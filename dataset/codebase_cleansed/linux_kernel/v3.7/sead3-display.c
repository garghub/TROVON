static void lcd_wait(unsigned int __iomem *display)
{
do { } while (__raw_readl(display + DISPLAY_CPLDSTATUS) & 1);
do {
__raw_readl(display + DISPLAY_LCDINSTRUCTION);
do { } while (__raw_readl(display + DISPLAY_CPLDSTATUS) & 1);
} while (__raw_readl(display + DISPLAY_CPLDDATA) & LCD_IR_BF);
}
void mips_display_message(const char *str)
{
static unsigned int __iomem *display;
char ch;
int i;
if (unlikely(display == NULL))
display = ioremap_nocache(LCD_DISPLAY_POS_BASE,
(8 * sizeof(int)));
for (i = 0; i < 16; i++) {
if (*str)
ch = *str++;
else
ch = ' ';
lcd_wait(display);
__raw_writel((LCD_SETDDRAM | i),
(display + DISPLAY_LCDINSTRUCTION));
lcd_wait(display);
__raw_writel(ch, display + DISPLAY_LCDDATA);
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
max_display_count = strlen(display_string) + 1 - 16;
mod_timer(&mips_scroll_timer, jiffies + 1);
}
