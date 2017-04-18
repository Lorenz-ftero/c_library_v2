/** @file
 *	@brief MAVLink comm protocol testsuite generated from ftero_messages.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef FTERO_MESSAGES_TESTSUITE_H
#define FTERO_MESSAGES_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_ftero_messages(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

	mavlink_test_ftero_messages(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_traction_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
	mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TRACTION_DATA >= 256) {
        	return;
        }
#endif
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_traction_data_t packet_in = {
		{ 17.0, 18.0, 19.0 },{ 101.0, 102.0, 103.0 },{ 185.0, 186.0, 187.0 },269.0
    };
	mavlink_traction_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.roll_t = packet_in.roll_t;
        
        mav_array_memcpy(packet1.pos_inert, packet_in.pos_inert, sizeof(float)*3);
        mav_array_memcpy(packet1.pos_local, packet_in.pos_local, sizeof(float)*3);
        mav_array_memcpy(packet1.att_rel, packet_in.att_rel, sizeof(float)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TRACTION_DATA_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_traction_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_traction_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_traction_data_pack(system_id, component_id, &msg , packet1.pos_inert , packet1.pos_local , packet1.att_rel , packet1.roll_t );
	mavlink_msg_traction_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_traction_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pos_inert , packet1.pos_local , packet1.att_rel , packet1.roll_t );
	mavlink_msg_traction_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_traction_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_traction_data_send(MAVLINK_COMM_1 , packet1.pos_inert , packet1.pos_local , packet1.att_rel , packet1.roll_t );
	mavlink_msg_traction_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_ftero_messages(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_traction_data(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // FTERO_MESSAGES_TESTSUITE_H
