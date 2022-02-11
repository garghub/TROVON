static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 )
{
return V_4 -> V_6 -> V_7 & V_8 ||
F_2 ( V_2 , F_3 ( V_4 ) -> V_9 ,
V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 , struct V_3 * V_4 )
{
F_5 ( V_2 , V_11 , F_3 ( V_4 ) , V_4 -> V_12 ,
0 , V_4 -> V_6 , V_13 ) ;
}
void F_6 ( void )
{
F_7 ( & V_14 ) ;
}
void F_8 ( void )
{
F_9 ( & V_14 ) ;
}
int F_10 ( void )
{
if ( V_15 )
return F_11 ( & V_14 ) ;
else
return 1 ;
}
static struct V_16 * F_12 ( struct V_17 * V_17 , int V_18 )
{
struct V_16 * V_19 = NULL ;
struct V_20 * V_21 ;
F_13 () ;
V_21 = F_14 ( V_17 , V_18 ) ;
if ( V_21 ) {
struct V_22 * V_22 = F_15 ( V_21 ) ;
if ( V_22 )
V_19 = V_22 -> V_19 ;
}
F_16 () ;
return V_19 ;
}
static const char * F_17 ( const struct V_16 * V_19 )
{
struct V_22 * V_22 = F_18 ( V_19 , V_23 ) ;
return V_22 -> V_24 -> V_25 ( V_22 ) ;
}
static int F_19 ( struct V_16 * V_19 )
{
struct V_22 * V_26 ;
int V_27 ;
F_13 () ;
V_26 = F_20 ( V_19 , V_23 ) ;
if ( V_26 )
V_27 = F_21 ( V_26 ) -> V_21 -> V_27 ;
else
V_27 = 0 ;
F_16 () ;
return V_27 ;
}
static void F_22 ( struct V_28 * V_29 )
{
struct V_16 * V_19 = F_23 ( V_29 , struct V_16 , V_29 ) ;
F_24 ( V_19 -> V_30 ) ;
F_25 ( F_26 ( V_19 ) ) ;
F_27 ( V_19 -> V_31 ) ;
F_27 ( V_19 ) ;
}
static struct V_32 * F_28 ( const struct V_16 * V_19 ,
T_1 V_33 )
{
return & V_19 -> V_31 [ V_33 & ( V_34 - 1 ) ] ;
}
struct V_22 * F_29 ( const struct V_16 * V_19 , T_1 V_33 )
{
struct V_22 * V_22 ;
struct V_32 * V_35 ;
V_35 = F_28 ( V_19 , V_33 ) ;
F_30 (vport, head, dp_hash_node) {
if ( V_22 -> V_33 == V_33 )
return V_22 ;
}
return NULL ;
}
static struct V_22 * F_31 ( const struct V_36 * V_37 )
{
struct V_22 * V_22 ;
V_22 = F_32 ( V_37 ) ;
if ( ! F_33 ( V_22 ) ) {
struct V_16 * V_19 = V_37 -> V_19 ;
struct V_32 * V_35 = F_28 ( V_19 , V_22 -> V_33 ) ;
F_34 ( & V_22 -> V_38 , V_35 ) ;
}
return V_22 ;
}
void F_35 ( struct V_22 * V_39 )
{
F_36 () ;
F_37 ( & V_39 -> V_38 ) ;
F_38 ( V_39 ) ;
}
void F_39 ( struct V_22 * V_39 , struct V_10 * V_11 )
{
struct V_16 * V_19 = V_39 -> V_19 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 V_45 ;
T_2 * V_46 ;
T_3 V_47 ;
int error ;
V_43 = F_40 ( V_19 -> V_30 ) ;
error = F_41 ( V_11 , V_39 -> V_33 , & V_45 ) ;
if ( F_42 ( error ) ) {
F_43 ( V_11 ) ;
return;
}
V_41 = F_44 ( & V_19 -> V_48 , & V_45 , & V_47 ) ;
if ( F_42 ( ! V_41 ) ) {
struct V_49 V_50 ;
V_50 . V_51 = V_52 ;
V_50 . V_45 = & V_45 ;
V_50 . V_53 = NULL ;
V_50 . V_54 = F_45 ( V_39 , V_11 ) ;
error = F_46 ( V_19 , V_11 , & V_50 ) ;
if ( F_42 ( error ) )
F_43 ( V_11 ) ;
else
F_47 ( V_11 ) ;
V_46 = & V_43 -> V_55 ;
goto V_56;
}
F_48 ( V_11 ) -> V_41 = V_41 ;
F_48 ( V_11 ) -> V_57 = & V_45 ;
F_49 ( F_48 ( V_11 ) -> V_41 , V_45 . V_58 . V_59 , V_11 ) ;
F_50 ( V_19 , V_11 ) ;
V_46 = & V_43 -> V_60 ;
V_56:
F_51 ( & V_43 -> V_61 ) ;
( * V_46 ) ++ ;
V_43 -> V_47 += V_47 ;
F_52 ( & V_43 -> V_61 ) ;
}
int F_46 ( struct V_16 * V_19 , struct V_10 * V_11 ,
const struct V_49 * V_62 )
{
struct V_42 * V_43 ;
int V_63 ;
if ( V_62 -> V_54 == 0 ) {
V_63 = - V_64 ;
goto V_63;
}
if ( ! F_53 ( V_11 ) )
V_63 = F_54 ( V_19 , V_11 , V_62 ) ;
else
V_63 = F_55 ( V_19 , V_11 , V_62 ) ;
if ( V_63 )
goto V_63;
return 0 ;
V_63:
V_43 = F_40 ( V_19 -> V_30 ) ;
F_51 ( & V_43 -> V_61 ) ;
V_43 -> V_65 ++ ;
F_52 ( & V_43 -> V_61 ) ;
return V_63 ;
}
static int F_55 ( struct V_16 * V_19 , struct V_10 * V_11 ,
const struct V_49 * V_62 )
{
unsigned short V_66 = F_56 ( V_11 ) -> V_66 ;
struct V_49 V_67 ;
struct V_44 V_68 ;
struct V_10 * V_69 , * V_70 ;
int V_63 ;
V_69 = F_57 ( V_11 , V_71 , false ) ;
if ( F_33 ( V_69 ) )
return F_58 ( V_69 ) ;
V_11 = V_69 ;
do {
V_63 = F_54 ( V_19 , V_11 , V_62 ) ;
if ( V_63 )
break;
if ( V_11 == V_69 && V_66 & V_72 ) {
V_68 = * V_62 -> V_45 ;
V_68 . V_73 . V_74 = V_75 ;
V_67 = * V_62 ;
V_67 . V_45 = & V_68 ;
V_62 = & V_67 ;
}
} while ( ( V_11 = V_11 -> V_76 ) );
V_11 = V_69 ;
do {
V_70 = V_11 -> V_76 ;
if ( V_63 )
F_43 ( V_11 ) ;
else
F_47 ( V_11 ) ;
} while ( ( V_11 = V_70 ) );
return V_63 ;
}
static T_4 F_59 ( void )
{
return F_60 ( 4 )
+ F_60 ( 0 )
+ F_60 ( 8 )
+ F_60 ( 4 )
+ F_60 ( 4 )
+ F_60 ( 1 )
+ F_60 ( 1 )
+ F_60 ( 0 )
+ F_60 ( 0 )
+ F_60 ( 4 )
+ F_60 ( 4 )
+ F_60 ( 12 )
+ F_60 ( 2 )
+ F_60 ( 4 )
+ F_60 ( 0 )
+ F_60 ( 2 )
+ F_60 ( 40 )
+ F_60 ( 2 )
+ F_60 ( 28 ) ;
}
static T_4 F_61 ( const struct V_77 * V_53 ,
unsigned int V_78 )
{
T_4 V_79 = F_62 ( sizeof( struct V_80 ) )
+ F_60 ( V_78 )
+ F_60 ( F_59 () ) ;
if ( V_53 )
V_79 += F_63 ( V_53 -> V_81 ) ;
return V_79 ;
}
static int F_54 ( struct V_16 * V_19 , struct V_10 * V_11 ,
const struct V_49 * V_62 )
{
struct V_80 * V_50 ;
struct V_10 * V_70 = NULL ;
struct V_10 * V_82 = NULL ;
struct V_77 * V_83 ;
struct V_3 V_4 = {
. V_84 = F_26 ( V_19 ) -> V_9 ,
. V_12 = V_62 -> V_54 ,
} ;
T_4 V_85 ;
unsigned int V_86 ;
int V_63 , V_18 ;
V_18 = F_19 ( V_19 ) ;
if ( ! V_18 )
return - V_87 ;
if ( F_64 ( V_11 ) ) {
V_70 = F_65 ( V_11 , V_88 ) ;
if ( ! V_70 )
return - V_89 ;
V_70 = F_66 ( V_70 , V_70 -> V_90 , F_67 ( V_70 ) ) ;
if ( ! V_70 )
return - V_89 ;
V_70 -> V_91 = 0 ;
V_11 = V_70 ;
}
if ( F_68 ( V_11 -> V_85 ) > V_92 ) {
V_63 = - V_93 ;
goto V_56;
}
if ( V_11 -> V_94 == V_95 &&
( V_63 = F_69 ( V_11 ) ) )
goto V_56;
if ( V_19 -> V_96 & V_97 )
V_86 = F_70 ( V_11 ) ;
else
V_86 = V_11 -> V_85 ;
V_85 = F_61 ( V_62 -> V_53 , V_86 ) ;
V_82 = F_71 ( V_85 , & V_4 , V_88 ) ;
if ( ! V_82 ) {
V_63 = - V_89 ;
goto V_56;
}
V_50 = F_72 ( V_82 , 0 , 0 , & V_98 ,
0 , V_62 -> V_51 ) ;
V_50 -> V_18 = V_18 ;
V_83 = F_73 ( V_82 , V_99 ) ;
V_63 = F_74 ( V_62 -> V_45 , V_62 -> V_45 , V_82 ) ;
F_75 ( V_63 ) ;
F_76 ( V_82 , V_83 ) ;
if ( V_62 -> V_53 )
F_77 ( V_82 , V_100 ,
V_81 ( V_62 -> V_53 ) ,
F_78 ( V_62 -> V_53 ) ) ;
if ( ! ( V_83 = F_79 ( V_82 , V_101 , 0 ) ) ) {
V_63 = - V_102 ;
goto V_56;
}
V_83 -> V_81 = F_68 ( V_11 -> V_85 ) ;
V_63 = F_80 ( V_82 , V_11 , V_11 -> V_85 , V_86 ) ;
if ( V_63 )
goto V_56;
if ( ! ( V_19 -> V_96 & V_97 ) ) {
T_4 V_103 = F_63 ( V_82 -> V_85 ) - V_82 -> V_85 ;
if ( V_103 > 0 )
memset ( F_81 ( V_82 , V_103 ) , 0 , V_103 ) ;
}
( (struct V_104 * ) V_82 -> V_105 ) -> V_106 = V_82 -> V_85 ;
V_63 = F_82 ( F_26 ( V_19 ) , V_82 , V_62 -> V_54 ) ;
V_82 = NULL ;
V_56:
if ( V_63 )
F_83 ( V_11 ) ;
F_43 ( V_82 ) ;
F_43 ( V_70 ) ;
return V_63 ;
}
static int F_84 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_80 * V_80 = V_4 -> V_107 ;
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_110 * V_111 ;
struct V_10 * V_112 ;
struct V_40 * V_41 ;
struct V_16 * V_19 ;
struct V_113 * V_114 ;
int V_85 ;
int V_63 ;
V_63 = - V_115 ;
if ( ! V_108 [ V_101 ] || ! V_108 [ V_99 ] ||
! V_108 [ V_116 ] )
goto V_63;
V_85 = V_81 ( V_108 [ V_101 ] ) ;
V_112 = F_85 ( V_117 + V_85 , V_13 ) ;
V_63 = - V_89 ;
if ( ! V_112 )
goto V_63;
F_86 ( V_112 , V_117 ) ;
F_87 ( F_88 ( V_112 , V_85 ) , V_108 [ V_101 ] , V_85 ) ;
F_89 ( V_112 ) ;
V_114 = F_90 ( V_112 ) ;
if ( F_91 ( V_114 -> V_118 ) >= V_119 )
V_112 -> V_120 = V_114 -> V_118 ;
else
V_112 -> V_120 = F_92 ( V_121 ) ;
V_41 = F_93 () ;
V_63 = F_58 ( V_41 ) ;
if ( F_33 ( V_41 ) )
goto V_122;
V_63 = F_41 ( V_112 , - 1 , & V_41 -> V_45 ) ;
if ( V_63 )
goto V_123;
V_63 = F_94 ( V_41 , V_108 [ V_99 ] ) ;
if ( V_63 )
goto V_123;
V_111 = F_95 ( V_81 ( V_108 [ V_116 ] ) ) ;
V_63 = F_58 ( V_111 ) ;
if ( F_33 ( V_111 ) )
goto V_123;
V_63 = F_96 ( V_108 [ V_116 ] ,
& V_41 -> V_45 , 0 , & V_111 ) ;
F_97 ( V_41 -> V_124 , V_111 ) ;
if ( V_63 )
goto V_123;
F_48 ( V_112 ) -> V_41 = V_41 ;
F_48 ( V_112 ) -> V_57 = & V_41 -> V_45 ;
V_112 -> V_125 = V_41 -> V_45 . V_126 . V_125 ;
V_112 -> V_127 = V_41 -> V_45 . V_126 . V_128 ;
F_13 () ;
V_19 = F_12 ( F_98 ( V_11 -> V_129 ) , V_80 -> V_18 ) ;
V_63 = - V_87 ;
if ( ! V_19 )
goto V_130;
F_99 () ;
V_63 = F_50 ( V_19 , V_112 ) ;
F_100 () ;
F_16 () ;
F_101 ( V_41 , false ) ;
return V_63 ;
V_130:
F_16 () ;
V_123:
F_101 ( V_41 , false ) ;
V_122:
F_43 ( V_112 ) ;
V_63:
return V_63 ;
}
static void F_102 ( struct V_16 * V_19 , struct V_131 * V_43 ,
struct V_132 * V_133 )
{
int V_134 ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_43 -> V_135 = F_103 ( & V_19 -> V_48 ) ;
V_133 -> V_136 = F_104 ( & V_19 -> V_48 ) ;
V_43 -> V_60 = V_43 -> V_55 = V_43 -> V_65 = 0 ;
F_105 (i) {
const struct V_42 * V_137 ;
struct V_42 V_138 ;
unsigned int V_139 ;
V_137 = F_106 ( V_19 -> V_30 , V_134 ) ;
do {
V_139 = F_107 ( & V_137 -> V_61 ) ;
V_138 = * V_137 ;
} while ( F_108 ( & V_137 -> V_61 , V_139 ) );
V_43 -> V_60 += V_138 . V_60 ;
V_43 -> V_55 += V_138 . V_55 ;
V_43 -> V_65 += V_138 . V_65 ;
V_133 -> V_47 += V_138 . V_47 ;
}
}
static T_4 F_109 ( const struct V_110 * V_111 )
{
return F_62 ( sizeof( struct V_80 ) )
+ F_60 ( F_59 () )
+ F_60 ( F_59 () )
+ F_60 ( sizeof( struct V_140 ) )
+ F_60 ( 1 )
+ F_60 ( 8 )
+ F_60 ( V_111 -> V_141 ) ;
}
static int F_110 ( const struct V_40 * V_41 , int V_18 ,
struct V_10 * V_11 , T_3 V_54 ,
T_3 V_142 , T_3 V_59 , T_5 V_51 )
{
const int V_143 = V_11 -> V_85 ;
struct V_77 * V_139 ;
struct V_140 V_43 ;
T_6 V_144 ;
unsigned long V_145 ;
struct V_80 * V_80 ;
struct V_77 * V_83 ;
int V_63 ;
V_80 = F_72 ( V_11 , V_54 , V_142 , & V_146 , V_59 , V_51 ) ;
if ( ! V_80 )
return - V_147 ;
V_80 -> V_18 = V_18 ;
V_83 = F_73 ( V_11 , V_148 ) ;
if ( ! V_83 )
goto V_149;
V_63 = F_74 ( & V_41 -> V_150 , & V_41 -> V_150 , V_11 ) ;
if ( V_63 )
goto error;
F_76 ( V_11 , V_83 ) ;
V_83 = F_73 ( V_11 , V_151 ) ;
if ( ! V_83 )
goto V_149;
V_63 = F_74 ( & V_41 -> V_45 , & V_41 -> V_152 -> V_45 , V_11 ) ;
if ( V_63 )
goto error;
F_76 ( V_11 , V_83 ) ;
F_111 ( V_41 , & V_43 , & V_145 , & V_144 ) ;
if ( V_145 &&
F_112 ( V_11 , V_153 , F_113 ( V_145 ) ) )
goto V_149;
if ( V_43 . V_154 &&
F_114 ( V_11 , V_155 , sizeof( struct V_140 ) , & V_43 ) )
goto V_149;
if ( ( T_5 ) F_91 ( V_144 ) &&
F_115 ( V_11 , V_156 , ( T_5 ) F_91 ( V_144 ) ) )
goto V_149;
V_139 = F_73 ( V_11 , V_157 ) ;
if ( V_139 ) {
const struct V_110 * V_124 ;
V_124 = F_116 ( V_41 -> V_124 ) ;
V_63 = F_117 ( V_124 -> V_158 ,
V_124 -> V_141 , V_11 ) ;
if ( ! V_63 )
F_76 ( V_11 , V_139 ) ;
else {
if ( V_143 )
goto error;
F_118 ( V_11 , V_139 ) ;
}
} else if ( V_143 )
goto V_149;
return F_119 ( V_11 , V_80 ) ;
V_149:
V_63 = - V_147 ;
error:
F_120 ( V_11 , V_80 ) ;
return V_63 ;
}
static struct V_10 * F_121 ( const struct V_110 * V_111 ,
struct V_3 * V_4 ,
bool V_159 )
{
struct V_10 * V_11 ;
if ( ! V_159 && ! F_1 ( & V_146 , V_4 , 0 ) )
return NULL ;
V_11 = F_71 ( F_109 ( V_111 ) , V_4 , V_13 ) ;
if ( ! V_11 )
return F_122 ( - V_89 ) ;
return V_11 ;
}
static struct V_10 * F_123 ( const struct V_40 * V_41 ,
int V_18 ,
struct V_3 * V_4 , T_5 V_51 ,
bool V_159 )
{
struct V_10 * V_11 ;
int V_160 ;
V_11 = F_121 ( F_124 ( V_41 -> V_124 ) , V_4 ,
V_159 ) ;
if ( F_125 ( V_11 ) )
return V_11 ;
V_160 = F_110 ( V_41 , V_18 , V_11 ,
V_4 -> V_12 , V_4 -> V_161 , 0 ,
V_51 ) ;
F_75 ( V_160 < 0 ) ;
return V_11 ;
}
static int F_126 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_80 * V_80 = V_4 -> V_107 ;
struct V_40 * V_41 , * V_162 ;
struct V_163 V_152 ;
struct V_10 * V_164 ;
struct V_16 * V_19 ;
struct V_110 * V_111 ;
struct V_165 V_166 ;
int error ;
error = - V_115 ;
if ( ! V_108 [ V_148 ] )
goto error;
if ( ! V_108 [ V_157 ] )
goto error;
V_162 = F_93 () ;
if ( F_33 ( V_162 ) ) {
error = F_58 ( V_162 ) ;
goto error;
}
F_127 ( & V_166 , & V_162 -> V_150 , & V_152 ) ;
error = F_128 ( & V_166 ,
V_108 [ V_148 ] , V_108 [ V_151 ] ) ;
if ( error )
goto V_167;
F_129 ( & V_162 -> V_45 , & V_162 -> V_150 , & V_152 ) ;
V_111 = F_95 ( V_81 ( V_108 [ V_157 ] ) ) ;
error = F_58 ( V_111 ) ;
if ( F_33 ( V_111 ) )
goto V_167;
error = F_96 ( V_108 [ V_157 ] , & V_162 -> V_45 ,
0 , & V_111 ) ;
if ( error ) {
F_130 ( L_1 ) ;
goto V_168;
}
V_164 = F_121 ( V_111 , V_4 , false ) ;
if ( F_33 ( V_164 ) ) {
error = F_58 ( V_164 ) ;
goto V_168;
}
F_6 () ;
V_19 = F_12 ( F_98 ( V_11 -> V_129 ) , V_80 -> V_18 ) ;
if ( F_42 ( ! V_19 ) ) {
error = - V_87 ;
goto V_169;
}
V_41 = F_131 ( & V_19 -> V_48 , & V_162 -> V_150 ) ;
if ( F_132 ( ! V_41 ) ) {
F_97 ( V_162 -> V_124 , V_111 ) ;
error = F_133 ( & V_19 -> V_48 , V_162 , & V_152 ) ;
if ( F_42 ( error ) ) {
V_111 = NULL ;
goto V_169;
}
if ( F_42 ( V_164 ) ) {
error = F_110 ( V_162 ,
V_80 -> V_18 ,
V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 ,
V_170 ) ;
F_75 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_110 * V_171 ;
if ( F_42 ( V_4 -> V_6 -> V_7 & ( V_172
| V_173 ) ) ) {
error = - V_174 ;
goto V_169;
}
if ( F_42 ( ! F_134 ( V_41 , & V_166 ) ) ) {
V_41 = F_135 ( & V_19 -> V_48 , & V_166 ) ;
if ( ! V_41 ) {
error = - V_175 ;
goto V_169;
}
}
V_171 = F_124 ( V_41 -> V_124 ) ;
F_97 ( V_41 -> V_124 , V_111 ) ;
if ( F_42 ( V_164 ) ) {
error = F_110 ( V_41 ,
V_80 -> V_18 ,
V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 ,
V_170 ) ;
F_75 ( error < 0 ) ;
}
F_8 () ;
F_136 ( V_171 ) ;
F_101 ( V_162 , false ) ;
}
if ( V_164 )
F_4 ( & V_146 , V_164 , V_4 ) ;
return 0 ;
V_169:
F_8 () ;
F_43 ( V_164 ) ;
V_168:
F_27 ( V_111 ) ;
V_167:
F_101 ( V_162 , false ) ;
error:
return error ;
}
static int F_137 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_80 * V_80 = V_4 -> V_107 ;
struct V_44 V_45 , V_176 ;
struct V_40 * V_41 ;
struct V_163 V_152 ;
struct V_10 * V_164 = NULL ;
struct V_16 * V_19 ;
struct V_110 * V_171 = NULL , * V_111 = NULL ;
struct V_165 V_166 ;
int error ;
error = - V_115 ;
if ( ! V_108 [ V_148 ] )
goto error;
F_127 ( & V_166 , & V_45 , & V_152 ) ;
error = F_128 ( & V_166 ,
V_108 [ V_148 ] , V_108 [ V_151 ] ) ;
if ( error )
goto error;
if ( V_108 [ V_157 ] ) {
V_111 = F_95 ( V_81 ( V_108 [ V_157 ] ) ) ;
error = F_58 ( V_111 ) ;
if ( F_33 ( V_111 ) )
goto error;
F_129 ( & V_176 , & V_45 , & V_152 ) ;
error = F_96 ( V_108 [ V_157 ] ,
& V_176 , 0 , & V_111 ) ;
if ( error ) {
F_130 ( L_1 ) ;
goto V_168;
}
}
if ( V_111 ) {
V_164 = F_121 ( V_111 , V_4 , false ) ;
if ( F_33 ( V_164 ) ) {
error = F_58 ( V_164 ) ;
goto V_168;
}
}
F_6 () ;
V_19 = F_12 ( F_98 ( V_11 -> V_129 ) , V_80 -> V_18 ) ;
if ( F_42 ( ! V_19 ) ) {
error = - V_87 ;
goto V_169;
}
V_41 = F_135 ( & V_19 -> V_48 , & V_166 ) ;
if ( F_42 ( ! V_41 ) ) {
error = - V_175 ;
goto V_169;
}
if ( F_132 ( V_111 ) ) {
V_171 = F_124 ( V_41 -> V_124 ) ;
F_97 ( V_41 -> V_124 , V_111 ) ;
if ( F_42 ( V_164 ) ) {
error = F_110 ( V_41 ,
V_80 -> V_18 ,
V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 ,
V_170 ) ;
F_75 ( error < 0 ) ;
}
} else {
V_164 = F_123 ( V_41 , V_80 -> V_18 ,
V_4 , V_170 , false ) ;
if ( F_42 ( F_33 ( V_164 ) ) ) {
error = F_58 ( V_164 ) ;
goto V_169;
}
}
if ( V_108 [ V_177 ] )
F_138 ( V_41 ) ;
F_8 () ;
if ( V_164 )
F_4 ( & V_146 , V_164 , V_4 ) ;
if ( V_171 )
F_136 ( V_171 ) ;
return 0 ;
V_169:
F_8 () ;
F_43 ( V_164 ) ;
V_168:
F_27 ( V_111 ) ;
error:
return error ;
}
static int F_139 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_80 * V_80 = V_4 -> V_107 ;
struct V_44 V_45 ;
struct V_10 * V_164 ;
struct V_40 * V_41 ;
struct V_16 * V_19 ;
struct V_165 V_166 ;
int V_63 ;
if ( ! V_108 [ V_148 ] ) {
F_130 ( L_2 ) ;
return - V_115 ;
}
F_127 ( & V_166 , & V_45 , NULL ) ;
V_63 = F_128 ( & V_166 , V_108 [ V_148 ] , NULL ) ;
if ( V_63 )
return V_63 ;
F_6 () ;
V_19 = F_12 ( F_98 ( V_11 -> V_129 ) , V_80 -> V_18 ) ;
if ( ! V_19 ) {
V_63 = - V_87 ;
goto V_178;
}
V_41 = F_135 ( & V_19 -> V_48 , & V_166 ) ;
if ( ! V_41 ) {
V_63 = - V_175 ;
goto V_178;
}
V_164 = F_123 ( V_41 , V_80 -> V_18 , V_4 ,
V_170 , true ) ;
if ( F_33 ( V_164 ) ) {
V_63 = F_58 ( V_164 ) ;
goto V_178;
}
F_8 () ;
return F_140 ( V_164 , V_4 ) ;
V_178:
F_8 () ;
return V_63 ;
}
static int F_141 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_80 * V_80 = V_4 -> V_107 ;
struct V_44 V_45 ;
struct V_10 * V_164 ;
struct V_40 * V_41 ;
struct V_16 * V_19 ;
struct V_165 V_166 ;
int V_63 ;
if ( F_132 ( V_108 [ V_148 ] ) ) {
F_127 ( & V_166 , & V_45 , NULL ) ;
V_63 = F_128 ( & V_166 , V_108 [ V_148 ] , NULL ) ;
if ( F_42 ( V_63 ) )
return V_63 ;
}
F_6 () ;
V_19 = F_12 ( F_98 ( V_11 -> V_129 ) , V_80 -> V_18 ) ;
if ( F_42 ( ! V_19 ) ) {
V_63 = - V_87 ;
goto V_178;
}
if ( F_42 ( ! V_108 [ V_148 ] ) ) {
V_63 = F_142 ( & V_19 -> V_48 ) ;
goto V_178;
}
V_41 = F_135 ( & V_19 -> V_48 , & V_166 ) ;
if ( F_42 ( ! V_41 ) ) {
V_63 = - V_175 ;
goto V_178;
}
F_143 ( & V_19 -> V_48 , V_41 ) ;
F_8 () ;
V_164 = F_121 ( ( const struct V_110 V_179 * ) V_41 -> V_124 ,
V_4 , false ) ;
if ( F_132 ( V_164 ) ) {
if ( F_132 ( ! F_33 ( V_164 ) ) ) {
F_13 () ;
V_63 = F_110 ( V_41 , V_80 -> V_18 ,
V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 ,
V_180 ) ;
F_16 () ;
F_75 ( V_63 < 0 ) ;
F_4 ( & V_146 , V_164 , V_4 ) ;
} else {
F_144 ( F_98 ( V_11 -> V_129 ) -> V_9 , 0 , 0 , F_58 ( V_164 ) ) ;
}
}
F_101 ( V_41 , true ) ;
return 0 ;
V_178:
F_8 () ;
return V_63 ;
}
static int F_145 ( struct V_10 * V_11 , struct V_181 * V_182 )
{
struct V_80 * V_80 = F_146 ( F_147 ( V_182 -> V_183 ) ) ;
struct V_184 * V_185 ;
struct V_16 * V_19 ;
F_13 () ;
V_19 = F_12 ( F_98 ( V_11 -> V_129 ) , V_80 -> V_18 ) ;
if ( ! V_19 ) {
F_16 () ;
return - V_87 ;
}
V_185 = F_148 ( V_19 -> V_48 . V_185 ) ;
for (; ; ) {
struct V_40 * V_41 ;
T_3 V_186 , V_187 ;
V_186 = V_182 -> args [ 0 ] ;
V_187 = V_182 -> args [ 1 ] ;
V_41 = F_149 ( V_185 , & V_186 , & V_187 ) ;
if ( ! V_41 )
break;
if ( F_110 ( V_41 , V_80 -> V_18 , V_11 ,
F_150 ( V_182 -> V_11 ) . V_54 ,
V_182 -> V_183 -> V_188 , V_189 ,
V_170 ) < 0 )
break;
V_182 -> args [ 0 ] = V_186 ;
V_182 -> args [ 1 ] = V_187 ;
}
F_16 () ;
return V_11 -> V_85 ;
}
static T_4 F_151 ( void )
{
T_4 V_190 = F_62 ( sizeof( struct V_80 ) ) ;
V_190 += F_60 ( V_191 ) ;
V_190 += F_60 ( sizeof( struct V_131 ) ) ;
V_190 += F_60 ( sizeof( struct V_132 ) ) ;
V_190 += F_60 ( sizeof( T_3 ) ) ;
return V_190 ;
}
static int F_152 ( struct V_16 * V_19 , struct V_10 * V_11 ,
T_3 V_54 , T_3 V_142 , T_3 V_59 , T_5 V_51 )
{
struct V_80 * V_80 ;
struct V_131 V_192 ;
struct V_132 V_193 ;
int V_63 ;
V_80 = F_72 ( V_11 , V_54 , V_142 , & V_194 ,
V_59 , V_51 ) ;
if ( ! V_80 )
goto error;
V_80 -> V_18 = F_19 ( V_19 ) ;
V_63 = F_153 ( V_11 , V_195 , F_17 ( V_19 ) ) ;
if ( V_63 )
goto V_149;
F_102 ( V_19 , & V_192 , & V_193 ) ;
if ( F_114 ( V_11 , V_196 , sizeof( struct V_131 ) ,
& V_192 ) )
goto V_149;
if ( F_114 ( V_11 , V_197 ,
sizeof( struct V_132 ) ,
& V_193 ) )
goto V_149;
if ( F_154 ( V_11 , V_198 , V_19 -> V_96 ) )
goto V_149;
return F_119 ( V_11 , V_80 ) ;
V_149:
F_120 ( V_11 , V_80 ) ;
error:
return - V_147 ;
}
static struct V_10 * F_155 ( struct V_3 * V_4 )
{
return F_71 ( F_151 () , V_4 , V_13 ) ;
}
static struct V_16 * F_156 ( struct V_17 * V_17 ,
struct V_80 * V_80 ,
struct V_77 * V_108 [ V_199 + 1 ] )
{
struct V_16 * V_19 ;
if ( ! V_108 [ V_195 ] )
V_19 = F_12 ( V_17 , V_80 -> V_18 ) ;
else {
struct V_22 * V_22 ;
V_22 = F_157 ( V_17 , F_78 ( V_108 [ V_195 ] ) ) ;
V_19 = V_22 && V_22 -> V_33 == V_23 ? V_22 -> V_19 : NULL ;
}
return V_19 ? V_19 : F_122 ( - V_87 ) ;
}
static void F_158 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_16 * V_19 ;
V_19 = F_156 ( F_98 ( V_11 -> V_129 ) , V_4 -> V_107 , V_4 -> V_109 ) ;
if ( F_33 ( V_19 ) )
return;
F_159 ( V_19 -> V_96 , L_3 ) ;
V_19 -> V_96 = 0 ;
}
static void F_160 ( struct V_16 * V_19 , struct V_77 * * V_108 )
{
if ( V_108 [ V_198 ] )
V_19 -> V_96 = F_161 ( V_108 [ V_198 ] ) ;
}
static int F_162 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_36 V_37 ;
struct V_10 * V_164 ;
struct V_16 * V_19 ;
struct V_22 * V_22 ;
struct V_200 * V_200 ;
int V_63 , V_134 ;
V_63 = - V_115 ;
if ( ! V_108 [ V_195 ] || ! V_108 [ V_201 ] )
goto V_63;
V_164 = F_155 ( V_4 ) ;
if ( ! V_164 )
return - V_89 ;
V_63 = - V_89 ;
V_19 = F_163 ( sizeof( * V_19 ) , V_13 ) ;
if ( V_19 == NULL )
goto V_202;
F_164 ( V_19 , F_165 ( F_98 ( V_11 -> V_129 ) ) ) ;
V_63 = F_166 ( & V_19 -> V_48 ) ;
if ( V_63 )
goto V_203;
V_19 -> V_30 = F_167 ( struct V_42 ) ;
if ( ! V_19 -> V_30 ) {
V_63 = - V_89 ;
goto V_204;
}
V_19 -> V_31 = F_168 ( V_34 * sizeof( struct V_32 ) ,
V_13 ) ;
if ( ! V_19 -> V_31 ) {
V_63 = - V_89 ;
goto V_205;
}
for ( V_134 = 0 ; V_134 < V_34 ; V_134 ++ )
F_169 ( & V_19 -> V_31 [ V_134 ] ) ;
V_37 . V_206 = F_78 ( V_108 [ V_195 ] ) ;
V_37 . type = V_207 ;
V_37 . V_208 = NULL ;
V_37 . V_19 = V_19 ;
V_37 . V_33 = V_23 ;
V_37 . V_209 = V_108 [ V_201 ] ;
F_160 ( V_19 , V_108 ) ;
F_6 () ;
V_22 = F_31 ( & V_37 ) ;
if ( F_33 ( V_22 ) ) {
V_63 = F_58 ( V_22 ) ;
if ( V_63 == - V_210 )
V_63 = - V_174 ;
if ( V_63 == - V_174 ) {
if ( V_4 -> V_211 -> V_212 < V_213 )
F_158 ( V_11 , V_4 ) ;
}
goto V_214;
}
V_63 = F_152 ( V_19 , V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 , V_215 ) ;
F_75 ( V_63 < 0 ) ;
V_200 = F_170 ( F_26 ( V_19 ) , V_216 ) ;
F_171 ( & V_19 -> V_217 , & V_200 -> V_218 ) ;
F_8 () ;
F_4 ( & V_194 , V_164 , V_4 ) ;
return 0 ;
V_214:
F_8 () ;
F_27 ( V_19 -> V_31 ) ;
V_205:
F_24 ( V_19 -> V_30 ) ;
V_204:
F_172 ( & V_19 -> V_48 , false ) ;
V_203:
F_25 ( F_26 ( V_19 ) ) ;
F_27 ( V_19 ) ;
V_202:
F_43 ( V_164 ) ;
V_63:
return V_63 ;
}
static void F_173 ( struct V_16 * V_19 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_34 ; V_134 ++ ) {
struct V_22 * V_22 ;
struct V_219 * V_220 ;
F_174 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_22 -> V_33 != V_23 )
F_35 ( V_22 ) ;
}
F_175 ( & V_19 -> V_217 ) ;
F_35 ( F_176 ( V_19 , V_23 ) ) ;
F_172 ( & V_19 -> V_48 , true ) ;
F_177 ( & V_19 -> V_29 , F_22 ) ;
}
static int F_178 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_10 * V_164 ;
struct V_16 * V_19 ;
int V_63 ;
V_164 = F_155 ( V_4 ) ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_19 = F_156 ( F_98 ( V_11 -> V_129 ) , V_4 -> V_107 , V_4 -> V_109 ) ;
V_63 = F_58 ( V_19 ) ;
if ( F_33 ( V_19 ) )
goto V_221;
V_63 = F_152 ( V_19 , V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 , V_222 ) ;
F_75 ( V_63 < 0 ) ;
F_173 ( V_19 ) ;
F_8 () ;
F_4 ( & V_194 , V_164 , V_4 ) ;
return 0 ;
V_221:
F_8 () ;
F_43 ( V_164 ) ;
return V_63 ;
}
static int F_179 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_10 * V_164 ;
struct V_16 * V_19 ;
int V_63 ;
V_164 = F_155 ( V_4 ) ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_19 = F_156 ( F_98 ( V_11 -> V_129 ) , V_4 -> V_107 , V_4 -> V_109 ) ;
V_63 = F_58 ( V_19 ) ;
if ( F_33 ( V_19 ) )
goto V_221;
F_160 ( V_19 , V_4 -> V_109 ) ;
V_63 = F_152 ( V_19 , V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 , V_215 ) ;
F_75 ( V_63 < 0 ) ;
F_8 () ;
F_4 ( & V_194 , V_164 , V_4 ) ;
return 0 ;
V_221:
F_8 () ;
F_43 ( V_164 ) ;
return V_63 ;
}
static int F_180 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_10 * V_164 ;
struct V_16 * V_19 ;
int V_63 ;
V_164 = F_155 ( V_4 ) ;
if ( ! V_164 )
return - V_89 ;
F_13 () ;
V_19 = F_156 ( F_98 ( V_11 -> V_129 ) , V_4 -> V_107 , V_4 -> V_109 ) ;
if ( F_33 ( V_19 ) ) {
V_63 = F_58 ( V_19 ) ;
goto V_221;
}
V_63 = F_152 ( V_19 , V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 , V_215 ) ;
F_75 ( V_63 < 0 ) ;
F_16 () ;
return F_140 ( V_164 , V_4 ) ;
V_221:
F_16 () ;
F_43 ( V_164 ) ;
return V_63 ;
}
static int F_181 ( struct V_10 * V_11 , struct V_181 * V_182 )
{
struct V_200 * V_200 = F_170 ( F_98 ( V_11 -> V_129 ) , V_216 ) ;
struct V_16 * V_19 ;
int V_223 = V_182 -> args [ 0 ] ;
int V_134 = 0 ;
F_13 () ;
F_182 (dp, &ovs_net->dps, list_node) {
if ( V_134 >= V_223 &&
F_152 ( V_19 , V_11 , F_150 ( V_182 -> V_11 ) . V_54 ,
V_182 -> V_183 -> V_188 , V_189 ,
V_215 ) < 0 )
break;
V_134 ++ ;
}
F_16 () ;
V_182 -> args [ 0 ] = V_134 ;
return V_11 -> V_85 ;
}
static int F_183 ( struct V_22 * V_22 , struct V_10 * V_11 ,
T_3 V_54 , T_3 V_142 , T_3 V_59 , T_5 V_51 )
{
struct V_80 * V_80 ;
struct V_224 V_225 ;
int V_63 ;
V_80 = F_72 ( V_11 , V_54 , V_142 , & V_226 ,
V_59 , V_51 ) ;
if ( ! V_80 )
return - V_147 ;
V_80 -> V_18 = F_19 ( V_22 -> V_19 ) ;
if ( F_154 ( V_11 , V_227 , V_22 -> V_33 ) ||
F_154 ( V_11 , V_228 , V_22 -> V_24 -> type ) ||
F_153 ( V_11 , V_229 ,
V_22 -> V_24 -> V_25 ( V_22 ) ) )
goto V_149;
F_184 ( V_22 , & V_225 ) ;
if ( F_114 ( V_11 , V_230 , sizeof( struct V_224 ) ,
& V_225 ) )
goto V_149;
if ( F_185 ( V_22 , V_11 ) )
goto V_149;
V_63 = F_186 ( V_22 , V_11 ) ;
if ( V_63 == - V_147 )
goto error;
return F_119 ( V_11 , V_80 ) ;
V_149:
V_63 = - V_147 ;
error:
F_120 ( V_11 , V_80 ) ;
return V_63 ;
}
static struct V_10 * F_187 ( void )
{
return F_188 ( V_231 , V_13 ) ;
}
struct V_10 * F_189 ( struct V_22 * V_22 , T_3 V_54 ,
T_3 V_142 , T_5 V_51 )
{
struct V_10 * V_11 ;
int V_160 ;
V_11 = F_188 ( V_231 , V_88 ) ;
if ( ! V_11 )
return F_122 ( - V_89 ) ;
V_160 = F_183 ( V_22 , V_11 , V_54 , V_142 , 0 , V_51 ) ;
F_75 ( V_160 < 0 ) ;
return V_11 ;
}
static struct V_22 * F_190 ( struct V_17 * V_17 ,
struct V_80 * V_80 ,
struct V_77 * V_108 [ V_232 + 1 ] )
{
struct V_16 * V_19 ;
struct V_22 * V_22 ;
if ( V_108 [ V_229 ] ) {
V_22 = F_157 ( V_17 , F_78 ( V_108 [ V_229 ] ) ) ;
if ( ! V_22 )
return F_122 ( - V_87 ) ;
if ( V_80 -> V_18 &&
V_80 -> V_18 != F_19 ( V_22 -> V_19 ) )
return F_122 ( - V_87 ) ;
return V_22 ;
} else if ( V_108 [ V_227 ] ) {
T_3 V_33 = F_161 ( V_108 [ V_227 ] ) ;
if ( V_33 >= V_233 )
return F_122 ( - V_93 ) ;
V_19 = F_12 ( V_17 , V_80 -> V_18 ) ;
if ( ! V_19 )
return F_122 ( - V_87 ) ;
V_22 = F_18 ( V_19 , V_33 ) ;
if ( ! V_22 )
return F_122 ( - V_87 ) ;
return V_22 ;
} else
return F_122 ( - V_115 ) ;
}
static int F_191 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_80 * V_80 = V_4 -> V_107 ;
struct V_36 V_37 ;
struct V_10 * V_164 ;
struct V_22 * V_22 ;
struct V_16 * V_19 ;
T_3 V_33 ;
int V_63 ;
if ( ! V_108 [ V_229 ] || ! V_108 [ V_228 ] ||
! V_108 [ V_234 ] )
return - V_115 ;
V_33 = V_108 [ V_227 ]
? F_161 ( V_108 [ V_227 ] ) : 0 ;
if ( V_33 >= V_233 )
return - V_93 ;
V_164 = F_187 () ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_19 = F_12 ( F_98 ( V_11 -> V_129 ) , V_80 -> V_18 ) ;
V_63 = - V_87 ;
if ( ! V_19 )
goto V_235;
if ( V_33 ) {
V_22 = F_176 ( V_19 , V_33 ) ;
V_63 = - V_210 ;
if ( V_22 )
goto V_235;
} else {
for ( V_33 = 1 ; ; V_33 ++ ) {
if ( V_33 >= V_233 ) {
V_63 = - V_93 ;
goto V_235;
}
V_22 = F_176 ( V_19 , V_33 ) ;
if ( ! V_22 )
break;
}
}
V_37 . V_206 = F_78 ( V_108 [ V_229 ] ) ;
V_37 . type = F_161 ( V_108 [ V_228 ] ) ;
V_37 . V_208 = V_108 [ V_236 ] ;
V_37 . V_19 = V_19 ;
V_37 . V_33 = V_33 ;
V_37 . V_209 = V_108 [ V_234 ] ;
V_22 = F_31 ( & V_37 ) ;
V_63 = F_58 ( V_22 ) ;
if ( F_33 ( V_22 ) )
goto V_235;
V_63 = F_183 ( V_22 , V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 , V_237 ) ;
F_75 ( V_63 < 0 ) ;
F_8 () ;
F_4 ( & V_226 , V_164 , V_4 ) ;
return 0 ;
V_235:
F_8 () ;
F_43 ( V_164 ) ;
return V_63 ;
}
static int F_192 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_10 * V_164 ;
struct V_22 * V_22 ;
int V_63 ;
V_164 = F_187 () ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_22 = F_190 ( F_98 ( V_11 -> V_129 ) , V_4 -> V_107 , V_108 ) ;
V_63 = F_58 ( V_22 ) ;
if ( F_33 ( V_22 ) )
goto V_235;
if ( V_108 [ V_228 ] &&
F_161 ( V_108 [ V_228 ] ) != V_22 -> V_24 -> type ) {
V_63 = - V_115 ;
goto V_235;
}
if ( V_108 [ V_236 ] ) {
V_63 = F_193 ( V_22 , V_108 [ V_236 ] ) ;
if ( V_63 )
goto V_235;
}
if ( V_108 [ V_234 ] ) {
struct V_77 * V_238 = V_108 [ V_234 ] ;
V_63 = F_194 ( V_22 , V_238 ) ;
if ( V_63 )
goto V_235;
}
V_63 = F_183 ( V_22 , V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 , V_237 ) ;
F_75 ( V_63 < 0 ) ;
F_8 () ;
F_4 ( & V_226 , V_164 , V_4 ) ;
return 0 ;
V_235:
F_8 () ;
F_43 ( V_164 ) ;
return V_63 ;
}
static int F_195 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_10 * V_164 ;
struct V_22 * V_22 ;
int V_63 ;
V_164 = F_187 () ;
if ( ! V_164 )
return - V_89 ;
F_6 () ;
V_22 = F_190 ( F_98 ( V_11 -> V_129 ) , V_4 -> V_107 , V_108 ) ;
V_63 = F_58 ( V_22 ) ;
if ( F_33 ( V_22 ) )
goto V_235;
if ( V_22 -> V_33 == V_23 ) {
V_63 = - V_115 ;
goto V_235;
}
V_63 = F_183 ( V_22 , V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 , V_239 ) ;
F_75 ( V_63 < 0 ) ;
F_35 ( V_22 ) ;
F_8 () ;
F_4 ( & V_226 , V_164 , V_4 ) ;
return 0 ;
V_235:
F_8 () ;
F_43 ( V_164 ) ;
return V_63 ;
}
static int F_196 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_77 * * V_108 = V_4 -> V_109 ;
struct V_80 * V_80 = V_4 -> V_107 ;
struct V_10 * V_164 ;
struct V_22 * V_22 ;
int V_63 ;
V_164 = F_187 () ;
if ( ! V_164 )
return - V_89 ;
F_13 () ;
V_22 = F_190 ( F_98 ( V_11 -> V_129 ) , V_80 , V_108 ) ;
V_63 = F_58 ( V_22 ) ;
if ( F_33 ( V_22 ) )
goto V_235;
V_63 = F_183 ( V_22 , V_164 , V_4 -> V_12 ,
V_4 -> V_161 , 0 , V_237 ) ;
F_75 ( V_63 < 0 ) ;
F_16 () ;
return F_140 ( V_164 , V_4 ) ;
V_235:
F_16 () ;
F_43 ( V_164 ) ;
return V_63 ;
}
static int F_197 ( struct V_10 * V_11 , struct V_181 * V_182 )
{
struct V_80 * V_80 = F_146 ( F_147 ( V_182 -> V_183 ) ) ;
struct V_16 * V_19 ;
int V_186 = V_182 -> args [ 0 ] , V_223 = V_182 -> args [ 1 ] ;
int V_134 , V_240 = 0 ;
F_13 () ;
V_19 = F_12 ( F_98 ( V_11 -> V_129 ) , V_80 -> V_18 ) ;
if ( ! V_19 ) {
F_16 () ;
return - V_87 ;
}
for ( V_134 = V_186 ; V_134 < V_34 ; V_134 ++ ) {
struct V_22 * V_22 ;
V_240 = 0 ;
F_30 (vport, &dp->ports[i], dp_hash_node) {
if ( V_240 >= V_223 &&
F_183 ( V_22 , V_11 ,
F_150 ( V_182 -> V_11 ) . V_54 ,
V_182 -> V_183 -> V_188 ,
V_189 ,
V_237 ) < 0 )
goto V_56;
V_240 ++ ;
}
V_223 = 0 ;
}
V_56:
F_16 () ;
V_182 -> args [ 0 ] = V_134 ;
V_182 -> args [ 1 ] = V_240 ;
return V_11 -> V_85 ;
}
static void F_198 ( int V_241 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_241 ; V_134 ++ )
F_199 ( V_242 [ V_134 ] ) ;
}
static int F_200 ( void )
{
int V_63 ;
int V_134 ;
for ( V_134 = 0 ; V_134 < F_201 ( V_242 ) ; V_134 ++ ) {
V_63 = F_202 ( V_242 [ V_134 ] ) ;
if ( V_63 )
goto error;
}
return 0 ;
error:
F_198 ( V_134 ) ;
return V_63 ;
}
static int T_7 F_203 ( struct V_17 * V_17 )
{
struct V_200 * V_200 = F_170 ( V_17 , V_216 ) ;
F_204 ( & V_200 -> V_218 ) ;
F_205 ( & V_200 -> V_243 , V_244 ) ;
return 0 ;
}
static void T_8 F_206 ( struct V_17 * V_17 )
{
struct V_16 * V_19 , * V_245 ;
struct V_200 * V_200 = F_170 ( V_17 , V_216 ) ;
F_6 () ;
F_207 (dp, dp_next, &ovs_net->dps, list_node)
F_173 ( V_19 ) ;
F_8 () ;
F_208 ( & V_200 -> V_243 ) ;
}
static int T_9 F_209 ( void )
{
int V_63 ;
F_210 ( sizeof( struct V_246 ) > F_211 ( struct V_10 , V_182 ) ) ;
F_212 ( L_4 ) ;
V_63 = F_213 () ;
if ( V_63 )
goto error;
V_63 = F_214 () ;
if ( V_63 )
goto V_247;
V_63 = F_215 () ;
if ( V_63 )
goto V_248;
V_63 = F_216 ( & V_249 ) ;
if ( V_63 )
goto V_250;
V_63 = F_217 ( & V_251 ) ;
if ( V_63 )
goto V_252;
V_63 = F_200 () ;
if ( V_63 < 0 )
goto V_253;
return 0 ;
V_253:
F_218 ( & V_251 ) ;
V_252:
F_219 ( & V_249 ) ;
V_250:
F_220 () ;
V_248:
F_221 () ;
V_247:
F_222 () ;
error:
return V_63 ;
}
static void F_223 ( void )
{
F_198 ( F_201 ( V_242 ) ) ;
F_218 ( & V_251 ) ;
F_219 ( & V_249 ) ;
F_224 () ;
F_220 () ;
F_221 () ;
F_222 () ;
}
