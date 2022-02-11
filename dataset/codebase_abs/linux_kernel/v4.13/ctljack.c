static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . integer . V_5 [ 0 ] = V_2 -> V_6 ;
return 0 ;
}
static int F_2 ( struct V_7 * V_8 , const char * V_9 )
{
struct V_10 V_11 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_12 = 0 ;
V_11 . V_13 = V_14 ;
F_3 ( V_11 . V_9 , V_9 , sizeof( V_11 . V_9 ) ) ;
while ( F_4 ( V_8 , & V_11 ) ) {
V_11 . V_12 ++ ;
V_11 . V_15 = 0 ;
}
return V_11 . V_12 ;
}
static void F_5 ( char * V_9 , const char * V_16 , int V_17 )
{
T_1 V_18 = strlen ( V_16 ) ;
bool V_19 = true ;
if ( V_18 >= 5 )
V_19 = strncmp ( & V_16 [ V_18 - 5 ] , L_1 , 5 ) ? true : false ;
snprintf ( V_9 , V_17 , V_19 ? L_2 : L_3 , V_16 ) ;
}
struct V_1 *
F_6 ( const char * V_9 , struct V_7 * V_8 )
{
struct V_1 * V_20 ;
V_20 = F_7 ( & V_21 , NULL ) ;
if ( ! V_20 )
return NULL ;
F_5 ( V_20 -> V_22 . V_9 , V_9 , sizeof( V_20 -> V_22 . V_9 ) ) ;
V_20 -> V_22 . V_12 = F_2 ( V_8 , V_20 -> V_22 . V_9 ) ;
V_20 -> V_6 = 0 ;
return V_20 ;
}
void F_8 ( struct V_7 * V_8 ,
struct V_1 * V_20 , bool V_23 )
{
if ( V_20 -> V_6 == V_23 )
return;
V_20 -> V_6 = V_23 ;
F_9 ( V_8 , V_24 , & V_20 -> V_22 ) ;
}
