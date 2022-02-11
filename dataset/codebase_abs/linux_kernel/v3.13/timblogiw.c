static int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 * 2 ;
}
static int F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 * F_1 ( V_2 ) ;
}
static const struct V_1 * F_3 ( const T_1 V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_7 ) ; V_6 ++ )
if ( V_7 [ V_6 ] . V_5 & V_5 )
return V_7 + V_6 ;
return V_7 ;
}
static void F_5 ( void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = & V_10 -> V_14 ;
F_6 ( & V_12 -> V_15 ) ;
V_10 -> V_16 = - 1 ;
V_12 -> V_17 ++ ;
if ( V_14 -> V_18 != V_19 ) {
F_7 ( & V_14 -> V_20 ) ;
F_8 ( & V_14 -> V_21 ) ;
V_14 -> V_22 = V_12 -> V_17 * 2 ;
V_14 -> V_18 = V_23 ;
F_9 ( & V_14 -> V_24 ) ;
}
if ( ! F_10 ( & V_12 -> V_25 ) ) {
V_14 = F_11 ( V_12 -> V_25 . V_26 , struct V_13 ,
V_20 ) ;
V_14 -> V_18 = V_27 ;
}
F_12 ( & V_12 -> V_15 ) ;
}
static bool F_13 ( struct V_28 * V_29 , void * V_30 )
{
return V_29 -> V_31 == ( V_32 ) V_30 ;
}
static int F_14 ( struct V_33 * V_33 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_39 * V_40 = F_16 ( V_38 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_1 , V_42 ) ;
if ( V_36 -> type != V_43 )
return - V_44 ;
F_18 ( & V_40 -> V_45 ) ;
V_36 -> V_46 . V_47 . V_3 = V_12 -> V_48 -> V_3 ;
V_36 -> V_46 . V_47 . V_4 = V_12 -> V_48 -> V_4 ;
V_36 -> V_46 . V_47 . V_49 = V_50 ;
V_36 -> V_46 . V_47 . V_51 = F_1 ( V_12 -> V_48 ) ;
V_36 -> V_46 . V_47 . V_52 = F_2 ( V_12 -> V_48 ) ;
V_36 -> V_46 . V_47 . V_53 = V_54 ;
F_19 ( & V_40 -> V_45 ) ;
return 0 ;
}
static int F_20 ( struct V_33 * V_33 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_55 * V_47 = & V_36 -> V_46 . V_47 ;
F_17 ( & V_38 -> V_41 ,
L_2
L_3 ,
V_42 ,
V_47 -> V_3 , V_47 -> V_4 , V_47 -> V_49 , V_47 -> V_53 ,
V_47 -> V_51 , V_47 -> V_52 , V_47 -> V_56 ) ;
if ( V_36 -> type != V_43 )
return - V_44 ;
if ( V_47 -> V_53 != V_54 )
return - V_44 ;
if ( V_47 -> V_49 != V_50 )
return - V_44 ;
return 0 ;
}
static int F_21 ( struct V_33 * V_33 , void * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_39 * V_40 = F_16 ( V_38 ) ;
struct V_11 * V_12 = V_34 ;
struct V_55 * V_47 = & V_36 -> V_46 . V_47 ;
int V_57 ;
F_18 ( & V_40 -> V_45 ) ;
V_57 = F_20 ( V_33 , V_34 , V_36 ) ;
if ( V_57 )
goto V_58;
if ( F_22 ( & V_12 -> V_59 ) ) {
F_23 ( & V_38 -> V_41 , L_4 , V_42 ) ;
V_57 = - V_60 ;
goto V_58;
}
V_47 -> V_3 = V_12 -> V_48 -> V_3 ;
V_47 -> V_4 = V_12 -> V_48 -> V_4 ;
V_58:
F_19 ( & V_40 -> V_45 ) ;
return V_57 ;
}
static int F_24 ( struct V_33 * V_33 , void * V_34 ,
struct V_61 * V_62 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
F_17 ( & V_38 -> V_41 , L_5 , V_42 ) ;
strncpy ( V_62 -> V_63 , V_64 , sizeof( V_62 -> V_63 ) - 1 ) ;
strncpy ( V_62 -> V_65 , V_66 , sizeof( V_62 -> V_65 ) - 1 ) ;
snprintf ( V_62 -> V_67 , sizeof( V_62 -> V_67 ) , L_6 , V_38 -> V_68 ) ;
V_62 -> V_69 = V_70 | V_71 |
V_72 ;
V_62 -> V_73 = V_62 -> V_69 | V_74 ;
return 0 ;
}
static int F_25 ( struct V_33 * V_33 , void * V_34 ,
struct V_75 * V_46 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
F_17 ( & V_38 -> V_41 , L_7 , V_42 , V_46 -> V_76 ) ;
if ( V_46 -> V_76 != 0 )
return - V_44 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_46 -> V_76 = 0 ;
V_46 -> type = V_43 ;
strncpy ( V_46 -> V_77 , L_8 ,
sizeof( V_46 -> V_77 ) - 1 ) ;
V_46 -> V_49 = V_50 ;
return 0 ;
}
static int F_26 ( struct V_33 * V_33 , void * V_34 ,
struct V_78 * V_79 )
{
struct V_11 * V_12 = V_34 ;
struct V_80 * V_81 = & V_79 -> V_82 . V_25 ;
V_81 -> V_83 = V_84 ;
V_81 -> V_85 . V_86 = 1 ;
V_81 -> V_85 . V_87 = V_12 -> V_48 -> V_88 ;
return 0 ;
}
static int F_27 ( struct V_33 * V_33 , void * V_34 ,
struct V_89 * V_90 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
return F_28 ( & V_12 -> V_59 , V_90 ) ;
}
static int F_29 ( struct V_33 * V_33 , void * V_34 ,
struct V_91 * V_92 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
return F_30 ( & V_12 -> V_59 , V_92 ) ;
}
static int F_31 ( struct V_33 * V_33 , void * V_34 , struct V_91 * V_92 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
return F_32 ( & V_12 -> V_59 , V_92 ) ;
}
static int F_33 ( struct V_33 * V_33 , void * V_34 ,
struct V_91 * V_92 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
return F_34 ( & V_12 -> V_59 , V_92 , V_33 -> V_93 & V_94 ) ;
}
static int F_35 ( struct V_33 * V_33 , void * V_34 , T_1 * V_5 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
* V_5 = V_12 -> V_48 -> V_5 ;
return 0 ;
}
static int F_36 ( struct V_33 * V_33 , void * V_34 , T_1 V_5 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_39 * V_40 = F_16 ( V_38 ) ;
struct V_11 * V_12 = V_34 ;
int V_57 = 0 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
F_18 ( & V_40 -> V_45 ) ;
if ( F_37 ( V_40 ) )
V_57 = F_38 ( V_40 -> V_95 , V_96 , V_97 , V_5 ) ;
if ( ! V_57 )
V_12 -> V_48 = F_3 ( V_5 ) ;
F_19 ( & V_40 -> V_45 ) ;
return V_57 ;
}
static int F_39 ( struct V_33 * V_33 , void * V_34 ,
struct V_98 * V_99 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
int V_6 ;
F_17 ( & V_38 -> V_41 , L_5 , V_42 ) ;
if ( V_99 -> V_76 != 0 )
return - V_44 ;
V_99 -> V_76 = 0 ;
strncpy ( V_99 -> V_68 , L_10 , sizeof( V_99 -> V_68 ) - 1 ) ;
V_99 -> type = V_100 ;
V_99 -> V_5 = 0 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_7 ) ; V_6 ++ )
V_99 -> V_5 |= V_7 [ V_6 ] . V_5 ;
return 0 ;
}
static int F_40 ( struct V_33 * V_33 , void * V_34 ,
unsigned int * V_101 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
F_17 ( & V_38 -> V_41 , L_5 , V_42 ) ;
* V_101 = 0 ;
return 0 ;
}
static int F_41 ( struct V_33 * V_33 , void * V_34 , unsigned int V_101 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
F_17 ( & V_38 -> V_41 , L_5 , V_42 ) ;
if ( V_101 != 0 )
return - V_44 ;
return 0 ;
}
static int F_42 ( struct V_33 * V_33 , void * V_34 , enum V_102 type )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
if ( type != V_43 ) {
F_17 ( & V_38 -> V_41 , L_11 , V_42 ) ;
return - V_44 ;
}
V_12 -> V_17 = 0 ;
return F_43 ( & V_12 -> V_59 ) ;
}
static int F_44 ( struct V_33 * V_33 , void * V_34 ,
enum V_102 type )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_1 , V_42 ) ;
if ( type != V_43 )
return - V_44 ;
return F_45 ( & V_12 -> V_59 ) ;
}
static int F_46 ( struct V_33 * V_33 , void * V_34 , T_1 * V_5 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_39 * V_40 = F_16 ( V_38 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_1 , V_42 ) ;
if ( F_37 ( V_40 ) )
return F_38 ( V_40 -> V_95 , V_103 , V_104 , V_5 ) ;
else {
* V_5 = V_12 -> V_48 -> V_5 ;
return 0 ;
}
}
static int F_47 ( struct V_33 * V_33 , void * V_34 ,
struct V_105 * V_106 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_34 ;
F_17 ( & V_38 -> V_41 , L_12 , V_42 ,
V_106 -> V_76 , V_106 -> V_107 ) ;
if ( ( V_106 -> V_76 != 0 ) ||
( V_106 -> V_107 != V_50 ) )
return - V_44 ;
V_106 -> type = V_108 ;
V_106 -> V_109 . V_3 = V_12 -> V_48 -> V_3 ;
V_106 -> V_109 . V_4 = V_12 -> V_48 -> V_4 ;
return 0 ;
}
static int F_48 ( struct V_110 * V_111 , unsigned int * V_112 ,
unsigned int * V_113 )
{
struct V_11 * V_12 = V_111 -> V_114 ;
* V_113 = F_2 ( V_12 -> V_48 ) ;
if ( ! * V_112 )
* V_112 = 32 ;
while ( * V_113 * * V_112 > V_115 * 1024 * 1024 )
( * V_112 ) -- ;
return 0 ;
}
static int F_49 ( struct V_110 * V_111 , struct V_13 * V_14 ,
enum V_116 V_53 )
{
struct V_11 * V_12 = V_111 -> V_114 ;
struct V_9 * V_10 = F_50 ( V_14 , struct V_9 ,
V_14 ) ;
unsigned int V_117 = F_2 ( V_12 -> V_48 ) ;
int V_57 = 0 ;
if ( V_14 -> V_118 && V_14 -> V_119 < V_117 )
return - V_120 ;
V_14 -> V_113 = V_117 ;
V_14 -> V_3 = V_12 -> V_48 -> V_3 ;
V_14 -> V_4 = V_12 -> V_48 -> V_4 ;
V_14 -> V_53 = V_53 ;
if ( V_14 -> V_18 == V_121 ) {
int V_6 ;
unsigned int V_113 ;
unsigned int V_122 = V_123 *
F_1 ( V_12 -> V_48 ) ;
T_2 V_124 ;
F_51 ( V_10 -> V_125 , F_4 ( V_10 -> V_125 ) ) ;
V_57 = F_52 ( V_111 , V_14 , NULL ) ;
if ( V_57 )
goto V_57;
V_124 = F_53 ( V_14 ) ;
for ( V_6 = 0 , V_113 = 0 ; V_113 < V_117 ; V_6 ++ ) {
F_54 ( V_10 -> V_125 + V_6 ) = V_124 + V_113 ;
V_113 += V_122 ;
F_55 ( V_10 -> V_125 + V_6 ) = ( V_113 > V_117 ) ?
( V_122 - ( V_113 - V_117 ) ) :
V_122 ;
}
V_14 -> V_18 = V_126 ;
V_10 -> V_16 = - 1 ;
V_10 -> V_12 = V_12 ;
}
return 0 ;
V_57:
F_56 ( V_111 , V_14 ) ;
V_14 -> V_18 = V_121 ;
return V_57 ;
}
static void F_57 ( struct V_110 * V_111 , struct V_13 * V_14 )
{
struct V_11 * V_12 = V_111 -> V_114 ;
struct V_9 * V_10 = F_50 ( V_14 , struct V_9 ,
V_14 ) ;
struct V_127 * V_128 ;
int V_129 ;
int V_122 = V_123 *
F_1 ( V_12 -> V_48 ) ;
V_129 = F_2 ( V_12 -> V_48 ) / V_122 ;
V_129 +=
( F_2 ( V_12 -> V_48 ) % V_122 ) ? 1 : 0 ;
if ( F_10 ( & V_12 -> V_25 ) )
V_14 -> V_18 = V_27 ;
else
V_14 -> V_18 = V_130 ;
F_58 ( & V_14 -> V_20 , & V_12 -> V_25 ) ;
F_59 ( & V_12 -> V_15 ) ;
V_128 = F_60 ( V_12 -> V_29 ,
V_10 -> V_125 , V_129 , V_131 ,
V_132 ) ;
if ( ! V_128 ) {
F_61 ( & V_12 -> V_15 ) ;
F_62 ( & V_14 -> V_20 ) ;
V_14 -> V_18 = V_126 ;
return;
}
V_128 -> V_133 = V_10 ;
V_128 -> V_134 = F_5 ;
V_10 -> V_16 = V_128 -> V_135 ( V_128 ) ;
F_61 ( & V_12 -> V_15 ) ;
}
static void F_63 ( struct V_110 * V_111 ,
struct V_13 * V_14 )
{
struct V_11 * V_12 = V_111 -> V_114 ;
struct V_9 * V_10 = F_50 ( V_14 , struct V_9 ,
V_14 ) ;
F_64 ( V_111 , V_14 , 0 , 0 ) ;
if ( V_10 -> V_16 >= 0 )
F_65 ( V_12 -> V_29 , V_10 -> V_16 ) ;
F_56 ( V_111 , V_14 ) ;
V_14 -> V_18 = V_121 ;
}
static int F_66 ( struct V_33 * V_33 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_39 * V_40 = F_16 ( V_38 ) ;
struct V_11 * V_12 ;
T_1 V_5 ;
T_3 V_136 ;
int V_57 = 0 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
F_18 ( & V_40 -> V_45 ) ;
if ( V_40 -> V_137 ) {
V_57 = - V_60 ;
goto V_58;
}
if ( F_37 ( V_40 ) && ! V_40 -> V_95 ) {
struct V_138 * V_139 ;
V_139 = F_67 ( V_40 -> V_140 . V_138 ) ;
if ( ! V_139 ) {
F_23 ( & V_38 -> V_41 , L_13 ,
V_40 -> V_140 . V_138 ) ;
V_57 = - V_141 ;
goto V_58;
}
V_40 -> V_95 = F_68 ( & V_40 -> V_142 , V_139 ,
V_40 -> V_140 . V_143 . V_144 , NULL ) ;
F_69 ( V_139 ) ;
if ( ! V_40 -> V_95 ) {
F_23 ( & V_38 -> V_41 , L_14 ,
V_40 -> V_140 . V_143 . V_145 ) ;
V_57 = - V_141 ;
goto V_58;
}
}
V_12 = F_70 ( sizeof( * V_12 ) , V_146 ) ;
if ( ! V_12 ) {
V_57 = - V_120 ;
goto V_58;
}
V_12 -> V_48 = V_7 ;
F_46 ( V_33 , V_12 , & V_5 ) ;
V_12 -> V_48 = F_3 ( V_5 ) ;
F_71 ( & V_12 -> V_25 ) ;
F_72 ( & V_12 -> V_15 ) ;
F_73 ( V_136 ) ;
F_74 ( V_147 , V_136 ) ;
F_74 ( V_148 , V_136 ) ;
V_12 -> V_29 = F_75 ( V_136 , F_13 ,
( void * ) ( V_32 ) V_40 -> V_140 . V_149 ) ;
if ( ! V_12 -> V_29 ) {
F_23 ( & V_38 -> V_41 , L_15 ) ;
F_76 ( V_12 ) ;
V_57 = - V_141 ;
goto V_58;
}
V_33 -> V_150 = V_12 ;
F_77 ( & V_12 -> V_59 ,
& V_151 , V_40 -> V_41 , & V_12 -> V_15 ,
V_43 , V_54 ,
sizeof( struct V_9 ) , V_12 , NULL ) ;
V_40 -> V_137 = true ;
V_58:
F_19 ( & V_40 -> V_45 ) ;
return V_57 ;
}
static int F_78 ( struct V_33 * V_33 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_39 * V_40 = F_16 ( V_38 ) ;
struct V_11 * V_12 = V_33 -> V_150 ;
F_17 ( & V_38 -> V_41 , L_5 , V_42 ) ;
F_79 ( & V_12 -> V_59 ) ;
F_80 ( & V_12 -> V_59 ) ;
F_81 ( V_12 -> V_29 ) ;
F_76 ( V_12 ) ;
F_18 ( & V_40 -> V_45 ) ;
V_40 -> V_137 = false ;
F_19 ( & V_40 -> V_45 ) ;
return 0 ;
}
static T_4 F_82 ( struct V_33 * V_33 , char T_5 * V_8 ,
T_6 V_112 , T_7 * V_152 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_33 -> V_150 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
return F_83 ( & V_12 -> V_59 , V_8 , V_112 , V_152 , 0 ,
V_33 -> V_93 & V_94 ) ;
}
static unsigned int F_84 ( struct V_33 * V_33 ,
struct V_153 * V_154 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_33 -> V_150 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
return F_85 ( V_33 , & V_12 -> V_59 , V_154 ) ;
}
static int F_86 ( struct V_33 * V_33 , struct V_155 * V_156 )
{
struct V_37 * V_38 = F_15 ( V_33 ) ;
struct V_11 * V_12 = V_33 -> V_150 ;
F_17 ( & V_38 -> V_41 , L_9 , V_42 ) ;
return F_87 ( & V_12 -> V_59 , V_156 ) ;
}
static int F_88 ( struct V_157 * V_158 )
{
int V_57 ;
struct V_39 * V_40 = NULL ;
struct V_159 * V_140 = V_158 -> V_41 . V_160 ;
if ( ! V_140 ) {
F_23 ( & V_158 -> V_41 , L_16 ) ;
V_57 = - V_44 ;
goto V_57;
}
if ( ! V_140 -> V_143 . V_145 )
F_89 ( & V_158 -> V_41 , L_17 ) ;
V_40 = F_70 ( sizeof( * V_40 ) , V_146 ) ;
if ( ! V_40 ) {
V_57 = - V_120 ;
goto V_57;
}
if ( V_158 -> V_41 . V_161 )
V_40 -> V_41 = V_158 -> V_41 . V_161 ;
else
V_40 -> V_41 = & V_158 -> V_41 ;
memcpy ( & V_40 -> V_140 , V_140 , sizeof( V_40 -> V_140 ) ) ;
F_90 ( & V_40 -> V_45 ) ;
V_40 -> V_162 = V_163 ;
F_91 ( V_40 -> V_142 . V_68 , V_66 , sizeof( V_40 -> V_142 . V_68 ) ) ;
V_57 = F_92 ( NULL , & V_40 -> V_142 ) ;
if ( V_57 )
goto V_164;
V_40 -> V_162 . V_142 = & V_40 -> V_142 ;
F_93 ( V_158 , V_40 ) ;
F_94 ( & V_40 -> V_162 , V_40 ) ;
V_57 = F_95 ( & V_40 -> V_162 , V_165 , 0 ) ;
if ( V_57 ) {
F_23 ( & V_158 -> V_41 , L_18 , V_57 ) ;
goto V_166;
}
return 0 ;
V_166:
F_96 ( & V_40 -> V_142 ) ;
V_164:
F_76 ( V_40 ) ;
V_57:
F_23 ( & V_158 -> V_41 , L_19 , V_57 ) ;
return V_57 ;
}
static int F_97 ( struct V_157 * V_158 )
{
struct V_39 * V_40 = F_98 ( V_158 ) ;
F_99 ( & V_40 -> V_162 ) ;
F_96 ( & V_40 -> V_142 ) ;
F_76 ( V_40 ) ;
return 0 ;
}
