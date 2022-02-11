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
static int F_9 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_15 V_16 ;
struct V_9 * V_17 = F_10 ( V_11 -> V_12 ) ;
int V_18 ;
V_18 = F_11 ( V_14 , V_17 , & V_16 ) ;
F_12 ( V_2 , V_14 ) ;
switch ( V_18 ) {
case V_19 :
V_18 = V_19 ;
F_13 ( V_2 ) ;
break;
case V_20 :
case V_21 :
V_18 = V_20 ;
break;
case V_22 :
case V_23 :
V_14 -> V_24 = F_3 ( V_16 . V_4 ) ;
default:
V_18 = V_23 ;
break;
}
return V_18 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
F_15 () ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
F_17 ( & V_11 -> V_12 ) ;
F_18 () ;
}
static int F_19 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_25 * V_27 ;
V_27 = F_20 ( V_14 , V_28 ) ;
if ( V_27 == NULL )
goto V_29;
return F_21 ( V_14 , V_27 ) ;
V_29:
F_22 ( V_14 , V_27 ) ;
return - 1 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_30 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_30 ) ;
}
