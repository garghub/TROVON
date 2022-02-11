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
struct V_225 * V_225 = F_172 ( & V_205 -> V_225 ) ;
struct V_13 * V_14 ;
unsigned int V_173 ;
if ( ! F_173 ( F_174 ( V_4 ) , V_225 ) || ! V_206 ) {
F_17 ( V_2 ) ;
return 0 ;
}
if ( F_169 ( V_205 , V_226 ) ) {
V_2 = F_175 ( V_225 , V_2 , V_227 ) ;
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
if ( V_24 -> V_238 != V_239 )
return false ;
return V_237 -> V_223 == F_36 ( V_24 ) -> V_26 ;
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
static void F_180 ( struct V_204 * V_205 , struct V_217 * V_240 )
{
struct V_217 * V_241 ;
F_46 ( & V_205 -> V_78 ) ;
V_241 = F_181 ( V_205 -> V_217 , F_182 ( & V_205 -> V_78 ) ) ;
F_26 ( V_205 -> V_217 , V_240 ) ;
F_44 ( & V_205 -> V_78 ) ;
if ( V_241 ) {
F_45 () ;
F_183 ( V_241 ) ;
}
}
static int F_184 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_172 )
{
struct V_217 * V_240 ;
struct V_242 V_243 ;
int V_8 ;
if ( F_151 ( & V_14 -> V_24 , V_244 ) )
return - V_245 ;
if ( V_172 != sizeof( V_243 ) )
return - V_246 ;
if ( F_185 ( & V_243 , V_80 , V_172 ) )
return - V_247 ;
V_8 = F_186 ( & V_240 , & V_243 , NULL , false ) ;
if ( V_8 )
return V_8 ;
F_180 ( V_14 -> V_26 , V_240 ) ;
return 0 ;
}
static int F_187 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_172 )
{
struct V_217 * V_240 ;
T_5 V_248 ;
if ( F_151 ( & V_14 -> V_24 , V_244 ) )
return - V_245 ;
if ( V_172 != sizeof( V_248 ) )
return - V_246 ;
if ( F_185 ( & V_248 , V_80 , V_172 ) )
return - V_247 ;
V_240 = F_188 ( V_248 ) ;
if ( F_189 ( V_240 ) )
return F_190 ( V_240 ) ;
if ( V_240 -> type != V_249 ) {
F_191 ( V_240 ) ;
return - V_246 ;
}
F_180 ( V_14 -> V_26 , V_240 ) ;
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
return - V_246 ;
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
static int F_194 ( struct V_23 * V_24 , T_2 V_250 , T_2 V_251 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_204 * V_205 , * V_252 ;
T_6 type = V_251 & 0xff ;
T_6 V_46 = V_251 >> 8 ;
int V_91 ;
switch ( type ) {
case V_233 :
if ( V_251 & V_236 )
return - V_246 ;
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_234 :
case V_235 :
break;
default:
return - V_246 ;
}
if ( ! V_14 -> V_25 )
return - V_246 ;
if ( V_14 -> V_26 )
return - V_253 ;
if ( type == V_233 ||
( V_251 & V_236 ) ) {
V_14 -> V_202 = F_195 ( sizeof( * V_14 -> V_202 ) , V_254 ) ;
if ( ! V_14 -> V_202 )
return - V_255 ;
F_196 ( & V_14 -> V_202 -> V_206 , 0 ) ;
F_196 ( & V_14 -> V_202 -> V_215 , 0 ) ;
F_196 ( & V_14 -> V_202 -> V_216 , 0 ) ;
}
F_197 ( & V_256 ) ;
V_252 = NULL ;
F_198 (f, &fanout_list, list) {
if ( V_205 -> V_250 == V_250 &&
F_172 ( & V_205 -> V_225 ) == F_78 ( V_24 ) ) {
V_252 = V_205 ;
break;
}
}
V_91 = - V_246 ;
if ( V_252 && V_252 -> V_46 != V_46 )
goto V_129;
if ( ! V_252 ) {
V_91 = - V_255 ;
V_252 = F_195 ( sizeof( * V_252 ) , V_254 ) ;
if ( ! V_252 )
goto V_129;
F_199 ( & V_252 -> V_225 , F_78 ( V_24 ) ) ;
V_252 -> V_250 = V_250 ;
V_252 -> type = type ;
V_252 -> V_46 = V_46 ;
F_200 ( & V_252 -> V_257 ) ;
F_201 ( & V_252 -> V_78 ) ;
F_179 ( & V_252 -> V_258 , 0 ) ;
F_178 ( V_252 ) ;
V_252 -> V_27 . type = V_14 -> V_27 . type ;
V_252 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_252 -> V_27 . F_72 = F_170 ;
V_252 -> V_27 . V_223 = V_252 ;
V_252 -> V_27 . V_259 = F_177 ;
F_38 ( & V_252 -> V_27 ) ;
F_202 ( & V_252 -> V_257 , & V_260 ) ;
}
V_91 = - V_246 ;
if ( V_252 -> type == type &&
V_252 -> V_27 . type == V_14 -> V_27 . type &&
V_252 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_91 = - V_261 ;
if ( F_92 ( & V_252 -> V_258 ) < V_262 ) {
F_42 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_252 ;
F_121 ( & V_252 -> V_258 ) ;
F_37 ( V_24 , V_14 ) ;
V_91 = 0 ;
}
}
V_129:
F_203 ( & V_256 ) ;
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
F_197 ( & V_256 ) ;
V_14 -> V_26 = NULL ;
if ( F_206 ( & V_205 -> V_258 ) ) {
F_207 ( & V_205 -> V_257 ) ;
F_208 ( & V_205 -> V_27 ) ;
F_193 ( V_205 ) ;
F_204 ( V_205 ) ;
}
F_203 ( & V_256 ) ;
if ( V_14 -> V_202 )
F_209 ( V_14 -> V_202 , V_263 ) ;
}
static bool F_210 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( F_2 ( V_4 -> type != V_264 ) )
return false ;
F_211 ( V_2 ) ;
return F_22 ( F_212 ( V_2 ) -> V_265 == F_213 ( V_266 ) ) ;
}
static int F_214 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_220 * V_221 , struct V_3 * V_222 )
{
struct V_23 * V_24 ;
struct V_267 * V_268 ;
V_24 = V_221 -> V_223 ;
if ( V_2 -> V_269 == V_270 )
goto V_129;
if ( ! F_173 ( F_174 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_129;
V_2 = F_215 ( V_2 , V_271 ) ;
if ( V_2 == NULL )
goto V_272;
F_216 ( V_2 ) ;
F_217 ( V_2 ) ;
V_268 = & F_218 ( V_2 ) -> V_273 . V_274 ;
F_219 ( V_2 , V_2 -> V_80 - F_220 ( V_2 ) ) ;
V_268 -> V_275 = V_4 -> type ;
F_221 ( V_268 -> V_276 , V_4 -> V_277 , sizeof( V_268 -> V_276 ) ) ;
V_268 -> V_278 = V_2 -> V_279 ;
if ( F_222 ( V_24 , V_2 ) == 0 )
return 0 ;
V_129:
F_17 ( V_2 ) ;
V_272:
return 0 ;
}
static int F_223 ( struct V_280 * V_23 , struct V_281 * V_282 ,
T_8 V_172 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_224 ( struct V_267 * , V_283 , V_282 -> V_284 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
T_9 V_285 = 0 ;
int V_91 ;
int V_286 = 0 ;
if ( V_283 ) {
if ( V_282 -> V_287 < sizeof( struct V_288 ) )
return - V_246 ;
if ( V_282 -> V_287 == sizeof( struct V_267 ) )
V_285 = V_283 -> V_278 ;
} else
return - V_289 ;
V_283 -> V_276 [ sizeof( V_283 -> V_276 ) - 1 ] = 0 ;
V_290:
F_20 () ;
V_4 = F_225 ( F_78 ( V_24 ) , V_283 -> V_276 ) ;
V_91 = - V_291 ;
if ( V_4 == NULL )
goto V_292;
V_91 = - V_293 ;
if ( ! ( V_4 -> V_46 & V_294 ) )
goto V_292;
if ( F_2 ( F_151 ( V_24 , V_295 ) ) ) {
if ( ! F_226 ( V_4 ) ) {
V_91 = - V_296 ;
goto V_292;
}
V_286 = 4 ;
}
V_91 = - V_297 ;
if ( V_172 > V_4 -> V_298 + V_4 -> V_299 + V_300 + V_286 )
goto V_292;
if ( ! V_2 ) {
T_8 V_301 = F_227 ( V_4 ) ;
int V_302 = V_4 -> V_303 ;
unsigned int V_304 = V_4 -> V_305 ? V_4 -> V_299 : 0 ;
F_24 () ;
V_2 = F_228 ( V_24 , V_172 + V_301 + V_302 , 0 , V_254 ) ;
if ( V_2 == NULL )
return - V_182 ;
F_229 ( V_2 , V_301 ) ;
F_230 ( V_2 ) ;
if ( V_304 ) {
V_2 -> V_80 -= V_304 ;
V_2 -> V_306 -= V_304 ;
if ( V_172 < V_304 )
F_230 ( V_2 ) ;
}
V_91 = F_231 ( F_232 ( V_2 , V_172 ) , V_282 , V_172 ) ;
if ( V_91 )
goto V_307;
goto V_290;
}
if ( V_172 > ( V_4 -> V_298 + V_4 -> V_299 + V_286 ) &&
! F_210 ( V_4 , V_2 ) ) {
V_91 = - V_297 ;
goto V_292;
}
V_2 -> V_279 = V_285 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_308 = V_24 -> V_309 ;
V_2 -> V_310 = V_24 -> V_311 ;
F_233 ( V_24 , & F_234 ( V_2 ) -> V_312 ) ;
if ( F_2 ( V_286 == 4 ) )
V_2 -> V_313 = 1 ;
F_235 ( V_2 , 0 ) ;
F_236 ( V_2 ) ;
F_24 () ;
return V_172 ;
V_292:
F_24 () ;
V_307:
F_17 ( V_2 ) ;
return V_91 ;
}
static unsigned int F_237 ( struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_314 )
{
struct V_315 * V_316 ;
F_20 () ;
V_316 = F_21 ( V_24 -> V_315 ) ;
if ( V_316 != NULL )
V_314 = F_168 ( V_316 -> V_218 , V_2 ) ;
F_24 () ;
return V_314 ;
}
static int F_238 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_220 * V_221 , struct V_3 * V_222 )
{
struct V_23 * V_24 ;
struct V_317 * V_318 ;
struct V_13 * V_14 ;
T_6 * V_319 = V_2 -> V_80 ;
int V_320 = V_2 -> V_172 ;
unsigned int V_321 , V_314 ;
if ( V_2 -> V_269 == V_270 )
goto V_10;
V_24 = V_221 -> V_223 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_173 ( F_174 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_305 ) {
if ( V_24 -> V_322 != V_323 )
F_219 ( V_2 , V_2 -> V_80 - F_220 ( V_2 ) ) ;
else if ( V_2 -> V_269 == V_324 ) {
F_239 ( V_2 , F_240 ( V_2 ) ) ;
}
}
V_321 = V_2 -> V_172 ;
V_314 = F_237 ( V_2 , V_24 , V_321 ) ;
if ( ! V_314 )
goto V_325;
if ( V_321 > V_314 )
V_321 = V_314 ;
if ( F_92 ( & V_24 -> V_188 ) >= V_24 -> V_187 )
goto V_326;
if ( F_241 ( V_2 ) ) {
struct V_1 * V_327 = F_242 ( V_2 , V_271 ) ;
if ( V_327 == NULL )
goto V_326;
if ( V_319 != V_2 -> V_80 ) {
V_2 -> V_80 = V_319 ;
V_2 -> V_172 = V_320 ;
}
F_243 ( V_2 ) ;
V_2 = V_327 ;
}
F_244 ( sizeof( * F_218 ( V_2 ) ) + V_328 - 8 ) ;
V_318 = & F_218 ( V_2 ) -> V_273 . V_329 ;
V_318 -> V_330 = V_4 -> type ;
V_318 -> V_331 = V_2 -> V_269 ;
if ( F_2 ( V_14 -> V_332 ) )
V_318 -> V_333 = V_222 -> V_93 ;
else
V_318 -> V_333 = V_4 -> V_93 ;
V_318 -> V_334 = F_245 ( V_2 , V_318 -> V_335 ) ;
F_218 ( V_2 ) -> V_273 . V_336 = V_2 -> V_172 ;
if ( F_246 ( V_2 , V_321 ) )
goto V_326;
F_247 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_216 ( V_2 ) ;
F_217 ( V_2 ) ;
F_46 ( & V_24 -> V_128 . V_78 ) ;
V_14 -> V_117 . V_337 . V_338 ++ ;
F_248 ( V_24 , V_2 ) ;
F_249 ( & V_24 -> V_128 , V_2 ) ;
F_44 ( & V_24 -> V_128 . V_78 ) ;
V_24 -> V_154 ( V_24 ) ;
return 0 ;
V_326:
F_46 ( & V_24 -> V_128 . V_78 ) ;
V_14 -> V_117 . V_337 . V_147 ++ ;
F_121 ( & V_24 -> V_339 ) ;
F_44 ( & V_24 -> V_128 . V_78 ) ;
V_325:
if ( V_319 != V_2 -> V_80 && F_241 ( V_2 ) ) {
V_2 -> V_80 = V_319 ;
V_2 -> V_172 = V_320 ;
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
struct V_317 * V_318 ;
union V_34 V_35 ;
T_6 * V_319 = V_2 -> V_80 ;
int V_320 = V_2 -> V_172 ;
unsigned int V_321 , V_314 ;
unsigned long V_33 = V_141 ;
unsigned short V_340 , V_341 , V_113 ;
struct V_1 * V_342 = NULL ;
struct V_44 V_45 ;
T_4 V_54 ;
F_250 ( F_251 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_250 ( F_251 ( sizeof( * V_35 . V_343 ) ) != 48 ) ;
if ( V_2 -> V_269 == V_270 )
goto V_10;
V_24 = V_221 -> V_223 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_173 ( F_174 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_305 ) {
if ( V_24 -> V_322 != V_323 )
F_219 ( V_2 , V_2 -> V_80 - F_220 ( V_2 ) ) ;
else if ( V_2 -> V_269 == V_324 ) {
F_239 ( V_2 , F_240 ( V_2 ) ) ;
}
}
V_321 = V_2 -> V_172 ;
V_314 = F_237 ( V_2 , V_24 , V_321 ) ;
if ( ! V_314 )
goto V_325;
if ( V_2 -> V_344 == V_345 )
V_33 |= V_346 ;
else if ( V_2 -> V_269 != V_324 &&
( V_2 -> V_344 == V_347 ||
F_252 ( V_2 ) ) )
V_33 |= V_348 ;
if ( V_321 > V_314 )
V_321 = V_314 ;
if ( V_24 -> V_322 == V_323 ) {
V_340 = V_341 = F_251 ( V_14 -> V_114 ) + 16 +
V_14 -> V_349 ;
} else {
unsigned int V_350 = F_240 ( V_2 ) ;
V_341 = F_251 ( V_14 -> V_114 +
( V_350 < 16 ? 16 : V_350 ) ) +
V_14 -> V_349 ;
V_340 = V_341 - V_350 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_340 + V_321 > V_14 -> V_77 . V_70 ) {
if ( V_14 -> V_351 &&
F_92 ( & V_24 -> V_188 ) < V_24 -> V_187 ) {
if ( F_241 ( V_2 ) ) {
V_342 = F_242 ( V_2 , V_271 ) ;
} else {
V_342 = F_253 ( V_2 ) ;
V_319 = V_2 -> V_80 ;
}
if ( V_342 )
F_247 ( V_342 , V_24 ) ;
}
V_321 = V_14 -> V_77 . V_70 - V_340 ;
if ( ( int ) V_321 < 0 )
V_321 = 0 ;
}
} else if ( F_2 ( V_340 + V_321 >
F_68 ( & V_14 -> V_77 ) -> V_125 ) ) {
T_5 V_352 ;
V_352 = F_68 ( & V_14 -> V_77 ) -> V_125 - V_340 ;
F_254 ( L_4 ,
V_321 , V_352 , V_340 ) ;
V_321 = V_352 ;
if ( F_2 ( ( int ) V_321 < 0 ) ) {
V_321 = 0 ;
V_340 = F_68 ( & V_14 -> V_77 ) -> V_125 ;
}
}
F_46 ( & V_24 -> V_128 . V_78 ) ;
V_35 . V_36 = F_124 ( V_14 , V_2 ,
V_159 , ( V_340 + V_321 ) ) ;
if ( ! V_35 . V_36 )
goto V_353;
if ( V_14 -> V_37 <= V_41 ) {
F_131 ( V_14 , & V_14 -> V_77 ) ;
if ( V_14 -> V_117 . V_337 . V_147 )
V_33 |= V_148 ;
}
V_14 -> V_117 . V_337 . V_338 ++ ;
if ( V_342 ) {
V_33 |= V_354 ;
F_249 ( & V_24 -> V_128 , V_342 ) ;
}
F_44 ( & V_24 -> V_128 . V_78 ) ;
F_255 ( V_2 , 0 , V_35 . V_36 + V_340 , V_321 ) ;
if ( ! ( V_54 = F_59 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
F_101 ( & V_45 ) ;
V_33 |= V_54 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_355 = V_2 -> V_172 ;
V_35 . V_39 -> V_356 = V_321 ;
V_35 . V_39 -> V_357 = V_340 ;
V_35 . V_39 -> V_358 = V_341 ;
V_35 . V_39 -> V_56 = V_45 . V_57 ;
V_35 . V_39 -> V_58 = V_45 . V_59 / V_60 ;
V_113 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_355 = V_2 -> V_172 ;
V_35 . V_42 -> V_356 = V_321 ;
V_35 . V_42 -> V_357 = V_340 ;
V_35 . V_42 -> V_358 = V_341 ;
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
V_35 . V_343 -> V_40 |= V_33 ;
V_35 . V_343 -> V_355 = V_2 -> V_172 ;
V_35 . V_343 -> V_356 = V_321 ;
V_35 . V_343 -> V_357 = V_340 ;
V_35 . V_343 -> V_358 = V_341 ;
V_35 . V_343 -> V_56 = V_45 . V_57 ;
V_35 . V_343 -> V_61 = V_45 . V_59 ;
memset ( V_35 . V_343 -> V_169 , 0 , sizeof( V_35 . V_343 -> V_169 ) ) ;
V_113 = sizeof( * V_35 . V_343 ) ;
break;
default:
F_55 () ;
}
V_318 = V_35 . V_36 + F_251 ( V_113 ) ;
V_318 -> V_334 = F_245 ( V_2 , V_318 -> V_335 ) ;
V_318 -> V_359 = V_360 ;
V_318 -> V_330 = V_4 -> type ;
V_318 -> V_361 = V_2 -> V_279 ;
V_318 -> V_331 = V_2 -> V_269 ;
if ( F_2 ( V_14 -> V_332 ) )
V_318 -> V_333 = V_222 -> V_93 ;
else
V_318 -> V_333 = V_4 -> V_93 ;
F_123 () ;
#if V_135 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_6 * V_136 , * V_137 ;
V_137 = ( T_6 * ) F_98 ( ( unsigned long ) V_35 . V_36 +
V_340 + V_321 ) ;
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
V_325:
if ( V_319 != V_2 -> V_80 && F_241 ( V_2 ) ) {
V_2 -> V_80 = V_319 ;
V_2 -> V_172 = V_320 ;
}
V_10:
F_17 ( V_2 ) ;
return 0 ;
V_353:
V_14 -> V_117 . V_337 . V_147 ++ ;
F_44 ( & V_24 -> V_128 . V_78 ) ;
V_24 -> V_154 ( V_24 ) ;
F_17 ( V_342 ) ;
goto V_325;
}
static void F_256 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_36 ( V_2 -> V_24 ) ;
if ( F_22 ( V_14 -> V_181 . V_68 ) ) {
void * V_362 ;
T_4 V_45 ;
V_362 = F_234 ( V_2 ) -> V_363 ;
F_135 ( & V_14 -> V_181 ) ;
V_45 = F_62 ( V_14 , V_362 , V_2 ) ;
F_52 ( V_14 , V_362 , V_168 | V_45 ) ;
}
F_257 ( V_2 ) ;
}
static bool F_258 ( const struct V_3 * V_4 , int V_172 )
{
if ( F_2 ( V_172 < V_4 -> V_299 ) ) {
F_259 ( L_5 ,
V_364 -> V_365 , V_172 , V_4 -> V_299 ) ;
return true ;
}
return false ;
}
static void F_260 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( V_4 -> type == V_264 ) {
F_211 ( V_2 ) ;
V_2 -> V_279 = F_212 ( V_2 ) -> V_265 ;
}
}
static int F_261 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , int V_366 ,
T_9 V_285 , unsigned char * V_31 , int V_367 )
{
union V_34 V_362 ;
int V_368 , V_369 , V_172 , V_355 , V_370 , V_371 ;
struct V_280 * V_23 = V_14 -> V_24 . V_372 ;
struct V_30 * V_30 ;
void * V_80 ;
int V_91 ;
V_362 . V_36 = V_32 ;
V_2 -> V_279 = V_285 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_308 = V_14 -> V_24 . V_309 ;
V_2 -> V_310 = V_14 -> V_24 . V_311 ;
F_233 ( & V_14 -> V_24 , & F_234 ( V_2 ) -> V_312 ) ;
F_234 ( V_2 ) -> V_363 = V_362 . V_36 ;
switch ( V_14 -> V_37 ) {
case V_41 :
V_355 = V_362 . V_42 -> V_355 ;
break;
default:
V_355 = V_362 . V_39 -> V_355 ;
break;
}
if ( F_2 ( V_355 > V_366 ) ) {
F_152 ( L_6 , V_355 , V_366 ) ;
return - V_297 ;
}
F_229 ( V_2 , V_367 ) ;
F_230 ( V_2 ) ;
if ( F_2 ( V_14 -> V_373 ) ) {
int V_374 , V_375 , V_376 ;
V_374 = V_14 -> V_114 - sizeof( struct V_317 ) ;
V_375 = V_14 -> V_181 . V_70 - V_355 ;
if ( V_23 -> type == V_323 ) {
switch ( V_14 -> V_37 ) {
case V_41 :
V_376 = V_362 . V_42 -> V_358 ;
break;
default:
V_376 = V_362 . V_39 -> V_358 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_41 :
V_376 = V_362 . V_42 -> V_357 ;
break;
default:
V_376 = V_362 . V_39 -> V_357 ;
break;
}
}
if ( F_2 ( ( V_376 < V_374 ) || ( V_375 < V_376 ) ) )
return - V_246 ;
V_80 = V_362 . V_36 + V_376 ;
} else {
V_80 = V_362 . V_36 + V_14 -> V_114 - sizeof( struct V_317 ) ;
}
V_368 = V_355 ;
if ( V_23 -> type == V_323 ) {
V_91 = F_262 ( V_2 , V_4 , F_117 ( V_285 ) , V_31 ,
NULL , V_355 ) ;
if ( F_2 ( V_91 < 0 ) )
return - V_246 ;
} else if ( V_4 -> V_299 ) {
if ( F_258 ( V_4 , V_355 ) )
return - V_246 ;
F_219 ( V_2 , V_4 -> V_299 ) ;
V_91 = F_263 ( V_2 , 0 , V_80 ,
V_4 -> V_299 ) ;
if ( F_2 ( V_91 ) )
return V_91 ;
if ( ! V_2 -> V_279 )
F_260 ( V_4 , V_2 ) ;
V_80 += V_4 -> V_299 ;
V_368 -= V_4 -> V_299 ;
}
V_369 = F_264 ( V_80 ) ;
V_371 = V_138 - V_369 ;
V_172 = ( ( V_368 > V_371 ) ? V_371 : V_368 ) ;
V_2 -> V_377 = V_368 ;
V_2 -> V_172 += V_368 ;
V_2 -> V_189 += V_368 ;
F_265 ( V_368 , & V_14 -> V_24 . V_196 ) ;
while ( F_22 ( V_368 ) ) {
V_370 = F_234 ( V_2 ) -> V_370 ;
if ( F_2 ( V_370 >= V_378 ) ) {
F_152 ( L_7 ,
V_378 ) ;
return - V_247 ;
}
V_30 = F_48 ( V_80 ) ;
V_80 += V_172 ;
F_53 ( V_30 ) ;
F_266 ( V_30 ) ;
F_267 ( V_2 , V_370 , V_30 , V_369 , V_172 ) ;
V_368 -= V_172 ;
V_369 = 0 ;
V_371 = V_138 ;
V_172 = ( ( V_368 > V_371 ) ? V_371 : V_368 ) ;
}
F_235 ( V_2 , 0 ) ;
return V_355 ;
}
static int F_268 ( struct V_13 * V_14 , struct V_281 * V_282 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_9 V_285 ;
int V_91 , V_379 = 0 ;
void * V_362 ;
F_224 ( struct V_317 * , V_283 , V_282 -> V_284 ) ;
bool V_380 = ! ( V_282 -> V_381 & V_382 ) ;
int V_355 , V_366 ;
unsigned char * V_31 ;
int V_383 = 0 ;
int V_33 = V_168 ;
int V_367 , V_302 ;
F_197 ( & V_14 -> V_384 ) ;
if ( F_22 ( V_283 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_285 = V_14 -> V_206 ;
V_31 = NULL ;
} else {
V_91 = - V_246 ;
if ( V_282 -> V_287 < sizeof( struct V_317 ) )
goto V_129;
if ( V_282 -> V_287 < ( V_283 -> V_334
+ F_269 ( struct V_317 ,
V_335 ) ) )
goto V_129;
V_285 = V_283 -> V_361 ;
V_31 = V_283 -> V_335 ;
V_4 = F_270 ( F_78 ( & V_14 -> V_24 ) , V_283 -> V_333 ) ;
}
V_91 = - V_385 ;
if ( F_2 ( V_4 == NULL ) )
goto V_129;
V_91 = - V_293 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_294 ) ) )
goto V_386;
if ( V_14 -> V_24 . V_372 -> type == V_387 )
V_379 = V_4 -> V_299 ;
V_366 = V_14 -> V_181 . V_70
- ( V_14 -> V_114 - sizeof( struct V_317 ) ) ;
if ( V_366 > V_4 -> V_298 + V_379 + V_300 )
V_366 = V_4 -> V_298 + V_379 + V_300 ;
do {
V_362 = F_64 ( V_14 , & V_14 -> V_181 ,
V_388 ) ;
if ( F_2 ( V_362 == NULL ) ) {
if ( V_380 && F_271 () )
F_272 () ;
continue;
}
V_33 = V_388 ;
V_367 = F_227 ( V_4 ) ;
V_302 = V_4 -> V_303 ;
V_2 = F_273 ( & V_14 -> V_24 ,
V_367 + V_302 + sizeof( struct V_317 ) ,
! V_380 , & V_91 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_22 ( V_383 > 0 ) )
V_91 = V_383 ;
goto V_389;
}
V_355 = F_261 ( V_14 , V_2 , V_362 , V_4 , V_366 , V_285 ,
V_31 , V_367 ) ;
if ( F_22 ( V_355 >= 0 ) &&
V_355 > V_4 -> V_298 + V_379 &&
! F_210 ( V_4 , V_2 ) )
V_355 = - V_297 ;
if ( F_2 ( V_355 < 0 ) ) {
if ( V_14 -> V_390 ) {
F_52 ( V_14 , V_362 ,
V_168 ) ;
F_132 ( & V_14 -> V_181 ) ;
F_17 ( V_2 ) ;
continue;
} else {
V_33 = V_391 ;
V_91 = V_355 ;
goto V_389;
}
}
F_32 ( V_4 , V_2 ) ;
V_2 -> V_392 = F_256 ;
F_52 ( V_14 , V_362 , V_393 ) ;
F_133 ( & V_14 -> V_181 ) ;
V_33 = V_388 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_91 > 0 ) ) {
V_91 = F_274 ( V_91 ) ;
if ( V_91 && F_57 ( V_14 , V_362 ) ==
V_168 ) {
V_2 = NULL ;
goto V_389;
}
V_91 = 0 ;
}
F_132 ( & V_14 -> V_181 ) ;
V_383 += V_355 ;
} while ( F_22 ( ( V_362 != NULL ) ||
( V_380 && F_137 ( & V_14 -> V_181 ) ) ) );
V_91 = V_383 ;
goto V_386;
V_389:
F_52 ( V_14 , V_362 , V_33 ) ;
F_17 ( V_2 ) ;
V_386:
F_275 ( V_4 ) ;
V_129:
F_203 ( & V_14 -> V_384 ) ;
return V_91 ;
}
static struct V_1 * F_276 ( struct V_23 * V_24 , T_8 V_394 ,
T_8 V_379 , T_8 V_172 ,
T_8 V_395 , int V_396 ,
int * V_91 )
{
struct V_1 * V_2 ;
if ( V_394 + V_172 < V_138 || ! V_395 )
V_395 = V_172 ;
V_2 = F_277 ( V_24 , V_394 + V_395 , V_172 - V_395 , V_396 ,
V_91 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_229 ( V_2 , V_379 ) ;
F_232 ( V_2 , V_395 ) ;
V_2 -> V_377 = V_172 - V_395 ;
V_2 -> V_172 += V_172 - V_395 ;
return V_2 ;
}
static int F_278 ( struct V_280 * V_23 , struct V_281 * V_282 , T_8 V_172 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_224 ( struct V_317 * , V_283 , V_282 -> V_284 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_9 V_285 ;
unsigned char * V_31 ;
int V_91 , V_379 = 0 ;
struct V_397 V_398 ;
struct V_399 V_400 = { 0 } ;
int V_369 = 0 ;
int V_401 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned short V_402 = 0 ;
int V_367 , V_302 ;
int V_286 = 0 ;
T_10 V_403 ;
if ( F_22 ( V_283 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_285 = V_14 -> V_206 ;
V_31 = NULL ;
} else {
V_91 = - V_246 ;
if ( V_282 -> V_287 < sizeof( struct V_317 ) )
goto V_129;
if ( V_282 -> V_287 < ( V_283 -> V_334 + F_269 ( struct V_317 , V_335 ) ) )
goto V_129;
V_285 = V_283 -> V_361 ;
V_31 = V_283 -> V_335 ;
V_4 = F_270 ( F_78 ( V_24 ) , V_283 -> V_333 ) ;
}
V_91 = - V_385 ;
if ( F_2 ( V_4 == NULL ) )
goto V_292;
V_91 = - V_293 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_294 ) ) )
goto V_292;
V_398 . V_310 = V_24 -> V_311 ;
if ( V_282 -> V_404 ) {
V_91 = F_279 ( V_24 , V_282 , & V_398 ) ;
if ( F_2 ( V_91 ) )
goto V_292;
}
if ( V_23 -> type == V_387 )
V_379 = V_4 -> V_299 ;
if ( V_14 -> V_405 ) {
V_401 = sizeof( V_400 ) ;
V_91 = - V_246 ;
if ( V_172 < V_401 )
goto V_292;
V_172 -= V_401 ;
V_91 = - V_247 ;
V_403 = F_280 ( & V_400 , V_401 , & V_282 -> V_406 ) ;
if ( V_403 != V_401 )
goto V_292;
if ( ( V_400 . V_46 & V_407 ) &&
( F_281 ( F_282 () , V_400 . V_408 ) +
F_281 ( F_282 () , V_400 . V_409 ) + 2 >
F_281 ( F_282 () , V_400 . V_410 ) ) )
V_400 . V_410 = F_283 ( F_282 () ,
F_281 ( F_282 () , V_400 . V_408 ) +
F_281 ( F_282 () , V_400 . V_409 ) + 2 ) ;
V_91 = - V_246 ;
if ( F_281 ( F_282 () , V_400 . V_410 ) > V_172 )
goto V_292;
if ( V_400 . V_402 != V_411 ) {
switch ( V_400 . V_402 & ~ V_412 ) {
case V_413 :
V_402 = V_414 ;
break;
case V_415 :
V_402 = V_416 ;
break;
case V_417 :
V_402 = V_418 ;
break;
default:
goto V_292;
}
if ( V_400 . V_402 & V_412 )
V_402 |= V_419 ;
if ( V_400 . V_420 == 0 )
goto V_292;
}
}
if ( F_2 ( F_151 ( V_24 , V_295 ) ) ) {
if ( ! F_226 ( V_4 ) ) {
V_91 = - V_296 ;
goto V_292;
}
V_286 = 4 ;
}
V_91 = - V_297 ;
if ( ! V_402 && ( V_172 > V_4 -> V_298 + V_379 + V_300 + V_286 ) )
goto V_292;
V_91 = - V_182 ;
V_367 = F_227 ( V_4 ) ;
V_302 = V_4 -> V_303 ;
V_2 = F_276 ( V_24 , V_367 + V_302 , V_367 , V_172 ,
F_281 ( F_282 () , V_400 . V_410 ) ,
V_282 -> V_381 & V_382 , & V_91 ) ;
if ( V_2 == NULL )
goto V_292;
F_284 ( V_2 , V_379 ) ;
V_91 = - V_246 ;
if ( V_23 -> type == V_323 ) {
V_369 = F_262 ( V_2 , V_4 , F_117 ( V_285 ) , V_31 , NULL , V_172 ) ;
if ( F_2 ( V_369 < 0 ) )
goto V_307;
} else {
if ( F_258 ( V_4 , V_172 ) )
goto V_307;
}
V_91 = F_285 ( V_2 , V_369 , & V_282 -> V_406 , V_172 ) ;
if ( V_91 )
goto V_307;
F_233 ( V_24 , & F_234 ( V_2 ) -> V_312 ) ;
if ( ! V_402 && ( V_172 > V_4 -> V_298 + V_379 + V_286 ) &&
! F_210 ( V_4 , V_2 ) ) {
V_91 = - V_297 ;
goto V_307;
}
V_2 -> V_279 = V_285 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_308 = V_24 -> V_309 ;
V_2 -> V_310 = V_398 . V_310 ;
F_32 ( V_4 , V_2 ) ;
if ( V_14 -> V_405 ) {
if ( V_400 . V_46 & V_407 ) {
T_2 V_421 = F_281 ( F_282 () , V_400 . V_408 ) ;
T_2 V_422 = F_281 ( F_282 () , V_400 . V_409 ) ;
if ( ! F_286 ( V_2 , V_421 , V_422 ) ) {
V_91 = - V_246 ;
goto V_307;
}
}
F_234 ( V_2 ) -> V_420 =
F_281 ( F_282 () , V_400 . V_420 ) ;
F_234 ( V_2 ) -> V_402 = V_402 ;
F_234 ( V_2 ) -> V_402 |= V_423 ;
F_234 ( V_2 ) -> V_424 = 0 ;
V_172 += V_401 ;
}
F_235 ( V_2 , V_379 ) ;
if ( F_2 ( V_286 == 4 ) )
V_2 -> V_313 = 1 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( V_91 > 0 && ( V_91 = F_274 ( V_91 ) ) != 0 )
goto V_292;
F_275 ( V_4 ) ;
return V_172 ;
V_307:
F_17 ( V_2 ) ;
V_292:
if ( V_4 )
F_275 ( V_4 ) ;
V_129:
return V_91 ;
}
static int F_287 ( struct V_280 * V_23 , struct V_281 * V_282 , T_8 V_172 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
if ( V_14 -> V_181 . V_68 )
return F_268 ( V_14 , V_282 ) ;
else
return F_278 ( V_23 , V_282 , V_172 ) ;
}
static int F_288 ( struct V_280 * V_23 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 ;
struct V_225 * V_225 ;
union V_98 V_99 ;
if ( ! V_24 )
return 0 ;
V_225 = F_78 ( V_24 ) ;
V_14 = F_36 ( V_24 ) ;
F_197 ( & V_225 -> V_425 . V_426 ) ;
F_289 ( V_24 ) ;
F_203 ( & V_225 -> V_425 . V_426 ) ;
F_290 () ;
F_291 ( V_225 , V_24 -> V_427 , - 1 ) ;
F_292 () ;
F_46 ( & V_14 -> V_29 ) ;
F_47 ( V_24 , false ) ;
F_27 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_275 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
F_293 ( V_24 ) ;
if ( V_14 -> V_77 . V_68 ) {
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
F_294 ( V_24 , & V_99 , 1 , 0 ) ;
}
if ( V_14 -> V_181 . V_68 ) {
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
F_294 ( V_24 , & V_99 , 1 , 1 ) ;
}
F_205 ( V_24 ) ;
F_45 () ;
F_295 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_149 ( & V_24 -> V_128 ) ;
F_142 ( V_14 ) ;
F_296 ( V_24 ) ;
F_297 ( V_24 ) ;
return 0 ;
}
static int F_298 ( struct V_23 * V_24 , const char * V_277 , int V_93 ,
T_9 V_285 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_3 * V_428 ;
T_9 V_429 ;
bool V_430 ;
struct V_3 * V_4 = NULL ;
int V_8 = 0 ;
bool V_431 = false ;
if ( V_14 -> V_26 )
return - V_246 ;
F_299 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
F_20 () ;
if ( V_277 ) {
V_4 = F_225 ( F_78 ( V_24 ) , V_277 ) ;
if ( ! V_4 ) {
V_8 = - V_291 ;
goto V_292;
}
} else if ( V_93 ) {
V_4 = F_300 ( F_78 ( V_24 ) , V_93 ) ;
if ( ! V_4 ) {
V_8 = - V_291 ;
goto V_292;
}
}
if ( V_4 )
F_23 ( V_4 ) ;
V_429 = V_14 -> V_27 . type ;
V_428 = V_14 -> V_27 . V_4 ;
V_430 = V_429 != V_285 || V_428 != V_4 ;
if ( V_430 ) {
if ( V_14 -> V_25 ) {
F_24 () ;
F_40 ( V_24 , true ) ;
F_20 () ;
V_428 = V_14 -> V_27 . V_4 ;
if ( V_4 )
V_431 = ! F_300 ( F_78 ( V_24 ) ,
V_4 -> V_93 ) ;
}
V_14 -> V_206 = V_285 ;
V_14 -> V_27 . type = V_285 ;
if ( F_2 ( V_431 ) ) {
F_275 ( V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
V_14 -> V_93 = - 1 ;
F_27 ( V_14 ) ;
} else {
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_93 = V_4 ? V_4 -> V_93 : 0 ;
F_25 ( V_14 , V_4 ) ;
}
}
if ( V_428 )
F_275 ( V_428 ) ;
if ( V_285 == 0 || ! V_430 )
goto V_292;
if ( ! V_431 && ( ! V_4 || ( V_4 -> V_46 & V_294 ) ) ) {
F_35 ( V_24 ) ;
} else {
V_24 -> V_432 = V_293 ;
if ( ! F_151 ( V_24 , V_197 ) )
V_24 -> V_433 ( V_24 ) ;
}
V_292:
F_24 () ;
F_44 ( & V_14 -> V_29 ) ;
F_301 ( V_24 ) ;
return V_8 ;
}
static int F_302 ( struct V_280 * V_23 , struct V_288 * V_434 ,
int V_435 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_277 [ 15 ] ;
if ( V_435 != sizeof( struct V_288 ) )
return - V_246 ;
F_221 ( V_277 , V_434 -> V_436 , sizeof( V_277 ) ) ;
return F_298 ( V_24 , V_277 , 0 , F_36 ( V_24 ) -> V_206 ) ;
}
static int F_303 ( struct V_280 * V_23 , struct V_288 * V_434 , int V_435 )
{
struct V_317 * V_318 = (struct V_317 * ) V_434 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_435 < sizeof( struct V_317 ) )
return - V_246 ;
if ( V_318 -> V_359 != V_360 )
return - V_246 ;
return F_298 ( V_24 , NULL , V_318 -> V_333 ,
V_318 -> V_361 ? : F_36 ( V_24 ) -> V_206 ) ;
}
static int F_304 ( struct V_225 * V_225 , struct V_280 * V_23 , int V_279 ,
int V_437 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_9 V_285 = ( V_438 T_9 ) V_279 ;
int V_91 ;
if ( ! F_305 ( V_225 -> V_439 , V_440 ) )
return - V_245 ;
if ( V_23 -> type != V_323 && V_23 -> type != V_387 &&
V_23 -> type != V_441 )
return - V_442 ;
V_23 -> V_443 = V_444 ;
V_91 = - V_182 ;
V_24 = F_306 ( V_225 , V_239 , V_254 , & V_445 , V_437 ) ;
if ( V_24 == NULL )
goto V_129;
V_23 -> V_19 = & V_446 ;
if ( V_23 -> type == V_441 )
V_23 -> V_19 = & V_447 ;
F_307 ( V_23 , V_24 ) ;
V_14 = F_36 ( V_24 ) ;
V_24 -> V_238 = V_239 ;
V_14 -> V_206 = V_285 ;
V_14 -> V_16 = F_236 ;
V_91 = F_140 ( V_14 ) ;
if ( V_91 )
goto V_448;
F_27 ( V_14 ) ;
V_24 -> V_449 = F_148 ;
F_308 ( V_24 ) ;
F_201 ( & V_14 -> V_29 ) ;
F_309 ( & V_14 -> V_384 ) ;
V_14 -> V_202 = NULL ;
V_14 -> V_27 . F_72 = F_238 ;
if ( V_23 -> type == V_441 )
V_14 -> V_27 . F_72 = F_214 ;
V_14 -> V_27 . V_223 = V_24 ;
if ( V_285 ) {
V_14 -> V_27 . type = V_285 ;
F_35 ( V_24 ) ;
}
F_197 ( & V_225 -> V_425 . V_426 ) ;
F_310 ( V_24 , & V_225 -> V_425 . V_450 ) ;
F_203 ( & V_225 -> V_425 . V_426 ) ;
F_290 () ;
F_291 ( V_225 , & V_445 , 1 ) ;
F_292 () ;
return 0 ;
V_448:
F_311 ( V_24 ) ;
V_129:
return V_91 ;
}
static int F_312 ( struct V_280 * V_23 , struct V_281 * V_282 , T_8 V_172 ,
int V_46 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_451 , V_91 ;
int V_401 = 0 ;
unsigned int V_336 = 0 ;
V_91 = - V_246 ;
if ( V_46 & ~ ( V_452 | V_382 | V_453 | V_454 | V_455 ) )
goto V_129;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_46 & V_455 ) {
V_91 = F_313 ( V_24 , V_282 , V_172 ,
V_456 , V_457 ) ;
goto V_129;
}
V_2 = F_314 ( V_24 , V_46 , V_46 & V_382 , & V_91 ) ;
if ( V_2 == NULL )
goto V_129;
if ( F_36 ( V_24 ) -> V_194 )
F_147 ( F_36 ( V_24 ) , NULL ) ;
if ( F_36 ( V_24 ) -> V_405 ) {
struct V_399 V_400 = { 0 } ;
V_91 = - V_246 ;
V_401 = sizeof( V_400 ) ;
if ( V_172 < V_401 )
goto V_307;
V_172 -= V_401 ;
if ( F_315 ( V_2 ) ) {
struct V_458 * V_459 = F_234 ( V_2 ) ;
V_400 . V_410 =
F_283 ( F_282 () , F_316 ( V_2 ) ) ;
V_400 . V_420 =
F_283 ( F_282 () , V_459 -> V_420 ) ;
if ( V_459 -> V_402 & V_414 )
V_400 . V_402 = V_413 ;
else if ( V_459 -> V_402 & V_416 )
V_400 . V_402 = V_415 ;
else if ( V_459 -> V_402 & V_418 )
V_400 . V_402 = V_417 ;
else if ( V_459 -> V_402 & V_460 )
goto V_307;
else
F_55 () ;
if ( V_459 -> V_402 & V_419 )
V_400 . V_402 |= V_412 ;
} else
V_400 . V_402 = V_411 ;
if ( V_2 -> V_344 == V_345 ) {
V_400 . V_46 = V_407 ;
V_400 . V_408 = F_283 ( F_282 () ,
F_317 ( V_2 ) ) ;
V_400 . V_409 = F_283 ( F_282 () ,
V_2 -> V_409 ) ;
} else if ( V_2 -> V_344 == V_461 ) {
V_400 . V_46 = V_462 ;
}
V_91 = F_318 ( V_282 , ( void * ) & V_400 , V_401 ) ;
if ( V_91 < 0 )
goto V_307;
}
V_451 = V_2 -> V_172 ;
if ( V_451 > V_172 ) {
V_451 = V_172 ;
V_282 -> V_381 |= V_453 ;
}
V_91 = F_319 ( V_2 , 0 , V_282 , V_451 ) ;
if ( V_91 )
goto V_307;
if ( V_23 -> type != V_441 ) {
struct V_317 * V_318 = & F_218 ( V_2 ) -> V_273 . V_329 ;
V_336 = F_218 ( V_2 ) -> V_273 . V_336 ;
V_318 -> V_359 = V_360 ;
V_318 -> V_361 = V_2 -> V_279 ;
}
F_320 ( V_282 , V_24 , V_2 ) ;
if ( V_282 -> V_284 ) {
if ( V_23 -> type == V_441 ) {
F_321 ( sizeof( struct V_267 ) ) ;
V_282 -> V_287 = sizeof( struct V_267 ) ;
} else {
struct V_317 * V_318 = & F_218 ( V_2 ) -> V_273 . V_329 ;
V_282 -> V_287 = V_318 -> V_334 +
F_269 ( struct V_317 , V_335 ) ;
}
memcpy ( V_282 -> V_284 , & F_218 ( V_2 ) -> V_273 ,
V_282 -> V_287 ) ;
}
if ( F_36 ( V_24 ) -> V_463 ) {
struct V_464 V_465 ;
V_465 . V_40 = V_141 ;
if ( V_2 -> V_344 == V_345 )
V_465 . V_40 |= V_346 ;
else if ( V_2 -> V_269 != V_324 &&
( V_2 -> V_344 == V_347 ||
F_252 ( V_2 ) ) )
V_465 . V_40 |= V_348 ;
V_465 . V_355 = V_336 ;
V_465 . V_356 = V_2 -> V_172 ;
V_465 . V_357 = 0 ;
V_465 . V_358 = F_240 ( V_2 ) ;
if ( F_115 ( V_2 ) ) {
V_465 . V_163 = F_116 ( V_2 ) ;
V_465 . V_164 = F_117 ( V_2 -> V_165 ) ;
V_465 . V_40 |= V_166 | V_167 ;
} else {
V_465 . V_163 = 0 ;
V_465 . V_164 = 0 ;
}
F_322 ( V_282 , V_456 , V_466 , sizeof( V_465 ) , & V_465 ) ;
}
V_91 = V_401 + ( ( V_46 & V_453 ) ? V_2 -> V_172 : V_451 ) ;
V_307:
F_323 ( V_24 , V_2 ) ;
V_129:
return V_91 ;
}
static int F_324 ( struct V_280 * V_23 , struct V_288 * V_434 ,
int * V_467 , int V_468 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_468 )
return - V_469 ;
V_434 -> V_470 = V_360 ;
memset ( V_434 -> V_436 , 0 , sizeof( V_434 -> V_436 ) ) ;
F_20 () ;
V_4 = F_300 ( F_78 ( V_24 ) , F_36 ( V_24 ) -> V_93 ) ;
if ( V_4 )
F_221 ( V_434 -> V_436 , V_4 -> V_277 , sizeof( V_434 -> V_436 ) ) ;
F_24 () ;
* V_467 = sizeof( * V_434 ) ;
return 0 ;
}
static int F_325 ( struct V_280 * V_23 , struct V_288 * V_434 ,
int * V_467 , int V_468 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
F_224 ( struct V_317 * , V_318 , V_434 ) ;
if ( V_468 )
return - V_469 ;
V_318 -> V_359 = V_360 ;
V_318 -> V_333 = V_14 -> V_93 ;
V_318 -> V_361 = V_14 -> V_206 ;
V_318 -> V_331 = 0 ;
F_20 () ;
V_4 = F_300 ( F_78 ( V_24 ) , V_14 -> V_93 ) ;
if ( V_4 ) {
V_318 -> V_330 = V_4 -> type ;
V_318 -> V_334 = V_4 -> V_435 ;
memcpy ( V_318 -> V_335 , V_4 -> V_471 , V_4 -> V_435 ) ;
} else {
V_318 -> V_330 = 0 ;
V_318 -> V_334 = 0 ;
}
F_24 () ;
* V_467 = F_269 ( struct V_317 , V_335 ) + V_318 -> V_334 ;
return 0 ;
}
static int F_326 ( struct V_3 * V_4 , struct V_472 * V_199 ,
int V_473 )
{
switch ( V_199 -> type ) {
case V_474 :
if ( V_199 -> V_475 != V_4 -> V_435 )
return - V_246 ;
if ( V_473 > 0 )
return F_327 ( V_4 , V_199 -> V_31 ) ;
else
return F_328 ( V_4 , V_199 -> V_31 ) ;
break;
case V_476 :
return F_329 ( V_4 , V_473 ) ;
case V_477 :
return F_330 ( V_4 , V_473 ) ;
case V_478 :
if ( V_199 -> V_475 != V_4 -> V_435 )
return - V_246 ;
if ( V_473 > 0 )
return F_331 ( V_4 , V_199 -> V_31 ) ;
else
return F_332 ( V_4 , V_199 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_333 ( struct V_3 * V_4 ,
struct V_472 * * V_479 )
{
struct V_472 * V_480 ;
while ( ( V_480 = * V_479 ) != NULL ) {
if ( V_480 -> V_93 == V_4 -> V_93 ) {
F_326 ( V_4 , V_480 , - 1 ) ;
* V_479 = V_480 -> V_481 ;
F_204 ( V_480 ) ;
} else
V_479 = & V_480 -> V_481 ;
}
}
static int F_334 ( struct V_23 * V_24 , struct V_482 * V_483 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_472 * V_480 , * V_199 ;
struct V_3 * V_4 ;
int V_91 ;
F_76 () ;
V_91 = - V_291 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_483 -> V_484 ) ;
if ( ! V_4 )
goto V_485;
V_91 = - V_246 ;
if ( V_483 -> V_486 > V_4 -> V_435 )
goto V_485;
V_91 = - V_182 ;
V_199 = F_335 ( sizeof( * V_199 ) , V_254 ) ;
if ( V_199 == NULL )
goto V_485;
V_91 = 0 ;
for ( V_480 = V_14 -> V_487 ; V_480 ; V_480 = V_480 -> V_481 ) {
if ( V_480 -> V_93 == V_483 -> V_484 &&
V_480 -> type == V_483 -> V_488 &&
V_480 -> V_475 == V_483 -> V_486 &&
memcmp ( V_480 -> V_31 , V_483 -> V_489 , V_480 -> V_475 ) == 0 ) {
V_480 -> V_200 ++ ;
F_204 ( V_199 ) ;
goto V_485;
}
}
V_199 -> type = V_483 -> V_488 ;
V_199 -> V_93 = V_483 -> V_484 ;
V_199 -> V_475 = V_483 -> V_486 ;
memcpy ( V_199 -> V_31 , V_483 -> V_489 , V_199 -> V_475 ) ;
V_199 -> V_200 = 1 ;
V_199 -> V_481 = V_14 -> V_487 ;
V_14 -> V_487 = V_199 ;
V_91 = F_326 ( V_4 , V_199 , 1 ) ;
if ( V_91 ) {
V_14 -> V_487 = V_199 -> V_481 ;
F_204 ( V_199 ) ;
}
V_485:
F_79 () ;
return V_91 ;
}
static int F_336 ( struct V_23 * V_24 , struct V_482 * V_483 )
{
struct V_472 * V_480 , * * V_479 ;
F_76 () ;
for ( V_479 = & F_36 ( V_24 ) -> V_487 ; ( V_480 = * V_479 ) != NULL ; V_479 = & V_480 -> V_481 ) {
if ( V_480 -> V_93 == V_483 -> V_484 &&
V_480 -> type == V_483 -> V_488 &&
V_480 -> V_475 == V_483 -> V_486 &&
memcmp ( V_480 -> V_31 , V_483 -> V_489 , V_480 -> V_475 ) == 0 ) {
if ( -- V_480 -> V_200 == 0 ) {
struct V_3 * V_4 ;
* V_479 = V_480 -> V_481 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_480 -> V_93 ) ;
if ( V_4 )
F_326 ( V_4 , V_480 , - 1 ) ;
F_204 ( V_480 ) ;
}
break;
}
}
F_79 () ;
return 0 ;
}
static void F_293 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_472 * V_480 ;
if ( ! V_14 -> V_487 )
return;
F_76 () ;
while ( ( V_480 = V_14 -> V_487 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_487 = V_480 -> V_481 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_480 -> V_93 ) ;
if ( V_4 != NULL )
F_326 ( V_4 , V_480 , - 1 ) ;
F_204 ( V_480 ) ;
}
F_79 () ;
}
static int
F_337 ( struct V_280 * V_23 , int V_490 , int V_491 , char T_7 * V_492 , unsigned int V_493 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_8 ;
if ( V_490 != V_456 )
return - V_494 ;
switch ( V_491 ) {
case V_495 :
case V_496 :
{
struct V_482 V_483 ;
int V_172 = V_493 ;
memset ( & V_483 , 0 , sizeof( V_483 ) ) ;
if ( V_172 < sizeof( struct V_497 ) )
return - V_246 ;
if ( V_172 > sizeof( V_483 ) )
V_172 = sizeof( V_483 ) ;
if ( F_185 ( & V_483 , V_492 , V_172 ) )
return - V_247 ;
if ( V_172 < ( V_483 . V_486 + F_269 ( struct V_497 , V_489 ) ) )
return - V_246 ;
if ( V_491 == V_495 )
V_8 = F_334 ( V_24 , & V_483 ) ;
else
V_8 = F_336 ( V_24 , & V_483 ) ;
return V_8 ;
}
case V_498 :
case V_499 :
{
union V_98 V_99 ;
int V_172 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_172 = sizeof( V_99 . V_500 ) ;
break;
case V_43 :
default:
V_172 = sizeof( V_99 . V_101 ) ;
break;
}
if ( V_493 < V_172 )
return - V_246 ;
if ( F_36 ( V_24 ) -> V_405 )
return - V_246 ;
if ( F_185 ( & V_99 . V_500 , V_492 , V_172 ) )
return - V_247 ;
return F_294 ( V_24 , & V_99 , 0 ,
V_491 == V_499 ) ;
}
case V_501 :
{
int V_207 ;
if ( V_493 != sizeof( V_207 ) )
return - V_246 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
F_36 ( V_24 ) -> V_351 = V_207 ;
return 0 ;
}
case V_502 :
{
int V_207 ;
if ( V_493 != sizeof( V_207 ) )
return - V_246 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_503 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
switch ( V_207 ) {
case V_38 :
case V_41 :
case V_43 :
V_14 -> V_37 = V_207 ;
return 0 ;
default:
return - V_246 ;
}
}
case V_504 :
{
unsigned int V_207 ;
if ( V_493 != sizeof( V_207 ) )
return - V_246 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_503 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
V_14 -> V_349 = V_207 ;
return 0 ;
}
case V_505 :
{
unsigned int V_207 ;
if ( V_493 != sizeof( V_207 ) )
return - V_246 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_503 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
V_14 -> V_390 = ! ! V_207 ;
return 0 ;
}
case V_466 :
{
int V_207 ;
if ( V_493 < sizeof( V_207 ) )
return - V_246 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
V_14 -> V_463 = ! ! V_207 ;
return 0 ;
}
case V_506 :
{
int V_207 ;
if ( V_493 < sizeof( V_207 ) )
return - V_246 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
V_14 -> V_332 = ! ! V_207 ;
return 0 ;
}
case V_507 :
{
int V_207 ;
if ( V_23 -> type != V_387 )
return - V_246 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_503 ;
if ( V_493 < sizeof( V_207 ) )
return - V_246 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
V_14 -> V_405 = ! ! V_207 ;
return 0 ;
}
case V_508 :
{
int V_207 ;
if ( V_493 != sizeof( V_207 ) )
return - V_246 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
V_14 -> V_55 = V_207 ;
return 0 ;
}
case V_509 :
{
int V_207 ;
if ( V_493 != sizeof( V_207 ) )
return - V_246 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
return F_194 ( V_24 , V_207 & 0xffff , V_207 >> 16 ) ;
}
case V_510 :
{
if ( ! V_14 -> V_26 )
return - V_246 ;
return F_192 ( V_14 , V_492 , V_493 ) ;
}
case V_511 :
{
unsigned int V_207 ;
if ( V_493 != sizeof( V_207 ) )
return - V_246 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_181 . V_68 )
return - V_503 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
V_14 -> V_373 = ! ! V_207 ;
return 0 ;
}
case V_512 :
{
int V_207 ;
if ( V_493 != sizeof( V_207 ) )
return - V_246 ;
if ( F_185 ( & V_207 , V_492 , sizeof( V_207 ) ) )
return - V_247 ;
V_14 -> V_16 = V_207 ? F_1 : F_236 ;
return 0 ;
}
default:
return - V_494 ;
}
}
static int F_338 ( struct V_280 * V_23 , int V_490 , int V_491 ,
char T_7 * V_492 , int T_7 * V_493 )
{
int V_172 ;
int V_207 , V_513 = sizeof( V_207 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
void * V_80 = & V_207 ;
union V_514 V_515 ;
struct V_516 V_517 ;
if ( V_490 != V_456 )
return - V_494 ;
if ( F_339 ( V_172 , V_493 ) )
return - V_247 ;
if ( V_172 < 0 )
return - V_246 ;
switch ( V_491 ) {
case V_518 :
F_69 ( & V_24 -> V_128 . V_78 ) ;
memcpy ( & V_515 , & V_14 -> V_117 , sizeof( V_515 ) ) ;
memset ( & V_14 -> V_117 , 0 , sizeof( V_14 -> V_117 ) ) ;
F_70 ( & V_24 -> V_128 . V_78 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_513 = sizeof( struct V_519 ) ;
V_515 . V_118 . V_338 += V_515 . V_118 . V_147 ;
V_80 = & V_515 . V_118 ;
} else {
V_513 = sizeof( struct V_520 ) ;
V_515 . V_337 . V_338 += V_515 . V_337 . V_147 ;
V_80 = & V_515 . V_337 ;
}
break;
case V_466 :
V_207 = V_14 -> V_463 ;
break;
case V_506 :
V_207 = V_14 -> V_332 ;
break;
case V_507 :
V_207 = V_14 -> V_405 ;
break;
case V_502 :
V_207 = V_14 -> V_37 ;
break;
case V_521 :
if ( V_172 > sizeof( int ) )
V_172 = sizeof( int ) ;
if ( F_185 ( & V_207 , V_492 , V_172 ) )
return - V_247 ;
switch ( V_207 ) {
case V_38 :
V_207 = sizeof( struct V_522 ) ;
break;
case V_41 :
V_207 = sizeof( struct V_523 ) ;
break;
case V_43 :
V_207 = sizeof( struct V_142 ) ;
break;
default:
return - V_246 ;
}
break;
case V_504 :
V_207 = V_14 -> V_349 ;
break;
case V_505 :
V_207 = V_14 -> V_390 ;
break;
case V_508 :
V_207 = V_14 -> V_55 ;
break;
case V_509 :
V_207 = ( V_14 -> V_26 ?
( ( T_5 ) V_14 -> V_26 -> V_250 |
( ( T_5 ) V_14 -> V_26 -> type << 16 ) |
( ( T_5 ) V_14 -> V_26 -> V_46 << 24 ) ) :
0 ) ;
break;
case V_524 :
if ( ! V_14 -> V_202 )
return - V_246 ;
V_517 . V_525 = F_340 ( & V_14 -> V_202 -> V_206 ) ;
V_517 . V_526 = F_340 ( & V_14 -> V_202 -> V_215 ) ;
V_517 . V_527 = F_340 ( & V_14 -> V_202 -> V_216 ) ;
V_80 = & V_517 ;
V_513 = sizeof( V_517 ) ;
break;
case V_511 :
V_207 = V_14 -> V_373 ;
break;
case V_512 :
V_207 = F_29 ( V_14 ) ;
break;
default:
return - V_494 ;
}
if ( V_172 > V_513 )
V_172 = V_513 ;
if ( F_341 ( V_172 , V_493 ) )
return - V_247 ;
if ( F_342 ( V_492 , V_80 , V_172 ) )
return - V_247 ;
return 0 ;
}
static int F_343 ( struct V_528 * V_529 ,
unsigned long V_282 , void * V_530 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_344 ( V_530 ) ;
struct V_225 * V_225 = F_174 ( V_4 ) ;
F_20 () ;
F_345 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_36 ( V_24 ) ;
switch ( V_282 ) {
case V_531 :
if ( V_14 -> V_487 )
F_333 ( V_4 , & V_14 -> V_487 ) ;
case V_532 :
if ( V_4 -> V_93 == V_14 -> V_93 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_40 ( V_24 , false ) ;
V_24 -> V_432 = V_293 ;
if ( ! F_151 ( V_24 , V_197 ) )
V_24 -> V_433 ( V_24 ) ;
}
if ( V_282 == V_531 ) {
F_27 ( V_14 ) ;
V_14 -> V_93 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_275 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
}
break;
case V_533 :
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
return V_534 ;
}
static int F_346 ( struct V_280 * V_23 , unsigned int V_535 ,
unsigned long V_536 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_535 ) {
case V_537 :
{
int V_538 = F_347 ( V_24 ) ;
return F_341 ( V_538 , ( int T_7 * ) V_536 ) ;
}
case V_539 :
{
struct V_1 * V_2 ;
int V_538 = 0 ;
F_69 ( & V_24 -> V_128 . V_78 ) ;
V_2 = F_348 ( & V_24 -> V_128 ) ;
if ( V_2 )
V_538 = V_2 -> V_172 ;
F_70 ( & V_24 -> V_128 . V_78 ) ;
return F_341 ( V_538 , ( int T_7 * ) V_536 ) ;
}
case V_540 :
return F_349 ( V_24 , (struct V_541 T_7 * ) V_536 ) ;
case V_542 :
return F_350 ( V_24 , (struct V_44 T_7 * ) V_536 ) ;
#ifdef F_351
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
case V_554 :
case V_555 :
case V_556 :
return V_557 . V_558 ( V_23 , V_535 , V_536 ) ;
#endif
default:
return - V_559 ;
}
return 0 ;
}
static unsigned int F_352 ( struct V_560 * V_560 , struct V_280 * V_23 ,
T_11 * V_561 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned int V_562 = F_353 ( V_560 , V_23 , V_561 ) ;
F_69 ( & V_24 -> V_128 . V_78 ) ;
if ( V_14 -> V_77 . V_68 ) {
if ( ! F_129 ( V_14 , & V_14 -> V_77 ,
V_159 ) )
V_562 |= V_563 | V_564 ;
}
if ( V_14 -> V_194 && F_146 ( V_14 , NULL ) == V_191 )
V_14 -> V_194 = 0 ;
F_70 ( & V_24 -> V_128 . V_78 ) ;
F_69 ( & V_24 -> V_565 . V_78 ) ;
if ( V_14 -> V_181 . V_68 ) {
if ( F_64 ( V_14 , & V_14 -> V_181 , V_168 ) )
V_562 |= V_566 | V_567 ;
}
F_70 ( & V_24 -> V_565 . V_78 ) ;
return V_562 ;
}
static void F_354 ( struct V_568 * V_569 )
{
struct V_560 * V_560 = V_569 -> V_570 ;
struct V_280 * V_23 = V_560 -> V_571 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_121 ( & F_36 ( V_24 ) -> V_572 ) ;
}
static void F_355 ( struct V_568 * V_569 )
{
struct V_560 * V_560 = V_569 -> V_570 ;
struct V_280 * V_23 = V_560 -> V_571 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_110 ( & F_36 ( V_24 ) -> V_572 ) ;
}
static void F_356 ( struct V_103 * V_68 , unsigned int V_573 ,
unsigned int V_172 )
{
int V_199 ;
for ( V_199 = 0 ; V_199 < V_172 ; V_199 ++ ) {
if ( F_22 ( V_68 [ V_199 ] . V_69 ) ) {
if ( F_49 ( V_68 [ V_199 ] . V_69 ) )
F_357 ( V_68 [ V_199 ] . V_69 ) ;
else
F_358 ( ( unsigned long ) V_68 [ V_199 ] . V_69 ,
V_573 ) ;
V_68 [ V_199 ] . V_69 = NULL ;
}
}
F_204 ( V_68 ) ;
}
static char * F_359 ( unsigned long V_573 )
{
char * V_69 ;
T_12 V_574 = V_254 | V_575 |
V_576 | V_577 | V_578 ;
V_69 = ( char * ) F_360 ( V_574 , V_573 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_361 ( ( 1 << V_573 ) * V_138 ) ;
if ( V_69 )
return V_69 ;
V_574 &= ~ V_578 ;
V_69 = ( char * ) F_360 ( V_574 , V_573 ) ;
if ( V_69 )
return V_69 ;
return NULL ;
}
static struct V_103 * F_362 ( struct V_579 * V_500 , int V_573 )
{
unsigned int V_580 = V_500 -> V_112 ;
struct V_103 * V_68 ;
int V_199 ;
V_68 = F_363 ( V_580 , sizeof( struct V_103 ) , V_254 ) ;
if ( F_2 ( ! V_68 ) )
goto V_129;
for ( V_199 = 0 ; V_199 < V_580 ; V_199 ++ ) {
V_68 [ V_199 ] . V_69 = F_359 ( V_573 ) ;
if ( F_2 ( ! V_68 [ V_199 ] . V_69 ) )
goto V_581;
}
V_129:
return V_68 ;
V_581:
F_356 ( V_68 , V_573 , V_580 ) ;
V_68 = NULL ;
goto V_129;
}
static int F_294 ( struct V_23 * V_24 , union V_98 * V_99 ,
int V_582 , int V_181 )
{
struct V_103 * V_68 = NULL ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_583 , V_573 = 0 ;
struct V_62 * V_63 ;
struct V_75 * V_76 ;
T_9 V_206 ;
int V_91 = - V_246 ;
struct V_579 * V_500 = & V_99 -> V_500 ;
if ( ! V_582 && V_181 && ( V_14 -> V_37 > V_41 ) ) {
F_54 ( 1 , L_8 ) ;
goto V_129;
}
V_63 = V_181 ? & V_14 -> V_181 : & V_14 -> V_77 ;
V_76 = V_181 ? & V_24 -> V_565 : & V_24 -> V_128 ;
V_91 = - V_503 ;
if ( ! V_582 ) {
if ( F_92 ( & V_14 -> V_572 ) )
goto V_129;
if ( F_137 ( V_63 ) )
goto V_129;
}
if ( V_500 -> V_112 ) {
V_91 = - V_503 ;
if ( F_2 ( V_63 -> V_68 ) )
goto V_129;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_114 = V_584 ;
break;
case V_41 :
V_14 -> V_114 = V_585 ;
break;
case V_43 :
V_14 -> V_114 = V_586 ;
break;
}
V_91 = - V_246 ;
if ( F_2 ( ( int ) V_500 -> V_110 <= 0 ) )
goto V_129;
if ( F_2 ( ! F_364 ( V_500 -> V_110 ) ) )
goto V_129;
if ( V_14 -> V_37 >= V_43 &&
( int ) ( V_500 -> V_110 -
F_85 ( V_99 -> V_101 . V_124 ) ) <= 0 )
goto V_129;
if ( F_2 ( V_500 -> V_587 < V_14 -> V_114 +
V_14 -> V_349 ) )
goto V_129;
if ( F_2 ( V_500 -> V_587 & ( V_588 - 1 ) ) )
goto V_129;
V_63 -> V_67 = V_500 -> V_110 / V_500 -> V_587 ;
if ( F_2 ( V_63 -> V_67 == 0 ) )
goto V_129;
if ( F_2 ( ( V_63 -> V_67 * V_500 -> V_112 ) !=
V_500 -> V_589 ) )
goto V_129;
V_91 = - V_255 ;
V_573 = F_365 ( V_500 -> V_110 ) ;
V_68 = F_362 ( V_500 , V_573 ) ;
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
V_91 = - V_246 ;
if ( F_2 ( V_500 -> V_589 ) )
goto V_129;
}
F_299 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_583 = V_14 -> V_25 ;
V_206 = V_14 -> V_206 ;
if ( V_583 ) {
V_14 -> V_206 = 0 ;
F_40 ( V_24 , false ) ;
}
F_44 ( & V_14 -> V_29 ) ;
F_45 () ;
V_91 = - V_503 ;
F_197 ( & V_14 -> V_384 ) ;
if ( V_582 || F_92 ( & V_14 -> V_572 ) == 0 ) {
V_91 = 0 ;
F_69 ( & V_76 -> V_78 ) ;
F_366 ( V_63 -> V_68 , V_68 ) ;
V_63 -> V_176 = ( V_500 -> V_589 - 1 ) ;
V_63 -> V_71 = 0 ;
V_63 -> V_70 = V_500 -> V_587 ;
F_70 ( & V_76 -> V_78 ) ;
F_366 ( V_63 -> V_590 , V_573 ) ;
F_366 ( V_63 -> V_591 , V_500 -> V_112 ) ;
V_63 -> V_592 = V_500 -> V_110 / V_138 ;
V_14 -> V_27 . F_72 = ( V_14 -> V_77 . V_68 ) ?
V_185 : F_238 ;
F_149 ( V_76 ) ;
if ( F_92 ( & V_14 -> V_572 ) )
F_152 ( L_9 ,
F_92 ( & V_14 -> V_572 ) ) ;
}
F_203 ( & V_14 -> V_384 ) ;
F_46 ( & V_14 -> V_29 ) ;
if ( V_583 ) {
V_14 -> V_206 = V_206 ;
F_35 ( V_24 ) ;
}
F_44 ( & V_14 -> V_29 ) ;
if ( V_582 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_181 )
F_67 ( V_14 , V_76 ) ;
}
F_301 ( V_24 ) ;
if ( V_68 )
F_356 ( V_68 , V_573 , V_500 -> V_112 ) ;
V_129:
return V_91 ;
}
static int F_367 ( struct V_560 * V_560 , struct V_280 * V_23 ,
struct V_568 * V_569 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned long V_593 , V_594 ;
struct V_62 * V_63 ;
unsigned long V_136 ;
int V_91 = - V_246 ;
int V_199 ;
if ( V_569 -> V_595 )
return - V_246 ;
F_197 ( & V_14 -> V_384 ) ;
V_594 = 0 ;
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_181 ; V_63 ++ ) {
if ( V_63 -> V_68 ) {
V_594 += V_63 -> V_591
* V_63 -> V_592
* V_138 ;
}
}
if ( V_594 == 0 )
goto V_129;
V_593 = V_569 -> V_596 - V_569 -> V_597 ;
if ( V_593 != V_594 )
goto V_129;
V_136 = V_569 -> V_597 ;
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_181 ; V_63 ++ ) {
if ( V_63 -> V_68 == NULL )
continue;
for ( V_199 = 0 ; V_199 < V_63 -> V_591 ; V_199 ++ ) {
struct V_30 * V_30 ;
void * V_598 = V_63 -> V_68 [ V_199 ] . V_69 ;
int V_599 ;
for ( V_599 = 0 ; V_599 < V_63 -> V_592 ; V_599 ++ ) {
V_30 = F_48 ( V_598 ) ;
V_91 = F_368 ( V_569 , V_136 , V_30 ) ;
if ( F_2 ( V_91 ) )
goto V_129;
V_136 += V_138 ;
V_598 += V_138 ;
}
}
}
F_121 ( & V_14 -> V_572 ) ;
V_569 -> V_600 = & V_601 ;
V_91 = 0 ;
V_129:
F_203 ( & V_14 -> V_384 ) ;
return V_91 ;
}
static void * F_369 ( struct V_602 * V_603 , T_13 * V_604 )
__acquires( T_14 )
{
struct V_225 * V_225 = F_370 ( V_603 ) ;
F_20 () ;
return F_371 ( & V_225 -> V_425 . V_450 , * V_604 ) ;
}
static void * F_372 ( struct V_602 * V_603 , void * V_605 , T_13 * V_604 )
{
struct V_225 * V_225 = F_370 ( V_603 ) ;
return F_373 ( V_605 , & V_225 -> V_425 . V_450 , V_604 ) ;
}
static void F_374 ( struct V_602 * V_603 , void * V_605 )
__releases( T_14 )
{
F_24 () ;
}
static int F_375 ( struct V_602 * V_603 , void * V_605 )
{
if ( V_605 == V_606 )
F_376 ( V_603 , L_10 ) ;
else {
struct V_23 * V_421 = F_377 ( V_605 ) ;
const struct V_13 * V_14 = F_36 ( V_421 ) ;
F_378 ( V_603 ,
L_11 ,
V_421 ,
F_92 ( & V_421 -> V_607 ) ,
V_421 -> V_322 ,
F_117 ( V_14 -> V_206 ) ,
V_14 -> V_93 ,
V_14 -> V_25 ,
F_92 ( & V_421 -> V_188 ) ,
F_379 ( F_380 ( V_603 ) , F_381 ( V_421 ) ) ,
F_382 ( V_421 ) ) ;
}
return 0 ;
}
static int F_383 ( struct V_608 * V_608 , struct V_560 * V_560 )
{
return F_384 ( V_608 , V_560 , & V_609 ,
sizeof( struct V_610 ) ) ;
}
static int T_15 F_385 ( struct V_225 * V_225 )
{
F_309 ( & V_225 -> V_425 . V_426 ) ;
F_386 ( & V_225 -> V_425 . V_450 ) ;
if ( ! F_387 ( L_12 , 0 , V_225 -> V_611 , & V_612 ) )
return - V_255 ;
return 0 ;
}
static void T_16 F_388 ( struct V_225 * V_225 )
{
F_389 ( L_12 , V_225 -> V_611 ) ;
}
static void T_17 F_390 ( void )
{
F_391 ( & V_613 ) ;
F_392 ( & V_614 ) ;
F_393 ( V_239 ) ;
F_394 ( & V_445 ) ;
}
static int T_18 F_395 ( void )
{
int V_615 = F_396 ( & V_445 , 0 ) ;
if ( V_615 != 0 )
goto V_129;
F_397 ( & V_616 ) ;
F_398 ( & V_614 ) ;
F_399 ( & V_613 ) ;
V_129:
return V_615 ;
}
