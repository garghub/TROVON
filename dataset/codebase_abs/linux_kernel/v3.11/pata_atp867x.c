static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_12 = V_4 -> V_13 ;
T_1 V_14 ;
T_1 V_15 = V_12 - V_16 + 1 ;
if ( V_10 -> V_17 && V_15 > V_18 &&
( V_6 -> V_19 == V_20 ||
V_15 < V_21 ) )
V_15 -- ;
V_14 = F_3 ( V_10 -> V_13 ) ;
if ( V_4 -> V_22 & 1 ) {
V_14 = ( V_14 & ~ V_23 ) |
( V_15 << V_24 ) ;
} else {
V_14 = ( V_14 & ~ V_25 ) |
( V_15 << V_26 ) ;
}
F_4 ( V_14 , V_10 -> V_13 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_27 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned char V_28 = V_27 ;
if ( V_10 -> V_17 )
V_28 ++ ;
switch ( V_28 ) {
case 0 :
V_28 = 1 ;
break;
case 1 ... 6 :
break;
default:
F_6 ( V_29 L_1
L_2 , V_27 ) ;
case 9 ... 12 :
V_28 = 7 ;
break;
case 7 :
case 8 :
V_28 = 0 ;
goto V_30;
}
V_30:
return V_28 << V_31 ;
}
static int F_7 ( unsigned int V_27 )
{
unsigned char V_28 = V_27 ;
switch ( V_28 ) {
case 0 :
V_28 = 1 ;
break;
case 1 ... 11 :
break;
case 13 :
case 14 :
-- V_28 ;
break;
case 15 :
break;
default:
F_6 ( V_29 L_3
L_4 , V_27 ) ;
case 12 :
V_28 = 0 ;
break;
}
return V_28 << V_32 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_33 = F_9 ( V_4 ) ;
struct V_9 * V_10 = V_2 -> V_11 ;
T_1 V_12 = V_4 -> V_34 ;
struct V_35 V_36 , V_37 ;
int V_38 , V_39 ;
T_1 V_14 ;
V_38 = 1000000000 / 33333 ;
V_39 = V_38 / 4 ;
F_10 ( V_4 , V_12 , & V_36 , V_38 , V_39 ) ;
if ( V_33 && V_33 -> V_34 ) {
F_10 ( V_33 , V_33 -> V_34 , & V_37 , V_38 , V_39 ) ;
F_11 ( & V_37 , & V_36 , & V_36 , V_40 ) ;
}
V_14 = F_3 ( V_10 -> V_13 ) ;
if ( V_4 -> V_22 & 1 )
V_14 = ( V_14 & ~ V_23 ) ;
else
V_14 = ( V_14 & ~ V_25 ) ;
F_4 ( V_14 , V_10 -> V_13 ) ;
V_14 = F_5 ( V_2 , V_36 . V_41 ) |
F_7 ( V_36 . V_42 ) ;
if ( V_4 -> V_22 & 1 )
F_4 ( V_14 , V_10 -> V_43 ) ;
else
F_4 ( V_14 , V_10 -> V_44 ) ;
V_14 = F_5 ( V_2 , V_36 . V_45 ) |
F_7 ( V_36 . V_46 ) ;
F_4 ( V_14 , V_10 -> V_47 ) ;
}
static int F_12 ( struct V_5 * V_6 )
{
if ( V_6 -> V_48 == V_49 &&
( V_6 -> V_50 == V_51 ||
V_6 -> V_50 == V_20 ) ) {
return 1 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
if ( F_12 ( V_6 ) )
return V_52 ;
return V_53 ;
}
static void F_14 ( struct V_5 * V_6 )
{
int V_54 ;
unsigned long V_55 , V_56 ;
for ( V_54 = 0 ; V_54 < V_57 ; V_54 ++ ) {
V_55 = F_15 ( V_6 , V_54 ) ;
V_56 = F_16 ( V_6 , V_54 ) ;
F_6 ( V_58 L_5 ,
V_55 , V_56 ) ;
}
}
static void F_17 ( struct V_1 * V_2 , int V_59 )
{
struct V_60 * V_61 = & V_2 -> V_61 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_6 ( V_58 L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24 ,
V_59 ,
( unsigned long long ) V_61 -> V_62 ,
( unsigned long long ) F_18 ( V_2 , V_59 ) ,
( unsigned long long ) V_61 -> V_63 ,
( unsigned long long ) F_19 ( V_2 , V_59 ) ,
( unsigned long long ) V_61 -> V_64 ,
( unsigned long long ) F_20 ( V_2 , V_59 ) ,
( unsigned long long ) V_61 -> V_65 ,
( unsigned long long ) V_61 -> V_66 ,
( unsigned long long ) V_61 -> V_67 ,
( unsigned long long ) V_61 -> V_68 ,
( unsigned long long ) V_61 -> V_69 ,
( unsigned long long ) V_61 -> V_70 ,
( unsigned long long ) V_61 -> V_71 ,
( unsigned long long ) V_61 -> V_72 ,
( unsigned long long ) V_61 -> V_73 ,
( unsigned long long ) V_61 -> V_74 ,
( unsigned long long ) V_10 -> V_13 ,
( unsigned long long ) V_10 -> V_44 ,
( unsigned long long ) V_10 -> V_43 ,
( unsigned long long ) V_10 -> V_47 ,
( unsigned long ) V_10 -> V_17 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 -> V_8 ) ;
struct V_9 * V_10 ;
int V_59 = V_2 -> V_75 ;
V_10 = V_2 -> V_11 =
F_22 ( & V_6 -> V_8 , sizeof( * V_10 ) , V_76 ) ;
if ( V_10 == NULL )
return - V_77 ;
V_10 -> V_13 = F_23 ( V_2 , V_59 ) ;
V_10 -> V_44 = F_24 ( V_2 , V_59 ) ;
V_10 -> V_43 = F_25 ( V_2 , V_59 ) ;
V_10 -> V_47 = F_26 ( V_2 , V_59 ) ;
V_10 -> V_17 =
F_3 ( F_27 ( V_2 ) ) & V_78 ;
return 0 ;
}
static void F_28 ( struct V_79 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 -> V_8 ) ;
struct V_1 * V_2 = V_7 -> V_80 [ 0 ] ;
int V_54 ;
T_1 V_81 ;
F_29 ( V_6 , V_82 , & V_81 ) ;
if ( V_81 < 0x80 ) {
V_81 = 0x80 ;
F_30 ( V_6 , V_82 , V_81 ) ;
F_6 ( V_58 L_25
L_26 , F_31 ( V_6 ) , V_81 ) ;
}
for ( V_54 = 0 ; V_54 < V_83 ; V_54 ++ )
F_32 ( V_84 , F_33 ( V_2 , V_54 ) ) ;
for ( V_54 = 0 ; V_54 < V_83 ; V_54 ++ )
F_32 ( V_85 , F_34 ( V_2 , V_54 ) ) ;
V_81 = F_3 ( F_35 ( V_2 ) + 0x28 ) ;
V_81 &= 0xcf ;
V_81 |= 0xc0 ;
F_4 ( V_81 , F_35 ( V_2 ) + 0x28 ) ;
V_81 = F_3 ( F_27 ( V_2 ) ) ;
V_81 &= V_86 ;
if ( V_6 -> V_19 == V_20 )
V_81 |= V_87 ;
F_4 ( V_81 , F_27 ( V_2 ) ) ;
}
static int F_36 ( struct V_79 * V_7 )
{
struct V_19 * V_88 = V_7 -> V_8 ;
struct V_5 * V_6 = F_2 ( V_88 ) ;
unsigned int V_89 = 0 ;
int V_54 , V_90 ;
V_90 = F_37 ( V_6 , 1 << V_91 , V_92 ) ;
if ( V_90 == - V_93 )
F_38 ( V_6 ) ;
if ( V_90 )
return V_90 ;
V_7 -> V_94 = F_39 ( V_6 ) ;
#ifdef F_40
F_14 ( V_6 ) ;
for ( V_54 = 0 ; V_54 < V_95 ; V_54 ++ )
F_6 ( V_58 L_27 , V_54 ,
( unsigned long long ) ( V_7 -> V_94 [ V_54 ] ) ) ;
#endif
for ( V_54 = 0 ; V_54 < V_7 -> V_96 ; V_54 ++ ) {
struct V_1 * V_2 = V_7 -> V_80 [ V_54 ] ;
struct V_60 * V_61 = & V_2 -> V_61 ;
V_61 -> V_62 = F_18 ( V_2 , V_54 ) ;
V_61 -> V_63 = V_61 -> V_97
= F_19 ( V_2 , V_54 ) ;
V_61 -> V_64 = F_20 ( V_2 , V_54 ) ;
F_41 ( V_61 ) ;
V_90 = F_21 ( V_2 ) ;
if ( V_90 )
return V_90 ;
#ifdef F_40
F_17 ( V_2 , V_54 ) ;
#endif
F_42 ( V_2 , L_28 ,
( unsigned long ) V_61 -> V_62 ,
( unsigned long ) V_61 -> V_63 ) ;
F_42 ( V_2 , L_29 ,
( unsigned long ) V_61 -> V_64 ) ;
V_89 |= 1 << V_54 ;
}
if ( ! V_89 ) {
F_43 ( V_88 , L_30 ) ;
return - V_98 ;
}
F_28 ( V_7 ) ;
V_90 = F_44 ( V_6 , V_99 ) ;
if ( V_90 )
return V_90 ;
V_90 = F_45 ( V_6 , V_99 ) ;
return V_90 ;
}
static int F_46 ( struct V_5 * V_6 ,
const struct V_100 * V_101 )
{
static const struct V_102 V_103 = {
. V_104 = V_105 ,
. V_106 = V_107 ,
. V_108 = V_109 ,
. V_110 = & V_111 ,
} ;
struct V_79 * V_7 ;
const struct V_102 * V_112 [] = { & V_103 , NULL } ;
int V_90 ;
F_47 ( & V_6 -> V_8 , V_113 ) ;
V_90 = F_48 ( V_6 ) ;
if ( V_90 )
return V_90 ;
F_6 ( V_114 L_31 ,
V_6 -> V_19 ) ;
V_7 = F_49 ( & V_6 -> V_8 , V_112 , V_83 ) ;
if ( ! V_7 ) {
F_43 ( & V_6 -> V_8 , L_32 ) ;
V_90 = - V_77 ;
goto V_115;
}
V_90 = F_36 ( V_7 ) ;
if ( V_90 ) {
F_43 ( & V_6 -> V_8 , L_33 ) ;
goto V_115;
}
F_50 ( V_6 ) ;
V_90 = F_51 ( V_7 , V_6 -> V_116 , V_117 ,
V_118 , & V_119 ) ;
if ( V_90 )
F_43 ( & V_6 -> V_8 , L_34 ) ;
V_115:
return V_90 ;
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_79 * V_7 = F_53 ( V_6 ) ;
int V_90 ;
V_90 = F_54 ( V_6 ) ;
if ( V_90 )
return V_90 ;
F_28 ( V_7 ) ;
F_55 ( V_7 ) ;
return 0 ;
}
