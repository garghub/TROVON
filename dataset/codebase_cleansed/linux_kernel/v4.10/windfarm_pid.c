void wf_pid_init(struct wf_pid_state *st, struct wf_pid_param *param)
{
memset(st, 0, sizeof(struct wf_pid_state));
st->param = *param;
st->first = 1;
}
s32 wf_pid_run(struct wf_pid_state *st, s32 new_sample)
{
s64 error, integ, deriv;
s32 target;
int i, hlen = st->param.history_len;
error = new_sample - st->param.itarget;
if (st->first) {
for (i = 0; i < hlen; i++) {
st->samples[i] = new_sample;
st->errors[i] = error;
}
st->first = 0;
st->index = 0;
} else {
st->index = (st->index + 1) % hlen;
st->samples[st->index] = new_sample;
st->errors[st->index] = error;
}
for (i = 0, integ = 0; i < hlen; i++)
integ += st->errors[(st->index + hlen - i) % hlen];
integ *= st->param.interval;
deriv = st->errors[st->index] -
st->errors[(st->index + hlen - 1) % hlen];
deriv /= st->param.interval;
target = (s32)((integ * (s64)st->param.gr + deriv * (s64)st->param.gd +
error * (s64)st->param.gp) >> 36);
if (st->param.additive)
target += st->target;
target = max(target, st->param.min);
target = min(target, st->param.max);
st->target = target;
return st->target;
}
void wf_cpu_pid_init(struct wf_cpu_pid_state *st,
struct wf_cpu_pid_param *param)
{
memset(st, 0, sizeof(struct wf_cpu_pid_state));
st->param = *param;
st->first = 1;
}
s32 wf_cpu_pid_run(struct wf_cpu_pid_state *st, s32 new_power, s32 new_temp)
{
s64 integ, deriv, prop;
s32 error, target, sval, adj;
int i, hlen = st->param.history_len;
error = st->param.pmaxadj - new_power;
if (st->first) {
for (i = 0; i < hlen; i++) {
st->powers[i] = new_power;
st->errors[i] = error;
}
st->temps[0] = st->temps[1] = new_temp;
st->first = 0;
st->index = st->tindex = 0;
} else {
st->index = (st->index + 1) % hlen;
st->powers[st->index] = new_power;
st->errors[st->index] = error;
st->tindex = (st->tindex + 1) % 2;
st->temps[st->tindex] = new_temp;
}
for (i = 0, integ = 0; i < hlen; i++)
integ += st->errors[(st->index + hlen - i) % hlen];
integ *= st->param.interval;
integ *= st->param.gr;
sval = st->param.tmax - (s32)(integ >> 20);
adj = min(st->param.ttarget, sval);
DBG("integ: %lx, sval: %lx, adj: %lx\n", integ, sval, adj);
deriv = st->temps[st->tindex] -
st->temps[(st->tindex + 2 - 1) % 2];
deriv /= st->param.interval;
deriv *= st->param.gd;
prop = st->last_delta = (new_temp - adj);
prop *= st->param.gp;
DBG("deriv: %lx, prop: %lx\n", deriv, prop);
target = st->target + (s32)((deriv + prop) >> 36);
target = max(target, st->param.min);
target = min(target, st->param.max);
st->target = target;
return st->target;
}
