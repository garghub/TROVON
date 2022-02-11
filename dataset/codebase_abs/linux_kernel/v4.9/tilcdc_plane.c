static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_3 * V_7 = V_2 -> V_4 ;
unsigned int V_8 , V_9 ;
if ( ! V_4 -> V_10 )
return 0 ;
if ( F_2 ( ! V_4 -> V_11 ) )
return - V_12 ;
if ( V_4 -> V_13 || V_4 -> V_14 ) {
F_3 ( V_2 -> V_15 -> V_15 , L_1 ,
V_16 ) ;
return - V_12 ;
}
V_6 = F_4 ( V_4 -> V_4 ,
V_4 -> V_10 ) ;
if ( F_2 ( ! V_6 ) )
return 0 ;
if ( V_6 -> V_17 . V_18 != V_4 -> V_19 ||
V_6 -> V_17 . V_20 != V_4 -> V_21 ) {
F_3 ( V_2 -> V_15 -> V_15 ,
L_2 , V_16 ,
V_6 -> V_17 . V_18 , V_6 -> V_17 . V_20 ,
V_4 -> V_19 , V_4 -> V_21 ) ;
return - V_12 ;
}
F_5 ( V_4 -> V_11 -> V_22 , & V_8 , & V_9 ) ;
if ( V_4 -> V_11 -> V_23 [ 0 ] != V_6 -> V_17 . V_18 * V_9 / 8 ) {
F_3 ( V_2 -> V_15 -> V_15 ,
L_3 ) ;
return - V_12 ;
}
if ( V_4 -> V_11 && V_7 -> V_11 &&
V_4 -> V_11 -> V_22 != V_7 -> V_11 -> V_22 ) {
F_6 ( V_2 -> V_15 -> V_15 ,
L_4 ,
V_16 ) ;
V_6 -> V_24 = true ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_7 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_10 )
return;
if ( F_2 ( ! V_4 -> V_11 || ! V_4 -> V_10 -> V_4 ) )
return;
F_8 ( V_4 -> V_10 ,
V_4 -> V_11 ,
V_4 -> V_10 -> V_4 -> V_25 ) ;
}
int F_9 ( struct V_26 * V_15 ,
struct V_1 * V_2 )
{
struct V_27 * V_28 = V_15 -> V_29 ;
int V_30 ;
V_30 = F_10 ( V_15 , V_2 , 1 ,
& V_31 ,
V_28 -> V_32 ,
V_28 -> V_33 ,
true ) ;
if ( V_30 ) {
F_3 ( V_15 -> V_15 , L_5 , V_30 ) ;
return V_30 ;
}
F_11 ( V_2 , & V_34 ) ;
return 0 ;
}
