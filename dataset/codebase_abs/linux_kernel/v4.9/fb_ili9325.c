static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 != - 1 )
F_2 ( V_2 -> V_5 . V_6 , 0 ) ;
V_7 &= 0x07 ;
V_8 &= 0x07 ;
V_9 &= 0x0f ;
V_10 &= 0x1f ;
V_11 &= 0x3f ;
F_3 ( V_2 , 0x00E3 , 0x3008 ) ;
F_3 ( V_2 , 0x00E7 , 0x0012 ) ;
F_3 ( V_2 , 0x00EF , 0x1231 ) ;
F_3 ( V_2 , 0x0001 , 0x0100 ) ;
F_3 ( V_2 , 0x0002 , 0x0700 ) ;
F_3 ( V_2 , 0x0004 , 0x0000 ) ;
F_3 ( V_2 , 0x0008 , 0x0207 ) ;
F_3 ( V_2 , 0x0009 , 0x0000 ) ;
F_3 ( V_2 , 0x000A , 0x0000 ) ;
F_3 ( V_2 , 0x000C , 0x0000 ) ;
F_3 ( V_2 , 0x000D , 0x0000 ) ;
F_3 ( V_2 , 0x000F , 0x0000 ) ;
F_3 ( V_2 , 0x0010 , 0x0000 ) ;
F_3 ( V_2 , 0x0011 , 0x0007 ) ;
F_3 ( V_2 , 0x0012 , 0x0000 ) ;
F_3 ( V_2 , 0x0013 , 0x0000 ) ;
F_4 ( 200 ) ;
F_3 ( V_2 , 0x0010 ,
( 1 << 12 ) | ( V_7 << 8 ) | ( 1 << 7 ) | ( 0x01 << 4 ) ) ;
F_3 ( V_2 , 0x0011 , 0x220 | V_8 ) ;
F_4 ( 50 ) ;
F_3 ( V_2 , 0x0012 , V_9 ) ;
F_4 ( 50 ) ;
F_3 ( V_2 , 0x0013 , V_10 << 8 ) ;
F_3 ( V_2 , 0x0029 , V_11 ) ;
F_3 ( V_2 , 0x002B , 0x000C ) ;
F_4 ( 50 ) ;
F_3 ( V_2 , 0x0020 , 0x0000 ) ;
F_3 ( V_2 , 0x0021 , 0x0000 ) ;
F_3 ( V_2 , 0x0050 , 0x0000 ) ;
F_3 ( V_2 , 0x0051 , 0x00EF ) ;
F_3 ( V_2 , 0x0052 , 0x0000 ) ;
F_3 ( V_2 , 0x0053 , 0x013F ) ;
F_3 ( V_2 , 0x0060 , 0xA700 ) ;
F_3 ( V_2 , 0x0061 , 0x0001 ) ;
F_3 ( V_2 , 0x006A , 0x0000 ) ;
F_3 ( V_2 , 0x0080 , 0x0000 ) ;
F_3 ( V_2 , 0x0081 , 0x0000 ) ;
F_3 ( V_2 , 0x0082 , 0x0000 ) ;
F_3 ( V_2 , 0x0083 , 0x0000 ) ;
F_3 ( V_2 , 0x0084 , 0x0000 ) ;
F_3 ( V_2 , 0x0085 , 0x0000 ) ;
F_3 ( V_2 , 0x0090 , 0x0010 ) ;
F_3 ( V_2 , 0x0092 , 0x0600 ) ;
F_3 ( V_2 , 0x0007 , 0x0133 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , int V_12 , int V_13 , int V_14 , int V_15 )
{
switch ( V_2 -> V_16 -> V_17 . V_18 ) {
case 0 :
F_3 ( V_2 , 0x0020 , V_12 ) ;
F_3 ( V_2 , 0x0021 , V_13 ) ;
break;
case 180 :
F_3 ( V_2 , 0x0020 , V_19 - 1 - V_12 ) ;
F_3 ( V_2 , 0x0021 , V_20 - 1 - V_13 ) ;
break;
case 270 :
F_3 ( V_2 , 0x0020 , V_19 - 1 - V_13 ) ;
F_3 ( V_2 , 0x0021 , V_12 ) ;
break;
case 90 :
F_3 ( V_2 , 0x0020 , V_13 ) ;
F_3 ( V_2 , 0x0021 , V_20 - 1 - V_12 ) ;
break;
}
F_3 ( V_2 , 0x0022 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_16 -> V_17 . V_18 ) {
case 0 :
F_3 ( V_2 , 0x03 , 0x0030 | ( V_2 -> V_21 << 12 ) ) ;
break;
case 180 :
F_3 ( V_2 , 0x03 , 0x0000 | ( V_2 -> V_21 << 12 ) ) ;
break;
case 270 :
F_3 ( V_2 , 0x03 , 0x0028 | ( V_2 -> V_21 << 12 ) ) ;
break;
case 90 :
F_3 ( V_2 , 0x03 , 0x0018 | ( V_2 -> V_21 << 12 ) ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long * V_22 )
{
unsigned long V_23 [] = {
0x1f , 0x1f , 0x07 , 0x07 , 0x07 , 0x07 , 0x07 , 0x07 , 0x07 , 0x07 ,
0x1f , 0x1f , 0x07 , 0x07 , 0x07 , 0x07 , 0x07 , 0x07 , 0x07 , 0x07 ,
} ;
int V_24 , V_25 ;
for ( V_24 = 0 ; V_24 < 2 ; V_24 ++ )
for ( V_25 = 0 ; V_25 < 10 ; V_25 ++ )
F_8 ( V_24 , V_25 ) &= V_23 [ V_24 * V_2 -> gamma . V_26 + V_25 ] ;
F_3 ( V_2 , 0x0030 , F_8 ( 0 , 5 ) << 8 | F_8 ( 0 , 4 ) ) ;
F_3 ( V_2 , 0x0031 , F_8 ( 0 , 7 ) << 8 | F_8 ( 0 , 6 ) ) ;
F_3 ( V_2 , 0x0032 , F_8 ( 0 , 9 ) << 8 | F_8 ( 0 , 8 ) ) ;
F_3 ( V_2 , 0x0035 , F_8 ( 0 , 3 ) << 8 | F_8 ( 0 , 2 ) ) ;
F_3 ( V_2 , 0x0036 , F_8 ( 0 , 1 ) << 8 | F_8 ( 0 , 0 ) ) ;
F_3 ( V_2 , 0x0037 , F_8 ( 1 , 5 ) << 8 | F_8 ( 1 , 4 ) ) ;
F_3 ( V_2 , 0x0038 , F_8 ( 1 , 7 ) << 8 | F_8 ( 1 , 6 ) ) ;
F_3 ( V_2 , 0x0039 , F_8 ( 1 , 9 ) << 8 | F_8 ( 1 , 8 ) ) ;
F_3 ( V_2 , 0x003C , F_8 ( 1 , 3 ) << 8 | F_8 ( 1 , 2 ) ) ;
F_3 ( V_2 , 0x003D , F_8 ( 1 , 1 ) << 8 | F_8 ( 1 , 0 ) ) ;
return 0 ;
}
