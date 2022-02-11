static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 ;
T_1 V_11 ;
T_2 V_12 ;
T_3 V_13 ;
switch ( ( V_13 = F_2 ( V_2 , V_4 -> V_14 + 0x00 ) ) ) {
case 0xaa55 :
case 0xbb77 :
case 0x4e56 :
break;
default:
F_3 ( V_6 , L_1 ,
V_4 -> V_14 , V_13 ) ;
return false ;
}
if ( ! ( V_13 = F_4 ( V_2 , V_4 -> V_14 , & V_11 , & V_12 , & V_8 ) ) )
return false ;
V_4 -> V_15 = V_8 . V_16 ;
V_4 -> type = V_8 . V_17 ;
V_4 -> V_18 = V_8 . V_18 ;
if ( V_4 -> type != 0x70 ) {
if ( ! ( V_13 = F_5 ( V_2 , V_4 -> V_14 , & V_10 ) ) )
return true ;
V_4 -> V_15 = V_10 . V_16 ;
V_4 -> V_18 = V_10 . V_18 ;
} else {
V_4 -> V_18 = true ;
}
return true ;
}
bool
V_3 ( struct V_1 * V_2 , int V_19 , struct V_3 * V_4 )
{
T_3 V_20 = V_2 -> V_20 ;
memset ( V_4 , 0x00 , sizeof( * V_4 ) ) ;
V_2 -> V_20 = 0 ;
do {
V_4 -> V_14 += V_4 -> V_15 ;
if ( V_4 -> V_18 || ! F_1 ( V_2 , V_4 ) ) {
V_2 -> V_20 = V_20 ;
return false ;
}
} while( V_19 -- );
V_2 -> V_20 = V_20 ;
return true ;
}
