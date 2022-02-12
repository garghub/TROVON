int ia_css_eventq_recv(
ia_css_queue_t *eventq_handle,
uint8_t *payload)
{
uint32_t sp_event;
int error;
error = ia_css_queue_dequeue(eventq_handle, &sp_event);
if (!error)
ia_css_event_decode(sp_event, payload);
return error;
}
int ia_css_eventq_send(
ia_css_queue_t *eventq_handle,
uint8_t evt_id,
uint8_t evt_payload_0,
uint8_t evt_payload_1,
uint8_t evt_payload_2)
{
uint8_t tmp[4];
uint32_t sw_event;
int error = ENOSYS;
tmp[0] = evt_id;
tmp[1] = evt_payload_0;
tmp[2] = evt_payload_1;
tmp[3] = evt_payload_2;
ia_css_event_encode(tmp, 4, &sw_event);
for ( ; ; ) {
error = ia_css_queue_enqueue(eventq_handle, sw_event);
if (ENOBUFS != error) {
break;
}
hrt_sleep();
}
return error;
}
