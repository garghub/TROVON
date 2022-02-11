static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 = V_6 -> V_7 * 4 ;
F_3 ( V_4 , F_4 ( V_4 ) ) ;
F_5 ( V_4 , - V_2 -> V_8 . V_9 ) ;
V_4 -> V_10 = V_4 -> V_11 +
F_6 ( struct V_5 , V_12 ) ;
V_4 -> V_13 = V_4 -> V_11 + V_7 ;
F_7 ( V_4 , V_7 ) ;
memmove ( F_8 ( V_4 ) , V_6 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_7 = V_4 -> V_14 - F_10 ( V_4 ) ;
struct V_15 * V_16 = V_15 ( V_4 ) ;
if ( V_4 -> V_13 != V_4 -> V_11 ) {
memmove ( F_10 ( V_4 ) ,
F_8 ( V_4 ) , V_7 ) ;
V_4 -> V_11 = V_4 -> V_13 ;
}
F_2 ( V_4 ) -> V_17 = F_11 ( V_4 -> V_18 + V_7 ) ;
if ( ! V_16 || ! ( V_16 -> V_19 & V_20 ) )
F_12 ( V_4 ) ;
return 0 ;
}
static struct V_3 * F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_21 )
{
const struct V_22 * V_23 ;
struct V_3 * V_24 = F_14 ( - V_25 ) ;
struct V_15 * V_16 = V_15 ( V_4 ) ;
V_4 -> V_13 += V_2 -> V_8 . V_9 ;
V_23 = F_15 ( V_26 [ V_16 -> V_27 ] ) ;
if ( F_16 ( V_23 && V_23 -> V_28 . V_29 ) )
V_24 = V_23 -> V_28 . V_29 ( V_4 , V_21 ) ;
return V_24 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_15 * V_16 = V_15 ( V_4 ) ;
F_18 ( V_4 ) ;
F_19 ( V_4 , V_4 -> V_30 + sizeof( struct V_5 ) + V_2 -> V_8 . V_9 ) ;
if ( V_16 -> V_19 & V_31 ) {
F_12 ( V_4 ) ;
V_4 -> V_13 -= V_2 -> V_8 . V_9 ;
}
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_32 , V_33 ) ;
}
static void T_3 F_22 ( void )
{
int V_34 ;
V_34 = F_23 ( & V_32 , V_33 ) ;
F_24 ( V_34 ) ;
}
