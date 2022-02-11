static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 ) {
if ( V_4 -> V_6 )
F_3 ( V_2 , V_4 ) ;
else
F_4 ( & V_4 -> V_7 ) ;
F_5 ( V_2 ) ;
V_4 -> V_5 = 1 ;
}
}
static void F_6 ( struct V_1 * V_2 , bool V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = 0 ;
if ( V_4 -> V_6 )
F_7 ( V_2 , V_4 ) ;
else
F_8 ( & V_4 -> V_7 ) ;
F_9 ( V_2 ) ;
if ( V_8 ) {
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
F_12 ( & V_4 -> V_9 ) ;
}
}
static void F_13 ( struct V_1 * V_2 , bool V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_6 ( V_2 , V_8 ) ;
}
void F_14 ( struct V_3 * V_4 , void * V_10 , int V_11 )
{
union V_12 V_13 ;
V_13 . V_14 = V_10 ;
switch ( V_4 -> V_15 ) {
case V_16 :
V_13 . V_17 -> V_18 = V_11 ;
F_15 ( F_16 ( & V_13 . V_17 -> V_18 ) ) ;
break;
case V_19 :
V_13 . V_20 -> V_18 = V_11 ;
F_15 ( F_16 ( & V_13 . V_20 -> V_18 ) ) ;
break;
case V_21 :
default:
F_17 ( 1 , L_1 ) ;
F_18 () ;
}
F_19 () ;
}
static int F_20 ( struct V_3 * V_4 , void * V_10 )
{
union V_12 V_13 ;
F_21 () ;
V_13 . V_14 = V_10 ;
switch ( V_4 -> V_15 ) {
case V_16 :
F_15 ( F_16 ( & V_13 . V_17 -> V_18 ) ) ;
return V_13 . V_17 -> V_18 ;
case V_19 :
F_15 ( F_16 ( & V_13 . V_20 -> V_18 ) ) ;
return V_13 . V_20 -> V_18 ;
case V_21 :
default:
F_17 ( 1 , L_1 ) ;
F_18 () ;
return 0 ;
}
}
static T_1 F_22 ( struct V_22 * V_23 , struct V_24 * V_25 ,
unsigned int V_26 )
{
struct V_27 * V_28 = F_23 ( V_23 ) ;
if ( V_28 ) {
if ( ( V_26 & V_29 ) &&
F_24 ( V_28 -> V_30 , V_25 ) )
return V_31 ;
if ( ( V_26 & V_32 ) &&
F_24 ( V_28 -> V_33 , V_25 ) )
return V_34 ;
}
if ( F_24 ( V_23 -> V_35 , V_25 ) )
return V_36 ;
return 0 ;
}
static T_1 F_25 ( struct V_3 * V_4 , void * V_10 ,
struct V_22 * V_23 )
{
union V_12 V_13 ;
struct V_24 V_25 ;
T_1 V_37 ;
if ( ! ( V_37 = F_22 ( V_23 , & V_25 , V_4 -> V_38 ) ) )
return 0 ;
V_13 . V_14 = V_10 ;
switch ( V_4 -> V_15 ) {
case V_16 :
V_13 . V_17 -> V_39 = V_25 . V_40 ;
V_13 . V_17 -> V_41 = V_25 . V_42 / V_43 ;
break;
case V_19 :
V_13 . V_20 -> V_39 = V_25 . V_40 ;
V_13 . V_20 -> V_44 = V_25 . V_42 ;
break;
case V_21 :
default:
F_17 ( 1 , L_1 ) ;
F_18 () ;
}
F_15 ( F_16 ( & V_13 . V_17 -> V_39 ) ) ;
F_19 () ;
return V_37 ;
}
static void * F_26 ( struct V_3 * V_4 ,
struct V_45 * V_46 ,
unsigned int V_47 ,
int V_11 )
{
unsigned int V_48 , V_49 ;
union V_12 V_13 ;
V_48 = V_47 / V_46 -> V_50 ;
V_49 = V_47 % V_46 -> V_50 ;
V_13 . V_14 = V_46 -> V_51 [ V_48 ] . V_52 +
( V_49 * V_46 -> V_53 ) ;
if ( V_11 != F_20 ( V_4 , V_13 . V_14 ) )
return NULL ;
return V_13 . V_14 ;
}
static void * F_27 ( struct V_3 * V_4 ,
struct V_45 * V_46 ,
int V_11 )
{
return F_26 ( V_4 , V_46 , V_46 -> V_54 , V_11 ) ;
}
static void F_28 ( struct V_55 * V_56 )
{
F_29 ( & V_56 -> V_57 ) ;
}
static void F_30 ( struct V_3 * V_4 ,
int V_58 ,
struct V_59 * V_60 )
{
struct V_55 * V_56 ;
V_56 = V_58 ? & V_4 -> V_58 . V_61 : & V_4 -> V_62 . V_61 ;
F_12 ( & V_60 -> V_63 ) ;
V_56 -> V_64 = 1 ;
F_10 ( & V_60 -> V_63 ) ;
F_28 ( V_56 ) ;
}
static void F_31 ( struct V_3 * V_4 ,
struct V_55 * V_56 ,
void (* F_32) ( unsigned long ) )
{
F_33 ( & V_56 -> V_57 ) ;
V_56 -> V_57 . V_65 = ( long ) V_4 ;
V_56 -> V_57 . V_66 = F_32 ;
V_56 -> V_57 . V_67 = V_68 ;
}
static void F_34 ( struct V_3 * V_4 , int V_58 )
{
struct V_55 * V_56 ;
if ( V_58 )
F_18 () ;
V_56 = V_58 ? & V_4 -> V_58 . V_61 : & V_4 -> V_62 . V_61 ;
F_31 ( V_4 , V_56 , V_69 ) ;
}
static int F_35 ( struct V_3 * V_4 ,
int V_70 )
{
struct V_71 * V_72 ;
unsigned int V_73 = 0 , V_74 = 0 , div = 0 , V_75 = 0 ;
struct V_76 V_77 ;
int V_78 ;
T_2 V_79 ;
F_36 () ;
V_72 = F_37 ( F_38 ( & V_4 -> V_2 ) , V_4 -> V_80 ) ;
if ( F_39 ( ! V_72 ) ) {
F_40 () ;
return V_81 ;
}
V_78 = F_41 ( V_72 , & V_77 ) ;
V_79 = F_42 ( & V_77 ) ;
F_40 () ;
if ( ! V_78 ) {
if ( V_79 < V_82 || V_79 == V_83 ) {
return V_81 ;
} else {
V_74 = 1 ;
div = V_79 / 1000 ;
}
}
V_73 = ( V_70 * 8 ) / ( 1024 * 1024 ) ;
if ( div )
V_73 /= div ;
V_75 = V_73 * V_74 ;
if ( div )
return V_75 + 1 ;
return V_75 ;
}
static void F_43 ( struct V_55 * V_84 ,
union V_85 * V_86 )
{
V_84 -> V_87 = V_86 -> V_88 . V_89 ;
}
static void F_44 ( struct V_3 * V_4 ,
struct V_45 * V_46 ,
struct V_90 * V_51 ,
union V_85 * V_86 , int V_58 )
{
struct V_55 * V_84 = & V_46 -> V_61 ;
struct V_91 * V_92 ;
memset ( V_84 , 0x0 , sizeof( * V_84 ) ) ;
V_84 -> V_93 = 1 ;
V_84 -> V_94 = V_51 ;
V_92 = (struct V_91 * ) V_51 [ 0 ] . V_52 ;
V_84 -> V_95 = V_51 [ 0 ] . V_52 ;
V_84 -> V_96 = V_86 -> V_88 . V_97 ;
V_84 -> V_98 = V_86 -> V_88 . V_99 ;
V_84 -> V_100 = V_4 -> V_101 ;
V_84 -> V_102 = V_4 -> V_15 ;
V_84 -> V_103 = 0 ;
V_4 -> V_104 . V_105 . V_106 = 0 ;
if ( V_86 -> V_88 . V_107 )
V_84 -> V_108 = V_86 -> V_88 . V_107 ;
else
V_84 -> V_108 = F_35 ( V_4 ,
V_86 -> V_88 . V_97 ) ;
V_84 -> V_109 = F_45 ( V_84 -> V_108 ) ;
V_84 -> V_110 = V_86 -> V_88 . V_111 ;
F_43 ( V_84 , V_86 ) ;
F_34 ( V_4 , V_58 ) ;
F_46 ( V_84 , V_92 ) ;
}
static void F_47 ( struct V_55 * V_56 )
{
F_48 ( & V_56 -> V_57 ,
V_68 + V_56 -> V_109 ) ;
V_56 -> V_103 = V_56 -> V_112 ;
}
static void V_69 ( unsigned long V_65 )
{
struct V_3 * V_4 = (struct V_3 * ) V_65 ;
struct V_55 * V_56 = & V_4 -> V_62 . V_61 ;
unsigned int V_113 ;
struct V_91 * V_92 ;
F_12 ( & V_4 -> V_2 . V_114 . V_63 ) ;
V_113 = F_49 ( V_56 ) ;
V_92 = F_50 ( V_56 ) ;
if ( F_39 ( V_56 -> V_64 ) )
goto V_115;
if ( F_51 ( V_92 ) ) {
while ( F_52 ( & V_56 -> V_116 ) ) {
F_53 () ;
}
}
if ( V_56 -> V_103 == V_56 -> V_112 ) {
if ( ! V_113 ) {
F_54 ( V_56 , V_4 , V_117 ) ;
if ( ! F_55 ( V_56 , V_4 ) )
goto V_118;
else
goto V_115;
} else {
if ( F_56 ( V_56 , V_92 ) ) {
goto V_118;
} else {
F_46 ( V_56 , V_92 ) ;
goto V_115;
}
}
}
V_118:
F_47 ( V_56 ) ;
V_115:
F_10 ( & V_4 -> V_2 . V_114 . V_63 ) ;
}
static void F_57 ( struct V_55 * V_119 ,
struct V_91 * V_120 , T_1 V_11 )
{
#if V_121 == 1
T_3 * V_122 , * V_123 ;
V_122 = ( T_3 * ) V_120 ;
V_122 += V_124 ;
V_123 = ( T_3 * ) F_58 ( ( unsigned long ) V_119 -> V_125 ) ;
for (; V_122 < V_123 ; V_122 += V_124 )
F_15 ( F_16 ( V_122 ) ) ;
F_19 () ;
#endif
F_59 ( V_120 ) = V_11 ;
#if V_121 == 1
V_122 = ( T_3 * ) V_120 ;
F_15 ( F_16 ( V_122 ) ) ;
F_19 () ;
#endif
}
static void F_60 ( struct V_55 * V_119 ,
struct V_91 * V_120 ,
struct V_3 * V_4 , unsigned int V_126 )
{
T_1 V_11 = V_127 | V_126 ;
struct V_128 * V_129 ;
struct V_130 * V_17 = & V_120 -> V_131 . V_132 ;
if ( V_4 -> V_104 . V_105 . V_133 )
V_11 |= V_134 ;
V_129 = (struct V_128 * ) V_119 -> V_135 ;
V_129 -> V_136 = 0 ;
if ( F_51 ( V_120 ) ) {
V_17 -> V_137 . V_138 = V_129 -> V_39 ;
V_17 -> V_137 . V_139 = V_129 -> V_44 ;
} else {
struct V_24 V_25 ;
F_61 ( & V_25 ) ;
V_17 -> V_137 . V_138 = V_25 . V_40 ;
V_17 -> V_137 . V_139 = V_25 . V_42 ;
}
F_19 () ;
F_57 ( V_119 , V_120 , V_11 ) ;
V_119 -> V_112 = F_62 ( V_119 ) ;
}
static void F_63 ( struct V_55 * V_56 )
{
V_56 -> V_140 = 0 ;
}
static void F_46 ( struct V_55 * V_119 ,
struct V_91 * V_120 )
{
struct V_24 V_25 ;
struct V_130 * V_17 = & V_120 -> V_131 . V_132 ;
F_21 () ;
F_64 ( V_120 ) = V_119 -> V_93 ++ ;
F_51 ( V_120 ) = 0 ;
F_65 ( V_120 ) = F_66 ( V_119 -> V_110 ) ;
F_61 ( & V_25 ) ;
V_17 -> V_141 . V_138 = V_25 . V_40 ;
V_17 -> V_141 . V_139 = V_25 . V_42 ;
V_119 -> V_95 = ( char * ) V_120 ;
V_119 -> V_142 = V_119 -> V_95 + F_66 ( V_119 -> V_110 ) ;
F_67 ( V_120 ) = ( T_1 ) F_66 ( V_119 -> V_110 ) ;
F_68 ( V_120 ) = V_143 ;
V_120 -> V_102 = V_119 -> V_102 ;
V_119 -> V_135 = V_119 -> V_142 ;
V_119 -> V_125 = V_119 -> V_95 + V_119 -> V_96 ;
F_63 ( V_119 ) ;
F_47 ( V_119 ) ;
F_19 () ;
}
static void F_69 ( struct V_55 * V_56 ,
struct V_3 * V_4 )
{
V_56 -> V_140 = 1 ;
V_4 -> V_104 . V_105 . V_106 ++ ;
}
static void * F_55 ( struct V_55 * V_56 ,
struct V_3 * V_4 )
{
struct V_91 * V_92 ;
F_21 () ;
V_92 = F_50 ( V_56 ) ;
if ( V_127 & F_59 ( V_92 ) ) {
F_69 ( V_56 , V_4 ) ;
return NULL ;
}
F_46 ( V_56 , V_92 ) ;
return ( void * ) V_56 -> V_142 ;
}
static void F_54 ( struct V_55 * V_56 ,
struct V_3 * V_4 , unsigned int V_11 )
{
struct V_91 * V_92 = F_50 ( V_56 ) ;
if ( F_70 ( V_144 == F_59 ( V_92 ) ) ) {
if ( ! ( V_11 & V_117 ) ) {
while ( F_52 ( & V_56 -> V_116 ) ) {
F_53 () ;
}
}
F_60 ( V_56 , V_92 , V_4 , V_11 ) ;
return;
}
}
static int F_56 ( struct V_55 * V_56 ,
struct V_91 * V_92 )
{
return V_127 & F_59 ( V_92 ) ;
}
static int F_49 ( struct V_55 * V_56 )
{
return V_56 -> V_140 ;
}
static void F_71 ( struct V_45 * V_46 )
{
struct V_55 * V_56 = F_72 ( V_46 ) ;
F_73 ( & V_56 -> V_116 ) ;
}
static void F_74 ( struct V_55 * V_56 ,
struct V_128 * V_145 )
{
V_145 -> V_146 . V_147 = F_75 ( V_56 -> V_23 ) ;
}
static void F_76 ( struct V_55 * V_56 ,
struct V_128 * V_145 )
{
V_145 -> V_146 . V_147 = 0 ;
}
static void F_77 ( struct V_55 * V_56 ,
struct V_128 * V_145 )
{
if ( F_78 ( V_56 -> V_23 ) ) {
V_145 -> V_146 . V_148 = F_79 ( V_56 -> V_23 ) ;
V_145 -> V_18 = V_149 ;
} else {
V_145 -> V_146 . V_148 = 0 ;
V_145 -> V_18 = V_150 ;
}
}
static void F_80 ( struct V_55 * V_56 ,
struct V_128 * V_145 )
{
F_77 ( V_56 , V_145 ) ;
if ( V_56 -> V_87 & V_151 )
F_74 ( V_56 , V_145 ) ;
else
F_76 ( V_56 , V_145 ) ;
}
static void F_81 ( char * V_152 ,
struct V_55 * V_56 ,
struct V_91 * V_92 ,
unsigned int V_153 )
{
struct V_128 * V_145 ;
V_145 = (struct V_128 * ) V_152 ;
V_145 -> V_136 = F_82 ( V_153 ) ;
V_56 -> V_135 = V_152 ;
V_56 -> V_142 += F_82 ( V_153 ) ;
F_65 ( V_92 ) += F_82 ( V_153 ) ;
F_51 ( V_92 ) += 1 ;
F_83 ( & V_56 -> V_116 ) ;
F_80 ( V_56 , V_145 ) ;
}
static void * F_84 ( struct V_3 * V_4 ,
struct V_22 * V_23 ,
int V_11 ,
unsigned int V_153
)
{
struct V_55 * V_56 ;
struct V_91 * V_92 ;
char * V_152 , * V_123 ;
V_56 = F_72 ( & V_4 -> V_62 ) ;
V_92 = F_50 ( V_56 ) ;
if ( F_49 ( V_56 ) ) {
if ( F_56 ( V_56 , V_92 ) ) {
return NULL ;
} else {
F_46 ( V_56 , V_92 ) ;
}
}
F_85 () ;
V_152 = V_56 -> V_142 ;
V_56 -> V_23 = V_23 ;
V_123 = ( char * ) V_92 + V_56 -> V_96 ;
if ( V_152 + F_82 ( V_153 ) < V_123 ) {
F_81 ( V_152 , V_56 , V_92 , V_153 ) ;
return ( void * ) V_152 ;
}
F_54 ( V_56 , V_4 , 0 ) ;
V_152 = ( char * ) F_55 ( V_56 , V_4 ) ;
if ( V_152 ) {
V_92 = F_50 ( V_56 ) ;
F_81 ( V_152 , V_56 , V_92 , V_153 ) ;
return ( void * ) V_152 ;
}
return NULL ;
}
static void * F_86 ( struct V_3 * V_4 ,
struct V_22 * V_23 ,
int V_11 , unsigned int V_153 )
{
char * V_152 = NULL ;
switch ( V_4 -> V_15 ) {
case V_16 :
case V_19 :
V_152 = F_26 ( V_4 , & V_4 -> V_62 ,
V_4 -> V_62 . V_54 , V_11 ) ;
return V_152 ;
case V_21 :
return F_84 ( V_4 , V_23 , V_11 , V_153 ) ;
default:
F_17 ( 1 , L_2 ) ;
F_18 () ;
return NULL ;
}
}
static void * F_87 ( struct V_3 * V_4 ,
struct V_45 * V_46 ,
unsigned int V_154 ,
int V_11 )
{
struct V_55 * V_56 = F_72 ( V_46 ) ;
struct V_91 * V_92 = F_88 ( V_56 , V_154 ) ;
if ( V_11 != F_59 ( V_92 ) )
return NULL ;
return V_92 ;
}
static int F_89 ( struct V_45 * V_46 )
{
unsigned int V_135 ;
if ( V_46 -> V_61 . V_112 )
V_135 = V_46 -> V_61 . V_112 - 1 ;
else
V_135 = V_46 -> V_61 . V_98 - 1 ;
return V_135 ;
}
static void * F_90 ( struct V_3 * V_4 ,
struct V_45 * V_46 ,
int V_11 )
{
unsigned int V_155 = F_89 ( V_46 ) ;
return F_87 ( V_4 , V_46 , V_155 , V_11 ) ;
}
static void * F_91 ( struct V_3 * V_4 ,
struct V_45 * V_46 ,
int V_11 )
{
if ( V_4 -> V_15 <= V_19 )
return F_92 ( V_4 , V_46 , V_11 ) ;
return F_90 ( V_4 , V_46 , V_11 ) ;
}
static void F_93 ( struct V_3 * V_4 ,
struct V_45 * V_46 )
{
switch ( V_4 -> V_15 ) {
case V_16 :
case V_19 :
return F_94 ( V_46 ) ;
case V_21 :
default:
F_17 ( 1 , L_1 ) ;
F_18 () ;
return;
}
}
static void * F_92 ( struct V_3 * V_4 ,
struct V_45 * V_46 ,
int V_11 )
{
unsigned int V_155 = V_46 -> V_54 ? V_46 -> V_54 - 1 : V_46 -> V_156 ;
return F_26 ( V_4 , V_46 , V_155 , V_11 ) ;
}
static void F_94 ( struct V_45 * V_157 )
{
V_157 -> V_54 = V_157 -> V_54 != V_157 -> V_156 ? V_157 -> V_54 + 1 : 0 ;
}
static bool F_95 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
bool V_158 ;
if ( V_4 -> V_7 . F_32 != V_159 )
return ( F_52 ( & V_2 -> V_160 ) + V_23 -> V_161 )
<= V_2 -> V_162 ;
F_12 ( & V_2 -> V_114 . V_63 ) ;
if ( V_4 -> V_15 == V_21 )
V_158 = F_87 ( V_4 , & V_4 -> V_62 ,
V_4 -> V_62 . V_61 . V_112 ,
V_144 ) ;
else
V_158 = F_26 ( V_4 , & V_4 -> V_62 ,
V_4 -> V_62 . V_54 ,
V_144 ) ;
F_10 ( & V_2 -> V_114 . V_63 ) ;
return V_158 ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_97 ( & V_2 -> V_163 ) ;
F_98 ( F_52 ( & V_2 -> V_160 ) ) ;
F_98 ( F_52 ( & V_2 -> V_164 ) ) ;
if ( ! F_99 ( V_2 , V_165 ) ) {
F_100 ( L_3 , V_2 ) ;
return;
}
F_101 ( V_2 ) ;
}
static int F_102 ( struct V_166 * V_167 , unsigned int V_168 )
{
int V_169 = F_52 ( & V_167 -> V_170 ) + 1 ;
if ( V_169 >= V_168 )
V_169 = 0 ;
return V_169 ;
}
static unsigned int F_103 ( struct V_166 * V_167 ,
struct V_22 * V_23 ,
unsigned int V_168 )
{
return ( ( ( V_171 ) V_23 -> V_172 ) * V_168 ) >> 32 ;
}
static unsigned int F_104 ( struct V_166 * V_167 ,
struct V_22 * V_23 ,
unsigned int V_168 )
{
int V_173 , V_174 ;
V_173 = F_52 ( & V_167 -> V_170 ) ;
while ( ( V_174 = F_105 ( & V_167 -> V_170 , V_173 ,
F_102 ( V_167 , V_168 ) ) ) != V_173 )
V_173 = V_174 ;
return V_173 ;
}
static unsigned int F_106 ( struct V_166 * V_167 ,
struct V_22 * V_23 ,
unsigned int V_168 )
{
return F_107 () % V_168 ;
}
static unsigned int F_108 ( struct V_166 * V_167 ,
struct V_22 * V_23 ,
unsigned int V_154 , unsigned int V_175 ,
unsigned int V_168 )
{
unsigned int V_176 , V_177 ;
V_176 = V_177 = F_109 ( int , V_167 -> V_178 [ V_154 ] , V_168 - 1 ) ;
do {
if ( V_176 != V_175 && F_95 ( F_2 ( V_167 -> V_179 [ V_176 ] ) , V_23 ) ) {
if ( V_176 != V_177 )
V_167 -> V_178 [ V_154 ] = V_176 ;
return V_176 ;
}
if ( ++ V_176 == V_168 )
V_176 = 0 ;
} while ( V_176 != V_177 );
return V_154 ;
}
static bool F_110 ( struct V_166 * V_167 , T_4 V_180 )
{
return V_167 -> V_26 & ( V_180 >> 8 ) ;
}
static int F_111 ( struct V_22 * V_23 , struct V_71 * V_72 ,
struct V_181 * V_182 , struct V_71 * V_183 )
{
struct V_166 * V_167 = V_182 -> V_184 ;
unsigned int V_168 = V_167 -> V_185 ;
struct V_3 * V_4 ;
unsigned int V_154 ;
if ( ! F_112 ( F_113 ( V_72 ) , F_114 ( & V_167 -> V_186 ) ) ||
! V_168 ) {
F_115 ( V_23 ) ;
return 0 ;
}
switch ( V_167 -> type ) {
case V_187 :
default:
if ( F_110 ( V_167 , V_188 ) ) {
V_23 = F_116 ( V_23 , V_189 ) ;
if ( ! V_23 )
return 0 ;
}
F_75 ( V_23 ) ;
V_154 = F_103 ( V_167 , V_23 , V_168 ) ;
break;
case V_190 :
V_154 = F_104 ( V_167 , V_23 , V_168 ) ;
break;
case V_191 :
V_154 = F_106 ( V_167 , V_23 , V_168 ) ;
break;
case V_192 :
V_154 = F_108 ( V_167 , V_23 , 0 , ( unsigned int ) - 1 , V_168 ) ;
break;
}
V_4 = F_2 ( V_167 -> V_179 [ V_154 ] ) ;
if ( F_110 ( V_167 , V_193 ) &&
F_39 ( ! F_95 ( V_4 , V_23 ) ) ) {
V_154 = F_108 ( V_167 , V_23 , V_154 , V_154 , V_168 ) ;
V_4 = F_2 ( V_167 -> V_179 [ V_154 ] ) ;
}
return V_4 -> V_7 . F_32 ( V_23 , V_72 , & V_4 -> V_7 , V_183 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_166 * V_167 = V_4 -> V_6 ;
F_12 ( & V_167 -> V_63 ) ;
V_167 -> V_179 [ V_167 -> V_185 ] = V_2 ;
F_19 () ;
V_167 -> V_185 ++ ;
F_10 ( & V_167 -> V_63 ) ;
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_166 * V_167 = V_4 -> V_6 ;
int V_176 ;
F_12 ( & V_167 -> V_63 ) ;
for ( V_176 = 0 ; V_176 < V_167 -> V_185 ; V_176 ++ ) {
if ( V_167 -> V_179 [ V_176 ] == V_2 )
break;
}
F_117 ( V_176 >= V_167 -> V_185 ) ;
V_167 -> V_179 [ V_176 ] = V_167 -> V_179 [ V_167 -> V_185 - 1 ] ;
V_167 -> V_185 -- ;
F_10 ( & V_167 -> V_63 ) ;
}
static bool F_118 ( struct V_181 * V_194 , struct V_1 * V_2 )
{
if ( V_194 -> V_184 == ( void * ) ( (struct V_3 * ) V_2 ) -> V_6 )
return true ;
return false ;
}
static int F_119 ( struct V_1 * V_2 , T_4 V_195 , T_4 V_196 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_166 * V_167 , * V_197 ;
T_3 type = V_196 & 0xff ;
T_3 V_26 = V_196 >> 8 ;
int V_78 ;
switch ( type ) {
case V_192 :
if ( V_196 & V_193 )
return - V_198 ;
case V_187 :
case V_190 :
case V_191 :
break;
default:
return - V_198 ;
}
if ( ! V_4 -> V_5 )
return - V_198 ;
if ( V_4 -> V_6 )
return - V_199 ;
F_120 ( & V_200 ) ;
V_197 = NULL ;
F_121 (f, &fanout_list, list) {
if ( V_167 -> V_195 == V_195 &&
F_114 ( & V_167 -> V_186 ) == F_38 ( V_2 ) ) {
V_197 = V_167 ;
break;
}
}
V_78 = - V_198 ;
if ( V_197 && V_197 -> V_26 != V_26 )
goto V_115;
if ( ! V_197 ) {
V_78 = - V_201 ;
V_197 = F_122 ( sizeof( * V_197 ) , V_202 ) ;
if ( ! V_197 )
goto V_115;
F_123 ( & V_197 -> V_186 , F_38 ( V_2 ) ) ;
V_197 -> V_195 = V_195 ;
V_197 -> type = type ;
V_197 -> V_26 = V_26 ;
F_124 ( & V_197 -> V_170 , 0 ) ;
F_125 ( & V_197 -> V_203 ) ;
F_126 ( & V_197 -> V_63 ) ;
F_124 ( & V_197 -> V_204 , 0 ) ;
V_197 -> V_7 . type = V_4 -> V_7 . type ;
V_197 -> V_7 . V_72 = V_4 -> V_7 . V_72 ;
V_197 -> V_7 . F_32 = F_111 ;
V_197 -> V_7 . V_184 = V_197 ;
V_197 -> V_7 . V_205 = F_118 ;
F_4 ( & V_197 -> V_7 ) ;
F_127 ( & V_197 -> V_203 , & V_206 ) ;
}
V_78 = - V_198 ;
if ( V_197 -> type == type &&
V_197 -> V_7 . type == V_4 -> V_7 . type &&
V_197 -> V_7 . V_72 == V_4 -> V_7 . V_72 ) {
V_78 = - V_207 ;
if ( F_52 ( & V_197 -> V_204 ) < V_208 ) {
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_6 = V_197 ;
F_83 ( & V_197 -> V_204 ) ;
F_3 ( V_2 , V_4 ) ;
V_78 = 0 ;
}
}
V_115:
F_128 ( & V_200 ) ;
return V_78 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_166 * V_167 ;
V_167 = V_4 -> V_6 ;
if ( ! V_167 )
return;
F_120 ( & V_200 ) ;
V_4 -> V_6 = NULL ;
if ( F_130 ( & V_167 -> V_204 ) ) {
F_131 ( & V_167 -> V_203 ) ;
F_132 ( & V_167 -> V_7 ) ;
F_133 ( V_167 ) ;
}
F_128 ( & V_200 ) ;
}
static int F_134 ( struct V_22 * V_23 , struct V_71 * V_72 ,
struct V_181 * V_182 , struct V_71 * V_183 )
{
struct V_1 * V_2 ;
struct V_209 * V_210 ;
V_2 = V_182 -> V_184 ;
if ( V_23 -> V_211 == V_212 )
goto V_115;
if ( ! F_112 ( F_113 ( V_72 ) , F_38 ( V_2 ) ) )
goto V_115;
V_23 = F_135 ( V_23 , V_213 ) ;
if ( V_23 == NULL )
goto V_214;
F_136 ( V_23 ) ;
F_137 ( V_23 ) ;
V_210 = & F_138 ( V_23 ) -> V_215 . V_216 ;
F_139 ( V_23 , V_23 -> V_65 - F_140 ( V_23 ) ) ;
V_210 -> V_217 = V_72 -> type ;
F_141 ( V_210 -> V_218 , V_72 -> V_219 , sizeof( V_210 -> V_218 ) ) ;
V_210 -> V_220 = V_23 -> V_221 ;
if ( F_142 ( V_2 , V_23 ) == 0 )
return 0 ;
V_115:
F_115 ( V_23 ) ;
V_214:
return 0 ;
}
static int F_143 ( struct V_222 * V_223 , struct V_224 * V_1 ,
struct V_225 * V_226 , T_5 V_153 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_209 * V_227 = (struct V_209 * ) V_226 -> V_228 ;
struct V_22 * V_23 = NULL ;
struct V_71 * V_72 ;
T_6 V_229 = 0 ;
int V_78 ;
int V_230 = 0 ;
if ( V_227 ) {
if ( V_226 -> V_231 < sizeof( struct V_232 ) )
return - V_198 ;
if ( V_226 -> V_231 == sizeof( struct V_209 ) )
V_229 = V_227 -> V_220 ;
} else
return - V_233 ;
V_227 -> V_218 [ sizeof( V_227 -> V_218 ) - 1 ] = 0 ;
V_234:
F_144 () ;
V_72 = F_145 ( F_38 ( V_2 ) , V_227 -> V_218 ) ;
V_78 = - V_235 ;
if ( V_72 == NULL )
goto V_236;
V_78 = - V_237 ;
if ( ! ( V_72 -> V_26 & V_238 ) )
goto V_236;
if ( F_39 ( F_99 ( V_2 , V_239 ) ) ) {
if ( ! F_146 ( V_72 ) ) {
V_78 = - V_240 ;
goto V_236;
}
V_230 = 4 ;
}
V_78 = - V_241 ;
if ( V_153 > V_72 -> V_242 + V_72 -> V_243 + V_244 + V_230 )
goto V_236;
if ( ! V_23 ) {
T_5 V_245 = F_147 ( V_72 ) ;
int V_246 = V_72 -> V_247 ;
unsigned int V_248 = V_72 -> V_249 ? V_72 -> V_243 : 0 ;
F_148 () ;
V_23 = F_149 ( V_2 , V_153 + V_245 + V_246 , 0 , V_202 ) ;
if ( V_23 == NULL )
return - V_250 ;
F_150 ( V_23 , V_245 ) ;
F_151 ( V_23 ) ;
if ( V_248 ) {
V_23 -> V_65 -= V_248 ;
V_23 -> V_251 -= V_248 ;
if ( V_153 < V_248 )
F_151 ( V_23 ) ;
}
V_78 = F_152 ( F_153 ( V_23 , V_153 ) , V_226 -> V_252 , V_153 ) ;
if ( V_78 )
goto V_253;
goto V_234;
}
if ( V_153 > ( V_72 -> V_242 + V_72 -> V_243 + V_230 ) ) {
struct V_254 * V_255 ;
F_154 ( V_23 ) ;
V_255 = F_155 ( V_23 ) ;
if ( V_255 -> V_256 != F_156 ( V_257 ) ) {
V_78 = - V_241 ;
goto V_236;
}
}
V_23 -> V_221 = V_229 ;
V_23 -> V_72 = V_72 ;
V_23 -> V_258 = V_2 -> V_259 ;
V_23 -> V_260 = V_2 -> V_261 ;
F_157 ( V_2 , & F_158 ( V_23 ) -> V_262 ) ;
if ( F_39 ( V_230 == 4 ) )
V_23 -> V_263 = 1 ;
F_159 ( V_23 , 0 ) ;
F_160 ( V_23 ) ;
F_148 () ;
return V_153 ;
V_236:
F_148 () ;
V_253:
F_115 ( V_23 ) ;
return V_78 ;
}
static unsigned int F_161 ( const struct V_22 * V_23 ,
const struct V_1 * V_2 ,
unsigned int V_264 )
{
struct V_265 * V_266 ;
F_144 () ;
V_266 = F_162 ( V_2 -> V_265 ) ;
if ( V_266 != NULL )
V_264 = F_163 ( V_266 , V_23 ) ;
F_148 () ;
return V_264 ;
}
static int F_164 ( struct V_22 * V_23 , struct V_71 * V_72 ,
struct V_181 * V_182 , struct V_71 * V_183 )
{
struct V_1 * V_2 ;
struct V_267 * V_268 ;
struct V_3 * V_4 ;
T_3 * V_269 = V_23 -> V_65 ;
int V_270 = V_23 -> V_153 ;
unsigned int V_271 , V_264 ;
if ( V_23 -> V_211 == V_212 )
goto V_272;
V_2 = V_182 -> V_184 ;
V_4 = F_2 ( V_2 ) ;
if ( ! F_112 ( F_113 ( V_72 ) , F_38 ( V_2 ) ) )
goto V_272;
V_23 -> V_72 = V_72 ;
if ( V_72 -> V_249 ) {
if ( V_2 -> V_273 != V_274 )
F_139 ( V_23 , V_23 -> V_65 - F_140 ( V_23 ) ) ;
else if ( V_23 -> V_211 == V_275 ) {
F_165 ( V_23 , F_166 ( V_23 ) ) ;
}
}
V_271 = V_23 -> V_153 ;
V_264 = F_161 ( V_23 , V_2 , V_271 ) ;
if ( ! V_264 )
goto V_276;
if ( V_271 > V_264 )
V_271 = V_264 ;
if ( F_52 ( & V_2 -> V_160 ) >= V_2 -> V_162 )
goto V_277;
if ( F_167 ( V_23 ) ) {
struct V_22 * V_278 = F_168 ( V_23 , V_213 ) ;
if ( V_278 == NULL )
goto V_277;
if ( V_269 != V_23 -> V_65 ) {
V_23 -> V_65 = V_269 ;
V_23 -> V_153 = V_270 ;
}
F_169 ( V_23 ) ;
V_23 = V_278 ;
}
F_170 ( sizeof( * F_138 ( V_23 ) ) + V_279 - 8 >
sizeof( V_23 -> V_280 ) ) ;
V_268 = & F_138 ( V_23 ) -> V_215 . V_281 ;
V_268 -> V_282 = V_283 ;
V_268 -> V_284 = V_72 -> type ;
V_268 -> V_285 = V_23 -> V_221 ;
V_268 -> V_286 = V_23 -> V_211 ;
if ( F_39 ( V_4 -> V_287 ) )
V_268 -> V_288 = V_183 -> V_80 ;
else
V_268 -> V_288 = V_72 -> V_80 ;
V_268 -> V_289 = F_171 ( V_23 , V_268 -> V_290 ) ;
F_138 ( V_23 ) -> V_291 = V_23 -> V_153 ;
if ( F_172 ( V_23 , V_271 ) )
goto V_277;
F_173 ( V_23 , V_2 ) ;
V_23 -> V_72 = NULL ;
F_136 ( V_23 ) ;
F_137 ( V_23 ) ;
F_12 ( & V_2 -> V_114 . V_63 ) ;
V_4 -> V_104 . V_292 . V_293 ++ ;
V_23 -> V_294 = F_52 ( & V_2 -> V_295 ) ;
F_174 ( & V_2 -> V_114 , V_23 ) ;
F_10 ( & V_2 -> V_114 . V_63 ) ;
V_2 -> V_296 ( V_2 , V_23 -> V_153 ) ;
return 0 ;
V_277:
F_12 ( & V_2 -> V_114 . V_63 ) ;
V_4 -> V_104 . V_292 . V_133 ++ ;
F_83 ( & V_2 -> V_295 ) ;
F_10 ( & V_2 -> V_114 . V_63 ) ;
V_276:
if ( V_269 != V_23 -> V_65 && F_167 ( V_23 ) ) {
V_23 -> V_65 = V_269 ;
V_23 -> V_153 = V_270 ;
}
V_272:
F_169 ( V_23 ) ;
return 0 ;
}
static int V_159 ( struct V_22 * V_23 , struct V_71 * V_72 ,
struct V_181 * V_182 , struct V_71 * V_183 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_267 * V_268 ;
union V_12 V_13 ;
T_3 * V_269 = V_23 -> V_65 ;
int V_270 = V_23 -> V_153 ;
unsigned int V_271 , V_264 ;
unsigned long V_11 = V_127 ;
unsigned short V_297 , V_298 , V_100 ;
struct V_22 * V_299 = NULL ;
struct V_24 V_25 ;
T_1 V_37 ;
if ( V_23 -> V_211 == V_212 )
goto V_272;
V_2 = V_182 -> V_184 ;
V_4 = F_2 ( V_2 ) ;
if ( ! F_112 ( F_113 ( V_72 ) , F_38 ( V_2 ) ) )
goto V_272;
if ( V_72 -> V_249 ) {
if ( V_2 -> V_273 != V_274 )
F_139 ( V_23 , V_23 -> V_65 - F_140 ( V_23 ) ) ;
else if ( V_23 -> V_211 == V_275 ) {
F_165 ( V_23 , F_166 ( V_23 ) ) ;
}
}
if ( V_23 -> V_300 == V_301 )
V_11 |= V_302 ;
V_271 = V_23 -> V_153 ;
V_264 = F_161 ( V_23 , V_2 , V_271 ) ;
if ( ! V_264 )
goto V_276;
if ( V_271 > V_264 )
V_271 = V_264 ;
if ( V_2 -> V_273 == V_274 ) {
V_297 = V_298 = F_175 ( V_4 -> V_101 ) + 16 +
V_4 -> V_303 ;
} else {
unsigned int V_304 = F_166 ( V_23 ) ;
V_298 = F_175 ( V_4 -> V_101 +
( V_304 < 16 ? 16 : V_304 ) ) +
V_4 -> V_303 ;
V_297 = V_298 - V_304 ;
}
if ( V_4 -> V_15 <= V_19 ) {
if ( V_297 + V_271 > V_4 -> V_62 . V_53 ) {
if ( V_4 -> V_305 &&
F_52 ( & V_2 -> V_160 ) < V_2 -> V_162 ) {
if ( F_167 ( V_23 ) ) {
V_299 = F_168 ( V_23 , V_213 ) ;
} else {
V_299 = F_176 ( V_23 ) ;
V_269 = V_23 -> V_65 ;
}
if ( V_299 )
F_173 ( V_299 , V_2 ) ;
}
V_271 = V_4 -> V_62 . V_53 - V_297 ;
if ( ( int ) V_271 < 0 )
V_271 = 0 ;
}
}
F_12 ( & V_2 -> V_114 . V_63 ) ;
V_13 . V_14 = F_86 ( V_4 , V_23 ,
V_144 , ( V_297 + V_271 ) ) ;
if ( ! V_13 . V_14 )
goto V_306;
if ( V_4 -> V_15 <= V_19 ) {
F_93 ( V_4 , & V_4 -> V_62 ) ;
if ( V_4 -> V_104 . V_292 . V_133 )
V_11 |= V_134 ;
}
V_4 -> V_104 . V_292 . V_293 ++ ;
if ( V_299 ) {
V_11 |= V_307 ;
F_174 ( & V_2 -> V_114 , V_299 ) ;
}
F_10 ( & V_2 -> V_114 . V_63 ) ;
F_177 ( V_23 , 0 , V_13 . V_14 + V_297 , V_271 ) ;
if ( ! ( V_37 = F_22 ( V_23 , & V_25 , V_4 -> V_38 ) ) )
F_61 ( & V_25 ) ;
V_11 |= V_37 ;
switch ( V_4 -> V_15 ) {
case V_16 :
V_13 . V_17 -> V_308 = V_23 -> V_153 ;
V_13 . V_17 -> V_309 = V_271 ;
V_13 . V_17 -> V_310 = V_297 ;
V_13 . V_17 -> V_311 = V_298 ;
V_13 . V_17 -> V_39 = V_25 . V_40 ;
V_13 . V_17 -> V_41 = V_25 . V_42 / V_43 ;
V_100 = sizeof( * V_13 . V_17 ) ;
break;
case V_19 :
V_13 . V_20 -> V_308 = V_23 -> V_153 ;
V_13 . V_20 -> V_309 = V_271 ;
V_13 . V_20 -> V_310 = V_297 ;
V_13 . V_20 -> V_311 = V_298 ;
V_13 . V_20 -> V_39 = V_25 . V_40 ;
V_13 . V_20 -> V_44 = V_25 . V_42 ;
if ( F_78 ( V_23 ) ) {
V_13 . V_20 -> V_148 = F_79 ( V_23 ) ;
V_11 |= V_149 ;
} else {
V_13 . V_20 -> V_148 = 0 ;
}
V_13 . V_20 -> V_312 = 0 ;
V_100 = sizeof( * V_13 . V_20 ) ;
break;
case V_21 :
V_13 . V_313 -> V_18 |= V_11 ;
V_13 . V_313 -> V_308 = V_23 -> V_153 ;
V_13 . V_313 -> V_309 = V_271 ;
V_13 . V_313 -> V_310 = V_297 ;
V_13 . V_313 -> V_311 = V_298 ;
V_13 . V_313 -> V_39 = V_25 . V_40 ;
V_13 . V_313 -> V_44 = V_25 . V_42 ;
V_100 = sizeof( * V_13 . V_313 ) ;
break;
default:
F_18 () ;
}
V_268 = V_13 . V_14 + F_175 ( V_100 ) ;
V_268 -> V_289 = F_171 ( V_23 , V_268 -> V_290 ) ;
V_268 -> V_282 = V_283 ;
V_268 -> V_284 = V_72 -> type ;
V_268 -> V_285 = V_23 -> V_221 ;
V_268 -> V_286 = V_23 -> V_211 ;
if ( F_39 ( V_4 -> V_287 ) )
V_268 -> V_288 = V_183 -> V_80 ;
else
V_268 -> V_288 = V_72 -> V_80 ;
F_85 () ;
#if V_121 == 1
{
T_3 * V_122 , * V_123 ;
if ( V_4 -> V_15 <= V_19 ) {
V_123 = ( T_3 * ) F_58 ( ( unsigned long ) V_13 . V_14
+ V_297 + V_271 ) ;
for ( V_122 = V_13 . V_14 ; V_122 < V_123 ; V_122 += V_124 )
F_15 ( F_16 ( V_122 ) ) ;
}
F_19 () ;
}
#endif
if ( V_4 -> V_15 <= V_19 )
F_14 ( V_4 , V_13 . V_14 , V_11 ) ;
else
F_71 ( & V_4 -> V_62 ) ;
V_2 -> V_296 ( V_2 , 0 ) ;
V_276:
if ( V_269 != V_23 -> V_65 && F_167 ( V_23 ) ) {
V_23 -> V_65 = V_269 ;
V_23 -> V_153 = V_270 ;
}
V_272:
F_115 ( V_23 ) ;
return 0 ;
V_306:
V_4 -> V_104 . V_292 . V_133 ++ ;
F_10 ( & V_2 -> V_114 . V_63 ) ;
V_2 -> V_296 ( V_2 , 0 ) ;
F_115 ( V_299 ) ;
goto V_276;
}
static void F_178 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = F_2 ( V_23 -> V_2 ) ;
void * V_314 ;
if ( F_70 ( V_4 -> V_58 . V_51 ) ) {
T_1 V_25 ;
V_314 = F_158 ( V_23 ) -> V_315 ;
F_117 ( F_52 ( & V_4 -> V_58 . V_316 ) == 0 ) ;
F_73 ( & V_4 -> V_58 . V_316 ) ;
V_25 = F_25 ( V_4 , V_314 , V_23 ) ;
F_14 ( V_4 , V_314 , V_150 | V_25 ) ;
}
F_179 ( V_23 ) ;
}
static int F_180 ( struct V_3 * V_4 , struct V_22 * V_23 ,
void * V_10 , struct V_71 * V_72 , int V_317 ,
T_6 V_229 , unsigned char * V_318 , int V_319 )
{
union V_12 V_314 ;
int V_320 , V_321 , V_153 , V_308 , V_322 , V_323 ;
struct V_224 * V_1 = V_4 -> V_2 . V_324 ;
struct V_325 * V_325 ;
void * V_65 ;
int V_78 ;
V_314 . V_14 = V_10 ;
V_23 -> V_221 = V_229 ;
V_23 -> V_72 = V_72 ;
V_23 -> V_258 = V_4 -> V_2 . V_259 ;
V_23 -> V_260 = V_4 -> V_2 . V_261 ;
F_157 ( & V_4 -> V_2 , & F_158 ( V_23 ) -> V_262 ) ;
F_158 ( V_23 ) -> V_315 = V_314 . V_14 ;
switch ( V_4 -> V_15 ) {
case V_19 :
V_308 = V_314 . V_20 -> V_308 ;
break;
default:
V_308 = V_314 . V_17 -> V_308 ;
break;
}
if ( F_39 ( V_308 > V_317 ) ) {
F_100 ( L_4 , V_308 , V_317 ) ;
return - V_241 ;
}
F_150 ( V_23 , V_319 ) ;
F_151 ( V_23 ) ;
F_159 ( V_23 , 0 ) ;
if ( V_4 -> V_326 ) {
int V_327 , V_328 , V_329 ;
V_327 = V_4 -> V_101 - sizeof( struct V_267 ) ;
V_328 = V_4 -> V_58 . V_53 - V_308 ;
if ( V_1 -> type == V_274 ) {
switch ( V_4 -> V_15 ) {
case V_19 :
V_329 = V_314 . V_20 -> V_311 ;
break;
default:
V_329 = V_314 . V_17 -> V_311 ;
break;
}
} else {
switch ( V_4 -> V_15 ) {
case V_19 :
V_329 = V_314 . V_20 -> V_310 ;
break;
default:
V_329 = V_314 . V_17 -> V_310 ;
break;
}
}
if ( F_39 ( ( V_329 < V_327 ) || ( V_328 < V_329 ) ) )
return - V_198 ;
V_65 = V_314 . V_14 + V_329 ;
} else {
V_65 = V_314 . V_14 + V_4 -> V_101 - sizeof( struct V_267 ) ;
}
V_320 = V_308 ;
if ( V_1 -> type == V_274 ) {
V_78 = F_181 ( V_23 , V_72 , F_182 ( V_229 ) , V_318 ,
NULL , V_308 ) ;
if ( F_39 ( V_78 < 0 ) )
return - V_198 ;
} else if ( V_72 -> V_243 ) {
if ( F_39 ( V_308 <= V_72 -> V_243 ) ) {
F_100 ( L_5 ,
V_308 , V_72 -> V_243 ) ;
return - V_198 ;
}
F_139 ( V_23 , V_72 -> V_243 ) ;
V_78 = F_183 ( V_23 , 0 , V_65 ,
V_72 -> V_243 ) ;
if ( F_39 ( V_78 ) )
return V_78 ;
V_65 += V_72 -> V_243 ;
V_320 -= V_72 -> V_243 ;
}
V_321 = F_184 ( V_65 ) ;
V_323 = V_124 - V_321 ;
V_153 = ( ( V_320 > V_323 ) ? V_323 : V_320 ) ;
V_23 -> V_330 = V_320 ;
V_23 -> V_153 += V_320 ;
V_23 -> V_161 += V_320 ;
F_185 ( V_320 , & V_4 -> V_2 . V_164 ) ;
while ( F_70 ( V_320 ) ) {
V_322 = F_158 ( V_23 ) -> V_322 ;
if ( F_39 ( V_322 >= V_331 ) ) {
F_100 ( L_6 ,
V_331 ) ;
return - V_332 ;
}
V_325 = F_16 ( V_65 ) ;
V_65 += V_153 ;
F_15 ( V_325 ) ;
F_186 ( V_325 ) ;
F_187 ( V_23 , V_322 , V_325 , V_321 , V_153 ) ;
V_320 -= V_153 ;
V_321 = 0 ;
V_323 = V_124 ;
V_153 = ( ( V_320 > V_323 ) ? V_323 : V_320 ) ;
}
return V_308 ;
}
static int F_188 ( struct V_3 * V_4 , struct V_225 * V_226 )
{
struct V_22 * V_23 ;
struct V_71 * V_72 ;
T_6 V_229 ;
bool V_333 = false ;
int V_78 , V_334 = 0 ;
void * V_314 ;
struct V_267 * V_227 = (struct V_267 * ) V_226 -> V_228 ;
int V_308 , V_317 ;
unsigned char * V_318 ;
int V_335 = 0 ;
int V_11 = V_150 ;
int V_319 , V_246 ;
F_120 ( & V_4 -> V_336 ) ;
if ( V_227 == NULL ) {
V_72 = V_4 -> V_7 . V_72 ;
V_229 = V_4 -> V_168 ;
V_318 = NULL ;
} else {
V_78 = - V_198 ;
if ( V_226 -> V_231 < sizeof( struct V_267 ) )
goto V_115;
if ( V_226 -> V_231 < ( V_227 -> V_289
+ F_189 ( struct V_267 ,
V_290 ) ) )
goto V_115;
V_229 = V_227 -> V_285 ;
V_318 = V_227 -> V_290 ;
V_72 = F_190 ( F_38 ( & V_4 -> V_2 ) , V_227 -> V_288 ) ;
V_333 = true ;
}
V_78 = - V_337 ;
if ( F_39 ( V_72 == NULL ) )
goto V_115;
V_334 = V_72 -> V_243 ;
V_78 = - V_237 ;
if ( F_39 ( ! ( V_72 -> V_26 & V_238 ) ) )
goto V_338;
V_317 = V_4 -> V_58 . V_53
- ( V_4 -> V_101 - sizeof( struct V_267 ) ) ;
if ( V_317 > V_72 -> V_242 + V_334 )
V_317 = V_72 -> V_242 + V_334 ;
do {
V_314 = F_27 ( V_4 , & V_4 -> V_58 ,
V_339 ) ;
if ( F_39 ( V_314 == NULL ) ) {
F_191 () ;
continue;
}
V_11 = V_339 ;
V_319 = F_147 ( V_72 ) ;
V_246 = V_72 -> V_247 ;
V_23 = F_192 ( & V_4 -> V_2 ,
V_319 + V_246 + sizeof( struct V_267 ) ,
0 , & V_78 ) ;
if ( F_39 ( V_23 == NULL ) )
goto V_340;
V_308 = F_180 ( V_4 , V_23 , V_314 , V_72 , V_317 , V_229 ,
V_318 , V_319 ) ;
if ( F_39 ( V_308 < 0 ) ) {
if ( V_4 -> V_341 ) {
F_14 ( V_4 , V_314 ,
V_150 ) ;
F_94 ( & V_4 -> V_58 ) ;
F_115 ( V_23 ) ;
continue;
} else {
V_11 = V_342 ;
V_78 = V_308 ;
goto V_340;
}
}
V_23 -> V_343 = F_178 ;
F_14 ( V_4 , V_314 , V_344 ) ;
F_83 ( & V_4 -> V_58 . V_316 ) ;
V_11 = V_339 ;
V_78 = F_160 ( V_23 ) ;
if ( F_39 ( V_78 > 0 ) ) {
V_78 = F_193 ( V_78 ) ;
if ( V_78 && F_20 ( V_4 , V_314 ) ==
V_150 ) {
V_23 = NULL ;
goto V_340;
}
V_78 = 0 ;
}
F_94 ( & V_4 -> V_58 ) ;
V_335 += V_308 ;
} while ( F_70 ( ( V_314 != NULL ) ||
( ( ! ( V_226 -> V_345 & V_346 ) ) &&
( F_52 ( & V_4 -> V_58 . V_316 ) ) ) )
);
V_78 = V_335 ;
goto V_338;
V_340:
F_14 ( V_4 , V_314 , V_11 ) ;
F_115 ( V_23 ) ;
V_338:
if ( V_333 )
F_194 ( V_72 ) ;
V_115:
F_128 ( & V_4 -> V_336 ) ;
return V_78 ;
}
static struct V_22 * F_195 ( struct V_1 * V_2 , T_5 V_347 ,
T_5 V_334 , T_5 V_153 ,
T_5 V_348 , int V_349 ,
int * V_78 )
{
struct V_22 * V_23 ;
if ( V_347 + V_153 < V_124 || ! V_348 )
V_348 = V_153 ;
V_23 = F_196 ( V_2 , V_347 + V_348 , V_153 - V_348 , V_349 ,
V_78 ) ;
if ( ! V_23 )
return NULL ;
F_150 ( V_23 , V_334 ) ;
F_153 ( V_23 , V_348 ) ;
V_23 -> V_330 = V_153 - V_348 ;
V_23 -> V_153 += V_153 - V_348 ;
return V_23 ;
}
static int F_197 ( struct V_224 * V_1 ,
struct V_225 * V_226 , T_5 V_153 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_267 * V_227 = (struct V_267 * ) V_226 -> V_228 ;
struct V_22 * V_23 ;
struct V_71 * V_72 ;
T_6 V_229 ;
bool V_333 = false ;
unsigned char * V_318 ;
int V_78 , V_334 = 0 ;
struct V_350 V_351 = { 0 } ;
int V_321 = 0 ;
int V_352 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_353 = 0 ;
int V_319 , V_246 ;
int V_230 = 0 ;
if ( V_227 == NULL ) {
V_72 = V_4 -> V_7 . V_72 ;
V_229 = V_4 -> V_168 ;
V_318 = NULL ;
} else {
V_78 = - V_198 ;
if ( V_226 -> V_231 < sizeof( struct V_267 ) )
goto V_115;
if ( V_226 -> V_231 < ( V_227 -> V_289 + F_189 ( struct V_267 , V_290 ) ) )
goto V_115;
V_229 = V_227 -> V_285 ;
V_318 = V_227 -> V_290 ;
V_72 = F_190 ( F_38 ( V_2 ) , V_227 -> V_288 ) ;
V_333 = true ;
}
V_78 = - V_337 ;
if ( V_72 == NULL )
goto V_236;
if ( V_1 -> type == V_354 )
V_334 = V_72 -> V_243 ;
V_78 = - V_237 ;
if ( ! ( V_72 -> V_26 & V_238 ) )
goto V_236;
if ( V_4 -> V_355 ) {
V_352 = sizeof( V_351 ) ;
V_78 = - V_198 ;
if ( V_153 < V_352 )
goto V_236;
V_153 -= V_352 ;
V_78 = F_152 ( ( void * ) & V_351 , V_226 -> V_252 ,
V_352 ) ;
if ( V_78 < 0 )
goto V_236;
if ( ( V_351 . V_26 & V_356 ) &&
( V_351 . V_357 + V_351 . V_358 + 2 >
V_351 . V_359 ) )
V_351 . V_359 = V_351 . V_357 +
V_351 . V_358 + 2 ;
V_78 = - V_198 ;
if ( V_351 . V_359 > V_153 )
goto V_236;
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
goto V_236;
}
if ( V_351 . V_353 & V_361 )
V_353 |= V_368 ;
if ( V_351 . V_369 == 0 )
goto V_236;
}
}
if ( F_39 ( F_99 ( V_2 , V_239 ) ) ) {
if ( ! F_146 ( V_72 ) ) {
V_78 = - V_240 ;
goto V_236;
}
V_230 = 4 ;
}
V_78 = - V_241 ;
if ( ! V_353 && ( V_153 > V_72 -> V_242 + V_334 + V_244 + V_230 ) )
goto V_236;
V_78 = - V_250 ;
V_319 = F_147 ( V_72 ) ;
V_246 = V_72 -> V_247 ;
V_23 = F_195 ( V_2 , V_319 + V_246 , V_319 , V_153 , V_351 . V_359 ,
V_226 -> V_345 & V_346 , & V_78 ) ;
if ( V_23 == NULL )
goto V_236;
F_198 ( V_23 , V_334 ) ;
V_78 = - V_198 ;
if ( V_1 -> type == V_274 &&
( V_321 = F_181 ( V_23 , V_72 , F_182 ( V_229 ) , V_318 , NULL , V_153 ) ) < 0 )
goto V_253;
V_78 = F_199 ( V_23 , V_321 , V_226 -> V_252 , 0 , V_153 ) ;
if ( V_78 )
goto V_253;
F_157 ( V_2 , & F_158 ( V_23 ) -> V_262 ) ;
if ( ! V_353 && ( V_153 > V_72 -> V_242 + V_334 + V_230 ) ) {
struct V_254 * V_255 ;
F_154 ( V_23 ) ;
V_255 = F_155 ( V_23 ) ;
if ( V_255 -> V_256 != F_156 ( V_257 ) ) {
V_78 = - V_241 ;
goto V_253;
}
}
V_23 -> V_221 = V_229 ;
V_23 -> V_72 = V_72 ;
V_23 -> V_258 = V_2 -> V_259 ;
V_23 -> V_260 = V_2 -> V_261 ;
if ( V_4 -> V_355 ) {
if ( V_351 . V_26 & V_356 ) {
if ( ! F_200 ( V_23 , V_351 . V_357 ,
V_351 . V_358 ) ) {
V_78 = - V_198 ;
goto V_253;
}
}
F_158 ( V_23 ) -> V_369 = V_351 . V_369 ;
F_158 ( V_23 ) -> V_353 = V_353 ;
F_158 ( V_23 ) -> V_353 |= V_370 ;
F_158 ( V_23 ) -> V_371 = 0 ;
V_153 += V_352 ;
}
F_159 ( V_23 , V_334 ) ;
if ( F_39 ( V_230 == 4 ) )
V_23 -> V_263 = 1 ;
V_78 = F_160 ( V_23 ) ;
if ( V_78 > 0 && ( V_78 = F_193 ( V_78 ) ) != 0 )
goto V_236;
if ( V_333 )
F_194 ( V_72 ) ;
return V_153 ;
V_253:
F_115 ( V_23 ) ;
V_236:
if ( V_72 && V_333 )
F_194 ( V_72 ) ;
V_115:
return V_78 ;
}
static int F_201 ( struct V_222 * V_223 , struct V_224 * V_1 ,
struct V_225 * V_226 , T_5 V_153 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_58 . V_51 )
return F_188 ( V_4 , V_226 ) ;
else
return F_197 ( V_1 , V_226 , V_153 ) ;
}
static int F_202 ( struct V_224 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 ;
struct V_186 * V_186 ;
union V_85 V_86 ;
if ( ! V_2 )
return 0 ;
V_186 = F_38 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
F_120 ( & V_186 -> V_372 . V_373 ) ;
F_203 ( V_2 ) ;
F_128 ( & V_186 -> V_372 . V_373 ) ;
F_204 () ;
F_205 ( V_186 , V_2 -> V_374 , - 1 ) ;
F_206 () ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_2 , false ) ;
if ( V_4 -> V_7 . V_72 ) {
F_194 ( V_4 -> V_7 . V_72 ) ;
V_4 -> V_7 . V_72 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
F_207 ( V_2 ) ;
if ( V_4 -> V_62 . V_51 ) {
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
F_208 ( V_2 , & V_86 , 1 , 0 ) ;
}
if ( V_4 -> V_58 . V_51 ) {
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
F_208 ( V_2 , & V_86 , 1 , 1 ) ;
}
F_129 ( V_2 ) ;
F_11 () ;
F_209 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_97 ( & V_2 -> V_114 ) ;
F_210 ( V_2 ) ;
F_211 ( V_2 ) ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 , struct V_71 * V_72 , T_6 V_221 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 ) {
if ( V_72 )
F_194 ( V_72 ) ;
return - V_198 ;
}
F_213 ( V_2 ) ;
F_12 ( & V_4 -> V_9 ) ;
F_13 ( V_2 , true ) ;
V_4 -> V_168 = V_221 ;
V_4 -> V_7 . type = V_221 ;
if ( V_4 -> V_7 . V_72 )
F_194 ( V_4 -> V_7 . V_72 ) ;
V_4 -> V_7 . V_72 = V_72 ;
V_4 -> V_80 = V_72 ? V_72 -> V_80 : 0 ;
if ( V_221 == 0 )
goto V_236;
if ( ! V_72 || ( V_72 -> V_26 & V_238 ) ) {
F_1 ( V_2 ) ;
} else {
V_2 -> V_375 = V_237 ;
if ( ! F_99 ( V_2 , V_165 ) )
V_2 -> V_376 ( V_2 ) ;
}
V_236:
F_10 ( & V_4 -> V_9 ) ;
F_214 ( V_2 ) ;
return 0 ;
}
static int F_215 ( struct V_224 * V_1 , struct V_232 * V_377 ,
int V_378 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
char V_219 [ 15 ] ;
struct V_71 * V_72 ;
int V_78 = - V_235 ;
if ( V_378 != sizeof( struct V_232 ) )
return - V_198 ;
F_141 ( V_219 , V_377 -> V_379 , sizeof( V_219 ) ) ;
V_72 = F_216 ( F_38 ( V_2 ) , V_219 ) ;
if ( V_72 )
V_78 = F_212 ( V_2 , V_72 , F_2 ( V_2 ) -> V_168 ) ;
return V_78 ;
}
static int F_217 ( struct V_224 * V_1 , struct V_232 * V_377 , int V_378 )
{
struct V_267 * V_268 = (struct V_267 * ) V_377 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_71 * V_72 = NULL ;
int V_78 ;
if ( V_378 < sizeof( struct V_267 ) )
return - V_198 ;
if ( V_268 -> V_282 != V_283 )
return - V_198 ;
if ( V_268 -> V_288 ) {
V_78 = - V_235 ;
V_72 = F_190 ( F_38 ( V_2 ) , V_268 -> V_288 ) ;
if ( V_72 == NULL )
goto V_115;
}
V_78 = F_212 ( V_2 , V_72 , V_268 -> V_285 ? : F_2 ( V_2 ) -> V_168 ) ;
V_115:
return V_78 ;
}
static int F_218 ( struct V_186 * V_186 , struct V_224 * V_1 , int V_221 ,
int V_380 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_6 V_229 = ( V_381 T_6 ) V_221 ;
int V_78 ;
if ( ! F_219 ( V_186 -> V_382 , V_383 ) )
return - V_384 ;
if ( V_1 -> type != V_274 && V_1 -> type != V_354 &&
V_1 -> type != V_385 )
return - V_386 ;
V_1 -> V_387 = V_388 ;
V_78 = - V_250 ;
V_2 = F_220 ( V_186 , V_389 , V_202 , & V_390 ) ;
if ( V_2 == NULL )
goto V_115;
V_1 -> V_391 = & V_392 ;
if ( V_1 -> type == V_385 )
V_1 -> V_391 = & V_393 ;
F_221 ( V_1 , V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_2 -> V_394 = V_389 ;
V_4 -> V_168 = V_229 ;
V_2 -> V_395 = F_96 ;
F_222 ( V_2 ) ;
F_126 ( & V_4 -> V_9 ) ;
F_223 ( & V_4 -> V_336 ) ;
V_4 -> V_7 . F_32 = F_164 ;
if ( V_1 -> type == V_385 )
V_4 -> V_7 . F_32 = F_134 ;
V_4 -> V_7 . V_184 = V_2 ;
if ( V_229 ) {
V_4 -> V_7 . type = V_229 ;
F_1 ( V_2 ) ;
}
F_120 ( & V_186 -> V_372 . V_373 ) ;
F_224 ( V_2 , & V_186 -> V_372 . V_396 ) ;
F_128 ( & V_186 -> V_372 . V_373 ) ;
F_204 () ;
F_205 ( V_186 , & V_390 , 1 ) ;
F_206 () ;
return 0 ;
V_115:
return V_78 ;
}
static int F_225 ( struct V_1 * V_2 , struct V_225 * V_226 , int V_153 )
{
struct V_397 * V_398 ;
struct V_22 * V_23 , * V_399 ;
int V_400 , V_78 ;
V_78 = - V_401 ;
V_23 = F_226 ( & V_2 -> V_163 ) ;
if ( V_23 == NULL )
goto V_115;
V_400 = V_23 -> V_153 ;
if ( V_400 > V_153 ) {
V_226 -> V_345 |= V_402 ;
V_400 = V_153 ;
}
V_78 = F_227 ( V_23 , 0 , V_226 -> V_252 , V_400 ) ;
if ( V_78 )
goto V_403;
F_228 ( V_226 , V_2 , V_23 ) ;
V_398 = F_229 ( V_23 ) ;
F_230 ( V_226 , V_404 , V_405 ,
sizeof( V_398 -> V_406 ) , & V_398 -> V_406 ) ;
V_226 -> V_345 |= V_407 ;
V_78 = V_400 ;
F_231 ( & V_2 -> V_163 . V_63 ) ;
V_2 -> V_375 = 0 ;
if ( ( V_399 = F_232 ( & V_2 -> V_163 ) ) != NULL ) {
V_2 -> V_375 = F_229 ( V_399 ) -> V_406 . V_408 ;
F_233 ( & V_2 -> V_163 . V_63 ) ;
V_2 -> V_376 ( V_2 ) ;
} else
F_233 ( & V_2 -> V_163 . V_63 ) ;
V_403:
F_115 ( V_23 ) ;
V_115:
return V_78 ;
}
static int F_234 ( struct V_222 * V_223 , struct V_224 * V_1 ,
struct V_225 * V_226 , T_5 V_153 , int V_26 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_22 * V_23 ;
int V_400 , V_78 ;
struct V_267 * V_268 ;
int V_352 = 0 ;
V_78 = - V_198 ;
if ( V_26 & ~ ( V_409 | V_346 | V_402 | V_410 | V_407 ) )
goto V_115;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_26 & V_407 ) {
V_78 = F_225 ( V_2 , V_226 , V_153 ) ;
goto V_115;
}
V_23 = F_235 ( V_2 , V_26 , V_26 & V_346 , & V_78 ) ;
if ( V_23 == NULL )
goto V_115;
if ( F_2 ( V_2 ) -> V_355 ) {
struct V_350 V_351 = { 0 } ;
V_78 = - V_198 ;
V_352 = sizeof( V_351 ) ;
if ( V_153 < V_352 )
goto V_253;
V_153 -= V_352 ;
if ( F_236 ( V_23 ) ) {
struct V_411 * V_412 = F_158 ( V_23 ) ;
V_351 . V_359 = F_237 ( V_23 ) ;
V_351 . V_369 = V_412 -> V_369 ;
if ( V_412 -> V_353 & V_363 )
V_351 . V_353 = V_362 ;
else if ( V_412 -> V_353 & V_365 )
V_351 . V_353 = V_364 ;
else if ( V_412 -> V_353 & V_367 )
V_351 . V_353 = V_366 ;
else if ( V_412 -> V_353 & V_413 )
goto V_253;
else
F_18 () ;
if ( V_412 -> V_353 & V_368 )
V_351 . V_353 |= V_361 ;
} else
V_351 . V_353 = V_360 ;
if ( V_23 -> V_300 == V_301 ) {
V_351 . V_26 = V_356 ;
V_351 . V_357 = F_238 ( V_23 ) ;
V_351 . V_358 = V_23 -> V_358 ;
} else if ( V_23 -> V_300 == V_414 ) {
V_351 . V_26 = V_415 ;
}
V_78 = F_239 ( V_226 -> V_252 , ( void * ) & V_351 ,
V_352 ) ;
if ( V_78 < 0 )
goto V_253;
}
V_268 = & F_138 ( V_23 ) -> V_215 . V_281 ;
if ( V_1 -> type == V_385 )
V_226 -> V_231 = sizeof( struct V_209 ) ;
else
V_226 -> V_231 = V_268 -> V_289 + F_189 ( struct V_267 , V_290 ) ;
V_400 = V_23 -> V_153 ;
if ( V_400 > V_153 ) {
V_400 = V_153 ;
V_226 -> V_345 |= V_402 ;
}
V_78 = F_227 ( V_23 , 0 , V_226 -> V_252 , V_400 ) ;
if ( V_78 )
goto V_253;
F_240 ( V_226 , V_2 , V_23 ) ;
if ( V_226 -> V_228 )
memcpy ( V_226 -> V_228 , & F_138 ( V_23 ) -> V_215 ,
V_226 -> V_231 ) ;
if ( F_2 ( V_2 ) -> V_416 ) {
struct V_417 V_418 ;
V_418 . V_18 = V_127 ;
if ( V_23 -> V_300 == V_301 )
V_418 . V_18 |= V_302 ;
V_418 . V_308 = F_138 ( V_23 ) -> V_291 ;
V_418 . V_309 = V_23 -> V_153 ;
V_418 . V_310 = 0 ;
V_418 . V_311 = F_166 ( V_23 ) ;
if ( F_78 ( V_23 ) ) {
V_418 . V_148 = F_79 ( V_23 ) ;
V_418 . V_18 |= V_149 ;
} else {
V_418 . V_148 = 0 ;
}
V_418 . V_312 = 0 ;
F_230 ( V_226 , V_404 , V_419 , sizeof( V_418 ) , & V_418 ) ;
}
V_78 = V_352 + ( ( V_26 & V_402 ) ? V_23 -> V_153 : V_400 ) ;
V_253:
F_241 ( V_2 , V_23 ) ;
V_115:
return V_78 ;
}
static int F_242 ( struct V_224 * V_1 , struct V_232 * V_377 ,
int * V_420 , int V_421 )
{
struct V_71 * V_72 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_421 )
return - V_422 ;
V_377 -> V_423 = V_283 ;
memset ( V_377 -> V_379 , 0 , sizeof( V_377 -> V_379 ) ) ;
F_144 () ;
V_72 = F_243 ( F_38 ( V_2 ) , F_2 ( V_2 ) -> V_80 ) ;
if ( V_72 )
F_141 ( V_377 -> V_379 , V_72 -> V_219 , sizeof( V_377 -> V_379 ) ) ;
F_148 () ;
* V_420 = sizeof( * V_377 ) ;
return 0 ;
}
static int F_244 ( struct V_224 * V_1 , struct V_232 * V_377 ,
int * V_420 , int V_421 )
{
struct V_71 * V_72 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_245 ( struct V_267 * , V_268 , V_377 ) ;
if ( V_421 )
return - V_422 ;
V_268 -> V_282 = V_283 ;
V_268 -> V_288 = V_4 -> V_80 ;
V_268 -> V_285 = V_4 -> V_168 ;
V_268 -> V_286 = 0 ;
F_144 () ;
V_72 = F_243 ( F_38 ( V_2 ) , V_4 -> V_80 ) ;
if ( V_72 ) {
V_268 -> V_284 = V_72 -> type ;
V_268 -> V_289 = V_72 -> V_378 ;
memcpy ( V_268 -> V_290 , V_72 -> V_424 , V_72 -> V_378 ) ;
} else {
V_268 -> V_284 = 0 ;
V_268 -> V_289 = 0 ;
}
F_148 () ;
* V_420 = F_189 ( struct V_267 , V_290 ) + V_268 -> V_289 ;
return 0 ;
}
static int F_246 ( struct V_71 * V_72 , struct V_425 * V_176 ,
int V_426 )
{
switch ( V_176 -> type ) {
case V_427 :
if ( V_176 -> V_428 != V_72 -> V_378 )
return - V_198 ;
if ( V_426 > 0 )
return F_247 ( V_72 , V_176 -> V_318 ) ;
else
return F_248 ( V_72 , V_176 -> V_318 ) ;
break;
case V_429 :
return F_249 ( V_72 , V_426 ) ;
break;
case V_430 :
return F_250 ( V_72 , V_426 ) ;
break;
case V_431 :
if ( V_176 -> V_428 != V_72 -> V_378 )
return - V_198 ;
if ( V_426 > 0 )
return F_251 ( V_72 , V_176 -> V_318 ) ;
else
return F_252 ( V_72 , V_176 -> V_318 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_253 ( struct V_71 * V_72 , struct V_425 * V_176 , int V_426 )
{
for ( ; V_176 ; V_176 = V_176 -> V_178 ) {
if ( V_176 -> V_80 == V_72 -> V_80 )
F_246 ( V_72 , V_176 , V_426 ) ;
}
}
static int F_254 ( struct V_1 * V_2 , struct V_432 * V_433 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_425 * V_434 , * V_176 ;
struct V_71 * V_72 ;
int V_78 ;
F_36 () ;
V_78 = - V_235 ;
V_72 = F_37 ( F_38 ( V_2 ) , V_433 -> V_435 ) ;
if ( ! V_72 )
goto V_436;
V_78 = - V_198 ;
if ( V_433 -> V_437 > V_72 -> V_378 )
goto V_436;
V_78 = - V_250 ;
V_176 = F_255 ( sizeof( * V_176 ) , V_202 ) ;
if ( V_176 == NULL )
goto V_436;
V_78 = 0 ;
for ( V_434 = V_4 -> V_438 ; V_434 ; V_434 = V_434 -> V_178 ) {
if ( V_434 -> V_80 == V_433 -> V_435 &&
V_434 -> type == V_433 -> V_439 &&
V_434 -> V_428 == V_433 -> V_437 &&
memcmp ( V_434 -> V_318 , V_433 -> V_440 , V_434 -> V_428 ) == 0 ) {
V_434 -> V_441 ++ ;
F_133 ( V_176 ) ;
goto V_436;
}
}
V_176 -> type = V_433 -> V_439 ;
V_176 -> V_80 = V_433 -> V_435 ;
V_176 -> V_428 = V_433 -> V_437 ;
memcpy ( V_176 -> V_318 , V_433 -> V_440 , V_176 -> V_428 ) ;
V_176 -> V_441 = 1 ;
V_176 -> V_178 = V_4 -> V_438 ;
V_4 -> V_438 = V_176 ;
V_78 = F_246 ( V_72 , V_176 , 1 ) ;
if ( V_78 ) {
V_4 -> V_438 = V_176 -> V_178 ;
F_133 ( V_176 ) ;
}
V_436:
F_40 () ;
return V_78 ;
}
static int F_256 ( struct V_1 * V_2 , struct V_432 * V_433 )
{
struct V_425 * V_434 , * * V_442 ;
F_36 () ;
for ( V_442 = & F_2 ( V_2 ) -> V_438 ; ( V_434 = * V_442 ) != NULL ; V_442 = & V_434 -> V_178 ) {
if ( V_434 -> V_80 == V_433 -> V_435 &&
V_434 -> type == V_433 -> V_439 &&
V_434 -> V_428 == V_433 -> V_437 &&
memcmp ( V_434 -> V_318 , V_433 -> V_440 , V_434 -> V_428 ) == 0 ) {
if ( -- V_434 -> V_441 == 0 ) {
struct V_71 * V_72 ;
* V_442 = V_434 -> V_178 ;
V_72 = F_37 ( F_38 ( V_2 ) , V_434 -> V_80 ) ;
if ( V_72 )
F_246 ( V_72 , V_434 , - 1 ) ;
F_133 ( V_434 ) ;
}
F_40 () ;
return 0 ;
}
}
F_40 () ;
return - V_443 ;
}
static void F_207 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_425 * V_434 ;
if ( ! V_4 -> V_438 )
return;
F_36 () ;
while ( ( V_434 = V_4 -> V_438 ) != NULL ) {
struct V_71 * V_72 ;
V_4 -> V_438 = V_434 -> V_178 ;
V_72 = F_37 ( F_38 ( V_2 ) , V_434 -> V_80 ) ;
if ( V_72 != NULL )
F_246 ( V_72 , V_434 , - 1 ) ;
F_133 ( V_434 ) ;
}
F_40 () ;
}
static int
F_257 ( struct V_224 * V_1 , int V_444 , int V_445 , char T_7 * V_446 , unsigned int V_447 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_448 ;
if ( V_444 != V_404 )
return - V_449 ;
switch ( V_445 ) {
case V_450 :
case V_451 :
{
struct V_432 V_433 ;
int V_153 = V_447 ;
memset ( & V_433 , 0 , sizeof( V_433 ) ) ;
if ( V_153 < sizeof( struct V_452 ) )
return - V_198 ;
if ( V_153 > sizeof( V_433 ) )
V_153 = sizeof( V_433 ) ;
if ( F_258 ( & V_433 , V_446 , V_153 ) )
return - V_332 ;
if ( V_153 < ( V_433 . V_437 + F_189 ( struct V_452 , V_440 ) ) )
return - V_198 ;
if ( V_445 == V_450 )
V_448 = F_254 ( V_2 , & V_433 ) ;
else
V_448 = F_256 ( V_2 , & V_433 ) ;
return V_448 ;
}
case V_453 :
case V_454 :
{
union V_85 V_86 ;
int V_153 ;
switch ( V_4 -> V_15 ) {
case V_16 :
case V_19 :
V_153 = sizeof( V_86 . V_455 ) ;
break;
case V_21 :
default:
V_153 = sizeof( V_86 . V_88 ) ;
break;
}
if ( V_447 < V_153 )
return - V_198 ;
if ( F_2 ( V_2 ) -> V_355 )
return - V_198 ;
if ( F_258 ( & V_86 . V_455 , V_446 , V_153 ) )
return - V_332 ;
return F_208 ( V_2 , & V_86 , 0 ,
V_445 == V_454 ) ;
}
case V_456 :
{
int V_457 ;
if ( V_447 != sizeof( V_457 ) )
return - V_198 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
F_2 ( V_2 ) -> V_305 = V_457 ;
return 0 ;
}
case V_458 :
{
int V_457 ;
if ( V_447 != sizeof( V_457 ) )
return - V_198 ;
if ( V_4 -> V_62 . V_51 || V_4 -> V_58 . V_51 )
return - V_459 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
switch ( V_457 ) {
case V_16 :
case V_19 :
case V_21 :
V_4 -> V_15 = V_457 ;
return 0 ;
default:
return - V_198 ;
}
}
case V_460 :
{
unsigned int V_457 ;
if ( V_447 != sizeof( V_457 ) )
return - V_198 ;
if ( V_4 -> V_62 . V_51 || V_4 -> V_58 . V_51 )
return - V_459 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
V_4 -> V_303 = V_457 ;
return 0 ;
}
case V_461 :
{
unsigned int V_457 ;
if ( V_447 != sizeof( V_457 ) )
return - V_198 ;
if ( V_4 -> V_62 . V_51 || V_4 -> V_58 . V_51 )
return - V_459 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
V_4 -> V_341 = ! ! V_457 ;
return 0 ;
}
case V_419 :
{
int V_457 ;
if ( V_447 < sizeof( V_457 ) )
return - V_198 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
V_4 -> V_416 = ! ! V_457 ;
return 0 ;
}
case V_462 :
{
int V_457 ;
if ( V_447 < sizeof( V_457 ) )
return - V_198 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
V_4 -> V_287 = ! ! V_457 ;
return 0 ;
}
case V_463 :
{
int V_457 ;
if ( V_1 -> type != V_354 )
return - V_198 ;
if ( V_4 -> V_62 . V_51 || V_4 -> V_58 . V_51 )
return - V_459 ;
if ( V_447 < sizeof( V_457 ) )
return - V_198 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
V_4 -> V_355 = ! ! V_457 ;
return 0 ;
}
case V_464 :
{
int V_457 ;
if ( V_447 != sizeof( V_457 ) )
return - V_198 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
V_4 -> V_38 = V_457 ;
return 0 ;
}
case V_465 :
{
int V_457 ;
if ( V_447 != sizeof( V_457 ) )
return - V_198 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
return F_119 ( V_2 , V_457 & 0xffff , V_457 >> 16 ) ;
}
case V_466 :
{
unsigned int V_457 ;
if ( V_447 != sizeof( V_457 ) )
return - V_198 ;
if ( V_4 -> V_62 . V_51 || V_4 -> V_58 . V_51 )
return - V_459 ;
if ( F_258 ( & V_457 , V_446 , sizeof( V_457 ) ) )
return - V_332 ;
V_4 -> V_326 = ! ! V_457 ;
return 0 ;
}
default:
return - V_449 ;
}
}
static int F_259 ( struct V_224 * V_1 , int V_444 , int V_445 ,
char T_7 * V_446 , int T_7 * V_447 )
{
int V_153 ;
int V_457 , V_467 = sizeof( V_457 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void * V_65 = & V_457 ;
union V_468 V_469 ;
if ( V_444 != V_404 )
return - V_449 ;
if ( F_260 ( V_153 , V_447 ) )
return - V_332 ;
if ( V_153 < 0 )
return - V_198 ;
switch ( V_445 ) {
case V_470 :
F_231 ( & V_2 -> V_114 . V_63 ) ;
memcpy ( & V_469 , & V_4 -> V_104 , sizeof( V_469 ) ) ;
memset ( & V_4 -> V_104 , 0 , sizeof( V_4 -> V_104 ) ) ;
F_233 ( & V_2 -> V_114 . V_63 ) ;
if ( V_4 -> V_15 == V_21 ) {
V_467 = sizeof( struct V_471 ) ;
V_65 = & V_469 . V_105 ;
} else {
V_467 = sizeof( struct V_472 ) ;
V_65 = & V_469 . V_292 ;
}
break;
case V_419 :
V_457 = V_4 -> V_416 ;
break;
case V_462 :
V_457 = V_4 -> V_287 ;
break;
case V_463 :
V_457 = V_4 -> V_355 ;
break;
case V_458 :
V_457 = V_4 -> V_15 ;
break;
case V_473 :
if ( V_153 > sizeof( int ) )
V_153 = sizeof( int ) ;
if ( F_258 ( & V_457 , V_446 , V_153 ) )
return - V_332 ;
switch ( V_457 ) {
case V_16 :
V_457 = sizeof( struct V_474 ) ;
break;
case V_19 :
V_457 = sizeof( struct V_475 ) ;
break;
case V_21 :
V_457 = sizeof( struct V_128 ) ;
break;
default:
return - V_198 ;
}
break;
case V_460 :
V_457 = V_4 -> V_303 ;
break;
case V_461 :
V_457 = V_4 -> V_341 ;
break;
case V_464 :
V_457 = V_4 -> V_38 ;
break;
case V_465 :
V_457 = ( V_4 -> V_6 ?
( ( T_2 ) V_4 -> V_6 -> V_195 |
( ( T_2 ) V_4 -> V_6 -> type << 16 ) |
( ( T_2 ) V_4 -> V_6 -> V_26 << 24 ) ) :
0 ) ;
break;
case V_466 :
V_457 = V_4 -> V_326 ;
break;
default:
return - V_449 ;
}
if ( V_153 > V_467 )
V_153 = V_467 ;
if ( F_261 ( V_153 , V_447 ) )
return - V_332 ;
if ( F_262 ( V_446 , V_65 , V_153 ) )
return - V_332 ;
return 0 ;
}
static int F_263 ( struct V_476 * V_477 , unsigned long V_226 , void * V_65 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 = V_65 ;
struct V_186 * V_186 = F_113 ( V_72 ) ;
F_144 () ;
F_264 (sk, &net->packet.sklist) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_226 ) {
case V_478 :
if ( V_4 -> V_438 )
F_253 ( V_72 , V_4 -> V_438 , - 1 ) ;
case V_479 :
if ( V_72 -> V_80 == V_4 -> V_80 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_5 ) {
F_6 ( V_2 , false ) ;
V_2 -> V_375 = V_237 ;
if ( ! F_99 ( V_2 , V_165 ) )
V_2 -> V_376 ( V_2 ) ;
}
if ( V_226 == V_478 ) {
V_4 -> V_80 = - 1 ;
if ( V_4 -> V_7 . V_72 )
F_194 ( V_4 -> V_7 . V_72 ) ;
V_4 -> V_7 . V_72 = NULL ;
}
F_10 ( & V_4 -> V_9 ) ;
}
break;
case V_480 :
if ( V_72 -> V_80 == V_4 -> V_80 ) {
F_12 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_168 )
F_1 ( V_2 ) ;
F_10 ( & V_4 -> V_9 ) ;
}
break;
}
}
F_148 () ;
return V_481 ;
}
static int F_265 ( struct V_224 * V_1 , unsigned int V_482 ,
unsigned long V_483 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
switch ( V_482 ) {
case V_484 :
{
int V_485 = F_266 ( V_2 ) ;
return F_261 ( V_485 , ( int T_7 * ) V_483 ) ;
}
case V_486 :
{
struct V_22 * V_23 ;
int V_485 = 0 ;
F_231 ( & V_2 -> V_114 . V_63 ) ;
V_23 = F_232 ( & V_2 -> V_114 ) ;
if ( V_23 )
V_485 = V_23 -> V_153 ;
F_233 ( & V_2 -> V_114 . V_63 ) ;
return F_261 ( V_485 , ( int T_7 * ) V_483 ) ;
}
case V_487 :
return F_267 ( V_2 , (struct V_488 T_7 * ) V_483 ) ;
case V_489 :
return F_268 ( V_2 , (struct V_24 T_7 * ) V_483 ) ;
#ifdef F_269
case V_490 :
case V_491 :
case V_492 :
case V_493 :
case V_494 :
case V_495 :
case V_496 :
case V_497 :
case V_498 :
case V_499 :
case V_500 :
case V_501 :
case V_502 :
case V_503 :
return V_504 . V_505 ( V_1 , V_482 , V_483 ) ;
#endif
default:
return - V_506 ;
}
return 0 ;
}
static unsigned int F_270 ( struct V_507 * V_507 , struct V_224 * V_1 ,
T_8 * V_508 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_509 = F_271 ( V_507 , V_1 , V_508 ) ;
F_231 ( & V_2 -> V_114 . V_63 ) ;
if ( V_4 -> V_62 . V_51 ) {
if ( ! F_91 ( V_4 , & V_4 -> V_62 ,
V_144 ) )
V_509 |= V_510 | V_511 ;
}
F_233 ( & V_2 -> V_114 . V_63 ) ;
F_231 ( & V_2 -> V_512 . V_63 ) ;
if ( V_4 -> V_58 . V_51 ) {
if ( F_27 ( V_4 , & V_4 -> V_58 , V_150 ) )
V_509 |= V_513 | V_514 ;
}
F_233 ( & V_2 -> V_512 . V_63 ) ;
return V_509 ;
}
static void F_272 ( struct V_515 * V_516 )
{
struct V_507 * V_507 = V_516 -> V_517 ;
struct V_224 * V_1 = V_507 -> V_518 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_83 ( & F_2 ( V_2 ) -> V_519 ) ;
}
static void F_273 ( struct V_515 * V_516 )
{
struct V_507 * V_507 = V_516 -> V_517 ;
struct V_224 * V_1 = V_507 -> V_518 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_73 ( & F_2 ( V_2 ) -> V_519 ) ;
}
static void F_274 ( struct V_90 * V_51 , unsigned int V_520 ,
unsigned int V_153 )
{
int V_176 ;
for ( V_176 = 0 ; V_176 < V_153 ; V_176 ++ ) {
if ( F_70 ( V_51 [ V_176 ] . V_52 ) ) {
if ( F_275 ( V_51 [ V_176 ] . V_52 ) )
F_276 ( V_51 [ V_176 ] . V_52 ) ;
else
F_277 ( ( unsigned long ) V_51 [ V_176 ] . V_52 ,
V_520 ) ;
V_51 [ V_176 ] . V_52 = NULL ;
}
}
F_133 ( V_51 ) ;
}
static char * F_278 ( unsigned long V_520 )
{
char * V_52 = NULL ;
T_9 V_521 = V_202 | V_522 |
V_523 | V_524 | V_525 ;
V_52 = ( char * ) F_279 ( V_521 , V_520 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_280 ( ( 1 << V_520 ) * V_124 ) ;
if ( V_52 )
return V_52 ;
V_521 &= ~ V_525 ;
V_52 = ( char * ) F_279 ( V_521 , V_520 ) ;
if ( V_52 )
return V_52 ;
return NULL ;
}
static struct V_90 * F_281 ( struct V_526 * V_455 , int V_520 )
{
unsigned int V_527 = V_455 -> V_99 ;
struct V_90 * V_51 ;
int V_176 ;
V_51 = F_282 ( V_527 , sizeof( struct V_90 ) , V_202 ) ;
if ( F_39 ( ! V_51 ) )
goto V_115;
for ( V_176 = 0 ; V_176 < V_527 ; V_176 ++ ) {
V_51 [ V_176 ] . V_52 = F_278 ( V_520 ) ;
if ( F_39 ( ! V_51 [ V_176 ] . V_52 ) )
goto V_528;
}
V_115:
return V_51 ;
V_528:
F_274 ( V_51 , V_520 , V_527 ) ;
V_51 = NULL ;
goto V_115;
}
static int F_208 ( struct V_1 * V_2 , union V_85 * V_86 ,
int V_529 , int V_58 )
{
struct V_90 * V_51 = NULL ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_530 , V_520 = 0 ;
struct V_45 * V_46 ;
struct V_59 * V_60 ;
T_6 V_168 ;
int V_78 = - V_198 ;
struct V_526 * V_455 = & V_86 -> V_455 ;
if ( ! V_529 && V_58 && ( V_4 -> V_15 > V_19 ) ) {
F_17 ( 1 , L_7 ) ;
goto V_115;
}
V_46 = V_58 ? & V_4 -> V_58 : & V_4 -> V_62 ;
V_60 = V_58 ? & V_2 -> V_512 : & V_2 -> V_114 ;
V_78 = - V_459 ;
if ( ! V_529 ) {
if ( F_52 ( & V_4 -> V_519 ) )
goto V_115;
if ( F_52 ( & V_46 -> V_316 ) )
goto V_115;
}
if ( V_455 -> V_99 ) {
V_78 = - V_459 ;
if ( F_39 ( V_46 -> V_51 ) )
goto V_115;
switch ( V_4 -> V_15 ) {
case V_16 :
V_4 -> V_101 = V_531 ;
break;
case V_19 :
V_4 -> V_101 = V_532 ;
break;
case V_21 :
V_4 -> V_101 = V_533 ;
break;
}
V_78 = - V_198 ;
if ( F_39 ( ( int ) V_455 -> V_97 <= 0 ) )
goto V_115;
if ( F_39 ( V_455 -> V_97 & ( V_124 - 1 ) ) )
goto V_115;
if ( F_39 ( V_455 -> V_534 < V_4 -> V_101 +
V_4 -> V_303 ) )
goto V_115;
if ( F_39 ( V_455 -> V_534 & ( V_535 - 1 ) ) )
goto V_115;
V_46 -> V_50 = V_455 -> V_97 / V_455 -> V_534 ;
if ( F_39 ( V_46 -> V_50 <= 0 ) )
goto V_115;
if ( F_39 ( ( V_46 -> V_50 * V_455 -> V_99 ) !=
V_455 -> V_536 ) )
goto V_115;
V_78 = - V_201 ;
V_520 = F_283 ( V_455 -> V_97 ) ;
V_51 = F_281 ( V_455 , V_520 ) ;
if ( F_39 ( ! V_51 ) )
goto V_115;
switch ( V_4 -> V_15 ) {
case V_21 :
if ( ! V_58 )
F_44 ( V_4 , V_46 , V_51 , V_86 , V_58 ) ;
break;
default:
break;
}
}
else {
V_78 = - V_198 ;
if ( F_39 ( V_455 -> V_536 ) )
goto V_115;
}
F_213 ( V_2 ) ;
F_12 ( & V_4 -> V_9 ) ;
V_530 = V_4 -> V_5 ;
V_168 = V_4 -> V_168 ;
if ( V_530 ) {
V_4 -> V_168 = 0 ;
F_6 ( V_2 , false ) ;
}
F_10 ( & V_4 -> V_9 ) ;
F_11 () ;
V_78 = - V_459 ;
F_120 ( & V_4 -> V_336 ) ;
if ( V_529 || F_52 ( & V_4 -> V_519 ) == 0 ) {
V_78 = 0 ;
F_231 ( & V_60 -> V_63 ) ;
F_284 ( V_46 -> V_51 , V_51 ) ;
V_46 -> V_156 = ( V_455 -> V_536 - 1 ) ;
V_46 -> V_54 = 0 ;
V_46 -> V_53 = V_455 -> V_534 ;
F_233 ( & V_60 -> V_63 ) ;
F_284 ( V_46 -> V_537 , V_520 ) ;
F_284 ( V_46 -> V_538 , V_455 -> V_99 ) ;
V_46 -> V_539 = V_455 -> V_97 / V_124 ;
V_4 -> V_7 . F_32 = ( V_4 -> V_62 . V_51 ) ?
V_159 : F_164 ;
F_97 ( V_60 ) ;
if ( F_52 ( & V_4 -> V_519 ) )
F_100 ( L_8 ,
F_52 ( & V_4 -> V_519 ) ) ;
}
F_128 ( & V_4 -> V_336 ) ;
F_12 ( & V_4 -> V_9 ) ;
if ( V_530 ) {
V_4 -> V_168 = V_168 ;
F_1 ( V_2 ) ;
}
F_10 ( & V_4 -> V_9 ) ;
if ( V_529 && ( V_4 -> V_15 > V_19 ) ) {
if ( ! V_58 )
F_30 ( V_4 , V_58 , V_60 ) ;
}
F_214 ( V_2 ) ;
if ( V_51 )
F_274 ( V_51 , V_520 , V_455 -> V_99 ) ;
V_115:
return V_78 ;
}
static int F_285 ( struct V_507 * V_507 , struct V_224 * V_1 ,
struct V_515 * V_516 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_540 , V_541 ;
struct V_45 * V_46 ;
unsigned long V_122 ;
int V_78 = - V_198 ;
int V_176 ;
if ( V_516 -> V_542 )
return - V_198 ;
F_120 ( & V_4 -> V_336 ) ;
V_541 = 0 ;
for ( V_46 = & V_4 -> V_62 ; V_46 <= & V_4 -> V_58 ; V_46 ++ ) {
if ( V_46 -> V_51 ) {
V_541 += V_46 -> V_538
* V_46 -> V_539
* V_124 ;
}
}
if ( V_541 == 0 )
goto V_115;
V_540 = V_516 -> V_543 - V_516 -> V_544 ;
if ( V_540 != V_541 )
goto V_115;
V_122 = V_516 -> V_544 ;
for ( V_46 = & V_4 -> V_62 ; V_46 <= & V_4 -> V_58 ; V_46 ++ ) {
if ( V_46 -> V_51 == NULL )
continue;
for ( V_176 = 0 ; V_176 < V_46 -> V_538 ; V_176 ++ ) {
struct V_325 * V_325 ;
void * V_545 = V_46 -> V_51 [ V_176 ] . V_52 ;
int V_546 ;
for ( V_546 = 0 ; V_546 < V_46 -> V_539 ; V_546 ++ ) {
V_325 = F_16 ( V_545 ) ;
V_78 = F_286 ( V_516 , V_122 , V_325 ) ;
if ( F_39 ( V_78 ) )
goto V_115;
V_122 += V_124 ;
V_545 += V_124 ;
}
}
}
F_83 ( & V_4 -> V_519 ) ;
V_516 -> V_547 = & V_548 ;
V_78 = 0 ;
V_115:
F_128 ( & V_4 -> V_336 ) ;
return V_78 ;
}
static void * F_287 ( struct V_549 * V_550 , T_10 * V_551 )
__acquires( T_11 )
{
struct V_186 * V_186 = F_288 ( V_550 ) ;
F_144 () ;
return F_289 ( & V_186 -> V_372 . V_396 , * V_551 ) ;
}
static void * F_290 ( struct V_549 * V_550 , void * V_552 , T_10 * V_551 )
{
struct V_186 * V_186 = F_288 ( V_550 ) ;
return F_291 ( V_552 , & V_186 -> V_372 . V_396 , V_551 ) ;
}
static void F_292 ( struct V_549 * V_550 , void * V_552 )
__releases( T_11 )
{
F_148 () ;
}
static int F_293 ( struct V_549 * V_550 , void * V_552 )
{
if ( V_552 == V_553 )
F_294 ( V_550 , L_9 ) ;
else {
struct V_1 * V_554 = F_295 ( V_552 ) ;
const struct V_3 * V_4 = F_2 ( V_554 ) ;
F_296 ( V_550 ,
L_10 ,
V_554 ,
F_52 ( & V_554 -> V_555 ) ,
V_554 -> V_273 ,
F_182 ( V_4 -> V_168 ) ,
V_4 -> V_80 ,
V_4 -> V_5 ,
F_52 ( & V_554 -> V_160 ) ,
F_297 ( F_298 ( V_550 ) , F_299 ( V_554 ) ) ,
F_300 ( V_554 ) ) ;
}
return 0 ;
}
static int F_301 ( struct V_556 * V_556 , struct V_507 * V_507 )
{
return F_302 ( V_556 , V_507 , & V_557 ,
sizeof( struct V_558 ) ) ;
}
static int T_12 F_303 ( struct V_186 * V_186 )
{
F_223 ( & V_186 -> V_372 . V_373 ) ;
F_304 ( & V_186 -> V_372 . V_396 ) ;
if ( ! F_305 ( L_11 , 0 , V_186 -> V_559 , & V_560 ) )
return - V_201 ;
return 0 ;
}
static void T_13 F_306 ( struct V_186 * V_186 )
{
F_307 ( L_11 , V_186 -> V_559 ) ;
}
static void T_14 F_308 ( void )
{
F_309 ( & V_561 ) ;
F_310 ( & V_562 ) ;
F_311 ( V_389 ) ;
F_312 ( & V_390 ) ;
}
static int T_15 F_313 ( void )
{
int V_563 = F_314 ( & V_390 , 0 ) ;
if ( V_563 != 0 )
goto V_115;
F_315 ( & V_564 ) ;
F_316 ( & V_562 ) ;
F_317 ( & V_561 ) ;
V_115:
return V_563 ;
}
