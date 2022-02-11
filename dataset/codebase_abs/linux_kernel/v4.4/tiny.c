bool T_1 F_1 ( void )
{
return true ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_3 ( F_4 ( V_2 ) ) ;
if ( V_2 -> V_3 != V_2 -> V_4 ) {
V_2 -> V_3 = V_2 -> V_4 ;
return 1 ;
}
return 0 ;
}
void F_5 ( void )
{
unsigned long V_5 ;
F_6 ( V_5 ) ;
if ( F_2 ( & V_6 ) +
F_2 ( & V_7 ) )
F_7 ( V_8 ) ;
F_8 ( V_5 ) ;
}
void F_9 ( void )
{
unsigned long V_5 ;
F_6 ( V_5 ) ;
if ( F_2 ( & V_7 ) )
F_7 ( V_8 ) ;
F_8 ( V_5 ) ;
}
void F_10 ( int V_9 )
{
F_3 ( F_11 () ) ;
if ( V_9 )
F_5 () ;
else if ( ! F_12 () )
F_9 () ;
if ( V_9 )
F_13 ( V_10 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
const char * V_11 = NULL ;
struct V_12 * V_13 , * V_14 ;
unsigned long V_5 ;
F_3 (int cb_count = 0 ) ;
F_6 ( V_5 ) ;
if ( V_2 -> V_3 == & V_2 -> V_15 ) {
F_8 ( V_5 ) ;
return;
}
F_3 ( F_15 ( V_2 -> V_16 , 0 , V_2 -> V_17 , - 1 ) ) ;
V_14 = V_2 -> V_15 ;
V_2 -> V_15 = * V_2 -> V_3 ;
* V_2 -> V_3 = NULL ;
if ( V_2 -> V_4 == V_2 -> V_3 )
V_2 -> V_4 = & V_2 -> V_15 ;
V_2 -> V_3 = & V_2 -> V_15 ;
F_8 ( V_5 ) ;
F_3 ( V_11 = V_2 -> V_16 ) ;
while ( V_14 ) {
V_13 = V_14 -> V_13 ;
F_16 ( V_13 ) ;
F_17 ( V_14 ) ;
F_18 () ;
F_19 ( V_11 , V_14 ) ;
F_20 () ;
V_14 = V_13 ;
F_3 ( V_18 ++ ) ;
}
F_3 ( F_21 ( V_2 , V_18 ) ) ;
F_3 ( F_22 ( V_2 -> V_16 ,
V_18 , 0 , F_23 () ,
F_24 ( V_10 ) ,
false ) ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
F_14 ( & V_6 ) ;
F_14 ( & V_7 ) ;
}
void F_26 ( void )
{
F_27 ( F_28 ( & V_21 ) ||
F_28 ( & V_22 ) ||
F_28 ( & V_23 ) ,
L_1 ) ;
F_29 () ;
}
static void F_30 ( struct V_12 * V_24 ,
T_2 V_25 ,
struct V_1 * V_2 )
{
unsigned long V_5 ;
F_31 ( V_24 ) ;
V_24 -> V_25 = V_25 ;
V_24 -> V_13 = NULL ;
F_6 ( V_5 ) ;
* V_2 -> V_4 = V_24 ;
V_2 -> V_4 = & V_24 -> V_13 ;
F_3 ( V_2 -> V_17 ++ ) ;
F_8 ( V_5 ) ;
if ( F_32 ( F_24 ( V_10 ) ) ) {
F_33 ( 0 ) ;
}
}
void F_34 ( struct V_12 * V_24 , T_2 V_25 )
{
F_30 ( V_24 , V_25 , & V_6 ) ;
}
void F_35 ( struct V_12 * V_24 , T_2 V_25 )
{
F_30 ( V_24 , V_25 , & V_7 ) ;
}
void T_3 F_36 ( void )
{
F_37 ( V_8 , F_25 ) ;
F_3 ( F_4 ( & V_6 ) ) ;
F_3 ( F_4 ( & V_7 ) ) ;
F_38 () ;
}
