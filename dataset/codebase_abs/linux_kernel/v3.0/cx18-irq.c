static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 & V_4 )
F_2 ( & V_2 -> V_5 ) ;
if ( V_3 & V_6 )
F_2 ( & V_2 -> V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_8 )
{
if ( V_8 & V_9 )
F_4 ( V_2 , V_10 ) ;
if ( V_8 & V_11 )
F_4 ( V_2 , V_12 ) ;
}
T_2 F_5 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
T_1 V_8 , V_3 , V_15 ;
V_8 = F_6 ( V_2 , V_16 ) & V_2 -> V_17 ;
V_3 = F_6 ( V_2 , V_18 ) & V_2 -> V_19 ;
V_15 = F_6 ( V_2 , V_20 ) & V_2 -> V_21 ;
if ( V_8 )
F_7 ( V_2 , V_8 , V_16 , ~ V_8 , V_8 ) ;
if ( V_3 )
F_7 ( V_2 , V_3 , V_18 , ~ V_3 , V_3 ) ;
if ( V_15 )
F_7 ( V_2 , V_15 , V_20 , ~ V_15 , V_15 ) ;
if ( V_8 || V_3 || V_15 )
F_8 ( L_1
L_2 , V_8 , V_3 , V_15 ) ;
if ( V_8 )
F_3 ( V_2 , V_8 ) ;
if ( V_3 )
F_1 ( V_2 , V_3 ) ;
return ( V_8 || V_3 || V_15 ) ? V_22 : V_23 ;
}
