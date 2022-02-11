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
F_6 ( V_4 , V_2 ) ;
V_7 = F_7 ( V_4 , V_2 ) ;
F_8 () ;
F_9 ( V_4 , V_7 , F_10 () ) ;
if ( ! F_11 ( V_7 ) )
V_8 = F_12 ( V_2 , V_4 , V_7 , false ) ;
F_13 ( V_4 , V_7 ) ;
F_14 () ;
if ( ! F_15 ( V_8 ) )
F_16 ( V_2 ) ;
return V_8 ;
V_10:
F_17 ( & V_4 -> V_11 ) ;
F_18 ( V_2 ) ;
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
static T_1 F_30 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
return ( T_1 ) F_31 () % V_4 -> V_17 ;
}
static void F_6 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
const struct V_18 * V_19 = V_4 -> V_20 ;
T_1 V_21 ;
if ( V_19 -> V_22 ) {
V_21 = V_19 -> V_22 ( V_4 , V_2 , NULL ,
F_30 ) ;
V_21 = F_32 ( V_4 , V_21 ) ;
} else {
V_21 = F_30 ( V_4 , V_2 ) ;
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
if ( F_94 ( V_107 ) ) {
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
if ( F_22 ( V_161 == F_97 ( V_107 ) ) ) {
if ( ! ( V_33 & V_134 ) ) {
while ( F_90 ( & V_74 -> V_132 ) ) {
F_91 () ;
}
}
F_98 ( V_74 , V_107 , V_14 , V_33 ) ;
return;
}
}
static int F_94 ( struct V_106 * V_107 )
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
if ( F_94 ( V_107 ) ) {
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
F_148 ( F_149 ( & V_24 -> V_198 ) ) ;
if ( ! F_150 ( V_24 , V_199 ) ) {
F_151 ( L_3 , V_24 ) ;
return;
}
F_152 ( V_24 ) ;
}
static bool F_153 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
T_5 V_200 ;
int V_201 , V_202 = 0 ;
V_200 = F_110 ( V_2 ) ;
for ( V_201 = 0 ; V_201 < V_203 ; V_201 ++ )
if ( V_14 -> V_204 -> V_205 [ V_201 ] == V_200 )
V_202 ++ ;
V_14 -> V_204 -> V_205 [ F_154 () % V_203 ] = V_200 ;
return V_202 > ( V_203 >> 1 ) ;
}
static unsigned int F_155 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
return F_156 ( F_157 ( V_2 ) , V_208 ) ;
}
static unsigned int F_158 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
unsigned int V_209 = F_159 ( & V_207 -> V_210 ) ;
return V_209 % V_208 ;
}
static unsigned int F_160 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
return F_10 () % V_208 ;
}
static unsigned int F_161 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
return F_162 ( V_208 ) ;
}
static unsigned int F_163 ( struct V_206 * V_207 ,
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
( V_215 == V_194 && ! F_153 ( V_14 , V_2 ) ) )
return V_175 ;
V_213 = V_14 ;
}
V_201 = V_214 = F_164 ( int , V_14 -> V_204 -> V_23 , V_208 - 1 ) ;
do {
V_212 = F_35 ( V_207 -> V_216 [ V_201 ] ) ;
if ( V_212 != V_213 && ! V_212 -> V_196 &&
F_145 ( V_212 , V_2 ) == V_193 ) {
if ( V_201 != V_214 )
V_14 -> V_204 -> V_23 = V_201 ;
F_17 ( & V_14 -> V_204 -> V_208 ) ;
if ( V_215 == V_194 )
F_17 ( & V_14 -> V_204 -> V_217 ) ;
return V_201 ;
}
if ( ++ V_201 == V_208 )
V_201 = 0 ;
} while ( V_201 != V_214 );
F_17 ( & V_14 -> V_204 -> V_218 ) ;
return V_175 ;
}
static unsigned int F_165 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
return F_166 ( V_2 ) % V_208 ;
}
static unsigned int F_167 ( struct V_206 * V_207 ,
struct V_1 * V_2 ,
unsigned int V_208 )
{
struct V_219 * V_220 ;
unsigned int V_8 = 0 ;
F_20 () ;
V_220 = F_21 ( V_207 -> V_219 ) ;
if ( V_220 )
V_8 = F_168 ( V_220 , V_2 ) % V_208 ;
F_24 () ;
return V_8 ;
}
static bool F_169 ( struct V_206 * V_207 , T_1 V_221 )
{
return V_207 -> V_47 & ( V_221 >> 8 ) ;
}
static int F_170 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_222 * V_223 , struct V_3 * V_224 )
{
struct V_206 * V_207 = V_223 -> V_225 ;
unsigned int V_208 = F_171 ( V_207 -> V_226 ) ;
struct V_227 * V_227 = F_172 ( & V_207 -> V_227 ) ;
struct V_13 * V_14 ;
unsigned int V_175 ;
if ( ! F_173 ( F_174 ( V_4 ) , V_227 ) || ! V_208 ) {
F_16 ( V_2 ) ;
return 0 ;
}
if ( F_169 ( V_207 , V_228 ) ) {
V_2 = F_175 ( V_227 , V_2 , V_229 ) ;
if ( ! V_2 )
return 0 ;
}
switch ( V_207 -> type ) {
case V_230 :
default:
V_175 = F_155 ( V_207 , V_2 , V_208 ) ;
break;
case V_231 :
V_175 = F_158 ( V_207 , V_2 , V_208 ) ;
break;
case V_232 :
V_175 = F_160 ( V_207 , V_2 , V_208 ) ;
break;
case V_233 :
V_175 = F_161 ( V_207 , V_2 , V_208 ) ;
break;
case V_234 :
V_175 = F_165 ( V_207 , V_2 , V_208 ) ;
break;
case V_235 :
V_175 = F_163 ( V_207 , V_2 , 0 , false , V_208 ) ;
break;
case V_236 :
case V_237 :
V_175 = F_167 ( V_207 , V_2 , V_208 ) ;
break;
}
if ( F_169 ( V_207 , V_238 ) )
V_175 = F_163 ( V_207 , V_2 , V_175 , true , V_208 ) ;
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
F_176 ( V_201 >= V_207 -> V_226 ) ;
V_207 -> V_216 [ V_201 ] = V_207 -> V_216 [ V_207 -> V_226 - 1 ] ;
V_207 -> V_226 -- ;
if ( V_207 -> V_226 == 0 )
F_41 ( & V_207 -> V_27 ) ;
F_43 ( & V_207 -> V_79 ) ;
}
static bool F_177 ( struct V_222 * V_239 , struct V_23 * V_24 )
{
if ( V_24 -> V_240 != V_241 )
return false ;
return V_239 -> V_225 == F_35 ( V_24 ) -> V_26 ;
}
static void F_178 ( struct V_206 * V_207 )
{
switch ( V_207 -> type ) {
case V_231 :
F_179 ( & V_207 -> V_210 , 0 ) ;
break;
case V_236 :
case V_237 :
F_28 ( V_207 -> V_219 , NULL ) ;
break;
}
}
static void F_180 ( struct V_206 * V_207 , struct V_219 * V_242 )
{
struct V_219 * V_243 ;
F_45 ( & V_207 -> V_79 ) ;
V_243 = F_181 ( V_207 -> V_219 , F_182 ( & V_207 -> V_79 ) ) ;
F_26 ( V_207 -> V_219 , V_242 ) ;
F_43 ( & V_207 -> V_79 ) ;
if ( V_243 ) {
F_44 () ;
F_183 ( V_243 ) ;
}
}
static int F_184 ( struct V_13 * V_14 , char T_6 * V_81 ,
unsigned int V_174 )
{
struct V_219 * V_242 ;
struct V_244 V_245 ;
int V_8 ;
if ( F_150 ( & V_14 -> V_24 , V_246 ) )
return - V_247 ;
if ( V_174 != sizeof( V_245 ) )
return - V_248 ;
if ( F_185 ( & V_245 , V_81 , V_174 ) )
return - V_249 ;
V_8 = F_186 ( & V_242 , & V_245 , NULL , false ) ;
if ( V_8 )
return V_8 ;
F_180 ( V_14 -> V_26 , V_242 ) ;
return 0 ;
}
static int F_187 ( struct V_13 * V_14 , char T_6 * V_81 ,
unsigned int V_174 )
{
struct V_219 * V_242 ;
T_5 V_250 ;
if ( F_150 ( & V_14 -> V_24 , V_246 ) )
return - V_247 ;
if ( V_174 != sizeof( V_250 ) )
return - V_248 ;
if ( F_185 ( & V_250 , V_81 , V_174 ) )
return - V_249 ;
V_242 = F_188 ( V_250 , V_251 ) ;
if ( F_189 ( V_242 ) )
return F_190 ( V_242 ) ;
F_180 ( V_14 -> V_26 , V_242 ) ;
return 0 ;
}
static int F_191 ( struct V_13 * V_14 , char T_6 * V_81 ,
unsigned int V_174 )
{
switch ( V_14 -> V_26 -> type ) {
case V_236 :
return F_184 ( V_14 , V_81 , V_174 ) ;
case V_237 :
return F_187 ( V_14 , V_81 , V_174 ) ;
default:
return - V_248 ;
} ;
}
static void F_192 ( struct V_206 * V_207 )
{
switch ( V_207 -> type ) {
case V_236 :
case V_237 :
F_180 ( V_207 , NULL ) ;
} ;
}
static bool F_193 ( struct V_23 * V_24 , T_1 V_252 )
{
struct V_206 * V_207 ;
F_194 (f, &fanout_list, list) {
if ( V_207 -> V_253 == V_252 &&
F_172 ( & V_207 -> V_227 ) == F_77 ( V_24 ) ) {
return false ;
}
}
return true ;
}
static bool F_195 ( struct V_23 * V_24 , T_1 * V_254 )
{
T_1 V_253 = V_255 ;
do {
if ( F_193 ( V_24 , V_253 ) ) {
* V_254 = V_253 ;
V_255 = V_253 + 1 ;
return true ;
}
V_253 ++ ;
} while ( V_253 != V_255 );
return false ;
}
static int F_196 ( struct V_23 * V_24 , T_1 V_253 , T_1 V_256 )
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
F_197 ( & V_259 ) ;
V_92 = - V_248 ;
if ( ! V_14 -> V_25 )
goto V_131;
V_92 = - V_260 ;
if ( V_14 -> V_26 )
goto V_131;
if ( type == V_235 ||
( V_256 & V_238 ) ) {
V_92 = - V_261 ;
V_204 = F_198 ( sizeof( * V_204 ) , V_262 ) ;
if ( ! V_204 )
goto V_131;
F_199 ( & V_204 -> V_208 , 0 ) ;
F_199 ( & V_204 -> V_217 , 0 ) ;
F_199 ( & V_204 -> V_218 , 0 ) ;
V_14 -> V_204 = V_204 ;
}
if ( V_256 & V_263 ) {
if ( V_253 != 0 ) {
V_92 = - V_248 ;
goto V_131;
}
if ( ! F_195 ( V_24 , & V_253 ) ) {
V_92 = - V_261 ;
goto V_131;
}
V_47 &= ~ ( V_263 >> 8 ) ;
}
V_258 = NULL ;
F_194 (f, &fanout_list, list) {
if ( V_207 -> V_253 == V_253 &&
F_172 ( & V_207 -> V_227 ) == F_77 ( V_24 ) ) {
V_258 = V_207 ;
break;
}
}
V_92 = - V_248 ;
if ( V_258 && V_258 -> V_47 != V_47 )
goto V_131;
if ( ! V_258 ) {
V_92 = - V_261 ;
V_258 = F_198 ( sizeof( * V_258 ) , V_262 ) ;
if ( ! V_258 )
goto V_131;
F_200 ( & V_258 -> V_227 , F_77 ( V_24 ) ) ;
V_258 -> V_253 = V_253 ;
V_258 -> type = type ;
V_258 -> V_47 = V_47 ;
F_201 ( & V_258 -> V_264 ) ;
F_202 ( & V_258 -> V_79 ) ;
F_203 ( & V_258 -> V_265 , 0 ) ;
F_178 ( V_258 ) ;
V_258 -> V_27 . type = V_14 -> V_27 . type ;
V_258 -> V_27 . V_4 = V_14 -> V_27 . V_4 ;
V_258 -> V_27 . F_71 = F_170 ;
V_258 -> V_27 . V_225 = V_258 ;
V_258 -> V_27 . V_266 = F_177 ;
F_204 ( & V_258 -> V_264 , & V_267 ) ;
}
V_92 = - V_248 ;
if ( V_258 -> type == type &&
V_258 -> V_27 . type == V_14 -> V_27 . type &&
V_258 -> V_27 . V_4 == V_14 -> V_27 . V_4 ) {
V_92 = - V_268 ;
if ( F_149 ( & V_258 -> V_265 ) < V_269 ) {
F_41 ( & V_14 -> V_27 ) ;
V_14 -> V_26 = V_258 ;
F_203 ( & V_258 -> V_265 , F_149 ( & V_258 -> V_265 ) + 1 ) ;
F_36 ( V_24 , V_14 ) ;
V_92 = 0 ;
}
}
V_131:
if ( V_92 && V_204 ) {
F_205 ( V_204 ) ;
V_14 -> V_204 = NULL ;
}
F_206 ( & V_259 ) ;
return V_92 ;
}
static struct V_206 * F_207 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_206 * V_207 ;
F_197 ( & V_259 ) ;
V_207 = V_14 -> V_26 ;
if ( V_207 ) {
V_14 -> V_26 = NULL ;
if ( F_208 ( & V_207 -> V_265 ) )
F_209 ( & V_207 -> V_264 ) ;
else
V_207 = NULL ;
if ( V_14 -> V_204 )
F_210 ( V_14 -> V_204 , V_270 ) ;
}
F_206 ( & V_259 ) ;
return V_207 ;
}
static bool F_211 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( F_2 ( V_4 -> type != V_271 ) )
return false ;
F_212 ( V_2 ) ;
return F_22 ( F_213 ( V_2 ) -> V_272 == F_214 ( V_273 ) ) ;
}
static int F_215 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_222 * V_223 , struct V_3 * V_224 )
{
struct V_23 * V_24 ;
struct V_274 * V_275 ;
V_24 = V_223 -> V_225 ;
if ( V_2 -> V_276 == V_277 )
goto V_131;
if ( ! F_173 ( F_174 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_131;
V_2 = F_216 ( V_2 , V_278 ) ;
if ( V_2 == NULL )
goto V_279;
F_217 ( V_2 ) ;
F_218 ( V_2 ) ;
V_275 = & F_219 ( V_2 ) -> V_280 . V_281 ;
F_220 ( V_2 , V_2 -> V_81 - F_221 ( V_2 ) ) ;
V_275 -> V_282 = V_4 -> type ;
F_222 ( V_275 -> V_283 , V_4 -> V_284 , sizeof( V_275 -> V_283 ) ) ;
V_275 -> V_285 = V_2 -> V_286 ;
if ( F_223 ( V_24 , V_2 ) == 0 )
return 0 ;
V_131:
F_16 ( V_2 ) ;
V_279:
return 0 ;
}
static int F_224 ( struct V_287 * V_23 , struct V_288 * V_289 ,
T_7 V_174 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_225 ( struct V_274 * , V_290 , V_289 -> V_291 ) ;
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
F_20 () ;
V_4 = F_226 ( F_77 ( V_24 ) , V_290 -> V_283 ) ;
V_92 = - V_300 ;
if ( V_4 == NULL )
goto V_301;
V_92 = - V_302 ;
if ( ! ( V_4 -> V_47 & V_303 ) )
goto V_301;
if ( F_2 ( F_150 ( V_24 , V_304 ) ) ) {
if ( ! F_227 ( V_4 ) ) {
V_92 = - V_305 ;
goto V_301;
}
V_295 = 4 ;
}
V_92 = - V_306 ;
if ( V_174 > V_4 -> V_307 + V_4 -> V_308 + V_309 + V_295 )
goto V_301;
if ( ! V_2 ) {
T_7 V_310 = F_228 ( V_4 ) ;
int V_311 = V_4 -> V_312 ;
unsigned int V_313 = V_4 -> V_314 ? V_4 -> V_308 : 0 ;
F_24 () ;
V_2 = F_229 ( V_24 , V_174 + V_310 + V_311 , 0 , V_262 ) ;
if ( V_2 == NULL )
return - V_184 ;
F_230 ( V_2 , V_310 ) ;
F_231 ( V_2 ) ;
if ( V_313 ) {
V_2 -> V_81 -= V_313 ;
V_2 -> V_315 -= V_313 ;
if ( V_174 < V_313 )
F_231 ( V_2 ) ;
}
V_92 = F_232 ( F_233 ( V_2 , V_174 ) , V_289 , V_174 ) ;
if ( V_92 )
goto V_316;
goto V_299;
}
if ( ! F_234 ( V_4 , V_2 -> V_81 , V_174 ) ) {
V_92 = - V_248 ;
goto V_301;
}
if ( V_174 > ( V_4 -> V_307 + V_4 -> V_308 + V_295 ) &&
! F_211 ( V_4 , V_2 ) ) {
V_92 = - V_306 ;
goto V_301;
}
V_293 . V_317 = V_24 -> V_318 ;
if ( V_289 -> V_319 ) {
V_92 = F_235 ( V_24 , V_289 , & V_293 ) ;
if ( F_2 ( V_92 ) )
goto V_301;
}
V_2 -> V_286 = V_294 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_320 = V_24 -> V_321 ;
V_2 -> V_322 = V_24 -> V_323 ;
F_236 ( V_24 , V_293 . V_317 , & F_237 ( V_2 ) -> V_324 ) ;
if ( F_2 ( V_295 == 4 ) )
V_2 -> V_325 = 1 ;
F_238 ( V_2 , 0 ) ;
F_239 ( V_2 ) ;
F_24 () ;
return V_174 ;
V_301:
F_24 () ;
V_316:
F_16 ( V_2 ) ;
return V_92 ;
}
static unsigned int F_240 ( struct V_1 * V_2 ,
const struct V_23 * V_24 ,
unsigned int V_326 )
{
struct V_327 * V_328 ;
F_20 () ;
V_328 = F_21 ( V_24 -> V_327 ) ;
if ( V_328 != NULL )
V_326 = F_168 ( V_328 -> V_220 , V_2 ) ;
F_24 () ;
return V_326 ;
}
static int F_241 ( struct V_288 * V_289 , const struct V_1 * V_2 ,
T_7 * V_174 )
{
struct V_329 V_330 ;
if ( * V_174 < sizeof( V_330 ) )
return - V_248 ;
* V_174 -= sizeof( V_330 ) ;
if ( F_242 ( V_2 , & V_330 , F_243 () , true ) )
return - V_248 ;
return F_244 ( V_289 , ( void * ) & V_330 , sizeof( V_330 ) ) ;
}
static int F_245 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
if ( ! F_173 ( F_174 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_10;
V_2 -> V_4 = V_4 ;
if ( V_4 -> V_314 ) {
if ( V_24 -> V_337 != V_338 )
F_220 ( V_2 , V_2 -> V_81 - F_221 ( V_2 ) ) ;
else if ( V_2 -> V_276 == V_339 ) {
F_246 ( V_2 , F_247 ( V_2 ) ) ;
}
}
V_335 = V_2 -> V_174 ;
V_326 = F_240 ( V_2 , V_24 , V_335 ) ;
if ( ! V_326 )
goto V_340;
if ( V_335 > V_326 )
V_335 = V_326 ;
if ( F_90 ( & V_24 -> V_190 ) >= V_24 -> V_189 )
goto V_341;
if ( F_248 ( V_2 ) ) {
struct V_1 * V_342 = F_249 ( V_2 , V_278 ) ;
if ( V_342 == NULL )
goto V_341;
if ( V_333 != V_2 -> V_81 ) {
V_2 -> V_81 = V_333 ;
V_2 -> V_174 = V_334 ;
}
F_250 ( V_2 ) ;
V_2 = V_342 ;
}
F_251 ( sizeof( * F_219 ( V_2 ) ) + V_343 - 8 ) ;
V_332 = & F_219 ( V_2 ) -> V_280 . V_344 ;
V_332 -> V_345 = V_4 -> type ;
V_332 -> V_346 = V_2 -> V_276 ;
if ( F_2 ( V_14 -> V_347 ) )
V_332 -> V_348 = V_224 -> V_93 ;
else
V_332 -> V_348 = V_4 -> V_93 ;
V_332 -> V_349 = F_252 ( V_2 , V_332 -> V_350 ) ;
F_219 ( V_2 ) -> V_280 . V_351 = V_2 -> V_174 ;
if ( F_253 ( V_2 , V_335 ) )
goto V_341;
F_254 ( V_2 , V_24 ) ;
V_2 -> V_4 = NULL ;
F_217 ( V_2 ) ;
F_218 ( V_2 ) ;
F_45 ( & V_24 -> V_130 . V_79 ) ;
V_14 -> V_119 . V_352 . V_353 ++ ;
F_255 ( V_24 , V_2 ) ;
F_256 ( & V_24 -> V_130 , V_2 ) ;
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
if ( V_333 != V_2 -> V_81 && F_248 ( V_2 ) ) {
V_2 -> V_81 = V_333 ;
V_2 -> V_174 = V_334 ;
}
V_10:
if ( ! V_336 )
F_250 ( V_2 ) ;
else
F_16 ( V_2 ) ;
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
bool V_358 = false ;
F_257 ( F_258 ( sizeof( * V_35 . V_42 ) ) != 32 ) ;
F_257 ( F_258 ( sizeof( * V_35 . V_44 ) ) != 48 ) ;
if ( V_2 -> V_276 == V_277 )
goto V_10;
V_24 = V_223 -> V_225 ;
V_14 = F_35 ( V_24 ) ;
if ( ! F_173 ( F_174 ( V_4 ) , F_77 ( V_24 ) ) )
goto V_10;
if ( V_4 -> V_314 ) {
if ( V_24 -> V_337 != V_338 )
F_220 ( V_2 , V_2 -> V_81 - F_221 ( V_2 ) ) ;
else if ( V_2 -> V_276 == V_339 ) {
F_246 ( V_2 , F_247 ( V_2 ) ) ;
}
}
V_335 = V_2 -> V_174 ;
V_326 = F_240 ( V_2 , V_24 , V_335 ) ;
if ( ! V_326 )
goto V_340;
if ( V_2 -> V_359 == V_360 )
V_33 |= V_361 ;
else if ( V_2 -> V_276 != V_339 &&
( V_2 -> V_359 == V_362 ||
F_259 ( V_2 ) ) )
V_33 |= V_363 ;
if ( V_335 > V_326 )
V_335 = V_326 ;
if ( V_24 -> V_337 == V_338 ) {
V_355 = V_356 = F_258 ( V_14 -> V_116 ) + 16 +
V_14 -> V_364 ;
} else {
unsigned int V_365 = F_247 ( V_2 ) ;
V_356 = F_258 ( V_14 -> V_116 +
( V_365 < 16 ? 16 : V_365 ) ) +
V_14 -> V_364 ;
if ( V_14 -> V_366 ) {
V_356 += sizeof( struct V_329 ) ;
V_358 = true ;
}
V_355 = V_356 - V_365 ;
}
if ( V_14 -> V_37 <= V_41 ) {
if ( V_355 + V_335 > V_14 -> V_78 . V_71 ) {
if ( V_14 -> V_367 &&
F_90 ( & V_24 -> V_190 ) < V_24 -> V_189 ) {
if ( F_248 ( V_2 ) ) {
V_357 = F_249 ( V_2 , V_278 ) ;
} else {
V_357 = F_260 ( V_2 ) ;
V_333 = V_2 -> V_81 ;
}
if ( V_357 )
F_254 ( V_357 , V_24 ) ;
}
V_335 = V_14 -> V_78 . V_71 - V_355 ;
if ( ( int ) V_335 < 0 ) {
V_335 = 0 ;
V_358 = false ;
}
}
} else if ( F_2 ( V_355 + V_335 >
F_67 ( & V_14 -> V_78 ) -> V_127 ) ) {
T_5 V_368 ;
V_368 = F_67 ( & V_14 -> V_78 ) -> V_127 - V_355 ;
F_261 ( L_4 ,
V_335 , V_368 , V_355 ) ;
V_335 = V_368 ;
if ( F_2 ( ( int ) V_335 < 0 ) ) {
V_335 = 0 ;
V_355 = F_67 ( & V_14 -> V_78 ) -> V_127 ;
V_358 = false ;
}
}
F_45 ( & V_24 -> V_130 . V_79 ) ;
V_35 . V_36 = F_122 ( V_14 , V_2 ,
V_161 , ( V_355 + V_335 ) ) ;
if ( ! V_35 . V_36 )
goto V_369;
if ( V_14 -> V_37 <= V_41 ) {
F_129 ( V_14 , & V_14 -> V_78 ) ;
if ( V_14 -> V_119 . V_352 . V_149 )
V_33 |= V_150 ;
}
V_14 -> V_119 . V_352 . V_353 ++ ;
if ( V_357 ) {
V_33 |= V_370 ;
F_256 ( & V_24 -> V_130 , V_357 ) ;
}
F_43 ( & V_24 -> V_130 . V_79 ) ;
if ( V_358 ) {
if ( F_242 ( V_2 , V_35 . V_36 + V_355 -
sizeof( struct V_329 ) ,
F_243 () , true ) ) {
F_45 ( & V_24 -> V_130 . V_79 ) ;
goto V_369;
}
}
F_262 ( V_2 , 0 , V_35 . V_36 + V_355 , V_335 ) ;
if ( ! ( V_55 = F_58 ( V_2 , & V_46 , V_14 -> V_56 ) ) )
F_99 ( & V_46 ) ;
V_33 |= V_55 ;
switch ( V_14 -> V_37 ) {
case V_38 :
V_35 . V_39 -> V_371 = V_2 -> V_174 ;
V_35 . V_39 -> V_372 = V_335 ;
V_35 . V_39 -> V_373 = V_355 ;
V_35 . V_39 -> V_374 = V_356 ;
V_35 . V_39 -> V_57 = V_46 . V_58 ;
V_35 . V_39 -> V_59 = V_46 . V_60 / V_61 ;
V_115 = sizeof( * V_35 . V_39 ) ;
break;
case V_41 :
V_35 . V_42 -> V_371 = V_2 -> V_174 ;
V_35 . V_42 -> V_372 = V_335 ;
V_35 . V_42 -> V_373 = V_355 ;
V_35 . V_42 -> V_374 = V_356 ;
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
V_35 . V_44 -> V_371 = V_2 -> V_174 ;
V_35 . V_44 -> V_372 = V_335 ;
V_35 . V_44 -> V_373 = V_355 ;
V_35 . V_44 -> V_374 = V_356 ;
V_35 . V_44 -> V_57 = V_46 . V_58 ;
V_35 . V_44 -> V_62 = V_46 . V_60 ;
memset ( V_35 . V_44 -> V_171 , 0 , sizeof( V_35 . V_44 -> V_171 ) ) ;
V_115 = sizeof( * V_35 . V_44 ) ;
break;
default:
F_54 () ;
}
V_332 = V_35 . V_36 + F_258 ( V_115 ) ;
V_332 -> V_349 = F_252 ( V_2 , V_332 -> V_350 ) ;
V_332 -> V_375 = V_376 ;
V_332 -> V_345 = V_4 -> type ;
V_332 -> V_377 = V_2 -> V_286 ;
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
if ( V_333 != V_2 -> V_81 && F_248 ( V_2 ) ) {
V_2 -> V_81 = V_333 ;
V_2 -> V_174 = V_334 ;
}
V_10:
if ( ! V_336 )
F_250 ( V_2 ) ;
else
F_16 ( V_2 ) ;
return 0 ;
V_369:
V_336 = true ;
V_14 -> V_119 . V_352 . V_149 ++ ;
F_43 ( & V_24 -> V_130 . V_79 ) ;
V_24 -> V_156 ( V_24 ) ;
F_16 ( V_357 ) ;
goto V_340;
}
static void F_263 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_35 ( V_2 -> V_24 ) ;
if ( F_22 ( V_14 -> V_183 . V_69 ) ) {
void * V_378 ;
T_3 V_46 ;
V_378 = F_237 ( V_2 ) -> V_379 ;
F_133 ( & V_14 -> V_183 ) ;
V_46 = F_61 ( V_14 , V_378 , V_2 ) ;
F_51 ( V_14 , V_378 , V_170 | V_46 ) ;
}
F_264 ( V_2 ) ;
}
static void F_265 ( const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
if ( V_4 -> type == V_271 ) {
F_212 ( V_2 ) ;
V_2 -> V_286 = F_213 ( V_2 ) -> V_272 ;
}
}
static int F_266 ( struct V_329 * V_330 , T_7 V_174 )
{
if ( ( V_330 -> V_47 & V_380 ) &&
( F_267 ( F_243 () , V_330 -> V_381 ) +
F_267 ( F_243 () , V_330 -> V_382 ) + 2 >
F_267 ( F_243 () , V_330 -> V_383 ) ) )
V_330 -> V_383 = F_268 ( F_243 () ,
F_267 ( F_243 () , V_330 -> V_381 ) +
F_267 ( F_243 () , V_330 -> V_382 ) + 2 ) ;
if ( F_267 ( F_243 () , V_330 -> V_383 ) > V_174 )
return - V_248 ;
return 0 ;
}
static int F_269 ( struct V_288 * V_289 , T_7 * V_174 ,
struct V_329 * V_330 )
{
if ( * V_174 < sizeof( * V_330 ) )
return - V_248 ;
* V_174 -= sizeof( * V_330 ) ;
if ( ! F_270 ( V_330 , sizeof( * V_330 ) , & V_289 -> V_384 ) )
return - V_249 ;
return F_266 ( V_330 , * V_174 ) ;
}
static int F_271 ( struct V_13 * V_14 , struct V_1 * V_2 ,
void * V_32 , struct V_3 * V_4 , void * V_81 , int V_371 ,
T_8 V_294 , unsigned char * V_31 , int V_385 , int V_386 ,
const struct V_292 * V_293 )
{
union V_34 V_378 ;
int V_387 , V_388 , V_174 , V_389 , V_390 ;
struct V_287 * V_23 = V_14 -> V_24 . V_391 ;
struct V_30 * V_30 ;
int V_92 ;
V_378 . V_36 = V_32 ;
V_2 -> V_286 = V_294 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_320 = V_14 -> V_24 . V_321 ;
V_2 -> V_322 = V_14 -> V_24 . V_323 ;
F_236 ( & V_14 -> V_24 , V_293 -> V_317 , & F_237 ( V_2 ) -> V_324 ) ;
F_237 ( V_2 ) -> V_379 = V_378 . V_36 ;
F_230 ( V_2 , V_385 ) ;
F_231 ( V_2 ) ;
V_387 = V_371 ;
if ( V_23 -> type == V_338 ) {
V_92 = F_272 ( V_2 , V_4 , F_115 ( V_294 ) , V_31 ,
NULL , V_371 ) ;
if ( F_2 ( V_92 < 0 ) )
return - V_248 ;
} else if ( V_386 ) {
int V_115 = F_164 ( int , V_386 , V_371 ) ;
F_220 ( V_2 , V_4 -> V_308 ) ;
F_233 ( V_2 , V_386 - V_4 -> V_308 ) ;
V_92 = F_273 ( V_2 , 0 , V_81 , V_115 ) ;
if ( F_2 ( V_92 ) )
return V_92 ;
if ( ! F_234 ( V_4 , V_2 -> V_81 , V_115 ) )
return - V_248 ;
if ( ! V_2 -> V_286 )
F_265 ( V_4 , V_2 ) ;
V_81 += V_115 ;
V_387 -= V_115 ;
}
V_388 = F_274 ( V_81 ) ;
V_390 = V_140 - V_388 ;
V_174 = ( ( V_387 > V_390 ) ? V_390 : V_387 ) ;
V_2 -> V_392 = V_387 ;
V_2 -> V_174 += V_387 ;
V_2 -> V_191 += V_387 ;
F_275 ( V_387 , & V_14 -> V_24 . V_198 ) ;
while ( F_22 ( V_387 ) ) {
V_389 = F_237 ( V_2 ) -> V_389 ;
if ( F_2 ( V_389 >= V_393 ) ) {
F_151 ( L_5 ,
V_393 ) ;
return - V_249 ;
}
V_30 = F_47 ( V_81 ) ;
V_81 += V_174 ;
F_52 ( V_30 ) ;
F_276 ( V_30 ) ;
F_277 ( V_2 , V_389 , V_30 , V_388 , V_174 ) ;
V_387 -= V_174 ;
V_388 = 0 ;
V_390 = V_140 ;
V_174 = ( ( V_387 > V_390 ) ? V_390 : V_387 ) ;
}
F_238 ( V_2 , 0 ) ;
return V_371 ;
}
static int F_278 ( struct V_13 * V_14 , void * V_32 ,
int V_394 , void * * V_81 )
{
union V_34 V_378 ;
int V_371 , V_395 ;
V_378 . V_36 = V_32 ;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( V_378 . V_44 -> V_152 != 0 ) {
F_279 ( L_6 ) ;
return - V_248 ;
}
V_371 = V_378 . V_44 -> V_371 ;
break;
case V_41 :
V_371 = V_378 . V_42 -> V_371 ;
break;
default:
V_371 = V_378 . V_39 -> V_371 ;
break;
}
if ( F_2 ( V_371 > V_394 ) ) {
F_151 ( L_7 , V_371 , V_394 ) ;
return - V_306 ;
}
if ( F_2 ( V_14 -> V_396 ) ) {
int V_397 , V_398 ;
V_397 = V_14 -> V_116 - sizeof( struct V_331 ) ;
V_398 = V_14 -> V_183 . V_71 - V_371 ;
if ( V_14 -> V_24 . V_337 == V_338 ) {
switch ( V_14 -> V_37 ) {
case V_43 :
V_395 = V_378 . V_44 -> V_374 ;
break;
case V_41 :
V_395 = V_378 . V_42 -> V_374 ;
break;
default:
V_395 = V_378 . V_39 -> V_374 ;
break;
}
} else {
switch ( V_14 -> V_37 ) {
case V_43 :
V_395 = V_378 . V_44 -> V_373 ;
break;
case V_41 :
V_395 = V_378 . V_42 -> V_373 ;
break;
default:
V_395 = V_378 . V_39 -> V_373 ;
break;
}
}
if ( F_2 ( ( V_395 < V_397 ) || ( V_398 < V_395 ) ) )
return - V_248 ;
} else {
V_395 = V_14 -> V_116 - sizeof( struct V_331 ) ;
}
* V_81 = V_32 + V_395 ;
return V_371 ;
}
static int F_280 ( struct V_13 * V_14 , struct V_288 * V_289 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_329 * V_330 = NULL ;
struct V_292 V_293 ;
T_8 V_294 ;
int V_92 , V_399 = 0 ;
void * V_378 ;
F_225 ( struct V_331 * , V_290 , V_289 -> V_291 ) ;
bool V_400 = ! ( V_289 -> V_401 & V_402 ) ;
int V_371 , V_394 ;
unsigned char * V_31 ;
void * V_81 ;
int V_403 = 0 ;
int V_33 = V_170 ;
int V_385 , V_311 , V_386 = 0 ;
F_197 ( & V_14 -> V_404 ) ;
if ( F_22 ( V_290 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_294 = V_14 -> V_208 ;
V_31 = NULL ;
} else {
V_92 = - V_248 ;
if ( V_289 -> V_296 < sizeof( struct V_331 ) )
goto V_131;
if ( V_289 -> V_296 < ( V_290 -> V_349
+ F_281 ( struct V_331 ,
V_350 ) ) )
goto V_131;
V_294 = V_290 -> V_377 ;
V_31 = V_290 -> V_350 ;
V_4 = F_282 ( F_77 ( & V_14 -> V_24 ) , V_290 -> V_348 ) ;
}
V_92 = - V_405 ;
if ( F_2 ( V_4 == NULL ) )
goto V_131;
V_92 = - V_302 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_303 ) ) )
goto V_406;
V_293 . V_317 = V_14 -> V_24 . V_318 ;
if ( V_289 -> V_319 ) {
V_92 = F_235 ( & V_14 -> V_24 , V_289 , & V_293 ) ;
if ( F_2 ( V_92 ) )
goto V_406;
}
if ( V_14 -> V_24 . V_391 -> type == V_407 )
V_399 = V_4 -> V_308 ;
V_394 = V_14 -> V_183 . V_71
- ( V_14 -> V_116 - sizeof( struct V_331 ) ) ;
if ( ( V_394 > V_4 -> V_307 + V_399 + V_309 ) && ! V_14 -> V_366 )
V_394 = V_4 -> V_307 + V_399 + V_309 ;
do {
V_378 = F_63 ( V_14 , & V_14 -> V_183 ,
V_408 ) ;
if ( F_2 ( V_378 == NULL ) ) {
if ( V_400 && F_283 () )
F_284 () ;
continue;
}
V_2 = NULL ;
V_371 = F_278 ( V_14 , V_378 , V_394 , & V_81 ) ;
if ( V_371 < 0 )
goto V_409;
V_33 = V_408 ;
V_385 = F_228 ( V_4 ) ;
V_311 = V_4 -> V_312 ;
if ( V_14 -> V_366 ) {
V_330 = V_81 ;
V_81 += sizeof( * V_330 ) ;
V_371 -= sizeof( * V_330 ) ;
if ( V_371 < 0 ||
F_266 ( V_330 , V_371 ) ) {
V_371 = - V_248 ;
goto V_409;
}
V_386 = F_267 ( F_243 () ,
V_330 -> V_383 ) ;
}
V_386 = F_285 ( int , V_386 , V_4 -> V_308 ) ;
V_2 = F_286 ( & V_14 -> V_24 ,
V_385 + V_311 + sizeof( struct V_331 ) +
( V_386 - V_4 -> V_308 ) ,
! V_400 , & V_92 ) ;
if ( F_2 ( V_2 == NULL ) ) {
if ( F_22 ( V_403 > 0 ) )
V_92 = V_403 ;
goto V_410;
}
V_371 = F_271 ( V_14 , V_2 , V_378 , V_4 , V_81 , V_371 , V_294 ,
V_31 , V_385 , V_386 , & V_293 ) ;
if ( F_22 ( V_371 >= 0 ) &&
V_371 > V_4 -> V_307 + V_399 &&
! V_14 -> V_366 &&
! F_211 ( V_4 , V_2 ) )
V_371 = - V_306 ;
if ( F_2 ( V_371 < 0 ) ) {
V_409:
if ( V_14 -> V_411 ) {
F_51 ( V_14 , V_378 ,
V_170 ) ;
F_130 ( & V_14 -> V_183 ) ;
F_16 ( V_2 ) ;
continue;
} else {
V_33 = V_412 ;
V_92 = V_371 ;
goto V_410;
}
}
if ( V_14 -> V_366 && F_287 ( V_2 , V_330 ,
F_243 () ) ) {
V_371 = - V_248 ;
goto V_409;
}
V_2 -> V_413 = F_263 ;
F_51 ( V_14 , V_378 , V_414 ) ;
F_131 ( & V_14 -> V_183 ) ;
V_33 = V_408 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( F_2 ( V_92 > 0 ) ) {
V_92 = F_288 ( V_92 ) ;
if ( V_92 && F_56 ( V_14 , V_378 ) ==
V_170 ) {
V_2 = NULL ;
goto V_410;
}
V_92 = 0 ;
}
F_130 ( & V_14 -> V_183 ) ;
V_403 += V_371 ;
} while ( F_22 ( ( V_378 != NULL ) ||
( V_400 && F_135 ( & V_14 -> V_183 ) ) ) );
V_92 = V_403 ;
goto V_406;
V_410:
F_51 ( V_14 , V_378 , V_33 ) ;
F_16 ( V_2 ) ;
V_406:
F_289 ( V_4 ) ;
V_131:
F_206 ( & V_14 -> V_404 ) ;
return V_92 ;
}
static struct V_1 * F_290 ( struct V_23 * V_24 , T_7 V_415 ,
T_7 V_399 , T_7 V_174 ,
T_7 V_416 , int V_417 ,
int * V_92 )
{
struct V_1 * V_2 ;
if ( V_415 + V_174 < V_140 || ! V_416 )
V_416 = V_174 ;
V_2 = F_291 ( V_24 , V_415 + V_416 , V_174 - V_416 , V_417 ,
V_92 , 0 ) ;
if ( ! V_2 )
return NULL ;
F_230 ( V_2 , V_399 ) ;
F_233 ( V_2 , V_416 ) ;
V_2 -> V_392 = V_174 - V_416 ;
V_2 -> V_174 += V_174 - V_416 ;
return V_2 ;
}
static int F_292 ( struct V_287 * V_23 , struct V_288 * V_289 , T_7 V_174 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
F_225 ( struct V_331 * , V_290 , V_289 -> V_291 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_8 V_294 ;
unsigned char * V_31 ;
int V_92 , V_399 = 0 ;
struct V_292 V_293 ;
struct V_329 V_330 = { 0 } ;
int V_388 = 0 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_385 , V_311 , V_416 ;
int V_295 = 0 ;
if ( F_22 ( V_290 == NULL ) ) {
V_4 = F_19 ( V_14 ) ;
V_294 = V_14 -> V_208 ;
V_31 = NULL ;
} else {
V_92 = - V_248 ;
if ( V_289 -> V_296 < sizeof( struct V_331 ) )
goto V_131;
if ( V_289 -> V_296 < ( V_290 -> V_349 + F_281 ( struct V_331 , V_350 ) ) )
goto V_131;
V_294 = V_290 -> V_377 ;
V_31 = V_290 -> V_350 ;
V_4 = F_282 ( F_77 ( V_24 ) , V_290 -> V_348 ) ;
}
V_92 = - V_405 ;
if ( F_2 ( V_4 == NULL ) )
goto V_301;
V_92 = - V_302 ;
if ( F_2 ( ! ( V_4 -> V_47 & V_303 ) ) )
goto V_301;
V_293 . V_317 = V_24 -> V_318 ;
V_293 . V_322 = V_24 -> V_323 ;
if ( V_289 -> V_319 ) {
V_92 = F_235 ( V_24 , V_289 , & V_293 ) ;
if ( F_2 ( V_92 ) )
goto V_301;
}
if ( V_23 -> type == V_407 )
V_399 = V_4 -> V_308 ;
if ( V_14 -> V_366 ) {
V_92 = F_269 ( V_289 , & V_174 , & V_330 ) ;
if ( V_92 )
goto V_301;
}
if ( F_2 ( F_150 ( V_24 , V_304 ) ) ) {
if ( ! F_227 ( V_4 ) ) {
V_92 = - V_305 ;
goto V_301;
}
V_295 = 4 ;
}
V_92 = - V_306 ;
if ( ! V_330 . V_418 &&
( V_174 > V_4 -> V_307 + V_399 + V_309 + V_295 ) )
goto V_301;
V_92 = - V_184 ;
V_385 = F_228 ( V_4 ) ;
V_311 = V_4 -> V_312 ;
V_416 = F_267 ( F_243 () , V_330 . V_383 ) ;
V_416 = F_293 ( V_416 , F_164 ( int , V_174 , V_4 -> V_308 ) ) ;
V_2 = F_290 ( V_24 , V_385 + V_311 , V_385 , V_174 , V_416 ,
V_289 -> V_401 & V_402 , & V_92 ) ;
if ( V_2 == NULL )
goto V_301;
F_294 ( V_2 , V_399 ) ;
V_92 = - V_248 ;
if ( V_23 -> type == V_338 ) {
V_388 = F_272 ( V_2 , V_4 , F_115 ( V_294 ) , V_31 , NULL , V_174 ) ;
if ( F_2 ( V_388 < 0 ) )
goto V_316;
}
V_92 = F_295 ( V_2 , V_388 , & V_289 -> V_384 , V_174 ) ;
if ( V_92 )
goto V_316;
if ( V_23 -> type == V_407 &&
! F_234 ( V_4 , V_2 -> V_81 , V_174 ) ) {
V_92 = - V_248 ;
goto V_316;
}
F_236 ( V_24 , V_293 . V_317 , & F_237 ( V_2 ) -> V_324 ) ;
if ( ! V_330 . V_418 && ( V_174 > V_4 -> V_307 + V_399 + V_295 ) &&
! F_211 ( V_4 , V_2 ) ) {
V_92 = - V_306 ;
goto V_316;
}
V_2 -> V_286 = V_294 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_320 = V_24 -> V_321 ;
V_2 -> V_322 = V_293 . V_322 ;
if ( V_14 -> V_366 ) {
V_92 = F_287 ( V_2 , & V_330 , F_243 () ) ;
if ( V_92 )
goto V_316;
V_174 += sizeof( V_330 ) ;
}
F_238 ( V_2 , V_399 ) ;
if ( F_2 ( V_295 == 4 ) )
V_2 -> V_325 = 1 ;
V_92 = V_14 -> V_16 ( V_2 ) ;
if ( V_92 > 0 && ( V_92 = F_288 ( V_92 ) ) != 0 )
goto V_301;
F_289 ( V_4 ) ;
return V_174 ;
V_316:
F_16 ( V_2 ) ;
V_301:
if ( V_4 )
F_289 ( V_4 ) ;
V_131:
return V_92 ;
}
static int F_296 ( struct V_287 * V_23 , struct V_288 * V_289 , T_7 V_174 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
if ( V_14 -> V_183 . V_69 )
return F_280 ( V_14 , V_289 ) ;
else
return F_292 ( V_23 , V_289 , V_174 ) ;
}
static int F_297 ( struct V_287 * V_23 )
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
F_197 ( & V_227 -> V_419 . V_420 ) ;
F_298 ( V_24 ) ;
F_206 ( & V_227 -> V_419 . V_420 ) ;
F_299 () ;
F_300 ( V_227 , V_24 -> V_421 , - 1 ) ;
F_301 () ;
F_45 ( & V_14 -> V_29 ) ;
F_46 ( V_24 , false ) ;
F_27 ( V_14 ) ;
if ( V_14 -> V_27 . V_4 ) {
F_289 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_43 ( & V_14 -> V_29 ) ;
F_302 ( V_24 ) ;
if ( V_14 -> V_78 . V_69 ) {
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_303 ( V_24 , & V_101 , 1 , 0 ) ;
}
if ( V_14 -> V_183 . V_69 ) {
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
F_303 ( V_24 , & V_101 , 1 , 1 ) ;
}
V_207 = F_207 ( V_24 ) ;
F_44 () ;
if ( V_207 ) {
F_192 ( V_207 ) ;
F_205 ( V_207 ) ;
}
F_304 ( V_24 ) ;
V_23 -> V_24 = NULL ;
F_147 ( & V_24 -> V_130 ) ;
F_140 ( V_14 ) ;
F_305 ( V_24 ) ;
F_306 ( V_24 ) ;
return 0 ;
}
static int F_307 ( struct V_23 * V_24 , const char * V_284 , int V_93 ,
T_8 V_294 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_3 * V_422 ;
T_8 V_423 ;
bool V_424 ;
struct V_3 * V_4 = NULL ;
int V_8 = 0 ;
bool V_425 = false ;
if ( V_14 -> V_26 )
return - V_248 ;
F_308 ( V_24 ) ;
F_45 ( & V_14 -> V_29 ) ;
F_20 () ;
if ( V_284 ) {
V_4 = F_226 ( F_77 ( V_24 ) , V_284 ) ;
if ( ! V_4 ) {
V_8 = - V_300 ;
goto V_301;
}
} else if ( V_93 ) {
V_4 = F_309 ( F_77 ( V_24 ) , V_93 ) ;
if ( ! V_4 ) {
V_8 = - V_300 ;
goto V_301;
}
}
if ( V_4 )
F_23 ( V_4 ) ;
V_423 = V_14 -> V_27 . type ;
V_422 = V_14 -> V_27 . V_4 ;
V_424 = V_423 != V_294 || V_422 != V_4 ;
if ( V_424 ) {
if ( V_14 -> V_25 ) {
F_24 () ;
F_39 ( V_24 , true ) ;
F_20 () ;
V_422 = V_14 -> V_27 . V_4 ;
if ( V_4 )
V_425 = ! F_309 ( F_77 ( V_24 ) ,
V_4 -> V_93 ) ;
}
V_14 -> V_208 = V_294 ;
V_14 -> V_27 . type = V_294 ;
if ( F_2 ( V_425 ) ) {
F_289 ( V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
V_14 -> V_93 = - 1 ;
F_27 ( V_14 ) ;
} else {
V_14 -> V_27 . V_4 = V_4 ;
V_14 -> V_93 = V_4 ? V_4 -> V_93 : 0 ;
F_25 ( V_14 , V_4 ) ;
}
}
if ( V_422 )
F_289 ( V_422 ) ;
if ( V_294 == 0 || ! V_424 )
goto V_301;
if ( ! V_425 && ( ! V_4 || ( V_4 -> V_47 & V_303 ) ) ) {
F_34 ( V_24 ) ;
} else {
V_24 -> V_426 = V_302 ;
if ( ! F_150 ( V_24 , V_199 ) )
V_24 -> V_427 ( V_24 ) ;
}
V_301:
F_24 () ;
F_43 ( & V_14 -> V_29 ) ;
F_310 ( V_24 ) ;
return V_8 ;
}
static int F_311 ( struct V_287 * V_23 , struct V_297 * V_428 ,
int V_429 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
char V_284 [ sizeof( V_428 -> V_430 ) + 1 ] ;
if ( V_429 != sizeof( struct V_297 ) )
return - V_248 ;
memcpy ( V_284 , V_428 -> V_430 , sizeof( V_428 -> V_430 ) ) ;
V_284 [ sizeof( V_428 -> V_430 ) ] = 0 ;
return F_307 ( V_24 , V_284 , 0 , F_35 ( V_24 ) -> V_208 ) ;
}
static int F_312 ( struct V_287 * V_23 , struct V_297 * V_428 , int V_429 )
{
struct V_331 * V_332 = (struct V_331 * ) V_428 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_429 < sizeof( struct V_331 ) )
return - V_248 ;
if ( V_332 -> V_375 != V_376 )
return - V_248 ;
return F_307 ( V_24 , NULL , V_332 -> V_348 ,
V_332 -> V_377 ? : F_35 ( V_24 ) -> V_208 ) ;
}
static int F_313 ( struct V_227 * V_227 , struct V_287 * V_23 , int V_286 ,
int V_431 )
{
struct V_23 * V_24 ;
struct V_13 * V_14 ;
T_8 V_294 = ( V_432 T_8 ) V_286 ;
int V_92 ;
if ( ! F_314 ( V_227 -> V_433 , V_434 ) )
return - V_247 ;
if ( V_23 -> type != V_338 && V_23 -> type != V_407 &&
V_23 -> type != V_435 )
return - V_436 ;
V_23 -> V_437 = V_438 ;
V_92 = - V_184 ;
V_24 = F_315 ( V_227 , V_241 , V_262 , & V_439 , V_431 ) ;
if ( V_24 == NULL )
goto V_131;
V_23 -> V_19 = & V_440 ;
if ( V_23 -> type == V_435 )
V_23 -> V_19 = & V_441 ;
F_316 ( V_23 , V_24 ) ;
V_14 = F_35 ( V_24 ) ;
V_24 -> V_240 = V_241 ;
V_14 -> V_208 = V_294 ;
V_14 -> V_16 = F_239 ;
V_92 = F_138 ( V_14 ) ;
if ( V_92 )
goto V_442;
F_27 ( V_14 ) ;
V_24 -> V_443 = F_146 ;
F_317 ( V_24 ) ;
F_202 ( & V_14 -> V_29 ) ;
F_318 ( & V_14 -> V_404 ) ;
V_14 -> V_204 = NULL ;
V_14 -> V_27 . F_71 = F_245 ;
if ( V_23 -> type == V_435 )
V_14 -> V_27 . F_71 = F_215 ;
V_14 -> V_27 . V_225 = V_24 ;
if ( V_294 ) {
V_14 -> V_27 . type = V_294 ;
F_34 ( V_24 ) ;
}
F_197 ( & V_227 -> V_419 . V_420 ) ;
F_319 ( V_24 , & V_227 -> V_419 . V_444 ) ;
F_206 ( & V_227 -> V_419 . V_420 ) ;
F_299 () ;
F_300 ( V_227 , & V_439 , 1 ) ;
F_301 () ;
return 0 ;
V_442:
F_320 ( V_24 ) ;
V_131:
return V_92 ;
}
static int F_321 ( struct V_287 * V_23 , struct V_288 * V_289 , T_7 V_174 ,
int V_47 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_1 * V_2 ;
int V_445 , V_92 ;
int V_446 = 0 ;
unsigned int V_351 = 0 ;
V_92 = - V_248 ;
if ( V_47 & ~ ( V_447 | V_402 | V_448 | V_449 | V_450 ) )
goto V_131;
#if 0
if (pkt_sk(sk)->ifindex < 0)
return -ENODEV;
#endif
if ( V_47 & V_450 ) {
V_92 = F_322 ( V_24 , V_289 , V_174 ,
V_451 , V_452 ) ;
goto V_131;
}
V_2 = F_323 ( V_24 , V_47 , V_47 & V_402 , & V_92 ) ;
if ( V_2 == NULL )
goto V_131;
if ( F_35 ( V_24 ) -> V_196 )
F_145 ( F_35 ( V_24 ) , NULL ) ;
if ( F_35 ( V_24 ) -> V_366 ) {
V_92 = F_241 ( V_289 , V_2 , & V_174 ) ;
if ( V_92 )
goto V_316;
V_446 = sizeof( struct V_329 ) ;
}
V_445 = V_2 -> V_174 ;
if ( V_445 > V_174 ) {
V_445 = V_174 ;
V_289 -> V_401 |= V_448 ;
}
V_92 = F_324 ( V_2 , 0 , V_289 , V_445 ) ;
if ( V_92 )
goto V_316;
if ( V_23 -> type != V_435 ) {
struct V_331 * V_332 = & F_219 ( V_2 ) -> V_280 . V_344 ;
V_351 = F_219 ( V_2 ) -> V_280 . V_351 ;
V_332 -> V_375 = V_376 ;
V_332 -> V_377 = V_2 -> V_286 ;
}
F_325 ( V_289 , V_24 , V_2 ) ;
if ( V_289 -> V_291 ) {
if ( V_23 -> type == V_435 ) {
F_326 ( sizeof( struct V_274 ) ) ;
V_289 -> V_296 = sizeof( struct V_274 ) ;
} else {
struct V_331 * V_332 = & F_219 ( V_2 ) -> V_280 . V_344 ;
V_289 -> V_296 = V_332 -> V_349 +
F_281 ( struct V_331 , V_350 ) ;
}
memcpy ( V_289 -> V_291 , & F_219 ( V_2 ) -> V_280 ,
V_289 -> V_296 ) ;
}
if ( F_35 ( V_24 ) -> V_453 ) {
struct V_454 V_455 ;
V_455 . V_40 = V_143 ;
if ( V_2 -> V_359 == V_360 )
V_455 . V_40 |= V_361 ;
else if ( V_2 -> V_276 != V_339 &&
( V_2 -> V_359 == V_362 ||
F_259 ( V_2 ) ) )
V_455 . V_40 |= V_363 ;
V_455 . V_371 = V_351 ;
V_455 . V_372 = V_2 -> V_174 ;
V_455 . V_373 = 0 ;
V_455 . V_374 = F_247 ( V_2 ) ;
if ( F_113 ( V_2 ) ) {
V_455 . V_165 = F_114 ( V_2 ) ;
V_455 . V_166 = F_115 ( V_2 -> V_167 ) ;
V_455 . V_40 |= V_168 | V_169 ;
} else {
V_455 . V_165 = 0 ;
V_455 . V_166 = 0 ;
}
F_327 ( V_289 , V_451 , V_456 , sizeof( V_455 ) , & V_455 ) ;
}
V_92 = V_446 + ( ( V_47 & V_448 ) ? V_2 -> V_174 : V_445 ) ;
V_316:
F_328 ( V_24 , V_2 ) ;
V_131:
return V_92 ;
}
static int F_329 ( struct V_287 * V_23 , struct V_297 * V_428 ,
int * V_457 , int V_458 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_458 )
return - V_459 ;
V_428 -> V_460 = V_376 ;
memset ( V_428 -> V_430 , 0 , sizeof( V_428 -> V_430 ) ) ;
F_20 () ;
V_4 = F_309 ( F_77 ( V_24 ) , F_35 ( V_24 ) -> V_93 ) ;
if ( V_4 )
F_222 ( V_428 -> V_430 , V_4 -> V_284 , sizeof( V_428 -> V_430 ) ) ;
F_24 () ;
* V_457 = sizeof( * V_428 ) ;
return 0 ;
}
static int F_330 ( struct V_287 * V_23 , struct V_297 * V_428 ,
int * V_457 , int V_458 )
{
struct V_3 * V_4 ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
F_225 ( struct V_331 * , V_332 , V_428 ) ;
if ( V_458 )
return - V_459 ;
V_332 -> V_375 = V_376 ;
V_332 -> V_348 = V_14 -> V_93 ;
V_332 -> V_377 = V_14 -> V_208 ;
V_332 -> V_346 = 0 ;
F_20 () ;
V_4 = F_309 ( F_77 ( V_24 ) , V_14 -> V_93 ) ;
if ( V_4 ) {
V_332 -> V_345 = V_4 -> type ;
V_332 -> V_349 = V_4 -> V_429 ;
memcpy ( V_332 -> V_350 , V_4 -> V_461 , V_4 -> V_429 ) ;
} else {
V_332 -> V_345 = 0 ;
V_332 -> V_349 = 0 ;
}
F_24 () ;
* V_457 = F_281 ( struct V_331 , V_350 ) + V_332 -> V_349 ;
return 0 ;
}
static int F_331 ( struct V_3 * V_4 , struct V_462 * V_201 ,
int V_463 )
{
switch ( V_201 -> type ) {
case V_464 :
if ( V_201 -> V_465 != V_4 -> V_429 )
return - V_248 ;
if ( V_463 > 0 )
return F_332 ( V_4 , V_201 -> V_31 ) ;
else
return F_333 ( V_4 , V_201 -> V_31 ) ;
break;
case V_466 :
return F_334 ( V_4 , V_463 ) ;
case V_467 :
return F_335 ( V_4 , V_463 ) ;
case V_468 :
if ( V_201 -> V_465 != V_4 -> V_429 )
return - V_248 ;
if ( V_463 > 0 )
return F_336 ( V_4 , V_201 -> V_31 ) ;
else
return F_337 ( V_4 , V_201 -> V_31 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_338 ( struct V_3 * V_4 ,
struct V_462 * * V_469 )
{
struct V_462 * V_470 ;
while ( ( V_470 = * V_469 ) != NULL ) {
if ( V_470 -> V_93 == V_4 -> V_93 ) {
F_331 ( V_4 , V_470 , - 1 ) ;
* V_469 = V_470 -> V_471 ;
F_205 ( V_470 ) ;
} else
V_469 = & V_470 -> V_471 ;
}
}
static int F_339 ( struct V_23 * V_24 , struct V_472 * V_473 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_462 * V_470 , * V_201 ;
struct V_3 * V_4 ;
int V_92 ;
F_75 () ;
V_92 = - V_300 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_473 -> V_474 ) ;
if ( ! V_4 )
goto V_475;
V_92 = - V_248 ;
if ( V_473 -> V_476 > V_4 -> V_429 )
goto V_475;
V_92 = - V_184 ;
V_201 = F_340 ( sizeof( * V_201 ) , V_262 ) ;
if ( V_201 == NULL )
goto V_475;
V_92 = 0 ;
for ( V_470 = V_14 -> V_477 ; V_470 ; V_470 = V_470 -> V_471 ) {
if ( V_470 -> V_93 == V_473 -> V_474 &&
V_470 -> type == V_473 -> V_478 &&
V_470 -> V_465 == V_473 -> V_476 &&
memcmp ( V_470 -> V_31 , V_473 -> V_479 , V_470 -> V_465 ) == 0 ) {
V_470 -> V_202 ++ ;
F_205 ( V_201 ) ;
goto V_475;
}
}
V_201 -> type = V_473 -> V_478 ;
V_201 -> V_93 = V_473 -> V_474 ;
V_201 -> V_465 = V_473 -> V_476 ;
memcpy ( V_201 -> V_31 , V_473 -> V_479 , V_201 -> V_465 ) ;
memset ( V_201 -> V_31 + V_201 -> V_465 , 0 , sizeof( V_201 -> V_31 ) - V_201 -> V_465 ) ;
V_201 -> V_202 = 1 ;
V_201 -> V_471 = V_14 -> V_477 ;
V_14 -> V_477 = V_201 ;
V_92 = F_331 ( V_4 , V_201 , 1 ) ;
if ( V_92 ) {
V_14 -> V_477 = V_201 -> V_471 ;
F_205 ( V_201 ) ;
}
V_475:
F_78 () ;
return V_92 ;
}
static int F_341 ( struct V_23 * V_24 , struct V_472 * V_473 )
{
struct V_462 * V_470 , * * V_469 ;
F_75 () ;
for ( V_469 = & F_35 ( V_24 ) -> V_477 ; ( V_470 = * V_469 ) != NULL ; V_469 = & V_470 -> V_471 ) {
if ( V_470 -> V_93 == V_473 -> V_474 &&
V_470 -> type == V_473 -> V_478 &&
V_470 -> V_465 == V_473 -> V_476 &&
memcmp ( V_470 -> V_31 , V_473 -> V_479 , V_470 -> V_465 ) == 0 ) {
if ( -- V_470 -> V_202 == 0 ) {
struct V_3 * V_4 ;
* V_469 = V_470 -> V_471 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_470 -> V_93 ) ;
if ( V_4 )
F_331 ( V_4 , V_470 , - 1 ) ;
F_205 ( V_470 ) ;
}
break;
}
}
F_78 () ;
return 0 ;
}
static void F_302 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_35 ( V_24 ) ;
struct V_462 * V_470 ;
if ( ! V_14 -> V_477 )
return;
F_75 () ;
while ( ( V_470 = V_14 -> V_477 ) != NULL ) {
struct V_3 * V_4 ;
V_14 -> V_477 = V_470 -> V_471 ;
V_4 = F_76 ( F_77 ( V_24 ) , V_470 -> V_93 ) ;
if ( V_4 != NULL )
F_331 ( V_4 , V_470 , - 1 ) ;
F_205 ( V_470 ) ;
}
F_78 () ;
}
static int
F_342 ( struct V_287 * V_23 , int V_480 , int V_481 , char T_6 * V_482 , unsigned int V_483 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_8 ;
if ( V_480 != V_451 )
return - V_484 ;
switch ( V_481 ) {
case V_485 :
case V_486 :
{
struct V_472 V_473 ;
int V_174 = V_483 ;
memset ( & V_473 , 0 , sizeof( V_473 ) ) ;
if ( V_174 < sizeof( struct V_487 ) )
return - V_248 ;
if ( V_174 > sizeof( V_473 ) )
V_174 = sizeof( V_473 ) ;
if ( F_185 ( & V_473 , V_482 , V_174 ) )
return - V_249 ;
if ( V_174 < ( V_473 . V_476 + F_281 ( struct V_487 , V_479 ) ) )
return - V_248 ;
if ( V_481 == V_485 )
V_8 = F_339 ( V_24 , & V_473 ) ;
else
V_8 = F_341 ( V_24 , & V_473 ) ;
return V_8 ;
}
case V_488 :
case V_489 :
{
union V_100 V_101 ;
int V_174 ;
switch ( V_14 -> V_37 ) {
case V_38 :
case V_41 :
V_174 = sizeof( V_101 . V_490 ) ;
break;
case V_43 :
default:
V_174 = sizeof( V_101 . V_103 ) ;
break;
}
if ( V_483 < V_174 )
return - V_248 ;
if ( F_185 ( & V_101 . V_490 , V_482 , V_174 ) )
return - V_249 ;
return F_303 ( V_24 , & V_101 , 0 ,
V_481 == V_489 ) ;
}
case V_491 :
{
int V_209 ;
if ( V_483 != sizeof( V_209 ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
F_35 ( V_24 ) -> V_367 = V_209 ;
return 0 ;
}
case V_492 :
{
int V_209 ;
if ( V_483 != sizeof( V_209 ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
switch ( V_209 ) {
case V_38 :
case V_41 :
case V_43 :
break;
default:
return - V_248 ;
}
F_308 ( V_24 ) ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 ) {
V_8 = - V_493 ;
} else {
V_14 -> V_37 = V_209 ;
V_8 = 0 ;
}
F_310 ( V_24 ) ;
return V_8 ;
}
case V_494 :
{
unsigned int V_209 ;
if ( V_483 != sizeof( V_209 ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
if ( V_209 > V_495 )
return - V_248 ;
F_308 ( V_24 ) ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 ) {
V_8 = - V_493 ;
} else {
V_14 -> V_364 = V_209 ;
V_8 = 0 ;
}
F_310 ( V_24 ) ;
return V_8 ;
}
case V_496 :
{
unsigned int V_209 ;
if ( V_483 != sizeof( V_209 ) )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_493 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_411 = ! ! V_209 ;
return 0 ;
}
case V_456 :
{
int V_209 ;
if ( V_483 < sizeof( V_209 ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_453 = ! ! V_209 ;
return 0 ;
}
case V_497 :
{
int V_209 ;
if ( V_483 < sizeof( V_209 ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_347 = ! ! V_209 ;
return 0 ;
}
case V_498 :
{
int V_209 ;
if ( V_23 -> type != V_407 )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_493 ;
if ( V_483 < sizeof( V_209 ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_366 = ! ! V_209 ;
return 0 ;
}
case V_499 :
{
int V_209 ;
if ( V_483 != sizeof( V_209 ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_56 = V_209 ;
return 0 ;
}
case V_500 :
{
int V_209 ;
if ( V_483 != sizeof( V_209 ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
return F_196 ( V_24 , V_209 & 0xffff , V_209 >> 16 ) ;
}
case V_501 :
{
if ( ! V_14 -> V_26 )
return - V_248 ;
return F_191 ( V_14 , V_482 , V_483 ) ;
}
case V_502 :
{
unsigned int V_209 ;
if ( V_483 != sizeof( V_209 ) )
return - V_248 ;
if ( V_14 -> V_78 . V_69 || V_14 -> V_183 . V_69 )
return - V_493 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_396 = ! ! V_209 ;
return 0 ;
}
case V_503 :
{
int V_209 ;
if ( V_483 != sizeof( V_209 ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , sizeof( V_209 ) ) )
return - V_249 ;
V_14 -> V_16 = V_209 ? F_1 : F_239 ;
return 0 ;
}
default:
return - V_484 ;
}
}
static int F_343 ( struct V_287 * V_23 , int V_480 , int V_481 ,
char T_6 * V_482 , int T_6 * V_483 )
{
int V_174 ;
int V_209 , V_504 = sizeof( V_209 ) ;
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
void * V_81 = & V_209 ;
union V_505 V_506 ;
struct V_507 V_508 ;
if ( V_480 != V_451 )
return - V_484 ;
if ( F_344 ( V_174 , V_483 ) )
return - V_249 ;
if ( V_174 < 0 )
return - V_248 ;
switch ( V_481 ) {
case V_509 :
F_68 ( & V_24 -> V_130 . V_79 ) ;
memcpy ( & V_506 , & V_14 -> V_119 , sizeof( V_506 ) ) ;
memset ( & V_14 -> V_119 , 0 , sizeof( V_14 -> V_119 ) ) ;
F_69 ( & V_24 -> V_130 . V_79 ) ;
if ( V_14 -> V_37 == V_43 ) {
V_504 = sizeof( struct V_510 ) ;
V_506 . V_120 . V_353 += V_506 . V_120 . V_149 ;
V_81 = & V_506 . V_120 ;
} else {
V_504 = sizeof( struct V_511 ) ;
V_506 . V_352 . V_353 += V_506 . V_352 . V_149 ;
V_81 = & V_506 . V_352 ;
}
break;
case V_456 :
V_209 = V_14 -> V_453 ;
break;
case V_497 :
V_209 = V_14 -> V_347 ;
break;
case V_498 :
V_209 = V_14 -> V_366 ;
break;
case V_492 :
V_209 = V_14 -> V_37 ;
break;
case V_512 :
if ( V_174 > sizeof( int ) )
V_174 = sizeof( int ) ;
if ( V_174 < sizeof( int ) )
return - V_248 ;
if ( F_185 ( & V_209 , V_482 , V_174 ) )
return - V_249 ;
switch ( V_209 ) {
case V_38 :
V_209 = sizeof( struct V_513 ) ;
break;
case V_41 :
V_209 = sizeof( struct V_514 ) ;
break;
case V_43 :
V_209 = sizeof( struct V_144 ) ;
break;
default:
return - V_248 ;
}
break;
case V_494 :
V_209 = V_14 -> V_364 ;
break;
case V_496 :
V_209 = V_14 -> V_411 ;
break;
case V_499 :
V_209 = V_14 -> V_56 ;
break;
case V_500 :
V_209 = ( V_14 -> V_26 ?
( ( T_5 ) V_14 -> V_26 -> V_253 |
( ( T_5 ) V_14 -> V_26 -> type << 16 ) |
( ( T_5 ) V_14 -> V_26 -> V_47 << 24 ) ) :
0 ) ;
break;
case V_515 :
if ( ! V_14 -> V_204 )
return - V_248 ;
V_508 . V_516 = F_345 ( & V_14 -> V_204 -> V_208 ) ;
V_508 . V_517 = F_345 ( & V_14 -> V_204 -> V_217 ) ;
V_508 . V_518 = F_345 ( & V_14 -> V_204 -> V_218 ) ;
V_81 = & V_508 ;
V_504 = sizeof( V_508 ) ;
break;
case V_502 :
V_209 = V_14 -> V_396 ;
break;
case V_503 :
V_209 = F_29 ( V_14 ) ;
break;
default:
return - V_484 ;
}
if ( V_174 > V_504 )
V_174 = V_504 ;
if ( F_346 ( V_174 , V_483 ) )
return - V_249 ;
if ( F_347 ( V_482 , V_81 , V_174 ) )
return - V_249 ;
return 0 ;
}
static int F_348 ( struct V_287 * V_23 , int V_480 , int V_481 ,
char T_6 * V_482 , unsigned int V_483 )
{
struct V_13 * V_14 = F_35 ( V_23 -> V_24 ) ;
if ( V_480 != V_451 )
return - V_484 ;
if ( V_481 == V_501 &&
V_14 -> V_26 && V_14 -> V_26 -> type == V_236 ) {
V_482 = ( char T_6 * ) F_349 ( V_482 ) ;
if ( ! V_482 )
return - V_249 ;
V_483 = sizeof( struct V_244 ) ;
}
return F_342 ( V_23 , V_480 , V_481 , V_482 , V_483 ) ;
}
static int F_350 ( struct V_519 * V_520 ,
unsigned long V_289 , void * V_521 )
{
struct V_23 * V_24 ;
struct V_3 * V_4 = F_351 ( V_521 ) ;
struct V_227 * V_227 = F_174 ( V_4 ) ;
F_20 () ;
F_352 (sk, &net->packet.sklist) {
struct V_13 * V_14 = F_35 ( V_24 ) ;
switch ( V_289 ) {
case V_522 :
if ( V_14 -> V_477 )
F_338 ( V_4 , & V_14 -> V_477 ) ;
case V_523 :
if ( V_4 -> V_93 == V_14 -> V_93 ) {
F_45 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_25 ) {
F_39 ( V_24 , false ) ;
V_24 -> V_426 = V_302 ;
if ( ! F_150 ( V_24 , V_199 ) )
V_24 -> V_427 ( V_24 ) ;
}
if ( V_289 == V_522 ) {
F_27 ( V_14 ) ;
V_14 -> V_93 = - 1 ;
if ( V_14 -> V_27 . V_4 )
F_289 ( V_14 -> V_27 . V_4 ) ;
V_14 -> V_27 . V_4 = NULL ;
}
F_43 ( & V_14 -> V_29 ) ;
}
break;
case V_524 :
if ( V_4 -> V_93 == V_14 -> V_93 ) {
F_45 ( & V_14 -> V_29 ) ;
if ( V_14 -> V_208 )
F_34 ( V_24 ) ;
F_43 ( & V_14 -> V_29 ) ;
}
break;
}
}
F_24 () ;
return V_525 ;
}
static int F_353 ( struct V_287 * V_23 , unsigned int V_526 ,
unsigned long V_527 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
switch ( V_526 ) {
case V_528 :
{
int V_529 = F_354 ( V_24 ) ;
return F_346 ( V_529 , ( int T_6 * ) V_527 ) ;
}
case V_530 :
{
struct V_1 * V_2 ;
int V_529 = 0 ;
F_68 ( & V_24 -> V_130 . V_79 ) ;
V_2 = F_355 ( & V_24 -> V_130 ) ;
if ( V_2 )
V_529 = V_2 -> V_174 ;
F_69 ( & V_24 -> V_130 . V_79 ) ;
return F_346 ( V_529 , ( int T_6 * ) V_527 ) ;
}
case V_531 :
return F_356 ( V_24 , (struct V_532 T_6 * ) V_527 ) ;
case V_533 :
return F_357 ( V_24 , (struct V_45 T_6 * ) V_527 ) ;
#ifdef F_358
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
case V_547 :
return V_548 . V_549 ( V_23 , V_526 , V_527 ) ;
#endif
default:
return - V_550 ;
}
return 0 ;
}
static unsigned int F_359 ( struct V_551 * V_551 , struct V_287 * V_23 ,
T_9 * V_552 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
unsigned int V_553 = F_360 ( V_551 , V_23 , V_552 ) ;
F_68 ( & V_24 -> V_130 . V_79 ) ;
if ( V_14 -> V_78 . V_69 ) {
if ( ! F_127 ( V_14 , & V_14 -> V_78 ,
V_161 ) )
V_553 |= V_554 | V_555 ;
}
if ( V_14 -> V_196 && F_144 ( V_14 , NULL ) == V_193 )
V_14 -> V_196 = 0 ;
F_69 ( & V_24 -> V_130 . V_79 ) ;
F_68 ( & V_24 -> V_556 . V_79 ) ;
if ( V_14 -> V_183 . V_69 ) {
if ( F_63 ( V_14 , & V_14 -> V_183 , V_170 ) )
V_553 |= V_557 | V_558 ;
}
F_69 ( & V_24 -> V_556 . V_79 ) ;
return V_553 ;
}
static void F_361 ( struct V_559 * V_560 )
{
struct V_551 * V_551 = V_560 -> V_561 ;
struct V_287 * V_23 = V_551 -> V_562 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_119 ( & F_35 ( V_24 ) -> V_563 ) ;
}
static void F_362 ( struct V_559 * V_560 )
{
struct V_551 * V_551 = V_560 -> V_561 ;
struct V_287 * V_23 = V_551 -> V_562 ;
struct V_23 * V_24 = V_23 -> V_24 ;
if ( V_24 )
F_108 ( & F_35 ( V_24 ) -> V_563 ) ;
}
static void F_363 ( struct V_105 * V_69 , unsigned int V_564 ,
unsigned int V_174 )
{
int V_201 ;
for ( V_201 = 0 ; V_201 < V_174 ; V_201 ++ ) {
if ( F_22 ( V_69 [ V_201 ] . V_70 ) ) {
if ( F_48 ( V_69 [ V_201 ] . V_70 ) )
F_364 ( V_69 [ V_201 ] . V_70 ) ;
else
F_365 ( ( unsigned long ) V_69 [ V_201 ] . V_70 ,
V_564 ) ;
V_69 [ V_201 ] . V_70 = NULL ;
}
}
F_205 ( V_69 ) ;
}
static char * F_366 ( unsigned long V_564 )
{
char * V_70 ;
T_10 V_565 = V_262 | V_566 |
V_567 | V_568 | V_569 ;
V_70 = ( char * ) F_367 ( V_565 , V_564 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_368 ( ( 1 << V_564 ) * V_140 ) ;
if ( V_70 )
return V_70 ;
V_565 &= ~ V_569 ;
V_70 = ( char * ) F_367 ( V_565 , V_564 ) ;
if ( V_70 )
return V_70 ;
return NULL ;
}
static struct V_105 * F_369 ( struct V_570 * V_490 , int V_564 )
{
unsigned int V_571 = V_490 -> V_114 ;
struct V_105 * V_69 ;
int V_201 ;
V_69 = F_370 ( V_571 , sizeof( struct V_105 ) , V_262 ) ;
if ( F_2 ( ! V_69 ) )
goto V_131;
for ( V_201 = 0 ; V_201 < V_571 ; V_201 ++ ) {
V_69 [ V_201 ] . V_70 = F_366 ( V_564 ) ;
if ( F_2 ( ! V_69 [ V_201 ] . V_70 ) )
goto V_572;
}
V_131:
return V_69 ;
V_572:
F_363 ( V_69 , V_564 , V_571 ) ;
V_69 = NULL ;
goto V_131;
}
static int F_303 ( struct V_23 * V_24 , union V_100 * V_101 ,
int V_573 , int V_183 )
{
struct V_105 * V_69 = NULL ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
int V_574 , V_564 = 0 ;
struct V_63 * V_64 ;
struct V_76 * V_77 ;
T_8 V_208 ;
int V_92 = - V_248 ;
struct V_570 * V_490 = & V_101 -> V_490 ;
F_308 ( V_24 ) ;
V_64 = V_183 ? & V_14 -> V_183 : & V_14 -> V_78 ;
V_77 = V_183 ? & V_24 -> V_556 : & V_24 -> V_130 ;
V_92 = - V_493 ;
if ( ! V_573 ) {
if ( F_90 ( & V_14 -> V_563 ) )
goto V_131;
if ( F_135 ( V_64 ) )
goto V_131;
}
if ( V_490 -> V_114 ) {
V_92 = - V_493 ;
if ( F_2 ( V_64 -> V_69 ) )
goto V_131;
switch ( V_14 -> V_37 ) {
case V_38 :
V_14 -> V_116 = V_575 ;
break;
case V_41 :
V_14 -> V_116 = V_576 ;
break;
case V_43 :
V_14 -> V_116 = V_577 ;
break;
}
V_92 = - V_248 ;
if ( F_2 ( ( int ) V_490 -> V_112 <= 0 ) )
goto V_131;
if ( F_2 ( ! F_371 ( V_490 -> V_112 ) ) )
goto V_131;
if ( V_14 -> V_37 >= V_43 &&
V_490 -> V_112 <=
F_83 ( ( V_578 ) V_101 -> V_103 . V_126 ) )
goto V_131;
if ( F_2 ( V_490 -> V_579 < V_14 -> V_116 +
V_14 -> V_364 ) )
goto V_131;
if ( F_2 ( V_490 -> V_579 & ( V_580 - 1 ) ) )
goto V_131;
V_64 -> V_68 = V_490 -> V_112 / V_490 -> V_579 ;
if ( F_2 ( V_64 -> V_68 == 0 ) )
goto V_131;
if ( F_2 ( V_490 -> V_112 > V_581 / V_490 -> V_114 ) )
goto V_131;
if ( F_2 ( ( V_64 -> V_68 * V_490 -> V_114 ) !=
V_490 -> V_582 ) )
goto V_131;
V_92 = - V_261 ;
V_564 = F_372 ( V_490 -> V_112 ) ;
V_69 = F_369 ( V_490 , V_564 ) ;
if ( F_2 ( ! V_69 ) )
goto V_131;
switch ( V_14 -> V_37 ) {
case V_43 :
if ( ! V_183 ) {
F_81 ( V_14 , V_64 , V_69 , V_101 ) ;
} else {
struct V_583 * V_103 = & V_101 -> V_103 ;
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
if ( F_2 ( V_490 -> V_582 ) )
goto V_131;
}
F_45 ( & V_14 -> V_29 ) ;
V_574 = V_14 -> V_25 ;
V_208 = V_14 -> V_208 ;
if ( V_574 ) {
V_14 -> V_208 = 0 ;
F_39 ( V_24 , false ) ;
}
F_43 ( & V_14 -> V_29 ) ;
F_44 () ;
V_92 = - V_493 ;
F_197 ( & V_14 -> V_404 ) ;
if ( V_573 || F_90 ( & V_14 -> V_563 ) == 0 ) {
V_92 = 0 ;
F_68 ( & V_77 -> V_79 ) ;
F_373 ( V_64 -> V_69 , V_69 ) ;
V_64 -> V_178 = ( V_490 -> V_582 - 1 ) ;
V_64 -> V_72 = 0 ;
V_64 -> V_71 = V_490 -> V_579 ;
F_69 ( & V_77 -> V_79 ) ;
F_373 ( V_64 -> V_584 , V_564 ) ;
F_373 ( V_64 -> V_585 , V_490 -> V_114 ) ;
V_64 -> V_586 = V_490 -> V_112 / V_140 ;
V_14 -> V_27 . F_71 = ( V_14 -> V_78 . V_69 ) ?
V_187 : F_245 ;
F_147 ( V_77 ) ;
if ( F_90 ( & V_14 -> V_563 ) )
F_151 ( L_8 ,
F_90 ( & V_14 -> V_563 ) ) ;
}
F_206 ( & V_14 -> V_404 ) ;
F_45 ( & V_14 -> V_29 ) ;
if ( V_574 ) {
V_14 -> V_208 = V_208 ;
F_34 ( V_24 ) ;
}
F_43 ( & V_14 -> V_29 ) ;
if ( V_69 && ( V_14 -> V_37 > V_41 ) ) {
if ( ! V_183 )
F_66 ( V_14 , V_77 ) ;
}
if ( V_69 )
F_363 ( V_69 , V_564 , V_490 -> V_114 ) ;
V_131:
F_310 ( V_24 ) ;
return V_92 ;
}
static int F_374 ( struct V_551 * V_551 , struct V_287 * V_23 ,
struct V_559 * V_560 )
{
struct V_23 * V_24 = V_23 -> V_24 ;
struct V_13 * V_14 = F_35 ( V_24 ) ;
unsigned long V_587 , V_588 ;
struct V_63 * V_64 ;
unsigned long V_138 ;
int V_92 = - V_248 ;
int V_201 ;
if ( V_560 -> V_589 )
return - V_248 ;
F_197 ( & V_14 -> V_404 ) ;
V_588 = 0 ;
for ( V_64 = & V_14 -> V_78 ; V_64 <= & V_14 -> V_183 ; V_64 ++ ) {
if ( V_64 -> V_69 ) {
V_588 += V_64 -> V_585
* V_64 -> V_586
* V_140 ;
}
}
if ( V_588 == 0 )
goto V_131;
V_587 = V_560 -> V_590 - V_560 -> V_591 ;
if ( V_587 != V_588 )
goto V_131;
V_138 = V_560 -> V_591 ;
for ( V_64 = & V_14 -> V_78 ; V_64 <= & V_14 -> V_183 ; V_64 ++ ) {
if ( V_64 -> V_69 == NULL )
continue;
for ( V_201 = 0 ; V_201 < V_64 -> V_585 ; V_201 ++ ) {
struct V_30 * V_30 ;
void * V_592 = V_64 -> V_69 [ V_201 ] . V_70 ;
int V_593 ;
for ( V_593 = 0 ; V_593 < V_64 -> V_586 ; V_593 ++ ) {
V_30 = F_47 ( V_592 ) ;
V_92 = F_375 ( V_560 , V_138 , V_30 ) ;
if ( F_2 ( V_92 ) )
goto V_131;
V_138 += V_140 ;
V_592 += V_140 ;
}
}
}
F_119 ( & V_14 -> V_563 ) ;
V_560 -> V_594 = & V_595 ;
V_92 = 0 ;
V_131:
F_206 ( & V_14 -> V_404 ) ;
return V_92 ;
}
static void * F_376 ( struct V_596 * V_597 , T_11 * V_598 )
__acquires( T_12 )
{
struct V_227 * V_227 = F_377 ( V_597 ) ;
F_20 () ;
return F_378 ( & V_227 -> V_419 . V_444 , * V_598 ) ;
}
static void * F_379 ( struct V_596 * V_597 , void * V_599 , T_11 * V_598 )
{
struct V_227 * V_227 = F_377 ( V_597 ) ;
return F_380 ( V_599 , & V_227 -> V_419 . V_444 , V_598 ) ;
}
static void F_381 ( struct V_596 * V_597 , void * V_599 )
__releases( T_12 )
{
F_24 () ;
}
static int F_382 ( struct V_596 * V_597 , void * V_599 )
{
if ( V_599 == V_600 )
F_383 ( V_597 , L_9 ) ;
else {
struct V_23 * V_601 = F_384 ( V_599 ) ;
const struct V_13 * V_14 = F_35 ( V_601 ) ;
F_385 ( V_597 ,
L_10 ,
V_601 ,
F_149 ( & V_601 -> V_602 ) ,
V_601 -> V_337 ,
F_115 ( V_14 -> V_208 ) ,
V_14 -> V_93 ,
V_14 -> V_25 ,
F_90 ( & V_601 -> V_190 ) ,
F_386 ( F_387 ( V_597 ) , F_388 ( V_601 ) ) ,
F_389 ( V_601 ) ) ;
}
return 0 ;
}
static int F_390 ( struct V_603 * V_603 , struct V_551 * V_551 )
{
return F_391 ( V_603 , V_551 , & V_604 ,
sizeof( struct V_605 ) ) ;
}
static int T_13 F_392 ( struct V_227 * V_227 )
{
F_318 ( & V_227 -> V_419 . V_420 ) ;
F_393 ( & V_227 -> V_419 . V_444 ) ;
if ( ! F_394 ( L_11 , 0 , V_227 -> V_606 , & V_607 ) )
return - V_261 ;
return 0 ;
}
static void T_14 F_395 ( struct V_227 * V_227 )
{
F_396 ( L_11 , V_227 -> V_606 ) ;
}
static void T_15 F_397 ( void )
{
F_398 ( & V_608 ) ;
F_399 ( & V_609 ) ;
F_400 ( V_241 ) ;
F_401 ( & V_439 ) ;
}
static int T_16 F_402 ( void )
{
int V_610 = F_403 ( & V_439 , 0 ) ;
if ( V_610 != 0 )
goto V_131;
F_404 ( & V_611 ) ;
F_405 ( & V_609 ) ;
F_406 ( & V_608 ) ;
V_131:
return V_610 ;
}
