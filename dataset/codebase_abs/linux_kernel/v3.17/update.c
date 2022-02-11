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
int T_1 F_8 ( void )
{
return V_8 && V_9 &&
V_1 -> V_10 == 0 ;
}
int F_9 ( void )
{
if ( ! F_8 () )
return 1 ;
if ( ! F_10 () )
return 0 ;
if ( ! F_11 () )
return 0 ;
return F_12 () || F_13 () ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( V_12 , struct V_13 , V_12 ) ;
F_16 ( & V_14 -> V_15 ) ;
}
void F_17 ( T_2 V_16 )
{
struct V_13 V_14 ;
F_18 ( & V_14 . V_12 ) ;
F_19 ( & V_14 . V_15 ) ;
V_16 ( & V_14 . V_12 , F_14 ) ;
F_20 ( & V_14 . V_15 ) ;
F_21 ( & V_14 . V_12 ) ;
}
void F_22 ( struct V_11 * V_12 )
{
F_23 ( V_12 , & V_17 ) ;
}
void F_24 ( struct V_11 * V_12 )
{
F_25 ( V_12 , & V_17 ) ;
}
static int F_26 ( void * V_18 , enum V_19 V_20 )
{
struct V_11 * V_12 = V_18 ;
switch ( V_20 ) {
case V_21 :
F_23 ( V_12 , & V_17 ) ;
F_27 ( V_12 , & V_17 ) ;
return 0 ;
default:
return 1 ;
}
}
void F_18 ( struct V_11 * V_12 )
{
F_28 ( V_12 , & V_17 ) ;
}
void F_21 ( struct V_11 * V_12 )
{
F_25 ( V_12 , & V_17 ) ;
}
void F_29 ( const char * V_22 , struct V_11 * V_23 ,
unsigned long V_24 ,
unsigned long V_25 , unsigned long V_26 )
{
F_30 ( V_22 , V_23 , V_24 , V_25 , V_26 ) ;
}
int F_31 ( void )
{
int V_27 = F_5 ( V_28 ) ;
if ( V_27 < 3 ) {
F_5 ( V_28 ) = 3 ;
V_27 = 3 ;
} else if ( V_27 > 300 ) {
F_5 ( V_28 ) = 300 ;
V_27 = 300 ;
}
return V_27 * V_29 + V_30 ;
}
void F_32 ( void )
{
if ( ! V_31 )
V_31 = 2 ;
}
void F_33 ( void )
{
if ( V_31 == 2 )
V_31 = 0 ;
}
static int F_34 ( struct V_32 * V_33 , unsigned long V_34 , void * V_35 )
{
V_31 = 1 ;
return V_36 ;
}
static int T_3 F_35 ( void )
{
F_36 ( & V_37 , & V_38 ) ;
return 0 ;
}
