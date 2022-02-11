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
F_18 ( V_2 , L_1 ) ;
if ( ! V_17 )
V_17 = V_18 ;
V_17 = F_19 ( V_2 -> V_19 ,
! F_1 ( V_2 ) , V_17 ) ;
if ( V_17 <= 0 )
return;
if ( V_17 == V_18 )
V_17 = 0 ;
if ( V_2 -> V_3 -> V_20 )
V_2 -> V_3 -> V_20 ( V_2 , V_17 ) ;
}
static void F_20 ( struct V_21 * V_22 ,
struct V_21 * V_23 ,
struct V_21 * V_24 )
{
int V_25 ;
#define F_21 ( T_1 , T_2 , T_3 ) (x = ((x) & ~(z)) | ((y) & (z)))
if ( ! V_24 ) {
F_22 ( V_26 L_2 ) ;
return;
}
F_21 ( V_22 -> V_27 , V_23 -> V_27 , V_24 -> V_27 ) ;
F_21 ( V_22 -> V_28 , V_23 -> V_28 , V_24 -> V_28 ) ;
F_21 ( V_22 -> V_29 , V_23 -> V_29 , V_24 -> V_29 ) ;
F_21 ( V_22 -> V_30 , V_23 -> V_30 , V_24 -> V_30 ) ;
V_22 -> V_31 = V_24 -> V_31 ? V_23 -> V_31 : V_22 -> V_31 ;
for ( V_25 = 0 ; V_25 < V_32 ; V_25 ++ )
V_22 -> V_33 [ V_25 ] = V_24 -> V_33 [ V_25 ] ?
V_23 -> V_33 [ V_25 ] : V_22 -> V_33 [ V_25 ] ;
}
T_4 F_23 ( struct V_21 * V_22 )
{
unsigned int V_34 ;
V_34 = V_22 -> V_29 & V_35 ;
#ifdef F_24
if ( V_34 == F_24 )
return V_22 -> V_36 ;
#endif
if ( V_34 & V_37 ) {
V_34 &= ~ V_37 ;
if ( V_34 < 1 || V_34 + 15 > V_38 )
V_22 -> V_29 &= ~ V_37 ;
else
V_34 += 15 ;
}
return V_39 [ V_34 ] ;
}
T_4 F_25 ( struct V_21 * V_22 )
{
#ifdef F_26
unsigned int V_34 = ( V_22 -> V_29 >> F_26 ) & V_35 ;
if ( V_34 == V_40 )
return F_23 ( V_22 ) ;
if ( V_34 == F_24 )
return V_22 -> V_41 ;
if ( V_34 & V_37 ) {
V_34 &= ~ V_37 ;
if ( V_34 < 1 || V_34 + 15 > V_38 )
V_22 -> V_29 &= ~ ( V_37 << F_26 ) ;
else
V_34 += 15 ;
}
return V_39 [ V_34 ] ;
#else
return F_23 ( V_22 ) ;
#endif
}
void F_27 ( struct V_21 * V_22 ,
T_4 V_42 , T_4 V_43 )
{
int V_25 = 0 ;
int V_44 = - 1 , V_45 = - 1 ;
int V_46 = V_42 / 50 , V_47 = V_43 / 50 ;
int V_48 = 0 ;
if ( V_43 == 0 )
V_42 = 0 ;
V_22 -> V_41 = V_42 ;
V_22 -> V_36 = V_43 ;
#ifdef F_24
if ( ( V_22 -> V_29 & V_35 ) == F_24 )
V_47 = 0 ;
if ( ( ( V_22 -> V_29 >> F_26 ) & V_35 ) == F_24 )
V_46 = 0 ;
if ( ( V_22 -> V_29 >> F_26 ) & V_35 )
V_48 = 1 ;
#endif
V_22 -> V_29 &= ~ V_35 ;
do {
if ( V_43 - V_47 <= V_39 [ V_25 ] &&
V_43 + V_47 >= V_39 [ V_25 ] ) {
V_22 -> V_29 |= V_49 [ V_25 ] ;
V_45 = V_25 ;
}
if ( V_42 - V_46 <= V_39 [ V_25 ] &&
V_42 + V_46 >= V_39 [ V_25 ] ) {
if ( V_45 == V_25 && ! V_48 )
V_44 = V_25 ;
#ifdef F_26
else {
V_44 = V_25 ;
V_22 -> V_29 |= ( V_49 [ V_25 ] << F_26 ) ;
}
#endif
}
} while ( ++ V_25 < V_38 );
#ifdef F_24
if ( V_45 == - 1 )
V_22 -> V_29 |= F_24 ;
if ( V_44 == - 1 && ( V_42 != V_43 || V_48 ) )
V_22 -> V_29 |= ( F_24 << F_26 ) ;
#else
if ( V_44 == - 1 || V_45 == - 1 ) {
F_28 ( V_26 L_3
L_4 ) ;
}
#endif
}
void F_29 ( struct V_1 * V_2 , T_4 V_42 , T_4 V_43 )
{
F_27 ( & V_2 -> V_22 , V_42 , V_43 ) ;
}
void F_30 ( struct V_21 * V_50 , struct V_21 * V_23 )
{
V_50 -> V_29 &= V_51 | V_52 | V_53 ;
V_50 -> V_29 |= V_23 -> V_29 & ~ ( V_51 | V_52 | V_53 ) ;
V_50 -> V_41 = V_23 -> V_41 ;
V_50 -> V_36 = V_23 -> V_36 ;
}
int F_31 ( struct V_21 * V_54 , struct V_21 * V_55 )
{
if ( V_54 -> V_41 != V_55 -> V_41 || V_54 -> V_36 != V_55 -> V_36 )
return 1 ;
if ( ( V_54 -> V_29 ^ V_55 -> V_29 ) & ~ ( V_51 | V_52 | V_53 ) )
return 1 ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , struct V_21 * V_56 )
{
struct V_21 V_57 ;
struct V_58 * V_59 ;
F_33 ( V_2 -> V_60 -> type == V_61 &&
V_2 -> V_60 -> V_62 == V_63 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_57 = V_2 -> V_22 ;
V_2 -> V_22 = * V_56 ;
F_20 ( & V_2 -> V_22 , & V_57 , & V_2 -> V_64 ) ;
if ( V_2 -> V_3 -> V_65 )
V_2 -> V_3 -> V_65 ( V_2 , & V_57 ) ;
else
F_30 ( & V_2 -> V_22 , & V_57 ) ;
V_59 = F_34 ( V_2 ) ;
if ( V_59 != NULL ) {
if ( V_59 -> V_3 -> V_65 )
V_59 -> V_3 -> V_65 ( V_2 , & V_57 ) ;
F_35 ( V_59 ) ;
}
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int V_65 ( struct V_1 * V_2 , void T_5 * V_66 , int V_67 )
{
struct V_21 V_68 ;
struct V_58 * V_59 ;
int V_69 = F_36 ( V_2 ) ;
if ( V_69 )
return V_69 ;
F_37 ( & V_2 -> V_7 ) ;
V_68 = V_2 -> V_22 ;
F_38 ( & V_2 -> V_7 ) ;
if ( V_67 & V_70 ) {
if ( F_39 ( & V_68 ,
(struct V_71 T_5 * ) V_66 ) )
return - V_72 ;
#ifdef F_40
} else if ( V_67 & V_73 ) {
if ( F_41 ( & V_68 ,
(struct V_22 T_5 * ) V_66 ) )
return - V_72 ;
} else {
if ( F_42 ( & V_68 ,
(struct V_74 T_5 * ) V_66 ) )
return - V_72 ;
}
#else
}
void F_43 ( struct V_1 * V_2 , struct V_21 * V_75 )
{
F_37 ( & V_2 -> V_7 ) ;
* V_75 = V_2 -> V_22 ;
F_38 ( & V_2 -> V_7 ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_21 * V_75 )
{
F_37 ( & V_2 -> V_7 ) ;
* V_75 = V_2 -> V_64 ;
F_38 ( & V_2 -> V_7 ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_71 T_5 * V_71 )
{
struct V_21 V_75 ;
F_43 ( V_2 , & V_75 ) ;
if ( F_46 ( V_71 , & V_75 ) )
return - V_72 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , void T_5 * V_66 , int V_67 )
{
struct V_76 V_77 ;
struct V_58 * V_59 ;
if ( V_2 -> V_76 == NULL )
return - V_78 ;
if ( F_48 ( & V_77 , V_66 , sizeof( struct V_76 ) ) )
return - V_72 ;
V_59 = F_34 ( V_2 ) ;
if ( V_59 != NULL ) {
if ( ( V_67 & V_79 ) && V_59 -> V_3 -> V_6 )
V_59 -> V_3 -> V_6 ( V_2 ) ;
F_35 ( V_59 ) ;
}
if ( V_67 & V_80 ) {
F_17 ( V_2 , 0 ) ;
if ( F_49 ( V_81 ) )
return - V_82 ;
}
F_5 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_3 -> F_47 )
V_2 -> V_3 -> F_47 ( V_2 , & V_77 ) ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
if ( ! ( V_2 -> V_22 . V_30 & V_83 ) ) {
if ( V_2 -> V_22 . V_30 & V_84 )
V_9 |= 0x02 ;
else
V_9 |= 0x20 ;
}
if ( V_2 -> V_22 . V_30 & V_85 )
V_9 |= 0x08 ;
if ( V_2 -> V_22 . V_28 & V_86 )
if ( V_2 -> V_22 . V_28 & V_87 )
V_9 |= 0x10 ;
return V_9 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_88 T_5 * V_88 )
{
struct V_88 V_89 ;
F_37 ( & V_2 -> V_7 ) ;
V_89 . V_90 = V_2 -> V_22 . V_41 ;
V_89 . V_91 = V_2 -> V_22 . V_36 ;
V_89 . V_92 = V_2 -> V_22 . V_33 [ V_93 ] ;
V_89 . V_94 = V_2 -> V_22 . V_33 [ V_95 ] ;
V_89 . V_96 = F_50 ( V_2 ) ;
F_38 ( & V_2 -> V_7 ) ;
return F_52 ( V_88 , & V_89 , sizeof( V_89 ) ) ? - V_72 : 0 ;
}
static void F_53 ( struct V_21 * V_22 , int V_9 )
{
V_22 -> V_27 = V_97 | V_98 ;
V_22 -> V_28 = 0 ;
V_22 -> V_30 = V_84 | V_83 ;
if ( V_9 & 0x02 ) {
V_22 -> V_27 = 0 ;
V_22 -> V_30 &= ~ V_83 ;
}
if ( V_9 & 0x08 ) {
V_22 -> V_30 |= V_85 | V_99 | V_100 |
V_101 | V_102 | V_103 ;
}
if ( V_9 & 0x10 ) {
V_22 -> V_28 |= V_86 | V_87 ;
}
if ( V_9 & 0x20 ) {
V_22 -> V_27 = 0 ;
V_22 -> V_30 &= ~ ( V_84 | V_83 ) ;
}
if ( ! ( V_22 -> V_30 & V_83 ) ) {
V_22 -> V_33 [ V_104 ] = 1 ;
V_22 -> V_33 [ V_105 ] = 0 ;
}
}
static int F_54 ( struct V_1 * V_2 , struct V_88 T_5 * V_88 )
{
int V_69 ;
struct V_88 V_89 ;
struct V_21 V_22 ;
V_69 = F_36 ( V_2 ) ;
if ( V_69 )
return V_69 ;
if ( F_48 ( & V_89 , V_88 , sizeof( V_89 ) ) )
return - V_72 ;
F_5 ( & V_2 -> V_7 ) ;
V_22 = V_2 -> V_22 ;
V_22 . V_33 [ V_93 ] = V_89 . V_92 ;
V_22 . V_33 [ V_95 ] = V_89 . V_94 ;
F_53 ( & V_22 , V_89 . V_96 ) ;
#ifdef F_24
F_27 ( & V_22 , V_22 . V_41 ,
V_22 . V_36 ) ;
#endif
F_7 ( & V_2 -> V_7 ) ;
F_32 ( V_2 , & V_22 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_106 T_5 * V_106 )
{
struct V_106 V_89 ;
F_37 ( & V_2 -> V_7 ) ;
V_89 . V_107 = V_2 -> V_22 . V_33 [ V_108 ] ;
V_89 . V_109 = V_2 -> V_22 . V_33 [ V_110 ] ;
V_89 . V_111 = V_2 -> V_22 . V_33 [ V_112 ] ;
V_89 . V_113 = V_2 -> V_22 . V_33 [ V_114 ] ;
V_89 . V_115 = V_2 -> V_22 . V_33 [ V_116 ] ;
V_89 . V_117 = V_2 -> V_22 . V_33 [ V_118 ] ;
F_38 ( & V_2 -> V_7 ) ;
return F_52 ( V_106 , & V_89 , sizeof( V_89 ) ) ? - V_72 : 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_106 T_5 * V_106 )
{
struct V_106 V_89 ;
if ( F_48 ( & V_89 , V_106 , sizeof( V_89 ) ) )
return - V_72 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_22 . V_33 [ V_108 ] = V_89 . V_107 ;
V_2 -> V_22 . V_33 [ V_110 ] = V_89 . V_109 ;
V_2 -> V_22 . V_33 [ V_112 ] = V_89 . V_111 ;
V_2 -> V_22 . V_33 [ V_114 ] = V_89 . V_113 ;
V_2 -> V_22 . V_33 [ V_116 ] = V_89 . V_115 ;
V_2 -> V_22 . V_33 [ V_118 ] = V_89 . V_117 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_119 T_5 * V_119 )
{
struct V_119 V_89 ;
F_37 ( & V_2 -> V_7 ) ;
V_89 . V_120 = V_2 -> V_22 . V_33 [ V_121 ] ;
V_89 . V_122 = V_2 -> V_22 . V_33 [ V_121 ] ;
V_89 . V_123 = V_2 -> V_22 . V_33 [ V_124 ] ;
V_89 . V_125 = V_2 -> V_22 . V_33 [ V_118 ] ;
V_89 . V_126 = V_2 -> V_22 . V_33 [ V_127 ] ;
V_89 . V_128 = V_2 -> V_22 . V_33 [ V_129 ] ;
F_38 ( & V_2 -> V_7 ) ;
return F_52 ( V_119 , & V_89 , sizeof( V_89 ) ) ? - V_72 : 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_119 T_5 * V_119 )
{
struct V_119 V_89 ;
if ( F_48 ( & V_89 , V_119 , sizeof( V_89 ) ) )
return - V_72 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_22 . V_33 [ V_121 ] = V_89 . V_120 ;
V_2 -> V_22 . V_33 [ V_118 ] = V_89 . V_122 ;
V_2 -> V_22 . V_33 [ V_124 ] = V_89 . V_123 ;
V_2 -> V_22 . V_33 [ V_118 ] = V_89 . V_125 ;
V_2 -> V_22 . V_33 [ V_127 ] = V_89 . V_126 ;
V_2 -> V_22 . V_33 [ V_129 ] = V_89 . V_128 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int V_66 )
{
int V_13 = 0 ;
int V_130 = V_66 ? V_53 : 0 ;
struct V_21 V_23 ;
F_5 ( & V_2 -> V_7 ) ;
V_23 = V_2 -> V_22 ;
V_2 -> V_22 . V_29 &= ~ V_53 ;
V_2 -> V_22 . V_29 |= V_130 ;
if ( V_2 -> V_3 -> V_65 )
V_2 -> V_3 -> V_65 ( V_2 , & V_23 ) ;
if ( ( V_2 -> V_22 . V_29 & V_53 ) != V_130 )
V_13 = - V_78 ;
F_7 ( & V_2 -> V_7 ) ;
return V_13 ;
}
int F_60 ( struct V_1 * V_2 , struct V_131 * V_131 ,
unsigned int V_132 , unsigned long V_66 )
{
struct V_1 * V_133 ;
void T_5 * V_134 = ( void T_5 * ) V_66 ;
int V_13 = 0 ;
struct V_21 V_75 ;
F_61 ( V_131 == NULL ) ;
if ( V_2 -> V_60 -> type == V_61 &&
V_2 -> V_60 -> V_62 == V_63 )
V_133 = V_2 -> V_135 ;
else
V_133 = V_2 ;
switch ( V_132 ) {
#ifdef F_62
case F_62 :
return F_51 ( V_133 , (struct V_88 T_5 * ) V_66 ) ;
case V_136 :
case V_137 :
return F_54 ( V_133 , (struct V_88 T_5 * ) V_66 ) ;
#endif
#ifdef F_63
case F_63 :
return F_55 ( V_133 , V_134 ) ;
case V_138 :
return F_56 ( V_133 , V_134 ) ;
#endif
#ifdef F_64
case F_64 :
return F_57 ( V_133 , V_134 ) ;
case V_139 :
return F_58 ( V_133 , V_134 ) ;
#endif
case V_140 :
return V_65 ( V_133 , V_134 , V_79 | V_80 | V_73 ) ;
case V_141 :
return V_65 ( V_133 , V_134 , V_80 | V_73 ) ;
case V_142 :
return V_65 ( V_133 , V_134 , V_73 ) ;
#ifndef F_40
case V_143 :
F_43 ( V_133 , & V_75 ) ;
if ( F_65 ( (struct V_22 T_5 * ) V_66 , & V_75 ) )
V_13 = - V_72 ;
return V_13 ;
#else
case V_143 :
F_43 ( V_133 , & V_75 ) ;
if ( F_66 ( (struct V_22 T_5 * ) V_66 , & V_75 ) )
V_13 = - V_72 ;
return V_13 ;
case F_40 :
F_43 ( V_133 , & V_75 ) ;
if ( F_65 ( (struct V_74 T_5 * ) V_66 , & V_75 ) )
V_13 = - V_72 ;
return V_13 ;
case V_144 :
return V_65 ( V_133 , V_134 , V_79 | V_80 ) ;
case V_145 :
return V_65 ( V_133 , V_134 , V_80 ) ;
case V_146 :
return V_65 ( V_133 , V_134 , 0 ) ;
#endif
case V_147 :
return F_45 ( V_133 , V_134 ) ;
case V_148 :
return V_65 ( V_133 , V_134 , V_79 | V_80 | V_70 ) ;
case V_149 :
return V_65 ( V_133 , V_134 , V_80 | V_70 ) ;
case V_150 :
return V_65 ( V_133 , V_134 , V_70 ) ;
#ifndef F_40
case V_151 :
F_44 ( V_133 , & V_75 ) ;
if ( F_65 ( (struct V_22 T_5 * ) V_66 , & V_75 ) )
V_13 = - V_72 ;
return V_13 ;
case V_152 :
if ( ! F_67 ( V_153 ) )
return - V_154 ;
F_44 ( V_133 , & V_75 ) ;
if ( F_42 ( & V_75 ,
(struct V_22 T_5 * ) V_66 ) )
return - V_72 ;
F_5 ( & V_133 -> V_7 ) ;
V_133 -> V_64 = V_75 ;
F_7 ( & V_133 -> V_7 ) ;
return 0 ;
#else
case V_151 :
F_44 ( V_133 , & V_75 ) ;
if ( F_66 ( (struct V_22 T_5 * ) V_66 , & V_75 ) )
V_13 = - V_72 ;
return V_13 ;
case V_152 :
if ( ! F_67 ( V_153 ) )
return - V_154 ;
F_44 ( V_133 , & V_75 ) ;
if ( F_41 ( & V_75 ,
(struct V_22 T_5 * ) V_66 ) )
return - V_72 ;
F_5 ( & V_133 -> V_7 ) ;
V_133 -> V_64 = V_75 ;
F_7 ( & V_133 -> V_7 ) ;
return V_13 ;
#endif
#ifdef F_68
case F_68 : {
struct V_76 V_155 ;
if ( V_133 -> V_76 == NULL )
return - V_78 ;
F_37 ( & V_133 -> V_7 ) ;
memcpy ( & V_155 , V_133 -> V_76 , sizeof( struct V_76 ) ) ;
F_38 ( & V_133 -> V_7 ) ;
if ( F_52 ( V_134 , & V_155 , sizeof( struct V_76 ) ) )
V_13 = - V_72 ;
return V_13 ;
}
case V_156 :
return F_47 ( V_133 , V_134 , 0 ) ;
case V_157 :
return F_47 ( V_133 , V_134 , V_80 ) ;
case V_158 :
return F_47 ( V_133 , V_134 , V_79 ) ;
#endif
case V_159 :
F_43 ( V_133 , & V_75 ) ;
V_13 = F_69 ( ( V_75 . V_29 & V_53 ) ? 1 : 0 ,
( int T_5 * ) V_66 ) ;
return V_13 ;
case V_160 :
if ( F_70 ( V_66 , ( unsigned int T_5 * ) V_66 ) )
return - V_72 ;
return F_59 ( V_133 , V_66 ) ;
default:
return - V_161 ;
}
}
static int F_71 ( struct V_1 * V_2 , unsigned long V_66 )
{
struct V_58 * V_59 = V_2 -> V_162 ;
switch ( V_66 ) {
case V_163 :
if ( V_59 && V_59 -> V_3 -> V_6 ) {
V_59 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
break;
case V_164 :
if ( V_59 && V_59 -> V_3 -> V_6 ) {
V_59 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
case V_165 :
F_3 ( V_2 ) ;
break;
default:
return - V_78 ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_2 , unsigned long V_66 )
{
struct V_58 * V_59 ;
int V_69 = F_36 ( V_2 ) ;
if ( V_69 )
return V_69 ;
V_59 = F_73 ( V_2 ) ;
V_69 = F_71 ( V_2 , V_66 ) ;
if ( V_59 )
F_35 ( V_59 ) ;
return V_69 ;
}
int F_74 ( struct V_1 * V_2 , struct V_131 * V_131 ,
unsigned int V_132 , unsigned long V_66 )
{
int V_69 ;
switch ( V_132 ) {
case V_166 :
V_69 = F_36 ( V_2 ) ;
if ( V_69 )
return V_69 ;
switch ( V_66 ) {
case V_167 :
F_75 ( & V_2 -> V_168 ) ;
if ( ! V_2 -> V_169 ) {
V_2 -> V_169 = 1 ;
F_76 ( V_2 ) ;
}
F_77 ( & V_2 -> V_168 ) ;
break;
case V_170 :
F_75 ( & V_2 -> V_168 ) ;
if ( V_2 -> V_169 ) {
V_2 -> V_169 = 0 ;
F_78 ( V_2 ) ;
}
F_77 ( & V_2 -> V_168 ) ;
break;
case V_171 :
F_37 ( & V_2 -> V_7 ) ;
if ( F_79 ( V_2 ) != V_172 )
V_69 = F_80 ( V_2 , F_79 ( V_2 ) ) ;
F_38 ( & V_2 -> V_7 ) ;
break;
case V_173 :
F_37 ( & V_2 -> V_7 ) ;
if ( F_81 ( V_2 ) != V_172 )
V_69 = F_80 ( V_2 , F_81 ( V_2 ) ) ;
F_38 ( & V_2 -> V_7 ) ;
break;
default:
return - V_78 ;
}
return V_69 ;
case V_174 :
V_69 = F_36 ( V_2 ) ;
if ( V_69 )
return V_69 ;
return F_71 ( V_2 , V_66 ) ;
default:
return F_60 ( V_2 , V_131 , V_132 , V_66 ) ;
}
}
long F_82 ( struct V_1 * V_2 , struct V_131 * V_131 ,
unsigned int V_132 , unsigned long V_66 )
{
switch ( V_132 ) {
case V_151 :
case V_152 :
return F_60 ( V_2 , V_131 , V_132 , ( unsigned long ) F_83 ( V_66 ) ) ;
default:
return - V_161 ;
}
}
