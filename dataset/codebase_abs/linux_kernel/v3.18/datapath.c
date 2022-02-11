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
const char * F_17 ( const struct V_16 * V_19 )
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
void F_39 ( struct V_10 * V_11 , struct V_40 * V_41 )
{
const struct V_22 * V_39 = F_40 ( V_11 ) -> V_42 ;
struct V_16 * V_19 = V_39 -> V_19 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
T_2 * V_47 ;
T_3 V_48 ;
V_46 = F_41 ( V_19 -> V_30 ) ;
V_44 = F_42 ( & V_19 -> V_49 , V_41 , & V_48 ) ;
if ( F_43 ( ! V_44 ) ) {
struct V_50 V_51 ;
int error ;
V_51 . V_52 = V_53 ;
V_51 . V_41 = V_41 ;
V_51 . V_54 = NULL ;
V_51 . V_55 = F_44 ( V_39 , V_11 ) ;
error = F_45 ( V_19 , V_11 , & V_51 ) ;
if ( F_43 ( error ) )
F_46 ( V_11 ) ;
else
F_47 ( V_11 ) ;
V_47 = & V_46 -> V_56 ;
goto V_57;
}
F_40 ( V_11 ) -> V_44 = V_44 ;
F_48 ( F_40 ( V_11 ) -> V_44 , V_41 -> V_58 . V_59 , V_11 ) ;
F_49 ( V_19 , V_11 , V_41 ) ;
V_47 = & V_46 -> V_60 ;
V_57:
F_50 ( & V_46 -> V_61 ) ;
( * V_47 ) ++ ;
V_46 -> V_48 += V_48 ;
F_51 ( & V_46 -> V_61 ) ;
}
int F_45 ( struct V_16 * V_19 , struct V_10 * V_11 ,
const struct V_50 * V_62 )
{
struct V_45 * V_46 ;
int V_63 ;
if ( V_62 -> V_55 == 0 ) {
V_63 = - V_64 ;
goto V_63;
}
if ( ! F_52 ( V_11 ) )
V_63 = F_53 ( V_19 , V_11 , V_62 ) ;
else
V_63 = F_54 ( V_19 , V_11 , V_62 ) ;
if ( V_63 )
goto V_63;
return 0 ;
V_63:
V_46 = F_41 ( V_19 -> V_30 ) ;
F_50 ( & V_46 -> V_61 ) ;
V_46 -> V_65 ++ ;
F_51 ( & V_46 -> V_61 ) ;
return V_63 ;
}
static int F_54 ( struct V_16 * V_19 , struct V_10 * V_11 ,
const struct V_50 * V_62 )
{
unsigned short V_66 = F_55 ( V_11 ) -> V_66 ;
struct V_50 V_67 ;
struct V_40 V_68 ;
struct V_10 * V_69 , * V_70 ;
int V_63 ;
V_69 = F_56 ( V_11 , V_71 , false ) ;
if ( F_33 ( V_69 ) )
return F_57 ( V_69 ) ;
if ( V_69 == NULL )
return - V_72 ;
V_11 = V_69 ;
do {
V_63 = F_53 ( V_19 , V_11 , V_62 ) ;
if ( V_63 )
break;
if ( V_11 == V_69 && V_66 & V_73 ) {
V_68 = * V_62 -> V_41 ;
V_68 . V_74 . V_75 = V_76 ;
V_67 = * V_62 ;
V_67 . V_41 = & V_68 ;
V_62 = & V_67 ;
}
} while ( ( V_11 = V_11 -> V_77 ) );
V_11 = V_69 ;
do {
V_70 = V_11 -> V_77 ;
if ( V_63 )
F_46 ( V_11 ) ;
else
F_47 ( V_11 ) ;
} while ( ( V_11 = V_70 ) );
return V_63 ;
}
static T_4 F_58 ( void )
{
return F_59 ( 4 )
+ F_59 ( 0 )
+ F_59 ( 8 )
+ F_59 ( 4 )
+ F_59 ( 4 )
+ F_59 ( 1 )
+ F_59 ( 1 )
+ F_59 ( 0 )
+ F_59 ( 0 )
+ F_59 ( 0 )
+ F_59 ( 256 )
+ F_59 ( 4 )
+ F_59 ( 4 )
+ F_59 ( 12 )
+ F_59 ( 2 )
+ F_59 ( 4 )
+ F_59 ( 0 )
+ F_59 ( 2 )
+ F_59 ( 40 )
+ F_59 ( 2 )
+ F_59 ( 28 ) ;
}
static T_4 F_60 ( const struct V_78 * V_54 ,
unsigned int V_79 )
{
T_4 V_80 = F_61 ( sizeof( struct V_81 ) )
+ F_59 ( V_79 )
+ F_59 ( F_58 () ) ;
if ( V_54 )
V_80 += F_62 ( V_54 -> V_82 ) ;
return V_80 ;
}
static int F_53 ( struct V_16 * V_19 , struct V_10 * V_11 ,
const struct V_50 * V_62 )
{
struct V_81 * V_51 ;
struct V_10 * V_70 = NULL ;
struct V_10 * V_83 = NULL ;
struct V_78 * V_84 ;
struct V_3 V_4 = {
. V_85 = F_26 ( V_19 ) -> V_9 ,
. V_12 = V_62 -> V_55 ,
} ;
T_4 V_86 ;
unsigned int V_87 ;
int V_63 , V_18 ;
V_18 = F_19 ( V_19 ) ;
if ( ! V_18 )
return - V_88 ;
if ( F_63 ( V_11 ) ) {
V_70 = F_64 ( V_11 , V_89 ) ;
if ( ! V_70 )
return - V_90 ;
V_70 = F_65 ( V_70 , V_70 -> V_91 , F_66 ( V_70 ) ) ;
if ( ! V_70 )
return - V_90 ;
V_70 -> V_92 = 0 ;
V_11 = V_70 ;
}
if ( F_67 ( V_11 -> V_86 ) > V_93 ) {
V_63 = - V_94 ;
goto V_57;
}
if ( V_11 -> V_95 == V_96 &&
( V_63 = F_68 ( V_11 ) ) )
goto V_57;
if ( V_19 -> V_97 & V_98 )
V_87 = F_69 ( V_11 ) ;
else
V_87 = V_11 -> V_86 ;
V_86 = F_60 ( V_62 -> V_54 , V_87 ) ;
V_83 = F_70 ( V_86 , & V_4 , V_89 ) ;
if ( ! V_83 ) {
V_63 = - V_90 ;
goto V_57;
}
V_51 = F_71 ( V_83 , 0 , 0 , & V_99 ,
0 , V_62 -> V_52 ) ;
V_51 -> V_18 = V_18 ;
V_84 = F_72 ( V_83 , V_100 ) ;
V_63 = F_73 ( V_62 -> V_41 , V_62 -> V_41 , V_83 ) ;
F_74 ( V_63 ) ;
F_75 ( V_83 , V_84 ) ;
if ( V_62 -> V_54 )
F_76 ( V_83 , V_101 ,
V_82 ( V_62 -> V_54 ) ,
F_77 ( V_62 -> V_54 ) ) ;
if ( ! ( V_84 = F_78 ( V_83 , V_102 , 0 ) ) ) {
V_63 = - V_103 ;
goto V_57;
}
V_84 -> V_82 = F_67 ( V_11 -> V_86 ) ;
V_63 = F_79 ( V_83 , V_11 , V_11 -> V_86 , V_87 ) ;
if ( V_63 )
goto V_57;
if ( ! ( V_19 -> V_97 & V_98 ) ) {
T_4 V_104 = F_62 ( V_83 -> V_86 ) - V_83 -> V_86 ;
if ( V_104 > 0 )
memset ( F_80 ( V_83 , V_104 ) , 0 , V_104 ) ;
}
( (struct V_105 * ) V_83 -> V_106 ) -> V_107 = V_83 -> V_86 ;
V_63 = F_81 ( F_26 ( V_19 ) , V_83 , V_62 -> V_55 ) ;
V_83 = NULL ;
V_57:
if ( V_63 )
F_82 ( V_11 ) ;
F_46 ( V_83 ) ;
F_46 ( V_70 ) ;
return V_63 ;
}
static int F_83 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_81 * V_81 = V_4 -> V_108 ;
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_111 * V_112 ;
struct V_10 * V_113 ;
struct V_43 * V_44 ;
struct V_16 * V_19 ;
struct V_114 * V_115 ;
struct V_22 * V_42 ;
int V_86 ;
int V_63 ;
V_63 = - V_72 ;
if ( ! V_109 [ V_102 ] || ! V_109 [ V_100 ] ||
! V_109 [ V_116 ] )
goto V_63;
V_86 = V_82 ( V_109 [ V_102 ] ) ;
V_113 = F_84 ( V_117 + V_86 , V_13 ) ;
V_63 = - V_90 ;
if ( ! V_113 )
goto V_63;
F_85 ( V_113 , V_117 ) ;
F_86 ( F_87 ( V_113 , V_86 ) , V_109 [ V_102 ] , V_86 ) ;
F_88 ( V_113 ) ;
V_115 = F_89 ( V_113 ) ;
if ( F_90 ( V_115 -> V_118 ) >= V_119 )
V_113 -> V_120 = V_115 -> V_118 ;
else
V_113 -> V_120 = F_91 ( V_121 ) ;
V_44 = F_92 () ;
V_63 = F_57 ( V_44 ) ;
if ( F_33 ( V_44 ) )
goto V_122;
V_63 = F_93 ( V_109 [ V_100 ] , V_113 ,
& V_44 -> V_41 ) ;
if ( V_63 )
goto V_123;
V_112 = F_94 ( V_82 ( V_109 [ V_116 ] ) ) ;
V_63 = F_57 ( V_112 ) ;
if ( F_33 ( V_112 ) )
goto V_123;
V_63 = F_95 ( V_109 [ V_116 ] ,
& V_44 -> V_41 , 0 , & V_112 ) ;
if ( V_63 )
goto V_123;
F_96 ( V_44 -> V_124 , V_112 ) ;
F_40 ( V_113 ) -> V_125 = NULL ;
F_40 ( V_113 ) -> V_44 = V_44 ;
V_113 -> V_126 = V_44 -> V_41 . V_127 . V_126 ;
V_113 -> V_128 = V_44 -> V_41 . V_127 . V_129 ;
F_13 () ;
V_19 = F_12 ( F_97 ( V_11 -> V_130 ) , V_81 -> V_18 ) ;
V_63 = - V_88 ;
if ( ! V_19 )
goto V_131;
V_42 = F_20 ( V_19 , V_44 -> V_41 . V_127 . V_132 ) ;
if ( ! V_42 )
V_42 = F_20 ( V_19 , V_23 ) ;
if ( ! V_42 )
goto V_131;
F_40 ( V_113 ) -> V_42 = V_42 ;
F_98 () ;
V_63 = F_49 ( V_19 , V_113 , & V_44 -> V_41 ) ;
F_99 () ;
F_16 () ;
F_100 ( V_44 , false ) ;
return V_63 ;
V_131:
F_16 () ;
V_123:
F_100 ( V_44 , false ) ;
V_122:
F_46 ( V_113 ) ;
V_63:
return V_63 ;
}
static void F_101 ( struct V_16 * V_19 , struct V_133 * V_46 ,
struct V_134 * V_135 )
{
int V_136 ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
V_46 -> V_137 = F_102 ( & V_19 -> V_49 ) ;
V_135 -> V_138 = F_103 ( & V_19 -> V_49 ) ;
V_46 -> V_60 = V_46 -> V_56 = V_46 -> V_65 = 0 ;
F_104 (i) {
const struct V_45 * V_139 ;
struct V_45 V_140 ;
unsigned int V_141 ;
V_139 = F_105 ( V_19 -> V_30 , V_136 ) ;
do {
V_141 = F_106 ( & V_139 -> V_61 ) ;
V_140 = * V_139 ;
} while ( F_107 ( & V_139 -> V_61 , V_141 ) );
V_46 -> V_60 += V_140 . V_60 ;
V_46 -> V_56 += V_140 . V_56 ;
V_46 -> V_65 += V_140 . V_65 ;
V_135 -> V_48 += V_140 . V_48 ;
}
}
static T_4 F_108 ( const struct V_111 * V_112 )
{
return F_61 ( sizeof( struct V_81 ) )
+ F_59 ( F_58 () )
+ F_59 ( F_58 () )
+ F_59 ( sizeof( struct V_142 ) )
+ F_59 ( 1 )
+ F_59 ( 8 )
+ F_59 ( V_112 -> V_143 ) ;
}
static int F_109 ( const struct V_43 * V_44 , int V_18 ,
struct V_10 * V_11 , T_3 V_55 ,
T_3 V_144 , T_3 V_59 , T_5 V_52 )
{
const int V_145 = V_11 -> V_86 ;
struct V_78 * V_141 ;
struct V_142 V_46 ;
T_6 V_146 ;
unsigned long V_147 ;
struct V_81 * V_81 ;
struct V_78 * V_84 ;
int V_63 ;
V_81 = F_71 ( V_11 , V_55 , V_144 , & V_148 , V_59 , V_52 ) ;
if ( ! V_81 )
return - V_149 ;
V_81 -> V_18 = V_18 ;
V_84 = F_72 ( V_11 , V_150 ) ;
if ( ! V_84 )
goto V_151;
V_63 = F_73 ( & V_44 -> V_152 , & V_44 -> V_152 , V_11 ) ;
if ( V_63 )
goto error;
F_75 ( V_11 , V_84 ) ;
V_84 = F_72 ( V_11 , V_153 ) ;
if ( ! V_84 )
goto V_151;
V_63 = F_73 ( & V_44 -> V_41 , & V_44 -> V_154 -> V_41 , V_11 ) ;
if ( V_63 )
goto error;
F_75 ( V_11 , V_84 ) ;
F_110 ( V_44 , & V_46 , & V_147 , & V_146 ) ;
if ( V_147 &&
F_111 ( V_11 , V_155 , F_112 ( V_147 ) ) )
goto V_151;
if ( V_46 . V_156 &&
F_113 ( V_11 , V_157 , sizeof( struct V_142 ) , & V_46 ) )
goto V_151;
if ( ( T_5 ) F_90 ( V_146 ) &&
F_114 ( V_11 , V_158 , ( T_5 ) F_90 ( V_146 ) ) )
goto V_151;
V_141 = F_72 ( V_11 , V_159 ) ;
if ( V_141 ) {
const struct V_111 * V_124 ;
V_124 = F_115 ( V_44 -> V_124 ) ;
V_63 = F_116 ( V_124 -> V_160 ,
V_124 -> V_143 , V_11 ) ;
if ( ! V_63 )
F_75 ( V_11 , V_141 ) ;
else {
if ( V_145 )
goto error;
F_117 ( V_11 , V_141 ) ;
}
} else if ( V_145 )
goto V_151;
return F_118 ( V_11 , V_81 ) ;
V_151:
V_63 = - V_149 ;
error:
F_119 ( V_11 , V_81 ) ;
return V_63 ;
}
static struct V_10 * F_120 ( const struct V_111 * V_112 ,
struct V_3 * V_4 ,
bool V_161 )
{
struct V_10 * V_11 ;
if ( ! V_161 && ! F_1 ( & V_148 , V_4 , 0 ) )
return NULL ;
V_11 = F_70 ( F_108 ( V_112 ) , V_4 , V_13 ) ;
if ( ! V_11 )
return F_121 ( - V_90 ) ;
return V_11 ;
}
static struct V_10 * F_122 ( const struct V_43 * V_44 ,
int V_18 ,
struct V_3 * V_4 , T_5 V_52 ,
bool V_161 )
{
struct V_10 * V_11 ;
int V_162 ;
V_11 = F_120 ( F_123 ( V_44 -> V_124 ) , V_4 ,
V_161 ) ;
if ( F_124 ( V_11 ) )
return V_11 ;
V_162 = F_109 ( V_44 , V_18 , V_11 ,
V_4 -> V_12 , V_4 -> V_163 , 0 ,
V_52 ) ;
F_74 ( V_162 < 0 ) ;
return V_11 ;
}
static int F_125 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_81 * V_81 = V_4 -> V_108 ;
struct V_43 * V_44 , * V_164 ;
struct V_165 V_154 ;
struct V_10 * V_166 ;
struct V_16 * V_19 ;
struct V_111 * V_112 ;
struct V_167 V_168 ;
int error ;
error = - V_72 ;
if ( ! V_109 [ V_150 ] )
goto error;
if ( ! V_109 [ V_159 ] )
goto error;
V_164 = F_92 () ;
if ( F_33 ( V_164 ) ) {
error = F_57 ( V_164 ) ;
goto error;
}
F_126 ( & V_168 , & V_164 -> V_152 , & V_154 ) ;
error = F_127 ( & V_168 ,
V_109 [ V_150 ] , V_109 [ V_153 ] ) ;
if ( error )
goto V_169;
F_128 ( & V_164 -> V_41 , & V_164 -> V_152 , & V_154 ) ;
V_112 = F_94 ( V_82 ( V_109 [ V_159 ] ) ) ;
error = F_57 ( V_112 ) ;
if ( F_33 ( V_112 ) )
goto V_169;
error = F_95 ( V_109 [ V_159 ] , & V_164 -> V_41 ,
0 , & V_112 ) ;
if ( error ) {
F_129 ( L_1 ) ;
goto V_170;
}
V_166 = F_120 ( V_112 , V_4 , false ) ;
if ( F_33 ( V_166 ) ) {
error = F_57 ( V_166 ) ;
goto V_170;
}
F_6 () ;
V_19 = F_12 ( F_97 ( V_11 -> V_130 ) , V_81 -> V_18 ) ;
if ( F_43 ( ! V_19 ) ) {
error = - V_88 ;
goto V_171;
}
V_44 = F_130 ( & V_19 -> V_49 , & V_164 -> V_152 ) ;
if ( F_131 ( ! V_44 ) ) {
F_96 ( V_164 -> V_124 , V_112 ) ;
error = F_132 ( & V_19 -> V_49 , V_164 , & V_154 ) ;
if ( F_43 ( error ) ) {
V_112 = NULL ;
goto V_171;
}
if ( F_43 ( V_166 ) ) {
error = F_109 ( V_164 ,
V_81 -> V_18 ,
V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 ,
V_172 ) ;
F_74 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_111 * V_173 ;
if ( F_43 ( V_4 -> V_6 -> V_7 & ( V_174
| V_175 ) ) ) {
error = - V_176 ;
goto V_171;
}
if ( F_43 ( ! F_133 ( V_44 , & V_168 ) ) ) {
V_44 = F_134 ( & V_19 -> V_49 , & V_168 ) ;
if ( ! V_44 ) {
error = - V_177 ;
goto V_171;
}
}
V_173 = F_123 ( V_44 -> V_124 ) ;
F_96 ( V_44 -> V_124 , V_112 ) ;
if ( F_43 ( V_166 ) ) {
error = F_109 ( V_44 ,
V_81 -> V_18 ,
V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 ,
V_172 ) ;
F_74 ( error < 0 ) ;
}
F_8 () ;
F_135 ( V_173 ) ;
F_100 ( V_164 , false ) ;
}
if ( V_166 )
F_4 ( & V_148 , V_166 , V_4 ) ;
return 0 ;
V_171:
F_8 () ;
F_46 ( V_166 ) ;
V_170:
F_27 ( V_112 ) ;
V_169:
F_100 ( V_164 , false ) ;
error:
return error ;
}
static struct V_111 * F_136 ( const struct V_78 * V_109 ,
const struct V_40 * V_41 ,
const struct V_165 * V_154 )
{
struct V_111 * V_112 ;
struct V_40 V_178 ;
int error ;
V_112 = F_94 ( V_82 ( V_109 ) ) ;
if ( F_33 ( V_112 ) )
return V_112 ;
F_128 ( & V_178 , V_41 , V_154 ) ;
error = F_95 ( V_109 , & V_178 , 0 , & V_112 ) ;
if ( error ) {
F_129 ( L_1 ) ;
F_27 ( V_112 ) ;
return F_121 ( error ) ;
}
return V_112 ;
}
static int F_137 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_81 * V_81 = V_4 -> V_108 ;
struct V_40 V_41 ;
struct V_43 * V_44 ;
struct V_165 V_154 ;
struct V_10 * V_166 = NULL ;
struct V_16 * V_19 ;
struct V_111 * V_173 = NULL , * V_112 = NULL ;
struct V_167 V_168 ;
int error ;
error = - V_72 ;
if ( ! V_109 [ V_150 ] )
goto error;
F_126 ( & V_168 , & V_41 , & V_154 ) ;
error = F_127 ( & V_168 ,
V_109 [ V_150 ] , V_109 [ V_153 ] ) ;
if ( error )
goto error;
if ( V_109 [ V_159 ] ) {
V_112 = F_136 ( V_109 [ V_159 ] , & V_41 , & V_154 ) ;
if ( F_33 ( V_112 ) ) {
error = F_57 ( V_112 ) ;
goto error;
}
}
if ( V_112 ) {
V_166 = F_120 ( V_112 , V_4 , false ) ;
if ( F_33 ( V_166 ) ) {
error = F_57 ( V_166 ) ;
goto V_170;
}
}
F_6 () ;
V_19 = F_12 ( F_97 ( V_11 -> V_130 ) , V_81 -> V_18 ) ;
if ( F_43 ( ! V_19 ) ) {
error = - V_88 ;
goto V_171;
}
V_44 = F_134 ( & V_19 -> V_49 , & V_168 ) ;
if ( F_43 ( ! V_44 ) ) {
error = - V_177 ;
goto V_171;
}
if ( F_131 ( V_112 ) ) {
V_173 = F_123 ( V_44 -> V_124 ) ;
F_96 ( V_44 -> V_124 , V_112 ) ;
if ( F_43 ( V_166 ) ) {
error = F_109 ( V_44 ,
V_81 -> V_18 ,
V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 ,
V_172 ) ;
F_74 ( error < 0 ) ;
}
} else {
V_166 = F_122 ( V_44 , V_81 -> V_18 ,
V_4 , V_172 , false ) ;
if ( F_43 ( F_33 ( V_166 ) ) ) {
error = F_57 ( V_166 ) ;
goto V_171;
}
}
if ( V_109 [ V_179 ] )
F_138 ( V_44 ) ;
F_8 () ;
if ( V_166 )
F_4 ( & V_148 , V_166 , V_4 ) ;
if ( V_173 )
F_135 ( V_173 ) ;
return 0 ;
V_171:
F_8 () ;
F_46 ( V_166 ) ;
V_170:
F_27 ( V_112 ) ;
error:
return error ;
}
static int F_139 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_81 * V_81 = V_4 -> V_108 ;
struct V_40 V_41 ;
struct V_10 * V_166 ;
struct V_43 * V_44 ;
struct V_16 * V_19 ;
struct V_167 V_168 ;
int V_63 ;
if ( ! V_109 [ V_150 ] ) {
F_129 ( L_2 ) ;
return - V_72 ;
}
F_126 ( & V_168 , & V_41 , NULL ) ;
V_63 = F_127 ( & V_168 , V_109 [ V_150 ] , NULL ) ;
if ( V_63 )
return V_63 ;
F_6 () ;
V_19 = F_12 ( F_97 ( V_11 -> V_130 ) , V_81 -> V_18 ) ;
if ( ! V_19 ) {
V_63 = - V_88 ;
goto V_180;
}
V_44 = F_134 ( & V_19 -> V_49 , & V_168 ) ;
if ( ! V_44 ) {
V_63 = - V_177 ;
goto V_180;
}
V_166 = F_122 ( V_44 , V_81 -> V_18 , V_4 ,
V_172 , true ) ;
if ( F_33 ( V_166 ) ) {
V_63 = F_57 ( V_166 ) ;
goto V_180;
}
F_8 () ;
return F_140 ( V_166 , V_4 ) ;
V_180:
F_8 () ;
return V_63 ;
}
static int F_141 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_81 * V_81 = V_4 -> V_108 ;
struct V_40 V_41 ;
struct V_10 * V_166 ;
struct V_43 * V_44 ;
struct V_16 * V_19 ;
struct V_167 V_168 ;
int V_63 ;
if ( F_131 ( V_109 [ V_150 ] ) ) {
F_126 ( & V_168 , & V_41 , NULL ) ;
V_63 = F_127 ( & V_168 , V_109 [ V_150 ] , NULL ) ;
if ( F_43 ( V_63 ) )
return V_63 ;
}
F_6 () ;
V_19 = F_12 ( F_97 ( V_11 -> V_130 ) , V_81 -> V_18 ) ;
if ( F_43 ( ! V_19 ) ) {
V_63 = - V_88 ;
goto V_180;
}
if ( F_43 ( ! V_109 [ V_150 ] ) ) {
V_63 = F_142 ( & V_19 -> V_49 ) ;
goto V_180;
}
V_44 = F_134 ( & V_19 -> V_49 , & V_168 ) ;
if ( F_43 ( ! V_44 ) ) {
V_63 = - V_177 ;
goto V_180;
}
F_143 ( & V_19 -> V_49 , V_44 ) ;
F_8 () ;
V_166 = F_120 ( ( const struct V_111 V_181 * ) V_44 -> V_124 ,
V_4 , false ) ;
if ( F_131 ( V_166 ) ) {
if ( F_131 ( ! F_33 ( V_166 ) ) ) {
F_13 () ;
V_63 = F_109 ( V_44 , V_81 -> V_18 ,
V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 ,
V_182 ) ;
F_16 () ;
F_74 ( V_63 < 0 ) ;
F_4 ( & V_148 , V_166 , V_4 ) ;
} else {
F_144 ( F_97 ( V_11 -> V_130 ) -> V_9 , 0 , 0 , F_57 ( V_166 ) ) ;
}
}
F_100 ( V_44 , true ) ;
return 0 ;
V_180:
F_8 () ;
return V_63 ;
}
static int F_145 ( struct V_10 * V_11 , struct V_183 * V_184 )
{
struct V_81 * V_81 = F_146 ( F_147 ( V_184 -> V_185 ) ) ;
struct V_186 * V_187 ;
struct V_16 * V_19 ;
F_13 () ;
V_19 = F_12 ( F_97 ( V_11 -> V_130 ) , V_81 -> V_18 ) ;
if ( ! V_19 ) {
F_16 () ;
return - V_88 ;
}
V_187 = F_148 ( V_19 -> V_49 . V_187 ) ;
for (; ; ) {
struct V_43 * V_44 ;
T_3 V_188 , V_189 ;
V_188 = V_184 -> args [ 0 ] ;
V_189 = V_184 -> args [ 1 ] ;
V_44 = F_149 ( V_187 , & V_188 , & V_189 ) ;
if ( ! V_44 )
break;
if ( F_109 ( V_44 , V_81 -> V_18 , V_11 ,
F_150 ( V_184 -> V_11 ) . V_55 ,
V_184 -> V_185 -> V_190 , V_191 ,
V_172 ) < 0 )
break;
V_184 -> args [ 0 ] = V_188 ;
V_184 -> args [ 1 ] = V_189 ;
}
F_16 () ;
return V_11 -> V_86 ;
}
static T_4 F_151 ( void )
{
T_4 V_192 = F_61 ( sizeof( struct V_81 ) ) ;
V_192 += F_59 ( V_193 ) ;
V_192 += F_59 ( sizeof( struct V_133 ) ) ;
V_192 += F_59 ( sizeof( struct V_134 ) ) ;
V_192 += F_59 ( sizeof( T_3 ) ) ;
return V_192 ;
}
static int F_152 ( struct V_16 * V_19 , struct V_10 * V_11 ,
T_3 V_55 , T_3 V_144 , T_3 V_59 , T_5 V_52 )
{
struct V_81 * V_81 ;
struct V_133 V_194 ;
struct V_134 V_195 ;
int V_63 ;
V_81 = F_71 ( V_11 , V_55 , V_144 , & V_196 ,
V_59 , V_52 ) ;
if ( ! V_81 )
goto error;
V_81 -> V_18 = F_19 ( V_19 ) ;
V_63 = F_153 ( V_11 , V_197 , F_17 ( V_19 ) ) ;
if ( V_63 )
goto V_151;
F_101 ( V_19 , & V_194 , & V_195 ) ;
if ( F_113 ( V_11 , V_198 , sizeof( struct V_133 ) ,
& V_194 ) )
goto V_151;
if ( F_113 ( V_11 , V_199 ,
sizeof( struct V_134 ) ,
& V_195 ) )
goto V_151;
if ( F_154 ( V_11 , V_200 , V_19 -> V_97 ) )
goto V_151;
return F_118 ( V_11 , V_81 ) ;
V_151:
F_119 ( V_11 , V_81 ) ;
error:
return - V_149 ;
}
static struct V_10 * F_155 ( struct V_3 * V_4 )
{
return F_70 ( F_151 () , V_4 , V_13 ) ;
}
static struct V_16 * F_156 ( struct V_17 * V_17 ,
struct V_81 * V_81 ,
struct V_78 * V_109 [ V_201 + 1 ] )
{
struct V_16 * V_19 ;
if ( ! V_109 [ V_197 ] )
V_19 = F_12 ( V_17 , V_81 -> V_18 ) ;
else {
struct V_22 * V_22 ;
V_22 = F_157 ( V_17 , F_77 ( V_109 [ V_197 ] ) ) ;
V_19 = V_22 && V_22 -> V_33 == V_23 ? V_22 -> V_19 : NULL ;
}
return V_19 ? V_19 : F_121 ( - V_88 ) ;
}
static void F_158 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_16 * V_19 ;
V_19 = F_156 ( F_97 ( V_11 -> V_130 ) , V_4 -> V_108 , V_4 -> V_110 ) ;
if ( F_33 ( V_19 ) )
return;
F_159 ( V_19 -> V_97 , L_3 ) ;
V_19 -> V_97 = 0 ;
}
static void F_160 ( struct V_16 * V_19 , struct V_78 * * V_109 )
{
if ( V_109 [ V_200 ] )
V_19 -> V_97 = F_161 ( V_109 [ V_200 ] ) ;
}
static int F_162 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_36 V_37 ;
struct V_10 * V_166 ;
struct V_16 * V_19 ;
struct V_22 * V_22 ;
struct V_202 * V_202 ;
int V_63 , V_136 ;
V_63 = - V_72 ;
if ( ! V_109 [ V_197 ] || ! V_109 [ V_203 ] )
goto V_63;
V_166 = F_155 ( V_4 ) ;
if ( ! V_166 )
return - V_90 ;
V_63 = - V_90 ;
V_19 = F_163 ( sizeof( * V_19 ) , V_13 ) ;
if ( V_19 == NULL )
goto V_204;
F_164 ( V_19 , F_165 ( F_97 ( V_11 -> V_130 ) ) ) ;
V_63 = F_166 ( & V_19 -> V_49 ) ;
if ( V_63 )
goto V_205;
V_19 -> V_30 = F_167 ( struct V_45 ) ;
if ( ! V_19 -> V_30 ) {
V_63 = - V_90 ;
goto V_206;
}
V_19 -> V_31 = F_168 ( V_34 * sizeof( struct V_32 ) ,
V_13 ) ;
if ( ! V_19 -> V_31 ) {
V_63 = - V_90 ;
goto V_207;
}
for ( V_136 = 0 ; V_136 < V_34 ; V_136 ++ )
F_169 ( & V_19 -> V_31 [ V_136 ] ) ;
V_37 . V_208 = F_77 ( V_109 [ V_197 ] ) ;
V_37 . type = V_209 ;
V_37 . V_210 = NULL ;
V_37 . V_19 = V_19 ;
V_37 . V_33 = V_23 ;
V_37 . V_211 = V_109 [ V_203 ] ;
F_160 ( V_19 , V_109 ) ;
F_6 () ;
V_22 = F_31 ( & V_37 ) ;
if ( F_33 ( V_22 ) ) {
V_63 = F_57 ( V_22 ) ;
if ( V_63 == - V_212 )
V_63 = - V_176 ;
if ( V_63 == - V_176 ) {
if ( V_4 -> V_213 -> V_214 < V_215 )
F_158 ( V_11 , V_4 ) ;
}
goto V_216;
}
V_63 = F_152 ( V_19 , V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 , V_217 ) ;
F_74 ( V_63 < 0 ) ;
V_202 = F_170 ( F_26 ( V_19 ) , V_218 ) ;
F_171 ( & V_19 -> V_219 , & V_202 -> V_220 ) ;
F_8 () ;
F_4 ( & V_196 , V_166 , V_4 ) ;
return 0 ;
V_216:
F_8 () ;
F_27 ( V_19 -> V_31 ) ;
V_207:
F_24 ( V_19 -> V_30 ) ;
V_206:
F_172 ( & V_19 -> V_49 , false ) ;
V_205:
F_25 ( F_26 ( V_19 ) ) ;
F_27 ( V_19 ) ;
V_204:
F_46 ( V_166 ) ;
V_63:
return V_63 ;
}
static void F_173 ( struct V_16 * V_19 )
{
int V_136 ;
for ( V_136 = 0 ; V_136 < V_34 ; V_136 ++ ) {
struct V_22 * V_22 ;
struct V_221 * V_222 ;
F_174 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_22 -> V_33 != V_23 )
F_35 ( V_22 ) ;
}
F_175 ( & V_19 -> V_219 ) ;
F_35 ( F_176 ( V_19 , V_23 ) ) ;
F_172 ( & V_19 -> V_49 , true ) ;
F_177 ( & V_19 -> V_29 , F_22 ) ;
}
static int F_178 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_10 * V_166 ;
struct V_16 * V_19 ;
int V_63 ;
V_166 = F_155 ( V_4 ) ;
if ( ! V_166 )
return - V_90 ;
F_6 () ;
V_19 = F_156 ( F_97 ( V_11 -> V_130 ) , V_4 -> V_108 , V_4 -> V_110 ) ;
V_63 = F_57 ( V_19 ) ;
if ( F_33 ( V_19 ) )
goto V_223;
V_63 = F_152 ( V_19 , V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 , V_224 ) ;
F_74 ( V_63 < 0 ) ;
F_173 ( V_19 ) ;
F_8 () ;
F_4 ( & V_196 , V_166 , V_4 ) ;
return 0 ;
V_223:
F_8 () ;
F_46 ( V_166 ) ;
return V_63 ;
}
static int F_179 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_10 * V_166 ;
struct V_16 * V_19 ;
int V_63 ;
V_166 = F_155 ( V_4 ) ;
if ( ! V_166 )
return - V_90 ;
F_6 () ;
V_19 = F_156 ( F_97 ( V_11 -> V_130 ) , V_4 -> V_108 , V_4 -> V_110 ) ;
V_63 = F_57 ( V_19 ) ;
if ( F_33 ( V_19 ) )
goto V_223;
F_160 ( V_19 , V_4 -> V_110 ) ;
V_63 = F_152 ( V_19 , V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 , V_217 ) ;
F_74 ( V_63 < 0 ) ;
F_8 () ;
F_4 ( & V_196 , V_166 , V_4 ) ;
return 0 ;
V_223:
F_8 () ;
F_46 ( V_166 ) ;
return V_63 ;
}
static int F_180 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_10 * V_166 ;
struct V_16 * V_19 ;
int V_63 ;
V_166 = F_155 ( V_4 ) ;
if ( ! V_166 )
return - V_90 ;
F_6 () ;
V_19 = F_156 ( F_97 ( V_11 -> V_130 ) , V_4 -> V_108 , V_4 -> V_110 ) ;
if ( F_33 ( V_19 ) ) {
V_63 = F_57 ( V_19 ) ;
goto V_223;
}
V_63 = F_152 ( V_19 , V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 , V_217 ) ;
F_74 ( V_63 < 0 ) ;
F_8 () ;
return F_140 ( V_166 , V_4 ) ;
V_223:
F_8 () ;
F_46 ( V_166 ) ;
return V_63 ;
}
static int F_181 ( struct V_10 * V_11 , struct V_183 * V_184 )
{
struct V_202 * V_202 = F_170 ( F_97 ( V_11 -> V_130 ) , V_218 ) ;
struct V_16 * V_19 ;
int V_225 = V_184 -> args [ 0 ] ;
int V_136 = 0 ;
F_6 () ;
F_182 (dp, &ovs_net->dps, list_node) {
if ( V_136 >= V_225 &&
F_152 ( V_19 , V_11 , F_150 ( V_184 -> V_11 ) . V_55 ,
V_184 -> V_185 -> V_190 , V_191 ,
V_217 ) < 0 )
break;
V_136 ++ ;
}
F_8 () ;
V_184 -> args [ 0 ] = V_136 ;
return V_11 -> V_86 ;
}
static int F_183 ( struct V_22 * V_22 , struct V_10 * V_11 ,
T_3 V_55 , T_3 V_144 , T_3 V_59 , T_5 V_52 )
{
struct V_81 * V_81 ;
struct V_226 V_227 ;
int V_63 ;
V_81 = F_71 ( V_11 , V_55 , V_144 , & V_228 ,
V_59 , V_52 ) ;
if ( ! V_81 )
return - V_149 ;
V_81 -> V_18 = F_19 ( V_22 -> V_19 ) ;
if ( F_154 ( V_11 , V_229 , V_22 -> V_33 ) ||
F_154 ( V_11 , V_230 , V_22 -> V_24 -> type ) ||
F_153 ( V_11 , V_231 ,
V_22 -> V_24 -> V_25 ( V_22 ) ) )
goto V_151;
F_184 ( V_22 , & V_227 ) ;
if ( F_113 ( V_11 , V_232 , sizeof( struct V_226 ) ,
& V_227 ) )
goto V_151;
if ( F_185 ( V_22 , V_11 ) )
goto V_151;
V_63 = F_186 ( V_22 , V_11 ) ;
if ( V_63 == - V_149 )
goto error;
return F_118 ( V_11 , V_81 ) ;
V_151:
V_63 = - V_149 ;
error:
F_119 ( V_11 , V_81 ) ;
return V_63 ;
}
static struct V_10 * F_187 ( void )
{
return F_188 ( V_233 , V_13 ) ;
}
struct V_10 * F_189 ( struct V_22 * V_22 , T_3 V_55 ,
T_3 V_144 , T_5 V_52 )
{
struct V_10 * V_11 ;
int V_162 ;
V_11 = F_188 ( V_233 , V_89 ) ;
if ( ! V_11 )
return F_121 ( - V_90 ) ;
V_162 = F_183 ( V_22 , V_11 , V_55 , V_144 , 0 , V_52 ) ;
F_74 ( V_162 < 0 ) ;
return V_11 ;
}
static struct V_22 * F_190 ( struct V_17 * V_17 ,
struct V_81 * V_81 ,
struct V_78 * V_109 [ V_234 + 1 ] )
{
struct V_16 * V_19 ;
struct V_22 * V_22 ;
if ( V_109 [ V_231 ] ) {
V_22 = F_157 ( V_17 , F_77 ( V_109 [ V_231 ] ) ) ;
if ( ! V_22 )
return F_121 ( - V_88 ) ;
if ( V_81 -> V_18 &&
V_81 -> V_18 != F_19 ( V_22 -> V_19 ) )
return F_121 ( - V_88 ) ;
return V_22 ;
} else if ( V_109 [ V_229 ] ) {
T_3 V_33 = F_161 ( V_109 [ V_229 ] ) ;
if ( V_33 >= V_235 )
return F_121 ( - V_94 ) ;
V_19 = F_12 ( V_17 , V_81 -> V_18 ) ;
if ( ! V_19 )
return F_121 ( - V_88 ) ;
V_22 = F_18 ( V_19 , V_33 ) ;
if ( ! V_22 )
return F_121 ( - V_88 ) ;
return V_22 ;
} else
return F_121 ( - V_72 ) ;
}
static int F_191 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_81 * V_81 = V_4 -> V_108 ;
struct V_36 V_37 ;
struct V_10 * V_166 ;
struct V_22 * V_22 ;
struct V_16 * V_19 ;
T_3 V_33 ;
int V_63 ;
if ( ! V_109 [ V_231 ] || ! V_109 [ V_230 ] ||
! V_109 [ V_236 ] )
return - V_72 ;
V_33 = V_109 [ V_229 ]
? F_161 ( V_109 [ V_229 ] ) : 0 ;
if ( V_33 >= V_235 )
return - V_94 ;
V_166 = F_187 () ;
if ( ! V_166 )
return - V_90 ;
F_6 () ;
V_19 = F_12 ( F_97 ( V_11 -> V_130 ) , V_81 -> V_18 ) ;
V_63 = - V_88 ;
if ( ! V_19 )
goto V_237;
if ( V_33 ) {
V_22 = F_176 ( V_19 , V_33 ) ;
V_63 = - V_212 ;
if ( V_22 )
goto V_237;
} else {
for ( V_33 = 1 ; ; V_33 ++ ) {
if ( V_33 >= V_235 ) {
V_63 = - V_94 ;
goto V_237;
}
V_22 = F_176 ( V_19 , V_33 ) ;
if ( ! V_22 )
break;
}
}
V_37 . V_208 = F_77 ( V_109 [ V_231 ] ) ;
V_37 . type = F_161 ( V_109 [ V_230 ] ) ;
V_37 . V_210 = V_109 [ V_238 ] ;
V_37 . V_19 = V_19 ;
V_37 . V_33 = V_33 ;
V_37 . V_211 = V_109 [ V_236 ] ;
V_22 = F_31 ( & V_37 ) ;
V_63 = F_57 ( V_22 ) ;
if ( F_33 ( V_22 ) )
goto V_237;
V_63 = F_183 ( V_22 , V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 , V_239 ) ;
F_74 ( V_63 < 0 ) ;
F_8 () ;
F_4 ( & V_228 , V_166 , V_4 ) ;
return 0 ;
V_237:
F_8 () ;
F_46 ( V_166 ) ;
return V_63 ;
}
static int F_192 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_10 * V_166 ;
struct V_22 * V_22 ;
int V_63 ;
V_166 = F_187 () ;
if ( ! V_166 )
return - V_90 ;
F_6 () ;
V_22 = F_190 ( F_97 ( V_11 -> V_130 ) , V_4 -> V_108 , V_109 ) ;
V_63 = F_57 ( V_22 ) ;
if ( F_33 ( V_22 ) )
goto V_237;
if ( V_109 [ V_230 ] &&
F_161 ( V_109 [ V_230 ] ) != V_22 -> V_24 -> type ) {
V_63 = - V_72 ;
goto V_237;
}
if ( V_109 [ V_238 ] ) {
V_63 = F_193 ( V_22 , V_109 [ V_238 ] ) ;
if ( V_63 )
goto V_237;
}
if ( V_109 [ V_236 ] ) {
struct V_78 * V_240 = V_109 [ V_236 ] ;
V_63 = F_194 ( V_22 , V_240 ) ;
if ( V_63 )
goto V_237;
}
V_63 = F_183 ( V_22 , V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 , V_239 ) ;
F_74 ( V_63 < 0 ) ;
F_8 () ;
F_4 ( & V_228 , V_166 , V_4 ) ;
return 0 ;
V_237:
F_8 () ;
F_46 ( V_166 ) ;
return V_63 ;
}
static int F_195 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_10 * V_166 ;
struct V_22 * V_22 ;
int V_63 ;
V_166 = F_187 () ;
if ( ! V_166 )
return - V_90 ;
F_6 () ;
V_22 = F_190 ( F_97 ( V_11 -> V_130 ) , V_4 -> V_108 , V_109 ) ;
V_63 = F_57 ( V_22 ) ;
if ( F_33 ( V_22 ) )
goto V_237;
if ( V_22 -> V_33 == V_23 ) {
V_63 = - V_72 ;
goto V_237;
}
V_63 = F_183 ( V_22 , V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 , V_241 ) ;
F_74 ( V_63 < 0 ) ;
F_35 ( V_22 ) ;
F_8 () ;
F_4 ( & V_228 , V_166 , V_4 ) ;
return 0 ;
V_237:
F_8 () ;
F_46 ( V_166 ) ;
return V_63 ;
}
static int F_196 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
struct V_78 * * V_109 = V_4 -> V_110 ;
struct V_81 * V_81 = V_4 -> V_108 ;
struct V_10 * V_166 ;
struct V_22 * V_22 ;
int V_63 ;
V_166 = F_187 () ;
if ( ! V_166 )
return - V_90 ;
F_13 () ;
V_22 = F_190 ( F_97 ( V_11 -> V_130 ) , V_81 , V_109 ) ;
V_63 = F_57 ( V_22 ) ;
if ( F_33 ( V_22 ) )
goto V_237;
V_63 = F_183 ( V_22 , V_166 , V_4 -> V_12 ,
V_4 -> V_163 , 0 , V_239 ) ;
F_74 ( V_63 < 0 ) ;
F_16 () ;
return F_140 ( V_166 , V_4 ) ;
V_237:
F_16 () ;
F_46 ( V_166 ) ;
return V_63 ;
}
static int F_197 ( struct V_10 * V_11 , struct V_183 * V_184 )
{
struct V_81 * V_81 = F_146 ( F_147 ( V_184 -> V_185 ) ) ;
struct V_16 * V_19 ;
int V_188 = V_184 -> args [ 0 ] , V_225 = V_184 -> args [ 1 ] ;
int V_136 , V_242 = 0 ;
F_13 () ;
V_19 = F_12 ( F_97 ( V_11 -> V_130 ) , V_81 -> V_18 ) ;
if ( ! V_19 ) {
F_16 () ;
return - V_88 ;
}
for ( V_136 = V_188 ; V_136 < V_34 ; V_136 ++ ) {
struct V_22 * V_22 ;
V_242 = 0 ;
F_30 (vport, &dp->ports[i], dp_hash_node) {
if ( V_242 >= V_225 &&
F_183 ( V_22 , V_11 ,
F_150 ( V_184 -> V_11 ) . V_55 ,
V_184 -> V_185 -> V_190 ,
V_191 ,
V_239 ) < 0 )
goto V_57;
V_242 ++ ;
}
V_225 = 0 ;
}
V_57:
F_16 () ;
V_184 -> args [ 0 ] = V_136 ;
V_184 -> args [ 1 ] = V_242 ;
return V_11 -> V_86 ;
}
static void F_198 ( int V_243 )
{
int V_136 ;
for ( V_136 = 0 ; V_136 < V_243 ; V_136 ++ )
F_199 ( V_244 [ V_136 ] ) ;
}
static int F_200 ( void )
{
int V_63 ;
int V_136 ;
for ( V_136 = 0 ; V_136 < F_201 ( V_244 ) ; V_136 ++ ) {
V_63 = F_202 ( V_244 [ V_136 ] ) ;
if ( V_63 )
goto error;
}
return 0 ;
error:
F_198 ( V_136 ) ;
return V_63 ;
}
static int T_7 F_203 ( struct V_17 * V_17 )
{
struct V_202 * V_202 = F_170 ( V_17 , V_218 ) ;
F_204 ( & V_202 -> V_220 ) ;
F_205 ( & V_202 -> V_245 , V_246 ) ;
return 0 ;
}
static void T_8 F_206 ( struct V_17 * V_17 )
{
struct V_16 * V_19 , * V_247 ;
struct V_202 * V_202 = F_170 ( V_17 , V_218 ) ;
F_6 () ;
F_207 (dp, dp_next, &ovs_net->dps, list_node)
F_173 ( V_19 ) ;
F_8 () ;
F_208 ( & V_202 -> V_245 ) ;
}
static int T_9 F_209 ( void )
{
int V_63 ;
F_210 ( sizeof( struct V_248 ) > F_211 ( struct V_10 , V_184 ) ) ;
F_212 ( L_4 ) ;
V_63 = F_213 () ;
if ( V_63 )
goto error;
V_63 = F_214 () ;
if ( V_63 )
goto V_249;
V_63 = F_215 () ;
if ( V_63 )
goto V_250;
V_63 = F_216 () ;
if ( V_63 )
goto V_251;
V_63 = F_217 ( & V_252 ) ;
if ( V_63 )
goto V_253;
V_63 = F_218 ( & V_254 ) ;
if ( V_63 )
goto V_255;
V_63 = F_200 () ;
if ( V_63 < 0 )
goto V_256;
return 0 ;
V_256:
F_219 ( & V_254 ) ;
V_255:
F_220 ( & V_252 ) ;
V_253:
F_221 () ;
V_251:
F_222 () ;
V_250:
F_223 () ;
V_249:
F_224 () ;
error:
return V_63 ;
}
static void F_225 ( void )
{
F_198 ( F_201 ( V_244 ) ) ;
F_219 ( & V_254 ) ;
F_220 ( & V_252 ) ;
F_226 () ;
F_221 () ;
F_222 () ;
F_223 () ;
F_224 () ;
}
