static const inline struct V_1 * F_1 (
const struct V_2 * V_3 ,
const char * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
if ( ! strcmp ( V_3 -> V_7 [ V_5 ] . V_4 , V_4 ) )
return & V_3 -> V_7 [ V_5 ] ;
}
return NULL ;
}
static struct V_8 * F_2 ( struct V_2 * V_3 ,
unsigned V_9 )
{
struct V_8 * V_10 = V_3 -> V_11 -> V_12 ;
while ( V_9 >= ( V_10 -> V_13 + V_10 -> V_14 ) )
V_10 ++ ;
return V_10 ;
}
static struct V_8 * F_3 (
struct V_2 * V_3 ,
unsigned V_15 )
{
struct V_8 * V_10 = V_3 -> V_11 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_11 -> V_16 ; V_5 ++ , V_10 ++ ) {
if ( V_10 -> V_17 == V_15 )
return V_10 ;
}
return F_4 ( - V_18 ) ;
}
static int F_5 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_6 ;
}
static const char * F_7 ( struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_7 [ V_21 ] . V_4 ;
}
static int F_8 ( struct V_19 * V_20 ,
unsigned V_21 , const unsigned * * V_22 ,
unsigned * V_23 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
if ( V_21 >= V_3 -> V_6 )
return - V_18 ;
* V_22 = V_3 -> V_7 [ V_21 ] . V_22 ;
* V_23 = V_3 -> V_7 [ V_21 ] . V_23 ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 ,
struct V_24 * V_25 ,
struct V_26 * * V_27 , unsigned * V_28 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
const struct V_1 * V_29 ;
struct V_26 * V_30 ;
struct V_24 * V_31 ;
int V_32 = 1 ;
int V_5 ;
V_29 = F_1 ( V_3 , V_25 -> V_4 ) ;
if ( ! V_29 ) {
F_10 ( V_3 -> V_33 , L_1 ,
V_25 -> V_4 ) ;
return - V_18 ;
}
V_32 += V_29 -> V_23 ;
V_30 = F_11 ( V_20 -> V_33 , sizeof( * V_30 ) * V_32 ,
V_34 ) ;
if ( ! V_30 )
return - V_35 ;
* V_27 = V_30 ;
* V_28 = V_32 ;
V_31 = F_12 ( V_25 ) ;
if ( ! V_31 ) {
F_13 ( V_20 -> V_33 , V_30 ) ;
return - V_18 ;
}
V_30 [ 0 ] . type = V_36 ;
V_30 [ 0 ] . V_37 . V_38 . V_39 = V_31 -> V_4 ;
V_30 [ 0 ] . V_37 . V_38 . V_40 = V_25 -> V_4 ;
F_14 ( V_31 ) ;
V_30 ++ ;
for ( V_5 = 0 ; V_5 < V_29 -> V_23 ; V_5 ++ ) {
V_30 [ V_5 ] . type = V_41 ;
V_30 [ V_5 ] . V_37 . V_42 . V_43 =
F_15 ( V_20 , V_29 -> V_22 [ V_5 ] ) ;
V_30 [ V_5 ] . V_37 . V_42 . V_42 = V_29 -> V_37 [ V_5 ] . V_42 ;
V_30 [ V_5 ] . V_37 . V_42 . V_44 = V_29 -> V_37 [ V_5 ] . V_45 ;
}
F_16 ( V_20 -> V_33 , L_2 ,
( * V_27 ) -> V_37 . V_38 . V_39 , ( * V_27 ) -> V_37 . V_38 . V_40 , V_32 ) ;
return 0 ;
}
static void F_17 ( struct V_19 * V_20 ,
struct V_26 * V_27 , unsigned V_28 )
{
}
static int F_18 ( struct V_8 * V_46 , int V_9 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
int V_48 = ( V_9 / 8 ) ;
struct V_49 * V_49 ;
unsigned int V_50 ;
int V_51 , V_52 , V_53 ;
T_1 V_54 ;
if ( V_48 > 3 )
return - V_18 ;
if ( V_46 -> V_55 [ V_48 ] . type & V_56 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_46 -> V_55 [ V_48 ] . type & V_57 )
return V_58 ;
V_49 = ( V_46 -> V_55 [ V_48 ] . type & V_59 )
? V_3 -> V_60 : V_3 -> V_61 ;
V_53 = ( V_46 -> V_55 [ V_48 ] . type & V_62 ) ? 0xf : 0x3 ;
V_51 = V_46 -> V_55 [ V_48 ] . V_63 ;
if ( V_46 -> V_55 [ V_48 ] . type & V_62 ) {
if ( ( V_9 % 8 ) >= 4 )
V_51 += 0x4 ;
V_54 = ( V_9 % 4 ) * 4 ;
} else {
V_54 = ( V_9 % 8 ) * 2 ;
}
V_52 = F_19 ( V_49 , V_51 , & V_50 ) ;
if ( V_52 )
return V_52 ;
return ( ( V_50 >> V_54 ) & V_53 ) ;
}
static int F_20 ( struct V_8 * V_46 , int V_9 , int V_38 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
int V_48 = ( V_9 / 8 ) ;
struct V_49 * V_49 ;
int V_51 , V_52 , V_53 ;
unsigned long V_64 ;
T_1 V_54 ;
T_2 V_37 , V_65 ;
if ( V_48 > 3 )
return - V_18 ;
if ( V_46 -> V_55 [ V_48 ] . type & V_56 ) {
F_10 ( V_3 -> V_33 , L_3 , V_9 ) ;
return - V_18 ;
}
if ( V_46 -> V_55 [ V_48 ] . type & V_57 ) {
if ( V_38 != V_58 ) {
F_10 ( V_3 -> V_33 ,
L_4 , V_9 ) ;
return - V_66 ;
} else {
return 0 ;
}
}
F_16 ( V_3 -> V_33 , L_5 ,
V_46 -> V_17 , V_9 , V_38 ) ;
V_49 = ( V_46 -> V_55 [ V_48 ] . type & V_59 )
? V_3 -> V_60 : V_3 -> V_61 ;
V_53 = ( V_46 -> V_55 [ V_48 ] . type & V_62 ) ? 0xf : 0x3 ;
V_51 = V_46 -> V_55 [ V_48 ] . V_63 ;
if ( V_46 -> V_55 [ V_48 ] . type & V_62 ) {
if ( ( V_9 % 8 ) >= 4 )
V_51 += 0x4 ;
V_54 = ( V_9 % 4 ) * 4 ;
} else {
V_54 = ( V_9 % 8 ) * 2 ;
}
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = ( V_53 << ( V_54 + 16 ) ) ;
V_65 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_38 & V_53 ) << V_54 ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
return V_52 ;
}
static void F_24 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
* V_49 = V_3 -> V_61 ;
* V_51 = V_69 ;
* V_51 += V_46 -> V_17 * V_70 ;
* V_51 += ( V_68 / V_71 ) * 4 ;
* V_54 = V_68 % V_71 ;
}
static void F_25 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 && V_68 < 12 ) {
* V_49 = V_3 -> V_60 ? V_3 -> V_60
: V_46 -> V_72 ;
* V_51 = V_3 -> V_60 ? V_73 : 0 ;
* V_51 += ( ( V_68 / V_74 ) * 4 ) ;
* V_54 = V_68 % V_74 ;
* V_54 *= V_75 ;
} else {
* V_49 = V_3 -> V_72 ? V_3 -> V_72
: V_3 -> V_61 ;
* V_51 = V_3 -> V_72 ? 0 : V_76 ;
* V_51 -= 4 ;
* V_51 += V_46 -> V_17 * V_77 ;
* V_51 += ( ( V_68 / V_74 ) * 4 ) ;
* V_54 = 7 - ( V_68 % V_74 ) ;
* V_54 *= V_75 ;
}
}
static void F_26 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_73 ;
* V_51 += ( ( V_68 / V_74 ) * 4 ) ;
* V_54 = V_68 % V_74 ;
* V_54 *= V_75 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_78 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_77 ;
* V_51 += ( ( V_68 / V_74 ) * 4 ) ;
* V_54 = ( V_68 % V_74 ) ;
* V_54 *= V_75 ;
}
}
static void F_27 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_79 ;
* V_51 += ( ( V_68 / V_80 ) * 4 ) ;
* V_54 = V_68 % V_80 ;
* V_54 *= V_81 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_82 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_83 ;
* V_51 += ( ( V_68 / V_80 ) * 4 ) ;
* V_54 = ( V_68 % V_80 ) ;
* V_54 *= V_81 ;
}
}
static void F_28 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
* V_49 = V_3 -> V_61 ;
* V_51 = V_84 ;
* V_51 += V_46 -> V_17 * V_77 ;
* V_51 += ( ( V_68 / V_74 ) * 4 ) ;
* V_54 = ( V_68 % V_74 ) ;
* V_54 *= V_75 ;
}
static void F_29 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
* V_49 = V_3 -> V_61 ;
* V_51 = V_85 ;
* V_51 += V_46 -> V_17 * V_83 ;
* V_51 += ( ( V_68 / V_80 ) * 4 ) ;
* V_54 = ( V_68 % V_80 ) ;
* V_54 *= V_81 ;
}
static void F_30 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_86 ;
* V_51 += ( ( V_68 / V_74 ) * 4 ) ;
* V_54 = V_68 % V_74 ;
* V_54 *= V_75 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_87 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_77 ;
* V_51 += ( ( V_68 / V_74 ) * 4 ) ;
* V_54 = ( V_68 % V_74 ) ;
* V_54 *= V_75 ;
}
}
static void F_31 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( V_46 -> V_17 == 0 ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_88 ;
* V_51 += ( ( V_68 / V_80 ) * 4 ) ;
* V_54 = V_68 % V_80 ;
* V_54 *= V_81 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_89 ;
* V_51 -= 0x10 ;
* V_51 += V_46 -> V_17 * V_83 ;
* V_51 += ( ( V_68 / V_80 ) * 4 ) ;
* V_54 = ( V_68 % V_80 ) ;
* V_54 *= V_81 ;
}
}
static int F_32 ( struct V_8 * V_46 ,
int V_68 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_90 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 ;
T_2 V_37 ;
T_1 V_54 ;
V_11 -> V_91 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
V_52 = F_19 ( V_49 , V_51 , & V_37 ) ;
if ( V_52 )
return V_52 ;
V_37 >>= V_54 ;
V_37 &= ( 1 << V_81 ) - 1 ;
return V_92 [ V_37 ] ;
}
static int F_33 ( struct V_8 * V_46 ,
int V_68 , int V_93 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_90 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
unsigned long V_64 ;
int V_51 , V_52 , V_5 ;
T_2 V_37 , V_65 ;
T_1 V_54 ;
V_11 -> V_91 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
V_52 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_34 ( V_92 ) ; V_5 ++ ) {
if ( V_92 [ V_5 ] == V_93 ) {
V_52 = V_5 ;
break;
}
}
if ( V_52 < 0 ) {
F_10 ( V_3 -> V_33 , L_6 ,
V_93 ) ;
return V_52 ;
}
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = ( ( 1 << V_81 ) - 1 ) << ( V_54 + 16 ) ;
V_65 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_52 << V_54 ) ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
return V_52 ;
}
static int F_35 ( struct V_8 * V_46 , int V_68 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_90 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 ;
T_1 V_54 ;
T_2 V_37 ;
if ( V_11 -> type == V_94 )
return V_95 ;
V_11 -> V_96 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
V_52 = F_19 ( V_49 , V_51 , & V_37 ) ;
if ( V_52 )
return V_52 ;
switch ( V_11 -> type ) {
case V_97 :
return ! ( V_37 & F_36 ( V_54 ) )
? V_98
: V_95 ;
case V_99 :
case V_100 :
case V_101 :
V_37 >>= V_54 ;
V_37 &= ( 1 << V_75 ) - 1 ;
switch ( V_37 ) {
case 0 :
return V_95 ;
case 1 :
return V_102 ;
case 2 :
return V_103 ;
case 3 :
return V_104 ;
}
F_10 ( V_3 -> V_33 , L_7 ) ;
return - V_105 ;
default:
F_10 ( V_3 -> V_33 , L_8 ) ;
return - V_18 ;
} ;
}
static int F_37 ( struct V_8 * V_46 ,
int V_68 , int V_106 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_90 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 ;
unsigned long V_64 ;
T_1 V_54 ;
T_2 V_37 , V_65 ;
F_16 ( V_3 -> V_33 , L_9 ,
V_46 -> V_17 , V_68 , V_106 ) ;
if ( V_11 -> type == V_94 )
return V_106 ? - V_18 : 0 ;
V_11 -> V_96 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
switch ( V_11 -> type ) {
case V_97 :
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_36 ( V_54 + 16 ) ;
if ( V_106 == V_95 )
V_37 |= F_36 ( V_54 ) ;
V_52 = F_38 ( V_49 , V_51 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
break;
case V_99 :
case V_100 :
case V_101 :
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = ( ( 1 << V_75 ) - 1 ) << ( V_54 + 16 ) ;
V_65 = V_37 | ( V_37 >> 16 ) ;
switch ( V_106 ) {
case V_95 :
break;
case V_102 :
V_37 |= ( 1 << V_54 ) ;
break;
case V_103 :
V_37 |= ( 2 << V_54 ) ;
break;
case V_104 :
V_37 |= ( 3 << V_54 ) ;
break;
default:
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_10 ( V_3 -> V_33 , L_10 ,
V_106 ) ;
return - V_18 ;
}
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
break;
default:
F_10 ( V_3 -> V_33 , L_8 ) ;
return - V_18 ;
}
return V_52 ;
}
static int F_39 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_107 ;
}
static const char * F_40 ( struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_108 [ V_21 ] . V_4 ;
}
static int F_41 ( struct V_19 * V_20 ,
unsigned V_21 , const char * const * * V_7 ,
unsigned * const V_109 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
* V_7 = V_3 -> V_108 [ V_21 ] . V_7 ;
* V_109 = V_3 -> V_108 [ V_21 ] . V_6 ;
return 0 ;
}
static int F_42 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_40 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
const unsigned int * V_22 = V_3 -> V_7 [ V_40 ] . V_22 ;
const struct V_110 * V_37 = V_3 -> V_7 [ V_40 ] . V_37 ;
struct V_8 * V_46 ;
int V_111 , V_52 = 0 ;
F_16 ( V_3 -> V_33 , L_11 ,
V_3 -> V_108 [ V_21 ] . V_4 , V_3 -> V_7 [ V_40 ] . V_4 ) ;
for ( V_111 = 0 ; V_111 < V_3 -> V_7 [ V_40 ] . V_23 ; V_111 ++ ) {
V_46 = F_2 ( V_3 , V_22 [ V_111 ] ) ;
V_52 = F_20 ( V_46 , V_22 [ V_111 ] - V_46 -> V_13 ,
V_37 [ V_111 ] . V_112 ) ;
if ( V_52 )
break;
}
if ( V_52 ) {
for ( V_111 -- ; V_111 >= 0 ; V_111 -- )
F_20 ( V_46 , V_22 [ V_111 ] - V_46 -> V_13 , 0 ) ;
return V_52 ;
}
return 0 ;
}
static int F_43 ( struct V_113 * V_114 ,
int V_9 , bool V_115 )
{
struct V_8 * V_46 ;
int V_52 ;
unsigned long V_64 ;
T_2 V_37 ;
V_46 = F_44 ( V_114 ) ;
V_52 = F_20 ( V_46 , V_9 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
F_45 ( V_46 -> V_116 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_46 ( V_46 -> V_117 + V_118 ) ;
if ( ! V_115 )
V_37 |= F_36 ( V_9 ) ;
else
V_37 &= ~ F_36 ( V_9 ) ;
F_47 ( V_37 , V_46 -> V_117 + V_118 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_48 ( V_46 -> V_116 ) ;
return 0 ;
}
static int F_49 ( struct V_19 * V_20 ,
struct V_119 * V_120 ,
unsigned V_63 , bool V_115 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_113 * V_114 ;
int V_9 ;
V_114 = V_120 -> V_121 ;
V_9 = V_63 - V_114 -> V_122 ;
F_16 ( V_3 -> V_33 , L_12 ,
V_63 , V_120 -> V_4 , V_9 , V_115 ? L_13 : L_14 ) ;
return F_43 ( V_114 , V_63 - V_114 -> V_122 ,
V_115 ) ;
}
static bool F_50 ( struct V_90 * V_11 ,
enum V_123 V_106 )
{
switch ( V_11 -> type ) {
case V_97 :
return ( V_106 == V_98 ||
V_106 == V_95 ) ;
case V_94 :
return V_106 ? false : true ;
case V_99 :
case V_100 :
case V_101 :
return ( V_106 != V_98 ) ;
}
return false ;
}
static int F_51 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_42 , unsigned V_44 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_123 V_124 ;
T_3 V_125 ;
int V_5 ;
int V_126 ;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ ) {
V_124 = F_52 ( V_42 [ V_5 ] ) ;
V_125 = F_53 ( V_42 [ V_5 ] ) ;
switch ( V_124 ) {
case V_95 :
V_126 = F_37 ( V_46 , V_9 - V_46 -> V_13 ,
V_124 ) ;
if ( V_126 )
return V_126 ;
break;
case V_102 :
case V_103 :
case V_98 :
case V_104 :
if ( ! F_50 ( V_3 -> V_11 , V_124 ) )
return - V_66 ;
if ( ! V_125 )
return - V_18 ;
V_126 = F_37 ( V_46 , V_9 - V_46 -> V_13 ,
V_124 ) ;
if ( V_126 )
return V_126 ;
break;
case V_127 :
F_54 ( & V_46 -> V_113 ,
V_9 - V_46 -> V_13 , V_125 ) ;
V_126 = F_43 ( & V_46 -> V_113 ,
V_9 - V_46 -> V_13 , false ) ;
if ( V_126 )
return V_126 ;
break;
case V_128 :
if ( ! V_3 -> V_11 -> V_91 )
return - V_66 ;
V_126 = F_33 ( V_46 ,
V_9 - V_46 -> V_13 , V_125 ) ;
if ( V_126 < 0 )
return V_126 ;
break;
default:
return - V_66 ;
break;
}
}
return 0 ;
}
static int F_55 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_129 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_123 V_124 = F_52 ( * V_129 ) ;
T_3 V_125 ;
int V_126 ;
switch ( V_124 ) {
case V_95 :
if ( F_35 ( V_46 , V_9 - V_46 -> V_13 ) != V_124 )
return - V_18 ;
V_125 = 0 ;
break;
case V_102 :
case V_103 :
case V_98 :
case V_104 :
if ( ! F_50 ( V_3 -> V_11 , V_124 ) )
return - V_66 ;
if ( F_35 ( V_46 , V_9 - V_46 -> V_13 ) != V_124 )
return - V_18 ;
V_125 = 1 ;
break;
case V_127 :
V_126 = F_18 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_126 != V_58 )
return - V_18 ;
V_126 = F_56 ( & V_46 -> V_113 , V_9 - V_46 -> V_13 ) ;
if ( V_126 < 0 )
return V_126 ;
V_125 = V_126 ? 1 : 0 ;
break;
case V_128 :
if ( ! V_3 -> V_11 -> V_91 )
return - V_66 ;
V_126 = F_32 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_126 < 0 )
return V_126 ;
V_125 = V_126 ;
break;
default:
return - V_66 ;
break;
}
* V_129 = F_57 ( V_124 , V_125 ) ;
return 0 ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_24 * V_130 ;
F_59 (np, child) {
if ( F_60 ( V_131 , V_130 ) )
continue;
V_3 -> V_107 ++ ;
V_3 -> V_6 += F_61 ( V_130 ) ;
}
}
static int F_62 ( struct V_24 * V_25 ,
struct V_1 * V_29 ,
struct V_2 * V_3 ,
T_2 V_132 )
{
struct V_8 * V_46 ;
int V_133 ;
const T_4 * V_134 ;
int V_15 ;
int V_5 , V_135 ;
int V_52 ;
F_16 ( V_3 -> V_33 , L_15 , V_132 , V_25 -> V_4 ) ;
V_29 -> V_4 = V_25 -> V_4 ;
V_134 = F_63 ( V_25 , L_16 , & V_133 ) ;
V_133 /= sizeof( * V_134 ) ;
if ( ! V_133 || V_133 % 4 ) {
F_10 ( V_3 -> V_33 , L_17 ) ;
return - V_18 ;
}
V_29 -> V_23 = V_133 / 4 ;
V_29 -> V_22 = F_11 ( V_3 -> V_33 , V_29 -> V_23 * sizeof( unsigned int ) ,
V_34 ) ;
V_29 -> V_37 = F_11 ( V_3 -> V_33 , V_29 -> V_23 *
sizeof( struct V_110 ) ,
V_34 ) ;
if ( ! V_29 -> V_22 || ! V_29 -> V_37 )
return - V_35 ;
for ( V_5 = 0 , V_135 = 0 ; V_5 < V_133 ; V_5 += 4 , V_135 ++ ) {
const T_4 * V_136 ;
struct V_24 * V_137 ;
V_15 = F_64 ( * V_134 ++ ) ;
V_46 = F_3 ( V_3 , V_15 ) ;
if ( F_65 ( V_46 ) )
return F_66 ( V_46 ) ;
V_29 -> V_22 [ V_135 ] = V_46 -> V_13 + F_64 ( * V_134 ++ ) ;
V_29 -> V_37 [ V_135 ] . V_112 = F_64 ( * V_134 ++ ) ;
V_136 = V_134 ++ ;
if ( ! V_136 )
return - V_18 ;
V_137 = F_67 ( F_68 ( V_136 ) ) ;
V_52 = F_69 ( V_137 , NULL ,
& V_29 -> V_37 [ V_135 ] . V_42 , & V_29 -> V_37 [ V_135 ] . V_45 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_70 ( struct V_24 * V_25 ,
struct V_2 * V_3 ,
T_2 V_132 )
{
struct V_24 * V_130 ;
struct V_138 * V_112 ;
struct V_1 * V_29 ;
int V_52 ;
static T_2 V_139 ;
T_2 V_5 = 0 ;
F_16 ( V_3 -> V_33 , L_18 , V_132 , V_25 -> V_4 ) ;
V_112 = & V_3 -> V_108 [ V_132 ] ;
V_112 -> V_4 = V_25 -> V_4 ;
V_112 -> V_6 = F_61 ( V_25 ) ;
if ( V_112 -> V_6 <= 0 )
return 0 ;
V_112 -> V_7 = F_11 ( V_3 -> V_33 ,
V_112 -> V_6 * sizeof( char * ) , V_34 ) ;
if ( ! V_112 -> V_7 )
return - V_35 ;
F_59 (np, child) {
V_112 -> V_7 [ V_5 ] = V_130 -> V_4 ;
V_29 = & V_3 -> V_7 [ V_139 ++ ] ;
V_52 = F_62 ( V_130 , V_29 , V_3 , V_5 ++ ) ;
if ( V_52 ) {
F_14 ( V_130 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_71 ( struct V_140 * V_141 ,
struct V_2 * V_3 )
{
struct V_142 * V_33 = & V_141 -> V_33 ;
struct V_24 * V_25 = V_33 -> V_143 ;
struct V_24 * V_130 ;
int V_52 ;
int V_5 ;
F_58 ( V_3 , V_25 ) ;
F_16 ( & V_141 -> V_33 , L_19 , V_3 -> V_107 ) ;
F_16 ( & V_141 -> V_33 , L_20 , V_3 -> V_6 ) ;
V_3 -> V_108 = F_11 ( V_33 , V_3 -> V_107 *
sizeof( struct V_138 ) ,
V_34 ) ;
if ( ! V_3 -> V_108 ) {
F_10 ( V_33 , L_21 ) ;
return - V_18 ;
}
V_3 -> V_7 = F_11 ( V_33 , V_3 -> V_6 *
sizeof( struct V_1 ) ,
V_34 ) ;
if ( ! V_3 -> V_7 ) {
F_10 ( V_33 , L_22 ) ;
return - V_18 ;
}
V_5 = 0 ;
F_59 (np, child) {
if ( F_60 ( V_131 , V_130 ) )
continue;
V_52 = F_70 ( V_130 , V_3 , V_5 ++ ) ;
if ( V_52 ) {
F_10 ( & V_141 -> V_33 , L_23 ) ;
F_14 ( V_130 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_72 ( struct V_140 * V_141 ,
struct V_2 * V_3 )
{
struct V_144 * V_145 = & V_3 -> V_146 ;
struct V_147 * V_148 , * V_149 ;
struct V_8 * V_150 ;
int V_9 , V_46 , V_52 ;
int V_151 ;
V_145 -> V_4 = L_24 ;
V_145 -> V_152 = V_153 ;
V_145 -> V_154 = & V_155 ;
V_145 -> V_156 = & V_157 ;
V_145 -> V_158 = & V_159 ;
V_148 = F_11 ( & V_141 -> V_33 , sizeof( * V_148 ) *
V_3 -> V_11 -> V_14 , V_34 ) ;
if ( ! V_148 ) {
F_10 ( & V_141 -> V_33 , L_25 ) ;
return - V_35 ;
}
V_145 -> V_22 = V_148 ;
V_145 -> V_23 = V_3 -> V_11 -> V_14 ;
V_149 = V_148 ;
for ( V_46 = 0 , V_151 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; V_46 ++ ) {
V_150 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
for ( V_9 = 0 ; V_9 < V_150 -> V_14 ; V_9 ++ , V_151 ++ ) {
V_149 -> V_160 = V_151 ;
V_149 -> V_4 = F_73 ( V_34 , L_26 ,
V_150 -> V_4 , V_9 ) ;
V_149 ++ ;
}
}
V_52 = F_71 ( V_141 , V_3 ) ;
if ( V_52 )
return V_52 ;
V_3 -> V_161 = F_74 ( V_145 , & V_141 -> V_33 , V_3 ) ;
if ( F_65 ( V_3 -> V_161 ) ) {
F_10 ( & V_141 -> V_33 , L_27 ) ;
return F_66 ( V_3 -> V_161 ) ;
}
for ( V_46 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; ++ V_46 ) {
V_150 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
V_150 -> V_162 . V_4 = V_150 -> V_4 ;
V_150 -> V_162 . V_163 = V_46 ;
V_150 -> V_162 . V_13 = V_150 -> V_13 ;
V_150 -> V_162 . V_122 = V_150 -> V_113 . V_122 ;
V_150 -> V_162 . V_23 = V_150 -> V_113 . V_164 ;
V_150 -> V_162 . V_121 = & V_150 -> V_113 ;
F_75 ( V_3 -> V_161 , & V_150 -> V_162 ) ;
}
return 0 ;
}
static void F_54 ( struct V_113 * V_121 , unsigned V_63 , int V_165 )
{
struct V_8 * V_46 = F_44 ( V_121 ) ;
void T_5 * V_51 = V_46 -> V_117 + V_166 ;
unsigned long V_64 ;
T_2 V_37 ;
F_45 ( V_46 -> V_116 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_76 ( V_51 ) ;
V_37 &= ~ F_36 ( V_63 ) ;
if ( V_165 )
V_37 |= F_36 ( V_63 ) ;
F_77 ( V_37 , V_51 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_48 ( V_46 -> V_116 ) ;
}
static int F_56 ( struct V_113 * V_121 , unsigned V_63 )
{
struct V_8 * V_46 = F_44 ( V_121 ) ;
T_2 V_37 ;
F_45 ( V_46 -> V_116 ) ;
V_37 = F_76 ( V_46 -> V_117 + V_167 ) ;
F_48 ( V_46 -> V_116 ) ;
V_37 >>= V_63 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_78 ( struct V_113 * V_121 , unsigned V_63 )
{
return F_79 ( V_121 -> V_122 + V_63 ) ;
}
static int F_80 ( struct V_113 * V_121 ,
unsigned V_63 , int V_165 )
{
F_54 ( V_121 , V_63 , V_165 ) ;
return F_81 ( V_121 -> V_122 + V_63 ) ;
}
static int F_82 ( struct V_113 * V_121 , unsigned V_63 )
{
struct V_8 * V_46 = F_44 ( V_121 ) ;
unsigned int V_168 ;
if ( ! V_46 -> V_169 )
return - V_170 ;
V_168 = F_83 ( V_46 -> V_169 , V_63 ) ;
return ( V_168 ) ? : - V_170 ;
}
static void F_84 ( struct V_171 * V_172 )
{
struct V_173 * V_114 = F_85 ( V_172 ) ;
struct V_8 * V_46 = F_86 ( V_172 ) ;
T_2 V_174 ;
F_16 ( V_46 -> V_47 -> V_33 , L_28 , V_46 -> V_4 ) ;
F_87 ( V_114 , V_172 ) ;
V_174 = F_46 ( V_46 -> V_117 + V_175 ) ;
while ( V_174 ) {
unsigned int V_176 , V_168 ;
V_176 = F_88 ( V_174 ) ;
V_174 &= ~ F_36 ( V_176 ) ;
V_168 = F_89 ( V_46 -> V_169 , V_176 ) ;
if ( ! V_168 ) {
F_10 ( V_46 -> V_47 -> V_33 , L_29 , V_176 ) ;
continue;
}
F_16 ( V_46 -> V_47 -> V_33 , L_30 , V_176 ) ;
if ( V_46 -> V_177 & F_36 ( V_176 ) ) {
T_2 V_37 , V_178 , V_179 ;
unsigned long V_64 ;
V_37 = F_46 ( V_46 -> V_117 + V_167 ) ;
do {
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_179 = F_46 ( V_46 -> V_117 +
V_180 ) ;
if ( V_37 & F_36 ( V_176 ) )
V_179 &= ~ F_36 ( V_176 ) ;
else
V_179 |= F_36 ( V_176 ) ;
F_77 ( V_179 ,
V_46 -> V_117 + V_180 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
V_178 = V_37 ;
V_37 = F_46 ( V_46 -> V_117 +
V_167 ) ;
} while ( ( V_37 & F_36 ( V_176 ) ) != ( V_178 & F_36 ( V_176 ) ) );
}
F_90 ( V_168 ) ;
}
F_91 ( V_114 , V_172 ) ;
}
static int F_92 ( struct V_181 * V_182 , unsigned int type )
{
struct V_183 * V_121 = F_93 ( V_182 ) ;
struct V_8 * V_46 = V_121 -> V_184 ;
T_2 V_53 = F_36 ( V_182 -> V_185 ) ;
T_2 V_179 ;
T_2 V_186 ;
T_2 V_37 ;
unsigned long V_64 ;
int V_52 ;
V_52 = F_20 ( V_46 , V_182 -> V_185 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
F_45 ( V_46 -> V_116 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_46 ( V_46 -> V_117 + V_118 ) ;
V_37 &= ~ V_53 ;
F_47 ( V_37 , V_46 -> V_117 + V_118 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
if ( type & V_187 )
F_94 ( V_182 , V_188 ) ;
else
F_94 ( V_182 , V_189 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
F_95 ( V_121 ) ;
V_186 = F_46 ( V_121 -> V_117 + V_190 ) ;
V_179 = F_46 ( V_121 -> V_117 + V_180 ) ;
switch ( type ) {
case V_187 :
V_46 -> V_177 |= V_53 ;
V_186 |= V_53 ;
V_37 = F_76 ( V_46 -> V_117 + V_167 ) ;
if ( V_37 & V_53 )
V_179 &= ~ V_53 ;
else
V_179 |= V_53 ;
break;
case V_191 :
V_46 -> V_177 &= ~ V_53 ;
V_186 |= V_53 ;
V_179 |= V_53 ;
break;
case V_192 :
V_46 -> V_177 &= ~ V_53 ;
V_186 |= V_53 ;
V_179 &= ~ V_53 ;
break;
case V_193 :
V_46 -> V_177 &= ~ V_53 ;
V_186 &= ~ V_53 ;
V_179 |= V_53 ;
break;
case V_194 :
V_46 -> V_177 &= ~ V_53 ;
V_186 &= ~ V_53 ;
V_179 &= ~ V_53 ;
break;
default:
F_96 ( V_121 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_48 ( V_46 -> V_116 ) ;
return - V_18 ;
}
F_47 ( V_186 , V_121 -> V_117 + V_190 ) ;
F_47 ( V_179 , V_121 -> V_117 + V_180 ) ;
F_96 ( V_121 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_48 ( V_46 -> V_116 ) ;
return 0 ;
}
static void F_97 ( struct V_181 * V_182 )
{
struct V_183 * V_121 = F_93 ( V_182 ) ;
struct V_8 * V_46 = V_121 -> V_184 ;
F_45 ( V_46 -> V_116 ) ;
V_46 -> V_195 = F_98 ( V_121 , V_196 ) ;
F_99 ( V_121 , ~ V_121 -> V_197 , V_196 ) ;
F_48 ( V_46 -> V_116 ) ;
}
static void F_100 ( struct V_181 * V_182 )
{
struct V_183 * V_121 = F_93 ( V_182 ) ;
struct V_8 * V_46 = V_121 -> V_184 ;
F_45 ( V_46 -> V_116 ) ;
F_99 ( V_121 , V_46 -> V_195 , V_196 ) ;
F_48 ( V_46 -> V_116 ) ;
}
static void F_101 ( struct V_181 * V_182 )
{
struct V_183 * V_121 = F_93 ( V_182 ) ;
struct V_8 * V_46 = V_121 -> V_184 ;
F_45 ( V_46 -> V_116 ) ;
F_102 ( V_182 ) ;
}
void F_103 ( struct V_181 * V_182 )
{
struct V_183 * V_121 = F_93 ( V_182 ) ;
struct V_8 * V_46 = V_121 -> V_184 ;
F_104 ( V_182 ) ;
F_48 ( V_46 -> V_116 ) ;
}
static int F_105 ( struct V_140 * V_141 ,
struct V_2 * V_3 )
{
struct V_90 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
unsigned int V_198 = V_199 | V_200 | V_201 ;
struct V_183 * V_121 ;
int V_52 ;
int V_5 , V_135 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_202 ) {
F_106 ( & V_141 -> V_33 , L_31 ,
V_46 -> V_4 ) ;
continue;
}
V_52 = F_45 ( V_46 -> V_116 ) ;
if ( V_52 ) {
F_10 ( & V_141 -> V_33 , L_32 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_169 = F_107 ( V_46 -> V_143 , 32 ,
& V_203 , NULL ) ;
if ( ! V_46 -> V_169 ) {
F_106 ( & V_141 -> V_33 , L_33 ,
V_46 -> V_4 ) ;
F_48 ( V_46 -> V_116 ) ;
continue;
}
V_52 = F_108 ( V_46 -> V_169 , 32 , 1 ,
L_34 , V_189 ,
V_198 , 0 , V_204 ) ;
if ( V_52 ) {
F_10 ( & V_141 -> V_33 , L_35 ,
V_46 -> V_4 ) ;
F_109 ( V_46 -> V_169 ) ;
F_48 ( V_46 -> V_116 ) ;
continue;
}
F_47 ( 0xffffffff , V_46 -> V_117 + V_196 ) ;
F_47 ( 0xffffffff , V_46 -> V_117 + V_205 ) ;
V_121 = F_110 ( V_46 -> V_169 , 0 ) ;
V_121 -> V_117 = V_46 -> V_117 ;
V_121 -> V_184 = V_46 ;
V_121 -> V_206 [ 0 ] . V_207 . V_53 = V_196 ;
V_121 -> V_206 [ 0 ] . V_207 . V_208 = V_209 ;
V_121 -> V_206 [ 0 ] . V_114 . V_210 = V_211 ;
V_121 -> V_206 [ 0 ] . V_114 . V_212 = F_103 ;
V_121 -> V_206 [ 0 ] . V_114 . V_213 =
F_101 ;
V_121 -> V_206 [ 0 ] . V_114 . V_214 = V_215 ;
V_121 -> V_206 [ 0 ] . V_114 . V_216 = F_97 ;
V_121 -> V_206 [ 0 ] . V_114 . V_217 = F_100 ;
V_121 -> V_206 [ 0 ] . V_114 . V_218 = F_92 ;
V_121 -> V_219 = F_111 ( V_46 -> V_14 ) ;
F_112 ( V_46 -> V_176 ,
F_84 , V_46 ) ;
for ( V_135 = 0 ; V_135 < 32 ; V_135 ++ )
F_83 ( V_46 -> V_169 , V_135 ) ;
F_48 ( V_46 -> V_116 ) ;
}
return 0 ;
}
static int F_113 ( struct V_140 * V_141 ,
struct V_2 * V_3 )
{
struct V_90 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
struct V_113 * V_121 ;
int V_52 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_202 ) {
F_106 ( & V_141 -> V_33 , L_31 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_113 = V_220 ;
V_121 = & V_46 -> V_113 ;
V_121 -> V_122 = V_46 -> V_13 ;
V_121 -> V_164 = V_46 -> V_14 ;
V_121 -> V_31 = & V_141 -> V_33 ;
V_121 -> V_143 = V_46 -> V_143 ;
V_121 -> V_221 = V_46 -> V_4 ;
V_52 = F_114 ( V_121 , V_46 ) ;
if ( V_52 ) {
F_10 ( & V_141 -> V_33 , L_36 ,
V_121 -> V_221 , V_52 ) ;
goto V_222;
}
}
F_105 ( V_141 , V_3 ) ;
return 0 ;
V_222:
for ( -- V_5 , -- V_46 ; V_5 >= 0 ; -- V_5 , -- V_46 ) {
if ( ! V_46 -> V_202 )
continue;
F_115 ( & V_46 -> V_113 ) ;
}
return V_52 ;
}
static int F_116 ( struct V_140 * V_141 ,
struct V_2 * V_3 )
{
struct V_90 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_202 )
continue;
F_115 ( & V_46 -> V_113 ) ;
}
return 0 ;
}
static int F_117 ( struct V_8 * V_46 ,
struct V_2 * V_3 )
{
struct V_223 V_224 ;
void T_5 * V_122 ;
if ( F_118 ( V_46 -> V_143 , 0 , & V_224 ) ) {
F_10 ( V_3 -> V_33 , L_37 ) ;
return - V_225 ;
}
V_46 -> V_117 = F_119 ( V_3 -> V_33 , & V_224 ) ;
if ( F_65 ( V_46 -> V_117 ) )
return F_66 ( V_46 -> V_117 ) ;
if ( F_120 ( V_46 -> V_143 ,
L_38 ) ) {
struct V_24 * V_226 ;
V_226 = F_121 ( V_46 -> V_143 -> V_31 ,
L_39 , 0 ) ;
if ( ! V_226 ) {
if ( F_118 ( V_46 -> V_143 , 1 , & V_224 ) ) {
F_10 ( V_3 -> V_33 , L_37 ) ;
return - V_225 ;
}
V_122 = F_119 ( V_3 -> V_33 , & V_224 ) ;
if ( F_65 ( V_122 ) )
return F_66 ( V_122 ) ;
V_227 . V_228 =
F_122 ( & V_224 ) - 4 ;
V_227 . V_4 =
L_40 ;
V_46 -> V_72 = F_123 ( V_3 -> V_33 ,
V_122 ,
& V_227 ) ;
}
}
V_46 -> V_176 = F_124 ( V_46 -> V_143 , 0 ) ;
V_46 -> V_116 = F_125 ( V_46 -> V_143 , 0 ) ;
if ( F_65 ( V_46 -> V_116 ) )
return F_66 ( V_46 -> V_116 ) ;
return F_126 ( V_46 -> V_116 ) ;
}
static struct V_90 * F_127 (
struct V_2 * V_182 ,
struct V_140 * V_141 )
{
const struct V_229 * V_230 ;
struct V_24 * V_226 = V_141 -> V_33 . V_143 ;
struct V_24 * V_25 ;
struct V_90 * V_11 ;
struct V_8 * V_46 ;
int V_231 , V_232 , V_5 , V_135 ;
V_230 = F_60 ( V_233 , V_226 ) ;
V_11 = (struct V_90 * ) V_230 -> V_37 ;
F_59 (node, np) {
if ( ! F_128 ( V_25 , L_41 , NULL ) )
continue;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! strcmp ( V_46 -> V_4 , V_25 -> V_4 ) ) {
V_46 -> V_143 = V_25 ;
if ( ! F_117 ( V_46 , V_182 ) )
V_46 -> V_202 = true ;
break;
}
}
}
V_231 = V_11 -> V_234 ;
V_232 = V_11 -> V_235 ;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
int V_236 = 0 ;
F_129 ( & V_46 -> V_67 ) ;
V_46 -> V_47 = V_182 ;
V_46 -> V_13 = V_11 -> V_14 ;
V_11 -> V_14 += V_46 -> V_14 ;
for ( V_135 = 0 ; V_135 < 4 ; V_135 ++ ) {
struct V_237 * V_238 = & V_46 -> V_55 [ V_135 ] ;
int V_239 ;
if ( V_236 >= V_46 -> V_14 )
break;
if ( V_238 -> V_63 >= 0 ) {
if ( V_238 -> type & V_59 )
V_232 = V_238 -> V_63 ;
else
V_231 = V_238 -> V_63 ;
} else {
V_238 -> V_63 = ( V_238 -> type & V_59 ) ?
V_232 : V_231 ;
}
F_16 ( V_182 -> V_33 , L_42 ,
V_5 , V_135 , V_238 -> V_63 ) ;
V_239 = ( V_238 -> type & V_62 ) ? 8 : 4 ;
if ( V_238 -> type & V_59 )
V_232 += V_239 ;
else
V_231 += V_239 ;
V_236 += 8 ;
}
}
return V_11 ;
}
static int T_6 F_130 ( struct V_142 * V_33 )
{
struct V_2 * V_3 = F_131 ( V_33 ) ;
int V_52 = F_132 ( V_3 -> V_161 ) ;
if ( V_52 )
return V_52 ;
if ( V_3 -> V_11 -> type == V_100 ) {
V_52 = F_19 ( V_3 -> V_61 , V_240 ,
& V_241 ) ;
if ( V_52 ) {
F_133 ( V_3 -> V_161 ) ;
return V_52 ;
}
}
return 0 ;
}
static int T_6 F_134 ( struct V_142 * V_33 )
{
struct V_2 * V_3 = F_131 ( V_33 ) ;
int V_52 = F_38 ( V_3 -> V_61 , V_240 ,
V_241 |
V_242 ) ;
if ( V_52 )
return V_52 ;
return F_133 ( V_3 -> V_161 ) ;
}
static int F_135 ( struct V_140 * V_141 )
{
struct V_2 * V_3 ;
struct V_142 * V_33 = & V_141 -> V_33 ;
struct V_90 * V_11 ;
struct V_24 * V_25 = V_141 -> V_33 . V_143 , * V_226 ;
struct V_223 * V_224 ;
void T_5 * V_122 ;
int V_52 ;
if ( ! V_33 -> V_143 ) {
F_10 ( V_33 , L_43 ) ;
return - V_243 ;
}
V_3 = F_11 ( V_33 , sizeof( struct V_2 ) , V_34 ) ;
if ( ! V_3 )
return - V_35 ;
V_3 -> V_33 = V_33 ;
V_11 = F_127 ( V_3 , V_141 ) ;
if ( ! V_11 ) {
F_10 ( V_33 , L_44 ) ;
return - V_18 ;
}
V_3 -> V_11 = V_11 ;
V_226 = F_121 ( V_25 , L_45 , 0 ) ;
if ( V_226 ) {
V_3 -> V_61 = F_136 ( V_226 ) ;
if ( F_65 ( V_3 -> V_61 ) )
return F_66 ( V_3 -> V_61 ) ;
} else {
V_224 = F_137 ( V_141 , V_244 , 0 ) ;
V_122 = F_119 ( & V_141 -> V_33 , V_224 ) ;
if ( F_65 ( V_122 ) )
return F_66 ( V_122 ) ;
V_227 . V_228 = F_122 ( V_224 ) - 4 ;
V_227 . V_4 = L_46 ;
V_3 -> V_61 = F_123 ( & V_141 -> V_33 , V_122 ,
& V_227 ) ;
V_3 -> V_245 = F_122 ( V_224 ) ;
if ( V_11 -> type == V_99 && V_3 -> V_245 < 0x200 ) {
V_224 = F_137 ( V_141 , V_244 , 1 ) ;
V_122 = F_119 ( & V_141 -> V_33 , V_224 ) ;
if ( F_65 ( V_122 ) )
return F_66 ( V_122 ) ;
V_227 . V_228 =
F_122 ( V_224 ) - 4 ;
V_227 . V_4 = L_47 ;
V_3 -> V_72 = F_123 ( & V_141 -> V_33 ,
V_122 ,
& V_227 ) ;
}
}
V_226 = F_121 ( V_25 , L_39 , 0 ) ;
if ( V_226 ) {
V_3 -> V_60 = F_136 ( V_226 ) ;
if ( F_65 ( V_3 -> V_60 ) )
return F_66 ( V_3 -> V_60 ) ;
}
V_52 = F_113 ( V_141 , V_3 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_72 ( V_141 , V_3 ) ;
if ( V_52 ) {
F_116 ( V_141 , V_3 ) ;
return V_52 ;
}
F_138 ( V_141 , V_3 ) ;
return 0 ;
}
static int T_7 F_139 ( void )
{
return F_140 ( & V_246 ) ;
}
