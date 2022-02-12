static int mlxsw_sp_port_pb_init(struct mlxsw_sp_port *mlxsw_sp_port)
{
char pbmc_pl[MLXSW_REG_PBMC_LEN];
int i;
mlxsw_reg_pbmc_pack(pbmc_pl, mlxsw_sp_port->local_port,
0xffff, 0xffff / 2);
for (i = 0; i < MLXSW_SP_PBS_LEN; i++) {
const struct mlxsw_sp_pb *pb;
pb = &mlxsw_sp_pbs[i];
mlxsw_reg_pbmc_lossy_buffer_pack(pbmc_pl, pb->index, pb->size);
}
return mlxsw_reg_write(mlxsw_sp_port->mlxsw_sp->core,
MLXSW_REG(pbmc), pbmc_pl);
}
static int mlxsw_sp_sb_pools_init(struct mlxsw_sp *mlxsw_sp)
{
char sbpr_pl[MLXSW_REG_SBPR_LEN];
int i;
int err;
for (i = 0; i < MLXSW_SP_SB_POOLS_LEN; i++) {
const struct mlxsw_sp_sb_pool *pool;
pool = &mlxsw_sp_sb_pools[i];
mlxsw_reg_sbpr_pack(sbpr_pl, pool->pool, pool->dir,
pool->mode, pool->size);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sbpr), sbpr_pl);
if (err)
return err;
}
return 0;
}
static int mlxsw_sp_sb_cms_init(struct mlxsw_sp *mlxsw_sp, u8 local_port,
const struct mlxsw_sp_sb_cm *cms,
size_t cms_len)
{
char sbcm_pl[MLXSW_REG_SBCM_LEN];
int i;
int err;
for (i = 0; i < cms_len; i++) {
const struct mlxsw_sp_sb_cm *cm;
cm = &cms[i];
mlxsw_reg_sbcm_pack(sbcm_pl, local_port, cm->u.pg, cm->dir,
cm->min_buff, cm->max_buff, cm->pool);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sbcm), sbcm_pl);
if (err)
return err;
}
return 0;
}
static int mlxsw_sp_port_sb_cms_init(struct mlxsw_sp_port *mlxsw_sp_port)
{
return mlxsw_sp_sb_cms_init(mlxsw_sp_port->mlxsw_sp,
mlxsw_sp_port->local_port, mlxsw_sp_sb_cms,
MLXSW_SP_SB_CMS_LEN);
}
static int mlxsw_sp_cpu_port_sb_cms_init(struct mlxsw_sp *mlxsw_sp)
{
return mlxsw_sp_sb_cms_init(mlxsw_sp, 0, mlxsw_sp_cpu_port_sb_cms,
MLXSW_SP_CPU_PORT_SB_MCS_LEN);
}
static int mlxsw_sp_port_sb_pms_init(struct mlxsw_sp_port *mlxsw_sp_port)
{
char sbpm_pl[MLXSW_REG_SBPM_LEN];
int i;
int err;
for (i = 0; i < MLXSW_SP_SB_PMS_LEN; i++) {
const struct mlxsw_sp_sb_pm *pm;
pm = &mlxsw_sp_sb_pms[i];
mlxsw_reg_sbpm_pack(sbpm_pl, mlxsw_sp_port->local_port,
pm->pool, pm->dir,
pm->min_buff, pm->max_buff);
err = mlxsw_reg_write(mlxsw_sp_port->mlxsw_sp->core,
MLXSW_REG(sbpm), sbpm_pl);
if (err)
return err;
}
return 0;
}
static int mlxsw_sp_sb_mms_init(struct mlxsw_sp *mlxsw_sp)
{
char sbmm_pl[MLXSW_REG_SBMM_LEN];
int i;
int err;
for (i = 0; i < MLXSW_SP_SB_MMS_LEN; i++) {
const struct mlxsw_sp_sb_mm *mc;
mc = &mlxsw_sp_sb_mms[i];
mlxsw_reg_sbmm_pack(sbmm_pl, mc->prio, mc->min_buff,
mc->max_buff, mc->pool);
err = mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(sbmm), sbmm_pl);
if (err)
return err;
}
return 0;
}
int mlxsw_sp_buffers_init(struct mlxsw_sp *mlxsw_sp)
{
int err;
err = mlxsw_sp_sb_pools_init(mlxsw_sp);
if (err)
return err;
err = mlxsw_sp_cpu_port_sb_cms_init(mlxsw_sp);
if (err)
return err;
err = mlxsw_sp_sb_mms_init(mlxsw_sp);
return err;
}
int mlxsw_sp_port_buffers_init(struct mlxsw_sp_port *mlxsw_sp_port)
{
int err;
err = mlxsw_sp_port_pb_init(mlxsw_sp_port);
if (err)
return err;
err = mlxsw_sp_port_sb_cms_init(mlxsw_sp_port);
if (err)
return err;
err = mlxsw_sp_port_sb_pms_init(mlxsw_sp_port);
return err;
}
