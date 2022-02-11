static unsigned char F_1 ( struct V_1 * V_1 )
{
T_1 * V_2 = F_2 ( V_1 ) ;
return F_3 ( V_2 -> V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
T_1 * V_2 = F_2 ( V_1 ) ;
F_5 ( V_2 -> V_3 , V_4 , 0xff ) ;
}
static int
F_6 ( struct V_1 * V_1 , int * V_5 , int * V_6 )
{
T_1 * V_2 = F_2 ( V_1 ) ;
int V_7 ;
* V_6 = ( ~ F_3 ( V_2 -> V_3 , V_4 ) >> 4 ) & 0xf ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_5 [ V_7 ] =
F_3 ( V_2 -> V_3 , V_8 + ( V_7 * V_9 ) ) ;
if ( V_5 [ V_7 ] == V_10 )
V_5 [ V_7 ] = - 1 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , int V_11 )
{
T_1 * V_2 = F_2 ( V_1 ) ;
switch ( V_11 ) {
case V_12 :
F_5 ( V_2 -> V_3 , V_13 ,
F_3 ( V_2 -> V_3 ,
V_13 ) | V_14 ) ;
F_8 ( V_15 ) ;
return 0 ;
case V_16 :
F_5 ( V_2 -> V_3 , V_13 ,
F_3 ( V_2 -> V_3 ,
V_13 ) & ~ V_14 ) ;
return 0 ;
default:
return - 1 ;
}
return 0 ;
}
static int F_9 ( T_1 * V_2 )
{
struct V_1 * V_17 ;
V_2 -> V_1 = V_17 = F_10 () ;
if ( ! V_17 ) {
F_11 ( V_2 -> V_18 -> V_19 ,
L_1 ) ;
return - V_20 ;
}
F_12 ( V_17 , L_2 ) ;
F_13 ( V_17 , L_3 , F_14 ( V_2 -> V_21 ) ) ;
F_15 ( V_17 , & V_2 -> V_21 -> V_19 ) ;
V_17 -> V_22 = F_1 ;
V_17 -> V_23 = F_4 ;
V_17 -> V_24 = F_6 ;
V_17 -> V_25 = F_7 ;
F_16 ( V_17 , V_2 ) ;
V_17 -> V_26 = 64 ;
F_17 ( V_17 ) ;
return 0 ;
}
static void F_18 ( T_1 * V_2 )
{
if ( V_2 -> V_1 ) {
F_19 ( V_2 -> V_1 ) ;
V_2 -> V_1 = NULL ;
}
}
static inline int F_9 ( T_1 * V_2 ) { return - V_27 ; }
static inline void F_18 ( T_1 * V_2 ) { }
