static unsigned int F_1 ( unsigned int V_1 )
{
if ( V_1 == V_2 )
return V_3 ;
else
return V_4 ;
}
void F_2 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 , * V_10 ;
if ( ! V_6 || ! V_6 -> V_11 . V_12 )
return;
V_9 = F_3 ( V_6 -> V_11 . V_12 ) ;
V_10 = F_4 ( V_6 -> V_11 . V_12 ) ;
if ( V_9 && V_10 ) {
F_5 ( V_9 , V_7 ) ;
F_5 ( V_10 , V_7 ) ;
F_6 ( V_6 -> V_13 -> V_14 . V_15 ,
V_6 -> V_11 . V_12 ) ;
}
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
int V_17 ;
if ( ! F_8 ( V_16 ) )
return 0 ;
F_9 ( V_18 , V_6 ) ;
V_17 = F_10 ( V_16 -> V_19 ,
! F_11 ( V_18 , V_6 ) ,
V_20 ) ;
return V_17 == 0 ? - V_21 : V_17 ;
}
static int F_12 ( struct V_22 * V_23 , unsigned int V_24 )
{
struct V_5 * V_6 = V_23 -> V_25 ;
int V_17 ;
V_17 = F_13 ( & V_6 -> V_13 -> V_26 -> V_27 ) ;
return V_17 > 0 ? 0 : V_17 ;
}
static void F_14 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = V_23 -> V_25 ;
int V_17 ;
V_17 = F_7 ( V_6 ) ;
if ( V_17 == - V_21 )
F_2 ( V_6 , V_28 ) ;
F_15 ( & V_6 -> V_13 -> V_26 -> V_27 ) ;
}
static void F_16 ( void * V_29 )
{
struct V_8 * V_9 , * V_10 ;
struct V_5 * V_6 = V_29 ;
struct V_30 * V_31 , * V_32 ;
struct V_13 * V_16 ;
unsigned long V_33 ;
int V_17 ;
if ( F_17 ( ! V_6 , L_1 ) )
return;
V_16 = V_6 -> V_13 ;
F_18 ( & V_16 -> V_34 , V_33 ) ;
F_19 ( V_35 , & V_16 -> V_36 ) ;
V_31 = & V_6 -> V_37 ;
V_32 = & V_6 -> V_38 ;
if ( V_6 -> V_36 & V_39 ) {
F_20 ( V_6 , V_31 ) ;
F_20 ( V_6 , V_32 ) ;
}
V_9 = F_21 ( V_6 -> V_11 . V_12 ) ;
V_17 = F_22 ( V_6 , & V_9 -> V_40 , V_31 , & V_31 -> V_41 ) ;
if ( V_17 )
goto V_42;
V_10 = F_23 ( V_6 -> V_11 . V_12 ) ;
V_17 = F_22 ( V_6 , & V_10 -> V_40 , V_32 , & V_32 -> V_41 ) ;
if ( V_17 )
goto V_42;
V_10 -> V_40 . V_43 = V_9 -> V_40 . V_43 ;
V_10 -> V_33 &= ~ V_44 ;
V_10 -> V_33 |=
V_9 -> V_33 & V_44 ;
if ( V_16 -> V_14 . V_6 != V_6 ) {
V_6 -> V_36 |= V_39 ;
V_16 -> V_14 . V_6 = V_6 ;
}
if ( V_6 -> V_36 & V_39 ) {
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
V_17 = F_27 ( V_6 ) ;
if ( V_17 )
goto V_42;
F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
if ( V_16 -> V_45 -> V_46 )
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
}
F_36 ( V_16 , & V_31 -> V_41 ) ;
F_37 ( V_16 , & V_32 -> V_41 , - 1 ) ;
F_38 ( V_6 ) ;
V_6 -> V_36 &= ( V_47 | V_48 ) ;
F_39 ( V_16 , true ) ;
V_42:
F_40 ( & V_16 -> V_34 , V_33 ) ;
}
static void F_41 ( void * V_29 )
{
F_7 ( V_29 ) ;
}
static int F_42 ( struct V_22 * V_49 ,
unsigned int * V_50 , unsigned int * V_51 ,
unsigned int V_52 [] , void * V_53 [] )
{
struct V_5 * V_6 = F_43 ( V_49 ) ;
struct V_30 * V_54 ;
int V_55 ;
V_54 = F_44 ( V_6 , V_49 -> type ) ;
if ( F_45 ( V_54 ) )
return F_46 ( V_54 ) ;
if ( ! V_54 -> V_56 )
return - V_57 ;
* V_51 = V_54 -> V_56 -> V_58 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_56 -> V_58 ; V_55 ++ ) {
V_52 [ V_55 ] = V_54 -> V_59 [ V_55 ] ;
V_53 [ V_55 ] = V_6 -> V_13 -> V_60 ;
}
return 0 ;
}
static int F_47 ( struct V_61 * V_62 )
{
struct V_5 * V_6 = F_43 ( V_62 -> V_22 ) ;
struct V_30 * V_63 ;
int V_55 ;
V_63 = F_44 ( V_6 , V_62 -> V_22 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
for ( V_55 = 0 ; V_55 < V_63 -> V_56 -> V_58 ; V_55 ++ )
F_48 ( V_62 , V_55 , V_63 -> V_59 [ V_55 ] ) ;
return 0 ;
}
static void F_49 ( struct V_61 * V_62 )
{
struct V_8 * V_64 = F_50 ( V_62 ) ;
struct V_5 * V_6 = F_43 ( V_62 -> V_22 ) ;
F_51 ( V_6 -> V_11 . V_12 , V_64 ) ;
}
static int F_52 ( struct V_65 * V_65 , void * V_11 ,
struct V_66 * V_67 )
{
struct V_13 * V_16 = F_53 ( V_65 ) ;
unsigned int V_68 ;
V_68 = V_69 | V_70 |
V_71 | V_72 ;
F_54 ( & V_16 -> V_26 -> V_27 , V_67 , V_68 ) ;
return 0 ;
}
static int F_55 ( struct V_65 * V_65 , void * V_29 ,
struct V_73 * V_54 )
{
struct V_74 * V_56 ;
V_56 = F_56 ( NULL , NULL , F_1 ( V_54 -> type ) ,
V_54 -> V_75 ) ;
if ( ! V_56 )
return - V_57 ;
strncpy ( V_54 -> V_76 , V_56 -> V_77 , sizeof( V_54 -> V_76 ) - 1 ) ;
V_54 -> V_78 = V_56 -> V_79 ;
return 0 ;
}
static int F_57 ( struct V_65 * V_65 , void * V_11 ,
struct V_80 * V_54 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_30 * V_63 = F_44 ( V_6 , V_54 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
F_59 ( V_63 , V_54 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 , struct V_80 * V_54 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
const struct V_81 * V_82 = V_16 -> V_82 ;
struct V_83 * V_84 = & V_54 -> V_56 . V_85 ;
struct V_74 * V_56 ;
T_1 V_86 , V_87 , V_88 ;
if ( ! F_61 ( V_54 -> type ) )
return - V_57 ;
V_56 = F_56 ( & V_84 -> V_78 , NULL ,
F_1 ( V_54 -> type ) , 0 ) ;
if ( F_17 ( V_56 == NULL , L_2 ) )
return - V_57 ;
if ( V_84 -> V_89 == V_90 )
V_84 -> V_89 = V_91 ;
else if ( V_84 -> V_89 != V_91 )
return - V_57 ;
if ( V_54 -> type == V_2 ) {
V_86 = V_82 -> V_92 -> V_93 ;
V_87 = F_62 ( V_82 -> V_94 ) - 1 ;
} else {
V_86 = V_82 -> V_92 -> V_95 ;
V_87 = F_62 ( V_82 -> V_96 ) - 1 ;
}
if ( F_63 ( V_56 ) ) {
V_87 = 6 ;
V_88 = 5 ;
} else {
if ( V_82 -> V_97 == 1 )
V_88 = F_64 ( V_56 -> V_98 ) ? 0 : 1 ;
else
V_88 = F_62 ( V_82 -> V_97 ) - 1 ;
}
F_65 ( & V_84 -> V_99 , 16 , V_86 , V_87 ,
& V_84 -> V_100 , 8 , V_82 -> V_92 -> V_93 , V_88 , 0 ) ;
F_66 ( V_56 , V_84 -> V_99 , V_84 -> V_100 , & V_54 -> V_56 . V_85 ) ;
return 0 ;
}
static int F_67 ( struct V_65 * V_65 , void * V_11 ,
struct V_80 * V_54 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
return F_60 ( V_6 , V_54 ) ;
}
static void F_68 ( struct V_30 * V_63 , struct V_74 * V_56 ,
struct V_83 * V_101 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 -> V_58 ; V_55 ++ ) {
V_63 -> V_102 [ V_55 ] = V_101 -> V_103 [ V_55 ] . V_102 ;
V_63 -> V_59 [ V_55 ] = V_101 -> V_103 [ V_55 ] . V_104 ;
}
V_63 -> V_105 = V_101 -> V_99 ;
V_63 -> V_106 = V_101 -> V_100 ;
V_63 -> V_107 = V_101 -> V_99 ;
V_63 -> V_108 = V_101 -> V_100 ;
V_63 -> V_99 = V_101 -> V_99 ;
V_63 -> V_100 = V_101 -> V_100 ;
V_63 -> V_109 = 0 ;
V_63 -> V_110 = 0 ;
V_63 -> V_56 = V_56 ;
}
static int F_69 ( struct V_65 * V_65 , void * V_11 ,
struct V_80 * V_54 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_74 * V_56 ;
struct V_22 * V_49 ;
struct V_30 * V_63 ;
int V_17 ;
V_17 = F_60 ( V_6 , V_54 ) ;
if ( V_17 )
return V_17 ;
V_49 = F_70 ( V_6 -> V_11 . V_12 , V_54 -> type ) ;
if ( F_71 ( V_49 ) ) {
F_72 ( & V_16 -> V_14 . V_111 , L_3 , V_54 -> type ) ;
return - V_112 ;
}
if ( V_54 -> type == V_2 )
V_63 = & V_6 -> V_37 ;
else
V_63 = & V_6 -> V_38 ;
V_56 = F_56 ( & V_54 -> V_56 . V_85 . V_78 , NULL ,
F_1 ( V_54 -> type ) , 0 ) ;
if ( ! V_56 )
return - V_57 ;
F_68 ( V_63 , V_56 , & V_54 -> V_56 . V_85 ) ;
F_73 ( V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_65 * V_65 , void * V_11 ,
struct V_113 * V_114 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_30 * V_63 ;
V_63 = F_44 ( V_6 , V_114 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
V_114 -> V_115 . V_116 = 0 ;
V_114 -> V_115 . V_117 = 0 ;
V_114 -> V_115 . V_99 = V_63 -> V_107 ;
V_114 -> V_115 . V_100 = V_63 -> V_108 ;
V_114 -> V_118 = V_114 -> V_115 ;
return 0 ;
}
static int F_75 ( struct V_65 * V_65 , void * V_11 , struct V_119 * V_114 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_30 * V_63 ;
V_63 = F_44 ( V_6 , V_114 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
V_114 -> V_120 . V_116 = V_63 -> V_109 ;
V_114 -> V_120 . V_117 = V_63 -> V_110 ;
V_114 -> V_120 . V_99 = V_63 -> V_99 ;
V_114 -> V_120 . V_100 = V_63 -> V_100 ;
return 0 ;
}
static int F_76 ( struct V_5 * V_6 , struct V_119 * V_114 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_30 * V_54 ;
T_1 V_121 , V_122 , V_123 = 0 ;
int V_55 ;
if ( V_114 -> V_120 . V_117 < 0 || V_114 -> V_120 . V_116 < 0 ) {
F_72 ( & V_16 -> V_14 . V_111 ,
L_4 ) ;
return - V_57 ;
}
if ( V_114 -> type == V_124 )
V_54 = & V_6 -> V_38 ;
else if ( V_114 -> type == V_2 )
V_54 = & V_6 -> V_37 ;
else
return - V_57 ;
V_121 = ( V_54 == & V_6 -> V_37 ) ?
V_16 -> V_82 -> V_94 : V_16 -> V_82 -> V_96 ;
if ( V_16 -> V_82 -> V_97 == 1 )
V_122 = F_64 ( V_54 -> V_56 -> V_98 ) ? 0 : 1 ;
else
V_122 = F_62 ( V_16 -> V_82 -> V_97 ) - 1 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_56 -> V_58 ; V_55 ++ )
V_123 += V_54 -> V_56 -> V_123 [ V_55 ] ;
F_65 ( & V_114 -> V_120 . V_99 , V_121 , V_54 -> V_107 ,
F_62 ( V_121 ) - 1 ,
& V_114 -> V_120 . V_100 , V_121 , V_54 -> V_108 ,
V_122 , 64 / ( F_77 ( V_123 , 8 ) ) ) ;
if ( V_114 -> V_120 . V_116 + V_114 -> V_120 . V_99 > V_54 -> V_107 )
V_114 -> V_120 . V_116 = V_54 -> V_107 - V_114 -> V_120 . V_99 ;
if ( V_114 -> V_120 . V_117 + V_114 -> V_120 . V_100 > V_54 -> V_108 )
V_114 -> V_120 . V_117 = V_54 -> V_108 - V_114 -> V_120 . V_100 ;
V_114 -> V_120 . V_116 = F_78 ( V_114 -> V_120 . V_116 , V_121 ) ;
V_114 -> V_120 . V_117 = F_78 ( V_114 -> V_120 . V_117 , V_16 -> V_82 -> V_125 ) ;
F_79 ( L_5 ,
V_114 -> V_120 . V_116 , V_114 -> V_120 . V_117 , V_114 -> V_120 . V_99 , V_114 -> V_120 . V_100 ,
V_54 -> V_105 , V_54 -> V_106 ) ;
return 0 ;
}
static int F_80 ( struct V_65 * V_65 , void * V_11 , const struct V_119 * V_126 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_119 V_114 = * V_126 ;
struct V_30 * V_54 ;
int V_17 ;
V_17 = F_76 ( V_6 , & V_114 ) ;
if ( V_17 )
return V_17 ;
V_54 = ( V_114 . type == V_2 ) ?
& V_6 -> V_37 : & V_6 -> V_38 ;
if ( V_114 . type == V_2 ) {
V_17 = F_81 ( V_6 , V_114 . V_120 . V_99 ,
V_114 . V_120 . V_100 , V_6 -> V_38 . V_99 ,
V_6 -> V_38 . V_100 , V_6 -> V_127 ) ;
} else {
V_17 = F_81 ( V_6 , V_6 -> V_37 . V_99 ,
V_6 -> V_37 . V_100 , V_114 . V_120 . V_99 ,
V_114 . V_120 . V_100 , V_6 -> V_127 ) ;
}
if ( V_17 ) {
F_72 ( & V_16 -> V_14 . V_111 , L_6 ) ;
return - V_57 ;
}
V_54 -> V_109 = V_114 . V_120 . V_116 ;
V_54 -> V_110 = V_114 . V_120 . V_117 ;
V_54 -> V_99 = V_114 . V_120 . V_99 ;
V_54 -> V_100 = V_114 . V_120 . V_100 ;
F_9 ( V_39 , V_6 ) ;
return 0 ;
}
static int F_82 ( void * V_29 , struct V_22 * V_128 ,
struct V_22 * V_129 )
{
struct V_5 * V_6 = V_29 ;
int V_17 ;
V_128 -> type = V_2 ;
V_128 -> V_130 = V_131 | V_132 | V_133 ;
V_128 -> V_25 = V_6 ;
V_128 -> V_134 = & V_135 ;
V_128 -> V_136 = & V_137 ;
V_128 -> V_138 = sizeof( struct V_139 ) ;
V_128 -> V_140 = V_141 ;
V_128 -> V_142 = & V_6 -> V_13 -> V_142 ;
V_17 = F_83 ( V_128 ) ;
if ( V_17 )
return V_17 ;
V_129 -> type = V_124 ;
V_129 -> V_130 = V_131 | V_132 | V_133 ;
V_129 -> V_25 = V_6 ;
V_129 -> V_134 = & V_135 ;
V_129 -> V_136 = & V_137 ;
V_129 -> V_138 = sizeof( struct V_139 ) ;
V_129 -> V_140 = V_141 ;
V_129 -> V_142 = & V_6 -> V_13 -> V_142 ;
return F_83 ( V_129 ) ;
}
static int F_84 ( struct V_5 * V_6 )
{
struct V_83 V_101 = {
. V_78 = V_143 ,
. V_99 = 800 ,
. V_100 = 600 ,
. V_103 [ 0 ] = {
. V_102 = 800 * 4 ,
. V_104 = 800 * 4 * 600 ,
} ,
} ;
struct V_74 * V_56 ;
V_56 = F_56 ( & V_101 . V_78 , NULL , V_144 , 0 ) ;
if ( ! V_56 )
return - V_57 ;
F_68 ( & V_6 -> V_37 , V_56 , & V_101 ) ;
F_68 ( & V_6 -> V_38 , V_56 , & V_101 ) ;
return 0 ;
}
static int F_85 ( struct V_65 * V_65 )
{
struct V_13 * V_16 = F_53 ( V_65 ) ;
struct V_5 * V_6 ;
int V_17 = - V_112 ;
F_86 ( L_7 , F_87 ( V_145 ) , V_16 -> V_36 ) ;
if ( F_88 ( & V_16 -> V_142 ) )
return - V_146 ;
if ( F_89 ( V_147 , & V_16 -> V_36 ) )
goto V_148;
V_6 = F_90 ( sizeof( * V_6 ) , V_149 ) ;
if ( ! V_6 ) {
V_17 = - V_150 ;
goto V_148;
}
F_91 ( & V_6 -> V_11 , & V_16 -> V_14 . V_111 ) ;
V_6 -> V_13 = V_16 ;
V_6 -> V_37 . V_56 = F_92 ( 0 ) ;
V_6 -> V_38 . V_56 = F_92 ( 0 ) ;
V_17 = F_93 ( V_6 ) ;
if ( V_17 )
goto V_151;
V_6 -> V_11 . V_152 = & V_6 -> V_153 . V_154 ;
V_65 -> V_155 = & V_6 -> V_11 ;
F_94 ( & V_6 -> V_11 ) ;
V_6 -> V_36 = V_47 ;
V_6 -> V_33 = 0 ;
V_6 -> V_156 = V_157 ;
V_6 -> V_158 = V_157 ;
V_6 -> V_159 . V_160 = 1 ;
V_6 -> V_11 . V_12 = F_95 ( V_16 -> V_14 . V_15 , V_6 , F_82 ) ;
if ( F_45 ( V_6 -> V_11 . V_12 ) ) {
V_17 = F_46 ( V_6 -> V_11 . V_12 ) ;
goto V_161;
}
if ( V_16 -> V_14 . V_162 ++ == 0 )
F_19 ( V_163 , & V_16 -> V_36 ) ;
V_17 = F_84 ( V_6 ) ;
if ( V_17 < 0 )
goto V_164;
F_96 ( & V_16 -> V_142 ) ;
return 0 ;
V_164:
F_97 ( V_6 -> V_11 . V_12 ) ;
V_161:
F_98 ( V_6 ) ;
V_151:
F_99 ( & V_6 -> V_11 ) ;
F_100 ( & V_6 -> V_11 ) ;
F_101 ( V_6 ) ;
V_148:
F_96 ( & V_16 -> V_142 ) ;
return V_17 ;
}
static int F_102 ( struct V_65 * V_65 )
{
struct V_5 * V_6 = F_58 ( V_65 -> V_155 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
F_79 ( L_8 ,
F_87 ( V_145 ) , V_16 -> V_36 , V_16 -> V_14 . V_162 ) ;
F_103 ( & V_16 -> V_142 ) ;
F_97 ( V_6 -> V_11 . V_12 ) ;
F_98 ( V_6 ) ;
F_99 ( & V_6 -> V_11 ) ;
F_100 ( & V_6 -> V_11 ) ;
if ( -- V_16 -> V_14 . V_162 <= 0 )
F_104 ( V_163 , & V_16 -> V_36 ) ;
F_101 ( V_6 ) ;
F_96 ( & V_16 -> V_142 ) ;
return 0 ;
}
int F_105 ( struct V_13 * V_16 ,
struct V_165 * V_166 )
{
struct V_167 * V_111 = & V_16 -> V_14 . V_111 ;
int V_17 ;
V_16 -> V_166 = V_166 ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
V_111 -> V_168 = & V_169 ;
V_111 -> V_170 = & V_171 ;
V_111 -> V_166 = V_166 ;
V_111 -> V_172 = - 1 ;
V_111 -> V_173 = V_174 ;
V_111 -> V_142 = & V_16 -> V_142 ;
V_111 -> V_175 = V_176 ;
snprintf ( V_111 -> V_77 , sizeof( V_111 -> V_77 ) , L_9 , V_16 -> V_177 ) ;
F_106 ( V_111 , V_16 ) ;
V_16 -> V_14 . V_15 = F_107 ( & V_178 ) ;
if ( F_45 ( V_16 -> V_14 . V_15 ) ) {
F_72 ( V_166 , L_10 ) ;
return F_46 ( V_16 -> V_14 . V_15 ) ;
}
V_17 = F_108 ( & V_111 -> V_179 , 0 , NULL ) ;
if ( V_17 )
goto V_180;
V_17 = F_109 ( V_111 , V_181 , - 1 ) ;
if ( V_17 )
goto V_182;
F_110 ( V_166 , L_11 ,
V_111 -> V_77 , F_111 ( V_111 ) ) ;
return 0 ;
V_182:
F_112 ( & V_111 -> V_179 ) ;
V_180:
F_113 ( V_16 -> V_14 . V_15 ) ;
return V_17 ;
}
void F_114 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
if ( V_16 -> V_14 . V_15 )
F_113 ( V_16 -> V_14 . V_15 ) ;
if ( F_115 ( & V_16 -> V_14 . V_111 ) ) {
F_116 ( & V_16 -> V_14 . V_111 ) ;
F_112 ( & V_16 -> V_14 . V_111 . V_179 ) ;
}
}
