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
struct V_8 * V_29 = NULL ;
struct V_5 * V_6 = V_28 ;
struct V_30 * V_31 , * V_32 ;
struct V_12 * V_15 ;
unsigned long V_33 ;
int V_16 ;
if ( F_17 ( ! V_6 , L_1 ) )
return;
V_15 = V_6 -> V_12 ;
F_18 ( & V_15 -> V_34 , V_33 ) ;
F_19 ( V_35 , & V_15 -> V_36 ) ;
V_31 = & V_6 -> V_37 ;
V_32 = & V_6 -> V_38 ;
if ( V_6 -> V_36 & V_39 ) {
F_20 ( V_6 , V_31 ) ;
F_20 ( V_6 , V_32 ) ;
}
V_29 = F_21 ( V_6 -> V_11 ) ;
V_16 = F_22 ( V_6 , V_29 , V_31 , & V_31 -> V_40 ) ;
if ( V_16 )
goto V_41;
V_29 = F_23 ( V_6 -> V_11 ) ;
V_16 = F_22 ( V_6 , V_29 , V_32 , & V_32 -> V_40 ) ;
if ( V_16 )
goto V_41;
if ( V_15 -> V_13 . V_6 != V_6 ) {
V_6 -> V_36 |= V_39 ;
V_15 -> V_13 . V_6 = V_6 ;
}
if ( V_6 -> V_36 & V_39 ) {
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
V_16 = F_27 ( V_6 ) ;
if ( V_16 )
goto V_41;
F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
if ( V_15 -> V_42 -> V_43 )
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
}
F_36 ( V_15 , & V_31 -> V_40 ) ;
F_37 ( V_15 , & V_32 -> V_40 , - 1 ) ;
F_38 ( V_6 ) ;
V_6 -> V_36 &= ( V_44 | V_45 |
V_46 | V_47 ) ;
F_39 ( V_15 , true ) ;
V_41:
F_40 ( & V_15 -> V_34 , V_33 ) ;
}
static void F_41 ( void * V_28 )
{
F_7 ( V_28 ) ;
}
static int F_42 ( struct V_21 * V_48 , const struct V_49 * V_50 ,
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
V_54 [ V_56 ] = V_6 -> V_12 -> V_62 ;
}
return 0 ;
}
static int F_47 ( struct V_8 * V_29 )
{
struct V_5 * V_6 = F_43 ( V_29 -> V_21 ) ;
struct V_30 * V_63 ;
int V_56 ;
V_63 = F_44 ( V_6 , V_29 -> V_21 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
for ( V_56 = 0 ; V_56 < V_63 -> V_50 -> V_58 ; V_56 ++ )
F_48 ( V_29 , V_56 , V_63 -> V_64 [ V_56 ] ) ;
return 0 ;
}
static void F_49 ( struct V_8 * V_29 )
{
struct V_5 * V_6 = F_43 ( V_29 -> V_21 ) ;
F_50 ( L_2 , V_6 , V_6 -> V_36 ) ;
if ( V_6 -> V_11 )
F_51 ( V_6 -> V_11 , V_29 ) ;
}
static void F_52 ( struct V_21 * V_48 )
{
struct V_5 * V_6 = F_43 ( V_48 ) ;
F_53 ( & V_6 -> V_12 -> V_65 ) ;
}
static void F_54 ( struct V_21 * V_48 )
{
struct V_5 * V_6 = F_43 ( V_48 ) ;
F_55 ( & V_6 -> V_12 -> V_65 ) ;
}
static int F_56 ( struct V_66 * V_66 , void * V_67 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
strncpy ( V_69 -> V_70 , V_15 -> V_25 -> V_71 , sizeof( V_69 -> V_70 ) - 1 ) ;
strncpy ( V_69 -> V_72 , V_15 -> V_25 -> V_71 , sizeof( V_69 -> V_72 ) - 1 ) ;
V_69 -> V_73 [ 0 ] = 0 ;
V_69 -> V_74 = V_75 | V_76 |
V_77 | V_78 ;
return 0 ;
}
static int F_58 ( struct V_66 * V_66 , void * V_28 ,
struct V_79 * V_55 )
{
struct V_80 * V_50 ;
V_50 = F_59 ( NULL , NULL , F_1 ( V_55 -> type ) ,
V_55 -> V_81 ) ;
if ( ! V_50 )
return - V_57 ;
strncpy ( V_55 -> V_82 , V_50 -> V_71 , sizeof( V_55 -> V_82 ) - 1 ) ;
V_55 -> V_83 = V_50 -> V_84 ;
return 0 ;
}
static int F_60 ( struct V_66 * V_66 , void * V_67 ,
struct V_49 * V_55 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
struct V_30 * V_63 = F_44 ( V_6 , V_55 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
return F_61 ( V_63 , V_55 ) ;
}
static int F_62 ( struct V_5 * V_6 , struct V_49 * V_55 )
{
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_85 * V_42 = V_15 -> V_42 ;
struct V_86 * V_87 = & V_55 -> V_50 . V_88 ;
struct V_80 * V_50 ;
T_1 V_89 , V_90 , V_91 ;
if ( ! F_63 ( V_55 -> type ) )
return - V_57 ;
F_50 ( L_3 , V_87 -> V_92 , V_87 -> V_93 ) ;
V_50 = F_59 ( & V_87 -> V_83 , NULL ,
F_1 ( V_55 -> type ) , 0 ) ;
if ( F_17 ( V_50 == NULL , L_4 ) )
return - V_57 ;
if ( V_87 -> V_94 == V_95 )
V_87 -> V_94 = V_96 ;
else if ( V_87 -> V_94 != V_96 )
return - V_57 ;
if ( V_55 -> type == V_2 ) {
V_89 = V_42 -> V_97 -> V_98 ;
V_90 = F_64 ( V_42 -> V_99 ) - 1 ;
} else {
V_89 = V_42 -> V_97 -> V_100 ;
V_90 = F_64 ( V_42 -> V_101 ) - 1 ;
}
if ( F_65 ( V_50 ) ) {
V_90 = 6 ;
V_91 = 5 ;
} else {
if ( V_42 -> V_102 == 1 )
V_91 = F_66 ( V_50 -> V_103 ) ? 0 : 1 ;
else
V_91 = F_64 ( V_42 -> V_102 ) - 1 ;
}
F_67 ( & V_87 -> V_92 , 16 , V_89 , V_90 ,
& V_87 -> V_93 , 8 , V_42 -> V_97 -> V_98 , V_91 , 0 ) ;
F_68 ( V_50 , V_87 -> V_92 , V_87 -> V_93 , & V_55 -> V_50 . V_88 ) ;
return 0 ;
}
static int F_69 ( struct V_66 * V_66 , void * V_67 ,
struct V_49 * V_55 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
return F_62 ( V_6 , V_55 ) ;
}
static int F_70 ( struct V_66 * V_66 , void * V_67 ,
struct V_49 * V_55 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_21 * V_48 ;
struct V_30 * V_63 ;
struct V_86 * V_87 ;
int V_56 , V_16 = 0 ;
V_16 = F_62 ( V_6 , V_55 ) ;
if ( V_16 )
return V_16 ;
V_48 = F_71 ( V_6 -> V_11 , V_55 -> type ) ;
if ( F_72 ( V_48 ) ) {
F_73 ( & V_15 -> V_13 . V_104 , L_5 , V_55 -> type ) ;
return - V_105 ;
}
if ( V_55 -> type == V_2 )
V_63 = & V_6 -> V_37 ;
else
V_63 = & V_6 -> V_38 ;
V_87 = & V_55 -> V_50 . V_88 ;
V_63 -> V_50 = F_59 ( & V_87 -> V_83 , NULL ,
F_1 ( V_55 -> type ) , 0 ) ;
if ( ! V_63 -> V_50 )
return - V_57 ;
F_74 ( V_6 ) ;
for ( V_56 = 0 ; V_56 < V_63 -> V_50 -> V_106 ; V_56 ++ ) {
V_63 -> V_64 [ V_56 ] =
( V_87 -> V_92 * V_87 -> V_93 * V_63 -> V_50 -> V_61 [ V_56 ] ) / 8 ;
}
F_75 ( V_63 , V_55 ) ;
V_6 -> V_107 . V_108 = 1 ;
if ( V_55 -> type == V_109 )
F_9 ( V_39 | V_47 , V_6 ) ;
else
F_9 ( V_39 | V_46 , V_6 ) ;
F_50 ( L_6 , V_63 -> V_59 , V_63 -> V_60 ) ;
return 0 ;
}
static int F_76 ( struct V_66 * V_66 , void * V_67 ,
struct V_110 * V_111 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
return F_77 ( V_66 , V_6 -> V_11 , V_111 ) ;
}
static int F_78 ( struct V_66 * V_66 , void * V_67 ,
struct V_112 * V_113 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
return F_79 ( V_66 , V_6 -> V_11 , V_113 ) ;
}
static int F_80 ( struct V_66 * V_66 , void * V_67 ,
struct V_112 * V_113 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
return F_81 ( V_66 , V_6 -> V_11 , V_113 ) ;
}
static int F_82 ( struct V_66 * V_66 , void * V_67 ,
struct V_112 * V_113 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
return F_83 ( V_66 , V_6 -> V_11 , V_113 ) ;
}
static int F_84 ( struct V_66 * V_66 , void * V_67 ,
struct V_114 * V_115 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
return F_85 ( V_66 , V_6 -> V_11 , V_115 ) ;
}
static int F_86 ( struct V_66 * V_66 , void * V_67 ,
enum V_116 type )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
if ( F_87 ( type ) ) {
if ( ! F_11 ( V_46 , V_6 ) )
return - V_57 ;
} else if ( ! F_11 ( V_47 , V_6 ) ) {
return - V_57 ;
}
return F_88 ( V_66 , V_6 -> V_11 , type ) ;
}
static int F_89 ( struct V_66 * V_66 , void * V_67 ,
enum V_116 type )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
return F_90 ( V_66 , V_6 -> V_11 , type ) ;
}
static int F_91 ( struct V_66 * V_66 , void * V_67 ,
struct V_117 * V_118 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
struct V_30 * V_63 ;
V_63 = F_44 ( V_6 , V_118 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
V_118 -> V_119 . V_120 = 0 ;
V_118 -> V_119 . V_121 = 0 ;
V_118 -> V_119 . V_92 = V_63 -> V_122 ;
V_118 -> V_119 . V_93 = V_63 -> V_123 ;
V_118 -> V_124 = V_118 -> V_119 ;
return 0 ;
}
static int F_92 ( struct V_66 * V_66 , void * V_67 , struct V_125 * V_118 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
struct V_30 * V_63 ;
V_63 = F_44 ( V_6 , V_118 -> type ) ;
if ( F_45 ( V_63 ) )
return F_46 ( V_63 ) ;
V_118 -> V_126 . V_120 = V_63 -> V_127 ;
V_118 -> V_126 . V_121 = V_63 -> V_128 ;
V_118 -> V_126 . V_92 = V_63 -> V_92 ;
V_118 -> V_126 . V_93 = V_63 -> V_93 ;
return 0 ;
}
static int F_93 ( struct V_5 * V_6 , struct V_125 * V_118 )
{
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_30 * V_55 ;
T_1 V_129 , V_130 , V_61 = 0 ;
int V_56 ;
if ( V_118 -> V_126 . V_121 < 0 || V_118 -> V_126 . V_120 < 0 ) {
F_73 ( & V_15 -> V_13 . V_104 ,
L_7 ) ;
return - V_57 ;
}
if ( V_118 -> type == V_109 )
V_55 = & V_6 -> V_38 ;
else if ( V_118 -> type == V_2 )
V_55 = & V_6 -> V_37 ;
else
return - V_57 ;
V_129 = ( V_55 == & V_6 -> V_37 ) ?
V_15 -> V_42 -> V_99 : V_15 -> V_42 -> V_101 ;
if ( V_15 -> V_42 -> V_102 == 1 )
V_130 = F_66 ( V_55 -> V_50 -> V_103 ) ? 0 : 1 ;
else
V_130 = F_64 ( V_15 -> V_42 -> V_102 ) - 1 ;
for ( V_56 = 0 ; V_56 < V_55 -> V_50 -> V_106 ; V_56 ++ )
V_61 += V_55 -> V_50 -> V_61 [ V_56 ] ;
F_67 ( & V_118 -> V_126 . V_92 , V_129 , V_55 -> V_122 ,
F_64 ( V_129 ) - 1 ,
& V_118 -> V_126 . V_93 , V_129 , V_55 -> V_123 ,
V_130 , 64 / ( F_94 ( V_61 , 8 ) ) ) ;
if ( V_118 -> V_126 . V_120 + V_118 -> V_126 . V_92 > V_55 -> V_122 )
V_118 -> V_126 . V_120 = V_55 -> V_122 - V_118 -> V_126 . V_92 ;
if ( V_118 -> V_126 . V_121 + V_118 -> V_126 . V_93 > V_55 -> V_123 )
V_118 -> V_126 . V_121 = V_55 -> V_123 - V_118 -> V_126 . V_93 ;
V_118 -> V_126 . V_120 = F_95 ( V_118 -> V_126 . V_120 , V_129 ) ;
V_118 -> V_126 . V_121 = F_95 ( V_118 -> V_126 . V_121 , V_15 -> V_42 -> V_131 ) ;
F_50 ( L_8 ,
V_118 -> V_126 . V_120 , V_118 -> V_126 . V_121 , V_118 -> V_126 . V_92 , V_118 -> V_126 . V_93 ,
V_55 -> V_59 , V_55 -> V_60 ) ;
return 0 ;
}
static int F_96 ( struct V_66 * V_66 , void * V_67 , const struct V_125 * V_132 )
{
struct V_5 * V_6 = F_57 ( V_67 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_125 V_118 = * V_132 ;
struct V_30 * V_55 ;
int V_16 ;
V_16 = F_93 ( V_6 , & V_118 ) ;
if ( V_16 )
return V_16 ;
V_55 = ( V_118 . type == V_2 ) ?
& V_6 -> V_37 : & V_6 -> V_38 ;
if ( F_11 ( V_47 | V_46 , V_6 ) ) {
if ( V_118 . type == V_2 ) {
V_16 = F_97 ( V_6 , V_118 . V_126 . V_92 ,
V_118 . V_126 . V_93 , V_6 -> V_38 . V_92 ,
V_6 -> V_38 . V_93 , V_6 -> V_133 ) ;
} else {
V_16 = F_97 ( V_6 , V_6 -> V_37 . V_92 ,
V_6 -> V_37 . V_93 , V_118 . V_126 . V_92 ,
V_118 . V_126 . V_93 , V_6 -> V_133 ) ;
}
if ( V_16 ) {
F_73 ( & V_15 -> V_13 . V_104 , L_9 ) ;
return - V_57 ;
}
}
V_55 -> V_127 = V_118 . V_126 . V_120 ;
V_55 -> V_128 = V_118 . V_126 . V_121 ;
V_55 -> V_92 = V_118 . V_126 . V_92 ;
V_55 -> V_93 = V_118 . V_126 . V_93 ;
F_9 ( V_39 , V_6 ) ;
return 0 ;
}
static int F_98 ( void * V_28 , struct V_21 * V_134 ,
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
V_16 = F_99 ( V_134 ) ;
if ( V_16 )
return V_16 ;
V_135 -> type = V_109 ;
V_135 -> V_136 = V_137 | V_138 | V_139 ;
V_135 -> V_24 = V_6 ;
V_135 -> V_140 = & V_141 ;
V_135 -> V_142 = & V_143 ;
V_135 -> V_144 = sizeof( struct V_145 ) ;
return F_99 ( V_135 ) ;
}
static int F_100 ( struct V_66 * V_66 )
{
struct V_12 * V_15 = F_101 ( V_66 ) ;
struct V_5 * V_6 ;
int V_16 = - V_105 ;
F_50 ( L_10 ,
F_102 ( V_146 ) , V_15 -> V_36 , V_15 -> V_147 . V_148 ) ;
if ( F_103 ( & V_15 -> V_65 ) )
return - V_149 ;
if ( V_15 -> V_147 . V_148 > 0 )
goto V_150;
V_6 = F_104 ( sizeof( * V_6 ) , V_151 ) ;
if ( ! V_6 ) {
V_16 = - V_152 ;
goto V_150;
}
F_105 ( & V_6 -> V_67 , & V_15 -> V_13 . V_104 ) ;
V_6 -> V_12 = V_15 ;
V_6 -> V_37 . V_50 = F_106 ( 0 ) ;
V_6 -> V_38 . V_50 = F_106 ( 0 ) ;
V_16 = F_107 ( V_6 ) ;
if ( V_16 )
goto V_153;
V_6 -> V_67 . V_154 = & V_6 -> V_155 . V_156 ;
V_66 -> V_157 = & V_6 -> V_67 ;
F_108 ( & V_6 -> V_67 ) ;
V_6 -> V_36 = V_44 ;
V_6 -> V_33 = 0 ;
V_6 -> V_158 = V_159 ;
V_6 -> V_160 = V_159 ;
V_6 -> V_11 = F_109 ( V_15 -> V_13 . V_14 , V_6 , F_98 ) ;
if ( F_45 ( V_6 -> V_11 ) ) {
V_16 = F_46 ( V_6 -> V_11 ) ;
goto V_161;
}
if ( V_15 -> V_13 . V_148 ++ == 0 )
F_19 ( V_162 , & V_15 -> V_36 ) ;
F_55 ( & V_15 -> V_65 ) ;
return 0 ;
V_161:
F_110 ( V_6 ) ;
V_153:
F_111 ( & V_6 -> V_67 ) ;
F_112 ( & V_6 -> V_67 ) ;
F_113 ( V_6 ) ;
V_150:
F_55 ( & V_15 -> V_65 ) ;
return V_16 ;
}
static int F_114 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_57 ( V_66 -> V_157 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
F_50 ( L_11 ,
F_102 ( V_146 ) , V_15 -> V_36 , V_15 -> V_13 . V_148 ) ;
F_53 ( & V_15 -> V_65 ) ;
F_115 ( V_6 -> V_11 ) ;
F_110 ( V_6 ) ;
F_111 ( & V_6 -> V_67 ) ;
F_112 ( & V_6 -> V_67 ) ;
if ( -- V_15 -> V_13 . V_148 <= 0 )
F_116 ( V_162 , & V_15 -> V_36 ) ;
F_113 ( V_6 ) ;
F_55 ( & V_15 -> V_65 ) ;
return 0 ;
}
static unsigned int F_117 ( struct V_66 * V_66 ,
struct V_163 * V_164 )
{
struct V_5 * V_6 = F_57 ( V_66 -> V_157 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
int V_16 ;
if ( F_103 ( & V_15 -> V_65 ) )
return - V_149 ;
V_16 = F_118 ( V_66 , V_6 -> V_11 , V_164 ) ;
F_55 ( & V_15 -> V_65 ) ;
return V_16 ;
}
static int F_119 ( struct V_66 * V_66 , struct V_165 * V_166 )
{
struct V_5 * V_6 = F_57 ( V_66 -> V_157 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
int V_16 ;
if ( F_103 ( & V_15 -> V_65 ) )
return - V_149 ;
V_16 = F_120 ( V_66 , V_6 -> V_11 , V_166 ) ;
F_55 ( & V_15 -> V_65 ) ;
return V_16 ;
}
int F_121 ( struct V_12 * V_15 ,
struct V_167 * V_168 )
{
struct V_169 * V_104 = & V_15 -> V_13 . V_104 ;
int V_16 ;
V_15 -> V_168 = V_168 ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
V_104 -> V_170 = & V_171 ;
V_104 -> V_172 = & V_173 ;
V_104 -> V_168 = V_168 ;
V_104 -> V_174 = - 1 ;
V_104 -> V_175 = V_176 ;
V_104 -> V_65 = & V_15 -> V_65 ;
V_104 -> V_177 = V_178 ;
snprintf ( V_104 -> V_71 , sizeof( V_104 -> V_71 ) , L_12 , V_15 -> V_179 ) ;
F_122 ( V_104 , V_15 ) ;
V_15 -> V_13 . V_14 = F_123 ( & V_180 ) ;
if ( F_45 ( V_15 -> V_13 . V_14 ) ) {
F_73 ( V_168 , L_13 ) ;
return F_46 ( V_15 -> V_13 . V_14 ) ;
}
V_16 = F_124 ( & V_104 -> V_181 , 0 , NULL , 0 ) ;
if ( V_16 )
goto V_182;
V_16 = F_125 ( V_104 , V_183 , - 1 ) ;
if ( V_16 )
goto V_184;
F_126 ( V_168 , L_14 ,
V_104 -> V_71 , F_127 ( V_104 ) ) ;
return 0 ;
V_184:
F_128 ( & V_104 -> V_181 ) ;
V_182:
F_129 ( V_15 -> V_13 . V_14 ) ;
return V_16 ;
}
void F_130 ( struct V_12 * V_15 )
{
if ( ! V_15 )
return;
if ( V_15 -> V_13 . V_14 )
F_129 ( V_15 -> V_13 . V_14 ) ;
if ( F_131 ( & V_15 -> V_13 . V_104 ) ) {
F_132 ( & V_15 -> V_13 . V_104 ) ;
F_128 ( & V_15 -> V_13 . V_104 . V_181 ) ;
}
}
