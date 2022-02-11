static T_1 F_1 ( unsigned long div )
{
int V_1 , V_2 ;
if ( ! div )
return 0 ;
for ( V_1 = 3 ; V_1 >= 0 ; V_1 -- ) {
V_2 = 2 << ( V_1 * 2 ) ;
if ( 0 == ( div % V_2 ) )
return ( T_1 ) ( ( V_1 << 8 ) | ( ( div / V_2 ) - 1 ) ) ;
}
return ~ 0 ;
}
static T_1 F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 = F_4 ( V_6 ) ;
int V_8 = V_7 ;
if ( F_5 ( V_4 ) ) {
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
int F_6 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 = F_7 ( V_6 ) ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_5 * V_13 = F_9 ( V_12 ) ;
int V_7 = F_4 ( V_6 ) ;
int V_14 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_15 , V_16 ;
V_16 = F_2 ( V_4 ) ;
V_16 = V_16 << V_14 ;
V_15 = 0xffff << V_14 ;
F_10 ( V_13 , V_17 , V_15 , V_16 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_18 ,
struct V_3 * V_4 ,
T_1 V_19 )
{
struct V_9 * V_10 = F_7 ( V_18 ) ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_5 * V_13 = F_9 ( V_12 ) ;
int V_20 = F_12 ( V_4 ) ;
int V_7 = F_4 ( V_18 ) ;
int V_14 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_15 , V_8 ;
T_1 V_21 , V_22 ;
F_13 ( V_18 ) ;
V_8 = F_2 ( V_4 ) ;
V_21 = ( V_20 ) ? V_19 : V_8 ;
V_22 = ( V_20 ) ? V_8 : V_19 ;
V_21 = V_21 << V_14 ;
V_22 = V_22 << V_14 ;
V_15 = 0xffff << V_14 ;
switch ( V_7 / 2 ) {
case 0 :
F_10 ( V_13 , V_23 , V_15 , V_21 ) ;
F_10 ( V_13 , V_24 , V_15 , V_22 ) ;
break;
case 1 :
F_10 ( V_13 , V_25 , V_15 , V_21 ) ;
F_10 ( V_13 , V_26 , V_15 , V_22 ) ;
break;
case 2 :
F_10 ( V_13 , V_27 , V_15 , V_21 ) ;
F_10 ( V_13 , V_28 , V_15 , V_22 ) ;
break;
case 3 :
F_10 ( V_13 , V_29 , V_15 , V_21 ) ;
F_10 ( V_13 , V_30 , V_15 , V_22 ) ;
break;
case 4 :
F_10 ( V_13 , V_31 , V_15 , V_21 ) ;
F_10 ( V_13 , V_32 , V_15 , V_22 ) ;
break;
}
return 0 ;
}
int F_14 ( struct V_5 * V_18 ,
struct V_3 * V_4 ,
unsigned int V_33 ,
unsigned int V_34 )
{
struct V_9 * V_10 = F_7 ( V_18 ) ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_5 * V_13 = F_9 ( V_12 ) ;
struct V_35 * V_36 = F_15 ( V_10 ) ;
int V_37 , V_38 , div , V_39 , V_40 ;
T_1 V_16 , V_41 ;
unsigned int V_42 , V_43 ;
unsigned int V_44 [] = {
F_16 ( V_12 -> V_45 [ V_46 ] ) ,
F_16 ( V_12 -> V_45 [ V_47 ] ) ,
F_16 ( V_12 -> V_45 [ V_48 ] ) ,
V_12 -> V_49 ,
V_12 -> V_50 ,
} ;
F_13 ( V_18 ) ;
V_42 = ~ 0 ;
V_16 = 0 ;
V_41 = 0 ;
for ( V_38 = 0 ; V_38 < F_17 ( V_44 ) ; V_38 ++ ) {
V_37 = 0 ;
V_39 = 2 ;
if ( ! V_44 [ V_38 ] )
continue;
for ( div = 2 ; div <= 98304 ; div += V_39 ) {
V_43 = abs ( V_33 - V_44 [ V_38 ] / div ) ;
if ( V_42 > V_43 ) {
V_16 = ( V_38 << 8 ) | V_37 ;
V_42 = V_43 ;
V_41 = 1 << ( V_38 + 1 ) ;
}
if ( ( V_37 > 2 ) && ( V_37 % 2 ) )
V_39 *= 2 ;
if ( V_37 == 0x1c ) {
div += V_39 ;
V_39 *= 2 ;
}
V_37 ++ ;
}
}
if ( V_42 == ~ 0 ) {
F_18 ( V_36 , L_1 ) ;
return - V_51 ;
}
V_40 = F_11 ( V_18 , V_4 , V_16 ) ;
if ( V_40 < 0 ) {
F_18 ( V_36 , L_2 ) ;
return V_40 ;
}
F_10 ( V_13 , V_52 , V_41 , V_41 ) ;
F_19 ( V_36 , L_3 , V_33 , V_34 ) ;
return 0 ;
}
int F_20 ( struct V_5 * V_18 ,
struct V_3 * V_4 )
{
T_1 V_16 = F_2 ( V_4 ) ;
F_13 ( V_18 ) ;
return F_11 ( V_18 , V_4 , V_16 ) ;
}
int F_21 ( struct V_9 * V_10 ,
struct V_5 * V_6 ,
unsigned int V_33 ,
unsigned int V_34 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_5 * V_13 = F_9 ( V_12 ) ;
struct V_35 * V_36 = F_15 ( V_10 ) ;
int V_37 , V_38 , div , V_14 ;
T_1 V_15 , V_16 ;
int V_7 = F_4 ( V_6 ) ;
unsigned int V_44 [] = {
F_16 ( V_12 -> V_45 [ V_46 ] ) ,
F_16 ( V_12 -> V_45 [ V_47 ] ) ,
F_16 ( V_12 -> V_45 [ V_48 ] ) ,
0 ,
V_12 -> V_49 ,
V_12 -> V_50 ,
} ;
for ( V_38 = 0 ; V_38 < F_17 ( V_44 ) ; V_38 ++ ) {
for ( div = 128 , V_37 = 0 ;
div <= 2048 ;
div *= 2 , V_37 ++ ) {
if ( V_33 == V_44 [ V_38 ] / div ) {
V_16 = ( V_37 << 4 ) | V_38 ;
goto V_53;
}
}
}
F_18 ( V_36 , L_4 ) ;
return - V_54 ;
V_53:
V_14 = ( V_7 % 4 ) * 8 ;
V_15 = 0xFF << V_14 ;
V_16 = V_16 << V_14 ;
F_19 ( V_36 , L_5 , V_16 ) ;
switch ( V_7 / 4 ) {
case 0 :
F_10 ( V_13 , V_55 , V_15 , V_16 ) ;
break;
case 1 :
F_10 ( V_13 , V_56 , V_15 , V_16 ) ;
break;
case 2 :
F_10 ( V_13 , V_57 , V_15 , V_16 ) ;
break;
}
return 0 ;
}
static void F_22 ( struct V_5 * V_58 , T_1 V_16 )
{
struct V_9 * V_10 = F_7 ( V_58 ) ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_5 * V_13 = F_9 ( V_12 ) ;
int V_7 = F_4 ( V_58 ) ;
int V_14 = ( V_7 % 4 ) * 8 ;
T_1 V_15 = 0xFF << V_14 ;
F_23 ( V_58 ) ;
V_16 = V_16 << V_14 ;
if ( V_7 == 8 )
return;
switch ( V_7 / 4 ) {
case 0 :
F_10 ( V_13 , V_59 , V_15 , V_16 ) ;
break;
case 1 :
F_10 ( V_13 , V_60 , V_15 , V_16 ) ;
break;
case 2 :
F_10 ( V_13 , V_61 , V_15 , V_16 ) ;
break;
}
}
int F_24 ( struct V_5 * V_6 )
{
F_22 ( V_6 , 0 ) ;
return 0 ;
}
int F_25 ( struct V_5 * V_6 , unsigned int V_62 )
{
struct V_9 * V_10 = F_7 ( V_6 ) ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_35 * V_36 = F_15 ( V_10 ) ;
struct V_45 * V_45 ;
int V_1 ;
T_1 V_63 ;
int V_64 [] = {
[ V_46 ] = 0x1 ,
[ V_47 ] = 0x2 ,
[ V_48 ] = 0x3 ,
[ V_65 ] = 0x0 ,
} ;
F_19 ( V_36 , L_6 , V_62 ) ;
V_63 = 0 ;
F_26 (clk, adg, i) {
if ( V_62 == F_16 ( V_45 ) ) {
V_63 = V_64 [ V_1 ] ;
goto V_66;
}
}
if ( V_62 == V_12 -> V_49 ) {
V_63 = 0x10 ;
goto V_66;
}
if ( V_62 == V_12 -> V_50 ) {
V_63 = 0x20 ;
goto V_66;
}
return - V_51 ;
V_66:
F_22 ( V_6 , V_63 ) ;
F_19 ( V_36 , L_7 ,
F_27 ( V_6 ) , F_4 ( V_6 ) ,
V_63 , V_62 ) ;
return 0 ;
}
static void F_28 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_35 * V_36 = F_15 ( V_10 ) ;
struct V_45 * V_45 ;
static const char * const V_67 [] = {
[ V_46 ] = L_8 ,
[ V_47 ] = L_9 ,
[ V_48 ] = L_10 ,
[ V_65 ] = L_11 ,
} ;
int V_1 ;
for ( V_1 = 0 ; V_1 < V_68 ; V_1 ++ ) {
V_45 = F_29 ( V_36 , V_67 [ V_1 ] ) ;
V_12 -> V_45 [ V_1 ] = F_30 ( V_45 ) ? NULL : V_45 ;
}
F_26 (clk, adg, i)
F_19 ( V_36 , L_12 , V_1 , V_45 , F_16 ( V_45 ) ) ;
}
static void F_31 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_45 * V_45 ;
struct V_5 * V_13 = F_9 ( V_12 ) ;
struct V_35 * V_36 = F_15 ( V_10 ) ;
struct V_69 * V_70 = V_36 -> V_71 ;
T_1 V_72 , V_73 , V_74 , V_75 ;
T_1 V_62 , V_76 , div ;
T_2 V_77 = 0 ;
unsigned long V_78 , V_79 ;
int V_1 ;
const char * V_80 = NULL ;
static const char * const V_81 [] = {
[ V_82 ] = L_13 ,
[ V_83 ] = L_14 ,
[ V_84 ] = L_15 ,
[ V_85 ] = L_16 ,
} ;
int V_86 [] = {
[ V_46 ] = 0x0 ,
[ V_47 ] = 0x1 ,
[ V_48 ] = 0x4 ,
[ V_65 ] = 0x2 ,
} ;
F_32 ( V_70 , L_17 , & V_77 ) ;
F_32 ( V_70 , L_18 , & V_76 ) ;
V_78 = 0 ;
V_79 = 0 ;
if ( 0 == ( V_76 % 44100 ) )
V_79 = V_76 ;
if ( 0 == ( V_76 % 48000 ) )
V_78 = V_76 ;
V_72 = 0 ;
V_74 = 2 ;
V_75 = 2 ;
V_12 -> V_49 = 0 ;
V_12 -> V_50 = 0 ;
F_26 (clk, adg, i) {
V_62 = F_16 ( V_45 ) ;
if ( 0 == V_62 )
continue;
if ( ! V_12 -> V_49 && ( 0 == V_62 % 44100 ) ) {
div = 6 ;
if ( V_79 )
div = V_62 / V_79 ;
V_73 = F_1 ( div ) ;
if ( F_33 ( V_73 ) == V_73 ) {
V_74 = V_73 ;
V_12 -> V_49 = V_62 / div ;
V_72 |= V_86 [ V_1 ] << 20 ;
if ( V_79 )
V_80 = F_34 ( V_45 ) ;
}
}
if ( ! V_12 -> V_50 && ( 0 == V_62 % 48000 ) ) {
div = 6 ;
if ( V_78 )
div = V_62 / V_78 ;
V_73 = F_1 ( div ) ;
if ( F_33 ( V_73 ) == V_73 ) {
V_75 = V_73 ;
V_12 -> V_50 = V_62 / div ;
V_72 |= V_86 [ V_1 ] << 16 ;
if ( V_78 ) {
V_80 = F_34 ( V_45 ) ;
V_72 |= 0x80000000 ;
}
}
}
}
if ( ! V_77 ) {
V_45 = F_35 ( V_36 , V_81 [ V_82 ] ,
V_80 ,
( V_80 ) ?
0 : V_87 , V_76 ) ;
if ( ! F_30 ( V_45 ) ) {
V_12 -> V_88 [ V_82 ] = V_45 ;
F_36 ( V_70 , V_89 , V_45 ) ;
}
}
else {
for ( V_1 = 0 ; V_1 < V_90 ; V_1 ++ ) {
V_45 = F_35 ( V_36 , V_81 [ V_1 ] ,
V_80 ,
( V_80 ) ?
0 : V_87 ,
V_76 ) ;
if ( ! F_30 ( V_45 ) ) {
V_12 -> V_91 . V_92 = V_12 -> V_88 ;
V_12 -> V_91 . V_93 = V_90 ;
V_12 -> V_88 [ V_1 ] = V_45 ;
F_36 ( V_70 , V_94 ,
& V_12 -> V_91 ) ;
}
}
}
F_10 ( V_13 , V_95 , 0x00FF0000 , V_72 ) ;
F_37 ( V_13 , V_96 , V_74 ) ;
F_37 ( V_13 , V_97 , V_75 ) ;
F_38 (clk, adg, i)
F_19 ( V_36 , L_19 , V_1 , V_45 , F_16 ( V_45 ) ) ;
F_19 ( V_36 , L_20 ,
V_72 , V_74 , V_75 ) ;
}
int F_39 ( struct V_98 * V_99 ,
const struct V_100 * V_101 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_35 * V_36 = F_15 ( V_10 ) ;
V_12 = F_40 ( V_36 , sizeof( * V_12 ) , V_102 ) ;
if ( ! V_12 ) {
F_18 ( V_36 , L_21 ) ;
return - V_103 ;
}
V_12 -> V_6 . V_104 = & V_105 ;
V_12 -> V_6 . V_10 = V_10 ;
F_28 ( V_10 , V_12 ) ;
F_31 ( V_10 , V_12 ) ;
V_10 -> V_12 = V_12 ;
return 0 ;
}
