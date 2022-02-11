static T_1 void F_1 ( void )
{
void T_2 * V_1 = F_2 ( V_2 ) ;
int V_3 ;
T_3 V_4 ;
struct V_5 * V_6 = & V_5 ;
V_4 = F_3 ( V_1 ) ;
V_4 &= ~ F_4 ( 8 ) ;
V_3 = F_5 ( V_7 ) ;
if ( V_3 ) {
F_6 ( L_1 , V_8 , V_3 ) ;
return;
}
F_7 ( V_4 , V_1 ) ;
F_8 ( L_2 ) ;
V_6 -> V_9 -> V_10 = V_11 ;
V_3 = F_9 () ;
if ( V_3 )
F_6 ( L_3 , V_8 , V_3 ) ;
}
static T_1 void F_10 ( void )
{
int V_3 ;
V_3 = F_5 ( V_12 ) ;
if ( V_3 ) {
F_6 ( L_4 , V_8 , V_3 ) ;
return;
}
F_11 ( & V_13 ) ;
V_3 = F_12 ( & V_14 ) ;
if ( V_3 ) {
F_6 ( L_5 , V_8 , V_3 ) ;
goto V_15;
}
return;
V_15:
F_13 ( & V_13 ) ;
}
static int F_14 ( unsigned V_16 , int V_17 )
{
F_15 ( V_18 , V_17 ) ;
return 0 ;
}
static int F_16 ( unsigned V_16 )
{
return F_17 ( V_18 ) ;
}
static int F_18 ( unsigned V_16 )
{
return ! F_17 ( V_19 ) ;
}
static int F_19 ( T_4 V_20 )
{
int V_21 = F_20 ( V_19 ) ;
int error = 0 ;
if ( V_20 != NULL ) {
V_22 = V_20 ;
error = F_21 ( V_21 , V_23 ,
V_24 |
V_25 ,
L_6 , NULL ) ;
if ( error )
F_22 ( L_7
L_8 , V_8 ) ;
} else {
F_23 ( V_21 , NULL ) ;
}
return error ;
}
static T_5 V_23 ( int V_21 , void * V_26 )
{
V_22 ( & V_27 , 1 ) ;
return V_28 ;
}
static T_1 void F_24 ( void )
{
int V_3 ;
V_3 = F_5 ( V_29 ) ;
if ( V_3 ) {
F_6 ( L_9 , V_8 , V_3 ) ;
return;
}
V_3 = F_25 ( false ) ;
if ( V_3 )
F_6 ( L_10 ,
V_8 , V_3 ) ;
V_3 = F_26 ( false ) ;
if ( V_3 )
F_6 ( L_11 ,
V_8 , V_3 ) ;
V_3 = F_27 () ;
if ( V_3 )
F_6 ( L_12 ,
V_8 , V_3 ) ;
V_3 = F_28 ( V_18 ,
V_30 , L_13 ) ;
if ( V_3 < 0 ) {
F_22 ( L_14
L_15 , V_8 , V_3 ) ;
return;
}
V_3 = F_28 ( V_19 ,
V_31 , L_16 ) ;
if ( V_3 < 0 ) {
F_22 ( L_14
L_17 , V_8 , V_3 ) ;
goto V_32;
}
V_3 = F_29 ( & V_27 ) ;
if ( V_3 ) {
F_6 ( L_18 , V_8 , V_3 ) ;
goto V_33;
}
return;
V_33:
F_30 ( V_19 ) ;
V_32:
F_30 ( V_18 ) ;
}
static T_1 void F_31 ( void )
{
int V_3 ;
V_3 = F_32 () ;
if ( V_3 )
F_6 ( L_19 , V_8 , V_3 ) ;
V_3 = F_33 () ;
if ( V_3 )
F_6 ( L_20 , V_8 , V_3 ) ;
F_34 ( V_34 ) ;
F_1 () ;
V_3 = F_35 ( V_35 ) ;
if ( V_3 )
F_6 ( L_21 , V_8 , V_3 ) ;
F_10 () ;
F_24 () ;
V_3 = F_36 () ;
if ( V_3 )
F_6 ( L_22 ,
V_8 , V_3 ) ;
V_3 = F_37 () ;
if ( V_3 )
F_6 ( L_23 ,
V_8 , V_3 ) ;
F_38 () ;
}
static int T_1 F_39 ( void )
{
if ( ! F_40 () )
return 0 ;
return F_41 ( L_24 , 2 , L_25 ) ;
}
static void T_1 F_42 ( void )
{
F_43 () ;
}
