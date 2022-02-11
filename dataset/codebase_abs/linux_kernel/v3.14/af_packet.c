static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 ;
struct V_9 * V_10 ;
T_2 V_11 ;
int V_12 ;
if ( F_2 ( ! F_3 ( V_4 ) ||
! F_4 ( V_4 ) ) ) {
F_5 ( V_2 ) ;
return V_13 ;
}
V_8 = F_6 ( V_2 ) ;
if ( F_7 ( V_2 , V_8 ) &&
F_8 ( V_2 ) ) {
F_5 ( V_2 ) ;
return V_13 ;
}
V_11 = F_9 ( V_2 ) ;
V_10 = F_10 ( V_4 , V_11 ) ;
F_11 ( V_10 ) ;
if ( F_2 ( F_12 ( V_10 ) ) ) {
V_12 = V_14 ;
F_5 ( V_2 ) ;
goto V_15;
}
V_12 = V_6 -> V_16 ( V_2 , V_4 ) ;
if ( F_13 ( F_14 ( V_12 ) ) )
F_15 ( V_10 ) ;
else
F_5 ( V_2 ) ;
V_15:
F_16 ( V_10 ) ;
return V_12 ;
}
static struct V_3 * F_17 ( struct V_17 * V_18 )
{
struct V_3 * V_4 ;
F_18 () ;
V_4 = F_19 ( V_18 -> V_19 ) ;
if ( F_13 ( V_4 ) )
F_20 ( V_4 ) ;
F_21 () ;
return V_4 ;
}
static void F_22 ( struct V_17 * V_18 ,
struct V_3 * V_4 )
{
F_23 ( V_18 -> V_19 , V_4 ) ;
}
static void F_24 ( struct V_17 * V_18 )
{
F_25 ( V_18 -> V_19 , NULL ) ;
}
static bool F_26 ( const struct V_17 * V_18 )
{
return V_18 -> V_20 == F_1 ;
}
static T_2 F_27 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
return ( T_2 ) F_28 () % V_4 -> V_21 ;
}
static void F_29 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_22 ;
if ( V_6 -> V_23 ) {
V_22 = V_6 -> V_23 ( V_4 , V_2 , NULL ,
F_27 ) ;
V_22 = F_30 ( V_4 , V_22 ) ;
} else {
V_22 = F_27 ( V_4 , V_2 ) ;
}
F_31 ( V_2 , V_22 ) ;
}
static void F_32 ( struct V_24 * V_25 )
{
struct V_17 * V_18 = F_33 ( V_25 ) ;
if ( ! V_18 -> V_26 ) {
if ( V_18 -> V_27 )
F_34 ( V_25 , V_18 ) ;
else
F_35 ( & V_18 -> V_28 ) ;
F_36 ( V_25 ) ;
V_18 -> V_26 = 1 ;
}
}
static void F_37 ( struct V_24 * V_25 , bool V_29 )
{
struct V_17 * V_18 = F_33 ( V_25 ) ;
V_18 -> V_26 = 0 ;
if ( V_18 -> V_27 )
F_38 ( V_25 , V_18 ) ;
else
F_39 ( & V_18 -> V_28 ) ;
F_40 ( V_25 ) ;
if ( V_29 ) {
F_41 ( & V_18 -> V_30 ) ;
F_42 () ;
F_43 ( & V_18 -> V_30 ) ;
}
}
static void F_44 ( struct V_24 * V_25 , bool V_29 )
{
struct V_17 * V_18 = F_33 ( V_25 ) ;
if ( V_18 -> V_26 )
F_37 ( V_25 , V_29 ) ;
}
void F_45 ( struct V_17 * V_18 , void * V_31 , int V_32 )
{
union V_33 V_34 ;
V_34 . V_35 = V_31 ;
switch ( V_18 -> V_36 ) {
case V_37 :
V_34 . V_38 -> V_39 = V_32 ;
F_46 ( F_47 ( & V_34 . V_38 -> V_39 ) ) ;
break;
case V_40 :
V_34 . V_41 -> V_39 = V_32 ;
F_46 ( F_47 ( & V_34 . V_41 -> V_39 ) ) ;
break;
case V_42 :
default:
F_48 ( 1 , L_1 ) ;
F_49 () ;
}
F_50 () ;
}
static int F_51 ( struct V_17 * V_18 , void * V_31 )
{
union V_33 V_34 ;
F_52 () ;
V_34 . V_35 = V_31 ;
switch ( V_18 -> V_36 ) {
case V_37 :
F_46 ( F_47 ( & V_34 . V_38 -> V_39 ) ) ;
return V_34 . V_38 -> V_39 ;
case V_40 :
F_46 ( F_47 ( & V_34 . V_41 -> V_39 ) ) ;
return V_34 . V_41 -> V_39 ;
case V_42 :
default:
F_48 ( 1 , L_1 ) ;
F_49 () ;
return 0 ;
}
}
static T_3 F_53 ( struct V_1 * V_2 , struct V_43 * V_44 ,
unsigned int V_45 )
{
struct V_46 * V_47 = F_54 ( V_2 ) ;
if ( V_47 ) {
if ( ( V_45 & V_48 ) &&
F_55 ( V_47 -> V_49 , V_44 ) )
return V_50 ;
if ( ( V_45 & V_51 ) &&
F_55 ( V_47 -> V_52 , V_44 ) )
return V_53 ;
}
if ( F_55 ( V_2 -> V_54 , V_44 ) )
return V_55 ;
return 0 ;
}
static T_3 F_56 ( struct V_17 * V_18 , void * V_31 ,
struct V_1 * V_2 )
{
union V_33 V_34 ;
struct V_43 V_44 ;
T_3 V_56 ;
if ( ! ( V_56 = F_53 ( V_2 , & V_44 , V_18 -> V_57 ) ) )
return 0 ;
V_34 . V_35 = V_31 ;
switch ( V_18 -> V_36 ) {
case V_37 :
V_34 . V_38 -> V_58 = V_44 . V_59 ;
V_34 . V_38 -> V_60 = V_44 . V_61 / V_62 ;
break;
case V_40 :
V_34 . V_41 -> V_58 = V_44 . V_59 ;
V_34 . V_41 -> V_63 = V_44 . V_61 ;
break;
case V_42 :
default:
F_48 ( 1 , L_1 ) ;
F_49 () ;
}
F_46 ( F_47 ( & V_34 . V_38 -> V_58 ) ) ;
F_50 () ;
return V_56 ;
}
static void * F_57 ( struct V_17 * V_18 ,
struct V_64 * V_65 ,
unsigned int V_66 ,
int V_32 )
{
unsigned int V_67 , V_68 ;
union V_33 V_34 ;
V_67 = V_66 / V_65 -> V_69 ;
V_68 = V_66 % V_65 -> V_69 ;
V_34 . V_35 = V_65 -> V_70 [ V_67 ] . V_71 +
( V_68 * V_65 -> V_72 ) ;
if ( V_32 != F_51 ( V_18 , V_34 . V_35 ) )
return NULL ;
return V_34 . V_35 ;
}
static void * F_58 ( struct V_17 * V_18 ,
struct V_64 * V_65 ,
int V_32 )
{
return F_57 ( V_18 , V_65 , V_65 -> V_73 , V_32 ) ;
}
static void F_59 ( struct V_74 * V_75 )
{
F_60 ( & V_75 -> V_76 ) ;
}
static void F_61 ( struct V_17 * V_18 ,
int V_77 ,
struct V_78 * V_79 )
{
struct V_74 * V_75 ;
V_75 = V_77 ? F_62 ( & V_18 -> V_77 ) :
F_62 ( & V_18 -> V_80 ) ;
F_63 ( & V_79 -> V_81 ) ;
V_75 -> V_82 = 1 ;
F_64 ( & V_79 -> V_81 ) ;
F_59 ( V_75 ) ;
}
static void F_65 ( struct V_17 * V_18 ,
struct V_74 * V_75 ,
void (* F_66) ( unsigned long ) )
{
F_67 ( & V_75 -> V_76 ) ;
V_75 -> V_76 . V_83 = ( long ) V_18 ;
V_75 -> V_76 . V_84 = F_66 ;
V_75 -> V_76 . V_85 = V_86 ;
}
static void F_68 ( struct V_17 * V_18 , int V_77 )
{
struct V_74 * V_75 ;
if ( V_77 )
F_49 () ;
V_75 = V_77 ? F_62 ( & V_18 -> V_77 ) :
F_62 ( & V_18 -> V_80 ) ;
F_65 ( V_18 , V_75 , V_87 ) ;
}
static int F_69 ( struct V_17 * V_18 ,
int V_88 )
{
struct V_3 * V_4 ;
unsigned int V_89 = 0 , V_90 = 0 , div = 0 , V_91 = 0 ;
struct V_92 V_93 ;
int V_94 ;
T_4 V_95 ;
F_70 () ;
V_4 = F_71 ( F_72 ( & V_18 -> V_25 ) , V_18 -> V_96 ) ;
if ( F_2 ( ! V_4 ) ) {
F_73 () ;
return V_97 ;
}
V_94 = F_74 ( V_4 , & V_93 ) ;
V_95 = F_75 ( & V_93 ) ;
F_73 () ;
if ( ! V_94 ) {
if ( V_95 < V_98 || V_95 == V_99 ) {
return V_97 ;
} else {
V_90 = 1 ;
div = V_95 / 1000 ;
}
}
V_89 = ( V_88 * 8 ) / ( 1024 * 1024 ) ;
if ( div )
V_89 /= div ;
V_91 = V_89 * V_90 ;
if ( div )
return V_91 + 1 ;
return V_91 ;
}
static void F_76 ( struct V_74 * V_100 ,
union V_101 * V_102 )
{
V_100 -> V_103 = V_102 -> V_104 . V_105 ;
}
static void F_77 ( struct V_17 * V_18 ,
struct V_64 * V_65 ,
struct V_106 * V_70 ,
union V_101 * V_102 , int V_77 )
{
struct V_74 * V_100 = F_62 ( V_65 ) ;
struct V_107 * V_108 ;
memset ( V_100 , 0x0 , sizeof( * V_100 ) ) ;
V_100 -> V_109 = 1 ;
V_100 -> V_110 = V_70 ;
V_108 = (struct V_107 * ) V_70 [ 0 ] . V_71 ;
V_100 -> V_111 = V_70 [ 0 ] . V_71 ;
V_100 -> V_112 = V_102 -> V_104 . V_113 ;
V_100 -> V_114 = V_102 -> V_104 . V_115 ;
V_100 -> V_116 = V_18 -> V_117 ;
V_100 -> V_118 = V_18 -> V_36 ;
V_100 -> V_119 = 0 ;
V_18 -> V_120 . V_121 . V_122 = 0 ;
if ( V_102 -> V_104 . V_123 )
V_100 -> V_124 = V_102 -> V_104 . V_123 ;
else
V_100 -> V_124 = F_69 ( V_18 ,
V_102 -> V_104 . V_113 ) ;
V_100 -> V_125 = F_78 ( V_100 -> V_124 ) ;
V_100 -> V_126 = V_102 -> V_104 . V_127 ;
F_76 ( V_100 , V_102 ) ;
F_68 ( V_18 , V_77 ) ;
F_79 ( V_100 , V_108 ) ;
}
static void F_80 ( struct V_74 * V_75 )
{
F_81 ( & V_75 -> V_76 ,
V_86 + V_75 -> V_125 ) ;
V_75 -> V_119 = V_75 -> V_128 ;
}
static void V_87 ( unsigned long V_83 )
{
struct V_17 * V_18 = (struct V_17 * ) V_83 ;
struct V_74 * V_75 = F_62 ( & V_18 -> V_80 ) ;
unsigned int V_129 ;
struct V_107 * V_108 ;
F_43 ( & V_18 -> V_25 . V_130 . V_81 ) ;
V_129 = F_82 ( V_75 ) ;
V_108 = F_83 ( V_75 ) ;
if ( F_2 ( V_75 -> V_82 ) )
goto V_15;
if ( F_84 ( V_108 ) ) {
while ( F_85 ( & V_75 -> V_131 ) ) {
F_86 () ;
}
}
if ( V_75 -> V_119 == V_75 -> V_128 ) {
if ( ! V_129 ) {
F_87 ( V_75 , V_18 , V_132 ) ;
if ( ! F_88 ( V_75 , V_18 ) )
goto V_133;
else
goto V_15;
} else {
if ( F_89 ( V_75 , V_108 ) ) {
goto V_133;
} else {
F_79 ( V_75 , V_108 ) ;
goto V_15;
}
}
}
V_133:
F_80 ( V_75 ) ;
V_15:
F_41 ( & V_18 -> V_25 . V_130 . V_81 ) ;
}
static void F_90 ( struct V_74 * V_134 ,
struct V_107 * V_135 , T_3 V_32 )
{
#if V_136 == 1
T_5 * V_137 , * V_138 ;
V_137 = ( T_5 * ) V_135 ;
V_137 += V_139 ;
V_138 = ( T_5 * ) F_91 ( ( unsigned long ) V_134 -> V_140 ) ;
for (; V_137 < V_138 ; V_137 += V_139 )
F_46 ( F_47 ( V_137 ) ) ;
F_50 () ;
#endif
F_92 ( V_135 ) = V_32 ;
#if V_136 == 1
V_137 = ( T_5 * ) V_135 ;
F_46 ( F_47 ( V_137 ) ) ;
F_50 () ;
#endif
}
static void F_93 ( struct V_74 * V_134 ,
struct V_107 * V_135 ,
struct V_17 * V_18 , unsigned int V_141 )
{
T_3 V_32 = V_142 | V_141 ;
struct V_143 * V_144 ;
struct V_145 * V_38 = & V_135 -> V_146 . V_147 ;
if ( V_18 -> V_120 . V_121 . V_148 )
V_32 |= V_149 ;
V_144 = (struct V_143 * ) V_134 -> V_150 ;
V_144 -> V_151 = 0 ;
if ( F_84 ( V_135 ) ) {
V_38 -> V_152 . V_153 = V_144 -> V_58 ;
V_38 -> V_152 . V_154 = V_144 -> V_63 ;
} else {
struct V_43 V_44 ;
F_94 ( & V_44 ) ;
V_38 -> V_152 . V_153 = V_44 . V_59 ;
V_38 -> V_152 . V_154 = V_44 . V_61 ;
}
F_50 () ;
F_90 ( V_134 , V_135 , V_32 ) ;
V_134 -> V_128 = F_95 ( V_134 ) ;
}
static void F_96 ( struct V_74 * V_75 )
{
V_75 -> V_155 = 0 ;
}
static void F_79 ( struct V_74 * V_134 ,
struct V_107 * V_135 )
{
struct V_43 V_44 ;
struct V_145 * V_38 = & V_135 -> V_146 . V_147 ;
F_52 () ;
F_97 ( V_135 ) = V_134 -> V_109 ++ ;
F_84 ( V_135 ) = 0 ;
F_98 ( V_135 ) = F_99 ( V_134 -> V_126 ) ;
F_94 ( & V_44 ) ;
V_38 -> V_156 . V_153 = V_44 . V_59 ;
V_38 -> V_156 . V_154 = V_44 . V_61 ;
V_134 -> V_111 = ( char * ) V_135 ;
V_134 -> V_157 = V_134 -> V_111 + F_99 ( V_134 -> V_126 ) ;
F_100 ( V_135 ) = ( T_3 ) F_99 ( V_134 -> V_126 ) ;
F_101 ( V_135 ) = V_158 ;
V_135 -> V_118 = V_134 -> V_118 ;
V_134 -> V_150 = V_134 -> V_157 ;
V_134 -> V_140 = V_134 -> V_111 + V_134 -> V_112 ;
F_96 ( V_134 ) ;
F_80 ( V_134 ) ;
F_50 () ;
}
static void F_102 ( struct V_74 * V_75 ,
struct V_17 * V_18 )
{
V_75 -> V_155 = 1 ;
V_18 -> V_120 . V_121 . V_122 ++ ;
}
static void * F_88 ( struct V_74 * V_75 ,
struct V_17 * V_18 )
{
struct V_107 * V_108 ;
F_52 () ;
V_108 = F_83 ( V_75 ) ;
if ( V_142 & F_92 ( V_108 ) ) {
F_102 ( V_75 , V_18 ) ;
return NULL ;
}
F_79 ( V_75 , V_108 ) ;
return ( void * ) V_75 -> V_157 ;
}
static void F_87 ( struct V_74 * V_75 ,
struct V_17 * V_18 , unsigned int V_32 )
{
struct V_107 * V_108 = F_83 ( V_75 ) ;
if ( F_13 ( V_159 == F_92 ( V_108 ) ) ) {
if ( ! ( V_32 & V_132 ) ) {
while ( F_85 ( & V_75 -> V_131 ) ) {
F_86 () ;
}
}
F_93 ( V_75 , V_108 , V_18 , V_32 ) ;
return;
}
}
static int F_89 ( struct V_74 * V_75 ,
struct V_107 * V_108 )
{
return V_142 & F_92 ( V_108 ) ;
}
static int F_82 ( struct V_74 * V_75 )
{
return V_75 -> V_155 ;
}
static void F_103 ( struct V_64 * V_65 )
{
struct V_74 * V_75 = F_62 ( V_65 ) ;
F_104 ( & V_75 -> V_131 ) ;
}
static void F_105 ( struct V_74 * V_75 ,
struct V_143 * V_160 )
{
V_160 -> V_161 . V_162 = F_106 ( V_75 -> V_2 ) ;
}
static void F_107 ( struct V_74 * V_75 ,
struct V_143 * V_160 )
{
V_160 -> V_161 . V_162 = 0 ;
}
static void F_108 ( struct V_74 * V_75 ,
struct V_143 * V_160 )
{
if ( F_109 ( V_75 -> V_2 ) ) {
V_160 -> V_161 . V_163 = F_110 ( V_75 -> V_2 ) ;
V_160 -> V_161 . V_164 = F_111 ( V_75 -> V_2 -> V_165 ) ;
V_160 -> V_39 = V_166 | V_167 ;
} else {
V_160 -> V_161 . V_163 = 0 ;
V_160 -> V_161 . V_164 = 0 ;
V_160 -> V_39 = V_168 ;
}
}
static void F_112 ( struct V_74 * V_75 ,
struct V_143 * V_160 )
{
V_160 -> V_161 . V_169 = 0 ;
F_108 ( V_75 , V_160 ) ;
if ( V_75 -> V_103 & V_170 )
F_105 ( V_75 , V_160 ) ;
else
F_107 ( V_75 , V_160 ) ;
}
static void F_113 ( char * V_171 ,
struct V_74 * V_75 ,
struct V_107 * V_108 ,
unsigned int V_172 )
{
struct V_143 * V_160 ;
V_160 = (struct V_143 * ) V_171 ;
V_160 -> V_151 = F_114 ( V_172 ) ;
V_75 -> V_150 = V_171 ;
V_75 -> V_157 += F_114 ( V_172 ) ;
F_98 ( V_108 ) += F_114 ( V_172 ) ;
F_84 ( V_108 ) += 1 ;
F_115 ( & V_75 -> V_131 ) ;
F_112 ( V_75 , V_160 ) ;
}
static void * F_116 ( struct V_17 * V_18 ,
struct V_1 * V_2 ,
int V_32 ,
unsigned int V_172
)
{
struct V_74 * V_75 ;
struct V_107 * V_108 ;
char * V_171 , * V_138 ;
V_75 = F_62 ( & V_18 -> V_80 ) ;
V_108 = F_83 ( V_75 ) ;
if ( F_82 ( V_75 ) ) {
if ( F_89 ( V_75 , V_108 ) ) {
return NULL ;
} else {
F_79 ( V_75 , V_108 ) ;
}
}
F_117 () ;
V_171 = V_75 -> V_157 ;
V_75 -> V_2 = V_2 ;
V_138 = ( char * ) V_108 + V_75 -> V_112 ;
if ( V_171 + F_114 ( V_172 ) < V_138 ) {
F_113 ( V_171 , V_75 , V_108 , V_172 ) ;
return ( void * ) V_171 ;
}
F_87 ( V_75 , V_18 , 0 ) ;
V_171 = ( char * ) F_88 ( V_75 , V_18 ) ;
if ( V_171 ) {
V_108 = F_83 ( V_75 ) ;
F_113 ( V_171 , V_75 , V_108 , V_172 ) ;
return ( void * ) V_171 ;
}
return NULL ;
}
static void * F_118 ( struct V_17 * V_18 ,
struct V_1 * V_2 ,
int V_32 , unsigned int V_172 )
{
char * V_171 = NULL ;
switch ( V_18 -> V_36 ) {
case V_37 :
case V_40 :
V_171 = F_57 ( V_18 , & V_18 -> V_80 ,
V_18 -> V_80 . V_73 , V_32 ) ;
return V_171 ;
case V_42 :
return F_116 ( V_18 , V_2 , V_32 , V_172 ) ;
default:
F_48 ( 1 , L_2 ) ;
F_49 () ;
return NULL ;
}
}
static void * F_119 ( struct V_17 * V_18 ,
struct V_64 * V_65 ,
unsigned int V_173 ,
int V_32 )
{
struct V_74 * V_75 = F_62 ( V_65 ) ;
struct V_107 * V_108 = F_120 ( V_75 , V_173 ) ;
if ( V_32 != F_92 ( V_108 ) )
return NULL ;
return V_108 ;
}
static int F_121 ( struct V_64 * V_65 )
{
unsigned int V_150 ;
if ( V_65 -> V_174 . V_128 )
V_150 = V_65 -> V_174 . V_128 - 1 ;
else
V_150 = V_65 -> V_174 . V_114 - 1 ;
return V_150 ;
}
static void * F_122 ( struct V_17 * V_18 ,
struct V_64 * V_65 ,
int V_32 )
{
unsigned int V_175 = F_121 ( V_65 ) ;
return F_119 ( V_18 , V_65 , V_175 , V_32 ) ;
}
static void * F_123 ( struct V_17 * V_18 ,
struct V_64 * V_65 ,
int V_32 )
{
if ( V_18 -> V_36 <= V_40 )
return F_124 ( V_18 , V_65 , V_32 ) ;
return F_122 ( V_18 , V_65 , V_32 ) ;
}
static void F_125 ( struct V_17 * V_18 ,
struct V_64 * V_65 )
{
switch ( V_18 -> V_36 ) {
case V_37 :
case V_40 :
return F_126 ( V_65 ) ;
case V_42 :
default:
F_48 ( 1 , L_1 ) ;
F_49 () ;
return;
}
}
static void * F_124 ( struct V_17 * V_18 ,
struct V_64 * V_65 ,
int V_32 )
{
unsigned int V_175 = V_65 -> V_73 ? V_65 -> V_73 - 1 : V_65 -> V_176 ;
return F_57 ( V_18 , V_65 , V_175 , V_32 ) ;
}
static void F_126 ( struct V_64 * V_177 )
{
V_177 -> V_73 = V_177 -> V_73 != V_177 -> V_176 ? V_177 -> V_73 + 1 : 0 ;
}
static void F_127 ( struct V_64 * V_65 )
{
F_128 ( * V_65 -> V_178 ) ;
}
static void F_129 ( struct V_64 * V_65 )
{
F_130 ( * V_65 -> V_178 ) ;
}
static unsigned int F_131 ( const struct V_64 * V_65 )
{
unsigned int V_179 = 0 ;
int V_180 ;
if ( V_65 -> V_178 == NULL )
return 0 ;
F_132 (cpu)
V_179 += * F_133 ( V_65 -> V_178 , V_180 ) ;
return V_179 ;
}
static int F_134 ( struct V_17 * V_18 )
{
V_18 -> V_80 . V_178 = NULL ;
V_18 -> V_77 . V_178 = F_135 (unsigned int) ;
if ( F_2 ( V_18 -> V_77 . V_178 == NULL ) )
return - V_181 ;
return 0 ;
}
static void F_136 ( struct V_17 * V_18 )
{
F_137 ( V_18 -> V_77 . V_178 ) ;
}
static bool F_138 ( struct V_17 * V_18 , struct V_1 * V_2 )
{
struct V_24 * V_25 = & V_18 -> V_25 ;
bool V_182 ;
if ( V_18 -> V_28 . F_66 != V_183 )
return ( F_85 ( & V_25 -> V_184 ) + V_2 -> V_185 )
<= V_25 -> V_186 ;
F_43 ( & V_25 -> V_130 . V_81 ) ;
if ( V_18 -> V_36 == V_42 )
V_182 = F_119 ( V_18 , & V_18 -> V_80 ,
V_18 -> V_80 . V_174 . V_128 ,
V_159 ) ;
else
V_182 = F_57 ( V_18 , & V_18 -> V_80 ,
V_18 -> V_80 . V_73 ,
V_159 ) ;
F_41 ( & V_25 -> V_130 . V_81 ) ;
return V_182 ;
}
static void F_139 ( struct V_24 * V_25 )
{
F_140 ( & V_25 -> V_187 ) ;
F_141 ( F_85 ( & V_25 -> V_184 ) ) ;
F_141 ( F_85 ( & V_25 -> V_188 ) ) ;
if ( ! F_142 ( V_25 , V_189 ) ) {
F_143 ( L_3 , V_25 ) ;
return;
}
F_144 ( V_25 ) ;
}
static int F_145 ( struct V_190 * V_191 , unsigned int V_192 )
{
int V_193 = F_85 ( & V_191 -> V_194 ) + 1 ;
if ( V_193 >= V_192 )
V_193 = 0 ;
return V_193 ;
}
static unsigned int F_146 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
return F_147 ( V_2 -> V_195 , V_192 ) ;
}
static unsigned int F_148 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
int V_196 , V_197 ;
V_196 = F_85 ( & V_191 -> V_194 ) ;
while ( ( V_197 = F_149 ( & V_191 -> V_194 , V_196 ,
F_145 ( V_191 , V_192 ) ) ) != V_196 )
V_196 = V_197 ;
return V_196 ;
}
static unsigned int F_150 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
return F_151 () % V_192 ;
}
static unsigned int F_152 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
return F_153 ( V_192 ) ;
}
static unsigned int F_154 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_173 , unsigned int V_198 ,
unsigned int V_192 )
{
unsigned int V_199 , V_200 ;
V_199 = V_200 = F_155 ( int , V_191 -> V_201 [ V_173 ] , V_192 - 1 ) ;
do {
if ( V_199 != V_198 && F_138 ( F_33 ( V_191 -> V_202 [ V_199 ] ) , V_2 ) ) {
if ( V_199 != V_200 )
V_191 -> V_201 [ V_173 ] = V_199 ;
return V_199 ;
}
if ( ++ V_199 == V_192 )
V_199 = 0 ;
} while ( V_199 != V_200 );
return V_173 ;
}
static unsigned int F_156 ( struct V_190 * V_191 ,
struct V_1 * V_2 ,
unsigned int V_192 )
{
return F_9 ( V_2 ) % V_192 ;
}
static bool F_157 ( struct V_190 * V_191 , T_2 V_203 )
{
return V_191 -> V_45 & ( V_203 >> 8 ) ;
}
static int F_158 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_190 * V_191 = V_205 -> V_207 ;
unsigned int V_192 = V_191 -> V_208 ;
struct V_17 * V_18 ;
unsigned int V_173 ;
if ( ! F_159 ( F_160 ( V_4 ) , F_161 ( & V_191 -> V_209 ) ) ||
! V_192 ) {
F_5 ( V_2 ) ;
return 0 ;
}
switch ( V_191 -> type ) {
case V_210 :
default:
if ( F_157 ( V_191 , V_211 ) ) {
V_2 = F_162 ( V_2 , V_212 ) ;
if ( ! V_2 )
return 0 ;
}
F_106 ( V_2 ) ;
V_173 = F_146 ( V_191 , V_2 , V_192 ) ;
break;
case V_213 :
V_173 = F_148 ( V_191 , V_2 , V_192 ) ;
break;
case V_214 :
V_173 = F_150 ( V_191 , V_2 , V_192 ) ;
break;
case V_215 :
V_173 = F_152 ( V_191 , V_2 , V_192 ) ;
break;
case V_216 :
V_173 = F_156 ( V_191 , V_2 , V_192 ) ;
break;
case V_217 :
V_173 = F_154 ( V_191 , V_2 , 0 , ( unsigned int ) - 1 , V_192 ) ;
break;
}
V_18 = F_33 ( V_191 -> V_202 [ V_173 ] ) ;
if ( F_157 ( V_191 , V_218 ) &&
F_2 ( ! F_138 ( V_18 , V_2 ) ) ) {
V_173 = F_154 ( V_191 , V_2 , V_173 , V_173 , V_192 ) ;
V_18 = F_33 ( V_191 -> V_202 [ V_173 ] ) ;
}
return V_18 -> V_28 . F_66 ( V_2 , V_4 , & V_18 -> V_28 , V_206 ) ;
}
static void F_34 ( struct V_24 * V_25 , struct V_17 * V_18 )
{
struct V_190 * V_191 = V_18 -> V_27 ;
F_43 ( & V_191 -> V_81 ) ;
V_191 -> V_202 [ V_191 -> V_208 ] = V_25 ;
F_50 () ;
V_191 -> V_208 ++ ;
F_41 ( & V_191 -> V_81 ) ;
}
static void F_38 ( struct V_24 * V_25 , struct V_17 * V_18 )
{
struct V_190 * V_191 = V_18 -> V_27 ;
int V_199 ;
F_43 ( & V_191 -> V_81 ) ;
for ( V_199 = 0 ; V_199 < V_191 -> V_208 ; V_199 ++ ) {
if ( V_191 -> V_202 [ V_199 ] == V_25 )
break;
}
F_163 ( V_199 >= V_191 -> V_208 ) ;
V_191 -> V_202 [ V_199 ] = V_191 -> V_202 [ V_191 -> V_208 - 1 ] ;
V_191 -> V_208 -- ;
F_41 ( & V_191 -> V_81 ) ;
}
static bool F_164 ( struct V_204 * V_219 , struct V_24 * V_25 )
{
if ( V_219 -> V_207 == ( void * ) ( (struct V_17 * ) V_25 ) -> V_27 )
return true ;
return false ;
}
static int F_165 ( struct V_24 * V_25 , T_2 V_220 , T_2 V_221 )
{
struct V_17 * V_18 = F_33 ( V_25 ) ;
struct V_190 * V_191 , * V_222 ;
T_5 type = V_221 & 0xff ;
T_5 V_45 = V_221 >> 8 ;
int V_94 ;
switch ( type ) {
case V_217 :
if ( V_221 & V_218 )
return - V_223 ;
case V_210 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
break;
default:
return - V_223 ;
}
if ( ! V_18 -> V_26 )
return - V_223 ;
if ( V_18 -> V_27 )
return - V_224 ;
F_166 ( & V_225 ) ;
V_222 = NULL ;
F_167 (f, &fanout_list, list) {
if ( V_191 -> V_220 == V_220 &&
F_161 ( & V_191 -> V_209 ) == F_72 ( V_25 ) ) {
V_222 = V_191 ;
break;
}
}
V_94 = - V_223 ;
if ( V_222 && V_222 -> V_45 != V_45 )
goto V_15;
if ( ! V_222 ) {
V_94 = - V_226 ;
V_222 = F_168 ( sizeof( * V_222 ) , V_227 ) ;
if ( ! V_222 )
goto V_15;
F_169 ( & V_222 -> V_209 , F_72 ( V_25 ) ) ;
V_222 -> V_220 = V_220 ;
V_222 -> type = type ;
V_222 -> V_45 = V_45 ;
F_170 ( & V_222 -> V_194 , 0 ) ;
F_171 ( & V_222 -> V_228 ) ;
F_172 ( & V_222 -> V_81 ) ;
F_170 ( & V_222 -> V_229 , 0 ) ;
V_222 -> V_28 . type = V_18 -> V_28 . type ;
V_222 -> V_28 . V_4 = V_18 -> V_28 . V_4 ;
V_222 -> V_28 . F_66 = F_158 ;
V_222 -> V_28 . V_207 = V_222 ;
V_222 -> V_28 . V_230 = F_164 ;
F_35 ( & V_222 -> V_28 ) ;
F_173 ( & V_222 -> V_228 , & V_231 ) ;
}
V_94 = - V_223 ;
if ( V_222 -> type == type &&
V_222 -> V_28 . type == V_18 -> V_28 . type &&
V_222 -> V_28 . V_4 == V_18 -> V_28 . V_4 ) {
V_94 = - V_232 ;
if ( F_85 ( & V_222 -> V_229 ) < V_233 ) {
F_39 ( & V_18 -> V_28 ) ;
V_18 -> V_27 = V_222 ;
F_115 ( & V_222 -> V_229 ) ;
F_34 ( V_25 , V_18 ) ;
V_94 = 0 ;
}
}
V_15:
F_174 ( & V_225 ) ;
return V_94 ;
}
static void F_175 ( struct V_24 * V_25 )
{
struct V_17 * V_18 = F_33 ( V_25 ) ;
struct V_190 * V_191 ;
V_191 = V_18 -> V_27 ;
if ( ! V_191 )
return;
F_166 ( & V_225 ) ;
V_18 -> V_27 = NULL ;
if ( F_176 ( & V_191 -> V_229 ) ) {
F_177 ( & V_191 -> V_228 ) ;
F_178 ( & V_191 -> V_28 ) ;
F_179 ( V_191 ) ;
}
F_174 ( & V_225 ) ;
}
static int F_180 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_24 * V_25 ;
struct V_234 * V_235 ;
V_25 = V_205 -> V_207 ;
if ( V_2 -> V_236 == V_237 )
goto V_15;
if ( ! F_159 ( F_160 ( V_4 ) , F_72 ( V_25 ) ) )
goto V_15;
V_2 = F_181 ( V_2 , V_238 ) ;
if ( V_2 == NULL )
goto V_239;
F_182 ( V_2 ) ;
F_183 ( V_2 ) ;
V_235 = & F_184 ( V_2 ) -> V_240 . V_241 ;
F_185 ( V_2 , V_2 -> V_83 - F_186 ( V_2 ) ) ;
V_235 -> V_242 = V_4 -> type ;
F_187 ( V_235 -> V_243 , V_4 -> V_244 , sizeof( V_235 -> V_243 ) ) ;
V_235 -> V_245 = V_2 -> V_246 ;
if ( F_188 ( V_25 , V_2 ) == 0 )
return 0 ;
V_15:
F_5 ( V_2 ) ;
V_239:
return 0 ;
}
static int F_189 ( struct V_247 * V_248 , struct V_249 * V_24 ,
struct V_250 * V_251 , T_6 V_172 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
F_190 ( struct V_234 * , V_252 , V_251 -> V_253 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
T_7 V_254 = 0 ;
int V_94 ;
int V_255 = 0 ;
if ( V_252 ) {
if ( V_251 -> V_256 < sizeof( struct V_257 ) )
return - V_223 ;
if ( V_251 -> V_256 == sizeof( struct V_234 ) )
V_254 = V_252 -> V_245 ;
} else
return - V_258 ;
V_252 -> V_243 [ sizeof( V_252 -> V_243 ) - 1 ] = 0 ;
V_259:
F_18 () ;
V_4 = F_191 ( F_72 ( V_25 ) , V_252 -> V_243 ) ;
V_94 = - V_260 ;
if ( V_4 == NULL )
goto V_261;
V_94 = - V_262 ;
if ( ! ( V_4 -> V_45 & V_263 ) )
goto V_261;
if ( F_2 ( F_142 ( V_25 , V_264 ) ) ) {
if ( ! F_192 ( V_4 ) ) {
V_94 = - V_265 ;
goto V_261;
}
V_255 = 4 ;
}
V_94 = - V_266 ;
if ( V_172 > V_4 -> V_267 + V_4 -> V_268 + V_269 + V_255 )
goto V_261;
if ( ! V_2 ) {
T_6 V_270 = F_193 ( V_4 ) ;
int V_271 = V_4 -> V_272 ;
unsigned int V_273 = V_4 -> V_274 ? V_4 -> V_268 : 0 ;
F_21 () ;
V_2 = F_194 ( V_25 , V_172 + V_270 + V_271 , 0 , V_227 ) ;
if ( V_2 == NULL )
return - V_181 ;
F_195 ( V_2 , V_270 ) ;
F_196 ( V_2 ) ;
if ( V_273 ) {
V_2 -> V_83 -= V_273 ;
V_2 -> V_275 -= V_273 ;
if ( V_172 < V_273 )
F_196 ( V_2 ) ;
}
V_94 = F_197 ( F_198 ( V_2 , V_172 ) , V_251 -> V_276 , V_172 ) ;
if ( V_94 )
goto V_277;
goto V_259;
}
if ( V_172 > ( V_4 -> V_267 + V_4 -> V_268 + V_255 ) ) {
struct V_278 * V_279 ;
F_199 ( V_2 ) ;
V_279 = F_200 ( V_2 ) ;
if ( V_279 -> V_280 != F_201 ( V_281 ) ) {
V_94 = - V_266 ;
goto V_261;
}
}
V_2 -> V_246 = V_254 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_282 = V_25 -> V_283 ;
V_2 -> V_284 = V_25 -> V_285 ;
F_202 ( V_25 , & F_203 ( V_2 ) -> V_286 ) ;
if ( F_2 ( V_255 == 4 ) )
V_2 -> V_287 = 1 ;
F_204 ( V_2 , 0 ) ;
F_205 ( V_2 ) ;
F_21 () ;
return V_172 ;
V_261:
F_21 () ;
V_277:
F_5 ( V_2 ) ;
return V_94 ;
}
static unsigned int F_206 ( const struct V_1 * V_2 ,
const struct V_24 * V_25 ,
unsigned int V_288 )
{
struct V_289 * V_290 ;
F_18 () ;
V_290 = F_19 ( V_25 -> V_289 ) ;
if ( V_290 != NULL )
V_288 = F_207 ( V_290 , V_2 ) ;
F_21 () ;
return V_288 ;
}
static int F_208 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_24 * V_25 ;
struct V_291 * V_292 ;
struct V_17 * V_18 ;
T_5 * V_293 = V_2 -> V_83 ;
int V_294 = V_2 -> V_172 ;
unsigned int V_295 , V_288 ;
if ( V_2 -> V_236 == V_237 )
goto V_296;
V_25 = V_205 -> V_207 ;
V_18 = F_33 ( V_25 ) ;
if ( ! F_159 ( F_160 ( V_4 ) , F_72 ( V_25 ) ) )
goto V_296;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_274 ) {
if ( V_25 -> V_297 != V_298 )
F_185 ( V_2 , V_2 -> V_83 - F_186 ( V_2 ) ) ;
else if ( V_2 -> V_236 == V_299 ) {
F_209 ( V_2 , F_210 ( V_2 ) ) ;
}
}
V_295 = V_2 -> V_172 ;
V_288 = F_206 ( V_2 , V_25 , V_295 ) ;
if ( ! V_288 )
goto V_300;
if ( V_295 > V_288 )
V_295 = V_288 ;
if ( F_85 ( & V_25 -> V_184 ) >= V_25 -> V_186 )
goto V_301;
if ( F_211 ( V_2 ) ) {
struct V_1 * V_302 = F_212 ( V_2 , V_238 ) ;
if ( V_302 == NULL )
goto V_301;
if ( V_293 != V_2 -> V_83 ) {
V_2 -> V_83 = V_293 ;
V_2 -> V_172 = V_294 ;
}
F_213 ( V_2 ) ;
V_2 = V_302 ;
}
F_214 ( sizeof( * F_184 ( V_2 ) ) + V_303 - 8 >
sizeof( V_2 -> V_304 ) ) ;
V_292 = & F_184 ( V_2 ) -> V_240 . V_305 ;
V_292 -> V_306 = V_307 ;
V_292 -> V_308 = V_4 -> type ;
V_292 -> V_309 = V_2 -> V_246 ;
V_292 -> V_310 = V_2 -> V_236 ;
if ( F_2 ( V_18 -> V_311 ) )
V_292 -> V_312 = V_206 -> V_96 ;
else
V_292 -> V_312 = V_4 -> V_96 ;
V_292 -> V_313 = F_215 ( V_2 , V_292 -> V_314 ) ;
F_184 ( V_2 ) -> V_315 = V_2 -> V_172 ;
if ( F_216 ( V_2 , V_295 ) )
goto V_301;
F_217 ( V_2 , V_25 ) ;
V_2 -> V_4 = NULL ;
F_182 ( V_2 ) ;
F_183 ( V_2 ) ;
F_43 ( & V_25 -> V_130 . V_81 ) ;
V_18 -> V_120 . V_316 . V_317 ++ ;
V_2 -> V_318 = F_85 ( & V_25 -> V_319 ) ;
F_218 ( & V_25 -> V_130 , V_2 ) ;
F_41 ( & V_25 -> V_130 . V_81 ) ;
V_25 -> V_320 ( V_25 , V_2 -> V_172 ) ;
return 0 ;
V_301:
F_43 ( & V_25 -> V_130 . V_81 ) ;
V_18 -> V_120 . V_316 . V_148 ++ ;
F_115 ( & V_25 -> V_319 ) ;
F_41 ( & V_25 -> V_130 . V_81 ) ;
V_300:
if ( V_293 != V_2 -> V_83 && F_211 ( V_2 ) ) {
V_2 -> V_83 = V_293 ;
V_2 -> V_172 = V_294 ;
}
V_296:
F_213 ( V_2 ) ;
return 0 ;
}
static int V_183 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_24 * V_25 ;
struct V_17 * V_18 ;
struct V_291 * V_292 ;
union V_33 V_34 ;
T_5 * V_293 = V_2 -> V_83 ;
int V_294 = V_2 -> V_172 ;
unsigned int V_295 , V_288 ;
unsigned long V_32 = V_142 ;
unsigned short V_321 , V_322 , V_116 ;
struct V_1 * V_323 = NULL ;
struct V_43 V_44 ;
T_3 V_56 ;
F_214 ( F_219 ( sizeof( * V_34 . V_41 ) ) != 32 ) ;
F_214 ( F_219 ( sizeof( * V_34 . V_324 ) ) != 48 ) ;
if ( V_2 -> V_236 == V_237 )
goto V_296;
V_25 = V_205 -> V_207 ;
V_18 = F_33 ( V_25 ) ;
if ( ! F_159 ( F_160 ( V_4 ) , F_72 ( V_25 ) ) )
goto V_296;
if ( V_4 -> V_274 ) {
if ( V_25 -> V_297 != V_298 )
F_185 ( V_2 , V_2 -> V_83 - F_186 ( V_2 ) ) ;
else if ( V_2 -> V_236 == V_299 ) {
F_209 ( V_2 , F_210 ( V_2 ) ) ;
}
}
if ( V_2 -> V_325 == V_326 )
V_32 |= V_327 ;
V_295 = V_2 -> V_172 ;
V_288 = F_206 ( V_2 , V_25 , V_295 ) ;
if ( ! V_288 )
goto V_300;
if ( V_295 > V_288 )
V_295 = V_288 ;
if ( V_25 -> V_297 == V_298 ) {
V_321 = V_322 = F_219 ( V_18 -> V_117 ) + 16 +
V_18 -> V_328 ;
} else {
unsigned int V_329 = F_210 ( V_2 ) ;
V_322 = F_219 ( V_18 -> V_117 +
( V_329 < 16 ? 16 : V_329 ) ) +
V_18 -> V_328 ;
V_321 = V_322 - V_329 ;
}
if ( V_18 -> V_36 <= V_40 ) {
if ( V_321 + V_295 > V_18 -> V_80 . V_72 ) {
if ( V_18 -> V_330 &&
F_85 ( & V_25 -> V_184 ) < V_25 -> V_186 ) {
if ( F_211 ( V_2 ) ) {
V_323 = F_212 ( V_2 , V_238 ) ;
} else {
V_323 = F_220 ( V_2 ) ;
V_293 = V_2 -> V_83 ;
}
if ( V_323 )
F_217 ( V_323 , V_25 ) ;
}
V_295 = V_18 -> V_80 . V_72 - V_321 ;
if ( ( int ) V_295 < 0 )
V_295 = 0 ;
}
}
F_43 ( & V_25 -> V_130 . V_81 ) ;
V_34 . V_35 = F_118 ( V_18 , V_2 ,
V_159 , ( V_321 + V_295 ) ) ;
if ( ! V_34 . V_35 )
goto V_331;
if ( V_18 -> V_36 <= V_40 ) {
F_125 ( V_18 , & V_18 -> V_80 ) ;
if ( V_18 -> V_120 . V_316 . V_148 )
V_32 |= V_149 ;
}
V_18 -> V_120 . V_316 . V_317 ++ ;
if ( V_323 ) {
V_32 |= V_332 ;
F_218 ( & V_25 -> V_130 , V_323 ) ;
}
F_41 ( & V_25 -> V_130 . V_81 ) ;
F_221 ( V_2 , 0 , V_34 . V_35 + V_321 , V_295 ) ;
if ( ! ( V_56 = F_53 ( V_2 , & V_44 , V_18 -> V_57 ) ) )
F_94 ( & V_44 ) ;
V_32 |= V_56 ;
switch ( V_18 -> V_36 ) {
case V_37 :
V_34 . V_38 -> V_333 = V_2 -> V_172 ;
V_34 . V_38 -> V_334 = V_295 ;
V_34 . V_38 -> V_335 = V_321 ;
V_34 . V_38 -> V_336 = V_322 ;
V_34 . V_38 -> V_58 = V_44 . V_59 ;
V_34 . V_38 -> V_60 = V_44 . V_61 / V_62 ;
V_116 = sizeof( * V_34 . V_38 ) ;
break;
case V_40 :
V_34 . V_41 -> V_333 = V_2 -> V_172 ;
V_34 . V_41 -> V_334 = V_295 ;
V_34 . V_41 -> V_335 = V_321 ;
V_34 . V_41 -> V_336 = V_322 ;
V_34 . V_41 -> V_58 = V_44 . V_59 ;
V_34 . V_41 -> V_63 = V_44 . V_61 ;
if ( F_109 ( V_2 ) ) {
V_34 . V_41 -> V_163 = F_110 ( V_2 ) ;
V_34 . V_41 -> V_164 = F_111 ( V_2 -> V_165 ) ;
V_32 |= V_166 | V_167 ;
} else {
V_34 . V_41 -> V_163 = 0 ;
V_34 . V_41 -> V_164 = 0 ;
}
memset ( V_34 . V_41 -> V_169 , 0 , sizeof( V_34 . V_41 -> V_169 ) ) ;
V_116 = sizeof( * V_34 . V_41 ) ;
break;
case V_42 :
V_34 . V_324 -> V_39 |= V_32 ;
V_34 . V_324 -> V_333 = V_2 -> V_172 ;
V_34 . V_324 -> V_334 = V_295 ;
V_34 . V_324 -> V_335 = V_321 ;
V_34 . V_324 -> V_336 = V_322 ;
V_34 . V_324 -> V_58 = V_44 . V_59 ;
V_34 . V_324 -> V_63 = V_44 . V_61 ;
memset ( V_34 . V_324 -> V_169 , 0 , sizeof( V_34 . V_324 -> V_169 ) ) ;
V_116 = sizeof( * V_34 . V_324 ) ;
break;
default:
F_49 () ;
}
V_292 = V_34 . V_35 + F_219 ( V_116 ) ;
V_292 -> V_313 = F_215 ( V_2 , V_292 -> V_314 ) ;
V_292 -> V_306 = V_307 ;
V_292 -> V_308 = V_4 -> type ;
V_292 -> V_309 = V_2 -> V_246 ;
V_292 -> V_310 = V_2 -> V_236 ;
if ( F_2 ( V_18 -> V_311 ) )
V_292 -> V_312 = V_206 -> V_96 ;
else
V_292 -> V_312 = V_4 -> V_96 ;
F_117 () ;
#if V_136 == 1
if ( V_18 -> V_36 <= V_40 ) {
T_5 * V_137 , * V_138 ;
V_138 = ( T_5 * ) F_91 ( ( unsigned long ) V_34 . V_35 +
V_321 + V_295 ) ;
for ( V_137 = V_34 . V_35 ; V_137 < V_138 ; V_137 += V_139 )
F_46 ( F_47 ( V_137 ) ) ;
}
F_50 () ;
#endif
if ( V_18 -> V_36 <= V_40 )
F_45 ( V_18 , V_34 . V_35 , V_32 ) ;
else
F_103 ( & V_18 -> V_80 ) ;
V_25 -> V_320 ( V_25 , 0 ) ;
V_300:
if ( V_293 != V_2 -> V_83 && F_211 ( V_2 ) ) {
V_2 -> V_83 = V_293 ;
V_2 -> V_172 = V_294 ;
}
V_296:
F_5 ( V_2 ) ;
return 0 ;
V_331:
V_18 -> V_120 . V_316 . V_148 ++ ;
F_41 ( & V_25 -> V_130 . V_81 ) ;
V_25 -> V_320 ( V_25 , 0 ) ;
F_5 ( V_323 ) ;
goto V_300;
}
static void F_222 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_33 ( V_2 -> V_25 ) ;
if ( F_13 ( V_18 -> V_77 . V_70 ) ) {
void * V_337 ;
T_3 V_44 ;
V_337 = F_203 ( V_2 ) -> V_338 ;
F_129 ( & V_18 -> V_77 ) ;
V_44 = F_56 ( V_18 , V_337 , V_2 ) ;
F_45 ( V_18 , V_337 , V_168 | V_44 ) ;
}
F_223 ( V_2 ) ;
}
static int F_224 ( struct V_17 * V_18 , struct V_1 * V_2 ,
void * V_31 , struct V_3 * V_4 , int V_339 ,
T_7 V_254 , unsigned char * V_340 , int V_341 )
{
union V_33 V_337 ;
int V_342 , V_343 , V_172 , V_333 , V_344 , V_345 ;
struct V_249 * V_24 = V_18 -> V_25 . V_346 ;
struct V_347 * V_347 ;
void * V_83 ;
int V_94 ;
V_337 . V_35 = V_31 ;
V_2 -> V_246 = V_254 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_282 = V_18 -> V_25 . V_283 ;
V_2 -> V_284 = V_18 -> V_25 . V_285 ;
F_202 ( & V_18 -> V_25 , & F_203 ( V_2 ) -> V_286 ) ;
F_203 ( V_2 ) -> V_338 = V_337 . V_35 ;
switch ( V_18 -> V_36 ) {
case V_40 :
V_333 = V_337 . V_41 -> V_333 ;
break;
default:
V_333 = V_337 . V_38 -> V_333 ;
break;
}
if ( F_2 ( V_333 > V_339 ) ) {
F_143 ( L_4 , V_333 , V_339 ) ;
return - V_266 ;
}
F_195 ( V_2 , V_341 ) ;
F_196 ( V_2 ) ;
if ( ! F_26 ( V_18 ) )
F_204 ( V_2 , 0 ) ;
if ( F_2 ( V_18 -> V_348 ) ) {
int V_349 , V_350 , V_351 ;
V_349 = V_18 -> V_117 - sizeof( struct V_291 ) ;
V_350 = V_18 -> V_77 . V_72 - V_333 ;
if ( V_24 -> type == V_298 ) {
switch ( V_18 -> V_36 ) {
case V_40 :
V_351 = V_337 . V_41 -> V_336 ;
break;
default:
V_351 = V_337 . V_38 -> V_336 ;
break;
}
} else {
switch ( V_18 -> V_36 ) {
case V_40 :
V_351 = V_337 . V_41 -> V_335 ;
break;
default:
V_351 = V_337 . V_38 -> V_335 ;
break;
}
}
if ( F_2 ( ( V_351 < V_349 ) || ( V_350 < V_351 ) ) )
return - V_223 ;
V_83 = V_337 . V_35 + V_351 ;
} else {
V_83 = V_337 . V_35 + V_18 -> V_117 - sizeof( struct V_291 ) ;
}
V_342 = V_333 ;
if ( V_24 -> type == V_298 ) {
V_94 = F_225 ( V_2 , V_4 , F_111 ( V_254 ) , V_340 ,
NULL , V_333 ) ;
if ( F_2 ( V_94 < 0 ) )
return - V_223 ;
} else if ( V_4 -> V_268 ) {
if ( F_2 ( V_333 <= V_4 -> V_268 ) ) {
F_143 ( L_5 ,
V_333 , V_4 -> V_268 ) ;
return - V_223 ;
}
F_185 ( V_2 , V_4 -> V_268 ) ;
V_94 = F_226 ( V_2 , 0 , V_83 ,
V_4 -> V_268 ) ;
if ( F_2 ( V_94 ) )
return V_94 ;
V_83 += V_4 -> V_268 ;
V_342 -= V_4 -> V_268 ;
}
V_343 = F_227 ( V_83 ) ;
V_345 = V_139 - V_343 ;
V_172 = ( ( V_342 > V_345 ) ? V_345 : V_342 ) ;
V_2 -> V_352 = V_342 ;
V_2 -> V_172 += V_342 ;
V_2 -> V_185 += V_342 ;
F_228 ( V_342 , & V_18 -> V_25 . V_188 ) ;
while ( F_13 ( V_342 ) ) {
V_344 = F_203 ( V_2 ) -> V_344 ;
if ( F_2 ( V_344 >= V_353 ) ) {
F_143 ( L_6 ,
V_353 ) ;
return - V_354 ;
}
V_347 = F_47 ( V_83 ) ;
V_83 += V_172 ;
F_46 ( V_347 ) ;
F_229 ( V_347 ) ;
F_230 ( V_2 , V_344 , V_347 , V_343 , V_172 ) ;
V_342 -= V_172 ;
V_343 = 0 ;
V_345 = V_139 ;
V_172 = ( ( V_342 > V_345 ) ? V_345 : V_342 ) ;
}
return V_333 ;
}
static int F_231 ( struct V_17 * V_18 , struct V_250 * V_251 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_7 V_254 ;
int V_94 , V_355 = 0 ;
void * V_337 ;
F_190 ( struct V_291 * , V_252 , V_251 -> V_253 ) ;
bool V_356 = ! ( V_251 -> V_357 & V_358 ) ;
int V_333 , V_339 ;
unsigned char * V_340 ;
int V_359 = 0 ;
int V_32 = V_168 ;
int V_341 , V_271 ;
F_166 ( & V_18 -> V_360 ) ;
if ( F_13 ( V_252 == NULL ) ) {
V_4 = F_17 ( V_18 ) ;
V_254 = V_18 -> V_192 ;
V_340 = NULL ;
} else {
V_94 = - V_223 ;
if ( V_251 -> V_256 < sizeof( struct V_291 ) )
goto V_15;
if ( V_251 -> V_256 < ( V_252 -> V_313
+ F_232 ( struct V_291 ,
V_314 ) ) )
goto V_15;
V_254 = V_252 -> V_309 ;
V_340 = V_252 -> V_314 ;
V_4 = F_233 ( F_72 ( & V_18 -> V_25 ) , V_252 -> V_312 ) ;
}
V_94 = - V_361 ;
if ( F_2 ( V_4 == NULL ) )
goto V_15;
V_94 = - V_262 ;
if ( F_2 ( ! ( V_4 -> V_45 & V_263 ) ) )
goto V_362;
V_355 = V_4 -> V_268 ;
V_339 = V_18 -> V_77 . V_72
- ( V_18 -> V_117 - sizeof( struct V_291 ) ) ;
if ( V_339 > V_4 -> V_267 + V_355 )
V_339 = V_4 -> V_267 + V_355 ;
do {
V_337 = F_58 ( V_18 , & V_18 -> V_77 ,
V_363 ) ;
if ( F_2 ( V_337 == NULL ) ) {
if ( V_356 && F_234 () )
F_235 () ;
continue;
}
V_32 = V_363 ;
V_341 = F_193 ( V_4 ) ;
V_271 = V_4 -> V_272 ;
V_2 = F_236 ( & V_18 -> V_25 ,
V_341 + V_271 + sizeof( struct V_291 ) ,
0 , & V_94 ) ;
if ( F_2 ( V_2 == NULL ) )
goto V_364;
V_333 = F_224 ( V_18 , V_2 , V_337 , V_4 , V_339 , V_254 ,
V_340 , V_341 ) ;
if ( F_2 ( V_333 < 0 ) ) {
if ( V_18 -> V_365 ) {
F_45 ( V_18 , V_337 ,
V_168 ) ;
F_126 ( & V_18 -> V_77 ) ;
F_5 ( V_2 ) ;
continue;
} else {
V_32 = V_366 ;
V_94 = V_333 ;
goto V_364;
}
}
F_29 ( V_4 , V_2 ) ;
V_2 -> V_367 = F_222 ;
F_45 ( V_18 , V_337 , V_368 ) ;
F_127 ( & V_18 -> V_77 ) ;
V_32 = V_363 ;
V_94 = V_18 -> V_20 ( V_2 ) ;
if ( F_2 ( V_94 > 0 ) ) {
V_94 = F_237 ( V_94 ) ;
if ( V_94 && F_51 ( V_18 , V_337 ) ==
V_168 ) {
V_2 = NULL ;
goto V_364;
}
V_94 = 0 ;
}
F_126 ( & V_18 -> V_77 ) ;
V_359 += V_333 ;
} while ( F_13 ( ( V_337 != NULL ) ||
( V_356 && F_131 ( & V_18 -> V_77 ) ) ) );
V_94 = V_359 ;
goto V_362;
V_364:
F_45 ( V_18 , V_337 , V_32 ) ;
F_5 ( V_2 ) ;
V_362:
F_238 ( V_4 ) ;
V_15:
F_174 ( & V_18 -> V_360 ) ;
return V_94 ;
}
static struct V_1 * F_239 ( struct V_24 * V_25 , T_6 V_369 ,
T_6 V_355 , T_6 V_172 ,
T_6 V_370 , int V_371 ,
int * V_94 )
{
struct V_1 * V_2 ;
if ( V_369 + V_172 < V_139 || ! V_370 )
V_370 = V_172 ;
V_2 = F_240 ( V_25 , V_369 + V_370 , V_172 - V_370 , V_371 ,
V_94 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_195 ( V_2 , V_355 ) ;
F_198 ( V_2 , V_370 ) ;
V_2 -> V_352 = V_172 - V_370 ;
V_2 -> V_172 += V_172 - V_370 ;
return V_2 ;
}
static int F_241 ( struct V_249 * V_24 , struct V_250 * V_251 , T_6 V_172 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
F_190 ( struct V_291 * , V_252 , V_251 -> V_253 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_7 V_254 ;
unsigned char * V_340 ;
int V_94 , V_355 = 0 ;
struct V_372 V_373 = { 0 } ;
int V_343 = 0 ;
int V_374 ;
struct V_17 * V_18 = F_33 ( V_25 ) ;
unsigned short V_375 = 0 ;
int V_341 , V_271 ;
int V_255 = 0 ;
if ( F_13 ( V_252 == NULL ) ) {
V_4 = F_17 ( V_18 ) ;
V_254 = V_18 -> V_192 ;
V_340 = NULL ;
} else {
V_94 = - V_223 ;
if ( V_251 -> V_256 < sizeof( struct V_291 ) )
goto V_15;
if ( V_251 -> V_256 < ( V_252 -> V_313 + F_232 ( struct V_291 , V_314 ) ) )
goto V_15;
V_254 = V_252 -> V_309 ;
V_340 = V_252 -> V_314 ;
V_4 = F_233 ( F_72 ( V_25 ) , V_252 -> V_312 ) ;
}
V_94 = - V_361 ;
if ( F_2 ( V_4 == NULL ) )
goto V_261;
V_94 = - V_262 ;
if ( F_2 ( ! ( V_4 -> V_45 & V_263 ) ) )
goto V_261;
if ( V_24 -> type == V_376 )
V_355 = V_4 -> V_268 ;
if ( V_18 -> V_377 ) {
V_374 = sizeof( V_373 ) ;
V_94 = - V_223 ;
if ( V_172 < V_374 )
goto V_261;
V_172 -= V_374 ;
V_94 = F_197 ( ( void * ) & V_373 , V_251 -> V_276 ,
V_374 ) ;
if ( V_94 < 0 )
goto V_261;
if ( ( V_373 . V_45 & V_378 ) &&
( V_373 . V_379 + V_373 . V_380 + 2 >
V_373 . V_381 ) )
V_373 . V_381 = V_373 . V_379 +
V_373 . V_380 + 2 ;
V_94 = - V_223 ;
if ( V_373 . V_381 > V_172 )
goto V_261;
if ( V_373 . V_375 != V_382 ) {
switch ( V_373 . V_375 & ~ V_383 ) {
case V_384 :
V_375 = V_385 ;
break;
case V_386 :
V_375 = V_387 ;
break;
case V_388 :
V_375 = V_389 ;
break;
default:
goto V_261;
}
if ( V_373 . V_375 & V_383 )
V_375 |= V_390 ;
if ( V_373 . V_391 == 0 )
goto V_261;
}
}
if ( F_2 ( F_142 ( V_25 , V_264 ) ) ) {
if ( ! F_192 ( V_4 ) ) {
V_94 = - V_265 ;
goto V_261;
}
V_255 = 4 ;
}
V_94 = - V_266 ;
if ( ! V_375 && ( V_172 > V_4 -> V_267 + V_355 + V_269 + V_255 ) )
goto V_261;
V_94 = - V_181 ;
V_341 = F_193 ( V_4 ) ;
V_271 = V_4 -> V_272 ;
V_2 = F_239 ( V_25 , V_341 + V_271 , V_341 , V_172 , V_373 . V_381 ,
V_251 -> V_357 & V_358 , & V_94 ) ;
if ( V_2 == NULL )
goto V_261;
F_242 ( V_2 , V_355 ) ;
V_94 = - V_223 ;
if ( V_24 -> type == V_298 &&
( V_343 = F_225 ( V_2 , V_4 , F_111 ( V_254 ) , V_340 , NULL , V_172 ) ) < 0 )
goto V_277;
V_94 = F_243 ( V_2 , V_343 , V_251 -> V_276 , 0 , V_172 ) ;
if ( V_94 )
goto V_277;
F_202 ( V_25 , & F_203 ( V_2 ) -> V_286 ) ;
if ( ! V_375 && ( V_172 > V_4 -> V_267 + V_355 + V_255 ) ) {
struct V_278 * V_279 ;
F_199 ( V_2 ) ;
V_279 = F_200 ( V_2 ) ;
if ( V_279 -> V_280 != F_201 ( V_281 ) ) {
V_94 = - V_266 ;
goto V_277;
}
}
V_2 -> V_246 = V_254 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_282 = V_25 -> V_283 ;
V_2 -> V_284 = V_25 -> V_285 ;
F_29 ( V_4 , V_2 ) ;
if ( V_18 -> V_377 ) {
if ( V_373 . V_45 & V_378 ) {
if ( ! F_244 ( V_2 , V_373 . V_379 ,
V_373 . V_380 ) ) {
V_94 = - V_223 ;
goto V_277;
}
}
F_203 ( V_2 ) -> V_391 = V_373 . V_391 ;
F_203 ( V_2 ) -> V_375 = V_375 ;
F_203 ( V_2 ) -> V_375 |= V_392 ;
F_203 ( V_2 ) -> V_393 = 0 ;
V_172 += V_374 ;
}
if ( ! F_26 ( V_18 ) )
F_204 ( V_2 , V_355 ) ;
if ( F_2 ( V_255 == 4 ) )
V_2 -> V_287 = 1 ;
V_94 = V_18 -> V_20 ( V_2 ) ;
if ( V_94 > 0 && ( V_94 = F_237 ( V_94 ) ) != 0 )
goto V_261;
F_238 ( V_4 ) ;
return V_172 ;
V_277:
F_5 ( V_2 ) ;
V_261:
if ( V_4 )
F_238 ( V_4 ) ;
V_15:
return V_94 ;
}
static int F_245 ( struct V_247 * V_248 , struct V_249 * V_24 ,
struct V_250 * V_251 , T_6 V_172 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
struct V_17 * V_18 = F_33 ( V_25 ) ;
if ( V_18 -> V_77 . V_70 )
return F_231 ( V_18 , V_251 ) ;
else
return F_241 ( V_24 , V_251 , V_172 ) ;
}
static int F_246 ( struct V_249 * V_24 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
struct V_17 * V_18 ;
struct V_209 * V_209 ;
union V_101 V_102 ;
if ( ! V_25 )
return 0 ;
V_209 = F_72 ( V_25 ) ;
V_18 = F_33 ( V_25 ) ;
F_166 ( & V_209 -> V_394 . V_395 ) ;
F_247 ( V_25 ) ;
F_174 ( & V_209 -> V_394 . V_395 ) ;
F_248 () ;
F_249 ( V_209 , V_25 -> V_396 , - 1 ) ;
F_250 () ;
F_43 ( & V_18 -> V_30 ) ;
F_44 ( V_25 , false ) ;
F_24 ( V_18 ) ;
if ( V_18 -> V_28 . V_4 ) {
F_238 ( V_18 -> V_28 . V_4 ) ;
V_18 -> V_28 . V_4 = NULL ;
}
F_41 ( & V_18 -> V_30 ) ;
F_251 ( V_25 ) ;
if ( V_18 -> V_80 . V_70 ) {
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
F_252 ( V_25 , & V_102 , 1 , 0 ) ;
}
if ( V_18 -> V_77 . V_70 ) {
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
F_252 ( V_25 , & V_102 , 1 , 1 ) ;
}
F_175 ( V_25 ) ;
F_42 () ;
F_253 ( V_25 ) ;
V_24 -> V_25 = NULL ;
F_140 ( & V_25 -> V_130 ) ;
F_136 ( V_18 ) ;
F_254 ( V_25 ) ;
F_255 ( V_25 ) ;
return 0 ;
}
static int F_256 ( struct V_24 * V_25 , struct V_3 * V_4 , T_7 V_254 )
{
struct V_17 * V_18 = F_33 ( V_25 ) ;
const struct V_3 * V_397 ;
T_7 V_398 ;
bool V_399 ;
if ( V_18 -> V_27 ) {
if ( V_4 )
F_238 ( V_4 ) ;
return - V_223 ;
}
F_257 ( V_25 ) ;
F_43 ( & V_18 -> V_30 ) ;
V_398 = V_18 -> V_28 . type ;
V_397 = V_18 -> V_28 . V_4 ;
V_399 = V_398 != V_254 || V_397 != V_4 ;
if ( V_399 ) {
F_44 ( V_25 , true ) ;
V_18 -> V_192 = V_254 ;
V_18 -> V_28 . type = V_254 ;
if ( V_18 -> V_28 . V_4 )
F_238 ( V_18 -> V_28 . V_4 ) ;
V_18 -> V_28 . V_4 = V_4 ;
V_18 -> V_96 = V_4 ? V_4 -> V_96 : 0 ;
F_22 ( V_18 , V_4 ) ;
}
if ( V_254 == 0 || ! V_399 )
goto V_261;
if ( ! V_4 || ( V_4 -> V_45 & V_263 ) ) {
F_32 ( V_25 ) ;
} else {
V_25 -> V_400 = V_262 ;
if ( ! F_142 ( V_25 , V_189 ) )
V_25 -> V_401 ( V_25 ) ;
}
V_261:
F_41 ( & V_18 -> V_30 ) ;
F_258 ( V_25 ) ;
return 0 ;
}
static int F_259 ( struct V_249 * V_24 , struct V_257 * V_402 ,
int V_403 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
char V_244 [ 15 ] ;
struct V_3 * V_4 ;
int V_94 = - V_260 ;
if ( V_403 != sizeof( struct V_257 ) )
return - V_223 ;
F_187 ( V_244 , V_402 -> V_404 , sizeof( V_244 ) ) ;
V_4 = F_260 ( F_72 ( V_25 ) , V_244 ) ;
if ( V_4 )
V_94 = F_256 ( V_25 , V_4 , F_33 ( V_25 ) -> V_192 ) ;
return V_94 ;
}
static int F_261 ( struct V_249 * V_24 , struct V_257 * V_402 , int V_403 )
{
struct V_291 * V_292 = (struct V_291 * ) V_402 ;
struct V_24 * V_25 = V_24 -> V_25 ;
struct V_3 * V_4 = NULL ;
int V_94 ;
if ( V_403 < sizeof( struct V_291 ) )
return - V_223 ;
if ( V_292 -> V_306 != V_307 )
return - V_223 ;
if ( V_292 -> V_312 ) {
V_94 = - V_260 ;
V_4 = F_233 ( F_72 ( V_25 ) , V_292 -> V_312 ) ;
if ( V_4 == NULL )
goto V_15;
}
V_94 = F_256 ( V_25 , V_4 , V_292 -> V_309 ? : F_33 ( V_25 ) -> V_192 ) ;
V_15:
return V_94 ;
}
static int F_262 ( struct V_209 * V_209 , struct V_249 * V_24 , int V_246 ,
int V_405 )
{
struct V_24 * V_25 ;
struct V_17 * V_18 ;
T_7 V_254 = ( V_406 T_7 ) V_246 ;
int V_94 ;
if ( ! F_263 ( V_209 -> V_407 , V_408 ) )
return - V_409 ;
if ( V_24 -> type != V_298 && V_24 -> type != V_376 &&
V_24 -> type != V_410 )
return - V_411 ;
V_24 -> V_412 = V_413 ;
V_94 = - V_181 ;
V_25 = F_264 ( V_209 , V_414 , V_227 , & V_415 ) ;
if ( V_25 == NULL )
goto V_15;
V_24 -> V_6 = & V_416 ;
if ( V_24 -> type == V_410 )
V_24 -> V_6 = & V_417 ;
F_265 ( V_24 , V_25 ) ;
V_18 = F_33 ( V_25 ) ;
V_25 -> V_418 = V_414 ;
V_18 -> V_192 = V_254 ;
V_18 -> V_20 = F_205 ;
V_94 = F_134 ( V_18 ) ;
if ( V_94 )
goto V_419;
F_24 ( V_18 ) ;
V_25 -> V_420 = F_139 ;
F_266 ( V_25 ) ;
F_172 ( & V_18 -> V_30 ) ;
F_267 ( & V_18 -> V_360 ) ;
V_18 -> V_28 . F_66 = F_208 ;
if ( V_24 -> type == V_410 )
V_18 -> V_28 . F_66 = F_180 ;
V_18 -> V_28 . V_207 = V_25 ;
if ( V_254 ) {
V_18 -> V_28 . type = V_254 ;
F_32 ( V_25 ) ;
}
F_166 ( & V_209 -> V_394 . V_395 ) ;
F_268 ( V_25 , & V_209 -> V_394 . V_421 ) ;
F_174 ( & V_209 -> V_394 . V_395 ) ;
F_248 () ;
F_249 ( V_209 , & V_415 , 1 ) ;
F_250 () ;
return 0 ;
V_419:
F_269 ( V_25 ) ;
V_15:
return V_94 ;
}
static int F_270 ( struct V_247 * V_248 , struct V_249 * V_24 ,
struct V_250 * V_251 , T_6 V_172 , int V_45 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
struct V_1 * V_2 ;
int V_422 , V_94 ;
int V_374 = 0 ;
V_94 = - V_223 ;
if ( V_45 & ~ ( V_423 | V_358 | V_424 | V_425 | V_426 ) )
goto V_15;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_45 & V_426 ) {
V_94 = F_271 ( V_25 , V_251 , V_172 ,
V_427 , V_428 ) ;
goto V_15;
}
V_2 = F_272 ( V_25 , V_45 , V_45 & V_358 , & V_94 ) ;
if ( V_2 == NULL )
goto V_15;
if ( F_33 ( V_25 ) -> V_377 ) {
struct V_372 V_373 = { 0 } ;
V_94 = - V_223 ;
V_374 = sizeof( V_373 ) ;
if ( V_172 < V_374 )
goto V_277;
V_172 -= V_374 ;
if ( F_273 ( V_2 ) ) {
struct V_429 * V_430 = F_203 ( V_2 ) ;
V_373 . V_381 = F_274 ( V_2 ) ;
V_373 . V_391 = V_430 -> V_391 ;
if ( V_430 -> V_375 & V_385 )
V_373 . V_375 = V_384 ;
else if ( V_430 -> V_375 & V_387 )
V_373 . V_375 = V_386 ;
else if ( V_430 -> V_375 & V_389 )
V_373 . V_375 = V_388 ;
else if ( V_430 -> V_375 & V_431 )
goto V_277;
else
F_49 () ;
if ( V_430 -> V_375 & V_390 )
V_373 . V_375 |= V_383 ;
} else
V_373 . V_375 = V_382 ;
if ( V_2 -> V_325 == V_326 ) {
V_373 . V_45 = V_378 ;
V_373 . V_379 = F_275 ( V_2 ) ;
V_373 . V_380 = V_2 -> V_380 ;
} else if ( V_2 -> V_325 == V_432 ) {
V_373 . V_45 = V_433 ;
}
V_94 = F_276 ( V_251 -> V_276 , ( void * ) & V_373 ,
V_374 ) ;
if ( V_94 < 0 )
goto V_277;
}
V_422 = V_2 -> V_172 ;
if ( V_422 > V_172 ) {
V_422 = V_172 ;
V_251 -> V_357 |= V_424 ;
}
V_94 = F_277 ( V_2 , 0 , V_251 -> V_276 , V_422 ) ;
if ( V_94 )
goto V_277;
F_278 ( V_251 , V_25 , V_2 ) ;
if ( V_251 -> V_253 ) {
if ( V_24 -> type == V_410 ) {
F_279 ( sizeof( struct V_234 ) ) ;
V_251 -> V_256 = sizeof( struct V_234 ) ;
} else {
struct V_291 * V_292 = & F_184 ( V_2 ) -> V_240 . V_305 ;
V_251 -> V_256 = V_292 -> V_313 +
F_232 ( struct V_291 , V_314 ) ;
}
memcpy ( V_251 -> V_253 , & F_184 ( V_2 ) -> V_240 ,
V_251 -> V_256 ) ;
}
if ( F_33 ( V_25 ) -> V_434 ) {
struct V_435 V_436 ;
V_436 . V_39 = V_142 ;
if ( V_2 -> V_325 == V_326 )
V_436 . V_39 |= V_327 ;
V_436 . V_333 = F_184 ( V_2 ) -> V_315 ;
V_436 . V_334 = V_2 -> V_172 ;
V_436 . V_335 = 0 ;
V_436 . V_336 = F_210 ( V_2 ) ;
if ( F_109 ( V_2 ) ) {
V_436 . V_163 = F_110 ( V_2 ) ;
V_436 . V_164 = F_111 ( V_2 -> V_165 ) ;
V_436 . V_39 |= V_166 | V_167 ;
} else {
V_436 . V_163 = 0 ;
V_436 . V_164 = 0 ;
}
F_280 ( V_251 , V_427 , V_437 , sizeof( V_436 ) , & V_436 ) ;
}
V_94 = V_374 + ( ( V_45 & V_424 ) ? V_2 -> V_172 : V_422 ) ;
V_277:
F_281 ( V_25 , V_2 ) ;
V_15:
return V_94 ;
}
static int F_282 ( struct V_249 * V_24 , struct V_257 * V_402 ,
int * V_438 , int V_439 )
{
struct V_3 * V_4 ;
struct V_24 * V_25 = V_24 -> V_25 ;
if ( V_439 )
return - V_440 ;
V_402 -> V_441 = V_307 ;
memset ( V_402 -> V_404 , 0 , sizeof( V_402 -> V_404 ) ) ;
F_18 () ;
V_4 = F_283 ( F_72 ( V_25 ) , F_33 ( V_25 ) -> V_96 ) ;
if ( V_4 )
F_187 ( V_402 -> V_404 , V_4 -> V_244 , sizeof( V_402 -> V_404 ) ) ;
F_21 () ;
* V_438 = sizeof( * V_402 ) ;
return 0 ;
}
static int F_284 ( struct V_249 * V_24 , struct V_257 * V_402 ,
int * V_438 , int V_439 )
{
struct V_3 * V_4 ;
struct V_24 * V_25 = V_24 -> V_25 ;
struct V_17 * V_18 = F_33 ( V_25 ) ;
F_190 ( struct V_291 * , V_292 , V_402 ) ;
if ( V_439 )
return - V_440 ;
V_292 -> V_306 = V_307 ;
V_292 -> V_312 = V_18 -> V_96 ;
V_292 -> V_309 = V_18 -> V_192 ;
V_292 -> V_310 = 0 ;
F_18 () ;
V_4 = F_283 ( F_72 ( V_25 ) , V_18 -> V_96 ) ;
if ( V_4 ) {
V_292 -> V_308 = V_4 -> type ;
V_292 -> V_313 = V_4 -> V_403 ;
memcpy ( V_292 -> V_314 , V_4 -> V_442 , V_4 -> V_403 ) ;
} else {
V_292 -> V_308 = 0 ;
V_292 -> V_313 = 0 ;
}
F_21 () ;
* V_438 = F_232 ( struct V_291 , V_314 ) + V_292 -> V_313 ;
return 0 ;
}
static int F_285 ( struct V_3 * V_4 , struct V_443 * V_199 ,
int V_444 )
{
switch ( V_199 -> type ) {
case V_445 :
if ( V_199 -> V_446 != V_4 -> V_403 )
return - V_223 ;
if ( V_444 > 0 )
return F_286 ( V_4 , V_199 -> V_340 ) ;
else
return F_287 ( V_4 , V_199 -> V_340 ) ;
break;
case V_447 :
return F_288 ( V_4 , V_444 ) ;
break;
case V_448 :
return F_289 ( V_4 , V_444 ) ;
break;
case V_449 :
if ( V_199 -> V_446 != V_4 -> V_403 )
return - V_223 ;
if ( V_444 > 0 )
return F_290 ( V_4 , V_199 -> V_340 ) ;
else
return F_291 ( V_4 , V_199 -> V_340 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_292 ( struct V_3 * V_4 , struct V_443 * V_199 , int V_444 )
{
for ( ; V_199 ; V_199 = V_199 -> V_201 ) {
if ( V_199 -> V_96 == V_4 -> V_96 )
F_285 ( V_4 , V_199 , V_444 ) ;
}
}
static int F_293 ( struct V_24 * V_25 , struct V_450 * V_451 )
{
struct V_17 * V_18 = F_33 ( V_25 ) ;
struct V_443 * V_452 , * V_199 ;
struct V_3 * V_4 ;
int V_94 ;
F_70 () ;
V_94 = - V_260 ;
V_4 = F_71 ( F_72 ( V_25 ) , V_451 -> V_453 ) ;
if ( ! V_4 )
goto V_454;
V_94 = - V_223 ;
if ( V_451 -> V_455 > V_4 -> V_403 )
goto V_454;
V_94 = - V_181 ;
V_199 = F_294 ( sizeof( * V_199 ) , V_227 ) ;
if ( V_199 == NULL )
goto V_454;
V_94 = 0 ;
for ( V_452 = V_18 -> V_456 ; V_452 ; V_452 = V_452 -> V_201 ) {
if ( V_452 -> V_96 == V_451 -> V_453 &&
V_452 -> type == V_451 -> V_457 &&
V_452 -> V_446 == V_451 -> V_455 &&
memcmp ( V_452 -> V_340 , V_451 -> V_458 , V_452 -> V_446 ) == 0 ) {
V_452 -> V_459 ++ ;
F_179 ( V_199 ) ;
goto V_454;
}
}
V_199 -> type = V_451 -> V_457 ;
V_199 -> V_96 = V_451 -> V_453 ;
V_199 -> V_446 = V_451 -> V_455 ;
memcpy ( V_199 -> V_340 , V_451 -> V_458 , V_199 -> V_446 ) ;
V_199 -> V_459 = 1 ;
V_199 -> V_201 = V_18 -> V_456 ;
V_18 -> V_456 = V_199 ;
V_94 = F_285 ( V_4 , V_199 , 1 ) ;
if ( V_94 ) {
V_18 -> V_456 = V_199 -> V_201 ;
F_179 ( V_199 ) ;
}
V_454:
F_73 () ;
return V_94 ;
}
static int F_295 ( struct V_24 * V_25 , struct V_450 * V_451 )
{
struct V_443 * V_452 , * * V_460 ;
F_70 () ;
for ( V_460 = & F_33 ( V_25 ) -> V_456 ; ( V_452 = * V_460 ) != NULL ; V_460 = & V_452 -> V_201 ) {
if ( V_452 -> V_96 == V_451 -> V_453 &&
V_452 -> type == V_451 -> V_457 &&
V_452 -> V_446 == V_451 -> V_455 &&
memcmp ( V_452 -> V_340 , V_451 -> V_458 , V_452 -> V_446 ) == 0 ) {
if ( -- V_452 -> V_459 == 0 ) {
struct V_3 * V_4 ;
* V_460 = V_452 -> V_201 ;
V_4 = F_71 ( F_72 ( V_25 ) , V_452 -> V_96 ) ;
if ( V_4 )
F_285 ( V_4 , V_452 , - 1 ) ;
F_179 ( V_452 ) ;
}
F_73 () ;
return 0 ;
}
}
F_73 () ;
return - V_461 ;
}
static void F_251 ( struct V_24 * V_25 )
{
struct V_17 * V_18 = F_33 ( V_25 ) ;
struct V_443 * V_452 ;
if ( ! V_18 -> V_456 )
return;
F_70 () ;
while ( ( V_452 = V_18 -> V_456 ) != NULL ) {
struct V_3 * V_4 ;
V_18 -> V_456 = V_452 -> V_201 ;
V_4 = F_71 ( F_72 ( V_25 ) , V_452 -> V_96 ) ;
if ( V_4 != NULL )
F_285 ( V_4 , V_452 , - 1 ) ;
F_179 ( V_452 ) ;
}
F_73 () ;
}
static int
F_296 ( struct V_249 * V_24 , int V_462 , int V_463 , char T_8 * V_464 , unsigned int V_465 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
struct V_17 * V_18 = F_33 ( V_25 ) ;
int V_12 ;
if ( V_462 != V_427 )
return - V_466 ;
switch ( V_463 ) {
case V_467 :
case V_468 :
{
struct V_450 V_451 ;
int V_172 = V_465 ;
memset ( & V_451 , 0 , sizeof( V_451 ) ) ;
if ( V_172 < sizeof( struct V_469 ) )
return - V_223 ;
if ( V_172 > sizeof( V_451 ) )
V_172 = sizeof( V_451 ) ;
if ( F_297 ( & V_451 , V_464 , V_172 ) )
return - V_354 ;
if ( V_172 < ( V_451 . V_455 + F_232 ( struct V_469 , V_458 ) ) )
return - V_223 ;
if ( V_463 == V_467 )
V_12 = F_293 ( V_25 , & V_451 ) ;
else
V_12 = F_295 ( V_25 , & V_451 ) ;
return V_12 ;
}
case V_470 :
case V_471 :
{
union V_101 V_102 ;
int V_172 ;
switch ( V_18 -> V_36 ) {
case V_37 :
case V_40 :
V_172 = sizeof( V_102 . V_472 ) ;
break;
case V_42 :
default:
V_172 = sizeof( V_102 . V_104 ) ;
break;
}
if ( V_465 < V_172 )
return - V_223 ;
if ( F_33 ( V_25 ) -> V_377 )
return - V_223 ;
if ( F_297 ( & V_102 . V_472 , V_464 , V_172 ) )
return - V_354 ;
return F_252 ( V_25 , & V_102 , 0 ,
V_463 == V_471 ) ;
}
case V_473 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
F_33 ( V_25 ) -> V_330 = V_474 ;
return 0 ;
}
case V_475 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( V_18 -> V_80 . V_70 || V_18 -> V_77 . V_70 )
return - V_476 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
switch ( V_474 ) {
case V_37 :
case V_40 :
case V_42 :
V_18 -> V_36 = V_474 ;
return 0 ;
default:
return - V_223 ;
}
}
case V_477 :
{
unsigned int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( V_18 -> V_80 . V_70 || V_18 -> V_77 . V_70 )
return - V_476 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_18 -> V_328 = V_474 ;
return 0 ;
}
case V_478 :
{
unsigned int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( V_18 -> V_80 . V_70 || V_18 -> V_77 . V_70 )
return - V_476 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_18 -> V_365 = ! ! V_474 ;
return 0 ;
}
case V_437 :
{
int V_474 ;
if ( V_465 < sizeof( V_474 ) )
return - V_223 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_18 -> V_434 = ! ! V_474 ;
return 0 ;
}
case V_479 :
{
int V_474 ;
if ( V_465 < sizeof( V_474 ) )
return - V_223 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_18 -> V_311 = ! ! V_474 ;
return 0 ;
}
case V_480 :
{
int V_474 ;
if ( V_24 -> type != V_376 )
return - V_223 ;
if ( V_18 -> V_80 . V_70 || V_18 -> V_77 . V_70 )
return - V_476 ;
if ( V_465 < sizeof( V_474 ) )
return - V_223 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_18 -> V_377 = ! ! V_474 ;
return 0 ;
}
case V_481 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_18 -> V_57 = V_474 ;
return 0 ;
}
case V_482 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
return F_165 ( V_25 , V_474 & 0xffff , V_474 >> 16 ) ;
}
case V_483 :
{
unsigned int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( V_18 -> V_80 . V_70 || V_18 -> V_77 . V_70 )
return - V_476 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_18 -> V_348 = ! ! V_474 ;
return 0 ;
}
case V_484 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( F_297 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_18 -> V_20 = V_474 ? F_1 : F_205 ;
return 0 ;
}
default:
return - V_466 ;
}
}
static int F_298 ( struct V_249 * V_24 , int V_462 , int V_463 ,
char T_8 * V_464 , int T_8 * V_465 )
{
int V_172 ;
int V_474 , V_485 = sizeof( V_474 ) ;
struct V_24 * V_25 = V_24 -> V_25 ;
struct V_17 * V_18 = F_33 ( V_25 ) ;
void * V_83 = & V_474 ;
union V_486 V_487 ;
if ( V_462 != V_427 )
return - V_466 ;
if ( F_299 ( V_172 , V_465 ) )
return - V_354 ;
if ( V_172 < 0 )
return - V_223 ;
switch ( V_463 ) {
case V_488 :
F_63 ( & V_25 -> V_130 . V_81 ) ;
memcpy ( & V_487 , & V_18 -> V_120 , sizeof( V_487 ) ) ;
memset ( & V_18 -> V_120 , 0 , sizeof( V_18 -> V_120 ) ) ;
F_64 ( & V_25 -> V_130 . V_81 ) ;
if ( V_18 -> V_36 == V_42 ) {
V_485 = sizeof( struct V_489 ) ;
V_487 . V_121 . V_317 += V_487 . V_121 . V_148 ;
V_83 = & V_487 . V_121 ;
} else {
V_485 = sizeof( struct V_490 ) ;
V_487 . V_316 . V_317 += V_487 . V_316 . V_148 ;
V_83 = & V_487 . V_316 ;
}
break;
case V_437 :
V_474 = V_18 -> V_434 ;
break;
case V_479 :
V_474 = V_18 -> V_311 ;
break;
case V_480 :
V_474 = V_18 -> V_377 ;
break;
case V_475 :
V_474 = V_18 -> V_36 ;
break;
case V_491 :
if ( V_172 > sizeof( int ) )
V_172 = sizeof( int ) ;
if ( F_297 ( & V_474 , V_464 , V_172 ) )
return - V_354 ;
switch ( V_474 ) {
case V_37 :
V_474 = sizeof( struct V_492 ) ;
break;
case V_40 :
V_474 = sizeof( struct V_493 ) ;
break;
case V_42 :
V_474 = sizeof( struct V_143 ) ;
break;
default:
return - V_223 ;
}
break;
case V_477 :
V_474 = V_18 -> V_328 ;
break;
case V_478 :
V_474 = V_18 -> V_365 ;
break;
case V_481 :
V_474 = V_18 -> V_57 ;
break;
case V_482 :
V_474 = ( V_18 -> V_27 ?
( ( T_4 ) V_18 -> V_27 -> V_220 |
( ( T_4 ) V_18 -> V_27 -> type << 16 ) |
( ( T_4 ) V_18 -> V_27 -> V_45 << 24 ) ) :
0 ) ;
break;
case V_483 :
V_474 = V_18 -> V_348 ;
break;
case V_484 :
V_474 = F_26 ( V_18 ) ;
break;
default:
return - V_466 ;
}
if ( V_172 > V_485 )
V_172 = V_485 ;
if ( F_300 ( V_172 , V_465 ) )
return - V_354 ;
if ( F_301 ( V_464 , V_83 , V_172 ) )
return - V_354 ;
return 0 ;
}
static int F_302 ( struct V_494 * V_495 ,
unsigned long V_251 , void * V_496 )
{
struct V_24 * V_25 ;
struct V_3 * V_4 = F_303 ( V_496 ) ;
struct V_209 * V_209 = F_160 ( V_4 ) ;
F_18 () ;
F_304 (sk, &net->packet.sklist) {
struct V_17 * V_18 = F_33 ( V_25 ) ;
switch ( V_251 ) {
case V_497 :
if ( V_18 -> V_456 )
F_292 ( V_4 , V_18 -> V_456 , - 1 ) ;
case V_498 :
if ( V_4 -> V_96 == V_18 -> V_96 ) {
F_43 ( & V_18 -> V_30 ) ;
if ( V_18 -> V_26 ) {
F_37 ( V_25 , false ) ;
V_25 -> V_400 = V_262 ;
if ( ! F_142 ( V_25 , V_189 ) )
V_25 -> V_401 ( V_25 ) ;
}
if ( V_251 == V_497 ) {
F_24 ( V_18 ) ;
V_18 -> V_96 = - 1 ;
if ( V_18 -> V_28 . V_4 )
F_238 ( V_18 -> V_28 . V_4 ) ;
V_18 -> V_28 . V_4 = NULL ;
}
F_41 ( & V_18 -> V_30 ) ;
}
break;
case V_499 :
if ( V_4 -> V_96 == V_18 -> V_96 ) {
F_43 ( & V_18 -> V_30 ) ;
if ( V_18 -> V_192 )
F_32 ( V_25 ) ;
F_41 ( & V_18 -> V_30 ) ;
}
break;
}
}
F_21 () ;
return V_500 ;
}
static int F_305 ( struct V_249 * V_24 , unsigned int V_501 ,
unsigned long V_502 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
switch ( V_501 ) {
case V_503 :
{
int V_504 = F_306 ( V_25 ) ;
return F_300 ( V_504 , ( int T_8 * ) V_502 ) ;
}
case V_505 :
{
struct V_1 * V_2 ;
int V_504 = 0 ;
F_63 ( & V_25 -> V_130 . V_81 ) ;
V_2 = F_307 ( & V_25 -> V_130 ) ;
if ( V_2 )
V_504 = V_2 -> V_172 ;
F_64 ( & V_25 -> V_130 . V_81 ) ;
return F_300 ( V_504 , ( int T_8 * ) V_502 ) ;
}
case V_506 :
return F_308 ( V_25 , (struct V_507 T_8 * ) V_502 ) ;
case V_508 :
return F_309 ( V_25 , (struct V_43 T_8 * ) V_502 ) ;
#ifdef F_310
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
case V_522 :
return V_523 . V_524 ( V_24 , V_501 , V_502 ) ;
#endif
default:
return - V_525 ;
}
return 0 ;
}
static unsigned int F_311 ( struct V_526 * V_526 , struct V_249 * V_24 ,
T_9 * V_527 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
struct V_17 * V_18 = F_33 ( V_25 ) ;
unsigned int V_528 = F_312 ( V_526 , V_24 , V_527 ) ;
F_63 ( & V_25 -> V_130 . V_81 ) ;
if ( V_18 -> V_80 . V_70 ) {
if ( ! F_123 ( V_18 , & V_18 -> V_80 ,
V_159 ) )
V_528 |= V_529 | V_530 ;
}
F_64 ( & V_25 -> V_130 . V_81 ) ;
F_63 ( & V_25 -> V_531 . V_81 ) ;
if ( V_18 -> V_77 . V_70 ) {
if ( F_58 ( V_18 , & V_18 -> V_77 , V_168 ) )
V_528 |= V_532 | V_533 ;
}
F_64 ( & V_25 -> V_531 . V_81 ) ;
return V_528 ;
}
static void F_313 ( struct V_534 * V_535 )
{
struct V_526 * V_526 = V_535 -> V_536 ;
struct V_249 * V_24 = V_526 -> V_537 ;
struct V_24 * V_25 = V_24 -> V_25 ;
if ( V_25 )
F_115 ( & F_33 ( V_25 ) -> V_538 ) ;
}
static void F_314 ( struct V_534 * V_535 )
{
struct V_526 * V_526 = V_535 -> V_536 ;
struct V_249 * V_24 = V_526 -> V_537 ;
struct V_24 * V_25 = V_24 -> V_25 ;
if ( V_25 )
F_104 ( & F_33 ( V_25 ) -> V_538 ) ;
}
static void F_315 ( struct V_106 * V_70 , unsigned int V_539 ,
unsigned int V_172 )
{
int V_199 ;
for ( V_199 = 0 ; V_199 < V_172 ; V_199 ++ ) {
if ( F_13 ( V_70 [ V_199 ] . V_71 ) ) {
if ( F_316 ( V_70 [ V_199 ] . V_71 ) )
F_317 ( V_70 [ V_199 ] . V_71 ) ;
else
F_318 ( ( unsigned long ) V_70 [ V_199 ] . V_71 ,
V_539 ) ;
V_70 [ V_199 ] . V_71 = NULL ;
}
}
F_179 ( V_70 ) ;
}
static char * F_319 ( unsigned long V_539 )
{
char * V_71 ;
T_10 V_540 = V_227 | V_541 |
V_542 | V_543 | V_544 ;
V_71 = ( char * ) F_320 ( V_540 , V_539 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_321 ( ( 1 << V_539 ) * V_139 ) ;
if ( V_71 )
return V_71 ;
V_540 &= ~ V_544 ;
V_71 = ( char * ) F_320 ( V_540 , V_539 ) ;
if ( V_71 )
return V_71 ;
return NULL ;
}
static struct V_106 * F_322 ( struct V_545 * V_472 , int V_539 )
{
unsigned int V_546 = V_472 -> V_115 ;
struct V_106 * V_70 ;
int V_199 ;
V_70 = F_323 ( V_546 , sizeof( struct V_106 ) , V_227 ) ;
if ( F_2 ( ! V_70 ) )
goto V_15;
for ( V_199 = 0 ; V_199 < V_546 ; V_199 ++ ) {
V_70 [ V_199 ] . V_71 = F_319 ( V_539 ) ;
if ( F_2 ( ! V_70 [ V_199 ] . V_71 ) )
goto V_547;
}
V_15:
return V_70 ;
V_547:
F_315 ( V_70 , V_539 , V_546 ) ;
V_70 = NULL ;
goto V_15;
}
static int F_252 ( struct V_24 * V_25 , union V_101 * V_102 ,
int V_548 , int V_77 )
{
struct V_106 * V_70 = NULL ;
struct V_17 * V_18 = F_33 ( V_25 ) ;
int V_549 , V_539 = 0 ;
struct V_64 * V_65 ;
struct V_78 * V_79 ;
T_7 V_192 ;
int V_94 = - V_223 ;
struct V_545 * V_472 = & V_102 -> V_472 ;
if ( ! V_548 && V_77 && ( V_18 -> V_36 > V_40 ) ) {
F_48 ( 1 , L_7 ) ;
goto V_15;
}
V_65 = V_77 ? & V_18 -> V_77 : & V_18 -> V_80 ;
V_79 = V_77 ? & V_25 -> V_531 : & V_25 -> V_130 ;
V_94 = - V_476 ;
if ( ! V_548 ) {
if ( F_85 ( & V_18 -> V_538 ) )
goto V_15;
if ( F_131 ( V_65 ) )
goto V_15;
}
if ( V_472 -> V_115 ) {
V_94 = - V_476 ;
if ( F_2 ( V_65 -> V_70 ) )
goto V_15;
switch ( V_18 -> V_36 ) {
case V_37 :
V_18 -> V_117 = V_550 ;
break;
case V_40 :
V_18 -> V_117 = V_551 ;
break;
case V_42 :
V_18 -> V_117 = V_552 ;
break;
}
V_94 = - V_223 ;
if ( F_2 ( ( int ) V_472 -> V_113 <= 0 ) )
goto V_15;
if ( F_2 ( V_472 -> V_113 & ( V_139 - 1 ) ) )
goto V_15;
if ( F_2 ( V_472 -> V_553 < V_18 -> V_117 +
V_18 -> V_328 ) )
goto V_15;
if ( F_2 ( V_472 -> V_553 & ( V_554 - 1 ) ) )
goto V_15;
V_65 -> V_69 = V_472 -> V_113 / V_472 -> V_553 ;
if ( F_2 ( V_65 -> V_69 <= 0 ) )
goto V_15;
if ( F_2 ( ( V_65 -> V_69 * V_472 -> V_115 ) !=
V_472 -> V_555 ) )
goto V_15;
V_94 = - V_226 ;
V_539 = F_324 ( V_472 -> V_113 ) ;
V_70 = F_322 ( V_472 , V_539 ) ;
if ( F_2 ( ! V_70 ) )
goto V_15;
switch ( V_18 -> V_36 ) {
case V_42 :
if ( ! V_77 )
F_77 ( V_18 , V_65 , V_70 , V_102 , V_77 ) ;
break;
default:
break;
}
}
else {
V_94 = - V_223 ;
if ( F_2 ( V_472 -> V_555 ) )
goto V_15;
}
F_257 ( V_25 ) ;
F_43 ( & V_18 -> V_30 ) ;
V_549 = V_18 -> V_26 ;
V_192 = V_18 -> V_192 ;
if ( V_549 ) {
V_18 -> V_192 = 0 ;
F_37 ( V_25 , false ) ;
}
F_41 ( & V_18 -> V_30 ) ;
F_42 () ;
V_94 = - V_476 ;
F_166 ( & V_18 -> V_360 ) ;
if ( V_548 || F_85 ( & V_18 -> V_538 ) == 0 ) {
V_94 = 0 ;
F_63 ( & V_79 -> V_81 ) ;
F_325 ( V_65 -> V_70 , V_70 ) ;
V_65 -> V_176 = ( V_472 -> V_555 - 1 ) ;
V_65 -> V_73 = 0 ;
V_65 -> V_72 = V_472 -> V_553 ;
F_64 ( & V_79 -> V_81 ) ;
F_325 ( V_65 -> V_556 , V_539 ) ;
F_325 ( V_65 -> V_557 , V_472 -> V_115 ) ;
V_65 -> V_558 = V_472 -> V_113 / V_139 ;
V_18 -> V_28 . F_66 = ( V_18 -> V_80 . V_70 ) ?
V_183 : F_208 ;
F_140 ( V_79 ) ;
if ( F_85 ( & V_18 -> V_538 ) )
F_143 ( L_8 ,
F_85 ( & V_18 -> V_538 ) ) ;
}
F_174 ( & V_18 -> V_360 ) ;
F_43 ( & V_18 -> V_30 ) ;
if ( V_549 ) {
V_18 -> V_192 = V_192 ;
F_32 ( V_25 ) ;
}
F_41 ( & V_18 -> V_30 ) ;
if ( V_548 && ( V_18 -> V_36 > V_40 ) ) {
if ( ! V_77 )
F_61 ( V_18 , V_77 , V_79 ) ;
}
F_258 ( V_25 ) ;
if ( V_70 )
F_315 ( V_70 , V_539 , V_472 -> V_115 ) ;
V_15:
return V_94 ;
}
static int F_326 ( struct V_526 * V_526 , struct V_249 * V_24 ,
struct V_534 * V_535 )
{
struct V_24 * V_25 = V_24 -> V_25 ;
struct V_17 * V_18 = F_33 ( V_25 ) ;
unsigned long V_559 , V_560 ;
struct V_64 * V_65 ;
unsigned long V_137 ;
int V_94 = - V_223 ;
int V_199 ;
if ( V_535 -> V_561 )
return - V_223 ;
F_166 ( & V_18 -> V_360 ) ;
V_560 = 0 ;
for ( V_65 = & V_18 -> V_80 ; V_65 <= & V_18 -> V_77 ; V_65 ++ ) {
if ( V_65 -> V_70 ) {
V_560 += V_65 -> V_557
* V_65 -> V_558
* V_139 ;
}
}
if ( V_560 == 0 )
goto V_15;
V_559 = V_535 -> V_562 - V_535 -> V_563 ;
if ( V_559 != V_560 )
goto V_15;
V_137 = V_535 -> V_563 ;
for ( V_65 = & V_18 -> V_80 ; V_65 <= & V_18 -> V_77 ; V_65 ++ ) {
if ( V_65 -> V_70 == NULL )
continue;
for ( V_199 = 0 ; V_199 < V_65 -> V_557 ; V_199 ++ ) {
struct V_347 * V_347 ;
void * V_564 = V_65 -> V_70 [ V_199 ] . V_71 ;
int V_565 ;
for ( V_565 = 0 ; V_565 < V_65 -> V_558 ; V_565 ++ ) {
V_347 = F_47 ( V_564 ) ;
V_94 = F_327 ( V_535 , V_137 , V_347 ) ;
if ( F_2 ( V_94 ) )
goto V_15;
V_137 += V_139 ;
V_564 += V_139 ;
}
}
}
F_115 ( & V_18 -> V_538 ) ;
V_535 -> V_566 = & V_567 ;
V_94 = 0 ;
V_15:
F_174 ( & V_18 -> V_360 ) ;
return V_94 ;
}
static void * F_328 ( struct V_568 * V_569 , T_11 * V_570 )
__acquires( T_12 )
{
struct V_209 * V_209 = F_329 ( V_569 ) ;
F_18 () ;
return F_330 ( & V_209 -> V_394 . V_421 , * V_570 ) ;
}
static void * F_331 ( struct V_568 * V_569 , void * V_571 , T_11 * V_570 )
{
struct V_209 * V_209 = F_329 ( V_569 ) ;
return F_332 ( V_571 , & V_209 -> V_394 . V_421 , V_570 ) ;
}
static void F_333 ( struct V_568 * V_569 , void * V_571 )
__releases( T_12 )
{
F_21 () ;
}
static int F_334 ( struct V_568 * V_569 , void * V_571 )
{
if ( V_571 == V_572 )
F_335 ( V_569 , L_9 ) ;
else {
struct V_24 * V_573 = F_336 ( V_571 ) ;
const struct V_17 * V_18 = F_33 ( V_573 ) ;
F_337 ( V_569 ,
L_10 ,
V_573 ,
F_85 ( & V_573 -> V_574 ) ,
V_573 -> V_297 ,
F_111 ( V_18 -> V_192 ) ,
V_18 -> V_96 ,
V_18 -> V_26 ,
F_85 ( & V_573 -> V_184 ) ,
F_338 ( F_339 ( V_569 ) , F_340 ( V_573 ) ) ,
F_341 ( V_573 ) ) ;
}
return 0 ;
}
static int F_342 ( struct V_575 * V_575 , struct V_526 * V_526 )
{
return F_343 ( V_575 , V_526 , & V_576 ,
sizeof( struct V_577 ) ) ;
}
static int T_13 F_344 ( struct V_209 * V_209 )
{
F_267 ( & V_209 -> V_394 . V_395 ) ;
F_345 ( & V_209 -> V_394 . V_421 ) ;
if ( ! F_346 ( L_11 , 0 , V_209 -> V_578 , & V_579 ) )
return - V_226 ;
return 0 ;
}
static void T_14 F_347 ( struct V_209 * V_209 )
{
F_348 ( L_11 , V_209 -> V_578 ) ;
}
static void T_15 F_349 ( void )
{
F_350 ( & V_580 ) ;
F_351 ( & V_581 ) ;
F_352 ( V_414 ) ;
F_353 ( & V_415 ) ;
}
static int T_16 F_354 ( void )
{
int V_582 = F_355 ( & V_415 , 0 ) ;
if ( V_582 != 0 )
goto V_15;
F_356 ( & V_583 ) ;
F_357 ( & V_581 ) ;
F_358 ( & V_580 ) ;
V_15:
return V_582 ;
}
