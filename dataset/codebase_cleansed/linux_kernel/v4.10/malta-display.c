void mips_display_message(const char *str)
{
static unsigned int __iomem *display = NULL;
int i;
if (unlikely(display == NULL))
display = ioremap(ASCII_DISPLAY_POS_BASE, 16*sizeof(int));
for (i = 0; i <= 14; i += 2) {
if (*str)
__raw_writel(*str++, display + i);
else
__raw_writel(' ', display + i);
}
}
static void scroll_display_message(unsigned long data)
{
mips_display_message(&display_string[display_count++]);
if (display_count == max_display_count)
display_count = 0;
mod_timer(&mips_scroll_timer, jiffies + HZ);
}
void mips_scroll_message(void)
{
del_timer_sync(&mips_scroll_timer);
max_display_count = strlen(display_string) + 1 - 8;
mod_timer(&mips_scroll_timer, jiffies + 1);
}
