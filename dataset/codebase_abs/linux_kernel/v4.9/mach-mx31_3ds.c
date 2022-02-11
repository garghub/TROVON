static int T_1 F_1 ( void )
{
int V_1 , V_2 = - V_3 ;
struct V_4 * V_5 =
F_2 ( & V_6 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
if ( ! V_7 )
goto V_8;
V_1 = F_5 ( & V_5 -> V_9 ,
V_7 , V_7 ,
V_10 ,
V_11 | V_12 ) ;
if ( ! ( V_1 & V_11 ) )
goto V_8;
V_2 = F_6 ( V_5 ) ;
if ( V_2 )
V_8:
F_7 ( V_5 ) ;
return V_2 ;
}
static int F_8 ( struct V_13 * V_9 , int V_14 )
{
F_9 ( L_1 , V_15 , V_14 ? L_2 : L_3 ) ;
F_10 ( V_16 , V_14 ? 0 : 1 ) ;
if ( ! V_14 )
goto V_17;
F_10 ( V_18 , 0 ) ;
F_11 ( 20 ) ;
F_10 ( V_18 , 1 ) ;
F_11 ( 100 ) ;
V_17:
return 0 ;
}
static int F_12 ( struct V_13 * V_9 ,
T_2 V_19 ,
void * V_20 )
{
int V_2 ;
V_2 = F_13 ( V_21 ,
F_14 ( V_21 ) ) ;
if ( V_2 ) {
F_15 ( L_4 ) ;
return V_2 ;
}
V_2 = F_16 ( F_17 ( F_18 ( V_22 ) ) ,
V_19 ,
V_23 | V_24 ,
L_5 , V_20 ) ;
if ( V_2 ) {
F_15 ( L_6 ) ;
goto V_25;
}
return 0 ;
V_25:
F_19 ( V_21 ,
F_14 ( V_21 ) ) ;
return V_2 ;
}
static void F_20 ( struct V_13 * V_9 , void * V_20 )
{
F_21 ( F_17 ( F_18 ( V_22 ) ) , V_20 ) ;
F_19 ( V_21 ,
F_14 ( V_21 ) ) ;
}
static void F_22 ( struct V_13 * V_9 , unsigned int V_26 )
{
if ( V_26 > 7 )
F_10 ( V_27 , 1 ) ;
else
F_10 ( V_27 , 0 ) ;
}
static int F_23 ( void )
{
int V_8 ;
F_24 ( V_28 , V_29 ) ;
F_24 ( V_30 , V_29 ) ;
F_24 ( V_31 , V_29 ) ;
F_24 ( V_32 , V_29 ) ;
F_24 ( V_33 , V_29 ) ;
F_24 ( V_34 , V_29 ) ;
F_24 ( V_35 , V_29 ) ;
F_24 ( V_36 , V_29 ) ;
F_24 ( V_37 , V_29 ) ;
F_24 ( V_38 , V_29 ) ;
F_24 ( V_39 , V_29 ) ;
F_24 ( V_40 , V_29 ) ;
V_8 = F_25 ( V_41 , L_7 ) ;
if ( V_8 ) {
F_26 ( L_8 ) ;
return V_8 ;
}
V_8 = F_27 ( V_41 , 0 ) ;
if ( V_8 ) {
F_26 ( L_9 ) ;
goto V_42;
}
F_28 ( 1 ) ;
F_10 ( V_41 , 1 ) ;
return 0 ;
V_42:
V_25 ( V_41 ) ;
return V_8 ;
}
static int F_29 ( struct V_4 * V_5 )
{
return F_30 ( V_5 -> V_43 , V_44 ) ;
}
static int F_31 ( struct V_4 * V_5 )
{
int V_8 ;
F_24 ( V_45 , V_29 ) ;
F_24 ( V_46 , V_29 ) ;
F_24 ( V_47 , V_29 ) ;
F_24 ( V_48 , V_29 ) ;
F_24 ( V_49 , V_29 ) ;
F_24 ( V_50 , V_29 ) ;
F_24 ( V_51 , V_29 ) ;
F_24 ( V_52 , V_29 ) ;
F_24 ( V_53 , V_29 ) ;
F_24 ( V_54 , V_29 ) ;
F_24 ( V_55 , V_29 ) ;
F_24 ( V_56 , V_29 ) ;
V_8 = F_25 ( V_57 , L_10 ) ;
if ( V_8 ) {
F_26 ( L_11 ) ;
return V_8 ;
}
V_8 = F_27 ( V_57 , 0 ) ;
if ( V_8 ) {
F_26 ( L_12 ) ;
goto V_42;
}
F_28 ( 1 ) ;
F_10 ( V_57 , 1 ) ;
F_28 ( 10 ) ;
return F_30 ( V_5 -> V_43 , V_44 ) ;
V_42:
V_25 ( V_57 ) ;
return V_8 ;
}
static int T_1 F_32 ( char * V_58 )
{
if ( ! strcmp ( V_58 , L_13 ) )
V_59 = true ;
else if ( ! strcmp ( V_58 , L_14 ) )
V_59 = false ;
else
F_33 ( L_15
L_16 ) ;
return 1 ;
}
static void T_1 F_34 ( void )
{
F_35 () ;
F_36 ( V_60 , true ) ;
F_37 ( V_61 , F_14 ( V_61 ) ,
L_17 ) ;
F_38 ( & V_62 ) ;
F_39 ( & V_63 ) ;
F_40 ( & V_64 ) ;
F_41 ( & V_65 ) ;
F_42 () ;
F_43 ( & V_66 ) ;
F_44 ( & V_67 ) ;
F_45 () ;
F_46 ( & V_68 ) ;
F_47 ( 0 , & V_69 ) ;
F_48 ( L_18 , 0 , NULL , 0 , NULL , 0 ) ;
}
static void T_1 F_49 ( void )
{
int V_2 ;
V_70 [ 0 ] . V_71 = F_17 ( F_18 ( V_72 ) ) ;
F_50 ( V_70 ,
F_14 ( V_70 ) ) ;
F_51 ( V_73 , F_14 ( V_73 ) ) ;
F_23 () ;
if ( V_59 ) {
V_74 . V_75 = F_52 ( V_76 |
V_77 ) ;
if ( V_74 . V_75 )
F_53 ( & V_74 ) ;
}
V_78 . V_75 = F_52 ( V_76 |
V_77 ) ;
if ( V_78 . V_75 )
F_54 ( 2 , & V_78 ) ;
if ( ! V_59 )
F_55 ( & V_79 ) ;
if ( F_56 ( V_80 , F_18 ( V_81 ) ) )
F_57 ( V_82 L_19
L_20 ) ;
F_58 ( 0 , & V_83 ) ;
V_2 = F_13 ( V_84 ,
F_14 ( V_84 ) ) ;
if ( V_2 ) {
F_26 ( L_21 ) ;
V_85 . V_86 = NULL ;
}
F_1 () ;
}
static void T_1 F_59 ( void )
{
F_60 ( 26000000 ) ;
}
static void T_1 F_61 ( void )
{
V_7 = F_62 ( V_10 ,
V_10 ) ;
}
