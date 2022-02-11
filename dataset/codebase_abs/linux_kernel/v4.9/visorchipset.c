static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned int V_3 = F_2 ( V_1 ) ;
if ( V_3 )
return - V_4 ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return 0 ;
}
static T_1 F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_10 )
{
T_2 V_11 = 0 ;
F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_11 ) , & V_11 , sizeof( T_2 ) ) ;
return F_7 ( V_10 , V_14 , L_1 , V_11 ) ;
}
static T_1 F_8 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_15 )
{
T_2 V_11 ;
int V_16 ;
if ( F_9 ( V_10 , 10 , & V_11 ) )
return - V_17 ;
V_16 = F_10
( V_12 ,
F_6 ( struct V_13 ,
V_11 ) ,
& V_11 , sizeof( T_2 ) ) ;
if ( V_16 )
return V_16 ;
return V_15 ;
}
static T_1 F_11 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_10 )
{
struct V_18 V_18 ;
F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_19 ) , & V_18 ,
sizeof( struct V_18 ) ) ;
return F_7 ( V_10 , V_14 , L_1 ,
V_18 . V_20 ) ;
}
static T_1 F_12 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_15 )
{
int V_21 , V_16 ;
struct V_18 V_18 ;
if ( F_13 ( V_10 , 10 , & V_21 ) )
return - V_17 ;
V_18 . V_20 = V_21 ;
V_16 = F_10
( V_12 ,
F_6 ( struct V_13 ,
V_19 ) , & ( V_18 ) ,
sizeof( struct V_18 ) ) ;
if ( V_16 )
return V_16 ;
return V_15 ;
}
static T_1 F_14 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
T_4 error = 0 ;
F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_22 ) ,
& error , sizeof( T_4 ) ) ;
return F_7 ( V_10 , V_14 , L_2 , error ) ;
}
static T_1 F_15 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_3 V_15 )
{
T_4 error ;
int V_16 ;
if ( F_16 ( V_10 , 10 , & error ) )
return - V_17 ;
V_16 = F_10
( V_12 ,
F_6 ( struct V_13 ,
V_22 ) ,
& error , sizeof( T_4 ) ) ;
if ( V_16 )
return V_16 ;
return V_15 ;
}
static T_1 F_17 ( struct V_6 * V_7 , struct V_8 * V_9 ,
char * V_10 )
{
T_4 V_23 = 0 ;
F_5
( V_12 ,
F_6 ( struct V_13 ,
V_24 ) ,
& V_23 , sizeof( T_4 ) ) ;
return F_7 ( V_10 , V_14 , L_2 , V_23 ) ;
}
static T_1 F_18 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const char * V_10 , T_3 V_15 )
{
T_4 V_23 ;
int V_16 ;
if ( F_16 ( V_10 , 10 , & V_23 ) )
return - V_17 ;
V_16 = F_10
( V_12 ,
F_6 ( struct V_13 ,
V_24 ) ,
& V_23 , sizeof( T_4 ) ) ;
if ( V_16 )
return V_16 ;
return V_15 ;
}
static T_1 F_19 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
T_5 V_25 = 0 ;
F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_26 ) ,
& V_25 , sizeof( T_5 ) ) ;
return F_7 ( V_10 , V_14 , L_3 , V_25 ) ;
}
static T_1 F_20 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_15 )
{
T_5 V_25 ;
int V_16 ;
if ( F_21 ( V_10 , 10 , & V_25 ) )
return - V_17 ;
V_16 = F_10
( V_12 ,
F_6 ( struct V_13 ,
V_26 ) ,
& V_25 , sizeof( T_5 ) ) ;
if ( V_16 )
return V_16 ;
return V_15 ;
}
static T_6
F_22 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = NULL ;
if ( ! V_28 )
return V_31 ;
V_30 = (struct V_29 * ) ( V_28 -> V_32 ) ;
return V_30 -> V_33 ;
}
static void
F_23 ( struct V_27 * V_28 ,
enum V_34 V_35 )
{
struct V_29 * V_30 = NULL ;
if ( ! V_28 )
return;
V_30 = (struct V_29 * ) ( V_28 -> V_32 ) ;
switch ( V_35 ) {
case V_36 :
V_28 -> V_37 = V_28 -> V_32 + V_30 -> V_38 ;
V_28 -> V_39 = V_30 -> V_40 ;
break;
case V_41 :
V_28 -> V_37 = V_28 -> V_32 + V_30 -> V_42 ;
V_28 -> V_39 = V_30 -> V_43 ;
break;
case V_44 :
V_28 -> V_37 = V_28 -> V_32 + V_30 -> V_45 ;
V_28 -> V_39 = V_30 -> V_46 ;
break;
case V_47 :
V_28 -> V_37 = V_28 -> V_32 + V_30 -> V_48 ;
V_28 -> V_39 = V_30 -> V_49 ;
break;
default:
break;
}
}
static void F_24 ( struct V_27 * V_28 )
{
if ( ! V_28 )
return;
V_50 -= V_28 -> V_51 ;
F_25 ( V_28 ) ;
}
static void *
F_26 ( struct V_27 * V_28 )
{
T_2 * V_52 ;
unsigned long V_53 ;
int V_54 = - 1 ;
void * V_55 = NULL ;
int V_56 ;
if ( ! V_28 )
return NULL ;
V_52 = V_28 -> V_37 ;
V_53 = V_28 -> V_39 ;
if ( V_53 == 0 )
return NULL ;
if ( ! V_52 )
return NULL ;
for ( V_56 = 0 , V_54 = - 1 ; V_56 < V_53 ; V_56 ++ )
if ( V_52 [ V_56 ] == '\0' ) {
V_54 = V_56 ;
break;
}
if ( V_54 < 0 )
V_54 = V_53 ;
V_55 = F_27 ( V_54 + 1 , V_57 | V_58 ) ;
if ( ! V_55 )
return NULL ;
if ( V_54 > 0 )
memcpy ( V_55 , V_52 , V_54 ) ;
( ( T_2 * ) ( V_55 ) ) [ V_54 ] = '\0' ;
return V_55 ;
}
static int F_28 ( struct V_6 * V_7 , void * V_32 )
{
struct V_59 * V_60 = F_29 ( V_7 ) ;
struct V_61 * V_33 = V_32 ;
T_4 V_62 = V_33 -> V_62 ;
T_4 V_63 = V_33 -> V_63 ;
if ( ( V_60 -> V_64 == V_62 ) &&
( V_60 -> V_65 == V_63 ) )
return 1 ;
return 0 ;
}
struct V_59 * F_30 ( T_4 V_62 , T_4 V_63 ,
struct V_59 * V_66 )
{
struct V_6 * V_7 ;
struct V_6 * V_67 = NULL ;
struct V_59 * V_60 = NULL ;
struct V_61 V_33 = {
. V_62 = V_62 ,
. V_63 = V_63
} ;
if ( V_66 )
V_67 = & V_66 -> V_6 ;
V_7 = F_31 ( & V_68 , V_67 , ( void * ) & V_33 ,
F_28 ) ;
if ( V_7 )
V_60 = F_29 ( V_7 ) ;
return V_60 ;
}
static void
F_32 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
memcpy ( & V_70 -> V_74 , V_72 , sizeof( struct V_71 ) ) ;
V_70 -> V_74 . V_75 = 0 ;
V_70 -> V_74 . V_76 = 0 ;
V_70 -> V_74 . V_77 = 0 ;
if ( V_73 < 0 ) {
V_70 -> V_74 . V_78 . V_79 = 1 ;
V_70 -> V_74 . V_80 = ( T_4 ) ( - V_73 ) ;
}
}
static void
F_33 ( struct V_71 * V_72 ,
int V_73 ,
enum V_81 V_82 )
{
struct V_69 V_83 ;
F_32 ( & V_83 , V_72 , V_73 ) ;
V_83 . V_84 . V_85 . V_82 = V_82 ;
if ( F_34 ( V_12 ,
V_86 , & V_83 ) ) {
return;
}
}
static void
F_35 ( struct V_69 * V_87 )
{
static int V_88 ;
enum V_81 V_82 = 0 ;
int V_89 = V_90 ;
F_36 ( V_91 , V_92 ) ;
if ( V_88 ) {
V_89 = - V_93 ;
goto V_94;
}
V_88 = 1 ;
F_36 ( V_95 , V_92 ) ;
V_82 =
V_87 -> V_84 . V_85 .
V_82 & V_96 ;
V_82 |= V_97 ;
V_94:
if ( V_87 -> V_74 . V_78 . V_98 )
F_33 ( & V_87 -> V_74 , V_89 , V_82 ) ;
}
static void
F_37 ( struct V_71 * V_72 , int V_73 )
{
struct V_69 V_83 ;
F_32 ( & V_83 , V_72 , V_73 ) ;
if ( V_83 . V_74 . V_78 . V_99 == 1 )
return;
if ( F_34 ( V_12 ,
V_86 , & V_83 ) ) {
return;
}
}
static void F_38 (
struct V_71 * V_72 , int V_73 ,
struct V_100 V_101 )
{
struct V_69 V_83 ;
F_32 ( & V_83 , V_72 , V_73 ) ;
V_83 . V_84 . V_102 . V_101 = V_101 ;
V_83 . V_84 . V_102 . V_78 . V_103 = 1 ;
if ( F_34 ( V_12 ,
V_86 , & V_83 ) ) {
return;
}
}
static void
F_39 ( struct V_69 * V_70 , enum V_104 V_105 )
{
T_4 V_106 ;
T_5 V_107 ;
if ( F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_108 ) ,
& V_107 , sizeof( T_5 ) ) < 0 ) {
F_36 ( V_109 ,
V_110 ) ;
return;
}
if ( V_107 != V_111 ) {
F_40 ( V_112 ,
V_107 ,
V_110 ) ;
return;
}
if ( F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_113 ) ,
& V_106 , sizeof( T_4 ) ) < 0 ) {
F_36 ( V_109 ,
V_110 ) ;
return;
}
if ( V_105 == V_114 ) {
if ( F_10 ( V_12 ,
V_106 ,
V_70 ,
sizeof( struct V_69 ) ) < 0 ) {
F_36 ( V_115 ,
V_110 ) ;
return;
}
} else {
V_106 += sizeof( struct V_69 ) ;
if ( F_10 ( V_12 ,
V_106 ,
V_70 ,
sizeof( struct V_69 ) ) < 0 ) {
F_36 ( V_116 ,
V_110 ) ;
return;
}
}
}
static void
F_41 ( enum V_117 V_118 ,
struct V_71 * V_119 ,
int V_73 )
{
if ( ! V_119 )
return;
if ( V_119 -> V_33 != ( T_4 ) V_118 )
return;
F_37 ( V_119 , V_73 ) ;
}
static void
F_42 ( enum V_117 V_118 ,
struct V_59 * V_120 , int V_73 ,
struct V_100 V_121 )
{
struct V_69 V_83 ;
T_4 V_62 = V_120 -> V_64 ;
T_4 V_63 = V_120 -> V_65 ;
if ( ! V_120 -> V_119 )
return;
if ( V_120 -> V_119 -> V_33 != V_118 )
return;
F_32 ( & V_83 , V_120 -> V_119 , V_73 ) ;
V_83 . V_84 . V_102 . V_62 = V_62 ;
V_83 . V_84 . V_102 . V_63 = V_63 ;
V_83 . V_84 . V_102 . V_101 = V_121 ;
if ( F_34 ( V_12 ,
V_86 , & V_83 ) )
return;
}
static void
F_43 ( enum V_117 V_118 ,
struct V_71 * V_119 ,
int V_73 )
{
if ( ! V_119 )
return;
if ( V_119 -> V_33 != ( T_4 ) V_118 )
return;
F_37 ( V_119 , V_73 ) ;
}
static void
F_44 ( struct V_59 * V_122 ,
T_4 V_84 , struct V_71 * V_72 ,
int V_73 , bool V_123 )
{
struct V_71 * V_124 = NULL ;
if ( ! V_122 ) {
V_124 = V_72 ;
goto V_94;
}
if ( V_122 -> V_119 ) {
V_73 = - V_125 ;
V_124 = V_122 -> V_119 ;
goto V_94;
}
if ( V_123 ) {
V_124 = F_45 ( sizeof( * V_124 ) , V_57 ) ;
if ( ! V_124 ) {
F_46 ( V_126 , V_84 ,
V_122 -> V_64 ,
V_110 ) ;
return;
}
memcpy ( V_124 , V_72 ,
sizeof( struct V_71 ) ) ;
V_122 -> V_119 = V_124 ;
}
if ( V_73 == V_90 ) {
switch ( V_84 ) {
case V_127 :
F_47 ( V_122 ) ;
break;
case V_128 :
F_48 ( V_122 ) ;
break;
}
}
V_94:
F_41 ( V_84 , V_124 , V_73 ) ;
}
static void
F_49 ( struct V_59 * V_129 ,
struct V_100 V_101 , T_4 V_84 ,
struct V_71 * V_72 , int V_73 ,
bool V_123 , bool V_130 )
{
struct V_71 * V_124 = NULL ;
if ( ! V_129 ) {
V_124 = V_72 ;
goto V_94;
}
if ( V_129 -> V_119 ) {
V_73 = - V_125 ;
V_124 = V_129 -> V_119 ;
goto V_94;
}
if ( V_123 ) {
V_124 = F_45 ( sizeof( * V_124 ) , V_57 ) ;
if ( ! V_124 ) {
V_73 = - V_131 ;
goto V_94;
}
memcpy ( V_124 , V_72 ,
sizeof( struct V_71 ) ) ;
V_129 -> V_119 = V_124 ;
}
if ( V_73 >= 0 ) {
switch ( V_84 ) {
case V_132 :
F_50 ( V_129 ) ;
break;
case V_133 :
if ( V_101 . V_134 == V_135 . V_134 &&
V_101 . V_136 ==
V_135 . V_136 ) {
F_51 ( V_129 ) ;
}
else if ( V_101 . V_134 == V_137 . V_134 &&
V_101 . V_136 ==
V_137 . V_136 ) {
F_52 ( V_129 ) ;
}
break;
case V_138 :
F_53 ( V_129 ) ;
break;
}
}
V_94:
F_43 ( V_84 , V_124 , V_73 ) ;
}
static void
F_54 ( struct V_69 * V_87 )
{
struct V_139 * V_84 = & V_87 -> V_84 ;
T_4 V_62 = V_84 -> V_140 . V_62 ;
int V_89 = V_90 ;
struct V_59 * V_122 ;
struct V_141 * V_141 ;
V_122 = F_30 ( V_62 , V_142 , NULL ) ;
if ( V_122 && ( V_122 -> V_101 . V_143 == 1 ) ) {
F_40 ( V_144 , V_62 ,
V_110 ) ;
V_89 = - V_93 ;
goto V_145;
}
V_122 = F_45 ( sizeof( * V_122 ) , V_57 ) ;
if ( ! V_122 ) {
F_40 ( V_144 , V_62 ,
V_110 ) ;
V_89 = - V_131 ;
goto V_145;
}
F_55 ( & V_122 -> V_146 ) ;
V_122 -> V_64 = V_62 ;
V_122 -> V_65 = V_142 ;
F_40 ( V_147 , V_62 , V_92 ) ;
V_141 = F_56 ( V_84 -> V_140 . V_148 ,
V_84 -> V_140 . V_149 ,
V_57 ,
V_84 -> V_140 . V_150 ) ;
if ( ! V_141 ) {
F_40 ( V_144 , V_62 ,
V_110 ) ;
V_89 = - V_131 ;
F_25 ( V_122 ) ;
V_122 = NULL ;
goto V_145;
}
V_122 -> V_141 = V_141 ;
if ( F_57 ( V_84 -> V_140 . V_151 , V_152 ) == 0 )
F_39 ( V_87 , V_114 ) ;
F_40 ( V_153 , V_62 , V_92 ) ;
V_145:
F_44 ( V_122 , V_127 , & V_87 -> V_74 ,
V_89 , V_87 -> V_74 . V_78 . V_98 == 1 ) ;
}
static void
F_58 ( struct V_69 * V_87 )
{
struct V_139 * V_84 = & V_87 -> V_84 ;
T_4 V_62 = V_84 -> V_154 . V_62 ;
struct V_59 * V_122 ;
int V_89 = V_90 ;
V_122 = F_30 ( V_62 , V_142 , NULL ) ;
if ( ! V_122 )
V_89 = - V_155 ;
else if ( V_122 -> V_101 . V_143 == 0 )
V_89 = - V_93 ;
F_44 ( V_122 , V_128 , & V_87 -> V_74 ,
V_89 , V_87 -> V_74 . V_78 . V_98 == 1 ) ;
}
static void
F_59 ( struct V_69 * V_87 ,
struct V_27 * V_156 )
{
struct V_139 * V_84 = & V_87 -> V_84 ;
T_4 V_62 ;
struct V_59 * V_122 ;
int V_89 = V_90 ;
V_62 = V_84 -> V_157 . V_62 ;
F_40 ( V_158 , V_62 ,
V_92 ) ;
V_122 = F_30 ( V_62 , V_142 , NULL ) ;
if ( ! V_122 ) {
F_40 ( V_159 , V_62 ,
V_110 ) ;
V_89 = - V_155 ;
} else if ( V_122 -> V_101 . V_143 == 0 ) {
F_40 ( V_159 , V_62 ,
V_110 ) ;
V_89 = - V_155 ;
} else if ( V_122 -> V_119 ) {
F_40 ( V_159 , V_62 ,
V_110 ) ;
V_89 = - V_125 ;
} else {
F_60
( V_122 -> V_141 ,
V_84 -> V_157 . V_160 ) ;
V_122 -> V_161 = F_22 ( V_156 ) ;
F_23 ( V_156 , V_47 ) ;
V_122 -> V_162 = F_26 ( V_156 ) ;
F_40 ( V_163 , V_62 ,
V_92 ) ;
}
F_44 ( V_122 , V_164 , & V_87 -> V_74 ,
V_89 , V_87 -> V_74 . V_78 . V_98 == 1 ) ;
}
static void
F_61 ( struct V_69 * V_87 )
{
struct V_139 * V_84 = & V_87 -> V_84 ;
T_4 V_62 = V_84 -> V_165 . V_62 ;
T_4 V_63 = V_84 -> V_165 . V_63 ;
struct V_59 * V_129 = NULL ;
struct V_59 * V_122 ;
struct V_141 * V_141 ;
int V_89 = V_90 ;
V_122 = F_30 ( V_62 , V_142 , NULL ) ;
if ( ! V_122 ) {
F_46 ( V_166 , V_63 , V_62 ,
V_110 ) ;
V_89 = - V_155 ;
goto V_94;
}
if ( V_122 -> V_101 . V_143 == 0 ) {
F_46 ( V_166 , V_63 , V_62 ,
V_110 ) ;
V_89 = - V_155 ;
goto V_94;
}
V_129 = F_30 ( V_62 , V_63 , NULL ) ;
if ( V_129 && ( V_129 -> V_101 . V_143 == 1 ) ) {
F_46 ( V_166 , V_63 , V_62 ,
V_110 ) ;
V_89 = - V_93 ;
goto V_94;
}
V_129 = F_45 ( sizeof( * V_129 ) , V_57 ) ;
if ( ! V_129 ) {
F_46 ( V_166 , V_63 , V_62 ,
V_110 ) ;
V_89 = - V_131 ;
goto V_94;
}
V_129 -> V_64 = V_62 ;
V_129 -> V_65 = V_63 ;
V_129 -> V_167 = V_84 -> V_165 . V_168 ;
V_129 -> V_6 . V_169 = & V_122 -> V_6 ;
F_46 ( V_170 , V_63 , V_62 ,
V_92 ) ;
V_141 =
F_62 ( V_84 -> V_165 . V_148 ,
V_84 -> V_165 . V_149 ,
V_57 ,
V_84 -> V_165 . V_171 ) ;
if ( ! V_141 ) {
F_46 ( V_166 , V_63 , V_62 ,
V_110 ) ;
V_89 = - V_131 ;
F_25 ( V_129 ) ;
V_129 = NULL ;
goto V_94;
}
V_129 -> V_141 = V_141 ;
V_129 -> V_172 = V_84 -> V_165 . V_171 ;
if ( F_57 ( V_84 -> V_165 . V_171 ,
V_173 ) == 0 )
F_39 ( V_87 , V_174 ) ;
F_46 ( V_175 , V_63 , V_62 ,
V_92 ) ;
V_94:
F_49 ( V_129 , V_135 ,
V_132 , & V_87 -> V_74 , V_89 ,
V_87 -> V_74 . V_78 . V_98 == 1 , 1 ) ;
}
static void
F_63 ( struct V_69 * V_87 )
{
struct V_139 * V_84 = & V_87 -> V_84 ;
T_4 V_62 = V_84 -> V_102 . V_62 ;
T_4 V_63 = V_84 -> V_102 . V_63 ;
struct V_100 V_101 = V_84 -> V_102 . V_101 ;
struct V_59 * V_129 ;
int V_89 = V_90 ;
V_129 = F_30 ( V_62 , V_63 , NULL ) ;
if ( ! V_129 ) {
F_46 ( V_176 , V_63 , V_62 ,
V_110 ) ;
V_89 = - V_177 ;
} else if ( V_129 -> V_101 . V_143 == 0 ) {
F_46 ( V_176 , V_63 , V_62 ,
V_110 ) ;
V_89 = - V_177 ;
}
if ( ( V_89 >= V_90 ) && V_129 )
F_49 ( V_129 , V_101 ,
V_133 , & V_87 -> V_74 , V_89 ,
V_87 -> V_74 . V_78 . V_98 == 1 , 1 ) ;
}
static void
F_64 ( struct V_69 * V_87 )
{
struct V_139 * V_84 = & V_87 -> V_84 ;
T_4 V_62 = V_84 -> V_178 . V_62 ;
T_4 V_63 = V_84 -> V_178 . V_63 ;
struct V_59 * V_129 ;
int V_89 = V_90 ;
V_129 = F_30 ( V_62 , V_63 , NULL ) ;
if ( ! V_129 )
V_89 = - V_177 ;
else if ( V_129 -> V_101 . V_143 == 0 )
V_89 = - V_93 ;
if ( ( V_89 >= V_90 ) && V_129 )
F_49 ( V_129 , V_135 ,
V_138 , & V_87 -> V_74 , V_89 ,
V_87 -> V_74 . V_78 . V_98 == 1 , 1 ) ;
}
static int
F_65 ( T_7 V_179 , T_7 V_180 , T_4 V_181 ,
struct V_182 * V_183 )
{
T_2 * V_184 = NULL ;
if ( ! V_183 )
return - V_185 ;
memset ( V_183 , 0 , sizeof( struct V_182 ) ) ;
if ( ( V_180 == 0 ) || ( V_181 == 0 ) )
return - V_185 ;
V_184 = F_66 ( V_179 + V_180 , V_181 , V_186 ) ;
if ( ! V_184 )
return - V_187 ;
V_183 -> V_180 = V_180 ;
V_183 -> V_181 = V_181 ;
V_183 -> V_188 = V_184 ;
return V_90 ;
}
static void
F_67 ( struct V_182 * V_183 )
{
if ( V_183 -> V_188 ) {
F_68 ( V_183 -> V_188 ) ;
V_183 -> V_188 = NULL ;
}
memset ( V_183 , 0 , sizeof( struct V_182 ) ) ;
}
static void
F_69 ( void )
{
T_7 V_179 = F_70 ( V_12 ) ;
T_7 V_189 = 0 ;
T_4 V_75 = 0 ;
if ( F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_190 ) ,
& V_189 , sizeof( V_189 ) ) < 0 ) {
F_36 ( V_191 ,
V_110 ) ;
return;
}
if ( F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_192 ) ,
& V_75 , sizeof( V_75 ) ) < 0 ) {
F_36 ( V_191 ,
V_110 ) ;
return;
}
F_65 ( V_179 ,
V_189 , V_75 ,
& V_193 ) ;
}
static int
F_71 ( void )
{
static T_8 V_33 = F_72 ( 0 ) ;
return F_73 ( & V_33 ) ;
}
static unsigned long
F_74 ( void )
{
return V_194 + F_75 ( V_195 ) ;
}
static struct V_196 *
F_76 ( struct V_69 * V_70 )
{
struct V_196 * V_197 ;
V_197 = F_27 ( sizeof( * V_197 ) , V_57 | V_58 ) ;
if ( ! V_197 )
return NULL ;
V_197 -> V_33 = F_71 () ;
V_197 -> V_198 = F_74 () ;
V_197 -> V_70 = * V_70 ;
return V_197 ;
}
static void
F_77 ( struct V_196 * V_197 )
{
F_25 ( V_197 ) ;
}
static int
F_78 ( int V_33 , T_5 V_199 )
{
struct V_200 * V_201 ;
struct V_200 * V_202 ;
F_79 ( & V_203 ) ;
F_80 (pos, tmp, &parahotplug_request_list) {
struct V_196 * V_197 =
F_81 ( V_201 , struct V_196 , V_204 ) ;
if ( V_197 -> V_33 == V_33 ) {
F_82 ( V_201 ) ;
F_83 ( & V_203 ) ;
V_197 -> V_70 . V_84 . V_102 . V_101 . V_199 = V_199 ;
if ( V_197 -> V_70 . V_74 . V_78 . V_98 )
F_38 (
& V_197 -> V_70 . V_74 , V_90 ,
V_197 -> V_70 . V_84 . V_102 . V_101 ) ;
F_77 ( V_197 ) ;
return 0 ;
}
}
F_83 ( & V_203 ) ;
return - V_17 ;
}
static T_1 F_84 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_15 )
{
unsigned int V_33 ;
int V_205 ;
if ( F_85 ( V_10 , 10 , & V_33 ) )
return - V_17 ;
V_205 = F_78 ( V_33 , 0 ) ;
if ( V_205 < 0 )
return V_205 ;
return V_15 ;
}
static T_1 F_86 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_3 V_15 )
{
unsigned int V_33 ;
if ( F_85 ( V_10 , 10 , & V_33 ) )
return - V_17 ;
F_78 ( V_33 , 1 ) ;
return V_15 ;
}
static void F_87 ( struct V_6 * V_7 )
{
}
static void
F_88 ( struct V_196 * V_197 )
{
struct V_139 * V_84 = & V_197 -> V_70 . V_84 ;
char V_206 [ 40 ] , V_207 [ 40 ] , V_208 [ 40 ] , V_209 [ 40 ] , V_210 [ 40 ] ,
V_211 [ 40 ] ;
char * V_212 [] = {
V_206 , V_207 , V_208 , V_209 , V_210 , V_211 , NULL
} ;
sprintf ( V_206 , L_4 ) ;
sprintf ( V_207 , L_5 , V_197 -> V_33 ) ;
sprintf ( V_208 , L_6 ,
V_84 -> V_102 . V_101 . V_199 ) ;
sprintf ( V_209 , L_7 ,
V_84 -> V_102 . V_62 ) ;
sprintf ( V_210 , L_8 ,
V_84 -> V_102 . V_63 >> 3 ) ;
sprintf ( V_211 , L_9 ,
V_84 -> V_102 . V_63 & 0x7 ) ;
F_89 ( & V_213 . V_7 . V_214 , V_215 ,
V_212 ) ;
}
static void
F_90 ( struct V_69 * V_87 )
{
struct V_196 * V_197 ;
V_197 = F_76 ( V_87 ) ;
if ( ! V_197 )
return;
if ( V_87 -> V_84 . V_102 . V_101 . V_199 ) {
F_88 ( V_197 ) ;
F_38
( & V_87 -> V_74 ,
V_90 ,
V_87 -> V_84 . V_102 . V_101 ) ;
F_77 ( V_197 ) ;
} else {
F_79 ( & V_203 ) ;
F_91 ( & V_197 -> V_204 , & V_216 ) ;
F_83 ( & V_203 ) ;
F_88 ( V_197 ) ;
}
}
static int
F_92 ( void )
{
F_93 ( & V_213 . V_7 . V_214 , V_217 ) ;
return V_90 ;
}
static int
F_94 ( void )
{
char V_218 [ 20 ] ;
char * V_212 [] = { V_218 , NULL } ;
sprintf ( V_218 , L_10 , 1 ) ;
F_89 ( & V_213 . V_7 . V_214 , V_215 ,
V_212 ) ;
return V_90 ;
}
static int
F_95 ( void )
{
F_93 ( & V_213 . V_7 . V_214 , V_219 ) ;
return V_90 ;
}
static void
F_96 ( struct V_71 * V_72 )
{
int V_89 = F_92 () ;
if ( V_89 != V_90 )
V_89 = - V_89 ;
if ( V_72 -> V_78 . V_98 )
F_37 ( V_72 , V_89 ) ;
}
static void
F_97 ( struct V_71 * V_72 )
{
int V_89 = F_94 () ;
if ( V_89 != V_90 )
V_89 = - V_89 ;
if ( V_72 -> V_78 . V_98 )
F_37 ( V_72 , V_89 ) ;
}
static void
F_98 ( struct V_71 * V_72 )
{
int V_89 = F_95 () ;
if ( V_89 != V_90 )
V_89 = - V_89 ;
if ( V_72 -> V_78 . V_98 )
F_37 ( V_72 , V_89 ) ;
}
static inline unsigned int
F_99 ( T_7 * V_220 , T_4 * V_221 )
{
struct V_222 V_223 ;
int V_224 = V_225 ;
T_7 V_226 ;
V_226 = F_100 ( & V_223 ) ;
F_101 ( V_227 , V_226 , V_224 ) ;
if ( F_102 ( V_224 ) ) {
* V_220 = V_223 . V_228 ;
* V_221 = V_223 . V_149 ;
}
return V_224 ;
}
static T_7 F_103 ( void )
{
T_7 V_229 = 0 ;
T_4 V_230 = 0 ;
if ( ! F_102 ( F_99 ( & V_229 , & V_230 ) ) )
return 0 ;
return V_229 ;
}
static void
F_104 ( struct V_231 * V_232 )
{
struct V_69 V_233 ;
struct V_69 V_234 ;
struct V_69 V_70 ;
T_4 V_106 ;
T_5 V_107 ;
F_36 ( V_235 , V_92 ) ;
V_70 . V_74 . V_33 = V_236 ;
V_70 . V_84 . V_85 . V_237 = 23 ;
V_70 . V_84 . V_85 . V_238 = 0 ;
F_35 ( & V_70 ) ;
if ( F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_108 ) ,
& V_107 , sizeof( T_5 ) ) < 0 ) {
F_36 ( V_109 ,
V_110 ) ;
return;
}
if ( V_107 != V_111 ) {
F_40 ( V_112 ,
V_107 ,
V_110 ) ;
return;
}
if ( F_5 ( V_12 ,
F_6 ( struct V_13 ,
V_113 ) ,
& V_106 , sizeof( T_4 ) ) < 0 ) {
F_36 ( V_109 ,
V_110 ) ;
return;
}
if ( F_5 ( V_12 ,
V_106 ,
& V_233 ,
sizeof( struct V_69 ) ) < 0 ) {
F_36 ( V_239 ,
V_110 ) ;
return;
}
if ( F_5 ( V_12 ,
V_106 +
sizeof( struct V_69 ) ,
& V_234 ,
sizeof( struct V_69 ) ) < 0 ) {
F_36 ( V_240 ,
V_110 ) ;
return;
}
if ( V_233 . V_84 . V_140 . V_148 ) {
F_54 ( & V_233 ) ;
} else {
F_36 ( V_241 ,
V_110 ) ;
return;
}
if ( V_234 . V_84 . V_165 . V_148 ) {
F_61 ( & V_234 ) ;
} else {
F_36 ( V_242 ,
V_110 ) ;
return;
}
F_36 ( V_243 , V_92 ) ;
}
void
F_105 ( struct V_59 * V_122 , int V_73 )
{
if ( V_73 >= 0 )
V_122 -> V_101 . V_143 = 1 ;
F_41 ( V_127 , V_122 -> V_119 ,
V_73 ) ;
F_25 ( V_122 -> V_119 ) ;
V_122 -> V_119 = NULL ;
}
void
F_106 ( struct V_59 * V_122 , int V_73 )
{
F_41 ( V_128 , V_122 -> V_119 ,
V_73 ) ;
F_25 ( V_122 -> V_119 ) ;
V_122 -> V_119 = NULL ;
}
void
F_107 ( struct V_59 * V_129 , int V_73 )
{
if ( V_73 >= 0 )
V_129 -> V_101 . V_143 = 1 ;
F_43 ( V_132 , V_129 -> V_119 ,
V_73 ) ;
F_25 ( V_129 -> V_119 ) ;
V_129 -> V_119 = NULL ;
}
void
F_108 ( struct V_59 * V_129 , int V_73 )
{
F_43 ( V_138 , V_129 -> V_119 ,
V_73 ) ;
F_25 ( V_129 -> V_119 ) ;
V_129 -> V_119 = NULL ;
}
void
F_109 ( struct V_59 * V_129 ,
int V_73 )
{
F_42 ( V_133 ,
V_129 , V_73 ,
V_137 ) ;
F_25 ( V_129 -> V_119 ) ;
V_129 -> V_119 = NULL ;
}
void
F_110 ( struct V_59 * V_129 , int V_73 )
{
F_42 ( V_133 ,
V_129 , V_73 ,
V_135 ) ;
F_25 ( V_129 -> V_119 ) ;
V_129 -> V_119 = NULL ;
}
static int
F_111 ( struct V_2 * V_2 , struct V_244 * V_245 )
{
unsigned long V_226 = 0 ;
unsigned long V_180 = V_245 -> V_246 << V_247 ;
T_7 V_229 = 0 ;
if ( V_180 & ( V_14 - 1 ) )
return - V_248 ;
switch ( V_180 ) {
case V_249 :
V_245 -> V_250 |= V_251 ;
if ( ! * V_252 )
return - V_248 ;
F_5
( * V_252 ,
F_6 ( struct V_13 ,
V_253 ) ,
& V_229 , sizeof( V_229 ) ) ;
if ( ! V_229 )
return - V_248 ;
V_226 = ( unsigned long ) V_229 ;
if ( F_112 ( V_245 , V_245 -> V_254 ,
V_226 >> V_247 ,
V_245 -> V_255 - V_245 -> V_254 ,
( V_245 -> V_256 ) ) ) {
return - V_257 ;
}
break;
default:
return - V_248 ;
}
return 0 ;
}
static inline T_9 F_113 ( void )
{
T_7 V_224 = V_225 ;
T_7 V_226 = 0 ;
F_101 ( V_258 , V_226 ,
V_224 ) ;
return V_224 ;
}
static inline int F_114 ( T_7 V_259 )
{
int V_224 = V_225 ;
F_101 ( V_260 , V_259 , V_224 ) ;
return V_224 ;
}
static long F_115 ( struct V_2 * V_2 , unsigned int V_84 ,
unsigned long V_261 )
{
T_7 V_259 ;
T_9 V_262 ;
switch ( V_84 ) {
case V_258 :
V_262 = F_113 () ;
if ( F_116 ( ( void V_263 * ) V_261 , & V_262 ,
sizeof( V_262 ) ) ) {
return - V_264 ;
}
return 0 ;
case V_260 :
if ( F_117 ( & V_259 , ( void V_263 * ) V_261 ,
sizeof( V_259 ) ) ) {
return - V_264 ;
}
return F_114 ( V_259 ) ;
default:
return - V_264 ;
}
}
static int
F_118 ( T_10 V_265 , struct V_141 * * V_12 )
{
int V_89 = 0 ;
V_252 = V_12 ;
F_119 ( & V_266 , & V_267 ) ;
V_266 . V_268 = V_269 ;
if ( F_120 ( V_265 ) == 0 ) {
V_89 = F_121 ( & V_265 , 0 , 1 , L_11 ) ;
if ( V_89 < 0 )
return V_89 ;
} else {
V_89 = F_122 ( V_265 , 1 , L_11 ) ;
if ( V_89 < 0 )
return V_89 ;
}
V_89 = F_123 ( & V_266 , F_124 ( F_120 ( V_265 ) , 0 ) , 1 ) ;
if ( V_89 < 0 ) {
F_125 ( V_265 , 1 ) ;
return V_89 ;
}
return 0 ;
}
static void
F_126 ( T_10 V_265 )
{
if ( V_266 . V_270 )
F_127 ( & V_266 ) ;
V_266 . V_270 = NULL ;
F_125 ( V_265 , 1 ) ;
}
static struct V_27 *
F_128 ( T_7 V_229 , T_4 V_181 , bool V_271 , bool * V_272 )
{
int V_273 = sizeof( struct V_27 ) + V_181 ;
struct V_27 * V_28 ;
if ( V_272 )
* V_272 = false ;
V_273 ++ ;
if ( ( V_50 + V_181 )
> V_274 ) {
if ( V_272 )
* V_272 = true ;
return NULL ;
}
V_28 = F_45 ( V_273 , V_57 | V_58 ) ;
if ( ! V_28 ) {
if ( V_272 )
* V_272 = true ;
return NULL ;
}
V_28 -> V_273 = V_273 ;
V_28 -> V_51 = V_181 ;
V_28 -> V_37 = NULL ;
V_28 -> V_39 = 0 ;
V_28 -> V_275 = false ;
if ( V_271 ) {
void * V_120 ;
if ( V_229 > F_100 ( V_276 - 1 ) )
goto V_277;
V_120 = F_129 ( ( unsigned long ) ( V_229 ) ) ;
memcpy ( V_28 -> V_32 , V_120 , V_181 ) ;
} else {
void * V_278 = F_66 ( V_229 , V_181 , V_186 ) ;
if ( ! V_278 )
goto V_277;
memcpy ( V_28 -> V_32 , V_278 , V_181 ) ;
F_68 ( V_278 ) ;
}
V_28 -> V_275 = true ;
V_50 += V_28 -> V_51 ;
return V_28 ;
V_277:
F_24 ( V_28 ) ;
return NULL ;
}
static bool
F_130 ( struct V_69 V_87 , T_7 V_148 )
{
struct V_139 * V_84 = & V_87 . V_84 ;
T_7 V_279 ;
T_4 V_280 ;
struct V_27 * V_156 = NULL ;
bool V_281 ;
struct V_69 V_282 ;
V_281 = ( V_87 . V_74 . V_78 . V_99 == 1 ) ;
if ( V_148 == 0 )
return true ;
V_279 = V_148 + V_87 . V_74 . V_76 ;
V_280 = V_87 . V_74 . V_75 ;
if ( V_279 && V_280 ) {
bool V_272 = false ;
V_156 =
F_128 ( V_279 , V_280 ,
V_281 , & V_272 ) ;
if ( ! V_156 && V_272 )
return false ;
}
if ( ! V_281 ) {
F_32 ( & V_282 , & V_87 . V_74 ,
V_90 ) ;
if ( V_12 )
F_34 ( V_12 ,
V_283 ,
& V_282 ) ;
}
switch ( V_87 . V_74 . V_33 ) {
case V_236 :
F_35 ( & V_87 ) ;
break;
case V_127 :
F_54 ( & V_87 ) ;
break;
case V_128 :
F_58 ( & V_87 ) ;
break;
case V_164 :
F_59 ( & V_87 , V_156 ) ;
break;
case V_132 :
F_61 ( & V_87 ) ;
break;
case V_133 :
if ( V_84 -> V_102 . V_78 . V_103 ) {
F_90 ( & V_87 ) ;
} else {
F_63 ( & V_87 ) ;
break;
}
break;
case V_138 :
F_64 ( & V_87 ) ;
break;
case V_284 :
if ( V_87 . V_74 . V_78 . V_98 )
F_37 ( & V_87 . V_74 , V_90 ) ;
break;
case V_285 :
F_96 ( & V_87 . V_74 ) ;
break;
case V_286 :
F_97 ( & V_87 . V_74 ) ;
break;
case V_287 :
F_98 ( & V_87 . V_74 ) ;
break;
default:
if ( V_87 . V_74 . V_78 . V_98 )
F_37
( & V_87 . V_74 ,
- V_288 ) ;
break;
}
if ( V_156 ) {
F_24 ( V_156 ) ;
V_156 = NULL ;
}
return true ;
}
static bool
F_131 ( struct V_69 * V_70 )
{
if ( ! F_132 ( V_12 ,
V_289 , V_70 ) ) {
if ( V_70 -> V_74 . V_78 . V_99 == 1 )
return false ;
return true ;
}
return false ;
}
static void
F_133 ( void )
{
struct V_200 * V_201 ;
struct V_200 * V_202 ;
F_79 ( & V_203 ) ;
F_80 (pos, tmp, &parahotplug_request_list) {
struct V_196 * V_197 =
F_81 ( V_201 , struct V_196 , V_204 ) ;
if ( ! F_134 ( V_194 , V_197 -> V_198 ) )
continue;
F_82 ( V_201 ) ;
if ( V_197 -> V_70 . V_74 . V_78 . V_98 )
F_38 (
& V_197 -> V_70 . V_74 ,
V_290 ,
V_197 -> V_70 . V_84 . V_102 . V_101 ) ;
F_77 ( V_197 ) ;
}
F_83 ( & V_203 ) ;
}
static void
F_135 ( struct V_231 * V_232 )
{
struct V_69 V_87 ;
bool V_291 = false ;
bool V_292 = false ;
while ( ! F_132 ( V_12 ,
V_293 ,
& V_87 ) )
;
if ( ! V_291 ) {
if ( V_294 ) {
V_87 = V_295 ;
V_294 = false ;
V_291 = true ;
} else {
V_291 = F_131 ( & V_87 ) ;
}
}
V_292 = false ;
while ( V_291 && ( ! V_292 ) ) {
V_296 = V_194 ;
if ( F_130 ( V_87 ,
F_70
( V_12 ) ) )
V_291 = F_131 ( & V_87 ) ;
else {
V_292 = true ;
V_295 = V_87 ;
V_294 = true ;
}
}
F_133 () ;
if ( F_136 ( V_194 ,
V_296 + ( V_297 * V_298 ) ) ) {
if ( V_299 != V_300 )
V_299 = V_300 ;
} else {
if ( V_299 != V_301 )
V_299 = V_301 ;
}
F_137 ( & V_302 , V_299 ) ;
}
static int
F_138 ( struct V_303 * V_303 )
{
int V_205 = - V_4 ;
T_7 V_229 ;
T_6 V_304 = V_305 ;
V_229 = F_103 () ;
if ( ! V_229 )
goto error;
memset ( & V_193 , 0 , sizeof( V_193 ) ) ;
V_12 = F_62 ( V_229 , 0 ,
V_57 , V_304 ) ;
if ( ! V_12 )
goto error;
if ( F_139 (
F_140 ( V_12 ) ) ) {
F_69 () ;
} else {
goto V_306;
}
V_265 = F_124 ( V_307 , 0 ) ;
V_205 = F_118 ( V_265 , & V_12 ) ;
if ( V_205 < 0 )
goto V_308;
if ( F_141 () )
F_142 ( & V_302 ,
F_104 ) ;
else
F_142 ( & V_302 ,
F_135 ) ;
V_296 = V_194 ;
V_299 = V_301 ;
F_137 ( & V_302 , V_299 ) ;
V_213 . V_7 . V_309 = V_265 ;
if ( F_143 ( & V_213 ) < 0 ) {
F_36 ( V_310 , V_311 ) ;
V_205 = - V_4 ;
goto V_312;
}
F_36 ( V_313 , V_92 ) ;
V_205 = F_144 () ;
if ( V_205 < 0 )
goto V_314;
return 0 ;
V_314:
F_145 ( & V_213 ) ;
V_312:
F_146 ( & V_302 ) ;
F_126 ( V_265 ) ;
V_308:
F_67 ( & V_193 ) ;
V_306:
F_147 ( V_12 ) ;
error:
F_40 ( V_315 , V_205 , V_110 ) ;
return V_205 ;
}
static int
F_148 ( struct V_303 * V_303 )
{
F_36 ( V_316 , V_92 ) ;
F_149 () ;
F_146 ( & V_302 ) ;
F_67 ( & V_193 ) ;
F_147 ( V_12 ) ;
F_126 ( V_213 . V_7 . V_309 ) ;
F_145 ( & V_213 ) ;
F_36 ( V_316 , V_92 ) ;
return 0 ;
}
static T_11 T_12 F_150 ( void )
{
unsigned int V_317 , V_318 , V_319 , V_320 ;
if ( F_151 ( V_321 ) ) {
F_152 ( V_322 , & V_317 , & V_318 , & V_319 , & V_320 ) ;
return ( V_318 == V_323 ) &&
( V_319 == V_324 ) &&
( V_320 == V_325 ) ;
} else {
return 0 ;
}
}
static int F_153 ( void )
{
int V_224 ;
if ( ! F_150 () )
return - V_4 ;
V_224 = F_154 ( & V_326 ) ;
if ( V_224 )
return - V_4 ;
F_155 ( L_12 ) ;
return 0 ;
}
static void F_156 ( void )
{
F_157 ( & V_326 ) ;
}
