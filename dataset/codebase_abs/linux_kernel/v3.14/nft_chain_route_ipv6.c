static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
unsigned int V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 , V_13 ;
T_1 V_14 ;
T_2 V_15 , V_16 ;
if ( F_3 ( & V_10 , V_2 , V_4 , V_6 , V_7 ) < 0 )
return V_17 ;
memcpy ( & V_12 , & F_4 ( V_4 ) -> V_12 , sizeof( V_12 ) ) ;
memcpy ( & V_13 , & F_4 ( V_4 ) -> V_13 , sizeof( V_13 ) ) ;
V_15 = V_4 -> V_15 ;
V_14 = F_4 ( V_4 ) -> V_14 ;
V_16 = * ( ( T_2 * ) F_4 ( V_4 ) ) ;
V_8 = F_5 ( & V_10 , V_2 ) ;
if ( V_8 != V_17 && V_8 != V_18 &&
( memcmp ( & F_4 ( V_4 ) -> V_12 , & V_12 , sizeof( V_12 ) ) ||
memcmp ( & F_4 ( V_4 ) -> V_13 , & V_13 , sizeof( V_13 ) ) ||
V_4 -> V_15 != V_15 ||
F_4 ( V_4 ) -> V_14 != V_14 ||
V_16 != * ( ( V_19 * ) F_4 ( V_4 ) ) ) )
return F_6 ( V_4 ) == 0 ? V_8 : V_17 ;
return V_8 ;
}
static int T_3 F_7 ( void )
{
return F_8 ( & V_20 ) ;
}
static void T_4 F_9 ( void )
{
F_10 ( & V_20 ) ;
}
