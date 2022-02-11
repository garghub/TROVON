static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_3 ( & V_4 -> V_7 [ V_2 -> V_8 ] ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_7 ( & V_4 -> V_7 [ V_2 -> V_8 ] ) ;
}
static void F_8 ( struct V_1 * V_9 , int V_10 )
{
struct V_3 * V_4 = V_9 -> V_5 -> V_6 ;
unsigned long V_11 ;
F_9 ( & V_4 -> V_12 , V_11 ) ;
if ( V_10 )
V_4 -> V_13 [ V_9 -> V_8 ] = V_9 ;
else
V_4 -> V_13 [ V_9 -> V_8 ] = NULL ;
F_10 ( & V_4 -> V_12 , V_11 ) ;
}
static void F_11 ( struct V_1 * V_9 , int V_10 )
{
struct V_3 * V_4 = V_9 -> V_5 -> V_6 ;
unsigned long V_11 ;
F_9 ( & V_4 -> V_12 , V_11 ) ;
if ( V_10 )
F_12 ( & V_4 -> V_7 [ V_9 -> V_8 ] ,
V_9 ) ;
F_10 ( & V_4 -> V_12 , V_11 ) ;
}
int F_13 ( struct V_3 * V_4 )
{
static const struct V_14 V_15 = {
. V_16 = F_1 ,
. V_17 = F_4 ,
. V_18 = F_8 ,
} ;
static const struct V_14 V_19 = {
. V_16 = F_2 ,
. V_17 = F_5 ,
. V_20 = F_6 ,
. V_18 = F_11 ,
} ;
struct V_21 * V_5 ;
struct V_22 * V_23 ;
struct V_1 * V_24 ;
int V_25 ;
V_25 = F_14 ( V_4 -> V_26 , V_4 -> V_26 -> V_27 , 0 ,
V_4 -> V_28 -> V_29 ,
V_4 -> V_28 -> V_30 ,
& V_5 ) ;
if ( V_25 < 0 )
return V_25 ;
snprintf ( V_5 -> V_31 , sizeof( V_5 -> V_31 ) ,
L_1 , V_4 -> V_26 -> V_32 ) ;
V_5 -> V_6 = V_4 ;
V_5 -> V_33 |= V_34 ;
F_15 ( V_5 , V_35 ,
& V_15 ) ;
V_23 = & V_5 -> V_36 [ V_35 ] ;
F_16 (subs, &stream->substreams, list) {
if ( V_24 -> V_8 < V_4 -> V_28 -> V_30 ) {
snprintf ( V_24 -> V_31 , sizeof( V_24 -> V_31 ) ,
L_2 ,
V_4 -> V_26 -> V_32 , V_24 -> V_8 + 1 ) ;
}
}
V_5 -> V_33 |= V_37 ;
F_15 ( V_5 , V_38 ,
& V_19 ) ;
V_23 = & V_5 -> V_36 [ V_38 ] ;
F_16 (subs, &stream->substreams, list) {
if ( V_24 -> V_8 < V_4 -> V_28 -> V_29 ) {
snprintf ( V_24 -> V_31 , sizeof( V_24 -> V_31 ) ,
L_2 ,
V_4 -> V_26 -> V_32 , V_24 -> V_8 + 1 ) ;
}
}
V_5 -> V_33 |= V_39 ;
return 0 ;
}
