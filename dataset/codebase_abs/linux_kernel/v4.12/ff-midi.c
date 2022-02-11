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
struct V_19 * V_5 ;
struct V_16 * V_17 ;
int V_20 ;
V_20 = F_15 ( V_4 -> V_21 , V_4 -> V_21 -> V_22 , 0 ,
V_4 -> V_23 -> V_24 , V_4 -> V_23 -> V_25 ,
& V_5 ) ;
if ( V_20 < 0 )
return V_20 ;
snprintf ( V_5 -> V_18 , sizeof( V_5 -> V_18 ) ,
L_2 , V_4 -> V_21 -> V_26 ) ;
V_5 -> V_6 = V_4 ;
V_5 -> V_27 |= V_28 ;
F_16 ( V_5 , V_29 ,
& V_30 ) ;
V_17 = & V_5 -> V_31 [ V_29 ] ;
F_12 ( V_17 , V_4 -> V_21 -> V_26 ) ;
V_5 -> V_27 |= V_32 ;
F_16 ( V_5 , V_33 ,
& V_34 ) ;
V_17 = & V_5 -> V_31 [ V_33 ] ;
F_12 ( V_17 , V_4 -> V_21 -> V_26 ) ;
V_5 -> V_27 |= V_35 ;
return 0 ;
}
