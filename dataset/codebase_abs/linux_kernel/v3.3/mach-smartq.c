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
F_5 , V_11 |
V_12 | V_13 ,
L_4 , V_7 ) ;
if ( V_10 != 0 )
F_12 ( L_5 , V_10 ) ;
} else {
F_13 ( F_11 ( F_4 ( 10 ) ) , V_7 ) ;
}
}
static int F_14 ( struct V_14 * V_15 )
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
static void F_22 ( struct V_16 * V_17 , unsigned int V_18 )
{
F_21 ( F_20 ( 3 ) , V_18 ) ;
}
static void T_2 F_23 ( void )
{
T_3 V_19 ;
V_19 = F_24 ( V_20 ) ;
V_19 &= ~ V_21 ;
V_19 |= V_22 ;
F_25 ( V_19 , V_20 ) ;
V_19 = F_24 ( V_23 ) ;
V_19 &= ~ V_24 ;
F_25 ( V_19 , V_23 ) ;
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
V_25 = F_26 ;
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
goto V_26;
}
if ( ! F_9 () ) {
V_10 = F_19 ( F_4 ( 10 ) , L_4 ) ;
if ( V_10 < 0 ) {
F_12 ( L_13 , V_3 ) ;
goto V_27;
}
}
F_21 ( F_4 ( 0 ) , 0 ) ;
F_21 ( F_4 ( 1 ) , 0 ) ;
if ( ! F_9 () )
F_30 ( F_4 ( 10 ) ) ;
V_28 . V_15 . V_29 = & V_30 ;
return 0 ;
V_27:
F_31 ( F_4 ( 1 ) ) ;
V_26:
F_31 ( F_4 ( 0 ) ) ;
return V_10 ;
}
static int T_2 F_32 ( void )
{
V_31 . V_32 = 12000000 ;
return 0 ;
}
static int T_2 F_33 ( void )
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
F_34 ( 100 ) ;
F_3 ( F_27 ( 2 ) , 1 ) ;
F_30 ( F_27 ( 2 ) ) ;
return 0 ;
}
void T_2 F_35 ( void )
{
F_36 ( V_33 , F_37 ( V_33 ) ) ;
F_38 ( 12000000 ) ;
F_39 ( V_34 , F_37 ( V_34 ) ) ;
F_23 () ;
}
void T_2 F_40 ( void )
{
F_41 ( NULL ) ;
F_42 ( & V_35 ) ;
F_43 ( & V_36 ) ;
F_44 ( & V_36 ) ;
F_45 ( & V_37 ) ;
F_46 ( 0 , V_38 ,
F_37 ( V_38 ) ) ;
F_47 ( F_18 () ) ;
F_47 ( F_28 () ) ;
F_47 ( F_29 () ) ;
F_47 ( F_32 () ) ;
F_47 ( F_33 () ) ;
F_48 ( V_39 , F_37 ( V_39 ) ) ;
}
