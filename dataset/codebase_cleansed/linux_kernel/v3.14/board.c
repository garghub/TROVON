__init bcm47xx_board_detect(void)
{
int err;
char buf[10];
const struct bcm47xx_board_type *board_detected;
if (bcm47xx_board.board != BCM47XX_BOARD_NO)
return;
err = bcm47xx_nvram_getenv("boardtype", buf, sizeof(buf));
if (err == -ENXIO) {
return;
}
board_detected = bcm47xx_board_get_nvram();
bcm47xx_board.board = board_detected->board;
strlcpy(bcm47xx_board.name, board_detected->name,
BCM47XX_BOARD_MAX_NAME);
}
enum bcm47xx_board bcm47xx_board_get(void)
{
return bcm47xx_board.board;
}
const char *bcm47xx_board_get_name(void)
{
return bcm47xx_board.name;
}
