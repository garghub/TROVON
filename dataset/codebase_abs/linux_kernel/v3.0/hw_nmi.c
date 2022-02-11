T_1 F_1 ( int V_1 )
{
return ( T_1 ) ( V_2 ) * 1000 * V_1 ;
}
void F_2 ( void )
{
int V_3 ;
if ( F_3 ( 0 , & V_4 ) )
return;
F_4 ( F_5 ( V_5 ) , V_6 ) ;
F_6 ( V_7 L_1 ) ;
V_8 -> V_9 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < 10 * 1000 ; V_3 ++ ) {
if ( F_7 ( F_5 ( V_5 ) ) )
break;
F_8 ( 1 ) ;
}
F_9 ( 0 , & V_4 ) ;
F_10 () ;
}
static int T_2
F_11 ( struct V_11 * V_12 ,
unsigned long V_13 , void * V_14 )
{
struct V_15 * args = V_14 ;
struct V_16 * V_17 ;
int V_18 ;
switch ( V_13 ) {
case V_19 :
break;
default:
return V_20 ;
}
V_17 = args -> V_17 ;
V_18 = F_12 () ;
if ( F_13 ( V_18 , F_5 ( V_5 ) ) ) {
static T_3 V_21 = V_22 ;
F_14 ( & V_21 ) ;
F_6 ( V_23 L_2 , V_18 ) ;
F_15 ( V_17 ) ;
F_16 ( & V_21 ) ;
F_17 ( V_18 , F_5 ( V_5 ) ) ;
return V_24 ;
}
return V_20 ;
}
static int T_4 F_18 ( void )
{
F_19 ( & V_25 ) ;
return 0 ;
}
