void F_1 ( void )
{
if ( -- V_1 == 0 )
F_2 ( 0 ) ;
}
void F_3 ( void )
{
V_1 ++ ;
}
static int F_4 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 != NULL &&
V_3 -> V_5 != V_3 -> V_6 ) {
V_3 -> V_5 = V_3 -> V_6 ;
return 1 ;
}
return 0 ;
}
void F_2 ( int V_7 )
{
unsigned long V_8 ;
F_5 ( V_8 ) ;
if ( F_4 ( & V_9 ) +
F_4 ( & V_10 ) )
F_6 () ;
F_7 ( V_8 ) ;
}
void F_8 ( int V_7 )
{
unsigned long V_8 ;
F_5 ( V_8 ) ;
if ( F_4 ( & V_10 ) )
F_6 () ;
F_7 ( V_8 ) ;
}
void F_9 ( int V_7 , int V_11 )
{
if ( V_11 ||
( F_10 ( V_7 ) &&
! F_11 () &&
F_12 () <= ( 1 << V_12 ) ) )
F_2 ( V_7 ) ;
else if ( ! F_11 () )
F_8 ( V_7 ) ;
F_13 () ;
}
static void F_14 ( struct V_2 * V_3 )
{
char * V_13 = NULL ;
struct V_14 * V_15 , * V_16 ;
unsigned long V_8 ;
F_15 (int cb_count = 0 ) ;
if ( & V_3 -> V_4 == V_3 -> V_5 ) {
F_15 ( F_16 ( V_3 -> V_17 , 0 , - 1 ) ) ;
F_15 ( F_17 ( V_3 -> V_17 , 0 ) ) ;
return;
}
F_5 ( V_8 ) ;
F_15 ( F_16 ( V_3 -> V_17 , 0 , - 1 ) ) ;
V_16 = V_3 -> V_4 ;
V_3 -> V_4 = * V_3 -> V_5 ;
* V_3 -> V_5 = NULL ;
if ( V_3 -> V_6 == V_3 -> V_5 )
V_3 -> V_6 = & V_3 -> V_4 ;
F_18 ( V_3 ) ;
V_3 -> V_5 = & V_3 -> V_4 ;
F_7 ( V_8 ) ;
F_15 ( V_13 = V_3 -> V_17 ) ;
while ( V_16 ) {
V_15 = V_16 -> V_15 ;
F_19 ( V_15 ) ;
F_20 ( V_16 ) ;
F_21 () ;
F_22 ( V_13 , V_16 ) ;
F_23 () ;
V_16 = V_15 ;
F_15 ( V_18 ++ ) ;
}
F_15 ( F_24 ( V_3 , V_18 ) ) ;
F_15 ( F_17 ( V_3 -> V_17 , V_18 ) ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
F_14 ( & V_9 ) ;
F_14 ( & V_10 ) ;
F_26 () ;
}
void F_27 ( void )
{
F_28 () ;
}
static void F_29 ( struct V_14 * V_21 ,
void (* F_30)( struct V_14 * V_22 ) ,
struct V_2 * V_3 )
{
unsigned long V_8 ;
F_31 ( V_21 ) ;
V_21 -> F_30 = F_30 ;
V_21 -> V_15 = NULL ;
F_5 ( V_8 ) ;
* V_3 -> V_6 = V_21 ;
V_3 -> V_6 = & V_21 -> V_15 ;
F_15 ( V_3 -> V_23 ++ ) ;
F_7 ( V_8 ) ;
}
void F_32 ( struct V_14 * V_21 , void (* F_30)( struct V_14 * V_22 ) )
{
F_29 ( V_21 , F_30 , & V_9 ) ;
}
void F_33 ( struct V_14 * V_21 , void (* F_30)( struct V_14 * V_22 ) )
{
F_29 ( V_21 , F_30 , & V_10 ) ;
}
