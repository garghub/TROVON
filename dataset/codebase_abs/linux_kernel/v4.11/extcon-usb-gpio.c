static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ,
struct V_5 ,
V_7 ) ;
V_3 = V_6 -> V_8 ?
F_4 ( V_6 -> V_8 ) : 1 ;
V_4 = V_6 -> V_9 ?
F_4 ( V_6 -> V_9 ) : V_3 ;
if ( V_3 )
F_5 ( V_6 -> V_10 , V_11 , false ) ;
if ( ! V_4 )
F_5 ( V_6 -> V_10 , V_12 , false ) ;
if ( ! V_3 ) {
F_5 ( V_6 -> V_10 , V_11 , true ) ;
} else {
if ( V_4 )
F_5 ( V_6 -> V_10 , V_12 , true ) ;
}
}
static T_1 F_6 ( int V_13 , void * V_14 )
{
struct V_5 * V_6 = V_14 ;
F_7 ( V_15 , & V_6 -> V_7 ,
V_6 -> V_16 ) ;
return V_17 ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_5 * V_6 ;
int V_25 ;
if ( ! V_23 && ! F_9 ( V_21 ) )
return - V_26 ;
V_6 = F_10 ( & V_19 -> V_21 , sizeof( * V_6 ) , V_27 ) ;
if ( ! V_6 )
return - V_28 ;
V_6 -> V_21 = V_21 ;
V_6 -> V_8 = F_11 ( & V_19 -> V_21 , L_1 , V_29 ) ;
V_6 -> V_9 = F_11 ( & V_19 -> V_21 , L_2 ,
V_29 ) ;
if ( ! V_6 -> V_8 && ! V_6 -> V_9 ) {
F_12 ( V_21 , L_3 ) ;
return - V_30 ;
}
if ( F_13 ( V_6 -> V_8 ) )
return F_14 ( V_6 -> V_8 ) ;
if ( F_13 ( V_6 -> V_9 ) )
return F_14 ( V_6 -> V_9 ) ;
V_6 -> V_10 = F_15 ( V_21 , V_31 ) ;
if ( F_13 ( V_6 -> V_10 ) ) {
F_12 ( V_21 , L_4 ) ;
return - V_28 ;
}
V_25 = F_16 ( V_21 , V_6 -> V_10 ) ;
if ( V_25 < 0 ) {
F_12 ( V_21 , L_5 ) ;
return V_25 ;
}
if ( V_6 -> V_8 )
V_25 = F_17 ( V_6 -> V_8 ,
V_32 * 1000 ) ;
if ( ! V_25 && V_6 -> V_9 )
V_25 = F_17 ( V_6 -> V_9 ,
V_32 * 1000 ) ;
if ( V_25 < 0 )
V_6 -> V_16 = F_18 ( V_32 ) ;
F_19 ( & V_6 -> V_7 , F_1 ) ;
if ( V_6 -> V_8 ) {
V_6 -> V_33 = F_20 ( V_6 -> V_8 ) ;
if ( V_6 -> V_33 < 0 ) {
F_12 ( V_21 , L_6 ) ;
return V_6 -> V_33 ;
}
V_25 = F_21 ( V_21 , V_6 -> V_33 , NULL ,
F_6 ,
V_34 |
V_35 | V_36 ,
V_19 -> V_37 , V_6 ) ;
if ( V_25 < 0 ) {
F_12 ( V_21 , L_7 ) ;
return V_25 ;
}
}
if ( V_6 -> V_9 ) {
V_6 -> V_38 = F_20 ( V_6 -> V_9 ) ;
if ( V_6 -> V_38 < 0 ) {
F_12 ( V_21 , L_8 ) ;
return V_6 -> V_38 ;
}
V_25 = F_21 ( V_21 , V_6 -> V_38 , NULL ,
F_6 ,
V_34 |
V_35 | V_36 ,
V_19 -> V_37 , V_6 ) ;
if ( V_25 < 0 ) {
F_12 ( V_21 , L_9 ) ;
return V_25 ;
}
}
F_22 ( V_19 , V_6 ) ;
F_23 ( V_21 , true ) ;
F_1 ( & V_6 -> V_7 . V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = F_25 ( V_19 ) ;
F_26 ( & V_6 -> V_7 ) ;
F_23 ( & V_19 -> V_21 , false ) ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = F_28 ( V_21 ) ;
int V_25 = 0 ;
if ( F_29 ( V_21 ) ) {
if ( V_6 -> V_8 ) {
V_25 = F_30 ( V_6 -> V_33 ) ;
if ( V_25 )
return V_25 ;
}
if ( V_6 -> V_9 ) {
V_25 = F_30 ( V_6 -> V_38 ) ;
if ( V_25 ) {
if ( V_6 -> V_8 )
F_31 ( V_6 -> V_33 ) ;
return V_25 ;
}
}
}
if ( V_6 -> V_8 )
F_32 ( V_6 -> V_33 ) ;
if ( V_6 -> V_9 )
F_32 ( V_6 -> V_38 ) ;
if ( ! F_29 ( V_21 ) )
F_33 ( V_21 ) ;
return V_25 ;
}
static int F_34 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = F_28 ( V_21 ) ;
int V_25 = 0 ;
if ( ! F_29 ( V_21 ) )
F_35 ( V_21 ) ;
if ( F_29 ( V_21 ) ) {
if ( V_6 -> V_8 ) {
V_25 = F_31 ( V_6 -> V_33 ) ;
if ( V_25 )
return V_25 ;
}
if ( V_6 -> V_9 ) {
V_25 = F_31 ( V_6 -> V_38 ) ;
if ( V_25 ) {
if ( V_6 -> V_8 )
F_30 ( V_6 -> V_33 ) ;
return V_25 ;
}
}
}
if ( V_6 -> V_8 )
F_36 ( V_6 -> V_33 ) ;
if ( V_6 -> V_9 )
F_36 ( V_6 -> V_38 ) ;
if ( ! F_29 ( V_21 ) )
F_7 ( V_15 ,
& V_6 -> V_7 , 0 ) ;
return V_25 ;
}
