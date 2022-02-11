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
static int F_10 ( int V_12 )
{
return F_11 ( V_13 ) ;
}
static int F_12 ( int V_12 )
{
return ! F_11 ( V_14 ) ;
}
static T_1 void F_13 ( void )
{
int V_3 ;
V_3 = F_5 ( V_15 ) ;
if ( V_3 ) {
F_6 ( L_4 , V_8 , V_3 ) ;
return;
}
V_3 = F_14 ( V_14 ,
V_16 , L_5 ) ;
if ( V_3 < 0 ) {
F_6 ( L_6 ,
V_8 , V_14 ) ;
return;
}
V_3 = F_14 ( V_13 ,
V_16 , L_7 ) ;
if ( V_3 < 0 ) {
F_6 ( L_6 ,
V_8 , V_13 ) ;
goto V_17;
}
V_3 = F_15 ( & V_18 ) ;
if ( V_3 ) {
F_6 ( L_8 , V_8 , V_3 ) ;
goto V_19;
}
return;
V_19:
F_16 ( V_13 ) ;
V_17:
F_16 ( V_14 ) ;
}
static int F_17 ( unsigned V_20 , int V_21 )
{
F_18 ( V_22 , V_21 ) ;
return 0 ;
}
static int F_19 ( unsigned V_20 )
{
return F_11 ( V_22 ) ;
}
static int F_20 ( unsigned V_20 )
{
return ! F_11 ( V_23 ) ;
}
static int F_21 ( T_4 V_24 )
{
int V_25 = F_22 ( V_23 ) ;
int error = 0 ;
if ( V_24 != NULL ) {
V_26 = V_24 ;
error = F_23 ( V_25 , V_27 ,
V_28 |
V_29 ,
L_9 , NULL ) ;
if ( error )
F_24 ( L_10
L_11 , V_8 ) ;
} else {
F_25 ( V_25 , NULL ) ;
}
return error ;
}
static T_5 V_27 ( int V_25 , void * V_30 )
{
V_26 ( & V_31 , 1 ) ;
return V_32 ;
}
static T_1 void F_26 ( void )
{
int V_3 ;
T_3 V_33 ;
V_3 = F_5 ( V_34 ) ;
if ( V_3 ) {
F_6 ( L_12 , V_8 , V_3 ) ;
return;
}
V_33 = F_3 ( F_2 ( V_35 ) ) ;
V_33 &= ~ V_36 ;
V_33 |= V_37 ;
F_7 ( V_33 , F_2 ( V_35 ) ) ;
V_3 = F_14 ( V_22 ,
V_38 , L_13 ) ;
if ( V_3 < 0 ) {
F_24 ( L_14
L_15 , V_8 , V_3 ) ;
return;
}
V_3 = F_14 ( V_23 ,
V_16 , L_16 ) ;
if ( V_3 < 0 ) {
F_24 ( L_14
L_17 , V_8 , V_3 ) ;
goto V_39;
}
V_3 = F_27 ( & V_31 ) ;
if ( V_3 ) {
F_6 ( L_18 , V_8 , V_3 ) ;
goto V_40;
}
return;
V_40:
F_16 ( V_23 ) ;
V_39:
F_16 ( V_22 ) ;
}
static T_1 void F_28 ( void )
{
int V_3 ;
V_3 = F_29 () ;
if ( V_3 )
F_6 ( L_19 , V_8 , V_3 ) ;
F_30 ( V_41 ) ;
F_1 () ;
V_3 = F_31 ( V_42 ) ;
if ( V_3 )
F_6 ( L_20 , V_8 , V_3 ) ;
F_13 () ;
F_26 () ;
V_3 = F_32 () ;
if ( V_3 )
F_6 ( L_21 ,
V_8 , V_3 ) ;
V_3 = F_33 () ;
if ( V_3 )
F_6 ( L_22 ,
V_8 , V_3 ) ;
}
static int T_1 F_34 ( void )
{
if ( ! F_35 () )
return 0 ;
return F_36 ( L_23 , 2 , L_24 ) ;
}
static void T_1 F_37 ( void )
{
F_38 () ;
}
