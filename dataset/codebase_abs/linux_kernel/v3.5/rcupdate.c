void F_1 ( void )
{
struct V_1 * V_2 = V_3 ;
if ( F_2 ( F_3 ( & V_3 -> V_4 ) ) )
return;
V_2 -> V_5 = 1 ;
F_4 () ;
V_2 -> V_6 = V_7 ;
F_5 () ;
}
void F_1 ( void )
{
}
int F_6 ( void )
{
return V_8 && V_9 &&
V_3 -> V_10 == 0 ;
}
int F_7 ( void )
{
if ( ! F_6 () )
return 1 ;
if ( F_8 () )
return 0 ;
if ( ! F_9 () )
return 0 ;
return F_10 () || F_11 () ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_13 ( V_12 , struct V_13 , V_12 ) ;
F_14 ( & V_14 -> V_15 ) ;
}
void F_15 ( T_1 V_16 )
{
struct V_13 V_14 ;
F_16 ( & V_14 . V_12 ) ;
F_17 ( & V_14 . V_15 ) ;
V_16 ( & V_14 . V_12 , F_12 ) ;
F_18 ( & V_14 . V_15 ) ;
F_19 ( & V_14 . V_12 ) ;
}
int F_20 ( void )
{
return F_21 ( V_3 ) ;
}
static inline void F_22 ( struct V_11 * V_12 )
{
F_23 ( V_12 , & V_17 ) ;
}
static inline void F_24 ( struct V_11 * V_12 )
{
F_25 ( V_12 , & V_17 ) ;
}
static int F_26 ( void * V_18 , enum V_19 V_20 )
{
struct V_11 * V_12 = V_18 ;
switch ( V_20 ) {
case V_21 :
#ifndef F_27
F_28 ( 1 ) ;
return 0 ;
#endif
if ( F_29 () != 0 || F_30 () != 0 ||
F_11 () ) {
F_28 ( 1 ) ;
return 0 ;
}
F_31 () ;
F_32 () ;
F_33 () ;
F_23 ( V_12 , & V_17 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_34 ( void * V_18 , enum V_19 V_20 )
{
struct V_11 * V_12 = V_18 ;
switch ( V_20 ) {
case V_22 :
F_23 ( V_12 , & V_17 ) ;
F_35 ( V_12 , & V_17 ) ;
return 0 ;
case V_21 :
#ifndef F_27
F_28 ( 1 ) ;
return 0 ;
#endif
if ( F_29 () != 0 || F_30 () != 0 ||
F_11 () ) {
F_28 ( 1 ) ;
return 0 ;
}
F_31 () ;
F_32 () ;
F_33 () ;
F_35 ( V_12 , & V_17 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_36 ( void * V_18 , enum V_19 V_20 )
{
struct V_11 * V_12 = V_18 ;
switch ( V_20 ) {
case V_21 :
#ifndef F_27
F_28 ( 1 ) ;
return 0 ;
#endif
if ( F_29 () != 0 || F_30 () != 0 ||
F_11 () ) {
F_28 ( 1 ) ;
return 0 ;
}
F_31 () ;
F_32 () ;
F_33 () ;
F_25 ( V_12 , & V_17 ) ;
return 1 ;
default:
return 0 ;
}
}
void F_16 ( struct V_11 * V_12 )
{
F_37 ( V_12 , & V_17 ) ;
}
void F_19 ( struct V_11 * V_12 )
{
F_25 ( V_12 , & V_17 ) ;
}
void F_38 ( char * V_23 , struct V_11 * V_24 )
{
F_39 ( V_23 , V_24 ) ;
}
