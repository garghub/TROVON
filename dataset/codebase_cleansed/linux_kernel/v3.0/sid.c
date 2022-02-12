u32 aa_alloc_sid(void)
{
u32 sid;
spin_lock(&sid_lock);
sid = (++global_sid);
spin_unlock(&sid_lock);
return sid;
}
void aa_free_sid(u32 sid)
{
;
}
