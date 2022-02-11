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
static void F_5 ( void )
{
V_7 = 1 ;
F_6 ( & V_8 ) ;
}
void F_2 ( int V_9 )
{
unsigned long V_10 ;
F_7 ( V_10 ) ;
if ( F_4 ( & V_11 ) +
F_4 ( & V_12 ) )
F_5 () ;
F_8 ( V_10 ) ;
}
void F_9 ( int V_9 )
{
unsigned long V_10 ;
F_7 ( V_10 ) ;
if ( F_4 ( & V_12 ) )
F_5 () ;
F_8 ( V_10 ) ;
}
void F_10 ( int V_9 , int V_13 )
{
if ( V_13 ||
( F_11 ( V_9 ) &&
! F_12 () &&
F_13 () <= ( 1 << V_14 ) ) )
F_2 ( V_9 ) ;
else if ( ! F_12 () )
F_9 ( V_9 ) ;
F_14 () ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_15 * V_16 , * V_17 ;
unsigned long V_10 ;
F_16 (int cb_count = 0 ) ;
if ( & V_3 -> V_4 == V_3 -> V_5 )
return;
F_7 ( V_10 ) ;
V_17 = V_3 -> V_4 ;
V_3 -> V_4 = * V_3 -> V_5 ;
* V_3 -> V_5 = NULL ;
if ( V_3 -> V_6 == V_3 -> V_5 )
V_3 -> V_6 = & V_3 -> V_4 ;
F_17 ( V_3 ) ;
V_3 -> V_5 = & V_3 -> V_4 ;
F_8 ( V_10 ) ;
while ( V_17 ) {
V_16 = V_17 -> V_16 ;
F_18 ( V_16 ) ;
F_19 ( V_17 ) ;
F_20 () ;
F_21 ( V_17 ) ;
F_22 () ;
V_17 = V_16 ;
F_16 ( V_18 ++ ) ;
}
F_16 ( F_23 ( V_3 , V_18 ) ) ;
}
static int F_24 ( void * V_19 )
{
unsigned long V_20 ;
unsigned long V_21 ;
unsigned long V_10 ;
for (; ; ) {
F_25 ( V_8 ,
V_7 != 0 ) ;
V_21 = F_26 () ;
F_7 ( V_10 ) ;
V_20 = V_7 ;
V_7 = V_21 ;
F_8 ( V_10 ) ;
if ( V_20 ) {
F_15 ( & V_11 ) ;
F_15 ( & V_12 ) ;
F_27 () ;
}
F_28 ( 1 ) ;
}
return 0 ;
}
void F_29 ( void )
{
F_30 () ;
}
static void F_31 ( struct V_15 * V_22 ,
void (* F_32)( struct V_15 * V_23 ) ,
struct V_2 * V_3 )
{
unsigned long V_10 ;
F_33 ( V_22 ) ;
V_22 -> F_32 = F_32 ;
V_22 -> V_16 = NULL ;
F_7 ( V_10 ) ;
* V_3 -> V_6 = V_22 ;
V_3 -> V_6 = & V_22 -> V_16 ;
F_16 ( V_3 -> V_24 ++ ) ;
F_8 ( V_10 ) ;
}
void F_34 ( struct V_15 * V_22 , void (* F_32)( struct V_15 * V_23 ) )
{
F_31 ( V_22 , F_32 , & V_11 ) ;
}
void F_35 ( struct V_15 * V_22 , void (* F_32)( struct V_15 * V_23 ) )
{
F_31 ( V_22 , F_32 , & V_12 ) ;
}
void F_36 ( void )
{
struct V_25 V_23 ;
F_37 ( & V_23 . V_22 ) ;
F_38 ( & V_23 . V_26 ) ;
F_35 ( & V_23 . V_22 , V_27 ) ;
F_39 ( & V_23 . V_26 ) ;
F_40 ( & V_23 . V_22 ) ;
}
void F_41 ( void )
{
struct V_25 V_23 ;
F_37 ( & V_23 . V_22 ) ;
F_38 ( & V_23 . V_26 ) ;
F_34 ( & V_23 . V_22 , V_27 ) ;
F_39 ( & V_23 . V_26 ) ;
F_40 ( & V_23 . V_22 ) ;
}
static int T_1 F_42 ( void )
{
struct V_28 V_29 ;
V_30 = F_43 ( F_24 , NULL , L_1 ) ;
V_29 . V_31 = V_32 ;
F_44 ( V_30 , V_33 , & V_29 ) ;
return 0 ;
}
