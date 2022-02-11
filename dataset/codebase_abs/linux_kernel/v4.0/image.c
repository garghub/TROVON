static bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
struct V_7 V_8 ;
T_1 V_9 ;
T_2 V_10 ;
T_3 V_11 ;
switch ( ( V_11 = F_2 ( V_2 , V_4 -> V_12 + 0x00 ) ) ) {
case 0xaa55 :
case 0xbb77 :
case 0x4e56 :
break;
default:
F_3 ( V_2 , L_1 ,
V_4 -> V_12 , V_11 ) ;
return false ;
}
if ( ! ( V_11 = F_4 ( V_2 , V_4 -> V_12 , & V_9 , & V_10 , & V_6 ) ) )
return false ;
V_4 -> V_13 = V_6 . V_14 ;
V_4 -> type = V_6 . V_15 ;
V_4 -> V_16 = V_6 . V_16 ;
if ( V_4 -> type != 0x70 ) {
if ( ! ( V_11 = F_5 ( V_2 , V_4 -> V_12 , & V_8 ) ) )
return true ;
V_4 -> V_13 = V_8 . V_14 ;
V_4 -> V_16 = V_8 . V_16 ;
} else {
V_4 -> V_16 = true ;
}
return true ;
}
bool
V_3 ( struct V_1 * V_2 , int V_17 , struct V_3 * V_4 )
{
memset ( V_4 , 0x00 , sizeof( * V_4 ) ) ;
do {
V_4 -> V_12 += V_4 -> V_13 ;
if ( V_4 -> V_16 || ! F_1 ( V_2 , V_4 ) )
return false ;
} while( V_17 -- );
return true ;
}
