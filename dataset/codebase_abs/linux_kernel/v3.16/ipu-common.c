static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , unsigned V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_6 + V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_5 ,
unsigned V_3 )
{
F_4 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_2 , V_8 ) ;
V_7 |= 0x8 ;
F_3 ( V_2 , V_7 , V_8 ) ;
}
struct V_9 T_2 * F_8 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
return V_2 -> V_12 + V_11 -> V_13 ;
}
void F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_9 T_2 * V_14 = F_8 ( V_11 ) ;
T_1 V_7 ;
if ( V_2 -> V_15 == V_16 )
F_10 ( V_14 , V_17 , 1 ) ;
V_7 = F_5 ( V_2 , F_11 ( V_11 -> V_13 ) ) ;
V_7 |= 1 << ( V_11 -> V_13 % 32 ) ;
F_6 ( V_2 , V_7 , F_11 ( V_11 -> V_13 ) ) ;
}
void F_10 ( struct V_9 T_2 * V_18 , T_1 V_19 , T_1 V_20 )
{
T_1 V_21 = ( V_19 >> 8 ) % 160 ;
T_1 V_22 = V_19 & 0xff ;
T_1 V_23 = ( V_19 >> 8 ) / 160 ;
T_1 V_24 = V_21 / 32 ;
T_1 V_25 = V_21 % 32 ;
T_1 V_26 = ( 1 << V_22 ) - 1 ;
T_1 V_7 ;
F_12 ( L_1 , V_27 , V_23 , V_21 , V_22 ) ;
V_7 = F_2 ( & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 ] ) ;
V_7 &= ~ ( V_26 << V_25 ) ;
V_7 |= V_20 << V_25 ;
F_4 ( V_7 , & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 ] ) ;
if ( ( V_21 + V_22 - 1 ) / 32 > V_24 ) {
V_7 = F_2 ( & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 + 1 ] ) ;
V_7 &= ~ ( V_26 >> ( V_25 ? ( 32 - V_25 ) : 0 ) ) ;
V_7 |= V_20 >> ( V_25 ? ( 32 - V_25 ) : 0 ) ;
F_4 ( V_7 , & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 + 1 ] ) ;
}
}
T_1 F_13 ( struct V_9 T_2 * V_18 , T_1 V_19 )
{
T_1 V_21 = ( V_19 >> 8 ) % 160 ;
T_1 V_22 = V_19 & 0xff ;
T_1 V_23 = ( V_19 >> 8 ) / 160 ;
T_1 V_24 = V_21 / 32 ;
T_1 V_25 = V_21 % 32 ;
T_1 V_26 = ( 1 << V_22 ) - 1 ;
T_1 V_7 = 0 ;
F_12 ( L_1 , V_27 , V_23 , V_21 , V_22 ) ;
V_7 = ( F_2 ( & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 ] ) >> V_25 ) & V_26 ;
if ( ( V_21 + V_22 - 1 ) / 32 > V_24 ) {
T_1 V_29 ;
V_29 = F_2 ( & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 + 1 ] ) ;
V_29 &= V_26 >> ( V_25 ? ( 32 - V_25 ) : 0 ) ;
V_7 |= V_29 << ( V_25 ? ( 32 - V_25 ) : 0 ) ;
}
return V_7 ;
}
int F_14 ( struct V_9 T_2 * V_14 ,
const struct V_30 * V_31 )
{
int V_32 = 0 , V_33 = 0 , V_34 , V_35 , V_36 , V_37 ;
V_34 = V_31 -> V_38 - V_31 -> V_39 . V_40 - V_31 -> V_39 . V_3 ;
V_35 = V_31 -> V_38 - V_31 -> V_41 . V_40 - V_31 -> V_41 . V_3 ;
V_36 = V_31 -> V_38 - V_31 -> V_42 . V_40 - V_31 -> V_42 . V_3 ;
V_37 = V_31 -> V_38 - V_31 -> V_43 . V_40 - V_31 -> V_43 . V_3 ;
F_10 ( V_14 , V_44 , V_31 -> V_39 . V_40 - 1 ) ;
F_10 ( V_14 , V_45 , V_34 ) ;
F_10 ( V_14 , V_46 , V_31 -> V_41 . V_40 - 1 ) ;
F_10 ( V_14 , V_47 , V_35 ) ;
F_10 ( V_14 , V_48 , V_31 -> V_42 . V_40 - 1 ) ;
F_10 ( V_14 , V_49 , V_36 ) ;
if ( V_31 -> V_43 . V_40 ) {
F_10 ( V_14 , V_50 ,
V_31 -> V_43 . V_40 - 1 ) ;
F_10 ( V_14 , V_51 , V_37 ) ;
} else {
F_10 ( V_14 , V_50 , 7 ) ;
F_10 ( V_14 , V_51 ,
V_31 -> V_38 ) ;
}
switch ( V_31 -> V_38 ) {
case 32 :
V_32 = 0 ;
V_33 = 15 ;
break;
case 24 :
V_32 = 1 ;
V_33 = 19 ;
break;
case 16 :
V_32 = 3 ;
V_33 = 31 ;
break;
case 8 :
V_32 = 5 ;
V_33 = 63 ;
break;
default:
return - V_52 ;
}
F_10 ( V_14 , V_53 , V_32 ) ;
F_10 ( V_14 , V_54 , V_33 ) ;
F_10 ( V_14 , V_55 , 7 ) ;
return 0 ;
}
int F_15 ( struct V_9 T_2 * V_14 ,
int V_56 )
{
int V_32 = 0 , V_33 = 0 ;
switch ( V_56 ) {
case 32 :
V_32 = 0 ;
V_33 = 15 ;
break;
case 24 :
V_32 = 1 ;
V_33 = 19 ;
break;
case 16 :
V_32 = 3 ;
V_33 = 31 ;
break;
case 8 :
V_32 = 5 ;
V_33 = 63 ;
break;
default:
return - V_52 ;
}
F_10 ( V_14 , V_53 , V_32 ) ;
F_10 ( V_14 , V_54 , V_33 ) ;
F_10 ( V_14 , V_55 , 6 ) ;
return 0 ;
}
void F_16 ( struct V_9 T_2 * V_14 ,
T_1 V_57 )
{
switch ( V_57 ) {
case V_58 :
F_10 ( V_14 , V_53 , 3 ) ;
F_10 ( V_14 , V_55 , 0xA ) ;
F_10 ( V_14 , V_54 , 31 ) ;
break;
case V_59 :
F_10 ( V_14 , V_53 , 3 ) ;
F_10 ( V_14 , V_55 , 0x8 ) ;
F_10 ( V_14 , V_54 , 31 ) ;
break;
}
}
void F_17 ( struct V_9 T_2 * V_14 ,
T_1 V_57 , int V_60 , int V_61 , int V_62 )
{
switch ( V_57 ) {
case V_63 :
F_10 ( V_14 , V_64 , ( V_60 / 2 ) - 1 ) ;
F_10 ( V_14 , V_65 , V_61 / 8 ) ;
F_10 ( V_14 , V_66 , V_62 / 8 ) ;
break;
case V_67 :
F_10 ( V_14 , V_64 , ( V_60 / 2 ) - 1 ) ;
F_10 ( V_14 , V_65 , V_62 / 8 ) ;
F_10 ( V_14 , V_66 , V_61 / 8 ) ;
break;
}
}
void F_18 ( struct V_9 T_2 * V_14 , T_1 V_57 ,
int V_60 , int V_68 )
{
int V_61 , V_62 ;
int V_69 = 0 ;
switch ( V_57 ) {
case V_63 :
case V_67 :
V_69 = V_60 / 2 ;
V_61 = V_60 * V_68 ;
V_62 = V_61 + ( V_69 * V_68 / 2 ) ;
F_17 ( V_14 , V_57 , V_60 ,
V_61 , V_62 ) ;
break;
}
}
int F_19 ( struct V_9 T_2 * V_70 , T_1 V_71 )
{
switch ( V_71 ) {
case V_72 :
case V_73 :
F_10 ( V_70 , V_55 , 2 ) ;
F_10 ( V_70 , V_54 , 63 ) ;
break;
case V_74 :
F_10 ( V_70 , V_53 , 3 ) ;
F_10 ( V_70 , V_55 , 0xA ) ;
F_10 ( V_70 , V_54 , 31 ) ;
break;
case V_75 :
F_10 ( V_70 , V_53 , 3 ) ;
F_10 ( V_70 , V_55 , 0x8 ) ;
F_10 ( V_70 , V_54 , 31 ) ;
break;
case V_76 :
case V_77 :
F_14 ( V_70 , & V_78 ) ;
break;
case V_79 :
case V_80 :
F_14 ( V_70 , & V_81 ) ;
break;
case V_82 :
F_14 ( V_70 , & V_83 ) ;
break;
case V_84 :
F_14 ( V_70 , & V_85 ) ;
break;
case V_86 :
F_14 ( V_70 , & V_87 ) ;
break;
case V_88 :
F_14 ( V_70 , & V_89 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_20 ( T_1 V_90 )
{
switch ( V_90 ) {
case V_91 :
return V_86 ;
case V_92 :
return V_84 ;
case V_93 :
return V_82 ;
case V_94 :
return V_80 ;
case V_95 :
return V_77 ;
case V_58 :
return V_74 ;
case V_59 :
return V_75 ;
case V_63 :
return V_72 ;
case V_67 :
return V_73 ;
}
return - V_52 ;
}
enum V_96 F_21 ( T_1 V_71 )
{
switch ( V_71 ) {
case V_86 :
case V_88 :
case V_84 :
case V_82 :
case V_80 :
case V_77 :
case V_97 :
case V_98 :
case V_79 :
case V_76 :
case V_99 :
case V_100 :
return V_101 ;
case V_75 :
case V_74 :
case V_72 :
case V_73 :
return V_102 ;
default:
return V_103 ;
}
}
int F_22 ( struct V_9 T_2 * V_70 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = & V_105 -> V_107 ;
int V_108 , V_61 , V_62 ;
F_12 ( L_2 ,
V_27 , V_107 -> V_56 , V_107 -> V_68 ,
V_107 -> V_109 ) ;
F_23 ( V_70 , V_105 -> V_110 . V_56 ,
V_105 -> V_110 . V_68 ) ;
F_24 ( V_70 , V_107 -> V_109 ) ;
F_19 ( V_70 , F_20 ( V_107 -> V_90 ) ) ;
switch ( V_107 -> V_90 ) {
case V_63 :
case V_67 :
V_108 = F_25 ( V_107 , V_105 -> V_110 . V_111 , V_105 -> V_110 . V_112 ) ;
V_61 = F_26 ( V_107 , V_105 -> V_110 . V_111 ,
V_105 -> V_110 . V_112 ) - V_108 ;
V_62 = F_27 ( V_107 , V_105 -> V_110 . V_111 ,
V_105 -> V_110 . V_112 ) - V_108 ;
F_17 ( V_70 , V_107 -> V_90 ,
V_107 -> V_109 , V_61 , V_62 ) ;
F_28 ( V_70 , 0 , V_105 -> V_113 + V_108 ) ;
break;
case V_58 :
case V_59 :
F_28 ( V_70 , 0 , V_105 -> V_113 +
V_105 -> V_110 . V_111 * 2 +
V_105 -> V_110 . V_112 * V_105 -> V_107 . V_109 ) ;
break;
case V_95 :
case V_94 :
F_28 ( V_70 , 0 , V_105 -> V_113 +
V_105 -> V_110 . V_111 * 4 +
V_105 -> V_110 . V_112 * V_105 -> V_107 . V_109 ) ;
break;
case V_91 :
F_28 ( V_70 , 0 , V_105 -> V_113 +
V_105 -> V_110 . V_111 * 2 +
V_105 -> V_110 . V_112 * V_105 -> V_107 . V_109 ) ;
break;
case V_93 :
case V_92 :
F_28 ( V_70 , 0 , V_105 -> V_113 +
V_105 -> V_110 . V_111 * 3 +
V_105 -> V_110 . V_112 * V_105 -> V_107 . V_109 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
enum V_96 F_29 ( T_1 V_90 )
{
switch ( V_90 ) {
case V_63 :
case V_67 :
case V_58 :
case V_59 :
return V_102 ;
case V_95 :
case V_94 :
case V_93 :
case V_92 :
case V_91 :
return V_101 ;
default:
return V_103 ;
}
}
struct V_10 * F_30 ( struct V_1 * V_2 , unsigned V_13 )
{
struct V_10 * V_11 ;
F_31 ( V_2 -> V_114 , L_3 , V_27 , V_13 ) ;
if ( V_13 > 63 )
return F_32 ( - V_115 ) ;
F_33 ( & V_2 -> V_116 ) ;
V_11 = & V_2 -> V_11 [ V_13 ] ;
if ( V_11 -> V_117 ) {
V_11 = F_32 ( - V_118 ) ;
goto V_119;
}
V_11 -> V_117 = true ;
V_11 -> V_13 = V_13 ;
V_119:
F_34 ( & V_2 -> V_116 ) ;
return V_11 ;
}
void F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
F_31 ( V_2 -> V_114 , L_3 , V_27 , V_11 -> V_13 ) ;
F_33 ( & V_2 -> V_116 ) ;
V_11 -> V_117 = false ;
F_34 ( & V_2 -> V_116 ) ;
}
void F_36 ( struct V_10 * V_11 ,
bool V_120 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_121 ;
T_1 V_122 ;
F_37 ( & V_2 -> V_123 , V_121 ) ;
V_122 = F_1 ( V_2 , F_38 ( V_11 -> V_13 ) ) ;
if ( V_120 )
V_122 |= F_39 ( V_11 -> V_13 ) ;
else
V_122 &= ~ F_39 ( V_11 -> V_13 ) ;
F_3 ( V_2 , V_122 , F_38 ( V_11 -> V_13 ) ) ;
F_40 ( & V_2 -> V_123 , V_121 ) ;
}
int F_41 ( struct V_1 * V_2 , T_1 V_26 )
{
unsigned long V_124 ;
T_1 V_7 ;
F_37 ( & V_2 -> V_123 , V_124 ) ;
V_7 = F_1 ( V_2 , V_125 ) ;
if ( V_26 & V_126 )
V_7 |= V_127 ;
if ( V_26 & V_128 )
V_7 |= V_129 ;
F_3 ( V_2 , V_7 , V_125 ) ;
V_7 = F_1 ( V_2 , V_130 ) ;
V_7 |= V_26 ;
F_3 ( V_2 , V_7 , V_130 ) ;
F_40 ( & V_2 -> V_123 , V_124 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 , T_1 V_26 )
{
unsigned long V_124 ;
T_1 V_7 ;
F_37 ( & V_2 -> V_123 , V_124 ) ;
V_7 = F_1 ( V_2 , V_130 ) ;
V_7 &= ~ V_26 ;
F_3 ( V_2 , V_7 , V_130 ) ;
V_7 = F_1 ( V_2 , V_125 ) ;
if ( V_26 & V_126 )
V_7 &= ~ V_127 ;
if ( V_26 & V_128 )
V_7 &= ~ V_129 ;
F_3 ( V_2 , V_7 , V_125 ) ;
F_40 ( & V_2 -> V_123 , V_124 ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , int V_131 )
{
return F_41 ( V_2 , V_131 ? V_132 : V_133 ) ;
}
int F_44 ( struct V_1 * V_2 , int V_131 )
{
return F_42 ( V_2 , V_131 ? V_132 : V_133 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
return F_41 ( V_2 , V_134 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
return F_42 ( V_2 , V_134 ) ;
}
int F_47 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned int V_135 = V_11 -> V_13 ;
return ( F_1 ( V_2 , F_48 ( V_135 ) ) & F_39 ( V_135 ) ) ? 1 : 0 ;
}
void F_49 ( struct V_10 * V_11 , T_1 V_136 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned int V_135 = V_11 -> V_13 ;
unsigned long V_121 ;
F_37 ( & V_2 -> V_123 , V_121 ) ;
if ( V_136 == 0 )
F_3 ( V_2 , F_39 ( V_135 ) , F_50 ( V_135 ) ) ;
else
F_3 ( V_2 , F_39 ( V_135 ) , F_51 ( V_135 ) ) ;
F_40 ( & V_2 -> V_123 , V_121 ) ;
}
int F_52 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_7 ;
unsigned long V_121 ;
F_37 ( & V_2 -> V_123 , V_121 ) ;
V_7 = F_5 ( V_2 , F_53 ( V_11 -> V_13 ) ) ;
V_7 |= F_39 ( V_11 -> V_13 ) ;
F_6 ( V_2 , V_7 , F_53 ( V_11 -> V_13 ) ) ;
F_40 ( & V_2 -> V_123 , V_121 ) ;
return 0 ;
}
bool F_54 ( struct V_1 * V_2 , unsigned int V_135 )
{
return ( F_5 ( V_2 , F_55 ( V_135 ) ) & F_39 ( V_135 ) ) ;
}
int F_56 ( struct V_10 * V_11 , int V_137 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_138 ;
V_138 = V_139 + F_57 ( V_137 ) ;
while ( F_5 ( V_2 , F_55 ( V_11 -> V_13 ) ) &
F_39 ( V_11 -> V_13 ) ) {
if ( F_58 ( V_139 , V_138 ) )
return - V_140 ;
F_59 () ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 , int V_141 , int V_137 )
{
unsigned long V_138 ;
V_138 = V_139 + F_57 ( V_137 ) ;
F_3 ( V_2 , F_61 ( V_141 % 32 ) , F_62 ( V_141 / 32 ) ) ;
while ( ! ( F_1 ( V_2 , F_62 ( V_141 / 32 ) & F_61 ( V_141 % 32 ) ) ) ) {
if ( F_58 ( V_139 , V_138 ) )
return - V_140 ;
F_59 () ;
}
return 0 ;
}
int F_63 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_7 ;
unsigned long V_121 ;
F_37 ( & V_2 -> V_123 , V_121 ) ;
V_7 = F_5 ( V_2 , F_53 ( V_11 -> V_13 ) ) ;
V_7 &= ~ F_39 ( V_11 -> V_13 ) ;
F_6 ( V_2 , V_7 , F_53 ( V_11 -> V_13 ) ) ;
F_3 ( V_2 , 0xf0000000 , V_142 ) ;
if ( F_1 ( V_2 , F_50 ( V_11 -> V_13 ) ) &
F_39 ( V_11 -> V_13 ) ) {
F_3 ( V_2 , F_39 ( V_11 -> V_13 ) ,
F_50 ( V_11 -> V_13 ) ) ;
}
if ( F_1 ( V_2 , F_51 ( V_11 -> V_13 ) ) &
F_39 ( V_11 -> V_13 ) ) {
F_3 ( V_2 , F_39 ( V_11 -> V_13 ) ,
F_51 ( V_11 -> V_13 ) ) ;
}
F_3 ( V_2 , 0x0 , V_142 ) ;
V_7 = F_1 ( V_2 , F_38 ( V_11 -> V_13 ) ) ;
V_7 &= ~ F_39 ( V_11 -> V_13 ) ;
F_3 ( V_2 , V_7 , F_38 ( V_11 -> V_13 ) ) ;
F_40 ( & V_2 -> V_123 , V_121 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
unsigned long V_138 ;
F_3 ( V_2 , 0x807FFFFF , V_143 ) ;
V_138 = V_139 + F_57 ( 1000 ) ;
while ( F_1 ( V_2 , V_143 ) & 0x80000000 ) {
if ( F_58 ( V_139 , V_138 ) )
return - V_144 ;
F_59 () ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_145 * V_146 , unsigned long V_147 ,
struct V_148 * V_149 )
{
char * V_150 ;
int V_151 ;
struct V_152 * V_114 = & V_146 -> V_114 ;
const struct V_153 * V_154 = V_2 -> V_154 ;
V_151 = F_66 ( V_2 , V_114 , 0 , V_147 + V_154 -> V_155 ,
V_126 , V_149 ) ;
if ( V_151 ) {
V_150 = L_4 ;
goto V_156;
}
V_151 = F_66 ( V_2 , V_114 , 1 , V_147 + V_154 -> V_157 ,
V_128 , V_149 ) ;
if ( V_151 ) {
V_150 = L_5 ;
goto V_158;
}
V_151 = F_67 ( V_2 , V_114 , V_147 + V_154 -> V_159 +
V_160 , V_147 + V_154 -> V_161 ) ;
if ( V_151 ) {
V_150 = L_6 ;
goto V_162;
}
V_151 = F_68 ( V_2 , V_114 , V_147 +
V_154 -> V_159 + V_163 , V_149 ) ;
if ( V_151 ) {
V_150 = L_7 ;
goto V_164;
}
V_151 = F_69 ( V_2 , V_114 , V_147 + V_154 -> V_165 ) ;
if ( V_151 ) {
V_150 = L_8 ;
goto V_166;
}
V_151 = F_70 ( V_2 , V_114 , V_147 +
V_154 -> V_159 + V_167 ) ;
if ( V_151 ) {
V_150 = L_9 ;
goto V_168;
}
return 0 ;
V_168:
F_71 ( V_2 ) ;
V_166:
F_72 ( V_2 ) ;
V_164:
F_73 ( V_2 ) ;
V_162:
F_74 ( V_2 , 1 ) ;
V_158:
F_74 ( V_2 , 0 ) ;
V_156:
F_75 ( & V_146 -> V_114 , L_10 , V_150 , V_151 ) ;
return V_151 ;
}
static void F_76 ( struct V_1 * V_2 , const int * V_169 , int V_170 )
{
unsigned long V_171 ;
int V_24 , V_21 , V_141 ;
for ( V_24 = 0 ; V_24 < V_170 ; V_24 ++ ) {
V_171 = F_1 ( V_2 , F_62 ( V_169 [ V_24 ] ) ) ;
V_171 &= F_1 ( V_2 , F_77 ( V_169 [ V_24 ] ) ) ;
F_78 (bit, &status, 32 ) {
V_141 = F_79 ( V_2 -> V_172 ,
V_169 [ V_24 ] * 32 + V_21 ) ;
if ( V_141 )
F_80 ( V_141 ) ;
}
}
}
static void F_81 ( unsigned int V_141 , struct V_173 * V_174 )
{
struct V_1 * V_2 = F_82 ( V_174 ) ;
const int V_175 [] = { 0 , 1 , 2 , 3 , 10 , 11 , 12 , 13 , 14 } ;
struct V_176 * V_177 = F_83 ( V_141 ) ;
F_84 ( V_177 , V_174 ) ;
F_76 ( V_2 , V_175 , F_85 ( V_175 ) ) ;
F_86 ( V_177 , V_174 ) ;
}
static void F_87 ( unsigned int V_141 , struct V_173 * V_174 )
{
struct V_1 * V_2 = F_82 ( V_174 ) ;
const int V_175 [] = { 4 , 5 , 8 , 9 } ;
struct V_176 * V_177 = F_83 ( V_141 ) ;
F_84 ( V_177 , V_174 ) ;
F_76 ( V_2 , V_175 , F_85 ( V_175 ) ) ;
F_86 ( V_177 , V_174 ) ;
}
int F_88 ( struct V_1 * V_2 , int V_141 )
{
int V_178 ;
V_178 = F_79 ( V_2 -> V_172 , V_141 ) ;
if ( ! V_178 )
V_178 = F_89 ( V_2 -> V_172 , V_141 ) ;
return V_178 ;
}
int F_90 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_179 V_180 )
{
return F_88 ( V_2 , V_180 + V_11 -> V_13 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_92 ( V_2 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
F_74 ( V_2 , 1 ) ;
F_74 ( V_2 , 0 ) ;
}
static int F_93 ( struct V_152 * V_114 , void * V_181 )
{
struct V_145 * V_146 = F_94 ( V_114 ) ;
F_95 ( V_146 ) ;
return 0 ;
}
static void F_96 ( struct V_145 * V_146 )
{
F_97 ( & V_146 -> V_114 , NULL , F_93 ) ;
}
static int F_98 ( struct V_1 * V_2 , unsigned long V_147 )
{
struct V_152 * V_114 = V_2 -> V_114 ;
unsigned V_24 ;
int V_182 , V_151 ;
F_33 ( & V_183 ) ;
V_182 = V_184 ;
V_184 += F_85 ( V_185 ) ;
F_34 ( & V_183 ) ;
for ( V_24 = 0 ; V_24 < F_85 ( V_185 ) ; V_24 ++ ) {
const struct V_186 * V_122 = & V_185 [ V_24 ] ;
struct V_145 * V_146 ;
struct V_187 V_188 ;
if ( V_122 -> V_189 ) {
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_121 = V_190 ;
V_188 . V_191 = V_147 + V_2 -> V_154 -> V_159 + V_122 -> V_189 ;
V_188 . V_192 = V_188 . V_191 + V_193 - 1 ;
V_146 = F_99 ( V_114 , V_122 -> V_194 ,
V_182 ++ , & V_188 , 1 , & V_122 -> V_195 , sizeof( V_122 -> V_195 ) ) ;
} else {
V_146 = F_100 ( V_114 , V_122 -> V_194 ,
V_182 ++ , & V_122 -> V_195 , sizeof( V_122 -> V_195 ) ) ;
}
if ( F_101 ( V_146 ) )
goto V_196;
}
return 0 ;
V_196:
F_96 ( F_94 ( V_114 ) ) ;
return V_151 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_197 * V_198 ;
struct V_199 * V_200 ;
unsigned long V_181 [ V_201 / 32 ] = {
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x400100d0 , 0xffe000fd ,
0x4077ffff , 0xffe7e1fd ,
0x23fffffe , 0x8880fff0 ,
0xf98fe7d0 , 0xfff81fff ,
0x400100d0 , 0xffe000fd ,
0x00000000 ,
} ;
int V_151 , V_24 ;
V_2 -> V_172 = F_103 ( V_2 -> V_114 -> V_202 , V_201 ,
& V_203 , V_2 ) ;
if ( ! V_2 -> V_172 ) {
F_75 ( V_2 -> V_114 , L_11 ) ;
return - V_115 ;
}
V_151 = F_104 ( V_2 -> V_172 , 32 , 1 , L_12 ,
V_204 , 0 ,
V_205 , 0 ) ;
if ( V_151 < 0 ) {
F_75 ( V_2 -> V_114 , L_13 ) ;
F_105 ( V_2 -> V_172 ) ;
return V_151 ;
}
for ( V_24 = 0 ; V_24 < V_201 ; V_24 += 32 ) {
V_198 = F_106 ( V_2 -> V_172 , V_24 ) ;
V_198 -> V_206 = V_2 -> V_4 ;
V_198 -> V_181 = V_181 [ V_24 / 32 ] ;
V_200 = V_198 -> V_207 ;
V_200 -> V_177 . V_208 = V_209 ;
V_200 -> V_177 . V_210 = V_211 ;
V_200 -> V_177 . V_212 = V_213 ;
V_200 -> V_169 . V_214 = F_62 ( V_24 / 32 ) ;
V_200 -> V_169 . V_26 = F_77 ( V_24 / 32 ) ;
}
F_107 ( V_2 -> V_215 , F_81 ) ;
F_108 ( V_2 -> V_215 , V_2 ) ;
F_107 ( V_2 -> V_216 , F_87 ) ;
F_108 ( V_2 -> V_216 , V_2 ) ;
return 0 ;
}
static void F_109 ( struct V_1 * V_2 )
{
int V_24 , V_141 ;
F_107 ( V_2 -> V_216 , NULL ) ;
F_108 ( V_2 -> V_216 , NULL ) ;
F_107 ( V_2 -> V_215 , NULL ) ;
F_108 ( V_2 -> V_215 , NULL ) ;
for ( V_24 = 0 ; V_24 < V_201 ; V_24 ++ ) {
V_141 = F_79 ( V_2 -> V_172 , V_24 ) ;
if ( V_141 )
F_110 ( V_141 ) ;
}
F_105 ( V_2 -> V_172 ) ;
}
static int F_111 ( struct V_145 * V_146 )
{
const struct V_217 * V_218 =
F_112 ( V_219 , & V_146 -> V_114 ) ;
struct V_1 * V_2 ;
struct V_187 * V_188 ;
unsigned long V_147 ;
int V_24 , V_151 , V_215 , V_216 ;
const struct V_153 * V_154 ;
V_154 = V_218 -> V_28 ;
V_215 = F_113 ( V_146 , 0 ) ;
V_216 = F_113 ( V_146 , 1 ) ;
V_188 = F_114 ( V_146 , V_190 , 0 ) ;
F_31 ( & V_146 -> V_114 , L_14 ,
V_215 , V_216 ) ;
if ( ! V_188 || V_215 < 0 || V_216 < 0 )
return - V_115 ;
V_147 = V_188 -> V_191 ;
V_2 = F_115 ( & V_146 -> V_114 , sizeof( * V_2 ) , V_220 ) ;
if ( ! V_2 )
return - V_115 ;
for ( V_24 = 0 ; V_24 < 64 ; V_24 ++ )
V_2 -> V_11 [ V_24 ] . V_2 = V_2 ;
V_2 -> V_154 = V_154 ;
V_2 -> V_15 = V_154 -> type ;
F_116 ( & V_2 -> V_123 ) ;
F_117 ( & V_2 -> V_116 ) ;
F_31 ( & V_146 -> V_114 , L_15 ,
V_147 + V_154 -> V_159 ) ;
F_31 ( & V_146 -> V_114 , L_16 ,
V_147 + V_154 -> V_159 + V_221 ) ;
F_31 ( & V_146 -> V_114 , L_17 ,
V_147 + V_154 -> V_222 ) ;
F_31 ( & V_146 -> V_114 , L_18 ,
V_147 + V_154 -> V_155 ) ;
F_31 ( & V_146 -> V_114 , L_19 ,
V_147 + V_154 -> V_157 ) ;
F_31 ( & V_146 -> V_114 , L_20 ,
V_147 + V_154 -> V_165 ) ;
F_31 ( & V_146 -> V_114 , L_21 ,
V_147 + V_154 -> V_223 ) ;
F_31 ( & V_146 -> V_114 , L_22 ,
V_147 + V_154 -> V_159 + V_160 ) ;
F_31 ( & V_146 -> V_114 , L_23 ,
V_147 + V_154 -> V_159 + V_224 ) ;
F_31 ( & V_146 -> V_114 , L_24 ,
V_147 + V_154 -> V_159 + V_163 ) ;
F_31 ( & V_146 -> V_114 , L_25 ,
V_147 + V_154 -> V_225 ) ;
V_2 -> V_4 = F_118 ( & V_146 -> V_114 ,
V_147 + V_154 -> V_159 , V_193 ) ;
V_2 -> V_6 = F_118 ( & V_146 -> V_114 ,
V_147 + V_154 -> V_159 + V_221 ,
V_193 ) ;
V_2 -> V_12 = F_118 ( & V_146 -> V_114 ,
V_147 + V_154 -> V_222 , V_193 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_6 || ! V_2 -> V_12 )
return - V_226 ;
V_2 -> V_148 = F_119 ( & V_146 -> V_114 , L_26 ) ;
if ( F_101 ( V_2 -> V_148 ) ) {
V_151 = F_120 ( V_2 -> V_148 ) ;
F_75 ( & V_146 -> V_114 , L_27 , V_151 ) ;
return V_151 ;
}
F_121 ( V_146 , V_2 ) ;
V_151 = F_122 ( V_2 -> V_148 ) ;
if ( V_151 ) {
F_75 ( & V_146 -> V_114 , L_28 , V_151 ) ;
return V_151 ;
}
V_2 -> V_114 = & V_146 -> V_114 ;
V_2 -> V_215 = V_215 ;
V_2 -> V_216 = V_216 ;
V_151 = F_102 ( V_2 ) ;
if ( V_151 )
goto V_227;
V_151 = F_123 ( & V_146 -> V_114 ) ;
if ( V_151 ) {
F_75 ( & V_146 -> V_114 , L_29 , V_151 ) ;
goto V_228;
}
V_151 = F_64 ( V_2 ) ;
if ( V_151 )
goto V_228;
F_3 ( V_2 , 0x00400000L | ( V_229 << 18 ) ,
V_125 ) ;
V_151 = F_65 ( V_2 , V_146 , V_147 , V_2 -> V_148 ) ;
if ( V_151 )
goto V_230;
V_151 = F_98 ( V_2 , V_147 ) ;
if ( V_151 ) {
F_75 ( & V_146 -> V_114 , L_30 ,
V_151 ) ;
goto V_231;
}
F_124 ( & V_146 -> V_114 , L_31 , V_154 -> V_194 ) ;
return 0 ;
V_231:
F_91 ( V_2 ) ;
V_230:
V_228:
F_109 ( V_2 ) ;
V_227:
F_125 ( V_2 -> V_148 ) ;
return V_151 ;
}
static int F_126 ( struct V_145 * V_146 )
{
struct V_1 * V_2 = F_127 ( V_146 ) ;
F_96 ( V_146 ) ;
F_91 ( V_2 ) ;
F_109 ( V_2 ) ;
F_125 ( V_2 -> V_148 ) ;
return 0 ;
}
