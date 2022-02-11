static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
void * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_6 ,
F_3 ( V_6 ) ) ;
if ( V_5 ) {
F_4 ( L_1 ) ;
return V_5 ;
}
V_5 = F_5 ( F_6 ( F_7 ( V_7 ) ) ,
V_3 ,
V_8 | V_9 ,
L_2 , V_4 ) ;
if ( V_5 ) {
F_4 ( L_3 ) ;
goto V_10;
}
return 0 ;
V_10:
F_8 ( V_6 ,
F_3 ( V_6 ) ) ;
return V_5 ;
}
static void F_9 ( struct V_1 * V_2 , void * V_4 )
{
F_10 ( F_6 ( F_7 ( V_7 ) ) , V_4 ) ;
F_8 ( V_6 ,
F_3 ( V_6 ) ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_11 )
{
if ( V_11 > 7 )
F_12 ( V_12 , 1 ) ;
else
F_12 ( V_12 , 0 ) ;
}
static int F_13 ( void )
{
int V_13 ;
F_14 ( V_14 , V_15 ) ;
F_14 ( V_16 , V_15 ) ;
F_14 ( V_17 , V_15 ) ;
F_14 ( V_18 , V_15 ) ;
F_14 ( V_19 , V_15 ) ;
F_14 ( V_20 , V_15 ) ;
F_14 ( V_21 , V_15 ) ;
F_14 ( V_22 , V_15 ) ;
F_14 ( V_23 , V_15 ) ;
F_14 ( V_24 , V_15 ) ;
F_14 ( V_25 , V_15 ) ;
F_14 ( V_26 , V_15 ) ;
V_13 = F_15 ( V_27 , L_4 ) ;
if ( V_13 ) {
F_16 ( L_5 ) ;
return V_13 ;
}
V_13 = F_17 ( V_27 , 0 ) ;
if ( V_13 ) {
F_16 ( L_6 ) ;
goto V_28;
}
F_18 ( 1 ) ;
F_12 ( V_27 , 1 ) ;
return 0 ;
V_28:
V_10 ( V_27 ) ;
return V_13 ;
}
static int F_19 ( struct V_29 * V_30 )
{
return F_20 ( V_30 -> V_31 , V_32 ) ;
}
static int F_21 ( struct V_29 * V_30 )
{
int V_13 ;
F_14 ( V_33 , V_15 ) ;
F_14 ( V_34 , V_15 ) ;
F_14 ( V_35 , V_15 ) ;
F_14 ( V_36 , V_15 ) ;
F_14 ( V_37 , V_15 ) ;
F_14 ( V_38 , V_15 ) ;
F_14 ( V_39 , V_15 ) ;
F_14 ( V_40 , V_15 ) ;
F_14 ( V_41 , V_15 ) ;
F_14 ( V_42 , V_15 ) ;
F_14 ( V_43 , V_15 ) ;
F_14 ( V_44 , V_15 ) ;
V_13 = F_15 ( V_45 , L_7 ) ;
if ( V_13 ) {
F_16 ( L_8 ) ;
return V_13 ;
}
V_13 = F_17 ( V_45 , 0 ) ;
if ( V_13 ) {
F_16 ( L_9 ) ;
goto V_28;
}
F_18 ( 1 ) ;
F_12 ( V_45 , 1 ) ;
F_18 ( 10 ) ;
return F_20 ( V_30 -> V_31 , V_32 ) ;
V_28:
V_10 ( V_45 ) ;
return V_13 ;
}
static int T_2 F_22 ( char * V_46 )
{
if ( ! strcmp ( V_46 , L_10 ) )
V_47 = true ;
else if ( ! strcmp ( V_46 , L_11 ) )
V_47 = false ;
else
F_23 ( L_12
L_13 ) ;
return 1 ;
}
static void T_2 F_24 ( void )
{
F_25 () ;
F_26 ( V_48 , true ) ;
F_27 ( V_49 , F_3 ( V_49 ) ,
L_14 ) ;
F_28 ( & V_50 ) ;
F_29 ( & V_51 ) ;
F_30 ( & V_52 ) ;
F_31 ( & V_53 ) ;
F_32 () ;
F_33 ( & V_54 ) ;
F_34 ( & V_55 ) ;
F_35 () ;
F_36 ( & V_56 ) ;
F_37 ( 0 , & V_57 ) ;
F_38 ( L_15 , 0 , NULL , 0 , NULL , 0 ) ;
}
static void T_2 F_39 ( void )
{
V_58 [ 0 ] . V_59 = F_6 ( F_7 ( V_60 ) ) ;
F_40 ( V_58 ,
F_3 ( V_58 ) ) ;
F_13 () ;
if ( V_47 ) {
V_61 . V_62 = F_41 ( V_63 |
V_64 ) ;
if ( V_61 . V_62 )
F_42 ( & V_61 ) ;
}
V_65 . V_62 = F_41 ( V_63 |
V_64 ) ;
if ( V_65 . V_62 )
F_43 ( 2 , & V_65 ) ;
if ( ! V_47 )
F_44 ( & V_66 ) ;
if ( F_45 ( V_67 , F_7 ( V_68 ) ) )
F_46 ( V_69 L_16
L_17 ) ;
F_47 ( 0 , & V_70 ) ;
}
static void T_2 F_48 ( void )
{
F_49 ( 26000000 ) ;
}
