static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_2 ) ;
if ( V_4 && V_4 -> V_5 )
V_4 -> V_5 ( 0 ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_1 V_6 ;
struct V_7 * V_8 ;
V_8 = F_4 ( V_2 ) ;
if ( V_4 && V_4 -> V_5 )
V_4 -> V_5 ( 1 ) ;
V_6 = V_8 -> V_9 -> V_10 . V_11 ;
V_6 = F_5 ( V_6 , V_8 -> V_12 . V_13 ) ;
if ( V_4 &&
V_4 -> V_14 &&
V_4 -> V_14 ( & V_6 ) )
F_6 ( V_15
L_1 ,
V_16 , V_6 ) ;
if ( F_7 ( V_17 , V_6 ) < 0 )
F_6 ( V_15 L_2 ,
V_16 ) ;
V_3 = F_8 ( V_2 ) ;
return V_3 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_1 * V_18 = NULL ;
struct V_19 * V_20 = NULL ;
int V_21 ;
T_2 V_22 ;
T_1 V_6 ;
if ( ( V_2 -> V_23 == 0 ) && ( V_2 -> V_24 >= 0 ) ) {
V_4 = V_2 -> V_25 . V_26 ;
V_22 = F_10 ( & V_2 -> V_27 [ 0 ] ) ;
V_28 = F_11 ( V_2 -> V_27 [ 0 ] . V_29 , V_22 ) ;
F_12 ( L_3 ,
V_2 -> V_27 [ 0 ] . V_29 , ( int ) V_28 ) ;
if ( F_13 ( ! V_28 ) )
return - V_30 ;
if ( V_4 && V_4 -> V_5 )
V_4 -> V_5 ( 1 ) ;
V_31 = 1 ;
return 0 ;
}
if ( ! V_31 )
return - V_32 ;
V_8 = F_4 ( V_2 ) ;
if ( ! V_8 )
return - V_33 ;
if ( V_8 -> V_34 != V_35 )
return - V_36 ;
if ( V_37 >= V_38 )
return - V_30 ;
V_18 = F_14 ( L_4 , V_2 -> V_23 ) ;
if ( ! V_18 )
return - V_30 ;
V_8 -> V_2 = V_18 ;
V_8 -> V_39 = V_40 ;
if ( F_15
( V_18 , V_2 -> V_25 . V_26 ,
sizeof( struct V_19 ) ) ) {
F_6 ( V_15 L_5 ) ;
F_16 ( V_18 ) ;
return - V_30 ;
}
V_20 = V_18 -> V_25 . V_26 ;
V_20 -> V_41 = F_3 ;
V_20 -> V_42 = F_1 ;
V_20 -> V_43 = V_2 ;
V_8 -> V_12 = V_20 -> V_12 ;
V_8 -> V_44 = V_45 ;
V_6 = V_8 -> V_12 . V_13 ;
if ( V_4 &&
V_4 -> V_14 &&
V_4 -> V_14 ( & V_6 ) )
F_6 ( V_15
L_1 ,
V_16 , V_6 ) ;
if ( F_17 ( V_17 , V_6 ) < 0 )
F_6 ( V_15 L_6 , V_16 ) ;
V_8 -> V_12 . V_6 = V_8 -> V_12 . V_46 ;
F_18 ( V_18 , V_8 ) ;
V_21 = F_19 ( V_18 ) ;
if ( V_21 )
goto V_47;
V_48 [ V_37 ++ ] = V_2 ;
#ifdef F_20
V_8 -> V_49 . V_50 = V_51 ;
V_8 -> V_49 . V_52 = V_49 ;
V_8 -> V_49 . V_53 = V_54 ;
F_21 ( & V_8 -> V_49 ) ;
#endif
return 0 ;
V_47:
F_16 ( V_18 ) ;
return V_21 ;
}
void F_22 ( int V_55 )
{
T_3 V_56 = V_57 ;
if ( V_58 )
return;
if ( V_55 )
V_58 = 1 ;
if ( V_59 . V_60 )
F_23 ( & V_59 ) ;
V_61 = F_24 ( V_62 ) ;
F_25 ( V_62 , 0x0 ) ;
if ( F_7 ( V_17 , 0 ) < 0 )
F_6 ( V_15 L_2 , V_16 ) ;
F_26 ( V_17 ) ;
if ( V_63 )
F_26 ( V_63 ) ;
F_27 ( V_64 ) ;
if ( V_4 && V_4 -> V_5 )
V_4 -> V_5 ( 0 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_4 V_65 )
{
if ( V_66 )
return 0 ;
V_66 = 1 ;
F_22 ( 0 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_3 V_56 = V_57 ;
if ( ! V_66 )
return 0 ;
V_66 = 0 ;
if ( V_58 )
return 0 ;
F_30 ( V_64 ) ;
F_31 ( V_17 ) ;
if ( V_63 )
F_31 ( V_63 ) ;
F_25 ( V_62 , V_61 ) ;
if ( V_59 . V_60 )
F_32 ( 0 ) ;
return 0 ;
}
static void V_49 ( struct V_67 * V_68 )
{
T_4 V_65 ;
struct V_7 * V_8 = F_33 ( V_68 , struct V_7 ,
V_49 ) ;
V_65 . V_69 = V_70 ;
F_28 ( V_8 -> V_2 , V_65 ) ;
}
static void V_54 ( struct V_67 * V_68 )
{
struct V_7 * V_8 = F_33 ( V_68 , struct V_7 ,
V_49 ) ;
F_29 ( V_8 -> V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
if ( V_59 . V_60 )
F_23 ( & V_59 ) ;
F_35 ( V_28 ) ;
return 0 ;
}
static int F_36 ( void )
{
return F_37 ( & V_71 ) ;
}
static int T_5 F_38 ( void )
{
int V_3 ;
V_17 = F_39 ( NULL , L_7 ) ;
if ( F_40 ( V_17 ) ) {
F_6 ( V_15 L_8 ) ;
return F_41 ( V_17 ) ;
}
F_31 ( V_17 ) ;
V_63 = F_39 ( NULL , L_9 ) ;
if ( F_40 ( V_63 ) )
V_63 = NULL ;
else
F_31 ( V_63 ) ;
V_3 = F_36 () ;
if ( V_3 ) {
F_26 ( V_17 ) ;
F_42 ( V_17 ) ;
if ( V_63 ) {
F_26 ( V_63 ) ;
F_42 ( V_63 ) ;
}
F_6 ( V_15 L_10 ) ;
return V_3 ;
}
F_43 () ;
return V_3 ;
}
