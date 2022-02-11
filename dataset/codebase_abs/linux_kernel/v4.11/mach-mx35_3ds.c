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
static void T_1 F_8 ( void )
{
int V_12 = F_9 ( V_13 , V_14 , L_5 ) ;
if ( V_12 ) {
F_6 ( L_6 , V_12 ) ;
return;
}
V_15 . V_16 = F_10 ( V_13 ) ;
F_11 ( 0 , & V_15 , 1 ) ;
}
static int F_12 ( struct V_17 * V_18 )
{
return F_13 ( V_18 -> V_19 , V_20 ) ;
}
static int F_14 ( struct V_17 * V_18 )
{
return F_13 ( V_18 -> V_19 , V_21 |
V_20 ) ;
}
static int T_1 F_15 ( char * V_22 )
{
if ( ! strcmp ( V_22 , L_7 ) )
V_23 = true ;
else if ( ! strcmp ( V_22 , L_8 ) )
V_23 = false ;
else
F_16 ( L_9
L_10 ) ;
return 1 ;
}
static void T_1 F_17 ( void )
{
F_18 () ;
F_19 ( V_24 , F_20 ( V_24 ) ) ;
F_21 ( NULL ) ;
F_22 () ;
F_23 () ;
F_24 ( V_25 , F_20 ( V_25 ) ) ;
F_25 ( & V_26 ) ;
if ( V_23 )
F_26 ( & V_27 ) ;
F_27 ( & V_28 ) ;
if ( ! V_23 )
F_28 ( & V_29 ) ;
F_29 ( & V_30 ) ;
F_30 ( 0 , NULL ) ;
F_31 ( & V_31 ) ;
F_11 (
0 , V_32 , F_20 ( V_32 ) ) ;
F_32 () ;
}
static void T_1 F_33 ( void )
{
struct V_17 * V_33 ;
if ( F_34 ( V_34 , F_35 ( 1 , 1 ) ) )
F_36 ( L_11
L_12 ) ;
V_33 = F_37 ( & V_35 ) ;
V_36 . V_37 . V_38 = & V_33 -> V_37 ;
F_38 ( & V_36 ) ;
F_8 () ;
}
static void T_1 F_39 ( void )
{
F_40 () ;
}
