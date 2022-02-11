static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 () ;
V_4 = F_3 ( V_3 -> V_5 ) ;
if ( F_4 ( V_4 ) )
F_5 ( V_4 ) ;
F_6 () ;
return V_4 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
F_8 ( V_3 -> V_5 , V_4 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_10 ( V_3 -> V_5 , NULL ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_12 ( V_7 ) ;
if ( ! V_3 -> V_8 ) {
if ( V_3 -> V_9 )
F_13 ( V_7 , V_3 ) ;
else
F_14 ( & V_3 -> V_10 ) ;
F_15 ( V_7 ) ;
V_3 -> V_8 = 1 ;
}
}
static void F_16 ( struct V_6 * V_7 , bool V_11 )
{
struct V_2 * V_3 = F_12 ( V_7 ) ;
V_3 -> V_8 = 0 ;
if ( V_3 -> V_9 )
F_17 ( V_7 , V_3 ) ;
else
F_18 ( & V_3 -> V_10 ) ;
F_19 ( V_7 ) ;
if ( V_11 ) {
F_20 ( & V_3 -> V_12 ) ;
F_21 () ;
F_22 ( & V_3 -> V_12 ) ;
}
}
static void F_23 ( struct V_6 * V_7 , bool V_11 )
{
struct V_2 * V_3 = F_12 ( V_7 ) ;
if ( V_3 -> V_8 )
F_16 ( V_7 , V_11 ) ;
}
void F_24 ( struct V_2 * V_3 , void * V_13 , int V_14 )
{
union V_15 V_16 ;
V_16 . V_17 = V_13 ;
switch ( V_3 -> V_18 ) {
case V_19 :
V_16 . V_20 -> V_21 = V_14 ;
F_25 ( F_26 ( & V_16 . V_20 -> V_21 ) ) ;
break;
case V_22 :
V_16 . V_23 -> V_21 = V_14 ;
F_25 ( F_26 ( & V_16 . V_23 -> V_21 ) ) ;
break;
case V_24 :
default:
F_27 ( 1 , L_1 ) ;
F_28 () ;
}
F_29 () ;
}
static int F_30 ( struct V_2 * V_3 , void * V_13 )
{
union V_15 V_16 ;
F_31 () ;
V_16 . V_17 = V_13 ;
switch ( V_3 -> V_18 ) {
case V_19 :
F_25 ( F_26 ( & V_16 . V_20 -> V_21 ) ) ;
return V_16 . V_20 -> V_21 ;
case V_22 :
F_25 ( F_26 ( & V_16 . V_23 -> V_21 ) ) ;
return V_16 . V_23 -> V_21 ;
case V_24 :
default:
F_27 ( 1 , L_1 ) ;
F_28 () ;
return 0 ;
}
}
static T_1 F_32 ( struct V_25 * V_26 , struct V_27 * V_28 ,
unsigned int V_29 )
{
struct V_30 * V_31 = F_33 ( V_26 ) ;
if ( V_31 ) {
if ( ( V_29 & V_32 ) &&
F_34 ( V_31 -> V_33 , V_28 ) )
return V_34 ;
if ( ( V_29 & V_35 ) &&
F_34 ( V_31 -> V_36 , V_28 ) )
return V_37 ;
}
if ( F_34 ( V_26 -> V_38 , V_28 ) )
return V_39 ;
return 0 ;
}
static T_1 F_35 ( struct V_2 * V_3 , void * V_13 ,
struct V_25 * V_26 )
{
union V_15 V_16 ;
struct V_27 V_28 ;
T_1 V_40 ;
if ( ! ( V_40 = F_32 ( V_26 , & V_28 , V_3 -> V_41 ) ) )
return 0 ;
V_16 . V_17 = V_13 ;
switch ( V_3 -> V_18 ) {
case V_19 :
V_16 . V_20 -> V_42 = V_28 . V_43 ;
V_16 . V_20 -> V_44 = V_28 . V_45 / V_46 ;
break;
case V_22 :
V_16 . V_23 -> V_42 = V_28 . V_43 ;
V_16 . V_23 -> V_47 = V_28 . V_45 ;
break;
case V_24 :
default:
F_27 ( 1 , L_1 ) ;
F_28 () ;
}
F_25 ( F_26 ( & V_16 . V_20 -> V_42 ) ) ;
F_29 () ;
return V_40 ;
}
static void * F_36 ( struct V_2 * V_3 ,
struct V_48 * V_49 ,
unsigned int V_50 ,
int V_14 )
{
unsigned int V_51 , V_52 ;
union V_15 V_16 ;
V_51 = V_50 / V_49 -> V_53 ;
V_52 = V_50 % V_49 -> V_53 ;
V_16 . V_17 = V_49 -> V_54 [ V_51 ] . V_55 +
( V_52 * V_49 -> V_56 ) ;
if ( V_14 != F_30 ( V_3 , V_16 . V_17 ) )
return NULL ;
return V_16 . V_17 ;
}
static void * F_37 ( struct V_2 * V_3 ,
struct V_48 * V_49 ,
int V_14 )
{
return F_36 ( V_3 , V_49 , V_49 -> V_57 , V_14 ) ;
}
static void F_38 ( struct V_58 * V_59 )
{
F_39 ( & V_59 -> V_60 ) ;
}
static void F_40 ( struct V_2 * V_3 ,
int V_61 ,
struct V_62 * V_63 )
{
struct V_58 * V_59 ;
V_59 = V_61 ? & V_3 -> V_61 . V_64 : & V_3 -> V_65 . V_64 ;
F_41 ( & V_63 -> V_66 ) ;
V_59 -> V_67 = 1 ;
F_42 ( & V_63 -> V_66 ) ;
F_38 ( V_59 ) ;
}
static void F_43 ( struct V_2 * V_3 ,
struct V_58 * V_59 ,
void (* F_44) ( unsigned long ) )
{
F_45 ( & V_59 -> V_60 ) ;
V_59 -> V_60 . V_68 = ( long ) V_3 ;
V_59 -> V_60 . V_69 = F_44 ;
V_59 -> V_60 . V_70 = V_71 ;
}
static void F_46 ( struct V_2 * V_3 , int V_61 )
{
struct V_58 * V_59 ;
if ( V_61 )
F_28 () ;
V_59 = V_61 ? & V_3 -> V_61 . V_64 : & V_3 -> V_65 . V_64 ;
F_43 ( V_3 , V_59 , V_72 ) ;
}
static int F_47 ( struct V_2 * V_3 ,
int V_73 )
{
struct V_1 * V_4 ;
unsigned int V_74 = 0 , V_75 = 0 , div = 0 , V_76 = 0 ;
struct V_77 V_78 ;
int V_79 ;
T_2 V_80 ;
F_48 () ;
V_4 = F_49 ( F_50 ( & V_3 -> V_7 ) , V_3 -> V_81 ) ;
if ( F_51 ( ! V_4 ) ) {
F_52 () ;
return V_82 ;
}
V_79 = F_53 ( V_4 , & V_78 ) ;
V_80 = F_54 ( & V_78 ) ;
F_52 () ;
if ( ! V_79 ) {
if ( V_80 < V_83 || V_80 == V_84 ) {
return V_82 ;
} else {
V_75 = 1 ;
div = V_80 / 1000 ;
}
}
V_74 = ( V_73 * 8 ) / ( 1024 * 1024 ) ;
if ( div )
V_74 /= div ;
V_76 = V_74 * V_75 ;
if ( div )
return V_76 + 1 ;
return V_76 ;
}
static void F_55 ( struct V_58 * V_85 ,
union V_86 * V_87 )
{
V_85 -> V_88 = V_87 -> V_89 . V_90 ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_48 * V_49 ,
struct V_91 * V_54 ,
union V_86 * V_87 , int V_61 )
{
struct V_58 * V_85 = & V_49 -> V_64 ;
struct V_92 * V_93 ;
memset ( V_85 , 0x0 , sizeof( * V_85 ) ) ;
V_85 -> V_94 = 1 ;
V_85 -> V_95 = V_54 ;
V_93 = (struct V_92 * ) V_54 [ 0 ] . V_55 ;
V_85 -> V_96 = V_54 [ 0 ] . V_55 ;
V_85 -> V_97 = V_87 -> V_89 . V_98 ;
V_85 -> V_99 = V_87 -> V_89 . V_100 ;
V_85 -> V_101 = V_3 -> V_102 ;
V_85 -> V_103 = V_3 -> V_18 ;
V_85 -> V_104 = 0 ;
V_3 -> V_105 . V_106 . V_107 = 0 ;
if ( V_87 -> V_89 . V_108 )
V_85 -> V_109 = V_87 -> V_89 . V_108 ;
else
V_85 -> V_109 = F_47 ( V_3 ,
V_87 -> V_89 . V_98 ) ;
V_85 -> V_110 = F_57 ( V_85 -> V_109 ) ;
V_85 -> V_111 = V_87 -> V_89 . V_112 ;
F_55 ( V_85 , V_87 ) ;
F_46 ( V_3 , V_61 ) ;
F_58 ( V_85 , V_93 ) ;
}
static void F_59 ( struct V_58 * V_59 )
{
F_60 ( & V_59 -> V_60 ,
V_71 + V_59 -> V_110 ) ;
V_59 -> V_104 = V_59 -> V_113 ;
}
static void V_72 ( unsigned long V_68 )
{
struct V_2 * V_3 = (struct V_2 * ) V_68 ;
struct V_58 * V_59 = & V_3 -> V_65 . V_64 ;
unsigned int V_114 ;
struct V_92 * V_93 ;
F_22 ( & V_3 -> V_7 . V_115 . V_66 ) ;
V_114 = F_61 ( V_59 ) ;
V_93 = F_62 ( V_59 ) ;
if ( F_51 ( V_59 -> V_67 ) )
goto V_116;
if ( F_63 ( V_93 ) ) {
while ( F_64 ( & V_59 -> V_117 ) ) {
F_65 () ;
}
}
if ( V_59 -> V_104 == V_59 -> V_113 ) {
if ( ! V_114 ) {
F_66 ( V_59 , V_3 , V_118 ) ;
if ( ! F_67 ( V_59 , V_3 ) )
goto V_119;
else
goto V_116;
} else {
if ( F_68 ( V_59 , V_93 ) ) {
goto V_119;
} else {
F_58 ( V_59 , V_93 ) ;
goto V_116;
}
}
}
V_119:
F_59 ( V_59 ) ;
V_116:
F_20 ( & V_3 -> V_7 . V_115 . V_66 ) ;
}
static void F_69 ( struct V_58 * V_120 ,
struct V_92 * V_121 , T_1 V_14 )
{
#if V_122 == 1
T_3 * V_123 , * V_124 ;
V_123 = ( T_3 * ) V_121 ;
V_123 += V_125 ;
V_124 = ( T_3 * ) F_70 ( ( unsigned long ) V_120 -> V_126 ) ;
for (; V_123 < V_124 ; V_123 += V_125 )
F_25 ( F_26 ( V_123 ) ) ;
F_29 () ;
#endif
F_71 ( V_121 ) = V_14 ;
#if V_122 == 1
V_123 = ( T_3 * ) V_121 ;
F_25 ( F_26 ( V_123 ) ) ;
F_29 () ;
#endif
}
static void F_72 ( struct V_58 * V_120 ,
struct V_92 * V_121 ,
struct V_2 * V_3 , unsigned int V_127 )
{
T_1 V_14 = V_128 | V_127 ;
struct V_129 * V_130 ;
struct V_131 * V_20 = & V_121 -> V_132 . V_133 ;
if ( V_3 -> V_105 . V_106 . V_134 )
V_14 |= V_135 ;
V_130 = (struct V_129 * ) V_120 -> V_136 ;
V_130 -> V_137 = 0 ;
if ( F_63 ( V_121 ) ) {
V_20 -> V_138 . V_139 = V_130 -> V_42 ;
V_20 -> V_138 . V_140 = V_130 -> V_47 ;
} else {
struct V_27 V_28 ;
F_73 ( & V_28 ) ;
V_20 -> V_138 . V_139 = V_28 . V_43 ;
V_20 -> V_138 . V_140 = V_28 . V_45 ;
}
F_29 () ;
F_69 ( V_120 , V_121 , V_14 ) ;
V_120 -> V_113 = F_74 ( V_120 ) ;
}
static void F_75 ( struct V_58 * V_59 )
{
V_59 -> V_141 = 0 ;
}
static void F_58 ( struct V_58 * V_120 ,
struct V_92 * V_121 )
{
struct V_27 V_28 ;
struct V_131 * V_20 = & V_121 -> V_132 . V_133 ;
F_31 () ;
F_76 ( V_121 ) = V_120 -> V_94 ++ ;
F_63 ( V_121 ) = 0 ;
F_77 ( V_121 ) = F_78 ( V_120 -> V_111 ) ;
F_73 ( & V_28 ) ;
V_20 -> V_142 . V_139 = V_28 . V_43 ;
V_20 -> V_142 . V_140 = V_28 . V_45 ;
V_120 -> V_96 = ( char * ) V_121 ;
V_120 -> V_143 = V_120 -> V_96 + F_78 ( V_120 -> V_111 ) ;
F_79 ( V_121 ) = ( T_1 ) F_78 ( V_120 -> V_111 ) ;
F_80 ( V_121 ) = V_144 ;
V_121 -> V_103 = V_120 -> V_103 ;
V_120 -> V_136 = V_120 -> V_143 ;
V_120 -> V_126 = V_120 -> V_96 + V_120 -> V_97 ;
F_75 ( V_120 ) ;
F_59 ( V_120 ) ;
F_29 () ;
}
static void F_81 ( struct V_58 * V_59 ,
struct V_2 * V_3 )
{
V_59 -> V_141 = 1 ;
V_3 -> V_105 . V_106 . V_107 ++ ;
}
static void * F_67 ( struct V_58 * V_59 ,
struct V_2 * V_3 )
{
struct V_92 * V_93 ;
F_31 () ;
V_93 = F_62 ( V_59 ) ;
if ( V_128 & F_71 ( V_93 ) ) {
F_81 ( V_59 , V_3 ) ;
return NULL ;
}
F_58 ( V_59 , V_93 ) ;
return ( void * ) V_59 -> V_143 ;
}
static void F_66 ( struct V_58 * V_59 ,
struct V_2 * V_3 , unsigned int V_14 )
{
struct V_92 * V_93 = F_62 ( V_59 ) ;
if ( F_4 ( V_145 == F_71 ( V_93 ) ) ) {
if ( ! ( V_14 & V_118 ) ) {
while ( F_64 ( & V_59 -> V_117 ) ) {
F_65 () ;
}
}
F_72 ( V_59 , V_93 , V_3 , V_14 ) ;
return;
}
}
static int F_68 ( struct V_58 * V_59 ,
struct V_92 * V_93 )
{
return V_128 & F_71 ( V_93 ) ;
}
static int F_61 ( struct V_58 * V_59 )
{
return V_59 -> V_141 ;
}
static void F_82 ( struct V_48 * V_49 )
{
struct V_58 * V_59 = F_83 ( V_49 ) ;
F_84 ( & V_59 -> V_117 ) ;
}
static void F_85 ( struct V_58 * V_59 ,
struct V_129 * V_146 )
{
V_146 -> V_147 . V_148 = F_86 ( V_59 -> V_26 ) ;
}
static void F_87 ( struct V_58 * V_59 ,
struct V_129 * V_146 )
{
V_146 -> V_147 . V_148 = 0 ;
}
static void F_88 ( struct V_58 * V_59 ,
struct V_129 * V_146 )
{
if ( F_89 ( V_59 -> V_26 ) ) {
V_146 -> V_147 . V_149 = F_90 ( V_59 -> V_26 ) ;
V_146 -> V_21 = V_150 ;
} else {
V_146 -> V_147 . V_149 = 0 ;
V_146 -> V_21 = V_151 ;
}
}
static void F_91 ( struct V_58 * V_59 ,
struct V_129 * V_146 )
{
F_88 ( V_59 , V_146 ) ;
if ( V_59 -> V_88 & V_152 )
F_85 ( V_59 , V_146 ) ;
else
F_87 ( V_59 , V_146 ) ;
}
static void F_92 ( char * V_153 ,
struct V_58 * V_59 ,
struct V_92 * V_93 ,
unsigned int V_154 )
{
struct V_129 * V_146 ;
V_146 = (struct V_129 * ) V_153 ;
V_146 -> V_137 = F_93 ( V_154 ) ;
V_59 -> V_136 = V_153 ;
V_59 -> V_143 += F_93 ( V_154 ) ;
F_77 ( V_93 ) += F_93 ( V_154 ) ;
F_63 ( V_93 ) += 1 ;
F_94 ( & V_59 -> V_117 ) ;
F_91 ( V_59 , V_146 ) ;
}
static void * F_95 ( struct V_2 * V_3 ,
struct V_25 * V_26 ,
int V_14 ,
unsigned int V_154
)
{
struct V_58 * V_59 ;
struct V_92 * V_93 ;
char * V_153 , * V_124 ;
V_59 = F_83 ( & V_3 -> V_65 ) ;
V_93 = F_62 ( V_59 ) ;
if ( F_61 ( V_59 ) ) {
if ( F_68 ( V_59 , V_93 ) ) {
return NULL ;
} else {
F_58 ( V_59 , V_93 ) ;
}
}
F_96 () ;
V_153 = V_59 -> V_143 ;
V_59 -> V_26 = V_26 ;
V_124 = ( char * ) V_93 + V_59 -> V_97 ;
if ( V_153 + F_93 ( V_154 ) < V_124 ) {
F_92 ( V_153 , V_59 , V_93 , V_154 ) ;
return ( void * ) V_153 ;
}
F_66 ( V_59 , V_3 , 0 ) ;
V_153 = ( char * ) F_67 ( V_59 , V_3 ) ;
if ( V_153 ) {
V_93 = F_62 ( V_59 ) ;
F_92 ( V_153 , V_59 , V_93 , V_154 ) ;
return ( void * ) V_153 ;
}
return NULL ;
}
static void * F_97 ( struct V_2 * V_3 ,
struct V_25 * V_26 ,
int V_14 , unsigned int V_154 )
{
char * V_153 = NULL ;
switch ( V_3 -> V_18 ) {
case V_19 :
case V_22 :
V_153 = F_36 ( V_3 , & V_3 -> V_65 ,
V_3 -> V_65 . V_57 , V_14 ) ;
return V_153 ;
case V_24 :
return F_95 ( V_3 , V_26 , V_14 , V_154 ) ;
default:
F_27 ( 1 , L_2 ) ;
F_28 () ;
return NULL ;
}
}
static void * F_98 ( struct V_2 * V_3 ,
struct V_48 * V_49 ,
unsigned int V_155 ,
int V_14 )
{
struct V_58 * V_59 = F_83 ( V_49 ) ;
struct V_92 * V_93 = F_99 ( V_59 , V_155 ) ;
if ( V_14 != F_71 ( V_93 ) )
return NULL ;
return V_93 ;
}
static int F_100 ( struct V_48 * V_49 )
{
unsigned int V_136 ;
if ( V_49 -> V_64 . V_113 )
V_136 = V_49 -> V_64 . V_113 - 1 ;
else
V_136 = V_49 -> V_64 . V_99 - 1 ;
return V_136 ;
}
static void * F_101 ( struct V_2 * V_3 ,
struct V_48 * V_49 ,
int V_14 )
{
unsigned int V_156 = F_100 ( V_49 ) ;
return F_98 ( V_3 , V_49 , V_156 , V_14 ) ;
}
static void * F_102 ( struct V_2 * V_3 ,
struct V_48 * V_49 ,
int V_14 )
{
if ( V_3 -> V_18 <= V_22 )
return F_103 ( V_3 , V_49 , V_14 ) ;
return F_101 ( V_3 , V_49 , V_14 ) ;
}
static void F_104 ( struct V_2 * V_3 ,
struct V_48 * V_49 )
{
switch ( V_3 -> V_18 ) {
case V_19 :
case V_22 :
return F_105 ( V_49 ) ;
case V_24 :
default:
F_27 ( 1 , L_1 ) ;
F_28 () ;
return;
}
}
static void * F_103 ( struct V_2 * V_3 ,
struct V_48 * V_49 ,
int V_14 )
{
unsigned int V_156 = V_49 -> V_57 ? V_49 -> V_57 - 1 : V_49 -> V_157 ;
return F_36 ( V_3 , V_49 , V_156 , V_14 ) ;
}
static void F_105 ( struct V_48 * V_158 )
{
V_158 -> V_57 = V_158 -> V_57 != V_158 -> V_157 ? V_158 -> V_57 + 1 : 0 ;
}
static bool F_106 ( struct V_2 * V_3 , struct V_25 * V_26 )
{
struct V_6 * V_7 = & V_3 -> V_7 ;
bool V_159 ;
if ( V_3 -> V_10 . F_44 != V_160 )
return ( F_64 ( & V_7 -> V_161 ) + V_26 -> V_162 )
<= V_7 -> V_163 ;
F_22 ( & V_7 -> V_115 . V_66 ) ;
if ( V_3 -> V_18 == V_24 )
V_159 = F_98 ( V_3 , & V_3 -> V_65 ,
V_3 -> V_65 . V_64 . V_113 ,
V_145 ) ;
else
V_159 = F_36 ( V_3 , & V_3 -> V_65 ,
V_3 -> V_65 . V_57 ,
V_145 ) ;
F_20 ( & V_7 -> V_115 . V_66 ) ;
return V_159 ;
}
static void F_107 ( struct V_6 * V_7 )
{
F_108 ( & V_7 -> V_164 ) ;
F_109 ( F_64 ( & V_7 -> V_161 ) ) ;
F_109 ( F_64 ( & V_7 -> V_165 ) ) ;
if ( ! F_110 ( V_7 , V_166 ) ) {
F_111 ( L_3 , V_7 ) ;
return;
}
F_112 ( V_7 ) ;
}
static int F_113 ( struct V_167 * V_168 , unsigned int V_169 )
{
int V_170 = F_64 ( & V_168 -> V_171 ) + 1 ;
if ( V_170 >= V_169 )
V_170 = 0 ;
return V_170 ;
}
static unsigned int F_114 ( struct V_167 * V_168 ,
struct V_25 * V_26 ,
unsigned int V_169 )
{
return F_115 ( V_26 -> V_172 , V_169 ) ;
}
static unsigned int F_116 ( struct V_167 * V_168 ,
struct V_25 * V_26 ,
unsigned int V_169 )
{
int V_173 , V_174 ;
V_173 = F_64 ( & V_168 -> V_171 ) ;
while ( ( V_174 = F_117 ( & V_168 -> V_171 , V_173 ,
F_113 ( V_168 , V_169 ) ) ) != V_173 )
V_173 = V_174 ;
return V_173 ;
}
static unsigned int F_118 ( struct V_167 * V_168 ,
struct V_25 * V_26 ,
unsigned int V_169 )
{
return F_119 () % V_169 ;
}
static unsigned int F_120 ( struct V_167 * V_168 ,
struct V_25 * V_26 ,
unsigned int V_169 )
{
return F_115 ( F_121 () , V_169 ) ;
}
static unsigned int F_122 ( struct V_167 * V_168 ,
struct V_25 * V_26 ,
unsigned int V_155 , unsigned int V_175 ,
unsigned int V_169 )
{
unsigned int V_176 , V_177 ;
V_176 = V_177 = F_123 ( int , V_168 -> V_178 [ V_155 ] , V_169 - 1 ) ;
do {
if ( V_176 != V_175 && F_106 ( F_12 ( V_168 -> V_179 [ V_176 ] ) , V_26 ) ) {
if ( V_176 != V_177 )
V_168 -> V_178 [ V_155 ] = V_176 ;
return V_176 ;
}
if ( ++ V_176 == V_169 )
V_176 = 0 ;
} while ( V_176 != V_177 );
return V_155 ;
}
static bool F_124 ( struct V_167 * V_168 , T_4 V_180 )
{
return V_168 -> V_29 & ( V_180 >> 8 ) ;
}
static int F_125 ( struct V_25 * V_26 , struct V_1 * V_4 ,
struct V_181 * V_182 , struct V_1 * V_183 )
{
struct V_167 * V_168 = V_182 -> V_184 ;
unsigned int V_169 = V_168 -> V_185 ;
struct V_2 * V_3 ;
unsigned int V_155 ;
if ( ! F_126 ( F_127 ( V_4 ) , F_128 ( & V_168 -> V_186 ) ) ||
! V_169 ) {
F_129 ( V_26 ) ;
return 0 ;
}
switch ( V_168 -> type ) {
case V_187 :
default:
if ( F_124 ( V_168 , V_188 ) ) {
V_26 = F_130 ( V_26 , V_189 ) ;
if ( ! V_26 )
return 0 ;
}
F_86 ( V_26 ) ;
V_155 = F_114 ( V_168 , V_26 , V_169 ) ;
break;
case V_190 :
V_155 = F_116 ( V_168 , V_26 , V_169 ) ;
break;
case V_191 :
V_155 = F_118 ( V_168 , V_26 , V_169 ) ;
break;
case V_192 :
V_155 = F_120 ( V_168 , V_26 , V_169 ) ;
break;
case V_193 :
V_155 = F_122 ( V_168 , V_26 , 0 , ( unsigned int ) - 1 , V_169 ) ;
break;
}
V_3 = F_12 ( V_168 -> V_179 [ V_155 ] ) ;
if ( F_124 ( V_168 , V_194 ) &&
F_51 ( ! F_106 ( V_3 , V_26 ) ) ) {
V_155 = F_122 ( V_168 , V_26 , V_155 , V_155 , V_169 ) ;
V_3 = F_12 ( V_168 -> V_179 [ V_155 ] ) ;
}
return V_3 -> V_10 . F_44 ( V_26 , V_4 , & V_3 -> V_10 , V_183 ) ;
}
static void F_13 ( struct V_6 * V_7 , struct V_2 * V_3 )
{
struct V_167 * V_168 = V_3 -> V_9 ;
F_22 ( & V_168 -> V_66 ) ;
V_168 -> V_179 [ V_168 -> V_185 ] = V_7 ;
F_29 () ;
V_168 -> V_185 ++ ;
F_20 ( & V_168 -> V_66 ) ;
}
static void F_17 ( struct V_6 * V_7 , struct V_2 * V_3 )
{
struct V_167 * V_168 = V_3 -> V_9 ;
int V_176 ;
F_22 ( & V_168 -> V_66 ) ;
for ( V_176 = 0 ; V_176 < V_168 -> V_185 ; V_176 ++ ) {
if ( V_168 -> V_179 [ V_176 ] == V_7 )
break;
}
F_131 ( V_176 >= V_168 -> V_185 ) ;
V_168 -> V_179 [ V_176 ] = V_168 -> V_179 [ V_168 -> V_185 - 1 ] ;
V_168 -> V_185 -- ;
F_20 ( & V_168 -> V_66 ) ;
}
static bool F_132 ( struct V_181 * V_195 , struct V_6 * V_7 )
{
if ( V_195 -> V_184 == ( void * ) ( (struct V_2 * ) V_7 ) -> V_9 )
return true ;
return false ;
}
static int F_133 ( struct V_6 * V_7 , T_4 V_196 , T_4 V_197 )
{
struct V_2 * V_3 = F_12 ( V_7 ) ;
struct V_167 * V_168 , * V_198 ;
T_3 type = V_197 & 0xff ;
T_3 V_29 = V_197 >> 8 ;
int V_79 ;
switch ( type ) {
case V_193 :
if ( V_197 & V_194 )
return - V_199 ;
case V_187 :
case V_190 :
case V_191 :
case V_192 :
break;
default:
return - V_199 ;
}
if ( ! V_3 -> V_8 )
return - V_199 ;
if ( V_3 -> V_9 )
return - V_200 ;
F_134 ( & V_201 ) ;
V_198 = NULL ;
F_135 (f, &fanout_list, list) {
if ( V_168 -> V_196 == V_196 &&
F_128 ( & V_168 -> V_186 ) == F_50 ( V_7 ) ) {
V_198 = V_168 ;
break;
}
}
V_79 = - V_199 ;
if ( V_198 && V_198 -> V_29 != V_29 )
goto V_116;
if ( ! V_198 ) {
V_79 = - V_202 ;
V_198 = F_136 ( sizeof( * V_198 ) , V_203 ) ;
if ( ! V_198 )
goto V_116;
F_137 ( & V_198 -> V_186 , F_50 ( V_7 ) ) ;
V_198 -> V_196 = V_196 ;
V_198 -> type = type ;
V_198 -> V_29 = V_29 ;
F_138 ( & V_198 -> V_171 , 0 ) ;
F_139 ( & V_198 -> V_204 ) ;
F_140 ( & V_198 -> V_66 ) ;
F_138 ( & V_198 -> V_205 , 0 ) ;
V_198 -> V_10 . type = V_3 -> V_10 . type ;
V_198 -> V_10 . V_4 = V_3 -> V_10 . V_4 ;
V_198 -> V_10 . F_44 = F_125 ;
V_198 -> V_10 . V_184 = V_198 ;
V_198 -> V_10 . V_206 = F_132 ;
F_14 ( & V_198 -> V_10 ) ;
F_141 ( & V_198 -> V_204 , & V_207 ) ;
}
V_79 = - V_199 ;
if ( V_198 -> type == type &&
V_198 -> V_10 . type == V_3 -> V_10 . type &&
V_198 -> V_10 . V_4 == V_3 -> V_10 . V_4 ) {
V_79 = - V_208 ;
if ( F_64 ( & V_198 -> V_205 ) < V_209 ) {
F_18 ( & V_3 -> V_10 ) ;
V_3 -> V_9 = V_198 ;
F_94 ( & V_198 -> V_205 ) ;
F_13 ( V_7 , V_3 ) ;
V_79 = 0 ;
}
}
V_116:
F_142 ( & V_201 ) ;
return V_79 ;
}
static void F_143 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_12 ( V_7 ) ;
struct V_167 * V_168 ;
V_168 = V_3 -> V_9 ;
if ( ! V_168 )
return;
F_134 ( & V_201 ) ;
V_3 -> V_9 = NULL ;
if ( F_144 ( & V_168 -> V_205 ) ) {
F_145 ( & V_168 -> V_204 ) ;
F_146 ( & V_168 -> V_10 ) ;
F_147 ( V_168 ) ;
}
F_142 ( & V_201 ) ;
}
static int F_148 ( struct V_25 * V_26 , struct V_1 * V_4 ,
struct V_181 * V_182 , struct V_1 * V_183 )
{
struct V_6 * V_7 ;
struct V_210 * V_211 ;
V_7 = V_182 -> V_184 ;
if ( V_26 -> V_212 == V_213 )
goto V_116;
if ( ! F_126 ( F_127 ( V_4 ) , F_50 ( V_7 ) ) )
goto V_116;
V_26 = F_149 ( V_26 , V_214 ) ;
if ( V_26 == NULL )
goto V_215;
F_150 ( V_26 ) ;
F_151 ( V_26 ) ;
V_211 = & F_152 ( V_26 ) -> V_216 . V_217 ;
F_153 ( V_26 , V_26 -> V_68 - F_154 ( V_26 ) ) ;
V_211 -> V_218 = V_4 -> type ;
F_155 ( V_211 -> V_219 , V_4 -> V_220 , sizeof( V_211 -> V_219 ) ) ;
V_211 -> V_221 = V_26 -> V_222 ;
if ( F_156 ( V_7 , V_26 ) == 0 )
return 0 ;
V_116:
F_129 ( V_26 ) ;
V_215:
return 0 ;
}
static int F_157 ( struct V_223 * V_224 , struct V_225 * V_6 ,
struct V_226 * V_227 , T_5 V_154 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_210 * V_228 = (struct V_210 * ) V_227 -> V_229 ;
struct V_25 * V_26 = NULL ;
struct V_1 * V_4 ;
T_6 V_230 = 0 ;
int V_79 ;
int V_231 = 0 ;
if ( V_228 ) {
if ( V_227 -> V_232 < sizeof( struct V_233 ) )
return - V_199 ;
if ( V_227 -> V_232 == sizeof( struct V_210 ) )
V_230 = V_228 -> V_221 ;
} else
return - V_234 ;
V_228 -> V_219 [ sizeof( V_228 -> V_219 ) - 1 ] = 0 ;
V_235:
F_2 () ;
V_4 = F_158 ( F_50 ( V_7 ) , V_228 -> V_219 ) ;
V_79 = - V_236 ;
if ( V_4 == NULL )
goto V_237;
V_79 = - V_238 ;
if ( ! ( V_4 -> V_29 & V_239 ) )
goto V_237;
if ( F_51 ( F_110 ( V_7 , V_240 ) ) ) {
if ( ! F_159 ( V_4 ) ) {
V_79 = - V_241 ;
goto V_237;
}
V_231 = 4 ;
}
V_79 = - V_242 ;
if ( V_154 > V_4 -> V_243 + V_4 -> V_244 + V_245 + V_231 )
goto V_237;
if ( ! V_26 ) {
T_5 V_246 = F_160 ( V_4 ) ;
int V_247 = V_4 -> V_248 ;
unsigned int V_249 = V_4 -> V_250 ? V_4 -> V_244 : 0 ;
F_6 () ;
V_26 = F_161 ( V_7 , V_154 + V_246 + V_247 , 0 , V_203 ) ;
if ( V_26 == NULL )
return - V_251 ;
F_162 ( V_26 , V_246 ) ;
F_163 ( V_26 ) ;
if ( V_249 ) {
V_26 -> V_68 -= V_249 ;
V_26 -> V_252 -= V_249 ;
if ( V_154 < V_249 )
F_163 ( V_26 ) ;
}
V_79 = F_164 ( F_165 ( V_26 , V_154 ) , V_227 -> V_253 , V_154 ) ;
if ( V_79 )
goto V_254;
goto V_235;
}
if ( V_154 > ( V_4 -> V_243 + V_4 -> V_244 + V_231 ) ) {
struct V_255 * V_256 ;
F_166 ( V_26 ) ;
V_256 = F_167 ( V_26 ) ;
if ( V_256 -> V_257 != F_168 ( V_258 ) ) {
V_79 = - V_242 ;
goto V_237;
}
}
V_26 -> V_222 = V_230 ;
V_26 -> V_4 = V_4 ;
V_26 -> V_259 = V_7 -> V_260 ;
V_26 -> V_261 = V_7 -> V_262 ;
F_169 ( V_7 , & F_170 ( V_26 ) -> V_263 ) ;
if ( F_51 ( V_231 == 4 ) )
V_26 -> V_264 = 1 ;
F_171 ( V_26 , 0 ) ;
F_172 ( V_26 ) ;
F_6 () ;
return V_154 ;
V_237:
F_6 () ;
V_254:
F_129 ( V_26 ) ;
return V_79 ;
}
static unsigned int F_173 ( const struct V_25 * V_26 ,
const struct V_6 * V_7 ,
unsigned int V_265 )
{
struct V_266 * V_267 ;
F_2 () ;
V_267 = F_3 ( V_7 -> V_266 ) ;
if ( V_267 != NULL )
V_265 = F_174 ( V_267 , V_26 ) ;
F_6 () ;
return V_265 ;
}
static int F_175 ( struct V_25 * V_26 , struct V_1 * V_4 ,
struct V_181 * V_182 , struct V_1 * V_183 )
{
struct V_6 * V_7 ;
struct V_268 * V_269 ;
struct V_2 * V_3 ;
T_3 * V_270 = V_26 -> V_68 ;
int V_271 = V_26 -> V_154 ;
unsigned int V_272 , V_265 ;
if ( V_26 -> V_212 == V_213 )
goto V_273;
V_7 = V_182 -> V_184 ;
V_3 = F_12 ( V_7 ) ;
if ( ! F_126 ( F_127 ( V_4 ) , F_50 ( V_7 ) ) )
goto V_273;
V_26 -> V_4 = V_4 ;
if ( V_4 -> V_250 ) {
if ( V_7 -> V_274 != V_275 )
F_153 ( V_26 , V_26 -> V_68 - F_154 ( V_26 ) ) ;
else if ( V_26 -> V_212 == V_276 ) {
F_176 ( V_26 , F_177 ( V_26 ) ) ;
}
}
V_272 = V_26 -> V_154 ;
V_265 = F_173 ( V_26 , V_7 , V_272 ) ;
if ( ! V_265 )
goto V_277;
if ( V_272 > V_265 )
V_272 = V_265 ;
if ( F_64 ( & V_7 -> V_161 ) >= V_7 -> V_163 )
goto V_278;
if ( F_178 ( V_26 ) ) {
struct V_25 * V_279 = F_179 ( V_26 , V_214 ) ;
if ( V_279 == NULL )
goto V_278;
if ( V_270 != V_26 -> V_68 ) {
V_26 -> V_68 = V_270 ;
V_26 -> V_154 = V_271 ;
}
F_180 ( V_26 ) ;
V_26 = V_279 ;
}
F_181 ( sizeof( * F_152 ( V_26 ) ) + V_280 - 8 >
sizeof( V_26 -> V_281 ) ) ;
V_269 = & F_152 ( V_26 ) -> V_216 . V_282 ;
V_269 -> V_283 = V_284 ;
V_269 -> V_285 = V_4 -> type ;
V_269 -> V_286 = V_26 -> V_222 ;
V_269 -> V_287 = V_26 -> V_212 ;
if ( F_51 ( V_3 -> V_288 ) )
V_269 -> V_289 = V_183 -> V_81 ;
else
V_269 -> V_289 = V_4 -> V_81 ;
V_269 -> V_290 = F_182 ( V_26 , V_269 -> V_291 ) ;
F_152 ( V_26 ) -> V_292 = V_26 -> V_154 ;
if ( F_183 ( V_26 , V_272 ) )
goto V_278;
F_184 ( V_26 , V_7 ) ;
V_26 -> V_4 = NULL ;
F_150 ( V_26 ) ;
F_151 ( V_26 ) ;
F_22 ( & V_7 -> V_115 . V_66 ) ;
V_3 -> V_105 . V_293 . V_294 ++ ;
V_26 -> V_295 = F_64 ( & V_7 -> V_296 ) ;
F_185 ( & V_7 -> V_115 , V_26 ) ;
F_20 ( & V_7 -> V_115 . V_66 ) ;
V_7 -> V_297 ( V_7 , V_26 -> V_154 ) ;
return 0 ;
V_278:
F_22 ( & V_7 -> V_115 . V_66 ) ;
V_3 -> V_105 . V_293 . V_134 ++ ;
F_94 ( & V_7 -> V_296 ) ;
F_20 ( & V_7 -> V_115 . V_66 ) ;
V_277:
if ( V_270 != V_26 -> V_68 && F_178 ( V_26 ) ) {
V_26 -> V_68 = V_270 ;
V_26 -> V_154 = V_271 ;
}
V_273:
F_180 ( V_26 ) ;
return 0 ;
}
static int V_160 ( struct V_25 * V_26 , struct V_1 * V_4 ,
struct V_181 * V_182 , struct V_1 * V_183 )
{
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_268 * V_269 ;
union V_15 V_16 ;
T_3 * V_270 = V_26 -> V_68 ;
int V_271 = V_26 -> V_154 ;
unsigned int V_272 , V_265 ;
unsigned long V_14 = V_128 ;
unsigned short V_298 , V_299 , V_101 ;
struct V_25 * V_300 = NULL ;
struct V_27 V_28 ;
T_1 V_40 ;
if ( V_26 -> V_212 == V_213 )
goto V_273;
V_7 = V_182 -> V_184 ;
V_3 = F_12 ( V_7 ) ;
if ( ! F_126 ( F_127 ( V_4 ) , F_50 ( V_7 ) ) )
goto V_273;
if ( V_4 -> V_250 ) {
if ( V_7 -> V_274 != V_275 )
F_153 ( V_26 , V_26 -> V_68 - F_154 ( V_26 ) ) ;
else if ( V_26 -> V_212 == V_276 ) {
F_176 ( V_26 , F_177 ( V_26 ) ) ;
}
}
if ( V_26 -> V_301 == V_302 )
V_14 |= V_303 ;
V_272 = V_26 -> V_154 ;
V_265 = F_173 ( V_26 , V_7 , V_272 ) ;
if ( ! V_265 )
goto V_277;
if ( V_272 > V_265 )
V_272 = V_265 ;
if ( V_7 -> V_274 == V_275 ) {
V_298 = V_299 = F_186 ( V_3 -> V_102 ) + 16 +
V_3 -> V_304 ;
} else {
unsigned int V_305 = F_177 ( V_26 ) ;
V_299 = F_186 ( V_3 -> V_102 +
( V_305 < 16 ? 16 : V_305 ) ) +
V_3 -> V_304 ;
V_298 = V_299 - V_305 ;
}
if ( V_3 -> V_18 <= V_22 ) {
if ( V_298 + V_272 > V_3 -> V_65 . V_56 ) {
if ( V_3 -> V_306 &&
F_64 ( & V_7 -> V_161 ) < V_7 -> V_163 ) {
if ( F_178 ( V_26 ) ) {
V_300 = F_179 ( V_26 , V_214 ) ;
} else {
V_300 = F_187 ( V_26 ) ;
V_270 = V_26 -> V_68 ;
}
if ( V_300 )
F_184 ( V_300 , V_7 ) ;
}
V_272 = V_3 -> V_65 . V_56 - V_298 ;
if ( ( int ) V_272 < 0 )
V_272 = 0 ;
}
}
F_22 ( & V_7 -> V_115 . V_66 ) ;
V_16 . V_17 = F_97 ( V_3 , V_26 ,
V_145 , ( V_298 + V_272 ) ) ;
if ( ! V_16 . V_17 )
goto V_307;
if ( V_3 -> V_18 <= V_22 ) {
F_104 ( V_3 , & V_3 -> V_65 ) ;
if ( V_3 -> V_105 . V_293 . V_134 )
V_14 |= V_135 ;
}
V_3 -> V_105 . V_293 . V_294 ++ ;
if ( V_300 ) {
V_14 |= V_308 ;
F_185 ( & V_7 -> V_115 , V_300 ) ;
}
F_20 ( & V_7 -> V_115 . V_66 ) ;
F_188 ( V_26 , 0 , V_16 . V_17 + V_298 , V_272 ) ;
if ( ! ( V_40 = F_32 ( V_26 , & V_28 , V_3 -> V_41 ) ) )
F_73 ( & V_28 ) ;
V_14 |= V_40 ;
switch ( V_3 -> V_18 ) {
case V_19 :
V_16 . V_20 -> V_309 = V_26 -> V_154 ;
V_16 . V_20 -> V_310 = V_272 ;
V_16 . V_20 -> V_311 = V_298 ;
V_16 . V_20 -> V_312 = V_299 ;
V_16 . V_20 -> V_42 = V_28 . V_43 ;
V_16 . V_20 -> V_44 = V_28 . V_45 / V_46 ;
V_101 = sizeof( * V_16 . V_20 ) ;
break;
case V_22 :
V_16 . V_23 -> V_309 = V_26 -> V_154 ;
V_16 . V_23 -> V_310 = V_272 ;
V_16 . V_23 -> V_311 = V_298 ;
V_16 . V_23 -> V_312 = V_299 ;
V_16 . V_23 -> V_42 = V_28 . V_43 ;
V_16 . V_23 -> V_47 = V_28 . V_45 ;
if ( F_89 ( V_26 ) ) {
V_16 . V_23 -> V_149 = F_90 ( V_26 ) ;
V_14 |= V_150 ;
} else {
V_16 . V_23 -> V_149 = 0 ;
}
V_16 . V_23 -> V_313 = 0 ;
V_101 = sizeof( * V_16 . V_23 ) ;
break;
case V_24 :
V_16 . V_314 -> V_21 |= V_14 ;
V_16 . V_314 -> V_309 = V_26 -> V_154 ;
V_16 . V_314 -> V_310 = V_272 ;
V_16 . V_314 -> V_311 = V_298 ;
V_16 . V_314 -> V_312 = V_299 ;
V_16 . V_314 -> V_42 = V_28 . V_43 ;
V_16 . V_314 -> V_47 = V_28 . V_45 ;
V_101 = sizeof( * V_16 . V_314 ) ;
break;
default:
F_28 () ;
}
V_269 = V_16 . V_17 + F_186 ( V_101 ) ;
V_269 -> V_290 = F_182 ( V_26 , V_269 -> V_291 ) ;
V_269 -> V_283 = V_284 ;
V_269 -> V_285 = V_4 -> type ;
V_269 -> V_286 = V_26 -> V_222 ;
V_269 -> V_287 = V_26 -> V_212 ;
if ( F_51 ( V_3 -> V_288 ) )
V_269 -> V_289 = V_183 -> V_81 ;
else
V_269 -> V_289 = V_4 -> V_81 ;
F_96 () ;
#if V_122 == 1
{
T_3 * V_123 , * V_124 ;
if ( V_3 -> V_18 <= V_22 ) {
V_124 = ( T_3 * ) F_70 ( ( unsigned long ) V_16 . V_17
+ V_298 + V_272 ) ;
for ( V_123 = V_16 . V_17 ; V_123 < V_124 ; V_123 += V_125 )
F_25 ( F_26 ( V_123 ) ) ;
}
F_29 () ;
}
#endif
if ( V_3 -> V_18 <= V_22 )
F_24 ( V_3 , V_16 . V_17 , V_14 ) ;
else
F_82 ( & V_3 -> V_65 ) ;
V_7 -> V_297 ( V_7 , 0 ) ;
V_277:
if ( V_270 != V_26 -> V_68 && F_178 ( V_26 ) ) {
V_26 -> V_68 = V_270 ;
V_26 -> V_154 = V_271 ;
}
V_273:
F_129 ( V_26 ) ;
return 0 ;
V_307:
V_3 -> V_105 . V_293 . V_134 ++ ;
F_20 ( & V_7 -> V_115 . V_66 ) ;
V_7 -> V_297 ( V_7 , 0 ) ;
F_129 ( V_300 ) ;
goto V_277;
}
static void F_189 ( struct V_25 * V_26 )
{
struct V_2 * V_3 = F_12 ( V_26 -> V_7 ) ;
void * V_315 ;
if ( F_4 ( V_3 -> V_61 . V_54 ) ) {
T_1 V_28 ;
V_315 = F_170 ( V_26 ) -> V_316 ;
F_131 ( F_64 ( & V_3 -> V_61 . V_317 ) == 0 ) ;
F_84 ( & V_3 -> V_61 . V_317 ) ;
V_28 = F_35 ( V_3 , V_315 , V_26 ) ;
F_24 ( V_3 , V_315 , V_151 | V_28 ) ;
}
F_190 ( V_26 ) ;
}
static int F_191 ( struct V_2 * V_3 , struct V_25 * V_26 ,
void * V_13 , struct V_1 * V_4 , int V_318 ,
T_6 V_230 , unsigned char * V_319 , int V_320 )
{
union V_15 V_315 ;
int V_321 , V_322 , V_154 , V_309 , V_323 , V_324 ;
struct V_225 * V_6 = V_3 -> V_7 . V_325 ;
struct V_326 * V_326 ;
void * V_68 ;
int V_79 ;
V_315 . V_17 = V_13 ;
V_26 -> V_222 = V_230 ;
V_26 -> V_4 = V_4 ;
V_26 -> V_259 = V_3 -> V_7 . V_260 ;
V_26 -> V_261 = V_3 -> V_7 . V_262 ;
F_169 ( & V_3 -> V_7 , & F_170 ( V_26 ) -> V_263 ) ;
F_170 ( V_26 ) -> V_316 = V_315 . V_17 ;
switch ( V_3 -> V_18 ) {
case V_22 :
V_309 = V_315 . V_23 -> V_309 ;
break;
default:
V_309 = V_315 . V_20 -> V_309 ;
break;
}
if ( F_51 ( V_309 > V_318 ) ) {
F_111 ( L_4 , V_309 , V_318 ) ;
return - V_242 ;
}
F_162 ( V_26 , V_320 ) ;
F_163 ( V_26 ) ;
F_171 ( V_26 , 0 ) ;
if ( V_3 -> V_327 ) {
int V_328 , V_329 , V_330 ;
V_328 = V_3 -> V_102 - sizeof( struct V_268 ) ;
V_329 = V_3 -> V_61 . V_56 - V_309 ;
if ( V_6 -> type == V_275 ) {
switch ( V_3 -> V_18 ) {
case V_22 :
V_330 = V_315 . V_23 -> V_312 ;
break;
default:
V_330 = V_315 . V_20 -> V_312 ;
break;
}
} else {
switch ( V_3 -> V_18 ) {
case V_22 :
V_330 = V_315 . V_23 -> V_311 ;
break;
default:
V_330 = V_315 . V_20 -> V_311 ;
break;
}
}
if ( F_51 ( ( V_330 < V_328 ) || ( V_329 < V_330 ) ) )
return - V_199 ;
V_68 = V_315 . V_17 + V_330 ;
} else {
V_68 = V_315 . V_17 + V_3 -> V_102 - sizeof( struct V_268 ) ;
}
V_321 = V_309 ;
if ( V_6 -> type == V_275 ) {
V_79 = F_192 ( V_26 , V_4 , F_193 ( V_230 ) , V_319 ,
NULL , V_309 ) ;
if ( F_51 ( V_79 < 0 ) )
return - V_199 ;
} else if ( V_4 -> V_244 ) {
if ( F_51 ( V_309 <= V_4 -> V_244 ) ) {
F_111 ( L_5 ,
V_309 , V_4 -> V_244 ) ;
return - V_199 ;
}
F_153 ( V_26 , V_4 -> V_244 ) ;
V_79 = F_194 ( V_26 , 0 , V_68 ,
V_4 -> V_244 ) ;
if ( F_51 ( V_79 ) )
return V_79 ;
V_68 += V_4 -> V_244 ;
V_321 -= V_4 -> V_244 ;
}
V_322 = F_195 ( V_68 ) ;
V_324 = V_125 - V_322 ;
V_154 = ( ( V_321 > V_324 ) ? V_324 : V_321 ) ;
V_26 -> V_331 = V_321 ;
V_26 -> V_154 += V_321 ;
V_26 -> V_162 += V_321 ;
F_196 ( V_321 , & V_3 -> V_7 . V_165 ) ;
while ( F_4 ( V_321 ) ) {
V_323 = F_170 ( V_26 ) -> V_323 ;
if ( F_51 ( V_323 >= V_332 ) ) {
F_111 ( L_6 ,
V_332 ) ;
return - V_333 ;
}
V_326 = F_26 ( V_68 ) ;
V_68 += V_154 ;
F_25 ( V_326 ) ;
F_197 ( V_326 ) ;
F_198 ( V_26 , V_323 , V_326 , V_322 , V_154 ) ;
V_321 -= V_154 ;
V_322 = 0 ;
V_324 = V_125 ;
V_154 = ( ( V_321 > V_324 ) ? V_324 : V_321 ) ;
}
return V_309 ;
}
static int F_199 ( struct V_2 * V_3 , struct V_226 * V_227 )
{
struct V_25 * V_26 ;
struct V_1 * V_4 ;
T_6 V_230 ;
int V_79 , V_334 = 0 ;
void * V_315 ;
struct V_268 * V_228 = (struct V_268 * ) V_227 -> V_229 ;
int V_309 , V_318 ;
unsigned char * V_319 ;
int V_335 = 0 ;
int V_14 = V_151 ;
int V_320 , V_247 ;
F_134 ( & V_3 -> V_336 ) ;
if ( F_4 ( V_228 == NULL ) ) {
V_4 = F_1 ( V_3 ) ;
V_230 = V_3 -> V_169 ;
V_319 = NULL ;
} else {
V_79 = - V_199 ;
if ( V_227 -> V_232 < sizeof( struct V_268 ) )
goto V_116;
if ( V_227 -> V_232 < ( V_228 -> V_290
+ F_200 ( struct V_268 ,
V_291 ) ) )
goto V_116;
V_230 = V_228 -> V_286 ;
V_319 = V_228 -> V_291 ;
V_4 = F_201 ( F_50 ( & V_3 -> V_7 ) , V_228 -> V_289 ) ;
}
V_79 = - V_337 ;
if ( F_51 ( V_4 == NULL ) )
goto V_116;
V_79 = - V_238 ;
if ( F_51 ( ! ( V_4 -> V_29 & V_239 ) ) )
goto V_338;
V_334 = V_4 -> V_244 ;
V_318 = V_3 -> V_61 . V_56
- ( V_3 -> V_102 - sizeof( struct V_268 ) ) ;
if ( V_318 > V_4 -> V_243 + V_334 )
V_318 = V_4 -> V_243 + V_334 ;
do {
V_315 = F_37 ( V_3 , & V_3 -> V_61 ,
V_339 ) ;
if ( F_51 ( V_315 == NULL ) ) {
F_202 () ;
continue;
}
V_14 = V_339 ;
V_320 = F_160 ( V_4 ) ;
V_247 = V_4 -> V_248 ;
V_26 = F_203 ( & V_3 -> V_7 ,
V_320 + V_247 + sizeof( struct V_268 ) ,
0 , & V_79 ) ;
if ( F_51 ( V_26 == NULL ) )
goto V_340;
V_309 = F_191 ( V_3 , V_26 , V_315 , V_4 , V_318 , V_230 ,
V_319 , V_320 ) ;
if ( F_51 ( V_309 < 0 ) ) {
if ( V_3 -> V_341 ) {
F_24 ( V_3 , V_315 ,
V_151 ) ;
F_105 ( & V_3 -> V_61 ) ;
F_129 ( V_26 ) ;
continue;
} else {
V_14 = V_342 ;
V_79 = V_309 ;
goto V_340;
}
}
V_26 -> V_343 = F_189 ;
F_24 ( V_3 , V_315 , V_344 ) ;
F_94 ( & V_3 -> V_61 . V_317 ) ;
V_14 = V_339 ;
V_79 = F_172 ( V_26 ) ;
if ( F_51 ( V_79 > 0 ) ) {
V_79 = F_204 ( V_79 ) ;
if ( V_79 && F_30 ( V_3 , V_315 ) ==
V_151 ) {
V_26 = NULL ;
goto V_340;
}
V_79 = 0 ;
}
F_105 ( & V_3 -> V_61 ) ;
V_335 += V_309 ;
} while ( F_4 ( ( V_315 != NULL ) ||
( ( ! ( V_227 -> V_345 & V_346 ) ) &&
( F_64 ( & V_3 -> V_61 . V_317 ) ) ) )
);
V_79 = V_335 ;
goto V_338;
V_340:
F_24 ( V_3 , V_315 , V_14 ) ;
F_129 ( V_26 ) ;
V_338:
F_205 ( V_4 ) ;
V_116:
F_142 ( & V_3 -> V_336 ) ;
return V_79 ;
}
static struct V_25 * F_206 ( struct V_6 * V_7 , T_5 V_347 ,
T_5 V_334 , T_5 V_154 ,
T_5 V_348 , int V_349 ,
int * V_79 )
{
struct V_25 * V_26 ;
if ( V_347 + V_154 < V_125 || ! V_348 )
V_348 = V_154 ;
V_26 = F_207 ( V_7 , V_347 + V_348 , V_154 - V_348 , V_349 ,
V_79 , 0 ) ;
if ( ! V_26 )
return NULL ;
F_162 ( V_26 , V_334 ) ;
F_165 ( V_26 , V_348 ) ;
V_26 -> V_331 = V_154 - V_348 ;
V_26 -> V_154 += V_154 - V_348 ;
return V_26 ;
}
static int F_208 ( struct V_225 * V_6 ,
struct V_226 * V_227 , T_5 V_154 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_268 * V_228 = (struct V_268 * ) V_227 -> V_229 ;
struct V_25 * V_26 ;
struct V_1 * V_4 ;
T_6 V_230 ;
unsigned char * V_319 ;
int V_79 , V_334 = 0 ;
struct V_350 V_351 = { 0 } ;
int V_322 = 0 ;
int V_352 ;
struct V_2 * V_3 = F_12 ( V_7 ) ;
unsigned short V_353 = 0 ;
int V_320 , V_247 ;
int V_231 = 0 ;
if ( F_4 ( V_228 == NULL ) ) {
V_4 = F_1 ( V_3 ) ;
V_230 = V_3 -> V_169 ;
V_319 = NULL ;
} else {
V_79 = - V_199 ;
if ( V_227 -> V_232 < sizeof( struct V_268 ) )
goto V_116;
if ( V_227 -> V_232 < ( V_228 -> V_290 + F_200 ( struct V_268 , V_291 ) ) )
goto V_116;
V_230 = V_228 -> V_286 ;
V_319 = V_228 -> V_291 ;
V_4 = F_201 ( F_50 ( V_7 ) , V_228 -> V_289 ) ;
}
V_79 = - V_337 ;
if ( F_51 ( V_4 == NULL ) )
goto V_237;
V_79 = - V_238 ;
if ( F_51 ( ! ( V_4 -> V_29 & V_239 ) ) )
goto V_237;
if ( V_6 -> type == V_354 )
V_334 = V_4 -> V_244 ;
if ( V_3 -> V_355 ) {
V_352 = sizeof( V_351 ) ;
V_79 = - V_199 ;
if ( V_154 < V_352 )
goto V_237;
V_154 -= V_352 ;
V_79 = F_164 ( ( void * ) & V_351 , V_227 -> V_253 ,
V_352 ) ;
if ( V_79 < 0 )
goto V_237;
if ( ( V_351 . V_29 & V_356 ) &&
( V_351 . V_357 + V_351 . V_358 + 2 >
V_351 . V_359 ) )
V_351 . V_359 = V_351 . V_357 +
V_351 . V_358 + 2 ;
V_79 = - V_199 ;
if ( V_351 . V_359 > V_154 )
goto V_237;
if ( V_351 . V_353 != V_360 ) {
switch ( V_351 . V_353 & ~ V_361 ) {
case V_362 :
V_353 = V_363 ;
break;
case V_364 :
V_353 = V_365 ;
break;
case V_366 :
V_353 = V_367 ;
break;
default:
goto V_237;
}
if ( V_351 . V_353 & V_361 )
V_353 |= V_368 ;
if ( V_351 . V_369 == 0 )
goto V_237;
}
}
if ( F_51 ( F_110 ( V_7 , V_240 ) ) ) {
if ( ! F_159 ( V_4 ) ) {
V_79 = - V_241 ;
goto V_237;
}
V_231 = 4 ;
}
V_79 = - V_242 ;
if ( ! V_353 && ( V_154 > V_4 -> V_243 + V_334 + V_245 + V_231 ) )
goto V_237;
V_79 = - V_251 ;
V_320 = F_160 ( V_4 ) ;
V_247 = V_4 -> V_248 ;
V_26 = F_206 ( V_7 , V_320 + V_247 , V_320 , V_154 , V_351 . V_359 ,
V_227 -> V_345 & V_346 , & V_79 ) ;
if ( V_26 == NULL )
goto V_237;
F_209 ( V_26 , V_334 ) ;
V_79 = - V_199 ;
if ( V_6 -> type == V_275 &&
( V_322 = F_192 ( V_26 , V_4 , F_193 ( V_230 ) , V_319 , NULL , V_154 ) ) < 0 )
goto V_254;
V_79 = F_210 ( V_26 , V_322 , V_227 -> V_253 , 0 , V_154 ) ;
if ( V_79 )
goto V_254;
F_169 ( V_7 , & F_170 ( V_26 ) -> V_263 ) ;
if ( ! V_353 && ( V_154 > V_4 -> V_243 + V_334 + V_231 ) ) {
struct V_255 * V_256 ;
F_166 ( V_26 ) ;
V_256 = F_167 ( V_26 ) ;
if ( V_256 -> V_257 != F_168 ( V_258 ) ) {
V_79 = - V_242 ;
goto V_254;
}
}
V_26 -> V_222 = V_230 ;
V_26 -> V_4 = V_4 ;
V_26 -> V_259 = V_7 -> V_260 ;
V_26 -> V_261 = V_7 -> V_262 ;
if ( V_3 -> V_355 ) {
if ( V_351 . V_29 & V_356 ) {
if ( ! F_211 ( V_26 , V_351 . V_357 ,
V_351 . V_358 ) ) {
V_79 = - V_199 ;
goto V_254;
}
}
F_170 ( V_26 ) -> V_369 = V_351 . V_369 ;
F_170 ( V_26 ) -> V_353 = V_353 ;
F_170 ( V_26 ) -> V_353 |= V_370 ;
F_170 ( V_26 ) -> V_371 = 0 ;
V_154 += V_352 ;
}
F_171 ( V_26 , V_334 ) ;
if ( F_51 ( V_231 == 4 ) )
V_26 -> V_264 = 1 ;
V_79 = F_172 ( V_26 ) ;
if ( V_79 > 0 && ( V_79 = F_204 ( V_79 ) ) != 0 )
goto V_237;
F_205 ( V_4 ) ;
return V_154 ;
V_254:
F_129 ( V_26 ) ;
V_237:
if ( V_4 )
F_205 ( V_4 ) ;
V_116:
return V_79 ;
}
static int F_212 ( struct V_223 * V_224 , struct V_225 * V_6 ,
struct V_226 * V_227 , T_5 V_154 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_2 * V_3 = F_12 ( V_7 ) ;
if ( V_3 -> V_61 . V_54 )
return F_199 ( V_3 , V_227 ) ;
else
return F_208 ( V_6 , V_227 , V_154 ) ;
}
static int F_213 ( struct V_225 * V_6 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_2 * V_3 ;
struct V_186 * V_186 ;
union V_86 V_87 ;
if ( ! V_7 )
return 0 ;
V_186 = F_50 ( V_7 ) ;
V_3 = F_12 ( V_7 ) ;
F_134 ( & V_186 -> V_372 . V_373 ) ;
F_214 ( V_7 ) ;
F_142 ( & V_186 -> V_372 . V_373 ) ;
F_215 () ;
F_216 ( V_186 , V_7 -> V_374 , - 1 ) ;
F_217 () ;
F_22 ( & V_3 -> V_12 ) ;
F_23 ( V_7 , false ) ;
F_9 ( V_3 ) ;
if ( V_3 -> V_10 . V_4 ) {
F_205 ( V_3 -> V_10 . V_4 ) ;
V_3 -> V_10 . V_4 = NULL ;
}
F_20 ( & V_3 -> V_12 ) ;
F_218 ( V_7 ) ;
if ( V_3 -> V_65 . V_54 ) {
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
F_219 ( V_7 , & V_87 , 1 , 0 ) ;
}
if ( V_3 -> V_61 . V_54 ) {
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
F_219 ( V_7 , & V_87 , 1 , 1 ) ;
}
F_143 ( V_7 ) ;
F_21 () ;
F_220 ( V_7 ) ;
V_6 -> V_7 = NULL ;
F_108 ( & V_7 -> V_115 ) ;
F_221 ( V_7 ) ;
F_222 ( V_7 ) ;
return 0 ;
}
static int F_223 ( struct V_6 * V_7 , struct V_1 * V_4 , T_6 V_222 )
{
struct V_2 * V_3 = F_12 ( V_7 ) ;
if ( V_3 -> V_9 ) {
if ( V_4 )
F_205 ( V_4 ) ;
return - V_199 ;
}
F_224 ( V_7 ) ;
F_22 ( & V_3 -> V_12 ) ;
F_23 ( V_7 , true ) ;
V_3 -> V_169 = V_222 ;
V_3 -> V_10 . type = V_222 ;
if ( V_3 -> V_10 . V_4 )
F_205 ( V_3 -> V_10 . V_4 ) ;
V_3 -> V_10 . V_4 = V_4 ;
V_3 -> V_81 = V_4 ? V_4 -> V_81 : 0 ;
F_7 ( V_3 , V_4 ) ;
if ( V_222 == 0 )
goto V_237;
if ( ! V_4 || ( V_4 -> V_29 & V_239 ) ) {
F_11 ( V_7 ) ;
} else {
V_7 -> V_375 = V_238 ;
if ( ! F_110 ( V_7 , V_166 ) )
V_7 -> V_376 ( V_7 ) ;
}
V_237:
F_20 ( & V_3 -> V_12 ) ;
F_225 ( V_7 ) ;
return 0 ;
}
static int F_226 ( struct V_225 * V_6 , struct V_233 * V_377 ,
int V_378 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
char V_220 [ 15 ] ;
struct V_1 * V_4 ;
int V_79 = - V_236 ;
if ( V_378 != sizeof( struct V_233 ) )
return - V_199 ;
F_155 ( V_220 , V_377 -> V_379 , sizeof( V_220 ) ) ;
V_4 = F_227 ( F_50 ( V_7 ) , V_220 ) ;
if ( V_4 )
V_79 = F_223 ( V_7 , V_4 , F_12 ( V_7 ) -> V_169 ) ;
return V_79 ;
}
static int F_228 ( struct V_225 * V_6 , struct V_233 * V_377 , int V_378 )
{
struct V_268 * V_269 = (struct V_268 * ) V_377 ;
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_1 * V_4 = NULL ;
int V_79 ;
if ( V_378 < sizeof( struct V_268 ) )
return - V_199 ;
if ( V_269 -> V_283 != V_284 )
return - V_199 ;
if ( V_269 -> V_289 ) {
V_79 = - V_236 ;
V_4 = F_201 ( F_50 ( V_7 ) , V_269 -> V_289 ) ;
if ( V_4 == NULL )
goto V_116;
}
V_79 = F_223 ( V_7 , V_4 , V_269 -> V_286 ? : F_12 ( V_7 ) -> V_169 ) ;
V_116:
return V_79 ;
}
static int F_229 ( struct V_186 * V_186 , struct V_225 * V_6 , int V_222 ,
int V_380 )
{
struct V_6 * V_7 ;
struct V_2 * V_3 ;
T_6 V_230 = ( V_381 T_6 ) V_222 ;
int V_79 ;
if ( ! F_230 ( V_186 -> V_382 , V_383 ) )
return - V_384 ;
if ( V_6 -> type != V_275 && V_6 -> type != V_354 &&
V_6 -> type != V_385 )
return - V_386 ;
V_6 -> V_387 = V_388 ;
V_79 = - V_251 ;
V_7 = F_231 ( V_186 , V_389 , V_203 , & V_390 ) ;
if ( V_7 == NULL )
goto V_116;
V_6 -> V_391 = & V_392 ;
if ( V_6 -> type == V_385 )
V_6 -> V_391 = & V_393 ;
F_232 ( V_6 , V_7 ) ;
V_3 = F_12 ( V_7 ) ;
V_7 -> V_394 = V_389 ;
V_3 -> V_169 = V_230 ;
F_9 ( V_3 ) ;
V_7 -> V_395 = F_107 ;
F_233 ( V_7 ) ;
F_140 ( & V_3 -> V_12 ) ;
F_234 ( & V_3 -> V_336 ) ;
V_3 -> V_10 . F_44 = F_175 ;
if ( V_6 -> type == V_385 )
V_3 -> V_10 . F_44 = F_148 ;
V_3 -> V_10 . V_184 = V_7 ;
if ( V_230 ) {
V_3 -> V_10 . type = V_230 ;
F_11 ( V_7 ) ;
}
F_134 ( & V_186 -> V_372 . V_373 ) ;
F_235 ( V_7 , & V_186 -> V_372 . V_396 ) ;
F_142 ( & V_186 -> V_372 . V_373 ) ;
F_215 () ;
F_216 ( V_186 , & V_390 , 1 ) ;
F_217 () ;
return 0 ;
V_116:
return V_79 ;
}
static int F_236 ( struct V_223 * V_224 , struct V_225 * V_6 ,
struct V_226 * V_227 , T_5 V_154 , int V_29 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_25 * V_26 ;
int V_397 , V_79 ;
int V_352 = 0 ;
V_79 = - V_199 ;
if ( V_29 & ~ ( V_398 | V_346 | V_399 | V_400 | V_401 ) )
goto V_116;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_29 & V_401 ) {
V_79 = F_237 ( V_7 , V_227 , V_154 ,
V_402 , V_403 ) ;
goto V_116;
}
V_26 = F_238 ( V_7 , V_29 , V_29 & V_346 , & V_79 ) ;
if ( V_26 == NULL )
goto V_116;
if ( F_12 ( V_7 ) -> V_355 ) {
struct V_350 V_351 = { 0 } ;
V_79 = - V_199 ;
V_352 = sizeof( V_351 ) ;
if ( V_154 < V_352 )
goto V_254;
V_154 -= V_352 ;
if ( F_239 ( V_26 ) ) {
struct V_404 * V_405 = F_170 ( V_26 ) ;
V_351 . V_359 = F_240 ( V_26 ) ;
V_351 . V_369 = V_405 -> V_369 ;
if ( V_405 -> V_353 & V_363 )
V_351 . V_353 = V_362 ;
else if ( V_405 -> V_353 & V_365 )
V_351 . V_353 = V_364 ;
else if ( V_405 -> V_353 & V_367 )
V_351 . V_353 = V_366 ;
else if ( V_405 -> V_353 & V_406 )
goto V_254;
else
F_28 () ;
if ( V_405 -> V_353 & V_368 )
V_351 . V_353 |= V_361 ;
} else
V_351 . V_353 = V_360 ;
if ( V_26 -> V_301 == V_302 ) {
V_351 . V_29 = V_356 ;
V_351 . V_357 = F_241 ( V_26 ) ;
V_351 . V_358 = V_26 -> V_358 ;
} else if ( V_26 -> V_301 == V_407 ) {
V_351 . V_29 = V_408 ;
}
V_79 = F_242 ( V_227 -> V_253 , ( void * ) & V_351 ,
V_352 ) ;
if ( V_79 < 0 )
goto V_254;
}
V_397 = V_26 -> V_154 ;
if ( V_397 > V_154 ) {
V_397 = V_154 ;
V_227 -> V_345 |= V_399 ;
}
V_79 = F_243 ( V_26 , 0 , V_227 -> V_253 , V_397 ) ;
if ( V_79 )
goto V_254;
F_244 ( V_227 , V_7 , V_26 ) ;
if ( V_227 -> V_229 ) {
if ( V_6 -> type == V_385 ) {
V_227 -> V_232 = sizeof( struct V_210 ) ;
} else {
struct V_268 * V_269 = & F_152 ( V_26 ) -> V_216 . V_282 ;
V_227 -> V_232 = V_269 -> V_290 +
F_200 ( struct V_268 , V_291 ) ;
}
memcpy ( V_227 -> V_229 , & F_152 ( V_26 ) -> V_216 ,
V_227 -> V_232 ) ;
}
if ( F_12 ( V_7 ) -> V_409 ) {
struct V_410 V_411 ;
V_411 . V_21 = V_128 ;
if ( V_26 -> V_301 == V_302 )
V_411 . V_21 |= V_303 ;
V_411 . V_309 = F_152 ( V_26 ) -> V_292 ;
V_411 . V_310 = V_26 -> V_154 ;
V_411 . V_311 = 0 ;
V_411 . V_312 = F_177 ( V_26 ) ;
if ( F_89 ( V_26 ) ) {
V_411 . V_149 = F_90 ( V_26 ) ;
V_411 . V_21 |= V_150 ;
} else {
V_411 . V_149 = 0 ;
}
V_411 . V_313 = 0 ;
F_245 ( V_227 , V_402 , V_412 , sizeof( V_411 ) , & V_411 ) ;
}
V_79 = V_352 + ( ( V_29 & V_399 ) ? V_26 -> V_154 : V_397 ) ;
V_254:
F_246 ( V_7 , V_26 ) ;
V_116:
return V_79 ;
}
static int F_247 ( struct V_225 * V_6 , struct V_233 * V_377 ,
int * V_413 , int V_414 )
{
struct V_1 * V_4 ;
struct V_6 * V_7 = V_6 -> V_7 ;
if ( V_414 )
return - V_415 ;
V_377 -> V_416 = V_284 ;
memset ( V_377 -> V_379 , 0 , sizeof( V_377 -> V_379 ) ) ;
F_2 () ;
V_4 = F_248 ( F_50 ( V_7 ) , F_12 ( V_7 ) -> V_81 ) ;
if ( V_4 )
F_155 ( V_377 -> V_379 , V_4 -> V_220 , sizeof( V_377 -> V_379 ) ) ;
F_6 () ;
* V_413 = sizeof( * V_377 ) ;
return 0 ;
}
static int F_249 ( struct V_225 * V_6 , struct V_233 * V_377 ,
int * V_413 , int V_414 )
{
struct V_1 * V_4 ;
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_2 * V_3 = F_12 ( V_7 ) ;
F_250 ( struct V_268 * , V_269 , V_377 ) ;
if ( V_414 )
return - V_415 ;
V_269 -> V_283 = V_284 ;
V_269 -> V_289 = V_3 -> V_81 ;
V_269 -> V_286 = V_3 -> V_169 ;
V_269 -> V_287 = 0 ;
F_2 () ;
V_4 = F_248 ( F_50 ( V_7 ) , V_3 -> V_81 ) ;
if ( V_4 ) {
V_269 -> V_285 = V_4 -> type ;
V_269 -> V_290 = V_4 -> V_378 ;
memcpy ( V_269 -> V_291 , V_4 -> V_417 , V_4 -> V_378 ) ;
} else {
V_269 -> V_285 = 0 ;
V_269 -> V_290 = 0 ;
}
F_6 () ;
* V_413 = F_200 ( struct V_268 , V_291 ) + V_269 -> V_290 ;
return 0 ;
}
static int F_251 ( struct V_1 * V_4 , struct V_418 * V_176 ,
int V_419 )
{
switch ( V_176 -> type ) {
case V_420 :
if ( V_176 -> V_421 != V_4 -> V_378 )
return - V_199 ;
if ( V_419 > 0 )
return F_252 ( V_4 , V_176 -> V_319 ) ;
else
return F_253 ( V_4 , V_176 -> V_319 ) ;
break;
case V_422 :
return F_254 ( V_4 , V_419 ) ;
break;
case V_423 :
return F_255 ( V_4 , V_419 ) ;
break;
case V_424 :
if ( V_176 -> V_421 != V_4 -> V_378 )
return - V_199 ;
if ( V_419 > 0 )
return F_256 ( V_4 , V_176 -> V_319 ) ;
else
return F_257 ( V_4 , V_176 -> V_319 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_258 ( struct V_1 * V_4 , struct V_418 * V_176 , int V_419 )
{
for ( ; V_176 ; V_176 = V_176 -> V_178 ) {
if ( V_176 -> V_81 == V_4 -> V_81 )
F_251 ( V_4 , V_176 , V_419 ) ;
}
}
static int F_259 ( struct V_6 * V_7 , struct V_425 * V_426 )
{
struct V_2 * V_3 = F_12 ( V_7 ) ;
struct V_418 * V_427 , * V_176 ;
struct V_1 * V_4 ;
int V_79 ;
F_48 () ;
V_79 = - V_236 ;
V_4 = F_49 ( F_50 ( V_7 ) , V_426 -> V_428 ) ;
if ( ! V_4 )
goto V_429;
V_79 = - V_199 ;
if ( V_426 -> V_430 > V_4 -> V_378 )
goto V_429;
V_79 = - V_251 ;
V_176 = F_260 ( sizeof( * V_176 ) , V_203 ) ;
if ( V_176 == NULL )
goto V_429;
V_79 = 0 ;
for ( V_427 = V_3 -> V_431 ; V_427 ; V_427 = V_427 -> V_178 ) {
if ( V_427 -> V_81 == V_426 -> V_428 &&
V_427 -> type == V_426 -> V_432 &&
V_427 -> V_421 == V_426 -> V_430 &&
memcmp ( V_427 -> V_319 , V_426 -> V_433 , V_427 -> V_421 ) == 0 ) {
V_427 -> V_434 ++ ;
F_147 ( V_176 ) ;
goto V_429;
}
}
V_176 -> type = V_426 -> V_432 ;
V_176 -> V_81 = V_426 -> V_428 ;
V_176 -> V_421 = V_426 -> V_430 ;
memcpy ( V_176 -> V_319 , V_426 -> V_433 , V_176 -> V_421 ) ;
V_176 -> V_434 = 1 ;
V_176 -> V_178 = V_3 -> V_431 ;
V_3 -> V_431 = V_176 ;
V_79 = F_251 ( V_4 , V_176 , 1 ) ;
if ( V_79 ) {
V_3 -> V_431 = V_176 -> V_178 ;
F_147 ( V_176 ) ;
}
V_429:
F_52 () ;
return V_79 ;
}
static int F_261 ( struct V_6 * V_7 , struct V_425 * V_426 )
{
struct V_418 * V_427 , * * V_435 ;
F_48 () ;
for ( V_435 = & F_12 ( V_7 ) -> V_431 ; ( V_427 = * V_435 ) != NULL ; V_435 = & V_427 -> V_178 ) {
if ( V_427 -> V_81 == V_426 -> V_428 &&
V_427 -> type == V_426 -> V_432 &&
V_427 -> V_421 == V_426 -> V_430 &&
memcmp ( V_427 -> V_319 , V_426 -> V_433 , V_427 -> V_421 ) == 0 ) {
if ( -- V_427 -> V_434 == 0 ) {
struct V_1 * V_4 ;
* V_435 = V_427 -> V_178 ;
V_4 = F_49 ( F_50 ( V_7 ) , V_427 -> V_81 ) ;
if ( V_4 )
F_251 ( V_4 , V_427 , - 1 ) ;
F_147 ( V_427 ) ;
}
F_52 () ;
return 0 ;
}
}
F_52 () ;
return - V_436 ;
}
static void F_218 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_12 ( V_7 ) ;
struct V_418 * V_427 ;
if ( ! V_3 -> V_431 )
return;
F_48 () ;
while ( ( V_427 = V_3 -> V_431 ) != NULL ) {
struct V_1 * V_4 ;
V_3 -> V_431 = V_427 -> V_178 ;
V_4 = F_49 ( F_50 ( V_7 ) , V_427 -> V_81 ) ;
if ( V_4 != NULL )
F_251 ( V_4 , V_427 , - 1 ) ;
F_147 ( V_427 ) ;
}
F_52 () ;
}
static int
F_262 ( struct V_225 * V_6 , int V_437 , int V_438 , char T_7 * V_439 , unsigned int V_440 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_2 * V_3 = F_12 ( V_7 ) ;
int V_441 ;
if ( V_437 != V_402 )
return - V_442 ;
switch ( V_438 ) {
case V_443 :
case V_444 :
{
struct V_425 V_426 ;
int V_154 = V_440 ;
memset ( & V_426 , 0 , sizeof( V_426 ) ) ;
if ( V_154 < sizeof( struct V_445 ) )
return - V_199 ;
if ( V_154 > sizeof( V_426 ) )
V_154 = sizeof( V_426 ) ;
if ( F_263 ( & V_426 , V_439 , V_154 ) )
return - V_333 ;
if ( V_154 < ( V_426 . V_430 + F_200 ( struct V_445 , V_433 ) ) )
return - V_199 ;
if ( V_438 == V_443 )
V_441 = F_259 ( V_7 , & V_426 ) ;
else
V_441 = F_261 ( V_7 , & V_426 ) ;
return V_441 ;
}
case V_446 :
case V_447 :
{
union V_86 V_87 ;
int V_154 ;
switch ( V_3 -> V_18 ) {
case V_19 :
case V_22 :
V_154 = sizeof( V_87 . V_448 ) ;
break;
case V_24 :
default:
V_154 = sizeof( V_87 . V_89 ) ;
break;
}
if ( V_440 < V_154 )
return - V_199 ;
if ( F_12 ( V_7 ) -> V_355 )
return - V_199 ;
if ( F_263 ( & V_87 . V_448 , V_439 , V_154 ) )
return - V_333 ;
return F_219 ( V_7 , & V_87 , 0 ,
V_438 == V_447 ) ;
}
case V_449 :
{
int V_450 ;
if ( V_440 != sizeof( V_450 ) )
return - V_199 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
F_12 ( V_7 ) -> V_306 = V_450 ;
return 0 ;
}
case V_451 :
{
int V_450 ;
if ( V_440 != sizeof( V_450 ) )
return - V_199 ;
if ( V_3 -> V_65 . V_54 || V_3 -> V_61 . V_54 )
return - V_452 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
switch ( V_450 ) {
case V_19 :
case V_22 :
case V_24 :
V_3 -> V_18 = V_450 ;
return 0 ;
default:
return - V_199 ;
}
}
case V_453 :
{
unsigned int V_450 ;
if ( V_440 != sizeof( V_450 ) )
return - V_199 ;
if ( V_3 -> V_65 . V_54 || V_3 -> V_61 . V_54 )
return - V_452 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
V_3 -> V_304 = V_450 ;
return 0 ;
}
case V_454 :
{
unsigned int V_450 ;
if ( V_440 != sizeof( V_450 ) )
return - V_199 ;
if ( V_3 -> V_65 . V_54 || V_3 -> V_61 . V_54 )
return - V_452 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
V_3 -> V_341 = ! ! V_450 ;
return 0 ;
}
case V_412 :
{
int V_450 ;
if ( V_440 < sizeof( V_450 ) )
return - V_199 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
V_3 -> V_409 = ! ! V_450 ;
return 0 ;
}
case V_455 :
{
int V_450 ;
if ( V_440 < sizeof( V_450 ) )
return - V_199 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
V_3 -> V_288 = ! ! V_450 ;
return 0 ;
}
case V_456 :
{
int V_450 ;
if ( V_6 -> type != V_354 )
return - V_199 ;
if ( V_3 -> V_65 . V_54 || V_3 -> V_61 . V_54 )
return - V_452 ;
if ( V_440 < sizeof( V_450 ) )
return - V_199 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
V_3 -> V_355 = ! ! V_450 ;
return 0 ;
}
case V_457 :
{
int V_450 ;
if ( V_440 != sizeof( V_450 ) )
return - V_199 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
V_3 -> V_41 = V_450 ;
return 0 ;
}
case V_458 :
{
int V_450 ;
if ( V_440 != sizeof( V_450 ) )
return - V_199 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
return F_133 ( V_7 , V_450 & 0xffff , V_450 >> 16 ) ;
}
case V_459 :
{
unsigned int V_450 ;
if ( V_440 != sizeof( V_450 ) )
return - V_199 ;
if ( V_3 -> V_65 . V_54 || V_3 -> V_61 . V_54 )
return - V_452 ;
if ( F_263 ( & V_450 , V_439 , sizeof( V_450 ) ) )
return - V_333 ;
V_3 -> V_327 = ! ! V_450 ;
return 0 ;
}
default:
return - V_442 ;
}
}
static int F_264 ( struct V_225 * V_6 , int V_437 , int V_438 ,
char T_7 * V_439 , int T_7 * V_440 )
{
int V_154 ;
int V_450 , V_460 = sizeof( V_450 ) ;
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_2 * V_3 = F_12 ( V_7 ) ;
void * V_68 = & V_450 ;
union V_461 V_462 ;
if ( V_437 != V_402 )
return - V_442 ;
if ( F_265 ( V_154 , V_440 ) )
return - V_333 ;
if ( V_154 < 0 )
return - V_199 ;
switch ( V_438 ) {
case V_463 :
F_41 ( & V_7 -> V_115 . V_66 ) ;
memcpy ( & V_462 , & V_3 -> V_105 , sizeof( V_462 ) ) ;
memset ( & V_3 -> V_105 , 0 , sizeof( V_3 -> V_105 ) ) ;
F_42 ( & V_7 -> V_115 . V_66 ) ;
if ( V_3 -> V_18 == V_24 ) {
V_460 = sizeof( struct V_464 ) ;
V_462 . V_106 . V_294 += V_462 . V_106 . V_134 ;
V_68 = & V_462 . V_106 ;
} else {
V_460 = sizeof( struct V_465 ) ;
V_462 . V_293 . V_294 += V_462 . V_293 . V_134 ;
V_68 = & V_462 . V_293 ;
}
break;
case V_412 :
V_450 = V_3 -> V_409 ;
break;
case V_455 :
V_450 = V_3 -> V_288 ;
break;
case V_456 :
V_450 = V_3 -> V_355 ;
break;
case V_451 :
V_450 = V_3 -> V_18 ;
break;
case V_466 :
if ( V_154 > sizeof( int ) )
V_154 = sizeof( int ) ;
if ( F_263 ( & V_450 , V_439 , V_154 ) )
return - V_333 ;
switch ( V_450 ) {
case V_19 :
V_450 = sizeof( struct V_467 ) ;
break;
case V_22 :
V_450 = sizeof( struct V_468 ) ;
break;
case V_24 :
V_450 = sizeof( struct V_129 ) ;
break;
default:
return - V_199 ;
}
break;
case V_453 :
V_450 = V_3 -> V_304 ;
break;
case V_454 :
V_450 = V_3 -> V_341 ;
break;
case V_457 :
V_450 = V_3 -> V_41 ;
break;
case V_458 :
V_450 = ( V_3 -> V_9 ?
( ( T_2 ) V_3 -> V_9 -> V_196 |
( ( T_2 ) V_3 -> V_9 -> type << 16 ) |
( ( T_2 ) V_3 -> V_9 -> V_29 << 24 ) ) :
0 ) ;
break;
case V_459 :
V_450 = V_3 -> V_327 ;
break;
default:
return - V_442 ;
}
if ( V_154 > V_460 )
V_154 = V_460 ;
if ( F_266 ( V_154 , V_440 ) )
return - V_333 ;
if ( F_267 ( V_439 , V_68 , V_154 ) )
return - V_333 ;
return 0 ;
}
static int F_268 ( struct V_469 * V_470 ,
unsigned long V_227 , void * V_471 )
{
struct V_6 * V_7 ;
struct V_1 * V_4 = F_269 ( V_471 ) ;
struct V_186 * V_186 = F_127 ( V_4 ) ;
F_2 () ;
F_270 (sk, &net->packet.sklist) {
struct V_2 * V_3 = F_12 ( V_7 ) ;
switch ( V_227 ) {
case V_472 :
if ( V_3 -> V_431 )
F_258 ( V_4 , V_3 -> V_431 , - 1 ) ;
case V_473 :
if ( V_4 -> V_81 == V_3 -> V_81 ) {
F_22 ( & V_3 -> V_12 ) ;
if ( V_3 -> V_8 ) {
F_16 ( V_7 , false ) ;
V_7 -> V_375 = V_238 ;
if ( ! F_110 ( V_7 , V_166 ) )
V_7 -> V_376 ( V_7 ) ;
}
if ( V_227 == V_472 ) {
F_9 ( V_3 ) ;
V_3 -> V_81 = - 1 ;
if ( V_3 -> V_10 . V_4 )
F_205 ( V_3 -> V_10 . V_4 ) ;
V_3 -> V_10 . V_4 = NULL ;
}
F_20 ( & V_3 -> V_12 ) ;
}
break;
case V_474 :
if ( V_4 -> V_81 == V_3 -> V_81 ) {
F_22 ( & V_3 -> V_12 ) ;
if ( V_3 -> V_169 )
F_11 ( V_7 ) ;
F_20 ( & V_3 -> V_12 ) ;
}
break;
}
}
F_6 () ;
return V_475 ;
}
static int F_271 ( struct V_225 * V_6 , unsigned int V_476 ,
unsigned long V_477 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
switch ( V_476 ) {
case V_478 :
{
int V_479 = F_272 ( V_7 ) ;
return F_266 ( V_479 , ( int T_7 * ) V_477 ) ;
}
case V_480 :
{
struct V_25 * V_26 ;
int V_479 = 0 ;
F_41 ( & V_7 -> V_115 . V_66 ) ;
V_26 = F_273 ( & V_7 -> V_115 ) ;
if ( V_26 )
V_479 = V_26 -> V_154 ;
F_42 ( & V_7 -> V_115 . V_66 ) ;
return F_266 ( V_479 , ( int T_7 * ) V_477 ) ;
}
case V_481 :
return F_274 ( V_7 , (struct V_482 T_7 * ) V_477 ) ;
case V_483 :
return F_275 ( V_7 , (struct V_27 T_7 * ) V_477 ) ;
#ifdef F_276
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_488 :
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
case V_494 :
case V_495 :
case V_496 :
case V_497 :
return V_498 . V_499 ( V_6 , V_476 , V_477 ) ;
#endif
default:
return - V_500 ;
}
return 0 ;
}
static unsigned int F_277 ( struct V_501 * V_501 , struct V_225 * V_6 ,
T_8 * V_502 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_2 * V_3 = F_12 ( V_7 ) ;
unsigned int V_503 = F_278 ( V_501 , V_6 , V_502 ) ;
F_41 ( & V_7 -> V_115 . V_66 ) ;
if ( V_3 -> V_65 . V_54 ) {
if ( ! F_102 ( V_3 , & V_3 -> V_65 ,
V_145 ) )
V_503 |= V_504 | V_505 ;
}
F_42 ( & V_7 -> V_115 . V_66 ) ;
F_41 ( & V_7 -> V_506 . V_66 ) ;
if ( V_3 -> V_61 . V_54 ) {
if ( F_37 ( V_3 , & V_3 -> V_61 , V_151 ) )
V_503 |= V_507 | V_508 ;
}
F_42 ( & V_7 -> V_506 . V_66 ) ;
return V_503 ;
}
static void F_279 ( struct V_509 * V_510 )
{
struct V_501 * V_501 = V_510 -> V_511 ;
struct V_225 * V_6 = V_501 -> V_512 ;
struct V_6 * V_7 = V_6 -> V_7 ;
if ( V_7 )
F_94 ( & F_12 ( V_7 ) -> V_513 ) ;
}
static void F_280 ( struct V_509 * V_510 )
{
struct V_501 * V_501 = V_510 -> V_511 ;
struct V_225 * V_6 = V_501 -> V_512 ;
struct V_6 * V_7 = V_6 -> V_7 ;
if ( V_7 )
F_84 ( & F_12 ( V_7 ) -> V_513 ) ;
}
static void F_281 ( struct V_91 * V_54 , unsigned int V_514 ,
unsigned int V_154 )
{
int V_176 ;
for ( V_176 = 0 ; V_176 < V_154 ; V_176 ++ ) {
if ( F_4 ( V_54 [ V_176 ] . V_55 ) ) {
if ( F_282 ( V_54 [ V_176 ] . V_55 ) )
F_283 ( V_54 [ V_176 ] . V_55 ) ;
else
F_284 ( ( unsigned long ) V_54 [ V_176 ] . V_55 ,
V_514 ) ;
V_54 [ V_176 ] . V_55 = NULL ;
}
}
F_147 ( V_54 ) ;
}
static char * F_285 ( unsigned long V_514 )
{
char * V_55 = NULL ;
T_9 V_515 = V_203 | V_516 |
V_517 | V_518 | V_519 ;
V_55 = ( char * ) F_286 ( V_515 , V_514 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_287 ( ( 1 << V_514 ) * V_125 ) ;
if ( V_55 )
return V_55 ;
V_515 &= ~ V_519 ;
V_55 = ( char * ) F_286 ( V_515 , V_514 ) ;
if ( V_55 )
return V_55 ;
return NULL ;
}
static struct V_91 * F_288 ( struct V_520 * V_448 , int V_514 )
{
unsigned int V_521 = V_448 -> V_100 ;
struct V_91 * V_54 ;
int V_176 ;
V_54 = F_289 ( V_521 , sizeof( struct V_91 ) , V_203 ) ;
if ( F_51 ( ! V_54 ) )
goto V_116;
for ( V_176 = 0 ; V_176 < V_521 ; V_176 ++ ) {
V_54 [ V_176 ] . V_55 = F_285 ( V_514 ) ;
if ( F_51 ( ! V_54 [ V_176 ] . V_55 ) )
goto V_522;
}
V_116:
return V_54 ;
V_522:
F_281 ( V_54 , V_514 , V_521 ) ;
V_54 = NULL ;
goto V_116;
}
static int F_219 ( struct V_6 * V_7 , union V_86 * V_87 ,
int V_523 , int V_61 )
{
struct V_91 * V_54 = NULL ;
struct V_2 * V_3 = F_12 ( V_7 ) ;
int V_524 , V_514 = 0 ;
struct V_48 * V_49 ;
struct V_62 * V_63 ;
T_6 V_169 ;
int V_79 = - V_199 ;
struct V_520 * V_448 = & V_87 -> V_448 ;
if ( ! V_523 && V_61 && ( V_3 -> V_18 > V_22 ) ) {
F_27 ( 1 , L_7 ) ;
goto V_116;
}
V_49 = V_61 ? & V_3 -> V_61 : & V_3 -> V_65 ;
V_63 = V_61 ? & V_7 -> V_506 : & V_7 -> V_115 ;
V_79 = - V_452 ;
if ( ! V_523 ) {
if ( F_64 ( & V_3 -> V_513 ) )
goto V_116;
if ( F_64 ( & V_49 -> V_317 ) )
goto V_116;
}
if ( V_448 -> V_100 ) {
V_79 = - V_452 ;
if ( F_51 ( V_49 -> V_54 ) )
goto V_116;
switch ( V_3 -> V_18 ) {
case V_19 :
V_3 -> V_102 = V_525 ;
break;
case V_22 :
V_3 -> V_102 = V_526 ;
break;
case V_24 :
V_3 -> V_102 = V_527 ;
break;
}
V_79 = - V_199 ;
if ( F_51 ( ( int ) V_448 -> V_98 <= 0 ) )
goto V_116;
if ( F_51 ( V_448 -> V_98 & ( V_125 - 1 ) ) )
goto V_116;
if ( F_51 ( V_448 -> V_528 < V_3 -> V_102 +
V_3 -> V_304 ) )
goto V_116;
if ( F_51 ( V_448 -> V_528 & ( V_529 - 1 ) ) )
goto V_116;
V_49 -> V_53 = V_448 -> V_98 / V_448 -> V_528 ;
if ( F_51 ( V_49 -> V_53 <= 0 ) )
goto V_116;
if ( F_51 ( ( V_49 -> V_53 * V_448 -> V_100 ) !=
V_448 -> V_530 ) )
goto V_116;
V_79 = - V_202 ;
V_514 = F_290 ( V_448 -> V_98 ) ;
V_54 = F_288 ( V_448 , V_514 ) ;
if ( F_51 ( ! V_54 ) )
goto V_116;
switch ( V_3 -> V_18 ) {
case V_24 :
if ( ! V_61 )
F_56 ( V_3 , V_49 , V_54 , V_87 , V_61 ) ;
break;
default:
break;
}
}
else {
V_79 = - V_199 ;
if ( F_51 ( V_448 -> V_530 ) )
goto V_116;
}
F_224 ( V_7 ) ;
F_22 ( & V_3 -> V_12 ) ;
V_524 = V_3 -> V_8 ;
V_169 = V_3 -> V_169 ;
if ( V_524 ) {
V_3 -> V_169 = 0 ;
F_16 ( V_7 , false ) ;
}
F_20 ( & V_3 -> V_12 ) ;
F_21 () ;
V_79 = - V_452 ;
F_134 ( & V_3 -> V_336 ) ;
if ( V_523 || F_64 ( & V_3 -> V_513 ) == 0 ) {
V_79 = 0 ;
F_41 ( & V_63 -> V_66 ) ;
F_291 ( V_49 -> V_54 , V_54 ) ;
V_49 -> V_157 = ( V_448 -> V_530 - 1 ) ;
V_49 -> V_57 = 0 ;
V_49 -> V_56 = V_448 -> V_528 ;
F_42 ( & V_63 -> V_66 ) ;
F_291 ( V_49 -> V_531 , V_514 ) ;
F_291 ( V_49 -> V_532 , V_448 -> V_100 ) ;
V_49 -> V_533 = V_448 -> V_98 / V_125 ;
V_3 -> V_10 . F_44 = ( V_3 -> V_65 . V_54 ) ?
V_160 : F_175 ;
F_108 ( V_63 ) ;
if ( F_64 ( & V_3 -> V_513 ) )
F_111 ( L_8 ,
F_64 ( & V_3 -> V_513 ) ) ;
}
F_142 ( & V_3 -> V_336 ) ;
F_22 ( & V_3 -> V_12 ) ;
if ( V_524 ) {
V_3 -> V_169 = V_169 ;
F_11 ( V_7 ) ;
}
F_20 ( & V_3 -> V_12 ) ;
if ( V_523 && ( V_3 -> V_18 > V_22 ) ) {
if ( ! V_61 )
F_40 ( V_3 , V_61 , V_63 ) ;
}
F_225 ( V_7 ) ;
if ( V_54 )
F_281 ( V_54 , V_514 , V_448 -> V_100 ) ;
V_116:
return V_79 ;
}
static int F_292 ( struct V_501 * V_501 , struct V_225 * V_6 ,
struct V_509 * V_510 )
{
struct V_6 * V_7 = V_6 -> V_7 ;
struct V_2 * V_3 = F_12 ( V_7 ) ;
unsigned long V_534 , V_535 ;
struct V_48 * V_49 ;
unsigned long V_123 ;
int V_79 = - V_199 ;
int V_176 ;
if ( V_510 -> V_536 )
return - V_199 ;
F_134 ( & V_3 -> V_336 ) ;
V_535 = 0 ;
for ( V_49 = & V_3 -> V_65 ; V_49 <= & V_3 -> V_61 ; V_49 ++ ) {
if ( V_49 -> V_54 ) {
V_535 += V_49 -> V_532
* V_49 -> V_533
* V_125 ;
}
}
if ( V_535 == 0 )
goto V_116;
V_534 = V_510 -> V_537 - V_510 -> V_538 ;
if ( V_534 != V_535 )
goto V_116;
V_123 = V_510 -> V_538 ;
for ( V_49 = & V_3 -> V_65 ; V_49 <= & V_3 -> V_61 ; V_49 ++ ) {
if ( V_49 -> V_54 == NULL )
continue;
for ( V_176 = 0 ; V_176 < V_49 -> V_532 ; V_176 ++ ) {
struct V_326 * V_326 ;
void * V_539 = V_49 -> V_54 [ V_176 ] . V_55 ;
int V_540 ;
for ( V_540 = 0 ; V_540 < V_49 -> V_533 ; V_540 ++ ) {
V_326 = F_26 ( V_539 ) ;
V_79 = F_293 ( V_510 , V_123 , V_326 ) ;
if ( F_51 ( V_79 ) )
goto V_116;
V_123 += V_125 ;
V_539 += V_125 ;
}
}
}
F_94 ( & V_3 -> V_513 ) ;
V_510 -> V_541 = & V_542 ;
V_79 = 0 ;
V_116:
F_142 ( & V_3 -> V_336 ) ;
return V_79 ;
}
static void * F_294 ( struct V_543 * V_544 , T_10 * V_545 )
__acquires( T_11 )
{
struct V_186 * V_186 = F_295 ( V_544 ) ;
F_2 () ;
return F_296 ( & V_186 -> V_372 . V_396 , * V_545 ) ;
}
static void * F_297 ( struct V_543 * V_544 , void * V_546 , T_10 * V_545 )
{
struct V_186 * V_186 = F_295 ( V_544 ) ;
return F_298 ( V_546 , & V_186 -> V_372 . V_396 , V_545 ) ;
}
static void F_299 ( struct V_543 * V_544 , void * V_546 )
__releases( T_11 )
{
F_6 () ;
}
static int F_300 ( struct V_543 * V_544 , void * V_546 )
{
if ( V_546 == V_547 )
F_301 ( V_544 , L_9 ) ;
else {
struct V_6 * V_548 = F_302 ( V_546 ) ;
const struct V_2 * V_3 = F_12 ( V_548 ) ;
F_303 ( V_544 ,
L_10 ,
V_548 ,
F_64 ( & V_548 -> V_549 ) ,
V_548 -> V_274 ,
F_193 ( V_3 -> V_169 ) ,
V_3 -> V_81 ,
V_3 -> V_8 ,
F_64 ( & V_548 -> V_161 ) ,
F_304 ( F_305 ( V_544 ) , F_306 ( V_548 ) ) ,
F_307 ( V_548 ) ) ;
}
return 0 ;
}
static int F_308 ( struct V_550 * V_550 , struct V_501 * V_501 )
{
return F_309 ( V_550 , V_501 , & V_551 ,
sizeof( struct V_552 ) ) ;
}
static int T_12 F_310 ( struct V_186 * V_186 )
{
F_234 ( & V_186 -> V_372 . V_373 ) ;
F_311 ( & V_186 -> V_372 . V_396 ) ;
if ( ! F_312 ( L_11 , 0 , V_186 -> V_553 , & V_554 ) )
return - V_202 ;
return 0 ;
}
static void T_13 F_313 ( struct V_186 * V_186 )
{
F_314 ( L_11 , V_186 -> V_553 ) ;
}
static void T_14 F_315 ( void )
{
F_316 ( & V_555 ) ;
F_317 ( & V_556 ) ;
F_318 ( V_389 ) ;
F_319 ( & V_390 ) ;
}
static int T_15 F_320 ( void )
{
int V_557 = F_321 ( & V_390 , 0 ) ;
if ( V_557 != 0 )
goto V_116;
F_322 ( & V_558 ) ;
F_323 ( & V_556 ) ;
F_324 ( & V_555 ) ;
V_116:
return V_557 ;
}
