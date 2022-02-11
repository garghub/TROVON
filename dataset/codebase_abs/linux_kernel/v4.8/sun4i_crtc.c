static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_9 ;
if ( V_2 -> V_10 -> V_11 ) {
F_3 ( F_4 ( V_2 ) != 0 ) ;
F_5 ( & V_8 -> V_12 , V_9 ) ;
V_6 -> V_11 = V_2 -> V_10 -> V_11 ;
F_6 ( & V_8 -> V_12 , V_9 ) ;
V_2 -> V_10 -> V_11 = NULL ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_6 -> V_14 ;
struct V_15 * V_11 = V_2 -> V_10 -> V_11 ;
F_8 ( L_1 ) ;
F_9 ( V_14 -> V_16 ) ;
if ( V_11 ) {
V_2 -> V_10 -> V_11 = NULL ;
F_10 ( & V_2 -> V_8 -> V_12 ) ;
if ( F_4 ( V_2 ) == 0 )
F_11 ( V_2 , V_11 ) ;
else
F_12 ( V_2 , V_11 ) ;
F_13 ( & V_2 -> V_8 -> V_12 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_6 -> V_14 ;
F_8 ( L_2 ) ;
F_15 ( V_14 -> V_17 ) ;
if ( V_2 -> V_10 -> V_11 && ! V_2 -> V_10 -> V_18 ) {
F_10 ( & V_2 -> V_8 -> V_12 ) ;
F_12 ( V_2 , V_2 -> V_10 -> V_11 ) ;
F_13 ( & V_2 -> V_8 -> V_12 ) ;
V_2 -> V_10 -> V_11 = NULL ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_13 * V_14 = V_6 -> V_14 ;
F_8 ( L_3 ) ;
F_17 ( V_14 -> V_17 ) ;
}
struct V_5 * F_18 ( struct V_7 * V_19 )
{
struct V_13 * V_14 = V_19 -> V_20 ;
struct V_5 * V_6 ;
int V_21 ;
V_6 = F_19 ( V_19 -> V_8 , sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_14 = V_14 ;
V_21 = F_20 ( V_19 , & V_6 -> V_2 ,
V_14 -> V_23 ,
NULL ,
& V_24 ,
NULL ) ;
if ( V_21 ) {
F_21 ( V_19 -> V_8 , L_4 ) ;
return NULL ;
}
F_22 ( & V_6 -> V_2 , & V_25 ) ;
return V_6 ;
}
