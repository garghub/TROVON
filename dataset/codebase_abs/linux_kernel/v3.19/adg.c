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
int F_7 ( struct V_9 * V_10 ,
struct V_3 * V_4 ,
struct V_1 * V_2 )
{
int V_7 = F_4 ( V_4 ) ;
int V_11 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_12 , V_13 ;
V_13 = F_1 ( V_2 ) ;
V_13 = V_13 << V_11 ;
V_12 = 0xffff << V_11 ;
F_8 ( V_4 , V_14 , V_12 , V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_3 * V_4 ,
struct V_1 * V_2 ,
T_1 V_15 )
{
int V_16 = F_10 ( V_10 , V_2 ) ;
int V_7 = F_4 ( V_4 ) ;
int V_11 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_12 , V_8 ;
T_1 V_17 , V_18 ;
V_8 = F_1 ( V_2 ) ;
V_17 = ( V_16 ) ? V_15 : V_8 ;
V_18 = ( V_16 ) ? V_8 : V_15 ;
V_17 = V_17 << V_11 ;
V_18 = V_18 << V_11 ;
V_12 = 0xffff << V_11 ;
switch ( V_7 / 2 ) {
case 0 :
F_8 ( V_4 , V_19 , V_12 , V_17 ) ;
F_8 ( V_4 , V_20 , V_12 , V_18 ) ;
break;
case 1 :
F_8 ( V_4 , V_21 , V_12 , V_17 ) ;
F_8 ( V_4 , V_22 , V_12 , V_18 ) ;
break;
case 2 :
F_8 ( V_4 , V_23 , V_12 , V_17 ) ;
F_8 ( V_4 , V_24 , V_12 , V_18 ) ;
break;
case 3 :
F_8 ( V_4 , V_25 , V_12 , V_17 ) ;
F_8 ( V_4 , V_26 , V_12 , V_18 ) ;
break;
case 4 :
F_8 ( V_4 , V_27 , V_12 , V_17 ) ;
F_8 ( V_4 , V_28 , V_12 , V_18 ) ;
break;
}
return 0 ;
}
int F_11 ( struct V_3 * V_4 ,
struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_29 ,
unsigned int V_30 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_31 * V_32 = F_12 ( V_6 ) ;
struct V_33 * V_34 = F_13 ( V_6 ) ;
int V_35 , V_36 , div , V_37 , V_38 ;
T_1 V_13 , V_39 ;
unsigned int V_40 , V_41 ;
unsigned int V_42 [] = {
F_14 ( V_32 -> V_43 [ V_44 ] ) ,
F_14 ( V_32 -> V_43 [ V_45 ] ) ,
F_14 ( V_32 -> V_43 [ V_46 ] ) ,
V_32 -> V_47 ,
V_32 -> V_48 ,
} ;
V_40 = ~ 0 ;
V_13 = 0 ;
V_39 = 0 ;
for ( V_36 = 0 ; V_36 < F_15 ( V_42 ) ; V_36 ++ ) {
V_35 = 0 ;
V_37 = 2 ;
if ( ! V_42 [ V_36 ] )
continue;
for ( div = 2 ; div <= 98304 ; div += V_37 ) {
V_41 = abs ( V_29 - V_42 [ V_36 ] / div ) ;
if ( V_40 > V_41 ) {
V_13 = ( V_36 << 8 ) | V_35 ;
V_40 = V_41 ;
V_39 = 1 << ( V_36 + 1 ) ;
}
if ( ( V_35 > 2 ) && ( V_35 % 2 ) )
V_37 *= 2 ;
if ( V_35 == 0x1c ) {
div += V_37 ;
V_37 *= 2 ;
}
V_35 ++ ;
}
}
if ( V_40 == ~ 0 ) {
F_16 ( V_34 , L_1 ) ;
return - V_49 ;
}
V_38 = F_9 ( V_10 , V_4 , V_2 , V_13 ) ;
if ( V_38 < 0 ) {
F_16 ( V_34 , L_2 ) ;
return V_38 ;
}
F_8 ( V_4 , V_50 , V_39 , V_39 ) ;
return 0 ;
}
int F_17 ( struct V_3 * V_4 ,
struct V_9 * V_10 ,
struct V_1 * V_2 )
{
T_1 V_13 = F_1 ( V_2 ) ;
return F_9 ( V_10 , V_4 , V_2 , V_13 ) ;
}
int F_18 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
unsigned int V_29 ,
unsigned int V_30 )
{
struct V_31 * V_32 = F_12 ( V_6 ) ;
struct V_33 * V_34 = F_13 ( V_6 ) ;
int V_35 , V_36 , div , V_11 ;
T_1 V_12 , V_13 ;
int V_7 = F_4 ( V_4 ) ;
unsigned int V_42 [] = {
F_14 ( V_32 -> V_43 [ V_44 ] ) ,
F_14 ( V_32 -> V_43 [ V_45 ] ) ,
F_14 ( V_32 -> V_43 [ V_46 ] ) ,
0 ,
V_32 -> V_47 ,
V_32 -> V_48 ,
} ;
for ( V_36 = 0 ; V_36 < F_15 ( V_42 ) ; V_36 ++ ) {
for ( div = 128 , V_35 = 0 ;
div <= 2048 ;
div *= 2 , V_35 ++ ) {
if ( V_29 == V_42 [ V_36 ] / div ) {
V_13 = ( V_35 << 4 ) | V_36 ;
goto V_51;
}
}
}
F_16 ( V_34 , L_3 ) ;
return - V_52 ;
V_51:
V_11 = ( V_7 % 4 ) * 8 ;
V_12 = 0xFF << V_11 ;
V_13 = V_13 << V_11 ;
F_19 ( V_34 , L_4 , V_13 ) ;
switch ( V_7 / 4 ) {
case 0 :
F_8 ( V_4 , V_53 , V_12 , V_13 ) ;
break;
case 1 :
F_8 ( V_4 , V_54 , V_12 , V_13 ) ;
break;
case 2 :
F_8 ( V_4 , V_55 , V_12 , V_13 ) ;
break;
}
return 0 ;
}
static void F_20 ( struct V_3 * V_4 , T_1 V_13 )
{
int V_7 = F_4 ( V_4 ) ;
int V_11 = ( V_7 % 4 ) * 8 ;
T_1 V_12 = 0xFF << V_11 ;
V_13 = V_13 << V_11 ;
if ( V_7 == 8 )
return;
switch ( V_7 / 4 ) {
case 0 :
F_8 ( V_4 , V_56 , V_12 , V_13 ) ;
break;
case 1 :
F_8 ( V_4 , V_57 , V_12 , V_13 ) ;
break;
case 2 :
F_8 ( V_4 , V_58 , V_12 , V_13 ) ;
break;
}
}
int F_21 ( struct V_3 * V_4 )
{
F_20 ( V_4 , 0 ) ;
return 0 ;
}
int F_22 ( struct V_3 * V_4 , unsigned int V_59 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_31 * V_32 = F_12 ( V_6 ) ;
struct V_33 * V_34 = F_13 ( V_6 ) ;
struct V_43 * V_43 ;
int V_60 ;
T_1 V_61 ;
int V_62 [] = {
[ V_44 ] = 0x1 ,
[ V_45 ] = 0x2 ,
[ V_46 ] = 0x3 ,
[ V_63 ] = 0x0 ,
} ;
F_19 ( V_34 , L_5 , V_59 ) ;
V_61 = 0 ;
F_23 (clk, adg, i) {
if ( V_59 == F_14 ( V_43 ) ) {
V_61 = V_62 [ V_60 ] ;
goto V_64;
}
}
if ( V_59 == V_32 -> V_47 ) {
V_61 = 0x10 ;
goto V_64;
}
if ( V_59 == V_32 -> V_48 ) {
V_61 = 0x20 ;
goto V_64;
}
return - V_49 ;
V_64:
F_8 ( V_4 , V_65 , 0x00FF0000 , V_32 -> V_66 ) ;
F_24 ( V_4 , V_67 , 0x00000002 ) ;
F_24 ( V_4 , V_68 , 0x00000002 ) ;
F_20 ( V_4 , V_61 ) ;
F_19 ( V_34 , L_6 ,
F_4 ( V_4 ) , V_60 , V_59 ) ;
return 0 ;
}
static void F_25 ( struct V_5 * V_6 , struct V_31 * V_32 )
{
struct V_43 * V_43 ;
unsigned long V_59 ;
T_1 V_66 ;
int V_60 ;
int V_69 [] = {
[ V_44 ] = 0x0 ,
[ V_45 ] = 0x1 ,
[ V_46 ] = 0x4 ,
[ V_63 ] = 0x2 ,
} ;
V_66 = 0 ;
V_32 -> V_47 = 0 ;
V_32 -> V_48 = 0 ;
F_23 (clk, adg, i) {
V_59 = F_14 ( V_43 ) ;
if ( 0 == V_59 )
continue;
if ( ! V_32 -> V_47 && ( 0 == V_59 % 44100 ) ) {
V_32 -> V_47 = V_59 / 6 ;
V_66 |= V_69 [ V_60 ] << 20 ;
}
if ( ! V_32 -> V_48 && ( 0 == V_59 % 48000 ) ) {
V_32 -> V_48 = V_59 / 6 ;
V_66 |= V_69 [ V_60 ] << 16 ;
}
}
V_32 -> V_66 = V_66 ;
}
int F_26 ( struct V_70 * V_71 ,
const struct V_72 * V_73 ,
struct V_5 * V_6 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 = F_13 ( V_6 ) ;
struct V_43 * V_43 ;
int V_60 ;
V_32 = F_27 ( V_34 , sizeof( * V_32 ) , V_74 ) ;
if ( ! V_32 ) {
F_16 ( V_34 , L_7 ) ;
return - V_75 ;
}
V_32 -> V_43 [ V_44 ] = F_28 ( V_34 , L_8 ) ;
V_32 -> V_43 [ V_45 ] = F_28 ( V_34 , L_9 ) ;
V_32 -> V_43 [ V_46 ] = F_28 ( V_34 , L_10 ) ;
V_32 -> V_43 [ V_63 ] = F_28 ( V_34 , L_11 ) ;
F_23 (clk, adg, i)
F_19 ( V_34 , L_12 , V_60 , V_43 , F_14 ( V_43 ) ) ;
F_25 ( V_6 , V_32 ) ;
V_6 -> V_32 = V_32 ;
F_19 ( V_34 , L_13 ) ;
return 0 ;
}
