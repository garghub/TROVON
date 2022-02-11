unsigned long F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_7 ; V_6 ++ ) {
V_5 = V_2 -> V_5 + V_6 ;
if ( V_3 < V_5 -> V_8 )
continue;
if ( V_3 >= ( V_5 -> V_8 + V_5 -> V_9 ) )
continue;
V_3 -= V_5 -> V_8 ;
V_3 += ( unsigned long ) V_5 -> V_10 ;
return V_3 ;
}
return V_3 ;
}
unsigned int F_2 ( struct V_1 * V_2 , unsigned long V_3 )
{
unsigned int V_6 ;
V_3 = F_1 ( V_2 , V_3 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 ; V_6 ++ ) {
if ( V_2 -> V_12 [ V_6 ] == V_3 )
return V_6 ;
}
F_3 () ;
return 0 ;
}
unsigned int F_4 ( unsigned int V_13 ,
unsigned int V_14 ,
unsigned int V_15 )
{
unsigned int V_16 = F_5 ( V_15 ) ;
unsigned int V_17 = F_6 ( V_15 ) ;
V_13 &= ~ ( ( ( 1 << V_16 ) - 1 ) << V_17 ) ;
V_13 |= V_14 << V_17 ;
return V_13 ;
}
unsigned long F_7 ( unsigned int V_13 , unsigned int V_15 )
{
unsigned int V_16 = F_5 ( V_15 ) ;
unsigned int V_17 = F_6 ( V_15 ) ;
unsigned int V_18 = ( ( 1 << V_16 ) - 1 ) << V_17 ;
return ( V_13 & V_18 ) >> V_17 ;
}
static unsigned long F_8 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_21 )
{
void T_1 * V_22 = ( void T_1 * ) V_19 ;
return F_7 ( F_9 ( V_22 ) , V_20 ) ;
}
static unsigned long F_10 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_21 )
{
void T_1 * V_22 = ( void T_1 * ) V_19 ;
return F_7 ( F_11 ( V_22 ) , V_20 ) ;
}
static unsigned long F_12 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_21 )
{
void T_1 * V_22 = ( void T_1 * ) V_19 ;
return F_7 ( F_13 ( V_22 ) , V_20 ) ;
}
static unsigned long F_14 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_23 )
{
void T_1 * V_22 = ( void T_1 * ) V_19 ;
F_15 ( F_4 ( 0 , V_23 , V_20 ) , V_22 ) ;
( void ) F_9 ( V_22 ) ;
return 0 ;
}
static unsigned long F_16 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_23 )
{
void T_1 * V_22 = ( void T_1 * ) V_19 ;
F_17 ( F_4 ( 0 , V_23 , V_20 ) , V_22 ) ;
( void ) F_11 ( V_22 ) ;
return 0 ;
}
static unsigned long F_18 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_23 )
{
void T_1 * V_22 = ( void T_1 * ) V_19 ;
F_19 ( F_4 ( 0 , V_23 , V_20 ) , V_22 ) ;
( void ) F_13 ( V_22 ) ;
return 0 ;
}
static unsigned long F_20 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_23 )
{
void T_1 * V_22 = ( void T_1 * ) V_19 ;
unsigned long V_24 ;
unsigned int V_13 ;
F_21 ( V_24 ) ;
V_13 = F_4 ( F_9 ( V_22 ) , V_23 , V_20 ) ;
F_15 ( V_13 , V_22 ) ;
( void ) F_9 ( V_22 ) ;
F_22 ( V_24 ) ;
return 0 ;
}
static unsigned long F_23 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_23 )
{
void T_1 * V_22 = ( void T_1 * ) V_19 ;
unsigned long V_24 ;
unsigned int V_13 ;
F_21 ( V_24 ) ;
V_13 = F_4 ( F_11 ( V_22 ) , V_23 , V_20 ) ;
F_17 ( V_13 , V_22 ) ;
( void ) F_11 ( V_22 ) ;
F_22 ( V_24 ) ;
return 0 ;
}
static unsigned long F_24 ( unsigned long V_19 , unsigned long V_20 ,
unsigned long V_23 )
{
void T_1 * V_22 = ( void T_1 * ) V_19 ;
unsigned long V_24 ;
unsigned int V_13 ;
F_21 ( V_24 ) ;
V_13 = F_4 ( F_13 ( V_22 ) , V_23 , V_20 ) ;
F_19 ( V_13 , V_22 ) ;
( void ) F_13 ( V_22 ) ;
F_22 ( V_24 ) ;
return 0 ;
}
