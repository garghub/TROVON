static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
int V_8 ;
for ( V_8 = F_3 ( V_9 ) - 1 ; V_8 >= 0 ; V_8 -- ) {
if ( V_3 <= V_9 [ V_8 ] &&
V_4 >= V_9 [ V_8 ] ) {
V_7 = V_8 ;
V_7 = V_7 << V_10 ;
return F_4 ( V_6 -> V_11 ,
V_12 ,
V_13 , V_7 ) ;
}
}
return - V_14 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_15 ;
unsigned int V_7 ;
int V_16 ;
V_16 = F_6 ( V_6 -> V_11 , V_12 , & V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
V_7 = ( V_15 & V_13 ) >> V_10 ;
return V_9 [ V_7 ] ;
}
static int F_7 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_5 * V_6 ;
struct V_21 * V_22 = & V_18 -> V_22 ;
struct V_23 * V_24 = F_8 ( V_22 ) ;
struct V_1 * V_2 = NULL ;
struct V_25 V_26 = { } ;
int error ;
V_6 = F_9 ( & V_18 -> V_22 , sizeof( struct V_5 ) , V_27 ) ;
if ( ! V_6 )
return - V_28 ;
V_6 -> V_11 = F_10 ( V_18 , & V_29 ) ;
if ( F_11 ( V_6 -> V_11 ) ) {
error = F_12 ( V_6 -> V_11 ) ;
F_13 ( & V_18 -> V_22 , L_1 ,
error ) ;
return error ;
}
V_26 . V_22 = & V_18 -> V_22 ;
V_26 . V_30 = V_24 ? & V_24 -> V_31 :
F_14 ( V_22 , V_22 -> V_32 , & V_33 ) ;
V_26 . V_34 = V_6 ;
V_26 . V_11 = V_6 -> V_11 ;
V_26 . V_32 = V_22 -> V_32 ;
V_2 = F_15 ( & V_18 -> V_22 , & V_33 , & V_26 ) ;
if ( F_11 ( V_2 ) ) {
F_13 ( & V_18 -> V_22 , L_2 ) ;
return F_12 ( V_2 ) ;
}
V_6 -> V_2 = V_2 ;
F_16 ( V_18 , V_6 ) ;
return 0 ;
}
