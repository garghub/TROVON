static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 . V_7 ;
struct V_1 * V_8 = NULL ;
int V_9 ;
V_9 = F_2 ( V_5 , L_1 , 0 ) ;
if ( ! F_3 ( V_9 ) )
V_9 = - 1 ;
if ( V_9 != - 1 ) {
V_8 = F_4 ( & V_3 -> V_6 , sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
F_5 ( & V_3 -> V_6 , L_2 ) ;
else
V_8 -> V_11 = V_9 ;
}
return V_8 ;
}
static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_6 ( - V_12 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 . V_7 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_6 ;
int V_20 ;
V_6 = V_3 -> V_6 . V_21 ? V_3 -> V_6 . V_21 : & V_3 -> V_6 ;
V_14 = F_8 ( V_6 , sizeof( * V_18 ) ) ;
if ( F_9 ( V_14 ) ) {
V_20 = F_10 ( V_14 ) ;
F_11 ( & V_3 -> V_6 , L_3 ) ;
goto V_22;
}
V_16 = F_12 ( V_3 , V_23 , 0 ) ;
V_14 -> V_24 = F_13 ( & V_3 -> V_6 , V_16 ) ;
if ( F_9 ( V_14 -> V_24 ) ) {
V_20 = F_10 ( V_14 -> V_24 ) ;
F_11 ( & V_3 -> V_6 , L_4 , V_20 ) ;
goto V_25;
}
V_14 -> V_26 = L_5 ;
V_14 -> V_27 = & V_28 ;
V_14 -> V_29 = F_14 ( V_3 , 0 ) ;
V_14 -> V_30 = V_31 ;
V_18 = F_15 ( V_14 ) ;
V_18 -> V_32 = F_16 ( & V_3 -> V_6 , NULL ) ;
if ( F_9 ( V_18 -> V_32 ) ) {
V_20 = F_10 ( V_18 -> V_32 ) ;
F_11 ( & V_3 -> V_6 , L_6 ) ;
goto V_25;
}
V_20 = F_17 ( V_18 -> V_32 ) ;
if ( V_20 ) {
F_11 ( & V_3 -> V_6 , L_7 ) ;
goto V_25;
}
V_20 = F_18 ( V_18 -> V_32 , 50000000 ) ;
if ( V_20 )
F_11 ( & V_3 -> V_6 , L_8 ,
F_19 ( V_18 -> V_32 ) ) ;
if ( V_5 ) {
V_18 -> V_33 = F_1 ( V_3 ) ;
if ( F_9 ( V_18 -> V_33 ) ) {
F_5 ( & V_3 -> V_6 , L_9 ) ;
goto V_34;
}
} else {
V_18 -> V_33 = F_20 ( & V_3 -> V_6 ) ;
}
if ( V_18 -> V_33 && V_18 -> V_33 -> V_11 >= 0 ) {
V_20 = F_21 ( V_14 -> V_35 ,
V_18 -> V_33 -> V_11 , 0 ) ;
if ( V_20 < 0 ) {
F_11 ( & V_3 -> V_6 ,
L_10 ,
V_18 -> V_33 -> V_11 ) ;
goto V_34;
}
}
V_20 = F_22 ( V_14 ) ;
if ( V_20 ) {
F_11 ( & V_3 -> V_6 , L_11 ) ;
goto V_34;
}
F_23 ( V_3 , V_14 ) ;
return 0 ;
V_34:
F_24 ( V_18 -> V_32 ) ;
V_25:
F_25 ( V_14 ) ;
V_22:
F_5 ( & V_3 -> V_6 , L_12 , V_20 ) ;
return V_20 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_13 * V_14 = F_27 ( V_3 ) ;
struct V_17 * V_18 = F_15 ( V_14 ) ;
int V_36 = 0 ;
T_1 V_37 ;
V_37 = F_28 ( V_14 -> V_24 + V_38 ) ;
if ( V_37 == ( T_1 ) - 1 )
V_36 = 1 ;
F_29 ( V_14 , V_36 ) ;
F_24 ( V_18 -> V_32 ) ;
F_25 ( V_14 ) ;
return 0 ;
}
static int F_30 ( struct V_19 * V_6 )
{
struct V_13 * V_14 = F_31 ( V_6 ) ;
struct V_17 * V_18 = F_15 ( V_14 ) ;
int V_20 ;
V_20 = F_32 ( V_14 ) ;
if ( ! V_20 )
F_33 ( V_18 -> V_32 ) ;
return V_20 ;
}
static int F_34 ( struct V_19 * V_6 )
{
struct V_13 * V_14 = F_31 ( V_6 ) ;
struct V_17 * V_18 = F_15 ( V_14 ) ;
int V_20 ;
V_20 = F_35 ( V_18 -> V_32 ) ;
if ( V_20 ) {
F_11 ( V_6 , L_13 ) ;
return V_20 ;
}
return F_36 ( V_14 ) ;
}
