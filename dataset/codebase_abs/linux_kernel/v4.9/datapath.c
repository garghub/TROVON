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
struct V_118 * V_119 ;
struct V_19 * V_39 ;
T_1 V_53 = 0 ;
int V_87 ;
int V_62 ;
bool log = ! V_114 [ V_120 ] ;
V_62 = - V_71 ;
if ( ! V_114 [ V_108 ] || ! V_114 [ V_100 ] ||
! V_114 [ V_103 ] )
goto V_62;
V_87 = V_81 ( V_114 [ V_108 ] ) ;
V_117 = F_96 ( V_121 + V_87 , V_11 ) ;
V_62 = - V_94 ;
if ( ! V_117 )
goto V_62;
F_97 ( V_117 , V_121 ) ;
F_98 ( F_99 ( V_117 , V_87 ) , V_114 [ V_108 ] , V_87 ) ;
F_100 ( V_117 ) ;
V_119 = F_101 ( V_117 ) ;
if ( F_102 ( V_119 -> V_122 ) )
V_117 -> V_123 = V_119 -> V_122 ;
else
V_117 -> V_123 = F_103 ( V_124 ) ;
if ( V_114 [ V_105 ] ) {
V_53 = F_104 ( V_114 [ V_105 ] ) ;
V_117 -> V_125 = 1 ;
}
F_42 ( V_117 ) -> V_53 = V_53 ;
V_41 = F_105 () ;
V_62 = F_61 ( V_41 ) ;
if ( F_35 ( V_41 ) )
goto V_126;
V_62 = F_106 ( V_15 , V_114 [ V_100 ] ,
V_117 , & V_41 -> V_38 , log ) ;
if ( V_62 )
goto V_127;
V_62 = F_107 ( V_15 , V_114 [ V_103 ] ,
& V_41 -> V_38 , & V_116 , log ) ;
if ( V_62 )
goto V_127;
F_108 ( V_41 -> V_43 , V_116 ) ;
V_117 -> V_128 = V_41 -> V_38 . V_129 . V_128 ;
V_117 -> V_130 = V_41 -> V_38 . V_129 . V_131 ;
F_18 () ;
V_20 = F_12 ( V_15 , V_79 -> V_16 ) ;
V_62 = - V_92 ;
if ( ! V_20 )
goto V_132;
V_39 = F_24 ( V_20 , V_41 -> V_38 . V_129 . V_133 ) ;
if ( ! V_39 )
V_39 = F_24 ( V_20 , V_21 ) ;
if ( ! V_39 )
goto V_132;
V_117 -> V_18 = V_39 -> V_18 ;
F_42 ( V_117 ) -> V_39 = V_39 ;
V_43 = F_51 ( V_41 -> V_43 ) ;
F_109 () ;
V_62 = F_52 ( V_20 , V_117 , V_43 , & V_41 -> V_38 ) ;
F_110 () ;
F_19 () ;
F_111 ( V_41 , false ) ;
return V_62 ;
V_132:
F_19 () ;
V_127:
F_111 ( V_41 , false ) ;
V_126:
F_48 ( V_117 ) ;
V_62:
return V_62 ;
}
static void F_112 ( const struct V_14 * V_20 , struct V_134 * V_45 ,
struct V_135 * V_136 )
{
int V_137 ;
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
V_45 -> V_138 = F_113 ( & V_20 -> V_26 ) ;
V_136 -> V_139 = F_114 ( & V_20 -> V_26 ) ;
V_45 -> V_58 = V_45 -> V_54 = V_45 -> V_64 = 0 ;
F_115 (i) {
const struct V_44 * V_140 ;
struct V_44 V_141 ;
unsigned int V_142 ;
V_140 = F_116 ( V_20 -> V_27 , V_137 ) ;
do {
V_142 = F_117 ( & V_140 -> V_59 ) ;
V_141 = * V_140 ;
} while ( F_118 ( & V_140 -> V_59 , V_142 ) );
V_45 -> V_58 += V_141 . V_58 ;
V_45 -> V_54 += V_141 . V_54 ;
V_45 -> V_64 += V_141 . V_64 ;
V_136 -> V_47 += V_141 . V_47 ;
}
}
static bool F_119 ( const struct V_143 * V_144 , T_4 V_145 )
{
return F_120 ( V_144 ) &&
! ( V_145 & V_146 ) ;
}
static bool F_121 ( T_4 V_145 )
{
return ! ( V_145 & V_147 ) ;
}
static bool F_122 ( T_4 V_145 )
{
return ! ( V_145 & V_148 ) ;
}
static T_5 F_123 ( const struct V_42 * V_116 ,
const struct V_143 * V_144 ,
T_4 V_145 )
{
T_5 V_87 = F_63 ( sizeof( struct V_79 ) ) ;
if ( V_144 && F_120 ( V_144 ) )
V_87 += F_64 ( V_144 -> V_149 ) ;
if ( ! V_144 || F_119 ( V_144 , V_145 ) )
V_87 += F_64 ( F_65 () ) ;
if ( F_121 ( V_145 ) )
V_87 += F_64 ( F_65 () ) ;
if ( F_122 ( V_145 ) )
V_87 += F_64 ( V_116 -> V_150 ) ;
return V_87
+ F_124 ( sizeof( struct V_151 ) )
+ F_64 ( 1 )
+ F_124 ( 8 ) ;
}
static int F_125 ( const struct V_40 * V_41 ,
struct V_9 * V_10 )
{
struct V_151 V_45 ;
T_6 V_152 ;
unsigned long V_153 ;
F_126 ( V_41 , & V_45 , & V_153 , & V_152 ) ;
if ( V_153 &&
F_127 ( V_10 , V_154 , F_128 ( V_153 ) ,
V_155 ) )
return - V_156 ;
if ( V_45 . V_157 &&
F_129 ( V_10 , V_158 ,
sizeof( struct V_151 ) , & V_45 ,
V_155 ) )
return - V_156 ;
if ( ( V_159 ) F_130 ( V_152 ) &&
F_131 ( V_10 , V_160 , ( V_159 ) F_130 ( V_152 ) ) )
return - V_156 ;
return 0 ;
}
static int F_132 ( const struct V_40 * V_41 ,
struct V_9 * V_10 , int V_161 )
{
struct V_89 * V_142 ;
int V_62 ;
V_142 = F_82 ( V_10 , V_162 ) ;
if ( V_142 ) {
const struct V_42 * V_43 ;
V_43 = F_133 ( V_41 -> V_43 ) ;
V_62 = F_85 ( V_43 -> V_104 ,
V_43 -> V_83 , V_10 ) ;
if ( ! V_62 )
F_84 ( V_10 , V_142 ) ;
else {
if ( V_161 )
return V_62 ;
F_86 ( V_10 , V_142 ) ;
}
} else if ( V_161 ) {
return - V_156 ;
}
return 0 ;
}
static int F_134 ( const struct V_40 * V_41 , int V_16 ,
struct V_9 * V_10 , T_3 V_52 ,
T_3 V_163 , T_3 V_57 , V_159 V_50 , T_3 V_145 )
{
const int V_161 = V_10 -> V_87 ;
struct V_79 * V_79 ;
int V_62 ;
V_79 = F_77 ( V_10 , V_52 , V_163 , & V_164 ,
V_57 , V_50 ) ;
if ( ! V_79 )
return - V_156 ;
V_79 -> V_16 = V_16 ;
V_62 = F_135 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_119 ( & V_41 -> V_165 , V_145 ) ) {
V_62 = F_136 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
}
if ( F_121 ( V_145 ) ) {
V_62 = F_137 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
}
V_62 = F_125 ( V_41 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_122 ( V_145 ) ) {
V_62 = F_132 ( V_41 , V_10 , V_161 ) ;
if ( V_62 )
goto error;
}
F_138 ( V_10 , V_79 ) ;
return 0 ;
error:
F_139 ( V_10 , V_79 ) ;
return V_62 ;
}
static struct V_9 * F_140 ( const struct V_42 * V_116 ,
const struct V_143 * V_144 ,
struct V_3 * V_4 ,
bool V_166 ,
T_4 V_145 )
{
struct V_9 * V_10 ;
T_5 V_87 ;
if ( ! V_166 && ! F_1 ( & V_164 , V_4 , 0 ) )
return NULL ;
V_87 = F_123 ( V_116 , V_144 , V_145 ) ;
V_10 = F_76 ( V_87 , V_11 ) ;
if ( ! V_10 )
return F_141 ( - V_94 ) ;
return V_10 ;
}
static struct V_9 * F_142 ( const struct V_40 * V_41 ,
int V_16 ,
struct V_3 * V_4 , V_159 V_50 ,
bool V_166 , T_3 V_145 )
{
struct V_9 * V_10 ;
int V_167 ;
V_10 = F_140 ( F_143 ( V_41 -> V_43 ) ,
& V_41 -> V_165 , V_4 , V_166 , V_145 ) ;
if ( F_144 ( V_10 ) )
return V_10 ;
V_167 = F_134 ( V_41 , V_16 , V_10 ,
V_4 -> V_168 , V_4 -> V_169 , 0 ,
V_50 , V_145 ) ;
F_79 ( V_167 < 0 ) ;
return V_10 ;
}
static int F_145 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_95 ( V_10 -> V_113 ) ;
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_40 * V_41 = NULL , * V_170 ;
struct V_171 V_172 ;
struct V_9 * V_173 ;
struct V_14 * V_20 ;
struct V_42 * V_116 ;
struct V_174 V_175 ;
T_3 V_145 = F_146 ( V_114 [ V_176 ] ) ;
int error ;
bool log = ! V_114 [ V_177 ] ;
error = - V_71 ;
if ( ! V_114 [ V_178 ] ) {
F_147 ( log , L_1 ) ;
goto error;
}
if ( ! V_114 [ V_162 ] ) {
F_147 ( log , L_2 ) ;
goto error;
}
V_170 = F_105 () ;
if ( F_35 ( V_170 ) ) {
error = F_61 ( V_170 ) ;
goto error;
}
F_148 ( & V_175 , & V_170 -> V_38 , false , & V_172 ) ;
error = F_149 ( V_15 , & V_175 , V_114 [ V_178 ] ,
V_114 [ V_179 ] , log ) ;
if ( error )
goto V_180;
error = F_150 ( & V_170 -> V_165 , V_114 [ V_181 ] ,
& V_170 -> V_38 , log ) ;
if ( error )
goto V_180;
if ( F_151 ( & V_170 -> V_165 ) )
V_175 . V_38 = V_170 -> V_165 . V_182 ;
F_152 ( & V_170 -> V_38 , & V_170 -> V_38 , true , & V_172 ) ;
error = F_107 ( V_15 , V_114 [ V_162 ] ,
& V_170 -> V_38 , & V_116 , log ) ;
if ( error ) {
F_147 ( log , L_3 ) ;
goto V_180;
}
V_173 = F_140 ( V_116 , & V_170 -> V_165 , V_4 , false ,
V_145 ) ;
if ( F_35 ( V_173 ) ) {
error = F_61 ( V_173 ) ;
goto V_183;
}
F_6 () ;
V_20 = F_15 ( V_15 , V_79 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_92 ;
goto V_184;
}
if ( F_120 ( & V_170 -> V_165 ) )
V_41 = F_153 ( & V_20 -> V_26 , & V_170 -> V_165 ) ;
if ( ! V_41 )
V_41 = F_154 ( & V_20 -> V_26 , & V_170 -> V_38 ) ;
if ( F_155 ( ! V_41 ) ) {
F_108 ( V_170 -> V_43 , V_116 ) ;
error = F_156 ( & V_20 -> V_26 , V_170 , & V_172 ) ;
if ( F_45 ( error ) ) {
V_116 = NULL ;
goto V_184;
}
if ( F_45 ( V_173 ) ) {
error = F_134 ( V_170 ,
V_79 -> V_16 ,
V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 ,
V_185 ,
V_145 ) ;
F_79 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_42 * V_186 ;
if ( F_45 ( V_4 -> V_6 -> V_7 & ( V_187
| V_188 ) ) ) {
error = - V_189 ;
goto V_184;
}
if ( F_45 ( ! F_157 ( V_41 , & V_175 ) ) ) {
if ( F_151 ( & V_41 -> V_165 ) )
V_41 = F_158 ( & V_20 -> V_26 ,
& V_175 ) ;
else
V_41 = NULL ;
if ( ! V_41 ) {
error = - V_190 ;
goto V_184;
}
}
V_186 = F_143 ( V_41 -> V_43 ) ;
F_108 ( V_41 -> V_43 , V_116 ) ;
if ( F_45 ( V_173 ) ) {
error = F_134 ( V_41 ,
V_79 -> V_16 ,
V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 ,
V_185 ,
V_145 ) ;
F_79 ( error < 0 ) ;
}
F_8 () ;
F_159 ( V_186 ) ;
F_111 ( V_170 , false ) ;
}
if ( V_173 )
F_4 ( & V_164 , V_173 , V_4 ) ;
return 0 ;
V_184:
F_8 () ;
F_48 ( V_173 ) ;
V_183:
F_160 ( V_116 ) ;
V_180:
F_111 ( V_170 , false ) ;
error:
return error ;
}
static struct V_42 * F_161 ( struct V_15 * V_15 ,
const struct V_89 * V_114 ,
const struct V_37 * V_38 ,
const struct V_171 * V_172 ,
bool log )
{
struct V_42 * V_116 ;
struct V_37 V_191 ;
int error ;
F_152 ( & V_191 , V_38 , true , V_172 ) ;
error = F_107 ( V_15 , V_114 , & V_191 , & V_116 , log ) ;
if ( error ) {
F_147 ( log ,
L_4 ) ;
return F_141 ( error ) ;
}
return V_116 ;
}
static int F_162 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_15 = F_95 ( V_10 -> V_113 ) ;
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_37 V_38 ;
struct V_40 * V_41 ;
struct V_171 V_172 ;
struct V_9 * V_173 = NULL ;
struct V_14 * V_20 ;
struct V_42 * V_186 = NULL , * V_116 = NULL ;
struct V_174 V_175 ;
struct V_143 V_144 ;
T_3 V_145 = F_146 ( V_114 [ V_176 ] ) ;
int error = 0 ;
bool log = ! V_114 [ V_177 ] ;
bool V_192 ;
V_192 = F_163 ( & V_144 , V_114 [ V_181 ] , log ) ;
if ( V_114 [ V_178 ] ) {
F_148 ( & V_175 , & V_38 , true , & V_172 ) ;
error = F_149 ( V_15 , & V_175 , V_114 [ V_178 ] ,
V_114 [ V_179 ] , log ) ;
} else if ( ! V_192 ) {
F_147 ( log ,
L_5 ) ;
error = - V_71 ;
}
if ( error )
goto error;
if ( V_114 [ V_162 ] ) {
if ( ! V_114 [ V_178 ] ) {
F_147 ( log ,
L_6 ) ;
error = - V_71 ;
goto error;
}
V_116 = F_161 ( V_15 , V_114 [ V_162 ] , & V_38 ,
& V_172 , log ) ;
if ( F_35 ( V_116 ) ) {
error = F_61 ( V_116 ) ;
goto error;
}
V_173 = F_140 ( V_116 , & V_144 , V_4 , false ,
V_145 ) ;
if ( F_35 ( V_173 ) ) {
error = F_61 ( V_173 ) ;
goto V_183;
}
}
F_6 () ;
V_20 = F_15 ( V_15 , V_79 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
error = - V_92 ;
goto V_184;
}
if ( V_192 )
V_41 = F_153 ( & V_20 -> V_26 , & V_144 ) ;
else
V_41 = F_158 ( & V_20 -> V_26 , & V_175 ) ;
if ( F_45 ( ! V_41 ) ) {
error = - V_190 ;
goto V_184;
}
if ( F_155 ( V_116 ) ) {
V_186 = F_143 ( V_41 -> V_43 ) ;
F_108 ( V_41 -> V_43 , V_116 ) ;
if ( F_45 ( V_173 ) ) {
error = F_134 ( V_41 ,
V_79 -> V_16 ,
V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 ,
V_185 ,
V_145 ) ;
F_79 ( error < 0 ) ;
}
} else {
V_173 = F_142 ( V_41 , V_79 -> V_16 ,
V_4 , V_185 , false ,
V_145 ) ;
if ( F_35 ( V_173 ) ) {
error = F_61 ( V_173 ) ;
goto V_184;
}
}
if ( V_114 [ V_193 ] )
F_164 ( V_41 ) ;
F_8 () ;
if ( V_173 )
F_4 ( & V_164 , V_173 , V_4 ) ;
if ( V_186 )
F_159 ( V_186 ) ;
return 0 ;
V_184:
F_8 () ;
F_48 ( V_173 ) ;
V_183:
F_160 ( V_116 ) ;
error:
return error ;
}
static int F_165 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_15 * V_15 = F_95 ( V_10 -> V_113 ) ;
struct V_37 V_38 ;
struct V_9 * V_173 ;
struct V_40 * V_41 ;
struct V_14 * V_20 ;
struct V_174 V_175 ;
struct V_143 V_194 ;
T_3 V_145 = F_146 ( V_114 [ V_176 ] ) ;
int V_62 = 0 ;
bool log = ! V_114 [ V_177 ] ;
bool V_192 ;
V_192 = F_163 ( & V_194 , V_114 [ V_181 ] , log ) ;
if ( V_114 [ V_178 ] ) {
F_148 ( & V_175 , & V_38 , true , NULL ) ;
V_62 = F_149 ( V_15 , & V_175 , V_114 [ V_178 ] , NULL ,
log ) ;
} else if ( ! V_192 ) {
F_147 ( log ,
L_7 ) ;
V_62 = - V_71 ;
}
if ( V_62 )
return V_62 ;
F_6 () ;
V_20 = F_15 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
if ( ! V_20 ) {
V_62 = - V_92 ;
goto V_195;
}
if ( V_192 )
V_41 = F_153 ( & V_20 -> V_26 , & V_194 ) ;
else
V_41 = F_158 ( & V_20 -> V_26 , & V_175 ) ;
if ( ! V_41 ) {
V_62 = - V_190 ;
goto V_195;
}
V_173 = F_142 ( V_41 , V_79 -> V_16 , V_4 ,
V_185 , true , V_145 ) ;
if ( F_35 ( V_173 ) ) {
V_62 = F_61 ( V_173 ) ;
goto V_195;
}
F_8 () ;
return F_166 ( V_173 , V_4 ) ;
V_195:
F_8 () ;
return V_62 ;
}
static int F_167 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_15 * V_15 = F_95 ( V_10 -> V_113 ) ;
struct V_37 V_38 ;
struct V_9 * V_173 ;
struct V_40 * V_41 = NULL ;
struct V_14 * V_20 ;
struct V_174 V_175 ;
struct V_143 V_194 ;
T_3 V_145 = F_146 ( V_114 [ V_176 ] ) ;
int V_62 ;
bool log = ! V_114 [ V_177 ] ;
bool V_192 ;
V_192 = F_163 ( & V_194 , V_114 [ V_181 ] , log ) ;
if ( V_114 [ V_178 ] ) {
F_148 ( & V_175 , & V_38 , true , NULL ) ;
V_62 = F_149 ( V_15 , & V_175 , V_114 [ V_178 ] ,
NULL , log ) ;
if ( F_45 ( V_62 ) )
return V_62 ;
}
F_6 () ;
V_20 = F_15 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
if ( F_45 ( ! V_20 ) ) {
V_62 = - V_92 ;
goto V_195;
}
if ( F_45 ( ! V_114 [ V_178 ] && ! V_192 ) ) {
V_62 = F_168 ( & V_20 -> V_26 ) ;
goto V_195;
}
if ( V_192 )
V_41 = F_153 ( & V_20 -> V_26 , & V_194 ) ;
else
V_41 = F_158 ( & V_20 -> V_26 , & V_175 ) ;
if ( F_45 ( ! V_41 ) ) {
V_62 = - V_190 ;
goto V_195;
}
F_169 ( & V_20 -> V_26 , V_41 ) ;
F_8 () ;
V_173 = F_140 ( ( const struct V_42 V_196 * ) V_41 -> V_43 ,
& V_41 -> V_165 , V_4 , false , V_145 ) ;
if ( F_155 ( V_173 ) ) {
if ( F_155 ( ! F_35 ( V_173 ) ) ) {
F_18 () ;
V_62 = F_134 ( V_41 , V_79 -> V_16 ,
V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 ,
V_197 ,
V_145 ) ;
F_19 () ;
F_79 ( V_62 < 0 ) ;
F_4 ( & V_164 , V_173 , V_4 ) ;
} else {
F_170 ( F_95 ( V_10 -> V_113 ) -> V_198 , 0 , 0 , F_61 ( V_173 ) ) ;
}
}
F_111 ( V_41 , true ) ;
return 0 ;
V_195:
F_8 () ;
return V_62 ;
}
static int F_171 ( struct V_9 * V_10 , struct V_199 * V_200 )
{
struct V_89 * V_114 [ V_201 ] ;
struct V_79 * V_79 = F_172 ( F_173 ( V_200 -> V_202 ) ) ;
struct V_203 * V_204 ;
struct V_14 * V_20 ;
T_3 V_145 ;
int V_62 ;
V_62 = F_174 ( V_200 -> V_202 , & V_164 , V_114 ,
V_205 , V_206 ) ;
if ( V_62 )
return V_62 ;
V_145 = F_146 ( V_114 [ V_176 ] ) ;
F_18 () ;
V_20 = F_12 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_92 ;
}
V_204 = F_51 ( V_20 -> V_26 . V_204 ) ;
for (; ; ) {
struct V_40 * V_41 ;
T_3 V_207 , V_208 ;
V_207 = V_200 -> args [ 0 ] ;
V_208 = V_200 -> args [ 1 ] ;
V_41 = F_175 ( V_204 , & V_207 , & V_208 ) ;
if ( ! V_41 )
break;
if ( F_134 ( V_41 , V_79 -> V_16 , V_10 ,
F_176 ( V_200 -> V_10 ) . V_52 ,
V_200 -> V_202 -> V_209 , V_210 ,
V_185 , V_145 ) < 0 )
break;
V_200 -> args [ 0 ] = V_207 ;
V_200 -> args [ 1 ] = V_208 ;
}
F_19 () ;
return V_10 -> V_87 ;
}
static T_5 F_177 ( void )
{
T_5 V_211 = F_63 ( sizeof( struct V_79 ) ) ;
V_211 += F_64 ( V_212 ) ;
V_211 += F_124 ( sizeof( struct V_134 ) ) ;
V_211 += F_124 ( sizeof( struct V_135 ) ) ;
V_211 += F_64 ( sizeof( T_3 ) ) ;
return V_211 ;
}
static int F_178 ( struct V_14 * V_20 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_163 , T_3 V_57 , V_159 V_50 )
{
struct V_79 * V_79 ;
struct V_134 V_213 ;
struct V_135 V_214 ;
int V_62 ;
V_79 = F_77 ( V_10 , V_52 , V_163 , & V_215 ,
V_57 , V_50 ) ;
if ( ! V_79 )
goto error;
V_79 -> V_16 = F_23 ( V_20 ) ;
V_62 = F_179 ( V_10 , V_216 , F_20 ( V_20 ) ) ;
if ( V_62 )
goto V_217;
F_112 ( V_20 , & V_213 , & V_214 ) ;
if ( F_129 ( V_10 , V_218 , sizeof( struct V_134 ) ,
& V_213 , V_219 ) )
goto V_217;
if ( F_129 ( V_10 , V_220 ,
sizeof( struct V_135 ) ,
& V_214 , V_219 ) )
goto V_217;
if ( F_88 ( V_10 , V_221 , V_20 -> V_84 ) )
goto V_217;
F_138 ( V_10 , V_79 ) ;
return 0 ;
V_217:
F_139 ( V_10 , V_79 ) ;
error:
return - V_156 ;
}
static struct V_9 * F_180 ( void )
{
return F_76 ( F_177 () , V_11 ) ;
}
static struct V_14 * F_181 ( struct V_15 * V_15 ,
const struct V_79 * V_79 ,
struct V_89 * V_114 [ V_222 + 1 ] )
{
struct V_14 * V_20 ;
if ( ! V_114 [ V_216 ] )
V_20 = F_15 ( V_15 , V_79 -> V_16 ) ;
else {
struct V_19 * V_19 ;
V_19 = F_182 ( V_15 , F_81 ( V_114 [ V_216 ] ) ) ;
V_20 = V_19 && V_19 -> V_30 == V_21 ? V_19 -> V_20 : NULL ;
}
return V_20 ? V_20 : F_141 ( - V_92 ) ;
}
static void F_183 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_14 * V_20 ;
V_20 = F_181 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_4 -> V_115 ) ;
if ( F_35 ( V_20 ) )
return;
F_184 ( V_20 -> V_84 , L_8 ) ;
V_20 -> V_84 = 0 ;
}
static void F_185 ( struct V_14 * V_20 , struct V_89 * V_114 [] )
{
if ( V_114 [ V_221 ] )
V_20 -> V_84 = F_186 ( V_114 [ V_221 ] ) ;
}
static int F_187 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_33 V_34 ;
struct V_9 * V_173 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
struct V_223 * V_223 ;
int V_62 , V_137 ;
V_62 = - V_71 ;
if ( ! V_114 [ V_216 ] || ! V_114 [ V_224 ] )
goto V_62;
V_173 = F_180 () ;
if ( ! V_173 )
return - V_94 ;
V_62 = - V_94 ;
V_20 = F_188 ( sizeof( * V_20 ) , V_11 ) ;
if ( V_20 == NULL )
goto V_225;
F_189 ( V_20 , F_95 ( V_10 -> V_113 ) ) ;
V_62 = F_190 ( & V_20 -> V_26 ) ;
if ( V_62 )
goto V_226;
V_20 -> V_27 = F_191 ( struct V_44 ) ;
if ( ! V_20 -> V_27 ) {
V_62 = - V_94 ;
goto V_227;
}
V_20 -> V_28 = F_192 ( V_31 * sizeof( struct V_29 ) ,
V_11 ) ;
if ( ! V_20 -> V_28 ) {
V_62 = - V_94 ;
goto V_228;
}
for ( V_137 = 0 ; V_137 < V_31 ; V_137 ++ )
F_193 ( & V_20 -> V_28 [ V_137 ] ) ;
V_34 . V_229 = F_81 ( V_114 [ V_216 ] ) ;
V_34 . type = V_230 ;
V_34 . V_231 = NULL ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_21 ;
V_34 . V_232 = V_114 [ V_224 ] ;
F_185 ( V_20 , V_114 ) ;
F_6 () ;
V_19 = F_33 ( & V_34 ) ;
if ( F_35 ( V_19 ) ) {
V_62 = F_61 ( V_19 ) ;
if ( V_62 == - V_233 )
V_62 = - V_189 ;
if ( V_62 == - V_189 ) {
if ( V_4 -> V_234 -> V_235 < V_236 )
F_183 ( V_10 , V_4 ) ;
}
goto V_237;
}
V_62 = F_178 ( V_20 , V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 , V_238 ) ;
F_79 ( V_62 < 0 ) ;
V_223 = F_194 ( F_92 ( V_20 ) , V_239 ) ;
F_195 ( & V_20 -> V_240 , & V_223 -> V_241 ) ;
F_8 () ;
F_4 ( & V_215 , V_173 , V_4 ) ;
return 0 ;
V_237:
F_8 () ;
F_29 ( V_20 -> V_28 ) ;
V_228:
F_28 ( V_20 -> V_27 ) ;
V_227:
F_27 ( & V_20 -> V_26 ) ;
V_226:
F_29 ( V_20 ) ;
V_225:
F_48 ( V_173 ) ;
V_62:
return V_62 ;
}
static void F_196 ( struct V_14 * V_20 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_31 ; V_137 ++ ) {
struct V_19 * V_19 ;
struct V_242 * V_243 ;
F_197 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_19 -> V_30 != V_21 )
F_37 ( V_19 ) ;
}
F_198 ( & V_20 -> V_240 ) ;
F_37 ( F_199 ( V_20 , V_21 ) ) ;
F_200 ( & V_20 -> V_25 , F_25 ) ;
}
static int F_201 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_173 ;
struct V_14 * V_20 ;
int V_62 ;
V_173 = F_180 () ;
if ( ! V_173 )
return - V_94 ;
F_6 () ;
V_20 = F_181 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_4 -> V_115 ) ;
V_62 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_244;
V_62 = F_178 ( V_20 , V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 , V_245 ) ;
F_79 ( V_62 < 0 ) ;
F_196 ( V_20 ) ;
F_8 () ;
F_4 ( & V_215 , V_173 , V_4 ) ;
return 0 ;
V_244:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_202 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_173 ;
struct V_14 * V_20 ;
int V_62 ;
V_173 = F_180 () ;
if ( ! V_173 )
return - V_94 ;
F_6 () ;
V_20 = F_181 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_4 -> V_115 ) ;
V_62 = F_61 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_244;
F_185 ( V_20 , V_4 -> V_115 ) ;
V_62 = F_178 ( V_20 , V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 , V_238 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_215 , V_173 , V_4 ) ;
return 0 ;
V_244:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_203 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_173 ;
struct V_14 * V_20 ;
int V_62 ;
V_173 = F_180 () ;
if ( ! V_173 )
return - V_94 ;
F_6 () ;
V_20 = F_181 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_4 -> V_115 ) ;
if ( F_35 ( V_20 ) ) {
V_62 = F_61 ( V_20 ) ;
goto V_244;
}
V_62 = F_178 ( V_20 , V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 , V_238 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
return F_166 ( V_173 , V_4 ) ;
V_244:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_204 ( struct V_9 * V_10 , struct V_199 * V_200 )
{
struct V_223 * V_223 = F_194 ( F_95 ( V_10 -> V_113 ) , V_239 ) ;
struct V_14 * V_20 ;
int V_246 = V_200 -> args [ 0 ] ;
int V_137 = 0 ;
F_6 () ;
F_205 (dp, &ovs_net->dps, list_node) {
if ( V_137 >= V_246 &&
F_178 ( V_20 , V_10 , F_176 ( V_200 -> V_10 ) . V_52 ,
V_200 -> V_202 -> V_209 , V_210 ,
V_238 ) < 0 )
break;
V_137 ++ ;
}
F_8 () ;
V_200 -> args [ 0 ] = V_137 ;
return V_10 -> V_87 ;
}
static int F_206 ( struct V_19 * V_19 , struct V_9 * V_10 ,
T_3 V_52 , T_3 V_163 , T_3 V_57 , V_159 V_50 )
{
struct V_79 * V_79 ;
struct V_247 V_248 ;
int V_62 ;
V_79 = F_77 ( V_10 , V_52 , V_163 , & V_249 ,
V_57 , V_50 ) ;
if ( ! V_79 )
return - V_156 ;
V_79 -> V_16 = F_23 ( V_19 -> V_20 ) ;
if ( F_88 ( V_10 , V_250 , V_19 -> V_30 ) ||
F_88 ( V_10 , V_251 , V_19 -> V_252 -> type ) ||
F_179 ( V_10 , V_253 ,
F_22 ( V_19 ) ) )
goto V_217;
F_207 ( V_19 , & V_248 ) ;
if ( F_129 ( V_10 , V_254 ,
sizeof( struct V_247 ) , & V_248 ,
V_255 ) )
goto V_217;
if ( F_208 ( V_19 , V_10 ) )
goto V_217;
V_62 = F_209 ( V_19 , V_10 ) ;
if ( V_62 == - V_156 )
goto error;
F_138 ( V_10 , V_79 ) ;
return 0 ;
V_217:
V_62 = - V_156 ;
error:
F_139 ( V_10 , V_79 ) ;
return V_62 ;
}
static struct V_9 * F_210 ( void )
{
return F_211 ( V_256 , V_11 ) ;
}
struct V_9 * F_212 ( struct V_19 * V_19 , T_3 V_52 ,
T_3 V_163 , V_159 V_50 )
{
struct V_9 * V_10 ;
int V_167 ;
V_10 = F_211 ( V_256 , V_93 ) ;
if ( ! V_10 )
return F_141 ( - V_94 ) ;
V_167 = F_206 ( V_19 , V_10 , V_52 , V_163 , 0 , V_50 ) ;
F_79 ( V_167 < 0 ) ;
return V_10 ;
}
static struct V_19 * F_213 ( struct V_15 * V_15 ,
const struct V_79 * V_79 ,
struct V_89 * V_114 [ V_257 + 1 ] )
{
struct V_14 * V_20 ;
struct V_19 * V_19 ;
if ( V_114 [ V_253 ] ) {
V_19 = F_182 ( V_15 , F_81 ( V_114 [ V_253 ] ) ) ;
if ( ! V_19 )
return F_141 ( - V_92 ) ;
if ( V_79 -> V_16 &&
V_79 -> V_16 != F_23 ( V_19 -> V_20 ) )
return F_141 ( - V_92 ) ;
return V_19 ;
} else if ( V_114 [ V_250 ] ) {
T_3 V_30 = F_186 ( V_114 [ V_250 ] ) ;
if ( V_30 >= V_258 )
return F_141 ( - V_96 ) ;
V_20 = F_15 ( V_15 , V_79 -> V_16 ) ;
if ( ! V_20 )
return F_141 ( - V_92 ) ;
V_19 = F_21 ( V_20 , V_30 ) ;
if ( ! V_19 )
return F_141 ( - V_92 ) ;
return V_19 ;
} else
return F_141 ( - V_71 ) ;
}
static void F_214 ( struct V_14 * V_20 )
{
unsigned V_259 , V_260 = 0 ;
struct V_17 * V_18 ;
struct V_19 * V_19 ;
int V_137 ;
for ( V_137 = 0 ; V_137 < V_31 ; V_137 ++ ) {
F_32 (vport, &dp->ports[i], dp_hash_node) {
V_18 = V_19 -> V_18 ;
V_259 = F_215 ( V_18 ) ;
if ( V_259 > V_260 )
V_260 = V_259 ;
}
}
V_20 -> V_260 = V_260 ;
for ( V_137 = 0 ; V_137 < V_31 ; V_137 ++ )
F_32 (vport, &dp->ports[i], dp_hash_node)
F_216 ( V_19 -> V_18 , V_260 ) ;
}
static int F_217 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_33 V_34 ;
struct V_9 * V_173 ;
struct V_19 * V_19 ;
struct V_14 * V_20 ;
T_3 V_30 ;
int V_62 ;
if ( ! V_114 [ V_253 ] || ! V_114 [ V_251 ] ||
! V_114 [ V_261 ] )
return - V_71 ;
V_30 = V_114 [ V_250 ]
? F_186 ( V_114 [ V_250 ] ) : 0 ;
if ( V_30 >= V_258 )
return - V_96 ;
V_173 = F_210 () ;
if ( ! V_173 )
return - V_94 ;
F_6 () ;
V_262:
V_20 = F_15 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
V_62 = - V_92 ;
if ( ! V_20 )
goto V_263;
if ( V_30 ) {
V_19 = F_199 ( V_20 , V_30 ) ;
V_62 = - V_233 ;
if ( V_19 )
goto V_263;
} else {
for ( V_30 = 1 ; ; V_30 ++ ) {
if ( V_30 >= V_258 ) {
V_62 = - V_96 ;
goto V_263;
}
V_19 = F_199 ( V_20 , V_30 ) ;
if ( ! V_19 )
break;
}
}
V_34 . V_229 = F_81 ( V_114 [ V_253 ] ) ;
V_34 . type = F_186 ( V_114 [ V_251 ] ) ;
V_34 . V_231 = V_114 [ V_264 ] ;
V_34 . V_20 = V_20 ;
V_34 . V_30 = V_30 ;
V_34 . V_232 = V_114 [ V_261 ] ;
V_19 = F_33 ( & V_34 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) ) {
if ( V_62 == - V_265 )
goto V_262;
goto V_263;
}
V_62 = F_206 ( V_19 , V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 , V_266 ) ;
if ( F_215 ( V_19 -> V_18 ) > V_20 -> V_260 )
F_214 ( V_20 ) ;
else
F_216 ( V_19 -> V_18 , V_20 -> V_260 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_249 , V_173 , V_4 ) ;
return 0 ;
V_263:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_218 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_9 * V_173 ;
struct V_19 * V_19 ;
int V_62 ;
V_173 = F_210 () ;
if ( ! V_173 )
return - V_94 ;
F_6 () ;
V_19 = F_213 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_114 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_263;
if ( V_114 [ V_251 ] &&
F_186 ( V_114 [ V_251 ] ) != V_19 -> V_252 -> type ) {
V_62 = - V_71 ;
goto V_263;
}
if ( V_114 [ V_264 ] ) {
V_62 = F_219 ( V_19 , V_114 [ V_264 ] ) ;
if ( V_62 )
goto V_263;
}
if ( V_114 [ V_261 ] ) {
struct V_89 * V_267 = V_114 [ V_261 ] ;
V_62 = F_220 ( V_19 , V_267 ) ;
if ( V_62 )
goto V_263;
}
V_62 = F_206 ( V_19 , V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 , V_266 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_249 , V_173 , V_4 ) ;
return 0 ;
V_263:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_221 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
bool V_268 = false ;
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_9 * V_173 ;
struct V_14 * V_20 ;
struct V_19 * V_19 ;
int V_62 ;
V_173 = F_210 () ;
if ( ! V_173 )
return - V_94 ;
F_6 () ;
V_19 = F_213 ( F_95 ( V_10 -> V_113 ) , V_4 -> V_112 , V_114 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_263;
if ( V_19 -> V_30 == V_21 ) {
V_62 = - V_71 ;
goto V_263;
}
V_62 = F_206 ( V_19 , V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 , V_269 ) ;
F_79 ( V_62 < 0 ) ;
V_20 = V_19 -> V_20 ;
if ( F_215 ( V_19 -> V_18 ) == V_20 -> V_260 )
V_268 = true ;
F_222 ( V_19 -> V_18 ) ;
F_37 ( V_19 ) ;
if ( V_268 )
F_214 ( V_20 ) ;
F_8 () ;
F_4 ( & V_249 , V_173 , V_4 ) ;
return 0 ;
V_263:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_223 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_89 * * V_114 = V_4 -> V_115 ;
struct V_79 * V_79 = V_4 -> V_112 ;
struct V_9 * V_173 ;
struct V_19 * V_19 ;
int V_62 ;
V_173 = F_210 () ;
if ( ! V_173 )
return - V_94 ;
F_18 () ;
V_19 = F_213 ( F_95 ( V_10 -> V_113 ) , V_79 , V_114 ) ;
V_62 = F_61 ( V_19 ) ;
if ( F_35 ( V_19 ) )
goto V_263;
V_62 = F_206 ( V_19 , V_173 , V_4 -> V_168 ,
V_4 -> V_169 , 0 , V_266 ) ;
F_79 ( V_62 < 0 ) ;
F_19 () ;
return F_166 ( V_173 , V_4 ) ;
V_263:
F_19 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_224 ( struct V_9 * V_10 , struct V_199 * V_200 )
{
struct V_79 * V_79 = F_172 ( F_173 ( V_200 -> V_202 ) ) ;
struct V_14 * V_20 ;
int V_207 = V_200 -> args [ 0 ] , V_246 = V_200 -> args [ 1 ] ;
int V_137 , V_270 = 0 ;
F_18 () ;
V_20 = F_12 ( F_95 ( V_10 -> V_113 ) , V_79 -> V_16 ) ;
if ( ! V_20 ) {
F_19 () ;
return - V_92 ;
}
for ( V_137 = V_207 ; V_137 < V_31 ; V_137 ++ ) {
struct V_19 * V_19 ;
V_270 = 0 ;
F_32 (vport, &dp->ports[i], dp_hash_node) {
if ( V_270 >= V_246 &&
F_206 ( V_19 , V_10 ,
F_176 ( V_200 -> V_10 ) . V_52 ,
V_200 -> V_202 -> V_209 ,
V_210 ,
V_266 ) < 0 )
goto V_55;
V_270 ++ ;
}
V_246 = 0 ;
}
V_55:
F_19 () ;
V_200 -> args [ 0 ] = V_137 ;
V_200 -> args [ 1 ] = V_270 ;
return V_10 -> V_87 ;
}
static void F_225 ( int V_271 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_271 ; V_137 ++ )
F_226 ( V_272 [ V_137 ] ) ;
}
static int F_227 ( void )
{
int V_62 ;
int V_137 ;
for ( V_137 = 0 ; V_137 < F_228 ( V_272 ) ; V_137 ++ ) {
V_62 = F_229 ( V_272 [ V_137 ] ) ;
if ( V_62 )
goto error;
}
return 0 ;
error:
F_225 ( V_137 ) ;
return V_62 ;
}
static int T_7 F_230 ( struct V_15 * V_15 )
{
struct V_223 * V_223 = F_194 ( V_15 , V_239 ) ;
F_231 ( & V_223 -> V_241 ) ;
F_232 ( & V_223 -> V_273 , V_274 ) ;
F_233 ( V_15 ) ;
return 0 ;
}
static void T_8 F_234 ( struct V_15 * V_15 , struct V_15 * V_275 ,
struct V_276 * V_32 )
{
struct V_223 * V_223 = F_194 ( V_15 , V_239 ) ;
struct V_14 * V_20 ;
F_205 (dp, &ovs_net->dps, list_node) {
int V_137 ;
for ( V_137 = 0 ; V_137 < V_31 ; V_137 ++ ) {
struct V_19 * V_19 ;
F_235 (vport, &dp->ports[i], dp_hash_node) {
if ( V_19 -> V_252 -> type != V_230 )
continue;
if ( F_236 ( V_19 -> V_18 ) == V_275 )
F_237 ( & V_19 -> V_277 , V_32 ) ;
}
}
}
}
static void T_8 F_238 ( struct V_15 * V_275 )
{
struct V_14 * V_20 , * V_278 ;
struct V_223 * V_223 = F_194 ( V_275 , V_239 ) ;
struct V_19 * V_19 , * V_279 ;
struct V_15 * V_15 ;
F_239 ( V_32 ) ;
F_240 ( V_275 ) ;
F_6 () ;
F_241 (dp, dp_next, &ovs_net->dps, list_node)
F_196 ( V_20 ) ;
F_242 () ;
F_243 (net)
F_234 ( V_15 , V_275 , & V_32 ) ;
F_244 () ;
F_241 (vport, vport_next, &head, detach_list) {
F_245 ( & V_19 -> V_277 ) ;
F_37 ( V_19 ) ;
}
F_8 () ;
F_246 ( & V_223 -> V_273 ) ;
}
static int T_9 F_247 ( void )
{
int V_62 ;
F_59 ( sizeof( struct V_280 ) > F_248 ( struct V_9 , V_200 ) ) ;
F_249 ( L_9 ) ;
V_62 = F_250 () ;
if ( V_62 )
goto error;
V_62 = F_251 () ;
if ( V_62 )
goto V_281;
V_62 = F_252 () ;
if ( V_62 )
goto V_282;
V_62 = F_253 () ;
if ( V_62 )
goto V_283;
V_62 = F_254 ( & V_284 ) ;
if ( V_62 )
goto V_285;
V_62 = F_255 ( & V_286 ) ;
if ( V_62 )
goto V_287;
V_62 = F_256 () ;
if ( V_62 )
goto V_288;
V_62 = F_227 () ;
if ( V_62 < 0 )
goto V_289;
return 0 ;
V_289:
F_257 () ;
V_288:
F_258 ( & V_286 ) ;
V_287:
F_259 ( & V_284 ) ;
V_285:
F_260 () ;
V_283:
F_261 () ;
V_282:
F_262 () ;
V_281:
F_263 () ;
error:
return V_62 ;
}
static void F_264 ( void )
{
F_225 ( F_228 ( V_272 ) ) ;
F_257 () ;
F_258 ( & V_286 ) ;
F_259 ( & V_284 ) ;
F_265 () ;
F_260 () ;
F_261 () ;
F_262 () ;
F_263 () ;
}
