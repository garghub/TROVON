int
F_1 ( struct V_1 * V_2 , int line )
{
if ( line < 2 ) {
line = line * 16 ;
line = F_2 ( V_2 , 0 , V_3 ) >> line ;
return ! ! ( line & 0x0100 ) ;
} else
if ( line < 10 ) {
line = ( line - 2 ) * 4 ;
line = F_2 ( V_2 , 0 , V_4 ) >> line ;
return ! ! ( line & 0x04 ) ;
} else
if ( line < 14 ) {
line = ( line - 10 ) * 4 ;
line = F_2 ( V_2 , 0 , V_5 ) >> line ;
return ! ! ( line & 0x04 ) ;
}
return - V_6 ;
}
int
F_3 ( struct V_1 * V_2 , int line , int V_7 , int V_8 )
{
T_1 V_9 , V_10 , V_11 ;
if ( line < 2 ) {
line = line * 16 ;
V_9 = V_3 ;
V_10 = 0x00000011 ;
V_11 = ( V_7 << 4 ) | V_8 ;
} else
if ( line < 10 ) {
line = ( line - 2 ) * 4 ;
V_9 = V_4 ;
V_10 = 0x00000003 << ( ( line - 2 ) * 4 ) ;
V_11 = ( V_7 << 1 ) | V_8 ;
} else
if ( line < 14 ) {
line = ( line - 10 ) * 4 ;
V_9 = V_5 ;
V_10 = 0x00000003 ;
V_11 = ( V_7 << 1 ) | V_8 ;
} else {
return - V_6 ;
}
V_10 = F_2 ( V_2 , 0 , V_9 ) & ~ ( V_10 << line ) ;
F_4 ( V_2 , 0 , V_9 , V_10 | ( V_11 << line ) ) ;
return 0 ;
}
void
F_5 ( struct V_1 * V_2 , int line , bool V_12 )
{
T_1 V_10 = 0x00010001 << line ;
F_6 ( V_2 , 0x001104 , V_10 ) ;
F_7 ( V_2 , 0x001144 , V_10 , V_12 ? V_10 : 0 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
T_1 V_13 = F_9 ( V_2 , 0x1104 ) ;
T_1 V_14 = ( V_13 & 0x0000ffff ) >> 0 ;
T_1 V_15 = ( V_13 & 0xffff0000 ) >> 16 ;
F_10 ( V_2 , 0 , V_14 | V_15 ) ;
F_6 ( V_2 , 0x001104 , V_13 ) ;
}
int
F_11 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 0x001140 , 0x00000000 ) ;
F_6 ( V_2 , 0x001100 , 0xffffffff ) ;
F_6 ( V_2 , 0x001144 , 0x00000000 ) ;
F_6 ( V_2 , 0x001104 , 0xffffffff ) ;
F_12 ( V_2 , 28 , F_8 ) ;
return 0 ;
}
void
F_13 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 0x001140 , 0x00000000 ) ;
F_6 ( V_2 , 0x001144 , 0x00000000 ) ;
F_14 ( V_2 , 28 ) ;
}
