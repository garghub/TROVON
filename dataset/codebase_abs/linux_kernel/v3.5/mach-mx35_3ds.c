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
F_17 ( 0 , & V_26 , 1 ) ;
}
static int F_18 ( struct V_15 * V_16 )
{
return F_19 ( V_16 -> V_27 , V_28 ) ;
}
static int F_20 ( struct V_15 * V_16 )
{
return F_19 ( V_16 -> V_27 , V_29 |
V_28 ) ;
}
static int T_1 F_21 ( char * V_30 )
{
if ( ! strcmp ( V_30 , L_7 ) )
V_31 = 1 ;
else if ( ! strcmp ( V_30 , L_8 ) )
V_31 = 0 ;
else
F_22 ( L_9
L_10 ) ;
return 0 ;
}
static void T_1 F_23 ( void )
{
struct V_15 * V_32 ;
F_24 () ;
F_25 ( V_33 , F_26 ( V_33 ) ) ;
F_27 ( NULL ) ;
F_28 ( NULL ) ;
F_29 ( V_34 , F_26 ( V_34 ) ) ;
F_30 ( & V_35 ) ;
if ( V_31 )
F_31 ( & V_36 ) ;
F_32 ( & V_37 ) ;
if ( ! V_31 )
F_33 ( & V_38 ) ;
F_34 ( & V_39 ) ;
F_35 ( 0 , NULL ) ;
if ( F_36 ( V_40 , V_41 ) )
F_37 ( L_11
L_12 ) ;
F_38 ( & V_42 ) ;
F_17 (
0 , V_43 , F_26 ( V_43 ) ) ;
F_39 ( & V_44 ) ;
F_40 ( & V_45 ) ;
F_8 () ;
V_32 = F_41 ( & V_46 ) ;
V_47 . V_20 . V_48 = & V_32 -> V_20 ;
F_40 ( & V_47 ) ;
F_15 () ;
}
static void T_1 F_42 ( void )
{
F_43 () ;
}
static void T_1 F_44 ( void )
{
V_18 = F_45 ( V_21 ,
V_21 ) ;
}
