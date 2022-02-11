static void F_1 ( void T_1 * V_1 , unsigned int V_2 , int V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_1 ) ;
if ( V_3 & 0x1 )
V_4 = V_4 | ( 0x1 << V_2 ) ;
else
V_4 = V_4 & ~ ( 0x1 << V_2 ) ;
F_3 ( V_4 , V_1 ) ;
}
static int F_4 ( struct V_5 * V_6 , unsigned V_2 )
{
unsigned int V_4 ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
V_4 = F_2 ( V_8 -> V_9 + V_10 ) ;
V_4 = V_4 | ( 0x1 << V_2 ) ;
F_3 ( V_4 , V_8 -> V_9 + V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 , unsigned V_2 , int V_3 )
{
unsigned int V_4 ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
F_1 ( V_8 -> V_9 + V_11 , V_2 , V_3 ) ;
V_4 = F_2 ( V_8 -> V_9 + V_10 ) ;
V_4 = V_4 & ~ ( 0x1 << V_2 ) ;
F_3 ( V_4 , V_8 -> V_9 + V_10 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , unsigned V_2 )
{
unsigned int V_4 ;
int V_12 = 0 ;
struct V_7 * V_8 = F_5 ( V_6 ) ;
V_4 = F_2 ( V_8 -> V_9 + V_13 ) ;
V_12 = ( int ) ( ( V_4 >> V_2 ) & 0x1 ) ;
return V_12 ;
}
static void F_8 ( struct V_5 * V_6 , unsigned V_2 , int V_3 )
{
struct V_7 * V_8 = F_5 ( V_6 ) ;
F_1 ( V_8 -> V_9 + V_11 , V_2 , V_3 ) ;
}
static int T_2 F_9 ( void )
{
struct V_14 * V_15 ;
int V_16 ;
struct V_7 * V_17 ;
F_10 (np, NULL, L_1 ) {
F_11 ( L_2 , V_15 -> V_18 ) ;
V_17 = F_12 ( sizeof( * V_17 ) , V_19 ) ;
if ( ! V_17 ) {
F_13 ( L_3 ,
V_15 -> V_18 ) ;
continue;
}
V_17 -> V_20 . V_21 = 2 ;
V_17 -> V_20 . V_22 = 19 ;
V_17 -> V_20 . V_23 = F_4 ;
V_17 -> V_20 . V_24 = F_6 ;
V_17 -> V_20 . V_25 = F_7 ;
V_17 -> V_20 . V_26 = F_8 ;
V_16 = F_14 ( V_15 , V_17 ) ;
if ( V_16 ) {
F_15 ( V_17 ) ;
F_13 ( L_4 , V_15 -> V_18 ) ;
}
}
F_10 (np, NULL, L_5 ) {
F_11 ( L_2 , V_15 -> V_18 ) ;
V_17 = F_12 ( sizeof( * V_17 ) , V_19 ) ;
if ( ! V_17 ) {
F_13 ( L_3 ,
V_15 -> V_18 ) ;
continue;
}
V_17 -> V_20 . V_21 = 2 ;
V_17 -> V_20 . V_22 = 6 ;
V_17 -> V_20 . V_23 = F_4 ;
V_17 -> V_20 . V_24 = F_6 ;
V_17 -> V_20 . V_25 = F_7 ;
V_17 -> V_20 . V_26 = F_8 ;
V_16 = F_14 ( V_15 , V_17 ) ;
if ( V_16 ) {
F_15 ( V_17 ) ;
F_13 ( L_4 , V_15 -> V_18 ) ;
}
}
F_10 (np, NULL, L_6 ) {
F_11 ( L_7 , V_15 -> V_18 ) ;
V_17 = F_12 ( sizeof( * V_17 ) , V_19 ) ;
if ( ! V_17 ) {
F_13 ( L_3 ,
V_15 -> V_18 ) ;
continue;
}
V_17 -> V_20 . V_21 = 2 ;
V_17 -> V_20 . V_22 = 16 ;
V_17 -> V_20 . V_23 = F_4 ;
V_17 -> V_20 . V_24 = F_6 ;
V_17 -> V_20 . V_25 = F_7 ;
V_17 -> V_20 . V_26 = F_8 ;
V_16 = F_14 ( V_15 , V_17 ) ;
if ( V_16 ) {
F_15 ( V_17 ) ;
F_13 ( L_4 , V_15 -> V_18 ) ;
}
}
return 0 ;
}
