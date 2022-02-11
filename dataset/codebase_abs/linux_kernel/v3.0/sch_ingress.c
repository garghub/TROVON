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
static struct V_9 * * F_7 ( struct V_1 * V_2 , unsigned long V_6 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
return & V_11 -> V_12 ;
}
static int F_9 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_15 V_16 ;
int V_17 ;
V_17 = F_10 ( V_14 , V_11 -> V_12 , & V_16 ) ;
F_11 ( V_2 , V_14 ) ;
switch ( V_17 ) {
case V_18 :
V_17 = V_18 ;
V_2 -> V_19 . V_20 ++ ;
break;
case V_21 :
case V_22 :
V_17 = V_21 ;
break;
case V_23 :
case V_24 :
V_14 -> V_25 = F_3 ( V_16 . V_4 ) ;
default:
V_17 = V_24 ;
break;
}
return V_17 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
F_13 ( & V_11 -> V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_26 * V_27 ;
V_27 = F_15 ( V_14 , V_28 ) ;
if ( V_27 == NULL )
goto V_29;
F_16 ( V_14 , V_27 ) ;
return V_14 -> V_30 ;
V_29:
F_17 ( V_14 , V_27 ) ;
return - 1 ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_31 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_31 ) ;
}
