void sha512_mb_mgr_init_avx2(struct sha512_mb_mgr *state)
{
unsigned int j;
state->lens[0] = 0;
state->lens[1] = 1;
state->lens[2] = 2;
state->lens[3] = 3;
state->unused_lanes = 0xFF03020100;
for (j = 0; j < 4; j++)
state->ldata[j].job_in_lane = NULL;
}
