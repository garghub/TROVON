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
static int F_12 ( struct V_22 * V_23 )
{
int V_24 , V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_21 = & V_23 -> V_21 ;
struct V_29 * V_30 ;
int V_31 [ V_32 ] = {
V_33 , V_34 , V_35
} ;
V_27 = F_13 ( V_21 , sizeof( * V_27 ) , V_36 ) ;
if ( ! V_27 )
return - V_37 ;
V_30 = F_14 ( V_23 , V_38 , 0 ) ;
V_27 -> V_39 = F_15 ( V_21 , V_30 ) ;
if ( F_16 ( V_27 -> V_39 ) ) {
F_9 ( V_21 , L_3 ) ;
return F_17 ( V_27 -> V_39 ) ;
}
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ ) {
V_27 -> V_4 [ V_24 ] . V_7 = & V_27 -> V_6 [ V_24 ] ;
V_27 -> V_6 [ V_24 ] . V_1 = F_18 ( V_23 , V_24 ) ;
if ( V_27 -> V_6 [ V_24 ] . V_1 < 0 ) {
F_9 ( V_21 , L_4 , V_24 ) ;
return V_27 -> V_6 [ V_24 ] . V_1 ;
}
V_27 -> V_6 [ V_24 ] . V_9 = V_27 -> V_39 + V_31 [ V_24 ] ;
V_27 -> V_6 [ V_24 ] . V_14 = V_27 -> V_6 [ V_24 ] . V_9 + V_40 ;
}
V_27 -> V_20 . V_21 = V_21 ;
V_27 -> V_20 . V_41 = & V_27 -> V_4 [ 0 ] ;
V_27 -> V_20 . V_42 = V_32 ;
V_27 -> V_20 . V_43 = & V_44 ;
V_27 -> V_20 . V_45 = false ;
V_27 -> V_20 . V_46 = true ;
V_27 -> V_20 . V_47 = 1 ;
F_19 ( V_23 , V_27 ) ;
V_25 = F_20 ( & V_27 -> V_20 ) ;
if ( V_25 ) {
F_9 ( V_21 , L_5 , V_25 ) ;
return V_25 ;
}
F_21 ( V_21 , L_6 ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_23 )
{
struct V_26 * V_27 = F_23 ( V_23 ) ;
F_24 ( & V_27 -> V_20 ) ;
return 0 ;
}
