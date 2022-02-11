static struct V_1 * F_1 ( void )
{
struct V_2 * V_3 = F_2 ( sizeof( struct V_2 ) , V_4 ) ;
if ( V_3 )
V_3 -> V_5 = 0xff ;
return V_3 ? & V_3 -> V_6 : NULL ;
}
static void F_3 ( struct V_1 * V_6 , int V_7 )
{
F_4 ( 128 + 64 + 16 + V_7 + 1 , V_6 -> V_8 ) ;
F_4 ( 128 + 64 + 16 + V_7 + 2 + 1 , V_6 -> V_8 ) ;
F_5 ( 1 ) ;
}
static void F_6 ( struct V_1 * V_6 , int V_7 )
{
F_4 ( 128 + 64 + 16 + V_7 + 4 + 1 , V_6 -> V_8 ) ;
F_4 ( 128 + 64 + 16 + V_7 + 4 + 2 + 1 , V_6 -> V_8 ) ;
F_5 ( 1 ) ;
}
static int F_7 ( struct V_1 * V_6 , T_1 V_9 )
{
int V_7 = F_8 ( V_6 -> V_10 ) ? 0 : 8 ;
int V_11 ;
V_9 += 171200 ;
V_9 /= 800 ;
F_3 ( V_6 , V_7 ) ;
for ( V_11 = 0 ; V_11 < 13 ; V_11 ++ )
if ( V_9 & ( 1 << V_11 ) )
F_6 ( V_6 , V_7 ) ;
else
F_3 ( V_6 , V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_6 ( V_6 , V_7 ) ;
F_3 ( V_6 , V_7 ) ;
F_6 ( V_6 , V_7 ) ;
F_9 ( 0xd0 + V_7 , V_6 -> V_8 ) ;
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_6 )
{
return 0xffff * ! ( F_11 ( V_6 -> V_8 ) & 2 ) ;
}
static int F_12 ( struct V_1 * V_6 , bool V_10 , int V_12 )
{
struct V_2 * V_3 = F_13 ( V_6 , struct V_2 , V_6 ) ;
int V_5 = V_3 -> V_5 ;
if ( V_10 ) {
F_9 ( 0xd0 , V_6 -> V_8 ) ;
return 0 ;
}
if ( V_12 == 0 ) {
F_9 ( 0x48 , V_6 -> V_8 ) ;
F_5 ( V_5 * 3 ) ;
} else if ( V_5 < V_12 ) {
F_9 ( 0x98 , V_6 -> V_8 ) ;
for (; V_5 < V_12 ; V_5 ++ )
F_14 ( 3000 ) ;
} else if ( V_5 > V_12 ) {
F_9 ( 0x58 , V_6 -> V_8 ) ;
for (; V_5 > V_12 ; V_5 -- )
F_14 ( 3000 ) ;
}
F_9 ( 0xd8 , V_6 -> V_8 ) ;
V_3 -> V_5 = V_12 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_6 )
{
F_9 ( 0x90 , V_6 -> V_8 ) ;
F_5 ( 3000 ) ;
F_9 ( 0xc0 , V_6 -> V_8 ) ;
return 0 ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_13 . V_14 , V_15 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_13 . V_14 ) ;
}
