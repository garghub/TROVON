static void T_1 F_1 ( void )
{
struct V_1 V_2 = {
. V_3 = L_1 ,
. V_4 = - 1 ,
. V_5 = V_6 ,
. V_7 = F_2 ( V_6 ) ,
. V_8 = & V_9 ,
. V_10 = sizeof( V_9 ) ,
. V_11 = F_3 ( 32 ) ,
} ;
F_4 ( & V_2 ) ;
}
static void T_1 F_5 ( unsigned V_12 ,
struct V_13 * V_14 )
{
struct V_1 V_15 = {
. V_16 = & V_17 ,
. V_3 = L_2 ,
. V_4 = V_12 ,
. V_5 = & V_18 [ V_12 * 2 ] ,
. V_7 = 2 ,
. V_11 = F_3 ( 32 ) ,
. V_8 = V_14 ,
. V_10 = sizeof( * V_14 ) ,
} ;
F_6 ( V_12 > 1 ) ;
F_4 ( & V_15 ) ;
}
static void T_1 F_7 ( void )
{
F_8 ( & V_17 , L_3 , 1 ,
& V_19 , sizeof( V_19 ) ) ;
F_5 ( 1 , & V_20 ) ;
}
static int F_9 ( struct V_21 * V_22 ,
void T_2 * V_23 , int V_24 )
{
struct V_25 * V_26 = F_10 ( V_22 ) ;
if ( ! V_26 -> V_27 )
return - V_28 ;
if ( V_24 ) {
int V_29 = F_11 ( V_26 -> V_27 ) ;
if ( ! V_29 )
V_29 = F_12 ( V_26 -> V_27 , 0 ) ;
return V_29 ;
}
F_12 ( V_26 -> V_27 , 1 ) ;
F_13 ( V_26 -> V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_25 * V_26 = F_10 ( V_22 ) ;
struct V_30 * V_27 ;
int V_31 ;
F_15 ( F_16 ( 5 , 18 ) , V_32 , NULL ) ;
if ( ! F_17 ( F_16 ( 5 , 18 ) ) ) {
F_18 ( L_4 ) ;
V_31 = - V_33 ;
goto error;
}
V_27 = F_19 ( & V_22 -> V_34 , 0 ) ;
if ( F_20 ( V_27 ) ) {
V_31 = F_21 ( V_27 ) ;
goto error;
}
V_26 -> V_27 = V_27 ;
return 0 ;
error:
F_22 ( F_16 ( 5 , 18 ) ) ;
return V_31 ;
}
static int F_23 ( struct V_21 * V_22 )
{
struct V_25 * V_26 = F_10 ( V_22 ) ;
if ( ! V_26 -> V_27 )
return 0 ;
F_24 ( V_26 -> V_27 ) ;
V_26 -> V_27 = NULL ;
F_22 ( F_16 ( 5 , 18 ) ) ;
return 0 ;
}
static int F_25 ( struct V_21 * V_22 )
{
return V_35 ;
}
static void T_1 F_26 ( void )
{
F_27 ( L_5 , 0 , L_6 ) ;
F_28 ( & V_17 ,
L_5 , - 1 ,
V_36 ,
F_2 ( V_36 ) ,
& V_37 . V_2 ,
sizeof( V_37 . V_2 ) ) ;
}
static void T_1 F_29 ( void )
{
struct V_1 V_38 = {
. V_16 = & V_17 ,
. V_3 = L_7 ,
. V_4 = - 1 ,
. V_8 = & V_39 ,
. V_10 = sizeof( struct V_40 ) ,
. V_11 = F_3 ( 32 ) ,
} ;
F_30 ( 2 , V_41 ,
F_2 ( V_41 ) ) ;
F_28 (
& V_17 , L_8 , - 1 ,
V_42 , F_2 ( V_42 ) ,
& V_43 , sizeof( V_43 ) ) ;
F_4 ( & V_38 ) ;
}
static void T_1 F_31 ( void )
{
F_4 ( & V_44 ) ;
}
static void T_1 F_32 ( void )
{
F_4 ( & V_45 ) ;
}
static void T_1 F_33 ( void )
{
int V_46 = 0 ;
int V_47 = 0 ;
F_34 () ;
F_35 ( V_48 ,
F_2 ( V_48 ) ) ;
F_36 () ;
F_37 () ;
F_8 ( & V_17 , L_9 , - 1 ,
& V_49 ,
sizeof( V_49 ) ) ;
F_8 ( & V_17 , L_10 , - 1 ,
& V_50 ,
sizeof( V_50 ) ) ;
F_38 ( V_46 ++ ,
L_11 , V_51 ,
F_2 ( V_51 ) , 3300000 ) ;
F_28 ( & V_17 , L_12 , 1 ,
V_52 , F_2 ( V_52 ) ,
& V_53 , sizeof( V_53 ) ) ;
F_4 ( & V_54 ) ;
F_1 () ;
F_28 ( & V_17 , L_13 , 0 ,
V_55 ,
F_2 ( V_55 ) ,
& V_56 , sizeof( V_56 ) ) ;
F_39 ( V_57 , F_2 ( V_57 ) ) ;
F_8 ( & V_17 , L_14 , V_46 ++ ,
& V_58 , sizeof( struct V_59 ) ) ;
F_8 ( & V_17 , L_14 , V_46 ++ ,
& V_60 , sizeof( struct V_59 ) ) ;
F_8 ( & V_17 , L_15 , V_47 ++ ,
& V_61 , sizeof( struct V_62 ) ) ;
F_8 ( & V_17 , L_15 , V_47 ++ ,
& V_63 , sizeof( struct V_62 ) ) ;
F_7 () ;
F_4 ( & V_64 ) ;
F_28 ( & V_17 , L_6 ,
- 1 , V_65 ,
F_2 ( V_65 ) ,
& V_66 ,
sizeof( V_66 ) ) ;
F_26 () ;
F_31 () ;
F_32 () ;
F_29 () ;
F_28 ( & V_17 , L_16 , 0 ,
V_67 , F_2 ( V_67 ) ,
& V_68 , sizeof( struct V_69 ) ) ;
F_28 ( & V_17 , L_16 , 2 ,
V_70 , F_2 ( V_70 ) ,
& V_71 , sizeof( struct V_69 ) ) ;
}
static int F_40 ( struct V_72 * V_73 )
{
T_3 V_74 = F_41 ( V_73 , 0x1e ) ;
V_74 &= ~ 0xc000 ;
V_74 |= 0x4000 ;
return F_42 ( V_73 , 0x1e , V_74 ) ;
}
static void T_1 F_43 ( void )
{
F_33 () ;
F_44 ( F_45 ( 0 ) , V_75 ) ;
if ( F_46 ( V_76 ) )
F_47 ( L_17 ,
F_40 ) ;
}
