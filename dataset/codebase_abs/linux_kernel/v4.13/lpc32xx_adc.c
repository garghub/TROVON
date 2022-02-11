static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 ,
int * V_6 ,
long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
if ( V_7 == V_11 ) {
F_3 ( & V_2 -> V_12 ) ;
V_10 = F_4 ( V_9 -> V_13 ) ;
if ( V_10 ) {
F_5 ( & V_2 -> V_12 ) ;
return V_10 ;
}
F_6 ( V_14 | ( V_4 -> V_15 ) |
V_16 | V_17 ,
F_7 ( V_9 -> V_18 ) ) ;
F_6 ( V_19 | V_20 ,
F_8 ( V_9 -> V_18 ) ) ;
F_9 ( & V_9 -> V_21 ) ;
F_10 ( V_9 -> V_13 ) ;
* V_5 = V_9 -> V_22 ;
F_5 ( & V_2 -> V_12 ) ;
return V_23 ;
}
return - V_24 ;
}
static T_1 F_11 ( int V_25 , void * V_26 )
{
struct V_8 * V_9 = V_26 ;
V_9 -> V_22 = F_12 ( F_13 ( V_9 -> V_18 ) ) &
V_27 ;
F_14 ( & V_9 -> V_21 ) ;
return V_28 ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_8 * V_9 = NULL ;
struct V_31 * V_32 ;
int V_33 = - V_34 ;
struct V_1 * V_35 = NULL ;
int V_25 ;
V_32 = F_16 ( V_30 , V_36 , 0 ) ;
if ( ! V_32 ) {
F_17 ( & V_30 -> V_37 , L_1 ) ;
return - V_38 ;
}
V_35 = F_18 ( & V_30 -> V_37 , sizeof( * V_9 ) ) ;
if ( ! V_35 )
return - V_39 ;
V_9 = F_2 ( V_35 ) ;
V_9 -> V_18 = F_19 ( & V_30 -> V_37 , V_32 -> V_40 ,
F_20 ( V_32 ) ) ;
if ( ! V_9 -> V_18 ) {
F_17 ( & V_30 -> V_37 , L_2 ) ;
return - V_41 ;
}
V_9 -> V_13 = F_21 ( & V_30 -> V_37 , NULL ) ;
if ( F_22 ( V_9 -> V_13 ) ) {
F_17 ( & V_30 -> V_37 , L_3 ) ;
return F_23 ( V_9 -> V_13 ) ;
}
V_25 = F_24 ( V_30 , 0 ) ;
if ( V_25 <= 0 ) {
F_17 ( & V_30 -> V_37 , L_4 ) ;
return - V_38 ;
}
V_33 = F_25 ( & V_30 -> V_37 , V_25 , F_11 , 0 ,
V_42 , V_9 ) ;
if ( V_33 < 0 ) {
F_17 ( & V_30 -> V_37 , L_5 ) ;
return V_33 ;
}
F_26 ( V_30 , V_35 ) ;
F_27 ( & V_9 -> V_21 ) ;
V_35 -> V_43 = V_42 ;
V_35 -> V_37 . V_44 = & V_30 -> V_37 ;
V_35 -> V_45 = & V_46 ;
V_35 -> V_47 = V_48 ;
V_35 -> V_49 = V_50 ;
V_35 -> V_51 = F_28 ( V_50 ) ;
V_33 = F_29 ( & V_30 -> V_37 , V_35 ) ;
if ( V_33 )
return V_33 ;
F_30 ( & V_30 -> V_37 , L_6 , V_25 ) ;
return 0 ;
}
