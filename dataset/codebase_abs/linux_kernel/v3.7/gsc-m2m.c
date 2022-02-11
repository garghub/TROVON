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
struct V_21 * V_29 = NULL ;
int V_6 ;
V_27 = & V_2 -> V_27 ;
V_28 = & V_2 -> V_28 ;
V_29 = F_18 ( V_2 -> V_24 ) ;
V_6 = F_19 ( V_2 , V_29 , V_27 , & V_27 -> V_30 ) ;
if ( V_6 )
return V_6 ;
V_29 = F_20 ( V_2 -> V_24 ) ;
return F_19 ( V_2 , V_29 , V_28 , & V_28 -> V_30 ) ;
}
static void F_21 ( void * V_25 )
{
struct V_1 * V_2 = V_25 ;
struct V_4 * V_5 ;
unsigned long V_31 ;
T_1 V_6 ;
bool V_32 = false ;
if ( F_22 ( ! V_2 , L_1 ) )
return;
V_5 = V_2 -> V_4 ;
F_23 ( & V_5 -> V_33 , V_31 ) ;
F_24 ( V_34 , & V_5 -> V_35 ) ;
if ( V_5 -> V_7 . V_2 != V_2 ) {
F_25 ( L_2 ,
V_5 -> V_7 . V_2 , V_2 ) ;
V_2 -> V_35 |= V_36 ;
V_5 -> V_7 . V_2 = V_2 ;
}
V_32 = ( V_2 -> V_35 & V_9 ) ? 1 : 0 ;
V_2 -> V_35 &= ~ V_9 ;
if ( V_32 ) {
F_26 ( & V_5 -> V_10 ) ;
goto V_37;
}
V_6 = F_17 ( V_2 ) ;
if ( V_6 ) {
F_27 ( L_3 ) ;
goto V_37;
}
F_28 ( V_5 , & V_2 -> V_27 ) ;
F_29 ( V_5 , & V_2 -> V_27 . V_30 , V_38 ) ;
F_30 ( V_5 , & V_2 -> V_28 . V_30 , V_38 ) ;
if ( V_2 -> V_35 & V_36 ) {
F_31 ( V_5 , V_38 , false ) ;
F_32 ( V_5 , V_38 , false ) ;
F_33 ( V_5 , false ) ;
F_34 ( V_5 , true ) ;
if ( F_35 ( V_2 ) ) {
F_27 ( L_4 ) ;
goto V_37;
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
V_2 -> V_35 &= ~ V_36 ;
F_47 ( V_5 , true ) ;
F_48 ( & V_5 -> V_33 , V_31 ) ;
return;
V_37:
V_2 -> V_35 &= ~ V_36 ;
F_48 ( & V_5 -> V_33 , V_31 ) ;
}
static int F_49 ( struct V_13 * V_39 ,
const struct V_40 * V_41 ,
unsigned int * V_42 , unsigned int * V_43 ,
unsigned int V_44 [] , void * V_45 [] )
{
struct V_1 * V_2 = F_50 ( V_39 ) ;
struct V_26 * V_46 ;
int V_47 ;
V_46 = F_51 ( V_2 , V_39 -> type ) ;
if ( F_52 ( V_46 ) )
return F_53 ( V_46 ) ;
if ( ! V_46 -> V_41 )
return - V_48 ;
* V_43 = V_46 -> V_41 -> V_43 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_41 -> V_43 ; V_47 ++ ) {
V_44 [ V_47 ] = V_46 -> V_49 [ V_47 ] ;
V_45 [ V_47 ] = V_2 -> V_4 -> V_50 ;
}
return 0 ;
}
static int F_54 ( struct V_21 * V_29 )
{
struct V_1 * V_2 = F_50 ( V_29 -> V_13 ) ;
struct V_26 * V_46 ;
int V_47 ;
V_46 = F_51 ( V_2 , V_29 -> V_13 -> type ) ;
if ( F_52 ( V_46 ) )
return F_53 ( V_46 ) ;
if ( ! F_55 ( V_29 -> V_13 -> type ) ) {
for ( V_47 = 0 ; V_47 < V_46 -> V_41 -> V_43 ; V_47 ++ )
F_56 ( V_29 , V_47 , V_46 -> V_49 [ V_47 ] ) ;
}
return 0 ;
}
static void F_57 ( struct V_21 * V_29 )
{
struct V_1 * V_2 = F_50 ( V_29 -> V_13 ) ;
F_25 ( L_5 , V_2 , V_2 -> V_35 ) ;
if ( V_2 -> V_24 )
F_58 ( V_2 -> V_24 , V_29 ) ;
}
static int F_59 ( struct V_51 * V_51 , void * V_52 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_61 ( V_54 -> V_55 , V_5 -> V_17 -> V_56 , sizeof( V_54 -> V_55 ) ) ;
F_61 ( V_54 -> V_57 , V_5 -> V_17 -> V_56 , sizeof( V_54 -> V_57 ) ) ;
F_61 ( V_54 -> V_58 , L_6 , sizeof( V_54 -> V_58 ) ) ;
V_54 -> V_59 = V_60 | V_61 |
V_62 | V_63 ;
V_54 -> V_64 = V_54 -> V_59 | V_65 ;
return 0 ;
}
static int F_62 ( struct V_51 * V_51 , void * V_25 ,
struct V_66 * V_67 )
{
return F_63 ( V_67 ) ;
}
static int F_64 ( struct V_51 * V_51 , void * V_52 ,
struct V_40 * V_67 )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
return F_65 ( V_2 , V_67 ) ;
}
static int F_66 ( struct V_51 * V_51 , void * V_52 ,
struct V_40 * V_67 )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
return F_67 ( V_2 , V_67 ) ;
}
static int F_68 ( struct V_51 * V_51 , void * V_52 ,
struct V_40 * V_67 )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
struct V_13 * V_39 ;
struct V_26 * V_46 ;
struct V_68 * V_69 ;
int V_47 , V_6 = 0 ;
V_6 = F_66 ( V_51 , V_52 , V_67 ) ;
if ( V_6 )
return V_6 ;
V_39 = F_69 ( V_2 -> V_24 , V_67 -> type ) ;
if ( F_70 ( V_39 ) ) {
F_27 ( L_7 , V_67 -> type ) ;
return - V_70 ;
}
if ( F_55 ( V_67 -> type ) )
V_46 = & V_2 -> V_27 ;
else
V_46 = & V_2 -> V_28 ;
V_69 = & V_67 -> V_41 . V_71 ;
V_46 -> V_41 = F_71 ( & V_69 -> V_72 , NULL , 0 ) ;
V_46 -> V_73 = V_69 -> V_73 ;
if ( ! V_46 -> V_41 )
return - V_48 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_41 -> V_43 ; V_47 ++ )
V_46 -> V_49 [ V_47 ] = V_69 -> V_74 [ V_47 ] . V_75 ;
F_72 ( V_46 , V_69 -> V_76 , V_69 -> V_77 ) ;
if ( V_67 -> type == V_78 )
F_4 ( V_36 | V_79 , V_2 ) ;
else
F_4 ( V_36 | V_80 , V_2 ) ;
F_25 ( L_8 , V_46 -> V_81 , V_46 -> V_82 ) ;
return 0 ;
}
static int F_73 ( struct V_51 * V_51 , void * V_52 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
struct V_26 * V_46 ;
T_1 V_85 ;
V_85 = ( V_84 -> type == V_86 ) ?
V_5 -> V_87 -> V_88 : V_5 -> V_87 -> V_89 ;
if ( V_84 -> V_15 > V_85 ) {
return - V_48 ;
} else if ( V_84 -> V_15 == 0 ) {
if ( V_84 -> type == V_86 )
F_74 ( V_80 , V_2 ) ;
else
F_74 ( V_79 , V_2 ) ;
}
V_46 = F_51 ( V_2 , V_84 -> type ) ;
return F_75 ( V_51 , V_2 -> V_24 , V_84 ) ;
}
static int F_76 ( struct V_51 * V_51 , void * V_52 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
return F_77 ( V_51 , V_2 -> V_24 , V_91 ) ;
}
static int F_78 ( struct V_51 * V_51 , void * V_52 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
return F_79 ( V_51 , V_2 -> V_24 , V_91 ) ;
}
static int F_80 ( struct V_51 * V_51 , void * V_52 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
return F_81 ( V_51 , V_2 -> V_24 , V_91 ) ;
}
static int F_82 ( struct V_51 * V_51 , void * V_52 ,
enum V_92 type )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
if ( F_55 ( type ) ) {
if ( ! F_6 ( V_80 , V_2 ) )
return - V_48 ;
} else if ( ! F_6 ( V_79 , V_2 ) ) {
return - V_48 ;
}
return F_83 ( V_51 , V_2 -> V_24 , type ) ;
}
static int F_84 ( struct V_51 * V_51 , void * V_52 ,
enum V_92 type )
{
struct V_1 * V_2 = F_60 ( V_52 ) ;
return F_85 ( V_51 , V_2 -> V_24 , type ) ;
}
static int F_86 ( struct V_93 * V_94 , struct V_93 * V_95 )
{
if ( V_94 -> V_96 < V_95 -> V_96 || V_94 -> V_97 < V_95 -> V_97 )
return 0 ;
if ( V_94 -> V_96 + V_94 -> V_76 > V_95 -> V_96 + V_95 -> V_76 )
return 0 ;
if ( V_94 -> V_97 + V_94 -> V_77 > V_95 -> V_97 + V_95 -> V_77 )
return 0 ;
return 1 ;
}
static int F_87 ( struct V_51 * V_51 , void * V_52 ,
struct V_98 * V_99 )
{
struct V_26 * V_46 ;
struct V_1 * V_2 = F_60 ( V_52 ) ;
if ( ( V_99 -> type != V_78 ) &&
( V_99 -> type != V_86 ) )
return - V_48 ;
V_46 = F_51 ( V_2 , V_99 -> type ) ;
if ( F_52 ( V_46 ) )
return F_53 ( V_46 ) ;
switch ( V_99 -> V_100 ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_99 -> V_105 . V_96 = 0 ;
V_99 -> V_105 . V_97 = 0 ;
V_99 -> V_105 . V_76 = V_46 -> V_81 ;
V_99 -> V_105 . V_77 = V_46 -> V_82 ;
return 0 ;
case V_106 :
case V_107 :
V_99 -> V_105 . V_96 = V_46 -> V_108 . V_96 ;
V_99 -> V_105 . V_97 = V_46 -> V_108 . V_97 ;
V_99 -> V_105 . V_76 = V_46 -> V_108 . V_76 ;
V_99 -> V_105 . V_77 = V_46 -> V_108 . V_77 ;
return 0 ;
}
return - V_48 ;
}
static int F_88 ( struct V_51 * V_51 , void * V_52 ,
struct V_98 * V_99 )
{
struct V_26 * V_46 ;
struct V_1 * V_2 = F_60 ( V_52 ) ;
struct V_109 V_110 ;
struct V_111 * V_87 = V_2 -> V_4 -> V_87 ;
int V_6 ;
V_110 . type = V_99 -> type ;
V_110 . V_112 = V_99 -> V_105 ;
if ( ( V_99 -> type != V_78 ) &&
( V_99 -> type != V_86 ) )
return - V_48 ;
V_6 = F_89 ( V_2 , & V_110 ) ;
if ( V_6 )
return V_6 ;
if ( V_99 -> V_31 & V_113 &&
! F_86 ( & V_110 . V_112 , & V_99 -> V_105 ) )
return - V_114 ;
if ( V_99 -> V_31 & V_115 &&
! F_86 ( & V_99 -> V_105 , & V_110 . V_112 ) )
return - V_114 ;
V_99 -> V_105 = V_110 . V_112 ;
switch ( V_99 -> V_100 ) {
case V_102 :
case V_101 :
case V_106 :
V_46 = & V_2 -> V_27 ;
break;
case V_103 :
case V_107 :
case V_104 :
V_46 = & V_2 -> V_28 ;
break;
default:
return - V_48 ;
}
if ( F_6 ( V_79 | V_80 , V_2 ) ) {
if ( V_99 -> type == V_86 ) {
V_6 = F_90 ( V_87 , V_110 . V_112 . V_76 ,
V_110 . V_112 . V_77 , V_2 -> V_28 . V_108 . V_76 ,
V_2 -> V_28 . V_108 . V_77 ,
V_2 -> V_116 . V_117 -> V_118 , V_2 -> V_119 ) ;
} else {
V_6 = F_90 ( V_87 ,
V_2 -> V_27 . V_108 . V_76 ,
V_2 -> V_27 . V_108 . V_77 , V_110 . V_112 . V_76 ,
V_110 . V_112 . V_77 , V_2 -> V_116 . V_117 -> V_118 ,
V_2 -> V_119 ) ;
}
if ( V_6 ) {
F_27 ( L_9 ) ;
return - V_48 ;
}
}
V_46 -> V_108 = V_110 . V_112 ;
F_4 ( V_36 , V_2 ) ;
return 0 ;
}
static int F_91 ( void * V_25 , struct V_13 * V_120 ,
struct V_13 * V_121 )
{
struct V_1 * V_2 = V_25 ;
int V_6 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
V_120 -> type = V_86 ;
V_120 -> V_122 = V_123 | V_124 ;
V_120 -> V_16 = V_2 ;
V_120 -> V_125 = & V_126 ;
V_120 -> V_127 = & V_128 ;
V_120 -> V_129 = sizeof( struct V_130 ) ;
V_6 = F_92 ( V_120 ) ;
if ( V_6 )
return V_6 ;
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_121 -> type = V_78 ;
V_121 -> V_122 = V_123 | V_124 ;
V_121 -> V_16 = V_2 ;
V_121 -> V_125 = & V_126 ;
V_121 -> V_127 = & V_128 ;
V_121 -> V_129 = sizeof( struct V_130 ) ;
return F_92 ( V_121 ) ;
}
static int F_93 ( struct V_51 * V_51 )
{
struct V_4 * V_5 = F_94 ( V_51 ) ;
struct V_1 * V_2 = NULL ;
int V_6 ;
F_25 ( L_10 , F_95 ( V_131 ) , V_5 -> V_35 ) ;
if ( F_96 ( & V_5 -> V_132 ) )
return - V_133 ;
V_2 = F_97 ( sizeof ( * V_2 ) , V_134 ) ;
if ( ! V_2 ) {
V_6 = - V_135 ;
goto V_136;
}
F_98 ( & V_2 -> V_52 , V_5 -> V_7 . V_137 ) ;
V_6 = F_99 ( V_2 ) ;
if ( V_6 )
goto V_138;
V_2 -> V_52 . V_139 = & V_2 -> V_139 ;
V_51 -> V_140 = & V_2 -> V_52 ;
F_100 ( & V_2 -> V_52 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_27 . V_41 = F_101 ( 0 ) ;
V_2 -> V_28 . V_41 = F_101 ( 0 ) ;
V_2 -> V_35 = V_141 ;
V_2 -> V_31 = 0 ;
V_2 -> V_142 = V_143 ;
V_2 -> V_119 = V_143 ;
V_2 -> V_24 = F_102 ( V_5 -> V_7 . V_8 , V_2 , F_91 ) ;
if ( F_52 ( V_2 -> V_24 ) ) {
F_27 ( L_11 ) ;
V_6 = F_53 ( V_2 -> V_24 ) ;
goto V_144;
}
if ( V_5 -> V_7 . V_145 ++ == 0 )
F_24 ( V_146 , & V_5 -> V_35 ) ;
F_25 ( L_12 , V_2 ) ;
F_103 ( & V_5 -> V_132 ) ;
return 0 ;
V_144:
F_104 ( V_2 ) ;
V_138:
F_105 ( & V_2 -> V_52 ) ;
F_106 ( & V_2 -> V_52 ) ;
F_107 ( V_2 ) ;
V_136:
F_103 ( & V_5 -> V_132 ) ;
return V_6 ;
}
static int F_108 ( struct V_51 * V_51 )
{
struct V_1 * V_2 = F_60 ( V_51 -> V_140 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_25 ( L_13 ,
F_95 ( V_131 ) , V_5 -> V_35 , V_5 -> V_7 . V_145 ) ;
F_109 ( & V_5 -> V_132 ) ;
F_110 ( V_2 -> V_24 ) ;
F_104 ( V_2 ) ;
F_105 ( & V_2 -> V_52 ) ;
F_106 ( & V_2 -> V_52 ) ;
if ( -- V_5 -> V_7 . V_145 <= 0 )
F_111 ( V_146 , & V_5 -> V_35 ) ;
F_107 ( V_2 ) ;
F_103 ( & V_5 -> V_132 ) ;
return 0 ;
}
static unsigned int F_112 ( struct V_51 * V_51 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_60 ( V_51 -> V_140 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_96 ( & V_5 -> V_132 ) )
return - V_133 ;
V_6 = F_113 ( V_51 , V_2 -> V_24 , V_148 ) ;
F_103 ( & V_5 -> V_132 ) ;
return V_6 ;
}
static int F_114 ( struct V_51 * V_51 , struct V_149 * V_150 )
{
struct V_1 * V_2 = F_60 ( V_51 -> V_140 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_96 ( & V_5 -> V_132 ) )
return - V_133 ;
V_6 = F_115 ( V_51 , V_2 -> V_24 , V_150 ) ;
F_103 ( & V_5 -> V_132 ) ;
return V_6 ;
}
int F_116 ( struct V_4 * V_5 )
{
struct V_151 * V_17 ;
int V_6 ;
if ( ! V_5 )
return - V_152 ;
V_17 = V_5 -> V_17 ;
V_5 -> V_153 . V_154 = & V_155 ;
V_5 -> V_153 . V_156 = & V_157 ;
V_5 -> V_153 . V_158 = V_159 ;
V_5 -> V_153 . V_132 = & V_5 -> V_132 ;
V_5 -> V_153 . V_160 = V_161 ;
snprintf ( V_5 -> V_153 . V_56 , sizeof( V_5 -> V_153 . V_56 ) , L_14 ,
V_162 , V_5 -> V_163 ) ;
F_117 ( & V_5 -> V_153 , V_5 ) ;
V_5 -> V_7 . V_137 = & V_5 -> V_153 ;
V_5 -> V_7 . V_8 = F_118 ( & V_164 ) ;
if ( F_52 ( V_5 -> V_7 . V_8 ) ) {
F_119 ( & V_17 -> V_18 , L_15 ) ;
V_6 = F_53 ( V_5 -> V_7 . V_8 ) ;
goto V_165;
}
V_6 = F_120 ( & V_5 -> V_153 , V_166 , - 1 ) ;
if ( V_6 ) {
F_119 ( & V_17 -> V_18 ,
L_16 , V_167 ) ;
goto V_168;
}
F_25 ( L_17 , V_5 -> V_153 . V_169 ) ;
return 0 ;
V_168:
F_121 ( V_5 -> V_7 . V_8 ) ;
V_165:
F_122 ( V_5 -> V_7 . V_137 ) ;
return V_6 ;
}
void F_123 ( struct V_4 * V_5 )
{
if ( V_5 )
F_121 ( V_5 -> V_7 . V_8 ) ;
}
