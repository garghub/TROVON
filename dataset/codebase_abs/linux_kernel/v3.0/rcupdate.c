int F_1 ( void )
{
return V_1 && V_2 &&
V_3 -> V_4 == 0 ;
}
int F_2 ( void )
{
if ( ! F_1 () )
return 1 ;
return F_3 () || F_4 () ;
}
void F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_6 ( V_6 , struct V_7 , V_6 ) ;
F_7 ( & V_8 -> V_9 ) ;
}
int F_8 ( void )
{
return F_9 ( V_3 ) ;
}
static inline void F_10 ( struct V_5 * V_6 )
{
F_11 ( V_6 , & V_10 ) ;
}
static inline void F_12 ( struct V_5 * V_6 )
{
F_13 ( V_6 , & V_10 ) ;
}
static int F_14 ( void * V_11 , enum V_12 V_13 )
{
struct V_5 * V_6 = V_11 ;
switch ( V_13 ) {
case V_14 :
#ifndef F_15
F_16 ( 1 ) ;
return 0 ;
#endif
if ( F_17 () != 0 || F_18 () != 0 ||
F_4 () ) {
F_16 ( 1 ) ;
return 0 ;
}
F_19 () ;
F_20 () ;
F_21 () ;
F_11 ( V_6 , & V_10 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_22 ( void * V_11 , enum V_12 V_13 )
{
struct V_5 * V_6 = V_11 ;
switch ( V_13 ) {
case V_15 :
F_11 ( V_6 , & V_10 ) ;
F_23 ( V_6 , & V_10 ) ;
return 0 ;
case V_14 :
#ifndef F_15
F_16 ( 1 ) ;
return 0 ;
#endif
if ( F_17 () != 0 || F_18 () != 0 ||
F_4 () ) {
F_16 ( 1 ) ;
return 0 ;
}
F_19 () ;
F_20 () ;
F_21 () ;
F_23 ( V_6 , & V_10 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_24 ( void * V_11 , enum V_12 V_13 )
{
struct V_5 * V_6 = V_11 ;
switch ( V_13 ) {
case V_14 :
#ifndef F_15
F_16 ( 1 ) ;
return 0 ;
#endif
if ( F_17 () != 0 || F_18 () != 0 ||
F_4 () ) {
F_16 ( 1 ) ;
return 0 ;
}
F_19 () ;
F_20 () ;
F_21 () ;
F_13 ( V_6 , & V_10 ) ;
return 1 ;
default:
return 0 ;
}
}
void F_25 ( struct V_5 * V_6 )
{
F_26 ( V_6 , & V_10 ) ;
}
void F_27 ( struct V_5 * V_6 )
{
F_13 ( V_6 , & V_10 ) ;
}
