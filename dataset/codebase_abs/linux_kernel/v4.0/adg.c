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
int F_7 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
int V_7 = F_4 ( V_4 ) ;
int V_9 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_10 , V_11 ;
V_11 = F_1 ( V_2 ) ;
V_11 = V_11 << V_9 ;
V_10 = 0xffff << V_9 ;
F_8 ( V_4 , V_12 , V_10 , V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
T_1 V_13 )
{
int V_14 = F_10 ( V_2 ) ;
int V_7 = F_4 ( V_4 ) ;
int V_9 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_10 , V_8 ;
T_1 V_15 , V_16 ;
V_8 = F_1 ( V_2 ) ;
V_15 = ( V_14 ) ? V_13 : V_8 ;
V_16 = ( V_14 ) ? V_8 : V_13 ;
V_15 = V_15 << V_9 ;
V_16 = V_16 << V_9 ;
V_10 = 0xffff << V_9 ;
switch ( V_7 / 2 ) {
case 0 :
F_8 ( V_4 , V_17 , V_10 , V_15 ) ;
F_8 ( V_4 , V_18 , V_10 , V_16 ) ;
break;
case 1 :
F_8 ( V_4 , V_19 , V_10 , V_15 ) ;
F_8 ( V_4 , V_20 , V_10 , V_16 ) ;
break;
case 2 :
F_8 ( V_4 , V_21 , V_10 , V_15 ) ;
F_8 ( V_4 , V_22 , V_10 , V_16 ) ;
break;
case 3 :
F_8 ( V_4 , V_23 , V_10 , V_15 ) ;
F_8 ( V_4 , V_24 , V_10 , V_16 ) ;
break;
case 4 :
F_8 ( V_4 , V_25 , V_10 , V_15 ) ;
F_8 ( V_4 , V_26 , V_10 , V_16 ) ;
break;
}
return 0 ;
}
int F_11 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
unsigned int V_27 ,
unsigned int V_28 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_29 * V_30 = F_12 ( V_6 ) ;
struct V_31 * V_32 = F_13 ( V_6 ) ;
int V_33 , V_34 , div , V_35 , V_36 ;
T_1 V_11 , V_37 ;
unsigned int V_38 , V_39 ;
unsigned int V_40 [] = {
F_14 ( V_30 -> V_41 [ V_42 ] ) ,
F_14 ( V_30 -> V_41 [ V_43 ] ) ,
F_14 ( V_30 -> V_41 [ V_44 ] ) ,
V_30 -> V_45 ,
V_30 -> V_46 ,
} ;
V_38 = ~ 0 ;
V_11 = 0 ;
V_37 = 0 ;
for ( V_34 = 0 ; V_34 < F_15 ( V_40 ) ; V_34 ++ ) {
V_33 = 0 ;
V_35 = 2 ;
if ( ! V_40 [ V_34 ] )
continue;
for ( div = 2 ; div <= 98304 ; div += V_35 ) {
V_39 = abs ( V_27 - V_40 [ V_34 ] / div ) ;
if ( V_38 > V_39 ) {
V_11 = ( V_34 << 8 ) | V_33 ;
V_38 = V_39 ;
V_37 = 1 << ( V_34 + 1 ) ;
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
if ( V_38 == ~ 0 ) {
F_16 ( V_32 , L_1 ) ;
return - V_47 ;
}
V_36 = F_9 ( V_4 , V_2 , V_11 ) ;
if ( V_36 < 0 ) {
F_16 ( V_32 , L_2 ) ;
return V_36 ;
}
F_8 ( V_4 , V_48 , V_37 , V_37 ) ;
return 0 ;
}
int F_17 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
T_1 V_11 = F_1 ( V_2 ) ;
return F_9 ( V_4 , V_2 , V_11 ) ;
}
int F_18 ( struct V_5 * V_6 ,
struct V_3 * V_4 ,
unsigned int V_27 ,
unsigned int V_28 )
{
struct V_29 * V_30 = F_12 ( V_6 ) ;
struct V_31 * V_32 = F_13 ( V_6 ) ;
int V_33 , V_34 , div , V_9 ;
T_1 V_10 , V_11 ;
int V_7 = F_4 ( V_4 ) ;
unsigned int V_40 [] = {
F_14 ( V_30 -> V_41 [ V_42 ] ) ,
F_14 ( V_30 -> V_41 [ V_43 ] ) ,
F_14 ( V_30 -> V_41 [ V_44 ] ) ,
0 ,
V_30 -> V_45 ,
V_30 -> V_46 ,
} ;
for ( V_34 = 0 ; V_34 < F_15 ( V_40 ) ; V_34 ++ ) {
for ( div = 128 , V_33 = 0 ;
div <= 2048 ;
div *= 2 , V_33 ++ ) {
if ( V_27 == V_40 [ V_34 ] / div ) {
V_11 = ( V_33 << 4 ) | V_34 ;
goto V_49;
}
}
}
F_16 ( V_32 , L_3 ) ;
return - V_50 ;
V_49:
V_9 = ( V_7 % 4 ) * 8 ;
V_10 = 0xFF << V_9 ;
V_11 = V_11 << V_9 ;
F_19 ( V_32 , L_4 , V_11 ) ;
switch ( V_7 / 4 ) {
case 0 :
F_8 ( V_4 , V_51 , V_10 , V_11 ) ;
break;
case 1 :
F_8 ( V_4 , V_52 , V_10 , V_11 ) ;
break;
case 2 :
F_8 ( V_4 , V_53 , V_10 , V_11 ) ;
break;
}
return 0 ;
}
static void F_20 ( struct V_3 * V_4 , T_1 V_11 )
{
int V_7 = F_4 ( V_4 ) ;
int V_9 = ( V_7 % 4 ) * 8 ;
T_1 V_10 = 0xFF << V_9 ;
V_11 = V_11 << V_9 ;
if ( V_7 == 8 )
return;
switch ( V_7 / 4 ) {
case 0 :
F_8 ( V_4 , V_54 , V_10 , V_11 ) ;
break;
case 1 :
F_8 ( V_4 , V_55 , V_10 , V_11 ) ;
break;
case 2 :
F_8 ( V_4 , V_56 , V_10 , V_11 ) ;
break;
}
}
int F_21 ( struct V_3 * V_4 )
{
F_20 ( V_4 , 0 ) ;
return 0 ;
}
int F_22 ( struct V_3 * V_4 , unsigned int V_57 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_29 * V_30 = F_12 ( V_6 ) ;
struct V_31 * V_32 = F_13 ( V_6 ) ;
struct V_41 * V_41 ;
int V_58 ;
T_1 V_59 ;
int V_60 [] = {
[ V_42 ] = 0x1 ,
[ V_43 ] = 0x2 ,
[ V_44 ] = 0x3 ,
[ V_61 ] = 0x0 ,
} ;
F_19 ( V_32 , L_5 , V_57 ) ;
V_59 = 0 ;
F_23 (clk, adg, i) {
if ( V_57 == F_14 ( V_41 ) ) {
V_59 = V_60 [ V_58 ] ;
goto V_62;
}
}
if ( V_57 == V_30 -> V_45 ) {
V_59 = 0x10 ;
goto V_62;
}
if ( V_57 == V_30 -> V_46 ) {
V_59 = 0x20 ;
goto V_62;
}
return - V_47 ;
V_62:
F_8 ( V_4 , V_63 , 0x00FF0000 , V_30 -> V_64 ) ;
F_24 ( V_4 , V_65 , 0x00000002 ) ;
F_24 ( V_4 , V_66 , 0x00000002 ) ;
F_20 ( V_4 , V_59 ) ;
F_19 ( V_32 , L_6 ,
F_4 ( V_4 ) , V_58 , V_57 ) ;
return 0 ;
}
static void F_25 ( struct V_5 * V_6 , struct V_29 * V_30 )
{
struct V_41 * V_41 ;
unsigned long V_57 ;
T_1 V_64 ;
int V_58 ;
int V_67 [] = {
[ V_42 ] = 0x0 ,
[ V_43 ] = 0x1 ,
[ V_44 ] = 0x4 ,
[ V_61 ] = 0x2 ,
} ;
V_64 = 0 ;
V_30 -> V_45 = 0 ;
V_30 -> V_46 = 0 ;
F_23 (clk, adg, i) {
V_57 = F_14 ( V_41 ) ;
if ( 0 == V_57 )
continue;
if ( ! V_30 -> V_45 && ( 0 == V_57 % 44100 ) ) {
V_30 -> V_45 = V_57 / 6 ;
V_64 |= V_67 [ V_58 ] << 20 ;
}
if ( ! V_30 -> V_46 && ( 0 == V_57 % 48000 ) ) {
V_30 -> V_46 = V_57 / 6 ;
V_64 |= V_67 [ V_58 ] << 16 ;
}
}
V_30 -> V_64 = V_64 ;
}
int F_26 ( struct V_68 * V_69 ,
const struct V_70 * V_71 ,
struct V_5 * V_6 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 = F_13 ( V_6 ) ;
struct V_41 * V_41 ;
int V_58 ;
V_30 = F_27 ( V_32 , sizeof( * V_30 ) , V_72 ) ;
if ( ! V_30 ) {
F_16 ( V_32 , L_7 ) ;
return - V_73 ;
}
V_30 -> V_41 [ V_42 ] = F_28 ( V_32 , L_8 ) ;
V_30 -> V_41 [ V_43 ] = F_28 ( V_32 , L_9 ) ;
V_30 -> V_41 [ V_44 ] = F_28 ( V_32 , L_10 ) ;
V_30 -> V_41 [ V_61 ] = F_28 ( V_32 , L_11 ) ;
F_23 (clk, adg, i)
F_19 ( V_32 , L_12 , V_58 , V_41 , F_14 ( V_41 ) ) ;
F_25 ( V_6 , V_30 ) ;
V_6 -> V_30 = V_30 ;
F_19 ( V_32 , L_13 ) ;
return 0 ;
}
