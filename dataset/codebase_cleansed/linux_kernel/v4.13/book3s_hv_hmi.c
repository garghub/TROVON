void wait_for_subcore_guest_exit(void)
{
int i;
if (!local_paca->sibling_subcore_state)
return;
for (i = 0; i < MAX_SUBCORE_PER_CORE; i++)
while (local_paca->sibling_subcore_state->in_guest[i])
cpu_relax();
}
void wait_for_tb_resync(void)
{
if (!local_paca->sibling_subcore_state)
return;
while (test_bit(CORE_TB_RESYNC_REQ_BIT,
&local_paca->sibling_subcore_state->flags))
cpu_relax();
}
