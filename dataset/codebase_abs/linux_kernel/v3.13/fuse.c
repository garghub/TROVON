T_1 F_1 ( unsigned long V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
bool F_3 ( int V_3 )
{
return F_1 ( V_4 + V_3 * 4 ) ;
}
static enum V_5 F_4 ( T_1 V_6 )
{
T_1 V_7 = ( V_6 >> 16 ) & 0xf ;
switch ( V_7 ) {
case 1 :
return V_8 ;
case 2 :
return V_9 ;
case 3 :
if ( V_10 == V_11 &&
( F_3 ( 18 ) || F_3 ( 19 ) ) )
return V_12 ;
else
return V_13 ;
case 4 :
return V_14 ;
default:
return V_15 ;
}
}
static void F_5 ( void )
{
T_1 V_16 ;
V_16 = F_1 ( V_4 ) ;
V_17 = ( V_16 >> 6 ) & 3 ;
V_16 = F_1 ( V_4 ) ;
V_18 = ( V_16 >> 12 ) & 3 ;
}
T_1 F_6 ( void )
{
return F_7 ( F_8 ( V_19 ) + 0x804 ) ;
}
static void T_2 F_9 ( void )
{
T_1 V_20 [ 2 ] ;
V_20 [ 0 ] = F_1 ( V_21 ) ;
V_20 [ 1 ] = F_1 ( V_22 ) ;
F_10 ( V_20 , sizeof( V_20 ) ) ;
}
static void T_2 F_11 ( void )
{
T_1 V_20 [ 7 ] ;
V_20 [ 0 ] = F_1 ( V_23 ) ;
V_20 [ 1 ] = F_1 ( V_24 ) ;
V_20 [ 2 ] = F_1 ( V_25 ) ;
V_20 [ 3 ] = F_1 ( V_26 ) ;
V_20 [ 4 ] = F_1 ( V_27 ) ;
V_20 [ 5 ] = F_1 ( V_28 ) ;
V_20 [ 6 ] = F_1 ( V_29 ) ;
F_10 ( V_20 , sizeof( V_20 ) ) ;
}
void T_2 F_12 ( void )
{
T_1 V_6 ;
T_1 V_20 [ 5 ] ;
T_1 V_16 = F_13 ( F_8 ( V_30 + 0x48 ) ) ;
V_16 |= 1 << 28 ;
F_14 ( V_16 , F_8 ( V_30 + 0x48 ) ) ;
V_16 = F_1 ( V_31 ) ;
V_20 [ 0 ] = V_16 ;
V_32 = V_16 & 0xFF ;
V_16 = F_2 ( V_19 + V_33 ) ;
V_20 [ 1 ] = V_16 ;
V_34 = ( V_16 & V_35 ) >> V_36 ;
V_6 = F_6 () ;
V_20 [ 2 ] = V_6 ;
V_10 = ( V_6 >> 8 ) & 0xff ;
switch ( V_10 ) {
case V_11 :
V_4 = V_37 ;
V_38 = & V_39 ;
break;
case V_40 :
V_4 = V_41 ;
V_38 = & V_42 ;
break;
case V_43 :
V_38 = & V_44 ;
break;
default:
F_15 ( L_1 , V_10 ) ;
V_4 = V_37 ;
V_38 = & F_5 ;
}
V_5 = F_4 ( V_6 ) ;
V_38 () ;
V_20 [ 3 ] = ( V_17 << 16 ) | V_18 ;
V_20 [ 4 ] = ( V_45 << 16 ) | V_46 ;
F_10 ( V_20 , sizeof( V_20 ) ) ;
switch ( V_10 ) {
case V_11 :
F_9 () ;
break;
case V_40 :
case V_43 :
default:
F_11 () ;
break;
}
F_16 ( L_2 ,
V_47 [ V_5 ] ,
V_32 , V_17 ,
V_18 ) ;
}
