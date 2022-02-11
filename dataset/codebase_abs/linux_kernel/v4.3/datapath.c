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
return F_22 ( V_20 ) ;
}
static int F_23 ( const struct V_15 * V_21 )
{
struct V_20 * V_23 ;
int V_24 ;
F_18 () ;
V_23 = F_24 ( V_21 , V_22 ) ;
if ( V_23 )
V_24 = V_23 -> V_19 -> V_24 ;
else
V_24 = 0 ;
F_19 () ;
return V_24 ;
}
static void F_25 ( struct V_25 * V_26 )
{
struct V_15 * V_21 = F_26 ( V_26 , struct V_15 , V_26 ) ;
F_27 ( & V_21 -> V_27 ) ;
F_28 ( V_21 -> V_28 ) ;
F_29 ( V_21 -> V_29 ) ;
F_29 ( V_21 ) ;
}
static struct V_30 * F_30 ( const struct V_15 * V_21 ,
T_1 V_31 )
{
return & V_21 -> V_29 [ V_31 & ( V_32 - 1 ) ] ;
}
struct V_20 * F_31 ( const struct V_15 * V_21 , T_1 V_31 )
{
struct V_20 * V_20 ;
struct V_30 * V_33 ;
V_33 = F_30 ( V_21 , V_31 ) ;
F_32 (vport, head, dp_hash_node) {
if ( V_20 -> V_31 == V_31 )
return V_20 ;
}
return NULL ;
}
static struct V_20 * F_33 ( const struct V_34 * V_35 )
{
struct V_20 * V_20 ;
V_20 = F_34 ( V_35 ) ;
if ( ! F_35 ( V_20 ) ) {
struct V_15 * V_21 = V_35 -> V_21 ;
struct V_30 * V_33 = F_30 ( V_21 , V_20 -> V_31 ) ;
F_36 ( & V_20 -> V_36 , V_33 ) ;
}
return V_20 ;
}
void F_37 ( struct V_20 * V_37 )
{
F_38 () ;
F_39 ( & V_37 -> V_36 ) ;
F_40 ( V_37 ) ;
}
void F_41 ( struct V_9 * V_10 , struct V_38 * V_39 )
{
const struct V_20 * V_37 = F_42 ( V_10 ) -> V_40 ;
struct V_15 * V_21 = V_37 -> V_21 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
T_2 * V_47 ;
T_3 V_48 ;
V_46 = F_43 ( V_21 -> V_28 ) ;
V_42 = F_44 ( & V_21 -> V_27 , V_39 , & V_48 ) ;
if ( F_45 ( ! V_42 ) ) {
struct V_49 V_50 ;
int error ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_51 = V_52 ;
V_50 . V_53 = F_46 ( V_37 , V_10 ) ;
V_50 . V_54 = F_42 ( V_10 ) -> V_54 ;
error = F_47 ( V_21 , V_10 , V_39 , & V_50 ) ;
if ( F_45 ( error ) )
F_48 ( V_10 ) ;
else
F_49 ( V_10 ) ;
V_47 = & V_46 -> V_55 ;
goto V_56;
}
F_50 ( V_42 , V_39 -> V_57 . V_58 , V_10 ) ;
V_44 = F_51 ( V_42 -> V_44 ) ;
F_52 ( V_21 , V_10 , V_44 , V_39 ) ;
V_47 = & V_46 -> V_59 ;
V_56:
F_53 ( & V_46 -> V_60 ) ;
( * V_47 ) ++ ;
V_46 -> V_48 += V_48 ;
F_54 ( & V_46 -> V_60 ) ;
}
int F_47 ( struct V_15 * V_21 , struct V_9 * V_10 ,
const struct V_38 * V_39 ,
const struct V_49 * V_61 )
{
struct V_45 * V_46 ;
int V_62 ;
if ( V_61 -> V_53 == 0 ) {
V_62 = - V_63 ;
goto V_62;
}
if ( ! F_55 ( V_10 ) )
V_62 = F_56 ( V_21 , V_10 , V_39 , V_61 ) ;
else
V_62 = F_57 ( V_21 , V_10 , V_39 , V_61 ) ;
if ( V_62 )
goto V_62;
return 0 ;
V_62:
V_46 = F_43 ( V_21 -> V_28 ) ;
F_53 ( & V_46 -> V_60 ) ;
V_46 -> V_64 ++ ;
F_54 ( & V_46 -> V_60 ) ;
return V_62 ;
}
static int F_57 ( struct V_15 * V_21 , struct V_9 * V_10 ,
const struct V_38 * V_39 ,
const struct V_49 * V_61 )
{
unsigned short V_65 = F_58 ( V_10 ) -> V_65 ;
struct V_38 V_66 ;
struct V_9 * V_67 , * V_68 ;
struct V_69 V_70 ;
int V_62 ;
V_70 = * F_42 ( V_10 ) ;
V_67 = F_59 ( V_10 , V_71 , false ) ;
* F_42 ( V_10 ) = V_70 ;
if ( F_35 ( V_67 ) )
return F_60 ( V_67 ) ;
if ( V_67 == NULL )
return - V_72 ;
if ( V_65 & V_73 ) {
V_66 = * V_39 ;
V_66 . V_74 . V_75 = V_76 ;
}
V_10 = V_67 ;
do {
* F_42 ( V_10 ) = V_70 ;
if ( V_65 & V_73 && V_10 != V_67 )
V_39 = & V_66 ;
V_62 = F_56 ( V_21 , V_10 , V_39 , V_61 ) ;
if ( V_62 )
break;
} while ( ( V_10 = V_10 -> V_77 ) );
V_10 = V_67 ;
do {
V_68 = V_10 -> V_77 ;
if ( V_62 )
F_48 ( V_10 ) ;
else
F_49 ( V_10 ) ;
} while ( ( V_10 = V_68 ) );
return V_62 ;
}
static T_4 F_61 ( const struct V_49 * V_61 ,
unsigned int V_78 )
{
T_4 V_79 = F_62 ( sizeof( struct V_80 ) )
+ F_63 ( V_78 )
+ F_63 ( F_64 () ) ;
if ( V_61 -> V_81 )
V_79 += F_65 ( V_61 -> V_81 -> V_82 ) ;
if ( V_61 -> V_83 )
V_79 += F_63 ( F_66 () ) ;
if ( V_61 -> V_84 )
V_79 += F_63 ( V_61 -> V_84 ) ;
if ( V_61 -> V_54 )
V_79 += F_63 ( sizeof( V_61 -> V_54 ) ) ;
return V_79 ;
}
static void F_67 ( struct V_15 * V_21 , struct V_9 * V_10 )
{
if ( ! ( V_21 -> V_85 & V_86 ) ) {
T_4 V_87 = F_65 ( V_10 -> V_88 ) - V_10 -> V_88 ;
if ( V_87 > 0 )
memset ( F_68 ( V_10 , V_87 ) , 0 , V_87 ) ;
}
}
static int F_56 ( struct V_15 * V_21 , struct V_9 * V_10 ,
const struct V_38 * V_39 ,
const struct V_49 * V_61 )
{
struct V_80 * V_50 ;
struct V_9 * V_68 = NULL ;
struct V_9 * V_89 = NULL ;
struct V_90 * V_91 ;
struct V_3 V_4 = {
. V_92 = F_69 ( V_21 ) -> V_93 ,
. V_11 = V_61 -> V_53 ,
} ;
T_4 V_88 ;
unsigned int V_94 ;
int V_62 , V_17 ;
V_17 = F_23 ( V_21 ) ;
if ( ! V_17 )
return - V_95 ;
if ( F_70 ( V_10 ) ) {
V_68 = F_71 ( V_10 , V_96 ) ;
if ( ! V_68 )
return - V_97 ;
V_68 = F_72 ( V_68 ) ;
if ( ! V_68 )
return - V_97 ;
V_10 = V_68 ;
}
if ( F_73 ( V_10 -> V_88 ) > V_98 ) {
V_62 = - V_99 ;
goto V_56;
}
if ( V_10 -> V_100 == V_101 &&
( V_62 = F_74 ( V_10 ) ) )
goto V_56;
if ( V_21 -> V_85 & V_86 )
V_94 = F_75 ( V_10 ) ;
else
V_94 = V_10 -> V_88 ;
V_88 = F_61 ( V_61 , V_94 ) ;
V_89 = F_76 ( V_88 , & V_4 , V_96 ) ;
if ( ! V_89 ) {
V_62 = - V_97 ;
goto V_56;
}
V_50 = F_77 ( V_89 , 0 , 0 , & V_102 ,
0 , V_61 -> V_51 ) ;
V_50 -> V_17 = V_17 ;
V_62 = F_78 ( V_39 , V_39 , V_103 , false , V_89 ) ;
F_79 ( V_62 ) ;
if ( V_61 -> V_81 )
F_80 ( V_89 , V_104 ,
V_82 ( V_61 -> V_81 ) ,
F_81 ( V_61 -> V_81 ) ) ;
if ( V_61 -> V_83 ) {
V_91 = F_82 ( V_89 , V_105 ) ;
V_62 = F_83 ( V_89 ,
V_61 -> V_83 ) ;
F_79 ( V_62 ) ;
F_84 ( V_89 , V_91 ) ;
}
if ( V_61 -> V_84 ) {
V_91 = F_82 ( V_89 , V_106 ) ;
V_62 = F_85 ( V_61 -> V_107 ,
V_61 -> V_84 ,
V_89 ) ;
if ( ! V_62 )
F_84 ( V_89 , V_91 ) ;
else
F_86 ( V_89 , V_91 ) ;
}
if ( V_61 -> V_54 ) {
if ( F_87 ( V_89 , V_108 ,
V_61 -> V_54 ) ) {
V_62 = - V_109 ;
goto V_56;
}
F_67 ( V_21 , V_89 ) ;
}
if ( ! ( V_91 = F_88 ( V_89 , V_110 , 0 ) ) ) {
V_62 = - V_109 ;
goto V_56;
}
V_91 -> V_82 = F_73 ( V_10 -> V_88 ) ;
V_62 = F_89 ( V_89 , V_10 , V_10 -> V_88 , V_94 ) ;
if ( V_62 )
goto V_56;
F_67 ( V_21 , V_89 ) ;
( (struct V_111 * ) V_89 -> V_112 ) -> V_113 = V_89 -> V_88 ;
V_62 = F_90 ( F_69 ( V_21 ) , V_89 , V_61 -> V_53 ) ;
V_89 = NULL ;
V_56:
if ( V_62 )
F_91 ( V_10 ) ;
F_48 ( V_89 ) ;
F_48 ( V_68 ) ;
return V_62 ;
}
static int F_92 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_16 * V_16 = F_93 ( V_10 -> V_115 ) ;
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_43 * V_118 ;
struct V_9 * V_119 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_15 * V_21 ;
struct V_120 * V_121 ;
struct V_20 * V_40 ;
T_1 V_54 = 0 ;
int V_88 ;
int V_62 ;
bool log = ! V_116 [ V_122 ] ;
V_62 = - V_72 ;
if ( ! V_116 [ V_110 ] || ! V_116 [ V_103 ] ||
! V_116 [ V_106 ] )
goto V_62;
V_88 = V_82 ( V_116 [ V_110 ] ) ;
V_119 = F_94 ( V_123 + V_88 , V_12 ) ;
V_62 = - V_97 ;
if ( ! V_119 )
goto V_62;
F_95 ( V_119 , V_123 ) ;
F_96 ( F_97 ( V_119 , V_88 ) , V_116 [ V_110 ] , V_88 ) ;
F_98 ( V_119 ) ;
V_121 = F_99 ( V_119 ) ;
if ( F_100 ( V_121 -> V_124 ) )
V_119 -> V_125 = V_121 -> V_124 ;
else
V_119 -> V_125 = F_101 ( V_126 ) ;
if ( V_116 [ V_108 ] ) {
V_54 = F_102 ( V_116 [ V_108 ] ) ;
V_119 -> V_127 = 1 ;
}
F_42 ( V_119 ) -> V_54 = V_54 ;
V_42 = F_103 () ;
V_62 = F_60 ( V_42 ) ;
if ( F_35 ( V_42 ) )
goto V_128;
V_62 = F_104 ( V_16 , V_116 [ V_103 ] ,
V_119 , & V_42 -> V_39 , log ) ;
if ( V_62 )
goto V_129;
V_62 = F_105 ( V_16 , V_116 [ V_106 ] ,
& V_42 -> V_39 , & V_118 , log ) ;
if ( V_62 )
goto V_129;
F_106 ( V_42 -> V_44 , V_118 ) ;
V_119 -> V_130 = V_42 -> V_39 . V_131 . V_130 ;
V_119 -> V_132 = V_42 -> V_39 . V_131 . V_133 ;
F_18 () ;
V_21 = F_12 ( V_16 , V_80 -> V_17 ) ;
V_62 = - V_95 ;
if ( ! V_21 )
goto V_134;
V_40 = F_24 ( V_21 , V_42 -> V_39 . V_131 . V_135 ) ;
if ( ! V_40 )
V_40 = F_24 ( V_21 , V_22 ) ;
if ( ! V_40 )
goto V_134;
V_119 -> V_19 = V_40 -> V_19 ;
F_42 ( V_119 ) -> V_40 = V_40 ;
V_44 = F_51 ( V_42 -> V_44 ) ;
F_107 () ;
V_62 = F_52 ( V_21 , V_119 , V_44 , & V_42 -> V_39 ) ;
F_108 () ;
F_19 () ;
F_109 ( V_42 , false ) ;
return V_62 ;
V_134:
F_19 () ;
V_129:
F_109 ( V_42 , false ) ;
V_128:
F_48 ( V_119 ) ;
V_62:
return V_62 ;
}
static void F_110 ( const struct V_15 * V_21 , struct V_136 * V_46 ,
struct V_137 * V_138 )
{
int V_139 ;
memset ( V_138 , 0 , sizeof( * V_138 ) ) ;
V_46 -> V_140 = F_111 ( & V_21 -> V_27 ) ;
V_138 -> V_141 = F_112 ( & V_21 -> V_27 ) ;
V_46 -> V_59 = V_46 -> V_55 = V_46 -> V_64 = 0 ;
F_113 (i) {
const struct V_45 * V_142 ;
struct V_45 V_143 ;
unsigned int V_144 ;
V_142 = F_114 ( V_21 -> V_28 , V_139 ) ;
do {
V_144 = F_115 ( & V_142 -> V_60 ) ;
V_143 = * V_142 ;
} while ( F_116 ( & V_142 -> V_60 , V_144 ) );
V_46 -> V_59 += V_143 . V_59 ;
V_46 -> V_55 += V_143 . V_55 ;
V_46 -> V_64 += V_143 . V_64 ;
V_138 -> V_48 += V_143 . V_48 ;
}
}
static bool F_117 ( const struct V_145 * V_146 , T_5 V_147 )
{
return F_118 ( V_146 ) &&
! ( V_147 & V_148 ) ;
}
static bool F_119 ( T_5 V_147 )
{
return ! ( V_147 & V_149 ) ;
}
static bool F_120 ( T_5 V_147 )
{
return ! ( V_147 & V_150 ) ;
}
static T_4 F_121 ( const struct V_43 * V_118 ,
const struct V_145 * V_146 ,
T_5 V_147 )
{
T_4 V_88 = F_62 ( sizeof( struct V_80 ) ) ;
if ( V_146 && F_118 ( V_146 ) )
V_88 += F_63 ( V_146 -> V_151 ) ;
if ( ! V_146 || F_117 ( V_146 , V_147 ) )
V_88 += F_63 ( F_64 () ) ;
if ( F_119 ( V_147 ) )
V_88 += F_63 ( F_64 () ) ;
if ( F_120 ( V_147 ) )
V_88 += F_63 ( V_118 -> V_152 ) ;
return V_88
+ F_63 ( sizeof( struct V_153 ) )
+ F_63 ( 1 )
+ F_63 ( 8 ) ;
}
static int F_122 ( const struct V_41 * V_42 ,
struct V_9 * V_10 )
{
struct V_153 V_46 ;
T_6 V_154 ;
unsigned long V_155 ;
F_123 ( V_42 , & V_46 , & V_155 , & V_154 ) ;
if ( V_155 &&
F_124 ( V_10 , V_156 , F_125 ( V_155 ) ) )
return - V_157 ;
if ( V_46 . V_158 &&
F_126 ( V_10 , V_159 , sizeof( struct V_153 ) , & V_46 ) )
return - V_157 ;
if ( ( V_160 ) F_127 ( V_154 ) &&
F_128 ( V_10 , V_161 , ( V_160 ) F_127 ( V_154 ) ) )
return - V_157 ;
return 0 ;
}
static int F_129 ( const struct V_41 * V_42 ,
struct V_9 * V_10 , int V_162 )
{
struct V_90 * V_144 ;
int V_62 ;
V_144 = F_82 ( V_10 , V_163 ) ;
if ( V_144 ) {
const struct V_43 * V_44 ;
V_44 = F_130 ( V_42 -> V_44 ) ;
V_62 = F_85 ( V_44 -> V_107 ,
V_44 -> V_84 , V_10 ) ;
if ( ! V_62 )
F_84 ( V_10 , V_144 ) ;
else {
if ( V_162 )
return V_62 ;
F_86 ( V_10 , V_144 ) ;
}
} else if ( V_162 ) {
return - V_157 ;
}
return 0 ;
}
static int F_131 ( const struct V_41 * V_42 , int V_17 ,
struct V_9 * V_10 , T_3 V_53 ,
T_3 V_164 , T_3 V_58 , V_160 V_51 , T_3 V_147 )
{
const int V_162 = V_10 -> V_88 ;
struct V_80 * V_80 ;
int V_62 ;
V_80 = F_77 ( V_10 , V_53 , V_164 , & V_165 ,
V_58 , V_51 ) ;
if ( ! V_80 )
return - V_157 ;
V_80 -> V_17 = V_17 ;
V_62 = F_132 ( V_42 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_117 ( & V_42 -> V_166 , V_147 ) ) {
V_62 = F_133 ( V_42 , V_10 ) ;
if ( V_62 )
goto error;
}
if ( F_119 ( V_147 ) ) {
V_62 = F_134 ( V_42 , V_10 ) ;
if ( V_62 )
goto error;
}
V_62 = F_122 ( V_42 , V_10 ) ;
if ( V_62 )
goto error;
if ( F_120 ( V_147 ) ) {
V_62 = F_129 ( V_42 , V_10 , V_162 ) ;
if ( V_62 )
goto error;
}
F_135 ( V_10 , V_80 ) ;
return 0 ;
error:
F_136 ( V_10 , V_80 ) ;
return V_62 ;
}
static struct V_9 * F_137 ( const struct V_43 * V_118 ,
const struct V_145 * V_146 ,
struct V_3 * V_4 ,
bool V_167 ,
T_5 V_147 )
{
struct V_9 * V_10 ;
T_4 V_88 ;
if ( ! V_167 && ! F_1 ( & V_165 , V_4 , 0 ) )
return NULL ;
V_88 = F_121 ( V_118 , V_146 , V_147 ) ;
V_10 = F_76 ( V_88 , V_4 , V_12 ) ;
if ( ! V_10 )
return F_138 ( - V_97 ) ;
return V_10 ;
}
static struct V_9 * F_139 ( const struct V_41 * V_42 ,
int V_17 ,
struct V_3 * V_4 , V_160 V_51 ,
bool V_167 , T_3 V_147 )
{
struct V_9 * V_10 ;
int V_168 ;
V_10 = F_137 ( F_140 ( V_42 -> V_44 ) ,
& V_42 -> V_166 , V_4 , V_167 , V_147 ) ;
if ( F_141 ( V_10 ) )
return V_10 ;
V_168 = F_131 ( V_42 , V_17 , V_10 ,
V_4 -> V_11 , V_4 -> V_169 , 0 ,
V_51 , V_147 ) ;
F_79 ( V_168 < 0 ) ;
return V_10 ;
}
static int F_142 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_16 * V_16 = F_93 ( V_10 -> V_115 ) ;
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_41 * V_42 = NULL , * V_170 ;
struct V_171 V_172 ;
struct V_9 * V_173 ;
struct V_15 * V_21 ;
struct V_38 V_39 ;
struct V_43 * V_118 ;
struct V_174 V_175 ;
T_3 V_147 = F_143 ( V_116 [ V_176 ] ) ;
int error ;
bool log = ! V_116 [ V_177 ] ;
error = - V_72 ;
if ( ! V_116 [ V_178 ] ) {
F_144 ( log , L_1 ) ;
goto error;
}
if ( ! V_116 [ V_163 ] ) {
F_144 ( log , L_2 ) ;
goto error;
}
V_170 = F_103 () ;
if ( F_35 ( V_170 ) ) {
error = F_60 ( V_170 ) ;
goto error;
}
F_145 ( & V_175 , & V_39 , & V_172 ) ;
error = F_146 ( V_16 , & V_175 , V_116 [ V_178 ] ,
V_116 [ V_179 ] , log ) ;
if ( error )
goto V_180;
F_147 ( & V_170 -> V_39 , & V_39 , true , & V_172 ) ;
error = F_148 ( & V_170 -> V_166 , V_116 [ V_181 ] ,
& V_39 , log ) ;
if ( error )
goto V_180;
error = F_105 ( V_16 , V_116 [ V_163 ] ,
& V_170 -> V_39 , & V_118 , log ) ;
if ( error ) {
F_144 ( log , L_3 ) ;
goto V_180;
}
V_173 = F_137 ( V_118 , & V_170 -> V_166 , V_4 , false ,
V_147 ) ;
if ( F_35 ( V_173 ) ) {
error = F_60 ( V_173 ) ;
goto V_182;
}
F_6 () ;
V_21 = F_15 ( V_16 , V_80 -> V_17 ) ;
if ( F_45 ( ! V_21 ) ) {
error = - V_95 ;
goto V_183;
}
if ( F_118 ( & V_170 -> V_166 ) )
V_42 = F_149 ( & V_21 -> V_27 , & V_170 -> V_166 ) ;
if ( ! V_42 )
V_42 = F_150 ( & V_21 -> V_27 , & V_39 ) ;
if ( F_151 ( ! V_42 ) ) {
F_106 ( V_170 -> V_44 , V_118 ) ;
error = F_152 ( & V_21 -> V_27 , V_170 , & V_172 ) ;
if ( F_45 ( error ) ) {
V_118 = NULL ;
goto V_183;
}
if ( F_45 ( V_173 ) ) {
error = F_131 ( V_170 ,
V_80 -> V_17 ,
V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 ,
V_184 ,
V_147 ) ;
F_79 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_43 * V_185 ;
if ( F_45 ( V_4 -> V_6 -> V_7 & ( V_186
| V_187 ) ) ) {
error = - V_188 ;
goto V_183;
}
if ( F_45 ( ! F_153 ( V_42 , & V_175 ) ) ) {
if ( F_154 ( & V_42 -> V_166 ) )
V_42 = F_155 ( & V_21 -> V_27 ,
& V_175 ) ;
else
V_42 = NULL ;
if ( ! V_42 ) {
error = - V_189 ;
goto V_183;
}
}
V_185 = F_140 ( V_42 -> V_44 ) ;
F_106 ( V_42 -> V_44 , V_118 ) ;
if ( F_45 ( V_173 ) ) {
error = F_131 ( V_42 ,
V_80 -> V_17 ,
V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 ,
V_184 ,
V_147 ) ;
F_79 ( error < 0 ) ;
}
F_8 () ;
F_156 ( V_185 ) ;
F_109 ( V_170 , false ) ;
}
if ( V_173 )
F_4 ( & V_165 , V_173 , V_4 ) ;
return 0 ;
V_183:
F_8 () ;
F_48 ( V_173 ) ;
V_182:
F_157 ( V_118 ) ;
V_180:
F_109 ( V_170 , false ) ;
error:
return error ;
}
static struct V_43 * F_158 ( struct V_16 * V_16 ,
const struct V_90 * V_116 ,
const struct V_38 * V_39 ,
const struct V_171 * V_172 ,
bool log )
{
struct V_43 * V_118 ;
struct V_38 V_190 ;
int error ;
F_147 ( & V_190 , V_39 , true , V_172 ) ;
error = F_105 ( V_16 , V_116 , & V_190 , & V_118 , log ) ;
if ( error ) {
F_144 ( log ,
L_4 ) ;
return F_138 ( error ) ;
}
return V_118 ;
}
static int F_159 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_16 * V_16 = F_93 ( V_10 -> V_115 ) ;
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_38 V_39 ;
struct V_41 * V_42 ;
struct V_171 V_172 ;
struct V_9 * V_173 = NULL ;
struct V_15 * V_21 ;
struct V_43 * V_185 = NULL , * V_118 = NULL ;
struct V_174 V_175 ;
struct V_145 V_146 ;
T_3 V_147 = F_143 ( V_116 [ V_176 ] ) ;
int error ;
bool log = ! V_116 [ V_177 ] ;
bool V_191 ;
error = - V_72 ;
if ( ! V_116 [ V_178 ] ) {
F_144 ( log , L_5 ) ;
goto error;
}
V_191 = F_160 ( & V_146 , V_116 [ V_181 ] , log ) ;
F_145 ( & V_175 , & V_39 , & V_172 ) ;
error = F_146 ( V_16 , & V_175 , V_116 [ V_178 ] ,
V_116 [ V_179 ] , log ) ;
if ( error )
goto error;
if ( V_116 [ V_163 ] ) {
V_118 = F_158 ( V_16 , V_116 [ V_163 ] , & V_39 ,
& V_172 , log ) ;
if ( F_35 ( V_118 ) ) {
error = F_60 ( V_118 ) ;
goto error;
}
V_173 = F_137 ( V_118 , & V_146 , V_4 , false ,
V_147 ) ;
if ( F_35 ( V_173 ) ) {
error = F_60 ( V_173 ) ;
goto V_182;
}
}
F_6 () ;
V_21 = F_15 ( V_16 , V_80 -> V_17 ) ;
if ( F_45 ( ! V_21 ) ) {
error = - V_95 ;
goto V_183;
}
if ( V_191 )
V_42 = F_149 ( & V_21 -> V_27 , & V_146 ) ;
else
V_42 = F_155 ( & V_21 -> V_27 , & V_175 ) ;
if ( F_45 ( ! V_42 ) ) {
error = - V_189 ;
goto V_183;
}
if ( F_151 ( V_118 ) ) {
V_185 = F_140 ( V_42 -> V_44 ) ;
F_106 ( V_42 -> V_44 , V_118 ) ;
if ( F_45 ( V_173 ) ) {
error = F_131 ( V_42 ,
V_80 -> V_17 ,
V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 ,
V_184 ,
V_147 ) ;
F_79 ( error < 0 ) ;
}
} else {
V_173 = F_139 ( V_42 , V_80 -> V_17 ,
V_4 , V_184 , false ,
V_147 ) ;
if ( F_45 ( F_35 ( V_173 ) ) ) {
error = F_60 ( V_173 ) ;
goto V_183;
}
}
if ( V_116 [ V_192 ] )
F_161 ( V_42 ) ;
F_8 () ;
if ( V_173 )
F_4 ( & V_165 , V_173 , V_4 ) ;
if ( V_185 )
F_156 ( V_185 ) ;
return 0 ;
V_183:
F_8 () ;
F_48 ( V_173 ) ;
V_182:
F_157 ( V_118 ) ;
error:
return error ;
}
static int F_162 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_16 * V_16 = F_93 ( V_10 -> V_115 ) ;
struct V_38 V_39 ;
struct V_9 * V_173 ;
struct V_41 * V_42 ;
struct V_15 * V_21 ;
struct V_174 V_175 ;
struct V_145 V_193 ;
T_3 V_147 = F_143 ( V_116 [ V_176 ] ) ;
int V_62 = 0 ;
bool log = ! V_116 [ V_177 ] ;
bool V_191 ;
V_191 = F_160 ( & V_193 , V_116 [ V_181 ] , log ) ;
if ( V_116 [ V_178 ] ) {
F_145 ( & V_175 , & V_39 , NULL ) ;
V_62 = F_146 ( V_16 , & V_175 , V_116 [ V_178 ] , NULL ,
log ) ;
} else if ( ! V_191 ) {
F_144 ( log ,
L_6 ) ;
V_62 = - V_72 ;
}
if ( V_62 )
return V_62 ;
F_6 () ;
V_21 = F_15 ( F_93 ( V_10 -> V_115 ) , V_80 -> V_17 ) ;
if ( ! V_21 ) {
V_62 = - V_95 ;
goto V_194;
}
if ( V_191 )
V_42 = F_149 ( & V_21 -> V_27 , & V_193 ) ;
else
V_42 = F_155 ( & V_21 -> V_27 , & V_175 ) ;
if ( ! V_42 ) {
V_62 = - V_189 ;
goto V_194;
}
V_173 = F_139 ( V_42 , V_80 -> V_17 , V_4 ,
V_184 , true , V_147 ) ;
if ( F_35 ( V_173 ) ) {
V_62 = F_60 ( V_173 ) ;
goto V_194;
}
F_8 () ;
return F_163 ( V_173 , V_4 ) ;
V_194:
F_8 () ;
return V_62 ;
}
static int F_164 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_16 * V_16 = F_93 ( V_10 -> V_115 ) ;
struct V_38 V_39 ;
struct V_9 * V_173 ;
struct V_41 * V_42 = NULL ;
struct V_15 * V_21 ;
struct V_174 V_175 ;
struct V_145 V_193 ;
T_3 V_147 = F_143 ( V_116 [ V_176 ] ) ;
int V_62 ;
bool log = ! V_116 [ V_177 ] ;
bool V_191 ;
V_191 = F_160 ( & V_193 , V_116 [ V_181 ] , log ) ;
if ( V_116 [ V_178 ] ) {
F_145 ( & V_175 , & V_39 , NULL ) ;
V_62 = F_146 ( V_16 , & V_175 , V_116 [ V_178 ] ,
NULL , log ) ;
if ( F_45 ( V_62 ) )
return V_62 ;
}
F_6 () ;
V_21 = F_15 ( F_93 ( V_10 -> V_115 ) , V_80 -> V_17 ) ;
if ( F_45 ( ! V_21 ) ) {
V_62 = - V_95 ;
goto V_194;
}
if ( F_45 ( ! V_116 [ V_178 ] && ! V_191 ) ) {
V_62 = F_165 ( & V_21 -> V_27 ) ;
goto V_194;
}
if ( V_191 )
V_42 = F_149 ( & V_21 -> V_27 , & V_193 ) ;
else
V_42 = F_155 ( & V_21 -> V_27 , & V_175 ) ;
if ( F_45 ( ! V_42 ) ) {
V_62 = - V_189 ;
goto V_194;
}
F_166 ( & V_21 -> V_27 , V_42 ) ;
F_8 () ;
V_173 = F_137 ( ( const struct V_43 V_195 * ) V_42 -> V_44 ,
& V_42 -> V_166 , V_4 , false , V_147 ) ;
if ( F_151 ( V_173 ) ) {
if ( F_151 ( ! F_35 ( V_173 ) ) ) {
F_18 () ;
V_62 = F_131 ( V_42 , V_80 -> V_17 ,
V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 ,
V_196 ,
V_147 ) ;
F_19 () ;
F_79 ( V_62 < 0 ) ;
F_4 ( & V_165 , V_173 , V_4 ) ;
} else {
F_167 ( F_93 ( V_10 -> V_115 ) -> V_93 , 0 , 0 , F_60 ( V_173 ) ) ;
}
}
F_109 ( V_42 , true ) ;
return 0 ;
V_194:
F_8 () ;
return V_62 ;
}
static int F_168 ( struct V_9 * V_10 , struct V_197 * V_198 )
{
struct V_90 * V_116 [ V_199 ] ;
struct V_80 * V_80 = F_169 ( F_170 ( V_198 -> V_200 ) ) ;
struct V_201 * V_202 ;
struct V_15 * V_21 ;
T_3 V_147 ;
int V_62 ;
V_62 = F_171 ( V_198 -> V_200 , & V_165 , V_116 ,
V_203 , V_204 ) ;
if ( V_62 )
return V_62 ;
V_147 = F_143 ( V_116 [ V_176 ] ) ;
F_18 () ;
V_21 = F_12 ( F_93 ( V_10 -> V_115 ) , V_80 -> V_17 ) ;
if ( ! V_21 ) {
F_19 () ;
return - V_95 ;
}
V_202 = F_51 ( V_21 -> V_27 . V_202 ) ;
for (; ; ) {
struct V_41 * V_42 ;
T_3 V_205 , V_206 ;
V_205 = V_198 -> args [ 0 ] ;
V_206 = V_198 -> args [ 1 ] ;
V_42 = F_172 ( V_202 , & V_205 , & V_206 ) ;
if ( ! V_42 )
break;
if ( F_131 ( V_42 , V_80 -> V_17 , V_10 ,
F_173 ( V_198 -> V_10 ) . V_53 ,
V_198 -> V_200 -> V_207 , V_208 ,
V_184 , V_147 ) < 0 )
break;
V_198 -> args [ 0 ] = V_205 ;
V_198 -> args [ 1 ] = V_206 ;
}
F_19 () ;
return V_10 -> V_88 ;
}
static T_4 F_174 ( void )
{
T_4 V_209 = F_62 ( sizeof( struct V_80 ) ) ;
V_209 += F_63 ( V_210 ) ;
V_209 += F_63 ( sizeof( struct V_136 ) ) ;
V_209 += F_63 ( sizeof( struct V_137 ) ) ;
V_209 += F_63 ( sizeof( T_3 ) ) ;
return V_209 ;
}
static int F_175 ( struct V_15 * V_21 , struct V_9 * V_10 ,
T_3 V_53 , T_3 V_164 , T_3 V_58 , V_160 V_51 )
{
struct V_80 * V_80 ;
struct V_136 V_211 ;
struct V_137 V_212 ;
int V_62 ;
V_80 = F_77 ( V_10 , V_53 , V_164 , & V_213 ,
V_58 , V_51 ) ;
if ( ! V_80 )
goto error;
V_80 -> V_17 = F_23 ( V_21 ) ;
V_62 = F_176 ( V_10 , V_214 , F_20 ( V_21 ) ) ;
if ( V_62 )
goto V_215;
F_110 ( V_21 , & V_211 , & V_212 ) ;
if ( F_126 ( V_10 , V_216 , sizeof( struct V_136 ) ,
& V_211 ) )
goto V_215;
if ( F_126 ( V_10 , V_217 ,
sizeof( struct V_137 ) ,
& V_212 ) )
goto V_215;
if ( F_177 ( V_10 , V_218 , V_21 -> V_85 ) )
goto V_215;
F_135 ( V_10 , V_80 ) ;
return 0 ;
V_215:
F_136 ( V_10 , V_80 ) ;
error:
return - V_157 ;
}
static struct V_9 * F_178 ( struct V_3 * V_4 )
{
return F_76 ( F_174 () , V_4 , V_12 ) ;
}
static struct V_15 * F_179 ( struct V_16 * V_16 ,
const struct V_80 * V_80 ,
struct V_90 * V_116 [ V_219 + 1 ] )
{
struct V_15 * V_21 ;
if ( ! V_116 [ V_214 ] )
V_21 = F_15 ( V_16 , V_80 -> V_17 ) ;
else {
struct V_20 * V_20 ;
V_20 = F_180 ( V_16 , F_81 ( V_116 [ V_214 ] ) ) ;
V_21 = V_20 && V_20 -> V_31 == V_22 ? V_20 -> V_21 : NULL ;
}
return V_21 ? V_21 : F_138 ( - V_95 ) ;
}
static void F_181 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_15 * V_21 ;
V_21 = F_179 ( F_93 ( V_10 -> V_115 ) , V_4 -> V_114 , V_4 -> V_117 ) ;
if ( F_35 ( V_21 ) )
return;
F_182 ( V_21 -> V_85 , L_7 ) ;
V_21 -> V_85 = 0 ;
}
static void F_183 ( struct V_15 * V_21 , struct V_90 * V_116 [] )
{
if ( V_116 [ V_218 ] )
V_21 -> V_85 = F_184 ( V_116 [ V_218 ] ) ;
}
static int F_185 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_34 V_35 ;
struct V_9 * V_173 ;
struct V_15 * V_21 ;
struct V_20 * V_20 ;
struct V_220 * V_220 ;
int V_62 , V_139 ;
V_62 = - V_72 ;
if ( ! V_116 [ V_214 ] || ! V_116 [ V_221 ] )
goto V_62;
V_173 = F_178 ( V_4 ) ;
if ( ! V_173 )
return - V_97 ;
V_62 = - V_97 ;
V_21 = F_186 ( sizeof( * V_21 ) , V_12 ) ;
if ( V_21 == NULL )
goto V_222;
F_187 ( V_21 , F_93 ( V_10 -> V_115 ) ) ;
V_62 = F_188 ( & V_21 -> V_27 ) ;
if ( V_62 )
goto V_223;
V_21 -> V_28 = F_189 ( struct V_45 ) ;
if ( ! V_21 -> V_28 ) {
V_62 = - V_97 ;
goto V_224;
}
V_21 -> V_29 = F_190 ( V_32 * sizeof( struct V_30 ) ,
V_12 ) ;
if ( ! V_21 -> V_29 ) {
V_62 = - V_97 ;
goto V_225;
}
for ( V_139 = 0 ; V_139 < V_32 ; V_139 ++ )
F_191 ( & V_21 -> V_29 [ V_139 ] ) ;
V_35 . V_226 = F_81 ( V_116 [ V_214 ] ) ;
V_35 . type = V_227 ;
V_35 . V_228 = NULL ;
V_35 . V_21 = V_21 ;
V_35 . V_31 = V_22 ;
V_35 . V_229 = V_116 [ V_221 ] ;
F_183 ( V_21 , V_116 ) ;
F_6 () ;
V_20 = F_33 ( & V_35 ) ;
if ( F_35 ( V_20 ) ) {
V_62 = F_60 ( V_20 ) ;
if ( V_62 == - V_230 )
V_62 = - V_188 ;
if ( V_62 == - V_188 ) {
if ( V_4 -> V_231 -> V_232 < V_233 )
F_181 ( V_10 , V_4 ) ;
}
goto V_234;
}
V_62 = F_175 ( V_21 , V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 , V_235 ) ;
F_79 ( V_62 < 0 ) ;
V_220 = F_192 ( F_69 ( V_21 ) , V_236 ) ;
F_193 ( & V_21 -> V_237 , & V_220 -> V_238 ) ;
F_8 () ;
F_4 ( & V_213 , V_173 , V_4 ) ;
return 0 ;
V_234:
F_8 () ;
F_29 ( V_21 -> V_29 ) ;
V_225:
F_28 ( V_21 -> V_28 ) ;
V_224:
F_27 ( & V_21 -> V_27 ) ;
V_223:
F_29 ( V_21 ) ;
V_222:
F_48 ( V_173 ) ;
V_62:
return V_62 ;
}
static void F_194 ( struct V_15 * V_21 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_32 ; V_139 ++ ) {
struct V_20 * V_20 ;
struct V_239 * V_240 ;
F_195 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_20 -> V_31 != V_22 )
F_37 ( V_20 ) ;
}
F_196 ( & V_21 -> V_237 ) ;
F_37 ( F_197 ( V_21 , V_22 ) ) ;
F_198 ( & V_21 -> V_26 , F_25 ) ;
}
static int F_199 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_173 ;
struct V_15 * V_21 ;
int V_62 ;
V_173 = F_178 ( V_4 ) ;
if ( ! V_173 )
return - V_97 ;
F_6 () ;
V_21 = F_179 ( F_93 ( V_10 -> V_115 ) , V_4 -> V_114 , V_4 -> V_117 ) ;
V_62 = F_60 ( V_21 ) ;
if ( F_35 ( V_21 ) )
goto V_241;
V_62 = F_175 ( V_21 , V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 , V_242 ) ;
F_79 ( V_62 < 0 ) ;
F_194 ( V_21 ) ;
F_8 () ;
F_4 ( & V_213 , V_173 , V_4 ) ;
return 0 ;
V_241:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_200 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_173 ;
struct V_15 * V_21 ;
int V_62 ;
V_173 = F_178 ( V_4 ) ;
if ( ! V_173 )
return - V_97 ;
F_6 () ;
V_21 = F_179 ( F_93 ( V_10 -> V_115 ) , V_4 -> V_114 , V_4 -> V_117 ) ;
V_62 = F_60 ( V_21 ) ;
if ( F_35 ( V_21 ) )
goto V_241;
F_183 ( V_21 , V_4 -> V_117 ) ;
V_62 = F_175 ( V_21 , V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 , V_235 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_213 , V_173 , V_4 ) ;
return 0 ;
V_241:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_201 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_9 * V_173 ;
struct V_15 * V_21 ;
int V_62 ;
V_173 = F_178 ( V_4 ) ;
if ( ! V_173 )
return - V_97 ;
F_6 () ;
V_21 = F_179 ( F_93 ( V_10 -> V_115 ) , V_4 -> V_114 , V_4 -> V_117 ) ;
if ( F_35 ( V_21 ) ) {
V_62 = F_60 ( V_21 ) ;
goto V_241;
}
V_62 = F_175 ( V_21 , V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 , V_235 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
return F_163 ( V_173 , V_4 ) ;
V_241:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_202 ( struct V_9 * V_10 , struct V_197 * V_198 )
{
struct V_220 * V_220 = F_192 ( F_93 ( V_10 -> V_115 ) , V_236 ) ;
struct V_15 * V_21 ;
int V_243 = V_198 -> args [ 0 ] ;
int V_139 = 0 ;
F_6 () ;
F_203 (dp, &ovs_net->dps, list_node) {
if ( V_139 >= V_243 &&
F_175 ( V_21 , V_10 , F_173 ( V_198 -> V_10 ) . V_53 ,
V_198 -> V_200 -> V_207 , V_208 ,
V_235 ) < 0 )
break;
V_139 ++ ;
}
F_8 () ;
V_198 -> args [ 0 ] = V_139 ;
return V_10 -> V_88 ;
}
static int F_204 ( struct V_20 * V_20 , struct V_9 * V_10 ,
T_3 V_53 , T_3 V_164 , T_3 V_58 , V_160 V_51 )
{
struct V_80 * V_80 ;
struct V_244 V_245 ;
int V_62 ;
V_80 = F_77 ( V_10 , V_53 , V_164 , & V_246 ,
V_58 , V_51 ) ;
if ( ! V_80 )
return - V_157 ;
V_80 -> V_17 = F_23 ( V_20 -> V_21 ) ;
if ( F_177 ( V_10 , V_247 , V_20 -> V_31 ) ||
F_177 ( V_10 , V_248 , V_20 -> V_249 -> type ) ||
F_176 ( V_10 , V_250 ,
F_22 ( V_20 ) ) )
goto V_215;
F_205 ( V_20 , & V_245 ) ;
if ( F_126 ( V_10 , V_251 , sizeof( struct V_244 ) ,
& V_245 ) )
goto V_215;
if ( F_206 ( V_20 , V_10 ) )
goto V_215;
V_62 = F_207 ( V_20 , V_10 ) ;
if ( V_62 == - V_157 )
goto error;
F_135 ( V_10 , V_80 ) ;
return 0 ;
V_215:
V_62 = - V_157 ;
error:
F_136 ( V_10 , V_80 ) ;
return V_62 ;
}
static struct V_9 * F_208 ( void )
{
return F_209 ( V_252 , V_12 ) ;
}
struct V_9 * F_210 ( struct V_20 * V_20 , T_3 V_53 ,
T_3 V_164 , V_160 V_51 )
{
struct V_9 * V_10 ;
int V_168 ;
V_10 = F_209 ( V_252 , V_96 ) ;
if ( ! V_10 )
return F_138 ( - V_97 ) ;
V_168 = F_204 ( V_20 , V_10 , V_53 , V_164 , 0 , V_51 ) ;
F_79 ( V_168 < 0 ) ;
return V_10 ;
}
static struct V_20 * F_211 ( struct V_16 * V_16 ,
const struct V_80 * V_80 ,
struct V_90 * V_116 [ V_253 + 1 ] )
{
struct V_15 * V_21 ;
struct V_20 * V_20 ;
if ( V_116 [ V_250 ] ) {
V_20 = F_180 ( V_16 , F_81 ( V_116 [ V_250 ] ) ) ;
if ( ! V_20 )
return F_138 ( - V_95 ) ;
if ( V_80 -> V_17 &&
V_80 -> V_17 != F_23 ( V_20 -> V_21 ) )
return F_138 ( - V_95 ) ;
return V_20 ;
} else if ( V_116 [ V_247 ] ) {
T_3 V_31 = F_184 ( V_116 [ V_247 ] ) ;
if ( V_31 >= V_254 )
return F_138 ( - V_99 ) ;
V_21 = F_15 ( V_16 , V_80 -> V_17 ) ;
if ( ! V_21 )
return F_138 ( - V_95 ) ;
V_20 = F_21 ( V_21 , V_31 ) ;
if ( ! V_20 )
return F_138 ( - V_95 ) ;
return V_20 ;
} else
return F_138 ( - V_72 ) ;
}
static int F_212 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_34 V_35 ;
struct V_9 * V_173 ;
struct V_20 * V_20 ;
struct V_15 * V_21 ;
T_3 V_31 ;
int V_62 ;
if ( ! V_116 [ V_250 ] || ! V_116 [ V_248 ] ||
! V_116 [ V_255 ] )
return - V_72 ;
V_31 = V_116 [ V_247 ]
? F_184 ( V_116 [ V_247 ] ) : 0 ;
if ( V_31 >= V_254 )
return - V_99 ;
V_173 = F_208 () ;
if ( ! V_173 )
return - V_97 ;
F_6 () ;
V_256:
V_21 = F_15 ( F_93 ( V_10 -> V_115 ) , V_80 -> V_17 ) ;
V_62 = - V_95 ;
if ( ! V_21 )
goto V_257;
if ( V_31 ) {
V_20 = F_197 ( V_21 , V_31 ) ;
V_62 = - V_230 ;
if ( V_20 )
goto V_257;
} else {
for ( V_31 = 1 ; ; V_31 ++ ) {
if ( V_31 >= V_254 ) {
V_62 = - V_99 ;
goto V_257;
}
V_20 = F_197 ( V_21 , V_31 ) ;
if ( ! V_20 )
break;
}
}
V_35 . V_226 = F_81 ( V_116 [ V_250 ] ) ;
V_35 . type = F_184 ( V_116 [ V_248 ] ) ;
V_35 . V_228 = V_116 [ V_258 ] ;
V_35 . V_21 = V_21 ;
V_35 . V_31 = V_31 ;
V_35 . V_229 = V_116 [ V_255 ] ;
V_20 = F_33 ( & V_35 ) ;
V_62 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) ) {
if ( V_62 == - V_259 )
goto V_256;
goto V_257;
}
V_62 = F_204 ( V_20 , V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 , V_260 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_246 , V_173 , V_4 ) ;
return 0 ;
V_257:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_213 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_9 * V_173 ;
struct V_20 * V_20 ;
int V_62 ;
V_173 = F_208 () ;
if ( ! V_173 )
return - V_97 ;
F_6 () ;
V_20 = F_211 ( F_93 ( V_10 -> V_115 ) , V_4 -> V_114 , V_116 ) ;
V_62 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_257;
if ( V_116 [ V_248 ] &&
F_184 ( V_116 [ V_248 ] ) != V_20 -> V_249 -> type ) {
V_62 = - V_72 ;
goto V_257;
}
if ( V_116 [ V_258 ] ) {
V_62 = F_214 ( V_20 , V_116 [ V_258 ] ) ;
if ( V_62 )
goto V_257;
}
if ( V_116 [ V_255 ] ) {
struct V_90 * V_261 = V_116 [ V_255 ] ;
V_62 = F_215 ( V_20 , V_261 ) ;
if ( V_62 )
goto V_257;
}
V_62 = F_204 ( V_20 , V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 , V_260 ) ;
F_79 ( V_62 < 0 ) ;
F_8 () ;
F_4 ( & V_246 , V_173 , V_4 ) ;
return 0 ;
V_257:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_216 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_9 * V_173 ;
struct V_20 * V_20 ;
int V_62 ;
V_173 = F_208 () ;
if ( ! V_173 )
return - V_97 ;
F_6 () ;
V_20 = F_211 ( F_93 ( V_10 -> V_115 ) , V_4 -> V_114 , V_116 ) ;
V_62 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_257;
if ( V_20 -> V_31 == V_22 ) {
V_62 = - V_72 ;
goto V_257;
}
V_62 = F_204 ( V_20 , V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 , V_262 ) ;
F_79 ( V_62 < 0 ) ;
F_37 ( V_20 ) ;
F_8 () ;
F_4 ( & V_246 , V_173 , V_4 ) ;
return 0 ;
V_257:
F_8 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_217 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_90 * * V_116 = V_4 -> V_117 ;
struct V_80 * V_80 = V_4 -> V_114 ;
struct V_9 * V_173 ;
struct V_20 * V_20 ;
int V_62 ;
V_173 = F_208 () ;
if ( ! V_173 )
return - V_97 ;
F_18 () ;
V_20 = F_211 ( F_93 ( V_10 -> V_115 ) , V_80 , V_116 ) ;
V_62 = F_60 ( V_20 ) ;
if ( F_35 ( V_20 ) )
goto V_257;
V_62 = F_204 ( V_20 , V_173 , V_4 -> V_11 ,
V_4 -> V_169 , 0 , V_260 ) ;
F_79 ( V_62 < 0 ) ;
F_19 () ;
return F_163 ( V_173 , V_4 ) ;
V_257:
F_19 () ;
F_48 ( V_173 ) ;
return V_62 ;
}
static int F_218 ( struct V_9 * V_10 , struct V_197 * V_198 )
{
struct V_80 * V_80 = F_169 ( F_170 ( V_198 -> V_200 ) ) ;
struct V_15 * V_21 ;
int V_205 = V_198 -> args [ 0 ] , V_243 = V_198 -> args [ 1 ] ;
int V_139 , V_263 = 0 ;
F_18 () ;
V_21 = F_12 ( F_93 ( V_10 -> V_115 ) , V_80 -> V_17 ) ;
if ( ! V_21 ) {
F_19 () ;
return - V_95 ;
}
for ( V_139 = V_205 ; V_139 < V_32 ; V_139 ++ ) {
struct V_20 * V_20 ;
V_263 = 0 ;
F_32 (vport, &dp->ports[i], dp_hash_node) {
if ( V_263 >= V_243 &&
F_204 ( V_20 , V_10 ,
F_173 ( V_198 -> V_10 ) . V_53 ,
V_198 -> V_200 -> V_207 ,
V_208 ,
V_260 ) < 0 )
goto V_56;
V_263 ++ ;
}
V_243 = 0 ;
}
V_56:
F_19 () ;
V_198 -> args [ 0 ] = V_139 ;
V_198 -> args [ 1 ] = V_263 ;
return V_10 -> V_88 ;
}
static void F_219 ( int V_264 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_264 ; V_139 ++ )
F_220 ( V_265 [ V_139 ] ) ;
}
static int F_221 ( void )
{
int V_62 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < F_222 ( V_265 ) ; V_139 ++ ) {
V_62 = F_223 ( V_265 [ V_139 ] ) ;
if ( V_62 )
goto error;
}
return 0 ;
error:
F_219 ( V_139 ) ;
return V_62 ;
}
static int T_7 F_224 ( struct V_16 * V_16 )
{
struct V_220 * V_220 = F_192 ( V_16 , V_236 ) ;
F_225 ( & V_220 -> V_238 ) ;
F_226 ( & V_220 -> V_266 , V_267 ) ;
F_227 ( V_16 ) ;
return 0 ;
}
static void T_8 F_228 ( struct V_16 * V_16 , struct V_16 * V_268 ,
struct V_269 * V_33 )
{
struct V_220 * V_220 = F_192 ( V_16 , V_236 ) ;
struct V_15 * V_21 ;
F_203 (dp, &ovs_net->dps, list_node) {
int V_139 ;
for ( V_139 = 0 ; V_139 < V_32 ; V_139 ++ ) {
struct V_20 * V_20 ;
F_229 (vport, &dp->ports[i], dp_hash_node) {
if ( V_20 -> V_249 -> type != V_227 )
continue;
if ( F_230 ( V_20 -> V_19 ) == V_268 )
F_231 ( & V_20 -> V_270 , V_33 ) ;
}
}
}
}
static void T_8 F_232 ( struct V_16 * V_268 )
{
struct V_15 * V_21 , * V_271 ;
struct V_220 * V_220 = F_192 ( V_268 , V_236 ) ;
struct V_20 * V_20 , * V_272 ;
struct V_16 * V_16 ;
F_233 ( V_33 ) ;
F_234 ( V_268 ) ;
F_6 () ;
F_235 (dp, dp_next, &ovs_net->dps, list_node)
F_194 ( V_21 ) ;
F_236 () ;
F_237 (net)
F_228 ( V_16 , V_268 , & V_33 ) ;
F_238 () ;
F_235 (vport, vport_next, &head, detach_list) {
F_239 ( & V_20 -> V_270 ) ;
F_37 ( V_20 ) ;
}
F_8 () ;
F_240 ( & V_220 -> V_266 ) ;
}
static int T_9 F_241 ( void )
{
int V_62 ;
F_242 ( sizeof( struct V_69 ) > F_243 ( struct V_9 , V_198 ) ) ;
F_244 ( L_8 ) ;
V_62 = F_245 () ;
if ( V_62 )
goto error;
V_62 = F_246 () ;
if ( V_62 )
goto V_273;
V_62 = F_247 () ;
if ( V_62 )
goto V_274;
V_62 = F_248 () ;
if ( V_62 )
goto V_275;
V_62 = F_249 ( & V_276 ) ;
if ( V_62 )
goto V_277;
V_62 = F_250 ( & V_278 ) ;
if ( V_62 )
goto V_279;
V_62 = F_251 () ;
if ( V_62 )
goto V_280;
V_62 = F_221 () ;
if ( V_62 < 0 )
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
return V_62 ;
}
static void F_259 ( void )
{
F_219 ( F_222 ( V_265 ) ) ;
F_252 () ;
F_253 ( & V_278 ) ;
F_254 ( & V_276 ) ;
F_260 () ;
F_255 () ;
F_256 () ;
F_257 () ;
F_258 () ;
}
