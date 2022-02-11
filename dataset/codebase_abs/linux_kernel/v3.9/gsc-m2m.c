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
static int F_7 ( struct V_13 * V_14 , unsigned int V_15 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
int V_6 ;
V_6 = F_8 ( & V_2 -> V_4 -> V_17 -> V_18 ) ;
return V_6 > 0 ? 0 : V_6 ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
int V_6 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == - V_12 )
F_10 ( V_2 , V_19 ) ;
F_11 ( & V_2 -> V_4 -> V_17 -> V_18 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 , int V_20 )
{
struct V_21 * V_22 , * V_23 ;
if ( ! V_2 || ! V_2 -> V_24 )
return;
V_22 = F_12 ( V_2 -> V_24 ) ;
V_23 = F_13 ( V_2 -> V_24 ) ;
if ( V_22 && V_23 ) {
F_14 ( V_22 , V_20 ) ;
F_14 ( V_23 , V_20 ) ;
F_15 ( V_2 -> V_4 -> V_7 . V_8 ,
V_2 -> V_24 ) ;
}
}
static void F_16 ( void * V_25 )
{
struct V_1 * V_2 = V_25 ;
int V_6 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == - V_12 )
F_10 ( V_2 , V_19 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_26 * V_27 , * V_28 ;
struct V_21 * V_22 , * V_23 ;
int V_6 ;
V_27 = & V_2 -> V_27 ;
V_28 = & V_2 -> V_28 ;
V_22 = F_18 ( V_2 -> V_24 ) ;
V_6 = F_19 ( V_2 , V_22 , V_27 , & V_27 -> V_29 ) ;
if ( V_6 )
return V_6 ;
V_23 = F_20 ( V_2 -> V_24 ) ;
V_6 = F_19 ( V_2 , V_23 , V_28 , & V_28 -> V_29 ) ;
if ( V_6 )
return V_6 ;
V_23 -> V_30 . V_31 = V_22 -> V_30 . V_31 ;
return 0 ;
}
static void F_21 ( void * V_25 )
{
struct V_1 * V_2 = V_25 ;
struct V_4 * V_5 ;
unsigned long V_32 ;
int V_6 ;
bool V_33 = false ;
if ( F_22 ( ! V_2 , L_1 ) )
return;
V_5 = V_2 -> V_4 ;
F_23 ( & V_5 -> V_34 , V_32 ) ;
F_24 ( V_35 , & V_5 -> V_36 ) ;
if ( V_5 -> V_7 . V_2 != V_2 ) {
F_25 ( L_2 ,
V_5 -> V_7 . V_2 , V_2 ) ;
V_2 -> V_36 |= V_37 ;
V_5 -> V_7 . V_2 = V_2 ;
}
V_33 = ( V_2 -> V_36 & V_9 ) ? 1 : 0 ;
V_2 -> V_36 &= ~ V_9 ;
if ( V_33 ) {
F_26 ( & V_5 -> V_10 ) ;
goto V_38;
}
V_6 = F_17 ( V_2 ) ;
if ( V_6 ) {
F_27 ( L_3 ) ;
goto V_38;
}
F_28 ( V_5 , & V_2 -> V_27 ) ;
F_29 ( V_5 , & V_2 -> V_27 . V_29 , V_39 ) ;
F_30 ( V_5 , & V_2 -> V_28 . V_29 , V_39 ) ;
if ( V_2 -> V_36 & V_37 ) {
F_31 ( V_5 , V_39 , false ) ;
F_32 ( V_5 , V_39 , false ) ;
F_33 ( V_5 , false ) ;
F_34 ( V_5 , true ) ;
if ( F_35 ( V_2 ) ) {
F_27 ( L_4 ) ;
goto V_38;
}
F_36 ( V_2 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
}
F_46 ( V_2 ) ;
V_2 -> V_36 &= ~ V_37 ;
F_47 ( V_5 , true ) ;
F_48 ( & V_5 -> V_34 , V_32 ) ;
return;
V_38:
V_2 -> V_36 &= ~ V_37 ;
F_48 ( & V_5 -> V_34 , V_32 ) ;
}
static int F_49 ( struct V_13 * V_40 ,
const struct V_41 * V_42 ,
unsigned int * V_43 , unsigned int * V_44 ,
unsigned int V_45 [] , void * V_46 [] )
{
struct V_1 * V_2 = F_50 ( V_40 ) ;
struct V_26 * V_47 ;
int V_48 ;
V_47 = F_51 ( V_2 , V_40 -> type ) ;
if ( F_52 ( V_47 ) )
return F_53 ( V_47 ) ;
if ( ! V_47 -> V_42 )
return - V_49 ;
* V_44 = V_47 -> V_42 -> V_44 ;
for ( V_48 = 0 ; V_48 < V_47 -> V_42 -> V_44 ; V_48 ++ ) {
V_45 [ V_48 ] = V_47 -> V_50 [ V_48 ] ;
V_46 [ V_48 ] = V_2 -> V_4 -> V_51 ;
}
return 0 ;
}
static int F_54 ( struct V_21 * V_52 )
{
struct V_1 * V_2 = F_50 ( V_52 -> V_13 ) ;
struct V_26 * V_47 ;
int V_48 ;
V_47 = F_51 ( V_2 , V_52 -> V_13 -> type ) ;
if ( F_52 ( V_47 ) )
return F_53 ( V_47 ) ;
if ( ! F_55 ( V_52 -> V_13 -> type ) ) {
for ( V_48 = 0 ; V_48 < V_47 -> V_42 -> V_44 ; V_48 ++ )
F_56 ( V_52 , V_48 , V_47 -> V_50 [ V_48 ] ) ;
}
return 0 ;
}
static void F_57 ( struct V_21 * V_52 )
{
struct V_1 * V_2 = F_50 ( V_52 -> V_13 ) ;
F_25 ( L_5 , V_2 , V_2 -> V_36 ) ;
if ( V_2 -> V_24 )
F_58 ( V_2 -> V_24 , V_52 ) ;
}
static int F_59 ( struct V_53 * V_53 , void * V_54 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_61 ( V_56 -> V_57 , V_5 -> V_17 -> V_58 , sizeof( V_56 -> V_57 ) ) ;
F_61 ( V_56 -> V_59 , V_5 -> V_17 -> V_58 , sizeof( V_56 -> V_59 ) ) ;
F_61 ( V_56 -> V_60 , L_6 , sizeof( V_56 -> V_60 ) ) ;
V_56 -> V_61 = V_62 | V_63 |
V_64 | V_65 ;
V_56 -> V_66 = V_56 -> V_61 | V_67 ;
return 0 ;
}
static int F_62 ( struct V_53 * V_53 , void * V_25 ,
struct V_68 * V_69 )
{
return F_63 ( V_69 ) ;
}
static int F_64 ( struct V_53 * V_53 , void * V_54 ,
struct V_41 * V_69 )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
return F_65 ( V_2 , V_69 ) ;
}
static int F_66 ( struct V_53 * V_53 , void * V_54 ,
struct V_41 * V_69 )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
return F_67 ( V_2 , V_69 ) ;
}
static int F_68 ( struct V_53 * V_53 , void * V_54 ,
struct V_41 * V_69 )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
struct V_13 * V_40 ;
struct V_26 * V_47 ;
struct V_70 * V_71 ;
int V_48 , V_6 = 0 ;
V_6 = F_66 ( V_53 , V_54 , V_69 ) ;
if ( V_6 )
return V_6 ;
V_40 = F_69 ( V_2 -> V_24 , V_69 -> type ) ;
if ( F_70 ( V_40 ) ) {
F_27 ( L_7 , V_69 -> type ) ;
return - V_72 ;
}
if ( F_55 ( V_69 -> type ) )
V_47 = & V_2 -> V_27 ;
else
V_47 = & V_2 -> V_28 ;
V_71 = & V_69 -> V_42 . V_73 ;
V_47 -> V_42 = F_71 ( & V_71 -> V_74 , NULL , 0 ) ;
V_47 -> V_75 = V_71 -> V_75 ;
if ( ! V_47 -> V_42 )
return - V_49 ;
for ( V_48 = 0 ; V_48 < V_47 -> V_42 -> V_44 ; V_48 ++ )
V_47 -> V_50 [ V_48 ] = V_71 -> V_76 [ V_48 ] . V_77 ;
F_72 ( V_47 , V_71 -> V_78 , V_71 -> V_79 ) ;
if ( V_69 -> type == V_80 )
F_4 ( V_37 | V_81 , V_2 ) ;
else
F_4 ( V_37 | V_82 , V_2 ) ;
F_25 ( L_8 , V_47 -> V_83 , V_47 -> V_84 ) ;
return 0 ;
}
static int F_73 ( struct V_53 * V_53 , void * V_54 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
struct V_26 * V_47 ;
T_1 V_87 ;
V_87 = ( V_86 -> type == V_88 ) ?
V_5 -> V_89 -> V_90 : V_5 -> V_89 -> V_91 ;
if ( V_86 -> V_15 > V_87 ) {
return - V_49 ;
} else if ( V_86 -> V_15 == 0 ) {
if ( V_86 -> type == V_88 )
F_74 ( V_82 , V_2 ) ;
else
F_74 ( V_81 , V_2 ) ;
}
V_47 = F_51 ( V_2 , V_86 -> type ) ;
return F_75 ( V_53 , V_2 -> V_24 , V_86 ) ;
}
static int F_76 ( struct V_53 * V_53 , void * V_54 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
return F_77 ( V_53 , V_2 -> V_24 , V_93 ) ;
}
static int F_78 ( struct V_53 * V_53 , void * V_54 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
return F_79 ( V_53 , V_2 -> V_24 , V_95 ) ;
}
static int F_80 ( struct V_53 * V_53 , void * V_54 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
return F_81 ( V_53 , V_2 -> V_24 , V_95 ) ;
}
static int F_82 ( struct V_53 * V_53 , void * V_54 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
return F_83 ( V_53 , V_2 -> V_24 , V_95 ) ;
}
static int F_84 ( struct V_53 * V_53 , void * V_54 ,
enum V_96 type )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
if ( F_55 ( type ) ) {
if ( ! F_6 ( V_82 , V_2 ) )
return - V_49 ;
} else if ( ! F_6 ( V_81 , V_2 ) ) {
return - V_49 ;
}
return F_85 ( V_53 , V_2 -> V_24 , type ) ;
}
static int F_86 ( struct V_53 * V_53 , void * V_54 ,
enum V_96 type )
{
struct V_1 * V_2 = F_60 ( V_54 ) ;
return F_87 ( V_53 , V_2 -> V_24 , type ) ;
}
static int F_88 ( struct V_97 * V_98 , struct V_97 * V_99 )
{
if ( V_98 -> V_100 < V_99 -> V_100 || V_98 -> V_101 < V_99 -> V_101 )
return 0 ;
if ( V_98 -> V_100 + V_98 -> V_78 > V_99 -> V_100 + V_99 -> V_78 )
return 0 ;
if ( V_98 -> V_101 + V_98 -> V_79 > V_99 -> V_101 + V_99 -> V_79 )
return 0 ;
return 1 ;
}
static int F_89 ( struct V_53 * V_53 , void * V_54 ,
struct V_102 * V_103 )
{
struct V_26 * V_47 ;
struct V_1 * V_2 = F_60 ( V_54 ) ;
if ( ( V_103 -> type != V_80 ) &&
( V_103 -> type != V_88 ) )
return - V_49 ;
V_47 = F_51 ( V_2 , V_103 -> type ) ;
if ( F_52 ( V_47 ) )
return F_53 ( V_47 ) ;
switch ( V_103 -> V_104 ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
V_103 -> V_109 . V_100 = 0 ;
V_103 -> V_109 . V_101 = 0 ;
V_103 -> V_109 . V_78 = V_47 -> V_83 ;
V_103 -> V_109 . V_79 = V_47 -> V_84 ;
return 0 ;
case V_110 :
case V_111 :
V_103 -> V_109 . V_100 = V_47 -> V_112 . V_100 ;
V_103 -> V_109 . V_101 = V_47 -> V_112 . V_101 ;
V_103 -> V_109 . V_78 = V_47 -> V_112 . V_78 ;
V_103 -> V_109 . V_79 = V_47 -> V_112 . V_79 ;
return 0 ;
}
return - V_49 ;
}
static int F_90 ( struct V_53 * V_53 , void * V_54 ,
struct V_102 * V_103 )
{
struct V_26 * V_47 ;
struct V_1 * V_2 = F_60 ( V_54 ) ;
struct V_113 V_114 ;
struct V_115 * V_89 = V_2 -> V_4 -> V_89 ;
int V_6 ;
V_114 . type = V_103 -> type ;
V_114 . V_116 = V_103 -> V_109 ;
if ( ( V_103 -> type != V_80 ) &&
( V_103 -> type != V_88 ) )
return - V_49 ;
V_6 = F_91 ( V_2 , & V_114 ) ;
if ( V_6 )
return V_6 ;
if ( V_103 -> V_32 & V_117 &&
! F_88 ( & V_114 . V_116 , & V_103 -> V_109 ) )
return - V_118 ;
if ( V_103 -> V_32 & V_119 &&
! F_88 ( & V_103 -> V_109 , & V_114 . V_116 ) )
return - V_118 ;
V_103 -> V_109 = V_114 . V_116 ;
switch ( V_103 -> V_104 ) {
case V_106 :
case V_105 :
case V_110 :
V_47 = & V_2 -> V_27 ;
break;
case V_107 :
case V_111 :
case V_108 :
V_47 = & V_2 -> V_28 ;
break;
default:
return - V_49 ;
}
if ( F_6 ( V_81 | V_82 , V_2 ) ) {
if ( V_103 -> type == V_88 ) {
V_6 = F_92 ( V_89 , V_114 . V_116 . V_78 ,
V_114 . V_116 . V_79 , V_2 -> V_28 . V_112 . V_78 ,
V_2 -> V_28 . V_112 . V_79 ,
V_2 -> V_120 . V_121 -> V_122 , V_2 -> V_123 ) ;
} else {
V_6 = F_92 ( V_89 ,
V_2 -> V_27 . V_112 . V_78 ,
V_2 -> V_27 . V_112 . V_79 , V_114 . V_116 . V_78 ,
V_114 . V_116 . V_79 , V_2 -> V_120 . V_121 -> V_122 ,
V_2 -> V_123 ) ;
}
if ( V_6 ) {
F_27 ( L_9 ) ;
return - V_49 ;
}
}
V_47 -> V_112 = V_114 . V_116 ;
F_4 ( V_37 , V_2 ) ;
return 0 ;
}
static int F_93 ( void * V_25 , struct V_13 * V_124 ,
struct V_13 * V_125 )
{
struct V_1 * V_2 = V_25 ;
int V_6 ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
V_124 -> type = V_88 ;
V_124 -> V_126 = V_127 | V_128 | V_129 ;
V_124 -> V_16 = V_2 ;
V_124 -> V_130 = & V_131 ;
V_124 -> V_132 = & V_133 ;
V_124 -> V_134 = sizeof( struct V_135 ) ;
V_6 = F_94 ( V_124 ) ;
if ( V_6 )
return V_6 ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_125 -> type = V_80 ;
V_125 -> V_126 = V_127 | V_128 | V_129 ;
V_125 -> V_16 = V_2 ;
V_125 -> V_130 = & V_131 ;
V_125 -> V_132 = & V_133 ;
V_125 -> V_134 = sizeof( struct V_135 ) ;
return F_94 ( V_125 ) ;
}
static int F_95 ( struct V_53 * V_53 )
{
struct V_4 * V_5 = F_96 ( V_53 ) ;
struct V_1 * V_2 = NULL ;
int V_6 ;
F_25 ( L_10 , F_97 ( V_136 ) , V_5 -> V_36 ) ;
if ( F_98 ( & V_5 -> V_137 ) )
return - V_138 ;
V_2 = F_99 ( sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 ) {
V_6 = - V_140 ;
goto V_141;
}
F_100 ( & V_2 -> V_54 , V_5 -> V_7 . V_142 ) ;
V_6 = F_101 ( V_2 ) ;
if ( V_6 )
goto V_143;
V_2 -> V_54 . V_144 = & V_2 -> V_144 ;
V_53 -> V_145 = & V_2 -> V_54 ;
F_102 ( & V_2 -> V_54 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_27 . V_42 = F_103 ( 0 ) ;
V_2 -> V_28 . V_42 = F_103 ( 0 ) ;
V_2 -> V_36 = V_146 ;
V_2 -> V_32 = 0 ;
V_2 -> V_147 = V_148 ;
V_2 -> V_123 = V_148 ;
V_2 -> V_24 = F_104 ( V_5 -> V_7 . V_8 , V_2 , F_93 ) ;
if ( F_52 ( V_2 -> V_24 ) ) {
F_27 ( L_11 ) ;
V_6 = F_53 ( V_2 -> V_24 ) ;
goto V_149;
}
if ( V_5 -> V_7 . V_150 ++ == 0 )
F_24 ( V_151 , & V_5 -> V_36 ) ;
F_25 ( L_12 , V_2 ) ;
F_105 ( & V_5 -> V_137 ) ;
return 0 ;
V_149:
F_106 ( V_2 ) ;
V_143:
F_107 ( & V_2 -> V_54 ) ;
F_108 ( & V_2 -> V_54 ) ;
F_109 ( V_2 ) ;
V_141:
F_105 ( & V_5 -> V_137 ) ;
return V_6 ;
}
static int F_110 ( struct V_53 * V_53 )
{
struct V_1 * V_2 = F_60 ( V_53 -> V_145 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_25 ( L_13 ,
F_97 ( V_136 ) , V_5 -> V_36 , V_5 -> V_7 . V_150 ) ;
F_111 ( & V_5 -> V_137 ) ;
F_112 ( V_2 -> V_24 ) ;
F_106 ( V_2 ) ;
F_107 ( & V_2 -> V_54 ) ;
F_108 ( & V_2 -> V_54 ) ;
if ( -- V_5 -> V_7 . V_150 <= 0 )
F_113 ( V_151 , & V_5 -> V_36 ) ;
F_109 ( V_2 ) ;
F_105 ( & V_5 -> V_137 ) ;
return 0 ;
}
static unsigned int F_114 ( struct V_53 * V_53 ,
struct V_152 * V_153 )
{
struct V_1 * V_2 = F_60 ( V_53 -> V_145 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_98 ( & V_5 -> V_137 ) )
return - V_138 ;
V_6 = F_115 ( V_53 , V_2 -> V_24 , V_153 ) ;
F_105 ( & V_5 -> V_137 ) ;
return V_6 ;
}
static int F_116 ( struct V_53 * V_53 , struct V_154 * V_155 )
{
struct V_1 * V_2 = F_60 ( V_53 -> V_145 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_98 ( & V_5 -> V_137 ) )
return - V_138 ;
V_6 = F_117 ( V_53 , V_2 -> V_24 , V_155 ) ;
F_105 ( & V_5 -> V_137 ) ;
return V_6 ;
}
int F_118 ( struct V_4 * V_5 )
{
struct V_156 * V_17 ;
int V_6 ;
if ( ! V_5 )
return - V_157 ;
V_17 = V_5 -> V_17 ;
V_5 -> V_158 . V_159 = & V_160 ;
V_5 -> V_158 . V_161 = & V_162 ;
V_5 -> V_158 . V_163 = V_164 ;
V_5 -> V_158 . V_137 = & V_5 -> V_137 ;
V_5 -> V_158 . V_165 = V_166 ;
snprintf ( V_5 -> V_158 . V_58 , sizeof( V_5 -> V_158 . V_58 ) , L_14 ,
V_167 , V_5 -> V_168 ) ;
F_119 ( & V_5 -> V_158 , V_5 ) ;
V_5 -> V_7 . V_142 = & V_5 -> V_158 ;
V_5 -> V_7 . V_8 = F_120 ( & V_169 ) ;
if ( F_52 ( V_5 -> V_7 . V_8 ) ) {
F_121 ( & V_17 -> V_18 , L_15 ) ;
V_6 = F_53 ( V_5 -> V_7 . V_8 ) ;
goto V_170;
}
V_6 = F_122 ( & V_5 -> V_158 , V_171 , - 1 ) ;
if ( V_6 ) {
F_121 ( & V_17 -> V_18 ,
L_16 , V_172 ) ;
goto V_173;
}
F_25 ( L_17 , V_5 -> V_158 . V_174 ) ;
return 0 ;
V_173:
F_123 ( V_5 -> V_7 . V_8 ) ;
V_170:
F_124 ( V_5 -> V_7 . V_142 ) ;
return V_6 ;
}
void F_125 ( struct V_4 * V_5 )
{
if ( V_5 )
F_123 ( V_5 -> V_7 . V_8 ) ;
}
