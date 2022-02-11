static void F_1 ( int V_1 , int V_2 )
{
F_2 ( L_1 , V_3 , V_1 , V_2 ) ;
if ( V_1 == 0 ) {
F_3 ( F_4 ( 0 ) , V_2 ) ;
F_3 ( F_4 ( 1 ) , V_2 ) ;
}
}
static T_1 F_5 ( int V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
if ( F_6 ( F_4 ( 10 ) ) == 0 ) {
F_2 ( L_2 , V_3 ) ;
F_7 ( V_7 , 3 ) ;
} else {
F_2 ( L_3 , V_3 ) ;
F_7 ( V_7 , 0 ) ;
}
return V_8 ;
}
static void F_8 ( struct V_6 * V_7 , int V_9 )
{
int V_10 ;
if ( F_9 () )
return;
if ( V_9 ) {
V_10 = F_10 ( F_11 ( F_4 ( 10 ) ) ,
F_5 ,
V_11 | V_12 ,
L_4 , V_7 ) ;
if ( V_10 != 0 )
F_12 ( L_5 , V_10 ) ;
} else {
F_13 ( F_11 ( F_4 ( 10 ) ) , V_7 ) ;
}
}
static int F_14 ( struct V_13 * V_14 )
{
F_15 ( F_16 ( 15 ) , F_17 ( 2 ) ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
int V_10 ;
V_10 = F_19 ( F_20 ( 3 ) , L_6 ) ;
if ( V_10 < 0 )
return V_10 ;
F_21 ( F_20 ( 3 ) , 0 ) ;
return 0 ;
}
static void F_22 ( struct V_15 * V_16 , unsigned int V_17 )
{
F_21 ( F_20 ( 3 ) , V_17 ) ;
}
static void T_2 F_23 ( void )
{
T_3 V_18 ;
V_18 = F_24 ( V_19 ) ;
V_18 &= ~ V_20 ;
V_18 |= V_21 ;
F_25 ( V_18 , V_19 ) ;
V_18 = F_24 ( V_22 ) ;
V_18 &= ~ V_23 ;
F_25 ( V_18 , V_22 ) ;
}
static void F_26 ( void )
{
F_21 ( F_27 ( 15 ) , 1 ) ;
}
static int T_2 F_28 ( void )
{
int V_10 ;
V_10 = F_19 ( F_27 ( 15 ) , L_7 ) ;
if ( V_10 < 0 ) {
F_12 ( L_8 , V_3 ) ;
return V_10 ;
}
F_21 ( F_27 ( 15 ) , 0 ) ;
V_24 = F_26 ;
return V_10 ;
}
static int T_2 F_29 ( void )
{
int V_10 ;
V_10 = F_19 ( F_4 ( 0 ) , L_9 ) ;
if ( V_10 < 0 ) {
F_12 ( L_10 , V_3 ) ;
return V_10 ;
}
V_10 = F_19 ( F_4 ( 1 ) , L_11 ) ;
if ( V_10 < 0 ) {
F_12 ( L_12 , V_3 ) ;
goto V_25;
}
if ( ! F_9 () ) {
V_10 = F_19 ( F_4 ( 10 ) , L_4 ) ;
if ( V_10 < 0 ) {
F_12 ( L_13 , V_3 ) ;
goto V_26;
}
}
F_21 ( F_4 ( 0 ) , 0 ) ;
F_21 ( F_4 ( 1 ) , 0 ) ;
if ( ! F_9 () )
F_30 ( F_4 ( 10 ) ) ;
V_27 . V_14 . V_28 = & V_29 ;
return 0 ;
V_26:
F_31 ( F_4 ( 1 ) ) ;
V_25:
F_31 ( F_4 ( 0 ) ) ;
return V_10 ;
}
static int T_2 F_32 ( void )
{
int V_10 ;
V_10 = F_19 ( F_27 ( 1 ) , L_14 ) ;
if ( V_10 < 0 ) {
F_12 ( L_15 , V_3 ) ;
return V_10 ;
}
V_10 = F_19 ( F_27 ( 2 ) , L_16 ) ;
if ( V_10 < 0 ) {
F_12 ( L_17 , V_3 ) ;
F_31 ( F_27 ( 1 ) ) ;
return V_10 ;
}
F_21 ( F_27 ( 1 ) , 1 ) ;
F_21 ( F_27 ( 2 ) , 0 ) ;
F_33 ( 100 ) ;
F_3 ( F_27 ( 2 ) , 1 ) ;
F_30 ( F_27 ( 2 ) ) ;
return 0 ;
}
void T_2 F_34 ( void )
{
F_35 ( V_30 , F_36 ( V_30 ) ) ;
F_37 ( 12000000 ) ;
F_38 ( 12000000 ) ;
F_39 ( V_31 , F_36 ( V_31 ) ) ;
F_40 ( V_32 , V_33 ) ;
F_23 () ;
}
void T_2 F_41 ( void )
{
F_42 ( NULL ) ;
F_43 ( & V_34 ) ;
F_44 ( & V_35 ) ;
F_45 ( & V_36 ) ;
F_46 ( & V_36 ) ;
F_47 ( & V_37 ) ;
F_48 ( 0 , V_38 ,
F_36 ( V_38 ) ) ;
F_49 ( F_18 () ) ;
F_49 ( F_28 () ) ;
F_49 ( F_29 () ) ;
F_49 ( F_32 () ) ;
F_50 ( V_39 , F_36 ( V_39 ) ) ;
F_51 ( V_40 , F_36 ( V_40 ) ) ;
}
