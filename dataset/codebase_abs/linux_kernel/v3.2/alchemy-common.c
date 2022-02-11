static inline void F_1 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_2 ) {
F_3 ( V_3 | V_5 , V_1 + V_4 ) ;
F_4 () ;
F_5 ( 2000 ) ;
} else {
F_3 ( V_3 & ~ V_5 , V_1 + V_4 ) ;
F_4 () ;
F_5 ( 1000 ) ;
}
}
static inline void F_6 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_2 ) {
F_3 ( V_3 | V_6 | V_7 , V_1 + V_4 ) ;
F_4 () ;
F_5 ( 1000 ) ;
} else {
if ( ! ( V_3 & V_8 ) )
V_3 &= ~ V_7 ;
F_3 ( V_3 & ~ V_6 , V_1 + V_4 ) ;
F_4 () ;
F_5 ( 1000 ) ;
}
}
static inline void F_7 ( void T_1 * V_1 , int V_2 )
{
unsigned long V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_2 ) {
F_3 ( V_3 | V_8 | V_7 , V_1 + V_4 ) ;
F_4 () ;
} else {
if ( ! ( V_3 & V_6 ) )
V_3 &= ~ V_7 ;
F_3 ( V_3 & ~ V_8 , V_1 + V_4 ) ;
F_4 () ;
}
}
static inline int F_8 ( void )
{
#if F_9 ( V_9 )
if ( ! ( F_10 () & 0xff ) ) {
F_11 ( V_10 L_1 ) ;
F_11 ( V_10 L_2
L_3 ) ;
return - V_11 ;
}
#endif
return 0 ;
}
static inline int F_12 ( int V_12 , int V_2 )
{
void T_1 * V_1 =
( void T_1 * ) F_13 ( V_13 ) ;
int V_14 = 0 ;
switch ( V_12 ) {
case V_15 :
V_14 = F_8 () ;
if ( V_14 && V_2 )
goto V_16;
F_1 ( V_1 , V_2 ) ;
break;
case V_17 :
F_7 ( V_1 , V_2 ) ;
break;
case V_18 :
V_14 = F_8 () ;
if ( V_14 && V_2 )
goto V_16;
F_6 ( V_1 , V_2 ) ;
break;
default:
V_14 = - V_11 ;
}
V_16:
return V_14 ;
}
static inline void F_14 ( void )
{
void T_1 * V_1 =
( void T_1 * ) F_13 ( V_13 ) ;
F_3 ( V_19 , V_1 + V_4 ) ;
F_4 () ;
F_5 ( 1000 ) ;
}
static inline void F_15 ( unsigned long V_20 , int V_21 )
{
void T_1 * V_1 = ( void T_1 * ) F_13 ( V_20 + V_21 ) ;
unsigned long V_3 = F_2 ( V_1 ) ;
#if F_9 ( V_22 )
V_3 |= V_23 ;
#endif
V_3 |= V_24 ;
F_3 ( V_3 , V_1 ) ;
F_4 () ;
F_5 ( 1000 ) ;
}
static inline void F_16 ( int V_2 , unsigned long V_20 , int V_25 )
{
void T_1 * V_1 = ( void T_1 * ) F_13 ( V_20 ) ;
unsigned long V_3 = F_2 ( V_1 + V_25 ) ;
if ( V_2 ) {
F_3 ( V_3 | V_26 , V_1 + V_25 ) ;
F_4 () ;
F_5 ( 1000 ) ;
F_3 ( V_3 | V_26 | V_27 , V_1 + V_25 ) ;
F_4 () ;
F_5 ( 1000 ) ;
while ( F_2 ( V_1 + V_25 ) ,
! ( F_2 ( V_1 + V_25 ) & V_28 ) )
F_5 ( 1000 ) ;
} else {
F_3 ( V_3 & ~ ( V_26 | V_27 ) , V_1 + V_25 ) ;
F_4 () ;
}
}
static inline int F_17 ( int V_12 , int V_2 , unsigned long V_20 ,
int V_25 )
{
int V_14 = 0 ;
switch ( V_12 ) {
case V_15 :
F_16 ( V_2 , V_20 , V_25 ) ;
break;
default:
V_14 = - V_11 ;
}
return V_14 ;
}
int F_18 ( int V_12 , int V_2 )
{
unsigned long V_29 ;
int V_14 ;
F_19 ( & V_30 , V_29 ) ;
switch ( F_20 () ) {
case V_31 :
case V_32 :
case V_33 :
V_14 = F_17 ( V_12 , V_2 ,
V_34 , V_35 ) ;
break;
case V_36 :
V_14 = F_17 ( V_12 , V_2 ,
V_37 , V_38 ) ;
break;
case V_39 :
V_14 = F_12 ( V_12 , V_2 ) ;
break;
default:
V_14 = - V_11 ;
}
F_21 ( & V_30 , V_29 ) ;
return V_14 ;
}
static void F_22 ( unsigned long V_40 , int V_25 , int V_41 )
{
void T_1 * V_1 = ( void T_1 * ) F_13 ( V_40 ) ;
if ( V_41 ) {
V_42 [ 0 ] = F_2 ( V_1 + V_25 ) ;
F_3 ( 0 , V_1 + 0x04 ) ;
F_4 () ;
F_3 ( 0 , V_1 + V_25 ) ;
F_4 () ;
} else {
F_3 ( V_42 [ 0 ] , V_1 + V_25 ) ;
F_4 () ;
}
}
static void F_23 ( int V_41 )
{
void T_1 * V_1 =
( void T_1 * ) F_13 ( V_43 ) ;
if ( V_41 ) {
V_42 [ 0 ] = F_2 ( V_1 + 0x00 ) ;
V_42 [ 1 ] = F_2 ( V_1 + 0x04 ) ;
} else {
F_14 () ;
F_3 ( V_42 [ 0 ] , V_1 + 0x00 ) ;
F_3 ( V_42 [ 1 ] , V_1 + 0x04 ) ;
F_4 () ;
}
}
static void F_24 ( int V_41 )
{
switch ( F_20 () ) {
case V_31 :
case V_32 :
case V_33 :
F_22 ( V_34 , V_35 , V_41 ) ;
break;
case V_36 :
F_22 ( V_37 , V_38 , V_41 ) ;
break;
case V_39 :
F_23 ( V_41 ) ;
break;
}
}
static int F_25 ( void )
{
F_24 ( 1 ) ;
return 0 ;
}
static void F_26 ( void )
{
F_24 ( 0 ) ;
}
static int T_2 F_27 ( void )
{
switch ( F_20 () ) {
case V_31 :
case V_32 :
case V_33 :
F_15 ( V_34 , V_35 ) ;
break;
case V_36 :
F_15 ( V_37 , V_38 ) ;
break;
case V_39 :
F_14 () ;
break;
}
F_28 ( & V_44 ) ;
return 0 ;
}
