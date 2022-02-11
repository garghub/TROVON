static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 + V_3 ;
V_8 -> V_10 [ V_4 ] += V_5 ;
if ( V_8 -> V_10 [ V_4 ] != V_6 )
return;
if ( V_8 -> V_11 & V_12 )
F_1 ( V_2 , V_8 -> V_13 , V_4 , V_5 , V_6 ) ;
}
static int F_2 ( struct V_1 * V_2 , int V_14 ,
int V_4 , int V_5 , int V_6 )
{
struct V_14 * V_15 = V_2 -> V_16 + V_14 ;
V_15 -> V_10 [ V_4 ] += V_5 ;
if ( V_15 -> V_10 [ V_4 ] == V_6 )
F_1 ( V_2 , V_15 -> V_3 , V_4 , V_5 , V_6 ) ;
return V_15 -> V_10 [ V_4 ] ;
}
static void F_3 ( struct V_1 * V_2 , int V_14 ,
int V_4 , int V_5 , int V_6 )
{
unsigned long V_11 ;
F_4 ( & V_17 , V_11 ) ;
F_2 ( V_2 , V_14 , V_4 , V_5 , V_6 ) ;
F_5 ( & V_17 , V_11 ) ;
}
void F_6 ( struct V_1 * V_2 , int V_14 , int V_4 )
{
F_3 ( V_2 , V_14 , V_4 , 1 , 1 ) ;
}
void F_7 ( struct V_1 * V_2 , int V_14 , int V_4 )
{
F_3 ( V_2 , V_14 , V_4 , - 1 , 0 ) ;
}
void F_8 ( struct V_1 * V_2 , int V_14 )
{
struct V_14 * V_15 = V_2 -> V_16 + V_14 ;
unsigned long V_18 ;
unsigned long V_11 ;
int V_19 ;
F_4 ( & V_17 , V_11 ) ;
V_19 = F_2 ( V_2 , V_14 , V_20 , 1 , 1 ) ;
if ( V_19 == 1 ) {
V_18 = F_9 ( V_15 -> V_21 ) ;
V_18 &= ~ ( 1 << V_15 -> V_22 ) ;
F_10 ( V_18 , V_15 -> V_21 ) ;
}
F_5 ( & V_17 , V_11 ) ;
}
void F_11 ( struct V_1 * V_2 , int V_14 )
{
struct V_14 * V_15 = V_2 -> V_16 + V_14 ;
unsigned long V_18 ;
unsigned long V_11 ;
int V_19 ;
F_4 ( & V_17 , V_11 ) ;
V_19 = F_2 ( V_2 , V_14 , V_20 , - 1 , 0 ) ;
if ( V_19 == 0 ) {
V_18 = F_9 ( V_15 -> V_21 ) ;
V_18 |= 1 << V_15 -> V_22 ;
F_10 ( V_18 , V_15 -> V_21 ) ;
}
F_5 ( & V_17 , V_11 ) ;
}
int T_1 F_12 ( struct V_1 * V_2 )
{
V_1 = V_2 ;
return 0 ;
}
int T_1 __weak F_13 ( void )
{
return 0 ;
}
int __weak F_14 ( void )
{
return V_23 ;
}
int T_1 F_15 ( void )
{
return F_13 () ;
}
static int F_16 ( struct V_24 * V_24 )
{
if ( ! V_1 )
return - V_25 ;
F_8 ( V_1 , V_24 -> V_26 ) ;
return 0 ;
}
static void F_17 ( struct V_24 * V_24 )
{
if ( V_1 )
F_11 ( V_1 , V_24 -> V_26 ) ;
}
int T_1 F_18 ( struct V_24 * V_27 , int V_28 )
{
struct V_24 * V_29 ;
int V_19 = 0 ;
int V_30 ;
for ( V_30 = 0 ; ! V_19 && ( V_30 < V_28 ) ; V_30 ++ ) {
V_29 = V_27 + V_30 ;
if ( ! V_29 -> V_26 )
continue;
V_29 -> V_31 = & V_32 ;
V_19 |= F_19 ( V_29 ) ;
}
return V_19 ;
}
