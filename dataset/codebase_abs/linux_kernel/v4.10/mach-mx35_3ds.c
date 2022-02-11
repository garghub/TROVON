static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
return ! strcmp ( V_2 -> V_4 , V_3 ) ;
}
static void F_2 (
struct V_5 * V_6 , unsigned int V_7 )
{
struct V_1 * V_2 ;
if ( ! F_3 ( V_8 ) ) {
V_2 = F_4 (
L_1 , F_1 ) ;
if ( V_2 ) {
V_8 =
V_2 -> V_9 + V_10 ;
if ( F_5 ( V_8 , L_2 ) < 0 ) {
F_6 ( L_3 ) ;
V_8 = - V_11 ;
}
} else {
F_6 ( L_4 ) ;
}
}
if ( F_3 ( V_8 ) )
F_7 ( V_8 , V_7 ) ;
}
static int T_1 F_8 ( void )
{
int V_12 , V_13 = - V_14 ;
struct V_15 * V_16 =
F_9 ( & V_17 ) ;
if ( F_10 ( V_16 ) )
return F_11 ( V_16 ) ;
if ( ! V_18 )
goto V_19;
V_12 = F_12 ( & V_16 -> V_20 ,
V_18 , V_18 ,
V_21 ,
V_22 | V_23 ) ;
if ( ! ( V_12 & V_22 ) )
goto V_19;
V_13 = F_13 ( V_16 ) ;
if ( V_13 )
V_19:
F_14 ( V_16 ) ;
return V_13 ;
}
static void T_1 F_15 ( void )
{
int V_13 = F_16 ( V_24 , V_25 , L_5 ) ;
if ( V_13 ) {
F_6 ( L_6 , V_13 ) ;
return;
}
V_26 . V_27 = F_17 ( V_24 ) ;
F_18 ( 0 , & V_26 , 1 ) ;
}
static int F_19 ( struct V_15 * V_16 )
{
return F_20 ( V_16 -> V_28 , V_29 ) ;
}
static int F_21 ( struct V_15 * V_16 )
{
return F_20 ( V_16 -> V_28 , V_30 |
V_29 ) ;
}
static int T_1 F_22 ( char * V_31 )
{
if ( ! strcmp ( V_31 , L_7 ) )
V_32 = true ;
else if ( ! strcmp ( V_31 , L_8 ) )
V_32 = false ;
else
F_23 ( L_9
L_10 ) ;
return 1 ;
}
static void T_1 F_24 ( void )
{
F_25 () ;
F_26 ( V_33 , F_27 ( V_33 ) ) ;
F_28 ( NULL ) ;
F_29 () ;
F_30 () ;
F_31 ( V_34 , F_27 ( V_34 ) ) ;
F_32 ( & V_35 ) ;
if ( V_32 )
F_33 ( & V_36 ) ;
F_34 ( & V_37 ) ;
if ( ! V_32 )
F_35 ( & V_38 ) ;
F_36 ( & V_39 ) ;
F_37 ( 0 , NULL ) ;
F_38 ( & V_40 ) ;
F_18 (
0 , V_41 , F_27 ( V_41 ) ) ;
F_39 () ;
F_40 ( & V_42 ) ;
F_8 () ;
}
static void T_1 F_41 ( void )
{
struct V_15 * V_43 ;
if ( F_42 ( V_44 , F_43 ( 1 , 1 ) ) )
F_44 ( L_11
L_12 ) ;
V_43 = F_45 ( & V_45 ) ;
V_46 . V_20 . V_47 = & V_43 -> V_20 ;
F_40 ( & V_46 ) ;
F_15 () ;
}
static void T_1 F_46 ( void )
{
F_47 () ;
}
static void T_1 F_48 ( void )
{
V_18 = F_49 ( V_21 ,
V_21 ) ;
}
