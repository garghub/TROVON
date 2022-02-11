static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
F_4 ( V_11 , V_7 -> V_12 , false ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
F_6 ( V_11 , V_7 -> V_12 , V_2 ) ;
F_7 ( V_11 , V_7 -> V_12 , V_2 ) ;
F_8 ( V_11 , V_7 -> V_12 , V_2 ) ;
F_4 ( V_11 , V_7 -> V_12 , true ) ;
}
static struct V_6 * F_9 ( struct V_13 * V_14 ,
enum V_15 type )
{
struct V_8 * V_9 = V_14 -> V_16 ;
struct V_6 * V_7 ;
int V_17 ;
V_7 = F_10 ( V_14 -> V_18 , sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return F_11 ( - V_20 ) ;
V_17 = F_12 ( V_14 , & V_7 -> V_2 , F_13 ( 0 ) ,
& V_21 ,
V_22 ,
F_14 ( V_22 ) ,
type ,
NULL ) ;
if ( V_17 ) {
F_15 ( V_14 -> V_18 , L_1 ) ;
return F_11 ( V_17 ) ;
}
F_16 ( & V_7 -> V_2 ,
& V_23 ) ;
V_7 -> V_9 = V_9 ;
if ( type == V_24 )
V_9 -> V_25 = & V_7 -> V_2 ;
return V_7 ;
}
struct V_6 * * F_17 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = V_14 -> V_16 ;
struct V_6 * * V_26 ;
int V_27 ;
V_26 = F_18 ( V_14 -> V_18 , V_28 , sizeof( * * V_26 ) ,
V_19 ) ;
if ( ! V_26 )
return F_11 ( - V_20 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
enum V_15 type = ( V_27 == 0 )
? V_24
: V_29 ;
struct V_6 * V_7 = V_26 [ V_27 ] ;
V_7 = F_9 ( V_14 , type ) ;
if ( F_19 ( V_7 ) ) {
F_15 ( V_14 -> V_18 , L_2 ,
V_27 ? L_3 : L_4 ) ;
return F_20 ( V_7 ) ;
} ;
F_21 ( L_5 ,
V_27 ? L_3 : L_4 , V_27 ) ;
F_22 ( V_9 -> V_11 -> V_30 , F_23 ( V_27 ) ,
V_31 ,
F_24 ( V_27 ) ) ;
V_7 -> V_12 = V_27 ;
} ;
return V_26 ;
}
