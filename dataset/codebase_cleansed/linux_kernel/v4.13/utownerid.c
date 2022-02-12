acpi_status acpi_ut_allocate_owner_id(acpi_owner_id *owner_id)
{
u32 i;
u32 j;
u32 k;
acpi_status status;
ACPI_FUNCTION_TRACE(ut_allocate_owner_id);
if (*owner_id) {
ACPI_ERROR((AE_INFO,
"Owner ID [0x%2.2X] already exists", *owner_id));
return_ACPI_STATUS(AE_ALREADY_EXISTS);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_CACHES);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
for (i = 0, j = acpi_gbl_last_owner_id_index;
i < (ACPI_NUM_OWNERID_MASKS + 1); i++, j++) {
if (j >= ACPI_NUM_OWNERID_MASKS) {
j = 0;
}
for (k = acpi_gbl_next_owner_id_offset; k < 32; k++) {
if (acpi_gbl_owner_id_mask[j] == ACPI_UINT32_MAX) {
break;
}
if (!(acpi_gbl_owner_id_mask[j] & ((u32)1 << k))) {
acpi_gbl_owner_id_mask[j] |= ((u32)1 << k);
acpi_gbl_last_owner_id_index = (u8)j;
acpi_gbl_next_owner_id_offset = (u8)(k + 1);
*owner_id =
(acpi_owner_id)((k + 1) + ACPI_MUL_32(j));
ACPI_DEBUG_PRINT((ACPI_DB_VALUES,
"Allocated OwnerId: %2.2X\n",
(unsigned int)*owner_id));
goto exit;
}
}
acpi_gbl_next_owner_id_offset = 0;
}
status = AE_OWNER_ID_LIMIT;
ACPI_ERROR((AE_INFO,
"Could not allocate new OwnerId (255 max), AE_OWNER_ID_LIMIT"));
exit:
(void)acpi_ut_release_mutex(ACPI_MTX_CACHES);
return_ACPI_STATUS(status);
}
void acpi_ut_release_owner_id(acpi_owner_id *owner_id_ptr)
{
acpi_owner_id owner_id = *owner_id_ptr;
acpi_status status;
u32 index;
u32 bit;
ACPI_FUNCTION_TRACE_U32(ut_release_owner_id, owner_id);
*owner_id_ptr = 0;
if (owner_id == 0) {
ACPI_ERROR((AE_INFO, "Invalid OwnerId: 0x%2.2X", owner_id));
return_VOID;
}
status = acpi_ut_acquire_mutex(ACPI_MTX_CACHES);
if (ACPI_FAILURE(status)) {
return_VOID;
}
owner_id--;
index = ACPI_DIV_32(owner_id);
bit = (u32)1 << ACPI_MOD_32(owner_id);
if (acpi_gbl_owner_id_mask[index] & bit) {
acpi_gbl_owner_id_mask[index] ^= bit;
} else {
ACPI_ERROR((AE_INFO,
"Release of non-allocated OwnerId: 0x%2.2X",
owner_id + 1));
}
(void)acpi_ut_release_mutex(ACPI_MTX_CACHES);
return_VOID;
}
