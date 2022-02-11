static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_7 = & V_5 -> V_8 -> V_9 -> V_7 ;
int V_10 ;
if ( ! V_4 -> V_5 -> V_8 ) {
F_3 ( V_5 -> V_11 , L_1 ) ;
return;
}
if ( V_4 -> V_12 ) {
V_10 = F_4 ( V_5 -> V_13 ,
V_14 ,
V_15 ,
V_4 -> V_12 ) ;
if ( V_10 != 0 ) {
F_3 ( V_5 -> V_11 , L_2 ,
V_10 ) ;
return;
}
V_10 = F_4 ( V_5 -> V_13 ,
V_16 ,
V_17 ,
1 << V_18 ) ;
if ( V_10 != 0 ) {
F_3 ( V_5 -> V_11 , L_3 ,
V_10 ) ;
return;
}
F_5 ( V_7 , V_19 ) ;
V_10 = F_6 ( V_5 -> V_8 , L_4 ) ;
if ( V_10 != 0 ) {
F_3 ( V_5 -> V_11 , L_5 ,
V_10 ) ;
F_7 ( V_7 ) ;
return;
}
V_10 = F_8 ( V_5 -> V_8 ) ;
if ( V_10 != 0 ) {
F_3 ( V_5 -> V_11 , L_6 ,
V_10 ) ;
F_7 ( V_7 ) ;
return;
}
F_7 ( V_7 ) ;
} else {
F_5 ( V_7 , V_19 ) ;
V_10 = F_9 ( V_5 -> V_8 , L_4 ) ;
if ( V_10 != 0 ) {
F_3 ( V_5 -> V_11 , L_7 ,
V_10 ) ;
F_7 ( V_7 ) ;
return;
}
V_10 = F_8 ( V_5 -> V_8 ) ;
if ( V_10 != 0 ) {
F_3 ( V_5 -> V_11 , L_6 ,
V_10 ) ;
F_7 ( V_7 ) ;
return;
}
F_7 ( V_7 ) ;
V_10 = F_4 ( V_5 -> V_13 ,
V_16 ,
V_17 ,
1 << V_18 ) ;
if ( V_10 != 0 ) {
F_3 ( V_5 -> V_11 , L_8 ,
V_10 ) ;
return;
}
}
}
static int F_10 ( struct V_20 * V_21 , void * V_22 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = F_11 ( V_21 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( ! V_5 -> V_8 ) {
F_3 ( V_5 -> V_11 , L_1 ) ;
return - V_25 ;
}
if ( V_24 -> V_26 . V_27 . V_28 ) {
if ( V_5 -> V_29 . V_30 ) {
V_4 -> V_12 =
V_24 -> V_26 . V_27 . V_28 >> 9 ;
if ( V_24 -> V_31 < 0x8000 )
V_4 -> V_12 += 0x7f ;
} else {
V_4 -> V_12 =
V_24 -> V_26 . V_27 . V_28 >> 8 ;
}
} else {
V_4 -> V_12 = 0 ;
}
F_12 ( & V_4 -> V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_11 ( V_21 ) ;
struct V_6 * V_7 = & V_4 -> V_5 -> V_8 -> V_9 -> V_7 ;
F_14 ( & V_4 -> V_2 ) ;
F_5 ( V_7 , V_19 ) ;
if ( V_4 -> V_5 -> V_8 )
F_9 ( V_4 -> V_5 -> V_8 , L_4 ) ;
F_7 ( V_7 ) ;
}
static int F_15 ( struct V_32 * V_33 )
{
struct V_5 * V_5 = F_16 ( V_33 -> V_11 . V_34 ) ;
struct V_3 * V_4 ;
int V_10 ;
V_4 = F_17 ( & V_33 -> V_11 , sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 )
return - V_36 ;
V_4 -> V_5 = V_5 ;
V_10 = F_4 ( V_5 -> V_13 , V_16 ,
V_37 , V_5 -> V_29 . V_30 ) ;
if ( V_10 != 0 ) {
F_3 ( V_5 -> V_11 , L_9 ,
V_10 ) ;
return V_10 ;
}
F_18 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_20 = F_19 () ;
if ( V_4 -> V_20 == NULL ) {
F_3 ( V_5 -> V_11 , L_10 ) ;
return - V_36 ;
}
F_20 ( V_4 -> V_20 , V_4 ) ;
V_4 -> V_20 -> V_38 = L_11 ;
V_4 -> V_20 -> V_11 . V_34 = V_33 -> V_11 . V_34 ;
V_4 -> V_20 -> V_39 = F_13 ;
F_21 ( V_40 , V_4 -> V_20 -> V_41 ) ;
V_10 = F_22 ( V_4 -> V_20 , NULL ,
F_10 ) ;
if ( V_10 < 0 ) {
F_3 ( V_5 -> V_11 , L_12 ,
V_10 ) ;
goto V_42;
}
V_10 = F_23 ( V_4 -> V_20 ) ;
if ( V_10 < 0 ) {
F_3 ( V_5 -> V_11 , L_13 ,
V_10 ) ;
goto V_43;
}
F_24 ( V_33 , V_4 ) ;
return 0 ;
V_43:
if ( V_4 -> V_20 )
F_25 ( V_4 -> V_20 ) ;
V_42:
F_26 ( V_4 -> V_20 ) ;
return V_10 ;
}
static int F_27 ( struct V_32 * V_33 )
{
struct V_3 * V_4 = F_28 ( V_33 ) ;
F_29 ( V_4 -> V_20 ) ;
return 0 ;
}
