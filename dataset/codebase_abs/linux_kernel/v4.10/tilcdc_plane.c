static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_3 * V_7 = V_2 -> V_4 ;
unsigned int V_8 ;
if ( ! V_4 -> V_9 )
return 0 ;
if ( F_2 ( ! V_4 -> V_10 ) )
return - V_11 ;
if ( V_4 -> V_12 || V_4 -> V_13 ) {
F_3 ( V_2 -> V_14 -> V_14 , L_1 ,
V_15 ) ;
return - V_11 ;
}
V_6 = F_4 ( V_4 -> V_4 ,
V_4 -> V_9 ) ;
if ( F_2 ( ! V_6 ) )
return 0 ;
if ( V_6 -> V_16 . V_17 != V_4 -> V_18 ||
V_6 -> V_16 . V_19 != V_4 -> V_20 ) {
F_3 ( V_2 -> V_14 -> V_14 ,
L_2 , V_15 ,
V_6 -> V_16 . V_17 , V_6 -> V_16 . V_19 ,
V_4 -> V_18 , V_4 -> V_20 ) ;
return - V_11 ;
}
V_8 = V_6 -> V_16 . V_17 *
F_5 ( V_4 -> V_10 -> V_21 , 0 ) ;
if ( V_4 -> V_10 -> V_22 [ 0 ] != V_8 ) {
F_3 ( V_2 -> V_14 -> V_14 ,
L_3 ) ;
return - V_11 ;
}
if ( V_4 -> V_10 && V_7 -> V_10 &&
V_4 -> V_10 -> V_21 != V_7 -> V_10 -> V_21 ) {
F_6 ( V_2 -> V_14 -> V_14 ,
L_4 ,
V_15 ) ;
V_6 -> V_23 = true ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_7 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_9 )
return;
if ( F_2 ( ! V_4 -> V_10 || ! V_4 -> V_9 -> V_4 ) )
return;
F_8 ( V_4 -> V_9 ,
V_4 -> V_10 ,
V_4 -> V_9 -> V_4 -> V_24 ) ;
}
int F_9 ( struct V_25 * V_14 ,
struct V_1 * V_2 )
{
struct V_26 * V_27 = V_14 -> V_28 ;
int V_29 ;
V_29 = F_10 ( V_14 , V_2 , 1 ,
& V_30 ,
V_27 -> V_31 ,
V_27 -> V_32 ,
true ) ;
if ( V_29 ) {
F_3 ( V_14 -> V_14 , L_5 , V_29 ) ;
return V_29 ;
}
F_11 ( V_2 , & V_33 ) ;
return 0 ;
}
