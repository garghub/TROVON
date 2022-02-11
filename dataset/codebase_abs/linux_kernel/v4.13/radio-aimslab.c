static struct V_1 * F_1 ( void )
{
struct V_2 * V_3 = F_2 ( sizeof( struct V_2 ) , V_4 ) ;
if ( V_3 )
V_3 -> V_5 = 0xff ;
return V_3 ? & V_3 -> V_6 : NULL ;
}
static void F_3 ( void * V_7 , T_1 V_8 )
{
struct V_1 * V_6 = V_7 ;
struct V_2 * V_3 = F_4 ( V_6 , struct V_2 , V_6 ) ;
T_1 V_9 = V_10 | V_11 | V_12 ;
if ( ! F_5 ( V_3 -> V_6 . V_13 ) )
V_9 |= V_14 ;
if ( V_8 & V_15 )
V_9 |= V_16 ;
if ( V_8 & V_17 )
V_9 |= V_18 ;
if ( V_8 & V_19 )
V_9 |= V_20 ;
F_6 ( V_9 , V_3 -> V_6 . V_21 ) ;
}
static int F_7 ( struct V_1 * V_6 , T_2 V_22 )
{
F_8 ( V_22 , V_6 , F_3 ) ;
return 0 ;
}
static T_2 F_9 ( struct V_1 * V_6 )
{
return 0xffff * ! ( F_10 ( V_6 -> V_21 ) & 2 ) ;
}
static int F_11 ( struct V_1 * V_6 , bool V_13 , int V_23 )
{
struct V_2 * V_3 = F_4 ( V_6 , struct V_2 , V_6 ) ;
int V_5 = V_3 -> V_5 ;
if ( V_13 ) {
F_12 ( 0xd0 , V_6 -> V_21 ) ;
return 0 ;
}
if ( V_23 == 0 ) {
F_12 ( 0x48 , V_6 -> V_21 ) ;
F_13 ( V_5 * 3 ) ;
} else if ( V_5 < V_23 ) {
F_12 ( 0x98 , V_6 -> V_21 ) ;
for (; V_5 < V_23 ; V_5 ++ )
F_14 ( 3 ) ;
} else if ( V_5 > V_23 ) {
F_12 ( 0x58 , V_6 -> V_21 ) ;
for (; V_5 > V_23 ; V_5 -- )
F_14 ( 3 ) ;
}
F_12 ( 0xd8 , V_6 -> V_21 ) ;
V_3 -> V_5 = V_23 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_6 )
{
F_12 ( 0x90 , V_6 -> V_21 ) ;
F_13 ( 3000 ) ;
F_12 ( 0xc0 , V_6 -> V_21 ) ;
return 0 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_24 . V_25 , V_26 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_24 . V_25 ) ;
}
