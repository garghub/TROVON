static int ircomm_state_idle(struct ircomm_cb *self, IRCOMM_EVENT event,
struct sk_buff *skb, struct ircomm_info *info)
{
int ret = 0;
switch (event) {
case IRCOMM_CONNECT_REQUEST:
ircomm_next_state(self, IRCOMM_WAITI);
ret = self->issue.connect_request(self, skb, info);
break;
case IRCOMM_TTP_CONNECT_INDICATION:
case IRCOMM_LMP_CONNECT_INDICATION:
ircomm_next_state(self, IRCOMM_WAITR);
ircomm_connect_indication(self, skb, info);
break;
default:
pr_debug("%s(), unknown event: %s\n", __func__ ,
ircomm_event[event]);
ret = -EINVAL;
}
return ret;
}
static int ircomm_state_waiti(struct ircomm_cb *self, IRCOMM_EVENT event,
struct sk_buff *skb, struct ircomm_info *info)
{
int ret = 0;
switch (event) {
case IRCOMM_TTP_CONNECT_CONFIRM:
case IRCOMM_LMP_CONNECT_CONFIRM:
ircomm_next_state(self, IRCOMM_CONN);
ircomm_connect_confirm(self, skb, info);
break;
case IRCOMM_TTP_DISCONNECT_INDICATION:
case IRCOMM_LMP_DISCONNECT_INDICATION:
ircomm_next_state(self, IRCOMM_IDLE);
ircomm_disconnect_indication(self, skb, info);
break;
default:
pr_debug("%s(), unknown event: %s\n", __func__ ,
ircomm_event[event]);
ret = -EINVAL;
}
return ret;
}
static int ircomm_state_waitr(struct ircomm_cb *self, IRCOMM_EVENT event,
struct sk_buff *skb, struct ircomm_info *info)
{
int ret = 0;
switch (event) {
case IRCOMM_CONNECT_RESPONSE:
ircomm_next_state(self, IRCOMM_CONN);
ret = self->issue.connect_response(self, skb);
break;
case IRCOMM_DISCONNECT_REQUEST:
ircomm_next_state(self, IRCOMM_IDLE);
ret = self->issue.disconnect_request(self, skb, info);
break;
case IRCOMM_TTP_DISCONNECT_INDICATION:
case IRCOMM_LMP_DISCONNECT_INDICATION:
ircomm_next_state(self, IRCOMM_IDLE);
ircomm_disconnect_indication(self, skb, info);
break;
default:
pr_debug("%s(), unknown event = %s\n", __func__ ,
ircomm_event[event]);
ret = -EINVAL;
}
return ret;
}
static int ircomm_state_conn(struct ircomm_cb *self, IRCOMM_EVENT event,
struct sk_buff *skb, struct ircomm_info *info)
{
int ret = 0;
switch (event) {
case IRCOMM_DATA_REQUEST:
ret = self->issue.data_request(self, skb, 0);
break;
case IRCOMM_TTP_DATA_INDICATION:
ircomm_process_data(self, skb);
break;
case IRCOMM_LMP_DATA_INDICATION:
ircomm_data_indication(self, skb);
break;
case IRCOMM_CONTROL_REQUEST:
ret = self->issue.data_request(self, skb, skb->len);
break;
case IRCOMM_TTP_DISCONNECT_INDICATION:
case IRCOMM_LMP_DISCONNECT_INDICATION:
ircomm_next_state(self, IRCOMM_IDLE);
ircomm_disconnect_indication(self, skb, info);
break;
case IRCOMM_DISCONNECT_REQUEST:
ircomm_next_state(self, IRCOMM_IDLE);
ret = self->issue.disconnect_request(self, skb, info);
break;
default:
pr_debug("%s(), unknown event = %s\n", __func__ ,
ircomm_event[event]);
ret = -EINVAL;
}
return ret;
}
int ircomm_do_event(struct ircomm_cb *self, IRCOMM_EVENT event,
struct sk_buff *skb, struct ircomm_info *info)
{
pr_debug("%s: state=%s, event=%s\n", __func__ ,
ircomm_state[self->state], ircomm_event[event]);
return (*state[self->state])(self, event, skb, info);
}
void ircomm_next_state(struct ircomm_cb *self, IRCOMM_STATE state)
{
self->state = state;
pr_debug("%s: next state=%s, service type=%d\n", __func__ ,
ircomm_state[self->state], self->service_type);
}
