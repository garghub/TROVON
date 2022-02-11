static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
const struct V_5 * V_6 = V_3 ;
unsigned long V_7 , V_8 ;
V_8 = V_9 + F_2 ( V_6 -> V_10 ) + 1 ;
do {
F_3 ( V_6 -> V_11 , ! V_6 -> V_12 ) ;
F_4 ( V_6 -> V_13 ) ;
V_7 = V_9 + F_2 ( V_6 -> V_14 ) + 1 ;
while ( F_5 ( V_9 , V_7 ) ) {
int V_15 = ! ! F_6 ( V_6 -> V_16 ) ;
if ( V_15 == V_6 -> V_17 ) {
return 0 ;
}
F_7 ( 50 , 200 ) ;
}
F_3 ( V_6 -> V_11 , V_6 -> V_12 ) ;
F_7 ( V_6 -> V_14 , V_6 -> V_14 * 2 ) ;
} while ( F_5 ( V_9 , V_8 ) );
F_3 ( V_6 -> V_11 , V_6 -> V_12 ) ;
F_4 ( V_6 -> V_13 ) ;
F_8 ( & V_2 -> V_18 , L_1 ) ;
return - V_19 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 ,
T_1 V_4 )
{
const struct V_5 * V_6 = V_3 ;
F_3 ( V_6 -> V_11 , V_6 -> V_12 ) ;
F_4 ( V_6 -> V_13 ) ;
return 0 ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_22 * V_18 = & V_21 -> V_18 ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_23 * V_26 ;
struct V_5 * V_6 ;
enum V_27 V_28 ;
unsigned long V_29 ;
int V_30 ;
if ( ! V_24 ) {
F_8 ( V_18 , L_2 ) ;
return - V_31 ;
}
if ( V_18 -> V_32 ) {
F_8 ( V_18 , L_3 ) ;
return - V_33 ;
}
V_6 = F_11 ( V_18 , sizeof( * V_6 ) , V_34 ) ;
if ( ! V_6 ) {
F_8 ( V_18 , L_4 ) ;
return - V_35 ;
}
F_12 ( V_21 , V_6 ) ;
V_30 = F_13 ( V_24 , L_5 , 0 , & V_28 ) ;
if ( ! F_14 ( V_30 ) ) {
if ( V_30 != - V_36 )
F_8 ( V_18 , L_6 ) ;
return V_30 ;
}
V_6 -> V_11 = V_30 ;
V_6 -> V_12 = ! ! ( V_28 & V_37 ) ;
V_29 = ( V_28 & V_37 ) ?
V_38 : V_39 ;
V_30 = F_15 ( V_18 , V_6 -> V_11 , V_29 ,
L_5 ) ;
if ( V_30 ) {
if ( V_30 != - V_36 )
F_8 ( V_18 , L_7 ) ;
return V_30 ;
}
V_30 = F_13 ( V_24 , L_8 , 0 , & V_28 ) ;
if ( ! F_14 ( V_30 ) ) {
if ( V_30 != - V_36 )
F_8 ( V_18 , L_9 ) ;
return V_30 ;
}
V_6 -> V_16 = V_30 ;
V_6 -> V_17 = ! ! ( V_28 & V_37 ) ;
V_30 = F_15 ( V_18 , V_6 -> V_16 , V_40 ,
L_10 ) ;
if ( V_30 ) {
if ( V_30 != - V_36 )
F_8 ( V_18 , L_11 ) ;
return V_30 ;
}
if ( F_14 ( F_16 ( V_24 , L_8 , 1 ) ) ) {
F_8 ( V_18 , L_12 ) ;
return - V_33 ;
}
if ( F_17 ( V_24 , L_13 , & V_6 -> V_13 ) )
V_6 -> V_13 = 10 ;
if ( F_17 ( V_24 , L_14 , & V_6 -> V_14 ) )
V_6 -> V_14 = 3000 ;
if ( F_17 ( V_24 , L_15 , & V_6 -> V_10 ) )
V_6 -> V_10 = 50000 ;
V_26 = F_18 ( V_24 , L_16 , 0 ) ;
if ( ! V_26 ) {
F_8 ( V_18 , L_17 ) ;
return - V_33 ;
}
V_6 -> V_41 = F_19 ( V_26 ) ;
if ( ! V_6 -> V_41 ) {
F_8 ( V_18 , L_18 ) ;
return - V_33 ;
}
V_6 -> V_42 = F_20 ( V_6 -> V_41 , V_18 , V_6 , 0 , 0 , 0 ,
F_1 ,
F_9 ) ;
if ( ! V_6 -> V_42 ) {
F_8 ( V_18 , L_19 ) ;
V_30 = - V_31 ;
F_21 ( V_6 -> V_41 ) ;
}
return V_30 ;
}
static int F_22 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = F_23 ( V_21 ) ;
F_24 ( V_6 -> V_42 ) ;
F_21 ( V_6 -> V_41 ) ;
return 0 ;
}
