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
if ( ! F_12 ( V_2 ) ) {
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
if ( F_12 ( V_2 ) ) {
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
F_18 ( V_2 , L_1 , V_17 ) ;
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
static void F_20 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_21 * V_23 = & V_2 -> V_23 ;
struct V_21 * V_24 = & V_2 -> V_25 ;
int V_26 ;
#define F_21 ( T_1 , T_2 , T_3 ) (x = ((x) & ~(z)) | ((y) & (z)))
F_21 ( V_23 -> V_27 , V_22 -> V_27 , V_24 -> V_27 ) ;
F_21 ( V_23 -> V_28 , V_22 -> V_28 , V_24 -> V_28 ) ;
F_21 ( V_23 -> V_29 , V_22 -> V_29 , V_24 -> V_29 ) ;
F_21 ( V_23 -> V_30 , V_22 -> V_30 , V_24 -> V_30 ) ;
V_23 -> V_31 = V_24 -> V_31 ? V_22 -> V_31 : V_23 -> V_31 ;
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ )
V_23 -> V_33 [ V_26 ] = V_24 -> V_33 [ V_26 ] ?
V_22 -> V_33 [ V_26 ] : V_23 -> V_33 [ V_26 ] ;
}
T_4 F_22 ( struct V_21 * V_23 )
{
unsigned int V_34 ;
V_34 = V_23 -> V_29 & V_35 ;
#ifdef F_23
if ( V_34 == F_23 )
return V_23 -> V_36 ;
#endif
if ( V_34 & V_37 ) {
V_34 &= ~ V_37 ;
if ( V_34 < 1 || V_34 + 15 > V_38 )
V_23 -> V_29 &= ~ V_37 ;
else
V_34 += 15 ;
}
return V_39 [ V_34 ] ;
}
T_4 F_24 ( struct V_21 * V_23 )
{
#ifdef F_25
unsigned int V_34 = ( V_23 -> V_29 >> F_25 ) & V_35 ;
if ( V_34 == V_40 )
return F_22 ( V_23 ) ;
if ( V_34 == F_23 )
return V_23 -> V_41 ;
if ( V_34 & V_37 ) {
V_34 &= ~ V_37 ;
if ( V_34 < 1 || V_34 + 15 > V_38 )
V_23 -> V_29 &= ~ ( V_37 << F_25 ) ;
else
V_34 += 15 ;
}
return V_39 [ V_34 ] ;
#else
return F_22 ( V_23 ) ;
#endif
}
void F_26 ( struct V_21 * V_23 ,
T_4 V_42 , T_4 V_43 )
{
int V_26 = 0 ;
int V_44 = - 1 , V_45 = - 1 ;
int V_46 = V_42 / 50 , V_47 = V_43 / 50 ;
int V_48 = 0 ;
if ( V_43 == 0 )
V_42 = 0 ;
V_23 -> V_41 = V_42 ;
V_23 -> V_36 = V_43 ;
#ifdef F_23
if ( ( V_23 -> V_29 & V_35 ) == F_23 )
V_47 = 0 ;
if ( ( ( V_23 -> V_29 >> F_25 ) & V_35 ) == F_23 )
V_46 = 0 ;
if ( ( V_23 -> V_29 >> F_25 ) & V_35 )
V_48 = 1 ;
#endif
V_23 -> V_29 &= ~ V_35 ;
do {
if ( V_43 - V_47 <= V_39 [ V_26 ] &&
V_43 + V_47 >= V_39 [ V_26 ] ) {
V_23 -> V_29 |= V_49 [ V_26 ] ;
V_45 = V_26 ;
}
if ( V_42 - V_46 <= V_39 [ V_26 ] &&
V_42 + V_46 >= V_39 [ V_26 ] ) {
if ( V_45 == V_26 && ! V_48 )
V_44 = V_26 ;
#ifdef F_25
else {
V_44 = V_26 ;
V_23 -> V_29 |= ( V_49 [ V_26 ] << F_25 ) ;
}
#endif
}
} while ( ++ V_26 < V_38 );
#ifdef F_23
if ( V_45 == - 1 )
V_23 -> V_29 |= F_23 ;
if ( V_44 == - 1 && ( V_42 != V_43 || V_48 ) )
V_23 -> V_29 |= ( F_23 << F_25 ) ;
#else
if ( V_44 == - 1 || V_45 == - 1 )
F_27 ( L_2 ) ;
#endif
}
void F_28 ( struct V_1 * V_2 , T_4 V_42 , T_4 V_43 )
{
F_26 ( & V_2 -> V_23 , V_42 , V_43 ) ;
}
void F_29 ( struct V_21 * V_50 , struct V_21 * V_22 )
{
V_50 -> V_29 &= V_51 | V_52 | V_53 ;
V_50 -> V_29 |= V_22 -> V_29 & ~ ( V_51 | V_52 | V_53 ) ;
V_50 -> V_41 = V_22 -> V_41 ;
V_50 -> V_36 = V_22 -> V_36 ;
}
int F_30 ( struct V_21 * V_54 , struct V_21 * V_55 )
{
if ( V_54 -> V_41 != V_55 -> V_41 || V_54 -> V_36 != V_55 -> V_36 )
return 1 ;
if ( ( V_54 -> V_29 ^ V_55 -> V_29 ) & ~ ( V_51 | V_52 | V_53 ) )
return 1 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_21 * V_56 )
{
struct V_21 V_57 ;
struct V_58 * V_59 ;
F_32 ( V_2 -> V_60 -> type == V_61 &&
V_2 -> V_60 -> V_62 == V_63 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_57 = V_2 -> V_23 ;
V_2 -> V_23 = * V_56 ;
F_20 ( V_2 , & V_57 ) ;
if ( V_2 -> V_3 -> V_64 )
V_2 -> V_3 -> V_64 ( V_2 , & V_57 ) ;
else
F_29 ( & V_2 -> V_23 , & V_57 ) ;
V_59 = F_33 ( V_2 ) ;
if ( V_59 != NULL ) {
if ( V_59 -> V_3 -> V_64 )
V_59 -> V_3 -> V_64 ( V_2 , & V_57 ) ;
F_34 ( V_59 ) ;
}
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int V_64 ( struct V_1 * V_2 , void T_5 * V_65 , int V_66 )
{
struct V_21 V_67 ;
struct V_58 * V_59 ;
int V_68 = F_35 ( V_2 ) ;
if ( V_68 )
return V_68 ;
F_36 ( & V_2 -> V_7 ) ;
V_67 = V_2 -> V_23 ;
F_37 ( & V_2 -> V_7 ) ;
if ( V_66 & V_69 ) {
if ( F_38 ( & V_67 ,
(struct V_70 T_5 * ) V_65 ) )
return - V_71 ;
#ifdef F_39
} else if ( V_66 & V_72 ) {
if ( F_40 ( & V_67 ,
(struct V_23 T_5 * ) V_65 ) )
return - V_71 ;
} else {
if ( F_41 ( & V_67 ,
(struct V_73 T_5 * ) V_65 ) )
return - V_71 ;
}
#else
}
void F_42 ( struct V_1 * V_2 , struct V_21 * V_74 )
{
F_36 ( & V_2 -> V_7 ) ;
* V_74 = V_2 -> V_23 ;
F_37 ( & V_2 -> V_7 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_21 * V_74 )
{
F_36 ( & V_2 -> V_7 ) ;
* V_74 = V_2 -> V_25 ;
F_37 ( & V_2 -> V_7 ) ;
}
static int F_44 ( struct V_1 * V_2 , struct V_70 T_5 * V_70 )
{
struct V_21 V_74 ;
F_42 ( V_2 , & V_74 ) ;
if ( F_45 ( V_70 , & V_74 ) )
return - V_71 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , void T_5 * V_65 , int V_66 )
{
struct V_75 V_76 ;
struct V_58 * V_59 ;
if ( V_2 -> V_75 == NULL )
return - V_77 ;
if ( F_47 ( & V_76 , V_65 , sizeof( struct V_75 ) ) )
return - V_71 ;
V_59 = F_33 ( V_2 ) ;
if ( V_59 != NULL ) {
if ( ( V_66 & V_78 ) && V_59 -> V_3 -> V_6 )
V_59 -> V_3 -> V_6 ( V_2 ) ;
F_34 ( V_59 ) ;
}
if ( V_66 & V_79 ) {
F_17 ( V_2 , 0 ) ;
if ( F_48 ( V_80 ) )
return - V_81 ;
}
F_5 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_3 -> F_46 )
V_2 -> V_3 -> F_46 ( V_2 , & V_76 ) ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
if ( ! F_50 ( V_2 ) ) {
if ( F_51 ( V_2 ) )
V_9 |= 0x02 ;
else
V_9 |= 0x20 ;
}
if ( F_52 ( V_2 ) )
V_9 |= 0x08 ;
if ( F_53 ( V_2 ) )
if ( F_54 ( V_2 ) )
V_9 |= 0x10 ;
return V_9 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_82 T_5 * V_82 )
{
struct V_82 V_83 ;
F_36 ( & V_2 -> V_7 ) ;
V_83 . V_84 = V_2 -> V_23 . V_41 ;
V_83 . V_85 = V_2 -> V_23 . V_36 ;
V_83 . V_86 = V_2 -> V_23 . V_33 [ V_87 ] ;
V_83 . V_88 = V_2 -> V_23 . V_33 [ V_89 ] ;
V_83 . V_90 = F_49 ( V_2 ) ;
F_37 ( & V_2 -> V_7 ) ;
return F_56 ( V_82 , & V_83 , sizeof( V_83 ) ) ? - V_71 : 0 ;
}
static void F_57 ( struct V_21 * V_23 , int V_9 )
{
V_23 -> V_27 = V_91 | V_92 ;
V_23 -> V_28 = 0 ;
V_23 -> V_30 = V_93 | V_94 ;
if ( V_9 & 0x02 ) {
V_23 -> V_27 = 0 ;
V_23 -> V_30 &= ~ V_94 ;
}
if ( V_9 & 0x08 ) {
V_23 -> V_30 |= V_95 | V_96 | V_97 |
V_98 | V_99 | V_100 ;
}
if ( V_9 & 0x10 ) {
V_23 -> V_28 |= V_101 | V_102 ;
}
if ( V_9 & 0x20 ) {
V_23 -> V_27 = 0 ;
V_23 -> V_30 &= ~ ( V_93 | V_94 ) ;
}
if ( ! ( V_23 -> V_30 & V_94 ) ) {
V_23 -> V_33 [ V_103 ] = 1 ;
V_23 -> V_33 [ V_104 ] = 0 ;
}
}
static int F_58 ( struct V_1 * V_2 , struct V_82 T_5 * V_82 )
{
int V_68 ;
struct V_82 V_83 ;
struct V_21 V_23 ;
V_68 = F_35 ( V_2 ) ;
if ( V_68 )
return V_68 ;
if ( F_47 ( & V_83 , V_82 , sizeof( V_83 ) ) )
return - V_71 ;
F_5 ( & V_2 -> V_7 ) ;
V_23 = V_2 -> V_23 ;
V_23 . V_33 [ V_87 ] = V_83 . V_86 ;
V_23 . V_33 [ V_89 ] = V_83 . V_88 ;
F_57 ( & V_23 , V_83 . V_90 ) ;
#ifdef F_23
F_26 ( & V_23 , V_23 . V_41 ,
V_23 . V_36 ) ;
#endif
F_7 ( & V_2 -> V_7 ) ;
F_31 ( V_2 , & V_23 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_105 T_5 * V_105 )
{
struct V_105 V_83 ;
F_36 ( & V_2 -> V_7 ) ;
V_83 . V_106 = V_2 -> V_23 . V_33 [ V_107 ] ;
V_83 . V_108 = V_2 -> V_23 . V_33 [ V_109 ] ;
V_83 . V_110 = V_2 -> V_23 . V_33 [ V_111 ] ;
V_83 . V_112 = V_2 -> V_23 . V_33 [ V_113 ] ;
V_83 . V_114 = V_2 -> V_23 . V_33 [ V_115 ] ;
V_83 . V_116 = V_2 -> V_23 . V_33 [ V_117 ] ;
F_37 ( & V_2 -> V_7 ) ;
return F_56 ( V_105 , & V_83 , sizeof( V_83 ) ) ? - V_71 : 0 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_105 T_5 * V_105 )
{
struct V_105 V_83 ;
if ( F_47 ( & V_83 , V_105 , sizeof( V_83 ) ) )
return - V_71 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_23 . V_33 [ V_107 ] = V_83 . V_106 ;
V_2 -> V_23 . V_33 [ V_109 ] = V_83 . V_108 ;
V_2 -> V_23 . V_33 [ V_111 ] = V_83 . V_110 ;
V_2 -> V_23 . V_33 [ V_113 ] = V_83 . V_112 ;
V_2 -> V_23 . V_33 [ V_115 ] = V_83 . V_114 ;
V_2 -> V_23 . V_33 [ V_117 ] = V_83 . V_116 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_118 T_5 * V_118 )
{
struct V_118 V_83 ;
F_36 ( & V_2 -> V_7 ) ;
V_83 . V_119 = V_2 -> V_23 . V_33 [ V_120 ] ;
V_83 . V_121 = V_2 -> V_23 . V_33 [ V_120 ] ;
V_83 . V_122 = V_2 -> V_23 . V_33 [ V_123 ] ;
V_83 . V_124 = V_2 -> V_23 . V_33 [ V_117 ] ;
V_83 . V_125 = V_2 -> V_23 . V_33 [ V_126 ] ;
V_83 . V_127 = V_2 -> V_23 . V_33 [ V_128 ] ;
F_37 ( & V_2 -> V_7 ) ;
return F_56 ( V_118 , & V_83 , sizeof( V_83 ) ) ? - V_71 : 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_118 T_5 * V_118 )
{
struct V_118 V_83 ;
if ( F_47 ( & V_83 , V_118 , sizeof( V_83 ) ) )
return - V_71 ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_23 . V_33 [ V_120 ] = V_83 . V_119 ;
V_2 -> V_23 . V_33 [ V_117 ] = V_83 . V_121 ;
V_2 -> V_23 . V_33 [ V_123 ] = V_83 . V_122 ;
V_2 -> V_23 . V_33 [ V_117 ] = V_83 . V_124 ;
V_2 -> V_23 . V_33 [ V_126 ] = V_83 . V_125 ;
V_2 -> V_23 . V_33 [ V_128 ] = V_83 . V_127 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , int V_65 )
{
int V_13 = 0 ;
int V_129 = V_65 ? V_53 : 0 ;
struct V_21 V_22 ;
F_5 ( & V_2 -> V_7 ) ;
V_22 = V_2 -> V_23 ;
V_2 -> V_23 . V_29 &= ~ V_53 ;
V_2 -> V_23 . V_29 |= V_129 ;
if ( V_2 -> V_3 -> V_64 )
V_2 -> V_3 -> V_64 ( V_2 , & V_22 ) ;
if ( F_64 ( V_2 ) != V_129 )
V_13 = - V_77 ;
F_7 ( & V_2 -> V_7 ) ;
return V_13 ;
}
int F_65 ( struct V_1 * V_2 , struct V_130 * V_130 ,
unsigned int V_131 , unsigned long V_65 )
{
struct V_1 * V_132 ;
void T_5 * V_133 = ( void T_5 * ) V_65 ;
int V_13 = 0 ;
struct V_21 V_74 ;
F_66 ( V_130 == NULL ) ;
if ( V_2 -> V_60 -> type == V_61 &&
V_2 -> V_60 -> V_62 == V_63 )
V_132 = V_2 -> V_134 ;
else
V_132 = V_2 ;
switch ( V_131 ) {
#ifdef F_67
case F_67 :
return F_55 ( V_132 , (struct V_82 T_5 * ) V_65 ) ;
case V_135 :
case V_136 :
return F_58 ( V_132 , (struct V_82 T_5 * ) V_65 ) ;
#endif
#ifdef F_68
case F_68 :
return F_59 ( V_132 , V_133 ) ;
case V_137 :
return F_60 ( V_132 , V_133 ) ;
#endif
#ifdef F_69
case F_69 :
return F_61 ( V_132 , V_133 ) ;
case V_138 :
return F_62 ( V_132 , V_133 ) ;
#endif
case V_139 :
return V_64 ( V_132 , V_133 , V_78 | V_79 | V_72 ) ;
case V_140 :
return V_64 ( V_132 , V_133 , V_79 | V_72 ) ;
case V_141 :
return V_64 ( V_132 , V_133 , V_72 ) ;
#ifndef F_39
case V_142 :
F_42 ( V_132 , & V_74 ) ;
if ( F_70 ( (struct V_23 T_5 * ) V_65 , & V_74 ) )
V_13 = - V_71 ;
return V_13 ;
#else
case V_142 :
F_42 ( V_132 , & V_74 ) ;
if ( F_71 ( (struct V_23 T_5 * ) V_65 , & V_74 ) )
V_13 = - V_71 ;
return V_13 ;
case F_39 :
F_42 ( V_132 , & V_74 ) ;
if ( F_70 ( (struct V_73 T_5 * ) V_65 , & V_74 ) )
V_13 = - V_71 ;
return V_13 ;
case V_143 :
return V_64 ( V_132 , V_133 , V_78 | V_79 ) ;
case V_144 :
return V_64 ( V_132 , V_133 , V_79 ) ;
case V_145 :
return V_64 ( V_132 , V_133 , 0 ) ;
#endif
case V_146 :
return F_44 ( V_132 , V_133 ) ;
case V_147 :
return V_64 ( V_132 , V_133 , V_78 | V_79 | V_69 ) ;
case V_148 :
return V_64 ( V_132 , V_133 , V_79 | V_69 ) ;
case V_149 :
return V_64 ( V_132 , V_133 , V_69 ) ;
#ifndef F_39
case V_150 :
F_43 ( V_132 , & V_74 ) ;
if ( F_70 ( (struct V_23 T_5 * ) V_65 , & V_74 ) )
V_13 = - V_71 ;
return V_13 ;
case V_151 :
if ( ! F_72 ( V_152 ) )
return - V_153 ;
F_43 ( V_132 , & V_74 ) ;
if ( F_41 ( & V_74 ,
(struct V_23 T_5 * ) V_65 ) )
return - V_71 ;
F_5 ( & V_132 -> V_7 ) ;
V_132 -> V_25 = V_74 ;
F_7 ( & V_132 -> V_7 ) ;
return 0 ;
#else
case V_150 :
F_43 ( V_132 , & V_74 ) ;
if ( F_71 ( (struct V_23 T_5 * ) V_65 , & V_74 ) )
V_13 = - V_71 ;
return V_13 ;
case V_151 :
if ( ! F_72 ( V_152 ) )
return - V_153 ;
F_43 ( V_132 , & V_74 ) ;
if ( F_40 ( & V_74 ,
(struct V_23 T_5 * ) V_65 ) )
return - V_71 ;
F_5 ( & V_132 -> V_7 ) ;
V_132 -> V_25 = V_74 ;
F_7 ( & V_132 -> V_7 ) ;
return V_13 ;
#endif
#ifdef F_73
case F_73 : {
struct V_75 V_154 ;
if ( V_132 -> V_75 == NULL )
return - V_77 ;
F_36 ( & V_132 -> V_7 ) ;
memcpy ( & V_154 , V_132 -> V_75 , sizeof( struct V_75 ) ) ;
F_37 ( & V_132 -> V_7 ) ;
if ( F_56 ( V_133 , & V_154 , sizeof( struct V_75 ) ) )
V_13 = - V_71 ;
return V_13 ;
}
case V_155 :
return F_46 ( V_132 , V_133 , 0 ) ;
case V_156 :
return F_46 ( V_132 , V_133 , V_79 ) ;
case V_157 :
return F_46 ( V_132 , V_133 , V_78 ) ;
#endif
case V_158 :
F_42 ( V_132 , & V_74 ) ;
V_13 = F_74 ( ( V_74 . V_29 & V_53 ) ? 1 : 0 ,
( int T_5 * ) V_65 ) ;
return V_13 ;
case V_159 :
if ( F_75 ( V_65 , ( unsigned int T_5 * ) V_65 ) )
return - V_71 ;
return F_63 ( V_132 , V_65 ) ;
default:
return - V_160 ;
}
}
static int F_76 ( struct V_1 * V_2 , unsigned long V_65 )
{
struct V_58 * V_59 = V_2 -> V_161 ;
switch ( V_65 ) {
case V_162 :
if ( V_59 && V_59 -> V_3 -> V_6 ) {
V_59 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
break;
case V_163 :
if ( V_59 && V_59 -> V_3 -> V_6 ) {
V_59 -> V_3 -> V_6 ( V_2 ) ;
F_8 ( V_2 ) ;
}
case V_164 :
F_3 ( V_2 ) ;
break;
default:
return - V_77 ;
}
return 0 ;
}
int F_77 ( struct V_1 * V_2 , unsigned long V_65 )
{
struct V_58 * V_59 ;
int V_68 = F_35 ( V_2 ) ;
if ( V_68 )
return V_68 ;
V_59 = F_78 ( V_2 ) ;
V_68 = F_76 ( V_2 , V_65 ) ;
if ( V_59 )
F_34 ( V_59 ) ;
return V_68 ;
}
int F_79 ( struct V_1 * V_2 , struct V_130 * V_130 ,
unsigned int V_131 , unsigned long V_65 )
{
int V_68 ;
switch ( V_131 ) {
case V_165 :
V_68 = F_35 ( V_2 ) ;
if ( V_68 )
return V_68 ;
switch ( V_65 ) {
case V_166 :
F_80 ( & V_2 -> V_167 ) ;
if ( ! V_2 -> V_168 ) {
V_2 -> V_168 = 1 ;
F_81 ( V_2 ) ;
}
F_82 ( & V_2 -> V_167 ) ;
break;
case V_169 :
F_80 ( & V_2 -> V_167 ) ;
if ( V_2 -> V_168 ) {
V_2 -> V_168 = 0 ;
F_83 ( V_2 ) ;
}
F_82 ( & V_2 -> V_167 ) ;
break;
case V_170 :
if ( F_84 ( V_2 ) != V_171 )
V_68 = F_85 ( V_2 , F_84 ( V_2 ) ) ;
break;
case V_172 :
if ( F_86 ( V_2 ) != V_171 )
V_68 = F_85 ( V_2 , F_86 ( V_2 ) ) ;
break;
default:
return - V_77 ;
}
return V_68 ;
case V_173 :
V_68 = F_35 ( V_2 ) ;
if ( V_68 )
return V_68 ;
return F_76 ( V_2 , V_65 ) ;
default:
return F_65 ( V_2 , V_130 , V_131 , V_65 ) ;
}
}
long F_87 ( struct V_1 * V_2 , struct V_130 * V_130 ,
unsigned int V_131 , unsigned long V_65 )
{
switch ( V_131 ) {
case V_150 :
case V_151 :
return F_65 ( V_2 , V_130 , V_131 , ( unsigned long ) F_88 ( V_65 ) ) ;
default:
return - V_160 ;
}
}
