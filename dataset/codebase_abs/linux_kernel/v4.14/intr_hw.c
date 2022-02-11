static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( V_5 , F_3 ( V_3 % 32 ) ,
F_4 ( V_3 / 32 ) ) ;
F_2 ( V_5 , F_3 ( V_3 % 32 ) ,
F_5 ( V_3 / 32 ) ) ;
F_6 ( & V_2 -> V_6 . V_7 ) ;
}
static T_1 F_7 ( int V_8 , void * V_9 )
{
struct V_4 * V_5 = V_9 ;
unsigned long V_10 ;
unsigned int V_11 , V_3 ;
for ( V_11 = 0 ; V_11 < F_8 ( V_5 -> V_12 -> V_13 , 32 ) ; V_11 ++ ) {
V_10 = F_9 ( V_5 ,
F_5 ( V_11 ) ) ;
F_10 (id, &reg, 32 ) {
struct V_1 * V_2 =
V_5 -> V_2 + ( V_11 * 32 + V_3 ) ;
F_1 ( V_2 ) ;
}
}
return V_14 ;
}
static void F_11 ( struct V_4 * V_5 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < F_8 ( V_5 -> V_12 -> V_13 , 32 ) ; ++ V_11 ) {
F_2 ( V_5 , 0xffffffffu ,
F_4 ( V_11 ) ) ;
F_2 ( V_5 , 0xffffffffu ,
F_5 ( V_11 ) ) ;
}
}
static int
F_12 ( struct V_4 * V_5 , T_2 V_15 ,
void (* F_13)( struct V_16 * ) )
{
unsigned int V_11 ;
int V_17 ;
F_14 ( V_5 ) ;
for ( V_11 = 0 ; V_11 < V_5 -> V_12 -> V_13 ; V_11 ++ )
F_15 ( & V_5 -> V_2 [ V_11 ] . V_6 . V_7 , F_13 ) ;
V_17 = F_16 ( V_5 -> V_18 , V_5 -> V_19 ,
F_7 , V_20 ,
L_1 , V_5 ) ;
if ( V_17 < 0 ) {
F_17 ( 1 ) ;
return V_17 ;
}
F_2 ( V_5 , 0 , V_21 ) ;
F_2 ( V_5 , 0xff , V_22 ) ;
F_2 ( V_5 , V_15 , V_23 ) ;
return 0 ;
}
static void F_18 ( struct V_4 * V_5 ,
unsigned int V_3 ,
T_2 V_24 )
{
F_2 ( V_5 , V_24 , F_19 ( V_3 ) ) ;
}
static void F_20 ( struct V_4 * V_5 ,
unsigned int V_3 )
{
F_2 ( V_5 , F_3 ( V_3 % 32 ) ,
F_21 ( V_3 / 32 ) ) ;
}
static void F_22 ( struct V_4 * V_5 ,
unsigned int V_3 )
{
F_2 ( V_5 , F_3 ( V_3 % 32 ) ,
F_4 ( V_3 / 32 ) ) ;
F_2 ( V_5 , F_3 ( V_3 % 32 ) ,
F_5 ( V_3 / 32 ) ) ;
}
static int F_23 ( struct V_4 * V_5 )
{
unsigned int V_11 ;
F_24 ( V_5 -> V_18 , V_5 -> V_19 , V_5 ) ;
for ( V_11 = 0 ; V_11 < V_5 -> V_12 -> V_13 ; V_11 ++ )
F_25 ( & V_5 -> V_2 [ V_11 ] . V_6 . V_7 ) ;
return 0 ;
}
