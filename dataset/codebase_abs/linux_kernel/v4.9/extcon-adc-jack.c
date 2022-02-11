static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 ( V_2 ) ,
struct V_3 ,
V_5 ) ;
struct V_6 * V_7 ;
int V_8 , V_9 ;
int V_10 ;
V_8 = F_4 ( V_4 -> V_11 , & V_9 ) ;
if ( V_8 < 0 ) {
F_5 ( & V_4 -> V_12 -> V_13 , L_1 , V_8 ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_4 -> V_14 ; V_10 ++ ) {
V_7 = & V_4 -> V_15 [ V_10 ] ;
if ( V_7 -> V_16 <= V_9 && V_7 -> V_17 >= V_9 ) {
F_6 ( V_4 -> V_12 , V_7 -> V_18 , true ) ;
return;
}
}
for ( V_10 = 0 ; V_10 < V_4 -> V_14 ; V_10 ++ ) {
V_7 = & V_4 -> V_15 [ V_10 ] ;
F_6 ( V_4 -> V_12 , V_7 -> V_18 , false ) ;
}
}
static T_1 F_7 ( int V_19 , void * V_20 )
{
struct V_3 * V_4 = V_20 ;
F_8 ( V_21 ,
& V_4 -> V_5 , V_4 -> V_22 ) ;
return V_23 ;
}
static int F_9 ( struct V_24 * V_25 )
{
struct V_3 * V_4 ;
struct V_26 * V_27 = F_10 ( & V_25 -> V_13 ) ;
int V_10 , V_28 = 0 ;
V_4 = F_11 ( & V_25 -> V_13 , sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
if ( ! V_27 -> V_31 ) {
F_5 ( & V_25 -> V_13 , L_2 ) ;
return - V_32 ;
}
V_4 -> V_13 = & V_25 -> V_13 ;
V_4 -> V_12 = F_12 ( & V_25 -> V_13 , V_27 -> V_31 ) ;
if ( F_13 ( V_4 -> V_12 ) ) {
F_5 ( & V_25 -> V_13 , L_3 ) ;
return - V_30 ;
}
if ( ! V_27 -> V_15 ) {
F_5 ( & V_25 -> V_13 , L_4 ) ;
return - V_32 ;
}
V_4 -> V_15 = V_27 -> V_15 ;
for ( V_10 = 0 ; V_4 -> V_15 [ V_10 ] . V_18 != V_33 ; V_10 ++ ) ;
V_4 -> V_14 = V_10 ;
V_4 -> V_11 = F_14 ( & V_25 -> V_13 , V_27 -> V_34 ) ;
if ( F_13 ( V_4 -> V_11 ) )
return F_15 ( V_4 -> V_11 ) ;
V_4 -> V_22 = F_16 ( V_27 -> V_35 ) ;
V_4 -> V_36 = V_27 -> V_36 ;
F_17 ( & V_4 -> V_5 , F_1 ) ;
F_18 ( V_25 , V_4 ) ;
V_28 = F_19 ( & V_25 -> V_13 , V_4 -> V_12 ) ;
if ( V_28 )
return V_28 ;
V_4 -> V_19 = F_20 ( V_25 , 0 ) ;
if ( ! V_4 -> V_19 ) {
F_5 ( & V_25 -> V_13 , L_5 ) ;
return - V_37 ;
}
V_28 = F_21 ( V_4 -> V_19 , F_7 ,
V_27 -> V_38 , V_27 -> V_39 , V_4 ) ;
if ( V_28 < 0 ) {
F_5 ( & V_25 -> V_13 , L_6 , V_4 -> V_19 ) ;
return V_28 ;
}
if ( V_4 -> V_36 )
F_22 ( & V_25 -> V_13 , 1 ) ;
F_1 ( & V_4 -> V_5 . V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_24 * V_25 )
{
struct V_3 * V_4 = F_24 ( V_25 ) ;
F_25 ( V_4 -> V_19 , V_4 ) ;
F_26 ( & V_4 -> V_5 . V_2 ) ;
F_27 ( V_4 -> V_11 ) ;
return 0 ;
}
static int F_28 ( struct V_40 * V_13 )
{
struct V_3 * V_4 = F_29 ( V_13 ) ;
F_30 ( & V_4 -> V_5 ) ;
if ( F_31 ( V_4 -> V_13 ) )
F_32 ( V_4 -> V_19 ) ;
return 0 ;
}
static int F_33 ( struct V_40 * V_13 )
{
struct V_3 * V_4 = F_29 ( V_13 ) ;
if ( F_31 ( V_4 -> V_13 ) )
F_34 ( V_4 -> V_19 ) ;
return 0 ;
}
