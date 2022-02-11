static inline void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_3 + 1 ) ;
}
static inline int F_3 ( int V_1 )
{
F_2 ( V_1 , V_3 ) ;
return F_4 ( V_3 + 1 ) ;
}
static int F_5 ( void )
{
int V_4 ;
V_3 = V_5 ;
V_4 = F_3 ( V_6 ) ;
if ( V_4 == V_7 || V_4 == V_8 )
return V_3 ;
V_3 = V_9 ;
V_4 = F_3 ( V_6 ) ;
if ( V_4 == V_7 || V_4 == V_8 )
return V_3 ;
return 0 ;
}
static void F_6 ( unsigned V_10 )
{
F_1 ( V_11 , V_10 ) ;
V_12 = V_10 ;
}
static void F_7 ( unsigned V_13 )
{
F_6 ( V_14 ) ;
F_1 ( V_15 ,
( ( V_13 << 1 ) & 0xF0 ) | ( V_13 & 0x7 ) ) ;
}
static inline T_1 F_8 ( unsigned V_16 , T_1 V_17 , T_1 V_18 ,
T_1 V_19 )
{
T_1 V_20 , V_21 ;
F_9 ( & V_22 ) ;
F_6 ( V_14 ) ;
F_7 ( V_16 ) ;
V_20 = F_3 ( V_19 ) ;
V_21 = ( V_20 & V_17 ) | V_18 ;
F_1 ( V_19 , V_21 ) ;
F_10 ( & V_22 ) ;
return V_20 ;
}
static T_1 F_11 ( unsigned V_16 , T_1 V_17 , T_1 V_18 )
{
return F_8 ( V_16 , V_17 , V_18 ,
V_23 ) ;
}
static int F_12 ( unsigned V_24 )
{
int V_25 , V_26 , V_2 ;
V_25 = V_24 >> 3 ;
V_26 = V_24 & 7 ;
V_2 = F_4 ( V_27 + V_28 [ V_25 ] + V_29 ) ;
V_2 >>= V_26 ;
V_2 &= 1 ;
F_13 ( & V_30 -> V_31 , L_1 ,
V_24 , V_27 + V_28 [ V_25 ] + V_29 , V_26 ,
V_2 ) ;
return V_2 ;
}
static void F_14 ( unsigned V_24 , int V_2 )
{
int V_25 , V_26 , V_32 ;
V_24 &= 0x1f ;
V_25 = V_24 >> 3 ;
V_26 = V_24 & 7 ;
V_32 = F_4 ( V_27 + V_28 [ V_25 ] + V_33 ) ;
F_13 ( & V_30 -> V_31 , L_2 ,
V_27 + V_28 [ V_25 ] + V_33 ,
V_32 , V_26 , ( V_32 & ~ ( 1 << V_26 ) ) , V_2 , ( V_2 << V_26 ) ) ;
V_2 = ( V_32 & ~ ( 1 << V_26 ) ) | ( V_2 << V_26 ) ;
F_13 ( & V_30 -> V_31 , L_3
L_4 , V_24 , V_25 , V_26 , V_32 , V_2 ) ;
F_2 ( V_2 , V_27 + V_28 [ V_25 ] + V_33 ) ;
V_32 = F_4 ( V_27 + V_28 [ V_25 ] + V_33 ) ;
V_2 = F_4 ( V_27 + V_28 [ V_25 ] + V_29 ) ;
F_13 ( & V_30 -> V_31 , L_5 , V_32 , V_2 ) ;
V_34 [ V_25 ] = V_2 ;
}
static int F_15 ( unsigned V_24 )
{
int V_25 , V_26 ;
V_24 &= 0x1f ;
V_25 = V_24 >> 3 ;
V_26 = V_24 & 7 ;
return ( ( V_34 [ V_25 ] >> V_26 ) & 0x01 ) ;
}
static void F_16 ( unsigned V_16 )
{
F_14 ( V_16 , ! F_15 ( V_16 ) ) ;
}
static int F_17 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
unsigned V_37 = V_13 ( V_35 ) ;
V_36 -> V_38 = & V_39 ;
F_13 ( & V_30 -> V_31 , L_6 , V_37 ) ;
if ( V_37 >= V_40 )
return - V_41 ;
return F_18 ( V_35 , V_36 ) ;
}
static void T_2 F_19 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < 4 ; ++ V_25 )
V_34 [ V_25 ]
= F_4 ( V_27 + V_28 [ V_25 ]
+ V_33 ) ;
}
static int T_2 F_20 ( void )
{
int V_42 ;
T_3 V_43 ;
V_30 = F_21 ( V_44 , 0 ) ;
if ( ! V_30 )
return - V_45 ;
V_42 = F_22 ( V_30 ) ;
if ( V_42 ) {
V_42 = - V_46 ;
goto V_47;
}
F_23 ( & V_30 -> V_31 , L_7 ) ;
if ( ! F_5 () ) {
V_42 = - V_46 ;
F_24 ( & V_30 -> V_31 , L_8 ) ;
goto V_48;
}
V_39 . V_31 = & V_30 -> V_31 ;
V_42 = F_3 ( V_49 ) ;
if ( ! ( V_42 & 0x01 ) ) {
V_42 = - V_46 ;
F_24 ( & V_30 -> V_31 , L_9 ) ;
goto V_48;
}
F_6 ( V_14 ) ;
if ( ! F_3 ( V_50 ) ) {
V_42 = - V_46 ;
F_24 ( & V_30 -> V_31 , L_10 ) ;
goto V_48;
}
V_27 = ( F_3 ( V_51 ) << 8
| F_3 ( V_52 ) ) ;
if ( ! F_25 ( V_27 , V_53 , V_44 ) ) {
V_42 = - V_46 ;
F_24 ( & V_30 -> V_31 , L_11 ,
V_27 ) ;
goto V_48;
}
F_23 ( & V_30 -> V_31 , L_12 , V_27 ) ;
if ( V_54 ) {
V_43 = F_26 ( V_54 , 0 ) ;
V_42 = F_27 ( V_43 , V_40 , V_44 ) ;
} else {
V_42 = F_28 ( & V_43 , 0 , V_40 , V_44 ) ;
V_54 = F_29 ( V_43 ) ;
}
if ( V_42 < 0 ) {
F_24 ( & V_30 -> V_31 , L_13 , V_42 ) ;
goto V_55;
}
if ( ! V_54 ) {
V_54 = V_42 ;
F_13 ( & V_30 -> V_31 , L_14 , V_54 ) ;
}
F_19 () ;
F_30 ( & V_56 , & V_57 ) ;
F_31 ( & V_56 , V_43 , V_40 ) ;
return 0 ;
V_55:
F_32 ( V_27 , V_53 ) ;
V_48:
F_33 ( V_30 ) ;
V_47:
F_34 ( V_30 ) ;
return V_42 ;
}
static void T_4 F_35 ( void )
{
F_13 ( & V_30 -> V_31 , L_15 ) ;
F_36 ( & V_56 ) ;
F_37 ( F_26 ( V_54 , 0 ) , V_40 ) ;
F_32 ( V_27 , V_53 ) ;
F_38 ( V_30 ) ;
}
