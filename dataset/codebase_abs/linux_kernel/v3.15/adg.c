static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 = F_4 ( V_4 ) ;
int V_8 = V_7 ;
if ( F_5 ( F_6 ( V_6 , V_7 ) ) ) {
switch ( V_7 ) {
case 1 :
case 2 :
V_8 = 0 ;
break;
case 4 :
V_8 = 3 ;
break;
case 8 :
V_8 = 7 ;
break;
}
}
return ( 0x6 + V_8 ) << 8 ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
T_1 V_11 )
{
int V_12 = F_8 ( V_10 , V_2 ) ;
int V_7 = F_4 ( V_4 ) ;
int V_13 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_14 , V_8 ;
T_1 V_15 , V_16 ;
V_8 = F_1 ( V_2 ) ;
V_15 = ( V_12 ) ? V_11 : V_8 ;
V_16 = ( V_12 ) ? V_8 : V_11 ;
V_15 = V_15 << V_13 ;
V_16 = V_16 << V_13 ;
V_14 = 0xffff << V_13 ;
switch ( V_7 / 2 ) {
case 0 :
F_9 ( V_4 , V_17 , V_14 , V_15 ) ;
F_9 ( V_4 , V_18 , V_14 , V_16 ) ;
break;
case 1 :
F_9 ( V_4 , V_19 , V_14 , V_15 ) ;
F_9 ( V_4 , V_20 , V_14 , V_16 ) ;
break;
case 2 :
F_9 ( V_4 , V_21 , V_14 , V_15 ) ;
F_9 ( V_4 , V_22 , V_14 , V_16 ) ;
break;
case 3 :
F_9 ( V_4 , V_23 , V_14 , V_15 ) ;
F_9 ( V_4 , V_24 , V_14 , V_16 ) ;
break;
case 4 :
F_9 ( V_4 , V_25 , V_14 , V_15 ) ;
F_9 ( V_4 , V_26 , V_14 , V_16 ) ;
break;
}
return 0 ;
}
int F_10 ( struct V_3 * V_4 ,
struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_27 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_29 * V_30 = F_11 ( V_6 ) ;
struct V_31 * V_32 = F_12 ( V_6 ) ;
int V_33 , V_34 , div , V_35 , V_36 ;
T_1 V_37 , V_38 ;
unsigned int V_39 , V_40 ;
unsigned int V_41 [] = {
F_13 ( V_30 -> V_42 [ V_43 ] ) ,
F_13 ( V_30 -> V_42 [ V_44 ] ) ,
F_13 ( V_30 -> V_42 [ V_45 ] ) ,
V_30 -> V_46 ,
V_30 -> V_47 ,
} ;
V_39 = ~ 0 ;
V_37 = 0 ;
V_38 = 0 ;
for ( V_34 = 0 ; V_34 < F_14 ( V_41 ) ; V_34 ++ ) {
V_33 = 0 ;
V_35 = 2 ;
if ( ! V_41 [ V_34 ] )
continue;
for ( div = 2 ; div <= 98304 ; div += V_35 ) {
V_40 = abs ( V_27 - V_41 [ V_34 ] / div ) ;
if ( V_39 > V_40 ) {
V_37 = ( V_34 << 8 ) | V_33 ;
V_39 = V_40 ;
V_38 = 1 << ( V_34 + 1 ) ;
}
if ( ( V_33 > 2 ) && ( V_33 % 2 ) )
V_35 *= 2 ;
if ( V_33 == 0x1c ) {
div += V_35 ;
V_35 *= 2 ;
}
V_33 ++ ;
}
}
if ( V_39 == ~ 0 ) {
F_15 ( V_32 , L_1 ) ;
return - V_48 ;
}
V_36 = F_7 ( V_10 , V_4 , V_2 , V_37 ) ;
if ( V_36 < 0 ) {
F_15 ( V_32 , L_2 ) ;
return V_36 ;
}
F_9 ( V_4 , V_49 , V_38 , V_38 ) ;
return 0 ;
}
int F_16 ( struct V_3 * V_4 ,
struct V_9 * V_10 ,
struct V_1 * V_2 )
{
T_1 V_37 = F_1 ( V_2 ) ;
return F_7 ( V_10 , V_4 , V_2 , V_37 ) ;
}
int F_17 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
unsigned int V_27 ,
unsigned int V_28 )
{
struct V_29 * V_30 = F_11 ( V_6 ) ;
struct V_31 * V_32 = F_12 ( V_6 ) ;
int V_33 , V_34 , div , V_13 ;
T_1 V_14 , V_37 ;
int V_7 = F_4 ( V_4 ) ;
unsigned int V_41 [] = {
F_13 ( V_30 -> V_42 [ V_43 ] ) ,
F_13 ( V_30 -> V_42 [ V_44 ] ) ,
F_13 ( V_30 -> V_42 [ V_45 ] ) ,
0 ,
V_30 -> V_46 ,
V_30 -> V_47 ,
} ;
for ( V_34 = 0 ; V_34 < F_14 ( V_41 ) ; V_34 ++ ) {
for ( div = 128 , V_33 = 0 ;
div <= 2048 ;
div *= 2 , V_33 ++ ) {
if ( V_27 == V_41 [ V_34 ] / div ) {
V_37 = ( V_33 << 4 ) | V_34 ;
goto V_50;
}
}
}
F_15 ( V_32 , L_3 ) ;
return - V_51 ;
V_50:
V_13 = ( V_7 % 4 ) * 8 ;
V_14 = 0xFF << V_13 ;
V_37 = V_37 << V_13 ;
F_18 ( V_32 , L_4 , V_37 ) ;
switch ( V_7 / 4 ) {
case 0 :
F_9 ( V_4 , V_52 , V_14 , V_37 ) ;
break;
case 1 :
F_9 ( V_4 , V_53 , V_14 , V_37 ) ;
break;
case 2 :
F_9 ( V_4 , V_54 , V_14 , V_37 ) ;
break;
}
return 0 ;
}
static void F_19 ( struct V_3 * V_4 , T_1 V_37 )
{
int V_7 = F_4 ( V_4 ) ;
int V_13 = ( V_7 % 4 ) * 8 ;
T_1 V_14 = 0xFF << V_13 ;
V_37 = V_37 << V_13 ;
if ( V_7 == 8 )
return;
switch ( V_7 / 4 ) {
case 0 :
F_9 ( V_4 , V_55 , V_14 , V_37 ) ;
break;
case 1 :
F_9 ( V_4 , V_56 , V_14 , V_37 ) ;
break;
case 2 :
F_9 ( V_4 , V_57 , V_14 , V_37 ) ;
break;
}
}
int F_20 ( struct V_3 * V_4 )
{
F_19 ( V_4 , 0 ) ;
return 0 ;
}
int F_21 ( struct V_3 * V_4 , unsigned int V_58 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_29 * V_30 = F_11 ( V_6 ) ;
struct V_31 * V_32 = F_12 ( V_6 ) ;
struct V_42 * V_42 ;
int V_59 ;
T_1 V_60 ;
int V_61 [] = {
[ V_43 ] = 0x1 ,
[ V_44 ] = 0x2 ,
[ V_45 ] = 0x3 ,
[ V_62 ] = 0x0 ,
} ;
F_18 ( V_32 , L_5 , V_58 ) ;
V_60 = 0 ;
F_22 (clk, adg, i) {
if ( V_58 == F_13 ( V_42 ) ) {
V_60 = V_61 [ V_59 ] ;
goto V_63;
}
}
if ( V_58 == V_30 -> V_46 ) {
V_60 = 0x10 ;
goto V_63;
}
if ( V_58 == V_30 -> V_47 ) {
V_60 = 0x20 ;
goto V_63;
}
return - V_48 ;
V_63:
F_9 ( V_4 , V_64 , 0x00FF0000 , V_30 -> V_65 ) ;
F_23 ( V_4 , V_66 , 0x00000002 ) ;
F_23 ( V_4 , V_67 , 0x00000002 ) ;
F_19 ( V_4 , V_60 ) ;
F_18 ( V_32 , L_6 ,
F_4 ( V_4 ) , V_59 , V_58 ) ;
return 0 ;
}
static void F_24 ( struct V_5 * V_6 , struct V_29 * V_30 )
{
struct V_42 * V_42 ;
unsigned long V_58 ;
T_1 V_65 ;
int V_59 ;
int V_68 [] = {
[ V_43 ] = 0x0 ,
[ V_44 ] = 0x1 ,
[ V_45 ] = 0x4 ,
[ V_62 ] = 0x2 ,
} ;
V_65 = 0 ;
V_30 -> V_46 = 0 ;
V_30 -> V_47 = 0 ;
F_22 (clk, adg, i) {
V_58 = F_13 ( V_42 ) ;
if ( 0 == V_58 )
continue;
if ( ! V_30 -> V_46 && ( 0 == V_58 % 44100 ) ) {
V_30 -> V_46 = V_58 / 6 ;
V_65 |= V_68 [ V_59 ] << 20 ;
}
if ( ! V_30 -> V_47 && ( 0 == V_58 % 48000 ) ) {
V_30 -> V_47 = V_58 / 6 ;
V_65 |= V_68 [ V_59 ] << 16 ;
}
}
V_30 -> V_65 = V_65 ;
}
int F_25 ( struct V_69 * V_70 ,
const struct V_71 * V_72 ,
struct V_5 * V_6 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 = F_12 ( V_6 ) ;
struct V_42 * V_42 , * V_73 ;
int V_59 ;
bool V_74 = false ;
V_30 = F_26 ( V_32 , sizeof( * V_30 ) , V_75 ) ;
if ( ! V_30 ) {
F_15 ( V_32 , L_7 ) ;
return - V_76 ;
}
V_73 = F_27 ( V_32 , NULL ) ;
V_30 -> V_42 [ V_43 ] = F_27 ( V_32 , L_8 ) ;
V_30 -> V_42 [ V_44 ] = F_27 ( V_32 , L_9 ) ;
V_30 -> V_42 [ V_45 ] = F_27 ( V_32 , L_10 ) ;
V_30 -> V_42 [ V_62 ] = F_27 ( V_32 , L_11 ) ;
F_22 (clk, adg, i) {
if ( V_73 == V_42 ) {
F_28 ( V_32 ,
L_12 ) ;
V_74 = true ;
break;
}
}
if ( V_74 ) {
V_30 -> V_42 [ V_43 ] = F_27 ( NULL , L_13 ) ;
V_30 -> V_42 [ V_44 ] = F_27 ( NULL , L_14 ) ;
V_30 -> V_42 [ V_45 ] = F_27 ( NULL , L_15 ) ;
V_30 -> V_42 [ V_62 ] = F_27 ( NULL , L_16 ) ;
}
F_22 (clk, adg, i) {
if ( F_29 ( V_42 ) ) {
F_15 ( V_32 , L_17 ) ;
return - V_48 ;
}
}
F_24 ( V_6 , V_30 ) ;
V_6 -> V_30 = V_30 ;
F_18 ( V_32 , L_18 ) ;
return 0 ;
}
