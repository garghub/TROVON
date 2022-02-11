int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
int V_5 ;
V_4 -> V_6 = NULL ;
switch ( V_4 -> type ) {
case V_7 :
#ifdef F_2
V_4 -> V_6 = & V_8 ;
#endif
break;
case V_9 :
#ifdef F_3
V_4 -> V_6 = & V_10 ;
#endif
break;
case V_11 :
#ifdef F_4
V_4 -> V_6 = & V_12 ;
#endif
break;
case V_13 :
#ifdef F_5
V_4 -> V_6 = & V_14 ;
#endif
break;
case V_15 :
#ifdef F_6
V_4 -> V_6 = & V_16 ;
#endif
break;
case V_17 :
#ifdef F_7
V_4 -> V_6 = & V_18 ;
#endif
break;
}
if ( F_8 ( ! V_4 -> V_6 ) )
return - V_19 ;
V_5 = V_4 -> V_6 -> V_20 ( V_2 ) ;
if ( V_5 )
V_4 -> V_6 = NULL ;
return V_5 ;
}
void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_4 . V_6 -> free ( V_2 ) ;
V_2 -> V_4 . V_6 = NULL ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
const struct V_21 * V_6 = V_4 -> V_6 ;
int V_5 ;
if ( ! V_4 -> V_22 ) {
V_4 -> V_22 = & V_2 -> V_23 -> V_24 -> V_25 . V_22 ;
V_4 -> V_26 = V_4 -> V_22 -> V_27 -> V_28 ;
}
V_4 -> V_6 -> V_29 ( V_2 , true ) ;
F_11 ( V_2 , false ) ;
V_5 = V_6 -> V_30 ( V_2 ) ;
if ( V_5 ) {
F_12 ( V_2 -> V_23 , L_1 ) ;
goto V_31;
}
V_4 -> V_32 = false ;
V_5 = F_13 ( V_2 , V_4 -> V_26 ) ;
if ( V_5 ) {
F_12 ( V_2 -> V_23 , L_2 ) ;
goto V_33;
}
return 0 ;
V_33:
V_4 -> V_32 = true ;
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
V_31:
F_11 ( V_2 , true ) ;
return V_5 ;
}
void F_14 ( struct V_1 * V_2 )
{
const struct V_21 * V_6 = V_2 -> V_4 . V_6 ;
F_11 ( V_2 , true ) ;
V_2 -> V_4 . V_32 = true ;
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
}
bool F_15 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_34 )
return false ;
if ( ! V_2 -> V_4 . V_6 -> V_35 )
return false ;
return V_2 -> V_4 . V_6 -> V_35 ( V_2 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
T_1 V_36 ;
#if V_37
F_8 ( V_2 -> V_4 . V_38 ) ;
V_2 -> V_4 . V_38 = true ;
#endif
V_36 = F_17 ( V_2 , V_39 ) ;
V_36 |= V_40 ;
F_18 ( V_2 , V_39 , V_36 ) ;
F_17 ( V_2 , V_39 ) ;
F_19 ( 10 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
T_1 V_36 ;
#if V_37
F_8 ( ! V_2 -> V_4 . V_38 ) ;
V_2 -> V_4 . V_38 = false ;
#endif
F_21 ( V_2 , V_41 ) ;
V_36 = F_17 ( V_2 , V_39 ) ;
V_36 &= ~ V_40 ;
F_18 ( V_2 , V_39 , V_36 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
#if V_37
F_8 ( V_2 -> V_4 . V_42 ) ;
V_2 -> V_4 . V_42 = true ;
#endif
F_8 ( V_2 -> V_2 -> V_43 < 3 ) ;
if ( ! F_23 ( V_2 -> V_23 , V_44 ) )
F_24 ( V_2 , V_45 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
#if V_37
F_8 ( ! V_2 -> V_4 . V_42 ) ;
V_2 -> V_4 . V_42 = false ;
#endif
F_8 ( V_2 -> V_2 -> V_43 < 3 ) ;
if ( ! F_23 ( V_2 -> V_23 , V_44 ) )
F_24 ( V_2 , 0 ) ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
if ( ! V_37 )
return;
if ( ( F_27 ( V_2 ) >= V_46 ) &&
( V_2 -> V_47 <= 0 ) ) {
F_28 ( V_2 -> V_23 , L_3
L_4 ) ;
F_29 () ;
}
}
T_2 F_30 ( struct V_1 * V_2 , T_2 V_48 )
{
F_26 ( V_2 ) ;
V_2 -> V_4 . V_49 = 0 ;
return V_2 -> V_4 . V_6 -> V_50 ( V_2 , V_48 ) ;
}
void F_31 ( struct V_1 * V_2 , T_2 V_48 , T_2 V_51 )
{
F_26 ( V_2 ) ;
if ( F_32 ( V_2 -> V_2 ) &&
++ V_2 -> V_4 . V_49 > V_52 ) {
F_17 ( V_2 , V_39 ) ;
V_2 -> V_4 . V_49 = 1 ;
}
V_2 -> V_4 . V_6 -> V_53 ( V_2 , V_48 , V_51 ) ;
}
void F_33 ( struct V_1 * V_2 , T_2 V_54 , T_2 V_55 )
{
F_34 ( V_2 , V_54 ,
F_35 ( V_2 , V_54 ) & V_55 ) ;
}
void F_36 ( struct V_1 * V_2 , T_2 V_54 , T_2 V_56 )
{
F_34 ( V_2 , V_54 ,
F_35 ( V_2 , V_54 ) | V_56 ) ;
}
void F_37 ( struct V_1 * V_2 , T_2 V_54 , T_2 V_55 , T_2 V_56 )
{
F_34 ( V_2 , V_54 ,
( F_35 ( V_2 , V_54 ) & V_55 ) | V_56 ) ;
}
bool F_38 ( struct V_1 * V_2 , T_2 V_54 , T_2 V_55 ,
T_2 V_51 , int V_57 , int V_58 )
{
T_2 V_59 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_58 ; V_60 += V_57 ) {
V_59 = F_30 ( V_2 , V_54 ) ;
if ( ( V_59 & V_55 ) == V_51 )
return true ;
F_19 ( V_57 ) ;
}
return false ;
}
T_2 F_39 ( struct V_1 * V_2 , T_2 V_48 )
{
F_26 ( V_2 ) ;
V_2 -> V_4 . V_49 = 0 ;
if ( V_2 -> V_4 . V_6 -> V_61 )
return V_2 -> V_4 . V_6 -> V_61 ( V_2 , V_48 ) ;
F_40 ( V_2 , V_62 , V_48 ) ;
return F_21 ( V_2 , V_63 ) ;
}
void F_41 ( struct V_1 * V_2 , T_2 V_48 , T_2 V_51 )
{
F_26 ( V_2 ) ;
if ( F_32 ( V_2 -> V_2 ) &&
++ V_2 -> V_4 . V_49 > V_52 ) {
F_21 ( V_2 , V_41 ) ;
V_2 -> V_4 . V_49 = 1 ;
}
if ( V_2 -> V_4 . V_6 -> V_64 )
return V_2 -> V_4 . V_6 -> V_64 ( V_2 , V_48 , V_51 ) ;
F_40 ( V_2 , V_62 , V_48 ) ;
F_42 ( V_2 , V_63 , V_51 ) ;
}
void F_43 ( struct V_1 * V_2 , T_2 V_65 , T_2 V_66 )
{
F_41 ( V_2 , V_65 , F_39 ( V_2 , V_66 ) ) ;
}
void F_44 ( struct V_1 * V_2 , T_2 V_54 , T_2 V_55 )
{
if ( V_2 -> V_4 . V_6 -> V_67 ) {
F_26 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_67 ( V_2 , V_54 , V_55 , 0 ) ;
} else {
F_41 ( V_2 , V_54 ,
F_39 ( V_2 , V_54 ) & V_55 ) ;
}
}
void F_45 ( struct V_1 * V_2 , T_2 V_54 , T_2 V_56 )
{
if ( V_2 -> V_4 . V_6 -> V_67 ) {
F_26 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_67 ( V_2 , V_54 , 0xFFFF , V_56 ) ;
} else {
F_41 ( V_2 , V_54 ,
F_39 ( V_2 , V_54 ) | V_56 ) ;
}
}
void F_46 ( struct V_1 * V_2 , T_2 V_54 , T_2 V_55 , T_2 V_56 )
{
if ( V_2 -> V_4 . V_6 -> V_67 ) {
F_26 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_67 ( V_2 , V_54 , V_55 , V_56 ) ;
} else {
F_41 ( V_2 , V_54 ,
( F_39 ( V_2 , V_54 ) & V_55 ) | V_56 ) ;
}
}
void F_47 ( struct V_1 * V_2 )
{
T_1 V_68 ;
switch ( V_2 -> V_2 -> V_69 ) {
#ifdef F_48
case V_70 :
V_68 = F_49 ( V_2 -> V_2 -> V_71 , V_72 ) ;
V_68 &= ~ V_73 ;
V_68 |= V_74 ;
V_68 |= V_75 ;
F_50 ( V_2 -> V_2 -> V_71 , V_72 , V_68 ) ;
F_19 ( 1 ) ;
V_68 = F_49 ( V_2 -> V_2 -> V_71 , V_72 ) ;
V_68 &= ~ V_75 ;
F_50 ( V_2 -> V_2 -> V_71 , V_72 , V_68 ) ;
F_19 ( 1 ) ;
break;
#endif
#ifdef F_51
case V_76 :
V_68 = F_52 ( V_2 -> V_2 -> V_77 , V_78 ) ;
V_68 &= ~ V_79 ;
V_68 |= V_80 ;
V_68 |= V_81 ;
F_53 ( V_2 -> V_2 -> V_77 , V_78 , V_68 ) ;
F_54 ( 1000 , 2000 ) ;
V_68 = F_52 ( V_2 -> V_2 -> V_77 , V_78 ) ;
V_68 &= ~ V_81 ;
F_53 ( V_2 -> V_2 -> V_77 , V_78 , V_68 ) ;
F_54 ( 1000 , 2000 ) ;
break;
#endif
}
}
void F_55 ( struct V_1 * V_2 )
{
T_1 V_68 ;
switch ( V_2 -> V_2 -> V_69 ) {
#ifdef F_48
case V_70 :
V_68 = F_49 ( V_2 -> V_2 -> V_71 , V_72 ) ;
V_68 &= ~ V_74 ;
V_68 &= ~ V_82 ;
V_68 |= V_75 ;
F_50 ( V_2 -> V_2 -> V_71 , V_72 , V_68 ) ;
F_19 ( 1 ) ;
V_68 = F_49 ( V_2 -> V_2 -> V_71 , V_72 ) ;
V_68 &= ~ V_75 ;
V_68 |= V_82 ;
F_50 ( V_2 -> V_2 -> V_71 , V_72 , V_68 ) ;
F_19 ( 1 ) ;
break;
#endif
#ifdef F_51
case V_76 :
V_68 = F_52 ( V_2 -> V_2 -> V_77 , V_78 ) ;
V_68 &= ~ V_80 ;
V_68 &= ~ V_83 ;
V_68 |= V_81 ;
F_53 ( V_2 -> V_2 -> V_77 , V_78 , V_68 ) ;
F_52 ( V_2 -> V_2 -> V_77 , V_78 ) ;
F_54 ( 1000 , 2000 ) ;
V_68 = F_52 ( V_2 -> V_2 -> V_77 , V_78 ) ;
V_68 &= ~ V_81 ;
V_68 |= V_83 ;
F_53 ( V_2 -> V_2 -> V_77 , V_78 , V_68 ) ;
F_52 ( V_2 -> V_2 -> V_77 , V_78 ) ;
F_54 ( 1000 , 2000 ) ;
break;
#endif
}
}
int F_13 ( struct V_1 * V_2 , unsigned int V_84 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
T_2 V_85 , V_86 ;
int V_5 ;
V_85 = V_84 ;
if ( F_56 ( V_2 -> V_23 ) == V_87 )
V_85 |= V_88 ;
if ( 0 )
V_85 |= V_89 ;
V_86 = F_57 ( V_2 , V_90 , V_91 ) ;
F_58 ( V_2 , V_90 , V_91 , V_85 ) ;
V_5 = V_4 -> V_6 -> V_92 ( V_2 , V_84 ) ;
if ( V_5 )
goto V_93;
F_59 ( 8 ) ;
return 0 ;
V_93:
F_58 ( V_2 , V_90 ,
V_91 , V_86 ) ;
return V_5 ;
}
void F_11 ( struct V_1 * V_2 , bool V_94 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_60 ( V_2 ) ;
V_4 -> V_6 -> V_95 ( V_2 , V_94 ) ;
V_4 -> V_96 = ! V_94 ;
F_61 ( V_2 ) ;
}
void F_62 ( struct V_97 * V_98 )
{
struct V_99 * V_23 = F_63 ( V_98 , struct V_99 ,
V_100 ) ;
struct V_1 * V_2 ;
F_64 ( & V_23 -> V_101 ) ;
V_2 = V_23 -> V_102 ;
if ( F_65 ( V_2 && ( F_27 ( V_2 ) >= V_103 ) ) )
V_2 -> V_4 . V_6 -> V_104 ( V_2 ) ;
F_66 ( & V_23 -> V_101 ) ;
}
void F_67 ( struct V_1 * V_2 , unsigned int V_105 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_106 = V_107 ;
enum V_108 V_109 ;
if ( ! ( V_105 & V_110 ) ) {
if ( F_68 ( V_106 , V_4 -> V_111 ) )
return;
}
V_4 -> V_111 = F_69 ( V_106 + ( V_112 * 2 ) ) ;
if ( ( V_2 -> V_2 -> V_113 == V_114 ) &&
( V_2 -> V_2 -> V_115 == V_116 ) )
return;
V_109 = V_4 -> V_6 -> V_117 ( V_2 , ! ! ( V_105 & V_118 ) ) ;
if ( V_109 == V_119 )
return;
F_8 ( V_109 != V_120 ) ;
F_8 ( V_4 -> V_6 -> V_104 == NULL ) ;
F_70 ( V_2 -> V_23 -> V_24 , & V_2 -> V_23 -> V_100 ) ;
}
int F_71 ( struct V_1 * V_2 , T_2 V_121 )
{
const bool V_122 = ( V_121 != V_123 ) ;
unsigned int V_124 , V_125 , V_126 , V_127 ;
unsigned int V_128 ;
T_1 V_68 ;
V_68 = F_72 ( V_2 , V_90 , V_121 ) ;
V_124 = V_68 & 0xFF ;
V_125 = ( V_68 >> 8 ) & 0xFF ;
V_126 = ( V_68 >> 16 ) & 0xFF ;
V_127 = ( V_68 >> 24 ) & 0xFF ;
if ( V_124 == 0 || V_124 == V_129 ||
V_125 == 0 || V_125 == V_129 ||
V_126 == 0 || V_126 == V_129 ||
V_127 == 0 || V_127 == V_129 )
return - V_130 ;
V_68 = V_129 | ( V_129 << 8 ) |
( V_129 << 16 ) | ( V_129 << 24 ) ;
F_73 ( V_2 , V_90 , V_121 , V_68 ) ;
if ( V_122 ) {
V_124 = ( V_124 + 32 ) & 0x3F ;
V_125 = ( V_125 + 32 ) & 0x3F ;
V_126 = ( V_126 + 32 ) & 0x3F ;
V_127 = ( V_127 + 32 ) & 0x3F ;
}
V_128 = ( V_124 + V_125 + V_126 + V_127 + 2 ) / 4 ;
if ( V_122 ) {
if ( F_57 ( V_2 , V_90 , V_131 )
& V_132 )
V_128 = ( V_128 >= 13 ) ? ( V_128 - 13 ) : 0 ;
}
return V_128 ;
}
void F_74 ( struct V_1 * V_2 , bool V_133 )
{
F_42 ( V_2 , V_134 , V_133 ? 0 : 0xF4 ) ;
}
bool F_75 ( struct V_1 * V_2 )
{
return V_2 -> V_4 . V_22 -> V_135 == V_136 ;
}
void F_76 ( struct V_1 * V_2 , bool V_137 )
{
T_1 V_68 ;
F_77 ( V_2 -> V_4 . type != V_9 &&
V_2 -> V_4 . type != V_13 &&
V_2 -> V_4 . type != V_17 ) ;
switch ( V_2 -> V_2 -> V_69 ) {
#ifdef F_48
case V_70 :
V_68 = F_49 ( V_2 -> V_2 -> V_71 , V_72 ) ;
if ( V_137 )
V_68 |= V_75 ;
else
V_68 &= ~ V_75 ;
F_50 ( V_2 -> V_2 -> V_71 , V_72 , V_68 ) ;
break;
#endif
#ifdef F_51
case V_76 :
V_68 = F_52 ( V_2 -> V_2 -> V_77 , V_78 ) ;
if ( V_137 )
V_68 |= V_81 ;
else
V_68 &= ~ V_81 ;
F_53 ( V_2 -> V_2 -> V_77 , V_78 , V_68 ) ;
break;
#endif
}
}
struct V_138 F_78 ( int V_139 )
{
static const T_1 V_140 [] = {
2949120 , 1740967 , 919879 , 466945 , 234379 , 117304 ,
58666 , 29335 , 14668 , 7334 , 3667 , 1833 ,
917 , 458 , 229 , 115 , 57 , 29 ,
} ;
T_3 V_60 ;
T_4 V_68 ;
T_5 V_141 = 1 ;
T_1 V_142 = 0 ;
struct V_138 V_143 = { . V_60 = 39797 , . V_144 = 0 , } ;
while ( V_139 > ( 180 << 16 ) )
V_139 -= ( 360 << 16 ) ;
while ( V_139 < - ( 180 << 16 ) )
V_139 += ( 360 << 16 ) ;
if ( V_139 > ( 90 << 16 ) ) {
V_139 -= ( 180 << 16 ) ;
V_141 = - 1 ;
} else if ( V_139 < - ( 90 << 16 ) ) {
V_139 += ( 180 << 16 ) ;
V_141 = - 1 ;
}
for ( V_60 = 0 ; V_60 <= 17 ; V_60 ++ ) {
if ( V_139 > V_142 ) {
V_68 = V_143 . V_60 - ( V_143 . V_144 >> V_60 ) ;
V_143 . V_144 += V_143 . V_60 >> V_60 ;
V_143 . V_60 = V_68 ;
V_142 += V_140 [ V_60 ] ;
} else {
V_68 = V_143 . V_60 + ( V_143 . V_144 >> V_60 ) ;
V_143 . V_144 -= V_143 . V_60 >> V_60 ;
V_143 . V_60 = V_68 ;
V_142 -= V_140 [ V_60 ] ;
}
}
V_143 . V_60 *= V_141 ;
V_143 . V_144 *= V_141 ;
return V_143 ;
}
