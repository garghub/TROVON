static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
V_3 = F_2 ( V_5 -> V_7 . V_8 ) ;
if ( ! F_3 ( V_5 ) || ( V_3 != V_2 ) )
return 0 ;
F_4 ( V_9 , V_2 ) ;
V_6 = F_5 ( V_5 -> V_10 ,
! F_6 ( V_9 , V_2 ) ,
V_11 ) ;
return V_6 == 0 ? - V_12 : V_6 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_1 ( V_2 ) ;
if ( ( V_6 == - V_12 ) || ( V_2 -> V_13 & V_14 ) ) {
F_8 ( V_9 | V_14 , V_2 ) ;
F_9 ( V_2 , V_15 ) ;
}
}
static int F_10 ( struct V_16 * V_17 , unsigned int V_18 )
{
struct V_1 * V_2 = V_17 -> V_19 ;
int V_6 ;
V_6 = F_11 ( & V_2 -> V_4 -> V_20 -> V_21 ) ;
return V_6 > 0 ? 0 : V_6 ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_19 ;
F_7 ( V_2 ) ;
F_13 ( & V_2 -> V_4 -> V_20 -> V_21 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 , int V_22 )
{
struct V_23 * V_24 , * V_25 ;
if ( ! V_2 || ! V_2 -> V_26 )
return;
V_24 = F_14 ( V_2 -> V_26 ) ;
V_25 = F_15 ( V_2 -> V_26 ) ;
if ( V_24 && V_25 ) {
V_24 -> V_27 . V_28 = V_25 -> V_27 . V_28 ;
V_24 -> V_27 . V_29 = V_25 -> V_27 . V_29 ;
F_16 ( V_24 , V_22 ) ;
F_16 ( V_25 , V_22 ) ;
F_17 ( V_2 -> V_4 -> V_7 . V_8 ,
V_2 -> V_26 ) ;
}
}
static void F_18 ( void * V_30 )
{
F_7 ( (struct V_1 * ) V_30 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_31 * V_32 , * V_33 ;
struct V_23 * V_24 , * V_25 ;
int V_6 ;
V_32 = & V_2 -> V_32 ;
V_33 = & V_2 -> V_33 ;
V_24 = F_20 ( V_2 -> V_26 ) ;
V_6 = F_21 ( V_2 , V_24 , V_32 , & V_32 -> V_34 ) ;
if ( V_6 )
return V_6 ;
V_25 = F_22 ( V_2 -> V_26 ) ;
V_6 = F_21 ( V_2 , V_25 , V_33 , & V_33 -> V_34 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_27 . V_28 = V_24 -> V_27 . V_28 ;
return 0 ;
}
static void F_23 ( void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_4 * V_5 ;
unsigned long V_35 ;
int V_6 ;
bool V_36 = false ;
if ( F_24 ( ! V_2 , L_1 ) )
return;
V_5 = V_2 -> V_4 ;
F_25 ( & V_5 -> V_37 , V_35 ) ;
F_26 ( V_38 , & V_5 -> V_13 ) ;
if ( V_5 -> V_7 . V_2 != V_2 ) {
F_27 ( L_2 ,
V_5 -> V_7 . V_2 , V_2 ) ;
V_2 -> V_13 |= V_39 ;
V_5 -> V_7 . V_2 = V_2 ;
}
V_36 = V_2 -> V_13 & V_9 ;
if ( V_36 ) {
V_2 -> V_13 &= ~ V_9 ;
V_2 -> V_13 |= V_14 ;
F_28 ( & V_5 -> V_10 ) ;
goto V_40;
}
V_6 = F_19 ( V_2 ) ;
if ( V_6 ) {
F_29 ( L_3 ) ;
goto V_40;
}
F_30 ( V_5 , & V_2 -> V_32 ) ;
F_31 ( V_5 , & V_2 -> V_32 . V_34 , V_41 ) ;
F_32 ( V_5 , & V_2 -> V_33 . V_34 , V_41 ) ;
if ( V_2 -> V_13 & V_39 ) {
F_33 ( V_5 , V_41 , false ) ;
F_34 ( V_5 , V_41 , false ) ;
F_35 ( V_5 , false ) ;
F_36 ( V_5 , true ) ;
if ( F_37 ( V_2 ) ) {
F_29 ( L_4 ) ;
goto V_40;
}
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
}
F_48 ( V_2 ) ;
V_2 -> V_13 &= ~ V_39 ;
F_49 ( V_5 , true ) ;
F_50 ( & V_5 -> V_37 , V_35 ) ;
return;
V_40:
V_2 -> V_13 &= ~ V_39 ;
F_50 ( & V_5 -> V_37 , V_35 ) ;
}
static int F_51 ( struct V_16 * V_42 ,
const struct V_43 * V_44 ,
unsigned int * V_45 , unsigned int * V_46 ,
unsigned int V_47 [] , void * V_48 [] )
{
struct V_1 * V_2 = F_52 ( V_42 ) ;
struct V_31 * V_49 ;
int V_50 ;
V_49 = F_53 ( V_2 , V_42 -> type ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
if ( ! V_49 -> V_44 )
return - V_51 ;
* V_46 = V_49 -> V_44 -> V_46 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_44 -> V_46 ; V_50 ++ ) {
V_47 [ V_50 ] = V_49 -> V_52 [ V_50 ] ;
V_48 [ V_50 ] = V_2 -> V_4 -> V_53 ;
}
return 0 ;
}
static int F_56 ( struct V_23 * V_54 )
{
struct V_1 * V_2 = F_52 ( V_54 -> V_16 ) ;
struct V_31 * V_49 ;
int V_50 ;
V_49 = F_53 ( V_2 , V_54 -> V_16 -> type ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
if ( ! F_57 ( V_54 -> V_16 -> type ) ) {
for ( V_50 = 0 ; V_50 < V_49 -> V_44 -> V_46 ; V_50 ++ )
F_58 ( V_54 , V_50 , V_49 -> V_52 [ V_50 ] ) ;
}
return 0 ;
}
static void F_59 ( struct V_23 * V_54 )
{
struct V_1 * V_2 = F_52 ( V_54 -> V_16 ) ;
F_27 ( L_5 , V_2 , V_2 -> V_13 ) ;
if ( V_2 -> V_26 )
F_60 ( V_2 -> V_26 , V_54 ) ;
}
static int F_61 ( struct V_55 * V_55 , void * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_63 ( V_58 -> V_59 , V_5 -> V_20 -> V_60 , sizeof( V_58 -> V_59 ) ) ;
F_63 ( V_58 -> V_61 , V_5 -> V_20 -> V_60 , sizeof( V_58 -> V_61 ) ) ;
F_63 ( V_58 -> V_62 , L_6 , sizeof( V_58 -> V_62 ) ) ;
V_58 -> V_63 = V_64 | V_65 |
V_66 | V_67 ;
V_58 -> V_68 = V_58 -> V_63 | V_69 ;
return 0 ;
}
static int F_64 ( struct V_55 * V_55 , void * V_30 ,
struct V_70 * V_71 )
{
return F_65 ( V_71 ) ;
}
static int F_66 ( struct V_55 * V_55 , void * V_56 ,
struct V_43 * V_71 )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
return F_67 ( V_2 , V_71 ) ;
}
static int F_68 ( struct V_55 * V_55 , void * V_56 ,
struct V_43 * V_71 )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
return F_69 ( V_2 , V_71 ) ;
}
static int F_70 ( struct V_55 * V_55 , void * V_56 ,
struct V_43 * V_71 )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
struct V_16 * V_42 ;
struct V_31 * V_49 ;
struct V_72 * V_73 ;
int V_50 , V_6 = 0 ;
V_6 = F_68 ( V_55 , V_56 , V_71 ) ;
if ( V_6 )
return V_6 ;
V_42 = F_71 ( V_2 -> V_26 , V_71 -> type ) ;
if ( F_72 ( V_42 ) ) {
F_29 ( L_7 , V_71 -> type ) ;
return - V_74 ;
}
if ( F_57 ( V_71 -> type ) )
V_49 = & V_2 -> V_32 ;
else
V_49 = & V_2 -> V_33 ;
V_73 = & V_71 -> V_44 . V_75 ;
V_49 -> V_44 = F_73 ( & V_73 -> V_76 , NULL , 0 ) ;
V_49 -> V_77 = V_73 -> V_77 ;
if ( ! V_49 -> V_44 )
return - V_51 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_44 -> V_46 ; V_50 ++ )
V_49 -> V_52 [ V_50 ] = V_73 -> V_78 [ V_50 ] . V_79 ;
F_74 ( V_49 , V_73 -> V_80 , V_73 -> V_81 ) ;
if ( V_71 -> type == V_82 )
F_4 ( V_39 | V_83 , V_2 ) ;
else
F_4 ( V_39 | V_84 , V_2 ) ;
F_27 ( L_8 , V_49 -> V_85 , V_49 -> V_86 ) ;
return 0 ;
}
static int F_75 ( struct V_55 * V_55 , void * V_56 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
struct V_31 * V_49 ;
T_1 V_89 ;
V_89 = ( V_88 -> type == V_90 ) ?
V_5 -> V_91 -> V_92 : V_5 -> V_91 -> V_93 ;
if ( V_88 -> V_18 > V_89 ) {
return - V_51 ;
} else if ( V_88 -> V_18 == 0 ) {
if ( V_88 -> type == V_90 )
F_8 ( V_84 , V_2 ) ;
else
F_8 ( V_83 , V_2 ) ;
}
V_49 = F_53 ( V_2 , V_88 -> type ) ;
return F_76 ( V_55 , V_2 -> V_26 , V_88 ) ;
}
static int F_77 ( struct V_55 * V_55 , void * V_56 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
return F_78 ( V_55 , V_2 -> V_26 , V_95 ) ;
}
static int F_79 ( struct V_55 * V_55 , void * V_56 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
return F_80 ( V_55 , V_2 -> V_26 , V_97 ) ;
}
static int F_81 ( struct V_55 * V_55 , void * V_56 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
return F_82 ( V_55 , V_2 -> V_26 , V_97 ) ;
}
static int F_83 ( struct V_55 * V_55 , void * V_56 ,
struct V_96 * V_97 )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
return F_84 ( V_55 , V_2 -> V_26 , V_97 ) ;
}
static int F_85 ( struct V_55 * V_55 , void * V_56 ,
enum V_98 type )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
if ( F_57 ( type ) ) {
if ( ! F_6 ( V_84 , V_2 ) )
return - V_51 ;
} else if ( ! F_6 ( V_83 , V_2 ) ) {
return - V_51 ;
}
return F_86 ( V_55 , V_2 -> V_26 , type ) ;
}
static int F_87 ( struct V_55 * V_55 , void * V_56 ,
enum V_98 type )
{
struct V_1 * V_2 = F_62 ( V_56 ) ;
return F_88 ( V_55 , V_2 -> V_26 , type ) ;
}
static int F_89 ( struct V_99 * V_100 , struct V_99 * V_101 )
{
if ( V_100 -> V_102 < V_101 -> V_102 || V_100 -> V_103 < V_101 -> V_103 )
return 0 ;
if ( V_100 -> V_102 + V_100 -> V_80 > V_101 -> V_102 + V_101 -> V_80 )
return 0 ;
if ( V_100 -> V_103 + V_100 -> V_81 > V_101 -> V_103 + V_101 -> V_81 )
return 0 ;
return 1 ;
}
static int F_90 ( struct V_55 * V_55 , void * V_56 ,
struct V_104 * V_105 )
{
struct V_31 * V_49 ;
struct V_1 * V_2 = F_62 ( V_56 ) ;
if ( ( V_105 -> type != V_82 ) &&
( V_105 -> type != V_90 ) )
return - V_51 ;
V_49 = F_53 ( V_2 , V_105 -> type ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
switch ( V_105 -> V_106 ) {
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_105 -> V_111 . V_102 = 0 ;
V_105 -> V_111 . V_103 = 0 ;
V_105 -> V_111 . V_80 = V_49 -> V_85 ;
V_105 -> V_111 . V_81 = V_49 -> V_86 ;
return 0 ;
case V_112 :
case V_113 :
V_105 -> V_111 . V_102 = V_49 -> V_114 . V_102 ;
V_105 -> V_111 . V_103 = V_49 -> V_114 . V_103 ;
V_105 -> V_111 . V_80 = V_49 -> V_114 . V_80 ;
V_105 -> V_111 . V_81 = V_49 -> V_114 . V_81 ;
return 0 ;
}
return - V_51 ;
}
static int F_91 ( struct V_55 * V_55 , void * V_56 ,
struct V_104 * V_105 )
{
struct V_31 * V_49 ;
struct V_1 * V_2 = F_62 ( V_56 ) ;
struct V_115 V_116 ;
struct V_117 * V_91 = V_2 -> V_4 -> V_91 ;
int V_6 ;
V_116 . type = V_105 -> type ;
V_116 . V_118 = V_105 -> V_111 ;
if ( ( V_105 -> type != V_82 ) &&
( V_105 -> type != V_90 ) )
return - V_51 ;
V_6 = F_92 ( V_2 , & V_116 ) ;
if ( V_6 )
return V_6 ;
if ( V_105 -> V_35 & V_119 &&
! F_89 ( & V_116 . V_118 , & V_105 -> V_111 ) )
return - V_120 ;
if ( V_105 -> V_35 & V_121 &&
! F_89 ( & V_105 -> V_111 , & V_116 . V_118 ) )
return - V_120 ;
V_105 -> V_111 = V_116 . V_118 ;
switch ( V_105 -> V_106 ) {
case V_108 :
case V_107 :
case V_112 :
V_49 = & V_2 -> V_32 ;
break;
case V_109 :
case V_113 :
case V_110 :
V_49 = & V_2 -> V_33 ;
break;
default:
return - V_51 ;
}
if ( F_6 ( V_83 | V_84 , V_2 ) ) {
if ( V_105 -> type == V_90 ) {
V_6 = F_93 ( V_91 , V_116 . V_118 . V_80 ,
V_116 . V_118 . V_81 , V_2 -> V_33 . V_114 . V_80 ,
V_2 -> V_33 . V_114 . V_81 ,
V_2 -> V_122 . V_123 -> V_124 , V_2 -> V_125 ) ;
} else {
V_6 = F_93 ( V_91 ,
V_2 -> V_32 . V_114 . V_80 ,
V_2 -> V_32 . V_114 . V_81 , V_116 . V_118 . V_80 ,
V_116 . V_118 . V_81 , V_2 -> V_122 . V_123 -> V_124 ,
V_2 -> V_125 ) ;
}
if ( V_6 ) {
F_29 ( L_9 ) ;
return - V_51 ;
}
}
V_49 -> V_114 = V_116 . V_118 ;
F_4 ( V_39 , V_2 ) ;
return 0 ;
}
static int F_94 ( void * V_30 , struct V_16 * V_126 ,
struct V_16 * V_127 )
{
struct V_1 * V_2 = V_30 ;
int V_6 ;
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
V_126 -> type = V_90 ;
V_126 -> V_128 = V_129 | V_130 | V_131 ;
V_126 -> V_19 = V_2 ;
V_126 -> V_132 = & V_133 ;
V_126 -> V_134 = & V_135 ;
V_126 -> V_136 = sizeof( struct V_137 ) ;
V_126 -> V_138 = V_139 ;
V_6 = F_95 ( V_126 ) ;
if ( V_6 )
return V_6 ;
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
V_127 -> type = V_82 ;
V_127 -> V_128 = V_129 | V_130 | V_131 ;
V_127 -> V_19 = V_2 ;
V_127 -> V_132 = & V_133 ;
V_127 -> V_134 = & V_135 ;
V_127 -> V_136 = sizeof( struct V_137 ) ;
V_127 -> V_138 = V_139 ;
return F_95 ( V_127 ) ;
}
static int F_96 ( struct V_55 * V_55 )
{
struct V_4 * V_5 = F_97 ( V_55 ) ;
struct V_1 * V_2 = NULL ;
int V_6 ;
F_27 ( L_10 , F_98 ( V_140 ) , V_5 -> V_13 ) ;
if ( F_99 ( & V_5 -> V_141 ) )
return - V_142 ;
V_2 = F_100 ( sizeof( * V_2 ) , V_143 ) ;
if ( ! V_2 ) {
V_6 = - V_144 ;
goto V_145;
}
F_101 ( & V_2 -> V_56 , V_5 -> V_7 . V_146 ) ;
V_6 = F_102 ( V_2 ) ;
if ( V_6 )
goto V_147;
V_2 -> V_56 . V_148 = & V_2 -> V_148 ;
V_55 -> V_149 = & V_2 -> V_56 ;
F_103 ( & V_2 -> V_56 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_32 . V_44 = F_104 ( 0 ) ;
V_2 -> V_33 . V_44 = F_104 ( 0 ) ;
V_2 -> V_13 = V_150 ;
V_2 -> V_35 = 0 ;
V_2 -> V_151 = V_152 ;
V_2 -> V_125 = V_152 ;
V_2 -> V_26 = F_105 ( V_5 -> V_7 . V_8 , V_2 , F_94 ) ;
if ( F_54 ( V_2 -> V_26 ) ) {
F_29 ( L_11 ) ;
V_6 = F_55 ( V_2 -> V_26 ) ;
goto V_153;
}
if ( V_5 -> V_7 . V_154 ++ == 0 )
F_26 ( V_155 , & V_5 -> V_13 ) ;
F_27 ( L_12 , V_2 ) ;
F_106 ( & V_5 -> V_141 ) ;
return 0 ;
V_153:
F_107 ( V_2 ) ;
V_147:
F_108 ( & V_2 -> V_56 ) ;
F_109 ( & V_2 -> V_56 ) ;
F_110 ( V_2 ) ;
V_145:
F_106 ( & V_5 -> V_141 ) ;
return V_6 ;
}
static int F_111 ( struct V_55 * V_55 )
{
struct V_1 * V_2 = F_62 ( V_55 -> V_149 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_27 ( L_13 ,
F_98 ( V_140 ) , V_5 -> V_13 , V_5 -> V_7 . V_154 ) ;
F_112 ( & V_5 -> V_141 ) ;
F_113 ( V_2 -> V_26 ) ;
F_107 ( V_2 ) ;
F_108 ( & V_2 -> V_56 ) ;
F_109 ( & V_2 -> V_56 ) ;
if ( -- V_5 -> V_7 . V_154 <= 0 )
F_114 ( V_155 , & V_5 -> V_13 ) ;
F_110 ( V_2 ) ;
F_106 ( & V_5 -> V_141 ) ;
return 0 ;
}
static unsigned int F_115 ( struct V_55 * V_55 ,
struct V_156 * V_157 )
{
struct V_1 * V_2 = F_62 ( V_55 -> V_149 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_99 ( & V_5 -> V_141 ) )
return - V_142 ;
V_6 = F_116 ( V_55 , V_2 -> V_26 , V_157 ) ;
F_106 ( & V_5 -> V_141 ) ;
return V_6 ;
}
static int F_117 ( struct V_55 * V_55 , struct V_158 * V_159 )
{
struct V_1 * V_2 = F_62 ( V_55 -> V_149 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_99 ( & V_5 -> V_141 ) )
return - V_142 ;
V_6 = F_118 ( V_55 , V_2 -> V_26 , V_159 ) ;
F_106 ( & V_5 -> V_141 ) ;
return V_6 ;
}
int F_119 ( struct V_4 * V_5 )
{
struct V_160 * V_20 ;
int V_6 ;
if ( ! V_5 )
return - V_161 ;
V_20 = V_5 -> V_20 ;
V_5 -> V_162 . V_163 = & V_164 ;
V_5 -> V_162 . V_165 = & V_166 ;
V_5 -> V_162 . V_167 = V_168 ;
V_5 -> V_162 . V_141 = & V_5 -> V_141 ;
V_5 -> V_162 . V_169 = V_170 ;
V_5 -> V_162 . V_171 = & V_5 -> V_171 ;
snprintf ( V_5 -> V_162 . V_60 , sizeof( V_5 -> V_162 . V_60 ) , L_14 ,
V_172 , V_5 -> V_173 ) ;
F_120 ( & V_5 -> V_162 , V_5 ) ;
V_5 -> V_7 . V_146 = & V_5 -> V_162 ;
V_5 -> V_7 . V_8 = F_121 ( & V_174 ) ;
if ( F_54 ( V_5 -> V_7 . V_8 ) ) {
F_122 ( & V_20 -> V_21 , L_15 ) ;
V_6 = F_55 ( V_5 -> V_7 . V_8 ) ;
goto V_175;
}
V_6 = F_123 ( & V_5 -> V_162 , V_176 , - 1 ) ;
if ( V_6 ) {
F_122 ( & V_20 -> V_21 ,
L_16 , V_177 ) ;
goto V_178;
}
F_27 ( L_17 , V_5 -> V_162 . V_179 ) ;
return 0 ;
V_178:
F_124 ( V_5 -> V_7 . V_8 ) ;
V_175:
F_125 ( V_5 -> V_7 . V_146 ) ;
return V_6 ;
}
void F_126 ( struct V_4 * V_5 )
{
if ( V_5 )
F_124 ( V_5 -> V_7 . V_8 ) ;
}
