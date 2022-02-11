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
}
static void F_8 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 -> V_2 ) ;
F_1 ( V_2 , 1 ) ;
if ( ! F_2 ( V_2 -> V_12 ) && V_2 -> V_13 ) {
F_9 ( V_2 -> V_12 ) ;
V_2 -> V_13 = false ;
}
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 = & V_15 -> V_17 ;
V_2 = F_11 ( V_17 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_12 = F_12 ( V_17 , L_1 ) ;
if ( F_2 ( V_2 -> V_12 ) && F_13 ( V_2 -> V_12 ) != - V_20 )
return F_13 ( V_2 -> V_12 ) ;
V_2 -> V_5 = F_14 ( V_17 , L_2 ,
V_21 ) ;
if ( F_2 ( V_2 -> V_5 ) &&
F_13 ( V_2 -> V_5 ) != - V_20 &&
F_13 ( V_2 -> V_5 ) != - V_22 ) {
return F_13 ( V_2 -> V_5 ) ;
}
V_2 -> V_2 . V_17 = V_17 ;
V_2 -> V_2 . V_23 = & V_24 ;
V_2 -> V_2 . V_25 = V_26 ;
F_15 ( V_15 , V_2 ) ;
return F_16 ( & V_2 -> V_2 ) ;
}
static int F_17 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_18 ( V_15 ) ;
F_19 ( & V_2 -> V_2 ) ;
return 0 ;
}
