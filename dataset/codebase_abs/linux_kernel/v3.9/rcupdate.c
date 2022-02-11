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
void F_10 ( void )
{
struct V_3 * V_4 = V_1 ;
if ( F_11 ( F_12 ( & V_1 -> V_8 ) ) )
return;
V_4 -> V_2 = 1 ;
F_2 () ;
V_4 -> V_6 = V_9 ;
F_3 () ;
}
void F_10 ( void )
{
}
int F_13 ( void )
{
return V_10 && V_11 &&
V_1 -> V_12 == 0 ;
}
int F_14 ( void )
{
if ( ! F_13 () )
return 1 ;
if ( F_15 () )
return 0 ;
if ( ! F_16 () )
return 0 ;
return F_17 () || F_18 () ;
}
static void F_19 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
V_16 = F_20 ( V_14 , struct V_15 , V_14 ) ;
F_21 ( & V_16 -> V_17 ) ;
}
void F_22 ( T_1 V_18 )
{
struct V_15 V_16 ;
F_23 ( & V_16 . V_14 ) ;
F_24 ( & V_16 . V_17 ) ;
V_18 ( & V_16 . V_14 , F_19 ) ;
F_25 ( & V_16 . V_17 ) ;
F_26 ( & V_16 . V_14 ) ;
}
int F_27 ( void )
{
return F_28 ( V_1 ) ;
}
static inline void F_29 ( struct V_13 * V_14 )
{
F_30 ( V_14 , & V_19 ) ;
}
static inline void F_31 ( struct V_13 * V_14 )
{
F_32 ( V_14 , & V_19 ) ;
}
static int F_33 ( void * V_20 , enum V_21 V_22 )
{
struct V_13 * V_14 = V_20 ;
switch ( V_22 ) {
case V_23 :
#ifndef F_34
F_9 ( 1 ) ;
return 0 ;
#endif
if ( F_35 () != 0 || F_36 () != 0 ||
F_18 () ) {
F_9 ( 1 ) ;
return 0 ;
}
F_37 () ;
F_38 () ;
F_39 () ;
F_30 ( V_14 , & V_19 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_40 ( void * V_20 , enum V_21 V_22 )
{
struct V_13 * V_14 = V_20 ;
switch ( V_22 ) {
case V_24 :
F_30 ( V_14 , & V_19 ) ;
F_41 ( V_14 , & V_19 ) ;
return 0 ;
case V_23 :
#ifndef F_34
F_9 ( 1 ) ;
return 0 ;
#endif
if ( F_35 () != 0 || F_36 () != 0 ||
F_18 () ) {
F_9 ( 1 ) ;
return 0 ;
}
F_37 () ;
F_38 () ;
F_39 () ;
F_41 ( V_14 , & V_19 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_42 ( void * V_20 , enum V_21 V_22 )
{
struct V_13 * V_14 = V_20 ;
switch ( V_22 ) {
case V_23 :
#ifndef F_34
F_9 ( 1 ) ;
return 0 ;
#endif
if ( F_35 () != 0 || F_36 () != 0 ||
F_18 () ) {
F_9 ( 1 ) ;
return 0 ;
}
F_37 () ;
F_38 () ;
F_39 () ;
F_32 ( V_14 , & V_19 ) ;
return 1 ;
default:
return 0 ;
}
}
void F_23 ( struct V_13 * V_14 )
{
F_43 ( V_14 , & V_19 ) ;
}
void F_26 ( struct V_13 * V_14 )
{
F_32 ( V_14 , & V_19 ) ;
}
void F_44 ( char * V_25 , struct V_13 * V_26 ,
unsigned long V_27 ,
unsigned long V_28 , unsigned long V_29 )
{
F_45 ( V_25 , V_26 , V_27 , V_28 , V_29 ) ;
}
int F_46 ( void )
{
int V_30 = F_7 ( V_31 ) ;
if ( V_30 < 3 ) {
F_7 ( V_31 ) = 3 ;
V_30 = 3 ;
} else if ( V_30 > 300 ) {
F_7 ( V_31 ) = 300 ;
V_30 = 300 ;
}
return V_30 * V_32 + V_33 ;
}
static int F_47 ( struct V_34 * V_35 , unsigned long V_36 , void * V_37 )
{
V_38 = 1 ;
return V_39 ;
}
static int T_2 F_48 ( void )
{
F_49 ( & V_40 , & V_41 ) ;
return 0 ;
}
