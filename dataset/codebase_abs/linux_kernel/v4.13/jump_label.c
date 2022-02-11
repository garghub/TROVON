static void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
V_3 -> V_4 = 0xc004 ;
V_3 -> V_5 = 0 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
V_3 -> V_4 = 0xc0f4 ;
V_3 -> V_5 = ( V_2 -> V_6 - V_2 -> V_7 ) >> 1 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_3 * V_8 ,
struct V_3 * V_9 )
{
unsigned char * V_10 = ( unsigned char * ) V_2 -> V_7 ;
unsigned char * V_11 = ( unsigned char * ) V_8 ;
unsigned char * V_12 = ( unsigned char * ) V_9 ;
F_4 ( L_1 , V_10 , V_10 ) ;
F_4 ( L_2 , V_10 ) ;
F_4 ( L_3 , V_11 ) ;
F_4 ( L_4 , V_12 ) ;
F_5 ( L_5 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_13 type ,
int V_14 )
{
struct V_3 V_15 , V_9 ;
if ( type == V_16 ) {
F_1 ( V_2 , & V_15 ) ;
F_2 ( V_2 , & V_9 ) ;
} else {
F_2 ( V_2 , & V_15 ) ;
F_1 ( V_2 , & V_9 ) ;
}
if ( V_14 ) {
if ( memcmp ( ( void * ) V_2 -> V_7 , & V_17 , sizeof( V_17 ) ) )
F_3 ( V_2 , & V_17 , & V_9 ) ;
} else {
if ( memcmp ( ( void * ) V_2 -> V_7 , & V_15 , sizeof( V_15 ) ) )
F_3 ( V_2 , & V_15 , & V_9 ) ;
}
F_7 ( ( void * ) V_2 -> V_7 , & V_9 , sizeof( V_9 ) ) ;
}
static int F_8 ( void * V_18 )
{
struct V_19 * args = V_18 ;
F_6 ( args -> V_2 , args -> type , 0 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 ,
enum V_13 type )
{
struct V_19 args ;
args . V_2 = V_2 ;
args . type = type ;
F_10 ( F_8 , & args , NULL ) ;
}
void F_11 ( struct V_1 * V_2 ,
enum V_13 type )
{
F_6 ( V_2 , type , 1 ) ;
}
