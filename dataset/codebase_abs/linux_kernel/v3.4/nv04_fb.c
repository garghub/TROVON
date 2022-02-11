int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = F_2 ( V_2 , V_7 ) ;
if ( V_6 & 0x00000100 ) {
V_4 -> V_8 = ( ( V_6 >> 12 ) & 0xf ) * 2 + 2 ;
V_4 -> V_8 *= 1024 * 1024 ;
} else {
switch ( V_6 & V_9 ) {
case V_10 :
V_4 -> V_8 = 32 * 1024 * 1024 ;
break;
case V_11 :
V_4 -> V_8 = 16 * 1024 * 1024 ;
break;
case V_12 :
V_4 -> V_8 = 8 * 1024 * 1024 ;
break;
case V_13 :
V_4 -> V_8 = 4 * 1024 * 1024 ;
break;
}
}
if ( ( V_6 & 0x00000038 ) <= 0x10 )
V_4 -> V_14 = V_15 ;
else
V_4 -> V_14 = V_16 ;
return 0 ;
}
int
F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_17 , 0x1114 ) ;
return 0 ;
}
void
F_5 ( struct V_1 * V_2 )
{
}
