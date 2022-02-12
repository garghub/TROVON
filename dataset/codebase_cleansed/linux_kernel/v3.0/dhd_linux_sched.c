int setScheduler(struct task_struct *p, int policy, struct sched_param *param)
{
int rc = 0;
rc = sched_setscheduler(p, policy, param);
return rc;
}
