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
F_5 ( & V_2 -> V_7 ) ;
if ( ! F_11 ( V_8 , & V_2 -> V_9 ) ) {
if ( V_2 -> V_11 != V_14 )
V_13 = 1 ;
else {
F_12 ( V_8 , & V_2 -> V_9 ) ;
if ( V_2 -> V_3 -> V_10 )
V_2 -> V_3 -> V_10 ( V_2 ) ;
}
}
F_7 ( & V_2 -> V_7 ) ;
return V_13 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
F_5 ( & V_2 -> V_7 ) ;
if ( F_11 ( V_8 , & V_2 -> V_9 ) ) {
if ( V_2 -> V_11 != V_15 )
V_13 = 1 ;
else {
F_14 ( V_8 , & V_2 -> V_9 ) ;
if ( V_2 -> V_3 -> V_12 )
V_2 -> V_3 -> V_12 ( V_2 ) ;
}
}
F_7 ( & V_2 -> V_7 ) ;
return V_13 ;
}
void F_15 ( struct V_1 * V_2 , long V_16 )
{
#ifdef F_16
char V_17 [ 64 ] ;
F_17 ( V_18 L_1 , F_18 ( V_2 , V_17 ) ) ;
#endif
if ( ! V_16 )
V_16 = V_19 ;
if ( F_19 ( V_2 -> V_20 ,
! F_1 ( V_2 ) , V_16 ) >= 0 ) {
if ( V_2 -> V_3 -> V_21 )
V_2 -> V_3 -> V_21 ( V_2 , V_16 ) ;
}
}
static void F_20 ( struct V_22 * V_23 ,
struct V_22 * V_24 ,
struct V_22 * V_25 )
{
int V_26 ;
#define F_21 ( T_1 , T_2 , T_3 ) (x = ((x) & ~(z)) | ((y) & (z)))
if ( ! V_25 ) {
F_17 ( V_27 L_2 ) ;
return;
}
F_21 ( V_23 -> V_28 , V_24 -> V_28 , V_25 -> V_28 ) ;
F_21 ( V_23 -> V_29 , V_24 -> V_29 , V_25 -> V_29 ) ;
F_21 ( V_23 -> V_30 , V_24 -> V_30 , V_25 -> V_30 ) ;
F_21 ( V_23 -> V_31 , V_24 -> V_31 , V_25 -> V_31 ) ;
V_23 -> V_32 = V_25 -> V_32 ? V_24 -> V_32 : V_23 -> V_32 ;
for ( V_26 = 0 ; V_26 < V_33 ; V_26 ++ )
V_23 -> V_34 [ V_26 ] = V_25 -> V_34 [ V_26 ] ?
V_24 -> V_34 [ V_26 ] : V_23 -> V_34 [ V_26 ] ;
}
T_4 F_22 ( struct V_22 * V_23 )
{
unsigned int V_35 ;
V_35 = V_23 -> V_30 & V_36 ;
#ifdef F_23
if ( V_35 == F_23 )
return V_23 -> V_37 ;
#endif
if ( V_35 & V_38 ) {
V_35 &= ~ V_38 ;
if ( V_35 < 1 || V_35 + 15 > V_39 )
V_23 -> V_30 &= ~ V_38 ;
else
V_35 += 15 ;
}
return V_40 [ V_35 ] ;
}
T_4 F_24 ( struct V_22 * V_23 )
{
#ifdef F_25
unsigned int V_35 = ( V_23 -> V_30 >> F_25 ) & V_36 ;
if ( V_35 == V_41 )
return F_22 ( V_23 ) ;
if ( V_35 == F_23 )
return V_23 -> V_42 ;
if ( V_35 & V_38 ) {
V_35 &= ~ V_38 ;
if ( V_35 < 1 || V_35 + 15 > V_39 )
V_23 -> V_30 &= ~ ( V_38 << F_25 ) ;
else
V_35 += 15 ;
}
return V_40 [ V_35 ] ;
#else
return F_22 ( V_23 ) ;
#endif
}
void F_26 ( struct V_22 * V_23 ,
T_4 V_43 , T_4 V_44 )
{
int V_26 = 0 ;
int V_45 = - 1 , V_46 = - 1 ;
int V_47 = V_43 / 50 , V_48 = V_44 / 50 ;
int V_49 = 0 ;
if ( V_44 == 0 )
V_43 = 0 ;
V_23 -> V_42 = V_43 ;
V_23 -> V_37 = V_44 ;
#ifdef F_23
if ( ( V_23 -> V_30 & V_36 ) == F_23 )
V_48 = 0 ;
if ( ( ( V_23 -> V_30 >> F_25 ) & V_36 ) == F_23 )
V_47 = 0 ;
if ( ( V_23 -> V_30 >> F_25 ) & V_36 )
V_49 = 1 ;
#endif
V_23 -> V_30 &= ~ V_36 ;
do {
if ( V_44 - V_48 <= V_40 [ V_26 ] &&
V_44 + V_48 >= V_40 [ V_26 ] ) {
V_23 -> V_30 |= V_50 [ V_26 ] ;
V_46 = V_26 ;
}
if ( V_43 - V_47 <= V_40 [ V_26 ] &&
V_43 + V_47 >= V_40 [ V_26 ] ) {
if ( V_46 == V_26 && ! V_49 )
V_45 = V_26 ;
#ifdef F_25
else {
V_45 = V_26 ;
V_23 -> V_30 |= ( V_50 [ V_26 ] << F_25 ) ;
}
#endif
}
} while ( ++ V_26 < V_39 );
#ifdef F_23
if ( V_46 == - 1 )
V_23 -> V_30 |= F_23 ;
if ( V_45 == - 1 && ( V_43 != V_44 || V_49 ) )
V_23 -> V_30 |= ( F_23 << F_25 ) ;
#else
if ( V_45 == - 1 || V_46 == - 1 ) {
F_27 ( V_27 L_3
L_4 ) ;
}
#endif
}
void F_28 ( struct V_1 * V_2 , T_4 V_43 , T_4 V_44 )
{
F_26 ( & V_2 -> V_23 , V_43 , V_44 ) ;
}
void F_29 ( struct V_22 * V_51 , struct V_22 * V_24 )
{
V_51 -> V_30 &= V_52 | V_53 | V_54 ;
V_51 -> V_30 |= V_24 -> V_30 & ~ ( V_52 | V_53 | V_54 ) ;
V_51 -> V_42 = V_24 -> V_42 ;
V_51 -> V_37 = V_24 -> V_37 ;
}
int F_30 ( struct V_22 * V_55 , struct V_22 * V_56 )
{
if ( V_55 -> V_42 != V_56 -> V_42 || V_55 -> V_37 != V_56 -> V_37 )
return 1 ;
if ( ( V_55 -> V_30 ^ V_56 -> V_30 ) & ~ ( V_52 | V_53 | V_54 ) )
return 1 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_22 * V_57 )
{
struct V_22 V_58 ;
struct V_59 * V_60 ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_7 ) ;
V_58 = V_2 -> V_23 ;
V_2 -> V_23 = * V_57 ;
F_20 ( & V_2 -> V_23 , & V_58 , & V_2 -> V_61 ) ;
if ( V_2 -> V_62 && V_2 -> V_62 -> V_63 ) {
int V_64 = ( V_58 . V_31 & V_65 ) |
( V_2 -> V_23 . V_31 & V_65 ) ;
int V_66 = ( ( V_58 . V_28 & V_67 ) &&
( V_58 . V_34 [ V_68 ] == '\023' ) &&
( V_58 . V_34 [ V_69 ] == '\021' ) ) ;
int V_70 = ( F_32 ( V_2 ) &&
F_33 ( V_2 ) == '\023' &&
F_34 ( V_2 ) == '\021' ) ;
if ( ( V_66 != V_70 ) || V_64 ) {
F_35 ( & V_2 -> V_71 , V_9 ) ;
if ( V_66 != V_70 ) {
V_2 -> V_72 &= ~ ( V_73 | V_74 ) ;
if ( V_70 )
V_2 -> V_72 |= V_73 ;
else
V_2 -> V_72 |= V_74 ;
}
if ( V_64 )
V_2 -> V_72 |= V_75 ;
F_36 ( & V_2 -> V_71 , V_9 ) ;
F_37 ( & V_2 -> V_62 -> V_76 ) ;
}
}
if ( V_2 -> V_3 -> V_77 )
(* V_2 -> V_3 -> V_77 )( V_2 , & V_58 ) ;
else
F_29 ( & V_2 -> V_23 , & V_58 ) ;
V_60 = F_38 ( V_2 ) ;
if ( V_60 != NULL ) {
if ( V_60 -> V_3 -> V_77 )
( V_60 -> V_3 -> V_77 ) ( V_2 , & V_58 ) ;
F_39 ( V_60 ) ;
}
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int V_77 ( struct V_1 * V_2 , void T_5 * V_78 , int V_79 )
{
struct V_22 V_80 ;
struct V_59 * V_60 ;
int V_81 = F_40 ( V_2 ) ;
if ( V_81 )
return V_81 ;
F_5 ( & V_2 -> V_7 ) ;
V_80 = V_2 -> V_23 ;
F_7 ( & V_2 -> V_7 ) ;
if ( V_79 & V_82 ) {
if ( F_41 ( & V_80 ,
(struct V_83 T_5 * ) V_78 ) )
return - V_84 ;
#ifdef F_42
} else if ( V_79 & V_85 ) {
if ( F_43 ( & V_80 ,
(struct V_23 T_5 * ) V_78 ) )
return - V_84 ;
} else {
if ( F_44 ( & V_80 ,
(struct V_86 T_5 * ) V_78 ) )
return - V_84 ;
}
#else
}
void F_45 ( struct V_1 * V_2 , struct V_22 * V_87 )
{
F_5 ( & V_2 -> V_7 ) ;
* V_87 = V_2 -> V_23 ;
F_7 ( & V_2 -> V_7 ) ;
}
static void F_46 ( struct V_1 * V_2 , struct V_22 * V_87 )
{
F_5 ( & V_2 -> V_7 ) ;
* V_87 = V_2 -> V_61 ;
F_7 ( & V_2 -> V_7 ) ;
}
static int F_47 ( struct V_1 * V_2 , struct V_83 T_5 * V_83 )
{
struct V_22 V_87 ;
F_45 ( V_2 , & V_87 ) ;
if ( F_48 ( V_83 , & V_87 ) )
return - V_84 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , void T_5 * V_78 , int V_79 )
{
struct V_88 V_89 ;
struct V_59 * V_60 ;
if ( V_2 -> V_88 == NULL )
return - V_90 ;
if ( F_50 ( & V_89 , V_78 , sizeof( struct V_88 ) ) )
return - V_84 ;
V_60 = F_38 ( V_2 ) ;
if ( V_60 != NULL ) {
if ( ( V_79 & V_91 ) && V_60 -> V_3 -> V_6 )
V_60 -> V_3 -> V_6 ( V_2 ) ;
F_39 ( V_60 ) ;
}
if ( V_79 & V_92 ) {
F_15 ( V_2 , 0 ) ;
if ( F_51 ( V_93 ) )
return - V_94 ;
}
F_5 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_3 -> F_49 )
V_2 -> V_3 -> F_49 ( V_2 , & V_89 ) ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
if ( ! ( V_2 -> V_23 . V_31 & V_95 ) ) {
if ( V_2 -> V_23 . V_31 & V_96 )
V_9 |= 0x02 ;
else
V_9 |= 0x20 ;
}
if ( V_2 -> V_23 . V_31 & V_97 )
V_9 |= 0x08 ;
if ( V_2 -> V_23 . V_29 & V_98 )
if ( V_2 -> V_23 . V_29 & V_99 )
V_9 |= 0x10 ;
return V_9 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_100 T_5 * V_100 )
{
struct V_100 V_101 ;
F_5 ( & V_2 -> V_7 ) ;
V_101 . V_102 = V_2 -> V_23 . V_42 ;
V_101 . V_103 = V_2 -> V_23 . V_37 ;
V_101 . V_104 = V_2 -> V_23 . V_34 [ V_105 ] ;
V_101 . V_106 = V_2 -> V_23 . V_34 [ V_107 ] ;
V_101 . V_108 = F_52 ( V_2 ) ;
F_7 ( & V_2 -> V_7 ) ;
return F_54 ( V_100 , & V_101 , sizeof( V_101 ) ) ? - V_84 : 0 ;
}
static void F_55 ( struct V_22 * V_23 , int V_9 )
{
V_23 -> V_28 = V_109 | V_67 ;
V_23 -> V_29 = 0 ;
V_23 -> V_31 = V_96 | V_95 ;
if ( V_9 & 0x02 ) {
V_23 -> V_28 = 0 ;
V_23 -> V_31 &= ~ V_95 ;
}
if ( V_9 & 0x08 ) {
V_23 -> V_31 |= V_97 | V_110 | V_111 |
V_112 | V_113 | V_114 ;
}
if ( V_9 & 0x10 ) {
V_23 -> V_29 |= V_98 | V_99 ;
}
if ( V_9 & 0x20 ) {
V_23 -> V_28 = 0 ;
V_23 -> V_31 &= ~ ( V_96 | V_95 ) ;
}
if ( ! ( V_23 -> V_31 & V_95 ) ) {
V_23 -> V_34 [ V_115 ] = 1 ;
V_23 -> V_34 [ V_116 ] = 0 ;
}
}
static int F_56 ( struct V_1 * V_2 , struct V_100 T_5 * V_100 )
{
int V_81 ;
struct V_100 V_101 ;
struct V_22 V_23 ;
V_81 = F_40 ( V_2 ) ;
if ( V_81 )
return V_81 ;
if ( F_50 ( & V_101 , V_100 , sizeof( V_101 ) ) )
return - V_84 ;
F_5 ( & V_2 -> V_7 ) ;
V_23 = V_2 -> V_23 ;
V_23 . V_34 [ V_105 ] = V_101 . V_104 ;
V_23 . V_34 [ V_107 ] = V_101 . V_106 ;
F_55 ( & V_23 , V_101 . V_108 ) ;
#ifdef F_23
F_26 ( & V_23 , V_23 . V_42 ,
V_23 . V_37 ) ;
#endif
F_7 ( & V_2 -> V_7 ) ;
F_31 ( V_2 , & V_23 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_117 T_5 * V_117 )
{
struct V_117 V_101 ;
F_5 ( & V_2 -> V_7 ) ;
V_101 . V_118 = V_2 -> V_23 . V_34 [ V_119 ] ;
V_101 . V_120 = V_2 -> V_23 . V_34 [ V_121 ] ;
V_101 . V_122 = V_2 -> V_23 . V_34 [ V_69 ] ;
V_101 . V_123 = V_2 -> V_23 . V_34 [ V_68 ] ;
V_101 . V_124 = V_2 -> V_23 . V_34 [ V_125 ] ;
V_101 . V_126 = V_2 -> V_23 . V_34 [ V_127 ] ;
F_7 ( & V_2 -> V_7 ) ;
return F_54 ( V_117 , & V_101 , sizeof( V_101 ) ) ? - V_84 : 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_117 T_5 * V_117 )
{
struct V_117 V_101 ;
if ( F_50 ( & V_101 , V_117 , sizeof( V_101 ) ) )
return - V_84 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_23 . V_34 [ V_119 ] = V_101 . V_118 ;
V_2 -> V_23 . V_34 [ V_121 ] = V_101 . V_120 ;
V_2 -> V_23 . V_34 [ V_69 ] = V_101 . V_122 ;
V_2 -> V_23 . V_34 [ V_68 ] = V_101 . V_123 ;
V_2 -> V_23 . V_34 [ V_125 ] = V_101 . V_124 ;
V_2 -> V_23 . V_34 [ V_127 ] = V_101 . V_126 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_128 T_5 * V_128 )
{
struct V_128 V_101 ;
F_5 ( & V_2 -> V_7 ) ;
V_101 . V_129 = V_2 -> V_23 . V_34 [ V_130 ] ;
V_101 . V_131 = V_2 -> V_23 . V_34 [ V_130 ] ;
V_101 . V_132 = V_2 -> V_23 . V_34 [ V_133 ] ;
V_101 . V_134 = V_2 -> V_23 . V_34 [ V_127 ] ;
V_101 . V_135 = V_2 -> V_23 . V_34 [ V_136 ] ;
V_101 . V_137 = V_2 -> V_23 . V_34 [ V_138 ] ;
F_7 ( & V_2 -> V_7 ) ;
return F_54 ( V_128 , & V_101 , sizeof( V_101 ) ) ? - V_84 : 0 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_128 T_5 * V_128 )
{
struct V_128 V_101 ;
if ( F_50 ( & V_101 , V_128 , sizeof( V_101 ) ) )
return - V_84 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_23 . V_34 [ V_130 ] = V_101 . V_129 ;
V_2 -> V_23 . V_34 [ V_127 ] = V_101 . V_131 ;
V_2 -> V_23 . V_34 [ V_133 ] = V_101 . V_132 ;
V_2 -> V_23 . V_34 [ V_127 ] = V_101 . V_134 ;
V_2 -> V_23 . V_34 [ V_136 ] = V_101 . V_135 ;
V_2 -> V_23 . V_34 [ V_138 ] = V_101 . V_137 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , char V_139 )
{
int V_140 = V_2 -> V_141 ;
if ( V_2 -> V_3 -> V_142 ) {
V_2 -> V_3 -> V_142 ( V_2 , V_139 ) ;
return 0 ;
}
if ( F_62 ( V_2 , 0 ) < 0 )
return - V_94 ;
if ( V_140 )
F_63 ( V_2 ) ;
V_2 -> V_3 -> V_143 ( V_2 , & V_139 , 1 ) ;
if ( V_140 )
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , int V_78 )
{
int V_13 = 0 ;
int V_144 = V_78 ? V_54 : 0 ;
struct V_22 V_24 ;
F_5 ( & V_2 -> V_7 ) ;
V_24 = V_2 -> V_23 ;
V_2 -> V_23 . V_30 &= ~ V_54 ;
V_2 -> V_23 . V_30 |= V_144 ;
if ( V_2 -> V_3 -> V_77 )
V_2 -> V_3 -> V_77 ( V_2 , & V_24 ) ;
if ( ( V_2 -> V_23 . V_30 & V_54 ) != V_144 )
V_13 = - V_90 ;
F_7 ( & V_2 -> V_7 ) ;
return V_13 ;
}
int F_67 ( struct V_1 * V_2 , struct V_145 * V_145 ,
unsigned int V_146 , unsigned long V_78 )
{
struct V_1 * V_147 ;
void T_5 * V_148 = ( void T_5 * ) V_78 ;
int V_13 = 0 ;
struct V_22 V_87 ;
F_68 ( V_145 == NULL ) ;
if ( V_2 -> V_149 -> type == V_150 &&
V_2 -> V_149 -> V_151 == V_152 )
V_147 = V_2 -> V_62 ;
else
V_147 = V_2 ;
switch ( V_146 ) {
#ifdef F_69
case F_69 :
return F_53 ( V_147 , (struct V_100 T_5 * ) V_78 ) ;
case V_153 :
case V_154 :
return F_56 ( V_147 , (struct V_100 T_5 * ) V_78 ) ;
#endif
#ifdef F_70
case F_70 :
return F_57 ( V_147 , V_148 ) ;
case V_155 :
return F_58 ( V_147 , V_148 ) ;
#endif
#ifdef F_71
case F_71 :
return F_59 ( V_147 , V_148 ) ;
case V_156 :
return F_60 ( V_147 , V_148 ) ;
#endif
case V_157 :
return V_77 ( V_147 , V_148 , V_91 | V_92 | V_85 ) ;
case V_158 :
return V_77 ( V_147 , V_148 , V_92 | V_85 ) ;
case V_159 :
return V_77 ( V_147 , V_148 , V_85 ) ;
#ifndef F_42
case V_160 :
F_45 ( V_147 , & V_87 ) ;
if ( F_72 ( (struct V_23 T_5 * ) V_78 , & V_87 ) )
V_13 = - V_84 ;
return V_13 ;
#else
case V_160 :
F_45 ( V_147 , & V_87 ) ;
if ( F_73 ( (struct V_23 T_5 * ) V_78 , & V_87 ) )
V_13 = - V_84 ;
return V_13 ;
case F_42 :
F_45 ( V_147 , & V_87 ) ;
if ( F_72 ( (struct V_86 T_5 * ) V_78 , & V_87 ) )
V_13 = - V_84 ;
return V_13 ;
case V_161 :
return V_77 ( V_147 , V_148 , V_91 | V_92 ) ;
case V_162 :
return V_77 ( V_147 , V_148 , V_92 ) ;
case V_163 :
return V_77 ( V_147 , V_148 , 0 ) ;
#endif
case V_164 :
return F_47 ( V_147 , V_148 ) ;
case V_165 :
return V_77 ( V_147 , V_148 , V_91 | V_92 | V_82 ) ;
case V_166 :
return V_77 ( V_147 , V_148 , V_92 | V_82 ) ;
case V_167 :
return V_77 ( V_147 , V_148 , V_82 ) ;
#ifndef F_42
case V_168 :
F_46 ( V_147 , & V_87 ) ;
if ( F_72 ( (struct V_23 T_5 * ) V_78 , & V_87 ) )
V_13 = - V_84 ;
return V_13 ;
case V_169 :
if ( ! F_74 ( V_170 ) )
return - V_171 ;
F_46 ( V_147 , & V_87 ) ;
if ( F_44 ( & V_87 ,
(struct V_23 T_5 * ) V_78 ) )
return - V_84 ;
F_5 ( & V_147 -> V_7 ) ;
V_147 -> V_61 = V_87 ;
F_7 ( & V_147 -> V_7 ) ;
return 0 ;
#else
case V_168 :
F_46 ( V_147 , & V_87 ) ;
if ( F_73 ( (struct V_23 T_5 * ) V_78 , & V_87 ) )
V_13 = - V_84 ;
return V_13 ;
case V_169 :
if ( ! F_74 ( V_170 ) )
return - V_171 ;
F_46 ( V_147 , & V_87 ) ;
if ( F_43 ( & V_87 ,
(struct V_23 T_5 * ) V_78 ) )
return - V_84 ;
F_5 ( & V_147 -> V_7 ) ;
V_147 -> V_61 = V_87 ;
F_7 ( & V_147 -> V_7 ) ;
return V_13 ;
#endif
#ifdef F_75
case F_75 : {
struct V_88 V_172 ;
if ( V_147 -> V_88 == NULL )
return - V_90 ;
F_5 ( & V_147 -> V_7 ) ;
memcpy ( & V_172 , V_147 -> V_88 , sizeof( struct V_88 ) ) ;
F_7 ( & V_147 -> V_7 ) ;
if ( F_54 ( V_148 , & V_172 , sizeof( struct V_88 ) ) )
V_13 = - V_84 ;
return V_13 ;
}
case V_173 :
return F_49 ( V_147 , V_148 , 0 ) ;
case V_174 :
return F_49 ( V_147 , V_148 , V_92 ) ;
case V_175 :
return F_49 ( V_147 , V_148 , V_91 ) ;
#endif
case V_176 :
F_45 ( V_147 , & V_87 ) ;
V_13 = F_76 ( ( V_87 . V_30 & V_54 ) ? 1 : 0 ,
( int T_5 * ) V_78 ) ;
return V_13 ;
case V_177 :
if ( F_77 ( V_78 , ( unsigned int T_5 * ) V_78 ) )
return - V_84 ;
return F_66 ( V_147 , V_78 ) ;
default:
return - V_178 ;
}
}
static int F_78 ( struct V_1 * V_2 , unsigned long V_78 )
{
struct V_59 * V_60 = V_2 -> V_179 ;
switch ( V_78 ) {
case V_180 :
if ( V_60 && V_60 -> V_3 -> V_6 ) {
V_60 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
break;
case V_181 :
if ( V_60 && V_60 -> V_3 -> V_6 ) {
V_60 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
case V_182 :
F_3 ( V_2 ) ;
break;
default:
return - V_90 ;
}
return 0 ;
}
int F_79 ( struct V_1 * V_2 , unsigned long V_78 )
{
struct V_59 * V_60 ;
int V_81 = F_40 ( V_2 ) ;
if ( V_81 )
return V_81 ;
V_60 = F_80 ( V_2 ) ;
V_81 = F_78 ( V_2 , V_78 ) ;
if ( V_60 )
F_39 ( V_60 ) ;
return V_81 ;
}
int F_81 ( struct V_1 * V_2 , struct V_145 * V_145 ,
unsigned int V_146 , unsigned long V_78 )
{
int V_81 ;
switch ( V_146 ) {
case V_183 :
V_81 = F_40 ( V_2 ) ;
if ( V_81 )
return V_81 ;
switch ( V_78 ) {
case V_184 :
if ( ! V_2 -> V_185 ) {
V_2 -> V_185 = 1 ;
F_64 ( V_2 ) ;
}
break;
case V_186 :
if ( V_2 -> V_185 ) {
V_2 -> V_185 = 0 ;
F_63 ( V_2 ) ;
}
break;
case V_187 :
if ( F_33 ( V_2 ) != V_188 )
return F_61 ( V_2 , F_33 ( V_2 ) ) ;
break;
case V_189 :
if ( F_34 ( V_2 ) != V_188 )
return F_61 ( V_2 , F_34 ( V_2 ) ) ;
break;
default:
return - V_90 ;
}
return 0 ;
case V_190 :
return F_78 ( V_2 , V_78 ) ;
default:
return F_67 ( V_2 , V_145 , V_146 , V_78 ) ;
}
}
long F_82 ( struct V_1 * V_2 , struct V_145 * V_145 ,
unsigned int V_146 , unsigned long V_78 )
{
switch ( V_146 ) {
case V_168 :
case V_169 :
return F_67 ( V_2 , V_145 , V_146 , ( unsigned long ) F_83 ( V_78 ) ) ;
default:
return - V_178 ;
}
}
