static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 ;
int V_8 ;
V_6 = F_2 ( V_4 ) ;
F_3 ( V_4 , F_4 ( V_4 ) ) ;
V_8 = V_2 -> type -> V_9 ( V_2 , V_4 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
F_5 ( V_4 , ( V_7 - V_2 -> V_10 . V_11 ) - V_4 -> V_12 ) ;
F_6 ( V_4 , - V_2 -> V_10 . V_11 ) ;
V_4 -> V_13 = V_4 -> V_14 + V_8 ;
F_7 ( V_4 , V_8 ) ;
memmove ( F_2 ( V_4 ) , V_6 , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_15 = V_4 -> V_12 - F_9 ( V_4 ) ;
struct V_16 * V_17 = V_16 ( V_4 ) ;
if ( V_4 -> V_13 != V_4 -> V_14 ) {
memmove ( F_9 ( V_4 ) ,
F_10 ( V_4 ) , V_15 ) ;
V_4 -> V_14 = V_4 -> V_13 ;
}
F_2 ( V_4 ) -> V_18 = F_11 ( V_4 -> V_19 + V_15 -
sizeof( struct V_5 ) ) ;
if ( ! V_17 || ! ( V_17 -> V_20 & V_21 ) )
F_12 ( V_4 ) ;
return 0 ;
}
static struct V_3 * F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_22 )
{
const struct V_23 * V_24 ;
struct V_3 * V_25 = F_14 ( - V_26 ) ;
struct V_16 * V_17 = V_16 ( V_4 ) ;
V_4 -> V_13 += V_2 -> V_10 . V_11 ;
V_24 = F_15 ( V_27 [ V_17 -> V_28 ] ) ;
if ( F_16 ( V_24 && V_24 -> V_29 . V_30 ) )
V_25 = V_24 -> V_29 . V_30 ( V_4 , V_22 ) ;
return V_25 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_16 * V_17 = V_16 ( V_4 ) ;
F_18 ( V_4 ) ;
F_19 ( V_4 , V_4 -> V_31 + sizeof( struct V_5 ) + V_2 -> V_10 . V_11 ) ;
if ( V_17 -> V_20 & V_32 ) {
F_12 ( V_4 ) ;
V_4 -> V_13 -= V_2 -> V_10 . V_11 ;
}
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_33 , V_34 ) ;
}
static void T_4 F_22 ( void )
{
int V_35 ;
V_35 = F_23 ( & V_33 , V_34 ) ;
F_24 ( V_35 ) ;
}
