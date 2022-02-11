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
}
V_2 -- ;
}
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
if ( F_6 ( V_9 ) &&
V_10 == V_11 )
F_7 ( V_12 , 1 ) ;
F_4 ( V_10 ) ;
V_13 = sprintf ( V_14 , L_1 , V_10 ) ;
V_10 = 0 ;
F_8 ( & V_15 ) ;
}
static T_1 F_9 ( int V_16 , void * V_17 )
{
V_10 ++ ;
F_10 ( & V_18 , V_19 + V_20 ) ;
return V_21 ;
}
static int F_11 ( struct V_22 * V_23 , char T_2 * V_24 ,
T_3 V_1 , T_4 * V_25 )
{
F_12 ( V_26 ) ;
F_13 ( & V_15 , & V_26 , V_27 ) ;
F_14 () ;
F_15 ( & V_15 , & V_26 ) ;
return ( F_16 ( V_24 , & V_14 , V_13 ) )
? - V_28 : V_13 ;
}
static int T_5 F_17 ( void )
{
if ( ! F_18 () )
return - V_29 ;
F_19 ( V_30 L_2
L_3 , V_31 ) ;
if ( F_20 ( & V_32 ) ) {
F_19 ( V_33 L_4
L_5 , V_34 ) ;
return - V_35 ;
}
if ( F_21 ( V_36 , F_9 , 0 ,
L_6 , NULL ) ) {
F_19 ( V_33 L_7 ,
V_36 ) ;
F_22 ( & V_32 ) ;
return - V_37 ;
}
return 0 ;
}
static void T_6 F_23 ( void )
{
F_24 ( V_36 , NULL ) ;
F_22 ( & V_32 ) ;
}
