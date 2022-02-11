static void F_1 ( void )
{
if ( F_2 ( V_1 ) )
V_1 = F_3 ( NULL , L_1 ) ;
if ( F_2 ( V_1 ) )
return;
F_4 ( V_1 ) ;
}
static void F_5 ( void )
{
if ( F_2 ( V_1 ) )
return;
F_6 ( V_1 ) ;
}
T_1 F_7 ( unsigned long V_2 )
{
return F_8 ( V_3 + V_2 ) ;
}
bool F_9 ( int V_4 )
{
bool V_5 ;
F_1 () ;
V_5 = F_7 ( V_6 + V_4 * 4 ) ;
F_5 () ;
return V_5 ;
}
static enum V_7 F_10 ( T_1 V_8 )
{
T_1 V_9 = ( V_8 >> 16 ) & 0xf ;
switch ( V_9 ) {
case 1 :
return V_10 ;
case 2 :
return V_11 ;
case 3 :
if ( V_12 == V_13 &&
( F_9 ( 18 ) || F_9 ( 19 ) ) )
return V_14 ;
else
return V_15 ;
case 4 :
return V_16 ;
default:
return V_17 ;
}
}
static void F_11 ( void )
{
T_1 V_18 ;
F_1 () ;
V_18 = F_7 ( V_6 ) ;
V_19 = ( V_18 >> 6 ) & 3 ;
V_18 = F_7 ( V_6 ) ;
V_20 = ( V_18 >> 12 ) & 3 ;
F_5 () ;
}
T_1 F_12 ( void )
{
return F_13 ( F_14 ( V_21 ) + 0x804 ) ;
}
static void T_2 F_15 ( void )
{
T_1 V_22 [ 2 ] ;
V_22 [ 0 ] = F_7 ( V_23 ) ;
V_22 [ 1 ] = F_7 ( V_24 ) ;
F_16 ( V_22 , sizeof( V_22 ) ) ;
}
static void T_2 F_17 ( void )
{
T_1 V_22 [ 7 ] ;
V_22 [ 0 ] = F_7 ( V_25 ) ;
V_22 [ 1 ] = F_7 ( V_26 ) ;
V_22 [ 2 ] = F_7 ( V_27 ) ;
V_22 [ 3 ] = F_7 ( V_28 ) ;
V_22 [ 4 ] = F_7 ( V_29 ) ;
V_22 [ 5 ] = F_7 ( V_30 ) ;
V_22 [ 6 ] = F_7 ( V_31 ) ;
F_16 ( V_22 , sizeof( V_22 ) ) ;
}
void T_2 F_18 ( void )
{
T_1 V_8 ;
T_1 V_22 [ 5 ] ;
T_1 V_18 = F_19 ( F_14 ( V_32 + 0x48 ) ) ;
V_18 |= 1 << 28 ;
F_20 ( V_18 , F_14 ( V_32 + 0x48 ) ) ;
V_18 = F_19 ( F_14 ( V_32 + 0x14 ) ) ;
V_18 |= 1 << 7 ;
F_20 ( V_18 , F_14 ( V_32 + 0x14 ) ) ;
V_1 = F_21 ( - V_33 ) ;
V_18 = F_7 ( V_34 ) ;
V_22 [ 0 ] = V_18 ;
V_35 = V_18 & 0xFF ;
V_18 = F_8 ( V_21 + V_36 ) ;
V_22 [ 1 ] = V_18 ;
V_37 = ( V_18 & V_38 ) >> V_39 ;
V_8 = F_12 () ;
V_22 [ 2 ] = V_8 ;
V_12 = ( V_8 >> 8 ) & 0xff ;
switch ( V_12 ) {
case V_13 :
V_6 = V_40 ;
V_41 = & V_42 ;
break;
case V_43 :
V_6 = V_44 ;
V_41 = & V_45 ;
break;
case V_46 :
V_41 = & V_47 ;
break;
default:
F_22 ( L_2 , V_12 ) ;
V_6 = V_40 ;
V_41 = & F_11 ;
}
V_7 = F_10 ( V_8 ) ;
V_41 () ;
V_22 [ 3 ] = ( V_19 << 16 ) | V_20 ;
V_22 [ 4 ] = ( V_48 << 16 ) | V_49 ;
F_16 ( V_22 , sizeof( V_22 ) ) ;
switch ( V_12 ) {
case V_13 :
F_15 () ;
break;
case V_43 :
case V_46 :
default:
F_17 () ;
break;
}
F_23 ( L_3 ,
V_50 [ V_7 ] ,
V_35 , V_19 ,
V_20 ) ;
}
