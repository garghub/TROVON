static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
int V_6 = F_2 ( V_4 , V_2 | V_7 ) ;
return ( V_6 < 0 ) ? V_6 : V_6 >> 8 ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_8 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
T_2 V_9 = ( V_8 << 8 ) | V_2 ;
return F_4 ( V_4 , ( const T_1 * ) & V_9 , 2 ) ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_10 , T_1 * V_11 )
{
int V_12 , V_13 ;
for ( V_13 = 0 ; V_13 < V_10 ; V_13 ++ ) {
V_12 = F_1 ( V_1 , V_2 + V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
* ( V_11 + V_13 ) = V_12 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_10 ,
const T_1 * V_11 )
{
int V_12 = 0 , V_13 ;
for ( V_13 = V_10 ; V_13 > 0 ; V_13 -- , V_2 ++ ) {
V_12 = F_3 ( V_1 , V_2 , * ( V_11 + V_13 - 1 ) ) ;
if ( V_12 < 0 )
return V_12 ;
}
return V_12 ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
V_4 -> V_14 = 8 ;
if ( V_1 -> V_15 -> V_16 == 0x0811 )
F_3 ( V_1 , V_17 , V_4 -> V_18 ) ;
if ( F_8 ( V_4 ) < 0 )
F_9 ( & V_4 -> V_19 , L_1 ) ;
}
static int T_3
F_10 ( struct V_3 * V_4 )
{
const struct V_20 * V_21 = F_11 ( V_4 ) ;
if ( V_4 -> V_22 > 1000000 ) {
F_9 ( & V_4 -> V_19 , L_2 ,
( V_4 -> V_22 / 1000 ) ) ;
return - V_23 ;
}
V_24 . V_25 = V_4 -> V_25 ;
V_24 . V_5 = V_4 ;
V_24 . V_19 = & V_4 -> V_19 ;
return F_12 ( & V_24 , V_21 -> V_26 ) ;
}
static int T_4 F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_14 ( & V_4 -> V_19 ) ;
return F_15 ( V_1 ) ;
}
static int T_5 F_16 ( void )
{
return F_17 ( & V_27 ) ;
}
static void T_6 F_18 ( void )
{
F_19 ( & V_27 ) ;
}
