static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_11 , V_12 , div , V_13 ;
T_1 V_14 , V_15 ;
int V_16 = F_4 ( V_4 ) ;
unsigned int V_17 [] = {
F_5 ( V_8 -> V_18 [ V_19 ] ) ,
F_5 ( V_8 -> V_18 [ V_20 ] ) ,
F_5 ( V_8 -> V_18 [ V_21 ] ) ,
0 ,
V_8 -> V_22 ,
V_8 -> V_23 ,
} ;
for ( V_12 = 0 ; V_12 < F_6 ( V_17 ) ; V_12 ++ ) {
for ( div = 128 , V_11 = 0 ;
div <= 2048 ;
div *= 2 , V_11 ++ ) {
if ( V_5 == V_17 [ V_12 ] / div ) {
V_15 = ( V_11 << 4 ) | V_12 ;
goto V_24;
}
}
}
F_7 ( V_10 , L_1 ) ;
return - V_25 ;
V_24:
V_13 = ( V_16 % 4 ) * 8 ;
V_14 = 0xFF << V_13 ;
V_15 = V_15 << V_13 ;
F_8 ( V_10 , L_2 , V_15 ) ;
switch ( V_16 / 4 ) {
case 0 :
F_9 ( V_4 , V_26 , V_14 , V_15 ) ;
break;
case 1 :
F_9 ( V_4 , V_27 , V_14 , V_15 ) ;
break;
case 2 :
F_9 ( V_4 , V_28 , V_14 , V_15 ) ;
break;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
if ( F_11 ( V_2 ) )
return F_1 ( V_2 , V_4 ,
V_5 , V_6 ) ;
return - V_25 ;
}
static void F_12 ( struct V_3 * V_4 , T_1 V_15 )
{
int V_16 = F_4 ( V_4 ) ;
int V_13 = ( V_16 % 4 ) * 8 ;
T_1 V_14 = 0xFF << V_13 ;
V_15 = V_15 << V_13 ;
if ( V_16 == 8 )
return;
switch ( V_16 / 4 ) {
case 0 :
F_9 ( V_4 , V_29 , V_14 , V_15 ) ;
break;
case 1 :
F_9 ( V_4 , V_30 , V_14 , V_15 ) ;
break;
case 2 :
F_9 ( V_4 , V_31 , V_14 , V_15 ) ;
break;
}
}
int F_13 ( struct V_3 * V_4 )
{
F_12 ( V_4 , 0 ) ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 , unsigned int V_32 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_18 * V_18 ;
int V_33 ;
T_1 V_34 ;
int V_35 [] = {
[ V_19 ] = 0x1 ,
[ V_20 ] = 0x2 ,
[ V_21 ] = 0x3 ,
[ V_36 ] = 0x0 ,
} ;
F_8 ( V_10 , L_3 , V_32 ) ;
V_34 = 0 ;
F_16 (clk, adg, i) {
if ( V_32 == F_5 ( V_18 ) ) {
V_34 = V_35 [ V_33 ] ;
goto V_37;
}
}
if ( V_32 == V_8 -> V_22 ) {
V_34 = 0x10 ;
goto V_37;
}
if ( V_32 == V_8 -> V_23 ) {
V_34 = 0x20 ;
goto V_37;
}
return - V_38 ;
V_37:
F_9 ( V_4 , V_39 , 0x00FF0000 , V_8 -> V_40 ) ;
F_17 ( V_4 , V_41 , 0x00000002 ) ;
F_17 ( V_4 , V_42 , 0x00000002 ) ;
F_12 ( V_4 , V_34 ) ;
F_8 ( V_10 , L_4 ,
F_4 ( V_4 ) , V_33 , V_32 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_18 * V_18 ;
unsigned long V_32 ;
T_1 V_40 ;
int V_33 ;
int V_43 [] = {
[ V_19 ] = 0x0 ,
[ V_20 ] = 0x1 ,
[ V_21 ] = 0x4 ,
[ V_36 ] = 0x2 ,
} ;
V_40 = 0 ;
V_8 -> V_22 = 0 ;
V_8 -> V_23 = 0 ;
F_16 (clk, adg, i) {
V_32 = F_5 ( V_18 ) ;
if ( 0 == V_32 )
continue;
if ( ! V_8 -> V_22 && ( 0 == V_32 % 44100 ) ) {
V_8 -> V_22 = V_32 / 6 ;
V_40 |= V_43 [ V_33 ] << 20 ;
}
if ( ! V_8 -> V_23 && ( 0 == V_32 % 48000 ) ) {
V_8 -> V_23 = V_32 / 6 ;
V_40 |= V_43 [ V_33 ] << 16 ;
}
}
V_8 -> V_40 = V_40 ;
}
int F_19 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_18 * V_18 ;
int V_33 ;
V_8 = F_20 ( V_10 , sizeof( * V_8 ) , V_48 ) ;
if ( ! V_8 ) {
F_7 ( V_10 , L_5 ) ;
return - V_49 ;
}
V_8 -> V_18 [ V_19 ] = F_21 ( NULL , L_6 ) ;
V_8 -> V_18 [ V_20 ] = F_21 ( NULL , L_7 ) ;
V_8 -> V_18 [ V_21 ] = F_21 ( NULL , L_8 ) ;
V_8 -> V_18 [ V_36 ] = F_21 ( NULL , L_9 ) ;
F_16 (clk, adg, i) {
if ( F_22 ( V_18 ) ) {
F_7 ( V_10 , L_10 ) ;
return - V_38 ;
}
}
F_18 ( V_2 , V_8 ) ;
V_2 -> V_8 = V_8 ;
F_8 ( V_10 , L_11 ) ;
return 0 ;
}
void F_23 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_18 * V_18 ;
int V_33 ;
F_16 (clk, adg, i)
F_24 ( V_18 ) ;
}
