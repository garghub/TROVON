unsigned short F_1 ( void )
{
unsigned short V_1 ;
V_1 = ( ( unsigned short ) F_2 ( V_2 , V_3 ) << 8 ) |
( unsigned short ) F_2 ( V_2 , V_4 ) ;
return V_1 ;
}
unsigned short F_3 ( void )
{
unsigned short V_5 ;
V_5 = ( ( unsigned short ) F_2 ( V_2 , V_6 ) << 8 ) |
( unsigned short ) F_2 ( V_2 , V_7 ) ;
return V_5 ;
}
long F_4 (
unsigned char V_8 ,
unsigned char V_9 ,
unsigned char V_10 ,
unsigned char V_11 ,
unsigned char V_12 ,
unsigned char V_13 ,
unsigned char V_14 ,
unsigned char V_15 ,
unsigned char V_16 ,
unsigned char V_17
)
{
unsigned char V_18 ;
#ifdef F_5
F_6 ( 1 ) ;
#else
F_7 ( V_19 , V_20 ) ;
#endif
if ( ( F_1 () == V_21 ) && ( F_3 () == V_22 ) )
{
#ifdef F_8
#endif
if ( V_8 == 0 )
V_18 = V_23 ;
else
V_18 = V_24 ;
if ( V_9 == 0 )
V_18 |= V_25 ;
else
V_18 |= V_26 ;
if ( V_10 == 0 )
V_18 |= V_27 ;
else
V_18 |= V_28 ;
if ( V_11 == 0 )
V_18 |= V_29 ;
else
V_18 |= V_30 ;
if ( V_12 == 0 )
V_18 |= V_31 ;
else
V_18 |= V_32 ;
F_9 ( V_2 , V_33 , V_18 ) ;
if ( V_13 == 0 )
V_18 = V_34 ;
else
V_18 = V_35 ;
switch ( V_14 )
{
case 0 :
V_18 |= V_36 ;
break;
case 1 :
V_18 |= V_37 ;
break;
case 2 :
V_18 |= V_38 ;
break;
case 3 :
V_18 |= V_39 ;
break;
case 4 :
V_18 |= V_40 ;
break;
case 5 :
V_18 |= V_41 ;
break;
case 6 :
V_18 |= V_42 ;
break;
case 7 :
V_18 |= V_43 ;
break;
}
F_9 ( V_2 , V_44 , V_18 ) ;
if ( V_15 == 0 )
V_18 = V_45 ;
else
V_18 = V_46 ;
if ( V_16 == 0 )
V_18 |= V_47 ;
else
V_18 |= V_48 ;
V_18 |= ( ( V_17 & 0x07 ) << 1 ) ;
F_9 ( V_2 , V_49 , V_18 ) ;
V_18 = F_2 ( V_2 , V_33 ) ;
V_18 |= V_50 ;
F_9 ( V_2 , V_33 , V_18 ) ;
#ifdef F_8
#endif
return 0 ;
}
return ( - 1 ) ;
}
void F_10 ( void )
{
F_11 ( 0 ) ;
F_11 ( 1 ) ;
}
char * F_12 ( void )
{
return V_51 ;
}
void F_11 (
unsigned char V_52
)
{
unsigned char V_18 ;
V_18 = F_2 ( V_2 , V_33 ) ;
if ( V_52 == 1 )
{
V_18 &= ~ V_53 ;
V_18 |= V_50 ;
F_9 ( V_2 , V_33 , V_18 ) ;
}
else
{
V_18 &= ~ V_53 ;
V_18 |= V_54 ;
F_9 ( V_2 , V_33 , V_18 ) ;
}
}
static void F_13 (
T_1 V_55
)
{
unsigned char V_56 ;
V_56 = F_2 ( V_2 , V_57 ) & ~ V_58 ;
switch ( V_55 )
{
case V_59 :
V_56 |= V_60 ;
break;
case V_61 :
V_56 &= ~ V_62 ;
V_56 |= V_63 ;
V_56 |= V_64 ;
break;
case V_65 :
V_56 |= V_66 ;
break;
case V_67 :
V_56 |= V_68 ;
break;
}
F_9 ( V_2 , V_57 , V_56 ) ;
}
void F_14 (
unsigned char V_69
)
{
unsigned char V_56 ;
V_56 = F_2 ( V_2 , V_57 ) ;
if ( V_69 != 0 )
F_13 ( V_61 ) ;
else
F_13 ( V_59 ) ;
}
unsigned char F_15 ( void )
{
unsigned char V_70 ;
V_70 = F_2 ( V_2 , V_57 ) & V_71 ;
if ( V_70 == V_72 )
return 1 ;
else
return 0 ;
}
unsigned char F_16 ( void )
{
unsigned char V_56 ;
V_56 = F_2 ( V_2 , V_57 ) & V_73 ;
if ( V_56 == V_74 )
return 1 ;
else
return 0 ;
}
void F_17 ( void )
{
unsigned char V_56 ;
V_56 = F_2 ( V_2 , V_57 ) ;
F_9 ( V_2 , V_57 , V_56 | V_75 ) ;
}
