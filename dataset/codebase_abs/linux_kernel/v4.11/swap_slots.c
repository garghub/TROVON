static void F_1 ( void )
{
F_2 ( & V_1 ) ;
V_2 = false ;
F_3 ( V_3 | V_4 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( void )
{
F_2 ( & V_1 ) ;
V_2 = true ;
F_4 ( & V_1 ) ;
}
void F_6 ( void )
{
F_2 ( & V_5 ) ;
V_6 = false ;
if ( V_7 ) {
F_7 () ;
F_3 ( V_3 | V_4 ) ;
F_8 () ;
}
}
static void F_9 ( void )
{
V_6 = F_10 () ;
}
void F_11 ( void )
{
F_9 () ;
F_4 ( & V_5 ) ;
}
static bool F_12 ( void )
{
long V_8 ;
if ( ! V_6 || ! V_7 )
return false ;
V_8 = F_13 () ;
if ( ! V_2 ) {
if ( V_8 > F_14 () *
V_9 )
F_5 () ;
goto V_10;
}
if ( V_8 < F_14 () * V_11 )
F_1 () ;
V_10:
return V_2 ;
}
static int F_15 ( unsigned int V_12 )
{
struct V_13 * V_14 ;
T_1 * V_15 , * V_16 ;
V_15 = F_16 ( sizeof( T_1 ) * V_17 ) ;
if ( ! V_15 )
return - V_18 ;
V_16 = F_16 ( sizeof( T_1 ) * V_17 ) ;
if ( ! V_16 ) {
F_17 ( V_15 ) ;
return - V_18 ;
}
F_2 ( & V_1 ) ;
V_14 = & F_18 ( V_19 , V_12 ) ;
if ( V_14 -> V_15 || V_14 -> V_16 )
goto V_10;
if ( ! V_14 -> V_20 ) {
F_19 ( & V_14 -> V_21 ) ;
F_20 ( & V_14 -> V_22 ) ;
V_14 -> V_20 = true ;
}
V_14 -> V_23 = 0 ;
V_14 -> V_24 = 0 ;
V_14 -> V_25 = 0 ;
V_14 -> V_15 = V_15 ;
V_15 = NULL ;
V_14 -> V_16 = V_16 ;
V_16 = NULL ;
V_10:
F_4 ( & V_1 ) ;
if ( V_15 )
F_17 ( V_15 ) ;
if ( V_16 )
F_17 ( V_16 ) ;
return 0 ;
}
static void F_21 ( unsigned int V_12 , unsigned int type ,
bool V_26 )
{
struct V_13 * V_14 ;
T_1 * V_15 = NULL ;
V_14 = & F_18 ( V_19 , V_12 ) ;
if ( ( type & V_3 ) && V_14 -> V_15 ) {
F_2 ( & V_14 -> V_21 ) ;
F_22 ( V_14 -> V_15 + V_14 -> V_24 , V_14 -> V_23 ) ;
V_14 -> V_24 = 0 ;
V_14 -> V_23 = 0 ;
if ( V_26 && V_14 -> V_15 ) {
F_17 ( V_14 -> V_15 ) ;
V_14 -> V_15 = NULL ;
}
F_4 ( & V_14 -> V_21 ) ;
}
if ( ( type & V_4 ) && V_14 -> V_16 ) {
F_23 ( & V_14 -> V_22 ) ;
F_22 ( V_14 -> V_16 , V_14 -> V_25 ) ;
V_14 -> V_25 = 0 ;
if ( V_26 && V_14 -> V_16 ) {
V_15 = V_14 -> V_16 ;
V_14 -> V_16 = NULL ;
}
F_24 ( & V_14 -> V_22 ) ;
if ( V_15 )
F_17 ( V_15 ) ;
}
}
static void F_3 ( unsigned int type )
{
unsigned int V_12 ;
F_25 (cpu)
F_21 ( V_12 , type , false ) ;
}
static int F_26 ( unsigned int V_12 )
{
F_2 ( & V_1 ) ;
F_21 ( V_12 , V_3 | V_4 , true ) ;
F_4 ( & V_1 ) ;
return 0 ;
}
int F_27 ( void )
{
int V_27 = 0 ;
F_2 ( & V_5 ) ;
if ( V_7 ) {
F_9 () ;
goto V_28;
}
V_27 = F_28 ( V_29 , L_1 ,
F_15 , F_26 ) ;
if ( V_27 < 0 )
goto V_28;
V_7 = true ;
F_9 () ;
V_28:
F_4 ( & V_5 ) ;
return 0 ;
}
static int F_29 ( struct V_13 * V_14 )
{
if ( ! V_30 || V_14 -> V_23 )
return 0 ;
V_14 -> V_24 = 0 ;
if ( V_2 )
V_14 -> V_23 = F_30 ( V_17 , V_14 -> V_15 ) ;
return V_14 -> V_23 ;
}
int F_31 ( T_1 V_31 )
{
struct V_13 * V_14 ;
V_14 = & F_32 ( V_19 ) ;
if ( V_30 && V_14 -> V_16 ) {
F_23 ( & V_14 -> V_22 ) ;
if ( ! V_30 ) {
F_24 ( & V_14 -> V_22 ) ;
goto V_32;
}
if ( V_14 -> V_25 >= V_17 ) {
F_22 ( V_14 -> V_16 , V_14 -> V_25 ) ;
V_14 -> V_25 = 0 ;
}
V_14 -> V_16 [ V_14 -> V_25 ++ ] = V_31 ;
F_24 ( & V_14 -> V_22 ) ;
} else {
V_32:
F_22 ( & V_31 , 1 ) ;
}
F_33 ( V_19 ) ;
return 0 ;
}
T_1 F_34 ( void )
{
T_1 V_31 , * V_33 ;
struct V_13 * V_14 ;
V_14 = F_35 ( & V_19 ) ;
V_31 . V_34 = 0 ;
if ( F_12 () ) {
F_2 ( & V_14 -> V_21 ) ;
if ( V_14 -> V_15 ) {
V_35:
if ( V_14 -> V_23 ) {
V_33 = & V_14 -> V_15 [ V_14 -> V_24 ++ ] ;
V_31 = * V_33 ;
V_33 -> V_34 = 0 ;
V_14 -> V_23 -- ;
} else {
if ( F_29 ( V_14 ) )
goto V_35;
}
}
F_4 ( & V_14 -> V_21 ) ;
if ( V_31 . V_34 )
return V_31 ;
}
F_30 ( 1 , & V_31 ) ;
return V_31 ;
}
