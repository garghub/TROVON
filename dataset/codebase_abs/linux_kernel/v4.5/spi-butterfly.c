static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static inline void
F_2 ( struct V_2 * V_3 , int V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 , V_8 = V_6 -> V_9 ;
V_7 = V_10 ;
if ( V_5 )
V_8 |= V_7 ;
else
V_8 &= ~ V_7 ;
F_3 ( V_6 -> V_11 , V_8 ) ;
V_6 -> V_9 = V_8 ;
}
static inline void
F_4 ( struct V_2 * V_3 , int V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_7 , V_8 = V_6 -> V_9 ;
V_7 = V_12 ;
if ( V_5 )
V_8 |= V_7 ;
else
V_8 &= ~ V_7 ;
F_3 ( V_6 -> V_11 , V_8 ) ;
V_6 -> V_9 = V_8 ;
}
static inline int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_13 ;
T_1 V_7 ;
V_7 = V_14 ;
V_13 = ! ( F_6 ( V_6 -> V_11 ) & V_7 ) ;
return ( V_7 == V_15 ) ? V_13 : ! V_13 ;
}
static void F_7 ( struct V_2 * V_3 , int V_13 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( V_13 != V_16 )
F_2 ( V_3 , V_3 -> V_17 & V_18 ) ;
if ( V_19 == V_20 )
V_13 = ! V_13 ;
F_8 ( V_6 -> V_11 , V_19 , V_13 ? V_19 : 0 ) ;
}
static T_2
F_9 ( struct V_2 * V_3 , unsigned V_21 , T_2 V_22 ,
T_1 V_23 )
{
return F_10 ( V_3 , V_21 , 0 , 0 , V_22 , V_23 ) ;
}
static void F_11 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
struct V_1 * V_6 ;
struct V_29 * V_30 ;
struct V_31 * V_32 = V_25 -> V_33 -> V_32 ;
struct V_34 V_35 ;
if ( V_1 || ! V_32 )
return;
V_30 = F_12 ( V_32 , sizeof( * V_6 ) ) ;
if ( ! V_30 ) {
V_28 = - V_36 ;
goto V_37;
}
V_6 = F_13 ( V_30 ) ;
V_30 -> V_38 = 42 ;
V_30 -> V_39 = 2 ;
V_6 -> V_40 . V_30 = V_30 ;
V_6 -> V_40 . V_41 = F_7 ;
V_6 -> V_40 . V_42 [ V_43 ] = F_9 ;
V_6 -> V_11 = V_25 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_44 = V_6 ;
V_27 = F_14 ( V_25 , L_1 , & V_35 , 0 ) ;
if ( ! V_27 ) {
V_28 = - V_36 ;
goto V_45;
}
V_6 -> V_27 = V_27 ;
V_28 = F_15 ( V_27 ) ;
if ( V_28 < 0 )
goto V_46;
F_16 ( L_2 , V_25 -> V_47 ) ;
F_8 ( V_6 -> V_11 , V_19 , 0 ) ;
V_6 -> V_9 |= V_48 ;
F_3 ( V_6 -> V_11 , V_6 -> V_9 ) ;
F_17 ( 5 ) ;
V_6 -> V_9 |= V_49 ;
F_3 ( V_6 -> V_11 , V_6 -> V_9 ) ;
F_17 ( 100 ) ;
V_28 = F_18 ( & V_6 -> V_40 ) ;
if ( V_28 < 0 )
goto V_50;
V_6 -> V_51 [ 0 ] . V_52 = 15 * 1000 * 1000 ;
strcpy ( V_6 -> V_51 [ 0 ] . V_53 , L_3 ) ;
V_6 -> V_51 [ 0 ] . V_54 = & V_55 ;
V_6 -> V_51 [ 0 ] . V_56 = 1 ;
V_6 -> V_51 [ 0 ] . V_4 = V_6 ;
V_6 -> V_57 = F_19 ( V_6 -> V_40 . V_30 , & V_6 -> V_51 [ 0 ] ) ;
if ( V_6 -> V_57 )
F_16 ( L_4 , V_25 -> V_47 ,
F_20 ( & V_6 -> V_57 -> V_32 ) ) ;
F_21 ( L_5 , V_25 -> V_47 ) ;
V_1 = V_6 ;
return;
V_50:
F_3 ( V_6 -> V_11 , 0 ) ;
F_22 ( V_6 -> V_27 ) ;
V_46:
F_23 ( V_27 ) ;
V_45:
F_24 ( V_6 -> V_40 . V_30 ) ;
V_37:
F_16 ( L_6 , V_25 -> V_47 , V_28 ) ;
}
static void F_25 ( struct V_24 * V_25 )
{
struct V_1 * V_6 ;
if ( ! V_1 || V_1 -> V_11 != V_25 )
return;
V_6 = V_1 ;
V_1 = NULL ;
F_26 ( & V_6 -> V_40 ) ;
F_3 ( V_6 -> V_11 , 0 ) ;
F_17 ( 10 ) ;
F_22 ( V_6 -> V_27 ) ;
F_23 ( V_6 -> V_27 ) ;
F_24 ( V_6 -> V_40 . V_30 ) ;
}
static int T_3 F_27 ( void )
{
return F_28 ( & V_58 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_58 ) ;
}
