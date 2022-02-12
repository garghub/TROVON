void lockref_get(struct lockref *lockref)
{
CMPXCHG_LOOP(
new.count++;
,
return;
);
spin_lock(&lockref->lock);
lockref->count++;
spin_unlock(&lockref->lock);
}
int lockref_get_not_zero(struct lockref *lockref)
{
int retval;
CMPXCHG_LOOP(
new.count++;
if (!old.count)
return 0;
,
return 1;
);
spin_lock(&lockref->lock);
retval = 0;
if (lockref->count) {
lockref->count++;
retval = 1;
}
spin_unlock(&lockref->lock);
return retval;
}
int lockref_get_or_lock(struct lockref *lockref)
{
CMPXCHG_LOOP(
new.count++;
if (!old.count)
break;
,
return 1;
);
spin_lock(&lockref->lock);
if (!lockref->count)
return 0;
lockref->count++;
spin_unlock(&lockref->lock);
return 1;
}
int lockref_put_or_lock(struct lockref *lockref)
{
CMPXCHG_LOOP(
new.count--;
if (old.count <= 1)
break;
,
return 1;
);
spin_lock(&lockref->lock);
if (lockref->count <= 1)
return 0;
lockref->count--;
spin_unlock(&lockref->lock);
return 1;
}
void lockref_mark_dead(struct lockref *lockref)
{
assert_spin_locked(&lockref->lock);
lockref->count = -128;
}
int lockref_get_not_dead(struct lockref *lockref)
{
int retval;
CMPXCHG_LOOP(
new.count++;
if ((int)old.count < 0)
return 0;
,
return 1;
);
spin_lock(&lockref->lock);
retval = 0;
if ((int) lockref->count >= 0) {
lockref->count++;
retval = 1;
}
spin_unlock(&lockref->lock);
return retval;
}
