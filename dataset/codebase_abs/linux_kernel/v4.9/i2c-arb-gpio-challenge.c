static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 , V_7 ;
V_7 = V_8 + F_3 ( V_5 -> V_9 ) + 1 ;
do {
F_4 ( V_5 -> V_10 , ! V_5 -> V_11 ) ;
F_5 ( V_5 -> V_12 ) ;
V_6 = V_8 + F_3 ( V_5 -> V_13 ) + 1 ;
while ( F_6 ( V_8 , V_6 ) ) {
int V_14 = ! ! F_7 ( V_5 -> V_15 ) ;
if ( V_14 == V_5 -> V_16 ) {
return 0 ;
}
F_8 ( 50 , 200 ) ;
}
F_4 ( V_5 -> V_10 , V_5 -> V_11 ) ;
F_8 ( V_5 -> V_13 , V_5 -> V_13 * 2 ) ;
} while ( F_6 ( V_8 , V_7 ) );
F_4 ( V_5 -> V_10 , V_5 -> V_11 ) ;
F_5 ( V_5 -> V_12 ) ;
F_9 ( V_2 -> V_17 , L_1 ) ;
return - V_18 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
F_4 ( V_5 -> V_10 , V_5 -> V_11 ) ;
F_5 ( V_5 -> V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 )
{
struct V_21 * V_17 = & V_20 -> V_17 ;
struct V_22 * V_23 = V_17 -> V_24 ;
struct V_22 * V_25 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
enum V_26 V_27 ;
unsigned long V_28 ;
int V_29 ;
if ( ! V_23 ) {
F_9 ( V_17 , L_2 ) ;
return - V_30 ;
}
if ( F_12 ( V_17 ) ) {
F_9 ( V_17 , L_3 ) ;
return - V_31 ;
}
V_2 = F_13 ( NULL , V_17 , 1 , sizeof( * V_5 ) , V_32 ,
F_1 , F_10 ) ;
if ( ! V_2 )
return - V_33 ;
V_5 = F_2 ( V_2 ) ;
F_14 ( V_20 , V_2 ) ;
V_29 = F_15 ( V_23 , L_4 , 0 , & V_27 ) ;
if ( ! F_16 ( V_29 ) ) {
if ( V_29 != - V_34 )
F_9 ( V_17 , L_5 ) ;
return V_29 ;
}
V_5 -> V_10 = V_29 ;
V_5 -> V_11 = ! ! ( V_27 & V_35 ) ;
V_28 = ( V_27 & V_35 ) ?
V_36 : V_37 ;
V_29 = F_17 ( V_17 , V_5 -> V_10 , V_28 ,
L_4 ) ;
if ( V_29 ) {
if ( V_29 != - V_34 )
F_9 ( V_17 , L_6 ) ;
return V_29 ;
}
V_29 = F_15 ( V_23 , L_7 , 0 , & V_27 ) ;
if ( ! F_16 ( V_29 ) ) {
if ( V_29 != - V_34 )
F_9 ( V_17 , L_8 ) ;
return V_29 ;
}
V_5 -> V_15 = V_29 ;
V_5 -> V_16 = ! ! ( V_27 & V_35 ) ;
V_29 = F_17 ( V_17 , V_5 -> V_15 , V_38 ,
L_9 ) ;
if ( V_29 ) {
if ( V_29 != - V_34 )
F_9 ( V_17 , L_10 ) ;
return V_29 ;
}
if ( F_16 ( F_18 ( V_23 , L_7 , 1 ) ) ) {
F_9 ( V_17 , L_11 ) ;
return - V_31 ;
}
if ( F_19 ( V_23 , L_12 , & V_5 -> V_12 ) )
V_5 -> V_12 = 10 ;
if ( F_19 ( V_23 , L_13 , & V_5 -> V_13 ) )
V_5 -> V_13 = 3000 ;
if ( F_19 ( V_23 , L_14 , & V_5 -> V_9 ) )
V_5 -> V_9 = 50000 ;
V_25 = F_20 ( V_23 , L_15 , 0 ) ;
if ( ! V_25 ) {
F_9 ( V_17 , L_16 ) ;
return - V_31 ;
}
V_2 -> V_39 = F_21 ( V_25 ) ;
F_22 ( V_25 ) ;
if ( ! V_2 -> V_39 ) {
F_9 ( V_17 , L_17 ) ;
return - V_34 ;
}
V_29 = F_23 ( V_2 , 0 , 0 , 0 ) ;
if ( V_29 ) {
F_9 ( V_17 , L_18 ) ;
F_24 ( V_2 -> V_39 ) ;
}
return V_29 ;
}
static int F_25 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_26 ( V_20 ) ;
F_27 ( V_2 ) ;
F_24 ( V_2 -> V_39 ) ;
return 0 ;
}
