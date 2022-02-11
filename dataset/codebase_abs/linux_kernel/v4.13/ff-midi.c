static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
V_4 -> V_7 [ V_2 -> V_8 ] = 0 ;
V_4 -> V_9 [ V_2 -> V_8 ] = false ;
F_3 ( V_4 -> V_10 [ V_2 -> V_8 ] ) = V_2 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_6 ( & V_4 -> V_11 [ V_2 -> V_8 ] ) ;
F_3 ( V_4 -> V_10 [ V_2 -> V_8 ] ) = NULL ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned long V_13 ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
if ( V_12 )
F_3 ( V_4 -> V_15 [ V_2 -> V_8 ] ) =
V_2 ;
else
F_3 ( V_4 -> V_15 [ V_2 -> V_8 ] ) = NULL ;
F_9 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
unsigned long V_13 ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
if ( V_12 || ! V_4 -> V_9 [ V_2 -> V_8 ] )
F_11 ( & V_4 -> V_11 [ V_2 -> V_8 ] ) ;
F_9 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_12 ( struct V_16 * V_17 ,
const char * const V_18 )
{
struct V_1 * V_2 ;
F_13 (substream, &stream->substreams, list) {
snprintf ( V_2 -> V_18 , sizeof( V_2 -> V_18 ) ,
L_1 , V_18 , V_2 -> V_8 + 1 ) ;
}
}
int F_14 ( struct V_3 * V_4 )
{
static const struct V_19 V_20 = {
. V_21 = F_1 ,
. V_22 = F_4 ,
. V_23 = F_7 ,
} ;
static const struct V_19 V_24 = {
. V_21 = F_2 ,
. V_22 = F_5 ,
. V_23 = F_10 ,
} ;
struct V_25 * V_5 ;
struct V_16 * V_17 ;
int V_26 ;
V_26 = F_15 ( V_4 -> V_27 , V_4 -> V_27 -> V_28 , 0 ,
V_4 -> V_29 -> V_30 , V_4 -> V_29 -> V_31 ,
& V_5 ) ;
if ( V_26 < 0 )
return V_26 ;
snprintf ( V_5 -> V_18 , sizeof( V_5 -> V_18 ) ,
L_2 , V_4 -> V_27 -> V_32 ) ;
V_5 -> V_6 = V_4 ;
V_5 -> V_33 |= V_34 ;
F_16 ( V_5 , V_35 ,
& V_20 ) ;
V_17 = & V_5 -> V_36 [ V_35 ] ;
F_12 ( V_17 , V_4 -> V_27 -> V_32 ) ;
V_5 -> V_33 |= V_37 ;
F_16 ( V_5 , V_38 ,
& V_24 ) ;
V_17 = & V_5 -> V_36 [ V_38 ] ;
F_12 ( V_17 , V_4 -> V_27 -> V_32 ) ;
V_5 -> V_33 |= V_39 ;
return 0 ;
}
