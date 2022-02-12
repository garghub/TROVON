void init_messaging(void)
{
HV_MsgState *state = &__get_cpu_var(msg_state);
int rc = hv_register_message_state(state);
if (rc != HV_OK)
panic("hv_register_message_state: error %d", rc);
arch_local_irq_unmask(INT_INTCTRL_K);
}
void hv_message_intr(struct pt_regs *regs, int intnum)
{
int message[HV_MAX_MESSAGE_SIZE/sizeof(int)];
HV_RcvMsgInfo rmi;
int nmsgs = 0;
struct pt_regs *old_regs = set_irq_regs(regs);
irq_enter();
#ifdef CONFIG_DEBUG_STACKOVERFLOW
{
long sp = stack_pointer - (long) current_thread_info();
if (unlikely(sp < (sizeof(struct thread_info) + STACK_WARN))) {
pr_emerg("hv_message_intr: "
"stack overflow: %ld\n",
sp - sizeof(struct thread_info));
dump_stack();
}
}
#endif
while (1) {
HV_MsgState *state = this_cpu_ptr(&msg_state);
rmi = hv_receive_message(*state, (HV_VirtAddr) message,
sizeof(message));
if (rmi.msglen == 0)
break;
if (rmi.msglen < 0)
panic("hv_receive_message failed: %d", rmi.msglen);
++nmsgs;
if (rmi.source == HV_MSG_TILE) {
int tag;
BUG_ON(rmi.msglen != sizeof(int));
tag = message[0];
#ifdef CONFIG_SMP
evaluate_message(message[0]);
#else
panic("Received IPI message %d in UP mode", tag);
#endif
} else if (rmi.source == HV_MSG_INTR) {
HV_IntrMsg *him = (HV_IntrMsg *)message;
struct hv_driver_cb *cb =
(struct hv_driver_cb *)him->intarg;
cb->callback(cb, him->intdata);
__get_cpu_var(irq_stat).irq_hv_msg_count++;
}
}
if (nmsgs == 0)
panic("Message downcall invoked with no messages!");
irq_exit();
set_irq_regs(old_regs);
}
