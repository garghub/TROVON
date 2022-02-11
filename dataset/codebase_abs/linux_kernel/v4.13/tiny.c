void F_1 ( void )
{
F_2 ( V_1 ) ;
}
void F_3 ( void )
{
F_2 ( V_2 ) ;
}
static int F_4 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 != V_4 -> V_6 ) {
V_4 -> V_5 = V_4 -> V_6 ;
return 1 ;
}
return 0 ;
}
void F_5 ( void )
{
unsigned long V_7 ;
F_6 ( V_7 ) ;
if ( F_4 ( & V_8 ) +
F_4 ( & V_9 ) )
F_7 ( V_10 ) ;
F_8 ( V_7 ) ;
}
void F_9 ( void )
{
unsigned long V_7 ;
F_6 ( V_7 ) ;
if ( F_4 ( & V_9 ) )
F_7 ( V_10 ) ;
F_8 ( V_7 ) ;
}
void F_10 ( int V_11 )
{
if ( V_11 )
F_5 () ;
else if ( ! F_11 () )
F_9 () ;
if ( V_11 )
F_12 ( V_12 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_13 * V_14 , * V_15 ;
unsigned long V_7 ;
F_6 ( V_7 ) ;
if ( V_4 -> V_5 == & V_4 -> V_16 ) {
F_8 ( V_7 ) ;
return;
}
V_15 = V_4 -> V_16 ;
V_4 -> V_16 = * V_4 -> V_5 ;
* V_4 -> V_5 = NULL ;
if ( V_4 -> V_6 == V_4 -> V_5 )
V_4 -> V_6 = & V_4 -> V_16 ;
V_4 -> V_5 = & V_4 -> V_16 ;
F_8 ( V_7 ) ;
while ( V_15 ) {
V_14 = V_15 -> V_14 ;
F_14 ( V_14 ) ;
F_15 ( V_15 ) ;
F_16 () ;
F_17 ( L_1 , V_15 ) ;
F_18 () ;
V_15 = V_14 ;
}
}
static T_1 void F_19 ( struct V_17 * V_18 )
{
F_13 ( & V_8 ) ;
F_13 ( & V_9 ) ;
}
void F_20 ( void )
{
F_21 ( F_22 ( & V_19 ) ||
F_22 ( & V_20 ) ||
F_22 ( & V_21 ) ,
L_2 ) ;
}
static void F_23 ( struct V_13 * V_22 ,
T_2 V_23 ,
struct V_3 * V_4 )
{
unsigned long V_7 ;
F_24 ( V_22 ) ;
V_22 -> V_23 = V_23 ;
V_22 -> V_14 = NULL ;
F_6 ( V_7 ) ;
* V_4 -> V_6 = V_22 ;
V_4 -> V_6 = & V_22 -> V_14 ;
F_8 ( V_7 ) ;
if ( F_25 ( F_26 ( V_12 ) ) ) {
F_27 ( 0 ) ;
}
}
void V_2 ( struct V_13 * V_22 , T_2 V_23 )
{
F_23 ( V_22 , V_23 , & V_8 ) ;
}
void V_1 ( struct V_13 * V_22 , T_2 V_23 )
{
F_23 ( V_22 , V_23 , & V_9 ) ;
}
void T_3 F_28 ( void )
{
F_29 ( V_10 , F_19 ) ;
F_30 () ;
}
