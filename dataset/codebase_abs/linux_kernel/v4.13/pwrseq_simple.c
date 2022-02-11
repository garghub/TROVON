static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! F_2 ( V_5 ) ) {
int V_6 ;
int V_7 [ V_5 -> V_8 ] ;
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ )
V_7 [ V_6 ] = V_3 ;
F_3 (
V_5 -> V_8 , V_5 -> V_9 , V_7 ) ;
}
}
static void F_4 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 -> V_2 ) ;
if ( ! F_2 ( V_2 -> V_12 ) && ! V_2 -> V_13 ) {
F_6 ( V_2 -> V_12 ) ;
V_2 -> V_13 = true ;
}
F_1 ( V_2 , 1 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 -> V_2 ) ;
F_1 ( V_2 , 0 ) ;
if ( V_2 -> V_14 )
F_8 ( V_2 -> V_14 ) ;
}
static void F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 -> V_2 ) ;
F_1 ( V_2 , 1 ) ;
if ( V_2 -> V_15 )
F_10 ( V_2 -> V_15 ,
2 * V_2 -> V_15 ) ;
if ( ! F_2 ( V_2 -> V_12 ) && V_2 -> V_13 ) {
F_11 ( V_2 -> V_12 ) ;
V_2 -> V_13 = false ;
}
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 = & V_17 -> V_19 ;
V_2 = F_13 ( V_19 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_12 = F_14 ( V_19 , L_1 ) ;
if ( F_2 ( V_2 -> V_12 ) && F_15 ( V_2 -> V_12 ) != - V_22 )
return F_15 ( V_2 -> V_12 ) ;
V_2 -> V_5 = F_16 ( V_19 , L_2 ,
V_23 ) ;
if ( F_2 ( V_2 -> V_5 ) &&
F_15 ( V_2 -> V_5 ) != - V_22 &&
F_15 ( V_2 -> V_5 ) != - V_24 ) {
return F_15 ( V_2 -> V_5 ) ;
}
F_17 ( V_19 , L_3 ,
& V_2 -> V_14 ) ;
F_17 ( V_19 , L_4 ,
& V_2 -> V_15 ) ;
V_2 -> V_2 . V_19 = V_19 ;
V_2 -> V_2 . V_25 = & V_26 ;
V_2 -> V_2 . V_27 = V_28 ;
F_18 ( V_17 , V_2 ) ;
return F_19 ( & V_2 -> V_2 ) ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_21 ( V_17 ) ;
F_22 ( & V_2 -> V_2 ) ;
return 0 ;
}
