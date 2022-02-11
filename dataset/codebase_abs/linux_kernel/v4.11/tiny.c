void F_1 ( void )
{
F_2 ( V_1 ) ;
}
void F_3 ( void )
{
F_2 ( V_2 ) ;
}
bool T_1 F_4 ( void )
{
return true ;
}
static int F_5 ( struct V_3 * V_4 )
{
F_6 ( F_7 ( V_4 ) ) ;
if ( V_4 -> V_5 != V_4 -> V_6 ) {
V_4 -> V_5 = V_4 -> V_6 ;
return 1 ;
}
return 0 ;
}
void F_8 ( void )
{
unsigned long V_7 ;
F_9 ( V_7 ) ;
if ( F_5 ( & V_8 ) +
F_5 ( & V_9 ) )
F_10 ( V_10 ) ;
F_11 ( V_7 ) ;
}
void F_12 ( void )
{
unsigned long V_7 ;
F_9 ( V_7 ) ;
if ( F_5 ( & V_9 ) )
F_10 ( V_10 ) ;
F_11 ( V_7 ) ;
}
void F_13 ( int V_11 )
{
F_6 ( F_14 () ) ;
if ( V_11 )
F_8 () ;
else if ( ! F_15 () )
F_12 () ;
if ( V_11 )
F_16 ( V_12 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
const char * V_13 = NULL ;
struct V_14 * V_15 , * V_16 ;
unsigned long V_7 ;
F_6 (int cb_count = 0 ) ;
F_9 ( V_7 ) ;
if ( V_4 -> V_5 == & V_4 -> V_17 ) {
F_11 ( V_7 ) ;
return;
}
F_6 ( F_18 ( V_4 -> V_18 , 0 , V_4 -> V_19 , - 1 ) ) ;
V_16 = V_4 -> V_17 ;
V_4 -> V_17 = * V_4 -> V_5 ;
* V_4 -> V_5 = NULL ;
if ( V_4 -> V_6 == V_4 -> V_5 )
V_4 -> V_6 = & V_4 -> V_17 ;
V_4 -> V_5 = & V_4 -> V_17 ;
F_11 ( V_7 ) ;
F_6 ( V_13 = V_4 -> V_18 ) ;
while ( V_16 ) {
V_15 = V_16 -> V_15 ;
F_19 ( V_15 ) ;
F_20 ( V_16 ) ;
F_21 () ;
F_22 ( V_13 , V_16 ) ;
F_23 () ;
V_16 = V_15 ;
F_6 ( V_20 ++ ) ;
}
F_6 ( F_24 ( V_4 , V_20 ) ) ;
F_6 ( F_25 ( V_4 -> V_18 ,
V_20 , 0 , F_26 () ,
F_27 ( V_12 ) ,
false ) ) ;
}
static T_2 void F_28 ( struct V_21 * V_22 )
{
F_17 ( & V_8 ) ;
F_17 ( & V_9 ) ;
}
void F_29 ( void )
{
F_30 ( F_31 ( & V_23 ) ||
F_31 ( & V_24 ) ||
F_31 ( & V_25 ) ,
L_1 ) ;
}
static void F_32 ( struct V_14 * V_26 ,
T_3 V_27 ,
struct V_3 * V_4 )
{
unsigned long V_7 ;
F_33 ( V_26 ) ;
V_26 -> V_27 = V_27 ;
V_26 -> V_15 = NULL ;
F_9 ( V_7 ) ;
* V_4 -> V_6 = V_26 ;
V_4 -> V_6 = & V_26 -> V_15 ;
F_6 ( V_4 -> V_19 ++ ) ;
F_11 ( V_7 ) ;
if ( F_34 ( F_27 ( V_12 ) ) ) {
F_35 ( 0 ) ;
}
}
void V_2 ( struct V_14 * V_26 , T_3 V_27 )
{
F_32 ( V_26 , V_27 , & V_8 ) ;
}
void V_1 ( struct V_14 * V_26 , T_3 V_27 )
{
F_32 ( V_26 , V_27 , & V_9 ) ;
}
void T_4 F_36 ( void )
{
F_37 ( V_10 , F_28 ) ;
F_6 ( F_7 ( & V_8 ) ) ;
F_6 ( F_7 ( & V_9 ) ) ;
F_38 () ;
}
