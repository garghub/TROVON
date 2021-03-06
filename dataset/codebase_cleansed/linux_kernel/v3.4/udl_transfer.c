static inline u16 pixel32_to_be16p(const uint8_t *pixel)
{
uint32_t pix = *(uint32_t *)pixel;
u16 retval;
retval = (((pix >> 3) & 0x001f) |
((pix >> 5) & 0x07e0) |
((pix >> 8) & 0xf800));
return retval;
}
static void udl_compress_hline16(
const u8 **pixel_start_ptr,
const u8 *const pixel_end,
uint32_t *device_address_ptr,
uint8_t **command_buffer_ptr,
const uint8_t *const cmd_buffer_end, int bpp)
{
const u8 *pixel = *pixel_start_ptr;
uint32_t dev_addr = *device_address_ptr;
uint8_t *cmd = *command_buffer_ptr;
while ((pixel_end > pixel) &&
(cmd_buffer_end - MIN_RLX_CMD_BYTES > cmd)) {
uint8_t *raw_pixels_count_byte = 0;
uint8_t *cmd_pixels_count_byte = 0;
const u8 *raw_pixel_start = 0;
const u8 *cmd_pixel_start, *cmd_pixel_end = 0;
prefetchw((void *) cmd);
*cmd++ = 0xaf;
*cmd++ = 0x6b;
*cmd++ = (uint8_t) ((dev_addr >> 16) & 0xFF);
*cmd++ = (uint8_t) ((dev_addr >> 8) & 0xFF);
*cmd++ = (uint8_t) ((dev_addr) & 0xFF);
cmd_pixels_count_byte = cmd++;
cmd_pixel_start = pixel;
raw_pixels_count_byte = cmd++;
raw_pixel_start = pixel;
cmd_pixel_end = pixel + (min(MAX_CMD_PIXELS + 1,
min((int)(pixel_end - pixel) / bpp,
(int)(cmd_buffer_end - cmd) / 2))) * bpp;
prefetch_range((void *) pixel, (cmd_pixel_end - pixel) * bpp);
while (pixel < cmd_pixel_end) {
const u8 * const repeating_pixel = pixel;
if (bpp == 2)
*(uint16_t *)cmd = cpu_to_be16p((uint16_t *)pixel);
else if (bpp == 4)
*(uint16_t *)cmd = cpu_to_be16(pixel32_to_be16p(pixel));
cmd += 2;
pixel += bpp;
if (unlikely((pixel < cmd_pixel_end) &&
(!memcmp(pixel, repeating_pixel, bpp)))) {
*raw_pixels_count_byte = (((repeating_pixel -
raw_pixel_start) / bpp) + 1) & 0xFF;
while ((pixel < cmd_pixel_end)
&& (!memcmp(pixel, repeating_pixel, bpp))) {
pixel += bpp;
}
*cmd++ = (((pixel - repeating_pixel) / bpp) - 1) & 0xFF;
raw_pixel_start = pixel;
raw_pixels_count_byte = cmd++;
}
}
if (pixel > raw_pixel_start) {
*raw_pixels_count_byte = ((pixel-raw_pixel_start) / bpp) & 0xFF;
}
*cmd_pixels_count_byte = ((pixel - cmd_pixel_start) / bpp) & 0xFF;
dev_addr += ((pixel - cmd_pixel_start) / bpp) * 2;
}
if (cmd_buffer_end <= MIN_RLX_CMD_BYTES + cmd) {
if (cmd_buffer_end > cmd)
memset(cmd, 0xAF, cmd_buffer_end - cmd);
cmd = (uint8_t *) cmd_buffer_end;
}
*command_buffer_ptr = cmd;
*pixel_start_ptr = pixel;
*device_address_ptr = dev_addr;
return;
}
int udl_render_hline(struct drm_device *dev, int bpp, struct urb **urb_ptr,
const char *front, char **urb_buf_ptr,
u32 byte_offset, u32 byte_width,
int *ident_ptr, int *sent_ptr)
{
const u8 *line_start, *line_end, *next_pixel;
u32 base16 = 0 + (byte_offset / bpp) * 2;
struct urb *urb = *urb_ptr;
u8 *cmd = *urb_buf_ptr;
u8 *cmd_end = (u8 *) urb->transfer_buffer + urb->transfer_buffer_length;
line_start = (u8 *) (front + byte_offset);
next_pixel = line_start;
line_end = next_pixel + byte_width;
while (next_pixel < line_end) {
udl_compress_hline16(&next_pixel,
line_end, &base16,
(u8 **) &cmd, (u8 *) cmd_end, bpp);
if (cmd >= cmd_end) {
int len = cmd - (u8 *) urb->transfer_buffer;
if (udl_submit_urb(dev, urb, len))
return 1;
*sent_ptr += len;
urb = udl_get_urb(dev);
if (!urb)
return 1;
*urb_ptr = urb;
cmd = urb->transfer_buffer;
cmd_end = &cmd[urb->transfer_buffer_length];
}
}
*urb_buf_ptr = cmd;
return 0;
}
