int mlxsw_sp_kvdl_alloc(struct mlxsw_sp *mlxsw_sp, unsigned int entry_count)
{
int entry_index;
int size;
int type_base;
int type_size;
int type_entries;
if (entry_count == 0 || entry_count > MLXSW_SP_CHUNK_MAX) {
return -EINVAL;
} else if (entry_count == 1) {
type_base = MLXSW_SP_KVDL_SINGLE_BASE;
type_size = MLXSW_SP_KVDL_SINGLE_SIZE;
type_entries = 1;
} else {
type_base = MLXSW_SP_KVDL_CHUNKS_BASE;
type_size = MLXSW_SP_KVDL_CHUNKS_SIZE;
type_entries = MLXSW_SP_CHUNK_MAX;
}
entry_index = type_base;
size = type_base + type_size;
for_each_clear_bit_from(entry_index, mlxsw_sp->kvdl.usage, size) {
int i;
for (i = 0; i < type_entries; i++)
set_bit(entry_index + i, mlxsw_sp->kvdl.usage);
return entry_index;
}
return -ENOBUFS;
}
void mlxsw_sp_kvdl_free(struct mlxsw_sp *mlxsw_sp, int entry_index)
{
int type_entries;
int i;
if (entry_index < MLXSW_SP_KVDL_CHUNKS_BASE)
type_entries = 1;
else
type_entries = MLXSW_SP_CHUNK_MAX;
for (i = 0; i < type_entries; i++)
clear_bit(entry_index + i, mlxsw_sp->kvdl.usage);
}
