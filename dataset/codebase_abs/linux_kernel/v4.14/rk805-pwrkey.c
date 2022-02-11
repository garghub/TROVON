static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 , V_5 , 1 ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static T_1 F_4 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 , V_5 , 0 ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_3 * V_4 ;
int V_9 , V_10 ;
int V_11 ;
V_4 = F_6 ( & V_8 -> V_12 ) ;
if ( ! V_4 ) {
F_7 ( & V_8 -> V_12 , L_1 ) ;
return - V_13 ;
}
V_4 -> V_14 = L_2 ;
V_4 -> V_15 = L_3 ;
V_4 -> V_16 . V_17 = V_18 ;
F_8 ( V_4 , V_19 , V_5 ) ;
V_9 = F_9 ( V_8 , 0 ) ;
if ( V_9 < 0 ) {
F_7 ( & V_8 -> V_12 , L_4 , V_9 ) ;
return V_9 ;
}
V_10 = F_9 ( V_8 , 1 ) ;
if ( V_10 < 0 ) {
F_7 ( & V_8 -> V_12 , L_5 , V_10 ) ;
return V_10 ;
}
V_11 = F_10 ( & V_4 -> V_12 , V_9 ,
F_1 ,
V_20 | V_21 ,
L_6 , V_4 ) ;
if ( V_11 < 0 ) {
F_7 ( & V_8 -> V_12 , L_7 , V_11 ) ;
return V_11 ;
}
V_11 = F_10 ( & V_4 -> V_12 , V_10 ,
F_4 ,
V_22 | V_21 ,
L_8 , V_4 ) ;
if ( V_11 < 0 ) {
F_7 ( & V_8 -> V_12 , L_9 , V_11 ) ;
return V_11 ;
}
V_11 = F_11 ( V_4 ) ;
if ( V_11 ) {
F_7 ( & V_8 -> V_12 , L_10 , V_11 ) ;
return V_11 ;
}
F_12 ( V_8 , V_4 ) ;
F_13 ( & V_8 -> V_12 , true ) ;
return 0 ;
}
