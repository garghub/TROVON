void F_1 ( void )
{
V_1 -> V_2 ++ ;
F_2 () ;
}
void F_3 ( void )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_2 != 1 ) {
-- V_4 -> V_2 ;
} else {
F_2 () ;
V_4 -> V_2 = V_5 ;
#ifdef F_4
F_5 ( 10 ) ;
#endif
F_2 () ;
if ( F_6 ( F_7 ( V_4 -> V_6 ) ) )
V_6 ( V_4 ) ;
F_2 () ;
V_4 -> V_2 = 0 ;
}
#ifdef F_8
{
int V_7 = F_7 ( V_4 -> V_2 ) ;
F_9 ( V_7 < 0 && V_7 > V_5 / 2 ) ;
}
#endif
}
int F_10 ( void )
{
return V_8 && V_9 &&
V_1 -> V_10 == 0 ;
}
int F_11 ( void )
{
if ( ! F_10 () )
return 1 ;
if ( F_12 () )
return 0 ;
if ( ! F_13 () )
return 0 ;
return F_14 () || F_15 () ;
}
static void F_16 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_17 ( V_12 , struct V_13 , V_12 ) ;
F_18 ( & V_14 -> V_15 ) ;
}
void F_19 ( T_1 V_16 )
{
struct V_13 V_14 ;
F_20 ( & V_14 . V_12 ) ;
F_21 ( & V_14 . V_15 ) ;
V_16 ( & V_14 . V_12 , F_16 ) ;
F_22 ( & V_14 . V_15 ) ;
F_23 ( & V_14 . V_12 ) ;
}
int F_24 ( void )
{
return F_25 ( V_1 ) ;
}
static inline void F_26 ( struct V_11 * V_12 )
{
F_27 ( V_12 , & V_17 ) ;
}
static inline void F_28 ( struct V_11 * V_12 )
{
F_29 ( V_12 , & V_17 ) ;
}
static int F_30 ( void * V_18 , enum V_19 V_20 )
{
struct V_11 * V_12 = V_18 ;
switch ( V_20 ) {
case V_21 :
#ifndef F_31
F_9 ( 1 ) ;
return 0 ;
#endif
if ( F_32 () != 0 || F_33 () != 0 ||
F_15 () ) {
F_9 ( 1 ) ;
return 0 ;
}
F_34 () ;
F_35 () ;
F_36 () ;
F_27 ( V_12 , & V_17 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_37 ( void * V_18 , enum V_19 V_20 )
{
struct V_11 * V_12 = V_18 ;
switch ( V_20 ) {
case V_22 :
F_27 ( V_12 , & V_17 ) ;
F_38 ( V_12 , & V_17 ) ;
return 0 ;
case V_21 :
#ifndef F_31
F_9 ( 1 ) ;
return 0 ;
#endif
if ( F_32 () != 0 || F_33 () != 0 ||
F_15 () ) {
F_9 ( 1 ) ;
return 0 ;
}
F_34 () ;
F_35 () ;
F_36 () ;
F_38 ( V_12 , & V_17 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_39 ( void * V_18 , enum V_19 V_20 )
{
struct V_11 * V_12 = V_18 ;
switch ( V_20 ) {
case V_21 :
#ifndef F_31
F_9 ( 1 ) ;
return 0 ;
#endif
if ( F_32 () != 0 || F_33 () != 0 ||
F_15 () ) {
F_9 ( 1 ) ;
return 0 ;
}
F_34 () ;
F_35 () ;
F_36 () ;
F_29 ( V_12 , & V_17 ) ;
return 1 ;
default:
return 0 ;
}
}
void F_20 ( struct V_11 * V_12 )
{
F_40 ( V_12 , & V_17 ) ;
}
void F_23 ( struct V_11 * V_12 )
{
F_29 ( V_12 , & V_17 ) ;
}
void F_41 ( char * V_23 , struct V_11 * V_24 ,
unsigned long V_25 ,
unsigned long V_26 , unsigned long V_27 )
{
F_42 ( V_23 , V_24 , V_25 , V_26 , V_27 ) ;
}
int F_43 ( void )
{
int V_28 = F_7 ( V_29 ) ;
if ( V_28 < 3 ) {
F_7 ( V_29 ) = 3 ;
V_28 = 3 ;
} else if ( V_28 > 300 ) {
F_7 ( V_29 ) = 300 ;
V_28 = 300 ;
}
return V_28 * V_30 + V_31 ;
}
static int F_44 ( struct V_32 * V_33 , unsigned long V_34 , void * V_35 )
{
V_36 = 1 ;
return V_37 ;
}
static int T_2 F_45 ( void )
{
F_46 ( & V_38 , & V_39 ) ;
return 0 ;
}
