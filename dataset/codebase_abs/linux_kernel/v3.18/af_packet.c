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
static void F_74 ( struct V_13 * V_14 , int V_75 )
{
struct V_72 * V_73 ;
if ( V_75 )
F_55 () ;
V_73 = V_75 ? F_68 ( & V_14 -> V_75 ) :
F_68 ( & V_14 -> V_78 ) ;
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
union V_99 * V_100 , int V_75 )
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
F_74 ( V_14 , V_75 ) ;
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
F_94 ( V_73 , V_14 , V_132 ) ;
if ( ! F_95 ( V_73 , V_14 ) )
goto V_133;
else
goto V_130;
} else {
if ( F_96 ( V_73 , V_106 ) ) {
goto V_133;
} else {
F_86 ( V_73 , V_106 ) ;
goto V_130;
}
}
}
V_133:
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
V_134 -> V_127 = F_102 ( V_134 ) ;
}
static void F_103 ( struct V_72 * V_73 )
{
V_73 -> V_155 = 0 ;
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
V_39 -> V_156 . V_153 = V_45 . V_57 ;
V_39 -> V_156 . V_154 = V_45 . V_59 ;
V_134 -> V_109 = ( char * ) V_135 ;
V_134 -> V_157 = V_134 -> V_109 + F_85 ( V_134 -> V_124 ) ;
F_106 ( V_135 ) = ( T_4 ) F_85 ( V_134 -> V_124 ) ;
F_107 ( V_135 ) = V_158 ;
V_135 -> V_116 = V_134 -> V_116 ;
V_134 -> V_150 = V_134 -> V_157 ;
V_134 -> V_140 = V_134 -> V_109 + V_134 -> V_110 ;
F_103 ( V_134 ) ;
F_87 ( V_134 ) ;
F_56 () ;
}
static void F_108 ( struct V_72 * V_73 ,
struct V_13 * V_14 )
{
V_73 -> V_155 = 1 ;
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
return ( void * ) V_73 -> V_157 ;
}
static void F_94 ( struct V_72 * V_73 ,
struct V_13 * V_14 , unsigned int V_33 )
{
struct V_105 * V_106 = F_90 ( V_73 ) ;
if ( F_22 ( V_159 == F_99 ( V_106 ) ) ) {
if ( ! ( V_33 & V_132 ) ) {
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
return V_73 -> V_155 ;
}
static void F_109 ( struct V_62 * V_63 )
{
struct V_72 * V_73 = F_68 ( V_63 ) ;
F_110 ( & V_73 -> V_131 ) ;
}
static void F_111 ( struct V_72 * V_73 ,
struct V_143 * V_160 )
{
V_160 -> V_161 . V_162 = F_112 ( V_73 -> V_2 ) ;
}
static void F_113 ( struct V_72 * V_73 ,
struct V_143 * V_160 )
{
V_160 -> V_161 . V_162 = 0 ;
}
static void F_114 ( struct V_72 * V_73 ,
struct V_143 * V_160 )
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
struct V_143 * V_160 )
{
V_160 -> V_161 . V_169 = 0 ;
F_114 ( V_73 , V_160 ) ;
if ( V_73 -> V_101 & V_170 )
F_111 ( V_73 , V_160 ) ;
else
F_113 ( V_73 , V_160 ) ;
}
static void F_119 ( char * V_171 ,
struct V_72 * V_73 ,
struct V_105 * V_106 ,
unsigned int V_172 )
{
struct V_143 * V_160 ;
V_160 = (struct V_143 * ) V_171 ;
V_160 -> V_151 = F_120 ( V_172 ) ;
V_73 -> V_150 = V_171 ;
V_73 -> V_157 += F_120 ( V_172 ) ;
F_105 ( V_106 ) += F_120 ( V_172 ) ;
F_91 ( V_106 ) += 1 ;
F_121 ( & V_73 -> V_131 ) ;
F_118 ( V_73 , V_160 ) ;
}
static void * F_122 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 ,
unsigned int V_172
)
{
struct V_72 * V_73 ;
struct V_105 * V_106 ;
char * V_171 , * V_138 ;
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
V_171 = V_73 -> V_157 ;
V_73 -> V_2 = V_2 ;
V_138 = ( char * ) V_106 + V_73 -> V_110 ;
if ( V_171 + F_120 ( V_172 ) < V_138 ) {
F_119 ( V_171 , V_73 , V_106 , V_172 ) ;
return ( void * ) V_171 ;
}
F_94 ( V_73 , V_14 , 0 ) ;
V_171 = ( char * ) F_95 ( V_73 , V_14 ) ;
if ( V_171 ) {
V_106 = F_90 ( V_73 ) ;
F_119 ( V_171 , V_73 , V_106 , V_172 ) ;
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
V_171 = F_63 ( V_14 , & V_14 -> V_78 ,
V_14 -> V_78 . V_71 , V_33 ) ;
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
struct V_105 * V_106 = F_126 ( V_73 , V_173 ) ;
if ( V_33 != F_99 ( V_106 ) )
return NULL ;
return V_106 ;
}
static int F_127 ( struct V_62 * V_63 )
{
unsigned int V_150 ;
if ( V_63 -> V_174 . V_127 )
V_150 = V_63 -> V_174 . V_127 - 1 ;
else
V_150 = V_63 -> V_174 . V_112 - 1 ;
return V_150 ;
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
V_14 -> V_78 . V_178 = NULL ;
V_14 -> V_75 . V_178 = F_141 (unsigned int) ;
if ( F_2 ( V_14 -> V_75 . V_178 == NULL ) )
return - V_181 ;
return 0 ;
}
static void F_142 ( struct V_13 * V_14 )
{
F_143 ( V_14 -> V_75 . V_178 ) ;
}
static bool F_144 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_14 -> V_24 ;
bool V_182 ;
if ( V_14 -> V_27 . F_72 != V_183 )
return ( F_92 ( & V_24 -> V_184 ) + V_2 -> V_185 )
<= V_24 -> V_186 ;
F_46 ( & V_24 -> V_129 . V_79 ) ;
if ( V_14 -> V_37 == V_43 )
V_182 = F_125 ( V_14 , & V_14 -> V_78 ,
V_14 -> V_78 . V_174 . V_127 ,
V_159 ) ;
else
V_182 = F_63 ( V_14 , & V_14 -> V_78 ,
V_14 -> V_78 . V_71 ,
V_159 ) ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
return V_182 ;
}
static void F_145 ( struct V_23 * V_24 )
{
F_146 ( & V_24 -> V_187 ) ;
F_147 ( F_92 ( & V_24 -> V_184 ) ) ;
F_147 ( F_92 ( & V_24 -> V_188 ) ) ;
if ( ! F_148 ( V_24 , V_189 ) ) {
F_149 ( L_3 , V_24 ) ;
return;
}
F_150 ( V_24 ) ;
}
static int F_151 ( struct V_190 * V_191 , unsigned int V_192 )
{
int V_193 = F_92 ( & V_191 -> V_194 ) + 1 ;
if ( V_193 >= V_192 )
V_193 = 0 ;
return V_193 ;
}
static unsigned int F_152 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
return F_153 ( F_112 ( V_2 ) , V_192 ) ;
}
static unsigned int F_154 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
int V_195 , V_196 ;
V_195 = F_92 ( & V_191 -> V_194 ) ;
while ( ( V_196 = F_155 ( & V_191 -> V_194 , V_195 ,
F_151 ( V_191 , V_192 ) ) ) != V_195 )
V_195 = V_196 ;
return V_195 ;
}
static unsigned int F_156 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
return F_11 () % V_192 ;
}
static unsigned int F_157 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
return F_158 ( V_192 ) ;
}
static unsigned int F_159 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_173 , unsigned int V_197 ,
unsigned int V_192 )
{
unsigned int V_198 , V_199 ;
V_198 = V_199 = F_160 ( int , V_191 -> V_200 [ V_173 ] , V_192 - 1 ) ;
do {
if ( V_198 != V_197 && F_144 ( F_36 ( V_191 -> V_201 [ V_198 ] ) , V_2 ) ) {
if ( V_198 != V_199 )
V_191 -> V_200 [ V_173 ] = V_198 ;
return V_198 ;
}
if ( ++ V_198 == V_192 )
V_198 = 0 ;
} while ( V_198 != V_199 );
return V_173 ;
}
static unsigned int F_161 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
return F_162 ( V_2 ) % V_192 ;
}
static bool F_163 ( struct V_190 * V_191 , T_2 V_202 )
{
return V_191 -> V_46 & ( V_202 >> 8 ) ;
}
static int F_164 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_203 * V_204 , struct V_3 * V_205 )
{
struct V_190 * V_191 = V_204 -> V_206 ;
unsigned int V_192 = V_191 -> V_207 ;
struct V_13 * V_14 ;
unsigned int V_173 ;
if ( ! F_165 ( F_166 ( V_4 ) , F_167 ( & V_191 -> V_208 ) ) ||
! V_192 ) {
F_17 ( V_2 ) ;
return 0 ;
}
switch ( V_191 -> type ) {
case V_209 :
default:
if ( F_163 ( V_191 , V_210 ) ) {
V_2 = F_168 ( V_2 , V_211 ) ;
if ( ! V_2 )
return 0 ;
}
V_173 = F_152 ( V_191 , V_2 , V_192 ) ;
break;
case V_212 :
V_173 = F_154 ( V_191 , V_2 , V_192 ) ;
break;
case V_213 :
V_173 = F_156 ( V_191 , V_2 , V_192 ) ;
break;
case V_214 :
V_173 = F_157 ( V_191 , V_2 , V_192 ) ;
break;
case V_215 :
V_173 = F_161 ( V_191 , V_2 , V_192 ) ;
break;
case V_216 :
V_173 = F_159 ( V_191 , V_2 , 0 , ( unsigned int ) - 1 , V_192 ) ;
break;
}
V_14 = F_36 ( V_191 -> V_201 [ V_173 ] ) ;
if ( F_163 ( V_191 , V_217 ) &&
F_2 ( ! F_144 ( V_14 , V_2 ) ) ) {
V_173 = F_159 ( V_191 , V_2 , V_173 , V_173 , V_192 ) ;
V_14 = F_36 ( V_191 -> V_201 [ V_173 ] ) ;
}
return V_14 -> V_27 . F_72 ( V_2 , V_4 , & V_14 -> V_27 , V_205 ) ;
}
static void F_37 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_190 * V_191 = V_14 -> V_26 ;
F_46 ( & V_191 -> V_79 ) ;
V_191 -> V_201 [ V_191 -> V_207 ] = V_24 ;
F_56 () ;
V_191 -> V_207 ++ ;
F_44 ( & V_191 -> V_79 ) ;
}
static void F_41 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_190 * V_191 = V_14 -> V_26 ;
int V_198 ;
F_46 ( & V_191 -> V_79 ) ;
for ( V_198 = 0 ; V_198 < V_191 -> V_207 ; V_198 ++ ) {
if ( V_191 -> V_201 [ V_198 ] == V_24 )
break;
}
F_169 ( V_198 >= V_191 -> V_207 ) ;
V_191 -> V_201 [ V_198 ] = V_191 -> V_201 [ V_191 -> V_207 - 1 ] ;
V_191 -> V_207 -- ;
F_44 ( & V_191 -> V_79 ) ;
}
static bool F_170 ( struct V_203 * V_218 , struct V_23 * V_24 )
{
if ( V_218 -> V_206 == ( void * ) ( (struct V_13 * ) V_24 ) -> V_26 )
return true ;
return false ;
}
static int F_171 ( struct V_23 * V_24 , T_2 V_219 , T_2 V_220 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_190 * V_191 , * V_221 ;
T_6 type = V_220 & 0xff ;
T_6 V_46 = V_220 >> 8 ;
int V_92 ;
switch ( type ) {
case V_216 :
if ( V_220 & V_217 )
return - V_222 ;
case V_209 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
break;
default:
return - V_222 ;
}
if ( ! V_14 -> V_25 )
return - V_222 ;
if ( V_14 -> V_26 )
return - V_223 ;
F_172 ( & V_224 ) ;
V_221 = NULL ;
F_173 (f, &fanout_list, list) {
if ( V_191 -> V_219 == V_219 &&
F_167 ( & V_191 -> V_208 ) == F_78 ( V_24 ) ) {
V_221 = V_191 ;
break;
}
}
V_92 = - V_222 ;
if ( V_221 && V_221 -> V_46 != V_46 )
goto V_130;
if ( ! V_221 ) {
V_92 = - V_225 ;
V_221 = F_174 ( sizeof( * V_221 ) , V_226 ) ;
if ( ! V_221 )
goto V_130;
F_175 ( & V_221 -> V_208 , F_78 ( V_24 ) ) ;
V_221 -> V_219 = V_219 ;
V_221 -> type = type ;
V_221 -> V_46 = V_46 ;
F_176 ( & V_221 -> V_194 , 0 ) ;
F_177 ( & V_221 -> V_227 ) ;
F_178 ( & V_221 -> V_79 ) ;
F_176 ( & V_221 -> V_228 , 0 ) ;
V_221 -> V_27 . type = V_14 -> V_27 . type ;
V_221 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_221 -> V_27 . F_72 = F_164 ;
V_221 -> V_27 . V_206 = V_221 ;
V_221 -> V_27 . V_229 = F_170 ;
F_38 ( & V_221 -> V_27 ) ;
F_179 ( & V_221 -> V_227 , & V_230 ) ;
}
V_92 = - V_222 ;
if ( V_221 -> type == type &&
V_221 -> V_27 . type == V_14 -> V_27 . type &&
V_221 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_92 = - V_231 ;
if ( F_92 ( & V_221 -> V_228 ) < V_232 ) {
F_42 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_221 ;
F_121 ( & V_221 -> V_228 ) ;
F_37 ( V_24 , V_14 ) ;
V_92 = 0 ;
}
}
V_130:
F_180 ( & V_224 ) ;
return V_92 ;
}
static void F_181 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_190 * V_191 ;
V_191 = V_14 -> V_26 ;
if ( ! V_191 )
return;
F_172 ( & V_224 ) ;
V_14 -> V_26 = NULL ;
if ( F_182 ( & V_191 -> V_228 ) ) {
F_183 ( & V_191 -> V_227 ) ;
F_184 ( & V_191 -> V_27 ) ;
F_185 ( V_191 ) ;
}
F_180 ( & V_224 ) ;
}
static int F_186 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_203 * V_204 , struct V_3 * V_205 )
{
struct V_23 * V_24 ;
struct V_233 * V_234 ;
V_24 = V_204 -> V_206 ;
if ( V_2 -> V_235 == V_236 )
goto V_130;
if ( ! F_165 ( F_166 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_130;
V_2 = F_187 ( V_2 , V_237 ) ;
if ( V_2 == NULL )
goto V_238;
F_188 ( V_2 ) ;
F_189 ( V_2 ) ;
V_234 = & F_190 ( V_2 ) -> V_239 . V_240 ;
F_191 ( V_2 , V_2 -> V_81 - F_192 ( V_2 ) ) ;
V_234 -> V_241 = V_4 -> type ;
F_193 ( V_234 -> V_242 , V_4 -> V_243 , sizeof( V_234 -> V_242 ) ) ;
V_234 -> V_244 = V_2 -> V_245 ;
if ( F_194 ( V_24 , V_2 ) == 0 )
return 0 ;
V_130:
F_17 ( V_2 ) ;
V_238:
return 0 ;
}
static int F_195 ( struct V_246 * V_247 , struct V_248 * V_23 ,
struct V_249 * V_250 , T_7 V_172 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_196 ( struct V_233 * , V_251 , V_250 -> V_252 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
T_8 V_253 = 0 ;
int V_92 ;
int V_254 = 0 ;
if ( V_251 ) {
if ( V_250 -> V_255 < sizeof( struct V_256 ) )
return - V_222 ;
if ( V_250 -> V_255 == sizeof( struct V_233 ) )
V_253 = V_251 -> V_244 ;
} else
return - V_257 ;
V_251 -> V_242 [ sizeof( V_251 -> V_242 ) - 1 ] = 0 ;
V_258:
F_20 () ;
V_4 = F_197 ( F_78 ( V_24 ) , V_251 -> V_242 ) ;
V_92 = - V_259 ;
if ( V_4 == NULL )
goto V_260;
V_92 = - V_261 ;
if ( ! ( V_4 -> V_46 & V_262 ) )
goto V_260;
if ( F_2 ( F_148 ( V_24 , V_263 ) ) ) {
if ( ! F_198 ( V_4 ) ) {
V_92 = - V_264 ;
goto V_260;
}
V_254 = 4 ;
}
V_92 = - V_265 ;
if ( V_172 > V_4 -> V_266 + V_4 -> V_267 + V_268 + V_254 )
goto V_260;
if ( ! V_2 ) {
T_7 V_269 = F_199 ( V_4 ) ;
int V_270 = V_4 -> V_271 ;
unsigned int V_272 = V_4 -> V_273 ? V_4 -> V_267 : 0 ;
F_24 () ;
V_2 = F_200 ( V_24 , V_172 + V_269 + V_270 , 0 , V_226 ) ;
if ( V_2 == NULL )
return - V_181 ;
F_201 ( V_2 , V_269 ) ;
F_202 ( V_2 ) ;
if ( V_272 ) {
V_2 -> V_81 -= V_272 ;
V_2 -> V_274 -= V_272 ;
if ( V_172 < V_272 )
F_202 ( V_2 ) ;
}
V_92 = F_203 ( F_204 ( V_2 , V_172 ) , V_250 -> V_275 , V_172 ) ;
if ( V_92 )
goto V_276;
goto V_258;
}
if ( V_172 > ( V_4 -> V_266 + V_4 -> V_267 + V_254 ) ) {
struct V_277 * V_278 ;
F_205 ( V_2 ) ;
V_278 = F_206 ( V_2 ) ;
if ( V_278 -> V_279 != F_207 ( V_280 ) ) {
V_92 = - V_265 ;
goto V_260;
}
}
V_2 -> V_245 = V_253 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_281 = V_24 -> V_282 ;
V_2 -> V_283 = V_24 -> V_284 ;
F_208 ( V_24 , & F_209 ( V_2 ) -> V_285 ) ;
if ( F_2 ( V_254 == 4 ) )
V_2 -> V_286 = 1 ;
F_210 ( V_2 , 0 ) ;
F_211 ( V_2 ) ;
F_24 () ;
return V_172 ;
V_260:
F_24 () ;
V_276:
F_17 ( V_2 ) ;
return V_92 ;
}
static unsigned int F_212 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_287 )
{
struct V_288 * V_289 ;
F_20 () ;
V_289 = F_21 ( V_24 -> V_288 ) ;
if ( V_289 != NULL )
V_287 = F_213 ( V_289 , V_2 ) ;
F_24 () ;
return V_287 ;
}
static int F_214 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_203 * V_204 , struct V_3 * V_205 )
{
struct V_23 * V_24 ;
struct V_290 * V_291 ;
struct V_13 * V_14 ;
T_6 * V_292 = V_2 -> V_81 ;
int V_293 = V_2 -> V_172 ;
unsigned int V_294 , V_287 ;
if ( V_2 -> V_235 == V_236 )
goto V_10;
V_24 = V_204 -> V_206 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_165 ( F_166 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_273 ) {
if ( V_24 -> V_295 != V_296 )
F_191 ( V_2 , V_2 -> V_81 - F_192 ( V_2 ) ) ;
else if ( V_2 -> V_235 == V_297 ) {
F_215 ( V_2 , F_216 ( V_2 ) ) ;
}
}
V_294 = V_2 -> V_172 ;
V_287 = F_212 ( V_2 , V_24 , V_294 ) ;
if ( ! V_287 )
goto V_298;
if ( V_294 > V_287 )
V_294 = V_287 ;
if ( F_92 ( & V_24 -> V_184 ) >= V_24 -> V_186 )
goto V_299;
if ( F_217 ( V_2 ) ) {
struct V_1 * V_300 = F_218 ( V_2 , V_237 ) ;
if ( V_300 == NULL )
goto V_299;
if ( V_292 != V_2 -> V_81 ) {
V_2 -> V_81 = V_292 ;
V_2 -> V_172 = V_293 ;
}
F_219 ( V_2 ) ;
V_2 = V_300 ;
}
F_220 ( sizeof( * F_190 ( V_2 ) ) + V_301 - 8 >
sizeof( V_2 -> V_302 ) ) ;
V_291 = & F_190 ( V_2 ) -> V_239 . V_303 ;
V_291 -> V_304 = V_305 ;
V_291 -> V_306 = V_4 -> type ;
V_291 -> V_307 = V_2 -> V_245 ;
V_291 -> V_308 = V_2 -> V_235 ;
if ( F_2 ( V_14 -> V_309 ) )
V_291 -> V_310 = V_205 -> V_94 ;
else
V_291 -> V_310 = V_4 -> V_94 ;
V_291 -> V_311 = F_221 ( V_2 , V_291 -> V_312 ) ;
F_190 ( V_2 ) -> V_313 = V_2 -> V_172 ;
if ( F_222 ( V_2 , V_294 ) )
goto V_299;
F_223 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_188 ( V_2 ) ;
F_189 ( V_2 ) ;
F_46 ( & V_24 -> V_129 . V_79 ) ;
V_14 -> V_118 . V_314 . V_315 ++ ;
V_2 -> V_316 = F_92 ( & V_24 -> V_317 ) ;
F_224 ( & V_24 -> V_129 , V_2 ) ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
V_24 -> V_318 ( V_24 ) ;
return 0 ;
V_299:
F_46 ( & V_24 -> V_129 . V_79 ) ;
V_14 -> V_118 . V_314 . V_148 ++ ;
F_121 ( & V_24 -> V_317 ) ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
V_298:
if ( V_292 != V_2 -> V_81 && F_217 ( V_2 ) ) {
V_2 -> V_81 = V_292 ;
V_2 -> V_172 = V_293 ;
}
V_10:
F_219 ( V_2 ) ;
return 0 ;
}
static int V_183 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_203 * V_204 , struct V_3 * V_205 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
struct V_290 * V_291 ;
union V_34 V_35 ;
T_6 * V_292 = V_2 -> V_81 ;
int V_293 = V_2 -> V_172 ;
unsigned int V_294 , V_287 ;
unsigned long V_33 = V_142 ;
unsigned short V_319 , V_320 , V_114 ;
struct V_1 * V_321 = NULL ;
struct V_44 V_45 ;
T_4 V_54 ;
F_220 ( F_225 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_220 ( F_225 ( sizeof( * V_35 . V_322 ) ) != 48 ) ;
if ( V_2 -> V_235 == V_236 )
goto V_10;
V_24 = V_204 -> V_206 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_165 ( F_166 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_273 ) {
if ( V_24 -> V_295 != V_296 )
F_191 ( V_2 , V_2 -> V_81 - F_192 ( V_2 ) ) ;
else if ( V_2 -> V_235 == V_297 ) {
F_215 ( V_2 , F_216 ( V_2 ) ) ;
}
}
if ( V_2 -> V_323 == V_324 )
V_33 |= V_325 ;
V_294 = V_2 -> V_172 ;
V_287 = F_212 ( V_2 , V_24 , V_294 ) ;
if ( ! V_287 )
goto V_298;
if ( V_294 > V_287 )
V_294 = V_287 ;
if ( V_24 -> V_295 == V_296 ) {
V_319 = V_320 = F_225 ( V_14 -> V_115 ) + 16 +
V_14 -> V_326 ;
} else {
unsigned int V_327 = F_216 ( V_2 ) ;
V_320 = F_225 ( V_14 -> V_115 +
( V_327 < 16 ? 16 : V_327 ) ) +
V_14 -> V_326 ;
V_319 = V_320 - V_327 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_319 + V_294 > V_14 -> V_78 . V_70 ) {
if ( V_14 -> V_328 &&
F_92 ( & V_24 -> V_184 ) < V_24 -> V_186 ) {
if ( F_217 ( V_2 ) ) {
V_321 = F_218 ( V_2 , V_237 ) ;
} else {
V_321 = F_226 ( V_2 ) ;
V_292 = V_2 -> V_81 ;
}
if ( V_321 )
F_223 ( V_321 , V_24 ) ;
}
V_294 = V_14 -> V_78 . V_70 - V_319 ;
if ( ( int ) V_294 < 0 )
V_294 = 0 ;
}
} else if ( F_2 ( V_319 + V_294 >
F_68 ( & V_14 -> V_78 ) -> V_126 ) ) {
T_5 V_329 ;
V_329 = F_68 ( & V_14 -> V_78 ) -> V_126 - V_319 ;
F_227 ( L_4 ,
V_294 , V_329 , V_319 ) ;
V_294 = V_329 ;
if ( F_2 ( ( int ) V_294 < 0 ) ) {
V_294 = 0 ;
V_319 = F_68 ( & V_14 -> V_78 ) -> V_126 ;
}
}
F_46 ( & V_24 -> V_129 . V_79 ) ;
V_35 . V_36 = F_124 ( V_14 , V_2 ,
V_159 , ( V_319 + V_294 ) ) ;
if ( ! V_35 . V_36 )
goto V_330;
if ( V_14 -> V_37 <= V_41 ) {
F_131 ( V_14 , & V_14 -> V_78 ) ;
if ( V_14 -> V_118 . V_314 . V_148 )
V_33 |= V_149 ;
}
V_14 -> V_118 . V_314 . V_315 ++ ;
if ( V_321 ) {
V_33 |= V_331 ;
F_224 ( & V_24 -> V_129 , V_321 ) ;
}
F_44 ( & V_24 -> V_129 . V_79 ) ;
F_228 ( V_2 , 0 , V_35 . V_36 + V_319 , V_294 ) ;
if ( ! ( V_54 = F_59 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
F_101 ( & V_45 ) ;
V_33 |= V_54 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_332 = V_2 -> V_172 ;
V_35 . V_39 -> V_333 = V_294 ;
V_35 . V_39 -> V_334 = V_319 ;
V_35 . V_39 -> V_335 = V_320 ;
V_35 . V_39 -> V_56 = V_45 . V_57 ;
V_35 . V_39 -> V_58 = V_45 . V_59 / V_60 ;
V_114 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_332 = V_2 -> V_172 ;
V_35 . V_42 -> V_333 = V_294 ;
V_35 . V_42 -> V_334 = V_319 ;
V_35 . V_42 -> V_335 = V_320 ;
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
V_114 = sizeof( * V_35 . V_42 ) ;
break;
case V_43 :
V_35 . V_322 -> V_40 |= V_33 ;
V_35 . V_322 -> V_332 = V_2 -> V_172 ;
V_35 . V_322 -> V_333 = V_294 ;
V_35 . V_322 -> V_334 = V_319 ;
V_35 . V_322 -> V_335 = V_320 ;
V_35 . V_322 -> V_56 = V_45 . V_57 ;
V_35 . V_322 -> V_61 = V_45 . V_59 ;
memset ( V_35 . V_322 -> V_169 , 0 , sizeof( V_35 . V_322 -> V_169 ) ) ;
V_114 = sizeof( * V_35 . V_322 ) ;
break;
default:
F_55 () ;
}
V_291 = V_35 . V_36 + F_225 ( V_114 ) ;
V_291 -> V_311 = F_221 ( V_2 , V_291 -> V_312 ) ;
V_291 -> V_304 = V_305 ;
V_291 -> V_306 = V_4 -> type ;
V_291 -> V_307 = V_2 -> V_245 ;
V_291 -> V_308 = V_2 -> V_235 ;
if ( F_2 ( V_14 -> V_309 ) )
V_291 -> V_310 = V_205 -> V_94 ;
else
V_291 -> V_310 = V_4 -> V_94 ;
F_123 () ;
#if V_136 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_6 * V_137 , * V_138 ;
V_138 = ( T_6 * ) F_98 ( ( unsigned long ) V_35 . V_36 +
V_319 + V_294 ) ;
for ( V_137 = V_35 . V_36 ; V_137 < V_138 ; V_137 += V_139 )
F_53 ( F_48 ( V_137 ) ) ;
}
F_56 () ;
#endif
if ( V_14 -> V_37 <= V_41 )
F_52 ( V_14 , V_35 . V_36 , V_33 ) ;
else
F_109 ( & V_14 -> V_78 ) ;
V_24 -> V_318 ( V_24 ) ;
V_298:
if ( V_292 != V_2 -> V_81 && F_217 ( V_2 ) ) {
V_2 -> V_81 = V_292 ;
V_2 -> V_172 = V_293 ;
}
V_10:
F_17 ( V_2 ) ;
return 0 ;
V_330:
V_14 -> V_118 . V_314 . V_148 ++ ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
V_24 -> V_318 ( V_24 ) ;
F_17 ( V_321 ) ;
goto V_298;
}
static void F_229 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_36 ( V_2 -> V_24 ) ;
if ( F_22 ( V_14 -> V_75 . V_68 ) ) {
void * V_336 ;
T_4 V_45 ;
V_336 = F_209 ( V_2 ) -> V_337 ;
F_135 ( & V_14 -> V_75 ) ;
V_45 = F_62 ( V_14 , V_336 , V_2 ) ;
F_52 ( V_14 , V_336 , V_168 | V_45 ) ;
}
F_230 ( V_2 ) ;
}
static int F_231 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , int V_338 ,
T_8 V_253 , unsigned char * V_31 , int V_339 )
{
union V_34 V_336 ;
int V_340 , V_341 , V_172 , V_332 , V_342 , V_343 ;
struct V_248 * V_23 = V_14 -> V_24 . V_344 ;
struct V_30 * V_30 ;
void * V_81 ;
int V_92 ;
V_336 . V_36 = V_32 ;
V_2 -> V_245 = V_253 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_281 = V_14 -> V_24 . V_282 ;
V_2 -> V_283 = V_14 -> V_24 . V_284 ;
F_208 ( & V_14 -> V_24 , & F_209 ( V_2 ) -> V_285 ) ;
F_209 ( V_2 ) -> V_337 = V_336 . V_36 ;
switch ( V_14 -> V_37 ) {
case V_41 :
V_332 = V_336 . V_42 -> V_332 ;
break;
default:
V_332 = V_336 . V_39 -> V_332 ;
break;
}
if ( F_2 ( V_332 > V_338 ) ) {
F_149 ( L_5 , V_332 , V_338 ) ;
return - V_265 ;
}
F_201 ( V_2 , V_339 ) ;
F_202 ( V_2 ) ;
if ( ! F_29 ( V_14 ) )
F_210 ( V_2 , 0 ) ;
if ( F_2 ( V_14 -> V_345 ) ) {
int V_346 , V_347 , V_348 ;
V_346 = V_14 -> V_115 - sizeof( struct V_290 ) ;
V_347 = V_14 -> V_75 . V_70 - V_332 ;
if ( V_23 -> type == V_296 ) {
switch ( V_14 -> V_37 ) {
case V_41 :
V_348 = V_336 . V_42 -> V_335 ;
break;
default:
V_348 = V_336 . V_39 -> V_335 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_41 :
V_348 = V_336 . V_42 -> V_334 ;
break;
default:
V_348 = V_336 . V_39 -> V_334 ;
break;
}
}
if ( F_2 ( ( V_348 < V_346 ) || ( V_347 < V_348 ) ) )
return - V_222 ;
V_81 = V_336 . V_36 + V_348 ;
} else {
V_81 = V_336 . V_36 + V_14 -> V_115 - sizeof( struct V_290 ) ;
}
V_340 = V_332 ;
if ( V_23 -> type == V_296 ) {
V_92 = F_232 ( V_2 , V_4 , F_117 ( V_253 ) , V_31 ,
NULL , V_332 ) ;
if ( F_2 ( V_92 < 0 ) )
return - V_222 ;
} else if ( V_4 -> V_267 ) {
if ( F_2 ( V_332 <= V_4 -> V_267 ) ) {
F_149 ( L_6 ,
V_332 , V_4 -> V_267 ) ;
return - V_222 ;
}
F_191 ( V_2 , V_4 -> V_267 ) ;
V_92 = F_233 ( V_2 , 0 , V_81 ,
V_4 -> V_267 ) ;
if ( F_2 ( V_92 ) )
return V_92 ;
V_81 += V_4 -> V_267 ;
V_340 -= V_4 -> V_267 ;
}
V_341 = F_234 ( V_81 ) ;
V_343 = V_139 - V_341 ;
V_172 = ( ( V_340 > V_343 ) ? V_343 : V_340 ) ;
V_2 -> V_349 = V_340 ;
V_2 -> V_172 += V_340 ;
V_2 -> V_185 += V_340 ;
F_235 ( V_340 , & V_14 -> V_24 . V_188 ) ;
while ( F_22 ( V_340 ) ) {
V_342 = F_209 ( V_2 ) -> V_342 ;
if ( F_2 ( V_342 >= V_350 ) ) {
F_149 ( L_7 ,
V_350 ) ;
return - V_351 ;
}
V_30 = F_48 ( V_81 ) ;
V_81 += V_172 ;
F_53 ( V_30 ) ;
F_236 ( V_30 ) ;
F_237 ( V_2 , V_342 , V_30 , V_341 , V_172 ) ;
V_340 -= V_172 ;
V_341 = 0 ;
V_343 = V_139 ;
V_172 = ( ( V_340 > V_343 ) ? V_343 : V_340 ) ;
}
return V_332 ;
}
static int F_238 ( struct V_13 * V_14 , struct V_249 * V_250 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_253 ;
int V_92 , V_352 = 0 ;
void * V_336 ;
F_196 ( struct V_290 * , V_251 , V_250 -> V_252 ) ;
bool V_353 = ! ( V_250 -> V_354 & V_355 ) ;
int V_332 , V_338 ;
unsigned char * V_31 ;
int V_356 = 0 ;
int V_33 = V_168 ;
int V_339 , V_270 ;
F_172 ( & V_14 -> V_357 ) ;
if ( F_22 ( V_251 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_253 = V_14 -> V_192 ;
V_31 = NULL ;
} else {
V_92 = - V_222 ;
if ( V_250 -> V_255 < sizeof( struct V_290 ) )
goto V_130;
if ( V_250 -> V_255 < ( V_251 -> V_311
+ F_239 ( struct V_290 ,
V_312 ) ) )
goto V_130;
V_253 = V_251 -> V_307 ;
V_31 = V_251 -> V_312 ;
V_4 = F_240 ( F_78 ( & V_14 -> V_24 ) , V_251 -> V_310 ) ;
}
V_92 = - V_358 ;
if ( F_2 ( V_4 == NULL ) )
goto V_130;
V_92 = - V_261 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_262 ) ) )
goto V_359;
V_352 = V_4 -> V_267 + V_268 ;
V_338 = V_14 -> V_75 . V_70
- ( V_14 -> V_115 - sizeof( struct V_290 ) ) ;
if ( V_338 > V_4 -> V_266 + V_352 )
V_338 = V_4 -> V_266 + V_352 ;
do {
V_336 = F_64 ( V_14 , & V_14 -> V_75 ,
V_360 ) ;
if ( F_2 ( V_336 == NULL ) ) {
if ( V_353 && F_241 () )
F_242 () ;
continue;
}
V_33 = V_360 ;
V_339 = F_199 ( V_4 ) ;
V_270 = V_4 -> V_271 ;
V_2 = F_243 ( & V_14 -> V_24 ,
V_339 + V_270 + sizeof( struct V_290 ) ,
0 , & V_92 ) ;
if ( F_2 ( V_2 == NULL ) )
goto V_361;
V_332 = F_231 ( V_14 , V_2 , V_336 , V_4 , V_338 , V_253 ,
V_31 , V_339 ) ;
if ( V_332 > V_4 -> V_266 + V_4 -> V_267 ) {
struct V_277 * V_278 ;
F_205 ( V_2 ) ;
V_278 = F_206 ( V_2 ) ;
if ( V_278 -> V_279 != F_207 ( V_280 ) )
V_332 = - V_265 ;
}
if ( F_2 ( V_332 < 0 ) ) {
if ( V_14 -> V_362 ) {
F_52 ( V_14 , V_336 ,
V_168 ) ;
F_132 ( & V_14 -> V_75 ) ;
F_17 ( V_2 ) ;
continue;
} else {
V_33 = V_363 ;
V_92 = V_332 ;
goto V_361;
}
}
F_32 ( V_4 , V_2 ) ;
V_2 -> V_364 = F_229 ;
F_52 ( V_14 , V_336 , V_365 ) ;
F_133 ( & V_14 -> V_75 ) ;
V_33 = V_360 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_92 > 0 ) ) {
V_92 = F_244 ( V_92 ) ;
if ( V_92 && F_57 ( V_14 , V_336 ) ==
V_168 ) {
V_2 = NULL ;
goto V_361;
}
V_92 = 0 ;
}
F_132 ( & V_14 -> V_75 ) ;
V_356 += V_332 ;
} while ( F_22 ( ( V_336 != NULL ) ||
( V_353 && F_137 ( & V_14 -> V_75 ) ) ) );
V_92 = V_356 ;
goto V_359;
V_361:
F_52 ( V_14 , V_336 , V_33 ) ;
F_17 ( V_2 ) ;
V_359:
F_245 ( V_4 ) ;
V_130:
F_180 ( & V_14 -> V_357 ) ;
return V_92 ;
}
static struct V_1 * F_246 ( struct V_23 * V_24 , T_7 V_366 ,
T_7 V_352 , T_7 V_172 ,
T_7 V_367 , int V_368 ,
int * V_92 )
{
struct V_1 * V_2 ;
if ( V_366 + V_172 < V_139 || ! V_367 )
V_367 = V_172 ;
V_2 = F_247 ( V_24 , V_366 + V_367 , V_172 - V_367 , V_368 ,
V_92 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_201 ( V_2 , V_352 ) ;
F_204 ( V_2 , V_367 ) ;
V_2 -> V_349 = V_172 - V_367 ;
V_2 -> V_172 += V_172 - V_367 ;
return V_2 ;
}
static int F_248 ( struct V_248 * V_23 , struct V_249 * V_250 , T_7 V_172 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_196 ( struct V_290 * , V_251 , V_250 -> V_252 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_253 ;
unsigned char * V_31 ;
int V_92 , V_352 = 0 ;
struct V_369 V_370 = { 0 } ;
int V_341 = 0 ;
int V_371 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned short V_372 = 0 ;
int V_339 , V_270 ;
int V_254 = 0 ;
if ( F_22 ( V_251 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_253 = V_14 -> V_192 ;
V_31 = NULL ;
} else {
V_92 = - V_222 ;
if ( V_250 -> V_255 < sizeof( struct V_290 ) )
goto V_130;
if ( V_250 -> V_255 < ( V_251 -> V_311 + F_239 ( struct V_290 , V_312 ) ) )
goto V_130;
V_253 = V_251 -> V_307 ;
V_31 = V_251 -> V_312 ;
V_4 = F_240 ( F_78 ( V_24 ) , V_251 -> V_310 ) ;
}
V_92 = - V_358 ;
if ( F_2 ( V_4 == NULL ) )
goto V_260;
V_92 = - V_261 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_262 ) ) )
goto V_260;
if ( V_23 -> type == V_373 )
V_352 = V_4 -> V_267 ;
if ( V_14 -> V_374 ) {
V_371 = sizeof( V_370 ) ;
V_92 = - V_222 ;
if ( V_172 < V_371 )
goto V_260;
V_172 -= V_371 ;
V_92 = F_203 ( ( void * ) & V_370 , V_250 -> V_275 ,
V_371 ) ;
if ( V_92 < 0 )
goto V_260;
if ( ( V_370 . V_46 & V_375 ) &&
( V_370 . V_376 + V_370 . V_377 + 2 >
V_370 . V_378 ) )
V_370 . V_378 = V_370 . V_376 +
V_370 . V_377 + 2 ;
V_92 = - V_222 ;
if ( V_370 . V_378 > V_172 )
goto V_260;
if ( V_370 . V_372 != V_379 ) {
switch ( V_370 . V_372 & ~ V_380 ) {
case V_381 :
V_372 = V_382 ;
break;
case V_383 :
V_372 = V_384 ;
break;
case V_385 :
V_372 = V_386 ;
break;
default:
goto V_260;
}
if ( V_370 . V_372 & V_380 )
V_372 |= V_387 ;
if ( V_370 . V_388 == 0 )
goto V_260;
}
}
if ( F_2 ( F_148 ( V_24 , V_263 ) ) ) {
if ( ! F_198 ( V_4 ) ) {
V_92 = - V_264 ;
goto V_260;
}
V_254 = 4 ;
}
V_92 = - V_265 ;
if ( ! V_372 && ( V_172 > V_4 -> V_266 + V_352 + V_268 + V_254 ) )
goto V_260;
V_92 = - V_181 ;
V_339 = F_199 ( V_4 ) ;
V_270 = V_4 -> V_271 ;
V_2 = F_246 ( V_24 , V_339 + V_270 , V_339 , V_172 , V_370 . V_378 ,
V_250 -> V_354 & V_355 , & V_92 ) ;
if ( V_2 == NULL )
goto V_260;
F_249 ( V_2 , V_352 ) ;
V_92 = - V_222 ;
if ( V_23 -> type == V_296 &&
( V_341 = F_232 ( V_2 , V_4 , F_117 ( V_253 ) , V_31 , NULL , V_172 ) ) < 0 )
goto V_276;
V_92 = F_250 ( V_2 , V_341 , V_250 -> V_275 , 0 , V_172 ) ;
if ( V_92 )
goto V_276;
F_208 ( V_24 , & F_209 ( V_2 ) -> V_285 ) ;
if ( ! V_372 && ( V_172 > V_4 -> V_266 + V_352 + V_254 ) ) {
struct V_277 * V_278 ;
F_205 ( V_2 ) ;
V_278 = F_206 ( V_2 ) ;
if ( V_278 -> V_279 != F_207 ( V_280 ) ) {
V_92 = - V_265 ;
goto V_276;
}
}
V_2 -> V_245 = V_253 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_281 = V_24 -> V_282 ;
V_2 -> V_283 = V_24 -> V_284 ;
F_32 ( V_4 , V_2 ) ;
if ( V_14 -> V_374 ) {
if ( V_370 . V_46 & V_375 ) {
if ( ! F_251 ( V_2 , V_370 . V_376 ,
V_370 . V_377 ) ) {
V_92 = - V_222 ;
goto V_276;
}
}
F_209 ( V_2 ) -> V_388 = V_370 . V_388 ;
F_209 ( V_2 ) -> V_372 = V_372 ;
F_209 ( V_2 ) -> V_372 |= V_389 ;
F_209 ( V_2 ) -> V_390 = 0 ;
V_172 += V_371 ;
}
if ( ! F_29 ( V_14 ) )
F_210 ( V_2 , V_352 ) ;
if ( F_2 ( V_254 == 4 ) )
V_2 -> V_286 = 1 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( V_92 > 0 && ( V_92 = F_244 ( V_92 ) ) != 0 )
goto V_260;
F_245 ( V_4 ) ;
return V_172 ;
V_276:
F_17 ( V_2 ) ;
V_260:
if ( V_4 )
F_245 ( V_4 ) ;
V_130:
return V_92 ;
}
static int F_252 ( struct V_246 * V_247 , struct V_248 * V_23 ,
struct V_249 * V_250 , T_7 V_172 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
if ( V_14 -> V_75 . V_68 )
return F_238 ( V_14 , V_250 ) ;
else
return F_248 ( V_23 , V_250 , V_172 ) ;
}
static int F_253 ( struct V_248 * V_23 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 ;
struct V_208 * V_208 ;
union V_99 V_100 ;
if ( ! V_24 )
return 0 ;
V_208 = F_78 ( V_24 ) ;
V_14 = F_36 ( V_24 ) ;
F_172 ( & V_208 -> V_391 . V_392 ) ;
F_254 ( V_24 ) ;
F_180 ( & V_208 -> V_391 . V_392 ) ;
F_255 () ;
F_256 ( V_208 , V_24 -> V_393 , - 1 ) ;
F_257 () ;
F_46 ( & V_14 -> V_29 ) ;
F_47 ( V_24 , false ) ;
F_27 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_245 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
F_258 ( V_24 ) ;
if ( V_14 -> V_78 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_259 ( V_24 , & V_100 , 1 , 0 ) ;
}
if ( V_14 -> V_75 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_259 ( V_24 , & V_100 , 1 , 1 ) ;
}
F_181 ( V_24 ) ;
F_45 () ;
F_260 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_146 ( & V_24 -> V_129 ) ;
F_142 ( V_14 ) ;
F_261 ( V_24 ) ;
F_262 ( V_24 ) ;
return 0 ;
}
static int F_263 ( struct V_23 * V_24 , struct V_3 * V_4 , T_8 V_253 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
const struct V_3 * V_394 ;
T_8 V_395 ;
bool V_396 ;
if ( V_14 -> V_26 ) {
if ( V_4 )
F_245 ( V_4 ) ;
return - V_222 ;
}
F_264 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_395 = V_14 -> V_27 . type ;
V_394 = V_14 -> V_27 . V_4 ;
V_396 = V_395 != V_253 || V_394 != V_4 ;
if ( V_396 ) {
F_47 ( V_24 , true ) ;
V_14 -> V_192 = V_253 ;
V_14 -> V_27 . type = V_253 ;
if ( V_14 -> V_27 . V_4 )
F_245 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_94 = V_4 ? V_4 -> V_94 : 0 ;
F_25 ( V_14 , V_4 ) ;
}
if ( V_253 == 0 || ! V_396 )
goto V_260;
if ( ! V_4 || ( V_4 -> V_46 & V_262 ) ) {
F_35 ( V_24 ) ;
} else {
V_24 -> V_397 = V_261 ;
if ( ! F_148 ( V_24 , V_189 ) )
V_24 -> V_398 ( V_24 ) ;
}
V_260:
F_44 ( & V_14 -> V_29 ) ;
F_265 ( V_24 ) ;
return 0 ;
}
static int F_266 ( struct V_248 * V_23 , struct V_256 * V_399 ,
int V_400 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_243 [ 15 ] ;
struct V_3 * V_4 ;
int V_92 = - V_259 ;
if ( V_400 != sizeof( struct V_256 ) )
return - V_222 ;
F_193 ( V_243 , V_399 -> V_401 , sizeof( V_243 ) ) ;
V_4 = F_267 ( F_78 ( V_24 ) , V_243 ) ;
if ( V_4 )
V_92 = F_263 ( V_24 , V_4 , F_36 ( V_24 ) -> V_192 ) ;
return V_92 ;
}
static int F_268 ( struct V_248 * V_23 , struct V_256 * V_399 , int V_400 )
{
struct V_290 * V_291 = (struct V_290 * ) V_399 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_3 * V_4 = NULL ;
int V_92 ;
if ( V_400 < sizeof( struct V_290 ) )
return - V_222 ;
if ( V_291 -> V_304 != V_305 )
return - V_222 ;
if ( V_291 -> V_310 ) {
V_92 = - V_259 ;
V_4 = F_240 ( F_78 ( V_24 ) , V_291 -> V_310 ) ;
if ( V_4 == NULL )
goto V_130;
}
V_92 = F_263 ( V_24 , V_4 , V_291 -> V_307 ? : F_36 ( V_24 ) -> V_192 ) ;
V_130:
return V_92 ;
}
static int F_269 ( struct V_208 * V_208 , struct V_248 * V_23 , int V_245 ,
int V_402 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_8 V_253 = ( V_403 T_8 ) V_245 ;
int V_92 ;
if ( ! F_270 ( V_208 -> V_404 , V_405 ) )
return - V_406 ;
if ( V_23 -> type != V_296 && V_23 -> type != V_373 &&
V_23 -> type != V_407 )
return - V_408 ;
V_23 -> V_409 = V_410 ;
V_92 = - V_181 ;
V_24 = F_271 ( V_208 , V_411 , V_226 , & V_412 ) ;
if ( V_24 == NULL )
goto V_130;
V_23 -> V_19 = & V_413 ;
if ( V_23 -> type == V_407 )
V_23 -> V_19 = & V_414 ;
F_272 ( V_23 , V_24 ) ;
V_14 = F_36 ( V_24 ) ;
V_24 -> V_415 = V_411 ;
V_14 -> V_192 = V_253 ;
V_14 -> V_16 = F_211 ;
V_92 = F_140 ( V_14 ) ;
if ( V_92 )
goto V_416;
F_27 ( V_14 ) ;
V_24 -> V_417 = F_145 ;
F_273 ( V_24 ) ;
F_178 ( & V_14 -> V_29 ) ;
F_274 ( & V_14 -> V_357 ) ;
V_14 -> V_27 . F_72 = F_214 ;
if ( V_23 -> type == V_407 )
V_14 -> V_27 . F_72 = F_186 ;
V_14 -> V_27 . V_206 = V_24 ;
if ( V_253 ) {
V_14 -> V_27 . type = V_253 ;
F_35 ( V_24 ) ;
}
F_172 ( & V_208 -> V_391 . V_392 ) ;
F_275 ( V_24 , & V_208 -> V_391 . V_418 ) ;
F_180 ( & V_208 -> V_391 . V_392 ) ;
F_255 () ;
F_256 ( V_208 , & V_412 , 1 ) ;
F_257 () ;
return 0 ;
V_416:
F_276 ( V_24 ) ;
V_130:
return V_92 ;
}
static int F_277 ( struct V_246 * V_247 , struct V_248 * V_23 ,
struct V_249 * V_250 , T_7 V_172 , int V_46 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_419 , V_92 ;
int V_371 = 0 ;
V_92 = - V_222 ;
if ( V_46 & ~ ( V_420 | V_355 | V_421 | V_422 | V_423 ) )
goto V_130;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_46 & V_423 ) {
V_92 = F_278 ( V_24 , V_250 , V_172 ,
V_424 , V_425 ) ;
goto V_130;
}
V_2 = F_279 ( V_24 , V_46 , V_46 & V_355 , & V_92 ) ;
if ( V_2 == NULL )
goto V_130;
if ( F_36 ( V_24 ) -> V_374 ) {
struct V_369 V_370 = { 0 } ;
V_92 = - V_222 ;
V_371 = sizeof( V_370 ) ;
if ( V_172 < V_371 )
goto V_276;
V_172 -= V_371 ;
if ( F_280 ( V_2 ) ) {
struct V_426 * V_427 = F_209 ( V_2 ) ;
V_370 . V_378 = F_281 ( V_2 ) ;
V_370 . V_388 = V_427 -> V_388 ;
if ( V_427 -> V_372 & V_382 )
V_370 . V_372 = V_381 ;
else if ( V_427 -> V_372 & V_384 )
V_370 . V_372 = V_383 ;
else if ( V_427 -> V_372 & V_386 )
V_370 . V_372 = V_385 ;
else if ( V_427 -> V_372 & V_428 )
goto V_276;
else
F_55 () ;
if ( V_427 -> V_372 & V_387 )
V_370 . V_372 |= V_380 ;
} else
V_370 . V_372 = V_379 ;
if ( V_2 -> V_323 == V_324 ) {
V_370 . V_46 = V_375 ;
V_370 . V_376 = F_282 ( V_2 ) ;
V_370 . V_377 = V_2 -> V_377 ;
} else if ( V_2 -> V_323 == V_429 ) {
V_370 . V_46 = V_430 ;
}
V_92 = F_283 ( V_250 -> V_275 , ( void * ) & V_370 ,
V_371 ) ;
if ( V_92 < 0 )
goto V_276;
}
V_419 = V_2 -> V_172 ;
if ( V_419 > V_172 ) {
V_419 = V_172 ;
V_250 -> V_354 |= V_421 ;
}
V_92 = F_284 ( V_2 , 0 , V_250 -> V_275 , V_419 ) ;
if ( V_92 )
goto V_276;
F_285 ( V_250 , V_24 , V_2 ) ;
if ( V_250 -> V_252 ) {
if ( V_23 -> type == V_407 ) {
F_286 ( sizeof( struct V_233 ) ) ;
V_250 -> V_255 = sizeof( struct V_233 ) ;
} else {
struct V_290 * V_291 = & F_190 ( V_2 ) -> V_239 . V_303 ;
V_250 -> V_255 = V_291 -> V_311 +
F_239 ( struct V_290 , V_312 ) ;
}
memcpy ( V_250 -> V_252 , & F_190 ( V_2 ) -> V_239 ,
V_250 -> V_255 ) ;
}
if ( F_36 ( V_24 ) -> V_431 ) {
struct V_432 V_433 ;
V_433 . V_40 = V_142 ;
if ( V_2 -> V_323 == V_324 )
V_433 . V_40 |= V_325 ;
V_433 . V_332 = F_190 ( V_2 ) -> V_313 ;
V_433 . V_333 = V_2 -> V_172 ;
V_433 . V_334 = 0 ;
V_433 . V_335 = F_216 ( V_2 ) ;
if ( F_115 ( V_2 ) ) {
V_433 . V_163 = F_116 ( V_2 ) ;
V_433 . V_164 = F_117 ( V_2 -> V_165 ) ;
V_433 . V_40 |= V_166 | V_167 ;
} else {
V_433 . V_163 = 0 ;
V_433 . V_164 = 0 ;
}
F_287 ( V_250 , V_424 , V_434 , sizeof( V_433 ) , & V_433 ) ;
}
V_92 = V_371 + ( ( V_46 & V_421 ) ? V_2 -> V_172 : V_419 ) ;
V_276:
F_288 ( V_24 , V_2 ) ;
V_130:
return V_92 ;
}
static int F_289 ( struct V_248 * V_23 , struct V_256 * V_399 ,
int * V_435 , int V_436 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_436 )
return - V_437 ;
V_399 -> V_438 = V_305 ;
memset ( V_399 -> V_401 , 0 , sizeof( V_399 -> V_401 ) ) ;
F_20 () ;
V_4 = F_290 ( F_78 ( V_24 ) , F_36 ( V_24 ) -> V_94 ) ;
if ( V_4 )
F_193 ( V_399 -> V_401 , V_4 -> V_243 , sizeof( V_399 -> V_401 ) ) ;
F_24 () ;
* V_435 = sizeof( * V_399 ) ;
return 0 ;
}
static int F_291 ( struct V_248 * V_23 , struct V_256 * V_399 ,
int * V_435 , int V_436 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
F_196 ( struct V_290 * , V_291 , V_399 ) ;
if ( V_436 )
return - V_437 ;
V_291 -> V_304 = V_305 ;
V_291 -> V_310 = V_14 -> V_94 ;
V_291 -> V_307 = V_14 -> V_192 ;
V_291 -> V_308 = 0 ;
F_20 () ;
V_4 = F_290 ( F_78 ( V_24 ) , V_14 -> V_94 ) ;
if ( V_4 ) {
V_291 -> V_306 = V_4 -> type ;
V_291 -> V_311 = V_4 -> V_400 ;
memcpy ( V_291 -> V_312 , V_4 -> V_439 , V_4 -> V_400 ) ;
} else {
V_291 -> V_306 = 0 ;
V_291 -> V_311 = 0 ;
}
F_24 () ;
* V_435 = F_239 ( struct V_290 , V_312 ) + V_291 -> V_311 ;
return 0 ;
}
static int F_292 ( struct V_3 * V_4 , struct V_440 * V_198 ,
int V_441 )
{
switch ( V_198 -> type ) {
case V_442 :
if ( V_198 -> V_443 != V_4 -> V_400 )
return - V_222 ;
if ( V_441 > 0 )
return F_293 ( V_4 , V_198 -> V_31 ) ;
else
return F_294 ( V_4 , V_198 -> V_31 ) ;
break;
case V_444 :
return F_295 ( V_4 , V_441 ) ;
case V_445 :
return F_296 ( V_4 , V_441 ) ;
case V_446 :
if ( V_198 -> V_443 != V_4 -> V_400 )
return - V_222 ;
if ( V_441 > 0 )
return F_297 ( V_4 , V_198 -> V_31 ) ;
else
return F_298 ( V_4 , V_198 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_299 ( struct V_3 * V_4 , struct V_440 * V_198 , int V_441 )
{
for ( ; V_198 ; V_198 = V_198 -> V_200 ) {
if ( V_198 -> V_94 == V_4 -> V_94 )
F_292 ( V_4 , V_198 , V_441 ) ;
}
}
static int F_300 ( struct V_23 * V_24 , struct V_447 * V_448 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_440 * V_449 , * V_198 ;
struct V_3 * V_4 ;
int V_92 ;
F_76 () ;
V_92 = - V_259 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_448 -> V_450 ) ;
if ( ! V_4 )
goto V_451;
V_92 = - V_222 ;
if ( V_448 -> V_452 > V_4 -> V_400 )
goto V_451;
V_92 = - V_181 ;
V_198 = F_301 ( sizeof( * V_198 ) , V_226 ) ;
if ( V_198 == NULL )
goto V_451;
V_92 = 0 ;
for ( V_449 = V_14 -> V_453 ; V_449 ; V_449 = V_449 -> V_200 ) {
if ( V_449 -> V_94 == V_448 -> V_450 &&
V_449 -> type == V_448 -> V_454 &&
V_449 -> V_443 == V_448 -> V_452 &&
memcmp ( V_449 -> V_31 , V_448 -> V_455 , V_449 -> V_443 ) == 0 ) {
V_449 -> V_456 ++ ;
F_185 ( V_198 ) ;
goto V_451;
}
}
V_198 -> type = V_448 -> V_454 ;
V_198 -> V_94 = V_448 -> V_450 ;
V_198 -> V_443 = V_448 -> V_452 ;
memcpy ( V_198 -> V_31 , V_448 -> V_455 , V_198 -> V_443 ) ;
V_198 -> V_456 = 1 ;
V_198 -> V_200 = V_14 -> V_453 ;
V_14 -> V_453 = V_198 ;
V_92 = F_292 ( V_4 , V_198 , 1 ) ;
if ( V_92 ) {
V_14 -> V_453 = V_198 -> V_200 ;
F_185 ( V_198 ) ;
}
V_451:
F_79 () ;
return V_92 ;
}
static int F_302 ( struct V_23 * V_24 , struct V_447 * V_448 )
{
struct V_440 * V_449 , * * V_457 ;
F_76 () ;
for ( V_457 = & F_36 ( V_24 ) -> V_453 ; ( V_449 = * V_457 ) != NULL ; V_457 = & V_449 -> V_200 ) {
if ( V_449 -> V_94 == V_448 -> V_450 &&
V_449 -> type == V_448 -> V_454 &&
V_449 -> V_443 == V_448 -> V_452 &&
memcmp ( V_449 -> V_31 , V_448 -> V_455 , V_449 -> V_443 ) == 0 ) {
if ( -- V_449 -> V_456 == 0 ) {
struct V_3 * V_4 ;
* V_457 = V_449 -> V_200 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_449 -> V_94 ) ;
if ( V_4 )
F_292 ( V_4 , V_449 , - 1 ) ;
F_185 ( V_449 ) ;
}
F_79 () ;
return 0 ;
}
}
F_79 () ;
return - V_458 ;
}
static void F_258 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_440 * V_449 ;
if ( ! V_14 -> V_453 )
return;
F_76 () ;
while ( ( V_449 = V_14 -> V_453 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_453 = V_449 -> V_200 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_449 -> V_94 ) ;
if ( V_4 != NULL )
F_292 ( V_4 , V_449 , - 1 ) ;
F_185 ( V_449 ) ;
}
F_79 () ;
}
static int
F_303 ( struct V_248 * V_23 , int V_459 , int V_460 , char T_9 * V_461 , unsigned int V_462 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_8 ;
if ( V_459 != V_424 )
return - V_463 ;
switch ( V_460 ) {
case V_464 :
case V_465 :
{
struct V_447 V_448 ;
int V_172 = V_462 ;
memset ( & V_448 , 0 , sizeof( V_448 ) ) ;
if ( V_172 < sizeof( struct V_466 ) )
return - V_222 ;
if ( V_172 > sizeof( V_448 ) )
V_172 = sizeof( V_448 ) ;
if ( F_304 ( & V_448 , V_461 , V_172 ) )
return - V_351 ;
if ( V_172 < ( V_448 . V_452 + F_239 ( struct V_466 , V_455 ) ) )
return - V_222 ;
if ( V_460 == V_464 )
V_8 = F_300 ( V_24 , & V_448 ) ;
else
V_8 = F_302 ( V_24 , & V_448 ) ;
return V_8 ;
}
case V_467 :
case V_468 :
{
union V_99 V_100 ;
int V_172 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_172 = sizeof( V_100 . V_469 ) ;
break;
case V_43 :
default:
V_172 = sizeof( V_100 . V_102 ) ;
break;
}
if ( V_462 < V_172 )
return - V_222 ;
if ( F_36 ( V_24 ) -> V_374 )
return - V_222 ;
if ( F_304 ( & V_100 . V_469 , V_461 , V_172 ) )
return - V_351 ;
return F_259 ( V_24 , & V_100 , 0 ,
V_460 == V_468 ) ;
}
case V_470 :
{
int V_471 ;
if ( V_462 != sizeof( V_471 ) )
return - V_222 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
F_36 ( V_24 ) -> V_328 = V_471 ;
return 0 ;
}
case V_472 :
{
int V_471 ;
if ( V_462 != sizeof( V_471 ) )
return - V_222 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_473 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
switch ( V_471 ) {
case V_38 :
case V_41 :
case V_43 :
V_14 -> V_37 = V_471 ;
return 0 ;
default:
return - V_222 ;
}
}
case V_474 :
{
unsigned int V_471 ;
if ( V_462 != sizeof( V_471 ) )
return - V_222 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_473 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
V_14 -> V_326 = V_471 ;
return 0 ;
}
case V_475 :
{
unsigned int V_471 ;
if ( V_462 != sizeof( V_471 ) )
return - V_222 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_473 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
V_14 -> V_362 = ! ! V_471 ;
return 0 ;
}
case V_434 :
{
int V_471 ;
if ( V_462 < sizeof( V_471 ) )
return - V_222 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
V_14 -> V_431 = ! ! V_471 ;
return 0 ;
}
case V_476 :
{
int V_471 ;
if ( V_462 < sizeof( V_471 ) )
return - V_222 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
V_14 -> V_309 = ! ! V_471 ;
return 0 ;
}
case V_477 :
{
int V_471 ;
if ( V_23 -> type != V_373 )
return - V_222 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_473 ;
if ( V_462 < sizeof( V_471 ) )
return - V_222 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
V_14 -> V_374 = ! ! V_471 ;
return 0 ;
}
case V_478 :
{
int V_471 ;
if ( V_462 != sizeof( V_471 ) )
return - V_222 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
V_14 -> V_55 = V_471 ;
return 0 ;
}
case V_479 :
{
int V_471 ;
if ( V_462 != sizeof( V_471 ) )
return - V_222 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
return F_171 ( V_24 , V_471 & 0xffff , V_471 >> 16 ) ;
}
case V_480 :
{
unsigned int V_471 ;
if ( V_462 != sizeof( V_471 ) )
return - V_222 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_473 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
V_14 -> V_345 = ! ! V_471 ;
return 0 ;
}
case V_481 :
{
int V_471 ;
if ( V_462 != sizeof( V_471 ) )
return - V_222 ;
if ( F_304 ( & V_471 , V_461 , sizeof( V_471 ) ) )
return - V_351 ;
V_14 -> V_16 = V_471 ? F_1 : F_211 ;
return 0 ;
}
default:
return - V_463 ;
}
}
static int F_305 ( struct V_248 * V_23 , int V_459 , int V_460 ,
char T_9 * V_461 , int T_9 * V_462 )
{
int V_172 ;
int V_471 , V_482 = sizeof( V_471 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
void * V_81 = & V_471 ;
union V_483 V_484 ;
if ( V_459 != V_424 )
return - V_463 ;
if ( F_306 ( V_172 , V_462 ) )
return - V_351 ;
if ( V_172 < 0 )
return - V_222 ;
switch ( V_460 ) {
case V_485 :
F_69 ( & V_24 -> V_129 . V_79 ) ;
memcpy ( & V_484 , & V_14 -> V_118 , sizeof( V_484 ) ) ;
memset ( & V_14 -> V_118 , 0 , sizeof( V_14 -> V_118 ) ) ;
F_70 ( & V_24 -> V_129 . V_79 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_482 = sizeof( struct V_486 ) ;
V_484 . V_119 . V_315 += V_484 . V_119 . V_148 ;
V_81 = & V_484 . V_119 ;
} else {
V_482 = sizeof( struct V_487 ) ;
V_484 . V_314 . V_315 += V_484 . V_314 . V_148 ;
V_81 = & V_484 . V_314 ;
}
break;
case V_434 :
V_471 = V_14 -> V_431 ;
break;
case V_476 :
V_471 = V_14 -> V_309 ;
break;
case V_477 :
V_471 = V_14 -> V_374 ;
break;
case V_472 :
V_471 = V_14 -> V_37 ;
break;
case V_488 :
if ( V_172 > sizeof( int ) )
V_172 = sizeof( int ) ;
if ( F_304 ( & V_471 , V_461 , V_172 ) )
return - V_351 ;
switch ( V_471 ) {
case V_38 :
V_471 = sizeof( struct V_489 ) ;
break;
case V_41 :
V_471 = sizeof( struct V_490 ) ;
break;
case V_43 :
V_471 = sizeof( struct V_143 ) ;
break;
default:
return - V_222 ;
}
break;
case V_474 :
V_471 = V_14 -> V_326 ;
break;
case V_475 :
V_471 = V_14 -> V_362 ;
break;
case V_478 :
V_471 = V_14 -> V_55 ;
break;
case V_479 :
V_471 = ( V_14 -> V_26 ?
( ( T_5 ) V_14 -> V_26 -> V_219 |
( ( T_5 ) V_14 -> V_26 -> type << 16 ) |
( ( T_5 ) V_14 -> V_26 -> V_46 << 24 ) ) :
0 ) ;
break;
case V_480 :
V_471 = V_14 -> V_345 ;
break;
case V_481 :
V_471 = F_29 ( V_14 ) ;
break;
default:
return - V_463 ;
}
if ( V_172 > V_482 )
V_172 = V_482 ;
if ( F_307 ( V_172 , V_462 ) )
return - V_351 ;
if ( F_308 ( V_461 , V_81 , V_172 ) )
return - V_351 ;
return 0 ;
}
static int F_309 ( struct V_491 * V_492 ,
unsigned long V_250 , void * V_493 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_310 ( V_493 ) ;
struct V_208 * V_208 = F_166 ( V_4 ) ;
F_20 () ;
F_311 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_36 ( V_24 ) ;
switch ( V_250 ) {
case V_494 :
if ( V_14 -> V_453 )
F_299 ( V_4 , V_14 -> V_453 , - 1 ) ;
case V_495 :
if ( V_4 -> V_94 == V_14 -> V_94 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_40 ( V_24 , false ) ;
V_24 -> V_397 = V_261 ;
if ( ! F_148 ( V_24 , V_189 ) )
V_24 -> V_398 ( V_24 ) ;
}
if ( V_250 == V_494 ) {
F_27 ( V_14 ) ;
V_14 -> V_94 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_245 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
}
break;
case V_496 :
if ( V_4 -> V_94 == V_14 -> V_94 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_192 )
F_35 ( V_24 ) ;
F_44 ( & V_14 -> V_29 ) ;
}
break;
}
}
F_24 () ;
return V_497 ;
}
static int F_312 ( struct V_248 * V_23 , unsigned int V_498 ,
unsigned long V_499 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_498 ) {
case V_500 :
{
int V_501 = F_313 ( V_24 ) ;
return F_307 ( V_501 , ( int T_9 * ) V_499 ) ;
}
case V_502 :
{
struct V_1 * V_2 ;
int V_501 = 0 ;
F_69 ( & V_24 -> V_129 . V_79 ) ;
V_2 = F_314 ( & V_24 -> V_129 ) ;
if ( V_2 )
V_501 = V_2 -> V_172 ;
F_70 ( & V_24 -> V_129 . V_79 ) ;
return F_307 ( V_501 , ( int T_9 * ) V_499 ) ;
}
case V_503 :
return F_315 ( V_24 , (struct V_504 T_9 * ) V_499 ) ;
case V_505 :
return F_316 ( V_24 , (struct V_44 T_9 * ) V_499 ) ;
#ifdef F_317
case V_506 :
case V_507 :
case V_508 :
case V_509 :
case V_510 :
case V_511 :
case V_512 :
case V_513 :
case V_514 :
case V_515 :
case V_516 :
case V_517 :
case V_518 :
case V_519 :
return V_520 . V_521 ( V_23 , V_498 , V_499 ) ;
#endif
default:
return - V_522 ;
}
return 0 ;
}
static unsigned int F_318 ( struct V_523 * V_523 , struct V_248 * V_23 ,
T_10 * V_524 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned int V_525 = F_319 ( V_523 , V_23 , V_524 ) ;
F_69 ( & V_24 -> V_129 . V_79 ) ;
if ( V_14 -> V_78 . V_68 ) {
if ( ! F_129 ( V_14 , & V_14 -> V_78 ,
V_159 ) )
V_525 |= V_526 | V_527 ;
}
F_70 ( & V_24 -> V_129 . V_79 ) ;
F_69 ( & V_24 -> V_528 . V_79 ) ;
if ( V_14 -> V_75 . V_68 ) {
if ( F_64 ( V_14 , & V_14 -> V_75 , V_168 ) )
V_525 |= V_529 | V_530 ;
}
F_70 ( & V_24 -> V_528 . V_79 ) ;
return V_525 ;
}
static void F_320 ( struct V_531 * V_532 )
{
struct V_523 * V_523 = V_532 -> V_533 ;
struct V_248 * V_23 = V_523 -> V_534 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_121 ( & F_36 ( V_24 ) -> V_535 ) ;
}
static void F_321 ( struct V_531 * V_532 )
{
struct V_523 * V_523 = V_532 -> V_533 ;
struct V_248 * V_23 = V_523 -> V_534 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_110 ( & F_36 ( V_24 ) -> V_535 ) ;
}
static void F_322 ( struct V_104 * V_68 , unsigned int V_536 ,
unsigned int V_172 )
{
int V_198 ;
for ( V_198 = 0 ; V_198 < V_172 ; V_198 ++ ) {
if ( F_22 ( V_68 [ V_198 ] . V_69 ) ) {
if ( F_49 ( V_68 [ V_198 ] . V_69 ) )
F_323 ( V_68 [ V_198 ] . V_69 ) ;
else
F_324 ( ( unsigned long ) V_68 [ V_198 ] . V_69 ,
V_536 ) ;
V_68 [ V_198 ] . V_69 = NULL ;
}
}
F_185 ( V_68 ) ;
}
static char * F_325 ( unsigned long V_536 )
{
char * V_69 ;
T_11 V_537 = V_226 | V_538 |
V_539 | V_540 | V_541 ;
V_69 = ( char * ) F_326 ( V_537 , V_536 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_327 ( ( 1 << V_536 ) * V_139 ) ;
if ( V_69 )
return V_69 ;
V_537 &= ~ V_541 ;
V_69 = ( char * ) F_326 ( V_537 , V_536 ) ;
if ( V_69 )
return V_69 ;
return NULL ;
}
static struct V_104 * F_328 ( struct V_542 * V_469 , int V_536 )
{
unsigned int V_543 = V_469 -> V_113 ;
struct V_104 * V_68 ;
int V_198 ;
V_68 = F_329 ( V_543 , sizeof( struct V_104 ) , V_226 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
for ( V_198 = 0 ; V_198 < V_543 ; V_198 ++ ) {
V_68 [ V_198 ] . V_69 = F_325 ( V_536 ) ;
if ( F_2 ( ! V_68 [ V_198 ] . V_69 ) )
goto V_544;
}
V_130:
return V_68 ;
V_544:
F_322 ( V_68 , V_536 , V_543 ) ;
V_68 = NULL ;
goto V_130;
}
static int F_259 ( struct V_23 * V_24 , union V_99 * V_100 ,
int V_545 , int V_75 )
{
struct V_104 * V_68 = NULL ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_546 , V_536 = 0 ;
struct V_62 * V_63 ;
struct V_76 * V_77 ;
T_8 V_192 ;
int V_92 = - V_222 ;
struct V_542 * V_469 = & V_100 -> V_469 ;
if ( ! V_545 && V_75 && ( V_14 -> V_37 > V_41 ) ) {
F_54 ( 1 , L_8 ) ;
goto V_130;
}
V_63 = V_75 ? & V_14 -> V_75 : & V_14 -> V_78 ;
V_77 = V_75 ? & V_24 -> V_528 : & V_24 -> V_129 ;
V_92 = - V_473 ;
if ( ! V_545 ) {
if ( F_92 ( & V_14 -> V_535 ) )
goto V_130;
if ( F_137 ( V_63 ) )
goto V_130;
}
if ( V_469 -> V_113 ) {
V_92 = - V_473 ;
if ( F_2 ( V_63 -> V_68 ) )
goto V_130;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_115 = V_547 ;
break;
case V_41 :
V_14 -> V_115 = V_548 ;
break;
case V_43 :
V_14 -> V_115 = V_549 ;
break;
}
V_92 = - V_222 ;
if ( F_2 ( ( int ) V_469 -> V_111 <= 0 ) )
goto V_130;
if ( F_2 ( V_469 -> V_111 & ( V_139 - 1 ) ) )
goto V_130;
if ( V_14 -> V_37 >= V_43 &&
( int ) ( V_469 -> V_111 -
F_85 ( V_100 -> V_102 . V_125 ) ) <= 0 )
goto V_130;
if ( F_2 ( V_469 -> V_550 < V_14 -> V_115 +
V_14 -> V_326 ) )
goto V_130;
if ( F_2 ( V_469 -> V_550 & ( V_551 - 1 ) ) )
goto V_130;
V_63 -> V_67 = V_469 -> V_111 / V_469 -> V_550 ;
if ( F_2 ( V_63 -> V_67 <= 0 ) )
goto V_130;
if ( F_2 ( ( V_63 -> V_67 * V_469 -> V_113 ) !=
V_469 -> V_552 ) )
goto V_130;
V_92 = - V_225 ;
V_536 = F_330 ( V_469 -> V_111 ) ;
V_68 = F_328 ( V_469 , V_536 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( ! V_75 )
F_83 ( V_14 , V_63 , V_68 , V_100 , V_75 ) ;
break;
default:
break;
}
}
else {
V_92 = - V_222 ;
if ( F_2 ( V_469 -> V_552 ) )
goto V_130;
}
F_264 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_546 = V_14 -> V_25 ;
V_192 = V_14 -> V_192 ;
if ( V_546 ) {
V_14 -> V_192 = 0 ;
F_40 ( V_24 , false ) ;
}
F_44 ( & V_14 -> V_29 ) ;
F_45 () ;
V_92 = - V_473 ;
F_172 ( & V_14 -> V_357 ) ;
if ( V_545 || F_92 ( & V_14 -> V_535 ) == 0 ) {
V_92 = 0 ;
F_69 ( & V_77 -> V_79 ) ;
F_331 ( V_63 -> V_68 , V_68 ) ;
V_63 -> V_176 = ( V_469 -> V_552 - 1 ) ;
V_63 -> V_71 = 0 ;
V_63 -> V_70 = V_469 -> V_550 ;
F_70 ( & V_77 -> V_79 ) ;
F_331 ( V_63 -> V_553 , V_536 ) ;
F_331 ( V_63 -> V_554 , V_469 -> V_113 ) ;
V_63 -> V_555 = V_469 -> V_111 / V_139 ;
V_14 -> V_27 . F_72 = ( V_14 -> V_78 . V_68 ) ?
V_183 : F_214 ;
F_146 ( V_77 ) ;
if ( F_92 ( & V_14 -> V_535 ) )
F_149 ( L_9 ,
F_92 ( & V_14 -> V_535 ) ) ;
}
F_180 ( & V_14 -> V_357 ) ;
F_46 ( & V_14 -> V_29 ) ;
if ( V_546 ) {
V_14 -> V_192 = V_192 ;
F_35 ( V_24 ) ;
}
F_44 ( & V_14 -> V_29 ) ;
if ( V_545 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_75 )
F_67 ( V_14 , V_75 , V_77 ) ;
}
F_265 ( V_24 ) ;
if ( V_68 )
F_322 ( V_68 , V_536 , V_469 -> V_113 ) ;
V_130:
return V_92 ;
}
static int F_332 ( struct V_523 * V_523 , struct V_248 * V_23 ,
struct V_531 * V_532 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned long V_556 , V_557 ;
struct V_62 * V_63 ;
unsigned long V_137 ;
int V_92 = - V_222 ;
int V_198 ;
if ( V_532 -> V_558 )
return - V_222 ;
F_172 ( & V_14 -> V_357 ) ;
V_557 = 0 ;
for ( V_63 = & V_14 -> V_78 ; V_63 <= & V_14 -> V_75 ; V_63 ++ ) {
if ( V_63 -> V_68 ) {
V_557 += V_63 -> V_554
* V_63 -> V_555
* V_139 ;
}
}
if ( V_557 == 0 )
goto V_130;
V_556 = V_532 -> V_559 - V_532 -> V_560 ;
if ( V_556 != V_557 )
goto V_130;
V_137 = V_532 -> V_560 ;
for ( V_63 = & V_14 -> V_78 ; V_63 <= & V_14 -> V_75 ; V_63 ++ ) {
if ( V_63 -> V_68 == NULL )
continue;
for ( V_198 = 0 ; V_198 < V_63 -> V_554 ; V_198 ++ ) {
struct V_30 * V_30 ;
void * V_561 = V_63 -> V_68 [ V_198 ] . V_69 ;
int V_562 ;
for ( V_562 = 0 ; V_562 < V_63 -> V_555 ; V_562 ++ ) {
V_30 = F_48 ( V_561 ) ;
V_92 = F_333 ( V_532 , V_137 , V_30 ) ;
if ( F_2 ( V_92 ) )
goto V_130;
V_137 += V_139 ;
V_561 += V_139 ;
}
}
}
F_121 ( & V_14 -> V_535 ) ;
V_532 -> V_563 = & V_564 ;
V_92 = 0 ;
V_130:
F_180 ( & V_14 -> V_357 ) ;
return V_92 ;
}
static void * F_334 ( struct V_565 * V_566 , T_12 * V_567 )
__acquires( T_13 )
{
struct V_208 * V_208 = F_335 ( V_566 ) ;
F_20 () ;
return F_336 ( & V_208 -> V_391 . V_418 , * V_567 ) ;
}
static void * F_337 ( struct V_565 * V_566 , void * V_568 , T_12 * V_567 )
{
struct V_208 * V_208 = F_335 ( V_566 ) ;
return F_338 ( V_568 , & V_208 -> V_391 . V_418 , V_567 ) ;
}
static void F_339 ( struct V_565 * V_566 , void * V_568 )
__releases( T_13 )
{
F_24 () ;
}
static int F_340 ( struct V_565 * V_566 , void * V_568 )
{
if ( V_568 == V_569 )
F_341 ( V_566 , L_10 ) ;
else {
struct V_23 * V_570 = F_342 ( V_568 ) ;
const struct V_13 * V_14 = F_36 ( V_570 ) ;
F_343 ( V_566 ,
L_11 ,
V_570 ,
F_92 ( & V_570 -> V_571 ) ,
V_570 -> V_295 ,
F_117 ( V_14 -> V_192 ) ,
V_14 -> V_94 ,
V_14 -> V_25 ,
F_92 ( & V_570 -> V_184 ) ,
F_344 ( F_345 ( V_566 ) , F_346 ( V_570 ) ) ,
F_347 ( V_570 ) ) ;
}
return 0 ;
}
static int F_348 ( struct V_572 * V_572 , struct V_523 * V_523 )
{
return F_349 ( V_572 , V_523 , & V_573 ,
sizeof( struct V_574 ) ) ;
}
static int T_14 F_350 ( struct V_208 * V_208 )
{
F_274 ( & V_208 -> V_391 . V_392 ) ;
F_351 ( & V_208 -> V_391 . V_418 ) ;
if ( ! F_352 ( L_12 , 0 , V_208 -> V_575 , & V_576 ) )
return - V_225 ;
return 0 ;
}
static void T_15 F_353 ( struct V_208 * V_208 )
{
F_354 ( L_12 , V_208 -> V_575 ) ;
}
static void T_16 F_355 ( void )
{
F_356 ( & V_577 ) ;
F_357 ( & V_578 ) ;
F_358 ( V_411 ) ;
F_359 ( & V_412 ) ;
}
static int T_17 F_360 ( void )
{
int V_579 = F_361 ( & V_412 , 0 ) ;
if ( V_579 != 0 )
goto V_130;
F_362 ( & V_580 ) ;
F_363 ( & V_578 ) ;
F_364 ( & V_577 ) ;
V_130:
return V_579 ;
}
