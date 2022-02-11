unsigned short F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
unsigned short V_4 = - 1 ;
volatile T_1 * V_5 ;
F_2 ( & V_6 ) ;
if ( F_3 () && V_3 == V_7 )
V_5 = V_2 -> V_8 ? & V_9 : & V_10 ;
else
V_5 = V_2 -> V_8 ? & V_11 : & V_12 ;
V_5 += ( V_3 >> 1 ) ;
V_13 = V_14 | V_15 ;
V_16 = 0 ;
V_4 = * V_5 ;
if ( V_3 == V_7 )
goto V_17;
if ( F_4 ( V_18 , ( V_13 | V_16 ) & V_15 , 1 ) <= 0 &&
! ( ( V_13 | V_16 ) & V_15 ) ) {
F_5 ( V_19 L_1 ,
V_20 , V_3 , V_13 | V_16 ) ;
V_4 = - 1 ;
goto V_17;
}
V_13 = V_14 | V_15 ;
V_16 = 0 ;
V_4 = * V_5 ;
F_4 ( V_18 , ( V_13 | V_16 ) & V_15 , 1 ) ;
V_17: F_6 ( & V_6 ) ;
return V_4 ;
}
void F_7 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_4 )
{
volatile T_1 * V_5 ;
F_2 ( & V_6 ) ;
if ( F_3 () && V_3 == V_7 )
V_5 = V_2 -> V_8 ? & V_9 : & V_10 ;
else
V_5 = V_2 -> V_8 ? & V_11 : & V_12 ;
V_5 += ( V_3 >> 1 ) ;
V_13 = V_14 | V_15 ;
V_16 = 0 ;
* V_5 = V_4 ;
if ( F_4 ( V_18 , ( V_13 | V_16 ) & V_14 , 1 ) <= 0 &&
! ( ( V_13 | V_16 ) & V_14 ) )
F_5 ( V_19 L_2 ,
V_20 , V_3 , V_13 | V_16 ) ;
F_6 ( & V_6 ) ;
}
static inline void F_8 ( void )
{
V_16 = 0 ;
V_21 |= V_22 ;
}
static inline void F_9 ( void )
{
V_21 &= V_23 ;
V_21 &= ~ V_23 ;
V_16 = 0 ;
V_21 = V_23 ;
}
static inline void F_10 ( void )
{
V_16 = 0 ;
F_11 ( V_24 , true ) ;
F_12 ( 10 ) ;
V_21 |= V_22 ;
F_11 ( V_24 , false ) ;
F_12 ( 500 ) ;
}
static inline void F_13 ( void )
{
V_21 &= V_23 ;
V_21 &= ~ V_23 ;
V_16 = 0 ;
F_14 ( V_25 ) ;
F_12 ( 5 ) ;
F_15 ( V_25 ) ;
V_21 = V_23 | V_22 ;
}
static inline void F_16 ( void )
{
V_16 = 0 ;
V_21 |= V_22 ;
}
static inline void F_17 ( void )
{
V_21 = 0 ;
V_21 = V_26 ;
F_12 ( 100 ) ;
V_21 = 0 ;
V_21 &= V_23 ;
V_21 &= ~ V_23 ;
V_16 = 0 ;
V_21 &= ~ ( V_27 | V_28 ) ;
V_21 = V_22 | V_23 ;
}
bool F_18 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
unsigned int V_30 = 100 ;
#ifdef F_19
if ( F_3 () )
F_8 () ;
else
#endif
#ifdef F_20
if ( F_21 () )
F_10 () ;
else
#endif
#ifdef F_22
if ( F_23 () )
F_16 () ;
else
#endif
F_24 () ;
while ( ! ( ( V_13 | V_16 ) & ( V_31 | V_32 ) ) && V_30 -- )
F_25 ( 1 ) ;
V_29 = V_13 | V_16 ;
if ( ! ( V_29 & ( V_31 | V_32 ) ) ) {
F_5 ( V_33 L_3 ,
V_20 , V_29 ) ;
return false ;
}
return true ;
}
bool F_26 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
unsigned int V_30 = 1000 ;
#ifdef F_19
if ( F_3 () )
F_9 () ;
else
#endif
#ifdef F_20
if ( F_21 () )
F_13 () ;
else
#endif
#ifdef F_22
if ( F_23 () )
F_17 () ;
else
#endif
F_24 () ;
while ( ! ( ( V_13 | V_16 ) & ( V_31 | V_32 ) ) && V_30 -- )
F_25 ( 1 ) ;
V_29 = V_13 | V_16 ;
if ( ! ( V_29 & ( V_31 | V_32 ) ) ) {
F_5 ( V_33 L_4 ,
V_20 , V_29 ) ;
return false ;
}
return true ;
}
void F_27 ( struct V_1 * V_2 )
{
V_21 &= ~ ( V_27 | V_28 ) ;
V_21 |= V_34 | V_35 ;
}
static T_2 F_28 ( int V_36 , void * V_37 )
{
long V_38 ;
V_38 = V_13 ;
if ( V_38 ) {
V_13 = V_38 ;
V_16 |= V_38 ;
F_29 ( & V_18 ) ;
if ( F_21 () ) {
V_39 = V_40 ;
V_41 = V_42 ;
V_43 = V_44 ;
}
return V_45 ;
}
return V_46 ;
}
int F_30 ( void )
{
V_21 |= V_47 ;
F_15 ( V_48 ) ;
return 0 ;
}
int F_31 ( void )
{
F_14 ( V_48 ) ;
return 0 ;
}
int F_32 ( struct V_49 * V_50 )
{
int V_51 ;
T_3 * V_52 = V_50 -> V_50 . V_53 ;
if ( V_52 ) {
switch ( V_52 -> V_24 ) {
case 95 :
case 113 :
V_24 = V_52 -> V_24 ;
break;
case 0 :
V_24 = 113 ;
break;
case - 1 :
break;
default:
F_33 ( & V_50 -> V_50 , L_5 ,
V_52 -> V_24 ) ;
}
} else {
if ( F_21 () )
V_24 = 113 ;
}
if ( F_21 () ) {
V_51 = F_34 ( V_24 , V_54 ,
L_6 ) ;
if ( V_51 < 0 ) {
F_35 ( L_7 ,
V_20 , V_51 ) ;
goto V_55;
}
F_11 ( V_24 , false ) ;
V_25 = F_36 ( & V_50 -> V_50 , L_8 ) ;
if ( F_37 ( V_25 ) ) {
V_51 = F_38 ( V_25 ) ;
V_25 = NULL ;
goto V_55;
}
}
V_48 = F_36 ( & V_50 -> V_50 , L_9 ) ;
if ( F_37 ( V_48 ) ) {
V_51 = F_38 ( V_48 ) ;
V_48 = NULL ;
goto V_56;
}
V_51 = F_14 ( V_48 ) ;
if ( V_51 )
goto V_57;
V_51 = F_39 ( V_58 , F_28 , 0 , L_10 , NULL ) ;
if ( V_51 < 0 )
goto V_59;
return 0 ;
V_59:
V_21 |= V_47 ;
V_57:
F_40 ( V_48 ) ;
V_48 = NULL ;
V_56:
if ( V_25 ) {
F_40 ( V_25 ) ;
V_25 = NULL ;
}
V_55:
return V_51 ;
}
void F_41 ( struct V_49 * V_50 )
{
if ( F_21 () )
F_42 ( V_24 ) ;
V_21 |= V_47 ;
F_43 ( V_58 , NULL ) ;
if ( V_25 ) {
F_40 ( V_25 ) ;
V_25 = NULL ;
}
F_15 ( V_48 ) ;
F_40 ( V_48 ) ;
V_48 = NULL ;
}
