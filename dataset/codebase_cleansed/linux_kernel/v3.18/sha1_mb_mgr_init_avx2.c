void sha1_mb_mgr_init_avx2(struct sha1_mb_mgr *state)
{
unsigned int j;
state->unused_lanes = 0xF76543210;
for (j = 0; j < 8; j++) {
state->lens[j] = 0xFFFFFFFF;
state->ldata[j].job_in_lane = NULL;
}
}
