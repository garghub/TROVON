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
error = F_47 ( V_20 , V_10 , V_38 , & V_49 ) ;
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
const struct V_48 * V_60 )
{
struct V_44 * V_45 ;
int V_61 ;
if ( V_60 -> V_52 == 0 ) {
V_61 = - V_62 ;
goto V_61;
}
if ( ! F_55 ( V_10 ) )
V_61 = F_56 ( V_20 , V_10 , V_38 , V_60 ) ;
else
V_61 = F_57 ( V_20 , V_10 , V_38 , V_60 ) ;
if ( V_61 )
goto V_61;
return 0 ;
V_61:
V_45 = F_43 ( V_20 -> V_27 ) ;
F_53 ( & V_45 -> V_59 ) ;
V_45 -> V_63 ++ ;
F_54 ( & V_45 -> V_59 ) ;
return V_61 ;
}
static int F_57 ( struct V_14 * V_20 , struct V_9 * V_10 ,
const struct V_37 * V_38 ,
const struct V_48 * V_60 )
{
unsigned short V_64 = F_58 ( V_10 ) -> V_64 ;
struct V_37 V_65 ;
struct V_9 * V_66 , * V_67 ;
int V_61 ;
F_59 ( sizeof( * F_42 ( V_10 ) ) > V_68 ) ;
V_66 = F_60 ( V_10 , V_69 , false ) ;
if ( F_35 ( V_66 ) )
return F_61 ( V_66 ) ;
if ( V_66 == NULL )
return - V_70 ;
if ( V_64 & V_71 ) {
V_65 = * V_38 ;
V_65 . V_72 . V_73 = V_74 ;
}
V_10 = V_66 ;
do {
if ( V_64 & V_71 && V_10 != V_66 )
V_38 = & V_65 ;
V_61 = F_56 ( V_20 , V_10 , V_38 , V_60 ) ;
if ( V_61 )
break;
} while ( ( V_10 = V_10 -> V_75 ) );
V_10 = V_66 ;
do {
V_67 = V_10 -> V_75 ;
if ( V_61 )
F_48 ( V_10 ) ;
else
F_49 ( V_10 ) ;
} while ( ( V_10 = V_67 ) );
return V_61 ;
}
static T_4 F_62 ( const struct V_48 * V_60 ,
unsigned int V_76 )
{
T_4 V_77 = F_63 ( sizeof( struct V_78 ) )
+ F_64 ( V_76 )
+ F_64 ( F_65 () ) ;
if ( V_60 -> V_79 )
V_77 += F_66 ( V_60 -> V_79 -> V_80 ) ;
if ( V_60 -> V_81 )
V_77 += F_64 ( F_67 () ) ;
if ( V_60 -> V_82 )
V_77 += F_64 ( V_60 -> V_82 ) ;
if ( V_60 -> V_53 )
V_77 += F_64 ( sizeof( V_60 -> V_53 ) ) ;
return V_77 ;
}
static void F_68 ( struct V_14 * V_20 , struct V_9 * V_10 )
{
if ( ! ( V_20 -> V_83 & V_84 ) ) {
T_4 V_85 = F_66 ( V_10 -> V_86 ) - V_10 -> V_86 ;
if ( V_85 > 0 )
memset ( F_69 ( V_10 , V_85 ) , 0 , V_85 ) ;
}
}
static int F_56 ( struct V_14 * V_20 , struct V_9 * V_10 ,
const struct V_37 * V_38 ,
const struct V_48 * V_60 )
{
struct V_78 * V_49 ;
struct V_9 * V_67 = NULL ;
struct V_9 * V_87 = NULL ;
struct V_88 * V_89 ;
T_4 V_86 ;
unsigned int V_90 ;
int V_61 , V_16 ;
V_16 = F_23 ( V_20 ) ;
if ( ! V_16 )
return - V_91 ;
if ( F_70 ( V_10 ) ) {
V_67 = F_71 ( V_10 , V_92 ) ;
if ( ! V_67 )
return - V_93 ;
V_67 = F_72 ( V_67 ) ;
if ( ! V_67 )
return - V_93 ;
V_10 = V_67 ;
}
if ( F_73 ( V_10 -> V_86 ) > V_94 ) {
V_61 = - V_95 ;
goto V_55;
}
if ( V_10 -> V_96 == V_97 &&
( V_61 = F_74 ( V_10 ) ) )
goto V_55;
if ( V_20 -> V_83 & V_84 )
V_90 = F_75 ( V_10 ) ;
else
V_90 = V_10 -> V_86 ;
V_86 = F_62 ( V_60 , V_90 ) ;
V_87 = F_76 ( V_86 , V_92 ) ;
if ( ! V_87 ) {
V_61 = - V_93 ;
goto V_55;
}
V_49 = F_77 ( V_87 , 0 , 0 , & V_98 ,
0 , V_60 -> V_50 ) ;
V_49 -> V_16 = V_16 ;
V_61 = F_78 ( V_38 , V_38 , V_99 , false , V_87 ) ;
F_79 ( V_61 ) ;
if ( V_60 -> V_79 )
F_80 ( V_87 , V_100 ,
V_80 ( V_60 -> V_79 ) ,
F_81 ( V_60 -> V_79 ) ) ;
if ( V_60 -> V_81 ) {
V_89 = F_82 ( V_87 , V_101 ) ;
V_61 = F_83 ( V_87 ,
V_60 -> V_81 ) ;
F_79 ( V_61 ) ;
F_84 ( V_87 , V_89 ) ;
}
if ( V_60 -> V_82 ) {
V_89 = F_82 ( V_87 , V_102 ) ;
V_61 = F_85 ( V_60 -> V_103 ,
V_60 -> V_82 ,
V_87 ) ;
if ( ! V_61 )
F_84 ( V_87 , V_89 ) ;
else
F_86 ( V_87 , V_89 ) ;
}
if ( V_60 -> V_53 ) {
if ( F_87 ( V_87 , V_104 ,
V_60 -> V_53 ) ) {
V_61 = - V_105 ;
goto V_55;
}
F_68 ( V_20 , V_87 ) ;
}
if ( ! ( V_89 = F_88 ( V_87 , V_106 , 0 ) ) ) {
V_61 = - V_105 ;
goto V_55;
}
V_89 -> V_80 = F_73 ( V_10 -> V_86 ) ;
V_61 = F_89 ( V_87 , V_10 , V_10 -> V_86 , V_90 ) ;
if ( V_61 )
goto V_55;
F_68 ( V_20 , V_87 ) ;
( (struct V_107 * ) V_87 -> V_108 ) -> V_109 = V_87 -> V_86 ;
V_61 = F_90 ( F_91 ( V_20 ) , V_87 , V_60 -> V_52 ) ;
V_87 = NULL ;
V_55:
if ( V_61 )
F_92 ( V_10 ) ;
F_48 ( V_87 ) ;
F_48 ( V_67 ) ;
return V_61 ;
}
static int F_93 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_78 * V_78 = V_4 -> V_110 ;
struct V_15 * V_15 = F_94 ( V_10 -> V_111 ) ;
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_42 * V_114 ;
struct V_9 * V_115 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_14 * V_20 ;
struct V_116 * V_117 ;
struct V_19 * V_39 ;
T_1 V_53 = 0 ;
int V_86 ;
int V_61 ;
bool log = ! V_112 [ V_118 ] ;
V_61 = - V_70 ;
if ( ! V_112 [ V_106 ] || ! V_112 [ V_99 ] ||
! V_112 [ V_102 ] )
goto V_61;
V_86 = V_80 ( V_112 [ V_106 ] ) ;
V_115 = F_95 ( V_119 + V_86 , V_11 ) ;
V_61 = - V_93 ;
if ( ! V_115 )
goto V_61;
F_96 ( V_115 , V_119 ) ;
F_97 ( F_98 ( V_115 , V_86 ) , V_112 [ V_106 ] , V_86 ) ;
F_99 ( V_115 ) ;
V_117 = F_100 ( V_115 ) ;
if ( F_101 ( V_117 -> V_120 ) )
V_115 -> V_121 = V_117 -> V_120 ;
else
V_115 -> V_121 = F_102 ( V_122 ) ;
if ( V_112 [ V_104 ] ) {
V_53 = F_103 ( V_112 [ V_104 ] ) ;
V_115 -> V_123 = 1 ;
}
F_42 ( V_115 ) -> V_53 = V_53 ;
V_41 = F_104 () ;
V_61 = F_61 ( V_41 ) ;
if ( F_35 ( V_41 ) )
goto V_124;
V_61 = F_105 ( V_15 , V_112 [ V_99 ] ,
V_115 , & V_41 -> V_38 , log ) ;
if ( V_61 )
goto V_125;
V_61 = F_106 ( V_15 , V_112 [ V_102 ] ,
& V_41 -> V_38 , & V_114 , log ) ;
if ( V_61 )
goto V_125;
F_107 ( V_41 -> V_43 , V_114 ) ;
V_115 -> V_126 = V_41 -> V_38 . V_127 . V_126 ;
V_115 -> V_128 = V_41 -> V_38 . V_127 . V_129 ;
F_18 () ;
V_20 = F_12 ( V_15 , V_78 -> V_16 ) ;
V_61 = - V_91 ;
if ( ! V_20 )
goto V_130;
V_39 = F_24 ( V_20 , V_41 -> V_38 . V_127 . V_131 ) ;
if ( ! V_39 )
V_39 = F_24 ( V_20 , V_21 ) ;
if ( ! V_39 )
goto V_130;
V_115 -> V_18 = V_39 -> V_18 ;
F_42 ( V_115 ) -> V_39 = V_39 ;
V_43 = F_51 ( V_41 -> V_43 ) ;
F_108 () ;
V_61 = F_52 ( V_20 , V_115 , V_43 , & V_41 -> V_38 ) ;
F_109 () ;
F_19 () ;
F_110 ( V_41 , false ) ;
return V_61 ;
V_130:
F_19 () ;
V_125:
F_110 ( V_41 , false ) ;
V_124:
F_48 ( V_115 ) ;
V_61:
return V_61 ;
}
static void F_111 ( const struct V_14 * V_20 , struct V_132 * V_45 ,
struct V_133 * V_134 )
{
int V_135 ;
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
V_45 -> V_136 = F_112 ( & V_20 -> V_26 ) ;
V_134 -> V_137 = F_113 ( & V_20 -> V_26 ) ;
V_45 -> V_58 = V_45 -> V_54 = V_45 -> V_63 = 0 ;
F_114 (i) {
const struct V_44 * V_138 ;
struct V_44 V_139 ;
unsigned int V_140 ;
V_138 = F_115 ( V_20 -> V_27 , V_135 ) ;
do {
V_140 = F_116 ( & V_138 -> V_59 ) ;
V_139 = * V_138 ;
} while ( F_117 ( & V_138 -> V_59 , V_140 ) );
V_45 -> V_58 += V_139 . V_58 ;
V_45 -> V_54 += V_139 . V_54 ;
V_45 -> V_63 += V_139 . V_63 ;
V_134 -> V_47 += V_139 . V_47 ;
}
}
static bool F_118 ( const struct V_141 * V_142 , T_5 V_143 )
{
return F_119 ( V_142 ) &&
! ( V_143 & V_144 ) ;
}
static bool F_120 ( T_5 V_143 )
{
return ! ( V_143 & V_145 ) ;
}
static bool F_121 ( T_5 V_143 )
{
return ! ( V_143 & V_146 ) ;
}
static T_4 F_122 ( const struct V_42 * V_114 ,
const struct V_141 * V_142 ,
T_5 V_143 )
{
T_4 V_86 = F_63 ( sizeof( struct V_78 ) ) ;
if ( V_142 && F_119 ( V_142 ) )
V_86 += F_64 ( V_142 -> V_147 ) ;
if ( ! V_142 || F_118 ( V_142 , V_143 ) )
V_86 += F_64 ( F_65 () ) ;
if ( F_120 ( V_143 ) )
V_86 += F_64 ( F_65 () ) ;
if ( F_121 ( V_143 ) )
V_86 += F_64 ( V_114 -> V_148 ) ;
return V_86
+ F_123 ( sizeof( struct V_149 ) )
+ F_64 ( 1 )
+ F_123 ( 8 ) ;
}
static int F_124 ( const struct V_40 * V_41 ,
struct V_9 * V_10 )
{
struct V_149 V_45 ;
T_6 V_150 ;
unsigned long V_151 ;
F_125 ( V_41 , & V_45 , & V_151 , & V_150 ) ;
if ( V_151 &&
F_126 ( V_10 , V_152 , F_127 ( V_151 ) ,
V_153 ) )
return - V_154 ;
if ( V_45 . V_155 &&
F_128 ( V_10 , V_156 ,
sizeof( struct V_149 ) , & V_45 ,
V_153 ) )
return - V_154 ;
if ( ( V_157 ) F_129 ( V_150 ) &&
F_130 ( V_10 , V_158 , ( V_157 ) F_129 ( V_150 ) ) )
return - V_154 ;
return 0 ;
}
static int F_131 ( const struct V_40 * V_41 ,
struct V_9 * V_10 , int V_159 )
{
struct V_88 * V_140 ;
int V_61 ;
V_140 = F_82 ( V_10 , V_160 ) ;
if ( V_140 ) {
const struct V_42 * V_43 ;
V_43 = F_132 ( V_41 -> V_43 ) ;
V_61 = F_85 ( V_43 -> V_103 ,
V_43 -> V_82 , V_10 ) ;
if ( ! V_61 )
F_84 ( V_10 , V_140 ) ;
else {
if ( V_159 )
return V_61 ;
F_86 ( V_10 , V_140 ) ;
}
} else if ( V_159 ) {
return - V_154 ;
}
return 0 ;
}
static int F_133 ( const struct V_40 * V_41 , int V_16 ,
struct V_9 * V_10 , T_3 V_52 ,
T_3 V_161 , T_3 V_57 , V_157 V_50 , T_3 V_143 )
{
const int V_159 = V_10 -> V_86 ;
struct V_78 * V_78 ;
int V_61 ;
V_78 = F_77 ( V_10 , V_52 , V_161 , & V_162 ,
V_57 , V_50 ) ;
if ( ! V_78 )
return - V_154 ;
V_78 -> V_16 = V_16 ;
V_61 = F_134 ( V_41 , V_10 ) ;
if ( V_61 )
goto error;
if ( F_118 ( & V_41 -> V_163 , V_143 ) ) {
V_61 = F_135 ( V_41 , V_10 ) ;
if ( V_61 )
goto error;
}
if ( F_120 ( V_143 ) ) {
V_61 = F_136 ( V_41 , V_10 ) ;
if ( V_61 )
goto error;
}
V_61 = F_124 ( V_41 , V_10 ) ;
if ( V_61 )
goto error;
if ( F_121 ( V_143 ) ) {
V_61 = F_131 ( V_41 , V_10 , V_159 ) ;
if ( V_61 )
goto error;
}
F_137 ( V_10 , V_78 ) ;
return 0 ;
error:
F_138 ( V_10 , V_78 ) ;
return V_61 ;
}
static struct V_9 * F_139 ( const struct V_42 * V_114 ,
const struct V_141 * V_142 ,
struct V_3 * V_4 ,
bool V_164 ,
T_5 V_143 )
{
struct V_9 * V_10 ;
T_4 V_86 ;
if ( ! V_164 && ! F_1 ( & V_162 , V_4 , 0 ) )
return NULL ;
V_86 = F_122 ( V_114 , V_142 , V_143 ) ;
V_10 = F_76 ( V_86 , V_11 ) ;
if ( ! V_10 )
return F_140 ( - V_93 ) ;
return V_10 ;
}
static struct V_9 * F_141 ( const struct V_40 * V_41 ,
int V_16 ,
struct V_3 * V_4 , V_157 V_50 ,
bool V_164 , T_3 V_143 )
{
struct V_9 * V_10 ;
int V_165 ;
V_10 = F_139 ( F_142 ( V_41 -> V_43 ) ,
& V_41 -> V_163 , V_4 , V_164 , V_143 ) ;
if ( F_143 ( V_10 ) )
return V_10 ;
V_165 = F_133 ( V_41 , V_16 , V_10 ,
V_4 -> V_166 , V_4 -> V_167 , 0 ,
V_50 , V_143 ) ;
F_79 ( V_165 < 0 ) ;
return V_10 ;
}
static int F_144 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_94 ( V_10 -> V_111 ) ;
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_78 * V_78 = V_4 -> V_110 ;
struct V_40 * V_41 = NULL , * V_168 ;
struct V_169 V_170 ;
struct V_9 * V_171 ;
struct V_14 * V_20 ;
struct V_37 V_38 ;
struct V_42 * V_114 ;
struct V_172 V_173 ;
T_3 V_143 = F_145 ( V_112 [ V_174 ] ) ;
int error ;
bool log = ! V_112 [ V_175 ] ;
error = - V_70 ;
if ( ! V_112 [ V_176 ] ) {
F_146 ( log , L_1 ) ;
goto error;
}
if ( ! V_112 [ V_160 ] ) {
F_146 ( log , L_2 ) ;
goto error;
}
V_168 = F_104 () ;
if ( F_35 ( V_168 ) ) {
error = F_61 ( V_168 ) ;
goto error;
}
F_147 ( & V_173 , & V_38 , & V_170 ) ;
error = F_148 ( V_15 , & V_173 , V_112 [ V_176 ] ,
V_112 [ V_177 ] , log ) ;
if ( error )
goto V_178;
F_149 ( & V_168 -> V_38 , & V_38 , true , & V_170 ) ;
error = F_150 ( & V_168 -> V_163 , V_112 [ V_179 ] ,
& V_38 , log ) ;
if ( error )
goto V_178;
error = F_106 ( V_15 , V_112 [ V_160 ] ,
& V_168 -> V_38 , & V_114 , log ) ;
if ( error ) {
F_146 ( log , L_3 ) ;
goto V_178;
}
V_171 = F_139 ( V_114 , & V_168 -> V_163 , V_4 , false ,
V_143 ) ;
if ( F_35 ( V_171 ) ) {
error = F_61 ( V_171 ) ;
goto V_180;
}
F_6 () ;
V_20 = F_15 ( V_15 , V_78 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_91 ;
goto V_181;
}
if ( F_119 ( & V_168 -> V_163 ) )
V_41 = F_151 ( & V_20 -> V_26 , & V_168 -> V_163 ) ;
if ( ! V_41 )
V_41 = F_152 ( & V_20 -> V_26 , & V_38 ) ;
if ( F_153 ( ! V_41 ) ) {
F_107 ( V_168 -> V_43 , V_114 ) ;
error = F_154 ( & V_20 -> V_26 , V_168 , & V_170 ) ;
if ( F_45 ( error ) ) {
V_114 = NULL ;
goto V_181;
}
if ( F_45 ( V_171 ) ) {
error = F_133 ( V_168 ,
V_78 -> V_16 ,
V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 ,
V_182 ,
V_143 ) ;
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
if ( F_45 ( ! F_155 ( V_41 , & V_173 ) ) ) {
if ( F_156 ( & V_41 -> V_163 ) )
V_41 = F_157 ( & V_20 -> V_26 ,
& V_173 ) ;
else
V_41 = NULL ;
if ( ! V_41 ) {
error = - V_187 ;
goto V_181;
}
}
V_183 = F_142 ( V_41 -> V_43 ) ;
F_107 ( V_41 -> V_43 , V_114 ) ;
if ( F_45 ( V_171 ) ) {
error = F_133 ( V_41 ,
V_78 -> V_16 ,
V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 ,
V_182 ,
V_143 ) ;
F_79 ( error < 0 ) ;
}
F_8 () ;
F_158 ( V_183 ) ;
F_110 ( V_168 , false ) ;
}
if ( V_171 )
F_4 ( & V_162 , V_171 , V_4 ) ;
return 0 ;
V_181:
F_8 () ;
F_48 ( V_171 ) ;
V_180:
F_159 ( V_114 ) ;
V_178:
F_110 ( V_168 , false ) ;
error:
return error ;
}
static struct V_42 * F_160 ( struct V_15 * V_15 ,
const struct V_88 * V_112 ,
const struct V_37 * V_38 ,
const struct V_169 * V_170 ,
bool log )
{
struct V_42 * V_114 ;
struct V_37 V_188 ;
int error ;
F_149 ( & V_188 , V_38 , true , V_170 ) ;
error = F_106 ( V_15 , V_112 , & V_188 , & V_114 , log ) ;
if ( error ) {
F_146 ( log ,
L_4 ) ;
return F_140 ( error ) ;
}
return V_114 ;
}
static int F_161 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_94 ( V_10 -> V_111 ) ;
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_78 * V_78 = V_4 -> V_110 ;
struct V_37 V_38 ;
struct V_40 * V_41 ;
struct V_169 V_170 ;
struct V_9 * V_171 = NULL ;
struct V_14 * V_20 ;
struct V_42 * V_183 = NULL , * V_114 = NULL ;
struct V_172 V_173 ;
struct V_141 V_142 ;
T_3 V_143 = F_145 ( V_112 [ V_174 ] ) ;
int error = 0 ;
bool log = ! V_112 [ V_175 ] ;
bool V_189 ;
V_189 = F_162 ( & V_142 , V_112 [ V_179 ] , log ) ;
if ( V_112 [ V_176 ] ) {
F_147 ( & V_173 , & V_38 , & V_170 ) ;
error = F_148 ( V_15 , & V_173 , V_112 [ V_176 ] ,
V_112 [ V_177 ] , log ) ;
} else if ( ! V_189 ) {
F_146 ( log ,
L_5 ) ;
error = - V_70 ;
}
if ( error )
goto error;
if ( V_112 [ V_160 ] ) {
if ( ! V_112 [ V_176 ] ) {
F_146 ( log ,
L_6 ) ;
error = - V_70 ;
goto error;
}
V_114 = F_160 ( V_15 , V_112 [ V_160 ] , & V_38 ,
& V_170 , log ) ;
if ( F_35 ( V_114 ) ) {
error = F_61 ( V_114 ) ;
goto error;
}
V_171 = F_139 ( V_114 , & V_142 , V_4 , false ,
V_143 ) ;
if ( F_35 ( V_171 ) ) {
error = F_61 ( V_171 ) ;
goto V_180;
}
}
F_6 () ;
V_20 = F_15 ( V_15 , V_78 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_91 ;
goto V_181;
}
if ( V_189 )
V_41 = F_151 ( & V_20 -> V_26 , & V_142 ) ;
else
V_41 = F_157 ( & V_20 -> V_26 , & V_173 ) ;
if ( F_45 ( ! V_41 ) ) {
error = - V_187 ;
goto V_181;
}
if ( F_153 ( V_114 ) ) {
V_183 = F_142 ( V_41 -> V_43 ) ;
F_107 ( V_41 -> V_43 , V_114 ) ;
if ( F_45 ( V_171 ) ) {
error = F_133 ( V_41 ,
V_78 -> V_16 ,
V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 ,
V_182 ,
V_143 ) ;
F_79 ( error < 0 ) ;
}
} else {
V_171 = F_141 ( V_41 , V_78 -> V_16 ,
V_4 , V_182 , false ,
V_143 ) ;
if ( F_35 ( V_171 ) ) {
error = F_61 ( V_171 ) ;
goto V_181;
}
}
if ( V_112 [ V_190 ] )
F_163 ( V_41 ) ;
F_8 () ;
if ( V_171 )
F_4 ( & V_162 , V_171 , V_4 ) ;
if ( V_183 )
F_158 ( V_183 ) ;
return 0 ;
V_181:
F_8 () ;
F_48 ( V_171 ) ;
V_180:
F_159 ( V_114 ) ;
error:
return error ;
}
static int F_164 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_78 * V_78 = V_4 -> V_110 ;
struct V_15 * V_15 = F_94 ( V_10 -> V_111 ) ;
struct V_37 V_38 ;
struct V_9 * V_171 ;
struct V_40 * V_41 ;
struct V_14 * V_20 ;
struct V_172 V_173 ;
struct V_141 V_191 ;
T_3 V_143 = F_145 ( V_112 [ V_174 ] ) ;
int V_61 = 0 ;
bool log = ! V_112 [ V_175 ] ;
bool V_189 ;
V_189 = F_162 ( & V_191 , V_112 [ V_179 ] , log ) ;
if ( V_112 [ V_176 ] ) {
F_147 ( & V_173 , & V_38 , NULL ) ;
V_61 = F_148 ( V_15 , & V_173 , V_112 [ V_176 ] , NULL ,
log ) ;
} else if ( ! V_189 ) {
F_146 ( log ,
L_7 ) ;
V_61 = - V_70 ;
}
if ( V_61 )
return V_61 ;
F_6 () ;
V_20 = F_15 ( F_94 ( V_10 -> V_111 ) , V_78 -> V_16 ) ;
if ( ! V_20 ) {
V_61 = - V_91 ;
goto V_192;
}
if ( V_189 )
V_41 = F_151 ( & V_20 -> V_26 , & V_191 ) ;
else
V_41 = F_157 ( & V_20 -> V_26 , & V_173 ) ;
if ( ! V_41 ) {
V_61 = - V_187 ;
goto V_192;
}
V_171 = F_141 ( V_41 , V_78 -> V_16 , V_4 ,
V_182 , true , V_143 ) ;
if ( F_35 ( V_171 ) ) {
V_61 = F_61 ( V_171 ) ;
goto V_192;
}
F_8 () ;
return F_165 ( V_171 , V_4 ) ;
V_192:
F_8 () ;
return V_61 ;
}
static int F_166 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_78 * V_78 = V_4 -> V_110 ;
struct V_15 * V_15 = F_94 ( V_10 -> V_111 ) ;
struct V_37 V_38 ;
struct V_9 * V_171 ;
struct V_40 * V_41 = NULL ;
struct V_14 * V_20 ;
struct V_172 V_173 ;
struct V_141 V_191 ;
T_3 V_143 = F_145 ( V_112 [ V_174 ] ) ;
int V_61 ;
bool log = ! V_112 [ V_175 ] ;
bool V_189 ;
V_189 = F_162 ( & V_191 , V_112 [ V_179 ] , log ) ;
if ( V_112 [ V_176 ] ) {
F_147 ( & V_173 , & V_38 , NULL ) ;
V_61 = F_148 ( V_15 , & V_173 , V_112 [ V_176 ] ,
NULL , log ) ;
if ( F_45 ( V_61 ) )
return V_61 ;
}
F_6 () ;
V_20 = F_15 ( F_94 ( V_10 -> V_111 ) , V_78 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
V_61 = - V_91 ;
goto V_192;
}
if ( F_45 ( ! V_112 [ V_176 ] && ! V_189 ) ) {
V_61 = F_167 ( & V_20 -> V_26 ) ;
goto V_192;
}
if ( V_189 )
V_41 = F_151 ( & V_20 -> V_26 , & V_191 ) ;
else
V_41 = F_157 ( & V_20 -> V_26 , & V_173 ) ;
if ( F_45 ( ! V_41 ) ) {
V_61 = - V_187 ;
goto V_192;
}
F_168 ( & V_20 -> V_26 , V_41 ) ;
F_8 () ;
V_171 = F_139 ( ( const struct V_42 V_193 * ) V_41 -> V_43 ,
& V_41 -> V_163 , V_4 , false , V_143 ) ;
if ( F_153 ( V_171 ) ) {
if ( F_153 ( ! F_35 ( V_171 ) ) ) {
F_18 () ;
V_61 = F_133 ( V_41 , V_78 -> V_16 ,
V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 ,
V_194 ,
V_143 ) ;
F_19 () ;
F_79 ( V_61 < 0 ) ;
F_4 ( & V_162 , V_171 , V_4 ) ;
} else {
F_169 ( F_94 ( V_10 -> V_111 ) -> V_195 , 0 , 0 , F_61 ( V_171 ) ) ;
}
}
F_110 ( V_41 , true ) ;
return 0 ;
V_192:
F_8 () ;
return V_61 ;
}
static int F_170 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_88 * V_112 [ V_198 ] ;
struct V_78 * V_78 = F_171 ( F_172 ( V_197 -> V_199 ) ) ;
struct V_200 * V_201 ;
struct V_14 * V_20 ;
T_3 V_143 ;
int V_61 ;
V_61 = F_173 ( V_197 -> V_199 , & V_162 , V_112 ,
V_202 , V_203 ) ;
if ( V_61 )
return V_61 ;
V_143 = F_145 ( V_112 [ V_174 ] ) ;
F_18 () ;
V_20 = F_12 ( F_94 ( V_10 -> V_111 ) , V_78 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_91 ;
}
V_201 = F_51 ( V_20 -> V_26 . V_201 ) ;
for (; ; ) {
struct V_40 * V_41 ;
T_3 V_204 , V_205 ;
V_204 = V_197 -> args [ 0 ] ;
V_205 = V_197 -> args [ 1 ] ;
V_41 = F_174 ( V_201 , & V_204 , & V_205 ) ;
if ( ! V_41 )
break;
if ( F_133 ( V_41 , V_78 -> V_16 , V_10 ,
F_175 ( V_197 -> V_10 ) . V_52 ,
V_197 -> V_199 -> V_206 , V_207 ,
V_182 , V_143 ) < 0 )
break;
V_197 -> args [ 0 ] = V_204 ;
V_197 -> args [ 1 ] = V_205 ;
}
F_19 () ;
return V_10 -> V_86 ;
}
static T_4 F_176 ( void )
{
T_4 V_208 = F_63 ( sizeof( struct V_78 ) ) ;
V_208 += F_64 ( V_209 ) ;
V_208 += F_123 ( sizeof( struct V_132 ) ) ;
V_208 += F_123 ( sizeof( struct V_133 ) ) ;
V_208 += F_64 ( sizeof( T_3 ) ) ;
return V_208 ;
}
static int F_177 ( struct V_14 * V_20 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_161 , T_3 V_57 , V_157 V_50 )
{
struct V_78 * V_78 ;
struct V_132 V_210 ;
struct V_133 V_211 ;
int V_61 ;
V_78 = F_77 ( V_10 , V_52 , V_161 , & V_212 ,
V_57 , V_50 ) ;
if ( ! V_78 )
goto error;
V_78 -> V_16 = F_23 ( V_20 ) ;
V_61 = F_178 ( V_10 , V_213 , F_20 ( V_20 ) ) ;
if ( V_61 )
goto V_214;
F_111 ( V_20 , & V_210 , & V_211 ) ;
if ( F_128 ( V_10 , V_215 , sizeof( struct V_132 ) ,
& V_210 , V_216 ) )
goto V_214;
if ( F_128 ( V_10 , V_217 ,
sizeof( struct V_133 ) ,
& V_211 , V_216 ) )
goto V_214;
if ( F_179 ( V_10 , V_218 , V_20 -> V_83 ) )
goto V_214;
F_137 ( V_10 , V_78 ) ;
return 0 ;
V_214:
F_138 ( V_10 , V_78 ) ;
error:
return - V_154 ;
}
static struct V_9 * F_180 ( void )
{
return F_76 ( F_176 () , V_11 ) ;
}
static struct V_14 * F_181 ( struct V_15 * V_15 ,
const struct V_78 * V_78 ,
struct V_88 * V_112 [ V_219 + 1 ] )
{
struct V_14 * V_20 ;
if ( ! V_112 [ V_213 ] )
V_20 = F_15 ( V_15 , V_78 -> V_16 ) ;
else {
struct V_19 * V_19 ;
V_19 = F_182 ( V_15 , F_81 ( V_112 [ V_213 ] ) ) ;
V_20 = V_19 && V_19 -> V_30 == V_21 ? V_19 -> V_20 : NULL ;
}
return V_20 ? V_20 : F_140 ( - V_91 ) ;
}
static void F_183 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_14 * V_20 ;
V_20 = F_181 ( F_94 ( V_10 -> V_111 ) , V_4 -> V_110 , V_4 -> V_113 ) ;
if ( F_35 ( V_20 ) )
return;
F_184 ( V_20 -> V_83 , L_8 ) ;
V_20 -> V_83 = 0 ;
}
static void F_185 ( struct V_14 * V_20 , struct V_88 * V_112 [] )
{
if ( V_112 [ V_218 ] )
V_20 -> V_83 = F_186 ( V_112 [ V_218 ] ) ;
}
static int F_187 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_33 V_34 ;
struct V_9 * V_171 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
struct V_220 * V_220 ;
int V_61 , V_135 ;
V_61 = - V_70 ;
if ( ! V_112 [ V_213 ] || ! V_112 [ V_221 ] )
goto V_61;
V_171 = F_180 () ;
if ( ! V_171 )
return - V_93 ;
V_61 = - V_93 ;
V_20 = F_188 ( sizeof( * V_20 ) , V_11 ) ;
if ( V_20 == NULL )
goto V_222;
F_189 ( V_20 , F_94 ( V_10 -> V_111 ) ) ;
V_61 = F_190 ( & V_20 -> V_26 ) ;
if ( V_61 )
goto V_223;
V_20 -> V_27 = F_191 ( struct V_44 ) ;
if ( ! V_20 -> V_27 ) {
V_61 = - V_93 ;
goto V_224;
}
V_20 -> V_28 = F_192 ( V_31 * sizeof( struct V_29 ) ,
V_11 ) ;
if ( ! V_20 -> V_28 ) {
V_61 = - V_93 ;
goto V_225;
}
for ( V_135 = 0 ; V_135 < V_31 ; V_135 ++ )
F_193 ( & V_20 -> V_28 [ V_135 ] ) ;
V_34 . V_226 = F_81 ( V_112 [ V_213 ] ) ;
V_34 . type = V_227 ;
V_34 . V_228 = NULL ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_21 ;
V_34 . V_229 = V_112 [ V_221 ] ;
F_185 ( V_20 , V_112 ) ;
F_6 () ;
V_19 = F_33 ( & V_34 ) ;
if ( F_35 ( V_19 ) ) {
V_61 = F_61 ( V_19 ) ;
if ( V_61 == - V_230 )
V_61 = - V_186 ;
if ( V_61 == - V_186 ) {
if ( V_4 -> V_231 -> V_232 < V_233 )
F_183 ( V_10 , V_4 ) ;
}
goto V_234;
}
V_61 = F_177 ( V_20 , V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 , V_235 ) ;
F_79 ( V_61 < 0 ) ;
V_220 = F_194 ( F_91 ( V_20 ) , V_236 ) ;
F_195 ( & V_20 -> V_237 , & V_220 -> V_238 ) ;
F_8 () ;
F_4 ( & V_212 , V_171 , V_4 ) ;
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
F_48 ( V_171 ) ;
V_61:
return V_61 ;
}
static void F_196 ( struct V_14 * V_20 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_31 ; V_135 ++ ) {
struct V_19 * V_19 ;
struct V_239 * V_240 ;
F_197 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_19 -> V_30 != V_21 )
F_37 ( V_19 ) ;
}
F_198 ( & V_20 -> V_237 ) ;
F_37 ( F_199 ( V_20 , V_21 ) ) ;
F_200 ( & V_20 -> V_25 , F_25 ) ;
}
static int F_201 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_171 ;
struct V_14 * V_20 ;
int V_61 ;
V_171 = F_180 () ;
if ( ! V_171 )
return - V_93 ;
F_6 () ;
V_20 = F_181 ( F_94 ( V_10 -> V_111 ) , V_4 -> V_110 , V_4 -> V_113 ) ;
V_61 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_241;
V_61 = F_177 ( V_20 , V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 , V_242 ) ;
F_79 ( V_61 < 0 ) ;
F_196 ( V_20 ) ;
F_8 () ;
F_4 ( & V_212 , V_171 , V_4 ) ;
return 0 ;
V_241:
F_8 () ;
F_48 ( V_171 ) ;
return V_61 ;
}
static int F_202 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_171 ;
struct V_14 * V_20 ;
int V_61 ;
V_171 = F_180 () ;
if ( ! V_171 )
return - V_93 ;
F_6 () ;
V_20 = F_181 ( F_94 ( V_10 -> V_111 ) , V_4 -> V_110 , V_4 -> V_113 ) ;
V_61 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_241;
F_185 ( V_20 , V_4 -> V_113 ) ;
V_61 = F_177 ( V_20 , V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 , V_235 ) ;
F_79 ( V_61 < 0 ) ;
F_8 () ;
F_4 ( & V_212 , V_171 , V_4 ) ;
return 0 ;
V_241:
F_8 () ;
F_48 ( V_171 ) ;
return V_61 ;
}
static int F_203 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_171 ;
struct V_14 * V_20 ;
int V_61 ;
V_171 = F_180 () ;
if ( ! V_171 )
return - V_93 ;
F_6 () ;
V_20 = F_181 ( F_94 ( V_10 -> V_111 ) , V_4 -> V_110 , V_4 -> V_113 ) ;
if ( F_35 ( V_20 ) ) {
V_61 = F_61 ( V_20 ) ;
goto V_241;
}
V_61 = F_177 ( V_20 , V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 , V_235 ) ;
F_79 ( V_61 < 0 ) ;
F_8 () ;
return F_165 ( V_171 , V_4 ) ;
V_241:
F_8 () ;
F_48 ( V_171 ) ;
return V_61 ;
}
static int F_204 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_220 * V_220 = F_194 ( F_94 ( V_10 -> V_111 ) , V_236 ) ;
struct V_14 * V_20 ;
int V_243 = V_197 -> args [ 0 ] ;
int V_135 = 0 ;
F_6 () ;
F_205 (dp, &ovs_net->dps, list_node) {
if ( V_135 >= V_243 &&
F_177 ( V_20 , V_10 , F_175 ( V_197 -> V_10 ) . V_52 ,
V_197 -> V_199 -> V_206 , V_207 ,
V_235 ) < 0 )
break;
V_135 ++ ;
}
F_8 () ;
V_197 -> args [ 0 ] = V_135 ;
return V_10 -> V_86 ;
}
static int F_206 ( struct V_19 * V_19 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_161 , T_3 V_57 , V_157 V_50 )
{
struct V_78 * V_78 ;
struct V_244 V_245 ;
int V_61 ;
V_78 = F_77 ( V_10 , V_52 , V_161 , & V_246 ,
V_57 , V_50 ) ;
if ( ! V_78 )
return - V_154 ;
V_78 -> V_16 = F_23 ( V_19 -> V_20 ) ;
if ( F_179 ( V_10 , V_247 , V_19 -> V_30 ) ||
F_179 ( V_10 , V_248 , V_19 -> V_249 -> type ) ||
F_178 ( V_10 , V_250 ,
F_22 ( V_19 ) ) )
goto V_214;
F_207 ( V_19 , & V_245 ) ;
if ( F_128 ( V_10 , V_251 ,
sizeof( struct V_244 ) , & V_245 ,
V_252 ) )
goto V_214;
if ( F_208 ( V_19 , V_10 ) )
goto V_214;
V_61 = F_209 ( V_19 , V_10 ) ;
if ( V_61 == - V_154 )
goto error;
F_137 ( V_10 , V_78 ) ;
return 0 ;
V_214:
V_61 = - V_154 ;
error:
F_138 ( V_10 , V_78 ) ;
return V_61 ;
}
static struct V_9 * F_210 ( void )
{
return F_211 ( V_253 , V_11 ) ;
}
struct V_9 * F_212 ( struct V_19 * V_19 , T_3 V_52 ,
T_3 V_161 , V_157 V_50 )
{
struct V_9 * V_10 ;
int V_165 ;
V_10 = F_211 ( V_253 , V_92 ) ;
if ( ! V_10 )
return F_140 ( - V_93 ) ;
V_165 = F_206 ( V_19 , V_10 , V_52 , V_161 , 0 , V_50 ) ;
F_79 ( V_165 < 0 ) ;
return V_10 ;
}
static struct V_19 * F_213 ( struct V_15 * V_15 ,
const struct V_78 * V_78 ,
struct V_88 * V_112 [ V_254 + 1 ] )
{
struct V_14 * V_20 ;
struct V_19 * V_19 ;
if ( V_112 [ V_250 ] ) {
V_19 = F_182 ( V_15 , F_81 ( V_112 [ V_250 ] ) ) ;
if ( ! V_19 )
return F_140 ( - V_91 ) ;
if ( V_78 -> V_16 &&
V_78 -> V_16 != F_23 ( V_19 -> V_20 ) )
return F_140 ( - V_91 ) ;
return V_19 ;
} else if ( V_112 [ V_247 ] ) {
T_3 V_30 = F_186 ( V_112 [ V_247 ] ) ;
if ( V_30 >= V_255 )
return F_140 ( - V_95 ) ;
V_20 = F_15 ( V_15 , V_78 -> V_16 ) ;
if ( ! V_20 )
return F_140 ( - V_91 ) ;
V_19 = F_21 ( V_20 , V_30 ) ;
if ( ! V_19 )
return F_140 ( - V_91 ) ;
return V_19 ;
} else
return F_140 ( - V_70 ) ;
}
static void F_214 ( struct V_14 * V_20 )
{
unsigned V_256 , V_257 = 0 ;
struct V_17 * V_18 ;
struct V_19 * V_19 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_31 ; V_135 ++ ) {
F_32 (vport, &dp->ports[i], dp_hash_node) {
V_18 = V_19 -> V_18 ;
V_256 = F_215 ( V_18 ) ;
if ( V_256 > V_257 )
V_257 = V_256 ;
}
}
V_20 -> V_257 = V_257 ;
for ( V_135 = 0 ; V_135 < V_31 ; V_135 ++ )
F_32 (vport, &dp->ports[i], dp_hash_node)
F_216 ( V_19 -> V_18 , V_257 ) ;
}
static int F_217 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_78 * V_78 = V_4 -> V_110 ;
struct V_33 V_34 ;
struct V_9 * V_171 ;
struct V_19 * V_19 ;
struct V_14 * V_20 ;
T_3 V_30 ;
int V_61 ;
if ( ! V_112 [ V_250 ] || ! V_112 [ V_248 ] ||
! V_112 [ V_258 ] )
return - V_70 ;
V_30 = V_112 [ V_247 ]
? F_186 ( V_112 [ V_247 ] ) : 0 ;
if ( V_30 >= V_255 )
return - V_95 ;
V_171 = F_210 () ;
if ( ! V_171 )
return - V_93 ;
F_6 () ;
V_259:
V_20 = F_15 ( F_94 ( V_10 -> V_111 ) , V_78 -> V_16 ) ;
V_61 = - V_91 ;
if ( ! V_20 )
goto V_260;
if ( V_30 ) {
V_19 = F_199 ( V_20 , V_30 ) ;
V_61 = - V_230 ;
if ( V_19 )
goto V_260;
} else {
for ( V_30 = 1 ; ; V_30 ++ ) {
if ( V_30 >= V_255 ) {
V_61 = - V_95 ;
goto V_260;
}
V_19 = F_199 ( V_20 , V_30 ) ;
if ( ! V_19 )
break;
}
}
V_34 . V_226 = F_81 ( V_112 [ V_250 ] ) ;
V_34 . type = F_186 ( V_112 [ V_248 ] ) ;
V_34 . V_228 = V_112 [ V_261 ] ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_30 ;
V_34 . V_229 = V_112 [ V_258 ] ;
V_19 = F_33 ( & V_34 ) ;
V_61 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) ) {
if ( V_61 == - V_262 )
goto V_259;
goto V_260;
}
V_61 = F_206 ( V_19 , V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 , V_263 ) ;
if ( F_215 ( V_19 -> V_18 ) > V_20 -> V_257 )
F_214 ( V_20 ) ;
else
F_216 ( V_19 -> V_18 , V_20 -> V_257 ) ;
F_79 ( V_61 < 0 ) ;
F_8 () ;
F_4 ( & V_246 , V_171 , V_4 ) ;
return 0 ;
V_260:
F_8 () ;
F_48 ( V_171 ) ;
return V_61 ;
}
static int F_218 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_9 * V_171 ;
struct V_19 * V_19 ;
int V_61 ;
V_171 = F_210 () ;
if ( ! V_171 )
return - V_93 ;
F_6 () ;
V_19 = F_213 ( F_94 ( V_10 -> V_111 ) , V_4 -> V_110 , V_112 ) ;
V_61 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_260;
if ( V_112 [ V_248 ] &&
F_186 ( V_112 [ V_248 ] ) != V_19 -> V_249 -> type ) {
V_61 = - V_70 ;
goto V_260;
}
if ( V_112 [ V_261 ] ) {
V_61 = F_219 ( V_19 , V_112 [ V_261 ] ) ;
if ( V_61 )
goto V_260;
}
if ( V_112 [ V_258 ] ) {
struct V_88 * V_264 = V_112 [ V_258 ] ;
V_61 = F_220 ( V_19 , V_264 ) ;
if ( V_61 )
goto V_260;
}
V_61 = F_206 ( V_19 , V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 , V_263 ) ;
F_79 ( V_61 < 0 ) ;
F_8 () ;
F_4 ( & V_246 , V_171 , V_4 ) ;
return 0 ;
V_260:
F_8 () ;
F_48 ( V_171 ) ;
return V_61 ;
}
static int F_221 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
bool V_265 = false ;
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_9 * V_171 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
int V_61 ;
V_171 = F_210 () ;
if ( ! V_171 )
return - V_93 ;
F_6 () ;
V_19 = F_213 ( F_94 ( V_10 -> V_111 ) , V_4 -> V_110 , V_112 ) ;
V_61 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_260;
if ( V_19 -> V_30 == V_21 ) {
V_61 = - V_70 ;
goto V_260;
}
V_61 = F_206 ( V_19 , V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 , V_266 ) ;
F_79 ( V_61 < 0 ) ;
V_20 = V_19 -> V_20 ;
if ( F_215 ( V_19 -> V_18 ) == V_20 -> V_257 )
V_265 = true ;
F_222 ( V_19 -> V_18 ) ;
F_37 ( V_19 ) ;
if ( V_265 )
F_214 ( V_20 ) ;
F_8 () ;
F_4 ( & V_246 , V_171 , V_4 ) ;
return 0 ;
V_260:
F_8 () ;
F_48 ( V_171 ) ;
return V_61 ;
}
static int F_223 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_112 = V_4 -> V_113 ;
struct V_78 * V_78 = V_4 -> V_110 ;
struct V_9 * V_171 ;
struct V_19 * V_19 ;
int V_61 ;
V_171 = F_210 () ;
if ( ! V_171 )
return - V_93 ;
F_18 () ;
V_19 = F_213 ( F_94 ( V_10 -> V_111 ) , V_78 , V_112 ) ;
V_61 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_260;
V_61 = F_206 ( V_19 , V_171 , V_4 -> V_166 ,
V_4 -> V_167 , 0 , V_263 ) ;
F_79 ( V_61 < 0 ) ;
F_19 () ;
return F_165 ( V_171 , V_4 ) ;
V_260:
F_19 () ;
F_48 ( V_171 ) ;
return V_61 ;
}
static int F_224 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_78 * V_78 = F_171 ( F_172 ( V_197 -> V_199 ) ) ;
struct V_14 * V_20 ;
int V_204 = V_197 -> args [ 0 ] , V_243 = V_197 -> args [ 1 ] ;
int V_135 , V_267 = 0 ;
F_18 () ;
V_20 = F_12 ( F_94 ( V_10 -> V_111 ) , V_78 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_91 ;
}
for ( V_135 = V_204 ; V_135 < V_31 ; V_135 ++ ) {
struct V_19 * V_19 ;
V_267 = 0 ;
F_32 (vport, &dp->ports[i], dp_hash_node) {
if ( V_267 >= V_243 &&
F_206 ( V_19 , V_10 ,
F_175 ( V_197 -> V_10 ) . V_52 ,
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
V_197 -> args [ 0 ] = V_135 ;
V_197 -> args [ 1 ] = V_267 ;
return V_10 -> V_86 ;
}
static void F_225 ( int V_268 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_268 ; V_135 ++ )
F_226 ( V_269 [ V_135 ] ) ;
}
static int F_227 ( void )
{
int V_61 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < F_228 ( V_269 ) ; V_135 ++ ) {
V_61 = F_229 ( V_269 [ V_135 ] ) ;
if ( V_61 )
goto error;
}
return 0 ;
error:
F_225 ( V_135 ) ;
return V_61 ;
}
static int T_7 F_230 ( struct V_15 * V_15 )
{
struct V_220 * V_220 = F_194 ( V_15 , V_236 ) ;
F_231 ( & V_220 -> V_238 ) ;
F_232 ( & V_220 -> V_270 , V_271 ) ;
F_233 ( V_15 ) ;
return 0 ;
}
static void T_8 F_234 ( struct V_15 * V_15 , struct V_15 * V_272 ,
struct V_273 * V_32 )
{
struct V_220 * V_220 = F_194 ( V_15 , V_236 ) ;
struct V_14 * V_20 ;
F_205 (dp, &ovs_net->dps, list_node) {
int V_135 ;
for ( V_135 = 0 ; V_135 < V_31 ; V_135 ++ ) {
struct V_19 * V_19 ;
F_235 (vport, &dp->ports[i], dp_hash_node) {
if ( V_19 -> V_249 -> type != V_227 )
continue;
if ( F_236 ( V_19 -> V_18 ) == V_272 )
F_237 ( & V_19 -> V_274 , V_32 ) ;
}
}
}
}
static void T_8 F_238 ( struct V_15 * V_272 )
{
struct V_14 * V_20 , * V_275 ;
struct V_220 * V_220 = F_194 ( V_272 , V_236 ) ;
struct V_19 * V_19 , * V_276 ;
struct V_15 * V_15 ;
F_239 ( V_32 ) ;
F_240 ( V_272 ) ;
F_6 () ;
F_241 (dp, dp_next, &ovs_net->dps, list_node)
F_196 ( V_20 ) ;
F_242 () ;
F_243 (net)
F_234 ( V_15 , V_272 , & V_32 ) ;
F_244 () ;
F_241 (vport, vport_next, &head, detach_list) {
F_245 ( & V_19 -> V_274 ) ;
F_37 ( V_19 ) ;
}
F_8 () ;
F_246 ( & V_220 -> V_270 ) ;
}
static int T_9 F_247 ( void )
{
int V_61 ;
F_59 ( sizeof( struct V_277 ) > F_248 ( struct V_9 , V_197 ) ) ;
F_249 ( L_9 ) ;
V_61 = F_250 () ;
if ( V_61 )
goto error;
V_61 = F_251 () ;
if ( V_61 )
goto V_278;
V_61 = F_252 () ;
if ( V_61 )
goto V_279;
V_61 = F_253 () ;
if ( V_61 )
goto V_280;
V_61 = F_254 ( & V_281 ) ;
if ( V_61 )
goto V_282;
V_61 = F_255 ( & V_283 ) ;
if ( V_61 )
goto V_284;
V_61 = F_256 () ;
if ( V_61 )
goto V_285;
V_61 = F_227 () ;
if ( V_61 < 0 )
goto V_286;
return 0 ;
V_286:
F_257 () ;
V_285:
F_258 ( & V_283 ) ;
V_284:
F_259 ( & V_281 ) ;
V_282:
F_260 () ;
V_280:
F_261 () ;
V_279:
F_262 () ;
V_278:
F_263 () ;
error:
return V_61 ;
}
static void F_264 ( void )
{
F_225 ( F_228 ( V_269 ) ) ;
F_257 () ;
F_258 ( & V_283 ) ;
F_259 ( & V_281 ) ;
F_265 () ;
F_260 () ;
F_261 () ;
F_262 () ;
F_263 () ;
}
