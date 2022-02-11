T_1 F_1 ( struct V_1 * V_2 )
{
#define F_2 ( T_2 , T_3 , T_4 , T_5 , T_6 ) ((s&c)<<d) ^ (((s <<a) ^ s)>>b)
V_2 -> V_3 = F_2 ( V_2 -> V_3 , 13 , 19 , 4294967294UL , 12 ) ;
V_2 -> V_4 = F_2 ( V_2 -> V_4 , 2 , 25 , 4294967288UL , 4 ) ;
V_2 -> V_5 = F_2 ( V_2 -> V_5 , 3 , 11 , 4294967280UL , 17 ) ;
return ( V_2 -> V_3 ^ V_2 -> V_4 ^ V_2 -> V_5 ) ;
}
T_1 F_3 ( void )
{
unsigned long V_6 ;
struct V_1 * V_2 = & F_4 ( V_7 ) ;
V_6 = F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
return V_6 ;
}
void F_6 ( struct V_1 * V_2 , void * V_8 , int V_9 )
{
unsigned char * V_10 = V_8 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_7 ( V_9 , sizeof( T_1 ) ) ; V_11 += sizeof( T_1 ) ) {
T_1 V_12 = F_1 ( V_2 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < sizeof( T_1 ) ; V_13 ++ ) {
V_10 [ V_11 + V_13 ] = V_12 ;
V_12 >>= V_14 ;
}
}
if ( V_11 < V_9 ) {
T_1 V_12 = F_1 ( V_2 ) ;
for (; V_11 < V_9 ; V_11 ++ ) {
V_10 [ V_11 ] = V_12 ;
V_12 >>= V_14 ;
}
}
}
void F_8 ( void * V_8 , int V_9 )
{
struct V_1 * V_2 = & F_4 ( V_7 ) ;
F_6 ( V_2 , V_8 , V_9 ) ;
F_5 ( V_2 ) ;
}
void F_9 ( T_1 V_15 )
{
int V_11 ;
F_10 (i) {
struct V_1 * V_2 = & F_11 ( V_7 , V_11 ) ;
V_2 -> V_3 = F_12 ( V_2 -> V_3 ^ V_15 , 1 ) ;
}
}
static int T_7 F_13 ( void )
{
int V_11 ;
F_10 (i) {
struct V_1 * V_2 = & F_11 ( V_7 , V_11 ) ;
#define F_14 ( T_8 ) ((x) * 69069)
V_2 -> V_3 = F_12 ( F_14 ( V_11 + V_16 ) , 1 ) ;
V_2 -> V_4 = F_12 ( F_14 ( V_2 -> V_3 ) , 7 ) ;
V_2 -> V_5 = F_12 ( F_14 ( V_2 -> V_4 ) , 15 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int T_7 F_15 ( void )
{
int V_11 ;
F_10 (i) {
struct V_1 * V_2 = & F_11 ( V_7 , V_11 ) ;
T_1 V_17 [ 3 ] ;
F_16 ( & V_17 , sizeof( V_17 ) ) ;
V_2 -> V_3 = F_12 ( V_17 [ 0 ] , 1 ) ;
V_2 -> V_4 = F_12 ( V_17 [ 1 ] , 7 ) ;
V_2 -> V_5 = F_12 ( V_17 [ 2 ] , 15 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
