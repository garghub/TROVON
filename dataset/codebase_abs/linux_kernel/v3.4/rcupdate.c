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
if ( ! F_4 () )
return 0 ;
return F_5 () || F_6 () ;
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_8 ( V_6 , struct V_7 , V_6 ) ;
F_9 ( & V_8 -> V_9 ) ;
}
void F_10 ( T_1 V_10 )
{
struct V_7 V_8 ;
F_11 ( & V_8 . V_6 ) ;
F_12 ( & V_8 . V_9 ) ;
V_10 ( & V_8 . V_6 , F_7 ) ;
F_13 ( & V_8 . V_9 ) ;
F_14 ( & V_8 . V_6 ) ;
}
int F_15 ( void )
{
return F_16 ( V_3 ) ;
}
static inline void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 , & V_11 ) ;
}
static inline void F_19 ( struct V_5 * V_6 )
{
F_20 ( V_6 , & V_11 ) ;
}
static int F_21 ( void * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_12 ;
switch ( V_14 ) {
case V_15 :
#ifndef F_22
F_23 ( 1 ) ;
return 0 ;
#endif
if ( F_24 () != 0 || F_25 () != 0 ||
F_6 () ) {
F_23 ( 1 ) ;
return 0 ;
}
F_26 () ;
F_27 () ;
F_28 () ;
F_18 ( V_6 , & V_11 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_29 ( void * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_12 ;
switch ( V_14 ) {
case V_16 :
F_18 ( V_6 , & V_11 ) ;
F_30 ( V_6 , & V_11 ) ;
return 0 ;
case V_15 :
#ifndef F_22
F_23 ( 1 ) ;
return 0 ;
#endif
if ( F_24 () != 0 || F_25 () != 0 ||
F_6 () ) {
F_23 ( 1 ) ;
return 0 ;
}
F_26 () ;
F_27 () ;
F_28 () ;
F_30 ( V_6 , & V_11 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_31 ( void * V_12 , enum V_13 V_14 )
{
struct V_5 * V_6 = V_12 ;
switch ( V_14 ) {
case V_15 :
#ifndef F_22
F_23 ( 1 ) ;
return 0 ;
#endif
if ( F_24 () != 0 || F_25 () != 0 ||
F_6 () ) {
F_23 ( 1 ) ;
return 0 ;
}
F_26 () ;
F_27 () ;
F_28 () ;
F_20 ( V_6 , & V_11 ) ;
return 1 ;
default:
return 0 ;
}
}
void F_11 ( struct V_5 * V_6 )
{
F_32 ( V_6 , & V_11 ) ;
}
void F_14 ( struct V_5 * V_6 )
{
F_20 ( V_6 , & V_11 ) ;
}
void F_33 ( char * V_17 , struct V_5 * V_18 )
{
F_34 ( V_17 , V_18 ) ;
}
