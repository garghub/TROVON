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
void F_6 ( T_1 V_8 )
{
int V_9 ;
F_7 (i) {
struct V_1 * V_2 = & F_8 ( V_7 , V_9 ) ;
V_2 -> V_3 = F_9 ( V_2 -> V_3 ^ V_8 , 1 ) ;
}
}
static int T_7 F_10 ( void )
{
int V_9 ;
F_7 (i) {
struct V_1 * V_2 = & F_8 ( V_7 , V_9 ) ;
#define F_11 ( T_8 ) ((x) * 69069)
V_2 -> V_3 = F_9 ( F_11 ( V_9 + V_10 ) , 1 ) ;
V_2 -> V_4 = F_9 ( F_11 ( V_2 -> V_3 ) , 7 ) ;
V_2 -> V_5 = F_9 ( F_11 ( V_2 -> V_4 ) , 15 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int T_7 F_12 ( void )
{
int V_9 ;
F_7 (i) {
struct V_1 * V_2 = & F_8 ( V_7 , V_9 ) ;
T_1 V_11 [ 3 ] ;
F_13 ( & V_11 , sizeof( V_11 ) ) ;
V_2 -> V_3 = F_9 ( V_11 [ 0 ] , 1 ) ;
V_2 -> V_4 = F_9 ( V_11 [ 1 ] , 7 ) ;
V_2 -> V_5 = F_9 ( V_11 [ 2 ] , 15 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
