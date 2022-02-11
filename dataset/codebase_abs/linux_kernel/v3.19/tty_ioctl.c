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
F_34 ( V_2 -> V_62 -> type == V_63 &&
V_2 -> V_62 -> V_64 == V_65 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_59 = V_2 -> V_24 ;
V_2 -> V_24 = * V_58 ;
F_22 ( & V_2 -> V_24 , & V_59 , & V_2 -> V_66 ) ;
if ( V_2 -> V_3 -> V_67 )
V_2 -> V_3 -> V_67 ( V_2 , & V_59 ) ;
else
F_31 ( & V_2 -> V_24 , & V_59 ) ;
V_61 = F_35 ( V_2 ) ;
if ( V_61 != NULL ) {
if ( V_61 -> V_3 -> V_67 )
V_61 -> V_3 -> V_67 ( V_2 , & V_59 ) ;
F_36 ( V_61 ) ;
}
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int V_67 ( struct V_1 * V_2 , void T_5 * V_68 , int V_69 )
{
struct V_23 V_70 ;
struct V_60 * V_61 ;
int V_71 = F_37 ( V_2 ) ;
if ( V_71 )
return V_71 ;
F_38 ( & V_2 -> V_7 ) ;
V_70 = V_2 -> V_24 ;
F_39 ( & V_2 -> V_7 ) ;
if ( V_69 & V_72 ) {
if ( F_40 ( & V_70 ,
(struct V_73 T_5 * ) V_68 ) )
return - V_74 ;
#ifdef F_41
} else if ( V_69 & V_75 ) {
if ( F_42 ( & V_70 ,
(struct V_24 T_5 * ) V_68 ) )
return - V_74 ;
} else {
if ( F_43 ( & V_70 ,
(struct V_76 T_5 * ) V_68 ) )
return - V_74 ;
}
#else
}
void F_44 ( struct V_1 * V_2 , struct V_23 * V_77 )
{
F_38 ( & V_2 -> V_7 ) ;
* V_77 = V_2 -> V_24 ;
F_39 ( & V_2 -> V_7 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_23 * V_77 )
{
F_38 ( & V_2 -> V_7 ) ;
* V_77 = V_2 -> V_66 ;
F_39 ( & V_2 -> V_7 ) ;
}
static int F_46 ( struct V_1 * V_2 , struct V_73 T_5 * V_73 )
{
struct V_23 V_77 ;
F_44 ( V_2 , & V_77 ) ;
if ( F_47 ( V_73 , & V_77 ) )
return - V_74 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , void T_5 * V_68 , int V_69 )
{
struct V_78 V_79 ;
struct V_60 * V_61 ;
if ( V_2 -> V_78 == NULL )
return - V_80 ;
if ( F_49 ( & V_79 , V_68 , sizeof( struct V_78 ) ) )
return - V_74 ;
V_61 = F_35 ( V_2 ) ;
if ( V_61 != NULL ) {
if ( ( V_69 & V_81 ) && V_61 -> V_3 -> V_6 )
V_61 -> V_3 -> V_6 ( V_2 ) ;
F_36 ( V_61 ) ;
}
if ( V_69 & V_82 ) {
F_17 ( V_2 , 0 ) ;
if ( F_50 ( V_83 ) )
return - V_84 ;
}
F_5 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_3 -> F_48 )
V_2 -> V_3 -> F_48 ( V_2 , & V_79 ) ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
if ( ! ( V_2 -> V_24 . V_32 & V_85 ) ) {
if ( V_2 -> V_24 . V_32 & V_86 )
V_9 |= 0x02 ;
else
V_9 |= 0x20 ;
}
if ( V_2 -> V_24 . V_32 & V_87 )
V_9 |= 0x08 ;
if ( V_2 -> V_24 . V_30 & V_88 )
if ( V_2 -> V_24 . V_30 & V_89 )
V_9 |= 0x10 ;
return V_9 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_90 T_5 * V_90 )
{
struct V_90 V_91 ;
F_38 ( & V_2 -> V_7 ) ;
V_91 . V_92 = V_2 -> V_24 . V_43 ;
V_91 . V_93 = V_2 -> V_24 . V_38 ;
V_91 . V_94 = V_2 -> V_24 . V_35 [ V_95 ] ;
V_91 . V_96 = V_2 -> V_24 . V_35 [ V_97 ] ;
V_91 . V_98 = F_51 ( V_2 ) ;
F_39 ( & V_2 -> V_7 ) ;
return F_53 ( V_90 , & V_91 , sizeof( V_91 ) ) ? - V_74 : 0 ;
}
static void F_54 ( struct V_23 * V_24 , int V_9 )
{
V_24 -> V_29 = V_99 | V_100 ;
V_24 -> V_30 = 0 ;
V_24 -> V_32 = V_86 | V_85 ;
if ( V_9 & 0x02 ) {
V_24 -> V_29 = 0 ;
V_24 -> V_32 &= ~ V_85 ;
}
if ( V_9 & 0x08 ) {
V_24 -> V_32 |= V_87 | V_101 | V_102 |
V_103 | V_104 | V_105 ;
}
if ( V_9 & 0x10 ) {
V_24 -> V_30 |= V_88 | V_89 ;
}
if ( V_9 & 0x20 ) {
V_24 -> V_29 = 0 ;
V_24 -> V_32 &= ~ ( V_86 | V_85 ) ;
}
if ( ! ( V_24 -> V_32 & V_85 ) ) {
V_24 -> V_35 [ V_106 ] = 1 ;
V_24 -> V_35 [ V_107 ] = 0 ;
}
}
static int F_55 ( struct V_1 * V_2 , struct V_90 T_5 * V_90 )
{
int V_71 ;
struct V_90 V_91 ;
struct V_23 V_24 ;
V_71 = F_37 ( V_2 ) ;
if ( V_71 )
return V_71 ;
if ( F_49 ( & V_91 , V_90 , sizeof( V_91 ) ) )
return - V_74 ;
F_5 ( & V_2 -> V_7 ) ;
V_24 = V_2 -> V_24 ;
V_24 . V_35 [ V_95 ] = V_91 . V_94 ;
V_24 . V_35 [ V_97 ] = V_91 . V_96 ;
F_54 ( & V_24 , V_91 . V_98 ) ;
#ifdef F_25
F_28 ( & V_24 , V_24 . V_43 ,
V_24 . V_38 ) ;
#endif
F_7 ( & V_2 -> V_7 ) ;
F_33 ( V_2 , & V_24 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_108 T_5 * V_108 )
{
struct V_108 V_91 ;
F_38 ( & V_2 -> V_7 ) ;
V_91 . V_109 = V_2 -> V_24 . V_35 [ V_110 ] ;
V_91 . V_111 = V_2 -> V_24 . V_35 [ V_112 ] ;
V_91 . V_113 = V_2 -> V_24 . V_35 [ V_114 ] ;
V_91 . V_115 = V_2 -> V_24 . V_35 [ V_116 ] ;
V_91 . V_117 = V_2 -> V_24 . V_35 [ V_118 ] ;
V_91 . V_119 = V_2 -> V_24 . V_35 [ V_120 ] ;
F_39 ( & V_2 -> V_7 ) ;
return F_53 ( V_108 , & V_91 , sizeof( V_91 ) ) ? - V_74 : 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_108 T_5 * V_108 )
{
struct V_108 V_91 ;
if ( F_49 ( & V_91 , V_108 , sizeof( V_91 ) ) )
return - V_74 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_24 . V_35 [ V_110 ] = V_91 . V_109 ;
V_2 -> V_24 . V_35 [ V_112 ] = V_91 . V_111 ;
V_2 -> V_24 . V_35 [ V_114 ] = V_91 . V_113 ;
V_2 -> V_24 . V_35 [ V_116 ] = V_91 . V_115 ;
V_2 -> V_24 . V_35 [ V_118 ] = V_91 . V_117 ;
V_2 -> V_24 . V_35 [ V_120 ] = V_91 . V_119 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_121 T_5 * V_121 )
{
struct V_121 V_91 ;
F_38 ( & V_2 -> V_7 ) ;
V_91 . V_122 = V_2 -> V_24 . V_35 [ V_123 ] ;
V_91 . V_124 = V_2 -> V_24 . V_35 [ V_123 ] ;
V_91 . V_125 = V_2 -> V_24 . V_35 [ V_126 ] ;
V_91 . V_127 = V_2 -> V_24 . V_35 [ V_120 ] ;
V_91 . V_128 = V_2 -> V_24 . V_35 [ V_129 ] ;
V_91 . V_130 = V_2 -> V_24 . V_35 [ V_131 ] ;
F_39 ( & V_2 -> V_7 ) ;
return F_53 ( V_121 , & V_91 , sizeof( V_91 ) ) ? - V_74 : 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_121 T_5 * V_121 )
{
struct V_121 V_91 ;
if ( F_49 ( & V_91 , V_121 , sizeof( V_91 ) ) )
return - V_74 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_24 . V_35 [ V_123 ] = V_91 . V_122 ;
V_2 -> V_24 . V_35 [ V_120 ] = V_91 . V_124 ;
V_2 -> V_24 . V_35 [ V_126 ] = V_91 . V_125 ;
V_2 -> V_24 . V_35 [ V_120 ] = V_91 . V_127 ;
V_2 -> V_24 . V_35 [ V_129 ] = V_91 . V_128 ;
V_2 -> V_24 . V_35 [ V_131 ] = V_91 . V_130 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_68 )
{
int V_13 = 0 ;
int V_132 = V_68 ? V_55 : 0 ;
struct V_23 V_25 ;
F_5 ( & V_2 -> V_7 ) ;
V_25 = V_2 -> V_24 ;
V_2 -> V_24 . V_31 &= ~ V_55 ;
V_2 -> V_24 . V_31 |= V_132 ;
if ( V_2 -> V_3 -> V_67 )
V_2 -> V_3 -> V_67 ( V_2 , & V_25 ) ;
if ( ( V_2 -> V_24 . V_31 & V_55 ) != V_132 )
V_13 = - V_80 ;
F_7 ( & V_2 -> V_7 ) ;
return V_13 ;
}
int F_61 ( struct V_1 * V_2 , struct V_133 * V_133 ,
unsigned int V_134 , unsigned long V_68 )
{
struct V_1 * V_135 ;
void T_5 * V_136 = ( void T_5 * ) V_68 ;
int V_13 = 0 ;
struct V_23 V_77 ;
F_62 ( V_133 == NULL ) ;
if ( V_2 -> V_62 -> type == V_63 &&
V_2 -> V_62 -> V_64 == V_65 )
V_135 = V_2 -> V_137 ;
else
V_135 = V_2 ;
switch ( V_134 ) {
#ifdef F_63
case F_63 :
return F_52 ( V_135 , (struct V_90 T_5 * ) V_68 ) ;
case V_138 :
case V_139 :
return F_55 ( V_135 , (struct V_90 T_5 * ) V_68 ) ;
#endif
#ifdef F_64
case F_64 :
return F_56 ( V_135 , V_136 ) ;
case V_140 :
return F_57 ( V_135 , V_136 ) ;
#endif
#ifdef F_65
case F_65 :
return F_58 ( V_135 , V_136 ) ;
case V_141 :
return F_59 ( V_135 , V_136 ) ;
#endif
case V_142 :
return V_67 ( V_135 , V_136 , V_81 | V_82 | V_75 ) ;
case V_143 :
return V_67 ( V_135 , V_136 , V_82 | V_75 ) ;
case V_144 :
return V_67 ( V_135 , V_136 , V_75 ) ;
#ifndef F_41
case V_145 :
F_44 ( V_135 , & V_77 ) ;
if ( F_66 ( (struct V_24 T_5 * ) V_68 , & V_77 ) )
V_13 = - V_74 ;
return V_13 ;
#else
case V_145 :
F_44 ( V_135 , & V_77 ) ;
if ( F_67 ( (struct V_24 T_5 * ) V_68 , & V_77 ) )
V_13 = - V_74 ;
return V_13 ;
case F_41 :
F_44 ( V_135 , & V_77 ) ;
if ( F_66 ( (struct V_76 T_5 * ) V_68 , & V_77 ) )
V_13 = - V_74 ;
return V_13 ;
case V_146 :
return V_67 ( V_135 , V_136 , V_81 | V_82 ) ;
case V_147 :
return V_67 ( V_135 , V_136 , V_82 ) ;
case V_148 :
return V_67 ( V_135 , V_136 , 0 ) ;
#endif
case V_149 :
return F_46 ( V_135 , V_136 ) ;
case V_150 :
return V_67 ( V_135 , V_136 , V_81 | V_82 | V_72 ) ;
case V_151 :
return V_67 ( V_135 , V_136 , V_82 | V_72 ) ;
case V_152 :
return V_67 ( V_135 , V_136 , V_72 ) ;
#ifndef F_41
case V_153 :
F_45 ( V_135 , & V_77 ) ;
if ( F_66 ( (struct V_24 T_5 * ) V_68 , & V_77 ) )
V_13 = - V_74 ;
return V_13 ;
case V_154 :
if ( ! F_68 ( V_155 ) )
return - V_156 ;
F_45 ( V_135 , & V_77 ) ;
if ( F_43 ( & V_77 ,
(struct V_24 T_5 * ) V_68 ) )
return - V_74 ;
F_5 ( & V_135 -> V_7 ) ;
V_135 -> V_66 = V_77 ;
F_7 ( & V_135 -> V_7 ) ;
return 0 ;
#else
case V_153 :
F_45 ( V_135 , & V_77 ) ;
if ( F_67 ( (struct V_24 T_5 * ) V_68 , & V_77 ) )
V_13 = - V_74 ;
return V_13 ;
case V_154 :
if ( ! F_68 ( V_155 ) )
return - V_156 ;
F_45 ( V_135 , & V_77 ) ;
if ( F_42 ( & V_77 ,
(struct V_24 T_5 * ) V_68 ) )
return - V_74 ;
F_5 ( & V_135 -> V_7 ) ;
V_135 -> V_66 = V_77 ;
F_7 ( & V_135 -> V_7 ) ;
return V_13 ;
#endif
#ifdef F_69
case F_69 : {
struct V_78 V_157 ;
if ( V_135 -> V_78 == NULL )
return - V_80 ;
F_38 ( & V_135 -> V_7 ) ;
memcpy ( & V_157 , V_135 -> V_78 , sizeof( struct V_78 ) ) ;
F_39 ( & V_135 -> V_7 ) ;
if ( F_53 ( V_136 , & V_157 , sizeof( struct V_78 ) ) )
V_13 = - V_74 ;
return V_13 ;
}
case V_158 :
return F_48 ( V_135 , V_136 , 0 ) ;
case V_159 :
return F_48 ( V_135 , V_136 , V_82 ) ;
case V_160 :
return F_48 ( V_135 , V_136 , V_81 ) ;
#endif
case V_161 :
F_44 ( V_135 , & V_77 ) ;
V_13 = F_70 ( ( V_77 . V_31 & V_55 ) ? 1 : 0 ,
( int T_5 * ) V_68 ) ;
return V_13 ;
case V_162 :
if ( F_71 ( V_68 , ( unsigned int T_5 * ) V_68 ) )
return - V_74 ;
return F_60 ( V_135 , V_68 ) ;
default:
return - V_163 ;
}
}
static int F_72 ( struct V_1 * V_2 , unsigned long V_68 )
{
struct V_60 * V_61 = V_2 -> V_164 ;
switch ( V_68 ) {
case V_165 :
if ( V_61 && V_61 -> V_3 -> V_6 ) {
V_61 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
break;
case V_166 :
if ( V_61 && V_61 -> V_3 -> V_6 ) {
V_61 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
case V_167 :
F_3 ( V_2 ) ;
break;
default:
return - V_80 ;
}
return 0 ;
}
int F_73 ( struct V_1 * V_2 , unsigned long V_68 )
{
struct V_60 * V_61 ;
int V_71 = F_37 ( V_2 ) ;
if ( V_71 )
return V_71 ;
V_61 = F_74 ( V_2 ) ;
V_71 = F_72 ( V_2 , V_68 ) ;
if ( V_61 )
F_36 ( V_61 ) ;
return V_71 ;
}
int F_75 ( struct V_1 * V_2 , struct V_133 * V_133 ,
unsigned int V_134 , unsigned long V_68 )
{
int V_71 ;
switch ( V_134 ) {
case V_168 :
V_71 = F_37 ( V_2 ) ;
if ( V_71 )
return V_71 ;
switch ( V_68 ) {
case V_169 :
F_76 ( & V_2 -> V_170 ) ;
if ( ! V_2 -> V_171 ) {
V_2 -> V_171 = 1 ;
F_77 ( V_2 ) ;
}
F_78 ( & V_2 -> V_170 ) ;
break;
case V_172 :
F_76 ( & V_2 -> V_170 ) ;
if ( V_2 -> V_171 ) {
V_2 -> V_171 = 0 ;
F_79 ( V_2 ) ;
}
F_78 ( & V_2 -> V_170 ) ;
break;
case V_173 :
F_38 ( & V_2 -> V_7 ) ;
if ( F_80 ( V_2 ) != V_174 )
V_71 = F_81 ( V_2 , F_80 ( V_2 ) ) ;
F_39 ( & V_2 -> V_7 ) ;
break;
case V_175 :
F_38 ( & V_2 -> V_7 ) ;
if ( F_82 ( V_2 ) != V_174 )
V_71 = F_81 ( V_2 , F_82 ( V_2 ) ) ;
F_39 ( & V_2 -> V_7 ) ;
break;
default:
return - V_80 ;
}
return V_71 ;
case V_176 :
V_71 = F_37 ( V_2 ) ;
if ( V_71 )
return V_71 ;
return F_72 ( V_2 , V_68 ) ;
default:
return F_61 ( V_2 , V_133 , V_134 , V_68 ) ;
}
}
long F_83 ( struct V_1 * V_2 , struct V_133 * V_133 ,
unsigned int V_134 , unsigned long V_68 )
{
switch ( V_134 ) {
case V_153 :
case V_154 :
return F_61 ( V_2 , V_133 , V_134 , ( unsigned long ) F_84 ( V_68 ) ) ;
default:
return - V_163 ;
}
}
