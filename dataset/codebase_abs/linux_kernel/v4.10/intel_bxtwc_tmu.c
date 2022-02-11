static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned int V_5 ;
F_2 ( V_4 -> V_6 , V_7 , & V_5 ) ;
if ( V_5 & V_8 ) {
F_3 ( V_4 -> V_6 , V_7 , V_5 ) ;
return V_9 ;
}
return V_10 ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 -> V_15 . V_16 ) ;
struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_19 , V_20 , V_1 ;
V_4 = F_6 ( & V_12 -> V_15 , sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 )
return - V_22 ;
V_4 -> V_15 = & V_12 -> V_15 ;
V_4 -> V_6 = V_14 -> V_6 ;
V_1 = F_7 ( V_12 , 0 ) ;
if ( V_1 < 0 ) {
F_8 ( & V_12 -> V_15 , L_1 , V_1 ) ;
return V_1 ;
}
V_18 = V_14 -> V_23 ;
V_20 = F_9 ( V_18 , V_1 ) ;
if ( V_20 < 0 ) {
F_8 ( & V_12 -> V_15 ,
L_2 , V_1 ) ;
return V_20 ;
}
V_19 = F_10 ( & V_12 -> V_15 , V_20 ,
NULL , F_1 ,
V_24 , L_3 , V_4 ) ;
if ( V_19 ) {
F_8 ( & V_12 -> V_15 , L_4 ,
V_19 , V_20 ) ;
return V_19 ;
}
V_4 -> V_1 = V_20 ;
F_11 ( V_4 -> V_6 , V_25 ,
V_26 , 0 ) ;
F_11 ( V_4 -> V_6 , V_27 ,
V_28 , 0 ) ;
F_12 ( V_12 , V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_14 ( V_12 ) ;
unsigned int V_29 ;
F_2 ( V_4 -> V_6 , V_25 , & V_29 ) ;
F_3 ( V_4 -> V_6 , V_25 ,
V_29 | V_26 ) ;
F_2 ( V_4 -> V_6 , V_27 , & V_29 ) ;
F_3 ( V_4 -> V_6 , V_27 ,
V_29 | V_28 ) ;
return 0 ;
}
static int F_15 ( struct V_30 * V_15 )
{
struct V_3 * V_4 = F_5 ( V_15 ) ;
F_16 ( V_4 -> V_1 ) ;
return 0 ;
}
static int F_17 ( struct V_30 * V_15 )
{
struct V_3 * V_4 = F_5 ( V_15 ) ;
F_18 ( V_4 -> V_1 ) ;
return 0 ;
}
