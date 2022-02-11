static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 = F_2 ( V_4 -> V_6 ) ;
if ( V_5 ) {
F_3 ( V_4 -> V_7 , V_8 , false ) ;
F_3 ( V_4 -> V_7 , V_9 , true ) ;
} else {
F_3 ( V_4 -> V_7 , V_9 , false ) ;
F_3 ( V_4 -> V_7 , V_8 , true ) ;
}
return V_10 ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_1 , V_15 ;
V_4 = F_5 ( & V_12 -> V_16 , sizeof( struct V_3 ) ,
V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_14 = F_6 ( & V_12 -> V_16 , L_1 , V_19 ) ;
if ( F_7 ( V_14 ) ) {
F_8 ( & V_12 -> V_16 , L_2 ) ;
return F_9 ( V_14 ) ;
}
V_4 -> V_6 = V_14 ;
V_14 = F_6 ( & V_12 -> V_16 , L_3 , V_20 ) ;
if ( F_7 ( V_14 ) ) {
F_8 ( & V_12 -> V_16 , L_4 ) ;
return F_9 ( V_14 ) ;
}
V_4 -> V_21 = V_14 ;
V_4 -> V_7 = F_10 ( & V_12 -> V_16 , V_22 ) ;
if ( F_7 ( V_4 -> V_7 ) ) {
F_8 ( & V_12 -> V_16 , L_5 ) ;
return F_9 ( V_4 -> V_7 ) ;
}
V_15 = F_11 ( & V_12 -> V_16 , V_4 -> V_7 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_12 -> V_16 , L_6 ) ;
return V_15 ;
}
V_1 = F_12 ( V_4 -> V_6 ) ;
if ( V_1 < 0 ) {
F_8 ( & V_12 -> V_16 , L_7 ) ;
return V_1 ;
}
V_15 = F_13 ( & V_12 -> V_16 , V_1 , NULL , F_1 ,
V_23 | V_24 |
V_25 |
V_26 ,
V_12 -> V_27 , V_4 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_12 -> V_16 , L_8 ) ;
return V_15 ;
}
F_14 ( V_12 , V_4 ) ;
F_1 ( V_1 , V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_16 ( V_12 ) ;
F_17 ( V_4 -> V_21 , 0 ) ;
return 0 ;
}
