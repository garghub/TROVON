static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
unsigned int V_7 ;
struct V_8 V_9 ;
struct V_10 V_11 , V_12 ;
T_1 V_13 ;
T_2 V_14 , V_15 ;
if ( F_2 ( & V_9 , V_2 , V_4 , V_6 ) < 0 )
return V_16 ;
memcpy ( & V_11 , & F_3 ( V_4 ) -> V_11 , sizeof( V_11 ) ) ;
memcpy ( & V_12 , & F_3 ( V_4 ) -> V_12 , sizeof( V_12 ) ) ;
V_14 = V_4 -> V_14 ;
V_13 = F_3 ( V_4 ) -> V_13 ;
V_15 = * ( ( T_2 * ) F_3 ( V_4 ) ) ;
V_7 = F_4 ( & V_9 , V_2 ) ;
if ( V_7 != V_16 && V_7 != V_17 &&
( memcmp ( & F_3 ( V_4 ) -> V_11 , & V_11 , sizeof( V_11 ) ) ||
memcmp ( & F_3 ( V_4 ) -> V_12 , & V_12 , sizeof( V_12 ) ) ||
V_4 -> V_14 != V_14 ||
F_3 ( V_4 ) -> V_13 != V_13 ||
V_15 != * ( ( V_18 * ) F_3 ( V_4 ) ) ) )
return F_5 ( V_4 ) == 0 ? V_7 : V_16 ;
return V_7 ;
}
static int T_3 F_6 ( void )
{
return F_7 ( & V_19 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_19 ) ;
}
