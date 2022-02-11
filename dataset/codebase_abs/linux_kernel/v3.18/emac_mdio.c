static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 * 40 ; V_3 ++ ) {
unsigned int V_5 = F_2 ( V_2 , V_6 ) ;
V_5 &= V_7 ;
if ( V_5 ) {
F_3 ( V_2 , V_6 , V_5 ) ;
return 0 ;
}
F_4 ( 25 ) ;
}
return - V_8 ;
}
static int F_5 ( struct V_9 * V_10 , int V_11 , int V_12 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned int V_13 ;
int error ;
F_3 ( V_2 , V_14 ,
0x60020000 | ( V_11 << 23 ) | ( V_12 << 18 ) ) ;
error = F_1 ( V_2 ) ;
if ( error < 0 )
return error ;
V_13 = F_2 ( V_2 , V_14 ) & 0xffff ;
F_6 ( V_2 -> V_15 , L_1 ,
V_11 , V_12 , V_13 ) ;
return V_13 ;
}
static int F_7 ( struct V_9 * V_10 , int V_11 ,
int V_12 , T_1 V_13 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_6 ( V_2 -> V_15 ,
L_2 ,
V_11 , V_12 , V_13 ) ;
F_3 ( V_2 , V_14 ,
0x50020000 | ( V_11 << 23 ) | ( V_12 << 18 ) | V_13 ) ;
return F_1 ( V_2 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int error ;
V_10 = F_9 () ;
if ( ! V_10 )
return - V_16 ;
V_2 -> V_10 = V_10 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_17 = V_2 -> V_15 ;
V_10 -> V_18 = L_3 ,
V_10 -> V_19 = & F_5 ;
V_10 -> V_20 = & F_7 ;
snprintf ( V_10 -> V_21 , V_22 , L_4 , V_10 -> V_18 ) ;
error = F_10 ( V_10 , V_2 -> V_15 -> V_23 ) ;
if ( error ) {
F_11 ( V_2 -> V_15 , L_5 , V_10 -> V_18 ) ;
F_12 ( V_10 ) ;
return error ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_10 ) ;
F_12 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
return 0 ;
}
