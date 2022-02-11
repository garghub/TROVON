void F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_3 * V_4 )
{
T_1 V_5 ;
F_3 ( V_4 , V_6 , & V_5 ) ;
F_4 ( V_7 L_1 , F_5 ( V_4 ) , V_5 ) ;
F_6 ( V_4 , V_6 , V_5 ) ;
}
T_2
F_7 ( void * V_8 , const struct V_9 * V_10 ,
T_2 V_11 , T_2 V_12 )
{
T_2 V_13 = V_10 -> V_13 ;
if ( ( V_10 -> V_14 & V_15 ) && ( V_13 & 0x300 ) )
V_13 = ( V_13 + 0x3ff ) & ~ 0x3ff ;
return V_13 ;
}
int F_8 ( struct V_3 * V_4 , int V_16 )
{
T_3 V_17 , V_18 ;
int V_19 ;
struct V_9 * V_20 ;
F_9 ( V_4 , V_21 , & V_17 ) ;
V_18 = V_17 ;
for( V_19 = 0 ; V_19 < 6 ; V_19 ++ ) {
if ( ! ( V_16 & ( 1 << V_19 ) ) )
continue;
V_20 = & V_4 -> V_9 [ V_19 ] ;
if ( ! V_20 -> V_13 && V_20 -> V_22 ) {
F_4 ( V_23 L_2 , F_5 ( V_4 ) ) ;
return - V_24 ;
}
if ( V_20 -> V_14 & V_15 )
V_17 |= V_25 ;
if ( V_20 -> V_14 & V_26 )
V_17 |= V_27 ;
}
if ( V_4 -> V_9 [ V_28 ] . V_13 )
V_17 |= V_27 ;
if ( V_17 != V_18 ) {
F_4 ( L_3 , F_5 ( V_4 ) , V_18 , V_17 ) ;
F_10 ( V_4 , V_21 , V_17 ) ;
}
return 0 ;
}
int F_11 ( struct V_3 * V_4 )
{
V_4 -> V_29 = V_30 ;
return 0 ;
}
int F_12 ( struct V_3 * V_4 , int V_16 )
{
int V_31 ;
if ( ( V_31 = F_8 ( V_4 , V_16 ) ) < 0 )
return V_31 ;
if ( ! V_4 -> V_32 )
F_11 ( V_4 ) ;
return 0 ;
}
