static int F_1 ( struct V_1 * V_2 ,
const void * V_3 )
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
static int F_15 ( struct V_15 * V_16 )
{
return F_16 ( V_16 -> V_24 , V_25 ) ;
}
static int F_17 ( struct V_15 * V_16 )
{
return F_16 ( V_16 -> V_24 , V_26 |
V_25 ) ;
}
static int T_1 F_18 ( char * V_27 )
{
if ( ! strcmp ( V_27 , L_5 ) )
V_28 = 1 ;
else if ( ! strcmp ( V_27 , L_6 ) )
V_28 = 0 ;
else
F_19 ( L_7
L_8 ) ;
return 0 ;
}
static void T_1 F_20 ( void )
{
struct V_15 * V_29 ;
F_21 () ;
F_22 ( V_30 , F_23 ( V_30 ) ) ;
F_24 ( NULL ) ;
F_25 ( NULL ) ;
F_26 ( V_31 , F_23 ( V_31 ) ) ;
F_27 ( & V_32 ) ;
if ( V_28 )
F_28 ( & V_33 ) ;
F_29 ( & V_34 ) ;
if ( ! V_28 )
F_30 ( & V_35 ) ;
F_31 ( & V_36 ) ;
F_32 ( 0 , NULL ) ;
if ( F_33 ( V_37 , V_38 ) )
F_34 ( L_9
L_10 ) ;
F_35 ( & V_39 ) ;
F_36 (
0 , V_40 , F_23 ( V_40 ) ) ;
F_37 ( & V_41 ) ;
F_38 ( & V_42 ) ;
F_8 () ;
V_29 = F_39 ( & V_43 ) ;
V_44 . V_20 . V_45 = & V_29 -> V_20 ;
F_38 ( & V_44 ) ;
}
static void T_1 F_40 ( void )
{
F_41 () ;
}
static void T_1 F_42 ( void )
{
V_18 = F_43 ( V_21 ,
V_21 ) ;
}
