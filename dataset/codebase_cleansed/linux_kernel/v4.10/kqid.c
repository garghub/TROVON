bool qid_eq(struct kqid left, struct kqid right)
{
if (left.type != right.type)
return false;
switch(left.type) {
case USRQUOTA:
return uid_eq(left.uid, right.uid);
case GRPQUOTA:
return gid_eq(left.gid, right.gid);
case PRJQUOTA:
return projid_eq(left.projid, right.projid);
default:
BUG();
}
}
bool qid_lt(struct kqid left, struct kqid right)
{
if (left.type < right.type)
return true;
if (left.type > right.type)
return false;
switch (left.type) {
case USRQUOTA:
return uid_lt(left.uid, right.uid);
case GRPQUOTA:
return gid_lt(left.gid, right.gid);
case PRJQUOTA:
return projid_lt(left.projid, right.projid);
default:
BUG();
}
}
qid_t from_kqid(struct user_namespace *targ, struct kqid kqid)
{
switch (kqid.type) {
case USRQUOTA:
return from_kuid(targ, kqid.uid);
case GRPQUOTA:
return from_kgid(targ, kqid.gid);
case PRJQUOTA:
return from_kprojid(targ, kqid.projid);
default:
BUG();
}
}
qid_t from_kqid_munged(struct user_namespace *targ, struct kqid kqid)
{
switch (kqid.type) {
case USRQUOTA:
return from_kuid_munged(targ, kqid.uid);
case GRPQUOTA:
return from_kgid_munged(targ, kqid.gid);
case PRJQUOTA:
return from_kprojid_munged(targ, kqid.projid);
default:
BUG();
}
}
bool qid_valid(struct kqid qid)
{
switch (qid.type) {
case USRQUOTA:
return uid_valid(qid.uid);
case GRPQUOTA:
return gid_valid(qid.gid);
case PRJQUOTA:
return projid_valid(qid.projid);
default:
BUG();
}
}
