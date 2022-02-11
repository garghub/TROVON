static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( V_5 , F_3 ( V_3 ) ,
F_4 ( F_5 ( V_3 ) ) ) ;
F_2 ( V_5 , F_3 ( V_3 ) ,
F_6 ( F_5 ( V_3 ) ) ) ;
F_7 ( V_5 -> V_6 , & V_2 -> V_7 . V_8 ) ;
}
static T_1 F_8 ( int V_9 , void * V_10 )
{
struct V_4 * V_5 = V_10 ;
unsigned long V_11 ;
int V_12 , V_3 ;
for ( V_12 = 0 ; V_12 < F_9 ( V_5 -> V_13 -> V_14 , 32 ) ; V_12 ++ ) {
V_11 = F_10 ( V_5 ,
F_6 ( V_12 ) ) ;
F_11 (id, &reg, BITS_PER_LONG) {
struct V_1 * V_2 =
V_5 -> V_2 + ( V_12 * V_15 + V_3 ) ;
F_1 ( V_2 ) ;
}
}
return V_16 ;
}
static void F_12 ( struct V_4 * V_5 )
{
T_2 V_12 ;
for ( V_12 = 0 ; V_12 < F_9 ( V_5 -> V_13 -> V_14 , 32 ) ; ++ V_12 ) {
F_2 ( V_5 , 0xffffffffu ,
F_4 ( V_12 ) ) ;
F_2 ( V_5 , 0xffffffffu ,
F_6 ( V_12 ) ) ;
}
}
static int F_13 ( struct V_4 * V_5 , T_2 V_17 ,
void (* F_14)( struct V_18 * ) )
{
int V_12 , V_19 ;
F_15 ( V_5 ) ;
for ( V_12 = 0 ; V_12 < V_5 -> V_13 -> V_14 ; V_12 ++ )
F_16 ( & V_5 -> V_2 [ V_12 ] . V_7 . V_8 , F_14 ) ;
V_19 = F_17 ( V_5 -> V_20 , V_5 -> V_21 ,
F_8 , V_22 ,
L_1 , V_5 ) ;
if ( F_18 ( V_19 ) ) {
F_19 ( 1 ) ;
return V_19 ;
}
F_2 ( V_5 , 0 , V_23 ) ;
F_2 ( V_5 , 0xff , V_24 ) ;
F_2 ( V_5 , V_17 , V_25 ) ;
return 0 ;
}
static void F_20 ( struct V_4 * V_5 ,
T_2 V_3 , T_2 V_26 )
{
F_2 ( V_5 , V_26 , F_21 ( V_3 ) ) ;
}
static void F_22 ( struct V_4 * V_5 , T_2 V_3 )
{
F_2 ( V_5 , F_3 ( V_3 ) ,
F_23 ( F_5 ( V_3 ) ) ) ;
}
static void F_24 ( struct V_4 * V_5 , T_2 V_3 )
{
F_2 ( V_5 , F_3 ( V_3 ) ,
F_4 ( F_5 ( V_3 ) ) ) ;
F_2 ( V_5 , F_3 ( V_3 ) ,
F_6 ( F_5 ( V_3 ) ) ) ;
}
static int F_25 ( struct V_4 * V_5 )
{
F_26 ( V_5 -> V_20 , V_5 -> V_21 , V_5 ) ;
F_27 ( V_5 -> V_6 ) ;
return 0 ;
}
