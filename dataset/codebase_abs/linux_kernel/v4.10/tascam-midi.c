static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
V_4 -> V_7 [ V_2 -> V_8 ] = 0 ;
V_4 -> V_9 [ V_2 -> V_8 ] = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_5 ( & V_4 -> V_10 [ V_2 -> V_8 ] ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_11 , int V_12 )
{
struct V_3 * V_4 = V_11 -> V_5 -> V_6 ;
unsigned long V_13 ;
F_7 ( & V_4 -> V_14 , V_13 ) ;
if ( V_12 )
V_4 -> V_15 [ V_11 -> V_8 ] = V_11 ;
else
V_4 -> V_15 [ V_11 -> V_8 ] = NULL ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_9 ( struct V_1 * V_11 , int V_12 )
{
struct V_3 * V_4 = V_11 -> V_5 -> V_6 ;
unsigned long V_13 ;
F_7 ( & V_4 -> V_14 , V_13 ) ;
if ( V_12 )
F_10 ( & V_4 -> V_10 [ V_11 -> V_8 ] ,
V_11 ) ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
}
int F_11 ( struct V_3 * V_4 )
{
struct V_16 * V_5 ;
struct V_17 * V_18 ;
struct V_1 * V_19 ;
int V_20 ;
V_20 = F_12 ( V_4 -> V_21 , V_4 -> V_21 -> V_22 , 0 ,
V_4 -> V_23 -> V_24 ,
V_4 -> V_23 -> V_25 ,
& V_5 ) ;
if ( V_20 < 0 )
return V_20 ;
snprintf ( V_5 -> V_26 , sizeof( V_5 -> V_26 ) ,
L_1 , V_4 -> V_21 -> V_27 ) ;
V_5 -> V_6 = V_4 ;
V_5 -> V_28 |= V_29 ;
F_13 ( V_5 , V_30 ,
& V_31 ) ;
V_18 = & V_5 -> V_32 [ V_30 ] ;
F_14 (subs, &stream->substreams, list) {
if ( V_19 -> V_8 < V_4 -> V_23 -> V_25 ) {
snprintf ( V_19 -> V_26 , sizeof( V_19 -> V_26 ) ,
L_2 ,
V_4 -> V_21 -> V_27 , V_19 -> V_8 + 1 ) ;
}
}
V_5 -> V_28 |= V_33 ;
F_13 ( V_5 , V_34 ,
& V_35 ) ;
V_18 = & V_5 -> V_32 [ V_34 ] ;
F_14 (subs, &stream->substreams, list) {
if ( V_19 -> V_8 < V_4 -> V_23 -> V_24 ) {
snprintf ( V_19 -> V_26 , sizeof( V_19 -> V_26 ) ,
L_2 ,
V_4 -> V_21 -> V_27 , V_19 -> V_8 + 1 ) ;
}
}
V_5 -> V_28 |= V_36 ;
return 0 ;
}
