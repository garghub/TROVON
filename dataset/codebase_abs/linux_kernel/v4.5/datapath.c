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
struct V_3 V_4 = {
. V_90 = F_70 ( V_20 ) -> V_91 ,
. V_92 = V_60 -> V_52 ,
} ;
T_4 V_86 ;
unsigned int V_93 ;
int V_61 , V_16 ;
V_16 = F_23 ( V_20 ) ;
if ( ! V_16 )
return - V_94 ;
if ( F_71 ( V_10 ) ) {
V_67 = F_72 ( V_10 , V_95 ) ;
if ( ! V_67 )
return - V_96 ;
V_67 = F_73 ( V_67 ) ;
if ( ! V_67 )
return - V_96 ;
V_10 = V_67 ;
}
if ( F_74 ( V_10 -> V_86 ) > V_97 ) {
V_61 = - V_98 ;
goto V_55;
}
if ( V_10 -> V_99 == V_100 &&
( V_61 = F_75 ( V_10 ) ) )
goto V_55;
if ( V_20 -> V_83 & V_84 )
V_93 = F_76 ( V_10 ) ;
else
V_93 = V_10 -> V_86 ;
V_86 = F_62 ( V_60 , V_93 ) ;
V_87 = F_77 ( V_86 , & V_4 , V_95 ) ;
if ( ! V_87 ) {
V_61 = - V_96 ;
goto V_55;
}
V_49 = F_78 ( V_87 , 0 , 0 , & V_101 ,
0 , V_60 -> V_50 ) ;
V_49 -> V_16 = V_16 ;
V_61 = F_79 ( V_38 , V_38 , V_102 , false , V_87 ) ;
F_80 ( V_61 ) ;
if ( V_60 -> V_79 )
F_81 ( V_87 , V_103 ,
V_80 ( V_60 -> V_79 ) ,
F_82 ( V_60 -> V_79 ) ) ;
if ( V_60 -> V_81 ) {
V_89 = F_83 ( V_87 , V_104 ) ;
V_61 = F_84 ( V_87 ,
V_60 -> V_81 ) ;
F_80 ( V_61 ) ;
F_85 ( V_87 , V_89 ) ;
}
if ( V_60 -> V_82 ) {
V_89 = F_83 ( V_87 , V_105 ) ;
V_61 = F_86 ( V_60 -> V_106 ,
V_60 -> V_82 ,
V_87 ) ;
if ( ! V_61 )
F_85 ( V_87 , V_89 ) ;
else
F_87 ( V_87 , V_89 ) ;
}
if ( V_60 -> V_53 ) {
if ( F_88 ( V_87 , V_107 ,
V_60 -> V_53 ) ) {
V_61 = - V_108 ;
goto V_55;
}
F_68 ( V_20 , V_87 ) ;
}
if ( ! ( V_89 = F_89 ( V_87 , V_109 , 0 ) ) ) {
V_61 = - V_108 ;
goto V_55;
}
V_89 -> V_80 = F_74 ( V_10 -> V_86 ) ;
V_61 = F_90 ( V_87 , V_10 , V_10 -> V_86 , V_93 ) ;
if ( V_61 )
goto V_55;
F_68 ( V_20 , V_87 ) ;
( (struct V_110 * ) V_87 -> V_111 ) -> V_112 = V_87 -> V_86 ;
V_61 = F_91 ( F_70 ( V_20 ) , V_87 , V_60 -> V_52 ) ;
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
struct V_78 * V_78 = V_4 -> V_113 ;
struct V_15 * V_15 = F_94 ( V_10 -> V_114 ) ;
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_42 * V_117 ;
struct V_9 * V_118 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_14 * V_20 ;
struct V_119 * V_120 ;
struct V_19 * V_39 ;
T_1 V_53 = 0 ;
int V_86 ;
int V_61 ;
bool log = ! V_115 [ V_121 ] ;
V_61 = - V_70 ;
if ( ! V_115 [ V_109 ] || ! V_115 [ V_102 ] ||
! V_115 [ V_105 ] )
goto V_61;
V_86 = V_80 ( V_115 [ V_109 ] ) ;
V_118 = F_95 ( V_122 + V_86 , V_11 ) ;
V_61 = - V_96 ;
if ( ! V_118 )
goto V_61;
F_96 ( V_118 , V_122 ) ;
F_97 ( F_98 ( V_118 , V_86 ) , V_115 [ V_109 ] , V_86 ) ;
F_99 ( V_118 ) ;
V_120 = F_100 ( V_118 ) ;
if ( F_101 ( V_120 -> V_123 ) )
V_118 -> V_124 = V_120 -> V_123 ;
else
V_118 -> V_124 = F_102 ( V_125 ) ;
if ( V_115 [ V_107 ] ) {
V_53 = F_103 ( V_115 [ V_107 ] ) ;
V_118 -> V_126 = 1 ;
}
F_42 ( V_118 ) -> V_53 = V_53 ;
V_41 = F_104 () ;
V_61 = F_61 ( V_41 ) ;
if ( F_35 ( V_41 ) )
goto V_127;
V_61 = F_105 ( V_15 , V_115 [ V_102 ] ,
V_118 , & V_41 -> V_38 , log ) ;
if ( V_61 )
goto V_128;
V_61 = F_106 ( V_15 , V_115 [ V_105 ] ,
& V_41 -> V_38 , & V_117 , log ) ;
if ( V_61 )
goto V_128;
F_107 ( V_41 -> V_43 , V_117 ) ;
V_118 -> V_129 = V_41 -> V_38 . V_130 . V_129 ;
V_118 -> V_131 = V_41 -> V_38 . V_130 . V_132 ;
F_18 () ;
V_20 = F_12 ( V_15 , V_78 -> V_16 ) ;
V_61 = - V_94 ;
if ( ! V_20 )
goto V_133;
V_39 = F_24 ( V_20 , V_41 -> V_38 . V_130 . V_134 ) ;
if ( ! V_39 )
V_39 = F_24 ( V_20 , V_21 ) ;
if ( ! V_39 )
goto V_133;
V_118 -> V_18 = V_39 -> V_18 ;
F_42 ( V_118 ) -> V_39 = V_39 ;
V_43 = F_51 ( V_41 -> V_43 ) ;
F_108 () ;
V_61 = F_52 ( V_20 , V_118 , V_43 , & V_41 -> V_38 ) ;
F_109 () ;
F_19 () ;
F_110 ( V_41 , false ) ;
return V_61 ;
V_133:
F_19 () ;
V_128:
F_110 ( V_41 , false ) ;
V_127:
F_48 ( V_118 ) ;
V_61:
return V_61 ;
}
static void F_111 ( const struct V_14 * V_20 , struct V_135 * V_45 ,
struct V_136 * V_137 )
{
int V_138 ;
memset ( V_137 , 0 , sizeof( * V_137 ) ) ;
V_45 -> V_139 = F_112 ( & V_20 -> V_26 ) ;
V_137 -> V_140 = F_113 ( & V_20 -> V_26 ) ;
V_45 -> V_58 = V_45 -> V_54 = V_45 -> V_63 = 0 ;
F_114 (i) {
const struct V_44 * V_141 ;
struct V_44 V_142 ;
unsigned int V_143 ;
V_141 = F_115 ( V_20 -> V_27 , V_138 ) ;
do {
V_143 = F_116 ( & V_141 -> V_59 ) ;
V_142 = * V_141 ;
} while ( F_117 ( & V_141 -> V_59 , V_143 ) );
V_45 -> V_58 += V_142 . V_58 ;
V_45 -> V_54 += V_142 . V_54 ;
V_45 -> V_63 += V_142 . V_63 ;
V_137 -> V_47 += V_142 . V_47 ;
}
}
static bool F_118 ( const struct V_144 * V_145 , T_5 V_146 )
{
return F_119 ( V_145 ) &&
! ( V_146 & V_147 ) ;
}
static bool F_120 ( T_5 V_146 )
{
return ! ( V_146 & V_148 ) ;
}
static bool F_121 ( T_5 V_146 )
{
return ! ( V_146 & V_149 ) ;
}
static T_4 F_122 ( const struct V_42 * V_117 ,
const struct V_144 * V_145 ,
T_5 V_146 )
{
T_4 V_86 = F_63 ( sizeof( struct V_78 ) ) ;
if ( V_145 && F_119 ( V_145 ) )
V_86 += F_64 ( V_145 -> V_150 ) ;
if ( ! V_145 || F_118 ( V_145 , V_146 ) )
V_86 += F_64 ( F_65 () ) ;
if ( F_120 ( V_146 ) )
V_86 += F_64 ( F_65 () ) ;
if ( F_121 ( V_146 ) )
V_86 += F_64 ( V_117 -> V_151 ) ;
return V_86
+ F_64 ( sizeof( struct V_152 ) )
+ F_64 ( 1 )
+ F_64 ( 8 ) ;
}
static int F_123 ( const struct V_40 * V_41 ,
struct V_9 * V_10 )
{
struct V_152 V_45 ;
T_6 V_153 ;
unsigned long V_154 ;
F_124 ( V_41 , & V_45 , & V_154 , & V_153 ) ;
if ( V_154 &&
F_125 ( V_10 , V_155 , F_126 ( V_154 ) ) )
return - V_156 ;
if ( V_45 . V_157 &&
F_127 ( V_10 , V_158 , sizeof( struct V_152 ) , & V_45 ) )
return - V_156 ;
if ( ( V_159 ) F_128 ( V_153 ) &&
F_129 ( V_10 , V_160 , ( V_159 ) F_128 ( V_153 ) ) )
return - V_156 ;
return 0 ;
}
static int F_130 ( const struct V_40 * V_41 ,
struct V_9 * V_10 , int V_161 )
{
struct V_88 * V_143 ;
int V_61 ;
V_143 = F_83 ( V_10 , V_162 ) ;
if ( V_143 ) {
const struct V_42 * V_43 ;
V_43 = F_131 ( V_41 -> V_43 ) ;
V_61 = F_86 ( V_43 -> V_106 ,
V_43 -> V_82 , V_10 ) ;
if ( ! V_61 )
F_85 ( V_10 , V_143 ) ;
else {
if ( V_161 )
return V_61 ;
F_87 ( V_10 , V_143 ) ;
}
} else if ( V_161 ) {
return - V_156 ;
}
return 0 ;
}
static int F_132 ( const struct V_40 * V_41 , int V_16 ,
struct V_9 * V_10 , T_3 V_52 ,
T_3 V_163 , T_3 V_57 , V_159 V_50 , T_3 V_146 )
{
const int V_161 = V_10 -> V_86 ;
struct V_78 * V_78 ;
int V_61 ;
V_78 = F_78 ( V_10 , V_52 , V_163 , & V_164 ,
V_57 , V_50 ) ;
if ( ! V_78 )
return - V_156 ;
V_78 -> V_16 = V_16 ;
V_61 = F_133 ( V_41 , V_10 ) ;
if ( V_61 )
goto error;
if ( F_118 ( & V_41 -> V_165 , V_146 ) ) {
V_61 = F_134 ( V_41 , V_10 ) ;
if ( V_61 )
goto error;
}
if ( F_120 ( V_146 ) ) {
V_61 = F_135 ( V_41 , V_10 ) ;
if ( V_61 )
goto error;
}
V_61 = F_123 ( V_41 , V_10 ) ;
if ( V_61 )
goto error;
if ( F_121 ( V_146 ) ) {
V_61 = F_130 ( V_41 , V_10 , V_161 ) ;
if ( V_61 )
goto error;
}
F_136 ( V_10 , V_78 ) ;
return 0 ;
error:
F_137 ( V_10 , V_78 ) ;
return V_61 ;
}
static struct V_9 * F_138 ( const struct V_42 * V_117 ,
const struct V_144 * V_145 ,
struct V_3 * V_4 ,
bool V_166 ,
T_5 V_146 )
{
struct V_9 * V_10 ;
T_4 V_86 ;
if ( ! V_166 && ! F_1 ( & V_164 , V_4 , 0 ) )
return NULL ;
V_86 = F_122 ( V_117 , V_145 , V_146 ) ;
V_10 = F_77 ( V_86 , V_4 , V_11 ) ;
if ( ! V_10 )
return F_139 ( - V_96 ) ;
return V_10 ;
}
static struct V_9 * F_140 ( const struct V_40 * V_41 ,
int V_16 ,
struct V_3 * V_4 , V_159 V_50 ,
bool V_166 , T_3 V_146 )
{
struct V_9 * V_10 ;
int V_167 ;
V_10 = F_138 ( F_141 ( V_41 -> V_43 ) ,
& V_41 -> V_165 , V_4 , V_166 , V_146 ) ;
if ( F_142 ( V_10 ) )
return V_10 ;
V_167 = F_132 ( V_41 , V_16 , V_10 ,
V_4 -> V_92 , V_4 -> V_168 , 0 ,
V_50 , V_146 ) ;
F_80 ( V_167 < 0 ) ;
return V_10 ;
}
static int F_143 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_94 ( V_10 -> V_114 ) ;
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_78 * V_78 = V_4 -> V_113 ;
struct V_40 * V_41 = NULL , * V_169 ;
struct V_170 V_171 ;
struct V_9 * V_172 ;
struct V_14 * V_20 ;
struct V_37 V_38 ;
struct V_42 * V_117 ;
struct V_173 V_174 ;
T_3 V_146 = F_144 ( V_115 [ V_175 ] ) ;
int error ;
bool log = ! V_115 [ V_176 ] ;
error = - V_70 ;
if ( ! V_115 [ V_177 ] ) {
F_145 ( log , L_1 ) ;
goto error;
}
if ( ! V_115 [ V_162 ] ) {
F_145 ( log , L_2 ) ;
goto error;
}
V_169 = F_104 () ;
if ( F_35 ( V_169 ) ) {
error = F_61 ( V_169 ) ;
goto error;
}
F_146 ( & V_174 , & V_38 , & V_171 ) ;
error = F_147 ( V_15 , & V_174 , V_115 [ V_177 ] ,
V_115 [ V_178 ] , log ) ;
if ( error )
goto V_179;
F_148 ( & V_169 -> V_38 , & V_38 , true , & V_171 ) ;
error = F_149 ( & V_169 -> V_165 , V_115 [ V_180 ] ,
& V_38 , log ) ;
if ( error )
goto V_179;
error = F_106 ( V_15 , V_115 [ V_162 ] ,
& V_169 -> V_38 , & V_117 , log ) ;
if ( error ) {
F_145 ( log , L_3 ) ;
goto V_179;
}
V_172 = F_138 ( V_117 , & V_169 -> V_165 , V_4 , false ,
V_146 ) ;
if ( F_35 ( V_172 ) ) {
error = F_61 ( V_172 ) ;
goto V_181;
}
F_6 () ;
V_20 = F_15 ( V_15 , V_78 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_94 ;
goto V_182;
}
if ( F_119 ( & V_169 -> V_165 ) )
V_41 = F_150 ( & V_20 -> V_26 , & V_169 -> V_165 ) ;
if ( ! V_41 )
V_41 = F_151 ( & V_20 -> V_26 , & V_38 ) ;
if ( F_152 ( ! V_41 ) ) {
F_107 ( V_169 -> V_43 , V_117 ) ;
error = F_153 ( & V_20 -> V_26 , V_169 , & V_171 ) ;
if ( F_45 ( error ) ) {
V_117 = NULL ;
goto V_182;
}
if ( F_45 ( V_172 ) ) {
error = F_132 ( V_169 ,
V_78 -> V_16 ,
V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 ,
V_183 ,
V_146 ) ;
F_80 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_42 * V_184 ;
if ( F_45 ( V_4 -> V_6 -> V_7 & ( V_185
| V_186 ) ) ) {
error = - V_187 ;
goto V_182;
}
if ( F_45 ( ! F_154 ( V_41 , & V_174 ) ) ) {
if ( F_155 ( & V_41 -> V_165 ) )
V_41 = F_156 ( & V_20 -> V_26 ,
& V_174 ) ;
else
V_41 = NULL ;
if ( ! V_41 ) {
error = - V_188 ;
goto V_182;
}
}
V_184 = F_141 ( V_41 -> V_43 ) ;
F_107 ( V_41 -> V_43 , V_117 ) ;
if ( F_45 ( V_172 ) ) {
error = F_132 ( V_41 ,
V_78 -> V_16 ,
V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 ,
V_183 ,
V_146 ) ;
F_80 ( error < 0 ) ;
}
F_8 () ;
F_157 ( V_184 ) ;
F_110 ( V_169 , false ) ;
}
if ( V_172 )
F_4 ( & V_164 , V_172 , V_4 ) ;
return 0 ;
V_182:
F_8 () ;
F_48 ( V_172 ) ;
V_181:
F_158 ( V_117 ) ;
V_179:
F_110 ( V_169 , false ) ;
error:
return error ;
}
static struct V_42 * F_159 ( struct V_15 * V_15 ,
const struct V_88 * V_115 ,
const struct V_37 * V_38 ,
const struct V_170 * V_171 ,
bool log )
{
struct V_42 * V_117 ;
struct V_37 V_189 ;
int error ;
F_148 ( & V_189 , V_38 , true , V_171 ) ;
error = F_106 ( V_15 , V_115 , & V_189 , & V_117 , log ) ;
if ( error ) {
F_145 ( log ,
L_4 ) ;
return F_139 ( error ) ;
}
return V_117 ;
}
static int F_160 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_94 ( V_10 -> V_114 ) ;
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_78 * V_78 = V_4 -> V_113 ;
struct V_37 V_38 ;
struct V_40 * V_41 ;
struct V_170 V_171 ;
struct V_9 * V_172 = NULL ;
struct V_14 * V_20 ;
struct V_42 * V_184 = NULL , * V_117 = NULL ;
struct V_173 V_174 ;
struct V_144 V_145 ;
T_3 V_146 = F_144 ( V_115 [ V_175 ] ) ;
int error ;
bool log = ! V_115 [ V_176 ] ;
bool V_190 ;
error = - V_70 ;
if ( ! V_115 [ V_177 ] ) {
F_145 ( log , L_5 ) ;
goto error;
}
V_190 = F_161 ( & V_145 , V_115 [ V_180 ] , log ) ;
F_146 ( & V_174 , & V_38 , & V_171 ) ;
error = F_147 ( V_15 , & V_174 , V_115 [ V_177 ] ,
V_115 [ V_178 ] , log ) ;
if ( error )
goto error;
if ( V_115 [ V_162 ] ) {
V_117 = F_159 ( V_15 , V_115 [ V_162 ] , & V_38 ,
& V_171 , log ) ;
if ( F_35 ( V_117 ) ) {
error = F_61 ( V_117 ) ;
goto error;
}
V_172 = F_138 ( V_117 , & V_145 , V_4 , false ,
V_146 ) ;
if ( F_35 ( V_172 ) ) {
error = F_61 ( V_172 ) ;
goto V_181;
}
}
F_6 () ;
V_20 = F_15 ( V_15 , V_78 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_94 ;
goto V_182;
}
if ( V_190 )
V_41 = F_150 ( & V_20 -> V_26 , & V_145 ) ;
else
V_41 = F_156 ( & V_20 -> V_26 , & V_174 ) ;
if ( F_45 ( ! V_41 ) ) {
error = - V_188 ;
goto V_182;
}
if ( F_152 ( V_117 ) ) {
V_184 = F_141 ( V_41 -> V_43 ) ;
F_107 ( V_41 -> V_43 , V_117 ) ;
if ( F_45 ( V_172 ) ) {
error = F_132 ( V_41 ,
V_78 -> V_16 ,
V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 ,
V_183 ,
V_146 ) ;
F_80 ( error < 0 ) ;
}
} else {
V_172 = F_140 ( V_41 , V_78 -> V_16 ,
V_4 , V_183 , false ,
V_146 ) ;
if ( F_35 ( V_172 ) ) {
error = F_61 ( V_172 ) ;
goto V_182;
}
}
if ( V_115 [ V_191 ] )
F_162 ( V_41 ) ;
F_8 () ;
if ( V_172 )
F_4 ( & V_164 , V_172 , V_4 ) ;
if ( V_184 )
F_157 ( V_184 ) ;
return 0 ;
V_182:
F_8 () ;
F_48 ( V_172 ) ;
V_181:
F_158 ( V_117 ) ;
error:
return error ;
}
static int F_163 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_78 * V_78 = V_4 -> V_113 ;
struct V_15 * V_15 = F_94 ( V_10 -> V_114 ) ;
struct V_37 V_38 ;
struct V_9 * V_172 ;
struct V_40 * V_41 ;
struct V_14 * V_20 ;
struct V_173 V_174 ;
struct V_144 V_192 ;
T_3 V_146 = F_144 ( V_115 [ V_175 ] ) ;
int V_61 = 0 ;
bool log = ! V_115 [ V_176 ] ;
bool V_190 ;
V_190 = F_161 ( & V_192 , V_115 [ V_180 ] , log ) ;
if ( V_115 [ V_177 ] ) {
F_146 ( & V_174 , & V_38 , NULL ) ;
V_61 = F_147 ( V_15 , & V_174 , V_115 [ V_177 ] , NULL ,
log ) ;
} else if ( ! V_190 ) {
F_145 ( log ,
L_6 ) ;
V_61 = - V_70 ;
}
if ( V_61 )
return V_61 ;
F_6 () ;
V_20 = F_15 ( F_94 ( V_10 -> V_114 ) , V_78 -> V_16 ) ;
if ( ! V_20 ) {
V_61 = - V_94 ;
goto V_193;
}
if ( V_190 )
V_41 = F_150 ( & V_20 -> V_26 , & V_192 ) ;
else
V_41 = F_156 ( & V_20 -> V_26 , & V_174 ) ;
if ( ! V_41 ) {
V_61 = - V_188 ;
goto V_193;
}
V_172 = F_140 ( V_41 , V_78 -> V_16 , V_4 ,
V_183 , true , V_146 ) ;
if ( F_35 ( V_172 ) ) {
V_61 = F_61 ( V_172 ) ;
goto V_193;
}
F_8 () ;
return F_164 ( V_172 , V_4 ) ;
V_193:
F_8 () ;
return V_61 ;
}
static int F_165 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_78 * V_78 = V_4 -> V_113 ;
struct V_15 * V_15 = F_94 ( V_10 -> V_114 ) ;
struct V_37 V_38 ;
struct V_9 * V_172 ;
struct V_40 * V_41 = NULL ;
struct V_14 * V_20 ;
struct V_173 V_174 ;
struct V_144 V_192 ;
T_3 V_146 = F_144 ( V_115 [ V_175 ] ) ;
int V_61 ;
bool log = ! V_115 [ V_176 ] ;
bool V_190 ;
V_190 = F_161 ( & V_192 , V_115 [ V_180 ] , log ) ;
if ( V_115 [ V_177 ] ) {
F_146 ( & V_174 , & V_38 , NULL ) ;
V_61 = F_147 ( V_15 , & V_174 , V_115 [ V_177 ] ,
NULL , log ) ;
if ( F_45 ( V_61 ) )
return V_61 ;
}
F_6 () ;
V_20 = F_15 ( F_94 ( V_10 -> V_114 ) , V_78 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
V_61 = - V_94 ;
goto V_193;
}
if ( F_45 ( ! V_115 [ V_177 ] && ! V_190 ) ) {
V_61 = F_166 ( & V_20 -> V_26 ) ;
goto V_193;
}
if ( V_190 )
V_41 = F_150 ( & V_20 -> V_26 , & V_192 ) ;
else
V_41 = F_156 ( & V_20 -> V_26 , & V_174 ) ;
if ( F_45 ( ! V_41 ) ) {
V_61 = - V_188 ;
goto V_193;
}
F_167 ( & V_20 -> V_26 , V_41 ) ;
F_8 () ;
V_172 = F_138 ( ( const struct V_42 V_194 * ) V_41 -> V_43 ,
& V_41 -> V_165 , V_4 , false , V_146 ) ;
if ( F_152 ( V_172 ) ) {
if ( F_152 ( ! F_35 ( V_172 ) ) ) {
F_18 () ;
V_61 = F_132 ( V_41 , V_78 -> V_16 ,
V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 ,
V_195 ,
V_146 ) ;
F_19 () ;
F_80 ( V_61 < 0 ) ;
F_4 ( & V_164 , V_172 , V_4 ) ;
} else {
F_168 ( F_94 ( V_10 -> V_114 ) -> V_91 , 0 , 0 , F_61 ( V_172 ) ) ;
}
}
F_110 ( V_41 , true ) ;
return 0 ;
V_193:
F_8 () ;
return V_61 ;
}
static int F_169 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_88 * V_115 [ V_198 ] ;
struct V_78 * V_78 = F_170 ( F_171 ( V_197 -> V_199 ) ) ;
struct V_200 * V_201 ;
struct V_14 * V_20 ;
T_3 V_146 ;
int V_61 ;
V_61 = F_172 ( V_197 -> V_199 , & V_164 , V_115 ,
V_202 , V_203 ) ;
if ( V_61 )
return V_61 ;
V_146 = F_144 ( V_115 [ V_175 ] ) ;
F_18 () ;
V_20 = F_12 ( F_94 ( V_10 -> V_114 ) , V_78 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_94 ;
}
V_201 = F_51 ( V_20 -> V_26 . V_201 ) ;
for (; ; ) {
struct V_40 * V_41 ;
T_3 V_204 , V_205 ;
V_204 = V_197 -> args [ 0 ] ;
V_205 = V_197 -> args [ 1 ] ;
V_41 = F_173 ( V_201 , & V_204 , & V_205 ) ;
if ( ! V_41 )
break;
if ( F_132 ( V_41 , V_78 -> V_16 , V_10 ,
F_174 ( V_197 -> V_10 ) . V_52 ,
V_197 -> V_199 -> V_206 , V_207 ,
V_183 , V_146 ) < 0 )
break;
V_197 -> args [ 0 ] = V_204 ;
V_197 -> args [ 1 ] = V_205 ;
}
F_19 () ;
return V_10 -> V_86 ;
}
static T_4 F_175 ( void )
{
T_4 V_208 = F_63 ( sizeof( struct V_78 ) ) ;
V_208 += F_64 ( V_209 ) ;
V_208 += F_64 ( sizeof( struct V_135 ) ) ;
V_208 += F_64 ( sizeof( struct V_136 ) ) ;
V_208 += F_64 ( sizeof( T_3 ) ) ;
return V_208 ;
}
static int F_176 ( struct V_14 * V_20 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_163 , T_3 V_57 , V_159 V_50 )
{
struct V_78 * V_78 ;
struct V_135 V_210 ;
struct V_136 V_211 ;
int V_61 ;
V_78 = F_78 ( V_10 , V_52 , V_163 , & V_212 ,
V_57 , V_50 ) ;
if ( ! V_78 )
goto error;
V_78 -> V_16 = F_23 ( V_20 ) ;
V_61 = F_177 ( V_10 , V_213 , F_20 ( V_20 ) ) ;
if ( V_61 )
goto V_214;
F_111 ( V_20 , & V_210 , & V_211 ) ;
if ( F_127 ( V_10 , V_215 , sizeof( struct V_135 ) ,
& V_210 ) )
goto V_214;
if ( F_127 ( V_10 , V_216 ,
sizeof( struct V_136 ) ,
& V_211 ) )
goto V_214;
if ( F_178 ( V_10 , V_217 , V_20 -> V_83 ) )
goto V_214;
F_136 ( V_10 , V_78 ) ;
return 0 ;
V_214:
F_137 ( V_10 , V_78 ) ;
error:
return - V_156 ;
}
static struct V_9 * F_179 ( struct V_3 * V_4 )
{
return F_77 ( F_175 () , V_4 , V_11 ) ;
}
static struct V_14 * F_180 ( struct V_15 * V_15 ,
const struct V_78 * V_78 ,
struct V_88 * V_115 [ V_218 + 1 ] )
{
struct V_14 * V_20 ;
if ( ! V_115 [ V_213 ] )
V_20 = F_15 ( V_15 , V_78 -> V_16 ) ;
else {
struct V_19 * V_19 ;
V_19 = F_181 ( V_15 , F_82 ( V_115 [ V_213 ] ) ) ;
V_20 = V_19 && V_19 -> V_30 == V_21 ? V_19 -> V_20 : NULL ;
}
return V_20 ? V_20 : F_139 ( - V_94 ) ;
}
static void F_182 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_14 * V_20 ;
V_20 = F_180 ( F_94 ( V_10 -> V_114 ) , V_4 -> V_113 , V_4 -> V_116 ) ;
if ( F_35 ( V_20 ) )
return;
F_183 ( V_20 -> V_83 , L_7 ) ;
V_20 -> V_83 = 0 ;
}
static void F_184 ( struct V_14 * V_20 , struct V_88 * V_115 [] )
{
if ( V_115 [ V_217 ] )
V_20 -> V_83 = F_185 ( V_115 [ V_217 ] ) ;
}
static int F_186 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_33 V_34 ;
struct V_9 * V_172 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
struct V_219 * V_219 ;
int V_61 , V_138 ;
V_61 = - V_70 ;
if ( ! V_115 [ V_213 ] || ! V_115 [ V_220 ] )
goto V_61;
V_172 = F_179 ( V_4 ) ;
if ( ! V_172 )
return - V_96 ;
V_61 = - V_96 ;
V_20 = F_187 ( sizeof( * V_20 ) , V_11 ) ;
if ( V_20 == NULL )
goto V_221;
F_188 ( V_20 , F_94 ( V_10 -> V_114 ) ) ;
V_61 = F_189 ( & V_20 -> V_26 ) ;
if ( V_61 )
goto V_222;
V_20 -> V_27 = F_190 ( struct V_44 ) ;
if ( ! V_20 -> V_27 ) {
V_61 = - V_96 ;
goto V_223;
}
V_20 -> V_28 = F_191 ( V_31 * sizeof( struct V_29 ) ,
V_11 ) ;
if ( ! V_20 -> V_28 ) {
V_61 = - V_96 ;
goto V_224;
}
for ( V_138 = 0 ; V_138 < V_31 ; V_138 ++ )
F_192 ( & V_20 -> V_28 [ V_138 ] ) ;
V_34 . V_225 = F_82 ( V_115 [ V_213 ] ) ;
V_34 . type = V_226 ;
V_34 . V_227 = NULL ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_21 ;
V_34 . V_228 = V_115 [ V_220 ] ;
F_184 ( V_20 , V_115 ) ;
F_6 () ;
V_19 = F_33 ( & V_34 ) ;
if ( F_35 ( V_19 ) ) {
V_61 = F_61 ( V_19 ) ;
if ( V_61 == - V_229 )
V_61 = - V_187 ;
if ( V_61 == - V_187 ) {
if ( V_4 -> V_230 -> V_231 < V_232 )
F_182 ( V_10 , V_4 ) ;
}
goto V_233;
}
V_61 = F_176 ( V_20 , V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 , V_234 ) ;
F_80 ( V_61 < 0 ) ;
V_219 = F_193 ( F_70 ( V_20 ) , V_235 ) ;
F_194 ( & V_20 -> V_236 , & V_219 -> V_237 ) ;
F_8 () ;
F_4 ( & V_212 , V_172 , V_4 ) ;
return 0 ;
V_233:
F_8 () ;
F_29 ( V_20 -> V_28 ) ;
V_224:
F_28 ( V_20 -> V_27 ) ;
V_223:
F_27 ( & V_20 -> V_26 ) ;
V_222:
F_29 ( V_20 ) ;
V_221:
F_48 ( V_172 ) ;
V_61:
return V_61 ;
}
static void F_195 ( struct V_14 * V_20 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_31 ; V_138 ++ ) {
struct V_19 * V_19 ;
struct V_238 * V_239 ;
F_196 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_19 -> V_30 != V_21 )
F_37 ( V_19 ) ;
}
F_197 ( & V_20 -> V_236 ) ;
F_37 ( F_198 ( V_20 , V_21 ) ) ;
F_199 ( & V_20 -> V_25 , F_25 ) ;
}
static int F_200 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_172 ;
struct V_14 * V_20 ;
int V_61 ;
V_172 = F_179 ( V_4 ) ;
if ( ! V_172 )
return - V_96 ;
F_6 () ;
V_20 = F_180 ( F_94 ( V_10 -> V_114 ) , V_4 -> V_113 , V_4 -> V_116 ) ;
V_61 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_240;
V_61 = F_176 ( V_20 , V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 , V_241 ) ;
F_80 ( V_61 < 0 ) ;
F_195 ( V_20 ) ;
F_8 () ;
F_4 ( & V_212 , V_172 , V_4 ) ;
return 0 ;
V_240:
F_8 () ;
F_48 ( V_172 ) ;
return V_61 ;
}
static int F_201 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_172 ;
struct V_14 * V_20 ;
int V_61 ;
V_172 = F_179 ( V_4 ) ;
if ( ! V_172 )
return - V_96 ;
F_6 () ;
V_20 = F_180 ( F_94 ( V_10 -> V_114 ) , V_4 -> V_113 , V_4 -> V_116 ) ;
V_61 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_240;
F_184 ( V_20 , V_4 -> V_116 ) ;
V_61 = F_176 ( V_20 , V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 , V_234 ) ;
F_80 ( V_61 < 0 ) ;
F_8 () ;
F_4 ( & V_212 , V_172 , V_4 ) ;
return 0 ;
V_240:
F_8 () ;
F_48 ( V_172 ) ;
return V_61 ;
}
static int F_202 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_172 ;
struct V_14 * V_20 ;
int V_61 ;
V_172 = F_179 ( V_4 ) ;
if ( ! V_172 )
return - V_96 ;
F_6 () ;
V_20 = F_180 ( F_94 ( V_10 -> V_114 ) , V_4 -> V_113 , V_4 -> V_116 ) ;
if ( F_35 ( V_20 ) ) {
V_61 = F_61 ( V_20 ) ;
goto V_240;
}
V_61 = F_176 ( V_20 , V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 , V_234 ) ;
F_80 ( V_61 < 0 ) ;
F_8 () ;
return F_164 ( V_172 , V_4 ) ;
V_240:
F_8 () ;
F_48 ( V_172 ) ;
return V_61 ;
}
static int F_203 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_219 * V_219 = F_193 ( F_94 ( V_10 -> V_114 ) , V_235 ) ;
struct V_14 * V_20 ;
int V_242 = V_197 -> args [ 0 ] ;
int V_138 = 0 ;
F_6 () ;
F_204 (dp, &ovs_net->dps, list_node) {
if ( V_138 >= V_242 &&
F_176 ( V_20 , V_10 , F_174 ( V_197 -> V_10 ) . V_52 ,
V_197 -> V_199 -> V_206 , V_207 ,
V_234 ) < 0 )
break;
V_138 ++ ;
}
F_8 () ;
V_197 -> args [ 0 ] = V_138 ;
return V_10 -> V_86 ;
}
static int F_205 ( struct V_19 * V_19 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_163 , T_3 V_57 , V_159 V_50 )
{
struct V_78 * V_78 ;
struct V_243 V_244 ;
int V_61 ;
V_78 = F_78 ( V_10 , V_52 , V_163 , & V_245 ,
V_57 , V_50 ) ;
if ( ! V_78 )
return - V_156 ;
V_78 -> V_16 = F_23 ( V_19 -> V_20 ) ;
if ( F_178 ( V_10 , V_246 , V_19 -> V_30 ) ||
F_178 ( V_10 , V_247 , V_19 -> V_248 -> type ) ||
F_177 ( V_10 , V_249 ,
F_22 ( V_19 ) ) )
goto V_214;
F_206 ( V_19 , & V_244 ) ;
if ( F_127 ( V_10 , V_250 , sizeof( struct V_243 ) ,
& V_244 ) )
goto V_214;
if ( F_207 ( V_19 , V_10 ) )
goto V_214;
V_61 = F_208 ( V_19 , V_10 ) ;
if ( V_61 == - V_156 )
goto error;
F_136 ( V_10 , V_78 ) ;
return 0 ;
V_214:
V_61 = - V_156 ;
error:
F_137 ( V_10 , V_78 ) ;
return V_61 ;
}
static struct V_9 * F_209 ( void )
{
return F_210 ( V_251 , V_11 ) ;
}
struct V_9 * F_211 ( struct V_19 * V_19 , T_3 V_52 ,
T_3 V_163 , V_159 V_50 )
{
struct V_9 * V_10 ;
int V_167 ;
V_10 = F_210 ( V_251 , V_95 ) ;
if ( ! V_10 )
return F_139 ( - V_96 ) ;
V_167 = F_205 ( V_19 , V_10 , V_52 , V_163 , 0 , V_50 ) ;
F_80 ( V_167 < 0 ) ;
return V_10 ;
}
static struct V_19 * F_212 ( struct V_15 * V_15 ,
const struct V_78 * V_78 ,
struct V_88 * V_115 [ V_252 + 1 ] )
{
struct V_14 * V_20 ;
struct V_19 * V_19 ;
if ( V_115 [ V_249 ] ) {
V_19 = F_181 ( V_15 , F_82 ( V_115 [ V_249 ] ) ) ;
if ( ! V_19 )
return F_139 ( - V_94 ) ;
if ( V_78 -> V_16 &&
V_78 -> V_16 != F_23 ( V_19 -> V_20 ) )
return F_139 ( - V_94 ) ;
return V_19 ;
} else if ( V_115 [ V_246 ] ) {
T_3 V_30 = F_185 ( V_115 [ V_246 ] ) ;
if ( V_30 >= V_253 )
return F_139 ( - V_98 ) ;
V_20 = F_15 ( V_15 , V_78 -> V_16 ) ;
if ( ! V_20 )
return F_139 ( - V_94 ) ;
V_19 = F_21 ( V_20 , V_30 ) ;
if ( ! V_19 )
return F_139 ( - V_94 ) ;
return V_19 ;
} else
return F_139 ( - V_70 ) ;
}
static int F_213 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_78 * V_78 = V_4 -> V_113 ;
struct V_33 V_34 ;
struct V_9 * V_172 ;
struct V_19 * V_19 ;
struct V_14 * V_20 ;
T_3 V_30 ;
int V_61 ;
if ( ! V_115 [ V_249 ] || ! V_115 [ V_247 ] ||
! V_115 [ V_254 ] )
return - V_70 ;
V_30 = V_115 [ V_246 ]
? F_185 ( V_115 [ V_246 ] ) : 0 ;
if ( V_30 >= V_253 )
return - V_98 ;
V_172 = F_209 () ;
if ( ! V_172 )
return - V_96 ;
F_6 () ;
V_255:
V_20 = F_15 ( F_94 ( V_10 -> V_114 ) , V_78 -> V_16 ) ;
V_61 = - V_94 ;
if ( ! V_20 )
goto V_256;
if ( V_30 ) {
V_19 = F_198 ( V_20 , V_30 ) ;
V_61 = - V_229 ;
if ( V_19 )
goto V_256;
} else {
for ( V_30 = 1 ; ; V_30 ++ ) {
if ( V_30 >= V_253 ) {
V_61 = - V_98 ;
goto V_256;
}
V_19 = F_198 ( V_20 , V_30 ) ;
if ( ! V_19 )
break;
}
}
V_34 . V_225 = F_82 ( V_115 [ V_249 ] ) ;
V_34 . type = F_185 ( V_115 [ V_247 ] ) ;
V_34 . V_227 = V_115 [ V_257 ] ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_30 ;
V_34 . V_228 = V_115 [ V_254 ] ;
V_19 = F_33 ( & V_34 ) ;
V_61 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) ) {
if ( V_61 == - V_258 )
goto V_255;
goto V_256;
}
V_61 = F_205 ( V_19 , V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 , V_259 ) ;
F_80 ( V_61 < 0 ) ;
F_8 () ;
F_4 ( & V_245 , V_172 , V_4 ) ;
return 0 ;
V_256:
F_8 () ;
F_48 ( V_172 ) ;
return V_61 ;
}
static int F_214 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_9 * V_172 ;
struct V_19 * V_19 ;
int V_61 ;
V_172 = F_209 () ;
if ( ! V_172 )
return - V_96 ;
F_6 () ;
V_19 = F_212 ( F_94 ( V_10 -> V_114 ) , V_4 -> V_113 , V_115 ) ;
V_61 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_256;
if ( V_115 [ V_247 ] &&
F_185 ( V_115 [ V_247 ] ) != V_19 -> V_248 -> type ) {
V_61 = - V_70 ;
goto V_256;
}
if ( V_115 [ V_257 ] ) {
V_61 = F_215 ( V_19 , V_115 [ V_257 ] ) ;
if ( V_61 )
goto V_256;
}
if ( V_115 [ V_254 ] ) {
struct V_88 * V_260 = V_115 [ V_254 ] ;
V_61 = F_216 ( V_19 , V_260 ) ;
if ( V_61 )
goto V_256;
}
V_61 = F_205 ( V_19 , V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 , V_259 ) ;
F_80 ( V_61 < 0 ) ;
F_8 () ;
F_4 ( & V_245 , V_172 , V_4 ) ;
return 0 ;
V_256:
F_8 () ;
F_48 ( V_172 ) ;
return V_61 ;
}
static int F_217 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_9 * V_172 ;
struct V_19 * V_19 ;
int V_61 ;
V_172 = F_209 () ;
if ( ! V_172 )
return - V_96 ;
F_6 () ;
V_19 = F_212 ( F_94 ( V_10 -> V_114 ) , V_4 -> V_113 , V_115 ) ;
V_61 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_256;
if ( V_19 -> V_30 == V_21 ) {
V_61 = - V_70 ;
goto V_256;
}
V_61 = F_205 ( V_19 , V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 , V_261 ) ;
F_80 ( V_61 < 0 ) ;
F_37 ( V_19 ) ;
F_8 () ;
F_4 ( & V_245 , V_172 , V_4 ) ;
return 0 ;
V_256:
F_8 () ;
F_48 ( V_172 ) ;
return V_61 ;
}
static int F_218 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_88 * * V_115 = V_4 -> V_116 ;
struct V_78 * V_78 = V_4 -> V_113 ;
struct V_9 * V_172 ;
struct V_19 * V_19 ;
int V_61 ;
V_172 = F_209 () ;
if ( ! V_172 )
return - V_96 ;
F_18 () ;
V_19 = F_212 ( F_94 ( V_10 -> V_114 ) , V_78 , V_115 ) ;
V_61 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_256;
V_61 = F_205 ( V_19 , V_172 , V_4 -> V_92 ,
V_4 -> V_168 , 0 , V_259 ) ;
F_80 ( V_61 < 0 ) ;
F_19 () ;
return F_164 ( V_172 , V_4 ) ;
V_256:
F_19 () ;
F_48 ( V_172 ) ;
return V_61 ;
}
static int F_219 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_78 * V_78 = F_170 ( F_171 ( V_197 -> V_199 ) ) ;
struct V_14 * V_20 ;
int V_204 = V_197 -> args [ 0 ] , V_242 = V_197 -> args [ 1 ] ;
int V_138 , V_262 = 0 ;
F_18 () ;
V_20 = F_12 ( F_94 ( V_10 -> V_114 ) , V_78 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_94 ;
}
for ( V_138 = V_204 ; V_138 < V_31 ; V_138 ++ ) {
struct V_19 * V_19 ;
V_262 = 0 ;
F_32 (vport, &dp->ports[i], dp_hash_node) {
if ( V_262 >= V_242 &&
F_205 ( V_19 , V_10 ,
F_174 ( V_197 -> V_10 ) . V_52 ,
V_197 -> V_199 -> V_206 ,
V_207 ,
V_259 ) < 0 )
goto V_55;
V_262 ++ ;
}
V_242 = 0 ;
}
V_55:
F_19 () ;
V_197 -> args [ 0 ] = V_138 ;
V_197 -> args [ 1 ] = V_262 ;
return V_10 -> V_86 ;
}
static void F_220 ( int V_263 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_263 ; V_138 ++ )
F_221 ( V_264 [ V_138 ] ) ;
}
static int F_222 ( void )
{
int V_61 ;
int V_138 ;
for ( V_138 = 0 ; V_138 < F_223 ( V_264 ) ; V_138 ++ ) {
V_61 = F_224 ( V_264 [ V_138 ] ) ;
if ( V_61 )
goto error;
}
return 0 ;
error:
F_220 ( V_138 ) ;
return V_61 ;
}
static int T_7 F_225 ( struct V_15 * V_15 )
{
struct V_219 * V_219 = F_193 ( V_15 , V_235 ) ;
F_226 ( & V_219 -> V_237 ) ;
F_227 ( & V_219 -> V_265 , V_266 ) ;
F_228 ( V_15 ) ;
return 0 ;
}
static void T_8 F_229 ( struct V_15 * V_15 , struct V_15 * V_267 ,
struct V_268 * V_32 )
{
struct V_219 * V_219 = F_193 ( V_15 , V_235 ) ;
struct V_14 * V_20 ;
F_204 (dp, &ovs_net->dps, list_node) {
int V_138 ;
for ( V_138 = 0 ; V_138 < V_31 ; V_138 ++ ) {
struct V_19 * V_19 ;
F_230 (vport, &dp->ports[i], dp_hash_node) {
if ( V_19 -> V_248 -> type != V_226 )
continue;
if ( F_231 ( V_19 -> V_18 ) == V_267 )
F_232 ( & V_19 -> V_269 , V_32 ) ;
}
}
}
}
static void T_8 F_233 ( struct V_15 * V_267 )
{
struct V_14 * V_20 , * V_270 ;
struct V_219 * V_219 = F_193 ( V_267 , V_235 ) ;
struct V_19 * V_19 , * V_271 ;
struct V_15 * V_15 ;
F_234 ( V_32 ) ;
F_235 ( V_267 ) ;
F_6 () ;
F_236 (dp, dp_next, &ovs_net->dps, list_node)
F_195 ( V_20 ) ;
F_237 () ;
F_238 (net)
F_229 ( V_15 , V_267 , & V_32 ) ;
F_239 () ;
F_236 (vport, vport_next, &head, detach_list) {
F_240 ( & V_19 -> V_269 ) ;
F_37 ( V_19 ) ;
}
F_8 () ;
F_241 ( & V_219 -> V_265 ) ;
}
static int T_9 F_242 ( void )
{
int V_61 ;
F_59 ( sizeof( struct V_272 ) > F_243 ( struct V_9 , V_197 ) ) ;
F_244 ( L_8 ) ;
V_61 = F_245 () ;
if ( V_61 )
goto error;
V_61 = F_246 () ;
if ( V_61 )
goto V_273;
V_61 = F_247 () ;
if ( V_61 )
goto V_274;
V_61 = F_248 () ;
if ( V_61 )
goto V_275;
V_61 = F_249 ( & V_276 ) ;
if ( V_61 )
goto V_277;
V_61 = F_250 ( & V_278 ) ;
if ( V_61 )
goto V_279;
V_61 = F_251 () ;
if ( V_61 )
goto V_280;
V_61 = F_222 () ;
if ( V_61 < 0 )
goto V_281;
return 0 ;
V_281:
F_252 () ;
V_280:
F_253 ( & V_278 ) ;
V_279:
F_254 ( & V_276 ) ;
V_277:
F_255 () ;
V_275:
F_256 () ;
V_274:
F_257 () ;
V_273:
F_258 () ;
error:
return V_61 ;
}
static void F_259 ( void )
{
F_220 ( F_223 ( V_264 ) ) ;
F_252 () ;
F_253 ( & V_278 ) ;
F_254 ( & V_276 ) ;
F_260 () ;
F_255 () ;
F_256 () ;
F_257 () ;
F_258 () ;
}
