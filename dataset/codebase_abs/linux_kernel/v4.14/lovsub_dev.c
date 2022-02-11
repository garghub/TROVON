static int F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , struct V_3 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
int V_11 ;
V_6 -> V_12 = V_4 -> V_12 ;
V_10 = V_6 -> V_13 ;
V_11 = V_10 -> V_14 -> V_15 ( V_2 , V_6 , V_10 -> V_16 , NULL ) ;
if ( V_11 ) {
V_6 -> V_12 = NULL ;
return V_11 ;
}
F_3 ( V_6 ) ;
F_4 ( & V_6 -> V_17 , L_1 , & V_18 ) ;
V_8 -> V_19 = F_5 ( V_6 ) ;
return V_11 ;
}
static struct V_3 * F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_6 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_4 ) ;
V_6 = F_7 ( V_8 -> V_19 ) ;
V_8 -> V_19 = NULL ;
return V_6 ;
}
static struct V_3 * F_8 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_3 * V_6 = F_7 ( V_8 -> V_19 ) ;
if ( F_9 ( & V_4 -> V_20 ) && V_4 -> V_12 ) {
F_10 ( V_21 , V_22 , NULL ) ;
F_11 ( V_2 , V_4 -> V_12 , & V_21 , V_23 ) ;
}
F_12 ( F_5 ( V_4 ) ) ;
F_13 ( V_8 ) ;
return V_6 ;
}
static struct V_3 * F_14 ( const struct V_1 * V_2 ,
struct V_9 * V_24 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
V_8 = F_15 ( sizeof( * V_8 ) , V_27 ) ;
if ( V_8 ) {
int V_28 ;
V_28 = F_16 ( & V_8 -> V_29 , V_24 ) ;
if ( V_28 == 0 ) {
V_4 = F_17 ( V_8 ) ;
V_4 -> V_30 = & V_31 ;
} else {
V_4 = F_18 ( V_28 ) ;
}
} else {
V_4 = F_18 ( - V_32 ) ;
}
return V_4 ;
}
