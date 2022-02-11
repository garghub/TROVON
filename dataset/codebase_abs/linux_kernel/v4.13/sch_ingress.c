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
static struct V_9 * F_8 ( struct V_1 * V_2 , unsigned long V_6 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
return V_11 -> V_12 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
struct V_15 * V_16 = F_11 ( V_2 ) ;
int V_17 ;
V_17 = F_12 ( & V_11 -> V_12 , & V_16 -> V_18 ) ;
if ( V_17 )
return V_17 ;
F_13 () ;
V_2 -> V_19 |= V_20 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_9 ( V_2 ) ;
F_15 ( V_11 -> V_12 ) ;
F_16 () ;
}
static int F_17 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_13 * V_23 ;
V_23 = F_18 ( V_22 , V_24 ) ;
if ( V_23 == NULL )
goto V_25;
return F_19 ( V_22 , V_23 ) ;
V_25:
F_20 ( V_22 , V_23 ) ;
return - 1 ;
}
static unsigned long F_21 ( struct V_1 * V_2 , T_1 V_4 )
{
switch ( F_3 ( V_4 ) ) {
case F_3 ( V_26 ) :
case F_3 ( V_27 ) :
return F_3 ( V_4 ) ;
default:
return 0 ;
}
}
static bool F_22 ( T_1 V_4 )
{
return F_3 ( V_4 ) == F_3 ( V_26 ) ;
}
static unsigned long F_23 ( struct V_1 * V_2 ,
unsigned long V_5 , T_1 V_4 )
{
return F_21 ( V_2 , V_4 ) ;
}
static struct V_9 * F_24 ( struct V_1 * V_2 , unsigned long V_6 )
{
struct V_28 * V_11 = F_9 ( V_2 ) ;
switch ( V_6 ) {
case F_3 ( V_26 ) :
return V_11 -> V_29 ;
case F_3 ( V_27 ) :
return V_11 -> V_30 ;
default:
return NULL ;
}
}
static int F_25 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_28 * V_11 = F_9 ( V_2 ) ;
struct V_15 * V_16 = F_11 ( V_2 ) ;
int V_17 ;
V_17 = F_12 ( & V_11 -> V_29 , & V_16 -> V_18 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_12 ( & V_11 -> V_30 , & V_16 -> V_31 ) ;
if ( V_17 )
return V_17 ;
F_13 () ;
F_26 () ;
V_2 -> V_19 |= V_20 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_28 * V_11 = F_9 ( V_2 ) ;
F_15 ( V_11 -> V_30 ) ;
F_15 ( V_11 -> V_29 ) ;
F_16 () ;
F_28 () ;
}
static int T_2 F_29 ( void )
{
int V_32 ;
V_32 = F_30 ( & V_33 ) ;
if ( ! V_32 ) {
V_32 = F_30 ( & V_34 ) ;
if ( V_32 )
F_31 ( & V_33 ) ;
}
return V_32 ;
}
static void T_3 F_32 ( void )
{
F_31 ( & V_33 ) ;
F_31 ( & V_34 ) ;
}
