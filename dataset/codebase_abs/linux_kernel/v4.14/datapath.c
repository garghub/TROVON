static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 )
{
return V_4 -> V_6 -> V_7 & V_8 ||
F_2 ( V_2 , F_3 ( V_4 ) , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_3 * V_4 )
{
F_5 ( V_2 , V_10 , V_4 , 0 , V_11 ) ;
}
void F_6 ( void )
{
F_7 ( & V_12 ) ;
}
void F_8 ( void )
{
F_9 ( & V_12 ) ;
}
int F_10 ( void )
{
if ( V_13 )
return F_11 ( & V_12 ) ;
else
return 1 ;
}
static struct V_14 * F_12 ( struct V_15 * V_15 , int V_16 )
{
struct V_17 * V_18 = F_13 ( V_15 , V_16 ) ;
if ( V_18 ) {
struct V_19 * V_19 = F_14 ( V_18 ) ;
if ( V_19 )
return V_19 -> V_20 ;
}
return NULL ;
}
static inline struct V_14 * F_15 ( struct V_15 * V_15 , int V_16 )
{
struct V_14 * V_20 ;
F_16 ( ! F_17 () && ! F_10 () ) ;
F_18 () ;
V_20 = F_12 ( V_15 , V_16 ) ;
F_19 () ;
return V_20 ;
}
const char * F_20 ( const struct V_14 * V_20 )
{
struct V_19 * V_19 = F_21 ( V_20 , V_21 ) ;
return F_22 ( V_19 ) ;
}
static int F_23 ( const struct V_14 * V_20 )
{
struct V_19 * V_22 ;
int V_23 ;
F_18 () ;
V_22 = F_24 ( V_20 , V_21 ) ;
if ( V_22 )
V_23 = V_22 -> V_18 -> V_23 ;
else
V_23 = 0 ;
F_19 () ;
return V_23 ;
}
static void F_25 ( struct V_24 * V_25 )
{
struct V_14 * V_20 = F_26 ( V_25 , struct V_14 , V_25 ) ;
F_27 ( & V_20 -> V_26 ) ;
F_28 ( V_20 -> V_27 ) ;
F_29 ( V_20 -> V_28 ) ;
F_29 ( V_20 ) ;
}
static struct V_29 * F_30 ( const struct V_14 * V_20 ,
T_1 V_30 )
{
return & V_20 -> V_28 [ V_30 & ( V_31 - 1 ) ] ;
}
struct V_19 * F_31 ( const struct V_14 * V_20 , T_1 V_30 )
{
struct V_19 * V_19 ;
struct V_29 * V_32 ;
V_32 = F_30 ( V_20 , V_30 ) ;
F_32 (vport, head, dp_hash_node) {
if ( V_19 -> V_30 == V_30 )
return V_19 ;
}
return NULL ;
}
static struct V_19 * F_33 ( const struct V_33 * V_34 )
{
struct V_19 * V_19 ;
V_19 = F_34 ( V_34 ) ;
if ( ! F_35 ( V_19 ) ) {
struct V_14 * V_20 = V_34 -> V_20 ;
struct V_29 * V_32 = F_30 ( V_20 , V_19 -> V_30 ) ;
F_36 ( & V_19 -> V_35 , V_32 ) ;
}
return V_19 ;
}
void F_37 ( struct V_19 * V_36 )
{
F_38 () ;
F_39 ( & V_36 -> V_35 ) ;
F_40 ( V_36 ) ;
}
void F_41 ( struct V_9 * V_10 , struct V_37 * V_38 )
{
const struct V_19 * V_36 = F_42 ( V_10 ) -> V_39 ;
struct V_14 * V_20 = V_36 -> V_20 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
T_2 * V_46 ;
T_3 V_47 ;
V_45 = F_43 ( V_20 -> V_27 ) ;
V_41 = F_44 ( & V_20 -> V_26 , V_38 , & V_47 ) ;
if ( F_45 ( ! V_41 ) ) {
struct V_48 V_49 ;
int error ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_50 = V_51 ;
V_49 . V_52 = F_46 ( V_36 , V_10 ) ;
V_49 . V_53 = F_42 ( V_10 ) -> V_53 ;
error = F_47 ( V_20 , V_10 , V_38 , & V_49 , 0 ) ;
if ( F_45 ( error ) )
F_48 ( V_10 ) ;
else
F_49 ( V_10 ) ;
V_46 = & V_45 -> V_54 ;
goto V_55;
}
F_50 ( V_41 , V_38 -> V_56 . V_57 , V_10 ) ;
V_43 = F_51 ( V_41 -> V_43 ) ;
F_52 ( V_20 , V_10 , V_43 , V_38 ) ;
V_46 = & V_45 -> V_58 ;
V_55:
F_53 ( & V_45 -> V_59 ) ;
( * V_46 ) ++ ;
V_45 -> V_47 += V_47 ;
F_54 ( & V_45 -> V_59 ) ;
}
int F_47 ( struct V_14 * V_20 , struct V_9 * V_10 ,
const struct V_37 * V_38 ,
const struct V_48 * V_60 ,
T_4 V_61 )
{
struct V_44 * V_45 ;
int V_62 ;
if ( V_60 -> V_52 == 0 ) {
V_62 = - V_63 ;
goto V_62;
}
if ( ! F_55 ( V_10 ) )
V_62 = F_56 ( V_20 , V_10 , V_38 , V_60 , V_61 ) ;
else
V_62 = F_57 ( V_20 , V_10 , V_38 , V_60 , V_61 ) ;
if ( V_62 )
goto V_62;
return 0 ;
V_62:
V_45 = F_43 ( V_20 -> V_27 ) ;
F_53 ( & V_45 -> V_59 ) ;
V_45 -> V_64 ++ ;
F_54 ( & V_45 -> V_59 ) ;
return V_62 ;
}
static int F_57 ( struct V_14 * V_20 , struct V_9 * V_10 ,
const struct V_37 * V_38 ,
const struct V_48 * V_60 ,
T_4 V_61 )
{
struct V_9 * V_65 , * V_66 ;
int V_62 ;
F_58 ( sizeof( * F_42 ( V_10 ) ) > V_67 ) ;
V_65 = F_59 ( V_10 , V_68 , false ) ;
if ( F_35 ( V_65 ) )
return F_60 ( V_65 ) ;
if ( V_65 == NULL )
return - V_69 ;
V_10 = V_65 ;
do {
V_62 = F_56 ( V_20 , V_10 , V_38 , V_60 , V_61 ) ;
if ( V_62 )
break;
} while ( ( V_10 = V_10 -> V_70 ) );
V_10 = V_65 ;
do {
V_66 = V_10 -> V_70 ;
if ( V_62 )
F_48 ( V_10 ) ;
else
F_49 ( V_10 ) ;
} while ( ( V_10 = V_66 ) );
return V_62 ;
}
static T_5 F_61 ( const struct V_48 * V_60 ,
unsigned int V_71 , int V_72 )
{
T_5 V_73 = F_62 ( sizeof( struct V_74 ) )
+ F_63 ( V_71 )
+ F_63 ( F_64 () )
+ F_63 ( sizeof( unsigned int ) ) ;
if ( V_60 -> V_75 )
V_73 += F_65 ( V_60 -> V_75 -> V_76 ) ;
if ( V_60 -> V_77 )
V_73 += F_63 ( F_66 () ) ;
if ( V_60 -> V_78 )
V_73 += F_63 ( V_72 ) ;
if ( V_60 -> V_53 )
V_73 += F_63 ( sizeof( V_60 -> V_53 ) ) ;
return V_73 ;
}
static void F_67 ( struct V_14 * V_20 , struct V_9 * V_10 )
{
if ( ! ( V_20 -> V_79 & V_80 ) ) {
T_5 V_81 = F_65 ( V_10 -> V_82 ) - V_10 -> V_82 ;
if ( V_81 > 0 )
F_68 ( V_10 , V_81 ) ;
}
}
static int F_56 ( struct V_14 * V_20 , struct V_9 * V_10 ,
const struct V_37 * V_38 ,
const struct V_48 * V_60 ,
T_4 V_61 )
{
struct V_74 * V_49 ;
struct V_9 * V_66 = NULL ;
struct V_9 * V_83 = NULL ;
struct V_84 * V_85 ;
T_5 V_82 ;
unsigned int V_86 ;
int V_62 , V_16 ;
V_16 = F_23 ( V_20 ) ;
if ( ! V_16 )
return - V_87 ;
if ( F_69 ( V_10 ) ) {
V_66 = F_70 ( V_10 , V_88 ) ;
if ( ! V_66 )
return - V_89 ;
V_66 = F_71 ( V_66 ) ;
if ( ! V_66 )
return - V_89 ;
V_10 = V_66 ;
}
if ( F_72 ( V_10 -> V_82 ) > V_90 ) {
V_62 = - V_91 ;
goto V_55;
}
if ( V_10 -> V_92 == V_93 &&
( V_62 = F_73 ( V_10 , 0 ) ) )
goto V_55;
if ( V_20 -> V_79 & V_80 )
V_86 = F_74 ( V_10 ) ;
else
V_86 = V_10 -> V_82 ;
V_82 = F_61 ( V_60 , V_86 - V_61 ,
F_42 ( V_10 ) -> V_94 ) ;
V_83 = F_75 ( V_82 , V_88 ) ;
if ( ! V_83 ) {
V_62 = - V_89 ;
goto V_55;
}
V_49 = F_76 ( V_83 , 0 , 0 , & V_95 ,
0 , V_60 -> V_50 ) ;
V_49 -> V_16 = V_16 ;
V_62 = F_77 ( V_38 , V_38 , V_96 , false , V_83 ) ;
F_78 ( V_62 ) ;
if ( V_60 -> V_75 )
F_79 ( V_83 , V_97 ,
V_76 ( V_60 -> V_75 ) ,
F_80 ( V_60 -> V_75 ) ) ;
if ( V_60 -> V_77 ) {
V_85 = F_81 ( V_83 , V_98 ) ;
V_62 = F_82 ( V_83 ,
V_60 -> V_77 ) ;
F_78 ( V_62 ) ;
F_83 ( V_83 , V_85 ) ;
}
if ( V_60 -> V_78 ) {
V_85 = F_81 ( V_83 , V_99 ) ;
V_62 = F_84 ( V_60 -> V_100 ,
V_60 -> V_78 ,
V_83 ) ;
if ( ! V_62 )
F_83 ( V_83 , V_85 ) ;
else
F_85 ( V_83 , V_85 ) ;
}
if ( V_60 -> V_53 ) {
if ( F_86 ( V_83 , V_101 ,
V_60 -> V_53 ) ) {
V_62 = - V_102 ;
goto V_55;
}
F_67 ( V_20 , V_83 ) ;
}
if ( V_61 > 0 ) {
if ( F_87 ( V_83 , V_103 ,
V_10 -> V_82 ) ) {
V_62 = - V_102 ;
goto V_55;
}
F_67 ( V_20 , V_83 ) ;
}
if ( ! ( V_85 = F_88 ( V_83 , V_104 , 0 ) ) ) {
V_62 = - V_102 ;
goto V_55;
}
V_85 -> V_76 = F_72 ( V_10 -> V_82 - V_61 ) ;
V_62 = F_89 ( V_83 , V_10 , V_10 -> V_82 - V_61 , V_86 ) ;
if ( V_62 )
goto V_55;
F_67 ( V_20 , V_83 ) ;
( (struct V_105 * ) V_83 -> V_106 ) -> V_107 = V_83 -> V_82 ;
V_62 = F_90 ( F_91 ( V_20 ) , V_83 , V_60 -> V_52 ) ;
V_83 = NULL ;
V_55:
if ( V_62 )
F_92 ( V_10 ) ;
F_48 ( V_83 ) ;
F_48 ( V_66 ) ;
return V_62 ;
}
static int F_93 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_74 * V_74 = V_4 -> V_108 ;
struct V_15 * V_15 = F_94 ( V_10 -> V_109 ) ;
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_42 * V_112 ;
struct V_9 * V_113 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_14 * V_20 ;
struct V_19 * V_39 ;
T_1 V_53 = 0 ;
int V_82 ;
int V_62 ;
bool log = ! V_110 [ V_114 ] ;
V_62 = - V_69 ;
if ( ! V_110 [ V_104 ] || ! V_110 [ V_96 ] ||
! V_110 [ V_99 ] )
goto V_62;
V_82 = V_76 ( V_110 [ V_104 ] ) ;
V_113 = F_95 ( V_115 + V_82 , V_11 ) ;
V_62 = - V_89 ;
if ( ! V_113 )
goto V_62;
F_96 ( V_113 , V_115 ) ;
F_97 ( F_98 ( V_113 , V_82 ) , V_110 [ V_104 ] , V_82 ) ;
if ( V_110 [ V_101 ] ) {
V_53 = F_99 ( V_110 [ V_101 ] ) ;
V_113 -> V_116 = 1 ;
}
F_42 ( V_113 ) -> V_53 = V_53 ;
V_41 = F_100 () ;
V_62 = F_60 ( V_41 ) ;
if ( F_35 ( V_41 ) )
goto V_117;
V_62 = F_101 ( V_15 , V_110 [ V_96 ] ,
V_113 , & V_41 -> V_38 , log ) ;
if ( V_62 )
goto V_118;
V_62 = F_102 ( V_15 , V_110 [ V_99 ] ,
& V_41 -> V_38 , & V_112 , log ) ;
if ( V_62 )
goto V_118;
F_103 ( V_41 -> V_43 , V_112 ) ;
V_113 -> V_119 = V_41 -> V_38 . V_120 . V_119 ;
V_113 -> V_121 = V_41 -> V_38 . V_120 . V_122 ;
F_18 () ;
V_20 = F_12 ( V_15 , V_74 -> V_16 ) ;
V_62 = - V_87 ;
if ( ! V_20 )
goto V_123;
V_39 = F_24 ( V_20 , V_41 -> V_38 . V_120 . V_124 ) ;
if ( ! V_39 )
V_39 = F_24 ( V_20 , V_21 ) ;
if ( ! V_39 )
goto V_123;
V_113 -> V_18 = V_39 -> V_18 ;
F_42 ( V_113 ) -> V_39 = V_39 ;
V_43 = F_51 ( V_41 -> V_43 ) ;
F_104 () ;
V_62 = F_52 ( V_20 , V_113 , V_43 , & V_41 -> V_38 ) ;
F_105 () ;
F_19 () ;
F_106 ( V_41 , false ) ;
return V_62 ;
V_123:
F_19 () ;
V_118:
F_106 ( V_41 , false ) ;
V_117:
F_48 ( V_113 ) ;
V_62:
return V_62 ;
}
static void F_107 ( const struct V_14 * V_20 , struct V_125 * V_45 ,
struct V_126 * V_127 )
{
int V_128 ;
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
V_45 -> V_129 = F_108 ( & V_20 -> V_26 ) ;
V_127 -> V_130 = F_109 ( & V_20 -> V_26 ) ;
V_45 -> V_58 = V_45 -> V_54 = V_45 -> V_64 = 0 ;
F_110 (i) {
const struct V_44 * V_131 ;
struct V_44 V_132 ;
unsigned int V_133 ;
V_131 = F_111 ( V_20 -> V_27 , V_128 ) ;
do {
V_133 = F_112 ( & V_131 -> V_59 ) ;
V_132 = * V_131 ;
} while ( F_113 ( & V_131 -> V_59 , V_133 ) );
V_45 -> V_58 += V_132 . V_58 ;
V_45 -> V_54 += V_132 . V_54 ;
V_45 -> V_64 += V_132 . V_64 ;
V_127 -> V_47 += V_132 . V_47 ;
}
}
static bool F_114 ( const struct V_134 * V_135 , T_4 V_136 )
{
return F_115 ( V_135 ) &&
! ( V_136 & V_137 ) ;
}
static bool F_116 ( T_4 V_136 )
{
return ! ( V_136 & V_138 ) ;
}
static bool F_117 ( T_4 V_136 )
{
return ! ( V_136 & V_139 ) ;
}
static T_5 F_118 ( const struct V_42 * V_112 ,
const struct V_134 * V_135 ,
T_4 V_136 )
{
T_5 V_82 = F_62 ( sizeof( struct V_74 ) ) ;
if ( V_135 && F_115 ( V_135 ) )
V_82 += F_63 ( V_135 -> V_140 ) ;
if ( ! V_135 || F_114 ( V_135 , V_136 ) )
V_82 += F_63 ( F_64 () ) ;
if ( F_116 ( V_136 ) )
V_82 += F_63 ( F_64 () ) ;
if ( F_117 ( V_136 ) )
V_82 += F_63 ( V_112 -> V_141 ) ;
return V_82
+ F_119 ( sizeof( struct V_142 ) )
+ F_63 ( 1 )
+ F_119 ( 8 ) ;
}
static int F_120 ( const struct V_40 * V_41 ,
struct V_9 * V_10 )
{
struct V_142 V_45 ;
T_6 V_143 ;
unsigned long V_144 ;
F_121 ( V_41 , & V_45 , & V_144 , & V_143 ) ;
if ( V_144 &&
F_122 ( V_10 , V_145 , F_123 ( V_144 ) ,
V_146 ) )
return - V_147 ;
if ( V_45 . V_148 &&
F_124 ( V_10 , V_149 ,
sizeof( struct V_142 ) , & V_45 ,
V_146 ) )
return - V_147 ;
if ( ( V_150 ) F_125 ( V_143 ) &&
F_126 ( V_10 , V_151 , ( V_150 ) F_125 ( V_143 ) ) )
return - V_147 ;
return 0 ;
}
static int F_127 ( const struct V_40 * V_41 ,
struct V_9 * V_10 , int V_152 )
{
struct V_84 * V_133 ;
int V_62 ;
V_133 = F_81 ( V_10 , V_153 ) ;
if ( V_133 ) {
const struct V_42 * V_43 ;
V_43 = F_128 ( V_41 -> V_43 ) ;
V_62 = F_84 ( V_43 -> V_100 ,
V_43 -> V_78 , V_10 ) ;
if ( ! V_62 )
F_83 ( V_10 , V_133 ) ;
else {
if ( V_152 )
return V_62 ;
F_85 ( V_10 , V_133 ) ;
}
} else if ( V_152 ) {
return - V_147 ;
}
return 0 ;
}
static int F_129 ( const struct V_40 * V_41 , int V_16 ,
struct V_9 * V_10 , T_3 V_52 ,
T_3 V_154 , T_3 V_57 , V_150 V_50 , T_3 V_136 )
{
const int V_152 = V_10 -> V_82 ;
struct V_74 * V_74 ;
int V_62 ;
V_74 = F_76 ( V_10 , V_52 , V_154 , & V_155 ,
V_57 , V_50 ) ;
if ( ! V_74 )
return - V_147 ;
V_74 -> V_16 = V_16 ;
V_62 = F_130 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_114 ( & V_41 -> V_156 , V_136 ) ) {
V_62 = F_131 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
}
if ( F_116 ( V_136 ) ) {
V_62 = F_132 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
}
V_62 = F_120 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_117 ( V_136 ) ) {
V_62 = F_127 ( V_41 , V_10 , V_152 ) ;
if ( V_62 )
goto error;
}
F_133 ( V_10 , V_74 ) ;
return 0 ;
error:
F_134 ( V_10 , V_74 ) ;
return V_62 ;
}
static struct V_9 * F_135 ( const struct V_42 * V_112 ,
const struct V_134 * V_135 ,
struct V_3 * V_4 ,
bool V_157 ,
T_4 V_136 )
{
struct V_9 * V_10 ;
T_5 V_82 ;
if ( ! V_157 && ! F_1 ( & V_155 , V_4 , 0 ) )
return NULL ;
V_82 = F_118 ( V_112 , V_135 , V_136 ) ;
V_10 = F_75 ( V_82 , V_11 ) ;
if ( ! V_10 )
return F_136 ( - V_89 ) ;
return V_10 ;
}
static struct V_9 * F_137 ( const struct V_40 * V_41 ,
int V_16 ,
struct V_3 * V_4 , V_150 V_50 ,
bool V_157 , T_3 V_136 )
{
struct V_9 * V_10 ;
int V_158 ;
V_10 = F_135 ( F_138 ( V_41 -> V_43 ) ,
& V_41 -> V_156 , V_4 , V_157 , V_136 ) ;
if ( F_139 ( V_10 ) )
return V_10 ;
V_158 = F_129 ( V_41 , V_16 , V_10 ,
V_4 -> V_159 , V_4 -> V_160 , 0 ,
V_50 , V_136 ) ;
F_78 ( V_158 < 0 ) ;
return V_10 ;
}
static int F_140 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_94 ( V_10 -> V_109 ) ;
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_74 * V_74 = V_4 -> V_108 ;
struct V_40 * V_41 = NULL , * V_161 ;
struct V_162 V_163 ;
struct V_9 * V_164 ;
struct V_14 * V_20 ;
struct V_42 * V_112 ;
struct V_165 V_166 ;
T_3 V_136 = F_141 ( V_110 [ V_167 ] ) ;
int error ;
bool log = ! V_110 [ V_168 ] ;
error = - V_69 ;
if ( ! V_110 [ V_169 ] ) {
F_142 ( log , L_1 ) ;
goto error;
}
if ( ! V_110 [ V_153 ] ) {
F_142 ( log , L_2 ) ;
goto error;
}
V_161 = F_100 () ;
if ( F_35 ( V_161 ) ) {
error = F_60 ( V_161 ) ;
goto error;
}
F_143 ( & V_166 , & V_161 -> V_38 , false , & V_163 ) ;
error = F_144 ( V_15 , & V_166 , V_110 [ V_169 ] ,
V_110 [ V_170 ] , log ) ;
if ( error )
goto V_171;
error = F_145 ( & V_161 -> V_156 , V_110 [ V_172 ] ,
& V_161 -> V_38 , log ) ;
if ( error )
goto V_171;
if ( F_146 ( & V_161 -> V_156 ) )
V_166 . V_38 = V_161 -> V_156 . V_173 ;
F_147 ( & V_161 -> V_38 , & V_161 -> V_38 , true , & V_163 ) ;
error = F_102 ( V_15 , V_110 [ V_153 ] ,
& V_161 -> V_38 , & V_112 , log ) ;
if ( error ) {
F_142 ( log , L_3 ) ;
goto V_171;
}
V_164 = F_135 ( V_112 , & V_161 -> V_156 , V_4 , false ,
V_136 ) ;
if ( F_35 ( V_164 ) ) {
error = F_60 ( V_164 ) ;
goto V_174;
}
F_6 () ;
V_20 = F_15 ( V_15 , V_74 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_87 ;
goto V_175;
}
if ( F_115 ( & V_161 -> V_156 ) )
V_41 = F_148 ( & V_20 -> V_26 , & V_161 -> V_156 ) ;
if ( ! V_41 )
V_41 = F_149 ( & V_20 -> V_26 , & V_161 -> V_38 ) ;
if ( F_150 ( ! V_41 ) ) {
F_103 ( V_161 -> V_43 , V_112 ) ;
error = F_151 ( & V_20 -> V_26 , V_161 , & V_163 ) ;
if ( F_45 ( error ) ) {
V_112 = NULL ;
goto V_175;
}
if ( F_45 ( V_164 ) ) {
error = F_129 ( V_161 ,
V_74 -> V_16 ,
V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 ,
V_176 ,
V_136 ) ;
F_78 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_42 * V_177 ;
if ( F_45 ( V_4 -> V_6 -> V_7 & ( V_178
| V_179 ) ) ) {
error = - V_180 ;
goto V_175;
}
if ( F_45 ( ! F_152 ( V_41 , & V_166 ) ) ) {
if ( F_146 ( & V_41 -> V_156 ) )
V_41 = F_153 ( & V_20 -> V_26 ,
& V_166 ) ;
else
V_41 = NULL ;
if ( ! V_41 ) {
error = - V_181 ;
goto V_175;
}
}
V_177 = F_138 ( V_41 -> V_43 ) ;
F_103 ( V_41 -> V_43 , V_112 ) ;
if ( F_45 ( V_164 ) ) {
error = F_129 ( V_41 ,
V_74 -> V_16 ,
V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 ,
V_176 ,
V_136 ) ;
F_78 ( error < 0 ) ;
}
F_8 () ;
F_154 ( V_177 ) ;
F_106 ( V_161 , false ) ;
}
if ( V_164 )
F_4 ( & V_155 , V_164 , V_4 ) ;
return 0 ;
V_175:
F_8 () ;
F_48 ( V_164 ) ;
V_174:
F_155 ( V_112 ) ;
V_171:
F_106 ( V_161 , false ) ;
error:
return error ;
}
static struct V_42 * F_156 ( struct V_15 * V_15 ,
const struct V_84 * V_110 ,
const struct V_37 * V_38 ,
const struct V_162 * V_163 ,
bool log )
{
struct V_42 * V_112 ;
struct V_37 V_182 ;
int error ;
F_147 ( & V_182 , V_38 , true , V_163 ) ;
error = F_102 ( V_15 , V_110 , & V_182 , & V_112 , log ) ;
if ( error ) {
F_142 ( log ,
L_4 ) ;
return F_136 ( error ) ;
}
return V_112 ;
}
static int F_157 ( struct V_15 * V_15 ,
struct V_165 * V_166 ,
struct V_37 * V_38 ,
struct V_84 * * V_110 ,
struct V_42 * * V_112 ,
bool log )
{
struct V_162 V_163 ;
int error = 0 ;
if ( V_110 [ V_169 ] ) {
F_143 ( V_166 , V_38 , true , & V_163 ) ;
error = F_144 ( V_15 , V_166 , V_110 [ V_169 ] ,
V_110 [ V_170 ] , log ) ;
if ( error )
goto error;
}
if ( V_110 [ V_153 ] ) {
if ( ! V_110 [ V_169 ] ) {
F_142 ( log ,
L_5 ) ;
error = - V_69 ;
goto error;
}
* V_112 = F_156 ( V_15 , V_110 [ V_153 ] , V_38 ,
& V_163 , log ) ;
if ( F_35 ( * V_112 ) ) {
error = F_60 ( * V_112 ) ;
goto error;
}
}
error:
V_166 -> V_163 = NULL ;
return error ;
}
static int F_158 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_94 ( V_10 -> V_109 ) ;
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_74 * V_74 = V_4 -> V_108 ;
struct V_37 V_38 ;
struct V_40 * V_41 ;
struct V_9 * V_164 = NULL ;
struct V_14 * V_20 ;
struct V_42 * V_177 = NULL , * V_112 = NULL ;
struct V_165 V_166 ;
struct V_134 V_135 ;
T_3 V_136 = F_141 ( V_110 [ V_167 ] ) ;
int error = 0 ;
bool log = ! V_110 [ V_168 ] ;
bool V_183 ;
V_183 = F_159 ( & V_135 , V_110 [ V_172 ] , log ) ;
if ( ! V_110 [ V_169 ] && ! V_183 ) {
F_142 ( log ,
L_6 ) ;
return - V_69 ;
}
error = F_157 ( V_15 , & V_166 , & V_38 , V_110 ,
& V_112 , log ) ;
if ( error )
goto error;
if ( V_112 ) {
V_164 = F_135 ( V_112 , & V_135 , V_4 , false ,
V_136 ) ;
if ( F_35 ( V_164 ) ) {
error = F_60 ( V_164 ) ;
goto V_174;
}
}
F_6 () ;
V_20 = F_15 ( V_15 , V_74 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_87 ;
goto V_175;
}
if ( V_183 )
V_41 = F_148 ( & V_20 -> V_26 , & V_135 ) ;
else
V_41 = F_153 ( & V_20 -> V_26 , & V_166 ) ;
if ( F_45 ( ! V_41 ) ) {
error = - V_181 ;
goto V_175;
}
if ( F_150 ( V_112 ) ) {
V_177 = F_138 ( V_41 -> V_43 ) ;
F_103 ( V_41 -> V_43 , V_112 ) ;
if ( F_45 ( V_164 ) ) {
error = F_129 ( V_41 ,
V_74 -> V_16 ,
V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 ,
V_176 ,
V_136 ) ;
F_78 ( error < 0 ) ;
}
} else {
V_164 = F_137 ( V_41 , V_74 -> V_16 ,
V_4 , V_176 , false ,
V_136 ) ;
if ( F_35 ( V_164 ) ) {
error = F_60 ( V_164 ) ;
goto V_175;
}
}
if ( V_110 [ V_184 ] )
F_160 ( V_41 ) ;
F_8 () ;
if ( V_164 )
F_4 ( & V_155 , V_164 , V_4 ) ;
if ( V_177 )
F_154 ( V_177 ) ;
return 0 ;
V_175:
F_8 () ;
F_48 ( V_164 ) ;
V_174:
F_155 ( V_112 ) ;
error:
return error ;
}
static int F_161 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_74 * V_74 = V_4 -> V_108 ;
struct V_15 * V_15 = F_94 ( V_10 -> V_109 ) ;
struct V_37 V_38 ;
struct V_9 * V_164 ;
struct V_40 * V_41 ;
struct V_14 * V_20 ;
struct V_165 V_166 ;
struct V_134 V_185 ;
T_3 V_136 = F_141 ( V_110 [ V_167 ] ) ;
int V_62 = 0 ;
bool log = ! V_110 [ V_168 ] ;
bool V_183 ;
V_183 = F_159 ( & V_185 , V_110 [ V_172 ] , log ) ;
if ( V_110 [ V_169 ] ) {
F_143 ( & V_166 , & V_38 , true , NULL ) ;
V_62 = F_144 ( V_15 , & V_166 , V_110 [ V_169 ] , NULL ,
log ) ;
} else if ( ! V_183 ) {
F_142 ( log ,
L_7 ) ;
V_62 = - V_69 ;
}
if ( V_62 )
return V_62 ;
F_6 () ;
V_20 = F_15 ( F_94 ( V_10 -> V_109 ) , V_74 -> V_16 ) ;
if ( ! V_20 ) {
V_62 = - V_87 ;
goto V_186;
}
if ( V_183 )
V_41 = F_148 ( & V_20 -> V_26 , & V_185 ) ;
else
V_41 = F_153 ( & V_20 -> V_26 , & V_166 ) ;
if ( ! V_41 ) {
V_62 = - V_181 ;
goto V_186;
}
V_164 = F_137 ( V_41 , V_74 -> V_16 , V_4 ,
V_176 , true , V_136 ) ;
if ( F_35 ( V_164 ) ) {
V_62 = F_60 ( V_164 ) ;
goto V_186;
}
F_8 () ;
return F_162 ( V_164 , V_4 ) ;
V_186:
F_8 () ;
return V_62 ;
}
static int F_163 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_74 * V_74 = V_4 -> V_108 ;
struct V_15 * V_15 = F_94 ( V_10 -> V_109 ) ;
struct V_37 V_38 ;
struct V_9 * V_164 ;
struct V_40 * V_41 = NULL ;
struct V_14 * V_20 ;
struct V_165 V_166 ;
struct V_134 V_185 ;
T_3 V_136 = F_141 ( V_110 [ V_167 ] ) ;
int V_62 ;
bool log = ! V_110 [ V_168 ] ;
bool V_183 ;
V_183 = F_159 ( & V_185 , V_110 [ V_172 ] , log ) ;
if ( V_110 [ V_169 ] ) {
F_143 ( & V_166 , & V_38 , true , NULL ) ;
V_62 = F_144 ( V_15 , & V_166 , V_110 [ V_169 ] ,
NULL , log ) ;
if ( F_45 ( V_62 ) )
return V_62 ;
}
F_6 () ;
V_20 = F_15 ( F_94 ( V_10 -> V_109 ) , V_74 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
V_62 = - V_87 ;
goto V_186;
}
if ( F_45 ( ! V_110 [ V_169 ] && ! V_183 ) ) {
V_62 = F_164 ( & V_20 -> V_26 ) ;
goto V_186;
}
if ( V_183 )
V_41 = F_148 ( & V_20 -> V_26 , & V_185 ) ;
else
V_41 = F_153 ( & V_20 -> V_26 , & V_166 ) ;
if ( F_45 ( ! V_41 ) ) {
V_62 = - V_181 ;
goto V_186;
}
F_165 ( & V_20 -> V_26 , V_41 ) ;
F_8 () ;
V_164 = F_135 ( ( const struct V_42 V_187 * ) V_41 -> V_43 ,
& V_41 -> V_156 , V_4 , false , V_136 ) ;
if ( F_150 ( V_164 ) ) {
if ( F_150 ( ! F_35 ( V_164 ) ) ) {
F_18 () ;
V_62 = F_129 ( V_41 , V_74 -> V_16 ,
V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 ,
V_188 ,
V_136 ) ;
F_19 () ;
F_78 ( V_62 < 0 ) ;
F_4 ( & V_155 , V_164 , V_4 ) ;
} else {
F_166 ( F_94 ( V_10 -> V_109 ) -> V_189 , 0 , 0 , F_60 ( V_164 ) ) ;
}
}
F_106 ( V_41 , true ) ;
return 0 ;
V_186:
F_8 () ;
return V_62 ;
}
static int F_167 ( struct V_9 * V_10 , struct V_190 * V_191 )
{
struct V_84 * V_110 [ V_192 ] ;
struct V_74 * V_74 = F_168 ( F_169 ( V_191 -> V_193 ) ) ;
struct V_194 * V_195 ;
struct V_14 * V_20 ;
T_3 V_136 ;
int V_62 ;
V_62 = F_170 ( V_191 -> V_193 , & V_155 , V_110 ,
V_196 , V_197 , NULL ) ;
if ( V_62 )
return V_62 ;
V_136 = F_141 ( V_110 [ V_167 ] ) ;
F_18 () ;
V_20 = F_12 ( F_94 ( V_10 -> V_109 ) , V_74 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_87 ;
}
V_195 = F_51 ( V_20 -> V_26 . V_195 ) ;
for (; ; ) {
struct V_40 * V_41 ;
T_3 V_198 , V_199 ;
V_198 = V_191 -> args [ 0 ] ;
V_199 = V_191 -> args [ 1 ] ;
V_41 = F_171 ( V_195 , & V_198 , & V_199 ) ;
if ( ! V_41 )
break;
if ( F_129 ( V_41 , V_74 -> V_16 , V_10 ,
F_172 ( V_191 -> V_10 ) . V_52 ,
V_191 -> V_193 -> V_200 , V_201 ,
V_176 , V_136 ) < 0 )
break;
V_191 -> args [ 0 ] = V_198 ;
V_191 -> args [ 1 ] = V_199 ;
}
F_19 () ;
return V_10 -> V_82 ;
}
static T_5 F_173 ( void )
{
T_5 V_202 = F_62 ( sizeof( struct V_74 ) ) ;
V_202 += F_63 ( V_203 ) ;
V_202 += F_119 ( sizeof( struct V_125 ) ) ;
V_202 += F_119 ( sizeof( struct V_126 ) ) ;
V_202 += F_63 ( sizeof( T_3 ) ) ;
return V_202 ;
}
static int F_174 ( struct V_14 * V_20 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_154 , T_3 V_57 , V_150 V_50 )
{
struct V_74 * V_74 ;
struct V_125 V_204 ;
struct V_126 V_205 ;
int V_62 ;
V_74 = F_76 ( V_10 , V_52 , V_154 , & V_206 ,
V_57 , V_50 ) ;
if ( ! V_74 )
goto error;
V_74 -> V_16 = F_23 ( V_20 ) ;
V_62 = F_175 ( V_10 , V_207 , F_20 ( V_20 ) ) ;
if ( V_62 )
goto V_208;
F_107 ( V_20 , & V_204 , & V_205 ) ;
if ( F_124 ( V_10 , V_209 , sizeof( struct V_125 ) ,
& V_204 , V_210 ) )
goto V_208;
if ( F_124 ( V_10 , V_211 ,
sizeof( struct V_126 ) ,
& V_205 , V_210 ) )
goto V_208;
if ( F_87 ( V_10 , V_212 , V_20 -> V_79 ) )
goto V_208;
F_133 ( V_10 , V_74 ) ;
return 0 ;
V_208:
F_134 ( V_10 , V_74 ) ;
error:
return - V_147 ;
}
static struct V_9 * F_176 ( void )
{
return F_75 ( F_173 () , V_11 ) ;
}
static struct V_14 * F_177 ( struct V_15 * V_15 ,
const struct V_74 * V_74 ,
struct V_84 * V_110 [ V_213 + 1 ] )
{
struct V_14 * V_20 ;
if ( ! V_110 [ V_207 ] )
V_20 = F_15 ( V_15 , V_74 -> V_16 ) ;
else {
struct V_19 * V_19 ;
V_19 = F_178 ( V_15 , F_80 ( V_110 [ V_207 ] ) ) ;
V_20 = V_19 && V_19 -> V_30 == V_21 ? V_19 -> V_20 : NULL ;
}
return V_20 ? V_20 : F_136 ( - V_87 ) ;
}
static void F_179 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_14 * V_20 ;
V_20 = F_177 ( F_94 ( V_10 -> V_109 ) , V_4 -> V_108 , V_4 -> V_111 ) ;
if ( F_35 ( V_20 ) )
return;
F_180 ( V_20 -> V_79 , L_8 ) ;
V_20 -> V_79 = 0 ;
}
static void F_181 ( struct V_14 * V_20 , struct V_84 * V_110 [] )
{
if ( V_110 [ V_212 ] )
V_20 -> V_79 = F_182 ( V_110 [ V_212 ] ) ;
}
static int F_183 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_33 V_34 ;
struct V_9 * V_164 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
struct V_214 * V_214 ;
int V_62 , V_128 ;
V_62 = - V_69 ;
if ( ! V_110 [ V_207 ] || ! V_110 [ V_215 ] )
goto V_62;
V_164 = F_176 () ;
if ( ! V_164 )
return - V_89 ;
V_62 = - V_89 ;
V_20 = F_184 ( sizeof( * V_20 ) , V_11 ) ;
if ( V_20 == NULL )
goto V_216;
F_185 ( V_20 , F_94 ( V_10 -> V_109 ) ) ;
V_62 = F_186 ( & V_20 -> V_26 ) ;
if ( V_62 )
goto V_217;
V_20 -> V_27 = F_187 ( struct V_44 ) ;
if ( ! V_20 -> V_27 ) {
V_62 = - V_89 ;
goto V_218;
}
V_20 -> V_28 = F_188 ( V_31 * sizeof( struct V_29 ) ,
V_11 ) ;
if ( ! V_20 -> V_28 ) {
V_62 = - V_89 ;
goto V_219;
}
for ( V_128 = 0 ; V_128 < V_31 ; V_128 ++ )
F_189 ( & V_20 -> V_28 [ V_128 ] ) ;
V_34 . V_220 = F_80 ( V_110 [ V_207 ] ) ;
V_34 . type = V_221 ;
V_34 . V_222 = NULL ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_21 ;
V_34 . V_223 = V_110 [ V_215 ] ;
F_181 ( V_20 , V_110 ) ;
F_6 () ;
V_19 = F_33 ( & V_34 ) ;
if ( F_35 ( V_19 ) ) {
V_62 = F_60 ( V_19 ) ;
if ( V_62 == - V_224 )
V_62 = - V_180 ;
if ( V_62 == - V_180 ) {
if ( V_4 -> V_225 -> V_226 < V_227 )
F_179 ( V_10 , V_4 ) ;
}
goto V_228;
}
V_62 = F_174 ( V_20 , V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 , V_229 ) ;
F_78 ( V_62 < 0 ) ;
V_214 = F_190 ( F_91 ( V_20 ) , V_230 ) ;
F_191 ( & V_20 -> V_231 , & V_214 -> V_232 ) ;
F_8 () ;
F_4 ( & V_206 , V_164 , V_4 ) ;
return 0 ;
V_228:
F_8 () ;
F_29 ( V_20 -> V_28 ) ;
V_219:
F_28 ( V_20 -> V_27 ) ;
V_218:
F_27 ( & V_20 -> V_26 ) ;
V_217:
F_29 ( V_20 ) ;
V_216:
F_48 ( V_164 ) ;
V_62:
return V_62 ;
}
static void F_192 ( struct V_14 * V_20 )
{
int V_128 ;
for ( V_128 = 0 ; V_128 < V_31 ; V_128 ++ ) {
struct V_19 * V_19 ;
struct V_233 * V_234 ;
F_193 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_19 -> V_30 != V_21 )
F_37 ( V_19 ) ;
}
F_194 ( & V_20 -> V_231 ) ;
F_37 ( F_195 ( V_20 , V_21 ) ) ;
F_196 ( & V_20 -> V_25 , F_25 ) ;
}
static int F_197 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_164 ;
struct V_14 * V_20 ;
int V_62 ;
V_164 = F_176 () ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_20 = F_177 ( F_94 ( V_10 -> V_109 ) , V_4 -> V_108 , V_4 -> V_111 ) ;
V_62 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_235;
V_62 = F_174 ( V_20 , V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 , V_236 ) ;
F_78 ( V_62 < 0 ) ;
F_192 ( V_20 ) ;
F_8 () ;
F_4 ( & V_206 , V_164 , V_4 ) ;
return 0 ;
V_235:
F_8 () ;
F_48 ( V_164 ) ;
return V_62 ;
}
static int F_198 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_164 ;
struct V_14 * V_20 ;
int V_62 ;
V_164 = F_176 () ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_20 = F_177 ( F_94 ( V_10 -> V_109 ) , V_4 -> V_108 , V_4 -> V_111 ) ;
V_62 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_235;
F_181 ( V_20 , V_4 -> V_111 ) ;
V_62 = F_174 ( V_20 , V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 , V_229 ) ;
F_78 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_206 , V_164 , V_4 ) ;
return 0 ;
V_235:
F_8 () ;
F_48 ( V_164 ) ;
return V_62 ;
}
static int F_199 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_164 ;
struct V_14 * V_20 ;
int V_62 ;
V_164 = F_176 () ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_20 = F_177 ( F_94 ( V_10 -> V_109 ) , V_4 -> V_108 , V_4 -> V_111 ) ;
if ( F_35 ( V_20 ) ) {
V_62 = F_60 ( V_20 ) ;
goto V_235;
}
V_62 = F_174 ( V_20 , V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 , V_229 ) ;
F_78 ( V_62 < 0 ) ;
F_8 () ;
return F_162 ( V_164 , V_4 ) ;
V_235:
F_8 () ;
F_48 ( V_164 ) ;
return V_62 ;
}
static int F_200 ( struct V_9 * V_10 , struct V_190 * V_191 )
{
struct V_214 * V_214 = F_190 ( F_94 ( V_10 -> V_109 ) , V_230 ) ;
struct V_14 * V_20 ;
int V_237 = V_191 -> args [ 0 ] ;
int V_128 = 0 ;
F_6 () ;
F_201 (dp, &ovs_net->dps, list_node) {
if ( V_128 >= V_237 &&
F_174 ( V_20 , V_10 , F_172 ( V_191 -> V_10 ) . V_52 ,
V_191 -> V_193 -> V_200 , V_201 ,
V_229 ) < 0 )
break;
V_128 ++ ;
}
F_8 () ;
V_191 -> args [ 0 ] = V_128 ;
return V_10 -> V_82 ;
}
static int F_202 ( struct V_19 * V_19 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_154 , T_3 V_57 , V_150 V_50 )
{
struct V_74 * V_74 ;
struct V_238 V_239 ;
int V_62 ;
V_74 = F_76 ( V_10 , V_52 , V_154 , & V_240 ,
V_57 , V_50 ) ;
if ( ! V_74 )
return - V_147 ;
V_74 -> V_16 = F_23 ( V_19 -> V_20 ) ;
if ( F_87 ( V_10 , V_241 , V_19 -> V_30 ) ||
F_87 ( V_10 , V_242 , V_19 -> V_243 -> type ) ||
F_175 ( V_10 , V_244 ,
F_22 ( V_19 ) ) )
goto V_208;
F_203 ( V_19 , & V_239 ) ;
if ( F_124 ( V_10 , V_245 ,
sizeof( struct V_238 ) , & V_239 ,
V_246 ) )
goto V_208;
if ( F_204 ( V_19 , V_10 ) )
goto V_208;
V_62 = F_205 ( V_19 , V_10 ) ;
if ( V_62 == - V_147 )
goto error;
F_133 ( V_10 , V_74 ) ;
return 0 ;
V_208:
V_62 = - V_147 ;
error:
F_134 ( V_10 , V_74 ) ;
return V_62 ;
}
static struct V_9 * F_206 ( void )
{
return F_207 ( V_247 , V_11 ) ;
}
struct V_9 * F_208 ( struct V_19 * V_19 , T_3 V_52 ,
T_3 V_154 , V_150 V_50 )
{
struct V_9 * V_10 ;
int V_158 ;
V_10 = F_207 ( V_247 , V_88 ) ;
if ( ! V_10 )
return F_136 ( - V_89 ) ;
V_158 = F_202 ( V_19 , V_10 , V_52 , V_154 , 0 , V_50 ) ;
F_78 ( V_158 < 0 ) ;
return V_10 ;
}
static struct V_19 * F_209 ( struct V_15 * V_15 ,
const struct V_74 * V_74 ,
struct V_84 * V_110 [ V_248 + 1 ] )
{
struct V_14 * V_20 ;
struct V_19 * V_19 ;
if ( V_110 [ V_244 ] ) {
V_19 = F_178 ( V_15 , F_80 ( V_110 [ V_244 ] ) ) ;
if ( ! V_19 )
return F_136 ( - V_87 ) ;
if ( V_74 -> V_16 &&
V_74 -> V_16 != F_23 ( V_19 -> V_20 ) )
return F_136 ( - V_87 ) ;
return V_19 ;
} else if ( V_110 [ V_241 ] ) {
T_3 V_30 = F_182 ( V_110 [ V_241 ] ) ;
if ( V_30 >= V_249 )
return F_136 ( - V_91 ) ;
V_20 = F_15 ( V_15 , V_74 -> V_16 ) ;
if ( ! V_20 )
return F_136 ( - V_87 ) ;
V_19 = F_21 ( V_20 , V_30 ) ;
if ( ! V_19 )
return F_136 ( - V_87 ) ;
return V_19 ;
} else
return F_136 ( - V_69 ) ;
}
static void F_210 ( struct V_14 * V_20 )
{
unsigned V_250 , V_251 = 0 ;
struct V_17 * V_18 ;
struct V_19 * V_19 ;
int V_128 ;
for ( V_128 = 0 ; V_128 < V_31 ; V_128 ++ ) {
F_32 (vport, &dp->ports[i], dp_hash_node) {
V_18 = V_19 -> V_18 ;
V_250 = F_211 ( V_18 ) ;
if ( V_250 > V_251 )
V_251 = V_250 ;
}
}
V_20 -> V_251 = V_251 ;
for ( V_128 = 0 ; V_128 < V_31 ; V_128 ++ )
F_32 (vport, &dp->ports[i], dp_hash_node)
F_212 ( V_19 -> V_18 , V_251 ) ;
}
static int F_213 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_74 * V_74 = V_4 -> V_108 ;
struct V_33 V_34 ;
struct V_9 * V_164 ;
struct V_19 * V_19 ;
struct V_14 * V_20 ;
T_3 V_30 ;
int V_62 ;
if ( ! V_110 [ V_244 ] || ! V_110 [ V_242 ] ||
! V_110 [ V_252 ] )
return - V_69 ;
V_30 = V_110 [ V_241 ]
? F_182 ( V_110 [ V_241 ] ) : 0 ;
if ( V_30 >= V_249 )
return - V_91 ;
V_164 = F_206 () ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_253:
V_20 = F_15 ( F_94 ( V_10 -> V_109 ) , V_74 -> V_16 ) ;
V_62 = - V_87 ;
if ( ! V_20 )
goto V_254;
if ( V_30 ) {
V_19 = F_195 ( V_20 , V_30 ) ;
V_62 = - V_224 ;
if ( V_19 )
goto V_254;
} else {
for ( V_30 = 1 ; ; V_30 ++ ) {
if ( V_30 >= V_249 ) {
V_62 = - V_91 ;
goto V_254;
}
V_19 = F_195 ( V_20 , V_30 ) ;
if ( ! V_19 )
break;
}
}
V_34 . V_220 = F_80 ( V_110 [ V_244 ] ) ;
V_34 . type = F_182 ( V_110 [ V_242 ] ) ;
V_34 . V_222 = V_110 [ V_255 ] ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_30 ;
V_34 . V_223 = V_110 [ V_252 ] ;
V_19 = F_33 ( & V_34 ) ;
V_62 = F_60 ( V_19 ) ;
if ( F_35 ( V_19 ) ) {
if ( V_62 == - V_256 )
goto V_253;
goto V_254;
}
V_62 = F_202 ( V_19 , V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 , V_257 ) ;
if ( F_211 ( V_19 -> V_18 ) > V_20 -> V_251 )
F_210 ( V_20 ) ;
else
F_212 ( V_19 -> V_18 , V_20 -> V_251 ) ;
F_78 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_240 , V_164 , V_4 ) ;
return 0 ;
V_254:
F_8 () ;
F_48 ( V_164 ) ;
return V_62 ;
}
static int F_214 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_9 * V_164 ;
struct V_19 * V_19 ;
int V_62 ;
V_164 = F_206 () ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_19 = F_209 ( F_94 ( V_10 -> V_109 ) , V_4 -> V_108 , V_110 ) ;
V_62 = F_60 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_254;
if ( V_110 [ V_242 ] &&
F_182 ( V_110 [ V_242 ] ) != V_19 -> V_243 -> type ) {
V_62 = - V_69 ;
goto V_254;
}
if ( V_110 [ V_255 ] ) {
V_62 = F_215 ( V_19 , V_110 [ V_255 ] ) ;
if ( V_62 )
goto V_254;
}
if ( V_110 [ V_252 ] ) {
struct V_84 * V_258 = V_110 [ V_252 ] ;
V_62 = F_216 ( V_19 , V_258 ) ;
if ( V_62 )
goto V_254;
}
V_62 = F_202 ( V_19 , V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 , V_257 ) ;
F_78 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_240 , V_164 , V_4 ) ;
return 0 ;
V_254:
F_8 () ;
F_48 ( V_164 ) ;
return V_62 ;
}
static int F_217 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
bool V_259 = false ;
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_9 * V_164 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
int V_62 ;
V_164 = F_206 () ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_19 = F_209 ( F_94 ( V_10 -> V_109 ) , V_4 -> V_108 , V_110 ) ;
V_62 = F_60 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_254;
if ( V_19 -> V_30 == V_21 ) {
V_62 = - V_69 ;
goto V_254;
}
V_62 = F_202 ( V_19 , V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 , V_260 ) ;
F_78 ( V_62 < 0 ) ;
V_20 = V_19 -> V_20 ;
if ( F_211 ( V_19 -> V_18 ) == V_20 -> V_251 )
V_259 = true ;
F_218 ( V_19 -> V_18 ) ;
F_37 ( V_19 ) ;
if ( V_259 )
F_210 ( V_20 ) ;
F_8 () ;
F_4 ( & V_240 , V_164 , V_4 ) ;
return 0 ;
V_254:
F_8 () ;
F_48 ( V_164 ) ;
return V_62 ;
}
static int F_219 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_84 * * V_110 = V_4 -> V_111 ;
struct V_74 * V_74 = V_4 -> V_108 ;
struct V_9 * V_164 ;
struct V_19 * V_19 ;
int V_62 ;
V_164 = F_206 () ;
if ( ! V_164 )
return - V_89 ;
F_18 () ;
V_19 = F_209 ( F_94 ( V_10 -> V_109 ) , V_74 , V_110 ) ;
V_62 = F_60 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_254;
V_62 = F_202 ( V_19 , V_164 , V_4 -> V_159 ,
V_4 -> V_160 , 0 , V_257 ) ;
F_78 ( V_62 < 0 ) ;
F_19 () ;
return F_162 ( V_164 , V_4 ) ;
V_254:
F_19 () ;
F_48 ( V_164 ) ;
return V_62 ;
}
static int F_220 ( struct V_9 * V_10 , struct V_190 * V_191 )
{
struct V_74 * V_74 = F_168 ( F_169 ( V_191 -> V_193 ) ) ;
struct V_14 * V_20 ;
int V_198 = V_191 -> args [ 0 ] , V_237 = V_191 -> args [ 1 ] ;
int V_128 , V_261 = 0 ;
F_18 () ;
V_20 = F_12 ( F_94 ( V_10 -> V_109 ) , V_74 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_87 ;
}
for ( V_128 = V_198 ; V_128 < V_31 ; V_128 ++ ) {
struct V_19 * V_19 ;
V_261 = 0 ;
F_32 (vport, &dp->ports[i], dp_hash_node) {
if ( V_261 >= V_237 &&
F_202 ( V_19 , V_10 ,
F_172 ( V_191 -> V_10 ) . V_52 ,
V_191 -> V_193 -> V_200 ,
V_201 ,
V_257 ) < 0 )
goto V_55;
V_261 ++ ;
}
V_237 = 0 ;
}
V_55:
F_19 () ;
V_191 -> args [ 0 ] = V_128 ;
V_191 -> args [ 1 ] = V_261 ;
return V_10 -> V_82 ;
}
static void F_221 ( int V_262 )
{
int V_128 ;
for ( V_128 = 0 ; V_128 < V_262 ; V_128 ++ )
F_222 ( V_263 [ V_128 ] ) ;
}
static int T_7 F_223 ( void )
{
int V_62 ;
int V_128 ;
for ( V_128 = 0 ; V_128 < F_224 ( V_263 ) ; V_128 ++ ) {
V_62 = F_225 ( V_263 [ V_128 ] ) ;
if ( V_62 )
goto error;
}
return 0 ;
error:
F_221 ( V_128 ) ;
return V_62 ;
}
static int T_8 F_226 ( struct V_15 * V_15 )
{
struct V_214 * V_214 = F_190 ( V_15 , V_230 ) ;
F_227 ( & V_214 -> V_232 ) ;
F_228 ( & V_214 -> V_264 , V_265 ) ;
F_229 ( V_15 ) ;
return 0 ;
}
static void T_9 F_230 ( struct V_15 * V_15 , struct V_15 * V_266 ,
struct V_267 * V_32 )
{
struct V_214 * V_214 = F_190 ( V_15 , V_230 ) ;
struct V_14 * V_20 ;
F_201 (dp, &ovs_net->dps, list_node) {
int V_128 ;
for ( V_128 = 0 ; V_128 < V_31 ; V_128 ++ ) {
struct V_19 * V_19 ;
F_231 (vport, &dp->ports[i], dp_hash_node) {
if ( V_19 -> V_243 -> type != V_221 )
continue;
if ( F_232 ( V_19 -> V_18 ) == V_266 )
F_233 ( & V_19 -> V_268 , V_32 ) ;
}
}
}
}
static void T_9 F_234 ( struct V_15 * V_266 )
{
struct V_14 * V_20 , * V_269 ;
struct V_214 * V_214 = F_190 ( V_266 , V_230 ) ;
struct V_19 * V_19 , * V_270 ;
struct V_15 * V_15 ;
F_235 ( V_32 ) ;
F_236 ( V_266 ) ;
F_6 () ;
F_237 (dp, dp_next, &ovs_net->dps, list_node)
F_192 ( V_20 ) ;
F_238 () ;
F_239 (net)
F_230 ( V_15 , V_266 , & V_32 ) ;
F_240 () ;
F_237 (vport, vport_next, &head, detach_list) {
F_241 ( & V_19 -> V_268 ) ;
F_37 ( V_19 ) ;
}
F_8 () ;
F_242 ( & V_214 -> V_264 ) ;
}
static int T_7 F_243 ( void )
{
int V_62 ;
F_58 ( sizeof( struct V_271 ) > F_244 ( struct V_9 , V_191 ) ) ;
F_245 ( L_9 ) ;
V_62 = F_246 () ;
if ( V_62 )
goto error;
V_62 = F_247 () ;
if ( V_62 )
goto V_272;
V_62 = F_248 () ;
if ( V_62 )
goto V_273;
V_62 = F_249 () ;
if ( V_62 )
goto V_274;
V_62 = F_250 ( & V_275 ) ;
if ( V_62 )
goto V_276;
V_62 = F_251 ( & V_277 ) ;
if ( V_62 )
goto V_278;
V_62 = F_252 () ;
if ( V_62 )
goto V_279;
V_62 = F_223 () ;
if ( V_62 < 0 )
goto V_280;
return 0 ;
V_280:
F_253 () ;
V_279:
F_254 ( & V_277 ) ;
V_278:
F_255 ( & V_275 ) ;
V_276:
F_256 () ;
V_274:
F_257 () ;
V_273:
F_258 () ;
V_272:
F_259 () ;
error:
return V_62 ;
}
static void F_260 ( void )
{
F_221 ( F_224 ( V_263 ) ) ;
F_253 () ;
F_254 ( & V_277 ) ;
F_255 ( & V_275 ) ;
F_261 () ;
F_256 () ;
F_257 () ;
F_258 () ;
F_259 () ;
}
