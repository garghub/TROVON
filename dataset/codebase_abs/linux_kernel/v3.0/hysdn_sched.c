int
F_1 ( T_1 * V_1 , unsigned char * V_2 , unsigned short V_3 ,
unsigned short V_4 )
{
switch ( V_4 ) {
case V_5 :
if ( V_6 & ( 1 << V_1 -> V_7 ) ) {
F_2 ( V_1 , V_2 , V_3 ) ;
}
break;
case V_8 :
F_3 ( V_1 , ( V_9 * ) V_2 , V_3 ) ;
if ( V_1 -> V_10 == V_11 )
V_1 -> V_10 = V_12 ;
break;
#ifdef F_4
case V_13 :
if ( V_14 & ( 1 << V_1 -> V_7 ) ) {
F_5 ( V_1 , V_2 , V_3 ) ;
}
break;
#endif
default:
F_6 ( V_15 L_1 , V_4 , V_3 ) ;
break;
}
return ( 1 ) ;
}
int
F_7 ( T_1 * V_1 , unsigned char * V_2 ,
unsigned short volatile * V_3 , unsigned short volatile * V_4 ,
unsigned short V_16 )
{
struct V_17 * V_18 ;
if ( V_1 -> V_19 ) {
V_1 -> V_19 = 0 ;
F_8 ( V_1 ) ;
}
if ( V_1 -> V_20 ) {
if ( V_1 -> V_21 <= V_16 ) {
memcpy ( V_2 , V_1 -> V_22 , V_1 -> V_21 ) ;
* V_3 = V_1 -> V_21 ;
* V_4 = V_1 -> V_23 ;
V_1 -> V_20 = 0 ;
return ( 1 ) ;
}
V_1 -> V_20 = 0 ;
}
if ( ( V_1 -> V_10 == V_12 ) &&
( V_16 >= V_24 ) ) {
strcpy ( V_2 , V_25 ) ;
* V_3 = V_24 ;
* V_4 = V_8 ;
V_1 -> V_10 = V_11 ;
return ( 1 ) ;
}
if ( ( V_1 -> V_10 == V_26 ) &&
( V_16 >= V_27 ) ) {
strcpy ( V_2 , V_28 ) ;
* V_3 = V_27 ;
* V_4 = V_8 ;
V_1 -> V_10 = V_29 ;
return ( 1 ) ;
}
if ( ( V_6 & ( 1 << V_1 -> V_7 ) ) &&
( V_18 = F_9 ( V_1 ) ) != NULL )
{
if ( V_18 -> V_3 <= V_16 ) {
F_10 ( V_18 , V_2 , V_18 -> V_3 ) ;
* V_3 = V_18 -> V_3 ;
* V_4 = V_5 ;
V_1 -> V_19 = 1 ;
return ( 1 ) ;
} else
F_8 ( V_1 ) ;
}
#ifdef F_4
if( ( ( V_14 & ( 1 << V_1 -> V_7 ) ) ) &&
( ( V_18 = F_11 ( V_1 ) ) != NULL ) )
{
if ( V_18 -> V_3 <= V_16 ) {
F_10 ( V_18 , V_2 , V_18 -> V_3 ) ;
* V_3 = V_18 -> V_3 ;
* V_4 = V_13 ;
F_12 ( V_1 ) ;
return ( 1 ) ;
}
}
#endif
return ( 0 ) ;
}
int
F_13 ( T_1 * V_1 , unsigned char * line , unsigned short V_4 )
{
int V_30 = 50 ;
unsigned long V_31 ;
if ( V_1 -> V_32 & V_33 )
F_14 ( V_1 , L_2 , V_4 , strlen ( line ) + 1 ) ;
while ( V_1 -> V_20 ) {
if ( V_1 -> V_32 & V_33 )
F_14 ( V_1 , L_3 ) ;
F_15 ( 20 ) ;
if ( ! -- V_30 )
return ( - V_34 ) ;
}
F_16 ( & V_1 -> V_35 , V_31 ) ;
strcpy ( V_1 -> V_22 , line ) ;
V_1 -> V_21 = strlen ( line ) + 1 ;
V_1 -> V_23 = V_4 ;
V_1 -> V_20 = 1 ;
F_17 ( & V_1 -> V_36 ) ;
F_18 ( & V_1 -> V_35 , V_31 ) ;
if ( V_1 -> V_32 & V_33 )
F_14 ( V_1 , L_4 ) ;
V_30 ++ ;
while ( V_1 -> V_20 ) {
if ( V_1 -> V_32 & V_33 )
F_14 ( V_1 , L_5 ) ;
F_15 ( 20 ) ;
if ( ! -- V_30 )
return ( - V_34 ) ;
}
if ( V_1 -> V_32 & V_33 )
F_14 ( V_1 , L_6 ) ;
return ( 0 ) ;
}
