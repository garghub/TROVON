int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
return V_2 -> V_3 -> V_4 ( V_2 ) ;
else
return 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_5 )
return V_2 -> V_3 -> V_5 ( V_2 ) ;
return 2048 ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_6 )
V_2 -> V_3 -> V_6 ( V_2 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_7 ) ;
if ( ! F_6 ( V_8 , & V_2 -> V_9 ) &&
V_2 -> V_3 -> V_10 )
V_2 -> V_3 -> V_10 ( V_2 ) ;
F_7 ( & V_2 -> V_7 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_7 ) ;
if ( F_9 ( V_8 , & V_2 -> V_9 ) &&
V_2 -> V_3 -> V_11 )
V_2 -> V_3 -> V_11 ( V_2 ) ;
F_7 ( & V_2 -> V_7 ) ;
}
void F_10 ( struct V_1 * V_2 , long V_12 )
{
#ifdef F_11
char V_13 [ 64 ] ;
F_12 ( V_14 L_1 , F_13 ( V_2 , V_13 ) ) ;
#endif
if ( ! V_12 )
V_12 = V_15 ;
if ( F_14 ( V_2 -> V_16 ,
! F_1 ( V_2 ) , V_12 ) >= 0 ) {
if ( V_2 -> V_3 -> V_17 )
V_2 -> V_3 -> V_17 ( V_2 , V_12 ) ;
}
}
static void F_15 ( struct V_18 * V_19 ,
struct V_18 * V_20 ,
struct V_18 * V_21 )
{
int V_22 ;
#define F_16 ( T_1 , T_2 , T_3 ) (x = ((x) & ~(z)) | ((y) & (z)))
if ( ! V_21 ) {
F_12 ( V_23 L_2 ) ;
return;
}
F_16 ( V_19 -> V_24 , V_20 -> V_24 , V_21 -> V_24 ) ;
F_16 ( V_19 -> V_25 , V_20 -> V_25 , V_21 -> V_25 ) ;
F_16 ( V_19 -> V_26 , V_20 -> V_26 , V_21 -> V_26 ) ;
F_16 ( V_19 -> V_27 , V_20 -> V_27 , V_21 -> V_27 ) ;
V_19 -> V_28 = V_21 -> V_28 ? V_20 -> V_28 : V_19 -> V_28 ;
for ( V_22 = 0 ; V_22 < V_29 ; V_22 ++ )
V_19 -> V_30 [ V_22 ] = V_21 -> V_30 [ V_22 ] ?
V_20 -> V_30 [ V_22 ] : V_19 -> V_30 [ V_22 ] ;
}
T_4 F_17 ( struct V_18 * V_19 )
{
unsigned int V_31 ;
V_31 = V_19 -> V_26 & V_32 ;
#ifdef F_18
if ( V_31 == F_18 )
return V_19 -> V_33 ;
#endif
if ( V_31 & V_34 ) {
V_31 &= ~ V_34 ;
if ( V_31 < 1 || V_31 + 15 > V_35 )
V_19 -> V_26 &= ~ V_34 ;
else
V_31 += 15 ;
}
return V_36 [ V_31 ] ;
}
T_4 F_19 ( struct V_18 * V_19 )
{
#ifdef F_20
unsigned int V_31 = ( V_19 -> V_26 >> F_20 ) & V_32 ;
if ( V_31 == V_37 )
return F_17 ( V_19 ) ;
if ( V_31 == F_18 )
return V_19 -> V_38 ;
if ( V_31 & V_34 ) {
V_31 &= ~ V_34 ;
if ( V_31 < 1 || V_31 + 15 > V_35 )
V_19 -> V_26 &= ~ ( V_34 << F_20 ) ;
else
V_31 += 15 ;
}
return V_36 [ V_31 ] ;
#else
return F_17 ( V_19 ) ;
#endif
}
void F_21 ( struct V_18 * V_19 ,
T_4 V_39 , T_4 V_40 )
{
int V_22 = 0 ;
int V_41 = - 1 , V_42 = - 1 ;
int V_43 = V_39 / 50 , V_44 = V_40 / 50 ;
int V_45 = 0 ;
if ( V_40 == 0 )
V_39 = 0 ;
V_19 -> V_38 = V_39 ;
V_19 -> V_33 = V_40 ;
#ifdef F_18
if ( ( V_19 -> V_26 & V_32 ) == F_18 )
V_44 = 0 ;
if ( ( ( V_19 -> V_26 >> F_20 ) & V_32 ) == F_18 )
V_43 = 0 ;
if ( ( V_19 -> V_26 >> F_20 ) & V_32 )
V_45 = 1 ;
#endif
V_19 -> V_26 &= ~ V_32 ;
do {
if ( V_40 - V_44 <= V_36 [ V_22 ] &&
V_40 + V_44 >= V_36 [ V_22 ] ) {
V_19 -> V_26 |= V_46 [ V_22 ] ;
V_42 = V_22 ;
}
if ( V_39 - V_43 <= V_36 [ V_22 ] &&
V_39 + V_43 >= V_36 [ V_22 ] ) {
if ( V_42 == V_22 && ! V_45 )
V_41 = V_22 ;
#ifdef F_20
else {
V_41 = V_22 ;
V_19 -> V_26 |= ( V_46 [ V_22 ] << F_20 ) ;
}
#endif
}
} while ( ++ V_22 < V_35 );
#ifdef F_18
if ( V_42 == - 1 )
V_19 -> V_26 |= F_18 ;
if ( V_41 == - 1 && ( V_39 != V_40 || V_45 ) )
V_19 -> V_26 |= ( F_18 << F_20 ) ;
#else
if ( V_41 == - 1 || V_42 == - 1 ) {
F_22 ( V_23 L_3
L_4 ) ;
}
#endif
}
void F_23 ( struct V_1 * V_2 , T_4 V_39 , T_4 V_40 )
{
F_21 ( & V_2 -> V_19 , V_39 , V_40 ) ;
}
T_4 F_24 ( struct V_1 * V_2 )
{
T_4 V_47 = F_17 ( & V_2 -> V_19 ) ;
if ( V_47 == 38400 && V_2 -> V_48 ) {
if ( ! V_2 -> V_49 ) {
F_12 ( V_23 L_5
L_6 ) ;
V_2 -> V_49 = 1 ;
}
V_47 = V_2 -> V_48 ;
}
return V_47 ;
}
void F_25 ( struct V_18 * V_50 , struct V_18 * V_20 )
{
V_50 -> V_26 &= V_51 | V_52 | V_53 ;
V_50 -> V_26 |= V_20 -> V_26 & ~ ( V_51 | V_52 | V_53 ) ;
V_50 -> V_38 = V_20 -> V_38 ;
V_50 -> V_33 = V_20 -> V_33 ;
}
int F_26 ( struct V_18 * V_54 , struct V_18 * V_55 )
{
if ( V_54 -> V_38 != V_55 -> V_38 || V_54 -> V_33 != V_55 -> V_33 )
return 1 ;
if ( ( V_54 -> V_26 ^ V_55 -> V_26 ) & ~ ( V_51 | V_52 | V_53 ) )
return 1 ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 , struct V_18 * V_56 )
{
struct V_18 V_57 ;
struct V_58 * V_59 ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_7 ) ;
V_57 = V_2 -> V_19 ;
V_2 -> V_19 = * V_56 ;
F_15 ( & V_2 -> V_19 , & V_57 , & V_2 -> V_60 ) ;
if ( V_2 -> V_61 && V_2 -> V_61 -> V_62 ) {
int V_63 = ( V_57 . V_27 & V_64 ) |
( V_2 -> V_19 . V_27 & V_64 ) ;
int V_65 = ( ( V_57 . V_24 & V_66 ) &&
( V_57 . V_30 [ V_67 ] == '\023' ) &&
( V_57 . V_30 [ V_68 ] == '\021' ) ) ;
int V_69 = ( F_28 ( V_2 ) &&
F_29 ( V_2 ) == '\023' &&
F_30 ( V_2 ) == '\021' ) ;
if ( ( V_65 != V_69 ) || V_63 ) {
F_31 ( & V_2 -> V_70 , V_9 ) ;
if ( V_65 != V_69 ) {
V_2 -> V_71 &= ~ ( V_72 | V_73 ) ;
if ( V_69 )
V_2 -> V_71 |= V_72 ;
else
V_2 -> V_71 |= V_73 ;
}
if ( V_63 )
V_2 -> V_71 |= V_74 ;
F_32 ( & V_2 -> V_70 , V_9 ) ;
F_33 ( & V_2 -> V_61 -> V_75 ) ;
}
}
if ( V_2 -> V_3 -> V_76 )
(* V_2 -> V_3 -> V_76 )( V_2 , & V_57 ) ;
else
F_25 ( & V_2 -> V_19 , & V_57 ) ;
V_59 = F_34 ( V_2 ) ;
if ( V_59 != NULL ) {
if ( V_59 -> V_3 -> V_76 )
( V_59 -> V_3 -> V_76 ) ( V_2 , & V_57 ) ;
F_35 ( V_59 ) ;
}
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int V_76 ( struct V_1 * V_2 , void T_5 * V_77 , int V_78 )
{
struct V_18 V_79 ;
struct V_58 * V_59 ;
int V_80 = F_36 ( V_2 ) ;
if ( V_80 )
return V_80 ;
F_5 ( & V_2 -> V_7 ) ;
V_79 = V_2 -> V_19 ;
F_7 ( & V_2 -> V_7 ) ;
if ( V_78 & V_81 ) {
if ( F_37 ( & V_79 ,
(struct V_82 T_5 * ) V_77 ) )
return - V_83 ;
#ifdef F_38
} else if ( V_78 & V_84 ) {
if ( F_39 ( & V_79 ,
(struct V_19 T_5 * ) V_77 ) )
return - V_83 ;
} else {
if ( F_40 ( & V_79 ,
(struct V_85 T_5 * ) V_77 ) )
return - V_83 ;
}
#else
}
void F_41 ( struct V_1 * V_2 , struct V_18 * V_86 )
{
F_5 ( & V_2 -> V_7 ) ;
* V_86 = V_2 -> V_19 ;
F_7 ( & V_2 -> V_7 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_18 * V_86 )
{
F_5 ( & V_2 -> V_7 ) ;
* V_86 = V_2 -> V_60 ;
F_7 ( & V_2 -> V_7 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_82 T_5 * V_82 )
{
struct V_18 V_86 ;
F_41 ( V_2 , & V_86 ) ;
if ( F_44 ( V_82 , & V_86 ) )
return - V_83 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , void T_5 * V_77 , int V_78 )
{
struct V_87 V_88 ;
struct V_58 * V_59 ;
if ( V_2 -> V_87 == NULL )
return - V_89 ;
if ( F_46 ( & V_88 , V_77 , sizeof( struct V_87 ) ) )
return - V_83 ;
V_59 = F_34 ( V_2 ) ;
if ( V_59 != NULL ) {
if ( ( V_78 & V_90 ) && V_59 -> V_3 -> V_6 )
V_59 -> V_3 -> V_6 ( V_2 ) ;
F_35 ( V_59 ) ;
}
if ( V_78 & V_91 ) {
F_10 ( V_2 , 0 ) ;
if ( F_47 ( V_92 ) )
return - V_93 ;
}
F_5 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_3 -> F_45 )
V_2 -> V_3 -> F_45 ( V_2 , & V_88 ) ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
if ( ! ( V_2 -> V_19 . V_27 & V_94 ) ) {
if ( V_2 -> V_19 . V_27 & V_95 )
V_9 |= 0x02 ;
else
V_9 |= 0x20 ;
}
if ( V_2 -> V_19 . V_27 & V_96 )
V_9 |= 0x08 ;
if ( V_2 -> V_19 . V_25 & V_97 )
if ( V_2 -> V_19 . V_25 & V_98 )
V_9 |= 0x10 ;
return V_9 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_99 T_5 * V_99 )
{
struct V_99 V_100 ;
F_5 ( & V_2 -> V_7 ) ;
V_100 . V_101 = V_2 -> V_19 . V_38 ;
V_100 . V_102 = V_2 -> V_19 . V_33 ;
V_100 . V_103 = V_2 -> V_19 . V_30 [ V_104 ] ;
V_100 . V_105 = V_2 -> V_19 . V_30 [ V_106 ] ;
V_100 . V_107 = F_48 ( V_2 ) ;
F_7 ( & V_2 -> V_7 ) ;
return F_50 ( V_99 , & V_100 , sizeof( V_100 ) ) ? - V_83 : 0 ;
}
static void F_51 ( struct V_18 * V_19 , int V_9 )
{
V_19 -> V_24 = V_108 | V_66 ;
V_19 -> V_25 = 0 ;
V_19 -> V_27 = V_95 | V_94 ;
if ( V_9 & 0x02 ) {
V_19 -> V_24 = 0 ;
V_19 -> V_27 &= ~ V_94 ;
}
if ( V_9 & 0x08 ) {
V_19 -> V_27 |= V_96 | V_109 | V_110 |
V_111 | V_112 | V_113 ;
}
if ( V_9 & 0x10 ) {
V_19 -> V_25 |= V_97 | V_98 ;
}
if ( V_9 & 0x20 ) {
V_19 -> V_24 = 0 ;
V_19 -> V_27 &= ~ ( V_95 | V_94 ) ;
}
if ( ! ( V_19 -> V_27 & V_94 ) ) {
V_19 -> V_30 [ V_114 ] = 1 ;
V_19 -> V_30 [ V_115 ] = 0 ;
}
}
static int F_52 ( struct V_1 * V_2 , struct V_99 T_5 * V_99 )
{
int V_80 ;
struct V_99 V_100 ;
struct V_18 V_19 ;
V_80 = F_36 ( V_2 ) ;
if ( V_80 )
return V_80 ;
if ( F_46 ( & V_100 , V_99 , sizeof( V_100 ) ) )
return - V_83 ;
F_5 ( & V_2 -> V_7 ) ;
V_19 = V_2 -> V_19 ;
V_19 . V_30 [ V_104 ] = V_100 . V_103 ;
V_19 . V_30 [ V_106 ] = V_100 . V_105 ;
F_51 ( & V_19 , V_100 . V_107 ) ;
#ifdef F_18
F_21 ( & V_19 , V_19 . V_38 ,
V_19 . V_33 ) ;
#endif
F_7 ( & V_2 -> V_7 ) ;
F_27 ( V_2 , & V_19 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_116 T_5 * V_116 )
{
struct V_116 V_100 ;
F_5 ( & V_2 -> V_7 ) ;
V_100 . V_117 = V_2 -> V_19 . V_30 [ V_118 ] ;
V_100 . V_119 = V_2 -> V_19 . V_30 [ V_120 ] ;
V_100 . V_121 = V_2 -> V_19 . V_30 [ V_68 ] ;
V_100 . V_122 = V_2 -> V_19 . V_30 [ V_67 ] ;
V_100 . V_123 = V_2 -> V_19 . V_30 [ V_124 ] ;
V_100 . V_125 = V_2 -> V_19 . V_30 [ V_126 ] ;
F_7 ( & V_2 -> V_7 ) ;
return F_50 ( V_116 , & V_100 , sizeof( V_100 ) ) ? - V_83 : 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_116 T_5 * V_116 )
{
struct V_116 V_100 ;
if ( F_46 ( & V_100 , V_116 , sizeof( V_100 ) ) )
return - V_83 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_19 . V_30 [ V_118 ] = V_100 . V_117 ;
V_2 -> V_19 . V_30 [ V_120 ] = V_100 . V_119 ;
V_2 -> V_19 . V_30 [ V_68 ] = V_100 . V_121 ;
V_2 -> V_19 . V_30 [ V_67 ] = V_100 . V_122 ;
V_2 -> V_19 . V_30 [ V_124 ] = V_100 . V_123 ;
V_2 -> V_19 . V_30 [ V_126 ] = V_100 . V_125 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_127 T_5 * V_127 )
{
struct V_127 V_100 ;
F_5 ( & V_2 -> V_7 ) ;
V_100 . V_128 = V_2 -> V_19 . V_30 [ V_129 ] ;
V_100 . V_130 = V_2 -> V_19 . V_30 [ V_129 ] ;
V_100 . V_131 = V_2 -> V_19 . V_30 [ V_132 ] ;
V_100 . V_133 = V_2 -> V_19 . V_30 [ V_126 ] ;
V_100 . V_134 = V_2 -> V_19 . V_30 [ V_135 ] ;
V_100 . V_136 = V_2 -> V_19 . V_30 [ V_137 ] ;
F_7 ( & V_2 -> V_7 ) ;
return F_50 ( V_127 , & V_100 , sizeof( V_100 ) ) ? - V_83 : 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_127 T_5 * V_127 )
{
struct V_127 V_100 ;
if ( F_46 ( & V_100 , V_127 , sizeof( V_100 ) ) )
return - V_83 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_19 . V_30 [ V_129 ] = V_100 . V_128 ;
V_2 -> V_19 . V_30 [ V_126 ] = V_100 . V_130 ;
V_2 -> V_19 . V_30 [ V_132 ] = V_100 . V_131 ;
V_2 -> V_19 . V_30 [ V_126 ] = V_100 . V_133 ;
V_2 -> V_19 . V_30 [ V_135 ] = V_100 . V_134 ;
V_2 -> V_19 . V_30 [ V_137 ] = V_100 . V_136 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , char V_138 )
{
int V_139 = V_2 -> V_140 ;
if ( V_2 -> V_3 -> V_141 ) {
V_2 -> V_3 -> V_141 ( V_2 , V_138 ) ;
return 0 ;
}
if ( F_58 ( V_2 , 0 ) < 0 )
return - V_142 ;
if ( V_139 )
F_59 ( V_2 ) ;
V_2 -> V_3 -> V_143 ( V_2 , & V_138 , 1 ) ;
if ( V_139 )
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_77 )
{
int V_144 = 0 ;
int V_145 = V_77 ? V_53 : 0 ;
struct V_18 V_20 ;
F_5 ( & V_2 -> V_7 ) ;
V_20 = V_2 -> V_19 ;
V_2 -> V_19 . V_26 &= ~ V_53 ;
V_2 -> V_19 . V_26 |= V_145 ;
if ( V_2 -> V_3 -> V_76 )
V_2 -> V_3 -> V_76 ( V_2 , & V_20 ) ;
if ( ( V_2 -> V_19 . V_26 & V_53 ) != V_145 )
V_144 = - V_89 ;
F_7 ( & V_2 -> V_7 ) ;
return V_144 ;
}
int F_63 ( struct V_1 * V_2 , struct V_146 * V_146 ,
unsigned int V_147 , unsigned long V_77 )
{
struct V_1 * V_148 ;
void T_5 * V_149 = ( void T_5 * ) V_77 ;
int V_144 = 0 ;
struct V_18 V_86 ;
F_64 ( V_146 == NULL ) ;
if ( V_2 -> V_150 -> type == V_151 &&
V_2 -> V_150 -> V_152 == V_153 )
V_148 = V_2 -> V_61 ;
else
V_148 = V_2 ;
switch ( V_147 ) {
#ifdef F_65
case F_65 :
return F_49 ( V_148 , (struct V_99 T_5 * ) V_77 ) ;
case V_154 :
case V_155 :
return F_52 ( V_148 , (struct V_99 T_5 * ) V_77 ) ;
#endif
#ifdef F_66
case F_66 :
return F_53 ( V_148 , V_149 ) ;
case V_156 :
return F_54 ( V_148 , V_149 ) ;
#endif
#ifdef F_67
case F_67 :
return F_55 ( V_148 , V_149 ) ;
case V_157 :
return F_56 ( V_148 , V_149 ) ;
#endif
case V_158 :
return V_76 ( V_148 , V_149 , V_90 | V_91 | V_84 ) ;
case V_159 :
return V_76 ( V_148 , V_149 , V_91 | V_84 ) ;
case V_160 :
return V_76 ( V_148 , V_149 , V_84 ) ;
#ifndef F_38
case V_161 :
F_41 ( V_148 , & V_86 ) ;
if ( F_68 ( (struct V_19 T_5 * ) V_77 , & V_86 ) )
V_144 = - V_83 ;
return V_144 ;
#else
case V_161 :
F_41 ( V_148 , & V_86 ) ;
if ( F_69 ( (struct V_19 T_5 * ) V_77 , & V_86 ) )
V_144 = - V_83 ;
return V_144 ;
case F_38 :
F_41 ( V_148 , & V_86 ) ;
if ( F_68 ( (struct V_85 T_5 * ) V_77 , & V_86 ) )
V_144 = - V_83 ;
return V_144 ;
case V_162 :
return V_76 ( V_148 , V_149 , V_90 | V_91 ) ;
case V_163 :
return V_76 ( V_148 , V_149 , V_91 ) ;
case V_164 :
return V_76 ( V_148 , V_149 , 0 ) ;
#endif
case V_165 :
return F_43 ( V_148 , V_149 ) ;
case V_166 :
return V_76 ( V_148 , V_149 , V_90 | V_91 | V_81 ) ;
case V_167 :
return V_76 ( V_148 , V_149 , V_91 | V_81 ) ;
case V_168 :
return V_76 ( V_148 , V_149 , V_81 ) ;
#ifndef F_38
case V_169 :
F_42 ( V_148 , & V_86 ) ;
if ( F_68 ( (struct V_19 T_5 * ) V_77 , & V_86 ) )
V_144 = - V_83 ;
return V_144 ;
case V_170 :
if ( ! F_70 ( V_171 ) )
return - V_172 ;
F_42 ( V_148 , & V_86 ) ;
if ( F_40 ( & V_86 ,
(struct V_19 T_5 * ) V_77 ) )
return - V_83 ;
F_5 ( & V_148 -> V_7 ) ;
V_148 -> V_60 = V_86 ;
F_7 ( & V_148 -> V_7 ) ;
return 0 ;
#else
case V_169 :
F_42 ( V_148 , & V_86 ) ;
if ( F_69 ( (struct V_19 T_5 * ) V_77 , & V_86 ) )
V_144 = - V_83 ;
return V_144 ;
case V_170 :
if ( ! F_70 ( V_171 ) )
return - V_172 ;
F_42 ( V_148 , & V_86 ) ;
if ( F_39 ( & V_86 ,
(struct V_19 T_5 * ) V_77 ) )
return - V_83 ;
F_5 ( & V_148 -> V_7 ) ;
V_148 -> V_60 = V_86 ;
F_7 ( & V_148 -> V_7 ) ;
return V_144 ;
#endif
#ifdef F_71
case F_71 : {
struct V_87 V_173 ;
if ( V_148 -> V_87 == NULL )
return - V_89 ;
F_5 ( & V_148 -> V_7 ) ;
memcpy ( & V_173 , V_148 -> V_87 , sizeof( struct V_87 ) ) ;
F_7 ( & V_148 -> V_7 ) ;
if ( F_50 ( V_149 , & V_173 , sizeof( struct V_87 ) ) )
V_144 = - V_83 ;
return V_144 ;
}
case V_174 :
return F_45 ( V_148 , V_149 , 0 ) ;
case V_175 :
return F_45 ( V_148 , V_149 , V_91 ) ;
case V_176 :
return F_45 ( V_148 , V_149 , V_90 ) ;
#endif
case V_177 :
F_41 ( V_148 , & V_86 ) ;
V_144 = F_72 ( ( V_86 . V_26 & V_53 ) ? 1 : 0 ,
( int T_5 * ) V_77 ) ;
return V_144 ;
case V_178 :
if ( F_73 ( V_77 , ( unsigned int T_5 * ) V_77 ) )
return - V_83 ;
return F_62 ( V_148 , V_77 ) ;
default:
return - V_179 ;
}
}
int F_74 ( struct V_1 * V_2 , unsigned long V_77 )
{
struct V_58 * V_59 ;
int V_80 = F_36 ( V_2 ) ;
if ( V_80 )
return V_80 ;
V_59 = F_75 ( V_2 ) ;
switch ( V_77 ) {
case V_180 :
if ( V_59 && V_59 -> V_3 -> V_6 )
V_59 -> V_3 -> V_6 ( V_2 ) ;
break;
case V_181 :
if ( V_59 && V_59 -> V_3 -> V_6 )
V_59 -> V_3 -> V_6 ( V_2 ) ;
case V_182 :
F_3 ( V_2 ) ;
break;
default:
F_35 ( V_59 ) ;
return - V_89 ;
}
F_35 ( V_59 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 , struct V_146 * V_146 ,
unsigned int V_147 , unsigned long V_77 )
{
int V_80 ;
switch ( V_147 ) {
case V_183 :
V_80 = F_36 ( V_2 ) ;
if ( V_80 )
return V_80 ;
switch ( V_77 ) {
case V_184 :
if ( ! V_2 -> V_185 ) {
V_2 -> V_185 = 1 ;
F_60 ( V_2 ) ;
}
break;
case V_186 :
if ( V_2 -> V_185 ) {
V_2 -> V_185 = 0 ;
F_59 ( V_2 ) ;
}
break;
case V_187 :
if ( F_29 ( V_2 ) != V_188 )
return F_57 ( V_2 , F_29 ( V_2 ) ) ;
break;
case V_189 :
if ( F_30 ( V_2 ) != V_188 )
return F_57 ( V_2 , F_30 ( V_2 ) ) ;
break;
default:
return - V_89 ;
}
return 0 ;
case V_190 :
return F_74 ( V_2 , V_77 ) ;
default:
return F_63 ( V_2 , V_146 , V_147 , V_77 ) ;
}
}
long F_77 ( struct V_1 * V_2 , struct V_146 * V_146 ,
unsigned int V_147 , unsigned long V_77 )
{
switch ( V_147 ) {
case V_169 :
case V_170 :
return F_63 ( V_2 , V_146 , V_147 , ( unsigned long ) F_78 ( V_77 ) ) ;
default:
return - V_179 ;
}
}
