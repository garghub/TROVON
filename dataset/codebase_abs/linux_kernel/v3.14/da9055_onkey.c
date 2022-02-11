static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_4 -> V_6 ,
L_1 , V_3 ) ;
} else {
V_3 &= V_7 ;
if ( ! V_3 ) {
F_4 ( V_2 -> V_8 , V_9 , 0 ) ;
F_5 ( V_2 -> V_8 ) ;
}
}
if ( V_3 )
F_6 ( & V_2 -> V_10 , F_7 ( 10 ) ) ;
}
static void F_8 ( struct V_11 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 , struct V_1 ,
V_10 . V_10 ) ;
F_1 ( V_2 ) ;
}
static T_1 F_10 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_4 ( V_2 -> V_8 , V_9 , 1 ) ;
F_5 ( V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
return V_14 ;
}
static int F_11 ( struct V_15 * V_16 )
{
struct V_4 * V_4 = F_12 ( V_16 -> V_6 . V_17 ) ;
struct V_1 * V_2 ;
struct V_18 * V_18 ;
int V_12 , V_19 ;
V_12 = F_13 ( V_16 , L_2 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_16 -> V_6 ,
L_3 , V_12 ) ;
return - V_20 ;
}
V_2 = F_14 ( & V_16 -> V_6 , sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 ) {
F_3 ( & V_16 -> V_6 , L_4 ) ;
return - V_22 ;
}
V_18 = F_15 () ;
if ( ! V_18 ) {
F_3 ( & V_16 -> V_6 , L_4 ) ;
return - V_22 ;
}
V_2 -> V_8 = V_18 ;
V_2 -> V_4 = V_4 ;
V_18 -> V_23 = L_5 ;
V_18 -> V_24 = L_6 ;
V_18 -> V_6 . V_17 = & V_16 -> V_6 ;
V_18 -> V_25 [ 0 ] = F_16 ( V_26 ) ;
F_17 ( V_9 , V_18 -> V_27 ) ;
F_18 ( & V_2 -> V_10 , F_8 ) ;
V_12 = F_19 ( V_4 -> V_28 , V_12 ) ;
V_19 = F_20 ( V_12 , NULL , F_10 ,
V_29 | V_30 ,
L_2 , V_2 ) ;
if ( V_19 < 0 ) {
F_3 ( & V_16 -> V_6 ,
L_7 ,
V_12 , V_19 ) ;
goto V_31;
}
V_19 = F_21 ( V_18 ) ;
if ( V_19 ) {
F_3 ( & V_16 -> V_6 , L_8 ,
V_19 ) ;
goto V_32;
}
F_22 ( V_16 , V_2 ) ;
return 0 ;
V_32:
F_23 ( V_12 , V_2 ) ;
F_24 ( & V_2 -> V_10 ) ;
V_31:
F_25 ( V_18 ) ;
return V_19 ;
}
static int F_26 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_27 ( V_16 ) ;
int V_12 = F_13 ( V_16 , L_2 ) ;
V_12 = F_19 ( V_2 -> V_4 -> V_28 , V_12 ) ;
F_23 ( V_12 , V_2 ) ;
F_24 ( & V_2 -> V_10 ) ;
F_28 ( V_2 -> V_8 ) ;
return 0 ;
}
