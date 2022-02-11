static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
if ( V_8 -> type == V_13 && V_8 -> V_14 == V_15 )
F_3 ( V_16 , * V_9 ) ;
if ( ( V_12 -> V_17 & V_18 ) && V_8 -> V_19 == 0x00090007 )
return - 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , T_1 V_20 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
struct V_21 * V_22 ;
if ( ! ( V_2 -> V_23 & V_24 ) || ! V_6 -> V_25 ||
! V_8 -> type )
return 0 ;
V_22 = V_6 -> V_25 -> V_22 ;
if ( V_12 -> V_17 & V_26 ) {
if ( V_8 -> type == V_13 && V_8 -> V_14 == V_15 ) {
V_12 -> V_27 = V_20 ;
return 1 ;
}
if ( V_8 -> V_19 == 0x000100b8 ) {
F_5 ( V_22 , V_13 , V_20 ? V_16 :
V_15 , V_12 -> V_27 ) ;
return 1 ;
}
}
if ( ( V_12 -> V_17 & V_18 ) && V_8 -> V_19 == 0x00090007 ) {
V_12 -> V_28 = ! ! V_20 ;
return 1 ;
}
if ( V_8 -> V_14 == V_15 && V_12 -> V_28 ) {
F_5 ( V_22 , V_8 -> type , V_16 , V_20 ) ;
return 1 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , const struct V_29 * V_30 )
{
struct V_11 * V_12 ;
int V_31 ;
V_12 = F_7 ( sizeof( * V_12 ) , V_32 ) ;
if ( V_12 == NULL ) {
F_8 ( V_2 , L_1 ) ;
V_31 = - V_33 ;
goto V_34;
}
V_12 -> V_17 = V_30 -> V_35 ;
F_9 ( V_2 , V_12 ) ;
V_31 = F_10 ( V_2 ) ;
if ( V_31 ) {
F_8 ( V_2 , L_2 ) ;
goto V_34;
}
V_31 = F_11 ( V_2 , V_36 ) ;
if ( V_31 ) {
F_8 ( V_2 , L_3 ) ;
goto V_34;
}
return 0 ;
V_34:
F_12 ( V_12 ) ;
return V_31 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
F_12 ( V_12 ) ;
}
