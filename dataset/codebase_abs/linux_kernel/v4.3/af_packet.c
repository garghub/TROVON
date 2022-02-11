static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
struct V_6 * V_7 ;
int V_8 = V_9 ;
if ( F_2 ( ! F_3 ( V_4 ) ||
! F_4 ( V_4 ) ) )
goto V_10;
V_5 = F_5 ( V_2 ) ;
if ( F_6 ( V_2 , V_5 ) &&
F_7 ( V_2 ) )
goto V_10;
V_7 = F_8 ( V_4 , V_2 ) ;
F_9 () ;
F_10 ( V_4 , V_7 , F_11 () ) ;
if ( ! F_12 ( V_7 ) )
V_8 = F_13 ( V_2 , V_4 , V_7 , false ) ;
F_14 ( V_4 , V_7 ) ;
F_15 () ;
if ( ! F_16 ( V_8 ) )
F_17 ( V_2 ) ;
return V_8 ;
V_10:
F_18 ( & V_4 -> V_11 ) ;
F_17 ( V_2 ) ;
return V_12 ;
}
static struct V_3 * F_19 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
F_20 () ;
V_4 = F_21 ( V_14 -> V_15 ) ;
if ( F_22 ( V_4 ) )
F_23 ( V_4 ) ;
F_24 () ;
return V_4 ;
}
static void F_25 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
F_26 ( V_14 -> V_15 , V_4 ) ;
}
static void F_27 ( struct V_13 * V_14 )
{
F_28 ( V_14 -> V_15 , NULL ) ;
}
static bool F_29 ( const struct V_13 * V_14 )
{
return V_14 -> V_16 == F_1 ;
}
static T_2 F_30 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
return ( T_2 ) F_31 () % V_4 -> V_17 ;
}
static void F_32 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
const struct V_18 * V_19 = V_4 -> V_20 ;
T_2 V_21 ;
if ( V_19 -> V_22 ) {
V_21 = V_19 -> V_22 ( V_4 , V_2 , NULL ,
F_30 ) ;
V_21 = F_33 ( V_4 , V_21 ) ;
} else {
V_21 = F_30 ( V_4 , V_2 ) ;
}
F_34 ( V_2 , V_21 ) ;
}
static void F_35 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
if ( ! V_14 -> V_25 ) {
if ( V_14 -> V_26 )
F_37 ( V_24 , V_14 ) ;
else
F_38 ( & V_14 -> V_27 ) ;
F_39 ( V_24 ) ;
V_14 -> V_25 = 1 ;
}
}
static void F_40 ( struct V_23 * V_24 , bool V_28 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
V_14 -> V_25 = 0 ;
if ( V_14 -> V_26 )
F_41 ( V_24 , V_14 ) ;
else
F_42 ( & V_14 -> V_27 ) ;
F_43 ( V_24 ) ;
if ( V_28 ) {
F_44 ( & V_14 -> V_29 ) ;
F_45 () ;
F_46 ( & V_14 -> V_29 ) ;
}
}
static void F_47 ( struct V_23 * V_24 , bool V_28 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
if ( V_14 -> V_25 )
F_40 ( V_24 , V_28 ) ;
}
static inline struct V_30 * T_3 F_48 ( void * V_31 )
{
if ( F_49 ( V_31 ) )
return F_50 ( V_31 ) ;
return F_51 ( V_31 ) ;
}
static void F_52 ( struct V_13 * V_14 , void * V_32 , int V_33 )
{
union V_34 V_35 ;
V_35 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_40 = V_33 ;
F_53 ( F_48 ( & V_35 . V_39 -> V_40 ) ) ;
break;
case V_41 :
V_35 . V_42 -> V_40 = V_33 ;
F_53 ( F_48 ( & V_35 . V_42 -> V_40 ) ) ;
break;
case V_43 :
default:
F_54 ( 1 , L_1 ) ;
F_55 () ;
}
F_56 () ;
}
static int F_57 ( struct V_13 * V_14 , void * V_32 )
{
union V_34 V_35 ;
F_58 () ;
V_35 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_38 :
F_53 ( F_48 ( & V_35 . V_39 -> V_40 ) ) ;
return V_35 . V_39 -> V_40 ;
case V_41 :
F_53 ( F_48 ( & V_35 . V_42 -> V_40 ) ) ;
return V_35 . V_42 -> V_40 ;
case V_43 :
default:
F_54 ( 1 , L_1 ) ;
F_55 () ;
return 0 ;
}
}
static T_4 F_59 ( struct V_1 * V_2 , struct V_44 * V_45 ,
unsigned int V_46 )
{
struct V_47 * V_48 = F_60 ( V_2 ) ;
if ( V_48 &&
( V_46 & V_49 ) &&
F_61 ( V_48 -> V_50 , V_45 ) )
return V_51 ;
if ( F_61 ( V_2 -> V_52 , V_45 ) )
return V_53 ;
return 0 ;
}
static T_4 F_62 ( struct V_13 * V_14 , void * V_32 ,
struct V_1 * V_2 )
{
union V_34 V_35 ;
struct V_44 V_45 ;
T_4 V_54 ;
if ( ! ( V_54 = F_59 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
return 0 ;
V_35 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_56 = V_45 . V_57 ;
V_35 . V_39 -> V_58 = V_45 . V_59 / V_60 ;
break;
case V_41 :
V_35 . V_42 -> V_56 = V_45 . V_57 ;
V_35 . V_42 -> V_61 = V_45 . V_59 ;
break;
case V_43 :
default:
F_54 ( 1 , L_1 ) ;
F_55 () ;
}
F_53 ( F_48 ( & V_35 . V_39 -> V_56 ) ) ;
F_56 () ;
return V_54 ;
}
static void * F_63 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
unsigned int V_64 ,
int V_33 )
{
unsigned int V_65 , V_66 ;
union V_34 V_35 ;
V_65 = V_64 / V_63 -> V_67 ;
V_66 = V_64 % V_63 -> V_67 ;
V_35 . V_36 = V_63 -> V_68 [ V_65 ] . V_69 +
( V_66 * V_63 -> V_70 ) ;
if ( V_33 != F_57 ( V_14 , V_35 . V_36 ) )
return NULL ;
return V_35 . V_36 ;
}
static void * F_64 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
return F_63 ( V_14 , V_63 , V_63 -> V_71 , V_33 ) ;
}
static void F_65 ( struct V_72 * V_73 )
{
F_66 ( & V_73 -> V_74 ) ;
}
static void F_67 ( struct V_13 * V_14 ,
struct V_75 * V_76 )
{
struct V_72 * V_73 ;
V_73 = F_68 ( & V_14 -> V_77 ) ;
F_69 ( & V_76 -> V_78 ) ;
V_73 -> V_79 = 1 ;
F_70 ( & V_76 -> V_78 ) ;
F_65 ( V_73 ) ;
}
static void F_71 ( struct V_13 * V_14 ,
struct V_72 * V_73 ,
void (* F_72) ( unsigned long ) )
{
F_73 ( & V_73 -> V_74 ) ;
V_73 -> V_74 . V_80 = ( long ) V_14 ;
V_73 -> V_74 . V_81 = F_72 ;
V_73 -> V_74 . V_82 = V_83 ;
}
static void F_74 ( struct V_13 * V_14 )
{
struct V_72 * V_73 ;
V_73 = F_68 ( & V_14 -> V_77 ) ;
F_71 ( V_14 , V_73 , V_84 ) ;
}
static int F_75 ( struct V_13 * V_14 ,
int V_85 )
{
struct V_3 * V_4 ;
unsigned int V_86 = 0 , V_87 = 0 , div = 0 , V_88 = 0 ;
struct V_89 V_90 ;
int V_91 ;
T_5 V_92 ;
F_76 () ;
V_4 = F_77 ( F_78 ( & V_14 -> V_24 ) , V_14 -> V_93 ) ;
if ( F_2 ( ! V_4 ) ) {
F_79 () ;
return V_94 ;
}
V_91 = F_80 ( V_4 , & V_90 ) ;
V_92 = F_81 ( & V_90 ) ;
F_79 () ;
if ( ! V_91 ) {
if ( V_92 < V_95 || V_92 == V_96 ) {
return V_94 ;
} else {
V_87 = 1 ;
div = V_92 / 1000 ;
}
}
V_86 = ( V_85 * 8 ) / ( 1024 * 1024 ) ;
if ( div )
V_86 /= div ;
V_88 = V_86 * V_87 ;
if ( div )
return V_88 + 1 ;
return V_88 ;
}
static void F_82 ( struct V_72 * V_97 ,
union V_98 * V_99 )
{
V_97 -> V_100 = V_99 -> V_101 . V_102 ;
}
static void F_83 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
struct V_103 * V_68 ,
union V_98 * V_99 )
{
struct V_72 * V_97 = F_68 ( V_63 ) ;
struct V_104 * V_105 ;
memset ( V_97 , 0x0 , sizeof( * V_97 ) ) ;
V_97 -> V_106 = 1 ;
V_97 -> V_107 = V_68 ;
V_105 = (struct V_104 * ) V_68 [ 0 ] . V_69 ;
V_97 -> V_108 = V_68 [ 0 ] . V_69 ;
V_97 -> V_109 = V_99 -> V_101 . V_110 ;
V_97 -> V_111 = V_99 -> V_101 . V_112 ;
V_97 -> V_113 = V_14 -> V_114 ;
V_97 -> V_115 = V_14 -> V_37 ;
V_97 -> V_116 = 0 ;
V_14 -> V_117 . V_118 . V_119 = 0 ;
if ( V_99 -> V_101 . V_120 )
V_97 -> V_121 = V_99 -> V_101 . V_120 ;
else
V_97 -> V_121 = F_75 ( V_14 ,
V_99 -> V_101 . V_110 ) ;
V_97 -> V_122 = F_84 ( V_97 -> V_121 ) ;
V_97 -> V_123 = V_99 -> V_101 . V_124 ;
V_97 -> V_125 = V_97 -> V_109 - F_85 ( V_97 -> V_123 ) ;
F_82 ( V_97 , V_99 ) ;
F_74 ( V_14 ) ;
F_86 ( V_97 , V_105 ) ;
}
static void F_87 ( struct V_72 * V_73 )
{
F_88 ( & V_73 -> V_74 ,
V_83 + V_73 -> V_122 ) ;
V_73 -> V_116 = V_73 -> V_126 ;
}
static void V_84 ( unsigned long V_80 )
{
struct V_13 * V_14 = (struct V_13 * ) V_80 ;
struct V_72 * V_73 = F_68 ( & V_14 -> V_77 ) ;
unsigned int V_127 ;
struct V_104 * V_105 ;
F_46 ( & V_14 -> V_24 . V_128 . V_78 ) ;
V_127 = F_89 ( V_73 ) ;
V_105 = F_90 ( V_73 ) ;
if ( F_2 ( V_73 -> V_79 ) )
goto V_129;
if ( F_91 ( V_105 ) ) {
while ( F_92 ( & V_73 -> V_130 ) ) {
F_93 () ;
}
}
if ( V_73 -> V_116 == V_73 -> V_126 ) {
if ( ! V_127 ) {
if ( ! F_91 ( V_105 ) ) {
goto V_131;
}
F_94 ( V_73 , V_14 , V_132 ) ;
if ( ! F_95 ( V_73 , V_14 ) )
goto V_131;
else
goto V_129;
} else {
if ( F_96 ( V_73 , V_105 ) ) {
goto V_131;
} else {
F_86 ( V_73 , V_105 ) ;
goto V_129;
}
}
}
V_131:
F_87 ( V_73 ) ;
V_129:
F_44 ( & V_14 -> V_24 . V_128 . V_78 ) ;
}
static void F_97 ( struct V_72 * V_133 ,
struct V_104 * V_134 , T_4 V_33 )
{
#if V_135 == 1
T_6 * V_136 , * V_137 ;
V_136 = ( T_6 * ) V_134 ;
V_136 += V_138 ;
V_137 = ( T_6 * ) F_98 ( ( unsigned long ) V_133 -> V_139 ) ;
for (; V_136 < V_137 ; V_136 += V_138 )
F_53 ( F_48 ( V_136 ) ) ;
F_56 () ;
#endif
F_99 ( V_134 ) = V_33 ;
#if V_135 == 1
V_136 = ( T_6 * ) V_134 ;
F_53 ( F_48 ( V_136 ) ) ;
F_56 () ;
#endif
}
static void F_100 ( struct V_72 * V_133 ,
struct V_104 * V_134 ,
struct V_13 * V_14 , unsigned int V_140 )
{
T_4 V_33 = V_141 | V_140 ;
struct V_142 * V_143 ;
struct V_144 * V_39 = & V_134 -> V_145 . V_146 ;
struct V_23 * V_24 = & V_14 -> V_24 ;
if ( V_14 -> V_117 . V_118 . V_147 )
V_33 |= V_148 ;
V_143 = (struct V_142 * ) V_133 -> V_149 ;
V_143 -> V_150 = 0 ;
if ( F_91 ( V_134 ) ) {
V_39 -> V_151 . V_152 = V_143 -> V_56 ;
V_39 -> V_151 . V_153 = V_143 -> V_61 ;
} else {
struct V_44 V_45 ;
F_101 ( & V_45 ) ;
V_39 -> V_151 . V_152 = V_45 . V_57 ;
V_39 -> V_151 . V_153 = V_45 . V_59 ;
}
F_56 () ;
F_97 ( V_133 , V_134 , V_33 ) ;
V_24 -> V_154 ( V_24 ) ;
V_133 -> V_126 = F_102 ( V_133 ) ;
}
static void F_103 ( struct V_72 * V_73 )
{
V_73 -> V_155 = 0 ;
}
static void F_86 ( struct V_72 * V_133 ,
struct V_104 * V_134 )
{
struct V_44 V_45 ;
struct V_144 * V_39 = & V_134 -> V_145 . V_146 ;
F_58 () ;
F_104 ( V_134 ) = V_133 -> V_106 ++ ;
F_91 ( V_134 ) = 0 ;
F_105 ( V_134 ) = F_85 ( V_133 -> V_123 ) ;
F_101 ( & V_45 ) ;
V_39 -> V_156 . V_152 = V_45 . V_57 ;
V_39 -> V_156 . V_153 = V_45 . V_59 ;
V_133 -> V_108 = ( char * ) V_134 ;
V_133 -> V_157 = V_133 -> V_108 + F_85 ( V_133 -> V_123 ) ;
F_106 ( V_134 ) = ( T_4 ) F_85 ( V_133 -> V_123 ) ;
F_107 ( V_134 ) = V_158 ;
V_134 -> V_115 = V_133 -> V_115 ;
V_133 -> V_149 = V_133 -> V_157 ;
V_133 -> V_139 = V_133 -> V_108 + V_133 -> V_109 ;
F_103 ( V_133 ) ;
F_87 ( V_133 ) ;
F_56 () ;
}
static void F_108 ( struct V_72 * V_73 ,
struct V_13 * V_14 )
{
V_73 -> V_155 = 1 ;
V_14 -> V_117 . V_118 . V_119 ++ ;
}
static void * F_95 ( struct V_72 * V_73 ,
struct V_13 * V_14 )
{
struct V_104 * V_105 ;
F_58 () ;
V_105 = F_90 ( V_73 ) ;
if ( V_141 & F_99 ( V_105 ) ) {
F_108 ( V_73 , V_14 ) ;
return NULL ;
}
F_86 ( V_73 , V_105 ) ;
return ( void * ) V_73 -> V_157 ;
}
static void F_94 ( struct V_72 * V_73 ,
struct V_13 * V_14 , unsigned int V_33 )
{
struct V_104 * V_105 = F_90 ( V_73 ) ;
if ( F_22 ( V_159 == F_99 ( V_105 ) ) ) {
if ( ! ( V_33 & V_132 ) ) {
while ( F_92 ( & V_73 -> V_130 ) ) {
F_93 () ;
}
}
F_100 ( V_73 , V_105 , V_14 , V_33 ) ;
return;
}
}
static int F_96 ( struct V_72 * V_73 ,
struct V_104 * V_105 )
{
return V_141 & F_99 ( V_105 ) ;
}
static int F_89 ( struct V_72 * V_73 )
{
return V_73 -> V_155 ;
}
static void F_109 ( struct V_62 * V_63 )
{
struct V_72 * V_73 = F_68 ( V_63 ) ;
F_110 ( & V_73 -> V_130 ) ;
}
static void F_111 ( struct V_72 * V_73 ,
struct V_142 * V_160 )
{
V_160 -> V_161 . V_162 = F_112 ( V_73 -> V_2 ) ;
}
static void F_113 ( struct V_72 * V_73 ,
struct V_142 * V_160 )
{
V_160 -> V_161 . V_162 = 0 ;
}
static void F_114 ( struct V_72 * V_73 ,
struct V_142 * V_160 )
{
if ( F_115 ( V_73 -> V_2 ) ) {
V_160 -> V_161 . V_163 = F_116 ( V_73 -> V_2 ) ;
V_160 -> V_161 . V_164 = F_117 ( V_73 -> V_2 -> V_165 ) ;
V_160 -> V_40 = V_166 | V_167 ;
} else {
V_160 -> V_161 . V_163 = 0 ;
V_160 -> V_161 . V_164 = 0 ;
V_160 -> V_40 = V_168 ;
}
}
static void F_118 ( struct V_72 * V_73 ,
struct V_142 * V_160 )
{
V_160 -> V_161 . V_169 = 0 ;
F_114 ( V_73 , V_160 ) ;
if ( V_73 -> V_100 & V_170 )
F_111 ( V_73 , V_160 ) ;
else
F_113 ( V_73 , V_160 ) ;
}
static void F_119 ( char * V_171 ,
struct V_72 * V_73 ,
struct V_104 * V_105 ,
unsigned int V_172 )
{
struct V_142 * V_160 ;
V_160 = (struct V_142 * ) V_171 ;
V_160 -> V_150 = F_120 ( V_172 ) ;
V_73 -> V_149 = V_171 ;
V_73 -> V_157 += F_120 ( V_172 ) ;
F_105 ( V_105 ) += F_120 ( V_172 ) ;
F_91 ( V_105 ) += 1 ;
F_121 ( & V_73 -> V_130 ) ;
F_118 ( V_73 , V_160 ) ;
}
static void * F_122 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 ,
unsigned int V_172
)
{
struct V_72 * V_73 ;
struct V_104 * V_105 ;
char * V_171 , * V_137 ;
V_73 = F_68 ( & V_14 -> V_77 ) ;
V_105 = F_90 ( V_73 ) ;
if ( F_89 ( V_73 ) ) {
if ( F_96 ( V_73 , V_105 ) ) {
return NULL ;
} else {
F_86 ( V_73 , V_105 ) ;
}
}
F_123 () ;
V_171 = V_73 -> V_157 ;
V_73 -> V_2 = V_2 ;
V_137 = ( char * ) V_105 + V_73 -> V_109 ;
if ( V_171 + F_120 ( V_172 ) < V_137 ) {
F_119 ( V_171 , V_73 , V_105 , V_172 ) ;
return ( void * ) V_171 ;
}
F_94 ( V_73 , V_14 , 0 ) ;
V_171 = ( char * ) F_95 ( V_73 , V_14 ) ;
if ( V_171 ) {
V_105 = F_90 ( V_73 ) ;
F_119 ( V_171 , V_73 , V_105 , V_172 ) ;
return ( void * ) V_171 ;
}
return NULL ;
}
static void * F_124 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 , unsigned int V_172 )
{
char * V_171 = NULL ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_171 = F_63 ( V_14 , & V_14 -> V_77 ,
V_14 -> V_77 . V_71 , V_33 ) ;
return V_171 ;
case V_43 :
return F_122 ( V_14 , V_2 , V_33 , V_172 ) ;
default:
F_54 ( 1 , L_2 ) ;
F_55 () ;
return NULL ;
}
}
static void * F_125 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
unsigned int V_173 ,
int V_33 )
{
struct V_72 * V_73 = F_68 ( V_63 ) ;
struct V_104 * V_105 = F_126 ( V_73 , V_173 ) ;
if ( V_33 != F_99 ( V_105 ) )
return NULL ;
return V_105 ;
}
static int F_127 ( struct V_62 * V_63 )
{
unsigned int V_149 ;
if ( V_63 -> V_174 . V_126 )
V_149 = V_63 -> V_174 . V_126 - 1 ;
else
V_149 = V_63 -> V_174 . V_111 - 1 ;
return V_149 ;
}
static void * F_128 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
unsigned int V_175 = F_127 ( V_63 ) ;
return F_125 ( V_14 , V_63 , V_175 , V_33 ) ;
}
static void * F_129 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
if ( V_14 -> V_37 <= V_41 )
return F_130 ( V_14 , V_63 , V_33 ) ;
return F_128 ( V_14 , V_63 , V_33 ) ;
}
static void F_131 ( struct V_13 * V_14 ,
struct V_62 * V_63 )
{
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
return F_132 ( V_63 ) ;
case V_43 :
default:
F_54 ( 1 , L_1 ) ;
F_55 () ;
return;
}
}
static void * F_130 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
unsigned int V_175 = V_63 -> V_71 ? V_63 -> V_71 - 1 : V_63 -> V_176 ;
return F_63 ( V_14 , V_63 , V_175 , V_33 ) ;
}
static void F_132 ( struct V_62 * V_177 )
{
V_177 -> V_71 = V_177 -> V_71 != V_177 -> V_176 ? V_177 -> V_71 + 1 : 0 ;
}
static void F_133 ( struct V_62 * V_63 )
{
F_134 ( * V_63 -> V_178 ) ;
}
static void F_135 ( struct V_62 * V_63 )
{
F_136 ( * V_63 -> V_178 ) ;
}
static unsigned int F_137 ( const struct V_62 * V_63 )
{
unsigned int V_179 = 0 ;
int V_180 ;
if ( V_63 -> V_178 == NULL )
return 0 ;
F_138 (cpu)
V_179 += * F_139 ( V_63 -> V_178 , V_180 ) ;
return V_179 ;
}
static int F_140 ( struct V_13 * V_14 )
{
V_14 -> V_77 . V_178 = NULL ;
V_14 -> V_181 . V_178 = F_141 (unsigned int) ;
if ( F_2 ( V_14 -> V_181 . V_178 == NULL ) )
return - V_182 ;
return 0 ;
}
static void F_142 ( struct V_13 * V_14 )
{
F_143 ( V_14 -> V_181 . V_178 ) ;
}
static bool F_144 ( struct V_13 * V_14 , int V_183 )
{
int V_173 , V_172 ;
V_172 = V_14 -> V_77 . V_176 + 1 ;
V_173 = V_14 -> V_77 . V_71 ;
if ( V_183 )
V_173 += V_172 >> V_183 ;
if ( V_173 >= V_172 )
V_173 -= V_172 ;
return F_63 ( V_14 , & V_14 -> V_77 , V_173 , V_159 ) ;
}
static bool F_145 ( struct V_13 * V_14 , int V_183 )
{
int V_173 , V_172 ;
V_172 = V_14 -> V_77 . V_174 . V_111 ;
V_173 = V_14 -> V_77 . V_174 . V_126 ;
if ( V_183 )
V_173 += V_172 >> V_183 ;
if ( V_173 >= V_172 )
V_173 -= V_172 ;
return F_125 ( V_14 , & V_14 -> V_77 , V_173 , V_159 ) ;
}
static int F_146 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_14 -> V_24 ;
int V_8 = V_184 ;
if ( V_14 -> V_27 . F_72 != V_185 ) {
int V_186 = V_24 -> V_187 - F_92 ( & V_24 -> V_188 )
- ( V_2 ? V_2 -> V_189 : 0 ) ;
if ( V_186 > ( V_24 -> V_187 >> V_190 ) )
return V_191 ;
else if ( V_186 > 0 )
return V_192 ;
else
return V_184 ;
}
if ( V_14 -> V_37 == V_43 ) {
if ( F_145 ( V_14 , V_190 ) )
V_8 = V_191 ;
else if ( F_145 ( V_14 , 0 ) )
V_8 = V_192 ;
} else {
if ( F_144 ( V_14 , V_190 ) )
V_8 = V_191 ;
else if ( F_144 ( V_14 , 0 ) )
V_8 = V_192 ;
}
return V_8 ;
}
static int F_147 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
int V_8 ;
bool V_193 ;
F_69 ( & V_14 -> V_24 . V_128 . V_78 ) ;
V_8 = F_146 ( V_14 , V_2 ) ;
V_193 = V_8 == V_191 ;
if ( V_14 -> V_194 == V_193 )
V_14 -> V_194 = ! V_193 ;
F_70 ( & V_14 -> V_24 . V_128 . V_78 ) ;
return V_8 ;
}
static void F_148 ( struct V_23 * V_24 )
{
F_149 ( & V_24 -> V_195 ) ;
F_150 ( F_92 ( & V_24 -> V_188 ) ) ;
F_150 ( F_92 ( & V_24 -> V_196 ) ) ;
if ( ! F_151 ( V_24 , V_197 ) ) {
F_152 ( L_3 , V_24 ) ;
return;
}
F_153 ( V_24 ) ;
}
static bool F_154 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
T_5 V_198 ;
int V_199 , V_200 = 0 ;
V_198 = F_112 ( V_2 ) ;
for ( V_199 = 0 ; V_199 < V_201 ; V_199 ++ )
if ( V_14 -> V_202 -> V_203 [ V_199 ] == V_198 )
V_200 ++ ;
V_14 -> V_202 -> V_203 [ F_155 () % V_201 ] = V_198 ;
return V_200 > ( V_201 >> 1 ) ;
}
static unsigned int F_156 ( struct V_204 * V_205 ,
struct V_1 * V_2 ,
unsigned int V_206 )
{
return F_157 ( F_112 ( V_2 ) , V_206 ) ;
}
static unsigned int F_158 ( struct V_204 * V_205 ,
struct V_1 * V_2 ,
unsigned int V_206 )
{
unsigned int V_207 = F_159 ( & V_205 -> V_208 ) ;
return V_207 % V_206 ;
}
static unsigned int F_160 ( struct V_204 * V_205 ,
struct V_1 * V_2 ,
unsigned int V_206 )
{
return F_11 () % V_206 ;
}
static unsigned int F_161 ( struct V_204 * V_205 ,
struct V_1 * V_2 ,
unsigned int V_206 )
{
return F_162 ( V_206 ) ;
}
static unsigned int F_163 ( struct V_204 * V_205 ,
struct V_1 * V_2 ,
unsigned int V_173 , bool V_209 ,
unsigned int V_206 )
{
struct V_13 * V_14 , * V_210 , * V_211 = NULL ;
unsigned int V_199 , V_212 , V_213 = V_184 ;
V_14 = F_36 ( V_205 -> V_214 [ V_173 ] ) ;
if ( V_209 ) {
V_213 = F_147 ( V_14 , V_2 ) ;
if ( V_213 == V_191 ||
( V_213 == V_192 && ! F_154 ( V_14 , V_2 ) ) )
return V_173 ;
V_211 = V_14 ;
}
V_199 = V_212 = F_164 ( int , V_14 -> V_202 -> V_23 , V_206 - 1 ) ;
do {
V_210 = F_36 ( V_205 -> V_214 [ V_199 ] ) ;
if ( V_210 != V_211 && ! V_210 -> V_194 &&
F_147 ( V_210 , V_2 ) == V_191 ) {
if ( V_199 != V_212 )
V_14 -> V_202 -> V_23 = V_199 ;
F_18 ( & V_14 -> V_202 -> V_206 ) ;
if ( V_213 == V_192 )
F_18 ( & V_14 -> V_202 -> V_215 ) ;
return V_199 ;
}
if ( ++ V_199 == V_206 )
V_199 = 0 ;
} while ( V_199 != V_212 );
F_18 ( & V_14 -> V_202 -> V_216 ) ;
return V_173 ;
}
static unsigned int F_165 ( struct V_204 * V_205 ,
struct V_1 * V_2 ,
unsigned int V_206 )
{
return F_166 ( V_2 ) % V_206 ;
}
static unsigned int F_167 ( struct V_204 * V_205 ,
struct V_1 * V_2 ,
unsigned int V_206 )
{
struct V_217 * V_218 ;
unsigned int V_8 = 0 ;
F_20 () ;
V_218 = F_21 ( V_205 -> V_217 ) ;
if ( V_218 )
V_8 = F_168 ( V_218 , V_2 ) % V_206 ;
F_24 () ;
return V_8 ;
}
static bool F_169 ( struct V_204 * V_205 , T_2 V_219 )
{
return V_205 -> V_46 & ( V_219 >> 8 ) ;
}
static int F_170 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_220 * V_221 , struct V_3 * V_222 )
{
struct V_204 * V_205 = V_221 -> V_223 ;
unsigned int V_206 = F_171 ( V_205 -> V_224 ) ;
struct V_13 * V_14 ;
unsigned int V_173 ;
if ( ! F_172 ( F_173 ( V_4 ) , F_174 ( & V_205 -> V_225 ) ) ||
! V_206 ) {
F_17 ( V_2 ) ;
return 0 ;
}
if ( F_169 ( V_205 , V_226 ) ) {
V_2 = F_175 ( V_2 , V_227 ) ;
if ( ! V_2 )
return 0 ;
}
switch ( V_205 -> type ) {
case V_228 :
default:
V_173 = F_156 ( V_205 , V_2 , V_206 ) ;
break;
case V_229 :
V_173 = F_158 ( V_205 , V_2 , V_206 ) ;
break;
case V_230 :
V_173 = F_160 ( V_205 , V_2 , V_206 ) ;
break;
case V_231 :
V_173 = F_161 ( V_205 , V_2 , V_206 ) ;
break;
case V_232 :
V_173 = F_165 ( V_205 , V_2 , V_206 ) ;
break;
case V_233 :
V_173 = F_163 ( V_205 , V_2 , 0 , false , V_206 ) ;
break;
case V_234 :
case V_235 :
V_173 = F_167 ( V_205 , V_2 , V_206 ) ;
break;
}
if ( F_169 ( V_205 , V_236 ) )
V_173 = F_163 ( V_205 , V_2 , V_173 , true , V_206 ) ;
V_14 = F_36 ( V_205 -> V_214 [ V_173 ] ) ;
return V_14 -> V_27 . F_72 ( V_2 , V_4 , & V_14 -> V_27 , V_222 ) ;
}
static void F_37 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_204 * V_205 = V_14 -> V_26 ;
F_46 ( & V_205 -> V_78 ) ;
V_205 -> V_214 [ V_205 -> V_224 ] = V_24 ;
F_56 () ;
V_205 -> V_224 ++ ;
F_44 ( & V_205 -> V_78 ) ;
}
static void F_41 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_204 * V_205 = V_14 -> V_26 ;
int V_199 ;
F_46 ( & V_205 -> V_78 ) ;
for ( V_199 = 0 ; V_199 < V_205 -> V_224 ; V_199 ++ ) {
if ( V_205 -> V_214 [ V_199 ] == V_24 )
break;
}
F_176 ( V_199 >= V_205 -> V_224 ) ;
V_205 -> V_214 [ V_199 ] = V_205 -> V_214 [ V_205 -> V_224 - 1 ] ;
V_205 -> V_224 -- ;
F_44 ( & V_205 -> V_78 ) ;
}
static bool F_177 ( struct V_220 * V_237 , struct V_23 * V_24 )
{
if ( V_237 -> V_223 == ( void * ) ( (struct V_13 * ) V_24 ) -> V_26 )
return true ;
return false ;
}
static void F_178 ( struct V_204 * V_205 )
{
switch ( V_205 -> type ) {
case V_229 :
F_179 ( & V_205 -> V_208 , 0 ) ;
break;
case V_234 :
case V_235 :
F_28 ( V_205 -> V_217 , NULL ) ;
break;
}
}
static void F_180 ( struct V_204 * V_205 , struct V_217 * V_238 )
{
struct V_217 * V_239 ;
F_46 ( & V_205 -> V_78 ) ;
V_239 = F_181 ( V_205 -> V_217 , F_182 ( & V_205 -> V_78 ) ) ;
F_26 ( V_205 -> V_217 , V_238 ) ;
F_44 ( & V_205 -> V_78 ) ;
if ( V_239 ) {
F_45 () ;
F_183 ( V_239 ) ;
}
}
static int F_184 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_172 )
{
struct V_217 * V_238 ;
struct V_240 V_241 ;
int V_8 ;
if ( F_151 ( & V_14 -> V_24 , V_242 ) )
return - V_243 ;
if ( V_172 != sizeof( V_241 ) )
return - V_244 ;
if ( F_185 ( & V_241 , V_80 , V_172 ) )
return - V_245 ;
V_8 = F_186 ( & V_238 , & V_241 , NULL ) ;
if ( V_8 )
return V_8 ;
F_180 ( V_14 -> V_26 , V_238 ) ;
return 0 ;
}
static int F_187 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_172 )
{
struct V_217 * V_238 ;
T_5 V_246 ;
if ( F_151 ( & V_14 -> V_24 , V_242 ) )
return - V_243 ;
if ( V_172 != sizeof( V_246 ) )
return - V_244 ;
if ( F_185 ( & V_246 , V_80 , V_172 ) )
return - V_245 ;
V_238 = F_188 ( V_246 ) ;
if ( F_189 ( V_238 ) )
return F_190 ( V_238 ) ;
if ( V_238 -> type != V_247 ) {
F_191 ( V_238 ) ;
return - V_244 ;
}
F_180 ( V_14 -> V_26 , V_238 ) ;
return 0 ;
}
static int F_192 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_172 )
{
switch ( V_14 -> V_26 -> type ) {
case V_234 :
return F_184 ( V_14 , V_80 , V_172 ) ;
case V_235 :
return F_187 ( V_14 , V_80 , V_172 ) ;
default:
return - V_244 ;
} ;
}
static void F_193 ( struct V_204 * V_205 )
{
switch ( V_205 -> type ) {
case V_234 :
case V_235 :
F_180 ( V_205 , NULL ) ;
} ;
}
static int F_194 ( struct V_23 * V_24 , T_2 V_248 , T_2 V_249 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_204 * V_205 , * V_250 ;
T_6 type = V_249 & 0xff ;
T_6 V_46 = V_249 >> 8 ;
int V_91 ;
switch ( type ) {
case V_233 :
if ( V_249 & V_236 )
return - V_244 ;
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_234 :
case V_235 :
break;
default:
return - V_244 ;
}
if ( ! V_14 -> V_25 )
return - V_244 ;
if ( V_14 -> V_26 )
return - V_251 ;
if ( type == V_233 ||
( V_249 & V_236 ) ) {
V_14 -> V_202 = F_195 ( sizeof( * V_14 -> V_202 ) , V_252 ) ;
if ( ! V_14 -> V_202 )
return - V_253 ;
F_196 ( & V_14 -> V_202 -> V_206 , 0 ) ;
F_196 ( & V_14 -> V_202 -> V_215 , 0 ) ;
F_196 ( & V_14 -> V_202 -> V_216 , 0 ) ;
}
F_197 ( & V_254 ) ;
V_250 = NULL ;
F_198 (f, &fanout_list, list) {
if ( V_205 -> V_248 == V_248 &&
F_174 ( & V_205 -> V_225 ) == F_78 ( V_24 ) ) {
V_250 = V_205 ;
break;
}
}
V_91 = - V_244 ;
if ( V_250 && V_250 -> V_46 != V_46 )
goto V_129;
if ( ! V_250 ) {
V_91 = - V_253 ;
V_250 = F_195 ( sizeof( * V_250 ) , V_252 ) ;
if ( ! V_250 )
goto V_129;
F_199 ( & V_250 -> V_225 , F_78 ( V_24 ) ) ;
V_250 -> V_248 = V_248 ;
V_250 -> type = type ;
V_250 -> V_46 = V_46 ;
F_200 ( & V_250 -> V_255 ) ;
F_201 ( & V_250 -> V_78 ) ;
F_179 ( & V_250 -> V_256 , 0 ) ;
F_178 ( V_250 ) ;
V_250 -> V_27 . type = V_14 -> V_27 . type ;
V_250 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_250 -> V_27 . F_72 = F_170 ;
V_250 -> V_27 . V_223 = V_250 ;
V_250 -> V_27 . V_257 = F_177 ;
F_38 ( & V_250 -> V_27 ) ;
F_202 ( & V_250 -> V_255 , & V_258 ) ;
}
V_91 = - V_244 ;
if ( V_250 -> type == type &&
V_250 -> V_27 . type == V_14 -> V_27 . type &&
V_250 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_91 = - V_259 ;
if ( F_92 ( & V_250 -> V_256 ) < V_260 ) {
F_42 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_250 ;
F_121 ( & V_250 -> V_256 ) ;
F_37 ( V_24 , V_14 ) ;
V_91 = 0 ;
}
}
V_129:
F_203 ( & V_254 ) ;
if ( V_91 ) {
F_204 ( V_14 -> V_202 ) ;
V_14 -> V_202 = NULL ;
}
return V_91 ;
}
static void F_205 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_204 * V_205 ;
V_205 = V_14 -> V_26 ;
if ( ! V_205 )
return;
F_197 ( & V_254 ) ;
V_14 -> V_26 = NULL ;
if ( F_206 ( & V_205 -> V_256 ) ) {
F_207 ( & V_205 -> V_255 ) ;
F_208 ( & V_205 -> V_27 ) ;
F_193 ( V_205 ) ;
F_204 ( V_205 ) ;
}
F_203 ( & V_254 ) ;
if ( V_14 -> V_202 )
F_209 ( V_14 -> V_202 , V_261 ) ;
}
static int F_210 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_220 * V_221 , struct V_3 * V_222 )
{
struct V_23 * V_24 ;
struct V_262 * V_263 ;
V_24 = V_221 -> V_223 ;
if ( V_2 -> V_264 == V_265 )
goto V_129;
if ( ! F_172 ( F_173 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_129;
V_2 = F_211 ( V_2 , V_266 ) ;
if ( V_2 == NULL )
goto V_267;
F_212 ( V_2 ) ;
F_213 ( V_2 ) ;
V_263 = & F_214 ( V_2 ) -> V_268 . V_269 ;
F_215 ( V_2 , V_2 -> V_80 - F_216 ( V_2 ) ) ;
V_263 -> V_270 = V_4 -> type ;
F_217 ( V_263 -> V_271 , V_4 -> V_272 , sizeof( V_263 -> V_271 ) ) ;
V_263 -> V_273 = V_2 -> V_274 ;
if ( F_218 ( V_24 , V_2 ) == 0 )
return 0 ;
V_129:
F_17 ( V_2 ) ;
V_267:
return 0 ;
}
static int F_219 ( struct V_275 * V_23 , struct V_276 * V_277 ,
T_8 V_172 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_220 ( struct V_262 * , V_278 , V_277 -> V_279 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
T_9 V_280 = 0 ;
int V_91 ;
int V_281 = 0 ;
if ( V_278 ) {
if ( V_277 -> V_282 < sizeof( struct V_283 ) )
return - V_244 ;
if ( V_277 -> V_282 == sizeof( struct V_262 ) )
V_280 = V_278 -> V_273 ;
} else
return - V_284 ;
V_278 -> V_271 [ sizeof( V_278 -> V_271 ) - 1 ] = 0 ;
V_285:
F_20 () ;
V_4 = F_221 ( F_78 ( V_24 ) , V_278 -> V_271 ) ;
V_91 = - V_286 ;
if ( V_4 == NULL )
goto V_287;
V_91 = - V_288 ;
if ( ! ( V_4 -> V_46 & V_289 ) )
goto V_287;
if ( F_2 ( F_151 ( V_24 , V_290 ) ) ) {
if ( ! F_222 ( V_4 ) ) {
V_91 = - V_291 ;
goto V_287;
}
V_281 = 4 ;
}
V_91 = - V_292 ;
if ( V_172 > V_4 -> V_293 + V_4 -> V_294 + V_295 + V_281 )
goto V_287;
if ( ! V_2 ) {
T_8 V_296 = F_223 ( V_4 ) ;
int V_297 = V_4 -> V_298 ;
unsigned int V_299 = V_4 -> V_300 ? V_4 -> V_294 : 0 ;
F_24 () ;
V_2 = F_224 ( V_24 , V_172 + V_296 + V_297 , 0 , V_252 ) ;
if ( V_2 == NULL )
return - V_182 ;
F_225 ( V_2 , V_296 ) ;
F_226 ( V_2 ) ;
if ( V_299 ) {
V_2 -> V_80 -= V_299 ;
V_2 -> V_301 -= V_299 ;
if ( V_172 < V_299 )
F_226 ( V_2 ) ;
}
V_91 = F_227 ( F_228 ( V_2 , V_172 ) , V_277 , V_172 ) ;
if ( V_91 )
goto V_302;
goto V_285;
}
if ( V_172 > ( V_4 -> V_293 + V_4 -> V_294 + V_281 ) ) {
struct V_303 * V_304 ;
F_229 ( V_2 ) ;
V_304 = F_230 ( V_2 ) ;
if ( V_304 -> V_305 != F_231 ( V_306 ) ) {
V_91 = - V_292 ;
goto V_287;
}
}
V_2 -> V_274 = V_280 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_307 = V_24 -> V_308 ;
V_2 -> V_309 = V_24 -> V_310 ;
F_232 ( V_24 , & F_233 ( V_2 ) -> V_311 ) ;
if ( F_2 ( V_281 == 4 ) )
V_2 -> V_312 = 1 ;
F_234 ( V_2 , 0 ) ;
F_235 ( V_2 ) ;
F_24 () ;
return V_172 ;
V_287:
F_24 () ;
V_302:
F_17 ( V_2 ) ;
return V_91 ;
}
static unsigned int F_236 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_313 )
{
struct V_314 * V_315 ;
F_20 () ;
V_315 = F_21 ( V_24 -> V_314 ) ;
if ( V_315 != NULL )
V_313 = F_237 ( V_315 , V_2 ) ;
F_24 () ;
return V_313 ;
}
static int F_238 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_220 * V_221 , struct V_3 * V_222 )
{
struct V_23 * V_24 ;
struct V_316 * V_317 ;
struct V_13 * V_14 ;
T_6 * V_318 = V_2 -> V_80 ;
int V_319 = V_2 -> V_172 ;
unsigned int V_320 , V_313 ;
if ( V_2 -> V_264 == V_265 )
goto V_10;
V_24 = V_221 -> V_223 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_300 ) {
if ( V_24 -> V_321 != V_322 )
F_215 ( V_2 , V_2 -> V_80 - F_216 ( V_2 ) ) ;
else if ( V_2 -> V_264 == V_323 ) {
F_239 ( V_2 , F_240 ( V_2 ) ) ;
}
}
V_320 = V_2 -> V_172 ;
V_313 = F_236 ( V_2 , V_24 , V_320 ) ;
if ( ! V_313 )
goto V_324;
if ( V_320 > V_313 )
V_320 = V_313 ;
if ( F_92 ( & V_24 -> V_188 ) >= V_24 -> V_187 )
goto V_325;
if ( F_241 ( V_2 ) ) {
struct V_1 * V_326 = F_242 ( V_2 , V_266 ) ;
if ( V_326 == NULL )
goto V_325;
if ( V_318 != V_2 -> V_80 ) {
V_2 -> V_80 = V_318 ;
V_2 -> V_172 = V_319 ;
}
F_243 ( V_2 ) ;
V_2 = V_326 ;
}
F_244 ( sizeof( * F_214 ( V_2 ) ) + V_327 - 8 ) ;
V_317 = & F_214 ( V_2 ) -> V_268 . V_328 ;
V_317 -> V_329 = V_4 -> type ;
V_317 -> V_330 = V_2 -> V_264 ;
if ( F_2 ( V_14 -> V_331 ) )
V_317 -> V_332 = V_222 -> V_93 ;
else
V_317 -> V_332 = V_4 -> V_93 ;
V_317 -> V_333 = F_245 ( V_2 , V_317 -> V_334 ) ;
F_214 ( V_2 ) -> V_268 . V_335 = V_2 -> V_172 ;
if ( F_246 ( V_2 , V_320 ) )
goto V_325;
F_247 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_212 ( V_2 ) ;
F_213 ( V_2 ) ;
F_46 ( & V_24 -> V_128 . V_78 ) ;
V_14 -> V_117 . V_336 . V_337 ++ ;
F_248 ( V_24 , V_2 ) ;
F_249 ( & V_24 -> V_128 , V_2 ) ;
F_44 ( & V_24 -> V_128 . V_78 ) ;
V_24 -> V_154 ( V_24 ) ;
return 0 ;
V_325:
F_46 ( & V_24 -> V_128 . V_78 ) ;
V_14 -> V_117 . V_336 . V_147 ++ ;
F_121 ( & V_24 -> V_338 ) ;
F_44 ( & V_24 -> V_128 . V_78 ) ;
V_324:
if ( V_318 != V_2 -> V_80 && F_241 ( V_2 ) ) {
V_2 -> V_80 = V_318 ;
V_2 -> V_172 = V_319 ;
}
V_10:
F_243 ( V_2 ) ;
return 0 ;
}
static int V_185 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_220 * V_221 , struct V_3 * V_222 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
struct V_316 * V_317 ;
union V_34 V_35 ;
T_6 * V_318 = V_2 -> V_80 ;
int V_319 = V_2 -> V_172 ;
unsigned int V_320 , V_313 ;
unsigned long V_33 = V_141 ;
unsigned short V_339 , V_340 , V_113 ;
struct V_1 * V_341 = NULL ;
struct V_44 V_45 ;
T_4 V_54 ;
F_250 ( F_251 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_250 ( F_251 ( sizeof( * V_35 . V_342 ) ) != 48 ) ;
if ( V_2 -> V_264 == V_265 )
goto V_10;
V_24 = V_221 -> V_223 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_300 ) {
if ( V_24 -> V_321 != V_322 )
F_215 ( V_2 , V_2 -> V_80 - F_216 ( V_2 ) ) ;
else if ( V_2 -> V_264 == V_323 ) {
F_239 ( V_2 , F_240 ( V_2 ) ) ;
}
}
V_320 = V_2 -> V_172 ;
V_313 = F_236 ( V_2 , V_24 , V_320 ) ;
if ( ! V_313 )
goto V_324;
if ( V_2 -> V_343 == V_344 )
V_33 |= V_345 ;
else if ( V_2 -> V_264 != V_323 &&
( V_2 -> V_343 == V_346 ||
F_252 ( V_2 ) ) )
V_33 |= V_347 ;
if ( V_320 > V_313 )
V_320 = V_313 ;
if ( V_24 -> V_321 == V_322 ) {
V_339 = V_340 = F_251 ( V_14 -> V_114 ) + 16 +
V_14 -> V_348 ;
} else {
unsigned int V_349 = F_240 ( V_2 ) ;
V_340 = F_251 ( V_14 -> V_114 +
( V_349 < 16 ? 16 : V_349 ) ) +
V_14 -> V_348 ;
V_339 = V_340 - V_349 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_339 + V_320 > V_14 -> V_77 . V_70 ) {
if ( V_14 -> V_350 &&
F_92 ( & V_24 -> V_188 ) < V_24 -> V_187 ) {
if ( F_241 ( V_2 ) ) {
V_341 = F_242 ( V_2 , V_266 ) ;
} else {
V_341 = F_253 ( V_2 ) ;
V_318 = V_2 -> V_80 ;
}
if ( V_341 )
F_247 ( V_341 , V_24 ) ;
}
V_320 = V_14 -> V_77 . V_70 - V_339 ;
if ( ( int ) V_320 < 0 )
V_320 = 0 ;
}
} else if ( F_2 ( V_339 + V_320 >
F_68 ( & V_14 -> V_77 ) -> V_125 ) ) {
T_5 V_351 ;
V_351 = F_68 ( & V_14 -> V_77 ) -> V_125 - V_339 ;
F_254 ( L_4 ,
V_320 , V_351 , V_339 ) ;
V_320 = V_351 ;
if ( F_2 ( ( int ) V_320 < 0 ) ) {
V_320 = 0 ;
V_339 = F_68 ( & V_14 -> V_77 ) -> V_125 ;
}
}
F_46 ( & V_24 -> V_128 . V_78 ) ;
V_35 . V_36 = F_124 ( V_14 , V_2 ,
V_159 , ( V_339 + V_320 ) ) ;
if ( ! V_35 . V_36 )
goto V_352;
if ( V_14 -> V_37 <= V_41 ) {
F_131 ( V_14 , & V_14 -> V_77 ) ;
if ( V_14 -> V_117 . V_336 . V_147 )
V_33 |= V_148 ;
}
V_14 -> V_117 . V_336 . V_337 ++ ;
if ( V_341 ) {
V_33 |= V_353 ;
F_249 ( & V_24 -> V_128 , V_341 ) ;
}
F_44 ( & V_24 -> V_128 . V_78 ) ;
F_255 ( V_2 , 0 , V_35 . V_36 + V_339 , V_320 ) ;
if ( ! ( V_54 = F_59 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
F_101 ( & V_45 ) ;
V_33 |= V_54 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_354 = V_2 -> V_172 ;
V_35 . V_39 -> V_355 = V_320 ;
V_35 . V_39 -> V_356 = V_339 ;
V_35 . V_39 -> V_357 = V_340 ;
V_35 . V_39 -> V_56 = V_45 . V_57 ;
V_35 . V_39 -> V_58 = V_45 . V_59 / V_60 ;
V_113 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_354 = V_2 -> V_172 ;
V_35 . V_42 -> V_355 = V_320 ;
V_35 . V_42 -> V_356 = V_339 ;
V_35 . V_42 -> V_357 = V_340 ;
V_35 . V_42 -> V_56 = V_45 . V_57 ;
V_35 . V_42 -> V_61 = V_45 . V_59 ;
if ( F_115 ( V_2 ) ) {
V_35 . V_42 -> V_163 = F_116 ( V_2 ) ;
V_35 . V_42 -> V_164 = F_117 ( V_2 -> V_165 ) ;
V_33 |= V_166 | V_167 ;
} else {
V_35 . V_42 -> V_163 = 0 ;
V_35 . V_42 -> V_164 = 0 ;
}
memset ( V_35 . V_42 -> V_169 , 0 , sizeof( V_35 . V_42 -> V_169 ) ) ;
V_113 = sizeof( * V_35 . V_42 ) ;
break;
case V_43 :
V_35 . V_342 -> V_40 |= V_33 ;
V_35 . V_342 -> V_354 = V_2 -> V_172 ;
V_35 . V_342 -> V_355 = V_320 ;
V_35 . V_342 -> V_356 = V_339 ;
V_35 . V_342 -> V_357 = V_340 ;
V_35 . V_342 -> V_56 = V_45 . V_57 ;
V_35 . V_342 -> V_61 = V_45 . V_59 ;
memset ( V_35 . V_342 -> V_169 , 0 , sizeof( V_35 . V_342 -> V_169 ) ) ;
V_113 = sizeof( * V_35 . V_342 ) ;
break;
default:
F_55 () ;
}
V_317 = V_35 . V_36 + F_251 ( V_113 ) ;
V_317 -> V_333 = F_245 ( V_2 , V_317 -> V_334 ) ;
V_317 -> V_358 = V_359 ;
V_317 -> V_329 = V_4 -> type ;
V_317 -> V_360 = V_2 -> V_274 ;
V_317 -> V_330 = V_2 -> V_264 ;
if ( F_2 ( V_14 -> V_331 ) )
V_317 -> V_332 = V_222 -> V_93 ;
else
V_317 -> V_332 = V_4 -> V_93 ;
F_123 () ;
#if V_135 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_6 * V_136 , * V_137 ;
V_137 = ( T_6 * ) F_98 ( ( unsigned long ) V_35 . V_36 +
V_339 + V_320 ) ;
for ( V_136 = V_35 . V_36 ; V_136 < V_137 ; V_136 += V_138 )
F_53 ( F_48 ( V_136 ) ) ;
}
F_56 () ;
#endif
if ( V_14 -> V_37 <= V_41 ) {
F_52 ( V_14 , V_35 . V_36 , V_33 ) ;
V_24 -> V_154 ( V_24 ) ;
} else {
F_109 ( & V_14 -> V_77 ) ;
}
V_324:
if ( V_318 != V_2 -> V_80 && F_241 ( V_2 ) ) {
V_2 -> V_80 = V_318 ;
V_2 -> V_172 = V_319 ;
}
V_10:
F_17 ( V_2 ) ;
return 0 ;
V_352:
V_14 -> V_117 . V_336 . V_147 ++ ;
F_44 ( & V_24 -> V_128 . V_78 ) ;
V_24 -> V_154 ( V_24 ) ;
F_17 ( V_341 ) ;
goto V_324;
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_36 ( V_2 -> V_24 ) ;
if ( F_22 ( V_14 -> V_181 . V_68 ) ) {
void * V_361 ;
T_4 V_45 ;
V_361 = F_233 ( V_2 ) -> V_362 ;
F_135 ( & V_14 -> V_181 ) ;
V_45 = F_62 ( V_14 , V_361 , V_2 ) ;
F_52 ( V_14 , V_361 , V_168 | V_45 ) ;
}
F_257 ( V_2 ) ;
}
static bool F_258 ( const struct V_3 * V_4 , int V_172 )
{
if ( F_2 ( V_172 <= V_4 -> V_294 ) ) {
F_259 ( L_5 ,
V_363 -> V_364 , V_172 , V_4 -> V_294 ) ;
return true ;
}
return false ;
}
static int F_260 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , int V_365 ,
T_9 V_280 , unsigned char * V_31 , int V_366 )
{
union V_34 V_361 ;
int V_367 , V_368 , V_172 , V_354 , V_369 , V_370 ;
struct V_275 * V_23 = V_14 -> V_24 . V_371 ;
struct V_30 * V_30 ;
void * V_80 ;
int V_91 ;
V_361 . V_36 = V_32 ;
V_2 -> V_274 = V_280 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_307 = V_14 -> V_24 . V_308 ;
V_2 -> V_309 = V_14 -> V_24 . V_310 ;
F_232 ( & V_14 -> V_24 , & F_233 ( V_2 ) -> V_311 ) ;
F_233 ( V_2 ) -> V_362 = V_361 . V_36 ;
switch ( V_14 -> V_37 ) {
case V_41 :
V_354 = V_361 . V_42 -> V_354 ;
break;
default:
V_354 = V_361 . V_39 -> V_354 ;
break;
}
if ( F_2 ( V_354 > V_365 ) ) {
F_152 ( L_6 , V_354 , V_365 ) ;
return - V_292 ;
}
F_225 ( V_2 , V_366 ) ;
F_226 ( V_2 ) ;
if ( ! F_29 ( V_14 ) )
F_234 ( V_2 , 0 ) ;
if ( F_2 ( V_14 -> V_372 ) ) {
int V_373 , V_374 , V_375 ;
V_373 = V_14 -> V_114 - sizeof( struct V_316 ) ;
V_374 = V_14 -> V_181 . V_70 - V_354 ;
if ( V_23 -> type == V_322 ) {
switch ( V_14 -> V_37 ) {
case V_41 :
V_375 = V_361 . V_42 -> V_357 ;
break;
default:
V_375 = V_361 . V_39 -> V_357 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_41 :
V_375 = V_361 . V_42 -> V_356 ;
break;
default:
V_375 = V_361 . V_39 -> V_356 ;
break;
}
}
if ( F_2 ( ( V_375 < V_373 ) || ( V_374 < V_375 ) ) )
return - V_244 ;
V_80 = V_361 . V_36 + V_375 ;
} else {
V_80 = V_361 . V_36 + V_14 -> V_114 - sizeof( struct V_316 ) ;
}
V_367 = V_354 ;
if ( V_23 -> type == V_322 ) {
V_91 = F_261 ( V_2 , V_4 , F_117 ( V_280 ) , V_31 ,
NULL , V_354 ) ;
if ( F_2 ( V_91 < 0 ) )
return - V_244 ;
} else if ( V_4 -> V_294 ) {
if ( F_258 ( V_4 , V_354 ) )
return - V_244 ;
F_215 ( V_2 , V_4 -> V_294 ) ;
V_91 = F_262 ( V_2 , 0 , V_80 ,
V_4 -> V_294 ) ;
if ( F_2 ( V_91 ) )
return V_91 ;
V_80 += V_4 -> V_294 ;
V_367 -= V_4 -> V_294 ;
}
V_368 = F_263 ( V_80 ) ;
V_370 = V_138 - V_368 ;
V_172 = ( ( V_367 > V_370 ) ? V_370 : V_367 ) ;
V_2 -> V_376 = V_367 ;
V_2 -> V_172 += V_367 ;
V_2 -> V_189 += V_367 ;
F_264 ( V_367 , & V_14 -> V_24 . V_196 ) ;
while ( F_22 ( V_367 ) ) {
V_369 = F_233 ( V_2 ) -> V_369 ;
if ( F_2 ( V_369 >= V_377 ) ) {
F_152 ( L_7 ,
V_377 ) ;
return - V_245 ;
}
V_30 = F_48 ( V_80 ) ;
V_80 += V_172 ;
F_53 ( V_30 ) ;
F_265 ( V_30 ) ;
F_266 ( V_2 , V_369 , V_30 , V_368 , V_172 ) ;
V_367 -= V_172 ;
V_368 = 0 ;
V_370 = V_138 ;
V_172 = ( ( V_367 > V_370 ) ? V_370 : V_367 ) ;
}
return V_354 ;
}
static int F_267 ( struct V_13 * V_14 , struct V_276 * V_277 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_9 V_280 ;
int V_91 , V_378 = 0 ;
void * V_361 ;
F_220 ( struct V_316 * , V_278 , V_277 -> V_279 ) ;
bool V_379 = ! ( V_277 -> V_380 & V_381 ) ;
int V_354 , V_365 ;
unsigned char * V_31 ;
int V_382 = 0 ;
int V_33 = V_168 ;
int V_366 , V_297 ;
F_197 ( & V_14 -> V_383 ) ;
if ( F_22 ( V_278 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_280 = V_14 -> V_206 ;
V_31 = NULL ;
} else {
V_91 = - V_244 ;
if ( V_277 -> V_282 < sizeof( struct V_316 ) )
goto V_129;
if ( V_277 -> V_282 < ( V_278 -> V_333
+ F_268 ( struct V_316 ,
V_334 ) ) )
goto V_129;
V_280 = V_278 -> V_360 ;
V_31 = V_278 -> V_334 ;
V_4 = F_269 ( F_78 ( & V_14 -> V_24 ) , V_278 -> V_332 ) ;
}
V_91 = - V_384 ;
if ( F_2 ( V_4 == NULL ) )
goto V_129;
V_91 = - V_288 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_289 ) ) )
goto V_385;
V_378 = V_4 -> V_294 + V_295 ;
V_365 = V_14 -> V_181 . V_70
- ( V_14 -> V_114 - sizeof( struct V_316 ) ) ;
if ( V_365 > V_4 -> V_293 + V_378 )
V_365 = V_4 -> V_293 + V_378 ;
do {
V_361 = F_64 ( V_14 , & V_14 -> V_181 ,
V_386 ) ;
if ( F_2 ( V_361 == NULL ) ) {
if ( V_379 && F_270 () )
F_271 () ;
continue;
}
V_33 = V_386 ;
V_366 = F_223 ( V_4 ) ;
V_297 = V_4 -> V_298 ;
V_2 = F_272 ( & V_14 -> V_24 ,
V_366 + V_297 + sizeof( struct V_316 ) ,
! V_379 , & V_91 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_22 ( V_382 > 0 ) )
V_91 = V_382 ;
goto V_387;
}
V_354 = F_260 ( V_14 , V_2 , V_361 , V_4 , V_365 , V_280 ,
V_31 , V_366 ) ;
if ( F_22 ( V_354 >= 0 ) &&
V_354 > V_4 -> V_293 + V_4 -> V_294 ) {
struct V_303 * V_304 ;
F_229 ( V_2 ) ;
V_304 = F_230 ( V_2 ) ;
if ( V_304 -> V_305 != F_231 ( V_306 ) )
V_354 = - V_292 ;
}
if ( F_2 ( V_354 < 0 ) ) {
if ( V_14 -> V_388 ) {
F_52 ( V_14 , V_361 ,
V_168 ) ;
F_132 ( & V_14 -> V_181 ) ;
F_17 ( V_2 ) ;
continue;
} else {
V_33 = V_389 ;
V_91 = V_354 ;
goto V_387;
}
}
F_32 ( V_4 , V_2 ) ;
V_2 -> V_390 = F_256 ;
F_52 ( V_14 , V_361 , V_391 ) ;
F_133 ( & V_14 -> V_181 ) ;
V_33 = V_386 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_91 > 0 ) ) {
V_91 = F_273 ( V_91 ) ;
if ( V_91 && F_57 ( V_14 , V_361 ) ==
V_168 ) {
V_2 = NULL ;
goto V_387;
}
V_91 = 0 ;
}
F_132 ( & V_14 -> V_181 ) ;
V_382 += V_354 ;
} while ( F_22 ( ( V_361 != NULL ) ||
( V_379 && F_137 ( & V_14 -> V_181 ) ) ) );
V_91 = V_382 ;
goto V_385;
V_387:
F_52 ( V_14 , V_361 , V_33 ) ;
F_17 ( V_2 ) ;
V_385:
F_274 ( V_4 ) ;
V_129:
F_203 ( & V_14 -> V_383 ) ;
return V_91 ;
}
static struct V_1 * F_275 ( struct V_23 * V_24 , T_8 V_392 ,
T_8 V_378 , T_8 V_172 ,
T_8 V_393 , int V_394 ,
int * V_91 )
{
struct V_1 * V_2 ;
if ( V_392 + V_172 < V_138 || ! V_393 )
V_393 = V_172 ;
V_2 = F_276 ( V_24 , V_392 + V_393 , V_172 - V_393 , V_394 ,
V_91 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_225 ( V_2 , V_378 ) ;
F_228 ( V_2 , V_393 ) ;
V_2 -> V_376 = V_172 - V_393 ;
V_2 -> V_172 += V_172 - V_393 ;
return V_2 ;
}
static int F_277 ( struct V_275 * V_23 , struct V_276 * V_277 , T_8 V_172 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_220 ( struct V_316 * , V_278 , V_277 -> V_279 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_9 V_280 ;
unsigned char * V_31 ;
int V_91 , V_378 = 0 ;
struct V_395 V_396 = { 0 } ;
int V_368 = 0 ;
int V_397 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned short V_398 = 0 ;
int V_366 , V_297 ;
int V_281 = 0 ;
T_10 V_399 ;
if ( F_22 ( V_278 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_280 = V_14 -> V_206 ;
V_31 = NULL ;
} else {
V_91 = - V_244 ;
if ( V_277 -> V_282 < sizeof( struct V_316 ) )
goto V_129;
if ( V_277 -> V_282 < ( V_278 -> V_333 + F_268 ( struct V_316 , V_334 ) ) )
goto V_129;
V_280 = V_278 -> V_360 ;
V_31 = V_278 -> V_334 ;
V_4 = F_269 ( F_78 ( V_24 ) , V_278 -> V_332 ) ;
}
V_91 = - V_384 ;
if ( F_2 ( V_4 == NULL ) )
goto V_287;
V_91 = - V_288 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_289 ) ) )
goto V_287;
if ( V_23 -> type == V_400 )
V_378 = V_4 -> V_294 ;
if ( V_14 -> V_401 ) {
V_397 = sizeof( V_396 ) ;
V_91 = - V_244 ;
if ( V_172 < V_397 )
goto V_287;
V_172 -= V_397 ;
V_91 = - V_245 ;
V_399 = F_278 ( & V_396 , V_397 , & V_277 -> V_402 ) ;
if ( V_399 != V_397 )
goto V_287;
if ( ( V_396 . V_46 & V_403 ) &&
( F_279 ( F_280 () , V_396 . V_404 ) +
F_279 ( F_280 () , V_396 . V_405 ) + 2 >
F_279 ( F_280 () , V_396 . V_406 ) ) )
V_396 . V_406 = F_281 ( F_280 () ,
F_279 ( F_280 () , V_396 . V_404 ) +
F_279 ( F_280 () , V_396 . V_405 ) + 2 ) ;
V_91 = - V_244 ;
if ( F_279 ( F_280 () , V_396 . V_406 ) > V_172 )
goto V_287;
if ( V_396 . V_398 != V_407 ) {
switch ( V_396 . V_398 & ~ V_408 ) {
case V_409 :
V_398 = V_410 ;
break;
case V_411 :
V_398 = V_412 ;
break;
case V_413 :
V_398 = V_414 ;
break;
default:
goto V_287;
}
if ( V_396 . V_398 & V_408 )
V_398 |= V_415 ;
if ( V_396 . V_416 == 0 )
goto V_287;
}
}
if ( F_2 ( F_151 ( V_24 , V_290 ) ) ) {
if ( ! F_222 ( V_4 ) ) {
V_91 = - V_291 ;
goto V_287;
}
V_281 = 4 ;
}
V_91 = - V_292 ;
if ( ! V_398 && ( V_172 > V_4 -> V_293 + V_378 + V_295 + V_281 ) )
goto V_287;
V_91 = - V_182 ;
V_366 = F_223 ( V_4 ) ;
V_297 = V_4 -> V_298 ;
V_2 = F_275 ( V_24 , V_366 + V_297 , V_366 , V_172 ,
F_279 ( F_280 () , V_396 . V_406 ) ,
V_277 -> V_380 & V_381 , & V_91 ) ;
if ( V_2 == NULL )
goto V_287;
F_282 ( V_2 , V_378 ) ;
V_91 = - V_244 ;
if ( V_23 -> type == V_322 ) {
V_368 = F_261 ( V_2 , V_4 , F_117 ( V_280 ) , V_31 , NULL , V_172 ) ;
if ( F_2 ( V_368 < 0 ) )
goto V_302;
} else {
if ( F_258 ( V_4 , V_172 ) )
goto V_302;
}
V_91 = F_283 ( V_2 , V_368 , & V_277 -> V_402 , V_172 ) ;
if ( V_91 )
goto V_302;
F_232 ( V_24 , & F_233 ( V_2 ) -> V_311 ) ;
if ( ! V_398 && ( V_172 > V_4 -> V_293 + V_378 + V_281 ) ) {
struct V_303 * V_304 ;
F_229 ( V_2 ) ;
V_304 = F_230 ( V_2 ) ;
if ( V_304 -> V_305 != F_231 ( V_306 ) ) {
V_91 = - V_292 ;
goto V_302;
}
}
V_2 -> V_274 = V_280 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_307 = V_24 -> V_308 ;
V_2 -> V_309 = V_24 -> V_310 ;
F_32 ( V_4 , V_2 ) ;
if ( V_14 -> V_401 ) {
if ( V_396 . V_46 & V_403 ) {
T_2 V_417 = F_279 ( F_280 () , V_396 . V_404 ) ;
T_2 V_418 = F_279 ( F_280 () , V_396 . V_405 ) ;
if ( ! F_284 ( V_2 , V_417 , V_418 ) ) {
V_91 = - V_244 ;
goto V_302;
}
}
F_233 ( V_2 ) -> V_416 =
F_279 ( F_280 () , V_396 . V_416 ) ;
F_233 ( V_2 ) -> V_398 = V_398 ;
F_233 ( V_2 ) -> V_398 |= V_419 ;
F_233 ( V_2 ) -> V_420 = 0 ;
V_172 += V_397 ;
}
if ( ! F_29 ( V_14 ) )
F_234 ( V_2 , V_378 ) ;
if ( F_2 ( V_281 == 4 ) )
V_2 -> V_312 = 1 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( V_91 > 0 && ( V_91 = F_273 ( V_91 ) ) != 0 )
goto V_287;
F_274 ( V_4 ) ;
return V_172 ;
V_302:
F_17 ( V_2 ) ;
V_287:
if ( V_4 )
F_274 ( V_4 ) ;
V_129:
return V_91 ;
}
static int F_285 ( struct V_275 * V_23 , struct V_276 * V_277 , T_8 V_172 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
if ( V_14 -> V_181 . V_68 )
return F_267 ( V_14 , V_277 ) ;
else
return F_277 ( V_23 , V_277 , V_172 ) ;
}
static int F_286 ( struct V_275 * V_23 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 ;
struct V_225 * V_225 ;
union V_98 V_99 ;
if ( ! V_24 )
return 0 ;
V_225 = F_78 ( V_24 ) ;
V_14 = F_36 ( V_24 ) ;
F_197 ( & V_225 -> V_421 . V_422 ) ;
F_287 ( V_24 ) ;
F_203 ( & V_225 -> V_421 . V_422 ) ;
F_288 () ;
F_289 ( V_225 , V_24 -> V_423 , - 1 ) ;
F_290 () ;
F_46 ( & V_14 -> V_29 ) ;
F_47 ( V_24 , false ) ;
F_27 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_274 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
F_291 ( V_24 ) ;
if ( V_14 -> V_77 . V_68 ) {
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
F_292 ( V_24 , & V_99 , 1 , 0 ) ;
}
if ( V_14 -> V_181 . V_68 ) {
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
F_292 ( V_24 , & V_99 , 1 , 1 ) ;
}
F_205 ( V_24 ) ;
F_45 () ;
F_293 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_149 ( & V_24 -> V_128 ) ;
F_142 ( V_14 ) ;
F_294 ( V_24 ) ;
F_295 ( V_24 ) ;
return 0 ;
}
static int F_296 ( struct V_23 * V_24 , struct V_3 * V_4 , T_9 V_280 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_3 * V_424 ;
T_9 V_425 ;
bool V_426 ;
if ( V_14 -> V_26 ) {
if ( V_4 )
F_274 ( V_4 ) ;
return - V_244 ;
}
F_297 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_425 = V_14 -> V_27 . type ;
V_424 = V_14 -> V_27 . V_4 ;
V_426 = V_425 != V_280 || V_424 != V_4 ;
if ( V_426 ) {
F_47 ( V_24 , true ) ;
V_14 -> V_206 = V_280 ;
V_14 -> V_27 . type = V_280 ;
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_93 = V_4 ? V_4 -> V_93 : 0 ;
F_25 ( V_14 , V_4 ) ;
}
if ( V_424 )
F_274 ( V_424 ) ;
if ( V_280 == 0 || ! V_426 )
goto V_287;
if ( ! V_4 || ( V_4 -> V_46 & V_289 ) ) {
F_35 ( V_24 ) ;
} else {
V_24 -> V_427 = V_288 ;
if ( ! F_151 ( V_24 , V_197 ) )
V_24 -> V_428 ( V_24 ) ;
}
V_287:
F_44 ( & V_14 -> V_29 ) ;
F_298 ( V_24 ) ;
return 0 ;
}
static int F_299 ( struct V_275 * V_23 , struct V_283 * V_429 ,
int V_430 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_272 [ 15 ] ;
struct V_3 * V_4 ;
int V_91 = - V_286 ;
if ( V_430 != sizeof( struct V_283 ) )
return - V_244 ;
F_217 ( V_272 , V_429 -> V_431 , sizeof( V_272 ) ) ;
V_4 = F_300 ( F_78 ( V_24 ) , V_272 ) ;
if ( V_4 )
V_91 = F_296 ( V_24 , V_4 , F_36 ( V_24 ) -> V_206 ) ;
return V_91 ;
}
static int F_301 ( struct V_275 * V_23 , struct V_283 * V_429 , int V_430 )
{
struct V_316 * V_317 = (struct V_316 * ) V_429 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_3 * V_4 = NULL ;
int V_91 ;
if ( V_430 < sizeof( struct V_316 ) )
return - V_244 ;
if ( V_317 -> V_358 != V_359 )
return - V_244 ;
if ( V_317 -> V_332 ) {
V_91 = - V_286 ;
V_4 = F_269 ( F_78 ( V_24 ) , V_317 -> V_332 ) ;
if ( V_4 == NULL )
goto V_129;
}
V_91 = F_296 ( V_24 , V_4 , V_317 -> V_360 ? : F_36 ( V_24 ) -> V_206 ) ;
V_129:
return V_91 ;
}
static int F_302 ( struct V_225 * V_225 , struct V_275 * V_23 , int V_274 ,
int V_432 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_9 V_280 = ( V_433 T_9 ) V_274 ;
int V_91 ;
if ( ! F_303 ( V_225 -> V_434 , V_435 ) )
return - V_243 ;
if ( V_23 -> type != V_322 && V_23 -> type != V_400 &&
V_23 -> type != V_436 )
return - V_437 ;
V_23 -> V_438 = V_439 ;
V_91 = - V_182 ;
V_24 = F_304 ( V_225 , V_440 , V_252 , & V_441 , V_432 ) ;
if ( V_24 == NULL )
goto V_129;
V_23 -> V_19 = & V_442 ;
if ( V_23 -> type == V_436 )
V_23 -> V_19 = & V_443 ;
F_305 ( V_23 , V_24 ) ;
V_14 = F_36 ( V_24 ) ;
V_24 -> V_444 = V_440 ;
V_14 -> V_206 = V_280 ;
V_14 -> V_16 = F_235 ;
V_91 = F_140 ( V_14 ) ;
if ( V_91 )
goto V_445;
F_27 ( V_14 ) ;
V_24 -> V_446 = F_148 ;
F_306 ( V_24 ) ;
F_201 ( & V_14 -> V_29 ) ;
F_307 ( & V_14 -> V_383 ) ;
V_14 -> V_202 = NULL ;
V_14 -> V_27 . F_72 = F_238 ;
if ( V_23 -> type == V_436 )
V_14 -> V_27 . F_72 = F_210 ;
V_14 -> V_27 . V_223 = V_24 ;
if ( V_280 ) {
V_14 -> V_27 . type = V_280 ;
F_35 ( V_24 ) ;
}
F_197 ( & V_225 -> V_421 . V_422 ) ;
F_308 ( V_24 , & V_225 -> V_421 . V_447 ) ;
F_203 ( & V_225 -> V_421 . V_422 ) ;
F_288 () ;
F_289 ( V_225 , & V_441 , 1 ) ;
F_290 () ;
return 0 ;
V_445:
F_309 ( V_24 ) ;
V_129:
return V_91 ;
}
static int F_310 ( struct V_275 * V_23 , struct V_276 * V_277 , T_8 V_172 ,
int V_46 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_448 , V_91 ;
int V_397 = 0 ;
unsigned int V_335 = 0 ;
V_91 = - V_244 ;
if ( V_46 & ~ ( V_449 | V_381 | V_450 | V_451 | V_452 ) )
goto V_129;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_46 & V_452 ) {
V_91 = F_311 ( V_24 , V_277 , V_172 ,
V_453 , V_454 ) ;
goto V_129;
}
V_2 = F_312 ( V_24 , V_46 , V_46 & V_381 , & V_91 ) ;
if ( V_2 == NULL )
goto V_129;
if ( F_36 ( V_24 ) -> V_194 )
F_147 ( F_36 ( V_24 ) , NULL ) ;
if ( F_36 ( V_24 ) -> V_401 ) {
struct V_395 V_396 = { 0 } ;
V_91 = - V_244 ;
V_397 = sizeof( V_396 ) ;
if ( V_172 < V_397 )
goto V_302;
V_172 -= V_397 ;
if ( F_313 ( V_2 ) ) {
struct V_455 * V_456 = F_233 ( V_2 ) ;
V_396 . V_406 =
F_281 ( F_280 () , F_314 ( V_2 ) ) ;
V_396 . V_416 =
F_281 ( F_280 () , V_456 -> V_416 ) ;
if ( V_456 -> V_398 & V_410 )
V_396 . V_398 = V_409 ;
else if ( V_456 -> V_398 & V_412 )
V_396 . V_398 = V_411 ;
else if ( V_456 -> V_398 & V_414 )
V_396 . V_398 = V_413 ;
else if ( V_456 -> V_398 & V_457 )
goto V_302;
else
F_55 () ;
if ( V_456 -> V_398 & V_415 )
V_396 . V_398 |= V_408 ;
} else
V_396 . V_398 = V_407 ;
if ( V_2 -> V_343 == V_344 ) {
V_396 . V_46 = V_403 ;
V_396 . V_404 = F_281 ( F_280 () ,
F_315 ( V_2 ) ) ;
V_396 . V_405 = F_281 ( F_280 () ,
V_2 -> V_405 ) ;
} else if ( V_2 -> V_343 == V_458 ) {
V_396 . V_46 = V_459 ;
}
V_91 = F_316 ( V_277 , ( void * ) & V_396 , V_397 ) ;
if ( V_91 < 0 )
goto V_302;
}
V_448 = V_2 -> V_172 ;
if ( V_448 > V_172 ) {
V_448 = V_172 ;
V_277 -> V_380 |= V_450 ;
}
V_91 = F_317 ( V_2 , 0 , V_277 , V_448 ) ;
if ( V_91 )
goto V_302;
if ( V_23 -> type != V_436 ) {
struct V_316 * V_317 = & F_214 ( V_2 ) -> V_268 . V_328 ;
V_335 = F_214 ( V_2 ) -> V_268 . V_335 ;
V_317 -> V_358 = V_359 ;
V_317 -> V_360 = V_2 -> V_274 ;
}
F_318 ( V_277 , V_24 , V_2 ) ;
if ( V_277 -> V_279 ) {
if ( V_23 -> type == V_436 ) {
F_319 ( sizeof( struct V_262 ) ) ;
V_277 -> V_282 = sizeof( struct V_262 ) ;
} else {
struct V_316 * V_317 = & F_214 ( V_2 ) -> V_268 . V_328 ;
V_277 -> V_282 = V_317 -> V_333 +
F_268 ( struct V_316 , V_334 ) ;
}
memcpy ( V_277 -> V_279 , & F_214 ( V_2 ) -> V_268 ,
V_277 -> V_282 ) ;
}
if ( F_36 ( V_24 ) -> V_460 ) {
struct V_461 V_462 ;
V_462 . V_40 = V_141 ;
if ( V_2 -> V_343 == V_344 )
V_462 . V_40 |= V_345 ;
else if ( V_2 -> V_264 != V_323 &&
( V_2 -> V_343 == V_346 ||
F_252 ( V_2 ) ) )
V_462 . V_40 |= V_347 ;
V_462 . V_354 = V_335 ;
V_462 . V_355 = V_2 -> V_172 ;
V_462 . V_356 = 0 ;
V_462 . V_357 = F_240 ( V_2 ) ;
if ( F_115 ( V_2 ) ) {
V_462 . V_163 = F_116 ( V_2 ) ;
V_462 . V_164 = F_117 ( V_2 -> V_165 ) ;
V_462 . V_40 |= V_166 | V_167 ;
} else {
V_462 . V_163 = 0 ;
V_462 . V_164 = 0 ;
}
F_320 ( V_277 , V_453 , V_463 , sizeof( V_462 ) , & V_462 ) ;
}
V_91 = V_397 + ( ( V_46 & V_450 ) ? V_2 -> V_172 : V_448 ) ;
V_302:
F_321 ( V_24 , V_2 ) ;
V_129:
return V_91 ;
}
static int F_322 ( struct V_275 * V_23 , struct V_283 * V_429 ,
int * V_464 , int V_465 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_465 )
return - V_466 ;
V_429 -> V_467 = V_359 ;
memset ( V_429 -> V_431 , 0 , sizeof( V_429 -> V_431 ) ) ;
F_20 () ;
V_4 = F_323 ( F_78 ( V_24 ) , F_36 ( V_24 ) -> V_93 ) ;
if ( V_4 )
F_217 ( V_429 -> V_431 , V_4 -> V_272 , sizeof( V_429 -> V_431 ) ) ;
F_24 () ;
* V_464 = sizeof( * V_429 ) ;
return 0 ;
}
static int F_324 ( struct V_275 * V_23 , struct V_283 * V_429 ,
int * V_464 , int V_465 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
F_220 ( struct V_316 * , V_317 , V_429 ) ;
if ( V_465 )
return - V_466 ;
V_317 -> V_358 = V_359 ;
V_317 -> V_332 = V_14 -> V_93 ;
V_317 -> V_360 = V_14 -> V_206 ;
V_317 -> V_330 = 0 ;
F_20 () ;
V_4 = F_323 ( F_78 ( V_24 ) , V_14 -> V_93 ) ;
if ( V_4 ) {
V_317 -> V_329 = V_4 -> type ;
V_317 -> V_333 = V_4 -> V_430 ;
memcpy ( V_317 -> V_334 , V_4 -> V_468 , V_4 -> V_430 ) ;
} else {
V_317 -> V_329 = 0 ;
V_317 -> V_333 = 0 ;
}
F_24 () ;
* V_464 = F_268 ( struct V_316 , V_334 ) + V_317 -> V_333 ;
return 0 ;
}
static int F_325 ( struct V_3 * V_4 , struct V_469 * V_199 ,
int V_470 )
{
switch ( V_199 -> type ) {
case V_471 :
if ( V_199 -> V_472 != V_4 -> V_430 )
return - V_244 ;
if ( V_470 > 0 )
return F_326 ( V_4 , V_199 -> V_31 ) ;
else
return F_327 ( V_4 , V_199 -> V_31 ) ;
break;
case V_473 :
return F_328 ( V_4 , V_470 ) ;
case V_474 :
return F_329 ( V_4 , V_470 ) ;
case V_475 :
if ( V_199 -> V_472 != V_4 -> V_430 )
return - V_244 ;
if ( V_470 > 0 )
return F_330 ( V_4 , V_199 -> V_31 ) ;
else
return F_331 ( V_4 , V_199 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_332 ( struct V_3 * V_4 ,
struct V_469 * * V_476 )
{
struct V_469 * V_477 ;
while ( ( V_477 = * V_476 ) != NULL ) {
if ( V_477 -> V_93 == V_4 -> V_93 ) {
F_325 ( V_4 , V_477 , - 1 ) ;
* V_476 = V_477 -> V_478 ;
F_204 ( V_477 ) ;
} else
V_476 = & V_477 -> V_478 ;
}
}
static int F_333 ( struct V_23 * V_24 , struct V_479 * V_480 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_469 * V_477 , * V_199 ;
struct V_3 * V_4 ;
int V_91 ;
F_76 () ;
V_91 = - V_286 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_480 -> V_481 ) ;
if ( ! V_4 )
goto V_482;
V_91 = - V_244 ;
if ( V_480 -> V_483 > V_4 -> V_430 )
goto V_482;
V_91 = - V_182 ;
V_199 = F_334 ( sizeof( * V_199 ) , V_252 ) ;
if ( V_199 == NULL )
goto V_482;
V_91 = 0 ;
for ( V_477 = V_14 -> V_484 ; V_477 ; V_477 = V_477 -> V_478 ) {
if ( V_477 -> V_93 == V_480 -> V_481 &&
V_477 -> type == V_480 -> V_485 &&
V_477 -> V_472 == V_480 -> V_483 &&
memcmp ( V_477 -> V_31 , V_480 -> V_486 , V_477 -> V_472 ) == 0 ) {
V_477 -> V_200 ++ ;
F_204 ( V_199 ) ;
goto V_482;
}
}
V_199 -> type = V_480 -> V_485 ;
V_199 -> V_93 = V_480 -> V_481 ;
V_199 -> V_472 = V_480 -> V_483 ;
memcpy ( V_199 -> V_31 , V_480 -> V_486 , V_199 -> V_472 ) ;
V_199 -> V_200 = 1 ;
V_199 -> V_478 = V_14 -> V_484 ;
V_14 -> V_484 = V_199 ;
V_91 = F_325 ( V_4 , V_199 , 1 ) ;
if ( V_91 ) {
V_14 -> V_484 = V_199 -> V_478 ;
F_204 ( V_199 ) ;
}
V_482:
F_79 () ;
return V_91 ;
}
static int F_335 ( struct V_23 * V_24 , struct V_479 * V_480 )
{
struct V_469 * V_477 , * * V_476 ;
F_76 () ;
for ( V_476 = & F_36 ( V_24 ) -> V_484 ; ( V_477 = * V_476 ) != NULL ; V_476 = & V_477 -> V_478 ) {
if ( V_477 -> V_93 == V_480 -> V_481 &&
V_477 -> type == V_480 -> V_485 &&
V_477 -> V_472 == V_480 -> V_483 &&
memcmp ( V_477 -> V_31 , V_480 -> V_486 , V_477 -> V_472 ) == 0 ) {
if ( -- V_477 -> V_200 == 0 ) {
struct V_3 * V_4 ;
* V_476 = V_477 -> V_478 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_477 -> V_93 ) ;
if ( V_4 )
F_325 ( V_4 , V_477 , - 1 ) ;
F_204 ( V_477 ) ;
}
break;
}
}
F_79 () ;
return 0 ;
}
static void F_291 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_469 * V_477 ;
if ( ! V_14 -> V_484 )
return;
F_76 () ;
while ( ( V_477 = V_14 -> V_484 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_484 = V_477 -> V_478 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_477 -> V_93 ) ;
if ( V_4 != NULL )
F_325 ( V_4 , V_477 , - 1 ) ;
F_204 ( V_477 ) ;
}
F_79 () ;
}
static int
F_336 ( struct V_275 * V_23 , int V_487 , int V_488 , char T_7 * V_489 , unsigned int V_490 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_8 ;
if ( V_487 != V_453 )
return - V_491 ;
switch ( V_488 ) {
case V_492 :
case V_493 :
{
struct V_479 V_480 ;
int V_172 = V_490 ;
memset ( & V_480 , 0 , sizeof( V_480 ) ) ;
if ( V_172 < sizeof( struct V_494 ) )
return - V_244 ;
if ( V_172 > sizeof( V_480 ) )
V_172 = sizeof( V_480 ) ;
if ( F_185 ( & V_480 , V_489 , V_172 ) )
return - V_245 ;
if ( V_172 < ( V_480 . V_483 + F_268 ( struct V_494 , V_486 ) ) )
return - V_244 ;
if ( V_488 == V_492 )
V_8 = F_333 ( V_24 , & V_480 ) ;
else
V_8 = F_335 ( V_24 , & V_480 ) ;
return V_8 ;
}
case V_495 :
case V_496 :
{
union V_98 V_99 ;
int V_172 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_172 = sizeof( V_99 . V_497 ) ;
break;
case V_43 :
default:
V_172 = sizeof( V_99 . V_101 ) ;
break;
}
if ( V_490 < V_172 )
return - V_244 ;
if ( F_36 ( V_24 ) -> V_401 )
return - V_244 ;
if ( F_185 ( & V_99 . V_497 , V_489 , V_172 ) )
return - V_245 ;
return F_292 ( V_24 , & V_99 , 0 ,
V_488 == V_496 ) ;
}
case V_498 :
{
int V_207 ;
if ( V_490 != sizeof( V_207 ) )
return - V_244 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
F_36 ( V_24 ) -> V_350 = V_207 ;
return 0 ;
}
case V_499 :
{
int V_207 ;
if ( V_490 != sizeof( V_207 ) )
return - V_244 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_500 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
switch ( V_207 ) {
case V_38 :
case V_41 :
case V_43 :
V_14 -> V_37 = V_207 ;
return 0 ;
default:
return - V_244 ;
}
}
case V_501 :
{
unsigned int V_207 ;
if ( V_490 != sizeof( V_207 ) )
return - V_244 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_500 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
V_14 -> V_348 = V_207 ;
return 0 ;
}
case V_502 :
{
unsigned int V_207 ;
if ( V_490 != sizeof( V_207 ) )
return - V_244 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_500 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
V_14 -> V_388 = ! ! V_207 ;
return 0 ;
}
case V_463 :
{
int V_207 ;
if ( V_490 < sizeof( V_207 ) )
return - V_244 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
V_14 -> V_460 = ! ! V_207 ;
return 0 ;
}
case V_503 :
{
int V_207 ;
if ( V_490 < sizeof( V_207 ) )
return - V_244 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
V_14 -> V_331 = ! ! V_207 ;
return 0 ;
}
case V_504 :
{
int V_207 ;
if ( V_23 -> type != V_400 )
return - V_244 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_500 ;
if ( V_490 < sizeof( V_207 ) )
return - V_244 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
V_14 -> V_401 = ! ! V_207 ;
return 0 ;
}
case V_505 :
{
int V_207 ;
if ( V_490 != sizeof( V_207 ) )
return - V_244 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
V_14 -> V_55 = V_207 ;
return 0 ;
}
case V_506 :
{
int V_207 ;
if ( V_490 != sizeof( V_207 ) )
return - V_244 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
return F_194 ( V_24 , V_207 & 0xffff , V_207 >> 16 ) ;
}
case V_507 :
{
if ( ! V_14 -> V_26 )
return - V_244 ;
return F_192 ( V_14 , V_489 , V_490 ) ;
}
case V_508 :
{
unsigned int V_207 ;
if ( V_490 != sizeof( V_207 ) )
return - V_244 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_500 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
V_14 -> V_372 = ! ! V_207 ;
return 0 ;
}
case V_509 :
{
int V_207 ;
if ( V_490 != sizeof( V_207 ) )
return - V_244 ;
if ( F_185 ( & V_207 , V_489 , sizeof( V_207 ) ) )
return - V_245 ;
V_14 -> V_16 = V_207 ? F_1 : F_235 ;
return 0 ;
}
default:
return - V_491 ;
}
}
static int F_337 ( struct V_275 * V_23 , int V_487 , int V_488 ,
char T_7 * V_489 , int T_7 * V_490 )
{
int V_172 ;
int V_207 , V_510 = sizeof( V_207 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
void * V_80 = & V_207 ;
union V_511 V_512 ;
struct V_513 V_514 ;
if ( V_487 != V_453 )
return - V_491 ;
if ( F_338 ( V_172 , V_490 ) )
return - V_245 ;
if ( V_172 < 0 )
return - V_244 ;
switch ( V_488 ) {
case V_515 :
F_69 ( & V_24 -> V_128 . V_78 ) ;
memcpy ( & V_512 , & V_14 -> V_117 , sizeof( V_512 ) ) ;
memset ( & V_14 -> V_117 , 0 , sizeof( V_14 -> V_117 ) ) ;
F_70 ( & V_24 -> V_128 . V_78 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_510 = sizeof( struct V_516 ) ;
V_512 . V_118 . V_337 += V_512 . V_118 . V_147 ;
V_80 = & V_512 . V_118 ;
} else {
V_510 = sizeof( struct V_517 ) ;
V_512 . V_336 . V_337 += V_512 . V_336 . V_147 ;
V_80 = & V_512 . V_336 ;
}
break;
case V_463 :
V_207 = V_14 -> V_460 ;
break;
case V_503 :
V_207 = V_14 -> V_331 ;
break;
case V_504 :
V_207 = V_14 -> V_401 ;
break;
case V_499 :
V_207 = V_14 -> V_37 ;
break;
case V_518 :
if ( V_172 > sizeof( int ) )
V_172 = sizeof( int ) ;
if ( F_185 ( & V_207 , V_489 , V_172 ) )
return - V_245 ;
switch ( V_207 ) {
case V_38 :
V_207 = sizeof( struct V_519 ) ;
break;
case V_41 :
V_207 = sizeof( struct V_520 ) ;
break;
case V_43 :
V_207 = sizeof( struct V_142 ) ;
break;
default:
return - V_244 ;
}
break;
case V_501 :
V_207 = V_14 -> V_348 ;
break;
case V_502 :
V_207 = V_14 -> V_388 ;
break;
case V_505 :
V_207 = V_14 -> V_55 ;
break;
case V_506 :
V_207 = ( V_14 -> V_26 ?
( ( T_5 ) V_14 -> V_26 -> V_248 |
( ( T_5 ) V_14 -> V_26 -> type << 16 ) |
( ( T_5 ) V_14 -> V_26 -> V_46 << 24 ) ) :
0 ) ;
break;
case V_521 :
if ( ! V_14 -> V_202 )
return - V_244 ;
V_514 . V_522 = F_339 ( & V_14 -> V_202 -> V_206 ) ;
V_514 . V_523 = F_339 ( & V_14 -> V_202 -> V_215 ) ;
V_514 . V_524 = F_339 ( & V_14 -> V_202 -> V_216 ) ;
V_80 = & V_514 ;
V_510 = sizeof( V_514 ) ;
break;
case V_508 :
V_207 = V_14 -> V_372 ;
break;
case V_509 :
V_207 = F_29 ( V_14 ) ;
break;
default:
return - V_491 ;
}
if ( V_172 > V_510 )
V_172 = V_510 ;
if ( F_340 ( V_172 , V_490 ) )
return - V_245 ;
if ( F_341 ( V_489 , V_80 , V_172 ) )
return - V_245 ;
return 0 ;
}
static int F_342 ( struct V_525 * V_526 ,
unsigned long V_277 , void * V_527 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_343 ( V_527 ) ;
struct V_225 * V_225 = F_173 ( V_4 ) ;
F_20 () ;
F_344 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_36 ( V_24 ) ;
switch ( V_277 ) {
case V_528 :
if ( V_14 -> V_484 )
F_332 ( V_4 , & V_14 -> V_484 ) ;
case V_529 :
if ( V_4 -> V_93 == V_14 -> V_93 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_40 ( V_24 , false ) ;
V_24 -> V_427 = V_288 ;
if ( ! F_151 ( V_24 , V_197 ) )
V_24 -> V_428 ( V_24 ) ;
}
if ( V_277 == V_528 ) {
F_27 ( V_14 ) ;
V_14 -> V_93 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_274 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
}
break;
case V_530 :
if ( V_4 -> V_93 == V_14 -> V_93 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_206 )
F_35 ( V_24 ) ;
F_44 ( & V_14 -> V_29 ) ;
}
break;
}
}
F_24 () ;
return V_531 ;
}
static int F_345 ( struct V_275 * V_23 , unsigned int V_532 ,
unsigned long V_533 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_532 ) {
case V_534 :
{
int V_535 = F_346 ( V_24 ) ;
return F_340 ( V_535 , ( int T_7 * ) V_533 ) ;
}
case V_536 :
{
struct V_1 * V_2 ;
int V_535 = 0 ;
F_69 ( & V_24 -> V_128 . V_78 ) ;
V_2 = F_347 ( & V_24 -> V_128 ) ;
if ( V_2 )
V_535 = V_2 -> V_172 ;
F_70 ( & V_24 -> V_128 . V_78 ) ;
return F_340 ( V_535 , ( int T_7 * ) V_533 ) ;
}
case V_537 :
return F_348 ( V_24 , (struct V_538 T_7 * ) V_533 ) ;
case V_539 :
return F_349 ( V_24 , (struct V_44 T_7 * ) V_533 ) ;
#ifdef F_350
case V_540 :
case V_541 :
case V_542 :
case V_543 :
case V_544 :
case V_545 :
case V_546 :
case V_547 :
case V_548 :
case V_549 :
case V_550 :
case V_551 :
case V_552 :
case V_553 :
return V_554 . V_555 ( V_23 , V_532 , V_533 ) ;
#endif
default:
return - V_556 ;
}
return 0 ;
}
static unsigned int F_351 ( struct V_557 * V_557 , struct V_275 * V_23 ,
T_11 * V_558 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned int V_559 = F_352 ( V_557 , V_23 , V_558 ) ;
F_69 ( & V_24 -> V_128 . V_78 ) ;
if ( V_14 -> V_77 . V_68 ) {
if ( ! F_129 ( V_14 , & V_14 -> V_77 ,
V_159 ) )
V_559 |= V_560 | V_561 ;
}
if ( V_14 -> V_194 && F_146 ( V_14 , NULL ) == V_191 )
V_14 -> V_194 = 0 ;
F_70 ( & V_24 -> V_128 . V_78 ) ;
F_69 ( & V_24 -> V_562 . V_78 ) ;
if ( V_14 -> V_181 . V_68 ) {
if ( F_64 ( V_14 , & V_14 -> V_181 , V_168 ) )
V_559 |= V_563 | V_564 ;
}
F_70 ( & V_24 -> V_562 . V_78 ) ;
return V_559 ;
}
static void F_353 ( struct V_565 * V_566 )
{
struct V_557 * V_557 = V_566 -> V_567 ;
struct V_275 * V_23 = V_557 -> V_568 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_121 ( & F_36 ( V_24 ) -> V_569 ) ;
}
static void F_354 ( struct V_565 * V_566 )
{
struct V_557 * V_557 = V_566 -> V_567 ;
struct V_275 * V_23 = V_557 -> V_568 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_110 ( & F_36 ( V_24 ) -> V_569 ) ;
}
static void F_355 ( struct V_103 * V_68 , unsigned int V_570 ,
unsigned int V_172 )
{
int V_199 ;
for ( V_199 = 0 ; V_199 < V_172 ; V_199 ++ ) {
if ( F_22 ( V_68 [ V_199 ] . V_69 ) ) {
if ( F_49 ( V_68 [ V_199 ] . V_69 ) )
F_356 ( V_68 [ V_199 ] . V_69 ) ;
else
F_357 ( ( unsigned long ) V_68 [ V_199 ] . V_69 ,
V_570 ) ;
V_68 [ V_199 ] . V_69 = NULL ;
}
}
F_204 ( V_68 ) ;
}
static char * F_358 ( unsigned long V_570 )
{
char * V_69 ;
T_12 V_571 = V_252 | V_572 |
V_573 | V_574 | V_575 ;
V_69 = ( char * ) F_359 ( V_571 , V_570 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_360 ( ( 1 << V_570 ) * V_138 ) ;
if ( V_69 )
return V_69 ;
V_571 &= ~ V_575 ;
V_69 = ( char * ) F_359 ( V_571 , V_570 ) ;
if ( V_69 )
return V_69 ;
return NULL ;
}
static struct V_103 * F_361 ( struct V_576 * V_497 , int V_570 )
{
unsigned int V_577 = V_497 -> V_112 ;
struct V_103 * V_68 ;
int V_199 ;
V_68 = F_362 ( V_577 , sizeof( struct V_103 ) , V_252 ) ;
if ( F_2 ( ! V_68 ) )
goto V_129;
for ( V_199 = 0 ; V_199 < V_577 ; V_199 ++ ) {
V_68 [ V_199 ] . V_69 = F_358 ( V_570 ) ;
if ( F_2 ( ! V_68 [ V_199 ] . V_69 ) )
goto V_578;
}
V_129:
return V_68 ;
V_578:
F_355 ( V_68 , V_570 , V_577 ) ;
V_68 = NULL ;
goto V_129;
}
static int F_292 ( struct V_23 * V_24 , union V_98 * V_99 ,
int V_579 , int V_181 )
{
struct V_103 * V_68 = NULL ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_580 , V_570 = 0 ;
struct V_62 * V_63 ;
struct V_75 * V_76 ;
T_9 V_206 ;
int V_91 = - V_244 ;
struct V_576 * V_497 = & V_99 -> V_497 ;
if ( ! V_579 && V_181 && ( V_14 -> V_37 > V_41 ) ) {
F_54 ( 1 , L_8 ) ;
goto V_129;
}
V_63 = V_181 ? & V_14 -> V_181 : & V_14 -> V_77 ;
V_76 = V_181 ? & V_24 -> V_562 : & V_24 -> V_128 ;
V_91 = - V_500 ;
if ( ! V_579 ) {
if ( F_92 ( & V_14 -> V_569 ) )
goto V_129;
if ( F_137 ( V_63 ) )
goto V_129;
}
if ( V_497 -> V_112 ) {
V_91 = - V_500 ;
if ( F_2 ( V_63 -> V_68 ) )
goto V_129;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_114 = V_581 ;
break;
case V_41 :
V_14 -> V_114 = V_582 ;
break;
case V_43 :
V_14 -> V_114 = V_583 ;
break;
}
V_91 = - V_244 ;
if ( F_2 ( ( int ) V_497 -> V_110 <= 0 ) )
goto V_129;
if ( F_2 ( V_497 -> V_110 & ( V_138 - 1 ) ) )
goto V_129;
if ( V_14 -> V_37 >= V_43 &&
( int ) ( V_497 -> V_110 -
F_85 ( V_99 -> V_101 . V_124 ) ) <= 0 )
goto V_129;
if ( F_2 ( V_497 -> V_584 < V_14 -> V_114 +
V_14 -> V_348 ) )
goto V_129;
if ( F_2 ( V_497 -> V_584 & ( V_585 - 1 ) ) )
goto V_129;
V_63 -> V_67 = V_497 -> V_110 / V_497 -> V_584 ;
if ( F_2 ( V_63 -> V_67 <= 0 ) )
goto V_129;
if ( F_2 ( ( V_63 -> V_67 * V_497 -> V_112 ) !=
V_497 -> V_586 ) )
goto V_129;
V_91 = - V_253 ;
V_570 = F_363 ( V_497 -> V_110 ) ;
V_68 = F_361 ( V_497 , V_570 ) ;
if ( F_2 ( ! V_68 ) )
goto V_129;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( ! V_181 )
F_83 ( V_14 , V_63 , V_68 , V_99 ) ;
break;
default:
break;
}
}
else {
V_91 = - V_244 ;
if ( F_2 ( V_497 -> V_586 ) )
goto V_129;
}
F_297 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_580 = V_14 -> V_25 ;
V_206 = V_14 -> V_206 ;
if ( V_580 ) {
V_14 -> V_206 = 0 ;
F_40 ( V_24 , false ) ;
}
F_44 ( & V_14 -> V_29 ) ;
F_45 () ;
V_91 = - V_500 ;
F_197 ( & V_14 -> V_383 ) ;
if ( V_579 || F_92 ( & V_14 -> V_569 ) == 0 ) {
V_91 = 0 ;
F_69 ( & V_76 -> V_78 ) ;
F_364 ( V_63 -> V_68 , V_68 ) ;
V_63 -> V_176 = ( V_497 -> V_586 - 1 ) ;
V_63 -> V_71 = 0 ;
V_63 -> V_70 = V_497 -> V_584 ;
F_70 ( & V_76 -> V_78 ) ;
F_364 ( V_63 -> V_587 , V_570 ) ;
F_364 ( V_63 -> V_588 , V_497 -> V_112 ) ;
V_63 -> V_589 = V_497 -> V_110 / V_138 ;
V_14 -> V_27 . F_72 = ( V_14 -> V_77 . V_68 ) ?
V_185 : F_238 ;
F_149 ( V_76 ) ;
if ( F_92 ( & V_14 -> V_569 ) )
F_152 ( L_9 ,
F_92 ( & V_14 -> V_569 ) ) ;
}
F_203 ( & V_14 -> V_383 ) ;
F_46 ( & V_14 -> V_29 ) ;
if ( V_580 ) {
V_14 -> V_206 = V_206 ;
F_35 ( V_24 ) ;
}
F_44 ( & V_14 -> V_29 ) ;
if ( V_579 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_181 )
F_67 ( V_14 , V_76 ) ;
}
F_298 ( V_24 ) ;
if ( V_68 )
F_355 ( V_68 , V_570 , V_497 -> V_112 ) ;
V_129:
return V_91 ;
}
static int F_365 ( struct V_557 * V_557 , struct V_275 * V_23 ,
struct V_565 * V_566 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned long V_590 , V_591 ;
struct V_62 * V_63 ;
unsigned long V_136 ;
int V_91 = - V_244 ;
int V_199 ;
if ( V_566 -> V_592 )
return - V_244 ;
F_197 ( & V_14 -> V_383 ) ;
V_591 = 0 ;
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_181 ; V_63 ++ ) {
if ( V_63 -> V_68 ) {
V_591 += V_63 -> V_588
* V_63 -> V_589
* V_138 ;
}
}
if ( V_591 == 0 )
goto V_129;
V_590 = V_566 -> V_593 - V_566 -> V_594 ;
if ( V_590 != V_591 )
goto V_129;
V_136 = V_566 -> V_594 ;
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_181 ; V_63 ++ ) {
if ( V_63 -> V_68 == NULL )
continue;
for ( V_199 = 0 ; V_199 < V_63 -> V_588 ; V_199 ++ ) {
struct V_30 * V_30 ;
void * V_595 = V_63 -> V_68 [ V_199 ] . V_69 ;
int V_596 ;
for ( V_596 = 0 ; V_596 < V_63 -> V_589 ; V_596 ++ ) {
V_30 = F_48 ( V_595 ) ;
V_91 = F_366 ( V_566 , V_136 , V_30 ) ;
if ( F_2 ( V_91 ) )
goto V_129;
V_136 += V_138 ;
V_595 += V_138 ;
}
}
}
F_121 ( & V_14 -> V_569 ) ;
V_566 -> V_597 = & V_598 ;
V_91 = 0 ;
V_129:
F_203 ( & V_14 -> V_383 ) ;
return V_91 ;
}
static void * F_367 ( struct V_599 * V_600 , T_13 * V_601 )
__acquires( T_14 )
{
struct V_225 * V_225 = F_368 ( V_600 ) ;
F_20 () ;
return F_369 ( & V_225 -> V_421 . V_447 , * V_601 ) ;
}
static void * F_370 ( struct V_599 * V_600 , void * V_602 , T_13 * V_601 )
{
struct V_225 * V_225 = F_368 ( V_600 ) ;
return F_371 ( V_602 , & V_225 -> V_421 . V_447 , V_601 ) ;
}
static void F_372 ( struct V_599 * V_600 , void * V_602 )
__releases( T_14 )
{
F_24 () ;
}
static int F_373 ( struct V_599 * V_600 , void * V_602 )
{
if ( V_602 == V_603 )
F_374 ( V_600 , L_10 ) ;
else {
struct V_23 * V_417 = F_375 ( V_602 ) ;
const struct V_13 * V_14 = F_36 ( V_417 ) ;
F_376 ( V_600 ,
L_11 ,
V_417 ,
F_92 ( & V_417 -> V_604 ) ,
V_417 -> V_321 ,
F_117 ( V_14 -> V_206 ) ,
V_14 -> V_93 ,
V_14 -> V_25 ,
F_92 ( & V_417 -> V_188 ) ,
F_377 ( F_378 ( V_600 ) , F_379 ( V_417 ) ) ,
F_380 ( V_417 ) ) ;
}
return 0 ;
}
static int F_381 ( struct V_605 * V_605 , struct V_557 * V_557 )
{
return F_382 ( V_605 , V_557 , & V_606 ,
sizeof( struct V_607 ) ) ;
}
static int T_15 F_383 ( struct V_225 * V_225 )
{
F_307 ( & V_225 -> V_421 . V_422 ) ;
F_384 ( & V_225 -> V_421 . V_447 ) ;
if ( ! F_385 ( L_12 , 0 , V_225 -> V_608 , & V_609 ) )
return - V_253 ;
return 0 ;
}
static void T_16 F_386 ( struct V_225 * V_225 )
{
F_387 ( L_12 , V_225 -> V_608 ) ;
}
static void T_17 F_388 ( void )
{
F_389 ( & V_610 ) ;
F_390 ( & V_611 ) ;
F_391 ( V_440 ) ;
F_392 ( & V_441 ) ;
}
static int T_18 F_393 ( void )
{
int V_612 = F_394 ( & V_441 , 0 ) ;
if ( V_612 != 0 )
goto V_129;
F_395 ( & V_613 ) ;
F_396 ( & V_611 ) ;
F_397 ( & V_610 ) ;
V_129:
return V_612 ;
}
