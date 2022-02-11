static int F_1 ( void * V_1 , int * V_2 )
{
struct V_3 * V_4 = V_1 ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_4 -> V_7 , V_8 , & V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( V_4 -> V_9 , L_1 , V_6 ) ;
return V_6 ;
}
if ( V_5 & V_10 )
* V_2 = V_11 ;
else if ( V_5 & V_12 )
* V_2 = V_13 ;
else
* V_2 = V_14 ;
return 0 ;
}
static T_1 F_4 ( int V_15 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_15 == V_4 -> V_16 )
F_5 ( V_4 -> V_9 , L_2 ) ;
else if ( V_15 == V_4 -> V_17 )
F_6 ( V_4 -> V_9 , L_3 ) ;
F_7 ( V_4 -> V_18 ,
V_19 ) ;
return V_20 ;
}
static int F_8 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
int V_6 ;
V_4 = F_9 ( & V_22 -> V_9 , sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_16 = F_10 ( V_22 , 0 ) ;
V_4 -> V_17 = F_10 ( V_22 , 1 ) ;
if ( ( V_4 -> V_16 < 0 ) || ( V_4 -> V_17 < 0 ) ) {
F_3 ( & V_22 -> V_9 , L_4 ) ;
return - V_25 ;
}
V_4 -> V_9 = & V_22 -> V_9 ;
V_4 -> V_7 = F_11 ( V_22 -> V_9 . V_26 , NULL ) ;
if ( ! V_4 -> V_7 ) {
F_3 ( & V_22 -> V_9 , L_5 ) ;
return - V_27 ;
}
F_12 ( & V_22 -> V_9 , V_22 -> V_9 . V_26 ) ;
V_4 -> V_18 = F_13 ( & V_22 -> V_9 , 0 ,
V_4 , & V_28 ) ;
if ( F_14 ( V_4 -> V_18 ) ) {
V_6 = F_15 ( V_4 -> V_18 ) ;
F_3 ( & V_22 -> V_9 , L_6 ,
V_6 ) ;
return V_6 ;
}
V_6 = F_16 ( & V_22 -> V_9 , V_4 -> V_16 , NULL ,
F_4 ,
V_29 | V_30 ,
F_17 ( & V_22 -> V_9 ) , V_4 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_22 -> V_9 , L_7 , V_6 ) ;
return V_6 ;
}
V_6 = F_16 ( & V_22 -> V_9 , V_4 -> V_17 , NULL ,
F_4 ,
V_29 | V_30 ,
F_17 ( & V_22 -> V_9 ) , V_4 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_22 -> V_9 , L_8 , V_6 ) ;
return V_6 ;
}
F_18 ( V_22 , V_4 ) ;
return 0 ;
}
