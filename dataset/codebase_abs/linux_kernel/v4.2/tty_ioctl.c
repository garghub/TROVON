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
F_19 ( V_18 L_1 , F_20 ( V_2 ) ) ;
#endif
if ( ! V_17 )
V_17 = V_19 ;
V_17 = F_21 ( V_2 -> V_20 ,
! F_1 ( V_2 ) , V_17 ) ;
if ( V_17 <= 0 )
return;
if ( V_17 == V_19 )
V_17 = 0 ;
if ( V_2 -> V_3 -> V_21 )
V_2 -> V_3 -> V_21 ( V_2 , V_17 ) ;
}
static void F_22 ( struct V_22 * V_23 ,
struct V_22 * V_24 ,
struct V_22 * V_25 )
{
int V_26 ;
#define F_23 ( T_1 , T_2 , T_3 ) (x = ((x) & ~(z)) | ((y) & (z)))
if ( ! V_25 ) {
F_19 ( V_27 L_2 ) ;
return;
}
F_23 ( V_23 -> V_28 , V_24 -> V_28 , V_25 -> V_28 ) ;
F_23 ( V_23 -> V_29 , V_24 -> V_29 , V_25 -> V_29 ) ;
F_23 ( V_23 -> V_30 , V_24 -> V_30 , V_25 -> V_30 ) ;
F_23 ( V_23 -> V_31 , V_24 -> V_31 , V_25 -> V_31 ) ;
V_23 -> V_32 = V_25 -> V_32 ? V_24 -> V_32 : V_23 -> V_32 ;
for ( V_26 = 0 ; V_26 < V_33 ; V_26 ++ )
V_23 -> V_34 [ V_26 ] = V_25 -> V_34 [ V_26 ] ?
V_24 -> V_34 [ V_26 ] : V_23 -> V_34 [ V_26 ] ;
}
T_4 F_24 ( struct V_22 * V_23 )
{
unsigned int V_35 ;
V_35 = V_23 -> V_30 & V_36 ;
#ifdef F_25
if ( V_35 == F_25 )
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
T_4 F_26 ( struct V_22 * V_23 )
{
#ifdef F_27
unsigned int V_35 = ( V_23 -> V_30 >> F_27 ) & V_36 ;
if ( V_35 == V_41 )
return F_24 ( V_23 ) ;
if ( V_35 == F_25 )
return V_23 -> V_42 ;
if ( V_35 & V_38 ) {
V_35 &= ~ V_38 ;
if ( V_35 < 1 || V_35 + 15 > V_39 )
V_23 -> V_30 &= ~ ( V_38 << F_27 ) ;
else
V_35 += 15 ;
}
return V_40 [ V_35 ] ;
#else
return F_24 ( V_23 ) ;
#endif
}
void F_28 ( struct V_22 * V_23 ,
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
#ifdef F_25
if ( ( V_23 -> V_30 & V_36 ) == F_25 )
V_48 = 0 ;
if ( ( ( V_23 -> V_30 >> F_27 ) & V_36 ) == F_25 )
V_47 = 0 ;
if ( ( V_23 -> V_30 >> F_27 ) & V_36 )
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
#ifdef F_27
else {
V_45 = V_26 ;
V_23 -> V_30 |= ( V_50 [ V_26 ] << F_27 ) ;
}
#endif
}
} while ( ++ V_26 < V_39 );
#ifdef F_25
if ( V_46 == - 1 )
V_23 -> V_30 |= F_25 ;
if ( V_45 == - 1 && ( V_43 != V_44 || V_49 ) )
V_23 -> V_30 |= ( F_25 << F_27 ) ;
#else
if ( V_45 == - 1 || V_46 == - 1 ) {
F_29 ( V_27 L_3
L_4 ) ;
}
#endif
}
void F_30 ( struct V_1 * V_2 , T_4 V_43 , T_4 V_44 )
{
F_28 ( & V_2 -> V_23 , V_43 , V_44 ) ;
}
void F_31 ( struct V_22 * V_51 , struct V_22 * V_24 )
{
V_51 -> V_30 &= V_52 | V_53 | V_54 ;
V_51 -> V_30 |= V_24 -> V_30 & ~ ( V_52 | V_53 | V_54 ) ;
V_51 -> V_42 = V_24 -> V_42 ;
V_51 -> V_37 = V_24 -> V_37 ;
}
int F_32 ( struct V_22 * V_55 , struct V_22 * V_56 )
{
if ( V_55 -> V_42 != V_56 -> V_42 || V_55 -> V_37 != V_56 -> V_37 )
return 1 ;
if ( ( V_55 -> V_30 ^ V_56 -> V_30 ) & ~ ( V_52 | V_53 | V_54 ) )
return 1 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_22 * V_57 )
{
struct V_22 V_58 ;
struct V_59 * V_60 ;
F_34 ( V_2 -> V_61 -> type == V_62 &&
V_2 -> V_61 -> V_63 == V_64 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_58 = V_2 -> V_23 ;
V_2 -> V_23 = * V_57 ;
F_22 ( & V_2 -> V_23 , & V_58 , & V_2 -> V_65 ) ;
if ( V_2 -> V_3 -> V_66 )
V_2 -> V_3 -> V_66 ( V_2 , & V_58 ) ;
else
F_31 ( & V_2 -> V_23 , & V_58 ) ;
V_60 = F_35 ( V_2 ) ;
if ( V_60 != NULL ) {
if ( V_60 -> V_3 -> V_66 )
V_60 -> V_3 -> V_66 ( V_2 , & V_58 ) ;
F_36 ( V_60 ) ;
}
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int V_66 ( struct V_1 * V_2 , void T_5 * V_67 , int V_68 )
{
struct V_22 V_69 ;
struct V_59 * V_60 ;
int V_70 = F_37 ( V_2 ) ;
if ( V_70 )
return V_70 ;
F_38 ( & V_2 -> V_7 ) ;
V_69 = V_2 -> V_23 ;
F_39 ( & V_2 -> V_7 ) ;
if ( V_68 & V_71 ) {
if ( F_40 ( & V_69 ,
(struct V_72 T_5 * ) V_67 ) )
return - V_73 ;
#ifdef F_41
} else if ( V_68 & V_74 ) {
if ( F_42 ( & V_69 ,
(struct V_23 T_5 * ) V_67 ) )
return - V_73 ;
} else {
if ( F_43 ( & V_69 ,
(struct V_75 T_5 * ) V_67 ) )
return - V_73 ;
}
#else
}
void F_44 ( struct V_1 * V_2 , struct V_22 * V_76 )
{
F_38 ( & V_2 -> V_7 ) ;
* V_76 = V_2 -> V_23 ;
F_39 ( & V_2 -> V_7 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_22 * V_76 )
{
F_38 ( & V_2 -> V_7 ) ;
* V_76 = V_2 -> V_65 ;
F_39 ( & V_2 -> V_7 ) ;
}
static int F_46 ( struct V_1 * V_2 , struct V_72 T_5 * V_72 )
{
struct V_22 V_76 ;
F_44 ( V_2 , & V_76 ) ;
if ( F_47 ( V_72 , & V_76 ) )
return - V_73 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , void T_5 * V_67 , int V_68 )
{
struct V_77 V_78 ;
struct V_59 * V_60 ;
if ( V_2 -> V_77 == NULL )
return - V_79 ;
if ( F_49 ( & V_78 , V_67 , sizeof( struct V_77 ) ) )
return - V_73 ;
V_60 = F_35 ( V_2 ) ;
if ( V_60 != NULL ) {
if ( ( V_68 & V_80 ) && V_60 -> V_3 -> V_6 )
V_60 -> V_3 -> V_6 ( V_2 ) ;
F_36 ( V_60 ) ;
}
if ( V_68 & V_81 ) {
F_17 ( V_2 , 0 ) ;
if ( F_50 ( V_82 ) )
return - V_83 ;
}
F_5 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_3 -> F_48 )
V_2 -> V_3 -> F_48 ( V_2 , & V_78 ) ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
if ( ! ( V_2 -> V_23 . V_31 & V_84 ) ) {
if ( V_2 -> V_23 . V_31 & V_85 )
V_9 |= 0x02 ;
else
V_9 |= 0x20 ;
}
if ( V_2 -> V_23 . V_31 & V_86 )
V_9 |= 0x08 ;
if ( V_2 -> V_23 . V_29 & V_87 )
if ( V_2 -> V_23 . V_29 & V_88 )
V_9 |= 0x10 ;
return V_9 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_89 T_5 * V_89 )
{
struct V_89 V_90 ;
F_38 ( & V_2 -> V_7 ) ;
V_90 . V_91 = V_2 -> V_23 . V_42 ;
V_90 . V_92 = V_2 -> V_23 . V_37 ;
V_90 . V_93 = V_2 -> V_23 . V_34 [ V_94 ] ;
V_90 . V_95 = V_2 -> V_23 . V_34 [ V_96 ] ;
V_90 . V_97 = F_51 ( V_2 ) ;
F_39 ( & V_2 -> V_7 ) ;
return F_53 ( V_89 , & V_90 , sizeof( V_90 ) ) ? - V_73 : 0 ;
}
static void F_54 ( struct V_22 * V_23 , int V_9 )
{
V_23 -> V_28 = V_98 | V_99 ;
V_23 -> V_29 = 0 ;
V_23 -> V_31 = V_85 | V_84 ;
if ( V_9 & 0x02 ) {
V_23 -> V_28 = 0 ;
V_23 -> V_31 &= ~ V_84 ;
}
if ( V_9 & 0x08 ) {
V_23 -> V_31 |= V_86 | V_100 | V_101 |
V_102 | V_103 | V_104 ;
}
if ( V_9 & 0x10 ) {
V_23 -> V_29 |= V_87 | V_88 ;
}
if ( V_9 & 0x20 ) {
V_23 -> V_28 = 0 ;
V_23 -> V_31 &= ~ ( V_85 | V_84 ) ;
}
if ( ! ( V_23 -> V_31 & V_84 ) ) {
V_23 -> V_34 [ V_105 ] = 1 ;
V_23 -> V_34 [ V_106 ] = 0 ;
}
}
static int F_55 ( struct V_1 * V_2 , struct V_89 T_5 * V_89 )
{
int V_70 ;
struct V_89 V_90 ;
struct V_22 V_23 ;
V_70 = F_37 ( V_2 ) ;
if ( V_70 )
return V_70 ;
if ( F_49 ( & V_90 , V_89 , sizeof( V_90 ) ) )
return - V_73 ;
F_5 ( & V_2 -> V_7 ) ;
V_23 = V_2 -> V_23 ;
V_23 . V_34 [ V_94 ] = V_90 . V_93 ;
V_23 . V_34 [ V_96 ] = V_90 . V_95 ;
F_54 ( & V_23 , V_90 . V_97 ) ;
#ifdef F_25
F_28 ( & V_23 , V_23 . V_42 ,
V_23 . V_37 ) ;
#endif
F_7 ( & V_2 -> V_7 ) ;
F_33 ( V_2 , & V_23 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_107 T_5 * V_107 )
{
struct V_107 V_90 ;
F_38 ( & V_2 -> V_7 ) ;
V_90 . V_108 = V_2 -> V_23 . V_34 [ V_109 ] ;
V_90 . V_110 = V_2 -> V_23 . V_34 [ V_111 ] ;
V_90 . V_112 = V_2 -> V_23 . V_34 [ V_113 ] ;
V_90 . V_114 = V_2 -> V_23 . V_34 [ V_115 ] ;
V_90 . V_116 = V_2 -> V_23 . V_34 [ V_117 ] ;
V_90 . V_118 = V_2 -> V_23 . V_34 [ V_119 ] ;
F_39 ( & V_2 -> V_7 ) ;
return F_53 ( V_107 , & V_90 , sizeof( V_90 ) ) ? - V_73 : 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_107 T_5 * V_107 )
{
struct V_107 V_90 ;
if ( F_49 ( & V_90 , V_107 , sizeof( V_90 ) ) )
return - V_73 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_23 . V_34 [ V_109 ] = V_90 . V_108 ;
V_2 -> V_23 . V_34 [ V_111 ] = V_90 . V_110 ;
V_2 -> V_23 . V_34 [ V_113 ] = V_90 . V_112 ;
V_2 -> V_23 . V_34 [ V_115 ] = V_90 . V_114 ;
V_2 -> V_23 . V_34 [ V_117 ] = V_90 . V_116 ;
V_2 -> V_23 . V_34 [ V_119 ] = V_90 . V_118 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_120 T_5 * V_120 )
{
struct V_120 V_90 ;
F_38 ( & V_2 -> V_7 ) ;
V_90 . V_121 = V_2 -> V_23 . V_34 [ V_122 ] ;
V_90 . V_123 = V_2 -> V_23 . V_34 [ V_122 ] ;
V_90 . V_124 = V_2 -> V_23 . V_34 [ V_125 ] ;
V_90 . V_126 = V_2 -> V_23 . V_34 [ V_119 ] ;
V_90 . V_127 = V_2 -> V_23 . V_34 [ V_128 ] ;
V_90 . V_129 = V_2 -> V_23 . V_34 [ V_130 ] ;
F_39 ( & V_2 -> V_7 ) ;
return F_53 ( V_120 , & V_90 , sizeof( V_90 ) ) ? - V_73 : 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_120 T_5 * V_120 )
{
struct V_120 V_90 ;
if ( F_49 ( & V_90 , V_120 , sizeof( V_90 ) ) )
return - V_73 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_23 . V_34 [ V_122 ] = V_90 . V_121 ;
V_2 -> V_23 . V_34 [ V_119 ] = V_90 . V_123 ;
V_2 -> V_23 . V_34 [ V_125 ] = V_90 . V_124 ;
V_2 -> V_23 . V_34 [ V_119 ] = V_90 . V_126 ;
V_2 -> V_23 . V_34 [ V_128 ] = V_90 . V_127 ;
V_2 -> V_23 . V_34 [ V_130 ] = V_90 . V_129 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_67 )
{
int V_13 = 0 ;
int V_131 = V_67 ? V_54 : 0 ;
struct V_22 V_24 ;
F_5 ( & V_2 -> V_7 ) ;
V_24 = V_2 -> V_23 ;
V_2 -> V_23 . V_30 &= ~ V_54 ;
V_2 -> V_23 . V_30 |= V_131 ;
if ( V_2 -> V_3 -> V_66 )
V_2 -> V_3 -> V_66 ( V_2 , & V_24 ) ;
if ( ( V_2 -> V_23 . V_30 & V_54 ) != V_131 )
V_13 = - V_79 ;
F_7 ( & V_2 -> V_7 ) ;
return V_13 ;
}
int F_61 ( struct V_1 * V_2 , struct V_132 * V_132 ,
unsigned int V_133 , unsigned long V_67 )
{
struct V_1 * V_134 ;
void T_5 * V_135 = ( void T_5 * ) V_67 ;
int V_13 = 0 ;
struct V_22 V_76 ;
F_62 ( V_132 == NULL ) ;
if ( V_2 -> V_61 -> type == V_62 &&
V_2 -> V_61 -> V_63 == V_64 )
V_134 = V_2 -> V_136 ;
else
V_134 = V_2 ;
switch ( V_133 ) {
#ifdef F_63
case F_63 :
return F_52 ( V_134 , (struct V_89 T_5 * ) V_67 ) ;
case V_137 :
case V_138 :
return F_55 ( V_134 , (struct V_89 T_5 * ) V_67 ) ;
#endif
#ifdef F_64
case F_64 :
return F_56 ( V_134 , V_135 ) ;
case V_139 :
return F_57 ( V_134 , V_135 ) ;
#endif
#ifdef F_65
case F_65 :
return F_58 ( V_134 , V_135 ) ;
case V_140 :
return F_59 ( V_134 , V_135 ) ;
#endif
case V_141 :
return V_66 ( V_134 , V_135 , V_80 | V_81 | V_74 ) ;
case V_142 :
return V_66 ( V_134 , V_135 , V_81 | V_74 ) ;
case V_143 :
return V_66 ( V_134 , V_135 , V_74 ) ;
#ifndef F_41
case V_144 :
F_44 ( V_134 , & V_76 ) ;
if ( F_66 ( (struct V_23 T_5 * ) V_67 , & V_76 ) )
V_13 = - V_73 ;
return V_13 ;
#else
case V_144 :
F_44 ( V_134 , & V_76 ) ;
if ( F_67 ( (struct V_23 T_5 * ) V_67 , & V_76 ) )
V_13 = - V_73 ;
return V_13 ;
case F_41 :
F_44 ( V_134 , & V_76 ) ;
if ( F_66 ( (struct V_75 T_5 * ) V_67 , & V_76 ) )
V_13 = - V_73 ;
return V_13 ;
case V_145 :
return V_66 ( V_134 , V_135 , V_80 | V_81 ) ;
case V_146 :
return V_66 ( V_134 , V_135 , V_81 ) ;
case V_147 :
return V_66 ( V_134 , V_135 , 0 ) ;
#endif
case V_148 :
return F_46 ( V_134 , V_135 ) ;
case V_149 :
return V_66 ( V_134 , V_135 , V_80 | V_81 | V_71 ) ;
case V_150 :
return V_66 ( V_134 , V_135 , V_81 | V_71 ) ;
case V_151 :
return V_66 ( V_134 , V_135 , V_71 ) ;
#ifndef F_41
case V_152 :
F_45 ( V_134 , & V_76 ) ;
if ( F_66 ( (struct V_23 T_5 * ) V_67 , & V_76 ) )
V_13 = - V_73 ;
return V_13 ;
case V_153 :
if ( ! F_68 ( V_154 ) )
return - V_155 ;
F_45 ( V_134 , & V_76 ) ;
if ( F_43 ( & V_76 ,
(struct V_23 T_5 * ) V_67 ) )
return - V_73 ;
F_5 ( & V_134 -> V_7 ) ;
V_134 -> V_65 = V_76 ;
F_7 ( & V_134 -> V_7 ) ;
return 0 ;
#else
case V_152 :
F_45 ( V_134 , & V_76 ) ;
if ( F_67 ( (struct V_23 T_5 * ) V_67 , & V_76 ) )
V_13 = - V_73 ;
return V_13 ;
case V_153 :
if ( ! F_68 ( V_154 ) )
return - V_155 ;
F_45 ( V_134 , & V_76 ) ;
if ( F_42 ( & V_76 ,
(struct V_23 T_5 * ) V_67 ) )
return - V_73 ;
F_5 ( & V_134 -> V_7 ) ;
V_134 -> V_65 = V_76 ;
F_7 ( & V_134 -> V_7 ) ;
return V_13 ;
#endif
#ifdef F_69
case F_69 : {
struct V_77 V_156 ;
if ( V_134 -> V_77 == NULL )
return - V_79 ;
F_38 ( & V_134 -> V_7 ) ;
memcpy ( & V_156 , V_134 -> V_77 , sizeof( struct V_77 ) ) ;
F_39 ( & V_134 -> V_7 ) ;
if ( F_53 ( V_135 , & V_156 , sizeof( struct V_77 ) ) )
V_13 = - V_73 ;
return V_13 ;
}
case V_157 :
return F_48 ( V_134 , V_135 , 0 ) ;
case V_158 :
return F_48 ( V_134 , V_135 , V_81 ) ;
case V_159 :
return F_48 ( V_134 , V_135 , V_80 ) ;
#endif
case V_160 :
F_44 ( V_134 , & V_76 ) ;
V_13 = F_70 ( ( V_76 . V_30 & V_54 ) ? 1 : 0 ,
( int T_5 * ) V_67 ) ;
return V_13 ;
case V_161 :
if ( F_71 ( V_67 , ( unsigned int T_5 * ) V_67 ) )
return - V_73 ;
return F_60 ( V_134 , V_67 ) ;
default:
return - V_162 ;
}
}
static int F_72 ( struct V_1 * V_2 , unsigned long V_67 )
{
struct V_59 * V_60 = V_2 -> V_163 ;
switch ( V_67 ) {
case V_164 :
if ( V_60 && V_60 -> V_3 -> V_6 ) {
V_60 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
break;
case V_165 :
if ( V_60 && V_60 -> V_3 -> V_6 ) {
V_60 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
case V_166 :
F_3 ( V_2 ) ;
break;
default:
return - V_79 ;
}
return 0 ;
}
int F_73 ( struct V_1 * V_2 , unsigned long V_67 )
{
struct V_59 * V_60 ;
int V_70 = F_37 ( V_2 ) ;
if ( V_70 )
return V_70 ;
V_60 = F_74 ( V_2 ) ;
V_70 = F_72 ( V_2 , V_67 ) ;
if ( V_60 )
F_36 ( V_60 ) ;
return V_70 ;
}
int F_75 ( struct V_1 * V_2 , struct V_132 * V_132 ,
unsigned int V_133 , unsigned long V_67 )
{
int V_70 ;
switch ( V_133 ) {
case V_167 :
V_70 = F_37 ( V_2 ) ;
if ( V_70 )
return V_70 ;
switch ( V_67 ) {
case V_168 :
F_76 ( & V_2 -> V_169 ) ;
if ( ! V_2 -> V_170 ) {
V_2 -> V_170 = 1 ;
F_77 ( V_2 ) ;
}
F_78 ( & V_2 -> V_169 ) ;
break;
case V_171 :
F_76 ( & V_2 -> V_169 ) ;
if ( V_2 -> V_170 ) {
V_2 -> V_170 = 0 ;
F_79 ( V_2 ) ;
}
F_78 ( & V_2 -> V_169 ) ;
break;
case V_172 :
F_38 ( & V_2 -> V_7 ) ;
if ( F_80 ( V_2 ) != V_173 )
V_70 = F_81 ( V_2 , F_80 ( V_2 ) ) ;
F_39 ( & V_2 -> V_7 ) ;
break;
case V_174 :
F_38 ( & V_2 -> V_7 ) ;
if ( F_82 ( V_2 ) != V_173 )
V_70 = F_81 ( V_2 , F_82 ( V_2 ) ) ;
F_39 ( & V_2 -> V_7 ) ;
break;
default:
return - V_79 ;
}
return V_70 ;
case V_175 :
V_70 = F_37 ( V_2 ) ;
if ( V_70 )
return V_70 ;
return F_72 ( V_2 , V_67 ) ;
default:
return F_61 ( V_2 , V_132 , V_133 , V_67 ) ;
}
}
long F_83 ( struct V_1 * V_2 , struct V_132 * V_132 ,
unsigned int V_133 , unsigned long V_67 )
{
switch ( V_133 ) {
case V_152 :
case V_153 :
return F_61 ( V_2 , V_132 , V_133 , ( unsigned long ) F_84 ( V_67 ) ) ;
default:
return - V_162 ;
}
}
