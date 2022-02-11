static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_2 ( V_9 , V_11 , V_11 ,
32768 , F_3 ( V_4 ) * 256 ) ;
if ( V_10 < 0 ) {
F_4 ( L_1 , V_12 ) ;
return V_10 ;
}
V_10 = F_5 ( V_9 , V_13 ,
0 , V_14 ) ;
if ( V_10 < 0 ) {
F_4 ( L_2 , V_12 ) ;
return V_10 ;
}
return 0 ;
}
static int F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 . V_20 ;
struct V_17 * V_21 , * V_22 ;
struct V_23 * V_24 = & V_25 ;
struct V_26 * V_27 = & V_28 ;
int V_10 ;
if ( ! V_18 ) {
F_7 ( & V_16 -> V_19 , L_3 ) ;
return - V_29 ;
}
V_10 = F_8 ( V_24 , L_4 ) ;
if ( V_10 ) {
F_7 ( & V_16 -> V_19 , L_5 ) ;
return V_10 ;
}
V_10 = F_9 ( V_24 , L_6 ) ;
if ( V_10 ) {
F_7 ( & V_16 -> V_19 , L_7 ) ;
return V_10 ;
}
V_22 = F_10 ( V_18 , L_8 , 0 ) ;
if ( ! V_22 ) {
F_7 ( & V_16 -> V_19 , L_9 ) ;
V_10 = - V_29 ;
return V_10 ;
}
V_27 -> V_30 = V_22 ;
V_27 -> V_31 = V_22 ;
F_11 ( V_22 ) ;
V_21 = F_10 ( V_18 , L_10 , 0 ) ;
if ( ! V_21 ) {
F_7 ( & V_16 -> V_19 , L_11 ) ;
V_10 = - V_29 ;
return V_10 ;
}
V_27 -> V_32 = V_21 ;
F_11 ( V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_15 * V_16 )
{
struct V_23 * V_24 = & V_25 ;
struct V_26 * V_27 = & V_28 ;
int V_33 , V_10 ;
V_24 -> V_19 = & V_16 -> V_19 ;
V_10 = F_6 ( V_16 ) ;
if ( V_10 ) {
F_7 ( & V_16 -> V_19 , L_12 ) ;
return V_10 ;
}
V_33 = F_13 ( (struct V_17 * ) V_27 -> V_30 , L_13 ) ;
V_10 = F_14 ( V_33 ) ;
if ( V_10 != 0 ) {
F_7 ( & V_16 -> V_19 , L_14 , V_33 ) ;
return V_10 ;
}
V_10 = F_15 ( V_24 ) ;
if ( V_10 ) {
F_7 ( & V_16 -> V_19 , L_15 ) ;
goto V_34;
}
return 0 ;
V_34:
F_16 ( V_33 ) ;
return V_10 ;
}
static int F_17 ( struct V_15 * V_16 )
{
struct V_23 * V_24 = F_18 ( V_16 ) ;
struct V_26 * V_27 = & V_28 ;
int V_33 ;
V_33 = F_13 ( (struct V_17 * ) V_27 -> V_30 , L_13 ) ;
F_19 ( V_24 ) ;
F_16 ( V_33 ) ;
return 0 ;
}
