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
unsigned short V_65 = F_58 ( V_10 ) -> V_65 ;
struct V_37 V_66 ;
struct V_9 * V_67 , * V_68 ;
int V_62 ;
F_59 ( sizeof( * F_42 ( V_10 ) ) > V_69 ) ;
V_67 = F_60 ( V_10 , V_70 , false ) ;
if ( F_35 ( V_67 ) )
return F_61 ( V_67 ) ;
if ( V_67 == NULL )
return - V_71 ;
if ( V_65 & V_72 ) {
V_66 = * V_38 ;
V_66 . V_73 . V_74 = V_75 ;
}
V_10 = V_67 ;
do {
if ( V_65 & V_72 && V_10 != V_67 )
V_38 = & V_66 ;
V_62 = F_56 ( V_20 , V_10 , V_38 , V_60 , V_61 ) ;
if ( V_62 )
break;
} while ( ( V_10 = V_10 -> V_76 ) );
V_10 = V_67 ;
do {
V_68 = V_10 -> V_76 ;
if ( V_62 )
F_48 ( V_10 ) ;
else
F_49 ( V_10 ) ;
} while ( ( V_10 = V_68 ) );
return V_62 ;
}
static T_5 F_62 ( const struct V_48 * V_60 ,
unsigned int V_77 )
{
T_5 V_78 = F_63 ( sizeof( struct V_79 ) )
+ F_64 ( V_77 )
+ F_64 ( F_65 () )
+ F_64 ( sizeof( unsigned int ) ) ;
if ( V_60 -> V_80 )
V_78 += F_66 ( V_60 -> V_80 -> V_81 ) ;
if ( V_60 -> V_82 )
V_78 += F_64 ( F_67 () ) ;
if ( V_60 -> V_83 )
V_78 += F_64 ( V_60 -> V_83 ) ;
if ( V_60 -> V_53 )
V_78 += F_64 ( sizeof( V_60 -> V_53 ) ) ;
return V_78 ;
}
static void F_68 ( struct V_14 * V_20 , struct V_9 * V_10 )
{
if ( ! ( V_20 -> V_84 & V_85 ) ) {
T_5 V_86 = F_66 ( V_10 -> V_87 ) - V_10 -> V_87 ;
if ( V_86 > 0 )
memset ( F_69 ( V_10 , V_86 ) , 0 , V_86 ) ;
}
}
static int F_56 ( struct V_14 * V_20 , struct V_9 * V_10 ,
const struct V_37 * V_38 ,
const struct V_48 * V_60 ,
T_4 V_61 )
{
struct V_79 * V_49 ;
struct V_9 * V_68 = NULL ;
struct V_9 * V_88 = NULL ;
struct V_89 * V_90 ;
T_5 V_87 ;
unsigned int V_91 ;
int V_62 , V_16 ;
V_16 = F_23 ( V_20 ) ;
if ( ! V_16 )
return - V_92 ;
if ( F_70 ( V_10 ) ) {
V_68 = F_71 ( V_10 , V_93 ) ;
if ( ! V_68 )
return - V_94 ;
V_68 = F_72 ( V_68 ) ;
if ( ! V_68 )
return - V_94 ;
V_10 = V_68 ;
}
if ( F_73 ( V_10 -> V_87 ) > V_95 ) {
V_62 = - V_96 ;
goto V_55;
}
if ( V_10 -> V_97 == V_98 &&
( V_62 = F_74 ( V_10 ) ) )
goto V_55;
if ( V_20 -> V_84 & V_85 )
V_91 = F_75 ( V_10 ) ;
else
V_91 = V_10 -> V_87 ;
V_87 = F_62 ( V_60 , V_91 - V_61 ) ;
V_88 = F_76 ( V_87 , V_93 ) ;
if ( ! V_88 ) {
V_62 = - V_94 ;
goto V_55;
}
V_49 = F_77 ( V_88 , 0 , 0 , & V_99 ,
0 , V_60 -> V_50 ) ;
V_49 -> V_16 = V_16 ;
V_62 = F_78 ( V_38 , V_38 , V_100 , false , V_88 ) ;
F_79 ( V_62 ) ;
if ( V_60 -> V_80 )
F_80 ( V_88 , V_101 ,
V_81 ( V_60 -> V_80 ) ,
F_81 ( V_60 -> V_80 ) ) ;
if ( V_60 -> V_82 ) {
V_90 = F_82 ( V_88 , V_102 ) ;
V_62 = F_83 ( V_88 ,
V_60 -> V_82 ) ;
F_79 ( V_62 ) ;
F_84 ( V_88 , V_90 ) ;
}
if ( V_60 -> V_83 ) {
V_90 = F_82 ( V_88 , V_103 ) ;
V_62 = F_85 ( V_60 -> V_104 ,
V_60 -> V_83 ,
V_88 ) ;
if ( ! V_62 )
F_84 ( V_88 , V_90 ) ;
else
F_86 ( V_88 , V_90 ) ;
}
if ( V_60 -> V_53 ) {
if ( F_87 ( V_88 , V_105 ,
V_60 -> V_53 ) ) {
V_62 = - V_106 ;
goto V_55;
}
F_68 ( V_20 , V_88 ) ;
}
if ( V_61 > 0 ) {
if ( F_88 ( V_88 , V_107 ,
V_10 -> V_87 ) ) {
V_62 = - V_106 ;
goto V_55;
}
F_68 ( V_20 , V_88 ) ;
}
if ( ! ( V_90 = F_89 ( V_88 , V_108 , 0 ) ) ) {
V_62 = - V_106 ;
goto V_55;
}
V_90 -> V_81 = F_73 ( V_10 -> V_87 - V_61 ) ;
V_62 = F_90 ( V_88 , V_10 , V_10 -> V_87 - V_61 , V_91 ) ;
if ( V_62 )
goto V_55;
F_68 ( V_20 , V_88 ) ;
( (struct V_109 * ) V_88 -> V_110 ) -> V_111 = V_88 -> V_87 ;
V_62 = F_91 ( F_92 ( V_20 ) , V_88 , V_60 -> V_52 ) ;
V_88 = NULL ;
V_55:
if ( V_62 )
F_93 ( V_10 ) ;
F_48 ( V_88 ) ;
F_48 ( V_68 ) ;
return V_62 ;
}
static int F_94 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_15 * V_15 = F_95 ( V_10 -> V_113 ) ;
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_42 * V_116 ;
struct V_9 * V_117 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_14 * V_20 ;
struct V_19 * V_39 ;
T_1 V_53 = 0 ;
int V_87 ;
int V_62 ;
bool log = ! V_114 [ V_118 ] ;
V_62 = - V_71 ;
if ( ! V_114 [ V_108 ] || ! V_114 [ V_100 ] ||
! V_114 [ V_103 ] )
goto V_62;
V_87 = V_81 ( V_114 [ V_108 ] ) ;
V_117 = F_96 ( V_119 + V_87 , V_11 ) ;
V_62 = - V_94 ;
if ( ! V_117 )
goto V_62;
F_97 ( V_117 , V_119 ) ;
F_98 ( F_99 ( V_117 , V_87 ) , V_114 [ V_108 ] , V_87 ) ;
if ( V_114 [ V_105 ] ) {
V_53 = F_100 ( V_114 [ V_105 ] ) ;
V_117 -> V_120 = 1 ;
}
F_42 ( V_117 ) -> V_53 = V_53 ;
V_41 = F_101 () ;
V_62 = F_61 ( V_41 ) ;
if ( F_35 ( V_41 ) )
goto V_121;
V_62 = F_102 ( V_15 , V_114 [ V_100 ] ,
V_117 , & V_41 -> V_38 , log ) ;
if ( V_62 )
goto V_122;
V_62 = F_103 ( V_15 , V_114 [ V_103 ] ,
& V_41 -> V_38 , & V_116 , log ) ;
if ( V_62 )
goto V_122;
F_104 ( V_41 -> V_43 , V_116 ) ;
V_117 -> V_123 = V_41 -> V_38 . V_124 . V_123 ;
V_117 -> V_125 = V_41 -> V_38 . V_124 . V_126 ;
F_18 () ;
V_20 = F_12 ( V_15 , V_79 -> V_16 ) ;
V_62 = - V_92 ;
if ( ! V_20 )
goto V_127;
V_39 = F_24 ( V_20 , V_41 -> V_38 . V_124 . V_128 ) ;
if ( ! V_39 )
V_39 = F_24 ( V_20 , V_21 ) ;
if ( ! V_39 )
goto V_127;
V_117 -> V_18 = V_39 -> V_18 ;
F_42 ( V_117 ) -> V_39 = V_39 ;
V_43 = F_51 ( V_41 -> V_43 ) ;
F_105 () ;
V_62 = F_52 ( V_20 , V_117 , V_43 , & V_41 -> V_38 ) ;
F_106 () ;
F_19 () ;
F_107 ( V_41 , false ) ;
return V_62 ;
V_127:
F_19 () ;
V_122:
F_107 ( V_41 , false ) ;
V_121:
F_48 ( V_117 ) ;
V_62:
return V_62 ;
}
static void F_108 ( const struct V_14 * V_20 , struct V_129 * V_45 ,
struct V_130 * V_131 )
{
int V_132 ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
V_45 -> V_133 = F_109 ( & V_20 -> V_26 ) ;
V_131 -> V_134 = F_110 ( & V_20 -> V_26 ) ;
V_45 -> V_58 = V_45 -> V_54 = V_45 -> V_64 = 0 ;
F_111 (i) {
const struct V_44 * V_135 ;
struct V_44 V_136 ;
unsigned int V_137 ;
V_135 = F_112 ( V_20 -> V_27 , V_132 ) ;
do {
V_137 = F_113 ( & V_135 -> V_59 ) ;
V_136 = * V_135 ;
} while ( F_114 ( & V_135 -> V_59 , V_137 ) );
V_45 -> V_58 += V_136 . V_58 ;
V_45 -> V_54 += V_136 . V_54 ;
V_45 -> V_64 += V_136 . V_64 ;
V_131 -> V_47 += V_136 . V_47 ;
}
}
static bool F_115 ( const struct V_138 * V_139 , T_4 V_140 )
{
return F_116 ( V_139 ) &&
! ( V_140 & V_141 ) ;
}
static bool F_117 ( T_4 V_140 )
{
return ! ( V_140 & V_142 ) ;
}
static bool F_118 ( T_4 V_140 )
{
return ! ( V_140 & V_143 ) ;
}
static T_5 F_119 ( const struct V_42 * V_116 ,
const struct V_138 * V_139 ,
T_4 V_140 )
{
T_5 V_87 = F_63 ( sizeof( struct V_79 ) ) ;
if ( V_139 && F_116 ( V_139 ) )
V_87 += F_64 ( V_139 -> V_144 ) ;
if ( ! V_139 || F_115 ( V_139 , V_140 ) )
V_87 += F_64 ( F_65 () ) ;
if ( F_117 ( V_140 ) )
V_87 += F_64 ( F_65 () ) ;
if ( F_118 ( V_140 ) )
V_87 += F_64 ( V_116 -> V_145 ) ;
return V_87
+ F_120 ( sizeof( struct V_146 ) )
+ F_64 ( 1 )
+ F_120 ( 8 ) ;
}
static int F_121 ( const struct V_40 * V_41 ,
struct V_9 * V_10 )
{
struct V_146 V_45 ;
T_6 V_147 ;
unsigned long V_148 ;
F_122 ( V_41 , & V_45 , & V_148 , & V_147 ) ;
if ( V_148 &&
F_123 ( V_10 , V_149 , F_124 ( V_148 ) ,
V_150 ) )
return - V_151 ;
if ( V_45 . V_152 &&
F_125 ( V_10 , V_153 ,
sizeof( struct V_146 ) , & V_45 ,
V_150 ) )
return - V_151 ;
if ( ( V_154 ) F_126 ( V_147 ) &&
F_127 ( V_10 , V_155 , ( V_154 ) F_126 ( V_147 ) ) )
return - V_151 ;
return 0 ;
}
static int F_128 ( const struct V_40 * V_41 ,
struct V_9 * V_10 , int V_156 )
{
struct V_89 * V_137 ;
int V_62 ;
V_137 = F_82 ( V_10 , V_157 ) ;
if ( V_137 ) {
const struct V_42 * V_43 ;
V_43 = F_129 ( V_41 -> V_43 ) ;
V_62 = F_85 ( V_43 -> V_104 ,
V_43 -> V_83 , V_10 ) ;
if ( ! V_62 )
F_84 ( V_10 , V_137 ) ;
else {
if ( V_156 )
return V_62 ;
F_86 ( V_10 , V_137 ) ;
}
} else if ( V_156 ) {
return - V_151 ;
}
return 0 ;
}
static int F_130 ( const struct V_40 * V_41 , int V_16 ,
struct V_9 * V_10 , T_3 V_52 ,
T_3 V_158 , T_3 V_57 , V_154 V_50 , T_3 V_140 )
{
const int V_156 = V_10 -> V_87 ;
struct V_79 * V_79 ;
int V_62 ;
V_79 = F_77 ( V_10 , V_52 , V_158 , & V_159 ,
V_57 , V_50 ) ;
if ( ! V_79 )
return - V_151 ;
V_79 -> V_16 = V_16 ;
V_62 = F_131 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_115 ( & V_41 -> V_160 , V_140 ) ) {
V_62 = F_132 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
}
if ( F_117 ( V_140 ) ) {
V_62 = F_133 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
}
V_62 = F_121 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_118 ( V_140 ) ) {
V_62 = F_128 ( V_41 , V_10 , V_156 ) ;
if ( V_62 )
goto error;
}
F_134 ( V_10 , V_79 ) ;
return 0 ;
error:
F_135 ( V_10 , V_79 ) ;
return V_62 ;
}
static struct V_9 * F_136 ( const struct V_42 * V_116 ,
const struct V_138 * V_139 ,
struct V_3 * V_4 ,
bool V_161 ,
T_4 V_140 )
{
struct V_9 * V_10 ;
T_5 V_87 ;
if ( ! V_161 && ! F_1 ( & V_159 , V_4 , 0 ) )
return NULL ;
V_87 = F_119 ( V_116 , V_139 , V_140 ) ;
V_10 = F_76 ( V_87 , V_11 ) ;
if ( ! V_10 )
return F_137 ( - V_94 ) ;
return V_10 ;
}
static struct V_9 * F_138 ( const struct V_40 * V_41 ,
int V_16 ,
struct V_3 * V_4 , V_154 V_50 ,
bool V_161 , T_3 V_140 )
{
struct V_9 * V_10 ;
int V_162 ;
V_10 = F_136 ( F_139 ( V_41 -> V_43 ) ,
& V_41 -> V_160 , V_4 , V_161 , V_140 ) ;
if ( F_140 ( V_10 ) )
return V_10 ;
V_162 = F_130 ( V_41 , V_16 , V_10 ,
V_4 -> V_163 , V_4 -> V_164 , 0 ,
V_50 , V_140 ) ;
F_79 ( V_162 < 0 ) ;
return V_10 ;
}
static int F_141 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_95 ( V_10 -> V_113 ) ;
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_40 * V_41 = NULL , * V_165 ;
struct V_166 V_167 ;
struct V_9 * V_168 ;
struct V_14 * V_20 ;
struct V_42 * V_116 ;
struct V_169 V_170 ;
T_3 V_140 = F_142 ( V_114 [ V_171 ] ) ;
int error ;
bool log = ! V_114 [ V_172 ] ;
error = - V_71 ;
if ( ! V_114 [ V_173 ] ) {
F_143 ( log , L_1 ) ;
goto error;
}
if ( ! V_114 [ V_157 ] ) {
F_143 ( log , L_2 ) ;
goto error;
}
V_165 = F_101 () ;
if ( F_35 ( V_165 ) ) {
error = F_61 ( V_165 ) ;
goto error;
}
F_144 ( & V_170 , & V_165 -> V_38 , false , & V_167 ) ;
error = F_145 ( V_15 , & V_170 , V_114 [ V_173 ] ,
V_114 [ V_174 ] , log ) ;
if ( error )
goto V_175;
error = F_146 ( & V_165 -> V_160 , V_114 [ V_176 ] ,
& V_165 -> V_38 , log ) ;
if ( error )
goto V_175;
if ( F_147 ( & V_165 -> V_160 ) )
V_170 . V_38 = V_165 -> V_160 . V_177 ;
F_148 ( & V_165 -> V_38 , & V_165 -> V_38 , true , & V_167 ) ;
error = F_103 ( V_15 , V_114 [ V_157 ] ,
& V_165 -> V_38 , & V_116 , log ) ;
if ( error ) {
F_143 ( log , L_3 ) ;
goto V_175;
}
V_168 = F_136 ( V_116 , & V_165 -> V_160 , V_4 , false ,
V_140 ) ;
if ( F_35 ( V_168 ) ) {
error = F_61 ( V_168 ) ;
goto V_178;
}
F_6 () ;
V_20 = F_15 ( V_15 , V_79 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_92 ;
goto V_179;
}
if ( F_116 ( & V_165 -> V_160 ) )
V_41 = F_149 ( & V_20 -> V_26 , & V_165 -> V_160 ) ;
if ( ! V_41 )
V_41 = F_150 ( & V_20 -> V_26 , & V_165 -> V_38 ) ;
if ( F_151 ( ! V_41 ) ) {
F_104 ( V_165 -> V_43 , V_116 ) ;
error = F_152 ( & V_20 -> V_26 , V_165 , & V_167 ) ;
if ( F_45 ( error ) ) {
V_116 = NULL ;
goto V_179;
}
if ( F_45 ( V_168 ) ) {
error = F_130 ( V_165 ,
V_79 -> V_16 ,
V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 ,
V_180 ,
V_140 ) ;
F_79 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_42 * V_181 ;
if ( F_45 ( V_4 -> V_6 -> V_7 & ( V_182
| V_183 ) ) ) {
error = - V_184 ;
goto V_179;
}
if ( F_45 ( ! F_153 ( V_41 , & V_170 ) ) ) {
if ( F_147 ( & V_41 -> V_160 ) )
V_41 = F_154 ( & V_20 -> V_26 ,
& V_170 ) ;
else
V_41 = NULL ;
if ( ! V_41 ) {
error = - V_185 ;
goto V_179;
}
}
V_181 = F_139 ( V_41 -> V_43 ) ;
F_104 ( V_41 -> V_43 , V_116 ) ;
if ( F_45 ( V_168 ) ) {
error = F_130 ( V_41 ,
V_79 -> V_16 ,
V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 ,
V_180 ,
V_140 ) ;
F_79 ( error < 0 ) ;
}
F_8 () ;
F_155 ( V_181 ) ;
F_107 ( V_165 , false ) ;
}
if ( V_168 )
F_4 ( & V_159 , V_168 , V_4 ) ;
return 0 ;
V_179:
F_8 () ;
F_48 ( V_168 ) ;
V_178:
F_156 ( V_116 ) ;
V_175:
F_107 ( V_165 , false ) ;
error:
return error ;
}
static struct V_42 * F_157 ( struct V_15 * V_15 ,
const struct V_89 * V_114 ,
const struct V_37 * V_38 ,
const struct V_166 * V_167 ,
bool log )
{
struct V_42 * V_116 ;
struct V_37 V_186 ;
int error ;
F_148 ( & V_186 , V_38 , true , V_167 ) ;
error = F_103 ( V_15 , V_114 , & V_186 , & V_116 , log ) ;
if ( error ) {
F_143 ( log ,
L_4 ) ;
return F_137 ( error ) ;
}
return V_116 ;
}
static int F_158 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_95 ( V_10 -> V_113 ) ;
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_37 V_38 ;
struct V_40 * V_41 ;
struct V_166 V_167 ;
struct V_9 * V_168 = NULL ;
struct V_14 * V_20 ;
struct V_42 * V_181 = NULL , * V_116 = NULL ;
struct V_169 V_170 ;
struct V_138 V_139 ;
T_3 V_140 = F_142 ( V_114 [ V_171 ] ) ;
int error = 0 ;
bool log = ! V_114 [ V_172 ] ;
bool V_187 ;
V_187 = F_159 ( & V_139 , V_114 [ V_176 ] , log ) ;
if ( V_114 [ V_173 ] ) {
F_144 ( & V_170 , & V_38 , true , & V_167 ) ;
error = F_145 ( V_15 , & V_170 , V_114 [ V_173 ] ,
V_114 [ V_174 ] , log ) ;
} else if ( ! V_187 ) {
F_143 ( log ,
L_5 ) ;
error = - V_71 ;
}
if ( error )
goto error;
if ( V_114 [ V_157 ] ) {
if ( ! V_114 [ V_173 ] ) {
F_143 ( log ,
L_6 ) ;
error = - V_71 ;
goto error;
}
V_116 = F_157 ( V_15 , V_114 [ V_157 ] , & V_38 ,
& V_167 , log ) ;
if ( F_35 ( V_116 ) ) {
error = F_61 ( V_116 ) ;
goto error;
}
V_168 = F_136 ( V_116 , & V_139 , V_4 , false ,
V_140 ) ;
if ( F_35 ( V_168 ) ) {
error = F_61 ( V_168 ) ;
goto V_178;
}
}
F_6 () ;
V_20 = F_15 ( V_15 , V_79 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_92 ;
goto V_179;
}
if ( V_187 )
V_41 = F_149 ( & V_20 -> V_26 , & V_139 ) ;
else
V_41 = F_154 ( & V_20 -> V_26 , & V_170 ) ;
if ( F_45 ( ! V_41 ) ) {
error = - V_185 ;
goto V_179;
}
if ( F_151 ( V_116 ) ) {
V_181 = F_139 ( V_41 -> V_43 ) ;
F_104 ( V_41 -> V_43 , V_116 ) ;
if ( F_45 ( V_168 ) ) {
error = F_130 ( V_41 ,
V_79 -> V_16 ,
V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 ,
V_180 ,
V_140 ) ;
F_79 ( error < 0 ) ;
}
} else {
V_168 = F_138 ( V_41 , V_79 -> V_16 ,
V_4 , V_180 , false ,
V_140 ) ;
if ( F_35 ( V_168 ) ) {
error = F_61 ( V_168 ) ;
goto V_179;
}
}
if ( V_114 [ V_188 ] )
F_160 ( V_41 ) ;
F_8 () ;
if ( V_168 )
F_4 ( & V_159 , V_168 , V_4 ) ;
if ( V_181 )
F_155 ( V_181 ) ;
return 0 ;
V_179:
F_8 () ;
F_48 ( V_168 ) ;
V_178:
F_156 ( V_116 ) ;
error:
return error ;
}
static int F_161 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_15 * V_15 = F_95 ( V_10 -> V_113 ) ;
struct V_37 V_38 ;
struct V_9 * V_168 ;
struct V_40 * V_41 ;
struct V_14 * V_20 ;
struct V_169 V_170 ;
struct V_138 V_189 ;
T_3 V_140 = F_142 ( V_114 [ V_171 ] ) ;
int V_62 = 0 ;
bool log = ! V_114 [ V_172 ] ;
bool V_187 ;
V_187 = F_159 ( & V_189 , V_114 [ V_176 ] , log ) ;
if ( V_114 [ V_173 ] ) {
F_144 ( & V_170 , & V_38 , true , NULL ) ;
V_62 = F_145 ( V_15 , & V_170 , V_114 [ V_173 ] , NULL ,
log ) ;
} else if ( ! V_187 ) {
F_143 ( log ,
L_7 ) ;
V_62 = - V_71 ;
}
if ( V_62 )
return V_62 ;
F_6 () ;
V_20 = F_15 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
if ( ! V_20 ) {
V_62 = - V_92 ;
goto V_190;
}
if ( V_187 )
V_41 = F_149 ( & V_20 -> V_26 , & V_189 ) ;
else
V_41 = F_154 ( & V_20 -> V_26 , & V_170 ) ;
if ( ! V_41 ) {
V_62 = - V_185 ;
goto V_190;
}
V_168 = F_138 ( V_41 , V_79 -> V_16 , V_4 ,
V_180 , true , V_140 ) ;
if ( F_35 ( V_168 ) ) {
V_62 = F_61 ( V_168 ) ;
goto V_190;
}
F_8 () ;
return F_162 ( V_168 , V_4 ) ;
V_190:
F_8 () ;
return V_62 ;
}
static int F_163 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_15 * V_15 = F_95 ( V_10 -> V_113 ) ;
struct V_37 V_38 ;
struct V_9 * V_168 ;
struct V_40 * V_41 = NULL ;
struct V_14 * V_20 ;
struct V_169 V_170 ;
struct V_138 V_189 ;
T_3 V_140 = F_142 ( V_114 [ V_171 ] ) ;
int V_62 ;
bool log = ! V_114 [ V_172 ] ;
bool V_187 ;
V_187 = F_159 ( & V_189 , V_114 [ V_176 ] , log ) ;
if ( V_114 [ V_173 ] ) {
F_144 ( & V_170 , & V_38 , true , NULL ) ;
V_62 = F_145 ( V_15 , & V_170 , V_114 [ V_173 ] ,
NULL , log ) ;
if ( F_45 ( V_62 ) )
return V_62 ;
}
F_6 () ;
V_20 = F_15 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
V_62 = - V_92 ;
goto V_190;
}
if ( F_45 ( ! V_114 [ V_173 ] && ! V_187 ) ) {
V_62 = F_164 ( & V_20 -> V_26 ) ;
goto V_190;
}
if ( V_187 )
V_41 = F_149 ( & V_20 -> V_26 , & V_189 ) ;
else
V_41 = F_154 ( & V_20 -> V_26 , & V_170 ) ;
if ( F_45 ( ! V_41 ) ) {
V_62 = - V_185 ;
goto V_190;
}
F_165 ( & V_20 -> V_26 , V_41 ) ;
F_8 () ;
V_168 = F_136 ( ( const struct V_42 V_191 * ) V_41 -> V_43 ,
& V_41 -> V_160 , V_4 , false , V_140 ) ;
if ( F_151 ( V_168 ) ) {
if ( F_151 ( ! F_35 ( V_168 ) ) ) {
F_18 () ;
V_62 = F_130 ( V_41 , V_79 -> V_16 ,
V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 ,
V_192 ,
V_140 ) ;
F_19 () ;
F_79 ( V_62 < 0 ) ;
F_4 ( & V_159 , V_168 , V_4 ) ;
} else {
F_166 ( F_95 ( V_10 -> V_113 ) -> V_193 , 0 , 0 , F_61 ( V_168 ) ) ;
}
}
F_107 ( V_41 , true ) ;
return 0 ;
V_190:
F_8 () ;
return V_62 ;
}
static int F_167 ( struct V_9 * V_10 , struct V_194 * V_195 )
{
struct V_89 * V_114 [ V_196 ] ;
struct V_79 * V_79 = F_168 ( F_169 ( V_195 -> V_197 ) ) ;
struct V_198 * V_199 ;
struct V_14 * V_20 ;
T_3 V_140 ;
int V_62 ;
V_62 = F_170 ( V_195 -> V_197 , & V_159 , V_114 ,
V_200 , V_201 ) ;
if ( V_62 )
return V_62 ;
V_140 = F_142 ( V_114 [ V_171 ] ) ;
F_18 () ;
V_20 = F_12 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_92 ;
}
V_199 = F_51 ( V_20 -> V_26 . V_199 ) ;
for (; ; ) {
struct V_40 * V_41 ;
T_3 V_202 , V_203 ;
V_202 = V_195 -> args [ 0 ] ;
V_203 = V_195 -> args [ 1 ] ;
V_41 = F_171 ( V_199 , & V_202 , & V_203 ) ;
if ( ! V_41 )
break;
if ( F_130 ( V_41 , V_79 -> V_16 , V_10 ,
F_172 ( V_195 -> V_10 ) . V_52 ,
V_195 -> V_197 -> V_204 , V_205 ,
V_180 , V_140 ) < 0 )
break;
V_195 -> args [ 0 ] = V_202 ;
V_195 -> args [ 1 ] = V_203 ;
}
F_19 () ;
return V_10 -> V_87 ;
}
static T_5 F_173 ( void )
{
T_5 V_206 = F_63 ( sizeof( struct V_79 ) ) ;
V_206 += F_64 ( V_207 ) ;
V_206 += F_120 ( sizeof( struct V_129 ) ) ;
V_206 += F_120 ( sizeof( struct V_130 ) ) ;
V_206 += F_64 ( sizeof( T_3 ) ) ;
return V_206 ;
}
static int F_174 ( struct V_14 * V_20 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_158 , T_3 V_57 , V_154 V_50 )
{
struct V_79 * V_79 ;
struct V_129 V_208 ;
struct V_130 V_209 ;
int V_62 ;
V_79 = F_77 ( V_10 , V_52 , V_158 , & V_210 ,
V_57 , V_50 ) ;
if ( ! V_79 )
goto error;
V_79 -> V_16 = F_23 ( V_20 ) ;
V_62 = F_175 ( V_10 , V_211 , F_20 ( V_20 ) ) ;
if ( V_62 )
goto V_212;
F_108 ( V_20 , & V_208 , & V_209 ) ;
if ( F_125 ( V_10 , V_213 , sizeof( struct V_129 ) ,
& V_208 , V_214 ) )
goto V_212;
if ( F_125 ( V_10 , V_215 ,
sizeof( struct V_130 ) ,
& V_209 , V_214 ) )
goto V_212;
if ( F_88 ( V_10 , V_216 , V_20 -> V_84 ) )
goto V_212;
F_134 ( V_10 , V_79 ) ;
return 0 ;
V_212:
F_135 ( V_10 , V_79 ) ;
error:
return - V_151 ;
}
static struct V_9 * F_176 ( void )
{
return F_76 ( F_173 () , V_11 ) ;
}
static struct V_14 * F_177 ( struct V_15 * V_15 ,
const struct V_79 * V_79 ,
struct V_89 * V_114 [ V_217 + 1 ] )
{
struct V_14 * V_20 ;
if ( ! V_114 [ V_211 ] )
V_20 = F_15 ( V_15 , V_79 -> V_16 ) ;
else {
struct V_19 * V_19 ;
V_19 = F_178 ( V_15 , F_81 ( V_114 [ V_211 ] ) ) ;
V_20 = V_19 && V_19 -> V_30 == V_21 ? V_19 -> V_20 : NULL ;
}
return V_20 ? V_20 : F_137 ( - V_92 ) ;
}
static void F_179 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_14 * V_20 ;
V_20 = F_177 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_4 -> V_115 ) ;
if ( F_35 ( V_20 ) )
return;
F_180 ( V_20 -> V_84 , L_8 ) ;
V_20 -> V_84 = 0 ;
}
static void F_181 ( struct V_14 * V_20 , struct V_89 * V_114 [] )
{
if ( V_114 [ V_216 ] )
V_20 -> V_84 = F_182 ( V_114 [ V_216 ] ) ;
}
static int F_183 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_33 V_34 ;
struct V_9 * V_168 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
struct V_218 * V_218 ;
int V_62 , V_132 ;
V_62 = - V_71 ;
if ( ! V_114 [ V_211 ] || ! V_114 [ V_219 ] )
goto V_62;
V_168 = F_176 () ;
if ( ! V_168 )
return - V_94 ;
V_62 = - V_94 ;
V_20 = F_184 ( sizeof( * V_20 ) , V_11 ) ;
if ( V_20 == NULL )
goto V_220;
F_185 ( V_20 , F_95 ( V_10 -> V_113 ) ) ;
V_62 = F_186 ( & V_20 -> V_26 ) ;
if ( V_62 )
goto V_221;
V_20 -> V_27 = F_187 ( struct V_44 ) ;
if ( ! V_20 -> V_27 ) {
V_62 = - V_94 ;
goto V_222;
}
V_20 -> V_28 = F_188 ( V_31 * sizeof( struct V_29 ) ,
V_11 ) ;
if ( ! V_20 -> V_28 ) {
V_62 = - V_94 ;
goto V_223;
}
for ( V_132 = 0 ; V_132 < V_31 ; V_132 ++ )
F_189 ( & V_20 -> V_28 [ V_132 ] ) ;
V_34 . V_224 = F_81 ( V_114 [ V_211 ] ) ;
V_34 . type = V_225 ;
V_34 . V_226 = NULL ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_21 ;
V_34 . V_227 = V_114 [ V_219 ] ;
F_181 ( V_20 , V_114 ) ;
F_6 () ;
V_19 = F_33 ( & V_34 ) ;
if ( F_35 ( V_19 ) ) {
V_62 = F_61 ( V_19 ) ;
if ( V_62 == - V_228 )
V_62 = - V_184 ;
if ( V_62 == - V_184 ) {
if ( V_4 -> V_229 -> V_230 < V_231 )
F_179 ( V_10 , V_4 ) ;
}
goto V_232;
}
V_62 = F_174 ( V_20 , V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 , V_233 ) ;
F_79 ( V_62 < 0 ) ;
V_218 = F_190 ( F_92 ( V_20 ) , V_234 ) ;
F_191 ( & V_20 -> V_235 , & V_218 -> V_236 ) ;
F_8 () ;
F_4 ( & V_210 , V_168 , V_4 ) ;
return 0 ;
V_232:
F_8 () ;
F_29 ( V_20 -> V_28 ) ;
V_223:
F_28 ( V_20 -> V_27 ) ;
V_222:
F_27 ( & V_20 -> V_26 ) ;
V_221:
F_29 ( V_20 ) ;
V_220:
F_48 ( V_168 ) ;
V_62:
return V_62 ;
}
static void F_192 ( struct V_14 * V_20 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < V_31 ; V_132 ++ ) {
struct V_19 * V_19 ;
struct V_237 * V_238 ;
F_193 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_19 -> V_30 != V_21 )
F_37 ( V_19 ) ;
}
F_194 ( & V_20 -> V_235 ) ;
F_37 ( F_195 ( V_20 , V_21 ) ) ;
F_196 ( & V_20 -> V_25 , F_25 ) ;
}
static int F_197 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_168 ;
struct V_14 * V_20 ;
int V_62 ;
V_168 = F_176 () ;
if ( ! V_168 )
return - V_94 ;
F_6 () ;
V_20 = F_177 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_4 -> V_115 ) ;
V_62 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_239;
V_62 = F_174 ( V_20 , V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 , V_240 ) ;
F_79 ( V_62 < 0 ) ;
F_192 ( V_20 ) ;
F_8 () ;
F_4 ( & V_210 , V_168 , V_4 ) ;
return 0 ;
V_239:
F_8 () ;
F_48 ( V_168 ) ;
return V_62 ;
}
static int F_198 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_168 ;
struct V_14 * V_20 ;
int V_62 ;
V_168 = F_176 () ;
if ( ! V_168 )
return - V_94 ;
F_6 () ;
V_20 = F_177 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_4 -> V_115 ) ;
V_62 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_239;
F_181 ( V_20 , V_4 -> V_115 ) ;
V_62 = F_174 ( V_20 , V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 , V_233 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_210 , V_168 , V_4 ) ;
return 0 ;
V_239:
F_8 () ;
F_48 ( V_168 ) ;
return V_62 ;
}
static int F_199 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_168 ;
struct V_14 * V_20 ;
int V_62 ;
V_168 = F_176 () ;
if ( ! V_168 )
return - V_94 ;
F_6 () ;
V_20 = F_177 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_4 -> V_115 ) ;
if ( F_35 ( V_20 ) ) {
V_62 = F_61 ( V_20 ) ;
goto V_239;
}
V_62 = F_174 ( V_20 , V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 , V_233 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
return F_162 ( V_168 , V_4 ) ;
V_239:
F_8 () ;
F_48 ( V_168 ) ;
return V_62 ;
}
static int F_200 ( struct V_9 * V_10 , struct V_194 * V_195 )
{
struct V_218 * V_218 = F_190 ( F_95 ( V_10 -> V_113 ) , V_234 ) ;
struct V_14 * V_20 ;
int V_241 = V_195 -> args [ 0 ] ;
int V_132 = 0 ;
F_6 () ;
F_201 (dp, &ovs_net->dps, list_node) {
if ( V_132 >= V_241 &&
F_174 ( V_20 , V_10 , F_172 ( V_195 -> V_10 ) . V_52 ,
V_195 -> V_197 -> V_204 , V_205 ,
V_233 ) < 0 )
break;
V_132 ++ ;
}
F_8 () ;
V_195 -> args [ 0 ] = V_132 ;
return V_10 -> V_87 ;
}
static int F_202 ( struct V_19 * V_19 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_158 , T_3 V_57 , V_154 V_50 )
{
struct V_79 * V_79 ;
struct V_242 V_243 ;
int V_62 ;
V_79 = F_77 ( V_10 , V_52 , V_158 , & V_244 ,
V_57 , V_50 ) ;
if ( ! V_79 )
return - V_151 ;
V_79 -> V_16 = F_23 ( V_19 -> V_20 ) ;
if ( F_88 ( V_10 , V_245 , V_19 -> V_30 ) ||
F_88 ( V_10 , V_246 , V_19 -> V_247 -> type ) ||
F_175 ( V_10 , V_248 ,
F_22 ( V_19 ) ) )
goto V_212;
F_203 ( V_19 , & V_243 ) ;
if ( F_125 ( V_10 , V_249 ,
sizeof( struct V_242 ) , & V_243 ,
V_250 ) )
goto V_212;
if ( F_204 ( V_19 , V_10 ) )
goto V_212;
V_62 = F_205 ( V_19 , V_10 ) ;
if ( V_62 == - V_151 )
goto error;
F_134 ( V_10 , V_79 ) ;
return 0 ;
V_212:
V_62 = - V_151 ;
error:
F_135 ( V_10 , V_79 ) ;
return V_62 ;
}
static struct V_9 * F_206 ( void )
{
return F_207 ( V_251 , V_11 ) ;
}
struct V_9 * F_208 ( struct V_19 * V_19 , T_3 V_52 ,
T_3 V_158 , V_154 V_50 )
{
struct V_9 * V_10 ;
int V_162 ;
V_10 = F_207 ( V_251 , V_93 ) ;
if ( ! V_10 )
return F_137 ( - V_94 ) ;
V_162 = F_202 ( V_19 , V_10 , V_52 , V_158 , 0 , V_50 ) ;
F_79 ( V_162 < 0 ) ;
return V_10 ;
}
static struct V_19 * F_209 ( struct V_15 * V_15 ,
const struct V_79 * V_79 ,
struct V_89 * V_114 [ V_252 + 1 ] )
{
struct V_14 * V_20 ;
struct V_19 * V_19 ;
if ( V_114 [ V_248 ] ) {
V_19 = F_178 ( V_15 , F_81 ( V_114 [ V_248 ] ) ) ;
if ( ! V_19 )
return F_137 ( - V_92 ) ;
if ( V_79 -> V_16 &&
V_79 -> V_16 != F_23 ( V_19 -> V_20 ) )
return F_137 ( - V_92 ) ;
return V_19 ;
} else if ( V_114 [ V_245 ] ) {
T_3 V_30 = F_182 ( V_114 [ V_245 ] ) ;
if ( V_30 >= V_253 )
return F_137 ( - V_96 ) ;
V_20 = F_15 ( V_15 , V_79 -> V_16 ) ;
if ( ! V_20 )
return F_137 ( - V_92 ) ;
V_19 = F_21 ( V_20 , V_30 ) ;
if ( ! V_19 )
return F_137 ( - V_92 ) ;
return V_19 ;
} else
return F_137 ( - V_71 ) ;
}
static void F_210 ( struct V_14 * V_20 )
{
unsigned V_254 , V_255 = 0 ;
struct V_17 * V_18 ;
struct V_19 * V_19 ;
int V_132 ;
for ( V_132 = 0 ; V_132 < V_31 ; V_132 ++ ) {
F_32 (vport, &dp->ports[i], dp_hash_node) {
V_18 = V_19 -> V_18 ;
V_254 = F_211 ( V_18 ) ;
if ( V_254 > V_255 )
V_255 = V_254 ;
}
}
V_20 -> V_255 = V_255 ;
for ( V_132 = 0 ; V_132 < V_31 ; V_132 ++ )
F_32 (vport, &dp->ports[i], dp_hash_node)
F_212 ( V_19 -> V_18 , V_255 ) ;
}
static int F_213 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_33 V_34 ;
struct V_9 * V_168 ;
struct V_19 * V_19 ;
struct V_14 * V_20 ;
T_3 V_30 ;
int V_62 ;
if ( ! V_114 [ V_248 ] || ! V_114 [ V_246 ] ||
! V_114 [ V_256 ] )
return - V_71 ;
V_30 = V_114 [ V_245 ]
? F_182 ( V_114 [ V_245 ] ) : 0 ;
if ( V_30 >= V_253 )
return - V_96 ;
V_168 = F_206 () ;
if ( ! V_168 )
return - V_94 ;
F_6 () ;
V_257:
V_20 = F_15 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
V_62 = - V_92 ;
if ( ! V_20 )
goto V_258;
if ( V_30 ) {
V_19 = F_195 ( V_20 , V_30 ) ;
V_62 = - V_228 ;
if ( V_19 )
goto V_258;
} else {
for ( V_30 = 1 ; ; V_30 ++ ) {
if ( V_30 >= V_253 ) {
V_62 = - V_96 ;
goto V_258;
}
V_19 = F_195 ( V_20 , V_30 ) ;
if ( ! V_19 )
break;
}
}
V_34 . V_224 = F_81 ( V_114 [ V_248 ] ) ;
V_34 . type = F_182 ( V_114 [ V_246 ] ) ;
V_34 . V_226 = V_114 [ V_259 ] ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_30 ;
V_34 . V_227 = V_114 [ V_256 ] ;
V_19 = F_33 ( & V_34 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) ) {
if ( V_62 == - V_260 )
goto V_257;
goto V_258;
}
V_62 = F_202 ( V_19 , V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 , V_261 ) ;
if ( F_211 ( V_19 -> V_18 ) > V_20 -> V_255 )
F_210 ( V_20 ) ;
else
F_212 ( V_19 -> V_18 , V_20 -> V_255 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_244 , V_168 , V_4 ) ;
return 0 ;
V_258:
F_8 () ;
F_48 ( V_168 ) ;
return V_62 ;
}
static int F_214 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_9 * V_168 ;
struct V_19 * V_19 ;
int V_62 ;
V_168 = F_206 () ;
if ( ! V_168 )
return - V_94 ;
F_6 () ;
V_19 = F_209 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_114 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_258;
if ( V_114 [ V_246 ] &&
F_182 ( V_114 [ V_246 ] ) != V_19 -> V_247 -> type ) {
V_62 = - V_71 ;
goto V_258;
}
if ( V_114 [ V_259 ] ) {
V_62 = F_215 ( V_19 , V_114 [ V_259 ] ) ;
if ( V_62 )
goto V_258;
}
if ( V_114 [ V_256 ] ) {
struct V_89 * V_262 = V_114 [ V_256 ] ;
V_62 = F_216 ( V_19 , V_262 ) ;
if ( V_62 )
goto V_258;
}
V_62 = F_202 ( V_19 , V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 , V_261 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_244 , V_168 , V_4 ) ;
return 0 ;
V_258:
F_8 () ;
F_48 ( V_168 ) ;
return V_62 ;
}
static int F_217 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
bool V_263 = false ;
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_9 * V_168 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
int V_62 ;
V_168 = F_206 () ;
if ( ! V_168 )
return - V_94 ;
F_6 () ;
V_19 = F_209 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_114 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_258;
if ( V_19 -> V_30 == V_21 ) {
V_62 = - V_71 ;
goto V_258;
}
V_62 = F_202 ( V_19 , V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 , V_264 ) ;
F_79 ( V_62 < 0 ) ;
V_20 = V_19 -> V_20 ;
if ( F_211 ( V_19 -> V_18 ) == V_20 -> V_255 )
V_263 = true ;
F_218 ( V_19 -> V_18 ) ;
F_37 ( V_19 ) ;
if ( V_263 )
F_210 ( V_20 ) ;
F_8 () ;
F_4 ( & V_244 , V_168 , V_4 ) ;
return 0 ;
V_258:
F_8 () ;
F_48 ( V_168 ) ;
return V_62 ;
}
static int F_219 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_9 * V_168 ;
struct V_19 * V_19 ;
int V_62 ;
V_168 = F_206 () ;
if ( ! V_168 )
return - V_94 ;
F_18 () ;
V_19 = F_209 ( F_95 ( V_10 -> V_113 ) , V_79 , V_114 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_258;
V_62 = F_202 ( V_19 , V_168 , V_4 -> V_163 ,
V_4 -> V_164 , 0 , V_261 ) ;
F_79 ( V_62 < 0 ) ;
F_19 () ;
return F_162 ( V_168 , V_4 ) ;
V_258:
F_19 () ;
F_48 ( V_168 ) ;
return V_62 ;
}
static int F_220 ( struct V_9 * V_10 , struct V_194 * V_195 )
{
struct V_79 * V_79 = F_168 ( F_169 ( V_195 -> V_197 ) ) ;
struct V_14 * V_20 ;
int V_202 = V_195 -> args [ 0 ] , V_241 = V_195 -> args [ 1 ] ;
int V_132 , V_265 = 0 ;
F_18 () ;
V_20 = F_12 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_92 ;
}
for ( V_132 = V_202 ; V_132 < V_31 ; V_132 ++ ) {
struct V_19 * V_19 ;
V_265 = 0 ;
F_32 (vport, &dp->ports[i], dp_hash_node) {
if ( V_265 >= V_241 &&
F_202 ( V_19 , V_10 ,
F_172 ( V_195 -> V_10 ) . V_52 ,
V_195 -> V_197 -> V_204 ,
V_205 ,
V_261 ) < 0 )
goto V_55;
V_265 ++ ;
}
V_241 = 0 ;
}
V_55:
F_19 () ;
V_195 -> args [ 0 ] = V_132 ;
V_195 -> args [ 1 ] = V_265 ;
return V_10 -> V_87 ;
}
static void F_221 ( int V_266 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < V_266 ; V_132 ++ )
F_222 ( V_267 [ V_132 ] ) ;
}
static int T_7 F_223 ( void )
{
int V_62 ;
int V_132 ;
for ( V_132 = 0 ; V_132 < F_224 ( V_267 ) ; V_132 ++ ) {
V_62 = F_225 ( V_267 [ V_132 ] ) ;
if ( V_62 )
goto error;
}
return 0 ;
error:
F_221 ( V_132 ) ;
return V_62 ;
}
static int T_8 F_226 ( struct V_15 * V_15 )
{
struct V_218 * V_218 = F_190 ( V_15 , V_234 ) ;
F_227 ( & V_218 -> V_236 ) ;
F_228 ( & V_218 -> V_268 , V_269 ) ;
F_229 ( V_15 ) ;
return 0 ;
}
static void T_9 F_230 ( struct V_15 * V_15 , struct V_15 * V_270 ,
struct V_271 * V_32 )
{
struct V_218 * V_218 = F_190 ( V_15 , V_234 ) ;
struct V_14 * V_20 ;
F_201 (dp, &ovs_net->dps, list_node) {
int V_132 ;
for ( V_132 = 0 ; V_132 < V_31 ; V_132 ++ ) {
struct V_19 * V_19 ;
F_231 (vport, &dp->ports[i], dp_hash_node) {
if ( V_19 -> V_247 -> type != V_225 )
continue;
if ( F_232 ( V_19 -> V_18 ) == V_270 )
F_233 ( & V_19 -> V_272 , V_32 ) ;
}
}
}
}
static void T_9 F_234 ( struct V_15 * V_270 )
{
struct V_14 * V_20 , * V_273 ;
struct V_218 * V_218 = F_190 ( V_270 , V_234 ) ;
struct V_19 * V_19 , * V_274 ;
struct V_15 * V_15 ;
F_235 ( V_32 ) ;
F_236 ( V_270 ) ;
F_6 () ;
F_237 (dp, dp_next, &ovs_net->dps, list_node)
F_192 ( V_20 ) ;
F_238 () ;
F_239 (net)
F_230 ( V_15 , V_270 , & V_32 ) ;
F_240 () ;
F_237 (vport, vport_next, &head, detach_list) {
F_241 ( & V_19 -> V_272 ) ;
F_37 ( V_19 ) ;
}
F_8 () ;
F_242 ( & V_218 -> V_268 ) ;
}
static int T_7 F_243 ( void )
{
int V_62 ;
F_59 ( sizeof( struct V_275 ) > F_244 ( struct V_9 , V_195 ) ) ;
F_245 ( L_9 ) ;
V_62 = F_246 () ;
if ( V_62 )
goto error;
V_62 = F_247 () ;
if ( V_62 )
goto V_276;
V_62 = F_248 () ;
if ( V_62 )
goto V_277;
V_62 = F_249 () ;
if ( V_62 )
goto V_278;
V_62 = F_250 ( & V_279 ) ;
if ( V_62 )
goto V_280;
V_62 = F_251 ( & V_281 ) ;
if ( V_62 )
goto V_282;
V_62 = F_252 () ;
if ( V_62 )
goto V_283;
V_62 = F_223 () ;
if ( V_62 < 0 )
goto V_284;
return 0 ;
V_284:
F_253 () ;
V_283:
F_254 ( & V_281 ) ;
V_282:
F_255 ( & V_279 ) ;
V_280:
F_256 () ;
V_278:
F_257 () ;
V_277:
F_258 () ;
V_276:
F_259 () ;
error:
return V_62 ;
}
static void F_260 ( void )
{
F_221 ( F_224 ( V_267 ) ) ;
F_253 () ;
F_254 ( & V_281 ) ;
F_255 ( & V_279 ) ;
F_261 () ;
F_256 () ;
F_257 () ;
F_258 () ;
F_259 () ;
}
