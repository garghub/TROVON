int ieee754si_xcpt(int r, const char *op, ...)
{
struct ieee754xctx ax;
if (!TSTX())
return r;
ax.op = op;
ax.rt = IEEE754_RT_SI;
ax.rv.si = r;
va_start(ax.ap, op);
ieee754_xcpt(&ax);
va_end(ax.ap);
return ax.rv.si;
}
s64 ieee754di_xcpt(s64 r, const char *op, ...)
{
struct ieee754xctx ax;
if (!TSTX())
return r;
ax.op = op;
ax.rt = IEEE754_RT_DI;
ax.rv.di = r;
va_start(ax.ap, op);
ieee754_xcpt(&ax);
va_end(ax.ap);
return ax.rv.di;
}
