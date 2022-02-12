static u32 minmax_subwin_update(struct minmax *m, u32 win,
const struct minmax_sample *val)
{
u32 dt = val->t - m->s[0].t;
if (unlikely(dt > win)) {
m->s[0] = m->s[1];
m->s[1] = m->s[2];
m->s[2] = *val;
if (unlikely(val->t - m->s[0].t > win)) {
m->s[0] = m->s[1];
m->s[1] = m->s[2];
m->s[2] = *val;
}
} else if (unlikely(m->s[1].t == m->s[0].t) && dt > win/4) {
m->s[2] = m->s[1] = *val;
} else if (unlikely(m->s[2].t == m->s[1].t) && dt > win/2) {
m->s[2] = *val;
}
return m->s[0].v;
}
u32 minmax_running_max(struct minmax *m, u32 win, u32 t, u32 meas)
{
struct minmax_sample val = { .t = t, .v = meas };
if (unlikely(val.v >= m->s[0].v) ||
unlikely(val.t - m->s[2].t > win))
return minmax_reset(m, t, meas);
if (unlikely(val.v >= m->s[1].v))
m->s[2] = m->s[1] = val;
else if (unlikely(val.v >= m->s[2].v))
m->s[2] = val;
return minmax_subwin_update(m, win, &val);
}
u32 minmax_running_min(struct minmax *m, u32 win, u32 t, u32 meas)
{
struct minmax_sample val = { .t = t, .v = meas };
if (unlikely(val.v <= m->s[0].v) ||
unlikely(val.t - m->s[2].t > win))
return minmax_reset(m, t, meas);
if (unlikely(val.v <= m->s[1].v))
m->s[2] = m->s[1] = val;
else if (unlikely(val.v <= m->s[2].v))
m->s[2] = val;
return minmax_subwin_update(m, win, &val);
}
