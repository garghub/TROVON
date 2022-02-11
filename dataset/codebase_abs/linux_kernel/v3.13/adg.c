static enum V_1 F_1 ( int V_2 )
{
enum V_1 V_3 ;
if ( V_2 == 8 )
return V_4 ;
if ( 0 <= V_2 && V_2 <= 3 )
V_3 = V_5 ;
else if ( 4 <= V_2 && V_2 <= 7 )
V_3 = V_6 ;
else
V_3 = V_7 ;
return V_3 ;
}
int F_2 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
enum V_1 V_3 ;
int V_2 ;
V_2 = F_4 ( V_9 ) ;
V_3 = F_1 ( V_2 ) ;
F_5 ( V_11 , V_9 , V_3 , 0 ) ;
return 0 ;
}
int F_6 ( struct V_8 * V_9 , unsigned int V_12 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
struct V_13 * V_14 = F_7 ( V_11 ) ;
struct V_15 * V_16 = F_8 ( V_11 ) ;
struct V_17 * V_17 ;
enum V_1 V_3 ;
int V_2 , V_18 , V_19 ;
T_1 V_20 ;
int V_21 [] = {
[ V_22 ] = 0x1 ,
[ V_23 ] = 0x2 ,
[ V_24 ] = 0x3 ,
[ V_25 ] = 0x0 ,
} ;
F_9 ( V_16 , L_1 , V_12 ) ;
V_20 = 0 ;
F_10 (clk, adg, i) {
if ( V_12 == F_11 ( V_17 ) ) {
V_20 = V_21 [ V_19 ] ;
goto V_26;
}
}
if ( V_12 == V_14 -> V_27 ) {
V_20 = 0x10 ;
goto V_26;
}
if ( V_12 == V_14 -> V_28 ) {
V_20 = 0x20 ;
goto V_26;
}
return - V_29 ;
V_26:
F_12 ( V_9 , V_30 , 0x00FF0000 , V_14 -> V_31 ) ;
F_13 ( V_9 , V_32 , 0x00000002 ) ;
F_13 ( V_9 , V_33 , 0x00000002 ) ;
V_2 = F_4 ( V_9 ) ;
V_3 = F_1 ( V_2 ) ;
F_9 ( V_16 , L_2 , V_2 , V_19 , V_12 ) ;
V_18 = ( V_2 % 4 ) * 8 ;
F_14 ( V_11 , V_9 , V_3 ,
0xFF << V_18 ,
V_20 << V_18 ) ;
return 0 ;
}
static void F_15 ( struct V_10 * V_11 , struct V_13 * V_14 )
{
struct V_17 * V_17 ;
unsigned long V_12 ;
T_1 V_31 ;
int V_19 ;
int V_34 [] = {
[ V_22 ] = 0x0 ,
[ V_23 ] = 0x1 ,
[ V_24 ] = 0x4 ,
[ V_25 ] = 0x2 ,
} ;
V_31 = 0 ;
V_14 -> V_27 = 0 ;
V_14 -> V_28 = 0 ;
F_10 (clk, adg, i) {
V_12 = F_11 ( V_17 ) ;
if ( 0 == V_12 )
continue;
if ( ! V_14 -> V_27 && ( 0 == V_12 % 44100 ) ) {
V_14 -> V_27 = V_12 / 6 ;
V_31 |= V_34 [ V_19 ] << 20 ;
}
if ( ! V_14 -> V_28 && ( 0 == V_12 % 48000 ) ) {
V_14 -> V_28 = V_12 / 6 ;
V_31 |= V_34 [ V_19 ] << 16 ;
}
}
V_14 -> V_31 = V_31 ;
}
int F_16 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
struct V_10 * V_11 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 = F_8 ( V_11 ) ;
struct V_17 * V_17 ;
int V_19 ;
V_14 = F_17 ( V_16 , sizeof( * V_14 ) , V_39 ) ;
if ( ! V_14 ) {
F_18 ( V_16 , L_3 ) ;
return - V_40 ;
}
V_14 -> V_17 [ V_22 ] = F_19 ( NULL , L_4 ) ;
V_14 -> V_17 [ V_23 ] = F_19 ( NULL , L_5 ) ;
V_14 -> V_17 [ V_24 ] = F_19 ( NULL , L_6 ) ;
V_14 -> V_17 [ V_25 ] = F_19 ( NULL , L_7 ) ;
F_10 (clk, adg, i) {
if ( F_20 ( V_17 ) ) {
F_18 ( V_16 , L_8 ) ;
return - V_29 ;
}
}
F_15 ( V_11 , V_14 ) ;
V_11 -> V_14 = V_14 ;
F_9 ( V_16 , L_9 ) ;
return 0 ;
}
void F_21 ( struct V_35 * V_36 ,
struct V_10 * V_11 )
{
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_17 * V_17 ;
int V_19 ;
F_10 (clk, adg, i)
F_22 ( V_17 ) ;
}
