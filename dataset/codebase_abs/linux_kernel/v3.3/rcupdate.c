int F_1 ( void )
{
return V_1 && V_2 &&
V_3 -> V_4 == 0 ;
}
int F_2 ( void )
{
if ( ! F_1 () )
return 1 ;
if ( F_3 () )
return 0 ;
return F_4 () || F_5 () ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_7 ( V_6 , struct V_7 , V_6 ) ;
F_8 ( & V_8 -> V_9 ) ;
}
void F_9 ( T_1 V_10 )
{
struct V_7 V_8 ;
F_10 ( & V_8 . V_6 ) ;
F_11 ( & V_8 . V_9 ) ;
V_10 ( & V_8 . V_6 , F_6 ) ;
F_12 ( & V_8 . V_9 ) ;
F_13 ( & V_8 . V_6 ) ;
}
int F_14 ( void )
{
return F_15 ( V_3 ) ;
}
static inline void F_16 ( struct V_5 * V_6 )
{
F_17 ( V_6 , & V_11 ) ;
}
static inline void F_18 ( struct V_5 * V_6 )
{
F_19 ( V_6 , & V_11 ) ;
}
static int F_20 ( void * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_12 ;
switch ( V_14 ) {
case V_15 :
#ifndef F_21
F_22 ( 1 ) ;
return 0 ;
#endif
if ( F_23 () != 0 || F_24 () != 0 ||
F_5 () ) {
F_22 ( 1 ) ;
return 0 ;
}
F_25 () ;
F_26 () ;
F_27 () ;
F_17 ( V_6 , & V_11 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_28 ( void * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_12 ;
switch ( V_14 ) {
case V_16 :
F_17 ( V_6 , & V_11 ) ;
F_29 ( V_6 , & V_11 ) ;
return 0 ;
case V_15 :
#ifndef F_21
F_22 ( 1 ) ;
return 0 ;
#endif
if ( F_23 () != 0 || F_24 () != 0 ||
F_5 () ) {
F_22 ( 1 ) ;
return 0 ;
}
F_25 () ;
F_26 () ;
F_27 () ;
F_29 ( V_6 , & V_11 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_30 ( void * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_12 ;
switch ( V_14 ) {
case V_15 :
#ifndef F_21
F_22 ( 1 ) ;
return 0 ;
#endif
if ( F_23 () != 0 || F_24 () != 0 ||
F_5 () ) {
F_22 ( 1 ) ;
return 0 ;
}
F_25 () ;
F_26 () ;
F_27 () ;
F_19 ( V_6 , & V_11 ) ;
return 1 ;
default:
return 0 ;
}
}
void F_10 ( struct V_5 * V_6 )
{
F_31 ( V_6 , & V_11 ) ;
}
void F_13 ( struct V_5 * V_6 )
{
F_19 ( V_6 , & V_11 ) ;
}
void F_32 ( char * V_17 , struct V_5 * V_18 )
{
F_33 ( V_17 , V_18 ) ;
}
