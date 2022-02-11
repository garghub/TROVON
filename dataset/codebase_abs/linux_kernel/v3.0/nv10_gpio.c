static bool
F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
T_1 * V_5 )
{
if ( V_2 -> line < 2 ) {
* V_3 = V_6 ;
* V_4 = V_2 -> line * 16 ;
* V_5 = 0x11 ;
} else if ( V_2 -> line < 10 ) {
* V_3 = V_7 ;
* V_4 = ( V_2 -> line - 2 ) * 4 ;
* V_5 = 0x3 ;
} else if ( V_2 -> line < 14 ) {
* V_3 = V_8 ;
* V_4 = ( V_2 -> line - 10 ) * 4 ;
* V_5 = 0x3 ;
} else {
return false ;
}
return true ;
}
int
F_2 ( struct V_9 * V_10 , enum V_11 V_12 )
{
struct V_1 * V_2 = F_3 ( V_10 , V_12 ) ;
T_1 V_3 , V_4 , V_5 , V_13 ;
if ( ! V_2 )
return - V_14 ;
if ( ! F_1 ( V_2 , & V_3 , & V_4 , & V_5 ) )
return - V_14 ;
V_13 = F_4 ( V_10 , 0 , V_3 ) >> V_4 ;
return ( V_2 -> V_15 ? 1 : 0 ) ^ ( V_13 & 1 ) ;
}
int
F_5 ( struct V_9 * V_10 , enum V_11 V_12 , int V_16 )
{
struct V_1 * V_2 = F_3 ( V_10 , V_12 ) ;
T_1 V_3 , V_4 , V_5 , V_13 ;
if ( ! V_2 )
return - V_14 ;
if ( ! F_1 ( V_2 , & V_3 , & V_4 , & V_5 ) )
return - V_14 ;
V_13 = ( ( V_2 -> V_15 ? 1 : 0 ) ^ ( V_16 ? 1 : 0 ) ) << V_4 ;
V_5 = ~ ( V_5 << V_4 ) ;
F_6 ( V_10 , 0 , V_3 , V_13 | ( F_4 ( V_10 , 0 , V_3 ) & V_5 ) ) ;
return 0 ;
}
