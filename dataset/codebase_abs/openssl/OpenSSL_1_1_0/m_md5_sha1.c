static int F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_3 ( & V_3 -> V_4 ) )
return 0 ;
return F_4 ( & V_3 -> V_5 ) ;
}
static int F_5 ( T_1 * V_1 , const void * V_6 , T_2 V_7 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_6 ( & V_3 -> V_4 , V_6 , V_7 ) )
return 0 ;
return F_7 ( & V_3 -> V_5 , V_6 , V_7 ) ;
}
static int F_8 ( T_1 * V_1 , unsigned char * V_8 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_9 ( V_8 , & V_3 -> V_4 ) )
return 0 ;
return F_10 ( V_8 + V_9 , & V_3 -> V_5 ) ;
}
static int F_11 ( T_1 * V_1 , int V_10 , int V_11 , void * V_12 )
{
unsigned char V_13 [ 48 ] ;
unsigned char V_14 [ V_9 ] ;
unsigned char V_15 [ V_16 ] ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_10 != V_17 )
return 0 ;
if ( V_11 != 48 )
return 0 ;
if ( F_5 ( V_1 , V_12 , V_11 ) <= 0 )
return 0 ;
memset ( V_13 , 0x36 , sizeof( V_13 ) ) ;
if ( ! F_6 ( & V_3 -> V_4 , V_13 , sizeof( V_13 ) ) )
return 0 ;
if ( ! F_9 ( V_14 , & V_3 -> V_4 ) )
return 0 ;
if ( ! F_7 ( & V_3 -> V_5 , V_13 , 40 ) )
return 0 ;
if ( ! F_10 ( V_15 , & V_3 -> V_5 ) )
return 0 ;
if ( ! F_1 ( V_1 ) )
return 0 ;
if ( F_5 ( V_1 , V_12 , V_11 ) <= 0 )
return 0 ;
memset ( V_13 , 0x5c , sizeof( V_13 ) ) ;
if ( ! F_6 ( & V_3 -> V_4 , V_13 , sizeof( V_13 ) ) )
return 0 ;
if ( ! F_6 ( & V_3 -> V_4 , V_14 , sizeof( V_14 ) ) )
return 0 ;
if ( ! F_7 ( & V_3 -> V_5 , V_13 , 40 ) )
return 0 ;
if ( ! F_7 ( & V_3 -> V_5 , V_15 , sizeof( V_15 ) ) )
return 0 ;
F_12 ( V_14 , sizeof( V_14 ) ) ;
F_12 ( V_15 , sizeof( V_15 ) ) ;
return 1 ;
}
const T_3 * F_13 ( void )
{
return & V_18 ;
}
