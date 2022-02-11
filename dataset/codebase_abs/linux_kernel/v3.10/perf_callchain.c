static bool F_1 ( unsigned long V_1 )
{
unsigned int V_2 ;
if ( ! ( V_1 & 0x3 ) ) {
if ( ! F_2 ( V_2 , ( unsigned int * ) V_1 ) ) {
if ( ( V_2 & 0xff000000 ) == 0xab000000 ||
V_2 == 0xa3200aa0 )
return true ;
}
}
return false ;
}
static struct V_3 T_1 *
F_3 ( struct V_3 T_1 * V_4 ,
struct V_5 * V_6 )
{
struct V_3 V_7 ;
unsigned long V_1 ;
while ( 1 ) {
if ( ! F_4 ( V_8 , V_4 , sizeof( V_7 ) ) )
return 0 ;
if ( F_5 ( & V_7 , V_4 ,
sizeof( V_7 ) ) )
return 0 ;
-- V_4 ;
V_1 = V_7 . V_9 - 4 ;
if ( F_1 ( V_1 ) ) {
F_6 ( V_6 , V_1 ) ;
return V_4 ;
}
}
return 0 ;
}
void
F_7 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
unsigned long V_12 = V_11 -> V_13 . V_14 [ 0 ] . V_15 ;
struct V_3 T_1 * V_7 ;
V_7 = (struct V_3 T_1 * ) V_12 ;
-- V_7 ;
while ( ( V_6 -> V_16 < V_17 ) && V_7 )
V_7 = F_3 ( V_7 , V_6 ) ;
}
static int
F_8 ( struct V_18 * V_19 ,
void * V_20 )
{
struct V_5 * V_6 = V_20 ;
F_6 ( V_6 , V_19 -> V_21 ) ;
return 0 ;
}
void
F_9 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_18 V_19 ;
V_19 . V_22 = V_11 -> V_13 . V_14 [ 1 ] . V_15 ;
V_19 . V_12 = V_11 -> V_13 . V_14 [ 0 ] . V_15 ;
V_19 . V_9 = V_11 -> V_13 . V_23 [ 4 ] . V_24 ;
V_19 . V_21 = V_11 -> V_13 . V_25 ;
F_10 ( & V_19 , F_8 , V_6 ) ;
}
