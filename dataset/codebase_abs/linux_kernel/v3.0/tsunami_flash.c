static inline T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 ;
V_4 . V_5 [ 0 ] = F_2 ( V_3 ) ;
return V_4 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_6 , unsigned long V_3 )
{
F_4 ( V_6 . V_5 [ 0 ] , V_3 ) ;
}
static void F_5 (
struct V_1 * V_2 , void * V_7 , unsigned long V_3 , T_2 V_8 )
{
unsigned char * V_9 ;
V_9 = V_7 ;
while( V_8 && ( V_3 < V_10 ) ) {
* V_9 = F_2 ( V_3 ) ;
V_3 ++ ;
V_9 ++ ;
V_8 -- ;
}
}
static void F_6 (
struct V_1 * V_2 , unsigned long V_3 ,
const void * V_7 , T_2 V_8 )
{
const unsigned char * V_11 ;
V_11 = V_7 ;
while( V_8 && ( V_3 < V_10 ) ) {
F_4 ( * V_11 , V_3 ) ;
V_3 ++ ;
V_11 ++ ;
V_8 -- ;
}
}
static void T_3 F_7 ( void )
{
struct V_12 * V_13 ;
V_13 = V_14 ;
if ( V_13 ) {
F_8 ( V_13 ) ;
F_9 ( V_13 ) ;
}
V_14 = 0 ;
}
static int T_4 F_10 ( void )
{
static const char * V_15 [] = { L_1 , L_2 , L_3 , NULL } ;
char * * type ;
F_4 ( V_16 , V_17 ) ;
V_14 = 0 ;
type = V_15 ;
for(; ! V_14 && * type ; type ++ ) {
V_14 = F_11 ( * type , & V_18 ) ;
}
if ( V_14 ) {
V_14 -> V_19 = V_20 ;
F_12 ( V_14 , NULL , 0 ) ;
return 0 ;
}
return - V_21 ;
}
