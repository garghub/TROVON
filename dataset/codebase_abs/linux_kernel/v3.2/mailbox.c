static inline int F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_2 V_3 , T_1 V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static T_3 F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
& ( (struct V_8 * ) V_5 -> V_9 ) -> V_10 ;
T_3 V_11 ;
V_11 = F_1 ( V_7 -> V_12 ) ;
V_11 |= ( ( T_3 ) F_1 ( V_7 -> V_13 ) ) << 16 ;
return V_11 ;
}
static void
F_6 ( struct V_4 * V_5 , T_3 V_11 )
{
struct V_6 * V_7 =
& ( (struct V_8 * ) V_5 -> V_9 ) -> V_14 ;
F_3 ( V_11 & 0xffff , V_7 -> V_12 ) ;
F_3 ( V_11 >> 16 , V_7 -> V_13 ) ;
}
static int F_7 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
& ( (struct V_8 * ) V_5 -> V_9 ) -> V_10 ;
return F_1 ( V_7 -> V_15 ) ;
}
static void
F_9 ( struct V_4 * V_5 , T_4 V_16 )
{
if ( V_16 == V_17 )
F_10 ( V_5 -> V_16 ) ;
}
static void
F_11 ( struct V_4 * V_5 , T_4 V_16 )
{
if ( V_16 == V_17 )
F_12 ( V_5 -> V_16 ) ;
}
static int
F_13 ( struct V_4 * V_5 , T_4 V_16 )
{
if ( V_16 == V_18 )
return 0 ;
return 1 ;
}
static int T_5 F_14 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_23 ;
struct V_4 * * V_24 ;
V_24 = V_25 ;
V_24 [ 0 ] -> V_16 = F_15 ( V_20 , L_1 ) ;
V_22 = F_16 ( V_20 , V_26 , 0 ) ;
V_2 = F_17 ( V_22 -> V_27 , F_18 ( V_22 ) ) ;
if ( ! V_2 )
return - V_28 ;
V_23 = F_19 ( & V_20 -> V_29 , V_24 ) ;
if ( V_23 ) {
F_20 ( V_2 ) ;
return V_23 ;
}
return 0 ;
}
static int T_6 F_21 ( struct V_19 * V_20 )
{
F_22 () ;
F_20 ( V_2 ) ;
return 0 ;
}
static int T_7 F_23 ( void )
{
return F_24 ( & V_30 ) ;
}
static void T_8 F_25 ( void )
{
F_26 ( & V_30 ) ;
}
