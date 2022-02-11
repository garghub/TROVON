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
V_35 . V_44 -> V_40 = V_33 ;
F_52 ( F_47 ( & V_35 . V_44 -> V_40 ) ) ;
break;
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
F_52 ( F_47 ( & V_35 . V_44 -> V_40 ) ) ;
return V_35 . V_44 -> V_40 ;
default:
F_53 ( 1 , L_1 ) ;
F_54 () ;
return 0 ;
}
}
static T_3 F_58 ( struct V_1 * V_2 , struct V_45 * V_46 ,
unsigned int V_47 )
{
struct V_48 * V_49 = F_59 ( V_2 ) ;
if ( V_49 &&
( V_47 & V_50 ) &&
F_60 ( V_49 -> V_51 , V_46 ) )
return V_52 ;
if ( F_60 ( V_2 -> V_53 , V_46 ) )
return V_54 ;
return 0 ;
}
static T_3 F_61 ( struct V_13 * V_14 , void * V_32 ,
struct V_1 * V_2 )
{
union V_34 V_35 ;
struct V_45 V_46 ;
T_3 V_55 ;
if ( ! ( V_55 = F_58 ( V_2 , & V_46 , V_14 -> V_56 ) ) )
return 0 ;
V_35 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_57 = V_46 . V_58 ;
V_35 . V_39 -> V_59 = V_46 . V_60 / V_61 ;
break;
case V_41 :
V_35 . V_42 -> V_57 = V_46 . V_58 ;
V_35 . V_42 -> V_62 = V_46 . V_60 ;
break;
case V_43 :
V_35 . V_44 -> V_57 = V_46 . V_58 ;
V_35 . V_44 -> V_62 = V_46 . V_60 ;
break;
default:
F_53 ( 1 , L_1 ) ;
F_54 () ;
}
F_52 ( F_47 ( & V_35 . V_39 -> V_57 ) ) ;
F_55 () ;
return V_55 ;
}
static void * F_62 ( struct V_13 * V_14 ,
struct V_63 * V_64 ,
unsigned int V_65 ,
int V_33 )
{
unsigned int V_66 , V_67 ;
union V_34 V_35 ;
V_66 = V_65 / V_64 -> V_68 ;
V_67 = V_65 % V_64 -> V_68 ;
V_35 . V_36 = V_64 -> V_69 [ V_66 ] . V_70 +
( V_67 * V_64 -> V_71 ) ;
if ( V_33 != F_56 ( V_14 , V_35 . V_36 ) )
return NULL ;
return V_35 . V_36 ;
}
static void * F_63 ( struct V_13 * V_14 ,
struct V_63 * V_64 ,
int V_33 )
{
return F_62 ( V_14 , V_64 , V_64 -> V_72 , V_33 ) ;
}
static void F_64 ( struct V_73 * V_74 )
{
F_65 ( & V_74 -> V_75 ) ;
}
static void F_66 ( struct V_13 * V_14 ,
struct V_76 * V_77 )
{
struct V_73 * V_74 ;
V_74 = F_67 ( & V_14 -> V_78 ) ;
F_68 ( & V_77 -> V_79 ) ;
V_74 -> V_80 = 1 ;
F_69 ( & V_77 -> V_79 ) ;
F_64 ( V_74 ) ;
}
static void F_70 ( struct V_13 * V_14 ,
struct V_73 * V_74 ,
void (* F_71) ( unsigned long ) )
{
F_72 ( & V_74 -> V_75 ) ;
V_74 -> V_75 . V_81 = ( long ) V_14 ;
V_74 -> V_75 . V_82 = F_71 ;
V_74 -> V_75 . V_83 = V_84 ;
}
static void F_73 ( struct V_13 * V_14 )
{
struct V_73 * V_74 ;
V_74 = F_67 ( & V_14 -> V_78 ) ;
F_70 ( V_14 , V_74 , V_85 ) ;
}
static int F_74 ( struct V_13 * V_14 ,
int V_86 )
{
struct V_3 * V_4 ;
unsigned int V_87 = 0 , V_88 = 0 , div = 0 , V_89 = 0 ;
struct V_90 V_91 ;
int V_92 ;
F_75 () ;
V_4 = F_76 ( F_77 ( & V_14 -> V_24 ) , V_14 -> V_93 ) ;
if ( F_2 ( ! V_4 ) ) {
F_78 () ;
return V_94 ;
}
V_92 = F_79 ( V_4 , & V_91 ) ;
F_78 () ;
if ( ! V_92 ) {
if ( V_91 . V_95 . V_96 < V_97 ||
V_91 . V_95 . V_96 == V_98 ) {
return V_94 ;
} else {
V_88 = 1 ;
div = V_91 . V_95 . V_96 / 1000 ;
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
static void F_80 ( struct V_73 * V_99 ,
union V_100 * V_101 )
{
V_99 -> V_102 = V_101 -> V_103 . V_104 ;
}
static void F_81 ( struct V_13 * V_14 ,
struct V_63 * V_64 ,
struct V_105 * V_69 ,
union V_100 * V_101 )
{
struct V_73 * V_99 = F_67 ( V_64 ) ;
struct V_106 * V_107 ;
memset ( V_99 , 0x0 , sizeof( * V_99 ) ) ;
V_99 -> V_108 = 1 ;
V_99 -> V_109 = V_69 ;
V_107 = (struct V_106 * ) V_69 [ 0 ] . V_70 ;
V_99 -> V_110 = V_69 [ 0 ] . V_70 ;
V_99 -> V_111 = V_101 -> V_103 . V_112 ;
V_99 -> V_113 = V_101 -> V_103 . V_114 ;
V_99 -> V_115 = V_14 -> V_116 ;
V_99 -> V_117 = V_14 -> V_37 ;
V_99 -> V_118 = 0 ;
V_14 -> V_119 . V_120 . V_121 = 0 ;
if ( V_101 -> V_103 . V_122 )
V_99 -> V_123 = V_101 -> V_103 . V_122 ;
else
V_99 -> V_123 = F_74 ( V_14 ,
V_101 -> V_103 . V_112 ) ;
V_99 -> V_124 = F_82 ( V_99 -> V_123 ) ;
V_99 -> V_125 = V_101 -> V_103 . V_126 ;
V_99 -> V_127 = V_99 -> V_111 - F_83 ( V_99 -> V_125 ) ;
F_80 ( V_99 , V_101 ) ;
F_73 ( V_14 ) ;
F_84 ( V_99 , V_107 ) ;
}
static void F_85 ( struct V_73 * V_74 )
{
F_86 ( & V_74 -> V_75 ,
V_84 + V_74 -> V_124 ) ;
V_74 -> V_118 = V_74 -> V_128 ;
}
static void V_85 ( unsigned long V_81 )
{
struct V_13 * V_14 = (struct V_13 * ) V_81 ;
struct V_73 * V_74 = F_67 ( & V_14 -> V_78 ) ;
unsigned int V_129 ;
struct V_106 * V_107 ;
F_45 ( & V_14 -> V_24 . V_130 . V_79 ) ;
V_129 = F_87 ( V_74 ) ;
V_107 = F_88 ( V_74 ) ;
if ( F_2 ( V_74 -> V_80 ) )
goto V_131;
if ( F_89 ( V_107 ) ) {
while ( F_90 ( & V_74 -> V_132 ) ) {
F_91 () ;
}
}
if ( V_74 -> V_118 == V_74 -> V_128 ) {
if ( ! V_129 ) {
if ( ! F_89 ( V_107 ) ) {
goto V_133;
}
F_92 ( V_74 , V_14 , V_134 ) ;
if ( ! F_93 ( V_74 , V_14 ) )
goto V_133;
else
goto V_131;
} else {
if ( F_94 ( V_74 , V_107 ) ) {
goto V_133;
} else {
F_84 ( V_74 , V_107 ) ;
goto V_131;
}
}
}
V_133:
F_85 ( V_74 ) ;
V_131:
F_43 ( & V_14 -> V_24 . V_130 . V_79 ) ;
}
static void F_95 ( struct V_73 * V_135 ,
struct V_106 * V_136 , T_3 V_33 )
{
#if V_137 == 1
T_4 * V_138 , * V_139 ;
V_138 = ( T_4 * ) V_136 ;
V_138 += V_140 ;
V_139 = ( T_4 * ) F_96 ( ( unsigned long ) V_135 -> V_141 ) ;
for (; V_138 < V_139 ; V_138 += V_140 )
F_52 ( F_47 ( V_138 ) ) ;
F_55 () ;
#endif
F_97 ( V_136 ) = V_33 ;
#if V_137 == 1
V_138 = ( T_4 * ) V_136 ;
F_52 ( F_47 ( V_138 ) ) ;
F_55 () ;
#endif
}
static void F_98 ( struct V_73 * V_135 ,
struct V_106 * V_136 ,
struct V_13 * V_14 , unsigned int V_142 )
{
T_3 V_33 = V_143 | V_142 ;
struct V_144 * V_145 ;
struct V_146 * V_39 = & V_136 -> V_147 . V_148 ;
struct V_23 * V_24 = & V_14 -> V_24 ;
if ( V_14 -> V_119 . V_120 . V_149 )
V_33 |= V_150 ;
V_145 = (struct V_144 * ) V_135 -> V_151 ;
V_145 -> V_152 = 0 ;
if ( F_89 ( V_136 ) ) {
V_39 -> V_153 . V_154 = V_145 -> V_57 ;
V_39 -> V_153 . V_155 = V_145 -> V_62 ;
} else {
struct V_45 V_46 ;
F_99 ( & V_46 ) ;
V_39 -> V_153 . V_154 = V_46 . V_58 ;
V_39 -> V_153 . V_155 = V_46 . V_60 ;
}
F_55 () ;
F_95 ( V_135 , V_136 , V_33 ) ;
V_24 -> V_156 ( V_24 ) ;
V_135 -> V_128 = F_100 ( V_135 ) ;
}
static void F_101 ( struct V_73 * V_74 )
{
V_74 -> V_157 = 0 ;
}
static void F_84 ( struct V_73 * V_135 ,
struct V_106 * V_136 )
{
struct V_45 V_46 ;
struct V_146 * V_39 = & V_136 -> V_147 . V_148 ;
F_57 () ;
F_102 ( V_136 ) = V_135 -> V_108 ++ ;
F_89 ( V_136 ) = 0 ;
F_103 ( V_136 ) = F_83 ( V_135 -> V_125 ) ;
F_99 ( & V_46 ) ;
V_39 -> V_158 . V_154 = V_46 . V_58 ;
V_39 -> V_158 . V_155 = V_46 . V_60 ;
V_135 -> V_110 = ( char * ) V_136 ;
V_135 -> V_159 = V_135 -> V_110 + F_83 ( V_135 -> V_125 ) ;
F_104 ( V_136 ) = ( T_3 ) F_83 ( V_135 -> V_125 ) ;
F_105 ( V_136 ) = V_160 ;
V_136 -> V_117 = V_135 -> V_117 ;
V_135 -> V_151 = V_135 -> V_159 ;
V_135 -> V_141 = V_135 -> V_110 + V_135 -> V_111 ;
F_101 ( V_135 ) ;
F_85 ( V_135 ) ;
F_55 () ;
}
static void F_106 ( struct V_73 * V_74 ,
struct V_13 * V_14 )
{
V_74 -> V_157 = 1 ;
V_14 -> V_119 . V_120 . V_121 ++ ;
}
static void * F_93 ( struct V_73 * V_74 ,
struct V_13 * V_14 )
{
struct V_106 * V_107 ;
F_57 () ;
V_107 = F_88 ( V_74 ) ;
if ( V_143 & F_97 ( V_107 ) ) {
F_106 ( V_74 , V_14 ) ;
return NULL ;
}
F_84 ( V_74 , V_107 ) ;
return ( void * ) V_74 -> V_159 ;
}
static void F_92 ( struct V_73 * V_74 ,
struct V_13 * V_14 , unsigned int V_33 )
{
struct V_106 * V_107 = F_88 ( V_74 ) ;
if ( F_21 ( V_161 == F_97 ( V_107 ) ) ) {
if ( ! ( V_33 & V_134 ) ) {
while ( F_90 ( & V_74 -> V_132 ) ) {
F_91 () ;
}
}
F_98 ( V_74 , V_107 , V_14 , V_33 ) ;
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
return V_74 -> V_157 ;
}
static void F_107 ( struct V_63 * V_64 )
{
struct V_73 * V_74 = F_67 ( V_64 ) ;
F_108 ( & V_74 -> V_132 ) ;
}
static void F_109 ( struct V_73 * V_74 ,
struct V_144 * V_162 )
{
V_162 -> V_163 . V_164 = F_110 ( V_74 -> V_2 ) ;
}
static void F_111 ( struct V_73 * V_74 ,
struct V_144 * V_162 )
{
V_162 -> V_163 . V_164 = 0 ;
}
static void F_112 ( struct V_73 * V_74 ,
struct V_144 * V_162 )
{
if ( F_113 ( V_74 -> V_2 ) ) {
V_162 -> V_163 . V_165 = F_114 ( V_74 -> V_2 ) ;
V_162 -> V_163 . V_166 = F_115 ( V_74 -> V_2 -> V_167 ) ;
V_162 -> V_40 = V_168 | V_169 ;
} else {
V_162 -> V_163 . V_165 = 0 ;
V_162 -> V_163 . V_166 = 0 ;
V_162 -> V_40 = V_170 ;
}
}
static void F_116 ( struct V_73 * V_74 ,
struct V_144 * V_162 )
{
V_162 -> V_163 . V_171 = 0 ;
F_112 ( V_74 , V_162 ) ;
if ( V_74 -> V_102 & V_172 )
F_109 ( V_74 , V_162 ) ;
else
F_111 ( V_74 , V_162 ) ;
}
static void F_117 ( char * V_173 ,
struct V_73 * V_74 ,
struct V_106 * V_107 ,
unsigned int V_174 )
{
struct V_144 * V_162 ;
V_162 = (struct V_144 * ) V_173 ;
V_162 -> V_152 = F_118 ( V_174 ) ;
V_74 -> V_151 = V_173 ;
V_74 -> V_159 += F_118 ( V_174 ) ;
F_103 ( V_107 ) += F_118 ( V_174 ) ;
F_89 ( V_107 ) += 1 ;
F_119 ( & V_74 -> V_132 ) ;
F_116 ( V_74 , V_162 ) ;
}
static void * F_120 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 ,
unsigned int V_174
)
{
struct V_73 * V_74 ;
struct V_106 * V_107 ;
char * V_173 , * V_139 ;
V_74 = F_67 ( & V_14 -> V_78 ) ;
V_107 = F_88 ( V_74 ) ;
if ( F_87 ( V_74 ) ) {
if ( F_94 ( V_74 , V_107 ) ) {
return NULL ;
} else {
F_84 ( V_74 , V_107 ) ;
}
}
F_121 () ;
V_173 = V_74 -> V_159 ;
V_74 -> V_2 = V_2 ;
V_139 = ( char * ) V_107 + V_74 -> V_111 ;
if ( V_173 + F_118 ( V_174 ) < V_139 ) {
F_117 ( V_173 , V_74 , V_107 , V_174 ) ;
return ( void * ) V_173 ;
}
F_92 ( V_74 , V_14 , 0 ) ;
V_173 = ( char * ) F_93 ( V_74 , V_14 ) ;
if ( V_173 ) {
V_107 = F_88 ( V_74 ) ;
F_117 ( V_173 , V_74 , V_107 , V_174 ) ;
return ( void * ) V_173 ;
}
return NULL ;
}
static void * F_122 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
int V_33 , unsigned int V_174 )
{
char * V_173 = NULL ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_173 = F_62 ( V_14 , & V_14 -> V_78 ,
V_14 -> V_78 . V_72 , V_33 ) ;
return V_173 ;
case V_43 :
return F_120 ( V_14 , V_2 , V_33 , V_174 ) ;
default:
F_53 ( 1 , L_2 ) ;
F_54 () ;
return NULL ;
}
}
static void * F_123 ( struct V_13 * V_14 ,
struct V_63 * V_64 ,
unsigned int V_175 ,
int V_33 )
{
struct V_73 * V_74 = F_67 ( V_64 ) ;
struct V_106 * V_107 = F_124 ( V_74 , V_175 ) ;
if ( V_33 != F_97 ( V_107 ) )
return NULL ;
return V_107 ;
}
static int F_125 ( struct V_63 * V_64 )
{
unsigned int V_151 ;
if ( V_64 -> V_176 . V_128 )
V_151 = V_64 -> V_176 . V_128 - 1 ;
else
V_151 = V_64 -> V_176 . V_113 - 1 ;
return V_151 ;
}
static void * F_126 ( struct V_13 * V_14 ,
struct V_63 * V_64 ,
int V_33 )
{
unsigned int V_177 = F_125 ( V_64 ) ;
return F_123 ( V_14 , V_64 , V_177 , V_33 ) ;
}
static void * F_127 ( struct V_13 * V_14 ,
struct V_63 * V_64 ,
int V_33 )
{
if ( V_14 -> V_37 <= V_41 )
return F_128 ( V_14 , V_64 , V_33 ) ;
return F_126 ( V_14 , V_64 , V_33 ) ;
}
static void F_129 ( struct V_13 * V_14 ,
struct V_63 * V_64 )
{
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
return F_130 ( V_64 ) ;
case V_43 :
default:
F_53 ( 1 , L_1 ) ;
F_54 () ;
return;
}
}
static void * F_128 ( struct V_13 * V_14 ,
struct V_63 * V_64 ,
int V_33 )
{
unsigned int V_177 = V_64 -> V_72 ? V_64 -> V_72 - 1 : V_64 -> V_178 ;
return F_62 ( V_14 , V_64 , V_177 , V_33 ) ;
}
static void F_130 ( struct V_63 * V_179 )
{
V_179 -> V_72 = V_179 -> V_72 != V_179 -> V_178 ? V_179 -> V_72 + 1 : 0 ;
}
static void F_131 ( struct V_63 * V_64 )
{
F_132 ( * V_64 -> V_180 ) ;
}
static void F_133 ( struct V_63 * V_64 )
{
F_134 ( * V_64 -> V_180 ) ;
}
static unsigned int F_135 ( const struct V_63 * V_64 )
{
unsigned int V_181 = 0 ;
int V_182 ;
if ( V_64 -> V_180 == NULL )
return 0 ;
F_136 (cpu)
V_181 += * F_137 ( V_64 -> V_180 , V_182 ) ;
return V_181 ;
}
static int F_138 ( struct V_13 * V_14 )
{
V_14 -> V_78 . V_180 = NULL ;
V_14 -> V_183 . V_180 = F_139 (unsigned int) ;
if ( F_2 ( V_14 -> V_183 . V_180 == NULL ) )
return - V_184 ;
return 0 ;
}
static void F_140 ( struct V_13 * V_14 )
{
F_141 ( V_14 -> V_183 . V_180 ) ;
}
static bool F_142 ( struct V_13 * V_14 , int V_185 )
{
int V_175 , V_174 ;
V_174 = V_14 -> V_78 . V_178 + 1 ;
V_175 = V_14 -> V_78 . V_72 ;
if ( V_185 )
V_175 += V_174 >> V_185 ;
if ( V_175 >= V_174 )
V_175 -= V_174 ;
return F_62 ( V_14 , & V_14 -> V_78 , V_175 , V_161 ) ;
}
static bool F_143 ( struct V_13 * V_14 , int V_185 )
{
int V_175 , V_174 ;
V_174 = V_14 -> V_78 . V_176 . V_113 ;
V_175 = V_14 -> V_78 . V_176 . V_128 ;
if ( V_185 )
V_175 += V_174 >> V_185 ;
if ( V_175 >= V_174 )
V_175 -= V_174 ;
return F_123 ( V_14 , & V_14 -> V_78 , V_175 , V_161 ) ;
}
static int F_144 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_14 -> V_24 ;
int V_8 = V_186 ;
if ( V_14 -> V_27 . F_71 != V_187 ) {
int V_188 = V_24 -> V_189 - F_90 ( & V_24 -> V_190 )
- ( V_2 ? V_2 -> V_191 : 0 ) ;
if ( V_188 > ( V_24 -> V_189 >> V_192 ) )
return V_193 ;
else if ( V_188 > 0 )
return V_194 ;
else
return V_186 ;
}
if ( V_14 -> V_37 == V_43 ) {
if ( F_143 ( V_14 , V_192 ) )
V_8 = V_193 ;
else if ( F_143 ( V_14 , 0 ) )
V_8 = V_194 ;
} else {
if ( F_142 ( V_14 , V_192 ) )
V_8 = V_193 ;
else if ( F_142 ( V_14 , 0 ) )
V_8 = V_194 ;
}
return V_8 ;
}
static int F_145 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
int V_8 ;
bool V_195 ;
F_68 ( & V_14 -> V_24 . V_130 . V_79 ) ;
V_8 = F_144 ( V_14 , V_2 ) ;
V_195 = V_8 == V_193 ;
if ( V_14 -> V_196 == V_195 )
V_14 -> V_196 = ! V_195 ;
F_69 ( & V_14 -> V_24 . V_130 . V_79 ) ;
return V_8 ;
}
static void F_146 ( struct V_23 * V_24 )
{
F_147 ( & V_24 -> V_197 ) ;
F_148 ( F_90 ( & V_24 -> V_190 ) ) ;
F_148 ( F_90 ( & V_24 -> V_198 ) ) ;
if ( ! F_149 ( V_24 , V_199 ) ) {
F_150 ( L_3 , V_24 ) ;
return;
}
F_151 ( V_24 ) ;
}
static bool F_152 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
T_5 V_200 ;
int V_201 , V_202 = 0 ;
V_200 = F_110 ( V_2 ) ;
for ( V_201 = 0 ; V_201 < V_203 ; V_201 ++ )
if ( V_14 -> V_204 -> V_205 [ V_201 ] == V_200 )
V_202 ++ ;
V_14 -> V_204 -> V_205 [ F_153 () % V_203 ] = V_200 ;
return V_202 > ( V_203 >> 1 ) ;
}
static unsigned int F_154 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
return F_155 ( F_156 ( V_2 ) , V_208 ) ;
}
static unsigned int F_157 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
unsigned int V_209 = F_158 ( & V_207 -> V_210 ) ;
return V_209 % V_208 ;
}
static unsigned int F_159 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
return F_9 () % V_208 ;
}
static unsigned int F_160 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
return F_161 ( V_208 ) ;
}
static unsigned int F_162 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_175 , bool V_211 ,
unsigned int V_208 )
{
struct V_13 * V_14 , * V_212 , * V_213 = NULL ;
unsigned int V_201 , V_214 , V_215 = V_186 ;
V_14 = F_35 ( V_207 -> V_216 [ V_175 ] ) ;
if ( V_211 ) {
V_215 = F_145 ( V_14 , V_2 ) ;
if ( V_215 == V_193 ||
( V_215 == V_194 && ! F_152 ( V_14 , V_2 ) ) )
return V_175 ;
V_213 = V_14 ;
}
V_201 = V_214 = F_163 ( int , V_14 -> V_204 -> V_23 , V_208 - 1 ) ;
do {
V_212 = F_35 ( V_207 -> V_216 [ V_201 ] ) ;
if ( V_212 != V_213 && ! V_212 -> V_196 &&
F_145 ( V_212 , V_2 ) == V_193 ) {
if ( V_201 != V_214 )
V_14 -> V_204 -> V_23 = V_201 ;
F_16 ( & V_14 -> V_204 -> V_208 ) ;
if ( V_215 == V_194 )
F_16 ( & V_14 -> V_204 -> V_217 ) ;
return V_201 ;
}
if ( ++ V_201 == V_208 )
V_201 = 0 ;
} while ( V_201 != V_214 );
F_16 ( & V_14 -> V_204 -> V_218 ) ;
return V_175 ;
}
static unsigned int F_164 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
return F_165 ( V_2 ) % V_208 ;
}
static unsigned int F_166 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
struct V_219 * V_220 ;
unsigned int V_8 = 0 ;
F_19 () ;
V_220 = F_20 ( V_207 -> V_219 ) ;
if ( V_220 )
V_8 = F_167 ( V_220 , V_2 ) % V_208 ;
F_23 () ;
return V_8 ;
}
static bool F_168 ( struct V_206 * V_207 , T_1 V_221 )
{
return V_207 -> V_47 & ( V_221 >> 8 ) ;
}
static int F_169 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_222 * V_223 , struct V_3 * V_224 )
{
struct V_206 * V_207 = V_223 -> V_225 ;
unsigned int V_208 = F_170 ( V_207 -> V_226 ) ;
struct V_227 * V_227 = F_171 ( & V_207 -> V_227 ) ;
struct V_13 * V_14 ;
unsigned int V_175 ;
if ( ! F_172 ( F_173 ( V_4 ) , V_227 ) || ! V_208 ) {
F_15 ( V_2 ) ;
return 0 ;
}
if ( F_168 ( V_207 , V_228 ) ) {
V_2 = F_174 ( V_227 , V_2 , V_229 ) ;
if ( ! V_2 )
return 0 ;
}
switch ( V_207 -> type ) {
case V_230 :
default:
V_175 = F_154 ( V_207 , V_2 , V_208 ) ;
break;
case V_231 :
V_175 = F_157 ( V_207 , V_2 , V_208 ) ;
break;
case V_232 :
V_175 = F_159 ( V_207 , V_2 , V_208 ) ;
break;
case V_233 :
V_175 = F_160 ( V_207 , V_2 , V_208 ) ;
break;
case V_234 :
V_175 = F_164 ( V_207 , V_2 , V_208 ) ;
break;
case V_235 :
V_175 = F_162 ( V_207 , V_2 , 0 , false , V_208 ) ;
break;
case V_236 :
case V_237 :
V_175 = F_166 ( V_207 , V_2 , V_208 ) ;
break;
}
if ( F_168 ( V_207 , V_238 ) )
V_175 = F_162 ( V_207 , V_2 , V_175 , true , V_208 ) ;
V_14 = F_35 ( V_207 -> V_216 [ V_175 ] ) ;
return V_14 -> V_27 . F_71 ( V_2 , V_4 , & V_14 -> V_27 , V_224 ) ;
}
static void F_36 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_206 * V_207 = V_14 -> V_26 ;
F_45 ( & V_207 -> V_79 ) ;
V_207 -> V_216 [ V_207 -> V_226 ] = V_24 ;
F_55 () ;
V_207 -> V_226 ++ ;
if ( V_207 -> V_226 == 1 )
F_37 ( & V_207 -> V_27 ) ;
F_43 ( & V_207 -> V_79 ) ;
}
static void F_40 ( struct V_23 * V_24 , struct V_13 * V_14 )
{
struct V_206 * V_207 = V_14 -> V_26 ;
int V_201 ;
F_45 ( & V_207 -> V_79 ) ;
for ( V_201 = 0 ; V_201 < V_207 -> V_226 ; V_201 ++ ) {
if ( V_207 -> V_216 [ V_201 ] == V_24 )
break;
}
F_175 ( V_201 >= V_207 -> V_226 ) ;
V_207 -> V_216 [ V_201 ] = V_207 -> V_216 [ V_207 -> V_226 - 1 ] ;
V_207 -> V_226 -- ;
if ( V_207 -> V_226 == 0 )
F_41 ( & V_207 -> V_27 ) ;
F_43 ( & V_207 -> V_79 ) ;
}
static bool F_176 ( struct V_222 * V_239 , struct V_23 * V_24 )
{
if ( V_24 -> V_240 != V_241 )
return false ;
return V_239 -> V_225 == F_35 ( V_24 ) -> V_26 ;
}
static void F_177 ( struct V_206 * V_207 )
{
switch ( V_207 -> type ) {
case V_231 :
F_178 ( & V_207 -> V_210 , 0 ) ;
break;
case V_236 :
case V_237 :
F_27 ( V_207 -> V_219 , NULL ) ;
break;
}
}
static void F_179 ( struct V_206 * V_207 , struct V_219 * V_242 )
{
struct V_219 * V_243 ;
F_45 ( & V_207 -> V_79 ) ;
V_243 = F_180 ( V_207 -> V_219 , F_181 ( & V_207 -> V_79 ) ) ;
F_25 ( V_207 -> V_219 , V_242 ) ;
F_43 ( & V_207 -> V_79 ) ;
if ( V_243 ) {
F_44 () ;
F_182 ( V_243 ) ;
}
}
static int F_183 ( struct V_13 * V_14 , char T_6 * V_81 ,
unsigned int V_174 )
{
struct V_219 * V_242 ;
struct V_244 V_245 ;
int V_8 ;
if ( F_149 ( & V_14 -> V_24 , V_246 ) )
return - V_247 ;
if ( V_174 != sizeof( V_245 ) )
return - V_248 ;
if ( F_184 ( & V_245 , V_81 , V_174 ) )
return - V_249 ;
V_8 = F_185 ( & V_242 , & V_245 , NULL , false ) ;
if ( V_8 )
return V_8 ;
F_179 ( V_14 -> V_26 , V_242 ) ;
return 0 ;
}
static int F_186 ( struct V_13 * V_14 , char T_6 * V_81 ,
unsigned int V_174 )
{
struct V_219 * V_242 ;
T_5 V_250 ;
if ( F_149 ( & V_14 -> V_24 , V_246 ) )
return - V_247 ;
if ( V_174 != sizeof( V_250 ) )
return - V_248 ;
if ( F_184 ( & V_250 , V_81 , V_174 ) )
return - V_249 ;
V_242 = F_187 ( V_250 , V_251 ) ;
if ( F_188 ( V_242 ) )
return F_189 ( V_242 ) ;
F_179 ( V_14 -> V_26 , V_242 ) ;
return 0 ;
}
static int F_190 ( struct V_13 * V_14 , char T_6 * V_81 ,
unsigned int V_174 )
{
switch ( V_14 -> V_26 -> type ) {
case V_236 :
return F_183 ( V_14 , V_81 , V_174 ) ;
case V_237 :
return F_186 ( V_14 , V_81 , V_174 ) ;
default:
return - V_248 ;
} ;
}
static void F_191 ( struct V_206 * V_207 )
{
switch ( V_207 -> type ) {
case V_236 :
case V_237 :
F_179 ( V_207 , NULL ) ;
} ;
}
static int F_192 ( struct V_23 * V_24 , T_1 V_252 , T_1 V_253 )
{
struct V_254 * V_204 = NULL ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_206 * V_207 , * V_255 ;
T_4 type = V_253 & 0xff ;
T_4 V_47 = V_253 >> 8 ;
int V_92 ;
switch ( type ) {
case V_235 :
if ( V_253 & V_238 )
return - V_248 ;
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_236 :
case V_237 :
break;
default:
return - V_248 ;
}
F_193 ( & V_256 ) ;
V_92 = - V_248 ;
if ( ! V_14 -> V_25 )
goto V_131;
V_92 = - V_257 ;
if ( V_14 -> V_26 )
goto V_131;
if ( type == V_235 ||
( V_253 & V_238 ) ) {
V_92 = - V_258 ;
V_204 = F_194 ( sizeof( * V_204 ) , V_259 ) ;
if ( ! V_204 )
goto V_131;
F_195 ( & V_204 -> V_208 , 0 ) ;
F_195 ( & V_204 -> V_217 , 0 ) ;
F_195 ( & V_204 -> V_218 , 0 ) ;
V_14 -> V_204 = V_204 ;
}
V_255 = NULL ;
F_196 (f, &fanout_list, list) {
if ( V_207 -> V_252 == V_252 &&
F_171 ( & V_207 -> V_227 ) == F_77 ( V_24 ) ) {
V_255 = V_207 ;
break;
}
}
V_92 = - V_248 ;
if ( V_255 && V_255 -> V_47 != V_47 )
goto V_131;
if ( ! V_255 ) {
V_92 = - V_258 ;
V_255 = F_194 ( sizeof( * V_255 ) , V_259 ) ;
if ( ! V_255 )
goto V_131;
F_197 ( & V_255 -> V_227 , F_77 ( V_24 ) ) ;
V_255 -> V_252 = V_252 ;
V_255 -> type = type ;
V_255 -> V_47 = V_47 ;
F_198 ( & V_255 -> V_260 ) ;
F_199 ( & V_255 -> V_79 ) ;
F_178 ( & V_255 -> V_261 , 0 ) ;
F_177 ( V_255 ) ;
V_255 -> V_27 . type = V_14 -> V_27 . type ;
V_255 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_255 -> V_27 . F_71 = F_169 ;
V_255 -> V_27 . V_225 = V_255 ;
V_255 -> V_27 . V_262 = F_176 ;
F_200 ( & V_255 -> V_260 , & V_263 ) ;
}
V_92 = - V_248 ;
if ( V_255 -> type == type &&
V_255 -> V_27 . type == V_14 -> V_27 . type &&
V_255 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_92 = - V_264 ;
if ( F_90 ( & V_255 -> V_261 ) < V_265 ) {
F_41 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_255 ;
F_119 ( & V_255 -> V_261 ) ;
F_36 ( V_24 , V_14 ) ;
V_92 = 0 ;
}
}
V_131:
if ( V_92 && V_204 ) {
F_201 ( V_204 ) ;
V_14 -> V_204 = NULL ;
}
F_202 ( & V_256 ) ;
return V_92 ;
}
static struct V_206 * F_203 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_206 * V_207 ;
F_193 ( & V_256 ) ;
V_207 = V_14 -> V_26 ;
if ( V_207 ) {
V_14 -> V_26 = NULL ;
if ( F_204 ( & V_207 -> V_261 ) )
F_205 ( & V_207 -> V_260 ) ;
else
V_207 = NULL ;
if ( V_14 -> V_204 )
F_206 ( V_14 -> V_204 , V_266 ) ;
}
F_202 ( & V_256 ) ;
return V_207 ;
}
static bool F_207 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( F_2 ( V_4 -> type != V_267 ) )
return false ;
F_208 ( V_2 ) ;
return F_21 ( F_209 ( V_2 ) -> V_268 == F_210 ( V_269 ) ) ;
}
static int F_211 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_222 * V_223 , struct V_3 * V_224 )
{
struct V_23 * V_24 ;
struct V_270 * V_271 ;
V_24 = V_223 -> V_225 ;
if ( V_2 -> V_272 == V_273 )
goto V_131;
if ( ! F_172 ( F_173 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_131;
V_2 = F_212 ( V_2 , V_274 ) ;
if ( V_2 == NULL )
goto V_275;
F_213 ( V_2 ) ;
F_214 ( V_2 ) ;
V_271 = & F_215 ( V_2 ) -> V_276 . V_277 ;
F_216 ( V_2 , V_2 -> V_81 - F_217 ( V_2 ) ) ;
V_271 -> V_278 = V_4 -> type ;
F_218 ( V_271 -> V_279 , V_4 -> V_280 , sizeof( V_271 -> V_279 ) ) ;
V_271 -> V_281 = V_2 -> V_282 ;
if ( F_219 ( V_24 , V_2 ) == 0 )
return 0 ;
V_131:
F_15 ( V_2 ) ;
V_275:
return 0 ;
}
static int F_220 ( struct V_283 * V_23 , struct V_284 * V_285 ,
T_7 V_174 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_221 ( struct V_270 * , V_286 , V_285 -> V_287 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
struct V_288 V_289 ;
T_8 V_290 = 0 ;
int V_92 ;
int V_291 = 0 ;
if ( V_286 ) {
if ( V_285 -> V_292 < sizeof( struct V_293 ) )
return - V_248 ;
if ( V_285 -> V_292 == sizeof( struct V_270 ) )
V_290 = V_286 -> V_281 ;
} else
return - V_294 ;
V_286 -> V_279 [ sizeof( V_286 -> V_279 ) - 1 ] = 0 ;
V_295:
F_19 () ;
V_4 = F_222 ( F_77 ( V_24 ) , V_286 -> V_279 ) ;
V_92 = - V_296 ;
if ( V_4 == NULL )
goto V_297;
V_92 = - V_298 ;
if ( ! ( V_4 -> V_47 & V_299 ) )
goto V_297;
if ( F_2 ( F_149 ( V_24 , V_300 ) ) ) {
if ( ! F_223 ( V_4 ) ) {
V_92 = - V_301 ;
goto V_297;
}
V_291 = 4 ;
}
V_92 = - V_302 ;
if ( V_174 > V_4 -> V_303 + V_4 -> V_304 + V_305 + V_291 )
goto V_297;
if ( ! V_2 ) {
T_7 V_306 = F_224 ( V_4 ) ;
int V_307 = V_4 -> V_308 ;
unsigned int V_309 = V_4 -> V_310 ? V_4 -> V_304 : 0 ;
F_23 () ;
V_2 = F_225 ( V_24 , V_174 + V_306 + V_307 , 0 , V_259 ) ;
if ( V_2 == NULL )
return - V_184 ;
F_226 ( V_2 , V_306 ) ;
F_227 ( V_2 ) ;
if ( V_309 ) {
V_2 -> V_81 -= V_309 ;
V_2 -> V_311 -= V_309 ;
if ( V_174 < V_309 )
F_227 ( V_2 ) ;
}
V_92 = F_228 ( F_229 ( V_2 , V_174 ) , V_285 , V_174 ) ;
if ( V_92 )
goto V_312;
goto V_295;
}
if ( ! F_230 ( V_4 , V_2 -> V_81 , V_174 ) ) {
V_92 = - V_248 ;
goto V_297;
}
if ( V_174 > ( V_4 -> V_303 + V_4 -> V_304 + V_291 ) &&
! F_207 ( V_4 , V_2 ) ) {
V_92 = - V_302 ;
goto V_297;
}
V_289 . V_313 = V_24 -> V_314 ;
if ( V_285 -> V_315 ) {
V_92 = F_231 ( V_24 , V_285 , & V_289 ) ;
if ( F_2 ( V_92 ) )
goto V_297;
}
V_2 -> V_282 = V_290 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_316 = V_24 -> V_317 ;
V_2 -> V_318 = V_24 -> V_319 ;
F_232 ( V_24 , V_289 . V_313 , & F_233 ( V_2 ) -> V_320 ) ;
if ( F_2 ( V_291 == 4 ) )
V_2 -> V_321 = 1 ;
F_234 ( V_2 , 0 ) ;
F_235 ( V_2 ) ;
F_23 () ;
return V_174 ;
V_297:
F_23 () ;
V_312:
F_15 ( V_2 ) ;
return V_92 ;
}
static unsigned int F_236 ( struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_322 )
{
struct V_323 * V_324 ;
F_19 () ;
V_324 = F_20 ( V_24 -> V_323 ) ;
if ( V_324 != NULL )
V_322 = F_167 ( V_324 -> V_220 , V_2 ) ;
F_23 () ;
return V_322 ;
}
static int F_237 ( struct V_284 * V_285 , const struct V_1 * V_2 ,
T_7 * V_174 )
{
struct V_325 V_326 ;
if ( * V_174 < sizeof( V_326 ) )
return - V_248 ;
* V_174 -= sizeof( V_326 ) ;
if ( F_238 ( V_2 , & V_326 , F_239 () , true ) )
return - V_248 ;
return F_240 ( V_285 , ( void * ) & V_326 , sizeof( V_326 ) ) ;
}
static int F_241 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_222 * V_223 , struct V_3 * V_224 )
{
struct V_23 * V_24 ;
struct V_327 * V_328 ;
struct V_13 * V_14 ;
T_4 * V_329 = V_2 -> V_81 ;
int V_330 = V_2 -> V_174 ;
unsigned int V_331 , V_322 ;
bool V_332 = false ;
if ( V_2 -> V_272 == V_273 )
goto V_10;
V_24 = V_223 -> V_225 ;
V_14 = F_35 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_310 ) {
if ( V_24 -> V_333 != V_334 )
F_216 ( V_2 , V_2 -> V_81 - F_217 ( V_2 ) ) ;
else if ( V_2 -> V_272 == V_335 ) {
F_242 ( V_2 , F_243 ( V_2 ) ) ;
}
}
V_331 = V_2 -> V_174 ;
V_322 = F_236 ( V_2 , V_24 , V_331 ) ;
if ( ! V_322 )
goto V_336;
if ( V_331 > V_322 )
V_331 = V_322 ;
if ( F_90 ( & V_24 -> V_190 ) >= V_24 -> V_189 )
goto V_337;
if ( F_244 ( V_2 ) ) {
struct V_1 * V_338 = F_245 ( V_2 , V_274 ) ;
if ( V_338 == NULL )
goto V_337;
if ( V_329 != V_2 -> V_81 ) {
V_2 -> V_81 = V_329 ;
V_2 -> V_174 = V_330 ;
}
F_246 ( V_2 ) ;
V_2 = V_338 ;
}
F_247 ( sizeof( * F_215 ( V_2 ) ) + V_339 - 8 ) ;
V_328 = & F_215 ( V_2 ) -> V_276 . V_340 ;
V_328 -> V_341 = V_4 -> type ;
V_328 -> V_342 = V_2 -> V_272 ;
if ( F_2 ( V_14 -> V_343 ) )
V_328 -> V_344 = V_224 -> V_93 ;
else
V_328 -> V_344 = V_4 -> V_93 ;
V_328 -> V_345 = F_248 ( V_2 , V_328 -> V_346 ) ;
F_215 ( V_2 ) -> V_276 . V_347 = V_2 -> V_174 ;
if ( F_249 ( V_2 , V_331 ) )
goto V_337;
F_250 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_213 ( V_2 ) ;
F_214 ( V_2 ) ;
F_45 ( & V_24 -> V_130 . V_79 ) ;
V_14 -> V_119 . V_348 . V_349 ++ ;
F_251 ( V_24 , V_2 ) ;
F_252 ( & V_24 -> V_130 , V_2 ) ;
F_43 ( & V_24 -> V_130 . V_79 ) ;
V_24 -> V_156 ( V_24 ) ;
return 0 ;
V_337:
V_332 = true ;
F_45 ( & V_24 -> V_130 . V_79 ) ;
V_14 -> V_119 . V_348 . V_149 ++ ;
F_119 ( & V_24 -> V_350 ) ;
F_43 ( & V_24 -> V_130 . V_79 ) ;
V_336:
if ( V_329 != V_2 -> V_81 && F_244 ( V_2 ) ) {
V_2 -> V_81 = V_329 ;
V_2 -> V_174 = V_330 ;
}
V_10:
if ( ! V_332 )
F_246 ( V_2 ) ;
else
F_15 ( V_2 ) ;
return 0 ;
}
static int V_187 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_222 * V_223 , struct V_3 * V_224 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
struct V_327 * V_328 ;
union V_34 V_35 ;
T_4 * V_329 = V_2 -> V_81 ;
int V_330 = V_2 -> V_174 ;
unsigned int V_331 , V_322 ;
unsigned long V_33 = V_143 ;
unsigned short V_351 , V_352 , V_115 ;
struct V_1 * V_353 = NULL ;
struct V_45 V_46 ;
T_3 V_55 ;
bool V_332 = false ;
F_253 ( F_254 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_253 ( F_254 ( sizeof( * V_35 . V_44 ) ) != 48 ) ;
if ( V_2 -> V_272 == V_273 )
goto V_10;
V_24 = V_223 -> V_225 ;
V_14 = F_35 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_310 ) {
if ( V_24 -> V_333 != V_334 )
F_216 ( V_2 , V_2 -> V_81 - F_217 ( V_2 ) ) ;
else if ( V_2 -> V_272 == V_335 ) {
F_242 ( V_2 , F_243 ( V_2 ) ) ;
}
}
V_331 = V_2 -> V_174 ;
V_322 = F_236 ( V_2 , V_24 , V_331 ) ;
if ( ! V_322 )
goto V_336;
if ( V_2 -> V_354 == V_355 )
V_33 |= V_356 ;
else if ( V_2 -> V_272 != V_335 &&
( V_2 -> V_354 == V_357 ||
F_255 ( V_2 ) ) )
V_33 |= V_358 ;
if ( V_331 > V_322 )
V_331 = V_322 ;
if ( V_24 -> V_333 == V_334 ) {
V_351 = V_352 = F_254 ( V_14 -> V_116 ) + 16 +
V_14 -> V_359 ;
} else {
unsigned int V_360 = F_243 ( V_2 ) ;
V_352 = F_254 ( V_14 -> V_116 +
( V_360 < 16 ? 16 : V_360 ) ) +
V_14 -> V_359 ;
if ( V_14 -> V_361 )
V_352 += sizeof( struct V_325 ) ;
V_351 = V_352 - V_360 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_351 + V_331 > V_14 -> V_78 . V_71 ) {
if ( V_14 -> V_362 &&
F_90 ( & V_24 -> V_190 ) < V_24 -> V_189 ) {
if ( F_244 ( V_2 ) ) {
V_353 = F_245 ( V_2 , V_274 ) ;
} else {
V_353 = F_256 ( V_2 ) ;
V_329 = V_2 -> V_81 ;
}
if ( V_353 )
F_250 ( V_353 , V_24 ) ;
}
V_331 = V_14 -> V_78 . V_71 - V_351 ;
if ( ( int ) V_331 < 0 )
V_331 = 0 ;
}
} else if ( F_2 ( V_351 + V_331 >
F_67 ( & V_14 -> V_78 ) -> V_127 ) ) {
T_5 V_363 ;
V_363 = F_67 ( & V_14 -> V_78 ) -> V_127 - V_351 ;
F_257 ( L_4 ,
V_331 , V_363 , V_351 ) ;
V_331 = V_363 ;
if ( F_2 ( ( int ) V_331 < 0 ) ) {
V_331 = 0 ;
V_351 = F_67 ( & V_14 -> V_78 ) -> V_127 ;
}
}
F_45 ( & V_24 -> V_130 . V_79 ) ;
V_35 . V_36 = F_122 ( V_14 , V_2 ,
V_161 , ( V_351 + V_331 ) ) ;
if ( ! V_35 . V_36 )
goto V_364;
if ( V_14 -> V_37 <= V_41 ) {
F_129 ( V_14 , & V_14 -> V_78 ) ;
if ( V_14 -> V_119 . V_348 . V_149 )
V_33 |= V_150 ;
}
V_14 -> V_119 . V_348 . V_349 ++ ;
if ( V_353 ) {
V_33 |= V_365 ;
F_252 ( & V_24 -> V_130 , V_353 ) ;
}
F_43 ( & V_24 -> V_130 . V_79 ) ;
if ( V_14 -> V_361 ) {
if ( F_238 ( V_2 , V_35 . V_36 + V_351 -
sizeof( struct V_325 ) ,
F_239 () , true ) ) {
F_45 ( & V_24 -> V_130 . V_79 ) ;
goto V_364;
}
}
F_258 ( V_2 , 0 , V_35 . V_36 + V_351 , V_331 ) ;
if ( ! ( V_55 = F_58 ( V_2 , & V_46 , V_14 -> V_56 ) ) )
F_99 ( & V_46 ) ;
V_33 |= V_55 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_366 = V_2 -> V_174 ;
V_35 . V_39 -> V_367 = V_331 ;
V_35 . V_39 -> V_368 = V_351 ;
V_35 . V_39 -> V_369 = V_352 ;
V_35 . V_39 -> V_57 = V_46 . V_58 ;
V_35 . V_39 -> V_59 = V_46 . V_60 / V_61 ;
V_115 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_366 = V_2 -> V_174 ;
V_35 . V_42 -> V_367 = V_331 ;
V_35 . V_42 -> V_368 = V_351 ;
V_35 . V_42 -> V_369 = V_352 ;
V_35 . V_42 -> V_57 = V_46 . V_58 ;
V_35 . V_42 -> V_62 = V_46 . V_60 ;
if ( F_113 ( V_2 ) ) {
V_35 . V_42 -> V_165 = F_114 ( V_2 ) ;
V_35 . V_42 -> V_166 = F_115 ( V_2 -> V_167 ) ;
V_33 |= V_168 | V_169 ;
} else {
V_35 . V_42 -> V_165 = 0 ;
V_35 . V_42 -> V_166 = 0 ;
}
memset ( V_35 . V_42 -> V_171 , 0 , sizeof( V_35 . V_42 -> V_171 ) ) ;
V_115 = sizeof( * V_35 . V_42 ) ;
break;
case V_43 :
V_35 . V_44 -> V_40 |= V_33 ;
V_35 . V_44 -> V_366 = V_2 -> V_174 ;
V_35 . V_44 -> V_367 = V_331 ;
V_35 . V_44 -> V_368 = V_351 ;
V_35 . V_44 -> V_369 = V_352 ;
V_35 . V_44 -> V_57 = V_46 . V_58 ;
V_35 . V_44 -> V_62 = V_46 . V_60 ;
memset ( V_35 . V_44 -> V_171 , 0 , sizeof( V_35 . V_44 -> V_171 ) ) ;
V_115 = sizeof( * V_35 . V_44 ) ;
break;
default:
F_54 () ;
}
V_328 = V_35 . V_36 + F_254 ( V_115 ) ;
V_328 -> V_345 = F_248 ( V_2 , V_328 -> V_346 ) ;
V_328 -> V_370 = V_371 ;
V_328 -> V_341 = V_4 -> type ;
V_328 -> V_372 = V_2 -> V_282 ;
V_328 -> V_342 = V_2 -> V_272 ;
if ( F_2 ( V_14 -> V_343 ) )
V_328 -> V_344 = V_224 -> V_93 ;
else
V_328 -> V_344 = V_4 -> V_93 ;
F_121 () ;
#if V_137 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_4 * V_138 , * V_139 ;
V_139 = ( T_4 * ) F_96 ( ( unsigned long ) V_35 . V_36 +
V_351 + V_331 ) ;
for ( V_138 = V_35 . V_36 ; V_138 < V_139 ; V_138 += V_140 )
F_52 ( F_47 ( V_138 ) ) ;
}
F_55 () ;
#endif
if ( V_14 -> V_37 <= V_41 ) {
F_51 ( V_14 , V_35 . V_36 , V_33 ) ;
V_24 -> V_156 ( V_24 ) ;
} else {
F_107 ( & V_14 -> V_78 ) ;
}
V_336:
if ( V_329 != V_2 -> V_81 && F_244 ( V_2 ) ) {
V_2 -> V_81 = V_329 ;
V_2 -> V_174 = V_330 ;
}
V_10:
if ( ! V_332 )
F_246 ( V_2 ) ;
else
F_15 ( V_2 ) ;
return 0 ;
V_364:
V_332 = true ;
V_14 -> V_119 . V_348 . V_149 ++ ;
F_43 ( & V_24 -> V_130 . V_79 ) ;
V_24 -> V_156 ( V_24 ) ;
F_15 ( V_353 ) ;
goto V_336;
}
static void F_259 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_35 ( V_2 -> V_24 ) ;
if ( F_21 ( V_14 -> V_183 . V_69 ) ) {
void * V_373 ;
T_3 V_46 ;
V_373 = F_233 ( V_2 ) -> V_374 ;
F_133 ( & V_14 -> V_183 ) ;
V_46 = F_61 ( V_14 , V_373 , V_2 ) ;
F_51 ( V_14 , V_373 , V_170 | V_46 ) ;
}
F_260 ( V_2 ) ;
}
static void F_261 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( V_4 -> type == V_267 ) {
F_208 ( V_2 ) ;
V_2 -> V_282 = F_209 ( V_2 ) -> V_268 ;
}
}
static int F_262 ( struct V_325 * V_326 , T_7 V_174 )
{
if ( ( V_326 -> V_47 & V_375 ) &&
( F_263 ( F_239 () , V_326 -> V_376 ) +
F_263 ( F_239 () , V_326 -> V_377 ) + 2 >
F_263 ( F_239 () , V_326 -> V_378 ) ) )
V_326 -> V_378 = F_264 ( F_239 () ,
F_263 ( F_239 () , V_326 -> V_376 ) +
F_263 ( F_239 () , V_326 -> V_377 ) + 2 ) ;
if ( F_263 ( F_239 () , V_326 -> V_378 ) > V_174 )
return - V_248 ;
return 0 ;
}
static int F_265 ( struct V_284 * V_285 , T_7 * V_174 ,
struct V_325 * V_326 )
{
if ( * V_174 < sizeof( * V_326 ) )
return - V_248 ;
* V_174 -= sizeof( * V_326 ) ;
if ( ! F_266 ( V_326 , sizeof( * V_326 ) , & V_285 -> V_379 ) )
return - V_249 ;
return F_262 ( V_326 , * V_174 ) ;
}
static int F_267 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , void * V_81 , int V_366 ,
T_8 V_290 , unsigned char * V_31 , int V_380 , int V_381 ,
const struct V_288 * V_289 )
{
union V_34 V_373 ;
int V_382 , V_383 , V_174 , V_384 , V_385 ;
struct V_283 * V_23 = V_14 -> V_24 . V_386 ;
struct V_30 * V_30 ;
int V_92 ;
V_373 . V_36 = V_32 ;
V_2 -> V_282 = V_290 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_316 = V_14 -> V_24 . V_317 ;
V_2 -> V_318 = V_14 -> V_24 . V_319 ;
F_232 ( & V_14 -> V_24 , V_289 -> V_313 , & F_233 ( V_2 ) -> V_320 ) ;
F_233 ( V_2 ) -> V_374 = V_373 . V_36 ;
F_226 ( V_2 , V_380 ) ;
F_227 ( V_2 ) ;
V_382 = V_366 ;
if ( V_23 -> type == V_334 ) {
V_92 = F_268 ( V_2 , V_4 , F_115 ( V_290 ) , V_31 ,
NULL , V_366 ) ;
if ( F_2 ( V_92 < 0 ) )
return - V_248 ;
} else if ( V_381 ) {
int V_115 = F_163 ( int , V_381 , V_366 ) ;
F_216 ( V_2 , V_4 -> V_304 ) ;
F_229 ( V_2 , V_381 - V_4 -> V_304 ) ;
V_92 = F_269 ( V_2 , 0 , V_81 , V_115 ) ;
if ( F_2 ( V_92 ) )
return V_92 ;
if ( ! F_230 ( V_4 , V_2 -> V_81 , V_115 ) )
return - V_248 ;
if ( ! V_2 -> V_282 )
F_261 ( V_4 , V_2 ) ;
V_81 += V_115 ;
V_382 -= V_115 ;
}
V_383 = F_270 ( V_81 ) ;
V_385 = V_140 - V_383 ;
V_174 = ( ( V_382 > V_385 ) ? V_385 : V_382 ) ;
V_2 -> V_387 = V_382 ;
V_2 -> V_174 += V_382 ;
V_2 -> V_191 += V_382 ;
F_271 ( V_382 , & V_14 -> V_24 . V_198 ) ;
while ( F_21 ( V_382 ) ) {
V_384 = F_233 ( V_2 ) -> V_384 ;
if ( F_2 ( V_384 >= V_388 ) ) {
F_150 ( L_5 ,
V_388 ) ;
return - V_249 ;
}
V_30 = F_47 ( V_81 ) ;
V_81 += V_174 ;
F_52 ( V_30 ) ;
F_272 ( V_30 ) ;
F_273 ( V_2 , V_384 , V_30 , V_383 , V_174 ) ;
V_382 -= V_174 ;
V_383 = 0 ;
V_385 = V_140 ;
V_174 = ( ( V_382 > V_385 ) ? V_385 : V_382 ) ;
}
F_234 ( V_2 , 0 ) ;
return V_366 ;
}
static int F_274 ( struct V_13 * V_14 , void * V_32 ,
int V_389 , void * * V_81 )
{
union V_34 V_373 ;
int V_366 , V_390 ;
V_373 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( V_373 . V_44 -> V_152 != 0 ) {
F_275 ( L_6 ) ;
return - V_248 ;
}
V_366 = V_373 . V_44 -> V_366 ;
break;
case V_41 :
V_366 = V_373 . V_42 -> V_366 ;
break;
default:
V_366 = V_373 . V_39 -> V_366 ;
break;
}
if ( F_2 ( V_366 > V_389 ) ) {
F_150 ( L_7 , V_366 , V_389 ) ;
return - V_302 ;
}
if ( F_2 ( V_14 -> V_391 ) ) {
int V_392 , V_393 ;
V_392 = V_14 -> V_116 - sizeof( struct V_327 ) ;
V_393 = V_14 -> V_183 . V_71 - V_366 ;
if ( V_14 -> V_24 . V_333 == V_334 ) {
switch ( V_14 -> V_37 ) {
case V_43 :
V_390 = V_373 . V_44 -> V_369 ;
break;
case V_41 :
V_390 = V_373 . V_42 -> V_369 ;
break;
default:
V_390 = V_373 . V_39 -> V_369 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_43 :
V_390 = V_373 . V_44 -> V_368 ;
break;
case V_41 :
V_390 = V_373 . V_42 -> V_368 ;
break;
default:
V_390 = V_373 . V_39 -> V_368 ;
break;
}
}
if ( F_2 ( ( V_390 < V_392 ) || ( V_393 < V_390 ) ) )
return - V_248 ;
} else {
V_390 = V_14 -> V_116 - sizeof( struct V_327 ) ;
}
* V_81 = V_32 + V_390 ;
return V_366 ;
}
static int F_276 ( struct V_13 * V_14 , struct V_284 * V_285 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_325 * V_326 = NULL ;
struct V_288 V_289 ;
T_8 V_290 ;
int V_92 , V_394 = 0 ;
void * V_373 ;
F_221 ( struct V_327 * , V_286 , V_285 -> V_287 ) ;
bool V_395 = ! ( V_285 -> V_396 & V_397 ) ;
int V_366 , V_389 ;
unsigned char * V_31 ;
void * V_81 ;
int V_398 = 0 ;
int V_33 = V_170 ;
int V_380 , V_307 , V_381 = 0 ;
F_193 ( & V_14 -> V_399 ) ;
if ( F_21 ( V_286 == NULL ) ) {
V_4 = F_18 ( V_14 ) ;
V_290 = V_14 -> V_208 ;
V_31 = NULL ;
} else {
V_92 = - V_248 ;
if ( V_285 -> V_292 < sizeof( struct V_327 ) )
goto V_131;
if ( V_285 -> V_292 < ( V_286 -> V_345
+ F_277 ( struct V_327 ,
V_346 ) ) )
goto V_131;
V_290 = V_286 -> V_372 ;
V_31 = V_286 -> V_346 ;
V_4 = F_278 ( F_77 ( & V_14 -> V_24 ) , V_286 -> V_344 ) ;
}
V_289 . V_313 = V_14 -> V_24 . V_314 ;
if ( V_285 -> V_315 ) {
V_92 = F_231 ( & V_14 -> V_24 , V_285 , & V_289 ) ;
if ( F_2 ( V_92 ) )
goto V_131;
}
V_92 = - V_400 ;
if ( F_2 ( V_4 == NULL ) )
goto V_131;
V_92 = - V_298 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_299 ) ) )
goto V_401;
if ( V_14 -> V_24 . V_386 -> type == V_402 )
V_394 = V_4 -> V_304 ;
V_389 = V_14 -> V_183 . V_71
- ( V_14 -> V_116 - sizeof( struct V_327 ) ) ;
if ( ( V_389 > V_4 -> V_303 + V_394 + V_305 ) && ! V_14 -> V_361 )
V_389 = V_4 -> V_303 + V_394 + V_305 ;
do {
V_373 = F_63 ( V_14 , & V_14 -> V_183 ,
V_403 ) ;
if ( F_2 ( V_373 == NULL ) ) {
if ( V_395 && F_279 () )
F_280 () ;
continue;
}
V_2 = NULL ;
V_366 = F_274 ( V_14 , V_373 , V_389 , & V_81 ) ;
if ( V_366 < 0 )
goto V_404;
V_33 = V_403 ;
V_380 = F_224 ( V_4 ) ;
V_307 = V_4 -> V_308 ;
if ( V_14 -> V_361 ) {
V_326 = V_81 ;
V_81 += sizeof( * V_326 ) ;
V_366 -= sizeof( * V_326 ) ;
if ( V_366 < 0 ||
F_262 ( V_326 , V_366 ) ) {
V_366 = - V_248 ;
goto V_404;
}
V_381 = F_263 ( F_239 () ,
V_326 -> V_378 ) ;
}
V_381 = F_281 ( int , V_381 , V_4 -> V_304 ) ;
V_2 = F_282 ( & V_14 -> V_24 ,
V_380 + V_307 + sizeof( struct V_327 ) +
( V_381 - V_4 -> V_304 ) ,
! V_395 , & V_92 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_21 ( V_398 > 0 ) )
V_92 = V_398 ;
goto V_405;
}
V_366 = F_267 ( V_14 , V_2 , V_373 , V_4 , V_81 , V_366 , V_290 ,
V_31 , V_380 , V_381 , & V_289 ) ;
if ( F_21 ( V_366 >= 0 ) &&
V_366 > V_4 -> V_303 + V_394 &&
! V_14 -> V_361 &&
! F_207 ( V_4 , V_2 ) )
V_366 = - V_302 ;
if ( F_2 ( V_366 < 0 ) ) {
V_404:
if ( V_14 -> V_406 ) {
F_51 ( V_14 , V_373 ,
V_170 ) ;
F_130 ( & V_14 -> V_183 ) ;
F_15 ( V_2 ) ;
continue;
} else {
V_33 = V_407 ;
V_92 = V_366 ;
goto V_405;
}
}
if ( V_14 -> V_361 && F_283 ( V_2 , V_326 ,
F_239 () ) ) {
V_366 = - V_248 ;
goto V_404;
}
F_31 ( V_4 , V_2 ) ;
V_2 -> V_408 = F_259 ;
F_51 ( V_14 , V_373 , V_409 ) ;
F_131 ( & V_14 -> V_183 ) ;
V_33 = V_403 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_92 > 0 ) ) {
V_92 = F_284 ( V_92 ) ;
if ( V_92 && F_56 ( V_14 , V_373 ) ==
V_170 ) {
V_2 = NULL ;
goto V_405;
}
V_92 = 0 ;
}
F_130 ( & V_14 -> V_183 ) ;
V_398 += V_366 ;
} while ( F_21 ( ( V_373 != NULL ) ||
( V_395 && F_135 ( & V_14 -> V_183 ) ) ) );
V_92 = V_398 ;
goto V_401;
V_405:
F_51 ( V_14 , V_373 , V_33 ) ;
F_15 ( V_2 ) ;
V_401:
F_285 ( V_4 ) ;
V_131:
F_202 ( & V_14 -> V_399 ) ;
return V_92 ;
}
static struct V_1 * F_286 ( struct V_23 * V_24 , T_7 V_410 ,
T_7 V_394 , T_7 V_174 ,
T_7 V_411 , int V_412 ,
int * V_92 )
{
struct V_1 * V_2 ;
if ( V_410 + V_174 < V_140 || ! V_411 )
V_411 = V_174 ;
V_2 = F_287 ( V_24 , V_410 + V_411 , V_174 - V_411 , V_412 ,
V_92 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_226 ( V_2 , V_394 ) ;
F_229 ( V_2 , V_411 ) ;
V_2 -> V_387 = V_174 - V_411 ;
V_2 -> V_174 += V_174 - V_411 ;
return V_2 ;
}
static int F_288 ( struct V_283 * V_23 , struct V_284 * V_285 , T_7 V_174 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_221 ( struct V_327 * , V_286 , V_285 -> V_287 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_290 ;
unsigned char * V_31 ;
int V_92 , V_394 = 0 ;
struct V_288 V_289 ;
struct V_325 V_326 = { 0 } ;
int V_383 = 0 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_380 , V_307 , V_411 ;
int V_291 = 0 ;
if ( F_21 ( V_286 == NULL ) ) {
V_4 = F_18 ( V_14 ) ;
V_290 = V_14 -> V_208 ;
V_31 = NULL ;
} else {
V_92 = - V_248 ;
if ( V_285 -> V_292 < sizeof( struct V_327 ) )
goto V_131;
if ( V_285 -> V_292 < ( V_286 -> V_345 + F_277 ( struct V_327 , V_346 ) ) )
goto V_131;
V_290 = V_286 -> V_372 ;
V_31 = V_286 -> V_346 ;
V_4 = F_278 ( F_77 ( V_24 ) , V_286 -> V_344 ) ;
}
V_92 = - V_400 ;
if ( F_2 ( V_4 == NULL ) )
goto V_297;
V_92 = - V_298 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_299 ) ) )
goto V_297;
V_289 . V_313 = V_24 -> V_314 ;
V_289 . V_318 = V_24 -> V_319 ;
if ( V_285 -> V_315 ) {
V_92 = F_231 ( V_24 , V_285 , & V_289 ) ;
if ( F_2 ( V_92 ) )
goto V_297;
}
if ( V_23 -> type == V_402 )
V_394 = V_4 -> V_304 ;
if ( V_14 -> V_361 ) {
V_92 = F_265 ( V_285 , & V_174 , & V_326 ) ;
if ( V_92 )
goto V_297;
}
if ( F_2 ( F_149 ( V_24 , V_300 ) ) ) {
if ( ! F_223 ( V_4 ) ) {
V_92 = - V_301 ;
goto V_297;
}
V_291 = 4 ;
}
V_92 = - V_302 ;
if ( ! V_326 . V_413 &&
( V_174 > V_4 -> V_303 + V_394 + V_305 + V_291 ) )
goto V_297;
V_92 = - V_184 ;
V_380 = F_224 ( V_4 ) ;
V_307 = V_4 -> V_308 ;
V_411 = F_263 ( F_239 () , V_326 . V_378 ) ;
V_411 = F_289 ( V_411 , F_163 ( int , V_174 , V_4 -> V_304 ) ) ;
V_2 = F_286 ( V_24 , V_380 + V_307 , V_380 , V_174 , V_411 ,
V_285 -> V_396 & V_397 , & V_92 ) ;
if ( V_2 == NULL )
goto V_297;
F_290 ( V_2 , V_394 ) ;
V_92 = - V_248 ;
if ( V_23 -> type == V_334 ) {
V_383 = F_268 ( V_2 , V_4 , F_115 ( V_290 ) , V_31 , NULL , V_174 ) ;
if ( F_2 ( V_383 < 0 ) )
goto V_312;
}
V_92 = F_291 ( V_2 , V_383 , & V_285 -> V_379 , V_174 ) ;
if ( V_92 )
goto V_312;
if ( V_23 -> type == V_402 &&
! F_230 ( V_4 , V_2 -> V_81 , V_174 ) ) {
V_92 = - V_248 ;
goto V_312;
}
F_232 ( V_24 , V_289 . V_313 , & F_233 ( V_2 ) -> V_320 ) ;
if ( ! V_326 . V_413 && ( V_174 > V_4 -> V_303 + V_394 + V_291 ) &&
! F_207 ( V_4 , V_2 ) ) {
V_92 = - V_302 ;
goto V_312;
}
V_2 -> V_282 = V_290 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_316 = V_24 -> V_317 ;
V_2 -> V_318 = V_289 . V_318 ;
F_31 ( V_4 , V_2 ) ;
if ( V_14 -> V_361 ) {
V_92 = F_283 ( V_2 , & V_326 , F_239 () ) ;
if ( V_92 )
goto V_312;
V_174 += sizeof( V_326 ) ;
}
F_234 ( V_2 , V_394 ) ;
if ( F_2 ( V_291 == 4 ) )
V_2 -> V_321 = 1 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( V_92 > 0 && ( V_92 = F_284 ( V_92 ) ) != 0 )
goto V_297;
F_285 ( V_4 ) ;
return V_174 ;
V_312:
F_15 ( V_2 ) ;
V_297:
if ( V_4 )
F_285 ( V_4 ) ;
V_131:
return V_92 ;
}
static int F_292 ( struct V_283 * V_23 , struct V_284 * V_285 , T_7 V_174 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
if ( V_14 -> V_183 . V_69 )
return F_276 ( V_14 , V_285 ) ;
else
return F_288 ( V_23 , V_285 , V_174 ) ;
}
static int F_293 ( struct V_283 * V_23 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 ;
struct V_206 * V_207 ;
struct V_227 * V_227 ;
union V_100 V_101 ;
if ( ! V_24 )
return 0 ;
V_227 = F_77 ( V_24 ) ;
V_14 = F_35 ( V_24 ) ;
F_193 ( & V_227 -> V_414 . V_415 ) ;
F_294 ( V_24 ) ;
F_202 ( & V_227 -> V_414 . V_415 ) ;
F_295 () ;
F_296 ( V_227 , V_24 -> V_416 , - 1 ) ;
F_297 () ;
F_45 ( & V_14 -> V_29 ) ;
F_46 ( V_24 , false ) ;
F_26 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_285 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_43 ( & V_14 -> V_29 ) ;
F_298 ( V_24 ) ;
if ( V_14 -> V_78 . V_69 ) {
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_299 ( V_24 , & V_101 , 1 , 0 ) ;
}
if ( V_14 -> V_183 . V_69 ) {
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_299 ( V_24 , & V_101 , 1 , 1 ) ;
}
V_207 = F_203 ( V_24 ) ;
F_44 () ;
if ( V_207 ) {
F_191 ( V_207 ) ;
F_201 ( V_207 ) ;
}
F_300 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_147 ( & V_24 -> V_130 ) ;
F_140 ( V_14 ) ;
F_301 ( V_24 ) ;
F_302 ( V_24 ) ;
return 0 ;
}
static int F_303 ( struct V_23 * V_24 , const char * V_280 , int V_93 ,
T_8 V_290 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_3 * V_417 ;
T_8 V_418 ;
bool V_419 ;
struct V_3 * V_4 = NULL ;
int V_8 = 0 ;
bool V_420 = false ;
if ( V_14 -> V_26 )
return - V_248 ;
F_304 ( V_24 ) ;
F_45 ( & V_14 -> V_29 ) ;
F_19 () ;
if ( V_280 ) {
V_4 = F_222 ( F_77 ( V_24 ) , V_280 ) ;
if ( ! V_4 ) {
V_8 = - V_296 ;
goto V_297;
}
} else if ( V_93 ) {
V_4 = F_305 ( F_77 ( V_24 ) , V_93 ) ;
if ( ! V_4 ) {
V_8 = - V_296 ;
goto V_297;
}
}
if ( V_4 )
F_22 ( V_4 ) ;
V_418 = V_14 -> V_27 . type ;
V_417 = V_14 -> V_27 . V_4 ;
V_419 = V_418 != V_290 || V_417 != V_4 ;
if ( V_419 ) {
if ( V_14 -> V_25 ) {
F_23 () ;
F_39 ( V_24 , true ) ;
F_19 () ;
V_417 = V_14 -> V_27 . V_4 ;
if ( V_4 )
V_420 = ! F_305 ( F_77 ( V_24 ) ,
V_4 -> V_93 ) ;
}
V_14 -> V_208 = V_290 ;
V_14 -> V_27 . type = V_290 ;
if ( F_2 ( V_420 ) ) {
F_285 ( V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
V_14 -> V_93 = - 1 ;
F_26 ( V_14 ) ;
} else {
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_93 = V_4 ? V_4 -> V_93 : 0 ;
F_24 ( V_14 , V_4 ) ;
}
}
if ( V_417 )
F_285 ( V_417 ) ;
if ( V_290 == 0 || ! V_419 )
goto V_297;
if ( ! V_420 && ( ! V_4 || ( V_4 -> V_47 & V_299 ) ) ) {
F_34 ( V_24 ) ;
} else {
V_24 -> V_421 = V_298 ;
if ( ! F_149 ( V_24 , V_199 ) )
V_24 -> V_422 ( V_24 ) ;
}
V_297:
F_23 () ;
F_43 ( & V_14 -> V_29 ) ;
F_306 ( V_24 ) ;
return V_8 ;
}
static int F_307 ( struct V_283 * V_23 , struct V_293 * V_423 ,
int V_424 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_280 [ sizeof( V_423 -> V_425 ) + 1 ] ;
if ( V_424 != sizeof( struct V_293 ) )
return - V_248 ;
memcpy ( V_280 , V_423 -> V_425 , sizeof( V_423 -> V_425 ) ) ;
V_280 [ sizeof( V_423 -> V_425 ) ] = 0 ;
return F_303 ( V_24 , V_280 , 0 , F_35 ( V_24 ) -> V_208 ) ;
}
static int F_308 ( struct V_283 * V_23 , struct V_293 * V_423 , int V_424 )
{
struct V_327 * V_328 = (struct V_327 * ) V_423 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_424 < sizeof( struct V_327 ) )
return - V_248 ;
if ( V_328 -> V_370 != V_371 )
return - V_248 ;
return F_303 ( V_24 , NULL , V_328 -> V_344 ,
V_328 -> V_372 ? : F_35 ( V_24 ) -> V_208 ) ;
}
static int F_309 ( struct V_227 * V_227 , struct V_283 * V_23 , int V_282 ,
int V_426 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_8 V_290 = ( V_427 T_8 ) V_282 ;
int V_92 ;
if ( ! F_310 ( V_227 -> V_428 , V_429 ) )
return - V_247 ;
if ( V_23 -> type != V_334 && V_23 -> type != V_402 &&
V_23 -> type != V_430 )
return - V_431 ;
V_23 -> V_432 = V_433 ;
V_92 = - V_184 ;
V_24 = F_311 ( V_227 , V_241 , V_259 , & V_434 , V_426 ) ;
if ( V_24 == NULL )
goto V_131;
V_23 -> V_19 = & V_435 ;
if ( V_23 -> type == V_430 )
V_23 -> V_19 = & V_436 ;
F_312 ( V_23 , V_24 ) ;
V_14 = F_35 ( V_24 ) ;
V_24 -> V_240 = V_241 ;
V_14 -> V_208 = V_290 ;
V_14 -> V_16 = F_235 ;
V_92 = F_138 ( V_14 ) ;
if ( V_92 )
goto V_437;
F_26 ( V_14 ) ;
V_24 -> V_438 = F_146 ;
F_313 ( V_24 ) ;
F_199 ( & V_14 -> V_29 ) ;
F_314 ( & V_14 -> V_399 ) ;
V_14 -> V_204 = NULL ;
V_14 -> V_27 . F_71 = F_241 ;
if ( V_23 -> type == V_430 )
V_14 -> V_27 . F_71 = F_211 ;
V_14 -> V_27 . V_225 = V_24 ;
if ( V_290 ) {
V_14 -> V_27 . type = V_290 ;
F_34 ( V_24 ) ;
}
F_193 ( & V_227 -> V_414 . V_415 ) ;
F_315 ( V_24 , & V_227 -> V_414 . V_439 ) ;
F_202 ( & V_227 -> V_414 . V_415 ) ;
F_295 () ;
F_296 ( V_227 , & V_434 , 1 ) ;
F_297 () ;
return 0 ;
V_437:
F_316 ( V_24 ) ;
V_131:
return V_92 ;
}
static int F_317 ( struct V_283 * V_23 , struct V_284 * V_285 , T_7 V_174 ,
int V_47 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_440 , V_92 ;
int V_441 = 0 ;
unsigned int V_347 = 0 ;
V_92 = - V_248 ;
if ( V_47 & ~ ( V_442 | V_397 | V_443 | V_444 | V_445 ) )
goto V_131;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_47 & V_445 ) {
V_92 = F_318 ( V_24 , V_285 , V_174 ,
V_446 , V_447 ) ;
goto V_131;
}
V_2 = F_319 ( V_24 , V_47 , V_47 & V_397 , & V_92 ) ;
if ( V_2 == NULL )
goto V_131;
if ( F_35 ( V_24 ) -> V_196 )
F_145 ( F_35 ( V_24 ) , NULL ) ;
if ( F_35 ( V_24 ) -> V_361 ) {
V_92 = F_237 ( V_285 , V_2 , & V_174 ) ;
if ( V_92 )
goto V_312;
V_441 = sizeof( struct V_325 ) ;
}
V_440 = V_2 -> V_174 ;
if ( V_440 > V_174 ) {
V_440 = V_174 ;
V_285 -> V_396 |= V_443 ;
}
V_92 = F_320 ( V_2 , 0 , V_285 , V_440 ) ;
if ( V_92 )
goto V_312;
if ( V_23 -> type != V_430 ) {
struct V_327 * V_328 = & F_215 ( V_2 ) -> V_276 . V_340 ;
V_347 = F_215 ( V_2 ) -> V_276 . V_347 ;
V_328 -> V_370 = V_371 ;
V_328 -> V_372 = V_2 -> V_282 ;
}
F_321 ( V_285 , V_24 , V_2 ) ;
if ( V_285 -> V_287 ) {
if ( V_23 -> type == V_430 ) {
F_322 ( sizeof( struct V_270 ) ) ;
V_285 -> V_292 = sizeof( struct V_270 ) ;
} else {
struct V_327 * V_328 = & F_215 ( V_2 ) -> V_276 . V_340 ;
V_285 -> V_292 = V_328 -> V_345 +
F_277 ( struct V_327 , V_346 ) ;
}
memcpy ( V_285 -> V_287 , & F_215 ( V_2 ) -> V_276 ,
V_285 -> V_292 ) ;
}
if ( F_35 ( V_24 ) -> V_448 ) {
struct V_449 V_450 ;
V_450 . V_40 = V_143 ;
if ( V_2 -> V_354 == V_355 )
V_450 . V_40 |= V_356 ;
else if ( V_2 -> V_272 != V_335 &&
( V_2 -> V_354 == V_357 ||
F_255 ( V_2 ) ) )
V_450 . V_40 |= V_358 ;
V_450 . V_366 = V_347 ;
V_450 . V_367 = V_2 -> V_174 ;
V_450 . V_368 = 0 ;
V_450 . V_369 = F_243 ( V_2 ) ;
if ( F_113 ( V_2 ) ) {
V_450 . V_165 = F_114 ( V_2 ) ;
V_450 . V_166 = F_115 ( V_2 -> V_167 ) ;
V_450 . V_40 |= V_168 | V_169 ;
} else {
V_450 . V_165 = 0 ;
V_450 . V_166 = 0 ;
}
F_323 ( V_285 , V_446 , V_451 , sizeof( V_450 ) , & V_450 ) ;
}
V_92 = V_441 + ( ( V_47 & V_443 ) ? V_2 -> V_174 : V_440 ) ;
V_312:
F_324 ( V_24 , V_2 ) ;
V_131:
return V_92 ;
}
static int F_325 ( struct V_283 * V_23 , struct V_293 * V_423 ,
int * V_452 , int V_453 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_453 )
return - V_454 ;
V_423 -> V_455 = V_371 ;
memset ( V_423 -> V_425 , 0 , sizeof( V_423 -> V_425 ) ) ;
F_19 () ;
V_4 = F_305 ( F_77 ( V_24 ) , F_35 ( V_24 ) -> V_93 ) ;
if ( V_4 )
F_218 ( V_423 -> V_425 , V_4 -> V_280 , sizeof( V_423 -> V_425 ) ) ;
F_23 () ;
* V_452 = sizeof( * V_423 ) ;
return 0 ;
}
static int F_326 ( struct V_283 * V_23 , struct V_293 * V_423 ,
int * V_452 , int V_453 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
F_221 ( struct V_327 * , V_328 , V_423 ) ;
if ( V_453 )
return - V_454 ;
V_328 -> V_370 = V_371 ;
V_328 -> V_344 = V_14 -> V_93 ;
V_328 -> V_372 = V_14 -> V_208 ;
V_328 -> V_342 = 0 ;
F_19 () ;
V_4 = F_305 ( F_77 ( V_24 ) , V_14 -> V_93 ) ;
if ( V_4 ) {
V_328 -> V_341 = V_4 -> type ;
V_328 -> V_345 = V_4 -> V_424 ;
memcpy ( V_328 -> V_346 , V_4 -> V_456 , V_4 -> V_424 ) ;
} else {
V_328 -> V_341 = 0 ;
V_328 -> V_345 = 0 ;
}
F_23 () ;
* V_452 = F_277 ( struct V_327 , V_346 ) + V_328 -> V_345 ;
return 0 ;
}
static int F_327 ( struct V_3 * V_4 , struct V_457 * V_201 ,
int V_458 )
{
switch ( V_201 -> type ) {
case V_459 :
if ( V_201 -> V_460 != V_4 -> V_424 )
return - V_248 ;
if ( V_458 > 0 )
return F_328 ( V_4 , V_201 -> V_31 ) ;
else
return F_329 ( V_4 , V_201 -> V_31 ) ;
break;
case V_461 :
return F_330 ( V_4 , V_458 ) ;
case V_462 :
return F_331 ( V_4 , V_458 ) ;
case V_463 :
if ( V_201 -> V_460 != V_4 -> V_424 )
return - V_248 ;
if ( V_458 > 0 )
return F_332 ( V_4 , V_201 -> V_31 ) ;
else
return F_333 ( V_4 , V_201 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_334 ( struct V_3 * V_4 ,
struct V_457 * * V_464 )
{
struct V_457 * V_465 ;
while ( ( V_465 = * V_464 ) != NULL ) {
if ( V_465 -> V_93 == V_4 -> V_93 ) {
F_327 ( V_4 , V_465 , - 1 ) ;
* V_464 = V_465 -> V_466 ;
F_201 ( V_465 ) ;
} else
V_464 = & V_465 -> V_466 ;
}
}
static int F_335 ( struct V_23 * V_24 , struct V_467 * V_468 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_457 * V_465 , * V_201 ;
struct V_3 * V_4 ;
int V_92 ;
F_75 () ;
V_92 = - V_296 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_468 -> V_469 ) ;
if ( ! V_4 )
goto V_470;
V_92 = - V_248 ;
if ( V_468 -> V_471 > V_4 -> V_424 )
goto V_470;
V_92 = - V_184 ;
V_201 = F_336 ( sizeof( * V_201 ) , V_259 ) ;
if ( V_201 == NULL )
goto V_470;
V_92 = 0 ;
for ( V_465 = V_14 -> V_472 ; V_465 ; V_465 = V_465 -> V_466 ) {
if ( V_465 -> V_93 == V_468 -> V_469 &&
V_465 -> type == V_468 -> V_473 &&
V_465 -> V_460 == V_468 -> V_471 &&
memcmp ( V_465 -> V_31 , V_468 -> V_474 , V_465 -> V_460 ) == 0 ) {
V_465 -> V_202 ++ ;
F_201 ( V_201 ) ;
goto V_470;
}
}
V_201 -> type = V_468 -> V_473 ;
V_201 -> V_93 = V_468 -> V_469 ;
V_201 -> V_460 = V_468 -> V_471 ;
memcpy ( V_201 -> V_31 , V_468 -> V_474 , V_201 -> V_460 ) ;
memset ( V_201 -> V_31 + V_201 -> V_460 , 0 , sizeof( V_201 -> V_31 ) - V_201 -> V_460 ) ;
V_201 -> V_202 = 1 ;
V_201 -> V_466 = V_14 -> V_472 ;
V_14 -> V_472 = V_201 ;
V_92 = F_327 ( V_4 , V_201 , 1 ) ;
if ( V_92 ) {
V_14 -> V_472 = V_201 -> V_466 ;
F_201 ( V_201 ) ;
}
V_470:
F_78 () ;
return V_92 ;
}
static int F_337 ( struct V_23 * V_24 , struct V_467 * V_468 )
{
struct V_457 * V_465 , * * V_464 ;
F_75 () ;
for ( V_464 = & F_35 ( V_24 ) -> V_472 ; ( V_465 = * V_464 ) != NULL ; V_464 = & V_465 -> V_466 ) {
if ( V_465 -> V_93 == V_468 -> V_469 &&
V_465 -> type == V_468 -> V_473 &&
V_465 -> V_460 == V_468 -> V_471 &&
memcmp ( V_465 -> V_31 , V_468 -> V_474 , V_465 -> V_460 ) == 0 ) {
if ( -- V_465 -> V_202 == 0 ) {
struct V_3 * V_4 ;
* V_464 = V_465 -> V_466 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_465 -> V_93 ) ;
if ( V_4 )
F_327 ( V_4 , V_465 , - 1 ) ;
F_201 ( V_465 ) ;
}
break;
}
}
F_78 () ;
return 0 ;
}
static void F_298 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_457 * V_465 ;
if ( ! V_14 -> V_472 )
return;
F_75 () ;
while ( ( V_465 = V_14 -> V_472 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_472 = V_465 -> V_466 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_465 -> V_93 ) ;
if ( V_4 != NULL )
F_327 ( V_4 , V_465 , - 1 ) ;
F_201 ( V_465 ) ;
}
F_78 () ;
}
static int
F_338 ( struct V_283 * V_23 , int V_475 , int V_476 , char T_6 * V_477 , unsigned int V_478 )
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
int V_174 = V_478 ;
memset ( & V_468 , 0 , sizeof( V_468 ) ) ;
if ( V_174 < sizeof( struct V_482 ) )
return - V_248 ;
if ( V_174 > sizeof( V_468 ) )
V_174 = sizeof( V_468 ) ;
if ( F_184 ( & V_468 , V_477 , V_174 ) )
return - V_249 ;
if ( V_174 < ( V_468 . V_471 + F_277 ( struct V_482 , V_474 ) ) )
return - V_248 ;
if ( V_476 == V_480 )
V_8 = F_335 ( V_24 , & V_468 ) ;
else
V_8 = F_337 ( V_24 , & V_468 ) ;
return V_8 ;
}
case V_483 :
case V_484 :
{
union V_100 V_101 ;
int V_174 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_174 = sizeof( V_101 . V_485 ) ;
break;
case V_43 :
default:
V_174 = sizeof( V_101 . V_103 ) ;
break;
}
if ( V_478 < V_174 )
return - V_248 ;
if ( F_184 ( & V_101 . V_485 , V_477 , V_174 ) )
return - V_249 ;
return F_299 ( V_24 , & V_101 , 0 ,
V_476 == V_484 ) ;
}
case V_486 :
{
int V_209 ;
if ( V_478 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
F_35 ( V_24 ) -> V_362 = V_209 ;
return 0 ;
}
case V_487 :
{
int V_209 ;
if ( V_478 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
switch ( V_209 ) {
case V_38 :
case V_41 :
case V_43 :
break;
default:
return - V_248 ;
}
F_304 ( V_24 ) ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 ) {
V_8 = - V_488 ;
} else {
V_14 -> V_37 = V_209 ;
V_8 = 0 ;
}
F_306 ( V_24 ) ;
return V_8 ;
}
case V_489 :
{
unsigned int V_209 ;
if ( V_478 != sizeof( V_209 ) )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_488 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
if ( V_209 > V_490 )
return - V_248 ;
V_14 -> V_359 = V_209 ;
return 0 ;
}
case V_491 :
{
unsigned int V_209 ;
if ( V_478 != sizeof( V_209 ) )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_488 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_406 = ! ! V_209 ;
return 0 ;
}
case V_451 :
{
int V_209 ;
if ( V_478 < sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_448 = ! ! V_209 ;
return 0 ;
}
case V_492 :
{
int V_209 ;
if ( V_478 < sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_343 = ! ! V_209 ;
return 0 ;
}
case V_493 :
{
int V_209 ;
if ( V_23 -> type != V_402 )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_488 ;
if ( V_478 < sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_361 = ! ! V_209 ;
return 0 ;
}
case V_494 :
{
int V_209 ;
if ( V_478 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_56 = V_209 ;
return 0 ;
}
case V_495 :
{
int V_209 ;
if ( V_478 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
return F_192 ( V_24 , V_209 & 0xffff , V_209 >> 16 ) ;
}
case V_496 :
{
if ( ! V_14 -> V_26 )
return - V_248 ;
return F_190 ( V_14 , V_477 , V_478 ) ;
}
case V_497 :
{
unsigned int V_209 ;
if ( V_478 != sizeof( V_209 ) )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_488 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_391 = ! ! V_209 ;
return 0 ;
}
case V_498 :
{
int V_209 ;
if ( V_478 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_477 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_16 = V_209 ? F_1 : F_235 ;
return 0 ;
}
default:
return - V_479 ;
}
}
static int F_339 ( struct V_283 * V_23 , int V_475 , int V_476 ,
char T_6 * V_477 , int T_6 * V_478 )
{
int V_174 ;
int V_209 , V_499 = sizeof( V_209 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
void * V_81 = & V_209 ;
union V_500 V_501 ;
struct V_502 V_503 ;
if ( V_475 != V_446 )
return - V_479 ;
if ( F_340 ( V_174 , V_478 ) )
return - V_249 ;
if ( V_174 < 0 )
return - V_248 ;
switch ( V_476 ) {
case V_504 :
F_68 ( & V_24 -> V_130 . V_79 ) ;
memcpy ( & V_501 , & V_14 -> V_119 , sizeof( V_501 ) ) ;
memset ( & V_14 -> V_119 , 0 , sizeof( V_14 -> V_119 ) ) ;
F_69 ( & V_24 -> V_130 . V_79 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_499 = sizeof( struct V_505 ) ;
V_501 . V_120 . V_349 += V_501 . V_120 . V_149 ;
V_81 = & V_501 . V_120 ;
} else {
V_499 = sizeof( struct V_506 ) ;
V_501 . V_348 . V_349 += V_501 . V_348 . V_149 ;
V_81 = & V_501 . V_348 ;
}
break;
case V_451 :
V_209 = V_14 -> V_448 ;
break;
case V_492 :
V_209 = V_14 -> V_343 ;
break;
case V_493 :
V_209 = V_14 -> V_361 ;
break;
case V_487 :
V_209 = V_14 -> V_37 ;
break;
case V_507 :
if ( V_174 > sizeof( int ) )
V_174 = sizeof( int ) ;
if ( V_174 < sizeof( int ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_477 , V_174 ) )
return - V_249 ;
switch ( V_209 ) {
case V_38 :
V_209 = sizeof( struct V_508 ) ;
break;
case V_41 :
V_209 = sizeof( struct V_509 ) ;
break;
case V_43 :
V_209 = sizeof( struct V_144 ) ;
break;
default:
return - V_248 ;
}
break;
case V_489 :
V_209 = V_14 -> V_359 ;
break;
case V_491 :
V_209 = V_14 -> V_406 ;
break;
case V_494 :
V_209 = V_14 -> V_56 ;
break;
case V_495 :
V_209 = ( V_14 -> V_26 ?
( ( T_5 ) V_14 -> V_26 -> V_252 |
( ( T_5 ) V_14 -> V_26 -> type << 16 ) |
( ( T_5 ) V_14 -> V_26 -> V_47 << 24 ) ) :
0 ) ;
break;
case V_510 :
if ( ! V_14 -> V_204 )
return - V_248 ;
V_503 . V_511 = F_341 ( & V_14 -> V_204 -> V_208 ) ;
V_503 . V_512 = F_341 ( & V_14 -> V_204 -> V_217 ) ;
V_503 . V_513 = F_341 ( & V_14 -> V_204 -> V_218 ) ;
V_81 = & V_503 ;
V_499 = sizeof( V_503 ) ;
break;
case V_497 :
V_209 = V_14 -> V_391 ;
break;
case V_498 :
V_209 = F_28 ( V_14 ) ;
break;
default:
return - V_479 ;
}
if ( V_174 > V_499 )
V_174 = V_499 ;
if ( F_342 ( V_174 , V_478 ) )
return - V_249 ;
if ( F_343 ( V_477 , V_81 , V_174 ) )
return - V_249 ;
return 0 ;
}
static int F_344 ( struct V_283 * V_23 , int V_475 , int V_476 ,
char T_6 * V_477 , unsigned int V_478 )
{
struct V_13 * V_14 = F_35 ( V_23 -> V_24 ) ;
if ( V_475 != V_446 )
return - V_479 ;
if ( V_476 == V_496 &&
V_14 -> V_26 && V_14 -> V_26 -> type == V_236 ) {
V_477 = ( char T_6 * ) F_345 ( V_477 ) ;
if ( ! V_477 )
return - V_249 ;
V_478 = sizeof( struct V_244 ) ;
}
return F_338 ( V_23 , V_475 , V_476 , V_477 , V_478 ) ;
}
static int F_346 ( struct V_514 * V_515 ,
unsigned long V_285 , void * V_516 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_347 ( V_516 ) ;
struct V_227 * V_227 = F_173 ( V_4 ) ;
F_19 () ;
F_348 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_35 ( V_24 ) ;
switch ( V_285 ) {
case V_517 :
if ( V_14 -> V_472 )
F_334 ( V_4 , & V_14 -> V_472 ) ;
case V_518 :
if ( V_4 -> V_93 == V_14 -> V_93 ) {
F_45 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_39 ( V_24 , false ) ;
V_24 -> V_421 = V_298 ;
if ( ! F_149 ( V_24 , V_199 ) )
V_24 -> V_422 ( V_24 ) ;
}
if ( V_285 == V_517 ) {
F_26 ( V_14 ) ;
V_14 -> V_93 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_285 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_43 ( & V_14 -> V_29 ) ;
}
break;
case V_519 :
if ( V_4 -> V_93 == V_14 -> V_93 ) {
F_45 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_208 )
F_34 ( V_24 ) ;
F_43 ( & V_14 -> V_29 ) ;
}
break;
}
}
F_23 () ;
return V_520 ;
}
static int F_349 ( struct V_283 * V_23 , unsigned int V_521 ,
unsigned long V_522 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_521 ) {
case V_523 :
{
int V_524 = F_350 ( V_24 ) ;
return F_342 ( V_524 , ( int T_6 * ) V_522 ) ;
}
case V_525 :
{
struct V_1 * V_2 ;
int V_524 = 0 ;
F_68 ( & V_24 -> V_130 . V_79 ) ;
V_2 = F_351 ( & V_24 -> V_130 ) ;
if ( V_2 )
V_524 = V_2 -> V_174 ;
F_69 ( & V_24 -> V_130 . V_79 ) ;
return F_342 ( V_524 , ( int T_6 * ) V_522 ) ;
}
case V_526 :
return F_352 ( V_24 , (struct V_527 T_6 * ) V_522 ) ;
case V_528 :
return F_353 ( V_24 , (struct V_45 T_6 * ) V_522 ) ;
#ifdef F_354
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
case V_542 :
return V_543 . V_544 ( V_23 , V_521 , V_522 ) ;
#endif
default:
return - V_545 ;
}
return 0 ;
}
static unsigned int F_355 ( struct V_546 * V_546 , struct V_283 * V_23 ,
T_9 * V_547 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
unsigned int V_548 = F_356 ( V_546 , V_23 , V_547 ) ;
F_68 ( & V_24 -> V_130 . V_79 ) ;
if ( V_14 -> V_78 . V_69 ) {
if ( ! F_127 ( V_14 , & V_14 -> V_78 ,
V_161 ) )
V_548 |= V_549 | V_550 ;
}
if ( V_14 -> V_196 && F_144 ( V_14 , NULL ) == V_193 )
V_14 -> V_196 = 0 ;
F_69 ( & V_24 -> V_130 . V_79 ) ;
F_68 ( & V_24 -> V_551 . V_79 ) ;
if ( V_14 -> V_183 . V_69 ) {
if ( F_63 ( V_14 , & V_14 -> V_183 , V_170 ) )
V_548 |= V_552 | V_553 ;
}
F_69 ( & V_24 -> V_551 . V_79 ) ;
return V_548 ;
}
static void F_357 ( struct V_554 * V_555 )
{
struct V_546 * V_546 = V_555 -> V_556 ;
struct V_283 * V_23 = V_546 -> V_557 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_119 ( & F_35 ( V_24 ) -> V_558 ) ;
}
static void F_358 ( struct V_554 * V_555 )
{
struct V_546 * V_546 = V_555 -> V_556 ;
struct V_283 * V_23 = V_546 -> V_557 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_108 ( & F_35 ( V_24 ) -> V_558 ) ;
}
static void F_359 ( struct V_105 * V_69 , unsigned int V_559 ,
unsigned int V_174 )
{
int V_201 ;
for ( V_201 = 0 ; V_201 < V_174 ; V_201 ++ ) {
if ( F_21 ( V_69 [ V_201 ] . V_70 ) ) {
if ( F_48 ( V_69 [ V_201 ] . V_70 ) )
F_360 ( V_69 [ V_201 ] . V_70 ) ;
else
F_361 ( ( unsigned long ) V_69 [ V_201 ] . V_70 ,
V_559 ) ;
V_69 [ V_201 ] . V_70 = NULL ;
}
}
F_201 ( V_69 ) ;
}
static char * F_362 ( unsigned long V_559 )
{
char * V_70 ;
T_10 V_560 = V_259 | V_561 |
V_562 | V_563 | V_564 ;
V_70 = ( char * ) F_363 ( V_560 , V_559 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_364 ( ( 1 << V_559 ) * V_140 ) ;
if ( V_70 )
return V_70 ;
V_560 &= ~ V_564 ;
V_70 = ( char * ) F_363 ( V_560 , V_559 ) ;
if ( V_70 )
return V_70 ;
return NULL ;
}
static struct V_105 * F_365 ( struct V_565 * V_485 , int V_559 )
{
unsigned int V_566 = V_485 -> V_114 ;
struct V_105 * V_69 ;
int V_201 ;
V_69 = F_366 ( V_566 , sizeof( struct V_105 ) , V_259 ) ;
if ( F_2 ( ! V_69 ) )
goto V_131;
for ( V_201 = 0 ; V_201 < V_566 ; V_201 ++ ) {
V_69 [ V_201 ] . V_70 = F_362 ( V_559 ) ;
if ( F_2 ( ! V_69 [ V_201 ] . V_70 ) )
goto V_567;
}
V_131:
return V_69 ;
V_567:
F_359 ( V_69 , V_559 , V_566 ) ;
V_69 = NULL ;
goto V_131;
}
static int F_299 ( struct V_23 * V_24 , union V_100 * V_101 ,
int V_568 , int V_183 )
{
struct V_105 * V_69 = NULL ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_569 , V_559 = 0 ;
struct V_63 * V_64 ;
struct V_76 * V_77 ;
T_8 V_208 ;
int V_92 = - V_248 ;
struct V_565 * V_485 = & V_101 -> V_485 ;
F_304 ( V_24 ) ;
V_64 = V_183 ? & V_14 -> V_183 : & V_14 -> V_78 ;
V_77 = V_183 ? & V_24 -> V_551 : & V_24 -> V_130 ;
V_92 = - V_488 ;
if ( ! V_568 ) {
if ( F_90 ( & V_14 -> V_558 ) )
goto V_131;
if ( F_135 ( V_64 ) )
goto V_131;
}
if ( V_485 -> V_114 ) {
V_92 = - V_488 ;
if ( F_2 ( V_64 -> V_69 ) )
goto V_131;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_116 = V_570 ;
break;
case V_41 :
V_14 -> V_116 = V_571 ;
break;
case V_43 :
V_14 -> V_116 = V_572 ;
break;
}
V_92 = - V_248 ;
if ( F_2 ( ( int ) V_485 -> V_112 <= 0 ) )
goto V_131;
if ( F_2 ( ! F_367 ( V_485 -> V_112 ) ) )
goto V_131;
if ( V_14 -> V_37 >= V_43 &&
V_485 -> V_112 <=
F_83 ( ( V_573 ) V_101 -> V_103 . V_126 ) )
goto V_131;
if ( F_2 ( V_485 -> V_574 < V_14 -> V_116 +
V_14 -> V_359 ) )
goto V_131;
if ( F_2 ( V_485 -> V_574 & ( V_575 - 1 ) ) )
goto V_131;
V_64 -> V_68 = V_485 -> V_112 / V_485 -> V_574 ;
if ( F_2 ( V_64 -> V_68 == 0 ) )
goto V_131;
if ( F_2 ( V_485 -> V_112 > V_576 / V_485 -> V_114 ) )
goto V_131;
if ( F_2 ( ( V_64 -> V_68 * V_485 -> V_114 ) !=
V_485 -> V_577 ) )
goto V_131;
V_92 = - V_258 ;
V_559 = F_368 ( V_485 -> V_112 ) ;
V_69 = F_365 ( V_485 , V_559 ) ;
if ( F_2 ( ! V_69 ) )
goto V_131;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( ! V_183 ) {
F_81 ( V_14 , V_64 , V_69 , V_101 ) ;
} else {
struct V_578 * V_103 = & V_101 -> V_103 ;
if ( V_103 -> V_122 ||
V_103 -> V_126 ||
V_103 -> V_104 ) {
V_92 = - V_248 ;
goto V_131;
}
}
break;
default:
break;
}
}
else {
V_92 = - V_248 ;
if ( F_2 ( V_485 -> V_577 ) )
goto V_131;
}
F_45 ( & V_14 -> V_29 ) ;
V_569 = V_14 -> V_25 ;
V_208 = V_14 -> V_208 ;
if ( V_569 ) {
V_14 -> V_208 = 0 ;
F_39 ( V_24 , false ) ;
}
F_43 ( & V_14 -> V_29 ) ;
F_44 () ;
V_92 = - V_488 ;
F_193 ( & V_14 -> V_399 ) ;
if ( V_568 || F_90 ( & V_14 -> V_558 ) == 0 ) {
V_92 = 0 ;
F_68 ( & V_77 -> V_79 ) ;
F_369 ( V_64 -> V_69 , V_69 ) ;
V_64 -> V_178 = ( V_485 -> V_577 - 1 ) ;
V_64 -> V_72 = 0 ;
V_64 -> V_71 = V_485 -> V_574 ;
F_69 ( & V_77 -> V_79 ) ;
F_369 ( V_64 -> V_579 , V_559 ) ;
F_369 ( V_64 -> V_580 , V_485 -> V_114 ) ;
V_64 -> V_581 = V_485 -> V_112 / V_140 ;
V_14 -> V_27 . F_71 = ( V_14 -> V_78 . V_69 ) ?
V_187 : F_241 ;
F_147 ( V_77 ) ;
if ( F_90 ( & V_14 -> V_558 ) )
F_150 ( L_8 ,
F_90 ( & V_14 -> V_558 ) ) ;
}
F_202 ( & V_14 -> V_399 ) ;
F_45 ( & V_14 -> V_29 ) ;
if ( V_569 ) {
V_14 -> V_208 = V_208 ;
F_34 ( V_24 ) ;
}
F_43 ( & V_14 -> V_29 ) ;
if ( V_568 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_183 )
F_66 ( V_14 , V_77 ) ;
}
if ( V_69 )
F_359 ( V_69 , V_559 , V_485 -> V_114 ) ;
V_131:
F_306 ( V_24 ) ;
return V_92 ;
}
static int F_370 ( struct V_546 * V_546 , struct V_283 * V_23 ,
struct V_554 * V_555 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
unsigned long V_582 , V_583 ;
struct V_63 * V_64 ;
unsigned long V_138 ;
int V_92 = - V_248 ;
int V_201 ;
if ( V_555 -> V_584 )
return - V_248 ;
F_193 ( & V_14 -> V_399 ) ;
V_583 = 0 ;
for ( V_64 = & V_14 -> V_78 ; V_64 <= & V_14 -> V_183 ; V_64 ++ ) {
if ( V_64 -> V_69 ) {
V_583 += V_64 -> V_580
* V_64 -> V_581
* V_140 ;
}
}
if ( V_583 == 0 )
goto V_131;
V_582 = V_555 -> V_585 - V_555 -> V_586 ;
if ( V_582 != V_583 )
goto V_131;
V_138 = V_555 -> V_586 ;
for ( V_64 = & V_14 -> V_78 ; V_64 <= & V_14 -> V_183 ; V_64 ++ ) {
if ( V_64 -> V_69 == NULL )
continue;
for ( V_201 = 0 ; V_201 < V_64 -> V_580 ; V_201 ++ ) {
struct V_30 * V_30 ;
void * V_587 = V_64 -> V_69 [ V_201 ] . V_70 ;
int V_588 ;
for ( V_588 = 0 ; V_588 < V_64 -> V_581 ; V_588 ++ ) {
V_30 = F_47 ( V_587 ) ;
V_92 = F_371 ( V_555 , V_138 , V_30 ) ;
if ( F_2 ( V_92 ) )
goto V_131;
V_138 += V_140 ;
V_587 += V_140 ;
}
}
}
F_119 ( & V_14 -> V_558 ) ;
V_555 -> V_589 = & V_590 ;
V_92 = 0 ;
V_131:
F_202 ( & V_14 -> V_399 ) ;
return V_92 ;
}
static void * F_372 ( struct V_591 * V_592 , T_11 * V_593 )
__acquires( T_12 )
{
struct V_227 * V_227 = F_373 ( V_592 ) ;
F_19 () ;
return F_374 ( & V_227 -> V_414 . V_439 , * V_593 ) ;
}
static void * F_375 ( struct V_591 * V_592 , void * V_594 , T_11 * V_593 )
{
struct V_227 * V_227 = F_373 ( V_592 ) ;
return F_376 ( V_594 , & V_227 -> V_414 . V_439 , V_593 ) ;
}
static void F_377 ( struct V_591 * V_592 , void * V_594 )
__releases( T_12 )
{
F_23 () ;
}
static int F_378 ( struct V_591 * V_592 , void * V_594 )
{
if ( V_594 == V_595 )
F_379 ( V_592 , L_9 ) ;
else {
struct V_23 * V_596 = F_380 ( V_594 ) ;
const struct V_13 * V_14 = F_35 ( V_596 ) ;
F_381 ( V_592 ,
L_10 ,
V_596 ,
F_90 ( & V_596 -> V_597 ) ,
V_596 -> V_333 ,
F_115 ( V_14 -> V_208 ) ,
V_14 -> V_93 ,
V_14 -> V_25 ,
F_90 ( & V_596 -> V_190 ) ,
F_382 ( F_383 ( V_592 ) , F_384 ( V_596 ) ) ,
F_385 ( V_596 ) ) ;
}
return 0 ;
}
static int F_386 ( struct V_598 * V_598 , struct V_546 * V_546 )
{
return F_387 ( V_598 , V_546 , & V_599 ,
sizeof( struct V_600 ) ) ;
}
static int T_13 F_388 ( struct V_227 * V_227 )
{
F_314 ( & V_227 -> V_414 . V_415 ) ;
F_389 ( & V_227 -> V_414 . V_439 ) ;
if ( ! F_390 ( L_11 , 0 , V_227 -> V_601 , & V_602 ) )
return - V_258 ;
return 0 ;
}
static void T_14 F_391 ( struct V_227 * V_227 )
{
F_392 ( L_11 , V_227 -> V_601 ) ;
}
static void T_15 F_393 ( void )
{
F_394 ( & V_603 ) ;
F_395 ( & V_604 ) ;
F_396 ( V_241 ) ;
F_397 ( & V_434 ) ;
}
static int T_16 F_398 ( void )
{
int V_605 = F_399 ( & V_434 , 0 ) ;
if ( V_605 != 0 )
goto V_131;
F_400 ( & V_606 ) ;
F_401 ( & V_604 ) ;
F_402 ( & V_603 ) ;
V_131:
return V_605 ;
}
