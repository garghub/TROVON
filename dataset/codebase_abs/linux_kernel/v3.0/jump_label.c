static int F_1 ( void * V_1 )
{
struct V_2 * args = V_1 ;
int V_3 ;
V_3 = F_2 ( args -> V_4 , args -> V_5 , args -> V_6 ) ;
F_3 ( V_3 < 0 ) ;
return 0 ;
}
void F_4 ( struct V_7 * V_8 ,
enum V_9 type )
{
struct V_2 args ;
struct V_5 V_5 ;
if ( type == V_10 ) {
V_5 . V_11 = 0xc0f4 ;
V_5 . V_12 = ( V_8 -> V_4 - V_8 -> V_13 ) >> 1 ;
} else {
V_5 . V_11 = 0xc004 ;
V_5 . V_12 = 0 ;
}
args . V_4 = ( void * ) V_8 -> V_13 ;
args . V_5 = & V_5 ;
args . V_6 = V_14 ;
F_5 ( F_1 , & args , NULL ) ;
}
