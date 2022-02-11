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
int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_16 * V_17 = & V_2 -> V_18 ;
if ( V_17 -> V_19 ) {
F_9 ( V_17 -> V_19 , 1 ) ;
F_4 ( V_17 -> V_20 ) ;
F_9 ( V_17 -> V_19 , 0 ) ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_18 ;
struct V_21 * V_22 = V_2 -> V_15 -> V_23 ;
struct V_9 * V_10 ;
int error ;
V_10 = F_11 () ;
if ( ! V_10 )
return - V_24 ;
V_2 -> V_10 = V_10 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_25 = V_2 -> V_15 ;
V_10 -> V_26 = L_3 ;
V_10 -> V_27 = & F_5 ;
V_10 -> V_28 = & F_7 ;
V_10 -> V_29 = & F_8 ;
V_17 -> V_19 = F_12 ( V_2 -> V_15 , L_4 ,
V_30 ) ;
if ( F_13 ( V_17 -> V_19 ) ) {
error = F_14 ( V_17 -> V_19 ) ;
F_15 ( V_2 -> V_15 , L_5 , error ) ;
return error ;
}
F_16 ( V_22 , L_6 , & V_17 -> V_20 ) ;
if ( V_17 -> V_20 > 1000 )
V_17 -> V_20 = 1 ;
snprintf ( V_10 -> V_31 , V_32 , L_7 , V_10 -> V_26 ) ;
error = F_17 ( V_10 , V_2 -> V_15 -> V_23 ) ;
if ( error ) {
F_15 ( V_2 -> V_15 , L_8 , V_10 -> V_26 ) ;
F_18 ( V_10 ) ;
return error ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_10 ) ;
F_18 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
return 0 ;
}
