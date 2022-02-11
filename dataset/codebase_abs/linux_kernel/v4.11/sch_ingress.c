static struct V_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return NULL ;
}
static unsigned long F_2 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_3 ( V_4 ) + 1 ;
}
static bool F_4 ( T_1 V_4 )
{
return true ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_5 , T_1 V_4 )
{
return F_2 ( V_2 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned long V_6 )
{
}
static void F_7 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
}
static struct V_9 T_2 * * F_8 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
return & V_11 -> V_12 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
F_11 () ;
V_2 -> V_15 |= V_16 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
F_13 ( & V_11 -> V_12 ) ;
F_14 () ;
}
static int F_15 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_13 * V_19 ;
V_19 = F_16 ( V_18 , V_20 ) ;
if ( V_19 == NULL )
goto V_21;
return F_17 ( V_18 , V_19 ) ;
V_21:
F_18 ( V_18 , V_19 ) ;
return - 1 ;
}
static unsigned long F_19 ( struct V_1 * V_2 , T_1 V_4 )
{
switch ( F_3 ( V_4 ) ) {
case F_3 ( V_22 ) :
case F_3 ( V_23 ) :
return F_3 ( V_4 ) ;
default:
return 0 ;
}
}
static bool F_20 ( T_1 V_4 )
{
return F_3 ( V_4 ) == F_3 ( V_22 ) ;
}
static unsigned long F_21 ( struct V_1 * V_2 ,
unsigned long V_5 , T_1 V_4 )
{
return F_19 ( V_2 , V_4 ) ;
}
static struct V_9 T_2 * * F_22 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
switch ( V_6 ) {
case F_3 ( V_22 ) :
return & V_11 -> V_12 ;
case F_3 ( V_23 ) :
return & V_11 -> V_24 ;
default:
return NULL ;
}
}
static int F_23 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
F_11 () ;
F_24 () ;
V_2 -> V_15 |= V_16 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
F_13 ( & V_11 -> V_12 ) ;
F_13 ( & V_11 -> V_24 ) ;
F_14 () ;
F_26 () ;
}
static int T_3 F_27 ( void )
{
int V_25 ;
V_25 = F_28 ( & V_26 ) ;
if ( ! V_25 ) {
V_25 = F_28 ( & V_27 ) ;
if ( V_25 )
F_29 ( & V_26 ) ;
}
return V_25 ;
}
static void T_4 F_30 ( void )
{
F_29 ( & V_26 ) ;
F_29 ( & V_27 ) ;
}
