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
static void F_6 ( struct V_9 * V_10 ,
struct V_3 * V_4 ,
unsigned int V_11 ,
unsigned int * V_12 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = F_7 ( V_10 ) ;
struct V_16 * V_17 = F_8 ( V_10 ) ;
int V_18 , V_19 , div , V_20 ;
unsigned int V_21 , V_22 ;
unsigned int V_23 , V_24 ;
unsigned int V_25 [] = {
F_9 ( V_15 -> V_26 [ V_27 ] ) ,
F_9 ( V_15 -> V_26 [ V_28 ] ) ,
F_9 ( V_15 -> V_26 [ V_29 ] ) ,
V_15 -> V_30 ,
V_15 -> V_31 ,
} ;
V_23 = ~ 0 ;
V_21 = 0 ;
V_22 = 0 ;
for ( V_19 = 0 ; V_19 < F_10 ( V_25 ) ; V_19 ++ ) {
V_18 = 0 ;
V_20 = 2 ;
if ( ! V_25 [ V_19 ] )
continue;
for ( div = 2 ; div <= 98304 ; div += V_20 ) {
V_24 = abs ( V_11 - V_25 [ V_19 ] / div ) ;
if ( V_23 > V_24 ) {
V_21 = ( V_19 << 8 ) | V_18 ;
V_23 = V_24 ;
V_22 = 1 << ( V_19 + 1 ) ;
}
if ( ( V_18 > 2 ) && ( V_18 % 2 ) )
V_20 *= 2 ;
if ( V_18 == 0x1c ) {
div += V_20 ;
V_20 *= 2 ;
}
V_18 ++ ;
}
}
if ( V_23 == ~ 0 ) {
F_11 ( V_17 , L_1 ) ;
return;
}
* V_12 = V_21 ;
if ( V_13 )
* V_13 = V_22 ;
}
static void F_12 ( struct V_9 * V_10 ,
struct V_3 * V_4 ,
unsigned int V_32 ,
unsigned int V_33 ,
T_1 * V_34 , T_1 * V_35 , T_1 * V_22 )
{
struct V_36 * V_37 = F_13 ( V_4 ) ;
unsigned int V_11 ;
T_1 * V_12 ;
T_1 V_38 ;
T_1 V_39 ;
T_1 V_40 ;
V_38 =
V_39 = F_2 ( V_4 ) ;
V_11 = 0 ;
V_12 = NULL ;
V_40 = 0 ;
if ( V_37 -> V_41 != V_32 ) {
V_11 = V_33 ;
V_12 = & V_39 ;
} else if ( V_37 -> V_41 != V_33 ) {
V_11 = V_32 ;
V_12 = & V_38 ;
}
if ( V_11 )
F_6 ( V_10 , V_4 ,
V_11 ,
V_12 , & V_40 ) ;
if ( V_34 )
* V_34 = V_38 ;
if ( V_35 )
* V_35 = V_39 ;
if ( V_22 )
* V_22 = V_40 ;
}
int F_14 ( struct V_5 * V_42 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 = F_15 ( V_42 ) ;
struct V_14 * V_15 = F_7 ( V_10 ) ;
struct V_5 * V_43 = F_16 ( V_15 ) ;
int V_7 = F_4 ( V_42 ) ;
int V_44 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_45 , V_21 ;
F_12 ( V_10 , V_4 ,
F_17 ( V_10 , V_4 ) ,
F_18 ( V_10 , V_4 ) ,
NULL , & V_21 , NULL ) ;
V_21 = V_21 << V_44 ;
V_45 = 0xffff << V_44 ;
F_19 ( V_43 , V_46 , V_45 , V_21 ) ;
return 0 ;
}
int F_20 ( struct V_5 * V_47 ,
struct V_3 * V_4 ,
unsigned int V_32 ,
unsigned int V_33 )
{
struct V_9 * V_10 = F_15 ( V_47 ) ;
struct V_14 * V_15 = F_7 ( V_10 ) ;
struct V_5 * V_43 = F_16 ( V_15 ) ;
T_1 V_34 , V_35 ;
T_1 V_45 , V_22 ;
int V_7 = F_4 ( V_47 ) ;
int V_44 = ( V_7 % 2 ) ? 16 : 0 ;
F_21 ( V_47 ) ;
F_12 ( V_10 , V_4 ,
V_32 , V_33 ,
& V_34 , & V_35 , & V_22 ) ;
V_34 = V_34 << V_44 ;
V_35 = V_35 << V_44 ;
V_45 = 0xffff << V_44 ;
switch ( V_7 / 2 ) {
case 0 :
F_19 ( V_43 , V_48 , V_45 , V_34 ) ;
F_19 ( V_43 , V_49 , V_45 , V_35 ) ;
break;
case 1 :
F_19 ( V_43 , V_50 , V_45 , V_34 ) ;
F_19 ( V_43 , V_51 , V_45 , V_35 ) ;
break;
case 2 :
F_19 ( V_43 , V_52 , V_45 , V_34 ) ;
F_19 ( V_43 , V_53 , V_45 , V_35 ) ;
break;
case 3 :
F_19 ( V_43 , V_54 , V_45 , V_34 ) ;
F_19 ( V_43 , V_55 , V_45 , V_35 ) ;
break;
case 4 :
F_19 ( V_43 , V_56 , V_45 , V_34 ) ;
F_19 ( V_43 , V_57 , V_45 , V_35 ) ;
break;
}
if ( V_22 )
F_19 ( V_43 , V_58 , V_22 , V_22 ) ;
return 0 ;
}
static void F_22 ( struct V_5 * V_6 , T_1 V_21 )
{
struct V_9 * V_10 = F_15 ( V_6 ) ;
struct V_14 * V_15 = F_7 ( V_10 ) ;
struct V_5 * V_43 = F_16 ( V_15 ) ;
int V_7 = F_4 ( V_6 ) ;
int V_44 = ( V_7 % 4 ) * 8 ;
T_1 V_45 = 0xFF << V_44 ;
F_23 ( V_6 ) ;
V_21 = V_21 << V_44 ;
if ( V_7 == 8 )
return;
switch ( V_7 / 4 ) {
case 0 :
F_19 ( V_43 , V_59 , V_45 , V_21 ) ;
break;
case 1 :
F_19 ( V_43 , V_60 , V_45 , V_21 ) ;
break;
case 2 :
F_19 ( V_43 , V_61 , V_45 , V_21 ) ;
break;
}
}
int F_24 ( struct V_5 * V_6 )
{
F_22 ( V_6 , 0 ) ;
return 0 ;
}
int F_25 ( struct V_5 * V_6 , unsigned int V_41 )
{
struct V_9 * V_10 = F_15 ( V_6 ) ;
struct V_14 * V_15 = F_7 ( V_10 ) ;
struct V_16 * V_17 = F_8 ( V_10 ) ;
struct V_26 * V_26 ;
int V_1 ;
T_1 V_62 ;
int V_63 [] = {
[ V_27 ] = 0x1 ,
[ V_28 ] = 0x2 ,
[ V_29 ] = 0x3 ,
[ V_64 ] = 0x0 ,
} ;
F_26 ( V_17 , L_2 , V_41 ) ;
V_62 = 0 ;
F_27 (clk, adg, i) {
if ( V_41 == F_9 ( V_26 ) ) {
V_62 = V_63 [ V_1 ] ;
goto V_65;
}
}
if ( V_41 == V_15 -> V_30 ) {
V_62 = 0x10 ;
goto V_65;
}
if ( V_41 == V_15 -> V_31 ) {
V_62 = 0x20 ;
goto V_65;
}
return - V_66 ;
V_65:
F_22 ( V_6 , V_62 ) ;
F_26 ( V_17 , L_3 ,
F_28 ( V_6 ) , F_4 ( V_6 ) ,
V_62 , V_41 ) ;
return 0 ;
}
static void F_29 ( struct V_9 * V_10 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = F_8 ( V_10 ) ;
struct V_26 * V_26 ;
static const char * const V_67 [] = {
[ V_27 ] = L_4 ,
[ V_28 ] = L_5 ,
[ V_29 ] = L_6 ,
[ V_64 ] = L_7 ,
} ;
int V_1 , V_68 ;
for ( V_1 = 0 ; V_1 < V_69 ; V_1 ++ ) {
V_26 = F_30 ( V_17 , V_67 [ V_1 ] ) ;
V_15 -> V_26 [ V_1 ] = F_31 ( V_26 ) ? NULL : V_26 ;
}
F_27 (clk, adg, i) {
V_68 = F_32 ( V_26 ) ;
if ( V_68 < 0 )
F_33 ( V_17 , L_8 , V_1 ) ;
F_26 ( V_17 , L_9 , V_1 , V_26 , F_9 ( V_26 ) ) ;
}
}
static void F_34 ( struct V_9 * V_10 ,
struct V_14 * V_15 )
{
struct V_26 * V_26 ;
struct V_5 * V_43 = F_16 ( V_15 ) ;
struct V_16 * V_17 = F_8 ( V_10 ) ;
struct V_70 * V_71 = V_17 -> V_72 ;
T_1 V_73 , V_74 , V_75 , V_76 ;
T_1 V_41 , V_77 = 0 , div ;
T_2 V_78 = 0 ;
unsigned long V_79 , V_80 ;
int V_1 ;
const char * V_81 = NULL ;
static const char * const V_82 [] = {
[ V_83 ] = L_10 ,
[ V_84 ] = L_11 ,
[ V_85 ] = L_12 ,
[ V_86 ] = L_13 ,
} ;
int V_87 [] = {
[ V_27 ] = 0x0 ,
[ V_28 ] = 0x1 ,
[ V_29 ] = 0x4 ,
[ V_64 ] = 0x2 ,
} ;
F_35 ( V_71 , L_14 , & V_78 ) ;
F_35 ( V_71 , L_15 , & V_77 ) ;
V_79 = 0 ;
V_80 = 0 ;
if ( 0 == ( V_77 % 44100 ) )
V_80 = V_77 ;
if ( 0 == ( V_77 % 48000 ) )
V_79 = V_77 ;
V_73 = 0 ;
V_75 = 2 ;
V_76 = 2 ;
V_15 -> V_30 = 0 ;
V_15 -> V_31 = 0 ;
F_27 (clk, adg, i) {
V_41 = F_9 ( V_26 ) ;
if ( 0 == V_41 )
continue;
if ( ! V_15 -> V_30 && ( 0 == V_41 % 44100 ) ) {
div = 6 ;
if ( V_80 )
div = V_41 / V_80 ;
V_74 = F_1 ( div ) ;
if ( F_36 ( V_74 ) == V_74 ) {
V_75 = V_74 ;
V_15 -> V_30 = V_41 / div ;
V_73 |= V_87 [ V_1 ] << 20 ;
if ( V_80 )
V_81 = F_37 ( V_26 ) ;
}
}
if ( ! V_15 -> V_31 && ( 0 == V_41 % 48000 ) ) {
div = 6 ;
if ( V_79 )
div = V_41 / V_79 ;
V_74 = F_1 ( div ) ;
if ( F_36 ( V_74 ) == V_74 ) {
V_76 = V_74 ;
V_15 -> V_31 = V_41 / div ;
V_73 |= V_87 [ V_1 ] << 16 ;
if ( V_79 ) {
V_81 = F_37 ( V_26 ) ;
V_73 |= 0x80000000 ;
}
}
}
}
if ( ! V_78 ) {
V_26 = F_38 ( V_17 , V_82 [ V_83 ] ,
V_81 ,
( V_81 ) ?
0 : V_88 , V_77 ) ;
if ( ! F_31 ( V_26 ) ) {
V_15 -> V_89 [ V_83 ] = V_26 ;
F_39 ( V_71 , V_90 , V_26 ) ;
}
}
else {
for ( V_1 = 0 ; V_1 < V_91 ; V_1 ++ ) {
V_26 = F_38 ( V_17 , V_82 [ V_1 ] ,
V_81 ,
( V_81 ) ?
0 : V_88 ,
V_77 ) ;
if ( ! F_31 ( V_26 ) ) {
V_15 -> V_92 . V_93 = V_15 -> V_89 ;
V_15 -> V_92 . V_94 = V_91 ;
V_15 -> V_89 [ V_1 ] = V_26 ;
F_39 ( V_71 , V_95 ,
& V_15 -> V_92 ) ;
}
}
}
F_19 ( V_43 , V_96 , 0x00FF0000 , V_73 ) ;
F_40 ( V_43 , V_97 , V_75 ) ;
F_40 ( V_43 , V_98 , V_76 ) ;
F_41 (clk, adg, i)
F_26 ( V_17 , L_16 , V_1 , V_26 , F_9 ( V_26 ) ) ;
F_26 ( V_17 , L_17 ,
V_73 , V_75 , V_76 ) ;
}
int F_42 ( struct V_9 * V_10 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 = F_8 ( V_10 ) ;
V_15 = F_43 ( V_17 , sizeof( * V_15 ) , V_99 ) ;
if ( ! V_15 ) {
F_11 ( V_17 , L_18 ) ;
return - V_100 ;
}
F_44 ( V_10 , & V_15 -> V_101 , & V_102 ,
NULL , NULL , 0 , 0 ) ;
F_29 ( V_10 , V_15 ) ;
F_34 ( V_10 , V_15 ) ;
V_10 -> V_15 = V_15 ;
return 0 ;
}
void F_45 ( struct V_9 * V_10 )
{
struct V_14 * V_15 = F_7 ( V_10 ) ;
struct V_26 * V_26 ;
int V_1 ;
F_27 (clk, adg, i) {
F_46 ( V_26 ) ;
}
}
