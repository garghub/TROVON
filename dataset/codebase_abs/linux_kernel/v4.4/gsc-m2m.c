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
static void F_12 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_19 ;
F_7 ( V_2 ) ;
F_13 ( & V_2 -> V_4 -> V_20 -> V_21 ) ;
}
void F_9 ( struct V_1 * V_2 , int V_22 )
{
struct V_23 * V_24 , * V_25 ;
if ( ! V_2 || ! V_2 -> V_26 )
return;
V_24 = F_14 ( V_2 -> V_26 ) ;
V_25 = F_15 ( V_2 -> V_26 ) ;
if ( V_24 && V_25 ) {
V_25 -> V_27 = V_24 -> V_27 ;
V_25 -> V_28 = V_24 -> V_28 ;
V_25 -> V_29 &= ~ V_30 ;
V_25 -> V_29 |=
V_24 -> V_29
& V_30 ;
F_16 ( V_24 , V_22 ) ;
F_16 ( V_25 , V_22 ) ;
F_17 ( V_2 -> V_4 -> V_7 . V_8 ,
V_2 -> V_26 ) ;
}
}
static void F_18 ( void * V_31 )
{
F_7 ( (struct V_1 * ) V_31 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_32 * V_33 , * V_34 ;
struct V_23 * V_24 , * V_25 ;
int V_6 ;
V_33 = & V_2 -> V_33 ;
V_34 = & V_2 -> V_34 ;
V_24 = F_20 ( V_2 -> V_26 ) ;
V_6 = F_21 ( V_2 , & V_24 -> V_35 , V_33 , & V_33 -> V_36 ) ;
if ( V_6 )
return V_6 ;
V_25 = F_22 ( V_2 -> V_26 ) ;
V_6 = F_21 ( V_2 , & V_25 -> V_35 , V_34 , & V_34 -> V_36 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_27 = V_24 -> V_27 ;
return 0 ;
}
static void F_23 ( void * V_31 )
{
struct V_1 * V_2 = V_31 ;
struct V_4 * V_5 ;
unsigned long V_29 ;
int V_6 ;
bool V_37 = false ;
if ( F_24 ( ! V_2 , L_1 ) )
return;
V_5 = V_2 -> V_4 ;
F_25 ( & V_5 -> V_38 , V_29 ) ;
F_26 ( V_39 , & V_5 -> V_13 ) ;
if ( V_5 -> V_7 . V_2 != V_2 ) {
F_27 ( L_2 ,
V_5 -> V_7 . V_2 , V_2 ) ;
V_2 -> V_13 |= V_40 ;
V_5 -> V_7 . V_2 = V_2 ;
}
V_37 = V_2 -> V_13 & V_9 ;
if ( V_37 ) {
V_2 -> V_13 &= ~ V_9 ;
V_2 -> V_13 |= V_14 ;
F_28 ( & V_5 -> V_10 ) ;
goto V_41;
}
V_6 = F_19 ( V_2 ) ;
if ( V_6 ) {
F_29 ( L_3 ) ;
goto V_41;
}
F_30 ( V_5 , & V_2 -> V_33 ) ;
F_31 ( V_5 , & V_2 -> V_33 . V_36 , V_42 ) ;
F_32 ( V_5 , & V_2 -> V_34 . V_36 , V_42 ) ;
if ( V_2 -> V_13 & V_40 ) {
F_33 ( V_5 , V_42 , false ) ;
F_34 ( V_5 , V_42 , false ) ;
F_35 ( V_5 , false ) ;
F_36 ( V_5 , true ) ;
if ( F_37 ( V_2 ) ) {
F_29 ( L_4 ) ;
goto V_41;
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
V_2 -> V_13 &= ~ V_40 ;
F_49 ( V_5 , true ) ;
F_50 ( & V_5 -> V_38 , V_29 ) ;
return;
V_41:
V_2 -> V_13 &= ~ V_40 ;
F_50 ( & V_5 -> V_38 , V_29 ) ;
}
static int F_51 ( struct V_16 * V_43 ,
const void * V_44 ,
unsigned int * V_45 , unsigned int * V_46 ,
unsigned int V_47 [] , void * V_48 [] )
{
struct V_1 * V_2 = F_52 ( V_43 ) ;
struct V_32 * V_49 ;
int V_50 ;
V_49 = F_53 ( V_2 , V_43 -> type ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
if ( ! V_49 -> V_51 )
return - V_52 ;
* V_46 = V_49 -> V_51 -> V_46 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_51 -> V_46 ; V_50 ++ ) {
V_47 [ V_50 ] = V_49 -> V_53 [ V_50 ] ;
V_48 [ V_50 ] = V_2 -> V_4 -> V_54 ;
}
return 0 ;
}
static int F_56 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_52 ( V_56 -> V_16 ) ;
struct V_32 * V_49 ;
int V_50 ;
V_49 = F_53 ( V_2 , V_56 -> V_16 -> type ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
if ( ! F_57 ( V_56 -> V_16 -> type ) ) {
for ( V_50 = 0 ; V_50 < V_49 -> V_51 -> V_46 ; V_50 ++ )
F_58 ( V_56 , V_50 , V_49 -> V_53 [ V_50 ] ) ;
}
return 0 ;
}
static void F_59 ( struct V_55 * V_56 )
{
struct V_23 * V_57 = F_60 ( V_56 ) ;
struct V_1 * V_2 = F_52 ( V_56 -> V_16 ) ;
F_27 ( L_5 , V_2 , V_2 -> V_13 ) ;
if ( V_2 -> V_26 )
F_61 ( V_2 -> V_26 , V_57 ) ;
}
static int F_62 ( struct V_58 * V_58 , void * V_59 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_64 ( V_61 -> V_62 , V_5 -> V_20 -> V_63 , sizeof( V_61 -> V_62 ) ) ;
F_64 ( V_61 -> V_64 , V_5 -> V_20 -> V_63 , sizeof( V_61 -> V_64 ) ) ;
F_64 ( V_61 -> V_65 , L_6 , sizeof( V_61 -> V_65 ) ) ;
V_61 -> V_66 = V_67 | V_68 |
V_69 | V_70 ;
V_61 -> V_71 = V_61 -> V_66 | V_72 ;
return 0 ;
}
static int F_65 ( struct V_58 * V_58 , void * V_31 ,
struct V_73 * V_74 )
{
return F_66 ( V_74 ) ;
}
static int F_67 ( struct V_58 * V_58 , void * V_59 ,
struct V_75 * V_74 )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
return F_68 ( V_2 , V_74 ) ;
}
static int F_69 ( struct V_58 * V_58 , void * V_59 ,
struct V_75 * V_74 )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
return F_70 ( V_2 , V_74 ) ;
}
static int F_71 ( struct V_58 * V_58 , void * V_59 ,
struct V_75 * V_74 )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
struct V_16 * V_43 ;
struct V_32 * V_49 ;
struct V_76 * V_77 ;
int V_50 , V_6 = 0 ;
V_6 = F_69 ( V_58 , V_59 , V_74 ) ;
if ( V_6 )
return V_6 ;
V_43 = F_72 ( V_2 -> V_26 , V_74 -> type ) ;
if ( F_73 ( V_43 ) ) {
F_29 ( L_7 , V_74 -> type ) ;
return - V_78 ;
}
if ( F_57 ( V_74 -> type ) )
V_49 = & V_2 -> V_33 ;
else
V_49 = & V_2 -> V_34 ;
V_77 = & V_74 -> V_51 . V_79 ;
V_49 -> V_51 = F_74 ( & V_77 -> V_80 , NULL , 0 ) ;
V_49 -> V_81 = V_77 -> V_81 ;
if ( ! V_49 -> V_51 )
return - V_52 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_51 -> V_46 ; V_50 ++ )
V_49 -> V_53 [ V_50 ] = V_77 -> V_82 [ V_50 ] . V_83 ;
F_75 ( V_49 , V_77 -> V_84 , V_77 -> V_85 ) ;
if ( V_74 -> type == V_86 )
F_4 ( V_40 | V_87 , V_2 ) ;
else
F_4 ( V_40 | V_88 , V_2 ) ;
F_27 ( L_8 , V_49 -> V_89 , V_49 -> V_90 ) ;
return 0 ;
}
static int F_76 ( struct V_58 * V_58 , void * V_59 ,
struct V_91 * V_92 )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
T_1 V_93 ;
V_93 = ( V_92 -> type == V_94 ) ?
V_5 -> V_95 -> V_96 : V_5 -> V_95 -> V_97 ;
if ( V_92 -> V_18 > V_93 ) {
return - V_52 ;
} else if ( V_92 -> V_18 == 0 ) {
if ( V_92 -> type == V_94 )
F_8 ( V_88 , V_2 ) ;
else
F_8 ( V_87 , V_2 ) ;
}
return F_77 ( V_58 , V_2 -> V_26 , V_92 ) ;
}
static int F_78 ( struct V_58 * V_58 , void * V_59 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
return F_79 ( V_58 , V_2 -> V_26 , V_99 ) ;
}
static int F_80 ( struct V_58 * V_58 , void * V_59 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
return F_81 ( V_58 , V_2 -> V_26 , V_101 ) ;
}
static int F_82 ( struct V_58 * V_58 , void * V_59 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
return F_83 ( V_58 , V_2 -> V_26 , V_101 ) ;
}
static int F_84 ( struct V_58 * V_58 , void * V_59 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
return F_85 ( V_58 , V_2 -> V_26 , V_101 ) ;
}
static int F_86 ( struct V_58 * V_58 , void * V_59 ,
enum V_102 type )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
if ( F_57 ( type ) ) {
if ( ! F_6 ( V_88 , V_2 ) )
return - V_52 ;
} else if ( ! F_6 ( V_87 , V_2 ) ) {
return - V_52 ;
}
return F_87 ( V_58 , V_2 -> V_26 , type ) ;
}
static int F_88 ( struct V_58 * V_58 , void * V_59 ,
enum V_102 type )
{
struct V_1 * V_2 = F_63 ( V_59 ) ;
return F_89 ( V_58 , V_2 -> V_26 , type ) ;
}
static int F_90 ( struct V_103 * V_104 , struct V_103 * V_105 )
{
if ( V_104 -> V_106 < V_105 -> V_106 || V_104 -> V_107 < V_105 -> V_107 )
return 0 ;
if ( V_104 -> V_106 + V_104 -> V_84 > V_105 -> V_106 + V_105 -> V_84 )
return 0 ;
if ( V_104 -> V_107 + V_104 -> V_85 > V_105 -> V_107 + V_105 -> V_85 )
return 0 ;
return 1 ;
}
static int F_91 ( struct V_58 * V_58 , void * V_59 ,
struct V_108 * V_109 )
{
struct V_32 * V_49 ;
struct V_1 * V_2 = F_63 ( V_59 ) ;
if ( ( V_109 -> type != V_86 ) &&
( V_109 -> type != V_94 ) )
return - V_52 ;
V_49 = F_53 ( V_2 , V_109 -> type ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
switch ( V_109 -> V_110 ) {
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_109 -> V_115 . V_106 = 0 ;
V_109 -> V_115 . V_107 = 0 ;
V_109 -> V_115 . V_84 = V_49 -> V_89 ;
V_109 -> V_115 . V_85 = V_49 -> V_90 ;
return 0 ;
case V_116 :
case V_117 :
V_109 -> V_115 . V_106 = V_49 -> V_118 . V_106 ;
V_109 -> V_115 . V_107 = V_49 -> V_118 . V_107 ;
V_109 -> V_115 . V_84 = V_49 -> V_118 . V_84 ;
V_109 -> V_115 . V_85 = V_49 -> V_118 . V_85 ;
return 0 ;
}
return - V_52 ;
}
static int F_92 ( struct V_58 * V_58 , void * V_59 ,
struct V_108 * V_109 )
{
struct V_32 * V_49 ;
struct V_1 * V_2 = F_63 ( V_59 ) ;
struct V_119 V_120 ;
struct V_121 * V_95 = V_2 -> V_4 -> V_95 ;
int V_6 ;
V_120 . type = V_109 -> type ;
V_120 . V_122 = V_109 -> V_115 ;
if ( ( V_109 -> type != V_86 ) &&
( V_109 -> type != V_94 ) )
return - V_52 ;
V_6 = F_93 ( V_2 , & V_120 ) ;
if ( V_6 )
return V_6 ;
if ( V_109 -> V_29 & V_123 &&
! F_90 ( & V_120 . V_122 , & V_109 -> V_115 ) )
return - V_124 ;
if ( V_109 -> V_29 & V_125 &&
! F_90 ( & V_109 -> V_115 , & V_120 . V_122 ) )
return - V_124 ;
V_109 -> V_115 = V_120 . V_122 ;
switch ( V_109 -> V_110 ) {
case V_112 :
case V_111 :
case V_116 :
V_49 = & V_2 -> V_33 ;
break;
case V_113 :
case V_117 :
case V_114 :
V_49 = & V_2 -> V_34 ;
break;
default:
return - V_52 ;
}
if ( F_6 ( V_87 | V_88 , V_2 ) ) {
if ( V_109 -> type == V_94 ) {
V_6 = F_94 ( V_95 , V_120 . V_122 . V_84 ,
V_120 . V_122 . V_85 , V_2 -> V_34 . V_118 . V_84 ,
V_2 -> V_34 . V_118 . V_85 ,
V_2 -> V_126 . V_127 -> V_128 , V_2 -> V_129 ) ;
} else {
V_6 = F_94 ( V_95 ,
V_2 -> V_33 . V_118 . V_84 ,
V_2 -> V_33 . V_118 . V_85 , V_120 . V_122 . V_84 ,
V_120 . V_122 . V_85 , V_2 -> V_126 . V_127 -> V_128 ,
V_2 -> V_129 ) ;
}
if ( V_6 ) {
F_29 ( L_9 ) ;
return - V_52 ;
}
}
V_49 -> V_118 = V_120 . V_122 ;
F_4 ( V_40 , V_2 ) ;
return 0 ;
}
static int F_95 ( void * V_31 , struct V_16 * V_130 ,
struct V_16 * V_131 )
{
struct V_1 * V_2 = V_31 ;
int V_6 ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> type = V_94 ;
V_130 -> V_132 = V_133 | V_134 | V_135 ;
V_130 -> V_19 = V_2 ;
V_130 -> V_136 = & V_137 ;
V_130 -> V_138 = & V_139 ;
V_130 -> V_140 = sizeof( struct V_141 ) ;
V_130 -> V_142 = V_143 ;
V_130 -> V_144 = & V_2 -> V_4 -> V_144 ;
V_6 = F_96 ( V_130 ) ;
if ( V_6 )
return V_6 ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> type = V_86 ;
V_131 -> V_132 = V_133 | V_134 | V_135 ;
V_131 -> V_19 = V_2 ;
V_131 -> V_136 = & V_137 ;
V_131 -> V_138 = & V_139 ;
V_131 -> V_140 = sizeof( struct V_141 ) ;
V_131 -> V_142 = V_143 ;
V_131 -> V_144 = & V_2 -> V_4 -> V_144 ;
return F_96 ( V_131 ) ;
}
static int F_97 ( struct V_58 * V_58 )
{
struct V_4 * V_5 = F_98 ( V_58 ) ;
struct V_1 * V_2 = NULL ;
int V_6 ;
F_27 ( L_10 , F_99 ( V_145 ) , V_5 -> V_13 ) ;
if ( F_100 ( & V_5 -> V_144 ) )
return - V_146 ;
V_2 = F_101 ( sizeof( * V_2 ) , V_147 ) ;
if ( ! V_2 ) {
V_6 = - V_148 ;
goto V_149;
}
F_102 ( & V_2 -> V_59 , V_5 -> V_7 . V_150 ) ;
V_6 = F_103 ( V_2 ) ;
if ( V_6 )
goto V_151;
V_2 -> V_59 . V_152 = & V_2 -> V_152 ;
V_58 -> V_153 = & V_2 -> V_59 ;
F_104 ( & V_2 -> V_59 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_33 . V_51 = F_105 ( 0 ) ;
V_2 -> V_34 . V_51 = F_105 ( 0 ) ;
V_2 -> V_13 = V_154 ;
V_2 -> V_29 = 0 ;
V_2 -> V_155 = V_156 ;
V_2 -> V_129 = V_156 ;
V_2 -> V_26 = F_106 ( V_5 -> V_7 . V_8 , V_2 , F_95 ) ;
if ( F_54 ( V_2 -> V_26 ) ) {
F_29 ( L_11 ) ;
V_6 = F_55 ( V_2 -> V_26 ) ;
goto V_157;
}
if ( V_5 -> V_7 . V_158 ++ == 0 )
F_26 ( V_159 , & V_5 -> V_13 ) ;
F_27 ( L_12 , V_2 ) ;
F_107 ( & V_5 -> V_144 ) ;
return 0 ;
V_157:
F_108 ( V_2 ) ;
V_151:
F_109 ( & V_2 -> V_59 ) ;
F_110 ( & V_2 -> V_59 ) ;
F_111 ( V_2 ) ;
V_149:
F_107 ( & V_5 -> V_144 ) ;
return V_6 ;
}
static int F_112 ( struct V_58 * V_58 )
{
struct V_1 * V_2 = F_63 ( V_58 -> V_153 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_27 ( L_13 ,
F_99 ( V_145 ) , V_5 -> V_13 , V_5 -> V_7 . V_158 ) ;
F_113 ( & V_5 -> V_144 ) ;
F_114 ( V_2 -> V_26 ) ;
F_108 ( V_2 ) ;
F_109 ( & V_2 -> V_59 ) ;
F_110 ( & V_2 -> V_59 ) ;
if ( -- V_5 -> V_7 . V_158 <= 0 )
F_115 ( V_159 , & V_5 -> V_13 ) ;
F_111 ( V_2 ) ;
F_107 ( & V_5 -> V_144 ) ;
return 0 ;
}
static unsigned int F_116 ( struct V_58 * V_58 ,
struct V_160 * V_161 )
{
struct V_1 * V_2 = F_63 ( V_58 -> V_153 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_100 ( & V_5 -> V_144 ) )
return - V_146 ;
V_6 = F_117 ( V_58 , V_2 -> V_26 , V_161 ) ;
F_107 ( & V_5 -> V_144 ) ;
return V_6 ;
}
static int F_118 ( struct V_58 * V_58 , struct V_162 * V_163 )
{
struct V_1 * V_2 = F_63 ( V_58 -> V_153 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_100 ( & V_5 -> V_144 ) )
return - V_146 ;
V_6 = F_119 ( V_58 , V_2 -> V_26 , V_163 ) ;
F_107 ( & V_5 -> V_144 ) ;
return V_6 ;
}
int F_120 ( struct V_4 * V_5 )
{
struct V_164 * V_20 ;
int V_6 ;
if ( ! V_5 )
return - V_165 ;
V_20 = V_5 -> V_20 ;
V_5 -> V_166 . V_167 = & V_168 ;
V_5 -> V_166 . V_169 = & V_170 ;
V_5 -> V_166 . V_171 = V_172 ;
V_5 -> V_166 . V_144 = & V_5 -> V_144 ;
V_5 -> V_166 . V_173 = V_174 ;
V_5 -> V_166 . V_175 = & V_5 -> V_175 ;
snprintf ( V_5 -> V_166 . V_63 , sizeof( V_5 -> V_166 . V_63 ) , L_14 ,
V_176 , V_5 -> V_177 ) ;
F_121 ( & V_5 -> V_166 , V_5 ) ;
V_5 -> V_7 . V_150 = & V_5 -> V_166 ;
V_5 -> V_7 . V_8 = F_122 ( & V_178 ) ;
if ( F_54 ( V_5 -> V_7 . V_8 ) ) {
F_123 ( & V_20 -> V_21 , L_15 ) ;
V_6 = F_55 ( V_5 -> V_7 . V_8 ) ;
goto V_179;
}
V_6 = F_124 ( & V_5 -> V_166 , V_180 , - 1 ) ;
if ( V_6 ) {
F_123 ( & V_20 -> V_21 ,
L_16 , V_181 ) ;
goto V_182;
}
F_27 ( L_17 , V_5 -> V_166 . V_183 ) ;
return 0 ;
V_182:
F_125 ( V_5 -> V_7 . V_8 ) ;
V_179:
F_126 ( V_5 -> V_7 . V_150 ) ;
return V_6 ;
}
void F_127 ( struct V_4 * V_5 )
{
if ( V_5 )
F_125 ( V_5 -> V_7 . V_8 ) ;
}
