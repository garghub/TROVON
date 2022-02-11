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
V_15 = F_16 ( sizeof( T_1 ) * V_17 ,
V_18 ) ;
if ( ! V_15 )
return - V_19 ;
V_16 = F_16 ( sizeof( T_1 ) * V_17 ,
V_18 ) ;
if ( ! V_16 ) {
F_17 ( V_15 ) ;
return - V_19 ;
}
F_2 ( & V_1 ) ;
V_14 = & F_18 ( V_20 , V_12 ) ;
if ( V_14 -> V_15 || V_14 -> V_16 )
goto V_10;
if ( ! V_14 -> V_21 ) {
F_19 ( & V_14 -> V_22 ) ;
F_20 ( & V_14 -> V_23 ) ;
V_14 -> V_21 = true ;
}
V_14 -> V_24 = 0 ;
V_14 -> V_25 = 0 ;
V_14 -> V_26 = 0 ;
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
bool V_27 )
{
struct V_13 * V_14 ;
T_1 * V_15 = NULL ;
V_14 = & F_18 ( V_20 , V_12 ) ;
if ( ( type & V_3 ) && V_14 -> V_15 ) {
F_2 ( & V_14 -> V_22 ) ;
F_22 ( V_14 -> V_15 + V_14 -> V_25 , V_14 -> V_24 ) ;
V_14 -> V_25 = 0 ;
V_14 -> V_24 = 0 ;
if ( V_27 && V_14 -> V_15 ) {
F_17 ( V_14 -> V_15 ) ;
V_14 -> V_15 = NULL ;
}
F_4 ( & V_14 -> V_22 ) ;
}
if ( ( type & V_4 ) && V_14 -> V_16 ) {
F_23 ( & V_14 -> V_23 ) ;
F_22 ( V_14 -> V_16 , V_14 -> V_26 ) ;
V_14 -> V_26 = 0 ;
if ( V_27 && V_14 -> V_16 ) {
V_15 = V_14 -> V_16 ;
V_14 -> V_16 = NULL ;
}
F_24 ( & V_14 -> V_23 ) ;
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
int V_28 = 0 ;
F_2 ( & V_5 ) ;
if ( V_7 ) {
F_9 () ;
goto V_29;
}
V_28 = F_28 ( V_30 , L_1 ,
F_15 , F_26 ) ;
if ( F_29 ( V_28 < 0 , L_2
L_3 , V_31 ) )
goto V_29;
V_7 = true ;
F_9 () ;
V_29:
F_4 ( & V_5 ) ;
return 0 ;
}
static int F_30 ( struct V_13 * V_14 )
{
if ( ! V_32 || V_14 -> V_24 )
return 0 ;
V_14 -> V_25 = 0 ;
if ( V_2 )
V_14 -> V_24 = F_31 ( V_17 , false ,
V_14 -> V_15 ) ;
return V_14 -> V_24 ;
}
int F_32 ( T_1 V_33 )
{
struct V_13 * V_14 ;
V_14 = F_33 ( & V_20 ) ;
if ( V_32 && V_14 -> V_16 ) {
F_23 ( & V_14 -> V_23 ) ;
if ( ! V_32 || ! V_14 -> V_16 ) {
F_24 ( & V_14 -> V_23 ) ;
goto V_34;
}
if ( V_14 -> V_26 >= V_17 ) {
F_22 ( V_14 -> V_16 , V_14 -> V_26 ) ;
V_14 -> V_26 = 0 ;
}
V_14 -> V_16 [ V_14 -> V_26 ++ ] = V_33 ;
F_24 ( & V_14 -> V_23 ) ;
} else {
V_34:
F_22 ( & V_33 , 1 ) ;
}
return 0 ;
}
T_1 F_34 ( struct V_35 * V_35 )
{
T_1 V_33 , * V_36 ;
struct V_13 * V_14 ;
V_33 . V_37 = 0 ;
if ( F_35 ( V_35 ) ) {
if ( F_36 ( V_38 ) )
F_31 ( 1 , true , & V_33 ) ;
return V_33 ;
}
V_14 = F_33 ( & V_20 ) ;
if ( F_12 () ) {
F_2 ( & V_14 -> V_22 ) ;
if ( V_14 -> V_15 ) {
V_39:
if ( V_14 -> V_24 ) {
V_36 = & V_14 -> V_15 [ V_14 -> V_25 ++ ] ;
V_33 = * V_36 ;
V_36 -> V_37 = 0 ;
V_14 -> V_24 -- ;
} else {
if ( F_30 ( V_14 ) )
goto V_39;
}
}
F_4 ( & V_14 -> V_22 ) ;
if ( V_33 . V_37 )
return V_33 ;
}
F_31 ( 1 , false , & V_33 ) ;
return V_33 ;
}
