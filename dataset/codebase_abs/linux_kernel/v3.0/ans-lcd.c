static void
F_1 ( unsigned char V_1 )
{
#ifdef F_2
F_3 ( V_2 L_1 , V_1 ) ;
#endif
F_4 ( V_3 + V_4 , V_1 ) ;
switch( V_1 ) {
case 1 :
case 2 :
case 3 :
F_5 ( V_5 ) ; break;
default: F_5 ( V_6 ) ;
}
}
static void
F_6 ( unsigned char V_1 )
{
F_4 ( V_3 + V_7 , V_1 ) ;
F_5 ( V_6 ) ;
}
static T_1
F_7 ( struct V_8 * V_8 , const char T_2 * V_9 ,
T_3 V_10 , T_4 * V_11 )
{
const char T_2 * V_12 = V_9 ;
int V_13 ;
#ifdef F_2
F_3 ( V_2 L_2 ) ;
#endif
if ( ! F_8 ( V_14 , V_9 , V_10 ) )
return - V_15 ;
F_9 ( & V_16 ) ;
for ( V_13 = * V_11 ; V_10 > 0 ; ++ V_13 , ++ V_12 , -- V_10 )
{
char V_1 ;
F_10 ( V_1 , V_12 ) ;
F_6 ( V_1 ) ;
}
F_11 ( & V_16 ) ;
* V_11 = V_13 ;
return V_12 - V_9 ;
}
static long
F_12 ( struct V_8 * V_8 , unsigned int V_17 , unsigned long V_18 )
{
char V_19 , T_2 * V_20 ;
long V_21 = 0 ;
#ifdef F_2
F_3 ( V_2 L_3 , V_17 , V_18 ) ;
#endif
F_9 ( & V_16 ) ;
switch ( V_17 )
{
case V_22 :
F_1 ( 0x38 ) ;
F_1 ( 0x0f ) ;
F_1 ( 0x06 ) ;
F_1 ( 0x01 ) ;
F_1 ( 0x02 ) ;
break;
case V_23 :
V_20 = ( char T_2 * ) V_18 ;
F_10 ( V_19 , V_20 ) ;
for (; V_19 ; V_20 ++ ) {
F_1 ( V_19 ) ;
F_10 ( V_19 , V_20 ) ;
}
break;
case V_24 :
if ( ! F_13 ( V_25 ) )
V_21 = - V_26 ;
else
V_6 = V_18 ;
break;
case V_27 :
if ( ! F_13 ( V_25 ) )
V_21 = - V_26 ;
else
V_5 = V_18 ;
break;
default:
V_21 = - V_28 ;
}
F_11 ( & V_16 ) ;
return V_21 ;
}
static int
F_14 ( struct V_29 * V_29 , struct V_8 * V_8 )
{
return 0 ;
}
static int T_5
F_15 ( void )
{
int V_30 ;
int V_31 ;
struct V_32 * V_33 ;
V_33 = F_16 ( NULL , L_4 ) ;
if ( ! V_33 || ! V_33 -> V_34 || strcmp ( V_33 -> V_34 -> V_35 , L_5 ) ) {
F_17 ( V_33 ) ;
return - V_36 ;
}
F_17 ( V_33 ) ;
V_3 = F_18 ( V_37 , 0x20 ) ;
V_31 = F_19 ( & V_38 ) ;
if( V_31 < 0 ) {
F_3 ( V_39 L_6 ) ;
F_20 ( V_3 ) ;
return V_31 ;
}
#ifdef F_2
F_3 ( V_2 L_7 ) ;
#endif
F_9 ( & V_16 ) ;
F_1 ( 0x38 ) ;
F_1 ( 0x0c ) ;
F_1 ( 0x06 ) ;
F_1 ( 0x01 ) ;
F_1 ( 0x02 ) ;
for( V_30 = 0 ; V_30 < 80 ; V_30 ++ ) {
F_6 ( V_40 [ V_30 ] ) ;
}
F_11 ( & V_16 ) ;
return 0 ;
}
static void T_6
F_21 ( void )
{
F_22 ( & V_38 ) ;
F_20 ( V_3 ) ;
}
