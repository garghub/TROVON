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
F_76 () ;
V_4 = F_77 ( F_78 ( & V_14 -> V_24 ) , V_14 -> V_92 ) ;
if ( F_2 ( ! V_4 ) ) {
F_79 () ;
return V_93 ;
}
V_91 = F_80 ( V_4 , & V_90 ) ;
F_79 () ;
if ( ! V_91 ) {
if ( V_90 . V_94 . V_95 < V_96 ||
V_90 . V_94 . V_95 == V_97 ) {
return V_93 ;
} else {
V_87 = 1 ;
div = V_90 . V_94 . V_95 / 1000 ;
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
static void F_81 ( struct V_72 * V_98 ,
union V_99 * V_100 )
{
V_98 -> V_101 = V_100 -> V_102 . V_103 ;
}
static void F_82 ( struct V_13 * V_14 ,
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
V_98 -> V_123 = F_83 ( V_98 -> V_122 ) ;
V_98 -> V_124 = V_100 -> V_102 . V_125 ;
V_98 -> V_126 = V_98 -> V_110 - F_84 ( V_98 -> V_124 ) ;
F_81 ( V_98 , V_100 ) ;
F_74 ( V_14 ) ;
F_85 ( V_98 , V_106 ) ;
}
static void F_86 ( struct V_72 * V_73 )
{
F_87 ( & V_73 -> V_74 ,
V_83 + V_73 -> V_123 ) ;
V_73 -> V_117 = V_73 -> V_127 ;
}
static void V_84 ( unsigned long V_80 )
{
struct V_13 * V_14 = (struct V_13 * ) V_80 ;
struct V_72 * V_73 = F_68 ( & V_14 -> V_77 ) ;
unsigned int V_128 ;
struct V_105 * V_106 ;
F_46 ( & V_14 -> V_24 . V_129 . V_78 ) ;
V_128 = F_88 ( V_73 ) ;
V_106 = F_89 ( V_73 ) ;
if ( F_2 ( V_73 -> V_79 ) )
goto V_130;
if ( F_90 ( V_106 ) ) {
while ( F_91 ( & V_73 -> V_131 ) ) {
F_92 () ;
}
}
if ( V_73 -> V_117 == V_73 -> V_127 ) {
if ( ! V_128 ) {
if ( ! F_90 ( V_106 ) ) {
goto V_132;
}
F_93 ( V_73 , V_14 , V_133 ) ;
if ( ! F_94 ( V_73 , V_14 ) )
goto V_132;
else
goto V_130;
} else {
if ( F_95 ( V_73 , V_106 ) ) {
goto V_132;
} else {
F_85 ( V_73 , V_106 ) ;
goto V_130;
}
}
}
V_132:
F_86 ( V_73 ) ;
V_130:
F_44 ( & V_14 -> V_24 . V_129 . V_78 ) ;
}
static void F_96 ( struct V_72 * V_134 ,
struct V_105 * V_135 , T_4 V_33 )
{
#if V_136 == 1
T_5 * V_137 , * V_138 ;
V_137 = ( T_5 * ) V_135 ;
V_137 += V_139 ;
V_138 = ( T_5 * ) F_97 ( ( unsigned long ) V_134 -> V_140 ) ;
for (; V_137 < V_138 ; V_137 += V_139 )
F_53 ( F_48 ( V_137 ) ) ;
F_56 () ;
#endif
F_98 ( V_135 ) = V_33 ;
#if V_136 == 1
V_137 = ( T_5 * ) V_135 ;
F_53 ( F_48 ( V_137 ) ) ;
F_56 () ;
#endif
}
static void F_99 ( struct V_72 * V_134 ,
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
if ( F_90 ( V_135 ) ) {
V_39 -> V_152 . V_153 = V_144 -> V_56 ;
V_39 -> V_152 . V_154 = V_144 -> V_61 ;
} else {
struct V_44 V_45 ;
F_100 ( & V_45 ) ;
V_39 -> V_152 . V_153 = V_45 . V_57 ;
V_39 -> V_152 . V_154 = V_45 . V_59 ;
}
F_56 () ;
F_96 ( V_134 , V_135 , V_33 ) ;
V_24 -> V_155 ( V_24 ) ;
V_134 -> V_127 = F_101 ( V_134 ) ;
}
static void F_102 ( struct V_72 * V_73 )
{
V_73 -> V_156 = 0 ;
}
static void F_85 ( struct V_72 * V_134 ,
struct V_105 * V_135 )
{
struct V_44 V_45 ;
struct V_145 * V_39 = & V_135 -> V_146 . V_147 ;
F_58 () ;
F_103 ( V_135 ) = V_134 -> V_107 ++ ;
F_90 ( V_135 ) = 0 ;
F_104 ( V_135 ) = F_84 ( V_134 -> V_124 ) ;
F_100 ( & V_45 ) ;
V_39 -> V_157 . V_153 = V_45 . V_57 ;
V_39 -> V_157 . V_154 = V_45 . V_59 ;
V_134 -> V_109 = ( char * ) V_135 ;
V_134 -> V_158 = V_134 -> V_109 + F_84 ( V_134 -> V_124 ) ;
F_105 ( V_135 ) = ( T_4 ) F_84 ( V_134 -> V_124 ) ;
F_106 ( V_135 ) = V_159 ;
V_135 -> V_116 = V_134 -> V_116 ;
V_134 -> V_150 = V_134 -> V_158 ;
V_134 -> V_140 = V_134 -> V_109 + V_134 -> V_110 ;
F_102 ( V_134 ) ;
F_86 ( V_134 ) ;
F_56 () ;
}
static void F_107 ( struct V_72 * V_73 ,
struct V_13 * V_14 )
{
V_73 -> V_156 = 1 ;
V_14 -> V_118 . V_119 . V_120 ++ ;
}
static void * F_94 ( struct V_72 * V_73 ,
struct V_13 * V_14 )
{
struct V_105 * V_106 ;
F_58 () ;
V_106 = F_89 ( V_73 ) ;
if ( V_142 & F_98 ( V_106 ) ) {
F_107 ( V_73 , V_14 ) ;
return NULL ;
}
F_85 ( V_73 , V_106 ) ;
return ( void * ) V_73 -> V_158 ;
}
static void F_93 ( struct V_72 * V_73 ,
struct V_13 * V_14 , unsigned int V_33 )
{
struct V_105 * V_106 = F_89 ( V_73 ) ;
if ( F_22 ( V_160 == F_98 ( V_106 ) ) ) {
if ( ! ( V_33 & V_133 ) ) {
while ( F_91 ( & V_73 -> V_131 ) ) {
F_92 () ;
}
}
F_99 ( V_73 , V_106 , V_14 , V_33 ) ;
return;
}
}
static int F_95 ( struct V_72 * V_73 ,
struct V_105 * V_106 )
{
return V_142 & F_98 ( V_106 ) ;
}
static int F_88 ( struct V_72 * V_73 )
{
return V_73 -> V_156 ;
}
static void F_108 ( struct V_62 * V_63 )
{
struct V_72 * V_73 = F_68 ( V_63 ) ;
F_109 ( & V_73 -> V_131 ) ;
}
static void F_110 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
V_161 -> V_162 . V_163 = F_111 ( V_73 -> V_2 ) ;
}
static void F_112 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
V_161 -> V_162 . V_163 = 0 ;
}
static void F_113 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
if ( F_114 ( V_73 -> V_2 ) ) {
V_161 -> V_162 . V_164 = F_115 ( V_73 -> V_2 ) ;
V_161 -> V_162 . V_165 = F_116 ( V_73 -> V_2 -> V_166 ) ;
V_161 -> V_40 = V_167 | V_168 ;
} else {
V_161 -> V_162 . V_164 = 0 ;
V_161 -> V_162 . V_165 = 0 ;
V_161 -> V_40 = V_169 ;
}
}
static void F_117 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
V_161 -> V_162 . V_170 = 0 ;
F_113 ( V_73 , V_161 ) ;
if ( V_73 -> V_101 & V_171 )
F_110 ( V_73 , V_161 ) ;
else
F_112 ( V_73 , V_161 ) ;
}
static void F_118 ( char * V_172 ,
struct V_72 * V_73 ,
struct V_105 * V_106 ,
unsigned int V_173 )
{
struct V_143 * V_161 ;
V_161 = (struct V_143 * ) V_172 ;
V_161 -> V_151 = F_119 ( V_173 ) ;
V_73 -> V_150 = V_172 ;
V_73 -> V_158 += F_119 ( V_173 ) ;
F_104 ( V_106 ) += F_119 ( V_173 ) ;
F_90 ( V_106 ) += 1 ;
F_120 ( & V_73 -> V_131 ) ;
F_117 ( V_73 , V_161 ) ;
}
static void * F_121 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 ,
unsigned int V_173
)
{
struct V_72 * V_73 ;
struct V_105 * V_106 ;
char * V_172 , * V_138 ;
V_73 = F_68 ( & V_14 -> V_77 ) ;
V_106 = F_89 ( V_73 ) ;
if ( F_88 ( V_73 ) ) {
if ( F_95 ( V_73 , V_106 ) ) {
return NULL ;
} else {
F_85 ( V_73 , V_106 ) ;
}
}
F_122 () ;
V_172 = V_73 -> V_158 ;
V_73 -> V_2 = V_2 ;
V_138 = ( char * ) V_106 + V_73 -> V_110 ;
if ( V_172 + F_119 ( V_173 ) < V_138 ) {
F_118 ( V_172 , V_73 , V_106 , V_173 ) ;
return ( void * ) V_172 ;
}
F_93 ( V_73 , V_14 , 0 ) ;
V_172 = ( char * ) F_94 ( V_73 , V_14 ) ;
if ( V_172 ) {
V_106 = F_89 ( V_73 ) ;
F_118 ( V_172 , V_73 , V_106 , V_173 ) ;
return ( void * ) V_172 ;
}
return NULL ;
}
static void * F_123 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 , unsigned int V_173 )
{
char * V_172 = NULL ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_172 = F_63 ( V_14 , & V_14 -> V_77 ,
V_14 -> V_77 . V_71 , V_33 ) ;
return V_172 ;
case V_43 :
return F_121 ( V_14 , V_2 , V_33 , V_173 ) ;
default:
F_54 ( 1 , L_2 ) ;
F_55 () ;
return NULL ;
}
}
static void * F_124 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
unsigned int V_174 ,
int V_33 )
{
struct V_72 * V_73 = F_68 ( V_63 ) ;
struct V_105 * V_106 = F_125 ( V_73 , V_174 ) ;
if ( V_33 != F_98 ( V_106 ) )
return NULL ;
return V_106 ;
}
static int F_126 ( struct V_62 * V_63 )
{
unsigned int V_150 ;
if ( V_63 -> V_175 . V_127 )
V_150 = V_63 -> V_175 . V_127 - 1 ;
else
V_150 = V_63 -> V_175 . V_112 - 1 ;
return V_150 ;
}
static void * F_127 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
unsigned int V_176 = F_126 ( V_63 ) ;
return F_124 ( V_14 , V_63 , V_176 , V_33 ) ;
}
static void * F_128 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
if ( V_14 -> V_37 <= V_41 )
return F_129 ( V_14 , V_63 , V_33 ) ;
return F_127 ( V_14 , V_63 , V_33 ) ;
}
static void F_130 ( struct V_13 * V_14 ,
struct V_62 * V_63 )
{
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
return F_131 ( V_63 ) ;
case V_43 :
default:
F_54 ( 1 , L_1 ) ;
F_55 () ;
return;
}
}
static void * F_129 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
unsigned int V_176 = V_63 -> V_71 ? V_63 -> V_71 - 1 : V_63 -> V_177 ;
return F_63 ( V_14 , V_63 , V_176 , V_33 ) ;
}
static void F_131 ( struct V_62 * V_178 )
{
V_178 -> V_71 = V_178 -> V_71 != V_178 -> V_177 ? V_178 -> V_71 + 1 : 0 ;
}
static void F_132 ( struct V_62 * V_63 )
{
F_133 ( * V_63 -> V_179 ) ;
}
static void F_134 ( struct V_62 * V_63 )
{
F_135 ( * V_63 -> V_179 ) ;
}
static unsigned int F_136 ( const struct V_62 * V_63 )
{
unsigned int V_180 = 0 ;
int V_181 ;
if ( V_63 -> V_179 == NULL )
return 0 ;
F_137 (cpu)
V_180 += * F_138 ( V_63 -> V_179 , V_181 ) ;
return V_180 ;
}
static int F_139 ( struct V_13 * V_14 )
{
V_14 -> V_77 . V_179 = NULL ;
V_14 -> V_182 . V_179 = F_140 (unsigned int) ;
if ( F_2 ( V_14 -> V_182 . V_179 == NULL ) )
return - V_183 ;
return 0 ;
}
static void F_141 ( struct V_13 * V_14 )
{
F_142 ( V_14 -> V_182 . V_179 ) ;
}
static bool F_143 ( struct V_13 * V_14 , int V_184 )
{
int V_174 , V_173 ;
V_173 = V_14 -> V_77 . V_177 + 1 ;
V_174 = V_14 -> V_77 . V_71 ;
if ( V_184 )
V_174 += V_173 >> V_184 ;
if ( V_174 >= V_173 )
V_174 -= V_173 ;
return F_63 ( V_14 , & V_14 -> V_77 , V_174 , V_160 ) ;
}
static bool F_144 ( struct V_13 * V_14 , int V_184 )
{
int V_174 , V_173 ;
V_173 = V_14 -> V_77 . V_175 . V_112 ;
V_174 = V_14 -> V_77 . V_175 . V_127 ;
if ( V_184 )
V_174 += V_173 >> V_184 ;
if ( V_174 >= V_173 )
V_174 -= V_173 ;
return F_124 ( V_14 , & V_14 -> V_77 , V_174 , V_160 ) ;
}
static int F_145 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_14 -> V_24 ;
int V_8 = V_185 ;
if ( V_14 -> V_27 . F_72 != V_186 ) {
int V_187 = V_24 -> V_188 - F_91 ( & V_24 -> V_189 )
- ( V_2 ? V_2 -> V_190 : 0 ) ;
if ( V_187 > ( V_24 -> V_188 >> V_191 ) )
return V_192 ;
else if ( V_187 > 0 )
return V_193 ;
else
return V_185 ;
}
if ( V_14 -> V_37 == V_43 ) {
if ( F_144 ( V_14 , V_191 ) )
V_8 = V_192 ;
else if ( F_144 ( V_14 , 0 ) )
V_8 = V_193 ;
} else {
if ( F_143 ( V_14 , V_191 ) )
V_8 = V_192 ;
else if ( F_143 ( V_14 , 0 ) )
V_8 = V_193 ;
}
return V_8 ;
}
static int F_146 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
int V_8 ;
bool V_194 ;
F_69 ( & V_14 -> V_24 . V_129 . V_78 ) ;
V_8 = F_145 ( V_14 , V_2 ) ;
V_194 = V_8 == V_192 ;
if ( V_14 -> V_195 == V_194 )
V_14 -> V_195 = ! V_194 ;
F_70 ( & V_14 -> V_24 . V_129 . V_78 ) ;
return V_8 ;
}
static void F_147 ( struct V_23 * V_24 )
{
F_148 ( & V_24 -> V_196 ) ;
F_149 ( F_91 ( & V_24 -> V_189 ) ) ;
F_149 ( F_91 ( & V_24 -> V_197 ) ) ;
if ( ! F_150 ( V_24 , V_198 ) ) {
F_151 ( L_3 , V_24 ) ;
return;
}
F_152 ( V_24 ) ;
}
static bool F_153 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
T_6 V_199 ;
int V_200 , V_201 = 0 ;
V_199 = F_111 ( V_2 ) ;
for ( V_200 = 0 ; V_200 < V_202 ; V_200 ++ )
if ( V_14 -> V_203 -> V_204 [ V_200 ] == V_199 )
V_201 ++ ;
V_14 -> V_203 -> V_204 [ F_154 () % V_202 ] = V_199 ;
return V_201 > ( V_202 >> 1 ) ;
}
static unsigned int F_155 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
return F_156 ( F_111 ( V_2 ) , V_207 ) ;
}
static unsigned int F_157 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
unsigned int V_208 = F_158 ( & V_206 -> V_209 ) ;
return V_208 % V_207 ;
}
static unsigned int F_159 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
return F_11 () % V_207 ;
}
static unsigned int F_160 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
return F_161 ( V_207 ) ;
}
static unsigned int F_162 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_174 , bool V_210 ,
unsigned int V_207 )
{
struct V_13 * V_14 , * V_211 , * V_212 = NULL ;
unsigned int V_200 , V_213 , V_214 = V_185 ;
V_14 = F_36 ( V_206 -> V_215 [ V_174 ] ) ;
if ( V_210 ) {
V_214 = F_146 ( V_14 , V_2 ) ;
if ( V_214 == V_192 ||
( V_214 == V_193 && ! F_153 ( V_14 , V_2 ) ) )
return V_174 ;
V_212 = V_14 ;
}
V_200 = V_213 = F_163 ( int , V_14 -> V_203 -> V_23 , V_207 - 1 ) ;
do {
V_211 = F_36 ( V_206 -> V_215 [ V_200 ] ) ;
if ( V_211 != V_212 && ! V_211 -> V_195 &&
F_146 ( V_211 , V_2 ) == V_192 ) {
if ( V_200 != V_213 )
V_14 -> V_203 -> V_23 = V_200 ;
F_18 ( & V_14 -> V_203 -> V_207 ) ;
if ( V_214 == V_193 )
F_18 ( & V_14 -> V_203 -> V_216 ) ;
return V_200 ;
}
if ( ++ V_200 == V_207 )
V_200 = 0 ;
} while ( V_200 != V_213 );
F_18 ( & V_14 -> V_203 -> V_217 ) ;
return V_174 ;
}
static unsigned int F_164 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
return F_165 ( V_2 ) % V_207 ;
}
static unsigned int F_166 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
struct V_218 * V_219 ;
unsigned int V_8 = 0 ;
F_20 () ;
V_219 = F_21 ( V_206 -> V_218 ) ;
if ( V_219 )
V_8 = F_167 ( V_219 , V_2 ) % V_207 ;
F_24 () ;
return V_8 ;
}
static bool F_168 ( struct V_205 * V_206 , T_2 V_220 )
{
return V_206 -> V_46 & ( V_220 >> 8 ) ;
}
static int F_169 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_205 * V_206 = V_222 -> V_224 ;
unsigned int V_207 = F_170 ( V_206 -> V_225 ) ;
struct V_226 * V_226 = F_171 ( & V_206 -> V_226 ) ;
struct V_13 * V_14 ;
unsigned int V_174 ;
if ( ! F_172 ( F_173 ( V_4 ) , V_226 ) || ! V_207 ) {
F_17 ( V_2 ) ;
return 0 ;
}
if ( F_168 ( V_206 , V_227 ) ) {
V_2 = F_174 ( V_226 , V_2 , V_228 ) ;
if ( ! V_2 )
return 0 ;
}
switch ( V_206 -> type ) {
case V_229 :
default:
V_174 = F_155 ( V_206 , V_2 , V_207 ) ;
break;
case V_230 :
V_174 = F_157 ( V_206 , V_2 , V_207 ) ;
break;
case V_231 :
V_174 = F_159 ( V_206 , V_2 , V_207 ) ;
break;
case V_232 :
V_174 = F_160 ( V_206 , V_2 , V_207 ) ;
break;
case V_233 :
V_174 = F_164 ( V_206 , V_2 , V_207 ) ;
break;
case V_234 :
V_174 = F_162 ( V_206 , V_2 , 0 , false , V_207 ) ;
break;
case V_235 :
case V_236 :
V_174 = F_166 ( V_206 , V_2 , V_207 ) ;
break;
}
if ( F_168 ( V_206 , V_237 ) )
V_174 = F_162 ( V_206 , V_2 , V_174 , true , V_207 ) ;
V_14 = F_36 ( V_206 -> V_215 [ V_174 ] ) ;
return V_14 -> V_27 . F_72 ( V_2 , V_4 , & V_14 -> V_27 , V_223 ) ;
}
static void F_37 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_205 * V_206 = V_14 -> V_26 ;
F_46 ( & V_206 -> V_78 ) ;
V_206 -> V_215 [ V_206 -> V_225 ] = V_24 ;
F_56 () ;
V_206 -> V_225 ++ ;
F_44 ( & V_206 -> V_78 ) ;
}
static void F_41 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_205 * V_206 = V_14 -> V_26 ;
int V_200 ;
F_46 ( & V_206 -> V_78 ) ;
for ( V_200 = 0 ; V_200 < V_206 -> V_225 ; V_200 ++ ) {
if ( V_206 -> V_215 [ V_200 ] == V_24 )
break;
}
F_175 ( V_200 >= V_206 -> V_225 ) ;
V_206 -> V_215 [ V_200 ] = V_206 -> V_215 [ V_206 -> V_225 - 1 ] ;
V_206 -> V_225 -- ;
F_44 ( & V_206 -> V_78 ) ;
}
static bool F_176 ( struct V_221 * V_238 , struct V_23 * V_24 )
{
if ( V_24 -> V_239 != V_240 )
return false ;
return V_238 -> V_224 == F_36 ( V_24 ) -> V_26 ;
}
static void F_177 ( struct V_205 * V_206 )
{
switch ( V_206 -> type ) {
case V_230 :
F_178 ( & V_206 -> V_209 , 0 ) ;
break;
case V_235 :
case V_236 :
F_28 ( V_206 -> V_218 , NULL ) ;
break;
}
}
static void F_179 ( struct V_205 * V_206 , struct V_218 * V_241 )
{
struct V_218 * V_242 ;
F_46 ( & V_206 -> V_78 ) ;
V_242 = F_180 ( V_206 -> V_218 , F_181 ( & V_206 -> V_78 ) ) ;
F_26 ( V_206 -> V_218 , V_241 ) ;
F_44 ( & V_206 -> V_78 ) ;
if ( V_242 ) {
F_45 () ;
F_182 ( V_242 ) ;
}
}
static int F_183 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_173 )
{
struct V_218 * V_241 ;
struct V_243 V_244 ;
int V_8 ;
if ( F_150 ( & V_14 -> V_24 , V_245 ) )
return - V_246 ;
if ( V_173 != sizeof( V_244 ) )
return - V_247 ;
if ( F_184 ( & V_244 , V_80 , V_173 ) )
return - V_248 ;
V_8 = F_185 ( & V_241 , & V_244 , NULL , false ) ;
if ( V_8 )
return V_8 ;
F_179 ( V_14 -> V_26 , V_241 ) ;
return 0 ;
}
static int F_186 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_173 )
{
struct V_218 * V_241 ;
T_6 V_249 ;
if ( F_150 ( & V_14 -> V_24 , V_245 ) )
return - V_246 ;
if ( V_173 != sizeof( V_249 ) )
return - V_247 ;
if ( F_184 ( & V_249 , V_80 , V_173 ) )
return - V_248 ;
V_241 = F_187 ( V_249 ) ;
if ( F_188 ( V_241 ) )
return F_189 ( V_241 ) ;
if ( V_241 -> type != V_250 ) {
F_190 ( V_241 ) ;
return - V_247 ;
}
F_179 ( V_14 -> V_26 , V_241 ) ;
return 0 ;
}
static int F_191 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_173 )
{
switch ( V_14 -> V_26 -> type ) {
case V_235 :
return F_183 ( V_14 , V_80 , V_173 ) ;
case V_236 :
return F_186 ( V_14 , V_80 , V_173 ) ;
default:
return - V_247 ;
} ;
}
static void F_192 ( struct V_205 * V_206 )
{
switch ( V_206 -> type ) {
case V_235 :
case V_236 :
F_179 ( V_206 , NULL ) ;
} ;
}
static int F_193 ( struct V_23 * V_24 , T_2 V_251 , T_2 V_252 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_205 * V_206 , * V_253 ;
T_5 type = V_252 & 0xff ;
T_5 V_46 = V_252 >> 8 ;
int V_91 ;
switch ( type ) {
case V_234 :
if ( V_252 & V_237 )
return - V_247 ;
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_235 :
case V_236 :
break;
default:
return - V_247 ;
}
if ( ! V_14 -> V_25 )
return - V_247 ;
if ( V_14 -> V_26 )
return - V_254 ;
if ( type == V_234 ||
( V_252 & V_237 ) ) {
V_14 -> V_203 = F_194 ( sizeof( * V_14 -> V_203 ) , V_255 ) ;
if ( ! V_14 -> V_203 )
return - V_256 ;
F_195 ( & V_14 -> V_203 -> V_207 , 0 ) ;
F_195 ( & V_14 -> V_203 -> V_216 , 0 ) ;
F_195 ( & V_14 -> V_203 -> V_217 , 0 ) ;
}
F_196 ( & V_257 ) ;
V_253 = NULL ;
F_197 (f, &fanout_list, list) {
if ( V_206 -> V_251 == V_251 &&
F_171 ( & V_206 -> V_226 ) == F_78 ( V_24 ) ) {
V_253 = V_206 ;
break;
}
}
V_91 = - V_247 ;
if ( V_253 && V_253 -> V_46 != V_46 )
goto V_130;
if ( ! V_253 ) {
V_91 = - V_256 ;
V_253 = F_194 ( sizeof( * V_253 ) , V_255 ) ;
if ( ! V_253 )
goto V_130;
F_198 ( & V_253 -> V_226 , F_78 ( V_24 ) ) ;
V_253 -> V_251 = V_251 ;
V_253 -> type = type ;
V_253 -> V_46 = V_46 ;
F_199 ( & V_253 -> V_258 ) ;
F_200 ( & V_253 -> V_78 ) ;
F_178 ( & V_253 -> V_259 , 0 ) ;
F_177 ( V_253 ) ;
V_253 -> V_27 . type = V_14 -> V_27 . type ;
V_253 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_253 -> V_27 . F_72 = F_169 ;
V_253 -> V_27 . V_224 = V_253 ;
V_253 -> V_27 . V_260 = F_176 ;
F_38 ( & V_253 -> V_27 ) ;
F_201 ( & V_253 -> V_258 , & V_261 ) ;
}
V_91 = - V_247 ;
if ( V_253 -> type == type &&
V_253 -> V_27 . type == V_14 -> V_27 . type &&
V_253 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_91 = - V_262 ;
if ( F_91 ( & V_253 -> V_259 ) < V_263 ) {
F_42 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_253 ;
F_120 ( & V_253 -> V_259 ) ;
F_37 ( V_24 , V_14 ) ;
V_91 = 0 ;
}
}
V_130:
F_202 ( & V_257 ) ;
if ( V_91 ) {
F_203 ( V_14 -> V_203 ) ;
V_14 -> V_203 = NULL ;
}
return V_91 ;
}
static void F_204 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_205 * V_206 ;
V_206 = V_14 -> V_26 ;
if ( ! V_206 )
return;
F_196 ( & V_257 ) ;
V_14 -> V_26 = NULL ;
if ( F_205 ( & V_206 -> V_259 ) ) {
F_206 ( & V_206 -> V_258 ) ;
F_207 ( & V_206 -> V_27 ) ;
F_192 ( V_206 ) ;
F_203 ( V_206 ) ;
}
F_202 ( & V_257 ) ;
if ( V_14 -> V_203 )
F_208 ( V_14 -> V_203 , V_264 ) ;
}
static bool F_209 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( F_2 ( V_4 -> type != V_265 ) )
return false ;
F_210 ( V_2 ) ;
return F_22 ( F_211 ( V_2 ) -> V_266 == F_212 ( V_267 ) ) ;
}
static int F_213 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_23 * V_24 ;
struct V_268 * V_269 ;
V_24 = V_222 -> V_224 ;
if ( V_2 -> V_270 == V_271 )
goto V_130;
if ( ! F_172 ( F_173 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_130;
V_2 = F_214 ( V_2 , V_272 ) ;
if ( V_2 == NULL )
goto V_273;
F_215 ( V_2 ) ;
F_216 ( V_2 ) ;
V_269 = & F_217 ( V_2 ) -> V_274 . V_275 ;
F_218 ( V_2 , V_2 -> V_80 - F_219 ( V_2 ) ) ;
V_269 -> V_276 = V_4 -> type ;
F_220 ( V_269 -> V_277 , V_4 -> V_278 , sizeof( V_269 -> V_277 ) ) ;
V_269 -> V_279 = V_2 -> V_280 ;
if ( F_221 ( V_24 , V_2 ) == 0 )
return 0 ;
V_130:
F_17 ( V_2 ) ;
V_273:
return 0 ;
}
static int F_222 ( struct V_281 * V_23 , struct V_282 * V_283 ,
T_8 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_223 ( struct V_268 * , V_284 , V_283 -> V_285 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
T_9 V_286 = 0 ;
int V_91 ;
int V_287 = 0 ;
if ( V_284 ) {
if ( V_283 -> V_288 < sizeof( struct V_289 ) )
return - V_247 ;
if ( V_283 -> V_288 == sizeof( struct V_268 ) )
V_286 = V_284 -> V_279 ;
} else
return - V_290 ;
V_284 -> V_277 [ sizeof( V_284 -> V_277 ) - 1 ] = 0 ;
V_291:
F_20 () ;
V_4 = F_224 ( F_78 ( V_24 ) , V_284 -> V_277 ) ;
V_91 = - V_292 ;
if ( V_4 == NULL )
goto V_293;
V_91 = - V_294 ;
if ( ! ( V_4 -> V_46 & V_295 ) )
goto V_293;
if ( F_2 ( F_150 ( V_24 , V_296 ) ) ) {
if ( ! F_225 ( V_4 ) ) {
V_91 = - V_297 ;
goto V_293;
}
V_287 = 4 ;
}
V_91 = - V_298 ;
if ( V_173 > V_4 -> V_299 + V_4 -> V_300 + V_301 + V_287 )
goto V_293;
if ( ! V_2 ) {
T_8 V_302 = F_226 ( V_4 ) ;
int V_303 = V_4 -> V_304 ;
unsigned int V_305 = V_4 -> V_306 ? V_4 -> V_300 : 0 ;
F_24 () ;
V_2 = F_227 ( V_24 , V_173 + V_302 + V_303 , 0 , V_255 ) ;
if ( V_2 == NULL )
return - V_183 ;
F_228 ( V_2 , V_302 ) ;
F_229 ( V_2 ) ;
if ( V_305 ) {
V_2 -> V_80 -= V_305 ;
V_2 -> V_307 -= V_305 ;
if ( V_173 < V_305 )
F_229 ( V_2 ) ;
}
V_91 = F_230 ( F_231 ( V_2 , V_173 ) , V_283 , V_173 ) ;
if ( V_91 )
goto V_308;
goto V_291;
}
if ( ! F_232 ( V_4 , V_2 -> V_80 , V_173 ) ) {
V_91 = - V_247 ;
goto V_293;
}
if ( V_173 > ( V_4 -> V_299 + V_4 -> V_300 + V_287 ) &&
! F_209 ( V_4 , V_2 ) ) {
V_91 = - V_298 ;
goto V_293;
}
V_2 -> V_280 = V_286 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_309 = V_24 -> V_310 ;
V_2 -> V_311 = V_24 -> V_312 ;
F_233 ( V_24 , & F_234 ( V_2 ) -> V_313 ) ;
if ( F_2 ( V_287 == 4 ) )
V_2 -> V_314 = 1 ;
F_235 ( V_2 , 0 ) ;
F_236 ( V_2 ) ;
F_24 () ;
return V_173 ;
V_293:
F_24 () ;
V_308:
F_17 ( V_2 ) ;
return V_91 ;
}
static unsigned int F_237 ( struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_315 )
{
struct V_316 * V_317 ;
F_20 () ;
V_317 = F_21 ( V_24 -> V_316 ) ;
if ( V_317 != NULL )
V_315 = F_167 ( V_317 -> V_219 , V_2 ) ;
F_24 () ;
return V_315 ;
}
static int F_238 ( const struct V_1 * V_2 ,
struct V_318 * V_319 )
{
* V_319 = ( const struct V_318 ) { 0 } ;
if ( F_239 ( V_2 ) ) {
struct V_320 * V_321 = F_234 ( V_2 ) ;
V_319 -> V_322 =
F_240 ( F_241 () , F_242 ( V_2 ) ) ;
V_319 -> V_323 =
F_240 ( F_241 () , V_321 -> V_323 ) ;
if ( V_321 -> V_324 & V_325 )
V_319 -> V_324 = V_326 ;
else if ( V_321 -> V_324 & V_327 )
V_319 -> V_324 = V_328 ;
else if ( V_321 -> V_324 & V_329 )
V_319 -> V_324 = V_330 ;
else if ( V_321 -> V_324 & V_331 )
return - V_247 ;
else
F_55 () ;
if ( V_321 -> V_324 & V_332 )
V_319 -> V_324 |= V_333 ;
} else
V_319 -> V_324 = V_334 ;
if ( V_2 -> V_335 == V_336 ) {
V_319 -> V_46 = V_337 ;
V_319 -> V_338 = F_240 ( F_241 () ,
F_243 ( V_2 ) ) ;
V_319 -> V_339 = F_240 ( F_241 () ,
V_2 -> V_339 ) ;
} else if ( V_2 -> V_335 == V_340 ) {
V_319 -> V_46 = V_341 ;
}
return 0 ;
}
static int F_244 ( struct V_282 * V_283 , const struct V_1 * V_2 ,
T_8 * V_173 )
{
struct V_318 V_319 ;
if ( * V_173 < sizeof( V_319 ) )
return - V_247 ;
* V_173 -= sizeof( V_319 ) ;
if ( F_238 ( V_2 , & V_319 ) )
return - V_247 ;
return F_245 ( V_283 , ( void * ) & V_319 , sizeof( V_319 ) ) ;
}
static int F_246 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_23 * V_24 ;
struct V_342 * V_343 ;
struct V_13 * V_14 ;
T_5 * V_344 = V_2 -> V_80 ;
int V_345 = V_2 -> V_173 ;
unsigned int V_346 , V_315 ;
if ( V_2 -> V_270 == V_271 )
goto V_10;
V_24 = V_222 -> V_224 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_306 ) {
if ( V_24 -> V_347 != V_348 )
F_218 ( V_2 , V_2 -> V_80 - F_219 ( V_2 ) ) ;
else if ( V_2 -> V_270 == V_349 ) {
F_247 ( V_2 , F_248 ( V_2 ) ) ;
}
}
V_346 = V_2 -> V_173 ;
V_315 = F_237 ( V_2 , V_24 , V_346 ) ;
if ( ! V_315 )
goto V_350;
if ( V_346 > V_315 )
V_346 = V_315 ;
if ( F_91 ( & V_24 -> V_189 ) >= V_24 -> V_188 )
goto V_351;
if ( F_249 ( V_2 ) ) {
struct V_1 * V_352 = F_250 ( V_2 , V_272 ) ;
if ( V_352 == NULL )
goto V_351;
if ( V_344 != V_2 -> V_80 ) {
V_2 -> V_80 = V_344 ;
V_2 -> V_173 = V_345 ;
}
F_251 ( V_2 ) ;
V_2 = V_352 ;
}
F_252 ( sizeof( * F_217 ( V_2 ) ) + V_353 - 8 ) ;
V_343 = & F_217 ( V_2 ) -> V_274 . V_354 ;
V_343 -> V_355 = V_4 -> type ;
V_343 -> V_356 = V_2 -> V_270 ;
if ( F_2 ( V_14 -> V_357 ) )
V_343 -> V_358 = V_223 -> V_92 ;
else
V_343 -> V_358 = V_4 -> V_92 ;
V_343 -> V_359 = F_253 ( V_2 , V_343 -> V_360 ) ;
F_217 ( V_2 ) -> V_274 . V_361 = V_2 -> V_173 ;
if ( F_254 ( V_2 , V_346 ) )
goto V_351;
F_255 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_215 ( V_2 ) ;
F_216 ( V_2 ) ;
F_46 ( & V_24 -> V_129 . V_78 ) ;
V_14 -> V_118 . V_362 . V_363 ++ ;
F_256 ( V_24 , V_2 ) ;
F_257 ( & V_24 -> V_129 , V_2 ) ;
F_44 ( & V_24 -> V_129 . V_78 ) ;
V_24 -> V_155 ( V_24 ) ;
return 0 ;
V_351:
F_46 ( & V_24 -> V_129 . V_78 ) ;
V_14 -> V_118 . V_362 . V_148 ++ ;
F_120 ( & V_24 -> V_364 ) ;
F_44 ( & V_24 -> V_129 . V_78 ) ;
V_350:
if ( V_344 != V_2 -> V_80 && F_249 ( V_2 ) ) {
V_2 -> V_80 = V_344 ;
V_2 -> V_173 = V_345 ;
}
V_10:
F_251 ( V_2 ) ;
return 0 ;
}
static int V_186 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
struct V_342 * V_343 ;
union V_34 V_35 ;
T_5 * V_344 = V_2 -> V_80 ;
int V_345 = V_2 -> V_173 ;
unsigned int V_346 , V_315 ;
unsigned long V_33 = V_142 ;
unsigned short V_365 , V_366 , V_114 ;
struct V_1 * V_367 = NULL ;
struct V_44 V_45 ;
T_4 V_54 ;
F_258 ( F_259 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_258 ( F_259 ( sizeof( * V_35 . V_368 ) ) != 48 ) ;
if ( V_2 -> V_270 == V_271 )
goto V_10;
V_24 = V_222 -> V_224 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_306 ) {
if ( V_24 -> V_347 != V_348 )
F_218 ( V_2 , V_2 -> V_80 - F_219 ( V_2 ) ) ;
else if ( V_2 -> V_270 == V_349 ) {
F_247 ( V_2 , F_248 ( V_2 ) ) ;
}
}
V_346 = V_2 -> V_173 ;
V_315 = F_237 ( V_2 , V_24 , V_346 ) ;
if ( ! V_315 )
goto V_350;
if ( V_2 -> V_335 == V_336 )
V_33 |= V_369 ;
else if ( V_2 -> V_270 != V_349 &&
( V_2 -> V_335 == V_370 ||
F_260 ( V_2 ) ) )
V_33 |= V_371 ;
if ( V_346 > V_315 )
V_346 = V_315 ;
if ( V_24 -> V_347 == V_348 ) {
V_365 = V_366 = F_259 ( V_14 -> V_115 ) + 16 +
V_14 -> V_372 ;
} else {
unsigned int V_373 = F_248 ( V_2 ) ;
V_366 = F_259 ( V_14 -> V_115 +
( V_373 < 16 ? 16 : V_373 ) ) +
V_14 -> V_372 ;
if ( V_14 -> V_374 )
V_366 += sizeof( struct V_318 ) ;
V_365 = V_366 - V_373 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_365 + V_346 > V_14 -> V_77 . V_70 ) {
if ( V_14 -> V_375 &&
F_91 ( & V_24 -> V_189 ) < V_24 -> V_188 ) {
if ( F_249 ( V_2 ) ) {
V_367 = F_250 ( V_2 , V_272 ) ;
} else {
V_367 = F_261 ( V_2 ) ;
V_344 = V_2 -> V_80 ;
}
if ( V_367 )
F_255 ( V_367 , V_24 ) ;
}
V_346 = V_14 -> V_77 . V_70 - V_365 ;
if ( ( int ) V_346 < 0 )
V_346 = 0 ;
}
} else if ( F_2 ( V_365 + V_346 >
F_68 ( & V_14 -> V_77 ) -> V_126 ) ) {
T_6 V_376 ;
V_376 = F_68 ( & V_14 -> V_77 ) -> V_126 - V_365 ;
F_262 ( L_4 ,
V_346 , V_376 , V_365 ) ;
V_346 = V_376 ;
if ( F_2 ( ( int ) V_346 < 0 ) ) {
V_346 = 0 ;
V_365 = F_68 ( & V_14 -> V_77 ) -> V_126 ;
}
}
F_46 ( & V_24 -> V_129 . V_78 ) ;
V_35 . V_36 = F_123 ( V_14 , V_2 ,
V_160 , ( V_365 + V_346 ) ) ;
if ( ! V_35 . V_36 )
goto V_377;
if ( V_14 -> V_37 <= V_41 ) {
F_130 ( V_14 , & V_14 -> V_77 ) ;
if ( V_14 -> V_118 . V_362 . V_148 )
V_33 |= V_149 ;
}
V_14 -> V_118 . V_362 . V_363 ++ ;
if ( V_367 ) {
V_33 |= V_378 ;
F_257 ( & V_24 -> V_129 , V_367 ) ;
}
F_44 ( & V_24 -> V_129 . V_78 ) ;
if ( V_14 -> V_374 ) {
if ( F_238 ( V_2 , V_35 . V_36 + V_365 -
sizeof( struct V_318 ) ) ) {
F_46 ( & V_24 -> V_129 . V_78 ) ;
goto V_377;
}
}
F_263 ( V_2 , 0 , V_35 . V_36 + V_365 , V_346 ) ;
if ( ! ( V_54 = F_59 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
F_100 ( & V_45 ) ;
V_33 |= V_54 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_379 = V_2 -> V_173 ;
V_35 . V_39 -> V_380 = V_346 ;
V_35 . V_39 -> V_381 = V_365 ;
V_35 . V_39 -> V_382 = V_366 ;
V_35 . V_39 -> V_56 = V_45 . V_57 ;
V_35 . V_39 -> V_58 = V_45 . V_59 / V_60 ;
V_114 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_379 = V_2 -> V_173 ;
V_35 . V_42 -> V_380 = V_346 ;
V_35 . V_42 -> V_381 = V_365 ;
V_35 . V_42 -> V_382 = V_366 ;
V_35 . V_42 -> V_56 = V_45 . V_57 ;
V_35 . V_42 -> V_61 = V_45 . V_59 ;
if ( F_114 ( V_2 ) ) {
V_35 . V_42 -> V_164 = F_115 ( V_2 ) ;
V_35 . V_42 -> V_165 = F_116 ( V_2 -> V_166 ) ;
V_33 |= V_167 | V_168 ;
} else {
V_35 . V_42 -> V_164 = 0 ;
V_35 . V_42 -> V_165 = 0 ;
}
memset ( V_35 . V_42 -> V_170 , 0 , sizeof( V_35 . V_42 -> V_170 ) ) ;
V_114 = sizeof( * V_35 . V_42 ) ;
break;
case V_43 :
V_35 . V_368 -> V_40 |= V_33 ;
V_35 . V_368 -> V_379 = V_2 -> V_173 ;
V_35 . V_368 -> V_380 = V_346 ;
V_35 . V_368 -> V_381 = V_365 ;
V_35 . V_368 -> V_382 = V_366 ;
V_35 . V_368 -> V_56 = V_45 . V_57 ;
V_35 . V_368 -> V_61 = V_45 . V_59 ;
memset ( V_35 . V_368 -> V_170 , 0 , sizeof( V_35 . V_368 -> V_170 ) ) ;
V_114 = sizeof( * V_35 . V_368 ) ;
break;
default:
F_55 () ;
}
V_343 = V_35 . V_36 + F_259 ( V_114 ) ;
V_343 -> V_359 = F_253 ( V_2 , V_343 -> V_360 ) ;
V_343 -> V_383 = V_384 ;
V_343 -> V_355 = V_4 -> type ;
V_343 -> V_385 = V_2 -> V_280 ;
V_343 -> V_356 = V_2 -> V_270 ;
if ( F_2 ( V_14 -> V_357 ) )
V_343 -> V_358 = V_223 -> V_92 ;
else
V_343 -> V_358 = V_4 -> V_92 ;
F_122 () ;
#if V_136 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_5 * V_137 , * V_138 ;
V_138 = ( T_5 * ) F_97 ( ( unsigned long ) V_35 . V_36 +
V_365 + V_346 ) ;
for ( V_137 = V_35 . V_36 ; V_137 < V_138 ; V_137 += V_139 )
F_53 ( F_48 ( V_137 ) ) ;
}
F_56 () ;
#endif
if ( V_14 -> V_37 <= V_41 ) {
F_52 ( V_14 , V_35 . V_36 , V_33 ) ;
V_24 -> V_155 ( V_24 ) ;
} else {
F_108 ( & V_14 -> V_77 ) ;
}
V_350:
if ( V_344 != V_2 -> V_80 && F_249 ( V_2 ) ) {
V_2 -> V_80 = V_344 ;
V_2 -> V_173 = V_345 ;
}
V_10:
F_17 ( V_2 ) ;
return 0 ;
V_377:
V_14 -> V_118 . V_362 . V_148 ++ ;
F_44 ( & V_24 -> V_129 . V_78 ) ;
V_24 -> V_155 ( V_24 ) ;
F_17 ( V_367 ) ;
goto V_350;
}
static void F_264 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_36 ( V_2 -> V_24 ) ;
if ( F_22 ( V_14 -> V_182 . V_68 ) ) {
void * V_386 ;
T_4 V_45 ;
V_386 = F_234 ( V_2 ) -> V_387 ;
F_134 ( & V_14 -> V_182 ) ;
V_45 = F_62 ( V_14 , V_386 , V_2 ) ;
F_52 ( V_14 , V_386 , V_169 | V_45 ) ;
}
F_265 ( V_2 ) ;
}
static void F_266 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( V_4 -> type == V_265 ) {
F_210 ( V_2 ) ;
V_2 -> V_280 = F_211 ( V_2 ) -> V_266 ;
}
}
static int F_267 ( struct V_318 * V_319 , T_8 V_173 )
{
unsigned short V_324 = 0 ;
if ( ( V_319 -> V_46 & V_337 ) &&
( F_268 ( F_241 () , V_319 -> V_338 ) +
F_268 ( F_241 () , V_319 -> V_339 ) + 2 >
F_268 ( F_241 () , V_319 -> V_322 ) ) )
V_319 -> V_322 = F_240 ( F_241 () ,
F_268 ( F_241 () , V_319 -> V_338 ) +
F_268 ( F_241 () , V_319 -> V_339 ) + 2 ) ;
if ( F_268 ( F_241 () , V_319 -> V_322 ) > V_173 )
return - V_247 ;
if ( V_319 -> V_324 != V_334 ) {
switch ( V_319 -> V_324 & ~ V_333 ) {
case V_326 :
V_324 = V_325 ;
break;
case V_328 :
V_324 = V_327 ;
break;
case V_330 :
V_324 = V_329 ;
break;
default:
return - V_247 ;
}
if ( V_319 -> V_324 & V_333 )
V_324 |= V_332 ;
if ( V_319 -> V_323 == 0 )
return - V_247 ;
}
V_319 -> V_324 = V_324 ;
return 0 ;
}
static int F_269 ( struct V_282 * V_283 , T_8 * V_173 ,
struct V_318 * V_319 )
{
int V_388 ;
if ( * V_173 < sizeof( * V_319 ) )
return - V_247 ;
* V_173 -= sizeof( * V_319 ) ;
V_388 = F_270 ( V_319 , sizeof( * V_319 ) , & V_283 -> V_389 ) ;
if ( V_388 != sizeof( * V_319 ) )
return - V_248 ;
return F_267 ( V_319 , * V_173 ) ;
}
static int F_271 ( struct V_1 * V_2 ,
struct V_318 * V_319 )
{
if ( V_319 -> V_46 & V_337 ) {
T_2 V_390 = F_268 ( F_241 () , V_319 -> V_338 ) ;
T_2 V_391 = F_268 ( F_241 () , V_319 -> V_339 ) ;
if ( ! F_272 ( V_2 , V_390 , V_391 ) )
return - V_247 ;
}
F_234 ( V_2 ) -> V_323 =
F_268 ( F_241 () , V_319 -> V_323 ) ;
F_234 ( V_2 ) -> V_324 = V_319 -> V_324 ;
F_234 ( V_2 ) -> V_324 |= V_392 ;
F_234 ( V_2 ) -> V_393 = 0 ;
return 0 ;
}
static int F_273 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , void * V_80 , int V_379 ,
T_9 V_286 , unsigned char * V_31 , int V_394 , int V_395 )
{
union V_34 V_386 ;
int V_396 , V_397 , V_173 , V_398 , V_399 ;
struct V_281 * V_23 = V_14 -> V_24 . V_400 ;
struct V_30 * V_30 ;
int V_91 ;
V_386 . V_36 = V_32 ;
V_2 -> V_280 = V_286 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_309 = V_14 -> V_24 . V_310 ;
V_2 -> V_311 = V_14 -> V_24 . V_312 ;
F_233 ( & V_14 -> V_24 , & F_234 ( V_2 ) -> V_313 ) ;
F_234 ( V_2 ) -> V_387 = V_386 . V_36 ;
F_228 ( V_2 , V_394 ) ;
F_229 ( V_2 ) ;
V_396 = V_379 ;
if ( V_23 -> type == V_348 ) {
V_91 = F_274 ( V_2 , V_4 , F_116 ( V_286 ) , V_31 ,
NULL , V_379 ) ;
if ( F_2 ( V_91 < 0 ) )
return - V_247 ;
} else if ( V_395 ) {
int V_114 = F_163 ( int , V_395 , V_379 ) ;
F_218 ( V_2 , V_4 -> V_300 ) ;
F_231 ( V_2 , V_395 - V_4 -> V_300 ) ;
V_91 = F_275 ( V_2 , 0 , V_80 , V_114 ) ;
if ( F_2 ( V_91 ) )
return V_91 ;
if ( ! F_232 ( V_4 , V_2 -> V_80 , V_114 ) )
return - V_247 ;
if ( ! V_2 -> V_280 )
F_266 ( V_4 , V_2 ) ;
V_80 += V_114 ;
V_396 -= V_114 ;
}
V_397 = F_276 ( V_80 ) ;
V_399 = V_139 - V_397 ;
V_173 = ( ( V_396 > V_399 ) ? V_399 : V_396 ) ;
V_2 -> V_401 = V_396 ;
V_2 -> V_173 += V_396 ;
V_2 -> V_190 += V_396 ;
F_277 ( V_396 , & V_14 -> V_24 . V_197 ) ;
while ( F_22 ( V_396 ) ) {
V_398 = F_234 ( V_2 ) -> V_398 ;
if ( F_2 ( V_398 >= V_402 ) ) {
F_151 ( L_5 ,
V_402 ) ;
return - V_248 ;
}
V_30 = F_48 ( V_80 ) ;
V_80 += V_173 ;
F_53 ( V_30 ) ;
F_278 ( V_30 ) ;
F_279 ( V_2 , V_398 , V_30 , V_397 , V_173 ) ;
V_396 -= V_173 ;
V_397 = 0 ;
V_399 = V_139 ;
V_173 = ( ( V_396 > V_399 ) ? V_399 : V_396 ) ;
}
F_235 ( V_2 , 0 ) ;
return V_379 ;
}
static int F_280 ( struct V_13 * V_14 , void * V_32 ,
int V_403 , void * * V_80 )
{
union V_34 V_386 ;
int V_379 , V_404 ;
V_386 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_41 :
V_379 = V_386 . V_42 -> V_379 ;
break;
default:
V_379 = V_386 . V_39 -> V_379 ;
break;
}
if ( F_2 ( V_379 > V_403 ) ) {
F_151 ( L_6 , V_379 , V_403 ) ;
return - V_298 ;
}
if ( F_2 ( V_14 -> V_405 ) ) {
int V_406 , V_407 ;
V_406 = V_14 -> V_115 - sizeof( struct V_342 ) ;
V_407 = V_14 -> V_182 . V_70 - V_379 ;
if ( V_14 -> V_24 . V_347 == V_348 ) {
switch ( V_14 -> V_37 ) {
case V_41 :
V_404 = V_386 . V_42 -> V_382 ;
break;
default:
V_404 = V_386 . V_39 -> V_382 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_41 :
V_404 = V_386 . V_42 -> V_381 ;
break;
default:
V_404 = V_386 . V_39 -> V_381 ;
break;
}
}
if ( F_2 ( ( V_404 < V_406 ) || ( V_407 < V_404 ) ) )
return - V_247 ;
} else {
V_404 = V_14 -> V_115 - sizeof( struct V_342 ) ;
}
* V_80 = V_32 + V_404 ;
return V_379 ;
}
static int F_281 ( struct V_13 * V_14 , struct V_282 * V_283 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_318 * V_319 = NULL ;
T_9 V_286 ;
int V_91 , V_408 = 0 ;
void * V_386 ;
F_223 ( struct V_342 * , V_284 , V_283 -> V_285 ) ;
bool V_409 = ! ( V_283 -> V_410 & V_411 ) ;
int V_379 , V_403 ;
unsigned char * V_31 ;
void * V_80 ;
int V_412 = 0 ;
int V_33 = V_169 ;
int V_394 , V_303 , V_395 = 0 ;
F_196 ( & V_14 -> V_413 ) ;
if ( F_22 ( V_284 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_286 = V_14 -> V_207 ;
V_31 = NULL ;
} else {
V_91 = - V_247 ;
if ( V_283 -> V_288 < sizeof( struct V_342 ) )
goto V_130;
if ( V_283 -> V_288 < ( V_284 -> V_359
+ F_282 ( struct V_342 ,
V_360 ) ) )
goto V_130;
V_286 = V_284 -> V_385 ;
V_31 = V_284 -> V_360 ;
V_4 = F_283 ( F_78 ( & V_14 -> V_24 ) , V_284 -> V_358 ) ;
}
V_91 = - V_414 ;
if ( F_2 ( V_4 == NULL ) )
goto V_130;
V_91 = - V_294 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_295 ) ) )
goto V_415;
if ( V_14 -> V_24 . V_400 -> type == V_416 )
V_408 = V_4 -> V_300 ;
V_403 = V_14 -> V_182 . V_70
- ( V_14 -> V_115 - sizeof( struct V_342 ) ) ;
if ( ( V_403 > V_4 -> V_299 + V_408 + V_301 ) && ! V_14 -> V_374 )
V_403 = V_4 -> V_299 + V_408 + V_301 ;
do {
V_386 = F_64 ( V_14 , & V_14 -> V_182 ,
V_417 ) ;
if ( F_2 ( V_386 == NULL ) ) {
if ( V_409 && F_284 () )
F_285 () ;
continue;
}
V_2 = NULL ;
V_379 = F_280 ( V_14 , V_386 , V_403 , & V_80 ) ;
if ( V_379 < 0 )
goto V_418;
V_33 = V_417 ;
V_394 = F_226 ( V_4 ) ;
V_303 = V_4 -> V_304 ;
if ( V_14 -> V_374 ) {
V_319 = V_80 ;
V_80 += sizeof( * V_319 ) ;
V_379 -= sizeof( * V_319 ) ;
if ( V_379 < 0 ||
F_267 ( V_319 , V_379 ) ) {
V_379 = - V_247 ;
goto V_418;
}
V_395 = F_268 ( F_241 () ,
V_319 -> V_322 ) ;
}
V_395 = F_286 ( int , V_395 , V_4 -> V_300 ) ;
V_2 = F_287 ( & V_14 -> V_24 ,
V_394 + V_303 + sizeof( struct V_342 ) +
( V_395 - V_4 -> V_300 ) ,
! V_409 , & V_91 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_22 ( V_412 > 0 ) )
V_91 = V_412 ;
goto V_419;
}
V_379 = F_273 ( V_14 , V_2 , V_386 , V_4 , V_80 , V_379 , V_286 ,
V_31 , V_394 , V_395 ) ;
if ( F_22 ( V_379 >= 0 ) &&
V_379 > V_4 -> V_299 + V_408 &&
! V_14 -> V_374 &&
! F_209 ( V_4 , V_2 ) )
V_379 = - V_298 ;
if ( F_2 ( V_379 < 0 ) ) {
V_418:
if ( V_14 -> V_420 ) {
F_52 ( V_14 , V_386 ,
V_169 ) ;
F_131 ( & V_14 -> V_182 ) ;
F_17 ( V_2 ) ;
continue;
} else {
V_33 = V_421 ;
V_91 = V_379 ;
goto V_419;
}
}
if ( V_14 -> V_374 && F_271 ( V_2 , V_319 ) ) {
V_379 = - V_247 ;
goto V_418;
}
F_32 ( V_4 , V_2 ) ;
V_2 -> V_422 = F_264 ;
F_52 ( V_14 , V_386 , V_423 ) ;
F_132 ( & V_14 -> V_182 ) ;
V_33 = V_417 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_91 > 0 ) ) {
V_91 = F_288 ( V_91 ) ;
if ( V_91 && F_57 ( V_14 , V_386 ) ==
V_169 ) {
V_2 = NULL ;
goto V_419;
}
V_91 = 0 ;
}
F_131 ( & V_14 -> V_182 ) ;
V_412 += V_379 ;
} while ( F_22 ( ( V_386 != NULL ) ||
( V_409 && F_136 ( & V_14 -> V_182 ) ) ) );
V_91 = V_412 ;
goto V_415;
V_419:
F_52 ( V_14 , V_386 , V_33 ) ;
F_17 ( V_2 ) ;
V_415:
F_289 ( V_4 ) ;
V_130:
F_202 ( & V_14 -> V_413 ) ;
return V_91 ;
}
static struct V_1 * F_290 ( struct V_23 * V_24 , T_8 V_424 ,
T_8 V_408 , T_8 V_173 ,
T_8 V_425 , int V_426 ,
int * V_91 )
{
struct V_1 * V_2 ;
if ( V_424 + V_173 < V_139 || ! V_425 )
V_425 = V_173 ;
V_2 = F_291 ( V_24 , V_424 + V_425 , V_173 - V_425 , V_426 ,
V_91 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_228 ( V_2 , V_408 ) ;
F_231 ( V_2 , V_425 ) ;
V_2 -> V_401 = V_173 - V_425 ;
V_2 -> V_173 += V_173 - V_425 ;
return V_2 ;
}
static int F_292 ( struct V_281 * V_23 , struct V_282 * V_283 , T_8 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_223 ( struct V_342 * , V_284 , V_283 -> V_285 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_9 V_286 ;
unsigned char * V_31 ;
int V_91 , V_408 = 0 ;
struct V_427 V_428 ;
struct V_318 V_319 = { 0 } ;
int V_397 = 0 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_394 , V_303 ;
int V_287 = 0 ;
if ( F_22 ( V_284 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_286 = V_14 -> V_207 ;
V_31 = NULL ;
} else {
V_91 = - V_247 ;
if ( V_283 -> V_288 < sizeof( struct V_342 ) )
goto V_130;
if ( V_283 -> V_288 < ( V_284 -> V_359 + F_282 ( struct V_342 , V_360 ) ) )
goto V_130;
V_286 = V_284 -> V_385 ;
V_31 = V_284 -> V_360 ;
V_4 = F_283 ( F_78 ( V_24 ) , V_284 -> V_358 ) ;
}
V_91 = - V_414 ;
if ( F_2 ( V_4 == NULL ) )
goto V_293;
V_91 = - V_294 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_295 ) ) )
goto V_293;
V_428 . V_311 = V_24 -> V_312 ;
if ( V_283 -> V_429 ) {
V_91 = F_293 ( V_24 , V_283 , & V_428 ) ;
if ( F_2 ( V_91 ) )
goto V_293;
}
if ( V_23 -> type == V_416 )
V_408 = V_4 -> V_300 ;
if ( V_14 -> V_374 ) {
V_91 = F_269 ( V_283 , & V_173 , & V_319 ) ;
if ( V_91 )
goto V_293;
}
if ( F_2 ( F_150 ( V_24 , V_296 ) ) ) {
if ( ! F_225 ( V_4 ) ) {
V_91 = - V_297 ;
goto V_293;
}
V_287 = 4 ;
}
V_91 = - V_298 ;
if ( ! V_319 . V_324 &&
( V_173 > V_4 -> V_299 + V_408 + V_301 + V_287 ) )
goto V_293;
V_91 = - V_183 ;
V_394 = F_226 ( V_4 ) ;
V_303 = V_4 -> V_304 ;
V_2 = F_290 ( V_24 , V_394 + V_303 , V_394 , V_173 ,
F_268 ( F_241 () , V_319 . V_322 ) ,
V_283 -> V_410 & V_411 , & V_91 ) ;
if ( V_2 == NULL )
goto V_293;
F_294 ( V_2 , V_408 ) ;
V_91 = - V_247 ;
if ( V_23 -> type == V_348 ) {
V_397 = F_274 ( V_2 , V_4 , F_116 ( V_286 ) , V_31 , NULL , V_173 ) ;
if ( F_2 ( V_397 < 0 ) )
goto V_308;
}
V_91 = F_295 ( V_2 , V_397 , & V_283 -> V_389 , V_173 ) ;
if ( V_91 )
goto V_308;
if ( V_23 -> type == V_416 &&
! F_232 ( V_4 , V_2 -> V_80 , V_173 ) ) {
V_91 = - V_247 ;
goto V_308;
}
F_233 ( V_24 , & F_234 ( V_2 ) -> V_313 ) ;
if ( ! V_319 . V_324 && ( V_173 > V_4 -> V_299 + V_408 + V_287 ) &&
! F_209 ( V_4 , V_2 ) ) {
V_91 = - V_298 ;
goto V_308;
}
V_2 -> V_280 = V_286 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_309 = V_24 -> V_310 ;
V_2 -> V_311 = V_428 . V_311 ;
F_32 ( V_4 , V_2 ) ;
if ( V_14 -> V_374 ) {
V_91 = F_271 ( V_2 , & V_319 ) ;
if ( V_91 )
goto V_308;
V_173 += sizeof( V_319 ) ;
}
F_235 ( V_2 , V_408 ) ;
if ( F_2 ( V_287 == 4 ) )
V_2 -> V_314 = 1 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( V_91 > 0 && ( V_91 = F_288 ( V_91 ) ) != 0 )
goto V_293;
F_289 ( V_4 ) ;
return V_173 ;
V_308:
F_17 ( V_2 ) ;
V_293:
if ( V_4 )
F_289 ( V_4 ) ;
V_130:
return V_91 ;
}
static int F_296 ( struct V_281 * V_23 , struct V_282 * V_283 , T_8 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
if ( V_14 -> V_182 . V_68 )
return F_281 ( V_14 , V_283 ) ;
else
return F_292 ( V_23 , V_283 , V_173 ) ;
}
static int F_297 ( struct V_281 * V_23 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 ;
struct V_226 * V_226 ;
union V_99 V_100 ;
if ( ! V_24 )
return 0 ;
V_226 = F_78 ( V_24 ) ;
V_14 = F_36 ( V_24 ) ;
F_196 ( & V_226 -> V_430 . V_431 ) ;
F_298 ( V_24 ) ;
F_202 ( & V_226 -> V_430 . V_431 ) ;
F_299 () ;
F_300 ( V_226 , V_24 -> V_432 , - 1 ) ;
F_301 () ;
F_46 ( & V_14 -> V_29 ) ;
F_47 ( V_24 , false ) ;
F_27 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_289 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
F_302 ( V_24 ) ;
if ( V_14 -> V_77 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_303 ( V_24 , & V_100 , 1 , 0 ) ;
}
if ( V_14 -> V_182 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_303 ( V_24 , & V_100 , 1 , 1 ) ;
}
F_204 ( V_24 ) ;
F_45 () ;
F_304 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_148 ( & V_24 -> V_129 ) ;
F_141 ( V_14 ) ;
F_305 ( V_24 ) ;
F_306 ( V_24 ) ;
return 0 ;
}
static int F_307 ( struct V_23 * V_24 , const char * V_278 , int V_92 ,
T_9 V_286 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_3 * V_433 ;
T_9 V_434 ;
bool V_435 ;
struct V_3 * V_4 = NULL ;
int V_8 = 0 ;
bool V_436 = false ;
if ( V_14 -> V_26 )
return - V_247 ;
F_308 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
F_20 () ;
if ( V_278 ) {
V_4 = F_224 ( F_78 ( V_24 ) , V_278 ) ;
if ( ! V_4 ) {
V_8 = - V_292 ;
goto V_293;
}
} else if ( V_92 ) {
V_4 = F_309 ( F_78 ( V_24 ) , V_92 ) ;
if ( ! V_4 ) {
V_8 = - V_292 ;
goto V_293;
}
}
if ( V_4 )
F_23 ( V_4 ) ;
V_434 = V_14 -> V_27 . type ;
V_433 = V_14 -> V_27 . V_4 ;
V_435 = V_434 != V_286 || V_433 != V_4 ;
if ( V_435 ) {
if ( V_14 -> V_25 ) {
F_24 () ;
F_40 ( V_24 , true ) ;
F_20 () ;
V_433 = V_14 -> V_27 . V_4 ;
if ( V_4 )
V_436 = ! F_309 ( F_78 ( V_24 ) ,
V_4 -> V_92 ) ;
}
V_14 -> V_207 = V_286 ;
V_14 -> V_27 . type = V_286 ;
if ( F_2 ( V_436 ) ) {
F_289 ( V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
V_14 -> V_92 = - 1 ;
F_27 ( V_14 ) ;
} else {
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_92 = V_4 ? V_4 -> V_92 : 0 ;
F_25 ( V_14 , V_4 ) ;
}
}
if ( V_433 )
F_289 ( V_433 ) ;
if ( V_286 == 0 || ! V_435 )
goto V_293;
if ( ! V_436 && ( ! V_4 || ( V_4 -> V_46 & V_295 ) ) ) {
F_35 ( V_24 ) ;
} else {
V_24 -> V_437 = V_294 ;
if ( ! F_150 ( V_24 , V_198 ) )
V_24 -> V_438 ( V_24 ) ;
}
V_293:
F_24 () ;
F_44 ( & V_14 -> V_29 ) ;
F_310 ( V_24 ) ;
return V_8 ;
}
static int F_311 ( struct V_281 * V_23 , struct V_289 * V_439 ,
int V_440 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_278 [ 15 ] ;
if ( V_440 != sizeof( struct V_289 ) )
return - V_247 ;
F_220 ( V_278 , V_439 -> V_441 , sizeof( V_278 ) ) ;
return F_307 ( V_24 , V_278 , 0 , F_36 ( V_24 ) -> V_207 ) ;
}
static int F_312 ( struct V_281 * V_23 , struct V_289 * V_439 , int V_440 )
{
struct V_342 * V_343 = (struct V_342 * ) V_439 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_440 < sizeof( struct V_342 ) )
return - V_247 ;
if ( V_343 -> V_383 != V_384 )
return - V_247 ;
return F_307 ( V_24 , NULL , V_343 -> V_358 ,
V_343 -> V_385 ? : F_36 ( V_24 ) -> V_207 ) ;
}
static int F_313 ( struct V_226 * V_226 , struct V_281 * V_23 , int V_280 ,
int V_442 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_9 V_286 = ( V_443 T_9 ) V_280 ;
int V_91 ;
if ( ! F_314 ( V_226 -> V_444 , V_445 ) )
return - V_246 ;
if ( V_23 -> type != V_348 && V_23 -> type != V_416 &&
V_23 -> type != V_446 )
return - V_447 ;
V_23 -> V_448 = V_449 ;
V_91 = - V_183 ;
V_24 = F_315 ( V_226 , V_240 , V_255 , & V_450 , V_442 ) ;
if ( V_24 == NULL )
goto V_130;
V_23 -> V_19 = & V_451 ;
if ( V_23 -> type == V_446 )
V_23 -> V_19 = & V_452 ;
F_316 ( V_23 , V_24 ) ;
V_14 = F_36 ( V_24 ) ;
V_24 -> V_239 = V_240 ;
V_14 -> V_207 = V_286 ;
V_14 -> V_16 = F_236 ;
V_91 = F_139 ( V_14 ) ;
if ( V_91 )
goto V_453;
F_27 ( V_14 ) ;
V_24 -> V_454 = F_147 ;
F_317 ( V_24 ) ;
F_200 ( & V_14 -> V_29 ) ;
F_318 ( & V_14 -> V_413 ) ;
V_14 -> V_203 = NULL ;
V_14 -> V_27 . F_72 = F_246 ;
if ( V_23 -> type == V_446 )
V_14 -> V_27 . F_72 = F_213 ;
V_14 -> V_27 . V_224 = V_24 ;
if ( V_286 ) {
V_14 -> V_27 . type = V_286 ;
F_35 ( V_24 ) ;
}
F_196 ( & V_226 -> V_430 . V_431 ) ;
F_319 ( V_24 , & V_226 -> V_430 . V_455 ) ;
F_202 ( & V_226 -> V_430 . V_431 ) ;
F_299 () ;
F_300 ( V_226 , & V_450 , 1 ) ;
F_301 () ;
return 0 ;
V_453:
F_320 ( V_24 ) ;
V_130:
return V_91 ;
}
static int F_321 ( struct V_281 * V_23 , struct V_282 * V_283 , T_8 V_173 ,
int V_46 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_456 , V_91 ;
int V_457 = 0 ;
unsigned int V_361 = 0 ;
V_91 = - V_247 ;
if ( V_46 & ~ ( V_458 | V_411 | V_459 | V_460 | V_461 ) )
goto V_130;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_46 & V_461 ) {
V_91 = F_322 ( V_24 , V_283 , V_173 ,
V_462 , V_463 ) ;
goto V_130;
}
V_2 = F_323 ( V_24 , V_46 , V_46 & V_411 , & V_91 ) ;
if ( V_2 == NULL )
goto V_130;
if ( F_36 ( V_24 ) -> V_195 )
F_146 ( F_36 ( V_24 ) , NULL ) ;
if ( F_36 ( V_24 ) -> V_374 ) {
V_91 = F_244 ( V_283 , V_2 , & V_173 ) ;
if ( V_91 )
goto V_308;
V_457 = sizeof( struct V_318 ) ;
}
V_456 = V_2 -> V_173 ;
if ( V_456 > V_173 ) {
V_456 = V_173 ;
V_283 -> V_410 |= V_459 ;
}
V_91 = F_324 ( V_2 , 0 , V_283 , V_456 ) ;
if ( V_91 )
goto V_308;
if ( V_23 -> type != V_446 ) {
struct V_342 * V_343 = & F_217 ( V_2 ) -> V_274 . V_354 ;
V_361 = F_217 ( V_2 ) -> V_274 . V_361 ;
V_343 -> V_383 = V_384 ;
V_343 -> V_385 = V_2 -> V_280 ;
}
F_325 ( V_283 , V_24 , V_2 ) ;
if ( V_283 -> V_285 ) {
if ( V_23 -> type == V_446 ) {
F_326 ( sizeof( struct V_268 ) ) ;
V_283 -> V_288 = sizeof( struct V_268 ) ;
} else {
struct V_342 * V_343 = & F_217 ( V_2 ) -> V_274 . V_354 ;
V_283 -> V_288 = V_343 -> V_359 +
F_282 ( struct V_342 , V_360 ) ;
}
memcpy ( V_283 -> V_285 , & F_217 ( V_2 ) -> V_274 ,
V_283 -> V_288 ) ;
}
if ( F_36 ( V_24 ) -> V_464 ) {
struct V_465 V_466 ;
V_466 . V_40 = V_142 ;
if ( V_2 -> V_335 == V_336 )
V_466 . V_40 |= V_369 ;
else if ( V_2 -> V_270 != V_349 &&
( V_2 -> V_335 == V_370 ||
F_260 ( V_2 ) ) )
V_466 . V_40 |= V_371 ;
V_466 . V_379 = V_361 ;
V_466 . V_380 = V_2 -> V_173 ;
V_466 . V_381 = 0 ;
V_466 . V_382 = F_248 ( V_2 ) ;
if ( F_114 ( V_2 ) ) {
V_466 . V_164 = F_115 ( V_2 ) ;
V_466 . V_165 = F_116 ( V_2 -> V_166 ) ;
V_466 . V_40 |= V_167 | V_168 ;
} else {
V_466 . V_164 = 0 ;
V_466 . V_165 = 0 ;
}
F_327 ( V_283 , V_462 , V_467 , sizeof( V_466 ) , & V_466 ) ;
}
V_91 = V_457 + ( ( V_46 & V_459 ) ? V_2 -> V_173 : V_456 ) ;
V_308:
F_328 ( V_24 , V_2 ) ;
V_130:
return V_91 ;
}
static int F_329 ( struct V_281 * V_23 , struct V_289 * V_439 ,
int * V_468 , int V_469 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_469 )
return - V_470 ;
V_439 -> V_471 = V_384 ;
memset ( V_439 -> V_441 , 0 , sizeof( V_439 -> V_441 ) ) ;
F_20 () ;
V_4 = F_309 ( F_78 ( V_24 ) , F_36 ( V_24 ) -> V_92 ) ;
if ( V_4 )
F_220 ( V_439 -> V_441 , V_4 -> V_278 , sizeof( V_439 -> V_441 ) ) ;
F_24 () ;
* V_468 = sizeof( * V_439 ) ;
return 0 ;
}
static int F_330 ( struct V_281 * V_23 , struct V_289 * V_439 ,
int * V_468 , int V_469 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
F_223 ( struct V_342 * , V_343 , V_439 ) ;
if ( V_469 )
return - V_470 ;
V_343 -> V_383 = V_384 ;
V_343 -> V_358 = V_14 -> V_92 ;
V_343 -> V_385 = V_14 -> V_207 ;
V_343 -> V_356 = 0 ;
F_20 () ;
V_4 = F_309 ( F_78 ( V_24 ) , V_14 -> V_92 ) ;
if ( V_4 ) {
V_343 -> V_355 = V_4 -> type ;
V_343 -> V_359 = V_4 -> V_440 ;
memcpy ( V_343 -> V_360 , V_4 -> V_472 , V_4 -> V_440 ) ;
} else {
V_343 -> V_355 = 0 ;
V_343 -> V_359 = 0 ;
}
F_24 () ;
* V_468 = F_282 ( struct V_342 , V_360 ) + V_343 -> V_359 ;
return 0 ;
}
static int F_331 ( struct V_3 * V_4 , struct V_473 * V_200 ,
int V_474 )
{
switch ( V_200 -> type ) {
case V_475 :
if ( V_200 -> V_476 != V_4 -> V_440 )
return - V_247 ;
if ( V_474 > 0 )
return F_332 ( V_4 , V_200 -> V_31 ) ;
else
return F_333 ( V_4 , V_200 -> V_31 ) ;
break;
case V_477 :
return F_334 ( V_4 , V_474 ) ;
case V_478 :
return F_335 ( V_4 , V_474 ) ;
case V_479 :
if ( V_200 -> V_476 != V_4 -> V_440 )
return - V_247 ;
if ( V_474 > 0 )
return F_336 ( V_4 , V_200 -> V_31 ) ;
else
return F_337 ( V_4 , V_200 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_338 ( struct V_3 * V_4 ,
struct V_473 * * V_480 )
{
struct V_473 * V_481 ;
while ( ( V_481 = * V_480 ) != NULL ) {
if ( V_481 -> V_92 == V_4 -> V_92 ) {
F_331 ( V_4 , V_481 , - 1 ) ;
* V_480 = V_481 -> V_482 ;
F_203 ( V_481 ) ;
} else
V_480 = & V_481 -> V_482 ;
}
}
static int F_339 ( struct V_23 * V_24 , struct V_483 * V_484 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_473 * V_481 , * V_200 ;
struct V_3 * V_4 ;
int V_91 ;
F_76 () ;
V_91 = - V_292 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_484 -> V_485 ) ;
if ( ! V_4 )
goto V_486;
V_91 = - V_247 ;
if ( V_484 -> V_487 > V_4 -> V_440 )
goto V_486;
V_91 = - V_183 ;
V_200 = F_340 ( sizeof( * V_200 ) , V_255 ) ;
if ( V_200 == NULL )
goto V_486;
V_91 = 0 ;
for ( V_481 = V_14 -> V_488 ; V_481 ; V_481 = V_481 -> V_482 ) {
if ( V_481 -> V_92 == V_484 -> V_485 &&
V_481 -> type == V_484 -> V_489 &&
V_481 -> V_476 == V_484 -> V_487 &&
memcmp ( V_481 -> V_31 , V_484 -> V_490 , V_481 -> V_476 ) == 0 ) {
V_481 -> V_201 ++ ;
F_203 ( V_200 ) ;
goto V_486;
}
}
V_200 -> type = V_484 -> V_489 ;
V_200 -> V_92 = V_484 -> V_485 ;
V_200 -> V_476 = V_484 -> V_487 ;
memcpy ( V_200 -> V_31 , V_484 -> V_490 , V_200 -> V_476 ) ;
memset ( V_200 -> V_31 + V_200 -> V_476 , 0 , sizeof( V_200 -> V_31 ) - V_200 -> V_476 ) ;
V_200 -> V_201 = 1 ;
V_200 -> V_482 = V_14 -> V_488 ;
V_14 -> V_488 = V_200 ;
V_91 = F_331 ( V_4 , V_200 , 1 ) ;
if ( V_91 ) {
V_14 -> V_488 = V_200 -> V_482 ;
F_203 ( V_200 ) ;
}
V_486:
F_79 () ;
return V_91 ;
}
static int F_341 ( struct V_23 * V_24 , struct V_483 * V_484 )
{
struct V_473 * V_481 , * * V_480 ;
F_76 () ;
for ( V_480 = & F_36 ( V_24 ) -> V_488 ; ( V_481 = * V_480 ) != NULL ; V_480 = & V_481 -> V_482 ) {
if ( V_481 -> V_92 == V_484 -> V_485 &&
V_481 -> type == V_484 -> V_489 &&
V_481 -> V_476 == V_484 -> V_487 &&
memcmp ( V_481 -> V_31 , V_484 -> V_490 , V_481 -> V_476 ) == 0 ) {
if ( -- V_481 -> V_201 == 0 ) {
struct V_3 * V_4 ;
* V_480 = V_481 -> V_482 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_481 -> V_92 ) ;
if ( V_4 )
F_331 ( V_4 , V_481 , - 1 ) ;
F_203 ( V_481 ) ;
}
break;
}
}
F_79 () ;
return 0 ;
}
static void F_302 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_473 * V_481 ;
if ( ! V_14 -> V_488 )
return;
F_76 () ;
while ( ( V_481 = V_14 -> V_488 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_488 = V_481 -> V_482 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_481 -> V_92 ) ;
if ( V_4 != NULL )
F_331 ( V_4 , V_481 , - 1 ) ;
F_203 ( V_481 ) ;
}
F_79 () ;
}
static int
F_342 ( struct V_281 * V_23 , int V_491 , int V_492 , char T_7 * V_493 , unsigned int V_494 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_8 ;
if ( V_491 != V_462 )
return - V_495 ;
switch ( V_492 ) {
case V_496 :
case V_497 :
{
struct V_483 V_484 ;
int V_173 = V_494 ;
memset ( & V_484 , 0 , sizeof( V_484 ) ) ;
if ( V_173 < sizeof( struct V_498 ) )
return - V_247 ;
if ( V_173 > sizeof( V_484 ) )
V_173 = sizeof( V_484 ) ;
if ( F_184 ( & V_484 , V_493 , V_173 ) )
return - V_248 ;
if ( V_173 < ( V_484 . V_487 + F_282 ( struct V_498 , V_490 ) ) )
return - V_247 ;
if ( V_492 == V_496 )
V_8 = F_339 ( V_24 , & V_484 ) ;
else
V_8 = F_341 ( V_24 , & V_484 ) ;
return V_8 ;
}
case V_499 :
case V_500 :
{
union V_99 V_100 ;
int V_173 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_173 = sizeof( V_100 . V_501 ) ;
break;
case V_43 :
default:
V_173 = sizeof( V_100 . V_102 ) ;
break;
}
if ( V_494 < V_173 )
return - V_247 ;
if ( F_184 ( & V_100 . V_501 , V_493 , V_173 ) )
return - V_248 ;
return F_303 ( V_24 , & V_100 , 0 ,
V_492 == V_500 ) ;
}
case V_502 :
{
int V_208 ;
if ( V_494 != sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
F_36 ( V_24 ) -> V_375 = V_208 ;
return 0 ;
}
case V_503 :
{
int V_208 ;
if ( V_494 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_504 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
switch ( V_208 ) {
case V_38 :
case V_41 :
case V_43 :
V_14 -> V_37 = V_208 ;
return 0 ;
default:
return - V_247 ;
}
}
case V_505 :
{
unsigned int V_208 ;
if ( V_494 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_504 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_372 = V_208 ;
return 0 ;
}
case V_506 :
{
unsigned int V_208 ;
if ( V_494 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_504 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_420 = ! ! V_208 ;
return 0 ;
}
case V_467 :
{
int V_208 ;
if ( V_494 < sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_464 = ! ! V_208 ;
return 0 ;
}
case V_507 :
{
int V_208 ;
if ( V_494 < sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_357 = ! ! V_208 ;
return 0 ;
}
case V_508 :
{
int V_208 ;
if ( V_23 -> type != V_416 )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_504 ;
if ( V_494 < sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_374 = ! ! V_208 ;
return 0 ;
}
case V_509 :
{
int V_208 ;
if ( V_494 != sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_55 = V_208 ;
return 0 ;
}
case V_510 :
{
int V_208 ;
if ( V_494 != sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
return F_193 ( V_24 , V_208 & 0xffff , V_208 >> 16 ) ;
}
case V_511 :
{
if ( ! V_14 -> V_26 )
return - V_247 ;
return F_191 ( V_14 , V_493 , V_494 ) ;
}
case V_512 :
{
unsigned int V_208 ;
if ( V_494 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_504 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_405 = ! ! V_208 ;
return 0 ;
}
case V_513 :
{
int V_208 ;
if ( V_494 != sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_493 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_16 = V_208 ? F_1 : F_236 ;
return 0 ;
}
default:
return - V_495 ;
}
}
static int F_343 ( struct V_281 * V_23 , int V_491 , int V_492 ,
char T_7 * V_493 , int T_7 * V_494 )
{
int V_173 ;
int V_208 , V_514 = sizeof( V_208 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
void * V_80 = & V_208 ;
union V_515 V_516 ;
struct V_517 V_518 ;
if ( V_491 != V_462 )
return - V_495 ;
if ( F_344 ( V_173 , V_494 ) )
return - V_248 ;
if ( V_173 < 0 )
return - V_247 ;
switch ( V_492 ) {
case V_519 :
F_69 ( & V_24 -> V_129 . V_78 ) ;
memcpy ( & V_516 , & V_14 -> V_118 , sizeof( V_516 ) ) ;
memset ( & V_14 -> V_118 , 0 , sizeof( V_14 -> V_118 ) ) ;
F_70 ( & V_24 -> V_129 . V_78 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_514 = sizeof( struct V_520 ) ;
V_516 . V_119 . V_363 += V_516 . V_119 . V_148 ;
V_80 = & V_516 . V_119 ;
} else {
V_514 = sizeof( struct V_521 ) ;
V_516 . V_362 . V_363 += V_516 . V_362 . V_148 ;
V_80 = & V_516 . V_362 ;
}
break;
case V_467 :
V_208 = V_14 -> V_464 ;
break;
case V_507 :
V_208 = V_14 -> V_357 ;
break;
case V_508 :
V_208 = V_14 -> V_374 ;
break;
case V_503 :
V_208 = V_14 -> V_37 ;
break;
case V_522 :
if ( V_173 > sizeof( int ) )
V_173 = sizeof( int ) ;
if ( F_184 ( & V_208 , V_493 , V_173 ) )
return - V_248 ;
switch ( V_208 ) {
case V_38 :
V_208 = sizeof( struct V_523 ) ;
break;
case V_41 :
V_208 = sizeof( struct V_524 ) ;
break;
case V_43 :
V_208 = sizeof( struct V_143 ) ;
break;
default:
return - V_247 ;
}
break;
case V_505 :
V_208 = V_14 -> V_372 ;
break;
case V_506 :
V_208 = V_14 -> V_420 ;
break;
case V_509 :
V_208 = V_14 -> V_55 ;
break;
case V_510 :
V_208 = ( V_14 -> V_26 ?
( ( T_6 ) V_14 -> V_26 -> V_251 |
( ( T_6 ) V_14 -> V_26 -> type << 16 ) |
( ( T_6 ) V_14 -> V_26 -> V_46 << 24 ) ) :
0 ) ;
break;
case V_525 :
if ( ! V_14 -> V_203 )
return - V_247 ;
V_518 . V_526 = F_345 ( & V_14 -> V_203 -> V_207 ) ;
V_518 . V_527 = F_345 ( & V_14 -> V_203 -> V_216 ) ;
V_518 . V_528 = F_345 ( & V_14 -> V_203 -> V_217 ) ;
V_80 = & V_518 ;
V_514 = sizeof( V_518 ) ;
break;
case V_512 :
V_208 = V_14 -> V_405 ;
break;
case V_513 :
V_208 = F_29 ( V_14 ) ;
break;
default:
return - V_495 ;
}
if ( V_173 > V_514 )
V_173 = V_514 ;
if ( F_346 ( V_173 , V_494 ) )
return - V_248 ;
if ( F_347 ( V_493 , V_80 , V_173 ) )
return - V_248 ;
return 0 ;
}
static int F_348 ( struct V_529 * V_530 ,
unsigned long V_283 , void * V_531 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_349 ( V_531 ) ;
struct V_226 * V_226 = F_173 ( V_4 ) ;
F_20 () ;
F_350 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_36 ( V_24 ) ;
switch ( V_283 ) {
case V_532 :
if ( V_14 -> V_488 )
F_338 ( V_4 , & V_14 -> V_488 ) ;
case V_533 :
if ( V_4 -> V_92 == V_14 -> V_92 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_40 ( V_24 , false ) ;
V_24 -> V_437 = V_294 ;
if ( ! F_150 ( V_24 , V_198 ) )
V_24 -> V_438 ( V_24 ) ;
}
if ( V_283 == V_532 ) {
F_27 ( V_14 ) ;
V_14 -> V_92 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_289 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
}
break;
case V_534 :
if ( V_4 -> V_92 == V_14 -> V_92 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_207 )
F_35 ( V_24 ) ;
F_44 ( & V_14 -> V_29 ) ;
}
break;
}
}
F_24 () ;
return V_535 ;
}
static int F_351 ( struct V_281 * V_23 , unsigned int V_536 ,
unsigned long V_537 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_536 ) {
case V_538 :
{
int V_539 = F_352 ( V_24 ) ;
return F_346 ( V_539 , ( int T_7 * ) V_537 ) ;
}
case V_540 :
{
struct V_1 * V_2 ;
int V_539 = 0 ;
F_69 ( & V_24 -> V_129 . V_78 ) ;
V_2 = F_353 ( & V_24 -> V_129 ) ;
if ( V_2 )
V_539 = V_2 -> V_173 ;
F_70 ( & V_24 -> V_129 . V_78 ) ;
return F_346 ( V_539 , ( int T_7 * ) V_537 ) ;
}
case V_541 :
return F_354 ( V_24 , (struct V_542 T_7 * ) V_537 ) ;
case V_543 :
return F_355 ( V_24 , (struct V_44 T_7 * ) V_537 ) ;
#ifdef F_356
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
case V_557 :
return V_558 . V_559 ( V_23 , V_536 , V_537 ) ;
#endif
default:
return - V_560 ;
}
return 0 ;
}
static unsigned int F_357 ( struct V_561 * V_561 , struct V_281 * V_23 ,
T_10 * V_562 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned int V_563 = F_358 ( V_561 , V_23 , V_562 ) ;
F_69 ( & V_24 -> V_129 . V_78 ) ;
if ( V_14 -> V_77 . V_68 ) {
if ( ! F_128 ( V_14 , & V_14 -> V_77 ,
V_160 ) )
V_563 |= V_564 | V_565 ;
}
if ( V_14 -> V_195 && F_145 ( V_14 , NULL ) == V_192 )
V_14 -> V_195 = 0 ;
F_70 ( & V_24 -> V_129 . V_78 ) ;
F_69 ( & V_24 -> V_566 . V_78 ) ;
if ( V_14 -> V_182 . V_68 ) {
if ( F_64 ( V_14 , & V_14 -> V_182 , V_169 ) )
V_563 |= V_567 | V_568 ;
}
F_70 ( & V_24 -> V_566 . V_78 ) ;
return V_563 ;
}
static void F_359 ( struct V_569 * V_570 )
{
struct V_561 * V_561 = V_570 -> V_571 ;
struct V_281 * V_23 = V_561 -> V_572 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_120 ( & F_36 ( V_24 ) -> V_573 ) ;
}
static void F_360 ( struct V_569 * V_570 )
{
struct V_561 * V_561 = V_570 -> V_571 ;
struct V_281 * V_23 = V_561 -> V_572 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_109 ( & F_36 ( V_24 ) -> V_573 ) ;
}
static void F_361 ( struct V_104 * V_68 , unsigned int V_574 ,
unsigned int V_173 )
{
int V_200 ;
for ( V_200 = 0 ; V_200 < V_173 ; V_200 ++ ) {
if ( F_22 ( V_68 [ V_200 ] . V_69 ) ) {
if ( F_49 ( V_68 [ V_200 ] . V_69 ) )
F_362 ( V_68 [ V_200 ] . V_69 ) ;
else
F_363 ( ( unsigned long ) V_68 [ V_200 ] . V_69 ,
V_574 ) ;
V_68 [ V_200 ] . V_69 = NULL ;
}
}
F_203 ( V_68 ) ;
}
static char * F_364 ( unsigned long V_574 )
{
char * V_69 ;
T_11 V_575 = V_255 | V_576 |
V_577 | V_578 | V_579 ;
V_69 = ( char * ) F_365 ( V_575 , V_574 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_366 ( ( 1 << V_574 ) * V_139 ) ;
if ( V_69 )
return V_69 ;
V_575 &= ~ V_579 ;
V_69 = ( char * ) F_365 ( V_575 , V_574 ) ;
if ( V_69 )
return V_69 ;
return NULL ;
}
static struct V_104 * F_367 ( struct V_580 * V_501 , int V_574 )
{
unsigned int V_581 = V_501 -> V_113 ;
struct V_104 * V_68 ;
int V_200 ;
V_68 = F_368 ( V_581 , sizeof( struct V_104 ) , V_255 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
for ( V_200 = 0 ; V_200 < V_581 ; V_200 ++ ) {
V_68 [ V_200 ] . V_69 = F_364 ( V_574 ) ;
if ( F_2 ( ! V_68 [ V_200 ] . V_69 ) )
goto V_582;
}
V_130:
return V_68 ;
V_582:
F_361 ( V_68 , V_574 , V_581 ) ;
V_68 = NULL ;
goto V_130;
}
static int F_303 ( struct V_23 * V_24 , union V_99 * V_100 ,
int V_583 , int V_182 )
{
struct V_104 * V_68 = NULL ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_584 , V_574 = 0 ;
struct V_62 * V_63 ;
struct V_75 * V_76 ;
T_9 V_207 ;
int V_91 = - V_247 ;
struct V_580 * V_501 = & V_100 -> V_501 ;
if ( ! V_583 && V_182 && ( V_14 -> V_37 > V_41 ) ) {
F_369 ( L_7 ) ;
goto V_130;
}
V_63 = V_182 ? & V_14 -> V_182 : & V_14 -> V_77 ;
V_76 = V_182 ? & V_24 -> V_566 : & V_24 -> V_129 ;
V_91 = - V_504 ;
if ( ! V_583 ) {
if ( F_91 ( & V_14 -> V_573 ) )
goto V_130;
if ( F_136 ( V_63 ) )
goto V_130;
}
if ( V_501 -> V_113 ) {
V_91 = - V_504 ;
if ( F_2 ( V_63 -> V_68 ) )
goto V_130;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_115 = V_585 ;
break;
case V_41 :
V_14 -> V_115 = V_586 ;
break;
case V_43 :
V_14 -> V_115 = V_587 ;
break;
}
V_91 = - V_247 ;
if ( F_2 ( ( int ) V_501 -> V_111 <= 0 ) )
goto V_130;
if ( F_2 ( ! F_370 ( V_501 -> V_111 ) ) )
goto V_130;
if ( V_14 -> V_37 >= V_43 &&
( int ) ( V_501 -> V_111 -
F_84 ( V_100 -> V_102 . V_125 ) ) <= 0 )
goto V_130;
if ( F_2 ( V_501 -> V_588 < V_14 -> V_115 +
V_14 -> V_372 ) )
goto V_130;
if ( F_2 ( V_501 -> V_588 & ( V_589 - 1 ) ) )
goto V_130;
V_63 -> V_67 = V_501 -> V_111 / V_501 -> V_588 ;
if ( F_2 ( V_63 -> V_67 == 0 ) )
goto V_130;
if ( F_2 ( ( V_63 -> V_67 * V_501 -> V_113 ) !=
V_501 -> V_590 ) )
goto V_130;
V_91 = - V_256 ;
V_574 = F_371 ( V_501 -> V_111 ) ;
V_68 = F_367 ( V_501 , V_574 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( ! V_182 )
F_82 ( V_14 , V_63 , V_68 , V_100 ) ;
break;
default:
break;
}
}
else {
V_91 = - V_247 ;
if ( F_2 ( V_501 -> V_590 ) )
goto V_130;
}
F_308 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_584 = V_14 -> V_25 ;
V_207 = V_14 -> V_207 ;
if ( V_584 ) {
V_14 -> V_207 = 0 ;
F_40 ( V_24 , false ) ;
}
F_44 ( & V_14 -> V_29 ) ;
F_45 () ;
V_91 = - V_504 ;
F_196 ( & V_14 -> V_413 ) ;
if ( V_583 || F_91 ( & V_14 -> V_573 ) == 0 ) {
V_91 = 0 ;
F_69 ( & V_76 -> V_78 ) ;
F_372 ( V_63 -> V_68 , V_68 ) ;
V_63 -> V_177 = ( V_501 -> V_590 - 1 ) ;
V_63 -> V_71 = 0 ;
V_63 -> V_70 = V_501 -> V_588 ;
F_70 ( & V_76 -> V_78 ) ;
F_372 ( V_63 -> V_591 , V_574 ) ;
F_372 ( V_63 -> V_592 , V_501 -> V_113 ) ;
V_63 -> V_593 = V_501 -> V_111 / V_139 ;
V_14 -> V_27 . F_72 = ( V_14 -> V_77 . V_68 ) ?
V_186 : F_246 ;
F_148 ( V_76 ) ;
if ( F_91 ( & V_14 -> V_573 ) )
F_151 ( L_8 ,
F_91 ( & V_14 -> V_573 ) ) ;
}
F_202 ( & V_14 -> V_413 ) ;
F_46 ( & V_14 -> V_29 ) ;
if ( V_584 ) {
V_14 -> V_207 = V_207 ;
F_35 ( V_24 ) ;
}
F_44 ( & V_14 -> V_29 ) ;
if ( V_583 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_182 )
F_67 ( V_14 , V_76 ) ;
}
F_310 ( V_24 ) ;
if ( V_68 )
F_361 ( V_68 , V_574 , V_501 -> V_113 ) ;
V_130:
return V_91 ;
}
static int F_373 ( struct V_561 * V_561 , struct V_281 * V_23 ,
struct V_569 * V_570 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned long V_594 , V_595 ;
struct V_62 * V_63 ;
unsigned long V_137 ;
int V_91 = - V_247 ;
int V_200 ;
if ( V_570 -> V_596 )
return - V_247 ;
F_196 ( & V_14 -> V_413 ) ;
V_595 = 0 ;
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_182 ; V_63 ++ ) {
if ( V_63 -> V_68 ) {
V_595 += V_63 -> V_592
* V_63 -> V_593
* V_139 ;
}
}
if ( V_595 == 0 )
goto V_130;
V_594 = V_570 -> V_597 - V_570 -> V_598 ;
if ( V_594 != V_595 )
goto V_130;
V_137 = V_570 -> V_598 ;
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_182 ; V_63 ++ ) {
if ( V_63 -> V_68 == NULL )
continue;
for ( V_200 = 0 ; V_200 < V_63 -> V_592 ; V_200 ++ ) {
struct V_30 * V_30 ;
void * V_599 = V_63 -> V_68 [ V_200 ] . V_69 ;
int V_600 ;
for ( V_600 = 0 ; V_600 < V_63 -> V_593 ; V_600 ++ ) {
V_30 = F_48 ( V_599 ) ;
V_91 = F_374 ( V_570 , V_137 , V_30 ) ;
if ( F_2 ( V_91 ) )
goto V_130;
V_137 += V_139 ;
V_599 += V_139 ;
}
}
}
F_120 ( & V_14 -> V_573 ) ;
V_570 -> V_601 = & V_602 ;
V_91 = 0 ;
V_130:
F_202 ( & V_14 -> V_413 ) ;
return V_91 ;
}
static void * F_375 ( struct V_603 * V_604 , T_12 * V_605 )
__acquires( T_13 )
{
struct V_226 * V_226 = F_376 ( V_604 ) ;
F_20 () ;
return F_377 ( & V_226 -> V_430 . V_455 , * V_605 ) ;
}
static void * F_378 ( struct V_603 * V_604 , void * V_606 , T_12 * V_605 )
{
struct V_226 * V_226 = F_376 ( V_604 ) ;
return F_379 ( V_606 , & V_226 -> V_430 . V_455 , V_605 ) ;
}
static void F_380 ( struct V_603 * V_604 , void * V_606 )
__releases( T_13 )
{
F_24 () ;
}
static int F_381 ( struct V_603 * V_604 , void * V_606 )
{
if ( V_606 == V_607 )
F_382 ( V_604 , L_9 ) ;
else {
struct V_23 * V_390 = F_383 ( V_606 ) ;
const struct V_13 * V_14 = F_36 ( V_390 ) ;
F_384 ( V_604 ,
L_10 ,
V_390 ,
F_91 ( & V_390 -> V_608 ) ,
V_390 -> V_347 ,
F_116 ( V_14 -> V_207 ) ,
V_14 -> V_92 ,
V_14 -> V_25 ,
F_91 ( & V_390 -> V_189 ) ,
F_385 ( F_386 ( V_604 ) , F_387 ( V_390 ) ) ,
F_388 ( V_390 ) ) ;
}
return 0 ;
}
static int F_389 ( struct V_609 * V_609 , struct V_561 * V_561 )
{
return F_390 ( V_609 , V_561 , & V_610 ,
sizeof( struct V_611 ) ) ;
}
static int T_14 F_391 ( struct V_226 * V_226 )
{
F_318 ( & V_226 -> V_430 . V_431 ) ;
F_392 ( & V_226 -> V_430 . V_455 ) ;
if ( ! F_393 ( L_11 , 0 , V_226 -> V_612 , & V_613 ) )
return - V_256 ;
return 0 ;
}
static void T_15 F_394 ( struct V_226 * V_226 )
{
F_395 ( L_11 , V_226 -> V_612 ) ;
}
static void T_16 F_396 ( void )
{
F_397 ( & V_614 ) ;
F_398 ( & V_615 ) ;
F_399 ( V_240 ) ;
F_400 ( & V_450 ) ;
}
static int T_17 F_401 ( void )
{
int V_616 = F_402 ( & V_450 , 0 ) ;
if ( V_616 != 0 )
goto V_130;
F_403 ( & V_617 ) ;
F_404 ( & V_615 ) ;
F_405 ( & V_614 ) ;
V_130:
return V_616 ;
}
