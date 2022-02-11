static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , bool V_6 )
{
T_1 V_7 = F_2 ( V_2 , V_8 ) ;
unsigned long V_9 = V_10 + ( V_11 * V_12 ) ;
F_3 ( & V_2 -> V_13 ) ;
F_4 ( L_1 , V_3 ) ;
F_5 ( V_2 , V_8 , V_7 | V_3 ) ;
V_7 = F_2 ( V_2 , V_8 ) ;
while ( ( V_7 & V_5 ) != V_4 ) {
if ( F_6 ( V_10 , V_9 ) ) {
F_7 ( & V_2 -> V_14 , L_2 ) ;
F_8 ( & V_2 -> V_13 ) ;
return - V_15 ;
}
F_9 ( L_3 ,
V_7 | V_3 ) ;
F_10 () ;
V_7 = F_2 ( V_2 , V_8 ) ;
} ;
F_4 ( L_4 , V_3 ) ;
V_2 -> V_6 = V_6 ;
F_8 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_4 ( L_5 ) ;
return F_1 ( V_2 , V_16 ,
V_17 ,
V_18 , true ) ;
}
int F_12 ( struct V_1 * V_2 )
{
F_4 ( L_6 ) ;
return F_1 ( V_2 , 0 , V_19 ,
V_18 , false ) ;
}
int F_13 ( struct V_1 * V_2 )
{
F_4 ( L_7 ) ;
return F_1 ( V_2 , V_20 ,
V_21 | V_19 ,
V_22 | V_18 ,
false ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
return 0 ;
return F_11 ( V_2 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
T_1 V_23 = F_16 ( V_2 , V_24 ) ;
T_1 V_7 = F_2 ( V_2 , V_8 ) ;
T_1 V_25 , V_26 ;
T_1 V_27 , V_28 ;
unsigned long V_9 = V_10 + ( V_11 * V_12 ) ;
F_4 ( L_8 ) ;
if ( ( V_7 & V_18 ) != V_19 ) {
F_17 ( 1 , L_9 ) ;
F_12 ( V_2 ) ;
}
F_18 ( V_2 , V_24 ,
V_23 | V_29 ) ;
V_27 = F_19 () ;
V_23 = F_16 ( V_2 , V_24 ) ;
while ( ( V_23 & V_30 )
== V_31 ) {
if ( F_6 ( V_10 , V_9 ) ) {
F_7 ( & V_2 -> V_14 , L_10 ) ;
return - V_15 ;
}
V_25 = F_2 ( V_2 , V_32 ) ;
F_9 ( L_11 , V_23 , V_25 ) ;
if ( V_25 & V_33 ) {
V_26 = F_2 ( V_2 , V_34 ) ;
F_20 ( & V_2 -> V_14 , L_12 , V_25 , V_26 ) ;
F_5 ( V_2 , V_35 , V_36 ) ;
} else if ( V_25 ) {
F_20 ( & V_2 -> V_14 , L_13 , V_25 ) ;
F_5 ( V_2 , V_35 , V_37 ) ;
} else {
F_10 () ;
}
V_23 = F_16 ( V_2 , V_24 ) ;
} ;
V_28 = F_19 () ;
F_4 ( L_14 , V_28 - V_27 ) ;
F_18 ( V_2 , V_24 ,
V_23 & ~ V_29 ) ;
return 0 ;
}
static int F_21 ( int V_38 )
{
return ( ( V_38 / 8 ) - 96 ) / 17 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_1 V_39 ;
V_2 -> V_40 = 0 ;
do {
V_2 -> V_40 ++ ;
V_2 -> V_38 = ( 1 << V_2 -> V_40 ) * V_41 ;
V_2 -> F_21 = F_21 ( V_2 -> V_38 ) ;
} while ( V_2 -> F_21 < V_2 -> V_42 );
F_23 ( V_2 -> V_38 > 0x100000 ) ;
if ( ! ( V_2 -> V_43 = (struct V_44 * )
F_24 ( V_45 | V_46 , V_2 -> V_40 ) ) ) {
F_25 ( L_15 ) ;
return - V_47 ;
}
F_4 ( L_16 ,
1 << V_2 -> V_40 , V_2 -> F_21 , V_2 -> V_42 ) ;
V_2 -> V_48 = ( V_49 * ) ( ( char * ) V_2 -> V_43 +
( ( V_2 -> F_21 + 3 ) * 128 ) ) ;
V_39 = F_26 ( V_2 -> V_43 ) & V_50 ;
V_39 |= ( ( V_2 -> V_38 >> ( 12 - V_51 ) ) - 1 ) & V_52 ;
V_39 |= V_53 ;
F_4 ( L_17 , V_2 -> V_43 , V_2 -> F_21 , V_2 -> V_48 , V_39 ) ;
F_18 ( V_2 , V_54 , V_39 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( ( unsigned long ) V_2 -> V_43 , V_2 -> V_40 ) ;
}
int F_29 ( struct V_55 * V_56 )
{
unsigned long V_9 = V_10 + ( V_11 * V_12 ) ;
F_4 ( L_18 ) ;
F_30 ( V_56 , V_57 , V_58 ) ;
F_30 ( V_56 , V_59 , V_60 ) ;
while ( F_31 ( V_56 , V_59 ) & V_61 ) {
if ( F_6 ( V_10 , V_9 ) ) {
F_7 ( & V_56 -> V_14 , L_19 ) ;
return - V_15 ;
}
F_10 () ;
}
F_30 ( V_56 , V_62 , V_60 ) ;
while ( F_31 ( V_56 , V_62 ) & V_61 ) {
if ( F_6 ( V_10 , V_9 ) ) {
F_7 ( & V_56 -> V_14 , L_20 ) ;
return - V_15 ;
}
F_10 () ;
}
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
unsigned long V_9 = V_10 + ( V_11 * V_12 ) ;
F_4 ( L_21 ) ;
F_5 ( V_2 , V_63 , V_60 ) ;
while ( F_2 ( V_2 , V_63 ) & V_61 ) {
if ( F_6 ( V_10 , V_9 ) ) {
F_7 ( & V_2 -> V_14 , L_22 ) ;
return - V_15 ;
}
F_10 () ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_64 , T_1 V_65 )
{
int V_66 ;
F_5 ( V_2 , V_67 , 0 ) ;
if ( ( V_66 = F_32 ( V_2 ) ) )
return V_66 ;
F_5 ( V_2 , V_68 , V_64 ) ;
F_5 ( V_2 , V_67 , V_65 ) ;
return 0 ;
}
static void F_34 ( struct V_69 * V_70 )
{
struct V_55 * V_56 = V_70 -> V_2 -> V_56 ;
T_1 V_71 ;
F_23 ( ! F_35 ( & V_70 -> V_2 -> V_72 ) ) ;
F_30 ( V_56 , V_73 ,
( ( T_1 ) F_36 ( V_70 -> V_74 -> V_75 . V_76 ) << 32 ) |
F_36 ( V_70 -> V_74 -> V_77 ) ) ;
F_30 ( V_56 , V_62 , V_78 ) ;
while ( 1 ) {
V_71 = F_31 ( V_56 , V_62 ) ;
if ( ! ( V_71 & V_61 ) )
break;
F_10 () ;
}
}
static int F_37 ( struct V_69 * V_70 ,
T_1 V_79 , T_1 V_80 )
{
T_1 V_81 ;
F_23 ( ! V_70 -> V_2 -> V_6 ) ;
V_70 -> V_74 -> V_82 = F_38 ( V_80 ) ;
F_39 () ;
* ( V_70 -> V_2 -> V_48 ) = F_40 ( V_79 | 0 | V_70 -> V_83 ) ;
F_41 () ;
F_18 ( V_70 -> V_2 , V_84 , V_79 | V_70 -> V_83 ) ;
while ( 1 ) {
V_81 = F_42 ( V_70 -> V_2 -> V_48 ) ;
if ( V_81 == ~ 0ULL ) {
F_25 ( L_23 ) ;
return - 1 ;
}
if ( ( V_81 & ( V_85 | V_86 | V_87 ) ) ==
( V_79 | ( V_79 >> 16 ) | V_70 -> V_83 ) )
break;
F_43 () ;
}
return 0 ;
}
static int F_44 ( struct V_69 * V_70 )
{
int V_66 = 0 ;
F_45 ( & V_70 -> V_2 -> V_72 ) ;
F_4 ( L_24 , V_88 , V_70 -> V_83 ) ;
if ( ! ( V_66 = F_37 ( V_70 , V_89 , V_90 ) ) )
V_70 -> V_91 = true ;
F_4 ( L_25 , V_88 , V_70 -> V_83 ) ;
F_46 ( & V_70 -> V_2 -> V_72 ) ;
return V_66 ;
}
static int F_47 ( struct V_69 * V_70 )
{
int V_66 = 0 ;
if ( ! ( V_70 -> V_74 -> V_82 & F_38 ( V_90 ) ) )
return V_66 ;
F_45 ( & V_70 -> V_2 -> V_72 ) ;
F_4 ( L_26 , V_88 , V_70 -> V_83 ) ;
V_66 = F_37 ( V_70 , V_92 ,
V_90 | V_93 ) ;
V_70 -> V_74 -> V_82 = 0 ;
F_4 ( L_27 , V_88 , V_70 -> V_83 ) ;
F_46 ( & V_70 -> V_2 -> V_72 ) ;
return V_66 ;
}
static int F_48 ( struct V_69 * V_70 )
{
int V_66 = 0 ;
F_45 ( & V_70 -> V_2 -> V_72 ) ;
F_4 ( L_28 , V_88 , V_70 -> V_83 ) ;
if ( ! ( V_66 = F_37 ( V_70 , V_94 , 0 ) ) )
V_70 -> V_91 = false ;
F_34 ( V_70 ) ;
F_4 ( L_29 , V_88 , V_70 -> V_83 ) ;
F_46 ( & V_70 -> V_2 -> V_72 ) ;
return V_66 ;
}
static void F_49 ( struct V_69 * V_70 )
{
if ( ! V_70 -> V_2 -> V_95 || V_70 -> V_96 ) {
V_70 -> V_97 = V_70 -> V_2 -> V_97 ;
V_70 -> V_98 = V_70 -> V_2 -> V_56 -> V_99 ;
} else {
V_70 -> V_97 = V_70 -> V_2 -> V_97 +
( V_70 -> V_2 -> V_100 + V_70 -> V_2 -> V_95 * V_70 -> V_83 ) ;
V_70 -> V_98 = V_70 -> V_2 -> V_95 ;
}
}
static int F_50 ( struct V_1 * V_2 )
{
int V_66 ;
F_51 ( & V_2 -> V_14 , L_30 ) ;
if ( F_22 ( V_2 ) )
return - V_47 ;
F_18 ( V_2 , V_24 , V_101 ) ;
F_18 ( V_2 , V_102 , 0xFFFFFFFFFFFFFFFFULL ) ;
F_18 ( V_2 , V_103 , V_104 | V_105 ) ;
V_2 -> V_106 = V_107 ;
V_2 -> V_42 = V_2 -> V_108 ;
if ( ( V_66 = F_52 ( V_2 ) ) )
return V_66 ;
if ( ( V_66 = F_53 ( V_2 ) ) )
goto V_109;
if ( ( V_66 = F_54 ( V_2 ) ) )
goto V_110;
return 0 ;
V_110:
F_55 ( V_2 ) ;
V_109:
F_56 ( V_2 ) ;
return V_66 ;
}
static int F_57 ( struct V_69 * V_70 , T_1 V_111 , T_1 V_112 )
{
T_1 V_113 ;
int V_114 , V_4 ;
F_49 ( V_70 ) ;
V_70 -> V_74 -> V_115 = 0 ;
V_70 -> V_74 -> V_77 = F_38 ( F_58 ( V_116 ) ) ;
V_70 -> V_74 -> V_117 = 0 ;
V_70 -> V_74 -> V_118 = F_40 ( F_58 ( V_119 ) ) ;
V_113 = 0 ;
if ( V_70 -> V_96 )
V_113 |= V_120 ;
if ( F_58 ( V_121 ) & V_122 )
V_113 |= V_123 ;
V_113 |= V_124 | V_125 ;
F_59 ( V_113 ) ;
V_113 &= ~ ( V_126 ) ;
if ( ! F_60 ( V_127 , V_128 ) )
V_113 |= V_129 ;
V_70 -> V_74 -> V_75 . V_76 = F_38 ( V_127 -> V_76 ) ;
V_70 -> V_74 -> V_75 . V_130 = 0 ;
V_70 -> V_74 -> V_113 = F_40 ( V_113 ) ;
V_70 -> V_74 -> V_75 . V_131 = 0 ;
V_70 -> V_74 -> V_75 . V_132 = 0 ;
V_70 -> V_74 -> V_75 . V_133 = 0 ;
F_61 ( V_70 , V_111 ) ;
V_70 -> V_74 -> V_75 . V_64 = F_40 ( V_70 -> V_64 ) ;
V_70 -> V_74 -> V_75 . V_65 = F_40 ( V_70 -> V_65 ) ;
for ( V_114 = 0 ; V_114 < V_134 ; V_114 ++ ) {
V_70 -> V_74 -> V_135 [ V_114 ] = F_62 ( V_70 -> V_136 . V_137 [ V_114 ] ) ;
V_70 -> V_74 -> V_138 [ V_114 ] = F_62 ( V_70 -> V_136 . V_139 [ V_114 ] ) ;
}
V_70 -> V_74 -> V_75 . V_112 = F_40 ( V_112 ) ;
V_70 -> V_74 -> V_75 . V_111 = F_40 ( V_111 ) ;
if ( ( V_4 = F_14 ( V_70 -> V_2 ) ) )
return V_4 ;
F_44 ( V_70 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_14 , L_31 ) ;
V_2 -> V_106 = 0 ;
V_2 -> V_42 = 0 ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_13 ( V_2 ) ;
F_12 ( V_2 ) ;
F_15 ( V_2 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_14 , L_32 ) ;
F_18 ( V_2 , V_24 , V_140 ) ;
F_18 ( V_2 , V_141 , 0 ) ;
F_18 ( V_2 , V_54 , 0 ) ;
F_18 ( V_2 , V_102 , 0xFFFFFFFFFFFFFFFFULL ) ;
F_18 ( V_2 , V_142 , F_58 ( V_116 ) ) ;
F_18 ( V_2 , V_143 , 0 ) ;
F_18 ( V_2 , V_144 , F_58 ( V_119 ) ) ;
F_5 ( V_2 , V_145 , 0 ) ;
F_5 ( V_2 , V_146 , 0 ) ;
F_5 ( V_2 , V_147 , 0 ) ;
V_2 -> V_106 = V_148 ;
V_2 -> V_42 = 1 ;
return F_65 ( V_2 ) ;
}
static int F_66 ( struct V_69 * V_70 , T_1 V_111 , T_1 V_112 )
{
struct V_1 * V_2 = V_70 -> V_2 ;
T_1 V_113 ;
int V_66 ;
V_113 = 0 ;
F_59 ( V_113 ) ;
if ( V_70 -> V_96 )
V_113 |= V_120 ;
if ( F_58 ( V_121 ) & V_122 )
V_113 |= V_123 ;
V_113 |= V_124 | V_125 ;
if ( ! F_60 ( V_127 , V_128 ) )
V_113 |= V_129 ;
F_5 ( V_2 , V_149 , ( T_1 ) V_127 -> V_76 << 32 ) ;
F_18 ( V_2 , V_150 , V_113 ) ;
if ( ( V_66 = F_33 ( V_2 , V_70 -> V_64 , V_70 -> V_65 ) ) )
return V_66 ;
F_61 ( V_70 , V_111 ) ;
F_18 ( V_2 , V_151 ,
( ( ( T_1 ) V_70 -> V_136 . V_137 [ 0 ] & 0xffff ) << 48 ) |
( ( ( T_1 ) V_70 -> V_136 . V_137 [ 1 ] & 0xffff ) << 32 ) |
( ( ( T_1 ) V_70 -> V_136 . V_137 [ 2 ] & 0xffff ) << 16 ) |
( ( T_1 ) V_70 -> V_136 . V_137 [ 3 ] & 0xffff ) ) ;
F_18 ( V_2 , V_152 , ( T_1 )
( ( ( T_1 ) V_70 -> V_136 . V_139 [ 0 ] & 0xffff ) << 48 ) |
( ( ( T_1 ) V_70 -> V_136 . V_139 [ 1 ] & 0xffff ) << 32 ) |
( ( ( T_1 ) V_70 -> V_136 . V_139 [ 2 ] & 0xffff ) << 16 ) |
( ( T_1 ) V_70 -> V_136 . V_139 [ 3 ] & 0xffff ) ) ;
F_5 ( V_2 , V_153 , V_112 ) ;
F_49 ( V_70 ) ;
if ( ( V_66 = F_13 ( V_2 ) ) )
return V_66 ;
F_5 ( V_2 , V_154 , V_111 ) ;
return F_11 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_14 , L_33 ) ;
V_2 -> V_106 = 0 ;
V_2 -> V_42 = 0 ;
F_56 ( V_2 ) ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 , int V_155 )
{
if ( V_155 == V_107 )
return F_63 ( V_2 ) ;
if ( V_155 == V_148 )
return F_67 ( V_2 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 )
{
return F_68 ( V_2 , V_2 -> V_106 ) ;
}
int F_70 ( struct V_1 * V_2 , int V_155 )
{
if ( ! V_155 )
return 0 ;
if ( ! ( V_155 & V_2 -> V_156 ) )
return - V_157 ;
if ( V_155 == V_107 )
return F_50 ( V_2 ) ;
if ( V_155 == V_148 )
return F_64 ( V_2 ) ;
return - V_157 ;
}
int F_71 ( struct V_69 * V_70 , bool V_158 , T_1 V_111 , T_1 V_112 )
{
V_70 -> V_158 = V_158 ;
if ( V_70 -> V_2 -> V_106 == V_107 )
return F_57 ( V_70 , V_111 , V_112 ) ;
if ( V_70 -> V_2 -> V_106 == V_148 )
return F_66 ( V_70 , V_111 , V_112 ) ;
return - V_157 ;
}
static inline int F_72 ( struct V_69 * V_70 )
{
F_13 ( V_70 -> V_2 ) ;
F_12 ( V_70 -> V_2 ) ;
F_15 ( V_70 -> V_2 ) ;
return 0 ;
}
static inline int F_73 ( struct V_69 * V_70 )
{
if ( ! V_70 -> V_91 )
return 0 ;
if ( F_47 ( V_70 ) )
return - 1 ;
if ( F_48 ( V_70 ) )
return - 1 ;
return 0 ;
}
int F_74 ( struct V_69 * V_70 )
{
if ( V_70 -> V_2 -> V_106 == V_148 )
return F_72 ( V_70 ) ;
return F_73 ( V_70 ) ;
}
int F_75 ( struct V_69 * V_70 , struct V_159 * V_160 )
{
T_1 V_161 ;
V_160 -> V_25 = F_2 ( V_70 -> V_2 , V_32 ) ;
V_160 -> V_26 = F_2 ( V_70 -> V_2 , V_34 ) ;
V_160 -> V_162 = F_2 ( V_70 -> V_2 , V_163 ) ;
V_161 = F_2 ( V_70 -> V_2 , V_149 ) ;
V_160 -> V_76 = V_161 >> 32 ;
V_160 -> V_130 = V_161 & 0xffffffff ;
V_160 -> V_164 = F_2 ( V_70 -> V_2 , V_165 ) ;
V_160 -> V_166 = F_2 ( V_70 -> V_2 , V_167 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 , T_1 V_166 )
{
T_1 V_25 ;
F_4 ( L_34 , V_166 ) ;
V_25 = F_2 ( V_2 , V_32 ) ;
F_5 ( V_2 , V_32 , V_25 & ~ V_168 ) ;
F_5 ( V_2 , V_167 , V_166 ) ;
}
int F_77 ( struct V_69 * V_70 , T_1 V_169 , T_1 V_170 )
{
if ( V_169 )
F_5 ( V_70 -> V_2 , V_35 , V_169 ) ;
if ( V_170 )
F_76 ( V_70 -> V_2 , V_170 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 )
{
return ( F_16 ( V_2 , V_24 ) == ~ 0ULL ) ;
}
