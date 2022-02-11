void T_1 F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_3 * V_4 )
{
T_2 V_5 ;
F_3 ( V_4 , V_6 , & V_5 ) ;
F_4 ( V_7 L_1 , F_5 ( V_4 ) , V_5 ) ;
F_6 ( V_4 , V_6 , V_5 ) ;
}
int F_7 ( struct V_3 * V_4 , struct V_8 * V_9 ,
enum V_10 V_11 , int V_12 )
{
unsigned long V_13 ;
V_13 = F_8 ( V_9 -> V_14 ) ;
V_9 -> V_14 = F_9 ( V_13 ) ;
if ( F_10 ( V_9 , V_9 -> V_15 , V_9 -> V_16 ,
V_9 -> V_17 - V_9 -> V_15 ,
V_9 -> V_14 ) )
return - V_18 ;
return 0 ;
}
T_3
F_11 ( void * V_19 , const struct V_20 * V_21 ,
T_3 V_22 , T_3 V_23 )
{
T_3 V_24 = V_21 -> V_24 ;
if ( ( V_21 -> V_25 & V_26 ) && ( V_24 & 0x300 ) )
V_24 = ( V_24 + 0x3ff ) & ~ 0x3ff ;
return V_24 ;
}
int F_12 ( struct V_3 * V_4 , int V_27 )
{
T_4 V_28 , V_29 ;
int V_30 ;
struct V_20 * V_31 ;
F_13 ( V_4 , V_32 , & V_28 ) ;
V_29 = V_28 ;
for( V_30 = 0 ; V_30 < 6 ; V_30 ++ ) {
if ( ! ( V_27 & ( 1 << V_30 ) ) )
continue;
V_31 = & V_4 -> V_20 [ V_30 ] ;
if ( ! V_31 -> V_24 && V_31 -> V_33 ) {
F_4 ( V_34 L_2 , F_5 ( V_4 ) ) ;
return - V_35 ;
}
if ( V_31 -> V_25 & V_26 )
V_28 |= V_36 ;
if ( V_31 -> V_25 & V_37 )
V_28 |= V_38 ;
}
if ( V_4 -> V_20 [ V_39 ] . V_24 )
V_28 |= V_38 ;
if ( V_28 != V_29 ) {
F_4 ( L_3 , F_5 ( V_4 ) , V_29 , V_28 ) ;
F_14 ( V_4 , V_32 , V_28 ) ;
}
return 0 ;
}
int F_15 ( struct V_3 * V_4 )
{
V_4 -> V_40 = V_41 ;
return 0 ;
}
int F_16 ( struct V_3 * V_4 , int V_27 )
{
int V_42 ;
if ( ( V_42 = F_12 ( V_4 , V_27 ) ) < 0 )
return V_42 ;
if ( ! V_4 -> V_43 )
F_15 ( V_4 ) ;
return 0 ;
}
