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
static void F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_6 ( V_6 , struct V_7 , V_6 ) ;
F_7 ( & V_8 -> V_9 ) ;
}
void F_8 ( T_1 V_10 )
{
struct V_7 V_8 ;
F_9 ( & V_8 . V_6 ) ;
F_10 ( & V_8 . V_9 ) ;
V_10 ( & V_8 . V_6 , F_5 ) ;
F_11 ( & V_8 . V_9 ) ;
F_12 ( & V_8 . V_6 ) ;
}
int F_13 ( void )
{
return F_14 ( V_3 ) ;
}
static inline void F_15 ( struct V_5 * V_6 )
{
F_16 ( V_6 , & V_11 ) ;
}
static inline void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 , & V_11 ) ;
}
static int F_19 ( void * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_12 ;
switch ( V_14 ) {
case V_15 :
#ifndef F_20
F_21 ( 1 ) ;
return 0 ;
#endif
if ( F_22 () != 0 || F_23 () != 0 ||
F_4 () ) {
F_21 ( 1 ) ;
return 0 ;
}
F_24 () ;
F_25 () ;
F_26 () ;
F_16 ( V_6 , & V_11 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_27 ( void * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_12 ;
switch ( V_14 ) {
case V_16 :
F_16 ( V_6 , & V_11 ) ;
F_28 ( V_6 , & V_11 ) ;
return 0 ;
case V_15 :
#ifndef F_20
F_21 ( 1 ) ;
return 0 ;
#endif
if ( F_22 () != 0 || F_23 () != 0 ||
F_4 () ) {
F_21 ( 1 ) ;
return 0 ;
}
F_24 () ;
F_25 () ;
F_26 () ;
F_28 ( V_6 , & V_11 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_29 ( void * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_12 ;
switch ( V_14 ) {
case V_15 :
#ifndef F_20
F_21 ( 1 ) ;
return 0 ;
#endif
if ( F_22 () != 0 || F_23 () != 0 ||
F_4 () ) {
F_21 ( 1 ) ;
return 0 ;
}
F_24 () ;
F_25 () ;
F_26 () ;
F_18 ( V_6 , & V_11 ) ;
return 1 ;
default:
return 0 ;
}
}
void F_9 ( struct V_5 * V_6 )
{
F_30 ( V_6 , & V_11 ) ;
}
void F_12 ( struct V_5 * V_6 )
{
F_18 ( V_6 , & V_11 ) ;
}
