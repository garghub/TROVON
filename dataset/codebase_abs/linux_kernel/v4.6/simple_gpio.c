static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( unsigned int V_4 )
{
return 1 << ( 8 - 1 - V_4 ) ;
}
static int F_4 ( struct V_5 * V_6 , unsigned int V_7 )
{
struct V_2 * V_3 = F_5 ( V_6 ) ;
return ! ! ( F_6 ( V_3 -> V_8 ) & F_3 ( V_7 ) ) ;
}
static void F_7 ( struct V_5 * V_6 , unsigned int V_7 , int V_9 )
{
struct V_2 * V_3 = F_5 ( V_6 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
unsigned long V_11 ;
F_8 ( & V_10 -> V_12 , V_11 ) ;
if ( V_9 )
V_10 -> V_13 |= F_3 ( V_7 ) ;
else
V_10 -> V_13 &= ~ F_3 ( V_7 ) ;
F_9 ( V_3 -> V_8 , V_10 -> V_13 ) ;
F_10 ( & V_10 -> V_12 , V_11 ) ;
}
static int F_11 ( struct V_5 * V_6 , unsigned int V_7 )
{
return 0 ;
}
static int F_12 ( struct V_5 * V_6 , unsigned int V_7 , int V_9 )
{
F_7 ( V_6 , V_7 , V_9 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
V_10 -> V_13 = F_6 ( V_3 -> V_8 ) ;
}
static int T_2 F_14 ( struct V_14 * V_15 )
{
int V_16 ;
struct V_1 * V_10 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
V_10 = F_15 ( sizeof( * V_10 ) , V_17 ) ;
if ( ! V_10 )
return - V_18 ;
F_16 ( & V_10 -> V_12 ) ;
V_3 = & V_10 -> V_3 ;
V_6 = & V_3 -> V_6 ;
V_3 -> V_19 = F_13 ;
V_6 -> V_20 = 8 ;
V_6 -> V_21 = F_11 ;
V_6 -> V_22 = F_12 ;
V_6 -> V_23 = F_4 ;
V_6 -> V_24 = F_7 ;
V_16 = F_17 ( V_15 , V_3 ) ;
if ( V_16 )
goto V_25;
return 0 ;
V_25:
F_18 ( V_10 ) ;
return V_16 ;
}
void T_2 F_19 ( const char * V_26 )
{
struct V_14 * V_15 ;
F_20 (np, NULL, compatible) {
int V_16 ;
struct V_27 V_28 ;
V_16 = F_21 ( V_15 , 0 , & V_28 ) ;
if ( V_16 )
goto V_25;
switch ( F_22 ( & V_28 ) ) {
case 1 :
V_16 = F_14 ( V_15 ) ;
if ( V_16 )
goto V_25;
break;
default:
V_16 = - V_29 ;
goto V_25;
}
continue;
V_25:
F_23 ( L_1 ,
V_15 -> V_30 , V_16 ) ;
}
}
