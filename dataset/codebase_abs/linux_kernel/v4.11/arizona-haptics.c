static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_7 =
F_3 ( V_5 -> V_8 ) ;
int V_9 ;
if ( ! V_4 -> V_5 -> V_8 ) {
F_4 ( V_5 -> V_10 , L_1 ) ;
return;
}
if ( V_4 -> V_11 ) {
V_9 = F_5 ( V_5 -> V_12 ,
V_13 ,
V_14 ,
V_4 -> V_11 ) ;
if ( V_9 != 0 ) {
F_4 ( V_5 -> V_10 , L_2 ,
V_9 ) ;
return;
}
V_9 = F_5 ( V_5 -> V_12 ,
V_15 ,
V_16 ,
1 << V_17 ) ;
if ( V_9 != 0 ) {
F_4 ( V_5 -> V_10 , L_3 ,
V_9 ) ;
return;
}
V_9 = F_6 ( V_7 , L_4 ) ;
if ( V_9 != 0 ) {
F_4 ( V_5 -> V_10 , L_5 ,
V_9 ) ;
return;
}
V_9 = F_7 ( V_5 -> V_8 ) ;
if ( V_9 != 0 ) {
F_4 ( V_5 -> V_10 , L_6 ,
V_9 ) ;
return;
}
} else {
V_9 = F_8 ( V_7 , L_4 ) ;
if ( V_9 != 0 ) {
F_4 ( V_5 -> V_10 , L_7 ,
V_9 ) ;
return;
}
V_9 = F_7 ( V_5 -> V_8 ) ;
if ( V_9 != 0 ) {
F_4 ( V_5 -> V_10 , L_6 ,
V_9 ) ;
return;
}
V_9 = F_5 ( V_5 -> V_12 ,
V_15 ,
V_16 , 0 ) ;
if ( V_9 != 0 ) {
F_4 ( V_5 -> V_10 , L_8 ,
V_9 ) ;
return;
}
}
}
static int F_9 ( struct V_18 * V_19 , void * V_20 ,
struct V_21 * V_22 )
{
struct V_3 * V_4 = F_10 ( V_19 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_8 ) {
F_4 ( V_5 -> V_10 , L_1 ) ;
return - V_23 ;
}
if ( V_22 -> V_24 . V_25 . V_26 ) {
if ( V_5 -> V_27 . V_28 ) {
V_4 -> V_11 =
V_22 -> V_24 . V_25 . V_26 >> 9 ;
if ( V_22 -> V_29 < 0x8000 )
V_4 -> V_11 += 0x7f ;
} else {
V_4 -> V_11 =
V_22 -> V_24 . V_25 . V_26 >> 8 ;
}
} else {
V_4 -> V_11 = 0 ;
}
F_11 ( & V_4 -> V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_18 * V_19 )
{
struct V_3 * V_4 = F_10 ( V_19 ) ;
struct V_6 * V_7 ;
F_13 ( & V_4 -> V_2 ) ;
if ( V_4 -> V_5 -> V_8 ) {
V_7 = F_3 ( V_4 -> V_5 -> V_8 ) ;
F_8 ( V_7 , L_4 ) ;
}
}
static int F_14 ( struct V_30 * V_31 )
{
struct V_5 * V_5 = F_15 ( V_31 -> V_10 . V_32 ) ;
struct V_3 * V_4 ;
int V_9 ;
V_4 = F_16 ( & V_31 -> V_10 , sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 )
return - V_34 ;
V_4 -> V_5 = V_5 ;
V_9 = F_5 ( V_5 -> V_12 , V_15 ,
V_35 , V_5 -> V_27 . V_28 ) ;
if ( V_9 != 0 ) {
F_4 ( V_5 -> V_10 , L_9 ,
V_9 ) ;
return V_9 ;
}
F_17 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_18 = F_18 ( & V_31 -> V_10 ) ;
if ( ! V_4 -> V_18 ) {
F_4 ( V_5 -> V_10 , L_10 ) ;
return - V_34 ;
}
F_19 ( V_4 -> V_18 , V_4 ) ;
V_4 -> V_18 -> V_36 = L_11 ;
V_4 -> V_18 -> V_37 = F_12 ;
F_20 ( V_38 , V_4 -> V_18 -> V_39 ) ;
V_9 = F_21 ( V_4 -> V_18 , NULL ,
F_9 ) ;
if ( V_9 < 0 ) {
F_4 ( V_5 -> V_10 , L_12 ,
V_9 ) ;
return V_9 ;
}
V_9 = F_22 ( V_4 -> V_18 ) ;
if ( V_9 < 0 ) {
F_4 ( V_5 -> V_10 , L_13 ,
V_9 ) ;
return V_9 ;
}
return 0 ;
}
