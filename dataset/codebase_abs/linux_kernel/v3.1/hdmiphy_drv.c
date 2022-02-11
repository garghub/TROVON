const T_1 * F_1 ( T_2 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; ++ V_2 )
if ( V_3 [ V_2 ] . V_1 == V_1 )
return V_3 [ V_2 ] . V_4 ;
return NULL ;
}
static int F_3 ( struct V_5 * V_6 , int V_7 )
{
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_8 * V_1 )
{
const T_1 * V_4 ;
T_1 V_9 [ 32 ] ;
int V_10 ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_13 * V_14 = & V_12 -> V_14 ;
F_6 ( V_14 , L_1 , V_1 -> V_1 ) ;
V_4 = F_1 ( V_1 -> V_1 ) ;
if ( ! V_4 ) {
F_7 ( V_14 , L_2 ) ;
return - V_15 ;
}
memcpy ( V_9 , V_4 , 32 ) ;
V_10 = F_8 ( V_12 , V_9 , 32 ) ;
if ( V_10 != 32 ) {
F_7 ( V_14 , L_3 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_9 ( struct V_5 * V_6 , int V_17 )
{
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_13 * V_14 = & V_12 -> V_14 ;
T_1 V_9 [ 2 ] ;
int V_10 ;
F_6 ( V_14 , L_4 , V_17 ) ;
V_9 [ 0 ] = 0x1f ;
V_9 [ 1 ] = V_17 ? 0x80 : 0x00 ;
V_10 = F_8 ( V_12 , V_9 , 2 ) ;
if ( V_10 != 2 ) {
F_7 ( V_14 , L_5 , V_17 ) ;
return - V_16 ;
}
return 0 ;
}
static int T_3 F_10 ( struct V_11 * V_12 ,
const struct V_18 * V_19 )
{
static struct V_5 V_6 ;
F_11 ( & V_6 , V_12 , & V_20 ) ;
F_6 ( & V_12 -> V_14 , L_6 ) ;
return 0 ;
}
static int T_4 F_12 ( struct V_11 * V_12 )
{
F_6 ( & V_12 -> V_14 , L_7 ) ;
return 0 ;
}
static int T_5 F_13 ( void )
{
return F_14 ( & V_21 ) ;
}
static void T_6 F_15 ( void )
{
F_16 ( & V_21 ) ;
}
