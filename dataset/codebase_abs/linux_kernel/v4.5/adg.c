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
int F_6 ( struct V_5 * V_9 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_5 * V_14 = F_9 ( V_13 ) ;
int V_7 = F_4 ( V_9 ) ;
int V_15 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_16 , V_17 ;
V_17 = F_2 ( V_4 ) ;
V_17 = V_17 << V_15 ;
V_16 = 0xffff << V_15 ;
F_10 ( V_14 , V_18 , V_16 , V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_19 ,
struct V_3 * V_4 ,
T_1 V_20 )
{
struct V_10 * V_11 = F_7 ( V_19 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_5 * V_14 = F_9 ( V_13 ) ;
int V_21 = F_12 ( V_4 ) ;
int V_7 = F_4 ( V_19 ) ;
int V_15 = ( V_7 % 2 ) ? 16 : 0 ;
T_1 V_16 , V_8 ;
T_1 V_22 , V_23 ;
F_13 ( V_19 ) ;
V_8 = F_2 ( V_4 ) ;
V_22 = ( V_21 ) ? V_20 : V_8 ;
V_23 = ( V_21 ) ? V_8 : V_20 ;
V_22 = V_22 << V_15 ;
V_23 = V_23 << V_15 ;
V_16 = 0xffff << V_15 ;
switch ( V_7 / 2 ) {
case 0 :
F_10 ( V_14 , V_24 , V_16 , V_22 ) ;
F_10 ( V_14 , V_25 , V_16 , V_23 ) ;
break;
case 1 :
F_10 ( V_14 , V_26 , V_16 , V_22 ) ;
F_10 ( V_14 , V_27 , V_16 , V_23 ) ;
break;
case 2 :
F_10 ( V_14 , V_28 , V_16 , V_22 ) ;
F_10 ( V_14 , V_29 , V_16 , V_23 ) ;
break;
case 3 :
F_10 ( V_14 , V_30 , V_16 , V_22 ) ;
F_10 ( V_14 , V_31 , V_16 , V_23 ) ;
break;
case 4 :
F_10 ( V_14 , V_32 , V_16 , V_22 ) ;
F_10 ( V_14 , V_33 , V_16 , V_23 ) ;
break;
}
return 0 ;
}
int F_14 ( struct V_5 * V_19 ,
struct V_3 * V_4 ,
unsigned int V_34 ,
unsigned int V_35 )
{
struct V_10 * V_11 = F_7 ( V_19 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_5 * V_14 = F_9 ( V_13 ) ;
struct V_36 * V_37 = F_15 ( V_11 ) ;
int V_38 , V_39 , div , V_40 , V_41 ;
T_1 V_17 , V_42 ;
unsigned int V_43 , V_44 ;
unsigned int V_45 [] = {
F_16 ( V_13 -> V_46 [ V_47 ] ) ,
F_16 ( V_13 -> V_46 [ V_48 ] ) ,
F_16 ( V_13 -> V_46 [ V_49 ] ) ,
V_13 -> V_50 ,
V_13 -> V_51 ,
} ;
F_13 ( V_19 ) ;
V_43 = ~ 0 ;
V_17 = 0 ;
V_42 = 0 ;
for ( V_39 = 0 ; V_39 < F_17 ( V_45 ) ; V_39 ++ ) {
V_38 = 0 ;
V_40 = 2 ;
if ( ! V_45 [ V_39 ] )
continue;
for ( div = 2 ; div <= 98304 ; div += V_40 ) {
V_44 = abs ( V_34 - V_45 [ V_39 ] / div ) ;
if ( V_43 > V_44 ) {
V_17 = ( V_39 << 8 ) | V_38 ;
V_43 = V_44 ;
V_42 = 1 << ( V_39 + 1 ) ;
}
if ( ( V_38 > 2 ) && ( V_38 % 2 ) )
V_40 *= 2 ;
if ( V_38 == 0x1c ) {
div += V_40 ;
V_40 *= 2 ;
}
V_38 ++ ;
}
}
if ( V_43 == ~ 0 ) {
F_18 ( V_37 , L_1 ) ;
return - V_52 ;
}
V_41 = F_11 ( V_19 , V_4 , V_17 ) ;
if ( V_41 < 0 ) {
F_18 ( V_37 , L_2 ) ;
return V_41 ;
}
F_10 ( V_14 , V_53 , V_42 , V_42 ) ;
F_19 ( V_37 , L_3 , V_34 , V_35 ) ;
return 0 ;
}
int F_20 ( struct V_5 * V_19 ,
struct V_3 * V_4 )
{
T_1 V_17 = F_2 ( V_4 ) ;
F_13 ( V_19 ) ;
return F_11 ( V_19 , V_4 , V_17 ) ;
}
static void F_21 ( struct V_5 * V_6 , T_1 V_17 )
{
struct V_10 * V_11 = F_7 ( V_6 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_5 * V_14 = F_9 ( V_13 ) ;
int V_7 = F_4 ( V_6 ) ;
int V_15 = ( V_7 % 4 ) * 8 ;
T_1 V_16 = 0xFF << V_15 ;
F_22 ( V_6 ) ;
V_17 = V_17 << V_15 ;
if ( V_7 == 8 )
return;
switch ( V_7 / 4 ) {
case 0 :
F_10 ( V_14 , V_54 , V_16 , V_17 ) ;
break;
case 1 :
F_10 ( V_14 , V_55 , V_16 , V_17 ) ;
break;
case 2 :
F_10 ( V_14 , V_56 , V_16 , V_17 ) ;
break;
}
}
int F_23 ( struct V_5 * V_6 )
{
F_21 ( V_6 , 0 ) ;
return 0 ;
}
int F_24 ( struct V_5 * V_6 , unsigned int V_57 )
{
struct V_10 * V_11 = F_7 ( V_6 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_36 * V_37 = F_15 ( V_11 ) ;
struct V_46 * V_46 ;
int V_1 ;
T_1 V_58 ;
int V_59 [] = {
[ V_47 ] = 0x1 ,
[ V_48 ] = 0x2 ,
[ V_49 ] = 0x3 ,
[ V_60 ] = 0x0 ,
} ;
F_19 ( V_37 , L_4 , V_57 ) ;
V_58 = 0 ;
F_25 (clk, adg, i) {
if ( V_57 == F_16 ( V_46 ) ) {
V_58 = V_59 [ V_1 ] ;
goto V_61;
}
}
if ( V_57 == V_13 -> V_50 ) {
V_58 = 0x10 ;
goto V_61;
}
if ( V_57 == V_13 -> V_51 ) {
V_58 = 0x20 ;
goto V_61;
}
return - V_52 ;
V_61:
F_21 ( V_6 , V_58 ) ;
F_19 ( V_37 , L_5 ,
F_26 ( V_6 ) , F_4 ( V_6 ) ,
V_58 , V_57 ) ;
return 0 ;
}
static void F_27 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_36 * V_37 = F_15 ( V_11 ) ;
struct V_46 * V_46 ;
static const char * const V_62 [] = {
[ V_47 ] = L_6 ,
[ V_48 ] = L_7 ,
[ V_49 ] = L_8 ,
[ V_60 ] = L_9 ,
} ;
int V_1 , V_41 ;
for ( V_1 = 0 ; V_1 < V_63 ; V_1 ++ ) {
V_46 = F_28 ( V_37 , V_62 [ V_1 ] ) ;
V_13 -> V_46 [ V_1 ] = F_29 ( V_46 ) ? NULL : V_46 ;
}
F_25 (clk, adg, i) {
V_41 = F_30 ( V_46 ) ;
if ( V_41 < 0 )
F_31 ( V_37 , L_10 , V_1 ) ;
F_19 ( V_37 , L_11 , V_1 , V_46 , F_16 ( V_46 ) ) ;
}
}
static void F_32 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_46 * V_46 ;
struct V_5 * V_14 = F_9 ( V_13 ) ;
struct V_36 * V_37 = F_15 ( V_11 ) ;
struct V_64 * V_65 = V_37 -> V_66 ;
T_1 V_67 , V_68 , V_69 , V_70 ;
T_1 V_57 , V_71 = 0 , div ;
T_2 V_72 = 0 ;
unsigned long V_73 , V_74 ;
int V_1 ;
const char * V_75 = NULL ;
static const char * const V_76 [] = {
[ V_77 ] = L_12 ,
[ V_78 ] = L_13 ,
[ V_79 ] = L_14 ,
[ V_80 ] = L_15 ,
} ;
int V_81 [] = {
[ V_47 ] = 0x0 ,
[ V_48 ] = 0x1 ,
[ V_49 ] = 0x4 ,
[ V_60 ] = 0x2 ,
} ;
F_33 ( V_65 , L_16 , & V_72 ) ;
F_33 ( V_65 , L_17 , & V_71 ) ;
V_73 = 0 ;
V_74 = 0 ;
if ( 0 == ( V_71 % 44100 ) )
V_74 = V_71 ;
if ( 0 == ( V_71 % 48000 ) )
V_73 = V_71 ;
V_67 = 0 ;
V_69 = 2 ;
V_70 = 2 ;
V_13 -> V_50 = 0 ;
V_13 -> V_51 = 0 ;
F_25 (clk, adg, i) {
V_57 = F_16 ( V_46 ) ;
if ( 0 == V_57 )
continue;
if ( ! V_13 -> V_50 && ( 0 == V_57 % 44100 ) ) {
div = 6 ;
if ( V_74 )
div = V_57 / V_74 ;
V_68 = F_1 ( div ) ;
if ( F_34 ( V_68 ) == V_68 ) {
V_69 = V_68 ;
V_13 -> V_50 = V_57 / div ;
V_67 |= V_81 [ V_1 ] << 20 ;
if ( V_74 )
V_75 = F_35 ( V_46 ) ;
}
}
if ( ! V_13 -> V_51 && ( 0 == V_57 % 48000 ) ) {
div = 6 ;
if ( V_73 )
div = V_57 / V_73 ;
V_68 = F_1 ( div ) ;
if ( F_34 ( V_68 ) == V_68 ) {
V_70 = V_68 ;
V_13 -> V_51 = V_57 / div ;
V_67 |= V_81 [ V_1 ] << 16 ;
if ( V_73 ) {
V_75 = F_35 ( V_46 ) ;
V_67 |= 0x80000000 ;
}
}
}
}
if ( ! V_72 ) {
V_46 = F_36 ( V_37 , V_76 [ V_77 ] ,
V_75 ,
( V_75 ) ?
0 : V_82 , V_71 ) ;
if ( ! F_29 ( V_46 ) ) {
V_13 -> V_83 [ V_77 ] = V_46 ;
F_37 ( V_65 , V_84 , V_46 ) ;
}
}
else {
for ( V_1 = 0 ; V_1 < V_85 ; V_1 ++ ) {
V_46 = F_36 ( V_37 , V_76 [ V_1 ] ,
V_75 ,
( V_75 ) ?
0 : V_82 ,
V_71 ) ;
if ( ! F_29 ( V_46 ) ) {
V_13 -> V_86 . V_87 = V_13 -> V_83 ;
V_13 -> V_86 . V_88 = V_85 ;
V_13 -> V_83 [ V_1 ] = V_46 ;
F_37 ( V_65 , V_89 ,
& V_13 -> V_86 ) ;
}
}
}
F_10 ( V_14 , V_90 , 0x00FF0000 , V_67 ) ;
F_38 ( V_14 , V_91 , V_69 ) ;
F_38 ( V_14 , V_92 , V_70 ) ;
F_39 (clk, adg, i)
F_19 ( V_37 , L_18 , V_1 , V_46 , F_16 ( V_46 ) ) ;
F_19 ( V_37 , L_19 ,
V_67 , V_69 , V_70 ) ;
}
int F_40 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_36 * V_37 = F_15 ( V_11 ) ;
V_13 = F_41 ( V_37 , sizeof( * V_13 ) , V_93 ) ;
if ( ! V_13 ) {
F_18 ( V_37 , L_20 ) ;
return - V_94 ;
}
V_13 -> V_95 . V_96 = & V_97 ;
V_13 -> V_95 . V_11 = V_11 ;
F_27 ( V_11 , V_13 ) ;
F_32 ( V_11 , V_13 ) ;
V_11 -> V_13 = V_13 ;
return 0 ;
}
void F_42 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_46 * V_46 ;
int V_1 ;
F_25 (clk, adg, i) {
F_43 ( V_46 ) ;
}
}
