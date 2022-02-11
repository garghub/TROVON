static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_4 | V_2 -> V_5 | V_2 -> type , F_3 ( V_3 ) ) ;
F_2 ( V_2 -> V_6 , F_4 ( V_3 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( 0 , F_3 ( V_3 ) ) ;
F_2 ( 0 , F_4 ( V_3 ) ) ;
}
static void F_6 ( unsigned long V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 . V_10 ; V_8 ++ )
if ( V_7 & ( 1 << V_8 ) )
F_2 ( F_7 ( F_3 ( V_8 ) ) | V_4 ,
F_3 ( V_8 ) ) ;
}
static void F_8 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 . V_10 ; V_8 ++ )
F_2 ( F_7 ( F_3 ( V_8 ) ) & ~ V_4 ,
F_3 ( V_8 ) ) ;
}
static unsigned long F_9 ( void )
{
unsigned long V_11 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 . V_10 ; V_8 ++ )
if ( F_7 ( F_3 ( V_8 ) ) & V_4 )
V_11 |= ( 1 << V_8 ) ;
return V_11 ;
}
static unsigned long F_10 ( void )
{
return F_7 ( V_12 ) ;
}
static void F_11 ( unsigned long V_7 )
{
F_2 ( F_7 ( V_12 ) & ~ V_7 , V_12 ) ;
}
static int T_1 F_12 ( void )
{
struct V_13 * V_14 = F_13 ( NULL , L_1 ) ;
int V_8 ;
if ( F_14 ( V_14 ) )
V_14 = NULL ;
F_15 ( V_14 ) ;
F_2 ( 0 , V_15 ) ;
for ( V_8 = 0 ; V_8 < V_9 . V_10 ; V_8 ++ ) {
F_2 ( 0 , F_16 ( V_8 ) ) ;
F_2 ( 0 , F_3 ( V_8 ) ) ;
F_2 ( V_16 | V_17 , F_17 ( V_8 ) ) ;
( void ) F_7 ( F_17 ( V_8 ) ) ;
}
F_18 ( V_14 ) ;
V_9 . V_13 = V_14 ;
return F_19 ( & V_9 ) ;
}
