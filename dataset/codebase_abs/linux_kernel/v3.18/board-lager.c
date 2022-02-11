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
. V_3 = L_2 ,
. V_4 = V_12 ,
. V_5 = & V_16 [ V_12 * 2 ] ,
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
F_8 ( NULL , L_3 , 1 ,
& V_17 , sizeof( V_17 ) ) ;
F_5 ( 1 , & V_18 ) ;
}
static int F_9 ( struct V_19 * V_20 ,
void T_2 * V_21 , int V_22 )
{
struct V_23 * V_24 = F_10 ( V_20 ) ;
if ( ! V_24 -> V_25 )
return - V_26 ;
if ( V_22 ) {
int V_27 = F_11 ( V_24 -> V_25 ) ;
if ( ! V_27 )
V_27 = F_12 ( V_24 -> V_25 , 0 ) ;
return V_27 ;
}
F_12 ( V_24 -> V_25 , 1 ) ;
F_13 ( V_24 -> V_25 ) ;
return 0 ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = F_10 ( V_20 ) ;
struct V_28 * V_25 ;
int V_29 ;
F_15 ( F_16 ( 5 , 18 ) , V_30 , NULL ) ;
if ( ! F_17 ( F_16 ( 5 , 18 ) ) ) {
F_18 ( L_4 ) ;
V_29 = - V_31 ;
goto error;
}
V_25 = F_19 ( & V_20 -> V_32 , 0 ) ;
if ( F_20 ( V_25 ) ) {
V_29 = F_21 ( V_25 ) ;
goto error;
}
V_24 -> V_25 = V_25 ;
return 0 ;
error:
F_22 ( F_16 ( 5 , 18 ) ) ;
return V_29 ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = F_10 ( V_20 ) ;
if ( ! V_24 -> V_25 )
return 0 ;
F_24 ( V_24 -> V_25 ) ;
V_24 -> V_25 = NULL ;
F_22 ( F_16 ( 5 , 18 ) ) ;
return 0 ;
}
static int F_25 ( struct V_19 * V_20 )
{
return V_33 ;
}
static void T_1 F_26 ( void )
{
F_27 ( L_5 , 0 , L_6 ) ;
F_28 ( NULL ,
L_5 , - 1 ,
V_34 ,
F_2 ( V_34 ) ,
& V_35 . V_2 ,
sizeof( V_35 . V_2 ) ) ;
}
static void T_1 F_29 ( void )
{
struct V_1 V_36 = {
. V_3 = L_7 ,
. V_4 = - 1 ,
. V_8 = & V_37 ,
. V_10 = sizeof( struct V_38 ) ,
. V_11 = F_3 ( 32 ) ,
} ;
F_30 ( 2 , V_39 ,
F_2 ( V_39 ) ) ;
F_28 (
NULL , L_8 , - 1 ,
V_40 , F_2 ( V_40 ) ,
& V_41 , sizeof( V_41 ) ) ;
F_4 ( & V_36 ) ;
}
static void T_1 F_31 ( void )
{
F_4 ( & V_42 ) ;
}
static void T_1 F_32 ( void )
{
F_4 ( & V_43 ) ;
}
static void T_1 F_33 ( void )
{
int V_44 = 0 ;
int V_45 = 0 ;
F_34 () ;
F_35 ( V_46 ,
F_2 ( V_46 ) ) ;
F_36 () ;
F_37 () ;
F_8 ( NULL , L_9 , - 1 ,
& V_47 ,
sizeof( V_47 ) ) ;
F_8 ( NULL , L_10 , - 1 ,
& V_48 ,
sizeof( V_48 ) ) ;
F_38 ( V_44 ++ ,
L_11 , V_49 ,
F_2 ( V_49 ) , 3300000 ) ;
F_28 ( NULL , L_12 , 1 ,
V_50 , F_2 ( V_50 ) ,
& V_51 , sizeof( V_51 ) ) ;
F_4 ( & V_52 ) ;
F_1 () ;
F_28 ( NULL , L_13 , 0 ,
V_53 ,
F_2 ( V_53 ) ,
& V_54 , sizeof( V_54 ) ) ;
F_39 ( V_55 , F_2 ( V_55 ) ) ;
F_8 ( NULL , L_14 , V_44 ++ ,
& V_56 , sizeof( struct V_57 ) ) ;
F_8 ( NULL , L_14 , V_44 ++ ,
& V_58 , sizeof( struct V_57 ) ) ;
F_8 ( NULL , L_15 , V_45 ++ ,
& V_59 , sizeof( struct V_60 ) ) ;
F_8 ( NULL , L_15 , V_45 ++ ,
& V_61 , sizeof( struct V_60 ) ) ;
F_7 () ;
F_4 ( & V_62 ) ;
F_28 ( NULL , L_6 ,
- 1 , V_63 ,
F_2 ( V_63 ) ,
& V_64 ,
sizeof( V_64 ) ) ;
F_26 () ;
F_31 () ;
F_32 () ;
F_29 () ;
F_28 ( NULL , L_16 , 0 ,
V_65 , F_2 ( V_65 ) ,
& V_66 , sizeof( struct V_67 ) ) ;
F_28 ( NULL , L_16 , 2 ,
V_68 , F_2 ( V_68 ) ,
& V_69 , sizeof( struct V_67 ) ) ;
}
static int F_40 ( struct V_70 * V_71 )
{
T_3 V_72 = F_41 ( V_71 , 0x1e ) ;
V_72 &= ~ 0xc000 ;
V_72 |= 0x4000 ;
return F_42 ( V_71 , 0x1e , V_72 ) ;
}
static void T_1 F_43 ( void )
{
F_33 () ;
F_44 ( F_45 ( 0 ) , V_73 ) ;
if ( F_46 ( V_74 ) )
F_47 ( L_17 ,
F_40 ) ;
}
