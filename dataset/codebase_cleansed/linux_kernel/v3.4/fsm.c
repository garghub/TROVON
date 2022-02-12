void
mISDN_FsmNew(struct Fsm *fsm,
struct FsmNode *fnlist, int fncount)
{
int i;
fsm->jumpmatrix = kzalloc(sizeof(FSMFNPTR) * fsm->state_count *
fsm->event_count, GFP_KERNEL);
for (i = 0; i < fncount; i++)
if ((fnlist[i].state >= fsm->state_count) ||
(fnlist[i].event >= fsm->event_count)) {
printk(KERN_ERR
"mISDN_FsmNew Error: %d st(%ld/%ld) ev(%ld/%ld)\n",
i, (long)fnlist[i].state, (long)fsm->state_count,
(long)fnlist[i].event, (long)fsm->event_count);
} else
fsm->jumpmatrix[fsm->state_count * fnlist[i].event +
fnlist[i].state] = (FSMFNPTR) fnlist[i].routine;
}
void
mISDN_FsmFree(struct Fsm *fsm)
{
kfree((void *) fsm->jumpmatrix);
}
int
mISDN_FsmEvent(struct FsmInst *fi, int event, void *arg)
{
FSMFNPTR r;
if ((fi->state >= fi->fsm->state_count) ||
(event >= fi->fsm->event_count)) {
printk(KERN_ERR
"mISDN_FsmEvent Error st(%ld/%ld) ev(%d/%ld)\n",
(long)fi->state, (long)fi->fsm->state_count, event,
(long)fi->fsm->event_count);
return 1;
}
r = fi->fsm->jumpmatrix[fi->fsm->state_count * event + fi->state];
if (r) {
if (fi->debug)
fi->printdebug(fi, "State %s Event %s",
fi->fsm->strState[fi->state],
fi->fsm->strEvent[event]);
r(fi, event, arg);
return 0;
} else {
if (fi->debug)
fi->printdebug(fi, "State %s Event %s no action",
fi->fsm->strState[fi->state],
fi->fsm->strEvent[event]);
return 1;
}
}
void
mISDN_FsmChangeState(struct FsmInst *fi, int newstate)
{
fi->state = newstate;
if (fi->debug)
fi->printdebug(fi, "ChangeState %s",
fi->fsm->strState[newstate]);
}
static void
FsmExpireTimer(struct FsmTimer *ft)
{
#if FSM_TIMER_DEBUG
if (ft->fi->debug)
ft->fi->printdebug(ft->fi, "FsmExpireTimer %lx", (long) ft);
#endif
mISDN_FsmEvent(ft->fi, ft->event, ft->arg);
}
void
mISDN_FsmInitTimer(struct FsmInst *fi, struct FsmTimer *ft)
{
ft->fi = fi;
ft->tl.function = (void *) FsmExpireTimer;
ft->tl.data = (long) ft;
#if FSM_TIMER_DEBUG
if (ft->fi->debug)
ft->fi->printdebug(ft->fi, "mISDN_FsmInitTimer %lx", (long) ft);
#endif
init_timer(&ft->tl);
}
void
mISDN_FsmDelTimer(struct FsmTimer *ft, int where)
{
#if FSM_TIMER_DEBUG
if (ft->fi->debug)
ft->fi->printdebug(ft->fi, "mISDN_FsmDelTimer %lx %d",
(long) ft, where);
#endif
del_timer(&ft->tl);
}
int
mISDN_FsmAddTimer(struct FsmTimer *ft,
int millisec, int event, void *arg, int where)
{
#if FSM_TIMER_DEBUG
if (ft->fi->debug)
ft->fi->printdebug(ft->fi, "mISDN_FsmAddTimer %lx %d %d",
(long) ft, millisec, where);
#endif
if (timer_pending(&ft->tl)) {
if (ft->fi->debug) {
printk(KERN_WARNING
"mISDN_FsmAddTimer: timer already active!\n");
ft->fi->printdebug(ft->fi,
"mISDN_FsmAddTimer already active!");
}
return -1;
}
init_timer(&ft->tl);
ft->event = event;
ft->arg = arg;
ft->tl.expires = jiffies + (millisec * HZ) / 1000;
add_timer(&ft->tl);
return 0;
}
void
mISDN_FsmRestartTimer(struct FsmTimer *ft,
int millisec, int event, void *arg, int where)
{
#if FSM_TIMER_DEBUG
if (ft->fi->debug)
ft->fi->printdebug(ft->fi, "mISDN_FsmRestartTimer %lx %d %d",
(long) ft, millisec, where);
#endif
if (timer_pending(&ft->tl))
del_timer(&ft->tl);
init_timer(&ft->tl);
ft->event = event;
ft->arg = arg;
ft->tl.expires = jiffies + (millisec * HZ) / 1000;
add_timer(&ft->tl);
}
