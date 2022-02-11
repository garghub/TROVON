static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_5 ;
V_5 = F_3 ( V_4 -> V_6 ) >> V_4 -> V_7 ;
V_5 &= ( 1 << V_4 -> V_8 ) - 1 ;
if ( V_5 && ( V_4 -> V_9 & V_10 ) )
V_5 = F_4 ( V_5 ) - 1 ;
if ( V_5 && ( V_4 -> V_9 & V_11 ) )
V_5 -- ;
if ( V_5 >= F_5 ( V_2 -> V_12 ) )
return - V_13 ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_5 ;
unsigned long V_9 = 0 ;
if ( V_4 -> V_9 & V_10 )
V_14 = ( 1 << F_4 ( V_14 ) ) ;
if ( V_4 -> V_9 & V_11 )
V_14 ++ ;
if ( V_4 -> V_15 )
F_7 ( V_4 -> V_15 , V_9 ) ;
V_5 = F_3 ( V_4 -> V_6 ) ;
V_5 &= ~ ( ( ( 1 << V_4 -> V_8 ) - 1 ) << V_4 -> V_7 ) ;
V_5 |= V_14 << V_4 -> V_7 ;
F_8 ( V_5 , V_4 -> V_6 ) ;
if ( V_4 -> V_15 )
F_9 ( V_4 -> V_15 , V_9 ) ;
return 0 ;
}
struct V_12 * F_10 ( struct V_16 * V_17 , const char * V_18 ,
const char * * V_19 , T_1 V_20 , unsigned long V_9 ,
void T_3 * V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_21 , T_4 * V_15 )
{
struct V_3 * V_4 ;
struct V_12 * V_12 ;
struct V_22 V_23 ;
V_4 = F_11 ( sizeof( struct V_3 ) , V_24 ) ;
if ( ! V_4 ) {
F_12 ( L_1 , V_25 ) ;
return F_13 ( - V_26 ) ;
}
V_23 . V_18 = V_18 ;
V_23 . V_27 = & V_28 ;
V_23 . V_9 = V_9 | V_29 ;
V_23 . V_19 = V_19 ;
V_23 . V_20 = V_20 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_21 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_2 . V_23 = & V_23 ;
V_12 = F_14 ( V_17 , & V_4 -> V_2 ) ;
if ( F_15 ( V_12 ) )
F_16 ( V_4 ) ;
return V_12 ;
}
