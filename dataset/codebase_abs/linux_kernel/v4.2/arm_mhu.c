static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_8 ;
V_8 = F_2 ( V_6 -> V_9 + V_10 ) ;
if ( ! V_8 )
return V_11 ;
F_3 ( V_4 , ( void * ) & V_8 ) ;
F_4 ( V_8 , V_6 -> V_9 + V_12 ) ;
return V_13 ;
}
static bool F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_8 = F_2 ( V_6 -> V_14 + V_10 ) ;
return ( V_8 == 0 ) ;
}
static int F_6 ( struct V_3 * V_4 , void * V_15 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 * V_16 = V_15 ;
F_4 ( * V_16 , V_6 -> V_14 + V_17 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_8 ;
int V_18 ;
V_8 = F_2 ( V_6 -> V_14 + V_10 ) ;
F_4 ( V_8 , V_6 -> V_14 + V_12 ) ;
V_18 = F_8 ( V_6 -> V_1 , F_1 ,
V_19 , L_1 , V_4 ) ;
if ( V_18 ) {
F_9 ( V_4 -> V_20 -> V_21 ,
L_2 , V_6 -> V_1 ) ;
return V_18 ;
}
return 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_11 ( V_6 -> V_1 , V_4 ) ;
}
static int F_12 ( struct V_22 * V_23 , const struct V_24 * V_25 )
{
int V_26 , V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_21 = & V_23 -> V_21 ;
int V_31 [ V_32 ] = { V_33 , V_34 , V_35 } ;
V_29 = F_13 ( V_21 , sizeof( * V_29 ) , V_36 ) ;
if ( ! V_29 )
return - V_37 ;
V_29 -> V_38 = F_14 ( V_21 , & V_23 -> V_39 ) ;
if ( F_15 ( V_29 -> V_38 ) ) {
F_9 ( V_21 , L_3 ) ;
return F_16 ( V_29 -> V_38 ) ;
}
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ ) {
V_29 -> V_4 [ V_26 ] . V_7 = & V_29 -> V_6 [ V_26 ] ;
V_29 -> V_6 [ V_26 ] . V_1 = V_23 -> V_1 [ V_26 ] ;
V_29 -> V_6 [ V_26 ] . V_9 = V_29 -> V_38 + V_31 [ V_26 ] ;
V_29 -> V_6 [ V_26 ] . V_14 = V_29 -> V_6 [ V_26 ] . V_9 + V_40 ;
}
V_29 -> V_20 . V_21 = V_21 ;
V_29 -> V_20 . V_41 = & V_29 -> V_4 [ 0 ] ;
V_29 -> V_20 . V_42 = V_32 ;
V_29 -> V_20 . V_43 = & V_44 ;
V_29 -> V_20 . V_45 = false ;
V_29 -> V_20 . V_46 = true ;
V_29 -> V_20 . V_47 = 10 ;
F_17 ( V_23 , V_29 ) ;
V_27 = F_18 ( & V_29 -> V_20 ) ;
if ( V_27 ) {
F_9 ( V_21 , L_4 , V_27 ) ;
return V_27 ;
}
F_19 ( V_21 , L_5 ) ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 )
{
struct V_28 * V_29 = F_21 ( V_23 ) ;
F_22 ( & V_29 -> V_20 ) ;
return 0 ;
}
