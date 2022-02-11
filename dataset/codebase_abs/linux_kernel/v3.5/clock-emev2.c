static void F_1 ( unsigned long V_1 , int V_2 )
{
F_2 ( ! V_3 || ( V_2 >= V_4 ) ) ;
F_3 ( V_1 , V_3 + V_2 ) ;
}
void F_4 ( unsigned long V_1 )
{
F_1 ( V_1 , V_5 ) ;
}
static unsigned long F_5 ( struct V_6 * V_6 )
{
return V_6 -> V_7 -> V_8 * 7000 ;
}
static int F_6 ( struct V_6 * V_6 )
{
F_3 ( F_7 ( V_6 -> V_9 ) | ( 1 << V_6 -> V_10 ) ,
V_6 -> V_9 ) ;
return 0 ;
}
static void F_8 ( struct V_6 * V_6 )
{
F_3 ( F_7 ( V_6 -> V_9 ) & ~ ( 1 << V_6 -> V_10 ) ,
V_6 -> V_9 ) ;
}
static int T_1 F_9 ( struct V_6 * V_11 , int V_12 )
{
struct V_6 * V_13 ;
int V_14 = 0 ;
int V_15 ;
for ( V_15 = 0 ; ! V_14 && ( V_15 < V_12 ) ; V_15 ++ ) {
V_13 = V_11 + V_15 ;
V_13 -> V_16 = & V_17 ;
V_14 |= F_10 ( V_13 ) ;
}
return V_14 ;
}
static unsigned long F_11 ( struct V_6 * V_6 )
{
unsigned int V_18 ;
V_18 = ( F_7 ( V_6 -> V_9 ) >> V_6 -> V_10 ) & 0xff ;
return V_6 -> V_7 -> V_8 / ( V_18 + 1 ) ;
}
static int T_1 F_12 ( struct V_6 * V_11 , int V_12 )
{
struct V_6 * V_13 ;
int V_14 = 0 ;
int V_15 ;
for ( V_15 = 0 ; ! V_14 && ( V_15 < V_12 ) ; V_15 ++ ) {
V_13 = V_11 + V_15 ;
V_13 -> V_16 = & V_19 ;
V_14 |= F_10 ( V_13 ) ;
}
return V_14 ;
}
void T_1 F_13 ( void )
{
int V_15 , V_14 = 0 ;
static int V_20 ;
if ( V_20 ++ )
return;
V_3 = F_14 ( V_21 , V_4 ) ;
F_2 ( ! V_3 ) ;
F_1 ( 0 , V_22 ) ;
F_1 ( 1 , V_23 ) ;
F_1 ( 2 , V_24 ) ;
F_1 ( 2 , V_25 ) ;
F_1 ( 2 , V_26 ) ;
F_1 ( 2 , V_27 ) ;
for ( V_15 = 0 ; ! V_14 && ( V_15 < F_15 ( V_28 ) ) ; V_15 ++ )
V_14 = F_10 ( V_28 [ V_15 ] ) ;
if ( ! V_14 )
V_14 = F_12 ( V_29 , V_30 ) ;
if ( ! V_14 )
V_14 = F_9 ( V_31 , V_32 ) ;
F_16 ( V_33 , F_15 ( V_33 ) ) ;
if ( ! V_14 )
F_17 () ;
else
F_18 ( L_1 ) ;
}
