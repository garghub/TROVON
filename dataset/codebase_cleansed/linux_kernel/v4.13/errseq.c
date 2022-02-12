errseq_t __errseq_set(errseq_t *eseq, int err)
{
errseq_t cur, old;
BUILD_BUG_ON_NOT_POWER_OF_2(MAX_ERRNO + 1);
old = READ_ONCE(*eseq);
if (WARN(unlikely(err == 0 || (unsigned int)-err > MAX_ERRNO),
"err = %d\n", err))
return old;
for (;;) {
errseq_t new;
new = (old & ~(MAX_ERRNO|ERRSEQ_SEEN)) | -err;
if (old & ERRSEQ_SEEN)
new += ERRSEQ_CTR_INC;
if (new == old) {
cur = new;
break;
}
cur = cmpxchg(eseq, old, new);
if (likely(cur == old || cur == new))
break;
old = cur;
}
return cur;
}
errseq_t errseq_sample(errseq_t *eseq)
{
errseq_t old = READ_ONCE(*eseq);
errseq_t new = old;
if (old != 0) {
new |= ERRSEQ_SEEN;
if (old != new)
cmpxchg(eseq, old, new);
}
return new;
}
int errseq_check(errseq_t *eseq, errseq_t since)
{
errseq_t cur = READ_ONCE(*eseq);
if (likely(cur == since))
return 0;
return -(cur & MAX_ERRNO);
}
int errseq_check_and_advance(errseq_t *eseq, errseq_t *since)
{
int err = 0;
errseq_t old, new;
old = READ_ONCE(*eseq);
if (old != *since) {
new = old | ERRSEQ_SEEN;
if (new != old)
cmpxchg(eseq, old, new);
*since = new;
err = -(new & MAX_ERRNO);
}
return err;
}
