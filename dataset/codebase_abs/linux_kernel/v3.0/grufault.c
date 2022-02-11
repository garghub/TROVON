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
if ( F_30
( V_7 , V_7 -> V_8 , V_5 , 1 , V_34 , 0 , & V_36 , NULL ) <= 0 )
return - V_39 ;
* V_1 = F_31 ( V_36 ) ;
F_32 ( V_36 ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_6 , unsigned long V_5 ,
int V_34 , unsigned long * V_1 , int * V_35 )
{
T_1 * V_40 ;
T_2 * V_41 ;
T_3 * V_42 ;
T_4 V_43 ;
V_40 = F_34 ( V_6 -> V_44 , V_5 ) ;
if ( F_35 ( F_36 ( * V_40 ) ) )
goto V_18;
V_42 = F_37 ( V_40 , V_5 ) ;
if ( F_35 ( F_38 ( * V_42 ) ) )
goto V_18;
V_41 = F_39 ( V_42 , V_5 ) ;
if ( F_35 ( F_40 ( * V_41 ) ) )
goto V_18;
#ifdef F_41
if ( F_35 ( F_42 ( * V_41 ) ) )
V_43 = * ( T_4 * ) V_41 ;
else
#endif
V_43 = * F_43 ( V_41 , V_5 ) ;
if ( F_35 ( ! F_44 ( V_43 ) ||
( V_34 && ( ! F_45 ( V_43 ) || ! F_46 ( V_43 ) ) ) ) )
return 1 ;
* V_1 = F_47 ( V_43 ) << V_38 ;
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
int V_34 , int V_45 , unsigned long * V_46 , int * V_35 )
{
struct V_13 * V_8 = V_14 -> V_47 ;
struct V_4 * V_6 ;
unsigned long V_1 ;
int V_48 , V_49 ;
V_6 = F_3 ( V_8 , V_5 ) ;
if ( ! V_6 )
goto V_50;
F_49 () ;
V_48 = F_33 ( V_6 , V_5 , V_34 , & V_1 , & V_49 ) ;
if ( V_48 ) {
if ( V_45 )
goto V_51;
if ( F_27 ( V_6 , V_5 , V_34 , & V_1 , & V_49 ) )
goto V_50;
}
if ( F_1 ( V_1 ) )
goto V_50;
V_1 = V_1 & ~ ( ( 1UL << V_49 ) - 1 ) ;
* V_46 = F_50 ( V_1 ) ;
* V_35 = V_49 ;
return V_52 ;
V_50:
return V_53 ;
V_51:
return V_54 ;
}
static void F_51 ( struct V_55 * V_56 )
{
if ( F_35 ( V_56 ) ) {
V_56 -> V_57 = 0 ;
F_26 ( V_56 ) ;
}
}
static void F_52 ( struct V_23 * V_24 ,
struct V_12 * V_14 , int V_45 ,
unsigned long V_58 , int V_59 , int V_34 ,
unsigned char V_60 ,
struct V_61 * V_62 ,
struct V_55 * V_56 )
{
unsigned long V_5 = 0 , V_46 ;
int V_48 , V_35 ;
if ( V_56 -> V_63 != V_64 )
return;
if ( V_58 == V_56 -> V_65 )
V_5 = V_58 + V_66 * V_56 -> V_67 - 1 ;
else if ( V_58 == V_56 -> V_68 )
V_5 = V_58 + ( 1 << V_56 -> V_69 ) * V_56 -> V_70 - 1 ;
V_58 &= V_71 ;
V_5 &= V_71 ;
V_5 = F_53 ( V_5 , V_58 + V_60 * V_72 ) ;
while ( V_5 > V_58 ) {
V_48 = F_48 ( V_14 , V_5 , V_34 , V_45 , & V_46 , & V_35 ) ;
if ( V_48 || F_54 ( V_62 , V_46 , V_73 , V_5 , V_59 , V_34 ,
F_55 ( V_35 ) ) )
return;
F_56 ( V_74 ,
L_1 ,
V_45 ? L_2 : L_3 , V_24 -> V_75 , V_14 , V_62 ,
V_5 , V_59 , V_34 , V_35 , V_46 ) ;
V_5 -= V_72 ;
F_57 ( V_76 ) ;
}
}
static int F_58 ( struct V_23 * V_24 ,
struct V_12 * V_14 ,
struct V_61 * V_62 ,
struct V_19 * V_20 )
{
struct V_55 * V_56 = NULL ;
unsigned char V_60 = V_14 -> V_77 ;
int V_35 = 0 , V_59 , V_34 , V_48 , V_45 = ! V_20 , V_78 ;
unsigned long V_46 = 0 , V_5 = 0 ;
if ( F_35 ( V_60 ) ) {
V_56 = F_59 ( V_62 ) ;
F_23 ( V_56 ) ;
}
if ( V_62 -> V_79 != V_80 ) {
F_26 ( V_62 ) ;
F_60 () ;
if ( V_62 -> V_79 != V_80 )
goto V_81;
F_57 ( V_82 ) ;
}
if ( V_62 -> V_83 == V_84 )
goto V_85;
if ( V_62 -> V_83 == V_86 && V_20 )
goto V_87;
V_34 = ( V_62 -> V_88 & V_89 ) != 0 ;
V_5 = V_62 -> V_90 ;
V_59 = V_62 -> V_91 ;
V_78 = V_62 -> V_78 ;
if ( V_59 == 0 )
goto V_92;
F_49 () ;
if ( F_61 ( & V_14 -> V_93 -> V_94 ) )
goto V_95;
V_48 = F_48 ( V_14 , V_5 , V_34 , V_45 , & V_46 , & V_35 ) ;
if ( V_48 == V_53 )
goto V_96;
if ( V_48 == V_54 )
goto V_97;
if ( ! ( V_14 -> V_98 & F_62 ( V_35 ) ) ) {
V_14 -> V_98 |= F_62 ( V_35 ) ;
if ( V_45 || ! F_63 ( V_14 ) ) {
V_14 -> V_99 = 1 ;
goto V_97;
}
}
if ( F_35 ( V_56 ) && V_35 == V_38 ) {
F_52 ( V_24 , V_14 , V_45 , V_5 , V_59 , V_34 , V_60 , V_62 , V_56 ) ;
F_51 ( V_56 ) ;
}
F_19 ( V_20 ) ;
V_14 -> V_100 . V_101 ++ ;
F_64 ( V_62 , V_46 , V_73 , V_5 , V_59 , V_34 ,
F_55 ( V_35 ) ) ;
F_56 ( V_74 ,
L_4
L_5 ,
V_45 ? L_2 : L_3 , V_24 -> V_75 , V_14 , V_62 , V_5 , V_59 ,
V_78 , V_34 , V_35 , V_46 ) ;
F_57 ( V_102 ) ;
return 0 ;
V_92:
F_57 ( V_103 ) ;
F_56 ( V_74 , L_6 , V_62 , V_5 ) ;
if ( ! V_20 )
F_65 ( V_62 ) ;
else
F_26 ( V_62 ) ;
F_51 ( V_56 ) ;
return - V_104 ;
V_97:
F_65 ( V_62 ) ;
F_51 ( V_56 ) ;
F_57 ( V_105 ) ;
F_56 ( V_74 , L_7 , V_62 , V_5 ) ;
return 1 ;
V_87:
F_26 ( V_62 ) ;
F_51 ( V_56 ) ;
F_57 ( V_106 ) ;
F_56 ( V_74 , L_8 , V_62 , V_62 -> V_83 ) ;
return 0 ;
V_81:
F_26 ( V_62 ) ;
F_51 ( V_56 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
F_57 ( V_107 ) ;
F_56 ( V_74 , L_9 ,
V_62 , V_62 -> V_79 , V_62 -> V_83 ) ;
return 0 ;
V_85:
F_26 ( V_62 ) ;
F_51 ( V_56 ) ;
if ( V_20 )
F_26 ( V_20 ) ;
F_57 ( V_108 ) ;
F_56 ( V_74 , L_10 , V_62 , V_62 -> V_83 ) ;
return 0 ;
V_96:
F_66 ( V_62 ) ;
F_51 ( V_56 ) ;
F_57 ( V_109 ) ;
F_56 ( V_74 , L_11 , V_62 , V_5 ) ;
return - V_39 ;
V_95:
if ( ! V_20 )
F_65 ( V_62 ) ;
else
F_26 ( V_62 ) ;
F_51 ( V_56 ) ;
F_57 ( V_110 ) ;
F_56 ( V_74 , L_12 ,
V_62 , V_5 ) ;
return 1 ;
}
static T_5 F_67 ( int V_111 , int V_112 )
{
struct V_23 * V_24 ;
struct V_25 V_26 , V_27 ;
struct V_12 * V_14 ;
struct V_61 * V_62 = NULL ;
struct V_113 * V_114 ;
int V_115 , V_116 ;
F_57 ( V_117 ) ;
V_24 = & V_118 [ V_112 ] -> V_119 [ V_111 ] ;
if ( ! V_24 ) {
F_68 ( V_74 , L_13 ,
F_69 () , V_111 ) ;
return V_120 ;
}
F_20 ( V_24 , & V_26 , & V_27 ) ;
F_56 ( V_74 ,
L_14 ,
F_70 () , V_111 , V_24 -> V_75 ,
V_26 . V_32 [ 0 ] , V_26 . V_32 [ 1 ] ,
V_27 . V_32 [ 0 ] , V_27 . V_32 [ 1 ] ) ;
F_71 (cbrnum, dmap.fault_bits) {
F_57 ( V_121 ) ;
V_114 = V_24 -> V_122 -> V_123 ;
if ( V_114 )
F_72 ( V_114 ) ;
F_56 ( V_74 , L_15 ,
V_24 -> V_75 , V_115 , V_114 ? V_114 -> V_124 : - 1 ) ;
}
F_71 (cbrnum, imap.fault_bits) {
F_57 ( V_125 ) ;
V_62 = F_73 ( V_24 , V_115 ) ;
F_23 ( V_62 ) ;
V_116 = V_62 -> V_116 ;
V_14 = V_24 -> V_126 [ V_116 ] ;
if ( ! V_14 ) {
F_57 ( V_127 ) ;
continue;
}
V_14 -> V_100 . V_128 ++ ;
if ( ! V_14 -> V_99 &&
F_74 ( & V_14 -> V_47 -> V_15 ) ) {
F_58 ( V_24 , V_14 , V_62 , NULL ) ;
F_9 ( & V_14 -> V_47 -> V_15 ) ;
} else {
F_65 ( V_62 ) ;
F_57 ( V_129 ) ;
}
}
return V_130 ;
}
T_5 F_75 ( int V_131 , void * V_132 )
{
return F_67 ( 0 , F_76 () ) ;
}
T_5 F_77 ( int V_131 , void * V_132 )
{
return F_67 ( 1 , F_76 () ) ;
}
T_5 F_78 ( int V_131 , void * V_132 )
{
int V_112 ;
F_79 (blade) {
if ( F_80 ( V_112 ) )
continue;
F_67 ( 0 , V_112 ) ;
F_67 ( 1 , V_112 ) ;
}
return V_130 ;
}
static int F_81 ( struct V_12 * V_14 ,
struct V_61 * V_62 ,
void * V_133 )
{
struct V_134 * V_135 = V_14 -> V_93 ;
int V_48 ;
V_14 -> V_100 . V_136 ++ ;
while ( 1 ) {
F_82 ( V_135 -> V_137 ,
F_61 ( & V_135 -> V_94 ) == 0 ) ;
F_23 ( V_62 ) ;
V_48 = F_58 ( V_14 -> V_138 , V_14 , V_62 , V_133 ) ;
if ( V_48 <= 0 )
return V_48 ;
F_57 ( V_139 ) ;
}
}
int F_83 ( unsigned long V_133 )
{
struct V_61 * V_62 ;
struct V_12 * V_14 ;
void * V_20 ;
int V_140 , V_115 , V_48 = - V_17 ;
F_57 ( V_141 ) ;
V_140 = F_84 ( ( void * ) V_133 ) ;
if ( ( V_133 & ( V_142 - 1 ) ) || V_140 >= V_143 )
return - V_17 ;
V_14 = F_4 ( V_133 ) ;
if ( ! V_14 )
return - V_17 ;
F_56 ( V_74 , L_16 , V_133 , V_14 -> V_138 ? V_14 -> V_138 -> V_75 : - 1 , V_14 ) ;
if ( V_140 >= V_14 -> V_144 * V_145 )
goto exit;
F_85 ( V_14 ) ;
if ( V_14 -> V_138 && V_14 -> V_99 ) {
V_14 -> V_99 = 0 ;
F_63 ( V_14 ) ;
}
V_48 = - V_104 ;
V_115 = F_86 ( V_14 , V_140 ) ;
if ( V_14 -> V_138 ) {
V_62 = F_73 ( V_14 -> V_138 , V_115 ) ;
V_20 = F_87 ( V_14 -> V_138 -> V_146 ,
V_14 -> V_147 , V_140 ) ;
V_48 = F_81 ( V_14 , V_62 , V_20 ) ;
}
exit:
F_17 ( V_14 ) ;
return V_48 ;
}
int F_88 ( unsigned long V_148 )
{
struct V_149 V_150 ;
struct V_55 * V_56 ;
struct V_12 * V_14 ;
int V_140 , V_115 , V_48 ;
F_57 ( V_151 ) ;
if ( F_89 ( & V_150 , ( void V_152 * ) V_148 , sizeof( V_150 ) ) )
return - V_39 ;
V_14 = F_4 ( V_150 . V_133 ) ;
if ( ! V_14 )
return - V_17 ;
F_56 ( V_74 , L_16 , V_150 . V_133 , V_14 -> V_138 ? V_14 -> V_138 -> V_75 : - 1 , V_14 ) ;
V_140 = F_84 ( ( void * ) V_150 . V_133 ) ;
if ( V_140 >= V_14 -> V_144 * V_145 ) {
V_48 = - V_17 ;
} else if ( V_14 -> V_138 ) {
V_115 = F_86 ( V_14 , V_140 ) ;
V_56 = F_90 ( V_14 -> V_138 , V_115 ) ;
F_26 ( V_56 ) ;
F_60 () ;
V_150 . V_153 = V_56 -> V_63 ;
V_150 . V_154 = V_56 -> V_155 ;
V_150 . V_156 = V_56 -> V_156 ;
V_150 . V_157 = V_56 -> V_158 ;
V_150 . V_159 = V_56 -> V_160 ;
V_150 . V_161 = V_56 -> V_161 ;
V_150 . V_57 = V_56 -> V_57 ;
F_51 ( V_56 ) ;
V_48 = 0 ;
} else {
V_48 = - V_104 ;
}
F_17 ( V_14 ) ;
F_56 ( V_74 ,
L_17
L_18 ,
V_150 . V_133 , V_150 . V_153 , V_150 . V_154 , V_150 . V_161 , V_150 . V_57 ,
V_150 . V_156 , V_150 . V_157 , V_150 . V_159 ) ;
if ( ! V_48 && F_91 ( ( void V_152 * ) V_148 , & V_150 , sizeof( V_150 ) ) )
V_48 = - V_39 ;
return V_48 ;
}
static int F_92 ( void )
{
struct V_12 * V_14 ;
struct V_23 * V_24 ;
int V_162 , V_116 ;
if ( ! F_93 ( V_163 ) )
return - V_164 ;
F_94 (gid) {
V_24 = F_95 ( V_162 ) ;
F_96 ( & V_24 -> V_165 ) ;
for ( V_116 = 0 ; V_116 < V_166 ; V_116 ++ ) {
V_14 = V_24 -> V_126 [ V_116 ] ;
if ( V_14 && F_97 ( & V_14 -> V_16 ) ) {
F_98 ( & V_24 -> V_165 ) ;
F_99 ( V_14 , 1 ) ;
F_18 ( & V_14 -> V_16 ) ;
F_96 ( & V_24 -> V_165 ) ;
}
}
F_98 ( & V_24 -> V_165 ) ;
}
return 0 ;
}
int F_100 ( unsigned long V_148 )
{
struct V_12 * V_14 ;
struct V_167 V_168 ;
F_57 ( V_169 ) ;
if ( F_89 ( & V_168 , ( void V_152 * ) V_148 , sizeof( V_168 ) ) )
return - V_39 ;
F_56 ( V_74 , L_19 , V_168 . V_170 ) ;
if ( ! V_168 . V_170 )
return F_92 () ;
V_14 = F_4 ( V_168 . V_170 ) ;
if ( ! V_14 )
return - V_17 ;
if ( V_14 -> V_138 )
F_99 ( V_14 , 1 ) ;
F_17 ( V_14 ) ;
return 0 ;
}
int F_101 ( unsigned long V_148 )
{
struct V_12 * V_14 ;
struct V_171 V_168 ;
struct V_134 * V_135 ;
F_57 ( V_172 ) ;
if ( F_89 ( & V_168 , ( void V_152 * ) V_148 , sizeof( V_168 ) ) )
return - V_39 ;
F_56 ( V_74 , L_20 , V_168 . V_170 ,
V_168 . V_5 , V_168 . V_173 ) ;
V_14 = F_4 ( V_168 . V_170 ) ;
if ( ! V_14 )
return - V_17 ;
V_135 = V_14 -> V_93 ;
F_17 ( V_14 ) ;
F_102 ( V_135 , V_168 . V_5 , V_168 . V_173 ) ;
return 0 ;
}
long F_103 ( unsigned long V_148 )
{
struct V_12 * V_14 ;
struct V_174 V_168 ;
if ( F_89 ( & V_168 , ( void V_152 * ) V_148 , sizeof( V_168 ) ) )
return - V_39 ;
V_14 = F_4 ( V_168 . V_170 ) ;
if ( V_14 ) {
memcpy ( & V_168 . V_175 , & V_14 -> V_100 , sizeof( V_14 -> V_100 ) ) ;
F_17 ( V_14 ) ;
} else {
memset ( & V_168 . V_175 , 0 , sizeof( V_14 -> V_100 ) ) ;
}
if ( F_91 ( ( void V_152 * ) V_148 , & V_168 , sizeof( V_168 ) ) )
return - V_39 ;
return 0 ;
}
int F_104 ( unsigned long V_148 )
{
struct V_12 * V_14 ;
struct V_176 V_168 ;
int V_48 = 0 ;
F_57 ( V_177 ) ;
if ( F_89 ( & V_168 , ( void V_152 * ) V_148 , sizeof( V_168 ) ) )
return - V_39 ;
F_56 ( V_74 , L_21 , V_168 . V_178 , V_168 . V_170 , V_168 . V_179 ) ;
V_14 = F_4 ( V_168 . V_170 ) ;
if ( ! V_14 ) {
V_14 = F_10 ( V_168 . V_170 ) ;
if ( F_14 ( V_14 ) )
return F_105 ( V_14 ) ;
}
switch ( V_168 . V_178 ) {
case V_180 :
if ( V_168 . V_179 < - 1 || V_168 . V_179 >= V_181 || ! V_118 [ V_168 . V_179 ] ||
V_168 . V_182 < - 1 || V_168 . V_182 >= V_183 ) {
V_48 = - V_17 ;
} else {
V_14 -> V_184 = V_168 . V_179 ;
V_14 -> V_185 = V_168 . V_182 ;
F_85 ( V_14 ) ;
}
break;
case V_186 :
V_14 -> V_187 = V_7 -> V_188 ;
break;
case V_189 :
V_14 -> V_190 = V_168 . V_179 & 3 ;
break;
default:
V_48 = - V_17 ;
}
F_17 ( V_14 ) ;
return V_48 ;
}
