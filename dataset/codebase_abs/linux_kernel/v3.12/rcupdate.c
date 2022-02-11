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
int T_1 F_10 ( void )
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
void F_19 ( T_2 V_16 )
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
F_27 ( V_12 , & V_17 ) ;
F_31 ( V_12 , & V_17 ) ;
return 0 ;
default:
return 1 ;
}
}
void F_20 ( struct V_11 * V_12 )
{
F_32 ( V_12 , & V_17 ) ;
}
void F_23 ( struct V_11 * V_12 )
{
F_29 ( V_12 , & V_17 ) ;
}
void F_33 ( const char * V_22 , struct V_11 * V_23 ,
unsigned long V_24 ,
unsigned long V_25 , unsigned long V_26 )
{
F_34 ( V_22 , V_23 , V_24 , V_25 , V_26 ) ;
}
int F_35 ( void )
{
int V_27 = F_7 ( V_28 ) ;
if ( V_27 < 3 ) {
F_7 ( V_28 ) = 3 ;
V_27 = 3 ;
} else if ( V_27 > 300 ) {
F_7 ( V_28 ) = 300 ;
V_27 = 300 ;
}
return V_27 * V_29 + V_30 ;
}
static int F_36 ( struct V_31 * V_32 , unsigned long V_33 , void * V_34 )
{
V_35 = 1 ;
return V_36 ;
}
static int T_3 F_37 ( void )
{
F_38 ( & V_37 , & V_38 ) ;
return 0 ;
}
