static void F_1 ( struct V_1 * V_2 )
{
bool V_3 ;
int V_4 ;
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ,
struct V_5 ,
V_7 ) ;
V_4 = F_4 ( V_6 -> V_8 , V_9 , & V_3 ) ;
if ( V_4 )
return;
F_5 ( V_6 -> V_10 , V_11 , ! V_3 ) ;
}
static T_1 F_6 ( int V_8 , void * V_12 )
{
struct V_5 * V_6 = V_12 ;
F_7 ( V_13 , & V_6 -> V_7 ,
V_6 -> V_14 ) ;
return V_15 ;
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
struct V_5 * V_6 ;
int V_4 ;
V_6 = F_9 ( V_19 , sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
return - V_21 ;
V_6 -> V_10 = F_10 ( V_19 , V_22 ) ;
if ( F_11 ( V_6 -> V_10 ) ) {
F_12 ( V_19 , L_1 ) ;
return - V_21 ;
}
V_4 = F_13 ( V_19 , V_6 -> V_10 ) ;
if ( V_4 < 0 ) {
F_12 ( V_19 , L_2 ) ;
return V_4 ;
}
V_6 -> V_14 = F_14 ( V_23 ) ;
F_15 ( & V_6 -> V_7 , F_1 ) ;
V_6 -> V_8 = F_16 ( V_17 , L_3 ) ;
if ( V_6 -> V_8 < 0 )
return V_6 -> V_8 ;
V_4 = F_17 ( V_19 , V_6 -> V_8 , NULL ,
F_6 ,
V_24 |
V_25 | V_26 ,
V_17 -> V_27 , V_6 ) ;
if ( V_4 < 0 ) {
F_12 ( V_19 , L_4 ) ;
return V_4 ;
}
F_18 ( V_17 , V_6 ) ;
F_19 ( V_19 , 1 ) ;
F_1 ( & V_6 -> V_7 . V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_21 ( V_17 ) ;
F_22 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = F_24 ( V_19 ) ;
int V_4 = 0 ;
if ( F_25 ( V_19 ) )
V_4 = F_26 ( V_6 -> V_8 ) ;
return V_4 ;
}
static int F_27 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = F_24 ( V_19 ) ;
int V_4 = 0 ;
if ( F_25 ( V_19 ) )
V_4 = F_28 ( V_6 -> V_8 ) ;
return V_4 ;
}
