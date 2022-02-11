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
V_10 -> V_43 = V_9 -> V_43 ;
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
static int F_42 ( struct V_22 * V_49 , const void * V_50 ,
unsigned int * V_51 , unsigned int * V_52 ,
unsigned int V_53 [] , void * V_54 [] )
{
struct V_5 * V_6 = F_43 ( V_49 ) ;
struct V_30 * V_55 ;
int V_56 ;
V_55 = F_44 ( V_6 , V_49 -> type ) ;
if ( F_45 ( V_55 ) )
return F_46 ( V_55 ) ;
if ( ! V_55 -> V_57 )
return - V_58 ;
* V_52 = V_55 -> V_57 -> V_59 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_57 -> V_59 ; V_56 ++ ) {
V_53 [ V_56 ] = V_55 -> V_60 [ V_56 ] ;
V_54 [ V_56 ] = V_6 -> V_13 -> V_61 ;
}
return 0 ;
}
static int F_47 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_43 ( V_63 -> V_22 ) ;
struct V_30 * V_64 ;
int V_56 ;
V_64 = F_44 ( V_6 , V_63 -> V_22 -> type ) ;
if ( F_45 ( V_64 ) )
return F_46 ( V_64 ) ;
for ( V_56 = 0 ; V_56 < V_64 -> V_57 -> V_59 ; V_56 ++ )
F_48 ( V_63 , V_56 , V_64 -> V_60 [ V_56 ] ) ;
return 0 ;
}
static void F_49 ( struct V_62 * V_63 )
{
struct V_8 * V_65 = F_50 ( V_63 ) ;
struct V_5 * V_6 = F_43 ( V_63 -> V_22 ) ;
F_51 ( V_6 -> V_11 . V_12 , V_65 ) ;
}
static int F_52 ( struct V_66 * V_66 , void * V_11 ,
struct V_67 * V_68 )
{
struct V_13 * V_16 = F_53 ( V_66 ) ;
unsigned int V_69 ;
V_69 = V_70 | V_71 |
V_72 | V_73 ;
F_54 ( & V_16 -> V_26 -> V_27 , V_68 , V_69 ) ;
return 0 ;
}
static int F_55 ( struct V_66 * V_66 , void * V_29 ,
struct V_74 * V_55 )
{
struct V_75 * V_57 ;
V_57 = F_56 ( NULL , NULL , F_1 ( V_55 -> type ) ,
V_55 -> V_76 ) ;
if ( ! V_57 )
return - V_58 ;
strncpy ( V_55 -> V_77 , V_57 -> V_78 , sizeof( V_55 -> V_77 ) - 1 ) ;
V_55 -> V_79 = V_57 -> V_80 ;
return 0 ;
}
static int F_57 ( struct V_66 * V_66 , void * V_11 ,
struct V_81 * V_55 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_30 * V_64 = F_44 ( V_6 , V_55 -> type ) ;
if ( F_45 ( V_64 ) )
return F_46 ( V_64 ) ;
F_59 ( V_64 , V_55 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 , struct V_81 * V_55 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
const struct V_82 * V_83 = V_16 -> V_83 ;
struct V_84 * V_85 = & V_55 -> V_57 . V_86 ;
struct V_75 * V_57 ;
T_1 V_87 , V_88 , V_89 ;
if ( ! F_61 ( V_55 -> type ) )
return - V_58 ;
V_57 = F_56 ( & V_85 -> V_79 , NULL ,
F_1 ( V_55 -> type ) , 0 ) ;
if ( F_17 ( V_57 == NULL , L_2 ) )
return - V_58 ;
if ( V_85 -> V_90 == V_91 )
V_85 -> V_90 = V_92 ;
else if ( V_85 -> V_90 != V_92 )
return - V_58 ;
if ( V_55 -> type == V_2 ) {
V_87 = V_83 -> V_93 -> V_94 ;
V_88 = F_62 ( V_83 -> V_95 ) - 1 ;
} else {
V_87 = V_83 -> V_93 -> V_96 ;
V_88 = F_62 ( V_83 -> V_97 ) - 1 ;
}
if ( F_63 ( V_57 ) ) {
V_88 = 6 ;
V_89 = 5 ;
} else {
if ( V_83 -> V_98 == 1 )
V_89 = F_64 ( V_57 -> V_99 ) ? 0 : 1 ;
else
V_89 = F_62 ( V_83 -> V_98 ) - 1 ;
}
F_65 ( & V_85 -> V_100 , 16 , V_87 , V_88 ,
& V_85 -> V_101 , 8 , V_83 -> V_93 -> V_94 , V_89 , 0 ) ;
F_66 ( V_57 , V_85 -> V_100 , V_85 -> V_101 , & V_55 -> V_57 . V_86 ) ;
return 0 ;
}
static int F_67 ( struct V_66 * V_66 , void * V_11 ,
struct V_81 * V_55 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
return F_60 ( V_6 , V_55 ) ;
}
static void F_68 ( struct V_30 * V_64 , struct V_75 * V_57 ,
struct V_84 * V_102 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_57 -> V_59 ; V_56 ++ ) {
V_64 -> V_103 [ V_56 ] = V_102 -> V_104 [ V_56 ] . V_103 ;
V_64 -> V_60 [ V_56 ] = V_102 -> V_104 [ V_56 ] . V_105 ;
}
V_64 -> V_106 = V_102 -> V_100 ;
V_64 -> V_107 = V_102 -> V_101 ;
V_64 -> V_108 = V_102 -> V_100 ;
V_64 -> V_109 = V_102 -> V_101 ;
V_64 -> V_100 = V_102 -> V_100 ;
V_64 -> V_101 = V_102 -> V_101 ;
V_64 -> V_110 = 0 ;
V_64 -> V_111 = 0 ;
V_64 -> V_57 = V_57 ;
}
static int F_69 ( struct V_66 * V_66 , void * V_11 ,
struct V_81 * V_55 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_75 * V_57 ;
struct V_22 * V_49 ;
struct V_30 * V_64 ;
int V_17 ;
V_17 = F_60 ( V_6 , V_55 ) ;
if ( V_17 )
return V_17 ;
V_49 = F_70 ( V_6 -> V_11 . V_12 , V_55 -> type ) ;
if ( F_71 ( V_49 ) ) {
F_72 ( & V_16 -> V_14 . V_112 , L_3 , V_55 -> type ) ;
return - V_113 ;
}
if ( V_55 -> type == V_2 )
V_64 = & V_6 -> V_37 ;
else
V_64 = & V_6 -> V_38 ;
V_57 = F_56 ( & V_55 -> V_57 . V_86 . V_79 , NULL ,
F_1 ( V_55 -> type ) , 0 ) ;
if ( ! V_57 )
return - V_58 ;
F_68 ( V_64 , V_57 , & V_55 -> V_57 . V_86 ) ;
F_73 ( V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_66 * V_66 , void * V_11 ,
struct V_114 * V_115 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_30 * V_64 ;
V_64 = F_44 ( V_6 , V_115 -> type ) ;
if ( F_45 ( V_64 ) )
return F_46 ( V_64 ) ;
V_115 -> V_116 . V_117 = 0 ;
V_115 -> V_116 . V_118 = 0 ;
V_115 -> V_116 . V_100 = V_64 -> V_108 ;
V_115 -> V_116 . V_101 = V_64 -> V_109 ;
V_115 -> V_119 = V_115 -> V_116 ;
return 0 ;
}
static int F_75 ( struct V_66 * V_66 , void * V_11 , struct V_120 * V_115 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_30 * V_64 ;
V_64 = F_44 ( V_6 , V_115 -> type ) ;
if ( F_45 ( V_64 ) )
return F_46 ( V_64 ) ;
V_115 -> V_121 . V_117 = V_64 -> V_110 ;
V_115 -> V_121 . V_118 = V_64 -> V_111 ;
V_115 -> V_121 . V_100 = V_64 -> V_100 ;
V_115 -> V_121 . V_101 = V_64 -> V_101 ;
return 0 ;
}
static int F_76 ( struct V_5 * V_6 , struct V_120 * V_115 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_30 * V_55 ;
T_1 V_122 , V_123 , V_124 = 0 ;
int V_56 ;
if ( V_115 -> V_121 . V_118 < 0 || V_115 -> V_121 . V_117 < 0 ) {
F_72 ( & V_16 -> V_14 . V_112 ,
L_4 ) ;
return - V_58 ;
}
if ( V_115 -> type == V_125 )
V_55 = & V_6 -> V_38 ;
else if ( V_115 -> type == V_2 )
V_55 = & V_6 -> V_37 ;
else
return - V_58 ;
V_122 = ( V_55 == & V_6 -> V_37 ) ?
V_16 -> V_83 -> V_95 : V_16 -> V_83 -> V_97 ;
if ( V_16 -> V_83 -> V_98 == 1 )
V_123 = F_64 ( V_55 -> V_57 -> V_99 ) ? 0 : 1 ;
else
V_123 = F_62 ( V_16 -> V_83 -> V_98 ) - 1 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_57 -> V_59 ; V_56 ++ )
V_124 += V_55 -> V_57 -> V_124 [ V_56 ] ;
F_65 ( & V_115 -> V_121 . V_100 , V_122 , V_55 -> V_108 ,
F_62 ( V_122 ) - 1 ,
& V_115 -> V_121 . V_101 , V_122 , V_55 -> V_109 ,
V_123 , 64 / ( F_77 ( V_124 , 8 ) ) ) ;
if ( V_115 -> V_121 . V_117 + V_115 -> V_121 . V_100 > V_55 -> V_108 )
V_115 -> V_121 . V_117 = V_55 -> V_108 - V_115 -> V_121 . V_100 ;
if ( V_115 -> V_121 . V_118 + V_115 -> V_121 . V_101 > V_55 -> V_109 )
V_115 -> V_121 . V_118 = V_55 -> V_109 - V_115 -> V_121 . V_101 ;
V_115 -> V_121 . V_117 = F_78 ( V_115 -> V_121 . V_117 , V_122 ) ;
V_115 -> V_121 . V_118 = F_78 ( V_115 -> V_121 . V_118 , V_16 -> V_83 -> V_126 ) ;
F_79 ( L_5 ,
V_115 -> V_121 . V_117 , V_115 -> V_121 . V_118 , V_115 -> V_121 . V_100 , V_115 -> V_121 . V_101 ,
V_55 -> V_106 , V_55 -> V_107 ) ;
return 0 ;
}
static int F_80 ( struct V_66 * V_66 , void * V_11 , const struct V_120 * V_127 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_120 V_115 = * V_127 ;
struct V_30 * V_55 ;
int V_17 ;
V_17 = F_76 ( V_6 , & V_115 ) ;
if ( V_17 )
return V_17 ;
V_55 = ( V_115 . type == V_2 ) ?
& V_6 -> V_37 : & V_6 -> V_38 ;
if ( V_115 . type == V_2 ) {
V_17 = F_81 ( V_6 , V_115 . V_121 . V_100 ,
V_115 . V_121 . V_101 , V_6 -> V_38 . V_100 ,
V_6 -> V_38 . V_101 , V_6 -> V_128 ) ;
} else {
V_17 = F_81 ( V_6 , V_6 -> V_37 . V_100 ,
V_6 -> V_37 . V_101 , V_115 . V_121 . V_100 ,
V_115 . V_121 . V_101 , V_6 -> V_128 ) ;
}
if ( V_17 ) {
F_72 ( & V_16 -> V_14 . V_112 , L_6 ) ;
return - V_58 ;
}
V_55 -> V_110 = V_115 . V_121 . V_117 ;
V_55 -> V_111 = V_115 . V_121 . V_118 ;
V_55 -> V_100 = V_115 . V_121 . V_100 ;
V_55 -> V_101 = V_115 . V_121 . V_101 ;
F_9 ( V_39 , V_6 ) ;
return 0 ;
}
static int F_82 ( void * V_29 , struct V_22 * V_129 ,
struct V_22 * V_130 )
{
struct V_5 * V_6 = V_29 ;
int V_17 ;
V_129 -> type = V_2 ;
V_129 -> V_131 = V_132 | V_133 | V_134 ;
V_129 -> V_25 = V_6 ;
V_129 -> V_135 = & V_136 ;
V_129 -> V_137 = & V_138 ;
V_129 -> V_139 = sizeof( struct V_140 ) ;
V_129 -> V_141 = V_142 ;
V_129 -> V_143 = & V_6 -> V_13 -> V_143 ;
V_17 = F_83 ( V_129 ) ;
if ( V_17 )
return V_17 ;
V_130 -> type = V_125 ;
V_130 -> V_131 = V_132 | V_133 | V_134 ;
V_130 -> V_25 = V_6 ;
V_130 -> V_135 = & V_136 ;
V_130 -> V_137 = & V_138 ;
V_130 -> V_139 = sizeof( struct V_140 ) ;
V_130 -> V_141 = V_142 ;
V_130 -> V_143 = & V_6 -> V_13 -> V_143 ;
return F_83 ( V_130 ) ;
}
static int F_84 ( struct V_5 * V_6 )
{
struct V_84 V_102 = {
. V_79 = V_144 ,
. V_100 = 800 ,
. V_101 = 600 ,
. V_104 [ 0 ] = {
. V_103 = 800 * 4 ,
. V_105 = 800 * 4 * 600 ,
} ,
} ;
struct V_75 * V_57 ;
V_57 = F_56 ( & V_102 . V_79 , NULL , V_145 , 0 ) ;
if ( ! V_57 )
return - V_58 ;
F_68 ( & V_6 -> V_37 , V_57 , & V_102 ) ;
F_68 ( & V_6 -> V_38 , V_57 , & V_102 ) ;
return 0 ;
}
static int F_85 ( struct V_66 * V_66 )
{
struct V_13 * V_16 = F_53 ( V_66 ) ;
struct V_5 * V_6 ;
int V_17 = - V_113 ;
F_86 ( L_7 , F_87 ( V_146 ) , V_16 -> V_36 ) ;
if ( F_88 ( & V_16 -> V_143 ) )
return - V_147 ;
if ( F_89 ( V_148 , & V_16 -> V_36 ) )
goto V_149;
V_6 = F_90 ( sizeof( * V_6 ) , V_150 ) ;
if ( ! V_6 ) {
V_17 = - V_151 ;
goto V_149;
}
F_91 ( & V_6 -> V_11 , & V_16 -> V_14 . V_112 ) ;
V_6 -> V_13 = V_16 ;
V_6 -> V_37 . V_57 = F_92 ( 0 ) ;
V_6 -> V_38 . V_57 = F_92 ( 0 ) ;
V_17 = F_93 ( V_6 ) ;
if ( V_17 )
goto V_152;
V_6 -> V_11 . V_153 = & V_6 -> V_154 . V_155 ;
V_66 -> V_156 = & V_6 -> V_11 ;
F_94 ( & V_6 -> V_11 ) ;
V_6 -> V_36 = V_47 ;
V_6 -> V_33 = 0 ;
V_6 -> V_157 = V_158 ;
V_6 -> V_159 = V_158 ;
V_6 -> V_160 . V_161 = 1 ;
V_6 -> V_11 . V_12 = F_95 ( V_16 -> V_14 . V_15 , V_6 , F_82 ) ;
if ( F_45 ( V_6 -> V_11 . V_12 ) ) {
V_17 = F_46 ( V_6 -> V_11 . V_12 ) ;
goto V_162;
}
if ( V_16 -> V_14 . V_163 ++ == 0 )
F_19 ( V_164 , & V_16 -> V_36 ) ;
V_17 = F_84 ( V_6 ) ;
if ( V_17 < 0 )
goto V_165;
F_96 ( & V_16 -> V_143 ) ;
return 0 ;
V_165:
F_97 ( V_6 -> V_11 . V_12 ) ;
V_162:
F_98 ( V_6 ) ;
V_152:
F_99 ( & V_6 -> V_11 ) ;
F_100 ( & V_6 -> V_11 ) ;
F_101 ( V_6 ) ;
V_149:
F_96 ( & V_16 -> V_143 ) ;
return V_17 ;
}
static int F_102 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_58 ( V_66 -> V_156 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
F_79 ( L_8 ,
F_87 ( V_146 ) , V_16 -> V_36 , V_16 -> V_14 . V_163 ) ;
F_103 ( & V_16 -> V_143 ) ;
F_97 ( V_6 -> V_11 . V_12 ) ;
F_98 ( V_6 ) ;
F_99 ( & V_6 -> V_11 ) ;
F_100 ( & V_6 -> V_11 ) ;
if ( -- V_16 -> V_14 . V_163 <= 0 )
F_104 ( V_164 , & V_16 -> V_36 ) ;
F_101 ( V_6 ) ;
F_96 ( & V_16 -> V_143 ) ;
return 0 ;
}
int F_105 ( struct V_13 * V_16 ,
struct V_166 * V_167 )
{
struct V_168 * V_112 = & V_16 -> V_14 . V_112 ;
int V_17 ;
V_16 -> V_167 = V_167 ;
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
V_112 -> V_169 = & V_170 ;
V_112 -> V_171 = & V_172 ;
V_112 -> V_167 = V_167 ;
V_112 -> V_173 = - 1 ;
V_112 -> V_174 = V_175 ;
V_112 -> V_143 = & V_16 -> V_143 ;
V_112 -> V_176 = V_177 ;
snprintf ( V_112 -> V_78 , sizeof( V_112 -> V_78 ) , L_9 , V_16 -> V_178 ) ;
F_106 ( V_112 , V_16 ) ;
V_16 -> V_14 . V_15 = F_107 ( & V_179 ) ;
if ( F_45 ( V_16 -> V_14 . V_15 ) ) {
F_72 ( V_167 , L_10 ) ;
return F_46 ( V_16 -> V_14 . V_15 ) ;
}
V_17 = F_108 ( & V_112 -> V_180 , 0 , NULL , 0 ) ;
if ( V_17 )
goto V_181;
V_17 = F_109 ( V_112 , V_182 , - 1 ) ;
if ( V_17 )
goto V_183;
F_110 ( V_167 , L_11 ,
V_112 -> V_78 , F_111 ( V_112 ) ) ;
return 0 ;
V_183:
F_112 ( & V_112 -> V_180 ) ;
V_181:
F_113 ( V_16 -> V_14 . V_15 ) ;
return V_17 ;
}
void F_114 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
if ( V_16 -> V_14 . V_15 )
F_113 ( V_16 -> V_14 . V_15 ) ;
if ( F_115 ( & V_16 -> V_14 . V_112 ) ) {
F_116 ( & V_16 -> V_14 . V_112 ) ;
F_112 ( & V_16 -> V_14 . V_112 . V_180 ) ;
}
}
