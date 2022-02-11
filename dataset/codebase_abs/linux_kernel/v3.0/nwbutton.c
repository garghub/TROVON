int F_1 ( void (* F_2) ( void ) , int V_1 )
{
int V_2 = 0 ;
if ( V_3 == 32 ) {
return - V_4 ;
}
if ( ! F_2 ) {
return - V_5 ;
}
V_3 ++ ;
for (; ( V_6 [ V_2 ] . F_2 ) ; V_2 ++ ) ;
V_6 [ V_2 ] . F_2 = F_2 ;
V_6 [ V_2 ] . V_1 = V_1 ;
return 0 ;
}
int F_3 ( void (* F_2) ( void ) )
{
int V_2 = 31 ;
if ( ! F_2 ) {
return - V_5 ;
}
while ( V_2 >= 0 ) {
if ( ( V_6 [ V_2 ] . F_2 ) == F_2 ) {
V_6 [ V_2 ] . F_2 = NULL ;
V_6 [ V_2 ] . V_1 = 0 ;
V_3 -- ;
return 0 ;
} ;
V_2 -- ;
} ;
return - V_5 ;
}
static void F_4 ( int V_7 )
{
int V_2 = 0 ;
for (; V_2 <= 31 ; V_2 ++ ) {
if ( ( V_6 [ V_2 ] . V_1 ) == V_7 ) {
if ( V_6 [ V_2 ] . F_2 ) {
V_6 [ V_2 ] . F_2 () ;
}
}
}
}
static void F_5 ( unsigned long V_8 )
{
#ifdef F_6
if ( V_9 == V_10 )
F_7 ( V_11 , 1 ) ;
#endif
F_4 ( V_9 ) ;
V_12 = sprintf ( V_13 , L_1 , V_9 ) ;
V_9 = 0 ;
F_8 ( & V_14 ) ;
}
static T_1 F_9 ( int V_15 , void * V_16 )
{
V_9 ++ ;
F_10 ( & V_17 , V_18 + V_19 ) ;
return V_20 ;
}
static int F_11 ( struct V_21 * V_22 , char T_2 * V_23 ,
T_3 V_1 , T_4 * V_24 )
{
F_12 ( & V_14 ) ;
return ( F_13 ( V_23 , & V_13 , V_12 ) )
? - V_25 : V_12 ;
}
static int T_5 F_14 ( void )
{
if ( ! F_15 () )
return - V_26 ;
F_16 ( V_27 L_2
L_3 , V_28 ) ;
if ( F_17 ( & V_29 ) ) {
F_16 ( V_30 L_4
L_5 , V_31 ) ;
return - V_32 ;
}
if ( F_18 ( V_33 , F_9 , V_34 ,
L_6 , NULL ) ) {
F_16 ( V_30 L_7 ,
V_33 ) ;
F_19 ( & V_29 ) ;
return - V_35 ;
}
return 0 ;
}
static void T_6 F_20 ( void )
{
F_21 ( V_33 , NULL ) ;
F_19 ( & V_29 ) ;
}
