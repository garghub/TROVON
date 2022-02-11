static inline int F_1 ( unsigned long V_1 )
{
return V_1 >= V_2 && V_1 < V_3 ;
}
struct V_4 * F_2 ( unsigned long V_5 )
{
struct V_4 * V_6 ;
V_6 = F_3 ( V_7 -> V_8 , V_5 ) ;
if ( V_6 && V_6 -> V_9 <= V_5 && V_6 -> V_10 == & V_11 )
return V_6 ;
return NULL ;
}
static struct V_12 * F_4 ( unsigned long V_5 )
{
struct V_13 * V_8 = V_7 -> V_8 ;
struct V_4 * V_6 ;
struct V_12 * V_14 = NULL ;
F_5 ( & V_8 -> V_15 ) ;
V_6 = F_2 ( V_5 ) ;
if ( V_6 )
V_14 = F_6 ( V_6 , F_7 ( V_5 , V_6 ) ) ;
if ( V_14 )
F_8 ( & V_14 -> V_16 ) ;
else
F_9 ( & V_8 -> V_15 ) ;
return V_14 ;
}
static struct V_12 * F_10 ( unsigned long V_5 )
{
struct V_13 * V_8 = V_7 -> V_8 ;
struct V_4 * V_6 ;
struct V_12 * V_14 = F_11 ( - V_17 ) ;
F_12 ( & V_8 -> V_15 ) ;
V_6 = F_2 ( V_5 ) ;
if ( ! V_6 )
goto V_18;
V_14 = F_13 ( V_6 , F_7 ( V_5 , V_6 ) ) ;
if ( F_14 ( V_14 ) )
goto V_18;
F_8 ( & V_14 -> V_16 ) ;
F_15 ( & V_8 -> V_15 ) ;
return V_14 ;
V_18:
F_16 ( & V_8 -> V_15 ) ;
return V_14 ;
}
static void F_17 ( struct V_12 * V_14 )
{
F_18 ( & V_14 -> V_16 ) ;
F_9 ( & V_7 -> V_8 -> V_15 ) ;
}
static void F_19 ( struct V_19 * V_20 )
{
if ( V_20 ) {
V_20 -> V_21 = V_22 ;
}
}
static void F_20 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_25 * V_27 )
{
unsigned long V_28 , V_29 ;
struct V_25 * V_30 ;
V_30 = F_21 ( V_24 , F_22 () ) ;
F_23 ( V_30 ) ;
for ( V_28 = 0 ; V_28 < F_24 ( V_31 ) ; V_28 ++ ) {
V_29 = V_30 -> V_32 [ V_28 ] ;
if ( V_29 )
V_29 = F_25 ( & V_30 -> V_32 [ V_28 ] , 0UL ) ;
V_26 -> V_32 [ V_28 ] = V_29 ;
V_29 = V_30 -> V_33 [ V_28 ] ;
if ( V_29 )
V_29 = F_25 ( & V_30 -> V_33 [ V_28 ] , 0UL ) ;
V_27 -> V_32 [ V_28 ] = V_29 ;
}
F_26 ( V_30 ) ;
}
static int F_27 ( struct V_4 * V_6 ,
unsigned long V_5 , int V_34 ,
unsigned long * V_1 , int * V_35 )
{
struct V_36 * V_36 ;
#ifdef F_28
* V_35 = F_29 ( V_6 ) ? V_37 : V_38 ;
#else
* V_35 = V_38 ;
#endif
if ( F_30 ( V_5 , 1 , V_34 ? V_39 : 0 , & V_36 , NULL ) <= 0 )
return - V_40 ;
* V_1 = F_31 ( V_36 ) ;
F_32 ( V_36 ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_6 , unsigned long V_5 ,
int V_34 , unsigned long * V_1 , int * V_35 )
{
T_1 * V_41 ;
T_2 * V_42 ;
T_3 * V_43 ;
T_4 * V_44 ;
T_5 V_45 ;
V_41 = F_34 ( V_6 -> V_46 , V_5 ) ;
if ( F_35 ( F_36 ( * V_41 ) ) )
goto V_18;
V_42 = F_37 ( V_41 , V_5 ) ;
if ( F_35 ( F_38 ( * V_42 ) ) )
goto V_18;
V_43 = F_39 ( V_42 , V_5 ) ;
if ( F_35 ( F_40 ( * V_43 ) ) )
goto V_18;
V_44 = F_41 ( V_43 , V_5 ) ;
if ( F_35 ( F_42 ( * V_44 ) ) )
goto V_18;
#ifdef F_43
if ( F_35 ( F_44 ( * V_44 ) ) )
V_45 = * ( T_5 * ) V_44 ;
else
#endif
V_45 = * F_45 ( V_44 , V_5 ) ;
if ( F_35 ( ! F_46 ( V_45 ) ||
( V_34 && ( ! F_47 ( V_45 ) || ! F_48 ( V_45 ) ) ) ) )
return 1 ;
* V_1 = F_49 ( V_45 ) << V_38 ;
#ifdef F_28
* V_35 = F_29 ( V_6 ) ? V_37 : V_38 ;
#else
* V_35 = V_38 ;
#endif
return 0 ;
V_18:
return 1 ;
}
static int F_50 ( struct V_12 * V_14 , unsigned long V_5 ,
int V_34 , int V_47 , unsigned long * V_48 , int * V_35 )
{
struct V_13 * V_8 = V_14 -> V_49 ;
struct V_4 * V_6 ;
unsigned long V_1 ;
int V_50 , V_51 ;
V_6 = F_3 ( V_8 , V_5 ) ;
if ( ! V_6 )
goto V_52;
F_51 () ;
V_50 = F_33 ( V_6 , V_5 , V_34 , & V_1 , & V_51 ) ;
if ( V_50 ) {
if ( V_47 )
goto V_53;
if ( F_27 ( V_6 , V_5 , V_34 , & V_1 , & V_51 ) )
goto V_52;
}
if ( F_1 ( V_1 ) )
goto V_52;
V_1 = V_1 & ~ ( ( 1UL << V_51 ) - 1 ) ;
* V_48 = F_52 ( V_1 ) ;
* V_35 = V_51 ;
return V_54 ;
V_52:
return V_55 ;
V_53:
return V_56 ;
}
static void F_53 ( struct V_57 * V_58 )
{
if ( F_35 ( V_58 ) ) {
V_58 -> V_59 = 0 ;
F_26 ( V_58 ) ;
}
}
static void F_54 ( struct V_23 * V_24 ,
struct V_12 * V_14 , int V_47 ,
unsigned long V_60 , int V_61 , int V_34 ,
unsigned char V_62 ,
struct V_63 * V_64 ,
struct V_57 * V_58 )
{
unsigned long V_5 = 0 , V_48 ;
int V_50 , V_35 ;
if ( V_58 -> V_65 != V_66 )
return;
if ( V_60 == V_58 -> V_67 )
V_5 = V_60 + V_68 * V_58 -> V_69 - 1 ;
else if ( V_60 == V_58 -> V_70 )
V_5 = V_60 + ( 1 << V_58 -> V_71 ) * V_58 -> V_72 - 1 ;
V_60 &= V_73 ;
V_5 &= V_73 ;
V_5 = F_55 ( V_5 , V_60 + V_62 * V_74 ) ;
while ( V_5 > V_60 ) {
V_50 = F_50 ( V_14 , V_5 , V_34 , V_47 , & V_48 , & V_35 ) ;
if ( V_50 || F_56 ( V_64 , V_48 , V_75 , V_5 , V_61 , V_34 ,
F_57 ( V_35 ) ) )
return;
F_58 ( V_76 ,
L_1 ,
V_47 ? L_2 : L_3 , V_24 -> V_77 , V_14 , V_64 ,
V_5 , V_61 , V_34 , V_35 , V_48 ) ;
V_5 -= V_74 ;
F_59 ( V_78 ) ;
}
}
static int F_60 ( struct V_23 * V_24 ,
struct V_12 * V_14 ,
struct V_63 * V_64 ,
struct V_19 * V_20 )
{
struct V_57 * V_58 = NULL ;
unsigned char V_62 = V_14 -> V_79 ;
int V_35 = 0 , V_61 , V_34 , V_50 , V_47 = ! V_20 , V_80 ;
unsigned long V_48 = 0 , V_5 = 0 ;
if ( F_35 ( V_62 ) ) {
V_58 = F_61 ( V_64 ) ;
F_23 ( V_58 ) ;
}
if ( V_64 -> V_81 != V_82 ) {
F_26 ( V_64 ) ;
F_62 () ;
if ( V_64 -> V_81 != V_82 )
goto V_83;
F_59 ( V_84 ) ;
}
if ( V_64 -> V_85 == V_86 )
goto V_87;
if ( V_64 -> V_85 == V_88 && V_20 )
goto V_89;
V_34 = ( V_64 -> V_90 & V_91 ) != 0 ;
V_5 = V_64 -> V_92 ;
V_61 = V_64 -> V_93 ;
V_80 = V_64 -> V_80 ;
if ( V_61 == 0 )
goto V_94;
F_51 () ;
if ( F_63 ( & V_14 -> V_95 -> V_96 ) )
goto V_97;
V_50 = F_50 ( V_14 , V_5 , V_34 , V_47 , & V_48 , & V_35 ) ;
if ( V_50 == V_55 )
goto V_98;
if ( V_50 == V_56 )
goto V_99;
if ( ! ( V_14 -> V_100 & F_64 ( V_35 ) ) ) {
V_14 -> V_100 |= F_64 ( V_35 ) ;
if ( V_47 || ! F_65 ( V_14 ) ) {
V_14 -> V_101 = 1 ;
goto V_99;
}
}
if ( F_35 ( V_58 ) && V_35 == V_38 ) {
F_54 ( V_24 , V_14 , V_47 , V_5 , V_61 , V_34 , V_62 , V_64 , V_58 ) ;
F_53 ( V_58 ) ;
}
F_19 ( V_20 ) ;
V_14 -> V_102 . V_103 ++ ;
F_66 ( V_64 , V_48 , V_75 , V_5 , V_61 , V_34 ,
F_57 ( V_35 ) ) ;
F_58 ( V_76 ,
L_4
L_5 ,
V_47 ? L_2 : L_3 , V_24 -> V_77 , V_14 , V_64 , V_5 , V_61 ,
V_80 , V_34 , V_35 , V_48 ) ;
F_59 ( V_104 ) ;
return 0 ;
V_94:
F_59 ( V_105 ) ;
F_58 ( V_76 , L_6 , V_64 , V_5 ) ;
if ( ! V_20 )
F_67 ( V_64 ) ;
else
F_26 ( V_64 ) ;
F_53 ( V_58 ) ;
return - V_106 ;
V_99:
F_67 ( V_64 ) ;
F_53 ( V_58 ) ;
F_59 ( V_107 ) ;
F_58 ( V_76 , L_7 , V_64 , V_5 ) ;
return 1 ;
V_89:
F_26 ( V_64 ) ;
F_53 ( V_58 ) ;
F_59 ( V_108 ) ;
F_58 ( V_76 , L_8 , V_64 , V_64 -> V_85 ) ;
return 0 ;
V_83:
F_26 ( V_64 ) ;
F_53 ( V_58 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
F_59 ( V_109 ) ;
F_58 ( V_76 , L_9 ,
V_64 , V_64 -> V_81 , V_64 -> V_85 ) ;
return 0 ;
V_87:
F_26 ( V_64 ) ;
F_53 ( V_58 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
F_59 ( V_110 ) ;
F_58 ( V_76 , L_10 , V_64 , V_64 -> V_85 ) ;
return 0 ;
V_98:
F_68 ( V_64 ) ;
F_53 ( V_58 ) ;
F_59 ( V_111 ) ;
F_58 ( V_76 , L_11 , V_64 , V_5 ) ;
return - V_40 ;
V_97:
if ( ! V_20 )
F_67 ( V_64 ) ;
else
F_26 ( V_64 ) ;
F_53 ( V_58 ) ;
F_59 ( V_112 ) ;
F_58 ( V_76 , L_12 ,
V_64 , V_5 ) ;
return 1 ;
}
static T_6 F_69 ( int V_113 , int V_114 )
{
struct V_23 * V_24 ;
struct V_25 V_26 , V_27 ;
struct V_12 * V_14 ;
struct V_63 * V_64 = NULL ;
struct V_115 * V_116 ;
int V_117 , V_118 ;
F_59 ( V_119 ) ;
V_24 = & V_120 [ V_114 ] -> V_121 [ V_113 ] ;
if ( ! V_24 ) {
F_70 ( V_76 , L_13 ,
F_71 () , V_113 ) ;
return V_122 ;
}
F_20 ( V_24 , & V_26 , & V_27 ) ;
F_58 ( V_76 ,
L_14 ,
F_72 () , V_113 , V_24 -> V_77 ,
V_26 . V_32 [ 0 ] , V_26 . V_32 [ 1 ] ,
V_27 . V_32 [ 0 ] , V_27 . V_32 [ 1 ] ) ;
F_73 (cbrnum, dmap.fault_bits) {
F_59 ( V_123 ) ;
V_116 = V_24 -> V_124 -> V_125 ;
if ( V_116 )
F_74 ( V_116 ) ;
F_58 ( V_76 , L_15 ,
V_24 -> V_77 , V_117 , V_116 ? V_116 -> V_126 : - 1 ) ;
}
F_73 (cbrnum, imap.fault_bits) {
F_59 ( V_127 ) ;
V_64 = F_75 ( V_24 , V_117 ) ;
F_23 ( V_64 ) ;
V_118 = V_64 -> V_118 ;
V_14 = V_24 -> V_128 [ V_118 ] ;
if ( ! V_14 ) {
F_59 ( V_129 ) ;
continue;
}
V_14 -> V_102 . V_130 ++ ;
if ( ! V_14 -> V_101 &&
F_76 ( & V_14 -> V_49 -> V_15 ) ) {
F_60 ( V_24 , V_14 , V_64 , NULL ) ;
F_9 ( & V_14 -> V_49 -> V_15 ) ;
} else {
F_67 ( V_64 ) ;
F_59 ( V_131 ) ;
}
}
return V_132 ;
}
T_6 F_77 ( int V_133 , void * V_134 )
{
return F_69 ( 0 , F_78 () ) ;
}
T_6 F_79 ( int V_133 , void * V_134 )
{
return F_69 ( 1 , F_78 () ) ;
}
T_6 F_80 ( int V_133 , void * V_134 )
{
int V_114 ;
F_81 (blade) {
if ( F_82 ( V_114 ) )
continue;
F_69 ( 0 , V_114 ) ;
F_69 ( 1 , V_114 ) ;
}
return V_132 ;
}
static int F_83 ( struct V_12 * V_14 ,
struct V_63 * V_64 ,
void * V_135 )
{
struct V_136 * V_137 = V_14 -> V_95 ;
int V_50 ;
V_14 -> V_102 . V_138 ++ ;
while ( 1 ) {
F_84 ( V_137 -> V_139 ,
F_63 ( & V_137 -> V_96 ) == 0 ) ;
F_23 ( V_64 ) ;
V_50 = F_60 ( V_14 -> V_140 , V_14 , V_64 , V_135 ) ;
if ( V_50 <= 0 )
return V_50 ;
F_59 ( V_141 ) ;
}
}
int F_85 ( unsigned long V_135 )
{
struct V_63 * V_64 ;
struct V_12 * V_14 ;
void * V_20 ;
int V_142 , V_117 , V_50 = - V_17 ;
F_59 ( V_143 ) ;
V_142 = F_86 ( ( void * ) V_135 ) ;
if ( ( V_135 & ( V_144 - 1 ) ) || V_142 >= V_145 )
return - V_17 ;
V_14 = F_4 ( V_135 ) ;
if ( ! V_14 )
return - V_17 ;
F_58 ( V_76 , L_16 , V_135 , V_14 -> V_140 ? V_14 -> V_140 -> V_77 : - 1 , V_14 ) ;
if ( V_142 >= V_14 -> V_146 * V_147 )
goto exit;
F_87 ( V_14 ) ;
if ( V_14 -> V_140 && V_14 -> V_101 ) {
V_14 -> V_101 = 0 ;
F_65 ( V_14 ) ;
}
V_50 = - V_106 ;
V_117 = F_88 ( V_14 , V_142 ) ;
if ( V_14 -> V_140 ) {
V_64 = F_75 ( V_14 -> V_140 , V_117 ) ;
V_20 = F_89 ( V_14 -> V_140 -> V_148 ,
V_14 -> V_149 , V_142 ) ;
V_50 = F_83 ( V_14 , V_64 , V_20 ) ;
}
exit:
F_17 ( V_14 ) ;
return V_50 ;
}
int F_90 ( unsigned long V_150 )
{
struct V_151 V_152 ;
struct V_57 * V_58 ;
struct V_12 * V_14 ;
int V_142 , V_117 , V_50 ;
F_59 ( V_153 ) ;
if ( F_91 ( & V_152 , ( void V_154 * ) V_150 , sizeof( V_152 ) ) )
return - V_40 ;
V_14 = F_4 ( V_152 . V_135 ) ;
if ( ! V_14 )
return - V_17 ;
F_58 ( V_76 , L_16 , V_152 . V_135 , V_14 -> V_140 ? V_14 -> V_140 -> V_77 : - 1 , V_14 ) ;
V_142 = F_86 ( ( void * ) V_152 . V_135 ) ;
if ( V_142 >= V_14 -> V_146 * V_147 ) {
V_50 = - V_17 ;
} else if ( V_14 -> V_140 ) {
V_117 = F_88 ( V_14 , V_142 ) ;
V_58 = F_92 ( V_14 -> V_140 , V_117 ) ;
F_26 ( V_58 ) ;
F_62 () ;
V_152 . V_155 = V_58 -> V_65 ;
V_152 . V_156 = V_58 -> V_157 ;
V_152 . V_158 = V_58 -> V_158 ;
V_152 . V_159 = V_58 -> V_160 ;
V_152 . V_161 = V_58 -> V_162 ;
V_152 . V_163 = V_58 -> V_163 ;
V_152 . V_59 = V_58 -> V_59 ;
F_53 ( V_58 ) ;
V_50 = 0 ;
} else {
V_50 = - V_106 ;
}
F_17 ( V_14 ) ;
F_58 ( V_76 ,
L_17
L_18 ,
V_152 . V_135 , V_152 . V_155 , V_152 . V_156 , V_152 . V_163 , V_152 . V_59 ,
V_152 . V_158 , V_152 . V_159 , V_152 . V_161 ) ;
if ( ! V_50 && F_93 ( ( void V_154 * ) V_150 , & V_152 , sizeof( V_152 ) ) )
V_50 = - V_40 ;
return V_50 ;
}
static int F_94 ( void )
{
struct V_12 * V_14 ;
struct V_23 * V_24 ;
int V_164 , V_118 ;
if ( ! F_95 ( V_165 ) )
return - V_166 ;
F_96 (gid) {
V_24 = F_97 ( V_164 ) ;
F_98 ( & V_24 -> V_167 ) ;
for ( V_118 = 0 ; V_118 < V_168 ; V_118 ++ ) {
V_14 = V_24 -> V_128 [ V_118 ] ;
if ( V_14 && F_99 ( & V_14 -> V_16 ) ) {
F_100 ( & V_24 -> V_167 ) ;
F_101 ( V_14 , 1 ) ;
F_18 ( & V_14 -> V_16 ) ;
F_98 ( & V_24 -> V_167 ) ;
}
}
F_100 ( & V_24 -> V_167 ) ;
}
return 0 ;
}
int F_102 ( unsigned long V_150 )
{
struct V_12 * V_14 ;
struct V_169 V_170 ;
F_59 ( V_171 ) ;
if ( F_91 ( & V_170 , ( void V_154 * ) V_150 , sizeof( V_170 ) ) )
return - V_40 ;
F_58 ( V_76 , L_19 , V_170 . V_172 ) ;
if ( ! V_170 . V_172 )
return F_94 () ;
V_14 = F_4 ( V_170 . V_172 ) ;
if ( ! V_14 )
return - V_17 ;
if ( V_14 -> V_140 )
F_101 ( V_14 , 1 ) ;
F_17 ( V_14 ) ;
return 0 ;
}
int F_103 ( unsigned long V_150 )
{
struct V_12 * V_14 ;
struct V_173 V_170 ;
struct V_136 * V_137 ;
F_59 ( V_174 ) ;
if ( F_91 ( & V_170 , ( void V_154 * ) V_150 , sizeof( V_170 ) ) )
return - V_40 ;
F_58 ( V_76 , L_20 , V_170 . V_172 ,
V_170 . V_5 , V_170 . V_175 ) ;
V_14 = F_4 ( V_170 . V_172 ) ;
if ( ! V_14 )
return - V_17 ;
V_137 = V_14 -> V_95 ;
F_17 ( V_14 ) ;
F_104 ( V_137 , V_170 . V_5 , V_170 . V_175 ) ;
return 0 ;
}
long F_105 ( unsigned long V_150 )
{
struct V_12 * V_14 ;
struct V_176 V_170 ;
if ( F_91 ( & V_170 , ( void V_154 * ) V_150 , sizeof( V_170 ) ) )
return - V_40 ;
V_14 = F_4 ( V_170 . V_172 ) ;
if ( V_14 ) {
memcpy ( & V_170 . V_177 , & V_14 -> V_102 , sizeof( V_14 -> V_102 ) ) ;
F_17 ( V_14 ) ;
} else {
memset ( & V_170 . V_177 , 0 , sizeof( V_14 -> V_102 ) ) ;
}
if ( F_93 ( ( void V_154 * ) V_150 , & V_170 , sizeof( V_170 ) ) )
return - V_40 ;
return 0 ;
}
int F_106 ( unsigned long V_150 )
{
struct V_12 * V_14 ;
struct V_178 V_170 ;
int V_50 = 0 ;
F_59 ( V_179 ) ;
if ( F_91 ( & V_170 , ( void V_154 * ) V_150 , sizeof( V_170 ) ) )
return - V_40 ;
F_58 ( V_76 , L_21 , V_170 . V_180 , V_170 . V_172 , V_170 . V_181 ) ;
V_14 = F_4 ( V_170 . V_172 ) ;
if ( ! V_14 ) {
V_14 = F_10 ( V_170 . V_172 ) ;
if ( F_14 ( V_14 ) )
return F_107 ( V_14 ) ;
}
switch ( V_170 . V_180 ) {
case V_182 :
if ( V_170 . V_183 < - 1 || V_170 . V_183 >= V_184 ||
V_170 . V_181 < - 1 || V_170 . V_181 >= V_185 ||
( V_170 . V_181 >= 0 && ! V_120 [ V_170 . V_181 ] ) ) {
V_50 = - V_17 ;
} else {
V_14 -> V_186 = V_170 . V_181 ;
V_14 -> V_187 = V_170 . V_183 ;
F_87 ( V_14 ) ;
}
break;
case V_188 :
V_14 -> V_189 = V_7 -> V_190 ;
break;
case V_191 :
V_14 -> V_192 = V_170 . V_181 & 3 ;
break;
default:
V_50 = - V_17 ;
}
F_17 ( V_14 ) ;
return V_50 ;
}
