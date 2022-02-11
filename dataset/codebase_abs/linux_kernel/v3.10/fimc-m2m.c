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
if ( ! V_6 || ! V_6 -> V_11 )
return;
V_9 = F_3 ( V_6 -> V_11 ) ;
V_10 = F_4 ( V_6 -> V_11 ) ;
if ( V_9 && V_10 ) {
F_5 ( V_9 , V_7 ) ;
F_5 ( V_10 , V_7 ) ;
F_6 ( V_6 -> V_12 -> V_13 . V_14 ,
V_6 -> V_11 ) ;
}
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_12 * V_15 = V_6 -> V_12 ;
int V_16 ;
if ( ! F_8 ( V_15 ) )
return 0 ;
F_9 ( V_17 , V_6 ) ;
V_16 = F_10 ( V_15 -> V_18 ,
! F_11 ( V_17 , V_6 ) ,
V_19 ) ;
return V_16 == 0 ? - V_20 : V_16 ;
}
static int F_12 ( struct V_21 * V_22 , unsigned int V_23 )
{
struct V_5 * V_6 = V_22 -> V_24 ;
int V_16 ;
V_16 = F_13 ( & V_6 -> V_12 -> V_25 -> V_26 ) ;
return V_16 > 0 ? 0 : V_16 ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_5 * V_6 = V_22 -> V_24 ;
int V_16 ;
V_16 = F_7 ( V_6 ) ;
if ( V_16 == - V_20 )
F_2 ( V_6 , V_27 ) ;
F_15 ( & V_6 -> V_12 -> V_25 -> V_26 ) ;
return 0 ;
}
static void F_16 ( void * V_28 )
{
struct V_8 * V_9 , * V_10 ;
struct V_5 * V_6 = V_28 ;
struct V_29 * V_30 , * V_31 ;
struct V_12 * V_15 ;
unsigned long V_32 ;
int V_16 ;
if ( F_17 ( ! V_6 , L_1 ) )
return;
V_15 = V_6 -> V_12 ;
F_18 ( & V_15 -> V_33 , V_32 ) ;
F_19 ( V_34 , & V_15 -> V_35 ) ;
V_30 = & V_6 -> V_36 ;
V_31 = & V_6 -> V_37 ;
if ( V_6 -> V_35 & V_38 ) {
F_20 ( V_6 , V_30 ) ;
F_20 ( V_6 , V_31 ) ;
}
V_9 = F_21 ( V_6 -> V_11 ) ;
V_16 = F_22 ( V_6 , V_9 , V_30 , & V_30 -> V_39 ) ;
if ( V_16 )
goto V_40;
V_10 = F_23 ( V_6 -> V_11 ) ;
V_16 = F_22 ( V_6 , V_10 , V_31 , & V_31 -> V_39 ) ;
if ( V_16 )
goto V_40;
V_10 -> V_41 . V_42 = V_9 -> V_41 . V_42 ;
if ( V_15 -> V_13 . V_6 != V_6 ) {
V_6 -> V_35 |= V_38 ;
V_15 -> V_13 . V_6 = V_6 ;
}
if ( V_6 -> V_35 & V_38 ) {
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
V_16 = F_27 ( V_6 ) ;
if ( V_16 )
goto V_40;
F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
if ( V_15 -> V_43 -> V_44 )
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
}
F_36 ( V_15 , & V_30 -> V_39 ) ;
F_37 ( V_15 , & V_31 -> V_39 , - 1 ) ;
F_38 ( V_6 ) ;
V_6 -> V_35 &= ( V_45 | V_46 ) ;
F_39 ( V_15 , true ) ;
V_40:
F_40 ( & V_15 -> V_33 , V_32 ) ;
}
static void F_41 ( void * V_28 )
{
F_7 ( V_28 ) ;
}
static int F_42 ( struct V_21 * V_47 , const struct V_48 * V_49 ,
unsigned int * V_50 , unsigned int * V_51 ,
unsigned int V_52 [] , void * V_53 [] )
{
struct V_5 * V_6 = F_43 ( V_47 ) ;
struct V_29 * V_54 ;
int V_55 ;
V_54 = F_44 ( V_6 , V_47 -> type ) ;
if ( F_45 ( V_54 ) )
return F_46 ( V_54 ) ;
if ( ! V_54 -> V_49 )
return - V_56 ;
* V_51 = V_54 -> V_49 -> V_57 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_49 -> V_57 ; V_55 ++ ) {
V_52 [ V_55 ] = ( V_54 -> V_58 * V_54 -> V_59 * V_54 -> V_49 -> V_60 [ V_55 ] ) / 8 ;
V_53 [ V_55 ] = V_6 -> V_12 -> V_61 ;
}
return 0 ;
}
static int F_47 ( struct V_8 * V_62 )
{
struct V_5 * V_6 = F_43 ( V_62 -> V_21 ) ;
struct V_29 * V_63 ;
int V_55 ;
V_63 = F_44 ( V_6 , V_62 -> V_21 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
for ( V_55 = 0 ; V_55 < V_63 -> V_49 -> V_57 ; V_55 ++ )
F_48 ( V_62 , V_55 , V_63 -> V_64 [ V_55 ] ) ;
return 0 ;
}
static void F_49 ( struct V_8 * V_62 )
{
struct V_5 * V_6 = F_43 ( V_62 -> V_21 ) ;
F_50 ( L_2 , V_6 , V_6 -> V_35 ) ;
if ( V_6 -> V_11 )
F_51 ( V_6 -> V_11 , V_62 ) ;
}
static void F_52 ( struct V_21 * V_47 )
{
struct V_5 * V_6 = F_43 ( V_47 ) ;
F_53 ( & V_6 -> V_12 -> V_65 ) ;
}
static void F_54 ( struct V_21 * V_47 )
{
struct V_5 * V_6 = F_43 ( V_47 ) ;
F_55 ( & V_6 -> V_12 -> V_65 ) ;
}
static int F_56 ( struct V_66 * V_66 , void * V_67 ,
struct V_68 * V_69 )
{
struct V_12 * V_15 = F_57 ( V_66 ) ;
unsigned int V_70 ;
V_70 = V_71 | V_72 |
V_73 | V_74 ;
F_58 ( & V_15 -> V_25 -> V_26 , V_69 , V_70 ) ;
return 0 ;
}
static int F_59 ( struct V_66 * V_66 , void * V_28 ,
struct V_75 * V_54 )
{
struct V_76 * V_49 ;
V_49 = F_60 ( NULL , NULL , F_1 ( V_54 -> type ) ,
V_54 -> V_77 ) ;
if ( ! V_49 )
return - V_56 ;
strncpy ( V_54 -> V_78 , V_49 -> V_79 , sizeof( V_54 -> V_78 ) - 1 ) ;
V_54 -> V_80 = V_49 -> V_81 ;
return 0 ;
}
static int F_61 ( struct V_66 * V_66 , void * V_67 ,
struct V_48 * V_54 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
struct V_29 * V_63 = F_44 ( V_6 , V_54 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
F_63 ( V_63 , V_54 ) ;
return 0 ;
}
static int F_64 ( struct V_5 * V_6 , struct V_48 * V_54 )
{
struct V_12 * V_15 = V_6 -> V_12 ;
const struct V_82 * V_83 = V_15 -> V_83 ;
struct V_84 * V_85 = & V_54 -> V_49 . V_86 ;
struct V_76 * V_49 ;
T_1 V_87 , V_88 , V_89 ;
if ( ! F_65 ( V_54 -> type ) )
return - V_56 ;
V_49 = F_60 ( & V_85 -> V_80 , NULL ,
F_1 ( V_54 -> type ) , 0 ) ;
if ( F_17 ( V_49 == NULL , L_3 ) )
return - V_56 ;
if ( V_85 -> V_90 == V_91 )
V_85 -> V_90 = V_92 ;
else if ( V_85 -> V_90 != V_92 )
return - V_56 ;
if ( V_54 -> type == V_2 ) {
V_87 = V_83 -> V_93 -> V_94 ;
V_88 = F_66 ( V_83 -> V_95 ) - 1 ;
} else {
V_87 = V_83 -> V_93 -> V_96 ;
V_88 = F_66 ( V_83 -> V_97 ) - 1 ;
}
if ( F_67 ( V_49 ) ) {
V_88 = 6 ;
V_89 = 5 ;
} else {
if ( V_83 -> V_98 == 1 )
V_89 = F_68 ( V_49 -> V_99 ) ? 0 : 1 ;
else
V_89 = F_66 ( V_83 -> V_98 ) - 1 ;
}
F_69 ( & V_85 -> V_100 , 16 , V_87 , V_88 ,
& V_85 -> V_101 , 8 , V_83 -> V_93 -> V_94 , V_89 , 0 ) ;
F_70 ( V_49 , V_85 -> V_100 , V_85 -> V_101 , & V_54 -> V_49 . V_86 ) ;
return 0 ;
}
static int F_71 ( struct V_66 * V_66 , void * V_67 ,
struct V_48 * V_54 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
return F_64 ( V_6 , V_54 ) ;
}
static void F_72 ( struct V_29 * V_63 , struct V_76 * V_49 ,
struct V_84 * V_102 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_49 -> V_103 ; V_55 ++ ) {
V_63 -> V_104 [ V_55 ] = V_102 -> V_105 [ V_55 ] . V_104 ;
V_63 -> V_64 [ V_55 ] = V_102 -> V_105 [ V_55 ] . V_106 ;
}
V_63 -> V_58 = V_102 -> V_100 ;
V_63 -> V_59 = V_102 -> V_101 ;
V_63 -> V_107 = V_102 -> V_100 ;
V_63 -> V_108 = V_102 -> V_101 ;
V_63 -> V_100 = V_102 -> V_100 ;
V_63 -> V_101 = V_102 -> V_101 ;
V_63 -> V_109 = 0 ;
V_63 -> V_110 = 0 ;
V_63 -> V_49 = V_49 ;
}
static int F_73 ( struct V_66 * V_66 , void * V_67 ,
struct V_48 * V_54 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_76 * V_49 ;
struct V_21 * V_47 ;
struct V_29 * V_63 ;
int V_16 ;
V_16 = F_64 ( V_6 , V_54 ) ;
if ( V_16 )
return V_16 ;
V_47 = F_74 ( V_6 -> V_11 , V_54 -> type ) ;
if ( F_75 ( V_47 ) ) {
F_76 ( & V_15 -> V_13 . V_111 , L_4 , V_54 -> type ) ;
return - V_112 ;
}
if ( V_54 -> type == V_2 )
V_63 = & V_6 -> V_36 ;
else
V_63 = & V_6 -> V_37 ;
V_49 = F_60 ( & V_54 -> V_49 . V_86 . V_80 , NULL ,
F_1 ( V_54 -> type ) , 0 ) ;
if ( ! V_49 )
return - V_56 ;
F_72 ( V_63 , V_49 , & V_54 -> V_49 . V_86 ) ;
F_77 ( V_6 ) ;
return 0 ;
}
static int F_78 ( struct V_66 * V_66 , void * V_67 ,
struct V_113 * V_114 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
return F_79 ( V_66 , V_6 -> V_11 , V_114 ) ;
}
static int F_80 ( struct V_66 * V_66 , void * V_67 ,
struct V_115 * V_116 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
return F_81 ( V_66 , V_6 -> V_11 , V_116 ) ;
}
static int F_82 ( struct V_66 * V_66 , void * V_67 ,
struct V_115 * V_116 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
return F_83 ( V_66 , V_6 -> V_11 , V_116 ) ;
}
static int F_84 ( struct V_66 * V_66 , void * V_67 ,
struct V_115 * V_116 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
return F_85 ( V_66 , V_6 -> V_11 , V_116 ) ;
}
static int F_86 ( struct V_66 * V_66 , void * V_67 ,
struct V_117 * V_118 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
return F_87 ( V_66 , V_6 -> V_11 , V_118 ) ;
}
static int F_88 ( struct V_66 * V_66 , void * V_67 ,
enum V_119 type )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
return F_89 ( V_66 , V_6 -> V_11 , type ) ;
}
static int F_90 ( struct V_66 * V_66 , void * V_67 ,
enum V_119 type )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
return F_91 ( V_66 , V_6 -> V_11 , type ) ;
}
static int F_92 ( struct V_66 * V_66 , void * V_67 ,
struct V_120 * V_121 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
struct V_29 * V_63 ;
V_63 = F_44 ( V_6 , V_121 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
V_121 -> V_122 . V_123 = 0 ;
V_121 -> V_122 . V_124 = 0 ;
V_121 -> V_122 . V_100 = V_63 -> V_107 ;
V_121 -> V_122 . V_101 = V_63 -> V_108 ;
V_121 -> V_125 = V_121 -> V_122 ;
return 0 ;
}
static int F_93 ( struct V_66 * V_66 , void * V_67 , struct V_126 * V_121 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
struct V_29 * V_63 ;
V_63 = F_44 ( V_6 , V_121 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
V_121 -> V_127 . V_123 = V_63 -> V_109 ;
V_121 -> V_127 . V_124 = V_63 -> V_110 ;
V_121 -> V_127 . V_100 = V_63 -> V_100 ;
V_121 -> V_127 . V_101 = V_63 -> V_101 ;
return 0 ;
}
static int F_94 ( struct V_5 * V_6 , struct V_126 * V_121 )
{
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_29 * V_54 ;
T_1 V_128 , V_129 , V_60 = 0 ;
int V_55 ;
if ( V_121 -> V_127 . V_124 < 0 || V_121 -> V_127 . V_123 < 0 ) {
F_76 ( & V_15 -> V_13 . V_111 ,
L_5 ) ;
return - V_56 ;
}
if ( V_121 -> type == V_130 )
V_54 = & V_6 -> V_37 ;
else if ( V_121 -> type == V_2 )
V_54 = & V_6 -> V_36 ;
else
return - V_56 ;
V_128 = ( V_54 == & V_6 -> V_36 ) ?
V_15 -> V_83 -> V_95 : V_15 -> V_83 -> V_97 ;
if ( V_15 -> V_83 -> V_98 == 1 )
V_129 = F_68 ( V_54 -> V_49 -> V_99 ) ? 0 : 1 ;
else
V_129 = F_66 ( V_15 -> V_83 -> V_98 ) - 1 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_49 -> V_103 ; V_55 ++ )
V_60 += V_54 -> V_49 -> V_60 [ V_55 ] ;
F_69 ( & V_121 -> V_127 . V_100 , V_128 , V_54 -> V_107 ,
F_66 ( V_128 ) - 1 ,
& V_121 -> V_127 . V_101 , V_128 , V_54 -> V_108 ,
V_129 , 64 / ( F_95 ( V_60 , 8 ) ) ) ;
if ( V_121 -> V_127 . V_123 + V_121 -> V_127 . V_100 > V_54 -> V_107 )
V_121 -> V_127 . V_123 = V_54 -> V_107 - V_121 -> V_127 . V_100 ;
if ( V_121 -> V_127 . V_124 + V_121 -> V_127 . V_101 > V_54 -> V_108 )
V_121 -> V_127 . V_124 = V_54 -> V_108 - V_121 -> V_127 . V_101 ;
V_121 -> V_127 . V_123 = F_96 ( V_121 -> V_127 . V_123 , V_128 ) ;
V_121 -> V_127 . V_124 = F_96 ( V_121 -> V_127 . V_124 , V_15 -> V_83 -> V_131 ) ;
F_50 ( L_6 ,
V_121 -> V_127 . V_123 , V_121 -> V_127 . V_124 , V_121 -> V_127 . V_100 , V_121 -> V_127 . V_101 ,
V_54 -> V_58 , V_54 -> V_59 ) ;
return 0 ;
}
static int F_97 ( struct V_66 * V_66 , void * V_67 , const struct V_126 * V_132 )
{
struct V_5 * V_6 = F_62 ( V_67 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_126 V_121 = * V_132 ;
struct V_29 * V_54 ;
int V_16 ;
V_16 = F_94 ( V_6 , & V_121 ) ;
if ( V_16 )
return V_16 ;
V_54 = ( V_121 . type == V_2 ) ?
& V_6 -> V_36 : & V_6 -> V_37 ;
if ( V_121 . type == V_2 ) {
V_16 = F_98 ( V_6 , V_121 . V_127 . V_100 ,
V_121 . V_127 . V_101 , V_6 -> V_37 . V_100 ,
V_6 -> V_37 . V_101 , V_6 -> V_133 ) ;
} else {
V_16 = F_98 ( V_6 , V_6 -> V_36 . V_100 ,
V_6 -> V_36 . V_101 , V_121 . V_127 . V_100 ,
V_121 . V_127 . V_101 , V_6 -> V_133 ) ;
}
if ( V_16 ) {
F_76 ( & V_15 -> V_13 . V_111 , L_7 ) ;
return - V_56 ;
}
V_54 -> V_109 = V_121 . V_127 . V_123 ;
V_54 -> V_110 = V_121 . V_127 . V_124 ;
V_54 -> V_100 = V_121 . V_127 . V_100 ;
V_54 -> V_101 = V_121 . V_127 . V_101 ;
F_9 ( V_38 , V_6 ) ;
return 0 ;
}
static int F_99 ( void * V_28 , struct V_21 * V_134 ,
struct V_21 * V_135 )
{
struct V_5 * V_6 = V_28 ;
int V_16 ;
V_134 -> type = V_2 ;
V_134 -> V_136 = V_137 | V_138 | V_139 ;
V_134 -> V_24 = V_6 ;
V_134 -> V_140 = & V_141 ;
V_134 -> V_142 = & V_143 ;
V_134 -> V_144 = sizeof( struct V_145 ) ;
V_134 -> V_146 = V_147 ;
V_16 = F_100 ( V_134 ) ;
if ( V_16 )
return V_16 ;
V_135 -> type = V_130 ;
V_135 -> V_136 = V_137 | V_138 | V_139 ;
V_135 -> V_24 = V_6 ;
V_135 -> V_140 = & V_141 ;
V_135 -> V_142 = & V_143 ;
V_135 -> V_144 = sizeof( struct V_145 ) ;
V_135 -> V_146 = V_147 ;
return F_100 ( V_135 ) ;
}
static int F_101 ( struct V_5 * V_6 )
{
struct V_84 V_102 = {
. V_80 = V_148 ,
. V_100 = 800 ,
. V_101 = 600 ,
. V_105 [ 0 ] = {
. V_104 = 800 * 4 ,
. V_106 = 800 * 4 * 600 ,
} ,
} ;
struct V_76 * V_49 ;
V_49 = F_60 ( & V_102 . V_80 , NULL , V_149 , 0 ) ;
if ( ! V_49 )
return - V_56 ;
F_72 ( & V_6 -> V_36 , V_49 , & V_102 ) ;
F_72 ( & V_6 -> V_37 , V_49 , & V_102 ) ;
return 0 ;
}
static int F_102 ( struct V_66 * V_66 )
{
struct V_12 * V_15 = F_57 ( V_66 ) ;
struct V_5 * V_6 ;
int V_16 = - V_112 ;
F_103 ( L_8 , F_104 ( V_150 ) , V_15 -> V_35 ) ;
if ( F_105 ( & V_15 -> V_65 ) )
return - V_151 ;
if ( F_106 ( V_152 , & V_15 -> V_35 ) )
goto V_153;
V_6 = F_107 ( sizeof( * V_6 ) , V_154 ) ;
if ( ! V_6 ) {
V_16 = - V_155 ;
goto V_153;
}
F_108 ( & V_6 -> V_67 , & V_15 -> V_13 . V_111 ) ;
V_6 -> V_12 = V_15 ;
V_6 -> V_36 . V_49 = F_109 ( 0 ) ;
V_6 -> V_37 . V_49 = F_109 ( 0 ) ;
V_16 = F_110 ( V_6 ) ;
if ( V_16 )
goto V_156;
V_6 -> V_67 . V_157 = & V_6 -> V_158 . V_159 ;
V_66 -> V_160 = & V_6 -> V_67 ;
F_111 ( & V_6 -> V_67 ) ;
V_6 -> V_35 = V_45 ;
V_6 -> V_32 = 0 ;
V_6 -> V_161 = V_162 ;
V_6 -> V_163 = V_162 ;
V_6 -> V_164 . V_165 = 1 ;
V_6 -> V_11 = F_112 ( V_15 -> V_13 . V_14 , V_6 , F_99 ) ;
if ( F_45 ( V_6 -> V_11 ) ) {
V_16 = F_46 ( V_6 -> V_11 ) ;
goto V_166;
}
if ( V_15 -> V_13 . V_167 ++ == 0 )
F_19 ( V_168 , & V_15 -> V_35 ) ;
V_16 = F_101 ( V_6 ) ;
if ( V_16 < 0 )
goto V_169;
F_55 ( & V_15 -> V_65 ) ;
return 0 ;
V_169:
F_113 ( V_6 -> V_11 ) ;
V_166:
F_114 ( V_6 ) ;
V_156:
F_115 ( & V_6 -> V_67 ) ;
F_116 ( & V_6 -> V_67 ) ;
F_117 ( V_6 ) ;
V_153:
F_55 ( & V_15 -> V_65 ) ;
return V_16 ;
}
static int F_118 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_62 ( V_66 -> V_160 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
F_50 ( L_9 ,
F_104 ( V_150 ) , V_15 -> V_35 , V_15 -> V_13 . V_167 ) ;
F_53 ( & V_15 -> V_65 ) ;
F_113 ( V_6 -> V_11 ) ;
F_114 ( V_6 ) ;
F_115 ( & V_6 -> V_67 ) ;
F_116 ( & V_6 -> V_67 ) ;
if ( -- V_15 -> V_13 . V_167 <= 0 )
F_119 ( V_168 , & V_15 -> V_35 ) ;
F_117 ( V_6 ) ;
F_55 ( & V_15 -> V_65 ) ;
return 0 ;
}
static unsigned int F_120 ( struct V_66 * V_66 ,
struct V_170 * V_171 )
{
struct V_5 * V_6 = F_62 ( V_66 -> V_160 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
int V_16 ;
if ( F_105 ( & V_15 -> V_65 ) )
return - V_151 ;
V_16 = F_121 ( V_66 , V_6 -> V_11 , V_171 ) ;
F_55 ( & V_15 -> V_65 ) ;
return V_16 ;
}
static int F_122 ( struct V_66 * V_66 , struct V_172 * V_173 )
{
struct V_5 * V_6 = F_62 ( V_66 -> V_160 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
int V_16 ;
if ( F_105 ( & V_15 -> V_65 ) )
return - V_151 ;
V_16 = F_123 ( V_66 , V_6 -> V_11 , V_173 ) ;
F_55 ( & V_15 -> V_65 ) ;
return V_16 ;
}
int F_124 ( struct V_12 * V_15 ,
struct V_174 * V_175 )
{
struct V_176 * V_111 = & V_15 -> V_13 . V_111 ;
int V_16 ;
V_15 -> V_175 = V_175 ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
V_111 -> V_177 = & V_178 ;
V_111 -> V_179 = & V_180 ;
V_111 -> V_175 = V_175 ;
V_111 -> V_181 = - 1 ;
V_111 -> V_182 = V_183 ;
V_111 -> V_65 = & V_15 -> V_65 ;
V_111 -> V_184 = V_185 ;
snprintf ( V_111 -> V_79 , sizeof( V_111 -> V_79 ) , L_10 , V_15 -> V_186 ) ;
F_125 ( V_111 , V_15 ) ;
V_15 -> V_13 . V_14 = F_126 ( & V_187 ) ;
if ( F_45 ( V_15 -> V_13 . V_14 ) ) {
F_76 ( V_175 , L_11 ) ;
return F_46 ( V_15 -> V_13 . V_14 ) ;
}
V_16 = F_127 ( & V_111 -> V_188 , 0 , NULL , 0 ) ;
if ( V_16 )
goto V_189;
V_16 = F_128 ( V_111 , V_190 , - 1 ) ;
if ( V_16 )
goto V_191;
F_129 ( V_175 , L_12 ,
V_111 -> V_79 , F_130 ( V_111 ) ) ;
return 0 ;
V_191:
F_131 ( & V_111 -> V_188 ) ;
V_189:
F_132 ( V_15 -> V_13 . V_14 ) ;
return V_16 ;
}
void F_133 ( struct V_12 * V_15 )
{
if ( ! V_15 )
return;
if ( V_15 -> V_13 . V_14 )
F_132 ( V_15 -> V_13 . V_14 ) ;
if ( F_134 ( & V_15 -> V_13 . V_111 ) ) {
F_135 ( & V_15 -> V_13 . V_111 ) ;
F_131 ( & V_15 -> V_13 . V_111 . V_188 ) ;
}
}
