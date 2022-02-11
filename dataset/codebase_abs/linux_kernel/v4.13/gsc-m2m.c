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
static void F_12 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_24 ;
while ( F_13 ( V_2 -> V_25 ) > 0 ) {
V_23 = F_14 ( V_2 -> V_25 ) ;
F_15 ( V_23 , V_15 ) ;
}
while ( F_16 ( V_2 -> V_25 ) > 0 ) {
V_24 = F_17 ( V_2 -> V_25 ) ;
F_15 ( V_24 , V_15 ) ;
}
}
static void F_18 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_19 ;
F_7 ( V_2 ) ;
F_12 ( V_2 ) ;
F_19 ( & V_2 -> V_4 -> V_20 -> V_21 ) ;
}
void F_9 ( struct V_1 * V_2 , int V_26 )
{
struct V_22 * V_23 , * V_24 ;
if ( ! V_2 || ! V_2 -> V_25 )
return;
V_23 = F_14 ( V_2 -> V_25 ) ;
V_24 = F_17 ( V_2 -> V_25 ) ;
if ( V_23 && V_24 ) {
V_24 -> V_27 . V_28 = V_23 -> V_27 . V_28 ;
V_24 -> V_29 = V_23 -> V_29 ;
V_24 -> V_30 &= ~ V_31 ;
V_24 -> V_30 |=
V_23 -> V_30
& V_31 ;
F_15 ( V_23 , V_26 ) ;
F_15 ( V_24 , V_26 ) ;
F_20 ( V_2 -> V_4 -> V_7 . V_8 ,
V_2 -> V_25 ) ;
}
}
static void F_21 ( void * V_32 )
{
F_7 ( (struct V_1 * ) V_32 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_33 * V_34 , * V_35 ;
struct V_22 * V_23 , * V_24 ;
int V_6 ;
V_34 = & V_2 -> V_34 ;
V_35 = & V_2 -> V_35 ;
V_23 = F_23 ( V_2 -> V_25 ) ;
V_6 = F_24 ( V_2 , & V_23 -> V_27 , V_34 , & V_34 -> V_36 ) ;
if ( V_6 )
return V_6 ;
V_24 = F_25 ( V_2 -> V_25 ) ;
V_6 = F_24 ( V_2 , & V_24 -> V_27 , V_35 , & V_35 -> V_36 ) ;
if ( V_6 )
return V_6 ;
V_24 -> V_27 . V_28 = V_23 -> V_27 . V_28 ;
return 0 ;
}
static void F_26 ( void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_4 * V_5 ;
unsigned long V_30 ;
int V_6 ;
bool V_37 = false ;
if ( F_27 ( ! V_2 , L_1 ) )
return;
V_5 = V_2 -> V_4 ;
F_28 ( & V_5 -> V_38 , V_30 ) ;
F_29 ( V_39 , & V_5 -> V_13 ) ;
if ( V_5 -> V_7 . V_2 != V_2 ) {
F_30 ( L_2 ,
V_5 -> V_7 . V_2 , V_2 ) ;
V_2 -> V_13 |= V_40 ;
V_5 -> V_7 . V_2 = V_2 ;
}
V_37 = V_2 -> V_13 & V_9 ;
if ( V_37 ) {
V_2 -> V_13 &= ~ V_9 ;
V_2 -> V_13 |= V_14 ;
F_31 ( & V_5 -> V_10 ) ;
goto V_41;
}
V_6 = F_22 ( V_2 ) ;
if ( V_6 ) {
F_32 ( L_3 ) ;
goto V_41;
}
F_33 ( V_5 , & V_2 -> V_34 ) ;
F_34 ( V_5 , & V_2 -> V_34 . V_36 , V_42 ) ;
F_35 ( V_5 , & V_2 -> V_35 . V_36 , V_42 ) ;
if ( V_2 -> V_13 & V_40 ) {
F_36 ( V_5 , V_42 , false ) ;
F_37 ( V_5 , V_42 , false ) ;
F_38 ( V_5 , false ) ;
F_39 ( V_5 , true ) ;
if ( F_40 ( V_2 ) ) {
F_32 ( L_4 ) ;
goto V_41;
}
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
}
F_51 ( V_2 ) ;
V_2 -> V_13 &= ~ V_40 ;
F_52 ( V_5 , true ) ;
F_53 ( & V_5 -> V_38 , V_30 ) ;
return;
V_41:
V_2 -> V_13 &= ~ V_40 ;
F_53 ( & V_5 -> V_38 , V_30 ) ;
}
static int F_54 ( struct V_16 * V_43 ,
unsigned int * V_44 , unsigned int * V_45 ,
unsigned int V_46 [] , struct V_47 * V_48 [] )
{
struct V_1 * V_2 = F_55 ( V_43 ) ;
struct V_33 * V_49 ;
int V_50 ;
V_49 = F_56 ( V_2 , V_43 -> type ) ;
if ( F_57 ( V_49 ) )
return F_58 ( V_49 ) ;
if ( ! V_49 -> V_51 )
return - V_52 ;
* V_45 = V_49 -> V_51 -> V_45 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_51 -> V_45 ; V_50 ++ )
V_46 [ V_50 ] = V_49 -> V_53 [ V_50 ] ;
return 0 ;
}
static int F_59 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_55 ( V_55 -> V_16 ) ;
struct V_33 * V_49 ;
int V_50 ;
V_49 = F_56 ( V_2 , V_55 -> V_16 -> type ) ;
if ( F_57 ( V_49 ) )
return F_58 ( V_49 ) ;
if ( ! F_60 ( V_55 -> V_16 -> type ) ) {
for ( V_50 = 0 ; V_50 < V_49 -> V_51 -> V_45 ; V_50 ++ )
F_61 ( V_55 , V_50 , V_49 -> V_53 [ V_50 ] ) ;
}
return 0 ;
}
static void F_62 ( struct V_54 * V_55 )
{
struct V_22 * V_56 = F_63 ( V_55 ) ;
struct V_1 * V_2 = F_55 ( V_55 -> V_16 ) ;
F_30 ( L_5 , V_2 , V_2 -> V_13 ) ;
if ( V_2 -> V_25 )
F_64 ( V_2 -> V_25 , V_56 ) ;
}
static int F_65 ( struct V_57 * V_57 , void * V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_67 ( V_60 -> V_61 , V_62 , sizeof( V_60 -> V_61 ) ) ;
F_67 ( V_60 -> V_63 , V_62 L_6 , sizeof( V_60 -> V_63 ) ) ;
snprintf ( V_60 -> V_64 , sizeof( V_60 -> V_64 ) , L_7 ,
F_68 ( & V_5 -> V_20 -> V_21 ) ) ;
V_60 -> V_65 = V_66 | V_67 |
V_68 | V_69 ;
V_60 -> V_70 = V_60 -> V_65 | V_71 ;
return 0 ;
}
static int F_69 ( struct V_57 * V_57 , void * V_32 ,
struct V_72 * V_73 )
{
return F_70 ( V_73 ) ;
}
static int F_71 ( struct V_57 * V_57 , void * V_58 ,
struct V_74 * V_73 )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
return F_72 ( V_2 , V_73 ) ;
}
static int F_73 ( struct V_57 * V_57 , void * V_58 ,
struct V_74 * V_73 )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
return F_74 ( V_2 , V_73 ) ;
}
static int F_75 ( struct V_57 * V_57 , void * V_58 ,
struct V_74 * V_73 )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
struct V_16 * V_43 ;
struct V_33 * V_49 ;
struct V_75 * V_76 ;
int V_50 , V_6 = 0 ;
V_6 = F_73 ( V_57 , V_58 , V_73 ) ;
if ( V_6 )
return V_6 ;
V_43 = F_76 ( V_2 -> V_25 , V_73 -> type ) ;
if ( F_77 ( V_43 ) ) {
F_32 ( L_8 , V_73 -> type ) ;
return - V_77 ;
}
if ( F_60 ( V_73 -> type ) )
V_49 = & V_2 -> V_34 ;
else
V_49 = & V_2 -> V_35 ;
V_76 = & V_73 -> V_51 . V_78 ;
V_49 -> V_51 = F_78 ( & V_76 -> V_79 , NULL , 0 ) ;
V_49 -> V_80 = V_76 -> V_80 ;
if ( ! V_49 -> V_51 )
return - V_52 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_51 -> V_45 ; V_50 ++ )
V_49 -> V_53 [ V_50 ] = V_76 -> V_81 [ V_50 ] . V_82 ;
F_79 ( V_49 , V_76 -> V_83 , V_76 -> V_84 ) ;
if ( V_73 -> type == V_85 )
F_4 ( V_40 | V_86 , V_2 ) ;
else
F_4 ( V_40 | V_87 , V_2 ) ;
F_30 ( L_9 , V_49 -> V_88 , V_49 -> V_89 ) ;
return 0 ;
}
static int F_80 ( struct V_57 * V_57 , void * V_58 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
T_1 V_92 ;
V_92 = ( V_91 -> type == V_93 ) ?
V_5 -> V_94 -> V_95 : V_5 -> V_94 -> V_96 ;
if ( V_91 -> V_18 > V_92 )
return - V_52 ;
return F_81 ( V_57 , V_2 -> V_25 , V_91 ) ;
}
static int F_82 ( struct V_57 * V_57 , void * V_58 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
return F_83 ( V_57 , V_2 -> V_25 , V_98 ) ;
}
static int F_84 ( struct V_57 * V_57 , void * V_58 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
return F_85 ( V_57 , V_2 -> V_25 , V_100 ) ;
}
static int F_86 ( struct V_57 * V_57 , void * V_58 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
return F_87 ( V_57 , V_2 -> V_25 , V_100 ) ;
}
static int F_88 ( struct V_57 * V_57 , void * V_58 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
return F_89 ( V_57 , V_2 -> V_25 , V_100 ) ;
}
static int F_90 ( struct V_57 * V_57 , void * V_58 ,
enum V_101 type )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
if ( F_60 ( type ) ) {
if ( ! F_6 ( V_87 , V_2 ) )
return - V_52 ;
} else if ( ! F_6 ( V_86 , V_2 ) ) {
return - V_52 ;
}
return F_91 ( V_57 , V_2 -> V_25 , type ) ;
}
static int F_92 ( struct V_57 * V_57 , void * V_58 ,
enum V_101 type )
{
struct V_1 * V_2 = F_66 ( V_58 ) ;
return F_93 ( V_57 , V_2 -> V_25 , type ) ;
}
static int F_94 ( struct V_102 * V_103 , struct V_102 * V_104 )
{
if ( V_103 -> V_105 < V_104 -> V_105 || V_103 -> V_106 < V_104 -> V_106 )
return 0 ;
if ( V_103 -> V_105 + V_103 -> V_83 > V_104 -> V_105 + V_104 -> V_83 )
return 0 ;
if ( V_103 -> V_106 + V_103 -> V_84 > V_104 -> V_106 + V_104 -> V_84 )
return 0 ;
return 1 ;
}
static int F_95 ( struct V_57 * V_57 , void * V_58 ,
struct V_107 * V_108 )
{
struct V_33 * V_49 ;
struct V_1 * V_2 = F_66 ( V_58 ) ;
if ( ( V_108 -> type != V_109 ) &&
( V_108 -> type != V_110 ) )
return - V_52 ;
V_49 = F_56 ( V_2 , V_108 -> type ) ;
if ( F_57 ( V_49 ) )
return F_58 ( V_49 ) ;
switch ( V_108 -> V_111 ) {
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_108 -> V_116 . V_105 = 0 ;
V_108 -> V_116 . V_106 = 0 ;
V_108 -> V_116 . V_83 = V_49 -> V_88 ;
V_108 -> V_116 . V_84 = V_49 -> V_89 ;
return 0 ;
case V_117 :
case V_118 :
V_108 -> V_116 . V_105 = V_49 -> V_119 . V_105 ;
V_108 -> V_116 . V_106 = V_49 -> V_119 . V_106 ;
V_108 -> V_116 . V_83 = V_49 -> V_119 . V_83 ;
V_108 -> V_116 . V_84 = V_49 -> V_119 . V_84 ;
return 0 ;
}
return - V_52 ;
}
static int F_96 ( struct V_57 * V_57 , void * V_58 ,
struct V_107 * V_108 )
{
struct V_33 * V_49 ;
struct V_1 * V_2 = F_66 ( V_58 ) ;
struct V_120 V_121 ;
struct V_122 * V_94 = V_2 -> V_4 -> V_94 ;
int V_6 ;
V_121 . type = V_108 -> type ;
V_121 . V_123 = V_108 -> V_116 ;
if ( ( V_108 -> type != V_109 ) &&
( V_108 -> type != V_110 ) )
return - V_52 ;
V_6 = F_97 ( V_2 , & V_121 ) ;
if ( V_6 )
return V_6 ;
if ( V_108 -> V_30 & V_124 &&
! F_94 ( & V_121 . V_123 , & V_108 -> V_116 ) )
return - V_125 ;
if ( V_108 -> V_30 & V_126 &&
! F_94 ( & V_108 -> V_116 , & V_121 . V_123 ) )
return - V_125 ;
V_108 -> V_116 = V_121 . V_123 ;
switch ( V_108 -> V_111 ) {
case V_113 :
case V_112 :
case V_117 :
V_49 = & V_2 -> V_34 ;
break;
case V_114 :
case V_118 :
case V_115 :
V_49 = & V_2 -> V_35 ;
break;
default:
return - V_52 ;
}
if ( F_6 ( V_86 | V_87 , V_2 ) ) {
if ( V_108 -> type == V_93 ) {
V_6 = F_98 ( V_94 , V_121 . V_123 . V_83 ,
V_121 . V_123 . V_84 , V_2 -> V_35 . V_119 . V_83 ,
V_2 -> V_35 . V_119 . V_84 ,
V_2 -> V_127 . V_128 -> V_129 , V_2 -> V_130 ) ;
} else {
V_6 = F_98 ( V_94 ,
V_2 -> V_34 . V_119 . V_83 ,
V_2 -> V_34 . V_119 . V_84 , V_121 . V_123 . V_83 ,
V_121 . V_123 . V_84 , V_2 -> V_127 . V_128 -> V_129 ,
V_2 -> V_130 ) ;
}
if ( V_6 ) {
F_32 ( L_10 ) ;
return - V_52 ;
}
}
V_49 -> V_119 = V_121 . V_123 ;
F_4 ( V_40 , V_2 ) ;
return 0 ;
}
static int F_99 ( void * V_32 , struct V_16 * V_131 ,
struct V_16 * V_132 )
{
struct V_1 * V_2 = V_32 ;
int V_6 ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_131 -> type = V_93 ;
V_131 -> V_133 = V_134 | V_135 | V_136 ;
V_131 -> V_19 = V_2 ;
V_131 -> V_137 = & V_138 ;
V_131 -> V_139 = & V_140 ;
V_131 -> V_141 = sizeof( struct V_142 ) ;
V_131 -> V_143 = V_144 ;
V_131 -> V_145 = & V_2 -> V_4 -> V_145 ;
V_131 -> V_21 = & V_2 -> V_4 -> V_20 -> V_21 ;
V_6 = F_100 ( V_131 ) ;
if ( V_6 )
return V_6 ;
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
V_132 -> type = V_85 ;
V_132 -> V_133 = V_134 | V_135 | V_136 ;
V_132 -> V_19 = V_2 ;
V_132 -> V_137 = & V_138 ;
V_132 -> V_139 = & V_140 ;
V_132 -> V_141 = sizeof( struct V_142 ) ;
V_132 -> V_143 = V_144 ;
V_132 -> V_145 = & V_2 -> V_4 -> V_145 ;
V_132 -> V_21 = & V_2 -> V_4 -> V_20 -> V_21 ;
return F_100 ( V_132 ) ;
}
static int F_101 ( struct V_57 * V_57 )
{
struct V_4 * V_5 = F_102 ( V_57 ) ;
struct V_1 * V_2 = NULL ;
int V_6 ;
F_30 ( L_11 , F_103 ( V_146 ) , V_5 -> V_13 ) ;
if ( F_104 ( & V_5 -> V_145 ) )
return - V_147 ;
V_2 = F_105 ( sizeof( * V_2 ) , V_148 ) ;
if ( ! V_2 ) {
V_6 = - V_149 ;
goto V_150;
}
F_106 ( & V_2 -> V_58 , V_5 -> V_7 . V_151 ) ;
V_6 = F_107 ( V_2 ) ;
if ( V_6 )
goto V_152;
V_2 -> V_58 . V_153 = & V_2 -> V_153 ;
V_57 -> V_154 = & V_2 -> V_58 ;
F_108 ( & V_2 -> V_58 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_34 . V_51 = F_109 ( 0 ) ;
V_2 -> V_35 . V_51 = F_109 ( 0 ) ;
V_2 -> V_13 = V_155 ;
V_2 -> V_30 = 0 ;
V_2 -> V_156 = V_157 ;
V_2 -> V_130 = V_157 ;
V_2 -> V_25 = F_110 ( V_5 -> V_7 . V_8 , V_2 , F_99 ) ;
if ( F_57 ( V_2 -> V_25 ) ) {
F_32 ( L_12 ) ;
V_6 = F_58 ( V_2 -> V_25 ) ;
goto V_158;
}
if ( V_5 -> V_7 . V_159 ++ == 0 )
F_29 ( V_160 , & V_5 -> V_13 ) ;
F_30 ( L_13 , V_2 ) ;
F_111 ( & V_5 -> V_145 ) ;
return 0 ;
V_158:
F_112 ( V_2 ) ;
F_113 ( & V_2 -> V_58 ) ;
V_152:
F_114 ( & V_2 -> V_58 ) ;
F_115 ( V_2 ) ;
V_150:
F_111 ( & V_5 -> V_145 ) ;
return V_6 ;
}
static int F_116 ( struct V_57 * V_57 )
{
struct V_1 * V_2 = F_66 ( V_57 -> V_154 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
F_30 ( L_14 ,
F_103 ( V_146 ) , V_5 -> V_13 , V_5 -> V_7 . V_159 ) ;
F_117 ( & V_5 -> V_145 ) ;
F_118 ( V_2 -> V_25 ) ;
F_112 ( V_2 ) ;
F_113 ( & V_2 -> V_58 ) ;
F_114 ( & V_2 -> V_58 ) ;
if ( -- V_5 -> V_7 . V_159 <= 0 )
F_119 ( V_160 , & V_5 -> V_13 ) ;
F_115 ( V_2 ) ;
F_111 ( & V_5 -> V_145 ) ;
return 0 ;
}
static unsigned int F_120 ( struct V_57 * V_57 ,
struct V_161 * V_162 )
{
struct V_1 * V_2 = F_66 ( V_57 -> V_154 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
unsigned int V_6 ;
if ( F_104 ( & V_5 -> V_145 ) )
return - V_147 ;
V_6 = F_121 ( V_57 , V_2 -> V_25 , V_162 ) ;
F_111 ( & V_5 -> V_145 ) ;
return V_6 ;
}
static int F_122 ( struct V_57 * V_57 , struct V_163 * V_164 )
{
struct V_1 * V_2 = F_66 ( V_57 -> V_154 ) ;
struct V_4 * V_5 = V_2 -> V_4 ;
int V_6 ;
if ( F_104 ( & V_5 -> V_145 ) )
return - V_147 ;
V_6 = F_123 ( V_57 , V_2 -> V_25 , V_164 ) ;
F_111 ( & V_5 -> V_145 ) ;
return V_6 ;
}
int F_124 ( struct V_4 * V_5 )
{
struct V_165 * V_20 ;
int V_6 ;
if ( ! V_5 )
return - V_166 ;
V_20 = V_5 -> V_20 ;
V_5 -> V_167 . V_168 = & V_169 ;
V_5 -> V_167 . V_170 = & V_171 ;
V_5 -> V_167 . V_172 = V_173 ;
V_5 -> V_167 . V_145 = & V_5 -> V_145 ;
V_5 -> V_167 . V_174 = V_175 ;
V_5 -> V_167 . V_176 = & V_5 -> V_176 ;
snprintf ( V_5 -> V_167 . V_177 , sizeof( V_5 -> V_167 . V_177 ) , L_15 ,
V_62 , V_5 -> V_178 ) ;
F_125 ( & V_5 -> V_167 , V_5 ) ;
V_5 -> V_7 . V_151 = & V_5 -> V_167 ;
V_5 -> V_7 . V_8 = F_126 ( & V_179 ) ;
if ( F_57 ( V_5 -> V_7 . V_8 ) ) {
F_127 ( & V_20 -> V_21 , L_16 ) ;
return F_58 ( V_5 -> V_7 . V_8 ) ;
}
V_6 = F_128 ( & V_5 -> V_167 , V_180 , - 1 ) ;
if ( V_6 ) {
F_127 ( & V_20 -> V_21 ,
L_17 , V_181 ) ;
goto V_182;
}
F_30 ( L_18 , V_5 -> V_167 . V_183 ) ;
return 0 ;
V_182:
F_129 ( V_5 -> V_7 . V_8 ) ;
return V_6 ;
}
void F_130 ( struct V_4 * V_5 )
{
if ( V_5 ) {
F_129 ( V_5 -> V_7 . V_8 ) ;
F_131 ( & V_5 -> V_167 ) ;
}
}
