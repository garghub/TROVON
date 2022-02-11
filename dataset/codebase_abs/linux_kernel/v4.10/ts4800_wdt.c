static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 -> V_4 , V_2 -> V_5 , V_3 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_1 ( V_2 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_1 ( V_2 , V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
unsigned int V_10 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( V_13 [ V_11 ] . V_10 >= V_10 )
break;
}
V_7 -> V_10 = V_13 [ V_11 ] . V_10 ;
V_2 -> V_8 = V_13 [ V_11 ] . V_14 ;
return 0 ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 . V_20 ;
struct V_17 * V_21 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
T_1 V_22 ;
int V_23 ;
V_21 = F_8 ( V_18 , L_1 , 0 ) ;
if ( ! V_21 ) {
F_9 ( & V_16 -> V_19 , L_2 ) ;
return - V_24 ;
}
V_23 = F_10 ( V_18 , L_1 , 1 , & V_22 ) ;
if ( V_23 < 0 ) {
F_9 ( & V_16 -> V_19 , L_3 ) ;
return V_23 ;
}
V_2 = F_11 ( & V_16 -> V_19 , sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
V_2 -> V_5 = V_22 ;
V_2 -> V_4 = F_12 ( V_21 ) ;
if ( F_13 ( V_2 -> V_4 ) ) {
F_9 ( & V_16 -> V_19 , L_4 ) ;
return F_14 ( V_2 -> V_4 ) ;
}
V_7 = & V_2 -> V_7 ;
V_7 -> V_27 = & V_16 -> V_19 ;
V_7 -> V_28 = & V_29 ;
V_7 -> V_30 = & V_31 ;
V_7 -> V_32 = V_13 [ 0 ] . V_10 ;
V_7 -> V_33 = V_13 [ V_12 ] . V_10 ;
F_15 ( V_7 , V_2 ) ;
F_16 ( V_7 , V_34 ) ;
F_17 ( V_7 , 0 , & V_16 -> V_19 ) ;
if ( ! V_7 -> V_10 )
V_7 -> V_10 = V_7 -> V_33 ;
F_6 ( V_7 , V_7 -> V_10 ) ;
F_5 ( V_7 ) ;
V_23 = F_18 ( V_7 ) ;
if ( V_23 ) {
F_9 ( & V_16 -> V_19 ,
L_5 ) ;
return V_23 ;
}
F_19 ( V_16 , V_2 ) ;
F_20 ( & V_16 -> V_19 ,
L_6 ,
V_7 -> V_10 , V_34 ) ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_22 ( V_16 ) ;
F_23 ( & V_2 -> V_7 ) ;
return 0 ;
}
