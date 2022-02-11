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
V_22 -> V_25 . V_26 = V_23 -> V_25 . V_26 ;
V_22 -> V_25 . V_27 = V_23 -> V_25 . V_27 ;
F_14 ( V_22 , V_20 ) ;
F_14 ( V_23 , V_20 ) ;
F_15 ( V_2 -> V_4 -> V_7 . V_8 ,
V_2 -> V_24 ) ;
}
}
static void F_16 ( void * V_28 )
{
struct V_1 * V_2 = V_28 ;
int V_6 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 == - V_12 )
F_10 ( V_2 , V_19 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_29 * V_30 , * V_31 ;
struct V_21 * V_22 , * V_23 ;
int V_6 ;
V_30 = & V_2 -> V_30 ;
V_31 = & V_2 -> V_31 ;
V_22 = F_18 ( V_2 -> V_24 ) ;
V_6 = F_19 ( V_2 , V_22 , V_30 , & V_30 -> V_32 ) ;
if ( V_6 )
return V_6 ;
V_23 = F_20 ( V_2 -> V_24 ) ;
V_6 = F_19 ( V_2 , V_23 , V_31 , & V_31 -> V_32 ) ;
if ( V_6 )
return V_6 ;
V_23 -> V_25 . V_26 = V_22 -> V_25 . V_26 ;
return 0 ;
}
static void F_21 ( void * V_28 )
{
struct V_1 * V_2 = V_28 ;
struct V_4 * V_5 ;
unsigned long V_33 ;
int V_6 ;
bool V_34 = false ;
if ( F_22 ( ! V_2 , L_1 ) )
return;
V_5 = V_2 -> V_4 ;
F_23 ( & V_5 -> V_35 , V_33 ) ;
F_24 ( V_36 , & V_5 -> V_37 ) ;
if ( V_5 -> V_7 . V_2 != V_2 ) {
F_25 ( L_2 ,
V_5 -> V_7 . V_2 , V_2 ) ;
V_2 -> V_37 |= V_38 ;
V_5 -> V_7 . V_2 = V_2 ;
}
V_34 = ( V_2 -> V_37 & V_9 ) ? 1 : 0 ;
V_2 -> V_37 &= ~ V_9 ;
if ( V_34 ) {
F_26 ( & V_5 -> V_10 ) ;
goto V_39;
}
V_6 = F_17 ( V_2 ) ;
if ( V_6 ) {
F_27 ( L_3 ) ;
goto V_39;
}
F_28 ( V_5 , & V_2 -> V_30 ) ;
F_29 ( V_5 , & V_2 -> V_30 . V_32 , V_40 ) ;
F_30 ( V_5 , & V_2 -> V_31 . V_32 , V_40 ) ;
if ( V_2 -> V_37 & V_38 ) {
F_31 ( V_5 , V_40 , false ) ;
F_32 ( V_5 , V_40 , false ) ;
F_33 ( V_5 , false ) ;
F_34 ( V_5 , true ) ;
if ( F_35 ( V_2 ) ) {
F_27 ( L_4 ) ;
goto V_39;
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
V_2 -> V_37 &= ~ V_38 ;
F_47 ( V_5 , true ) ;
F_48 ( & V_5 -> V_35 , V_33 ) ;
return;
V_39:
V_2 -> V_37 &= ~ V_38 ;
F_48 ( & V_5 -> V_35 , V_33 ) ;
}
static int F_49 ( struct V_13 * V_41 ,
const struct V_42 * V_43 ,
unsigned int * V_44 , unsigned int * V_45 ,
unsigned int V_46 [] , void * V_47 [] )
{
struct V_1 * V_2 = F_50 ( V_41 ) ;
struct V_29 * V_48 ;
int V_49 ;
V_48 = F_51 ( V_2 , V_41 -> type ) ;
if ( F_52 ( V_48 ) )
return F_53 ( V_48 ) ;
if ( ! V_48 -> V_43 )
return - V_50 ;
* V_45 = V_48 -> V_43 -> V_45 ;
for ( V_49 = 0 ; V_49 < V_48 -> V_43 -> V_45 ; V_49 ++ ) {
V_46 [ V_49 ] = V_48 -> V_51 [ V_49 ] ;
V_47 [ V_49 ] = V_2 -> V_4 -> V_52 ;
}
return 0 ;
}
static int F_54 ( struct V_21 * V_53 )
{
struct V_1 * V_2 = F_50 ( V_53 -> V_13 ) ;
struct V_29 * V_48 ;
int V_49 ;
V_48 = F_51 ( V_2 , V_53 -> V_13 -> type ) ;
if ( F_52 ( V_48 ) )
return F_53 ( V_48 ) ;
if ( ! F_55 ( V_53 -> V_13 -> type ) ) {
for ( V_49 = 0 ; V_49 < V_48 -> V_43 -> V_45 ; V_49 ++ )
F_56 ( V_53 , V_49 , V_48 -> V_51 [ V_49 ] ) ;
}
return 0 ;
}
static void F_57 ( struct V_21 * V_53 )
{
struct V_1 * V_2 = F_50 ( V_53 -> V_13 ) ;
F_25 ( L_5 , V_2 , V_2 -> V_37 ) ;
if ( V_2 -> V_24 )
F_58 ( V_2 -> V_24 , V_53 ) ;
}
static int F_59 ( struct V_54 * V_54 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_61 ( V_57 -> V_58 , V_5 -> V_17 -> V_59 , sizeof( V_57 -> V_58 ) ) ;
F_61 ( V_57 -> V_60 , V_5 -> V_17 -> V_59 , sizeof( V_57 -> V_60 ) ) ;
F_61 ( V_57 -> V_61 , L_6 , sizeof( V_57 -> V_61 ) ) ;
V_57 -> V_62 = V_63 | V_64 |
V_65 | V_66 ;
V_57 -> V_67 = V_57 -> V_62 | V_68 ;
return 0 ;
}
static int F_62 ( struct V_54 * V_54 , void * V_28 ,
struct V_69 * V_70 )
{
return F_63 ( V_70 ) ;
}
static int F_64 ( struct V_54 * V_54 , void * V_55 ,
struct V_42 * V_70 )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
return F_65 ( V_2 , V_70 ) ;
}
static int F_66 ( struct V_54 * V_54 , void * V_55 ,
struct V_42 * V_70 )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
return F_67 ( V_2 , V_70 ) ;
}
static int F_68 ( struct V_54 * V_54 , void * V_55 ,
struct V_42 * V_70 )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
struct V_13 * V_41 ;
struct V_29 * V_48 ;
struct V_71 * V_72 ;
int V_49 , V_6 = 0 ;
V_6 = F_66 ( V_54 , V_55 , V_70 ) ;
if ( V_6 )
return V_6 ;
V_41 = F_69 ( V_2 -> V_24 , V_70 -> type ) ;
if ( F_70 ( V_41 ) ) {
F_27 ( L_7 , V_70 -> type ) ;
return - V_73 ;
}
if ( F_55 ( V_70 -> type ) )
V_48 = & V_2 -> V_30 ;
else
V_48 = & V_2 -> V_31 ;
V_72 = & V_70 -> V_43 . V_74 ;
V_48 -> V_43 = F_71 ( & V_72 -> V_75 , NULL , 0 ) ;
V_48 -> V_76 = V_72 -> V_76 ;
if ( ! V_48 -> V_43 )
return - V_50 ;
for ( V_49 = 0 ; V_49 < V_48 -> V_43 -> V_45 ; V_49 ++ )
V_48 -> V_51 [ V_49 ] = V_72 -> V_77 [ V_49 ] . V_78 ;
F_72 ( V_48 , V_72 -> V_79 , V_72 -> V_80 ) ;
if ( V_70 -> type == V_81 )
F_4 ( V_38 | V_82 , V_2 ) ;
else
F_4 ( V_38 | V_83 , V_2 ) ;
F_25 ( L_8 , V_48 -> V_84 , V_48 -> V_85 ) ;
return 0 ;
}
static int F_73 ( struct V_54 * V_54 , void * V_55 ,
struct V_86 * V_87 )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
struct V_29 * V_48 ;
T_1 V_88 ;
V_88 = ( V_87 -> type == V_89 ) ?
V_5 -> V_90 -> V_91 : V_5 -> V_90 -> V_92 ;
if ( V_87 -> V_15 > V_88 ) {
return - V_50 ;
} else if ( V_87 -> V_15 == 0 ) {
if ( V_87 -> type == V_89 )
F_74 ( V_83 , V_2 ) ;
else
F_74 ( V_82 , V_2 ) ;
}
V_48 = F_51 ( V_2 , V_87 -> type ) ;
return F_75 ( V_54 , V_2 -> V_24 , V_87 ) ;
}
static int F_76 ( struct V_54 * V_54 , void * V_55 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
return F_77 ( V_54 , V_2 -> V_24 , V_94 ) ;
}
static int F_78 ( struct V_54 * V_54 , void * V_55 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
return F_79 ( V_54 , V_2 -> V_24 , V_96 ) ;
}
static int F_80 ( struct V_54 * V_54 , void * V_55 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
return F_81 ( V_54 , V_2 -> V_24 , V_96 ) ;
}
static int F_82 ( struct V_54 * V_54 , void * V_55 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
return F_83 ( V_54 , V_2 -> V_24 , V_96 ) ;
}
static int F_84 ( struct V_54 * V_54 , void * V_55 ,
enum V_97 type )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
if ( F_55 ( type ) ) {
if ( ! F_6 ( V_83 , V_2 ) )
return - V_50 ;
} else if ( ! F_6 ( V_82 , V_2 ) ) {
return - V_50 ;
}
return F_85 ( V_54 , V_2 -> V_24 , type ) ;
}
static int F_86 ( struct V_54 * V_54 , void * V_55 ,
enum V_97 type )
{
struct V_1 * V_2 = F_60 ( V_55 ) ;
return F_87 ( V_54 , V_2 -> V_24 , type ) ;
}
static int F_88 ( struct V_98 * V_99 , struct V_98 * V_100 )
{
if ( V_99 -> V_101 < V_100 -> V_101 || V_99 -> V_102 < V_100 -> V_102 )
return 0 ;
if ( V_99 -> V_101 + V_99 -> V_79 > V_100 -> V_101 + V_100 -> V_79 )
return 0 ;
if ( V_99 -> V_102 + V_99 -> V_80 > V_100 -> V_102 + V_100 -> V_80 )
return 0 ;
return 1 ;
}
static int F_89 ( struct V_54 * V_54 , void * V_55 ,
struct V_103 * V_104 )
{
struct V_29 * V_48 ;
struct V_1 * V_2 = F_60 ( V_55 ) ;
if ( ( V_104 -> type != V_81 ) &&
( V_104 -> type != V_89 ) )
return - V_50 ;
V_48 = F_51 ( V_2 , V_104 -> type ) ;
if ( F_52 ( V_48 ) )
return F_53 ( V_48 ) ;
switch ( V_104 -> V_105 ) {
case V_106 :
case V_107 :
case V_108 :
case V_109 :
V_104 -> V_110 . V_101 = 0 ;
V_104 -> V_110 . V_102 = 0 ;
V_104 -> V_110 . V_79 = V_48 -> V_84 ;
V_104 -> V_110 . V_80 = V_48 -> V_85 ;
return 0 ;
case V_111 :
case V_112 :
V_104 -> V_110 . V_101 = V_48 -> V_113 . V_101 ;
V_104 -> V_110 . V_102 = V_48 -> V_113 . V_102 ;
V_104 -> V_110 . V_79 = V_48 -> V_113 . V_79 ;
V_104 -> V_110 . V_80 = V_48 -> V_113 . V_80 ;
return 0 ;
}
return - V_50 ;
}
static int F_90 ( struct V_54 * V_54 , void * V_55 ,
struct V_103 * V_104 )
{
struct V_29 * V_48 ;
struct V_1 * V_2 = F_60 ( V_55 ) ;
struct V_114 V_115 ;
struct V_116 * V_90 = V_2 -> V_4 -> V_90 ;
int V_6 ;
V_115 . type = V_104 -> type ;
V_115 . V_117 = V_104 -> V_110 ;
if ( ( V_104 -> type != V_81 ) &&
( V_104 -> type != V_89 ) )
return - V_50 ;
V_6 = F_91 ( V_2 , & V_115 ) ;
if ( V_6 )
return V_6 ;
if ( V_104 -> V_33 & V_118 &&
! F_88 ( & V_115 . V_117 , & V_104 -> V_110 ) )
return - V_119 ;
if ( V_104 -> V_33 & V_120 &&
! F_88 ( & V_104 -> V_110 , & V_115 . V_117 ) )
return - V_119 ;
V_104 -> V_110 = V_115 . V_117 ;
switch ( V_104 -> V_105 ) {
case V_107 :
case V_106 :
case V_111 :
V_48 = & V_2 -> V_30 ;
break;
case V_108 :
case V_112 :
case V_109 :
V_48 = & V_2 -> V_31 ;
break;
default:
return - V_50 ;
}
if ( F_6 ( V_82 | V_83 , V_2 ) ) {
if ( V_104 -> type == V_89 ) {
V_6 = F_92 ( V_90 , V_115 . V_117 . V_79 ,
V_115 . V_117 . V_80 , V_2 -> V_31 . V_113 . V_79 ,
V_2 -> V_31 . V_113 . V_80 ,
V_2 -> V_121 . V_122 -> V_123 , V_2 -> V_124 ) ;
} else {
V_6 = F_92 ( V_90 ,
V_2 -> V_30 . V_113 . V_79 ,
V_2 -> V_30 . V_113 . V_80 , V_115 . V_117 . V_79 ,
V_115 . V_117 . V_80 , V_2 -> V_121 . V_122 -> V_123 ,
V_2 -> V_124 ) ;
}
if ( V_6 ) {
F_27 ( L_9 ) ;
return - V_50 ;
}
}
V_48 -> V_113 = V_115 . V_117 ;
F_4 ( V_38 , V_2 ) ;
return 0 ;
}
static int F_93 ( void * V_28 , struct V_13 * V_125 ,
struct V_13 * V_126 )
{
struct V_1 * V_2 = V_28 ;
int V_6 ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_125 -> type = V_89 ;
V_125 -> V_127 = V_128 | V_129 | V_130 ;
V_125 -> V_16 = V_2 ;
V_125 -> V_131 = & V_132 ;
V_125 -> V_133 = & V_134 ;
V_125 -> V_135 = sizeof( struct V_136 ) ;
V_125 -> V_137 = V_138 ;
V_6 = F_94 ( V_125 ) ;
if ( V_6 )
return V_6 ;
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
V_126 -> type = V_81 ;
V_126 -> V_127 = V_128 | V_129 | V_130 ;
V_126 -> V_16 = V_2 ;
V_126 -> V_131 = & V_132 ;
V_126 -> V_133 = & V_134 ;
V_126 -> V_135 = sizeof( struct V_136 ) ;
V_126 -> V_137 = V_138 ;
return F_94 ( V_126 ) ;
}
static int F_95 ( struct V_54 * V_54 )
{
struct V_4 * V_5 = F_96 ( V_54 ) ;
struct V_1 * V_2 = NULL ;
int V_6 ;
F_25 ( L_10 , F_97 ( V_139 ) , V_5 -> V_37 ) ;
if ( F_98 ( & V_5 -> V_140 ) )
return - V_141 ;
V_2 = F_99 ( sizeof( * V_2 ) , V_142 ) ;
if ( ! V_2 ) {
V_6 = - V_143 ;
goto V_144;
}
F_100 ( & V_2 -> V_55 , V_5 -> V_7 . V_145 ) ;
V_6 = F_101 ( V_2 ) ;
if ( V_6 )
goto V_146;
V_2 -> V_55 . V_147 = & V_2 -> V_147 ;
V_54 -> V_148 = & V_2 -> V_55 ;
F_102 ( & V_2 -> V_55 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_30 . V_43 = F_103 ( 0 ) ;
V_2 -> V_31 . V_43 = F_103 ( 0 ) ;
V_2 -> V_37 = V_149 ;
V_2 -> V_33 = 0 ;
V_2 -> V_150 = V_151 ;
V_2 -> V_124 = V_151 ;
V_2 -> V_24 = F_104 ( V_5 -> V_7 . V_8 , V_2 , F_93 ) ;
if ( F_52 ( V_2 -> V_24 ) ) {
F_27 ( L_11 ) ;
V_6 = F_53 ( V_2 -> V_24 ) ;
goto V_152;
}
if ( V_5 -> V_7 . V_153 ++ == 0 )
F_24 ( V_154 , & V_5 -> V_37 ) ;
F_25 ( L_12 , V_2 ) ;
F_105 ( & V_5 -> V_140 ) ;
return 0 ;
V_152:
F_106 ( V_2 ) ;
V_146:
F_107 ( & V_2 -> V_55 ) ;
F_108 ( & V_2 -> V_55 ) ;
F_109 ( V_2 ) ;
V_144:
F_105 ( & V_5 -> V_140 ) ;
return V_6 ;
}
static int F_110 ( struct V_54 * V_54 )
{
struct V_1 * V_2 = F_60 ( V_54 -> V_148 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_25 ( L_13 ,
F_97 ( V_139 ) , V_5 -> V_37 , V_5 -> V_7 . V_153 ) ;
F_111 ( & V_5 -> V_140 ) ;
F_112 ( V_2 -> V_24 ) ;
F_106 ( V_2 ) ;
F_107 ( & V_2 -> V_55 ) ;
F_108 ( & V_2 -> V_55 ) ;
if ( -- V_5 -> V_7 . V_153 <= 0 )
F_113 ( V_154 , & V_5 -> V_37 ) ;
F_109 ( V_2 ) ;
F_105 ( & V_5 -> V_140 ) ;
return 0 ;
}
static unsigned int F_114 ( struct V_54 * V_54 ,
struct V_155 * V_156 )
{
struct V_1 * V_2 = F_60 ( V_54 -> V_148 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_98 ( & V_5 -> V_140 ) )
return - V_141 ;
V_6 = F_115 ( V_54 , V_2 -> V_24 , V_156 ) ;
F_105 ( & V_5 -> V_140 ) ;
return V_6 ;
}
static int F_116 ( struct V_54 * V_54 , struct V_157 * V_158 )
{
struct V_1 * V_2 = F_60 ( V_54 -> V_148 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_98 ( & V_5 -> V_140 ) )
return - V_141 ;
V_6 = F_117 ( V_54 , V_2 -> V_24 , V_158 ) ;
F_105 ( & V_5 -> V_140 ) ;
return V_6 ;
}
int F_118 ( struct V_4 * V_5 )
{
struct V_159 * V_17 ;
int V_6 ;
if ( ! V_5 )
return - V_160 ;
V_17 = V_5 -> V_17 ;
V_5 -> V_161 . V_162 = & V_163 ;
V_5 -> V_161 . V_164 = & V_165 ;
V_5 -> V_161 . V_166 = V_167 ;
V_5 -> V_161 . V_140 = & V_5 -> V_140 ;
V_5 -> V_161 . V_168 = V_169 ;
snprintf ( V_5 -> V_161 . V_59 , sizeof( V_5 -> V_161 . V_59 ) , L_14 ,
V_170 , V_5 -> V_171 ) ;
F_119 ( & V_5 -> V_161 , V_5 ) ;
V_5 -> V_7 . V_145 = & V_5 -> V_161 ;
V_5 -> V_7 . V_8 = F_120 ( & V_172 ) ;
if ( F_52 ( V_5 -> V_7 . V_8 ) ) {
F_121 ( & V_17 -> V_18 , L_15 ) ;
V_6 = F_53 ( V_5 -> V_7 . V_8 ) ;
goto V_173;
}
V_6 = F_122 ( & V_5 -> V_161 , V_174 , - 1 ) ;
if ( V_6 ) {
F_121 ( & V_17 -> V_18 ,
L_16 , V_175 ) ;
goto V_176;
}
F_25 ( L_17 , V_5 -> V_161 . V_177 ) ;
return 0 ;
V_176:
F_123 ( V_5 -> V_7 . V_8 ) ;
V_173:
F_124 ( V_5 -> V_7 . V_145 ) ;
return V_6 ;
}
void F_125 ( struct V_4 * V_5 )
{
if ( V_5 )
F_123 ( V_5 -> V_7 . V_8 ) ;
}
