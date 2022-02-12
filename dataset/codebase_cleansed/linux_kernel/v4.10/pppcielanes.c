uint8_t encode_pcie_lane_width(uint32_t num_lanes)
{
return pp_r600_encode_lanes[num_lanes];
}
uint8_t decode_pcie_lane_width(uint32_t num_lanes)
{
return pp_r600_decoded_lanes[num_lanes];
}
