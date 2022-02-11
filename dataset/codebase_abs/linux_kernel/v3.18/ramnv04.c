static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 ;
T_1 V_13 = F_2 ( V_10 , V_14 ) ;
int V_15 ;
V_15 = F_3 ( V_2 , V_3 , V_5 , & V_12 ) ;
* V_8 = F_4 ( V_12 ) ;
if ( V_15 )
return V_15 ;
if ( V_13 & 0x00000100 ) {
V_12 -> V_7 = ( ( V_13 >> 12 ) & 0xf ) * 2 + 2 ;
V_12 -> V_7 *= 1024 * 1024 ;
} else {
switch ( V_13 & V_16 ) {
case V_17 :
V_12 -> V_7 = 32 * 1024 * 1024 ;
break;
case V_18 :
V_12 -> V_7 = 16 * 1024 * 1024 ;
break;
case V_19 :
V_12 -> V_7 = 8 * 1024 * 1024 ;
break;
case V_20 :
V_12 -> V_7 = 4 * 1024 * 1024 ;
break;
}
}
if ( ( V_13 & 0x00000038 ) <= 0x10 )
V_12 -> type = V_21 ;
else
V_12 -> type = V_22 ;
return 0 ;
}
