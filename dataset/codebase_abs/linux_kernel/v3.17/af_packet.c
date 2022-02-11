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
if ( V_49 &&
( V_47 & V_50 ) &&
F_59 ( V_49 -> V_51 , V_46 ) )
return V_52 ;
if ( F_59 ( V_2 -> V_53 , V_46 ) )
return V_54 ;
return 0 ;
}
static T_3 F_60 ( struct V_19 * V_20 , void * V_33 ,
struct V_1 * V_2 )
{
union V_35 V_36 ;
struct V_45 V_46 ;
T_3 V_55 ;
if ( ! ( V_55 = F_57 ( V_2 , & V_46 , V_20 -> V_56 ) ) )
return 0 ;
V_36 . V_37 = V_33 ;
switch ( V_20 -> V_38 ) {
case V_39 :
V_36 . V_40 -> V_57 = V_46 . V_58 ;
V_36 . V_40 -> V_59 = V_46 . V_60 / V_61 ;
break;
case V_42 :
V_36 . V_43 -> V_57 = V_46 . V_58 ;
V_36 . V_43 -> V_62 = V_46 . V_60 ;
break;
case V_44 :
default:
F_52 ( 1 , L_1 ) ;
F_53 () ;
}
F_50 ( F_51 ( & V_36 . V_40 -> V_57 ) ) ;
F_54 () ;
return V_55 ;
}
static void * F_61 ( struct V_19 * V_20 ,
struct V_63 * V_64 ,
unsigned int V_65 ,
int V_34 )
{
unsigned int V_66 , V_67 ;
union V_35 V_36 ;
V_66 = V_65 / V_64 -> V_68 ;
V_67 = V_65 % V_64 -> V_68 ;
V_36 . V_37 = V_64 -> V_69 [ V_66 ] . V_70 +
( V_67 * V_64 -> V_71 ) ;
if ( V_34 != F_55 ( V_20 , V_36 . V_37 ) )
return NULL ;
return V_36 . V_37 ;
}
static void * F_62 ( struct V_19 * V_20 ,
struct V_63 * V_64 ,
int V_34 )
{
return F_61 ( V_20 , V_64 , V_64 -> V_72 , V_34 ) ;
}
static void F_63 ( struct V_73 * V_74 )
{
F_64 ( & V_74 -> V_75 ) ;
}
static void F_65 ( struct V_19 * V_20 ,
int V_76 ,
struct V_77 * V_78 )
{
struct V_73 * V_74 ;
V_74 = V_76 ? F_66 ( & V_20 -> V_76 ) :
F_66 ( & V_20 -> V_79 ) ;
F_67 ( & V_78 -> V_80 ) ;
V_74 -> V_81 = 1 ;
F_68 ( & V_78 -> V_80 ) ;
F_63 ( V_74 ) ;
}
static void F_69 ( struct V_19 * V_20 ,
struct V_73 * V_74 ,
void (* F_70) ( unsigned long ) )
{
F_71 ( & V_74 -> V_75 ) ;
V_74 -> V_75 . V_82 = ( long ) V_20 ;
V_74 -> V_75 . V_83 = F_70 ;
V_74 -> V_75 . V_84 = V_85 ;
}
static void F_72 ( struct V_19 * V_20 , int V_76 )
{
struct V_73 * V_74 ;
if ( V_76 )
F_53 () ;
V_74 = V_76 ? F_66 ( & V_20 -> V_76 ) :
F_66 ( & V_20 -> V_79 ) ;
F_69 ( V_20 , V_74 , V_86 ) ;
}
static int F_73 ( struct V_19 * V_20 ,
int V_87 )
{
struct V_3 * V_4 ;
unsigned int V_88 = 0 , V_89 = 0 , div = 0 , V_90 = 0 ;
struct V_91 V_92 ;
int V_93 ;
T_4 V_94 ;
F_74 () ;
V_4 = F_75 ( F_76 ( & V_20 -> V_27 ) , V_20 -> V_95 ) ;
if ( F_2 ( ! V_4 ) ) {
F_77 () ;
return V_96 ;
}
V_93 = F_78 ( V_4 , & V_92 ) ;
V_94 = F_79 ( & V_92 ) ;
F_77 () ;
if ( ! V_93 ) {
if ( V_94 < V_97 || V_94 == V_98 ) {
return V_96 ;
} else {
V_89 = 1 ;
div = V_94 / 1000 ;
}
}
V_88 = ( V_87 * 8 ) / ( 1024 * 1024 ) ;
if ( div )
V_88 /= div ;
V_90 = V_88 * V_89 ;
if ( div )
return V_90 + 1 ;
return V_90 ;
}
static void F_80 ( struct V_73 * V_99 ,
union V_100 * V_101 )
{
V_99 -> V_102 = V_101 -> V_103 . V_104 ;
}
static void F_81 ( struct V_19 * V_20 ,
struct V_63 * V_64 ,
struct V_105 * V_69 ,
union V_100 * V_101 , int V_76 )
{
struct V_73 * V_99 = F_66 ( V_64 ) ;
struct V_106 * V_107 ;
memset ( V_99 , 0x0 , sizeof( * V_99 ) ) ;
V_99 -> V_108 = 1 ;
V_99 -> V_109 = V_69 ;
V_107 = (struct V_106 * ) V_69 [ 0 ] . V_70 ;
V_99 -> V_110 = V_69 [ 0 ] . V_70 ;
V_99 -> V_111 = V_101 -> V_103 . V_112 ;
V_99 -> V_113 = V_101 -> V_103 . V_114 ;
V_99 -> V_115 = V_20 -> V_116 ;
V_99 -> V_117 = V_20 -> V_38 ;
V_99 -> V_118 = 0 ;
V_20 -> V_119 . V_120 . V_121 = 0 ;
if ( V_101 -> V_103 . V_122 )
V_99 -> V_123 = V_101 -> V_103 . V_122 ;
else
V_99 -> V_123 = F_73 ( V_20 ,
V_101 -> V_103 . V_112 ) ;
V_99 -> V_124 = F_82 ( V_99 -> V_123 ) ;
V_99 -> V_125 = V_101 -> V_103 . V_126 ;
V_99 -> V_127 = V_99 -> V_111 - F_83 ( V_99 -> V_125 ) ;
F_80 ( V_99 , V_101 ) ;
F_72 ( V_20 , V_76 ) ;
F_84 ( V_99 , V_107 ) ;
}
static void F_85 ( struct V_73 * V_74 )
{
F_86 ( & V_74 -> V_75 ,
V_85 + V_74 -> V_124 ) ;
V_74 -> V_118 = V_74 -> V_128 ;
}
static void V_86 ( unsigned long V_82 )
{
struct V_19 * V_20 = (struct V_19 * ) V_82 ;
struct V_73 * V_74 = F_66 ( & V_20 -> V_79 ) ;
unsigned int V_129 ;
struct V_106 * V_107 ;
F_47 ( & V_20 -> V_27 . V_130 . V_80 ) ;
V_129 = F_87 ( V_74 ) ;
V_107 = F_88 ( V_74 ) ;
if ( F_2 ( V_74 -> V_81 ) )
goto V_131;
if ( F_89 ( V_107 ) ) {
while ( F_90 ( & V_74 -> V_132 ) ) {
F_91 () ;
}
}
if ( V_74 -> V_118 == V_74 -> V_128 ) {
if ( ! V_129 ) {
F_92 ( V_74 , V_20 , V_133 ) ;
if ( ! F_93 ( V_74 , V_20 ) )
goto V_134;
else
goto V_131;
} else {
if ( F_94 ( V_74 , V_107 ) ) {
goto V_134;
} else {
F_84 ( V_74 , V_107 ) ;
goto V_131;
}
}
}
V_134:
F_85 ( V_74 ) ;
V_131:
F_45 ( & V_20 -> V_27 . V_130 . V_80 ) ;
}
static void F_95 ( struct V_73 * V_135 ,
struct V_106 * V_136 , T_3 V_34 )
{
#if V_137 == 1
T_5 * V_138 , * V_139 ;
V_138 = ( T_5 * ) V_136 ;
V_138 += V_140 ;
V_139 = ( T_5 * ) F_96 ( ( unsigned long ) V_135 -> V_141 ) ;
for (; V_138 < V_139 ; V_138 += V_140 )
F_50 ( F_51 ( V_138 ) ) ;
F_54 () ;
#endif
F_97 ( V_136 ) = V_34 ;
#if V_137 == 1
V_138 = ( T_5 * ) V_136 ;
F_50 ( F_51 ( V_138 ) ) ;
F_54 () ;
#endif
}
static void F_98 ( struct V_73 * V_135 ,
struct V_106 * V_136 ,
struct V_19 * V_20 , unsigned int V_142 )
{
T_3 V_34 = V_143 | V_142 ;
struct V_144 * V_145 ;
struct V_146 * V_40 = & V_136 -> V_147 . V_148 ;
if ( V_20 -> V_119 . V_120 . V_149 )
V_34 |= V_150 ;
V_145 = (struct V_144 * ) V_135 -> V_151 ;
V_145 -> V_152 = 0 ;
if ( F_89 ( V_136 ) ) {
V_40 -> V_153 . V_154 = V_145 -> V_57 ;
V_40 -> V_153 . V_155 = V_145 -> V_62 ;
} else {
struct V_45 V_46 ;
F_99 ( & V_46 ) ;
V_40 -> V_153 . V_154 = V_46 . V_58 ;
V_40 -> V_153 . V_155 = V_46 . V_60 ;
}
F_54 () ;
F_95 ( V_135 , V_136 , V_34 ) ;
V_135 -> V_128 = F_100 ( V_135 ) ;
}
static void F_101 ( struct V_73 * V_74 )
{
V_74 -> V_156 = 0 ;
}
static void F_84 ( struct V_73 * V_135 ,
struct V_106 * V_136 )
{
struct V_45 V_46 ;
struct V_146 * V_40 = & V_136 -> V_147 . V_148 ;
F_56 () ;
F_102 ( V_136 ) = V_135 -> V_108 ++ ;
F_89 ( V_136 ) = 0 ;
F_103 ( V_136 ) = F_83 ( V_135 -> V_125 ) ;
F_99 ( & V_46 ) ;
V_40 -> V_157 . V_154 = V_46 . V_58 ;
V_40 -> V_157 . V_155 = V_46 . V_60 ;
V_135 -> V_110 = ( char * ) V_136 ;
V_135 -> V_158 = V_135 -> V_110 + F_83 ( V_135 -> V_125 ) ;
F_104 ( V_136 ) = ( T_3 ) F_83 ( V_135 -> V_125 ) ;
F_105 ( V_136 ) = V_159 ;
V_136 -> V_117 = V_135 -> V_117 ;
V_135 -> V_151 = V_135 -> V_158 ;
V_135 -> V_141 = V_135 -> V_110 + V_135 -> V_111 ;
F_101 ( V_135 ) ;
F_85 ( V_135 ) ;
F_54 () ;
}
static void F_106 ( struct V_73 * V_74 ,
struct V_19 * V_20 )
{
V_74 -> V_156 = 1 ;
V_20 -> V_119 . V_120 . V_121 ++ ;
}
static void * F_93 ( struct V_73 * V_74 ,
struct V_19 * V_20 )
{
struct V_106 * V_107 ;
F_56 () ;
V_107 = F_88 ( V_74 ) ;
if ( V_143 & F_97 ( V_107 ) ) {
F_106 ( V_74 , V_20 ) ;
return NULL ;
}
F_84 ( V_74 , V_107 ) ;
return ( void * ) V_74 -> V_158 ;
}
static void F_92 ( struct V_73 * V_74 ,
struct V_19 * V_20 , unsigned int V_34 )
{
struct V_106 * V_107 = F_88 ( V_74 ) ;
if ( F_23 ( V_160 == F_97 ( V_107 ) ) ) {
if ( ! ( V_34 & V_133 ) ) {
while ( F_90 ( & V_74 -> V_132 ) ) {
F_91 () ;
}
}
F_98 ( V_74 , V_107 , V_20 , V_34 ) ;
return;
}
}
static int F_94 ( struct V_73 * V_74 ,
struct V_106 * V_107 )
{
return V_143 & F_97 ( V_107 ) ;
}
static int F_87 ( struct V_73 * V_74 )
{
return V_74 -> V_156 ;
}
static void F_107 ( struct V_63 * V_64 )
{
struct V_73 * V_74 = F_66 ( V_64 ) ;
F_108 ( & V_74 -> V_132 ) ;
}
static void F_109 ( struct V_73 * V_74 ,
struct V_144 * V_161 )
{
V_161 -> V_162 . V_163 = F_110 ( V_74 -> V_2 ) ;
}
static void F_111 ( struct V_73 * V_74 ,
struct V_144 * V_161 )
{
V_161 -> V_162 . V_163 = 0 ;
}
static void F_112 ( struct V_73 * V_74 ,
struct V_144 * V_161 )
{
if ( F_113 ( V_74 -> V_2 ) ) {
V_161 -> V_162 . V_164 = F_114 ( V_74 -> V_2 ) ;
V_161 -> V_162 . V_165 = F_115 ( V_74 -> V_2 -> V_166 ) ;
V_161 -> V_41 = V_167 | V_168 ;
} else {
V_161 -> V_162 . V_164 = 0 ;
V_161 -> V_162 . V_165 = 0 ;
V_161 -> V_41 = V_169 ;
}
}
static void F_116 ( struct V_73 * V_74 ,
struct V_144 * V_161 )
{
V_161 -> V_162 . V_170 = 0 ;
F_112 ( V_74 , V_161 ) ;
if ( V_74 -> V_102 & V_171 )
F_109 ( V_74 , V_161 ) ;
else
F_111 ( V_74 , V_161 ) ;
}
static void F_117 ( char * V_172 ,
struct V_73 * V_74 ,
struct V_106 * V_107 ,
unsigned int V_173 )
{
struct V_144 * V_161 ;
V_161 = (struct V_144 * ) V_172 ;
V_161 -> V_152 = F_118 ( V_173 ) ;
V_74 -> V_151 = V_172 ;
V_74 -> V_158 += F_118 ( V_173 ) ;
F_103 ( V_107 ) += F_118 ( V_173 ) ;
F_89 ( V_107 ) += 1 ;
F_119 ( & V_74 -> V_132 ) ;
F_116 ( V_74 , V_161 ) ;
}
static void * F_120 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
int V_34 ,
unsigned int V_173
)
{
struct V_73 * V_74 ;
struct V_106 * V_107 ;
char * V_172 , * V_139 ;
V_74 = F_66 ( & V_20 -> V_79 ) ;
V_107 = F_88 ( V_74 ) ;
if ( F_87 ( V_74 ) ) {
if ( F_94 ( V_74 , V_107 ) ) {
return NULL ;
} else {
F_84 ( V_74 , V_107 ) ;
}
}
F_121 () ;
V_172 = V_74 -> V_158 ;
V_74 -> V_2 = V_2 ;
V_139 = ( char * ) V_107 + V_74 -> V_111 ;
if ( V_172 + F_118 ( V_173 ) < V_139 ) {
F_117 ( V_172 , V_74 , V_107 , V_173 ) ;
return ( void * ) V_172 ;
}
F_92 ( V_74 , V_20 , 0 ) ;
V_172 = ( char * ) F_93 ( V_74 , V_20 ) ;
if ( V_172 ) {
V_107 = F_88 ( V_74 ) ;
F_117 ( V_172 , V_74 , V_107 , V_173 ) ;
return ( void * ) V_172 ;
}
return NULL ;
}
static void * F_122 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
int V_34 , unsigned int V_173 )
{
char * V_172 = NULL ;
switch ( V_20 -> V_38 ) {
case V_39 :
case V_42 :
V_172 = F_61 ( V_20 , & V_20 -> V_79 ,
V_20 -> V_79 . V_72 , V_34 ) ;
return V_172 ;
case V_44 :
return F_120 ( V_20 , V_2 , V_34 , V_173 ) ;
default:
F_52 ( 1 , L_2 ) ;
F_53 () ;
return NULL ;
}
}
static void * F_123 ( struct V_19 * V_20 ,
struct V_63 * V_64 ,
unsigned int V_174 ,
int V_34 )
{
struct V_73 * V_74 = F_66 ( V_64 ) ;
struct V_106 * V_107 = F_124 ( V_74 , V_174 ) ;
if ( V_34 != F_97 ( V_107 ) )
return NULL ;
return V_107 ;
}
static int F_125 ( struct V_63 * V_64 )
{
unsigned int V_151 ;
if ( V_64 -> V_175 . V_128 )
V_151 = V_64 -> V_175 . V_128 - 1 ;
else
V_151 = V_64 -> V_175 . V_113 - 1 ;
return V_151 ;
}
static void * F_126 ( struct V_19 * V_20 ,
struct V_63 * V_64 ,
int V_34 )
{
unsigned int V_176 = F_125 ( V_64 ) ;
return F_123 ( V_20 , V_64 , V_176 , V_34 ) ;
}
static void * F_127 ( struct V_19 * V_20 ,
struct V_63 * V_64 ,
int V_34 )
{
if ( V_20 -> V_38 <= V_42 )
return F_128 ( V_20 , V_64 , V_34 ) ;
return F_126 ( V_20 , V_64 , V_34 ) ;
}
static void F_129 ( struct V_19 * V_20 ,
struct V_63 * V_64 )
{
switch ( V_20 -> V_38 ) {
case V_39 :
case V_42 :
return F_130 ( V_64 ) ;
case V_44 :
default:
F_52 ( 1 , L_1 ) ;
F_53 () ;
return;
}
}
static void * F_128 ( struct V_19 * V_20 ,
struct V_63 * V_64 ,
int V_34 )
{
unsigned int V_176 = V_64 -> V_72 ? V_64 -> V_72 - 1 : V_64 -> V_177 ;
return F_61 ( V_20 , V_64 , V_176 , V_34 ) ;
}
static void F_130 ( struct V_63 * V_178 )
{
V_178 -> V_72 = V_178 -> V_72 != V_178 -> V_177 ? V_178 -> V_72 + 1 : 0 ;
}
static void F_131 ( struct V_63 * V_64 )
{
F_132 ( * V_64 -> V_179 ) ;
}
static void F_133 ( struct V_63 * V_64 )
{
F_134 ( * V_64 -> V_179 ) ;
}
static unsigned int F_135 ( const struct V_63 * V_64 )
{
unsigned int V_180 = 0 ;
int V_181 ;
if ( V_64 -> V_179 == NULL )
return 0 ;
F_136 (cpu)
V_180 += * F_137 ( V_64 -> V_179 , V_181 ) ;
return V_180 ;
}
static int F_138 ( struct V_19 * V_20 )
{
V_20 -> V_79 . V_179 = NULL ;
V_20 -> V_76 . V_179 = F_139 (unsigned int) ;
if ( F_2 ( V_20 -> V_76 . V_179 == NULL ) )
return - V_182 ;
return 0 ;
}
static void F_140 ( struct V_19 * V_20 )
{
F_141 ( V_20 -> V_76 . V_179 ) ;
}
static bool F_142 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_20 -> V_27 ;
bool V_183 ;
if ( V_20 -> V_30 . F_70 != V_184 )
return ( F_90 ( & V_27 -> V_185 ) + V_2 -> V_186 )
<= V_27 -> V_187 ;
F_47 ( & V_27 -> V_130 . V_80 ) ;
if ( V_20 -> V_38 == V_44 )
V_183 = F_123 ( V_20 , & V_20 -> V_79 ,
V_20 -> V_79 . V_175 . V_128 ,
V_160 ) ;
else
V_183 = F_61 ( V_20 , & V_20 -> V_79 ,
V_20 -> V_79 . V_72 ,
V_160 ) ;
F_45 ( & V_27 -> V_130 . V_80 ) ;
return V_183 ;
}
static void F_143 ( struct V_26 * V_27 )
{
F_144 ( & V_27 -> V_188 ) ;
F_145 ( F_90 ( & V_27 -> V_185 ) ) ;
F_145 ( F_90 ( & V_27 -> V_189 ) ) ;
if ( ! F_146 ( V_27 , V_190 ) ) {
F_147 ( L_3 , V_27 ) ;
return;
}
F_148 ( V_27 ) ;
}
static int F_149 ( struct V_191 * V_192 , unsigned int V_193 )
{
int V_194 = F_90 ( & V_192 -> V_195 ) + 1 ;
if ( V_194 >= V_193 )
V_194 = 0 ;
return V_194 ;
}
static unsigned int F_150 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
return F_151 ( F_110 ( V_2 ) , V_193 ) ;
}
static unsigned int F_152 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
int V_196 , V_197 ;
V_196 = F_90 ( & V_192 -> V_195 ) ;
while ( ( V_197 = F_153 ( & V_192 -> V_195 , V_196 ,
F_149 ( V_192 , V_193 ) ) ) != V_196 )
V_196 = V_197 ;
return V_196 ;
}
static unsigned int F_154 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
return F_12 () % V_193 ;
}
static unsigned int F_155 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
return F_156 ( V_193 ) ;
}
static unsigned int F_157 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_174 , unsigned int V_198 ,
unsigned int V_193 )
{
unsigned int V_199 , V_200 ;
V_199 = V_200 = F_158 ( int , V_192 -> V_201 [ V_174 ] , V_193 - 1 ) ;
do {
if ( V_199 != V_198 && F_142 ( F_37 ( V_192 -> V_202 [ V_199 ] ) , V_2 ) ) {
if ( V_199 != V_200 )
V_192 -> V_201 [ V_174 ] = V_199 ;
return V_199 ;
}
if ( ++ V_199 == V_193 )
V_199 = 0 ;
} while ( V_199 != V_200 );
return V_174 ;
}
static unsigned int F_159 ( struct V_191 * V_192 ,
struct V_1 * V_2 ,
unsigned int V_193 )
{
return F_8 ( V_2 ) % V_193 ;
}
static bool F_160 ( struct V_191 * V_192 , T_2 V_203 )
{
return V_192 -> V_47 & ( V_203 >> 8 ) ;
}
static int F_161 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_191 * V_192 = V_205 -> V_207 ;
unsigned int V_193 = V_192 -> V_208 ;
struct V_19 * V_20 ;
unsigned int V_174 ;
if ( ! F_162 ( F_163 ( V_4 ) , F_164 ( & V_192 -> V_209 ) ) ||
! V_193 ) {
F_18 ( V_2 ) ;
return 0 ;
}
switch ( V_192 -> type ) {
case V_210 :
default:
if ( F_160 ( V_192 , V_211 ) ) {
V_2 = F_165 ( V_2 , V_212 ) ;
if ( ! V_2 )
return 0 ;
}
V_174 = F_150 ( V_192 , V_2 , V_193 ) ;
break;
case V_213 :
V_174 = F_152 ( V_192 , V_2 , V_193 ) ;
break;
case V_214 :
V_174 = F_154 ( V_192 , V_2 , V_193 ) ;
break;
case V_215 :
V_174 = F_155 ( V_192 , V_2 , V_193 ) ;
break;
case V_216 :
V_174 = F_159 ( V_192 , V_2 , V_193 ) ;
break;
case V_217 :
V_174 = F_157 ( V_192 , V_2 , 0 , ( unsigned int ) - 1 , V_193 ) ;
break;
}
V_20 = F_37 ( V_192 -> V_202 [ V_174 ] ) ;
if ( F_160 ( V_192 , V_218 ) &&
F_2 ( ! F_142 ( V_20 , V_2 ) ) ) {
V_174 = F_157 ( V_192 , V_2 , V_174 , V_174 , V_193 ) ;
V_20 = F_37 ( V_192 -> V_202 [ V_174 ] ) ;
}
return V_20 -> V_30 . F_70 ( V_2 , V_4 , & V_20 -> V_30 , V_206 ) ;
}
static void F_38 ( struct V_26 * V_27 , struct V_19 * V_20 )
{
struct V_191 * V_192 = V_20 -> V_29 ;
F_47 ( & V_192 -> V_80 ) ;
V_192 -> V_202 [ V_192 -> V_208 ] = V_27 ;
F_54 () ;
V_192 -> V_208 ++ ;
F_45 ( & V_192 -> V_80 ) ;
}
static void F_42 ( struct V_26 * V_27 , struct V_19 * V_20 )
{
struct V_191 * V_192 = V_20 -> V_29 ;
int V_199 ;
F_47 ( & V_192 -> V_80 ) ;
for ( V_199 = 0 ; V_199 < V_192 -> V_208 ; V_199 ++ ) {
if ( V_192 -> V_202 [ V_199 ] == V_27 )
break;
}
F_166 ( V_199 >= V_192 -> V_208 ) ;
V_192 -> V_202 [ V_199 ] = V_192 -> V_202 [ V_192 -> V_208 - 1 ] ;
V_192 -> V_208 -- ;
F_45 ( & V_192 -> V_80 ) ;
}
static bool F_167 ( struct V_204 * V_219 , struct V_26 * V_27 )
{
if ( V_219 -> V_207 == ( void * ) ( (struct V_19 * ) V_27 ) -> V_29 )
return true ;
return false ;
}
static int F_168 ( struct V_26 * V_27 , T_2 V_220 , T_2 V_221 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
struct V_191 * V_192 , * V_222 ;
T_5 type = V_221 & 0xff ;
T_5 V_47 = V_221 >> 8 ;
int V_93 ;
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
if ( ! V_20 -> V_28 )
return - V_223 ;
if ( V_20 -> V_29 )
return - V_224 ;
F_169 ( & V_225 ) ;
V_222 = NULL ;
F_170 (f, &fanout_list, list) {
if ( V_192 -> V_220 == V_220 &&
F_164 ( & V_192 -> V_209 ) == F_76 ( V_27 ) ) {
V_222 = V_192 ;
break;
}
}
V_93 = - V_223 ;
if ( V_222 && V_222 -> V_47 != V_47 )
goto V_131;
if ( ! V_222 ) {
V_93 = - V_226 ;
V_222 = F_171 ( sizeof( * V_222 ) , V_227 ) ;
if ( ! V_222 )
goto V_131;
F_172 ( & V_222 -> V_209 , F_76 ( V_27 ) ) ;
V_222 -> V_220 = V_220 ;
V_222 -> type = type ;
V_222 -> V_47 = V_47 ;
F_173 ( & V_222 -> V_195 , 0 ) ;
F_174 ( & V_222 -> V_228 ) ;
F_175 ( & V_222 -> V_80 ) ;
F_173 ( & V_222 -> V_229 , 0 ) ;
V_222 -> V_30 . type = V_20 -> V_30 . type ;
V_222 -> V_30 . V_4 = V_20 -> V_30 . V_4 ;
V_222 -> V_30 . F_70 = F_161 ;
V_222 -> V_30 . V_207 = V_222 ;
V_222 -> V_30 . V_230 = F_167 ;
F_39 ( & V_222 -> V_30 ) ;
F_176 ( & V_222 -> V_228 , & V_231 ) ;
}
V_93 = - V_223 ;
if ( V_222 -> type == type &&
V_222 -> V_30 . type == V_20 -> V_30 . type &&
V_222 -> V_30 . V_4 == V_20 -> V_30 . V_4 ) {
V_93 = - V_232 ;
if ( F_90 ( & V_222 -> V_229 ) < V_233 ) {
F_43 ( & V_20 -> V_30 ) ;
V_20 -> V_29 = V_222 ;
F_119 ( & V_222 -> V_229 ) ;
F_38 ( V_27 , V_20 ) ;
V_93 = 0 ;
}
}
V_131:
F_177 ( & V_225 ) ;
return V_93 ;
}
static void F_178 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
struct V_191 * V_192 ;
V_192 = V_20 -> V_29 ;
if ( ! V_192 )
return;
F_169 ( & V_225 ) ;
V_20 -> V_29 = NULL ;
if ( F_179 ( & V_192 -> V_229 ) ) {
F_180 ( & V_192 -> V_228 ) ;
F_181 ( & V_192 -> V_30 ) ;
F_182 ( V_192 ) ;
}
F_177 ( & V_225 ) ;
}
static int F_183 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_26 * V_27 ;
struct V_234 * V_235 ;
V_27 = V_205 -> V_207 ;
if ( V_2 -> V_236 == V_237 )
goto V_131;
if ( ! F_162 ( F_163 ( V_4 ) , F_76 ( V_27 ) ) )
goto V_131;
V_2 = F_184 ( V_2 , V_238 ) ;
if ( V_2 == NULL )
goto V_239;
F_185 ( V_2 ) ;
F_186 ( V_2 ) ;
V_235 = & F_187 ( V_2 ) -> V_240 . V_241 ;
F_188 ( V_2 , V_2 -> V_82 - F_189 ( V_2 ) ) ;
V_235 -> V_242 = V_4 -> type ;
F_190 ( V_235 -> V_243 , V_4 -> V_244 , sizeof( V_235 -> V_243 ) ) ;
V_235 -> V_245 = V_2 -> V_246 ;
if ( F_191 ( V_27 , V_2 ) == 0 )
return 0 ;
V_131:
F_18 ( V_2 ) ;
V_239:
return 0 ;
}
static int F_192 ( struct V_247 * V_248 , struct V_249 * V_26 ,
struct V_250 * V_251 , T_6 V_173 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
F_193 ( struct V_234 * , V_252 , V_251 -> V_253 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
T_7 V_254 = 0 ;
int V_93 ;
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
F_21 () ;
V_4 = F_194 ( F_76 ( V_27 ) , V_252 -> V_243 ) ;
V_93 = - V_260 ;
if ( V_4 == NULL )
goto V_261;
V_93 = - V_262 ;
if ( ! ( V_4 -> V_47 & V_263 ) )
goto V_261;
if ( F_2 ( F_146 ( V_27 , V_264 ) ) ) {
if ( ! F_195 ( V_4 ) ) {
V_93 = - V_265 ;
goto V_261;
}
V_255 = 4 ;
}
V_93 = - V_266 ;
if ( V_173 > V_4 -> V_267 + V_4 -> V_268 + V_269 + V_255 )
goto V_261;
if ( ! V_2 ) {
T_6 V_270 = F_196 ( V_4 ) ;
int V_271 = V_4 -> V_272 ;
unsigned int V_273 = V_4 -> V_274 ? V_4 -> V_268 : 0 ;
F_25 () ;
V_2 = F_197 ( V_27 , V_173 + V_270 + V_271 , 0 , V_227 ) ;
if ( V_2 == NULL )
return - V_182 ;
F_198 ( V_2 , V_270 ) ;
F_199 ( V_2 ) ;
if ( V_273 ) {
V_2 -> V_82 -= V_273 ;
V_2 -> V_275 -= V_273 ;
if ( V_173 < V_273 )
F_199 ( V_2 ) ;
}
V_93 = F_200 ( F_201 ( V_2 , V_173 ) , V_251 -> V_276 , V_173 ) ;
if ( V_93 )
goto V_277;
goto V_259;
}
if ( V_173 > ( V_4 -> V_267 + V_4 -> V_268 + V_255 ) ) {
struct V_278 * V_279 ;
F_202 ( V_2 ) ;
V_279 = F_203 ( V_2 ) ;
if ( V_279 -> V_280 != F_204 ( V_281 ) ) {
V_93 = - V_266 ;
goto V_261;
}
}
V_2 -> V_246 = V_254 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_282 = V_27 -> V_283 ;
V_2 -> V_284 = V_27 -> V_285 ;
F_205 ( V_27 , & F_206 ( V_2 ) -> V_286 ) ;
if ( F_2 ( V_255 == 4 ) )
V_2 -> V_287 = 1 ;
F_207 ( V_2 , 0 ) ;
F_208 ( V_2 ) ;
F_25 () ;
return V_173 ;
V_261:
F_25 () ;
V_277:
F_18 ( V_2 ) ;
return V_93 ;
}
static unsigned int F_209 ( const struct V_1 * V_2 ,
const struct V_26 * V_27 ,
unsigned int V_288 )
{
struct V_289 * V_290 ;
F_21 () ;
V_290 = F_22 ( V_27 -> V_289 ) ;
if ( V_290 != NULL )
V_288 = F_210 ( V_290 , V_2 ) ;
F_25 () ;
return V_288 ;
}
static int F_211 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_26 * V_27 ;
struct V_291 * V_292 ;
struct V_19 * V_20 ;
T_5 * V_293 = V_2 -> V_82 ;
int V_294 = V_2 -> V_173 ;
unsigned int V_295 , V_288 ;
if ( V_2 -> V_236 == V_237 )
goto V_14;
V_27 = V_205 -> V_207 ;
V_20 = F_37 ( V_27 ) ;
if ( ! F_162 ( F_163 ( V_4 ) , F_76 ( V_27 ) ) )
goto V_14;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_274 ) {
if ( V_27 -> V_296 != V_297 )
F_188 ( V_2 , V_2 -> V_82 - F_189 ( V_2 ) ) ;
else if ( V_2 -> V_236 == V_298 ) {
F_212 ( V_2 , F_213 ( V_2 ) ) ;
}
}
V_295 = V_2 -> V_173 ;
V_288 = F_209 ( V_2 , V_27 , V_295 ) ;
if ( ! V_288 )
goto V_299;
if ( V_295 > V_288 )
V_295 = V_288 ;
if ( F_90 ( & V_27 -> V_185 ) >= V_27 -> V_187 )
goto V_300;
if ( F_214 ( V_2 ) ) {
struct V_1 * V_301 = F_215 ( V_2 , V_238 ) ;
if ( V_301 == NULL )
goto V_300;
if ( V_293 != V_2 -> V_82 ) {
V_2 -> V_82 = V_293 ;
V_2 -> V_173 = V_294 ;
}
F_216 ( V_2 ) ;
V_2 = V_301 ;
}
F_217 ( sizeof( * F_187 ( V_2 ) ) + V_302 - 8 >
sizeof( V_2 -> V_303 ) ) ;
V_292 = & F_187 ( V_2 ) -> V_240 . V_304 ;
V_292 -> V_305 = V_306 ;
V_292 -> V_307 = V_4 -> type ;
V_292 -> V_308 = V_2 -> V_246 ;
V_292 -> V_309 = V_2 -> V_236 ;
if ( F_2 ( V_20 -> V_310 ) )
V_292 -> V_311 = V_206 -> V_95 ;
else
V_292 -> V_311 = V_4 -> V_95 ;
V_292 -> V_312 = F_218 ( V_2 , V_292 -> V_313 ) ;
F_187 ( V_2 ) -> V_314 = V_2 -> V_173 ;
if ( F_219 ( V_2 , V_295 ) )
goto V_300;
F_220 ( V_2 , V_27 ) ;
V_2 -> V_4 = NULL ;
F_185 ( V_2 ) ;
F_186 ( V_2 ) ;
F_47 ( & V_27 -> V_130 . V_80 ) ;
V_20 -> V_119 . V_315 . V_316 ++ ;
V_2 -> V_317 = F_90 ( & V_27 -> V_318 ) ;
F_221 ( & V_27 -> V_130 , V_2 ) ;
F_45 ( & V_27 -> V_130 . V_80 ) ;
V_27 -> V_319 ( V_27 ) ;
return 0 ;
V_300:
F_47 ( & V_27 -> V_130 . V_80 ) ;
V_20 -> V_119 . V_315 . V_149 ++ ;
F_119 ( & V_27 -> V_318 ) ;
F_45 ( & V_27 -> V_130 . V_80 ) ;
V_299:
if ( V_293 != V_2 -> V_82 && F_214 ( V_2 ) ) {
V_2 -> V_82 = V_293 ;
V_2 -> V_173 = V_294 ;
}
V_14:
F_216 ( V_2 ) ;
return 0 ;
}
static int V_184 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_204 * V_205 , struct V_3 * V_206 )
{
struct V_26 * V_27 ;
struct V_19 * V_20 ;
struct V_291 * V_292 ;
union V_35 V_36 ;
T_5 * V_293 = V_2 -> V_82 ;
int V_294 = V_2 -> V_173 ;
unsigned int V_295 , V_288 ;
unsigned long V_34 = V_143 ;
unsigned short V_320 , V_321 , V_115 ;
struct V_1 * V_322 = NULL ;
struct V_45 V_46 ;
T_3 V_55 ;
F_217 ( F_222 ( sizeof( * V_36 . V_43 ) ) != 32 ) ;
F_217 ( F_222 ( sizeof( * V_36 . V_323 ) ) != 48 ) ;
if ( V_2 -> V_236 == V_237 )
goto V_14;
V_27 = V_205 -> V_207 ;
V_20 = F_37 ( V_27 ) ;
if ( ! F_162 ( F_163 ( V_4 ) , F_76 ( V_27 ) ) )
goto V_14;
if ( V_4 -> V_274 ) {
if ( V_27 -> V_296 != V_297 )
F_188 ( V_2 , V_2 -> V_82 - F_189 ( V_2 ) ) ;
else if ( V_2 -> V_236 == V_298 ) {
F_212 ( V_2 , F_213 ( V_2 ) ) ;
}
}
if ( V_2 -> V_324 == V_325 )
V_34 |= V_326 ;
V_295 = V_2 -> V_173 ;
V_288 = F_209 ( V_2 , V_27 , V_295 ) ;
if ( ! V_288 )
goto V_299;
if ( V_295 > V_288 )
V_295 = V_288 ;
if ( V_27 -> V_296 == V_297 ) {
V_320 = V_321 = F_222 ( V_20 -> V_116 ) + 16 +
V_20 -> V_327 ;
} else {
unsigned int V_328 = F_213 ( V_2 ) ;
V_321 = F_222 ( V_20 -> V_116 +
( V_328 < 16 ? 16 : V_328 ) ) +
V_20 -> V_327 ;
V_320 = V_321 - V_328 ;
}
if ( V_20 -> V_38 <= V_42 ) {
if ( V_320 + V_295 > V_20 -> V_79 . V_71 ) {
if ( V_20 -> V_329 &&
F_90 ( & V_27 -> V_185 ) < V_27 -> V_187 ) {
if ( F_214 ( V_2 ) ) {
V_322 = F_215 ( V_2 , V_238 ) ;
} else {
V_322 = F_223 ( V_2 ) ;
V_293 = V_2 -> V_82 ;
}
if ( V_322 )
F_220 ( V_322 , V_27 ) ;
}
V_295 = V_20 -> V_79 . V_71 - V_320 ;
if ( ( int ) V_295 < 0 )
V_295 = 0 ;
}
} else if ( F_2 ( V_320 + V_295 >
F_66 ( & V_20 -> V_79 ) -> V_127 ) ) {
T_4 V_330 ;
V_330 = F_66 ( & V_20 -> V_79 ) -> V_127 - V_320 ;
F_224 ( L_4 ,
V_295 , V_330 , V_320 ) ;
V_295 = V_330 ;
if ( F_2 ( ( int ) V_295 < 0 ) ) {
V_295 = 0 ;
V_320 = F_66 ( & V_20 -> V_79 ) -> V_127 ;
}
}
F_47 ( & V_27 -> V_130 . V_80 ) ;
V_36 . V_37 = F_122 ( V_20 , V_2 ,
V_160 , ( V_320 + V_295 ) ) ;
if ( ! V_36 . V_37 )
goto V_331;
if ( V_20 -> V_38 <= V_42 ) {
F_129 ( V_20 , & V_20 -> V_79 ) ;
if ( V_20 -> V_119 . V_315 . V_149 )
V_34 |= V_150 ;
}
V_20 -> V_119 . V_315 . V_316 ++ ;
if ( V_322 ) {
V_34 |= V_332 ;
F_221 ( & V_27 -> V_130 , V_322 ) ;
}
F_45 ( & V_27 -> V_130 . V_80 ) ;
F_225 ( V_2 , 0 , V_36 . V_37 + V_320 , V_295 ) ;
if ( ! ( V_55 = F_57 ( V_2 , & V_46 , V_20 -> V_56 ) ) )
F_99 ( & V_46 ) ;
V_34 |= V_55 ;
switch ( V_20 -> V_38 ) {
case V_39 :
V_36 . V_40 -> V_333 = V_2 -> V_173 ;
V_36 . V_40 -> V_334 = V_295 ;
V_36 . V_40 -> V_335 = V_320 ;
V_36 . V_40 -> V_336 = V_321 ;
V_36 . V_40 -> V_57 = V_46 . V_58 ;
V_36 . V_40 -> V_59 = V_46 . V_60 / V_61 ;
V_115 = sizeof( * V_36 . V_40 ) ;
break;
case V_42 :
V_36 . V_43 -> V_333 = V_2 -> V_173 ;
V_36 . V_43 -> V_334 = V_295 ;
V_36 . V_43 -> V_335 = V_320 ;
V_36 . V_43 -> V_336 = V_321 ;
V_36 . V_43 -> V_57 = V_46 . V_58 ;
V_36 . V_43 -> V_62 = V_46 . V_60 ;
if ( F_113 ( V_2 ) ) {
V_36 . V_43 -> V_164 = F_114 ( V_2 ) ;
V_36 . V_43 -> V_165 = F_115 ( V_2 -> V_166 ) ;
V_34 |= V_167 | V_168 ;
} else {
V_36 . V_43 -> V_164 = 0 ;
V_36 . V_43 -> V_165 = 0 ;
}
memset ( V_36 . V_43 -> V_170 , 0 , sizeof( V_36 . V_43 -> V_170 ) ) ;
V_115 = sizeof( * V_36 . V_43 ) ;
break;
case V_44 :
V_36 . V_323 -> V_41 |= V_34 ;
V_36 . V_323 -> V_333 = V_2 -> V_173 ;
V_36 . V_323 -> V_334 = V_295 ;
V_36 . V_323 -> V_335 = V_320 ;
V_36 . V_323 -> V_336 = V_321 ;
V_36 . V_323 -> V_57 = V_46 . V_58 ;
V_36 . V_323 -> V_62 = V_46 . V_60 ;
memset ( V_36 . V_323 -> V_170 , 0 , sizeof( V_36 . V_323 -> V_170 ) ) ;
V_115 = sizeof( * V_36 . V_323 ) ;
break;
default:
F_53 () ;
}
V_292 = V_36 . V_37 + F_222 ( V_115 ) ;
V_292 -> V_312 = F_218 ( V_2 , V_292 -> V_313 ) ;
V_292 -> V_305 = V_306 ;
V_292 -> V_307 = V_4 -> type ;
V_292 -> V_308 = V_2 -> V_246 ;
V_292 -> V_309 = V_2 -> V_236 ;
if ( F_2 ( V_20 -> V_310 ) )
V_292 -> V_311 = V_206 -> V_95 ;
else
V_292 -> V_311 = V_4 -> V_95 ;
F_121 () ;
#if V_137 == 1
if ( V_20 -> V_38 <= V_42 ) {
T_5 * V_138 , * V_139 ;
V_139 = ( T_5 * ) F_96 ( ( unsigned long ) V_36 . V_37 +
V_320 + V_295 ) ;
for ( V_138 = V_36 . V_37 ; V_138 < V_139 ; V_138 += V_140 )
F_50 ( F_51 ( V_138 ) ) ;
}
F_54 () ;
#endif
if ( V_20 -> V_38 <= V_42 )
F_49 ( V_20 , V_36 . V_37 , V_34 ) ;
else
F_107 ( & V_20 -> V_79 ) ;
V_27 -> V_319 ( V_27 ) ;
V_299:
if ( V_293 != V_2 -> V_82 && F_214 ( V_2 ) ) {
V_2 -> V_82 = V_293 ;
V_2 -> V_173 = V_294 ;
}
V_14:
F_18 ( V_2 ) ;
return 0 ;
V_331:
V_20 -> V_119 . V_315 . V_149 ++ ;
F_45 ( & V_27 -> V_130 . V_80 ) ;
V_27 -> V_319 ( V_27 ) ;
F_18 ( V_322 ) ;
goto V_299;
}
static void F_226 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_37 ( V_2 -> V_27 ) ;
if ( F_23 ( V_20 -> V_76 . V_69 ) ) {
void * V_337 ;
T_3 V_46 ;
V_337 = F_206 ( V_2 ) -> V_338 ;
F_133 ( & V_20 -> V_76 ) ;
V_46 = F_60 ( V_20 , V_337 , V_2 ) ;
F_49 ( V_20 , V_337 , V_169 | V_46 ) ;
}
F_227 ( V_2 ) ;
}
static int F_228 ( struct V_19 * V_20 , struct V_1 * V_2 ,
void * V_33 , struct V_3 * V_4 , int V_339 ,
T_7 V_254 , unsigned char * V_340 , int V_341 )
{
union V_35 V_337 ;
int V_342 , V_343 , V_173 , V_333 , V_344 , V_345 ;
struct V_249 * V_26 = V_20 -> V_27 . V_346 ;
struct V_347 * V_347 ;
void * V_82 ;
int V_93 ;
V_337 . V_37 = V_33 ;
V_2 -> V_246 = V_254 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_282 = V_20 -> V_27 . V_283 ;
V_2 -> V_284 = V_20 -> V_27 . V_285 ;
F_205 ( & V_20 -> V_27 , & F_206 ( V_2 ) -> V_286 ) ;
F_206 ( V_2 ) -> V_338 = V_337 . V_37 ;
switch ( V_20 -> V_38 ) {
case V_42 :
V_333 = V_337 . V_43 -> V_333 ;
break;
default:
V_333 = V_337 . V_40 -> V_333 ;
break;
}
if ( F_2 ( V_333 > V_339 ) ) {
F_147 ( L_5 , V_333 , V_339 ) ;
return - V_266 ;
}
F_198 ( V_2 , V_341 ) ;
F_199 ( V_2 ) ;
if ( ! F_30 ( V_20 ) )
F_207 ( V_2 , 0 ) ;
if ( F_2 ( V_20 -> V_348 ) ) {
int V_349 , V_350 , V_351 ;
V_349 = V_20 -> V_116 - sizeof( struct V_291 ) ;
V_350 = V_20 -> V_76 . V_71 - V_333 ;
if ( V_26 -> type == V_297 ) {
switch ( V_20 -> V_38 ) {
case V_42 :
V_351 = V_337 . V_43 -> V_336 ;
break;
default:
V_351 = V_337 . V_40 -> V_336 ;
break;
}
} else {
switch ( V_20 -> V_38 ) {
case V_42 :
V_351 = V_337 . V_43 -> V_335 ;
break;
default:
V_351 = V_337 . V_40 -> V_335 ;
break;
}
}
if ( F_2 ( ( V_351 < V_349 ) || ( V_350 < V_351 ) ) )
return - V_223 ;
V_82 = V_337 . V_37 + V_351 ;
} else {
V_82 = V_337 . V_37 + V_20 -> V_116 - sizeof( struct V_291 ) ;
}
V_342 = V_333 ;
if ( V_26 -> type == V_297 ) {
V_93 = F_229 ( V_2 , V_4 , F_115 ( V_254 ) , V_340 ,
NULL , V_333 ) ;
if ( F_2 ( V_93 < 0 ) )
return - V_223 ;
} else if ( V_4 -> V_268 ) {
if ( F_2 ( V_333 <= V_4 -> V_268 ) ) {
F_147 ( L_6 ,
V_333 , V_4 -> V_268 ) ;
return - V_223 ;
}
F_188 ( V_2 , V_4 -> V_268 ) ;
V_93 = F_230 ( V_2 , 0 , V_82 ,
V_4 -> V_268 ) ;
if ( F_2 ( V_93 ) )
return V_93 ;
V_82 += V_4 -> V_268 ;
V_342 -= V_4 -> V_268 ;
}
V_343 = F_231 ( V_82 ) ;
V_345 = V_140 - V_343 ;
V_173 = ( ( V_342 > V_345 ) ? V_345 : V_342 ) ;
V_2 -> V_352 = V_342 ;
V_2 -> V_173 += V_342 ;
V_2 -> V_186 += V_342 ;
F_232 ( V_342 , & V_20 -> V_27 . V_189 ) ;
while ( F_23 ( V_342 ) ) {
V_344 = F_206 ( V_2 ) -> V_344 ;
if ( F_2 ( V_344 >= V_353 ) ) {
F_147 ( L_7 ,
V_353 ) ;
return - V_354 ;
}
V_347 = F_51 ( V_82 ) ;
V_82 += V_173 ;
F_50 ( V_347 ) ;
F_233 ( V_347 ) ;
F_234 ( V_2 , V_344 , V_347 , V_343 , V_173 ) ;
V_342 -= V_173 ;
V_343 = 0 ;
V_345 = V_140 ;
V_173 = ( ( V_342 > V_345 ) ? V_345 : V_342 ) ;
}
return V_333 ;
}
static int F_235 ( struct V_19 * V_20 , struct V_250 * V_251 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_7 V_254 ;
int V_93 , V_355 = 0 ;
void * V_337 ;
F_193 ( struct V_291 * , V_252 , V_251 -> V_253 ) ;
bool V_356 = ! ( V_251 -> V_357 & V_358 ) ;
int V_333 , V_339 ;
unsigned char * V_340 ;
int V_359 = 0 ;
int V_34 = V_169 ;
int V_341 , V_271 ;
F_169 ( & V_20 -> V_360 ) ;
if ( F_23 ( V_252 == NULL ) ) {
V_4 = F_20 ( V_20 ) ;
V_254 = V_20 -> V_193 ;
V_340 = NULL ;
} else {
V_93 = - V_223 ;
if ( V_251 -> V_256 < sizeof( struct V_291 ) )
goto V_131;
if ( V_251 -> V_256 < ( V_252 -> V_312
+ F_236 ( struct V_291 ,
V_313 ) ) )
goto V_131;
V_254 = V_252 -> V_308 ;
V_340 = V_252 -> V_313 ;
V_4 = F_237 ( F_76 ( & V_20 -> V_27 ) , V_252 -> V_311 ) ;
}
V_93 = - V_361 ;
if ( F_2 ( V_4 == NULL ) )
goto V_131;
V_93 = - V_262 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_263 ) ) )
goto V_362;
V_355 = V_4 -> V_268 + V_269 ;
V_339 = V_20 -> V_76 . V_71
- ( V_20 -> V_116 - sizeof( struct V_291 ) ) ;
if ( V_339 > V_4 -> V_267 + V_355 )
V_339 = V_4 -> V_267 + V_355 ;
do {
V_337 = F_62 ( V_20 , & V_20 -> V_76 ,
V_363 ) ;
if ( F_2 ( V_337 == NULL ) ) {
if ( V_356 && F_238 () )
F_239 () ;
continue;
}
V_34 = V_363 ;
V_341 = F_196 ( V_4 ) ;
V_271 = V_4 -> V_272 ;
V_2 = F_240 ( & V_20 -> V_27 ,
V_341 + V_271 + sizeof( struct V_291 ) ,
0 , & V_93 ) ;
if ( F_2 ( V_2 == NULL ) )
goto V_364;
V_333 = F_228 ( V_20 , V_2 , V_337 , V_4 , V_339 , V_254 ,
V_340 , V_341 ) ;
if ( V_333 > V_4 -> V_267 + V_4 -> V_268 ) {
struct V_278 * V_279 ;
F_202 ( V_2 ) ;
V_279 = F_203 ( V_2 ) ;
if ( V_279 -> V_280 != F_204 ( V_281 ) )
V_333 = - V_266 ;
}
if ( F_2 ( V_333 < 0 ) ) {
if ( V_20 -> V_365 ) {
F_49 ( V_20 , V_337 ,
V_169 ) ;
F_130 ( & V_20 -> V_76 ) ;
F_18 ( V_2 ) ;
continue;
} else {
V_34 = V_366 ;
V_93 = V_333 ;
goto V_364;
}
}
F_33 ( V_4 , V_2 ) ;
V_2 -> V_367 = F_226 ;
F_49 ( V_20 , V_337 , V_368 ) ;
F_131 ( & V_20 -> V_76 ) ;
V_34 = V_363 ;
V_93 = V_20 -> V_22 ( V_2 ) ;
if ( F_2 ( V_93 > 0 ) ) {
V_93 = F_241 ( V_93 ) ;
if ( V_93 && F_55 ( V_20 , V_337 ) ==
V_169 ) {
V_2 = NULL ;
goto V_364;
}
V_93 = 0 ;
}
F_130 ( & V_20 -> V_76 ) ;
V_359 += V_333 ;
} while ( F_23 ( ( V_337 != NULL ) ||
( V_356 && F_135 ( & V_20 -> V_76 ) ) ) );
V_93 = V_359 ;
goto V_362;
V_364:
F_49 ( V_20 , V_337 , V_34 ) ;
F_18 ( V_2 ) ;
V_362:
F_242 ( V_4 ) ;
V_131:
F_177 ( & V_20 -> V_360 ) ;
return V_93 ;
}
static struct V_1 * F_243 ( struct V_26 * V_27 , T_6 V_369 ,
T_6 V_355 , T_6 V_173 ,
T_6 V_370 , int V_371 ,
int * V_93 )
{
struct V_1 * V_2 ;
if ( V_369 + V_173 < V_140 || ! V_370 )
V_370 = V_173 ;
V_2 = F_244 ( V_27 , V_369 + V_370 , V_173 - V_370 , V_371 ,
V_93 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_198 ( V_2 , V_355 ) ;
F_201 ( V_2 , V_370 ) ;
V_2 -> V_352 = V_173 - V_370 ;
V_2 -> V_173 += V_173 - V_370 ;
return V_2 ;
}
static int F_245 ( struct V_249 * V_26 , struct V_250 * V_251 , T_6 V_173 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
F_193 ( struct V_291 * , V_252 , V_251 -> V_253 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_7 V_254 ;
unsigned char * V_340 ;
int V_93 , V_355 = 0 ;
struct V_372 V_373 = { 0 } ;
int V_343 = 0 ;
int V_374 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
unsigned short V_375 = 0 ;
int V_341 , V_271 ;
int V_255 = 0 ;
if ( F_23 ( V_252 == NULL ) ) {
V_4 = F_20 ( V_20 ) ;
V_254 = V_20 -> V_193 ;
V_340 = NULL ;
} else {
V_93 = - V_223 ;
if ( V_251 -> V_256 < sizeof( struct V_291 ) )
goto V_131;
if ( V_251 -> V_256 < ( V_252 -> V_312 + F_236 ( struct V_291 , V_313 ) ) )
goto V_131;
V_254 = V_252 -> V_308 ;
V_340 = V_252 -> V_313 ;
V_4 = F_237 ( F_76 ( V_27 ) , V_252 -> V_311 ) ;
}
V_93 = - V_361 ;
if ( F_2 ( V_4 == NULL ) )
goto V_261;
V_93 = - V_262 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_263 ) ) )
goto V_261;
if ( V_26 -> type == V_376 )
V_355 = V_4 -> V_268 ;
if ( V_20 -> V_377 ) {
V_374 = sizeof( V_373 ) ;
V_93 = - V_223 ;
if ( V_173 < V_374 )
goto V_261;
V_173 -= V_374 ;
V_93 = F_200 ( ( void * ) & V_373 , V_251 -> V_276 ,
V_374 ) ;
if ( V_93 < 0 )
goto V_261;
if ( ( V_373 . V_47 & V_378 ) &&
( V_373 . V_379 + V_373 . V_380 + 2 >
V_373 . V_381 ) )
V_373 . V_381 = V_373 . V_379 +
V_373 . V_380 + 2 ;
V_93 = - V_223 ;
if ( V_373 . V_381 > V_173 )
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
if ( F_2 ( F_146 ( V_27 , V_264 ) ) ) {
if ( ! F_195 ( V_4 ) ) {
V_93 = - V_265 ;
goto V_261;
}
V_255 = 4 ;
}
V_93 = - V_266 ;
if ( ! V_375 && ( V_173 > V_4 -> V_267 + V_355 + V_269 + V_255 ) )
goto V_261;
V_93 = - V_182 ;
V_341 = F_196 ( V_4 ) ;
V_271 = V_4 -> V_272 ;
V_2 = F_243 ( V_27 , V_341 + V_271 , V_341 , V_173 , V_373 . V_381 ,
V_251 -> V_357 & V_358 , & V_93 ) ;
if ( V_2 == NULL )
goto V_261;
F_246 ( V_2 , V_355 ) ;
V_93 = - V_223 ;
if ( V_26 -> type == V_297 &&
( V_343 = F_229 ( V_2 , V_4 , F_115 ( V_254 ) , V_340 , NULL , V_173 ) ) < 0 )
goto V_277;
V_93 = F_247 ( V_2 , V_343 , V_251 -> V_276 , 0 , V_173 ) ;
if ( V_93 )
goto V_277;
F_205 ( V_27 , & F_206 ( V_2 ) -> V_286 ) ;
if ( ! V_375 && ( V_173 > V_4 -> V_267 + V_355 + V_255 ) ) {
struct V_278 * V_279 ;
F_202 ( V_2 ) ;
V_279 = F_203 ( V_2 ) ;
if ( V_279 -> V_280 != F_204 ( V_281 ) ) {
V_93 = - V_266 ;
goto V_277;
}
}
V_2 -> V_246 = V_254 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_282 = V_27 -> V_283 ;
V_2 -> V_284 = V_27 -> V_285 ;
F_33 ( V_4 , V_2 ) ;
if ( V_20 -> V_377 ) {
if ( V_373 . V_47 & V_378 ) {
if ( ! F_248 ( V_2 , V_373 . V_379 ,
V_373 . V_380 ) ) {
V_93 = - V_223 ;
goto V_277;
}
}
F_206 ( V_2 ) -> V_391 = V_373 . V_391 ;
F_206 ( V_2 ) -> V_375 = V_375 ;
F_206 ( V_2 ) -> V_375 |= V_392 ;
F_206 ( V_2 ) -> V_393 = 0 ;
V_173 += V_374 ;
}
if ( ! F_30 ( V_20 ) )
F_207 ( V_2 , V_355 ) ;
if ( F_2 ( V_255 == 4 ) )
V_2 -> V_287 = 1 ;
V_93 = V_20 -> V_22 ( V_2 ) ;
if ( V_93 > 0 && ( V_93 = F_241 ( V_93 ) ) != 0 )
goto V_261;
F_242 ( V_4 ) ;
return V_173 ;
V_277:
F_18 ( V_2 ) ;
V_261:
if ( V_4 )
F_242 ( V_4 ) ;
V_131:
return V_93 ;
}
static int F_249 ( struct V_247 * V_248 , struct V_249 * V_26 ,
struct V_250 * V_251 , T_6 V_173 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
if ( V_20 -> V_76 . V_69 )
return F_235 ( V_20 , V_251 ) ;
else
return F_245 ( V_26 , V_251 , V_173 ) ;
}
static int F_250 ( struct V_249 * V_26 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 ;
struct V_209 * V_209 ;
union V_100 V_101 ;
if ( ! V_27 )
return 0 ;
V_209 = F_76 ( V_27 ) ;
V_20 = F_37 ( V_27 ) ;
F_169 ( & V_209 -> V_394 . V_395 ) ;
F_251 ( V_27 ) ;
F_177 ( & V_209 -> V_394 . V_395 ) ;
F_252 () ;
F_253 ( V_209 , V_27 -> V_396 , - 1 ) ;
F_254 () ;
F_47 ( & V_20 -> V_32 ) ;
F_48 ( V_27 , false ) ;
F_28 ( V_20 ) ;
if ( V_20 -> V_30 . V_4 ) {
F_242 ( V_20 -> V_30 . V_4 ) ;
V_20 -> V_30 . V_4 = NULL ;
}
F_45 ( & V_20 -> V_32 ) ;
F_255 ( V_27 ) ;
if ( V_20 -> V_79 . V_69 ) {
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_256 ( V_27 , & V_101 , 1 , 0 ) ;
}
if ( V_20 -> V_76 . V_69 ) {
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_256 ( V_27 , & V_101 , 1 , 1 ) ;
}
F_178 ( V_27 ) ;
F_46 () ;
F_257 ( V_27 ) ;
V_26 -> V_27 = NULL ;
F_144 ( & V_27 -> V_130 ) ;
F_140 ( V_20 ) ;
F_258 ( V_27 ) ;
F_259 ( V_27 ) ;
return 0 ;
}
static int F_260 ( struct V_26 * V_27 , struct V_3 * V_4 , T_7 V_254 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
const struct V_3 * V_397 ;
T_7 V_398 ;
bool V_399 ;
if ( V_20 -> V_29 ) {
if ( V_4 )
F_242 ( V_4 ) ;
return - V_223 ;
}
F_261 ( V_27 ) ;
F_47 ( & V_20 -> V_32 ) ;
V_398 = V_20 -> V_30 . type ;
V_397 = V_20 -> V_30 . V_4 ;
V_399 = V_398 != V_254 || V_397 != V_4 ;
if ( V_399 ) {
F_48 ( V_27 , true ) ;
V_20 -> V_193 = V_254 ;
V_20 -> V_30 . type = V_254 ;
if ( V_20 -> V_30 . V_4 )
F_242 ( V_20 -> V_30 . V_4 ) ;
V_20 -> V_30 . V_4 = V_4 ;
V_20 -> V_95 = V_4 ? V_4 -> V_95 : 0 ;
F_26 ( V_20 , V_4 ) ;
}
if ( V_254 == 0 || ! V_399 )
goto V_261;
if ( ! V_4 || ( V_4 -> V_47 & V_263 ) ) {
F_36 ( V_27 ) ;
} else {
V_27 -> V_400 = V_262 ;
if ( ! F_146 ( V_27 , V_190 ) )
V_27 -> V_401 ( V_27 ) ;
}
V_261:
F_45 ( & V_20 -> V_32 ) ;
F_262 ( V_27 ) ;
return 0 ;
}
static int F_263 ( struct V_249 * V_26 , struct V_257 * V_402 ,
int V_403 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
char V_244 [ 15 ] ;
struct V_3 * V_4 ;
int V_93 = - V_260 ;
if ( V_403 != sizeof( struct V_257 ) )
return - V_223 ;
F_190 ( V_244 , V_402 -> V_404 , sizeof( V_244 ) ) ;
V_4 = F_264 ( F_76 ( V_27 ) , V_244 ) ;
if ( V_4 )
V_93 = F_260 ( V_27 , V_4 , F_37 ( V_27 ) -> V_193 ) ;
return V_93 ;
}
static int F_265 ( struct V_249 * V_26 , struct V_257 * V_402 , int V_403 )
{
struct V_291 * V_292 = (struct V_291 * ) V_402 ;
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_3 * V_4 = NULL ;
int V_93 ;
if ( V_403 < sizeof( struct V_291 ) )
return - V_223 ;
if ( V_292 -> V_305 != V_306 )
return - V_223 ;
if ( V_292 -> V_311 ) {
V_93 = - V_260 ;
V_4 = F_237 ( F_76 ( V_27 ) , V_292 -> V_311 ) ;
if ( V_4 == NULL )
goto V_131;
}
V_93 = F_260 ( V_27 , V_4 , V_292 -> V_308 ? : F_37 ( V_27 ) -> V_193 ) ;
V_131:
return V_93 ;
}
static int F_266 ( struct V_209 * V_209 , struct V_249 * V_26 , int V_246 ,
int V_405 )
{
struct V_26 * V_27 ;
struct V_19 * V_20 ;
T_7 V_254 = ( V_406 T_7 ) V_246 ;
int V_93 ;
if ( ! F_267 ( V_209 -> V_407 , V_408 ) )
return - V_409 ;
if ( V_26 -> type != V_297 && V_26 -> type != V_376 &&
V_26 -> type != V_410 )
return - V_411 ;
V_26 -> V_412 = V_413 ;
V_93 = - V_182 ;
V_27 = F_268 ( V_209 , V_414 , V_227 , & V_415 ) ;
if ( V_27 == NULL )
goto V_131;
V_26 -> V_6 = & V_416 ;
if ( V_26 -> type == V_410 )
V_26 -> V_6 = & V_417 ;
F_269 ( V_26 , V_27 ) ;
V_20 = F_37 ( V_27 ) ;
V_27 -> V_418 = V_414 ;
V_20 -> V_193 = V_254 ;
V_20 -> V_22 = F_208 ;
V_93 = F_138 ( V_20 ) ;
if ( V_93 )
goto V_419;
F_28 ( V_20 ) ;
V_27 -> V_420 = F_143 ;
F_270 ( V_27 ) ;
F_175 ( & V_20 -> V_32 ) ;
F_271 ( & V_20 -> V_360 ) ;
V_20 -> V_30 . F_70 = F_211 ;
if ( V_26 -> type == V_410 )
V_20 -> V_30 . F_70 = F_183 ;
V_20 -> V_30 . V_207 = V_27 ;
if ( V_254 ) {
V_20 -> V_30 . type = V_254 ;
F_36 ( V_27 ) ;
}
F_169 ( & V_209 -> V_394 . V_395 ) ;
F_272 ( V_27 , & V_209 -> V_394 . V_421 ) ;
F_177 ( & V_209 -> V_394 . V_395 ) ;
F_252 () ;
F_253 ( V_209 , & V_415 , 1 ) ;
F_254 () ;
return 0 ;
V_419:
F_273 ( V_27 ) ;
V_131:
return V_93 ;
}
static int F_274 ( struct V_247 * V_248 , struct V_249 * V_26 ,
struct V_250 * V_251 , T_6 V_173 , int V_47 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_1 * V_2 ;
int V_422 , V_93 ;
int V_374 = 0 ;
V_93 = - V_223 ;
if ( V_47 & ~ ( V_423 | V_358 | V_424 | V_425 | V_426 ) )
goto V_131;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_47 & V_426 ) {
V_93 = F_275 ( V_27 , V_251 , V_173 ,
V_427 , V_428 ) ;
goto V_131;
}
V_2 = F_276 ( V_27 , V_47 , V_47 & V_358 , & V_93 ) ;
if ( V_2 == NULL )
goto V_131;
if ( F_37 ( V_27 ) -> V_377 ) {
struct V_372 V_373 = { 0 } ;
V_93 = - V_223 ;
V_374 = sizeof( V_373 ) ;
if ( V_173 < V_374 )
goto V_277;
V_173 -= V_374 ;
if ( F_277 ( V_2 ) ) {
struct V_429 * V_430 = F_206 ( V_2 ) ;
V_373 . V_381 = F_278 ( V_2 ) ;
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
F_53 () ;
if ( V_430 -> V_375 & V_390 )
V_373 . V_375 |= V_383 ;
} else
V_373 . V_375 = V_382 ;
if ( V_2 -> V_324 == V_325 ) {
V_373 . V_47 = V_378 ;
V_373 . V_379 = F_279 ( V_2 ) ;
V_373 . V_380 = V_2 -> V_380 ;
} else if ( V_2 -> V_324 == V_432 ) {
V_373 . V_47 = V_433 ;
}
V_93 = F_280 ( V_251 -> V_276 , ( void * ) & V_373 ,
V_374 ) ;
if ( V_93 < 0 )
goto V_277;
}
V_422 = V_2 -> V_173 ;
if ( V_422 > V_173 ) {
V_422 = V_173 ;
V_251 -> V_357 |= V_424 ;
}
V_93 = F_281 ( V_2 , 0 , V_251 -> V_276 , V_422 ) ;
if ( V_93 )
goto V_277;
F_282 ( V_251 , V_27 , V_2 ) ;
if ( V_251 -> V_253 ) {
if ( V_26 -> type == V_410 ) {
F_283 ( sizeof( struct V_234 ) ) ;
V_251 -> V_256 = sizeof( struct V_234 ) ;
} else {
struct V_291 * V_292 = & F_187 ( V_2 ) -> V_240 . V_304 ;
V_251 -> V_256 = V_292 -> V_312 +
F_236 ( struct V_291 , V_313 ) ;
}
memcpy ( V_251 -> V_253 , & F_187 ( V_2 ) -> V_240 ,
V_251 -> V_256 ) ;
}
if ( F_37 ( V_27 ) -> V_434 ) {
struct V_435 V_436 ;
V_436 . V_41 = V_143 ;
if ( V_2 -> V_324 == V_325 )
V_436 . V_41 |= V_326 ;
V_436 . V_333 = F_187 ( V_2 ) -> V_314 ;
V_436 . V_334 = V_2 -> V_173 ;
V_436 . V_335 = 0 ;
V_436 . V_336 = F_213 ( V_2 ) ;
if ( F_113 ( V_2 ) ) {
V_436 . V_164 = F_114 ( V_2 ) ;
V_436 . V_165 = F_115 ( V_2 -> V_166 ) ;
V_436 . V_41 |= V_167 | V_168 ;
} else {
V_436 . V_164 = 0 ;
V_436 . V_165 = 0 ;
}
F_284 ( V_251 , V_427 , V_437 , sizeof( V_436 ) , & V_436 ) ;
}
V_93 = V_374 + ( ( V_47 & V_424 ) ? V_2 -> V_173 : V_422 ) ;
V_277:
F_285 ( V_27 , V_2 ) ;
V_131:
return V_93 ;
}
static int F_286 ( struct V_249 * V_26 , struct V_257 * V_402 ,
int * V_438 , int V_439 )
{
struct V_3 * V_4 ;
struct V_26 * V_27 = V_26 -> V_27 ;
if ( V_439 )
return - V_440 ;
V_402 -> V_441 = V_306 ;
memset ( V_402 -> V_404 , 0 , sizeof( V_402 -> V_404 ) ) ;
F_21 () ;
V_4 = F_287 ( F_76 ( V_27 ) , F_37 ( V_27 ) -> V_95 ) ;
if ( V_4 )
F_190 ( V_402 -> V_404 , V_4 -> V_244 , sizeof( V_402 -> V_404 ) ) ;
F_25 () ;
* V_438 = sizeof( * V_402 ) ;
return 0 ;
}
static int F_288 ( struct V_249 * V_26 , struct V_257 * V_402 ,
int * V_438 , int V_439 )
{
struct V_3 * V_4 ;
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
F_193 ( struct V_291 * , V_292 , V_402 ) ;
if ( V_439 )
return - V_440 ;
V_292 -> V_305 = V_306 ;
V_292 -> V_311 = V_20 -> V_95 ;
V_292 -> V_308 = V_20 -> V_193 ;
V_292 -> V_309 = 0 ;
F_21 () ;
V_4 = F_287 ( F_76 ( V_27 ) , V_20 -> V_95 ) ;
if ( V_4 ) {
V_292 -> V_307 = V_4 -> type ;
V_292 -> V_312 = V_4 -> V_403 ;
memcpy ( V_292 -> V_313 , V_4 -> V_442 , V_4 -> V_403 ) ;
} else {
V_292 -> V_307 = 0 ;
V_292 -> V_312 = 0 ;
}
F_25 () ;
* V_438 = F_236 ( struct V_291 , V_313 ) + V_292 -> V_312 ;
return 0 ;
}
static int F_289 ( struct V_3 * V_4 , struct V_443 * V_199 ,
int V_444 )
{
switch ( V_199 -> type ) {
case V_445 :
if ( V_199 -> V_446 != V_4 -> V_403 )
return - V_223 ;
if ( V_444 > 0 )
return F_290 ( V_4 , V_199 -> V_340 ) ;
else
return F_291 ( V_4 , V_199 -> V_340 ) ;
break;
case V_447 :
return F_292 ( V_4 , V_444 ) ;
case V_448 :
return F_293 ( V_4 , V_444 ) ;
case V_449 :
if ( V_199 -> V_446 != V_4 -> V_403 )
return - V_223 ;
if ( V_444 > 0 )
return F_294 ( V_4 , V_199 -> V_340 ) ;
else
return F_295 ( V_4 , V_199 -> V_340 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_296 ( struct V_3 * V_4 , struct V_443 * V_199 , int V_444 )
{
for ( ; V_199 ; V_199 = V_199 -> V_201 ) {
if ( V_199 -> V_95 == V_4 -> V_95 )
F_289 ( V_4 , V_199 , V_444 ) ;
}
}
static int F_297 ( struct V_26 * V_27 , struct V_450 * V_451 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
struct V_443 * V_452 , * V_199 ;
struct V_3 * V_4 ;
int V_93 ;
F_74 () ;
V_93 = - V_260 ;
V_4 = F_75 ( F_76 ( V_27 ) , V_451 -> V_453 ) ;
if ( ! V_4 )
goto V_454;
V_93 = - V_223 ;
if ( V_451 -> V_455 > V_4 -> V_403 )
goto V_454;
V_93 = - V_182 ;
V_199 = F_298 ( sizeof( * V_199 ) , V_227 ) ;
if ( V_199 == NULL )
goto V_454;
V_93 = 0 ;
for ( V_452 = V_20 -> V_456 ; V_452 ; V_452 = V_452 -> V_201 ) {
if ( V_452 -> V_95 == V_451 -> V_453 &&
V_452 -> type == V_451 -> V_457 &&
V_452 -> V_446 == V_451 -> V_455 &&
memcmp ( V_452 -> V_340 , V_451 -> V_458 , V_452 -> V_446 ) == 0 ) {
V_452 -> V_459 ++ ;
F_182 ( V_199 ) ;
goto V_454;
}
}
V_199 -> type = V_451 -> V_457 ;
V_199 -> V_95 = V_451 -> V_453 ;
V_199 -> V_446 = V_451 -> V_455 ;
memcpy ( V_199 -> V_340 , V_451 -> V_458 , V_199 -> V_446 ) ;
V_199 -> V_459 = 1 ;
V_199 -> V_201 = V_20 -> V_456 ;
V_20 -> V_456 = V_199 ;
V_93 = F_289 ( V_4 , V_199 , 1 ) ;
if ( V_93 ) {
V_20 -> V_456 = V_199 -> V_201 ;
F_182 ( V_199 ) ;
}
V_454:
F_77 () ;
return V_93 ;
}
static int F_299 ( struct V_26 * V_27 , struct V_450 * V_451 )
{
struct V_443 * V_452 , * * V_460 ;
F_74 () ;
for ( V_460 = & F_37 ( V_27 ) -> V_456 ; ( V_452 = * V_460 ) != NULL ; V_460 = & V_452 -> V_201 ) {
if ( V_452 -> V_95 == V_451 -> V_453 &&
V_452 -> type == V_451 -> V_457 &&
V_452 -> V_446 == V_451 -> V_455 &&
memcmp ( V_452 -> V_340 , V_451 -> V_458 , V_452 -> V_446 ) == 0 ) {
if ( -- V_452 -> V_459 == 0 ) {
struct V_3 * V_4 ;
* V_460 = V_452 -> V_201 ;
V_4 = F_75 ( F_76 ( V_27 ) , V_452 -> V_95 ) ;
if ( V_4 )
F_289 ( V_4 , V_452 , - 1 ) ;
F_182 ( V_452 ) ;
}
F_77 () ;
return 0 ;
}
}
F_77 () ;
return - V_461 ;
}
static void F_255 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_37 ( V_27 ) ;
struct V_443 * V_452 ;
if ( ! V_20 -> V_456 )
return;
F_74 () ;
while ( ( V_452 = V_20 -> V_456 ) != NULL ) {
struct V_3 * V_4 ;
V_20 -> V_456 = V_452 -> V_201 ;
V_4 = F_75 ( F_76 ( V_27 ) , V_452 -> V_95 ) ;
if ( V_4 != NULL )
F_289 ( V_4 , V_452 , - 1 ) ;
F_182 ( V_452 ) ;
}
F_77 () ;
}
static int
F_300 ( struct V_249 * V_26 , int V_462 , int V_463 , char T_8 * V_464 , unsigned int V_465 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
int V_11 ;
if ( V_462 != V_427 )
return - V_466 ;
switch ( V_463 ) {
case V_467 :
case V_468 :
{
struct V_450 V_451 ;
int V_173 = V_465 ;
memset ( & V_451 , 0 , sizeof( V_451 ) ) ;
if ( V_173 < sizeof( struct V_469 ) )
return - V_223 ;
if ( V_173 > sizeof( V_451 ) )
V_173 = sizeof( V_451 ) ;
if ( F_301 ( & V_451 , V_464 , V_173 ) )
return - V_354 ;
if ( V_173 < ( V_451 . V_455 + F_236 ( struct V_469 , V_458 ) ) )
return - V_223 ;
if ( V_463 == V_467 )
V_11 = F_297 ( V_27 , & V_451 ) ;
else
V_11 = F_299 ( V_27 , & V_451 ) ;
return V_11 ;
}
case V_470 :
case V_471 :
{
union V_100 V_101 ;
int V_173 ;
switch ( V_20 -> V_38 ) {
case V_39 :
case V_42 :
V_173 = sizeof( V_101 . V_472 ) ;
break;
case V_44 :
default:
V_173 = sizeof( V_101 . V_103 ) ;
break;
}
if ( V_465 < V_173 )
return - V_223 ;
if ( F_37 ( V_27 ) -> V_377 )
return - V_223 ;
if ( F_301 ( & V_101 . V_472 , V_464 , V_173 ) )
return - V_354 ;
return F_256 ( V_27 , & V_101 , 0 ,
V_463 == V_471 ) ;
}
case V_473 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
F_37 ( V_27 ) -> V_329 = V_474 ;
return 0 ;
}
case V_475 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( V_20 -> V_79 . V_69 || V_20 -> V_76 . V_69 )
return - V_476 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
switch ( V_474 ) {
case V_39 :
case V_42 :
case V_44 :
V_20 -> V_38 = V_474 ;
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
if ( V_20 -> V_79 . V_69 || V_20 -> V_76 . V_69 )
return - V_476 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_20 -> V_327 = V_474 ;
return 0 ;
}
case V_478 :
{
unsigned int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( V_20 -> V_79 . V_69 || V_20 -> V_76 . V_69 )
return - V_476 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_20 -> V_365 = ! ! V_474 ;
return 0 ;
}
case V_437 :
{
int V_474 ;
if ( V_465 < sizeof( V_474 ) )
return - V_223 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_20 -> V_434 = ! ! V_474 ;
return 0 ;
}
case V_479 :
{
int V_474 ;
if ( V_465 < sizeof( V_474 ) )
return - V_223 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_20 -> V_310 = ! ! V_474 ;
return 0 ;
}
case V_480 :
{
int V_474 ;
if ( V_26 -> type != V_376 )
return - V_223 ;
if ( V_20 -> V_79 . V_69 || V_20 -> V_76 . V_69 )
return - V_476 ;
if ( V_465 < sizeof( V_474 ) )
return - V_223 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_20 -> V_377 = ! ! V_474 ;
return 0 ;
}
case V_481 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_20 -> V_56 = V_474 ;
return 0 ;
}
case V_482 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
return F_168 ( V_27 , V_474 & 0xffff , V_474 >> 16 ) ;
}
case V_483 :
{
unsigned int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( V_20 -> V_79 . V_69 || V_20 -> V_76 . V_69 )
return - V_476 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_20 -> V_348 = ! ! V_474 ;
return 0 ;
}
case V_484 :
{
int V_474 ;
if ( V_465 != sizeof( V_474 ) )
return - V_223 ;
if ( F_301 ( & V_474 , V_464 , sizeof( V_474 ) ) )
return - V_354 ;
V_20 -> V_22 = V_474 ? F_1 : F_208 ;
return 0 ;
}
default:
return - V_466 ;
}
}
static int F_302 ( struct V_249 * V_26 , int V_462 , int V_463 ,
char T_8 * V_464 , int T_8 * V_465 )
{
int V_173 ;
int V_474 , V_485 = sizeof( V_474 ) ;
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
void * V_82 = & V_474 ;
union V_486 V_487 ;
if ( V_462 != V_427 )
return - V_466 ;
if ( F_303 ( V_173 , V_465 ) )
return - V_354 ;
if ( V_173 < 0 )
return - V_223 ;
switch ( V_463 ) {
case V_488 :
F_67 ( & V_27 -> V_130 . V_80 ) ;
memcpy ( & V_487 , & V_20 -> V_119 , sizeof( V_487 ) ) ;
memset ( & V_20 -> V_119 , 0 , sizeof( V_20 -> V_119 ) ) ;
F_68 ( & V_27 -> V_130 . V_80 ) ;
if ( V_20 -> V_38 == V_44 ) {
V_485 = sizeof( struct V_489 ) ;
V_487 . V_120 . V_316 += V_487 . V_120 . V_149 ;
V_82 = & V_487 . V_120 ;
} else {
V_485 = sizeof( struct V_490 ) ;
V_487 . V_315 . V_316 += V_487 . V_315 . V_149 ;
V_82 = & V_487 . V_315 ;
}
break;
case V_437 :
V_474 = V_20 -> V_434 ;
break;
case V_479 :
V_474 = V_20 -> V_310 ;
break;
case V_480 :
V_474 = V_20 -> V_377 ;
break;
case V_475 :
V_474 = V_20 -> V_38 ;
break;
case V_491 :
if ( V_173 > sizeof( int ) )
V_173 = sizeof( int ) ;
if ( F_301 ( & V_474 , V_464 , V_173 ) )
return - V_354 ;
switch ( V_474 ) {
case V_39 :
V_474 = sizeof( struct V_492 ) ;
break;
case V_42 :
V_474 = sizeof( struct V_493 ) ;
break;
case V_44 :
V_474 = sizeof( struct V_144 ) ;
break;
default:
return - V_223 ;
}
break;
case V_477 :
V_474 = V_20 -> V_327 ;
break;
case V_478 :
V_474 = V_20 -> V_365 ;
break;
case V_481 :
V_474 = V_20 -> V_56 ;
break;
case V_482 :
V_474 = ( V_20 -> V_29 ?
( ( T_4 ) V_20 -> V_29 -> V_220 |
( ( T_4 ) V_20 -> V_29 -> type << 16 ) |
( ( T_4 ) V_20 -> V_29 -> V_47 << 24 ) ) :
0 ) ;
break;
case V_483 :
V_474 = V_20 -> V_348 ;
break;
case V_484 :
V_474 = F_30 ( V_20 ) ;
break;
default:
return - V_466 ;
}
if ( V_173 > V_485 )
V_173 = V_485 ;
if ( F_304 ( V_173 , V_465 ) )
return - V_354 ;
if ( F_305 ( V_464 , V_82 , V_173 ) )
return - V_354 ;
return 0 ;
}
static int F_306 ( struct V_494 * V_495 ,
unsigned long V_251 , void * V_496 )
{
struct V_26 * V_27 ;
struct V_3 * V_4 = F_307 ( V_496 ) ;
struct V_209 * V_209 = F_163 ( V_4 ) ;
F_21 () ;
F_308 (sk, &net->packet.sklist) {
struct V_19 * V_20 = F_37 ( V_27 ) ;
switch ( V_251 ) {
case V_497 :
if ( V_20 -> V_456 )
F_296 ( V_4 , V_20 -> V_456 , - 1 ) ;
case V_498 :
if ( V_4 -> V_95 == V_20 -> V_95 ) {
F_47 ( & V_20 -> V_32 ) ;
if ( V_20 -> V_28 ) {
F_41 ( V_27 , false ) ;
V_27 -> V_400 = V_262 ;
if ( ! F_146 ( V_27 , V_190 ) )
V_27 -> V_401 ( V_27 ) ;
}
if ( V_251 == V_497 ) {
F_28 ( V_20 ) ;
V_20 -> V_95 = - 1 ;
if ( V_20 -> V_30 . V_4 )
F_242 ( V_20 -> V_30 . V_4 ) ;
V_20 -> V_30 . V_4 = NULL ;
}
F_45 ( & V_20 -> V_32 ) ;
}
break;
case V_499 :
if ( V_4 -> V_95 == V_20 -> V_95 ) {
F_47 ( & V_20 -> V_32 ) ;
if ( V_20 -> V_193 )
F_36 ( V_27 ) ;
F_45 ( & V_20 -> V_32 ) ;
}
break;
}
}
F_25 () ;
return V_500 ;
}
static int F_309 ( struct V_249 * V_26 , unsigned int V_501 ,
unsigned long V_502 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
switch ( V_501 ) {
case V_503 :
{
int V_504 = F_310 ( V_27 ) ;
return F_304 ( V_504 , ( int T_8 * ) V_502 ) ;
}
case V_505 :
{
struct V_1 * V_2 ;
int V_504 = 0 ;
F_67 ( & V_27 -> V_130 . V_80 ) ;
V_2 = F_311 ( & V_27 -> V_130 ) ;
if ( V_2 )
V_504 = V_2 -> V_173 ;
F_68 ( & V_27 -> V_130 . V_80 ) ;
return F_304 ( V_504 , ( int T_8 * ) V_502 ) ;
}
case V_506 :
return F_312 ( V_27 , (struct V_507 T_8 * ) V_502 ) ;
case V_508 :
return F_313 ( V_27 , (struct V_45 T_8 * ) V_502 ) ;
#ifdef F_314
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
return V_523 . V_524 ( V_26 , V_501 , V_502 ) ;
#endif
default:
return - V_525 ;
}
return 0 ;
}
static unsigned int F_315 ( struct V_526 * V_526 , struct V_249 * V_26 ,
T_9 * V_527 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
unsigned int V_528 = F_316 ( V_526 , V_26 , V_527 ) ;
F_67 ( & V_27 -> V_130 . V_80 ) ;
if ( V_20 -> V_79 . V_69 ) {
if ( ! F_127 ( V_20 , & V_20 -> V_79 ,
V_160 ) )
V_528 |= V_529 | V_530 ;
}
F_68 ( & V_27 -> V_130 . V_80 ) ;
F_67 ( & V_27 -> V_531 . V_80 ) ;
if ( V_20 -> V_76 . V_69 ) {
if ( F_62 ( V_20 , & V_20 -> V_76 , V_169 ) )
V_528 |= V_532 | V_533 ;
}
F_68 ( & V_27 -> V_531 . V_80 ) ;
return V_528 ;
}
static void F_317 ( struct V_534 * V_535 )
{
struct V_526 * V_526 = V_535 -> V_536 ;
struct V_249 * V_26 = V_526 -> V_537 ;
struct V_26 * V_27 = V_26 -> V_27 ;
if ( V_27 )
F_119 ( & F_37 ( V_27 ) -> V_538 ) ;
}
static void F_318 ( struct V_534 * V_535 )
{
struct V_526 * V_526 = V_535 -> V_536 ;
struct V_249 * V_26 = V_526 -> V_537 ;
struct V_26 * V_27 = V_26 -> V_27 ;
if ( V_27 )
F_108 ( & F_37 ( V_27 ) -> V_538 ) ;
}
static void F_319 ( struct V_105 * V_69 , unsigned int V_539 ,
unsigned int V_173 )
{
int V_199 ;
for ( V_199 = 0 ; V_199 < V_173 ; V_199 ++ ) {
if ( F_23 ( V_69 [ V_199 ] . V_70 ) ) {
if ( F_320 ( V_69 [ V_199 ] . V_70 ) )
F_321 ( V_69 [ V_199 ] . V_70 ) ;
else
F_322 ( ( unsigned long ) V_69 [ V_199 ] . V_70 ,
V_539 ) ;
V_69 [ V_199 ] . V_70 = NULL ;
}
}
F_182 ( V_69 ) ;
}
static char * F_323 ( unsigned long V_539 )
{
char * V_70 ;
T_10 V_540 = V_227 | V_541 |
V_542 | V_543 | V_544 ;
V_70 = ( char * ) F_324 ( V_540 , V_539 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_325 ( ( 1 << V_539 ) * V_140 ) ;
if ( V_70 )
return V_70 ;
V_540 &= ~ V_544 ;
V_70 = ( char * ) F_324 ( V_540 , V_539 ) ;
if ( V_70 )
return V_70 ;
return NULL ;
}
static struct V_105 * F_326 ( struct V_545 * V_472 , int V_539 )
{
unsigned int V_546 = V_472 -> V_114 ;
struct V_105 * V_69 ;
int V_199 ;
V_69 = F_327 ( V_546 , sizeof( struct V_105 ) , V_227 ) ;
if ( F_2 ( ! V_69 ) )
goto V_131;
for ( V_199 = 0 ; V_199 < V_546 ; V_199 ++ ) {
V_69 [ V_199 ] . V_70 = F_323 ( V_539 ) ;
if ( F_2 ( ! V_69 [ V_199 ] . V_70 ) )
goto V_547;
}
V_131:
return V_69 ;
V_547:
F_319 ( V_69 , V_539 , V_546 ) ;
V_69 = NULL ;
goto V_131;
}
static int F_256 ( struct V_26 * V_27 , union V_100 * V_101 ,
int V_548 , int V_76 )
{
struct V_105 * V_69 = NULL ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
int V_549 , V_539 = 0 ;
struct V_63 * V_64 ;
struct V_77 * V_78 ;
T_7 V_193 ;
int V_93 = - V_223 ;
struct V_545 * V_472 = & V_101 -> V_472 ;
if ( ! V_548 && V_76 && ( V_20 -> V_38 > V_42 ) ) {
F_52 ( 1 , L_8 ) ;
goto V_131;
}
V_64 = V_76 ? & V_20 -> V_76 : & V_20 -> V_79 ;
V_78 = V_76 ? & V_27 -> V_531 : & V_27 -> V_130 ;
V_93 = - V_476 ;
if ( ! V_548 ) {
if ( F_90 ( & V_20 -> V_538 ) )
goto V_131;
if ( F_135 ( V_64 ) )
goto V_131;
}
if ( V_472 -> V_114 ) {
V_93 = - V_476 ;
if ( F_2 ( V_64 -> V_69 ) )
goto V_131;
switch ( V_20 -> V_38 ) {
case V_39 :
V_20 -> V_116 = V_550 ;
break;
case V_42 :
V_20 -> V_116 = V_551 ;
break;
case V_44 :
V_20 -> V_116 = V_552 ;
break;
}
V_93 = - V_223 ;
if ( F_2 ( ( int ) V_472 -> V_112 <= 0 ) )
goto V_131;
if ( F_2 ( V_472 -> V_112 & ( V_140 - 1 ) ) )
goto V_131;
if ( V_20 -> V_38 >= V_44 &&
( int ) ( V_472 -> V_112 -
F_83 ( V_101 -> V_103 . V_126 ) ) <= 0 )
goto V_131;
if ( F_2 ( V_472 -> V_553 < V_20 -> V_116 +
V_20 -> V_327 ) )
goto V_131;
if ( F_2 ( V_472 -> V_553 & ( V_554 - 1 ) ) )
goto V_131;
V_64 -> V_68 = V_472 -> V_112 / V_472 -> V_553 ;
if ( F_2 ( V_64 -> V_68 <= 0 ) )
goto V_131;
if ( F_2 ( ( V_64 -> V_68 * V_472 -> V_114 ) !=
V_472 -> V_555 ) )
goto V_131;
V_93 = - V_226 ;
V_539 = F_328 ( V_472 -> V_112 ) ;
V_69 = F_326 ( V_472 , V_539 ) ;
if ( F_2 ( ! V_69 ) )
goto V_131;
switch ( V_20 -> V_38 ) {
case V_44 :
if ( ! V_76 )
F_81 ( V_20 , V_64 , V_69 , V_101 , V_76 ) ;
break;
default:
break;
}
}
else {
V_93 = - V_223 ;
if ( F_2 ( V_472 -> V_555 ) )
goto V_131;
}
F_261 ( V_27 ) ;
F_47 ( & V_20 -> V_32 ) ;
V_549 = V_20 -> V_28 ;
V_193 = V_20 -> V_193 ;
if ( V_549 ) {
V_20 -> V_193 = 0 ;
F_41 ( V_27 , false ) ;
}
F_45 ( & V_20 -> V_32 ) ;
F_46 () ;
V_93 = - V_476 ;
F_169 ( & V_20 -> V_360 ) ;
if ( V_548 || F_90 ( & V_20 -> V_538 ) == 0 ) {
V_93 = 0 ;
F_67 ( & V_78 -> V_80 ) ;
F_329 ( V_64 -> V_69 , V_69 ) ;
V_64 -> V_177 = ( V_472 -> V_555 - 1 ) ;
V_64 -> V_72 = 0 ;
V_64 -> V_71 = V_472 -> V_553 ;
F_68 ( & V_78 -> V_80 ) ;
F_329 ( V_64 -> V_556 , V_539 ) ;
F_329 ( V_64 -> V_557 , V_472 -> V_114 ) ;
V_64 -> V_558 = V_472 -> V_112 / V_140 ;
V_20 -> V_30 . F_70 = ( V_20 -> V_79 . V_69 ) ?
V_184 : F_211 ;
F_144 ( V_78 ) ;
if ( F_90 ( & V_20 -> V_538 ) )
F_147 ( L_9 ,
F_90 ( & V_20 -> V_538 ) ) ;
}
F_177 ( & V_20 -> V_360 ) ;
F_47 ( & V_20 -> V_32 ) ;
if ( V_549 ) {
V_20 -> V_193 = V_193 ;
F_36 ( V_27 ) ;
}
F_45 ( & V_20 -> V_32 ) ;
if ( V_548 && ( V_20 -> V_38 > V_42 ) ) {
if ( ! V_76 )
F_65 ( V_20 , V_76 , V_78 ) ;
}
F_262 ( V_27 ) ;
if ( V_69 )
F_319 ( V_69 , V_539 , V_472 -> V_114 ) ;
V_131:
return V_93 ;
}
static int F_330 ( struct V_526 * V_526 , struct V_249 * V_26 ,
struct V_534 * V_535 )
{
struct V_26 * V_27 = V_26 -> V_27 ;
struct V_19 * V_20 = F_37 ( V_27 ) ;
unsigned long V_559 , V_560 ;
struct V_63 * V_64 ;
unsigned long V_138 ;
int V_93 = - V_223 ;
int V_199 ;
if ( V_535 -> V_561 )
return - V_223 ;
F_169 ( & V_20 -> V_360 ) ;
V_560 = 0 ;
for ( V_64 = & V_20 -> V_79 ; V_64 <= & V_20 -> V_76 ; V_64 ++ ) {
if ( V_64 -> V_69 ) {
V_560 += V_64 -> V_557
* V_64 -> V_558
* V_140 ;
}
}
if ( V_560 == 0 )
goto V_131;
V_559 = V_535 -> V_562 - V_535 -> V_563 ;
if ( V_559 != V_560 )
goto V_131;
V_138 = V_535 -> V_563 ;
for ( V_64 = & V_20 -> V_79 ; V_64 <= & V_20 -> V_76 ; V_64 ++ ) {
if ( V_64 -> V_69 == NULL )
continue;
for ( V_199 = 0 ; V_199 < V_64 -> V_557 ; V_199 ++ ) {
struct V_347 * V_347 ;
void * V_564 = V_64 -> V_69 [ V_199 ] . V_70 ;
int V_565 ;
for ( V_565 = 0 ; V_565 < V_64 -> V_558 ; V_565 ++ ) {
V_347 = F_51 ( V_564 ) ;
V_93 = F_331 ( V_535 , V_138 , V_347 ) ;
if ( F_2 ( V_93 ) )
goto V_131;
V_138 += V_140 ;
V_564 += V_140 ;
}
}
}
F_119 ( & V_20 -> V_538 ) ;
V_535 -> V_566 = & V_567 ;
V_93 = 0 ;
V_131:
F_177 ( & V_20 -> V_360 ) ;
return V_93 ;
}
static void * F_332 ( struct V_568 * V_569 , T_11 * V_570 )
__acquires( T_12 )
{
struct V_209 * V_209 = F_333 ( V_569 ) ;
F_21 () ;
return F_334 ( & V_209 -> V_394 . V_421 , * V_570 ) ;
}
static void * F_335 ( struct V_568 * V_569 , void * V_571 , T_11 * V_570 )
{
struct V_209 * V_209 = F_333 ( V_569 ) ;
return F_336 ( V_571 , & V_209 -> V_394 . V_421 , V_570 ) ;
}
static void F_337 ( struct V_568 * V_569 , void * V_571 )
__releases( T_12 )
{
F_25 () ;
}
static int F_338 ( struct V_568 * V_569 , void * V_571 )
{
if ( V_571 == V_572 )
F_339 ( V_569 , L_10 ) ;
else {
struct V_26 * V_573 = F_340 ( V_571 ) ;
const struct V_19 * V_20 = F_37 ( V_573 ) ;
F_341 ( V_569 ,
L_11 ,
V_573 ,
F_90 ( & V_573 -> V_574 ) ,
V_573 -> V_296 ,
F_115 ( V_20 -> V_193 ) ,
V_20 -> V_95 ,
V_20 -> V_28 ,
F_90 ( & V_573 -> V_185 ) ,
F_342 ( F_343 ( V_569 ) , F_344 ( V_573 ) ) ,
F_345 ( V_573 ) ) ;
}
return 0 ;
}
static int F_346 ( struct V_575 * V_575 , struct V_526 * V_526 )
{
return F_347 ( V_575 , V_526 , & V_576 ,
sizeof( struct V_577 ) ) ;
}
static int T_13 F_348 ( struct V_209 * V_209 )
{
F_271 ( & V_209 -> V_394 . V_395 ) ;
F_349 ( & V_209 -> V_394 . V_421 ) ;
if ( ! F_350 ( L_12 , 0 , V_209 -> V_578 , & V_579 ) )
return - V_226 ;
return 0 ;
}
static void T_14 F_351 ( struct V_209 * V_209 )
{
F_352 ( L_12 , V_209 -> V_578 ) ;
}
static void T_15 F_353 ( void )
{
F_354 ( & V_580 ) ;
F_355 ( & V_581 ) ;
F_356 ( V_414 ) ;
F_357 ( & V_415 ) ;
}
static int T_16 F_358 ( void )
{
int V_582 = F_359 ( & V_415 , 0 ) ;
if ( V_582 != 0 )
goto V_131;
F_360 ( & V_583 ) ;
F_361 ( & V_581 ) ;
F_362 ( & V_580 ) ;
V_131:
return V_582 ;
}
