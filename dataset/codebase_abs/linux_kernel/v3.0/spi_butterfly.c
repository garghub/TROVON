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
F_9 ( struct V_2 * V_3 ,
unsigned V_21 ,
T_2 V_22 , T_1 V_23 )
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
if ( V_1 || ! V_32 )
return;
V_30 = F_12 ( V_32 , sizeof *V_6 ) ;
if ( ! V_30 ) {
V_28 = - V_34 ;
goto V_35;
}
V_6 = F_13 ( V_30 ) ;
V_30 -> V_36 = 42 ;
V_30 -> V_37 = 2 ;
V_6 -> V_38 . V_30 = F_14 ( V_30 ) ;
V_6 -> V_38 . V_39 = F_7 ;
V_6 -> V_38 . V_40 [ V_41 ] = F_9 ;
V_6 -> V_11 = V_25 ;
V_27 = F_15 ( V_25 , L_1 ,
NULL , NULL , NULL ,
0 , V_6 ) ;
if ( ! V_27 ) {
V_28 = - V_34 ;
goto V_42;
}
V_6 -> V_27 = V_27 ;
V_28 = F_16 ( V_27 ) ;
if ( V_28 < 0 )
goto V_43;
F_17 ( L_2 , V_25 -> V_44 ) ;
F_8 ( V_6 -> V_11 , V_19 , 0 ) ;
V_6 -> V_9 |= V_45 ;
F_3 ( V_6 -> V_11 , V_6 -> V_9 ) ;
F_18 ( 5 ) ;
V_6 -> V_9 |= V_46 ;
F_3 ( V_6 -> V_11 , V_6 -> V_9 ) ;
F_18 ( 100 ) ;
V_28 = F_19 ( & V_6 -> V_38 ) ;
if ( V_28 < 0 )
goto V_47;
V_6 -> V_48 [ 0 ] . V_49 = 15 * 1000 * 1000 ;
strcpy ( V_6 -> V_48 [ 0 ] . V_50 , L_3 ) ;
V_6 -> V_48 [ 0 ] . V_51 = & V_52 ;
V_6 -> V_48 [ 0 ] . V_53 = 1 ;
V_6 -> V_48 [ 0 ] . V_4 = V_6 ;
V_6 -> V_54 = F_20 ( V_6 -> V_38 . V_30 , & V_6 -> V_48 [ 0 ] ) ;
if ( V_6 -> V_54 )
F_17 ( L_4 , V_25 -> V_44 ,
F_21 ( & V_6 -> V_54 -> V_32 ) ) ;
F_22 ( L_5 , V_25 -> V_44 ) ;
V_1 = V_6 ;
return;
V_47:
F_3 ( V_6 -> V_11 , 0 ) ;
F_23 ( V_6 -> V_27 ) ;
V_43:
F_24 ( V_27 ) ;
V_42:
( void ) F_25 ( V_6 -> V_38 . V_30 ) ;
V_35:
F_17 ( L_6 , V_25 -> V_44 , V_28 ) ;
}
static void F_26 ( struct V_24 * V_25 )
{
struct V_1 * V_6 ;
int V_28 ;
if ( ! V_1 || V_1 -> V_11 != V_25 )
return;
V_6 = V_1 ;
V_1 = NULL ;
V_28 = F_27 ( & V_6 -> V_38 ) ;
F_3 ( V_6 -> V_11 , 0 ) ;
F_18 ( 10 ) ;
F_23 ( V_6 -> V_27 ) ;
F_24 ( V_6 -> V_27 ) ;
( void ) F_25 ( V_6 -> V_38 . V_30 ) ;
}
static int T_3 F_28 ( void )
{
return F_29 ( & V_55 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_55 ) ;
}
