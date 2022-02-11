void F_1 ( int V_1 )
{
V_2 . V_3 = 0x7ff ;
V_2 . V_4 = V_5 | V_1 ;
while( V_2 . V_3 != 0x7ff )
;
}
void F_2 ( unsigned int V_6 , unsigned int V_7 )
{
unsigned long V_8 ;
unsigned char V_9 ;
int V_10 ;
F_3 ( V_8 ) ;
V_11 . V_12 = 7 ;
V_9 = V_11 . V_12 ;
V_9 |= 011 ;
V_11 . V_13 = V_9 ;
if ( V_6 ) {
V_10 = V_14 / V_6 ;
if ( V_10 > 0xfff ) V_10 = 0xfff ;
V_11 . V_12 = 0 ;
V_11 . V_13 = V_10 & 0xff ;
V_11 . V_12 = 1 ;
V_11 . V_13 = ( V_10 >> 8 ) & 0xf ;
if ( V_7 ) {
int V_15 = ( V_7 * V_16 ) / V_17 / 10 ;
if ( V_15 > 0xffff ) V_15 = 0xffff ;
V_11 . V_12 = 11 ;
V_11 . V_13 = V_15 & 0xff ;
V_11 . V_12 = 12 ;
V_11 . V_13 = V_15 >> 8 ;
V_11 . V_12 = 13 ;
V_11 . V_13 = 0 ;
V_11 . V_12 = 8 ;
V_11 . V_13 = 0x10 ;
} else {
V_11 . V_12 = 8 ;
V_11 . V_13 = 15 ;
}
V_11 . V_12 = 7 ;
V_9 &= ~ 1 ;
V_11 . V_13 = V_9 ;
}
F_4 ( V_8 ) ;
}
