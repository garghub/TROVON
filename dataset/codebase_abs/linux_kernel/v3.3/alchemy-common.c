static inline void F_1 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 , V_4 ;
V_3 = F_2 ( V_1 + V_5 ) ;
V_4 = F_2 ( V_1 + V_6 ) ;
V_4 &= V_7 | V_8 |
V_9 | V_10 ;
if ( V_2 ) {
V_3 |= V_11 | V_12 |
V_13 ;
F_3 ( V_3 , V_1 + V_5 ) ;
F_4 () ;
} else if ( ! V_4 ) {
V_3 &= ~ ( V_11 | V_12 |
V_13 ) ;
F_3 ( V_3 , V_1 + V_5 ) ;
F_4 () ;
}
}
static inline void F_5 ( void T_1 * V_1 , int V_2 , int V_14 )
{
unsigned long V_3 ;
if ( V_2 ) {
F_3 ( 1 , V_1 + V_15 ) ;
F_4 () ;
V_3 = F_2 ( V_1 + V_6 ) ;
V_3 |= ( V_14 == 0 ) ? V_8
: V_7 ;
F_3 ( V_3 , V_1 + V_6 ) ;
F_4 () ;
F_1 ( V_1 , V_2 ) ;
V_3 = F_2 ( V_1 + V_16 ) ;
V_3 |= ( V_14 == 0 ) ? V_17 : V_18 ;
F_3 ( V_3 , V_1 + V_16 ) ;
F_4 () ;
F_3 ( 0 , V_1 + V_15 ) ;
F_4 () ;
} else {
V_3 = F_2 ( V_1 + V_16 ) ;
V_3 &= ~ ( ( V_14 == 0 ) ? V_17 : V_18 ) ;
F_3 ( V_3 , V_1 + V_16 ) ;
F_4 () ;
V_3 = F_2 ( V_1 + V_6 ) ;
V_3 &= ~ ( ( V_14 == 0 ) ? V_8
: V_7 ) ;
F_3 ( V_3 , V_1 + V_6 ) ;
F_4 () ;
F_1 ( V_1 , V_2 ) ;
}
}
static inline void F_6 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 ;
if ( V_2 ) {
V_3 = F_2 ( V_1 + V_6 ) ;
V_3 |= V_9 ;
F_3 ( V_3 , V_1 + V_6 ) ;
F_4 () ;
V_3 = F_2 ( V_1 + V_19 ) ;
V_3 |= V_20 ;
F_3 ( V_3 , V_1 + V_19 ) ;
F_4 () ;
F_1 ( V_1 , V_2 ) ;
V_3 = F_2 ( V_1 + V_16 ) ;
V_3 |= V_21 ;
F_3 ( V_3 , V_1 + V_16 ) ;
F_4 () ;
} else {
V_3 = F_2 ( V_1 + V_16 ) ;
V_3 &= ~ V_21 ;
F_3 ( V_3 , V_1 + V_16 ) ;
F_4 () ;
V_3 = F_2 ( V_1 + V_19 ) ;
V_3 &= ~ V_20 ;
F_3 ( V_3 , V_1 + V_19 ) ;
F_4 () ;
V_3 = F_2 ( V_1 + V_6 ) ;
V_3 &= ~ V_9 ;
F_3 ( V_3 , V_1 + V_6 ) ;
F_4 () ;
F_1 ( V_1 , V_2 ) ;
}
}
static inline void F_7 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 ;
if ( V_2 ) {
V_3 = F_2 ( V_1 + V_19 ) ;
V_3 |= V_22 ;
F_3 ( V_3 , V_1 + V_19 ) ;
F_4 () ;
F_1 ( V_1 , V_2 ) ;
V_3 = F_2 ( V_1 + V_16 ) ;
V_3 |= V_23 ;
F_3 ( V_3 , V_1 + V_16 ) ;
F_4 () ;
} else {
V_3 = F_2 ( V_1 + V_16 ) ;
V_3 &= ~ V_23 ;
F_3 ( V_3 , V_1 + V_16 ) ;
F_4 () ;
V_3 = F_2 ( V_1 + V_19 ) ;
V_3 &= ~ V_22 ;
F_3 ( V_3 , V_1 + V_19 ) ;
F_4 () ;
F_1 ( V_1 , V_2 ) ;
}
}
static inline void F_8 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 ;
if ( V_2 ) {
V_3 = F_2 ( V_1 + V_6 ) ;
V_3 |= V_10 ;
F_3 ( V_3 , V_1 + V_6 ) ;
F_4 () ;
V_3 = F_2 ( V_1 + V_19 ) ;
V_3 &= ~ V_24 ;
F_3 ( V_3 , V_1 + V_19 ) ;
F_4 () ;
F_1 ( V_1 , V_2 ) ;
} else {
V_3 = F_2 ( V_1 + V_19 ) ;
V_3 |= V_24 ;
F_3 ( V_3 , V_1 + V_19 ) ;
F_4 () ;
V_3 = F_2 ( V_1 + V_6 ) ;
V_3 &= ~ V_10 ;
F_3 ( V_3 , V_1 + V_6 ) ;
F_4 () ;
F_1 ( V_1 , V_2 ) ;
}
}
static inline int F_9 ( int V_25 , int V_2 )
{
void T_1 * V_1 =
( void T_1 * ) F_10 ( V_26 ) ;
int V_27 = 0 ;
switch ( V_25 ) {
case V_28 :
F_5 ( V_1 , V_2 , 0 ) ;
break;
case V_29 :
F_5 ( V_1 , V_2 , 1 ) ;
break;
case V_30 :
F_6 ( V_1 , V_2 ) ;
break;
case V_31 :
F_7 ( V_1 , V_2 ) ;
break;
case V_32 :
F_8 ( V_1 , V_2 ) ;
break;
default:
V_27 = - V_33 ;
}
return V_27 ;
}
static inline void F_11 ( void )
{
void T_1 * V_1 =
( void T_1 * ) F_10 ( V_26 ) ;
F_3 ( 0 , V_1 + V_16 ) ;
F_4 () ;
F_3 ( 0 , V_1 + V_6 ) ;
F_4 () ;
F_3 ( ~ 0 , V_1 + V_34 ) ;
F_4 () ;
F_3 ( ~ 0 , V_1 + V_35 ) ;
F_4 () ;
F_3 ( V_36 , V_1 + V_37 ) ;
F_4 () ;
}
static inline void F_12 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 = F_2 ( V_1 + V_38 ) ;
if ( V_2 ) {
F_3 ( V_3 | V_39 , V_1 + V_38 ) ;
F_4 () ;
F_13 ( 2000 ) ;
} else {
F_3 ( V_3 & ~ V_39 , V_1 + V_38 ) ;
F_4 () ;
F_13 ( 1000 ) ;
}
}
static inline void F_14 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 = F_2 ( V_1 + V_38 ) ;
if ( V_2 ) {
F_3 ( V_3 | V_40 | V_41 , V_1 + V_38 ) ;
F_4 () ;
F_13 ( 1000 ) ;
} else {
if ( ! ( V_3 & V_42 ) )
V_3 &= ~ V_41 ;
F_3 ( V_3 & ~ V_40 , V_1 + V_38 ) ;
F_4 () ;
F_13 ( 1000 ) ;
}
}
static inline void F_15 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 = F_2 ( V_1 + V_38 ) ;
if ( V_2 ) {
F_3 ( V_3 | V_42 | V_41 , V_1 + V_38 ) ;
F_4 () ;
} else {
if ( ! ( V_3 & V_40 ) )
V_3 &= ~ V_41 ;
F_3 ( V_3 & ~ V_42 , V_1 + V_38 ) ;
F_4 () ;
}
}
static inline int F_16 ( void )
{
#if F_17 ( V_43 )
if ( ! ( F_18 () & 0xff ) ) {
F_19 ( V_44 L_1 ) ;
F_19 ( V_44 L_2
L_3 ) ;
return - V_33 ;
}
#endif
return 0 ;
}
static inline int F_20 ( int V_25 , int V_2 )
{
void T_1 * V_1 =
( void T_1 * ) F_10 ( V_45 ) ;
int V_27 = 0 ;
switch ( V_25 ) {
case V_28 :
V_27 = F_16 () ;
if ( V_27 && V_2 )
goto V_46;
F_12 ( V_1 , V_2 ) ;
break;
case V_31 :
F_15 ( V_1 , V_2 ) ;
break;
case V_30 :
V_27 = F_16 () ;
if ( V_27 && V_2 )
goto V_46;
F_14 ( V_1 , V_2 ) ;
break;
default:
V_27 = - V_33 ;
}
V_46:
return V_27 ;
}
static inline void F_21 ( void )
{
void T_1 * V_1 =
( void T_1 * ) F_10 ( V_45 ) ;
F_3 ( V_47 , V_1 + V_38 ) ;
F_4 () ;
F_13 ( 1000 ) ;
}
static inline void F_22 ( unsigned long V_48 , int V_49 )
{
void T_1 * V_1 = ( void T_1 * ) F_10 ( V_48 + V_49 ) ;
unsigned long V_3 = F_2 ( V_1 ) ;
#if F_17 ( V_50 )
V_3 |= V_51 ;
#endif
V_3 |= V_52 ;
F_3 ( V_3 , V_1 ) ;
F_4 () ;
F_13 ( 1000 ) ;
}
static inline void F_23 ( int V_2 , unsigned long V_48 , int V_53 )
{
void T_1 * V_1 = ( void T_1 * ) F_10 ( V_48 ) ;
unsigned long V_3 = F_2 ( V_1 + V_53 ) ;
if ( V_2 ) {
F_3 ( V_3 | V_54 , V_1 + V_53 ) ;
F_4 () ;
F_13 ( 1000 ) ;
F_3 ( V_3 | V_54 | V_55 , V_1 + V_53 ) ;
F_4 () ;
F_13 ( 1000 ) ;
while ( F_2 ( V_1 + V_53 ) ,
! ( F_2 ( V_1 + V_53 ) & V_56 ) )
F_13 ( 1000 ) ;
} else {
F_3 ( V_3 & ~ ( V_54 | V_55 ) , V_1 + V_53 ) ;
F_4 () ;
}
}
static inline int F_24 ( int V_25 , int V_2 , unsigned long V_48 ,
int V_53 )
{
int V_27 = 0 ;
switch ( V_25 ) {
case V_28 :
F_23 ( V_2 , V_48 , V_53 ) ;
break;
default:
V_27 = - V_33 ;
}
return V_27 ;
}
int F_25 ( int V_25 , int V_2 )
{
unsigned long V_57 ;
int V_27 ;
F_26 ( & V_58 , V_57 ) ;
switch ( F_27 () ) {
case V_59 :
case V_60 :
case V_61 :
V_27 = F_24 ( V_25 , V_2 ,
V_62 , V_63 ) ;
break;
case V_64 :
V_27 = F_24 ( V_25 , V_2 ,
V_65 , V_66 ) ;
break;
case V_67 :
V_27 = F_20 ( V_25 , V_2 ) ;
break;
case V_68 :
V_27 = F_9 ( V_25 , V_2 ) ;
break;
default:
V_27 = - V_33 ;
}
F_28 ( & V_58 , V_57 ) ;
return V_27 ;
}
static void F_29 ( unsigned long V_69 , int V_53 , int V_70 )
{
void T_1 * V_1 = ( void T_1 * ) F_10 ( V_69 ) ;
if ( V_70 ) {
V_71 [ 0 ] = F_2 ( V_1 + V_53 ) ;
F_3 ( 0 , V_1 + 0x04 ) ;
F_4 () ;
F_3 ( 0 , V_1 + V_53 ) ;
F_4 () ;
} else {
F_3 ( V_71 [ 0 ] , V_1 + V_53 ) ;
F_4 () ;
}
}
static void F_30 ( int V_70 )
{
void T_1 * V_1 =
( void T_1 * ) F_10 ( V_72 ) ;
if ( V_70 ) {
V_71 [ 0 ] = F_2 ( V_1 + 0x00 ) ;
V_71 [ 1 ] = F_2 ( V_1 + 0x04 ) ;
} else {
F_21 () ;
F_3 ( V_71 [ 0 ] , V_1 + 0x00 ) ;
F_3 ( V_71 [ 1 ] , V_1 + 0x04 ) ;
F_4 () ;
}
}
static void F_31 ( int V_70 )
{
void T_1 * V_1 =
( void T_1 * ) F_10 ( V_26 ) ;
if ( V_70 ) {
V_71 [ 0 ] = F_2 ( V_1 + V_73 ) ;
} else {
F_11 () ;
F_3 ( V_71 [ 0 ] , V_1 + V_73 ) ;
F_4 () ;
}
}
static void F_32 ( int V_70 )
{
switch ( F_27 () ) {
case V_59 :
case V_60 :
case V_61 :
F_29 ( V_62 , V_63 , V_70 ) ;
break;
case V_64 :
F_29 ( V_65 , V_66 , V_70 ) ;
break;
case V_67 :
F_30 ( V_70 ) ;
break;
case V_68 :
F_31 ( V_70 ) ;
break;
}
}
static int F_33 ( void )
{
F_32 ( 1 ) ;
return 0 ;
}
static void F_34 ( void )
{
F_32 ( 0 ) ;
}
static int T_2 F_35 ( void )
{
switch ( F_27 () ) {
case V_59 :
case V_60 :
case V_61 :
F_22 ( V_62 , V_63 ) ;
break;
case V_64 :
F_22 ( V_65 , V_66 ) ;
break;
case V_67 :
F_21 () ;
break;
case V_68 :
F_11 () ;
break;
}
F_36 ( & V_74 ) ;
return 0 ;
}
