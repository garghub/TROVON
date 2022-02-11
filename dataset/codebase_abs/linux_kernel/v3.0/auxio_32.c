void T_1 F_1 ( void )
{
T_2 V_1 , V_2 ;
struct V_3 V_4 [ 1 ] ;
struct V_5 V_6 ;
switch ( V_7 ) {
case V_8 :
case V_9 :
case V_10 :
return;
default:
break;
}
V_1 = F_2 ( V_11 ) ;
V_2 = F_3 ( V_1 , L_1 ) ;
if( ! V_2 ) {
V_1 = F_3 ( V_1 , L_2 ) ;
V_1 = F_2 ( V_1 ) ;
V_2 = F_3 ( V_1 , L_3 ) ;
if( ! V_2 ) {
#ifdef F_4
return;
#else
if( F_3 ( V_1 , L_4 ) ) {
return;
}
F_5 ( L_5 ) ;
F_6 () ;
#endif
}
}
if( F_7 ( V_2 , L_6 , ( char * ) V_4 , sizeof( V_4 ) ) <= 0 )
return;
F_8 ( V_4 , 0x1 ) ;
V_6 . V_12 = V_4 [ 0 ] . V_13 & 0xF ;
V_6 . V_14 = V_4 [ 0 ] . V_15 ;
V_6 . V_16 = V_4 [ 0 ] . V_15 + V_4 [ 0 ] . V_17 - 1 ;
V_18 = F_9 ( & V_6 , 0 , V_4 [ 0 ] . V_17 , L_3 ) ;
if( ( ( ( unsigned long ) V_4 [ 0 ] . V_15 ) & 3 ) == 3 ||
V_7 == V_19 )
V_18 += ( 3 - ( ( unsigned long ) V_18 & 3 ) ) ;
F_10 ( V_20 , 0 ) ;
}
unsigned char F_11 ( void )
{
if( V_18 )
return F_12 ( V_18 ) ;
return 0 ;
}
void F_10 ( unsigned char V_21 , unsigned char V_22 )
{
unsigned char V_23 ;
unsigned long V_12 ;
F_13 ( & V_24 , V_12 ) ;
switch( V_7 ) {
case V_19 :
V_23 = F_12 ( V_18 ) ;
F_14 ( ( ( V_23 | V_21 ) & ~ V_22 ) | V_25 ,
V_18 ) ;
break;
case V_26 :
if( ! V_18 )
break;
V_23 = F_12 ( V_18 ) ;
F_14 ( ( ( V_23 | V_21 ) & ~ V_22 ) | V_27 ,
V_18 ) ;
break;
case V_9 :
break;
default:
F_15 ( L_7 ) ;
}
F_16 ( & V_24 , V_12 ) ;
}
void T_1 F_17 ( void )
{
struct V_3 V_28 ;
T_2 V_1 ;
struct V_5 V_6 ;
V_1 = F_2 ( V_11 ) ;
V_1 = F_3 ( V_1 , L_2 ) ;
V_1 = F_2 ( V_1 ) ;
V_1 = F_3 ( V_1 , L_8 ) ;
if ( V_1 == 0 || ( V_29 ) V_1 == - 1 )
return;
if ( F_7 ( V_1 , L_6 , ( char * ) & V_28 , sizeof( V_28 ) ) <= 0 )
return;
F_8 ( & V_28 , 1 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_12 = V_28 . V_13 & 0xF ;
V_6 . V_14 = V_28 . V_15 ;
V_6 . V_16 = V_28 . V_15 + V_28 . V_17 - 1 ;
V_30 = ( unsigned char * ) F_9 ( & V_6 , 0 ,
V_28 . V_17 , L_9 ) ;
if ( V_30 )
F_18 ( V_31 L_10 ) ;
}
