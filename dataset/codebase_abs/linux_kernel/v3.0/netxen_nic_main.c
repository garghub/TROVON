void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 , V_4 -> V_5 , V_4 -> V_6 ) ;
}
static inline void
F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 , V_4 -> V_7 , V_4 -> V_8 ) ;
}
static inline void F_4 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_2 ( V_2 , V_10 -> V_11 , 0 ) ;
}
static inline void F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_2 ( V_2 , V_10 -> V_11 , 0x1 ) ;
if ( ! F_6 ( V_2 ) )
F_2 ( V_2 , V_2 -> V_12 , 0xfbff ) ;
}
static int
F_7 ( struct V_13 * V_14 , int V_15 )
{
int V_16 = sizeof( struct V_9 ) * V_15 ;
V_14 -> V_17 = F_8 ( V_16 , V_18 ) ;
return V_14 -> V_17 == NULL ;
}
static void
F_9 ( struct V_13 * V_14 )
{
if ( V_14 -> V_17 != NULL )
F_10 ( V_14 -> V_17 ) ;
V_14 -> V_17 = NULL ;
}
static int
F_11 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_21 ;
struct V_9 * V_10 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( F_7 ( V_14 , V_2 -> V_22 ) )
return - V_23 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 ; V_21 ++ ) {
V_10 = & V_14 -> V_17 [ V_21 ] ;
F_12 ( V_20 , & V_10 -> V_24 ,
V_25 , V_26 ) ;
}
return 0 ;
}
static void
F_13 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_9 * V_10 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 ; V_21 ++ ) {
V_10 = & V_14 -> V_17 [ V_21 ] ;
F_14 ( & V_10 -> V_24 ) ;
}
F_9 ( & V_2 -> V_14 ) ;
}
static void
F_15 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_9 * V_10 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 ; V_21 ++ ) {
V_10 = & V_14 -> V_17 [ V_21 ] ;
F_16 ( & V_10 -> V_24 ) ;
F_5 ( V_10 ) ;
}
}
static void
F_17 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_9 * V_10 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 ; V_21 ++ ) {
V_10 = & V_14 -> V_17 [ V_21 ] ;
F_4 ( V_10 ) ;
F_18 ( & V_10 -> V_24 ) ;
F_19 ( & V_10 -> V_24 ) ;
}
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
T_1 V_29 , V_30 ;
V_2 -> V_31 = 0 ;
V_29 = F_21 ( 32 ) ;
V_30 = F_21 ( 32 ) ;
if ( F_22 ( V_2 -> V_32 . V_33 ) ) {
#ifndef F_23
V_29 = F_21 ( 35 ) ;
#endif
} else {
V_29 = F_21 ( 39 ) ;
V_30 = V_29 ;
}
if ( F_24 ( V_28 , V_29 ) == 0 &&
F_25 ( V_28 , V_30 ) == 0 ) {
V_2 -> V_31 = 1 ;
return 0 ;
}
return - V_34 ;
}
static int
F_26 ( struct V_1 * V_2 )
{
int V_35 , V_36 , V_37 ;
T_1 V_29 , V_38 , V_39 ;
struct V_27 * V_28 = V_2 -> V_28 ;
V_35 = 0 ;
V_36 = F_27 ( V_2 , V_40 ) ;
if ( V_36 > 32 )
return 0 ;
if ( F_28 ( V_2 -> V_32 . V_33 ) && ( V_36 > 9 ) )
V_35 = 1 ;
else if ( ( V_2 -> V_32 . V_33 == V_41 ) && ( V_36 <= 4 ) )
V_35 = 1 ;
if ( V_35 ) {
V_38 = V_28 -> V_42 ;
V_39 = V_28 -> V_43 . V_44 ;
V_29 = F_21 ( 32 + V_36 ) ;
V_37 = F_24 ( V_28 , V_29 ) ;
if ( V_37 )
goto V_45;
if ( F_28 ( V_2 -> V_32 . V_33 ) ) {
V_37 = F_25 ( V_28 , V_29 ) ;
if ( V_37 )
goto V_45;
}
F_29 ( & V_28 -> V_43 , L_1 , 32 + V_36 ) ;
}
return 0 ;
V_45:
F_24 ( V_28 , V_38 ) ;
F_25 ( V_28 , V_39 ) ;
return V_37 ;
}
static int
F_30 ( struct V_1 * V_2 , int V_46 )
{
T_2 V_47 , V_48 ;
if ( V_46 == 0x55555555 ) {
F_31 ( V_2 , F_32 ( 0x1fc ) , V_49 ) ;
if ( ! F_22 ( V_2 -> V_32 . V_33 ) )
return 0 ;
V_46 = F_27 ( V_2 , F_33 ( 0x4 ) ) ;
if ( ! ( V_46 & 0x4 ) ) {
V_46 |= 0x4 ;
F_31 ( V_2 , F_33 ( 0x4 ) , V_46 ) ;
F_27 ( V_2 , F_33 ( 0x4 ) ) ;
}
V_46 = F_27 ( V_2 , V_50 ) ;
if ( V_46 != 0x80000f ) {
F_31 ( V_2 , F_32 ( 0x1fc ) , 0 ) ;
return - V_34 ;
}
V_47 = F_27 ( V_2 , V_51 ) ;
F_31 ( V_2 , V_51 , V_47 | 0x1 ) ;
V_48 = 0 ;
do {
F_34 ( 1 ) ;
V_47 = F_27 ( V_2 , F_32 ( 0x1fc ) ) ;
if ( ++ V_48 > 5000 )
return - V_34 ;
} while ( V_47 == V_49 );
}
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_2 V_47 , V_52 ;
V_47 = V_2 -> V_32 . V_53 ;
if ( ( V_47 == V_54 ) ||
( V_47 == V_55 ) ) {
if ( V_56 == V_57 ) {
V_52 = V_57 ;
F_31 ( V_2 , V_58 , V_52 ) ;
} else if ( V_56 == V_59 ) {
V_52 = V_59 ;
F_31 ( V_2 , V_58 , V_52 ) ;
} else if ( V_56 == V_60 ) {
V_52 = V_60 ;
F_31 ( V_2 , V_58 , V_52 ) ;
} else if ( V_56 == V_61 ) {
V_52 = V_61 ;
F_31 ( V_2 , V_58 , V_52 ) ;
} else {
V_52 = V_62 ;
F_31 ( V_2 , V_58 , V_52 ) ;
}
if ( ( V_63 != V_57 ) &&
( V_63 != V_59 ) &&
( V_63 != V_60 ) &&
( V_63 != V_61 ) ) {
V_63 = V_62 ;
}
F_31 ( V_2 , V_64 , V_63 ) ;
}
}
static void F_36 ( struct V_27 * V_28 , int V_65 )
{
T_2 V_66 ;
int V_67 ;
V_67 = F_37 ( V_28 , V_68 ) ;
if ( V_67 ) {
F_38 ( V_28 , V_67 , & V_66 ) ;
if ( V_65 )
V_66 |= V_69 ;
else
V_66 = 0 ;
F_39 ( V_28 , V_67 , V_66 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , int V_15 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_15 ; V_70 ++ )
V_2 -> V_71 [ V_70 ] . V_72 = V_70 ;
}
static int
F_41 ( struct V_1 * V_2 )
{
int V_70 ;
unsigned char * V_73 ;
T_3 V_74 ;
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_27 * V_28 = V_2 -> V_28 ;
if ( F_28 ( V_2 -> V_32 . V_33 ) ) {
if ( F_42 ( V_2 , & V_74 ) != 0 )
return - V_34 ;
} else {
if ( F_43 ( V_2 , & V_74 ) != 0 )
return - V_34 ;
}
V_73 = ( unsigned char * ) & V_74 ;
for ( V_70 = 0 ; V_70 < 6 ; V_70 ++ )
V_20 -> V_75 [ V_70 ] = * ( V_73 + 5 - V_70 ) ;
memcpy ( V_20 -> V_76 , V_20 -> V_75 , V_20 -> V_77 ) ;
memcpy ( V_2 -> V_74 , V_20 -> V_75 , V_20 -> V_77 ) ;
if ( ! F_44 ( V_20 -> V_76 ) )
F_45 ( & V_28 -> V_43 , L_2 , V_20 -> V_75 ) ;
return 0 ;
}
static int F_46 ( struct V_19 * V_20 , void * V_73 )
{
struct V_1 * V_2 = F_47 ( V_20 ) ;
struct V_78 * V_79 = V_73 ;
if ( ! F_44 ( V_79 -> V_80 ) )
return - V_81 ;
if ( F_48 ( V_20 ) ) {
F_49 ( V_20 ) ;
F_17 ( V_2 ) ;
}
memcpy ( V_2 -> V_74 , V_79 -> V_80 , V_20 -> V_77 ) ;
memcpy ( V_20 -> V_75 , V_79 -> V_80 , V_20 -> V_77 ) ;
V_2 -> V_82 ( V_2 , V_79 -> V_80 ) ;
if ( F_48 ( V_20 ) ) {
F_50 ( V_20 ) ;
F_15 ( V_2 ) ;
}
return 0 ;
}
static void F_51 ( struct V_19 * V_43 )
{
struct V_1 * V_2 = F_47 ( V_43 ) ;
V_2 -> V_83 ( V_43 ) ;
}
static T_2 F_52 ( struct V_19 * V_43 , T_2 V_84 )
{
if ( ! ( V_84 & V_85 ) ) {
F_53 ( V_43 , L_3 ) ;
V_84 &= ~ V_86 ;
}
return V_84 ;
}
static int F_54 ( struct V_19 * V_43 , T_2 V_84 )
{
struct V_1 * V_2 = F_47 ( V_43 ) ;
int V_87 ;
if ( ! ( ( V_43 -> V_84 ^ V_84 ) & V_86 ) )
return 0 ;
V_87 = ( V_84 & V_86 ) ? V_88
: V_89 ;
if ( F_55 ( V_2 , V_87 ) )
return - V_34 ;
if ( ! ( V_84 & V_86 ) && F_56 ( V_2 ) )
return - V_34 ;
return 0 ;
}
static void
F_57 ( struct V_1 * V_2 )
{
struct V_90 * V_91 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_37 , V_92 ;
if ( V_2 -> V_93 ) {
V_92 = ( F_58 () >= V_94 ) ?
V_94 : 2 ;
} else
V_92 = 1 ;
V_2 -> V_22 = 1 ;
V_2 -> V_95 &= ~ ( V_96 | V_97 ) ;
if ( V_2 -> V_32 . V_33 >= V_98 )
V_91 = & V_99 [ V_2 -> V_32 . V_100 ] ;
else
V_91 = & V_99 [ 0 ] ;
V_2 -> V_101 = V_91 -> V_101 ;
V_2 -> V_102 = F_59 ( V_2 ,
V_91 -> V_102 ) ;
V_2 -> V_12 = F_59 ( V_2 ,
V_91 -> V_12 ) ;
V_2 -> V_103 = F_59 ( V_2 ,
V_91 -> V_103 ) ;
V_2 -> V_104 = F_59 ( V_2 , V_105 ) ;
if ( V_2 -> V_32 . V_33 >= V_106 )
V_2 -> V_107 = F_59 ( V_2 ,
V_108 ) ;
else
V_2 -> V_107 = F_59 ( V_2 ,
V_109 ) ;
F_36 ( V_28 , 0 ) ;
if ( V_2 -> V_110 ) {
F_40 ( V_2 , V_92 ) ;
V_37 = F_60 ( V_28 , V_2 -> V_71 , V_92 ) ;
if ( V_37 == 0 ) {
V_2 -> V_95 |= V_97 ;
F_36 ( V_28 , 1 ) ;
if ( V_2 -> V_93 )
V_2 -> V_22 = V_92 ;
F_29 ( & V_28 -> V_43 , L_4 ) ;
return;
}
if ( V_37 > 0 )
F_61 ( V_28 ) ;
}
if ( V_111 && ! F_62 ( V_28 ) ) {
V_2 -> V_95 |= V_96 ;
V_2 -> V_102 = F_59 ( V_2 ,
V_112 [ V_2 -> V_32 . V_100 ] ) ;
F_29 ( & V_28 -> V_43 , L_5 ) ;
V_2 -> V_71 [ 0 ] . V_113 = V_28 -> V_114 ;
return;
}
F_29 ( & V_28 -> V_43 , L_6 ) ;
V_2 -> V_71 [ 0 ] . V_113 = V_28 -> V_114 ;
}
static void
F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_95 & V_97 )
F_61 ( V_2 -> V_28 ) ;
if ( V_2 -> V_95 & V_96 )
F_64 ( V_2 -> V_28 ) ;
}
static void
F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 . V_115 != NULL )
F_66 ( V_2 -> V_32 . V_115 ) ;
if ( V_2 -> V_32 . V_116 != NULL )
F_66 ( V_2 -> V_32 . V_116 ) ;
if ( V_2 -> V_32 . V_117 != NULL )
F_66 ( V_2 -> V_32 . V_117 ) ;
if ( V_2 -> V_32 . V_118 != NULL )
F_66 ( V_2 -> V_32 . V_118 ) ;
}
static int
F_67 ( struct V_1 * V_2 )
{
void T_4 * V_119 = NULL ;
T_5 V_120 , V_115 ;
unsigned long V_121 , V_122 = 0 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_100 = V_2 -> V_32 . V_100 ;
struct V_123 * V_32 = & V_2 -> V_32 ;
int V_37 = 0 ;
V_2 -> V_32 . V_124 = - 1 ;
V_2 -> V_32 . V_125 = - 1 ;
V_120 = F_68 ( V_28 , 0 ) ;
V_121 = F_69 ( V_28 , 0 ) ;
if ( V_121 == V_126 ) {
V_32 -> V_116 = F_70 ( V_120 , V_127 ) ;
V_32 -> V_117 = F_70 ( V_120 + V_128 ,
V_129 ) ;
V_32 -> V_118 = F_70 ( V_120 + V_130 ,
V_131 ) ;
if ( V_32 -> V_116 == NULL || V_32 -> V_117 == NULL ||
V_32 -> V_118 == NULL ) {
F_71 ( & V_28 -> V_43 , L_7 ) ;
V_37 = - V_34 ;
goto V_45;
}
V_32 -> V_132 = V_127 ;
} else if ( V_121 == V_133 ) {
V_32 -> V_117 = F_70 ( V_120 , V_129 ) ;
V_32 -> V_118 = F_70 ( V_120 + V_130 -
V_128 , V_131 ) ;
if ( V_32 -> V_117 == NULL || V_32 -> V_118 == NULL ) {
F_71 ( & V_28 -> V_43 , L_7 ) ;
V_37 = - V_34 ;
goto V_45;
}
} else if ( V_121 == V_134 ) {
V_32 -> V_116 = F_72 ( V_28 , 0 ) ;
if ( V_32 -> V_116 == NULL ) {
F_71 ( & V_28 -> V_43 , L_7 ) ;
return - V_34 ;
}
V_32 -> V_132 = V_121 ;
} else {
return - V_34 ;
}
F_73 ( V_2 ) ;
F_29 ( & V_28 -> V_43 , L_8 , ( int ) ( V_121 >> 20 ) ) ;
if ( F_74 ( V_2 -> V_32 . V_33 ) ) {
V_2 -> V_32 . V_135 = F_59 ( V_2 ,
F_75 ( F_76 ( V_100 ) ) ) ;
} else if ( F_28 ( V_2 -> V_32 . V_33 ) ) {
V_2 -> V_32 . V_135 = F_59 ( V_2 ,
F_75 ( F_77 ( V_100 ) ) ) ;
}
if ( F_28 ( V_2 -> V_32 . V_33 ) )
goto V_136;
V_115 = F_68 ( V_28 , 4 ) ;
V_122 = F_69 ( V_28 , 4 ) ;
if ( V_122 == 0 ) {
F_78 ( V_137 L_9 ,
V_138 ) ;
V_37 = - V_34 ;
goto V_45;
}
V_119 = F_70 ( V_115 , V_139 ) ;
if ( ! V_119 ) {
F_78 ( V_137 L_10 ,
V_138 ) ;
V_37 = - V_34 ;
goto V_45;
}
V_136:
V_2 -> V_32 . V_115 = V_119 ;
V_2 -> V_32 . V_122 = V_122 ;
return 0 ;
V_45:
F_65 ( V_2 ) ;
return V_37 ;
}
static void
F_79 ( struct V_1 * V_2 )
{
T_2 V_140 , V_141 , V_142 ;
char V_143 [ V_144 ] ;
char V_145 [ 32 ] ;
int V_70 , V_146 , V_47 ;
int * V_147 ;
struct V_27 * V_28 = V_2 -> V_28 ;
V_2 -> V_148 = 0 ;
V_147 = ( int * ) & V_145 ;
V_146 = V_149 ;
for ( V_70 = 0 ; V_70 < 8 ; V_70 ++ ) {
if ( F_80 ( V_2 , V_146 , & V_47 ) == - 1 ) {
F_71 ( & V_28 -> V_43 , L_11 ) ;
V_2 -> V_148 = 1 ;
return;
}
V_147 [ V_70 ] = F_81 ( V_47 ) ;
V_146 += sizeof( T_2 ) ;
}
V_140 = F_27 ( V_2 , V_150 ) ;
V_141 = F_27 ( V_2 , V_151 ) ;
V_142 = F_27 ( V_2 , V_152 ) ;
V_2 -> V_153 = F_82 ( V_140 , V_141 , V_142 ) ;
if ( V_2 -> V_154 == 0 ) {
F_83 ( V_2 -> V_32 . V_53 , V_143 ) ;
F_84 ( L_12 ,
F_85 ( V_155 ) ,
V_143 , V_145 , V_2 -> V_32 . V_33 ) ;
}
if ( V_2 -> V_153 < F_82 ( 3 , 4 , 216 ) ) {
V_2 -> V_148 = 1 ;
F_45 ( & V_28 -> V_43 , L_13 ,
V_140 , V_141 , V_142 ) ;
return;
}
if ( F_28 ( V_2 -> V_32 . V_33 ) ) {
V_70 = F_27 ( V_2 , V_156 ) ;
V_2 -> V_32 . V_157 = ( V_70 & 0x8000 ) ? 1 : 0 ;
}
F_29 ( & V_28 -> V_43 , L_14 ,
V_140 , V_141 , V_142 ,
V_2 -> V_32 . V_157 ? L_15 : L_16 ) ;
if ( V_2 -> V_153 >= F_82 ( 4 , 0 , 222 ) )
V_2 -> V_158 = F_27 ( V_2 , V_159 ) ;
if ( V_2 -> V_32 . V_160 == V_161 ) {
V_2 -> V_162 = V_163 ;
V_2 -> V_164 = V_165 ;
} else if ( V_2 -> V_32 . V_160 == V_166 ) {
V_2 -> V_162 = V_167 ;
V_2 -> V_164 = V_168 ;
}
V_2 -> V_110 = 0 ;
if ( F_28 ( V_2 -> V_32 . V_33 ) ) {
V_2 -> V_110 = ! ! V_169 ;
V_2 -> V_93 = ! ! V_169 ;
} else {
T_2 V_170 = 0 ;
F_80 ( V_2 ,
V_171 , ( int * ) & V_170 ) ;
V_170 = F_86 ( V_170 ) ;
if ( V_170 >= F_82 ( 3 , 4 , 336 ) ) {
switch ( V_2 -> V_32 . V_53 ) {
case V_172 :
case V_173 :
V_2 -> V_110 = ! ! V_169 ;
V_2 -> V_93 = ! ! V_169 ;
break;
default:
break;
}
}
}
V_2 -> V_174 = V_175 ;
if ( F_22 ( V_2 -> V_32 . V_33 ) ) {
V_2 -> V_176 = V_177 ;
V_2 -> V_178 = 3 ;
} else {
V_2 -> V_176 = 0 ;
V_2 -> V_178 = 2 ;
}
}
static int
F_87 ( struct V_1 * V_2 )
{
int V_47 , V_37 , V_46 ;
struct V_27 * V_28 = V_2 -> V_28 ;
V_37 = F_20 ( V_2 ) ;
if ( V_37 )
return V_37 ;
if ( ! F_88 ( V_2 ) )
goto V_179;
V_46 = F_27 ( V_2 , F_32 ( 0x1fc ) ) ;
V_37 = F_30 ( V_2 , V_46 ) ;
if ( V_37 ) {
F_71 ( & V_28 -> V_43 , L_17 ) ;
return V_37 ;
}
F_89 ( V_2 ) ;
V_37 = F_90 ( V_2 ) ;
if ( V_37 < 0 )
goto V_45;
if ( V_37 == 0 )
goto V_179;
if ( V_46 != 0x55555555 ) {
F_31 ( V_2 , V_180 , 0 ) ;
F_91 ( V_2 ) ;
F_34 ( 1 ) ;
}
F_31 ( V_2 , V_40 , 0x55555555 ) ;
F_31 ( V_2 , V_181 , 0 ) ;
F_31 ( V_2 , V_182 , 0 ) ;
if ( F_28 ( V_2 -> V_32 . V_33 ) )
F_35 ( V_2 ) ;
V_37 = F_92 ( V_2 ) ;
if ( V_37 )
goto V_45;
F_93 ( V_2 ) ;
if ( F_22 ( V_2 -> V_32 . V_33 ) ) {
V_47 = 0x7654 ;
if ( V_2 -> V_32 . V_160 == V_161 )
V_47 |= 0x0f000000 ;
F_31 ( V_2 , V_183 , V_47 ) ;
}
V_37 = F_94 ( V_2 ) ;
if ( V_37 )
goto V_45;
V_47 = ( V_184 << 16 )
| ( ( V_185 << 8 ) )
| ( V_186 ) ;
F_31 ( V_2 , V_187 , V_47 ) ;
V_179:
V_37 = F_95 ( V_2 , V_188 ) ;
if ( V_37 ) {
F_96 ( V_2 ) ;
goto V_45;
}
F_31 ( V_2 , V_189 , V_190 ) ;
F_26 ( V_2 ) ;
F_79 ( V_2 ) ;
V_2 -> V_191 = 0 ;
V_45:
F_93 ( V_2 ) ;
return V_37 ;
}
static int
F_97 ( struct V_1 * V_2 )
{
T_6 V_192 ;
struct V_9 * V_10 ;
int V_37 , V_21 ;
unsigned long V_95 = 0 ;
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_95 & V_97 )
V_192 = V_193 ;
else if ( V_2 -> V_95 & V_96 )
V_192 = V_194 ;
else {
V_95 |= V_195 ;
V_192 = V_196 ;
}
V_2 -> V_114 = V_20 -> V_114 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 ; V_21 ++ ) {
V_10 = & V_14 -> V_17 [ V_21 ] ;
sprintf ( V_10 -> V_197 , L_18 , V_20 -> V_197 , V_21 ) ;
V_37 = F_98 ( V_10 -> V_114 , V_192 ,
V_95 , V_10 -> V_197 , V_10 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static void
F_99 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_9 * V_10 ;
struct V_13 * V_14 = & V_2 -> V_14 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 ; V_21 ++ ) {
V_10 = & V_14 -> V_17 [ V_21 ] ;
F_100 ( V_10 -> V_114 , V_10 ) ;
}
}
static void
F_101 ( struct V_1 * V_2 )
{
V_2 -> V_198 . V_95 = V_199 ;
V_2 -> V_198 . V_200 . V_52 . V_201 =
V_202 ;
V_2 -> V_198 . V_200 . V_52 . V_203 =
V_204 ;
V_2 -> V_198 . V_200 . V_52 . V_205 =
V_206 ;
V_2 -> V_198 . V_200 . V_52 . V_207 =
V_208 ;
}
static int
F_102 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_37 ;
if ( V_2 -> V_209 != V_210 )
return - V_34 ;
V_37 = V_2 -> V_211 ( V_2 , V_2 -> V_212 ) ;
if ( V_37 ) {
F_78 ( V_137 L_19 ,
V_138 , V_2 -> V_154 ) ;
return V_37 ;
}
if ( F_22 ( V_2 -> V_32 . V_33 ) )
V_2 -> V_82 ( V_2 , V_2 -> V_74 ) ;
V_2 -> V_83 ( V_20 ) ;
V_2 -> V_213 ( V_2 , V_20 -> V_214 ) ;
V_2 -> V_32 . V_215 = 0 ;
if ( V_2 -> V_22 > 1 )
F_103 ( V_2 , 1 ) ;
if ( F_28 ( V_2 -> V_32 . V_33 ) )
F_104 ( V_2 ) ;
if ( V_20 -> V_84 & V_86 )
F_55 ( V_2 , V_88 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_158 & V_216 )
F_105 ( V_2 , 1 ) ;
else
F_106 ( V_2 ) ;
F_107 ( V_217 , & V_2 -> V_218 ) ;
return 0 ;
}
static inline int
F_108 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_37 = 0 ;
F_109 () ;
if ( F_48 ( V_20 ) )
V_37 = F_102 ( V_2 , V_20 ) ;
F_110 () ;
return V_37 ;
}
static void
F_111 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
if ( V_2 -> V_209 != V_210 )
return;
if ( ! F_112 ( V_217 , & V_2 -> V_218 ) )
return;
F_113 () ;
F_114 ( & V_2 -> V_219 ) ;
F_115 ( V_20 ) ;
F_116 ( V_20 ) ;
if ( V_2 -> V_158 & V_216 )
F_105 ( V_2 , 0 ) ;
if ( V_2 -> V_220 )
V_2 -> V_220 ( V_2 ) ;
if ( F_28 ( V_2 -> V_32 . V_33 ) )
F_117 ( V_2 ) ;
V_2 -> V_221 ( V_2 , V_222 ) ;
F_17 ( V_2 ) ;
F_118 ( V_2 ) ;
F_119 ( & V_2 -> V_219 ) ;
}
static inline void
F_120 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
F_109 () ;
if ( F_48 ( V_20 ) )
F_111 ( V_2 , V_20 ) ;
F_110 () ;
}
static int
F_121 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_37 , V_21 ;
struct V_223 * V_224 ;
struct V_3 * V_4 ;
if ( V_2 -> V_209 == V_210 )
return 0 ;
V_37 = F_122 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_11 ( V_2 , V_20 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_123 ( V_2 ) ;
if ( V_37 ) {
F_78 ( V_137 L_20 ,
V_20 -> V_197 ) ;
return V_37 ;
}
V_37 = F_124 ( V_2 ) ;
if ( V_37 ) {
F_78 ( V_137 L_21 ,
V_20 -> V_197 ) ;
goto V_225;
}
if ( F_22 ( V_2 -> V_32 . V_33 ) ) {
V_4 = V_2 -> V_4 ;
V_4 -> V_5 = F_59 ( V_2 ,
V_5 [ V_2 -> V_154 ] ) ;
V_4 -> V_7 = F_59 ( V_2 ,
V_7 [ V_2 -> V_154 ] ) ;
V_4 -> V_6 = 0 ;
V_4 -> V_8 = 0 ;
F_1 ( V_2 , V_4 ) ;
F_3 ( V_2 , V_4 ) ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_178 ; V_21 ++ ) {
V_224 = & V_2 -> V_14 . V_226 [ V_21 ] ;
F_125 ( V_2 , V_21 , V_224 ) ;
}
V_37 = F_97 ( V_2 ) ;
if ( V_37 ) {
F_71 ( & V_28 -> V_43 , L_22 ,
V_20 -> V_197 ) ;
goto V_227;
}
if ( F_28 ( V_2 -> V_32 . V_33 ) )
F_101 ( V_2 ) ;
F_126 ( V_2 ) ;
V_2 -> V_209 = V_210 ;
return 0 ;
V_227:
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
V_225:
F_129 ( V_2 ) ;
return V_37 ;
}
static void
F_130 ( struct V_1 * V_2 )
{
if ( V_2 -> V_209 != V_210 )
return;
F_131 ( V_2 ) ;
F_128 ( V_2 ) ;
F_127 ( V_2 ) ;
F_99 ( V_2 ) ;
F_13 ( V_2 ) ;
F_129 ( V_2 ) ;
V_2 -> V_209 = 0 ;
}
int
F_132 ( struct V_1 * V_2 )
{
int V_37 = 0 ;
struct V_19 * V_20 = V_2 -> V_20 ;
if ( F_133 ( V_228 , & V_2 -> V_218 ) )
return - V_229 ;
if ( V_2 -> V_209 == V_210 ) {
F_49 ( V_20 ) ;
if ( F_48 ( V_20 ) )
F_111 ( V_2 , V_20 ) ;
F_130 ( V_2 ) ;
if ( F_48 ( V_20 ) ) {
V_37 = F_121 ( V_2 ) ;
if ( ! V_37 )
V_37 = F_102 ( V_2 , V_20 ) ;
if ( V_37 )
goto V_230;
}
F_50 ( V_20 ) ;
}
V_230:
F_134 ( V_228 , & V_2 -> V_218 ) ;
return V_37 ;
}
static int
F_135 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_37 = 0 ;
struct V_27 * V_28 = V_2 -> V_28 ;
V_2 -> V_231 = 0 ;
if ( F_28 ( V_2 -> V_32 . V_33 ) )
V_2 -> V_232 = 38 ;
else
V_2 -> V_232 = 16 ;
V_20 -> V_233 = & V_234 ;
V_20 -> V_235 = 5 * V_236 ;
F_136 ( V_20 , V_20 -> V_214 ) ;
F_137 ( V_20 , & V_237 ) ;
V_20 -> V_238 = V_239 | V_240 | V_241 |
V_85 ;
if ( F_28 ( V_2 -> V_32 . V_33 ) )
V_20 -> V_238 |= V_242 | V_243 ;
V_20 -> V_244 |= V_20 -> V_238 ;
if ( V_2 -> V_31 ) {
V_20 -> V_84 |= V_245 ;
V_20 -> V_244 |= V_245 ;
}
if ( V_2 -> V_158 & V_246 )
V_20 -> V_238 |= V_247 ;
if ( V_2 -> V_158 & V_248 )
V_20 -> V_238 |= V_86 ;
V_20 -> V_84 |= V_20 -> V_238 ;
V_20 -> V_114 = V_2 -> V_71 [ 0 ] . V_113 ;
F_138 ( & V_2 -> V_249 , V_250 ) ;
if ( F_41 ( V_2 ) )
F_45 ( & V_28 -> V_43 , L_23 ) ;
F_115 ( V_20 ) ;
V_37 = F_139 ( V_20 ) ;
if ( V_37 ) {
F_71 ( & V_28 -> V_43 , L_24 ) ;
return V_37 ;
}
return 0 ;
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_27 * V_251 = V_28 -> V_252 -> V_253 ;
T_2 V_254 ;
if ( V_2 -> V_32 . V_53 != V_255 &&
V_2 -> V_32 . V_53 != V_256 )
return;
if ( V_251 -> V_257 != V_258 )
return;
V_254 = F_141 ( V_251 , V_259 ) ;
if ( ! V_254 )
return;
F_39 ( V_251 , V_254 + V_260 , 0xffff ) ;
}
static int T_7
F_142 ( struct V_27 * V_28 , const struct V_261 * V_262 )
{
struct V_19 * V_20 = NULL ;
struct V_1 * V_2 = NULL ;
int V_70 = 0 , V_37 ;
int V_263 = F_143 ( V_28 -> V_264 ) ;
T_8 V_33 ;
T_2 V_47 ;
if ( V_28 -> V_265 >= V_266 && V_28 -> V_265 <= V_106 ) {
F_144 ( L_25
L_26 ,
F_85 ( V_155 ) , V_266 , V_106 ) ;
return - V_267 ;
}
if ( ( V_37 = F_145 ( V_28 ) ) )
return V_37 ;
if ( ! ( F_146 ( V_28 , 0 ) & V_268 ) ) {
V_37 = - V_267 ;
goto V_269;
}
if ( ( V_37 = F_147 ( V_28 , V_138 ) ) )
goto V_269;
if ( F_28 ( V_28 -> V_265 ) )
F_148 ( V_28 ) ;
F_149 ( V_28 ) ;
V_20 = F_150 ( sizeof( struct V_1 ) ) ;
if( ! V_20 ) {
F_71 ( & V_28 -> V_43 , L_27 ) ;
V_37 = - V_23 ;
goto V_270;
}
F_151 ( V_20 , & V_28 -> V_43 ) ;
V_2 = F_47 ( V_20 ) ;
V_2 -> V_20 = V_20 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_32 . V_100 = V_263 ;
V_33 = V_28 -> V_265 ;
V_2 -> V_32 . V_33 = V_33 ;
F_152 ( & V_2 -> V_32 . V_271 ) ;
F_153 ( & V_2 -> V_32 . V_272 ) ;
F_153 ( & V_2 -> V_219 ) ;
F_154 ( & V_2 -> V_273 ) ;
V_37 = F_67 ( V_2 ) ;
if ( V_37 )
goto V_274;
V_2 -> V_154 = V_263 ;
V_37 = F_155 ( V_2 ) ;
if ( V_37 ) {
F_71 ( & V_28 -> V_43 , L_28 ) ;
goto V_275;
}
#ifdef F_156
F_140 ( V_2 ) ;
#endif
switch ( V_2 -> V_32 . V_53 ) {
case V_276 :
case V_277 :
if ( V_263 >= 2 )
V_2 -> V_154 = V_263 - 2 ;
break;
default:
break;
}
if ( V_2 -> V_154 == 0 ) {
V_47 = F_27 ( V_2 , V_278 ) ;
if ( V_47 != 0xffffffff && V_47 != 0 ) {
F_31 ( V_2 , V_278 , 0 ) ;
V_2 -> V_191 = 1 ;
}
}
V_37 = F_87 ( V_2 ) ;
if ( V_37 )
goto V_279;
V_2 -> V_212 = V_2 -> V_154 ;
if ( F_22 ( V_2 -> V_32 . V_33 ) ) {
V_70 = F_27 ( V_2 , F_157 ( V_2 -> V_154 ) ) ;
if ( V_70 != 0x55555555 )
V_2 -> V_212 = V_70 ;
}
F_158 ( V_2 ) ;
F_57 ( V_2 ) ;
V_37 = F_135 ( V_2 , V_20 ) ;
if ( V_37 )
goto V_280;
F_159 ( V_28 , V_2 ) ;
F_160 ( V_2 , V_281 , V_282 ) ;
switch ( V_2 -> V_32 . V_160 ) {
case V_166 :
F_29 ( & V_2 -> V_28 -> V_43 , L_29 ,
V_2 -> V_20 -> V_197 ) ;
break;
case V_161 :
F_29 ( & V_2 -> V_28 -> V_43 , L_30 ,
V_2 -> V_20 -> V_197 ) ;
break;
}
F_161 ( V_2 ) ;
return 0 ;
V_280:
F_63 ( V_2 ) ;
F_96 ( V_2 ) ;
V_279:
F_162 ( V_2 ) ;
V_275:
F_65 ( V_2 ) ;
V_274:
F_163 ( V_20 ) ;
V_270:
F_164 ( V_28 ) ;
V_269:
F_159 ( V_28 , NULL ) ;
F_165 ( V_28 ) ;
return V_37 ;
}
static void T_9 F_166 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
V_2 = F_167 ( V_28 ) ;
if ( V_2 == NULL )
return;
V_20 = V_2 -> V_20 ;
F_168 ( V_2 ) ;
F_169 ( V_20 ) ;
F_170 ( & V_2 -> V_249 ) ;
F_130 ( V_2 ) ;
F_162 ( V_2 ) ;
if ( V_2 -> V_154 == 0 )
F_96 ( V_2 ) ;
F_134 ( V_228 , & V_2 -> V_218 ) ;
F_63 ( V_2 ) ;
F_171 ( V_2 ) ;
F_65 ( V_2 ) ;
F_93 ( V_2 ) ;
if ( F_28 ( V_28 -> V_265 ) )
F_172 ( V_28 ) ;
F_164 ( V_28 ) ;
F_165 ( V_28 ) ;
F_159 ( V_28 , NULL ) ;
F_163 ( V_20 ) ;
}
static void F_173 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
F_49 ( V_20 ) ;
F_168 ( V_2 ) ;
if ( F_48 ( V_20 ) )
F_120 ( V_2 , V_20 ) ;
F_170 ( & V_2 -> V_249 ) ;
F_130 ( V_2 ) ;
if ( V_2 -> V_154 == 0 )
F_96 ( V_2 ) ;
F_162 ( V_2 ) ;
F_134 ( V_228 , & V_2 -> V_218 ) ;
}
static int F_174 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_167 ( V_28 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
int V_37 ;
V_37 = F_145 ( V_28 ) ;
if ( V_37 )
return V_37 ;
F_175 ( V_28 , V_283 ) ;
F_149 ( V_28 ) ;
F_176 ( V_28 ) ;
V_2 -> V_32 . V_124 = - 1 ;
V_2 -> V_32 . V_125 = - 1 ;
V_37 = F_87 ( V_2 ) ;
if ( V_37 ) {
F_71 ( & V_28 -> V_43 , L_31 ) ;
return V_37 ;
}
if ( F_48 ( V_20 ) ) {
V_37 = F_121 ( V_2 ) ;
if ( V_37 )
goto V_45;
V_37 = F_108 ( V_2 , V_20 ) ;
if ( V_37 )
goto V_284;
F_177 ( V_20 , V_285 ) ;
}
F_50 ( V_20 ) ;
F_160 ( V_2 , V_281 , V_282 ) ;
return 0 ;
V_284:
F_130 ( V_2 ) ;
V_45:
F_162 ( V_2 ) ;
return V_37 ;
}
static T_10 F_178 ( struct V_27 * V_28 ,
T_11 V_218 )
{
struct V_1 * V_2 = F_167 ( V_28 ) ;
if ( V_218 == V_286 )
return V_287 ;
if ( F_179 ( V_2 ) )
return V_288 ;
F_173 ( V_2 ) ;
F_165 ( V_28 ) ;
return V_289 ;
}
static T_10 F_180 ( struct V_27 * V_28 )
{
int V_37 = 0 ;
V_37 = F_174 ( V_28 ) ;
return V_37 ? V_287 : V_288 ;
}
static void F_181 ( struct V_27 * V_28 )
{
F_182 ( V_28 ) ;
}
static void F_183 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_167 ( V_28 ) ;
F_173 ( V_2 ) ;
if ( F_184 ( V_28 ) )
return;
if ( F_185 ( V_2 ) ) {
F_186 ( V_28 , V_290 , 1 ) ;
F_186 ( V_28 , V_291 , 1 ) ;
}
F_165 ( V_28 ) ;
}
static int
F_187 ( struct V_27 * V_28 , T_12 V_218 )
{
struct V_1 * V_2 = F_167 ( V_28 ) ;
int V_292 ;
F_173 ( V_2 ) ;
V_292 = F_184 ( V_28 ) ;
if ( V_292 )
return V_292 ;
if ( F_185 ( V_2 ) ) {
F_186 ( V_28 , V_290 , 1 ) ;
F_186 ( V_28 , V_291 , 1 ) ;
}
F_165 ( V_28 ) ;
F_175 ( V_28 , F_188 ( V_28 , V_218 ) ) ;
return 0 ;
}
static int
F_189 ( struct V_27 * V_28 )
{
return F_174 ( V_28 ) ;
}
static int F_190 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_47 ( V_20 ) ;
int V_37 = 0 ;
if ( V_2 -> V_148 )
return - V_34 ;
V_37 = F_121 ( V_2 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_102 ( V_2 , V_20 ) ;
if ( V_37 )
goto V_45;
F_191 ( V_20 ) ;
return 0 ;
V_45:
F_130 ( V_2 ) ;
return V_37 ;
}
static int F_192 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_47 ( V_20 ) ;
F_111 ( V_2 , V_20 ) ;
return 0 ;
}
static void
F_193 ( struct V_19 * V_20 ,
struct V_3 * V_4 ,
struct V_293 * V_294 ,
struct V_295 * V_296 )
{
T_13 V_297 = V_298 ;
T_14 V_299 = V_296 -> V_299 ;
T_15 V_95 = 0 , V_300 = 0 ;
T_2 V_6 ;
int V_301 , V_146 , V_302 , V_303 = 0 , V_304 = 0 , V_305 = 0 ;
struct V_293 * V_306 ;
struct V_307 * V_308 ;
if ( V_299 == F_194 ( V_309 ) ) {
V_308 = (struct V_307 * ) V_296 -> V_52 ;
V_299 = V_308 -> V_310 ;
V_95 = V_311 ;
} else if ( F_195 ( V_296 ) ) {
V_95 = V_312 ;
V_300 = F_196 ( V_296 ) ;
F_197 ( V_294 , V_300 ) ;
V_305 = 1 ;
}
if ( ( V_20 -> V_84 & ( V_241 | V_243 ) ) &&
F_198 ( V_296 ) -> V_313 > 0 ) {
V_303 = F_199 ( V_296 ) + F_200 ( V_296 ) ;
V_294 -> V_314 = F_201 ( F_198 ( V_296 ) -> V_313 ) ;
V_294 -> V_315 = V_303 ;
if ( V_305 ) {
V_294 -> V_315 += V_316 ;
V_294 -> V_317 = V_316 ;
V_294 -> V_318 = V_316 ;
V_95 |= V_311 ;
}
V_297 = ( V_299 == F_194 ( V_319 ) ) ?
V_320 : V_321 ;
V_304 = 1 ;
} else if ( V_296 -> V_322 == V_323 ) {
T_13 V_324 ;
if ( V_299 == F_194 ( V_325 ) ) {
V_324 = F_202 ( V_296 ) -> V_299 ;
if ( V_324 == V_326 )
V_297 = V_327 ;
else if( V_324 == V_328 )
V_297 = V_329 ;
} else if ( V_299 == F_194 ( V_319 ) ) {
V_324 = F_203 ( V_296 ) -> V_330 ;
if ( V_324 == V_326 )
V_297 = V_331 ;
else if( V_324 == V_328 )
V_297 = V_332 ;
}
}
V_294 -> V_317 += F_199 ( V_296 ) ;
V_294 -> V_318 += F_204 ( V_296 ) ;
F_205 ( V_294 , V_95 , V_297 ) ;
if ( ! V_304 )
return;
V_6 = V_4 -> V_6 ;
V_301 = 0 ;
V_146 = 2 ;
if ( V_305 ) {
V_306 = & V_4 -> V_333 [ V_6 ] ;
V_4 -> V_334 [ V_6 ] . V_296 = NULL ;
V_302 = F_206 ( ( int ) sizeof( struct V_293 ) - V_146 ,
V_303 + V_316 ) ;
V_308 = (struct V_307 * ) ( ( char * ) V_306 + 2 ) ;
F_207 ( V_296 , V_308 , 12 ) ;
V_308 -> V_335 = F_208 ( V_309 ) ;
V_308 -> V_336 = F_208 ( V_300 ) ;
F_209 ( V_296 , 12 ,
( char * ) V_308 + 16 , V_302 - 16 ) ;
V_301 = V_302 - V_316 ;
V_146 = 0 ;
V_6 = F_210 ( V_6 , V_4 -> V_337 ) ;
}
while ( V_301 < V_303 ) {
V_302 = F_206 ( ( int ) sizeof( struct V_293 ) - V_146 ,
( V_303 - V_301 ) ) ;
V_306 = & V_4 -> V_333 [ V_6 ] ;
V_4 -> V_334 [ V_6 ] . V_296 = NULL ;
F_209 ( V_296 , V_301 ,
( char * ) V_306 + V_146 , V_302 ) ;
V_301 += V_302 ;
V_146 = 0 ;
V_6 = F_210 ( V_6 , V_4 -> V_337 ) ;
}
V_4 -> V_6 = V_6 ;
F_211 () ;
}
static int
F_212 ( struct V_27 * V_28 ,
struct V_295 * V_296 , struct V_338 * V_339 )
{
struct V_340 * V_341 ;
struct V_342 * V_343 ;
int V_70 , V_344 ;
T_16 V_345 ;
V_344 = F_198 ( V_296 ) -> V_344 ;
V_341 = & V_339 -> V_346 [ 0 ] ;
V_345 = F_213 ( V_28 , V_296 -> V_52 ,
F_214 ( V_296 ) , V_347 ) ;
if ( F_215 ( V_28 , V_345 ) )
goto V_348;
V_341 -> V_349 = V_345 ;
V_341 -> V_350 = F_214 ( V_296 ) ;
for ( V_70 = 0 ; V_70 < V_344 ; V_70 ++ ) {
V_343 = & F_198 ( V_296 ) -> V_351 [ V_70 ] ;
V_341 = & V_339 -> V_346 [ V_70 + 1 ] ;
V_345 = F_216 ( V_28 , V_343 -> V_352 , V_343 -> V_353 ,
V_343 -> V_16 , V_347 ) ;
if ( F_215 ( V_28 , V_345 ) )
goto V_354;
V_341 -> V_349 = V_345 ;
V_341 -> V_350 = V_343 -> V_16 ;
}
return 0 ;
V_354:
while ( -- V_70 >= 0 ) {
V_341 = & V_339 -> V_346 [ V_70 + 1 ] ;
F_217 ( V_28 , V_341 -> V_349 , V_341 -> V_350 , V_347 ) ;
}
V_341 = & V_339 -> V_346 [ 0 ] ;
F_218 ( V_28 , V_341 -> V_349 , F_214 ( V_296 ) , V_347 ) ;
V_348:
return - V_23 ;
}
static inline void
F_219 ( T_3 * V_355 )
{
V_355 [ 0 ] = 0ULL ;
V_355 [ 2 ] = 0ULL ;
}
static T_17
F_220 ( struct V_295 * V_296 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_47 ( V_20 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_338 * V_339 ;
struct V_340 * V_356 ;
struct V_293 * V_306 , * V_294 ;
struct V_27 * V_28 ;
int V_70 , V_357 ;
int V_358 = 0 ;
struct V_342 * V_343 ;
T_2 V_6 ;
int V_359 , V_360 ;
T_2 V_174 = V_4 -> V_337 ;
V_359 = F_198 ( V_296 ) -> V_344 + 1 ;
if ( ! F_221 ( V_296 ) && V_359 > V_361 ) {
for ( V_70 = 0 ; V_70 < ( V_359 - V_361 ) ; V_70 ++ ) {
V_343 = & F_198 ( V_296 ) -> V_351 [ V_70 ] ;
V_358 += V_343 -> V_16 ;
}
if ( ! F_222 ( V_296 , V_358 ) )
goto V_362;
V_359 = 1 + F_198 ( V_296 ) -> V_344 ;
}
V_360 = ( V_359 + 3 ) >> 2 ;
if ( F_223 ( F_224 ( V_4 ) <= V_363 ) ) {
F_225 ( V_20 ) ;
F_113 () ;
if ( F_224 ( V_4 ) > V_363 )
F_191 ( V_20 ) ;
else
return V_364 ;
}
V_6 = V_4 -> V_6 ;
V_339 = & V_4 -> V_334 [ V_6 ] ;
V_28 = V_2 -> V_28 ;
if ( F_212 ( V_28 , V_296 , V_339 ) )
goto V_362;
V_339 -> V_296 = V_296 ;
V_339 -> V_359 = V_359 ;
V_294 = V_306 = & V_4 -> V_333 [ V_6 ] ;
F_219 ( ( T_3 * ) V_306 ) ;
F_226 ( V_294 , V_359 , V_296 -> V_365 ) ;
F_227 ( V_294 , V_2 -> V_154 ) ;
for ( V_70 = 0 ; V_70 < V_359 ; V_70 ++ ) {
V_357 = V_70 % 4 ;
if ( ( V_357 == 0 ) && ( V_70 > 0 ) ) {
V_6 = F_210 ( V_6 , V_174 ) ;
V_306 = & V_4 -> V_333 [ V_6 ] ;
F_219 ( ( T_3 * ) V_306 ) ;
V_4 -> V_334 [ V_6 ] . V_296 = NULL ;
}
V_356 = & V_339 -> V_346 [ V_70 ] ;
V_306 -> V_366 [ V_357 ] = F_201 ( V_356 -> V_350 ) ;
switch ( V_357 ) {
case 0 :
V_306 -> V_367 = F_228 ( V_356 -> V_349 ) ;
break;
case 1 :
V_306 -> V_368 = F_228 ( V_356 -> V_349 ) ;
break;
case 2 :
V_306 -> V_369 = F_228 ( V_356 -> V_349 ) ;
break;
case 3 :
V_306 -> V_370 = F_228 ( V_356 -> V_349 ) ;
break;
}
}
V_4 -> V_6 = F_210 ( V_6 , V_174 ) ;
F_193 ( V_20 , V_4 , V_294 , V_296 ) ;
V_2 -> V_371 . V_372 += V_296 -> V_365 ;
V_2 -> V_371 . V_373 ++ ;
F_1 ( V_2 , V_4 ) ;
return V_374 ;
V_362:
V_2 -> V_371 . V_375 ++ ;
F_229 ( V_296 ) ;
return V_374 ;
}
static int F_230 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_18 V_376 , V_377 , V_378 ;
int V_379 = 0 ;
V_376 = F_27 ( V_2 , V_380 ) ;
V_377 = F_231 ( V_376 ) ;
V_378 = F_232 ( V_376 ) ;
if ( V_377 == V_381 ) {
F_78 ( V_382
L_32
L_33 ,
V_20 -> V_197 , V_378 ) ;
V_379 = 1 ;
} else if ( V_377 == V_383 ) {
if ( V_2 -> V_376 == V_384 ) {
F_78 ( V_382
L_34
L_35
L_36 ,
V_20 -> V_197 , V_378 ) ;
}
} else {
if ( V_2 -> V_376 == V_383 ) {
F_78 ( V_385
L_37
L_38 , V_20 -> V_197 ,
V_378 ) ;
}
}
V_2 -> V_376 = V_377 ;
return V_379 ;
}
void F_233 ( struct V_1 * V_2 , int V_215 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
if ( V_2 -> V_32 . V_215 && ! V_215 ) {
F_78 ( V_385 L_39 ,
V_138 , V_20 -> V_197 ) ;
V_2 -> V_32 . V_215 = 0 ;
if ( F_48 ( V_20 ) ) {
F_115 ( V_20 ) ;
F_225 ( V_20 ) ;
}
V_2 -> V_386 = ! V_2 -> V_387 ;
} else if ( ! V_2 -> V_32 . V_215 && V_215 ) {
F_78 ( V_385 L_40 ,
V_138 , V_20 -> V_197 ) ;
V_2 -> V_32 . V_215 = 1 ;
if ( F_48 ( V_20 ) ) {
F_234 ( V_20 ) ;
F_235 ( V_20 ) ;
}
V_2 -> V_386 = ! V_2 -> V_387 ;
}
}
static void F_236 ( struct V_1 * V_2 )
{
T_2 V_47 , V_388 , V_215 ;
V_388 = V_2 -> V_212 ;
if ( F_28 ( V_2 -> V_32 . V_33 ) ) {
V_47 = F_27 ( V_2 , V_389 ) ;
V_47 = F_237 ( V_2 -> V_32 . V_100 , V_47 ) ;
V_215 = ( V_47 == V_390 ) ;
} else {
V_47 = F_27 ( V_2 , V_391 ) ;
V_47 = ( V_47 >> V_388 * 8 ) & 0xff ;
V_215 = ( V_47 == V_392 ) ;
}
F_233 ( V_2 , V_215 ) ;
}
static void F_238 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_47 ( V_20 ) ;
if ( F_239 ( V_228 , & V_2 -> V_218 ) )
return;
F_71 ( & V_20 -> V_43 , L_41 ) ;
F_240 ( & V_2 -> V_249 ) ;
}
static void V_250 ( struct V_393 * V_394 )
{
struct V_1 * V_2 =
F_241 ( V_394 , struct V_1 , V_249 ) ;
if ( ! F_48 ( V_2 -> V_20 ) )
return;
if ( F_133 ( V_228 , & V_2 -> V_218 ) )
return;
if ( ++ V_2 -> V_395 >= V_396 )
goto V_397;
F_109 () ;
if ( F_22 ( V_2 -> V_32 . V_33 ) ) {
F_17 ( V_2 ) ;
F_15 ( V_2 ) ;
F_235 ( V_2 -> V_20 ) ;
F_134 ( V_228 , & V_2 -> V_218 ) ;
} else {
F_134 ( V_228 , & V_2 -> V_218 ) ;
if ( F_132 ( V_2 ) ) {
F_110 () ;
goto V_397;
}
}
V_2 -> V_20 -> V_398 = V_399 ;
F_110 () ;
return;
V_397:
V_2 -> V_191 = 1 ;
F_134 ( V_228 , & V_2 -> V_218 ) ;
}
static struct V_400 * F_242 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_47 ( V_20 ) ;
struct V_400 * V_371 = & V_20 -> V_371 ;
V_371 -> V_203 = V_2 -> V_371 . V_401 + V_2 -> V_371 . V_402 ;
V_371 -> V_207 = V_2 -> V_371 . V_403 ;
V_371 -> V_404 = V_2 -> V_371 . V_405 ;
V_371 -> V_406 = V_2 -> V_371 . V_372 ;
V_371 -> V_407 = V_2 -> V_371 . V_408 ;
V_371 -> V_409 = V_2 -> V_371 . V_375 ;
return V_371 ;
}
static T_19 V_196 ( int V_114 , void * V_52 )
{
struct V_9 * V_10 = V_52 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_410 = 0 ;
V_410 = F_243 ( V_2 -> V_104 ) ;
if ( ! ( V_410 & V_2 -> V_101 ) )
return V_411 ;
if ( F_28 ( V_2 -> V_32 . V_33 ) ) {
V_410 = F_243 ( V_2 -> V_107 ) ;
if ( ! F_244 ( V_410 ) )
return V_411 ;
} else {
unsigned long V_412 = 0 ;
V_412 = F_243 ( V_2 -> V_107 ) ;
if ( ! F_112 ( ( 7 + V_2 -> V_154 ) , & V_412 ) )
return V_411 ;
F_245 ( ( V_412 & 0xffffffff ) , V_2 -> V_107 ) ;
F_4 ( V_10 ) ;
}
F_245 ( 0xffffffff , V_2 -> V_102 ) ;
F_243 ( V_2 -> V_104 ) ;
F_243 ( V_2 -> V_104 ) ;
F_246 ( & V_10 -> V_24 ) ;
return V_413 ;
}
static T_19 V_194 ( int V_114 , void * V_52 )
{
struct V_9 * V_10 = V_52 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_245 ( 0xffffffff , V_2 -> V_102 ) ;
F_246 ( & V_10 -> V_24 ) ;
return V_413 ;
}
static T_19 V_193 ( int V_114 , void * V_52 )
{
struct V_9 * V_10 = V_52 ;
F_246 ( & V_10 -> V_24 ) ;
return V_413 ;
}
static int V_25 ( struct V_414 * V_24 , int V_415 )
{
struct V_9 * V_10 =
F_241 ( V_24 , struct V_9 , V_24 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_416 ;
int V_417 ;
V_416 = F_247 ( V_2 ) ;
V_417 = F_248 ( V_10 , V_415 ) ;
if ( ( V_417 < V_415 ) && V_416 ) {
F_249 ( & V_10 -> V_24 ) ;
if ( F_239 ( V_217 , & V_2 -> V_218 ) )
F_5 ( V_10 ) ;
}
return V_417 ;
}
static void F_250 ( struct V_19 * V_20 )
{
int V_21 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = F_47 ( V_20 ) ;
struct V_13 * V_14 = & V_2 -> V_14 ;
F_251 ( V_2 -> V_114 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_22 ; V_21 ++ ) {
V_10 = & V_14 -> V_17 [ V_21 ] ;
V_196 ( V_2 -> V_114 , V_10 ) ;
}
F_252 ( V_2 -> V_114 ) ;
}
static int
F_253 ( struct V_1 * V_2 )
{
int V_15 ;
if ( F_254 ( V_2 ) )
return - V_34 ;
V_15 = F_27 ( V_2 , V_278 ) ;
F_31 ( V_2 , V_278 , ++ V_15 ) ;
F_255 ( V_2 ) ;
return V_15 ;
}
static int
F_162 ( struct V_1 * V_2 )
{
int V_15 ;
if ( F_254 ( V_2 ) )
return - V_34 ;
V_15 = F_27 ( V_2 , V_278 ) ;
F_256 ( V_15 == 0 ) ;
F_31 ( V_2 , V_278 , -- V_15 ) ;
if ( V_15 == 0 )
F_31 ( V_2 , V_189 , V_418 ) ;
F_255 ( V_2 ) ;
return V_15 ;
}
static int
F_179 ( struct V_1 * V_2 )
{
T_2 V_218 ;
int V_419 = - V_81 ;
if ( F_254 ( V_2 ) )
return V_419 ;
V_218 = F_27 ( V_2 , V_189 ) ;
if ( V_218 == V_420 )
V_419 = 0 ;
else if ( V_218 == V_190 ) {
F_31 ( V_2 , V_189 , V_420 ) ;
V_419 = 0 ;
}
F_255 ( V_2 ) ;
return V_419 ;
}
static int
F_257 ( struct V_1 * V_2 )
{
T_2 V_218 ;
int V_419 = - V_81 ;
if ( F_254 ( V_2 ) )
return V_419 ;
V_218 = F_27 ( V_2 , V_189 ) ;
if ( V_218 == V_421 )
V_419 = 0 ;
else if ( V_218 != V_422 && V_218 != V_420 ) {
F_31 ( V_2 , V_189 , V_421 ) ;
V_419 = 0 ;
}
F_255 ( V_2 ) ;
return V_419 ;
}
static int
F_88 ( struct V_1 * V_2 )
{
int V_15 ;
int V_423 = 0 ;
if ( F_254 ( V_2 ) )
return 0 ;
V_15 = F_27 ( V_2 , V_278 ) ;
if ( ( V_15 < 0 ) || ( V_15 >= V_424 ) )
V_15 = 0 ;
if ( V_15 == 0 ) {
V_423 = 1 ;
F_31 ( V_2 , V_189 , V_422 ) ;
}
F_31 ( V_2 , V_278 , ++ V_15 ) ;
F_255 ( V_2 ) ;
return V_423 ;
}
static void
F_160 ( struct V_1 * V_2 ,
T_20 V_425 , int V_426 )
{
F_258 ( & V_2 -> V_427 , V_425 ) ;
F_259 ( & V_2 -> V_427 , V_426 ) ;
}
static void
F_168 ( struct V_1 * V_2 )
{
while ( F_133 ( V_228 , & V_2 -> V_218 ) )
F_34 ( 10 ) ;
F_260 ( & V_2 -> V_427 ) ;
}
static void
F_261 ( struct V_393 * V_394 )
{
struct V_1 * V_2 = F_241 ( V_394 ,
struct V_1 , V_427 . V_394 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
int V_37 = 0 ;
if ( F_48 ( V_20 ) ) {
V_37 = F_121 ( V_2 ) ;
if ( V_37 )
goto V_230;
V_37 = F_108 ( V_2 , V_20 ) ;
if ( V_37 ) {
F_130 ( V_2 ) ;
goto V_230;
}
F_177 ( V_20 , V_285 ) ;
}
F_50 ( V_20 ) ;
V_230:
V_2 -> V_428 = 0 ;
F_134 ( V_228 , & V_2 -> V_218 ) ;
F_160 ( V_2 , V_281 , V_282 ) ;
}
static void
F_262 ( struct V_393 * V_394 )
{
struct V_1 * V_2 = F_241 ( V_394 ,
struct V_1 , V_427 . V_394 ) ;
int V_429 ;
V_429 = F_27 ( V_2 , V_189 ) ;
switch ( V_429 ) {
case V_418 :
case V_190 :
if ( ! F_87 ( V_2 ) ) {
F_160 ( V_2 , F_261 , 0 ) ;
return;
}
break;
case V_421 :
case V_422 :
if ( ++ V_2 -> V_430 < V_431 ) {
F_160 ( V_2 ,
F_262 , 2 * V_282 ) ;
return;
}
case V_432 :
default:
F_253 ( V_2 ) ;
break;
}
F_134 ( V_228 , & V_2 -> V_218 ) ;
}
static void
F_263 ( struct V_393 * V_394 )
{
struct V_1 * V_2 = F_241 ( V_394 ,
struct V_1 , V_427 . V_394 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
int V_433 , V_426 ;
T_2 V_410 ;
F_49 ( V_20 ) ;
F_120 ( V_2 , V_20 ) ;
F_109 () ;
F_130 ( V_2 ) ;
F_110 () ;
V_410 = F_27 ( V_2 , V_181 ) ;
if ( V_410 & V_434 )
goto V_435;
if ( V_2 -> V_376 == V_381 )
goto V_435;
V_433 = F_162 ( V_2 ) ;
if ( V_433 == - V_34 )
goto V_435;
V_426 = ( V_433 == 0 ) ? 0 : ( 2 * V_282 ) ;
V_2 -> V_430 = 0 ;
F_160 ( V_2 , F_262 , V_426 ) ;
return;
V_435:
F_134 ( V_228 , & V_2 -> V_218 ) ;
}
static int
F_264 ( struct V_1 * V_2 )
{
T_2 V_218 , V_436 ;
struct V_19 * V_20 = V_2 -> V_20 ;
V_218 = F_27 ( V_2 , V_189 ) ;
if ( V_218 == V_420 )
return 0 ;
if ( F_230 ( V_2 ) )
goto V_437;
if ( V_2 -> V_191 ) {
if ( F_257 ( V_2 ) )
return 0 ;
goto V_437;
}
if ( V_218 == V_421 ) {
V_2 -> V_191 = 1 ;
if ( F_22 ( V_2 -> V_32 . V_33 ) )
goto V_437;
}
if ( F_22 ( V_2 -> V_32 . V_33 ) )
return 0 ;
V_436 = F_27 ( V_2 , V_438 ) ;
if ( V_436 != V_2 -> V_436 ) {
V_2 -> V_436 = V_436 ;
V_2 -> V_428 = 0 ;
if ( V_2 -> V_191 )
goto V_437;
return 0 ;
}
if ( ++ V_2 -> V_428 < V_439 )
return 0 ;
if ( F_257 ( V_2 ) )
return 0 ;
F_134 ( V_440 , & V_2 -> V_218 ) ;
F_29 ( & V_20 -> V_43 , L_42 ) ;
V_437:
if ( ( V_441 == V_442 ) &&
! F_133 ( V_228 , & V_2 -> V_218 ) )
F_160 ( V_2 , F_263 , 0 ) ;
return 1 ;
}
static void
V_281 ( struct V_393 * V_394 )
{
struct V_1 * V_2 = F_241 ( V_394 ,
struct V_1 , V_427 . V_394 ) ;
if ( F_239 ( V_228 , & V_2 -> V_218 ) )
goto V_443;
if ( F_239 ( V_217 , & V_2 -> V_218 ) ) {
if ( ! V_2 -> V_387 ) {
F_236 ( V_2 ) ;
if ( V_2 -> V_386 )
F_106 ( V_2 ) ;
}
}
if ( F_264 ( V_2 ) )
return;
V_443:
F_160 ( V_2 , V_281 , V_282 ) ;
}
static T_21
F_265 ( struct V_444 * V_43 ,
struct V_445 * V_446 , const char * V_447 , T_22 V_365 )
{
struct V_19 * V_448 = F_266 ( V_43 ) ;
struct V_1 * V_2 = F_47 ( V_448 ) ;
unsigned long V_449 ;
int V_419 = - V_81 ;
if ( ! ( V_2 -> V_158 & V_450 ) )
goto V_45;
if ( V_2 -> V_209 != V_210 )
goto V_45;
if ( F_267 ( V_447 , 2 , & V_449 ) )
goto V_45;
if ( ! F_268 ( V_2 , ! ! V_449 ) )
V_419 = V_365 ;
V_45:
return V_419 ;
}
static T_21
F_269 ( struct V_444 * V_43 ,
struct V_445 * V_446 , char * V_447 )
{
struct V_19 * V_448 = F_266 ( V_43 ) ;
struct V_1 * V_2 ;
int V_451 = 0 ;
V_2 = F_47 ( V_448 ) ;
if ( V_2 -> V_158 & V_450 )
V_451 = ! ! ( V_2 -> V_95 & V_452 ) ;
return sprintf ( V_447 , L_43 , V_451 ) ;
}
static T_21
F_270 ( struct V_444 * V_43 ,
struct V_445 * V_446 , const char * V_447 , T_22 V_365 )
{
struct V_1 * V_2 = F_271 ( V_43 ) ;
unsigned long V_449 ;
if ( F_267 ( V_447 , 2 , & V_449 ) )
return - V_81 ;
if ( ! ! V_449 != ! ! ( V_2 -> V_95 & V_453 ) )
V_2 -> V_95 ^= V_453 ;
return V_365 ;
}
static T_21
F_272 ( struct V_444 * V_43 ,
struct V_445 * V_446 , char * V_447 )
{
struct V_1 * V_2 = F_271 ( V_43 ) ;
return sprintf ( V_447 , L_43 ,
! ! ( V_2 -> V_95 & V_453 ) ) ;
}
static int
F_273 ( struct V_1 * V_2 ,
T_23 V_146 , T_22 V_16 )
{
T_22 V_454 = 4 ;
if ( ! ( V_2 -> V_95 & V_453 ) )
return - V_34 ;
if ( V_146 < V_455 ) {
if ( F_22 ( V_2 -> V_32 . V_33 ) )
return - V_81 ;
if ( F_274 ( V_146 , V_456 ,
V_457 ) )
V_454 = 8 ;
else
return - V_81 ;
}
if ( ( V_16 != V_454 ) || ( V_146 & ( V_454 - 1 ) ) )
return - V_81 ;
return 0 ;
}
static T_21
F_275 ( struct V_458 * V_459 , struct V_460 * V_461 ,
struct V_462 * V_446 ,
char * V_447 , T_23 V_146 , T_22 V_16 )
{
struct V_444 * V_43 = F_241 ( V_461 , struct V_444 , V_461 ) ;
struct V_1 * V_2 = F_271 ( V_43 ) ;
T_2 V_52 ;
T_3 V_463 ;
int V_419 ;
V_419 = F_273 ( V_2 , V_146 , V_16 ) ;
if ( V_419 != 0 )
return V_419 ;
if ( F_28 ( V_2 -> V_32 . V_33 ) &&
F_274 ( V_146 , V_456 ,
V_457 ) ) {
F_276 ( V_2 , V_146 , & V_463 ) ;
memcpy ( V_447 , & V_463 , V_16 ) ;
} else {
V_52 = F_27 ( V_2 , V_146 ) ;
memcpy ( V_447 , & V_52 , V_16 ) ;
}
return V_16 ;
}
static T_21
F_277 ( struct V_458 * V_459 , struct V_460 * V_461 ,
struct V_462 * V_446 ,
char * V_447 , T_23 V_146 , T_22 V_16 )
{
struct V_444 * V_43 = F_241 ( V_461 , struct V_444 , V_461 ) ;
struct V_1 * V_2 = F_271 ( V_43 ) ;
T_2 V_52 ;
T_3 V_463 ;
int V_419 ;
V_419 = F_273 ( V_2 , V_146 , V_16 ) ;
if ( V_419 != 0 )
return V_419 ;
if ( F_28 ( V_2 -> V_32 . V_33 ) &&
F_274 ( V_146 , V_456 ,
V_457 ) ) {
memcpy ( & V_463 , V_447 , V_16 ) ;
F_278 ( V_2 , V_146 , V_463 ) ;
} else {
memcpy ( & V_52 , V_447 , V_16 ) ;
F_31 ( V_2 , V_146 , V_52 ) ;
}
return V_16 ;
}
static int
F_279 ( struct V_1 * V_2 ,
T_23 V_146 , T_22 V_16 )
{
if ( ! ( V_2 -> V_95 & V_453 ) )
return - V_34 ;
if ( ( V_16 != 8 ) || ( V_146 & 0x7 ) )
return - V_34 ;
return 0 ;
}
static T_21
F_280 ( struct V_458 * V_459 , struct V_460 * V_461 ,
struct V_462 * V_446 ,
char * V_447 , T_23 V_146 , T_22 V_16 )
{
struct V_444 * V_43 = F_241 ( V_461 , struct V_444 , V_461 ) ;
struct V_1 * V_2 = F_271 ( V_43 ) ;
T_3 V_52 ;
int V_419 ;
V_419 = F_279 ( V_2 , V_146 , V_16 ) ;
if ( V_419 != 0 )
return V_419 ;
if ( V_2 -> V_464 ( V_2 , V_146 , & V_52 ) )
return - V_34 ;
memcpy ( V_447 , & V_52 , V_16 ) ;
return V_16 ;
}
static T_21 F_281 ( struct V_458 * V_459 , struct V_460 * V_461 ,
struct V_462 * V_446 , char * V_447 ,
T_23 V_146 , T_22 V_16 )
{
struct V_444 * V_43 = F_241 ( V_461 , struct V_444 , V_461 ) ;
struct V_1 * V_2 = F_271 ( V_43 ) ;
T_3 V_52 ;
int V_419 ;
V_419 = F_279 ( V_2 , V_146 , V_16 ) ;
if ( V_419 != 0 )
return V_419 ;
memcpy ( & V_52 , V_447 , V_16 ) ;
if ( V_2 -> V_465 ( V_2 , V_146 , V_52 ) )
return - V_34 ;
return V_16 ;
}
static void
F_126 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_444 * V_43 = & V_20 -> V_43 ;
if ( V_2 -> V_158 & V_450 ) {
if ( F_282 ( V_43 , & V_466 ) ) {
F_45 ( & V_20 -> V_43 ,
L_44 ) ;
}
}
}
static void
F_131 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_444 * V_43 = & V_20 -> V_43 ;
if ( V_2 -> V_158 & V_450 )
F_283 ( V_43 , & V_466 ) ;
}
static void
F_161 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_444 * V_43 ;
V_43 = & V_28 -> V_43 ;
if ( F_282 ( V_43 , & V_467 ) )
F_29 ( V_43 , L_45 ) ;
if ( F_284 ( V_43 , & V_468 ) )
F_29 ( V_43 , L_46 ) ;
if ( F_284 ( V_43 , & V_469 ) )
F_29 ( V_43 , L_47 ) ;
}
static void
F_171 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_444 * V_43 = & V_28 -> V_43 ;
F_283 ( V_43 , & V_467 ) ;
F_285 ( V_43 , & V_468 ) ;
F_285 ( V_43 , & V_469 ) ;
}
static int
F_286 ( struct V_1 * V_2 )
{
if ( F_22 ( V_2 -> V_32 . V_33 ) )
return 0 ;
if ( V_2 -> V_32 . V_157 )
return 0 ;
return 1 ;
}
static void
F_177 ( struct V_19 * V_43 , unsigned long V_470 )
{
struct V_471 * V_472 ;
struct V_1 * V_2 = F_47 ( V_43 ) ;
if ( ! F_286 ( V_2 ) )
return;
V_472 = F_287 ( V_43 ) ;
if ( ! V_472 )
return;
F_288 (indev) {
switch ( V_470 ) {
case V_285 :
F_289 ( V_2 ,
V_473 -> V_474 , V_475 ) ;
break;
case V_476 :
F_289 ( V_2 ,
V_473 -> V_474 , V_477 ) ;
break;
default:
break;
}
} F_290 ( V_472 ) ;
F_291 ( V_472 ) ;
}
static int F_292 ( struct V_478 * V_479 ,
unsigned long V_470 , void * V_480 )
{
struct V_1 * V_2 ;
struct V_19 * V_43 = (struct V_19 * ) V_480 ;
V_481:
if ( V_43 == NULL )
goto V_230;
if ( V_43 -> V_482 & V_483 ) {
V_43 = F_293 ( V_43 ) ;
goto V_481;
}
if ( ! F_294 ( V_43 ) )
goto V_230;
V_2 = F_47 ( V_43 ) ;
if ( ! V_2 )
goto V_230;
if ( V_2 -> V_209 != V_210 )
goto V_230;
F_177 ( V_43 , V_470 ) ;
V_230:
return V_484 ;
}
static int
F_295 ( struct V_478 * V_479 ,
unsigned long V_470 , void * V_480 )
{
struct V_1 * V_2 ;
struct V_19 * V_43 ;
struct V_485 * V_473 = (struct V_485 * ) V_480 ;
V_43 = V_473 -> V_486 ? V_473 -> V_486 -> V_43 : NULL ;
V_481:
if ( V_43 == NULL || ! F_48 ( V_43 ) )
goto V_230;
if ( V_43 -> V_482 & V_483 ) {
V_43 = F_293 ( V_43 ) ;
goto V_481;
}
if ( ! F_294 ( V_43 ) )
goto V_230;
V_2 = F_47 ( V_43 ) ;
if ( ! V_2 || ! F_286 ( V_2 ) )
goto V_230;
if ( V_2 -> V_209 != V_210 )
goto V_230;
switch ( V_470 ) {
case V_285 :
F_289 ( V_2 , V_473 -> V_474 , V_475 ) ;
break;
case V_476 :
F_289 ( V_2 , V_473 -> V_474 , V_477 ) ;
break;
default:
break;
}
V_230:
return V_484 ;
}
static void
F_177 ( struct V_19 * V_43 , unsigned long V_470 )
{ }
static int T_24 F_296 ( void )
{
F_78 ( V_385 L_48 , V_487 ) ;
#ifdef F_297
F_298 ( & V_488 ) ;
F_299 ( & V_489 ) ;
#endif
return F_300 ( & V_490 ) ;
}
static void T_25 F_301 ( void )
{
F_302 ( & V_490 ) ;
#ifdef F_297
F_303 ( & V_489 ) ;
F_304 ( & V_488 ) ;
#endif
}
