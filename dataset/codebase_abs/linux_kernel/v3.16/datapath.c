static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return V_2 -> V_5 -> V_6 & V_7 ||
F_2 ( F_3 ( V_2 ) -> V_8 , 0 ) ;
}
static void F_4 ( struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_1 * V_2 )
{
F_5 ( V_10 , V_12 , F_3 ( V_2 ) , V_2 -> V_13 ,
0 , V_2 -> V_5 , V_14 ) ;
}
void F_6 ( void )
{
F_7 ( & V_15 ) ;
}
void F_8 ( void )
{
F_9 ( & V_15 ) ;
}
int F_10 ( void )
{
if ( V_16 )
return F_11 ( & V_15 ) ;
else
return 1 ;
}
static struct V_17 * F_12 ( struct V_18 * V_18 , int V_19 )
{
struct V_17 * V_20 = NULL ;
struct V_21 * V_22 ;
F_13 () ;
V_22 = F_14 ( V_18 , V_19 ) ;
if ( V_22 ) {
struct V_23 * V_23 = F_15 ( V_22 ) ;
if ( V_23 )
V_20 = V_23 -> V_20 ;
}
F_16 () ;
return V_20 ;
}
static const char * F_17 ( const struct V_17 * V_20 )
{
struct V_23 * V_23 = F_18 ( V_20 , V_24 ) ;
return V_23 -> V_25 -> V_26 ( V_23 ) ;
}
static int F_19 ( struct V_17 * V_20 )
{
struct V_23 * V_27 ;
int V_28 ;
F_13 () ;
V_27 = F_20 ( V_20 , V_24 ) ;
if ( V_27 )
V_28 = F_21 ( V_27 ) -> V_22 -> V_28 ;
else
V_28 = 0 ;
F_16 () ;
return V_28 ;
}
static void F_22 ( struct V_29 * V_30 )
{
struct V_17 * V_20 = F_23 ( V_30 , struct V_17 , V_30 ) ;
F_24 ( V_20 -> V_31 ) ;
F_25 ( F_26 ( V_20 ) ) ;
F_27 ( V_20 -> V_32 ) ;
F_27 ( V_20 ) ;
}
static struct V_33 * F_28 ( const struct V_17 * V_20 ,
T_1 V_34 )
{
return & V_20 -> V_32 [ V_34 & ( V_35 - 1 ) ] ;
}
struct V_23 * F_29 ( const struct V_17 * V_20 , T_1 V_34 )
{
struct V_23 * V_23 ;
struct V_33 * V_36 ;
V_36 = F_28 ( V_20 , V_34 ) ;
F_30 (vport, head, dp_hash_node) {
if ( V_23 -> V_34 == V_34 )
return V_23 ;
}
return NULL ;
}
static struct V_23 * F_31 ( const struct V_37 * V_38 )
{
struct V_23 * V_23 ;
V_23 = F_32 ( V_38 ) ;
if ( ! F_33 ( V_23 ) ) {
struct V_17 * V_20 = V_38 -> V_20 ;
struct V_33 * V_36 = F_28 ( V_20 , V_23 -> V_34 ) ;
F_34 ( & V_23 -> V_39 , V_36 ) ;
}
return V_23 ;
}
void F_35 ( struct V_23 * V_40 )
{
F_36 () ;
F_37 ( & V_40 -> V_39 ) ;
F_38 ( V_40 ) ;
}
void F_39 ( struct V_23 * V_40 , struct V_11 * V_12 )
{
struct V_17 * V_20 = V_40 -> V_20 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
T_2 * V_47 ;
T_3 V_48 ;
int error ;
V_44 = F_40 ( V_20 -> V_31 ) ;
error = F_41 ( V_12 , V_40 -> V_34 , & V_46 ) ;
if ( F_42 ( error ) ) {
F_43 ( V_12 ) ;
return;
}
V_42 = F_44 ( & V_20 -> V_49 , & V_46 , & V_48 ) ;
if ( F_42 ( ! V_42 ) ) {
struct V_50 V_51 ;
V_51 . V_52 = V_53 ;
V_51 . V_46 = & V_46 ;
V_51 . V_54 = NULL ;
V_51 . V_55 = V_40 -> V_56 ;
F_45 ( V_20 , V_12 , & V_51 ) ;
F_46 ( V_12 ) ;
V_47 = & V_44 -> V_57 ;
goto V_58;
}
F_47 ( V_12 ) -> V_42 = V_42 ;
F_47 ( V_12 ) -> V_59 = & V_46 ;
F_48 ( F_47 ( V_12 ) -> V_42 , V_46 . V_60 . V_61 , V_12 ) ;
F_49 ( V_20 , V_12 ) ;
V_47 = & V_44 -> V_62 ;
V_58:
F_50 ( & V_44 -> V_63 ) ;
( * V_47 ) ++ ;
V_44 -> V_48 += V_48 ;
F_51 ( & V_44 -> V_63 ) ;
}
int F_45 ( struct V_17 * V_20 , struct V_11 * V_12 ,
const struct V_50 * V_64 )
{
struct V_43 * V_44 ;
int V_65 ;
if ( V_64 -> V_55 == 0 ) {
V_65 = - V_66 ;
goto V_65;
}
if ( ! F_52 ( V_12 ) )
V_65 = F_53 ( V_20 , V_12 , V_64 ) ;
else
V_65 = F_54 ( V_20 , V_12 , V_64 ) ;
if ( V_65 )
goto V_65;
return 0 ;
V_65:
V_44 = F_40 ( V_20 -> V_31 ) ;
F_50 ( & V_44 -> V_63 ) ;
V_44 -> V_67 ++ ;
F_51 ( & V_44 -> V_63 ) ;
return V_65 ;
}
static int F_54 ( struct V_17 * V_20 , struct V_11 * V_12 ,
const struct V_50 * V_64 )
{
unsigned short V_68 = F_55 ( V_12 ) -> V_68 ;
struct V_50 V_69 ;
struct V_45 V_70 ;
struct V_11 * V_71 , * V_72 ;
int V_65 ;
V_71 = F_56 ( V_12 , V_73 , false ) ;
if ( F_33 ( V_71 ) )
return F_57 ( V_71 ) ;
V_12 = V_71 ;
do {
V_65 = F_53 ( V_20 , V_12 , V_64 ) ;
if ( V_65 )
break;
if ( V_12 == V_71 && V_68 & V_74 ) {
V_70 = * V_64 -> V_46 ;
V_70 . V_75 . V_76 = V_77 ;
V_69 = * V_64 ;
V_69 . V_46 = & V_70 ;
V_64 = & V_69 ;
}
} while ( ( V_12 = V_12 -> V_78 ) );
V_12 = V_71 ;
do {
V_72 = V_12 -> V_78 ;
if ( V_65 )
F_43 ( V_12 ) ;
else
F_46 ( V_12 ) ;
} while ( ( V_12 = V_72 ) );
return V_65 ;
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
static T_4 F_60 ( const struct V_79 * V_54 ,
unsigned int V_80 )
{
T_4 V_81 = F_61 ( sizeof( struct V_82 ) )
+ F_59 ( V_80 )
+ F_59 ( F_58 () ) ;
if ( V_54 )
V_81 += F_62 ( V_54 -> V_83 ) ;
return V_81 ;
}
static int F_53 ( struct V_17 * V_20 , struct V_11 * V_12 ,
const struct V_50 * V_64 )
{
struct V_82 * V_51 ;
struct V_11 * V_72 = NULL ;
struct V_11 * V_84 ;
struct V_79 * V_85 ;
struct V_1 V_2 = {
. V_86 = F_26 ( V_20 ) -> V_8 ,
. V_13 = V_64 -> V_55 ,
} ;
T_4 V_87 ;
unsigned int V_88 ;
int V_65 , V_19 ;
V_19 = F_19 ( V_20 ) ;
if ( ! V_19 )
return - V_89 ;
if ( F_63 ( V_12 ) ) {
V_72 = F_64 ( V_12 , V_90 ) ;
if ( ! V_72 )
return - V_91 ;
V_72 = F_65 ( V_72 , V_72 -> V_92 , F_66 ( V_72 ) ) ;
if ( ! V_72 )
return - V_91 ;
V_72 -> V_93 = 0 ;
V_12 = V_72 ;
}
if ( F_67 ( V_12 -> V_87 ) > V_94 ) {
V_65 = - V_95 ;
goto V_58;
}
if ( V_12 -> V_96 == V_97 &&
( V_65 = F_68 ( V_12 ) ) )
goto V_58;
if ( V_20 -> V_98 & V_99 )
V_88 = F_69 ( V_12 ) ;
else
V_88 = V_12 -> V_87 ;
V_87 = F_60 ( V_64 -> V_54 , V_88 ) ;
V_84 = F_70 ( V_87 , & V_2 , V_90 ) ;
if ( ! V_84 ) {
V_65 = - V_91 ;
goto V_58;
}
V_51 = F_71 ( V_84 , 0 , 0 , & V_100 ,
0 , V_64 -> V_52 ) ;
V_51 -> V_19 = V_19 ;
V_85 = F_72 ( V_84 , V_101 ) ;
F_73 ( V_64 -> V_46 , V_64 -> V_46 , V_84 ) ;
F_74 ( V_84 , V_85 ) ;
if ( V_64 -> V_54 )
F_75 ( V_84 , V_102 ,
V_83 ( V_64 -> V_54 ) ,
F_76 ( V_64 -> V_54 ) ) ;
if ( ! ( V_85 = F_77 ( V_84 , V_103 , 0 ) ) ) {
V_65 = - V_104 ;
goto V_58;
}
V_85 -> V_83 = F_67 ( V_12 -> V_87 ) ;
V_65 = F_78 ( V_84 , V_12 , V_12 -> V_87 , V_88 ) ;
if ( V_65 )
goto V_58;
if ( ! ( V_20 -> V_98 & V_99 ) ) {
T_4 V_105 = F_62 ( V_84 -> V_87 ) - V_84 -> V_87 ;
if ( V_105 > 0 )
memset ( F_79 ( V_84 , V_105 ) , 0 , V_105 ) ;
}
( (struct V_106 * ) V_84 -> V_107 ) -> V_108 = V_84 -> V_87 ;
V_65 = F_80 ( F_26 ( V_20 ) , V_84 , V_64 -> V_55 ) ;
V_58:
if ( V_65 )
F_81 ( V_12 ) ;
F_43 ( V_72 ) ;
return V_65 ;
}
static int F_82 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_82 * V_82 = V_2 -> V_109 ;
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_112 * V_113 ;
struct V_11 * V_114 ;
struct V_41 * V_42 ;
struct V_17 * V_20 ;
struct V_115 * V_116 ;
int V_87 ;
int V_65 ;
V_65 = - V_117 ;
if ( ! V_110 [ V_103 ] || ! V_110 [ V_101 ] ||
! V_110 [ V_118 ] )
goto V_65;
V_87 = V_83 ( V_110 [ V_103 ] ) ;
V_114 = F_83 ( V_119 + V_87 , V_14 ) ;
V_65 = - V_91 ;
if ( ! V_114 )
goto V_65;
F_84 ( V_114 , V_119 ) ;
F_85 ( F_86 ( V_114 , V_87 ) , V_110 [ V_103 ] , V_87 ) ;
F_87 ( V_114 ) ;
V_116 = F_88 ( V_114 ) ;
if ( F_89 ( V_116 -> V_120 ) >= V_121 )
V_114 -> V_122 = V_116 -> V_120 ;
else
V_114 -> V_122 = F_90 ( V_123 ) ;
V_42 = F_91 () ;
V_65 = F_57 ( V_42 ) ;
if ( F_33 ( V_42 ) )
goto V_124;
V_65 = F_41 ( V_114 , - 1 , & V_42 -> V_46 ) ;
if ( V_65 )
goto V_125;
V_65 = F_92 ( V_42 , V_110 [ V_101 ] ) ;
if ( V_65 )
goto V_125;
V_113 = F_93 ( V_83 ( V_110 [ V_118 ] ) ) ;
V_65 = F_57 ( V_113 ) ;
if ( F_33 ( V_113 ) )
goto V_125;
V_65 = F_94 ( V_110 [ V_118 ] ,
& V_42 -> V_46 , 0 , & V_113 ) ;
F_95 ( V_42 -> V_126 , V_113 ) ;
if ( V_65 )
goto V_125;
F_47 ( V_114 ) -> V_42 = V_42 ;
F_47 ( V_114 ) -> V_59 = & V_42 -> V_46 ;
V_114 -> V_127 = V_42 -> V_46 . V_128 . V_127 ;
V_114 -> V_129 = V_42 -> V_46 . V_128 . V_130 ;
F_13 () ;
V_20 = F_12 ( F_96 ( V_12 -> V_131 ) , V_82 -> V_19 ) ;
V_65 = - V_89 ;
if ( ! V_20 )
goto V_132;
F_97 () ;
V_65 = F_49 ( V_20 , V_114 ) ;
F_98 () ;
F_16 () ;
F_99 ( V_42 , false ) ;
return V_65 ;
V_132:
F_16 () ;
V_125:
F_99 ( V_42 , false ) ;
V_124:
F_43 ( V_114 ) ;
V_65:
return V_65 ;
}
static void F_100 ( struct V_17 * V_20 , struct V_133 * V_44 ,
struct V_134 * V_135 )
{
int V_136 ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
V_44 -> V_137 = F_101 ( & V_20 -> V_49 ) ;
V_135 -> V_138 = F_102 ( & V_20 -> V_49 ) ;
V_44 -> V_62 = V_44 -> V_57 = V_44 -> V_67 = 0 ;
F_103 (i) {
const struct V_43 * V_139 ;
struct V_43 V_140 ;
unsigned int V_141 ;
V_139 = F_104 ( V_20 -> V_31 , V_136 ) ;
do {
V_141 = F_105 ( & V_139 -> V_63 ) ;
V_140 = * V_139 ;
} while ( F_106 ( & V_139 -> V_63 , V_141 ) );
V_44 -> V_62 += V_140 . V_62 ;
V_44 -> V_57 += V_140 . V_57 ;
V_44 -> V_67 += V_140 . V_67 ;
V_135 -> V_48 += V_140 . V_48 ;
}
}
static T_4 F_107 ( const struct V_112 * V_113 )
{
return F_61 ( sizeof( struct V_82 ) )
+ F_59 ( F_58 () )
+ F_59 ( F_58 () )
+ F_59 ( sizeof( struct V_142 ) )
+ F_59 ( 1 )
+ F_59 ( 8 )
+ F_59 ( V_113 -> V_143 ) ;
}
static int F_108 ( const struct V_41 * V_42 , int V_19 ,
struct V_11 * V_12 , T_3 V_55 ,
T_3 V_144 , T_3 V_61 , T_5 V_52 )
{
const int V_145 = V_12 -> V_87 ;
struct V_79 * V_141 ;
struct V_142 V_44 ;
T_6 V_146 ;
unsigned long V_147 ;
struct V_82 * V_82 ;
struct V_79 * V_85 ;
int V_65 ;
V_82 = F_71 ( V_12 , V_55 , V_144 , & V_148 , V_61 , V_52 ) ;
if ( ! V_82 )
return - V_149 ;
V_82 -> V_19 = V_19 ;
V_85 = F_72 ( V_12 , V_150 ) ;
if ( ! V_85 )
goto V_151;
V_65 = F_73 ( & V_42 -> V_152 , & V_42 -> V_152 , V_12 ) ;
if ( V_65 )
goto error;
F_74 ( V_12 , V_85 ) ;
V_85 = F_72 ( V_12 , V_153 ) ;
if ( ! V_85 )
goto V_151;
V_65 = F_73 ( & V_42 -> V_46 , & V_42 -> V_154 -> V_46 , V_12 ) ;
if ( V_65 )
goto error;
F_74 ( V_12 , V_85 ) ;
F_109 ( V_42 , & V_44 , & V_147 , & V_146 ) ;
if ( V_147 &&
F_110 ( V_12 , V_155 , F_111 ( V_147 ) ) )
goto V_151;
if ( V_44 . V_156 &&
F_112 ( V_12 , V_157 , sizeof( struct V_142 ) , & V_44 ) )
goto V_151;
if ( ( T_5 ) F_89 ( V_146 ) &&
F_113 ( V_12 , V_158 , ( T_5 ) F_89 ( V_146 ) ) )
goto V_151;
V_141 = F_72 ( V_12 , V_159 ) ;
if ( V_141 ) {
const struct V_112 * V_126 ;
V_126 = F_114 ( V_42 -> V_126 ) ;
V_65 = F_115 ( V_126 -> V_160 ,
V_126 -> V_143 , V_12 ) ;
if ( ! V_65 )
F_74 ( V_12 , V_141 ) ;
else {
if ( V_145 )
goto error;
F_116 ( V_12 , V_141 ) ;
}
} else if ( V_145 )
goto V_151;
return F_117 ( V_12 , V_82 ) ;
V_151:
V_65 = - V_149 ;
error:
F_118 ( V_12 , V_82 ) ;
return V_65 ;
}
static struct V_11 * F_119 ( const struct V_112 * V_113 ,
struct V_1 * V_2 ,
bool V_161 )
{
struct V_11 * V_12 ;
if ( ! V_161 && ! F_1 ( V_2 , & V_162 ) )
return NULL ;
V_12 = F_70 ( F_107 ( V_113 ) , V_2 , V_14 ) ;
if ( ! V_12 )
return F_120 ( - V_91 ) ;
return V_12 ;
}
static struct V_11 * F_121 ( const struct V_41 * V_42 ,
int V_19 ,
struct V_1 * V_2 , T_5 V_52 ,
bool V_161 )
{
struct V_11 * V_12 ;
int V_163 ;
V_12 = F_119 ( F_122 ( V_42 -> V_126 ) , V_2 ,
V_161 ) ;
if ( ! V_12 || F_33 ( V_12 ) )
return V_12 ;
V_163 = F_108 ( V_42 , V_19 , V_12 ,
V_2 -> V_13 , V_2 -> V_164 , 0 ,
V_52 ) ;
F_123 ( V_163 < 0 ) ;
return V_12 ;
}
static int F_124 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_82 * V_82 = V_2 -> V_109 ;
struct V_41 * V_42 , * V_165 ;
struct V_166 V_154 ;
struct V_11 * V_167 ;
struct V_17 * V_20 ;
struct V_112 * V_113 ;
struct V_168 V_169 ;
int error ;
error = - V_117 ;
if ( ! V_110 [ V_150 ] )
goto error;
if ( ! V_110 [ V_159 ] )
goto error;
V_165 = F_91 () ;
if ( F_33 ( V_165 ) ) {
error = F_57 ( V_165 ) ;
goto error;
}
F_125 ( & V_169 , & V_165 -> V_152 , & V_154 ) ;
error = F_126 ( & V_169 ,
V_110 [ V_150 ] , V_110 [ V_153 ] ) ;
if ( error )
goto V_170;
F_127 ( & V_165 -> V_46 , & V_165 -> V_152 , & V_154 ) ;
V_113 = F_93 ( V_83 ( V_110 [ V_159 ] ) ) ;
error = F_57 ( V_113 ) ;
if ( F_33 ( V_113 ) )
goto V_170;
error = F_94 ( V_110 [ V_159 ] , & V_165 -> V_46 ,
0 , & V_113 ) ;
if ( error ) {
F_128 ( L_1 ) ;
goto V_171;
}
V_167 = F_119 ( V_113 , V_2 , false ) ;
if ( F_33 ( V_167 ) ) {
error = F_57 ( V_167 ) ;
goto V_171;
}
F_6 () ;
V_20 = F_12 ( F_96 ( V_12 -> V_131 ) , V_82 -> V_19 ) ;
if ( F_42 ( ! V_20 ) ) {
error = - V_89 ;
goto V_172;
}
V_42 = F_129 ( & V_20 -> V_49 , & V_165 -> V_152 ) ;
if ( F_130 ( ! V_42 ) ) {
F_95 ( V_165 -> V_126 , V_113 ) ;
error = F_131 ( & V_20 -> V_49 , V_165 , & V_154 ) ;
if ( F_42 ( error ) ) {
V_113 = NULL ;
goto V_172;
}
if ( F_42 ( V_167 ) ) {
error = F_108 ( V_165 ,
V_82 -> V_19 ,
V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 ,
V_173 ) ;
F_123 ( error < 0 ) ;
}
F_8 () ;
} else {
struct V_112 * V_174 ;
if ( F_42 ( V_2 -> V_5 -> V_6 & ( V_175
| V_176 ) ) ) {
error = - V_177 ;
goto V_172;
}
if ( F_42 ( ! F_132 ( V_42 , & V_169 ) ) ) {
V_42 = F_133 ( & V_20 -> V_49 , & V_169 ) ;
if ( ! V_42 ) {
error = - V_178 ;
goto V_172;
}
}
V_174 = F_122 ( V_42 -> V_126 ) ;
F_95 ( V_42 -> V_126 , V_113 ) ;
if ( F_42 ( V_167 ) ) {
error = F_108 ( V_42 ,
V_82 -> V_19 ,
V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 ,
V_173 ) ;
F_123 ( error < 0 ) ;
}
F_8 () ;
F_134 ( V_174 ) ;
F_99 ( V_165 , false ) ;
}
if ( V_167 )
F_4 ( & V_148 , V_167 , V_2 ) ;
return 0 ;
V_172:
F_8 () ;
F_43 ( V_167 ) ;
V_171:
F_27 ( V_113 ) ;
V_170:
F_99 ( V_165 , false ) ;
error:
return error ;
}
static int F_135 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_82 * V_82 = V_2 -> V_109 ;
struct V_45 V_46 , V_179 ;
struct V_41 * V_42 ;
struct V_166 V_154 ;
struct V_11 * V_167 = NULL ;
struct V_17 * V_20 ;
struct V_112 * V_174 = NULL , * V_113 = NULL ;
struct V_168 V_169 ;
int error ;
error = - V_117 ;
if ( ! V_110 [ V_150 ] )
goto error;
F_125 ( & V_169 , & V_46 , & V_154 ) ;
error = F_126 ( & V_169 ,
V_110 [ V_150 ] , V_110 [ V_153 ] ) ;
if ( error )
goto error;
if ( V_110 [ V_159 ] ) {
V_113 = F_93 ( V_83 ( V_110 [ V_159 ] ) ) ;
error = F_57 ( V_113 ) ;
if ( F_33 ( V_113 ) )
goto error;
F_127 ( & V_179 , & V_46 , & V_154 ) ;
error = F_94 ( V_110 [ V_159 ] ,
& V_179 , 0 , & V_113 ) ;
if ( error ) {
F_128 ( L_1 ) ;
goto V_171;
}
}
if ( V_113 ) {
V_167 = F_119 ( V_113 , V_2 , false ) ;
if ( F_33 ( V_167 ) ) {
error = F_57 ( V_167 ) ;
goto V_171;
}
}
F_6 () ;
V_20 = F_12 ( F_96 ( V_12 -> V_131 ) , V_82 -> V_19 ) ;
if ( F_42 ( ! V_20 ) ) {
error = - V_89 ;
goto V_172;
}
V_42 = F_133 ( & V_20 -> V_49 , & V_169 ) ;
if ( F_42 ( ! V_42 ) ) {
error = - V_178 ;
goto V_172;
}
if ( F_130 ( V_113 ) ) {
V_174 = F_122 ( V_42 -> V_126 ) ;
F_95 ( V_42 -> V_126 , V_113 ) ;
if ( F_42 ( V_167 ) ) {
error = F_108 ( V_42 ,
V_82 -> V_19 ,
V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 ,
V_173 ) ;
F_123 ( error < 0 ) ;
}
} else {
V_167 = F_121 ( V_42 , V_82 -> V_19 ,
V_2 , V_173 , false ) ;
if ( F_42 ( F_33 ( V_167 ) ) ) {
error = F_57 ( V_167 ) ;
goto V_172;
}
}
if ( V_110 [ V_180 ] )
F_136 ( V_42 ) ;
F_8 () ;
if ( V_167 )
F_4 ( & V_148 , V_167 , V_2 ) ;
if ( V_174 )
F_134 ( V_174 ) ;
return 0 ;
V_172:
F_8 () ;
F_43 ( V_167 ) ;
V_171:
F_27 ( V_113 ) ;
error:
return error ;
}
static int F_137 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_82 * V_82 = V_2 -> V_109 ;
struct V_45 V_46 ;
struct V_11 * V_167 ;
struct V_41 * V_42 ;
struct V_17 * V_20 ;
struct V_168 V_169 ;
int V_65 ;
if ( ! V_110 [ V_150 ] ) {
F_128 ( L_2 ) ;
return - V_117 ;
}
F_125 ( & V_169 , & V_46 , NULL ) ;
V_65 = F_126 ( & V_169 , V_110 [ V_150 ] , NULL ) ;
if ( V_65 )
return V_65 ;
F_6 () ;
V_20 = F_12 ( F_96 ( V_12 -> V_131 ) , V_82 -> V_19 ) ;
if ( ! V_20 ) {
V_65 = - V_89 ;
goto V_181;
}
V_42 = F_133 ( & V_20 -> V_49 , & V_169 ) ;
if ( ! V_42 ) {
V_65 = - V_178 ;
goto V_181;
}
V_167 = F_121 ( V_42 , V_82 -> V_19 , V_2 ,
V_173 , true ) ;
if ( F_33 ( V_167 ) ) {
V_65 = F_57 ( V_167 ) ;
goto V_181;
}
F_8 () ;
return F_138 ( V_167 , V_2 ) ;
V_181:
F_8 () ;
return V_65 ;
}
static int F_139 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_82 * V_82 = V_2 -> V_109 ;
struct V_45 V_46 ;
struct V_11 * V_167 ;
struct V_41 * V_42 ;
struct V_17 * V_20 ;
struct V_168 V_169 ;
int V_65 ;
if ( F_130 ( V_110 [ V_150 ] ) ) {
F_125 ( & V_169 , & V_46 , NULL ) ;
V_65 = F_126 ( & V_169 , V_110 [ V_150 ] , NULL ) ;
if ( F_42 ( V_65 ) )
return V_65 ;
}
F_6 () ;
V_20 = F_12 ( F_96 ( V_12 -> V_131 ) , V_82 -> V_19 ) ;
if ( F_42 ( ! V_20 ) ) {
V_65 = - V_89 ;
goto V_181;
}
if ( F_42 ( ! V_110 [ V_150 ] ) ) {
V_65 = F_140 ( & V_20 -> V_49 ) ;
goto V_181;
}
V_42 = F_133 ( & V_20 -> V_49 , & V_169 ) ;
if ( F_42 ( ! V_42 ) ) {
V_65 = - V_178 ;
goto V_181;
}
F_141 ( & V_20 -> V_49 , V_42 ) ;
F_8 () ;
V_167 = F_119 ( ( const struct V_112 V_182 * ) V_42 -> V_126 ,
V_2 , false ) ;
if ( F_130 ( V_167 ) ) {
if ( F_130 ( ! F_33 ( V_167 ) ) ) {
F_13 () ;
V_65 = F_108 ( V_42 , V_82 -> V_19 ,
V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 ,
V_183 ) ;
F_16 () ;
F_123 ( V_65 < 0 ) ;
F_4 ( & V_148 , V_167 , V_2 ) ;
} else {
F_142 ( F_96 ( V_12 -> V_131 ) -> V_8 , 0 , 0 , F_57 ( V_167 ) ) ;
}
}
F_99 ( V_42 , true ) ;
return 0 ;
V_181:
F_8 () ;
return V_65 ;
}
static int F_143 ( struct V_11 * V_12 , struct V_184 * V_185 )
{
struct V_82 * V_82 = F_144 ( F_145 ( V_185 -> V_186 ) ) ;
struct V_187 * V_188 ;
struct V_17 * V_20 ;
F_13 () ;
V_20 = F_12 ( F_96 ( V_12 -> V_131 ) , V_82 -> V_19 ) ;
if ( ! V_20 ) {
F_16 () ;
return - V_89 ;
}
V_188 = F_146 ( V_20 -> V_49 . V_188 ) ;
for (; ; ) {
struct V_41 * V_42 ;
T_3 V_189 , V_190 ;
V_189 = V_185 -> args [ 0 ] ;
V_190 = V_185 -> args [ 1 ] ;
V_42 = F_147 ( V_188 , & V_189 , & V_190 ) ;
if ( ! V_42 )
break;
if ( F_108 ( V_42 , V_82 -> V_19 , V_12 ,
F_148 ( V_185 -> V_12 ) . V_55 ,
V_185 -> V_186 -> V_191 , V_192 ,
V_173 ) < 0 )
break;
V_185 -> args [ 0 ] = V_189 ;
V_185 -> args [ 1 ] = V_190 ;
}
F_16 () ;
return V_12 -> V_87 ;
}
static T_4 F_149 ( void )
{
T_4 V_193 = F_61 ( sizeof( struct V_82 ) ) ;
V_193 += F_59 ( V_194 ) ;
V_193 += F_59 ( sizeof( struct V_133 ) ) ;
V_193 += F_59 ( sizeof( struct V_134 ) ) ;
V_193 += F_59 ( sizeof( T_3 ) ) ;
return V_193 ;
}
static int F_150 ( struct V_17 * V_20 , struct V_11 * V_12 ,
T_3 V_55 , T_3 V_144 , T_3 V_61 , T_5 V_52 )
{
struct V_82 * V_82 ;
struct V_133 V_195 ;
struct V_134 V_196 ;
int V_65 ;
V_82 = F_71 ( V_12 , V_55 , V_144 , & V_197 ,
V_61 , V_52 ) ;
if ( ! V_82 )
goto error;
V_82 -> V_19 = F_19 ( V_20 ) ;
V_65 = F_151 ( V_12 , V_198 , F_17 ( V_20 ) ) ;
if ( V_65 )
goto V_151;
F_100 ( V_20 , & V_195 , & V_196 ) ;
if ( F_112 ( V_12 , V_199 , sizeof( struct V_133 ) ,
& V_195 ) )
goto V_151;
if ( F_112 ( V_12 , V_200 ,
sizeof( struct V_134 ) ,
& V_196 ) )
goto V_151;
if ( F_152 ( V_12 , V_201 , V_20 -> V_98 ) )
goto V_151;
return F_117 ( V_12 , V_82 ) ;
V_151:
F_118 ( V_12 , V_82 ) ;
error:
return - V_149 ;
}
static struct V_11 * F_153 ( struct V_1 * V_2 )
{
return F_70 ( F_149 () , V_2 , V_14 ) ;
}
static struct V_17 * F_154 ( struct V_18 * V_18 ,
struct V_82 * V_82 ,
struct V_79 * V_110 [ V_202 + 1 ] )
{
struct V_17 * V_20 ;
if ( ! V_110 [ V_198 ] )
V_20 = F_12 ( V_18 , V_82 -> V_19 ) ;
else {
struct V_23 * V_23 ;
V_23 = F_155 ( V_18 , F_76 ( V_110 [ V_198 ] ) ) ;
V_20 = V_23 && V_23 -> V_34 == V_24 ? V_23 -> V_20 : NULL ;
}
return V_20 ? V_20 : F_120 ( - V_89 ) ;
}
static void F_156 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_17 * V_20 ;
V_20 = F_154 ( F_96 ( V_12 -> V_131 ) , V_2 -> V_109 , V_2 -> V_111 ) ;
if ( F_33 ( V_20 ) )
return;
F_157 ( V_20 -> V_98 , L_3 ) ;
V_20 -> V_98 = 0 ;
}
static void F_158 ( struct V_17 * V_20 , struct V_79 * * V_110 )
{
if ( V_110 [ V_201 ] )
V_20 -> V_98 = F_159 ( V_110 [ V_201 ] ) ;
}
static int F_160 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_37 V_38 ;
struct V_11 * V_167 ;
struct V_17 * V_20 ;
struct V_23 * V_23 ;
struct V_203 * V_203 ;
int V_65 , V_136 ;
V_65 = - V_117 ;
if ( ! V_110 [ V_198 ] || ! V_110 [ V_204 ] )
goto V_65;
V_167 = F_153 ( V_2 ) ;
if ( ! V_167 )
return - V_91 ;
V_65 = - V_91 ;
V_20 = F_161 ( sizeof( * V_20 ) , V_14 ) ;
if ( V_20 == NULL )
goto V_205;
F_162 ( V_20 , F_163 ( F_96 ( V_12 -> V_131 ) ) ) ;
V_65 = F_164 ( & V_20 -> V_49 ) ;
if ( V_65 )
goto V_206;
V_20 -> V_31 = F_165 ( struct V_43 ) ;
if ( ! V_20 -> V_31 ) {
V_65 = - V_91 ;
goto V_207;
}
V_20 -> V_32 = F_166 ( V_35 * sizeof( struct V_33 ) ,
V_14 ) ;
if ( ! V_20 -> V_32 ) {
V_65 = - V_91 ;
goto V_208;
}
for ( V_136 = 0 ; V_136 < V_35 ; V_136 ++ )
F_167 ( & V_20 -> V_32 [ V_136 ] ) ;
V_38 . V_209 = F_76 ( V_110 [ V_198 ] ) ;
V_38 . type = V_210 ;
V_38 . V_211 = NULL ;
V_38 . V_20 = V_20 ;
V_38 . V_34 = V_24 ;
V_38 . V_56 = F_159 ( V_110 [ V_204 ] ) ;
F_158 ( V_20 , V_110 ) ;
F_6 () ;
V_23 = F_31 ( & V_38 ) ;
if ( F_33 ( V_23 ) ) {
V_65 = F_57 ( V_23 ) ;
if ( V_65 == - V_212 )
V_65 = - V_177 ;
if ( V_65 == - V_177 ) {
if ( V_2 -> V_213 -> V_214 < V_215 )
F_156 ( V_12 , V_2 ) ;
}
goto V_216;
}
V_65 = F_150 ( V_20 , V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 , V_217 ) ;
F_123 ( V_65 < 0 ) ;
V_203 = F_168 ( F_26 ( V_20 ) , V_218 ) ;
F_169 ( & V_20 -> V_219 , & V_203 -> V_220 ) ;
F_8 () ;
F_4 ( & V_197 , V_167 , V_2 ) ;
return 0 ;
V_216:
F_8 () ;
F_27 ( V_20 -> V_32 ) ;
V_208:
F_24 ( V_20 -> V_31 ) ;
V_207:
F_170 ( & V_20 -> V_49 , false ) ;
V_206:
F_25 ( F_26 ( V_20 ) ) ;
F_27 ( V_20 ) ;
V_205:
F_43 ( V_167 ) ;
V_65:
return V_65 ;
}
static void F_171 ( struct V_17 * V_20 )
{
int V_136 ;
for ( V_136 = 0 ; V_136 < V_35 ; V_136 ++ ) {
struct V_23 * V_23 ;
struct V_221 * V_222 ;
F_172 (vport, n, &dp->ports[i], dp_hash_node)
if ( V_23 -> V_34 != V_24 )
F_35 ( V_23 ) ;
}
F_173 ( & V_20 -> V_219 ) ;
F_35 ( F_174 ( V_20 , V_24 ) ) ;
F_170 ( & V_20 -> V_49 , true ) ;
F_175 ( & V_20 -> V_30 , F_22 ) ;
}
static int F_176 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_11 * V_167 ;
struct V_17 * V_20 ;
int V_65 ;
V_167 = F_153 ( V_2 ) ;
if ( ! V_167 )
return - V_91 ;
F_6 () ;
V_20 = F_154 ( F_96 ( V_12 -> V_131 ) , V_2 -> V_109 , V_2 -> V_111 ) ;
V_65 = F_57 ( V_20 ) ;
if ( F_33 ( V_20 ) )
goto V_223;
V_65 = F_150 ( V_20 , V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 , V_224 ) ;
F_123 ( V_65 < 0 ) ;
F_171 ( V_20 ) ;
F_8 () ;
F_4 ( & V_197 , V_167 , V_2 ) ;
return 0 ;
V_223:
F_8 () ;
F_43 ( V_167 ) ;
return V_65 ;
}
static int F_177 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_11 * V_167 ;
struct V_17 * V_20 ;
int V_65 ;
V_167 = F_153 ( V_2 ) ;
if ( ! V_167 )
return - V_91 ;
F_6 () ;
V_20 = F_154 ( F_96 ( V_12 -> V_131 ) , V_2 -> V_109 , V_2 -> V_111 ) ;
V_65 = F_57 ( V_20 ) ;
if ( F_33 ( V_20 ) )
goto V_223;
F_158 ( V_20 , V_2 -> V_111 ) ;
V_65 = F_150 ( V_20 , V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 , V_217 ) ;
F_123 ( V_65 < 0 ) ;
F_8 () ;
F_4 ( & V_197 , V_167 , V_2 ) ;
return 0 ;
V_223:
F_8 () ;
F_43 ( V_167 ) ;
return V_65 ;
}
static int F_178 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_11 * V_167 ;
struct V_17 * V_20 ;
int V_65 ;
V_167 = F_153 ( V_2 ) ;
if ( ! V_167 )
return - V_91 ;
F_13 () ;
V_20 = F_154 ( F_96 ( V_12 -> V_131 ) , V_2 -> V_109 , V_2 -> V_111 ) ;
if ( F_33 ( V_20 ) ) {
V_65 = F_57 ( V_20 ) ;
goto V_223;
}
V_65 = F_150 ( V_20 , V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 , V_217 ) ;
F_123 ( V_65 < 0 ) ;
F_16 () ;
return F_138 ( V_167 , V_2 ) ;
V_223:
F_16 () ;
F_43 ( V_167 ) ;
return V_65 ;
}
static int F_179 ( struct V_11 * V_12 , struct V_184 * V_185 )
{
struct V_203 * V_203 = F_168 ( F_96 ( V_12 -> V_131 ) , V_218 ) ;
struct V_17 * V_20 ;
int V_225 = V_185 -> args [ 0 ] ;
int V_136 = 0 ;
F_13 () ;
F_180 (dp, &ovs_net->dps, list_node) {
if ( V_136 >= V_225 &&
F_150 ( V_20 , V_12 , F_148 ( V_185 -> V_12 ) . V_55 ,
V_185 -> V_186 -> V_191 , V_192 ,
V_217 ) < 0 )
break;
V_136 ++ ;
}
F_16 () ;
V_185 -> args [ 0 ] = V_136 ;
return V_12 -> V_87 ;
}
static int F_181 ( struct V_23 * V_23 , struct V_11 * V_12 ,
T_3 V_55 , T_3 V_144 , T_3 V_61 , T_5 V_52 )
{
struct V_82 * V_82 ;
struct V_226 V_227 ;
int V_65 ;
V_82 = F_71 ( V_12 , V_55 , V_144 , & V_228 ,
V_61 , V_52 ) ;
if ( ! V_82 )
return - V_149 ;
V_82 -> V_19 = F_19 ( V_23 -> V_20 ) ;
if ( F_152 ( V_12 , V_229 , V_23 -> V_34 ) ||
F_152 ( V_12 , V_230 , V_23 -> V_25 -> type ) ||
F_151 ( V_12 , V_231 , V_23 -> V_25 -> V_26 ( V_23 ) ) ||
F_152 ( V_12 , V_232 , V_23 -> V_56 ) )
goto V_151;
F_182 ( V_23 , & V_227 ) ;
if ( F_112 ( V_12 , V_233 , sizeof( struct V_226 ) ,
& V_227 ) )
goto V_151;
V_65 = F_183 ( V_23 , V_12 ) ;
if ( V_65 == - V_149 )
goto error;
return F_117 ( V_12 , V_82 ) ;
V_151:
V_65 = - V_149 ;
error:
F_118 ( V_12 , V_82 ) ;
return V_65 ;
}
static struct V_11 * F_184 ( void )
{
return F_185 ( V_234 , V_14 ) ;
}
struct V_11 * F_186 ( struct V_23 * V_23 , T_3 V_55 ,
T_3 V_144 , T_5 V_52 )
{
struct V_11 * V_12 ;
int V_163 ;
V_12 = F_185 ( V_234 , V_90 ) ;
if ( ! V_12 )
return F_120 ( - V_91 ) ;
V_163 = F_181 ( V_23 , V_12 , V_55 , V_144 , 0 , V_52 ) ;
F_123 ( V_163 < 0 ) ;
return V_12 ;
}
static struct V_23 * F_187 ( struct V_18 * V_18 ,
struct V_82 * V_82 ,
struct V_79 * V_110 [ V_235 + 1 ] )
{
struct V_17 * V_20 ;
struct V_23 * V_23 ;
if ( V_110 [ V_231 ] ) {
V_23 = F_155 ( V_18 , F_76 ( V_110 [ V_231 ] ) ) ;
if ( ! V_23 )
return F_120 ( - V_89 ) ;
if ( V_82 -> V_19 &&
V_82 -> V_19 != F_19 ( V_23 -> V_20 ) )
return F_120 ( - V_89 ) ;
return V_23 ;
} else if ( V_110 [ V_229 ] ) {
T_3 V_34 = F_159 ( V_110 [ V_229 ] ) ;
if ( V_34 >= V_236 )
return F_120 ( - V_95 ) ;
V_20 = F_12 ( V_18 , V_82 -> V_19 ) ;
if ( ! V_20 )
return F_120 ( - V_89 ) ;
V_23 = F_18 ( V_20 , V_34 ) ;
if ( ! V_23 )
return F_120 ( - V_89 ) ;
return V_23 ;
} else
return F_120 ( - V_117 ) ;
}
static int F_188 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_82 * V_82 = V_2 -> V_109 ;
struct V_37 V_38 ;
struct V_11 * V_167 ;
struct V_23 * V_23 ;
struct V_17 * V_20 ;
T_3 V_34 ;
int V_65 ;
if ( ! V_110 [ V_231 ] || ! V_110 [ V_230 ] ||
! V_110 [ V_232 ] )
return - V_117 ;
V_34 = V_110 [ V_229 ]
? F_159 ( V_110 [ V_229 ] ) : 0 ;
if ( V_34 >= V_236 )
return - V_95 ;
V_167 = F_184 () ;
if ( ! V_167 )
return - V_91 ;
F_6 () ;
V_20 = F_12 ( F_96 ( V_12 -> V_131 ) , V_82 -> V_19 ) ;
V_65 = - V_89 ;
if ( ! V_20 )
goto V_237;
if ( V_34 ) {
V_23 = F_174 ( V_20 , V_34 ) ;
V_65 = - V_212 ;
if ( V_23 )
goto V_237;
} else {
for ( V_34 = 1 ; ; V_34 ++ ) {
if ( V_34 >= V_236 ) {
V_65 = - V_95 ;
goto V_237;
}
V_23 = F_174 ( V_20 , V_34 ) ;
if ( ! V_23 )
break;
}
}
V_38 . V_209 = F_76 ( V_110 [ V_231 ] ) ;
V_38 . type = F_159 ( V_110 [ V_230 ] ) ;
V_38 . V_211 = V_110 [ V_238 ] ;
V_38 . V_20 = V_20 ;
V_38 . V_34 = V_34 ;
V_38 . V_56 = F_159 ( V_110 [ V_232 ] ) ;
V_23 = F_31 ( & V_38 ) ;
V_65 = F_57 ( V_23 ) ;
if ( F_33 ( V_23 ) )
goto V_237;
V_65 = F_181 ( V_23 , V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 , V_239 ) ;
F_123 ( V_65 < 0 ) ;
F_8 () ;
F_4 ( & V_228 , V_167 , V_2 ) ;
return 0 ;
V_237:
F_8 () ;
F_43 ( V_167 ) ;
return V_65 ;
}
static int F_189 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_11 * V_167 ;
struct V_23 * V_23 ;
int V_65 ;
V_167 = F_184 () ;
if ( ! V_167 )
return - V_91 ;
F_6 () ;
V_23 = F_187 ( F_96 ( V_12 -> V_131 ) , V_2 -> V_109 , V_110 ) ;
V_65 = F_57 ( V_23 ) ;
if ( F_33 ( V_23 ) )
goto V_237;
if ( V_110 [ V_230 ] &&
F_159 ( V_110 [ V_230 ] ) != V_23 -> V_25 -> type ) {
V_65 = - V_117 ;
goto V_237;
}
if ( V_110 [ V_238 ] ) {
V_65 = F_190 ( V_23 , V_110 [ V_238 ] ) ;
if ( V_65 )
goto V_237;
}
if ( V_110 [ V_232 ] )
V_23 -> V_56 = F_159 ( V_110 [ V_232 ] ) ;
V_65 = F_181 ( V_23 , V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 , V_239 ) ;
F_123 ( V_65 < 0 ) ;
F_8 () ;
F_4 ( & V_228 , V_167 , V_2 ) ;
return 0 ;
V_237:
F_8 () ;
F_43 ( V_167 ) ;
return V_65 ;
}
static int F_191 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_11 * V_167 ;
struct V_23 * V_23 ;
int V_65 ;
V_167 = F_184 () ;
if ( ! V_167 )
return - V_91 ;
F_6 () ;
V_23 = F_187 ( F_96 ( V_12 -> V_131 ) , V_2 -> V_109 , V_110 ) ;
V_65 = F_57 ( V_23 ) ;
if ( F_33 ( V_23 ) )
goto V_237;
if ( V_23 -> V_34 == V_24 ) {
V_65 = - V_117 ;
goto V_237;
}
V_65 = F_181 ( V_23 , V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 , V_240 ) ;
F_123 ( V_65 < 0 ) ;
F_35 ( V_23 ) ;
F_8 () ;
F_4 ( & V_228 , V_167 , V_2 ) ;
return 0 ;
V_237:
F_8 () ;
F_43 ( V_167 ) ;
return V_65 ;
}
static int F_192 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_79 * * V_110 = V_2 -> V_111 ;
struct V_82 * V_82 = V_2 -> V_109 ;
struct V_11 * V_167 ;
struct V_23 * V_23 ;
int V_65 ;
V_167 = F_184 () ;
if ( ! V_167 )
return - V_91 ;
F_13 () ;
V_23 = F_187 ( F_96 ( V_12 -> V_131 ) , V_82 , V_110 ) ;
V_65 = F_57 ( V_23 ) ;
if ( F_33 ( V_23 ) )
goto V_237;
V_65 = F_181 ( V_23 , V_167 , V_2 -> V_13 ,
V_2 -> V_164 , 0 , V_239 ) ;
F_123 ( V_65 < 0 ) ;
F_16 () ;
return F_138 ( V_167 , V_2 ) ;
V_237:
F_16 () ;
F_43 ( V_167 ) ;
return V_65 ;
}
static int F_193 ( struct V_11 * V_12 , struct V_184 * V_185 )
{
struct V_82 * V_82 = F_144 ( F_145 ( V_185 -> V_186 ) ) ;
struct V_17 * V_20 ;
int V_189 = V_185 -> args [ 0 ] , V_225 = V_185 -> args [ 1 ] ;
int V_136 , V_241 = 0 ;
F_13 () ;
V_20 = F_12 ( F_96 ( V_12 -> V_131 ) , V_82 -> V_19 ) ;
if ( ! V_20 ) {
F_16 () ;
return - V_89 ;
}
for ( V_136 = V_189 ; V_136 < V_35 ; V_136 ++ ) {
struct V_23 * V_23 ;
V_241 = 0 ;
F_30 (vport, &dp->ports[i], dp_hash_node) {
if ( V_241 >= V_225 &&
F_181 ( V_23 , V_12 ,
F_148 ( V_185 -> V_12 ) . V_55 ,
V_185 -> V_186 -> V_191 ,
V_192 ,
V_239 ) < 0 )
goto V_58;
V_241 ++ ;
}
V_225 = 0 ;
}
V_58:
F_16 () ;
V_185 -> args [ 0 ] = V_136 ;
V_185 -> args [ 1 ] = V_241 ;
return V_12 -> V_87 ;
}
static void F_194 ( int V_242 )
{
int V_136 ;
for ( V_136 = 0 ; V_136 < V_242 ; V_136 ++ )
F_195 ( V_243 [ V_136 ] ) ;
}
static int F_196 ( void )
{
int V_65 ;
int V_136 ;
for ( V_136 = 0 ; V_136 < F_197 ( V_243 ) ; V_136 ++ ) {
V_65 = F_198 ( V_243 [ V_136 ] ) ;
if ( V_65 )
goto error;
}
return 0 ;
error:
F_194 ( V_136 ) ;
return V_65 ;
}
static int T_7 F_199 ( struct V_18 * V_18 )
{
struct V_203 * V_203 = F_168 ( V_18 , V_218 ) ;
F_200 ( & V_203 -> V_220 ) ;
F_201 ( & V_203 -> V_244 , V_245 ) ;
return 0 ;
}
static void T_8 F_202 ( struct V_18 * V_18 )
{
struct V_17 * V_20 , * V_246 ;
struct V_203 * V_203 = F_168 ( V_18 , V_218 ) ;
F_6 () ;
F_203 (dp, dp_next, &ovs_net->dps, list_node)
F_171 ( V_20 ) ;
F_8 () ;
F_204 ( & V_203 -> V_244 ) ;
}
static int T_9 F_205 ( void )
{
int V_65 ;
F_206 ( sizeof( struct V_247 ) > F_207 ( struct V_11 , V_185 ) ) ;
F_208 ( L_4 ) ;
V_65 = F_209 () ;
if ( V_65 )
goto error;
V_65 = F_210 () ;
if ( V_65 )
goto V_248;
V_65 = F_211 ( & V_249 ) ;
if ( V_65 )
goto V_250;
V_65 = F_212 ( & V_251 ) ;
if ( V_65 )
goto V_252;
V_65 = F_196 () ;
if ( V_65 < 0 )
goto V_253;
return 0 ;
V_253:
F_213 ( & V_251 ) ;
V_252:
F_214 ( & V_249 ) ;
V_250:
F_215 () ;
V_248:
F_216 () ;
error:
return V_65 ;
}
static void F_217 ( void )
{
F_194 ( F_197 ( V_243 ) ) ;
F_213 ( & V_251 ) ;
F_214 ( & V_249 ) ;
F_218 () ;
F_215 () ;
F_216 () ;
}
