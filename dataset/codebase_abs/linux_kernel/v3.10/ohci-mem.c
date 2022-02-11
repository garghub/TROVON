static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
V_2 -> V_7 = F_5 ( L_1 ,
F_6 ( V_2 ) -> V_8 . V_9 ,
sizeof ( struct V_10 ) ,
32 ,
0 ) ;
if ( ! V_2 -> V_7 )
return - V_11 ;
V_2 -> V_12 = F_5 ( L_2 ,
F_6 ( V_2 ) -> V_8 . V_9 ,
sizeof ( struct V_13 ) ,
16 ,
0 ) ;
if ( ! V_2 -> V_12 ) {
F_7 ( V_2 -> V_7 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 ) {
F_7 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
if ( V_2 -> V_12 ) {
F_7 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
}
static inline struct V_10 *
F_9 ( struct V_1 * V_14 , T_1 V_15 )
{
struct V_10 * V_10 ;
V_15 &= V_16 ;
V_10 = V_14 -> V_17 [ F_10 ( V_15 ) ] ;
while ( V_10 && V_10 -> V_15 != V_15 )
V_10 = V_10 -> V_17 ;
return V_10 ;
}
static struct V_10 *
F_11 ( struct V_1 * V_14 , T_2 V_18 )
{
T_1 V_19 ;
struct V_10 * V_10 ;
V_10 = F_12 ( V_14 -> V_7 , V_18 , & V_19 ) ;
if ( V_10 ) {
memset ( V_10 , 0 , sizeof *V_10 ) ;
V_10 -> V_20 = F_13 ( V_14 , V_19 ) ;
V_10 -> V_15 = V_19 ;
}
return V_10 ;
}
static void
F_14 ( struct V_1 * V_14 , struct V_10 * V_10 )
{
struct V_10 * * V_21 = & V_14 -> V_17 [ F_10 ( V_10 -> V_15 ) ] ;
while ( * V_21 && * V_21 != V_10 )
V_21 = & ( * V_21 ) -> V_17 ;
if ( * V_21 )
* V_21 = V_10 -> V_17 ;
else if ( ( V_10 -> V_22 & F_13 ( V_14 , V_23 ) ) != 0 )
F_15 ( V_14 , L_3 , V_10 ) ;
F_16 ( V_14 -> V_7 , V_10 , V_10 -> V_15 ) ;
}
static struct V_13 *
F_17 ( struct V_1 * V_14 , T_2 V_18 )
{
T_1 V_19 ;
struct V_13 * V_13 ;
V_13 = F_12 ( V_14 -> V_12 , V_18 , & V_19 ) ;
if ( V_13 ) {
memset ( V_13 , 0 , sizeof ( * V_13 ) ) ;
F_3 ( & V_13 -> V_24 ) ;
V_13 -> V_19 = V_19 ;
}
return V_13 ;
}
static void
F_18 ( struct V_1 * V_14 , struct V_13 * V_13 )
{
F_16 ( V_14 -> V_12 , V_13 , V_13 -> V_19 ) ;
}
