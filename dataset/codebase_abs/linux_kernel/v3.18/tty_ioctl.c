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
V_2 -> V_11 = 0 ;
F_7 ( & V_2 -> V_7 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_7 ) ;
if ( F_9 ( V_8 , & V_2 -> V_9 ) &&
V_2 -> V_3 -> V_12 )
V_2 -> V_3 -> V_12 ( V_2 ) ;
V_2 -> V_11 = 0 ;
F_7 ( & V_2 -> V_7 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_11 ( & V_2 -> V_14 ) ;
if ( ! F_12 ( V_8 , & V_2 -> V_9 ) ) {
if ( V_2 -> V_11 != V_15 )
V_13 = 1 ;
else {
F_13 ( V_8 , & V_2 -> V_9 ) ;
if ( V_2 -> V_3 -> V_10 )
V_2 -> V_3 -> V_10 ( V_2 ) ;
}
}
F_14 ( & V_2 -> V_14 ) ;
return V_13 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_11 ( & V_2 -> V_14 ) ;
if ( F_12 ( V_8 , & V_2 -> V_9 ) ) {
if ( V_2 -> V_11 != V_16 )
V_13 = 1 ;
else {
F_16 ( V_8 , & V_2 -> V_9 ) ;
if ( V_2 -> V_3 -> V_12 )
V_2 -> V_3 -> V_12 ( V_2 ) ;
}
}
F_14 ( & V_2 -> V_14 ) ;
return V_13 ;
}
void F_17 ( struct V_1 * V_2 , long V_17 )
{
#ifdef F_18
char V_18 [ 64 ] ;
F_19 ( V_19 L_1 , F_20 ( V_2 , V_18 ) ) ;
#endif
if ( ! V_17 )
V_17 = V_20 ;
if ( F_21 ( V_2 -> V_21 ,
! F_1 ( V_2 ) , V_17 ) >= 0 ) {
if ( V_2 -> V_3 -> V_22 )
V_2 -> V_3 -> V_22 ( V_2 , V_17 ) ;
}
}
static void F_22 ( struct V_23 * V_24 ,
struct V_23 * V_25 ,
struct V_23 * V_26 )
{
int V_27 ;
#define F_23 ( T_1 , T_2 , T_3 ) (x = ((x) & ~(z)) | ((y) & (z)))
if ( ! V_26 ) {
F_19 ( V_28 L_2 ) ;
return;
}
F_23 ( V_24 -> V_29 , V_25 -> V_29 , V_26 -> V_29 ) ;
F_23 ( V_24 -> V_30 , V_25 -> V_30 , V_26 -> V_30 ) ;
F_23 ( V_24 -> V_31 , V_25 -> V_31 , V_26 -> V_31 ) ;
F_23 ( V_24 -> V_32 , V_25 -> V_32 , V_26 -> V_32 ) ;
V_24 -> V_33 = V_26 -> V_33 ? V_25 -> V_33 : V_24 -> V_33 ;
for ( V_27 = 0 ; V_27 < V_34 ; V_27 ++ )
V_24 -> V_35 [ V_27 ] = V_26 -> V_35 [ V_27 ] ?
V_25 -> V_35 [ V_27 ] : V_24 -> V_35 [ V_27 ] ;
}
T_4 F_24 ( struct V_23 * V_24 )
{
unsigned int V_36 ;
V_36 = V_24 -> V_31 & V_37 ;
#ifdef F_25
if ( V_36 == F_25 )
return V_24 -> V_38 ;
#endif
if ( V_36 & V_39 ) {
V_36 &= ~ V_39 ;
if ( V_36 < 1 || V_36 + 15 > V_40 )
V_24 -> V_31 &= ~ V_39 ;
else
V_36 += 15 ;
}
return V_41 [ V_36 ] ;
}
T_4 F_26 ( struct V_23 * V_24 )
{
#ifdef F_27
unsigned int V_36 = ( V_24 -> V_31 >> F_27 ) & V_37 ;
if ( V_36 == V_42 )
return F_24 ( V_24 ) ;
if ( V_36 == F_25 )
return V_24 -> V_43 ;
if ( V_36 & V_39 ) {
V_36 &= ~ V_39 ;
if ( V_36 < 1 || V_36 + 15 > V_40 )
V_24 -> V_31 &= ~ ( V_39 << F_27 ) ;
else
V_36 += 15 ;
}
return V_41 [ V_36 ] ;
#else
return F_24 ( V_24 ) ;
#endif
}
void F_28 ( struct V_23 * V_24 ,
T_4 V_44 , T_4 V_45 )
{
int V_27 = 0 ;
int V_46 = - 1 , V_47 = - 1 ;
int V_48 = V_44 / 50 , V_49 = V_45 / 50 ;
int V_50 = 0 ;
if ( V_45 == 0 )
V_44 = 0 ;
V_24 -> V_43 = V_44 ;
V_24 -> V_38 = V_45 ;
#ifdef F_25
if ( ( V_24 -> V_31 & V_37 ) == F_25 )
V_49 = 0 ;
if ( ( ( V_24 -> V_31 >> F_27 ) & V_37 ) == F_25 )
V_48 = 0 ;
if ( ( V_24 -> V_31 >> F_27 ) & V_37 )
V_50 = 1 ;
#endif
V_24 -> V_31 &= ~ V_37 ;
do {
if ( V_45 - V_49 <= V_41 [ V_27 ] &&
V_45 + V_49 >= V_41 [ V_27 ] ) {
V_24 -> V_31 |= V_51 [ V_27 ] ;
V_47 = V_27 ;
}
if ( V_44 - V_48 <= V_41 [ V_27 ] &&
V_44 + V_48 >= V_41 [ V_27 ] ) {
if ( V_47 == V_27 && ! V_50 )
V_46 = V_27 ;
#ifdef F_27
else {
V_46 = V_27 ;
V_24 -> V_31 |= ( V_51 [ V_27 ] << F_27 ) ;
}
#endif
}
} while ( ++ V_27 < V_40 );
#ifdef F_25
if ( V_47 == - 1 )
V_24 -> V_31 |= F_25 ;
if ( V_46 == - 1 && ( V_44 != V_45 || V_50 ) )
V_24 -> V_31 |= ( F_25 << F_27 ) ;
#else
if ( V_46 == - 1 || V_47 == - 1 ) {
F_29 ( V_28 L_3
L_4 ) ;
}
#endif
}
void F_30 ( struct V_1 * V_2 , T_4 V_44 , T_4 V_45 )
{
F_28 ( & V_2 -> V_24 , V_44 , V_45 ) ;
}
void F_31 ( struct V_23 * V_52 , struct V_23 * V_25 )
{
V_52 -> V_31 &= V_53 | V_54 | V_55 ;
V_52 -> V_31 |= V_25 -> V_31 & ~ ( V_53 | V_54 | V_55 ) ;
V_52 -> V_43 = V_25 -> V_43 ;
V_52 -> V_38 = V_25 -> V_38 ;
}
int F_32 ( struct V_23 * V_56 , struct V_23 * V_57 )
{
if ( V_56 -> V_43 != V_57 -> V_43 || V_56 -> V_38 != V_57 -> V_38 )
return 1 ;
if ( ( V_56 -> V_31 ^ V_57 -> V_31 ) & ~ ( V_53 | V_54 | V_55 ) )
return 1 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_23 * V_58 )
{
struct V_23 V_59 ;
struct V_60 * V_61 ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_7 ) ;
V_59 = V_2 -> V_24 ;
V_2 -> V_24 = * V_58 ;
F_22 ( & V_2 -> V_24 , & V_59 , & V_2 -> V_62 ) ;
if ( V_2 -> V_63 && V_2 -> V_63 -> V_64 ) {
int V_65 = ( V_59 . V_32 & V_66 ) |
( V_2 -> V_24 . V_32 & V_66 ) ;
int V_67 = ( ( V_59 . V_29 & V_68 ) &&
( V_59 . V_35 [ V_69 ] == '\023' ) &&
( V_59 . V_35 [ V_70 ] == '\021' ) ) ;
int V_71 = ( F_34 ( V_2 ) &&
F_35 ( V_2 ) == '\023' &&
F_36 ( V_2 ) == '\021' ) ;
if ( ( V_67 != V_71 ) || V_65 ) {
F_37 ( & V_2 -> V_72 , V_9 ) ;
if ( V_67 != V_71 ) {
V_2 -> V_73 &= ~ ( V_74 | V_75 ) ;
if ( V_71 )
V_2 -> V_73 |= V_74 ;
else
V_2 -> V_73 |= V_75 ;
}
if ( V_65 )
V_2 -> V_73 |= V_76 ;
F_38 ( & V_2 -> V_72 , V_9 ) ;
F_39 ( & V_2 -> V_63 -> V_77 ) ;
}
}
if ( V_2 -> V_3 -> V_78 )
(* V_2 -> V_3 -> V_78 )( V_2 , & V_59 ) ;
else
F_31 ( & V_2 -> V_24 , & V_59 ) ;
V_61 = F_40 ( V_2 ) ;
if ( V_61 != NULL ) {
if ( V_61 -> V_3 -> V_78 )
( V_61 -> V_3 -> V_78 ) ( V_2 , & V_59 ) ;
F_41 ( V_61 ) ;
}
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int V_78 ( struct V_1 * V_2 , void T_5 * V_79 , int V_80 )
{
struct V_23 V_81 ;
struct V_60 * V_61 ;
int V_82 = F_42 ( V_2 ) ;
if ( V_82 )
return V_82 ;
F_43 ( & V_2 -> V_7 ) ;
V_81 = V_2 -> V_24 ;
F_44 ( & V_2 -> V_7 ) ;
if ( V_80 & V_83 ) {
if ( F_45 ( & V_81 ,
(struct V_84 T_5 * ) V_79 ) )
return - V_85 ;
#ifdef F_46
} else if ( V_80 & V_86 ) {
if ( F_47 ( & V_81 ,
(struct V_24 T_5 * ) V_79 ) )
return - V_85 ;
} else {
if ( F_48 ( & V_81 ,
(struct V_87 T_5 * ) V_79 ) )
return - V_85 ;
}
#else
}
void F_49 ( struct V_1 * V_2 , struct V_23 * V_88 )
{
F_43 ( & V_2 -> V_7 ) ;
* V_88 = V_2 -> V_24 ;
F_44 ( & V_2 -> V_7 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_23 * V_88 )
{
F_43 ( & V_2 -> V_7 ) ;
* V_88 = V_2 -> V_62 ;
F_44 ( & V_2 -> V_7 ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_84 T_5 * V_84 )
{
struct V_23 V_88 ;
F_49 ( V_2 , & V_88 ) ;
if ( F_52 ( V_84 , & V_88 ) )
return - V_85 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , void T_5 * V_79 , int V_80 )
{
struct V_89 V_90 ;
struct V_60 * V_61 ;
if ( V_2 -> V_89 == NULL )
return - V_91 ;
if ( F_54 ( & V_90 , V_79 , sizeof( struct V_89 ) ) )
return - V_85 ;
V_61 = F_40 ( V_2 ) ;
if ( V_61 != NULL ) {
if ( ( V_80 & V_92 ) && V_61 -> V_3 -> V_6 )
V_61 -> V_3 -> V_6 ( V_2 ) ;
F_41 ( V_61 ) ;
}
if ( V_80 & V_93 ) {
F_17 ( V_2 , 0 ) ;
if ( F_55 ( V_94 ) )
return - V_95 ;
}
F_5 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_3 -> F_53 )
V_2 -> V_3 -> F_53 ( V_2 , & V_90 ) ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
if ( ! ( V_2 -> V_24 . V_32 & V_96 ) ) {
if ( V_2 -> V_24 . V_32 & V_97 )
V_9 |= 0x02 ;
else
V_9 |= 0x20 ;
}
if ( V_2 -> V_24 . V_32 & V_98 )
V_9 |= 0x08 ;
if ( V_2 -> V_24 . V_30 & V_99 )
if ( V_2 -> V_24 . V_30 & V_100 )
V_9 |= 0x10 ;
return V_9 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_101 T_5 * V_101 )
{
struct V_101 V_102 ;
F_43 ( & V_2 -> V_7 ) ;
V_102 . V_103 = V_2 -> V_24 . V_43 ;
V_102 . V_104 = V_2 -> V_24 . V_38 ;
V_102 . V_105 = V_2 -> V_24 . V_35 [ V_106 ] ;
V_102 . V_107 = V_2 -> V_24 . V_35 [ V_108 ] ;
V_102 . V_109 = F_56 ( V_2 ) ;
F_44 ( & V_2 -> V_7 ) ;
return F_58 ( V_101 , & V_102 , sizeof( V_102 ) ) ? - V_85 : 0 ;
}
static void F_59 ( struct V_23 * V_24 , int V_9 )
{
V_24 -> V_29 = V_110 | V_68 ;
V_24 -> V_30 = 0 ;
V_24 -> V_32 = V_97 | V_96 ;
if ( V_9 & 0x02 ) {
V_24 -> V_29 = 0 ;
V_24 -> V_32 &= ~ V_96 ;
}
if ( V_9 & 0x08 ) {
V_24 -> V_32 |= V_98 | V_111 | V_112 |
V_113 | V_114 | V_115 ;
}
if ( V_9 & 0x10 ) {
V_24 -> V_30 |= V_99 | V_100 ;
}
if ( V_9 & 0x20 ) {
V_24 -> V_29 = 0 ;
V_24 -> V_32 &= ~ ( V_97 | V_96 ) ;
}
if ( ! ( V_24 -> V_32 & V_96 ) ) {
V_24 -> V_35 [ V_116 ] = 1 ;
V_24 -> V_35 [ V_117 ] = 0 ;
}
}
static int F_60 ( struct V_1 * V_2 , struct V_101 T_5 * V_101 )
{
int V_82 ;
struct V_101 V_102 ;
struct V_23 V_24 ;
V_82 = F_42 ( V_2 ) ;
if ( V_82 )
return V_82 ;
if ( F_54 ( & V_102 , V_101 , sizeof( V_102 ) ) )
return - V_85 ;
F_5 ( & V_2 -> V_7 ) ;
V_24 = V_2 -> V_24 ;
V_24 . V_35 [ V_106 ] = V_102 . V_105 ;
V_24 . V_35 [ V_108 ] = V_102 . V_107 ;
F_59 ( & V_24 , V_102 . V_109 ) ;
#ifdef F_25
F_28 ( & V_24 , V_24 . V_43 ,
V_24 . V_38 ) ;
#endif
F_7 ( & V_2 -> V_7 ) ;
F_33 ( V_2 , & V_24 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_118 T_5 * V_118 )
{
struct V_118 V_102 ;
F_43 ( & V_2 -> V_7 ) ;
V_102 . V_119 = V_2 -> V_24 . V_35 [ V_120 ] ;
V_102 . V_121 = V_2 -> V_24 . V_35 [ V_122 ] ;
V_102 . V_123 = V_2 -> V_24 . V_35 [ V_70 ] ;
V_102 . V_124 = V_2 -> V_24 . V_35 [ V_69 ] ;
V_102 . V_125 = V_2 -> V_24 . V_35 [ V_126 ] ;
V_102 . V_127 = V_2 -> V_24 . V_35 [ V_128 ] ;
F_44 ( & V_2 -> V_7 ) ;
return F_58 ( V_118 , & V_102 , sizeof( V_102 ) ) ? - V_85 : 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_118 T_5 * V_118 )
{
struct V_118 V_102 ;
if ( F_54 ( & V_102 , V_118 , sizeof( V_102 ) ) )
return - V_85 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_24 . V_35 [ V_120 ] = V_102 . V_119 ;
V_2 -> V_24 . V_35 [ V_122 ] = V_102 . V_121 ;
V_2 -> V_24 . V_35 [ V_70 ] = V_102 . V_123 ;
V_2 -> V_24 . V_35 [ V_69 ] = V_102 . V_124 ;
V_2 -> V_24 . V_35 [ V_126 ] = V_102 . V_125 ;
V_2 -> V_24 . V_35 [ V_128 ] = V_102 . V_127 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_129 T_5 * V_129 )
{
struct V_129 V_102 ;
F_43 ( & V_2 -> V_7 ) ;
V_102 . V_130 = V_2 -> V_24 . V_35 [ V_131 ] ;
V_102 . V_132 = V_2 -> V_24 . V_35 [ V_131 ] ;
V_102 . V_133 = V_2 -> V_24 . V_35 [ V_134 ] ;
V_102 . V_135 = V_2 -> V_24 . V_35 [ V_128 ] ;
V_102 . V_136 = V_2 -> V_24 . V_35 [ V_137 ] ;
V_102 . V_138 = V_2 -> V_24 . V_35 [ V_139 ] ;
F_44 ( & V_2 -> V_7 ) ;
return F_58 ( V_129 , & V_102 , sizeof( V_102 ) ) ? - V_85 : 0 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_129 T_5 * V_129 )
{
struct V_129 V_102 ;
if ( F_54 ( & V_102 , V_129 , sizeof( V_102 ) ) )
return - V_85 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_24 . V_35 [ V_131 ] = V_102 . V_130 ;
V_2 -> V_24 . V_35 [ V_128 ] = V_102 . V_132 ;
V_2 -> V_24 . V_35 [ V_134 ] = V_102 . V_133 ;
V_2 -> V_24 . V_35 [ V_128 ] = V_102 . V_135 ;
V_2 -> V_24 . V_35 [ V_137 ] = V_102 . V_136 ;
V_2 -> V_24 . V_35 [ V_139 ] = V_102 . V_138 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , int V_79 )
{
int V_13 = 0 ;
int V_140 = V_79 ? V_55 : 0 ;
struct V_23 V_25 ;
F_5 ( & V_2 -> V_7 ) ;
V_25 = V_2 -> V_24 ;
V_2 -> V_24 . V_31 &= ~ V_55 ;
V_2 -> V_24 . V_31 |= V_140 ;
if ( V_2 -> V_3 -> V_78 )
V_2 -> V_3 -> V_78 ( V_2 , & V_25 ) ;
if ( ( V_2 -> V_24 . V_31 & V_55 ) != V_140 )
V_13 = - V_91 ;
F_7 ( & V_2 -> V_7 ) ;
return V_13 ;
}
int F_66 ( struct V_1 * V_2 , struct V_141 * V_141 ,
unsigned int V_142 , unsigned long V_79 )
{
struct V_1 * V_143 ;
void T_5 * V_144 = ( void T_5 * ) V_79 ;
int V_13 = 0 ;
struct V_23 V_88 ;
F_67 ( V_141 == NULL ) ;
if ( V_2 -> V_145 -> type == V_146 &&
V_2 -> V_145 -> V_147 == V_148 )
V_143 = V_2 -> V_63 ;
else
V_143 = V_2 ;
switch ( V_142 ) {
#ifdef F_68
case F_68 :
return F_57 ( V_143 , (struct V_101 T_5 * ) V_79 ) ;
case V_149 :
case V_150 :
return F_60 ( V_143 , (struct V_101 T_5 * ) V_79 ) ;
#endif
#ifdef F_69
case F_69 :
return F_61 ( V_143 , V_144 ) ;
case V_151 :
return F_62 ( V_143 , V_144 ) ;
#endif
#ifdef F_70
case F_70 :
return F_63 ( V_143 , V_144 ) ;
case V_152 :
return F_64 ( V_143 , V_144 ) ;
#endif
case V_153 :
return V_78 ( V_143 , V_144 , V_92 | V_93 | V_86 ) ;
case V_154 :
return V_78 ( V_143 , V_144 , V_93 | V_86 ) ;
case V_155 :
return V_78 ( V_143 , V_144 , V_86 ) ;
#ifndef F_46
case V_156 :
F_49 ( V_143 , & V_88 ) ;
if ( F_71 ( (struct V_24 T_5 * ) V_79 , & V_88 ) )
V_13 = - V_85 ;
return V_13 ;
#else
case V_156 :
F_49 ( V_143 , & V_88 ) ;
if ( F_72 ( (struct V_24 T_5 * ) V_79 , & V_88 ) )
V_13 = - V_85 ;
return V_13 ;
case F_46 :
F_49 ( V_143 , & V_88 ) ;
if ( F_71 ( (struct V_87 T_5 * ) V_79 , & V_88 ) )
V_13 = - V_85 ;
return V_13 ;
case V_157 :
return V_78 ( V_143 , V_144 , V_92 | V_93 ) ;
case V_158 :
return V_78 ( V_143 , V_144 , V_93 ) ;
case V_159 :
return V_78 ( V_143 , V_144 , 0 ) ;
#endif
case V_160 :
return F_51 ( V_143 , V_144 ) ;
case V_161 :
return V_78 ( V_143 , V_144 , V_92 | V_93 | V_83 ) ;
case V_162 :
return V_78 ( V_143 , V_144 , V_93 | V_83 ) ;
case V_163 :
return V_78 ( V_143 , V_144 , V_83 ) ;
#ifndef F_46
case V_164 :
F_50 ( V_143 , & V_88 ) ;
if ( F_71 ( (struct V_24 T_5 * ) V_79 , & V_88 ) )
V_13 = - V_85 ;
return V_13 ;
case V_165 :
if ( ! F_73 ( V_166 ) )
return - V_167 ;
F_50 ( V_143 , & V_88 ) ;
if ( F_48 ( & V_88 ,
(struct V_24 T_5 * ) V_79 ) )
return - V_85 ;
F_5 ( & V_143 -> V_7 ) ;
V_143 -> V_62 = V_88 ;
F_7 ( & V_143 -> V_7 ) ;
return 0 ;
#else
case V_164 :
F_50 ( V_143 , & V_88 ) ;
if ( F_72 ( (struct V_24 T_5 * ) V_79 , & V_88 ) )
V_13 = - V_85 ;
return V_13 ;
case V_165 :
if ( ! F_73 ( V_166 ) )
return - V_167 ;
F_50 ( V_143 , & V_88 ) ;
if ( F_47 ( & V_88 ,
(struct V_24 T_5 * ) V_79 ) )
return - V_85 ;
F_5 ( & V_143 -> V_7 ) ;
V_143 -> V_62 = V_88 ;
F_7 ( & V_143 -> V_7 ) ;
return V_13 ;
#endif
#ifdef F_74
case F_74 : {
struct V_89 V_168 ;
if ( V_143 -> V_89 == NULL )
return - V_91 ;
F_43 ( & V_143 -> V_7 ) ;
memcpy ( & V_168 , V_143 -> V_89 , sizeof( struct V_89 ) ) ;
F_44 ( & V_143 -> V_7 ) ;
if ( F_58 ( V_144 , & V_168 , sizeof( struct V_89 ) ) )
V_13 = - V_85 ;
return V_13 ;
}
case V_169 :
return F_53 ( V_143 , V_144 , 0 ) ;
case V_170 :
return F_53 ( V_143 , V_144 , V_93 ) ;
case V_171 :
return F_53 ( V_143 , V_144 , V_92 ) ;
#endif
case V_172 :
F_49 ( V_143 , & V_88 ) ;
V_13 = F_75 ( ( V_88 . V_31 & V_55 ) ? 1 : 0 ,
( int T_5 * ) V_79 ) ;
return V_13 ;
case V_173 :
if ( F_76 ( V_79 , ( unsigned int T_5 * ) V_79 ) )
return - V_85 ;
return F_65 ( V_143 , V_79 ) ;
default:
return - V_174 ;
}
}
static int F_77 ( struct V_1 * V_2 , unsigned long V_79 )
{
struct V_60 * V_61 = V_2 -> V_175 ;
switch ( V_79 ) {
case V_176 :
if ( V_61 && V_61 -> V_3 -> V_6 ) {
V_61 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
break;
case V_177 :
if ( V_61 && V_61 -> V_3 -> V_6 ) {
V_61 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
case V_178 :
F_3 ( V_2 ) ;
break;
default:
return - V_91 ;
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 , unsigned long V_79 )
{
struct V_60 * V_61 ;
int V_82 = F_42 ( V_2 ) ;
if ( V_82 )
return V_82 ;
V_61 = F_79 ( V_2 ) ;
V_82 = F_77 ( V_2 , V_79 ) ;
if ( V_61 )
F_41 ( V_61 ) ;
return V_82 ;
}
int F_80 ( struct V_1 * V_2 , struct V_141 * V_141 ,
unsigned int V_142 , unsigned long V_79 )
{
int V_82 ;
switch ( V_142 ) {
case V_179 :
V_82 = F_42 ( V_2 ) ;
if ( V_82 )
return V_82 ;
switch ( V_79 ) {
case V_180 :
F_81 ( & V_2 -> V_181 ) ;
if ( ! V_2 -> V_182 ) {
V_2 -> V_182 = 1 ;
F_82 ( V_2 ) ;
}
F_83 ( & V_2 -> V_181 ) ;
break;
case V_183 :
F_81 ( & V_2 -> V_181 ) ;
if ( V_2 -> V_182 ) {
V_2 -> V_182 = 0 ;
F_84 ( V_2 ) ;
}
F_83 ( & V_2 -> V_181 ) ;
break;
case V_184 :
F_43 ( & V_2 -> V_7 ) ;
if ( F_35 ( V_2 ) != V_185 )
V_82 = F_85 ( V_2 , F_35 ( V_2 ) ) ;
F_44 ( & V_2 -> V_7 ) ;
break;
case V_186 :
F_43 ( & V_2 -> V_7 ) ;
if ( F_36 ( V_2 ) != V_185 )
V_82 = F_85 ( V_2 , F_36 ( V_2 ) ) ;
F_44 ( & V_2 -> V_7 ) ;
break;
default:
return - V_91 ;
}
return V_82 ;
case V_187 :
V_82 = F_42 ( V_2 ) ;
if ( V_82 )
return V_82 ;
return F_77 ( V_2 , V_79 ) ;
default:
return F_66 ( V_2 , V_141 , V_142 , V_79 ) ;
}
}
long F_86 ( struct V_1 * V_2 , struct V_141 * V_141 ,
unsigned int V_142 , unsigned long V_79 )
{
switch ( V_142 ) {
case V_164 :
case V_165 :
return F_66 ( V_2 , V_141 , V_142 , ( unsigned long ) F_87 ( V_79 ) ) ;
default:
return - V_174 ;
}
}
