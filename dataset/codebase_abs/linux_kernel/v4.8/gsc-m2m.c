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
V_25 -> V_27 . V_28 = V_24 -> V_27 . V_28 ;
V_25 -> V_29 = V_24 -> V_29 ;
V_25 -> V_30 &= ~ V_31 ;
V_25 -> V_30 |=
V_24 -> V_30
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
V_6 = F_21 ( V_2 , & V_24 -> V_27 , V_34 , & V_34 -> V_36 ) ;
if ( V_6 )
return V_6 ;
V_25 = F_22 ( V_2 -> V_26 ) ;
V_6 = F_21 ( V_2 , & V_25 -> V_27 , V_35 , & V_35 -> V_36 ) ;
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
unsigned int * V_44 , unsigned int * V_45 ,
unsigned int V_46 [] , struct V_47 * V_48 [] )
{
struct V_1 * V_2 = F_52 ( V_43 ) ;
struct V_33 * V_49 ;
int V_50 ;
V_49 = F_53 ( V_2 , V_43 -> type ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
if ( ! V_49 -> V_51 )
return - V_52 ;
* V_45 = V_49 -> V_51 -> V_45 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_51 -> V_45 ; V_50 ++ )
V_46 [ V_50 ] = V_49 -> V_53 [ V_50 ] ;
return 0 ;
}
static int F_56 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_52 ( V_55 -> V_16 ) ;
struct V_33 * V_49 ;
int V_50 ;
V_49 = F_53 ( V_2 , V_55 -> V_16 -> type ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
if ( ! F_57 ( V_55 -> V_16 -> type ) ) {
for ( V_50 = 0 ; V_50 < V_49 -> V_51 -> V_45 ; V_50 ++ )
F_58 ( V_55 , V_50 , V_49 -> V_53 [ V_50 ] ) ;
}
return 0 ;
}
static void F_59 ( struct V_54 * V_55 )
{
struct V_23 * V_56 = F_60 ( V_55 ) ;
struct V_1 * V_2 = F_52 ( V_55 -> V_16 ) ;
F_27 ( L_5 , V_2 , V_2 -> V_13 ) ;
if ( V_2 -> V_26 )
F_61 ( V_2 -> V_26 , V_56 ) ;
}
static int F_62 ( struct V_57 * V_57 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_64 ( V_60 -> V_61 , V_5 -> V_20 -> V_62 , sizeof( V_60 -> V_61 ) ) ;
F_64 ( V_60 -> V_63 , V_5 -> V_20 -> V_62 , sizeof( V_60 -> V_63 ) ) ;
F_64 ( V_60 -> V_64 , L_6 , sizeof( V_60 -> V_64 ) ) ;
V_60 -> V_65 = V_66 | V_67 |
V_68 | V_69 ;
V_60 -> V_70 = V_60 -> V_65 | V_71 ;
return 0 ;
}
static int F_65 ( struct V_57 * V_57 , void * V_32 ,
struct V_72 * V_73 )
{
return F_66 ( V_73 ) ;
}
static int F_67 ( struct V_57 * V_57 , void * V_58 ,
struct V_74 * V_73 )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
return F_68 ( V_2 , V_73 ) ;
}
static int F_69 ( struct V_57 * V_57 , void * V_58 ,
struct V_74 * V_73 )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
return F_70 ( V_2 , V_73 ) ;
}
static int F_71 ( struct V_57 * V_57 , void * V_58 ,
struct V_74 * V_73 )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
struct V_16 * V_43 ;
struct V_33 * V_49 ;
struct V_75 * V_76 ;
int V_50 , V_6 = 0 ;
V_6 = F_69 ( V_57 , V_58 , V_73 ) ;
if ( V_6 )
return V_6 ;
V_43 = F_72 ( V_2 -> V_26 , V_73 -> type ) ;
if ( F_73 ( V_43 ) ) {
F_29 ( L_7 , V_73 -> type ) ;
return - V_77 ;
}
if ( F_57 ( V_73 -> type ) )
V_49 = & V_2 -> V_34 ;
else
V_49 = & V_2 -> V_35 ;
V_76 = & V_73 -> V_51 . V_78 ;
V_49 -> V_51 = F_74 ( & V_76 -> V_79 , NULL , 0 ) ;
V_49 -> V_80 = V_76 -> V_80 ;
if ( ! V_49 -> V_51 )
return - V_52 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_51 -> V_45 ; V_50 ++ )
V_49 -> V_53 [ V_50 ] = V_76 -> V_81 [ V_50 ] . V_82 ;
F_75 ( V_49 , V_76 -> V_83 , V_76 -> V_84 ) ;
if ( V_73 -> type == V_85 )
F_4 ( V_40 | V_86 , V_2 ) ;
else
F_4 ( V_40 | V_87 , V_2 ) ;
F_27 ( L_8 , V_49 -> V_88 , V_49 -> V_89 ) ;
return 0 ;
}
static int F_76 ( struct V_57 * V_57 , void * V_58 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
T_1 V_92 ;
V_92 = ( V_91 -> type == V_93 ) ?
V_5 -> V_94 -> V_95 : V_5 -> V_94 -> V_96 ;
if ( V_91 -> V_18 > V_92 ) {
return - V_52 ;
} else if ( V_91 -> V_18 == 0 ) {
if ( V_91 -> type == V_93 )
F_8 ( V_87 , V_2 ) ;
else
F_8 ( V_86 , V_2 ) ;
}
return F_77 ( V_57 , V_2 -> V_26 , V_91 ) ;
}
static int F_78 ( struct V_57 * V_57 , void * V_58 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
return F_79 ( V_57 , V_2 -> V_26 , V_98 ) ;
}
static int F_80 ( struct V_57 * V_57 , void * V_58 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
return F_81 ( V_57 , V_2 -> V_26 , V_100 ) ;
}
static int F_82 ( struct V_57 * V_57 , void * V_58 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
return F_83 ( V_57 , V_2 -> V_26 , V_100 ) ;
}
static int F_84 ( struct V_57 * V_57 , void * V_58 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
return F_85 ( V_57 , V_2 -> V_26 , V_100 ) ;
}
static int F_86 ( struct V_57 * V_57 , void * V_58 ,
enum V_101 type )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
if ( F_57 ( type ) ) {
if ( ! F_6 ( V_87 , V_2 ) )
return - V_52 ;
} else if ( ! F_6 ( V_86 , V_2 ) ) {
return - V_52 ;
}
return F_87 ( V_57 , V_2 -> V_26 , type ) ;
}
static int F_88 ( struct V_57 * V_57 , void * V_58 ,
enum V_101 type )
{
struct V_1 * V_2 = F_63 ( V_58 ) ;
return F_89 ( V_57 , V_2 -> V_26 , type ) ;
}
static int F_90 ( struct V_102 * V_103 , struct V_102 * V_104 )
{
if ( V_103 -> V_105 < V_104 -> V_105 || V_103 -> V_106 < V_104 -> V_106 )
return 0 ;
if ( V_103 -> V_105 + V_103 -> V_83 > V_104 -> V_105 + V_104 -> V_83 )
return 0 ;
if ( V_103 -> V_106 + V_103 -> V_84 > V_104 -> V_106 + V_104 -> V_84 )
return 0 ;
return 1 ;
}
static int F_91 ( struct V_57 * V_57 , void * V_58 ,
struct V_107 * V_108 )
{
struct V_33 * V_49 ;
struct V_1 * V_2 = F_63 ( V_58 ) ;
if ( ( V_108 -> type != V_85 ) &&
( V_108 -> type != V_93 ) )
return - V_52 ;
V_49 = F_53 ( V_2 , V_108 -> type ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
switch ( V_108 -> V_109 ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_108 -> V_114 . V_105 = 0 ;
V_108 -> V_114 . V_106 = 0 ;
V_108 -> V_114 . V_83 = V_49 -> V_88 ;
V_108 -> V_114 . V_84 = V_49 -> V_89 ;
return 0 ;
case V_115 :
case V_116 :
V_108 -> V_114 . V_105 = V_49 -> V_117 . V_105 ;
V_108 -> V_114 . V_106 = V_49 -> V_117 . V_106 ;
V_108 -> V_114 . V_83 = V_49 -> V_117 . V_83 ;
V_108 -> V_114 . V_84 = V_49 -> V_117 . V_84 ;
return 0 ;
}
return - V_52 ;
}
static int F_92 ( struct V_57 * V_57 , void * V_58 ,
struct V_107 * V_108 )
{
struct V_33 * V_49 ;
struct V_1 * V_2 = F_63 ( V_58 ) ;
struct V_118 V_119 ;
struct V_120 * V_94 = V_2 -> V_4 -> V_94 ;
int V_6 ;
V_119 . type = V_108 -> type ;
V_119 . V_121 = V_108 -> V_114 ;
if ( ( V_108 -> type != V_85 ) &&
( V_108 -> type != V_93 ) )
return - V_52 ;
V_6 = F_93 ( V_2 , & V_119 ) ;
if ( V_6 )
return V_6 ;
if ( V_108 -> V_30 & V_122 &&
! F_90 ( & V_119 . V_121 , & V_108 -> V_114 ) )
return - V_123 ;
if ( V_108 -> V_30 & V_124 &&
! F_90 ( & V_108 -> V_114 , & V_119 . V_121 ) )
return - V_123 ;
V_108 -> V_114 = V_119 . V_121 ;
switch ( V_108 -> V_109 ) {
case V_111 :
case V_110 :
case V_115 :
V_49 = & V_2 -> V_34 ;
break;
case V_112 :
case V_116 :
case V_113 :
V_49 = & V_2 -> V_35 ;
break;
default:
return - V_52 ;
}
if ( F_6 ( V_86 | V_87 , V_2 ) ) {
if ( V_108 -> type == V_93 ) {
V_6 = F_94 ( V_94 , V_119 . V_121 . V_83 ,
V_119 . V_121 . V_84 , V_2 -> V_35 . V_117 . V_83 ,
V_2 -> V_35 . V_117 . V_84 ,
V_2 -> V_125 . V_126 -> V_127 , V_2 -> V_128 ) ;
} else {
V_6 = F_94 ( V_94 ,
V_2 -> V_34 . V_117 . V_83 ,
V_2 -> V_34 . V_117 . V_84 , V_119 . V_121 . V_83 ,
V_119 . V_121 . V_84 , V_2 -> V_125 . V_126 -> V_127 ,
V_2 -> V_128 ) ;
}
if ( V_6 ) {
F_29 ( L_9 ) ;
return - V_52 ;
}
}
V_49 -> V_117 = V_119 . V_121 ;
F_4 ( V_40 , V_2 ) ;
return 0 ;
}
static int F_95 ( void * V_32 , struct V_16 * V_129 ,
struct V_16 * V_130 )
{
struct V_1 * V_2 = V_32 ;
int V_6 ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
V_129 -> type = V_93 ;
V_129 -> V_131 = V_132 | V_133 | V_134 ;
V_129 -> V_19 = V_2 ;
V_129 -> V_135 = & V_136 ;
V_129 -> V_137 = & V_138 ;
V_129 -> V_139 = sizeof( struct V_140 ) ;
V_129 -> V_141 = V_142 ;
V_129 -> V_143 = & V_2 -> V_4 -> V_143 ;
V_129 -> V_21 = & V_2 -> V_4 -> V_20 -> V_21 ;
V_6 = F_96 ( V_129 ) ;
if ( V_6 )
return V_6 ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
V_130 -> type = V_85 ;
V_130 -> V_131 = V_132 | V_133 | V_134 ;
V_130 -> V_19 = V_2 ;
V_130 -> V_135 = & V_136 ;
V_130 -> V_137 = & V_138 ;
V_130 -> V_139 = sizeof( struct V_140 ) ;
V_130 -> V_141 = V_142 ;
V_130 -> V_143 = & V_2 -> V_4 -> V_143 ;
V_130 -> V_21 = & V_2 -> V_4 -> V_20 -> V_21 ;
return F_96 ( V_130 ) ;
}
static int F_97 ( struct V_57 * V_57 )
{
struct V_4 * V_5 = F_98 ( V_57 ) ;
struct V_1 * V_2 = NULL ;
int V_6 ;
F_27 ( L_10 , F_99 ( V_144 ) , V_5 -> V_13 ) ;
if ( F_100 ( & V_5 -> V_143 ) )
return - V_145 ;
V_2 = F_101 ( sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 ) {
V_6 = - V_147 ;
goto V_148;
}
F_102 ( & V_2 -> V_58 , V_5 -> V_7 . V_149 ) ;
V_6 = F_103 ( V_2 ) ;
if ( V_6 )
goto V_150;
V_2 -> V_58 . V_151 = & V_2 -> V_151 ;
V_57 -> V_152 = & V_2 -> V_58 ;
F_104 ( & V_2 -> V_58 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_34 . V_51 = F_105 ( 0 ) ;
V_2 -> V_35 . V_51 = F_105 ( 0 ) ;
V_2 -> V_13 = V_153 ;
V_2 -> V_30 = 0 ;
V_2 -> V_154 = V_155 ;
V_2 -> V_128 = V_155 ;
V_2 -> V_26 = F_106 ( V_5 -> V_7 . V_8 , V_2 , F_95 ) ;
if ( F_54 ( V_2 -> V_26 ) ) {
F_29 ( L_11 ) ;
V_6 = F_55 ( V_2 -> V_26 ) ;
goto V_156;
}
if ( V_5 -> V_7 . V_157 ++ == 0 )
F_26 ( V_158 , & V_5 -> V_13 ) ;
F_27 ( L_12 , V_2 ) ;
F_107 ( & V_5 -> V_143 ) ;
return 0 ;
V_156:
F_108 ( V_2 ) ;
V_150:
F_109 ( & V_2 -> V_58 ) ;
F_110 ( & V_2 -> V_58 ) ;
F_111 ( V_2 ) ;
V_148:
F_107 ( & V_5 -> V_143 ) ;
return V_6 ;
}
static int F_112 ( struct V_57 * V_57 )
{
struct V_1 * V_2 = F_63 ( V_57 -> V_152 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_27 ( L_13 ,
F_99 ( V_144 ) , V_5 -> V_13 , V_5 -> V_7 . V_157 ) ;
F_113 ( & V_5 -> V_143 ) ;
F_114 ( V_2 -> V_26 ) ;
F_108 ( V_2 ) ;
F_109 ( & V_2 -> V_58 ) ;
F_110 ( & V_2 -> V_58 ) ;
if ( -- V_5 -> V_7 . V_157 <= 0 )
F_115 ( V_158 , & V_5 -> V_13 ) ;
F_111 ( V_2 ) ;
F_107 ( & V_5 -> V_143 ) ;
return 0 ;
}
static unsigned int F_116 ( struct V_57 * V_57 ,
struct V_159 * V_160 )
{
struct V_1 * V_2 = F_63 ( V_57 -> V_152 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
unsigned int V_6 ;
if ( F_100 ( & V_5 -> V_143 ) )
return - V_145 ;
V_6 = F_117 ( V_57 , V_2 -> V_26 , V_160 ) ;
F_107 ( & V_5 -> V_143 ) ;
return V_6 ;
}
static int F_118 ( struct V_57 * V_57 , struct V_161 * V_162 )
{
struct V_1 * V_2 = F_63 ( V_57 -> V_152 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_100 ( & V_5 -> V_143 ) )
return - V_145 ;
V_6 = F_119 ( V_57 , V_2 -> V_26 , V_162 ) ;
F_107 ( & V_5 -> V_143 ) ;
return V_6 ;
}
int F_120 ( struct V_4 * V_5 )
{
struct V_163 * V_20 ;
int V_6 ;
if ( ! V_5 )
return - V_164 ;
V_20 = V_5 -> V_20 ;
V_5 -> V_165 . V_166 = & V_167 ;
V_5 -> V_165 . V_168 = & V_169 ;
V_5 -> V_165 . V_170 = V_171 ;
V_5 -> V_165 . V_143 = & V_5 -> V_143 ;
V_5 -> V_165 . V_172 = V_173 ;
V_5 -> V_165 . V_174 = & V_5 -> V_174 ;
snprintf ( V_5 -> V_165 . V_62 , sizeof( V_5 -> V_165 . V_62 ) , L_14 ,
V_175 , V_5 -> V_176 ) ;
F_121 ( & V_5 -> V_165 , V_5 ) ;
V_5 -> V_7 . V_149 = & V_5 -> V_165 ;
V_5 -> V_7 . V_8 = F_122 ( & V_177 ) ;
if ( F_54 ( V_5 -> V_7 . V_8 ) ) {
F_123 ( & V_20 -> V_21 , L_15 ) ;
V_6 = F_55 ( V_5 -> V_7 . V_8 ) ;
goto V_178;
}
V_6 = F_124 ( & V_5 -> V_165 , V_179 , - 1 ) ;
if ( V_6 ) {
F_123 ( & V_20 -> V_21 ,
L_16 , V_180 ) ;
goto V_181;
}
F_27 ( L_17 , V_5 -> V_165 . V_182 ) ;
return 0 ;
V_181:
F_125 ( V_5 -> V_7 . V_8 ) ;
V_178:
F_126 ( V_5 -> V_7 . V_149 ) ;
return V_6 ;
}
void F_127 ( struct V_4 * V_5 )
{
if ( V_5 )
F_125 ( V_5 -> V_7 . V_8 ) ;
}
