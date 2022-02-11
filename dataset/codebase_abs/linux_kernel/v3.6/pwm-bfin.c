static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
if ( V_4 -> V_8 >= F_2 ( V_9 ) )
return - V_10 ;
V_6 = F_3 ( sizeof( * V_6 ) , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
V_6 -> V_13 = V_9 [ V_4 -> V_8 ] ;
V_7 = F_4 ( V_6 -> V_13 , NULL ) ;
if ( V_7 ) {
F_5 ( V_6 ) ;
return V_7 ;
}
F_6 ( V_4 , V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_8 ( V_4 ) ;
if ( V_6 ) {
F_9 ( V_6 -> V_13 ) ;
F_5 ( V_6 ) ;
}
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_14 , int V_15 )
{
struct V_5 * V_6 = F_8 ( V_4 ) ;
unsigned long V_16 , V_17 ;
unsigned long long V_18 ;
if ( V_14 < 0 || V_14 > V_15 )
return - V_10 ;
V_18 = ( unsigned long long ) F_11 () * V_15 ;
F_12 ( V_18 , V_19 ) ;
V_16 = V_18 ;
V_18 = ( unsigned long long ) V_16 * V_14 ;
F_12 ( V_18 , V_15 ) ;
V_17 = V_16 - V_18 ;
if ( V_17 >= V_16 )
V_17 = V_16 - 1 ;
F_13 ( V_6 -> V_13 , V_20 | V_21 ) ;
F_14 ( V_6 -> V_13 , V_17 ) ;
F_15 ( V_6 -> V_13 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_8 ( V_4 ) ;
F_17 ( V_6 -> V_13 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_8 ( V_4 ) ;
F_19 ( V_6 -> V_13 ) ;
}
static int F_20 ( struct V_22 * V_23 )
{
struct V_24 * V_4 ;
int V_7 ;
V_4 = F_21 ( & V_23 -> V_25 , sizeof( * V_4 ) , V_11 ) ;
if ( ! V_4 ) {
F_22 ( & V_23 -> V_25 , L_1 ) ;
return - V_12 ;
}
F_23 ( V_23 , V_4 ) ;
V_4 -> V_2 . V_25 = & V_23 -> V_25 ;
V_4 -> V_2 . V_26 = & V_27 ;
V_4 -> V_2 . V_28 = - 1 ;
V_4 -> V_2 . V_29 = 12 ;
V_7 = F_24 ( & V_4 -> V_2 ) ;
if ( V_7 < 0 ) {
F_22 ( & V_23 -> V_25 , L_2 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int T_1 F_25 ( struct V_22 * V_23 )
{
struct V_24 * V_4 = F_26 ( V_23 ) ;
return F_27 ( & V_4 -> V_2 ) ;
}
