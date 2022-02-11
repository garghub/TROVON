static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 ;
const struct V_10 * V_11 ;
const struct V_12 * V_13 ;
enum V_14 V_15 ;
bool V_16 = V_6 -> V_17 ;
V_9 = F_2 ( V_2 , & V_15 ) ;
if ( ! V_9 || ! V_9 -> V_18 )
return V_16 ;
V_11 = F_3 ( V_9 -> V_18 ) ;
if ( ! V_11 )
return V_16 ;
V_13 = F_4 ( V_11 -> V_13 ) ;
if ( ! V_13 )
return V_16 ;
if ( V_6 -> V_19 [ 0 ] == '\0' )
V_16 = ! V_16 ;
else
V_16 ^= ! strncmp ( V_13 -> V_19 , V_6 -> V_19 ,
strlen ( V_13 -> V_19 ) ) ;
return V_16 ;
}
static int F_5 ( const struct V_20 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_16 ;
V_16 = F_6 ( V_4 -> V_21 ) ;
if ( V_16 < 0 ) {
F_7 ( L_1 ,
V_4 -> V_21 ) ;
return V_16 ;
}
V_6 -> V_19 [ sizeof( V_6 -> V_19 ) - 1 ] = '\0' ;
return 0 ;
}
static void F_8 ( const struct V_22 * V_4 )
{
F_9 ( V_4 -> V_21 ) ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_23 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_23 ) ;
}
