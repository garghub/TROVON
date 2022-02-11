static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_2 ) ;
F_3 () ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_1 V_4 ;
struct V_5 * V_6 ;
V_6 = F_5 ( V_2 ) ;
V_4 = V_6 -> V_7 -> V_8 . V_9 ;
V_4 = F_6 ( V_4 , V_6 -> V_10 . V_11 ) ;
if ( V_12 &&
V_12 -> V_13 &&
V_12 -> V_13 ( & V_4 ) )
F_7 ( V_14
L_1 ,
V_15 , V_4 ) ;
if ( F_8 ( V_16 , V_4 ) < 0 )
F_7 ( V_14 L_2 ,
V_15 ) ;
F_9 () ;
V_3 = F_10 ( V_2 ) ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_1 * V_17 = NULL ;
struct V_18 * V_19 = NULL ;
int V_20 ;
T_2 V_21 ;
T_1 V_4 ;
if ( ( V_2 -> V_22 == 0 ) && ( V_2 -> V_23 >= 0 ) ) {
V_12 = V_2 -> V_24 . V_25 ;
V_21 = F_12 ( & V_2 -> V_26 [ 0 ] ) ;
V_27 = F_13 ( V_2 -> V_26 [ 0 ] . V_28 , V_21 ) ;
F_14 ( L_3 ,
V_2 -> V_26 [ 0 ] . V_28 ) ;
if ( F_15 ( ! V_27 ) )
return - V_29 ;
V_30 = 1 ;
return 0 ;
}
if ( ! V_30 )
return - V_31 ;
V_6 = F_5 ( V_2 ) ;
if ( ! V_6 )
return - V_32 ;
if ( V_6 -> V_33 != V_34 )
return - V_35 ;
if ( V_36 >= V_37 )
return - V_29 ;
V_17 = F_16 ( L_4 , V_2 -> V_22 ) ;
if ( ! V_17 )
return - V_29 ;
V_6 -> V_2 = V_17 ;
V_6 -> V_38 = V_39 ;
if ( F_17
( V_17 , V_2 -> V_24 . V_25 ,
sizeof( struct V_18 ) ) ) {
F_7 ( V_14 L_5 ) ;
F_18 ( V_17 ) ;
return - V_29 ;
}
V_19 = V_17 -> V_24 . V_25 ;
V_19 -> V_40 = F_4 ;
V_19 -> V_41 = F_1 ;
V_19 -> V_42 = V_2 ;
V_6 -> V_10 = V_19 -> V_10 ;
V_6 -> V_43 = V_44 ;
V_4 = V_6 -> V_10 . V_11 ;
if ( V_12 &&
V_12 -> V_13 &&
V_12 -> V_13 ( & V_4 ) )
F_7 ( V_14
L_1 ,
V_15 , V_4 ) ;
if ( F_19 ( V_16 , V_4 ) < 0 )
F_7 ( V_14 L_6 , V_15 ) ;
V_6 -> V_10 . V_4 = V_6 -> V_10 . V_45 ;
F_20 ( V_17 , V_6 ) ;
V_20 = F_21 ( V_17 ) ;
if ( V_20 )
goto V_46;
V_47 [ V_36 ++ ] = V_2 ;
#ifdef F_22
V_6 -> V_48 . V_49 = V_50 ;
V_6 -> V_48 . V_51 = V_48 ;
V_6 -> V_48 . V_52 = V_53 ;
F_23 ( & V_6 -> V_48 ) ;
#endif
return 0 ;
V_46:
F_18 ( V_17 ) ;
return V_20 ;
}
static int F_24 ( struct V_1 * V_2 , T_3 V_54 )
{
if ( V_55 )
return 0 ;
V_55 = 1 ;
if ( F_8 ( V_16 , 0 ) < 0 )
F_7 ( V_14 L_2 , V_15 ) ;
F_25 ( V_16 ) ;
F_26 ( V_56 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_5 ( V_2 ) ;
if ( ! V_55 )
return 0 ;
V_55 = 0 ;
F_28 ( V_56 ) ;
F_29 ( V_16 ) ;
return 0 ;
}
static void V_48 ( struct V_57 * V_58 )
{
T_3 V_54 ;
struct V_5 * V_6 = F_30 ( V_58 , struct V_5 ,
V_48 ) ;
V_54 . V_59 = V_60 ;
F_24 ( V_6 -> V_2 , V_54 ) ;
}
static void V_53 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_30 ( V_58 , struct V_5 ,
V_48 ) ;
F_27 ( V_6 -> V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
F_32 ( V_27 ) ;
return 0 ;
}
static int F_33 ( void )
{
return F_34 ( & V_61 ) ;
}
static int T_4 F_35 ( void )
{
int V_3 ;
V_16 = F_36 ( NULL , L_7 ) ;
if ( F_37 ( V_16 ) ) {
F_7 ( V_14 L_8 ) ;
return F_38 ( V_16 ) ;
}
F_29 ( V_16 ) ;
V_3 = F_33 () ;
if ( V_3 ) {
F_25 ( V_16 ) ;
F_39 ( V_16 ) ;
F_7 ( V_14 L_9 ) ;
return V_3 ;
}
F_40 () ;
return V_3 ;
}
