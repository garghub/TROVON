static bool F_1 ( void )
{
T_1 V_1 ;
int V_2 , V_3 ;
T_2 V_4 ;
T_2 V_5 [ V_6 ] = { 0 } ;
V_4 = F_2 ( V_6 ) ;
V_3 = F_3 ( V_5 , & V_4 ) ;
if ( V_3 != V_7 ) {
F_4 ( L_1 ) ;
return false ;
}
for ( V_2 = 0 ; V_2 < F_5 ( V_4 ) ; V_2 ++ ) {
V_1 = F_5 ( V_5 [ V_2 ] ) ;
if ( V_2 == V_8 )
V_1 &= ~ ( V_9 | V_10 |
V_11 ) ;
if ( V_1 )
return true ;
}
return false ;
}
static bool F_6 ( void )
{
int V_3 ;
T_3 V_12 ;
V_3 = F_7 ( & V_12 ) ;
if ( V_3 == V_7 ) {
F_8 ( L_2 ) ;
return true ;
}
if ( F_1 () ) {
F_8 ( L_3 ) ;
return true ;
}
return false ;
}
static int F_9 ( struct V_13 * V_14 ,
unsigned long V_15 , void * V_16 )
{
T_4 type ;
switch ( V_15 ) {
case V_17 :
if ( F_1 () ) {
F_8 ( L_4 ) ;
F_10 ( true ) ;
}
break;
case V_18 :
F_8 ( L_5 ) ;
F_10 ( true ) ;
break;
case V_19 :
type = F_11 ( ( (struct V_20 * ) V_16 ) -> V_21 [ 0 ] ) ;
switch ( type ) {
case V_22 :
F_8 ( L_6 ) ;
F_12 () ;
break;
case V_23 :
F_8 ( L_7 ) ;
F_10 ( true ) ;
break;
default:
F_4 ( L_8 , type ) ;
}
break;
default:
F_4 ( L_9 , V_15 ) ;
}
return 0 ;
}
static int T_5 F_13 ( void )
{
int V_24 , V_25 = 0 ;
struct V_26 * V_27 ;
V_24 = F_14 ( V_19 ,
& V_28 ) ;
if ( V_24 )
F_4 ( L_10 , V_24 ) ;
V_27 = F_15 ( L_11 ) ;
if ( V_27 ) {
V_25 = F_16 ( V_27 , L_12 ) ;
F_17 ( V_27 ) ;
}
if ( ! V_25 )
return 0 ;
F_8 ( L_13 ) ;
V_24 = F_14 ( V_17 , & V_29 ) ;
if ( V_24 )
F_4 ( L_14 , V_24 ) ;
V_24 = F_14 ( V_18 , & V_30 ) ;
if ( V_24 )
F_4 ( L_15 , V_24 ) ;
if ( F_6 () )
F_10 ( true ) ;
return 0 ;
}
