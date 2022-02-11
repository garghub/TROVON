void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , V_4 , & V_3 ) ;
F_3 ( V_5 L_1 , F_4 ( V_2 ) , V_3 ) ;
F_5 ( V_2 , V_4 , V_3 ) ;
}
T_2
F_6 ( void * V_6 , const struct V_7 * V_8 ,
T_2 V_9 , T_2 V_10 )
{
T_2 V_11 = V_8 -> V_11 ;
if ( ( V_8 -> V_12 & V_13 ) && ( V_11 & 0x300 ) )
V_11 = ( V_11 + 0x3ff ) & ~ 0x3ff ;
return V_11 ;
}
int F_7 ( struct V_1 * V_2 , int V_14 )
{
T_3 V_15 , V_16 ;
int V_17 ;
struct V_7 * V_18 ;
F_8 ( V_2 , V_19 , & V_15 ) ;
V_16 = V_15 ;
for( V_17 = 0 ; V_17 < 6 ; V_17 ++ ) {
if ( ! ( V_14 & ( 1 << V_17 ) ) )
continue;
V_18 = & V_2 -> V_7 [ V_17 ] ;
if ( ! V_18 -> V_11 && V_18 -> V_20 ) {
F_3 ( V_21 L_2 , F_4 ( V_2 ) ) ;
return - V_22 ;
}
if ( V_18 -> V_12 & V_13 )
V_15 |= V_23 ;
if ( V_18 -> V_12 & V_24 )
V_15 |= V_25 ;
}
if ( V_2 -> V_7 [ V_26 ] . V_11 )
V_15 |= V_25 ;
if ( V_15 != V_16 ) {
F_3 ( L_3 , F_4 ( V_2 ) , V_16 , V_15 ) ;
F_9 ( V_2 , V_19 , V_15 ) ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
V_2 -> V_27 = V_28 ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , int V_14 )
{
int V_29 ;
if ( ( V_29 = F_7 ( V_2 , V_14 ) ) < 0 )
return V_29 ;
if ( ! V_2 -> V_30 )
F_10 ( V_2 ) ;
return 0 ;
}
