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
V_25 -> V_27 . V_28 = V_24 -> V_27 . V_28 ;
V_25 -> V_27 . V_29 = V_24 -> V_27 . V_29 ;
V_25 -> V_27 . V_30 &= ~ V_31 ;
V_25 -> V_27 . V_30 |=
V_24 -> V_27 . V_30
& V_31 ;
F_16 ( V_24 , V_22 ) ;
F_16 ( V_25 , V_22 ) ;
F_17 ( V_2 -> V_4 -> V_7 . V_8 ,
V_2 -> V_26 ) ;
}
}
static void F_18 ( void * V_32 )
{
F_7 ( (struct V_1 * ) V_32 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_33 * V_34 , * V_35 ;
struct V_23 * V_24 , * V_25 ;
int V_6 ;
V_34 = & V_2 -> V_34 ;
V_35 = & V_2 -> V_35 ;
V_24 = F_20 ( V_2 -> V_26 ) ;
V_6 = F_21 ( V_2 , V_24 , V_34 , & V_34 -> V_36 ) ;
if ( V_6 )
return V_6 ;
V_25 = F_22 ( V_2 -> V_26 ) ;
V_6 = F_21 ( V_2 , V_25 , V_35 , & V_35 -> V_36 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_27 . V_28 = V_24 -> V_27 . V_28 ;
return 0 ;
}
static void F_23 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_4 * V_5 ;
unsigned long V_30 ;
int V_6 ;
bool V_37 = false ;
if ( F_24 ( ! V_2 , L_1 ) )
return;
V_5 = V_2 -> V_4 ;
F_25 ( & V_5 -> V_38 , V_30 ) ;
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
F_30 ( V_5 , & V_2 -> V_34 ) ;
F_31 ( V_5 , & V_2 -> V_34 . V_36 , V_42 ) ;
F_32 ( V_5 , & V_2 -> V_35 . V_36 , V_42 ) ;
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
F_50 ( & V_5 -> V_38 , V_30 ) ;
return;
V_41:
V_2 -> V_13 &= ~ V_40 ;
F_50 ( & V_5 -> V_38 , V_30 ) ;
}
static int F_51 ( struct V_16 * V_43 ,
const struct V_44 * V_45 ,
unsigned int * V_46 , unsigned int * V_47 ,
unsigned int V_48 [] , void * V_49 [] )
{
struct V_1 * V_2 = F_52 ( V_43 ) ;
struct V_33 * V_50 ;
int V_51 ;
V_50 = F_53 ( V_2 , V_43 -> type ) ;
if ( F_54 ( V_50 ) )
return F_55 ( V_50 ) ;
if ( ! V_50 -> V_45 )
return - V_52 ;
* V_47 = V_50 -> V_45 -> V_47 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_45 -> V_47 ; V_51 ++ ) {
V_48 [ V_51 ] = V_50 -> V_53 [ V_51 ] ;
V_49 [ V_51 ] = V_2 -> V_4 -> V_54 ;
}
return 0 ;
}
static int F_56 ( struct V_23 * V_55 )
{
struct V_1 * V_2 = F_52 ( V_55 -> V_16 ) ;
struct V_33 * V_50 ;
int V_51 ;
V_50 = F_53 ( V_2 , V_55 -> V_16 -> type ) ;
if ( F_54 ( V_50 ) )
return F_55 ( V_50 ) ;
if ( ! F_57 ( V_55 -> V_16 -> type ) ) {
for ( V_51 = 0 ; V_51 < V_50 -> V_45 -> V_47 ; V_51 ++ )
F_58 ( V_55 , V_51 , V_50 -> V_53 [ V_51 ] ) ;
}
return 0 ;
}
static void F_59 ( struct V_23 * V_55 )
{
struct V_1 * V_2 = F_52 ( V_55 -> V_16 ) ;
F_27 ( L_5 , V_2 , V_2 -> V_13 ) ;
if ( V_2 -> V_26 )
F_60 ( V_2 -> V_26 , V_55 ) ;
}
static int F_61 ( struct V_56 * V_56 , void * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_63 ( V_59 -> V_60 , V_5 -> V_20 -> V_61 , sizeof( V_59 -> V_60 ) ) ;
F_63 ( V_59 -> V_62 , V_5 -> V_20 -> V_61 , sizeof( V_59 -> V_62 ) ) ;
F_63 ( V_59 -> V_63 , L_6 , sizeof( V_59 -> V_63 ) ) ;
V_59 -> V_64 = V_65 | V_66 |
V_67 | V_68 ;
V_59 -> V_69 = V_59 -> V_64 | V_70 ;
return 0 ;
}
static int F_64 ( struct V_56 * V_56 , void * V_32 ,
struct V_71 * V_72 )
{
return F_65 ( V_72 ) ;
}
static int F_66 ( struct V_56 * V_56 , void * V_57 ,
struct V_44 * V_72 )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
return F_67 ( V_2 , V_72 ) ;
}
static int F_68 ( struct V_56 * V_56 , void * V_57 ,
struct V_44 * V_72 )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
return F_69 ( V_2 , V_72 ) ;
}
static int F_70 ( struct V_56 * V_56 , void * V_57 ,
struct V_44 * V_72 )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
struct V_16 * V_43 ;
struct V_33 * V_50 ;
struct V_73 * V_74 ;
int V_51 , V_6 = 0 ;
V_6 = F_68 ( V_56 , V_57 , V_72 ) ;
if ( V_6 )
return V_6 ;
V_43 = F_71 ( V_2 -> V_26 , V_72 -> type ) ;
if ( F_72 ( V_43 ) ) {
F_29 ( L_7 , V_72 -> type ) ;
return - V_75 ;
}
if ( F_57 ( V_72 -> type ) )
V_50 = & V_2 -> V_34 ;
else
V_50 = & V_2 -> V_35 ;
V_74 = & V_72 -> V_45 . V_76 ;
V_50 -> V_45 = F_73 ( & V_74 -> V_77 , NULL , 0 ) ;
V_50 -> V_78 = V_74 -> V_78 ;
if ( ! V_50 -> V_45 )
return - V_52 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_45 -> V_47 ; V_51 ++ )
V_50 -> V_53 [ V_51 ] = V_74 -> V_79 [ V_51 ] . V_80 ;
F_74 ( V_50 , V_74 -> V_81 , V_74 -> V_82 ) ;
if ( V_72 -> type == V_83 )
F_4 ( V_40 | V_84 , V_2 ) ;
else
F_4 ( V_40 | V_85 , V_2 ) ;
F_27 ( L_8 , V_50 -> V_86 , V_50 -> V_87 ) ;
return 0 ;
}
static int F_75 ( struct V_56 * V_56 , void * V_57 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
struct V_33 * V_50 ;
T_1 V_90 ;
V_90 = ( V_89 -> type == V_91 ) ?
V_5 -> V_92 -> V_93 : V_5 -> V_92 -> V_94 ;
if ( V_89 -> V_18 > V_90 ) {
return - V_52 ;
} else if ( V_89 -> V_18 == 0 ) {
if ( V_89 -> type == V_91 )
F_8 ( V_85 , V_2 ) ;
else
F_8 ( V_84 , V_2 ) ;
}
V_50 = F_53 ( V_2 , V_89 -> type ) ;
return F_76 ( V_56 , V_2 -> V_26 , V_89 ) ;
}
static int F_77 ( struct V_56 * V_56 , void * V_57 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
return F_78 ( V_56 , V_2 -> V_26 , V_96 ) ;
}
static int F_79 ( struct V_56 * V_56 , void * V_57 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
return F_80 ( V_56 , V_2 -> V_26 , V_98 ) ;
}
static int F_81 ( struct V_56 * V_56 , void * V_57 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
return F_82 ( V_56 , V_2 -> V_26 , V_98 ) ;
}
static int F_83 ( struct V_56 * V_56 , void * V_57 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
return F_84 ( V_56 , V_2 -> V_26 , V_98 ) ;
}
static int F_85 ( struct V_56 * V_56 , void * V_57 ,
enum V_99 type )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
if ( F_57 ( type ) ) {
if ( ! F_6 ( V_85 , V_2 ) )
return - V_52 ;
} else if ( ! F_6 ( V_84 , V_2 ) ) {
return - V_52 ;
}
return F_86 ( V_56 , V_2 -> V_26 , type ) ;
}
static int F_87 ( struct V_56 * V_56 , void * V_57 ,
enum V_99 type )
{
struct V_1 * V_2 = F_62 ( V_57 ) ;
return F_88 ( V_56 , V_2 -> V_26 , type ) ;
}
static int F_89 ( struct V_100 * V_101 , struct V_100 * V_102 )
{
if ( V_101 -> V_103 < V_102 -> V_103 || V_101 -> V_104 < V_102 -> V_104 )
return 0 ;
if ( V_101 -> V_103 + V_101 -> V_81 > V_102 -> V_103 + V_102 -> V_81 )
return 0 ;
if ( V_101 -> V_104 + V_101 -> V_82 > V_102 -> V_104 + V_102 -> V_82 )
return 0 ;
return 1 ;
}
static int F_90 ( struct V_56 * V_56 , void * V_57 ,
struct V_105 * V_106 )
{
struct V_33 * V_50 ;
struct V_1 * V_2 = F_62 ( V_57 ) ;
if ( ( V_106 -> type != V_83 ) &&
( V_106 -> type != V_91 ) )
return - V_52 ;
V_50 = F_53 ( V_2 , V_106 -> type ) ;
if ( F_54 ( V_50 ) )
return F_55 ( V_50 ) ;
switch ( V_106 -> V_107 ) {
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_106 -> V_112 . V_103 = 0 ;
V_106 -> V_112 . V_104 = 0 ;
V_106 -> V_112 . V_81 = V_50 -> V_86 ;
V_106 -> V_112 . V_82 = V_50 -> V_87 ;
return 0 ;
case V_113 :
case V_114 :
V_106 -> V_112 . V_103 = V_50 -> V_115 . V_103 ;
V_106 -> V_112 . V_104 = V_50 -> V_115 . V_104 ;
V_106 -> V_112 . V_81 = V_50 -> V_115 . V_81 ;
V_106 -> V_112 . V_82 = V_50 -> V_115 . V_82 ;
return 0 ;
}
return - V_52 ;
}
static int F_91 ( struct V_56 * V_56 , void * V_57 ,
struct V_105 * V_106 )
{
struct V_33 * V_50 ;
struct V_1 * V_2 = F_62 ( V_57 ) ;
struct V_116 V_117 ;
struct V_118 * V_92 = V_2 -> V_4 -> V_92 ;
int V_6 ;
V_117 . type = V_106 -> type ;
V_117 . V_119 = V_106 -> V_112 ;
if ( ( V_106 -> type != V_83 ) &&
( V_106 -> type != V_91 ) )
return - V_52 ;
V_6 = F_92 ( V_2 , & V_117 ) ;
if ( V_6 )
return V_6 ;
if ( V_106 -> V_30 & V_120 &&
! F_89 ( & V_117 . V_119 , & V_106 -> V_112 ) )
return - V_121 ;
if ( V_106 -> V_30 & V_122 &&
! F_89 ( & V_106 -> V_112 , & V_117 . V_119 ) )
return - V_121 ;
V_106 -> V_112 = V_117 . V_119 ;
switch ( V_106 -> V_107 ) {
case V_109 :
case V_108 :
case V_113 :
V_50 = & V_2 -> V_34 ;
break;
case V_110 :
case V_114 :
case V_111 :
V_50 = & V_2 -> V_35 ;
break;
default:
return - V_52 ;
}
if ( F_6 ( V_84 | V_85 , V_2 ) ) {
if ( V_106 -> type == V_91 ) {
V_6 = F_93 ( V_92 , V_117 . V_119 . V_81 ,
V_117 . V_119 . V_82 , V_2 -> V_35 . V_115 . V_81 ,
V_2 -> V_35 . V_115 . V_82 ,
V_2 -> V_123 . V_124 -> V_125 , V_2 -> V_126 ) ;
} else {
V_6 = F_93 ( V_92 ,
V_2 -> V_34 . V_115 . V_81 ,
V_2 -> V_34 . V_115 . V_82 , V_117 . V_119 . V_81 ,
V_117 . V_119 . V_82 , V_2 -> V_123 . V_124 -> V_125 ,
V_2 -> V_126 ) ;
}
if ( V_6 ) {
F_29 ( L_9 ) ;
return - V_52 ;
}
}
V_50 -> V_115 = V_117 . V_119 ;
F_4 ( V_40 , V_2 ) ;
return 0 ;
}
static int F_94 ( void * V_32 , struct V_16 * V_127 ,
struct V_16 * V_128 )
{
struct V_1 * V_2 = V_32 ;
int V_6 ;
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
V_127 -> type = V_91 ;
V_127 -> V_129 = V_130 | V_131 | V_132 ;
V_127 -> V_19 = V_2 ;
V_127 -> V_133 = & V_134 ;
V_127 -> V_135 = & V_136 ;
V_127 -> V_137 = sizeof( struct V_138 ) ;
V_127 -> V_139 = V_140 ;
V_6 = F_95 ( V_127 ) ;
if ( V_6 )
return V_6 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
V_128 -> type = V_83 ;
V_128 -> V_129 = V_130 | V_131 | V_132 ;
V_128 -> V_19 = V_2 ;
V_128 -> V_133 = & V_134 ;
V_128 -> V_135 = & V_136 ;
V_128 -> V_137 = sizeof( struct V_138 ) ;
V_128 -> V_139 = V_140 ;
return F_95 ( V_128 ) ;
}
static int F_96 ( struct V_56 * V_56 )
{
struct V_4 * V_5 = F_97 ( V_56 ) ;
struct V_1 * V_2 = NULL ;
int V_6 ;
F_27 ( L_10 , F_98 ( V_141 ) , V_5 -> V_13 ) ;
if ( F_99 ( & V_5 -> V_142 ) )
return - V_143 ;
V_2 = F_100 ( sizeof( * V_2 ) , V_144 ) ;
if ( ! V_2 ) {
V_6 = - V_145 ;
goto V_146;
}
F_101 ( & V_2 -> V_57 , V_5 -> V_7 . V_147 ) ;
V_6 = F_102 ( V_2 ) ;
if ( V_6 )
goto V_148;
V_2 -> V_57 . V_149 = & V_2 -> V_149 ;
V_56 -> V_150 = & V_2 -> V_57 ;
F_103 ( & V_2 -> V_57 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_34 . V_45 = F_104 ( 0 ) ;
V_2 -> V_35 . V_45 = F_104 ( 0 ) ;
V_2 -> V_13 = V_151 ;
V_2 -> V_30 = 0 ;
V_2 -> V_152 = V_153 ;
V_2 -> V_126 = V_153 ;
V_2 -> V_26 = F_105 ( V_5 -> V_7 . V_8 , V_2 , F_94 ) ;
if ( F_54 ( V_2 -> V_26 ) ) {
F_29 ( L_11 ) ;
V_6 = F_55 ( V_2 -> V_26 ) ;
goto V_154;
}
if ( V_5 -> V_7 . V_155 ++ == 0 )
F_26 ( V_156 , & V_5 -> V_13 ) ;
F_27 ( L_12 , V_2 ) ;
F_106 ( & V_5 -> V_142 ) ;
return 0 ;
V_154:
F_107 ( V_2 ) ;
V_148:
F_108 ( & V_2 -> V_57 ) ;
F_109 ( & V_2 -> V_57 ) ;
F_110 ( V_2 ) ;
V_146:
F_106 ( & V_5 -> V_142 ) ;
return V_6 ;
}
static int F_111 ( struct V_56 * V_56 )
{
struct V_1 * V_2 = F_62 ( V_56 -> V_150 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_27 ( L_13 ,
F_98 ( V_141 ) , V_5 -> V_13 , V_5 -> V_7 . V_155 ) ;
F_112 ( & V_5 -> V_142 ) ;
F_113 ( V_2 -> V_26 ) ;
F_107 ( V_2 ) ;
F_108 ( & V_2 -> V_57 ) ;
F_109 ( & V_2 -> V_57 ) ;
if ( -- V_5 -> V_7 . V_155 <= 0 )
F_114 ( V_156 , & V_5 -> V_13 ) ;
F_110 ( V_2 ) ;
F_106 ( & V_5 -> V_142 ) ;
return 0 ;
}
static unsigned int F_115 ( struct V_56 * V_56 ,
struct V_157 * V_158 )
{
struct V_1 * V_2 = F_62 ( V_56 -> V_150 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_99 ( & V_5 -> V_142 ) )
return - V_143 ;
V_6 = F_116 ( V_56 , V_2 -> V_26 , V_158 ) ;
F_106 ( & V_5 -> V_142 ) ;
return V_6 ;
}
static int F_117 ( struct V_56 * V_56 , struct V_159 * V_160 )
{
struct V_1 * V_2 = F_62 ( V_56 -> V_150 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_99 ( & V_5 -> V_142 ) )
return - V_143 ;
V_6 = F_118 ( V_56 , V_2 -> V_26 , V_160 ) ;
F_106 ( & V_5 -> V_142 ) ;
return V_6 ;
}
int F_119 ( struct V_4 * V_5 )
{
struct V_161 * V_20 ;
int V_6 ;
if ( ! V_5 )
return - V_162 ;
V_20 = V_5 -> V_20 ;
V_5 -> V_163 . V_164 = & V_165 ;
V_5 -> V_163 . V_166 = & V_167 ;
V_5 -> V_163 . V_168 = V_169 ;
V_5 -> V_163 . V_142 = & V_5 -> V_142 ;
V_5 -> V_163 . V_170 = V_171 ;
V_5 -> V_163 . V_172 = & V_5 -> V_172 ;
snprintf ( V_5 -> V_163 . V_61 , sizeof( V_5 -> V_163 . V_61 ) , L_14 ,
V_173 , V_5 -> V_174 ) ;
F_120 ( & V_5 -> V_163 , V_5 ) ;
V_5 -> V_7 . V_147 = & V_5 -> V_163 ;
V_5 -> V_7 . V_8 = F_121 ( & V_175 ) ;
if ( F_54 ( V_5 -> V_7 . V_8 ) ) {
F_122 ( & V_20 -> V_21 , L_15 ) ;
V_6 = F_55 ( V_5 -> V_7 . V_8 ) ;
goto V_176;
}
V_6 = F_123 ( & V_5 -> V_163 , V_177 , - 1 ) ;
if ( V_6 ) {
F_122 ( & V_20 -> V_21 ,
L_16 , V_178 ) ;
goto V_179;
}
F_27 ( L_17 , V_5 -> V_163 . V_180 ) ;
return 0 ;
V_179:
F_124 ( V_5 -> V_7 . V_8 ) ;
V_176:
F_125 ( V_5 -> V_7 . V_147 ) ;
return V_6 ;
}
void F_126 ( struct V_4 * V_5 )
{
if ( V_5 )
F_124 ( V_5 -> V_7 . V_8 ) ;
}
