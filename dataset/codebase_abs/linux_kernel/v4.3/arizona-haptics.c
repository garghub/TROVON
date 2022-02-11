static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 ;
if ( ! V_4 -> V_5 -> V_7 ) {
F_3 ( V_5 -> V_8 , L_1 ) ;
return;
}
if ( V_4 -> V_9 ) {
V_6 = F_4 ( V_5 -> V_10 ,
V_11 ,
V_12 ,
V_4 -> V_9 ) ;
if ( V_6 != 0 ) {
F_3 ( V_5 -> V_8 , L_2 ,
V_6 ) ;
return;
}
V_6 = F_4 ( V_5 -> V_10 ,
V_13 ,
V_14 ,
1 << V_15 ) ;
if ( V_6 != 0 ) {
F_3 ( V_5 -> V_8 , L_3 ,
V_6 ) ;
return;
}
V_6 = F_5 ( V_5 -> V_7 , L_4 ) ;
if ( V_6 != 0 ) {
F_3 ( V_5 -> V_8 , L_5 ,
V_6 ) ;
return;
}
V_6 = F_6 ( V_5 -> V_7 ) ;
if ( V_6 != 0 ) {
F_3 ( V_5 -> V_8 , L_6 ,
V_6 ) ;
return;
}
} else {
V_6 = F_7 ( V_5 -> V_7 , L_4 ) ;
if ( V_6 != 0 ) {
F_3 ( V_5 -> V_8 , L_7 ,
V_6 ) ;
return;
}
V_6 = F_6 ( V_5 -> V_7 ) ;
if ( V_6 != 0 ) {
F_3 ( V_5 -> V_8 , L_6 ,
V_6 ) ;
return;
}
V_6 = F_4 ( V_5 -> V_10 ,
V_13 ,
V_14 ,
1 << V_15 ) ;
if ( V_6 != 0 ) {
F_3 ( V_5 -> V_8 , L_8 ,
V_6 ) ;
return;
}
}
}
static int F_8 ( struct V_16 * V_17 , void * V_18 ,
struct V_19 * V_20 )
{
struct V_3 * V_4 = F_9 ( V_17 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_7 ) {
F_3 ( V_5 -> V_8 , L_1 ) ;
return - V_21 ;
}
if ( V_20 -> V_22 . V_23 . V_24 ) {
if ( V_5 -> V_25 . V_26 ) {
V_4 -> V_9 =
V_20 -> V_22 . V_23 . V_24 >> 9 ;
if ( V_20 -> V_27 < 0x8000 )
V_4 -> V_9 += 0x7f ;
} else {
V_4 -> V_9 =
V_20 -> V_22 . V_23 . V_24 >> 8 ;
}
} else {
V_4 -> V_9 = 0 ;
}
F_10 ( & V_4 -> V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = F_9 ( V_17 ) ;
F_12 ( & V_4 -> V_2 ) ;
if ( V_4 -> V_5 -> V_7 )
F_7 ( V_4 -> V_5 -> V_7 , L_4 ) ;
}
static int F_13 ( struct V_28 * V_29 )
{
struct V_5 * V_5 = F_14 ( V_29 -> V_8 . V_30 ) ;
struct V_3 * V_4 ;
int V_6 ;
V_4 = F_15 ( & V_29 -> V_8 , sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_5 = V_5 ;
V_6 = F_4 ( V_5 -> V_10 , V_13 ,
V_33 , V_5 -> V_25 . V_26 ) ;
if ( V_6 != 0 ) {
F_3 ( V_5 -> V_8 , L_9 ,
V_6 ) ;
return V_6 ;
}
F_16 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_16 = F_17 ( & V_29 -> V_8 ) ;
if ( ! V_4 -> V_16 ) {
F_3 ( V_5 -> V_8 , L_10 ) ;
return - V_32 ;
}
F_18 ( V_4 -> V_16 , V_4 ) ;
V_4 -> V_16 -> V_34 = L_11 ;
V_4 -> V_16 -> V_8 . V_30 = V_29 -> V_8 . V_30 ;
V_4 -> V_16 -> V_35 = F_11 ;
F_19 ( V_36 , V_4 -> V_16 -> V_37 ) ;
V_6 = F_20 ( V_4 -> V_16 , NULL ,
F_8 ) ;
if ( V_6 < 0 ) {
F_3 ( V_5 -> V_8 , L_12 ,
V_6 ) ;
return V_6 ;
}
V_6 = F_21 ( V_4 -> V_16 ) ;
if ( V_6 < 0 ) {
F_3 ( V_5 -> V_8 , L_13 ,
V_6 ) ;
return V_6 ;
}
F_22 ( V_29 , V_4 ) ;
return 0 ;
}
