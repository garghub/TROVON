static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_6 -> V_9 || V_6 -> V_10 )
return - V_11 ;
* V_4 = V_8 -> V_4 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_12 , struct V_13 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
int V_16 = - V_11 ;
if ( F_4 ( V_12 != 1 ) ) {
F_5 ( L_1 , V_12 ) ;
goto V_17;
}
V_15 = & V_8 -> V_15 ;
* V_4 = V_15 -> V_4 ;
F_6 ( & V_8 -> V_18 ) ;
V_16 = F_7 ( V_2 , V_12 , & V_4 -> V_19 ,
& V_4 -> V_20 ) ;
F_8 ( & V_8 -> V_18 ) ;
V_17:
return V_16 ;
}
static int F_9 ( struct V_1 * V_21 ,
T_1 V_12 , int V_22 , union V_23 * V_24 )
{
int V_25 ;
if ( V_22 > V_26 )
return - V_11 ;
V_25 = F_10 ( V_21 , V_12 , V_22 , V_24 , NULL ) ;
if ( V_25 == - V_27 ) {
memcpy ( V_24 , & V_28 , sizeof( * V_24 ) ) ;
return 0 ;
}
return V_25 ;
}
static int F_11 ( struct V_1 * V_21 , T_1 V_12 , unsigned int
V_22 , const union V_23 * V_24 ,
const struct V_29 * V_4 , void * * V_30 )
{
if ( V_22 >= V_26 )
return - V_11 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_21 , T_1 V_12 , unsigned int
V_22 , void * * V_30 )
{
if ( V_22 >= V_26 )
return - V_11 ;
return 0 ;
}
static struct V_31 * F_13 ( struct V_1 * V_21 ,
T_1 V_12 )
{
struct V_7 * V_8 = F_2 ( V_21 ) ;
if ( V_8 -> V_32 ) {
F_14 ( V_8 -> V_32 ) ;
return V_8 -> V_32 ;
}
return NULL ;
}
static int F_15 ( struct V_1 * V_21 ,
T_1 V_12 , T_2 V_22 , T_2 * V_33 )
{
struct V_7 * V_8 = F_2 ( V_21 ) ;
struct V_14 * V_15 ;
if ( F_4 ( V_12 != 1 ) ) {
F_16 ( V_21 -> V_2 . V_34 , L_2 ,
V_12 ) ;
goto V_35;
}
V_15 = & V_8 -> V_15 ;
if ( F_4 ( V_22 >= V_15 -> V_4 . V_36 ) ) {
F_16 ( V_21 -> V_2 . V_34 , L_3 ,
V_22 ) ;
goto V_35;
}
* V_33 = V_15 -> V_37 [ V_22 ] ;
return 0 ;
V_35:
return - V_11 ;
}
static int F_17 ( struct V_1 * V_2 ,
int V_38 , struct V_39 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_38 & V_40 )
V_8 -> V_4 . V_41 = F_18 ( V_4 -> V_41 ) ;
if ( V_38 & V_42 ) {
memcpy ( V_8 -> V_43 . V_44 ,
V_4 -> V_44 , sizeof( V_8 -> V_43 . V_44 ) ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_1 V_12 , int V_38 , struct V_45 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
if ( F_4 ( V_12 != 1 ) ) {
F_5 ( L_2 , V_12 ) ;
goto V_35;
}
V_15 = & V_8 -> V_15 ;
V_15 -> V_4 . V_46 |= V_4 -> V_47 ;
V_15 -> V_4 . V_46 &= ~ V_4 -> V_48 ;
if ( V_38 & V_49 )
V_15 -> V_4 . V_50 = 0 ;
return 0 ;
V_35:
return - V_11 ;
}
static enum V_51 F_20 ( struct V_1 * V_2 ,
T_1 V_12 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_21 ( V_8 , V_12 ) ;
}
static struct V_52 * F_22 ( struct V_1 * V_2 ,
struct V_5 * V_53 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_54 * V_55 ;
V_55 = F_23 ( & V_8 -> V_56 ) ;
return V_55 ? & V_55 -> V_57 : F_24 ( - V_58 ) ;
}
static int F_25 ( struct V_52 * V_57 )
{
struct V_54 * V_55 = F_26 ( V_57 ) ;
F_27 ( V_55 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_12 ,
struct V_59 * V_60 )
{
int V_61 ;
struct V_13 V_4 ;
V_60 -> V_62 = V_63 ;
V_61 = F_29 ( V_2 , V_12 , & V_4 ) ;
if ( V_61 )
return V_61 ;
V_60 -> V_36 = V_4 . V_36 ;
V_60 -> V_64 = V_4 . V_64 ;
V_60 -> V_65 = V_66 ;
return 0 ;
}
static struct V_67 * F_30 ( struct V_1 * V_2 ,
struct V_52 * V_30 ,
struct V_5 * V_53 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_68 * V_69 ;
V_69 = F_23 ( & V_8 -> V_70 ) ;
return V_69 ? & V_69 -> V_71 : F_24 ( - V_58 ) ;
}
static int F_31 ( struct V_67 * V_71 )
{
struct V_68 * V_69 = F_32 ( V_71 ) ;
F_27 ( V_69 ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_8 , struct V_72 * V_4 ,
struct V_73 * V_74 )
{
int V_61 ;
union V_23 V_75 ;
struct V_29 V_76 ;
V_61 = F_10 ( & V_8 -> V_43 , F_34 ( V_4 ) ,
F_35 ( V_4 ) -> V_77 , & V_75 ,
& V_76 ) ;
if ( V_61 ) {
F_36 ( L_4 , V_61 ) ;
return V_61 ;
}
V_61 = F_37 ( V_8 , F_34 ( V_4 ) , V_74 , V_4 ) ;
if ( ! V_61 )
V_61 = F_38 ( V_8 , V_74 , V_4 , & V_76 , & V_75 ) ;
if ( V_76 . V_32 )
F_39 ( V_76 . V_32 ) ;
return V_61 ;
}
static struct V_78 * F_40 ( struct V_67 * V_71 ,
struct V_72 * V_4 ,
struct V_5 * V_53 )
{
int V_61 ;
struct V_7 * V_8 = F_2 ( V_71 -> V_21 ) ;
struct V_68 * V_69 = F_32 ( V_71 ) ;
struct V_79 * V_80 ;
V_61 = F_41 ( V_8 , V_4 ) ;
if ( V_61 )
goto V_35;
V_80 = F_23 ( & V_8 -> V_81 ) ;
if ( ! V_80 ) {
V_61 = - V_58 ;
goto V_35;
}
F_42 ( V_69 ) ;
V_80 -> V_69 = V_69 ;
V_61 = F_33 ( V_8 , V_4 , & V_80 -> V_74 ) ;
if ( V_61 )
goto V_82;
return & V_80 -> V_83 ;
V_82:
F_27 ( V_69 ) ;
F_27 ( V_80 ) ;
V_35:
return F_24 ( V_61 ) ;
}
static int F_43 ( struct V_78 * V_83 , struct V_72 * V_4 )
{
int V_61 ;
struct V_7 * V_8 = F_2 ( V_83 -> V_21 ) ;
struct V_79 * V_80 = F_44 ( V_83 ) ;
V_61 = F_41 ( V_8 , V_4 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_33 ( V_8 , V_4 , & V_80 -> V_74 ) ;
if ( V_61 )
return V_61 ;
return 0 ;
}
static int F_45 ( struct V_78 * V_83 , struct V_72 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_83 -> V_21 ) ;
struct V_79 * V_80 = F_44 ( V_83 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> type = V_83 -> type ;
F_46 ( V_8 , & V_80 -> V_74 , V_4 ) ;
return 0 ;
}
static int F_47 ( struct V_78 * V_83 )
{
struct V_79 * V_80 = F_44 ( V_83 ) ;
F_27 ( V_80 -> V_69 ) ;
F_27 ( V_80 ) ;
return 0 ;
}
static int F_48 ( struct V_84 * V_85 , struct V_86 * V_87 )
{
int V_61 ;
int V_88 ;
T_3 V_89 ;
struct V_90 * V_91 ;
int V_92 = V_87 -> V_92 ;
if ( F_4 ( F_49 ( V_85 -> V_93 ) ) ) {
V_61 = - V_58 ;
goto V_35;
}
if ( F_4 ( V_92 > V_85 -> V_94 ) ) {
V_61 = - V_11 ;
goto V_35;
}
V_89 = 0 ;
for ( V_88 = 0 ; V_88 < V_92 ; V_88 ++ )
V_89 += V_87 -> V_95 [ V_88 ] . V_89 ;
V_91 = F_50 ( V_85 -> V_93 ) ;
V_91 -> V_96 = V_87 -> V_96 ;
V_91 -> V_92 = V_92 ;
memcpy ( V_91 -> V_97 . V_98 , V_87 -> V_95 ,
V_92 * sizeof( struct V_99 ) ) ;
V_91 -> V_97 . V_89 = V_89 ;
V_91 -> V_97 . V_100 = V_89 ;
V_91 -> V_97 . V_92 = V_92 ;
V_91 -> V_97 . V_101 = 0 ;
V_91 -> V_97 . V_102 = 0 ;
F_51 () ;
F_52 ( V_85 -> V_93 ) ;
return 0 ;
V_35:
return V_61 ;
}
static struct V_103 * F_53 ( struct V_67 * V_71 ,
struct V_104 * V_105 ,
struct V_5 * V_53 )
{
int V_61 ;
struct V_7 * V_8 = F_2 ( V_71 -> V_21 ) ;
struct V_68 * V_69 = F_32 ( V_71 ) ;
struct V_106 * V_107 ;
struct V_52 * V_30 = V_53 ? V_71 -> V_108 -> V_30 : NULL ;
V_61 = F_54 ( V_8 , NULL , & V_105 -> V_4 , V_109 ) ;
if ( V_61 )
goto V_35;
V_107 = F_23 ( & V_8 -> V_110 ) ;
if ( ! V_107 ) {
V_61 = - V_58 ;
goto V_35;
}
F_55 ( V_107 ) ;
F_42 ( V_69 ) ;
V_107 -> V_69 = V_69 ;
V_61 = F_56 ( V_8 , V_107 , V_105 , V_30 , V_53 ) ;
if ( V_61 )
goto V_82;
return & V_107 -> V_111 ;
V_82:
F_27 ( V_69 ) ;
F_57 ( V_107 ) ;
F_27 ( V_107 ) ;
V_35:
return F_24 ( V_61 ) ;
}
static int F_58 ( struct V_103 * V_111 , struct V_112 * V_4 ,
enum V_113 V_38 ,
struct V_5 * V_53 )
{
int V_61 ;
struct V_106 * V_107 = F_59 ( V_111 ) ;
struct V_7 * V_8 = F_2 ( V_111 -> V_21 ) ;
V_61 = F_54 ( V_8 , V_107 , V_4 , V_38 ) ;
if ( V_61 )
goto V_35;
V_61 = F_60 ( V_8 , V_107 , V_4 , V_38 , V_53 ) ;
if ( V_61 )
goto V_35;
return 0 ;
V_35:
return V_61 ;
}
static int F_61 ( struct V_103 * V_111 , struct V_112 * V_4 )
{
struct V_106 * V_107 = F_59 ( V_111 ) ;
if ( V_107 -> error )
return - V_11 ;
V_4 -> V_114 = V_107 -> V_85 . V_93 -> V_115 -> V_116 ;
V_4 -> V_94 = V_107 -> V_85 . V_94 ;
V_4 -> V_117 = V_107 -> V_118 ;
return 0 ;
}
static int F_62 ( struct V_103 * V_111 )
{
struct V_106 * V_107 = F_59 ( V_111 ) ;
if ( V_107 -> V_85 . V_93 )
F_63 ( V_107 -> V_85 . V_93 ) ;
F_27 ( V_107 -> V_69 ) ;
F_57 ( V_107 ) ;
F_27 ( V_107 ) ;
return 0 ;
}
static int F_64 ( struct V_103 * V_111 , struct V_86 * V_119 ,
struct V_86 * * V_120 )
{
int V_61 = 0 ;
unsigned long V_121 ;
struct V_106 * V_107 = F_59 ( V_111 ) ;
F_65 ( & V_107 -> V_85 . V_122 , V_121 ) ;
while ( V_119 ) {
V_61 = F_48 ( & V_107 -> V_85 , V_119 ) ;
if ( F_4 ( V_61 ) )
break;
V_119 = V_119 -> V_123 ;
}
F_66 ( & V_107 -> V_85 . V_122 , V_121 ) ;
if ( V_61 )
* V_120 = V_119 ;
return V_61 ;
}
static struct V_124 * F_67 ( struct V_67 * V_71 ,
struct V_125 * V_105 ,
struct V_5 * V_53 )
{
int V_61 ;
struct V_7 * V_8 = F_2 ( V_71 -> V_21 ) ;
struct V_68 * V_69 = F_32 ( V_71 ) ;
struct V_126 * V_127 ;
V_61 = F_68 ( V_8 , V_105 ) ;
if ( V_61 )
goto V_35;
V_127 = F_23 ( & V_8 -> V_128 ) ;
if ( ! V_127 ) {
V_61 = - V_58 ;
goto V_35;
}
if ( V_53 ) {
if ( V_53 -> V_9 ) {
V_61 = - V_11 ;
goto V_82;
}
V_127 -> V_129 = 1 ;
}
F_55 ( V_127 ) ;
V_61 = F_69 ( V_8 , V_127 , V_69 , V_105 , V_53 , V_71 ) ;
if ( V_61 )
goto V_130;
return & V_127 -> V_131 ;
V_130:
F_57 ( V_127 ) ;
V_82:
F_27 ( V_127 ) ;
V_35:
return F_24 ( V_61 ) ;
}
static int F_70 ( struct V_124 * V_131 , struct V_132 * V_4 ,
int V_38 , struct V_5 * V_53 )
{
int V_61 ;
struct V_7 * V_8 = F_2 ( V_131 -> V_21 ) ;
struct V_126 * V_127 = F_71 ( V_131 ) ;
V_61 = F_72 ( V_8 , V_127 , V_4 , V_38 ) ;
if ( V_61 )
goto V_35;
V_61 = F_73 ( V_127 , V_4 , V_38 , V_53 ) ;
if ( V_61 )
goto V_35;
return 0 ;
V_35:
return V_61 ;
}
static int F_74 ( struct V_124 * V_131 , struct V_132 * V_4 ,
int V_38 , struct V_125 * V_105 )
{
struct V_126 * V_127 = F_71 ( V_131 ) ;
F_75 ( V_127 , V_105 ) ;
F_76 ( V_127 , V_4 , V_38 ) ;
return 0 ;
}
static int F_77 ( struct V_124 * V_131 )
{
struct V_126 * V_127 = F_71 ( V_131 ) ;
F_78 ( V_127 ) ;
F_57 ( V_127 ) ;
F_27 ( V_127 ) ;
return 0 ;
}
static int F_79 ( struct V_126 * V_127 , struct V_133 * V_87 ,
unsigned int V_38 , unsigned int V_89 )
{
int V_92 = V_87 -> V_92 ;
struct V_134 * V_135 = & V_127 -> V_135 ;
if ( F_4 ( V_92 > V_135 -> V_94 ) )
goto V_35;
if ( F_4 ( V_38 & V_136 ) ) {
if ( V_89 < 8 )
goto V_35;
if ( F_80 ( V_87 ) -> V_137 & 0x7 )
goto V_35;
}
if ( F_4 ( ( V_87 -> V_138 & V_139 ) &&
( V_89 > V_135 -> V_140 ) ) )
goto V_35;
return 0 ;
V_35:
return - V_11 ;
}
static void F_81 ( struct V_126 * V_127 , struct V_141 * V_119 ,
struct V_133 * V_87 )
{
V_119 -> V_96 = V_87 -> V_96 ;
V_119 -> V_92 = V_87 -> V_92 ;
V_119 -> V_142 = V_87 -> V_142 ;
V_119 -> V_138 = V_87 -> V_138 ;
if ( F_82 ( V_127 ) == V_143 ||
F_82 ( V_127 ) == V_144 ||
F_82 ( V_127 ) == V_145 ) {
V_119 -> V_119 . V_146 . V_147 = F_83 ( V_87 ) -> V_147 ;
V_119 -> V_119 . V_146 . V_148 = F_83 ( V_87 ) -> V_148 ;
if ( F_82 ( V_127 ) == V_145 )
V_119 -> V_119 . V_146 . V_149 = F_83 ( V_87 ) -> V_149 ;
if ( V_119 -> V_142 == V_150 )
V_119 -> V_151 . V_152 = V_87 -> V_151 . V_152 ;
} else {
switch ( V_119 -> V_142 ) {
case V_153 :
V_119 -> V_151 . V_152 = V_87 -> V_151 . V_152 ;
case V_154 :
case V_155 :
V_119 -> V_119 . V_156 . V_137 = F_84 ( V_87 ) -> V_137 ;
V_119 -> V_119 . V_156 . V_157 = F_84 ( V_87 ) -> V_157 ;
break;
case V_150 :
V_119 -> V_151 . V_152 = V_87 -> V_151 . V_152 ;
break;
case V_158 :
V_119 -> V_151 . V_159 = V_87 -> V_151 . V_159 ;
break;
case V_160 :
case V_161 :
V_119 -> V_119 . V_162 . V_137 =
F_80 ( V_87 ) -> V_137 ;
V_119 -> V_119 . V_162 . V_163 =
F_80 ( V_87 ) -> V_163 ;
V_119 -> V_119 . V_162 . V_164 = F_80 ( V_87 ) -> V_164 ;
V_119 -> V_119 . V_162 . V_157 = F_80 ( V_87 ) -> V_157 ;
break;
case V_165 :
V_119 -> V_151 . V_159 = V_87 -> V_151 . V_159 ;
break;
case V_166 :
V_119 -> V_119 . V_167 . V_168 = F_85 ( V_87 ) -> V_168 ;
V_119 -> V_119 . V_167 . V_169 = F_85 ( V_87 ) -> V_169 ;
V_119 -> V_119 . V_167 . V_170 = F_85 ( V_87 ) -> V_170 ;
break;
default:
break;
}
}
}
static int F_86 ( struct V_126 * V_127 , struct V_133 * V_87 ,
unsigned int V_38 , unsigned int V_89 ,
struct V_171 * V_172 )
{
int V_92 = V_87 -> V_92 ;
struct V_99 * V_98 ;
int V_88 ;
T_1 * V_173 ;
F_81 ( V_127 , & V_172 -> V_119 , V_87 ) ;
if ( F_82 ( V_127 ) == V_143 ||
F_82 ( V_127 ) == V_144 ||
F_82 ( V_127 ) == V_145 )
memcpy ( & V_172 -> V_74 , & F_44 ( F_83 ( V_87 ) -> V_80 ) -> V_74 , sizeof( V_172 -> V_74 ) ) ;
if ( F_4 ( V_87 -> V_138 & V_139 ) ) {
V_173 = V_172 -> V_97 . V_174 ;
V_98 = V_87 -> V_95 ;
for ( V_88 = 0 ; V_88 < V_92 ; V_88 ++ , V_98 ++ ) {
memcpy ( V_173 , ( void * ) ( V_175 ) V_98 -> V_176 ,
V_98 -> V_89 ) ;
V_173 += V_98 -> V_89 ;
}
} else if ( V_38 & V_177 ) {
V_172 -> V_38 = V_38 ;
V_172 -> V_178 = V_179 ;
return 0 ;
} else
memcpy ( V_172 -> V_97 . V_98 , V_87 -> V_95 ,
V_92 * sizeof( struct V_99 ) ) ;
V_172 -> V_180 = ( V_38 & V_136 ) ?
F_80 ( V_87 ) -> V_137 :
F_84 ( V_87 ) -> V_137 ;
V_172 -> V_38 = V_38 ;
V_172 -> V_97 . V_89 = V_89 ;
V_172 -> V_97 . V_100 = V_89 ;
V_172 -> V_97 . V_92 = V_92 ;
V_172 -> V_97 . V_101 = 0 ;
V_172 -> V_97 . V_102 = 0 ;
V_172 -> V_178 = V_179 ;
V_172 -> V_181 = F_87 ( 1 , & V_127 -> V_181 ) ;
return 0 ;
}
static int F_88 ( struct V_126 * V_127 , struct V_133 * V_87 ,
unsigned int V_38 , T_3 V_89 )
{
int V_61 ;
struct V_134 * V_135 = & V_127 -> V_135 ;
struct V_171 * V_182 ;
unsigned long V_121 ;
V_61 = F_79 ( V_127 , V_87 , V_38 , V_89 ) ;
if ( V_61 )
return V_61 ;
F_65 ( & V_127 -> V_135 . V_183 , V_121 ) ;
if ( F_4 ( F_49 ( V_135 -> V_93 ) ) ) {
V_61 = - V_58 ;
goto V_35;
}
V_182 = F_50 ( V_135 -> V_93 ) ;
V_61 = F_86 ( V_127 , V_87 , V_38 , V_89 , V_182 ) ;
if ( F_4 ( V_61 ) )
goto V_35;
F_51 () ;
F_52 ( V_135 -> V_93 ) ;
F_66 ( & V_127 -> V_135 . V_183 , V_121 ) ;
return 0 ;
V_35:
F_66 ( & V_127 -> V_135 . V_183 , V_121 ) ;
return V_61 ;
}
static int F_89 ( struct V_126 * V_127 , struct V_133 * V_119 ,
struct V_133 * * V_120 )
{
int V_61 = 0 ;
unsigned int V_38 ;
unsigned int V_89 = 0 ;
int V_88 ;
int V_184 ;
while ( V_119 ) {
V_38 = F_90 ( V_119 -> V_142 , V_127 ) ;
if ( F_4 ( ! V_38 ) ) {
V_61 = - V_11 ;
* V_120 = V_119 ;
break;
}
if ( F_4 ( ( V_119 -> V_138 & V_139 ) &&
! ( V_38 & V_185 ) ) ) {
V_61 = - V_11 ;
* V_120 = V_119 ;
break;
}
V_89 = 0 ;
for ( V_88 = 0 ; V_88 < V_119 -> V_92 ; V_88 ++ )
V_89 += V_119 -> V_95 [ V_88 ] . V_89 ;
V_61 = F_88 ( V_127 , V_119 , V_38 , V_89 ) ;
if ( V_61 ) {
* V_120 = V_119 ;
break;
}
V_119 = V_119 -> V_123 ;
}
V_184 = ( F_82 ( V_127 ) == V_145 ) ||
( F_91 ( V_127 -> V_135 . V_93 ) > 1 ) ;
F_92 ( & V_127 -> V_186 . V_187 , V_184 ) ;
return V_61 ;
}
static int F_93 ( struct V_124 * V_131 , struct V_133 * V_119 ,
struct V_133 * * V_120 )
{
struct V_126 * V_127 = F_71 ( V_131 ) ;
if ( F_4 ( ! V_127 -> V_188 ) ) {
* V_120 = V_119 ;
return - V_11 ;
}
if ( F_4 ( V_127 -> V_186 . V_178 < V_189 ) ) {
* V_120 = V_119 ;
return - V_11 ;
}
if ( V_127 -> V_129 ) {
F_92 ( & V_127 -> V_186 . V_187 , 0 ) ;
return 0 ;
} else
return F_89 ( V_127 , V_119 , V_120 ) ;
}
static int F_94 ( struct V_124 * V_131 , struct V_86 * V_119 ,
struct V_86 * * V_120 )
{
int V_61 = 0 ;
struct V_126 * V_127 = F_71 ( V_131 ) ;
struct V_84 * V_85 = & V_127 -> V_85 ;
unsigned long V_121 ;
if ( F_4 ( ( F_95 ( V_127 ) < V_190 ) || ! V_127 -> V_188 ) ) {
* V_120 = V_119 ;
V_61 = - V_11 ;
goto V_35;
}
if ( F_4 ( V_127 -> V_107 ) ) {
* V_120 = V_119 ;
V_61 = - V_11 ;
goto V_35;
}
F_65 ( & V_85 -> V_122 , V_121 ) ;
while ( V_119 ) {
V_61 = F_48 ( V_85 , V_119 ) ;
if ( F_4 ( V_61 ) ) {
* V_120 = V_119 ;
break;
}
V_119 = V_119 -> V_123 ;
}
F_66 ( & V_85 -> V_122 , V_121 ) ;
if ( V_127 -> V_191 . V_178 == V_192 )
F_92 ( & V_127 -> V_191 . V_187 , 1 ) ;
V_35:
return V_61 ;
}
static struct V_193 * F_96 ( struct V_1 * V_2 ,
const struct V_194 * V_4 ,
struct V_52 * V_30 ,
struct V_5 * V_53 )
{
int V_61 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_195 * V_196 ;
if ( V_4 -> V_121 )
return F_24 ( - V_11 ) ;
V_61 = F_97 ( V_8 , NULL , V_4 -> V_197 , V_4 -> V_198 , V_53 ) ;
if ( V_61 )
goto V_35;
V_196 = F_23 ( & V_8 -> V_199 ) ;
if ( ! V_196 ) {
V_61 = - V_58 ;
goto V_35;
}
V_61 = F_98 ( V_8 , V_196 , V_4 -> V_197 , V_4 -> V_198 ,
V_30 , V_53 ) ;
if ( V_61 )
goto V_82;
return & V_196 -> V_200 ;
V_82:
F_27 ( V_196 ) ;
V_35:
return F_24 ( V_61 ) ;
}
static int F_99 ( struct V_193 * V_200 )
{
struct V_195 * V_196 = F_100 ( V_200 ) ;
F_101 ( V_196 ) ;
F_27 ( V_196 ) ;
return 0 ;
}
static int F_102 ( struct V_193 * V_200 , int V_197 , struct V_5 * V_53 )
{
int V_61 ;
struct V_195 * V_196 = F_100 ( V_200 ) ;
struct V_7 * V_8 = F_2 ( V_200 -> V_21 ) ;
V_61 = F_97 ( V_8 , V_196 , V_197 , 0 , V_53 ) ;
if ( V_61 )
goto V_35;
V_61 = F_103 ( V_196 , V_197 , V_53 ) ;
if ( V_61 )
goto V_35;
return 0 ;
V_35:
return V_61 ;
}
static int F_104 ( struct V_193 * V_200 , int V_201 , struct V_202 * V_203 )
{
int V_88 ;
struct V_195 * V_196 = F_100 ( V_200 ) ;
struct V_204 * V_197 ;
unsigned long V_121 ;
F_65 ( & V_196 -> V_205 , V_121 ) ;
for ( V_88 = 0 ; V_88 < V_201 ; V_88 ++ ) {
V_197 = F_105 ( V_196 -> V_93 ) ;
if ( ! V_197 )
break;
memcpy ( V_203 ++ , & V_197 -> V_206 , sizeof( * V_203 ) ) ;
F_106 ( V_196 -> V_93 ) ;
}
F_66 ( & V_196 -> V_205 , V_121 ) ;
return V_88 ;
}
static int F_107 ( struct V_193 * V_200 , int V_207 )
{
struct V_195 * V_196 = F_100 ( V_200 ) ;
int V_208 = F_91 ( V_196 -> V_93 ) ;
return ( V_208 > V_207 ) ? V_207 : V_208 ;
}
static int F_108 ( struct V_193 * V_200 , enum V_209 V_121 )
{
struct V_195 * V_196 = F_100 ( V_200 ) ;
unsigned long V_210 ;
int V_25 = 0 ;
F_65 ( & V_196 -> V_205 , V_210 ) ;
if ( V_196 -> V_211 != V_212 )
V_196 -> V_211 = V_121 & V_213 ;
if ( ( V_121 & V_214 ) && ! F_109 ( V_196 -> V_93 ) )
V_25 = 1 ;
F_66 ( & V_196 -> V_205 , V_210 ) ;
return V_25 ;
}
static struct V_215 * F_110 ( struct V_67 * V_71 , int V_170 )
{
struct V_7 * V_8 = F_2 ( V_71 -> V_21 ) ;
struct V_68 * V_69 = F_32 ( V_71 ) ;
struct V_216 * V_168 ;
int V_61 ;
V_168 = F_23 ( & V_8 -> V_217 ) ;
if ( ! V_168 ) {
V_61 = - V_58 ;
goto V_35;
}
F_55 ( V_168 ) ;
F_42 ( V_69 ) ;
V_61 = F_111 ( V_8 , V_69 , V_170 , V_168 ) ;
if ( V_61 )
goto V_82;
return & V_168 -> V_218 ;
V_82:
F_27 ( V_69 ) ;
F_57 ( V_168 ) ;
F_27 ( V_168 ) ;
V_35:
return F_24 ( V_61 ) ;
}
static struct V_215 * F_112 ( struct V_67 * V_71 ,
T_4 V_219 ,
T_4 V_89 ,
T_4 V_180 ,
int V_170 , struct V_5 * V_53 )
{
int V_61 ;
struct V_7 * V_8 = F_2 ( V_71 -> V_21 ) ;
struct V_68 * V_69 = F_32 ( V_71 ) ;
struct V_216 * V_168 ;
V_168 = F_23 ( & V_8 -> V_217 ) ;
if ( ! V_168 ) {
V_61 = - V_58 ;
goto V_82;
}
F_55 ( V_168 ) ;
F_42 ( V_69 ) ;
V_61 = F_113 ( V_8 , V_69 , V_219 , V_89 , V_180 ,
V_170 , V_53 , V_168 ) ;
if ( V_61 )
goto V_130;
return & V_168 -> V_218 ;
V_130:
F_27 ( V_69 ) ;
F_57 ( V_168 ) ;
F_27 ( V_168 ) ;
V_82:
return F_24 ( V_61 ) ;
}
static int F_114 ( struct V_215 * V_218 )
{
struct V_216 * V_168 = F_115 ( V_218 ) ;
V_168 -> V_178 = V_220 ;
F_27 ( V_168 -> V_69 ) ;
F_57 ( V_168 ) ;
F_27 ( V_168 ) ;
return 0 ;
}
static struct V_215 * F_116 ( struct V_67 * V_71 ,
enum V_221 V_222 ,
T_3 V_223 )
{
struct V_7 * V_8 = F_2 ( V_71 -> V_21 ) ;
struct V_68 * V_69 = F_32 ( V_71 ) ;
struct V_216 * V_168 ;
int V_61 ;
if ( V_222 != V_224 )
return F_24 ( - V_11 ) ;
V_168 = F_23 ( & V_8 -> V_217 ) ;
if ( ! V_168 ) {
V_61 = - V_58 ;
goto V_35;
}
F_55 ( V_168 ) ;
F_42 ( V_69 ) ;
V_61 = F_117 ( V_8 , V_69 , V_223 , V_168 ) ;
if ( V_61 )
goto V_82;
return & V_168 -> V_218 ;
V_82:
F_27 ( V_69 ) ;
F_57 ( V_168 ) ;
F_27 ( V_168 ) ;
V_35:
return F_24 ( V_61 ) ;
}
static int F_118 ( struct V_215 * V_218 , T_4 V_176 )
{
struct V_216 * V_168 = F_115 ( V_218 ) ;
struct V_225 * V_226 ;
struct V_227 * V_115 ;
if ( F_4 ( V_168 -> V_228 == V_168 -> V_229 ) )
return - V_58 ;
V_226 = V_168 -> V_226 [ V_168 -> V_228 / V_230 ] ;
V_115 = & V_226 -> V_115 [ V_168 -> V_228 % V_230 ] ;
V_115 -> V_176 = V_176 ;
V_115 -> V_231 = V_218 -> V_232 ;
V_168 -> V_228 ++ ;
return 0 ;
}
static int F_119 ( struct V_215 * V_218 , struct V_233 * V_234 ,
int V_235 , unsigned int * V_236 )
{
struct V_216 * V_168 = F_115 ( V_218 ) ;
int V_237 ;
V_168 -> V_228 = 0 ;
V_237 = F_120 ( V_218 , V_234 , V_235 , V_236 , F_118 ) ;
V_168 -> V_238 = V_218 -> V_180 ;
V_168 -> V_180 = V_218 -> V_180 ;
V_168 -> V_89 = V_218 -> V_89 ;
V_168 -> V_239 = F_121 ( V_218 -> V_232 ) ;
V_168 -> V_240 = V_218 -> V_232 - 1 ;
V_168 -> V_241 = V_168 -> V_180 & V_168 -> V_240 ;
return V_237 ;
}
static int F_122 ( struct V_124 * V_131 , union V_23 * V_242 , T_2 V_243 )
{
int V_61 ;
struct V_7 * V_8 = F_2 ( V_131 -> V_21 ) ;
struct V_126 * V_127 = F_71 ( V_131 ) ;
struct V_244 * V_245 ;
V_61 = F_123 ( V_8 , V_242 , & V_245 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_124 ( V_8 , V_127 , V_245 ) ;
F_27 ( V_245 ) ;
return V_61 ;
}
static int F_125 ( struct V_124 * V_131 , union V_23 * V_242 , T_2 V_243 )
{
struct V_7 * V_8 = F_2 ( V_131 -> V_21 ) ;
struct V_126 * V_127 = F_71 ( V_131 ) ;
return F_126 ( V_8 , V_127 , V_242 ) ;
}
static T_5 F_127 ( struct V_21 * V_21 ,
struct V_246 * V_4 , char * V_115 )
{
struct V_7 * V_8 = F_128 ( V_21 , struct V_7 ,
V_43 . V_2 ) ;
return snprintf ( V_115 , 16 , L_5 , F_129 ( V_8 , 1 ) ) ;
}
int F_130 ( struct V_7 * V_8 )
{
int V_61 ;
int V_88 ;
struct V_1 * V_2 = & V_8 -> V_43 ;
F_131 ( V_2 -> V_247 , L_6 , V_248 ) ;
F_131 ( V_2 -> V_44 , L_7 , sizeof( V_2 -> V_44 ) ) ;
V_2 -> V_249 = V_250 ;
V_2 -> V_251 = V_252 ;
V_2 -> V_253 = 1 ;
V_2 -> V_254 = F_132 () ;
V_2 -> V_2 . V_34 = F_133 ( V_8 ) ;
V_2 -> V_255 = 0 ;
F_134 ( ( unsigned char * ) & V_2 -> V_256 ,
V_8 -> V_32 -> V_257 ) ;
V_2 -> V_2 . V_258 = & V_259 ;
F_135 ( & V_2 -> V_2 ,
F_136 ( V_2 -> V_2 . V_34 ) ) ;
V_2 -> V_260 = V_261 ;
V_2 -> V_262 = F_137 ( V_263 )
| F_137 ( V_264 )
| F_137 ( V_265 )
| F_137 ( V_266 )
| F_137 ( V_267 )
| F_137 ( V_268 )
| F_137 ( V_269 )
| F_137 ( V_270 )
| F_137 ( V_271 )
| F_137 ( V_272 )
| F_137 ( V_273 )
| F_137 ( V_274 )
| F_137 ( V_275 )
| F_137 ( V_276 )
| F_137 ( V_277 )
| F_137 ( V_278 )
| F_137 ( V_279 )
| F_137 ( V_280 )
| F_137 ( V_281 )
| F_137 ( V_282 )
| F_137 ( V_283 )
| F_137 ( V_284 )
| F_137 ( V_285 )
| F_137 ( V_286 )
| F_137 ( V_287 )
| F_137 ( V_288 )
| F_137 ( V_289 )
| F_137 ( V_290 )
| F_137 ( V_291 )
| F_137 ( V_292 )
| F_137 ( V_293 )
;
V_2 -> V_294 = F_1 ;
V_2 -> V_295 = F_17 ;
V_2 -> V_296 = F_3 ;
V_2 -> V_297 = F_19 ;
V_2 -> V_298 = F_20 ;
V_2 -> V_299 = F_9 ;
V_2 -> V_300 = F_13 ;
V_2 -> V_301 = F_11 ;
V_2 -> V_302 = F_12 ;
V_2 -> V_303 = F_15 ;
V_2 -> V_304 = F_22 ;
V_2 -> V_305 = F_25 ;
V_2 -> V_306 = V_307 ;
V_2 -> V_308 = F_28 ;
V_2 -> V_309 = F_30 ;
V_2 -> V_310 = F_31 ;
V_2 -> V_311 = F_40 ;
V_2 -> V_312 = F_43 ;
V_2 -> V_313 = F_45 ;
V_2 -> V_314 = F_47 ;
V_2 -> V_315 = F_53 ;
V_2 -> V_316 = F_58 ;
V_2 -> V_317 = F_61 ;
V_2 -> V_318 = F_62 ;
V_2 -> V_319 = F_64 ;
V_2 -> V_320 = F_67 ;
V_2 -> V_321 = F_70 ;
V_2 -> V_322 = F_74 ;
V_2 -> V_323 = F_77 ;
V_2 -> V_324 = F_93 ;
V_2 -> V_325 = F_94 ;
V_2 -> V_326 = F_96 ;
V_2 -> V_327 = F_99 ;
V_2 -> V_328 = F_102 ;
V_2 -> V_329 = F_104 ;
V_2 -> V_330 = F_107 ;
V_2 -> V_331 = F_108 ;
V_2 -> V_332 = F_110 ;
V_2 -> V_333 = F_112 ;
V_2 -> V_334 = F_114 ;
V_2 -> V_335 = F_116 ;
V_2 -> V_336 = F_119 ;
V_2 -> V_337 = F_122 ;
V_2 -> V_338 = F_125 ;
V_2 -> V_339 = V_340 ;
V_2 -> V_341 = V_342 ;
V_8 -> V_343 = F_138 ( L_8 , 0 , 0 ) ;
if ( F_139 ( V_8 -> V_343 ) ) {
F_36 ( L_9 ,
F_140 ( V_8 -> V_343 ) ) ;
return F_140 ( V_8 -> V_343 ) ;
}
V_61 = F_141 ( V_2 , NULL ) ;
if ( V_61 ) {
F_5 ( L_10 , V_344 , V_61 ) ;
goto V_35;
}
for ( V_88 = 0 ; V_88 < F_142 ( V_345 ) ; ++ V_88 ) {
V_61 = F_143 ( & V_2 -> V_2 , V_345 [ V_88 ] ) ;
if ( V_61 ) {
F_5 ( L_11 ,
V_344 , V_61 , V_88 ) ;
goto V_82;
}
}
return 0 ;
V_82:
F_144 ( V_2 ) ;
V_35:
F_145 ( V_8 -> V_343 ) ;
return V_61 ;
}
int F_146 ( struct V_7 * V_8 )
{
int V_88 ;
struct V_1 * V_2 = & V_8 -> V_43 ;
for ( V_88 = 0 ; V_88 < F_142 ( V_345 ) ; ++ V_88 )
F_147 ( & V_2 -> V_2 , V_345 [ V_88 ] ) ;
F_144 ( V_2 ) ;
return 0 ;
}
