static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
F_2 ( V_2 , V_4 , F_3 ( V_6 ) , V_6 -> V_7 ,
0 , V_6 -> V_8 , V_9 ) ;
}
void F_4 ( void )
{
F_5 ( & V_10 ) ;
}
void F_6 ( void )
{
F_7 ( & V_10 ) ;
}
int F_8 ( void )
{
if ( V_11 )
return F_9 ( & V_10 ) ;
else
return 1 ;
}
static struct V_12 * F_10 ( struct V_13 * V_13 , int V_14 )
{
struct V_12 * V_15 = NULL ;
struct V_16 * V_17 ;
F_11 () ;
V_17 = F_12 ( V_13 , V_14 ) ;
if ( V_17 ) {
struct V_18 * V_18 = F_13 ( V_17 ) ;
if ( V_18 )
V_15 = V_18 -> V_15 ;
}
F_14 () ;
return V_15 ;
}
const char * F_15 ( const struct V_12 * V_15 )
{
struct V_18 * V_18 = F_16 ( V_15 , V_19 ) ;
return V_18 -> V_20 -> V_21 ( V_18 ) ;
}
static int F_17 ( struct V_12 * V_15 )
{
struct V_18 * V_22 ;
int V_23 ;
F_11 () ;
V_22 = F_18 ( V_15 , V_19 ) ;
if ( V_22 )
V_23 = F_19 ( V_22 ) -> V_17 -> V_23 ;
else
V_23 = 0 ;
F_14 () ;
return V_23 ;
}
static void F_20 ( struct V_24 * V_25 )
{
struct V_12 * V_15 = F_21 ( V_25 , struct V_12 , V_25 ) ;
F_22 ( & V_15 -> V_26 ) ;
F_23 ( V_15 -> V_27 ) ;
F_24 ( F_25 ( V_15 ) ) ;
F_26 ( V_15 -> V_28 ) ;
F_26 ( V_15 ) ;
}
static struct V_29 * F_27 ( const struct V_12 * V_15 ,
T_1 V_30 )
{
return & V_15 -> V_28 [ V_30 & ( V_31 - 1 ) ] ;
}
struct V_18 * F_28 ( const struct V_12 * V_15 , T_1 V_30 )
{
struct V_18 * V_18 ;
struct V_29 * V_32 ;
V_32 = F_27 ( V_15 , V_30 ) ;
F_29 (vport, head, dp_hash_node) {
if ( V_18 -> V_30 == V_30 )
return V_18 ;
}
return NULL ;
}
static struct V_18 * F_30 ( const struct V_33 * V_34 )
{
struct V_18 * V_18 ;
V_18 = F_31 ( V_34 ) ;
if ( ! F_32 ( V_18 ) ) {
struct V_12 * V_15 = V_34 -> V_15 ;
struct V_29 * V_32 = F_27 ( V_15 , V_18 -> V_30 ) ;
F_33 ( & V_18 -> V_35 , V_32 ) ;
}
return V_18 ;
}
void F_34 ( struct V_18 * V_36 )
{
F_35 () ;
F_36 ( & V_36 -> V_35 ) ;
F_37 ( V_36 ) ;
}
void F_38 ( struct V_18 * V_36 , struct V_3 * V_4 )
{
struct V_12 * V_15 = V_36 -> V_15 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_41 V_42 ;
T_2 * V_43 ;
T_3 V_44 ;
int error ;
V_40 = F_39 ( V_15 -> V_27 ) ;
error = F_40 ( V_4 , V_36 -> V_30 , & V_42 ) ;
if ( F_41 ( error ) ) {
F_42 ( V_4 ) ;
return;
}
V_38 = F_43 ( & V_15 -> V_26 , & V_42 , & V_44 ) ;
if ( F_41 ( ! V_38 ) ) {
struct V_45 V_46 ;
V_46 . V_47 = V_48 ;
V_46 . V_42 = & V_42 ;
V_46 . V_49 = NULL ;
V_46 . V_50 = V_36 -> V_51 ;
F_44 ( V_15 , V_4 , & V_46 ) ;
F_45 ( V_4 ) ;
V_43 = & V_40 -> V_52 ;
goto V_53;
}
F_46 ( V_4 ) -> V_38 = V_38 ;
F_46 ( V_4 ) -> V_54 = & V_42 ;
V_43 = & V_40 -> V_55 ;
F_47 ( F_46 ( V_4 ) -> V_38 , V_4 ) ;
F_48 ( V_15 , V_4 ) ;
V_53:
F_49 ( & V_40 -> V_56 ) ;
( * V_43 ) ++ ;
V_40 -> V_44 += V_44 ;
F_50 ( & V_40 -> V_56 ) ;
}
int F_44 ( struct V_12 * V_15 , struct V_3 * V_4 ,
const struct V_45 * V_57 )
{
struct V_39 * V_40 ;
int V_14 ;
int V_58 ;
if ( V_57 -> V_50 == 0 ) {
V_58 = - V_59 ;
goto V_58;
}
V_14 = F_17 ( V_15 ) ;
if ( ! V_14 ) {
V_58 = - V_60 ;
goto V_58;
}
if ( ! F_51 ( V_4 ) )
V_58 = F_52 ( F_25 ( V_15 ) , V_14 , V_4 , V_57 ) ;
else
V_58 = F_53 ( F_25 ( V_15 ) , V_14 , V_4 , V_57 ) ;
if ( V_58 )
goto V_58;
return 0 ;
V_58:
V_40 = F_39 ( V_15 -> V_27 ) ;
F_49 ( & V_40 -> V_56 ) ;
V_40 -> V_61 ++ ;
F_50 ( & V_40 -> V_56 ) ;
return V_58 ;
}
static int F_53 ( struct V_13 * V_13 , int V_14 ,
struct V_3 * V_4 ,
const struct V_45 * V_57 )
{
unsigned short V_62 = F_54 ( V_4 ) -> V_62 ;
struct V_45 V_63 ;
struct V_41 V_64 ;
struct V_3 * V_65 , * V_66 ;
int V_58 ;
V_65 = F_55 ( V_4 , V_67 | V_68 , false ) ;
if ( F_32 ( V_65 ) )
return F_56 ( V_65 ) ;
V_4 = V_65 ;
do {
V_58 = F_52 ( V_13 , V_14 , V_4 , V_57 ) ;
if ( V_58 )
break;
if ( V_4 == V_65 && V_62 & V_69 ) {
V_64 = * V_57 -> V_42 ;
V_64 . V_70 . V_71 = V_72 ;
V_63 = * V_57 ;
V_63 . V_42 = & V_64 ;
V_57 = & V_63 ;
}
} while ( ( V_4 = V_4 -> V_73 ) );
V_4 = V_65 ;
do {
V_66 = V_4 -> V_73 ;
if ( V_58 )
F_42 ( V_4 ) ;
else
F_45 ( V_4 ) ;
} while ( ( V_4 = V_66 ) );
return V_58 ;
}
static T_4 F_57 ( void )
{
return F_58 ( 4 )
+ F_58 ( 0 )
+ F_58 ( 8 )
+ F_58 ( 4 )
+ F_58 ( 4 )
+ F_58 ( 1 )
+ F_58 ( 1 )
+ F_58 ( 0 )
+ F_58 ( 0 )
+ F_58 ( 4 )
+ F_58 ( 4 )
+ F_58 ( 12 )
+ F_58 ( 2 )
+ F_58 ( 4 )
+ F_58 ( 0 )
+ F_58 ( 2 )
+ F_58 ( 40 )
+ F_58 ( 2 )
+ F_58 ( 28 ) ;
}
static T_4 F_59 ( const struct V_3 * V_4 ,
const struct V_74 * V_49 )
{
T_4 V_75 = F_60 ( sizeof( struct V_76 ) )
+ F_58 ( V_4 -> V_77 )
+ F_58 ( F_57 () ) ;
if ( V_49 )
V_75 += F_61 ( V_49 -> V_78 ) ;
return V_75 ;
}
static int F_52 ( struct V_13 * V_13 , int V_14 ,
struct V_3 * V_4 ,
const struct V_45 * V_57 )
{
struct V_76 * V_46 ;
struct V_3 * V_66 = NULL ;
struct V_3 * V_79 ;
struct V_74 * V_80 ;
int V_58 ;
if ( F_62 ( V_4 ) ) {
V_66 = F_63 ( V_4 , V_81 ) ;
if ( ! V_66 )
return - V_82 ;
V_66 = F_64 ( V_66 , V_66 -> V_83 , F_65 ( V_66 ) ) ;
if ( ! V_66 )
return - V_82 ;
V_66 -> V_84 = 0 ;
V_4 = V_66 ;
}
if ( F_66 ( V_4 -> V_77 ) > V_85 ) {
V_58 = - V_86 ;
goto V_53;
}
V_79 = F_67 ( F_59 ( V_4 , V_57 -> V_49 ) , V_81 ) ;
if ( ! V_79 ) {
V_58 = - V_82 ;
goto V_53;
}
V_46 = F_68 ( V_79 , 0 , 0 , & V_87 ,
0 , V_57 -> V_47 ) ;
V_46 -> V_14 = V_14 ;
V_80 = F_69 ( V_79 , V_88 ) ;
F_70 ( V_57 -> V_42 , V_57 -> V_42 , V_79 ) ;
F_71 ( V_79 , V_80 ) ;
if ( V_57 -> V_49 )
F_72 ( V_79 , V_89 ,
V_78 ( V_57 -> V_49 ) ,
F_73 ( V_57 -> V_49 ) ) ;
V_80 = F_74 ( V_79 , V_90 , V_4 -> V_77 ) ;
F_75 ( V_4 , F_73 ( V_80 ) ) ;
F_76 ( V_79 , V_46 ) ;
V_58 = F_77 ( V_13 , V_79 , V_57 -> V_50 ) ;
V_53:
F_42 ( V_66 ) ;
return V_58 ;
}
static void F_78 ( struct V_37 * V_38 )
{
V_38 -> V_91 = 0 ;
V_38 -> V_92 = 0 ;
V_38 -> V_93 = 0 ;
V_38 -> V_94 = 0 ;
}
static int F_79 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_76 * V_76 = V_6 -> V_95 ;
struct V_74 * * V_96 = V_6 -> V_97 ;
struct V_98 * V_99 ;
struct V_3 * V_100 ;
struct V_37 * V_38 ;
struct V_12 * V_15 ;
struct V_101 * V_102 ;
int V_77 ;
int V_58 ;
V_58 = - V_103 ;
if ( ! V_96 [ V_90 ] || ! V_96 [ V_88 ] ||
! V_96 [ V_104 ] )
goto V_58;
V_77 = V_78 ( V_96 [ V_90 ] ) ;
V_100 = F_80 ( V_105 + V_77 , V_9 ) ;
V_58 = - V_82 ;
if ( ! V_100 )
goto V_58;
F_81 ( V_100 , V_105 ) ;
F_82 ( F_83 ( V_100 , V_77 ) , V_96 [ V_90 ] , V_77 ) ;
F_84 ( V_100 ) ;
V_102 = F_85 ( V_100 ) ;
if ( F_86 ( V_102 -> V_106 ) >= V_107 )
V_100 -> V_108 = V_102 -> V_106 ;
else
V_100 -> V_108 = F_87 ( V_109 ) ;
V_38 = F_88 () ;
V_58 = F_56 ( V_38 ) ;
if ( F_32 ( V_38 ) )
goto V_110;
V_58 = F_40 ( V_100 , - 1 , & V_38 -> V_42 ) ;
if ( V_58 )
goto V_111;
V_58 = F_89 ( V_38 , V_96 [ V_88 ] ) ;
if ( V_58 )
goto V_111;
V_99 = F_90 ( V_78 ( V_96 [ V_104 ] ) ) ;
V_58 = F_56 ( V_99 ) ;
if ( F_32 ( V_99 ) )
goto V_111;
V_58 = F_91 ( V_96 [ V_104 ] ,
& V_38 -> V_42 , 0 , & V_99 ) ;
F_92 ( V_38 -> V_112 , V_99 ) ;
if ( V_58 )
goto V_111;
F_46 ( V_100 ) -> V_38 = V_38 ;
F_46 ( V_100 ) -> V_54 = & V_38 -> V_42 ;
V_100 -> V_113 = V_38 -> V_42 . V_114 . V_113 ;
V_100 -> V_115 = V_38 -> V_42 . V_114 . V_116 ;
F_11 () ;
V_15 = F_10 ( F_93 ( V_4 -> V_117 ) , V_76 -> V_14 ) ;
V_58 = - V_60 ;
if ( ! V_15 )
goto V_118;
F_94 () ;
V_58 = F_48 ( V_15 , V_100 ) ;
F_95 () ;
F_14 () ;
F_96 ( V_38 , false ) ;
return V_58 ;
V_118:
F_14 () ;
V_111:
F_96 ( V_38 , false ) ;
V_110:
F_42 ( V_100 ) ;
V_58:
return V_58 ;
}
static void F_97 ( struct V_12 * V_15 , struct V_119 * V_40 ,
struct V_120 * V_121 )
{
int V_122 ;
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_40 -> V_123 = F_98 ( & V_15 -> V_26 ) ;
V_121 -> V_124 = F_99 ( & V_15 -> V_26 ) ;
V_40 -> V_55 = V_40 -> V_52 = V_40 -> V_61 = 0 ;
F_100 (i) {
const struct V_39 * V_125 ;
struct V_39 V_126 ;
unsigned int V_127 ;
V_125 = F_101 ( V_15 -> V_27 , V_122 ) ;
do {
V_127 = F_102 ( & V_125 -> V_56 ) ;
V_126 = * V_125 ;
} while ( F_103 ( & V_125 -> V_56 , V_127 ) );
V_40 -> V_55 += V_126 . V_55 ;
V_40 -> V_52 += V_126 . V_52 ;
V_40 -> V_61 += V_126 . V_61 ;
V_121 -> V_44 += V_126 . V_44 ;
}
}
static T_4 F_104 ( const struct V_98 * V_99 )
{
return F_60 ( sizeof( struct V_76 ) )
+ F_58 ( F_57 () )
+ F_58 ( F_57 () )
+ F_58 ( sizeof( struct V_128 ) )
+ F_58 ( 1 )
+ F_58 ( 8 )
+ F_58 ( V_99 -> V_129 ) ;
}
static int F_105 ( struct V_37 * V_38 , struct V_12 * V_15 ,
struct V_3 * V_4 , T_3 V_50 ,
T_3 V_130 , T_3 V_131 , T_5 V_47 )
{
const int V_132 = V_4 -> V_77 ;
struct V_74 * V_127 ;
struct V_128 V_40 ;
struct V_76 * V_76 ;
struct V_74 * V_80 ;
unsigned long V_91 ;
T_5 V_92 ;
int V_58 ;
V_76 = F_68 ( V_4 , V_50 , V_130 , & V_133 , V_131 , V_47 ) ;
if ( ! V_76 )
return - V_134 ;
V_76 -> V_14 = F_17 ( V_15 ) ;
V_80 = F_69 ( V_4 , V_135 ) ;
if ( ! V_80 )
goto V_136;
V_58 = F_70 ( & V_38 -> V_137 , & V_38 -> V_137 , V_4 ) ;
if ( V_58 )
goto error;
F_71 ( V_4 , V_80 ) ;
V_80 = F_69 ( V_4 , V_138 ) ;
if ( ! V_80 )
goto V_136;
V_58 = F_70 ( & V_38 -> V_42 , & V_38 -> V_139 -> V_42 , V_4 ) ;
if ( V_58 )
goto error;
F_71 ( V_4 , V_80 ) ;
F_106 ( & V_38 -> V_140 ) ;
V_91 = V_38 -> V_91 ;
V_40 . V_141 = V_38 -> V_93 ;
V_40 . V_142 = V_38 -> V_94 ;
V_92 = ( T_5 ) F_86 ( V_38 -> V_92 ) ;
F_107 ( & V_38 -> V_140 ) ;
if ( V_91 &&
F_108 ( V_4 , V_143 , F_109 ( V_91 ) ) )
goto V_136;
if ( V_40 . V_141 &&
F_110 ( V_4 , V_144 ,
sizeof( struct V_128 ) , & V_40 ) )
goto V_136;
if ( V_92 &&
F_111 ( V_4 , V_145 , V_92 ) )
goto V_136;
V_127 = F_69 ( V_4 , V_146 ) ;
if ( V_127 ) {
const struct V_98 * V_112 ;
V_112 = F_112 ( V_38 -> V_112 ,
F_8 () ) ;
V_58 = F_113 ( V_112 -> V_147 ,
V_112 -> V_129 , V_4 ) ;
if ( ! V_58 )
F_71 ( V_4 , V_127 ) ;
else {
if ( V_132 )
goto error;
F_114 ( V_4 , V_127 ) ;
}
} else if ( V_132 )
goto V_136;
return F_76 ( V_4 , V_76 ) ;
V_136:
V_58 = - V_134 ;
error:
F_115 ( V_4 , V_76 ) ;
return V_58 ;
}
static struct V_3 * F_116 ( struct V_37 * V_38 )
{
const struct V_98 * V_112 ;
V_112 = F_117 ( V_38 -> V_112 ) ;
return F_67 ( F_104 ( V_112 ) , V_9 ) ;
}
static struct V_3 * F_118 ( struct V_37 * V_38 ,
struct V_12 * V_15 ,
T_3 V_50 , T_3 V_130 , T_5 V_47 )
{
struct V_3 * V_4 ;
int V_148 ;
V_4 = F_116 ( V_38 ) ;
if ( ! V_4 )
return F_119 ( - V_82 ) ;
V_148 = F_105 ( V_38 , V_15 , V_4 , V_50 , V_130 , 0 , V_47 ) ;
F_120 ( V_148 < 0 ) ;
return V_4 ;
}
static struct V_37 * F_121 ( struct V_149 * V_150 ,
const struct V_41 * V_42 )
{
T_3 T_6 V_44 ;
return F_43 ( V_150 , V_42 , & V_44 ) ;
}
static int F_122 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_74 * * V_96 = V_6 -> V_97 ;
struct V_76 * V_76 = V_6 -> V_95 ;
struct V_41 V_42 , V_151 ;
struct V_37 * V_38 = NULL ;
struct V_152 V_139 ;
struct V_3 * V_153 ;
struct V_12 * V_15 ;
struct V_98 * V_99 = NULL ;
struct V_154 V_155 ;
int error ;
error = - V_103 ;
if ( ! V_96 [ V_135 ] )
goto error;
F_123 ( & V_155 , & V_42 , & V_139 ) ;
error = F_124 ( & V_155 ,
V_96 [ V_135 ] , V_96 [ V_138 ] ) ;
if ( error )
goto error;
if ( V_96 [ V_146 ] ) {
V_99 = F_90 ( V_78 ( V_96 [ V_146 ] ) ) ;
error = F_56 ( V_99 ) ;
if ( F_32 ( V_99 ) )
goto error;
F_125 ( & V_151 , & V_42 , & V_139 ) ;
error = F_91 ( V_96 [ V_146 ] ,
& V_151 , 0 , & V_99 ) ;
if ( error ) {
F_126 ( L_1 ) ;
goto V_156;
}
} else if ( V_6 -> V_157 -> V_47 == V_158 ) {
error = - V_103 ;
goto error;
}
F_4 () ;
V_15 = F_10 ( F_93 ( V_4 -> V_117 ) , V_76 -> V_14 ) ;
error = - V_60 ;
if ( ! V_15 )
goto V_159;
V_38 = F_121 ( & V_15 -> V_26 , & V_42 ) ;
if ( ! V_38 ) {
error = - V_160 ;
if ( V_6 -> V_157 -> V_47 == V_161 )
goto V_159;
V_38 = F_88 () ;
if ( F_32 ( V_38 ) ) {
error = F_56 ( V_38 ) ;
goto V_159;
}
F_78 ( V_38 ) ;
V_38 -> V_42 = V_151 ;
V_38 -> V_137 = V_42 ;
F_92 ( V_38 -> V_112 , V_99 ) ;
error = F_127 ( & V_15 -> V_26 , V_38 , & V_139 ) ;
if ( error ) {
V_99 = NULL ;
goto V_111;
}
V_153 = F_118 ( V_38 , V_15 , V_6 -> V_7 ,
V_6 -> V_162 , V_158 ) ;
} else {
struct V_98 * V_163 ;
error = - V_164 ;
if ( V_6 -> V_157 -> V_47 == V_158 &&
V_6 -> V_8 -> V_165 & ( V_166 | V_167 ) )
goto V_159;
error = - V_103 ;
if ( ! F_128 ( V_38 , & V_155 ) ) {
F_126 ( L_2 ) ;
goto V_159;
}
V_163 = F_117 ( V_38 -> V_112 ) ;
F_92 ( V_38 -> V_112 , V_99 ) ;
F_129 ( V_163 ) ;
V_153 = F_118 ( V_38 , V_15 , V_6 -> V_7 ,
V_6 -> V_162 , V_158 ) ;
if ( V_96 [ V_168 ] ) {
F_106 ( & V_38 -> V_140 ) ;
F_78 ( V_38 ) ;
F_107 ( & V_38 -> V_140 ) ;
}
}
F_6 () ;
if ( ! F_32 ( V_153 ) )
F_1 ( & V_133 , V_153 , V_6 ) ;
else
F_130 ( & V_133 , F_93 ( V_4 -> V_117 ) , 0 ,
0 , F_56 ( V_153 ) ) ;
return 0 ;
V_111:
F_96 ( V_38 , false ) ;
V_159:
F_6 () ;
V_156:
F_26 ( V_99 ) ;
error:
return error ;
}
static int F_131 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_74 * * V_96 = V_6 -> V_97 ;
struct V_76 * V_76 = V_6 -> V_95 ;
struct V_41 V_42 ;
struct V_3 * V_153 ;
struct V_37 * V_38 ;
struct V_12 * V_15 ;
struct V_154 V_155 ;
int V_58 ;
if ( ! V_96 [ V_135 ] ) {
F_126 ( L_3 ) ;
return - V_103 ;
}
F_123 ( & V_155 , & V_42 , NULL ) ;
V_58 = F_124 ( & V_155 , V_96 [ V_135 ] , NULL ) ;
if ( V_58 )
return V_58 ;
F_4 () ;
V_15 = F_10 ( F_93 ( V_4 -> V_117 ) , V_76 -> V_14 ) ;
if ( ! V_15 ) {
V_58 = - V_60 ;
goto V_169;
}
V_38 = F_121 ( & V_15 -> V_26 , & V_42 ) ;
if ( ! V_38 || ! F_128 ( V_38 , & V_155 ) ) {
V_58 = - V_160 ;
goto V_169;
}
V_153 = F_118 ( V_38 , V_15 , V_6 -> V_7 ,
V_6 -> V_162 , V_158 ) ;
if ( F_32 ( V_153 ) ) {
V_58 = F_56 ( V_153 ) ;
goto V_169;
}
F_6 () ;
return F_132 ( V_153 , V_6 ) ;
V_169:
F_6 () ;
return V_58 ;
}
static int F_133 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_74 * * V_96 = V_6 -> V_97 ;
struct V_76 * V_76 = V_6 -> V_95 ;
struct V_41 V_42 ;
struct V_3 * V_153 ;
struct V_37 * V_38 ;
struct V_12 * V_15 ;
struct V_154 V_155 ;
int V_58 ;
F_4 () ;
V_15 = F_10 ( F_93 ( V_4 -> V_117 ) , V_76 -> V_14 ) ;
if ( ! V_15 ) {
V_58 = - V_60 ;
goto V_169;
}
if ( ! V_96 [ V_135 ] ) {
V_58 = F_134 ( & V_15 -> V_26 ) ;
goto V_169;
}
F_123 ( & V_155 , & V_42 , NULL ) ;
V_58 = F_124 ( & V_155 , V_96 [ V_135 ] , NULL ) ;
if ( V_58 )
goto V_169;
V_38 = F_121 ( & V_15 -> V_26 , & V_42 ) ;
if ( ! V_38 || ! F_128 ( V_38 , & V_155 ) ) {
V_58 = - V_160 ;
goto V_169;
}
V_153 = F_116 ( V_38 ) ;
if ( ! V_153 ) {
V_58 = - V_82 ;
goto V_169;
}
F_135 ( & V_15 -> V_26 , V_38 ) ;
V_58 = F_105 ( V_38 , V_15 , V_153 , V_6 -> V_7 ,
V_6 -> V_162 , 0 , V_170 ) ;
F_120 ( V_58 < 0 ) ;
F_96 ( V_38 , true ) ;
F_6 () ;
F_1 ( & V_133 , V_153 , V_6 ) ;
return 0 ;
V_169:
F_6 () ;
return V_58 ;
}
static int F_136 ( struct V_3 * V_4 , struct V_171 * V_172 )
{
struct V_76 * V_76 = F_137 ( F_138 ( V_172 -> V_173 ) ) ;
struct V_174 * V_175 ;
struct V_12 * V_15 ;
F_11 () ;
V_15 = F_10 ( F_93 ( V_4 -> V_117 ) , V_76 -> V_14 ) ;
if ( ! V_15 ) {
F_14 () ;
return - V_60 ;
}
V_175 = F_139 ( V_15 -> V_26 . V_175 ) ;
for (; ; ) {
struct V_37 * V_38 ;
T_3 V_176 , V_177 ;
V_176 = V_172 -> args [ 0 ] ;
V_177 = V_172 -> args [ 1 ] ;
V_38 = F_140 ( V_175 , & V_176 , & V_177 ) ;
if ( ! V_38 )
break;
if ( F_105 ( V_38 , V_15 , V_4 ,
F_141 ( V_172 -> V_4 ) . V_50 ,
V_172 -> V_173 -> V_178 , V_179 ,
V_158 ) < 0 )
break;
V_172 -> args [ 0 ] = V_176 ;
V_172 -> args [ 1 ] = V_177 ;
}
F_14 () ;
return V_4 -> V_77 ;
}
static T_4 F_142 ( void )
{
T_4 V_180 = F_60 ( sizeof( struct V_76 ) ) ;
V_180 += F_58 ( V_181 ) ;
V_180 += F_58 ( sizeof( struct V_119 ) ) ;
V_180 += F_58 ( sizeof( struct V_120 ) ) ;
return V_180 ;
}
static int F_143 ( struct V_12 * V_15 , struct V_3 * V_4 ,
T_3 V_50 , T_3 V_130 , T_3 V_131 , T_5 V_47 )
{
struct V_76 * V_76 ;
struct V_119 V_182 ;
struct V_120 V_183 ;
int V_58 ;
V_76 = F_68 ( V_4 , V_50 , V_130 , & V_184 ,
V_131 , V_47 ) ;
if ( ! V_76 )
goto error;
V_76 -> V_14 = F_17 ( V_15 ) ;
F_11 () ;
V_58 = F_144 ( V_4 , V_185 , F_15 ( V_15 ) ) ;
F_14 () ;
if ( V_58 )
goto V_136;
F_97 ( V_15 , & V_182 , & V_183 ) ;
if ( F_110 ( V_4 , V_186 , sizeof( struct V_119 ) ,
& V_182 ) )
goto V_136;
if ( F_110 ( V_4 , V_187 ,
sizeof( struct V_120 ) ,
& V_183 ) )
goto V_136;
return F_76 ( V_4 , V_76 ) ;
V_136:
F_115 ( V_4 , V_76 ) ;
error:
return - V_134 ;
}
static struct V_3 * F_145 ( struct V_12 * V_15 , T_3 V_50 ,
T_3 V_130 , T_5 V_47 )
{
struct V_3 * V_4 ;
int V_148 ;
V_4 = F_67 ( F_142 () , V_9 ) ;
if ( ! V_4 )
return F_119 ( - V_82 ) ;
V_148 = F_143 ( V_15 , V_4 , V_50 , V_130 , 0 , V_47 ) ;
if ( V_148 < 0 ) {
F_42 ( V_4 ) ;
return F_119 ( V_148 ) ;
}
return V_4 ;
}
static struct V_12 * F_146 ( struct V_13 * V_13 ,
struct V_76 * V_76 ,
struct V_74 * V_96 [ V_188 + 1 ] )
{
struct V_12 * V_15 ;
if ( ! V_96 [ V_185 ] )
V_15 = F_10 ( V_13 , V_76 -> V_14 ) ;
else {
struct V_18 * V_18 ;
F_11 () ;
V_18 = F_147 ( V_13 , F_73 ( V_96 [ V_185 ] ) ) ;
V_15 = V_18 && V_18 -> V_30 == V_19 ? V_18 -> V_15 : NULL ;
F_14 () ;
}
return V_15 ? V_15 : F_119 ( - V_60 ) ;
}
static int F_148 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_74 * * V_96 = V_6 -> V_97 ;
struct V_33 V_34 ;
struct V_3 * V_153 ;
struct V_12 * V_15 ;
struct V_18 * V_18 ;
struct V_189 * V_189 ;
int V_58 , V_122 ;
V_58 = - V_103 ;
if ( ! V_96 [ V_185 ] || ! V_96 [ V_190 ] )
goto V_58;
F_4 () ;
V_58 = - V_82 ;
V_15 = F_149 ( sizeof( * V_15 ) , V_9 ) ;
if ( V_15 == NULL )
goto V_159;
F_150 ( V_15 , F_151 ( F_93 ( V_4 -> V_117 ) ) ) ;
V_58 = F_152 ( & V_15 -> V_26 ) ;
if ( V_58 )
goto V_191;
V_15 -> V_27 = F_153 ( struct V_39 ) ;
if ( ! V_15 -> V_27 ) {
V_58 = - V_82 ;
goto V_192;
}
F_100 (i) {
struct V_39 * V_193 ;
V_193 = F_101 ( V_15 -> V_27 , V_122 ) ;
F_154 ( & V_193 -> V_56 ) ;
}
V_15 -> V_28 = F_155 ( V_31 * sizeof( struct V_29 ) ,
V_9 ) ;
if ( ! V_15 -> V_28 ) {
V_58 = - V_82 ;
goto V_194;
}
for ( V_122 = 0 ; V_122 < V_31 ; V_122 ++ )
F_156 ( & V_15 -> V_28 [ V_122 ] ) ;
V_34 . V_195 = F_73 ( V_96 [ V_185 ] ) ;
V_34 . type = V_196 ;
V_34 . V_197 = NULL ;
V_34 . V_15 = V_15 ;
V_34 . V_30 = V_19 ;
V_34 . V_51 = F_157 ( V_96 [ V_190 ] ) ;
V_18 = F_30 ( & V_34 ) ;
if ( F_32 ( V_18 ) ) {
V_58 = F_56 ( V_18 ) ;
if ( V_58 == - V_198 )
V_58 = - V_164 ;
goto V_199;
}
V_153 = F_145 ( V_15 , V_6 -> V_7 ,
V_6 -> V_162 , V_200 ) ;
V_58 = F_56 ( V_153 ) ;
if ( F_32 ( V_153 ) )
goto V_201;
V_189 = F_158 ( F_25 ( V_15 ) , V_202 ) ;
F_159 ( & V_15 -> V_203 , & V_189 -> V_204 ) ;
F_6 () ;
F_1 ( & V_184 , V_153 , V_6 ) ;
return 0 ;
V_201:
F_34 ( F_160 ( V_15 , V_19 ) ) ;
V_199:
F_26 ( V_15 -> V_28 ) ;
V_194:
F_23 ( V_15 -> V_27 ) ;
V_192:
F_22 ( & V_15 -> V_26 ) ;
V_191:
F_24 ( F_25 ( V_15 ) ) ;
F_26 ( V_15 ) ;
V_159:
F_6 () ;
V_58:
return V_58 ;
}
static void F_161 ( struct V_12 * V_15 )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_31 ; V_122 ++ ) {
struct V_18 * V_18 ;
struct V_205 * V_206 ;
F_162 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_18 -> V_30 != V_19 )
F_34 ( V_18 ) ;
}
F_163 ( & V_15 -> V_203 ) ;
F_34 ( F_160 ( V_15 , V_19 ) ) ;
F_164 ( & V_15 -> V_25 , F_20 ) ;
}
static int F_165 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_3 * V_153 ;
struct V_12 * V_15 ;
int V_58 ;
F_4 () ;
V_15 = F_146 ( F_93 ( V_4 -> V_117 ) , V_6 -> V_95 , V_6 -> V_97 ) ;
V_58 = F_56 ( V_15 ) ;
if ( F_32 ( V_15 ) )
goto V_169;
V_153 = F_145 ( V_15 , V_6 -> V_7 ,
V_6 -> V_162 , V_207 ) ;
V_58 = F_56 ( V_153 ) ;
if ( F_32 ( V_153 ) )
goto V_169;
F_161 ( V_15 ) ;
F_6 () ;
F_1 ( & V_184 , V_153 , V_6 ) ;
return 0 ;
V_169:
F_6 () ;
return V_58 ;
}
static int F_166 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_3 * V_153 ;
struct V_12 * V_15 ;
int V_58 ;
F_4 () ;
V_15 = F_146 ( F_93 ( V_4 -> V_117 ) , V_6 -> V_95 , V_6 -> V_97 ) ;
V_58 = F_56 ( V_15 ) ;
if ( F_32 ( V_15 ) )
goto V_169;
V_153 = F_145 ( V_15 , V_6 -> V_7 ,
V_6 -> V_162 , V_200 ) ;
if ( F_32 ( V_153 ) ) {
V_58 = F_56 ( V_153 ) ;
F_130 ( & V_184 , F_93 ( V_4 -> V_117 ) , 0 ,
0 , V_58 ) ;
V_58 = 0 ;
goto V_169;
}
F_6 () ;
F_1 ( & V_184 , V_153 , V_6 ) ;
return 0 ;
V_169:
F_6 () ;
return V_58 ;
}
static int F_167 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_3 * V_153 ;
struct V_12 * V_15 ;
int V_58 ;
F_4 () ;
V_15 = F_146 ( F_93 ( V_4 -> V_117 ) , V_6 -> V_95 , V_6 -> V_97 ) ;
if ( F_32 ( V_15 ) ) {
V_58 = F_56 ( V_15 ) ;
goto V_169;
}
V_153 = F_145 ( V_15 , V_6 -> V_7 ,
V_6 -> V_162 , V_200 ) ;
if ( F_32 ( V_153 ) ) {
V_58 = F_56 ( V_153 ) ;
goto V_169;
}
F_6 () ;
return F_132 ( V_153 , V_6 ) ;
V_169:
F_6 () ;
return V_58 ;
}
static int F_168 ( struct V_3 * V_4 , struct V_171 * V_172 )
{
struct V_189 * V_189 = F_158 ( F_93 ( V_4 -> V_117 ) , V_202 ) ;
struct V_12 * V_15 ;
int V_208 = V_172 -> args [ 0 ] ;
int V_122 = 0 ;
F_11 () ;
F_169 (dp, &ovs_net->dps, list_node) {
if ( V_122 >= V_208 &&
F_143 ( V_15 , V_4 , F_141 ( V_172 -> V_4 ) . V_50 ,
V_172 -> V_173 -> V_178 , V_179 ,
V_200 ) < 0 )
break;
V_122 ++ ;
}
F_14 () ;
V_172 -> args [ 0 ] = V_122 ;
return V_4 -> V_77 ;
}
static int F_170 ( struct V_18 * V_18 , struct V_3 * V_4 ,
T_3 V_50 , T_3 V_130 , T_3 V_131 , T_5 V_47 )
{
struct V_76 * V_76 ;
struct V_209 V_210 ;
int V_58 ;
V_76 = F_68 ( V_4 , V_50 , V_130 , & V_211 ,
V_131 , V_47 ) ;
if ( ! V_76 )
return - V_134 ;
V_76 -> V_14 = F_17 ( V_18 -> V_15 ) ;
if ( F_171 ( V_4 , V_212 , V_18 -> V_30 ) ||
F_171 ( V_4 , V_213 , V_18 -> V_20 -> type ) ||
F_144 ( V_4 , V_214 , V_18 -> V_20 -> V_21 ( V_18 ) ) ||
F_171 ( V_4 , V_215 , V_18 -> V_51 ) )
goto V_136;
F_172 ( V_18 , & V_210 ) ;
if ( F_110 ( V_4 , V_216 , sizeof( struct V_209 ) ,
& V_210 ) )
goto V_136;
V_58 = F_173 ( V_18 , V_4 ) ;
if ( V_58 == - V_134 )
goto error;
return F_76 ( V_4 , V_76 ) ;
V_136:
V_58 = - V_134 ;
error:
F_115 ( V_4 , V_76 ) ;
return V_58 ;
}
struct V_3 * F_174 ( struct V_18 * V_18 , T_3 V_50 ,
T_3 V_130 , T_5 V_47 )
{
struct V_3 * V_4 ;
int V_148 ;
V_4 = F_175 ( V_217 , V_81 ) ;
if ( ! V_4 )
return F_119 ( - V_82 ) ;
V_148 = F_170 ( V_18 , V_4 , V_50 , V_130 , 0 , V_47 ) ;
F_120 ( V_148 < 0 ) ;
return V_4 ;
}
static struct V_18 * F_176 ( struct V_13 * V_13 ,
struct V_76 * V_76 ,
struct V_74 * V_96 [ V_218 + 1 ] )
{
struct V_12 * V_15 ;
struct V_18 * V_18 ;
if ( V_96 [ V_214 ] ) {
V_18 = F_147 ( V_13 , F_73 ( V_96 [ V_214 ] ) ) ;
if ( ! V_18 )
return F_119 ( - V_60 ) ;
if ( V_76 -> V_14 &&
V_76 -> V_14 != F_17 ( V_18 -> V_15 ) )
return F_119 ( - V_60 ) ;
return V_18 ;
} else if ( V_96 [ V_212 ] ) {
T_3 V_30 = F_157 ( V_96 [ V_212 ] ) ;
if ( V_30 >= V_219 )
return F_119 ( - V_86 ) ;
V_15 = F_10 ( V_13 , V_76 -> V_14 ) ;
if ( ! V_15 )
return F_119 ( - V_60 ) ;
V_18 = F_16 ( V_15 , V_30 ) ;
if ( ! V_18 )
return F_119 ( - V_60 ) ;
return V_18 ;
} else
return F_119 ( - V_103 ) ;
}
static int F_177 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_74 * * V_96 = V_6 -> V_97 ;
struct V_76 * V_76 = V_6 -> V_95 ;
struct V_33 V_34 ;
struct V_3 * V_153 ;
struct V_18 * V_18 ;
struct V_12 * V_15 ;
T_3 V_30 ;
int V_58 ;
V_58 = - V_103 ;
if ( ! V_96 [ V_214 ] || ! V_96 [ V_213 ] ||
! V_96 [ V_215 ] )
goto exit;
F_4 () ;
V_15 = F_10 ( F_93 ( V_4 -> V_117 ) , V_76 -> V_14 ) ;
V_58 = - V_60 ;
if ( ! V_15 )
goto V_220;
if ( V_96 [ V_212 ] ) {
V_30 = F_157 ( V_96 [ V_212 ] ) ;
V_58 = - V_86 ;
if ( V_30 >= V_219 )
goto V_220;
V_18 = F_160 ( V_15 , V_30 ) ;
V_58 = - V_198 ;
if ( V_18 )
goto V_220;
} else {
for ( V_30 = 1 ; ; V_30 ++ ) {
if ( V_30 >= V_219 ) {
V_58 = - V_86 ;
goto V_220;
}
V_18 = F_160 ( V_15 , V_30 ) ;
if ( ! V_18 )
break;
}
}
V_34 . V_195 = F_73 ( V_96 [ V_214 ] ) ;
V_34 . type = F_157 ( V_96 [ V_213 ] ) ;
V_34 . V_197 = V_96 [ V_221 ] ;
V_34 . V_15 = V_15 ;
V_34 . V_30 = V_30 ;
V_34 . V_51 = F_157 ( V_96 [ V_215 ] ) ;
V_18 = F_30 ( & V_34 ) ;
V_58 = F_56 ( V_18 ) ;
if ( F_32 ( V_18 ) )
goto V_220;
V_58 = 0 ;
V_153 = F_174 ( V_18 , V_6 -> V_7 , V_6 -> V_162 ,
V_222 ) ;
if ( F_32 ( V_153 ) ) {
V_58 = F_56 ( V_153 ) ;
F_34 ( V_18 ) ;
goto V_220;
}
F_1 ( & V_211 , V_153 , V_6 ) ;
V_220:
F_6 () ;
exit:
return V_58 ;
}
static int F_178 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_74 * * V_96 = V_6 -> V_97 ;
struct V_3 * V_153 ;
struct V_18 * V_18 ;
int V_58 ;
F_4 () ;
V_18 = F_176 ( F_93 ( V_4 -> V_117 ) , V_6 -> V_95 , V_96 ) ;
V_58 = F_56 ( V_18 ) ;
if ( F_32 ( V_18 ) )
goto V_220;
if ( V_96 [ V_213 ] &&
F_157 ( V_96 [ V_213 ] ) != V_18 -> V_20 -> type ) {
V_58 = - V_103 ;
goto V_220;
}
V_153 = F_175 ( V_217 , V_9 ) ;
if ( ! V_153 ) {
V_58 = - V_82 ;
goto V_220;
}
if ( V_96 [ V_221 ] ) {
V_58 = F_179 ( V_18 , V_96 [ V_221 ] ) ;
if ( V_58 )
goto V_223;
}
if ( V_96 [ V_215 ] )
V_18 -> V_51 = F_157 ( V_96 [ V_215 ] ) ;
V_58 = F_170 ( V_18 , V_153 , V_6 -> V_7 ,
V_6 -> V_162 , 0 , V_222 ) ;
F_120 ( V_58 < 0 ) ;
F_6 () ;
F_1 ( & V_211 , V_153 , V_6 ) ;
return 0 ;
V_223:
F_42 ( V_153 ) ;
V_220:
F_6 () ;
return V_58 ;
}
static int F_180 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_74 * * V_96 = V_6 -> V_97 ;
struct V_3 * V_153 ;
struct V_18 * V_18 ;
int V_58 ;
F_4 () ;
V_18 = F_176 ( F_93 ( V_4 -> V_117 ) , V_6 -> V_95 , V_96 ) ;
V_58 = F_56 ( V_18 ) ;
if ( F_32 ( V_18 ) )
goto V_220;
if ( V_18 -> V_30 == V_19 ) {
V_58 = - V_103 ;
goto V_220;
}
V_153 = F_174 ( V_18 , V_6 -> V_7 ,
V_6 -> V_162 , V_224 ) ;
V_58 = F_56 ( V_153 ) ;
if ( F_32 ( V_153 ) )
goto V_220;
V_58 = 0 ;
F_34 ( V_18 ) ;
F_1 ( & V_211 , V_153 , V_6 ) ;
V_220:
F_6 () ;
return V_58 ;
}
static int F_181 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_74 * * V_96 = V_6 -> V_97 ;
struct V_76 * V_76 = V_6 -> V_95 ;
struct V_3 * V_153 ;
struct V_18 * V_18 ;
int V_58 ;
F_11 () ;
V_18 = F_176 ( F_93 ( V_4 -> V_117 ) , V_76 , V_96 ) ;
V_58 = F_56 ( V_18 ) ;
if ( F_32 ( V_18 ) )
goto V_220;
V_153 = F_174 ( V_18 , V_6 -> V_7 ,
V_6 -> V_162 , V_222 ) ;
V_58 = F_56 ( V_153 ) ;
if ( F_32 ( V_153 ) )
goto V_220;
F_14 () ;
return F_132 ( V_153 , V_6 ) ;
V_220:
F_14 () ;
return V_58 ;
}
static int F_182 ( struct V_3 * V_4 , struct V_171 * V_172 )
{
struct V_76 * V_76 = F_137 ( F_138 ( V_172 -> V_173 ) ) ;
struct V_12 * V_15 ;
int V_176 = V_172 -> args [ 0 ] , V_208 = V_172 -> args [ 1 ] ;
int V_122 , V_225 = 0 ;
V_15 = F_10 ( F_93 ( V_4 -> V_117 ) , V_76 -> V_14 ) ;
if ( ! V_15 )
return - V_60 ;
F_11 () ;
for ( V_122 = V_176 ; V_122 < V_31 ; V_122 ++ ) {
struct V_18 * V_18 ;
V_225 = 0 ;
F_29 (vport, &dp->ports[i], dp_hash_node) {
if ( V_225 >= V_208 &&
F_170 ( V_18 , V_4 ,
F_141 ( V_172 -> V_4 ) . V_50 ,
V_172 -> V_173 -> V_178 ,
V_179 ,
V_222 ) < 0 )
goto V_53;
V_225 ++ ;
}
V_208 = 0 ;
}
V_53:
F_14 () ;
V_172 -> args [ 0 ] = V_122 ;
V_172 -> args [ 1 ] = V_225 ;
return V_4 -> V_77 ;
}
static void F_183 ( int V_226 )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_226 ; V_122 ++ )
F_184 ( V_227 [ V_122 ] . V_2 ) ;
}
static int F_185 ( void )
{
int V_228 ;
int V_58 ;
int V_122 ;
V_228 = 0 ;
for ( V_122 = 0 ; V_122 < F_186 ( V_227 ) ; V_122 ++ ) {
const struct V_229 * V_230 = & V_227 [ V_122 ] ;
V_230 -> V_2 -> V_20 = V_230 -> V_20 ;
V_230 -> V_2 -> V_231 = V_230 -> V_231 ;
V_230 -> V_2 -> V_232 = V_230 -> V_233 ;
V_230 -> V_2 -> V_234 = V_230 -> V_233 ? 1 : 0 ;
V_58 = F_187 ( V_230 -> V_2 ) ;
if ( V_58 )
goto error;
V_228 ++ ;
}
return 0 ;
error:
F_183 ( V_228 ) ;
return V_58 ;
}
static int T_7 F_188 ( struct V_13 * V_13 )
{
struct V_189 * V_189 = F_158 ( V_13 , V_202 ) ;
F_189 ( & V_189 -> V_204 ) ;
F_190 ( & V_189 -> V_235 , V_236 ) ;
return 0 ;
}
static void T_8 F_191 ( struct V_13 * V_13 )
{
struct V_12 * V_15 , * V_237 ;
struct V_189 * V_189 = F_158 ( V_13 , V_202 ) ;
F_4 () ;
F_192 (dp, dp_next, &ovs_net->dps, list_node)
F_161 ( V_15 ) ;
F_6 () ;
F_193 ( & V_189 -> V_235 ) ;
}
static int T_9 F_194 ( void )
{
int V_58 ;
F_195 ( sizeof( struct V_238 ) > F_196 ( struct V_3 , V_172 ) ) ;
F_197 ( L_4 ) ;
V_58 = F_198 () ;
if ( V_58 )
goto error;
V_58 = F_199 () ;
if ( V_58 )
goto V_239;
V_58 = F_200 ( & V_240 ) ;
if ( V_58 )
goto V_241;
V_58 = F_201 ( & V_242 ) ;
if ( V_58 )
goto V_243;
V_58 = F_185 () ;
if ( V_58 < 0 )
goto V_244;
return 0 ;
V_244:
F_202 ( & V_242 ) ;
V_243:
F_203 ( & V_240 ) ;
V_241:
F_204 () ;
V_239:
F_205 () ;
error:
return V_58 ;
}
static void F_206 ( void )
{
F_183 ( F_186 ( V_227 ) ) ;
F_202 ( & V_242 ) ;
F_203 ( & V_240 ) ;
F_207 () ;
F_204 () ;
F_205 () ;
}
