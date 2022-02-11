int
F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
T_1 V_8 = F_2 ( V_6 , V_9 ) ;
T_2 V_10 ;
enum V_11 type ;
if ( V_8 & 0x00000100 ) {
V_10 = ( ( V_8 >> 12 ) & 0xf ) * 2 + 2 ;
V_10 *= 1024 * 1024 ;
} else {
switch ( V_8 & V_12 ) {
case V_13 :
V_10 = 32 * 1024 * 1024 ;
break;
case V_14 :
V_10 = 16 * 1024 * 1024 ;
break;
case V_15 :
V_10 = 8 * 1024 * 1024 ;
break;
case V_16 :
V_10 = 4 * 1024 * 1024 ;
break;
}
}
if ( ( V_8 & 0x00000038 ) <= 0x10 )
type = V_17 ;
else
type = V_18 ;
return F_3 ( & V_19 , V_2 , type , V_10 , 0 , V_4 ) ;
}
