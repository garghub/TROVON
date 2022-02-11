static void F_1 ( unsigned long V_1 , int V_2 )
{
F_2 ( ! V_3 || ( V_2 >= V_4 ) ) ;
F_3 ( V_1 , V_3 + V_2 ) ;
}
static unsigned long F_4 ( struct V_5 * V_5 )
{
return V_5 -> V_6 -> V_7 * 7000 ;
}
static int F_5 ( struct V_5 * V_5 )
{
F_3 ( F_6 ( V_5 -> V_8 ) | ( 1 << V_5 -> V_9 ) ,
V_5 -> V_8 ) ;
return 0 ;
}
static void F_7 ( struct V_5 * V_5 )
{
F_3 ( F_6 ( V_5 -> V_8 ) & ~ ( 1 << V_5 -> V_9 ) ,
V_5 -> V_8 ) ;
}
static int T_1 F_8 ( struct V_5 * V_10 , int V_11 )
{
struct V_5 * V_12 ;
int V_13 = 0 ;
int V_14 ;
for ( V_14 = 0 ; ! V_13 && ( V_14 < V_11 ) ; V_14 ++ ) {
V_12 = V_10 + V_14 ;
V_12 -> V_15 = & V_16 ;
V_13 |= F_9 ( V_12 ) ;
}
return V_13 ;
}
static unsigned long F_10 ( struct V_5 * V_5 )
{
unsigned int V_17 ;
V_17 = ( F_6 ( V_5 -> V_8 ) >> V_5 -> V_9 ) & 0xff ;
return V_5 -> V_6 -> V_7 / ( V_17 + 1 ) ;
}
static int T_1 F_11 ( struct V_5 * V_10 , int V_11 )
{
struct V_5 * V_12 ;
int V_13 = 0 ;
int V_14 ;
for ( V_14 = 0 ; ! V_13 && ( V_14 < V_11 ) ; V_14 ++ ) {
V_12 = V_10 + V_14 ;
V_12 -> V_15 = & V_18 ;
V_13 |= F_9 ( V_12 ) ;
}
return V_13 ;
}
void T_1 F_12 ( void )
{
int V_14 , V_13 = 0 ;
V_3 = F_13 ( V_19 , V_4 ) ;
F_2 ( ! V_3 ) ;
F_1 ( 0 , V_20 ) ;
F_1 ( 1 , V_21 ) ;
F_1 ( 2 , V_22 ) ;
F_1 ( 2 , V_23 ) ;
F_1 ( 2 , V_24 ) ;
F_1 ( 2 , V_25 ) ;
for ( V_14 = 0 ; ! V_13 && ( V_14 < F_14 ( V_26 ) ) ; V_14 ++ )
V_13 = F_9 ( V_26 [ V_14 ] ) ;
if ( ! V_13 )
V_13 = F_11 ( V_27 , V_28 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_29 , V_30 ) ;
F_15 ( V_31 , F_14 ( V_31 ) ) ;
if ( ! V_13 )
F_16 () ;
else
F_17 ( L_1 ) ;
}
