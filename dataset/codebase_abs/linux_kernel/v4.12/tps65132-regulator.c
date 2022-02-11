static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
struct V_6 * V_7 = & V_4 -> V_8 [ V_5 ] ;
int V_9 ;
if ( ! F_4 ( V_7 -> V_10 ) ) {
F_5 ( V_7 -> V_10 , 1 ) ;
V_7 -> V_11 = 1 ;
}
if ( V_2 -> V_12 -> V_13 ==
V_14 ) {
V_9 = F_6 ( V_2 , false ) ;
if ( V_9 < 0 ) {
F_7 ( V_4 -> V_15 , L_1 ,
V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
struct V_6 * V_7 = & V_4 -> V_8 [ V_5 ] ;
if ( ! F_4 ( V_7 -> V_10 ) ) {
F_5 ( V_7 -> V_10 , 0 ) ;
V_7 -> V_11 = 0 ;
}
if ( ! F_4 ( V_7 -> V_16 ) ) {
F_5 ( V_7 -> V_16 , 1 ) ;
F_9 ( V_7 -> V_17 , V_7 -> V_17 +
V_18 ) ;
F_5 ( V_7 -> V_16 , 0 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
struct V_6 * V_7 = & V_4 -> V_8 [ V_5 ] ;
if ( ! F_4 ( V_7 -> V_10 ) )
return V_7 -> V_11 ;
return 1 ;
}
static int F_11 ( struct V_19 * V_20 ,
const struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_25 ;
struct V_6 * V_7 = & V_4 -> V_8 [ V_22 -> V_5 ] ;
int V_9 ;
V_7 -> V_10 = F_12 ( V_4 -> V_15 ,
L_2 , 0 , & V_20 -> V_26 , 0 , L_2 ) ;
if ( F_4 ( V_7 -> V_10 ) ) {
V_9 = F_13 ( V_7 -> V_10 ) ;
if ( V_9 == - V_27 )
return V_9 ;
return 0 ;
}
V_7 -> V_16 = F_12 (
V_4 -> V_15 , L_3 , 0 ,
& V_20 -> V_26 , 0 , L_3 ) ;
if ( F_4 ( V_7 -> V_16 ) ) {
V_9 = F_13 ( V_7 -> V_16 ) ;
if ( V_9 == - V_27 )
return V_9 ;
return 0 ;
}
V_9 = F_14 ( V_20 , L_4 ,
& V_7 -> V_17 ) ;
if ( V_9 < 0 ) {
F_7 ( V_4 -> V_15 , L_5 ,
V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_15 ( struct V_28 * V_29 ,
const struct V_30 * V_31 )
{
struct V_32 * V_15 = & V_29 -> V_15 ;
struct V_3 * V_4 ;
struct V_23 V_24 = { } ;
int V_5 ;
int V_9 ;
V_4 = F_16 ( V_15 , sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 )
return - V_34 ;
V_4 -> V_35 = F_17 ( V_29 , & V_36 ) ;
if ( F_4 ( V_4 -> V_35 ) ) {
V_9 = F_13 ( V_4 -> V_35 ) ;
F_7 ( V_15 , L_6 , V_9 ) ;
return V_9 ;
}
F_18 ( V_29 , V_4 ) ;
V_4 -> V_15 = V_15 ;
for ( V_5 = 0 ; V_5 < V_37 ; ++ V_5 ) {
V_4 -> V_38 [ V_5 ] = & V_39 [ V_5 ] ;
V_24 . V_40 = V_4 -> V_35 ;
V_24 . V_15 = V_15 ;
V_24 . V_25 = V_4 ;
V_4 -> V_2 [ V_5 ] = F_19 ( V_15 ,
V_4 -> V_38 [ V_5 ] , & V_24 ) ;
if ( F_4 ( V_4 -> V_2 [ V_5 ] ) ) {
V_9 = F_13 ( V_4 -> V_2 [ V_5 ] ) ;
F_7 ( V_15 , L_7 ,
V_4 -> V_38 [ V_5 ] -> V_41 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
