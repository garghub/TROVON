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
V_6 -> V_36 &= ( V_44 | V_45 ) ;
F_39 ( V_15 , true ) ;
V_41:
F_40 ( & V_15 -> V_34 , V_33 ) ;
}
static void F_41 ( void * V_28 )
{
F_7 ( V_28 ) ;
}
static int F_42 ( struct V_21 * V_46 , const struct V_47 * V_48 ,
unsigned int * V_49 , unsigned int * V_50 ,
unsigned int V_51 [] , void * V_52 [] )
{
struct V_5 * V_6 = F_43 ( V_46 ) ;
struct V_30 * V_53 ;
int V_54 ;
V_53 = F_44 ( V_6 , V_46 -> type ) ;
if ( F_45 ( V_53 ) )
return F_46 ( V_53 ) ;
if ( ! V_53 -> V_48 )
return - V_55 ;
* V_50 = V_53 -> V_48 -> V_56 ;
for ( V_54 = 0 ; V_54 < V_53 -> V_48 -> V_56 ; V_54 ++ ) {
V_51 [ V_54 ] = ( V_53 -> V_57 * V_53 -> V_58 * V_53 -> V_48 -> V_59 [ V_54 ] ) / 8 ;
V_52 [ V_54 ] = V_6 -> V_12 -> V_60 ;
}
return 0 ;
}
static int F_47 ( struct V_8 * V_29 )
{
struct V_5 * V_6 = F_43 ( V_29 -> V_21 ) ;
struct V_30 * V_61 ;
int V_54 ;
V_61 = F_44 ( V_6 , V_29 -> V_21 -> type ) ;
if ( F_45 ( V_61 ) )
return F_46 ( V_61 ) ;
for ( V_54 = 0 ; V_54 < V_61 -> V_48 -> V_56 ; V_54 ++ )
F_48 ( V_29 , V_54 , V_61 -> V_62 [ V_54 ] ) ;
return 0 ;
}
static void F_49 ( struct V_8 * V_29 )
{
struct V_5 * V_6 = F_43 ( V_29 -> V_21 ) ;
F_50 ( L_2 , V_6 , V_6 -> V_36 ) ;
if ( V_6 -> V_11 )
F_51 ( V_6 -> V_11 , V_29 ) ;
}
static void F_52 ( struct V_21 * V_46 )
{
struct V_5 * V_6 = F_43 ( V_46 ) ;
F_53 ( & V_6 -> V_12 -> V_63 ) ;
}
static void F_54 ( struct V_21 * V_46 )
{
struct V_5 * V_6 = F_43 ( V_46 ) ;
F_55 ( & V_6 -> V_12 -> V_63 ) ;
}
static int F_56 ( struct V_64 * V_64 , void * V_65 ,
struct V_66 * V_67 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
strncpy ( V_67 -> V_68 , V_15 -> V_25 -> V_69 , sizeof( V_67 -> V_68 ) - 1 ) ;
strncpy ( V_67 -> V_70 , V_15 -> V_25 -> V_69 , sizeof( V_67 -> V_70 ) - 1 ) ;
V_67 -> V_71 [ 0 ] = 0 ;
V_67 -> V_72 = V_73 | V_74 |
V_75 | V_76 ;
return 0 ;
}
static int F_58 ( struct V_64 * V_64 , void * V_28 ,
struct V_77 * V_53 )
{
struct V_78 * V_48 ;
V_48 = F_59 ( NULL , NULL , F_1 ( V_53 -> type ) ,
V_53 -> V_79 ) ;
if ( ! V_48 )
return - V_55 ;
strncpy ( V_53 -> V_80 , V_48 -> V_69 , sizeof( V_53 -> V_80 ) - 1 ) ;
V_53 -> V_81 = V_48 -> V_82 ;
return 0 ;
}
static int F_60 ( struct V_64 * V_64 , void * V_65 ,
struct V_47 * V_53 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
struct V_30 * V_61 = F_44 ( V_6 , V_53 -> type ) ;
if ( F_45 ( V_61 ) )
return F_46 ( V_61 ) ;
F_61 ( V_61 , V_53 ) ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 , struct V_47 * V_53 )
{
struct V_12 * V_15 = V_6 -> V_12 ;
const struct V_83 * V_42 = V_15 -> V_42 ;
struct V_84 * V_85 = & V_53 -> V_48 . V_86 ;
struct V_78 * V_48 ;
T_1 V_87 , V_88 , V_89 ;
if ( ! F_63 ( V_53 -> type ) )
return - V_55 ;
V_48 = F_59 ( & V_85 -> V_81 , NULL ,
F_1 ( V_53 -> type ) , 0 ) ;
if ( F_17 ( V_48 == NULL , L_3 ) )
return - V_55 ;
if ( V_85 -> V_90 == V_91 )
V_85 -> V_90 = V_92 ;
else if ( V_85 -> V_90 != V_92 )
return - V_55 ;
if ( V_53 -> type == V_2 ) {
V_87 = V_42 -> V_93 -> V_94 ;
V_88 = F_64 ( V_42 -> V_95 ) - 1 ;
} else {
V_87 = V_42 -> V_93 -> V_96 ;
V_88 = F_64 ( V_42 -> V_97 ) - 1 ;
}
if ( F_65 ( V_48 ) ) {
V_88 = 6 ;
V_89 = 5 ;
} else {
if ( V_42 -> V_98 == 1 )
V_89 = F_66 ( V_48 -> V_99 ) ? 0 : 1 ;
else
V_89 = F_64 ( V_42 -> V_98 ) - 1 ;
}
F_67 ( & V_85 -> V_100 , 16 , V_87 , V_88 ,
& V_85 -> V_101 , 8 , V_42 -> V_93 -> V_94 , V_89 , 0 ) ;
F_68 ( V_48 , V_85 -> V_100 , V_85 -> V_101 , & V_53 -> V_48 . V_86 ) ;
return 0 ;
}
static int F_69 ( struct V_64 * V_64 , void * V_65 ,
struct V_47 * V_53 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
return F_62 ( V_6 , V_53 ) ;
}
static void F_70 ( struct V_30 * V_61 , struct V_78 * V_48 ,
struct V_84 * V_102 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_48 -> V_103 ; V_54 ++ ) {
V_61 -> V_104 [ V_54 ] = V_102 -> V_105 [ V_54 ] . V_104 ;
V_61 -> V_62 [ V_54 ] = V_102 -> V_105 [ V_54 ] . V_106 ;
}
V_61 -> V_57 = V_102 -> V_100 ;
V_61 -> V_58 = V_102 -> V_101 ;
V_61 -> V_107 = V_102 -> V_100 ;
V_61 -> V_108 = V_102 -> V_101 ;
V_61 -> V_100 = V_102 -> V_100 ;
V_61 -> V_101 = V_102 -> V_101 ;
V_61 -> V_109 = 0 ;
V_61 -> V_110 = 0 ;
V_61 -> V_48 = V_48 ;
}
static int F_71 ( struct V_64 * V_64 , void * V_65 ,
struct V_47 * V_53 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_78 * V_48 ;
struct V_21 * V_46 ;
struct V_30 * V_61 ;
int V_16 ;
V_16 = F_62 ( V_6 , V_53 ) ;
if ( V_16 )
return V_16 ;
V_46 = F_72 ( V_6 -> V_11 , V_53 -> type ) ;
if ( F_73 ( V_46 ) ) {
F_74 ( & V_15 -> V_13 . V_111 , L_4 , V_53 -> type ) ;
return - V_112 ;
}
if ( V_53 -> type == V_2 )
V_61 = & V_6 -> V_37 ;
else
V_61 = & V_6 -> V_38 ;
V_48 = F_59 ( & V_53 -> V_48 . V_86 . V_81 , NULL ,
F_1 ( V_53 -> type ) , 0 ) ;
if ( ! V_48 )
return - V_55 ;
F_70 ( V_61 , V_48 , & V_53 -> V_48 . V_86 ) ;
F_75 ( V_6 ) ;
return 0 ;
}
static int F_76 ( struct V_64 * V_64 , void * V_65 ,
struct V_113 * V_114 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
return F_77 ( V_64 , V_6 -> V_11 , V_114 ) ;
}
static int F_78 ( struct V_64 * V_64 , void * V_65 ,
struct V_115 * V_116 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
return F_79 ( V_64 , V_6 -> V_11 , V_116 ) ;
}
static int F_80 ( struct V_64 * V_64 , void * V_65 ,
struct V_115 * V_116 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
return F_81 ( V_64 , V_6 -> V_11 , V_116 ) ;
}
static int F_82 ( struct V_64 * V_64 , void * V_65 ,
struct V_115 * V_116 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
return F_83 ( V_64 , V_6 -> V_11 , V_116 ) ;
}
static int F_84 ( struct V_64 * V_64 , void * V_65 ,
struct V_117 * V_118 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
return F_85 ( V_64 , V_6 -> V_11 , V_118 ) ;
}
static int F_86 ( struct V_64 * V_64 , void * V_65 ,
enum V_119 type )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
return F_87 ( V_64 , V_6 -> V_11 , type ) ;
}
static int F_88 ( struct V_64 * V_64 , void * V_65 ,
enum V_119 type )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
return F_89 ( V_64 , V_6 -> V_11 , type ) ;
}
static int F_90 ( struct V_64 * V_64 , void * V_65 ,
struct V_120 * V_121 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
struct V_30 * V_61 ;
V_61 = F_44 ( V_6 , V_121 -> type ) ;
if ( F_45 ( V_61 ) )
return F_46 ( V_61 ) ;
V_121 -> V_122 . V_123 = 0 ;
V_121 -> V_122 . V_124 = 0 ;
V_121 -> V_122 . V_100 = V_61 -> V_107 ;
V_121 -> V_122 . V_101 = V_61 -> V_108 ;
V_121 -> V_125 = V_121 -> V_122 ;
return 0 ;
}
static int F_91 ( struct V_64 * V_64 , void * V_65 , struct V_126 * V_121 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
struct V_30 * V_61 ;
V_61 = F_44 ( V_6 , V_121 -> type ) ;
if ( F_45 ( V_61 ) )
return F_46 ( V_61 ) ;
V_121 -> V_127 . V_123 = V_61 -> V_109 ;
V_121 -> V_127 . V_124 = V_61 -> V_110 ;
V_121 -> V_127 . V_100 = V_61 -> V_100 ;
V_121 -> V_127 . V_101 = V_61 -> V_101 ;
return 0 ;
}
static int F_92 ( struct V_5 * V_6 , struct V_126 * V_121 )
{
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_30 * V_53 ;
T_1 V_128 , V_129 , V_59 = 0 ;
int V_54 ;
if ( V_121 -> V_127 . V_124 < 0 || V_121 -> V_127 . V_123 < 0 ) {
F_74 ( & V_15 -> V_13 . V_111 ,
L_5 ) ;
return - V_55 ;
}
if ( V_121 -> type == V_130 )
V_53 = & V_6 -> V_38 ;
else if ( V_121 -> type == V_2 )
V_53 = & V_6 -> V_37 ;
else
return - V_55 ;
V_128 = ( V_53 == & V_6 -> V_37 ) ?
V_15 -> V_42 -> V_95 : V_15 -> V_42 -> V_97 ;
if ( V_15 -> V_42 -> V_98 == 1 )
V_129 = F_66 ( V_53 -> V_48 -> V_99 ) ? 0 : 1 ;
else
V_129 = F_64 ( V_15 -> V_42 -> V_98 ) - 1 ;
for ( V_54 = 0 ; V_54 < V_53 -> V_48 -> V_103 ; V_54 ++ )
V_59 += V_53 -> V_48 -> V_59 [ V_54 ] ;
F_67 ( & V_121 -> V_127 . V_100 , V_128 , V_53 -> V_107 ,
F_64 ( V_128 ) - 1 ,
& V_121 -> V_127 . V_101 , V_128 , V_53 -> V_108 ,
V_129 , 64 / ( F_93 ( V_59 , 8 ) ) ) ;
if ( V_121 -> V_127 . V_123 + V_121 -> V_127 . V_100 > V_53 -> V_107 )
V_121 -> V_127 . V_123 = V_53 -> V_107 - V_121 -> V_127 . V_100 ;
if ( V_121 -> V_127 . V_124 + V_121 -> V_127 . V_101 > V_53 -> V_108 )
V_121 -> V_127 . V_124 = V_53 -> V_108 - V_121 -> V_127 . V_101 ;
V_121 -> V_127 . V_123 = F_94 ( V_121 -> V_127 . V_123 , V_128 ) ;
V_121 -> V_127 . V_124 = F_94 ( V_121 -> V_127 . V_124 , V_15 -> V_42 -> V_131 ) ;
F_50 ( L_6 ,
V_121 -> V_127 . V_123 , V_121 -> V_127 . V_124 , V_121 -> V_127 . V_100 , V_121 -> V_127 . V_101 ,
V_53 -> V_57 , V_53 -> V_58 ) ;
return 0 ;
}
static int F_95 ( struct V_64 * V_64 , void * V_65 , const struct V_126 * V_132 )
{
struct V_5 * V_6 = F_57 ( V_65 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
struct V_126 V_121 = * V_132 ;
struct V_30 * V_53 ;
int V_16 ;
V_16 = F_92 ( V_6 , & V_121 ) ;
if ( V_16 )
return V_16 ;
V_53 = ( V_121 . type == V_2 ) ?
& V_6 -> V_37 : & V_6 -> V_38 ;
if ( V_121 . type == V_2 ) {
V_16 = F_96 ( V_6 , V_121 . V_127 . V_100 ,
V_121 . V_127 . V_101 , V_6 -> V_38 . V_100 ,
V_6 -> V_38 . V_101 , V_6 -> V_133 ) ;
} else {
V_16 = F_96 ( V_6 , V_6 -> V_37 . V_100 ,
V_6 -> V_37 . V_101 , V_121 . V_127 . V_100 ,
V_121 . V_127 . V_101 , V_6 -> V_133 ) ;
}
if ( V_16 ) {
F_74 ( & V_15 -> V_13 . V_111 , L_7 ) ;
return - V_55 ;
}
V_53 -> V_109 = V_121 . V_127 . V_123 ;
V_53 -> V_110 = V_121 . V_127 . V_124 ;
V_53 -> V_100 = V_121 . V_127 . V_100 ;
V_53 -> V_101 = V_121 . V_127 . V_101 ;
F_9 ( V_39 , V_6 ) ;
return 0 ;
}
static int F_97 ( void * V_28 , struct V_21 * V_134 ,
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
V_16 = F_98 ( V_134 ) ;
if ( V_16 )
return V_16 ;
V_135 -> type = V_130 ;
V_135 -> V_136 = V_137 | V_138 | V_139 ;
V_135 -> V_24 = V_6 ;
V_135 -> V_140 = & V_141 ;
V_135 -> V_142 = & V_143 ;
V_135 -> V_144 = sizeof( struct V_145 ) ;
return F_98 ( V_135 ) ;
}
static int F_99 ( struct V_5 * V_6 )
{
struct V_84 V_102 = {
. V_81 = V_146 ,
. V_100 = 800 ,
. V_101 = 600 ,
. V_105 [ 0 ] = {
. V_104 = 800 * 4 ,
. V_106 = 800 * 4 * 600 ,
} ,
} ;
struct V_78 * V_48 ;
V_48 = F_59 ( & V_102 . V_81 , NULL , V_147 , 0 ) ;
if ( ! V_48 )
return - V_55 ;
F_70 ( & V_6 -> V_37 , V_48 , & V_102 ) ;
F_70 ( & V_6 -> V_38 , V_48 , & V_102 ) ;
return 0 ;
}
static int F_100 ( struct V_64 * V_64 )
{
struct V_12 * V_15 = F_101 ( V_64 ) ;
struct V_5 * V_6 ;
int V_16 = - V_112 ;
F_50 ( L_8 ,
F_102 ( V_148 ) , V_15 -> V_36 , V_15 -> V_149 . V_150 ) ;
if ( F_103 ( & V_15 -> V_63 ) )
return - V_151 ;
if ( V_15 -> V_149 . V_150 > 0 )
goto V_152;
V_6 = F_104 ( sizeof( * V_6 ) , V_153 ) ;
if ( ! V_6 ) {
V_16 = - V_154 ;
goto V_152;
}
F_105 ( & V_6 -> V_65 , & V_15 -> V_13 . V_111 ) ;
V_6 -> V_12 = V_15 ;
V_6 -> V_37 . V_48 = F_106 ( 0 ) ;
V_6 -> V_38 . V_48 = F_106 ( 0 ) ;
V_16 = F_107 ( V_6 ) ;
if ( V_16 )
goto V_155;
V_6 -> V_65 . V_156 = & V_6 -> V_157 . V_158 ;
V_64 -> V_159 = & V_6 -> V_65 ;
F_108 ( & V_6 -> V_65 ) ;
V_6 -> V_36 = V_44 ;
V_6 -> V_33 = 0 ;
V_6 -> V_160 = V_161 ;
V_6 -> V_162 = V_161 ;
V_6 -> V_163 . V_164 = 1 ;
V_6 -> V_11 = F_109 ( V_15 -> V_13 . V_14 , V_6 , F_97 ) ;
if ( F_45 ( V_6 -> V_11 ) ) {
V_16 = F_46 ( V_6 -> V_11 ) ;
goto V_165;
}
if ( V_15 -> V_13 . V_150 ++ == 0 )
F_19 ( V_166 , & V_15 -> V_36 ) ;
V_16 = F_99 ( V_6 ) ;
if ( V_16 < 0 )
goto V_167;
F_55 ( & V_15 -> V_63 ) ;
return 0 ;
V_167:
F_110 ( V_6 -> V_11 ) ;
V_165:
F_111 ( V_6 ) ;
V_155:
F_112 ( & V_6 -> V_65 ) ;
F_113 ( & V_6 -> V_65 ) ;
F_114 ( V_6 ) ;
V_152:
F_55 ( & V_15 -> V_63 ) ;
return V_16 ;
}
static int F_115 ( struct V_64 * V_64 )
{
struct V_5 * V_6 = F_57 ( V_64 -> V_159 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
F_50 ( L_9 ,
F_102 ( V_148 ) , V_15 -> V_36 , V_15 -> V_13 . V_150 ) ;
F_53 ( & V_15 -> V_63 ) ;
F_110 ( V_6 -> V_11 ) ;
F_111 ( V_6 ) ;
F_112 ( & V_6 -> V_65 ) ;
F_113 ( & V_6 -> V_65 ) ;
if ( -- V_15 -> V_13 . V_150 <= 0 )
F_116 ( V_166 , & V_15 -> V_36 ) ;
F_114 ( V_6 ) ;
F_55 ( & V_15 -> V_63 ) ;
return 0 ;
}
static unsigned int F_117 ( struct V_64 * V_64 ,
struct V_168 * V_169 )
{
struct V_5 * V_6 = F_57 ( V_64 -> V_159 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
int V_16 ;
if ( F_103 ( & V_15 -> V_63 ) )
return - V_151 ;
V_16 = F_118 ( V_64 , V_6 -> V_11 , V_169 ) ;
F_55 ( & V_15 -> V_63 ) ;
return V_16 ;
}
static int F_119 ( struct V_64 * V_64 , struct V_170 * V_171 )
{
struct V_5 * V_6 = F_57 ( V_64 -> V_159 ) ;
struct V_12 * V_15 = V_6 -> V_12 ;
int V_16 ;
if ( F_103 ( & V_15 -> V_63 ) )
return - V_151 ;
V_16 = F_120 ( V_64 , V_6 -> V_11 , V_171 ) ;
F_55 ( & V_15 -> V_63 ) ;
return V_16 ;
}
int F_121 ( struct V_12 * V_15 ,
struct V_172 * V_173 )
{
struct V_174 * V_111 = & V_15 -> V_13 . V_111 ;
int V_16 ;
V_15 -> V_173 = V_173 ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
V_111 -> V_175 = & V_176 ;
V_111 -> V_177 = & V_178 ;
V_111 -> V_173 = V_173 ;
V_111 -> V_179 = - 1 ;
V_111 -> V_180 = V_181 ;
V_111 -> V_63 = & V_15 -> V_63 ;
V_111 -> V_182 = V_183 ;
snprintf ( V_111 -> V_69 , sizeof( V_111 -> V_69 ) , L_10 , V_15 -> V_184 ) ;
F_122 ( V_111 , V_15 ) ;
V_15 -> V_13 . V_14 = F_123 ( & V_185 ) ;
if ( F_45 ( V_15 -> V_13 . V_14 ) ) {
F_74 ( V_173 , L_11 ) ;
return F_46 ( V_15 -> V_13 . V_14 ) ;
}
V_16 = F_124 ( & V_111 -> V_186 , 0 , NULL , 0 ) ;
if ( V_16 )
goto V_187;
V_16 = F_125 ( V_111 , V_188 , - 1 ) ;
if ( V_16 )
goto V_189;
F_126 ( V_173 , L_12 ,
V_111 -> V_69 , F_127 ( V_111 ) ) ;
return 0 ;
V_189:
F_128 ( & V_111 -> V_186 ) ;
V_187:
F_129 ( V_15 -> V_13 . V_14 ) ;
return V_16 ;
}
void F_130 ( struct V_12 * V_15 )
{
if ( ! V_15 )
return;
if ( V_15 -> V_13 . V_14 )
F_129 ( V_15 -> V_13 . V_14 ) ;
if ( F_131 ( & V_15 -> V_13 . V_111 ) ) {
F_132 ( & V_15 -> V_13 . V_111 ) ;
F_128 ( & V_15 -> V_13 . V_111 . V_186 ) ;
}
}
