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
V_21 |= V_22 | V_23 | V_24 ;
F_4 ( V_18 , V_16 & ( V_25 | V_26 ) , 1 ) ;
}
static inline void F_9 ( void )
{
V_21 &= V_27 ;
V_21 &= ~ V_27 ;
V_16 = 0 ;
V_21 = V_27 ;
V_21 |= V_28 | V_29 ;
F_4 ( V_18 , V_16 & ( V_25 | V_26 ) , 1 ) ;
}
static inline void F_10 ( void )
{
V_16 = 0 ;
F_11 ( V_30 , 1 ) ;
F_12 ( 10 ) ;
V_21 |= V_22 ;
F_11 ( V_30 , 0 ) ;
F_12 ( 500 ) ;
}
static inline void F_13 ( void )
{
V_21 &= V_27 ;
V_21 &= ~ V_27 ;
V_16 = 0 ;
F_14 ( V_31 ) ;
F_12 ( 5 ) ;
F_15 ( V_31 ) ;
V_21 = V_27 ;
F_12 ( 50 ) ;
}
static inline void F_16 ( void )
{
int V_32 = 100 ;
V_16 = 0 ;
V_21 |= V_22 ;
while ( ! ( ( V_13 | V_16 ) & ( V_25 | V_26 ) ) && V_32 -- )
F_17 ( 1 ) ;
}
static inline void F_18 ( void )
{
int V_32 = 1000 ;
V_21 = 0 ;
V_21 = V_33 ;
F_12 ( 100 ) ;
V_21 = 0 ;
V_21 &= V_27 ;
V_21 &= ~ V_27 ;
V_16 = 0 ;
V_21 &= ~ ( V_23 | V_24 ) ;
V_21 = V_22 | V_27 ;
while ( ! ( V_13 & ( V_25 | V_26 ) ) && V_32 -- )
F_17 ( 10 ) ;
}
bool F_19 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
#ifdef F_20
if ( F_3 () )
F_8 () ;
else
#endif
#ifdef F_21
if ( F_22 () )
F_10 () ;
else
#endif
#ifdef F_23
if ( F_24 () )
F_16 () ;
else
#endif
F_25 () ;
V_34 = V_13 | V_16 ;
if ( ! ( V_34 & ( V_25 | V_26 ) ) ) {
F_5 ( V_35 L_3 ,
V_20 , V_34 ) ;
return false ;
}
return true ;
}
bool F_26 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
#ifdef F_20
if ( F_3 () )
F_9 () ;
else
#endif
#ifdef F_21
if ( F_22 () )
F_13 () ;
else
#endif
#ifdef F_23
if ( F_24 () )
F_18 () ;
else
#endif
F_25 () ;
V_34 = V_13 | V_16 ;
if ( ! ( V_34 & ( V_25 | V_26 ) ) ) {
F_5 ( V_35 L_4 ,
V_20 , V_34 ) ;
return false ;
}
return true ;
}
void F_27 ( struct V_1 * V_2 )
{
V_21 &= ~ ( V_23 | V_24 ) ;
V_21 |= V_29 | V_28 ;
}
static T_2 F_28 ( int V_36 , void * V_37 )
{
long V_38 ;
V_38 = V_13 ;
if ( V_38 ) {
V_13 = V_38 ;
V_16 |= V_38 ;
F_29 ( & V_18 ) ;
if ( F_22 () ) {
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
int T_3 F_32 ( struct V_49 * V_50 )
{
int V_51 ;
T_4 * V_52 = V_50 -> V_50 . V_53 ;
if ( V_52 ) {
switch ( V_52 -> V_30 ) {
case 95 :
case 113 :
V_30 = V_52 -> V_30 ;
break;
case 0 :
V_30 = 113 ;
break;
case - 1 :
break;
default:
F_33 ( & V_50 -> V_50 , L_5 ,
V_52 -> V_30 ) ;
}
} else {
if ( F_22 () )
V_30 = 113 ;
}
if ( F_22 () ) {
F_11 ( V_30 , 0 ) ;
V_31 = F_34 ( & V_50 -> V_50 , L_6 ) ;
if ( F_35 ( V_31 ) ) {
V_51 = F_36 ( V_31 ) ;
V_31 = NULL ;
goto V_54;
}
}
V_48 = F_34 ( & V_50 -> V_50 , L_7 ) ;
if ( F_35 ( V_48 ) ) {
V_51 = F_36 ( V_48 ) ;
V_48 = NULL ;
goto V_55;
}
V_51 = F_14 ( V_48 ) ;
if ( V_51 )
goto V_56;
V_51 = F_37 ( V_57 , F_28 , V_58 , L_8 , NULL ) ;
if ( V_51 < 0 )
goto V_59;
return 0 ;
V_59:
V_21 |= V_47 ;
V_56:
F_38 ( V_48 ) ;
V_48 = NULL ;
V_55:
if ( V_31 ) {
F_38 ( V_31 ) ;
V_31 = NULL ;
}
V_54:
return V_51 ;
}
void F_39 ( struct V_49 * V_50 )
{
V_21 |= V_47 ;
F_40 ( V_57 , NULL ) ;
if ( V_31 ) {
F_38 ( V_31 ) ;
V_31 = NULL ;
}
F_15 ( V_48 ) ;
F_38 ( V_48 ) ;
V_48 = NULL ;
}
