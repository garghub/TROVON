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
if ( ! F_2 ( V_2 -> V_12 ) && V_2 -> V_13 ) {
F_10 ( V_2 -> V_12 ) ;
V_2 -> V_13 = false ;
}
}
static int F_11 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 = & V_16 -> V_18 ;
V_2 = F_12 ( V_18 , sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_12 = F_13 ( V_18 , L_1 ) ;
if ( F_2 ( V_2 -> V_12 ) && F_14 ( V_2 -> V_12 ) != - V_21 )
return F_14 ( V_2 -> V_12 ) ;
V_2 -> V_5 = F_15 ( V_18 , L_2 ,
V_22 ) ;
if ( F_2 ( V_2 -> V_5 ) &&
F_14 ( V_2 -> V_5 ) != - V_21 &&
F_14 ( V_2 -> V_5 ) != - V_23 ) {
return F_14 ( V_2 -> V_5 ) ;
}
F_16 ( V_18 , L_3 ,
& V_2 -> V_14 ) ;
V_2 -> V_2 . V_18 = V_18 ;
V_2 -> V_2 . V_24 = & V_25 ;
V_2 -> V_2 . V_26 = V_27 ;
F_17 ( V_16 , V_2 ) ;
return F_18 ( & V_2 -> V_2 ) ;
}
static int F_19 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_20 ( V_16 ) ;
F_21 ( & V_2 -> V_2 ) ;
return 0 ;
}
