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
F_29 ( F_30 ( V_21 ) ) ;
F_31 ( V_21 -> V_31 ) ;
F_31 ( V_21 ) ;
}
static struct V_32 * F_32 ( const struct V_15 * V_21 ,
T_1 V_33 )
{
return & V_21 -> V_31 [ V_33 & ( V_34 - 1 ) ] ;
}
struct V_20 * F_33 ( const struct V_15 * V_21 , T_1 V_33 )
{
struct V_20 * V_20 ;
struct V_32 * V_35 ;
V_35 = F_32 ( V_21 , V_33 ) ;
F_34 (vport, head, dp_hash_node) {
if ( V_20 -> V_33 == V_33 )
return V_20 ;
}
return NULL ;
}
static struct V_20 * F_35 ( const struct V_36 * V_37 )
{
struct V_20 * V_20 ;
V_20 = F_36 ( V_37 ) ;
if ( ! F_37 ( V_20 ) ) {
struct V_15 * V_21 = V_37 -> V_21 ;
struct V_32 * V_35 = F_32 ( V_21 , V_20 -> V_33 ) ;
F_38 ( & V_20 -> V_38 , V_35 ) ;
}
return V_20 ;
}
void F_39 ( struct V_20 * V_39 )
{
F_40 () ;
F_41 ( & V_39 -> V_38 ) ;
F_42 ( V_39 ) ;
}
void F_43 ( struct V_9 * V_10 , struct V_40 * V_41 )
{
const struct V_20 * V_39 = F_44 ( V_10 ) -> V_42 ;
struct V_15 * V_21 = V_39 -> V_21 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_2 * V_49 ;
T_3 V_50 ;
V_48 = F_45 ( V_21 -> V_30 ) ;
V_44 = F_46 ( & V_21 -> V_29 , V_41 , & V_50 ) ;
if ( F_47 ( ! V_44 ) ) {
struct V_51 V_52 ;
int error ;
V_52 . V_53 = V_54 ;
V_52 . V_55 = NULL ;
V_52 . V_56 = F_48 ( V_39 , V_10 ) ;
V_52 . V_57 = NULL ;
error = F_49 ( V_21 , V_10 , V_41 , & V_52 ) ;
if ( F_47 ( error ) )
F_50 ( V_10 ) ;
else
F_51 ( V_10 ) ;
V_49 = & V_48 -> V_58 ;
goto V_59;
}
F_52 ( V_44 , V_41 -> V_60 . V_61 , V_10 ) ;
V_46 = F_53 ( V_44 -> V_46 ) ;
F_54 ( V_21 , V_10 , V_46 , V_41 ) ;
V_49 = & V_48 -> V_62 ;
V_59:
F_55 ( & V_48 -> V_63 ) ;
( * V_49 ) ++ ;
V_48 -> V_50 += V_50 ;
F_56 ( & V_48 -> V_63 ) ;
}
int F_49 ( struct V_15 * V_21 , struct V_9 * V_10 ,
const struct V_40 * V_41 ,
const struct V_51 * V_64 )
{
struct V_47 * V_48 ;
int V_65 ;
if ( V_64 -> V_56 == 0 ) {
V_65 = - V_66 ;
goto V_65;
}
if ( ! F_57 ( V_10 ) )
V_65 = F_58 ( V_21 , V_10 , V_41 , V_64 ) ;
else
V_65 = F_59 ( V_21 , V_10 , V_41 , V_64 ) ;
if ( V_65 )
goto V_65;
return 0 ;
V_65:
V_48 = F_45 ( V_21 -> V_30 ) ;
F_55 ( & V_48 -> V_63 ) ;
V_48 -> V_67 ++ ;
F_56 ( & V_48 -> V_63 ) ;
return V_65 ;
}
static int F_59 ( struct V_15 * V_21 , struct V_9 * V_10 ,
const struct V_40 * V_41 ,
const struct V_51 * V_64 )
{
unsigned short V_68 = F_60 ( V_10 ) -> V_68 ;
struct V_40 V_69 ;
struct V_9 * V_70 , * V_71 ;
struct V_72 V_73 ;
int V_65 ;
V_73 = * F_44 ( V_10 ) ;
V_70 = F_61 ( V_10 , V_74 , false ) ;
* F_44 ( V_10 ) = V_73 ;
if ( F_37 ( V_70 ) )
return F_62 ( V_70 ) ;
if ( V_70 == NULL )
return - V_75 ;
if ( V_68 & V_76 ) {
V_69 = * V_41 ;
V_69 . V_77 . V_78 = V_79 ;
}
V_10 = V_70 ;
do {
* F_44 ( V_10 ) = V_73 ;
if ( V_68 & V_76 && V_10 != V_70 )
V_41 = & V_69 ;
V_65 = F_58 ( V_21 , V_10 , V_41 , V_64 ) ;
if ( V_65 )
break;
} while ( ( V_10 = V_10 -> V_80 ) );
V_10 = V_70 ;
do {
V_71 = V_10 -> V_80 ;
if ( V_65 )
F_50 ( V_10 ) ;
else
F_51 ( V_10 ) ;
} while ( ( V_10 = V_71 ) );
return V_65 ;
}
static T_4 F_63 ( const struct V_51 * V_64 ,
unsigned int V_81 )
{
T_4 V_82 = F_64 ( sizeof( struct V_83 ) )
+ F_65 ( V_81 )
+ F_65 ( F_66 () ) ;
if ( V_64 -> V_55 )
V_82 += F_67 ( V_64 -> V_55 -> V_84 ) ;
if ( V_64 -> V_57 )
V_82 += F_65 ( F_68 () ) ;
return V_82 ;
}
static int F_58 ( struct V_15 * V_21 , struct V_9 * V_10 ,
const struct V_40 * V_41 ,
const struct V_51 * V_64 )
{
struct V_83 * V_52 ;
struct V_9 * V_71 = NULL ;
struct V_9 * V_85 = NULL ;
struct V_86 * V_87 ;
struct V_3 V_4 = {
. V_88 = F_30 ( V_21 ) -> V_89 ,
. V_11 = V_64 -> V_56 ,
} ;
T_4 V_90 ;
unsigned int V_91 ;
int V_65 , V_17 ;
V_17 = F_22 ( V_21 ) ;
if ( ! V_17 )
return - V_92 ;
if ( F_69 ( V_10 ) ) {
V_71 = F_70 ( V_10 , V_93 ) ;
if ( ! V_71 )
return - V_94 ;
V_71 = F_71 ( V_71 ) ;
if ( ! V_71 )
return - V_94 ;
V_10 = V_71 ;
}
if ( F_72 ( V_10 -> V_90 ) > V_95 ) {
V_65 = - V_96 ;
goto V_59;
}
if ( V_10 -> V_97 == V_98 &&
( V_65 = F_73 ( V_10 ) ) )
goto V_59;
if ( V_21 -> V_99 & V_100 )
V_91 = F_74 ( V_10 ) ;
else
V_91 = V_10 -> V_90 ;
V_90 = F_63 ( V_64 , V_91 ) ;
V_85 = F_75 ( V_90 , & V_4 , V_93 ) ;
if ( ! V_85 ) {
V_65 = - V_94 ;
goto V_59;
}
V_52 = F_76 ( V_85 , 0 , 0 , & V_101 ,
0 , V_64 -> V_53 ) ;
V_52 -> V_17 = V_17 ;
V_65 = F_77 ( V_41 , V_41 , V_102 , false , V_85 ) ;
F_78 ( V_65 ) ;
if ( V_64 -> V_55 )
F_79 ( V_85 , V_103 ,
V_84 ( V_64 -> V_55 ) ,
F_80 ( V_64 -> V_55 ) ) ;
if ( V_64 -> V_57 ) {
V_87 = F_81 ( V_85 , V_104 ) ;
V_65 = F_82 ( V_85 ,
V_64 -> V_57 ) ;
F_78 ( V_65 ) ;
F_83 ( V_85 , V_87 ) ;
}
if ( ! ( V_87 = F_84 ( V_85 , V_105 , 0 ) ) ) {
V_65 = - V_106 ;
goto V_59;
}
V_87 -> V_84 = F_72 ( V_10 -> V_90 ) ;
V_65 = F_85 ( V_85 , V_10 , V_10 -> V_90 , V_91 ) ;
if ( V_65 )
goto V_59;
if ( ! ( V_21 -> V_99 & V_100 ) ) {
T_4 V_107 = F_67 ( V_85 -> V_90 ) - V_85 -> V_90 ;
if ( V_107 > 0 )
memset ( F_86 ( V_85 , V_107 ) , 0 , V_107 ) ;
}
( (struct V_108 * ) V_85 -> V_109 ) -> V_110 = V_85 -> V_90 ;
V_65 = F_87 ( F_30 ( V_21 ) , V_85 , V_64 -> V_56 ) ;
V_85 = NULL ;
V_59:
if ( V_65 )
F_88 ( V_10 ) ;
F_50 ( V_85 ) ;
F_50 ( V_71 ) ;
return V_65 ;
}
static int F_89 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_83 * V_83 = V_4 -> V_111 ;
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_45 * V_114 ;
struct V_9 * V_115 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_15 * V_21 ;
struct V_116 * V_117 ;
struct V_20 * V_42 ;
int V_90 ;
int V_65 ;
bool log = ! V_112 [ V_118 ] ;
V_65 = - V_75 ;
if ( ! V_112 [ V_105 ] || ! V_112 [ V_102 ] ||
! V_112 [ V_119 ] )
goto V_65;
V_90 = V_84 ( V_112 [ V_105 ] ) ;
V_115 = F_90 ( V_120 + V_90 , V_12 ) ;
V_65 = - V_94 ;
if ( ! V_115 )
goto V_65;
F_91 ( V_115 , V_120 ) ;
F_92 ( F_93 ( V_115 , V_90 ) , V_112 [ V_105 ] , V_90 ) ;
F_94 ( V_115 ) ;
V_117 = F_95 ( V_115 ) ;
if ( F_96 ( V_117 -> V_121 ) >= V_122 )
V_115 -> V_123 = V_117 -> V_121 ;
else
V_115 -> V_123 = F_97 ( V_124 ) ;
V_44 = F_98 () ;
V_65 = F_62 ( V_44 ) ;
if ( F_37 ( V_44 ) )
goto V_125;
V_65 = F_99 ( V_112 [ V_102 ] , V_115 ,
& V_44 -> V_41 , log ) ;
if ( V_65 )
goto V_126;
V_65 = F_100 ( V_112 [ V_119 ] ,
& V_44 -> V_41 , & V_114 , log ) ;
if ( V_65 )
goto V_126;
F_101 ( V_44 -> V_46 , V_114 ) ;
F_44 ( V_115 ) -> V_57 = NULL ;
V_115 -> V_127 = V_44 -> V_41 . V_128 . V_127 ;
V_115 -> V_129 = V_44 -> V_41 . V_128 . V_130 ;
F_18 () ;
V_21 = F_12 ( F_102 ( V_10 -> V_131 ) , V_83 -> V_17 ) ;
V_65 = - V_92 ;
if ( ! V_21 )
goto V_132;
V_42 = F_23 ( V_21 , V_44 -> V_41 . V_128 . V_133 ) ;
if ( ! V_42 )
V_42 = F_23 ( V_21 , V_22 ) ;
if ( ! V_42 )
goto V_132;
F_44 ( V_115 ) -> V_42 = V_42 ;
V_46 = F_53 ( V_44 -> V_46 ) ;
F_103 () ;
V_65 = F_54 ( V_21 , V_115 , V_46 , & V_44 -> V_41 ) ;
F_104 () ;
F_19 () ;
F_105 ( V_44 , false ) ;
return V_65 ;
V_132:
F_19 () ;
V_126:
F_105 ( V_44 , false ) ;
V_125:
F_50 ( V_115 ) ;
V_65:
return V_65 ;
}
static void F_106 ( const struct V_15 * V_21 , struct V_134 * V_48 ,
struct V_135 * V_136 )
{
int V_137 ;
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
V_48 -> V_138 = F_107 ( & V_21 -> V_29 ) ;
V_136 -> V_139 = F_108 ( & V_21 -> V_29 ) ;
V_48 -> V_62 = V_48 -> V_58 = V_48 -> V_67 = 0 ;
F_109 (i) {
const struct V_47 * V_140 ;
struct V_47 V_141 ;
unsigned int V_142 ;
V_140 = F_110 ( V_21 -> V_30 , V_137 ) ;
do {
V_142 = F_111 ( & V_140 -> V_63 ) ;
V_141 = * V_140 ;
} while ( F_112 ( & V_140 -> V_63 , V_142 ) );
V_48 -> V_62 += V_141 . V_62 ;
V_48 -> V_58 += V_141 . V_58 ;
V_48 -> V_67 += V_141 . V_67 ;
V_136 -> V_50 += V_141 . V_50 ;
}
}
static bool F_113 ( const struct V_143 * V_144 , T_5 V_145 )
{
return F_114 ( V_144 ) &&
! ( V_145 & V_146 ) ;
}
static bool F_115 ( T_5 V_145 )
{
return ! ( V_145 & V_147 ) ;
}
static bool F_116 ( T_5 V_145 )
{
return ! ( V_145 & V_148 ) ;
}
static T_4 F_117 ( const struct V_45 * V_114 ,
const struct V_143 * V_144 ,
T_5 V_145 )
{
T_4 V_90 = F_64 ( sizeof( struct V_83 ) ) ;
if ( V_144 && F_114 ( V_144 ) )
V_90 += F_65 ( V_144 -> V_149 ) ;
if ( ! V_144 || F_113 ( V_144 , V_145 ) )
V_90 += F_65 ( F_66 () ) ;
if ( F_115 ( V_145 ) )
V_90 += F_65 ( F_66 () ) ;
if ( F_116 ( V_145 ) )
V_90 += F_65 ( V_114 -> V_150 ) ;
return V_90
+ F_65 ( sizeof( struct V_151 ) )
+ F_65 ( 1 )
+ F_65 ( 8 ) ;
}
static int F_118 ( const struct V_43 * V_44 ,
struct V_9 * V_10 )
{
struct V_151 V_48 ;
T_6 V_152 ;
unsigned long V_153 ;
F_119 ( V_44 , & V_48 , & V_153 , & V_152 ) ;
if ( V_153 &&
F_120 ( V_10 , V_154 , F_121 ( V_153 ) ) )
return - V_155 ;
if ( V_48 . V_156 &&
F_122 ( V_10 , V_157 , sizeof( struct V_151 ) , & V_48 ) )
return - V_155 ;
if ( ( V_158 ) F_96 ( V_152 ) &&
F_123 ( V_10 , V_159 , ( V_158 ) F_96 ( V_152 ) ) )
return - V_155 ;
return 0 ;
}
static int F_124 ( const struct V_43 * V_44 ,
struct V_9 * V_10 , int V_160 )
{
struct V_86 * V_142 ;
int V_65 ;
V_142 = F_81 ( V_10 , V_161 ) ;
if ( V_142 ) {
const struct V_45 * V_46 ;
V_46 = F_125 ( V_44 -> V_46 ) ;
V_65 = F_126 ( V_46 -> V_162 ,
V_46 -> V_150 , V_10 ) ;
if ( ! V_65 )
F_83 ( V_10 , V_142 ) ;
else {
if ( V_160 )
return V_65 ;
F_127 ( V_10 , V_142 ) ;
}
} else if ( V_160 ) {
return - V_155 ;
}
return 0 ;
}
static int F_128 ( const struct V_43 * V_44 , int V_17 ,
struct V_9 * V_10 , T_3 V_56 ,
T_3 V_163 , T_3 V_61 , V_158 V_53 , T_3 V_145 )
{
const int V_160 = V_10 -> V_90 ;
struct V_83 * V_83 ;
int V_65 ;
V_83 = F_76 ( V_10 , V_56 , V_163 , & V_164 ,
V_61 , V_53 ) ;
if ( ! V_83 )
return - V_155 ;
V_83 -> V_17 = V_17 ;
V_65 = F_129 ( V_44 , V_10 ) ;
if ( V_65 )
goto error;
if ( F_113 ( & V_44 -> V_165 , V_145 ) ) {
V_65 = F_130 ( V_44 , V_10 ) ;
if ( V_65 )
goto error;
}
if ( F_115 ( V_145 ) ) {
V_65 = F_131 ( V_44 , V_10 ) ;
if ( V_65 )
goto error;
}
V_65 = F_118 ( V_44 , V_10 ) ;
if ( V_65 )
goto error;
if ( F_116 ( V_145 ) ) {
V_65 = F_124 ( V_44 , V_10 , V_160 ) ;
if ( V_65 )
goto error;
}
F_132 ( V_10 , V_83 ) ;
return 0 ;
error:
F_133 ( V_10 , V_83 ) ;
return V_65 ;
}
static struct V_9 * F_134 ( const struct V_45 * V_114 ,
const struct V_143 * V_144 ,
struct V_3 * V_4 ,
bool V_166 ,
T_5 V_145 )
{
struct V_9 * V_10 ;
T_4 V_90 ;
if ( ! V_166 && ! F_1 ( & V_164 , V_4 , 0 ) )
return NULL ;
V_90 = F_117 ( V_114 , V_144 , V_145 ) ;
V_10 = F_75 ( V_90 , V_4 , V_12 ) ;
if ( ! V_10 )
return F_135 ( - V_94 ) ;
return V_10 ;
}
static struct V_9 * F_136 ( const struct V_43 * V_44 ,
int V_17 ,
struct V_3 * V_4 , V_158 V_53 ,
bool V_166 , T_3 V_145 )
{
struct V_9 * V_10 ;
int V_167 ;
V_10 = F_134 ( F_137 ( V_44 -> V_46 ) ,
& V_44 -> V_165 , V_4 , V_166 , V_145 ) ;
if ( F_138 ( V_10 ) )
return V_10 ;
V_167 = F_128 ( V_44 , V_17 , V_10 ,
V_4 -> V_11 , V_4 -> V_168 , 0 ,
V_53 , V_145 ) ;
F_78 ( V_167 < 0 ) ;
return V_10 ;
}
static int F_139 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_83 * V_83 = V_4 -> V_111 ;
struct V_43 * V_44 = NULL , * V_169 ;
struct V_170 V_171 ;
struct V_9 * V_172 ;
struct V_15 * V_21 ;
struct V_40 V_41 ;
struct V_45 * V_114 ;
struct V_173 V_174 ;
T_3 V_145 = F_140 ( V_112 [ V_175 ] ) ;
int error ;
bool log = ! V_112 [ V_176 ] ;
error = - V_75 ;
if ( ! V_112 [ V_177 ] ) {
F_141 ( log , L_1 ) ;
goto error;
}
if ( ! V_112 [ V_161 ] ) {
F_141 ( log , L_2 ) ;
goto error;
}
V_169 = F_98 () ;
if ( F_37 ( V_169 ) ) {
error = F_62 ( V_169 ) ;
goto error;
}
F_142 ( & V_174 , & V_41 , & V_171 ) ;
error = F_143 ( & V_174 , V_112 [ V_177 ] ,
V_112 [ V_178 ] , log ) ;
if ( error )
goto V_179;
F_144 ( & V_169 -> V_41 , & V_41 , & V_171 ) ;
error = F_145 ( & V_169 -> V_165 , V_112 [ V_180 ] ,
& V_41 , log ) ;
if ( error )
goto V_179;
error = F_100 ( V_112 [ V_161 ] , & V_169 -> V_41 ,
& V_114 , log ) ;
if ( error ) {
F_141 ( log , L_3 ) ;
goto V_179;
}
V_172 = F_134 ( V_114 , & V_169 -> V_165 , V_4 , false ,
V_145 ) ;
if ( F_37 ( V_172 ) ) {
error = F_62 ( V_172 ) ;
goto V_181;
}
F_6 () ;
V_21 = F_15 ( F_102 ( V_10 -> V_131 ) , V_83 -> V_17 ) ;
if ( F_47 ( ! V_21 ) ) {
error = - V_92 ;
goto V_182;
}
if ( F_114 ( & V_169 -> V_165 ) )
V_44 = F_146 ( & V_21 -> V_29 , & V_169 -> V_165 ) ;
if ( ! V_44 )
V_44 = F_147 ( & V_21 -> V_29 , & V_41 ) ;
if ( F_148 ( ! V_44 ) ) {
F_101 ( V_169 -> V_46 , V_114 ) ;
error = F_149 ( & V_21 -> V_29 , V_169 , & V_171 ) ;
if ( F_47 ( error ) ) {
V_114 = NULL ;
goto V_182;
}
if ( F_47 ( V_172 ) ) {
error = F_128 ( V_169 ,
V_83 -> V_17 ,
V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 ,
V_183 ,
V_145 ) ;
F_78 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_45 * V_184 ;
if ( F_47 ( V_4 -> V_6 -> V_7 & ( V_185
| V_186 ) ) ) {
error = - V_187 ;
goto V_182;
}
if ( F_47 ( ! F_150 ( V_44 , & V_174 ) ) ) {
if ( F_151 ( & V_44 -> V_165 ) )
V_44 = F_152 ( & V_21 -> V_29 ,
& V_174 ) ;
else
V_44 = NULL ;
if ( ! V_44 ) {
error = - V_188 ;
goto V_182;
}
}
V_184 = F_137 ( V_44 -> V_46 ) ;
F_101 ( V_44 -> V_46 , V_114 ) ;
if ( F_47 ( V_172 ) ) {
error = F_128 ( V_44 ,
V_83 -> V_17 ,
V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 ,
V_183 ,
V_145 ) ;
F_78 ( error < 0 ) ;
}
F_8 () ;
F_153 ( V_184 ) ;
F_105 ( V_169 , false ) ;
}
if ( V_172 )
F_4 ( & V_164 , V_172 , V_4 ) ;
return 0 ;
V_182:
F_8 () ;
F_50 ( V_172 ) ;
V_181:
F_31 ( V_114 ) ;
V_179:
F_105 ( V_169 , false ) ;
error:
return error ;
}
static struct V_45 * F_154 ( const struct V_86 * V_112 ,
const struct V_40 * V_41 ,
const struct V_170 * V_171 ,
bool log )
{
struct V_45 * V_114 ;
struct V_40 V_189 ;
int error ;
F_144 ( & V_189 , V_41 , V_171 ) ;
error = F_100 ( V_112 , & V_189 , & V_114 , log ) ;
if ( error ) {
F_141 ( log ,
L_4 ) ;
return F_135 ( error ) ;
}
return V_114 ;
}
static int F_155 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_83 * V_83 = V_4 -> V_111 ;
struct V_40 V_41 ;
struct V_43 * V_44 ;
struct V_170 V_171 ;
struct V_9 * V_172 = NULL ;
struct V_15 * V_21 ;
struct V_45 * V_184 = NULL , * V_114 = NULL ;
struct V_173 V_174 ;
struct V_143 V_144 ;
T_3 V_145 = F_140 ( V_112 [ V_175 ] ) ;
int error ;
bool log = ! V_112 [ V_176 ] ;
bool V_190 ;
error = - V_75 ;
if ( ! V_112 [ V_177 ] ) {
F_141 ( log , L_5 ) ;
goto error;
}
V_190 = F_156 ( & V_144 , V_112 [ V_180 ] , log ) ;
F_142 ( & V_174 , & V_41 , & V_171 ) ;
error = F_143 ( & V_174 , V_112 [ V_177 ] ,
V_112 [ V_178 ] , log ) ;
if ( error )
goto error;
if ( V_112 [ V_161 ] ) {
V_114 = F_154 ( V_112 [ V_161 ] , & V_41 , & V_171 ,
log ) ;
if ( F_37 ( V_114 ) ) {
error = F_62 ( V_114 ) ;
goto error;
}
V_172 = F_134 ( V_114 , & V_144 , V_4 , false ,
V_145 ) ;
if ( F_37 ( V_172 ) ) {
error = F_62 ( V_172 ) ;
goto V_181;
}
}
F_6 () ;
V_21 = F_15 ( F_102 ( V_10 -> V_131 ) , V_83 -> V_17 ) ;
if ( F_47 ( ! V_21 ) ) {
error = - V_92 ;
goto V_182;
}
if ( V_190 )
V_44 = F_146 ( & V_21 -> V_29 , & V_144 ) ;
else
V_44 = F_152 ( & V_21 -> V_29 , & V_174 ) ;
if ( F_47 ( ! V_44 ) ) {
error = - V_188 ;
goto V_182;
}
if ( F_148 ( V_114 ) ) {
V_184 = F_137 ( V_44 -> V_46 ) ;
F_101 ( V_44 -> V_46 , V_114 ) ;
if ( F_47 ( V_172 ) ) {
error = F_128 ( V_44 ,
V_83 -> V_17 ,
V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 ,
V_183 ,
V_145 ) ;
F_78 ( error < 0 ) ;
}
} else {
V_172 = F_136 ( V_44 , V_83 -> V_17 ,
V_4 , V_183 , false ,
V_145 ) ;
if ( F_47 ( F_37 ( V_172 ) ) ) {
error = F_62 ( V_172 ) ;
goto V_182;
}
}
if ( V_112 [ V_191 ] )
F_157 ( V_44 ) ;
F_8 () ;
if ( V_172 )
F_4 ( & V_164 , V_172 , V_4 ) ;
if ( V_184 )
F_153 ( V_184 ) ;
return 0 ;
V_182:
F_8 () ;
F_50 ( V_172 ) ;
V_181:
F_31 ( V_114 ) ;
error:
return error ;
}
static int F_158 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_83 * V_83 = V_4 -> V_111 ;
struct V_40 V_41 ;
struct V_9 * V_172 ;
struct V_43 * V_44 ;
struct V_15 * V_21 ;
struct V_173 V_174 ;
struct V_143 V_192 ;
T_3 V_145 = F_140 ( V_112 [ V_175 ] ) ;
int V_65 = 0 ;
bool log = ! V_112 [ V_176 ] ;
bool V_190 ;
V_190 = F_156 ( & V_192 , V_112 [ V_180 ] , log ) ;
if ( V_112 [ V_177 ] ) {
F_142 ( & V_174 , & V_41 , NULL ) ;
V_65 = F_143 ( & V_174 , V_112 [ V_177 ] , NULL ,
log ) ;
} else if ( ! V_190 ) {
F_141 ( log ,
L_6 ) ;
V_65 = - V_75 ;
}
if ( V_65 )
return V_65 ;
F_6 () ;
V_21 = F_15 ( F_102 ( V_10 -> V_131 ) , V_83 -> V_17 ) ;
if ( ! V_21 ) {
V_65 = - V_92 ;
goto V_193;
}
if ( V_190 )
V_44 = F_146 ( & V_21 -> V_29 , & V_192 ) ;
else
V_44 = F_152 ( & V_21 -> V_29 , & V_174 ) ;
if ( ! V_44 ) {
V_65 = - V_188 ;
goto V_193;
}
V_172 = F_136 ( V_44 , V_83 -> V_17 , V_4 ,
V_183 , true , V_145 ) ;
if ( F_37 ( V_172 ) ) {
V_65 = F_62 ( V_172 ) ;
goto V_193;
}
F_8 () ;
return F_159 ( V_172 , V_4 ) ;
V_193:
F_8 () ;
return V_65 ;
}
static int F_160 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_83 * V_83 = V_4 -> V_111 ;
struct V_40 V_41 ;
struct V_9 * V_172 ;
struct V_43 * V_44 = NULL ;
struct V_15 * V_21 ;
struct V_173 V_174 ;
struct V_143 V_192 ;
T_3 V_145 = F_140 ( V_112 [ V_175 ] ) ;
int V_65 ;
bool log = ! V_112 [ V_176 ] ;
bool V_190 ;
V_190 = F_156 ( & V_192 , V_112 [ V_180 ] , log ) ;
if ( V_112 [ V_177 ] ) {
F_142 ( & V_174 , & V_41 , NULL ) ;
V_65 = F_143 ( & V_174 , V_112 [ V_177 ] , NULL ,
log ) ;
if ( F_47 ( V_65 ) )
return V_65 ;
}
F_6 () ;
V_21 = F_15 ( F_102 ( V_10 -> V_131 ) , V_83 -> V_17 ) ;
if ( F_47 ( ! V_21 ) ) {
V_65 = - V_92 ;
goto V_193;
}
if ( F_47 ( ! V_112 [ V_177 ] && ! V_190 ) ) {
V_65 = F_161 ( & V_21 -> V_29 ) ;
goto V_193;
}
if ( V_190 )
V_44 = F_146 ( & V_21 -> V_29 , & V_192 ) ;
else
V_44 = F_152 ( & V_21 -> V_29 , & V_174 ) ;
if ( F_47 ( ! V_44 ) ) {
V_65 = - V_188 ;
goto V_193;
}
F_162 ( & V_21 -> V_29 , V_44 ) ;
F_8 () ;
V_172 = F_134 ( ( const struct V_45 V_194 * ) V_44 -> V_46 ,
& V_44 -> V_165 , V_4 , false , V_145 ) ;
if ( F_148 ( V_172 ) ) {
if ( F_148 ( ! F_37 ( V_172 ) ) ) {
F_18 () ;
V_65 = F_128 ( V_44 , V_83 -> V_17 ,
V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 ,
V_195 ,
V_145 ) ;
F_19 () ;
F_78 ( V_65 < 0 ) ;
F_4 ( & V_164 , V_172 , V_4 ) ;
} else {
F_163 ( F_102 ( V_10 -> V_131 ) -> V_89 , 0 , 0 , F_62 ( V_172 ) ) ;
}
}
F_105 ( V_44 , true ) ;
return 0 ;
V_193:
F_8 () ;
return V_65 ;
}
static int F_164 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_86 * V_112 [ V_198 ] ;
struct V_83 * V_83 = F_165 ( F_166 ( V_197 -> V_199 ) ) ;
struct V_200 * V_201 ;
struct V_15 * V_21 ;
T_3 V_145 ;
int V_65 ;
V_65 = F_167 ( V_197 -> V_199 , & V_164 , V_112 ,
V_202 , V_203 ) ;
if ( V_65 )
return V_65 ;
V_145 = F_140 ( V_112 [ V_175 ] ) ;
F_18 () ;
V_21 = F_12 ( F_102 ( V_10 -> V_131 ) , V_83 -> V_17 ) ;
if ( ! V_21 ) {
F_19 () ;
return - V_92 ;
}
V_201 = F_53 ( V_21 -> V_29 . V_201 ) ;
for (; ; ) {
struct V_43 * V_44 ;
T_3 V_204 , V_205 ;
V_204 = V_197 -> args [ 0 ] ;
V_205 = V_197 -> args [ 1 ] ;
V_44 = F_168 ( V_201 , & V_204 , & V_205 ) ;
if ( ! V_44 )
break;
if ( F_128 ( V_44 , V_83 -> V_17 , V_10 ,
F_169 ( V_197 -> V_10 ) . V_56 ,
V_197 -> V_199 -> V_206 , V_207 ,
V_183 , V_145 ) < 0 )
break;
V_197 -> args [ 0 ] = V_204 ;
V_197 -> args [ 1 ] = V_205 ;
}
F_19 () ;
return V_10 -> V_90 ;
}
static T_4 F_170 ( void )
{
T_4 V_208 = F_64 ( sizeof( struct V_83 ) ) ;
V_208 += F_65 ( V_209 ) ;
V_208 += F_65 ( sizeof( struct V_134 ) ) ;
V_208 += F_65 ( sizeof( struct V_135 ) ) ;
V_208 += F_65 ( sizeof( T_3 ) ) ;
return V_208 ;
}
static int F_171 ( struct V_15 * V_21 , struct V_9 * V_10 ,
T_3 V_56 , T_3 V_163 , T_3 V_61 , V_158 V_53 )
{
struct V_83 * V_83 ;
struct V_134 V_210 ;
struct V_135 V_211 ;
int V_65 ;
V_83 = F_76 ( V_10 , V_56 , V_163 , & V_212 ,
V_61 , V_53 ) ;
if ( ! V_83 )
goto error;
V_83 -> V_17 = F_22 ( V_21 ) ;
V_65 = F_172 ( V_10 , V_213 , F_20 ( V_21 ) ) ;
if ( V_65 )
goto V_214;
F_106 ( V_21 , & V_210 , & V_211 ) ;
if ( F_122 ( V_10 , V_215 , sizeof( struct V_134 ) ,
& V_210 ) )
goto V_214;
if ( F_122 ( V_10 , V_216 ,
sizeof( struct V_135 ) ,
& V_211 ) )
goto V_214;
if ( F_173 ( V_10 , V_217 , V_21 -> V_99 ) )
goto V_214;
F_132 ( V_10 , V_83 ) ;
return 0 ;
V_214:
F_133 ( V_10 , V_83 ) ;
error:
return - V_155 ;
}
static struct V_9 * F_174 ( struct V_3 * V_4 )
{
return F_75 ( F_170 () , V_4 , V_12 ) ;
}
static struct V_15 * F_175 ( struct V_16 * V_16 ,
const struct V_83 * V_83 ,
struct V_86 * V_112 [ V_218 + 1 ] )
{
struct V_15 * V_21 ;
if ( ! V_112 [ V_213 ] )
V_21 = F_15 ( V_16 , V_83 -> V_17 ) ;
else {
struct V_20 * V_20 ;
V_20 = F_176 ( V_16 , F_80 ( V_112 [ V_213 ] ) ) ;
V_21 = V_20 && V_20 -> V_33 == V_22 ? V_20 -> V_21 : NULL ;
}
return V_21 ? V_21 : F_135 ( - V_92 ) ;
}
static void F_177 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_21 ;
V_21 = F_175 ( F_102 ( V_10 -> V_131 ) , V_4 -> V_111 , V_4 -> V_113 ) ;
if ( F_37 ( V_21 ) )
return;
F_178 ( V_21 -> V_99 , L_7 ) ;
V_21 -> V_99 = 0 ;
}
static void F_179 ( struct V_15 * V_21 , struct V_86 * V_112 [] )
{
if ( V_112 [ V_217 ] )
V_21 -> V_99 = F_180 ( V_112 [ V_217 ] ) ;
}
static int F_181 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_36 V_37 ;
struct V_9 * V_172 ;
struct V_15 * V_21 ;
struct V_20 * V_20 ;
struct V_219 * V_219 ;
int V_65 , V_137 ;
V_65 = - V_75 ;
if ( ! V_112 [ V_213 ] || ! V_112 [ V_220 ] )
goto V_65;
V_172 = F_174 ( V_4 ) ;
if ( ! V_172 )
return - V_94 ;
V_65 = - V_94 ;
V_21 = F_182 ( sizeof( * V_21 ) , V_12 ) ;
if ( V_21 == NULL )
goto V_221;
F_183 ( V_21 , F_184 ( F_102 ( V_10 -> V_131 ) ) ) ;
V_65 = F_185 ( & V_21 -> V_29 ) ;
if ( V_65 )
goto V_222;
V_21 -> V_30 = F_186 ( struct V_47 ) ;
if ( ! V_21 -> V_30 ) {
V_65 = - V_94 ;
goto V_223;
}
V_21 -> V_31 = F_187 ( V_34 * sizeof( struct V_32 ) ,
V_12 ) ;
if ( ! V_21 -> V_31 ) {
V_65 = - V_94 ;
goto V_224;
}
for ( V_137 = 0 ; V_137 < V_34 ; V_137 ++ )
F_188 ( & V_21 -> V_31 [ V_137 ] ) ;
V_37 . V_225 = F_80 ( V_112 [ V_213 ] ) ;
V_37 . type = V_226 ;
V_37 . V_227 = NULL ;
V_37 . V_21 = V_21 ;
V_37 . V_33 = V_22 ;
V_37 . V_228 = V_112 [ V_220 ] ;
F_179 ( V_21 , V_112 ) ;
F_6 () ;
V_20 = F_35 ( & V_37 ) ;
if ( F_37 ( V_20 ) ) {
V_65 = F_62 ( V_20 ) ;
if ( V_65 == - V_229 )
V_65 = - V_187 ;
if ( V_65 == - V_187 ) {
if ( V_4 -> V_230 -> V_231 < V_232 )
F_177 ( V_10 , V_4 ) ;
}
goto V_233;
}
V_65 = F_171 ( V_21 , V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 , V_234 ) ;
F_78 ( V_65 < 0 ) ;
V_219 = F_189 ( F_30 ( V_21 ) , V_235 ) ;
F_190 ( & V_21 -> V_236 , & V_219 -> V_237 ) ;
F_8 () ;
F_4 ( & V_212 , V_172 , V_4 ) ;
return 0 ;
V_233:
F_8 () ;
F_31 ( V_21 -> V_31 ) ;
V_224:
F_28 ( V_21 -> V_30 ) ;
V_223:
F_27 ( & V_21 -> V_29 ) ;
V_222:
F_29 ( F_30 ( V_21 ) ) ;
F_31 ( V_21 ) ;
V_221:
F_50 ( V_172 ) ;
V_65:
return V_65 ;
}
static void F_191 ( struct V_15 * V_21 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_34 ; V_137 ++ ) {
struct V_20 * V_20 ;
struct V_238 * V_239 ;
F_192 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_20 -> V_33 != V_22 )
F_39 ( V_20 ) ;
}
F_193 ( & V_21 -> V_236 ) ;
F_39 ( F_194 ( V_21 , V_22 ) ) ;
F_195 ( & V_21 -> V_28 , F_25 ) ;
}
static int F_196 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_172 ;
struct V_15 * V_21 ;
int V_65 ;
V_172 = F_174 ( V_4 ) ;
if ( ! V_172 )
return - V_94 ;
F_6 () ;
V_21 = F_175 ( F_102 ( V_10 -> V_131 ) , V_4 -> V_111 , V_4 -> V_113 ) ;
V_65 = F_62 ( V_21 ) ;
if ( F_37 ( V_21 ) )
goto V_240;
V_65 = F_171 ( V_21 , V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 , V_241 ) ;
F_78 ( V_65 < 0 ) ;
F_191 ( V_21 ) ;
F_8 () ;
F_4 ( & V_212 , V_172 , V_4 ) ;
return 0 ;
V_240:
F_8 () ;
F_50 ( V_172 ) ;
return V_65 ;
}
static int F_197 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_172 ;
struct V_15 * V_21 ;
int V_65 ;
V_172 = F_174 ( V_4 ) ;
if ( ! V_172 )
return - V_94 ;
F_6 () ;
V_21 = F_175 ( F_102 ( V_10 -> V_131 ) , V_4 -> V_111 , V_4 -> V_113 ) ;
V_65 = F_62 ( V_21 ) ;
if ( F_37 ( V_21 ) )
goto V_240;
F_179 ( V_21 , V_4 -> V_113 ) ;
V_65 = F_171 ( V_21 , V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 , V_234 ) ;
F_78 ( V_65 < 0 ) ;
F_8 () ;
F_4 ( & V_212 , V_172 , V_4 ) ;
return 0 ;
V_240:
F_8 () ;
F_50 ( V_172 ) ;
return V_65 ;
}
static int F_198 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_172 ;
struct V_15 * V_21 ;
int V_65 ;
V_172 = F_174 ( V_4 ) ;
if ( ! V_172 )
return - V_94 ;
F_6 () ;
V_21 = F_175 ( F_102 ( V_10 -> V_131 ) , V_4 -> V_111 , V_4 -> V_113 ) ;
if ( F_37 ( V_21 ) ) {
V_65 = F_62 ( V_21 ) ;
goto V_240;
}
V_65 = F_171 ( V_21 , V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 , V_234 ) ;
F_78 ( V_65 < 0 ) ;
F_8 () ;
return F_159 ( V_172 , V_4 ) ;
V_240:
F_8 () ;
F_50 ( V_172 ) ;
return V_65 ;
}
static int F_199 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_219 * V_219 = F_189 ( F_102 ( V_10 -> V_131 ) , V_235 ) ;
struct V_15 * V_21 ;
int V_242 = V_197 -> args [ 0 ] ;
int V_137 = 0 ;
F_6 () ;
F_200 (dp, &ovs_net->dps, list_node) {
if ( V_137 >= V_242 &&
F_171 ( V_21 , V_10 , F_169 ( V_197 -> V_10 ) . V_56 ,
V_197 -> V_199 -> V_206 , V_207 ,
V_234 ) < 0 )
break;
V_137 ++ ;
}
F_8 () ;
V_197 -> args [ 0 ] = V_137 ;
return V_10 -> V_90 ;
}
static int F_201 ( struct V_20 * V_20 , struct V_9 * V_10 ,
T_3 V_56 , T_3 V_163 , T_3 V_61 , V_158 V_53 )
{
struct V_83 * V_83 ;
struct V_243 V_244 ;
int V_65 ;
V_83 = F_76 ( V_10 , V_56 , V_163 , & V_245 ,
V_61 , V_53 ) ;
if ( ! V_83 )
return - V_155 ;
V_83 -> V_17 = F_22 ( V_20 -> V_21 ) ;
if ( F_173 ( V_10 , V_246 , V_20 -> V_33 ) ||
F_173 ( V_10 , V_247 , V_20 -> V_23 -> type ) ||
F_172 ( V_10 , V_248 ,
V_20 -> V_23 -> V_24 ( V_20 ) ) )
goto V_214;
F_202 ( V_20 , & V_244 ) ;
if ( F_122 ( V_10 , V_249 , sizeof( struct V_243 ) ,
& V_244 ) )
goto V_214;
if ( F_203 ( V_20 , V_10 ) )
goto V_214;
V_65 = F_204 ( V_20 , V_10 ) ;
if ( V_65 == - V_155 )
goto error;
F_132 ( V_10 , V_83 ) ;
return 0 ;
V_214:
V_65 = - V_155 ;
error:
F_133 ( V_10 , V_83 ) ;
return V_65 ;
}
static struct V_9 * F_205 ( void )
{
return F_206 ( V_250 , V_12 ) ;
}
struct V_9 * F_207 ( struct V_20 * V_20 , T_3 V_56 ,
T_3 V_163 , V_158 V_53 )
{
struct V_9 * V_10 ;
int V_167 ;
V_10 = F_206 ( V_250 , V_93 ) ;
if ( ! V_10 )
return F_135 ( - V_94 ) ;
V_167 = F_201 ( V_20 , V_10 , V_56 , V_163 , 0 , V_53 ) ;
F_78 ( V_167 < 0 ) ;
return V_10 ;
}
static struct V_20 * F_208 ( struct V_16 * V_16 ,
const struct V_83 * V_83 ,
struct V_86 * V_112 [ V_251 + 1 ] )
{
struct V_15 * V_21 ;
struct V_20 * V_20 ;
if ( V_112 [ V_248 ] ) {
V_20 = F_176 ( V_16 , F_80 ( V_112 [ V_248 ] ) ) ;
if ( ! V_20 )
return F_135 ( - V_92 ) ;
if ( V_83 -> V_17 &&
V_83 -> V_17 != F_22 ( V_20 -> V_21 ) )
return F_135 ( - V_92 ) ;
return V_20 ;
} else if ( V_112 [ V_246 ] ) {
T_3 V_33 = F_180 ( V_112 [ V_246 ] ) ;
if ( V_33 >= V_252 )
return F_135 ( - V_96 ) ;
V_21 = F_15 ( V_16 , V_83 -> V_17 ) ;
if ( ! V_21 )
return F_135 ( - V_92 ) ;
V_20 = F_21 ( V_21 , V_33 ) ;
if ( ! V_20 )
return F_135 ( - V_92 ) ;
return V_20 ;
} else
return F_135 ( - V_75 ) ;
}
static int F_209 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_83 * V_83 = V_4 -> V_111 ;
struct V_36 V_37 ;
struct V_9 * V_172 ;
struct V_20 * V_20 ;
struct V_15 * V_21 ;
T_3 V_33 ;
int V_65 ;
if ( ! V_112 [ V_248 ] || ! V_112 [ V_247 ] ||
! V_112 [ V_253 ] )
return - V_75 ;
V_33 = V_112 [ V_246 ]
? F_180 ( V_112 [ V_246 ] ) : 0 ;
if ( V_33 >= V_252 )
return - V_96 ;
V_172 = F_205 () ;
if ( ! V_172 )
return - V_94 ;
F_6 () ;
V_254:
V_21 = F_15 ( F_102 ( V_10 -> V_131 ) , V_83 -> V_17 ) ;
V_65 = - V_92 ;
if ( ! V_21 )
goto V_255;
if ( V_33 ) {
V_20 = F_194 ( V_21 , V_33 ) ;
V_65 = - V_229 ;
if ( V_20 )
goto V_255;
} else {
for ( V_33 = 1 ; ; V_33 ++ ) {
if ( V_33 >= V_252 ) {
V_65 = - V_96 ;
goto V_255;
}
V_20 = F_194 ( V_21 , V_33 ) ;
if ( ! V_20 )
break;
}
}
V_37 . V_225 = F_80 ( V_112 [ V_248 ] ) ;
V_37 . type = F_180 ( V_112 [ V_247 ] ) ;
V_37 . V_227 = V_112 [ V_256 ] ;
V_37 . V_21 = V_21 ;
V_37 . V_33 = V_33 ;
V_37 . V_228 = V_112 [ V_253 ] ;
V_20 = F_35 ( & V_37 ) ;
V_65 = F_62 ( V_20 ) ;
if ( F_37 ( V_20 ) ) {
if ( V_65 == - V_257 )
goto V_254;
goto V_255;
}
V_65 = F_201 ( V_20 , V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 , V_258 ) ;
F_78 ( V_65 < 0 ) ;
F_8 () ;
F_4 ( & V_245 , V_172 , V_4 ) ;
return 0 ;
V_255:
F_8 () ;
F_50 ( V_172 ) ;
return V_65 ;
}
static int F_210 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_9 * V_172 ;
struct V_20 * V_20 ;
int V_65 ;
V_172 = F_205 () ;
if ( ! V_172 )
return - V_94 ;
F_6 () ;
V_20 = F_208 ( F_102 ( V_10 -> V_131 ) , V_4 -> V_111 , V_112 ) ;
V_65 = F_62 ( V_20 ) ;
if ( F_37 ( V_20 ) )
goto V_255;
if ( V_112 [ V_247 ] &&
F_180 ( V_112 [ V_247 ] ) != V_20 -> V_23 -> type ) {
V_65 = - V_75 ;
goto V_255;
}
if ( V_112 [ V_256 ] ) {
V_65 = F_211 ( V_20 , V_112 [ V_256 ] ) ;
if ( V_65 )
goto V_255;
}
if ( V_112 [ V_253 ] ) {
struct V_86 * V_259 = V_112 [ V_253 ] ;
V_65 = F_212 ( V_20 , V_259 ) ;
if ( V_65 )
goto V_255;
}
V_65 = F_201 ( V_20 , V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 , V_258 ) ;
F_78 ( V_65 < 0 ) ;
F_8 () ;
F_4 ( & V_245 , V_172 , V_4 ) ;
return 0 ;
V_255:
F_8 () ;
F_50 ( V_172 ) ;
return V_65 ;
}
static int F_213 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_9 * V_172 ;
struct V_20 * V_20 ;
int V_65 ;
V_172 = F_205 () ;
if ( ! V_172 )
return - V_94 ;
F_6 () ;
V_20 = F_208 ( F_102 ( V_10 -> V_131 ) , V_4 -> V_111 , V_112 ) ;
V_65 = F_62 ( V_20 ) ;
if ( F_37 ( V_20 ) )
goto V_255;
if ( V_20 -> V_33 == V_22 ) {
V_65 = - V_75 ;
goto V_255;
}
V_65 = F_201 ( V_20 , V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 , V_260 ) ;
F_78 ( V_65 < 0 ) ;
F_39 ( V_20 ) ;
F_8 () ;
F_4 ( & V_245 , V_172 , V_4 ) ;
return 0 ;
V_255:
F_8 () ;
F_50 ( V_172 ) ;
return V_65 ;
}
static int F_214 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_86 * * V_112 = V_4 -> V_113 ;
struct V_83 * V_83 = V_4 -> V_111 ;
struct V_9 * V_172 ;
struct V_20 * V_20 ;
int V_65 ;
V_172 = F_205 () ;
if ( ! V_172 )
return - V_94 ;
F_18 () ;
V_20 = F_208 ( F_102 ( V_10 -> V_131 ) , V_83 , V_112 ) ;
V_65 = F_62 ( V_20 ) ;
if ( F_37 ( V_20 ) )
goto V_255;
V_65 = F_201 ( V_20 , V_172 , V_4 -> V_11 ,
V_4 -> V_168 , 0 , V_258 ) ;
F_78 ( V_65 < 0 ) ;
F_19 () ;
return F_159 ( V_172 , V_4 ) ;
V_255:
F_19 () ;
F_50 ( V_172 ) ;
return V_65 ;
}
static int F_215 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_83 * V_83 = F_165 ( F_166 ( V_197 -> V_199 ) ) ;
struct V_15 * V_21 ;
int V_204 = V_197 -> args [ 0 ] , V_242 = V_197 -> args [ 1 ] ;
int V_137 , V_261 = 0 ;
F_18 () ;
V_21 = F_12 ( F_102 ( V_10 -> V_131 ) , V_83 -> V_17 ) ;
if ( ! V_21 ) {
F_19 () ;
return - V_92 ;
}
for ( V_137 = V_204 ; V_137 < V_34 ; V_137 ++ ) {
struct V_20 * V_20 ;
V_261 = 0 ;
F_34 (vport, &dp->ports[i], dp_hash_node) {
if ( V_261 >= V_242 &&
F_201 ( V_20 , V_10 ,
F_169 ( V_197 -> V_10 ) . V_56 ,
V_197 -> V_199 -> V_206 ,
V_207 ,
V_258 ) < 0 )
goto V_59;
V_261 ++ ;
}
V_242 = 0 ;
}
V_59:
F_19 () ;
V_197 -> args [ 0 ] = V_137 ;
V_197 -> args [ 1 ] = V_261 ;
return V_10 -> V_90 ;
}
static void F_216 ( int V_262 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_262 ; V_137 ++ )
F_217 ( V_263 [ V_137 ] ) ;
}
static int F_218 ( void )
{
int V_65 ;
int V_137 ;
for ( V_137 = 0 ; V_137 < F_219 ( V_263 ) ; V_137 ++ ) {
V_65 = F_220 ( V_263 [ V_137 ] ) ;
if ( V_65 )
goto error;
}
return 0 ;
error:
F_216 ( V_137 ) ;
return V_65 ;
}
static int T_7 F_221 ( struct V_16 * V_16 )
{
struct V_219 * V_219 = F_189 ( V_16 , V_235 ) ;
F_222 ( & V_219 -> V_237 ) ;
F_223 ( & V_219 -> V_264 , V_265 ) ;
return 0 ;
}
static void T_8 F_224 ( struct V_16 * V_16 , struct V_16 * V_266 ,
struct V_267 * V_35 )
{
struct V_219 * V_219 = F_189 ( V_16 , V_235 ) ;
struct V_15 * V_21 ;
F_200 (dp, &ovs_net->dps, list_node) {
int V_137 ;
for ( V_137 = 0 ; V_137 < V_34 ; V_137 ++ ) {
struct V_20 * V_20 ;
F_225 (vport, &dp->ports[i], dp_hash_node) {
struct V_268 * V_268 ;
if ( V_20 -> V_23 -> type != V_226 )
continue;
V_268 = F_24 ( V_20 ) ;
if ( F_226 ( V_268 -> V_19 ) == V_266 )
F_227 ( & V_20 -> V_269 , V_35 ) ;
}
}
}
}
static void T_8 F_228 ( struct V_16 * V_266 )
{
struct V_15 * V_21 , * V_270 ;
struct V_219 * V_219 = F_189 ( V_266 , V_235 ) ;
struct V_20 * V_20 , * V_271 ;
struct V_16 * V_16 ;
F_229 ( V_35 ) ;
F_6 () ;
F_230 (dp, dp_next, &ovs_net->dps, list_node)
F_191 ( V_21 ) ;
F_231 () ;
F_232 (net)
F_224 ( V_16 , V_266 , & V_35 ) ;
F_233 () ;
F_230 (vport, vport_next, &head, detach_list) {
F_234 ( & V_20 -> V_269 ) ;
F_39 ( V_20 ) ;
}
F_8 () ;
F_235 ( & V_219 -> V_264 ) ;
}
static int T_9 F_236 ( void )
{
int V_65 ;
F_237 ( sizeof( struct V_72 ) > F_238 ( struct V_9 , V_197 ) ) ;
F_239 ( L_8 ) ;
V_65 = F_240 () ;
if ( V_65 )
goto error;
V_65 = F_241 () ;
if ( V_65 )
goto V_272;
V_65 = F_242 () ;
if ( V_65 )
goto V_273;
V_65 = F_243 () ;
if ( V_65 )
goto V_274;
V_65 = F_244 ( & V_275 ) ;
if ( V_65 )
goto V_276;
V_65 = F_245 ( & V_277 ) ;
if ( V_65 )
goto V_278;
V_65 = F_246 () ;
if ( V_65 )
goto V_279;
V_65 = F_218 () ;
if ( V_65 < 0 )
goto V_280;
return 0 ;
V_280:
F_247 () ;
V_279:
F_248 ( & V_277 ) ;
V_278:
F_249 ( & V_275 ) ;
V_276:
F_250 () ;
V_274:
F_251 () ;
V_273:
F_252 () ;
V_272:
F_253 () ;
error:
return V_65 ;
}
static void F_254 ( void )
{
F_216 ( F_219 ( V_263 ) ) ;
F_247 () ;
F_248 ( & V_277 ) ;
F_249 ( & V_275 ) ;
F_255 () ;
F_250 () ;
F_251 () ;
F_252 () ;
F_253 () ;
}
