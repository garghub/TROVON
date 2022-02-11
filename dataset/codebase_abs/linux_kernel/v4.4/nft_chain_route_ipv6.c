static unsigned int F_1 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
unsigned int V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 , V_11 ;
T_1 V_12 ;
T_2 V_13 , V_14 ;
if ( F_2 ( & V_8 , V_3 , V_5 ) < 0 )
return V_15 ;
memcpy ( & V_10 , & F_3 ( V_3 ) -> V_10 , sizeof( V_10 ) ) ;
memcpy ( & V_11 , & F_3 ( V_3 ) -> V_11 , sizeof( V_11 ) ) ;
V_13 = V_3 -> V_13 ;
V_12 = F_3 ( V_3 ) -> V_12 ;
V_14 = * ( ( T_2 * ) F_3 ( V_3 ) ) ;
V_6 = F_4 ( & V_8 , V_1 ) ;
if ( V_6 != V_15 && V_6 != V_16 &&
( memcmp ( & F_3 ( V_3 ) -> V_10 , & V_10 , sizeof( V_10 ) ) ||
memcmp ( & F_3 ( V_3 ) -> V_11 , & V_11 , sizeof( V_11 ) ) ||
V_3 -> V_13 != V_13 ||
F_3 ( V_3 ) -> V_12 != V_12 ||
V_14 != * ( ( V_17 * ) F_3 ( V_3 ) ) ) )
return F_5 ( V_5 -> V_18 , V_3 ) == 0 ? V_6 : V_15 ;
return V_6 ;
}
static int T_3 F_6 ( void )
{
return F_7 ( & V_19 ) ;
}
static void T_4 F_8 ( void )
{
F_9 ( & V_19 ) ;
}
