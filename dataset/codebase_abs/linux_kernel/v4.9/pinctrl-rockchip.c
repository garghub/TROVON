static inline const struct V_1 * F_1 (
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
int V_51 , V_52 , V_107 ;
T_1 V_54 ;
T_2 V_37 ;
if ( V_11 -> type == V_108 )
return V_109 ;
V_11 -> V_110 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
V_52 = F_19 ( V_49 , V_51 , & V_37 ) ;
if ( V_52 )
return V_52 ;
switch ( V_11 -> type ) {
case V_111 :
return ! ( V_37 & F_37 ( V_54 ) )
? V_112
: V_109 ;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_107 = V_46 -> V_107 [ V_68 / 8 ] ;
V_37 >>= V_54 ;
V_37 &= ( 1 << V_75 ) - 1 ;
return V_117 [ V_107 ] [ V_37 ] ;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
} ;
}
static int F_39 ( struct V_8 * V_46 ,
int V_68 , int V_118 )
{
struct V_2 * V_3 = V_46 -> V_47 ;
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_49 * V_49 ;
int V_51 , V_52 , V_5 , V_107 ;
unsigned long V_64 ;
T_1 V_54 ;
T_2 V_37 , V_65 ;
F_16 ( V_3 -> V_33 , L_11 ,
V_46 -> V_17 , V_68 , V_118 ) ;
if ( V_11 -> type == V_108 )
return V_118 ? - V_18 : 0 ;
V_11 -> V_110 ( V_46 , V_68 , & V_49 , & V_51 , & V_54 ) ;
switch ( V_11 -> type ) {
case V_111 :
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_37 ( V_54 + 16 ) ;
if ( V_118 == V_109 )
V_37 |= F_37 ( V_54 ) ;
V_52 = F_40 ( V_49 , V_51 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_107 = V_46 -> V_107 [ V_68 / 8 ] ;
V_52 = - V_18 ;
for ( V_5 = 0 ; V_5 < F_36 ( V_117 [ V_107 ] ) ;
V_5 ++ ) {
if ( V_117 [ V_107 ] [ V_5 ] == V_118 ) {
V_52 = V_5 ;
break;
}
}
if ( V_52 < 0 ) {
F_10 ( V_3 -> V_33 , L_12 ,
V_118 ) ;
return V_52 ;
}
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = ( ( 1 << V_75 ) - 1 ) << ( V_54 + 16 ) ;
V_65 = V_37 | ( V_37 >> 16 ) ;
V_37 |= ( V_52 << V_54 ) ;
V_52 = F_22 ( V_49 , V_51 , V_65 , V_37 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
break;
default:
F_10 ( V_3 -> V_33 , L_10 ) ;
return - V_18 ;
}
return V_52 ;
}
static int F_41 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_119 ;
}
static const char * F_42 ( struct V_19 * V_20 ,
unsigned V_21 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
return V_3 -> V_120 [ V_21 ] . V_4 ;
}
static int F_43 ( struct V_19 * V_20 ,
unsigned V_21 , const char * const * * V_7 ,
unsigned * const V_121 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
* V_7 = V_3 -> V_120 [ V_21 ] . V_7 ;
* V_121 = V_3 -> V_120 [ V_21 ] . V_6 ;
return 0 ;
}
static int F_44 ( struct V_19 * V_20 , unsigned V_21 ,
unsigned V_40 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
const unsigned int * V_22 = V_3 -> V_7 [ V_40 ] . V_22 ;
const struct V_122 * V_37 = V_3 -> V_7 [ V_40 ] . V_37 ;
struct V_8 * V_46 ;
int V_123 , V_52 = 0 ;
F_16 ( V_3 -> V_33 , L_13 ,
V_3 -> V_120 [ V_21 ] . V_4 , V_3 -> V_7 [ V_40 ] . V_4 ) ;
for ( V_123 = 0 ; V_123 < V_3 -> V_7 [ V_40 ] . V_23 ; V_123 ++ ) {
V_46 = F_2 ( V_3 , V_22 [ V_123 ] ) ;
V_52 = F_20 ( V_46 , V_22 [ V_123 ] - V_46 -> V_13 ,
V_37 [ V_123 ] . V_124 ) ;
if ( V_52 )
break;
}
if ( V_52 ) {
for ( V_123 -- ; V_123 >= 0 ; V_123 -- )
F_20 ( V_46 , V_22 [ V_123 ] - V_46 -> V_13 , 0 ) ;
return V_52 ;
}
return 0 ;
}
static int F_45 ( struct V_125 * V_126 , unsigned V_63 )
{
struct V_8 * V_46 = F_46 ( V_126 ) ;
T_2 V_37 ;
V_37 = F_47 ( V_46 -> V_127 + V_128 ) ;
return ! ( V_37 & F_37 ( V_63 ) ) ;
}
static int F_48 ( struct V_125 * V_126 ,
int V_9 , bool V_129 )
{
struct V_8 * V_46 ;
int V_52 ;
unsigned long V_64 ;
T_2 V_37 ;
V_46 = F_46 ( V_126 ) ;
V_52 = F_20 ( V_46 , V_9 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
F_49 ( V_46 -> V_130 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_47 ( V_46 -> V_127 + V_128 ) ;
if ( ! V_129 )
V_37 |= F_37 ( V_9 ) ;
else
V_37 &= ~ F_37 ( V_9 ) ;
F_50 ( V_37 , V_46 -> V_127 + V_128 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_51 ( V_46 -> V_130 ) ;
return 0 ;
}
static int F_52 ( struct V_19 * V_20 ,
struct V_131 * V_132 ,
unsigned V_63 , bool V_129 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_125 * V_126 ;
int V_9 ;
V_126 = V_132 -> V_133 ;
V_9 = V_63 - V_126 -> V_134 ;
F_16 ( V_3 -> V_33 , L_14 ,
V_63 , V_132 -> V_4 , V_9 , V_129 ? L_15 : L_16 ) ;
return F_48 ( V_126 , V_63 - V_126 -> V_134 ,
V_129 ) ;
}
static bool F_53 ( struct V_97 * V_11 ,
enum V_135 V_118 )
{
switch ( V_11 -> type ) {
case V_111 :
return ( V_118 == V_112 ||
V_118 == V_109 ) ;
case V_108 :
return V_118 ? false : true ;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
return ( V_118 != V_112 ) ;
}
return false ;
}
static int F_54 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_42 , unsigned V_44 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_135 V_136 ;
T_3 V_137 ;
int V_5 ;
int V_138 ;
for ( V_5 = 0 ; V_5 < V_44 ; V_5 ++ ) {
V_136 = F_55 ( V_42 [ V_5 ] ) ;
V_137 = F_56 ( V_42 [ V_5 ] ) ;
switch ( V_136 ) {
case V_109 :
V_138 = F_39 ( V_46 , V_9 - V_46 -> V_13 ,
V_136 ) ;
if ( V_138 )
return V_138 ;
break;
case V_139 :
case V_140 :
case V_112 :
case V_141 :
if ( ! F_53 ( V_3 -> V_11 , V_136 ) )
return - V_66 ;
if ( ! V_137 )
return - V_18 ;
V_138 = F_39 ( V_46 , V_9 - V_46 -> V_13 ,
V_136 ) ;
if ( V_138 )
return V_138 ;
break;
case V_142 :
F_57 ( & V_46 -> V_125 ,
V_9 - V_46 -> V_13 , V_137 ) ;
V_138 = F_48 ( & V_46 -> V_125 ,
V_9 - V_46 -> V_13 , false ) ;
if ( V_138 )
return V_138 ;
break;
case V_143 :
if ( ! V_3 -> V_11 -> V_100 )
return - V_66 ;
V_138 = F_35 ( V_46 ,
V_9 - V_46 -> V_13 , V_137 ) ;
if ( V_138 < 0 )
return V_138 ;
break;
default:
return - V_66 ;
break;
}
}
return 0 ;
}
static int F_58 ( struct V_19 * V_20 , unsigned int V_9 ,
unsigned long * V_144 )
{
struct V_2 * V_3 = F_6 ( V_20 ) ;
struct V_8 * V_46 = F_2 ( V_3 , V_9 ) ;
enum V_135 V_136 = F_55 ( * V_144 ) ;
T_3 V_137 ;
int V_138 ;
switch ( V_136 ) {
case V_109 :
if ( F_38 ( V_46 , V_9 - V_46 -> V_13 ) != V_136 )
return - V_18 ;
V_137 = 0 ;
break;
case V_139 :
case V_140 :
case V_112 :
case V_141 :
if ( ! F_53 ( V_3 -> V_11 , V_136 ) )
return - V_66 ;
if ( F_38 ( V_46 , V_9 - V_46 -> V_13 ) != V_136 )
return - V_18 ;
V_137 = 1 ;
break;
case V_142 :
V_138 = F_18 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_138 != V_58 )
return - V_18 ;
V_138 = F_59 ( & V_46 -> V_125 , V_9 - V_46 -> V_13 ) ;
if ( V_138 < 0 )
return V_138 ;
V_137 = V_138 ? 1 : 0 ;
break;
case V_143 :
if ( ! V_3 -> V_11 -> V_100 )
return - V_66 ;
V_138 = F_34 ( V_46 , V_9 - V_46 -> V_13 ) ;
if ( V_138 < 0 )
return V_138 ;
V_137 = V_138 ;
break;
default:
return - V_66 ;
break;
}
* V_144 = F_60 ( V_136 , V_137 ) ;
return 0 ;
}
static void F_61 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_24 * V_145 ;
F_62 (np, child) {
if ( F_63 ( V_146 , V_145 ) )
continue;
V_3 -> V_119 ++ ;
V_3 -> V_6 += F_64 ( V_145 ) ;
}
}
static int F_65 ( struct V_24 * V_25 ,
struct V_1 * V_29 ,
struct V_2 * V_3 ,
T_2 V_147 )
{
struct V_8 * V_46 ;
int V_148 ;
const T_4 * V_149 ;
int V_15 ;
int V_5 , V_150 ;
int V_52 ;
F_16 ( V_3 -> V_33 , L_17 , V_147 , V_25 -> V_4 ) ;
V_29 -> V_4 = V_25 -> V_4 ;
V_149 = F_66 ( V_25 , L_18 , & V_148 ) ;
V_148 /= sizeof( * V_149 ) ;
if ( ! V_148 || V_148 % 4 ) {
F_10 ( V_3 -> V_33 , L_19 ) ;
return - V_18 ;
}
V_29 -> V_23 = V_148 / 4 ;
V_29 -> V_22 = F_11 ( V_3 -> V_33 , V_29 -> V_23 * sizeof( unsigned int ) ,
V_34 ) ;
V_29 -> V_37 = F_11 ( V_3 -> V_33 , V_29 -> V_23 *
sizeof( struct V_122 ) ,
V_34 ) ;
if ( ! V_29 -> V_22 || ! V_29 -> V_37 )
return - V_35 ;
for ( V_5 = 0 , V_150 = 0 ; V_5 < V_148 ; V_5 += 4 , V_150 ++ ) {
const T_4 * V_151 ;
struct V_24 * V_152 ;
V_15 = F_67 ( * V_149 ++ ) ;
V_46 = F_3 ( V_3 , V_15 ) ;
if ( F_68 ( V_46 ) )
return F_69 ( V_46 ) ;
V_29 -> V_22 [ V_150 ] = V_46 -> V_13 + F_67 ( * V_149 ++ ) ;
V_29 -> V_37 [ V_150 ] . V_124 = F_67 ( * V_149 ++ ) ;
V_151 = V_149 ++ ;
if ( ! V_151 )
return - V_18 ;
V_152 = F_70 ( F_71 ( V_151 ) ) ;
V_52 = F_72 ( V_152 , NULL ,
& V_29 -> V_37 [ V_150 ] . V_42 , & V_29 -> V_37 [ V_150 ] . V_45 ) ;
if ( V_52 )
return V_52 ;
}
return 0 ;
}
static int F_73 ( struct V_24 * V_25 ,
struct V_2 * V_3 ,
T_2 V_147 )
{
struct V_24 * V_145 ;
struct V_153 * V_124 ;
struct V_1 * V_29 ;
int V_52 ;
static T_2 V_154 ;
T_2 V_5 = 0 ;
F_16 ( V_3 -> V_33 , L_20 , V_147 , V_25 -> V_4 ) ;
V_124 = & V_3 -> V_120 [ V_147 ] ;
V_124 -> V_4 = V_25 -> V_4 ;
V_124 -> V_6 = F_64 ( V_25 ) ;
if ( V_124 -> V_6 <= 0 )
return 0 ;
V_124 -> V_7 = F_11 ( V_3 -> V_33 ,
V_124 -> V_6 * sizeof( char * ) , V_34 ) ;
if ( ! V_124 -> V_7 )
return - V_35 ;
F_62 (np, child) {
V_124 -> V_7 [ V_5 ] = V_145 -> V_4 ;
V_29 = & V_3 -> V_7 [ V_154 ++ ] ;
V_52 = F_65 ( V_145 , V_29 , V_3 , V_5 ++ ) ;
if ( V_52 ) {
F_14 ( V_145 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_74 ( struct V_155 * V_156 ,
struct V_2 * V_3 )
{
struct V_157 * V_33 = & V_156 -> V_33 ;
struct V_24 * V_25 = V_33 -> V_158 ;
struct V_24 * V_145 ;
int V_52 ;
int V_5 ;
F_61 ( V_3 , V_25 ) ;
F_16 ( & V_156 -> V_33 , L_21 , V_3 -> V_119 ) ;
F_16 ( & V_156 -> V_33 , L_22 , V_3 -> V_6 ) ;
V_3 -> V_120 = F_11 ( V_33 , V_3 -> V_119 *
sizeof( struct V_153 ) ,
V_34 ) ;
if ( ! V_3 -> V_120 ) {
F_10 ( V_33 , L_23 ) ;
return - V_18 ;
}
V_3 -> V_7 = F_11 ( V_33 , V_3 -> V_6 *
sizeof( struct V_1 ) ,
V_34 ) ;
if ( ! V_3 -> V_7 ) {
F_10 ( V_33 , L_24 ) ;
return - V_18 ;
}
V_5 = 0 ;
F_62 (np, child) {
if ( F_63 ( V_146 , V_145 ) )
continue;
V_52 = F_73 ( V_145 , V_3 , V_5 ++ ) ;
if ( V_52 ) {
F_10 ( & V_156 -> V_33 , L_25 ) ;
F_14 ( V_145 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_75 ( struct V_155 * V_156 ,
struct V_2 * V_3 )
{
struct V_159 * V_160 = & V_3 -> V_161 ;
struct V_162 * V_163 , * V_164 ;
struct V_8 * V_165 ;
int V_9 , V_46 , V_52 ;
int V_166 ;
V_160 -> V_4 = L_26 ;
V_160 -> V_167 = V_168 ;
V_160 -> V_169 = & V_170 ;
V_160 -> V_171 = & V_172 ;
V_160 -> V_173 = & V_174 ;
V_163 = F_11 ( & V_156 -> V_33 , sizeof( * V_163 ) *
V_3 -> V_11 -> V_14 , V_34 ) ;
if ( ! V_163 ) {
F_10 ( & V_156 -> V_33 , L_27 ) ;
return - V_35 ;
}
V_160 -> V_22 = V_163 ;
V_160 -> V_23 = V_3 -> V_11 -> V_14 ;
V_164 = V_163 ;
for ( V_46 = 0 , V_166 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; V_46 ++ ) {
V_165 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
for ( V_9 = 0 ; V_9 < V_165 -> V_14 ; V_9 ++ , V_166 ++ ) {
V_164 -> V_175 = V_166 ;
V_164 -> V_4 = F_76 ( V_34 , L_28 ,
V_165 -> V_4 , V_9 ) ;
V_164 ++ ;
}
}
V_52 = F_74 ( V_156 , V_3 ) ;
if ( V_52 )
return V_52 ;
V_3 -> V_176 = F_77 ( & V_156 -> V_33 , V_160 , V_3 ) ;
if ( F_68 ( V_3 -> V_176 ) ) {
F_10 ( & V_156 -> V_33 , L_29 ) ;
return F_69 ( V_3 -> V_176 ) ;
}
for ( V_46 = 0 ; V_46 < V_3 -> V_11 -> V_16 ; ++ V_46 ) {
V_165 = & V_3 -> V_11 -> V_12 [ V_46 ] ;
V_165 -> V_177 . V_4 = V_165 -> V_4 ;
V_165 -> V_177 . V_178 = V_46 ;
V_165 -> V_177 . V_13 = V_165 -> V_13 ;
V_165 -> V_177 . V_134 = V_165 -> V_125 . V_134 ;
V_165 -> V_177 . V_23 = V_165 -> V_125 . V_179 ;
V_165 -> V_177 . V_133 = & V_165 -> V_125 ;
F_78 ( V_3 -> V_176 , & V_165 -> V_177 ) ;
}
return 0 ;
}
static void F_57 ( struct V_125 * V_133 , unsigned V_63 , int V_180 )
{
struct V_8 * V_46 = F_46 ( V_133 ) ;
void T_5 * V_51 = V_46 -> V_127 + V_181 ;
unsigned long V_64 ;
T_2 V_37 ;
F_49 ( V_46 -> V_130 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_79 ( V_51 ) ;
V_37 &= ~ F_37 ( V_63 ) ;
if ( V_180 )
V_37 |= F_37 ( V_63 ) ;
F_80 ( V_37 , V_51 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_51 ( V_46 -> V_130 ) ;
}
static int F_59 ( struct V_125 * V_133 , unsigned V_63 )
{
struct V_8 * V_46 = F_46 ( V_133 ) ;
T_2 V_37 ;
F_49 ( V_46 -> V_130 ) ;
V_37 = F_79 ( V_46 -> V_127 + V_182 ) ;
F_51 ( V_46 -> V_130 ) ;
V_37 >>= V_63 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_81 ( struct V_125 * V_133 , unsigned V_63 )
{
return F_82 ( V_133 -> V_134 + V_63 ) ;
}
static int F_83 ( struct V_125 * V_133 ,
unsigned V_63 , int V_180 )
{
F_57 ( V_133 , V_63 , V_180 ) ;
return F_84 ( V_133 -> V_134 + V_63 ) ;
}
static int F_85 ( struct V_125 * V_133 , unsigned V_63 )
{
struct V_8 * V_46 = F_46 ( V_133 ) ;
unsigned int V_183 ;
if ( ! V_46 -> V_184 )
return - V_185 ;
V_183 = F_86 ( V_46 -> V_184 , V_63 ) ;
return ( V_183 ) ? : - V_185 ;
}
static void F_87 ( struct V_186 * V_187 )
{
struct V_188 * V_126 = F_88 ( V_187 ) ;
struct V_8 * V_46 = F_89 ( V_187 ) ;
T_2 V_189 ;
F_16 ( V_46 -> V_47 -> V_33 , L_30 , V_46 -> V_4 ) ;
F_90 ( V_126 , V_187 ) ;
V_189 = F_47 ( V_46 -> V_127 + V_190 ) ;
while ( V_189 ) {
unsigned int V_191 , V_183 ;
V_191 = F_91 ( V_189 ) ;
V_189 &= ~ F_37 ( V_191 ) ;
V_183 = F_92 ( V_46 -> V_184 , V_191 ) ;
if ( ! V_183 ) {
F_10 ( V_46 -> V_47 -> V_33 , L_31 , V_191 ) ;
continue;
}
F_16 ( V_46 -> V_47 -> V_33 , L_32 , V_191 ) ;
if ( V_46 -> V_192 & F_37 ( V_191 ) ) {
T_2 V_37 , V_193 , V_194 ;
unsigned long V_64 ;
V_37 = F_47 ( V_46 -> V_127 + V_182 ) ;
do {
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_194 = F_47 ( V_46 -> V_127 +
V_195 ) ;
if ( V_37 & F_37 ( V_191 ) )
V_194 &= ~ F_37 ( V_191 ) ;
else
V_194 |= F_37 ( V_191 ) ;
F_80 ( V_194 ,
V_46 -> V_127 + V_195 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
V_193 = V_37 ;
V_37 = F_47 ( V_46 -> V_127 +
V_182 ) ;
} while ( ( V_37 & F_37 ( V_191 ) ) != ( V_193 & F_37 ( V_191 ) ) );
}
F_93 ( V_183 ) ;
}
F_94 ( V_126 , V_187 ) ;
}
static int F_95 ( struct V_196 * V_197 , unsigned int type )
{
struct V_198 * V_133 = F_96 ( V_197 ) ;
struct V_8 * V_46 = V_133 -> V_199 ;
T_2 V_53 = F_37 ( V_197 -> V_200 ) ;
T_2 V_194 ;
T_2 V_201 ;
T_2 V_37 ;
unsigned long V_64 ;
int V_52 ;
V_52 = F_20 ( V_46 , V_197 -> V_200 , V_58 ) ;
if ( V_52 < 0 )
return V_52 ;
F_49 ( V_46 -> V_130 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
V_37 = F_47 ( V_46 -> V_127 + V_128 ) ;
V_37 &= ~ V_53 ;
F_50 ( V_37 , V_46 -> V_127 + V_128 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
if ( type & V_202 )
F_97 ( V_197 , V_203 ) ;
else
F_97 ( V_197 , V_204 ) ;
F_21 ( & V_46 -> V_67 , V_64 ) ;
F_98 ( V_133 ) ;
V_201 = F_47 ( V_133 -> V_127 + V_205 ) ;
V_194 = F_47 ( V_133 -> V_127 + V_195 ) ;
switch ( type ) {
case V_202 :
V_46 -> V_192 |= V_53 ;
V_201 |= V_53 ;
V_37 = F_79 ( V_46 -> V_127 + V_182 ) ;
if ( V_37 & V_53 )
V_194 &= ~ V_53 ;
else
V_194 |= V_53 ;
break;
case V_206 :
V_46 -> V_192 &= ~ V_53 ;
V_201 |= V_53 ;
V_194 |= V_53 ;
break;
case V_207 :
V_46 -> V_192 &= ~ V_53 ;
V_201 |= V_53 ;
V_194 &= ~ V_53 ;
break;
case V_208 :
V_46 -> V_192 &= ~ V_53 ;
V_201 &= ~ V_53 ;
V_194 |= V_53 ;
break;
case V_209 :
V_46 -> V_192 &= ~ V_53 ;
V_201 &= ~ V_53 ;
V_194 &= ~ V_53 ;
break;
default:
F_99 ( V_133 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_51 ( V_46 -> V_130 ) ;
return - V_18 ;
}
F_50 ( V_201 , V_133 -> V_127 + V_205 ) ;
F_50 ( V_194 , V_133 -> V_127 + V_195 ) ;
F_99 ( V_133 ) ;
F_23 ( & V_46 -> V_67 , V_64 ) ;
F_51 ( V_46 -> V_130 ) ;
return 0 ;
}
static void F_100 ( struct V_196 * V_197 )
{
struct V_198 * V_133 = F_96 ( V_197 ) ;
struct V_8 * V_46 = V_133 -> V_199 ;
F_49 ( V_46 -> V_130 ) ;
V_46 -> V_210 = F_101 ( V_133 , V_211 ) ;
F_102 ( V_133 , ~ V_133 -> V_212 , V_211 ) ;
F_51 ( V_46 -> V_130 ) ;
}
static void F_103 ( struct V_196 * V_197 )
{
struct V_198 * V_133 = F_96 ( V_197 ) ;
struct V_8 * V_46 = V_133 -> V_199 ;
F_49 ( V_46 -> V_130 ) ;
F_102 ( V_133 , V_46 -> V_210 , V_211 ) ;
F_51 ( V_46 -> V_130 ) ;
}
static void F_104 ( struct V_196 * V_197 )
{
struct V_198 * V_133 = F_96 ( V_197 ) ;
struct V_8 * V_46 = V_133 -> V_199 ;
F_49 ( V_46 -> V_130 ) ;
F_105 ( V_197 ) ;
}
static void F_106 ( struct V_196 * V_197 )
{
struct V_198 * V_133 = F_96 ( V_197 ) ;
struct V_8 * V_46 = V_133 -> V_199 ;
F_107 ( V_197 ) ;
F_51 ( V_46 -> V_130 ) ;
}
static int F_108 ( struct V_155 * V_156 ,
struct V_2 * V_3 )
{
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
unsigned int V_213 = V_214 | V_215 | V_216 ;
struct V_198 * V_133 ;
int V_52 ;
int V_5 , V_150 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_217 ) {
F_109 ( & V_156 -> V_33 , L_33 ,
V_46 -> V_4 ) ;
continue;
}
V_52 = F_49 ( V_46 -> V_130 ) ;
if ( V_52 ) {
F_10 ( & V_156 -> V_33 , L_34 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_184 = F_110 ( V_46 -> V_158 , 32 ,
& V_218 , NULL ) ;
if ( ! V_46 -> V_184 ) {
F_109 ( & V_156 -> V_33 , L_35 ,
V_46 -> V_4 ) ;
F_51 ( V_46 -> V_130 ) ;
continue;
}
V_52 = F_111 ( V_46 -> V_184 , 32 , 1 ,
L_36 , V_204 ,
V_213 , 0 , V_219 ) ;
if ( V_52 ) {
F_10 ( & V_156 -> V_33 , L_37 ,
V_46 -> V_4 ) ;
F_112 ( V_46 -> V_184 ) ;
F_51 ( V_46 -> V_130 ) ;
continue;
}
F_50 ( 0xffffffff , V_46 -> V_127 + V_211 ) ;
F_50 ( 0xffffffff , V_46 -> V_127 + V_220 ) ;
V_133 = F_113 ( V_46 -> V_184 , 0 ) ;
V_133 -> V_127 = V_46 -> V_127 ;
V_133 -> V_199 = V_46 ;
V_133 -> V_221 [ 0 ] . V_222 . V_53 = V_211 ;
V_133 -> V_221 [ 0 ] . V_222 . V_223 = V_224 ;
V_133 -> V_221 [ 0 ] . V_126 . V_225 = V_226 ;
V_133 -> V_221 [ 0 ] . V_126 . V_227 = F_106 ;
V_133 -> V_221 [ 0 ] . V_126 . V_228 =
F_104 ;
V_133 -> V_221 [ 0 ] . V_126 . V_229 = V_230 ;
V_133 -> V_221 [ 0 ] . V_126 . V_231 = F_100 ;
V_133 -> V_221 [ 0 ] . V_126 . V_232 = F_103 ;
V_133 -> V_221 [ 0 ] . V_126 . V_233 = F_95 ;
V_133 -> V_234 = F_114 ( V_46 -> V_14 ) ;
F_115 ( V_46 -> V_191 ,
F_87 , V_46 ) ;
for ( V_150 = 0 ; V_150 < 32 ; V_150 ++ )
F_86 ( V_46 -> V_184 , V_150 ) ;
F_51 ( V_46 -> V_130 ) ;
}
return 0 ;
}
static int F_116 ( struct V_155 * V_156 ,
struct V_2 * V_3 )
{
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
struct V_125 * V_133 ;
int V_52 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_217 ) {
F_109 ( & V_156 -> V_33 , L_33 ,
V_46 -> V_4 ) ;
continue;
}
V_46 -> V_125 = V_235 ;
V_133 = & V_46 -> V_125 ;
V_133 -> V_134 = V_46 -> V_13 ;
V_133 -> V_179 = V_46 -> V_14 ;
V_133 -> V_31 = & V_156 -> V_33 ;
V_133 -> V_158 = V_46 -> V_158 ;
V_133 -> V_236 = V_46 -> V_4 ;
V_52 = F_117 ( V_133 , V_46 ) ;
if ( V_52 ) {
F_10 ( & V_156 -> V_33 , L_38 ,
V_133 -> V_236 , V_52 ) ;
goto V_237;
}
}
F_108 ( V_156 , V_3 ) ;
return 0 ;
V_237:
for ( -- V_5 , -- V_46 ; V_5 >= 0 ; -- V_5 , -- V_46 ) {
if ( ! V_46 -> V_217 )
continue;
F_118 ( & V_46 -> V_125 ) ;
}
return V_52 ;
}
static int F_119 ( struct V_155 * V_156 ,
struct V_2 * V_3 )
{
struct V_97 * V_11 = V_3 -> V_11 ;
struct V_8 * V_46 = V_11 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! V_46 -> V_217 )
continue;
F_118 ( & V_46 -> V_125 ) ;
}
return 0 ;
}
static int F_120 ( struct V_8 * V_46 ,
struct V_2 * V_3 )
{
struct V_238 V_239 ;
void T_5 * V_134 ;
if ( F_121 ( V_46 -> V_158 , 0 , & V_239 ) ) {
F_10 ( V_3 -> V_33 , L_39 ) ;
return - V_240 ;
}
V_46 -> V_127 = F_122 ( V_3 -> V_33 , & V_239 ) ;
if ( F_68 ( V_46 -> V_127 ) )
return F_69 ( V_46 -> V_127 ) ;
if ( F_123 ( V_46 -> V_158 ,
L_40 ) ) {
struct V_24 * V_241 ;
V_241 = F_124 ( V_46 -> V_158 -> V_31 ,
L_41 , 0 ) ;
if ( ! V_241 ) {
if ( F_121 ( V_46 -> V_158 , 1 , & V_239 ) ) {
F_10 ( V_3 -> V_33 , L_39 ) ;
return - V_240 ;
}
V_134 = F_122 ( V_3 -> V_33 , & V_239 ) ;
if ( F_68 ( V_134 ) )
return F_69 ( V_134 ) ;
V_242 . V_243 =
F_125 ( & V_239 ) - 4 ;
V_242 . V_4 =
L_42 ;
V_46 -> V_72 = F_126 ( V_3 -> V_33 ,
V_134 ,
& V_242 ) ;
}
}
V_46 -> V_191 = F_127 ( V_46 -> V_158 , 0 ) ;
V_46 -> V_130 = F_128 ( V_46 -> V_158 , 0 ) ;
if ( F_68 ( V_46 -> V_130 ) )
return F_69 ( V_46 -> V_130 ) ;
return F_129 ( V_46 -> V_130 ) ;
}
static struct V_97 * F_130 (
struct V_2 * V_197 ,
struct V_155 * V_156 )
{
const struct V_244 * V_245 ;
struct V_24 * V_241 = V_156 -> V_33 . V_158 ;
struct V_24 * V_25 ;
struct V_97 * V_11 ;
struct V_8 * V_46 ;
int V_246 , V_247 , V_248 , V_249 , V_5 , V_150 ;
V_245 = F_63 ( V_250 , V_241 ) ;
V_11 = (struct V_97 * ) V_245 -> V_37 ;
F_62 (node, np) {
if ( ! F_131 ( V_25 , L_43 , NULL ) )
continue;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
if ( ! strcmp ( V_46 -> V_4 , V_25 -> V_4 ) ) {
V_46 -> V_158 = V_25 ;
if ( ! F_120 ( V_46 , V_197 ) )
V_46 -> V_217 = true ;
break;
}
}
}
V_246 = V_11 -> V_251 ;
V_247 = V_11 -> V_252 ;
V_249 = V_11 -> V_253 ;
V_248 = V_11 -> V_254 ;
V_46 = V_11 -> V_12 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_16 ; ++ V_5 , ++ V_46 ) {
int V_255 = 0 ;
F_132 ( & V_46 -> V_67 ) ;
V_46 -> V_47 = V_197 ;
V_46 -> V_13 = V_11 -> V_14 ;
V_11 -> V_14 += V_46 -> V_14 ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
struct V_256 * V_257 = & V_46 -> V_55 [ V_150 ] ;
struct V_258 * V_93 = & V_46 -> V_93 [ V_150 ] ;
int V_259 ;
if ( V_255 >= V_46 -> V_14 )
break;
if ( V_257 -> V_63 >= 0 ) {
if ( V_257 -> type & V_59 )
V_247 = V_257 -> V_63 ;
else
V_246 = V_257 -> V_63 ;
} else {
V_257 -> V_63 = ( V_257 -> type & V_59 ) ?
V_247 : V_246 ;
}
if ( V_93 -> V_63 >= 0 ) {
if ( V_257 -> type & V_59 )
V_249 = V_93 -> V_63 ;
else
V_248 = V_93 -> V_63 ;
} else {
V_93 -> V_63 = ( V_257 -> type & V_59 ) ?
V_249 : V_248 ;
}
F_16 ( V_197 -> V_33 , L_44 ,
V_5 , V_150 , V_257 -> V_63 , V_93 -> V_63 ) ;
V_259 = ( V_257 -> type & V_62 ) ? 8 : 4 ;
if ( V_257 -> type & V_59 )
V_247 += V_259 ;
else
V_246 += V_259 ;
if ( ( V_93 -> V_94 == V_95 ) ||
( V_93 -> V_94 == V_96 ) )
V_259 = 8 ;
else
V_259 = 4 ;
if ( V_257 -> type & V_59 )
V_249 += V_259 ;
else
V_248 += V_259 ;
V_255 += 8 ;
}
}
return V_11 ;
}
static int T_6 F_133 ( struct V_157 * V_33 )
{
struct V_2 * V_3 = F_134 ( V_33 ) ;
int V_52 = F_135 ( V_3 -> V_176 ) ;
if ( V_52 )
return V_52 ;
if ( V_3 -> V_11 -> type == V_114 ) {
V_52 = F_19 ( V_3 -> V_61 , V_260 ,
& V_261 ) ;
if ( V_52 ) {
F_136 ( V_3 -> V_176 ) ;
return V_52 ;
}
}
return 0 ;
}
static int T_6 F_137 ( struct V_157 * V_33 )
{
struct V_2 * V_3 = F_134 ( V_33 ) ;
int V_52 = F_40 ( V_3 -> V_61 , V_260 ,
V_261 |
V_262 ) ;
if ( V_52 )
return V_52 ;
return F_136 ( V_3 -> V_176 ) ;
}
static int F_138 ( struct V_155 * V_156 )
{
struct V_2 * V_3 ;
struct V_157 * V_33 = & V_156 -> V_33 ;
struct V_97 * V_11 ;
struct V_24 * V_25 = V_156 -> V_33 . V_158 , * V_241 ;
struct V_238 * V_239 ;
void T_5 * V_134 ;
int V_52 ;
if ( ! V_33 -> V_158 ) {
F_10 ( V_33 , L_45 ) ;
return - V_263 ;
}
V_3 = F_11 ( V_33 , sizeof( struct V_2 ) , V_34 ) ;
if ( ! V_3 )
return - V_35 ;
V_3 -> V_33 = V_33 ;
V_11 = F_130 ( V_3 , V_156 ) ;
if ( ! V_11 ) {
F_10 ( V_33 , L_46 ) ;
return - V_18 ;
}
V_3 -> V_11 = V_11 ;
V_241 = F_124 ( V_25 , L_47 , 0 ) ;
if ( V_241 ) {
V_3 -> V_61 = F_139 ( V_241 ) ;
if ( F_68 ( V_3 -> V_61 ) )
return F_69 ( V_3 -> V_61 ) ;
} else {
V_239 = F_140 ( V_156 , V_264 , 0 ) ;
V_134 = F_122 ( & V_156 -> V_33 , V_239 ) ;
if ( F_68 ( V_134 ) )
return F_69 ( V_134 ) ;
V_242 . V_243 = F_125 ( V_239 ) - 4 ;
V_242 . V_4 = L_48 ;
V_3 -> V_61 = F_126 ( & V_156 -> V_33 , V_134 ,
& V_242 ) ;
V_3 -> V_265 = F_125 ( V_239 ) ;
if ( V_11 -> type == V_113 && V_3 -> V_265 < 0x200 ) {
V_239 = F_140 ( V_156 , V_264 , 1 ) ;
V_134 = F_122 ( & V_156 -> V_33 , V_239 ) ;
if ( F_68 ( V_134 ) )
return F_69 ( V_134 ) ;
V_242 . V_243 =
F_125 ( V_239 ) - 4 ;
V_242 . V_4 = L_49 ;
V_3 -> V_72 = F_126 ( & V_156 -> V_33 ,
V_134 ,
& V_242 ) ;
}
}
V_241 = F_124 ( V_25 , L_41 , 0 ) ;
if ( V_241 ) {
V_3 -> V_60 = F_139 ( V_241 ) ;
if ( F_68 ( V_3 -> V_60 ) )
return F_69 ( V_3 -> V_60 ) ;
}
V_52 = F_116 ( V_156 , V_3 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_75 ( V_156 , V_3 ) ;
if ( V_52 ) {
F_119 ( V_156 , V_3 ) ;
return V_52 ;
}
F_141 ( V_156 , V_3 ) ;
return 0 ;
}
static int T_7 F_142 ( void )
{
return F_143 ( & V_266 ) ;
}
