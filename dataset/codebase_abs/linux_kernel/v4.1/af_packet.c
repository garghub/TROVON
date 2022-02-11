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
static bool F_144 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_14 -> V_24 ;
bool V_183 ;
if ( V_14 -> V_27 . F_72 != V_184 )
return ( F_92 ( & V_24 -> V_185 ) + V_2 -> V_186 )
<= V_24 -> V_187 ;
F_46 ( & V_24 -> V_129 . V_79 ) ;
if ( V_14 -> V_37 == V_43 )
V_183 = F_125 ( V_14 , & V_14 -> V_78 ,
V_14 -> V_78 . V_175 . V_127 ,
V_160 ) ;
else
V_183 = F_63 ( V_14 , & V_14 -> V_78 ,
V_14 -> V_78 . V_71 ,
V_160 ) ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
return V_183 ;
}
static void F_145 ( struct V_23 * V_24 )
{
F_146 ( & V_24 -> V_188 ) ;
F_147 ( F_92 ( & V_24 -> V_185 ) ) ;
F_147 ( F_92 ( & V_24 -> V_189 ) ) ;
if ( ! F_148 ( V_24 , V_190 ) ) {
F_149 ( L_3 , V_24 ) ;
return;
}
F_150 ( V_24 ) ;
}
static int F_151 ( struct V_191 * V_192 , unsigned int V_193 )
{
int V_194 = F_92 ( & V_192 -> V_195 ) + 1 ;
if ( V_194 >= V_193 )
V_194 = 0 ;
return V_194 ;
}
static unsigned int F_152 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
return F_153 ( F_112 ( V_2 ) , V_193 ) ;
}
static unsigned int F_154 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
int V_196 , V_197 ;
V_196 = F_92 ( & V_192 -> V_195 ) ;
while ( ( V_197 = F_155 ( & V_192 -> V_195 , V_196 ,
F_151 ( V_192 , V_193 ) ) ) != V_196 )
V_196 = V_197 ;
return V_196 ;
}
static unsigned int F_156 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
return F_11 () % V_193 ;
}
static unsigned int F_157 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
return F_158 ( V_193 ) ;
}
static unsigned int F_159 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_174 , unsigned int V_198 ,
unsigned int V_193 )
{
unsigned int V_199 , V_200 ;
V_199 = V_200 = F_160 ( int , V_192 -> V_201 [ V_174 ] , V_193 - 1 ) ;
do {
if ( V_199 != V_198 && F_144 ( F_36 ( V_192 -> V_202 [ V_199 ] ) , V_2 ) ) {
if ( V_199 != V_200 )
V_192 -> V_201 [ V_174 ] = V_199 ;
return V_199 ;
}
if ( ++ V_199 == V_193 )
V_199 = 0 ;
} while ( V_199 != V_200 );
return V_174 ;
}
static unsigned int F_161 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
return F_162 ( V_2 ) % V_193 ;
}
static bool F_163 ( struct V_191 * V_192 , T_2 V_203 )
{
return V_192 -> V_46 & ( V_203 >> 8 ) ;
}
static int F_164 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_191 * V_192 = V_205 -> V_207 ;
unsigned int V_193 = V_192 -> V_208 ;
struct V_13 * V_14 ;
unsigned int V_174 ;
if ( ! F_165 ( F_166 ( V_4 ) , F_167 ( & V_192 -> V_209 ) ) ||
! V_193 ) {
F_17 ( V_2 ) ;
return 0 ;
}
if ( F_163 ( V_192 , V_210 ) ) {
V_2 = F_168 ( V_2 , V_211 ) ;
if ( ! V_2 )
return 0 ;
}
switch ( V_192 -> type ) {
case V_212 :
default:
V_174 = F_152 ( V_192 , V_2 , V_193 ) ;
break;
case V_213 :
V_174 = F_154 ( V_192 , V_2 , V_193 ) ;
break;
case V_214 :
V_174 = F_156 ( V_192 , V_2 , V_193 ) ;
break;
case V_215 :
V_174 = F_157 ( V_192 , V_2 , V_193 ) ;
break;
case V_216 :
V_174 = F_161 ( V_192 , V_2 , V_193 ) ;
break;
case V_217 :
V_174 = F_159 ( V_192 , V_2 , 0 , ( unsigned int ) - 1 , V_193 ) ;
break;
}
V_14 = F_36 ( V_192 -> V_202 [ V_174 ] ) ;
if ( F_163 ( V_192 , V_218 ) &&
F_2 ( ! F_144 ( V_14 , V_2 ) ) ) {
V_174 = F_159 ( V_192 , V_2 , V_174 , V_174 , V_193 ) ;
V_14 = F_36 ( V_192 -> V_202 [ V_174 ] ) ;
}
return V_14 -> V_27 . F_72 ( V_2 , V_4 , & V_14 -> V_27 , V_206 ) ;
}
static void F_37 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_191 * V_192 = V_14 -> V_26 ;
F_46 ( & V_192 -> V_79 ) ;
V_192 -> V_202 [ V_192 -> V_208 ] = V_24 ;
F_56 () ;
V_192 -> V_208 ++ ;
F_44 ( & V_192 -> V_79 ) ;
}
static void F_41 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_191 * V_192 = V_14 -> V_26 ;
int V_199 ;
F_46 ( & V_192 -> V_79 ) ;
for ( V_199 = 0 ; V_199 < V_192 -> V_208 ; V_199 ++ ) {
if ( V_192 -> V_202 [ V_199 ] == V_24 )
break;
}
F_169 ( V_199 >= V_192 -> V_208 ) ;
V_192 -> V_202 [ V_199 ] = V_192 -> V_202 [ V_192 -> V_208 - 1 ] ;
V_192 -> V_208 -- ;
F_44 ( & V_192 -> V_79 ) ;
}
static bool F_170 ( struct V_204 * V_219 , struct V_23 * V_24 )
{
if ( V_219 -> V_207 == ( void * ) ( (struct V_13 * ) V_24 ) -> V_26 )
return true ;
return false ;
}
static int F_171 ( struct V_23 * V_24 , T_2 V_220 , T_2 V_221 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_191 * V_192 , * V_222 ;
T_6 type = V_221 & 0xff ;
T_6 V_46 = V_221 >> 8 ;
int V_92 ;
switch ( type ) {
case V_217 :
if ( V_221 & V_218 )
return - V_223 ;
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
break;
default:
return - V_223 ;
}
if ( ! V_14 -> V_25 )
return - V_223 ;
if ( V_14 -> V_26 )
return - V_224 ;
F_172 ( & V_225 ) ;
V_222 = NULL ;
F_173 (f, &fanout_list, list) {
if ( V_192 -> V_220 == V_220 &&
F_167 ( & V_192 -> V_209 ) == F_78 ( V_24 ) ) {
V_222 = V_192 ;
break;
}
}
V_92 = - V_223 ;
if ( V_222 && V_222 -> V_46 != V_46 )
goto V_130;
if ( ! V_222 ) {
V_92 = - V_226 ;
V_222 = F_174 ( sizeof( * V_222 ) , V_227 ) ;
if ( ! V_222 )
goto V_130;
F_175 ( & V_222 -> V_209 , F_78 ( V_24 ) ) ;
V_222 -> V_220 = V_220 ;
V_222 -> type = type ;
V_222 -> V_46 = V_46 ;
F_176 ( & V_222 -> V_195 , 0 ) ;
F_177 ( & V_222 -> V_228 ) ;
F_178 ( & V_222 -> V_79 ) ;
F_176 ( & V_222 -> V_229 , 0 ) ;
V_222 -> V_27 . type = V_14 -> V_27 . type ;
V_222 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_222 -> V_27 . F_72 = F_164 ;
V_222 -> V_27 . V_207 = V_222 ;
V_222 -> V_27 . V_230 = F_170 ;
F_38 ( & V_222 -> V_27 ) ;
F_179 ( & V_222 -> V_228 , & V_231 ) ;
}
V_92 = - V_223 ;
if ( V_222 -> type == type &&
V_222 -> V_27 . type == V_14 -> V_27 . type &&
V_222 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_92 = - V_232 ;
if ( F_92 ( & V_222 -> V_229 ) < V_233 ) {
F_42 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_222 ;
F_121 ( & V_222 -> V_229 ) ;
F_37 ( V_24 , V_14 ) ;
V_92 = 0 ;
}
}
V_130:
F_180 ( & V_225 ) ;
return V_92 ;
}
static void F_181 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_191 * V_192 ;
V_192 = V_14 -> V_26 ;
if ( ! V_192 )
return;
F_172 ( & V_225 ) ;
V_14 -> V_26 = NULL ;
if ( F_182 ( & V_192 -> V_229 ) ) {
F_183 ( & V_192 -> V_228 ) ;
F_184 ( & V_192 -> V_27 ) ;
F_185 ( V_192 ) ;
}
F_180 ( & V_225 ) ;
}
static int F_186 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_23 * V_24 ;
struct V_234 * V_235 ;
V_24 = V_205 -> V_207 ;
if ( V_2 -> V_236 == V_237 )
goto V_130;
if ( ! F_165 ( F_166 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_130;
V_2 = F_187 ( V_2 , V_238 ) ;
if ( V_2 == NULL )
goto V_239;
F_188 ( V_2 ) ;
F_189 ( V_2 ) ;
V_235 = & F_190 ( V_2 ) -> V_240 . V_241 ;
F_191 ( V_2 , V_2 -> V_81 - F_192 ( V_2 ) ) ;
V_235 -> V_242 = V_4 -> type ;
F_193 ( V_235 -> V_243 , V_4 -> V_244 , sizeof( V_235 -> V_243 ) ) ;
V_235 -> V_245 = V_2 -> V_246 ;
if ( F_194 ( V_24 , V_2 ) == 0 )
return 0 ;
V_130:
F_17 ( V_2 ) ;
V_239:
return 0 ;
}
static int F_195 ( struct V_247 * V_23 , struct V_248 * V_249 ,
T_7 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_196 ( struct V_234 * , V_250 , V_249 -> V_251 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
T_8 V_252 = 0 ;
int V_92 ;
int V_253 = 0 ;
if ( V_250 ) {
if ( V_249 -> V_254 < sizeof( struct V_255 ) )
return - V_223 ;
if ( V_249 -> V_254 == sizeof( struct V_234 ) )
V_252 = V_250 -> V_245 ;
} else
return - V_256 ;
V_250 -> V_243 [ sizeof( V_250 -> V_243 ) - 1 ] = 0 ;
V_257:
F_20 () ;
V_4 = F_197 ( F_78 ( V_24 ) , V_250 -> V_243 ) ;
V_92 = - V_258 ;
if ( V_4 == NULL )
goto V_259;
V_92 = - V_260 ;
if ( ! ( V_4 -> V_46 & V_261 ) )
goto V_259;
if ( F_2 ( F_148 ( V_24 , V_262 ) ) ) {
if ( ! F_198 ( V_4 ) ) {
V_92 = - V_263 ;
goto V_259;
}
V_253 = 4 ;
}
V_92 = - V_264 ;
if ( V_173 > V_4 -> V_265 + V_4 -> V_266 + V_267 + V_253 )
goto V_259;
if ( ! V_2 ) {
T_7 V_268 = F_199 ( V_4 ) ;
int V_269 = V_4 -> V_270 ;
unsigned int V_271 = V_4 -> V_272 ? V_4 -> V_266 : 0 ;
F_24 () ;
V_2 = F_200 ( V_24 , V_173 + V_268 + V_269 , 0 , V_227 ) ;
if ( V_2 == NULL )
return - V_182 ;
F_201 ( V_2 , V_268 ) ;
F_202 ( V_2 ) ;
if ( V_271 ) {
V_2 -> V_81 -= V_271 ;
V_2 -> V_273 -= V_271 ;
if ( V_173 < V_271 )
F_202 ( V_2 ) ;
}
V_92 = F_203 ( F_204 ( V_2 , V_173 ) , V_249 , V_173 ) ;
if ( V_92 )
goto V_274;
goto V_257;
}
if ( V_173 > ( V_4 -> V_265 + V_4 -> V_266 + V_253 ) ) {
struct V_275 * V_276 ;
F_205 ( V_2 ) ;
V_276 = F_206 ( V_2 ) ;
if ( V_276 -> V_277 != F_207 ( V_278 ) ) {
V_92 = - V_264 ;
goto V_259;
}
}
V_2 -> V_246 = V_252 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_279 = V_24 -> V_280 ;
V_2 -> V_281 = V_24 -> V_282 ;
F_208 ( V_24 , & F_209 ( V_2 ) -> V_283 ) ;
if ( F_2 ( V_253 == 4 ) )
V_2 -> V_284 = 1 ;
F_210 ( V_2 , 0 ) ;
F_211 ( V_2 ) ;
F_24 () ;
return V_173 ;
V_259:
F_24 () ;
V_274:
F_17 ( V_2 ) ;
return V_92 ;
}
static unsigned int F_212 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_285 )
{
struct V_286 * V_287 ;
F_20 () ;
V_287 = F_21 ( V_24 -> V_286 ) ;
if ( V_287 != NULL )
V_285 = F_213 ( V_287 , V_2 ) ;
F_24 () ;
return V_285 ;
}
static int F_214 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_23 * V_24 ;
struct V_288 * V_289 ;
struct V_13 * V_14 ;
T_6 * V_290 = V_2 -> V_81 ;
int V_291 = V_2 -> V_173 ;
unsigned int V_292 , V_285 ;
if ( V_2 -> V_236 == V_237 )
goto V_10;
V_24 = V_205 -> V_207 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_165 ( F_166 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_272 ) {
if ( V_24 -> V_293 != V_294 )
F_191 ( V_2 , V_2 -> V_81 - F_192 ( V_2 ) ) ;
else if ( V_2 -> V_236 == V_295 ) {
F_215 ( V_2 , F_216 ( V_2 ) ) ;
}
}
V_292 = V_2 -> V_173 ;
V_285 = F_212 ( V_2 , V_24 , V_292 ) ;
if ( ! V_285 )
goto V_296;
if ( V_292 > V_285 )
V_292 = V_285 ;
if ( F_92 ( & V_24 -> V_185 ) >= V_24 -> V_187 )
goto V_297;
if ( F_217 ( V_2 ) ) {
struct V_1 * V_298 = F_218 ( V_2 , V_238 ) ;
if ( V_298 == NULL )
goto V_297;
if ( V_290 != V_2 -> V_81 ) {
V_2 -> V_81 = V_290 ;
V_2 -> V_173 = V_291 ;
}
F_219 ( V_2 ) ;
V_2 = V_298 ;
}
F_220 ( sizeof( * F_190 ( V_2 ) ) + V_299 - 8 ) ;
V_289 = & F_190 ( V_2 ) -> V_240 . V_300 ;
V_289 -> V_301 = V_4 -> type ;
V_289 -> V_302 = V_2 -> V_236 ;
if ( F_2 ( V_14 -> V_303 ) )
V_289 -> V_304 = V_206 -> V_94 ;
else
V_289 -> V_304 = V_4 -> V_94 ;
V_289 -> V_305 = F_221 ( V_2 , V_289 -> V_306 ) ;
F_190 ( V_2 ) -> V_240 . V_307 = V_2 -> V_173 ;
if ( F_222 ( V_2 , V_292 ) )
goto V_297;
F_223 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_188 ( V_2 ) ;
F_189 ( V_2 ) ;
F_46 ( & V_24 -> V_129 . V_79 ) ;
V_14 -> V_118 . V_308 . V_309 ++ ;
F_224 ( V_24 , V_2 ) ;
F_225 ( & V_24 -> V_129 , V_2 ) ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
V_24 -> V_155 ( V_24 ) ;
return 0 ;
V_297:
F_46 ( & V_24 -> V_129 . V_79 ) ;
V_14 -> V_118 . V_308 . V_148 ++ ;
F_121 ( & V_24 -> V_310 ) ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
V_296:
if ( V_290 != V_2 -> V_81 && F_217 ( V_2 ) ) {
V_2 -> V_81 = V_290 ;
V_2 -> V_173 = V_291 ;
}
V_10:
F_219 ( V_2 ) ;
return 0 ;
}
static int V_184 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
struct V_288 * V_289 ;
union V_34 V_35 ;
T_6 * V_290 = V_2 -> V_81 ;
int V_291 = V_2 -> V_173 ;
unsigned int V_292 , V_285 ;
unsigned long V_33 = V_142 ;
unsigned short V_311 , V_312 , V_114 ;
struct V_1 * V_313 = NULL ;
struct V_44 V_45 ;
T_4 V_54 ;
F_226 ( F_227 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_226 ( F_227 ( sizeof( * V_35 . V_314 ) ) != 48 ) ;
if ( V_2 -> V_236 == V_237 )
goto V_10;
V_24 = V_205 -> V_207 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_165 ( F_166 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_272 ) {
if ( V_24 -> V_293 != V_294 )
F_191 ( V_2 , V_2 -> V_81 - F_192 ( V_2 ) ) ;
else if ( V_2 -> V_236 == V_295 ) {
F_215 ( V_2 , F_216 ( V_2 ) ) ;
}
}
V_292 = V_2 -> V_173 ;
V_285 = F_212 ( V_2 , V_24 , V_292 ) ;
if ( ! V_285 )
goto V_296;
if ( V_2 -> V_315 == V_316 )
V_33 |= V_317 ;
else if ( V_2 -> V_236 != V_295 &&
( V_2 -> V_315 == V_318 ||
F_228 ( V_2 ) ) )
V_33 |= V_319 ;
if ( V_292 > V_285 )
V_292 = V_285 ;
if ( V_24 -> V_293 == V_294 ) {
V_311 = V_312 = F_227 ( V_14 -> V_115 ) + 16 +
V_14 -> V_320 ;
} else {
unsigned int V_321 = F_216 ( V_2 ) ;
V_312 = F_227 ( V_14 -> V_115 +
( V_321 < 16 ? 16 : V_321 ) ) +
V_14 -> V_320 ;
V_311 = V_312 - V_321 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_311 + V_292 > V_14 -> V_78 . V_70 ) {
if ( V_14 -> V_322 &&
F_92 ( & V_24 -> V_185 ) < V_24 -> V_187 ) {
if ( F_217 ( V_2 ) ) {
V_313 = F_218 ( V_2 , V_238 ) ;
} else {
V_313 = F_229 ( V_2 ) ;
V_290 = V_2 -> V_81 ;
}
if ( V_313 )
F_223 ( V_313 , V_24 ) ;
}
V_292 = V_14 -> V_78 . V_70 - V_311 ;
if ( ( int ) V_292 < 0 )
V_292 = 0 ;
}
} else if ( F_2 ( V_311 + V_292 >
F_68 ( & V_14 -> V_78 ) -> V_126 ) ) {
T_5 V_323 ;
V_323 = F_68 ( & V_14 -> V_78 ) -> V_126 - V_311 ;
F_230 ( L_4 ,
V_292 , V_323 , V_311 ) ;
V_292 = V_323 ;
if ( F_2 ( ( int ) V_292 < 0 ) ) {
V_292 = 0 ;
V_311 = F_68 ( & V_14 -> V_78 ) -> V_126 ;
}
}
F_46 ( & V_24 -> V_129 . V_79 ) ;
V_35 . V_36 = F_124 ( V_14 , V_2 ,
V_160 , ( V_311 + V_292 ) ) ;
if ( ! V_35 . V_36 )
goto V_324;
if ( V_14 -> V_37 <= V_41 ) {
F_131 ( V_14 , & V_14 -> V_78 ) ;
if ( V_14 -> V_118 . V_308 . V_148 )
V_33 |= V_149 ;
}
V_14 -> V_118 . V_308 . V_309 ++ ;
if ( V_313 ) {
V_33 |= V_325 ;
F_225 ( & V_24 -> V_129 , V_313 ) ;
}
F_44 ( & V_24 -> V_129 . V_79 ) ;
F_231 ( V_2 , 0 , V_35 . V_36 + V_311 , V_292 ) ;
if ( ! ( V_54 = F_59 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
F_101 ( & V_45 ) ;
V_33 |= V_54 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_326 = V_2 -> V_173 ;
V_35 . V_39 -> V_327 = V_292 ;
V_35 . V_39 -> V_328 = V_311 ;
V_35 . V_39 -> V_329 = V_312 ;
V_35 . V_39 -> V_56 = V_45 . V_57 ;
V_35 . V_39 -> V_58 = V_45 . V_59 / V_60 ;
V_114 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_326 = V_2 -> V_173 ;
V_35 . V_42 -> V_327 = V_292 ;
V_35 . V_42 -> V_328 = V_311 ;
V_35 . V_42 -> V_329 = V_312 ;
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
V_35 . V_314 -> V_40 |= V_33 ;
V_35 . V_314 -> V_326 = V_2 -> V_173 ;
V_35 . V_314 -> V_327 = V_292 ;
V_35 . V_314 -> V_328 = V_311 ;
V_35 . V_314 -> V_329 = V_312 ;
V_35 . V_314 -> V_56 = V_45 . V_57 ;
V_35 . V_314 -> V_61 = V_45 . V_59 ;
memset ( V_35 . V_314 -> V_170 , 0 , sizeof( V_35 . V_314 -> V_170 ) ) ;
V_114 = sizeof( * V_35 . V_314 ) ;
break;
default:
F_55 () ;
}
V_289 = V_35 . V_36 + F_227 ( V_114 ) ;
V_289 -> V_305 = F_221 ( V_2 , V_289 -> V_306 ) ;
V_289 -> V_330 = V_331 ;
V_289 -> V_301 = V_4 -> type ;
V_289 -> V_332 = V_2 -> V_246 ;
V_289 -> V_302 = V_2 -> V_236 ;
if ( F_2 ( V_14 -> V_303 ) )
V_289 -> V_304 = V_206 -> V_94 ;
else
V_289 -> V_304 = V_4 -> V_94 ;
F_123 () ;
#if V_136 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_6 * V_137 , * V_138 ;
V_138 = ( T_6 * ) F_98 ( ( unsigned long ) V_35 . V_36 +
V_311 + V_292 ) ;
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
V_296:
if ( V_290 != V_2 -> V_81 && F_217 ( V_2 ) ) {
V_2 -> V_81 = V_290 ;
V_2 -> V_173 = V_291 ;
}
V_10:
F_17 ( V_2 ) ;
return 0 ;
V_324:
V_14 -> V_118 . V_308 . V_148 ++ ;
F_44 ( & V_24 -> V_129 . V_79 ) ;
V_24 -> V_155 ( V_24 ) ;
F_17 ( V_313 ) ;
goto V_296;
}
static void F_232 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_36 ( V_2 -> V_24 ) ;
if ( F_22 ( V_14 -> V_75 . V_68 ) ) {
void * V_333 ;
T_4 V_45 ;
V_333 = F_209 ( V_2 ) -> V_334 ;
F_135 ( & V_14 -> V_75 ) ;
V_45 = F_62 ( V_14 , V_333 , V_2 ) ;
F_52 ( V_14 , V_333 , V_169 | V_45 ) ;
}
F_233 ( V_2 ) ;
}
static bool F_234 ( const struct V_3 * V_4 , int V_173 )
{
if ( F_2 ( V_173 <= V_4 -> V_266 ) ) {
F_235 ( L_5 ,
V_335 -> V_336 , V_173 , V_4 -> V_266 ) ;
return true ;
}
return false ;
}
static int F_236 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , int V_337 ,
T_8 V_252 , unsigned char * V_31 , int V_338 )
{
union V_34 V_333 ;
int V_339 , V_340 , V_173 , V_326 , V_341 , V_342 ;
struct V_247 * V_23 = V_14 -> V_24 . V_343 ;
struct V_30 * V_30 ;
void * V_81 ;
int V_92 ;
V_333 . V_36 = V_32 ;
V_2 -> V_246 = V_252 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_279 = V_14 -> V_24 . V_280 ;
V_2 -> V_281 = V_14 -> V_24 . V_282 ;
F_208 ( & V_14 -> V_24 , & F_209 ( V_2 ) -> V_283 ) ;
F_209 ( V_2 ) -> V_334 = V_333 . V_36 ;
switch ( V_14 -> V_37 ) {
case V_41 :
V_326 = V_333 . V_42 -> V_326 ;
break;
default:
V_326 = V_333 . V_39 -> V_326 ;
break;
}
if ( F_2 ( V_326 > V_337 ) ) {
F_149 ( L_6 , V_326 , V_337 ) ;
return - V_264 ;
}
F_201 ( V_2 , V_338 ) ;
F_202 ( V_2 ) ;
if ( ! F_29 ( V_14 ) )
F_210 ( V_2 , 0 ) ;
if ( F_2 ( V_14 -> V_344 ) ) {
int V_345 , V_346 , V_347 ;
V_345 = V_14 -> V_115 - sizeof( struct V_288 ) ;
V_346 = V_14 -> V_75 . V_70 - V_326 ;
if ( V_23 -> type == V_294 ) {
switch ( V_14 -> V_37 ) {
case V_41 :
V_347 = V_333 . V_42 -> V_329 ;
break;
default:
V_347 = V_333 . V_39 -> V_329 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_41 :
V_347 = V_333 . V_42 -> V_328 ;
break;
default:
V_347 = V_333 . V_39 -> V_328 ;
break;
}
}
if ( F_2 ( ( V_347 < V_345 ) || ( V_346 < V_347 ) ) )
return - V_223 ;
V_81 = V_333 . V_36 + V_347 ;
} else {
V_81 = V_333 . V_36 + V_14 -> V_115 - sizeof( struct V_288 ) ;
}
V_339 = V_326 ;
if ( V_23 -> type == V_294 ) {
V_92 = F_237 ( V_2 , V_4 , F_117 ( V_252 ) , V_31 ,
NULL , V_326 ) ;
if ( F_2 ( V_92 < 0 ) )
return - V_223 ;
} else if ( V_4 -> V_266 ) {
if ( F_234 ( V_4 , V_326 ) )
return - V_223 ;
F_191 ( V_2 , V_4 -> V_266 ) ;
V_92 = F_238 ( V_2 , 0 , V_81 ,
V_4 -> V_266 ) ;
if ( F_2 ( V_92 ) )
return V_92 ;
V_81 += V_4 -> V_266 ;
V_339 -= V_4 -> V_266 ;
}
V_340 = F_239 ( V_81 ) ;
V_342 = V_139 - V_340 ;
V_173 = ( ( V_339 > V_342 ) ? V_342 : V_339 ) ;
V_2 -> V_348 = V_339 ;
V_2 -> V_173 += V_339 ;
V_2 -> V_186 += V_339 ;
F_240 ( V_339 , & V_14 -> V_24 . V_189 ) ;
while ( F_22 ( V_339 ) ) {
V_341 = F_209 ( V_2 ) -> V_341 ;
if ( F_2 ( V_341 >= V_349 ) ) {
F_149 ( L_7 ,
V_349 ) ;
return - V_350 ;
}
V_30 = F_48 ( V_81 ) ;
V_81 += V_173 ;
F_53 ( V_30 ) ;
F_241 ( V_30 ) ;
F_242 ( V_2 , V_341 , V_30 , V_340 , V_173 ) ;
V_339 -= V_173 ;
V_340 = 0 ;
V_342 = V_139 ;
V_173 = ( ( V_339 > V_342 ) ? V_342 : V_339 ) ;
}
return V_326 ;
}
static int F_243 ( struct V_13 * V_14 , struct V_248 * V_249 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_252 ;
int V_92 , V_351 = 0 ;
void * V_333 ;
F_196 ( struct V_288 * , V_250 , V_249 -> V_251 ) ;
bool V_352 = ! ( V_249 -> V_353 & V_354 ) ;
int V_326 , V_337 ;
unsigned char * V_31 ;
int V_355 = 0 ;
int V_33 = V_169 ;
int V_338 , V_269 ;
F_172 ( & V_14 -> V_356 ) ;
if ( F_22 ( V_250 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_252 = V_14 -> V_193 ;
V_31 = NULL ;
} else {
V_92 = - V_223 ;
if ( V_249 -> V_254 < sizeof( struct V_288 ) )
goto V_130;
if ( V_249 -> V_254 < ( V_250 -> V_305
+ F_244 ( struct V_288 ,
V_306 ) ) )
goto V_130;
V_252 = V_250 -> V_332 ;
V_31 = V_250 -> V_306 ;
V_4 = F_245 ( F_78 ( & V_14 -> V_24 ) , V_250 -> V_304 ) ;
}
V_92 = - V_357 ;
if ( F_2 ( V_4 == NULL ) )
goto V_130;
V_92 = - V_260 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_261 ) ) )
goto V_358;
V_351 = V_4 -> V_266 + V_267 ;
V_337 = V_14 -> V_75 . V_70
- ( V_14 -> V_115 - sizeof( struct V_288 ) ) ;
if ( V_337 > V_4 -> V_265 + V_351 )
V_337 = V_4 -> V_265 + V_351 ;
do {
V_333 = F_64 ( V_14 , & V_14 -> V_75 ,
V_359 ) ;
if ( F_2 ( V_333 == NULL ) ) {
if ( V_352 && F_246 () )
F_247 () ;
continue;
}
V_33 = V_359 ;
V_338 = F_199 ( V_4 ) ;
V_269 = V_4 -> V_270 ;
V_2 = F_248 ( & V_14 -> V_24 ,
V_338 + V_269 + sizeof( struct V_288 ) ,
! V_352 , & V_92 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_22 ( V_355 > 0 ) )
V_92 = V_355 ;
goto V_360;
}
V_326 = F_236 ( V_14 , V_2 , V_333 , V_4 , V_337 , V_252 ,
V_31 , V_338 ) ;
if ( V_326 > V_4 -> V_265 + V_4 -> V_266 ) {
struct V_275 * V_276 ;
F_205 ( V_2 ) ;
V_276 = F_206 ( V_2 ) ;
if ( V_276 -> V_277 != F_207 ( V_278 ) )
V_326 = - V_264 ;
}
if ( F_2 ( V_326 < 0 ) ) {
if ( V_14 -> V_361 ) {
F_52 ( V_14 , V_333 ,
V_169 ) ;
F_132 ( & V_14 -> V_75 ) ;
F_17 ( V_2 ) ;
continue;
} else {
V_33 = V_362 ;
V_92 = V_326 ;
goto V_360;
}
}
F_32 ( V_4 , V_2 ) ;
V_2 -> V_363 = F_232 ;
F_52 ( V_14 , V_333 , V_364 ) ;
F_133 ( & V_14 -> V_75 ) ;
V_33 = V_359 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_92 > 0 ) ) {
V_92 = F_249 ( V_92 ) ;
if ( V_92 && F_57 ( V_14 , V_333 ) ==
V_169 ) {
V_2 = NULL ;
goto V_360;
}
V_92 = 0 ;
}
F_132 ( & V_14 -> V_75 ) ;
V_355 += V_326 ;
} while ( F_22 ( ( V_333 != NULL ) ||
( V_352 && F_137 ( & V_14 -> V_75 ) ) ) );
V_92 = V_355 ;
goto V_358;
V_360:
F_52 ( V_14 , V_333 , V_33 ) ;
F_17 ( V_2 ) ;
V_358:
F_250 ( V_4 ) ;
V_130:
F_180 ( & V_14 -> V_356 ) ;
return V_92 ;
}
static struct V_1 * F_251 ( struct V_23 * V_24 , T_7 V_365 ,
T_7 V_351 , T_7 V_173 ,
T_7 V_366 , int V_367 ,
int * V_92 )
{
struct V_1 * V_2 ;
if ( V_365 + V_173 < V_139 || ! V_366 )
V_366 = V_173 ;
V_2 = F_252 ( V_24 , V_365 + V_366 , V_173 - V_366 , V_367 ,
V_92 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_201 ( V_2 , V_351 ) ;
F_204 ( V_2 , V_366 ) ;
V_2 -> V_348 = V_173 - V_366 ;
V_2 -> V_173 += V_173 - V_366 ;
return V_2 ;
}
static int F_253 ( struct V_247 * V_23 , struct V_248 * V_249 , T_7 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_196 ( struct V_288 * , V_250 , V_249 -> V_251 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_252 ;
unsigned char * V_31 ;
int V_92 , V_351 = 0 ;
struct V_368 V_369 = { 0 } ;
int V_340 = 0 ;
int V_370 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned short V_371 = 0 ;
int V_338 , V_269 ;
int V_253 = 0 ;
T_9 V_372 ;
if ( F_22 ( V_250 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_252 = V_14 -> V_193 ;
V_31 = NULL ;
} else {
V_92 = - V_223 ;
if ( V_249 -> V_254 < sizeof( struct V_288 ) )
goto V_130;
if ( V_249 -> V_254 < ( V_250 -> V_305 + F_244 ( struct V_288 , V_306 ) ) )
goto V_130;
V_252 = V_250 -> V_332 ;
V_31 = V_250 -> V_306 ;
V_4 = F_245 ( F_78 ( V_24 ) , V_250 -> V_304 ) ;
}
V_92 = - V_357 ;
if ( F_2 ( V_4 == NULL ) )
goto V_259;
V_92 = - V_260 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_261 ) ) )
goto V_259;
if ( V_23 -> type == V_373 )
V_351 = V_4 -> V_266 ;
if ( V_14 -> V_374 ) {
V_370 = sizeof( V_369 ) ;
V_92 = - V_223 ;
if ( V_173 < V_370 )
goto V_259;
V_173 -= V_370 ;
V_92 = - V_350 ;
V_372 = F_254 ( & V_369 , V_370 , & V_249 -> V_375 ) ;
if ( V_372 != V_370 )
goto V_259;
if ( ( V_369 . V_46 & V_376 ) &&
( F_255 ( false , V_369 . V_377 ) +
F_255 ( false , V_369 . V_378 ) + 2 >
F_255 ( false , V_369 . V_379 ) ) )
V_369 . V_379 = F_256 ( false ,
F_255 ( false , V_369 . V_377 ) +
F_255 ( false , V_369 . V_378 ) + 2 ) ;
V_92 = - V_223 ;
if ( F_255 ( false , V_369 . V_379 ) > V_173 )
goto V_259;
if ( V_369 . V_371 != V_380 ) {
switch ( V_369 . V_371 & ~ V_381 ) {
case V_382 :
V_371 = V_383 ;
break;
case V_384 :
V_371 = V_385 ;
break;
case V_386 :
V_371 = V_387 ;
break;
default:
goto V_259;
}
if ( V_369 . V_371 & V_381 )
V_371 |= V_388 ;
if ( V_369 . V_389 == 0 )
goto V_259;
}
}
if ( F_2 ( F_148 ( V_24 , V_262 ) ) ) {
if ( ! F_198 ( V_4 ) ) {
V_92 = - V_263 ;
goto V_259;
}
V_253 = 4 ;
}
V_92 = - V_264 ;
if ( ! V_371 && ( V_173 > V_4 -> V_265 + V_351 + V_267 + V_253 ) )
goto V_259;
V_92 = - V_182 ;
V_338 = F_199 ( V_4 ) ;
V_269 = V_4 -> V_270 ;
V_2 = F_251 ( V_24 , V_338 + V_269 , V_338 , V_173 ,
F_255 ( false , V_369 . V_379 ) ,
V_249 -> V_353 & V_354 , & V_92 ) ;
if ( V_2 == NULL )
goto V_259;
F_257 ( V_2 , V_351 ) ;
V_92 = - V_223 ;
if ( V_23 -> type == V_294 ) {
V_340 = F_237 ( V_2 , V_4 , F_117 ( V_252 ) , V_31 , NULL , V_173 ) ;
if ( F_2 ( V_340 < 0 ) )
goto V_274;
} else {
if ( F_234 ( V_4 , V_173 ) )
goto V_274;
}
V_92 = F_258 ( V_2 , V_340 , & V_249 -> V_375 , V_173 ) ;
if ( V_92 )
goto V_274;
F_208 ( V_24 , & F_209 ( V_2 ) -> V_283 ) ;
if ( ! V_371 && ( V_173 > V_4 -> V_265 + V_351 + V_253 ) ) {
struct V_275 * V_276 ;
F_205 ( V_2 ) ;
V_276 = F_206 ( V_2 ) ;
if ( V_276 -> V_277 != F_207 ( V_278 ) ) {
V_92 = - V_264 ;
goto V_274;
}
}
V_2 -> V_246 = V_252 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_279 = V_24 -> V_280 ;
V_2 -> V_281 = V_24 -> V_282 ;
F_32 ( V_4 , V_2 ) ;
if ( V_14 -> V_374 ) {
if ( V_369 . V_46 & V_376 ) {
T_2 V_390 = F_255 ( false , V_369 . V_377 ) ;
T_2 V_391 = F_255 ( false , V_369 . V_378 ) ;
if ( ! F_259 ( V_2 , V_390 , V_391 ) ) {
V_92 = - V_223 ;
goto V_274;
}
}
F_209 ( V_2 ) -> V_389 =
F_255 ( false , V_369 . V_389 ) ;
F_209 ( V_2 ) -> V_371 = V_371 ;
F_209 ( V_2 ) -> V_371 |= V_392 ;
F_209 ( V_2 ) -> V_393 = 0 ;
V_173 += V_370 ;
}
if ( ! F_29 ( V_14 ) )
F_210 ( V_2 , V_351 ) ;
if ( F_2 ( V_253 == 4 ) )
V_2 -> V_284 = 1 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( V_92 > 0 && ( V_92 = F_249 ( V_92 ) ) != 0 )
goto V_259;
F_250 ( V_4 ) ;
return V_173 ;
V_274:
F_17 ( V_2 ) ;
V_259:
if ( V_4 )
F_250 ( V_4 ) ;
V_130:
return V_92 ;
}
static int F_260 ( struct V_247 * V_23 , struct V_248 * V_249 , T_7 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
if ( V_14 -> V_75 . V_68 )
return F_243 ( V_14 , V_249 ) ;
else
return F_253 ( V_23 , V_249 , V_173 ) ;
}
static int F_261 ( struct V_247 * V_23 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 ;
struct V_209 * V_209 ;
union V_99 V_100 ;
if ( ! V_24 )
return 0 ;
V_209 = F_78 ( V_24 ) ;
V_14 = F_36 ( V_24 ) ;
F_172 ( & V_209 -> V_394 . V_395 ) ;
F_262 ( V_24 ) ;
F_180 ( & V_209 -> V_394 . V_395 ) ;
F_263 () ;
F_264 ( V_209 , V_24 -> V_396 , - 1 ) ;
F_265 () ;
F_46 ( & V_14 -> V_29 ) ;
F_47 ( V_24 , false ) ;
F_27 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_250 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
F_266 ( V_24 ) ;
if ( V_14 -> V_78 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_267 ( V_24 , & V_100 , 1 , 0 ) ;
}
if ( V_14 -> V_75 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_267 ( V_24 , & V_100 , 1 , 1 ) ;
}
F_181 ( V_24 ) ;
F_45 () ;
F_268 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_146 ( & V_24 -> V_129 ) ;
F_142 ( V_14 ) ;
F_269 ( V_24 ) ;
F_270 ( V_24 ) ;
return 0 ;
}
static int F_271 ( struct V_23 * V_24 , struct V_3 * V_4 , T_8 V_252 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
const struct V_3 * V_397 ;
T_8 V_398 ;
bool V_399 ;
if ( V_14 -> V_26 ) {
if ( V_4 )
F_250 ( V_4 ) ;
return - V_223 ;
}
F_272 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_398 = V_14 -> V_27 . type ;
V_397 = V_14 -> V_27 . V_4 ;
V_399 = V_398 != V_252 || V_397 != V_4 ;
if ( V_399 ) {
F_47 ( V_24 , true ) ;
V_14 -> V_193 = V_252 ;
V_14 -> V_27 . type = V_252 ;
if ( V_14 -> V_27 . V_4 )
F_250 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_94 = V_4 ? V_4 -> V_94 : 0 ;
F_25 ( V_14 , V_4 ) ;
}
if ( V_252 == 0 || ! V_399 )
goto V_259;
if ( ! V_4 || ( V_4 -> V_46 & V_261 ) ) {
F_35 ( V_24 ) ;
} else {
V_24 -> V_400 = V_260 ;
if ( ! F_148 ( V_24 , V_190 ) )
V_24 -> V_401 ( V_24 ) ;
}
V_259:
F_44 ( & V_14 -> V_29 ) ;
F_273 ( V_24 ) ;
return 0 ;
}
static int F_274 ( struct V_247 * V_23 , struct V_255 * V_402 ,
int V_403 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_244 [ 15 ] ;
struct V_3 * V_4 ;
int V_92 = - V_258 ;
if ( V_403 != sizeof( struct V_255 ) )
return - V_223 ;
F_193 ( V_244 , V_402 -> V_404 , sizeof( V_244 ) ) ;
V_4 = F_275 ( F_78 ( V_24 ) , V_244 ) ;
if ( V_4 )
V_92 = F_271 ( V_24 , V_4 , F_36 ( V_24 ) -> V_193 ) ;
return V_92 ;
}
static int F_276 ( struct V_247 * V_23 , struct V_255 * V_402 , int V_403 )
{
struct V_288 * V_289 = (struct V_288 * ) V_402 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_3 * V_4 = NULL ;
int V_92 ;
if ( V_403 < sizeof( struct V_288 ) )
return - V_223 ;
if ( V_289 -> V_330 != V_331 )
return - V_223 ;
if ( V_289 -> V_304 ) {
V_92 = - V_258 ;
V_4 = F_245 ( F_78 ( V_24 ) , V_289 -> V_304 ) ;
if ( V_4 == NULL )
goto V_130;
}
V_92 = F_271 ( V_24 , V_4 , V_289 -> V_332 ? : F_36 ( V_24 ) -> V_193 ) ;
V_130:
return V_92 ;
}
static int F_277 ( struct V_209 * V_209 , struct V_247 * V_23 , int V_246 ,
int V_405 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_8 V_252 = ( V_406 T_8 ) V_246 ;
int V_92 ;
if ( ! F_278 ( V_209 -> V_407 , V_408 ) )
return - V_409 ;
if ( V_23 -> type != V_294 && V_23 -> type != V_373 &&
V_23 -> type != V_410 )
return - V_411 ;
V_23 -> V_412 = V_413 ;
V_92 = - V_182 ;
V_24 = F_279 ( V_209 , V_414 , V_227 , & V_415 ) ;
if ( V_24 == NULL )
goto V_130;
V_23 -> V_19 = & V_416 ;
if ( V_23 -> type == V_410 )
V_23 -> V_19 = & V_417 ;
F_280 ( V_23 , V_24 ) ;
V_14 = F_36 ( V_24 ) ;
V_24 -> V_418 = V_414 ;
V_14 -> V_193 = V_252 ;
V_14 -> V_16 = F_211 ;
V_92 = F_140 ( V_14 ) ;
if ( V_92 )
goto V_419;
F_27 ( V_14 ) ;
V_24 -> V_420 = F_145 ;
F_281 ( V_24 ) ;
F_178 ( & V_14 -> V_29 ) ;
F_282 ( & V_14 -> V_356 ) ;
V_14 -> V_27 . F_72 = F_214 ;
if ( V_23 -> type == V_410 )
V_14 -> V_27 . F_72 = F_186 ;
V_14 -> V_27 . V_207 = V_24 ;
if ( V_252 ) {
V_14 -> V_27 . type = V_252 ;
F_35 ( V_24 ) ;
}
F_172 ( & V_209 -> V_394 . V_395 ) ;
F_283 ( V_24 , & V_209 -> V_394 . V_421 ) ;
F_180 ( & V_209 -> V_394 . V_395 ) ;
F_263 () ;
F_264 ( V_209 , & V_415 , 1 ) ;
F_265 () ;
return 0 ;
V_419:
F_284 ( V_24 ) ;
V_130:
return V_92 ;
}
static int F_285 ( struct V_247 * V_23 , struct V_248 * V_249 , T_7 V_173 ,
int V_46 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_422 , V_92 ;
int V_370 = 0 ;
unsigned int V_307 = 0 ;
V_92 = - V_223 ;
if ( V_46 & ~ ( V_423 | V_354 | V_424 | V_425 | V_426 ) )
goto V_130;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_46 & V_426 ) {
V_92 = F_286 ( V_24 , V_249 , V_173 ,
V_427 , V_428 ) ;
goto V_130;
}
V_2 = F_287 ( V_24 , V_46 , V_46 & V_354 , & V_92 ) ;
if ( V_2 == NULL )
goto V_130;
if ( F_36 ( V_24 ) -> V_374 ) {
struct V_368 V_369 = { 0 } ;
V_92 = - V_223 ;
V_370 = sizeof( V_369 ) ;
if ( V_173 < V_370 )
goto V_274;
V_173 -= V_370 ;
if ( F_288 ( V_2 ) ) {
struct V_429 * V_430 = F_209 ( V_2 ) ;
V_369 . V_379 =
F_256 ( false , F_289 ( V_2 ) ) ;
V_369 . V_389 =
F_256 ( false , V_430 -> V_389 ) ;
if ( V_430 -> V_371 & V_383 )
V_369 . V_371 = V_382 ;
else if ( V_430 -> V_371 & V_385 )
V_369 . V_371 = V_384 ;
else if ( V_430 -> V_371 & V_387 )
V_369 . V_371 = V_386 ;
else if ( V_430 -> V_371 & V_431 )
goto V_274;
else
F_55 () ;
if ( V_430 -> V_371 & V_388 )
V_369 . V_371 |= V_381 ;
} else
V_369 . V_371 = V_380 ;
if ( V_2 -> V_315 == V_316 ) {
V_369 . V_46 = V_376 ;
V_369 . V_377 = F_256 ( false ,
F_290 ( V_2 ) ) ;
V_369 . V_378 = F_256 ( false ,
V_2 -> V_378 ) ;
} else if ( V_2 -> V_315 == V_432 ) {
V_369 . V_46 = V_433 ;
}
V_92 = F_291 ( V_249 , ( void * ) & V_369 , V_370 ) ;
if ( V_92 < 0 )
goto V_274;
}
V_422 = V_2 -> V_173 ;
if ( V_422 > V_173 ) {
V_422 = V_173 ;
V_249 -> V_353 |= V_424 ;
}
V_92 = F_292 ( V_2 , 0 , V_249 , V_422 ) ;
if ( V_92 )
goto V_274;
if ( V_23 -> type != V_410 ) {
struct V_288 * V_289 = & F_190 ( V_2 ) -> V_240 . V_300 ;
V_307 = F_190 ( V_2 ) -> V_240 . V_307 ;
V_289 -> V_330 = V_331 ;
V_289 -> V_332 = V_2 -> V_246 ;
}
F_293 ( V_249 , V_24 , V_2 ) ;
if ( V_249 -> V_251 ) {
if ( V_23 -> type == V_410 ) {
F_294 ( sizeof( struct V_234 ) ) ;
V_249 -> V_254 = sizeof( struct V_234 ) ;
} else {
struct V_288 * V_289 = & F_190 ( V_2 ) -> V_240 . V_300 ;
V_249 -> V_254 = V_289 -> V_305 +
F_244 ( struct V_288 , V_306 ) ;
}
memcpy ( V_249 -> V_251 , & F_190 ( V_2 ) -> V_240 ,
V_249 -> V_254 ) ;
}
if ( F_36 ( V_24 ) -> V_434 ) {
struct V_435 V_436 ;
V_436 . V_40 = V_142 ;
if ( V_2 -> V_315 == V_316 )
V_436 . V_40 |= V_317 ;
else if ( V_2 -> V_236 != V_295 &&
( V_2 -> V_315 == V_318 ||
F_228 ( V_2 ) ) )
V_436 . V_40 |= V_319 ;
V_436 . V_326 = V_307 ;
V_436 . V_327 = V_2 -> V_173 ;
V_436 . V_328 = 0 ;
V_436 . V_329 = F_216 ( V_2 ) ;
if ( F_115 ( V_2 ) ) {
V_436 . V_164 = F_116 ( V_2 ) ;
V_436 . V_165 = F_117 ( V_2 -> V_166 ) ;
V_436 . V_40 |= V_167 | V_168 ;
} else {
V_436 . V_164 = 0 ;
V_436 . V_165 = 0 ;
}
F_295 ( V_249 , V_427 , V_437 , sizeof( V_436 ) , & V_436 ) ;
}
V_92 = V_370 + ( ( V_46 & V_424 ) ? V_2 -> V_173 : V_422 ) ;
V_274:
F_296 ( V_24 , V_2 ) ;
V_130:
return V_92 ;
}
static int F_297 ( struct V_247 * V_23 , struct V_255 * V_402 ,
int * V_438 , int V_439 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_439 )
return - V_440 ;
V_402 -> V_441 = V_331 ;
memset ( V_402 -> V_404 , 0 , sizeof( V_402 -> V_404 ) ) ;
F_20 () ;
V_4 = F_298 ( F_78 ( V_24 ) , F_36 ( V_24 ) -> V_94 ) ;
if ( V_4 )
F_193 ( V_402 -> V_404 , V_4 -> V_244 , sizeof( V_402 -> V_404 ) ) ;
F_24 () ;
* V_438 = sizeof( * V_402 ) ;
return 0 ;
}
static int F_299 ( struct V_247 * V_23 , struct V_255 * V_402 ,
int * V_438 , int V_439 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
F_196 ( struct V_288 * , V_289 , V_402 ) ;
if ( V_439 )
return - V_440 ;
V_289 -> V_330 = V_331 ;
V_289 -> V_304 = V_14 -> V_94 ;
V_289 -> V_332 = V_14 -> V_193 ;
V_289 -> V_302 = 0 ;
F_20 () ;
V_4 = F_298 ( F_78 ( V_24 ) , V_14 -> V_94 ) ;
if ( V_4 ) {
V_289 -> V_301 = V_4 -> type ;
V_289 -> V_305 = V_4 -> V_403 ;
memcpy ( V_289 -> V_306 , V_4 -> V_442 , V_4 -> V_403 ) ;
} else {
V_289 -> V_301 = 0 ;
V_289 -> V_305 = 0 ;
}
F_24 () ;
* V_438 = F_244 ( struct V_288 , V_306 ) + V_289 -> V_305 ;
return 0 ;
}
static int F_300 ( struct V_3 * V_4 , struct V_443 * V_199 ,
int V_444 )
{
switch ( V_199 -> type ) {
case V_445 :
if ( V_199 -> V_446 != V_4 -> V_403 )
return - V_223 ;
if ( V_444 > 0 )
return F_301 ( V_4 , V_199 -> V_31 ) ;
else
return F_302 ( V_4 , V_199 -> V_31 ) ;
break;
case V_447 :
return F_303 ( V_4 , V_444 ) ;
case V_448 :
return F_304 ( V_4 , V_444 ) ;
case V_449 :
if ( V_199 -> V_446 != V_4 -> V_403 )
return - V_223 ;
if ( V_444 > 0 )
return F_305 ( V_4 , V_199 -> V_31 ) ;
else
return F_306 ( V_4 , V_199 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_307 ( struct V_3 * V_4 ,
struct V_443 * * V_450 )
{
struct V_443 * V_451 ;
while ( ( V_451 = * V_450 ) != NULL ) {
if ( V_451 -> V_94 == V_4 -> V_94 ) {
F_300 ( V_4 , V_451 , - 1 ) ;
* V_450 = V_451 -> V_201 ;
F_185 ( V_451 ) ;
} else
V_450 = & V_451 -> V_201 ;
}
}
static int F_308 ( struct V_23 * V_24 , struct V_452 * V_453 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_443 * V_451 , * V_199 ;
struct V_3 * V_4 ;
int V_92 ;
F_76 () ;
V_92 = - V_258 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_453 -> V_454 ) ;
if ( ! V_4 )
goto V_455;
V_92 = - V_223 ;
if ( V_453 -> V_456 > V_4 -> V_403 )
goto V_455;
V_92 = - V_182 ;
V_199 = F_309 ( sizeof( * V_199 ) , V_227 ) ;
if ( V_199 == NULL )
goto V_455;
V_92 = 0 ;
for ( V_451 = V_14 -> V_457 ; V_451 ; V_451 = V_451 -> V_201 ) {
if ( V_451 -> V_94 == V_453 -> V_454 &&
V_451 -> type == V_453 -> V_458 &&
V_451 -> V_446 == V_453 -> V_456 &&
memcmp ( V_451 -> V_31 , V_453 -> V_459 , V_451 -> V_446 ) == 0 ) {
V_451 -> V_460 ++ ;
F_185 ( V_199 ) ;
goto V_455;
}
}
V_199 -> type = V_453 -> V_458 ;
V_199 -> V_94 = V_453 -> V_454 ;
V_199 -> V_446 = V_453 -> V_456 ;
memcpy ( V_199 -> V_31 , V_453 -> V_459 , V_199 -> V_446 ) ;
V_199 -> V_460 = 1 ;
V_199 -> V_201 = V_14 -> V_457 ;
V_14 -> V_457 = V_199 ;
V_92 = F_300 ( V_4 , V_199 , 1 ) ;
if ( V_92 ) {
V_14 -> V_457 = V_199 -> V_201 ;
F_185 ( V_199 ) ;
}
V_455:
F_79 () ;
return V_92 ;
}
static int F_310 ( struct V_23 * V_24 , struct V_452 * V_453 )
{
struct V_443 * V_451 , * * V_450 ;
F_76 () ;
for ( V_450 = & F_36 ( V_24 ) -> V_457 ; ( V_451 = * V_450 ) != NULL ; V_450 = & V_451 -> V_201 ) {
if ( V_451 -> V_94 == V_453 -> V_454 &&
V_451 -> type == V_453 -> V_458 &&
V_451 -> V_446 == V_453 -> V_456 &&
memcmp ( V_451 -> V_31 , V_453 -> V_459 , V_451 -> V_446 ) == 0 ) {
if ( -- V_451 -> V_460 == 0 ) {
struct V_3 * V_4 ;
* V_450 = V_451 -> V_201 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_451 -> V_94 ) ;
if ( V_4 )
F_300 ( V_4 , V_451 , - 1 ) ;
F_185 ( V_451 ) ;
}
break;
}
}
F_79 () ;
return 0 ;
}
static void F_266 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_443 * V_451 ;
if ( ! V_14 -> V_457 )
return;
F_76 () ;
while ( ( V_451 = V_14 -> V_457 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_457 = V_451 -> V_201 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_451 -> V_94 ) ;
if ( V_4 != NULL )
F_300 ( V_4 , V_451 , - 1 ) ;
F_185 ( V_451 ) ;
}
F_79 () ;
}
static int
F_311 ( struct V_247 * V_23 , int V_461 , int V_462 , char T_10 * V_463 , unsigned int V_464 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_8 ;
if ( V_461 != V_427 )
return - V_465 ;
switch ( V_462 ) {
case V_466 :
case V_467 :
{
struct V_452 V_453 ;
int V_173 = V_464 ;
memset ( & V_453 , 0 , sizeof( V_453 ) ) ;
if ( V_173 < sizeof( struct V_468 ) )
return - V_223 ;
if ( V_173 > sizeof( V_453 ) )
V_173 = sizeof( V_453 ) ;
if ( F_312 ( & V_453 , V_463 , V_173 ) )
return - V_350 ;
if ( V_173 < ( V_453 . V_456 + F_244 ( struct V_468 , V_459 ) ) )
return - V_223 ;
if ( V_462 == V_466 )
V_8 = F_308 ( V_24 , & V_453 ) ;
else
V_8 = F_310 ( V_24 , & V_453 ) ;
return V_8 ;
}
case V_469 :
case V_470 :
{
union V_99 V_100 ;
int V_173 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_173 = sizeof( V_100 . V_471 ) ;
break;
case V_43 :
default:
V_173 = sizeof( V_100 . V_102 ) ;
break;
}
if ( V_464 < V_173 )
return - V_223 ;
if ( F_36 ( V_24 ) -> V_374 )
return - V_223 ;
if ( F_312 ( & V_100 . V_471 , V_463 , V_173 ) )
return - V_350 ;
return F_267 ( V_24 , & V_100 , 0 ,
V_462 == V_470 ) ;
}
case V_472 :
{
int V_473 ;
if ( V_464 != sizeof( V_473 ) )
return - V_223 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
F_36 ( V_24 ) -> V_322 = V_473 ;
return 0 ;
}
case V_474 :
{
int V_473 ;
if ( V_464 != sizeof( V_473 ) )
return - V_223 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_475 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
switch ( V_473 ) {
case V_38 :
case V_41 :
case V_43 :
V_14 -> V_37 = V_473 ;
return 0 ;
default:
return - V_223 ;
}
}
case V_476 :
{
unsigned int V_473 ;
if ( V_464 != sizeof( V_473 ) )
return - V_223 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_475 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
V_14 -> V_320 = V_473 ;
return 0 ;
}
case V_477 :
{
unsigned int V_473 ;
if ( V_464 != sizeof( V_473 ) )
return - V_223 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_475 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
V_14 -> V_361 = ! ! V_473 ;
return 0 ;
}
case V_437 :
{
int V_473 ;
if ( V_464 < sizeof( V_473 ) )
return - V_223 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
V_14 -> V_434 = ! ! V_473 ;
return 0 ;
}
case V_478 :
{
int V_473 ;
if ( V_464 < sizeof( V_473 ) )
return - V_223 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
V_14 -> V_303 = ! ! V_473 ;
return 0 ;
}
case V_479 :
{
int V_473 ;
if ( V_23 -> type != V_373 )
return - V_223 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_475 ;
if ( V_464 < sizeof( V_473 ) )
return - V_223 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
V_14 -> V_374 = ! ! V_473 ;
return 0 ;
}
case V_480 :
{
int V_473 ;
if ( V_464 != sizeof( V_473 ) )
return - V_223 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
V_14 -> V_55 = V_473 ;
return 0 ;
}
case V_481 :
{
int V_473 ;
if ( V_464 != sizeof( V_473 ) )
return - V_223 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
return F_171 ( V_24 , V_473 & 0xffff , V_473 >> 16 ) ;
}
case V_482 :
{
unsigned int V_473 ;
if ( V_464 != sizeof( V_473 ) )
return - V_223 ;
if ( V_14 -> V_78 . V_68 || V_14 -> V_75 . V_68 )
return - V_475 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
V_14 -> V_344 = ! ! V_473 ;
return 0 ;
}
case V_483 :
{
int V_473 ;
if ( V_464 != sizeof( V_473 ) )
return - V_223 ;
if ( F_312 ( & V_473 , V_463 , sizeof( V_473 ) ) )
return - V_350 ;
V_14 -> V_16 = V_473 ? F_1 : F_211 ;
return 0 ;
}
default:
return - V_465 ;
}
}
static int F_313 ( struct V_247 * V_23 , int V_461 , int V_462 ,
char T_10 * V_463 , int T_10 * V_464 )
{
int V_173 ;
int V_473 , V_484 = sizeof( V_473 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
void * V_81 = & V_473 ;
union V_485 V_486 ;
if ( V_461 != V_427 )
return - V_465 ;
if ( F_314 ( V_173 , V_464 ) )
return - V_350 ;
if ( V_173 < 0 )
return - V_223 ;
switch ( V_462 ) {
case V_487 :
F_69 ( & V_24 -> V_129 . V_79 ) ;
memcpy ( & V_486 , & V_14 -> V_118 , sizeof( V_486 ) ) ;
memset ( & V_14 -> V_118 , 0 , sizeof( V_14 -> V_118 ) ) ;
F_70 ( & V_24 -> V_129 . V_79 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_484 = sizeof( struct V_488 ) ;
V_486 . V_119 . V_309 += V_486 . V_119 . V_148 ;
V_81 = & V_486 . V_119 ;
} else {
V_484 = sizeof( struct V_489 ) ;
V_486 . V_308 . V_309 += V_486 . V_308 . V_148 ;
V_81 = & V_486 . V_308 ;
}
break;
case V_437 :
V_473 = V_14 -> V_434 ;
break;
case V_478 :
V_473 = V_14 -> V_303 ;
break;
case V_479 :
V_473 = V_14 -> V_374 ;
break;
case V_474 :
V_473 = V_14 -> V_37 ;
break;
case V_490 :
if ( V_173 > sizeof( int ) )
V_173 = sizeof( int ) ;
if ( F_312 ( & V_473 , V_463 , V_173 ) )
return - V_350 ;
switch ( V_473 ) {
case V_38 :
V_473 = sizeof( struct V_491 ) ;
break;
case V_41 :
V_473 = sizeof( struct V_492 ) ;
break;
case V_43 :
V_473 = sizeof( struct V_143 ) ;
break;
default:
return - V_223 ;
}
break;
case V_476 :
V_473 = V_14 -> V_320 ;
break;
case V_477 :
V_473 = V_14 -> V_361 ;
break;
case V_480 :
V_473 = V_14 -> V_55 ;
break;
case V_481 :
V_473 = ( V_14 -> V_26 ?
( ( T_5 ) V_14 -> V_26 -> V_220 |
( ( T_5 ) V_14 -> V_26 -> type << 16 ) |
( ( T_5 ) V_14 -> V_26 -> V_46 << 24 ) ) :
0 ) ;
break;
case V_482 :
V_473 = V_14 -> V_344 ;
break;
case V_483 :
V_473 = F_29 ( V_14 ) ;
break;
default:
return - V_465 ;
}
if ( V_173 > V_484 )
V_173 = V_484 ;
if ( F_315 ( V_173 , V_464 ) )
return - V_350 ;
if ( F_316 ( V_463 , V_81 , V_173 ) )
return - V_350 ;
return 0 ;
}
static int F_317 ( struct V_493 * V_494 ,
unsigned long V_249 , void * V_495 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_318 ( V_495 ) ;
struct V_209 * V_209 = F_166 ( V_4 ) ;
F_20 () ;
F_319 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_36 ( V_24 ) ;
switch ( V_249 ) {
case V_496 :
if ( V_14 -> V_457 )
F_307 ( V_4 , & V_14 -> V_457 ) ;
case V_497 :
if ( V_4 -> V_94 == V_14 -> V_94 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_40 ( V_24 , false ) ;
V_24 -> V_400 = V_260 ;
if ( ! F_148 ( V_24 , V_190 ) )
V_24 -> V_401 ( V_24 ) ;
}
if ( V_249 == V_496 ) {
F_27 ( V_14 ) ;
V_14 -> V_94 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_250 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
}
break;
case V_498 :
if ( V_4 -> V_94 == V_14 -> V_94 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_193 )
F_35 ( V_24 ) ;
F_44 ( & V_14 -> V_29 ) ;
}
break;
}
}
F_24 () ;
return V_499 ;
}
static int F_320 ( struct V_247 * V_23 , unsigned int V_500 ,
unsigned long V_501 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_500 ) {
case V_502 :
{
int V_503 = F_321 ( V_24 ) ;
return F_315 ( V_503 , ( int T_10 * ) V_501 ) ;
}
case V_504 :
{
struct V_1 * V_2 ;
int V_503 = 0 ;
F_69 ( & V_24 -> V_129 . V_79 ) ;
V_2 = F_322 ( & V_24 -> V_129 ) ;
if ( V_2 )
V_503 = V_2 -> V_173 ;
F_70 ( & V_24 -> V_129 . V_79 ) ;
return F_315 ( V_503 , ( int T_10 * ) V_501 ) ;
}
case V_505 :
return F_323 ( V_24 , (struct V_506 T_10 * ) V_501 ) ;
case V_507 :
return F_324 ( V_24 , (struct V_44 T_10 * ) V_501 ) ;
#ifdef F_325
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
case V_520 :
case V_521 :
return V_522 . V_523 ( V_23 , V_500 , V_501 ) ;
#endif
default:
return - V_524 ;
}
return 0 ;
}
static unsigned int F_326 ( struct V_525 * V_525 , struct V_247 * V_23 ,
T_11 * V_526 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned int V_527 = F_327 ( V_525 , V_23 , V_526 ) ;
F_69 ( & V_24 -> V_129 . V_79 ) ;
if ( V_14 -> V_78 . V_68 ) {
if ( ! F_129 ( V_14 , & V_14 -> V_78 ,
V_160 ) )
V_527 |= V_528 | V_529 ;
}
F_70 ( & V_24 -> V_129 . V_79 ) ;
F_69 ( & V_24 -> V_530 . V_79 ) ;
if ( V_14 -> V_75 . V_68 ) {
if ( F_64 ( V_14 , & V_14 -> V_75 , V_169 ) )
V_527 |= V_531 | V_532 ;
}
F_70 ( & V_24 -> V_530 . V_79 ) ;
return V_527 ;
}
static void F_328 ( struct V_533 * V_534 )
{
struct V_525 * V_525 = V_534 -> V_535 ;
struct V_247 * V_23 = V_525 -> V_536 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_121 ( & F_36 ( V_24 ) -> V_537 ) ;
}
static void F_329 ( struct V_533 * V_534 )
{
struct V_525 * V_525 = V_534 -> V_535 ;
struct V_247 * V_23 = V_525 -> V_536 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_110 ( & F_36 ( V_24 ) -> V_537 ) ;
}
static void F_330 ( struct V_104 * V_68 , unsigned int V_538 ,
unsigned int V_173 )
{
int V_199 ;
for ( V_199 = 0 ; V_199 < V_173 ; V_199 ++ ) {
if ( F_22 ( V_68 [ V_199 ] . V_69 ) ) {
if ( F_49 ( V_68 [ V_199 ] . V_69 ) )
F_331 ( V_68 [ V_199 ] . V_69 ) ;
else
F_332 ( ( unsigned long ) V_68 [ V_199 ] . V_69 ,
V_538 ) ;
V_68 [ V_199 ] . V_69 = NULL ;
}
}
F_185 ( V_68 ) ;
}
static char * F_333 ( unsigned long V_538 )
{
char * V_69 ;
T_12 V_539 = V_227 | V_540 |
V_541 | V_542 | V_543 ;
V_69 = ( char * ) F_334 ( V_539 , V_538 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_335 ( ( 1 << V_538 ) * V_139 ) ;
if ( V_69 )
return V_69 ;
V_539 &= ~ V_543 ;
V_69 = ( char * ) F_334 ( V_539 , V_538 ) ;
if ( V_69 )
return V_69 ;
return NULL ;
}
static struct V_104 * F_336 ( struct V_544 * V_471 , int V_538 )
{
unsigned int V_545 = V_471 -> V_113 ;
struct V_104 * V_68 ;
int V_199 ;
V_68 = F_337 ( V_545 , sizeof( struct V_104 ) , V_227 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
for ( V_199 = 0 ; V_199 < V_545 ; V_199 ++ ) {
V_68 [ V_199 ] . V_69 = F_333 ( V_538 ) ;
if ( F_2 ( ! V_68 [ V_199 ] . V_69 ) )
goto V_546;
}
V_130:
return V_68 ;
V_546:
F_330 ( V_68 , V_538 , V_545 ) ;
V_68 = NULL ;
goto V_130;
}
static int F_267 ( struct V_23 * V_24 , union V_99 * V_100 ,
int V_547 , int V_75 )
{
struct V_104 * V_68 = NULL ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_548 , V_538 = 0 ;
struct V_62 * V_63 ;
struct V_76 * V_77 ;
T_8 V_193 ;
int V_92 = - V_223 ;
struct V_544 * V_471 = & V_100 -> V_471 ;
if ( ! V_547 && V_75 && ( V_14 -> V_37 > V_41 ) ) {
F_54 ( 1 , L_8 ) ;
goto V_130;
}
V_63 = V_75 ? & V_14 -> V_75 : & V_14 -> V_78 ;
V_77 = V_75 ? & V_24 -> V_530 : & V_24 -> V_129 ;
V_92 = - V_475 ;
if ( ! V_547 ) {
if ( F_92 ( & V_14 -> V_537 ) )
goto V_130;
if ( F_137 ( V_63 ) )
goto V_130;
}
if ( V_471 -> V_113 ) {
V_92 = - V_475 ;
if ( F_2 ( V_63 -> V_68 ) )
goto V_130;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_115 = V_549 ;
break;
case V_41 :
V_14 -> V_115 = V_550 ;
break;
case V_43 :
V_14 -> V_115 = V_551 ;
break;
}
V_92 = - V_223 ;
if ( F_2 ( ( int ) V_471 -> V_111 <= 0 ) )
goto V_130;
if ( F_2 ( V_471 -> V_111 & ( V_139 - 1 ) ) )
goto V_130;
if ( V_14 -> V_37 >= V_43 &&
( int ) ( V_471 -> V_111 -
F_85 ( V_100 -> V_102 . V_125 ) ) <= 0 )
goto V_130;
if ( F_2 ( V_471 -> V_552 < V_14 -> V_115 +
V_14 -> V_320 ) )
goto V_130;
if ( F_2 ( V_471 -> V_552 & ( V_553 - 1 ) ) )
goto V_130;
V_63 -> V_67 = V_471 -> V_111 / V_471 -> V_552 ;
if ( F_2 ( V_63 -> V_67 <= 0 ) )
goto V_130;
if ( F_2 ( ( V_63 -> V_67 * V_471 -> V_113 ) !=
V_471 -> V_554 ) )
goto V_130;
V_92 = - V_226 ;
V_538 = F_338 ( V_471 -> V_111 ) ;
V_68 = F_336 ( V_471 , V_538 ) ;
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
V_92 = - V_223 ;
if ( F_2 ( V_471 -> V_554 ) )
goto V_130;
}
F_272 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_548 = V_14 -> V_25 ;
V_193 = V_14 -> V_193 ;
if ( V_548 ) {
V_14 -> V_193 = 0 ;
F_40 ( V_24 , false ) ;
}
F_44 ( & V_14 -> V_29 ) ;
F_45 () ;
V_92 = - V_475 ;
F_172 ( & V_14 -> V_356 ) ;
if ( V_547 || F_92 ( & V_14 -> V_537 ) == 0 ) {
V_92 = 0 ;
F_69 ( & V_77 -> V_79 ) ;
F_339 ( V_63 -> V_68 , V_68 ) ;
V_63 -> V_177 = ( V_471 -> V_554 - 1 ) ;
V_63 -> V_71 = 0 ;
V_63 -> V_70 = V_471 -> V_552 ;
F_70 ( & V_77 -> V_79 ) ;
F_339 ( V_63 -> V_555 , V_538 ) ;
F_339 ( V_63 -> V_556 , V_471 -> V_113 ) ;
V_63 -> V_557 = V_471 -> V_111 / V_139 ;
V_14 -> V_27 . F_72 = ( V_14 -> V_78 . V_68 ) ?
V_184 : F_214 ;
F_146 ( V_77 ) ;
if ( F_92 ( & V_14 -> V_537 ) )
F_149 ( L_9 ,
F_92 ( & V_14 -> V_537 ) ) ;
}
F_180 ( & V_14 -> V_356 ) ;
F_46 ( & V_14 -> V_29 ) ;
if ( V_548 ) {
V_14 -> V_193 = V_193 ;
F_35 ( V_24 ) ;
}
F_44 ( & V_14 -> V_29 ) ;
if ( V_547 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_75 )
F_67 ( V_14 , V_75 , V_77 ) ;
}
F_273 ( V_24 ) ;
if ( V_68 )
F_330 ( V_68 , V_538 , V_471 -> V_113 ) ;
V_130:
return V_92 ;
}
static int F_340 ( struct V_525 * V_525 , struct V_247 * V_23 ,
struct V_533 * V_534 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned long V_558 , V_559 ;
struct V_62 * V_63 ;
unsigned long V_137 ;
int V_92 = - V_223 ;
int V_199 ;
if ( V_534 -> V_560 )
return - V_223 ;
F_172 ( & V_14 -> V_356 ) ;
V_559 = 0 ;
for ( V_63 = & V_14 -> V_78 ; V_63 <= & V_14 -> V_75 ; V_63 ++ ) {
if ( V_63 -> V_68 ) {
V_559 += V_63 -> V_556
* V_63 -> V_557
* V_139 ;
}
}
if ( V_559 == 0 )
goto V_130;
V_558 = V_534 -> V_561 - V_534 -> V_562 ;
if ( V_558 != V_559 )
goto V_130;
V_137 = V_534 -> V_562 ;
for ( V_63 = & V_14 -> V_78 ; V_63 <= & V_14 -> V_75 ; V_63 ++ ) {
if ( V_63 -> V_68 == NULL )
continue;
for ( V_199 = 0 ; V_199 < V_63 -> V_556 ; V_199 ++ ) {
struct V_30 * V_30 ;
void * V_563 = V_63 -> V_68 [ V_199 ] . V_69 ;
int V_564 ;
for ( V_564 = 0 ; V_564 < V_63 -> V_557 ; V_564 ++ ) {
V_30 = F_48 ( V_563 ) ;
V_92 = F_341 ( V_534 , V_137 , V_30 ) ;
if ( F_2 ( V_92 ) )
goto V_130;
V_137 += V_139 ;
V_563 += V_139 ;
}
}
}
F_121 ( & V_14 -> V_537 ) ;
V_534 -> V_565 = & V_566 ;
V_92 = 0 ;
V_130:
F_180 ( & V_14 -> V_356 ) ;
return V_92 ;
}
static void * F_342 ( struct V_567 * V_568 , T_13 * V_569 )
__acquires( T_14 )
{
struct V_209 * V_209 = F_343 ( V_568 ) ;
F_20 () ;
return F_344 ( & V_209 -> V_394 . V_421 , * V_569 ) ;
}
static void * F_345 ( struct V_567 * V_568 , void * V_570 , T_13 * V_569 )
{
struct V_209 * V_209 = F_343 ( V_568 ) ;
return F_346 ( V_570 , & V_209 -> V_394 . V_421 , V_569 ) ;
}
static void F_347 ( struct V_567 * V_568 , void * V_570 )
__releases( T_14 )
{
F_24 () ;
}
static int F_348 ( struct V_567 * V_568 , void * V_570 )
{
if ( V_570 == V_571 )
F_349 ( V_568 , L_10 ) ;
else {
struct V_23 * V_390 = F_350 ( V_570 ) ;
const struct V_13 * V_14 = F_36 ( V_390 ) ;
F_351 ( V_568 ,
L_11 ,
V_390 ,
F_92 ( & V_390 -> V_572 ) ,
V_390 -> V_293 ,
F_117 ( V_14 -> V_193 ) ,
V_14 -> V_94 ,
V_14 -> V_25 ,
F_92 ( & V_390 -> V_185 ) ,
F_352 ( F_353 ( V_568 ) , F_354 ( V_390 ) ) ,
F_355 ( V_390 ) ) ;
}
return 0 ;
}
static int F_356 ( struct V_573 * V_573 , struct V_525 * V_525 )
{
return F_357 ( V_573 , V_525 , & V_574 ,
sizeof( struct V_575 ) ) ;
}
static int T_15 F_358 ( struct V_209 * V_209 )
{
F_282 ( & V_209 -> V_394 . V_395 ) ;
F_359 ( & V_209 -> V_394 . V_421 ) ;
if ( ! F_360 ( L_12 , 0 , V_209 -> V_576 , & V_577 ) )
return - V_226 ;
return 0 ;
}
static void T_16 F_361 ( struct V_209 * V_209 )
{
F_362 ( L_12 , V_209 -> V_576 ) ;
}
static void T_17 F_363 ( void )
{
F_364 ( & V_578 ) ;
F_365 ( & V_579 ) ;
F_366 ( V_414 ) ;
F_367 ( & V_415 ) ;
}
static int T_18 F_368 ( void )
{
int V_580 = F_369 ( & V_415 , 0 ) ;
if ( V_580 != 0 )
goto V_130;
F_370 ( & V_581 ) ;
F_371 ( & V_579 ) ;
F_372 ( & V_578 ) ;
V_130:
return V_580 ;
}
