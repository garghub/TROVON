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
static void F_32 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
if ( ( V_46 -> V_17 == 0 ) || ( V_46 -> V_17 == 1 ) ) {
* V_49 = V_3 -> V_60 ;
* V_51 = V_90 ;
* V_51 += V_46 -> V_17 * V_77 ;
* V_51 += ( ( V_68 / V_74 ) * 4 ) ;
* V_54 = V_68 % V_74 ;
* V_54 *= V_75 ;
} else {
* V_49 = V_3 -> V_61 ;
* V_51 = V_91 ;
* V_51 -= 0x20 ;
* V_51 += V_46 -> V_17 * V_77 ;
* V_51 += ( ( V_68 / V_74 ) * 4 ) ;
* V_54 = ( V_68 % V_74 ) ;
* V_54 *= V_75 ;
}
}
static void F_33 ( struct V_8 * V_46 ,
int V_68 , struct V_49 * * V_49 ,
int * V_51 , T_1 * V_54 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
int V_92 = ( V_68 / 8 ) ;
if ( ( V_46 -> V_17 == 0 ) || ( V_46 -> V_17 == 1 ) )
* V_49 = V_3 -> V_60 ;
else
* V_49 = V_3 -> V_61 ;
* V_51 = V_46 -> V_93 [ V_92 ] . V_63 ;
if ( ( V_46 -> V_93 [ V_92 ] . V_94 == V_95 ) ||
( V_46 -> V_93 [ V_92 ] . V_94 == V_96 ) )
* V_54 = ( V_68 % 8 ) * 3 ;
else
* V_54 = ( V_68 % 8 ) * 2 ;
}
static int F_34 ( struct V_8 * V_46 ,
int V_68 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 ;
T_2 V_37 , V_98 , V_99 ;
T_1 V_54 ;
int V_94 = V_46 -> V_93 [ V_68 / 8 ] . V_94 ;
V_11 -> V_100 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
switch ( V_94 ) {
case V_95 :
case V_96 :
V_99 = V_101 ;
switch ( V_54 ) {
case 0 ... 12 :
break;
case 15 :
V_52 = F_19 ( V_49 , V_51 , & V_37 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_19 ( V_49 , V_51 + 0x4 , & V_98 ) ;
if ( V_52 )
return V_52 ;
V_37 >>= 15 ;
V_98 &= 0x3 ;
V_98 <<= 1 ;
V_37 |= V_98 ;
return V_102 [ V_94 ] [ V_37 ] ;
case 18 ... 21 :
V_51 += 4 ;
V_54 -= 16 ;
break;
default:
F_10 ( V_3 -> V_33 , L_6 ,
V_54 , V_94 ) ;
return - V_18 ;
}
break;
case V_103 :
case V_104 :
case V_105 :
V_99 = V_81 ;
break;
default:
F_10 ( V_3 -> V_33 , L_7 ,
V_94 ) ;
return - V_18 ;
}
V_52 = F_19 ( V_49 , V_51 , & V_37 ) ;
if ( V_52 )
return V_52 ;
V_37 >>= V_54 ;
V_37 &= ( 1 << V_99 ) - 1 ;
return V_102 [ V_94 ] [ V_37 ] ;
}
static int F_35 ( struct V_8 * V_46 ,
int V_68 , int V_106 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
unsigned long V_64 ;
int V_51 , V_52 , V_5 ;
T_2 V_37 , V_65 , V_99 , V_98 ;
T_1 V_54 ;
int V_94 = V_46 -> V_93 [ V_68 / 8 ] . V_94 ;
F_16 ( V_3 -> V_33 , L_8 ,
V_46 -> V_17 , V_68 , V_106 ) ;
V_11 -> V_100 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
V_52 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_36 ( V_102 [ V_94 ] ) ; V_5 ++ ) {
if ( V_102 [ V_94 ] [ V_5 ] == V_106 ) {
V_52 = V_5 ;
break;
} else if ( V_102 [ V_94 ] [ V_5 ] < 0 ) {
V_52 = V_102 [ V_94 ] [ V_5 ] ;
break;
}
}
if ( V_52 < 0 ) {
F_10 ( V_3 -> V_33 , L_9 ,
V_106 ) ;
return V_52 ;
}
F_21 ( & V_46 -> V_67 , V_64 ) ;
switch ( V_94 ) {
case V_95 :
case V_96 :
V_99 = V_101 ;
switch ( V_54 ) {
case 0 ... 12 :
break;
case 15 :
V_37 = ( V_52 & 0x1 ) << 15 ;
V_98 = ( V_52 >> 0x1 ) & 0x3 ;
V_65 = F_37 ( 15 ) | F_37 ( 31 ) ;
V_37 |= F_37 ( 31 ) ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
if ( V_52 ) {
F_23 ( & V_46 -> V_67 , V_64 ) ;
return V_52 ;
}
V_65 = 0x3 | ( 0x3 << 16 ) ;
V_98 |= ( 0x3 << 16 ) ;
V_51 += 0x4 ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_98 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
return V_52 ;
case 18 ... 21 :
V_51 += 4 ;
V_54 -= 16 ;
break;
default:
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_10 ( V_3 -> V_33 , L_6 ,
V_54 , V_94 ) ;
return - V_18 ;
}
break;
case V_103 :
case V_104 :
case V_105 :
V_99 = V_81 ;
break;
default:
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_10 ( V_3 -> V_33 , L_7 ,
V_94 ) ;
return - V_18 ;
}
V_37 = ( ( 1 << V_99 ) - 1 ) << ( V_54 + 16 ) ;
V_65 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_52 << V_54 ) ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
return V_52 ;
}
static int F_38 ( struct V_8 * V_46 , int V_68 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 ;
T_1 V_54 ;
T_2 V_37 ;
if ( V_11 -> type == V_107 )
return V_108 ;
V_11 -> V_109 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
V_52 = F_19 ( V_49 , V_51 , & V_37 ) ;
if ( V_52 )
return V_52 ;
switch ( V_11 -> type ) {
case V_110 :
return ! ( V_37 & F_37 ( V_54 ) )
? V_111
: V_108 ;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_37 >>= V_54 ;
V_37 &= ( 1 << V_75 ) - 1 ;
switch ( V_37 ) {
case 0 :
return V_108 ;
case 1 :
return V_116 ;
case 2 :
return V_117 ;
case 3 :
return V_118 ;
}
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_119 ;
default:
F_10 ( V_3 -> V_33 , L_11 ) ;
return - V_18 ;
} ;
}
static int F_39 ( struct V_8 * V_46 ,
int V_68 , int V_120 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 ;
unsigned long V_64 ;
T_1 V_54 ;
T_2 V_37 , V_65 ;
F_16 ( V_3 -> V_33 , L_12 ,
V_46 -> V_17 , V_68 , V_120 ) ;
if ( V_11 -> type == V_107 )
return V_120 ? - V_18 : 0 ;
V_11 -> V_109 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
switch ( V_11 -> type ) {
case V_110 :
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_37 ( V_54 + 16 ) ;
if ( V_120 == V_108 )
V_37 |= F_37 ( V_54 ) ;
V_52 = F_40 ( V_49 , V_51 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = ( ( 1 << V_75 ) - 1 ) << ( V_54 + 16 ) ;
V_65 = V_37 | ( V_37 >> 16 ) ;
switch ( V_120 ) {
case V_108 :
break;
case V_116 :
V_37 |= ( 1 << V_54 ) ;
break;
case V_117 :
V_37 |= ( 2 << V_54 ) ;
break;
case V_118 :
V_37 |= ( 3 << V_54 ) ;
break;
default:
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_10 ( V_3 -> V_33 , L_13 ,
V_120 ) ;
return - V_18 ;
}
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
break;
default:
F_10 ( V_3 -> V_33 , L_11 ) ;
return - V_18 ;
}
return V_52 ;
}
static int F_41 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_121 ;
}
static const char * F_42 ( struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_122 [ V_21 ] . V_4 ;
}
static int F_43 ( struct V_19 * V_20 ,
unsigned V_21 , const char * const * * V_7 ,
unsigned * const V_123 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
* V_7 = V_3 -> V_122 [ V_21 ] . V_7 ;
* V_123 = V_3 -> V_122 [ V_21 ] . V_6 ;
return 0 ;
}
static int F_44 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_40 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
const unsigned int * V_22 = V_3 -> V_7 [ V_40 ] . V_22 ;
const struct V_124 * V_37 = V_3 -> V_7 [ V_40 ] . V_37 ;
struct V_8 * V_46 ;
int V_125 , V_52 = 0 ;
F_16 ( V_3 -> V_33 , L_14 ,
V_3 -> V_122 [ V_21 ] . V_4 , V_3 -> V_7 [ V_40 ] . V_4 ) ;
for ( V_125 = 0 ; V_125 < V_3 -> V_7 [ V_40 ] . V_23 ; V_125 ++ ) {
V_46 = F_2 ( V_3 , V_22 [ V_125 ] ) ;
V_52 = F_20 ( V_46 , V_22 [ V_125 ] - V_46 -> V_13 ,
V_37 [ V_125 ] . V_126 ) ;
if ( V_52 )
break;
}
if ( V_52 ) {
for ( V_125 -- ; V_125 >= 0 ; V_125 -- )
F_20 ( V_46 , V_22 [ V_125 ] - V_46 -> V_13 , 0 ) ;
return V_52 ;
}
return 0 ;
}
static int F_45 ( struct V_127 * V_128 ,
int V_9 , bool V_129 )
{
struct V_8 * V_46 ;
int V_52 ;
unsigned long V_64 ;
T_2 V_37 ;
V_46 = F_46 ( V_128 ) ;
V_52 = F_20 ( V_46 , V_9 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
F_47 ( V_46 -> V_130 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_48 ( V_46 -> V_131 + V_132 ) ;
if ( ! V_129 )
V_37 |= F_37 ( V_9 ) ;
else
V_37 &= ~ F_37 ( V_9 ) ;
F_49 ( V_37 , V_46 -> V_131 + V_132 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_50 ( V_46 -> V_130 ) ;
return 0 ;
}
static int F_51 ( struct V_19 * V_20 ,
struct V_133 * V_134 ,
unsigned V_63 , bool V_129 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_127 * V_128 ;
int V_9 ;
V_128 = V_134 -> V_135 ;
V_9 = V_63 - V_128 -> V_136 ;
F_16 ( V_3 -> V_33 , L_15 ,
V_63 , V_134 -> V_4 , V_9 , V_129 ? L_16 : L_17 ) ;
return F_45 ( V_128 , V_63 - V_128 -> V_136 ,
V_129 ) ;
}
static bool F_52 ( struct V_97 * V_11 ,
enum V_137 V_120 )
{
switch ( V_11 -> type ) {
case V_110 :
return ( V_120 == V_111 ||
V_120 == V_108 ) ;
case V_107 :
return V_120 ? false : true ;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
return ( V_120 != V_111 ) ;
}
return false ;
}
static int F_53 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_42 , unsigned V_44 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_137 V_138 ;
T_3 V_139 ;
int V_5 ;
int V_140 ;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ ) {
V_138 = F_54 ( V_42 [ V_5 ] ) ;
V_139 = F_55 ( V_42 [ V_5 ] ) ;
switch ( V_138 ) {
case V_108 :
V_140 = F_39 ( V_46 , V_9 - V_46 -> V_13 ,
V_138 ) ;
if ( V_140 )
return V_140 ;
break;
case V_116 :
case V_117 :
case V_111 :
case V_118 :
if ( ! F_52 ( V_3 -> V_11 , V_138 ) )
return - V_66 ;
if ( ! V_139 )
return - V_18 ;
V_140 = F_39 ( V_46 , V_9 - V_46 -> V_13 ,
V_138 ) ;
if ( V_140 )
return V_140 ;
break;
case V_141 :
F_56 ( & V_46 -> V_127 ,
V_9 - V_46 -> V_13 , V_139 ) ;
V_140 = F_45 ( & V_46 -> V_127 ,
V_9 - V_46 -> V_13 , false ) ;
if ( V_140 )
return V_140 ;
break;
case V_142 :
if ( ! V_3 -> V_11 -> V_100 )
return - V_66 ;
V_140 = F_35 ( V_46 ,
V_9 - V_46 -> V_13 , V_139 ) ;
if ( V_140 < 0 )
return V_140 ;
break;
default:
return - V_66 ;
break;
}
}
return 0 ;
}
static int F_57 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_143 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_137 V_138 = F_54 ( * V_143 ) ;
T_3 V_139 ;
int V_140 ;
switch ( V_138 ) {
case V_108 :
if ( F_38 ( V_46 , V_9 - V_46 -> V_13 ) != V_138 )
return - V_18 ;
V_139 = 0 ;
break;
case V_116 :
case V_117 :
case V_111 :
case V_118 :
if ( ! F_52 ( V_3 -> V_11 , V_138 ) )
return - V_66 ;
if ( F_38 ( V_46 , V_9 - V_46 -> V_13 ) != V_138 )
return - V_18 ;
V_139 = 1 ;
break;
case V_141 :
V_140 = F_18 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_140 != V_58 )
return - V_18 ;
V_140 = F_58 ( & V_46 -> V_127 , V_9 - V_46 -> V_13 ) ;
if ( V_140 < 0 )
return V_140 ;
V_139 = V_140 ? 1 : 0 ;
break;
case V_142 :
if ( ! V_3 -> V_11 -> V_100 )
return - V_66 ;
V_140 = F_34 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_140 < 0 )
return V_140 ;
V_139 = V_140 ;
break;
default:
return - V_66 ;
break;
}
* V_143 = F_59 ( V_138 , V_139 ) ;
return 0 ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_24 * V_144 ;
F_61 (np, child) {
if ( F_62 ( V_145 , V_144 ) )
continue;
V_3 -> V_121 ++ ;
V_3 -> V_6 += F_63 ( V_144 ) ;
}
}
static int F_64 ( struct V_24 * V_25 ,
struct V_1 * V_29 ,
struct V_2 * V_3 ,
T_2 V_146 )
{
struct V_8 * V_46 ;
int V_147 ;
const T_4 * V_148 ;
int V_15 ;
int V_5 , V_149 ;
int V_52 ;
F_16 ( V_3 -> V_33 , L_18 , V_146 , V_25 -> V_4 ) ;
V_29 -> V_4 = V_25 -> V_4 ;
V_148 = F_65 ( V_25 , L_19 , & V_147 ) ;
V_147 /= sizeof( * V_148 ) ;
if ( ! V_147 || V_147 % 4 ) {
F_10 ( V_3 -> V_33 , L_20 ) ;
return - V_18 ;
}
V_29 -> V_23 = V_147 / 4 ;
V_29 -> V_22 = F_11 ( V_3 -> V_33 , V_29 -> V_23 * sizeof( unsigned int ) ,
V_34 ) ;
V_29 -> V_37 = F_11 ( V_3 -> V_33 , V_29 -> V_23 *
sizeof( struct V_124 ) ,
V_34 ) ;
if ( ! V_29 -> V_22 || ! V_29 -> V_37 )
return - V_35 ;
for ( V_5 = 0 , V_149 = 0 ; V_5 < V_147 ; V_5 += 4 , V_149 ++ ) {
const T_4 * V_150 ;
struct V_24 * V_151 ;
V_15 = F_66 ( * V_148 ++ ) ;
V_46 = F_3 ( V_3 , V_15 ) ;
if ( F_67 ( V_46 ) )
return F_68 ( V_46 ) ;
V_29 -> V_22 [ V_149 ] = V_46 -> V_13 + F_66 ( * V_148 ++ ) ;
V_29 -> V_37 [ V_149 ] . V_126 = F_66 ( * V_148 ++ ) ;
V_150 = V_148 ++ ;
if ( ! V_150 )
return - V_18 ;
V_151 = F_69 ( F_70 ( V_150 ) ) ;
V_52 = F_71 ( V_151 , NULL ,
& V_29 -> V_37 [ V_149 ] . V_42 , & V_29 -> V_37 [ V_149 ] . V_45 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_72 ( struct V_24 * V_25 ,
struct V_2 * V_3 ,
T_2 V_146 )
{
struct V_24 * V_144 ;
struct V_152 * V_126 ;
struct V_1 * V_29 ;
int V_52 ;
static T_2 V_153 ;
T_2 V_5 = 0 ;
F_16 ( V_3 -> V_33 , L_21 , V_146 , V_25 -> V_4 ) ;
V_126 = & V_3 -> V_122 [ V_146 ] ;
V_126 -> V_4 = V_25 -> V_4 ;
V_126 -> V_6 = F_63 ( V_25 ) ;
if ( V_126 -> V_6 <= 0 )
return 0 ;
V_126 -> V_7 = F_11 ( V_3 -> V_33 ,
V_126 -> V_6 * sizeof( char * ) , V_34 ) ;
if ( ! V_126 -> V_7 )
return - V_35 ;
F_61 (np, child) {
V_126 -> V_7 [ V_5 ] = V_144 -> V_4 ;
V_29 = & V_3 -> V_7 [ V_153 ++ ] ;
V_52 = F_64 ( V_144 , V_29 , V_3 , V_5 ++ ) ;
if ( V_52 ) {
F_14 ( V_144 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_73 ( struct V_154 * V_155 ,
struct V_2 * V_3 )
{
struct V_156 * V_33 = & V_155 -> V_33 ;
struct V_24 * V_25 = V_33 -> V_157 ;
struct V_24 * V_144 ;
int V_52 ;
int V_5 ;
F_60 ( V_3 , V_25 ) ;
F_16 ( & V_155 -> V_33 , L_22 , V_3 -> V_121 ) ;
F_16 ( & V_155 -> V_33 , L_23 , V_3 -> V_6 ) ;
V_3 -> V_122 = F_11 ( V_33 , V_3 -> V_121 *
sizeof( struct V_152 ) ,
V_34 ) ;
if ( ! V_3 -> V_122 ) {
F_10 ( V_33 , L_24 ) ;
return - V_18 ;
}
V_3 -> V_7 = F_11 ( V_33 , V_3 -> V_6 *
sizeof( struct V_1 ) ,
V_34 ) ;
if ( ! V_3 -> V_7 ) {
F_10 ( V_33 , L_25 ) ;
return - V_18 ;
}
V_5 = 0 ;
F_61 (np, child) {
if ( F_62 ( V_145 , V_144 ) )
continue;
V_52 = F_72 ( V_144 , V_3 , V_5 ++ ) ;
if ( V_52 ) {
F_10 ( & V_155 -> V_33 , L_26 ) ;
F_14 ( V_144 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_74 ( struct V_154 * V_155 ,
struct V_2 * V_3 )
{
struct V_158 * V_159 = & V_3 -> V_160 ;
struct V_161 * V_162 , * V_163 ;
struct V_8 * V_164 ;
int V_9 , V_46 , V_52 ;
int V_165 ;
V_159 -> V_4 = L_27 ;
V_159 -> V_166 = V_167 ;
V_159 -> V_168 = & V_169 ;
V_159 -> V_170 = & V_171 ;
V_159 -> V_172 = & V_173 ;
V_162 = F_11 ( & V_155 -> V_33 , sizeof( * V_162 ) *
V_3 -> V_11 -> V_14 , V_34 ) ;
if ( ! V_162 ) {
F_10 ( & V_155 -> V_33 , L_28 ) ;
return - V_35 ;
}
V_159 -> V_22 = V_162 ;
V_159 -> V_23 = V_3 -> V_11 -> V_14 ;
V_163 = V_162 ;
for ( V_46 = 0 , V_165 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; V_46 ++ ) {
V_164 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
for ( V_9 = 0 ; V_9 < V_164 -> V_14 ; V_9 ++ , V_165 ++ ) {
V_163 -> V_174 = V_165 ;
V_163 -> V_4 = F_75 ( V_34 , L_29 ,
V_164 -> V_4 , V_9 ) ;
V_163 ++ ;
}
}
V_52 = F_73 ( V_155 , V_3 ) ;
if ( V_52 )
return V_52 ;
V_3 -> V_175 = F_76 ( V_159 , & V_155 -> V_33 , V_3 ) ;
if ( F_67 ( V_3 -> V_175 ) ) {
F_10 ( & V_155 -> V_33 , L_30 ) ;
return F_68 ( V_3 -> V_175 ) ;
}
for ( V_46 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; ++ V_46 ) {
V_164 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
V_164 -> V_176 . V_4 = V_164 -> V_4 ;
V_164 -> V_176 . V_177 = V_46 ;
V_164 -> V_176 . V_13 = V_164 -> V_13 ;
V_164 -> V_176 . V_136 = V_164 -> V_127 . V_136 ;
V_164 -> V_176 . V_23 = V_164 -> V_127 . V_178 ;
V_164 -> V_176 . V_135 = & V_164 -> V_127 ;
F_77 ( V_3 -> V_175 , & V_164 -> V_176 ) ;
}
return 0 ;
}
static void F_56 ( struct V_127 * V_135 , unsigned V_63 , int V_179 )
{
struct V_8 * V_46 = F_46 ( V_135 ) ;
void T_5 * V_51 = V_46 -> V_131 + V_180 ;
unsigned long V_64 ;
T_2 V_37 ;
F_47 ( V_46 -> V_130 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_78 ( V_51 ) ;
V_37 &= ~ F_37 ( V_63 ) ;
if ( V_179 )
V_37 |= F_37 ( V_63 ) ;
F_79 ( V_37 , V_51 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_50 ( V_46 -> V_130 ) ;
}
static int F_58 ( struct V_127 * V_135 , unsigned V_63 )
{
struct V_8 * V_46 = F_46 ( V_135 ) ;
T_2 V_37 ;
F_47 ( V_46 -> V_130 ) ;
V_37 = F_78 ( V_46 -> V_131 + V_181 ) ;
F_50 ( V_46 -> V_130 ) ;
V_37 >>= V_63 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_80 ( struct V_127 * V_135 , unsigned V_63 )
{
return F_81 ( V_135 -> V_136 + V_63 ) ;
}
static int F_82 ( struct V_127 * V_135 ,
unsigned V_63 , int V_179 )
{
F_56 ( V_135 , V_63 , V_179 ) ;
return F_83 ( V_135 -> V_136 + V_63 ) ;
}
static int F_84 ( struct V_127 * V_135 , unsigned V_63 )
{
struct V_8 * V_46 = F_46 ( V_135 ) ;
unsigned int V_182 ;
if ( ! V_46 -> V_183 )
return - V_184 ;
V_182 = F_85 ( V_46 -> V_183 , V_63 ) ;
return ( V_182 ) ? : - V_184 ;
}
static void F_86 ( struct V_185 * V_186 )
{
struct V_187 * V_128 = F_87 ( V_186 ) ;
struct V_8 * V_46 = F_88 ( V_186 ) ;
T_2 V_188 ;
F_16 ( V_46 -> V_47 -> V_33 , L_31 , V_46 -> V_4 ) ;
F_89 ( V_128 , V_186 ) ;
V_188 = F_48 ( V_46 -> V_131 + V_189 ) ;
while ( V_188 ) {
unsigned int V_190 , V_182 ;
V_190 = F_90 ( V_188 ) ;
V_188 &= ~ F_37 ( V_190 ) ;
V_182 = F_91 ( V_46 -> V_183 , V_190 ) ;
if ( ! V_182 ) {
F_10 ( V_46 -> V_47 -> V_33 , L_32 , V_190 ) ;
continue;
}
F_16 ( V_46 -> V_47 -> V_33 , L_33 , V_190 ) ;
if ( V_46 -> V_191 & F_37 ( V_190 ) ) {
T_2 V_37 , V_192 , V_193 ;
unsigned long V_64 ;
V_37 = F_48 ( V_46 -> V_131 + V_181 ) ;
do {
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_193 = F_48 ( V_46 -> V_131 +
V_194 ) ;
if ( V_37 & F_37 ( V_190 ) )
V_193 &= ~ F_37 ( V_190 ) ;
else
V_193 |= F_37 ( V_190 ) ;
F_79 ( V_193 ,
V_46 -> V_131 + V_194 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
V_192 = V_37 ;
V_37 = F_48 ( V_46 -> V_131 +
V_181 ) ;
} while ( ( V_37 & F_37 ( V_190 ) ) != ( V_192 & F_37 ( V_190 ) ) );
}
F_92 ( V_182 ) ;
}
F_93 ( V_128 , V_186 ) ;
}
static int F_94 ( struct V_195 * V_196 , unsigned int type )
{
struct V_197 * V_135 = F_95 ( V_196 ) ;
struct V_8 * V_46 = V_135 -> V_198 ;
T_2 V_53 = F_37 ( V_196 -> V_199 ) ;
T_2 V_193 ;
T_2 V_200 ;
T_2 V_37 ;
unsigned long V_64 ;
int V_52 ;
V_52 = F_20 ( V_46 , V_196 -> V_199 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
F_47 ( V_46 -> V_130 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_48 ( V_46 -> V_131 + V_132 ) ;
V_37 &= ~ V_53 ;
F_49 ( V_37 , V_46 -> V_131 + V_132 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
if ( type & V_201 )
F_96 ( V_196 , V_202 ) ;
else
F_96 ( V_196 , V_203 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
F_97 ( V_135 ) ;
V_200 = F_48 ( V_135 -> V_131 + V_204 ) ;
V_193 = F_48 ( V_135 -> V_131 + V_194 ) ;
switch ( type ) {
case V_201 :
V_46 -> V_191 |= V_53 ;
V_200 |= V_53 ;
V_37 = F_78 ( V_46 -> V_131 + V_181 ) ;
if ( V_37 & V_53 )
V_193 &= ~ V_53 ;
else
V_193 |= V_53 ;
break;
case V_205 :
V_46 -> V_191 &= ~ V_53 ;
V_200 |= V_53 ;
V_193 |= V_53 ;
break;
case V_206 :
V_46 -> V_191 &= ~ V_53 ;
V_200 |= V_53 ;
V_193 &= ~ V_53 ;
break;
case V_207 :
V_46 -> V_191 &= ~ V_53 ;
V_200 &= ~ V_53 ;
V_193 |= V_53 ;
break;
case V_208 :
V_46 -> V_191 &= ~ V_53 ;
V_200 &= ~ V_53 ;
V_193 &= ~ V_53 ;
break;
default:
F_98 ( V_135 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_50 ( V_46 -> V_130 ) ;
return - V_18 ;
}
F_49 ( V_200 , V_135 -> V_131 + V_204 ) ;
F_49 ( V_193 , V_135 -> V_131 + V_194 ) ;
F_98 ( V_135 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_50 ( V_46 -> V_130 ) ;
return 0 ;
}
static void F_99 ( struct V_195 * V_196 )
{
struct V_197 * V_135 = F_95 ( V_196 ) ;
struct V_8 * V_46 = V_135 -> V_198 ;
F_47 ( V_46 -> V_130 ) ;
V_46 -> V_209 = F_100 ( V_135 , V_210 ) ;
F_101 ( V_135 , ~ V_135 -> V_211 , V_210 ) ;
F_50 ( V_46 -> V_130 ) ;
}
static void F_102 ( struct V_195 * V_196 )
{
struct V_197 * V_135 = F_95 ( V_196 ) ;
struct V_8 * V_46 = V_135 -> V_198 ;
F_47 ( V_46 -> V_130 ) ;
F_101 ( V_135 , V_46 -> V_209 , V_210 ) ;
F_50 ( V_46 -> V_130 ) ;
}
static void F_103 ( struct V_195 * V_196 )
{
struct V_197 * V_135 = F_95 ( V_196 ) ;
struct V_8 * V_46 = V_135 -> V_198 ;
F_47 ( V_46 -> V_130 ) ;
F_104 ( V_196 ) ;
}
void F_105 ( struct V_195 * V_196 )
{
struct V_197 * V_135 = F_95 ( V_196 ) ;
struct V_8 * V_46 = V_135 -> V_198 ;
F_106 ( V_196 ) ;
F_50 ( V_46 -> V_130 ) ;
}
static int F_107 ( struct V_154 * V_155 ,
struct V_2 * V_3 )
{
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
unsigned int V_212 = V_213 | V_214 | V_215 ;
struct V_197 * V_135 ;
int V_52 ;
int V_5 , V_149 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_216 ) {
F_108 ( & V_155 -> V_33 , L_34 ,
V_46 -> V_4 ) ;
continue;
}
V_52 = F_47 ( V_46 -> V_130 ) ;
if ( V_52 ) {
F_10 ( & V_155 -> V_33 , L_35 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_183 = F_109 ( V_46 -> V_157 , 32 ,
& V_217 , NULL ) ;
if ( ! V_46 -> V_183 ) {
F_108 ( & V_155 -> V_33 , L_36 ,
V_46 -> V_4 ) ;
F_50 ( V_46 -> V_130 ) ;
continue;
}
V_52 = F_110 ( V_46 -> V_183 , 32 , 1 ,
L_37 , V_203 ,
V_212 , 0 , V_218 ) ;
if ( V_52 ) {
F_10 ( & V_155 -> V_33 , L_38 ,
V_46 -> V_4 ) ;
F_111 ( V_46 -> V_183 ) ;
F_50 ( V_46 -> V_130 ) ;
continue;
}
F_49 ( 0xffffffff , V_46 -> V_131 + V_210 ) ;
F_49 ( 0xffffffff , V_46 -> V_131 + V_219 ) ;
V_135 = F_112 ( V_46 -> V_183 , 0 ) ;
V_135 -> V_131 = V_46 -> V_131 ;
V_135 -> V_198 = V_46 ;
V_135 -> V_220 [ 0 ] . V_221 . V_53 = V_210 ;
V_135 -> V_220 [ 0 ] . V_221 . V_222 = V_223 ;
V_135 -> V_220 [ 0 ] . V_128 . V_224 = V_225 ;
V_135 -> V_220 [ 0 ] . V_128 . V_226 = F_105 ;
V_135 -> V_220 [ 0 ] . V_128 . V_227 =
F_103 ;
V_135 -> V_220 [ 0 ] . V_128 . V_228 = V_229 ;
V_135 -> V_220 [ 0 ] . V_128 . V_230 = F_99 ;
V_135 -> V_220 [ 0 ] . V_128 . V_231 = F_102 ;
V_135 -> V_220 [ 0 ] . V_128 . V_232 = F_94 ;
V_135 -> V_233 = F_113 ( V_46 -> V_14 ) ;
F_114 ( V_46 -> V_190 ,
F_86 , V_46 ) ;
for ( V_149 = 0 ; V_149 < 32 ; V_149 ++ )
F_85 ( V_46 -> V_183 , V_149 ) ;
F_50 ( V_46 -> V_130 ) ;
}
return 0 ;
}
static int F_115 ( struct V_154 * V_155 ,
struct V_2 * V_3 )
{
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
struct V_127 * V_135 ;
int V_52 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_216 ) {
F_108 ( & V_155 -> V_33 , L_34 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_127 = V_234 ;
V_135 = & V_46 -> V_127 ;
V_135 -> V_136 = V_46 -> V_13 ;
V_135 -> V_178 = V_46 -> V_14 ;
V_135 -> V_31 = & V_155 -> V_33 ;
V_135 -> V_157 = V_46 -> V_157 ;
V_135 -> V_235 = V_46 -> V_4 ;
V_52 = F_116 ( V_135 , V_46 ) ;
if ( V_52 ) {
F_10 ( & V_155 -> V_33 , L_39 ,
V_135 -> V_235 , V_52 ) ;
goto V_236;
}
}
F_107 ( V_155 , V_3 ) ;
return 0 ;
V_236:
for ( -- V_5 , -- V_46 ; V_5 >= 0 ; -- V_5 , -- V_46 ) {
if ( ! V_46 -> V_216 )
continue;
F_117 ( & V_46 -> V_127 ) ;
}
return V_52 ;
}
static int F_118 ( struct V_154 * V_155 ,
struct V_2 * V_3 )
{
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_216 )
continue;
F_117 ( & V_46 -> V_127 ) ;
}
return 0 ;
}
static int F_119 ( struct V_8 * V_46 ,
struct V_2 * V_3 )
{
struct V_237 V_238 ;
void T_5 * V_136 ;
if ( F_120 ( V_46 -> V_157 , 0 , & V_238 ) ) {
F_10 ( V_3 -> V_33 , L_40 ) ;
return - V_239 ;
}
V_46 -> V_131 = F_121 ( V_3 -> V_33 , & V_238 ) ;
if ( F_67 ( V_46 -> V_131 ) )
return F_68 ( V_46 -> V_131 ) ;
if ( F_122 ( V_46 -> V_157 ,
L_41 ) ) {
struct V_24 * V_240 ;
V_240 = F_123 ( V_46 -> V_157 -> V_31 ,
L_42 , 0 ) ;
if ( ! V_240 ) {
if ( F_120 ( V_46 -> V_157 , 1 , & V_238 ) ) {
F_10 ( V_3 -> V_33 , L_40 ) ;
return - V_239 ;
}
V_136 = F_121 ( V_3 -> V_33 , & V_238 ) ;
if ( F_67 ( V_136 ) )
return F_68 ( V_136 ) ;
V_241 . V_242 =
F_124 ( & V_238 ) - 4 ;
V_241 . V_4 =
L_43 ;
V_46 -> V_72 = F_125 ( V_3 -> V_33 ,
V_136 ,
& V_241 ) ;
}
}
V_46 -> V_190 = F_126 ( V_46 -> V_157 , 0 ) ;
V_46 -> V_130 = F_127 ( V_46 -> V_157 , 0 ) ;
if ( F_67 ( V_46 -> V_130 ) )
return F_68 ( V_46 -> V_130 ) ;
return F_128 ( V_46 -> V_130 ) ;
}
static struct V_97 * F_129 (
struct V_2 * V_196 ,
struct V_154 * V_155 )
{
const struct V_243 * V_244 ;
struct V_24 * V_240 = V_155 -> V_33 . V_157 ;
struct V_24 * V_25 ;
struct V_97 * V_11 ;
struct V_8 * V_46 ;
int V_245 , V_246 , V_247 , V_248 , V_5 , V_149 ;
V_244 = F_62 ( V_249 , V_240 ) ;
V_11 = (struct V_97 * ) V_244 -> V_37 ;
F_61 (node, np) {
if ( ! F_130 ( V_25 , L_44 , NULL ) )
continue;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! strcmp ( V_46 -> V_4 , V_25 -> V_4 ) ) {
V_46 -> V_157 = V_25 ;
if ( ! F_119 ( V_46 , V_196 ) )
V_46 -> V_216 = true ;
break;
}
}
}
V_245 = V_11 -> V_250 ;
V_246 = V_11 -> V_251 ;
V_248 = V_11 -> V_252 ;
V_247 = V_11 -> V_253 ;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
int V_254 = 0 ;
F_131 ( & V_46 -> V_67 ) ;
V_46 -> V_47 = V_196 ;
V_46 -> V_13 = V_11 -> V_14 ;
V_11 -> V_14 += V_46 -> V_14 ;
for ( V_149 = 0 ; V_149 < 4 ; V_149 ++ ) {
struct V_255 * V_256 = & V_46 -> V_55 [ V_149 ] ;
struct V_257 * V_93 = & V_46 -> V_93 [ V_149 ] ;
int V_258 ;
if ( V_254 >= V_46 -> V_14 )
break;
if ( V_256 -> V_63 >= 0 ) {
if ( V_256 -> type & V_59 )
V_246 = V_256 -> V_63 ;
else
V_245 = V_256 -> V_63 ;
} else {
V_256 -> V_63 = ( V_256 -> type & V_59 ) ?
V_246 : V_245 ;
}
if ( V_93 -> V_63 >= 0 ) {
if ( V_256 -> type & V_59 )
V_248 = V_93 -> V_63 ;
else
V_247 = V_93 -> V_63 ;
} else {
V_93 -> V_63 = ( V_256 -> type & V_59 ) ?
V_248 : V_247 ;
}
F_16 ( V_196 -> V_33 , L_45 ,
V_5 , V_149 , V_256 -> V_63 , V_93 -> V_63 ) ;
V_258 = ( V_256 -> type & V_62 ) ? 8 : 4 ;
if ( V_256 -> type & V_59 )
V_246 += V_258 ;
else
V_245 += V_258 ;
if ( ( V_93 -> V_94 == V_95 ) ||
( V_93 -> V_94 == V_96 ) )
V_258 = 8 ;
else
V_258 = 4 ;
if ( V_256 -> type & V_59 )
V_248 += V_258 ;
else
V_247 += V_258 ;
V_254 += 8 ;
}
}
return V_11 ;
}
static int T_6 F_132 ( struct V_156 * V_33 )
{
struct V_2 * V_3 = F_133 ( V_33 ) ;
int V_52 = F_134 ( V_3 -> V_175 ) ;
if ( V_52 )
return V_52 ;
if ( V_3 -> V_11 -> type == V_113 ) {
V_52 = F_19 ( V_3 -> V_61 , V_259 ,
& V_260 ) ;
if ( V_52 ) {
F_135 ( V_3 -> V_175 ) ;
return V_52 ;
}
}
return 0 ;
}
static int T_6 F_136 ( struct V_156 * V_33 )
{
struct V_2 * V_3 = F_133 ( V_33 ) ;
int V_52 = F_40 ( V_3 -> V_61 , V_259 ,
V_260 |
V_261 ) ;
if ( V_52 )
return V_52 ;
return F_135 ( V_3 -> V_175 ) ;
}
static int F_137 ( struct V_154 * V_155 )
{
struct V_2 * V_3 ;
struct V_156 * V_33 = & V_155 -> V_33 ;
struct V_97 * V_11 ;
struct V_24 * V_25 = V_155 -> V_33 . V_157 , * V_240 ;
struct V_237 * V_238 ;
void T_5 * V_136 ;
int V_52 ;
if ( ! V_33 -> V_157 ) {
F_10 ( V_33 , L_46 ) ;
return - V_262 ;
}
V_3 = F_11 ( V_33 , sizeof( struct V_2 ) , V_34 ) ;
if ( ! V_3 )
return - V_35 ;
V_3 -> V_33 = V_33 ;
V_11 = F_129 ( V_3 , V_155 ) ;
if ( ! V_11 ) {
F_10 ( V_33 , L_47 ) ;
return - V_18 ;
}
V_3 -> V_11 = V_11 ;
V_240 = F_123 ( V_25 , L_48 , 0 ) ;
if ( V_240 ) {
V_3 -> V_61 = F_138 ( V_240 ) ;
if ( F_67 ( V_3 -> V_61 ) )
return F_68 ( V_3 -> V_61 ) ;
} else {
V_238 = F_139 ( V_155 , V_263 , 0 ) ;
V_136 = F_121 ( & V_155 -> V_33 , V_238 ) ;
if ( F_67 ( V_136 ) )
return F_68 ( V_136 ) ;
V_241 . V_242 = F_124 ( V_238 ) - 4 ;
V_241 . V_4 = L_49 ;
V_3 -> V_61 = F_125 ( & V_155 -> V_33 , V_136 ,
& V_241 ) ;
V_3 -> V_264 = F_124 ( V_238 ) ;
if ( V_11 -> type == V_112 && V_3 -> V_264 < 0x200 ) {
V_238 = F_139 ( V_155 , V_263 , 1 ) ;
V_136 = F_121 ( & V_155 -> V_33 , V_238 ) ;
if ( F_67 ( V_136 ) )
return F_68 ( V_136 ) ;
V_241 . V_242 =
F_124 ( V_238 ) - 4 ;
V_241 . V_4 = L_50 ;
V_3 -> V_72 = F_125 ( & V_155 -> V_33 ,
V_136 ,
& V_241 ) ;
}
}
V_240 = F_123 ( V_25 , L_42 , 0 ) ;
if ( V_240 ) {
V_3 -> V_60 = F_138 ( V_240 ) ;
if ( F_67 ( V_3 -> V_60 ) )
return F_68 ( V_3 -> V_60 ) ;
}
V_52 = F_115 ( V_155 , V_3 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_74 ( V_155 , V_3 ) ;
if ( V_52 ) {
F_118 ( V_155 , V_3 ) ;
return V_52 ;
}
F_140 ( V_155 , V_3 ) ;
return 0 ;
}
static int T_7 F_141 ( void )
{
return F_142 ( & V_265 ) ;
}
