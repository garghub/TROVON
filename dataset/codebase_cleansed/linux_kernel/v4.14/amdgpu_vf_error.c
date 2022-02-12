void amdgpu_vf_error_put(uint16_t sub_error_code, uint16_t error_flags, uint64_t error_data)
{
int index;
uint16_t error_code = AMDGIM_ERROR_CODE(AMDGIM_ERROR_CATEGORY_VF, sub_error_code);
index = admgpu_vf_errors.write_count % AMDGPU_VF_ERROR_ENTRY_SIZE;
admgpu_vf_errors.code [index] = error_code;
admgpu_vf_errors.flags [index] = error_flags;
admgpu_vf_errors.data [index] = error_data;
admgpu_vf_errors.write_count ++;
}
void amdgpu_vf_error_trans_all(struct amdgpu_device *adev)
{
u32 data1, data2, data3;
int index;
if ((NULL == adev) || (!amdgpu_sriov_vf(adev)) || (!adev->virt.ops) || (!adev->virt.ops->trans_msg)) {
return;
}
if (admgpu_vf_errors.write_count - admgpu_vf_errors.read_count > AMDGPU_VF_ERROR_ENTRY_SIZE) {
admgpu_vf_errors.read_count = admgpu_vf_errors.write_count - AMDGPU_VF_ERROR_ENTRY_SIZE;
}
while (admgpu_vf_errors.read_count < admgpu_vf_errors.write_count) {
index =admgpu_vf_errors.read_count % AMDGPU_VF_ERROR_ENTRY_SIZE;
data1 = AMDGIM_ERROR_CODE_FLAGS_TO_MAILBOX (admgpu_vf_errors.code[index], admgpu_vf_errors.flags[index]);
data2 = admgpu_vf_errors.data[index] & 0xFFFFFFFF;
data3 = (admgpu_vf_errors.data[index] >> 32) & 0xFFFFFFFF;
adev->virt.ops->trans_msg(adev, IDH_LOG_VF_ERROR, data1, data2, data3);
admgpu_vf_errors.read_count ++;
}
}
