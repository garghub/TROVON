static struct V_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return NULL ;
}
static unsigned long F_2 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_3 ( V_4 ) + 1 ;
}
static unsigned long F_4 ( struct V_1 * V_2 ,
unsigned long V_5 , T_1 V_4 )
{
return F_2 ( V_2 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned long V_6 )
{
}
static void F_6 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
}
static struct V_9 T_2 * * F_7 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
return & V_11 -> V_12 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
F_10 () ;
V_2 -> V_15 |= V_16 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
F_12 ( & V_11 -> V_12 ) ;
F_13 () ;
}
static int F_14 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_13 * V_19 ;
V_19 = F_15 ( V_18 , V_20 ) ;
if ( V_19 == NULL )
goto V_21;
return F_16 ( V_18 , V_19 ) ;
V_21:
F_17 ( V_18 , V_19 ) ;
return - 1 ;
}
static unsigned long F_18 ( struct V_1 * V_2 , T_1 V_4 )
{
switch ( F_3 ( V_4 ) ) {
case F_3 ( V_22 ) :
case F_3 ( V_23 ) :
return F_3 ( V_4 ) ;
default:
return 0 ;
}
}
static unsigned long F_19 ( struct V_1 * V_2 ,
unsigned long V_5 , T_1 V_4 )
{
return F_18 ( V_2 , V_4 ) ;
}
static struct V_9 T_2 * * F_20 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
switch ( V_6 ) {
case F_3 ( V_22 ) :
return & V_11 -> V_12 ;
case F_3 ( V_23 ) :
return & V_11 -> V_24 ;
default:
return NULL ;
}
}
static int F_21 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
F_10 () ;
F_22 () ;
V_2 -> V_15 |= V_16 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
F_12 ( & V_11 -> V_12 ) ;
F_12 ( & V_11 -> V_24 ) ;
F_13 () ;
F_24 () ;
}
static int T_3 F_25 ( void )
{
int V_25 ;
V_25 = F_26 ( & V_26 ) ;
if ( ! V_25 ) {
V_25 = F_26 ( & V_27 ) ;
if ( V_25 )
F_27 ( & V_26 ) ;
}
return V_25 ;
}
static void T_4 F_28 ( void )
{
F_27 ( & V_26 ) ;
F_27 ( & V_27 ) ;
}
