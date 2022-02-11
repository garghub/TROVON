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
static int F_14 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = V_23 -> V_25 ;
int V_17 ;
V_17 = F_7 ( V_6 ) ;
if ( V_17 == - V_21 )
F_2 ( V_6 , V_28 ) ;
F_15 ( & V_6 -> V_13 -> V_26 -> V_27 ) ;
return 0 ;
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
V_17 = F_22 ( V_6 , V_9 , V_31 , & V_31 -> V_40 ) ;
if ( V_17 )
goto V_41;
V_10 = F_23 ( V_6 -> V_11 . V_12 ) ;
V_17 = F_22 ( V_6 , V_10 , V_32 , & V_32 -> V_40 ) ;
if ( V_17 )
goto V_41;
V_10 -> V_42 . V_43 = V_9 -> V_42 . V_43 ;
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
goto V_41;
F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
if ( V_16 -> V_44 -> V_45 )
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
}
F_36 ( V_16 , & V_31 -> V_40 ) ;
F_37 ( V_16 , & V_32 -> V_40 , - 1 ) ;
F_38 ( V_6 ) ;
V_6 -> V_36 &= ( V_46 | V_47 ) ;
F_39 ( V_16 , true ) ;
V_41:
F_40 ( & V_16 -> V_34 , V_33 ) ;
}
static void F_41 ( void * V_29 )
{
F_7 ( V_29 ) ;
}
static int F_42 ( struct V_22 * V_48 , const struct V_49 * V_50 ,
unsigned int * V_51 , unsigned int * V_52 ,
unsigned int V_53 [] , void * V_54 [] )
{
struct V_5 * V_6 = F_43 ( V_48 ) ;
struct V_30 * V_55 ;
int V_56 ;
V_55 = F_44 ( V_6 , V_48 -> type ) ;
if ( F_45 ( V_55 ) )
return F_46 ( V_55 ) ;
if ( ! V_55 -> V_50 )
return - V_57 ;
* V_52 = V_55 -> V_50 -> V_58 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_50 -> V_58 ; V_56 ++ ) {
V_53 [ V_56 ] = ( V_55 -> V_59 * V_55 -> V_60 * V_55 -> V_50 -> V_61 [ V_56 ] ) / 8 ;
V_54 [ V_56 ] = V_6 -> V_13 -> V_62 ;
}
return 0 ;
}
static int F_47 ( struct V_8 * V_63 )
{
struct V_5 * V_6 = F_43 ( V_63 -> V_22 ) ;
struct V_30 * V_64 ;
int V_56 ;
V_64 = F_44 ( V_6 , V_63 -> V_22 -> type ) ;
if ( F_45 ( V_64 ) )
return F_46 ( V_64 ) ;
for ( V_56 = 0 ; V_56 < V_64 -> V_50 -> V_58 ; V_56 ++ )
F_48 ( V_63 , V_56 , V_64 -> V_65 [ V_56 ] ) ;
return 0 ;
}
static void F_49 ( struct V_8 * V_63 )
{
struct V_5 * V_6 = F_43 ( V_63 -> V_22 ) ;
F_50 ( V_6 -> V_11 . V_12 , V_63 ) ;
}
static int F_51 ( struct V_66 * V_66 , void * V_11 ,
struct V_67 * V_68 )
{
struct V_13 * V_16 = F_52 ( V_66 ) ;
unsigned int V_69 ;
V_69 = V_70 | V_71 |
V_72 | V_73 ;
F_53 ( & V_16 -> V_26 -> V_27 , V_68 , V_69 ) ;
return 0 ;
}
static int F_54 ( struct V_66 * V_66 , void * V_29 ,
struct V_74 * V_55 )
{
struct V_75 * V_50 ;
V_50 = F_55 ( NULL , NULL , F_1 ( V_55 -> type ) ,
V_55 -> V_76 ) ;
if ( ! V_50 )
return - V_57 ;
strncpy ( V_55 -> V_77 , V_50 -> V_78 , sizeof( V_55 -> V_77 ) - 1 ) ;
V_55 -> V_79 = V_50 -> V_80 ;
return 0 ;
}
static int F_56 ( struct V_66 * V_66 , void * V_11 ,
struct V_49 * V_55 )
{
struct V_5 * V_6 = F_57 ( V_11 ) ;
struct V_30 * V_64 = F_44 ( V_6 , V_55 -> type ) ;
if ( F_45 ( V_64 ) )
return F_46 ( V_64 ) ;
F_58 ( V_64 , V_55 ) ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 , struct V_49 * V_55 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
const struct V_81 * V_82 = V_16 -> V_82 ;
struct V_83 * V_84 = & V_55 -> V_50 . V_85 ;
struct V_75 * V_50 ;
T_1 V_86 , V_87 , V_88 ;
if ( ! F_60 ( V_55 -> type ) )
return - V_57 ;
V_50 = F_55 ( & V_84 -> V_79 , NULL ,
F_1 ( V_55 -> type ) , 0 ) ;
if ( F_17 ( V_50 == NULL , L_2 ) )
return - V_57 ;
if ( V_84 -> V_89 == V_90 )
V_84 -> V_89 = V_91 ;
else if ( V_84 -> V_89 != V_91 )
return - V_57 ;
if ( V_55 -> type == V_2 ) {
V_86 = V_82 -> V_92 -> V_93 ;
V_87 = F_61 ( V_82 -> V_94 ) - 1 ;
} else {
V_86 = V_82 -> V_92 -> V_95 ;
V_87 = F_61 ( V_82 -> V_96 ) - 1 ;
}
if ( F_62 ( V_50 ) ) {
V_87 = 6 ;
V_88 = 5 ;
} else {
if ( V_82 -> V_97 == 1 )
V_88 = F_63 ( V_50 -> V_98 ) ? 0 : 1 ;
else
V_88 = F_61 ( V_82 -> V_97 ) - 1 ;
}
F_64 ( & V_84 -> V_99 , 16 , V_86 , V_87 ,
& V_84 -> V_100 , 8 , V_82 -> V_92 -> V_93 , V_88 , 0 ) ;
F_65 ( V_50 , V_84 -> V_99 , V_84 -> V_100 , & V_55 -> V_50 . V_85 ) ;
return 0 ;
}
static int F_66 ( struct V_66 * V_66 , void * V_11 ,
struct V_49 * V_55 )
{
struct V_5 * V_6 = F_57 ( V_11 ) ;
return F_59 ( V_6 , V_55 ) ;
}
static void F_67 ( struct V_30 * V_64 , struct V_75 * V_50 ,
struct V_83 * V_101 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_50 -> V_102 ; V_56 ++ ) {
V_64 -> V_103 [ V_56 ] = V_101 -> V_104 [ V_56 ] . V_103 ;
V_64 -> V_65 [ V_56 ] = V_101 -> V_104 [ V_56 ] . V_105 ;
}
V_64 -> V_59 = V_101 -> V_99 ;
V_64 -> V_60 = V_101 -> V_100 ;
V_64 -> V_106 = V_101 -> V_99 ;
V_64 -> V_107 = V_101 -> V_100 ;
V_64 -> V_99 = V_101 -> V_99 ;
V_64 -> V_100 = V_101 -> V_100 ;
V_64 -> V_108 = 0 ;
V_64 -> V_109 = 0 ;
V_64 -> V_50 = V_50 ;
}
static int F_68 ( struct V_66 * V_66 , void * V_11 ,
struct V_49 * V_55 )
{
struct V_5 * V_6 = F_57 ( V_11 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_75 * V_50 ;
struct V_22 * V_48 ;
struct V_30 * V_64 ;
int V_17 ;
V_17 = F_59 ( V_6 , V_55 ) ;
if ( V_17 )
return V_17 ;
V_48 = F_69 ( V_6 -> V_11 . V_12 , V_55 -> type ) ;
if ( F_70 ( V_48 ) ) {
F_71 ( & V_16 -> V_14 . V_110 , L_3 , V_55 -> type ) ;
return - V_111 ;
}
if ( V_55 -> type == V_2 )
V_64 = & V_6 -> V_37 ;
else
V_64 = & V_6 -> V_38 ;
V_50 = F_55 ( & V_55 -> V_50 . V_85 . V_79 , NULL ,
F_1 ( V_55 -> type ) , 0 ) ;
if ( ! V_50 )
return - V_57 ;
F_67 ( V_64 , V_50 , & V_55 -> V_50 . V_85 ) ;
F_72 ( V_6 ) ;
return 0 ;
}
static int F_73 ( struct V_66 * V_66 , void * V_11 ,
struct V_112 * V_113 )
{
struct V_5 * V_6 = F_57 ( V_11 ) ;
struct V_30 * V_64 ;
V_64 = F_44 ( V_6 , V_113 -> type ) ;
if ( F_45 ( V_64 ) )
return F_46 ( V_64 ) ;
V_113 -> V_114 . V_115 = 0 ;
V_113 -> V_114 . V_116 = 0 ;
V_113 -> V_114 . V_99 = V_64 -> V_106 ;
V_113 -> V_114 . V_100 = V_64 -> V_107 ;
V_113 -> V_117 = V_113 -> V_114 ;
return 0 ;
}
static int F_74 ( struct V_66 * V_66 , void * V_11 , struct V_118 * V_113 )
{
struct V_5 * V_6 = F_57 ( V_11 ) ;
struct V_30 * V_64 ;
V_64 = F_44 ( V_6 , V_113 -> type ) ;
if ( F_45 ( V_64 ) )
return F_46 ( V_64 ) ;
V_113 -> V_119 . V_115 = V_64 -> V_108 ;
V_113 -> V_119 . V_116 = V_64 -> V_109 ;
V_113 -> V_119 . V_99 = V_64 -> V_99 ;
V_113 -> V_119 . V_100 = V_64 -> V_100 ;
return 0 ;
}
static int F_75 ( struct V_5 * V_6 , struct V_118 * V_113 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_30 * V_55 ;
T_1 V_120 , V_121 , V_61 = 0 ;
int V_56 ;
if ( V_113 -> V_119 . V_116 < 0 || V_113 -> V_119 . V_115 < 0 ) {
F_71 ( & V_16 -> V_14 . V_110 ,
L_4 ) ;
return - V_57 ;
}
if ( V_113 -> type == V_122 )
V_55 = & V_6 -> V_38 ;
else if ( V_113 -> type == V_2 )
V_55 = & V_6 -> V_37 ;
else
return - V_57 ;
V_120 = ( V_55 == & V_6 -> V_37 ) ?
V_16 -> V_82 -> V_94 : V_16 -> V_82 -> V_96 ;
if ( V_16 -> V_82 -> V_97 == 1 )
V_121 = F_63 ( V_55 -> V_50 -> V_98 ) ? 0 : 1 ;
else
V_121 = F_61 ( V_16 -> V_82 -> V_97 ) - 1 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_50 -> V_102 ; V_56 ++ )
V_61 += V_55 -> V_50 -> V_61 [ V_56 ] ;
F_64 ( & V_113 -> V_119 . V_99 , V_120 , V_55 -> V_106 ,
F_61 ( V_120 ) - 1 ,
& V_113 -> V_119 . V_100 , V_120 , V_55 -> V_107 ,
V_121 , 64 / ( F_76 ( V_61 , 8 ) ) ) ;
if ( V_113 -> V_119 . V_115 + V_113 -> V_119 . V_99 > V_55 -> V_106 )
V_113 -> V_119 . V_115 = V_55 -> V_106 - V_113 -> V_119 . V_99 ;
if ( V_113 -> V_119 . V_116 + V_113 -> V_119 . V_100 > V_55 -> V_107 )
V_113 -> V_119 . V_116 = V_55 -> V_107 - V_113 -> V_119 . V_100 ;
V_113 -> V_119 . V_115 = F_77 ( V_113 -> V_119 . V_115 , V_120 ) ;
V_113 -> V_119 . V_116 = F_77 ( V_113 -> V_119 . V_116 , V_16 -> V_82 -> V_123 ) ;
F_78 ( L_5 ,
V_113 -> V_119 . V_115 , V_113 -> V_119 . V_116 , V_113 -> V_119 . V_99 , V_113 -> V_119 . V_100 ,
V_55 -> V_59 , V_55 -> V_60 ) ;
return 0 ;
}
static int F_79 ( struct V_66 * V_66 , void * V_11 , const struct V_118 * V_124 )
{
struct V_5 * V_6 = F_57 ( V_11 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_118 V_113 = * V_124 ;
struct V_30 * V_55 ;
int V_17 ;
V_17 = F_75 ( V_6 , & V_113 ) ;
if ( V_17 )
return V_17 ;
V_55 = ( V_113 . type == V_2 ) ?
& V_6 -> V_37 : & V_6 -> V_38 ;
if ( V_113 . type == V_2 ) {
V_17 = F_80 ( V_6 , V_113 . V_119 . V_99 ,
V_113 . V_119 . V_100 , V_6 -> V_38 . V_99 ,
V_6 -> V_38 . V_100 , V_6 -> V_125 ) ;
} else {
V_17 = F_80 ( V_6 , V_6 -> V_37 . V_99 ,
V_6 -> V_37 . V_100 , V_113 . V_119 . V_99 ,
V_113 . V_119 . V_100 , V_6 -> V_125 ) ;
}
if ( V_17 ) {
F_71 ( & V_16 -> V_14 . V_110 , L_6 ) ;
return - V_57 ;
}
V_55 -> V_108 = V_113 . V_119 . V_115 ;
V_55 -> V_109 = V_113 . V_119 . V_116 ;
V_55 -> V_99 = V_113 . V_119 . V_99 ;
V_55 -> V_100 = V_113 . V_119 . V_100 ;
F_9 ( V_39 , V_6 ) ;
return 0 ;
}
static int F_81 ( void * V_29 , struct V_22 * V_126 ,
struct V_22 * V_127 )
{
struct V_5 * V_6 = V_29 ;
int V_17 ;
V_126 -> type = V_2 ;
V_126 -> V_128 = V_129 | V_130 | V_131 ;
V_126 -> V_25 = V_6 ;
V_126 -> V_132 = & V_133 ;
V_126 -> V_134 = & V_135 ;
V_126 -> V_136 = sizeof( struct V_137 ) ;
V_126 -> V_138 = V_139 ;
V_126 -> V_140 = & V_6 -> V_13 -> V_140 ;
V_17 = F_82 ( V_126 ) ;
if ( V_17 )
return V_17 ;
V_127 -> type = V_122 ;
V_127 -> V_128 = V_129 | V_130 | V_131 ;
V_127 -> V_25 = V_6 ;
V_127 -> V_132 = & V_133 ;
V_127 -> V_134 = & V_135 ;
V_127 -> V_136 = sizeof( struct V_137 ) ;
V_127 -> V_138 = V_139 ;
V_127 -> V_140 = & V_6 -> V_13 -> V_140 ;
return F_82 ( V_127 ) ;
}
static int F_83 ( struct V_5 * V_6 )
{
struct V_83 V_101 = {
. V_79 = V_141 ,
. V_99 = 800 ,
. V_100 = 600 ,
. V_104 [ 0 ] = {
. V_103 = 800 * 4 ,
. V_105 = 800 * 4 * 600 ,
} ,
} ;
struct V_75 * V_50 ;
V_50 = F_55 ( & V_101 . V_79 , NULL , V_142 , 0 ) ;
if ( ! V_50 )
return - V_57 ;
F_67 ( & V_6 -> V_37 , V_50 , & V_101 ) ;
F_67 ( & V_6 -> V_38 , V_50 , & V_101 ) ;
return 0 ;
}
static int F_84 ( struct V_66 * V_66 )
{
struct V_13 * V_16 = F_52 ( V_66 ) ;
struct V_5 * V_6 ;
int V_17 = - V_111 ;
F_85 ( L_7 , F_86 ( V_143 ) , V_16 -> V_36 ) ;
if ( F_87 ( & V_16 -> V_140 ) )
return - V_144 ;
if ( F_88 ( V_145 , & V_16 -> V_36 ) )
goto V_146;
V_6 = F_89 ( sizeof( * V_6 ) , V_147 ) ;
if ( ! V_6 ) {
V_17 = - V_148 ;
goto V_146;
}
F_90 ( & V_6 -> V_11 , & V_16 -> V_14 . V_110 ) ;
V_6 -> V_13 = V_16 ;
V_6 -> V_37 . V_50 = F_91 ( 0 ) ;
V_6 -> V_38 . V_50 = F_91 ( 0 ) ;
V_17 = F_92 ( V_6 ) ;
if ( V_17 )
goto V_149;
V_6 -> V_11 . V_150 = & V_6 -> V_151 . V_152 ;
V_66 -> V_153 = & V_6 -> V_11 ;
F_93 ( & V_6 -> V_11 ) ;
V_6 -> V_36 = V_46 ;
V_6 -> V_33 = 0 ;
V_6 -> V_154 = V_155 ;
V_6 -> V_156 = V_155 ;
V_6 -> V_157 . V_158 = 1 ;
V_6 -> V_11 . V_12 = F_94 ( V_16 -> V_14 . V_15 , V_6 , F_81 ) ;
if ( F_45 ( V_6 -> V_11 . V_12 ) ) {
V_17 = F_46 ( V_6 -> V_11 . V_12 ) ;
goto V_159;
}
if ( V_16 -> V_14 . V_160 ++ == 0 )
F_19 ( V_161 , & V_16 -> V_36 ) ;
V_17 = F_83 ( V_6 ) ;
if ( V_17 < 0 )
goto V_162;
F_95 ( & V_16 -> V_140 ) ;
return 0 ;
V_162:
F_96 ( V_6 -> V_11 . V_12 ) ;
V_159:
F_97 ( V_6 ) ;
V_149:
F_98 ( & V_6 -> V_11 ) ;
F_99 ( & V_6 -> V_11 ) ;
F_100 ( V_6 ) ;
V_146:
F_95 ( & V_16 -> V_140 ) ;
return V_17 ;
}
static int F_101 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_57 ( V_66 -> V_153 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
F_78 ( L_8 ,
F_86 ( V_143 ) , V_16 -> V_36 , V_16 -> V_14 . V_160 ) ;
F_102 ( & V_16 -> V_140 ) ;
F_96 ( V_6 -> V_11 . V_12 ) ;
F_97 ( V_6 ) ;
F_98 ( & V_6 -> V_11 ) ;
F_99 ( & V_6 -> V_11 ) ;
if ( -- V_16 -> V_14 . V_160 <= 0 )
F_103 ( V_161 , & V_16 -> V_36 ) ;
F_100 ( V_6 ) ;
F_95 ( & V_16 -> V_140 ) ;
return 0 ;
}
int F_104 ( struct V_13 * V_16 ,
struct V_163 * V_164 )
{
struct V_165 * V_110 = & V_16 -> V_14 . V_110 ;
int V_17 ;
V_16 -> V_164 = V_164 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_166 = & V_167 ;
V_110 -> V_168 = & V_169 ;
V_110 -> V_164 = V_164 ;
V_110 -> V_170 = - 1 ;
V_110 -> V_171 = V_172 ;
V_110 -> V_140 = & V_16 -> V_140 ;
V_110 -> V_173 = V_174 ;
snprintf ( V_110 -> V_78 , sizeof( V_110 -> V_78 ) , L_9 , V_16 -> V_175 ) ;
F_105 ( V_110 , V_16 ) ;
V_16 -> V_14 . V_15 = F_106 ( & V_176 ) ;
if ( F_45 ( V_16 -> V_14 . V_15 ) ) {
F_71 ( V_164 , L_10 ) ;
return F_46 ( V_16 -> V_14 . V_15 ) ;
}
V_17 = F_107 ( & V_110 -> V_177 , 0 , NULL , 0 ) ;
if ( V_17 )
goto V_178;
V_17 = F_108 ( V_110 , V_179 , - 1 ) ;
if ( V_17 )
goto V_180;
F_109 ( V_164 , L_11 ,
V_110 -> V_78 , F_110 ( V_110 ) ) ;
return 0 ;
V_180:
F_111 ( & V_110 -> V_177 ) ;
V_178:
F_112 ( V_16 -> V_14 . V_15 ) ;
return V_17 ;
}
void F_113 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
if ( V_16 -> V_14 . V_15 )
F_112 ( V_16 -> V_14 . V_15 ) ;
if ( F_114 ( & V_16 -> V_14 . V_110 ) ) {
F_115 ( & V_16 -> V_14 . V_110 ) ;
F_111 ( & V_16 -> V_14 . V_110 . V_177 ) ;
}
}
