int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
int V_5 ;
V_4 -> V_6 = NULL ;
switch ( V_4 -> type ) {
case V_7 :
V_4 -> V_6 = & V_8 ;
break;
case V_9 :
V_4 -> V_6 = & V_10 ;
break;
case V_11 :
#ifdef F_2
V_4 -> V_6 = & V_12 ;
#endif
break;
case V_13 :
#ifdef F_3
V_4 -> V_6 = & V_14 ;
#endif
break;
case V_15 :
#ifdef F_4
V_4 -> V_6 = & V_16 ;
#endif
break;
case V_17 :
#ifdef F_5
V_4 -> V_6 = & V_18 ;
#endif
break;
}
if ( F_6 ( ! V_4 -> V_6 ) )
return - V_19 ;
V_5 = V_4 -> V_6 -> V_20 ( V_2 ) ;
if ( V_5 )
V_4 -> V_6 = NULL ;
return V_5 ;
}
void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_4 . V_6 -> free ( V_2 ) ;
V_2 -> V_4 . V_6 = NULL ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
const struct V_21 * V_6 = V_4 -> V_6 ;
int V_5 ;
V_4 -> V_22 = V_6 -> V_23 ( V_2 ) ;
V_6 -> V_24 ( V_2 , false ) ;
V_5 = V_6 -> V_25 ( V_2 ) ;
if ( V_5 ) {
F_9 ( V_2 -> V_26 , L_1 ) ;
goto V_27;
}
V_5 = F_10 ( V_2 , V_6 -> V_23 ( V_2 ) ) ;
if ( V_5 ) {
F_9 ( V_2 -> V_26 , L_2 ) ;
goto V_28;
}
return 0 ;
V_28:
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
V_27:
V_6 -> V_24 ( V_2 , true ) ;
return V_5 ;
}
void F_11 ( struct V_1 * V_2 )
{
const struct V_21 * V_6 = V_2 -> V_4 . V_6 ;
V_6 -> V_24 ( V_2 , true ) ;
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
}
bool F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_29 )
return 0 ;
if ( ! V_2 -> V_4 . V_6 -> V_30 )
return 0 ;
return V_2 -> V_4 . V_6 -> V_30 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
T_1 V_31 ;
#if V_32
F_6 ( V_2 -> V_4 . V_33 ) ;
V_2 -> V_4 . V_33 = true ;
#endif
V_31 = F_14 ( V_2 , V_34 ) ;
V_31 |= V_35 ;
F_15 ( V_2 , V_34 , V_31 ) ;
F_14 ( V_2 , V_34 ) ;
F_16 ( 10 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
T_1 V_31 ;
#if V_32
F_6 ( ! V_2 -> V_4 . V_33 ) ;
V_2 -> V_4 . V_33 = false ;
#endif
F_18 ( V_2 , V_36 ) ;
V_31 = F_14 ( V_2 , V_34 ) ;
V_31 &= ~ V_35 ;
F_15 ( V_2 , V_34 , V_31 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
#if V_32
F_6 ( V_2 -> V_4 . V_37 ) ;
V_2 -> V_4 . V_37 = true ;
#endif
F_6 ( V_2 -> V_2 -> V_38 < 3 ) ;
if ( ! F_20 ( V_2 -> V_26 , V_39 ) )
F_21 ( V_2 , V_40 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
#if V_32
F_6 ( ! V_2 -> V_4 . V_37 ) ;
V_2 -> V_4 . V_37 = false ;
#endif
F_6 ( V_2 -> V_2 -> V_38 < 3 ) ;
if ( ! F_20 ( V_2 -> V_26 , V_39 ) )
F_21 ( V_2 , 0 ) ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
if ( ! V_32 )
return;
if ( ( F_24 ( V_2 ) >= V_41 ) &&
( V_2 -> V_42 <= 0 ) ) {
F_25 ( V_2 -> V_26 , L_3
L_4 ) ;
F_26 () ;
}
}
T_2 F_27 ( struct V_1 * V_2 , T_2 V_43 )
{
F_23 ( V_2 ) ;
return V_2 -> V_4 . V_6 -> V_44 ( V_2 , V_43 ) ;
}
void F_28 ( struct V_1 * V_2 , T_2 V_43 , T_2 V_45 )
{
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_46 ( V_2 , V_43 , V_45 ) ;
}
void F_29 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_48 )
{
F_30 ( V_2 , V_47 ,
F_31 ( V_2 , V_47 ) & V_48 ) ;
}
void F_32 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_49 )
{
F_30 ( V_2 , V_47 ,
F_31 ( V_2 , V_47 ) | V_49 ) ;
}
void F_33 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_48 , T_2 V_49 )
{
F_30 ( V_2 , V_47 ,
( F_31 ( V_2 , V_47 ) & V_48 ) | V_49 ) ;
}
bool F_34 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_48 ,
T_2 V_45 , int V_50 , int V_51 )
{
T_2 V_52 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_51 ; V_53 += V_50 ) {
V_52 = F_27 ( V_2 , V_47 ) ;
if ( ( V_52 & V_48 ) == V_45 )
return true ;
F_16 ( V_50 ) ;
}
return false ;
}
T_2 F_35 ( struct V_1 * V_2 , T_2 V_43 )
{
F_23 ( V_2 ) ;
V_2 -> V_4 . V_54 = 0 ;
return V_2 -> V_4 . V_6 -> V_55 ( V_2 , V_43 ) ;
}
void F_36 ( struct V_1 * V_2 , T_2 V_43 , T_2 V_45 )
{
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_56 ( V_2 , V_43 , V_45 ) ;
if ( ++ V_2 -> V_4 . V_54 == V_57 ) {
F_18 ( V_2 , V_36 ) ;
V_2 -> V_4 . V_54 = 0 ;
}
}
void F_37 ( struct V_1 * V_2 , T_2 V_58 , T_2 V_59 )
{
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_56 ( V_2 , V_58 ,
V_2 -> V_4 . V_6 -> V_55 ( V_2 , V_59 ) ) ;
}
void F_38 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_48 )
{
if ( V_2 -> V_4 . V_6 -> V_60 ) {
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_60 ( V_2 , V_47 , V_48 , 0 ) ;
} else {
F_36 ( V_2 , V_47 ,
F_35 ( V_2 , V_47 ) & V_48 ) ;
}
}
void F_39 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_49 )
{
if ( V_2 -> V_4 . V_6 -> V_60 ) {
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_60 ( V_2 , V_47 , 0xFFFF , V_49 ) ;
} else {
F_36 ( V_2 , V_47 ,
F_35 ( V_2 , V_47 ) | V_49 ) ;
}
}
void F_40 ( struct V_1 * V_2 , T_2 V_47 , T_2 V_48 , T_2 V_49 )
{
if ( V_2 -> V_4 . V_6 -> V_60 ) {
F_23 ( V_2 ) ;
V_2 -> V_4 . V_6 -> V_60 ( V_2 , V_47 , V_48 , V_49 ) ;
} else {
F_36 ( V_2 , V_47 ,
( F_35 ( V_2 , V_47 ) & V_48 ) | V_49 ) ;
}
}
int F_10 ( struct V_1 * V_2 , unsigned int V_61 )
{
struct V_3 * V_4 = & ( V_2 -> V_4 ) ;
T_2 V_62 , V_63 ;
int V_5 ;
if ( V_61 == V_64 )
V_61 = V_4 -> V_6 -> V_23 ( V_2 ) ;
V_62 = V_61 ;
if ( F_41 ( V_2 -> V_26 ) == V_65 )
V_62 |= V_66 ;
if ( 0 )
V_62 |= V_67 ;
V_63 = F_42 ( V_2 , V_68 , V_69 ) ;
F_43 ( V_2 , V_68 , V_69 , V_62 ) ;
V_5 = V_4 -> V_6 -> V_70 ( V_2 , V_61 ) ;
if ( V_5 )
goto V_71;
V_2 -> V_4 . V_22 = V_61 ;
F_44 ( 8 ) ;
return 0 ;
V_71:
F_43 ( V_2 , V_68 ,
V_69 , V_63 ) ;
return V_5 ;
}
void F_45 ( struct V_1 * V_2 , bool V_72 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_46 ( V_2 ) ;
V_4 -> V_6 -> V_24 ( V_2 , V_72 ) ;
V_4 -> V_73 = ! V_72 ;
F_47 ( V_2 ) ;
}
void F_48 ( struct V_74 * V_75 )
{
struct V_76 * V_26 = F_49 ( V_75 , struct V_76 ,
V_77 ) ;
struct V_1 * V_2 ;
F_50 ( & V_26 -> V_78 ) ;
V_2 = V_26 -> V_79 ;
if ( F_51 ( V_2 && ( F_24 ( V_2 ) >= V_80 ) ) )
V_2 -> V_4 . V_6 -> V_81 ( V_2 ) ;
F_52 ( & V_26 -> V_78 ) ;
}
void F_53 ( struct V_1 * V_2 , unsigned int V_82 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_83 = V_84 ;
enum V_85 V_86 ;
if ( ! ( V_82 & V_87 ) ) {
if ( F_54 ( V_83 , V_4 -> V_88 ) )
return;
}
V_4 -> V_88 = F_55 ( V_83 + ( V_89 * 2 ) ) ;
if ( ( V_2 -> V_2 -> V_90 == V_91 ) &&
( V_2 -> V_2 -> V_92 == V_93 ) )
return;
V_86 = V_4 -> V_6 -> V_94 ( V_2 , ! ! ( V_82 & V_95 ) ) ;
if ( V_86 == V_96 )
return;
F_6 ( V_86 != V_97 ) ;
F_6 ( V_4 -> V_6 -> V_81 == NULL ) ;
F_56 ( V_2 -> V_26 -> V_98 , & V_2 -> V_26 -> V_77 ) ;
}
int F_57 ( struct V_1 * V_2 , T_2 V_99 )
{
const bool V_100 = ( V_99 != V_101 ) ;
unsigned int V_102 , V_103 , V_104 , V_105 ;
unsigned int V_106 ;
T_1 V_107 ;
V_107 = F_58 ( V_2 , V_68 , V_99 ) ;
V_102 = V_107 & 0xFF ;
V_103 = ( V_107 >> 8 ) & 0xFF ;
V_104 = ( V_107 >> 16 ) & 0xFF ;
V_105 = ( V_107 >> 24 ) & 0xFF ;
if ( V_102 == 0 || V_102 == V_108 ||
V_103 == 0 || V_103 == V_108 ||
V_104 == 0 || V_104 == V_108 ||
V_105 == 0 || V_105 == V_108 )
return - V_109 ;
V_107 = V_108 | ( V_108 << 8 ) |
( V_108 << 16 ) | ( V_108 << 24 ) ;
F_59 ( V_2 , V_68 , V_99 , V_107 ) ;
if ( V_100 ) {
V_102 = ( V_102 + 32 ) & 0x3F ;
V_103 = ( V_103 + 32 ) & 0x3F ;
V_104 = ( V_104 + 32 ) & 0x3F ;
V_105 = ( V_105 + 32 ) & 0x3F ;
}
V_106 = ( V_102 + V_103 + V_104 + V_105 + 2 ) / 4 ;
if ( V_100 ) {
if ( F_42 ( V_2 , V_68 , V_110 )
& V_111 )
V_106 = ( V_106 >= 13 ) ? ( V_106 - 13 ) : 0 ;
}
return V_106 ;
}
void F_60 ( struct V_1 * V_2 , bool V_112 )
{
F_61 ( V_2 , V_113 , V_112 ? 0 : 0xF4 ) ;
}
bool F_62 ( enum V_114 V_115 )
{
return ( V_115 == V_116 ||
V_115 == V_117 ) ;
}
void F_63 ( struct V_1 * V_2 , bool V_118 )
{
T_1 V_107 ;
F_64 ( V_2 -> V_4 . type != V_11 &&
V_2 -> V_4 . type != V_15 ) ;
switch ( V_2 -> V_2 -> V_119 ) {
#ifdef F_65
case V_120 :
V_107 = F_66 ( V_2 -> V_2 -> V_121 , V_122 ) ;
if ( V_118 )
V_107 |= V_123 ;
else
V_107 &= ~ V_123 ;
F_67 ( V_2 -> V_2 -> V_121 , V_122 , V_107 ) ;
break;
#endif
#ifdef F_68
case V_124 :
V_107 = F_69 ( V_2 -> V_2 -> V_125 , V_126 ) ;
if ( V_118 )
V_107 |= V_127 ;
else
V_107 &= ~ V_127 ;
F_70 ( V_2 -> V_2 -> V_125 , V_126 , V_107 ) ;
break;
#endif
}
}
struct V_128 F_71 ( int V_129 )
{
static const T_1 V_130 [] = {
2949120 , 1740967 , 919879 , 466945 , 234379 , 117304 ,
58666 , 29335 , 14668 , 7334 , 3667 , 1833 ,
917 , 458 , 229 , 115 , 57 , 29 ,
} ;
T_3 V_53 ;
T_4 V_107 ;
T_5 V_131 = 1 ;
T_1 V_132 = 0 ;
struct V_128 V_133 = { . V_53 = 39797 , . V_134 = 0 , } ;
while ( V_129 > ( 180 << 16 ) )
V_129 -= ( 360 << 16 ) ;
while ( V_129 < - ( 180 << 16 ) )
V_129 += ( 360 << 16 ) ;
if ( V_129 > ( 90 << 16 ) ) {
V_129 -= ( 180 << 16 ) ;
V_131 = - 1 ;
} else if ( V_129 < - ( 90 << 16 ) ) {
V_129 += ( 180 << 16 ) ;
V_131 = - 1 ;
}
for ( V_53 = 0 ; V_53 <= 17 ; V_53 ++ ) {
if ( V_129 > V_132 ) {
V_107 = V_133 . V_53 - ( V_133 . V_134 >> V_53 ) ;
V_133 . V_134 += V_133 . V_53 >> V_53 ;
V_133 . V_53 = V_107 ;
V_132 += V_130 [ V_53 ] ;
} else {
V_107 = V_133 . V_53 + ( V_133 . V_134 >> V_53 ) ;
V_133 . V_134 -= V_133 . V_53 >> V_53 ;
V_133 . V_53 = V_107 ;
V_132 -= V_130 [ V_53 ] ;
}
}
V_133 . V_53 *= V_131 ;
V_133 . V_134 *= V_131 ;
return V_133 ;
}
