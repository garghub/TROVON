static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( V_5 , F_3 ( V_3 ) ,
F_4 ( F_5 ( V_3 ) ) ) ;
F_2 ( V_5 , F_3 ( V_3 ) ,
F_6 ( F_5 ( V_3 ) ) ) ;
F_7 ( & V_2 -> V_6 . V_7 ) ;
}
static T_1 F_8 ( int V_8 , void * V_9 )
{
struct V_4 * V_5 = V_9 ;
unsigned long V_10 ;
unsigned int V_11 , V_3 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_5 -> V_12 -> V_13 , 32 ) ; V_11 ++ ) {
V_10 = F_10 ( V_5 ,
F_6 ( V_11 ) ) ;
F_11 (id, &reg, BITS_PER_LONG) {
struct V_1 * V_2 =
V_5 -> V_2 + ( V_11 * V_14 + V_3 ) ;
F_1 ( V_2 ) ;
}
}
return V_15 ;
}
static void F_12 ( struct V_4 * V_5 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_5 -> V_12 -> V_13 , 32 ) ; ++ V_11 ) {
F_2 ( V_5 , 0xffffffffu ,
F_4 ( V_11 ) ) ;
F_2 ( V_5 , 0xffffffffu ,
F_6 ( V_11 ) ) ;
}
}
static int
F_13 ( struct V_4 * V_5 , T_2 V_16 ,
void (* F_14)( struct V_17 * ) )
{
unsigned int V_11 ;
int V_18 ;
F_15 ( V_5 ) ;
for ( V_11 = 0 ; V_11 < V_5 -> V_12 -> V_13 ; V_11 ++ )
F_16 ( & V_5 -> V_2 [ V_11 ] . V_6 . V_7 , F_14 ) ;
V_18 = F_17 ( V_5 -> V_19 , V_5 -> V_20 ,
F_8 , V_21 ,
L_1 , V_5 ) ;
if ( V_18 < 0 ) {
F_18 ( 1 ) ;
return V_18 ;
}
F_2 ( V_5 , 0 , V_22 ) ;
F_2 ( V_5 , 0xff , V_23 ) ;
F_2 ( V_5 , V_16 , V_24 ) ;
return 0 ;
}
static void F_19 ( struct V_4 * V_5 ,
unsigned int V_3 ,
T_2 V_25 )
{
F_2 ( V_5 , V_25 , F_20 ( V_3 ) ) ;
}
static void F_21 ( struct V_4 * V_5 ,
unsigned int V_3 )
{
F_2 ( V_5 , F_3 ( V_3 ) ,
F_22 ( F_5 ( V_3 ) ) ) ;
}
static void F_23 ( struct V_4 * V_5 ,
unsigned int V_3 )
{
F_2 ( V_5 , F_3 ( V_3 ) ,
F_4 ( F_5 ( V_3 ) ) ) ;
F_2 ( V_5 , F_3 ( V_3 ) ,
F_6 ( F_5 ( V_3 ) ) ) ;
}
static int F_24 ( struct V_4 * V_5 )
{
unsigned int V_11 ;
F_25 ( V_5 -> V_19 , V_5 -> V_20 , V_5 ) ;
for ( V_11 = 0 ; V_11 < V_5 -> V_12 -> V_13 ; V_11 ++ )
F_26 ( & V_5 -> V_2 [ V_11 ] . V_6 . V_7 ) ;
return 0 ;
}
