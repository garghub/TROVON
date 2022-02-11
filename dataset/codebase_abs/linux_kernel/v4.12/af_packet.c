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
static bool F_192 ( struct V_23 * V_24 , T_1 V_252 )
{
struct V_206 * V_207 ;
F_193 (f, &fanout_list, list) {
if ( V_207 -> V_253 == V_252 &&
F_171 ( & V_207 -> V_227 ) == F_77 ( V_24 ) ) {
return false ;
}
}
return true ;
}
static bool F_194 ( struct V_23 * V_24 , T_1 * V_254 )
{
T_1 V_253 = V_255 ;
do {
if ( F_192 ( V_24 , V_253 ) ) {
* V_254 = V_253 ;
V_255 = V_253 + 1 ;
return true ;
}
V_253 ++ ;
} while ( V_253 != V_255 );
return false ;
}
static int F_195 ( struct V_23 * V_24 , T_1 V_253 , T_1 V_256 )
{
struct V_257 * V_204 = NULL ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_206 * V_207 , * V_258 ;
T_4 type = V_256 & 0xff ;
T_4 V_47 = V_256 >> 8 ;
int V_92 ;
switch ( type ) {
case V_235 :
if ( V_256 & V_238 )
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
F_196 ( & V_259 ) ;
V_92 = - V_248 ;
if ( ! V_14 -> V_25 )
goto V_131;
V_92 = - V_260 ;
if ( V_14 -> V_26 )
goto V_131;
if ( type == V_235 ||
( V_256 & V_238 ) ) {
V_92 = - V_261 ;
V_204 = F_197 ( sizeof( * V_204 ) , V_262 ) ;
if ( ! V_204 )
goto V_131;
F_198 ( & V_204 -> V_208 , 0 ) ;
F_198 ( & V_204 -> V_217 , 0 ) ;
F_198 ( & V_204 -> V_218 , 0 ) ;
V_14 -> V_204 = V_204 ;
}
if ( V_256 & V_263 ) {
if ( V_253 != 0 ) {
V_92 = - V_248 ;
goto V_131;
}
if ( ! F_194 ( V_24 , & V_253 ) ) {
V_92 = - V_261 ;
goto V_131;
}
V_47 &= ~ ( V_263 >> 8 ) ;
}
V_258 = NULL ;
F_193 (f, &fanout_list, list) {
if ( V_207 -> V_253 == V_253 &&
F_171 ( & V_207 -> V_227 ) == F_77 ( V_24 ) ) {
V_258 = V_207 ;
break;
}
}
V_92 = - V_248 ;
if ( V_258 && V_258 -> V_47 != V_47 )
goto V_131;
if ( ! V_258 ) {
V_92 = - V_261 ;
V_258 = F_197 ( sizeof( * V_258 ) , V_262 ) ;
if ( ! V_258 )
goto V_131;
F_199 ( & V_258 -> V_227 , F_77 ( V_24 ) ) ;
V_258 -> V_253 = V_253 ;
V_258 -> type = type ;
V_258 -> V_47 = V_47 ;
F_200 ( & V_258 -> V_264 ) ;
F_201 ( & V_258 -> V_79 ) ;
F_178 ( & V_258 -> V_265 , 0 ) ;
F_177 ( V_258 ) ;
V_258 -> V_27 . type = V_14 -> V_27 . type ;
V_258 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_258 -> V_27 . F_71 = F_169 ;
V_258 -> V_27 . V_225 = V_258 ;
V_258 -> V_27 . V_266 = F_176 ;
F_202 ( & V_258 -> V_264 , & V_267 ) ;
}
V_92 = - V_248 ;
if ( V_258 -> type == type &&
V_258 -> V_27 . type == V_14 -> V_27 . type &&
V_258 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_92 = - V_268 ;
if ( F_90 ( & V_258 -> V_265 ) < V_269 ) {
F_41 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_258 ;
F_119 ( & V_258 -> V_265 ) ;
F_36 ( V_24 , V_14 ) ;
V_92 = 0 ;
}
}
V_131:
if ( V_92 && V_204 ) {
F_203 ( V_204 ) ;
V_14 -> V_204 = NULL ;
}
F_204 ( & V_259 ) ;
return V_92 ;
}
static struct V_206 * F_205 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_206 * V_207 ;
F_196 ( & V_259 ) ;
V_207 = V_14 -> V_26 ;
if ( V_207 ) {
V_14 -> V_26 = NULL ;
if ( F_206 ( & V_207 -> V_265 ) )
F_207 ( & V_207 -> V_264 ) ;
else
V_207 = NULL ;
if ( V_14 -> V_204 )
F_208 ( V_14 -> V_204 , V_270 ) ;
}
F_204 ( & V_259 ) ;
return V_207 ;
}
static bool F_209 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( F_2 ( V_4 -> type != V_271 ) )
return false ;
F_210 ( V_2 ) ;
return F_21 ( F_211 ( V_2 ) -> V_272 == F_212 ( V_273 ) ) ;
}
static int F_213 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_222 * V_223 , struct V_3 * V_224 )
{
struct V_23 * V_24 ;
struct V_274 * V_275 ;
V_24 = V_223 -> V_225 ;
if ( V_2 -> V_276 == V_277 )
goto V_131;
if ( ! F_172 ( F_173 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_131;
V_2 = F_214 ( V_2 , V_278 ) ;
if ( V_2 == NULL )
goto V_279;
F_215 ( V_2 ) ;
F_216 ( V_2 ) ;
V_275 = & F_217 ( V_2 ) -> V_280 . V_281 ;
F_218 ( V_2 , V_2 -> V_81 - F_219 ( V_2 ) ) ;
V_275 -> V_282 = V_4 -> type ;
F_220 ( V_275 -> V_283 , V_4 -> V_284 , sizeof( V_275 -> V_283 ) ) ;
V_275 -> V_285 = V_2 -> V_286 ;
if ( F_221 ( V_24 , V_2 ) == 0 )
return 0 ;
V_131:
F_15 ( V_2 ) ;
V_279:
return 0 ;
}
static int F_222 ( struct V_287 * V_23 , struct V_288 * V_289 ,
T_7 V_174 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_223 ( struct V_274 * , V_290 , V_289 -> V_291 ) ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
struct V_292 V_293 ;
T_8 V_294 = 0 ;
int V_92 ;
int V_295 = 0 ;
if ( V_290 ) {
if ( V_289 -> V_296 < sizeof( struct V_297 ) )
return - V_248 ;
if ( V_289 -> V_296 == sizeof( struct V_274 ) )
V_294 = V_290 -> V_285 ;
} else
return - V_298 ;
V_290 -> V_283 [ sizeof( V_290 -> V_283 ) - 1 ] = 0 ;
V_299:
F_19 () ;
V_4 = F_224 ( F_77 ( V_24 ) , V_290 -> V_283 ) ;
V_92 = - V_300 ;
if ( V_4 == NULL )
goto V_301;
V_92 = - V_302 ;
if ( ! ( V_4 -> V_47 & V_303 ) )
goto V_301;
if ( F_2 ( F_149 ( V_24 , V_304 ) ) ) {
if ( ! F_225 ( V_4 ) ) {
V_92 = - V_305 ;
goto V_301;
}
V_295 = 4 ;
}
V_92 = - V_306 ;
if ( V_174 > V_4 -> V_307 + V_4 -> V_308 + V_309 + V_295 )
goto V_301;
if ( ! V_2 ) {
T_7 V_310 = F_226 ( V_4 ) ;
int V_311 = V_4 -> V_312 ;
unsigned int V_313 = V_4 -> V_314 ? V_4 -> V_308 : 0 ;
F_23 () ;
V_2 = F_227 ( V_24 , V_174 + V_310 + V_311 , 0 , V_262 ) ;
if ( V_2 == NULL )
return - V_184 ;
F_228 ( V_2 , V_310 ) ;
F_229 ( V_2 ) ;
if ( V_313 ) {
V_2 -> V_81 -= V_313 ;
V_2 -> V_315 -= V_313 ;
if ( V_174 < V_313 )
F_229 ( V_2 ) ;
}
V_92 = F_230 ( F_231 ( V_2 , V_174 ) , V_289 , V_174 ) ;
if ( V_92 )
goto V_316;
goto V_299;
}
if ( ! F_232 ( V_4 , V_2 -> V_81 , V_174 ) ) {
V_92 = - V_248 ;
goto V_301;
}
if ( V_174 > ( V_4 -> V_307 + V_4 -> V_308 + V_295 ) &&
! F_209 ( V_4 , V_2 ) ) {
V_92 = - V_306 ;
goto V_301;
}
V_293 . V_317 = V_24 -> V_318 ;
if ( V_289 -> V_319 ) {
V_92 = F_233 ( V_24 , V_289 , & V_293 ) ;
if ( F_2 ( V_92 ) )
goto V_301;
}
V_2 -> V_286 = V_294 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_320 = V_24 -> V_321 ;
V_2 -> V_322 = V_24 -> V_323 ;
F_234 ( V_24 , V_293 . V_317 , & F_235 ( V_2 ) -> V_324 ) ;
if ( F_2 ( V_295 == 4 ) )
V_2 -> V_325 = 1 ;
F_236 ( V_2 , 0 ) ;
F_237 ( V_2 ) ;
F_23 () ;
return V_174 ;
V_301:
F_23 () ;
V_316:
F_15 ( V_2 ) ;
return V_92 ;
}
static unsigned int F_238 ( struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_326 )
{
struct V_327 * V_328 ;
F_19 () ;
V_328 = F_20 ( V_24 -> V_327 ) ;
if ( V_328 != NULL )
V_326 = F_167 ( V_328 -> V_220 , V_2 ) ;
F_23 () ;
return V_326 ;
}
static int F_239 ( struct V_288 * V_289 , const struct V_1 * V_2 ,
T_7 * V_174 )
{
struct V_329 V_330 ;
if ( * V_174 < sizeof( V_330 ) )
return - V_248 ;
* V_174 -= sizeof( V_330 ) ;
if ( F_240 ( V_2 , & V_330 , F_241 () , true ) )
return - V_248 ;
return F_242 ( V_289 , ( void * ) & V_330 , sizeof( V_330 ) ) ;
}
static int F_243 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_222 * V_223 , struct V_3 * V_224 )
{
struct V_23 * V_24 ;
struct V_331 * V_332 ;
struct V_13 * V_14 ;
T_4 * V_333 = V_2 -> V_81 ;
int V_334 = V_2 -> V_174 ;
unsigned int V_335 , V_326 ;
bool V_336 = false ;
if ( V_2 -> V_276 == V_277 )
goto V_10;
V_24 = V_223 -> V_225 ;
V_14 = F_35 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_314 ) {
if ( V_24 -> V_337 != V_338 )
F_218 ( V_2 , V_2 -> V_81 - F_219 ( V_2 ) ) ;
else if ( V_2 -> V_276 == V_339 ) {
F_244 ( V_2 , F_245 ( V_2 ) ) ;
}
}
V_335 = V_2 -> V_174 ;
V_326 = F_238 ( V_2 , V_24 , V_335 ) ;
if ( ! V_326 )
goto V_340;
if ( V_335 > V_326 )
V_335 = V_326 ;
if ( F_90 ( & V_24 -> V_190 ) >= V_24 -> V_189 )
goto V_341;
if ( F_246 ( V_2 ) ) {
struct V_1 * V_342 = F_247 ( V_2 , V_278 ) ;
if ( V_342 == NULL )
goto V_341;
if ( V_333 != V_2 -> V_81 ) {
V_2 -> V_81 = V_333 ;
V_2 -> V_174 = V_334 ;
}
F_248 ( V_2 ) ;
V_2 = V_342 ;
}
F_249 ( sizeof( * F_217 ( V_2 ) ) + V_343 - 8 ) ;
V_332 = & F_217 ( V_2 ) -> V_280 . V_344 ;
V_332 -> V_345 = V_4 -> type ;
V_332 -> V_346 = V_2 -> V_276 ;
if ( F_2 ( V_14 -> V_347 ) )
V_332 -> V_348 = V_224 -> V_93 ;
else
V_332 -> V_348 = V_4 -> V_93 ;
V_332 -> V_349 = F_250 ( V_2 , V_332 -> V_350 ) ;
F_217 ( V_2 ) -> V_280 . V_351 = V_2 -> V_174 ;
if ( F_251 ( V_2 , V_335 ) )
goto V_341;
F_252 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_215 ( V_2 ) ;
F_216 ( V_2 ) ;
F_45 ( & V_24 -> V_130 . V_79 ) ;
V_14 -> V_119 . V_352 . V_353 ++ ;
F_253 ( V_24 , V_2 ) ;
F_254 ( & V_24 -> V_130 , V_2 ) ;
F_43 ( & V_24 -> V_130 . V_79 ) ;
V_24 -> V_156 ( V_24 ) ;
return 0 ;
V_341:
V_336 = true ;
F_45 ( & V_24 -> V_130 . V_79 ) ;
V_14 -> V_119 . V_352 . V_149 ++ ;
F_119 ( & V_24 -> V_354 ) ;
F_43 ( & V_24 -> V_130 . V_79 ) ;
V_340:
if ( V_333 != V_2 -> V_81 && F_246 ( V_2 ) ) {
V_2 -> V_81 = V_333 ;
V_2 -> V_174 = V_334 ;
}
V_10:
if ( ! V_336 )
F_248 ( V_2 ) ;
else
F_15 ( V_2 ) ;
return 0 ;
}
static int V_187 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_222 * V_223 , struct V_3 * V_224 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
struct V_331 * V_332 ;
union V_34 V_35 ;
T_4 * V_333 = V_2 -> V_81 ;
int V_334 = V_2 -> V_174 ;
unsigned int V_335 , V_326 ;
unsigned long V_33 = V_143 ;
unsigned short V_355 , V_356 , V_115 ;
struct V_1 * V_357 = NULL ;
struct V_45 V_46 ;
T_3 V_55 ;
bool V_336 = false ;
F_255 ( F_256 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_255 ( F_256 ( sizeof( * V_35 . V_44 ) ) != 48 ) ;
if ( V_2 -> V_276 == V_277 )
goto V_10;
V_24 = V_223 -> V_225 ;
V_14 = F_35 ( V_24 ) ;
if ( ! F_172 ( F_173 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_314 ) {
if ( V_24 -> V_337 != V_338 )
F_218 ( V_2 , V_2 -> V_81 - F_219 ( V_2 ) ) ;
else if ( V_2 -> V_276 == V_339 ) {
F_244 ( V_2 , F_245 ( V_2 ) ) ;
}
}
V_335 = V_2 -> V_174 ;
V_326 = F_238 ( V_2 , V_24 , V_335 ) ;
if ( ! V_326 )
goto V_340;
if ( V_2 -> V_358 == V_359 )
V_33 |= V_360 ;
else if ( V_2 -> V_276 != V_339 &&
( V_2 -> V_358 == V_361 ||
F_257 ( V_2 ) ) )
V_33 |= V_362 ;
if ( V_335 > V_326 )
V_335 = V_326 ;
if ( V_24 -> V_337 == V_338 ) {
V_355 = V_356 = F_256 ( V_14 -> V_116 ) + 16 +
V_14 -> V_363 ;
} else {
unsigned int V_364 = F_245 ( V_2 ) ;
V_356 = F_256 ( V_14 -> V_116 +
( V_364 < 16 ? 16 : V_364 ) ) +
V_14 -> V_363 ;
if ( V_14 -> V_365 )
V_356 += sizeof( struct V_329 ) ;
V_355 = V_356 - V_364 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_355 + V_335 > V_14 -> V_78 . V_71 ) {
if ( V_14 -> V_366 &&
F_90 ( & V_24 -> V_190 ) < V_24 -> V_189 ) {
if ( F_246 ( V_2 ) ) {
V_357 = F_247 ( V_2 , V_278 ) ;
} else {
V_357 = F_258 ( V_2 ) ;
V_333 = V_2 -> V_81 ;
}
if ( V_357 )
F_252 ( V_357 , V_24 ) ;
}
V_335 = V_14 -> V_78 . V_71 - V_355 ;
if ( ( int ) V_335 < 0 )
V_335 = 0 ;
}
} else if ( F_2 ( V_355 + V_335 >
F_67 ( & V_14 -> V_78 ) -> V_127 ) ) {
T_5 V_367 ;
V_367 = F_67 ( & V_14 -> V_78 ) -> V_127 - V_355 ;
F_259 ( L_4 ,
V_335 , V_367 , V_355 ) ;
V_335 = V_367 ;
if ( F_2 ( ( int ) V_335 < 0 ) ) {
V_335 = 0 ;
V_355 = F_67 ( & V_14 -> V_78 ) -> V_127 ;
}
}
F_45 ( & V_24 -> V_130 . V_79 ) ;
V_35 . V_36 = F_122 ( V_14 , V_2 ,
V_161 , ( V_355 + V_335 ) ) ;
if ( ! V_35 . V_36 )
goto V_368;
if ( V_14 -> V_37 <= V_41 ) {
F_129 ( V_14 , & V_14 -> V_78 ) ;
if ( V_14 -> V_119 . V_352 . V_149 )
V_33 |= V_150 ;
}
V_14 -> V_119 . V_352 . V_353 ++ ;
if ( V_357 ) {
V_33 |= V_369 ;
F_254 ( & V_24 -> V_130 , V_357 ) ;
}
F_43 ( & V_24 -> V_130 . V_79 ) ;
if ( V_14 -> V_365 ) {
if ( F_240 ( V_2 , V_35 . V_36 + V_355 -
sizeof( struct V_329 ) ,
F_241 () , true ) ) {
F_45 ( & V_24 -> V_130 . V_79 ) ;
goto V_368;
}
}
F_260 ( V_2 , 0 , V_35 . V_36 + V_355 , V_335 ) ;
if ( ! ( V_55 = F_58 ( V_2 , & V_46 , V_14 -> V_56 ) ) )
F_99 ( & V_46 ) ;
V_33 |= V_55 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_370 = V_2 -> V_174 ;
V_35 . V_39 -> V_371 = V_335 ;
V_35 . V_39 -> V_372 = V_355 ;
V_35 . V_39 -> V_373 = V_356 ;
V_35 . V_39 -> V_57 = V_46 . V_58 ;
V_35 . V_39 -> V_59 = V_46 . V_60 / V_61 ;
V_115 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_370 = V_2 -> V_174 ;
V_35 . V_42 -> V_371 = V_335 ;
V_35 . V_42 -> V_372 = V_355 ;
V_35 . V_42 -> V_373 = V_356 ;
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
V_35 . V_44 -> V_370 = V_2 -> V_174 ;
V_35 . V_44 -> V_371 = V_335 ;
V_35 . V_44 -> V_372 = V_355 ;
V_35 . V_44 -> V_373 = V_356 ;
V_35 . V_44 -> V_57 = V_46 . V_58 ;
V_35 . V_44 -> V_62 = V_46 . V_60 ;
memset ( V_35 . V_44 -> V_171 , 0 , sizeof( V_35 . V_44 -> V_171 ) ) ;
V_115 = sizeof( * V_35 . V_44 ) ;
break;
default:
F_54 () ;
}
V_332 = V_35 . V_36 + F_256 ( V_115 ) ;
V_332 -> V_349 = F_250 ( V_2 , V_332 -> V_350 ) ;
V_332 -> V_374 = V_375 ;
V_332 -> V_345 = V_4 -> type ;
V_332 -> V_376 = V_2 -> V_286 ;
V_332 -> V_346 = V_2 -> V_276 ;
if ( F_2 ( V_14 -> V_347 ) )
V_332 -> V_348 = V_224 -> V_93 ;
else
V_332 -> V_348 = V_4 -> V_93 ;
F_121 () ;
#if V_137 == 1
if ( V_14 -> V_37 <= V_41 ) {
T_4 * V_138 , * V_139 ;
V_139 = ( T_4 * ) F_96 ( ( unsigned long ) V_35 . V_36 +
V_355 + V_335 ) ;
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
V_340:
if ( V_333 != V_2 -> V_81 && F_246 ( V_2 ) ) {
V_2 -> V_81 = V_333 ;
V_2 -> V_174 = V_334 ;
}
V_10:
if ( ! V_336 )
F_248 ( V_2 ) ;
else
F_15 ( V_2 ) ;
return 0 ;
V_368:
V_336 = true ;
V_14 -> V_119 . V_352 . V_149 ++ ;
F_43 ( & V_24 -> V_130 . V_79 ) ;
V_24 -> V_156 ( V_24 ) ;
F_15 ( V_357 ) ;
goto V_340;
}
static void F_261 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_35 ( V_2 -> V_24 ) ;
if ( F_21 ( V_14 -> V_183 . V_69 ) ) {
void * V_377 ;
T_3 V_46 ;
V_377 = F_235 ( V_2 ) -> V_378 ;
F_133 ( & V_14 -> V_183 ) ;
V_46 = F_61 ( V_14 , V_377 , V_2 ) ;
F_51 ( V_14 , V_377 , V_170 | V_46 ) ;
}
F_262 ( V_2 ) ;
}
static void F_263 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( V_4 -> type == V_271 ) {
F_210 ( V_2 ) ;
V_2 -> V_286 = F_211 ( V_2 ) -> V_272 ;
}
}
static int F_264 ( struct V_329 * V_330 , T_7 V_174 )
{
if ( ( V_330 -> V_47 & V_379 ) &&
( F_265 ( F_241 () , V_330 -> V_380 ) +
F_265 ( F_241 () , V_330 -> V_381 ) + 2 >
F_265 ( F_241 () , V_330 -> V_382 ) ) )
V_330 -> V_382 = F_266 ( F_241 () ,
F_265 ( F_241 () , V_330 -> V_380 ) +
F_265 ( F_241 () , V_330 -> V_381 ) + 2 ) ;
if ( F_265 ( F_241 () , V_330 -> V_382 ) > V_174 )
return - V_248 ;
return 0 ;
}
static int F_267 ( struct V_288 * V_289 , T_7 * V_174 ,
struct V_329 * V_330 )
{
if ( * V_174 < sizeof( * V_330 ) )
return - V_248 ;
* V_174 -= sizeof( * V_330 ) ;
if ( ! F_268 ( V_330 , sizeof( * V_330 ) , & V_289 -> V_383 ) )
return - V_249 ;
return F_264 ( V_330 , * V_174 ) ;
}
static int F_269 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , void * V_81 , int V_370 ,
T_8 V_294 , unsigned char * V_31 , int V_384 , int V_385 ,
const struct V_292 * V_293 )
{
union V_34 V_377 ;
int V_386 , V_387 , V_174 , V_388 , V_389 ;
struct V_287 * V_23 = V_14 -> V_24 . V_390 ;
struct V_30 * V_30 ;
int V_92 ;
V_377 . V_36 = V_32 ;
V_2 -> V_286 = V_294 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_320 = V_14 -> V_24 . V_321 ;
V_2 -> V_322 = V_14 -> V_24 . V_323 ;
F_234 ( & V_14 -> V_24 , V_293 -> V_317 , & F_235 ( V_2 ) -> V_324 ) ;
F_235 ( V_2 ) -> V_378 = V_377 . V_36 ;
F_228 ( V_2 , V_384 ) ;
F_229 ( V_2 ) ;
V_386 = V_370 ;
if ( V_23 -> type == V_338 ) {
V_92 = F_270 ( V_2 , V_4 , F_115 ( V_294 ) , V_31 ,
NULL , V_370 ) ;
if ( F_2 ( V_92 < 0 ) )
return - V_248 ;
} else if ( V_385 ) {
int V_115 = F_163 ( int , V_385 , V_370 ) ;
F_218 ( V_2 , V_4 -> V_308 ) ;
F_231 ( V_2 , V_385 - V_4 -> V_308 ) ;
V_92 = F_271 ( V_2 , 0 , V_81 , V_115 ) ;
if ( F_2 ( V_92 ) )
return V_92 ;
if ( ! F_232 ( V_4 , V_2 -> V_81 , V_115 ) )
return - V_248 ;
if ( ! V_2 -> V_286 )
F_263 ( V_4 , V_2 ) ;
V_81 += V_115 ;
V_386 -= V_115 ;
}
V_387 = F_272 ( V_81 ) ;
V_389 = V_140 - V_387 ;
V_174 = ( ( V_386 > V_389 ) ? V_389 : V_386 ) ;
V_2 -> V_391 = V_386 ;
V_2 -> V_174 += V_386 ;
V_2 -> V_191 += V_386 ;
F_273 ( V_386 , & V_14 -> V_24 . V_198 ) ;
while ( F_21 ( V_386 ) ) {
V_388 = F_235 ( V_2 ) -> V_388 ;
if ( F_2 ( V_388 >= V_392 ) ) {
F_150 ( L_5 ,
V_392 ) ;
return - V_249 ;
}
V_30 = F_47 ( V_81 ) ;
V_81 += V_174 ;
F_52 ( V_30 ) ;
F_274 ( V_30 ) ;
F_275 ( V_2 , V_388 , V_30 , V_387 , V_174 ) ;
V_386 -= V_174 ;
V_387 = 0 ;
V_389 = V_140 ;
V_174 = ( ( V_386 > V_389 ) ? V_389 : V_386 ) ;
}
F_236 ( V_2 , 0 ) ;
return V_370 ;
}
static int F_276 ( struct V_13 * V_14 , void * V_32 ,
int V_393 , void * * V_81 )
{
union V_34 V_377 ;
int V_370 , V_394 ;
V_377 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( V_377 . V_44 -> V_152 != 0 ) {
F_277 ( L_6 ) ;
return - V_248 ;
}
V_370 = V_377 . V_44 -> V_370 ;
break;
case V_41 :
V_370 = V_377 . V_42 -> V_370 ;
break;
default:
V_370 = V_377 . V_39 -> V_370 ;
break;
}
if ( F_2 ( V_370 > V_393 ) ) {
F_150 ( L_7 , V_370 , V_393 ) ;
return - V_306 ;
}
if ( F_2 ( V_14 -> V_395 ) ) {
int V_396 , V_397 ;
V_396 = V_14 -> V_116 - sizeof( struct V_331 ) ;
V_397 = V_14 -> V_183 . V_71 - V_370 ;
if ( V_14 -> V_24 . V_337 == V_338 ) {
switch ( V_14 -> V_37 ) {
case V_43 :
V_394 = V_377 . V_44 -> V_373 ;
break;
case V_41 :
V_394 = V_377 . V_42 -> V_373 ;
break;
default:
V_394 = V_377 . V_39 -> V_373 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_43 :
V_394 = V_377 . V_44 -> V_372 ;
break;
case V_41 :
V_394 = V_377 . V_42 -> V_372 ;
break;
default:
V_394 = V_377 . V_39 -> V_372 ;
break;
}
}
if ( F_2 ( ( V_394 < V_396 ) || ( V_397 < V_394 ) ) )
return - V_248 ;
} else {
V_394 = V_14 -> V_116 - sizeof( struct V_331 ) ;
}
* V_81 = V_32 + V_394 ;
return V_370 ;
}
static int F_278 ( struct V_13 * V_14 , struct V_288 * V_289 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_329 * V_330 = NULL ;
struct V_292 V_293 ;
T_8 V_294 ;
int V_92 , V_398 = 0 ;
void * V_377 ;
F_223 ( struct V_331 * , V_290 , V_289 -> V_291 ) ;
bool V_399 = ! ( V_289 -> V_400 & V_401 ) ;
int V_370 , V_393 ;
unsigned char * V_31 ;
void * V_81 ;
int V_402 = 0 ;
int V_33 = V_170 ;
int V_384 , V_311 , V_385 = 0 ;
F_196 ( & V_14 -> V_403 ) ;
if ( F_21 ( V_290 == NULL ) ) {
V_4 = F_18 ( V_14 ) ;
V_294 = V_14 -> V_208 ;
V_31 = NULL ;
} else {
V_92 = - V_248 ;
if ( V_289 -> V_296 < sizeof( struct V_331 ) )
goto V_131;
if ( V_289 -> V_296 < ( V_290 -> V_349
+ F_279 ( struct V_331 ,
V_350 ) ) )
goto V_131;
V_294 = V_290 -> V_376 ;
V_31 = V_290 -> V_350 ;
V_4 = F_280 ( F_77 ( & V_14 -> V_24 ) , V_290 -> V_348 ) ;
}
V_92 = - V_404 ;
if ( F_2 ( V_4 == NULL ) )
goto V_131;
V_92 = - V_302 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_303 ) ) )
goto V_405;
V_293 . V_317 = V_14 -> V_24 . V_318 ;
if ( V_289 -> V_319 ) {
V_92 = F_233 ( & V_14 -> V_24 , V_289 , & V_293 ) ;
if ( F_2 ( V_92 ) )
goto V_405;
}
if ( V_14 -> V_24 . V_390 -> type == V_406 )
V_398 = V_4 -> V_308 ;
V_393 = V_14 -> V_183 . V_71
- ( V_14 -> V_116 - sizeof( struct V_331 ) ) ;
if ( ( V_393 > V_4 -> V_307 + V_398 + V_309 ) && ! V_14 -> V_365 )
V_393 = V_4 -> V_307 + V_398 + V_309 ;
do {
V_377 = F_63 ( V_14 , & V_14 -> V_183 ,
V_407 ) ;
if ( F_2 ( V_377 == NULL ) ) {
if ( V_399 && F_281 () )
F_282 () ;
continue;
}
V_2 = NULL ;
V_370 = F_276 ( V_14 , V_377 , V_393 , & V_81 ) ;
if ( V_370 < 0 )
goto V_408;
V_33 = V_407 ;
V_384 = F_226 ( V_4 ) ;
V_311 = V_4 -> V_312 ;
if ( V_14 -> V_365 ) {
V_330 = V_81 ;
V_81 += sizeof( * V_330 ) ;
V_370 -= sizeof( * V_330 ) ;
if ( V_370 < 0 ||
F_264 ( V_330 , V_370 ) ) {
V_370 = - V_248 ;
goto V_408;
}
V_385 = F_265 ( F_241 () ,
V_330 -> V_382 ) ;
}
V_385 = F_283 ( int , V_385 , V_4 -> V_308 ) ;
V_2 = F_284 ( & V_14 -> V_24 ,
V_384 + V_311 + sizeof( struct V_331 ) +
( V_385 - V_4 -> V_308 ) ,
! V_399 , & V_92 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_21 ( V_402 > 0 ) )
V_92 = V_402 ;
goto V_409;
}
V_370 = F_269 ( V_14 , V_2 , V_377 , V_4 , V_81 , V_370 , V_294 ,
V_31 , V_384 , V_385 , & V_293 ) ;
if ( F_21 ( V_370 >= 0 ) &&
V_370 > V_4 -> V_307 + V_398 &&
! V_14 -> V_365 &&
! F_209 ( V_4 , V_2 ) )
V_370 = - V_306 ;
if ( F_2 ( V_370 < 0 ) ) {
V_408:
if ( V_14 -> V_410 ) {
F_51 ( V_14 , V_377 ,
V_170 ) ;
F_130 ( & V_14 -> V_183 ) ;
F_15 ( V_2 ) ;
continue;
} else {
V_33 = V_411 ;
V_92 = V_370 ;
goto V_409;
}
}
if ( V_14 -> V_365 && F_285 ( V_2 , V_330 ,
F_241 () ) ) {
V_370 = - V_248 ;
goto V_408;
}
F_31 ( V_4 , V_2 ) ;
V_2 -> V_412 = F_261 ;
F_51 ( V_14 , V_377 , V_413 ) ;
F_131 ( & V_14 -> V_183 ) ;
V_33 = V_407 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_92 > 0 ) ) {
V_92 = F_286 ( V_92 ) ;
if ( V_92 && F_56 ( V_14 , V_377 ) ==
V_170 ) {
V_2 = NULL ;
goto V_409;
}
V_92 = 0 ;
}
F_130 ( & V_14 -> V_183 ) ;
V_402 += V_370 ;
} while ( F_21 ( ( V_377 != NULL ) ||
( V_399 && F_135 ( & V_14 -> V_183 ) ) ) );
V_92 = V_402 ;
goto V_405;
V_409:
F_51 ( V_14 , V_377 , V_33 ) ;
F_15 ( V_2 ) ;
V_405:
F_287 ( V_4 ) ;
V_131:
F_204 ( & V_14 -> V_403 ) ;
return V_92 ;
}
static struct V_1 * F_288 ( struct V_23 * V_24 , T_7 V_414 ,
T_7 V_398 , T_7 V_174 ,
T_7 V_415 , int V_416 ,
int * V_92 )
{
struct V_1 * V_2 ;
if ( V_414 + V_174 < V_140 || ! V_415 )
V_415 = V_174 ;
V_2 = F_289 ( V_24 , V_414 + V_415 , V_174 - V_415 , V_416 ,
V_92 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_228 ( V_2 , V_398 ) ;
F_231 ( V_2 , V_415 ) ;
V_2 -> V_391 = V_174 - V_415 ;
V_2 -> V_174 += V_174 - V_415 ;
return V_2 ;
}
static int F_290 ( struct V_287 * V_23 , struct V_288 * V_289 , T_7 V_174 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_223 ( struct V_331 * , V_290 , V_289 -> V_291 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_294 ;
unsigned char * V_31 ;
int V_92 , V_398 = 0 ;
struct V_292 V_293 ;
struct V_329 V_330 = { 0 } ;
int V_387 = 0 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_384 , V_311 , V_415 ;
int V_295 = 0 ;
if ( F_21 ( V_290 == NULL ) ) {
V_4 = F_18 ( V_14 ) ;
V_294 = V_14 -> V_208 ;
V_31 = NULL ;
} else {
V_92 = - V_248 ;
if ( V_289 -> V_296 < sizeof( struct V_331 ) )
goto V_131;
if ( V_289 -> V_296 < ( V_290 -> V_349 + F_279 ( struct V_331 , V_350 ) ) )
goto V_131;
V_294 = V_290 -> V_376 ;
V_31 = V_290 -> V_350 ;
V_4 = F_280 ( F_77 ( V_24 ) , V_290 -> V_348 ) ;
}
V_92 = - V_404 ;
if ( F_2 ( V_4 == NULL ) )
goto V_301;
V_92 = - V_302 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_303 ) ) )
goto V_301;
V_293 . V_317 = V_24 -> V_318 ;
V_293 . V_322 = V_24 -> V_323 ;
if ( V_289 -> V_319 ) {
V_92 = F_233 ( V_24 , V_289 , & V_293 ) ;
if ( F_2 ( V_92 ) )
goto V_301;
}
if ( V_23 -> type == V_406 )
V_398 = V_4 -> V_308 ;
if ( V_14 -> V_365 ) {
V_92 = F_267 ( V_289 , & V_174 , & V_330 ) ;
if ( V_92 )
goto V_301;
}
if ( F_2 ( F_149 ( V_24 , V_304 ) ) ) {
if ( ! F_225 ( V_4 ) ) {
V_92 = - V_305 ;
goto V_301;
}
V_295 = 4 ;
}
V_92 = - V_306 ;
if ( ! V_330 . V_417 &&
( V_174 > V_4 -> V_307 + V_398 + V_309 + V_295 ) )
goto V_301;
V_92 = - V_184 ;
V_384 = F_226 ( V_4 ) ;
V_311 = V_4 -> V_312 ;
V_415 = F_265 ( F_241 () , V_330 . V_382 ) ;
V_415 = F_291 ( V_415 , F_163 ( int , V_174 , V_4 -> V_308 ) ) ;
V_2 = F_288 ( V_24 , V_384 + V_311 , V_384 , V_174 , V_415 ,
V_289 -> V_400 & V_401 , & V_92 ) ;
if ( V_2 == NULL )
goto V_301;
F_292 ( V_2 , V_398 ) ;
V_92 = - V_248 ;
if ( V_23 -> type == V_338 ) {
V_387 = F_270 ( V_2 , V_4 , F_115 ( V_294 ) , V_31 , NULL , V_174 ) ;
if ( F_2 ( V_387 < 0 ) )
goto V_316;
}
V_92 = F_293 ( V_2 , V_387 , & V_289 -> V_383 , V_174 ) ;
if ( V_92 )
goto V_316;
if ( V_23 -> type == V_406 &&
! F_232 ( V_4 , V_2 -> V_81 , V_174 ) ) {
V_92 = - V_248 ;
goto V_316;
}
F_234 ( V_24 , V_293 . V_317 , & F_235 ( V_2 ) -> V_324 ) ;
if ( ! V_330 . V_417 && ( V_174 > V_4 -> V_307 + V_398 + V_295 ) &&
! F_209 ( V_4 , V_2 ) ) {
V_92 = - V_306 ;
goto V_316;
}
V_2 -> V_286 = V_294 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_320 = V_24 -> V_321 ;
V_2 -> V_322 = V_293 . V_322 ;
F_31 ( V_4 , V_2 ) ;
if ( V_14 -> V_365 ) {
V_92 = F_285 ( V_2 , & V_330 , F_241 () ) ;
if ( V_92 )
goto V_316;
V_174 += sizeof( V_330 ) ;
}
F_236 ( V_2 , V_398 ) ;
if ( F_2 ( V_295 == 4 ) )
V_2 -> V_325 = 1 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( V_92 > 0 && ( V_92 = F_286 ( V_92 ) ) != 0 )
goto V_301;
F_287 ( V_4 ) ;
return V_174 ;
V_316:
F_15 ( V_2 ) ;
V_301:
if ( V_4 )
F_287 ( V_4 ) ;
V_131:
return V_92 ;
}
static int F_294 ( struct V_287 * V_23 , struct V_288 * V_289 , T_7 V_174 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
if ( V_14 -> V_183 . V_69 )
return F_278 ( V_14 , V_289 ) ;
else
return F_290 ( V_23 , V_289 , V_174 ) ;
}
static int F_295 ( struct V_287 * V_23 )
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
F_196 ( & V_227 -> V_418 . V_419 ) ;
F_296 ( V_24 ) ;
F_204 ( & V_227 -> V_418 . V_419 ) ;
F_297 () ;
F_298 ( V_227 , V_24 -> V_420 , - 1 ) ;
F_299 () ;
F_45 ( & V_14 -> V_29 ) ;
F_46 ( V_24 , false ) ;
F_26 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_287 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_43 ( & V_14 -> V_29 ) ;
F_300 ( V_24 ) ;
if ( V_14 -> V_78 . V_69 ) {
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_301 ( V_24 , & V_101 , 1 , 0 ) ;
}
if ( V_14 -> V_183 . V_69 ) {
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_301 ( V_24 , & V_101 , 1 , 1 ) ;
}
V_207 = F_205 ( V_24 ) ;
F_44 () ;
if ( V_207 ) {
F_191 ( V_207 ) ;
F_203 ( V_207 ) ;
}
F_302 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_147 ( & V_24 -> V_130 ) ;
F_140 ( V_14 ) ;
F_303 ( V_24 ) ;
F_304 ( V_24 ) ;
return 0 ;
}
static int F_305 ( struct V_23 * V_24 , const char * V_284 , int V_93 ,
T_8 V_294 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_3 * V_421 ;
T_8 V_422 ;
bool V_423 ;
struct V_3 * V_4 = NULL ;
int V_8 = 0 ;
bool V_424 = false ;
if ( V_14 -> V_26 )
return - V_248 ;
F_306 ( V_24 ) ;
F_45 ( & V_14 -> V_29 ) ;
F_19 () ;
if ( V_284 ) {
V_4 = F_224 ( F_77 ( V_24 ) , V_284 ) ;
if ( ! V_4 ) {
V_8 = - V_300 ;
goto V_301;
}
} else if ( V_93 ) {
V_4 = F_307 ( F_77 ( V_24 ) , V_93 ) ;
if ( ! V_4 ) {
V_8 = - V_300 ;
goto V_301;
}
}
if ( V_4 )
F_22 ( V_4 ) ;
V_422 = V_14 -> V_27 . type ;
V_421 = V_14 -> V_27 . V_4 ;
V_423 = V_422 != V_294 || V_421 != V_4 ;
if ( V_423 ) {
if ( V_14 -> V_25 ) {
F_23 () ;
F_39 ( V_24 , true ) ;
F_19 () ;
V_421 = V_14 -> V_27 . V_4 ;
if ( V_4 )
V_424 = ! F_307 ( F_77 ( V_24 ) ,
V_4 -> V_93 ) ;
}
V_14 -> V_208 = V_294 ;
V_14 -> V_27 . type = V_294 ;
if ( F_2 ( V_424 ) ) {
F_287 ( V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
V_14 -> V_93 = - 1 ;
F_26 ( V_14 ) ;
} else {
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_93 = V_4 ? V_4 -> V_93 : 0 ;
F_24 ( V_14 , V_4 ) ;
}
}
if ( V_421 )
F_287 ( V_421 ) ;
if ( V_294 == 0 || ! V_423 )
goto V_301;
if ( ! V_424 && ( ! V_4 || ( V_4 -> V_47 & V_303 ) ) ) {
F_34 ( V_24 ) ;
} else {
V_24 -> V_425 = V_302 ;
if ( ! F_149 ( V_24 , V_199 ) )
V_24 -> V_426 ( V_24 ) ;
}
V_301:
F_23 () ;
F_43 ( & V_14 -> V_29 ) ;
F_308 ( V_24 ) ;
return V_8 ;
}
static int F_309 ( struct V_287 * V_23 , struct V_297 * V_427 ,
int V_428 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_284 [ sizeof( V_427 -> V_429 ) + 1 ] ;
if ( V_428 != sizeof( struct V_297 ) )
return - V_248 ;
memcpy ( V_284 , V_427 -> V_429 , sizeof( V_427 -> V_429 ) ) ;
V_284 [ sizeof( V_427 -> V_429 ) ] = 0 ;
return F_305 ( V_24 , V_284 , 0 , F_35 ( V_24 ) -> V_208 ) ;
}
static int F_310 ( struct V_287 * V_23 , struct V_297 * V_427 , int V_428 )
{
struct V_331 * V_332 = (struct V_331 * ) V_427 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_428 < sizeof( struct V_331 ) )
return - V_248 ;
if ( V_332 -> V_374 != V_375 )
return - V_248 ;
return F_305 ( V_24 , NULL , V_332 -> V_348 ,
V_332 -> V_376 ? : F_35 ( V_24 ) -> V_208 ) ;
}
static int F_311 ( struct V_227 * V_227 , struct V_287 * V_23 , int V_286 ,
int V_430 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_8 V_294 = ( V_431 T_8 ) V_286 ;
int V_92 ;
if ( ! F_312 ( V_227 -> V_432 , V_433 ) )
return - V_247 ;
if ( V_23 -> type != V_338 && V_23 -> type != V_406 &&
V_23 -> type != V_434 )
return - V_435 ;
V_23 -> V_436 = V_437 ;
V_92 = - V_184 ;
V_24 = F_313 ( V_227 , V_241 , V_262 , & V_438 , V_430 ) ;
if ( V_24 == NULL )
goto V_131;
V_23 -> V_19 = & V_439 ;
if ( V_23 -> type == V_434 )
V_23 -> V_19 = & V_440 ;
F_314 ( V_23 , V_24 ) ;
V_14 = F_35 ( V_24 ) ;
V_24 -> V_240 = V_241 ;
V_14 -> V_208 = V_294 ;
V_14 -> V_16 = F_237 ;
V_92 = F_138 ( V_14 ) ;
if ( V_92 )
goto V_441;
F_26 ( V_14 ) ;
V_24 -> V_442 = F_146 ;
F_315 ( V_24 ) ;
F_201 ( & V_14 -> V_29 ) ;
F_316 ( & V_14 -> V_403 ) ;
V_14 -> V_204 = NULL ;
V_14 -> V_27 . F_71 = F_243 ;
if ( V_23 -> type == V_434 )
V_14 -> V_27 . F_71 = F_213 ;
V_14 -> V_27 . V_225 = V_24 ;
if ( V_294 ) {
V_14 -> V_27 . type = V_294 ;
F_34 ( V_24 ) ;
}
F_196 ( & V_227 -> V_418 . V_419 ) ;
F_317 ( V_24 , & V_227 -> V_418 . V_443 ) ;
F_204 ( & V_227 -> V_418 . V_419 ) ;
F_297 () ;
F_298 ( V_227 , & V_438 , 1 ) ;
F_299 () ;
return 0 ;
V_441:
F_318 ( V_24 ) ;
V_131:
return V_92 ;
}
static int F_319 ( struct V_287 * V_23 , struct V_288 * V_289 , T_7 V_174 ,
int V_47 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_444 , V_92 ;
int V_445 = 0 ;
unsigned int V_351 = 0 ;
V_92 = - V_248 ;
if ( V_47 & ~ ( V_446 | V_401 | V_447 | V_448 | V_449 ) )
goto V_131;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_47 & V_449 ) {
V_92 = F_320 ( V_24 , V_289 , V_174 ,
V_450 , V_451 ) ;
goto V_131;
}
V_2 = F_321 ( V_24 , V_47 , V_47 & V_401 , & V_92 ) ;
if ( V_2 == NULL )
goto V_131;
if ( F_35 ( V_24 ) -> V_196 )
F_145 ( F_35 ( V_24 ) , NULL ) ;
if ( F_35 ( V_24 ) -> V_365 ) {
V_92 = F_239 ( V_289 , V_2 , & V_174 ) ;
if ( V_92 )
goto V_316;
V_445 = sizeof( struct V_329 ) ;
}
V_444 = V_2 -> V_174 ;
if ( V_444 > V_174 ) {
V_444 = V_174 ;
V_289 -> V_400 |= V_447 ;
}
V_92 = F_322 ( V_2 , 0 , V_289 , V_444 ) ;
if ( V_92 )
goto V_316;
if ( V_23 -> type != V_434 ) {
struct V_331 * V_332 = & F_217 ( V_2 ) -> V_280 . V_344 ;
V_351 = F_217 ( V_2 ) -> V_280 . V_351 ;
V_332 -> V_374 = V_375 ;
V_332 -> V_376 = V_2 -> V_286 ;
}
F_323 ( V_289 , V_24 , V_2 ) ;
if ( V_289 -> V_291 ) {
if ( V_23 -> type == V_434 ) {
F_324 ( sizeof( struct V_274 ) ) ;
V_289 -> V_296 = sizeof( struct V_274 ) ;
} else {
struct V_331 * V_332 = & F_217 ( V_2 ) -> V_280 . V_344 ;
V_289 -> V_296 = V_332 -> V_349 +
F_279 ( struct V_331 , V_350 ) ;
}
memcpy ( V_289 -> V_291 , & F_217 ( V_2 ) -> V_280 ,
V_289 -> V_296 ) ;
}
if ( F_35 ( V_24 ) -> V_452 ) {
struct V_453 V_454 ;
V_454 . V_40 = V_143 ;
if ( V_2 -> V_358 == V_359 )
V_454 . V_40 |= V_360 ;
else if ( V_2 -> V_276 != V_339 &&
( V_2 -> V_358 == V_361 ||
F_257 ( V_2 ) ) )
V_454 . V_40 |= V_362 ;
V_454 . V_370 = V_351 ;
V_454 . V_371 = V_2 -> V_174 ;
V_454 . V_372 = 0 ;
V_454 . V_373 = F_245 ( V_2 ) ;
if ( F_113 ( V_2 ) ) {
V_454 . V_165 = F_114 ( V_2 ) ;
V_454 . V_166 = F_115 ( V_2 -> V_167 ) ;
V_454 . V_40 |= V_168 | V_169 ;
} else {
V_454 . V_165 = 0 ;
V_454 . V_166 = 0 ;
}
F_325 ( V_289 , V_450 , V_455 , sizeof( V_454 ) , & V_454 ) ;
}
V_92 = V_445 + ( ( V_47 & V_447 ) ? V_2 -> V_174 : V_444 ) ;
V_316:
F_326 ( V_24 , V_2 ) ;
V_131:
return V_92 ;
}
static int F_327 ( struct V_287 * V_23 , struct V_297 * V_427 ,
int * V_456 , int V_457 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_457 )
return - V_458 ;
V_427 -> V_459 = V_375 ;
memset ( V_427 -> V_429 , 0 , sizeof( V_427 -> V_429 ) ) ;
F_19 () ;
V_4 = F_307 ( F_77 ( V_24 ) , F_35 ( V_24 ) -> V_93 ) ;
if ( V_4 )
F_220 ( V_427 -> V_429 , V_4 -> V_284 , sizeof( V_427 -> V_429 ) ) ;
F_23 () ;
* V_456 = sizeof( * V_427 ) ;
return 0 ;
}
static int F_328 ( struct V_287 * V_23 , struct V_297 * V_427 ,
int * V_456 , int V_457 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
F_223 ( struct V_331 * , V_332 , V_427 ) ;
if ( V_457 )
return - V_458 ;
V_332 -> V_374 = V_375 ;
V_332 -> V_348 = V_14 -> V_93 ;
V_332 -> V_376 = V_14 -> V_208 ;
V_332 -> V_346 = 0 ;
F_19 () ;
V_4 = F_307 ( F_77 ( V_24 ) , V_14 -> V_93 ) ;
if ( V_4 ) {
V_332 -> V_345 = V_4 -> type ;
V_332 -> V_349 = V_4 -> V_428 ;
memcpy ( V_332 -> V_350 , V_4 -> V_460 , V_4 -> V_428 ) ;
} else {
V_332 -> V_345 = 0 ;
V_332 -> V_349 = 0 ;
}
F_23 () ;
* V_456 = F_279 ( struct V_331 , V_350 ) + V_332 -> V_349 ;
return 0 ;
}
static int F_329 ( struct V_3 * V_4 , struct V_461 * V_201 ,
int V_462 )
{
switch ( V_201 -> type ) {
case V_463 :
if ( V_201 -> V_464 != V_4 -> V_428 )
return - V_248 ;
if ( V_462 > 0 )
return F_330 ( V_4 , V_201 -> V_31 ) ;
else
return F_331 ( V_4 , V_201 -> V_31 ) ;
break;
case V_465 :
return F_332 ( V_4 , V_462 ) ;
case V_466 :
return F_333 ( V_4 , V_462 ) ;
case V_467 :
if ( V_201 -> V_464 != V_4 -> V_428 )
return - V_248 ;
if ( V_462 > 0 )
return F_334 ( V_4 , V_201 -> V_31 ) ;
else
return F_335 ( V_4 , V_201 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_336 ( struct V_3 * V_4 ,
struct V_461 * * V_468 )
{
struct V_461 * V_469 ;
while ( ( V_469 = * V_468 ) != NULL ) {
if ( V_469 -> V_93 == V_4 -> V_93 ) {
F_329 ( V_4 , V_469 , - 1 ) ;
* V_468 = V_469 -> V_470 ;
F_203 ( V_469 ) ;
} else
V_468 = & V_469 -> V_470 ;
}
}
static int F_337 ( struct V_23 * V_24 , struct V_471 * V_472 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_461 * V_469 , * V_201 ;
struct V_3 * V_4 ;
int V_92 ;
F_75 () ;
V_92 = - V_300 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_472 -> V_473 ) ;
if ( ! V_4 )
goto V_474;
V_92 = - V_248 ;
if ( V_472 -> V_475 > V_4 -> V_428 )
goto V_474;
V_92 = - V_184 ;
V_201 = F_338 ( sizeof( * V_201 ) , V_262 ) ;
if ( V_201 == NULL )
goto V_474;
V_92 = 0 ;
for ( V_469 = V_14 -> V_476 ; V_469 ; V_469 = V_469 -> V_470 ) {
if ( V_469 -> V_93 == V_472 -> V_473 &&
V_469 -> type == V_472 -> V_477 &&
V_469 -> V_464 == V_472 -> V_475 &&
memcmp ( V_469 -> V_31 , V_472 -> V_478 , V_469 -> V_464 ) == 0 ) {
V_469 -> V_202 ++ ;
F_203 ( V_201 ) ;
goto V_474;
}
}
V_201 -> type = V_472 -> V_477 ;
V_201 -> V_93 = V_472 -> V_473 ;
V_201 -> V_464 = V_472 -> V_475 ;
memcpy ( V_201 -> V_31 , V_472 -> V_478 , V_201 -> V_464 ) ;
memset ( V_201 -> V_31 + V_201 -> V_464 , 0 , sizeof( V_201 -> V_31 ) - V_201 -> V_464 ) ;
V_201 -> V_202 = 1 ;
V_201 -> V_470 = V_14 -> V_476 ;
V_14 -> V_476 = V_201 ;
V_92 = F_329 ( V_4 , V_201 , 1 ) ;
if ( V_92 ) {
V_14 -> V_476 = V_201 -> V_470 ;
F_203 ( V_201 ) ;
}
V_474:
F_78 () ;
return V_92 ;
}
static int F_339 ( struct V_23 * V_24 , struct V_471 * V_472 )
{
struct V_461 * V_469 , * * V_468 ;
F_75 () ;
for ( V_468 = & F_35 ( V_24 ) -> V_476 ; ( V_469 = * V_468 ) != NULL ; V_468 = & V_469 -> V_470 ) {
if ( V_469 -> V_93 == V_472 -> V_473 &&
V_469 -> type == V_472 -> V_477 &&
V_469 -> V_464 == V_472 -> V_475 &&
memcmp ( V_469 -> V_31 , V_472 -> V_478 , V_469 -> V_464 ) == 0 ) {
if ( -- V_469 -> V_202 == 0 ) {
struct V_3 * V_4 ;
* V_468 = V_469 -> V_470 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_469 -> V_93 ) ;
if ( V_4 )
F_329 ( V_4 , V_469 , - 1 ) ;
F_203 ( V_469 ) ;
}
break;
}
}
F_78 () ;
return 0 ;
}
static void F_300 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_461 * V_469 ;
if ( ! V_14 -> V_476 )
return;
F_75 () ;
while ( ( V_469 = V_14 -> V_476 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_476 = V_469 -> V_470 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_469 -> V_93 ) ;
if ( V_4 != NULL )
F_329 ( V_4 , V_469 , - 1 ) ;
F_203 ( V_469 ) ;
}
F_78 () ;
}
static int
F_340 ( struct V_287 * V_23 , int V_479 , int V_480 , char T_6 * V_481 , unsigned int V_482 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_8 ;
if ( V_479 != V_450 )
return - V_483 ;
switch ( V_480 ) {
case V_484 :
case V_485 :
{
struct V_471 V_472 ;
int V_174 = V_482 ;
memset ( & V_472 , 0 , sizeof( V_472 ) ) ;
if ( V_174 < sizeof( struct V_486 ) )
return - V_248 ;
if ( V_174 > sizeof( V_472 ) )
V_174 = sizeof( V_472 ) ;
if ( F_184 ( & V_472 , V_481 , V_174 ) )
return - V_249 ;
if ( V_174 < ( V_472 . V_475 + F_279 ( struct V_486 , V_478 ) ) )
return - V_248 ;
if ( V_480 == V_484 )
V_8 = F_337 ( V_24 , & V_472 ) ;
else
V_8 = F_339 ( V_24 , & V_472 ) ;
return V_8 ;
}
case V_487 :
case V_488 :
{
union V_100 V_101 ;
int V_174 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_174 = sizeof( V_101 . V_489 ) ;
break;
case V_43 :
default:
V_174 = sizeof( V_101 . V_103 ) ;
break;
}
if ( V_482 < V_174 )
return - V_248 ;
if ( F_184 ( & V_101 . V_489 , V_481 , V_174 ) )
return - V_249 ;
return F_301 ( V_24 , & V_101 , 0 ,
V_480 == V_488 ) ;
}
case V_490 :
{
int V_209 ;
if ( V_482 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
F_35 ( V_24 ) -> V_366 = V_209 ;
return 0 ;
}
case V_491 :
{
int V_209 ;
if ( V_482 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
switch ( V_209 ) {
case V_38 :
case V_41 :
case V_43 :
break;
default:
return - V_248 ;
}
F_306 ( V_24 ) ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 ) {
V_8 = - V_492 ;
} else {
V_14 -> V_37 = V_209 ;
V_8 = 0 ;
}
F_308 ( V_24 ) ;
return V_8 ;
}
case V_493 :
{
unsigned int V_209 ;
if ( V_482 != sizeof( V_209 ) )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_492 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
if ( V_209 > V_494 )
return - V_248 ;
V_14 -> V_363 = V_209 ;
return 0 ;
}
case V_495 :
{
unsigned int V_209 ;
if ( V_482 != sizeof( V_209 ) )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_492 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_410 = ! ! V_209 ;
return 0 ;
}
case V_455 :
{
int V_209 ;
if ( V_482 < sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_452 = ! ! V_209 ;
return 0 ;
}
case V_496 :
{
int V_209 ;
if ( V_482 < sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_347 = ! ! V_209 ;
return 0 ;
}
case V_497 :
{
int V_209 ;
if ( V_23 -> type != V_406 )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_492 ;
if ( V_482 < sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_365 = ! ! V_209 ;
return 0 ;
}
case V_498 :
{
int V_209 ;
if ( V_482 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_56 = V_209 ;
return 0 ;
}
case V_499 :
{
int V_209 ;
if ( V_482 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
return F_195 ( V_24 , V_209 & 0xffff , V_209 >> 16 ) ;
}
case V_500 :
{
if ( ! V_14 -> V_26 )
return - V_248 ;
return F_190 ( V_14 , V_481 , V_482 ) ;
}
case V_501 :
{
unsigned int V_209 ;
if ( V_482 != sizeof( V_209 ) )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_492 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_395 = ! ! V_209 ;
return 0 ;
}
case V_502 :
{
int V_209 ;
if ( V_482 != sizeof( V_209 ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_481 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_16 = V_209 ? F_1 : F_237 ;
return 0 ;
}
default:
return - V_483 ;
}
}
static int F_341 ( struct V_287 * V_23 , int V_479 , int V_480 ,
char T_6 * V_481 , int T_6 * V_482 )
{
int V_174 ;
int V_209 , V_503 = sizeof( V_209 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
void * V_81 = & V_209 ;
union V_504 V_505 ;
struct V_506 V_507 ;
if ( V_479 != V_450 )
return - V_483 ;
if ( F_342 ( V_174 , V_482 ) )
return - V_249 ;
if ( V_174 < 0 )
return - V_248 ;
switch ( V_480 ) {
case V_508 :
F_68 ( & V_24 -> V_130 . V_79 ) ;
memcpy ( & V_505 , & V_14 -> V_119 , sizeof( V_505 ) ) ;
memset ( & V_14 -> V_119 , 0 , sizeof( V_14 -> V_119 ) ) ;
F_69 ( & V_24 -> V_130 . V_79 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_503 = sizeof( struct V_509 ) ;
V_505 . V_120 . V_353 += V_505 . V_120 . V_149 ;
V_81 = & V_505 . V_120 ;
} else {
V_503 = sizeof( struct V_510 ) ;
V_505 . V_352 . V_353 += V_505 . V_352 . V_149 ;
V_81 = & V_505 . V_352 ;
}
break;
case V_455 :
V_209 = V_14 -> V_452 ;
break;
case V_496 :
V_209 = V_14 -> V_347 ;
break;
case V_497 :
V_209 = V_14 -> V_365 ;
break;
case V_491 :
V_209 = V_14 -> V_37 ;
break;
case V_511 :
if ( V_174 > sizeof( int ) )
V_174 = sizeof( int ) ;
if ( V_174 < sizeof( int ) )
return - V_248 ;
if ( F_184 ( & V_209 , V_481 , V_174 ) )
return - V_249 ;
switch ( V_209 ) {
case V_38 :
V_209 = sizeof( struct V_512 ) ;
break;
case V_41 :
V_209 = sizeof( struct V_513 ) ;
break;
case V_43 :
V_209 = sizeof( struct V_144 ) ;
break;
default:
return - V_248 ;
}
break;
case V_493 :
V_209 = V_14 -> V_363 ;
break;
case V_495 :
V_209 = V_14 -> V_410 ;
break;
case V_498 :
V_209 = V_14 -> V_56 ;
break;
case V_499 :
V_209 = ( V_14 -> V_26 ?
( ( T_5 ) V_14 -> V_26 -> V_253 |
( ( T_5 ) V_14 -> V_26 -> type << 16 ) |
( ( T_5 ) V_14 -> V_26 -> V_47 << 24 ) ) :
0 ) ;
break;
case V_514 :
if ( ! V_14 -> V_204 )
return - V_248 ;
V_507 . V_515 = F_343 ( & V_14 -> V_204 -> V_208 ) ;
V_507 . V_516 = F_343 ( & V_14 -> V_204 -> V_217 ) ;
V_507 . V_517 = F_343 ( & V_14 -> V_204 -> V_218 ) ;
V_81 = & V_507 ;
V_503 = sizeof( V_507 ) ;
break;
case V_501 :
V_209 = V_14 -> V_395 ;
break;
case V_502 :
V_209 = F_28 ( V_14 ) ;
break;
default:
return - V_483 ;
}
if ( V_174 > V_503 )
V_174 = V_503 ;
if ( F_344 ( V_174 , V_482 ) )
return - V_249 ;
if ( F_345 ( V_481 , V_81 , V_174 ) )
return - V_249 ;
return 0 ;
}
static int F_346 ( struct V_287 * V_23 , int V_479 , int V_480 ,
char T_6 * V_481 , unsigned int V_482 )
{
struct V_13 * V_14 = F_35 ( V_23 -> V_24 ) ;
if ( V_479 != V_450 )
return - V_483 ;
if ( V_480 == V_500 &&
V_14 -> V_26 && V_14 -> V_26 -> type == V_236 ) {
V_481 = ( char T_6 * ) F_347 ( V_481 ) ;
if ( ! V_481 )
return - V_249 ;
V_482 = sizeof( struct V_244 ) ;
}
return F_340 ( V_23 , V_479 , V_480 , V_481 , V_482 ) ;
}
static int F_348 ( struct V_518 * V_519 ,
unsigned long V_289 , void * V_520 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_349 ( V_520 ) ;
struct V_227 * V_227 = F_173 ( V_4 ) ;
F_19 () ;
F_350 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_35 ( V_24 ) ;
switch ( V_289 ) {
case V_521 :
if ( V_14 -> V_476 )
F_336 ( V_4 , & V_14 -> V_476 ) ;
case V_522 :
if ( V_4 -> V_93 == V_14 -> V_93 ) {
F_45 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_39 ( V_24 , false ) ;
V_24 -> V_425 = V_302 ;
if ( ! F_149 ( V_24 , V_199 ) )
V_24 -> V_426 ( V_24 ) ;
}
if ( V_289 == V_521 ) {
F_26 ( V_14 ) ;
V_14 -> V_93 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_287 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_43 ( & V_14 -> V_29 ) ;
}
break;
case V_523 :
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
return V_524 ;
}
static int F_351 ( struct V_287 * V_23 , unsigned int V_525 ,
unsigned long V_526 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_525 ) {
case V_527 :
{
int V_528 = F_352 ( V_24 ) ;
return F_344 ( V_528 , ( int T_6 * ) V_526 ) ;
}
case V_529 :
{
struct V_1 * V_2 ;
int V_528 = 0 ;
F_68 ( & V_24 -> V_130 . V_79 ) ;
V_2 = F_353 ( & V_24 -> V_130 ) ;
if ( V_2 )
V_528 = V_2 -> V_174 ;
F_69 ( & V_24 -> V_130 . V_79 ) ;
return F_344 ( V_528 , ( int T_6 * ) V_526 ) ;
}
case V_530 :
return F_354 ( V_24 , (struct V_531 T_6 * ) V_526 ) ;
case V_532 :
return F_355 ( V_24 , (struct V_45 T_6 * ) V_526 ) ;
#ifdef F_356
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
case V_543 :
case V_544 :
case V_545 :
case V_546 :
return V_547 . V_548 ( V_23 , V_525 , V_526 ) ;
#endif
default:
return - V_549 ;
}
return 0 ;
}
static unsigned int F_357 ( struct V_550 * V_550 , struct V_287 * V_23 ,
T_9 * V_551 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
unsigned int V_552 = F_358 ( V_550 , V_23 , V_551 ) ;
F_68 ( & V_24 -> V_130 . V_79 ) ;
if ( V_14 -> V_78 . V_69 ) {
if ( ! F_127 ( V_14 , & V_14 -> V_78 ,
V_161 ) )
V_552 |= V_553 | V_554 ;
}
if ( V_14 -> V_196 && F_144 ( V_14 , NULL ) == V_193 )
V_14 -> V_196 = 0 ;
F_69 ( & V_24 -> V_130 . V_79 ) ;
F_68 ( & V_24 -> V_555 . V_79 ) ;
if ( V_14 -> V_183 . V_69 ) {
if ( F_63 ( V_14 , & V_14 -> V_183 , V_170 ) )
V_552 |= V_556 | V_557 ;
}
F_69 ( & V_24 -> V_555 . V_79 ) ;
return V_552 ;
}
static void F_359 ( struct V_558 * V_559 )
{
struct V_550 * V_550 = V_559 -> V_560 ;
struct V_287 * V_23 = V_550 -> V_561 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_119 ( & F_35 ( V_24 ) -> V_562 ) ;
}
static void F_360 ( struct V_558 * V_559 )
{
struct V_550 * V_550 = V_559 -> V_560 ;
struct V_287 * V_23 = V_550 -> V_561 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_108 ( & F_35 ( V_24 ) -> V_562 ) ;
}
static void F_361 ( struct V_105 * V_69 , unsigned int V_563 ,
unsigned int V_174 )
{
int V_201 ;
for ( V_201 = 0 ; V_201 < V_174 ; V_201 ++ ) {
if ( F_21 ( V_69 [ V_201 ] . V_70 ) ) {
if ( F_48 ( V_69 [ V_201 ] . V_70 ) )
F_362 ( V_69 [ V_201 ] . V_70 ) ;
else
F_363 ( ( unsigned long ) V_69 [ V_201 ] . V_70 ,
V_563 ) ;
V_69 [ V_201 ] . V_70 = NULL ;
}
}
F_203 ( V_69 ) ;
}
static char * F_364 ( unsigned long V_563 )
{
char * V_70 ;
T_10 V_564 = V_262 | V_565 |
V_566 | V_567 | V_568 ;
V_70 = ( char * ) F_365 ( V_564 , V_563 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_366 ( ( 1 << V_563 ) * V_140 ) ;
if ( V_70 )
return V_70 ;
V_564 &= ~ V_568 ;
V_70 = ( char * ) F_365 ( V_564 , V_563 ) ;
if ( V_70 )
return V_70 ;
return NULL ;
}
static struct V_105 * F_367 ( struct V_569 * V_489 , int V_563 )
{
unsigned int V_570 = V_489 -> V_114 ;
struct V_105 * V_69 ;
int V_201 ;
V_69 = F_368 ( V_570 , sizeof( struct V_105 ) , V_262 ) ;
if ( F_2 ( ! V_69 ) )
goto V_131;
for ( V_201 = 0 ; V_201 < V_570 ; V_201 ++ ) {
V_69 [ V_201 ] . V_70 = F_364 ( V_563 ) ;
if ( F_2 ( ! V_69 [ V_201 ] . V_70 ) )
goto V_571;
}
V_131:
return V_69 ;
V_571:
F_361 ( V_69 , V_563 , V_570 ) ;
V_69 = NULL ;
goto V_131;
}
static int F_301 ( struct V_23 * V_24 , union V_100 * V_101 ,
int V_572 , int V_183 )
{
struct V_105 * V_69 = NULL ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_573 , V_563 = 0 ;
struct V_63 * V_64 ;
struct V_76 * V_77 ;
T_8 V_208 ;
int V_92 = - V_248 ;
struct V_569 * V_489 = & V_101 -> V_489 ;
F_306 ( V_24 ) ;
V_64 = V_183 ? & V_14 -> V_183 : & V_14 -> V_78 ;
V_77 = V_183 ? & V_24 -> V_555 : & V_24 -> V_130 ;
V_92 = - V_492 ;
if ( ! V_572 ) {
if ( F_90 ( & V_14 -> V_562 ) )
goto V_131;
if ( F_135 ( V_64 ) )
goto V_131;
}
if ( V_489 -> V_114 ) {
V_92 = - V_492 ;
if ( F_2 ( V_64 -> V_69 ) )
goto V_131;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_116 = V_574 ;
break;
case V_41 :
V_14 -> V_116 = V_575 ;
break;
case V_43 :
V_14 -> V_116 = V_576 ;
break;
}
V_92 = - V_248 ;
if ( F_2 ( ( int ) V_489 -> V_112 <= 0 ) )
goto V_131;
if ( F_2 ( ! F_369 ( V_489 -> V_112 ) ) )
goto V_131;
if ( V_14 -> V_37 >= V_43 &&
V_489 -> V_112 <=
F_83 ( ( V_577 ) V_101 -> V_103 . V_126 ) )
goto V_131;
if ( F_2 ( V_489 -> V_578 < V_14 -> V_116 +
V_14 -> V_363 ) )
goto V_131;
if ( F_2 ( V_489 -> V_578 & ( V_579 - 1 ) ) )
goto V_131;
V_64 -> V_68 = V_489 -> V_112 / V_489 -> V_578 ;
if ( F_2 ( V_64 -> V_68 == 0 ) )
goto V_131;
if ( F_2 ( V_489 -> V_112 > V_580 / V_489 -> V_114 ) )
goto V_131;
if ( F_2 ( ( V_64 -> V_68 * V_489 -> V_114 ) !=
V_489 -> V_581 ) )
goto V_131;
V_92 = - V_261 ;
V_563 = F_370 ( V_489 -> V_112 ) ;
V_69 = F_367 ( V_489 , V_563 ) ;
if ( F_2 ( ! V_69 ) )
goto V_131;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( ! V_183 ) {
F_81 ( V_14 , V_64 , V_69 , V_101 ) ;
} else {
struct V_582 * V_103 = & V_101 -> V_103 ;
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
if ( F_2 ( V_489 -> V_581 ) )
goto V_131;
}
F_45 ( & V_14 -> V_29 ) ;
V_573 = V_14 -> V_25 ;
V_208 = V_14 -> V_208 ;
if ( V_573 ) {
V_14 -> V_208 = 0 ;
F_39 ( V_24 , false ) ;
}
F_43 ( & V_14 -> V_29 ) ;
F_44 () ;
V_92 = - V_492 ;
F_196 ( & V_14 -> V_403 ) ;
if ( V_572 || F_90 ( & V_14 -> V_562 ) == 0 ) {
V_92 = 0 ;
F_68 ( & V_77 -> V_79 ) ;
F_371 ( V_64 -> V_69 , V_69 ) ;
V_64 -> V_178 = ( V_489 -> V_581 - 1 ) ;
V_64 -> V_72 = 0 ;
V_64 -> V_71 = V_489 -> V_578 ;
F_69 ( & V_77 -> V_79 ) ;
F_371 ( V_64 -> V_583 , V_563 ) ;
F_371 ( V_64 -> V_584 , V_489 -> V_114 ) ;
V_64 -> V_585 = V_489 -> V_112 / V_140 ;
V_14 -> V_27 . F_71 = ( V_14 -> V_78 . V_69 ) ?
V_187 : F_243 ;
F_147 ( V_77 ) ;
if ( F_90 ( & V_14 -> V_562 ) )
F_150 ( L_8 ,
F_90 ( & V_14 -> V_562 ) ) ;
}
F_204 ( & V_14 -> V_403 ) ;
F_45 ( & V_14 -> V_29 ) ;
if ( V_573 ) {
V_14 -> V_208 = V_208 ;
F_34 ( V_24 ) ;
}
F_43 ( & V_14 -> V_29 ) ;
if ( V_572 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_183 )
F_66 ( V_14 , V_77 ) ;
}
if ( V_69 )
F_361 ( V_69 , V_563 , V_489 -> V_114 ) ;
V_131:
F_308 ( V_24 ) ;
return V_92 ;
}
static int F_372 ( struct V_550 * V_550 , struct V_287 * V_23 ,
struct V_558 * V_559 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
unsigned long V_586 , V_587 ;
struct V_63 * V_64 ;
unsigned long V_138 ;
int V_92 = - V_248 ;
int V_201 ;
if ( V_559 -> V_588 )
return - V_248 ;
F_196 ( & V_14 -> V_403 ) ;
V_587 = 0 ;
for ( V_64 = & V_14 -> V_78 ; V_64 <= & V_14 -> V_183 ; V_64 ++ ) {
if ( V_64 -> V_69 ) {
V_587 += V_64 -> V_584
* V_64 -> V_585
* V_140 ;
}
}
if ( V_587 == 0 )
goto V_131;
V_586 = V_559 -> V_589 - V_559 -> V_590 ;
if ( V_586 != V_587 )
goto V_131;
V_138 = V_559 -> V_590 ;
for ( V_64 = & V_14 -> V_78 ; V_64 <= & V_14 -> V_183 ; V_64 ++ ) {
if ( V_64 -> V_69 == NULL )
continue;
for ( V_201 = 0 ; V_201 < V_64 -> V_584 ; V_201 ++ ) {
struct V_30 * V_30 ;
void * V_591 = V_64 -> V_69 [ V_201 ] . V_70 ;
int V_592 ;
for ( V_592 = 0 ; V_592 < V_64 -> V_585 ; V_592 ++ ) {
V_30 = F_47 ( V_591 ) ;
V_92 = F_373 ( V_559 , V_138 , V_30 ) ;
if ( F_2 ( V_92 ) )
goto V_131;
V_138 += V_140 ;
V_591 += V_140 ;
}
}
}
F_119 ( & V_14 -> V_562 ) ;
V_559 -> V_593 = & V_594 ;
V_92 = 0 ;
V_131:
F_204 ( & V_14 -> V_403 ) ;
return V_92 ;
}
static void * F_374 ( struct V_595 * V_596 , T_11 * V_597 )
__acquires( T_12 )
{
struct V_227 * V_227 = F_375 ( V_596 ) ;
F_19 () ;
return F_376 ( & V_227 -> V_418 . V_443 , * V_597 ) ;
}
static void * F_377 ( struct V_595 * V_596 , void * V_598 , T_11 * V_597 )
{
struct V_227 * V_227 = F_375 ( V_596 ) ;
return F_378 ( V_598 , & V_227 -> V_418 . V_443 , V_597 ) ;
}
static void F_379 ( struct V_595 * V_596 , void * V_598 )
__releases( T_12 )
{
F_23 () ;
}
static int F_380 ( struct V_595 * V_596 , void * V_598 )
{
if ( V_598 == V_599 )
F_381 ( V_596 , L_9 ) ;
else {
struct V_23 * V_600 = F_382 ( V_598 ) ;
const struct V_13 * V_14 = F_35 ( V_600 ) ;
F_383 ( V_596 ,
L_10 ,
V_600 ,
F_90 ( & V_600 -> V_601 ) ,
V_600 -> V_337 ,
F_115 ( V_14 -> V_208 ) ,
V_14 -> V_93 ,
V_14 -> V_25 ,
F_90 ( & V_600 -> V_190 ) ,
F_384 ( F_385 ( V_596 ) , F_386 ( V_600 ) ) ,
F_387 ( V_600 ) ) ;
}
return 0 ;
}
static int F_388 ( struct V_602 * V_602 , struct V_550 * V_550 )
{
return F_389 ( V_602 , V_550 , & V_603 ,
sizeof( struct V_604 ) ) ;
}
static int T_13 F_390 ( struct V_227 * V_227 )
{
F_316 ( & V_227 -> V_418 . V_419 ) ;
F_391 ( & V_227 -> V_418 . V_443 ) ;
if ( ! F_392 ( L_11 , 0 , V_227 -> V_605 , & V_606 ) )
return - V_261 ;
return 0 ;
}
static void T_14 F_393 ( struct V_227 * V_227 )
{
F_394 ( L_11 , V_227 -> V_605 ) ;
}
static void T_15 F_395 ( void )
{
F_396 ( & V_607 ) ;
F_397 ( & V_608 ) ;
F_398 ( V_241 ) ;
F_399 ( & V_438 ) ;
}
static int T_16 F_400 ( void )
{
int V_609 = F_401 ( & V_438 , 0 ) ;
if ( V_609 != 0 )
goto V_131;
F_402 ( & V_610 ) ;
F_403 ( & V_608 ) ;
F_404 ( & V_607 ) ;
V_131:
return V_609 ;
}
