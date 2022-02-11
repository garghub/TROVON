static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return ! ! ( F_2 ( F_3 ( V_2 ) ) & ( 1 << V_3 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
int V_5 ;
unsigned long V_6 ;
struct V_7 * V_8 = F_5 ( V_2 -> V_9 ) ;
F_6 ( & V_8 -> V_10 , V_6 ) ;
V_5 = F_2 ( F_3 ( V_2 ) ) & ~ ( 1 << V_3 ) ;
if ( V_4 )
V_5 |= 1 << V_3 ;
F_7 ( V_5 , F_3 ( V_2 ) ) ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_5 ;
unsigned long V_6 ;
struct V_7 * V_8 = F_5 ( V_2 -> V_9 ) ;
F_6 ( & V_8 -> V_10 , V_6 ) ;
V_5 = F_2 ( F_10 ( V_2 ) ) & ~ ( 1 << V_3 ) ;
F_7 ( V_5 , F_10 ( V_2 ) ) ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
int V_5 ;
unsigned long V_6 ;
struct V_7 * V_8 = F_5 ( V_2 -> V_9 ) ;
F_6 ( & V_8 -> V_10 , V_6 ) ;
V_5 = F_2 ( F_10 ( V_2 ) ) | ( 1 << V_3 ) ;
F_7 ( V_5 , F_10 ( V_2 ) ) ;
V_5 = F_2 ( F_3 ( V_2 ) ) & ~ ( 1 << V_3 ) ;
if ( V_4 )
V_5 |= 1 << V_3 ;
F_7 ( V_5 , F_3 ( V_2 ) ) ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_5 ;
unsigned long V_6 ;
struct V_7 * V_8 = F_5 ( V_2 -> V_9 ) ;
F_6 ( & V_8 -> V_10 , V_6 ) ;
V_5 = F_2 ( F_10 ( V_2 ) ) | ( 1 << V_3 ) ;
F_7 ( V_5 , F_10 ( V_2 ) ) ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
int V_5 ;
unsigned long V_6 ;
struct V_7 * V_8 = F_5 ( V_2 -> V_9 ) ;
F_6 ( & V_8 -> V_10 , V_6 ) ;
V_5 = F_2 ( F_10 ( V_2 ) ) & ~ ( 1 << V_3 ) ;
F_7 ( V_5 , F_10 ( V_2 ) ) ;
V_5 = F_2 ( F_3 ( V_2 ) ) & ~ ( 1 << V_3 ) ;
if ( V_4 )
V_5 |= 1 << V_3 ;
F_7 ( V_5 , F_3 ( V_2 ) ) ;
F_8 ( & V_8 -> V_10 , V_6 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
int V_11 ;
struct V_12 * V_13 ;
struct V_7 * V_8 ;
V_13 = F_15 ( V_14 , 0 ) ;
if ( ! V_13 ) {
F_16 ( L_1 ,
V_14 ) ;
return - V_15 ;
}
F_17 ( V_13 ) ;
V_8 = F_18 ( & V_13 -> V_9 , sizeof( struct V_7 ) ,
V_16 ) ;
if ( ! V_8 ) {
F_19 ( & V_13 -> V_9 , L_2 ) ;
F_20 ( V_13 ) ;
return - V_15 ;
}
F_21 ( V_13 , V_8 ) ;
F_22 ( & V_8 -> V_10 ) ;
for ( V_11 = 0 ; V_11 < V_17 ; V_11 ++ ) {
V_8 -> V_2 [ V_11 ] . V_18 = V_19 ;
V_8 -> V_2 [ V_11 ] . V_9 = & V_13 -> V_9 ;
V_8 -> V_2 [ V_11 ] . V_20 = V_21 [ V_11 ] . V_22 ;
V_8 -> V_2 [ V_11 ] . V_23 = V_11 * 8 ;
V_8 -> V_2 [ V_11 ] . V_24 = V_21 [ V_11 ] . V_25 ;
V_8 -> V_2 [ V_11 ] . V_26 = F_1 ;
V_8 -> V_2 [ V_11 ] . V_27 = F_4 ;
if ( ! V_21 [ V_11 ] . V_28 ) {
V_8 -> V_2 [ V_11 ] . V_29 = F_9 ;
V_8 -> V_2 [ V_11 ] . V_30 = F_11 ;
} else {
V_8 -> V_2 [ V_11 ] . V_29 = F_12 ;
V_8 -> V_2 [ V_11 ] . V_30 = F_13 ;
}
F_23 ( F_24 ( & V_8 -> V_2 [ V_11 ] ) ) ;
}
F_25 ( & V_13 -> V_9 , L_3 ) ;
return 0 ;
}
