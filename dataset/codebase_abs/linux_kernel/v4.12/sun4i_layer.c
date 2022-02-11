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
F_4 ( V_9 , V_7 -> V_10 , false ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_6 ( V_9 , V_7 -> V_10 , V_2 ) ;
F_7 ( V_9 , V_7 -> V_10 , V_2 ) ;
F_8 ( V_9 , V_7 -> V_10 , V_2 ) ;
F_4 ( V_9 , V_7 -> V_10 , true ) ;
}
static struct V_6 * F_9 ( struct V_11 * V_12 ,
struct V_8 * V_9 ,
const struct V_13 * V_2 )
{
struct V_6 * V_7 ;
int V_14 ;
V_7 = F_10 ( V_12 -> V_15 , sizeof( * V_7 ) , V_16 ) ;
if ( ! V_7 )
return F_11 ( - V_17 ) ;
V_14 = F_12 ( V_12 , & V_7 -> V_2 , 0 ,
& V_18 ,
V_2 -> V_19 , V_2 -> V_20 ,
V_2 -> type , NULL ) ;
if ( V_14 ) {
F_13 ( V_12 -> V_15 , L_1 ) ;
return F_11 ( V_14 ) ;
}
F_14 ( & V_7 -> V_2 ,
& V_21 ) ;
V_7 -> V_9 = V_9 ;
return V_7 ;
}
struct V_6 * * F_15 ( struct V_11 * V_12 ,
struct V_8 * V_9 )
{
struct V_6 * * V_22 ;
int V_23 ;
V_22 = F_16 ( V_12 -> V_15 , F_17 ( V_24 ) + 1 ,
sizeof( * V_22 ) , V_16 ) ;
if ( ! V_22 )
return F_11 ( - V_17 ) ;
for ( V_23 = 0 ; V_23 < F_17 ( V_24 ) ; V_23 ++ ) {
const struct V_13 * V_2 = & V_24 [ V_23 ] ;
struct V_6 * V_7 ;
V_7 = F_9 ( V_12 , V_9 , V_2 ) ;
if ( F_18 ( V_7 ) ) {
F_13 ( V_12 -> V_15 , L_2 ,
V_23 ? L_3 : L_4 ) ;
return F_19 ( V_7 ) ;
} ;
F_20 ( L_5 ,
V_23 ? L_3 : L_4 , V_2 -> V_25 ) ;
F_21 ( V_9 -> V_26 , F_22 ( V_23 ) ,
V_27 ,
F_23 ( V_2 -> V_25 ) ) ;
V_7 -> V_10 = V_23 ;
V_22 [ V_23 ] = V_7 ;
} ;
return V_22 ;
}
