#pragma once
// MESSAGE TRACTION_DATA PACKING

#define MAVLINK_MSG_ID_TRACTION_DATA 180

MAVPACKED(
typedef struct __mavlink_traction_data_t {
 float pos_inert[3]; /*< Position in the earth fixed frame /inertial frame*/
 float pos_local[3]; /*< Position in the local frame /spherical coordinate frame*/
 float att_rel[3]; /*< Attitude of the vehicle relativ to the local frame*/
 float roll_t; /*< target roll for the vehicle, will be a setpoint*/
}) mavlink_traction_data_t;

#define MAVLINK_MSG_ID_TRACTION_DATA_LEN 40
#define MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN 40
#define MAVLINK_MSG_ID_180_LEN 40
#define MAVLINK_MSG_ID_180_MIN_LEN 40

#define MAVLINK_MSG_ID_TRACTION_DATA_CRC 134
#define MAVLINK_MSG_ID_180_CRC 134

#define MAVLINK_MSG_TRACTION_DATA_FIELD_POS_INERT_LEN 3
#define MAVLINK_MSG_TRACTION_DATA_FIELD_POS_LOCAL_LEN 3
#define MAVLINK_MSG_TRACTION_DATA_FIELD_ATT_REL_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TRACTION_DATA { \
	180, \
	"TRACTION_DATA", \
	4, \
	{  { "pos_inert", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_traction_data_t, pos_inert) }, \
         { "pos_local", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_traction_data_t, pos_local) }, \
         { "att_rel", NULL, MAVLINK_TYPE_FLOAT, 3, 24, offsetof(mavlink_traction_data_t, att_rel) }, \
         { "roll_t", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_traction_data_t, roll_t) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TRACTION_DATA { \
	"TRACTION_DATA", \
	4, \
	{  { "pos_inert", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_traction_data_t, pos_inert) }, \
         { "pos_local", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_traction_data_t, pos_local) }, \
         { "att_rel", NULL, MAVLINK_TYPE_FLOAT, 3, 24, offsetof(mavlink_traction_data_t, att_rel) }, \
         { "roll_t", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_traction_data_t, roll_t) }, \
         } \
}
#endif

/**
 * @brief Pack a traction_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pos_inert Position in the earth fixed frame /inertial frame
 * @param pos_local Position in the local frame /spherical coordinate frame
 * @param att_rel Attitude of the vehicle relativ to the local frame
 * @param roll_t target roll for the vehicle, will be a setpoint
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_traction_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       const float *pos_inert, const float *pos_local, const float *att_rel, float roll_t)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TRACTION_DATA_LEN];
	_mav_put_float(buf, 36, roll_t);
	_mav_put_float_array(buf, 0, pos_inert, 3);
	_mav_put_float_array(buf, 12, pos_local, 3);
	_mav_put_float_array(buf, 24, att_rel, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRACTION_DATA_LEN);
#else
	mavlink_traction_data_t packet;
	packet.roll_t = roll_t;
	mav_array_memcpy(packet.pos_inert, pos_inert, sizeof(float)*3);
	mav_array_memcpy(packet.pos_local, pos_local, sizeof(float)*3);
	mav_array_memcpy(packet.att_rel, att_rel, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRACTION_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TRACTION_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN, MAVLINK_MSG_ID_TRACTION_DATA_LEN, MAVLINK_MSG_ID_TRACTION_DATA_CRC);
}

/**
 * @brief Pack a traction_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pos_inert Position in the earth fixed frame /inertial frame
 * @param pos_local Position in the local frame /spherical coordinate frame
 * @param att_rel Attitude of the vehicle relativ to the local frame
 * @param roll_t target roll for the vehicle, will be a setpoint
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_traction_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           const float *pos_inert,const float *pos_local,const float *att_rel,float roll_t)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TRACTION_DATA_LEN];
	_mav_put_float(buf, 36, roll_t);
	_mav_put_float_array(buf, 0, pos_inert, 3);
	_mav_put_float_array(buf, 12, pos_local, 3);
	_mav_put_float_array(buf, 24, att_rel, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRACTION_DATA_LEN);
#else
	mavlink_traction_data_t packet;
	packet.roll_t = roll_t;
	mav_array_memcpy(packet.pos_inert, pos_inert, sizeof(float)*3);
	mav_array_memcpy(packet.pos_local, pos_local, sizeof(float)*3);
	mav_array_memcpy(packet.att_rel, att_rel, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRACTION_DATA_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_TRACTION_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN, MAVLINK_MSG_ID_TRACTION_DATA_LEN, MAVLINK_MSG_ID_TRACTION_DATA_CRC);
}

/**
 * @brief Encode a traction_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param traction_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_traction_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_traction_data_t* traction_data)
{
	return mavlink_msg_traction_data_pack(system_id, component_id, msg, traction_data->pos_inert, traction_data->pos_local, traction_data->att_rel, traction_data->roll_t);
}

/**
 * @brief Encode a traction_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param traction_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_traction_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_traction_data_t* traction_data)
{
	return mavlink_msg_traction_data_pack_chan(system_id, component_id, chan, msg, traction_data->pos_inert, traction_data->pos_local, traction_data->att_rel, traction_data->roll_t);
}

/**
 * @brief Send a traction_data message
 * @param chan MAVLink channel to send the message
 *
 * @param pos_inert Position in the earth fixed frame /inertial frame
 * @param pos_local Position in the local frame /spherical coordinate frame
 * @param att_rel Attitude of the vehicle relativ to the local frame
 * @param roll_t target roll for the vehicle, will be a setpoint
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_traction_data_send(mavlink_channel_t chan, const float *pos_inert, const float *pos_local, const float *att_rel, float roll_t)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_TRACTION_DATA_LEN];
	_mav_put_float(buf, 36, roll_t);
	_mav_put_float_array(buf, 0, pos_inert, 3);
	_mav_put_float_array(buf, 12, pos_local, 3);
	_mav_put_float_array(buf, 24, att_rel, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACTION_DATA, buf, MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN, MAVLINK_MSG_ID_TRACTION_DATA_LEN, MAVLINK_MSG_ID_TRACTION_DATA_CRC);
#else
	mavlink_traction_data_t packet;
	packet.roll_t = roll_t;
	mav_array_memcpy(packet.pos_inert, pos_inert, sizeof(float)*3);
	mav_array_memcpy(packet.pos_local, pos_local, sizeof(float)*3);
	mav_array_memcpy(packet.att_rel, att_rel, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACTION_DATA, (const char *)&packet, MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN, MAVLINK_MSG_ID_TRACTION_DATA_LEN, MAVLINK_MSG_ID_TRACTION_DATA_CRC);
#endif
}

/**
 * @brief Send a traction_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_traction_data_send_struct(mavlink_channel_t chan, const mavlink_traction_data_t* traction_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_traction_data_send(chan, traction_data->pos_inert, traction_data->pos_local, traction_data->att_rel, traction_data->roll_t);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACTION_DATA, (const char *)traction_data, MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN, MAVLINK_MSG_ID_TRACTION_DATA_LEN, MAVLINK_MSG_ID_TRACTION_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_TRACTION_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_traction_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const float *pos_inert, const float *pos_local, const float *att_rel, float roll_t)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 36, roll_t);
	_mav_put_float_array(buf, 0, pos_inert, 3);
	_mav_put_float_array(buf, 12, pos_local, 3);
	_mav_put_float_array(buf, 24, att_rel, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACTION_DATA, buf, MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN, MAVLINK_MSG_ID_TRACTION_DATA_LEN, MAVLINK_MSG_ID_TRACTION_DATA_CRC);
#else
	mavlink_traction_data_t *packet = (mavlink_traction_data_t *)msgbuf;
	packet->roll_t = roll_t;
	mav_array_memcpy(packet->pos_inert, pos_inert, sizeof(float)*3);
	mav_array_memcpy(packet->pos_local, pos_local, sizeof(float)*3);
	mav_array_memcpy(packet->att_rel, att_rel, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRACTION_DATA, (const char *)packet, MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN, MAVLINK_MSG_ID_TRACTION_DATA_LEN, MAVLINK_MSG_ID_TRACTION_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE TRACTION_DATA UNPACKING


/**
 * @brief Get field pos_inert from traction_data message
 *
 * @return Position in the earth fixed frame /inertial frame
 */
static inline uint16_t mavlink_msg_traction_data_get_pos_inert(const mavlink_message_t* msg, float *pos_inert)
{
	return _MAV_RETURN_float_array(msg, pos_inert, 3,  0);
}

/**
 * @brief Get field pos_local from traction_data message
 *
 * @return Position in the local frame /spherical coordinate frame
 */
static inline uint16_t mavlink_msg_traction_data_get_pos_local(const mavlink_message_t* msg, float *pos_local)
{
	return _MAV_RETURN_float_array(msg, pos_local, 3,  12);
}

/**
 * @brief Get field att_rel from traction_data message
 *
 * @return Attitude of the vehicle relativ to the local frame
 */
static inline uint16_t mavlink_msg_traction_data_get_att_rel(const mavlink_message_t* msg, float *att_rel)
{
	return _MAV_RETURN_float_array(msg, att_rel, 3,  24);
}

/**
 * @brief Get field roll_t from traction_data message
 *
 * @return target roll for the vehicle, will be a setpoint
 */
static inline float mavlink_msg_traction_data_get_roll_t(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a traction_data message into a struct
 *
 * @param msg The message to decode
 * @param traction_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_traction_data_decode(const mavlink_message_t* msg, mavlink_traction_data_t* traction_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mavlink_msg_traction_data_get_pos_inert(msg, traction_data->pos_inert);
	mavlink_msg_traction_data_get_pos_local(msg, traction_data->pos_local);
	mavlink_msg_traction_data_get_att_rel(msg, traction_data->att_rel);
	traction_data->roll_t = mavlink_msg_traction_data_get_roll_t(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TRACTION_DATA_LEN? msg->len : MAVLINK_MSG_ID_TRACTION_DATA_LEN;
        memset(traction_data, 0, MAVLINK_MSG_ID_TRACTION_DATA_LEN);
	memcpy(traction_data, _MAV_PAYLOAD(msg), len);
#endif
}
