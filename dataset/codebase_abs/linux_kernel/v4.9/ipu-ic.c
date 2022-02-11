static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_6 , unsigned V_3 )
{
F_4 ( V_6 , V_2 -> V_4 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_7 V_8 ,
enum V_7 V_9 ,
int V_10 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
const struct V_12 * V_13 ;
T_1 T_2 * V_5 ;
const F_6 ( * V_14 ) [ 3 ] ;
const F_6 * V_15 ;
T_1 V_16 ;
V_5 = ( T_1 T_2 * )
( V_4 -> V_17 + V_2 -> V_18 -> V_19 [ V_10 ] ) ;
if ( V_8 == V_20 && V_9 == V_21 )
V_13 = & V_22 ;
else if ( V_8 == V_21 && V_9 == V_20 )
V_13 = & V_23 ;
else if ( V_8 == V_21 && V_9 == V_21 )
V_13 = & V_24 ;
else {
F_7 ( V_4 -> V_25 -> V_26 , L_1 ) ;
return - V_27 ;
}
V_14 = ( const F_6 ( * ) [ 3 ] ) V_13 -> V_28 ;
V_15 = ( const F_6 * ) V_13 -> V_3 ;
V_16 = ( ( V_15 [ 0 ] & 0x1f ) << 27 ) | ( ( V_14 [ 0 ] [ 0 ] & 0x1ff ) << 18 ) |
( ( V_14 [ 1 ] [ 1 ] & 0x1ff ) << 9 ) | ( V_14 [ 2 ] [ 2 ] & 0x1ff ) ;
F_4 ( V_16 , V_5 ++ ) ;
V_16 = ( ( V_15 [ 0 ] & 0x1fe0 ) >> 5 ) | ( V_13 -> V_29 << 8 ) |
( V_13 -> V_30 << 9 ) ;
F_4 ( V_16 , V_5 ++ ) ;
V_16 = ( ( V_15 [ 1 ] & 0x1f ) << 27 ) | ( ( V_14 [ 0 ] [ 1 ] & 0x1ff ) << 18 ) |
( ( V_14 [ 1 ] [ 0 ] & 0x1ff ) << 9 ) | ( V_14 [ 2 ] [ 0 ] & 0x1ff ) ;
F_4 ( V_16 , V_5 ++ ) ;
V_16 = ( ( V_15 [ 1 ] & 0x1fe0 ) >> 5 ) ;
F_4 ( V_16 , V_5 ++ ) ;
V_16 = ( ( V_15 [ 2 ] & 0x1f ) << 27 ) | ( ( V_14 [ 0 ] [ 2 ] & 0x1ff ) << 18 ) |
( ( V_14 [ 1 ] [ 2 ] & 0x1ff ) << 9 ) | ( V_14 [ 2 ] [ 1 ] & 0x1ff ) ;
F_4 ( V_16 , V_5 ++ ) ;
V_16 = ( ( V_15 [ 2 ] & 0x1fe0 ) >> 5 ) ;
F_4 ( V_16 , V_5 ++ ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_31 , T_1 V_32 ,
T_1 * V_33 ,
T_1 * V_34 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
struct V_35 * V_25 = V_4 -> V_25 ;
T_1 V_36 , V_37 ;
if ( V_31 > 4096 ) {
F_7 ( V_25 -> V_26 , L_2 ) ;
return - V_27 ;
}
if ( V_32 > 1024 ) {
F_7 ( V_25 -> V_26 , L_3 ) ;
return - V_27 ;
}
if ( ( V_32 << 2 ) < V_31 ) {
F_7 ( V_25 -> V_26 , L_4 ) ;
return - V_27 ;
}
V_37 = 0 ;
V_36 = V_31 ;
while ( ( ( V_36 > 1024 ) || ( V_36 >= V_32 * 2 ) ) &&
( V_37 < 2 ) ) {
V_36 >>= 1 ;
V_37 ++ ;
}
* V_34 = V_37 ;
* V_33 = ( 8192L * ( V_36 - 1 ) ) / ( V_32 - 1 ) ;
if ( * V_33 >= 16384L ) {
F_7 ( V_25 -> V_26 , L_5 ) ;
* V_33 = 0x3FFF ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
unsigned long V_38 ;
T_1 V_39 ;
F_10 ( & V_4 -> V_40 , V_38 ) ;
V_39 = F_1 ( V_2 , V_41 ) ;
V_39 |= V_2 -> V_42 -> V_43 ;
if ( V_2 -> V_44 )
V_39 |= V_2 -> V_42 -> V_45 ;
if ( V_2 -> V_46 != V_2 -> V_47 )
V_39 |= V_2 -> V_42 -> V_48 ;
if ( V_2 -> V_49 ) {
V_39 |= V_2 -> V_42 -> V_50 ;
V_39 |= V_2 -> V_42 -> V_48 ;
if ( V_2 -> V_51 != V_2 -> V_47 )
V_39 |= V_2 -> V_42 -> V_52 ;
}
F_3 ( V_2 , V_39 , V_41 ) ;
F_11 ( & V_4 -> V_40 , V_38 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
unsigned long V_38 ;
T_1 V_39 ;
F_10 ( & V_4 -> V_40 , V_38 ) ;
V_39 = F_1 ( V_2 , V_41 ) ;
V_39 &= ~ ( V_2 -> V_42 -> V_43 |
V_2 -> V_42 -> V_48 |
V_2 -> V_42 -> V_45 ) ;
if ( V_2 -> V_42 -> V_52 )
V_39 &= ~ V_2 -> V_42 -> V_52 ;
if ( V_2 -> V_42 -> V_50 )
V_39 &= ~ V_2 -> V_42 -> V_50 ;
F_3 ( V_2 , V_39 , V_41 ) ;
F_11 ( & V_4 -> V_40 , V_38 ) ;
}
int F_13 ( struct V_1 * V_2 ,
enum V_7 V_53 ,
bool V_54 , T_1 V_55 ,
bool V_56 , T_1 V_57 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
unsigned long V_38 ;
T_1 V_18 , V_39 ;
int V_58 = 0 ;
if ( V_2 -> V_59 == V_60 )
return - V_27 ;
F_10 ( & V_4 -> V_40 , V_38 ) ;
V_39 = F_1 ( V_2 , V_41 ) ;
if ( ! ( V_39 & V_2 -> V_42 -> V_48 ) ) {
V_58 = F_5 ( V_2 , V_21 ,
V_21 , 0 ) ;
if ( V_58 )
goto V_61;
}
V_2 -> V_51 = V_53 ;
if ( V_2 -> V_51 != V_2 -> V_47 ) {
V_58 = F_5 ( V_2 , V_2 -> V_51 , V_2 -> V_47 , 1 ) ;
if ( V_58 )
goto V_61;
}
if ( V_54 ) {
V_39 |= V_62 ;
V_18 = F_1 ( V_2 , V_63 ) ;
V_18 &= ~ ( 0xff << V_2 -> V_42 -> V_64 ) ;
V_18 |= ( V_55 << V_2 -> V_42 -> V_64 ) ;
F_3 ( V_2 , V_18 , V_63 ) ;
} else
V_39 &= ~ V_62 ;
if ( V_56 ) {
V_39 |= V_65 ;
F_3 ( V_2 , V_57 , V_66 ) ;
} else
V_39 &= ~ V_65 ;
F_3 ( V_2 , V_39 , V_41 ) ;
V_2 -> V_49 = true ;
V_61:
F_11 ( & V_4 -> V_40 , V_38 ) ;
return V_58 ;
}
int F_14 ( struct V_1 * V_2 ,
int V_67 , int V_68 ,
int V_69 , int V_70 ,
enum V_7 V_46 ,
enum V_7 V_47 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
T_1 V_18 , V_34 , V_33 ;
unsigned long V_38 ;
int V_58 = 0 ;
V_58 = F_8 ( V_2 , V_68 , V_70 ,
& V_33 , & V_34 ) ;
if ( V_58 )
return V_58 ;
V_18 = ( V_34 << 30 ) | ( V_33 << 16 ) ;
V_58 = F_8 ( V_2 , V_67 , V_69 ,
& V_33 , & V_34 ) ;
if ( V_58 )
return V_58 ;
V_18 |= ( V_34 << 14 ) | V_33 ;
F_10 ( & V_4 -> V_40 , V_38 ) ;
F_3 ( V_2 , V_18 , V_2 -> V_18 -> V_71 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_47 = V_47 ;
if ( V_2 -> V_46 != V_2 -> V_47 ) {
V_58 = F_5 ( V_2 , V_2 -> V_46 , V_2 -> V_47 , 0 ) ;
if ( V_58 )
goto V_61;
}
V_61:
F_11 ( & V_4 -> V_40 , V_38 ) ;
return V_58 ;
}
int F_15 ( struct V_1 * V_2 , struct V_72 * V_73 ,
T_1 V_74 , T_1 V_75 , int V_76 ,
enum V_77 V_78 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
struct V_35 * V_25 = V_4 -> V_25 ;
T_1 V_79 , V_80 , V_81 ;
T_1 V_82 = F_16 ( V_78 ) >> 5 ;
bool V_83 = false ;
unsigned long V_38 ;
int V_58 = 0 ;
if ( ( V_76 != 8 ) && ( V_76 != 16 ) ) {
F_7 ( V_25 -> V_26 , L_6 ) ;
return - V_27 ;
}
V_74 -- ;
V_75 -- ;
if ( V_82 & 0x2 )
V_83 = true ;
F_10 ( & V_4 -> V_40 , V_38 ) ;
V_79 = F_1 ( V_2 , V_84 ) ;
V_80 = F_1 ( V_2 , V_85 ) ;
V_81 = F_1 ( V_2 , V_86 ) ;
switch ( V_73 -> V_87 ) {
case V_88 :
if ( V_76 == 16 )
V_79 |= V_89 ;
else
V_79 &= ~ V_89 ;
if ( V_83 )
V_79 |= V_90 ;
else
V_79 &= ~ V_90 ;
V_80 &= ~ V_91 ;
V_80 |= V_75 << V_92 ;
V_81 &= ~ V_93 ;
V_81 |= V_74 << V_94 ;
break;
case V_95 :
if ( V_76 == 16 )
V_79 |= V_96 ;
else
V_79 &= ~ V_96 ;
break;
case V_97 :
V_79 &= ~ V_98 ;
V_79 |= V_82 << V_99 ;
break;
case V_100 :
if ( V_76 == 16 )
V_79 |= V_101 ;
else
V_79 &= ~ V_101 ;
break;
case V_102 :
if ( V_76 == 16 )
V_79 |= V_103 ;
else
V_79 &= ~ V_103 ;
if ( V_83 )
V_79 |= V_104 ;
else
V_79 &= ~ V_104 ;
V_80 &= ~ V_105 ;
V_80 |= V_75 << V_106 ;
V_81 &= ~ V_107 ;
V_81 |= V_74 << V_108 ;
break;
case V_109 :
V_79 &= ~ V_110 ;
V_79 |= V_82 << V_111 ;
break;
case V_112 :
if ( V_76 == 16 )
V_79 |= V_113 ;
else
V_79 &= ~ V_113 ;
if ( V_83 )
V_79 |= V_114 ;
else
V_79 &= ~ V_114 ;
V_80 &= ~ V_115 ;
V_80 |= V_75 << V_116 ;
V_81 &= ~ V_117 ;
V_81 |= V_74 << V_118 ;
break;
case V_119 :
V_79 &= ~ V_120 ;
V_79 |= V_82 << V_121 ;
break;
case V_122 :
if ( V_76 == 16 )
V_79 |= V_123 ;
else
V_79 &= ~ V_123 ;
break;
case V_124 :
if ( V_76 == 16 )
V_79 |= V_125 ;
else
V_79 &= ~ V_125 ;
break;
case V_126 :
if ( V_76 == 16 )
V_79 |= V_127 ;
else
V_79 &= ~ V_127 ;
break;
default:
goto V_61;
}
F_3 ( V_2 , V_79 , V_84 ) ;
F_3 ( V_2 , V_80 , V_85 ) ;
F_3 ( V_2 , V_81 , V_86 ) ;
if ( F_17 ( V_78 ) )
V_2 -> V_44 = true ;
V_61:
F_11 ( & V_4 -> V_40 , V_38 ) ;
return V_58 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_128 )
F_19 ( V_4 -> V_25 , V_129 ) ;
V_4 -> V_128 ++ ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_128 ) {
if ( ! -- V_4 -> V_128 )
F_21 ( V_4 -> V_25 , V_129 ) ;
}
}
int F_22 ( struct V_1 * V_2 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
unsigned long V_38 ;
F_10 ( & V_4 -> V_40 , V_38 ) ;
if ( ! V_4 -> V_130 )
F_19 ( V_4 -> V_25 , V_131 ) ;
V_4 -> V_130 ++ ;
if ( V_2 -> V_44 )
F_18 ( V_2 ) ;
F_11 ( & V_4 -> V_40 , V_38 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
unsigned long V_38 ;
F_10 ( & V_4 -> V_40 , V_38 ) ;
V_4 -> V_130 -- ;
if ( ! V_4 -> V_130 )
F_21 ( V_4 -> V_25 , V_131 ) ;
if ( V_4 -> V_130 < 0 )
V_4 -> V_130 = 0 ;
if ( V_2 -> V_44 )
F_20 ( V_2 ) ;
V_2 -> V_44 = V_2 -> V_49 = false ;
F_11 ( & V_4 -> V_40 , V_38 ) ;
return 0 ;
}
struct V_1 * F_24 ( struct V_35 * V_25 , enum V_132 V_59 )
{
struct V_11 * V_4 = V_25 -> V_133 ;
unsigned long V_38 ;
struct V_1 * V_2 , * V_58 ;
if ( V_59 >= V_134 )
return F_25 ( - V_27 ) ;
V_2 = & V_4 -> V_59 [ V_59 ] ;
F_10 ( & V_4 -> V_40 , V_38 ) ;
if ( V_2 -> V_135 ) {
V_58 = F_25 ( - V_136 ) ;
goto V_61;
}
V_2 -> V_135 = true ;
V_58 = V_2 ;
V_61:
F_11 ( & V_4 -> V_40 , V_38 ) ;
return V_58 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
unsigned long V_38 ;
F_10 ( & V_4 -> V_40 , V_38 ) ;
V_2 -> V_135 = false ;
F_11 ( & V_4 -> V_40 , V_38 ) ;
}
int F_27 ( struct V_35 * V_25 , struct V_137 * V_26 ,
unsigned long V_5 , unsigned long V_17 )
{
struct V_11 * V_4 ;
int V_138 ;
V_4 = F_28 ( V_26 , sizeof( * V_4 ) , V_139 ) ;
if ( ! V_4 )
return - V_140 ;
V_25 -> V_133 = V_4 ;
F_29 ( & V_4 -> V_40 ) ;
V_4 -> V_5 = F_30 ( V_26 , V_5 , V_141 ) ;
if ( ! V_4 -> V_5 )
return - V_140 ;
V_4 -> V_17 = F_30 ( V_26 , V_17 , V_142 ) ;
if ( ! V_4 -> V_17 )
return - V_140 ;
F_31 ( V_26 , L_7 , V_5 , V_4 -> V_5 ) ;
V_4 -> V_25 = V_25 ;
for ( V_138 = 0 ; V_138 < V_134 ; V_138 ++ ) {
V_4 -> V_59 [ V_138 ] . V_59 = V_138 ;
V_4 -> V_59 [ V_138 ] . V_4 = V_4 ;
V_4 -> V_59 [ V_138 ] . V_18 = & V_143 [ V_138 ] ;
V_4 -> V_59 [ V_138 ] . V_42 = & V_144 [ V_138 ] ;
}
return 0 ;
}
void F_32 ( struct V_35 * V_25 )
{
}
void F_33 ( struct V_1 * V_2 )
{
struct V_11 * V_4 = V_2 -> V_4 ;
struct V_35 * V_25 = V_4 -> V_25 ;
F_31 ( V_25 -> V_26 , L_8 ,
F_1 ( V_2 , V_41 ) ) ;
F_31 ( V_25 -> V_26 , L_9 ,
F_1 ( V_2 , V_145 ) ) ;
F_31 ( V_25 -> V_26 , L_10 ,
F_1 ( V_2 , V_146 ) ) ;
F_31 ( V_25 -> V_26 , L_11 ,
F_1 ( V_2 , V_147 ) ) ;
F_31 ( V_25 -> V_26 , L_12 ,
F_1 ( V_2 , V_63 ) ) ;
F_31 ( V_25 -> V_26 , L_13 ,
F_1 ( V_2 , V_66 ) ) ;
F_31 ( V_25 -> V_26 , L_14 ,
F_1 ( V_2 , V_84 ) ) ;
F_31 ( V_25 -> V_26 , L_15 ,
F_1 ( V_2 , V_85 ) ) ;
F_31 ( V_25 -> V_26 , L_16 ,
F_1 ( V_2 , V_86 ) ) ;
F_31 ( V_25 -> V_26 , L_17 ,
F_1 ( V_2 , V_148 ) ) ;
}
