static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 ;
struct V_9 * V_10 ;
int V_11 = V_12 ;
T_2 V_13 ;
if ( F_2 ( ! F_3 ( V_4 ) ||
! F_4 ( V_4 ) ) )
goto V_14;
V_8 = F_5 ( V_2 ) ;
if ( F_6 ( V_2 , V_8 ) &&
F_7 ( V_2 ) )
goto V_14;
V_13 = F_8 ( V_2 ) ;
V_10 = F_9 ( V_4 , V_13 ) ;
F_10 () ;
F_11 ( V_4 , V_10 , F_12 () ) ;
if ( ! F_13 ( V_10 ) ) {
V_11 = V_6 -> V_15 ( V_2 , V_4 ) ;
if ( V_11 == V_16 )
F_14 ( V_10 ) ;
}
F_15 ( V_4 , V_10 ) ;
F_16 () ;
if ( ! F_17 ( V_11 ) )
F_18 ( V_2 ) ;
return V_11 ;
V_14:
F_19 ( & V_4 -> V_17 ) ;
F_18 ( V_2 ) ;
return V_18 ;
}
static struct V_3 * F_20 ( struct V_19 * V_20 )
{
struct V_3 * V_4 ;
F_21 () ;
V_4 = F_22 ( V_20 -> V_21 ) ;
if ( F_23 ( V_4 ) )
F_24 ( V_4 ) ;
F_25 () ;
return V_4 ;
}
static void F_26 ( struct V_19 * V_20 ,
struct V_3 * V_4 )
{
F_27 ( V_20 -> V_21 , V_4 ) ;
}
static void F_28 ( struct V_19 * V_20 )
{
F_29 ( V_20 -> V_21 , NULL ) ;
}
static bool F_30 ( const struct V_19 * V_20 )
{
return V_20 -> V_22 == F_1 ;
}
static T_2 F_31 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
return ( T_2 ) F_32 () % V_4 -> V_23 ;
}
static void F_33 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_24 ;
if ( V_6 -> V_25 ) {
V_24 = V_6 -> V_25 ( V_4 , V_2 , NULL ,
F_31 ) ;
V_24 = F_34 ( V_4 , V_24 ) ;
} else {
V_24 = F_31 ( V_4 , V_2 ) ;
}
F_35 ( V_2 , V_24 ) ;
}
static void F_36 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
if ( ! V_20 -> V_28 ) {
if ( V_20 -> V_29 )
F_38 ( V_27 , V_20 ) ;
else
F_39 ( & V_20 -> V_30 ) ;
F_40 ( V_27 ) ;
V_20 -> V_28 = 1 ;
}
}
static void F_41 ( struct V_26 * V_27 , bool V_31 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
V_20 -> V_28 = 0 ;
if ( V_20 -> V_29 )
F_42 ( V_27 , V_20 ) ;
else
F_43 ( & V_20 -> V_30 ) ;
F_44 ( V_27 ) ;
if ( V_31 ) {
F_45 ( & V_20 -> V_32 ) ;
F_46 () ;
F_47 ( & V_20 -> V_32 ) ;
}
}
static void F_48 ( struct V_26 * V_27 , bool V_31 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
if ( V_20 -> V_28 )
F_41 ( V_27 , V_31 ) ;
}
void F_49 ( struct V_19 * V_20 , void * V_33 , int V_34 )
{
union V_35 V_36 ;
V_36 . V_37 = V_33 ;
switch ( V_20 -> V_38 ) {
case V_39 :
V_36 . V_40 -> V_41 = V_34 ;
F_50 ( F_51 ( & V_36 . V_40 -> V_41 ) ) ;
break;
case V_42 :
V_36 . V_43 -> V_41 = V_34 ;
F_50 ( F_51 ( & V_36 . V_43 -> V_41 ) ) ;
break;
case V_44 :
default:
F_52 ( 1 , L_1 ) ;
F_53 () ;
}
F_54 () ;
}
static int F_55 ( struct V_19 * V_20 , void * V_33 )
{
union V_35 V_36 ;
F_56 () ;
V_36 . V_37 = V_33 ;
switch ( V_20 -> V_38 ) {
case V_39 :
F_50 ( F_51 ( & V_36 . V_40 -> V_41 ) ) ;
return V_36 . V_40 -> V_41 ;
case V_42 :
F_50 ( F_51 ( & V_36 . V_43 -> V_41 ) ) ;
return V_36 . V_43 -> V_41 ;
case V_44 :
default:
F_52 ( 1 , L_1 ) ;
F_53 () ;
return 0 ;
}
}
static T_3 F_57 ( struct V_1 * V_2 , struct V_45 * V_46 ,
unsigned int V_47 )
{
struct V_48 * V_49 = F_58 ( V_2 ) ;
if ( V_49 ) {
if ( ( V_47 & V_50 ) &&
F_59 ( V_49 -> V_51 , V_46 ) )
return V_52 ;
if ( ( V_47 & V_53 ) &&
F_59 ( V_49 -> V_54 , V_46 ) )
return V_55 ;
}
if ( F_59 ( V_2 -> V_56 , V_46 ) )
return V_57 ;
return 0 ;
}
static T_3 F_60 ( struct V_19 * V_20 , void * V_33 ,
struct V_1 * V_2 )
{
union V_35 V_36 ;
struct V_45 V_46 ;
T_3 V_58 ;
if ( ! ( V_58 = F_57 ( V_2 , & V_46 , V_20 -> V_59 ) ) )
return 0 ;
V_36 . V_37 = V_33 ;
switch ( V_20 -> V_38 ) {
case V_39 :
V_36 . V_40 -> V_60 = V_46 . V_61 ;
V_36 . V_40 -> V_62 = V_46 . V_63 / V_64 ;
break;
case V_42 :
V_36 . V_43 -> V_60 = V_46 . V_61 ;
V_36 . V_43 -> V_65 = V_46 . V_63 ;
break;
case V_44 :
default:
F_52 ( 1 , L_1 ) ;
F_53 () ;
}
F_50 ( F_51 ( & V_36 . V_40 -> V_60 ) ) ;
F_54 () ;
return V_58 ;
}
static void * F_61 ( struct V_19 * V_20 ,
struct V_66 * V_67 ,
unsigned int V_68 ,
int V_34 )
{
unsigned int V_69 , V_70 ;
union V_35 V_36 ;
V_69 = V_68 / V_67 -> V_71 ;
V_70 = V_68 % V_67 -> V_71 ;
V_36 . V_37 = V_67 -> V_72 [ V_69 ] . V_73 +
( V_70 * V_67 -> V_74 ) ;
if ( V_34 != F_55 ( V_20 , V_36 . V_37 ) )
return NULL ;
return V_36 . V_37 ;
}
static void * F_62 ( struct V_19 * V_20 ,
struct V_66 * V_67 ,
int V_34 )
{
return F_61 ( V_20 , V_67 , V_67 -> V_75 , V_34 ) ;
}
static void F_63 ( struct V_76 * V_77 )
{
F_64 ( & V_77 -> V_78 ) ;
}
static void F_65 ( struct V_19 * V_20 ,
int V_79 ,
struct V_80 * V_81 )
{
struct V_76 * V_77 ;
V_77 = V_79 ? F_66 ( & V_20 -> V_79 ) :
F_66 ( & V_20 -> V_82 ) ;
F_67 ( & V_81 -> V_83 ) ;
V_77 -> V_84 = 1 ;
F_68 ( & V_81 -> V_83 ) ;
F_63 ( V_77 ) ;
}
static void F_69 ( struct V_19 * V_20 ,
struct V_76 * V_77 ,
void (* F_70) ( unsigned long ) )
{
F_71 ( & V_77 -> V_78 ) ;
V_77 -> V_78 . V_85 = ( long ) V_20 ;
V_77 -> V_78 . V_86 = F_70 ;
V_77 -> V_78 . V_87 = V_88 ;
}
static void F_72 ( struct V_19 * V_20 , int V_79 )
{
struct V_76 * V_77 ;
if ( V_79 )
F_53 () ;
V_77 = V_79 ? F_66 ( & V_20 -> V_79 ) :
F_66 ( & V_20 -> V_82 ) ;
F_69 ( V_20 , V_77 , V_89 ) ;
}
static int F_73 ( struct V_19 * V_20 ,
int V_90 )
{
struct V_3 * V_4 ;
unsigned int V_91 = 0 , V_92 = 0 , div = 0 , V_93 = 0 ;
struct V_94 V_95 ;
int V_96 ;
T_4 V_97 ;
F_74 () ;
V_4 = F_75 ( F_76 ( & V_20 -> V_27 ) , V_20 -> V_98 ) ;
if ( F_2 ( ! V_4 ) ) {
F_77 () ;
return V_99 ;
}
V_96 = F_78 ( V_4 , & V_95 ) ;
V_97 = F_79 ( & V_95 ) ;
F_77 () ;
if ( ! V_96 ) {
if ( V_97 < V_100 || V_97 == V_101 ) {
return V_99 ;
} else {
V_92 = 1 ;
div = V_97 / 1000 ;
}
}
V_91 = ( V_90 * 8 ) / ( 1024 * 1024 ) ;
if ( div )
V_91 /= div ;
V_93 = V_91 * V_92 ;
if ( div )
return V_93 + 1 ;
return V_93 ;
}
static void F_80 ( struct V_76 * V_102 ,
union V_103 * V_104 )
{
V_102 -> V_105 = V_104 -> V_106 . V_107 ;
}
static void F_81 ( struct V_19 * V_20 ,
struct V_66 * V_67 ,
struct V_108 * V_72 ,
union V_103 * V_104 , int V_79 )
{
struct V_76 * V_102 = F_66 ( V_67 ) ;
struct V_109 * V_110 ;
memset ( V_102 , 0x0 , sizeof( * V_102 ) ) ;
V_102 -> V_111 = 1 ;
V_102 -> V_112 = V_72 ;
V_110 = (struct V_109 * ) V_72 [ 0 ] . V_73 ;
V_102 -> V_113 = V_72 [ 0 ] . V_73 ;
V_102 -> V_114 = V_104 -> V_106 . V_115 ;
V_102 -> V_116 = V_104 -> V_106 . V_117 ;
V_102 -> V_118 = V_20 -> V_119 ;
V_102 -> V_120 = V_20 -> V_38 ;
V_102 -> V_121 = 0 ;
V_20 -> V_122 . V_123 . V_124 = 0 ;
if ( V_104 -> V_106 . V_125 )
V_102 -> V_126 = V_104 -> V_106 . V_125 ;
else
V_102 -> V_126 = F_73 ( V_20 ,
V_104 -> V_106 . V_115 ) ;
V_102 -> V_127 = F_82 ( V_102 -> V_126 ) ;
V_102 -> V_128 = V_104 -> V_106 . V_129 ;
F_80 ( V_102 , V_104 ) ;
F_72 ( V_20 , V_79 ) ;
F_83 ( V_102 , V_110 ) ;
}
static void F_84 ( struct V_76 * V_77 )
{
F_85 ( & V_77 -> V_78 ,
V_88 + V_77 -> V_127 ) ;
V_77 -> V_121 = V_77 -> V_130 ;
}
static void V_89 ( unsigned long V_85 )
{
struct V_19 * V_20 = (struct V_19 * ) V_85 ;
struct V_76 * V_77 = F_66 ( & V_20 -> V_82 ) ;
unsigned int V_131 ;
struct V_109 * V_110 ;
F_47 ( & V_20 -> V_27 . V_132 . V_83 ) ;
V_131 = F_86 ( V_77 ) ;
V_110 = F_87 ( V_77 ) ;
if ( F_2 ( V_77 -> V_84 ) )
goto V_133;
if ( F_88 ( V_110 ) ) {
while ( F_89 ( & V_77 -> V_134 ) ) {
F_90 () ;
}
}
if ( V_77 -> V_121 == V_77 -> V_130 ) {
if ( ! V_131 ) {
F_91 ( V_77 , V_20 , V_135 ) ;
if ( ! F_92 ( V_77 , V_20 ) )
goto V_136;
else
goto V_133;
} else {
if ( F_93 ( V_77 , V_110 ) ) {
goto V_136;
} else {
F_83 ( V_77 , V_110 ) ;
goto V_133;
}
}
}
V_136:
F_84 ( V_77 ) ;
V_133:
F_45 ( & V_20 -> V_27 . V_132 . V_83 ) ;
}
static void F_94 ( struct V_76 * V_137 ,
struct V_109 * V_138 , T_3 V_34 )
{
#if V_139 == 1
T_5 * V_140 , * V_141 ;
V_140 = ( T_5 * ) V_138 ;
V_140 += V_142 ;
V_141 = ( T_5 * ) F_95 ( ( unsigned long ) V_137 -> V_143 ) ;
for (; V_140 < V_141 ; V_140 += V_142 )
F_50 ( F_51 ( V_140 ) ) ;
F_54 () ;
#endif
F_96 ( V_138 ) = V_34 ;
#if V_139 == 1
V_140 = ( T_5 * ) V_138 ;
F_50 ( F_51 ( V_140 ) ) ;
F_54 () ;
#endif
}
static void F_97 ( struct V_76 * V_137 ,
struct V_109 * V_138 ,
struct V_19 * V_20 , unsigned int V_144 )
{
T_3 V_34 = V_145 | V_144 ;
struct V_146 * V_147 ;
struct V_148 * V_40 = & V_138 -> V_149 . V_150 ;
if ( V_20 -> V_122 . V_123 . V_151 )
V_34 |= V_152 ;
V_147 = (struct V_146 * ) V_137 -> V_153 ;
V_147 -> V_154 = 0 ;
if ( F_88 ( V_138 ) ) {
V_40 -> V_155 . V_156 = V_147 -> V_60 ;
V_40 -> V_155 . V_157 = V_147 -> V_65 ;
} else {
struct V_45 V_46 ;
F_98 ( & V_46 ) ;
V_40 -> V_155 . V_156 = V_46 . V_61 ;
V_40 -> V_155 . V_157 = V_46 . V_63 ;
}
F_54 () ;
F_94 ( V_137 , V_138 , V_34 ) ;
V_137 -> V_130 = F_99 ( V_137 ) ;
}
static void F_100 ( struct V_76 * V_77 )
{
V_77 -> V_158 = 0 ;
}
static void F_83 ( struct V_76 * V_137 ,
struct V_109 * V_138 )
{
struct V_45 V_46 ;
struct V_148 * V_40 = & V_138 -> V_149 . V_150 ;
F_56 () ;
F_101 ( V_138 ) = V_137 -> V_111 ++ ;
F_88 ( V_138 ) = 0 ;
F_102 ( V_138 ) = F_103 ( V_137 -> V_128 ) ;
F_98 ( & V_46 ) ;
V_40 -> V_159 . V_156 = V_46 . V_61 ;
V_40 -> V_159 . V_157 = V_46 . V_63 ;
V_137 -> V_113 = ( char * ) V_138 ;
V_137 -> V_160 = V_137 -> V_113 + F_103 ( V_137 -> V_128 ) ;
F_104 ( V_138 ) = ( T_3 ) F_103 ( V_137 -> V_128 ) ;
F_105 ( V_138 ) = V_161 ;
V_138 -> V_120 = V_137 -> V_120 ;
V_137 -> V_153 = V_137 -> V_160 ;
V_137 -> V_143 = V_137 -> V_113 + V_137 -> V_114 ;
F_100 ( V_137 ) ;
F_84 ( V_137 ) ;
F_54 () ;
}
static void F_106 ( struct V_76 * V_77 ,
struct V_19 * V_20 )
{
V_77 -> V_158 = 1 ;
V_20 -> V_122 . V_123 . V_124 ++ ;
}
static void * F_92 ( struct V_76 * V_77 ,
struct V_19 * V_20 )
{
struct V_109 * V_110 ;
F_56 () ;
V_110 = F_87 ( V_77 ) ;
if ( V_145 & F_96 ( V_110 ) ) {
F_106 ( V_77 , V_20 ) ;
return NULL ;
}
F_83 ( V_77 , V_110 ) ;
return ( void * ) V_77 -> V_160 ;
}
static void F_91 ( struct V_76 * V_77 ,
struct V_19 * V_20 , unsigned int V_34 )
{
struct V_109 * V_110 = F_87 ( V_77 ) ;
if ( F_23 ( V_162 == F_96 ( V_110 ) ) ) {
if ( ! ( V_34 & V_135 ) ) {
while ( F_89 ( & V_77 -> V_134 ) ) {
F_90 () ;
}
}
F_97 ( V_77 , V_110 , V_20 , V_34 ) ;
return;
}
}
static int F_93 ( struct V_76 * V_77 ,
struct V_109 * V_110 )
{
return V_145 & F_96 ( V_110 ) ;
}
static int F_86 ( struct V_76 * V_77 )
{
return V_77 -> V_158 ;
}
static void F_107 ( struct V_66 * V_67 )
{
struct V_76 * V_77 = F_66 ( V_67 ) ;
F_108 ( & V_77 -> V_134 ) ;
}
static void F_109 ( struct V_76 * V_77 ,
struct V_146 * V_163 )
{
V_163 -> V_164 . V_165 = F_110 ( V_77 -> V_2 ) ;
}
static void F_111 ( struct V_76 * V_77 ,
struct V_146 * V_163 )
{
V_163 -> V_164 . V_165 = 0 ;
}
static void F_112 ( struct V_76 * V_77 ,
struct V_146 * V_163 )
{
if ( F_113 ( V_77 -> V_2 ) ) {
V_163 -> V_164 . V_166 = F_114 ( V_77 -> V_2 ) ;
V_163 -> V_164 . V_167 = F_115 ( V_77 -> V_2 -> V_168 ) ;
V_163 -> V_41 = V_169 | V_170 ;
} else {
V_163 -> V_164 . V_166 = 0 ;
V_163 -> V_164 . V_167 = 0 ;
V_163 -> V_41 = V_171 ;
}
}
static void F_116 ( struct V_76 * V_77 ,
struct V_146 * V_163 )
{
V_163 -> V_164 . V_172 = 0 ;
F_112 ( V_77 , V_163 ) ;
if ( V_77 -> V_105 & V_173 )
F_109 ( V_77 , V_163 ) ;
else
F_111 ( V_77 , V_163 ) ;
}
static void F_117 ( char * V_174 ,
struct V_76 * V_77 ,
struct V_109 * V_110 ,
unsigned int V_175 )
{
struct V_146 * V_163 ;
V_163 = (struct V_146 * ) V_174 ;
V_163 -> V_154 = F_118 ( V_175 ) ;
V_77 -> V_153 = V_174 ;
V_77 -> V_160 += F_118 ( V_175 ) ;
F_102 ( V_110 ) += F_118 ( V_175 ) ;
F_88 ( V_110 ) += 1 ;
F_119 ( & V_77 -> V_134 ) ;
F_116 ( V_77 , V_163 ) ;
}
static void * F_120 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
int V_34 ,
unsigned int V_175
)
{
struct V_76 * V_77 ;
struct V_109 * V_110 ;
char * V_174 , * V_141 ;
V_77 = F_66 ( & V_20 -> V_82 ) ;
V_110 = F_87 ( V_77 ) ;
if ( F_86 ( V_77 ) ) {
if ( F_93 ( V_77 , V_110 ) ) {
return NULL ;
} else {
F_83 ( V_77 , V_110 ) ;
}
}
F_121 () ;
V_174 = V_77 -> V_160 ;
V_77 -> V_2 = V_2 ;
V_141 = ( char * ) V_110 + V_77 -> V_114 ;
if ( V_174 + F_118 ( V_175 ) < V_141 ) {
F_117 ( V_174 , V_77 , V_110 , V_175 ) ;
return ( void * ) V_174 ;
}
F_91 ( V_77 , V_20 , 0 ) ;
V_174 = ( char * ) F_92 ( V_77 , V_20 ) ;
if ( V_174 ) {
V_110 = F_87 ( V_77 ) ;
F_117 ( V_174 , V_77 , V_110 , V_175 ) ;
return ( void * ) V_174 ;
}
return NULL ;
}
static void * F_122 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
int V_34 , unsigned int V_175 )
{
char * V_174 = NULL ;
switch ( V_20 -> V_38 ) {
case V_39 :
case V_42 :
V_174 = F_61 ( V_20 , & V_20 -> V_82 ,
V_20 -> V_82 . V_75 , V_34 ) ;
return V_174 ;
case V_44 :
return F_120 ( V_20 , V_2 , V_34 , V_175 ) ;
default:
F_52 ( 1 , L_2 ) ;
F_53 () ;
return NULL ;
}
}
static void * F_123 ( struct V_19 * V_20 ,
struct V_66 * V_67 ,
unsigned int V_176 ,
int V_34 )
{
struct V_76 * V_77 = F_66 ( V_67 ) ;
struct V_109 * V_110 = F_124 ( V_77 , V_176 ) ;
if ( V_34 != F_96 ( V_110 ) )
return NULL ;
return V_110 ;
}
static int F_125 ( struct V_66 * V_67 )
{
unsigned int V_153 ;
if ( V_67 -> V_177 . V_130 )
V_153 = V_67 -> V_177 . V_130 - 1 ;
else
V_153 = V_67 -> V_177 . V_116 - 1 ;
return V_153 ;
}
static void * F_126 ( struct V_19 * V_20 ,
struct V_66 * V_67 ,
int V_34 )
{
unsigned int V_178 = F_125 ( V_67 ) ;
return F_123 ( V_20 , V_67 , V_178 , V_34 ) ;
}
static void * F_127 ( struct V_19 * V_20 ,
struct V_66 * V_67 ,
int V_34 )
{
if ( V_20 -> V_38 <= V_42 )
return F_128 ( V_20 , V_67 , V_34 ) ;
return F_126 ( V_20 , V_67 , V_34 ) ;
}
static void F_129 ( struct V_19 * V_20 ,
struct V_66 * V_67 )
{
switch ( V_20 -> V_38 ) {
case V_39 :
case V_42 :
return F_130 ( V_67 ) ;
case V_44 :
default:
F_52 ( 1 , L_1 ) ;
F_53 () ;
return;
}
}
static void * F_128 ( struct V_19 * V_20 ,
struct V_66 * V_67 ,
int V_34 )
{
unsigned int V_178 = V_67 -> V_75 ? V_67 -> V_75 - 1 : V_67 -> V_179 ;
return F_61 ( V_20 , V_67 , V_178 , V_34 ) ;
}
static void F_130 ( struct V_66 * V_180 )
{
V_180 -> V_75 = V_180 -> V_75 != V_180 -> V_179 ? V_180 -> V_75 + 1 : 0 ;
}
static void F_131 ( struct V_66 * V_67 )
{
F_132 ( * V_67 -> V_181 ) ;
}
static void F_133 ( struct V_66 * V_67 )
{
F_134 ( * V_67 -> V_181 ) ;
}
static unsigned int F_135 ( const struct V_66 * V_67 )
{
unsigned int V_182 = 0 ;
int V_183 ;
if ( V_67 -> V_181 == NULL )
return 0 ;
F_136 (cpu)
V_182 += * F_137 ( V_67 -> V_181 , V_183 ) ;
return V_182 ;
}
static int F_138 ( struct V_19 * V_20 )
{
V_20 -> V_82 . V_181 = NULL ;
V_20 -> V_79 . V_181 = F_139 (unsigned int) ;
if ( F_2 ( V_20 -> V_79 . V_181 == NULL ) )
return - V_184 ;
return 0 ;
}
static void F_140 ( struct V_19 * V_20 )
{
F_141 ( V_20 -> V_79 . V_181 ) ;
}
static bool F_142 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_20 -> V_27 ;
bool V_185 ;
if ( V_20 -> V_30 . F_70 != V_186 )
return ( F_89 ( & V_27 -> V_187 ) + V_2 -> V_188 )
<= V_27 -> V_189 ;
F_47 ( & V_27 -> V_132 . V_83 ) ;
if ( V_20 -> V_38 == V_44 )
V_185 = F_123 ( V_20 , & V_20 -> V_82 ,
V_20 -> V_82 . V_177 . V_130 ,
V_162 ) ;
else
V_185 = F_61 ( V_20 , & V_20 -> V_82 ,
V_20 -> V_82 . V_75 ,
V_162 ) ;
F_45 ( & V_27 -> V_132 . V_83 ) ;
return V_185 ;
}
static void F_143 ( struct V_26 * V_27 )
{
F_144 ( & V_27 -> V_190 ) ;
F_145 ( F_89 ( & V_27 -> V_187 ) ) ;
F_145 ( F_89 ( & V_27 -> V_191 ) ) ;
if ( ! F_146 ( V_27 , V_192 ) ) {
F_147 ( L_3 , V_27 ) ;
return;
}
F_148 ( V_27 ) ;
}
static int F_149 ( struct V_193 * V_194 , unsigned int V_195 )
{
int V_196 = F_89 ( & V_194 -> V_197 ) + 1 ;
if ( V_196 >= V_195 )
V_196 = 0 ;
return V_196 ;
}
static unsigned int F_150 ( struct V_193 * V_194 ,
struct V_1 * V_2 ,
unsigned int V_195 )
{
return F_151 ( F_110 ( V_2 ) , V_195 ) ;
}
static unsigned int F_152 ( struct V_193 * V_194 ,
struct V_1 * V_2 ,
unsigned int V_195 )
{
int V_198 , V_199 ;
V_198 = F_89 ( & V_194 -> V_197 ) ;
while ( ( V_199 = F_153 ( & V_194 -> V_197 , V_198 ,
F_149 ( V_194 , V_195 ) ) ) != V_198 )
V_198 = V_199 ;
return V_198 ;
}
static unsigned int F_154 ( struct V_193 * V_194 ,
struct V_1 * V_2 ,
unsigned int V_195 )
{
return F_12 () % V_195 ;
}
static unsigned int F_155 ( struct V_193 * V_194 ,
struct V_1 * V_2 ,
unsigned int V_195 )
{
return F_156 ( V_195 ) ;
}
static unsigned int F_157 ( struct V_193 * V_194 ,
struct V_1 * V_2 ,
unsigned int V_176 , unsigned int V_200 ,
unsigned int V_195 )
{
unsigned int V_201 , V_202 ;
V_201 = V_202 = F_158 ( int , V_194 -> V_203 [ V_176 ] , V_195 - 1 ) ;
do {
if ( V_201 != V_200 && F_142 ( F_37 ( V_194 -> V_204 [ V_201 ] ) , V_2 ) ) {
if ( V_201 != V_202 )
V_194 -> V_203 [ V_176 ] = V_201 ;
return V_201 ;
}
if ( ++ V_201 == V_195 )
V_201 = 0 ;
} while ( V_201 != V_202 );
return V_176 ;
}
static unsigned int F_159 ( struct V_193 * V_194 ,
struct V_1 * V_2 ,
unsigned int V_195 )
{
return F_8 ( V_2 ) % V_195 ;
}
static bool F_160 ( struct V_193 * V_194 , T_2 V_205 )
{
return V_194 -> V_47 & ( V_205 >> 8 ) ;
}
static int F_161 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_206 * V_207 , struct V_3 * V_208 )
{
struct V_193 * V_194 = V_207 -> V_209 ;
unsigned int V_195 = V_194 -> V_210 ;
struct V_19 * V_20 ;
unsigned int V_176 ;
if ( ! F_162 ( F_163 ( V_4 ) , F_164 ( & V_194 -> V_211 ) ) ||
! V_195 ) {
F_18 ( V_2 ) ;
return 0 ;
}
switch ( V_194 -> type ) {
case V_212 :
default:
if ( F_160 ( V_194 , V_213 ) ) {
V_2 = F_165 ( V_2 , V_214 ) ;
if ( ! V_2 )
return 0 ;
}
V_176 = F_150 ( V_194 , V_2 , V_195 ) ;
break;
case V_215 :
V_176 = F_152 ( V_194 , V_2 , V_195 ) ;
break;
case V_216 :
V_176 = F_154 ( V_194 , V_2 , V_195 ) ;
break;
case V_217 :
V_176 = F_155 ( V_194 , V_2 , V_195 ) ;
break;
case V_218 :
V_176 = F_159 ( V_194 , V_2 , V_195 ) ;
break;
case V_219 :
V_176 = F_157 ( V_194 , V_2 , 0 , ( unsigned int ) - 1 , V_195 ) ;
break;
}
V_20 = F_37 ( V_194 -> V_204 [ V_176 ] ) ;
if ( F_160 ( V_194 , V_220 ) &&
F_2 ( ! F_142 ( V_20 , V_2 ) ) ) {
V_176 = F_157 ( V_194 , V_2 , V_176 , V_176 , V_195 ) ;
V_20 = F_37 ( V_194 -> V_204 [ V_176 ] ) ;
}
return V_20 -> V_30 . F_70 ( V_2 , V_4 , & V_20 -> V_30 , V_208 ) ;
}
static void F_38 ( struct V_26 * V_27 , struct V_19 * V_20 )
{
struct V_193 * V_194 = V_20 -> V_29 ;
F_47 ( & V_194 -> V_83 ) ;
V_194 -> V_204 [ V_194 -> V_210 ] = V_27 ;
F_54 () ;
V_194 -> V_210 ++ ;
F_45 ( & V_194 -> V_83 ) ;
}
static void F_42 ( struct V_26 * V_27 , struct V_19 * V_20 )
{
struct V_193 * V_194 = V_20 -> V_29 ;
int V_201 ;
F_47 ( & V_194 -> V_83 ) ;
for ( V_201 = 0 ; V_201 < V_194 -> V_210 ; V_201 ++ ) {
if ( V_194 -> V_204 [ V_201 ] == V_27 )
break;
}
F_166 ( V_201 >= V_194 -> V_210 ) ;
V_194 -> V_204 [ V_201 ] = V_194 -> V_204 [ V_194 -> V_210 - 1 ] ;
V_194 -> V_210 -- ;
F_45 ( & V_194 -> V_83 ) ;
}
static bool F_167 ( struct V_206 * V_221 , struct V_26 * V_27 )
{
if ( V_221 -> V_209 == ( void * ) ( (struct V_19 * ) V_27 ) -> V_29 )
return true ;
return false ;
}
static int F_168 ( struct V_26 * V_27 , T_2 V_222 , T_2 V_223 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
struct V_193 * V_194 , * V_224 ;
T_5 type = V_223 & 0xff ;
T_5 V_47 = V_223 >> 8 ;
int V_96 ;
switch ( type ) {
case V_219 :
if ( V_223 & V_220 )
return - V_225 ;
case V_212 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
break;
default:
return - V_225 ;
}
if ( ! V_20 -> V_28 )
return - V_225 ;
if ( V_20 -> V_29 )
return - V_226 ;
F_169 ( & V_227 ) ;
V_224 = NULL ;
F_170 (f, &fanout_list, list) {
if ( V_194 -> V_222 == V_222 &&
F_164 ( & V_194 -> V_211 ) == F_76 ( V_27 ) ) {
V_224 = V_194 ;
break;
}
}
V_96 = - V_225 ;
if ( V_224 && V_224 -> V_47 != V_47 )
goto V_133;
if ( ! V_224 ) {
V_96 = - V_228 ;
V_224 = F_171 ( sizeof( * V_224 ) , V_229 ) ;
if ( ! V_224 )
goto V_133;
F_172 ( & V_224 -> V_211 , F_76 ( V_27 ) ) ;
V_224 -> V_222 = V_222 ;
V_224 -> type = type ;
V_224 -> V_47 = V_47 ;
F_173 ( & V_224 -> V_197 , 0 ) ;
F_174 ( & V_224 -> V_230 ) ;
F_175 ( & V_224 -> V_83 ) ;
F_173 ( & V_224 -> V_231 , 0 ) ;
V_224 -> V_30 . type = V_20 -> V_30 . type ;
V_224 -> V_30 . V_4 = V_20 -> V_30 . V_4 ;
V_224 -> V_30 . F_70 = F_161 ;
V_224 -> V_30 . V_209 = V_224 ;
V_224 -> V_30 . V_232 = F_167 ;
F_39 ( & V_224 -> V_30 ) ;
F_176 ( & V_224 -> V_230 , & V_233 ) ;
}
V_96 = - V_225 ;
if ( V_224 -> type == type &&
V_224 -> V_30 . type == V_20 -> V_30 . type &&
V_224 -> V_30 . V_4 == V_20 -> V_30 . V_4 ) {
V_96 = - V_234 ;
if ( F_89 ( & V_224 -> V_231 ) < V_235 ) {
F_43 ( & V_20 -> V_30 ) ;
V_20 -> V_29 = V_224 ;
F_119 ( & V_224 -> V_231 ) ;
F_38 ( V_27 , V_20 ) ;
V_96 = 0 ;
}
}
V_133:
F_177 ( & V_227 ) ;
return V_96 ;
}
static void F_178 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
struct V_193 * V_194 ;
V_194 = V_20 -> V_29 ;
if ( ! V_194 )
return;
F_169 ( & V_227 ) ;
V_20 -> V_29 = NULL ;
if ( F_179 ( & V_194 -> V_231 ) ) {
F_180 ( & V_194 -> V_230 ) ;
F_181 ( & V_194 -> V_30 ) ;
F_182 ( V_194 ) ;
}
F_177 ( & V_227 ) ;
}
static int F_183 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_206 * V_207 , struct V_3 * V_208 )
{
struct V_26 * V_27 ;
struct V_236 * V_237 ;
V_27 = V_207 -> V_209 ;
if ( V_2 -> V_238 == V_239 )
goto V_133;
if ( ! F_162 ( F_163 ( V_4 ) , F_76 ( V_27 ) ) )
goto V_133;
V_2 = F_184 ( V_2 , V_240 ) ;
if ( V_2 == NULL )
goto V_241;
F_185 ( V_2 ) ;
F_186 ( V_2 ) ;
V_237 = & F_187 ( V_2 ) -> V_242 . V_243 ;
F_188 ( V_2 , V_2 -> V_85 - F_189 ( V_2 ) ) ;
V_237 -> V_244 = V_4 -> type ;
F_190 ( V_237 -> V_245 , V_4 -> V_246 , sizeof( V_237 -> V_245 ) ) ;
V_237 -> V_247 = V_2 -> V_248 ;
if ( F_191 ( V_27 , V_2 ) == 0 )
return 0 ;
V_133:
F_18 ( V_2 ) ;
V_241:
return 0 ;
}
static int F_192 ( struct V_249 * V_250 , struct V_251 * V_26 ,
struct V_252 * V_253 , T_6 V_175 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
F_193 ( struct V_236 * , V_254 , V_253 -> V_255 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
T_7 V_256 = 0 ;
int V_96 ;
int V_257 = 0 ;
if ( V_254 ) {
if ( V_253 -> V_258 < sizeof( struct V_259 ) )
return - V_225 ;
if ( V_253 -> V_258 == sizeof( struct V_236 ) )
V_256 = V_254 -> V_247 ;
} else
return - V_260 ;
V_254 -> V_245 [ sizeof( V_254 -> V_245 ) - 1 ] = 0 ;
V_261:
F_21 () ;
V_4 = F_194 ( F_76 ( V_27 ) , V_254 -> V_245 ) ;
V_96 = - V_262 ;
if ( V_4 == NULL )
goto V_263;
V_96 = - V_264 ;
if ( ! ( V_4 -> V_47 & V_265 ) )
goto V_263;
if ( F_2 ( F_146 ( V_27 , V_266 ) ) ) {
if ( ! F_195 ( V_4 ) ) {
V_96 = - V_267 ;
goto V_263;
}
V_257 = 4 ;
}
V_96 = - V_268 ;
if ( V_175 > V_4 -> V_269 + V_4 -> V_270 + V_271 + V_257 )
goto V_263;
if ( ! V_2 ) {
T_6 V_272 = F_196 ( V_4 ) ;
int V_273 = V_4 -> V_274 ;
unsigned int V_275 = V_4 -> V_276 ? V_4 -> V_270 : 0 ;
F_25 () ;
V_2 = F_197 ( V_27 , V_175 + V_272 + V_273 , 0 , V_229 ) ;
if ( V_2 == NULL )
return - V_184 ;
F_198 ( V_2 , V_272 ) ;
F_199 ( V_2 ) ;
if ( V_275 ) {
V_2 -> V_85 -= V_275 ;
V_2 -> V_277 -= V_275 ;
if ( V_175 < V_275 )
F_199 ( V_2 ) ;
}
V_96 = F_200 ( F_201 ( V_2 , V_175 ) , V_253 -> V_278 , V_175 ) ;
if ( V_96 )
goto V_279;
goto V_261;
}
if ( V_175 > ( V_4 -> V_269 + V_4 -> V_270 + V_257 ) ) {
struct V_280 * V_281 ;
F_202 ( V_2 ) ;
V_281 = F_203 ( V_2 ) ;
if ( V_281 -> V_282 != F_204 ( V_283 ) ) {
V_96 = - V_268 ;
goto V_263;
}
}
V_2 -> V_248 = V_256 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_284 = V_27 -> V_285 ;
V_2 -> V_286 = V_27 -> V_287 ;
F_205 ( V_27 , & F_206 ( V_2 ) -> V_288 ) ;
if ( F_2 ( V_257 == 4 ) )
V_2 -> V_289 = 1 ;
F_207 ( V_2 , 0 ) ;
F_208 ( V_2 ) ;
F_25 () ;
return V_175 ;
V_263:
F_25 () ;
V_279:
F_18 ( V_2 ) ;
return V_96 ;
}
static unsigned int F_209 ( const struct V_1 * V_2 ,
const struct V_26 * V_27 ,
unsigned int V_290 )
{
struct V_291 * V_292 ;
F_21 () ;
V_292 = F_22 ( V_27 -> V_291 ) ;
if ( V_292 != NULL )
V_290 = F_210 ( V_292 , V_2 ) ;
F_25 () ;
return V_290 ;
}
static int F_211 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_206 * V_207 , struct V_3 * V_208 )
{
struct V_26 * V_27 ;
struct V_293 * V_294 ;
struct V_19 * V_20 ;
T_5 * V_295 = V_2 -> V_85 ;
int V_296 = V_2 -> V_175 ;
unsigned int V_297 , V_290 ;
if ( V_2 -> V_238 == V_239 )
goto V_14;
V_27 = V_207 -> V_209 ;
V_20 = F_37 ( V_27 ) ;
if ( ! F_162 ( F_163 ( V_4 ) , F_76 ( V_27 ) ) )
goto V_14;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_276 ) {
if ( V_27 -> V_298 != V_299 )
F_188 ( V_2 , V_2 -> V_85 - F_189 ( V_2 ) ) ;
else if ( V_2 -> V_238 == V_300 ) {
F_212 ( V_2 , F_213 ( V_2 ) ) ;
}
}
V_297 = V_2 -> V_175 ;
V_290 = F_209 ( V_2 , V_27 , V_297 ) ;
if ( ! V_290 )
goto V_301;
if ( V_297 > V_290 )
V_297 = V_290 ;
if ( F_89 ( & V_27 -> V_187 ) >= V_27 -> V_189 )
goto V_302;
if ( F_214 ( V_2 ) ) {
struct V_1 * V_303 = F_215 ( V_2 , V_240 ) ;
if ( V_303 == NULL )
goto V_302;
if ( V_295 != V_2 -> V_85 ) {
V_2 -> V_85 = V_295 ;
V_2 -> V_175 = V_296 ;
}
F_216 ( V_2 ) ;
V_2 = V_303 ;
}
F_217 ( sizeof( * F_187 ( V_2 ) ) + V_304 - 8 >
sizeof( V_2 -> V_305 ) ) ;
V_294 = & F_187 ( V_2 ) -> V_242 . V_306 ;
V_294 -> V_307 = V_308 ;
V_294 -> V_309 = V_4 -> type ;
V_294 -> V_310 = V_2 -> V_248 ;
V_294 -> V_311 = V_2 -> V_238 ;
if ( F_2 ( V_20 -> V_312 ) )
V_294 -> V_313 = V_208 -> V_98 ;
else
V_294 -> V_313 = V_4 -> V_98 ;
V_294 -> V_314 = F_218 ( V_2 , V_294 -> V_315 ) ;
F_187 ( V_2 ) -> V_316 = V_2 -> V_175 ;
if ( F_219 ( V_2 , V_297 ) )
goto V_302;
F_220 ( V_2 , V_27 ) ;
V_2 -> V_4 = NULL ;
F_185 ( V_2 ) ;
F_186 ( V_2 ) ;
F_47 ( & V_27 -> V_132 . V_83 ) ;
V_20 -> V_122 . V_317 . V_318 ++ ;
V_2 -> V_319 = F_89 ( & V_27 -> V_320 ) ;
F_221 ( & V_27 -> V_132 , V_2 ) ;
F_45 ( & V_27 -> V_132 . V_83 ) ;
V_27 -> V_321 ( V_27 ) ;
return 0 ;
V_302:
F_47 ( & V_27 -> V_132 . V_83 ) ;
V_20 -> V_122 . V_317 . V_151 ++ ;
F_119 ( & V_27 -> V_320 ) ;
F_45 ( & V_27 -> V_132 . V_83 ) ;
V_301:
if ( V_295 != V_2 -> V_85 && F_214 ( V_2 ) ) {
V_2 -> V_85 = V_295 ;
V_2 -> V_175 = V_296 ;
}
V_14:
F_216 ( V_2 ) ;
return 0 ;
}
static int V_186 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_206 * V_207 , struct V_3 * V_208 )
{
struct V_26 * V_27 ;
struct V_19 * V_20 ;
struct V_293 * V_294 ;
union V_35 V_36 ;
T_5 * V_295 = V_2 -> V_85 ;
int V_296 = V_2 -> V_175 ;
unsigned int V_297 , V_290 ;
unsigned long V_34 = V_145 ;
unsigned short V_322 , V_323 , V_118 ;
struct V_1 * V_324 = NULL ;
struct V_45 V_46 ;
T_3 V_58 ;
F_217 ( F_222 ( sizeof( * V_36 . V_43 ) ) != 32 ) ;
F_217 ( F_222 ( sizeof( * V_36 . V_325 ) ) != 48 ) ;
if ( V_2 -> V_238 == V_239 )
goto V_14;
V_27 = V_207 -> V_209 ;
V_20 = F_37 ( V_27 ) ;
if ( ! F_162 ( F_163 ( V_4 ) , F_76 ( V_27 ) ) )
goto V_14;
if ( V_4 -> V_276 ) {
if ( V_27 -> V_298 != V_299 )
F_188 ( V_2 , V_2 -> V_85 - F_189 ( V_2 ) ) ;
else if ( V_2 -> V_238 == V_300 ) {
F_212 ( V_2 , F_213 ( V_2 ) ) ;
}
}
if ( V_2 -> V_326 == V_327 )
V_34 |= V_328 ;
V_297 = V_2 -> V_175 ;
V_290 = F_209 ( V_2 , V_27 , V_297 ) ;
if ( ! V_290 )
goto V_301;
if ( V_297 > V_290 )
V_297 = V_290 ;
if ( V_27 -> V_298 == V_299 ) {
V_322 = V_323 = F_222 ( V_20 -> V_119 ) + 16 +
V_20 -> V_329 ;
} else {
unsigned int V_330 = F_213 ( V_2 ) ;
V_323 = F_222 ( V_20 -> V_119 +
( V_330 < 16 ? 16 : V_330 ) ) +
V_20 -> V_329 ;
V_322 = V_323 - V_330 ;
}
if ( V_20 -> V_38 <= V_42 ) {
if ( V_322 + V_297 > V_20 -> V_82 . V_74 ) {
if ( V_20 -> V_331 &&
F_89 ( & V_27 -> V_187 ) < V_27 -> V_189 ) {
if ( F_214 ( V_2 ) ) {
V_324 = F_215 ( V_2 , V_240 ) ;
} else {
V_324 = F_223 ( V_2 ) ;
V_295 = V_2 -> V_85 ;
}
if ( V_324 )
F_220 ( V_324 , V_27 ) ;
}
V_297 = V_20 -> V_82 . V_74 - V_322 ;
if ( ( int ) V_297 < 0 )
V_297 = 0 ;
}
}
F_47 ( & V_27 -> V_132 . V_83 ) ;
V_36 . V_37 = F_122 ( V_20 , V_2 ,
V_162 , ( V_322 + V_297 ) ) ;
if ( ! V_36 . V_37 )
goto V_332;
if ( V_20 -> V_38 <= V_42 ) {
F_129 ( V_20 , & V_20 -> V_82 ) ;
if ( V_20 -> V_122 . V_317 . V_151 )
V_34 |= V_152 ;
}
V_20 -> V_122 . V_317 . V_318 ++ ;
if ( V_324 ) {
V_34 |= V_333 ;
F_221 ( & V_27 -> V_132 , V_324 ) ;
}
F_45 ( & V_27 -> V_132 . V_83 ) ;
F_224 ( V_2 , 0 , V_36 . V_37 + V_322 , V_297 ) ;
if ( ! ( V_58 = F_57 ( V_2 , & V_46 , V_20 -> V_59 ) ) )
F_98 ( & V_46 ) ;
V_34 |= V_58 ;
switch ( V_20 -> V_38 ) {
case V_39 :
V_36 . V_40 -> V_334 = V_2 -> V_175 ;
V_36 . V_40 -> V_335 = V_297 ;
V_36 . V_40 -> V_336 = V_322 ;
V_36 . V_40 -> V_337 = V_323 ;
V_36 . V_40 -> V_60 = V_46 . V_61 ;
V_36 . V_40 -> V_62 = V_46 . V_63 / V_64 ;
V_118 = sizeof( * V_36 . V_40 ) ;
break;
case V_42 :
V_36 . V_43 -> V_334 = V_2 -> V_175 ;
V_36 . V_43 -> V_335 = V_297 ;
V_36 . V_43 -> V_336 = V_322 ;
V_36 . V_43 -> V_337 = V_323 ;
V_36 . V_43 -> V_60 = V_46 . V_61 ;
V_36 . V_43 -> V_65 = V_46 . V_63 ;
if ( F_113 ( V_2 ) ) {
V_36 . V_43 -> V_166 = F_114 ( V_2 ) ;
V_36 . V_43 -> V_167 = F_115 ( V_2 -> V_168 ) ;
V_34 |= V_169 | V_170 ;
} else {
V_36 . V_43 -> V_166 = 0 ;
V_36 . V_43 -> V_167 = 0 ;
}
memset ( V_36 . V_43 -> V_172 , 0 , sizeof( V_36 . V_43 -> V_172 ) ) ;
V_118 = sizeof( * V_36 . V_43 ) ;
break;
case V_44 :
V_36 . V_325 -> V_41 |= V_34 ;
V_36 . V_325 -> V_334 = V_2 -> V_175 ;
V_36 . V_325 -> V_335 = V_297 ;
V_36 . V_325 -> V_336 = V_322 ;
V_36 . V_325 -> V_337 = V_323 ;
V_36 . V_325 -> V_60 = V_46 . V_61 ;
V_36 . V_325 -> V_65 = V_46 . V_63 ;
memset ( V_36 . V_325 -> V_172 , 0 , sizeof( V_36 . V_325 -> V_172 ) ) ;
V_118 = sizeof( * V_36 . V_325 ) ;
break;
default:
F_53 () ;
}
V_294 = V_36 . V_37 + F_222 ( V_118 ) ;
V_294 -> V_314 = F_218 ( V_2 , V_294 -> V_315 ) ;
V_294 -> V_307 = V_308 ;
V_294 -> V_309 = V_4 -> type ;
V_294 -> V_310 = V_2 -> V_248 ;
V_294 -> V_311 = V_2 -> V_238 ;
if ( F_2 ( V_20 -> V_312 ) )
V_294 -> V_313 = V_208 -> V_98 ;
else
V_294 -> V_313 = V_4 -> V_98 ;
F_121 () ;
#if V_139 == 1
if ( V_20 -> V_38 <= V_42 ) {
T_5 * V_140 , * V_141 ;
V_141 = ( T_5 * ) F_95 ( ( unsigned long ) V_36 . V_37 +
V_322 + V_297 ) ;
for ( V_140 = V_36 . V_37 ; V_140 < V_141 ; V_140 += V_142 )
F_50 ( F_51 ( V_140 ) ) ;
}
F_54 () ;
#endif
if ( V_20 -> V_38 <= V_42 )
F_49 ( V_20 , V_36 . V_37 , V_34 ) ;
else
F_107 ( & V_20 -> V_82 ) ;
V_27 -> V_321 ( V_27 ) ;
V_301:
if ( V_295 != V_2 -> V_85 && F_214 ( V_2 ) ) {
V_2 -> V_85 = V_295 ;
V_2 -> V_175 = V_296 ;
}
V_14:
F_18 ( V_2 ) ;
return 0 ;
V_332:
V_20 -> V_122 . V_317 . V_151 ++ ;
F_45 ( & V_27 -> V_132 . V_83 ) ;
V_27 -> V_321 ( V_27 ) ;
F_18 ( V_324 ) ;
goto V_301;
}
static void F_225 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_37 ( V_2 -> V_27 ) ;
if ( F_23 ( V_20 -> V_79 . V_72 ) ) {
void * V_338 ;
T_3 V_46 ;
V_338 = F_206 ( V_2 ) -> V_339 ;
F_133 ( & V_20 -> V_79 ) ;
V_46 = F_60 ( V_20 , V_338 , V_2 ) ;
F_49 ( V_20 , V_338 , V_171 | V_46 ) ;
}
F_226 ( V_2 ) ;
}
static int F_227 ( struct V_19 * V_20 , struct V_1 * V_2 ,
void * V_33 , struct V_3 * V_4 , int V_340 ,
T_7 V_256 , unsigned char * V_341 , int V_342 )
{
union V_35 V_338 ;
int V_343 , V_344 , V_175 , V_334 , V_345 , V_346 ;
struct V_251 * V_26 = V_20 -> V_27 . V_347 ;
struct V_348 * V_348 ;
void * V_85 ;
int V_96 ;
V_338 . V_37 = V_33 ;
V_2 -> V_248 = V_256 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_284 = V_20 -> V_27 . V_285 ;
V_2 -> V_286 = V_20 -> V_27 . V_287 ;
F_205 ( & V_20 -> V_27 , & F_206 ( V_2 ) -> V_288 ) ;
F_206 ( V_2 ) -> V_339 = V_338 . V_37 ;
switch ( V_20 -> V_38 ) {
case V_42 :
V_334 = V_338 . V_43 -> V_334 ;
break;
default:
V_334 = V_338 . V_40 -> V_334 ;
break;
}
if ( F_2 ( V_334 > V_340 ) ) {
F_147 ( L_4 , V_334 , V_340 ) ;
return - V_268 ;
}
F_198 ( V_2 , V_342 ) ;
F_199 ( V_2 ) ;
if ( ! F_30 ( V_20 ) )
F_207 ( V_2 , 0 ) ;
if ( F_2 ( V_20 -> V_349 ) ) {
int V_350 , V_351 , V_352 ;
V_350 = V_20 -> V_119 - sizeof( struct V_293 ) ;
V_351 = V_20 -> V_79 . V_74 - V_334 ;
if ( V_26 -> type == V_299 ) {
switch ( V_20 -> V_38 ) {
case V_42 :
V_352 = V_338 . V_43 -> V_337 ;
break;
default:
V_352 = V_338 . V_40 -> V_337 ;
break;
}
} else {
switch ( V_20 -> V_38 ) {
case V_42 :
V_352 = V_338 . V_43 -> V_336 ;
break;
default:
V_352 = V_338 . V_40 -> V_336 ;
break;
}
}
if ( F_2 ( ( V_352 < V_350 ) || ( V_351 < V_352 ) ) )
return - V_225 ;
V_85 = V_338 . V_37 + V_352 ;
} else {
V_85 = V_338 . V_37 + V_20 -> V_119 - sizeof( struct V_293 ) ;
}
V_343 = V_334 ;
if ( V_26 -> type == V_299 ) {
V_96 = F_228 ( V_2 , V_4 , F_115 ( V_256 ) , V_341 ,
NULL , V_334 ) ;
if ( F_2 ( V_96 < 0 ) )
return - V_225 ;
} else if ( V_4 -> V_270 ) {
if ( F_2 ( V_334 <= V_4 -> V_270 ) ) {
F_147 ( L_5 ,
V_334 , V_4 -> V_270 ) ;
return - V_225 ;
}
F_188 ( V_2 , V_4 -> V_270 ) ;
V_96 = F_229 ( V_2 , 0 , V_85 ,
V_4 -> V_270 ) ;
if ( F_2 ( V_96 ) )
return V_96 ;
V_85 += V_4 -> V_270 ;
V_343 -= V_4 -> V_270 ;
}
V_344 = F_230 ( V_85 ) ;
V_346 = V_142 - V_344 ;
V_175 = ( ( V_343 > V_346 ) ? V_346 : V_343 ) ;
V_2 -> V_353 = V_343 ;
V_2 -> V_175 += V_343 ;
V_2 -> V_188 += V_343 ;
F_231 ( V_343 , & V_20 -> V_27 . V_191 ) ;
while ( F_23 ( V_343 ) ) {
V_345 = F_206 ( V_2 ) -> V_345 ;
if ( F_2 ( V_345 >= V_354 ) ) {
F_147 ( L_6 ,
V_354 ) ;
return - V_355 ;
}
V_348 = F_51 ( V_85 ) ;
V_85 += V_175 ;
F_50 ( V_348 ) ;
F_232 ( V_348 ) ;
F_233 ( V_2 , V_345 , V_348 , V_344 , V_175 ) ;
V_343 -= V_175 ;
V_344 = 0 ;
V_346 = V_142 ;
V_175 = ( ( V_343 > V_346 ) ? V_346 : V_343 ) ;
}
return V_334 ;
}
static int F_234 ( struct V_19 * V_20 , struct V_252 * V_253 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_7 V_256 ;
int V_96 , V_356 = 0 ;
void * V_338 ;
F_193 ( struct V_293 * , V_254 , V_253 -> V_255 ) ;
bool V_357 = ! ( V_253 -> V_358 & V_359 ) ;
int V_334 , V_340 ;
unsigned char * V_341 ;
int V_360 = 0 ;
int V_34 = V_171 ;
int V_342 , V_273 ;
F_169 ( & V_20 -> V_361 ) ;
if ( F_23 ( V_254 == NULL ) ) {
V_4 = F_20 ( V_20 ) ;
V_256 = V_20 -> V_195 ;
V_341 = NULL ;
} else {
V_96 = - V_225 ;
if ( V_253 -> V_258 < sizeof( struct V_293 ) )
goto V_133;
if ( V_253 -> V_258 < ( V_254 -> V_314
+ F_235 ( struct V_293 ,
V_315 ) ) )
goto V_133;
V_256 = V_254 -> V_310 ;
V_341 = V_254 -> V_315 ;
V_4 = F_236 ( F_76 ( & V_20 -> V_27 ) , V_254 -> V_313 ) ;
}
V_96 = - V_362 ;
if ( F_2 ( V_4 == NULL ) )
goto V_133;
V_96 = - V_264 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_265 ) ) )
goto V_363;
V_356 = V_4 -> V_270 + V_271 ;
V_340 = V_20 -> V_79 . V_74
- ( V_20 -> V_119 - sizeof( struct V_293 ) ) ;
if ( V_340 > V_4 -> V_269 + V_356 )
V_340 = V_4 -> V_269 + V_356 ;
do {
V_338 = F_62 ( V_20 , & V_20 -> V_79 ,
V_364 ) ;
if ( F_2 ( V_338 == NULL ) ) {
if ( V_357 && F_237 () )
F_238 () ;
continue;
}
V_34 = V_364 ;
V_342 = F_196 ( V_4 ) ;
V_273 = V_4 -> V_274 ;
V_2 = F_239 ( & V_20 -> V_27 ,
V_342 + V_273 + sizeof( struct V_293 ) ,
0 , & V_96 ) ;
if ( F_2 ( V_2 == NULL ) )
goto V_365;
V_334 = F_227 ( V_20 , V_2 , V_338 , V_4 , V_340 , V_256 ,
V_341 , V_342 ) ;
if ( V_334 > V_4 -> V_269 + V_4 -> V_270 ) {
struct V_280 * V_281 ;
F_202 ( V_2 ) ;
V_281 = F_203 ( V_2 ) ;
if ( V_281 -> V_282 != F_204 ( V_283 ) )
V_334 = - V_268 ;
}
if ( F_2 ( V_334 < 0 ) ) {
if ( V_20 -> V_366 ) {
F_49 ( V_20 , V_338 ,
V_171 ) ;
F_130 ( & V_20 -> V_79 ) ;
F_18 ( V_2 ) ;
continue;
} else {
V_34 = V_367 ;
V_96 = V_334 ;
goto V_365;
}
}
F_33 ( V_4 , V_2 ) ;
V_2 -> V_368 = F_225 ;
F_49 ( V_20 , V_338 , V_369 ) ;
F_131 ( & V_20 -> V_79 ) ;
V_34 = V_364 ;
V_96 = V_20 -> V_22 ( V_2 ) ;
if ( F_2 ( V_96 > 0 ) ) {
V_96 = F_240 ( V_96 ) ;
if ( V_96 && F_55 ( V_20 , V_338 ) ==
V_171 ) {
V_2 = NULL ;
goto V_365;
}
V_96 = 0 ;
}
F_130 ( & V_20 -> V_79 ) ;
V_360 += V_334 ;
} while ( F_23 ( ( V_338 != NULL ) ||
( V_357 && F_135 ( & V_20 -> V_79 ) ) ) );
V_96 = V_360 ;
goto V_363;
V_365:
F_49 ( V_20 , V_338 , V_34 ) ;
F_18 ( V_2 ) ;
V_363:
F_241 ( V_4 ) ;
V_133:
F_177 ( & V_20 -> V_361 ) ;
return V_96 ;
}
static struct V_1 * F_242 ( struct V_26 * V_27 , T_6 V_370 ,
T_6 V_356 , T_6 V_175 ,
T_6 V_371 , int V_372 ,
int * V_96 )
{
struct V_1 * V_2 ;
if ( V_370 + V_175 < V_142 || ! V_371 )
V_371 = V_175 ;
V_2 = F_243 ( V_27 , V_370 + V_371 , V_175 - V_371 , V_372 ,
V_96 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_198 ( V_2 , V_356 ) ;
F_201 ( V_2 , V_371 ) ;
V_2 -> V_353 = V_175 - V_371 ;
V_2 -> V_175 += V_175 - V_371 ;
return V_2 ;
}
static int F_244 ( struct V_251 * V_26 , struct V_252 * V_253 , T_6 V_175 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
F_193 ( struct V_293 * , V_254 , V_253 -> V_255 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_7 V_256 ;
unsigned char * V_341 ;
int V_96 , V_356 = 0 ;
struct V_373 V_374 = { 0 } ;
int V_344 = 0 ;
int V_375 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
unsigned short V_376 = 0 ;
int V_342 , V_273 ;
int V_257 = 0 ;
if ( F_23 ( V_254 == NULL ) ) {
V_4 = F_20 ( V_20 ) ;
V_256 = V_20 -> V_195 ;
V_341 = NULL ;
} else {
V_96 = - V_225 ;
if ( V_253 -> V_258 < sizeof( struct V_293 ) )
goto V_133;
if ( V_253 -> V_258 < ( V_254 -> V_314 + F_235 ( struct V_293 , V_315 ) ) )
goto V_133;
V_256 = V_254 -> V_310 ;
V_341 = V_254 -> V_315 ;
V_4 = F_236 ( F_76 ( V_27 ) , V_254 -> V_313 ) ;
}
V_96 = - V_362 ;
if ( F_2 ( V_4 == NULL ) )
goto V_263;
V_96 = - V_264 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_265 ) ) )
goto V_263;
if ( V_26 -> type == V_377 )
V_356 = V_4 -> V_270 ;
if ( V_20 -> V_378 ) {
V_375 = sizeof( V_374 ) ;
V_96 = - V_225 ;
if ( V_175 < V_375 )
goto V_263;
V_175 -= V_375 ;
V_96 = F_200 ( ( void * ) & V_374 , V_253 -> V_278 ,
V_375 ) ;
if ( V_96 < 0 )
goto V_263;
if ( ( V_374 . V_47 & V_379 ) &&
( V_374 . V_380 + V_374 . V_381 + 2 >
V_374 . V_382 ) )
V_374 . V_382 = V_374 . V_380 +
V_374 . V_381 + 2 ;
V_96 = - V_225 ;
if ( V_374 . V_382 > V_175 )
goto V_263;
if ( V_374 . V_376 != V_383 ) {
switch ( V_374 . V_376 & ~ V_384 ) {
case V_385 :
V_376 = V_386 ;
break;
case V_387 :
V_376 = V_388 ;
break;
case V_389 :
V_376 = V_390 ;
break;
default:
goto V_263;
}
if ( V_374 . V_376 & V_384 )
V_376 |= V_391 ;
if ( V_374 . V_392 == 0 )
goto V_263;
}
}
if ( F_2 ( F_146 ( V_27 , V_266 ) ) ) {
if ( ! F_195 ( V_4 ) ) {
V_96 = - V_267 ;
goto V_263;
}
V_257 = 4 ;
}
V_96 = - V_268 ;
if ( ! V_376 && ( V_175 > V_4 -> V_269 + V_356 + V_271 + V_257 ) )
goto V_263;
V_96 = - V_184 ;
V_342 = F_196 ( V_4 ) ;
V_273 = V_4 -> V_274 ;
V_2 = F_242 ( V_27 , V_342 + V_273 , V_342 , V_175 , V_374 . V_382 ,
V_253 -> V_358 & V_359 , & V_96 ) ;
if ( V_2 == NULL )
goto V_263;
F_245 ( V_2 , V_356 ) ;
V_96 = - V_225 ;
if ( V_26 -> type == V_299 &&
( V_344 = F_228 ( V_2 , V_4 , F_115 ( V_256 ) , V_341 , NULL , V_175 ) ) < 0 )
goto V_279;
V_96 = F_246 ( V_2 , V_344 , V_253 -> V_278 , 0 , V_175 ) ;
if ( V_96 )
goto V_279;
F_205 ( V_27 , & F_206 ( V_2 ) -> V_288 ) ;
if ( ! V_376 && ( V_175 > V_4 -> V_269 + V_356 + V_257 ) ) {
struct V_280 * V_281 ;
F_202 ( V_2 ) ;
V_281 = F_203 ( V_2 ) ;
if ( V_281 -> V_282 != F_204 ( V_283 ) ) {
V_96 = - V_268 ;
goto V_279;
}
}
V_2 -> V_248 = V_256 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_284 = V_27 -> V_285 ;
V_2 -> V_286 = V_27 -> V_287 ;
F_33 ( V_4 , V_2 ) ;
if ( V_20 -> V_378 ) {
if ( V_374 . V_47 & V_379 ) {
if ( ! F_247 ( V_2 , V_374 . V_380 ,
V_374 . V_381 ) ) {
V_96 = - V_225 ;
goto V_279;
}
}
F_206 ( V_2 ) -> V_392 = V_374 . V_392 ;
F_206 ( V_2 ) -> V_376 = V_376 ;
F_206 ( V_2 ) -> V_376 |= V_393 ;
F_206 ( V_2 ) -> V_394 = 0 ;
V_175 += V_375 ;
}
if ( ! F_30 ( V_20 ) )
F_207 ( V_2 , V_356 ) ;
if ( F_2 ( V_257 == 4 ) )
V_2 -> V_289 = 1 ;
V_96 = V_20 -> V_22 ( V_2 ) ;
if ( V_96 > 0 && ( V_96 = F_240 ( V_96 ) ) != 0 )
goto V_263;
F_241 ( V_4 ) ;
return V_175 ;
V_279:
F_18 ( V_2 ) ;
V_263:
if ( V_4 )
F_241 ( V_4 ) ;
V_133:
return V_96 ;
}
static int F_248 ( struct V_249 * V_250 , struct V_251 * V_26 ,
struct V_252 * V_253 , T_6 V_175 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
if ( V_20 -> V_79 . V_72 )
return F_234 ( V_20 , V_253 ) ;
else
return F_244 ( V_26 , V_253 , V_175 ) ;
}
static int F_249 ( struct V_251 * V_26 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 ;
struct V_211 * V_211 ;
union V_103 V_104 ;
if ( ! V_27 )
return 0 ;
V_211 = F_76 ( V_27 ) ;
V_20 = F_37 ( V_27 ) ;
F_169 ( & V_211 -> V_395 . V_396 ) ;
F_250 ( V_27 ) ;
F_177 ( & V_211 -> V_395 . V_396 ) ;
F_251 () ;
F_252 ( V_211 , V_27 -> V_397 , - 1 ) ;
F_253 () ;
F_47 ( & V_20 -> V_32 ) ;
F_48 ( V_27 , false ) ;
F_28 ( V_20 ) ;
if ( V_20 -> V_30 . V_4 ) {
F_241 ( V_20 -> V_30 . V_4 ) ;
V_20 -> V_30 . V_4 = NULL ;
}
F_45 ( & V_20 -> V_32 ) ;
F_254 ( V_27 ) ;
if ( V_20 -> V_82 . V_72 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
F_255 ( V_27 , & V_104 , 1 , 0 ) ;
}
if ( V_20 -> V_79 . V_72 ) {
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
F_255 ( V_27 , & V_104 , 1 , 1 ) ;
}
F_178 ( V_27 ) ;
F_46 () ;
F_256 ( V_27 ) ;
V_26 -> V_27 = NULL ;
F_144 ( & V_27 -> V_132 ) ;
F_140 ( V_20 ) ;
F_257 ( V_27 ) ;
F_258 ( V_27 ) ;
return 0 ;
}
static int F_259 ( struct V_26 * V_27 , struct V_3 * V_4 , T_7 V_256 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
const struct V_3 * V_398 ;
T_7 V_399 ;
bool V_400 ;
if ( V_20 -> V_29 ) {
if ( V_4 )
F_241 ( V_4 ) ;
return - V_225 ;
}
F_260 ( V_27 ) ;
F_47 ( & V_20 -> V_32 ) ;
V_399 = V_20 -> V_30 . type ;
V_398 = V_20 -> V_30 . V_4 ;
V_400 = V_399 != V_256 || V_398 != V_4 ;
if ( V_400 ) {
F_48 ( V_27 , true ) ;
V_20 -> V_195 = V_256 ;
V_20 -> V_30 . type = V_256 ;
if ( V_20 -> V_30 . V_4 )
F_241 ( V_20 -> V_30 . V_4 ) ;
V_20 -> V_30 . V_4 = V_4 ;
V_20 -> V_98 = V_4 ? V_4 -> V_98 : 0 ;
F_26 ( V_20 , V_4 ) ;
}
if ( V_256 == 0 || ! V_400 )
goto V_263;
if ( ! V_4 || ( V_4 -> V_47 & V_265 ) ) {
F_36 ( V_27 ) ;
} else {
V_27 -> V_401 = V_264 ;
if ( ! F_146 ( V_27 , V_192 ) )
V_27 -> V_402 ( V_27 ) ;
}
V_263:
F_45 ( & V_20 -> V_32 ) ;
F_261 ( V_27 ) ;
return 0 ;
}
static int F_262 ( struct V_251 * V_26 , struct V_259 * V_403 ,
int V_404 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
char V_246 [ 15 ] ;
struct V_3 * V_4 ;
int V_96 = - V_262 ;
if ( V_404 != sizeof( struct V_259 ) )
return - V_225 ;
F_190 ( V_246 , V_403 -> V_405 , sizeof( V_246 ) ) ;
V_4 = F_263 ( F_76 ( V_27 ) , V_246 ) ;
if ( V_4 )
V_96 = F_259 ( V_27 , V_4 , F_37 ( V_27 ) -> V_195 ) ;
return V_96 ;
}
static int F_264 ( struct V_251 * V_26 , struct V_259 * V_403 , int V_404 )
{
struct V_293 * V_294 = (struct V_293 * ) V_403 ;
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_3 * V_4 = NULL ;
int V_96 ;
if ( V_404 < sizeof( struct V_293 ) )
return - V_225 ;
if ( V_294 -> V_307 != V_308 )
return - V_225 ;
if ( V_294 -> V_313 ) {
V_96 = - V_262 ;
V_4 = F_236 ( F_76 ( V_27 ) , V_294 -> V_313 ) ;
if ( V_4 == NULL )
goto V_133;
}
V_96 = F_259 ( V_27 , V_4 , V_294 -> V_310 ? : F_37 ( V_27 ) -> V_195 ) ;
V_133:
return V_96 ;
}
static int F_265 ( struct V_211 * V_211 , struct V_251 * V_26 , int V_248 ,
int V_406 )
{
struct V_26 * V_27 ;
struct V_19 * V_20 ;
T_7 V_256 = ( V_407 T_7 ) V_248 ;
int V_96 ;
if ( ! F_266 ( V_211 -> V_408 , V_409 ) )
return - V_410 ;
if ( V_26 -> type != V_299 && V_26 -> type != V_377 &&
V_26 -> type != V_411 )
return - V_412 ;
V_26 -> V_413 = V_414 ;
V_96 = - V_184 ;
V_27 = F_267 ( V_211 , V_415 , V_229 , & V_416 ) ;
if ( V_27 == NULL )
goto V_133;
V_26 -> V_6 = & V_417 ;
if ( V_26 -> type == V_411 )
V_26 -> V_6 = & V_418 ;
F_268 ( V_26 , V_27 ) ;
V_20 = F_37 ( V_27 ) ;
V_27 -> V_419 = V_415 ;
V_20 -> V_195 = V_256 ;
V_20 -> V_22 = F_208 ;
V_96 = F_138 ( V_20 ) ;
if ( V_96 )
goto V_420;
F_28 ( V_20 ) ;
V_27 -> V_421 = F_143 ;
F_269 ( V_27 ) ;
F_175 ( & V_20 -> V_32 ) ;
F_270 ( & V_20 -> V_361 ) ;
V_20 -> V_30 . F_70 = F_211 ;
if ( V_26 -> type == V_411 )
V_20 -> V_30 . F_70 = F_183 ;
V_20 -> V_30 . V_209 = V_27 ;
if ( V_256 ) {
V_20 -> V_30 . type = V_256 ;
F_36 ( V_27 ) ;
}
F_169 ( & V_211 -> V_395 . V_396 ) ;
F_271 ( V_27 , & V_211 -> V_395 . V_422 ) ;
F_177 ( & V_211 -> V_395 . V_396 ) ;
F_251 () ;
F_252 ( V_211 , & V_416 , 1 ) ;
F_253 () ;
return 0 ;
V_420:
F_272 ( V_27 ) ;
V_133:
return V_96 ;
}
static int F_273 ( struct V_249 * V_250 , struct V_251 * V_26 ,
struct V_252 * V_253 , T_6 V_175 , int V_47 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_1 * V_2 ;
int V_423 , V_96 ;
int V_375 = 0 ;
V_96 = - V_225 ;
if ( V_47 & ~ ( V_424 | V_359 | V_425 | V_426 | V_427 ) )
goto V_133;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_47 & V_427 ) {
V_96 = F_274 ( V_27 , V_253 , V_175 ,
V_428 , V_429 ) ;
goto V_133;
}
V_2 = F_275 ( V_27 , V_47 , V_47 & V_359 , & V_96 ) ;
if ( V_2 == NULL )
goto V_133;
if ( F_37 ( V_27 ) -> V_378 ) {
struct V_373 V_374 = { 0 } ;
V_96 = - V_225 ;
V_375 = sizeof( V_374 ) ;
if ( V_175 < V_375 )
goto V_279;
V_175 -= V_375 ;
if ( F_276 ( V_2 ) ) {
struct V_430 * V_431 = F_206 ( V_2 ) ;
V_374 . V_382 = F_277 ( V_2 ) ;
V_374 . V_392 = V_431 -> V_392 ;
if ( V_431 -> V_376 & V_386 )
V_374 . V_376 = V_385 ;
else if ( V_431 -> V_376 & V_388 )
V_374 . V_376 = V_387 ;
else if ( V_431 -> V_376 & V_390 )
V_374 . V_376 = V_389 ;
else if ( V_431 -> V_376 & V_432 )
goto V_279;
else
F_53 () ;
if ( V_431 -> V_376 & V_391 )
V_374 . V_376 |= V_384 ;
} else
V_374 . V_376 = V_383 ;
if ( V_2 -> V_326 == V_327 ) {
V_374 . V_47 = V_379 ;
V_374 . V_380 = F_278 ( V_2 ) ;
V_374 . V_381 = V_2 -> V_381 ;
} else if ( V_2 -> V_326 == V_433 ) {
V_374 . V_47 = V_434 ;
}
V_96 = F_279 ( V_253 -> V_278 , ( void * ) & V_374 ,
V_375 ) ;
if ( V_96 < 0 )
goto V_279;
}
V_423 = V_2 -> V_175 ;
if ( V_423 > V_175 ) {
V_423 = V_175 ;
V_253 -> V_358 |= V_425 ;
}
V_96 = F_280 ( V_2 , 0 , V_253 -> V_278 , V_423 ) ;
if ( V_96 )
goto V_279;
F_281 ( V_253 , V_27 , V_2 ) ;
if ( V_253 -> V_255 ) {
if ( V_26 -> type == V_411 ) {
F_282 ( sizeof( struct V_236 ) ) ;
V_253 -> V_258 = sizeof( struct V_236 ) ;
} else {
struct V_293 * V_294 = & F_187 ( V_2 ) -> V_242 . V_306 ;
V_253 -> V_258 = V_294 -> V_314 +
F_235 ( struct V_293 , V_315 ) ;
}
memcpy ( V_253 -> V_255 , & F_187 ( V_2 ) -> V_242 ,
V_253 -> V_258 ) ;
}
if ( F_37 ( V_27 ) -> V_435 ) {
struct V_436 V_437 ;
V_437 . V_41 = V_145 ;
if ( V_2 -> V_326 == V_327 )
V_437 . V_41 |= V_328 ;
V_437 . V_334 = F_187 ( V_2 ) -> V_316 ;
V_437 . V_335 = V_2 -> V_175 ;
V_437 . V_336 = 0 ;
V_437 . V_337 = F_213 ( V_2 ) ;
if ( F_113 ( V_2 ) ) {
V_437 . V_166 = F_114 ( V_2 ) ;
V_437 . V_167 = F_115 ( V_2 -> V_168 ) ;
V_437 . V_41 |= V_169 | V_170 ;
} else {
V_437 . V_166 = 0 ;
V_437 . V_167 = 0 ;
}
F_283 ( V_253 , V_428 , V_438 , sizeof( V_437 ) , & V_437 ) ;
}
V_96 = V_375 + ( ( V_47 & V_425 ) ? V_2 -> V_175 : V_423 ) ;
V_279:
F_284 ( V_27 , V_2 ) ;
V_133:
return V_96 ;
}
static int F_285 ( struct V_251 * V_26 , struct V_259 * V_403 ,
int * V_439 , int V_440 )
{
struct V_3 * V_4 ;
struct V_26 * V_27 = V_26 -> V_27 ;
if ( V_440 )
return - V_441 ;
V_403 -> V_442 = V_308 ;
memset ( V_403 -> V_405 , 0 , sizeof( V_403 -> V_405 ) ) ;
F_21 () ;
V_4 = F_286 ( F_76 ( V_27 ) , F_37 ( V_27 ) -> V_98 ) ;
if ( V_4 )
F_190 ( V_403 -> V_405 , V_4 -> V_246 , sizeof( V_403 -> V_405 ) ) ;
F_25 () ;
* V_439 = sizeof( * V_403 ) ;
return 0 ;
}
static int F_287 ( struct V_251 * V_26 , struct V_259 * V_403 ,
int * V_439 , int V_440 )
{
struct V_3 * V_4 ;
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
F_193 ( struct V_293 * , V_294 , V_403 ) ;
if ( V_440 )
return - V_441 ;
V_294 -> V_307 = V_308 ;
V_294 -> V_313 = V_20 -> V_98 ;
V_294 -> V_310 = V_20 -> V_195 ;
V_294 -> V_311 = 0 ;
F_21 () ;
V_4 = F_286 ( F_76 ( V_27 ) , V_20 -> V_98 ) ;
if ( V_4 ) {
V_294 -> V_309 = V_4 -> type ;
V_294 -> V_314 = V_4 -> V_404 ;
memcpy ( V_294 -> V_315 , V_4 -> V_443 , V_4 -> V_404 ) ;
} else {
V_294 -> V_309 = 0 ;
V_294 -> V_314 = 0 ;
}
F_25 () ;
* V_439 = F_235 ( struct V_293 , V_315 ) + V_294 -> V_314 ;
return 0 ;
}
static int F_288 ( struct V_3 * V_4 , struct V_444 * V_201 ,
int V_445 )
{
switch ( V_201 -> type ) {
case V_446 :
if ( V_201 -> V_447 != V_4 -> V_404 )
return - V_225 ;
if ( V_445 > 0 )
return F_289 ( V_4 , V_201 -> V_341 ) ;
else
return F_290 ( V_4 , V_201 -> V_341 ) ;
break;
case V_448 :
return F_291 ( V_4 , V_445 ) ;
break;
case V_449 :
return F_292 ( V_4 , V_445 ) ;
break;
case V_450 :
if ( V_201 -> V_447 != V_4 -> V_404 )
return - V_225 ;
if ( V_445 > 0 )
return F_293 ( V_4 , V_201 -> V_341 ) ;
else
return F_294 ( V_4 , V_201 -> V_341 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_295 ( struct V_3 * V_4 , struct V_444 * V_201 , int V_445 )
{
for ( ; V_201 ; V_201 = V_201 -> V_203 ) {
if ( V_201 -> V_98 == V_4 -> V_98 )
F_288 ( V_4 , V_201 , V_445 ) ;
}
}
static int F_296 ( struct V_26 * V_27 , struct V_451 * V_452 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
struct V_444 * V_453 , * V_201 ;
struct V_3 * V_4 ;
int V_96 ;
F_74 () ;
V_96 = - V_262 ;
V_4 = F_75 ( F_76 ( V_27 ) , V_452 -> V_454 ) ;
if ( ! V_4 )
goto V_455;
V_96 = - V_225 ;
if ( V_452 -> V_456 > V_4 -> V_404 )
goto V_455;
V_96 = - V_184 ;
V_201 = F_297 ( sizeof( * V_201 ) , V_229 ) ;
if ( V_201 == NULL )
goto V_455;
V_96 = 0 ;
for ( V_453 = V_20 -> V_457 ; V_453 ; V_453 = V_453 -> V_203 ) {
if ( V_453 -> V_98 == V_452 -> V_454 &&
V_453 -> type == V_452 -> V_458 &&
V_453 -> V_447 == V_452 -> V_456 &&
memcmp ( V_453 -> V_341 , V_452 -> V_459 , V_453 -> V_447 ) == 0 ) {
V_453 -> V_460 ++ ;
F_182 ( V_201 ) ;
goto V_455;
}
}
V_201 -> type = V_452 -> V_458 ;
V_201 -> V_98 = V_452 -> V_454 ;
V_201 -> V_447 = V_452 -> V_456 ;
memcpy ( V_201 -> V_341 , V_452 -> V_459 , V_201 -> V_447 ) ;
V_201 -> V_460 = 1 ;
V_201 -> V_203 = V_20 -> V_457 ;
V_20 -> V_457 = V_201 ;
V_96 = F_288 ( V_4 , V_201 , 1 ) ;
if ( V_96 ) {
V_20 -> V_457 = V_201 -> V_203 ;
F_182 ( V_201 ) ;
}
V_455:
F_77 () ;
return V_96 ;
}
static int F_298 ( struct V_26 * V_27 , struct V_451 * V_452 )
{
struct V_444 * V_453 , * * V_461 ;
F_74 () ;
for ( V_461 = & F_37 ( V_27 ) -> V_457 ; ( V_453 = * V_461 ) != NULL ; V_461 = & V_453 -> V_203 ) {
if ( V_453 -> V_98 == V_452 -> V_454 &&
V_453 -> type == V_452 -> V_458 &&
V_453 -> V_447 == V_452 -> V_456 &&
memcmp ( V_453 -> V_341 , V_452 -> V_459 , V_453 -> V_447 ) == 0 ) {
if ( -- V_453 -> V_460 == 0 ) {
struct V_3 * V_4 ;
* V_461 = V_453 -> V_203 ;
V_4 = F_75 ( F_76 ( V_27 ) , V_453 -> V_98 ) ;
if ( V_4 )
F_288 ( V_4 , V_453 , - 1 ) ;
F_182 ( V_453 ) ;
}
F_77 () ;
return 0 ;
}
}
F_77 () ;
return - V_462 ;
}
static void F_254 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
struct V_444 * V_453 ;
if ( ! V_20 -> V_457 )
return;
F_74 () ;
while ( ( V_453 = V_20 -> V_457 ) != NULL ) {
struct V_3 * V_4 ;
V_20 -> V_457 = V_453 -> V_203 ;
V_4 = F_75 ( F_76 ( V_27 ) , V_453 -> V_98 ) ;
if ( V_4 != NULL )
F_288 ( V_4 , V_453 , - 1 ) ;
F_182 ( V_453 ) ;
}
F_77 () ;
}
static int
F_299 ( struct V_251 * V_26 , int V_463 , int V_464 , char T_8 * V_465 , unsigned int V_466 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
int V_11 ;
if ( V_463 != V_428 )
return - V_467 ;
switch ( V_464 ) {
case V_468 :
case V_469 :
{
struct V_451 V_452 ;
int V_175 = V_466 ;
memset ( & V_452 , 0 , sizeof( V_452 ) ) ;
if ( V_175 < sizeof( struct V_470 ) )
return - V_225 ;
if ( V_175 > sizeof( V_452 ) )
V_175 = sizeof( V_452 ) ;
if ( F_300 ( & V_452 , V_465 , V_175 ) )
return - V_355 ;
if ( V_175 < ( V_452 . V_456 + F_235 ( struct V_470 , V_459 ) ) )
return - V_225 ;
if ( V_464 == V_468 )
V_11 = F_296 ( V_27 , & V_452 ) ;
else
V_11 = F_298 ( V_27 , & V_452 ) ;
return V_11 ;
}
case V_471 :
case V_472 :
{
union V_103 V_104 ;
int V_175 ;
switch ( V_20 -> V_38 ) {
case V_39 :
case V_42 :
V_175 = sizeof( V_104 . V_473 ) ;
break;
case V_44 :
default:
V_175 = sizeof( V_104 . V_106 ) ;
break;
}
if ( V_466 < V_175 )
return - V_225 ;
if ( F_37 ( V_27 ) -> V_378 )
return - V_225 ;
if ( F_300 ( & V_104 . V_473 , V_465 , V_175 ) )
return - V_355 ;
return F_255 ( V_27 , & V_104 , 0 ,
V_464 == V_472 ) ;
}
case V_474 :
{
int V_475 ;
if ( V_466 != sizeof( V_475 ) )
return - V_225 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
F_37 ( V_27 ) -> V_331 = V_475 ;
return 0 ;
}
case V_476 :
{
int V_475 ;
if ( V_466 != sizeof( V_475 ) )
return - V_225 ;
if ( V_20 -> V_82 . V_72 || V_20 -> V_79 . V_72 )
return - V_477 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
switch ( V_475 ) {
case V_39 :
case V_42 :
case V_44 :
V_20 -> V_38 = V_475 ;
return 0 ;
default:
return - V_225 ;
}
}
case V_478 :
{
unsigned int V_475 ;
if ( V_466 != sizeof( V_475 ) )
return - V_225 ;
if ( V_20 -> V_82 . V_72 || V_20 -> V_79 . V_72 )
return - V_477 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
V_20 -> V_329 = V_475 ;
return 0 ;
}
case V_479 :
{
unsigned int V_475 ;
if ( V_466 != sizeof( V_475 ) )
return - V_225 ;
if ( V_20 -> V_82 . V_72 || V_20 -> V_79 . V_72 )
return - V_477 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
V_20 -> V_366 = ! ! V_475 ;
return 0 ;
}
case V_438 :
{
int V_475 ;
if ( V_466 < sizeof( V_475 ) )
return - V_225 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
V_20 -> V_435 = ! ! V_475 ;
return 0 ;
}
case V_480 :
{
int V_475 ;
if ( V_466 < sizeof( V_475 ) )
return - V_225 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
V_20 -> V_312 = ! ! V_475 ;
return 0 ;
}
case V_481 :
{
int V_475 ;
if ( V_26 -> type != V_377 )
return - V_225 ;
if ( V_20 -> V_82 . V_72 || V_20 -> V_79 . V_72 )
return - V_477 ;
if ( V_466 < sizeof( V_475 ) )
return - V_225 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
V_20 -> V_378 = ! ! V_475 ;
return 0 ;
}
case V_482 :
{
int V_475 ;
if ( V_466 != sizeof( V_475 ) )
return - V_225 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
V_20 -> V_59 = V_475 ;
return 0 ;
}
case V_483 :
{
int V_475 ;
if ( V_466 != sizeof( V_475 ) )
return - V_225 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
return F_168 ( V_27 , V_475 & 0xffff , V_475 >> 16 ) ;
}
case V_484 :
{
unsigned int V_475 ;
if ( V_466 != sizeof( V_475 ) )
return - V_225 ;
if ( V_20 -> V_82 . V_72 || V_20 -> V_79 . V_72 )
return - V_477 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
V_20 -> V_349 = ! ! V_475 ;
return 0 ;
}
case V_485 :
{
int V_475 ;
if ( V_466 != sizeof( V_475 ) )
return - V_225 ;
if ( F_300 ( & V_475 , V_465 , sizeof( V_475 ) ) )
return - V_355 ;
V_20 -> V_22 = V_475 ? F_1 : F_208 ;
return 0 ;
}
default:
return - V_467 ;
}
}
static int F_301 ( struct V_251 * V_26 , int V_463 , int V_464 ,
char T_8 * V_465 , int T_8 * V_466 )
{
int V_175 ;
int V_475 , V_486 = sizeof( V_475 ) ;
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
void * V_85 = & V_475 ;
union V_487 V_488 ;
if ( V_463 != V_428 )
return - V_467 ;
if ( F_302 ( V_175 , V_466 ) )
return - V_355 ;
if ( V_175 < 0 )
return - V_225 ;
switch ( V_464 ) {
case V_489 :
F_67 ( & V_27 -> V_132 . V_83 ) ;
memcpy ( & V_488 , & V_20 -> V_122 , sizeof( V_488 ) ) ;
memset ( & V_20 -> V_122 , 0 , sizeof( V_20 -> V_122 ) ) ;
F_68 ( & V_27 -> V_132 . V_83 ) ;
if ( V_20 -> V_38 == V_44 ) {
V_486 = sizeof( struct V_490 ) ;
V_488 . V_123 . V_318 += V_488 . V_123 . V_151 ;
V_85 = & V_488 . V_123 ;
} else {
V_486 = sizeof( struct V_491 ) ;
V_488 . V_317 . V_318 += V_488 . V_317 . V_151 ;
V_85 = & V_488 . V_317 ;
}
break;
case V_438 :
V_475 = V_20 -> V_435 ;
break;
case V_480 :
V_475 = V_20 -> V_312 ;
break;
case V_481 :
V_475 = V_20 -> V_378 ;
break;
case V_476 :
V_475 = V_20 -> V_38 ;
break;
case V_492 :
if ( V_175 > sizeof( int ) )
V_175 = sizeof( int ) ;
if ( F_300 ( & V_475 , V_465 , V_175 ) )
return - V_355 ;
switch ( V_475 ) {
case V_39 :
V_475 = sizeof( struct V_493 ) ;
break;
case V_42 :
V_475 = sizeof( struct V_494 ) ;
break;
case V_44 :
V_475 = sizeof( struct V_146 ) ;
break;
default:
return - V_225 ;
}
break;
case V_478 :
V_475 = V_20 -> V_329 ;
break;
case V_479 :
V_475 = V_20 -> V_366 ;
break;
case V_482 :
V_475 = V_20 -> V_59 ;
break;
case V_483 :
V_475 = ( V_20 -> V_29 ?
( ( T_4 ) V_20 -> V_29 -> V_222 |
( ( T_4 ) V_20 -> V_29 -> type << 16 ) |
( ( T_4 ) V_20 -> V_29 -> V_47 << 24 ) ) :
0 ) ;
break;
case V_484 :
V_475 = V_20 -> V_349 ;
break;
case V_485 :
V_475 = F_30 ( V_20 ) ;
break;
default:
return - V_467 ;
}
if ( V_175 > V_486 )
V_175 = V_486 ;
if ( F_303 ( V_175 , V_466 ) )
return - V_355 ;
if ( F_304 ( V_465 , V_85 , V_175 ) )
return - V_355 ;
return 0 ;
}
static int F_305 ( struct V_495 * V_496 ,
unsigned long V_253 , void * V_497 )
{
struct V_26 * V_27 ;
struct V_3 * V_4 = F_306 ( V_497 ) ;
struct V_211 * V_211 = F_163 ( V_4 ) ;
F_21 () ;
F_307 (sk, &net->packet.sklist) {
struct V_19 * V_20 = F_37 ( V_27 ) ;
switch ( V_253 ) {
case V_498 :
if ( V_20 -> V_457 )
F_295 ( V_4 , V_20 -> V_457 , - 1 ) ;
case V_499 :
if ( V_4 -> V_98 == V_20 -> V_98 ) {
F_47 ( & V_20 -> V_32 ) ;
if ( V_20 -> V_28 ) {
F_41 ( V_27 , false ) ;
V_27 -> V_401 = V_264 ;
if ( ! F_146 ( V_27 , V_192 ) )
V_27 -> V_402 ( V_27 ) ;
}
if ( V_253 == V_498 ) {
F_28 ( V_20 ) ;
V_20 -> V_98 = - 1 ;
if ( V_20 -> V_30 . V_4 )
F_241 ( V_20 -> V_30 . V_4 ) ;
V_20 -> V_30 . V_4 = NULL ;
}
F_45 ( & V_20 -> V_32 ) ;
}
break;
case V_500 :
if ( V_4 -> V_98 == V_20 -> V_98 ) {
F_47 ( & V_20 -> V_32 ) ;
if ( V_20 -> V_195 )
F_36 ( V_27 ) ;
F_45 ( & V_20 -> V_32 ) ;
}
break;
}
}
F_25 () ;
return V_501 ;
}
static int F_308 ( struct V_251 * V_26 , unsigned int V_502 ,
unsigned long V_503 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
switch ( V_502 ) {
case V_504 :
{
int V_505 = F_309 ( V_27 ) ;
return F_303 ( V_505 , ( int T_8 * ) V_503 ) ;
}
case V_506 :
{
struct V_1 * V_2 ;
int V_505 = 0 ;
F_67 ( & V_27 -> V_132 . V_83 ) ;
V_2 = F_310 ( & V_27 -> V_132 ) ;
if ( V_2 )
V_505 = V_2 -> V_175 ;
F_68 ( & V_27 -> V_132 . V_83 ) ;
return F_303 ( V_505 , ( int T_8 * ) V_503 ) ;
}
case V_507 :
return F_311 ( V_27 , (struct V_508 T_8 * ) V_503 ) ;
case V_509 :
return F_312 ( V_27 , (struct V_45 T_8 * ) V_503 ) ;
#ifdef F_313
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
case V_522 :
case V_523 :
return V_524 . V_525 ( V_26 , V_502 , V_503 ) ;
#endif
default:
return - V_526 ;
}
return 0 ;
}
static unsigned int F_314 ( struct V_527 * V_527 , struct V_251 * V_26 ,
T_9 * V_528 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
unsigned int V_529 = F_315 ( V_527 , V_26 , V_528 ) ;
F_67 ( & V_27 -> V_132 . V_83 ) ;
if ( V_20 -> V_82 . V_72 ) {
if ( ! F_127 ( V_20 , & V_20 -> V_82 ,
V_162 ) )
V_529 |= V_530 | V_531 ;
}
F_68 ( & V_27 -> V_132 . V_83 ) ;
F_67 ( & V_27 -> V_532 . V_83 ) ;
if ( V_20 -> V_79 . V_72 ) {
if ( F_62 ( V_20 , & V_20 -> V_79 , V_171 ) )
V_529 |= V_533 | V_534 ;
}
F_68 ( & V_27 -> V_532 . V_83 ) ;
return V_529 ;
}
static void F_316 ( struct V_535 * V_536 )
{
struct V_527 * V_527 = V_536 -> V_537 ;
struct V_251 * V_26 = V_527 -> V_538 ;
struct V_26 * V_27 = V_26 -> V_27 ;
if ( V_27 )
F_119 ( & F_37 ( V_27 ) -> V_539 ) ;
}
static void F_317 ( struct V_535 * V_536 )
{
struct V_527 * V_527 = V_536 -> V_537 ;
struct V_251 * V_26 = V_527 -> V_538 ;
struct V_26 * V_27 = V_26 -> V_27 ;
if ( V_27 )
F_108 ( & F_37 ( V_27 ) -> V_539 ) ;
}
static void F_318 ( struct V_108 * V_72 , unsigned int V_540 ,
unsigned int V_175 )
{
int V_201 ;
for ( V_201 = 0 ; V_201 < V_175 ; V_201 ++ ) {
if ( F_23 ( V_72 [ V_201 ] . V_73 ) ) {
if ( F_319 ( V_72 [ V_201 ] . V_73 ) )
F_320 ( V_72 [ V_201 ] . V_73 ) ;
else
F_321 ( ( unsigned long ) V_72 [ V_201 ] . V_73 ,
V_540 ) ;
V_72 [ V_201 ] . V_73 = NULL ;
}
}
F_182 ( V_72 ) ;
}
static char * F_322 ( unsigned long V_540 )
{
char * V_73 ;
T_10 V_541 = V_229 | V_542 |
V_543 | V_544 | V_545 ;
V_73 = ( char * ) F_323 ( V_541 , V_540 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_324 ( ( 1 << V_540 ) * V_142 ) ;
if ( V_73 )
return V_73 ;
V_541 &= ~ V_545 ;
V_73 = ( char * ) F_323 ( V_541 , V_540 ) ;
if ( V_73 )
return V_73 ;
return NULL ;
}
static struct V_108 * F_325 ( struct V_546 * V_473 , int V_540 )
{
unsigned int V_547 = V_473 -> V_117 ;
struct V_108 * V_72 ;
int V_201 ;
V_72 = F_326 ( V_547 , sizeof( struct V_108 ) , V_229 ) ;
if ( F_2 ( ! V_72 ) )
goto V_133;
for ( V_201 = 0 ; V_201 < V_547 ; V_201 ++ ) {
V_72 [ V_201 ] . V_73 = F_322 ( V_540 ) ;
if ( F_2 ( ! V_72 [ V_201 ] . V_73 ) )
goto V_548;
}
V_133:
return V_72 ;
V_548:
F_318 ( V_72 , V_540 , V_547 ) ;
V_72 = NULL ;
goto V_133;
}
static int F_255 ( struct V_26 * V_27 , union V_103 * V_104 ,
int V_549 , int V_79 )
{
struct V_108 * V_72 = NULL ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
int V_550 , V_540 = 0 ;
struct V_66 * V_67 ;
struct V_80 * V_81 ;
T_7 V_195 ;
int V_96 = - V_225 ;
struct V_546 * V_473 = & V_104 -> V_473 ;
if ( ! V_549 && V_79 && ( V_20 -> V_38 > V_42 ) ) {
F_52 ( 1 , L_7 ) ;
goto V_133;
}
V_67 = V_79 ? & V_20 -> V_79 : & V_20 -> V_82 ;
V_81 = V_79 ? & V_27 -> V_532 : & V_27 -> V_132 ;
V_96 = - V_477 ;
if ( ! V_549 ) {
if ( F_89 ( & V_20 -> V_539 ) )
goto V_133;
if ( F_135 ( V_67 ) )
goto V_133;
}
if ( V_473 -> V_117 ) {
V_96 = - V_477 ;
if ( F_2 ( V_67 -> V_72 ) )
goto V_133;
switch ( V_20 -> V_38 ) {
case V_39 :
V_20 -> V_119 = V_551 ;
break;
case V_42 :
V_20 -> V_119 = V_552 ;
break;
case V_44 :
V_20 -> V_119 = V_553 ;
break;
}
V_96 = - V_225 ;
if ( F_2 ( ( int ) V_473 -> V_115 <= 0 ) )
goto V_133;
if ( F_2 ( V_473 -> V_115 & ( V_142 - 1 ) ) )
goto V_133;
if ( F_2 ( V_473 -> V_554 < V_20 -> V_119 +
V_20 -> V_329 ) )
goto V_133;
if ( F_2 ( V_473 -> V_554 & ( V_555 - 1 ) ) )
goto V_133;
V_67 -> V_71 = V_473 -> V_115 / V_473 -> V_554 ;
if ( F_2 ( V_67 -> V_71 <= 0 ) )
goto V_133;
if ( F_2 ( ( V_67 -> V_71 * V_473 -> V_117 ) !=
V_473 -> V_556 ) )
goto V_133;
V_96 = - V_228 ;
V_540 = F_327 ( V_473 -> V_115 ) ;
V_72 = F_325 ( V_473 , V_540 ) ;
if ( F_2 ( ! V_72 ) )
goto V_133;
switch ( V_20 -> V_38 ) {
case V_44 :
if ( ! V_79 )
F_81 ( V_20 , V_67 , V_72 , V_104 , V_79 ) ;
break;
default:
break;
}
}
else {
V_96 = - V_225 ;
if ( F_2 ( V_473 -> V_556 ) )
goto V_133;
}
F_260 ( V_27 ) ;
F_47 ( & V_20 -> V_32 ) ;
V_550 = V_20 -> V_28 ;
V_195 = V_20 -> V_195 ;
if ( V_550 ) {
V_20 -> V_195 = 0 ;
F_41 ( V_27 , false ) ;
}
F_45 ( & V_20 -> V_32 ) ;
F_46 () ;
V_96 = - V_477 ;
F_169 ( & V_20 -> V_361 ) ;
if ( V_549 || F_89 ( & V_20 -> V_539 ) == 0 ) {
V_96 = 0 ;
F_67 ( & V_81 -> V_83 ) ;
F_328 ( V_67 -> V_72 , V_72 ) ;
V_67 -> V_179 = ( V_473 -> V_556 - 1 ) ;
V_67 -> V_75 = 0 ;
V_67 -> V_74 = V_473 -> V_554 ;
F_68 ( & V_81 -> V_83 ) ;
F_328 ( V_67 -> V_557 , V_540 ) ;
F_328 ( V_67 -> V_558 , V_473 -> V_117 ) ;
V_67 -> V_559 = V_473 -> V_115 / V_142 ;
V_20 -> V_30 . F_70 = ( V_20 -> V_82 . V_72 ) ?
V_186 : F_211 ;
F_144 ( V_81 ) ;
if ( F_89 ( & V_20 -> V_539 ) )
F_147 ( L_8 ,
F_89 ( & V_20 -> V_539 ) ) ;
}
F_177 ( & V_20 -> V_361 ) ;
F_47 ( & V_20 -> V_32 ) ;
if ( V_550 ) {
V_20 -> V_195 = V_195 ;
F_36 ( V_27 ) ;
}
F_45 ( & V_20 -> V_32 ) ;
if ( V_549 && ( V_20 -> V_38 > V_42 ) ) {
if ( ! V_79 )
F_65 ( V_20 , V_79 , V_81 ) ;
}
F_261 ( V_27 ) ;
if ( V_72 )
F_318 ( V_72 , V_540 , V_473 -> V_117 ) ;
V_133:
return V_96 ;
}
static int F_329 ( struct V_527 * V_527 , struct V_251 * V_26 ,
struct V_535 * V_536 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
unsigned long V_560 , V_561 ;
struct V_66 * V_67 ;
unsigned long V_140 ;
int V_96 = - V_225 ;
int V_201 ;
if ( V_536 -> V_562 )
return - V_225 ;
F_169 ( & V_20 -> V_361 ) ;
V_561 = 0 ;
for ( V_67 = & V_20 -> V_82 ; V_67 <= & V_20 -> V_79 ; V_67 ++ ) {
if ( V_67 -> V_72 ) {
V_561 += V_67 -> V_558
* V_67 -> V_559
* V_142 ;
}
}
if ( V_561 == 0 )
goto V_133;
V_560 = V_536 -> V_563 - V_536 -> V_564 ;
if ( V_560 != V_561 )
goto V_133;
V_140 = V_536 -> V_564 ;
for ( V_67 = & V_20 -> V_82 ; V_67 <= & V_20 -> V_79 ; V_67 ++ ) {
if ( V_67 -> V_72 == NULL )
continue;
for ( V_201 = 0 ; V_201 < V_67 -> V_558 ; V_201 ++ ) {
struct V_348 * V_348 ;
void * V_565 = V_67 -> V_72 [ V_201 ] . V_73 ;
int V_566 ;
for ( V_566 = 0 ; V_566 < V_67 -> V_559 ; V_566 ++ ) {
V_348 = F_51 ( V_565 ) ;
V_96 = F_330 ( V_536 , V_140 , V_348 ) ;
if ( F_2 ( V_96 ) )
goto V_133;
V_140 += V_142 ;
V_565 += V_142 ;
}
}
}
F_119 ( & V_20 -> V_539 ) ;
V_536 -> V_567 = & V_568 ;
V_96 = 0 ;
V_133:
F_177 ( & V_20 -> V_361 ) ;
return V_96 ;
}
static void * F_331 ( struct V_569 * V_570 , T_11 * V_571 )
__acquires( T_12 )
{
struct V_211 * V_211 = F_332 ( V_570 ) ;
F_21 () ;
return F_333 ( & V_211 -> V_395 . V_422 , * V_571 ) ;
}
static void * F_334 ( struct V_569 * V_570 , void * V_572 , T_11 * V_571 )
{
struct V_211 * V_211 = F_332 ( V_570 ) ;
return F_335 ( V_572 , & V_211 -> V_395 . V_422 , V_571 ) ;
}
static void F_336 ( struct V_569 * V_570 , void * V_572 )
__releases( T_12 )
{
F_25 () ;
}
static int F_337 ( struct V_569 * V_570 , void * V_572 )
{
if ( V_572 == V_573 )
F_338 ( V_570 , L_9 ) ;
else {
struct V_26 * V_574 = F_339 ( V_572 ) ;
const struct V_19 * V_20 = F_37 ( V_574 ) ;
F_340 ( V_570 ,
L_10 ,
V_574 ,
F_89 ( & V_574 -> V_575 ) ,
V_574 -> V_298 ,
F_115 ( V_20 -> V_195 ) ,
V_20 -> V_98 ,
V_20 -> V_28 ,
F_89 ( & V_574 -> V_187 ) ,
F_341 ( F_342 ( V_570 ) , F_343 ( V_574 ) ) ,
F_344 ( V_574 ) ) ;
}
return 0 ;
}
static int F_345 ( struct V_576 * V_576 , struct V_527 * V_527 )
{
return F_346 ( V_576 , V_527 , & V_577 ,
sizeof( struct V_578 ) ) ;
}
static int T_13 F_347 ( struct V_211 * V_211 )
{
F_270 ( & V_211 -> V_395 . V_396 ) ;
F_348 ( & V_211 -> V_395 . V_422 ) ;
if ( ! F_349 ( L_11 , 0 , V_211 -> V_579 , & V_580 ) )
return - V_228 ;
return 0 ;
}
static void T_14 F_350 ( struct V_211 * V_211 )
{
F_351 ( L_11 , V_211 -> V_579 ) ;
}
static void T_15 F_352 ( void )
{
F_353 ( & V_581 ) ;
F_354 ( & V_582 ) ;
F_355 ( V_415 ) ;
F_356 ( & V_416 ) ;
}
static int T_16 F_357 ( void )
{
int V_583 = F_358 ( & V_416 , 0 ) ;
if ( V_583 != 0 )
goto V_133;
F_359 ( & V_584 ) ;
F_360 ( & V_582 ) ;
F_361 ( & V_581 ) ;
V_133:
return V_583 ;
}
