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
int V_75 ,
struct V_76 * V_77 )
{
struct V_72 * V_73 ;
V_73 = V_75 ? F_68 ( & V_14 -> V_75 ) :
F_68 ( & V_14 -> V_78 ) ;
F_69 ( & V_77 -> V_79 ) ;
V_73 -> V_80 = 1 ;
F_70 ( & V_77 -> V_79 ) ;
F_65 ( V_73 ) ;
}
static void F_71 ( struct V_13 * V_14 ,
struct V_72 * V_73 ,
void (* F_72) ( unsigned long ) )
{
F_73 ( & V_73 -> V_74 ) ;
V_73 -> V_74 . V_81 = ( long ) V_14 ;
V_73 -> V_74 . V_82 = F_72 ;
V_73 -> V_74 . V_83 = V_84 ;
}
static void F_74 ( struct V_13 * V_14 )
{
struct V_72 * V_73 ;
V_73 = F_68 ( & V_14 -> V_78 ) ;
F_71 ( V_14 , V_73 , V_85 ) ;
}
static int F_75 ( struct V_13 * V_14 ,
int V_86 )
{
struct V_3 * V_4 ;
unsigned int V_87 = 0 , V_88 = 0 , div = 0 , V_89 = 0 ;
struct V_90 V_91 ;
int V_92 ;
T_5 V_93 ;
F_76 () ;
V_4 = F_77 ( F_78 ( & V_14 -> V_24 ) , V_14 -> V_94 ) ;
if ( F_2 ( ! V_4 ) ) {
F_79 () ;
return V_95 ;
}
V_92 = F_80 ( V_4 , & V_91 ) ;
V_93 = F_81 ( & V_91 ) ;
F_79 () ;
if ( ! V_92 ) {
if ( V_93 < V_96 || V_93 == V_97 ) {
return V_95 ;
} else {
V_88 = 1 ;
div = V_93 / 1000 ;
}
}
V_87 = ( V_86 * 8 ) / ( 1024 * 1024 ) ;
if ( div )
V_87 /= div ;
V_89 = V_87 * V_88 ;
if ( div )
return V_89 + 1 ;
return V_89 ;
}
static void F_82 ( struct V_72 * V_98 ,
union V_99 * V_100 )
{
V_98 -> V_101 = V_100 -> V_102 . V_103 ;
}
static void F_83 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
struct V_104 * V_68 ,
union V_99 * V_100 )
{
struct V_72 * V_98 = F_68 ( V_63 ) ;
struct V_105 * V_106 ;
memset ( V_98 , 0x0 , sizeof( * V_98 ) ) ;
V_98 -> V_107 = 1 ;
V_98 -> V_108 = V_68 ;
V_106 = (struct V_105 * ) V_68 [ 0 ] . V_69 ;
V_98 -> V_109 = V_68 [ 0 ] . V_69 ;
V_98 -> V_110 = V_100 -> V_102 . V_111 ;
V_98 -> V_112 = V_100 -> V_102 . V_113 ;
V_98 -> V_114 = V_14 -> V_115 ;
V_98 -> V_116 = V_14 -> V_37 ;
V_98 -> V_117 = 0 ;
V_14 -> V_118 . V_119 . V_120 = 0 ;
if ( V_100 -> V_102 . V_121 )
V_98 -> V_122 = V_100 -> V_102 . V_121 ;
else
V_98 -> V_122 = F_75 ( V_14 ,
V_100 -> V_102 . V_111 ) ;
V_98 -> V_123 = F_84 ( V_98 -> V_122 ) ;
V_98 -> V_124 = V_100 -> V_102 . V_125 ;
V_98 -> V_126 = V_98 -> V_110 - F_85 ( V_98 -> V_124 ) ;
F_82 ( V_98 , V_100 ) ;
F_74 ( V_14 ) ;
F_86 ( V_98 , V_106 ) ;
}
static void F_87 ( struct V_72 * V_73 )
{
F_88 ( & V_73 -> V_74 ,
V_84 + V_73 -> V_123 ) ;
V_73 -> V_117 = V_73 -> V_127 ;
}
static void V_85 ( unsigned long V_81 )
{
struct V_13 * V_14 = (struct V_13 * ) V_81 ;
struct V_72 * V_73 = F_68 ( & V_14 -> V_78 ) ;
unsigned int V_128 ;
struct V_105 * V_106 ;
F_46 ( & V_14 -> V_24 . V_129 . V_79 ) ;
V_128 = F_89 ( V_73 ) ;
V_106 = F_90 ( V_73 ) ;
if ( F_2 ( V_73 -> V_80 ) )
goto V_130;
if ( F_91 ( V_106 ) ) {
while ( F_92 ( & V_73 -> V_131 ) ) {
F_93 () ;
}
}
if ( V_73 -> V_117 == V_73 -> V_127 ) {
if ( ! V_128 ) {
if ( ! F_91 ( V_106 ) ) {
goto V_132;
}
F_94 ( V_73 , V_14 , V_133 ) ;
if ( ! F_95 ( V_73 , V_14 ) )
goto V_132;
else
goto V_130;
} else {
if ( F_96 ( V_73 , V_106 ) ) {
goto V_132;
} else {
F_86 ( V_73 , V_106 ) ;
goto V_130;
}
}
}
V_132:
F_87 ( V_73 ) ;
V_130:
F_44 ( & V_14 -> V_24 . V_129 . V_79 ) ;
}
static void F_97 ( struct V_72 * V_134 ,
struct V_105 * V_135 , T_4 V_33 )
{
#if V_136 == 1
T_6 * V_137 , * V_138 ;
V_137 = ( T_6 * ) V_135 ;
V_137 += V_139 ;
V_138 = ( T_6 * ) F_98 ( ( unsigned long ) V_134 -> V_140 ) ;
for (; V_137 < V_138 ; V_137 += V_139 )
F_53 ( F_48 ( V_137 ) ) ;
F_56 () ;
#endif
F_99 ( V_135 ) = V_33 ;
#if V_136 == 1
V_137 = ( T_6 * ) V_135 ;
F_53 ( F_48 ( V_137 ) ) ;
F_56 () ;
#endif
}
static void F_100 ( struct V_72 * V_134 ,
struct V_105 * V_135 ,
struct V_13 * V_14 , unsigned int V_141 )
{
T_4 V_33 = V_142 | V_141 ;
struct V_143 * V_144 ;
struct V_145 * V_39 = & V_135 -> V_146 . V_147 ;
struct V_23 * V_24 = & V_14 -> V_24 ;
if ( V_14 -> V_118 . V_119 . V_148 )
V_33 |= V_149 ;
V_144 = (struct V_143 * ) V_134 -> V_150 ;
V_144 -> V_151 = 0 ;
if ( F_91 ( V_135 ) ) {
V_39 -> V_152 . V_153 = V_144 -> V_56 ;
V_39 -> V_152 . V_154 = V_144 -> V_61 ;
} else {
struct V_44 V_45 ;
F_101 ( & V_45 ) ;
V_39 -> V_152 . V_153 = V_45 . V_57 ;
V_39 -> V_152 . V_154 = V_45 . V_59 ;
}
F_56 () ;
F_97 ( V_134 , V_135 , V_33 ) ;
V_24 -> V_155 ( V_24 ) ;
V_134 -> V_127 = F_102 ( V_134 ) ;
}
static void F_103 ( struct V_72 * V_73 )
{
V_73 -> V_156 = 0 ;
}
static void F_86 ( struct V_72 * V_134 ,
struct V_105 * V_135 )
{
struct V_44 V_45 ;
struct V_145 * V_39 = & V_135 -> V_146 . V_147 ;
F_58 () ;
F_104 ( V_135 ) = V_134 -> V_107 ++ ;
F_91 ( V_135 ) = 0 ;
F_105 ( V_135 ) = F_85 ( V_134 -> V_124 ) ;
F_101 ( & V_45 ) ;
V_39 -> V_157 . V_153 = V_45 . V_57 ;
V_39 -> V_157 . V_154 = V_45 . V_59 ;
V_134 -> V_109 = ( char * ) V_135 ;
V_134 -> V_158 = V_134 -> V_109 + F_85 ( V_134 -> V_124 ) ;
F_106 ( V_135 ) = ( T_4 ) F_85 ( V_134 -> V_124 ) ;
F_107 ( V_135 ) = V_159 ;
V_135 -> V_116 = V_134 -> V_116 ;
V_134 -> V_150 = V_134 -> V_158 ;
V_134 -> V_140 = V_134 -> V_109 + V_134 -> V_110 ;
F_103 ( V_134 ) ;
F_87 ( V_134 ) ;
F_56 () ;
}
static void F_108 ( struct V_72 * V_73 ,
struct V_13 * V_14 )
{
V_73 -> V_156 = 1 ;
V_14 -> V_118 . V_119 . V_120 ++ ;
}
static void * F_95 ( struct V_72 * V_73 ,
struct V_13 * V_14 )
{
struct V_105 * V_106 ;
F_58 () ;
V_106 = F_90 ( V_73 ) ;
if ( V_142 & F_99 ( V_106 ) ) {
F_108 ( V_73 , V_14 ) ;
return NULL ;
}
F_86 ( V_73 , V_106 ) ;
return ( void * ) V_73 -> V_158 ;
}
static void F_94 ( struct V_72 * V_73 ,
struct V_13 * V_14 , unsigned int V_33 )
{
struct V_105 * V_106 = F_90 ( V_73 ) ;
if ( F_22 ( V_160 == F_99 ( V_106 ) ) ) {
if ( ! ( V_33 & V_133 ) ) {
while ( F_92 ( & V_73 -> V_131 ) ) {
F_93 () ;
}
}
F_100 ( V_73 , V_106 , V_14 , V_33 ) ;
return;
}
}
static int F_96 ( struct V_72 * V_73 ,
struct V_105 * V_106 )
{
return V_142 & F_99 ( V_106 ) ;
}
static int F_89 ( struct V_72 * V_73 )
{
return V_73 -> V_156 ;
}
static void F_109 ( struct V_62 * V_63 )
{
struct V_72 * V_73 = F_68 ( V_63 ) ;
F_110 ( & V_73 -> V_131 ) ;
}
static void F_111 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
V_161 -> V_162 . V_163 = F_112 ( V_73 -> V_2 ) ;
}
static void F_113 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
V_161 -> V_162 . V_163 = 0 ;
}
static void F_114 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
if ( F_115 ( V_73 -> V_2 ) ) {
V_161 -> V_162 . V_164 = F_116 ( V_73 -> V_2 ) ;
V_161 -> V_162 . V_165 = F_117 ( V_73 -> V_2 -> V_166 ) ;
V_161 -> V_40 = V_167 | V_168 ;
} else {
V_161 -> V_162 . V_164 = 0 ;
V_161 -> V_162 . V_165 = 0 ;
V_161 -> V_40 = V_169 ;
}
}
static void F_118 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
V_161 -> V_162 . V_170 = 0 ;
F_114 ( V_73 , V_161 ) ;
if ( V_73 -> V_101 & V_171 )
F_111 ( V_73 , V_161 ) ;
else
F_113 ( V_73 , V_161 ) ;
}
static void F_119 ( char * V_172 ,
struct V_72 * V_73 ,
struct V_105 * V_106 ,
unsigned int V_173 )
{
struct V_143 * V_161 ;
V_161 = (struct V_143 * ) V_172 ;
V_161 -> V_151 = F_120 ( V_173 ) ;
V_73 -> V_150 = V_172 ;
V_73 -> V_158 += F_120 ( V_173 ) ;
F_105 ( V_106 ) += F_120 ( V_173 ) ;
F_91 ( V_106 ) += 1 ;
F_121 ( & V_73 -> V_131 ) ;
F_118 ( V_73 , V_161 ) ;
}
static void * F_122 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 ,
unsigned int V_173
)
{
struct V_72 * V_73 ;
struct V_105 * V_106 ;
char * V_172 , * V_138 ;
V_73 = F_68 ( & V_14 -> V_78 ) ;
V_106 = F_90 ( V_73 ) ;
if ( F_89 ( V_73 ) ) {
if ( F_96 ( V_73 , V_106 ) ) {
return NULL ;
} else {
F_86 ( V_73 , V_106 ) ;
}
}
F_123 () ;
V_172 = V_73 -> V_158 ;
V_73 -> V_2 = V_2 ;
V_138 = ( char * ) V_106 + V_73 -> V_110 ;
if ( V_172 + F_120 ( V_173 ) < V_138 ) {
F_119 ( V_172 , V_73 , V_106 , V_173 ) ;
return ( void * ) V_172 ;
}
F_94 ( V_73 , V_14 , 0 ) ;
V_172 = ( char * ) F_95 ( V_73 , V_14 ) ;
if ( V_172 ) {
V_106 = F_90 ( V_73 ) ;
F_119 ( V_172 , V_73 , V_106 , V_173 ) ;
return ( void * ) V_172 ;
}
return NULL ;
}
static void * F_124 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 , unsigned int V_173 )
{
char * V_172 = NULL ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_172 = F_63 ( V_14 , & V_14 -> V_78 ,
V_14 -> V_78 . V_71 , V_33 ) ;
return V_172 ;
case V_43 :
return F_122 ( V_14 , V_2 , V_33 , V_173 ) ;
default:
F_54 ( 1 , L_2 ) ;
F_55 () ;
return NULL ;
}
}
static void * F_125 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
unsigned int V_174 ,
int V_33 )
{
struct V_72 * V_73 = F_68 ( V_63 ) ;
struct V_105 * V_106 = F_126 ( V_73 , V_174 ) ;
if ( V_33 != F_99 ( V_106 ) )
return NULL ;
return V_106 ;
}
static int F_127 ( struct V_62 * V_63 )
{
unsigned int V_150 ;
if ( V_63 -> V_175 . V_127 )
V_150 = V_63 -> V_175 . V_127 - 1 ;
else
V_150 = V_63 -> V_175 . V_112 - 1 ;
return V_150 ;
}
static void * F_128 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
unsigned int V_176 = F_127 ( V_63 ) ;
return F_125 ( V_14 , V_63 , V_176 , V_33 ) ;
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
unsigned int V_176 = V_63 -> V_71 ? V_63 -> V_71 - 1 : V_63 -> V_177 ;
return F_63 ( V_14 , V_63 , V_176 , V_33 ) ;
}
static void F_132 ( struct V_62 * V_178 )
{
V_178 -> V_71 = V_178 -> V_71 != V_178 -> V_177 ? V_178 -> V_71 + 1 : 0 ;
}
static void F_133 ( struct V_62 * V_63 )
{
F_134 ( * V_63 -> V_179 ) ;
}
static void F_135 ( struct V_62 * V_63 )
{
F_136 ( * V_63 -> V_179 ) ;
}
static unsigned int F_137 ( const struct V_62 * V_63 )
{
unsigned int V_180 = 0 ;
int V_181 ;
if ( V_63 -> V_179 == NULL )
return 0 ;
F_138 (cpu)
V_180 += * F_139 ( V_63 -> V_179 , V_181 ) ;
return V_180 ;
}
static int F_140 ( struct V_13 * V_14 )
{
V_14 -> V_78 . V_179 = NULL ;
V_14 -> V_75 . V_179 = F_141 (unsigned int) ;
if ( F_2 ( V_14 -> V_75 . V_179 == NULL ) )
return - V_182 ;
return 0 ;
}
static void F_142 ( struct V_13 * V_14 )
{
F_143 ( V_14 -> V_75 . V_179 ) ;
}
static bool F_144 ( struct V_13 * V_14 , int V_183 )
{
int V_174 , V_173 ;
V_173 = V_14 -> V_78 . V_177 + 1 ;
V_174 = V_14 -> V_78 . V_71 ;
if ( V_183 )
V_174 += V_173 >> V_183 ;
if ( V_174 >= V_173 )
V_174 -= V_173 ;
return F_63 ( V_14 , & V_14 -> V_78 , V_174 , V_160 ) ;
}
static bool F_145 ( struct V_13 * V_14 , int V_183 )
{
int V_174 , V_173 ;
V_173 = V_14 -> V_78 . V_175 . V_112 ;
V_174 = V_14 -> V_78 . V_175 . V_127 ;
if ( V_183 )
V_174 += V_173 >> V_183 ;
if ( V_174 >= V_173 )
V_174 -= V_173 ;
return F_125 ( V_14 , & V_14 -> V_78 , V_174 , V_160 ) ;
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
F_69 ( & V_14 -> V_24 . V_129 . V_79 ) ;
V_8 = F_146 ( V_14 , V_2 ) ;
V_193 = V_8 == V_191 ;
if ( V_14 -> V_194 == V_193 )
V_14 -> V_194 = ! V_193 ;
F_70 ( & V_14 -> V_24 . V_129 . V_79 ) ;
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
unsigned int V_174 , bool V_209 ,
unsigned int V_206 )
{
struct V_13 * V_14 , * V_210 , * V_211 = NULL ;
unsigned int V_199 , V_212 , V_213 = V_184 ;
V_14 = F_36 ( V_205 -> V_214 [ V_174 ] ) ;
if ( V_209 ) {
V_213 = F_147 ( V_14 , V_2 ) ;
if ( V_213 == V_191 ||
( V_213 == V_192 && ! F_154 ( V_14 , V_2 ) ) )
return V_174 ;
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
return V_174 ;
}
static unsigned int F_165 ( struct V_204 * V_205 ,
struct V_1 * V_2 ,
unsigned int V_206 )
{
return F_166 ( V_2 ) % V_206 ;
}
static bool F_167 ( struct V_204 * V_205 , T_2 V_217 )
{
return V_205 -> V_46 & ( V_217 >> 8 ) ;
}
static int F_168 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_218 * V_219 , struct V_3 * V_220 )
{
struct V_204 * V_205 = V_219 -> V_221 ;
unsigned int V_206 = F_169 ( V_205 -> V_222 ) ;
struct V_13 * V_14 ;
unsigned int V_174 ;
if ( ! F_170 ( F_171 ( V_4 ) , F_172 ( & V_205 -> V_223 ) ) ||
! V_206 ) {
F_17 ( V_2 ) ;
return 0 ;
}
if ( F_167 ( V_205 , V_224 ) ) {
V_2 = F_173 ( V_2 , V_225 ) ;
if ( ! V_2 )
return 0 ;
}
switch ( V_205 -> type ) {
case V_226 :
default:
V_174 = F_156 ( V_205 , V_2 , V_206 ) ;
break;
case V_227 :
V_174 = F_158 ( V_205 , V_2 , V_206 ) ;
break;
case V_228 :
V_174 = F_160 ( V_205 , V_2 , V_206 ) ;
break;
case V_229 :
V_174 = F_161 ( V_205 , V_2 , V_206 ) ;
break;
case V_230 :
V_174 = F_165 ( V_205 , V_2 , V_206 ) ;
break;
case V_231 :
V_174 = F_163 ( V_205 , V_2 , 0 , false , V_206 ) ;
break;
}
if ( F_167 ( V_205 , V_232 ) )
V_174 = F_163 ( V_205 , V_2 , V_174 , true , V_206 ) ;
V_14 = F_36 ( V_205 -> V_214 [ V_174 ] ) ;
return V_14 -> V_27 . F_72 ( V_2 , V_4 , & V_14 -> V_27 , V_220 ) ;
}
static void F_37 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_204 * V_205 = V_14 -> V_26 ;
F_46 ( & V_205 -> V_79 ) ;
V_205 -> V_214 [ V_205 -> V_222 ] = V_24 ;
F_56 () ;
V_205 -> V_222 ++ ;
F_44 ( & V_205 -> V_79 ) ;
}
static void F_41 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_204 * V_205 = V_14 -> V_26 ;
int V_199 ;
F_46 ( & V_205 -> V_79 ) ;
for ( V_199 = 0 ; V_199 < V_205 -> V_222 ; V_199 ++ ) {
if ( V_205 -> V_214 [ V_199 ] == V_24 )
break;
}
F_174 ( V_199 >= V_205 -> V_222 ) ;
V_205 -> V_214 [ V_199 ] = V_205 -> V_214 [ V_205 -> V_222 - 1 ] ;
V_205 -> V_222 -- ;
F_44 ( & V_205 -> V_79 ) ;
}
static bool F_175 ( struct V_218 * V_233 , struct V_23 * V_24 )
{
if ( V_233 -> V_221 == ( void * ) ( (struct V_13 * ) V_24 ) -> V_26 )
return true ;
return false ;
}
static int F_176 ( struct V_23 * V_24 , T_2 V_234 , T_2 V_235 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_204 * V_205 , * V_236 ;
T_6 type = V_235 & 0xff ;
T_6 V_46 = V_235 >> 8 ;
int V_92 ;
switch ( type ) {
case V_231 :
if ( V_235 & V_232 )
return - V_237 ;
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
break;
default:
return - V_237 ;
}
if ( ! V_14 -> V_25 )
return - V_237 ;
if ( V_14 -> V_26 )
return - V_238 ;
if ( type == V_231 ||
( V_235 & V_232 ) ) {
V_14 -> V_202 = F_177 ( sizeof( * V_14 -> V_202 ) , V_239 ) ;
if ( ! V_14 -> V_202 )
return - V_240 ;
F_178 ( & V_14 -> V_202 -> V_206 , 0 ) ;
F_178 ( & V_14 -> V_202 -> V_215 , 0 ) ;
F_178 ( & V_14 -> V_202 -> V_216 , 0 ) ;
}
F_179 ( & V_241 ) ;
V_236 = NULL ;
F_180 (f, &fanout_list, list) {
if ( V_205 -> V_234 == V_234 &&
F_172 ( & V_205 -> V_223 ) == F_78 ( V_24 ) ) {
V_236 = V_205 ;
break;
}
}
V_92 = - V_237 ;
if ( V_236 && V_236 -> V_46 != V_46 )
goto V_130;
if ( ! V_236 ) {
V_92 = - V_240 ;
V_236 = F_177 ( sizeof( * V_236 ) , V_239 ) ;
if ( ! V_236 )
goto V_130;
F_181 ( & V_236 -> V_223 , F_78 ( V_24 ) ) ;
V_236 -> V_234 = V_234 ;
V_236 -> type = type ;
V_236 -> V_46 = V_46 ;
F_182 ( & V_236 -> V_208 , 0 ) ;
F_183 ( & V_236 -> V_242 ) ;
F_184 ( & V_236 -> V_79 ) ;
F_182 ( & V_236 -> V_243 , 0 ) ;
V_236 -> V_27 . type = V_14 -> V_27 . type ;
V_236 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_236 -> V_27 . F_72 = F_168 ;
V_236 -> V_27 . V_221 = V_236 ;
V_236 -> V_27 . V_244 = F_175 ;
F_38 ( & V_236 -> V_27 ) ;
F_185 ( & V_236 -> V_242 , & V_245 ) ;
}
V_92 = - V_237 ;
if ( V_236 -> type == type &&
V_236 -> V_27 . type == V_14 -> V_27 . type &&
V_236 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_92 = - V_246 ;
if ( F_92 ( & V_236 -> V_243 ) < V_247 ) {
F_42 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_236 ;
F_121 ( & V_236 -> V_243 ) ;
F_37 ( V_24 , V_14 ) ;
V_92 = 0 ;
}
}
V_130:
F_186 ( & V_241 ) ;
if ( V_92 ) {
F_187 ( V_14 -> V_202 ) ;
V_14 -> V_202 = NULL ;
}
return V_92 ;
}
static void F_188 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_204 * V_205 ;
V_205 = V_14 -> V_26 ;
if ( ! V_205 )
return;
F_179 ( & V_241 ) ;
V_14 -> V_26 = NULL ;
if ( F_189 ( & V_205 -> V_243 ) ) {
F_190 ( & V_205 -> V_242 ) ;
F_191 ( & V_205 -> V_27 ) ;
F_187 ( V_205 ) ;
}
F_186 ( & V_241 ) ;
if ( V_14 -> V_202 )
F_192 ( V_14 -> V_202 , V_248 ) ;
}
static int F_193 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_218 * V_219 , struct V_3 * V_220 )
{
struct V_23 * V_24 ;
struct V_249 * V_250 ;
V_24 = V_219 -> V_221 ;
if ( V_2 -> V_251 == V_252 )
goto V_130;
if ( ! F_170 ( F_171 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_130;
V_2 = F_194 ( V_2 , V_253 ) ;
if ( V_2 == NULL )
goto V_254;
F_195 ( V_2 ) ;
F_196 ( V_2 ) ;
V_250 = & F_197 ( V_2 ) -> V_255 . V_256 ;
F_198 ( V_2 , V_2 -> V_81 - F_199 ( V_2 ) ) ;
V_250 -> V_257 = V_4 -> type ;
F_200 ( V_250 -> V_258 , V_4 -> V_259 , sizeof( V_250 -> V_258 ) ) ;
V_250 -> V_260 = V_2 -> V_261 ;
if ( F_201 ( V_24 , V_2 ) == 0 )
return 0 ;
V_130:
F_17 ( V_2 ) ;
V_254:
return 0 ;
}
static int F_202 ( struct V_262 * V_23 , struct V_263 * V_264 ,
T_7 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_203 ( struct V_249 * , V_265 , V_264 -> V_266 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
T_8 V_267 = 0 ;
int V_92 ;
int V_268 = 0 ;
if ( V_265 ) {
if ( V_264 -> V_269 < sizeof( struct V_270 ) )
return - V_237 ;
if ( V_264 -> V_269 == sizeof( struct V_249 ) )
V_267 = V_265 -> V_260 ;
} else
return - V_271 ;
V_265 -> V_258 [ sizeof( V_265 -> V_258 ) - 1 ] = 0 ;
V_272:
F_20 () ;
V_4 = F_204 ( F_78 ( V_24 ) , V_265 -> V_258 ) ;
V_92 = - V_273 ;
if ( V_4 == NULL )
goto V_274;
V_92 = - V_275 ;
if ( ! ( V_4 -> V_46 & V_276 ) )
goto V_274;
if ( F_2 ( F_151 ( V_24 , V_277 ) ) ) {
if ( ! F_205 ( V_4 ) ) {
V_92 = - V_278 ;
goto V_274;
}
V_268 = 4 ;
}
V_92 = - V_279 ;
if ( V_173 > V_4 -> V_280 + V_4 -> V_281 + V_282 + V_268 )
goto V_274;
if ( ! V_2 ) {
T_7 V_283 = F_206 ( V_4 ) ;
int V_284 = V_4 -> V_285 ;
unsigned int V_286 = V_4 -> V_287 ? V_4 -> V_281 : 0 ;
F_24 () ;
V_2 = F_207 ( V_24 , V_173 + V_283 + V_284 , 0 , V_239 ) ;
if ( V_2 == NULL )
return - V_182 ;
F_208 ( V_2 , V_283 ) ;
F_209 ( V_2 ) ;
if ( V_286 ) {
V_2 -> V_81 -= V_286 ;
V_2 -> V_288 -= V_286 ;
if ( V_173 < V_286 )
F_209 ( V_2 ) ;
}
V_92 = F_210 ( F_211 ( V_2 , V_173 ) , V_264 , V_173 ) ;
if ( V_92 )
goto V_289;
goto V_272;
}
if ( V_173 > ( V_4 -> V_280 + V_4 -> V_281 + V_268 ) ) {
struct V_290 * V_291 ;
F_212 ( V_2 ) ;
V_291 = F_213 ( V_2 ) ;
if ( V_291 -> V_292 != F_214 ( V_293 ) ) {
V_92 = - V_279 ;
goto V_274;
}
}
V_2 -> V_261 = V_267 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_294 = V_24 -> V_295 ;
V_2 -> V_296 = V_24 -> V_297 ;
F_215 ( V_24 , & F_216 ( V_2 ) -> V_298 ) ;
if ( F_2 ( V_268 == 4 ) )
V_2 -> V_299 = 1 ;
F_217 ( V_2 , 0 ) ;
F_218 ( V_2 ) ;
F_24 () ;
return V_173 ;
V_274:
F_24 () ;
V_289:
F_17 ( V_2 ) ;
return V_92 ;
}
static unsigned int F_219 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_300 )
{
struct V_301 * V_302 ;
F_20 () ;
V_302 = F_21 ( V_24 -> V_301 ) ;
if ( V_302 != NULL )
V_300 = F_220 ( V_302 , V_2 ) ;
F_24 () ;
return V_300 ;
}
static int F_221 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_218 * V_219 , struct V_3 * V_220 )
{
struct V_23 * V_24 ;
struct V_303 * V_304 ;
struct V_13 * V_14 ;
T_6 * V_305 = V_2 -> V_81 ;
int V_306 = V_2 -> V_173 ;
unsigned int V_307 , V_300 ;
if ( V_2 -> V_251 == V_252 )
goto V_10;
V_24 = V_219 -> V_221 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_170 ( F_171 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_287 ) {
if ( V_24 -> V_308 != V_309 )
F_198 ( V_2 , V_2 -> V_81 - F_199 ( V_2 ) ) ;
else if ( V_2 -> V_251 == V_310 ) {
F_222 ( V_2 , F_223 ( V_2 ) ) ;
}
}
V_307 = V_2 -> V_173 ;
V_300 = F_219 ( V_2 , V_24 , V_307 ) ;
if ( ! V_300 )
goto V_311;
if ( V_307 > V_300 )
V_307 = V_300 ;
if ( F_92 ( & V_24 -> V_188 ) >= V_24 -> V_187 )
goto V_312;
if ( F_224 ( V_2 ) ) {
struct V_1 * V_313 = F_225 ( V_2 , V_253 ) ;
if ( V_313 == NULL )
goto V_312;
if ( V_305 != V_2 -> V_81 ) {
V_2 -> V_81 = V_305 ;
V_2 -> V_173 = V_306 ;
}
F_226 ( V_2 ) ;
V_2 = V_313 ;
}
F_227 ( sizeof( * F_197 ( V_2 ) ) + V_314 - 8 ) ;
V_304 = & F_197 ( V_2 ) -> V_255 . V_315 ;
V_304 -> V_316 = V_4 -> type ;
V_304 -> V_317 = V_2 -> V_251 ;
if ( F_2 ( V_14 -> V_318 ) )
V_304 -> V_319 = V_220 -> V_94 ;
else
V_304 -> V_319 = V_4 -> V_94 ;
V_304 -> V_320 = F_228 ( V_2 , V_304 -> V_321 ) ;
F_197 ( V_2 ) -> V_255 . V_322 = V_2 -> V_173 ;
if ( F_229 ( V_2 , V_307 ) )
goto V_312;
F_230 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_195 ( V_2 ) ;
F_196 ( V_2 ) ;
F_46 ( & V_24 -> V_129 . V_79 ) ;
V_14 -> V_118 . V_323 . V_324 ++ ;
F_231 ( V_24 , V_2 ) ;
F_232 ( & V_24 -> V_129 , V_2 ) ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
V_24 -> V_155 ( V_24 ) ;
return 0 ;
V_312:
F_46 ( & V_24 -> V_129 . V_79 ) ;
V_14 -> V_118 . V_323 . V_148 ++ ;
F_121 ( & V_24 -> V_325 ) ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
V_311:
if ( V_305 != V_2 -> V_81 && F_224 ( V_2 ) ) {
V_2 -> V_81 = V_305 ;
V_2 -> V_173 = V_306 ;
}
V_10:
F_226 ( V_2 ) ;
return 0 ;
}
static int V_185 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_218 * V_219 , struct V_3 * V_220 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
struct V_303 * V_304 ;
union V_34 V_35 ;
T_6 * V_305 = V_2 -> V_81 ;
int V_306 = V_2 -> V_173 ;
unsigned int V_307 , V_300 ;
unsigned long V_33 = V_142 ;
unsigned short V_326 , V_327 , V_114 ;
struct V_1 * V_328 = NULL ;
struct V_44 V_45 ;
T_4 V_54 ;
F_233 ( F_234 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_233 ( F_234 ( sizeof( * V_35 . V_329 ) ) != 48 ) ;
if ( V_2 -> V_251 == V_252 )
goto V_10;
V_24 = V_219 -> V_221 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_170 ( F_171 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_287 ) {
if ( V_24 -> V_308 != V_309 )
F_198 ( V_2 , V_2 -> V_81 - F_199 ( V_2 ) ) ;
else if ( V_2 -> V_251 == V_310 ) {
F_222 ( V_2 , F_223 ( V_2 ) ) ;
}
}
V_307 = V_2 -> V_173 ;
V_300 = F_219 ( V_2 , V_24 , V_307 ) ;
if ( ! V_300 )
goto V_311;
if ( V_2 -> V_330 == V_331 )
V_33 |= V_332 ;
else if ( V_2 -> V_251 != V_310 &&
( V_2 -> V_330 == V_333 ||
F_235 ( V_2 ) ) )
V_33 |= V_334 ;
if ( V_307 > V_300 )
V_307 = V_300 ;
if ( V_24 -> V_308 == V_309 ) {
V_326 = V_327 = F_234 ( V_14 -> V_115 ) + 16 +
V_14 -> V_335 ;
} else {
unsigned int V_336 = F_223 ( V_2 ) ;
V_327 = F_234 ( V_14 -> V_115 +
( V_336 < 16 ? 16 : V_336 ) ) +
V_14 -> V_335 ;
V_326 = V_327 - V_336 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_326 + V_307 > V_14 -> V_78 . V_70 ) {
if ( V_14 -> V_337 &&
F_92 ( & V_24 -> V_188 ) < V_24 -> V_187 ) {
if ( F_224 ( V_2 ) ) {
V_328 = F_225 ( V_2 , V_253 ) ;
} else {
V_328 = F_236 ( V_2 ) ;
V_305 = V_2 -> V_81 ;
}
if ( V_328 )
F_230 ( V_328 , V_24 ) ;
}
V_307 = V_14 -> V_78 . V_70 - V_326 ;
if ( ( int ) V_307 < 0 )
V_307 = 0 ;
}
} else if ( F_2 ( V_326 + V_307 >
F_68 ( & V_14 -> V_78 ) -> V_126 ) ) {
T_5 V_338 ;
V_338 = F_68 ( & V_14 -> V_78 ) -> V_126 - V_326 ;
F_237 ( L_4 ,
V_307 , V_338 , V_326 ) ;
V_307 = V_338 ;
if ( F_2 ( ( int ) V_307 < 0 ) ) {
V_307 = 0 ;
V_326 = F_68 ( & V_14 -> V_78 ) -> V_126 ;
}
}
F_46 ( & V_24 -> V_129 . V_79 ) ;
V_35 . V_36 = F_124 ( V_14 , V_2 ,
V_160 , ( V_326 + V_307 ) ) ;
if ( ! V_35 . V_36 )
goto V_339;
if ( V_14 -> V_37 <= V_41 ) {
F_131 ( V_14 , & V_14 -> V_78 ) ;
if ( V_14 -> V_118 . V_323 . V_148 )
V_33 |= V_149 ;
}
V_14 -> V_118 . V_323 . V_324 ++ ;
if ( V_328 ) {
V_33 |= V_340 ;
F_232 ( & V_24 -> V_129 , V_328 ) ;
}
F_44 ( & V_24 -> V_129 . V_79 ) ;
F_238 ( V_2 , 0 , V_35 . V_36 + V_326 , V_307 ) ;
if ( ! ( V_54 = F_59 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
F_101 ( & V_45 ) ;
V_33 |= V_54 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_341 = V_2 -> V_173 ;
V_35 . V_39 -> V_342 = V_307 ;
V_35 . V_39 -> V_343 = V_326 ;
V_35 . V_39 -> V_344 = V_327 ;
V_35 . V_39 -> V_56 = V_45 . V_57 ;
V_35 . V_39 -> V_58 = V_45 . V_59 / V_60 ;
V_114 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_341 = V_2 -> V_173 ;
V_35 . V_42 -> V_342 = V_307 ;
V_35 . V_42 -> V_343 = V_326 ;
V_35 . V_42 -> V_344 = V_327 ;
V_35 . V_42 -> V_56 = V_45 . V_57 ;
V_35 . V_42 -> V_61 = V_45 . V_59 ;
if ( F_115 ( V_2 ) ) {
V_35 . V_42 -> V_164 = F_116 ( V_2 ) ;
V_35 . V_42 -> V_165 = F_117 ( V_2 -> V_166 ) ;
V_33 |= V_167 | V_168 ;
} else {
V_35 . V_42 -> V_164 = 0 ;
V_35 . V_42 -> V_165 = 0 ;
}
memset ( V_35 . V_42 -> V_170 , 0 , sizeof( V_35 . V_42 -> V_170 ) ) ;
V_114 = sizeof( * V_35 . V_42 ) ;
break;
case V_43 :
V_35 . V_329 -> V_40 |= V_33 ;
V_35 . V_329 -> V_341 = V_2 -> V_173 ;
V_35 . V_329 -> V_342 = V_307 ;
V_35 . V_329 -> V_343 = V_326 ;
V_35 . V_329 -> V_344 = V_327 ;
V_35 . V_329 -> V_56 = V_45 . V_57 ;
V_35 . V_329 -> V_61 = V_45 . V_59 ;
memset ( V_35 . V_329 -> V_170 , 0 , sizeof( V_35 . V_329 -> V_170 ) ) ;
V_114 = sizeof( * V_35 . V_329 ) ;
break;
default:
F_55 () ;
}
V_304 = V_35 . V_36 + F_234 ( V_114 ) ;
V_304 -> V_320 = F_228 ( V_2 , V_304 -> V_321 ) ;
V_304 -> V_345 = V_346 ;
V_304 -> V_316 = V_4 -> type ;
V_304 -> V_347 = V_2 -> V_261 ;
V_304 -> V_317 = V_2 -> V_251 ;
if ( F_2 ( V_14 -> V_318 ) )
V_304 -> V_319 = V_220 -> V_94 ;
else
V_304 -> V_319 = V_4 -> V_94 ;
F_123 () ;
#if V_136 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_6 * V_137 , * V_138 ;
V_138 = ( T_6 * ) F_98 ( ( unsigned long ) V_35 . V_36 +
V_326 + V_307 ) ;
for ( V_137 = V_35 . V_36 ; V_137 < V_138 ; V_137 += V_139 )
F_53 ( F_48 ( V_137 ) ) ;
}
F_56 () ;
#endif
if ( V_14 -> V_37 <= V_41 ) {
F_52 ( V_14 , V_35 . V_36 , V_33 ) ;
V_24 -> V_155 ( V_24 ) ;
} else {
F_109 ( & V_14 -> V_78 ) ;
}
V_311:
if ( V_305 != V_2 -> V_81 && F_224 ( V_2 ) ) {
V_2 -> V_81 = V_305 ;
V_2 -> V_173 = V_306 ;
}
V_10:
F_17 ( V_2 ) ;
return 0 ;
V_339:
V_14 -> V_118 . V_323 . V_148 ++ ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
V_24 -> V_155 ( V_24 ) ;
F_17 ( V_328 ) ;
goto V_311;
}
static void F_239 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_36 ( V_2 -> V_24 ) ;
if ( F_22 ( V_14 -> V_75 . V_68 ) ) {
void * V_348 ;
T_4 V_45 ;
V_348 = F_216 ( V_2 ) -> V_349 ;
F_135 ( & V_14 -> V_75 ) ;
V_45 = F_62 ( V_14 , V_348 , V_2 ) ;
F_52 ( V_14 , V_348 , V_169 | V_45 ) ;
}
F_240 ( V_2 ) ;
}
static bool F_241 ( const struct V_3 * V_4 , int V_173 )
{
if ( F_2 ( V_173 <= V_4 -> V_281 ) ) {
F_242 ( L_5 ,
V_350 -> V_351 , V_173 , V_4 -> V_281 ) ;
return true ;
}
return false ;
}
static int F_243 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , int V_352 ,
T_8 V_267 , unsigned char * V_31 , int V_353 )
{
union V_34 V_348 ;
int V_354 , V_355 , V_173 , V_341 , V_356 , V_357 ;
struct V_262 * V_23 = V_14 -> V_24 . V_358 ;
struct V_30 * V_30 ;
void * V_81 ;
int V_92 ;
V_348 . V_36 = V_32 ;
V_2 -> V_261 = V_267 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_294 = V_14 -> V_24 . V_295 ;
V_2 -> V_296 = V_14 -> V_24 . V_297 ;
F_215 ( & V_14 -> V_24 , & F_216 ( V_2 ) -> V_298 ) ;
F_216 ( V_2 ) -> V_349 = V_348 . V_36 ;
switch ( V_14 -> V_37 ) {
case V_41 :
V_341 = V_348 . V_42 -> V_341 ;
break;
default:
V_341 = V_348 . V_39 -> V_341 ;
break;
}
if ( F_2 ( V_341 > V_352 ) ) {
F_152 ( L_6 , V_341 , V_352 ) ;
return - V_279 ;
}
F_208 ( V_2 , V_353 ) ;
F_209 ( V_2 ) ;
if ( ! F_29 ( V_14 ) )
F_217 ( V_2 , 0 ) ;
if ( F_2 ( V_14 -> V_359 ) ) {
int V_360 , V_361 , V_362 ;
V_360 = V_14 -> V_115 - sizeof( struct V_303 ) ;
V_361 = V_14 -> V_75 . V_70 - V_341 ;
if ( V_23 -> type == V_309 ) {
switch ( V_14 -> V_37 ) {
case V_41 :
V_362 = V_348 . V_42 -> V_344 ;
break;
default:
V_362 = V_348 . V_39 -> V_344 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_41 :
V_362 = V_348 . V_42 -> V_343 ;
break;
default:
V_362 = V_348 . V_39 -> V_343 ;
break;
}
}
if ( F_2 ( ( V_362 < V_360 ) || ( V_361 < V_362 ) ) )
return - V_237 ;
V_81 = V_348 . V_36 + V_362 ;
} else {
V_81 = V_348 . V_36 + V_14 -> V_115 - sizeof( struct V_303 ) ;
}
V_354 = V_341 ;
if ( V_23 -> type == V_309 ) {
V_92 = F_244 ( V_2 , V_4 , F_117 ( V_267 ) , V_31 ,
NULL , V_341 ) ;
if ( F_2 ( V_92 < 0 ) )
return - V_237 ;
} else if ( V_4 -> V_281 ) {
if ( F_241 ( V_4 , V_341 ) )
return - V_237 ;
F_198 ( V_2 , V_4 -> V_281 ) ;
V_92 = F_245 ( V_2 , 0 , V_81 ,
V_4 -> V_281 ) ;
if ( F_2 ( V_92 ) )
return V_92 ;
V_81 += V_4 -> V_281 ;
V_354 -= V_4 -> V_281 ;
}
V_355 = F_246 ( V_81 ) ;
V_357 = V_139 - V_355 ;
V_173 = ( ( V_354 > V_357 ) ? V_357 : V_354 ) ;
V_2 -> V_363 = V_354 ;
V_2 -> V_173 += V_354 ;
V_2 -> V_189 += V_354 ;
F_247 ( V_354 , & V_14 -> V_24 . V_196 ) ;
while ( F_22 ( V_354 ) ) {
V_356 = F_216 ( V_2 ) -> V_356 ;
if ( F_2 ( V_356 >= V_364 ) ) {
F_152 ( L_7 ,
V_364 ) ;
return - V_365 ;
}
V_30 = F_48 ( V_81 ) ;
V_81 += V_173 ;
F_53 ( V_30 ) ;
F_248 ( V_30 ) ;
F_249 ( V_2 , V_356 , V_30 , V_355 , V_173 ) ;
V_354 -= V_173 ;
V_355 = 0 ;
V_357 = V_139 ;
V_173 = ( ( V_354 > V_357 ) ? V_357 : V_354 ) ;
}
return V_341 ;
}
static int F_250 ( struct V_13 * V_14 , struct V_263 * V_264 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_267 ;
int V_92 , V_366 = 0 ;
void * V_348 ;
F_203 ( struct V_303 * , V_265 , V_264 -> V_266 ) ;
bool V_367 = ! ( V_264 -> V_368 & V_369 ) ;
int V_341 , V_352 ;
unsigned char * V_31 ;
int V_370 = 0 ;
int V_33 = V_169 ;
int V_353 , V_284 ;
F_179 ( & V_14 -> V_371 ) ;
if ( F_22 ( V_265 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_267 = V_14 -> V_206 ;
V_31 = NULL ;
} else {
V_92 = - V_237 ;
if ( V_264 -> V_269 < sizeof( struct V_303 ) )
goto V_130;
if ( V_264 -> V_269 < ( V_265 -> V_320
+ F_251 ( struct V_303 ,
V_321 ) ) )
goto V_130;
V_267 = V_265 -> V_347 ;
V_31 = V_265 -> V_321 ;
V_4 = F_252 ( F_78 ( & V_14 -> V_24 ) , V_265 -> V_319 ) ;
}
V_92 = - V_372 ;
if ( F_2 ( V_4 == NULL ) )
goto V_130;
V_92 = - V_275 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_276 ) ) )
goto V_373;
V_366 = V_4 -> V_281 + V_282 ;
V_352 = V_14 -> V_75 . V_70
- ( V_14 -> V_115 - sizeof( struct V_303 ) ) ;
if ( V_352 > V_4 -> V_280 + V_366 )
V_352 = V_4 -> V_280 + V_366 ;
do {
V_348 = F_64 ( V_14 , & V_14 -> V_75 ,
V_374 ) ;
if ( F_2 ( V_348 == NULL ) ) {
if ( V_367 && F_253 () )
F_254 () ;
continue;
}
V_33 = V_374 ;
V_353 = F_206 ( V_4 ) ;
V_284 = V_4 -> V_285 ;
V_2 = F_255 ( & V_14 -> V_24 ,
V_353 + V_284 + sizeof( struct V_303 ) ,
! V_367 , & V_92 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_22 ( V_370 > 0 ) )
V_92 = V_370 ;
goto V_375;
}
V_341 = F_243 ( V_14 , V_2 , V_348 , V_4 , V_352 , V_267 ,
V_31 , V_353 ) ;
if ( F_22 ( V_341 >= 0 ) &&
V_341 > V_4 -> V_280 + V_4 -> V_281 ) {
struct V_290 * V_291 ;
F_212 ( V_2 ) ;
V_291 = F_213 ( V_2 ) ;
if ( V_291 -> V_292 != F_214 ( V_293 ) )
V_341 = - V_279 ;
}
if ( F_2 ( V_341 < 0 ) ) {
if ( V_14 -> V_376 ) {
F_52 ( V_14 , V_348 ,
V_169 ) ;
F_132 ( & V_14 -> V_75 ) ;
F_17 ( V_2 ) ;
continue;
} else {
V_33 = V_377 ;
V_92 = V_341 ;
goto V_375;
}
}
F_32 ( V_4 , V_2 ) ;
V_2 -> V_378 = F_239 ;
F_52 ( V_14 , V_348 , V_379 ) ;
F_133 ( & V_14 -> V_75 ) ;
V_33 = V_374 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_92 > 0 ) ) {
V_92 = F_256 ( V_92 ) ;
if ( V_92 && F_57 ( V_14 , V_348 ) ==
V_169 ) {
V_2 = NULL ;
goto V_375;
}
V_92 = 0 ;
}
F_132 ( & V_14 -> V_75 ) ;
V_370 += V_341 ;
} while ( F_22 ( ( V_348 != NULL ) ||
( V_367 && F_137 ( & V_14 -> V_75 ) ) ) );
V_92 = V_370 ;
goto V_373;
V_375:
F_52 ( V_14 , V_348 , V_33 ) ;
F_17 ( V_2 ) ;
V_373:
F_257 ( V_4 ) ;
V_130:
F_186 ( & V_14 -> V_371 ) ;
return V_92 ;
}
static struct V_1 * F_258 ( struct V_23 * V_24 , T_7 V_380 ,
T_7 V_366 , T_7 V_173 ,
T_7 V_381 , int V_382 ,
int * V_92 )
{
struct V_1 * V_2 ;
if ( V_380 + V_173 < V_139 || ! V_381 )
V_381 = V_173 ;
V_2 = F_259 ( V_24 , V_380 + V_381 , V_173 - V_381 , V_382 ,
V_92 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_208 ( V_2 , V_366 ) ;
F_211 ( V_2 , V_381 ) ;
V_2 -> V_363 = V_173 - V_381 ;
V_2 -> V_173 += V_173 - V_381 ;
return V_2 ;
}
static int F_260 ( struct V_262 * V_23 , struct V_263 * V_264 , T_7 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_203 ( struct V_303 * , V_265 , V_264 -> V_266 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_267 ;
unsigned char * V_31 ;
int V_92 , V_366 = 0 ;
struct V_383 V_384 = { 0 } ;
int V_355 = 0 ;
int V_385 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned short V_386 = 0 ;
int V_353 , V_284 ;
int V_268 = 0 ;
T_9 V_387 ;
if ( F_22 ( V_265 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_267 = V_14 -> V_206 ;
V_31 = NULL ;
} else {
V_92 = - V_237 ;
if ( V_264 -> V_269 < sizeof( struct V_303 ) )
goto V_130;
if ( V_264 -> V_269 < ( V_265 -> V_320 + F_251 ( struct V_303 , V_321 ) ) )
goto V_130;
V_267 = V_265 -> V_347 ;
V_31 = V_265 -> V_321 ;
V_4 = F_252 ( F_78 ( V_24 ) , V_265 -> V_319 ) ;
}
V_92 = - V_372 ;
if ( F_2 ( V_4 == NULL ) )
goto V_274;
V_92 = - V_275 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_276 ) ) )
goto V_274;
if ( V_23 -> type == V_388 )
V_366 = V_4 -> V_281 ;
if ( V_14 -> V_389 ) {
V_385 = sizeof( V_384 ) ;
V_92 = - V_237 ;
if ( V_173 < V_385 )
goto V_274;
V_173 -= V_385 ;
V_92 = - V_365 ;
V_387 = F_261 ( & V_384 , V_385 , & V_264 -> V_390 ) ;
if ( V_387 != V_385 )
goto V_274;
if ( ( V_384 . V_46 & V_391 ) &&
( F_262 ( false , V_384 . V_392 ) +
F_262 ( false , V_384 . V_393 ) + 2 >
F_262 ( false , V_384 . V_394 ) ) )
V_384 . V_394 = F_263 ( false ,
F_262 ( false , V_384 . V_392 ) +
F_262 ( false , V_384 . V_393 ) + 2 ) ;
V_92 = - V_237 ;
if ( F_262 ( false , V_384 . V_394 ) > V_173 )
goto V_274;
if ( V_384 . V_386 != V_395 ) {
switch ( V_384 . V_386 & ~ V_396 ) {
case V_397 :
V_386 = V_398 ;
break;
case V_399 :
V_386 = V_400 ;
break;
case V_401 :
V_386 = V_402 ;
break;
default:
goto V_274;
}
if ( V_384 . V_386 & V_396 )
V_386 |= V_403 ;
if ( V_384 . V_404 == 0 )
goto V_274;
}
}
if ( F_2 ( F_151 ( V_24 , V_277 ) ) ) {
if ( ! F_205 ( V_4 ) ) {
V_92 = - V_278 ;
goto V_274;
}
V_268 = 4 ;
}
V_92 = - V_279 ;
if ( ! V_386 && ( V_173 > V_4 -> V_280 + V_366 + V_282 + V_268 ) )
goto V_274;
V_92 = - V_182 ;
V_353 = F_206 ( V_4 ) ;
V_284 = V_4 -> V_285 ;
V_2 = F_258 ( V_24 , V_353 + V_284 , V_353 , V_173 ,
F_262 ( false , V_384 . V_394 ) ,
V_264 -> V_368 & V_369 , & V_92 ) ;
if ( V_2 == NULL )
goto V_274;
F_264 ( V_2 , V_366 ) ;
V_92 = - V_237 ;
if ( V_23 -> type == V_309 ) {
V_355 = F_244 ( V_2 , V_4 , F_117 ( V_267 ) , V_31 , NULL , V_173 ) ;
if ( F_2 ( V_355 < 0 ) )
goto V_289;
} else {
if ( F_241 ( V_4 , V_173 ) )
goto V_289;
}
V_92 = F_265 ( V_2 , V_355 , & V_264 -> V_390 , V_173 ) ;
if ( V_92 )
goto V_289;
F_215 ( V_24 , & F_216 ( V_2 ) -> V_298 ) ;
if ( ! V_386 && ( V_173 > V_4 -> V_280 + V_366 + V_268 ) ) {
struct V_290 * V_291 ;
F_212 ( V_2 ) ;
V_291 = F_213 ( V_2 ) ;
if ( V_291 -> V_292 != F_214 ( V_293 ) ) {
V_92 = - V_279 ;
goto V_289;
}
}
V_2 -> V_261 = V_267 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_294 = V_24 -> V_295 ;
V_2 -> V_296 = V_24 -> V_297 ;
F_32 ( V_4 , V_2 ) ;
if ( V_14 -> V_389 ) {
if ( V_384 . V_46 & V_391 ) {
T_2 V_405 = F_262 ( false , V_384 . V_392 ) ;
T_2 V_406 = F_262 ( false , V_384 . V_393 ) ;
if ( ! F_266 ( V_2 , V_405 , V_406 ) ) {
V_92 = - V_237 ;
goto V_289;
}
}
F_216 ( V_2 ) -> V_404 =
F_262 ( false , V_384 . V_404 ) ;
F_216 ( V_2 ) -> V_386 = V_386 ;
F_216 ( V_2 ) -> V_386 |= V_407 ;
F_216 ( V_2 ) -> V_408 = 0 ;
V_173 += V_385 ;
}
if ( ! F_29 ( V_14 ) )
F_217 ( V_2 , V_366 ) ;
if ( F_2 ( V_268 == 4 ) )
V_2 -> V_299 = 1 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( V_92 > 0 && ( V_92 = F_256 ( V_92 ) ) != 0 )
goto V_274;
F_257 ( V_4 ) ;
return V_173 ;
V_289:
F_17 ( V_2 ) ;
V_274:
if ( V_4 )
F_257 ( V_4 ) ;
V_130:
return V_92 ;
}
static int F_267 ( struct V_262 * V_23 , struct V_263 * V_264 , T_7 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
if ( V_14 -> V_75 . V_68 )
return F_250 ( V_14 , V_264 ) ;
else
return F_260 ( V_23 , V_264 , V_173 ) ;
}
static int F_268 ( struct V_262 * V_23 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 ;
struct V_223 * V_223 ;
union V_99 V_100 ;
if ( ! V_24 )
return 0 ;
V_223 = F_78 ( V_24 ) ;
V_14 = F_36 ( V_24 ) ;
F_179 ( & V_223 -> V_409 . V_410 ) ;
F_269 ( V_24 ) ;
F_186 ( & V_223 -> V_409 . V_410 ) ;
F_270 () ;
F_271 ( V_223 , V_24 -> V_411 , - 1 ) ;
F_272 () ;
F_46 ( & V_14 -> V_29 ) ;
F_47 ( V_24 , false ) ;
F_27 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_257 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
F_273 ( V_24 ) ;
if ( V_14 -> V_78 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_274 ( V_24 , & V_100 , 1 , 0 ) ;
}
if ( V_14 -> V_75 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_274 ( V_24 , & V_100 , 1 , 1 ) ;
}
F_188 ( V_24 ) ;
F_45 () ;
F_275 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_149 ( & V_24 -> V_129 ) ;
F_142 ( V_14 ) ;
F_276 ( V_24 ) ;
F_277 ( V_24 ) ;
return 0 ;
}
static int F_278 ( struct V_23 * V_24 , struct V_3 * V_4 , T_8 V_267 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_3 * V_412 ;
T_8 V_413 ;
bool V_414 ;
if ( V_14 -> V_26 ) {
if ( V_4 )
F_257 ( V_4 ) ;
return - V_237 ;
}
F_279 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_413 = V_14 -> V_27 . type ;
V_412 = V_14 -> V_27 . V_4 ;
V_414 = V_413 != V_267 || V_412 != V_4 ;
if ( V_414 ) {
F_47 ( V_24 , true ) ;
V_14 -> V_206 = V_267 ;
V_14 -> V_27 . type = V_267 ;
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_94 = V_4 ? V_4 -> V_94 : 0 ;
F_25 ( V_14 , V_4 ) ;
}
if ( V_412 )
F_257 ( V_412 ) ;
if ( V_267 == 0 || ! V_414 )
goto V_274;
if ( ! V_4 || ( V_4 -> V_46 & V_276 ) ) {
F_35 ( V_24 ) ;
} else {
V_24 -> V_415 = V_275 ;
if ( ! F_151 ( V_24 , V_197 ) )
V_24 -> V_416 ( V_24 ) ;
}
V_274:
F_44 ( & V_14 -> V_29 ) ;
F_280 ( V_24 ) ;
return 0 ;
}
static int F_281 ( struct V_262 * V_23 , struct V_270 * V_417 ,
int V_418 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_259 [ 15 ] ;
struct V_3 * V_4 ;
int V_92 = - V_273 ;
if ( V_418 != sizeof( struct V_270 ) )
return - V_237 ;
F_200 ( V_259 , V_417 -> V_419 , sizeof( V_259 ) ) ;
V_4 = F_282 ( F_78 ( V_24 ) , V_259 ) ;
if ( V_4 )
V_92 = F_278 ( V_24 , V_4 , F_36 ( V_24 ) -> V_206 ) ;
return V_92 ;
}
static int F_283 ( struct V_262 * V_23 , struct V_270 * V_417 , int V_418 )
{
struct V_303 * V_304 = (struct V_303 * ) V_417 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_3 * V_4 = NULL ;
int V_92 ;
if ( V_418 < sizeof( struct V_303 ) )
return - V_237 ;
if ( V_304 -> V_345 != V_346 )
return - V_237 ;
if ( V_304 -> V_319 ) {
V_92 = - V_273 ;
V_4 = F_252 ( F_78 ( V_24 ) , V_304 -> V_319 ) ;
if ( V_4 == NULL )
goto V_130;
}
V_92 = F_278 ( V_24 , V_4 , V_304 -> V_347 ? : F_36 ( V_24 ) -> V_206 ) ;
V_130:
return V_92 ;
}
static int F_284 ( struct V_223 * V_223 , struct V_262 * V_23 , int V_261 ,
int V_420 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_8 V_267 = ( V_421 T_8 ) V_261 ;
int V_92 ;
if ( ! F_285 ( V_223 -> V_422 , V_423 ) )
return - V_424 ;
if ( V_23 -> type != V_309 && V_23 -> type != V_388 &&
V_23 -> type != V_425 )
return - V_426 ;
V_23 -> V_427 = V_428 ;
V_92 = - V_182 ;
V_24 = F_286 ( V_223 , V_429 , V_239 , & V_430 , V_420 ) ;
if ( V_24 == NULL )
goto V_130;
V_23 -> V_19 = & V_431 ;
if ( V_23 -> type == V_425 )
V_23 -> V_19 = & V_432 ;
F_287 ( V_23 , V_24 ) ;
V_14 = F_36 ( V_24 ) ;
V_24 -> V_433 = V_429 ;
V_14 -> V_206 = V_267 ;
V_14 -> V_16 = F_218 ;
V_92 = F_140 ( V_14 ) ;
if ( V_92 )
goto V_434;
F_27 ( V_14 ) ;
V_24 -> V_435 = F_148 ;
F_288 ( V_24 ) ;
F_184 ( & V_14 -> V_29 ) ;
F_289 ( & V_14 -> V_371 ) ;
V_14 -> V_202 = NULL ;
V_14 -> V_27 . F_72 = F_221 ;
if ( V_23 -> type == V_425 )
V_14 -> V_27 . F_72 = F_193 ;
V_14 -> V_27 . V_221 = V_24 ;
if ( V_267 ) {
V_14 -> V_27 . type = V_267 ;
F_35 ( V_24 ) ;
}
F_179 ( & V_223 -> V_409 . V_410 ) ;
F_290 ( V_24 , & V_223 -> V_409 . V_436 ) ;
F_186 ( & V_223 -> V_409 . V_410 ) ;
F_270 () ;
F_271 ( V_223 , & V_430 , 1 ) ;
F_272 () ;
return 0 ;
V_434:
F_291 ( V_24 ) ;
V_130:
return V_92 ;
}
static int F_292 ( struct V_262 * V_23 , struct V_263 * V_264 , T_7 V_173 ,
int V_46 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_437 , V_92 ;
int V_385 = 0 ;
unsigned int V_322 = 0 ;
V_92 = - V_237 ;
if ( V_46 & ~ ( V_438 | V_369 | V_439 | V_440 | V_441 ) )
goto V_130;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_46 & V_441 ) {
V_92 = F_293 ( V_24 , V_264 , V_173 ,
V_442 , V_443 ) ;
goto V_130;
}
V_2 = F_294 ( V_24 , V_46 , V_46 & V_369 , & V_92 ) ;
if ( V_2 == NULL )
goto V_130;
if ( F_36 ( V_24 ) -> V_194 )
F_147 ( F_36 ( V_24 ) , NULL ) ;
if ( F_36 ( V_24 ) -> V_389 ) {
struct V_383 V_384 = { 0 } ;
V_92 = - V_237 ;
V_385 = sizeof( V_384 ) ;
if ( V_173 < V_385 )
goto V_289;
V_173 -= V_385 ;
if ( F_295 ( V_2 ) ) {
struct V_444 * V_445 = F_216 ( V_2 ) ;
V_384 . V_394 =
F_263 ( false , F_296 ( V_2 ) ) ;
V_384 . V_404 =
F_263 ( false , V_445 -> V_404 ) ;
if ( V_445 -> V_386 & V_398 )
V_384 . V_386 = V_397 ;
else if ( V_445 -> V_386 & V_400 )
V_384 . V_386 = V_399 ;
else if ( V_445 -> V_386 & V_402 )
V_384 . V_386 = V_401 ;
else if ( V_445 -> V_386 & V_446 )
goto V_289;
else
F_55 () ;
if ( V_445 -> V_386 & V_403 )
V_384 . V_386 |= V_396 ;
} else
V_384 . V_386 = V_395 ;
if ( V_2 -> V_330 == V_331 ) {
V_384 . V_46 = V_391 ;
V_384 . V_392 = F_263 ( false ,
F_297 ( V_2 ) ) ;
V_384 . V_393 = F_263 ( false ,
V_2 -> V_393 ) ;
} else if ( V_2 -> V_330 == V_447 ) {
V_384 . V_46 = V_448 ;
}
V_92 = F_298 ( V_264 , ( void * ) & V_384 , V_385 ) ;
if ( V_92 < 0 )
goto V_289;
}
V_437 = V_2 -> V_173 ;
if ( V_437 > V_173 ) {
V_437 = V_173 ;
V_264 -> V_368 |= V_439 ;
}
V_92 = F_299 ( V_2 , 0 , V_264 , V_437 ) ;
if ( V_92 )
goto V_289;
if ( V_23 -> type != V_425 ) {
struct V_303 * V_304 = & F_197 ( V_2 ) -> V_255 . V_315 ;
V_322 = F_197 ( V_2 ) -> V_255 . V_322 ;
V_304 -> V_345 = V_346 ;
V_304 -> V_347 = V_2 -> V_261 ;
}
F_300 ( V_264 , V_24 , V_2 ) ;
if ( V_264 -> V_266 ) {
if ( V_23 -> type == V_425 ) {
F_301 ( sizeof( struct V_249 ) ) ;
V_264 -> V_269 = sizeof( struct V_249 ) ;
} else {
struct V_303 * V_304 = & F_197 ( V_2 ) -> V_255 . V_315 ;
V_264 -> V_269 = V_304 -> V_320 +
F_251 ( struct V_303 , V_321 ) ;
}
memcpy ( V_264 -> V_266 , & F_197 ( V_2 ) -> V_255 ,
V_264 -> V_269 ) ;
}
if ( F_36 ( V_24 ) -> V_449 ) {
struct V_450 V_451 ;
V_451 . V_40 = V_142 ;
if ( V_2 -> V_330 == V_331 )
V_451 . V_40 |= V_332 ;
else if ( V_2 -> V_251 != V_310 &&
( V_2 -> V_330 == V_333 ||
F_235 ( V_2 ) ) )
V_451 . V_40 |= V_334 ;
V_451 . V_341 = V_322 ;
V_451 . V_342 = V_2 -> V_173 ;
V_451 . V_343 = 0 ;
V_451 . V_344 = F_223 ( V_2 ) ;
if ( F_115 ( V_2 ) ) {
V_451 . V_164 = F_116 ( V_2 ) ;
V_451 . V_165 = F_117 ( V_2 -> V_166 ) ;
V_451 . V_40 |= V_167 | V_168 ;
} else {
V_451 . V_164 = 0 ;
V_451 . V_165 = 0 ;
}
F_302 ( V_264 , V_442 , V_452 , sizeof( V_451 ) , & V_451 ) ;
}
V_92 = V_385 + ( ( V_46 & V_439 ) ? V_2 -> V_173 : V_437 ) ;
V_289:
F_303 ( V_24 , V_2 ) ;
V_130:
return V_92 ;
}
static int F_304 ( struct V_262 * V_23 , struct V_270 * V_417 ,
int * V_453 , int V_454 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_454 )
return - V_455 ;
V_417 -> V_456 = V_346 ;
memset ( V_417 -> V_419 , 0 , sizeof( V_417 -> V_419 ) ) ;
F_20 () ;
V_4 = F_305 ( F_78 ( V_24 ) , F_36 ( V_24 ) -> V_94 ) ;
if ( V_4 )
F_200 ( V_417 -> V_419 , V_4 -> V_259 , sizeof( V_417 -> V_419 ) ) ;
F_24 () ;
* V_453 = sizeof( * V_417 ) ;
return 0 ;
}
static int F_306 ( struct V_262 * V_23 , struct V_270 * V_417 ,
int * V_453 , int V_454 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
F_203 ( struct V_303 * , V_304 , V_417 ) ;
if ( V_454 )
return - V_455 ;
V_304 -> V_345 = V_346 ;
V_304 -> V_319 = V_14 -> V_94 ;
V_304 -> V_347 = V_14 -> V_206 ;
V_304 -> V_317 = 0 ;
F_20 () ;
V_4 = F_305 ( F_78 ( V_24 ) , V_14 -> V_94 ) ;
if ( V_4 ) {
V_304 -> V_316 = V_4 -> type ;
V_304 -> V_320 = V_4 -> V_418 ;
memcpy ( V_304 -> V_321 , V_4 -> V_457 , V_4 -> V_418 ) ;
} else {
V_304 -> V_316 = 0 ;
V_304 -> V_320 = 0 ;
}
F_24 () ;
* V_453 = F_251 ( struct V_303 , V_321 ) + V_304 -> V_320 ;
return 0 ;
}
static int F_307 ( struct V_3 * V_4 , struct V_458 * V_199 ,
int V_459 )
{
switch ( V_199 -> type ) {
case V_460 :
if ( V_199 -> V_461 != V_4 -> V_418 )
return - V_237 ;
if ( V_459 > 0 )
return F_308 ( V_4 , V_199 -> V_31 ) ;
else
return F_309 ( V_4 , V_199 -> V_31 ) ;
break;
case V_462 :
return F_310 ( V_4 , V_459 ) ;
case V_463 :
return F_311 ( V_4 , V_459 ) ;
case V_464 :
if ( V_199 -> V_461 != V_4 -> V_418 )
return - V_237 ;
if ( V_459 > 0 )
return F_312 ( V_4 , V_199 -> V_31 ) ;
else
return F_313 ( V_4 , V_199 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_314 ( struct V_3 * V_4 ,
struct V_458 * * V_465 )
{
struct V_458 * V_466 ;
while ( ( V_466 = * V_465 ) != NULL ) {
if ( V_466 -> V_94 == V_4 -> V_94 ) {
F_307 ( V_4 , V_466 , - 1 ) ;
* V_465 = V_466 -> V_467 ;
F_187 ( V_466 ) ;
} else
V_465 = & V_466 -> V_467 ;
}
}
static int F_315 ( struct V_23 * V_24 , struct V_468 * V_469 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_458 * V_466 , * V_199 ;
struct V_3 * V_4 ;
int V_92 ;
F_76 () ;
V_92 = - V_273 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_469 -> V_470 ) ;
if ( ! V_4 )
goto V_471;
V_92 = - V_237 ;
if ( V_469 -> V_472 > V_4 -> V_418 )
goto V_471;
V_92 = - V_182 ;
V_199 = F_316 ( sizeof( * V_199 ) , V_239 ) ;
if ( V_199 == NULL )
goto V_471;
V_92 = 0 ;
for ( V_466 = V_14 -> V_473 ; V_466 ; V_466 = V_466 -> V_467 ) {
if ( V_466 -> V_94 == V_469 -> V_470 &&
V_466 -> type == V_469 -> V_474 &&
V_466 -> V_461 == V_469 -> V_472 &&
memcmp ( V_466 -> V_31 , V_469 -> V_475 , V_466 -> V_461 ) == 0 ) {
V_466 -> V_200 ++ ;
F_187 ( V_199 ) ;
goto V_471;
}
}
V_199 -> type = V_469 -> V_474 ;
V_199 -> V_94 = V_469 -> V_470 ;
V_199 -> V_461 = V_469 -> V_472 ;
memcpy ( V_199 -> V_31 , V_469 -> V_475 , V_199 -> V_461 ) ;
V_199 -> V_200 = 1 ;
V_199 -> V_467 = V_14 -> V_473 ;
V_14 -> V_473 = V_199 ;
V_92 = F_307 ( V_4 , V_199 , 1 ) ;
if ( V_92 ) {
V_14 -> V_473 = V_199 -> V_467 ;
F_187 ( V_199 ) ;
}
V_471:
F_79 () ;
return V_92 ;
}
static int F_317 ( struct V_23 * V_24 , struct V_468 * V_469 )
{
struct V_458 * V_466 , * * V_465 ;
F_76 () ;
for ( V_465 = & F_36 ( V_24 ) -> V_473 ; ( V_466 = * V_465 ) != NULL ; V_465 = & V_466 -> V_467 ) {
if ( V_466 -> V_94 == V_469 -> V_470 &&
V_466 -> type == V_469 -> V_474 &&
V_466 -> V_461 == V_469 -> V_472 &&
memcmp ( V_466 -> V_31 , V_469 -> V_475 , V_466 -> V_461 ) == 0 ) {
if ( -- V_466 -> V_200 == 0 ) {
struct V_3 * V_4 ;
* V_465 = V_466 -> V_467 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_466 -> V_94 ) ;
if ( V_4 )
F_307 ( V_4 , V_466 , - 1 ) ;
F_187 ( V_466 ) ;
}
break;
}
}
F_79 () ;
return 0 ;
}
static void F_273 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_458 * V_466 ;
if ( ! V_14 -> V_473 )
return;
F_76 () ;
while ( ( V_466 = V_14 -> V_473 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_473 = V_466 -> V_467 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_466 -> V_94 ) ;
if ( V_4 != NULL )
F_307 ( V_4 , V_466 , - 1 ) ;
F_187 ( V_466 ) ;
}
F_79 () ;
}
static int
F_318 ( struct V_262 * V_23 , int V_476 , int V_477 , char T_10 * V_478 , unsigned int V_479 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_8 ;
if ( V_476 != V_442 )
return - V_480 ;
switch ( V_477 ) {
case V_481 :
case V_482 :
{
struct V_468 V_469 ;
int V_173 = V_479 ;
memset ( & V_469 , 0 , sizeof( V_469 ) ) ;
if ( V_173 < sizeof( struct V_483 ) )
return - V_237 ;
if ( V_173 > sizeof( V_469 ) )
V_173 = sizeof( V_469 ) ;
if ( F_319 ( & V_469 , V_478 , V_173 ) )
return - V_365 ;
if ( V_173 < ( V_469 . V_472 + F_251 ( struct V_483 , V_475 ) ) )
return - V_237 ;
if ( V_477 == V_481 )
V_8 = F_315 ( V_24 , & V_469 ) ;
else
V_8 = F_317 ( V_24 , & V_469 ) ;
return V_8 ;
}
case V_484 :
case V_485 :
{
union V_99 V_100 ;
int V_173 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_173 = sizeof( V_100 . V_486 ) ;
break;
case V_43 :
default:
V_173 = sizeof( V_100 . V_102 ) ;
break;
}
if ( V_479 < V_173 )
return - V_237 ;
if ( F_36 ( V_24 ) -> V_389 )
return - V_237 ;
if ( F_319 ( & V_100 . V_486 , V_478 , V_173 ) )
return - V_365 ;
return F_274 ( V_24 , & V_100 , 0 ,
V_477 == V_485 ) ;
}
case V_487 :
{
int V_207 ;
if ( V_479 != sizeof( V_207 ) )
return - V_237 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
F_36 ( V_24 ) -> V_337 = V_207 ;
return 0 ;
}
case V_488 :
{
int V_207 ;
if ( V_479 != sizeof( V_207 ) )
return - V_237 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_489 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
switch ( V_207 ) {
case V_38 :
case V_41 :
case V_43 :
V_14 -> V_37 = V_207 ;
return 0 ;
default:
return - V_237 ;
}
}
case V_490 :
{
unsigned int V_207 ;
if ( V_479 != sizeof( V_207 ) )
return - V_237 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_489 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
V_14 -> V_335 = V_207 ;
return 0 ;
}
case V_491 :
{
unsigned int V_207 ;
if ( V_479 != sizeof( V_207 ) )
return - V_237 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_489 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
V_14 -> V_376 = ! ! V_207 ;
return 0 ;
}
case V_452 :
{
int V_207 ;
if ( V_479 < sizeof( V_207 ) )
return - V_237 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
V_14 -> V_449 = ! ! V_207 ;
return 0 ;
}
case V_492 :
{
int V_207 ;
if ( V_479 < sizeof( V_207 ) )
return - V_237 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
V_14 -> V_318 = ! ! V_207 ;
return 0 ;
}
case V_493 :
{
int V_207 ;
if ( V_23 -> type != V_388 )
return - V_237 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_489 ;
if ( V_479 < sizeof( V_207 ) )
return - V_237 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
V_14 -> V_389 = ! ! V_207 ;
return 0 ;
}
case V_494 :
{
int V_207 ;
if ( V_479 != sizeof( V_207 ) )
return - V_237 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
V_14 -> V_55 = V_207 ;
return 0 ;
}
case V_495 :
{
int V_207 ;
if ( V_479 != sizeof( V_207 ) )
return - V_237 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
return F_176 ( V_24 , V_207 & 0xffff , V_207 >> 16 ) ;
}
case V_496 :
{
unsigned int V_207 ;
if ( V_479 != sizeof( V_207 ) )
return - V_237 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_489 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
V_14 -> V_359 = ! ! V_207 ;
return 0 ;
}
case V_497 :
{
int V_207 ;
if ( V_479 != sizeof( V_207 ) )
return - V_237 ;
if ( F_319 ( & V_207 , V_478 , sizeof( V_207 ) ) )
return - V_365 ;
V_14 -> V_16 = V_207 ? F_1 : F_218 ;
return 0 ;
}
default:
return - V_480 ;
}
}
static int F_320 ( struct V_262 * V_23 , int V_476 , int V_477 ,
char T_10 * V_478 , int T_10 * V_479 )
{
int V_173 ;
int V_207 , V_498 = sizeof( V_207 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
void * V_81 = & V_207 ;
union V_499 V_500 ;
struct V_501 V_502 ;
if ( V_476 != V_442 )
return - V_480 ;
if ( F_321 ( V_173 , V_479 ) )
return - V_365 ;
if ( V_173 < 0 )
return - V_237 ;
switch ( V_477 ) {
case V_503 :
F_69 ( & V_24 -> V_129 . V_79 ) ;
memcpy ( & V_500 , & V_14 -> V_118 , sizeof( V_500 ) ) ;
memset ( & V_14 -> V_118 , 0 , sizeof( V_14 -> V_118 ) ) ;
F_70 ( & V_24 -> V_129 . V_79 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_498 = sizeof( struct V_504 ) ;
V_500 . V_119 . V_324 += V_500 . V_119 . V_148 ;
V_81 = & V_500 . V_119 ;
} else {
V_498 = sizeof( struct V_505 ) ;
V_500 . V_323 . V_324 += V_500 . V_323 . V_148 ;
V_81 = & V_500 . V_323 ;
}
break;
case V_452 :
V_207 = V_14 -> V_449 ;
break;
case V_492 :
V_207 = V_14 -> V_318 ;
break;
case V_493 :
V_207 = V_14 -> V_389 ;
break;
case V_488 :
V_207 = V_14 -> V_37 ;
break;
case V_506 :
if ( V_173 > sizeof( int ) )
V_173 = sizeof( int ) ;
if ( F_319 ( & V_207 , V_478 , V_173 ) )
return - V_365 ;
switch ( V_207 ) {
case V_38 :
V_207 = sizeof( struct V_507 ) ;
break;
case V_41 :
V_207 = sizeof( struct V_508 ) ;
break;
case V_43 :
V_207 = sizeof( struct V_143 ) ;
break;
default:
return - V_237 ;
}
break;
case V_490 :
V_207 = V_14 -> V_335 ;
break;
case V_491 :
V_207 = V_14 -> V_376 ;
break;
case V_494 :
V_207 = V_14 -> V_55 ;
break;
case V_495 :
V_207 = ( V_14 -> V_26 ?
( ( T_5 ) V_14 -> V_26 -> V_234 |
( ( T_5 ) V_14 -> V_26 -> type << 16 ) |
( ( T_5 ) V_14 -> V_26 -> V_46 << 24 ) ) :
0 ) ;
break;
case V_509 :
if ( ! V_14 -> V_202 )
return - V_237 ;
V_502 . V_510 = F_322 ( & V_14 -> V_202 -> V_206 ) ;
V_502 . V_511 = F_322 ( & V_14 -> V_202 -> V_215 ) ;
V_502 . V_512 = F_322 ( & V_14 -> V_202 -> V_216 ) ;
V_81 = & V_502 ;
V_498 = sizeof( V_502 ) ;
break;
case V_496 :
V_207 = V_14 -> V_359 ;
break;
case V_497 :
V_207 = F_29 ( V_14 ) ;
break;
default:
return - V_480 ;
}
if ( V_173 > V_498 )
V_173 = V_498 ;
if ( F_323 ( V_173 , V_479 ) )
return - V_365 ;
if ( F_324 ( V_478 , V_81 , V_173 ) )
return - V_365 ;
return 0 ;
}
static int F_325 ( struct V_513 * V_514 ,
unsigned long V_264 , void * V_515 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_326 ( V_515 ) ;
struct V_223 * V_223 = F_171 ( V_4 ) ;
F_20 () ;
F_327 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_36 ( V_24 ) ;
switch ( V_264 ) {
case V_516 :
if ( V_14 -> V_473 )
F_314 ( V_4 , & V_14 -> V_473 ) ;
case V_517 :
if ( V_4 -> V_94 == V_14 -> V_94 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_40 ( V_24 , false ) ;
V_24 -> V_415 = V_275 ;
if ( ! F_151 ( V_24 , V_197 ) )
V_24 -> V_416 ( V_24 ) ;
}
if ( V_264 == V_516 ) {
F_27 ( V_14 ) ;
V_14 -> V_94 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_257 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
}
break;
case V_518 :
if ( V_4 -> V_94 == V_14 -> V_94 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_206 )
F_35 ( V_24 ) ;
F_44 ( & V_14 -> V_29 ) ;
}
break;
}
}
F_24 () ;
return V_519 ;
}
static int F_328 ( struct V_262 * V_23 , unsigned int V_520 ,
unsigned long V_521 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_520 ) {
case V_522 :
{
int V_523 = F_329 ( V_24 ) ;
return F_323 ( V_523 , ( int T_10 * ) V_521 ) ;
}
case V_524 :
{
struct V_1 * V_2 ;
int V_523 = 0 ;
F_69 ( & V_24 -> V_129 . V_79 ) ;
V_2 = F_330 ( & V_24 -> V_129 ) ;
if ( V_2 )
V_523 = V_2 -> V_173 ;
F_70 ( & V_24 -> V_129 . V_79 ) ;
return F_323 ( V_523 , ( int T_10 * ) V_521 ) ;
}
case V_525 :
return F_331 ( V_24 , (struct V_526 T_10 * ) V_521 ) ;
case V_527 :
return F_332 ( V_24 , (struct V_44 T_10 * ) V_521 ) ;
#ifdef F_333
case V_528 :
case V_529 :
case V_530 :
case V_531 :
case V_532 :
case V_533 :
case V_534 :
case V_535 :
case V_536 :
case V_537 :
case V_538 :
case V_539 :
case V_540 :
case V_541 :
return V_542 . V_543 ( V_23 , V_520 , V_521 ) ;
#endif
default:
return - V_544 ;
}
return 0 ;
}
static unsigned int F_334 ( struct V_545 * V_545 , struct V_262 * V_23 ,
T_11 * V_546 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned int V_547 = F_335 ( V_545 , V_23 , V_546 ) ;
F_69 ( & V_24 -> V_129 . V_79 ) ;
if ( V_14 -> V_78 . V_68 ) {
if ( ! F_129 ( V_14 , & V_14 -> V_78 ,
V_160 ) )
V_547 |= V_548 | V_549 ;
}
if ( V_14 -> V_194 && F_146 ( V_14 , NULL ) == V_191 )
V_14 -> V_194 = 0 ;
F_70 ( & V_24 -> V_129 . V_79 ) ;
F_69 ( & V_24 -> V_550 . V_79 ) ;
if ( V_14 -> V_75 . V_68 ) {
if ( F_64 ( V_14 , & V_14 -> V_75 , V_169 ) )
V_547 |= V_551 | V_552 ;
}
F_70 ( & V_24 -> V_550 . V_79 ) ;
return V_547 ;
}
static void F_336 ( struct V_553 * V_554 )
{
struct V_545 * V_545 = V_554 -> V_555 ;
struct V_262 * V_23 = V_545 -> V_556 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_121 ( & F_36 ( V_24 ) -> V_557 ) ;
}
static void F_337 ( struct V_553 * V_554 )
{
struct V_545 * V_545 = V_554 -> V_555 ;
struct V_262 * V_23 = V_545 -> V_556 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_110 ( & F_36 ( V_24 ) -> V_557 ) ;
}
static void F_338 ( struct V_104 * V_68 , unsigned int V_558 ,
unsigned int V_173 )
{
int V_199 ;
for ( V_199 = 0 ; V_199 < V_173 ; V_199 ++ ) {
if ( F_22 ( V_68 [ V_199 ] . V_69 ) ) {
if ( F_49 ( V_68 [ V_199 ] . V_69 ) )
F_339 ( V_68 [ V_199 ] . V_69 ) ;
else
F_340 ( ( unsigned long ) V_68 [ V_199 ] . V_69 ,
V_558 ) ;
V_68 [ V_199 ] . V_69 = NULL ;
}
}
F_187 ( V_68 ) ;
}
static char * F_341 ( unsigned long V_558 )
{
char * V_69 ;
T_12 V_559 = V_239 | V_560 |
V_561 | V_562 | V_563 ;
V_69 = ( char * ) F_342 ( V_559 , V_558 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_343 ( ( 1 << V_558 ) * V_139 ) ;
if ( V_69 )
return V_69 ;
V_559 &= ~ V_563 ;
V_69 = ( char * ) F_342 ( V_559 , V_558 ) ;
if ( V_69 )
return V_69 ;
return NULL ;
}
static struct V_104 * F_344 ( struct V_564 * V_486 , int V_558 )
{
unsigned int V_565 = V_486 -> V_113 ;
struct V_104 * V_68 ;
int V_199 ;
V_68 = F_345 ( V_565 , sizeof( struct V_104 ) , V_239 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
for ( V_199 = 0 ; V_199 < V_565 ; V_199 ++ ) {
V_68 [ V_199 ] . V_69 = F_341 ( V_558 ) ;
if ( F_2 ( ! V_68 [ V_199 ] . V_69 ) )
goto V_566;
}
V_130:
return V_68 ;
V_566:
F_338 ( V_68 , V_558 , V_565 ) ;
V_68 = NULL ;
goto V_130;
}
static int F_274 ( struct V_23 * V_24 , union V_99 * V_100 ,
int V_567 , int V_75 )
{
struct V_104 * V_68 = NULL ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_568 , V_558 = 0 ;
struct V_62 * V_63 ;
struct V_76 * V_77 ;
T_8 V_206 ;
int V_92 = - V_237 ;
struct V_564 * V_486 = & V_100 -> V_486 ;
if ( ! V_567 && V_75 && ( V_14 -> V_37 > V_41 ) ) {
F_54 ( 1 , L_8 ) ;
goto V_130;
}
V_63 = V_75 ? & V_14 -> V_75 : & V_14 -> V_78 ;
V_77 = V_75 ? & V_24 -> V_550 : & V_24 -> V_129 ;
V_92 = - V_489 ;
if ( ! V_567 ) {
if ( F_92 ( & V_14 -> V_557 ) )
goto V_130;
if ( F_137 ( V_63 ) )
goto V_130;
}
if ( V_486 -> V_113 ) {
V_92 = - V_489 ;
if ( F_2 ( V_63 -> V_68 ) )
goto V_130;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_115 = V_569 ;
break;
case V_41 :
V_14 -> V_115 = V_570 ;
break;
case V_43 :
V_14 -> V_115 = V_571 ;
break;
}
V_92 = - V_237 ;
if ( F_2 ( ( int ) V_486 -> V_111 <= 0 ) )
goto V_130;
if ( F_2 ( V_486 -> V_111 & ( V_139 - 1 ) ) )
goto V_130;
if ( V_14 -> V_37 >= V_43 &&
( int ) ( V_486 -> V_111 -
F_85 ( V_100 -> V_102 . V_125 ) ) <= 0 )
goto V_130;
if ( F_2 ( V_486 -> V_572 < V_14 -> V_115 +
V_14 -> V_335 ) )
goto V_130;
if ( F_2 ( V_486 -> V_572 & ( V_573 - 1 ) ) )
goto V_130;
V_63 -> V_67 = V_486 -> V_111 / V_486 -> V_572 ;
if ( F_2 ( V_63 -> V_67 <= 0 ) )
goto V_130;
if ( F_2 ( ( V_63 -> V_67 * V_486 -> V_113 ) !=
V_486 -> V_574 ) )
goto V_130;
V_92 = - V_240 ;
V_558 = F_346 ( V_486 -> V_111 ) ;
V_68 = F_344 ( V_486 , V_558 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( ! V_75 )
F_83 ( V_14 , V_63 , V_68 , V_100 ) ;
break;
default:
break;
}
}
else {
V_92 = - V_237 ;
if ( F_2 ( V_486 -> V_574 ) )
goto V_130;
}
F_279 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_568 = V_14 -> V_25 ;
V_206 = V_14 -> V_206 ;
if ( V_568 ) {
V_14 -> V_206 = 0 ;
F_40 ( V_24 , false ) ;
}
F_44 ( & V_14 -> V_29 ) ;
F_45 () ;
V_92 = - V_489 ;
F_179 ( & V_14 -> V_371 ) ;
if ( V_567 || F_92 ( & V_14 -> V_557 ) == 0 ) {
V_92 = 0 ;
F_69 ( & V_77 -> V_79 ) ;
F_347 ( V_63 -> V_68 , V_68 ) ;
V_63 -> V_177 = ( V_486 -> V_574 - 1 ) ;
V_63 -> V_71 = 0 ;
V_63 -> V_70 = V_486 -> V_572 ;
F_70 ( & V_77 -> V_79 ) ;
F_347 ( V_63 -> V_575 , V_558 ) ;
F_347 ( V_63 -> V_576 , V_486 -> V_113 ) ;
V_63 -> V_577 = V_486 -> V_111 / V_139 ;
V_14 -> V_27 . F_72 = ( V_14 -> V_78 . V_68 ) ?
V_185 : F_221 ;
F_149 ( V_77 ) ;
if ( F_92 ( & V_14 -> V_557 ) )
F_152 ( L_9 ,
F_92 ( & V_14 -> V_557 ) ) ;
}
F_186 ( & V_14 -> V_371 ) ;
F_46 ( & V_14 -> V_29 ) ;
if ( V_568 ) {
V_14 -> V_206 = V_206 ;
F_35 ( V_24 ) ;
}
F_44 ( & V_14 -> V_29 ) ;
if ( V_567 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_75 )
F_67 ( V_14 , V_75 , V_77 ) ;
}
F_280 ( V_24 ) ;
if ( V_68 )
F_338 ( V_68 , V_558 , V_486 -> V_113 ) ;
V_130:
return V_92 ;
}
static int F_348 ( struct V_545 * V_545 , struct V_262 * V_23 ,
struct V_553 * V_554 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned long V_578 , V_579 ;
struct V_62 * V_63 ;
unsigned long V_137 ;
int V_92 = - V_237 ;
int V_199 ;
if ( V_554 -> V_580 )
return - V_237 ;
F_179 ( & V_14 -> V_371 ) ;
V_579 = 0 ;
for ( V_63 = & V_14 -> V_78 ; V_63 <= & V_14 -> V_75 ; V_63 ++ ) {
if ( V_63 -> V_68 ) {
V_579 += V_63 -> V_576
* V_63 -> V_577
* V_139 ;
}
}
if ( V_579 == 0 )
goto V_130;
V_578 = V_554 -> V_581 - V_554 -> V_582 ;
if ( V_578 != V_579 )
goto V_130;
V_137 = V_554 -> V_582 ;
for ( V_63 = & V_14 -> V_78 ; V_63 <= & V_14 -> V_75 ; V_63 ++ ) {
if ( V_63 -> V_68 == NULL )
continue;
for ( V_199 = 0 ; V_199 < V_63 -> V_576 ; V_199 ++ ) {
struct V_30 * V_30 ;
void * V_583 = V_63 -> V_68 [ V_199 ] . V_69 ;
int V_584 ;
for ( V_584 = 0 ; V_584 < V_63 -> V_577 ; V_584 ++ ) {
V_30 = F_48 ( V_583 ) ;
V_92 = F_349 ( V_554 , V_137 , V_30 ) ;
if ( F_2 ( V_92 ) )
goto V_130;
V_137 += V_139 ;
V_583 += V_139 ;
}
}
}
F_121 ( & V_14 -> V_557 ) ;
V_554 -> V_585 = & V_586 ;
V_92 = 0 ;
V_130:
F_186 ( & V_14 -> V_371 ) ;
return V_92 ;
}
static void * F_350 ( struct V_587 * V_588 , T_13 * V_589 )
__acquires( T_14 )
{
struct V_223 * V_223 = F_351 ( V_588 ) ;
F_20 () ;
return F_352 ( & V_223 -> V_409 . V_436 , * V_589 ) ;
}
static void * F_353 ( struct V_587 * V_588 , void * V_590 , T_13 * V_589 )
{
struct V_223 * V_223 = F_351 ( V_588 ) ;
return F_354 ( V_590 , & V_223 -> V_409 . V_436 , V_589 ) ;
}
static void F_355 ( struct V_587 * V_588 , void * V_590 )
__releases( T_14 )
{
F_24 () ;
}
static int F_356 ( struct V_587 * V_588 , void * V_590 )
{
if ( V_590 == V_591 )
F_357 ( V_588 , L_10 ) ;
else {
struct V_23 * V_405 = F_358 ( V_590 ) ;
const struct V_13 * V_14 = F_36 ( V_405 ) ;
F_359 ( V_588 ,
L_11 ,
V_405 ,
F_92 ( & V_405 -> V_592 ) ,
V_405 -> V_308 ,
F_117 ( V_14 -> V_206 ) ,
V_14 -> V_94 ,
V_14 -> V_25 ,
F_92 ( & V_405 -> V_188 ) ,
F_360 ( F_361 ( V_588 ) , F_362 ( V_405 ) ) ,
F_363 ( V_405 ) ) ;
}
return 0 ;
}
static int F_364 ( struct V_593 * V_593 , struct V_545 * V_545 )
{
return F_365 ( V_593 , V_545 , & V_594 ,
sizeof( struct V_595 ) ) ;
}
static int T_15 F_366 ( struct V_223 * V_223 )
{
F_289 ( & V_223 -> V_409 . V_410 ) ;
F_367 ( & V_223 -> V_409 . V_436 ) ;
if ( ! F_368 ( L_12 , 0 , V_223 -> V_596 , & V_597 ) )
return - V_240 ;
return 0 ;
}
static void T_16 F_369 ( struct V_223 * V_223 )
{
F_370 ( L_12 , V_223 -> V_596 ) ;
}
static void T_17 F_371 ( void )
{
F_372 ( & V_598 ) ;
F_373 ( & V_599 ) ;
F_374 ( V_429 ) ;
F_375 ( & V_430 ) ;
}
static int T_18 F_376 ( void )
{
int V_600 = F_377 ( & V_430 , 0 ) ;
if ( V_600 != 0 )
goto V_130;
F_378 ( & V_601 ) ;
F_379 ( & V_599 ) ;
F_380 ( & V_598 ) ;
V_130:
return V_600 ;
}
