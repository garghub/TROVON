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
return F_156 ( F_157 ( V_2 ) , V_207 ) ;
}
static unsigned int F_158 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
unsigned int V_208 = F_159 ( & V_206 -> V_209 ) ;
return V_208 % V_207 ;
}
static unsigned int F_160 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
return F_11 () % V_207 ;
}
static unsigned int F_161 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
return F_162 ( V_207 ) ;
}
static unsigned int F_163 ( struct V_205 * V_206 ,
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
V_200 = V_213 = F_164 ( int , V_14 -> V_203 -> V_23 , V_207 - 1 ) ;
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
static unsigned int F_165 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
return F_166 ( V_2 ) % V_207 ;
}
static unsigned int F_167 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
struct V_218 * V_219 ;
unsigned int V_8 = 0 ;
F_20 () ;
V_219 = F_21 ( V_206 -> V_218 ) ;
if ( V_219 )
V_8 = F_168 ( V_219 , V_2 ) % V_207 ;
F_24 () ;
return V_8 ;
}
static bool F_169 ( struct V_205 * V_206 , T_2 V_220 )
{
return V_206 -> V_46 & ( V_220 >> 8 ) ;
}
static int F_170 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_205 * V_206 = V_222 -> V_224 ;
unsigned int V_207 = F_171 ( V_206 -> V_225 ) ;
struct V_226 * V_226 = F_172 ( & V_206 -> V_226 ) ;
struct V_13 * V_14 ;
unsigned int V_174 ;
if ( ! F_173 ( F_174 ( V_4 ) , V_226 ) || ! V_207 ) {
F_17 ( V_2 ) ;
return 0 ;
}
if ( F_169 ( V_206 , V_227 ) ) {
V_2 = F_175 ( V_226 , V_2 , V_228 ) ;
if ( ! V_2 )
return 0 ;
}
switch ( V_206 -> type ) {
case V_229 :
default:
V_174 = F_155 ( V_206 , V_2 , V_207 ) ;
break;
case V_230 :
V_174 = F_158 ( V_206 , V_2 , V_207 ) ;
break;
case V_231 :
V_174 = F_160 ( V_206 , V_2 , V_207 ) ;
break;
case V_232 :
V_174 = F_161 ( V_206 , V_2 , V_207 ) ;
break;
case V_233 :
V_174 = F_165 ( V_206 , V_2 , V_207 ) ;
break;
case V_234 :
V_174 = F_163 ( V_206 , V_2 , 0 , false , V_207 ) ;
break;
case V_235 :
case V_236 :
V_174 = F_167 ( V_206 , V_2 , V_207 ) ;
break;
}
if ( F_169 ( V_206 , V_237 ) )
V_174 = F_163 ( V_206 , V_2 , V_174 , true , V_207 ) ;
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
F_176 ( V_200 >= V_206 -> V_225 ) ;
V_206 -> V_215 [ V_200 ] = V_206 -> V_215 [ V_206 -> V_225 - 1 ] ;
V_206 -> V_225 -- ;
F_44 ( & V_206 -> V_78 ) ;
}
static bool F_177 ( struct V_221 * V_238 , struct V_23 * V_24 )
{
if ( V_24 -> V_239 != V_240 )
return false ;
return V_238 -> V_224 == F_36 ( V_24 ) -> V_26 ;
}
static void F_178 ( struct V_205 * V_206 )
{
switch ( V_206 -> type ) {
case V_230 :
F_179 ( & V_206 -> V_209 , 0 ) ;
break;
case V_235 :
case V_236 :
F_28 ( V_206 -> V_218 , NULL ) ;
break;
}
}
static void F_180 ( struct V_205 * V_206 , struct V_218 * V_241 )
{
struct V_218 * V_242 ;
F_46 ( & V_206 -> V_78 ) ;
V_242 = F_181 ( V_206 -> V_218 , F_182 ( & V_206 -> V_78 ) ) ;
F_26 ( V_206 -> V_218 , V_241 ) ;
F_44 ( & V_206 -> V_78 ) ;
if ( V_242 ) {
F_45 () ;
F_183 ( V_242 ) ;
}
}
static int F_184 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_173 )
{
struct V_218 * V_241 ;
struct V_243 V_244 ;
int V_8 ;
if ( F_150 ( & V_14 -> V_24 , V_245 ) )
return - V_246 ;
if ( V_173 != sizeof( V_244 ) )
return - V_247 ;
if ( F_185 ( & V_244 , V_80 , V_173 ) )
return - V_248 ;
V_8 = F_186 ( & V_241 , & V_244 , NULL , false ) ;
if ( V_8 )
return V_8 ;
F_180 ( V_14 -> V_26 , V_241 ) ;
return 0 ;
}
static int F_187 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_173 )
{
struct V_218 * V_241 ;
T_6 V_249 ;
if ( F_150 ( & V_14 -> V_24 , V_245 ) )
return - V_246 ;
if ( V_173 != sizeof( V_249 ) )
return - V_247 ;
if ( F_185 ( & V_249 , V_80 , V_173 ) )
return - V_248 ;
V_241 = F_188 ( V_249 , V_250 ) ;
if ( F_189 ( V_241 ) )
return F_190 ( V_241 ) ;
F_180 ( V_14 -> V_26 , V_241 ) ;
return 0 ;
}
static int F_191 ( struct V_13 * V_14 , char T_7 * V_80 ,
unsigned int V_173 )
{
switch ( V_14 -> V_26 -> type ) {
case V_235 :
return F_184 ( V_14 , V_80 , V_173 ) ;
case V_236 :
return F_187 ( V_14 , V_80 , V_173 ) ;
default:
return - V_247 ;
} ;
}
static void F_192 ( struct V_205 * V_206 )
{
switch ( V_206 -> type ) {
case V_235 :
case V_236 :
F_180 ( V_206 , NULL ) ;
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
F_172 ( & V_206 -> V_226 ) == F_78 ( V_24 ) ) {
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
F_179 ( & V_253 -> V_259 , 0 ) ;
F_178 ( V_253 ) ;
V_253 -> V_27 . type = V_14 -> V_27 . type ;
V_253 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_253 -> V_27 . F_72 = F_170 ;
V_253 -> V_27 . V_224 = V_253 ;
V_253 -> V_27 . V_260 = F_177 ;
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
if ( ! F_173 ( F_174 ( V_4 ) , F_78 ( V_24 ) ) )
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
struct V_286 V_287 ;
T_9 V_288 = 0 ;
int V_91 ;
int V_289 = 0 ;
if ( V_284 ) {
if ( V_283 -> V_290 < sizeof( struct V_291 ) )
return - V_247 ;
if ( V_283 -> V_290 == sizeof( struct V_268 ) )
V_288 = V_284 -> V_279 ;
} else
return - V_292 ;
V_284 -> V_277 [ sizeof( V_284 -> V_277 ) - 1 ] = 0 ;
V_293:
F_20 () ;
V_4 = F_224 ( F_78 ( V_24 ) , V_284 -> V_277 ) ;
V_91 = - V_294 ;
if ( V_4 == NULL )
goto V_295;
V_91 = - V_296 ;
if ( ! ( V_4 -> V_46 & V_297 ) )
goto V_295;
if ( F_2 ( F_150 ( V_24 , V_298 ) ) ) {
if ( ! F_225 ( V_4 ) ) {
V_91 = - V_299 ;
goto V_295;
}
V_289 = 4 ;
}
V_91 = - V_300 ;
if ( V_173 > V_4 -> V_301 + V_4 -> V_302 + V_303 + V_289 )
goto V_295;
if ( ! V_2 ) {
T_8 V_304 = F_226 ( V_4 ) ;
int V_305 = V_4 -> V_306 ;
unsigned int V_307 = V_4 -> V_308 ? V_4 -> V_302 : 0 ;
F_24 () ;
V_2 = F_227 ( V_24 , V_173 + V_304 + V_305 , 0 , V_255 ) ;
if ( V_2 == NULL )
return - V_183 ;
F_228 ( V_2 , V_304 ) ;
F_229 ( V_2 ) ;
if ( V_307 ) {
V_2 -> V_80 -= V_307 ;
V_2 -> V_309 -= V_307 ;
if ( V_173 < V_307 )
F_229 ( V_2 ) ;
}
V_91 = F_230 ( F_231 ( V_2 , V_173 ) , V_283 , V_173 ) ;
if ( V_91 )
goto V_310;
goto V_293;
}
if ( ! F_232 ( V_4 , V_2 -> V_80 , V_173 ) ) {
V_91 = - V_247 ;
goto V_295;
}
if ( V_173 > ( V_4 -> V_301 + V_4 -> V_302 + V_289 ) &&
! F_209 ( V_4 , V_2 ) ) {
V_91 = - V_300 ;
goto V_295;
}
V_287 . V_311 = V_24 -> V_312 ;
if ( V_283 -> V_313 ) {
V_91 = F_233 ( V_24 , V_283 , & V_287 ) ;
if ( F_2 ( V_91 ) )
goto V_295;
}
V_2 -> V_280 = V_288 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_314 = V_24 -> V_315 ;
V_2 -> V_316 = V_24 -> V_317 ;
F_234 ( V_24 , V_287 . V_311 , & F_235 ( V_2 ) -> V_318 ) ;
if ( F_2 ( V_289 == 4 ) )
V_2 -> V_319 = 1 ;
F_236 ( V_2 , 0 ) ;
F_237 ( V_2 ) ;
F_24 () ;
return V_173 ;
V_295:
F_24 () ;
V_310:
F_17 ( V_2 ) ;
return V_91 ;
}
static unsigned int F_238 ( struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_320 )
{
struct V_321 * V_322 ;
F_20 () ;
V_322 = F_21 ( V_24 -> V_321 ) ;
if ( V_322 != NULL )
V_320 = F_168 ( V_322 -> V_219 , V_2 ) ;
F_24 () ;
return V_320 ;
}
static int F_239 ( const struct V_1 * V_2 ,
struct V_323 * V_324 )
{
* V_324 = ( const struct V_323 ) { 0 } ;
if ( F_240 ( V_2 , V_324 , F_241 () ) )
F_55 () ;
return 0 ;
}
static int F_242 ( struct V_282 * V_283 , const struct V_1 * V_2 ,
T_8 * V_173 )
{
struct V_323 V_324 ;
if ( * V_173 < sizeof( V_324 ) )
return - V_247 ;
* V_173 -= sizeof( V_324 ) ;
if ( F_239 ( V_2 , & V_324 ) )
return - V_247 ;
return F_243 ( V_283 , ( void * ) & V_324 , sizeof( V_324 ) ) ;
}
static int F_244 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_23 * V_24 ;
struct V_325 * V_326 ;
struct V_13 * V_14 ;
T_5 * V_327 = V_2 -> V_80 ;
int V_328 = V_2 -> V_173 ;
unsigned int V_329 , V_320 ;
bool V_330 = false ;
if ( V_2 -> V_270 == V_271 )
goto V_10;
V_24 = V_222 -> V_224 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_173 ( F_174 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_308 ) {
if ( V_24 -> V_331 != V_332 )
F_218 ( V_2 , V_2 -> V_80 - F_219 ( V_2 ) ) ;
else if ( V_2 -> V_270 == V_333 ) {
F_245 ( V_2 , F_246 ( V_2 ) ) ;
}
}
V_329 = V_2 -> V_173 ;
V_320 = F_238 ( V_2 , V_24 , V_329 ) ;
if ( ! V_320 )
goto V_334;
if ( V_329 > V_320 )
V_329 = V_320 ;
if ( F_91 ( & V_24 -> V_189 ) >= V_24 -> V_188 )
goto V_335;
if ( F_247 ( V_2 ) ) {
struct V_1 * V_336 = F_248 ( V_2 , V_272 ) ;
if ( V_336 == NULL )
goto V_335;
if ( V_327 != V_2 -> V_80 ) {
V_2 -> V_80 = V_327 ;
V_2 -> V_173 = V_328 ;
}
F_249 ( V_2 ) ;
V_2 = V_336 ;
}
F_250 ( sizeof( * F_217 ( V_2 ) ) + V_337 - 8 ) ;
V_326 = & F_217 ( V_2 ) -> V_274 . V_338 ;
V_326 -> V_339 = V_4 -> type ;
V_326 -> V_340 = V_2 -> V_270 ;
if ( F_2 ( V_14 -> V_341 ) )
V_326 -> V_342 = V_223 -> V_92 ;
else
V_326 -> V_342 = V_4 -> V_92 ;
V_326 -> V_343 = F_251 ( V_2 , V_326 -> V_344 ) ;
F_217 ( V_2 ) -> V_274 . V_345 = V_2 -> V_173 ;
if ( F_252 ( V_2 , V_329 ) )
goto V_335;
F_253 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_215 ( V_2 ) ;
F_216 ( V_2 ) ;
F_46 ( & V_24 -> V_129 . V_78 ) ;
V_14 -> V_118 . V_346 . V_347 ++ ;
F_254 ( V_24 , V_2 ) ;
F_255 ( & V_24 -> V_129 , V_2 ) ;
F_44 ( & V_24 -> V_129 . V_78 ) ;
V_24 -> V_155 ( V_24 ) ;
return 0 ;
V_335:
V_330 = true ;
F_46 ( & V_24 -> V_129 . V_78 ) ;
V_14 -> V_118 . V_346 . V_148 ++ ;
F_120 ( & V_24 -> V_348 ) ;
F_44 ( & V_24 -> V_129 . V_78 ) ;
V_334:
if ( V_327 != V_2 -> V_80 && F_247 ( V_2 ) ) {
V_2 -> V_80 = V_327 ;
V_2 -> V_173 = V_328 ;
}
V_10:
if ( ! V_330 )
F_249 ( V_2 ) ;
else
F_17 ( V_2 ) ;
return 0 ;
}
static int V_186 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
struct V_325 * V_326 ;
union V_34 V_35 ;
T_5 * V_327 = V_2 -> V_80 ;
int V_328 = V_2 -> V_173 ;
unsigned int V_329 , V_320 ;
unsigned long V_33 = V_142 ;
unsigned short V_349 , V_350 , V_114 ;
struct V_1 * V_351 = NULL ;
struct V_44 V_45 ;
T_4 V_54 ;
bool V_330 = false ;
F_256 ( F_257 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_256 ( F_257 ( sizeof( * V_35 . V_352 ) ) != 48 ) ;
if ( V_2 -> V_270 == V_271 )
goto V_10;
V_24 = V_222 -> V_224 ;
V_14 = F_36 ( V_24 ) ;
if ( ! F_173 ( F_174 ( V_4 ) , F_78 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_308 ) {
if ( V_24 -> V_331 != V_332 )
F_218 ( V_2 , V_2 -> V_80 - F_219 ( V_2 ) ) ;
else if ( V_2 -> V_270 == V_333 ) {
F_245 ( V_2 , F_246 ( V_2 ) ) ;
}
}
V_329 = V_2 -> V_173 ;
V_320 = F_238 ( V_2 , V_24 , V_329 ) ;
if ( ! V_320 )
goto V_334;
if ( V_2 -> V_353 == V_354 )
V_33 |= V_355 ;
else if ( V_2 -> V_270 != V_333 &&
( V_2 -> V_353 == V_356 ||
F_258 ( V_2 ) ) )
V_33 |= V_357 ;
if ( V_329 > V_320 )
V_329 = V_320 ;
if ( V_24 -> V_331 == V_332 ) {
V_349 = V_350 = F_257 ( V_14 -> V_115 ) + 16 +
V_14 -> V_358 ;
} else {
unsigned int V_359 = F_246 ( V_2 ) ;
V_350 = F_257 ( V_14 -> V_115 +
( V_359 < 16 ? 16 : V_359 ) ) +
V_14 -> V_358 ;
if ( V_14 -> V_360 )
V_350 += sizeof( struct V_323 ) ;
V_349 = V_350 - V_359 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_349 + V_329 > V_14 -> V_77 . V_70 ) {
if ( V_14 -> V_361 &&
F_91 ( & V_24 -> V_189 ) < V_24 -> V_188 ) {
if ( F_247 ( V_2 ) ) {
V_351 = F_248 ( V_2 , V_272 ) ;
} else {
V_351 = F_259 ( V_2 ) ;
V_327 = V_2 -> V_80 ;
}
if ( V_351 )
F_253 ( V_351 , V_24 ) ;
}
V_329 = V_14 -> V_77 . V_70 - V_349 ;
if ( ( int ) V_329 < 0 )
V_329 = 0 ;
}
} else if ( F_2 ( V_349 + V_329 >
F_68 ( & V_14 -> V_77 ) -> V_126 ) ) {
T_6 V_362 ;
V_362 = F_68 ( & V_14 -> V_77 ) -> V_126 - V_349 ;
F_260 ( L_4 ,
V_329 , V_362 , V_349 ) ;
V_329 = V_362 ;
if ( F_2 ( ( int ) V_329 < 0 ) ) {
V_329 = 0 ;
V_349 = F_68 ( & V_14 -> V_77 ) -> V_126 ;
}
}
F_46 ( & V_24 -> V_129 . V_78 ) ;
V_35 . V_36 = F_123 ( V_14 , V_2 ,
V_160 , ( V_349 + V_329 ) ) ;
if ( ! V_35 . V_36 )
goto V_363;
if ( V_14 -> V_37 <= V_41 ) {
F_130 ( V_14 , & V_14 -> V_77 ) ;
if ( V_14 -> V_118 . V_346 . V_148 )
V_33 |= V_149 ;
}
V_14 -> V_118 . V_346 . V_347 ++ ;
if ( V_351 ) {
V_33 |= V_364 ;
F_255 ( & V_24 -> V_129 , V_351 ) ;
}
F_44 ( & V_24 -> V_129 . V_78 ) ;
if ( V_14 -> V_360 ) {
if ( F_239 ( V_2 , V_35 . V_36 + V_349 -
sizeof( struct V_323 ) ) ) {
F_46 ( & V_24 -> V_129 . V_78 ) ;
goto V_363;
}
}
F_261 ( V_2 , 0 , V_35 . V_36 + V_349 , V_329 ) ;
if ( ! ( V_54 = F_59 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
F_100 ( & V_45 ) ;
V_33 |= V_54 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_365 = V_2 -> V_173 ;
V_35 . V_39 -> V_366 = V_329 ;
V_35 . V_39 -> V_367 = V_349 ;
V_35 . V_39 -> V_368 = V_350 ;
V_35 . V_39 -> V_56 = V_45 . V_57 ;
V_35 . V_39 -> V_58 = V_45 . V_59 / V_60 ;
V_114 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_365 = V_2 -> V_173 ;
V_35 . V_42 -> V_366 = V_329 ;
V_35 . V_42 -> V_367 = V_349 ;
V_35 . V_42 -> V_368 = V_350 ;
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
V_35 . V_352 -> V_40 |= V_33 ;
V_35 . V_352 -> V_365 = V_2 -> V_173 ;
V_35 . V_352 -> V_366 = V_329 ;
V_35 . V_352 -> V_367 = V_349 ;
V_35 . V_352 -> V_368 = V_350 ;
V_35 . V_352 -> V_56 = V_45 . V_57 ;
V_35 . V_352 -> V_61 = V_45 . V_59 ;
memset ( V_35 . V_352 -> V_170 , 0 , sizeof( V_35 . V_352 -> V_170 ) ) ;
V_114 = sizeof( * V_35 . V_352 ) ;
break;
default:
F_55 () ;
}
V_326 = V_35 . V_36 + F_257 ( V_114 ) ;
V_326 -> V_343 = F_251 ( V_2 , V_326 -> V_344 ) ;
V_326 -> V_369 = V_370 ;
V_326 -> V_339 = V_4 -> type ;
V_326 -> V_371 = V_2 -> V_280 ;
V_326 -> V_340 = V_2 -> V_270 ;
if ( F_2 ( V_14 -> V_341 ) )
V_326 -> V_342 = V_223 -> V_92 ;
else
V_326 -> V_342 = V_4 -> V_92 ;
F_122 () ;
#if V_136 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_5 * V_137 , * V_138 ;
V_138 = ( T_5 * ) F_97 ( ( unsigned long ) V_35 . V_36 +
V_349 + V_329 ) ;
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
V_334:
if ( V_327 != V_2 -> V_80 && F_247 ( V_2 ) ) {
V_2 -> V_80 = V_327 ;
V_2 -> V_173 = V_328 ;
}
V_10:
if ( ! V_330 )
F_249 ( V_2 ) ;
else
F_17 ( V_2 ) ;
return 0 ;
V_363:
V_330 = true ;
V_14 -> V_118 . V_346 . V_148 ++ ;
F_44 ( & V_24 -> V_129 . V_78 ) ;
V_24 -> V_155 ( V_24 ) ;
F_17 ( V_351 ) ;
goto V_334;
}
static void F_262 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_36 ( V_2 -> V_24 ) ;
if ( F_22 ( V_14 -> V_182 . V_68 ) ) {
void * V_372 ;
T_4 V_45 ;
V_372 = F_235 ( V_2 ) -> V_373 ;
F_134 ( & V_14 -> V_182 ) ;
V_45 = F_62 ( V_14 , V_372 , V_2 ) ;
F_52 ( V_14 , V_372 , V_169 | V_45 ) ;
}
F_263 ( V_2 ) ;
}
static void F_264 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( V_4 -> type == V_265 ) {
F_210 ( V_2 ) ;
V_2 -> V_280 = F_211 ( V_2 ) -> V_266 ;
}
}
static int F_265 ( struct V_323 * V_324 , T_8 V_173 )
{
unsigned short V_374 = 0 ;
if ( ( V_324 -> V_46 & V_375 ) &&
( F_266 ( F_241 () , V_324 -> V_376 ) +
F_266 ( F_241 () , V_324 -> V_377 ) + 2 >
F_266 ( F_241 () , V_324 -> V_378 ) ) )
V_324 -> V_378 = F_267 ( F_241 () ,
F_266 ( F_241 () , V_324 -> V_376 ) +
F_266 ( F_241 () , V_324 -> V_377 ) + 2 ) ;
if ( F_266 ( F_241 () , V_324 -> V_378 ) > V_173 )
return - V_247 ;
if ( V_324 -> V_374 != V_379 ) {
switch ( V_324 -> V_374 & ~ V_380 ) {
case V_381 :
V_374 = V_382 ;
break;
case V_383 :
V_374 = V_384 ;
break;
case V_385 :
V_374 = V_386 ;
break;
default:
return - V_247 ;
}
if ( V_324 -> V_374 & V_380 )
V_374 |= V_387 ;
if ( V_324 -> V_388 == 0 )
return - V_247 ;
}
V_324 -> V_374 = V_374 ;
return 0 ;
}
static int F_268 ( struct V_282 * V_283 , T_8 * V_173 ,
struct V_323 * V_324 )
{
int V_389 ;
if ( * V_173 < sizeof( * V_324 ) )
return - V_247 ;
* V_173 -= sizeof( * V_324 ) ;
V_389 = F_269 ( V_324 , sizeof( * V_324 ) , & V_283 -> V_390 ) ;
if ( V_389 != sizeof( * V_324 ) )
return - V_248 ;
return F_265 ( V_324 , * V_173 ) ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_323 * V_324 )
{
if ( V_324 -> V_46 & V_375 ) {
T_2 V_391 = F_266 ( F_241 () , V_324 -> V_376 ) ;
T_2 V_392 = F_266 ( F_241 () , V_324 -> V_377 ) ;
if ( ! F_271 ( V_2 , V_391 , V_392 ) )
return - V_247 ;
}
F_235 ( V_2 ) -> V_388 =
F_266 ( F_241 () , V_324 -> V_388 ) ;
F_235 ( V_2 ) -> V_374 = V_324 -> V_374 ;
F_235 ( V_2 ) -> V_374 |= V_393 ;
F_235 ( V_2 ) -> V_394 = 0 ;
return 0 ;
}
static int F_272 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , void * V_80 , int V_365 ,
T_9 V_288 , unsigned char * V_31 , int V_395 , int V_396 ,
const struct V_286 * V_287 )
{
union V_34 V_372 ;
int V_397 , V_398 , V_173 , V_399 , V_400 ;
struct V_281 * V_23 = V_14 -> V_24 . V_401 ;
struct V_30 * V_30 ;
int V_91 ;
V_372 . V_36 = V_32 ;
V_2 -> V_280 = V_288 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_314 = V_14 -> V_24 . V_315 ;
V_2 -> V_316 = V_14 -> V_24 . V_317 ;
F_234 ( & V_14 -> V_24 , V_287 -> V_311 , & F_235 ( V_2 ) -> V_318 ) ;
F_235 ( V_2 ) -> V_373 = V_372 . V_36 ;
F_228 ( V_2 , V_395 ) ;
F_229 ( V_2 ) ;
V_397 = V_365 ;
if ( V_23 -> type == V_332 ) {
V_91 = F_273 ( V_2 , V_4 , F_116 ( V_288 ) , V_31 ,
NULL , V_365 ) ;
if ( F_2 ( V_91 < 0 ) )
return - V_247 ;
} else if ( V_396 ) {
int V_114 = F_164 ( int , V_396 , V_365 ) ;
F_218 ( V_2 , V_4 -> V_302 ) ;
F_231 ( V_2 , V_396 - V_4 -> V_302 ) ;
V_91 = F_274 ( V_2 , 0 , V_80 , V_114 ) ;
if ( F_2 ( V_91 ) )
return V_91 ;
if ( ! F_232 ( V_4 , V_2 -> V_80 , V_114 ) )
return - V_247 ;
if ( ! V_2 -> V_280 )
F_264 ( V_4 , V_2 ) ;
V_80 += V_114 ;
V_397 -= V_114 ;
}
V_398 = F_275 ( V_80 ) ;
V_400 = V_139 - V_398 ;
V_173 = ( ( V_397 > V_400 ) ? V_400 : V_397 ) ;
V_2 -> V_402 = V_397 ;
V_2 -> V_173 += V_397 ;
V_2 -> V_190 += V_397 ;
F_276 ( V_397 , & V_14 -> V_24 . V_197 ) ;
while ( F_22 ( V_397 ) ) {
V_399 = F_235 ( V_2 ) -> V_399 ;
if ( F_2 ( V_399 >= V_403 ) ) {
F_151 ( L_5 ,
V_403 ) ;
return - V_248 ;
}
V_30 = F_48 ( V_80 ) ;
V_80 += V_173 ;
F_53 ( V_30 ) ;
F_277 ( V_30 ) ;
F_278 ( V_2 , V_399 , V_30 , V_398 , V_173 ) ;
V_397 -= V_173 ;
V_398 = 0 ;
V_400 = V_139 ;
V_173 = ( ( V_397 > V_400 ) ? V_400 : V_397 ) ;
}
F_236 ( V_2 , 0 ) ;
return V_365 ;
}
static int F_279 ( struct V_13 * V_14 , void * V_32 ,
int V_404 , void * * V_80 )
{
union V_34 V_372 ;
int V_365 , V_405 ;
V_372 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_41 :
V_365 = V_372 . V_42 -> V_365 ;
break;
default:
V_365 = V_372 . V_39 -> V_365 ;
break;
}
if ( F_2 ( V_365 > V_404 ) ) {
F_151 ( L_6 , V_365 , V_404 ) ;
return - V_300 ;
}
if ( F_2 ( V_14 -> V_406 ) ) {
int V_407 , V_408 ;
V_407 = V_14 -> V_115 - sizeof( struct V_325 ) ;
V_408 = V_14 -> V_182 . V_70 - V_365 ;
if ( V_14 -> V_24 . V_331 == V_332 ) {
switch ( V_14 -> V_37 ) {
case V_41 :
V_405 = V_372 . V_42 -> V_368 ;
break;
default:
V_405 = V_372 . V_39 -> V_368 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_41 :
V_405 = V_372 . V_42 -> V_367 ;
break;
default:
V_405 = V_372 . V_39 -> V_367 ;
break;
}
}
if ( F_2 ( ( V_405 < V_407 ) || ( V_408 < V_405 ) ) )
return - V_247 ;
} else {
V_405 = V_14 -> V_115 - sizeof( struct V_325 ) ;
}
* V_80 = V_32 + V_405 ;
return V_365 ;
}
static int F_280 ( struct V_13 * V_14 , struct V_282 * V_283 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_323 * V_324 = NULL ;
struct V_286 V_287 ;
T_9 V_288 ;
int V_91 , V_409 = 0 ;
void * V_372 ;
F_223 ( struct V_325 * , V_284 , V_283 -> V_285 ) ;
bool V_410 = ! ( V_283 -> V_411 & V_412 ) ;
int V_365 , V_404 ;
unsigned char * V_31 ;
void * V_80 ;
int V_413 = 0 ;
int V_33 = V_169 ;
int V_395 , V_305 , V_396 = 0 ;
F_196 ( & V_14 -> V_414 ) ;
if ( F_22 ( V_284 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_288 = V_14 -> V_207 ;
V_31 = NULL ;
} else {
V_91 = - V_247 ;
if ( V_283 -> V_290 < sizeof( struct V_325 ) )
goto V_130;
if ( V_283 -> V_290 < ( V_284 -> V_343
+ F_281 ( struct V_325 ,
V_344 ) ) )
goto V_130;
V_288 = V_284 -> V_371 ;
V_31 = V_284 -> V_344 ;
V_4 = F_282 ( F_78 ( & V_14 -> V_24 ) , V_284 -> V_342 ) ;
}
V_287 . V_311 = V_14 -> V_24 . V_312 ;
if ( V_283 -> V_313 ) {
V_91 = F_233 ( & V_14 -> V_24 , V_283 , & V_287 ) ;
if ( F_2 ( V_91 ) )
goto V_130;
}
V_91 = - V_415 ;
if ( F_2 ( V_4 == NULL ) )
goto V_130;
V_91 = - V_296 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_297 ) ) )
goto V_416;
if ( V_14 -> V_24 . V_401 -> type == V_417 )
V_409 = V_4 -> V_302 ;
V_404 = V_14 -> V_182 . V_70
- ( V_14 -> V_115 - sizeof( struct V_325 ) ) ;
if ( ( V_404 > V_4 -> V_301 + V_409 + V_303 ) && ! V_14 -> V_360 )
V_404 = V_4 -> V_301 + V_409 + V_303 ;
do {
V_372 = F_64 ( V_14 , & V_14 -> V_182 ,
V_418 ) ;
if ( F_2 ( V_372 == NULL ) ) {
if ( V_410 && F_283 () )
F_284 () ;
continue;
}
V_2 = NULL ;
V_365 = F_279 ( V_14 , V_372 , V_404 , & V_80 ) ;
if ( V_365 < 0 )
goto V_419;
V_33 = V_418 ;
V_395 = F_226 ( V_4 ) ;
V_305 = V_4 -> V_306 ;
if ( V_14 -> V_360 ) {
V_324 = V_80 ;
V_80 += sizeof( * V_324 ) ;
V_365 -= sizeof( * V_324 ) ;
if ( V_365 < 0 ||
F_265 ( V_324 , V_365 ) ) {
V_365 = - V_247 ;
goto V_419;
}
V_396 = F_266 ( F_241 () ,
V_324 -> V_378 ) ;
}
V_396 = F_285 ( int , V_396 , V_4 -> V_302 ) ;
V_2 = F_286 ( & V_14 -> V_24 ,
V_395 + V_305 + sizeof( struct V_325 ) +
( V_396 - V_4 -> V_302 ) ,
! V_410 , & V_91 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_22 ( V_413 > 0 ) )
V_91 = V_413 ;
goto V_420;
}
V_365 = F_272 ( V_14 , V_2 , V_372 , V_4 , V_80 , V_365 , V_288 ,
V_31 , V_395 , V_396 , & V_287 ) ;
if ( F_22 ( V_365 >= 0 ) &&
V_365 > V_4 -> V_301 + V_409 &&
! V_14 -> V_360 &&
! F_209 ( V_4 , V_2 ) )
V_365 = - V_300 ;
if ( F_2 ( V_365 < 0 ) ) {
V_419:
if ( V_14 -> V_421 ) {
F_52 ( V_14 , V_372 ,
V_169 ) ;
F_131 ( & V_14 -> V_182 ) ;
F_17 ( V_2 ) ;
continue;
} else {
V_33 = V_422 ;
V_91 = V_365 ;
goto V_420;
}
}
if ( V_14 -> V_360 && F_270 ( V_2 , V_324 ) ) {
V_365 = - V_247 ;
goto V_419;
}
F_32 ( V_4 , V_2 ) ;
V_2 -> V_423 = F_262 ;
F_52 ( V_14 , V_372 , V_424 ) ;
F_132 ( & V_14 -> V_182 ) ;
V_33 = V_418 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_91 > 0 ) ) {
V_91 = F_287 ( V_91 ) ;
if ( V_91 && F_57 ( V_14 , V_372 ) ==
V_169 ) {
V_2 = NULL ;
goto V_420;
}
V_91 = 0 ;
}
F_131 ( & V_14 -> V_182 ) ;
V_413 += V_365 ;
} while ( F_22 ( ( V_372 != NULL ) ||
( V_410 && F_136 ( & V_14 -> V_182 ) ) ) );
V_91 = V_413 ;
goto V_416;
V_420:
F_52 ( V_14 , V_372 , V_33 ) ;
F_17 ( V_2 ) ;
V_416:
F_288 ( V_4 ) ;
V_130:
F_202 ( & V_14 -> V_414 ) ;
return V_91 ;
}
static struct V_1 * F_289 ( struct V_23 * V_24 , T_8 V_425 ,
T_8 V_409 , T_8 V_173 ,
T_8 V_426 , int V_427 ,
int * V_91 )
{
struct V_1 * V_2 ;
if ( V_425 + V_173 < V_139 || ! V_426 )
V_426 = V_173 ;
V_2 = F_290 ( V_24 , V_425 + V_426 , V_173 - V_426 , V_427 ,
V_91 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_228 ( V_2 , V_409 ) ;
F_231 ( V_2 , V_426 ) ;
V_2 -> V_402 = V_173 - V_426 ;
V_2 -> V_173 += V_173 - V_426 ;
return V_2 ;
}
static int F_291 ( struct V_281 * V_23 , struct V_282 * V_283 , T_8 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_223 ( struct V_325 * , V_284 , V_283 -> V_285 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_9 V_288 ;
unsigned char * V_31 ;
int V_91 , V_409 = 0 ;
struct V_286 V_287 ;
struct V_323 V_324 = { 0 } ;
int V_398 = 0 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_395 , V_305 ;
int V_289 = 0 ;
if ( F_22 ( V_284 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_288 = V_14 -> V_207 ;
V_31 = NULL ;
} else {
V_91 = - V_247 ;
if ( V_283 -> V_290 < sizeof( struct V_325 ) )
goto V_130;
if ( V_283 -> V_290 < ( V_284 -> V_343 + F_281 ( struct V_325 , V_344 ) ) )
goto V_130;
V_288 = V_284 -> V_371 ;
V_31 = V_284 -> V_344 ;
V_4 = F_282 ( F_78 ( V_24 ) , V_284 -> V_342 ) ;
}
V_91 = - V_415 ;
if ( F_2 ( V_4 == NULL ) )
goto V_295;
V_91 = - V_296 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_297 ) ) )
goto V_295;
V_287 . V_311 = V_24 -> V_312 ;
V_287 . V_316 = V_24 -> V_317 ;
if ( V_283 -> V_313 ) {
V_91 = F_233 ( V_24 , V_283 , & V_287 ) ;
if ( F_2 ( V_91 ) )
goto V_295;
}
if ( V_23 -> type == V_417 )
V_409 = V_4 -> V_302 ;
if ( V_14 -> V_360 ) {
V_91 = F_268 ( V_283 , & V_173 , & V_324 ) ;
if ( V_91 )
goto V_295;
}
if ( F_2 ( F_150 ( V_24 , V_298 ) ) ) {
if ( ! F_225 ( V_4 ) ) {
V_91 = - V_299 ;
goto V_295;
}
V_289 = 4 ;
}
V_91 = - V_300 ;
if ( ! V_324 . V_374 &&
( V_173 > V_4 -> V_301 + V_409 + V_303 + V_289 ) )
goto V_295;
V_91 = - V_183 ;
V_395 = F_226 ( V_4 ) ;
V_305 = V_4 -> V_306 ;
V_2 = F_289 ( V_24 , V_395 + V_305 , V_395 , V_173 ,
F_266 ( F_241 () , V_324 . V_378 ) ,
V_283 -> V_411 & V_412 , & V_91 ) ;
if ( V_2 == NULL )
goto V_295;
F_292 ( V_2 , V_409 ) ;
V_91 = - V_247 ;
if ( V_23 -> type == V_332 ) {
V_398 = F_273 ( V_2 , V_4 , F_116 ( V_288 ) , V_31 , NULL , V_173 ) ;
if ( F_2 ( V_398 < 0 ) )
goto V_310;
}
V_91 = F_293 ( V_2 , V_398 , & V_283 -> V_390 , V_173 ) ;
if ( V_91 )
goto V_310;
if ( V_23 -> type == V_417 &&
! F_232 ( V_4 , V_2 -> V_80 , V_173 ) ) {
V_91 = - V_247 ;
goto V_310;
}
F_234 ( V_24 , V_287 . V_311 , & F_235 ( V_2 ) -> V_318 ) ;
if ( ! V_324 . V_374 && ( V_173 > V_4 -> V_301 + V_409 + V_289 ) &&
! F_209 ( V_4 , V_2 ) ) {
V_91 = - V_300 ;
goto V_310;
}
V_2 -> V_280 = V_288 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_314 = V_24 -> V_315 ;
V_2 -> V_316 = V_287 . V_316 ;
F_32 ( V_4 , V_2 ) ;
if ( V_14 -> V_360 ) {
V_91 = F_270 ( V_2 , & V_324 ) ;
if ( V_91 )
goto V_310;
V_173 += sizeof( V_324 ) ;
}
F_236 ( V_2 , V_409 ) ;
if ( F_2 ( V_289 == 4 ) )
V_2 -> V_319 = 1 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( V_91 > 0 && ( V_91 = F_287 ( V_91 ) ) != 0 )
goto V_295;
F_288 ( V_4 ) ;
return V_173 ;
V_310:
F_17 ( V_2 ) ;
V_295:
if ( V_4 )
F_288 ( V_4 ) ;
V_130:
return V_91 ;
}
static int F_294 ( struct V_281 * V_23 , struct V_282 * V_283 , T_8 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
if ( V_14 -> V_182 . V_68 )
return F_280 ( V_14 , V_283 ) ;
else
return F_291 ( V_23 , V_283 , V_173 ) ;
}
static int F_295 ( struct V_281 * V_23 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 ;
struct V_226 * V_226 ;
union V_99 V_100 ;
if ( ! V_24 )
return 0 ;
V_226 = F_78 ( V_24 ) ;
V_14 = F_36 ( V_24 ) ;
F_196 ( & V_226 -> V_428 . V_429 ) ;
F_296 ( V_24 ) ;
F_202 ( & V_226 -> V_428 . V_429 ) ;
F_297 () ;
F_298 ( V_226 , V_24 -> V_430 , - 1 ) ;
F_299 () ;
F_46 ( & V_14 -> V_29 ) ;
F_47 ( V_24 , false ) ;
F_27 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_288 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
F_300 ( V_24 ) ;
if ( V_14 -> V_77 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_301 ( V_24 , & V_100 , 1 , 0 ) ;
}
if ( V_14 -> V_182 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_301 ( V_24 , & V_100 , 1 , 1 ) ;
}
F_204 ( V_24 ) ;
F_45 () ;
F_302 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_148 ( & V_24 -> V_129 ) ;
F_141 ( V_14 ) ;
F_303 ( V_24 ) ;
F_304 ( V_24 ) ;
return 0 ;
}
static int F_305 ( struct V_23 * V_24 , const char * V_278 , int V_92 ,
T_9 V_288 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_3 * V_431 ;
T_9 V_432 ;
bool V_433 ;
struct V_3 * V_4 = NULL ;
int V_8 = 0 ;
bool V_434 = false ;
if ( V_14 -> V_26 )
return - V_247 ;
F_306 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
F_20 () ;
if ( V_278 ) {
V_4 = F_224 ( F_78 ( V_24 ) , V_278 ) ;
if ( ! V_4 ) {
V_8 = - V_294 ;
goto V_295;
}
} else if ( V_92 ) {
V_4 = F_307 ( F_78 ( V_24 ) , V_92 ) ;
if ( ! V_4 ) {
V_8 = - V_294 ;
goto V_295;
}
}
if ( V_4 )
F_23 ( V_4 ) ;
V_432 = V_14 -> V_27 . type ;
V_431 = V_14 -> V_27 . V_4 ;
V_433 = V_432 != V_288 || V_431 != V_4 ;
if ( V_433 ) {
if ( V_14 -> V_25 ) {
F_24 () ;
F_40 ( V_24 , true ) ;
F_20 () ;
V_431 = V_14 -> V_27 . V_4 ;
if ( V_4 )
V_434 = ! F_307 ( F_78 ( V_24 ) ,
V_4 -> V_92 ) ;
}
V_14 -> V_207 = V_288 ;
V_14 -> V_27 . type = V_288 ;
if ( F_2 ( V_434 ) ) {
F_288 ( V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
V_14 -> V_92 = - 1 ;
F_27 ( V_14 ) ;
} else {
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_92 = V_4 ? V_4 -> V_92 : 0 ;
F_25 ( V_14 , V_4 ) ;
}
}
if ( V_431 )
F_288 ( V_431 ) ;
if ( V_288 == 0 || ! V_433 )
goto V_295;
if ( ! V_434 && ( ! V_4 || ( V_4 -> V_46 & V_297 ) ) ) {
F_35 ( V_24 ) ;
} else {
V_24 -> V_435 = V_296 ;
if ( ! F_150 ( V_24 , V_198 ) )
V_24 -> V_436 ( V_24 ) ;
}
V_295:
F_24 () ;
F_44 ( & V_14 -> V_29 ) ;
F_308 ( V_24 ) ;
return V_8 ;
}
static int F_309 ( struct V_281 * V_23 , struct V_291 * V_437 ,
int V_438 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_278 [ 15 ] ;
if ( V_438 != sizeof( struct V_291 ) )
return - V_247 ;
F_220 ( V_278 , V_437 -> V_439 , sizeof( V_278 ) ) ;
return F_305 ( V_24 , V_278 , 0 , F_36 ( V_24 ) -> V_207 ) ;
}
static int F_310 ( struct V_281 * V_23 , struct V_291 * V_437 , int V_438 )
{
struct V_325 * V_326 = (struct V_325 * ) V_437 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_438 < sizeof( struct V_325 ) )
return - V_247 ;
if ( V_326 -> V_369 != V_370 )
return - V_247 ;
return F_305 ( V_24 , NULL , V_326 -> V_342 ,
V_326 -> V_371 ? : F_36 ( V_24 ) -> V_207 ) ;
}
static int F_311 ( struct V_226 * V_226 , struct V_281 * V_23 , int V_280 ,
int V_440 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_9 V_288 = ( V_441 T_9 ) V_280 ;
int V_91 ;
if ( ! F_312 ( V_226 -> V_442 , V_443 ) )
return - V_246 ;
if ( V_23 -> type != V_332 && V_23 -> type != V_417 &&
V_23 -> type != V_444 )
return - V_445 ;
V_23 -> V_446 = V_447 ;
V_91 = - V_183 ;
V_24 = F_313 ( V_226 , V_240 , V_255 , & V_448 , V_440 ) ;
if ( V_24 == NULL )
goto V_130;
V_23 -> V_19 = & V_449 ;
if ( V_23 -> type == V_444 )
V_23 -> V_19 = & V_450 ;
F_314 ( V_23 , V_24 ) ;
V_14 = F_36 ( V_24 ) ;
V_24 -> V_239 = V_240 ;
V_14 -> V_207 = V_288 ;
V_14 -> V_16 = F_237 ;
V_91 = F_139 ( V_14 ) ;
if ( V_91 )
goto V_451;
F_27 ( V_14 ) ;
V_24 -> V_452 = F_147 ;
F_315 ( V_24 ) ;
F_200 ( & V_14 -> V_29 ) ;
F_316 ( & V_14 -> V_414 ) ;
V_14 -> V_203 = NULL ;
V_14 -> V_27 . F_72 = F_244 ;
if ( V_23 -> type == V_444 )
V_14 -> V_27 . F_72 = F_213 ;
V_14 -> V_27 . V_224 = V_24 ;
if ( V_288 ) {
V_14 -> V_27 . type = V_288 ;
F_35 ( V_24 ) ;
}
F_196 ( & V_226 -> V_428 . V_429 ) ;
F_317 ( V_24 , & V_226 -> V_428 . V_453 ) ;
F_202 ( & V_226 -> V_428 . V_429 ) ;
F_297 () ;
F_298 ( V_226 , & V_448 , 1 ) ;
F_299 () ;
return 0 ;
V_451:
F_318 ( V_24 ) ;
V_130:
return V_91 ;
}
static int F_319 ( struct V_281 * V_23 , struct V_282 * V_283 , T_8 V_173 ,
int V_46 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_454 , V_91 ;
int V_455 = 0 ;
unsigned int V_345 = 0 ;
V_91 = - V_247 ;
if ( V_46 & ~ ( V_456 | V_412 | V_457 | V_458 | V_459 ) )
goto V_130;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_46 & V_459 ) {
V_91 = F_320 ( V_24 , V_283 , V_173 ,
V_460 , V_461 ) ;
goto V_130;
}
V_2 = F_321 ( V_24 , V_46 , V_46 & V_412 , & V_91 ) ;
if ( V_2 == NULL )
goto V_130;
if ( F_36 ( V_24 ) -> V_195 )
F_146 ( F_36 ( V_24 ) , NULL ) ;
if ( F_36 ( V_24 ) -> V_360 ) {
V_91 = F_242 ( V_283 , V_2 , & V_173 ) ;
if ( V_91 )
goto V_310;
V_455 = sizeof( struct V_323 ) ;
}
V_454 = V_2 -> V_173 ;
if ( V_454 > V_173 ) {
V_454 = V_173 ;
V_283 -> V_411 |= V_457 ;
}
V_91 = F_322 ( V_2 , 0 , V_283 , V_454 ) ;
if ( V_91 )
goto V_310;
if ( V_23 -> type != V_444 ) {
struct V_325 * V_326 = & F_217 ( V_2 ) -> V_274 . V_338 ;
V_345 = F_217 ( V_2 ) -> V_274 . V_345 ;
V_326 -> V_369 = V_370 ;
V_326 -> V_371 = V_2 -> V_280 ;
}
F_323 ( V_283 , V_24 , V_2 ) ;
if ( V_283 -> V_285 ) {
if ( V_23 -> type == V_444 ) {
F_324 ( sizeof( struct V_268 ) ) ;
V_283 -> V_290 = sizeof( struct V_268 ) ;
} else {
struct V_325 * V_326 = & F_217 ( V_2 ) -> V_274 . V_338 ;
V_283 -> V_290 = V_326 -> V_343 +
F_281 ( struct V_325 , V_344 ) ;
}
memcpy ( V_283 -> V_285 , & F_217 ( V_2 ) -> V_274 ,
V_283 -> V_290 ) ;
}
if ( F_36 ( V_24 ) -> V_462 ) {
struct V_463 V_464 ;
V_464 . V_40 = V_142 ;
if ( V_2 -> V_353 == V_354 )
V_464 . V_40 |= V_355 ;
else if ( V_2 -> V_270 != V_333 &&
( V_2 -> V_353 == V_356 ||
F_258 ( V_2 ) ) )
V_464 . V_40 |= V_357 ;
V_464 . V_365 = V_345 ;
V_464 . V_366 = V_2 -> V_173 ;
V_464 . V_367 = 0 ;
V_464 . V_368 = F_246 ( V_2 ) ;
if ( F_114 ( V_2 ) ) {
V_464 . V_164 = F_115 ( V_2 ) ;
V_464 . V_165 = F_116 ( V_2 -> V_166 ) ;
V_464 . V_40 |= V_167 | V_168 ;
} else {
V_464 . V_164 = 0 ;
V_464 . V_165 = 0 ;
}
F_325 ( V_283 , V_460 , V_465 , sizeof( V_464 ) , & V_464 ) ;
}
V_91 = V_455 + ( ( V_46 & V_457 ) ? V_2 -> V_173 : V_454 ) ;
V_310:
F_326 ( V_24 , V_2 ) ;
V_130:
return V_91 ;
}
static int F_327 ( struct V_281 * V_23 , struct V_291 * V_437 ,
int * V_466 , int V_467 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_467 )
return - V_468 ;
V_437 -> V_469 = V_370 ;
memset ( V_437 -> V_439 , 0 , sizeof( V_437 -> V_439 ) ) ;
F_20 () ;
V_4 = F_307 ( F_78 ( V_24 ) , F_36 ( V_24 ) -> V_92 ) ;
if ( V_4 )
F_220 ( V_437 -> V_439 , V_4 -> V_278 , sizeof( V_437 -> V_439 ) ) ;
F_24 () ;
* V_466 = sizeof( * V_437 ) ;
return 0 ;
}
static int F_328 ( struct V_281 * V_23 , struct V_291 * V_437 ,
int * V_466 , int V_467 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
F_223 ( struct V_325 * , V_326 , V_437 ) ;
if ( V_467 )
return - V_468 ;
V_326 -> V_369 = V_370 ;
V_326 -> V_342 = V_14 -> V_92 ;
V_326 -> V_371 = V_14 -> V_207 ;
V_326 -> V_340 = 0 ;
F_20 () ;
V_4 = F_307 ( F_78 ( V_24 ) , V_14 -> V_92 ) ;
if ( V_4 ) {
V_326 -> V_339 = V_4 -> type ;
V_326 -> V_343 = V_4 -> V_438 ;
memcpy ( V_326 -> V_344 , V_4 -> V_470 , V_4 -> V_438 ) ;
} else {
V_326 -> V_339 = 0 ;
V_326 -> V_343 = 0 ;
}
F_24 () ;
* V_466 = F_281 ( struct V_325 , V_344 ) + V_326 -> V_343 ;
return 0 ;
}
static int F_329 ( struct V_3 * V_4 , struct V_471 * V_200 ,
int V_472 )
{
switch ( V_200 -> type ) {
case V_473 :
if ( V_200 -> V_474 != V_4 -> V_438 )
return - V_247 ;
if ( V_472 > 0 )
return F_330 ( V_4 , V_200 -> V_31 ) ;
else
return F_331 ( V_4 , V_200 -> V_31 ) ;
break;
case V_475 :
return F_332 ( V_4 , V_472 ) ;
case V_476 :
return F_333 ( V_4 , V_472 ) ;
case V_477 :
if ( V_200 -> V_474 != V_4 -> V_438 )
return - V_247 ;
if ( V_472 > 0 )
return F_334 ( V_4 , V_200 -> V_31 ) ;
else
return F_335 ( V_4 , V_200 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_336 ( struct V_3 * V_4 ,
struct V_471 * * V_478 )
{
struct V_471 * V_479 ;
while ( ( V_479 = * V_478 ) != NULL ) {
if ( V_479 -> V_92 == V_4 -> V_92 ) {
F_329 ( V_4 , V_479 , - 1 ) ;
* V_478 = V_479 -> V_480 ;
F_203 ( V_479 ) ;
} else
V_478 = & V_479 -> V_480 ;
}
}
static int F_337 ( struct V_23 * V_24 , struct V_481 * V_482 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_471 * V_479 , * V_200 ;
struct V_3 * V_4 ;
int V_91 ;
F_76 () ;
V_91 = - V_294 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_482 -> V_483 ) ;
if ( ! V_4 )
goto V_484;
V_91 = - V_247 ;
if ( V_482 -> V_485 > V_4 -> V_438 )
goto V_484;
V_91 = - V_183 ;
V_200 = F_338 ( sizeof( * V_200 ) , V_255 ) ;
if ( V_200 == NULL )
goto V_484;
V_91 = 0 ;
for ( V_479 = V_14 -> V_486 ; V_479 ; V_479 = V_479 -> V_480 ) {
if ( V_479 -> V_92 == V_482 -> V_483 &&
V_479 -> type == V_482 -> V_487 &&
V_479 -> V_474 == V_482 -> V_485 &&
memcmp ( V_479 -> V_31 , V_482 -> V_488 , V_479 -> V_474 ) == 0 ) {
V_479 -> V_201 ++ ;
F_203 ( V_200 ) ;
goto V_484;
}
}
V_200 -> type = V_482 -> V_487 ;
V_200 -> V_92 = V_482 -> V_483 ;
V_200 -> V_474 = V_482 -> V_485 ;
memcpy ( V_200 -> V_31 , V_482 -> V_488 , V_200 -> V_474 ) ;
memset ( V_200 -> V_31 + V_200 -> V_474 , 0 , sizeof( V_200 -> V_31 ) - V_200 -> V_474 ) ;
V_200 -> V_201 = 1 ;
V_200 -> V_480 = V_14 -> V_486 ;
V_14 -> V_486 = V_200 ;
V_91 = F_329 ( V_4 , V_200 , 1 ) ;
if ( V_91 ) {
V_14 -> V_486 = V_200 -> V_480 ;
F_203 ( V_200 ) ;
}
V_484:
F_79 () ;
return V_91 ;
}
static int F_339 ( struct V_23 * V_24 , struct V_481 * V_482 )
{
struct V_471 * V_479 , * * V_478 ;
F_76 () ;
for ( V_478 = & F_36 ( V_24 ) -> V_486 ; ( V_479 = * V_478 ) != NULL ; V_478 = & V_479 -> V_480 ) {
if ( V_479 -> V_92 == V_482 -> V_483 &&
V_479 -> type == V_482 -> V_487 &&
V_479 -> V_474 == V_482 -> V_485 &&
memcmp ( V_479 -> V_31 , V_482 -> V_488 , V_479 -> V_474 ) == 0 ) {
if ( -- V_479 -> V_201 == 0 ) {
struct V_3 * V_4 ;
* V_478 = V_479 -> V_480 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_479 -> V_92 ) ;
if ( V_4 )
F_329 ( V_4 , V_479 , - 1 ) ;
F_203 ( V_479 ) ;
}
break;
}
}
F_79 () ;
return 0 ;
}
static void F_300 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_36 ( V_24 ) ;
struct V_471 * V_479 ;
if ( ! V_14 -> V_486 )
return;
F_76 () ;
while ( ( V_479 = V_14 -> V_486 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_486 = V_479 -> V_480 ;
V_4 = F_77 ( F_78 ( V_24 ) , V_479 -> V_92 ) ;
if ( V_4 != NULL )
F_329 ( V_4 , V_479 , - 1 ) ;
F_203 ( V_479 ) ;
}
F_79 () ;
}
static int
F_340 ( struct V_281 * V_23 , int V_489 , int V_490 , char T_7 * V_491 , unsigned int V_492 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_8 ;
if ( V_489 != V_460 )
return - V_493 ;
switch ( V_490 ) {
case V_494 :
case V_495 :
{
struct V_481 V_482 ;
int V_173 = V_492 ;
memset ( & V_482 , 0 , sizeof( V_482 ) ) ;
if ( V_173 < sizeof( struct V_496 ) )
return - V_247 ;
if ( V_173 > sizeof( V_482 ) )
V_173 = sizeof( V_482 ) ;
if ( F_185 ( & V_482 , V_491 , V_173 ) )
return - V_248 ;
if ( V_173 < ( V_482 . V_485 + F_281 ( struct V_496 , V_488 ) ) )
return - V_247 ;
if ( V_490 == V_494 )
V_8 = F_337 ( V_24 , & V_482 ) ;
else
V_8 = F_339 ( V_24 , & V_482 ) ;
return V_8 ;
}
case V_497 :
case V_498 :
{
union V_99 V_100 ;
int V_173 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_173 = sizeof( V_100 . V_499 ) ;
break;
case V_43 :
default:
V_173 = sizeof( V_100 . V_102 ) ;
break;
}
if ( V_492 < V_173 )
return - V_247 ;
if ( F_185 ( & V_100 . V_499 , V_491 , V_173 ) )
return - V_248 ;
return F_301 ( V_24 , & V_100 , 0 ,
V_490 == V_498 ) ;
}
case V_500 :
{
int V_208 ;
if ( V_492 != sizeof( V_208 ) )
return - V_247 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
F_36 ( V_24 ) -> V_361 = V_208 ;
return 0 ;
}
case V_501 :
{
int V_208 ;
if ( V_492 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_502 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
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
case V_503 :
{
unsigned int V_208 ;
if ( V_492 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_502 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_358 = V_208 ;
return 0 ;
}
case V_504 :
{
unsigned int V_208 ;
if ( V_492 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_502 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_421 = ! ! V_208 ;
return 0 ;
}
case V_465 :
{
int V_208 ;
if ( V_492 < sizeof( V_208 ) )
return - V_247 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_462 = ! ! V_208 ;
return 0 ;
}
case V_505 :
{
int V_208 ;
if ( V_492 < sizeof( V_208 ) )
return - V_247 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_341 = ! ! V_208 ;
return 0 ;
}
case V_506 :
{
int V_208 ;
if ( V_23 -> type != V_417 )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_502 ;
if ( V_492 < sizeof( V_208 ) )
return - V_247 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_360 = ! ! V_208 ;
return 0 ;
}
case V_507 :
{
int V_208 ;
if ( V_492 != sizeof( V_208 ) )
return - V_247 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_55 = V_208 ;
return 0 ;
}
case V_508 :
{
int V_208 ;
if ( V_492 != sizeof( V_208 ) )
return - V_247 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
return F_193 ( V_24 , V_208 & 0xffff , V_208 >> 16 ) ;
}
case V_509 :
{
if ( ! V_14 -> V_26 )
return - V_247 ;
return F_191 ( V_14 , V_491 , V_492 ) ;
}
case V_510 :
{
unsigned int V_208 ;
if ( V_492 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_502 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_406 = ! ! V_208 ;
return 0 ;
}
case V_511 :
{
int V_208 ;
if ( V_492 != sizeof( V_208 ) )
return - V_247 ;
if ( F_185 ( & V_208 , V_491 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_16 = V_208 ? F_1 : F_237 ;
return 0 ;
}
default:
return - V_493 ;
}
}
static int F_341 ( struct V_281 * V_23 , int V_489 , int V_490 ,
char T_7 * V_491 , int T_7 * V_492 )
{
int V_173 ;
int V_208 , V_512 = sizeof( V_208 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
void * V_80 = & V_208 ;
union V_513 V_514 ;
struct V_515 V_516 ;
if ( V_489 != V_460 )
return - V_493 ;
if ( F_342 ( V_173 , V_492 ) )
return - V_248 ;
if ( V_173 < 0 )
return - V_247 ;
switch ( V_490 ) {
case V_517 :
F_69 ( & V_24 -> V_129 . V_78 ) ;
memcpy ( & V_514 , & V_14 -> V_118 , sizeof( V_514 ) ) ;
memset ( & V_14 -> V_118 , 0 , sizeof( V_14 -> V_118 ) ) ;
F_70 ( & V_24 -> V_129 . V_78 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_512 = sizeof( struct V_518 ) ;
V_514 . V_119 . V_347 += V_514 . V_119 . V_148 ;
V_80 = & V_514 . V_119 ;
} else {
V_512 = sizeof( struct V_519 ) ;
V_514 . V_346 . V_347 += V_514 . V_346 . V_148 ;
V_80 = & V_514 . V_346 ;
}
break;
case V_465 :
V_208 = V_14 -> V_462 ;
break;
case V_505 :
V_208 = V_14 -> V_341 ;
break;
case V_506 :
V_208 = V_14 -> V_360 ;
break;
case V_501 :
V_208 = V_14 -> V_37 ;
break;
case V_520 :
if ( V_173 > sizeof( int ) )
V_173 = sizeof( int ) ;
if ( F_185 ( & V_208 , V_491 , V_173 ) )
return - V_248 ;
switch ( V_208 ) {
case V_38 :
V_208 = sizeof( struct V_521 ) ;
break;
case V_41 :
V_208 = sizeof( struct V_522 ) ;
break;
case V_43 :
V_208 = sizeof( struct V_143 ) ;
break;
default:
return - V_247 ;
}
break;
case V_503 :
V_208 = V_14 -> V_358 ;
break;
case V_504 :
V_208 = V_14 -> V_421 ;
break;
case V_507 :
V_208 = V_14 -> V_55 ;
break;
case V_508 :
V_208 = ( V_14 -> V_26 ?
( ( T_6 ) V_14 -> V_26 -> V_251 |
( ( T_6 ) V_14 -> V_26 -> type << 16 ) |
( ( T_6 ) V_14 -> V_26 -> V_46 << 24 ) ) :
0 ) ;
break;
case V_523 :
if ( ! V_14 -> V_203 )
return - V_247 ;
V_516 . V_524 = F_343 ( & V_14 -> V_203 -> V_207 ) ;
V_516 . V_525 = F_343 ( & V_14 -> V_203 -> V_216 ) ;
V_516 . V_526 = F_343 ( & V_14 -> V_203 -> V_217 ) ;
V_80 = & V_516 ;
V_512 = sizeof( V_516 ) ;
break;
case V_510 :
V_208 = V_14 -> V_406 ;
break;
case V_511 :
V_208 = F_29 ( V_14 ) ;
break;
default:
return - V_493 ;
}
if ( V_173 > V_512 )
V_173 = V_512 ;
if ( F_344 ( V_173 , V_492 ) )
return - V_248 ;
if ( F_345 ( V_491 , V_80 , V_173 ) )
return - V_248 ;
return 0 ;
}
static int F_346 ( struct V_281 * V_23 , int V_489 , int V_490 ,
char T_7 * V_491 , unsigned int V_492 )
{
struct V_13 * V_14 = F_36 ( V_23 -> V_24 ) ;
if ( V_489 != V_460 )
return - V_493 ;
if ( V_490 == V_509 &&
V_14 -> V_26 && V_14 -> V_26 -> type == V_235 ) {
V_491 = ( char T_7 * ) F_347 ( V_491 ) ;
if ( ! V_491 )
return - V_248 ;
V_492 = sizeof( struct V_243 ) ;
}
return F_340 ( V_23 , V_489 , V_490 , V_491 , V_492 ) ;
}
static int F_348 ( struct V_527 * V_528 ,
unsigned long V_283 , void * V_529 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_349 ( V_529 ) ;
struct V_226 * V_226 = F_174 ( V_4 ) ;
F_20 () ;
F_350 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_36 ( V_24 ) ;
switch ( V_283 ) {
case V_530 :
if ( V_14 -> V_486 )
F_336 ( V_4 , & V_14 -> V_486 ) ;
case V_531 :
if ( V_4 -> V_92 == V_14 -> V_92 ) {
F_46 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_40 ( V_24 , false ) ;
V_24 -> V_435 = V_296 ;
if ( ! F_150 ( V_24 , V_198 ) )
V_24 -> V_436 ( V_24 ) ;
}
if ( V_283 == V_530 ) {
F_27 ( V_14 ) ;
V_14 -> V_92 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_288 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_44 ( & V_14 -> V_29 ) ;
}
break;
case V_532 :
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
return V_533 ;
}
static int F_351 ( struct V_281 * V_23 , unsigned int V_534 ,
unsigned long V_535 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_534 ) {
case V_536 :
{
int V_537 = F_352 ( V_24 ) ;
return F_344 ( V_537 , ( int T_7 * ) V_535 ) ;
}
case V_538 :
{
struct V_1 * V_2 ;
int V_537 = 0 ;
F_69 ( & V_24 -> V_129 . V_78 ) ;
V_2 = F_353 ( & V_24 -> V_129 ) ;
if ( V_2 )
V_537 = V_2 -> V_173 ;
F_70 ( & V_24 -> V_129 . V_78 ) ;
return F_344 ( V_537 , ( int T_7 * ) V_535 ) ;
}
case V_539 :
return F_354 ( V_24 , (struct V_540 T_7 * ) V_535 ) ;
case V_541 :
return F_355 ( V_24 , (struct V_44 T_7 * ) V_535 ) ;
#ifdef F_356
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
case V_554 :
case V_555 :
return V_556 . V_557 ( V_23 , V_534 , V_535 ) ;
#endif
default:
return - V_558 ;
}
return 0 ;
}
static unsigned int F_357 ( struct V_559 * V_559 , struct V_281 * V_23 ,
T_10 * V_560 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned int V_561 = F_358 ( V_559 , V_23 , V_560 ) ;
F_69 ( & V_24 -> V_129 . V_78 ) ;
if ( V_14 -> V_77 . V_68 ) {
if ( ! F_128 ( V_14 , & V_14 -> V_77 ,
V_160 ) )
V_561 |= V_562 | V_563 ;
}
if ( V_14 -> V_195 && F_145 ( V_14 , NULL ) == V_192 )
V_14 -> V_195 = 0 ;
F_70 ( & V_24 -> V_129 . V_78 ) ;
F_69 ( & V_24 -> V_564 . V_78 ) ;
if ( V_14 -> V_182 . V_68 ) {
if ( F_64 ( V_14 , & V_14 -> V_182 , V_169 ) )
V_561 |= V_565 | V_566 ;
}
F_70 ( & V_24 -> V_564 . V_78 ) ;
return V_561 ;
}
static void F_359 ( struct V_567 * V_568 )
{
struct V_559 * V_559 = V_568 -> V_569 ;
struct V_281 * V_23 = V_559 -> V_570 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_120 ( & F_36 ( V_24 ) -> V_571 ) ;
}
static void F_360 ( struct V_567 * V_568 )
{
struct V_559 * V_559 = V_568 -> V_569 ;
struct V_281 * V_23 = V_559 -> V_570 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_109 ( & F_36 ( V_24 ) -> V_571 ) ;
}
static void F_361 ( struct V_104 * V_68 , unsigned int V_572 ,
unsigned int V_173 )
{
int V_200 ;
for ( V_200 = 0 ; V_200 < V_173 ; V_200 ++ ) {
if ( F_22 ( V_68 [ V_200 ] . V_69 ) ) {
if ( F_49 ( V_68 [ V_200 ] . V_69 ) )
F_362 ( V_68 [ V_200 ] . V_69 ) ;
else
F_363 ( ( unsigned long ) V_68 [ V_200 ] . V_69 ,
V_572 ) ;
V_68 [ V_200 ] . V_69 = NULL ;
}
}
F_203 ( V_68 ) ;
}
static char * F_364 ( unsigned long V_572 )
{
char * V_69 ;
T_11 V_573 = V_255 | V_574 |
V_575 | V_576 | V_577 ;
V_69 = ( char * ) F_365 ( V_573 , V_572 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_366 ( ( 1 << V_572 ) * V_139 ) ;
if ( V_69 )
return V_69 ;
V_573 &= ~ V_577 ;
V_69 = ( char * ) F_365 ( V_573 , V_572 ) ;
if ( V_69 )
return V_69 ;
return NULL ;
}
static struct V_104 * F_367 ( struct V_578 * V_499 , int V_572 )
{
unsigned int V_579 = V_499 -> V_113 ;
struct V_104 * V_68 ;
int V_200 ;
V_68 = F_368 ( V_579 , sizeof( struct V_104 ) , V_255 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
for ( V_200 = 0 ; V_200 < V_579 ; V_200 ++ ) {
V_68 [ V_200 ] . V_69 = F_364 ( V_572 ) ;
if ( F_2 ( ! V_68 [ V_200 ] . V_69 ) )
goto V_580;
}
V_130:
return V_68 ;
V_580:
F_361 ( V_68 , V_572 , V_579 ) ;
V_68 = NULL ;
goto V_130;
}
static int F_301 ( struct V_23 * V_24 , union V_99 * V_100 ,
int V_581 , int V_182 )
{
struct V_104 * V_68 = NULL ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
int V_582 , V_572 = 0 ;
struct V_62 * V_63 ;
struct V_75 * V_76 ;
T_9 V_207 ;
int V_91 = - V_247 ;
struct V_578 * V_499 = & V_100 -> V_499 ;
if ( ! V_581 && V_182 && ( V_14 -> V_37 > V_41 ) ) {
F_369 ( L_7 ) ;
goto V_130;
}
V_63 = V_182 ? & V_14 -> V_182 : & V_14 -> V_77 ;
V_76 = V_182 ? & V_24 -> V_564 : & V_24 -> V_129 ;
V_91 = - V_502 ;
if ( ! V_581 ) {
if ( F_91 ( & V_14 -> V_571 ) )
goto V_130;
if ( F_136 ( V_63 ) )
goto V_130;
}
if ( V_499 -> V_113 ) {
V_91 = - V_502 ;
if ( F_2 ( V_63 -> V_68 ) )
goto V_130;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_115 = V_583 ;
break;
case V_41 :
V_14 -> V_115 = V_584 ;
break;
case V_43 :
V_14 -> V_115 = V_585 ;
break;
}
V_91 = - V_247 ;
if ( F_2 ( ( int ) V_499 -> V_111 <= 0 ) )
goto V_130;
if ( F_2 ( ! F_370 ( V_499 -> V_111 ) ) )
goto V_130;
if ( V_14 -> V_37 >= V_43 &&
( int ) ( V_499 -> V_111 -
F_84 ( V_100 -> V_102 . V_125 ) ) <= 0 )
goto V_130;
if ( F_2 ( V_499 -> V_586 < V_14 -> V_115 +
V_14 -> V_358 ) )
goto V_130;
if ( F_2 ( V_499 -> V_586 & ( V_587 - 1 ) ) )
goto V_130;
V_63 -> V_67 = V_499 -> V_111 / V_499 -> V_586 ;
if ( F_2 ( V_63 -> V_67 == 0 ) )
goto V_130;
if ( F_2 ( ( V_63 -> V_67 * V_499 -> V_113 ) !=
V_499 -> V_588 ) )
goto V_130;
V_91 = - V_256 ;
V_572 = F_371 ( V_499 -> V_111 ) ;
V_68 = F_367 ( V_499 , V_572 ) ;
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
if ( F_2 ( V_499 -> V_588 ) )
goto V_130;
}
F_306 ( V_24 ) ;
F_46 ( & V_14 -> V_29 ) ;
V_582 = V_14 -> V_25 ;
V_207 = V_14 -> V_207 ;
if ( V_582 ) {
V_14 -> V_207 = 0 ;
F_40 ( V_24 , false ) ;
}
F_44 ( & V_14 -> V_29 ) ;
F_45 () ;
V_91 = - V_502 ;
F_196 ( & V_14 -> V_414 ) ;
if ( V_581 || F_91 ( & V_14 -> V_571 ) == 0 ) {
V_91 = 0 ;
F_69 ( & V_76 -> V_78 ) ;
F_372 ( V_63 -> V_68 , V_68 ) ;
V_63 -> V_177 = ( V_499 -> V_588 - 1 ) ;
V_63 -> V_71 = 0 ;
V_63 -> V_70 = V_499 -> V_586 ;
F_70 ( & V_76 -> V_78 ) ;
F_372 ( V_63 -> V_589 , V_572 ) ;
F_372 ( V_63 -> V_590 , V_499 -> V_113 ) ;
V_63 -> V_591 = V_499 -> V_111 / V_139 ;
V_14 -> V_27 . F_72 = ( V_14 -> V_77 . V_68 ) ?
V_186 : F_244 ;
F_148 ( V_76 ) ;
if ( F_91 ( & V_14 -> V_571 ) )
F_151 ( L_8 ,
F_91 ( & V_14 -> V_571 ) ) ;
}
F_202 ( & V_14 -> V_414 ) ;
F_46 ( & V_14 -> V_29 ) ;
if ( V_582 ) {
V_14 -> V_207 = V_207 ;
F_35 ( V_24 ) ;
}
F_44 ( & V_14 -> V_29 ) ;
if ( V_581 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_182 )
F_67 ( V_14 , V_76 ) ;
}
F_308 ( V_24 ) ;
if ( V_68 )
F_361 ( V_68 , V_572 , V_499 -> V_113 ) ;
V_130:
return V_91 ;
}
static int F_373 ( struct V_559 * V_559 , struct V_281 * V_23 ,
struct V_567 * V_568 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_36 ( V_24 ) ;
unsigned long V_592 , V_593 ;
struct V_62 * V_63 ;
unsigned long V_137 ;
int V_91 = - V_247 ;
int V_200 ;
if ( V_568 -> V_594 )
return - V_247 ;
F_196 ( & V_14 -> V_414 ) ;
V_593 = 0 ;
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_182 ; V_63 ++ ) {
if ( V_63 -> V_68 ) {
V_593 += V_63 -> V_590
* V_63 -> V_591
* V_139 ;
}
}
if ( V_593 == 0 )
goto V_130;
V_592 = V_568 -> V_595 - V_568 -> V_596 ;
if ( V_592 != V_593 )
goto V_130;
V_137 = V_568 -> V_596 ;
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_182 ; V_63 ++ ) {
if ( V_63 -> V_68 == NULL )
continue;
for ( V_200 = 0 ; V_200 < V_63 -> V_590 ; V_200 ++ ) {
struct V_30 * V_30 ;
void * V_597 = V_63 -> V_68 [ V_200 ] . V_69 ;
int V_598 ;
for ( V_598 = 0 ; V_598 < V_63 -> V_591 ; V_598 ++ ) {
V_30 = F_48 ( V_597 ) ;
V_91 = F_374 ( V_568 , V_137 , V_30 ) ;
if ( F_2 ( V_91 ) )
goto V_130;
V_137 += V_139 ;
V_597 += V_139 ;
}
}
}
F_120 ( & V_14 -> V_571 ) ;
V_568 -> V_599 = & V_600 ;
V_91 = 0 ;
V_130:
F_202 ( & V_14 -> V_414 ) ;
return V_91 ;
}
static void * F_375 ( struct V_601 * V_602 , T_12 * V_603 )
__acquires( T_13 )
{
struct V_226 * V_226 = F_376 ( V_602 ) ;
F_20 () ;
return F_377 ( & V_226 -> V_428 . V_453 , * V_603 ) ;
}
static void * F_378 ( struct V_601 * V_602 , void * V_604 , T_12 * V_603 )
{
struct V_226 * V_226 = F_376 ( V_602 ) ;
return F_379 ( V_604 , & V_226 -> V_428 . V_453 , V_603 ) ;
}
static void F_380 ( struct V_601 * V_602 , void * V_604 )
__releases( T_13 )
{
F_24 () ;
}
static int F_381 ( struct V_601 * V_602 , void * V_604 )
{
if ( V_604 == V_605 )
F_382 ( V_602 , L_9 ) ;
else {
struct V_23 * V_391 = F_383 ( V_604 ) ;
const struct V_13 * V_14 = F_36 ( V_391 ) ;
F_384 ( V_602 ,
L_10 ,
V_391 ,
F_91 ( & V_391 -> V_606 ) ,
V_391 -> V_331 ,
F_116 ( V_14 -> V_207 ) ,
V_14 -> V_92 ,
V_14 -> V_25 ,
F_91 ( & V_391 -> V_189 ) ,
F_385 ( F_386 ( V_602 ) , F_387 ( V_391 ) ) ,
F_388 ( V_391 ) ) ;
}
return 0 ;
}
static int F_389 ( struct V_607 * V_607 , struct V_559 * V_559 )
{
return F_390 ( V_607 , V_559 , & V_608 ,
sizeof( struct V_609 ) ) ;
}
static int T_14 F_391 ( struct V_226 * V_226 )
{
F_316 ( & V_226 -> V_428 . V_429 ) ;
F_392 ( & V_226 -> V_428 . V_453 ) ;
if ( ! F_393 ( L_11 , 0 , V_226 -> V_610 , & V_611 ) )
return - V_256 ;
return 0 ;
}
static void T_15 F_394 ( struct V_226 * V_226 )
{
F_395 ( L_11 , V_226 -> V_610 ) ;
}
static void T_16 F_396 ( void )
{
F_397 ( & V_612 ) ;
F_398 ( & V_613 ) ;
F_399 ( V_240 ) ;
F_400 ( & V_448 ) ;
}
static int T_17 F_401 ( void )
{
int V_614 = F_402 ( & V_448 , 0 ) ;
if ( V_614 != 0 )
goto V_130;
F_403 ( & V_615 ) ;
F_404 ( & V_613 ) ;
F_405 ( & V_612 ) ;
V_130:
return V_614 ;
}
