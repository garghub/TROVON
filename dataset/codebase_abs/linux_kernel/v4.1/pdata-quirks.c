static void T_1 F_1 ( void )
{
V_1 [ 0 ] . V_2 = F_2 () ;
}
static void T_1 F_3 ( void )
{
T_2 V_3 ;
V_3 = F_4 ( V_4 ) ;
V_3 |= V_5 ;
F_5 ( V_3 , V_4 ) ;
}
static int F_6 ( struct V_6 * V_7 ,
unsigned V_8 ,
unsigned V_9 )
{
int V_10 ;
V_10 = F_7 ( V_8 + 2 , V_11 ,
L_1 ) ;
if ( V_10 )
return V_10 ;
F_8 ( V_8 , 0 ) ;
return 0 ;
}
static void T_1 F_9 ( int V_8 , char * V_12 )
{
int V_13 = F_7 ( V_8 , V_14 , V_12 ) ;
if ( V_13 ) {
F_10 ( L_2 ,
V_12 , V_13 ) ;
return;
}
F_8 ( V_8 , 0 ) ;
F_11 ( 10 ) ;
F_12 ( V_8 , 1 ) ;
F_13 ( 1 ) ;
}
static void T_1 F_14 ( void )
{
V_15 . V_16 = F_6 ;
}
static void T_1 F_15 ( void )
{
F_9 ( 167 , L_3 ) ;
}
static void T_1 F_16 ( void )
{
F_9 ( 167 , L_3 ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( & V_17 ) ;
F_18 ( & V_18 ) ;
}
static void T_1 F_19 ( void )
{
F_18 ( & V_17 ) ;
F_18 ( & V_18 ) ;
}
static void T_1 F_20 ( void )
{
F_3 () ;
}
static void F_21 ( void )
{
T_2 V_19 ;
V_19 = F_4 ( V_20 ) ;
V_19 |= ( V_21 | V_22 |
V_23 | V_24 ) ;
F_5 ( V_19 , V_20 ) ;
F_4 ( V_20 ) ;
}
static void F_22 ( void )
{
T_2 V_19 ;
V_19 = F_4 ( V_20 ) ;
V_19 |= ( V_21 | V_22 ) ;
F_5 ( V_19 , V_20 ) ;
F_4 ( V_20 ) ;
}
static void T_1 F_23 ( void )
{
T_2 V_19 ;
V_19 = F_4 ( V_25 ) ;
V_19 &= ~ V_26 ;
F_5 ( V_19 , V_25 ) ;
F_4 ( V_25 ) ;
}
static void T_1 F_24 ( void )
{
int V_13 = F_25 ( V_27 ,
F_26 ( V_27 ) ) ;
if ( V_13 ) {
F_10 ( L_4 , V_13 ) ;
return;
}
F_8 ( V_27 [ 0 ] . V_8 , 0 ) ;
F_8 ( V_27 [ 1 ] . V_8 , 0 ) ;
F_13 ( 100 ) ;
F_12 ( V_27 [ 1 ] . V_8 , 0 ) ;
}
static void T_1 F_27 ( void )
{
F_9 ( 152 , L_5 ) ;
F_9 ( 98 , L_3 ) ;
F_23 () ;
F_3 () ;
F_24 () ;
}
static void T_1 F_28 ( void )
{
F_23 () ;
}
static void T_1 F_29 ( void )
{
F_3 () ;
if ( F_30 () == V_28 ) {
if ( F_31 ( V_29 ) ) {
F_32 ( L_6 ) ;
F_33 ( F_34 ( 6 ) , 0 ) ;
} else {
F_35 ( L_7 ) ;
F_35 ( L_8 ) ;
}
F_32 ( L_9 ) ;
F_18 ( & V_30 ) ;
}
}
static void T_1 F_36 ( void )
{
F_3 () ;
}
static void T_1 F_37 ( void )
{
}
void F_38 ( int V_31 , void (* F_39)( void ) )
{
V_32 . V_31 = V_31 ;
V_32 . F_39 = F_39 ;
}
void F_40 ( struct V_6 * V_7 )
{
if ( V_7 -> V_2 )
return;
if ( strcmp ( L_10 , F_41 ( V_7 ) ) )
return;
V_7 -> V_2 = & V_15 ;
}
static void F_42 ( struct V_33 * V_34 )
{
while ( V_34 -> V_35 ) {
if ( F_43 ( V_34 -> V_35 ) ) {
if ( V_34 -> V_36 )
V_34 -> V_36 () ;
break;
}
V_34 ++ ;
}
}
void T_1 F_44 ( const struct V_37 * V_38 )
{
F_45 ( NULL , NULL ) ;
F_42 ( V_39 ) ;
F_46 ( NULL , V_38 ,
V_1 , NULL ) ;
F_42 ( V_40 ) ;
}
