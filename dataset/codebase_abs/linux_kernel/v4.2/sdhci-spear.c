static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , L_1 , 0 ) ;
if ( ! F_3 ( V_5 ) )
V_5 = - 1 ;
V_4 -> V_6 = V_5 ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_4 ;
struct V_10 * V_11 ;
struct V_3 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
V_14 = V_8 -> V_14 . V_16 ? V_8 -> V_14 . V_16 : & V_8 -> V_14 ;
V_4 = F_5 ( V_14 , sizeof( * V_12 ) ) ;
if ( F_6 ( V_4 ) ) {
V_15 = F_7 ( V_4 ) ;
F_8 ( & V_8 -> V_14 , L_2 ) ;
goto V_17;
}
V_11 = F_9 ( V_8 , V_18 , 0 ) ;
V_4 -> V_19 = F_10 ( & V_8 -> V_14 , V_11 ) ;
if ( F_6 ( V_4 -> V_19 ) ) {
V_15 = F_7 ( V_4 -> V_19 ) ;
F_8 ( & V_8 -> V_14 , L_3 , V_15 ) ;
goto V_20;
}
V_4 -> V_21 = L_4 ;
V_4 -> V_22 = & V_23 ;
V_4 -> V_24 = F_11 ( V_8 , 0 ) ;
V_4 -> V_25 = V_26 ;
V_12 = F_12 ( V_4 ) ;
V_12 -> V_27 = F_13 ( & V_8 -> V_14 , NULL ) ;
if ( F_6 ( V_12 -> V_27 ) ) {
V_15 = F_7 ( V_12 -> V_27 ) ;
F_8 ( & V_8 -> V_14 , L_5 ) ;
goto V_20;
}
V_15 = F_14 ( V_12 -> V_27 ) ;
if ( V_15 ) {
F_8 ( & V_8 -> V_14 , L_6 ) ;
goto V_20;
}
V_15 = F_15 ( V_12 -> V_27 , 50000000 ) ;
if ( V_15 )
F_8 ( & V_8 -> V_14 , L_7 ,
F_16 ( V_12 -> V_27 ) ) ;
F_1 ( V_8 -> V_14 . V_28 , V_12 ) ;
if ( V_12 -> V_6 >= 0 ) {
V_15 = F_17 ( V_4 -> V_29 , V_12 -> V_6 , 0 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_8 -> V_14 ,
L_8 ,
V_12 -> V_6 ) ;
goto V_30;
}
}
V_15 = F_18 ( V_4 ) ;
if ( V_15 ) {
F_8 ( & V_8 -> V_14 , L_9 ) ;
goto V_30;
}
F_19 ( V_8 , V_4 ) ;
return 0 ;
V_30:
F_20 ( V_12 -> V_27 ) ;
V_20:
F_21 ( V_4 ) ;
V_17:
F_22 ( & V_8 -> V_14 , L_10 , V_15 ) ;
return V_15 ;
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_9 * V_4 = F_24 ( V_8 ) ;
struct V_3 * V_12 = F_12 ( V_4 ) ;
int V_31 = 0 ;
T_1 V_32 ;
V_32 = F_25 ( V_4 -> V_19 + V_33 ) ;
if ( V_32 == ( T_1 ) - 1 )
V_31 = 1 ;
F_26 ( V_4 , V_31 ) ;
F_20 ( V_12 -> V_27 ) ;
F_21 ( V_4 ) ;
return 0 ;
}
static int F_27 ( struct V_13 * V_14 )
{
struct V_9 * V_4 = F_28 ( V_14 ) ;
struct V_3 * V_12 = F_12 ( V_4 ) ;
int V_15 ;
V_15 = F_29 ( V_4 ) ;
if ( ! V_15 )
F_30 ( V_12 -> V_27 ) ;
return V_15 ;
}
static int F_31 ( struct V_13 * V_14 )
{
struct V_9 * V_4 = F_28 ( V_14 ) ;
struct V_3 * V_12 = F_12 ( V_4 ) ;
int V_15 ;
V_15 = F_32 ( V_12 -> V_27 ) ;
if ( V_15 ) {
F_8 ( V_14 , L_11 ) ;
return V_15 ;
}
return F_33 ( V_4 ) ;
}
