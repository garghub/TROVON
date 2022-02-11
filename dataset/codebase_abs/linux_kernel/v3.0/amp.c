static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned short V_4 )
{
unsigned short V_5 ;
V_5 = ( V_3 << 9 ) | V_4 ;
F_2 ( V_2 , V_6 , V_5 >> 8 , V_5 & 0xff ) ;
}
static int T_1 F_3 ( struct V_1 * V_2 )
{
static const unsigned short V_7 [] = {
V_8 , 0x0000 ,
V_9 , 0x0000 ,
V_10 , 0x0008 ,
V_11 , 0x0001 ,
} ;
unsigned int V_12 ;
V_2 -> V_13 = 6 ;
V_2 -> V_14 = 2 ;
if ( V_2 -> V_15 . V_16 == V_17 ) {
for ( V_12 = 0 ; V_12 < F_4 ( V_7 ) ; V_12 += 2 )
F_1 ( V_2 , V_7 [ V_12 ] , V_7 [ V_12 + 1 ] ) ;
}
return 0 ;
}
static int T_1 F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_18 , 0x5a , F_7 ( V_2 -> V_18 , 0x5a ) & ~ 0x8000 ) ;
return 0 ;
}
