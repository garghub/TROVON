static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
V_6 = V_8 -> V_9 ;
if ( V_6 == NULL ) {
F_3 ( V_2 -> V_10 -> V_10 ,
L_1 ) ;
return 0 ;
}
V_4 = V_6 -> V_11 ;
if ( V_4 -> V_12 == NULL )
return 0 ;
return V_4 -> V_12 ( & V_6 -> V_13 , V_2 ) ;
}
static enum V_14
F_4 ( struct V_1 * V_2 , bool V_15 )
{
enum V_14 V_16 = V_17 ;
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
V_6 = V_8 -> V_9 ;
if ( V_6 == NULL ) {
F_3 ( V_2 -> V_10 -> V_10 ,
L_2 ) ;
return V_16 ;
}
V_4 = V_6 -> V_11 ;
if ( V_4 && V_4 -> V_18 )
return V_4 -> V_18 ( & V_6 -> V_13 , V_2 ) ;
F_3 ( V_2 -> V_10 -> V_10 , L_3 ) ;
return V_16 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
int F_8 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_7 * V_23 ;
struct V_24 * V_25 ;
struct V_5 * V_26 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
int V_29 ;
V_26 = F_9 ( V_20 -> V_10 , sizeof( * V_26 ) , V_30 ) ;
if ( V_26 == NULL )
return - V_31 ;
V_28 = F_10 ( V_22 ) ;
if ( ! V_28 || ! F_11 ( V_28 ) ) {
F_3 ( V_20 -> V_10 , L_4 ) ;
return - V_32 ;
}
if ( V_28 -> V_10 . V_25 == NULL ) {
F_3 ( V_20 -> V_10 , L_5 ) ;
return - V_32 ;
}
V_25 =
F_12 ( F_13 ( V_28 -> V_10 . V_25 ) ) ;
V_29 = V_25 -> V_33 ( V_28 , V_20 , V_26 ) ;
if ( V_29 ) {
F_3 ( V_20 -> V_10 , L_6 ) ;
return V_29 ;
}
V_26 -> V_13 . V_34 = 1 ;
V_26 -> V_13 . V_35 = 0 ;
V_29 = F_14 ( V_20 , & V_26 -> V_13 , & V_36 ,
V_37 , NULL ) ;
if ( V_29 )
return V_29 ;
F_15 ( & V_26 -> V_13 ,
& V_38 ) ;
V_23 = F_9 ( V_20 -> V_10 , sizeof( * V_23 ) ,
V_30 ) ;
if ( ! V_23 ) {
V_29 = - V_31 ;
goto V_39;
}
V_2 = & V_23 -> V_2 ;
F_16 ( V_2 , & V_40 ) ;
V_29 = F_17 ( V_20 , V_2 , & V_41 ,
V_42 ) ;
if ( V_29 < 0 ) {
F_3 ( V_20 -> V_10 , L_7 ) ;
goto V_39;
}
V_29 = F_18 ( V_2 , & V_26 -> V_13 ) ;
if ( V_29 < 0 ) {
F_3 ( V_20 -> V_10 , L_8 ) ;
F_6 ( V_2 ) ;
goto V_43;
}
V_23 -> V_9 = V_26 ;
return 0 ;
V_43:
F_7 ( V_2 ) ;
V_39:
F_19 ( & V_26 -> V_13 ) ;
return V_29 ;
}
