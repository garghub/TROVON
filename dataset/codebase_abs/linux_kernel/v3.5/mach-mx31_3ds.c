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
V_2 = F_16 ( F_17 ( V_22 ) ,
V_19 , V_23 |
V_24 | V_25 ,
L_5 , V_20 ) ;
if ( V_2 ) {
F_15 ( L_6 ) ;
goto V_26;
}
return 0 ;
V_26:
F_18 ( V_21 ,
F_14 ( V_21 ) ) ;
return V_2 ;
}
static void F_19 ( struct V_13 * V_9 , void * V_20 )
{
F_20 ( F_17 ( V_22 ) , V_20 ) ;
F_18 ( V_21 ,
F_14 ( V_21 ) ) ;
}
static void F_21 ( struct V_13 * V_9 , unsigned int V_27 )
{
if ( V_27 > 7 )
F_10 ( V_28 , 1 ) ;
else
F_10 ( V_28 , 0 ) ;
}
static int F_22 ( void )
{
int V_8 ;
F_23 ( V_29 , V_30 ) ;
F_23 ( V_31 , V_30 ) ;
F_23 ( V_32 , V_30 ) ;
F_23 ( V_33 , V_30 ) ;
F_23 ( V_34 , V_30 ) ;
F_23 ( V_35 , V_30 ) ;
F_23 ( V_36 , V_30 ) ;
F_23 ( V_37 , V_30 ) ;
F_23 ( V_38 , V_30 ) ;
F_23 ( V_39 , V_30 ) ;
F_23 ( V_40 , V_30 ) ;
F_23 ( V_41 , V_30 ) ;
V_8 = F_24 ( V_42 , L_7 ) ;
if ( V_8 ) {
F_25 ( L_8 ) ;
return V_8 ;
}
V_8 = F_26 ( V_42 , 0 ) ;
if ( V_8 ) {
F_25 ( L_9 ) ;
goto V_43;
}
F_27 ( 1 ) ;
F_10 ( V_42 , 1 ) ;
return 0 ;
V_43:
V_26 ( V_42 ) ;
return V_8 ;
}
static int F_28 ( struct V_4 * V_5 )
{
return F_29 ( V_5 -> V_44 , V_45 ) ;
}
static int F_30 ( struct V_4 * V_5 )
{
int V_8 ;
F_23 ( V_46 , V_30 ) ;
F_23 ( V_47 , V_30 ) ;
F_23 ( V_48 , V_30 ) ;
F_23 ( V_49 , V_30 ) ;
F_23 ( V_50 , V_30 ) ;
F_23 ( V_51 , V_30 ) ;
F_23 ( V_52 , V_30 ) ;
F_23 ( V_53 , V_30 ) ;
F_23 ( V_54 , V_30 ) ;
F_23 ( V_55 , V_30 ) ;
F_23 ( V_56 , V_30 ) ;
F_23 ( V_57 , V_30 ) ;
V_8 = F_24 ( V_58 , L_10 ) ;
if ( V_8 ) {
F_25 ( L_11 ) ;
return V_8 ;
}
V_8 = F_26 ( V_58 , 0 ) ;
if ( V_8 ) {
F_25 ( L_12 ) ;
goto V_43;
}
F_27 ( 1 ) ;
F_10 ( V_58 , 1 ) ;
F_27 ( 10 ) ;
return F_29 ( V_5 -> V_44 , V_45 ) ;
V_43:
V_26 ( V_58 ) ;
return V_8 ;
}
static int T_1 F_31 ( char * V_59 )
{
if ( ! strcmp ( V_59 , L_13 ) )
V_60 = 1 ;
else if ( ! strcmp ( V_59 , L_14 ) )
V_60 = 0 ;
else
F_32 ( L_15
L_16 ) ;
return 0 ;
}
static void T_1 F_33 ( void )
{
int V_2 ;
F_34 () ;
F_35 ( V_61 , true ) ;
F_36 ( V_62 , F_14 ( V_62 ) ,
L_17 ) ;
F_37 ( & V_63 ) ;
F_38 ( & V_64 ) ;
F_39 ( & V_65 ) ;
F_40 ( V_66 ,
F_14 ( V_66 ) ) ;
F_41 ( V_67 , F_14 ( V_67 ) ) ;
F_42 ( & V_68 ) ;
F_22 () ;
if ( V_60 ) {
V_69 . V_70 = F_43 ( V_71 |
V_72 ) ;
if ( V_69 . V_70 )
F_44 ( & V_69 ) ;
}
V_73 . V_70 = F_43 ( V_71 |
V_72 ) ;
if ( V_73 . V_70 )
F_45 ( 2 , & V_73 ) ;
if ( ! V_60 )
F_46 ( & V_74 ) ;
if ( F_47 ( V_75 , V_76 ) )
F_48 ( V_77 L_18
L_19 ) ;
F_49 ( NULL ) ;
F_50 ( & V_78 ) ;
F_51 ( 0 , & V_79 ) ;
F_52 ( & V_80 ) ;
F_53 ( & V_81 ) ;
F_54 ( & V_82 ) ;
V_2 = F_13 ( V_83 ,
F_14 ( V_83 ) ) ;
if ( V_2 ) {
F_25 ( L_20 ) ;
V_84 . V_85 = NULL ;
}
F_1 () ;
F_55 ( 0 , & V_86 ) ;
F_56 ( L_21 , 0 , NULL , 0 , NULL , 0 ) ;
}
static void T_1 F_57 ( void )
{
F_58 ( 26000000 ) ;
}
static void T_1 F_59 ( void )
{
V_7 = F_60 ( V_10 ,
V_10 ) ;
}
