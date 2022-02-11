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
T_4 V_44 ;
V_41 = F_34 ( V_6 -> V_45 , V_5 ) ;
if ( F_35 ( F_36 ( * V_41 ) ) )
goto V_18;
V_43 = F_37 ( V_41 , V_5 ) ;
if ( F_35 ( F_38 ( * V_43 ) ) )
goto V_18;
V_42 = F_39 ( V_43 , V_5 ) ;
if ( F_35 ( F_40 ( * V_42 ) ) )
goto V_18;
#ifdef F_41
if ( F_35 ( F_42 ( * V_42 ) ) )
V_44 = * ( T_4 * ) V_42 ;
else
#endif
V_44 = * F_43 ( V_42 , V_5 ) ;
if ( F_35 ( ! F_44 ( V_44 ) ||
( V_34 && ( ! F_45 ( V_44 ) || ! F_46 ( V_44 ) ) ) ) )
return 1 ;
* V_1 = F_47 ( V_44 ) << V_38 ;
#ifdef F_28
* V_35 = F_29 ( V_6 ) ? V_37 : V_38 ;
#else
* V_35 = V_38 ;
#endif
return 0 ;
V_18:
return 1 ;
}
static int F_48 ( struct V_12 * V_14 , unsigned long V_5 ,
int V_34 , int V_46 , unsigned long * V_47 , int * V_35 )
{
struct V_13 * V_8 = V_14 -> V_48 ;
struct V_4 * V_6 ;
unsigned long V_1 ;
int V_49 , V_50 ;
V_6 = F_3 ( V_8 , V_5 ) ;
if ( ! V_6 )
goto V_51;
F_49 () ;
V_49 = F_33 ( V_6 , V_5 , V_34 , & V_1 , & V_50 ) ;
if ( V_49 ) {
if ( V_46 )
goto V_52;
if ( F_27 ( V_6 , V_5 , V_34 , & V_1 , & V_50 ) )
goto V_51;
}
if ( F_1 ( V_1 ) )
goto V_51;
V_1 = V_1 & ~ ( ( 1UL << V_50 ) - 1 ) ;
* V_47 = F_50 ( V_1 ) ;
* V_35 = V_50 ;
return V_53 ;
V_51:
return V_54 ;
V_52:
return V_55 ;
}
static void F_51 ( struct V_56 * V_57 )
{
if ( F_35 ( V_57 ) ) {
V_57 -> V_58 = 0 ;
F_26 ( V_57 ) ;
}
}
static void F_52 ( struct V_23 * V_24 ,
struct V_12 * V_14 , int V_46 ,
unsigned long V_59 , int V_60 , int V_34 ,
unsigned char V_61 ,
struct V_62 * V_63 ,
struct V_56 * V_57 )
{
unsigned long V_5 = 0 , V_47 ;
int V_49 , V_35 ;
if ( V_57 -> V_64 != V_65 )
return;
if ( V_59 == V_57 -> V_66 )
V_5 = V_59 + V_67 * V_57 -> V_68 - 1 ;
else if ( V_59 == V_57 -> V_69 )
V_5 = V_59 + ( 1 << V_57 -> V_70 ) * V_57 -> V_71 - 1 ;
V_59 &= V_72 ;
V_5 &= V_72 ;
V_5 = F_53 ( V_5 , V_59 + V_61 * V_73 ) ;
while ( V_5 > V_59 ) {
V_49 = F_48 ( V_14 , V_5 , V_34 , V_46 , & V_47 , & V_35 ) ;
if ( V_49 || F_54 ( V_63 , V_47 , V_74 , V_5 , V_60 , V_34 ,
F_55 ( V_35 ) ) )
return;
F_56 ( V_75 ,
L_1 ,
V_46 ? L_2 : L_3 , V_24 -> V_76 , V_14 , V_63 ,
V_5 , V_60 , V_34 , V_35 , V_47 ) ;
V_5 -= V_73 ;
F_57 ( V_77 ) ;
}
}
static int F_58 ( struct V_23 * V_24 ,
struct V_12 * V_14 ,
struct V_62 * V_63 ,
struct V_19 * V_20 )
{
struct V_56 * V_57 = NULL ;
unsigned char V_61 = V_14 -> V_78 ;
int V_35 = 0 , V_60 , V_34 , V_49 , V_46 = ! V_20 , V_79 ;
unsigned long V_47 = 0 , V_5 = 0 ;
if ( F_35 ( V_61 ) ) {
V_57 = F_59 ( V_63 ) ;
F_23 ( V_57 ) ;
}
if ( V_63 -> V_80 != V_81 ) {
F_26 ( V_63 ) ;
F_60 () ;
if ( V_63 -> V_80 != V_81 )
goto V_82;
F_57 ( V_83 ) ;
}
if ( V_63 -> V_84 == V_85 )
goto V_86;
if ( V_63 -> V_84 == V_87 && V_20 )
goto V_88;
V_34 = ( V_63 -> V_89 & V_90 ) != 0 ;
V_5 = V_63 -> V_91 ;
V_60 = V_63 -> V_92 ;
V_79 = V_63 -> V_79 ;
if ( V_60 == 0 )
goto V_93;
F_49 () ;
if ( F_61 ( & V_14 -> V_94 -> V_95 ) )
goto V_96;
V_49 = F_48 ( V_14 , V_5 , V_34 , V_46 , & V_47 , & V_35 ) ;
if ( V_49 == V_54 )
goto V_97;
if ( V_49 == V_55 )
goto V_98;
if ( ! ( V_14 -> V_99 & F_62 ( V_35 ) ) ) {
V_14 -> V_99 |= F_62 ( V_35 ) ;
if ( V_46 || ! F_63 ( V_14 ) ) {
V_14 -> V_100 = 1 ;
goto V_98;
}
}
if ( F_35 ( V_57 ) && V_35 == V_38 ) {
F_52 ( V_24 , V_14 , V_46 , V_5 , V_60 , V_34 , V_61 , V_63 , V_57 ) ;
F_51 ( V_57 ) ;
}
F_19 ( V_20 ) ;
V_14 -> V_101 . V_102 ++ ;
F_64 ( V_63 , V_47 , V_74 , V_5 , V_60 , V_34 ,
F_55 ( V_35 ) ) ;
F_56 ( V_75 ,
L_4
L_5 ,
V_46 ? L_2 : L_3 , V_24 -> V_76 , V_14 , V_63 , V_5 , V_60 ,
V_79 , V_34 , V_35 , V_47 ) ;
F_57 ( V_103 ) ;
return 0 ;
V_93:
F_57 ( V_104 ) ;
F_56 ( V_75 , L_6 , V_63 , V_5 ) ;
if ( ! V_20 )
F_65 ( V_63 ) ;
else
F_26 ( V_63 ) ;
F_51 ( V_57 ) ;
return - V_105 ;
V_98:
F_65 ( V_63 ) ;
F_51 ( V_57 ) ;
F_57 ( V_106 ) ;
F_56 ( V_75 , L_7 , V_63 , V_5 ) ;
return 1 ;
V_88:
F_26 ( V_63 ) ;
F_51 ( V_57 ) ;
F_57 ( V_107 ) ;
F_56 ( V_75 , L_8 , V_63 , V_63 -> V_84 ) ;
return 0 ;
V_82:
F_26 ( V_63 ) ;
F_51 ( V_57 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
F_57 ( V_108 ) ;
F_56 ( V_75 , L_9 ,
V_63 , V_63 -> V_80 , V_63 -> V_84 ) ;
return 0 ;
V_86:
F_26 ( V_63 ) ;
F_51 ( V_57 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
F_57 ( V_109 ) ;
F_56 ( V_75 , L_10 , V_63 , V_63 -> V_84 ) ;
return 0 ;
V_97:
F_66 ( V_63 ) ;
F_51 ( V_57 ) ;
F_57 ( V_110 ) ;
F_56 ( V_75 , L_11 , V_63 , V_5 ) ;
return - V_40 ;
V_96:
if ( ! V_20 )
F_65 ( V_63 ) ;
else
F_26 ( V_63 ) ;
F_51 ( V_57 ) ;
F_57 ( V_111 ) ;
F_56 ( V_75 , L_12 ,
V_63 , V_5 ) ;
return 1 ;
}
static T_5 F_67 ( int V_112 , int V_113 )
{
struct V_23 * V_24 ;
struct V_25 V_26 , V_27 ;
struct V_12 * V_14 ;
struct V_62 * V_63 = NULL ;
struct V_114 * V_115 ;
int V_116 , V_117 ;
F_57 ( V_118 ) ;
V_24 = & V_119 [ V_113 ] -> V_120 [ V_112 ] ;
if ( ! V_24 ) {
F_68 ( V_75 , L_13 ,
F_69 () , V_112 ) ;
return V_121 ;
}
F_20 ( V_24 , & V_26 , & V_27 ) ;
F_56 ( V_75 ,
L_14 ,
F_70 () , V_112 , V_24 -> V_76 ,
V_26 . V_32 [ 0 ] , V_26 . V_32 [ 1 ] ,
V_27 . V_32 [ 0 ] , V_27 . V_32 [ 1 ] ) ;
F_71 (cbrnum, dmap.fault_bits) {
F_57 ( V_122 ) ;
V_115 = V_24 -> V_123 -> V_124 ;
if ( V_115 )
F_72 ( V_115 ) ;
F_56 ( V_75 , L_15 ,
V_24 -> V_76 , V_116 , V_115 ? V_115 -> V_125 : - 1 ) ;
}
F_71 (cbrnum, imap.fault_bits) {
F_57 ( V_126 ) ;
V_63 = F_73 ( V_24 , V_116 ) ;
F_23 ( V_63 ) ;
V_117 = V_63 -> V_117 ;
V_14 = V_24 -> V_127 [ V_117 ] ;
if ( ! V_14 ) {
F_57 ( V_128 ) ;
continue;
}
V_14 -> V_101 . V_129 ++ ;
if ( ! V_14 -> V_100 &&
F_74 ( & V_14 -> V_48 -> V_15 ) ) {
F_58 ( V_24 , V_14 , V_63 , NULL ) ;
F_9 ( & V_14 -> V_48 -> V_15 ) ;
} else {
F_65 ( V_63 ) ;
F_57 ( V_130 ) ;
}
}
return V_131 ;
}
T_5 F_75 ( int V_132 , void * V_133 )
{
return F_67 ( 0 , F_76 () ) ;
}
T_5 F_77 ( int V_132 , void * V_133 )
{
return F_67 ( 1 , F_76 () ) ;
}
T_5 F_78 ( int V_132 , void * V_133 )
{
int V_113 ;
F_79 (blade) {
if ( F_80 ( V_113 ) )
continue;
F_67 ( 0 , V_113 ) ;
F_67 ( 1 , V_113 ) ;
}
return V_131 ;
}
static int F_81 ( struct V_12 * V_14 ,
struct V_62 * V_63 ,
void * V_134 )
{
struct V_135 * V_136 = V_14 -> V_94 ;
int V_49 ;
V_14 -> V_101 . V_137 ++ ;
while ( 1 ) {
F_82 ( V_136 -> V_138 ,
F_61 ( & V_136 -> V_95 ) == 0 ) ;
F_23 ( V_63 ) ;
V_49 = F_58 ( V_14 -> V_139 , V_14 , V_63 , V_134 ) ;
if ( V_49 <= 0 )
return V_49 ;
F_57 ( V_140 ) ;
}
}
int F_83 ( unsigned long V_134 )
{
struct V_62 * V_63 ;
struct V_12 * V_14 ;
void * V_20 ;
int V_141 , V_116 , V_49 = - V_17 ;
F_57 ( V_142 ) ;
V_141 = F_84 ( ( void * ) V_134 ) ;
if ( ( V_134 & ( V_143 - 1 ) ) || V_141 >= V_144 )
return - V_17 ;
V_14 = F_4 ( V_134 ) ;
if ( ! V_14 )
return - V_17 ;
F_56 ( V_75 , L_16 , V_134 , V_14 -> V_139 ? V_14 -> V_139 -> V_76 : - 1 , V_14 ) ;
if ( V_141 >= V_14 -> V_145 * V_146 )
goto exit;
F_85 ( V_14 ) ;
if ( V_14 -> V_139 && V_14 -> V_100 ) {
V_14 -> V_100 = 0 ;
F_63 ( V_14 ) ;
}
V_49 = - V_105 ;
V_116 = F_86 ( V_14 , V_141 ) ;
if ( V_14 -> V_139 ) {
V_63 = F_73 ( V_14 -> V_139 , V_116 ) ;
V_20 = F_87 ( V_14 -> V_139 -> V_147 ,
V_14 -> V_148 , V_141 ) ;
V_49 = F_81 ( V_14 , V_63 , V_20 ) ;
}
exit:
F_17 ( V_14 ) ;
return V_49 ;
}
int F_88 ( unsigned long V_149 )
{
struct V_150 V_151 ;
struct V_56 * V_57 ;
struct V_12 * V_14 ;
int V_141 , V_116 , V_49 ;
F_57 ( V_152 ) ;
if ( F_89 ( & V_151 , ( void V_153 * ) V_149 , sizeof( V_151 ) ) )
return - V_40 ;
V_14 = F_4 ( V_151 . V_134 ) ;
if ( ! V_14 )
return - V_17 ;
F_56 ( V_75 , L_16 , V_151 . V_134 , V_14 -> V_139 ? V_14 -> V_139 -> V_76 : - 1 , V_14 ) ;
V_141 = F_84 ( ( void * ) V_151 . V_134 ) ;
if ( V_141 >= V_14 -> V_145 * V_146 ) {
V_49 = - V_17 ;
} else if ( V_14 -> V_139 ) {
V_116 = F_86 ( V_14 , V_141 ) ;
V_57 = F_90 ( V_14 -> V_139 , V_116 ) ;
F_26 ( V_57 ) ;
F_60 () ;
V_151 . V_154 = V_57 -> V_64 ;
V_151 . V_155 = V_57 -> V_156 ;
V_151 . V_157 = V_57 -> V_157 ;
V_151 . V_158 = V_57 -> V_159 ;
V_151 . V_160 = V_57 -> V_161 ;
V_151 . V_162 = V_57 -> V_162 ;
V_151 . V_58 = V_57 -> V_58 ;
F_51 ( V_57 ) ;
V_49 = 0 ;
} else {
V_49 = - V_105 ;
}
F_17 ( V_14 ) ;
F_56 ( V_75 ,
L_17
L_18 ,
V_151 . V_134 , V_151 . V_154 , V_151 . V_155 , V_151 . V_162 , V_151 . V_58 ,
V_151 . V_157 , V_151 . V_158 , V_151 . V_160 ) ;
if ( ! V_49 && F_91 ( ( void V_153 * ) V_149 , & V_151 , sizeof( V_151 ) ) )
V_49 = - V_40 ;
return V_49 ;
}
static int F_92 ( void )
{
struct V_12 * V_14 ;
struct V_23 * V_24 ;
int V_163 , V_117 ;
if ( ! F_93 ( V_164 ) )
return - V_165 ;
F_94 (gid) {
V_24 = F_95 ( V_163 ) ;
F_96 ( & V_24 -> V_166 ) ;
for ( V_117 = 0 ; V_117 < V_167 ; V_117 ++ ) {
V_14 = V_24 -> V_127 [ V_117 ] ;
if ( V_14 && F_97 ( & V_14 -> V_16 ) ) {
F_98 ( & V_24 -> V_166 ) ;
F_99 ( V_14 , 1 ) ;
F_18 ( & V_14 -> V_16 ) ;
F_96 ( & V_24 -> V_166 ) ;
}
}
F_98 ( & V_24 -> V_166 ) ;
}
return 0 ;
}
int F_100 ( unsigned long V_149 )
{
struct V_12 * V_14 ;
struct V_168 V_169 ;
F_57 ( V_170 ) ;
if ( F_89 ( & V_169 , ( void V_153 * ) V_149 , sizeof( V_169 ) ) )
return - V_40 ;
F_56 ( V_75 , L_19 , V_169 . V_171 ) ;
if ( ! V_169 . V_171 )
return F_92 () ;
V_14 = F_4 ( V_169 . V_171 ) ;
if ( ! V_14 )
return - V_17 ;
if ( V_14 -> V_139 )
F_99 ( V_14 , 1 ) ;
F_17 ( V_14 ) ;
return 0 ;
}
int F_101 ( unsigned long V_149 )
{
struct V_12 * V_14 ;
struct V_172 V_169 ;
struct V_135 * V_136 ;
F_57 ( V_173 ) ;
if ( F_89 ( & V_169 , ( void V_153 * ) V_149 , sizeof( V_169 ) ) )
return - V_40 ;
F_56 ( V_75 , L_20 , V_169 . V_171 ,
V_169 . V_5 , V_169 . V_174 ) ;
V_14 = F_4 ( V_169 . V_171 ) ;
if ( ! V_14 )
return - V_17 ;
V_136 = V_14 -> V_94 ;
F_17 ( V_14 ) ;
F_102 ( V_136 , V_169 . V_5 , V_169 . V_174 ) ;
return 0 ;
}
long F_103 ( unsigned long V_149 )
{
struct V_12 * V_14 ;
struct V_175 V_169 ;
if ( F_89 ( & V_169 , ( void V_153 * ) V_149 , sizeof( V_169 ) ) )
return - V_40 ;
V_14 = F_4 ( V_169 . V_171 ) ;
if ( V_14 ) {
memcpy ( & V_169 . V_176 , & V_14 -> V_101 , sizeof( V_14 -> V_101 ) ) ;
F_17 ( V_14 ) ;
} else {
memset ( & V_169 . V_176 , 0 , sizeof( V_14 -> V_101 ) ) ;
}
if ( F_91 ( ( void V_153 * ) V_149 , & V_169 , sizeof( V_169 ) ) )
return - V_40 ;
return 0 ;
}
int F_104 ( unsigned long V_149 )
{
struct V_12 * V_14 ;
struct V_177 V_169 ;
int V_49 = 0 ;
F_57 ( V_178 ) ;
if ( F_89 ( & V_169 , ( void V_153 * ) V_149 , sizeof( V_169 ) ) )
return - V_40 ;
F_56 ( V_75 , L_21 , V_169 . V_179 , V_169 . V_171 , V_169 . V_180 ) ;
V_14 = F_4 ( V_169 . V_171 ) ;
if ( ! V_14 ) {
V_14 = F_10 ( V_169 . V_171 ) ;
if ( F_14 ( V_14 ) )
return F_105 ( V_14 ) ;
}
switch ( V_169 . V_179 ) {
case V_181 :
if ( V_169 . V_182 < - 1 || V_169 . V_182 >= V_183 ||
V_169 . V_180 < - 1 || V_169 . V_180 >= V_184 ||
( V_169 . V_180 >= 0 && ! V_119 [ V_169 . V_180 ] ) ) {
V_49 = - V_17 ;
} else {
V_14 -> V_185 = V_169 . V_180 ;
V_14 -> V_186 = V_169 . V_182 ;
F_85 ( V_14 ) ;
}
break;
case V_187 :
V_14 -> V_188 = V_7 -> V_189 ;
break;
case V_190 :
V_14 -> V_191 = V_169 . V_180 & 3 ;
break;
default:
V_49 = - V_17 ;
}
F_17 ( V_14 ) ;
return V_49 ;
}
