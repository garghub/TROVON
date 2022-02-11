static int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return ( ! V_1 && ( ( F_2 ( V_2 ) == V_3 ) ||
( F_2 ( V_2 ) == V_4 ) ) ) ;
}
static T_1 * F_3 ( const T_1 * V_5 , int V_6 )
{
T_1 V_7 ;
V_7 = ( T_1 ) V_5 + V_6 + ( V_8 ? - 0x10 : 0x20 ) ;
V_8 = 0 ;
return ( T_1 * ) V_7 ;
}
static int F_4 ( unsigned int V_9 , unsigned int V_1 ,
unsigned int V_2 , int V_6 , int V_10 , T_1 * V_11 )
{
T_1 * V_7 ;
if ( ! F_1 ( V_1 , V_2 ) )
return V_12 . V_13 ( V_9 , V_1 , V_2 , V_6 , V_10 , V_11 ) ;
if ( V_6 >= 0x70 )
V_7 = & V_14 ;
else {
switch ( V_2 ) {
case 0x8 :
V_7 = F_3 ( V_15 ? V_16 : V_17 , V_6 ) ;
break;
case 0x9 :
V_7 = F_3 ( V_15 ? V_18 : V_19 , V_6 ) ;
break;
case 0xa :
V_7 = V_15 ? F_3 ( V_20 , V_6 ) : & V_21 ;
break;
case 0x78 :
V_7 = F_3 ( V_22 , V_6 ) ;
break;
case 0x7b :
V_7 = F_3 ( V_23 , V_6 ) ;
break;
case 0x7c :
V_7 = F_3 ( V_24 , V_6 ) ;
break;
case 0x7d :
V_7 = F_3 ( V_25 , V_6 ) ;
break;
default:
V_7 = & V_21 ;
break;
}
}
switch ( V_10 ) {
case 1 :
* V_11 = * ( V_26 * ) V_7 ;
break;
case 2 :
* V_11 = * ( V_27 * ) V_7 ;
break;
case 4 :
* V_11 = * V_7 ;
break;
default:
F_5 () ;
}
return 0 ;
}
static int F_6 ( unsigned int V_9 , unsigned int V_1 ,
unsigned int V_2 , int V_6 , int V_10 , T_1 V_11 )
{
if ( ! F_1 ( V_1 , V_2 ) )
return V_12 . V_28 ( V_9 , V_1 , V_2 , V_6 , V_10 , V_11 ) ;
if ( ( V_6 >= 0x10 ) && ( V_6 < 0x2c ) ) {
if ( V_11 == ~ 0 )
V_8 = 1 ;
} else {
if ( ( V_6 != V_29 ) && ( V_6 != V_30 ) &&
( V_6 != V_31 ) &&
( V_6 != V_32 ) && ( V_6 != 0x44 ) )
F_7 ( V_33 L_1
L_2 , V_2 , V_6 , V_11 ) ;
}
return 0 ;
}
int T_2 F_8 ( void )
{
F_7 ( V_34 L_3 ) ;
V_35 = & V_36 ;
V_15 = F_9 () ;
return 0 ;
}
