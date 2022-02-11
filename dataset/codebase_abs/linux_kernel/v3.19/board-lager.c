static void T_1 F_1 ( unsigned V_1 ,
struct V_2 * V_3 )
{
struct V_4 V_5 = {
. V_6 = L_1 ,
. V_7 = V_1 ,
. V_8 = & V_9 [ V_1 * 2 ] ,
. V_10 = 2 ,
. V_11 = F_2 ( 32 ) ,
. V_12 = V_3 ,
. V_13 = sizeof( * V_3 ) ,
} ;
F_3 ( V_1 > 1 ) ;
F_4 ( & V_5 ) ;
}
static void T_1 F_5 ( void )
{
F_6 ( NULL , L_2 , 1 ,
& V_14 , sizeof( V_14 ) ) ;
F_1 ( 1 , & V_15 ) ;
}
static int F_7 ( struct V_16 * V_17 ,
void T_2 * V_18 , int V_19 )
{
struct V_20 * V_21 = F_8 ( V_17 ) ;
if ( ! V_21 -> V_22 )
return - V_23 ;
if ( V_19 ) {
int V_24 = F_9 ( V_21 -> V_22 ) ;
if ( ! V_24 )
V_24 = F_10 ( V_21 -> V_22 , 0 ) ;
return V_24 ;
}
F_10 ( V_21 -> V_22 , 1 ) ;
F_11 ( V_21 -> V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = F_8 ( V_17 ) ;
struct V_25 * V_22 ;
int V_26 ;
F_13 ( F_14 ( 5 , 18 ) , V_27 , NULL ) ;
if ( ! F_15 ( F_14 ( 5 , 18 ) ) ) {
F_16 ( L_3 ) ;
V_26 = - V_28 ;
goto error;
}
V_22 = F_17 ( & V_17 -> V_29 , 0 ) ;
if ( F_18 ( V_22 ) ) {
V_26 = F_19 ( V_22 ) ;
goto error;
}
V_21 -> V_22 = V_22 ;
return 0 ;
error:
F_20 ( F_14 ( 5 , 18 ) ) ;
return V_26 ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = F_8 ( V_17 ) ;
if ( ! V_21 -> V_22 )
return 0 ;
F_22 ( V_21 -> V_22 ) ;
V_21 -> V_22 = NULL ;
F_20 ( F_14 ( 5 , 18 ) ) ;
return 0 ;
}
static int F_23 ( struct V_16 * V_17 )
{
return V_30 ;
}
static void T_1 F_24 ( void )
{
F_25 ( L_4 , 0 , L_5 ) ;
F_26 ( NULL ,
L_4 , - 1 ,
V_31 ,
F_27 ( V_31 ) ,
& V_32 . V_33 ,
sizeof( V_32 . V_33 ) ) ;
}
static void T_1 F_28 ( void )
{
struct V_4 V_34 = {
. V_6 = L_6 ,
. V_7 = - 1 ,
. V_12 = & V_35 ,
. V_13 = sizeof( struct V_36 ) ,
. V_11 = F_2 ( 32 ) ,
} ;
F_29 ( 2 , V_37 ,
F_27 ( V_37 ) ) ;
F_26 (
NULL , L_7 , - 1 ,
V_38 , F_27 ( V_38 ) ,
& V_39 , sizeof( V_39 ) ) ;
F_4 ( & V_34 ) ;
}
static void T_1 F_30 ( void )
{
F_4 ( & V_40 ) ;
}
static void T_1 F_31 ( void )
{
F_4 ( & V_41 ) ;
}
static void T_1 F_32 ( void )
{
int V_42 = 0 ;
int V_43 = 0 ;
F_33 () ;
F_34 ( V_44 ,
F_27 ( V_44 ) ) ;
F_35 () ;
F_36 () ;
F_6 ( NULL , L_8 , - 1 ,
& V_45 ,
sizeof( V_45 ) ) ;
F_6 ( NULL , L_9 , - 1 ,
& V_46 ,
sizeof( V_46 ) ) ;
F_37 ( V_42 ++ ,
L_10 , V_47 ,
F_27 ( V_47 ) , 3300000 ) ;
F_26 ( NULL , L_11 , 1 ,
V_48 , F_27 ( V_48 ) ,
& V_49 , sizeof( V_49 ) ) ;
F_4 ( & V_50 ) ;
F_26 ( NULL , L_12 , 0 ,
V_51 ,
F_27 ( V_51 ) ,
& V_52 , sizeof( V_52 ) ) ;
F_38 ( V_53 , F_27 ( V_53 ) ) ;
F_6 ( NULL , L_13 , V_42 ++ ,
& V_54 , sizeof( struct V_55 ) ) ;
F_6 ( NULL , L_13 , V_42 ++ ,
& V_56 , sizeof( struct V_55 ) ) ;
F_6 ( NULL , L_14 , V_43 ++ ,
& V_57 , sizeof( struct V_58 ) ) ;
F_6 ( NULL , L_14 , V_43 ++ ,
& V_59 , sizeof( struct V_58 ) ) ;
F_5 () ;
F_4 ( & V_60 ) ;
F_26 ( NULL , L_5 ,
- 1 , V_61 ,
F_27 ( V_61 ) ,
& V_62 ,
sizeof( V_62 ) ) ;
F_24 () ;
F_30 () ;
F_31 () ;
F_28 () ;
F_26 ( NULL , L_15 , 0 ,
V_63 , F_27 ( V_63 ) ,
& V_64 , sizeof( struct V_65 ) ) ;
F_26 ( NULL , L_15 , 2 ,
V_66 , F_27 ( V_66 ) ,
& V_67 , sizeof( struct V_65 ) ) ;
}
static int F_39 ( struct V_68 * V_69 )
{
T_3 V_70 = F_40 ( V_69 , 0x1e ) ;
V_70 &= ~ 0xc000 ;
V_70 |= 0x4000 ;
return F_41 ( V_69 , 0x1e , V_70 ) ;
}
static void T_1 F_42 ( void )
{
F_32 () ;
F_43 ( F_44 ( 0 ) , V_71 ) ;
if ( F_45 ( V_72 ) )
F_46 ( L_16 ,
F_39 ) ;
}
static void T_1 F_47 ( void )
{
void T_2 * V_73 = F_48 ( 0xf1001000 , 0x1000 ) ;
void T_2 * V_74 = F_48 ( 0xf1002000 , 0x1000 ) ;
F_49 ( 0 , 29 , V_73 , V_74 ) ;
}
