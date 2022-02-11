void T_1 F_1 ( void )
{
T_2 V_1 , V_2 ;
struct V_3 V_4 [ 1 ] ;
struct V_5 V_6 ;
switch ( V_7 ) {
case V_8 :
case V_9 :
return;
default:
break;
}
V_1 = F_2 ( V_10 ) ;
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
V_6 . V_11 = V_4 [ 0 ] . V_12 & 0xF ;
V_6 . V_13 = V_4 [ 0 ] . V_14 ;
V_6 . V_15 = V_4 [ 0 ] . V_14 + V_4 [ 0 ] . V_16 - 1 ;
V_17 = F_9 ( & V_6 , 0 , V_4 [ 0 ] . V_16 , L_3 ) ;
if ( ( ( ( unsigned long ) V_4 [ 0 ] . V_14 ) & 3 ) == 3 )
V_17 += ( 3 - ( ( unsigned long ) V_17 & 3 ) ) ;
F_10 ( V_18 , 0 ) ;
}
unsigned char F_11 ( void )
{
if( V_17 )
return F_12 ( V_17 ) ;
return 0 ;
}
void F_10 ( unsigned char V_19 , unsigned char V_20 )
{
unsigned char V_21 ;
unsigned long V_11 ;
F_13 ( & V_22 , V_11 ) ;
switch ( V_7 ) {
case V_23 :
if( ! V_17 )
break;
V_21 = F_12 ( V_17 ) ;
F_14 ( ( ( V_21 | V_19 ) & ~ V_20 ) | V_24 ,
V_17 ) ;
break;
case V_9 :
break;
default:
F_15 ( L_7 ) ;
}
F_16 ( & V_22 , V_11 ) ;
}
void T_1 F_17 ( void )
{
struct V_3 V_25 ;
T_2 V_1 ;
struct V_5 V_6 ;
V_1 = F_2 ( V_10 ) ;
V_1 = F_3 ( V_1 , L_2 ) ;
V_1 = F_2 ( V_1 ) ;
V_1 = F_3 ( V_1 , L_8 ) ;
if ( V_1 == 0 || ( V_26 ) V_1 == - 1 )
return;
if ( F_7 ( V_1 , L_6 , ( char * ) & V_25 , sizeof( V_25 ) ) <= 0 )
return;
F_8 ( & V_25 , 1 ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_11 = V_25 . V_12 & 0xF ;
V_6 . V_13 = V_25 . V_14 ;
V_6 . V_15 = V_25 . V_14 + V_25 . V_16 - 1 ;
V_27 = ( unsigned char * ) F_9 ( & V_6 , 0 ,
V_25 . V_16 , L_9 ) ;
if ( V_27 )
F_18 ( V_28 L_10 ) ;
}
