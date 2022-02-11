static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 [ V_6 -> V_8 ] ;
for ( V_4 = 0 ; V_4 < V_6 -> V_8 ; V_4 ++ )
V_7 [ V_4 ] = V_3 ;
F_2 ( V_6 -> V_8 , V_6 -> V_9 ,
V_7 ) ;
}
static void F_3 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_2 ,
struct V_1 , V_2 ) ;
if ( ! F_5 ( V_2 -> V_12 ) && ! V_2 -> V_13 ) {
F_6 ( V_2 -> V_12 ) ;
V_2 -> V_13 = true ;
}
F_1 ( V_2 , 1 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_2 ,
struct V_1 , V_2 ) ;
F_1 ( V_2 , 0 ) ;
}
static void F_8 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_2 ,
struct V_1 , V_2 ) ;
F_1 ( V_2 , 1 ) ;
if ( ! F_5 ( V_2 -> V_12 ) && V_2 -> V_13 ) {
F_9 ( V_2 -> V_12 ) ;
V_2 -> V_13 = false ;
}
}
static void F_10 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_4 ( V_11 -> V_2 ,
struct V_1 , V_2 ) ;
F_11 ( V_2 -> V_6 ) ;
if ( ! F_5 ( V_2 -> V_12 ) )
F_12 ( V_2 -> V_12 ) ;
F_13 ( V_2 ) ;
}
struct V_14 * F_14 ( struct V_10 * V_11 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return F_16 ( - V_19 ) ;
V_2 -> V_12 = F_17 ( V_16 , L_1 ) ;
if ( F_5 ( V_2 -> V_12 ) &&
F_18 ( V_2 -> V_12 ) != - V_20 ) {
V_17 = F_18 ( V_2 -> V_12 ) ;
goto free;
}
V_2 -> V_6 = F_19 ( V_16 , L_2 , V_21 ) ;
if ( F_5 ( V_2 -> V_6 ) ) {
V_17 = F_18 ( V_2 -> V_6 ) ;
goto F_12;
}
V_2 -> V_2 . V_22 = & V_23 ;
return & V_2 -> V_2 ;
F_12:
if ( ! F_5 ( V_2 -> V_12 ) )
F_12 ( V_2 -> V_12 ) ;
free:
F_13 ( V_2 ) ;
return F_16 ( V_17 ) ;
}
