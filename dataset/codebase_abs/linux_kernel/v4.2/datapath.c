static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 )
{
return V_4 -> V_6 -> V_7 & V_8 ||
F_2 ( V_2 , F_3 ( V_4 ) , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_3 * V_4 )
{
F_5 ( V_2 , V_10 , F_3 ( V_4 ) , V_4 -> V_11 ,
0 , V_4 -> V_6 , V_12 ) ;
}
void F_6 ( void )
{
F_7 ( & V_13 ) ;
}
void F_8 ( void )
{
F_9 ( & V_13 ) ;
}
int F_10 ( void )
{
if ( V_14 )
return F_11 ( & V_13 ) ;
else
return 1 ;
}
static struct V_15 * F_12 ( struct V_16 * V_16 , int V_17 )
{
struct V_18 * V_19 = F_13 ( V_16 , V_17 ) ;
if ( V_19 ) {
struct V_20 * V_20 = F_14 ( V_19 ) ;
if ( V_20 )
return V_20 -> V_21 ;
}
return NULL ;
}
static inline struct V_15 * F_15 ( struct V_16 * V_16 , int V_17 )
{
struct V_15 * V_21 ;
F_16 ( ! F_17 () && ! F_10 () ) ;
F_18 () ;
V_21 = F_12 ( V_16 , V_17 ) ;
F_19 () ;
return V_21 ;
}
const char * F_20 ( const struct V_15 * V_21 )
{
struct V_20 * V_20 = F_21 ( V_21 , V_22 ) ;
return V_20 -> V_23 -> V_24 ( V_20 ) ;
}
static int F_22 ( const struct V_15 * V_21 )
{
struct V_20 * V_25 ;
int V_26 ;
F_18 () ;
V_25 = F_23 ( V_21 , V_22 ) ;
if ( V_25 )
V_26 = F_24 ( V_25 ) -> V_19 -> V_26 ;
else
V_26 = 0 ;
F_19 () ;
return V_26 ;
}
static void F_25 ( struct V_27 * V_28 )
{
struct V_15 * V_21 = F_26 ( V_28 , struct V_15 , V_28 ) ;
F_27 ( & V_21 -> V_29 ) ;
F_28 ( V_21 -> V_30 ) ;
F_29 ( V_21 -> V_31 ) ;
F_29 ( V_21 ) ;
}
static struct V_32 * F_30 ( const struct V_15 * V_21 ,
T_1 V_33 )
{
return & V_21 -> V_31 [ V_33 & ( V_34 - 1 ) ] ;
}
struct V_20 * F_31 ( const struct V_15 * V_21 , T_1 V_33 )
{
struct V_20 * V_20 ;
struct V_32 * V_35 ;
V_35 = F_30 ( V_21 , V_33 ) ;
F_32 (vport, head, dp_hash_node) {
if ( V_20 -> V_33 == V_33 )
return V_20 ;
}
return NULL ;
}
static struct V_20 * F_33 ( const struct V_36 * V_37 )
{
struct V_20 * V_20 ;
V_20 = F_34 ( V_37 ) ;
if ( ! F_35 ( V_20 ) ) {
struct V_15 * V_21 = V_37 -> V_21 ;
struct V_32 * V_35 = F_30 ( V_21 , V_20 -> V_33 ) ;
F_36 ( & V_20 -> V_38 , V_35 ) ;
}
return V_20 ;
}
void F_37 ( struct V_20 * V_39 )
{
F_38 () ;
F_39 ( & V_39 -> V_38 ) ;
F_40 ( V_39 ) ;
}
void F_41 ( struct V_9 * V_10 , struct V_40 * V_41 )
{
const struct V_20 * V_39 = F_42 ( V_10 ) -> V_42 ;
struct V_15 * V_21 = V_39 -> V_21 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_2 * V_49 ;
T_3 V_50 ;
V_48 = F_43 ( V_21 -> V_30 ) ;
V_44 = F_44 ( & V_21 -> V_29 , V_41 , & V_50 ) ;
if ( F_45 ( ! V_44 ) ) {
struct V_51 V_52 ;
int error ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_53 = V_54 ;
V_52 . V_55 = F_46 ( V_39 , V_10 ) ;
error = F_47 ( V_21 , V_10 , V_41 , & V_52 ) ;
if ( F_45 ( error ) )
F_48 ( V_10 ) ;
else
F_49 ( V_10 ) ;
V_49 = & V_48 -> V_56 ;
goto V_57;
}
F_50 ( V_44 , V_41 -> V_58 . V_59 , V_10 ) ;
V_46 = F_51 ( V_44 -> V_46 ) ;
F_52 ( V_21 , V_10 , V_46 , V_41 ) ;
V_49 = & V_48 -> V_60 ;
V_57:
F_53 ( & V_48 -> V_61 ) ;
( * V_49 ) ++ ;
V_48 -> V_50 += V_50 ;
F_54 ( & V_48 -> V_61 ) ;
}
int F_47 ( struct V_15 * V_21 , struct V_9 * V_10 ,
const struct V_40 * V_41 ,
const struct V_51 * V_62 )
{
struct V_47 * V_48 ;
int V_63 ;
if ( V_62 -> V_55 == 0 ) {
V_63 = - V_64 ;
goto V_63;
}
if ( ! F_55 ( V_10 ) )
V_63 = F_56 ( V_21 , V_10 , V_41 , V_62 ) ;
else
V_63 = F_57 ( V_21 , V_10 , V_41 , V_62 ) ;
if ( V_63 )
goto V_63;
return 0 ;
V_63:
V_48 = F_43 ( V_21 -> V_30 ) ;
F_53 ( & V_48 -> V_61 ) ;
V_48 -> V_65 ++ ;
F_54 ( & V_48 -> V_61 ) ;
return V_63 ;
}
static int F_57 ( struct V_15 * V_21 , struct V_9 * V_10 ,
const struct V_40 * V_41 ,
const struct V_51 * V_62 )
{
unsigned short V_66 = F_58 ( V_10 ) -> V_66 ;
struct V_40 V_67 ;
struct V_9 * V_68 , * V_69 ;
struct V_70 V_71 ;
int V_63 ;
V_71 = * F_42 ( V_10 ) ;
V_68 = F_59 ( V_10 , V_72 , false ) ;
* F_42 ( V_10 ) = V_71 ;
if ( F_35 ( V_68 ) )
return F_60 ( V_68 ) ;
if ( V_68 == NULL )
return - V_73 ;
if ( V_66 & V_74 ) {
V_67 = * V_41 ;
V_67 . V_75 . V_76 = V_77 ;
}
V_10 = V_68 ;
do {
* F_42 ( V_10 ) = V_71 ;
if ( V_66 & V_74 && V_10 != V_68 )
V_41 = & V_67 ;
V_63 = F_56 ( V_21 , V_10 , V_41 , V_62 ) ;
if ( V_63 )
break;
} while ( ( V_10 = V_10 -> V_78 ) );
V_10 = V_68 ;
do {
V_69 = V_10 -> V_78 ;
if ( V_63 )
F_48 ( V_10 ) ;
else
F_49 ( V_10 ) ;
} while ( ( V_10 = V_69 ) );
return V_63 ;
}
static T_4 F_61 ( const struct V_51 * V_62 ,
unsigned int V_79 )
{
T_4 V_80 = F_62 ( sizeof( struct V_81 ) )
+ F_63 ( V_79 )
+ F_63 ( F_64 () ) ;
if ( V_62 -> V_82 )
V_80 += F_65 ( V_62 -> V_82 -> V_83 ) ;
if ( V_62 -> V_84 )
V_80 += F_63 ( F_66 () ) ;
if ( V_62 -> V_85 )
V_80 += F_63 ( V_62 -> V_85 ) ;
return V_80 ;
}
static int F_56 ( struct V_15 * V_21 , struct V_9 * V_10 ,
const struct V_40 * V_41 ,
const struct V_51 * V_62 )
{
struct V_81 * V_52 ;
struct V_9 * V_69 = NULL ;
struct V_9 * V_86 = NULL ;
struct V_87 * V_88 ;
struct V_3 V_4 = {
. V_89 = F_67 ( V_21 ) -> V_90 ,
. V_11 = V_62 -> V_55 ,
} ;
T_4 V_91 ;
unsigned int V_92 ;
int V_63 , V_17 ;
V_17 = F_22 ( V_21 ) ;
if ( ! V_17 )
return - V_93 ;
if ( F_68 ( V_10 ) ) {
V_69 = F_69 ( V_10 , V_94 ) ;
if ( ! V_69 )
return - V_95 ;
V_69 = F_70 ( V_69 ) ;
if ( ! V_69 )
return - V_95 ;
V_10 = V_69 ;
}
if ( F_71 ( V_10 -> V_91 ) > V_96 ) {
V_63 = - V_97 ;
goto V_57;
}
if ( V_10 -> V_98 == V_99 &&
( V_63 = F_72 ( V_10 ) ) )
goto V_57;
if ( V_21 -> V_100 & V_101 )
V_92 = F_73 ( V_10 ) ;
else
V_92 = V_10 -> V_91 ;
V_91 = F_61 ( V_62 , V_92 ) ;
V_86 = F_74 ( V_91 , & V_4 , V_94 ) ;
if ( ! V_86 ) {
V_63 = - V_95 ;
goto V_57;
}
V_52 = F_75 ( V_86 , 0 , 0 , & V_102 ,
0 , V_62 -> V_53 ) ;
V_52 -> V_17 = V_17 ;
V_63 = F_76 ( V_41 , V_41 , V_103 , false , V_86 ) ;
F_77 ( V_63 ) ;
if ( V_62 -> V_82 )
F_78 ( V_86 , V_104 ,
V_83 ( V_62 -> V_82 ) ,
F_79 ( V_62 -> V_82 ) ) ;
if ( V_62 -> V_84 ) {
V_88 = F_80 ( V_86 , V_105 ) ;
V_63 = F_81 ( V_86 ,
V_62 -> V_84 ) ;
F_77 ( V_63 ) ;
F_82 ( V_86 , V_88 ) ;
}
if ( V_62 -> V_85 ) {
V_88 = F_80 ( V_86 , V_106 ) ;
V_63 = F_83 ( V_62 -> V_107 ,
V_62 -> V_85 ,
V_86 ) ;
if ( ! V_63 )
F_82 ( V_86 , V_88 ) ;
else
F_84 ( V_86 , V_88 ) ;
}
if ( ! ( V_88 = F_85 ( V_86 , V_108 , 0 ) ) ) {
V_63 = - V_109 ;
goto V_57;
}
V_88 -> V_83 = F_71 ( V_10 -> V_91 ) ;
V_63 = F_86 ( V_86 , V_10 , V_10 -> V_91 , V_92 ) ;
if ( V_63 )
goto V_57;
if ( ! ( V_21 -> V_100 & V_101 ) ) {
T_4 V_110 = F_65 ( V_86 -> V_91 ) - V_86 -> V_91 ;
if ( V_110 > 0 )
memset ( F_87 ( V_86 , V_110 ) , 0 , V_110 ) ;
}
( (struct V_111 * ) V_86 -> V_112 ) -> V_113 = V_86 -> V_91 ;
V_63 = F_88 ( F_67 ( V_21 ) , V_86 , V_62 -> V_55 ) ;
V_86 = NULL ;
V_57:
if ( V_63 )
F_89 ( V_10 ) ;
F_48 ( V_86 ) ;
F_48 ( V_69 ) ;
return V_63 ;
}
static int F_90 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_81 * V_81 = V_4 -> V_114 ;
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_45 * V_117 ;
struct V_9 * V_118 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_15 * V_21 ;
struct V_119 * V_120 ;
struct V_20 * V_42 ;
int V_91 ;
int V_63 ;
bool log = ! V_115 [ V_121 ] ;
V_63 = - V_73 ;
if ( ! V_115 [ V_108 ] || ! V_115 [ V_103 ] ||
! V_115 [ V_106 ] )
goto V_63;
V_91 = V_83 ( V_115 [ V_108 ] ) ;
V_118 = F_91 ( V_122 + V_91 , V_12 ) ;
V_63 = - V_95 ;
if ( ! V_118 )
goto V_63;
F_92 ( V_118 , V_122 ) ;
F_93 ( F_94 ( V_118 , V_91 ) , V_115 [ V_108 ] , V_91 ) ;
F_95 ( V_118 ) ;
V_120 = F_96 ( V_118 ) ;
if ( F_97 ( V_120 -> V_123 ) )
V_118 -> V_124 = V_120 -> V_123 ;
else
V_118 -> V_124 = F_98 ( V_125 ) ;
V_44 = F_99 () ;
V_63 = F_60 ( V_44 ) ;
if ( F_35 ( V_44 ) )
goto V_126;
V_63 = F_100 ( V_115 [ V_103 ] , V_118 ,
& V_44 -> V_41 , log ) ;
if ( V_63 )
goto V_127;
V_63 = F_101 ( V_115 [ V_106 ] ,
& V_44 -> V_41 , & V_117 , log ) ;
if ( V_63 )
goto V_127;
F_102 ( V_44 -> V_46 , V_117 ) ;
F_42 ( V_118 ) -> V_84 = NULL ;
V_118 -> V_128 = V_44 -> V_41 . V_129 . V_128 ;
V_118 -> V_130 = V_44 -> V_41 . V_129 . V_131 ;
F_18 () ;
V_21 = F_12 ( F_103 ( V_10 -> V_132 ) , V_81 -> V_17 ) ;
V_63 = - V_93 ;
if ( ! V_21 )
goto V_133;
V_42 = F_23 ( V_21 , V_44 -> V_41 . V_129 . V_134 ) ;
if ( ! V_42 )
V_42 = F_23 ( V_21 , V_22 ) ;
if ( ! V_42 )
goto V_133;
F_42 ( V_118 ) -> V_42 = V_42 ;
V_46 = F_51 ( V_44 -> V_46 ) ;
F_104 () ;
V_63 = F_52 ( V_21 , V_118 , V_46 , & V_44 -> V_41 ) ;
F_105 () ;
F_19 () ;
F_106 ( V_44 , false ) ;
return V_63 ;
V_133:
F_19 () ;
V_127:
F_106 ( V_44 , false ) ;
V_126:
F_48 ( V_118 ) ;
V_63:
return V_63 ;
}
static void F_107 ( const struct V_15 * V_21 , struct V_135 * V_48 ,
struct V_136 * V_137 )
{
int V_138 ;
memset ( V_137 , 0 , sizeof( * V_137 ) ) ;
V_48 -> V_139 = F_108 ( & V_21 -> V_29 ) ;
V_137 -> V_140 = F_109 ( & V_21 -> V_29 ) ;
V_48 -> V_60 = V_48 -> V_56 = V_48 -> V_65 = 0 ;
F_110 (i) {
const struct V_47 * V_141 ;
struct V_47 V_142 ;
unsigned int V_143 ;
V_141 = F_111 ( V_21 -> V_30 , V_138 ) ;
do {
V_143 = F_112 ( & V_141 -> V_61 ) ;
V_142 = * V_141 ;
} while ( F_113 ( & V_141 -> V_61 , V_143 ) );
V_48 -> V_60 += V_142 . V_60 ;
V_48 -> V_56 += V_142 . V_56 ;
V_48 -> V_65 += V_142 . V_65 ;
V_137 -> V_50 += V_142 . V_50 ;
}
}
static bool F_114 ( const struct V_144 * V_145 , T_5 V_146 )
{
return F_115 ( V_145 ) &&
! ( V_146 & V_147 ) ;
}
static bool F_116 ( T_5 V_146 )
{
return ! ( V_146 & V_148 ) ;
}
static bool F_117 ( T_5 V_146 )
{
return ! ( V_146 & V_149 ) ;
}
static T_4 F_118 ( const struct V_45 * V_117 ,
const struct V_144 * V_145 ,
T_5 V_146 )
{
T_4 V_91 = F_62 ( sizeof( struct V_81 ) ) ;
if ( V_145 && F_115 ( V_145 ) )
V_91 += F_63 ( V_145 -> V_150 ) ;
if ( ! V_145 || F_114 ( V_145 , V_146 ) )
V_91 += F_63 ( F_64 () ) ;
if ( F_116 ( V_146 ) )
V_91 += F_63 ( F_64 () ) ;
if ( F_117 ( V_146 ) )
V_91 += F_63 ( V_117 -> V_85 ) ;
return V_91
+ F_63 ( sizeof( struct V_151 ) )
+ F_63 ( 1 )
+ F_63 ( 8 ) ;
}
static int F_119 ( const struct V_43 * V_44 ,
struct V_9 * V_10 )
{
struct V_151 V_48 ;
T_6 V_152 ;
unsigned long V_153 ;
F_120 ( V_44 , & V_48 , & V_153 , & V_152 ) ;
if ( V_153 &&
F_121 ( V_10 , V_154 , F_122 ( V_153 ) ) )
return - V_155 ;
if ( V_48 . V_156 &&
F_123 ( V_10 , V_157 , sizeof( struct V_151 ) , & V_48 ) )
return - V_155 ;
if ( ( V_158 ) F_124 ( V_152 ) &&
F_125 ( V_10 , V_159 , ( V_158 ) F_124 ( V_152 ) ) )
return - V_155 ;
return 0 ;
}
static int F_126 ( const struct V_43 * V_44 ,
struct V_9 * V_10 , int V_160 )
{
struct V_87 * V_143 ;
int V_63 ;
V_143 = F_80 ( V_10 , V_161 ) ;
if ( V_143 ) {
const struct V_45 * V_46 ;
V_46 = F_127 ( V_44 -> V_46 ) ;
V_63 = F_83 ( V_46 -> V_107 ,
V_46 -> V_85 , V_10 ) ;
if ( ! V_63 )
F_82 ( V_10 , V_143 ) ;
else {
if ( V_160 )
return V_63 ;
F_84 ( V_10 , V_143 ) ;
}
} else if ( V_160 ) {
return - V_155 ;
}
return 0 ;
}
static int F_128 ( const struct V_43 * V_44 , int V_17 ,
struct V_9 * V_10 , T_3 V_55 ,
T_3 V_162 , T_3 V_59 , V_158 V_53 , T_3 V_146 )
{
const int V_160 = V_10 -> V_91 ;
struct V_81 * V_81 ;
int V_63 ;
V_81 = F_75 ( V_10 , V_55 , V_162 , & V_163 ,
V_59 , V_53 ) ;
if ( ! V_81 )
return - V_155 ;
V_81 -> V_17 = V_17 ;
V_63 = F_129 ( V_44 , V_10 ) ;
if ( V_63 )
goto error;
if ( F_114 ( & V_44 -> V_164 , V_146 ) ) {
V_63 = F_130 ( V_44 , V_10 ) ;
if ( V_63 )
goto error;
}
if ( F_116 ( V_146 ) ) {
V_63 = F_131 ( V_44 , V_10 ) ;
if ( V_63 )
goto error;
}
V_63 = F_119 ( V_44 , V_10 ) ;
if ( V_63 )
goto error;
if ( F_117 ( V_146 ) ) {
V_63 = F_126 ( V_44 , V_10 , V_160 ) ;
if ( V_63 )
goto error;
}
F_132 ( V_10 , V_81 ) ;
return 0 ;
error:
F_133 ( V_10 , V_81 ) ;
return V_63 ;
}
static struct V_9 * F_134 ( const struct V_45 * V_117 ,
const struct V_144 * V_145 ,
struct V_3 * V_4 ,
bool V_165 ,
T_5 V_146 )
{
struct V_9 * V_10 ;
T_4 V_91 ;
if ( ! V_165 && ! F_1 ( & V_163 , V_4 , 0 ) )
return NULL ;
V_91 = F_118 ( V_117 , V_145 , V_146 ) ;
V_10 = F_74 ( V_91 , V_4 , V_12 ) ;
if ( ! V_10 )
return F_135 ( - V_95 ) ;
return V_10 ;
}
static struct V_9 * F_136 ( const struct V_43 * V_44 ,
int V_17 ,
struct V_3 * V_4 , V_158 V_53 ,
bool V_165 , T_3 V_146 )
{
struct V_9 * V_10 ;
int V_166 ;
V_10 = F_134 ( F_137 ( V_44 -> V_46 ) ,
& V_44 -> V_164 , V_4 , V_165 , V_146 ) ;
if ( F_138 ( V_10 ) )
return V_10 ;
V_166 = F_128 ( V_44 , V_17 , V_10 ,
V_4 -> V_11 , V_4 -> V_167 , 0 ,
V_53 , V_146 ) ;
F_77 ( V_166 < 0 ) ;
return V_10 ;
}
static int F_139 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_81 * V_81 = V_4 -> V_114 ;
struct V_43 * V_44 = NULL , * V_168 ;
struct V_169 V_170 ;
struct V_9 * V_171 ;
struct V_15 * V_21 ;
struct V_40 V_41 ;
struct V_45 * V_117 ;
struct V_172 V_173 ;
T_3 V_146 = F_140 ( V_115 [ V_174 ] ) ;
int error ;
bool log = ! V_115 [ V_175 ] ;
error = - V_73 ;
if ( ! V_115 [ V_176 ] ) {
F_141 ( log , L_1 ) ;
goto error;
}
if ( ! V_115 [ V_161 ] ) {
F_141 ( log , L_2 ) ;
goto error;
}
V_168 = F_99 () ;
if ( F_35 ( V_168 ) ) {
error = F_60 ( V_168 ) ;
goto error;
}
F_142 ( & V_173 , & V_41 , & V_170 ) ;
error = F_143 ( & V_173 , V_115 [ V_176 ] ,
V_115 [ V_177 ] , log ) ;
if ( error )
goto V_178;
F_144 ( & V_168 -> V_41 , & V_41 , & V_170 ) ;
error = F_145 ( & V_168 -> V_164 , V_115 [ V_179 ] ,
& V_41 , log ) ;
if ( error )
goto V_178;
error = F_101 ( V_115 [ V_161 ] , & V_168 -> V_41 ,
& V_117 , log ) ;
if ( error ) {
F_141 ( log , L_3 ) ;
goto V_178;
}
V_171 = F_134 ( V_117 , & V_168 -> V_164 , V_4 , false ,
V_146 ) ;
if ( F_35 ( V_171 ) ) {
error = F_60 ( V_171 ) ;
goto V_180;
}
F_6 () ;
V_21 = F_15 ( F_103 ( V_10 -> V_132 ) , V_81 -> V_17 ) ;
if ( F_45 ( ! V_21 ) ) {
error = - V_93 ;
goto V_181;
}
if ( F_115 ( & V_168 -> V_164 ) )
V_44 = F_146 ( & V_21 -> V_29 , & V_168 -> V_164 ) ;
if ( ! V_44 )
V_44 = F_147 ( & V_21 -> V_29 , & V_41 ) ;
if ( F_148 ( ! V_44 ) ) {
F_102 ( V_168 -> V_46 , V_117 ) ;
error = F_149 ( & V_21 -> V_29 , V_168 , & V_170 ) ;
if ( F_45 ( error ) ) {
V_117 = NULL ;
goto V_181;
}
if ( F_45 ( V_171 ) ) {
error = F_128 ( V_168 ,
V_81 -> V_17 ,
V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 ,
V_182 ,
V_146 ) ;
F_77 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_45 * V_183 ;
if ( F_45 ( V_4 -> V_6 -> V_7 & ( V_184
| V_185 ) ) ) {
error = - V_186 ;
goto V_181;
}
if ( F_45 ( ! F_150 ( V_44 , & V_173 ) ) ) {
if ( F_151 ( & V_44 -> V_164 ) )
V_44 = F_152 ( & V_21 -> V_29 ,
& V_173 ) ;
else
V_44 = NULL ;
if ( ! V_44 ) {
error = - V_187 ;
goto V_181;
}
}
V_183 = F_137 ( V_44 -> V_46 ) ;
F_102 ( V_44 -> V_46 , V_117 ) ;
if ( F_45 ( V_171 ) ) {
error = F_128 ( V_44 ,
V_81 -> V_17 ,
V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 ,
V_182 ,
V_146 ) ;
F_77 ( error < 0 ) ;
}
F_8 () ;
F_153 ( V_183 ) ;
F_106 ( V_168 , false ) ;
}
if ( V_171 )
F_4 ( & V_163 , V_171 , V_4 ) ;
return 0 ;
V_181:
F_8 () ;
F_48 ( V_171 ) ;
V_180:
F_29 ( V_117 ) ;
V_178:
F_106 ( V_168 , false ) ;
error:
return error ;
}
static struct V_45 * F_154 ( const struct V_87 * V_115 ,
const struct V_40 * V_41 ,
const struct V_169 * V_170 ,
bool log )
{
struct V_45 * V_117 ;
struct V_40 V_188 ;
int error ;
F_144 ( & V_188 , V_41 , V_170 ) ;
error = F_101 ( V_115 , & V_188 , & V_117 , log ) ;
if ( error ) {
F_141 ( log ,
L_4 ) ;
return F_135 ( error ) ;
}
return V_117 ;
}
static int F_155 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_81 * V_81 = V_4 -> V_114 ;
struct V_40 V_41 ;
struct V_43 * V_44 ;
struct V_169 V_170 ;
struct V_9 * V_171 = NULL ;
struct V_15 * V_21 ;
struct V_45 * V_183 = NULL , * V_117 = NULL ;
struct V_172 V_173 ;
struct V_144 V_145 ;
T_3 V_146 = F_140 ( V_115 [ V_174 ] ) ;
int error ;
bool log = ! V_115 [ V_175 ] ;
bool V_189 ;
error = - V_73 ;
if ( ! V_115 [ V_176 ] ) {
F_141 ( log , L_5 ) ;
goto error;
}
V_189 = F_156 ( & V_145 , V_115 [ V_179 ] , log ) ;
F_142 ( & V_173 , & V_41 , & V_170 ) ;
error = F_143 ( & V_173 , V_115 [ V_176 ] ,
V_115 [ V_177 ] , log ) ;
if ( error )
goto error;
if ( V_115 [ V_161 ] ) {
V_117 = F_154 ( V_115 [ V_161 ] , & V_41 , & V_170 ,
log ) ;
if ( F_35 ( V_117 ) ) {
error = F_60 ( V_117 ) ;
goto error;
}
V_171 = F_134 ( V_117 , & V_145 , V_4 , false ,
V_146 ) ;
if ( F_35 ( V_171 ) ) {
error = F_60 ( V_171 ) ;
goto V_180;
}
}
F_6 () ;
V_21 = F_15 ( F_103 ( V_10 -> V_132 ) , V_81 -> V_17 ) ;
if ( F_45 ( ! V_21 ) ) {
error = - V_93 ;
goto V_181;
}
if ( V_189 )
V_44 = F_146 ( & V_21 -> V_29 , & V_145 ) ;
else
V_44 = F_152 ( & V_21 -> V_29 , & V_173 ) ;
if ( F_45 ( ! V_44 ) ) {
error = - V_187 ;
goto V_181;
}
if ( F_148 ( V_117 ) ) {
V_183 = F_137 ( V_44 -> V_46 ) ;
F_102 ( V_44 -> V_46 , V_117 ) ;
if ( F_45 ( V_171 ) ) {
error = F_128 ( V_44 ,
V_81 -> V_17 ,
V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 ,
V_182 ,
V_146 ) ;
F_77 ( error < 0 ) ;
}
} else {
V_171 = F_136 ( V_44 , V_81 -> V_17 ,
V_4 , V_182 , false ,
V_146 ) ;
if ( F_45 ( F_35 ( V_171 ) ) ) {
error = F_60 ( V_171 ) ;
goto V_181;
}
}
if ( V_115 [ V_190 ] )
F_157 ( V_44 ) ;
F_8 () ;
if ( V_171 )
F_4 ( & V_163 , V_171 , V_4 ) ;
if ( V_183 )
F_153 ( V_183 ) ;
return 0 ;
V_181:
F_8 () ;
F_48 ( V_171 ) ;
V_180:
F_29 ( V_117 ) ;
error:
return error ;
}
static int F_158 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_81 * V_81 = V_4 -> V_114 ;
struct V_40 V_41 ;
struct V_9 * V_171 ;
struct V_43 * V_44 ;
struct V_15 * V_21 ;
struct V_172 V_173 ;
struct V_144 V_191 ;
T_3 V_146 = F_140 ( V_115 [ V_174 ] ) ;
int V_63 = 0 ;
bool log = ! V_115 [ V_175 ] ;
bool V_189 ;
V_189 = F_156 ( & V_191 , V_115 [ V_179 ] , log ) ;
if ( V_115 [ V_176 ] ) {
F_142 ( & V_173 , & V_41 , NULL ) ;
V_63 = F_143 ( & V_173 , V_115 [ V_176 ] , NULL ,
log ) ;
} else if ( ! V_189 ) {
F_141 ( log ,
L_6 ) ;
V_63 = - V_73 ;
}
if ( V_63 )
return V_63 ;
F_6 () ;
V_21 = F_15 ( F_103 ( V_10 -> V_132 ) , V_81 -> V_17 ) ;
if ( ! V_21 ) {
V_63 = - V_93 ;
goto V_192;
}
if ( V_189 )
V_44 = F_146 ( & V_21 -> V_29 , & V_191 ) ;
else
V_44 = F_152 ( & V_21 -> V_29 , & V_173 ) ;
if ( ! V_44 ) {
V_63 = - V_187 ;
goto V_192;
}
V_171 = F_136 ( V_44 , V_81 -> V_17 , V_4 ,
V_182 , true , V_146 ) ;
if ( F_35 ( V_171 ) ) {
V_63 = F_60 ( V_171 ) ;
goto V_192;
}
F_8 () ;
return F_159 ( V_171 , V_4 ) ;
V_192:
F_8 () ;
return V_63 ;
}
static int F_160 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_81 * V_81 = V_4 -> V_114 ;
struct V_40 V_41 ;
struct V_9 * V_171 ;
struct V_43 * V_44 = NULL ;
struct V_15 * V_21 ;
struct V_172 V_173 ;
struct V_144 V_191 ;
T_3 V_146 = F_140 ( V_115 [ V_174 ] ) ;
int V_63 ;
bool log = ! V_115 [ V_175 ] ;
bool V_189 ;
V_189 = F_156 ( & V_191 , V_115 [ V_179 ] , log ) ;
if ( V_115 [ V_176 ] ) {
F_142 ( & V_173 , & V_41 , NULL ) ;
V_63 = F_143 ( & V_173 , V_115 [ V_176 ] , NULL ,
log ) ;
if ( F_45 ( V_63 ) )
return V_63 ;
}
F_6 () ;
V_21 = F_15 ( F_103 ( V_10 -> V_132 ) , V_81 -> V_17 ) ;
if ( F_45 ( ! V_21 ) ) {
V_63 = - V_93 ;
goto V_192;
}
if ( F_45 ( ! V_115 [ V_176 ] && ! V_189 ) ) {
V_63 = F_161 ( & V_21 -> V_29 ) ;
goto V_192;
}
if ( V_189 )
V_44 = F_146 ( & V_21 -> V_29 , & V_191 ) ;
else
V_44 = F_152 ( & V_21 -> V_29 , & V_173 ) ;
if ( F_45 ( ! V_44 ) ) {
V_63 = - V_187 ;
goto V_192;
}
F_162 ( & V_21 -> V_29 , V_44 ) ;
F_8 () ;
V_171 = F_134 ( ( const struct V_45 V_193 * ) V_44 -> V_46 ,
& V_44 -> V_164 , V_4 , false , V_146 ) ;
if ( F_148 ( V_171 ) ) {
if ( F_148 ( ! F_35 ( V_171 ) ) ) {
F_18 () ;
V_63 = F_128 ( V_44 , V_81 -> V_17 ,
V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 ,
V_194 ,
V_146 ) ;
F_19 () ;
F_77 ( V_63 < 0 ) ;
F_4 ( & V_163 , V_171 , V_4 ) ;
} else {
F_163 ( F_103 ( V_10 -> V_132 ) -> V_90 , 0 , 0 , F_60 ( V_171 ) ) ;
}
}
F_106 ( V_44 , true ) ;
return 0 ;
V_192:
F_8 () ;
return V_63 ;
}
static int F_164 ( struct V_9 * V_10 , struct V_195 * V_196 )
{
struct V_87 * V_115 [ V_197 ] ;
struct V_81 * V_81 = F_165 ( F_166 ( V_196 -> V_198 ) ) ;
struct V_199 * V_200 ;
struct V_15 * V_21 ;
T_3 V_146 ;
int V_63 ;
V_63 = F_167 ( V_196 -> V_198 , & V_163 , V_115 ,
V_201 , V_202 ) ;
if ( V_63 )
return V_63 ;
V_146 = F_140 ( V_115 [ V_174 ] ) ;
F_18 () ;
V_21 = F_12 ( F_103 ( V_10 -> V_132 ) , V_81 -> V_17 ) ;
if ( ! V_21 ) {
F_19 () ;
return - V_93 ;
}
V_200 = F_51 ( V_21 -> V_29 . V_200 ) ;
for (; ; ) {
struct V_43 * V_44 ;
T_3 V_203 , V_204 ;
V_203 = V_196 -> args [ 0 ] ;
V_204 = V_196 -> args [ 1 ] ;
V_44 = F_168 ( V_200 , & V_203 , & V_204 ) ;
if ( ! V_44 )
break;
if ( F_128 ( V_44 , V_81 -> V_17 , V_10 ,
F_169 ( V_196 -> V_10 ) . V_55 ,
V_196 -> V_198 -> V_205 , V_206 ,
V_182 , V_146 ) < 0 )
break;
V_196 -> args [ 0 ] = V_203 ;
V_196 -> args [ 1 ] = V_204 ;
}
F_19 () ;
return V_10 -> V_91 ;
}
static T_4 F_170 ( void )
{
T_4 V_207 = F_62 ( sizeof( struct V_81 ) ) ;
V_207 += F_63 ( V_208 ) ;
V_207 += F_63 ( sizeof( struct V_135 ) ) ;
V_207 += F_63 ( sizeof( struct V_136 ) ) ;
V_207 += F_63 ( sizeof( T_3 ) ) ;
return V_207 ;
}
static int F_171 ( struct V_15 * V_21 , struct V_9 * V_10 ,
T_3 V_55 , T_3 V_162 , T_3 V_59 , V_158 V_53 )
{
struct V_81 * V_81 ;
struct V_135 V_209 ;
struct V_136 V_210 ;
int V_63 ;
V_81 = F_75 ( V_10 , V_55 , V_162 , & V_211 ,
V_59 , V_53 ) ;
if ( ! V_81 )
goto error;
V_81 -> V_17 = F_22 ( V_21 ) ;
V_63 = F_172 ( V_10 , V_212 , F_20 ( V_21 ) ) ;
if ( V_63 )
goto V_213;
F_107 ( V_21 , & V_209 , & V_210 ) ;
if ( F_123 ( V_10 , V_214 , sizeof( struct V_135 ) ,
& V_209 ) )
goto V_213;
if ( F_123 ( V_10 , V_215 ,
sizeof( struct V_136 ) ,
& V_210 ) )
goto V_213;
if ( F_173 ( V_10 , V_216 , V_21 -> V_100 ) )
goto V_213;
F_132 ( V_10 , V_81 ) ;
return 0 ;
V_213:
F_133 ( V_10 , V_81 ) ;
error:
return - V_155 ;
}
static struct V_9 * F_174 ( struct V_3 * V_4 )
{
return F_74 ( F_170 () , V_4 , V_12 ) ;
}
static struct V_15 * F_175 ( struct V_16 * V_16 ,
const struct V_81 * V_81 ,
struct V_87 * V_115 [ V_217 + 1 ] )
{
struct V_15 * V_21 ;
if ( ! V_115 [ V_212 ] )
V_21 = F_15 ( V_16 , V_81 -> V_17 ) ;
else {
struct V_20 * V_20 ;
V_20 = F_176 ( V_16 , F_79 ( V_115 [ V_212 ] ) ) ;
V_21 = V_20 && V_20 -> V_33 == V_22 ? V_20 -> V_21 : NULL ;
}
return V_21 ? V_21 : F_135 ( - V_93 ) ;
}
static void F_177 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_21 ;
V_21 = F_175 ( F_103 ( V_10 -> V_132 ) , V_4 -> V_114 , V_4 -> V_116 ) ;
if ( F_35 ( V_21 ) )
return;
F_178 ( V_21 -> V_100 , L_7 ) ;
V_21 -> V_100 = 0 ;
}
static void F_179 ( struct V_15 * V_21 , struct V_87 * V_115 [] )
{
if ( V_115 [ V_216 ] )
V_21 -> V_100 = F_180 ( V_115 [ V_216 ] ) ;
}
static int F_181 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_36 V_37 ;
struct V_9 * V_171 ;
struct V_15 * V_21 ;
struct V_20 * V_20 ;
struct V_218 * V_218 ;
int V_63 , V_138 ;
V_63 = - V_73 ;
if ( ! V_115 [ V_212 ] || ! V_115 [ V_219 ] )
goto V_63;
V_171 = F_174 ( V_4 ) ;
if ( ! V_171 )
return - V_95 ;
V_63 = - V_95 ;
V_21 = F_182 ( sizeof( * V_21 ) , V_12 ) ;
if ( V_21 == NULL )
goto V_220;
F_183 ( V_21 , F_103 ( V_10 -> V_132 ) ) ;
V_63 = F_184 ( & V_21 -> V_29 ) ;
if ( V_63 )
goto V_221;
V_21 -> V_30 = F_185 ( struct V_47 ) ;
if ( ! V_21 -> V_30 ) {
V_63 = - V_95 ;
goto V_222;
}
V_21 -> V_31 = F_186 ( V_34 * sizeof( struct V_32 ) ,
V_12 ) ;
if ( ! V_21 -> V_31 ) {
V_63 = - V_95 ;
goto V_223;
}
for ( V_138 = 0 ; V_138 < V_34 ; V_138 ++ )
F_187 ( & V_21 -> V_31 [ V_138 ] ) ;
V_37 . V_224 = F_79 ( V_115 [ V_212 ] ) ;
V_37 . type = V_225 ;
V_37 . V_226 = NULL ;
V_37 . V_21 = V_21 ;
V_37 . V_33 = V_22 ;
V_37 . V_227 = V_115 [ V_219 ] ;
F_179 ( V_21 , V_115 ) ;
F_6 () ;
V_20 = F_33 ( & V_37 ) ;
if ( F_35 ( V_20 ) ) {
V_63 = F_60 ( V_20 ) ;
if ( V_63 == - V_228 )
V_63 = - V_186 ;
if ( V_63 == - V_186 ) {
if ( V_4 -> V_229 -> V_230 < V_231 )
F_177 ( V_10 , V_4 ) ;
}
goto V_232;
}
V_63 = F_171 ( V_21 , V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 , V_233 ) ;
F_77 ( V_63 < 0 ) ;
V_218 = F_188 ( F_67 ( V_21 ) , V_234 ) ;
F_189 ( & V_21 -> V_235 , & V_218 -> V_236 ) ;
F_8 () ;
F_4 ( & V_211 , V_171 , V_4 ) ;
return 0 ;
V_232:
F_8 () ;
F_29 ( V_21 -> V_31 ) ;
V_223:
F_28 ( V_21 -> V_30 ) ;
V_222:
F_27 ( & V_21 -> V_29 ) ;
V_221:
F_29 ( V_21 ) ;
V_220:
F_48 ( V_171 ) ;
V_63:
return V_63 ;
}
static void F_190 ( struct V_15 * V_21 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_34 ; V_138 ++ ) {
struct V_20 * V_20 ;
struct V_237 * V_238 ;
F_191 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_20 -> V_33 != V_22 )
F_37 ( V_20 ) ;
}
F_192 ( & V_21 -> V_235 ) ;
F_37 ( F_193 ( V_21 , V_22 ) ) ;
F_194 ( & V_21 -> V_28 , F_25 ) ;
}
static int F_195 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_171 ;
struct V_15 * V_21 ;
int V_63 ;
V_171 = F_174 ( V_4 ) ;
if ( ! V_171 )
return - V_95 ;
F_6 () ;
V_21 = F_175 ( F_103 ( V_10 -> V_132 ) , V_4 -> V_114 , V_4 -> V_116 ) ;
V_63 = F_60 ( V_21 ) ;
if ( F_35 ( V_21 ) )
goto V_239;
V_63 = F_171 ( V_21 , V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 , V_240 ) ;
F_77 ( V_63 < 0 ) ;
F_190 ( V_21 ) ;
F_8 () ;
F_4 ( & V_211 , V_171 , V_4 ) ;
return 0 ;
V_239:
F_8 () ;
F_48 ( V_171 ) ;
return V_63 ;
}
static int F_196 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_171 ;
struct V_15 * V_21 ;
int V_63 ;
V_171 = F_174 ( V_4 ) ;
if ( ! V_171 )
return - V_95 ;
F_6 () ;
V_21 = F_175 ( F_103 ( V_10 -> V_132 ) , V_4 -> V_114 , V_4 -> V_116 ) ;
V_63 = F_60 ( V_21 ) ;
if ( F_35 ( V_21 ) )
goto V_239;
F_179 ( V_21 , V_4 -> V_116 ) ;
V_63 = F_171 ( V_21 , V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 , V_233 ) ;
F_77 ( V_63 < 0 ) ;
F_8 () ;
F_4 ( & V_211 , V_171 , V_4 ) ;
return 0 ;
V_239:
F_8 () ;
F_48 ( V_171 ) ;
return V_63 ;
}
static int F_197 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_171 ;
struct V_15 * V_21 ;
int V_63 ;
V_171 = F_174 ( V_4 ) ;
if ( ! V_171 )
return - V_95 ;
F_6 () ;
V_21 = F_175 ( F_103 ( V_10 -> V_132 ) , V_4 -> V_114 , V_4 -> V_116 ) ;
if ( F_35 ( V_21 ) ) {
V_63 = F_60 ( V_21 ) ;
goto V_239;
}
V_63 = F_171 ( V_21 , V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 , V_233 ) ;
F_77 ( V_63 < 0 ) ;
F_8 () ;
return F_159 ( V_171 , V_4 ) ;
V_239:
F_8 () ;
F_48 ( V_171 ) ;
return V_63 ;
}
static int F_198 ( struct V_9 * V_10 , struct V_195 * V_196 )
{
struct V_218 * V_218 = F_188 ( F_103 ( V_10 -> V_132 ) , V_234 ) ;
struct V_15 * V_21 ;
int V_241 = V_196 -> args [ 0 ] ;
int V_138 = 0 ;
F_6 () ;
F_199 (dp, &ovs_net->dps, list_node) {
if ( V_138 >= V_241 &&
F_171 ( V_21 , V_10 , F_169 ( V_196 -> V_10 ) . V_55 ,
V_196 -> V_198 -> V_205 , V_206 ,
V_233 ) < 0 )
break;
V_138 ++ ;
}
F_8 () ;
V_196 -> args [ 0 ] = V_138 ;
return V_10 -> V_91 ;
}
static int F_200 ( struct V_20 * V_20 , struct V_9 * V_10 ,
T_3 V_55 , T_3 V_162 , T_3 V_59 , V_158 V_53 )
{
struct V_81 * V_81 ;
struct V_242 V_243 ;
int V_63 ;
V_81 = F_75 ( V_10 , V_55 , V_162 , & V_244 ,
V_59 , V_53 ) ;
if ( ! V_81 )
return - V_155 ;
V_81 -> V_17 = F_22 ( V_20 -> V_21 ) ;
if ( F_173 ( V_10 , V_245 , V_20 -> V_33 ) ||
F_173 ( V_10 , V_246 , V_20 -> V_23 -> type ) ||
F_172 ( V_10 , V_247 ,
V_20 -> V_23 -> V_24 ( V_20 ) ) )
goto V_213;
F_201 ( V_20 , & V_243 ) ;
if ( F_123 ( V_10 , V_248 , sizeof( struct V_242 ) ,
& V_243 ) )
goto V_213;
if ( F_202 ( V_20 , V_10 ) )
goto V_213;
V_63 = F_203 ( V_20 , V_10 ) ;
if ( V_63 == - V_155 )
goto error;
F_132 ( V_10 , V_81 ) ;
return 0 ;
V_213:
V_63 = - V_155 ;
error:
F_133 ( V_10 , V_81 ) ;
return V_63 ;
}
static struct V_9 * F_204 ( void )
{
return F_205 ( V_249 , V_12 ) ;
}
struct V_9 * F_206 ( struct V_20 * V_20 , T_3 V_55 ,
T_3 V_162 , V_158 V_53 )
{
struct V_9 * V_10 ;
int V_166 ;
V_10 = F_205 ( V_249 , V_94 ) ;
if ( ! V_10 )
return F_135 ( - V_95 ) ;
V_166 = F_200 ( V_20 , V_10 , V_55 , V_162 , 0 , V_53 ) ;
F_77 ( V_166 < 0 ) ;
return V_10 ;
}
static struct V_20 * F_207 ( struct V_16 * V_16 ,
const struct V_81 * V_81 ,
struct V_87 * V_115 [ V_250 + 1 ] )
{
struct V_15 * V_21 ;
struct V_20 * V_20 ;
if ( V_115 [ V_247 ] ) {
V_20 = F_176 ( V_16 , F_79 ( V_115 [ V_247 ] ) ) ;
if ( ! V_20 )
return F_135 ( - V_93 ) ;
if ( V_81 -> V_17 &&
V_81 -> V_17 != F_22 ( V_20 -> V_21 ) )
return F_135 ( - V_93 ) ;
return V_20 ;
} else if ( V_115 [ V_245 ] ) {
T_3 V_33 = F_180 ( V_115 [ V_245 ] ) ;
if ( V_33 >= V_251 )
return F_135 ( - V_97 ) ;
V_21 = F_15 ( V_16 , V_81 -> V_17 ) ;
if ( ! V_21 )
return F_135 ( - V_93 ) ;
V_20 = F_21 ( V_21 , V_33 ) ;
if ( ! V_20 )
return F_135 ( - V_93 ) ;
return V_20 ;
} else
return F_135 ( - V_73 ) ;
}
static int F_208 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_81 * V_81 = V_4 -> V_114 ;
struct V_36 V_37 ;
struct V_9 * V_171 ;
struct V_20 * V_20 ;
struct V_15 * V_21 ;
T_3 V_33 ;
int V_63 ;
if ( ! V_115 [ V_247 ] || ! V_115 [ V_246 ] ||
! V_115 [ V_252 ] )
return - V_73 ;
V_33 = V_115 [ V_245 ]
? F_180 ( V_115 [ V_245 ] ) : 0 ;
if ( V_33 >= V_251 )
return - V_97 ;
V_171 = F_204 () ;
if ( ! V_171 )
return - V_95 ;
F_6 () ;
V_253:
V_21 = F_15 ( F_103 ( V_10 -> V_132 ) , V_81 -> V_17 ) ;
V_63 = - V_93 ;
if ( ! V_21 )
goto V_254;
if ( V_33 ) {
V_20 = F_193 ( V_21 , V_33 ) ;
V_63 = - V_228 ;
if ( V_20 )
goto V_254;
} else {
for ( V_33 = 1 ; ; V_33 ++ ) {
if ( V_33 >= V_251 ) {
V_63 = - V_97 ;
goto V_254;
}
V_20 = F_193 ( V_21 , V_33 ) ;
if ( ! V_20 )
break;
}
}
V_37 . V_224 = F_79 ( V_115 [ V_247 ] ) ;
V_37 . type = F_180 ( V_115 [ V_246 ] ) ;
V_37 . V_226 = V_115 [ V_255 ] ;
V_37 . V_21 = V_21 ;
V_37 . V_33 = V_33 ;
V_37 . V_227 = V_115 [ V_252 ] ;
V_20 = F_33 ( & V_37 ) ;
V_63 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) ) {
if ( V_63 == - V_256 )
goto V_253;
goto V_254;
}
V_63 = F_200 ( V_20 , V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 , V_257 ) ;
F_77 ( V_63 < 0 ) ;
F_8 () ;
F_4 ( & V_244 , V_171 , V_4 ) ;
return 0 ;
V_254:
F_8 () ;
F_48 ( V_171 ) ;
return V_63 ;
}
static int F_209 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_9 * V_171 ;
struct V_20 * V_20 ;
int V_63 ;
V_171 = F_204 () ;
if ( ! V_171 )
return - V_95 ;
F_6 () ;
V_20 = F_207 ( F_103 ( V_10 -> V_132 ) , V_4 -> V_114 , V_115 ) ;
V_63 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_254;
if ( V_115 [ V_246 ] &&
F_180 ( V_115 [ V_246 ] ) != V_20 -> V_23 -> type ) {
V_63 = - V_73 ;
goto V_254;
}
if ( V_115 [ V_255 ] ) {
V_63 = F_210 ( V_20 , V_115 [ V_255 ] ) ;
if ( V_63 )
goto V_254;
}
if ( V_115 [ V_252 ] ) {
struct V_87 * V_258 = V_115 [ V_252 ] ;
V_63 = F_211 ( V_20 , V_258 ) ;
if ( V_63 )
goto V_254;
}
V_63 = F_200 ( V_20 , V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 , V_257 ) ;
F_77 ( V_63 < 0 ) ;
F_8 () ;
F_4 ( & V_244 , V_171 , V_4 ) ;
return 0 ;
V_254:
F_8 () ;
F_48 ( V_171 ) ;
return V_63 ;
}
static int F_212 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_9 * V_171 ;
struct V_20 * V_20 ;
int V_63 ;
V_171 = F_204 () ;
if ( ! V_171 )
return - V_95 ;
F_6 () ;
V_20 = F_207 ( F_103 ( V_10 -> V_132 ) , V_4 -> V_114 , V_115 ) ;
V_63 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_254;
if ( V_20 -> V_33 == V_22 ) {
V_63 = - V_73 ;
goto V_254;
}
V_63 = F_200 ( V_20 , V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 , V_259 ) ;
F_77 ( V_63 < 0 ) ;
F_37 ( V_20 ) ;
F_8 () ;
F_4 ( & V_244 , V_171 , V_4 ) ;
return 0 ;
V_254:
F_8 () ;
F_48 ( V_171 ) ;
return V_63 ;
}
static int F_213 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_87 * * V_115 = V_4 -> V_116 ;
struct V_81 * V_81 = V_4 -> V_114 ;
struct V_9 * V_171 ;
struct V_20 * V_20 ;
int V_63 ;
V_171 = F_204 () ;
if ( ! V_171 )
return - V_95 ;
F_18 () ;
V_20 = F_207 ( F_103 ( V_10 -> V_132 ) , V_81 , V_115 ) ;
V_63 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_254;
V_63 = F_200 ( V_20 , V_171 , V_4 -> V_11 ,
V_4 -> V_167 , 0 , V_257 ) ;
F_77 ( V_63 < 0 ) ;
F_19 () ;
return F_159 ( V_171 , V_4 ) ;
V_254:
F_19 () ;
F_48 ( V_171 ) ;
return V_63 ;
}
static int F_214 ( struct V_9 * V_10 , struct V_195 * V_196 )
{
struct V_81 * V_81 = F_165 ( F_166 ( V_196 -> V_198 ) ) ;
struct V_15 * V_21 ;
int V_203 = V_196 -> args [ 0 ] , V_241 = V_196 -> args [ 1 ] ;
int V_138 , V_260 = 0 ;
F_18 () ;
V_21 = F_12 ( F_103 ( V_10 -> V_132 ) , V_81 -> V_17 ) ;
if ( ! V_21 ) {
F_19 () ;
return - V_93 ;
}
for ( V_138 = V_203 ; V_138 < V_34 ; V_138 ++ ) {
struct V_20 * V_20 ;
V_260 = 0 ;
F_32 (vport, &dp->ports[i], dp_hash_node) {
if ( V_260 >= V_241 &&
F_200 ( V_20 , V_10 ,
F_169 ( V_196 -> V_10 ) . V_55 ,
V_196 -> V_198 -> V_205 ,
V_206 ,
V_257 ) < 0 )
goto V_57;
V_260 ++ ;
}
V_241 = 0 ;
}
V_57:
F_19 () ;
V_196 -> args [ 0 ] = V_138 ;
V_196 -> args [ 1 ] = V_260 ;
return V_10 -> V_91 ;
}
static void F_215 ( int V_261 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_261 ; V_138 ++ )
F_216 ( V_262 [ V_138 ] ) ;
}
static int F_217 ( void )
{
int V_63 ;
int V_138 ;
for ( V_138 = 0 ; V_138 < F_218 ( V_262 ) ; V_138 ++ ) {
V_63 = F_219 ( V_262 [ V_138 ] ) ;
if ( V_63 )
goto error;
}
return 0 ;
error:
F_215 ( V_138 ) ;
return V_63 ;
}
static int T_7 F_220 ( struct V_16 * V_16 )
{
struct V_218 * V_218 = F_188 ( V_16 , V_234 ) ;
F_221 ( & V_218 -> V_236 ) ;
F_222 ( & V_218 -> V_263 , V_264 ) ;
return 0 ;
}
static void T_8 F_223 ( struct V_16 * V_16 , struct V_16 * V_265 ,
struct V_266 * V_35 )
{
struct V_218 * V_218 = F_188 ( V_16 , V_234 ) ;
struct V_15 * V_21 ;
F_199 (dp, &ovs_net->dps, list_node) {
int V_138 ;
for ( V_138 = 0 ; V_138 < V_34 ; V_138 ++ ) {
struct V_20 * V_20 ;
F_224 (vport, &dp->ports[i], dp_hash_node) {
struct V_267 * V_267 ;
if ( V_20 -> V_23 -> type != V_225 )
continue;
V_267 = F_24 ( V_20 ) ;
if ( F_225 ( V_267 -> V_19 ) == V_265 )
F_226 ( & V_20 -> V_268 , V_35 ) ;
}
}
}
}
static void T_8 F_227 ( struct V_16 * V_265 )
{
struct V_15 * V_21 , * V_269 ;
struct V_218 * V_218 = F_188 ( V_265 , V_234 ) ;
struct V_20 * V_20 , * V_270 ;
struct V_16 * V_16 ;
F_228 ( V_35 ) ;
F_6 () ;
F_229 (dp, dp_next, &ovs_net->dps, list_node)
F_190 ( V_21 ) ;
F_230 () ;
F_231 (net)
F_223 ( V_16 , V_265 , & V_35 ) ;
F_232 () ;
F_229 (vport, vport_next, &head, detach_list) {
F_233 ( & V_20 -> V_268 ) ;
F_37 ( V_20 ) ;
}
F_8 () ;
F_234 ( & V_218 -> V_263 ) ;
}
static int T_9 F_235 ( void )
{
int V_63 ;
F_236 ( sizeof( struct V_70 ) > F_237 ( struct V_9 , V_196 ) ) ;
F_238 ( L_8 ) ;
V_63 = F_239 () ;
if ( V_63 )
goto error;
V_63 = F_240 () ;
if ( V_63 )
goto V_271;
V_63 = F_241 () ;
if ( V_63 )
goto V_272;
V_63 = F_242 () ;
if ( V_63 )
goto V_273;
V_63 = F_243 ( & V_274 ) ;
if ( V_63 )
goto V_275;
V_63 = F_244 ( & V_276 ) ;
if ( V_63 )
goto V_277;
V_63 = F_245 () ;
if ( V_63 )
goto V_278;
V_63 = F_217 () ;
if ( V_63 < 0 )
goto V_279;
return 0 ;
V_279:
F_246 () ;
V_278:
F_247 ( & V_276 ) ;
V_277:
F_248 ( & V_274 ) ;
V_275:
F_249 () ;
V_273:
F_250 () ;
V_272:
F_251 () ;
V_271:
F_252 () ;
error:
return V_63 ;
}
static void F_253 ( void )
{
F_215 ( F_218 ( V_262 ) ) ;
F_246 () ;
F_247 ( & V_276 ) ;
F_248 ( & V_274 ) ;
F_254 () ;
F_249 () ;
F_250 () ;
F_251 () ;
F_252 () ;
}
