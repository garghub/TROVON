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
unsigned int V_77 , int V_78 )
{
T_5 V_79 = F_63 ( sizeof( struct V_80 ) )
+ F_64 ( V_77 )
+ F_64 ( F_65 () )
+ F_64 ( sizeof( unsigned int ) ) ;
if ( V_60 -> V_81 )
V_79 += F_66 ( V_60 -> V_81 -> V_82 ) ;
if ( V_60 -> V_83 )
V_79 += F_64 ( F_67 () ) ;
if ( V_60 -> V_84 )
V_79 += F_64 ( V_78 ) ;
if ( V_60 -> V_53 )
V_79 += F_64 ( sizeof( V_60 -> V_53 ) ) ;
return V_79 ;
}
static void F_68 ( struct V_14 * V_20 , struct V_9 * V_10 )
{
if ( ! ( V_20 -> V_85 & V_86 ) ) {
T_5 V_87 = F_66 ( V_10 -> V_88 ) - V_10 -> V_88 ;
if ( V_87 > 0 )
F_69 ( V_10 , V_87 ) ;
}
}
static int F_56 ( struct V_14 * V_20 , struct V_9 * V_10 ,
const struct V_37 * V_38 ,
const struct V_48 * V_60 ,
T_4 V_61 )
{
struct V_80 * V_49 ;
struct V_9 * V_68 = NULL ;
struct V_9 * V_89 = NULL ;
struct V_90 * V_91 ;
T_5 V_88 ;
unsigned int V_92 ;
int V_62 , V_16 ;
V_16 = F_23 ( V_20 ) ;
if ( ! V_16 )
return - V_93 ;
if ( F_70 ( V_10 ) ) {
V_68 = F_71 ( V_10 , V_94 ) ;
if ( ! V_68 )
return - V_95 ;
V_68 = F_72 ( V_68 ) ;
if ( ! V_68 )
return - V_95 ;
V_10 = V_68 ;
}
if ( F_73 ( V_10 -> V_88 ) > V_96 ) {
V_62 = - V_97 ;
goto V_55;
}
if ( V_10 -> V_98 == V_99 &&
( V_62 = F_74 ( V_10 , 0 ) ) )
goto V_55;
if ( V_20 -> V_85 & V_86 )
V_92 = F_75 ( V_10 ) ;
else
V_92 = V_10 -> V_88 ;
V_88 = F_62 ( V_60 , V_92 - V_61 ,
F_42 ( V_10 ) -> V_100 ) ;
V_89 = F_76 ( V_88 , V_94 ) ;
if ( ! V_89 ) {
V_62 = - V_95 ;
goto V_55;
}
V_49 = F_77 ( V_89 , 0 , 0 , & V_101 ,
0 , V_60 -> V_50 ) ;
V_49 -> V_16 = V_16 ;
V_62 = F_78 ( V_38 , V_38 , V_102 , false , V_89 ) ;
F_79 ( V_62 ) ;
if ( V_60 -> V_81 )
F_80 ( V_89 , V_103 ,
V_82 ( V_60 -> V_81 ) ,
F_81 ( V_60 -> V_81 ) ) ;
if ( V_60 -> V_83 ) {
V_91 = F_82 ( V_89 , V_104 ) ;
V_62 = F_83 ( V_89 ,
V_60 -> V_83 ) ;
F_79 ( V_62 ) ;
F_84 ( V_89 , V_91 ) ;
}
if ( V_60 -> V_84 ) {
V_91 = F_82 ( V_89 , V_105 ) ;
V_62 = F_85 ( V_60 -> V_106 ,
V_60 -> V_84 ,
V_89 ) ;
if ( ! V_62 )
F_84 ( V_89 , V_91 ) ;
else
F_86 ( V_89 , V_91 ) ;
}
if ( V_60 -> V_53 ) {
if ( F_87 ( V_89 , V_107 ,
V_60 -> V_53 ) ) {
V_62 = - V_108 ;
goto V_55;
}
F_68 ( V_20 , V_89 ) ;
}
if ( V_61 > 0 ) {
if ( F_88 ( V_89 , V_109 ,
V_10 -> V_88 ) ) {
V_62 = - V_108 ;
goto V_55;
}
F_68 ( V_20 , V_89 ) ;
}
if ( ! ( V_91 = F_89 ( V_89 , V_110 , 0 ) ) ) {
V_62 = - V_108 ;
goto V_55;
}
V_91 -> V_82 = F_73 ( V_10 -> V_88 - V_61 ) ;
V_62 = F_90 ( V_89 , V_10 , V_10 -> V_88 - V_61 , V_92 ) ;
if ( V_62 )
goto V_55;
F_68 ( V_20 , V_89 ) ;
( (struct V_111 * ) V_89 -> V_112 ) -> V_113 = V_89 -> V_88 ;
V_62 = F_91 ( F_92 ( V_20 ) , V_89 , V_60 -> V_52 ) ;
V_89 = NULL ;
V_55:
if ( V_62 )
F_93 ( V_10 ) ;
F_48 ( V_89 ) ;
F_48 ( V_68 ) ;
return V_62 ;
}
static int F_94 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_15 * V_15 = F_95 ( V_10 -> V_115 ) ;
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_42 * V_118 ;
struct V_9 * V_119 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_14 * V_20 ;
struct V_19 * V_39 ;
T_1 V_53 = 0 ;
int V_88 ;
int V_62 ;
bool log = ! V_116 [ V_120 ] ;
V_62 = - V_71 ;
if ( ! V_116 [ V_110 ] || ! V_116 [ V_102 ] ||
! V_116 [ V_105 ] )
goto V_62;
V_88 = V_82 ( V_116 [ V_110 ] ) ;
V_119 = F_96 ( V_121 + V_88 , V_11 ) ;
V_62 = - V_95 ;
if ( ! V_119 )
goto V_62;
F_97 ( V_119 , V_121 ) ;
F_98 ( F_99 ( V_119 , V_88 ) , V_116 [ V_110 ] , V_88 ) ;
if ( V_116 [ V_107 ] ) {
V_53 = F_100 ( V_116 [ V_107 ] ) ;
V_119 -> V_122 = 1 ;
}
F_42 ( V_119 ) -> V_53 = V_53 ;
V_41 = F_101 () ;
V_62 = F_61 ( V_41 ) ;
if ( F_35 ( V_41 ) )
goto V_123;
V_62 = F_102 ( V_15 , V_116 [ V_102 ] ,
V_119 , & V_41 -> V_38 , log ) ;
if ( V_62 )
goto V_124;
V_62 = F_103 ( V_15 , V_116 [ V_105 ] ,
& V_41 -> V_38 , & V_118 , log ) ;
if ( V_62 )
goto V_124;
F_104 ( V_41 -> V_43 , V_118 ) ;
V_119 -> V_125 = V_41 -> V_38 . V_126 . V_125 ;
V_119 -> V_127 = V_41 -> V_38 . V_126 . V_128 ;
F_18 () ;
V_20 = F_12 ( V_15 , V_80 -> V_16 ) ;
V_62 = - V_93 ;
if ( ! V_20 )
goto V_129;
V_39 = F_24 ( V_20 , V_41 -> V_38 . V_126 . V_130 ) ;
if ( ! V_39 )
V_39 = F_24 ( V_20 , V_21 ) ;
if ( ! V_39 )
goto V_129;
V_119 -> V_18 = V_39 -> V_18 ;
F_42 ( V_119 ) -> V_39 = V_39 ;
V_43 = F_51 ( V_41 -> V_43 ) ;
F_105 () ;
V_62 = F_52 ( V_20 , V_119 , V_43 , & V_41 -> V_38 ) ;
F_106 () ;
F_19 () ;
F_107 ( V_41 , false ) ;
return V_62 ;
V_129:
F_19 () ;
V_124:
F_107 ( V_41 , false ) ;
V_123:
F_48 ( V_119 ) ;
V_62:
return V_62 ;
}
static void F_108 ( const struct V_14 * V_20 , struct V_131 * V_45 ,
struct V_132 * V_133 )
{
int V_134 ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_45 -> V_135 = F_109 ( & V_20 -> V_26 ) ;
V_133 -> V_136 = F_110 ( & V_20 -> V_26 ) ;
V_45 -> V_58 = V_45 -> V_54 = V_45 -> V_64 = 0 ;
F_111 (i) {
const struct V_44 * V_137 ;
struct V_44 V_138 ;
unsigned int V_139 ;
V_137 = F_112 ( V_20 -> V_27 , V_134 ) ;
do {
V_139 = F_113 ( & V_137 -> V_59 ) ;
V_138 = * V_137 ;
} while ( F_114 ( & V_137 -> V_59 , V_139 ) );
V_45 -> V_58 += V_138 . V_58 ;
V_45 -> V_54 += V_138 . V_54 ;
V_45 -> V_64 += V_138 . V_64 ;
V_133 -> V_47 += V_138 . V_47 ;
}
}
static bool F_115 ( const struct V_140 * V_141 , T_4 V_142 )
{
return F_116 ( V_141 ) &&
! ( V_142 & V_143 ) ;
}
static bool F_117 ( T_4 V_142 )
{
return ! ( V_142 & V_144 ) ;
}
static bool F_118 ( T_4 V_142 )
{
return ! ( V_142 & V_145 ) ;
}
static T_5 F_119 ( const struct V_42 * V_118 ,
const struct V_140 * V_141 ,
T_4 V_142 )
{
T_5 V_88 = F_63 ( sizeof( struct V_80 ) ) ;
if ( V_141 && F_116 ( V_141 ) )
V_88 += F_64 ( V_141 -> V_146 ) ;
if ( ! V_141 || F_115 ( V_141 , V_142 ) )
V_88 += F_64 ( F_65 () ) ;
if ( F_117 ( V_142 ) )
V_88 += F_64 ( F_65 () ) ;
if ( F_118 ( V_142 ) )
V_88 += F_64 ( V_118 -> V_147 ) ;
return V_88
+ F_120 ( sizeof( struct V_148 ) )
+ F_64 ( 1 )
+ F_120 ( 8 ) ;
}
static int F_121 ( const struct V_40 * V_41 ,
struct V_9 * V_10 )
{
struct V_148 V_45 ;
T_6 V_149 ;
unsigned long V_150 ;
F_122 ( V_41 , & V_45 , & V_150 , & V_149 ) ;
if ( V_150 &&
F_123 ( V_10 , V_151 , F_124 ( V_150 ) ,
V_152 ) )
return - V_153 ;
if ( V_45 . V_154 &&
F_125 ( V_10 , V_155 ,
sizeof( struct V_148 ) , & V_45 ,
V_152 ) )
return - V_153 ;
if ( ( V_156 ) F_126 ( V_149 ) &&
F_127 ( V_10 , V_157 , ( V_156 ) F_126 ( V_149 ) ) )
return - V_153 ;
return 0 ;
}
static int F_128 ( const struct V_40 * V_41 ,
struct V_9 * V_10 , int V_158 )
{
struct V_90 * V_139 ;
int V_62 ;
V_139 = F_82 ( V_10 , V_159 ) ;
if ( V_139 ) {
const struct V_42 * V_43 ;
V_43 = F_129 ( V_41 -> V_43 ) ;
V_62 = F_85 ( V_43 -> V_106 ,
V_43 -> V_84 , V_10 ) ;
if ( ! V_62 )
F_84 ( V_10 , V_139 ) ;
else {
if ( V_158 )
return V_62 ;
F_86 ( V_10 , V_139 ) ;
}
} else if ( V_158 ) {
return - V_153 ;
}
return 0 ;
}
static int F_130 ( const struct V_40 * V_41 , int V_16 ,
struct V_9 * V_10 , T_3 V_52 ,
T_3 V_160 , T_3 V_57 , V_156 V_50 , T_3 V_142 )
{
const int V_158 = V_10 -> V_88 ;
struct V_80 * V_80 ;
int V_62 ;
V_80 = F_77 ( V_10 , V_52 , V_160 , & V_161 ,
V_57 , V_50 ) ;
if ( ! V_80 )
return - V_153 ;
V_80 -> V_16 = V_16 ;
V_62 = F_131 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_115 ( & V_41 -> V_162 , V_142 ) ) {
V_62 = F_132 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
}
if ( F_117 ( V_142 ) ) {
V_62 = F_133 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
}
V_62 = F_121 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_118 ( V_142 ) ) {
V_62 = F_128 ( V_41 , V_10 , V_158 ) ;
if ( V_62 )
goto error;
}
F_134 ( V_10 , V_80 ) ;
return 0 ;
error:
F_135 ( V_10 , V_80 ) ;
return V_62 ;
}
static struct V_9 * F_136 ( const struct V_42 * V_118 ,
const struct V_140 * V_141 ,
struct V_3 * V_4 ,
bool V_163 ,
T_4 V_142 )
{
struct V_9 * V_10 ;
T_5 V_88 ;
if ( ! V_163 && ! F_1 ( & V_161 , V_4 , 0 ) )
return NULL ;
V_88 = F_119 ( V_118 , V_141 , V_142 ) ;
V_10 = F_76 ( V_88 , V_11 ) ;
if ( ! V_10 )
return F_137 ( - V_95 ) ;
return V_10 ;
}
static struct V_9 * F_138 ( const struct V_40 * V_41 ,
int V_16 ,
struct V_3 * V_4 , V_156 V_50 ,
bool V_163 , T_3 V_142 )
{
struct V_9 * V_10 ;
int V_164 ;
V_10 = F_136 ( F_139 ( V_41 -> V_43 ) ,
& V_41 -> V_162 , V_4 , V_163 , V_142 ) ;
if ( F_140 ( V_10 ) )
return V_10 ;
V_164 = F_130 ( V_41 , V_16 , V_10 ,
V_4 -> V_165 , V_4 -> V_166 , 0 ,
V_50 , V_142 ) ;
F_79 ( V_164 < 0 ) ;
return V_10 ;
}
static int F_141 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_95 ( V_10 -> V_115 ) ;
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_40 * V_41 = NULL , * V_167 ;
struct V_168 V_169 ;
struct V_9 * V_170 ;
struct V_14 * V_20 ;
struct V_42 * V_118 ;
struct V_171 V_172 ;
T_3 V_142 = F_142 ( V_116 [ V_173 ] ) ;
int error ;
bool log = ! V_116 [ V_174 ] ;
error = - V_71 ;
if ( ! V_116 [ V_175 ] ) {
F_143 ( log , L_1 ) ;
goto error;
}
if ( ! V_116 [ V_159 ] ) {
F_143 ( log , L_2 ) ;
goto error;
}
V_167 = F_101 () ;
if ( F_35 ( V_167 ) ) {
error = F_61 ( V_167 ) ;
goto error;
}
F_144 ( & V_172 , & V_167 -> V_38 , false , & V_169 ) ;
error = F_145 ( V_15 , & V_172 , V_116 [ V_175 ] ,
V_116 [ V_176 ] , log ) ;
if ( error )
goto V_177;
error = F_146 ( & V_167 -> V_162 , V_116 [ V_178 ] ,
& V_167 -> V_38 , log ) ;
if ( error )
goto V_177;
if ( F_147 ( & V_167 -> V_162 ) )
V_172 . V_38 = V_167 -> V_162 . V_179 ;
F_148 ( & V_167 -> V_38 , & V_167 -> V_38 , true , & V_169 ) ;
error = F_103 ( V_15 , V_116 [ V_159 ] ,
& V_167 -> V_38 , & V_118 , log ) ;
if ( error ) {
F_143 ( log , L_3 ) ;
goto V_177;
}
V_170 = F_136 ( V_118 , & V_167 -> V_162 , V_4 , false ,
V_142 ) ;
if ( F_35 ( V_170 ) ) {
error = F_61 ( V_170 ) ;
goto V_180;
}
F_6 () ;
V_20 = F_15 ( V_15 , V_80 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_93 ;
goto V_181;
}
if ( F_116 ( & V_167 -> V_162 ) )
V_41 = F_149 ( & V_20 -> V_26 , & V_167 -> V_162 ) ;
if ( ! V_41 )
V_41 = F_150 ( & V_20 -> V_26 , & V_167 -> V_38 ) ;
if ( F_151 ( ! V_41 ) ) {
F_104 ( V_167 -> V_43 , V_118 ) ;
error = F_152 ( & V_20 -> V_26 , V_167 , & V_169 ) ;
if ( F_45 ( error ) ) {
V_118 = NULL ;
goto V_181;
}
if ( F_45 ( V_170 ) ) {
error = F_130 ( V_167 ,
V_80 -> V_16 ,
V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 ,
V_182 ,
V_142 ) ;
F_79 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_42 * V_183 ;
if ( F_45 ( V_4 -> V_6 -> V_7 & ( V_184
| V_185 ) ) ) {
error = - V_186 ;
goto V_181;
}
if ( F_45 ( ! F_153 ( V_41 , & V_172 ) ) ) {
if ( F_147 ( & V_41 -> V_162 ) )
V_41 = F_154 ( & V_20 -> V_26 ,
& V_172 ) ;
else
V_41 = NULL ;
if ( ! V_41 ) {
error = - V_187 ;
goto V_181;
}
}
V_183 = F_139 ( V_41 -> V_43 ) ;
F_104 ( V_41 -> V_43 , V_118 ) ;
if ( F_45 ( V_170 ) ) {
error = F_130 ( V_41 ,
V_80 -> V_16 ,
V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 ,
V_182 ,
V_142 ) ;
F_79 ( error < 0 ) ;
}
F_8 () ;
F_155 ( V_183 ) ;
F_107 ( V_167 , false ) ;
}
if ( V_170 )
F_4 ( & V_161 , V_170 , V_4 ) ;
return 0 ;
V_181:
F_8 () ;
F_48 ( V_170 ) ;
V_180:
F_156 ( V_118 ) ;
V_177:
F_107 ( V_167 , false ) ;
error:
return error ;
}
static struct V_42 * F_157 ( struct V_15 * V_15 ,
const struct V_90 * V_116 ,
const struct V_37 * V_38 ,
const struct V_168 * V_169 ,
bool log )
{
struct V_42 * V_118 ;
struct V_37 V_188 ;
int error ;
F_148 ( & V_188 , V_38 , true , V_169 ) ;
error = F_103 ( V_15 , V_116 , & V_188 , & V_118 , log ) ;
if ( error ) {
F_143 ( log ,
L_4 ) ;
return F_137 ( error ) ;
}
return V_118 ;
}
static int F_158 ( struct V_15 * V_15 ,
struct V_171 * V_172 ,
struct V_37 * V_38 ,
struct V_90 * * V_116 ,
struct V_42 * * V_118 ,
bool log )
{
struct V_168 V_169 ;
int error = 0 ;
if ( V_116 [ V_175 ] ) {
F_144 ( V_172 , V_38 , true , & V_169 ) ;
error = F_145 ( V_15 , V_172 , V_116 [ V_175 ] ,
V_116 [ V_176 ] , log ) ;
if ( error )
goto error;
}
if ( V_116 [ V_159 ] ) {
if ( ! V_116 [ V_175 ] ) {
F_143 ( log ,
L_5 ) ;
return - V_71 ;
}
* V_118 = F_157 ( V_15 , V_116 [ V_159 ] , V_38 ,
& V_169 , log ) ;
if ( F_35 ( * V_118 ) ) {
error = F_61 ( * V_118 ) ;
goto error;
}
}
error:
V_172 -> V_169 = NULL ;
return error ;
}
static int F_159 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_95 ( V_10 -> V_115 ) ;
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_37 V_38 ;
struct V_40 * V_41 ;
struct V_9 * V_170 = NULL ;
struct V_14 * V_20 ;
struct V_42 * V_183 = NULL , * V_118 = NULL ;
struct V_171 V_172 ;
struct V_140 V_141 ;
T_3 V_142 = F_142 ( V_116 [ V_173 ] ) ;
int error = 0 ;
bool log = ! V_116 [ V_174 ] ;
bool V_189 ;
V_189 = F_160 ( & V_141 , V_116 [ V_178 ] , log ) ;
if ( ! V_116 [ V_175 ] && ! V_189 ) {
F_143 ( log ,
L_6 ) ;
return - V_71 ;
}
error = F_158 ( V_15 , & V_172 , & V_38 , V_116 ,
& V_118 , log ) ;
if ( error )
goto error;
if ( V_118 ) {
V_170 = F_136 ( V_118 , & V_141 , V_4 , false ,
V_142 ) ;
if ( F_35 ( V_170 ) ) {
error = F_61 ( V_170 ) ;
goto V_180;
}
}
F_6 () ;
V_20 = F_15 ( V_15 , V_80 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_93 ;
goto V_181;
}
if ( V_189 )
V_41 = F_149 ( & V_20 -> V_26 , & V_141 ) ;
else
V_41 = F_154 ( & V_20 -> V_26 , & V_172 ) ;
if ( F_45 ( ! V_41 ) ) {
error = - V_187 ;
goto V_181;
}
if ( F_151 ( V_118 ) ) {
V_183 = F_139 ( V_41 -> V_43 ) ;
F_104 ( V_41 -> V_43 , V_118 ) ;
if ( F_45 ( V_170 ) ) {
error = F_130 ( V_41 ,
V_80 -> V_16 ,
V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 ,
V_182 ,
V_142 ) ;
F_79 ( error < 0 ) ;
}
} else {
V_170 = F_138 ( V_41 , V_80 -> V_16 ,
V_4 , V_182 , false ,
V_142 ) ;
if ( F_35 ( V_170 ) ) {
error = F_61 ( V_170 ) ;
goto V_181;
}
}
if ( V_116 [ V_190 ] )
F_161 ( V_41 ) ;
F_8 () ;
if ( V_170 )
F_4 ( & V_161 , V_170 , V_4 ) ;
if ( V_183 )
F_155 ( V_183 ) ;
return 0 ;
V_181:
F_8 () ;
F_48 ( V_170 ) ;
V_180:
F_156 ( V_118 ) ;
error:
return error ;
}
static int F_162 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_15 * V_15 = F_95 ( V_10 -> V_115 ) ;
struct V_37 V_38 ;
struct V_9 * V_170 ;
struct V_40 * V_41 ;
struct V_14 * V_20 ;
struct V_171 V_172 ;
struct V_140 V_191 ;
T_3 V_142 = F_142 ( V_116 [ V_173 ] ) ;
int V_62 = 0 ;
bool log = ! V_116 [ V_174 ] ;
bool V_189 ;
V_189 = F_160 ( & V_191 , V_116 [ V_178 ] , log ) ;
if ( V_116 [ V_175 ] ) {
F_144 ( & V_172 , & V_38 , true , NULL ) ;
V_62 = F_145 ( V_15 , & V_172 , V_116 [ V_175 ] , NULL ,
log ) ;
} else if ( ! V_189 ) {
F_143 ( log ,
L_7 ) ;
V_62 = - V_71 ;
}
if ( V_62 )
return V_62 ;
F_6 () ;
V_20 = F_15 ( F_95 ( V_10 -> V_115 ) , V_80 -> V_16 ) ;
if ( ! V_20 ) {
V_62 = - V_93 ;
goto V_192;
}
if ( V_189 )
V_41 = F_149 ( & V_20 -> V_26 , & V_191 ) ;
else
V_41 = F_154 ( & V_20 -> V_26 , & V_172 ) ;
if ( ! V_41 ) {
V_62 = - V_187 ;
goto V_192;
}
V_170 = F_138 ( V_41 , V_80 -> V_16 , V_4 ,
V_182 , true , V_142 ) ;
if ( F_35 ( V_170 ) ) {
V_62 = F_61 ( V_170 ) ;
goto V_192;
}
F_8 () ;
return F_163 ( V_170 , V_4 ) ;
V_192:
F_8 () ;
return V_62 ;
}
static int F_164 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_15 * V_15 = F_95 ( V_10 -> V_115 ) ;
struct V_37 V_38 ;
struct V_9 * V_170 ;
struct V_40 * V_41 = NULL ;
struct V_14 * V_20 ;
struct V_171 V_172 ;
struct V_140 V_191 ;
T_3 V_142 = F_142 ( V_116 [ V_173 ] ) ;
int V_62 ;
bool log = ! V_116 [ V_174 ] ;
bool V_189 ;
V_189 = F_160 ( & V_191 , V_116 [ V_178 ] , log ) ;
if ( V_116 [ V_175 ] ) {
F_144 ( & V_172 , & V_38 , true , NULL ) ;
V_62 = F_145 ( V_15 , & V_172 , V_116 [ V_175 ] ,
NULL , log ) ;
if ( F_45 ( V_62 ) )
return V_62 ;
}
F_6 () ;
V_20 = F_15 ( F_95 ( V_10 -> V_115 ) , V_80 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
V_62 = - V_93 ;
goto V_192;
}
if ( F_45 ( ! V_116 [ V_175 ] && ! V_189 ) ) {
V_62 = F_165 ( & V_20 -> V_26 ) ;
goto V_192;
}
if ( V_189 )
V_41 = F_149 ( & V_20 -> V_26 , & V_191 ) ;
else
V_41 = F_154 ( & V_20 -> V_26 , & V_172 ) ;
if ( F_45 ( ! V_41 ) ) {
V_62 = - V_187 ;
goto V_192;
}
F_166 ( & V_20 -> V_26 , V_41 ) ;
F_8 () ;
V_170 = F_136 ( ( const struct V_42 V_193 * ) V_41 -> V_43 ,
& V_41 -> V_162 , V_4 , false , V_142 ) ;
if ( F_151 ( V_170 ) ) {
if ( F_151 ( ! F_35 ( V_170 ) ) ) {
F_18 () ;
V_62 = F_130 ( V_41 , V_80 -> V_16 ,
V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 ,
V_194 ,
V_142 ) ;
F_19 () ;
F_79 ( V_62 < 0 ) ;
F_4 ( & V_161 , V_170 , V_4 ) ;
} else {
F_167 ( F_95 ( V_10 -> V_115 ) -> V_195 , 0 , 0 , F_61 ( V_170 ) ) ;
}
}
F_107 ( V_41 , true ) ;
return 0 ;
V_192:
F_8 () ;
return V_62 ;
}
static int F_168 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_90 * V_116 [ V_198 ] ;
struct V_80 * V_80 = F_169 ( F_170 ( V_197 -> V_199 ) ) ;
struct V_200 * V_201 ;
struct V_14 * V_20 ;
T_3 V_142 ;
int V_62 ;
V_62 = F_171 ( V_197 -> V_199 , & V_161 , V_116 ,
V_202 , V_203 , NULL ) ;
if ( V_62 )
return V_62 ;
V_142 = F_142 ( V_116 [ V_173 ] ) ;
F_18 () ;
V_20 = F_12 ( F_95 ( V_10 -> V_115 ) , V_80 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_93 ;
}
V_201 = F_51 ( V_20 -> V_26 . V_201 ) ;
for (; ; ) {
struct V_40 * V_41 ;
T_3 V_204 , V_205 ;
V_204 = V_197 -> args [ 0 ] ;
V_205 = V_197 -> args [ 1 ] ;
V_41 = F_172 ( V_201 , & V_204 , & V_205 ) ;
if ( ! V_41 )
break;
if ( F_130 ( V_41 , V_80 -> V_16 , V_10 ,
F_173 ( V_197 -> V_10 ) . V_52 ,
V_197 -> V_199 -> V_206 , V_207 ,
V_182 , V_142 ) < 0 )
break;
V_197 -> args [ 0 ] = V_204 ;
V_197 -> args [ 1 ] = V_205 ;
}
F_19 () ;
return V_10 -> V_88 ;
}
static T_5 F_174 ( void )
{
T_5 V_208 = F_63 ( sizeof( struct V_80 ) ) ;
V_208 += F_64 ( V_209 ) ;
V_208 += F_120 ( sizeof( struct V_131 ) ) ;
V_208 += F_120 ( sizeof( struct V_132 ) ) ;
V_208 += F_64 ( sizeof( T_3 ) ) ;
return V_208 ;
}
static int F_175 ( struct V_14 * V_20 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_160 , T_3 V_57 , V_156 V_50 )
{
struct V_80 * V_80 ;
struct V_131 V_210 ;
struct V_132 V_211 ;
int V_62 ;
V_80 = F_77 ( V_10 , V_52 , V_160 , & V_212 ,
V_57 , V_50 ) ;
if ( ! V_80 )
goto error;
V_80 -> V_16 = F_23 ( V_20 ) ;
V_62 = F_176 ( V_10 , V_213 , F_20 ( V_20 ) ) ;
if ( V_62 )
goto V_214;
F_108 ( V_20 , & V_210 , & V_211 ) ;
if ( F_125 ( V_10 , V_215 , sizeof( struct V_131 ) ,
& V_210 , V_216 ) )
goto V_214;
if ( F_125 ( V_10 , V_217 ,
sizeof( struct V_132 ) ,
& V_211 , V_216 ) )
goto V_214;
if ( F_88 ( V_10 , V_218 , V_20 -> V_85 ) )
goto V_214;
F_134 ( V_10 , V_80 ) ;
return 0 ;
V_214:
F_135 ( V_10 , V_80 ) ;
error:
return - V_153 ;
}
static struct V_9 * F_177 ( void )
{
return F_76 ( F_174 () , V_11 ) ;
}
static struct V_14 * F_178 ( struct V_15 * V_15 ,
const struct V_80 * V_80 ,
struct V_90 * V_116 [ V_219 + 1 ] )
{
struct V_14 * V_20 ;
if ( ! V_116 [ V_213 ] )
V_20 = F_15 ( V_15 , V_80 -> V_16 ) ;
else {
struct V_19 * V_19 ;
V_19 = F_179 ( V_15 , F_81 ( V_116 [ V_213 ] ) ) ;
V_20 = V_19 && V_19 -> V_30 == V_21 ? V_19 -> V_20 : NULL ;
}
return V_20 ? V_20 : F_137 ( - V_93 ) ;
}
static void F_180 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_14 * V_20 ;
V_20 = F_178 ( F_95 ( V_10 -> V_115 ) , V_4 -> V_114 , V_4 -> V_117 ) ;
if ( F_35 ( V_20 ) )
return;
F_181 ( V_20 -> V_85 , L_8 ) ;
V_20 -> V_85 = 0 ;
}
static void F_182 ( struct V_14 * V_20 , struct V_90 * V_116 [] )
{
if ( V_116 [ V_218 ] )
V_20 -> V_85 = F_183 ( V_116 [ V_218 ] ) ;
}
static int F_184 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_33 V_34 ;
struct V_9 * V_170 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
struct V_220 * V_220 ;
int V_62 , V_134 ;
V_62 = - V_71 ;
if ( ! V_116 [ V_213 ] || ! V_116 [ V_221 ] )
goto V_62;
V_170 = F_177 () ;
if ( ! V_170 )
return - V_95 ;
V_62 = - V_95 ;
V_20 = F_185 ( sizeof( * V_20 ) , V_11 ) ;
if ( V_20 == NULL )
goto V_222;
F_186 ( V_20 , F_95 ( V_10 -> V_115 ) ) ;
V_62 = F_187 ( & V_20 -> V_26 ) ;
if ( V_62 )
goto V_223;
V_20 -> V_27 = F_188 ( struct V_44 ) ;
if ( ! V_20 -> V_27 ) {
V_62 = - V_95 ;
goto V_224;
}
V_20 -> V_28 = F_189 ( V_31 * sizeof( struct V_29 ) ,
V_11 ) ;
if ( ! V_20 -> V_28 ) {
V_62 = - V_95 ;
goto V_225;
}
for ( V_134 = 0 ; V_134 < V_31 ; V_134 ++ )
F_190 ( & V_20 -> V_28 [ V_134 ] ) ;
V_34 . V_226 = F_81 ( V_116 [ V_213 ] ) ;
V_34 . type = V_227 ;
V_34 . V_228 = NULL ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_21 ;
V_34 . V_229 = V_116 [ V_221 ] ;
F_182 ( V_20 , V_116 ) ;
F_6 () ;
V_19 = F_33 ( & V_34 ) ;
if ( F_35 ( V_19 ) ) {
V_62 = F_61 ( V_19 ) ;
if ( V_62 == - V_230 )
V_62 = - V_186 ;
if ( V_62 == - V_186 ) {
if ( V_4 -> V_231 -> V_232 < V_233 )
F_180 ( V_10 , V_4 ) ;
}
goto V_234;
}
V_62 = F_175 ( V_20 , V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 , V_235 ) ;
F_79 ( V_62 < 0 ) ;
V_220 = F_191 ( F_92 ( V_20 ) , V_236 ) ;
F_192 ( & V_20 -> V_237 , & V_220 -> V_238 ) ;
F_8 () ;
F_4 ( & V_212 , V_170 , V_4 ) ;
return 0 ;
V_234:
F_8 () ;
F_29 ( V_20 -> V_28 ) ;
V_225:
F_28 ( V_20 -> V_27 ) ;
V_224:
F_27 ( & V_20 -> V_26 ) ;
V_223:
F_29 ( V_20 ) ;
V_222:
F_48 ( V_170 ) ;
V_62:
return V_62 ;
}
static void F_193 ( struct V_14 * V_20 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_31 ; V_134 ++ ) {
struct V_19 * V_19 ;
struct V_239 * V_240 ;
F_194 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_19 -> V_30 != V_21 )
F_37 ( V_19 ) ;
}
F_195 ( & V_20 -> V_237 ) ;
F_37 ( F_196 ( V_20 , V_21 ) ) ;
F_197 ( & V_20 -> V_25 , F_25 ) ;
}
static int F_198 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_170 ;
struct V_14 * V_20 ;
int V_62 ;
V_170 = F_177 () ;
if ( ! V_170 )
return - V_95 ;
F_6 () ;
V_20 = F_178 ( F_95 ( V_10 -> V_115 ) , V_4 -> V_114 , V_4 -> V_117 ) ;
V_62 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_241;
V_62 = F_175 ( V_20 , V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 , V_242 ) ;
F_79 ( V_62 < 0 ) ;
F_193 ( V_20 ) ;
F_8 () ;
F_4 ( & V_212 , V_170 , V_4 ) ;
return 0 ;
V_241:
F_8 () ;
F_48 ( V_170 ) ;
return V_62 ;
}
static int F_199 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_170 ;
struct V_14 * V_20 ;
int V_62 ;
V_170 = F_177 () ;
if ( ! V_170 )
return - V_95 ;
F_6 () ;
V_20 = F_178 ( F_95 ( V_10 -> V_115 ) , V_4 -> V_114 , V_4 -> V_117 ) ;
V_62 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_241;
F_182 ( V_20 , V_4 -> V_117 ) ;
V_62 = F_175 ( V_20 , V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 , V_235 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_212 , V_170 , V_4 ) ;
return 0 ;
V_241:
F_8 () ;
F_48 ( V_170 ) ;
return V_62 ;
}
static int F_200 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_170 ;
struct V_14 * V_20 ;
int V_62 ;
V_170 = F_177 () ;
if ( ! V_170 )
return - V_95 ;
F_6 () ;
V_20 = F_178 ( F_95 ( V_10 -> V_115 ) , V_4 -> V_114 , V_4 -> V_117 ) ;
if ( F_35 ( V_20 ) ) {
V_62 = F_61 ( V_20 ) ;
goto V_241;
}
V_62 = F_175 ( V_20 , V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 , V_235 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
return F_163 ( V_170 , V_4 ) ;
V_241:
F_8 () ;
F_48 ( V_170 ) ;
return V_62 ;
}
static int F_201 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_220 * V_220 = F_191 ( F_95 ( V_10 -> V_115 ) , V_236 ) ;
struct V_14 * V_20 ;
int V_243 = V_197 -> args [ 0 ] ;
int V_134 = 0 ;
F_6 () ;
F_202 (dp, &ovs_net->dps, list_node) {
if ( V_134 >= V_243 &&
F_175 ( V_20 , V_10 , F_173 ( V_197 -> V_10 ) . V_52 ,
V_197 -> V_199 -> V_206 , V_207 ,
V_235 ) < 0 )
break;
V_134 ++ ;
}
F_8 () ;
V_197 -> args [ 0 ] = V_134 ;
return V_10 -> V_88 ;
}
static int F_203 ( struct V_19 * V_19 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_160 , T_3 V_57 , V_156 V_50 )
{
struct V_80 * V_80 ;
struct V_244 V_245 ;
int V_62 ;
V_80 = F_77 ( V_10 , V_52 , V_160 , & V_246 ,
V_57 , V_50 ) ;
if ( ! V_80 )
return - V_153 ;
V_80 -> V_16 = F_23 ( V_19 -> V_20 ) ;
if ( F_88 ( V_10 , V_247 , V_19 -> V_30 ) ||
F_88 ( V_10 , V_248 , V_19 -> V_249 -> type ) ||
F_176 ( V_10 , V_250 ,
F_22 ( V_19 ) ) )
goto V_214;
F_204 ( V_19 , & V_245 ) ;
if ( F_125 ( V_10 , V_251 ,
sizeof( struct V_244 ) , & V_245 ,
V_252 ) )
goto V_214;
if ( F_205 ( V_19 , V_10 ) )
goto V_214;
V_62 = F_206 ( V_19 , V_10 ) ;
if ( V_62 == - V_153 )
goto error;
F_134 ( V_10 , V_80 ) ;
return 0 ;
V_214:
V_62 = - V_153 ;
error:
F_135 ( V_10 , V_80 ) ;
return V_62 ;
}
static struct V_9 * F_207 ( void )
{
return F_208 ( V_253 , V_11 ) ;
}
struct V_9 * F_209 ( struct V_19 * V_19 , T_3 V_52 ,
T_3 V_160 , V_156 V_50 )
{
struct V_9 * V_10 ;
int V_164 ;
V_10 = F_208 ( V_253 , V_94 ) ;
if ( ! V_10 )
return F_137 ( - V_95 ) ;
V_164 = F_203 ( V_19 , V_10 , V_52 , V_160 , 0 , V_50 ) ;
F_79 ( V_164 < 0 ) ;
return V_10 ;
}
static struct V_19 * F_210 ( struct V_15 * V_15 ,
const struct V_80 * V_80 ,
struct V_90 * V_116 [ V_254 + 1 ] )
{
struct V_14 * V_20 ;
struct V_19 * V_19 ;
if ( V_116 [ V_250 ] ) {
V_19 = F_179 ( V_15 , F_81 ( V_116 [ V_250 ] ) ) ;
if ( ! V_19 )
return F_137 ( - V_93 ) ;
if ( V_80 -> V_16 &&
V_80 -> V_16 != F_23 ( V_19 -> V_20 ) )
return F_137 ( - V_93 ) ;
return V_19 ;
} else if ( V_116 [ V_247 ] ) {
T_3 V_30 = F_183 ( V_116 [ V_247 ] ) ;
if ( V_30 >= V_255 )
return F_137 ( - V_97 ) ;
V_20 = F_15 ( V_15 , V_80 -> V_16 ) ;
if ( ! V_20 )
return F_137 ( - V_93 ) ;
V_19 = F_21 ( V_20 , V_30 ) ;
if ( ! V_19 )
return F_137 ( - V_93 ) ;
return V_19 ;
} else
return F_137 ( - V_71 ) ;
}
static void F_211 ( struct V_14 * V_20 )
{
unsigned V_256 , V_257 = 0 ;
struct V_17 * V_18 ;
struct V_19 * V_19 ;
int V_134 ;
for ( V_134 = 0 ; V_134 < V_31 ; V_134 ++ ) {
F_32 (vport, &dp->ports[i], dp_hash_node) {
V_18 = V_19 -> V_18 ;
V_256 = F_212 ( V_18 ) ;
if ( V_256 > V_257 )
V_257 = V_256 ;
}
}
V_20 -> V_257 = V_257 ;
for ( V_134 = 0 ; V_134 < V_31 ; V_134 ++ )
F_32 (vport, &dp->ports[i], dp_hash_node)
F_213 ( V_19 -> V_18 , V_257 ) ;
}
static int F_214 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_33 V_34 ;
struct V_9 * V_170 ;
struct V_19 * V_19 ;
struct V_14 * V_20 ;
T_3 V_30 ;
int V_62 ;
if ( ! V_116 [ V_250 ] || ! V_116 [ V_248 ] ||
! V_116 [ V_258 ] )
return - V_71 ;
V_30 = V_116 [ V_247 ]
? F_183 ( V_116 [ V_247 ] ) : 0 ;
if ( V_30 >= V_255 )
return - V_97 ;
V_170 = F_207 () ;
if ( ! V_170 )
return - V_95 ;
F_6 () ;
V_259:
V_20 = F_15 ( F_95 ( V_10 -> V_115 ) , V_80 -> V_16 ) ;
V_62 = - V_93 ;
if ( ! V_20 )
goto V_260;
if ( V_30 ) {
V_19 = F_196 ( V_20 , V_30 ) ;
V_62 = - V_230 ;
if ( V_19 )
goto V_260;
} else {
for ( V_30 = 1 ; ; V_30 ++ ) {
if ( V_30 >= V_255 ) {
V_62 = - V_97 ;
goto V_260;
}
V_19 = F_196 ( V_20 , V_30 ) ;
if ( ! V_19 )
break;
}
}
V_34 . V_226 = F_81 ( V_116 [ V_250 ] ) ;
V_34 . type = F_183 ( V_116 [ V_248 ] ) ;
V_34 . V_228 = V_116 [ V_261 ] ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_30 ;
V_34 . V_229 = V_116 [ V_258 ] ;
V_19 = F_33 ( & V_34 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) ) {
if ( V_62 == - V_262 )
goto V_259;
goto V_260;
}
V_62 = F_203 ( V_19 , V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 , V_263 ) ;
if ( F_212 ( V_19 -> V_18 ) > V_20 -> V_257 )
F_211 ( V_20 ) ;
else
F_213 ( V_19 -> V_18 , V_20 -> V_257 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_246 , V_170 , V_4 ) ;
return 0 ;
V_260:
F_8 () ;
F_48 ( V_170 ) ;
return V_62 ;
}
static int F_215 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_9 * V_170 ;
struct V_19 * V_19 ;
int V_62 ;
V_170 = F_207 () ;
if ( ! V_170 )
return - V_95 ;
F_6 () ;
V_19 = F_210 ( F_95 ( V_10 -> V_115 ) , V_4 -> V_114 , V_116 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_260;
if ( V_116 [ V_248 ] &&
F_183 ( V_116 [ V_248 ] ) != V_19 -> V_249 -> type ) {
V_62 = - V_71 ;
goto V_260;
}
if ( V_116 [ V_261 ] ) {
V_62 = F_216 ( V_19 , V_116 [ V_261 ] ) ;
if ( V_62 )
goto V_260;
}
if ( V_116 [ V_258 ] ) {
struct V_90 * V_264 = V_116 [ V_258 ] ;
V_62 = F_217 ( V_19 , V_264 ) ;
if ( V_62 )
goto V_260;
}
V_62 = F_203 ( V_19 , V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 , V_263 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_246 , V_170 , V_4 ) ;
return 0 ;
V_260:
F_8 () ;
F_48 ( V_170 ) ;
return V_62 ;
}
static int F_218 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
bool V_265 = false ;
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_9 * V_170 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
int V_62 ;
V_170 = F_207 () ;
if ( ! V_170 )
return - V_95 ;
F_6 () ;
V_19 = F_210 ( F_95 ( V_10 -> V_115 ) , V_4 -> V_114 , V_116 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_260;
if ( V_19 -> V_30 == V_21 ) {
V_62 = - V_71 ;
goto V_260;
}
V_62 = F_203 ( V_19 , V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 , V_266 ) ;
F_79 ( V_62 < 0 ) ;
V_20 = V_19 -> V_20 ;
if ( F_212 ( V_19 -> V_18 ) == V_20 -> V_257 )
V_265 = true ;
F_219 ( V_19 -> V_18 ) ;
F_37 ( V_19 ) ;
if ( V_265 )
F_211 ( V_20 ) ;
F_8 () ;
F_4 ( & V_246 , V_170 , V_4 ) ;
return 0 ;
V_260:
F_8 () ;
F_48 ( V_170 ) ;
return V_62 ;
}
static int F_220 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_9 * V_170 ;
struct V_19 * V_19 ;
int V_62 ;
V_170 = F_207 () ;
if ( ! V_170 )
return - V_95 ;
F_18 () ;
V_19 = F_210 ( F_95 ( V_10 -> V_115 ) , V_80 , V_116 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_260;
V_62 = F_203 ( V_19 , V_170 , V_4 -> V_165 ,
V_4 -> V_166 , 0 , V_263 ) ;
F_79 ( V_62 < 0 ) ;
F_19 () ;
return F_163 ( V_170 , V_4 ) ;
V_260:
F_19 () ;
F_48 ( V_170 ) ;
return V_62 ;
}
static int F_221 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_80 * V_80 = F_169 ( F_170 ( V_197 -> V_199 ) ) ;
struct V_14 * V_20 ;
int V_204 = V_197 -> args [ 0 ] , V_243 = V_197 -> args [ 1 ] ;
int V_134 , V_267 = 0 ;
F_18 () ;
V_20 = F_12 ( F_95 ( V_10 -> V_115 ) , V_80 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_93 ;
}
for ( V_134 = V_204 ; V_134 < V_31 ; V_134 ++ ) {
struct V_19 * V_19 ;
V_267 = 0 ;
F_32 (vport, &dp->ports[i], dp_hash_node) {
if ( V_267 >= V_243 &&
F_203 ( V_19 , V_10 ,
F_173 ( V_197 -> V_10 ) . V_52 ,
V_197 -> V_199 -> V_206 ,
V_207 ,
V_263 ) < 0 )
goto V_55;
V_267 ++ ;
}
V_243 = 0 ;
}
V_55:
F_19 () ;
V_197 -> args [ 0 ] = V_134 ;
V_197 -> args [ 1 ] = V_267 ;
return V_10 -> V_88 ;
}
static void F_222 ( int V_268 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_268 ; V_134 ++ )
F_223 ( V_269 [ V_134 ] ) ;
}
static int T_7 F_224 ( void )
{
int V_62 ;
int V_134 ;
for ( V_134 = 0 ; V_134 < F_225 ( V_269 ) ; V_134 ++ ) {
V_62 = F_226 ( V_269 [ V_134 ] ) ;
if ( V_62 )
goto error;
}
return 0 ;
error:
F_222 ( V_134 ) ;
return V_62 ;
}
static int T_8 F_227 ( struct V_15 * V_15 )
{
struct V_220 * V_220 = F_191 ( V_15 , V_236 ) ;
F_228 ( & V_220 -> V_238 ) ;
F_229 ( & V_220 -> V_270 , V_271 ) ;
F_230 ( V_15 ) ;
return 0 ;
}
static void T_9 F_231 ( struct V_15 * V_15 , struct V_15 * V_272 ,
struct V_273 * V_32 )
{
struct V_220 * V_220 = F_191 ( V_15 , V_236 ) ;
struct V_14 * V_20 ;
F_202 (dp, &ovs_net->dps, list_node) {
int V_134 ;
for ( V_134 = 0 ; V_134 < V_31 ; V_134 ++ ) {
struct V_19 * V_19 ;
F_232 (vport, &dp->ports[i], dp_hash_node) {
if ( V_19 -> V_249 -> type != V_227 )
continue;
if ( F_233 ( V_19 -> V_18 ) == V_272 )
F_234 ( & V_19 -> V_274 , V_32 ) ;
}
}
}
}
static void T_9 F_235 ( struct V_15 * V_272 )
{
struct V_14 * V_20 , * V_275 ;
struct V_220 * V_220 = F_191 ( V_272 , V_236 ) ;
struct V_19 * V_19 , * V_276 ;
struct V_15 * V_15 ;
F_236 ( V_32 ) ;
F_237 ( V_272 ) ;
F_6 () ;
F_238 (dp, dp_next, &ovs_net->dps, list_node)
F_193 ( V_20 ) ;
F_239 () ;
F_240 (net)
F_231 ( V_15 , V_272 , & V_32 ) ;
F_241 () ;
F_238 (vport, vport_next, &head, detach_list) {
F_242 ( & V_19 -> V_274 ) ;
F_37 ( V_19 ) ;
}
F_8 () ;
F_243 ( & V_220 -> V_270 ) ;
}
static int T_7 F_244 ( void )
{
int V_62 ;
F_59 ( sizeof( struct V_277 ) > F_245 ( struct V_9 , V_197 ) ) ;
F_246 ( L_9 ) ;
V_62 = F_247 () ;
if ( V_62 )
goto error;
V_62 = F_248 () ;
if ( V_62 )
goto V_278;
V_62 = F_249 () ;
if ( V_62 )
goto V_279;
V_62 = F_250 () ;
if ( V_62 )
goto V_280;
V_62 = F_251 ( & V_281 ) ;
if ( V_62 )
goto V_282;
V_62 = F_252 ( & V_283 ) ;
if ( V_62 )
goto V_284;
V_62 = F_253 () ;
if ( V_62 )
goto V_285;
V_62 = F_224 () ;
if ( V_62 < 0 )
goto V_286;
return 0 ;
V_286:
F_254 () ;
V_285:
F_255 ( & V_283 ) ;
V_284:
F_256 ( & V_281 ) ;
V_282:
F_257 () ;
V_280:
F_258 () ;
V_279:
F_259 () ;
V_278:
F_260 () ;
error:
return V_62 ;
}
static void F_261 ( void )
{
F_222 ( F_225 ( V_269 ) ) ;
F_254 () ;
F_255 ( & V_283 ) ;
F_256 ( & V_281 ) ;
F_262 () ;
F_257 () ;
F_258 () ;
F_259 () ;
F_260 () ;
}
