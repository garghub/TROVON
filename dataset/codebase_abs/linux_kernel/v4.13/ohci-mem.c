static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
V_2 -> V_8 = F_5 ( L_1 ,
F_6 ( V_2 ) -> V_9 . V_10 ,
sizeof ( struct V_11 ) ,
32 ,
0 ) ;
if ( ! V_2 -> V_8 )
return - V_12 ;
V_2 -> V_13 = F_5 ( L_2 ,
F_6 ( V_2 ) -> V_9 . V_10 ,
sizeof ( struct V_14 ) ,
16 ,
0 ) ;
if ( ! V_2 -> V_13 ) {
F_7 ( V_2 -> V_8 ) ;
return - V_12 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_7 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
if ( V_2 -> V_13 ) {
F_7 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
}
static inline struct V_11 *
F_9 ( struct V_1 * V_15 , T_1 V_16 )
{
struct V_11 * V_11 ;
V_16 &= V_17 ;
V_11 = V_15 -> V_18 [ F_10 ( V_16 ) ] ;
while ( V_11 && V_11 -> V_16 != V_16 )
V_11 = V_11 -> V_18 ;
return V_11 ;
}
static struct V_11 *
F_11 ( struct V_1 * V_15 , T_2 V_19 )
{
T_1 V_20 ;
struct V_11 * V_11 ;
V_11 = F_12 ( V_15 -> V_8 , V_19 , & V_20 ) ;
if ( V_11 ) {
V_11 -> V_21 = F_13 ( V_15 , V_20 ) ;
V_11 -> V_16 = V_20 ;
}
return V_11 ;
}
static void
F_14 ( struct V_1 * V_15 , struct V_11 * V_11 )
{
struct V_11 * * V_22 = & V_15 -> V_18 [ F_10 ( V_11 -> V_16 ) ] ;
while ( * V_22 && * V_22 != V_11 )
V_22 = & ( * V_22 ) -> V_18 ;
if ( * V_22 )
* V_22 = V_11 -> V_18 ;
else if ( ( V_11 -> V_23 & F_13 ( V_15 , V_24 ) ) != 0 )
F_15 ( V_15 , L_3 , V_11 ) ;
F_16 ( V_15 -> V_8 , V_11 , V_11 -> V_16 ) ;
}
static struct V_14 *
F_17 ( struct V_1 * V_15 , T_2 V_19 )
{
T_1 V_20 ;
struct V_14 * V_14 ;
V_14 = F_12 ( V_15 -> V_13 , V_19 , & V_20 ) ;
if ( V_14 ) {
F_3 ( & V_14 -> V_25 ) ;
V_14 -> V_20 = V_20 ;
}
return V_14 ;
}
static void
F_18 ( struct V_1 * V_15 , struct V_14 * V_14 )
{
F_16 ( V_15 -> V_13 , V_14 , V_14 -> V_20 ) ;
}
