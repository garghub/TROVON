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
struct V_14 *
F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
V_6 = V_8 -> V_9 ;
if ( V_6 == NULL ) {
F_3 ( V_2 -> V_10 -> V_10 ,
L_2 ) ;
return NULL ;
}
return & V_6 -> V_13 ;
}
static enum V_15
F_5 ( struct V_1 * V_2 , bool V_16 )
{
enum V_15 V_17 = V_18 ;
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
V_6 = V_8 -> V_9 ;
if ( V_6 == NULL ) {
F_3 ( V_2 -> V_10 -> V_10 ,
L_3 ) ;
return V_17 ;
}
V_4 = V_6 -> V_11 ;
if ( V_4 && V_4 -> V_19 )
return V_4 -> V_19 ( & V_6 -> V_13 , V_2 ) ;
F_3 ( V_2 -> V_10 -> V_10 , L_4 ) ;
return V_17 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
int F_9 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_7 * V_24 ;
struct V_25 * V_26 ;
struct V_5 * V_27 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
int V_30 ;
V_27 = F_10 ( V_21 -> V_10 , sizeof( * V_27 ) , V_31 ) ;
if ( V_27 == NULL )
return - V_32 ;
V_29 = F_11 ( V_23 ) ;
if ( ! V_29 || ! F_12 ( V_29 ) ) {
F_3 ( V_21 -> V_10 , L_5 ) ;
return - V_33 ;
}
if ( V_29 -> V_10 . V_26 == NULL ) {
F_3 ( V_21 -> V_10 , L_6 ) ;
return - V_33 ;
}
V_26 =
F_13 ( F_14 ( V_29 -> V_10 . V_26 ) ) ;
V_30 = V_26 -> V_34 ( V_29 , V_21 , V_27 ) ;
if ( V_30 ) {
F_3 ( V_21 -> V_10 , L_7 ) ;
return V_30 ;
}
V_27 -> V_13 . V_35 = 1 ;
V_27 -> V_13 . V_36 = 0 ;
V_30 = F_15 ( V_21 , & V_27 -> V_13 , & V_37 ,
V_38 , NULL ) ;
if ( V_30 )
return V_30 ;
F_16 ( & V_27 -> V_13 ,
& V_39 ) ;
V_24 = F_10 ( V_21 -> V_10 , sizeof( * V_24 ) ,
V_31 ) ;
if ( ! V_24 ) {
V_30 = - V_32 ;
goto V_40;
}
V_2 = & V_24 -> V_2 ;
F_17 ( V_2 , & V_41 ) ;
V_30 = F_18 ( V_21 , V_2 , & V_42 ,
V_43 ) ;
if ( V_30 < 0 ) {
F_3 ( V_21 -> V_10 , L_8 ) ;
goto V_40;
}
V_30 = F_19 ( V_2 , & V_27 -> V_13 ) ;
if ( V_30 < 0 ) {
F_3 ( V_21 -> V_10 , L_9 ) ;
F_7 ( V_2 ) ;
goto V_44;
}
V_24 -> V_9 = V_27 ;
return 0 ;
V_44:
F_8 ( V_2 ) ;
V_40:
F_20 ( & V_27 -> V_13 ) ;
return V_30 ;
}
