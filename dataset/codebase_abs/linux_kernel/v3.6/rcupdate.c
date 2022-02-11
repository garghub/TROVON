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
F_2 () ;
if ( F_4 ( F_5 ( V_4 -> V_6 ) ) )
V_6 ( V_4 ) ;
F_2 () ;
V_4 -> V_2 = 0 ;
}
#ifdef F_6
{
int V_7 = F_5 ( V_4 -> V_2 ) ;
F_7 ( V_7 < 0 && V_7 > V_5 / 2 ) ;
}
#endif
}
void F_8 ( void )
{
struct V_3 * V_4 = V_1 ;
if ( F_9 ( F_10 ( & V_1 -> V_8 ) ) )
return;
V_4 -> V_2 = 1 ;
F_2 () ;
V_4 -> V_6 = V_9 ;
F_3 () ;
}
void F_8 ( void )
{
}
int F_11 ( void )
{
return V_10 && V_11 &&
V_1 -> V_12 == 0 ;
}
int F_12 ( void )
{
if ( ! F_11 () )
return 1 ;
if ( F_13 () )
return 0 ;
if ( ! F_14 () )
return 0 ;
return F_15 () || F_16 () ;
}
static void F_17 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
V_16 = F_18 ( V_14 , struct V_15 , V_14 ) ;
F_19 ( & V_16 -> V_17 ) ;
}
void F_20 ( T_1 V_18 )
{
struct V_15 V_16 ;
F_21 ( & V_16 . V_14 ) ;
F_22 ( & V_16 . V_17 ) ;
V_18 ( & V_16 . V_14 , F_17 ) ;
F_23 ( & V_16 . V_17 ) ;
F_24 ( & V_16 . V_14 ) ;
}
int F_25 ( void )
{
return F_26 ( V_1 ) ;
}
static inline void F_27 ( struct V_13 * V_14 )
{
F_28 ( V_14 , & V_19 ) ;
}
static inline void F_29 ( struct V_13 * V_14 )
{
F_30 ( V_14 , & V_19 ) ;
}
static int F_31 ( void * V_20 , enum V_21 V_22 )
{
struct V_13 * V_14 = V_20 ;
switch ( V_22 ) {
case V_23 :
#ifndef F_32
F_7 ( 1 ) ;
return 0 ;
#endif
if ( F_33 () != 0 || F_34 () != 0 ||
F_16 () ) {
F_7 ( 1 ) ;
return 0 ;
}
F_35 () ;
F_36 () ;
F_37 () ;
F_28 ( V_14 , & V_19 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_38 ( void * V_20 , enum V_21 V_22 )
{
struct V_13 * V_14 = V_20 ;
switch ( V_22 ) {
case V_24 :
F_28 ( V_14 , & V_19 ) ;
F_39 ( V_14 , & V_19 ) ;
return 0 ;
case V_23 :
#ifndef F_32
F_7 ( 1 ) ;
return 0 ;
#endif
if ( F_33 () != 0 || F_34 () != 0 ||
F_16 () ) {
F_7 ( 1 ) ;
return 0 ;
}
F_35 () ;
F_36 () ;
F_37 () ;
F_39 ( V_14 , & V_19 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_40 ( void * V_20 , enum V_21 V_22 )
{
struct V_13 * V_14 = V_20 ;
switch ( V_22 ) {
case V_23 :
#ifndef F_32
F_7 ( 1 ) ;
return 0 ;
#endif
if ( F_33 () != 0 || F_34 () != 0 ||
F_16 () ) {
F_7 ( 1 ) ;
return 0 ;
}
F_35 () ;
F_36 () ;
F_37 () ;
F_30 ( V_14 , & V_19 ) ;
return 1 ;
default:
return 0 ;
}
}
void F_21 ( struct V_13 * V_14 )
{
F_41 ( V_14 , & V_19 ) ;
}
void F_24 ( struct V_13 * V_14 )
{
F_30 ( V_14 , & V_19 ) ;
}
void F_42 ( char * V_25 , struct V_13 * V_26 )
{
F_43 ( V_25 , V_26 ) ;
}
