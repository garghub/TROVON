static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_1 * V_5 = V_2 ;
struct V_6 * V_7 ;
int V_8 = V_9 ;
if ( F_2 ( ! F_3 ( V_4 ) ||
! F_4 ( V_4 ) ) )
goto V_10;
V_2 = F_5 ( V_2 , V_4 ) ;
if ( V_2 != V_5 )
goto V_10;
V_7 = F_6 ( V_4 , V_2 ) ;
F_7 () ;
F_8 ( V_4 , V_7 , F_9 () ) ;
if ( ! F_10 ( V_7 ) )
V_8 = F_11 ( V_2 , V_4 , V_7 , false ) ;
F_12 ( V_4 , V_7 ) ;
F_13 () ;
if ( ! F_14 ( V_8 ) )
F_15 ( V_2 ) ;
return V_8 ;
V_10:
F_16 ( & V_4 -> V_11 ) ;
F_17 ( V_2 ) ;
return V_12 ;
}
static struct V_3 * F_18 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
F_19 () ;
V_4 = F_20 ( V_14 -> V_15 ) ;
if ( F_21 ( V_4 ) )
F_22 ( V_4 ) ;
F_23 () ;
return V_4 ;
}
static void F_24 ( struct V_13 * V_14 ,
struct V_3 * V_4 )
{
F_25 ( V_14 -> V_15 , V_4 ) ;
}
static void F_26 ( struct V_13 * V_14 )
{
F_27 ( V_14 -> V_15 , NULL ) ;
}
static bool F_28 ( const struct V_13 * V_14 )
{
return V_14 -> V_16 == F_1 ;
}
static T_1 F_29 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
return ( T_1 ) F_30 () % V_4 -> V_17 ;
}
static void F_31 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
const struct V_18 * V_19 = V_4 -> V_20 ;
T_1 V_21 ;
if ( V_19 -> V_22 ) {
V_21 = V_19 -> V_22 ( V_4 , V_2 , NULL ,
F_29 ) ;
V_21 = F_32 ( V_4 , V_21 ) ;
} else {
V_21 = F_29 ( V_4 , V_2 ) ;
}
F_33 ( V_2 , V_21 ) ;
}
static void F_34 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
if ( ! V_14 -> V_25 ) {
if ( V_14 -> V_26 )
F_36 ( V_24 , V_14 ) ;
else
F_37 ( & V_14 -> V_27 ) ;
F_38 ( V_24 ) ;
V_14 -> V_25 = 1 ;
}
}
static void F_39 ( struct V_23 * V_24 , bool V_28 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
V_14 -> V_25 = 0 ;
if ( V_14 -> V_26 )
F_40 ( V_24 , V_14 ) ;
else
F_41 ( & V_14 -> V_27 ) ;
F_42 ( V_24 ) ;
if ( V_28 ) {
F_43 ( & V_14 -> V_29 ) ;
F_44 () ;
F_45 ( & V_14 -> V_29 ) ;
}
}
static void F_46 ( struct V_23 * V_24 , bool V_28 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
if ( V_14 -> V_25 )
F_39 ( V_24 , V_28 ) ;
}
static inline struct V_30 * T_2 F_47 ( void * V_31 )
{
if ( F_48 ( V_31 ) )
return F_49 ( V_31 ) ;
return F_50 ( V_31 ) ;
}
static void F_51 ( struct V_13 * V_14 , void * V_32 , int V_33 )
{
union V_34 V_35 ;
V_35 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_40 = V_33 ;
F_52 ( F_47 ( & V_35 . V_39 -> V_40 ) ) ;
break;
case V_41 :
V_35 . V_42 -> V_40 = V_33 ;
F_52 ( F_47 ( & V_35 . V_42 -> V_40 ) ) ;
break;
case V_43 :
default:
F_53 ( 1 , L_1 ) ;
F_54 () ;
}
F_55 () ;
}
static int F_56 ( struct V_13 * V_14 , void * V_32 )
{
union V_34 V_35 ;
F_57 () ;
V_35 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_38 :
F_52 ( F_47 ( & V_35 . V_39 -> V_40 ) ) ;
return V_35 . V_39 -> V_40 ;
case V_41 :
F_52 ( F_47 ( & V_35 . V_42 -> V_40 ) ) ;
return V_35 . V_42 -> V_40 ;
case V_43 :
default:
F_53 ( 1 , L_1 ) ;
F_54 () ;
return 0 ;
}
}
static T_3 F_58 ( struct V_1 * V_2 , struct V_44 * V_45 ,
unsigned int V_46 )
{
struct V_47 * V_48 = F_59 ( V_2 ) ;
if ( V_48 &&
( V_46 & V_49 ) &&
F_60 ( V_48 -> V_50 , V_45 ) )
return V_51 ;
if ( F_60 ( V_2 -> V_52 , V_45 ) )
return V_53 ;
return 0 ;
}
static T_3 F_61 ( struct V_13 * V_14 , void * V_32 ,
struct V_1 * V_2 )
{
union V_34 V_35 ;
struct V_44 V_45 ;
T_3 V_54 ;
if ( ! ( V_54 = F_58 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
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
F_53 ( 1 , L_1 ) ;
F_54 () ;
}
F_52 ( F_47 ( & V_35 . V_39 -> V_56 ) ) ;
F_55 () ;
return V_54 ;
}
static void * F_62 ( struct V_13 * V_14 ,
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
if ( V_33 != F_56 ( V_14 , V_35 . V_36 ) )
return NULL ;
return V_35 . V_36 ;
}
static void * F_63 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
return F_62 ( V_14 , V_63 , V_63 -> V_71 , V_33 ) ;
}
static void F_64 ( struct V_72 * V_73 )
{
F_65 ( & V_73 -> V_74 ) ;
}
static void F_66 ( struct V_13 * V_14 ,
struct V_75 * V_76 )
{
struct V_72 * V_73 ;
V_73 = F_67 ( & V_14 -> V_77 ) ;
F_68 ( & V_76 -> V_78 ) ;
V_73 -> V_79 = 1 ;
F_69 ( & V_76 -> V_78 ) ;
F_64 ( V_73 ) ;
}
static void F_70 ( struct V_13 * V_14 ,
struct V_72 * V_73 ,
void (* F_71) ( unsigned long ) )
{
F_72 ( & V_73 -> V_74 ) ;
V_73 -> V_74 . V_80 = ( long ) V_14 ;
V_73 -> V_74 . V_81 = F_71 ;
V_73 -> V_74 . V_82 = V_83 ;
}
static void F_73 ( struct V_13 * V_14 )
{
struct V_72 * V_73 ;
V_73 = F_67 ( & V_14 -> V_77 ) ;
F_70 ( V_14 , V_73 , V_84 ) ;
}
static int F_74 ( struct V_13 * V_14 ,
int V_85 )
{
struct V_3 * V_4 ;
unsigned int V_86 = 0 , V_87 = 0 , div = 0 , V_88 = 0 ;
struct V_89 V_90 ;
int V_91 ;
F_75 () ;
V_4 = F_76 ( F_77 ( & V_14 -> V_24 ) , V_14 -> V_92 ) ;
if ( F_2 ( ! V_4 ) ) {
F_78 () ;
return V_93 ;
}
V_91 = F_79 ( V_4 , & V_90 ) ;
F_78 () ;
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
static void F_80 ( struct V_72 * V_98 ,
union V_99 * V_100 )
{
V_98 -> V_101 = V_100 -> V_102 . V_103 ;
}
static void F_81 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
struct V_104 * V_68 ,
union V_99 * V_100 )
{
struct V_72 * V_98 = F_67 ( V_63 ) ;
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
V_98 -> V_122 = F_74 ( V_14 ,
V_100 -> V_102 . V_111 ) ;
V_98 -> V_123 = F_82 ( V_98 -> V_122 ) ;
V_98 -> V_124 = V_100 -> V_102 . V_125 ;
V_98 -> V_126 = V_98 -> V_110 - F_83 ( V_98 -> V_124 ) ;
F_80 ( V_98 , V_100 ) ;
F_73 ( V_14 ) ;
F_84 ( V_98 , V_106 ) ;
}
static void F_85 ( struct V_72 * V_73 )
{
F_86 ( & V_73 -> V_74 ,
V_83 + V_73 -> V_123 ) ;
V_73 -> V_117 = V_73 -> V_127 ;
}
static void V_84 ( unsigned long V_80 )
{
struct V_13 * V_14 = (struct V_13 * ) V_80 ;
struct V_72 * V_73 = F_67 ( & V_14 -> V_77 ) ;
unsigned int V_128 ;
struct V_105 * V_106 ;
F_45 ( & V_14 -> V_24 . V_129 . V_78 ) ;
V_128 = F_87 ( V_73 ) ;
V_106 = F_88 ( V_73 ) ;
if ( F_2 ( V_73 -> V_79 ) )
goto V_130;
if ( F_89 ( V_106 ) ) {
while ( F_90 ( & V_73 -> V_131 ) ) {
F_91 () ;
}
}
if ( V_73 -> V_117 == V_73 -> V_127 ) {
if ( ! V_128 ) {
if ( ! F_89 ( V_106 ) ) {
goto V_132;
}
F_92 ( V_73 , V_14 , V_133 ) ;
if ( ! F_93 ( V_73 , V_14 ) )
goto V_132;
else
goto V_130;
} else {
if ( F_94 ( V_73 , V_106 ) ) {
goto V_132;
} else {
F_84 ( V_73 , V_106 ) ;
goto V_130;
}
}
}
V_132:
F_85 ( V_73 ) ;
V_130:
F_43 ( & V_14 -> V_24 . V_129 . V_78 ) ;
}
static void F_95 ( struct V_72 * V_134 ,
struct V_105 * V_135 , T_3 V_33 )
{
#if V_136 == 1
T_4 * V_137 , * V_138 ;
V_137 = ( T_4 * ) V_135 ;
V_137 += V_139 ;
V_138 = ( T_4 * ) F_96 ( ( unsigned long ) V_134 -> V_140 ) ;
for (; V_137 < V_138 ; V_137 += V_139 )
F_52 ( F_47 ( V_137 ) ) ;
F_55 () ;
#endif
F_97 ( V_135 ) = V_33 ;
#if V_136 == 1
V_137 = ( T_4 * ) V_135 ;
F_52 ( F_47 ( V_137 ) ) ;
F_55 () ;
#endif
}
static void F_98 ( struct V_72 * V_134 ,
struct V_105 * V_135 ,
struct V_13 * V_14 , unsigned int V_141 )
{
T_3 V_33 = V_142 | V_141 ;
struct V_143 * V_144 ;
struct V_145 * V_39 = & V_135 -> V_146 . V_147 ;
struct V_23 * V_24 = & V_14 -> V_24 ;
if ( V_14 -> V_118 . V_119 . V_148 )
V_33 |= V_149 ;
V_144 = (struct V_143 * ) V_134 -> V_150 ;
V_144 -> V_151 = 0 ;
if ( F_89 ( V_135 ) ) {
V_39 -> V_152 . V_153 = V_144 -> V_56 ;
V_39 -> V_152 . V_154 = V_144 -> V_61 ;
} else {
struct V_44 V_45 ;
F_99 ( & V_45 ) ;
V_39 -> V_152 . V_153 = V_45 . V_57 ;
V_39 -> V_152 . V_154 = V_45 . V_59 ;
}
F_55 () ;
F_95 ( V_134 , V_135 , V_33 ) ;
V_24 -> V_155 ( V_24 ) ;
V_134 -> V_127 = F_100 ( V_134 ) ;
}
static void F_101 ( struct V_72 * V_73 )
{
V_73 -> V_156 = 0 ;
}
static void F_84 ( struct V_72 * V_134 ,
struct V_105 * V_135 )
{
struct V_44 V_45 ;
struct V_145 * V_39 = & V_135 -> V_146 . V_147 ;
F_57 () ;
F_102 ( V_135 ) = V_134 -> V_107 ++ ;
F_89 ( V_135 ) = 0 ;
F_103 ( V_135 ) = F_83 ( V_134 -> V_124 ) ;
F_99 ( & V_45 ) ;
V_39 -> V_157 . V_153 = V_45 . V_57 ;
V_39 -> V_157 . V_154 = V_45 . V_59 ;
V_134 -> V_109 = ( char * ) V_135 ;
V_134 -> V_158 = V_134 -> V_109 + F_83 ( V_134 -> V_124 ) ;
F_104 ( V_135 ) = ( T_3 ) F_83 ( V_134 -> V_124 ) ;
F_105 ( V_135 ) = V_159 ;
V_135 -> V_116 = V_134 -> V_116 ;
V_134 -> V_150 = V_134 -> V_158 ;
V_134 -> V_140 = V_134 -> V_109 + V_134 -> V_110 ;
F_101 ( V_134 ) ;
F_85 ( V_134 ) ;
F_55 () ;
}
static void F_106 ( struct V_72 * V_73 ,
struct V_13 * V_14 )
{
V_73 -> V_156 = 1 ;
V_14 -> V_118 . V_119 . V_120 ++ ;
}
static void * F_93 ( struct V_72 * V_73 ,
struct V_13 * V_14 )
{
struct V_105 * V_106 ;
F_57 () ;
V_106 = F_88 ( V_73 ) ;
if ( V_142 & F_97 ( V_106 ) ) {
F_106 ( V_73 , V_14 ) ;
return NULL ;
}
F_84 ( V_73 , V_106 ) ;
return ( void * ) V_73 -> V_158 ;
}
static void F_92 ( struct V_72 * V_73 ,
struct V_13 * V_14 , unsigned int V_33 )
{
struct V_105 * V_106 = F_88 ( V_73 ) ;
if ( F_21 ( V_160 == F_97 ( V_106 ) ) ) {
if ( ! ( V_33 & V_133 ) ) {
while ( F_90 ( & V_73 -> V_131 ) ) {
F_91 () ;
}
}
F_98 ( V_73 , V_106 , V_14 , V_33 ) ;
return;
}
}
static int F_94 ( struct V_72 * V_73 ,
struct V_105 * V_106 )
{
return V_142 & F_97 ( V_106 ) ;
}
static int F_87 ( struct V_72 * V_73 )
{
return V_73 -> V_156 ;
}
static void F_107 ( struct V_62 * V_63 )
{
struct V_72 * V_73 = F_67 ( V_63 ) ;
F_108 ( & V_73 -> V_131 ) ;
}
static void F_109 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
V_161 -> V_162 . V_163 = F_110 ( V_73 -> V_2 ) ;
}
static void F_111 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
V_161 -> V_162 . V_163 = 0 ;
}
static void F_112 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
if ( F_113 ( V_73 -> V_2 ) ) {
V_161 -> V_162 . V_164 = F_114 ( V_73 -> V_2 ) ;
V_161 -> V_162 . V_165 = F_115 ( V_73 -> V_2 -> V_166 ) ;
V_161 -> V_40 = V_167 | V_168 ;
} else {
V_161 -> V_162 . V_164 = 0 ;
V_161 -> V_162 . V_165 = 0 ;
V_161 -> V_40 = V_169 ;
}
}
static void F_116 ( struct V_72 * V_73 ,
struct V_143 * V_161 )
{
V_161 -> V_162 . V_170 = 0 ;
F_112 ( V_73 , V_161 ) ;
if ( V_73 -> V_101 & V_171 )
F_109 ( V_73 , V_161 ) ;
else
F_111 ( V_73 , V_161 ) ;
}
static void F_117 ( char * V_172 ,
struct V_72 * V_73 ,
struct V_105 * V_106 ,
unsigned int V_173 )
{
struct V_143 * V_161 ;
V_161 = (struct V_143 * ) V_172 ;
V_161 -> V_151 = F_118 ( V_173 ) ;
V_73 -> V_150 = V_172 ;
V_73 -> V_158 += F_118 ( V_173 ) ;
F_103 ( V_106 ) += F_118 ( V_173 ) ;
F_89 ( V_106 ) += 1 ;
F_119 ( & V_73 -> V_131 ) ;
F_116 ( V_73 , V_161 ) ;
}
static void * F_120 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 ,
unsigned int V_173
)
{
struct V_72 * V_73 ;
struct V_105 * V_106 ;
char * V_172 , * V_138 ;
V_73 = F_67 ( & V_14 -> V_77 ) ;
V_106 = F_88 ( V_73 ) ;
if ( F_87 ( V_73 ) ) {
if ( F_94 ( V_73 , V_106 ) ) {
return NULL ;
} else {
F_84 ( V_73 , V_106 ) ;
}
}
F_121 () ;
V_172 = V_73 -> V_158 ;
V_73 -> V_2 = V_2 ;
V_138 = ( char * ) V_106 + V_73 -> V_110 ;
if ( V_172 + F_118 ( V_173 ) < V_138 ) {
F_117 ( V_172 , V_73 , V_106 , V_173 ) ;
return ( void * ) V_172 ;
}
F_92 ( V_73 , V_14 , 0 ) ;
V_172 = ( char * ) F_93 ( V_73 , V_14 ) ;
if ( V_172 ) {
V_106 = F_88 ( V_73 ) ;
F_117 ( V_172 , V_73 , V_106 , V_173 ) ;
return ( void * ) V_172 ;
}
return NULL ;
}
static void * F_122 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 , unsigned int V_173 )
{
char * V_172 = NULL ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_172 = F_62 ( V_14 , & V_14 -> V_77 ,
V_14 -> V_77 . V_71 , V_33 ) ;
return V_172 ;
case V_43 :
return F_120 ( V_14 , V_2 , V_33 , V_173 ) ;
default:
F_53 ( 1 , L_2 ) ;
F_54 () ;
return NULL ;
}
}
static void * F_123 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
unsigned int V_174 ,
int V_33 )
{
struct V_72 * V_73 = F_67 ( V_63 ) ;
struct V_105 * V_106 = F_124 ( V_73 , V_174 ) ;
if ( V_33 != F_97 ( V_106 ) )
return NULL ;
return V_106 ;
}
static int F_125 ( struct V_62 * V_63 )
{
unsigned int V_150 ;
if ( V_63 -> V_175 . V_127 )
V_150 = V_63 -> V_175 . V_127 - 1 ;
else
V_150 = V_63 -> V_175 . V_112 - 1 ;
return V_150 ;
}
static void * F_126 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
unsigned int V_176 = F_125 ( V_63 ) ;
return F_123 ( V_14 , V_63 , V_176 , V_33 ) ;
}
static void * F_127 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
if ( V_14 -> V_37 <= V_41 )
return F_128 ( V_14 , V_63 , V_33 ) ;
return F_126 ( V_14 , V_63 , V_33 ) ;
}
static void F_129 ( struct V_13 * V_14 ,
struct V_62 * V_63 )
{
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
return F_130 ( V_63 ) ;
case V_43 :
default:
F_53 ( 1 , L_1 ) ;
F_54 () ;
return;
}
}
static void * F_128 ( struct V_13 * V_14 ,
struct V_62 * V_63 ,
int V_33 )
{
unsigned int V_176 = V_63 -> V_71 ? V_63 -> V_71 - 1 : V_63 -> V_177 ;
return F_62 ( V_14 , V_63 , V_176 , V_33 ) ;
}
static void F_130 ( struct V_62 * V_178 )
{
V_178 -> V_71 = V_178 -> V_71 != V_178 -> V_177 ? V_178 -> V_71 + 1 : 0 ;
}
static void F_131 ( struct V_62 * V_63 )
{
F_132 ( * V_63 -> V_179 ) ;
}
static void F_133 ( struct V_62 * V_63 )
{
F_134 ( * V_63 -> V_179 ) ;
}
static unsigned int F_135 ( const struct V_62 * V_63 )
{
unsigned int V_180 = 0 ;
int V_181 ;
if ( V_63 -> V_179 == NULL )
return 0 ;
F_136 (cpu)
V_180 += * F_137 ( V_63 -> V_179 , V_181 ) ;
return V_180 ;
}
static int F_138 ( struct V_13 * V_14 )
{
V_14 -> V_77 . V_179 = NULL ;
V_14 -> V_182 . V_179 = F_139 (unsigned int) ;
if ( F_2 ( V_14 -> V_182 . V_179 == NULL ) )
return - V_183 ;
return 0 ;
}
static void F_140 ( struct V_13 * V_14 )
{
F_141 ( V_14 -> V_182 . V_179 ) ;
}
static bool F_142 ( struct V_13 * V_14 , int V_184 )
{
int V_174 , V_173 ;
V_173 = V_14 -> V_77 . V_177 + 1 ;
V_174 = V_14 -> V_77 . V_71 ;
if ( V_184 )
V_174 += V_173 >> V_184 ;
if ( V_174 >= V_173 )
V_174 -= V_173 ;
return F_62 ( V_14 , & V_14 -> V_77 , V_174 , V_160 ) ;
}
static bool F_143 ( struct V_13 * V_14 , int V_184 )
{
int V_174 , V_173 ;
V_173 = V_14 -> V_77 . V_175 . V_112 ;
V_174 = V_14 -> V_77 . V_175 . V_127 ;
if ( V_184 )
V_174 += V_173 >> V_184 ;
if ( V_174 >= V_173 )
V_174 -= V_173 ;
return F_123 ( V_14 , & V_14 -> V_77 , V_174 , V_160 ) ;
}
static int F_144 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_14 -> V_24 ;
int V_8 = V_185 ;
if ( V_14 -> V_27 . F_71 != V_186 ) {
int V_187 = V_24 -> V_188 - F_90 ( & V_24 -> V_189 )
- ( V_2 ? V_2 -> V_190 : 0 ) ;
if ( V_187 > ( V_24 -> V_188 >> V_191 ) )
return V_192 ;
else if ( V_187 > 0 )
return V_193 ;
else
return V_185 ;
}
if ( V_14 -> V_37 == V_43 ) {
if ( F_143 ( V_14 , V_191 ) )
V_8 = V_192 ;
else if ( F_143 ( V_14 , 0 ) )
V_8 = V_193 ;
} else {
if ( F_142 ( V_14 , V_191 ) )
V_8 = V_192 ;
else if ( F_142 ( V_14 , 0 ) )
V_8 = V_193 ;
}
return V_8 ;
}
static int F_145 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
int V_8 ;
bool V_194 ;
F_68 ( & V_14 -> V_24 . V_129 . V_78 ) ;
V_8 = F_144 ( V_14 , V_2 ) ;
V_194 = V_8 == V_192 ;
if ( V_14 -> V_195 == V_194 )
V_14 -> V_195 = ! V_194 ;
F_69 ( & V_14 -> V_24 . V_129 . V_78 ) ;
return V_8 ;
}
static void F_146 ( struct V_23 * V_24 )
{
F_147 ( & V_24 -> V_196 ) ;
F_148 ( F_90 ( & V_24 -> V_189 ) ) ;
F_148 ( F_90 ( & V_24 -> V_197 ) ) ;
if ( ! F_149 ( V_24 , V_198 ) ) {
F_150 ( L_3 , V_24 ) ;
return;
}
F_151 ( V_24 ) ;
}
static bool F_152 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
T_5 V_199 ;
int V_200 , V_201 = 0 ;
V_199 = F_110 ( V_2 ) ;
for ( V_200 = 0 ; V_200 < V_202 ; V_200 ++ )
if ( V_14 -> V_203 -> V_204 [ V_200 ] == V_199 )
V_201 ++ ;
V_14 -> V_203 -> V_204 [ F_153 () % V_202 ] = V_199 ;
return V_201 > ( V_202 >> 1 ) ;
}
static unsigned int F_154 ( struct V_205 * V_206 ,
struct V_1 * V_2 ,
unsigned int V_207 )
{
return F_155 ( F_156 ( V_2 ) , V_207 ) ;
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
return F_9 () % V_207 ;
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
V_14 = F_35 ( V_206 -> V_215 [ V_174 ] ) ;
if ( V_210 ) {
V_214 = F_145 ( V_14 , V_2 ) ;
if ( V_214 == V_192 ||
( V_214 == V_193 && ! F_152 ( V_14 , V_2 ) ) )
return V_174 ;
V_212 = V_14 ;
}
V_200 = V_213 = F_163 ( int , V_14 -> V_203 -> V_23 , V_207 - 1 ) ;
do {
V_211 = F_35 ( V_206 -> V_215 [ V_200 ] ) ;
if ( V_211 != V_212 && ! V_211 -> V_195 &&
F_145 ( V_211 , V_2 ) == V_192 ) {
if ( V_200 != V_213 )
V_14 -> V_203 -> V_23 = V_200 ;
F_16 ( & V_14 -> V_203 -> V_207 ) ;
if ( V_214 == V_193 )
F_16 ( & V_14 -> V_203 -> V_216 ) ;
return V_200 ;
}
if ( ++ V_200 == V_207 )
V_200 = 0 ;
} while ( V_200 != V_213 );
F_16 ( & V_14 -> V_203 -> V_217 ) ;
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
F_19 () ;
V_219 = F_20 ( V_206 -> V_218 ) ;
if ( V_219 )
V_8 = F_167 ( V_219 , V_2 ) % V_207 ;
F_23 () ;
return V_8 ;
}
static bool F_168 ( struct V_205 * V_206 , T_1 V_220 )
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
F_15 ( V_2 ) ;
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
V_174 = F_154 ( V_206 , V_2 , V_207 ) ;
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
V_14 = F_35 ( V_206 -> V_215 [ V_174 ] ) ;
return V_14 -> V_27 . F_71 ( V_2 , V_4 , & V_14 -> V_27 , V_223 ) ;
}
static void F_36 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_205 * V_206 = V_14 -> V_26 ;
F_45 ( & V_206 -> V_78 ) ;
V_206 -> V_215 [ V_206 -> V_225 ] = V_24 ;
F_55 () ;
V_206 -> V_225 ++ ;
if ( V_206 -> V_225 == 1 )
F_37 ( & V_206 -> V_27 ) ;
F_43 ( & V_206 -> V_78 ) ;
}
static void F_40 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_205 * V_206 = V_14 -> V_26 ;
int V_200 ;
F_45 ( & V_206 -> V_78 ) ;
for ( V_200 = 0 ; V_200 < V_206 -> V_225 ; V_200 ++ ) {
if ( V_206 -> V_215 [ V_200 ] == V_24 )
break;
}
F_175 ( V_200 >= V_206 -> V_225 ) ;
V_206 -> V_215 [ V_200 ] = V_206 -> V_215 [ V_206 -> V_225 - 1 ] ;
V_206 -> V_225 -- ;
if ( V_206 -> V_225 == 0 )
F_41 ( & V_206 -> V_27 ) ;
F_43 ( & V_206 -> V_78 ) ;
}
static bool F_176 ( struct V_221 * V_238 , struct V_23 * V_24 )
{
if ( V_24 -> V_239 != V_240 )
return false ;
return V_238 -> V_224 == F_35 ( V_24 ) -> V_26 ;
}
static void F_177 ( struct V_205 * V_206 )
{
switch ( V_206 -> type ) {
case V_230 :
F_178 ( & V_206 -> V_209 , 0 ) ;
break;
case V_235 :
case V_236 :
F_27 ( V_206 -> V_218 , NULL ) ;
break;
}
}
static void F_179 ( struct V_205 * V_206 , struct V_218 * V_241 )
{
struct V_218 * V_242 ;
F_45 ( & V_206 -> V_78 ) ;
V_242 = F_180 ( V_206 -> V_218 , F_181 ( & V_206 -> V_78 ) ) ;
F_25 ( V_206 -> V_218 , V_241 ) ;
F_43 ( & V_206 -> V_78 ) ;
if ( V_242 ) {
F_44 () ;
F_182 ( V_242 ) ;
}
}
static int F_183 ( struct V_13 * V_14 , char T_6 * V_80 ,
unsigned int V_173 )
{
struct V_218 * V_241 ;
struct V_243 V_244 ;
int V_8 ;
if ( F_149 ( & V_14 -> V_24 , V_245 ) )
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
static int F_186 ( struct V_13 * V_14 , char T_6 * V_80 ,
unsigned int V_173 )
{
struct V_218 * V_241 ;
T_5 V_249 ;
if ( F_149 ( & V_14 -> V_24 , V_245 ) )
return - V_246 ;
if ( V_173 != sizeof( V_249 ) )
return - V_247 ;
if ( F_184 ( & V_249 , V_80 , V_173 ) )
return - V_248 ;
V_241 = F_187 ( V_249 , V_250 ) ;
if ( F_188 ( V_241 ) )
return F_189 ( V_241 ) ;
F_179 ( V_14 -> V_26 , V_241 ) ;
return 0 ;
}
static int F_190 ( struct V_13 * V_14 , char T_6 * V_80 ,
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
static void F_191 ( struct V_205 * V_206 )
{
switch ( V_206 -> type ) {
case V_235 :
case V_236 :
F_179 ( V_206 , NULL ) ;
} ;
}
static int F_192 ( struct V_23 * V_24 , T_1 V_251 , T_1 V_252 )
{
struct V_253 * V_203 = NULL ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_205 * V_206 , * V_254 ;
T_4 type = V_252 & 0xff ;
T_4 V_46 = V_252 >> 8 ;
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
F_193 ( & V_255 ) ;
V_91 = - V_247 ;
if ( ! V_14 -> V_25 )
goto V_130;
V_91 = - V_256 ;
if ( V_14 -> V_26 )
goto V_130;
if ( type == V_234 ||
( V_252 & V_237 ) ) {
V_91 = - V_257 ;
V_203 = F_194 ( sizeof( * V_203 ) , V_258 ) ;
if ( ! V_203 )
goto V_130;
F_195 ( & V_203 -> V_207 , 0 ) ;
F_195 ( & V_203 -> V_216 , 0 ) ;
F_195 ( & V_203 -> V_217 , 0 ) ;
V_14 -> V_203 = V_203 ;
}
V_254 = NULL ;
F_196 (f, &fanout_list, list) {
if ( V_206 -> V_251 == V_251 &&
F_171 ( & V_206 -> V_226 ) == F_77 ( V_24 ) ) {
V_254 = V_206 ;
break;
}
}
V_91 = - V_247 ;
if ( V_254 && V_254 -> V_46 != V_46 )
goto V_130;
if ( ! V_254 ) {
V_91 = - V_257 ;
V_254 = F_194 ( sizeof( * V_254 ) , V_258 ) ;
if ( ! V_254 )
goto V_130;
F_197 ( & V_254 -> V_226 , F_77 ( V_24 ) ) ;
V_254 -> V_251 = V_251 ;
V_254 -> type = type ;
V_254 -> V_46 = V_46 ;
F_198 ( & V_254 -> V_259 ) ;
F_199 ( & V_254 -> V_78 ) ;
F_178 ( & V_254 -> V_260 , 0 ) ;
F_177 ( V_254 ) ;
V_254 -> V_27 . type = V_14 -> V_27 . type ;
V_254 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_254 -> V_27 . F_71 = F_169 ;
V_254 -> V_27 . V_224 = V_254 ;
V_254 -> V_27 . V_261 = F_176 ;
F_200 ( & V_254 -> V_259 , & V_262 ) ;
}
V_91 = - V_247 ;
if ( V_254 -> type == type &&
V_254 -> V_27 . type == V_14 -> V_27 . type &&
V_254 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_91 = - V_263 ;
if ( F_90 ( & V_254 -> V_260 ) < V_264 ) {
F_41 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_254 ;
F_119 ( & V_254 -> V_260 ) ;
F_36 ( V_24 , V_14 ) ;
V_91 = 0 ;
}
}
V_130:
if ( V_91 && V_203 ) {
F_201 ( V_203 ) ;
V_14 -> V_203 = NULL ;
}
F_202 ( & V_255 ) ;
return V_91 ;
}
static struct V_205 * F_203 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_205 * V_206 ;
F_193 ( & V_255 ) ;
V_206 = V_14 -> V_26 ;
if ( V_206 ) {
V_14 -> V_26 = NULL ;
if ( F_204 ( & V_206 -> V_260 ) )
F_205 ( & V_206 -> V_259 ) ;
else
V_206 = NULL ;
if ( V_14 -> V_203 )
F_206 ( V_14 -> V_203 , V_265 ) ;
}
F_202 ( & V_255 ) ;
return V_206 ;
}
static bool F_207 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( F_2 ( V_4 -> type != V_266 ) )
return false ;
F_208 ( V_2 ) ;
return F_21 ( F_209 ( V_2 ) -> V_267 == F_210 ( V_268 ) ) ;
}
static int F_211 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_23 * V_24 ;
struct V_269 * V_270 ;
V_24 = V_222 -> V_224 ;
if ( V_2 -> V_271 == V_272 )
goto V_130;
if ( ! F_172 ( F_173 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_130;
V_2 = F_212 ( V_2 , V_273 ) ;
if ( V_2 == NULL )
goto V_274;
F_213 ( V_2 ) ;
F_214 ( V_2 ) ;
V_270 = & F_215 ( V_2 ) -> V_275 . V_276 ;
F_216 ( V_2 , V_2 -> V_80 - F_217 ( V_2 ) ) ;
V_270 -> V_277 = V_4 -> type ;
F_218 ( V_270 -> V_278 , V_4 -> V_279 , sizeof( V_270 -> V_278 ) ) ;
V_270 -> V_280 = V_2 -> V_281 ;
if ( F_219 ( V_24 , V_2 ) == 0 )
return 0 ;
V_130:
F_15 ( V_2 ) ;
V_274:
return 0 ;
}
static int F_220 ( struct V_282 * V_23 , struct V_283 * V_284 ,
T_7 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_221 ( struct V_269 * , V_285 , V_284 -> V_286 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
struct V_287 V_288 ;
T_8 V_289 = 0 ;
int V_91 ;
int V_290 = 0 ;
if ( V_285 ) {
if ( V_284 -> V_291 < sizeof( struct V_292 ) )
return - V_247 ;
if ( V_284 -> V_291 == sizeof( struct V_269 ) )
V_289 = V_285 -> V_280 ;
} else
return - V_293 ;
V_285 -> V_278 [ sizeof( V_285 -> V_278 ) - 1 ] = 0 ;
V_294:
F_19 () ;
V_4 = F_222 ( F_77 ( V_24 ) , V_285 -> V_278 ) ;
V_91 = - V_295 ;
if ( V_4 == NULL )
goto V_296;
V_91 = - V_297 ;
if ( ! ( V_4 -> V_46 & V_298 ) )
goto V_296;
if ( F_2 ( F_149 ( V_24 , V_299 ) ) ) {
if ( ! F_223 ( V_4 ) ) {
V_91 = - V_300 ;
goto V_296;
}
V_290 = 4 ;
}
V_91 = - V_301 ;
if ( V_173 > V_4 -> V_302 + V_4 -> V_303 + V_304 + V_290 )
goto V_296;
if ( ! V_2 ) {
T_7 V_305 = F_224 ( V_4 ) ;
int V_306 = V_4 -> V_307 ;
unsigned int V_308 = V_4 -> V_309 ? V_4 -> V_303 : 0 ;
F_23 () ;
V_2 = F_225 ( V_24 , V_173 + V_305 + V_306 , 0 , V_258 ) ;
if ( V_2 == NULL )
return - V_183 ;
F_226 ( V_2 , V_305 ) ;
F_227 ( V_2 ) ;
if ( V_308 ) {
V_2 -> V_80 -= V_308 ;
V_2 -> V_310 -= V_308 ;
if ( V_173 < V_308 )
F_227 ( V_2 ) ;
}
V_91 = F_228 ( F_229 ( V_2 , V_173 ) , V_284 , V_173 ) ;
if ( V_91 )
goto V_311;
goto V_294;
}
if ( ! F_230 ( V_4 , V_2 -> V_80 , V_173 ) ) {
V_91 = - V_247 ;
goto V_296;
}
if ( V_173 > ( V_4 -> V_302 + V_4 -> V_303 + V_290 ) &&
! F_207 ( V_4 , V_2 ) ) {
V_91 = - V_301 ;
goto V_296;
}
V_288 . V_312 = V_24 -> V_313 ;
if ( V_284 -> V_314 ) {
V_91 = F_231 ( V_24 , V_284 , & V_288 ) ;
if ( F_2 ( V_91 ) )
goto V_296;
}
V_2 -> V_281 = V_289 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_315 = V_24 -> V_316 ;
V_2 -> V_317 = V_24 -> V_318 ;
F_232 ( V_24 , V_288 . V_312 , & F_233 ( V_2 ) -> V_319 ) ;
if ( F_2 ( V_290 == 4 ) )
V_2 -> V_320 = 1 ;
F_234 ( V_2 , 0 ) ;
F_235 ( V_2 ) ;
F_23 () ;
return V_173 ;
V_296:
F_23 () ;
V_311:
F_15 ( V_2 ) ;
return V_91 ;
}
static unsigned int F_236 ( struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_321 )
{
struct V_322 * V_323 ;
F_19 () ;
V_323 = F_20 ( V_24 -> V_322 ) ;
if ( V_323 != NULL )
V_321 = F_167 ( V_323 -> V_219 , V_2 ) ;
F_23 () ;
return V_321 ;
}
static int F_237 ( struct V_283 * V_284 , const struct V_1 * V_2 ,
T_7 * V_173 )
{
struct V_324 V_325 ;
if ( * V_173 < sizeof( V_325 ) )
return - V_247 ;
* V_173 -= sizeof( V_325 ) ;
if ( F_238 ( V_2 , & V_325 , F_239 () , true ) )
return - V_247 ;
return F_240 ( V_284 , ( void * ) & V_325 , sizeof( V_325 ) ) ;
}
static int F_241 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_23 * V_24 ;
struct V_326 * V_327 ;
struct V_13 * V_14 ;
T_4 * V_328 = V_2 -> V_80 ;
int V_329 = V_2 -> V_173 ;
unsigned int V_330 , V_321 ;
bool V_331 = false ;
if ( V_2 -> V_271 == V_272 )
goto V_10;
V_24 = V_222 -> V_224 ;
V_14 = F_35 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_309 ) {
if ( V_24 -> V_332 != V_333 )
F_216 ( V_2 , V_2 -> V_80 - F_217 ( V_2 ) ) ;
else if ( V_2 -> V_271 == V_334 ) {
F_242 ( V_2 , F_243 ( V_2 ) ) ;
}
}
V_330 = V_2 -> V_173 ;
V_321 = F_236 ( V_2 , V_24 , V_330 ) ;
if ( ! V_321 )
goto V_335;
if ( V_330 > V_321 )
V_330 = V_321 ;
if ( F_90 ( & V_24 -> V_189 ) >= V_24 -> V_188 )
goto V_336;
if ( F_244 ( V_2 ) ) {
struct V_1 * V_337 = F_245 ( V_2 , V_273 ) ;
if ( V_337 == NULL )
goto V_336;
if ( V_328 != V_2 -> V_80 ) {
V_2 -> V_80 = V_328 ;
V_2 -> V_173 = V_329 ;
}
F_246 ( V_2 ) ;
V_2 = V_337 ;
}
F_247 ( sizeof( * F_215 ( V_2 ) ) + V_338 - 8 ) ;
V_327 = & F_215 ( V_2 ) -> V_275 . V_339 ;
V_327 -> V_340 = V_4 -> type ;
V_327 -> V_341 = V_2 -> V_271 ;
if ( F_2 ( V_14 -> V_342 ) )
V_327 -> V_343 = V_223 -> V_92 ;
else
V_327 -> V_343 = V_4 -> V_92 ;
V_327 -> V_344 = F_248 ( V_2 , V_327 -> V_345 ) ;
F_215 ( V_2 ) -> V_275 . V_346 = V_2 -> V_173 ;
if ( F_249 ( V_2 , V_330 ) )
goto V_336;
F_250 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_213 ( V_2 ) ;
F_214 ( V_2 ) ;
F_45 ( & V_24 -> V_129 . V_78 ) ;
V_14 -> V_118 . V_347 . V_348 ++ ;
F_251 ( V_24 , V_2 ) ;
F_252 ( & V_24 -> V_129 , V_2 ) ;
F_43 ( & V_24 -> V_129 . V_78 ) ;
V_24 -> V_155 ( V_24 ) ;
return 0 ;
V_336:
V_331 = true ;
F_45 ( & V_24 -> V_129 . V_78 ) ;
V_14 -> V_118 . V_347 . V_148 ++ ;
F_119 ( & V_24 -> V_349 ) ;
F_43 ( & V_24 -> V_129 . V_78 ) ;
V_335:
if ( V_328 != V_2 -> V_80 && F_244 ( V_2 ) ) {
V_2 -> V_80 = V_328 ;
V_2 -> V_173 = V_329 ;
}
V_10:
if ( ! V_331 )
F_246 ( V_2 ) ;
else
F_15 ( V_2 ) ;
return 0 ;
}
static int V_186 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_221 * V_222 , struct V_3 * V_223 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
struct V_326 * V_327 ;
union V_34 V_35 ;
T_4 * V_328 = V_2 -> V_80 ;
int V_329 = V_2 -> V_173 ;
unsigned int V_330 , V_321 ;
unsigned long V_33 = V_142 ;
unsigned short V_350 , V_351 , V_114 ;
struct V_1 * V_352 = NULL ;
struct V_44 V_45 ;
T_3 V_54 ;
bool V_331 = false ;
F_253 ( F_254 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_253 ( F_254 ( sizeof( * V_35 . V_353 ) ) != 48 ) ;
if ( V_2 -> V_271 == V_272 )
goto V_10;
V_24 = V_222 -> V_224 ;
V_14 = F_35 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_309 ) {
if ( V_24 -> V_332 != V_333 )
F_216 ( V_2 , V_2 -> V_80 - F_217 ( V_2 ) ) ;
else if ( V_2 -> V_271 == V_334 ) {
F_242 ( V_2 , F_243 ( V_2 ) ) ;
}
}
V_330 = V_2 -> V_173 ;
V_321 = F_236 ( V_2 , V_24 , V_330 ) ;
if ( ! V_321 )
goto V_335;
if ( V_2 -> V_354 == V_355 )
V_33 |= V_356 ;
else if ( V_2 -> V_271 != V_334 &&
( V_2 -> V_354 == V_357 ||
F_255 ( V_2 ) ) )
V_33 |= V_358 ;
if ( V_330 > V_321 )
V_330 = V_321 ;
if ( V_24 -> V_332 == V_333 ) {
V_350 = V_351 = F_254 ( V_14 -> V_115 ) + 16 +
V_14 -> V_359 ;
} else {
unsigned int V_360 = F_243 ( V_2 ) ;
V_351 = F_254 ( V_14 -> V_115 +
( V_360 < 16 ? 16 : V_360 ) ) +
V_14 -> V_359 ;
if ( V_14 -> V_361 )
V_351 += sizeof( struct V_324 ) ;
V_350 = V_351 - V_360 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_350 + V_330 > V_14 -> V_77 . V_70 ) {
if ( V_14 -> V_362 &&
F_90 ( & V_24 -> V_189 ) < V_24 -> V_188 ) {
if ( F_244 ( V_2 ) ) {
V_352 = F_245 ( V_2 , V_273 ) ;
} else {
V_352 = F_256 ( V_2 ) ;
V_328 = V_2 -> V_80 ;
}
if ( V_352 )
F_250 ( V_352 , V_24 ) ;
}
V_330 = V_14 -> V_77 . V_70 - V_350 ;
if ( ( int ) V_330 < 0 )
V_330 = 0 ;
}
} else if ( F_2 ( V_350 + V_330 >
F_67 ( & V_14 -> V_77 ) -> V_126 ) ) {
T_5 V_363 ;
V_363 = F_67 ( & V_14 -> V_77 ) -> V_126 - V_350 ;
F_257 ( L_4 ,
V_330 , V_363 , V_350 ) ;
V_330 = V_363 ;
if ( F_2 ( ( int ) V_330 < 0 ) ) {
V_330 = 0 ;
V_350 = F_67 ( & V_14 -> V_77 ) -> V_126 ;
}
}
F_45 ( & V_24 -> V_129 . V_78 ) ;
V_35 . V_36 = F_122 ( V_14 , V_2 ,
V_160 , ( V_350 + V_330 ) ) ;
if ( ! V_35 . V_36 )
goto V_364;
if ( V_14 -> V_37 <= V_41 ) {
F_129 ( V_14 , & V_14 -> V_77 ) ;
if ( V_14 -> V_118 . V_347 . V_148 )
V_33 |= V_149 ;
}
V_14 -> V_118 . V_347 . V_348 ++ ;
if ( V_352 ) {
V_33 |= V_365 ;
F_252 ( & V_24 -> V_129 , V_352 ) ;
}
F_43 ( & V_24 -> V_129 . V_78 ) ;
if ( V_14 -> V_361 ) {
if ( F_238 ( V_2 , V_35 . V_36 + V_350 -
sizeof( struct V_324 ) ,
F_239 () , true ) ) {
F_45 ( & V_24 -> V_129 . V_78 ) ;
goto V_364;
}
}
F_258 ( V_2 , 0 , V_35 . V_36 + V_350 , V_330 ) ;
if ( ! ( V_54 = F_58 ( V_2 , & V_45 , V_14 -> V_55 ) ) )
F_99 ( & V_45 ) ;
V_33 |= V_54 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_366 = V_2 -> V_173 ;
V_35 . V_39 -> V_367 = V_330 ;
V_35 . V_39 -> V_368 = V_350 ;
V_35 . V_39 -> V_369 = V_351 ;
V_35 . V_39 -> V_56 = V_45 . V_57 ;
V_35 . V_39 -> V_58 = V_45 . V_59 / V_60 ;
V_114 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_366 = V_2 -> V_173 ;
V_35 . V_42 -> V_367 = V_330 ;
V_35 . V_42 -> V_368 = V_350 ;
V_35 . V_42 -> V_369 = V_351 ;
V_35 . V_42 -> V_56 = V_45 . V_57 ;
V_35 . V_42 -> V_61 = V_45 . V_59 ;
if ( F_113 ( V_2 ) ) {
V_35 . V_42 -> V_164 = F_114 ( V_2 ) ;
V_35 . V_42 -> V_165 = F_115 ( V_2 -> V_166 ) ;
V_33 |= V_167 | V_168 ;
} else {
V_35 . V_42 -> V_164 = 0 ;
V_35 . V_42 -> V_165 = 0 ;
}
memset ( V_35 . V_42 -> V_170 , 0 , sizeof( V_35 . V_42 -> V_170 ) ) ;
V_114 = sizeof( * V_35 . V_42 ) ;
break;
case V_43 :
V_35 . V_353 -> V_40 |= V_33 ;
V_35 . V_353 -> V_366 = V_2 -> V_173 ;
V_35 . V_353 -> V_367 = V_330 ;
V_35 . V_353 -> V_368 = V_350 ;
V_35 . V_353 -> V_369 = V_351 ;
V_35 . V_353 -> V_56 = V_45 . V_57 ;
V_35 . V_353 -> V_61 = V_45 . V_59 ;
memset ( V_35 . V_353 -> V_170 , 0 , sizeof( V_35 . V_353 -> V_170 ) ) ;
V_114 = sizeof( * V_35 . V_353 ) ;
break;
default:
F_54 () ;
}
V_327 = V_35 . V_36 + F_254 ( V_114 ) ;
V_327 -> V_344 = F_248 ( V_2 , V_327 -> V_345 ) ;
V_327 -> V_370 = V_371 ;
V_327 -> V_340 = V_4 -> type ;
V_327 -> V_372 = V_2 -> V_281 ;
V_327 -> V_341 = V_2 -> V_271 ;
if ( F_2 ( V_14 -> V_342 ) )
V_327 -> V_343 = V_223 -> V_92 ;
else
V_327 -> V_343 = V_4 -> V_92 ;
F_121 () ;
#if V_136 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_4 * V_137 , * V_138 ;
V_138 = ( T_4 * ) F_96 ( ( unsigned long ) V_35 . V_36 +
V_350 + V_330 ) ;
for ( V_137 = V_35 . V_36 ; V_137 < V_138 ; V_137 += V_139 )
F_52 ( F_47 ( V_137 ) ) ;
}
F_55 () ;
#endif
if ( V_14 -> V_37 <= V_41 ) {
F_51 ( V_14 , V_35 . V_36 , V_33 ) ;
V_24 -> V_155 ( V_24 ) ;
} else {
F_107 ( & V_14 -> V_77 ) ;
}
V_335:
if ( V_328 != V_2 -> V_80 && F_244 ( V_2 ) ) {
V_2 -> V_80 = V_328 ;
V_2 -> V_173 = V_329 ;
}
V_10:
if ( ! V_331 )
F_246 ( V_2 ) ;
else
F_15 ( V_2 ) ;
return 0 ;
V_364:
V_331 = true ;
V_14 -> V_118 . V_347 . V_148 ++ ;
F_43 ( & V_24 -> V_129 . V_78 ) ;
V_24 -> V_155 ( V_24 ) ;
F_15 ( V_352 ) ;
goto V_335;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_35 ( V_2 -> V_24 ) ;
if ( F_21 ( V_14 -> V_182 . V_68 ) ) {
void * V_373 ;
T_3 V_45 ;
V_373 = F_233 ( V_2 ) -> V_374 ;
F_133 ( & V_14 -> V_182 ) ;
V_45 = F_61 ( V_14 , V_373 , V_2 ) ;
F_51 ( V_14 , V_373 , V_169 | V_45 ) ;
}
F_260 ( V_2 ) ;
}
static void F_261 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( V_4 -> type == V_266 ) {
F_208 ( V_2 ) ;
V_2 -> V_281 = F_209 ( V_2 ) -> V_267 ;
}
}
static int F_262 ( struct V_324 * V_325 , T_7 V_173 )
{
if ( ( V_325 -> V_46 & V_375 ) &&
( F_263 ( F_239 () , V_325 -> V_376 ) +
F_263 ( F_239 () , V_325 -> V_377 ) + 2 >
F_263 ( F_239 () , V_325 -> V_378 ) ) )
V_325 -> V_378 = F_264 ( F_239 () ,
F_263 ( F_239 () , V_325 -> V_376 ) +
F_263 ( F_239 () , V_325 -> V_377 ) + 2 ) ;
if ( F_263 ( F_239 () , V_325 -> V_378 ) > V_173 )
return - V_247 ;
return 0 ;
}
static int F_265 ( struct V_283 * V_284 , T_7 * V_173 ,
struct V_324 * V_325 )
{
if ( * V_173 < sizeof( * V_325 ) )
return - V_247 ;
* V_173 -= sizeof( * V_325 ) ;
if ( ! F_266 ( V_325 , sizeof( * V_325 ) , & V_284 -> V_379 ) )
return - V_248 ;
return F_262 ( V_325 , * V_173 ) ;
}
static int F_267 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , void * V_80 , int V_366 ,
T_8 V_289 , unsigned char * V_31 , int V_380 , int V_381 ,
const struct V_287 * V_288 )
{
union V_34 V_373 ;
int V_382 , V_383 , V_173 , V_384 , V_385 ;
struct V_282 * V_23 = V_14 -> V_24 . V_386 ;
struct V_30 * V_30 ;
int V_91 ;
V_373 . V_36 = V_32 ;
V_2 -> V_281 = V_289 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_315 = V_14 -> V_24 . V_316 ;
V_2 -> V_317 = V_14 -> V_24 . V_318 ;
F_232 ( & V_14 -> V_24 , V_288 -> V_312 , & F_233 ( V_2 ) -> V_319 ) ;
F_233 ( V_2 ) -> V_374 = V_373 . V_36 ;
F_226 ( V_2 , V_380 ) ;
F_227 ( V_2 ) ;
V_382 = V_366 ;
if ( V_23 -> type == V_333 ) {
V_91 = F_268 ( V_2 , V_4 , F_115 ( V_289 ) , V_31 ,
NULL , V_366 ) ;
if ( F_2 ( V_91 < 0 ) )
return - V_247 ;
} else if ( V_381 ) {
int V_114 = F_163 ( int , V_381 , V_366 ) ;
F_216 ( V_2 , V_4 -> V_303 ) ;
F_229 ( V_2 , V_381 - V_4 -> V_303 ) ;
V_91 = F_269 ( V_2 , 0 , V_80 , V_114 ) ;
if ( F_2 ( V_91 ) )
return V_91 ;
if ( ! F_230 ( V_4 , V_2 -> V_80 , V_114 ) )
return - V_247 ;
if ( ! V_2 -> V_281 )
F_261 ( V_4 , V_2 ) ;
V_80 += V_114 ;
V_382 -= V_114 ;
}
V_383 = F_270 ( V_80 ) ;
V_385 = V_139 - V_383 ;
V_173 = ( ( V_382 > V_385 ) ? V_385 : V_382 ) ;
V_2 -> V_387 = V_382 ;
V_2 -> V_173 += V_382 ;
V_2 -> V_190 += V_382 ;
F_271 ( V_382 , & V_14 -> V_24 . V_197 ) ;
while ( F_21 ( V_382 ) ) {
V_384 = F_233 ( V_2 ) -> V_384 ;
if ( F_2 ( V_384 >= V_388 ) ) {
F_150 ( L_5 ,
V_388 ) ;
return - V_248 ;
}
V_30 = F_47 ( V_80 ) ;
V_80 += V_173 ;
F_52 ( V_30 ) ;
F_272 ( V_30 ) ;
F_273 ( V_2 , V_384 , V_30 , V_383 , V_173 ) ;
V_382 -= V_173 ;
V_383 = 0 ;
V_385 = V_139 ;
V_173 = ( ( V_382 > V_385 ) ? V_385 : V_382 ) ;
}
F_234 ( V_2 , 0 ) ;
return V_366 ;
}
static int F_274 ( struct V_13 * V_14 , void * V_32 ,
int V_389 , void * * V_80 )
{
union V_34 V_373 ;
int V_366 , V_390 ;
V_373 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_41 :
V_366 = V_373 . V_42 -> V_366 ;
break;
default:
V_366 = V_373 . V_39 -> V_366 ;
break;
}
if ( F_2 ( V_366 > V_389 ) ) {
F_150 ( L_6 , V_366 , V_389 ) ;
return - V_301 ;
}
if ( F_2 ( V_14 -> V_391 ) ) {
int V_392 , V_393 ;
V_392 = V_14 -> V_115 - sizeof( struct V_326 ) ;
V_393 = V_14 -> V_182 . V_70 - V_366 ;
if ( V_14 -> V_24 . V_332 == V_333 ) {
switch ( V_14 -> V_37 ) {
case V_41 :
V_390 = V_373 . V_42 -> V_369 ;
break;
default:
V_390 = V_373 . V_39 -> V_369 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_41 :
V_390 = V_373 . V_42 -> V_368 ;
break;
default:
V_390 = V_373 . V_39 -> V_368 ;
break;
}
}
if ( F_2 ( ( V_390 < V_392 ) || ( V_393 < V_390 ) ) )
return - V_247 ;
} else {
V_390 = V_14 -> V_115 - sizeof( struct V_326 ) ;
}
* V_80 = V_32 + V_390 ;
return V_366 ;
}
static int F_275 ( struct V_13 * V_14 , struct V_283 * V_284 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_324 * V_325 = NULL ;
struct V_287 V_288 ;
T_8 V_289 ;
int V_91 , V_394 = 0 ;
void * V_373 ;
F_221 ( struct V_326 * , V_285 , V_284 -> V_286 ) ;
bool V_395 = ! ( V_284 -> V_396 & V_397 ) ;
int V_366 , V_389 ;
unsigned char * V_31 ;
void * V_80 ;
int V_398 = 0 ;
int V_33 = V_169 ;
int V_380 , V_306 , V_381 = 0 ;
F_193 ( & V_14 -> V_399 ) ;
if ( F_21 ( V_285 == NULL ) ) {
V_4 = F_18 ( V_14 ) ;
V_289 = V_14 -> V_207 ;
V_31 = NULL ;
} else {
V_91 = - V_247 ;
if ( V_284 -> V_291 < sizeof( struct V_326 ) )
goto V_130;
if ( V_284 -> V_291 < ( V_285 -> V_344
+ F_276 ( struct V_326 ,
V_345 ) ) )
goto V_130;
V_289 = V_285 -> V_372 ;
V_31 = V_285 -> V_345 ;
V_4 = F_277 ( F_77 ( & V_14 -> V_24 ) , V_285 -> V_343 ) ;
}
V_288 . V_312 = V_14 -> V_24 . V_313 ;
if ( V_284 -> V_314 ) {
V_91 = F_231 ( & V_14 -> V_24 , V_284 , & V_288 ) ;
if ( F_2 ( V_91 ) )
goto V_130;
}
V_91 = - V_400 ;
if ( F_2 ( V_4 == NULL ) )
goto V_130;
V_91 = - V_297 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_298 ) ) )
goto V_401;
if ( V_14 -> V_24 . V_386 -> type == V_402 )
V_394 = V_4 -> V_303 ;
V_389 = V_14 -> V_182 . V_70
- ( V_14 -> V_115 - sizeof( struct V_326 ) ) ;
if ( ( V_389 > V_4 -> V_302 + V_394 + V_304 ) && ! V_14 -> V_361 )
V_389 = V_4 -> V_302 + V_394 + V_304 ;
do {
V_373 = F_63 ( V_14 , & V_14 -> V_182 ,
V_403 ) ;
if ( F_2 ( V_373 == NULL ) ) {
if ( V_395 && F_278 () )
F_279 () ;
continue;
}
V_2 = NULL ;
V_366 = F_274 ( V_14 , V_373 , V_389 , & V_80 ) ;
if ( V_366 < 0 )
goto V_404;
V_33 = V_403 ;
V_380 = F_224 ( V_4 ) ;
V_306 = V_4 -> V_307 ;
if ( V_14 -> V_361 ) {
V_325 = V_80 ;
V_80 += sizeof( * V_325 ) ;
V_366 -= sizeof( * V_325 ) ;
if ( V_366 < 0 ||
F_262 ( V_325 , V_366 ) ) {
V_366 = - V_247 ;
goto V_404;
}
V_381 = F_263 ( F_239 () ,
V_325 -> V_378 ) ;
}
V_381 = F_280 ( int , V_381 , V_4 -> V_303 ) ;
V_2 = F_281 ( & V_14 -> V_24 ,
V_380 + V_306 + sizeof( struct V_326 ) +
( V_381 - V_4 -> V_303 ) ,
! V_395 , & V_91 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_21 ( V_398 > 0 ) )
V_91 = V_398 ;
goto V_405;
}
V_366 = F_267 ( V_14 , V_2 , V_373 , V_4 , V_80 , V_366 , V_289 ,
V_31 , V_380 , V_381 , & V_288 ) ;
if ( F_21 ( V_366 >= 0 ) &&
V_366 > V_4 -> V_302 + V_394 &&
! V_14 -> V_361 &&
! F_207 ( V_4 , V_2 ) )
V_366 = - V_301 ;
if ( F_2 ( V_366 < 0 ) ) {
V_404:
if ( V_14 -> V_406 ) {
F_51 ( V_14 , V_373 ,
V_169 ) ;
F_130 ( & V_14 -> V_182 ) ;
F_15 ( V_2 ) ;
continue;
} else {
V_33 = V_407 ;
V_91 = V_366 ;
goto V_405;
}
}
if ( V_14 -> V_361 && F_282 ( V_2 , V_325 ,
F_239 () ) ) {
V_366 = - V_247 ;
goto V_404;
}
F_31 ( V_4 , V_2 ) ;
V_2 -> V_408 = F_259 ;
F_51 ( V_14 , V_373 , V_409 ) ;
F_131 ( & V_14 -> V_182 ) ;
V_33 = V_403 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_91 > 0 ) ) {
V_91 = F_283 ( V_91 ) ;
if ( V_91 && F_56 ( V_14 , V_373 ) ==
V_169 ) {
V_2 = NULL ;
goto V_405;
}
V_91 = 0 ;
}
F_130 ( & V_14 -> V_182 ) ;
V_398 += V_366 ;
} while ( F_21 ( ( V_373 != NULL ) ||
( V_395 && F_135 ( & V_14 -> V_182 ) ) ) );
V_91 = V_398 ;
goto V_401;
V_405:
F_51 ( V_14 , V_373 , V_33 ) ;
F_15 ( V_2 ) ;
V_401:
F_284 ( V_4 ) ;
V_130:
F_202 ( & V_14 -> V_399 ) ;
return V_91 ;
}
static struct V_1 * F_285 ( struct V_23 * V_24 , T_7 V_410 ,
T_7 V_394 , T_7 V_173 ,
T_7 V_411 , int V_412 ,
int * V_91 )
{
struct V_1 * V_2 ;
if ( V_410 + V_173 < V_139 || ! V_411 )
V_411 = V_173 ;
V_2 = F_286 ( V_24 , V_410 + V_411 , V_173 - V_411 , V_412 ,
V_91 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_226 ( V_2 , V_394 ) ;
F_229 ( V_2 , V_411 ) ;
V_2 -> V_387 = V_173 - V_411 ;
V_2 -> V_173 += V_173 - V_411 ;
return V_2 ;
}
static int F_287 ( struct V_282 * V_23 , struct V_283 * V_284 , T_7 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_221 ( struct V_326 * , V_285 , V_284 -> V_286 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_289 ;
unsigned char * V_31 ;
int V_91 , V_394 = 0 ;
struct V_287 V_288 ;
struct V_324 V_325 = { 0 } ;
int V_383 = 0 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_380 , V_306 , V_411 ;
int V_290 = 0 ;
if ( F_21 ( V_285 == NULL ) ) {
V_4 = F_18 ( V_14 ) ;
V_289 = V_14 -> V_207 ;
V_31 = NULL ;
} else {
V_91 = - V_247 ;
if ( V_284 -> V_291 < sizeof( struct V_326 ) )
goto V_130;
if ( V_284 -> V_291 < ( V_285 -> V_344 + F_276 ( struct V_326 , V_345 ) ) )
goto V_130;
V_289 = V_285 -> V_372 ;
V_31 = V_285 -> V_345 ;
V_4 = F_277 ( F_77 ( V_24 ) , V_285 -> V_343 ) ;
}
V_91 = - V_400 ;
if ( F_2 ( V_4 == NULL ) )
goto V_296;
V_91 = - V_297 ;
if ( F_2 ( ! ( V_4 -> V_46 & V_298 ) ) )
goto V_296;
V_288 . V_312 = V_24 -> V_313 ;
V_288 . V_317 = V_24 -> V_318 ;
if ( V_284 -> V_314 ) {
V_91 = F_231 ( V_24 , V_284 , & V_288 ) ;
if ( F_2 ( V_91 ) )
goto V_296;
}
if ( V_23 -> type == V_402 )
V_394 = V_4 -> V_303 ;
if ( V_14 -> V_361 ) {
V_91 = F_265 ( V_284 , & V_173 , & V_325 ) ;
if ( V_91 )
goto V_296;
}
if ( F_2 ( F_149 ( V_24 , V_299 ) ) ) {
if ( ! F_223 ( V_4 ) ) {
V_91 = - V_300 ;
goto V_296;
}
V_290 = 4 ;
}
V_91 = - V_301 ;
if ( ! V_325 . V_413 &&
( V_173 > V_4 -> V_302 + V_394 + V_304 + V_290 ) )
goto V_296;
V_91 = - V_183 ;
V_380 = F_224 ( V_4 ) ;
V_306 = V_4 -> V_307 ;
V_411 = F_263 ( F_239 () , V_325 . V_378 ) ;
V_411 = F_288 ( V_411 , F_163 ( int , V_173 , V_4 -> V_303 ) ) ;
V_2 = F_285 ( V_24 , V_380 + V_306 , V_380 , V_173 , V_411 ,
V_284 -> V_396 & V_397 , & V_91 ) ;
if ( V_2 == NULL )
goto V_296;
F_289 ( V_2 , V_394 ) ;
V_91 = - V_247 ;
if ( V_23 -> type == V_333 ) {
V_383 = F_268 ( V_2 , V_4 , F_115 ( V_289 ) , V_31 , NULL , V_173 ) ;
if ( F_2 ( V_383 < 0 ) )
goto V_311;
}
V_91 = F_290 ( V_2 , V_383 , & V_284 -> V_379 , V_173 ) ;
if ( V_91 )
goto V_311;
if ( V_23 -> type == V_402 &&
! F_230 ( V_4 , V_2 -> V_80 , V_173 ) ) {
V_91 = - V_247 ;
goto V_311;
}
F_232 ( V_24 , V_288 . V_312 , & F_233 ( V_2 ) -> V_319 ) ;
if ( ! V_325 . V_413 && ( V_173 > V_4 -> V_302 + V_394 + V_290 ) &&
! F_207 ( V_4 , V_2 ) ) {
V_91 = - V_301 ;
goto V_311;
}
V_2 -> V_281 = V_289 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_315 = V_24 -> V_316 ;
V_2 -> V_317 = V_288 . V_317 ;
F_31 ( V_4 , V_2 ) ;
if ( V_14 -> V_361 ) {
V_91 = F_282 ( V_2 , & V_325 , F_239 () ) ;
if ( V_91 )
goto V_311;
V_173 += sizeof( V_325 ) ;
}
F_234 ( V_2 , V_394 ) ;
if ( F_2 ( V_290 == 4 ) )
V_2 -> V_320 = 1 ;
V_91 = V_14 -> V_16 ( V_2 ) ;
if ( V_91 > 0 && ( V_91 = F_283 ( V_91 ) ) != 0 )
goto V_296;
F_284 ( V_4 ) ;
return V_173 ;
V_311:
F_15 ( V_2 ) ;
V_296:
if ( V_4 )
F_284 ( V_4 ) ;
V_130:
return V_91 ;
}
static int F_291 ( struct V_282 * V_23 , struct V_283 * V_284 , T_7 V_173 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
if ( V_14 -> V_182 . V_68 )
return F_275 ( V_14 , V_284 ) ;
else
return F_287 ( V_23 , V_284 , V_173 ) ;
}
static int F_292 ( struct V_282 * V_23 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 ;
struct V_205 * V_206 ;
struct V_226 * V_226 ;
union V_99 V_100 ;
if ( ! V_24 )
return 0 ;
V_226 = F_77 ( V_24 ) ;
V_14 = F_35 ( V_24 ) ;
F_193 ( & V_226 -> V_414 . V_415 ) ;
F_293 ( V_24 ) ;
F_202 ( & V_226 -> V_414 . V_415 ) ;
F_294 () ;
F_295 ( V_226 , V_24 -> V_416 , - 1 ) ;
F_296 () ;
F_45 ( & V_14 -> V_29 ) ;
F_46 ( V_24 , false ) ;
F_26 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_284 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_43 ( & V_14 -> V_29 ) ;
F_297 ( V_24 ) ;
if ( V_14 -> V_77 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_298 ( V_24 , & V_100 , 1 , 0 ) ;
}
if ( V_14 -> V_182 . V_68 ) {
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
F_298 ( V_24 , & V_100 , 1 , 1 ) ;
}
V_206 = F_203 ( V_24 ) ;
F_44 () ;
if ( V_206 ) {
F_191 ( V_206 ) ;
F_201 ( V_206 ) ;
}
F_299 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_147 ( & V_24 -> V_129 ) ;
F_140 ( V_14 ) ;
F_300 ( V_24 ) ;
F_301 ( V_24 ) ;
return 0 ;
}
static int F_302 ( struct V_23 * V_24 , const char * V_279 , int V_92 ,
T_8 V_289 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_3 * V_417 ;
T_8 V_418 ;
bool V_419 ;
struct V_3 * V_4 = NULL ;
int V_8 = 0 ;
bool V_420 = false ;
if ( V_14 -> V_26 )
return - V_247 ;
F_303 ( V_24 ) ;
F_45 ( & V_14 -> V_29 ) ;
F_19 () ;
if ( V_279 ) {
V_4 = F_222 ( F_77 ( V_24 ) , V_279 ) ;
if ( ! V_4 ) {
V_8 = - V_295 ;
goto V_296;
}
} else if ( V_92 ) {
V_4 = F_304 ( F_77 ( V_24 ) , V_92 ) ;
if ( ! V_4 ) {
V_8 = - V_295 ;
goto V_296;
}
}
if ( V_4 )
F_22 ( V_4 ) ;
V_418 = V_14 -> V_27 . type ;
V_417 = V_14 -> V_27 . V_4 ;
V_419 = V_418 != V_289 || V_417 != V_4 ;
if ( V_419 ) {
if ( V_14 -> V_25 ) {
F_23 () ;
F_39 ( V_24 , true ) ;
F_19 () ;
V_417 = V_14 -> V_27 . V_4 ;
if ( V_4 )
V_420 = ! F_304 ( F_77 ( V_24 ) ,
V_4 -> V_92 ) ;
}
V_14 -> V_207 = V_289 ;
V_14 -> V_27 . type = V_289 ;
if ( F_2 ( V_420 ) ) {
F_284 ( V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
V_14 -> V_92 = - 1 ;
F_26 ( V_14 ) ;
} else {
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_92 = V_4 ? V_4 -> V_92 : 0 ;
F_24 ( V_14 , V_4 ) ;
}
}
if ( V_417 )
F_284 ( V_417 ) ;
if ( V_289 == 0 || ! V_419 )
goto V_296;
if ( ! V_420 && ( ! V_4 || ( V_4 -> V_46 & V_298 ) ) ) {
F_34 ( V_24 ) ;
} else {
V_24 -> V_421 = V_297 ;
if ( ! F_149 ( V_24 , V_198 ) )
V_24 -> V_422 ( V_24 ) ;
}
V_296:
F_23 () ;
F_43 ( & V_14 -> V_29 ) ;
F_305 ( V_24 ) ;
return V_8 ;
}
static int F_306 ( struct V_282 * V_23 , struct V_292 * V_423 ,
int V_424 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_279 [ 15 ] ;
if ( V_424 != sizeof( struct V_292 ) )
return - V_247 ;
F_218 ( V_279 , V_423 -> V_425 , sizeof( V_279 ) ) ;
return F_302 ( V_24 , V_279 , 0 , F_35 ( V_24 ) -> V_207 ) ;
}
static int F_307 ( struct V_282 * V_23 , struct V_292 * V_423 , int V_424 )
{
struct V_326 * V_327 = (struct V_326 * ) V_423 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_424 < sizeof( struct V_326 ) )
return - V_247 ;
if ( V_327 -> V_370 != V_371 )
return - V_247 ;
return F_302 ( V_24 , NULL , V_327 -> V_343 ,
V_327 -> V_372 ? : F_35 ( V_24 ) -> V_207 ) ;
}
static int F_308 ( struct V_226 * V_226 , struct V_282 * V_23 , int V_281 ,
int V_426 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_8 V_289 = ( V_427 T_8 ) V_281 ;
int V_91 ;
if ( ! F_309 ( V_226 -> V_428 , V_429 ) )
return - V_246 ;
if ( V_23 -> type != V_333 && V_23 -> type != V_402 &&
V_23 -> type != V_430 )
return - V_431 ;
V_23 -> V_432 = V_433 ;
V_91 = - V_183 ;
V_24 = F_310 ( V_226 , V_240 , V_258 , & V_434 , V_426 ) ;
if ( V_24 == NULL )
goto V_130;
V_23 -> V_19 = & V_435 ;
if ( V_23 -> type == V_430 )
V_23 -> V_19 = & V_436 ;
F_311 ( V_23 , V_24 ) ;
V_14 = F_35 ( V_24 ) ;
V_24 -> V_239 = V_240 ;
V_14 -> V_207 = V_289 ;
V_14 -> V_16 = F_235 ;
V_91 = F_138 ( V_14 ) ;
if ( V_91 )
goto V_437;
F_26 ( V_14 ) ;
V_24 -> V_438 = F_146 ;
F_312 ( V_24 ) ;
F_199 ( & V_14 -> V_29 ) ;
F_313 ( & V_14 -> V_399 ) ;
V_14 -> V_203 = NULL ;
V_14 -> V_27 . F_71 = F_241 ;
if ( V_23 -> type == V_430 )
V_14 -> V_27 . F_71 = F_211 ;
V_14 -> V_27 . V_224 = V_24 ;
if ( V_289 ) {
V_14 -> V_27 . type = V_289 ;
F_34 ( V_24 ) ;
}
F_193 ( & V_226 -> V_414 . V_415 ) ;
F_314 ( V_24 , & V_226 -> V_414 . V_439 ) ;
F_202 ( & V_226 -> V_414 . V_415 ) ;
F_294 () ;
F_295 ( V_226 , & V_434 , 1 ) ;
F_296 () ;
return 0 ;
V_437:
F_315 ( V_24 ) ;
V_130:
return V_91 ;
}
static int F_316 ( struct V_282 * V_23 , struct V_283 * V_284 , T_7 V_173 ,
int V_46 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_440 , V_91 ;
int V_441 = 0 ;
unsigned int V_346 = 0 ;
V_91 = - V_247 ;
if ( V_46 & ~ ( V_442 | V_397 | V_443 | V_444 | V_445 ) )
goto V_130;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_46 & V_445 ) {
V_91 = F_317 ( V_24 , V_284 , V_173 ,
V_446 , V_447 ) ;
goto V_130;
}
V_2 = F_318 ( V_24 , V_46 , V_46 & V_397 , & V_91 ) ;
if ( V_2 == NULL )
goto V_130;
if ( F_35 ( V_24 ) -> V_195 )
F_145 ( F_35 ( V_24 ) , NULL ) ;
if ( F_35 ( V_24 ) -> V_361 ) {
V_91 = F_237 ( V_284 , V_2 , & V_173 ) ;
if ( V_91 )
goto V_311;
V_441 = sizeof( struct V_324 ) ;
}
V_440 = V_2 -> V_173 ;
if ( V_440 > V_173 ) {
V_440 = V_173 ;
V_284 -> V_396 |= V_443 ;
}
V_91 = F_319 ( V_2 , 0 , V_284 , V_440 ) ;
if ( V_91 )
goto V_311;
if ( V_23 -> type != V_430 ) {
struct V_326 * V_327 = & F_215 ( V_2 ) -> V_275 . V_339 ;
V_346 = F_215 ( V_2 ) -> V_275 . V_346 ;
V_327 -> V_370 = V_371 ;
V_327 -> V_372 = V_2 -> V_281 ;
}
F_320 ( V_284 , V_24 , V_2 ) ;
if ( V_284 -> V_286 ) {
if ( V_23 -> type == V_430 ) {
F_321 ( sizeof( struct V_269 ) ) ;
V_284 -> V_291 = sizeof( struct V_269 ) ;
} else {
struct V_326 * V_327 = & F_215 ( V_2 ) -> V_275 . V_339 ;
V_284 -> V_291 = V_327 -> V_344 +
F_276 ( struct V_326 , V_345 ) ;
}
memcpy ( V_284 -> V_286 , & F_215 ( V_2 ) -> V_275 ,
V_284 -> V_291 ) ;
}
if ( F_35 ( V_24 ) -> V_448 ) {
struct V_449 V_450 ;
V_450 . V_40 = V_142 ;
if ( V_2 -> V_354 == V_355 )
V_450 . V_40 |= V_356 ;
else if ( V_2 -> V_271 != V_334 &&
( V_2 -> V_354 == V_357 ||
F_255 ( V_2 ) ) )
V_450 . V_40 |= V_358 ;
V_450 . V_366 = V_346 ;
V_450 . V_367 = V_2 -> V_173 ;
V_450 . V_368 = 0 ;
V_450 . V_369 = F_243 ( V_2 ) ;
if ( F_113 ( V_2 ) ) {
V_450 . V_164 = F_114 ( V_2 ) ;
V_450 . V_165 = F_115 ( V_2 -> V_166 ) ;
V_450 . V_40 |= V_167 | V_168 ;
} else {
V_450 . V_164 = 0 ;
V_450 . V_165 = 0 ;
}
F_322 ( V_284 , V_446 , V_451 , sizeof( V_450 ) , & V_450 ) ;
}
V_91 = V_441 + ( ( V_46 & V_443 ) ? V_2 -> V_173 : V_440 ) ;
V_311:
F_323 ( V_24 , V_2 ) ;
V_130:
return V_91 ;
}
static int F_324 ( struct V_282 * V_23 , struct V_292 * V_423 ,
int * V_452 , int V_453 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_453 )
return - V_454 ;
V_423 -> V_455 = V_371 ;
memset ( V_423 -> V_425 , 0 , sizeof( V_423 -> V_425 ) ) ;
F_19 () ;
V_4 = F_304 ( F_77 ( V_24 ) , F_35 ( V_24 ) -> V_92 ) ;
if ( V_4 )
F_218 ( V_423 -> V_425 , V_4 -> V_279 , sizeof( V_423 -> V_425 ) ) ;
F_23 () ;
* V_452 = sizeof( * V_423 ) ;
return 0 ;
}
static int F_325 ( struct V_282 * V_23 , struct V_292 * V_423 ,
int * V_452 , int V_453 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
F_221 ( struct V_326 * , V_327 , V_423 ) ;
if ( V_453 )
return - V_454 ;
V_327 -> V_370 = V_371 ;
V_327 -> V_343 = V_14 -> V_92 ;
V_327 -> V_372 = V_14 -> V_207 ;
V_327 -> V_341 = 0 ;
F_19 () ;
V_4 = F_304 ( F_77 ( V_24 ) , V_14 -> V_92 ) ;
if ( V_4 ) {
V_327 -> V_340 = V_4 -> type ;
V_327 -> V_344 = V_4 -> V_424 ;
memcpy ( V_327 -> V_345 , V_4 -> V_456 , V_4 -> V_424 ) ;
} else {
V_327 -> V_340 = 0 ;
V_327 -> V_344 = 0 ;
}
F_23 () ;
* V_452 = F_276 ( struct V_326 , V_345 ) + V_327 -> V_344 ;
return 0 ;
}
static int F_326 ( struct V_3 * V_4 , struct V_457 * V_200 ,
int V_458 )
{
switch ( V_200 -> type ) {
case V_459 :
if ( V_200 -> V_460 != V_4 -> V_424 )
return - V_247 ;
if ( V_458 > 0 )
return F_327 ( V_4 , V_200 -> V_31 ) ;
else
return F_328 ( V_4 , V_200 -> V_31 ) ;
break;
case V_461 :
return F_329 ( V_4 , V_458 ) ;
case V_462 :
return F_330 ( V_4 , V_458 ) ;
case V_463 :
if ( V_200 -> V_460 != V_4 -> V_424 )
return - V_247 ;
if ( V_458 > 0 )
return F_331 ( V_4 , V_200 -> V_31 ) ;
else
return F_332 ( V_4 , V_200 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_333 ( struct V_3 * V_4 ,
struct V_457 * * V_464 )
{
struct V_457 * V_465 ;
while ( ( V_465 = * V_464 ) != NULL ) {
if ( V_465 -> V_92 == V_4 -> V_92 ) {
F_326 ( V_4 , V_465 , - 1 ) ;
* V_464 = V_465 -> V_466 ;
F_201 ( V_465 ) ;
} else
V_464 = & V_465 -> V_466 ;
}
}
static int F_334 ( struct V_23 * V_24 , struct V_467 * V_468 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_457 * V_465 , * V_200 ;
struct V_3 * V_4 ;
int V_91 ;
F_75 () ;
V_91 = - V_295 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_468 -> V_469 ) ;
if ( ! V_4 )
goto V_470;
V_91 = - V_247 ;
if ( V_468 -> V_471 > V_4 -> V_424 )
goto V_470;
V_91 = - V_183 ;
V_200 = F_335 ( sizeof( * V_200 ) , V_258 ) ;
if ( V_200 == NULL )
goto V_470;
V_91 = 0 ;
for ( V_465 = V_14 -> V_472 ; V_465 ; V_465 = V_465 -> V_466 ) {
if ( V_465 -> V_92 == V_468 -> V_469 &&
V_465 -> type == V_468 -> V_473 &&
V_465 -> V_460 == V_468 -> V_471 &&
memcmp ( V_465 -> V_31 , V_468 -> V_474 , V_465 -> V_460 ) == 0 ) {
V_465 -> V_201 ++ ;
F_201 ( V_200 ) ;
goto V_470;
}
}
V_200 -> type = V_468 -> V_473 ;
V_200 -> V_92 = V_468 -> V_469 ;
V_200 -> V_460 = V_468 -> V_471 ;
memcpy ( V_200 -> V_31 , V_468 -> V_474 , V_200 -> V_460 ) ;
memset ( V_200 -> V_31 + V_200 -> V_460 , 0 , sizeof( V_200 -> V_31 ) - V_200 -> V_460 ) ;
V_200 -> V_201 = 1 ;
V_200 -> V_466 = V_14 -> V_472 ;
V_14 -> V_472 = V_200 ;
V_91 = F_326 ( V_4 , V_200 , 1 ) ;
if ( V_91 ) {
V_14 -> V_472 = V_200 -> V_466 ;
F_201 ( V_200 ) ;
}
V_470:
F_78 () ;
return V_91 ;
}
static int F_336 ( struct V_23 * V_24 , struct V_467 * V_468 )
{
struct V_457 * V_465 , * * V_464 ;
F_75 () ;
for ( V_464 = & F_35 ( V_24 ) -> V_472 ; ( V_465 = * V_464 ) != NULL ; V_464 = & V_465 -> V_466 ) {
if ( V_465 -> V_92 == V_468 -> V_469 &&
V_465 -> type == V_468 -> V_473 &&
V_465 -> V_460 == V_468 -> V_471 &&
memcmp ( V_465 -> V_31 , V_468 -> V_474 , V_465 -> V_460 ) == 0 ) {
if ( -- V_465 -> V_201 == 0 ) {
struct V_3 * V_4 ;
* V_464 = V_465 -> V_466 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_465 -> V_92 ) ;
if ( V_4 )
F_326 ( V_4 , V_465 , - 1 ) ;
F_201 ( V_465 ) ;
}
break;
}
}
F_78 () ;
return 0 ;
}
static void F_297 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_457 * V_465 ;
if ( ! V_14 -> V_472 )
return;
F_75 () ;
while ( ( V_465 = V_14 -> V_472 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_472 = V_465 -> V_466 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_465 -> V_92 ) ;
if ( V_4 != NULL )
F_326 ( V_4 , V_465 , - 1 ) ;
F_201 ( V_465 ) ;
}
F_78 () ;
}
static int
F_337 ( struct V_282 * V_23 , int V_475 , int V_476 , char T_6 * V_477 , unsigned int V_478 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_8 ;
if ( V_475 != V_446 )
return - V_479 ;
switch ( V_476 ) {
case V_480 :
case V_481 :
{
struct V_467 V_468 ;
int V_173 = V_478 ;
memset ( & V_468 , 0 , sizeof( V_468 ) ) ;
if ( V_173 < sizeof( struct V_482 ) )
return - V_247 ;
if ( V_173 > sizeof( V_468 ) )
V_173 = sizeof( V_468 ) ;
if ( F_184 ( & V_468 , V_477 , V_173 ) )
return - V_248 ;
if ( V_173 < ( V_468 . V_471 + F_276 ( struct V_482 , V_474 ) ) )
return - V_247 ;
if ( V_476 == V_480 )
V_8 = F_334 ( V_24 , & V_468 ) ;
else
V_8 = F_336 ( V_24 , & V_468 ) ;
return V_8 ;
}
case V_483 :
case V_484 :
{
union V_99 V_100 ;
int V_173 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_173 = sizeof( V_100 . V_485 ) ;
break;
case V_43 :
default:
V_173 = sizeof( V_100 . V_102 ) ;
break;
}
if ( V_478 < V_173 )
return - V_247 ;
if ( F_184 ( & V_100 . V_485 , V_477 , V_173 ) )
return - V_248 ;
return F_298 ( V_24 , & V_100 , 0 ,
V_476 == V_484 ) ;
}
case V_486 :
{
int V_208 ;
if ( V_478 != sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
F_35 ( V_24 ) -> V_362 = V_208 ;
return 0 ;
}
case V_487 :
{
int V_208 ;
if ( V_478 != sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
switch ( V_208 ) {
case V_38 :
case V_41 :
case V_43 :
break;
default:
return - V_247 ;
}
F_303 ( V_24 ) ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 ) {
V_8 = - V_488 ;
} else {
V_14 -> V_37 = V_208 ;
V_8 = 0 ;
}
F_305 ( V_24 ) ;
return V_8 ;
}
case V_489 :
{
unsigned int V_208 ;
if ( V_478 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_488 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_359 = V_208 ;
return 0 ;
}
case V_490 :
{
unsigned int V_208 ;
if ( V_478 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_488 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_406 = ! ! V_208 ;
return 0 ;
}
case V_451 :
{
int V_208 ;
if ( V_478 < sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_448 = ! ! V_208 ;
return 0 ;
}
case V_491 :
{
int V_208 ;
if ( V_478 < sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_342 = ! ! V_208 ;
return 0 ;
}
case V_492 :
{
int V_208 ;
if ( V_23 -> type != V_402 )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_488 ;
if ( V_478 < sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_361 = ! ! V_208 ;
return 0 ;
}
case V_493 :
{
int V_208 ;
if ( V_478 != sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_55 = V_208 ;
return 0 ;
}
case V_494 :
{
int V_208 ;
if ( V_478 != sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
return F_192 ( V_24 , V_208 & 0xffff , V_208 >> 16 ) ;
}
case V_495 :
{
if ( ! V_14 -> V_26 )
return - V_247 ;
return F_190 ( V_14 , V_477 , V_478 ) ;
}
case V_496 :
{
unsigned int V_208 ;
if ( V_478 != sizeof( V_208 ) )
return - V_247 ;
if ( V_14 -> V_77 . V_68 || V_14 -> V_182 . V_68 )
return - V_488 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_391 = ! ! V_208 ;
return 0 ;
}
case V_497 :
{
int V_208 ;
if ( V_478 != sizeof( V_208 ) )
return - V_247 ;
if ( F_184 ( & V_208 , V_477 , sizeof( V_208 ) ) )
return - V_248 ;
V_14 -> V_16 = V_208 ? F_1 : F_235 ;
return 0 ;
}
default:
return - V_479 ;
}
}
static int F_338 ( struct V_282 * V_23 , int V_475 , int V_476 ,
char T_6 * V_477 , int T_6 * V_478 )
{
int V_173 ;
int V_208 , V_498 = sizeof( V_208 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
void * V_80 = & V_208 ;
union V_499 V_500 ;
struct V_501 V_502 ;
if ( V_475 != V_446 )
return - V_479 ;
if ( F_339 ( V_173 , V_478 ) )
return - V_248 ;
if ( V_173 < 0 )
return - V_247 ;
switch ( V_476 ) {
case V_503 :
F_68 ( & V_24 -> V_129 . V_78 ) ;
memcpy ( & V_500 , & V_14 -> V_118 , sizeof( V_500 ) ) ;
memset ( & V_14 -> V_118 , 0 , sizeof( V_14 -> V_118 ) ) ;
F_69 ( & V_24 -> V_129 . V_78 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_498 = sizeof( struct V_504 ) ;
V_500 . V_119 . V_348 += V_500 . V_119 . V_148 ;
V_80 = & V_500 . V_119 ;
} else {
V_498 = sizeof( struct V_505 ) ;
V_500 . V_347 . V_348 += V_500 . V_347 . V_148 ;
V_80 = & V_500 . V_347 ;
}
break;
case V_451 :
V_208 = V_14 -> V_448 ;
break;
case V_491 :
V_208 = V_14 -> V_342 ;
break;
case V_492 :
V_208 = V_14 -> V_361 ;
break;
case V_487 :
V_208 = V_14 -> V_37 ;
break;
case V_506 :
if ( V_173 > sizeof( int ) )
V_173 = sizeof( int ) ;
if ( F_184 ( & V_208 , V_477 , V_173 ) )
return - V_248 ;
switch ( V_208 ) {
case V_38 :
V_208 = sizeof( struct V_507 ) ;
break;
case V_41 :
V_208 = sizeof( struct V_508 ) ;
break;
case V_43 :
V_208 = sizeof( struct V_143 ) ;
break;
default:
return - V_247 ;
}
break;
case V_489 :
V_208 = V_14 -> V_359 ;
break;
case V_490 :
V_208 = V_14 -> V_406 ;
break;
case V_493 :
V_208 = V_14 -> V_55 ;
break;
case V_494 :
V_208 = ( V_14 -> V_26 ?
( ( T_5 ) V_14 -> V_26 -> V_251 |
( ( T_5 ) V_14 -> V_26 -> type << 16 ) |
( ( T_5 ) V_14 -> V_26 -> V_46 << 24 ) ) :
0 ) ;
break;
case V_509 :
if ( ! V_14 -> V_203 )
return - V_247 ;
V_502 . V_510 = F_340 ( & V_14 -> V_203 -> V_207 ) ;
V_502 . V_511 = F_340 ( & V_14 -> V_203 -> V_216 ) ;
V_502 . V_512 = F_340 ( & V_14 -> V_203 -> V_217 ) ;
V_80 = & V_502 ;
V_498 = sizeof( V_502 ) ;
break;
case V_496 :
V_208 = V_14 -> V_391 ;
break;
case V_497 :
V_208 = F_28 ( V_14 ) ;
break;
default:
return - V_479 ;
}
if ( V_173 > V_498 )
V_173 = V_498 ;
if ( F_341 ( V_173 , V_478 ) )
return - V_248 ;
if ( F_342 ( V_477 , V_80 , V_173 ) )
return - V_248 ;
return 0 ;
}
static int F_343 ( struct V_282 * V_23 , int V_475 , int V_476 ,
char T_6 * V_477 , unsigned int V_478 )
{
struct V_13 * V_14 = F_35 ( V_23 -> V_24 ) ;
if ( V_475 != V_446 )
return - V_479 ;
if ( V_476 == V_495 &&
V_14 -> V_26 && V_14 -> V_26 -> type == V_235 ) {
V_477 = ( char T_6 * ) F_344 ( V_477 ) ;
if ( ! V_477 )
return - V_248 ;
V_478 = sizeof( struct V_243 ) ;
}
return F_337 ( V_23 , V_475 , V_476 , V_477 , V_478 ) ;
}
static int F_345 ( struct V_513 * V_514 ,
unsigned long V_284 , void * V_515 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_346 ( V_515 ) ;
struct V_226 * V_226 = F_173 ( V_4 ) ;
F_19 () ;
F_347 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_35 ( V_24 ) ;
switch ( V_284 ) {
case V_516 :
if ( V_14 -> V_472 )
F_333 ( V_4 , & V_14 -> V_472 ) ;
case V_517 :
if ( V_4 -> V_92 == V_14 -> V_92 ) {
F_45 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_39 ( V_24 , false ) ;
V_24 -> V_421 = V_297 ;
if ( ! F_149 ( V_24 , V_198 ) )
V_24 -> V_422 ( V_24 ) ;
}
if ( V_284 == V_516 ) {
F_26 ( V_14 ) ;
V_14 -> V_92 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_284 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_43 ( & V_14 -> V_29 ) ;
}
break;
case V_518 :
if ( V_4 -> V_92 == V_14 -> V_92 ) {
F_45 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_207 )
F_34 ( V_24 ) ;
F_43 ( & V_14 -> V_29 ) ;
}
break;
}
}
F_23 () ;
return V_519 ;
}
static int F_348 ( struct V_282 * V_23 , unsigned int V_520 ,
unsigned long V_521 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_520 ) {
case V_522 :
{
int V_523 = F_349 ( V_24 ) ;
return F_341 ( V_523 , ( int T_6 * ) V_521 ) ;
}
case V_524 :
{
struct V_1 * V_2 ;
int V_523 = 0 ;
F_68 ( & V_24 -> V_129 . V_78 ) ;
V_2 = F_350 ( & V_24 -> V_129 ) ;
if ( V_2 )
V_523 = V_2 -> V_173 ;
F_69 ( & V_24 -> V_129 . V_78 ) ;
return F_341 ( V_523 , ( int T_6 * ) V_521 ) ;
}
case V_525 :
return F_351 ( V_24 , (struct V_526 T_6 * ) V_521 ) ;
case V_527 :
return F_352 ( V_24 , (struct V_44 T_6 * ) V_521 ) ;
#ifdef F_353
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
static unsigned int F_354 ( struct V_545 * V_545 , struct V_282 * V_23 ,
T_9 * V_546 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
unsigned int V_547 = F_355 ( V_545 , V_23 , V_546 ) ;
F_68 ( & V_24 -> V_129 . V_78 ) ;
if ( V_14 -> V_77 . V_68 ) {
if ( ! F_127 ( V_14 , & V_14 -> V_77 ,
V_160 ) )
V_547 |= V_548 | V_549 ;
}
if ( V_14 -> V_195 && F_144 ( V_14 , NULL ) == V_192 )
V_14 -> V_195 = 0 ;
F_69 ( & V_24 -> V_129 . V_78 ) ;
F_68 ( & V_24 -> V_550 . V_78 ) ;
if ( V_14 -> V_182 . V_68 ) {
if ( F_63 ( V_14 , & V_14 -> V_182 , V_169 ) )
V_547 |= V_551 | V_552 ;
}
F_69 ( & V_24 -> V_550 . V_78 ) ;
return V_547 ;
}
static void F_356 ( struct V_553 * V_554 )
{
struct V_545 * V_545 = V_554 -> V_555 ;
struct V_282 * V_23 = V_545 -> V_556 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_119 ( & F_35 ( V_24 ) -> V_557 ) ;
}
static void F_357 ( struct V_553 * V_554 )
{
struct V_545 * V_545 = V_554 -> V_555 ;
struct V_282 * V_23 = V_545 -> V_556 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_108 ( & F_35 ( V_24 ) -> V_557 ) ;
}
static void F_358 ( struct V_104 * V_68 , unsigned int V_558 ,
unsigned int V_173 )
{
int V_200 ;
for ( V_200 = 0 ; V_200 < V_173 ; V_200 ++ ) {
if ( F_21 ( V_68 [ V_200 ] . V_69 ) ) {
if ( F_48 ( V_68 [ V_200 ] . V_69 ) )
F_359 ( V_68 [ V_200 ] . V_69 ) ;
else
F_360 ( ( unsigned long ) V_68 [ V_200 ] . V_69 ,
V_558 ) ;
V_68 [ V_200 ] . V_69 = NULL ;
}
}
F_201 ( V_68 ) ;
}
static char * F_361 ( unsigned long V_558 )
{
char * V_69 ;
T_10 V_559 = V_258 | V_560 |
V_561 | V_562 | V_563 ;
V_69 = ( char * ) F_362 ( V_559 , V_558 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_363 ( ( 1 << V_558 ) * V_139 ) ;
if ( V_69 )
return V_69 ;
V_559 &= ~ V_563 ;
V_69 = ( char * ) F_362 ( V_559 , V_558 ) ;
if ( V_69 )
return V_69 ;
return NULL ;
}
static struct V_104 * F_364 ( struct V_564 * V_485 , int V_558 )
{
unsigned int V_565 = V_485 -> V_113 ;
struct V_104 * V_68 ;
int V_200 ;
V_68 = F_365 ( V_565 , sizeof( struct V_104 ) , V_258 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
for ( V_200 = 0 ; V_200 < V_565 ; V_200 ++ ) {
V_68 [ V_200 ] . V_69 = F_361 ( V_558 ) ;
if ( F_2 ( ! V_68 [ V_200 ] . V_69 ) )
goto V_566;
}
V_130:
return V_68 ;
V_566:
F_358 ( V_68 , V_558 , V_565 ) ;
V_68 = NULL ;
goto V_130;
}
static int F_298 ( struct V_23 * V_24 , union V_99 * V_100 ,
int V_567 , int V_182 )
{
struct V_104 * V_68 = NULL ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_568 , V_558 = 0 ;
struct V_62 * V_63 ;
struct V_75 * V_76 ;
T_8 V_207 ;
int V_91 = - V_247 ;
struct V_564 * V_485 = & V_100 -> V_485 ;
F_303 ( V_24 ) ;
if ( ! V_567 && V_182 && ( V_14 -> V_37 > V_41 ) ) {
F_366 ( L_7 ) ;
goto V_130;
}
V_63 = V_182 ? & V_14 -> V_182 : & V_14 -> V_77 ;
V_76 = V_182 ? & V_24 -> V_550 : & V_24 -> V_129 ;
V_91 = - V_488 ;
if ( ! V_567 ) {
if ( F_90 ( & V_14 -> V_557 ) )
goto V_130;
if ( F_135 ( V_63 ) )
goto V_130;
}
if ( V_485 -> V_113 ) {
V_91 = - V_488 ;
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
V_91 = - V_247 ;
if ( F_2 ( ( int ) V_485 -> V_111 <= 0 ) )
goto V_130;
if ( F_2 ( ! F_367 ( V_485 -> V_111 ) ) )
goto V_130;
if ( V_14 -> V_37 >= V_43 &&
( int ) ( V_485 -> V_111 -
F_83 ( V_100 -> V_102 . V_125 ) ) <= 0 )
goto V_130;
if ( F_2 ( V_485 -> V_572 < V_14 -> V_115 +
V_14 -> V_359 ) )
goto V_130;
if ( F_2 ( V_485 -> V_572 & ( V_573 - 1 ) ) )
goto V_130;
V_63 -> V_67 = V_485 -> V_111 / V_485 -> V_572 ;
if ( F_2 ( V_63 -> V_67 == 0 ) )
goto V_130;
if ( F_2 ( ( V_63 -> V_67 * V_485 -> V_113 ) !=
V_485 -> V_574 ) )
goto V_130;
V_91 = - V_257 ;
V_558 = F_368 ( V_485 -> V_111 ) ;
V_68 = F_364 ( V_485 , V_558 ) ;
if ( F_2 ( ! V_68 ) )
goto V_130;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( ! V_182 )
F_81 ( V_14 , V_63 , V_68 , V_100 ) ;
break;
default:
break;
}
}
else {
V_91 = - V_247 ;
if ( F_2 ( V_485 -> V_574 ) )
goto V_130;
}
F_45 ( & V_14 -> V_29 ) ;
V_568 = V_14 -> V_25 ;
V_207 = V_14 -> V_207 ;
if ( V_568 ) {
V_14 -> V_207 = 0 ;
F_39 ( V_24 , false ) ;
}
F_43 ( & V_14 -> V_29 ) ;
F_44 () ;
V_91 = - V_488 ;
F_193 ( & V_14 -> V_399 ) ;
if ( V_567 || F_90 ( & V_14 -> V_557 ) == 0 ) {
V_91 = 0 ;
F_68 ( & V_76 -> V_78 ) ;
F_369 ( V_63 -> V_68 , V_68 ) ;
V_63 -> V_177 = ( V_485 -> V_574 - 1 ) ;
V_63 -> V_71 = 0 ;
V_63 -> V_70 = V_485 -> V_572 ;
F_69 ( & V_76 -> V_78 ) ;
F_369 ( V_63 -> V_575 , V_558 ) ;
F_369 ( V_63 -> V_576 , V_485 -> V_113 ) ;
V_63 -> V_577 = V_485 -> V_111 / V_139 ;
V_14 -> V_27 . F_71 = ( V_14 -> V_77 . V_68 ) ?
V_186 : F_241 ;
F_147 ( V_76 ) ;
if ( F_90 ( & V_14 -> V_557 ) )
F_150 ( L_8 ,
F_90 ( & V_14 -> V_557 ) ) ;
}
F_202 ( & V_14 -> V_399 ) ;
F_45 ( & V_14 -> V_29 ) ;
if ( V_568 ) {
V_14 -> V_207 = V_207 ;
F_34 ( V_24 ) ;
}
F_43 ( & V_14 -> V_29 ) ;
if ( V_567 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_182 )
F_66 ( V_14 , V_76 ) ;
}
if ( V_68 )
F_358 ( V_68 , V_558 , V_485 -> V_113 ) ;
V_130:
F_305 ( V_24 ) ;
return V_91 ;
}
static int F_370 ( struct V_545 * V_545 , struct V_282 * V_23 ,
struct V_553 * V_554 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
unsigned long V_578 , V_579 ;
struct V_62 * V_63 ;
unsigned long V_137 ;
int V_91 = - V_247 ;
int V_200 ;
if ( V_554 -> V_580 )
return - V_247 ;
F_193 ( & V_14 -> V_399 ) ;
V_579 = 0 ;
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_182 ; V_63 ++ ) {
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
for ( V_63 = & V_14 -> V_77 ; V_63 <= & V_14 -> V_182 ; V_63 ++ ) {
if ( V_63 -> V_68 == NULL )
continue;
for ( V_200 = 0 ; V_200 < V_63 -> V_576 ; V_200 ++ ) {
struct V_30 * V_30 ;
void * V_583 = V_63 -> V_68 [ V_200 ] . V_69 ;
int V_584 ;
for ( V_584 = 0 ; V_584 < V_63 -> V_577 ; V_584 ++ ) {
V_30 = F_47 ( V_583 ) ;
V_91 = F_371 ( V_554 , V_137 , V_30 ) ;
if ( F_2 ( V_91 ) )
goto V_130;
V_137 += V_139 ;
V_583 += V_139 ;
}
}
}
F_119 ( & V_14 -> V_557 ) ;
V_554 -> V_585 = & V_586 ;
V_91 = 0 ;
V_130:
F_202 ( & V_14 -> V_399 ) ;
return V_91 ;
}
static void * F_372 ( struct V_587 * V_588 , T_11 * V_589 )
__acquires( T_12 )
{
struct V_226 * V_226 = F_373 ( V_588 ) ;
F_19 () ;
return F_374 ( & V_226 -> V_414 . V_439 , * V_589 ) ;
}
static void * F_375 ( struct V_587 * V_588 , void * V_590 , T_11 * V_589 )
{
struct V_226 * V_226 = F_373 ( V_588 ) ;
return F_376 ( V_590 , & V_226 -> V_414 . V_439 , V_589 ) ;
}
static void F_377 ( struct V_587 * V_588 , void * V_590 )
__releases( T_12 )
{
F_23 () ;
}
static int F_378 ( struct V_587 * V_588 , void * V_590 )
{
if ( V_590 == V_591 )
F_379 ( V_588 , L_9 ) ;
else {
struct V_23 * V_592 = F_380 ( V_590 ) ;
const struct V_13 * V_14 = F_35 ( V_592 ) ;
F_381 ( V_588 ,
L_10 ,
V_592 ,
F_90 ( & V_592 -> V_593 ) ,
V_592 -> V_332 ,
F_115 ( V_14 -> V_207 ) ,
V_14 -> V_92 ,
V_14 -> V_25 ,
F_90 ( & V_592 -> V_189 ) ,
F_382 ( F_383 ( V_588 ) , F_384 ( V_592 ) ) ,
F_385 ( V_592 ) ) ;
}
return 0 ;
}
static int F_386 ( struct V_594 * V_594 , struct V_545 * V_545 )
{
return F_387 ( V_594 , V_545 , & V_595 ,
sizeof( struct V_596 ) ) ;
}
static int T_13 F_388 ( struct V_226 * V_226 )
{
F_313 ( & V_226 -> V_414 . V_415 ) ;
F_389 ( & V_226 -> V_414 . V_439 ) ;
if ( ! F_390 ( L_11 , 0 , V_226 -> V_597 , & V_598 ) )
return - V_257 ;
return 0 ;
}
static void T_14 F_391 ( struct V_226 * V_226 )
{
F_392 ( L_11 , V_226 -> V_597 ) ;
}
static void T_15 F_393 ( void )
{
F_394 ( & V_599 ) ;
F_395 ( & V_600 ) ;
F_396 ( V_240 ) ;
F_397 ( & V_434 ) ;
}
static int T_16 F_398 ( void )
{
int V_601 = F_399 ( & V_434 , 0 ) ;
if ( V_601 != 0 )
goto V_130;
F_400 ( & V_602 ) ;
F_401 ( & V_600 ) ;
F_402 ( & V_599 ) ;
V_130:
return V_601 ;
}
