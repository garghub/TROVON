static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_3 ( V_8 , V_6 -> V_9 , false ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_5 ( V_8 , V_6 -> V_9 , V_2 ) ;
F_6 ( V_8 , V_6 -> V_9 , V_2 ) ;
F_7 ( V_8 , V_6 -> V_9 , V_2 ) ;
F_3 ( V_8 , V_6 -> V_9 , true ) ;
}
static struct V_5 * F_8 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
const struct V_12 * V_2 )
{
struct V_5 * V_6 ;
int V_13 ;
V_6 = F_9 ( V_11 -> V_14 , sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return F_10 ( - V_16 ) ;
V_13 = F_11 ( V_11 , & V_6 -> V_2 , 0 ,
& V_17 ,
V_2 -> V_18 , V_2 -> V_19 ,
NULL , V_2 -> type , NULL ) ;
if ( V_13 ) {
F_12 ( V_11 -> V_14 , L_1 ) ;
return F_10 ( V_13 ) ;
}
F_13 ( & V_6 -> V_2 ,
& V_20 ) ;
V_6 -> V_8 = V_8 ;
return V_6 ;
}
struct V_1 * * F_14 ( struct V_10 * V_11 ,
struct V_21 * V_22 )
{
struct V_1 * * V_23 ;
struct V_7 * V_8 = F_15 ( V_22 ) ;
int V_24 ;
V_23 = F_16 ( V_11 -> V_14 , F_17 ( V_25 ) + 1 ,
sizeof( * V_23 ) , V_15 ) ;
if ( ! V_23 )
return F_10 ( - V_16 ) ;
for ( V_24 = 0 ; V_24 < F_17 ( V_25 ) ; V_24 ++ ) {
const struct V_12 * V_2 = & V_25 [ V_24 ] ;
struct V_5 * V_6 ;
V_6 = F_8 ( V_11 , V_8 , V_2 ) ;
if ( F_18 ( V_6 ) ) {
F_12 ( V_11 -> V_14 , L_2 ,
V_24 ? L_3 : L_4 ) ;
return F_19 ( V_6 ) ;
} ;
F_20 ( L_5 ,
V_24 ? L_3 : L_4 , V_2 -> V_26 ) ;
F_21 ( V_22 -> V_27 , F_22 ( V_24 ) ,
V_28 ,
F_23 ( V_2 -> V_26 ) ) ;
V_6 -> V_9 = V_24 ;
V_23 [ V_24 ] = & V_6 -> V_2 ;
} ;
return V_23 ;
}
