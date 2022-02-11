static int F_1 ( const char * V_1 , char * V_2 )
{
char * V_3 = V_2 ;
while ( * V_1 == '/' || * V_1 == '.' )
V_1 ++ ;
if ( V_2 ) {
for (; * V_1 ; V_1 ++ ) {
if ( * V_1 == '/' )
* ( V_3 ) ++ = '.' ;
else if ( isspace ( * V_1 ) )
* ( V_3 ) ++ = '_' ;
else if ( isalnum ( * V_1 ) || strchr ( L_1 , * V_1 ) )
* ( V_3 ) ++ = * V_1 ;
}
* V_3 = 0 ;
} else {
int V_4 = 0 ;
for (; * V_1 ; V_1 ++ ) {
if ( isalnum ( * V_1 ) || isspace ( * V_1 ) ||
strchr ( L_2 , * V_1 ) )
V_4 ++ ;
}
return V_4 ;
}
return V_3 - V_2 ;
}
static int F_2 ( struct V_5 * V_6 , struct V_7 * V_7 )
{
struct V_8 * V_8 = F_3 ( V_7 ) ;
F_4 ( V_6 , L_3 , V_9 , V_8 -> V_10 ) ;
return 0 ;
}
static void F_5 ( struct V_8 * V_8 )
{
F_6 ( & V_8 -> V_11 ) ;
F_7 ( V_8 ) ;
if ( F_8 ( V_8 -> V_12 ) )
F_9 ( V_8 -> V_13 ) ;
}
static int F_10 ( struct V_14 * V_15 , void * V_16 , int V_17 )
{
static struct V_18 V_19 [] = { { L_4 } } ;
int error ;
error = F_11 ( V_15 , V_20 , V_19 ) ;
if ( error )
return error ;
V_15 -> V_21 = & V_22 ;
return 0 ;
}
static struct V_7 * F_12 ( struct V_23 * V_24 ,
int V_25 , const char * V_26 , void * V_16 )
{
return F_13 ( V_24 , V_25 , V_16 , F_10 ) ;
}
static int F_14 ( struct V_8 * V_27 , struct V_7 * V_7 ,
T_1 V_28 , void * V_16 , char * V_29 ,
const struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_8 * V_8 = F_15 ( V_27 -> V_34 ) ;
F_16 ( ! V_27 ) ;
F_16 ( ! V_7 ) ;
if ( ! V_8 )
return - V_35 ;
V_8 -> V_10 = F_17 () ;
V_8 -> V_12 = V_28 ;
V_8 -> V_36 = V_8 -> V_37 = V_8 -> V_38 = F_18 ( V_8 ) ;
V_8 -> V_39 = V_16 ;
if ( F_19 ( V_28 ) ) {
V_8 -> V_40 = V_33 ? V_33 : & V_41 ;
V_8 -> V_42 = & V_43 ;
F_20 ( V_8 ) ;
F_20 ( V_27 ) ;
} else if ( F_8 ( V_28 ) ) {
V_8 -> V_40 = V_33 ? V_33 : & V_44 ;
V_8 -> V_13 = V_29 ;
} else {
V_8 -> V_42 = V_31 ;
}
F_21 ( V_7 , V_8 ) ;
F_22 ( V_7 ) ;
return 0 ;
}
static struct V_7 * F_23 ( const char * V_1 , T_1 V_28 ,
struct V_7 * V_45 , void * V_16 , void * V_29 ,
const struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_7 * V_7 ;
struct V_8 * V_27 ;
int error ;
F_16 ( ! V_1 ) ;
F_16 ( ! V_45 ) ;
if ( ! ( V_28 & V_46 ) )
V_28 = ( V_28 & V_47 ) | V_48 ;
error = F_24 ( & V_49 , & V_50 , & V_51 ) ;
if ( error )
return F_25 ( error ) ;
V_27 = F_3 ( V_45 ) ;
F_26 ( V_27 ) ;
V_7 = F_27 ( V_1 , V_45 , strlen ( V_1 ) ) ;
if ( F_28 ( V_7 ) )
goto V_52;
if ( F_29 ( V_7 ) ) {
error = - V_53 ;
goto V_54;
}
error = F_14 ( V_27 , V_7 , V_28 , V_16 , V_29 , V_31 , V_33 ) ;
if ( error )
goto V_54;
F_30 ( V_27 ) ;
return V_7 ;
V_54:
F_31 ( V_7 ) ;
V_52:
F_30 ( V_27 ) ;
F_32 ( & V_50 , & V_51 ) ;
return F_25 ( error ) ;
}
static struct V_7 * F_33 ( const char * V_1 , T_1 V_28 ,
struct V_7 * V_45 , void * V_16 ,
const struct V_30 * V_31 )
{
return F_23 ( V_1 , V_28 , V_45 , V_16 , NULL , V_31 , NULL ) ;
}
static struct V_7 * F_34 ( const char * V_1 , struct V_7 * V_45 )
{
return F_23 ( V_1 , V_55 | 0755 , V_45 , NULL , NULL , NULL ,
NULL ) ;
}
static struct V_7 * F_35 ( const char * V_1 ,
struct V_7 * V_45 ,
const char * V_2 ,
const struct V_32 * V_33 )
{
struct V_7 * V_56 ;
char * V_29 = NULL ;
if ( V_2 ) {
V_29 = F_36 ( V_2 , V_57 ) ;
if ( ! V_29 )
return F_25 ( - V_35 ) ;
}
V_56 = F_23 ( V_1 , V_58 | 0444 , V_45 , NULL , V_29 , NULL ,
V_33 ) ;
if ( F_28 ( V_56 ) )
F_9 ( V_29 ) ;
return V_56 ;
}
static void F_37 ( struct V_7 * V_7 )
{
struct V_8 * V_27 ;
if ( ! V_7 || F_28 ( V_7 ) )
return;
V_27 = F_3 ( V_7 -> V_59 ) ;
F_26 ( V_27 ) ;
if ( F_38 ( V_7 ) ) {
if ( F_39 ( V_7 ) )
F_40 ( V_27 , V_7 ) ;
else
F_41 ( V_27 , V_7 ) ;
F_31 ( V_7 ) ;
}
F_30 ( V_27 ) ;
F_32 ( & V_50 , & V_51 ) ;
}
static struct V_60 * F_42 ( const char T_2 * V_61 ,
T_3 V_62 ,
T_3 V_63 ,
T_4 * V_64 )
{
struct V_60 * V_16 ;
F_16 ( V_63 > V_62 ) ;
if ( * V_64 != 0 )
return F_25 ( - V_65 ) ;
V_16 = F_43 ( V_62 ) ;
if ( F_28 ( V_16 ) )
return V_16 ;
V_16 -> V_66 = V_63 ;
if ( F_44 ( V_16 -> V_16 , V_61 , V_63 ) ) {
F_45 ( V_16 ) ;
return F_25 ( - V_67 ) ;
}
return V_16 ;
}
static T_5 F_46 ( T_6 V_68 , const char T_2 * V_69 , T_3 V_66 ,
T_4 * V_64 , struct V_70 * V_71 )
{
struct V_60 * V_16 ;
struct V_72 * V_73 ;
T_5 error ;
V_73 = F_47 () ;
error = F_48 ( V_73 , V_71 , V_68 ) ;
if ( error )
return error ;
V_16 = F_42 ( V_69 , V_66 , V_66 , V_64 ) ;
error = F_49 ( V_16 ) ;
if ( ! F_28 ( V_16 ) ) {
error = F_50 ( V_71 , V_73 , V_68 , V_16 ) ;
F_51 ( V_16 ) ;
}
F_52 ( V_73 ) ;
return error ;
}
static T_5 F_53 ( struct V_74 * V_75 , const char T_2 * V_69 , T_3 V_66 ,
T_4 * V_64 )
{
struct V_70 * V_71 = F_54 ( V_75 -> V_76 -> V_39 ) ;
int error = F_46 ( V_77 , V_69 , V_66 , V_64 , V_71 ) ;
F_55 ( V_71 ) ;
return error ;
}
static T_5 F_56 ( struct V_74 * V_75 , const char T_2 * V_69 ,
T_3 V_66 , T_4 * V_64 )
{
struct V_70 * V_71 = F_54 ( V_75 -> V_76 -> V_39 ) ;
int error = F_46 ( V_77 | V_78 ,
V_69 , V_66 , V_64 , V_71 ) ;
F_55 ( V_71 ) ;
return error ;
}
static T_5 F_57 ( struct V_74 * V_75 , const char T_2 * V_69 ,
T_3 V_66 , T_4 * V_64 )
{
struct V_60 * V_16 ;
struct V_72 * V_73 ;
T_5 error ;
struct V_70 * V_71 = F_54 ( V_75 -> V_76 -> V_39 ) ;
V_73 = F_47 () ;
error = F_48 ( V_73 , V_71 , V_79 ) ;
if ( error )
goto V_80;
V_16 = F_42 ( V_69 , V_66 + 1 , V_66 , V_64 ) ;
error = F_49 ( V_16 ) ;
if ( ! F_28 ( V_16 ) ) {
V_16 -> V_16 [ V_66 ] = 0 ;
error = F_58 ( V_71 , V_73 , V_16 -> V_16 , V_66 ) ;
F_51 ( V_16 ) ;
}
V_80:
F_52 ( V_73 ) ;
F_55 ( V_71 ) ;
return error ;
}
static int F_59 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
struct V_81 * V_82 = V_74 -> V_83 ;
if ( V_82 ) {
F_55 ( V_82 -> V_71 ) ;
F_9 ( V_82 ) ;
}
return 0 ;
}
static T_5 F_60 ( struct V_74 * V_74 , char T_2 * V_69 ,
T_3 V_66 , T_4 * V_84 )
{
struct V_81 * V_82 = V_74 -> V_83 ;
char V_85 [ 32 ] ;
long V_86 ;
int V_87 ;
F_61 ( & V_82 -> V_71 -> V_88 ) ;
V_86 = V_82 -> V_86 ;
if ( V_86 == V_82 -> V_71 -> V_89 ) {
F_62 ( & V_82 -> V_71 -> V_88 ) ;
if ( V_74 -> V_90 & V_91 )
return - V_92 ;
if ( F_63 ( V_82 -> V_71 -> V_93 ,
V_86 !=
F_64 ( V_82 -> V_71 -> V_89 ) ) )
return - V_94 ;
F_61 ( & V_82 -> V_71 -> V_88 ) ;
}
V_87 = sprintf ( V_85 , L_5 , V_82 -> V_71 -> V_89 ) ;
if ( * V_84 + V_66 > V_87 ) {
V_82 -> V_86 = V_82 -> V_71 -> V_89 ;
* V_84 = 0 ;
}
F_62 ( & V_82 -> V_71 -> V_88 ) ;
return F_65 ( V_69 , V_66 , V_84 , V_85 , V_87 ) ;
}
static int F_66 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
struct V_81 * V_82 = F_67 ( sizeof( * V_82 ) , V_57 ) ;
if ( ! V_82 )
return - V_35 ;
V_82 -> V_71 = F_54 ( V_8 -> V_39 ) ;
if ( ! V_82 -> V_71 )
V_82 -> V_71 = F_68 () ;
V_74 -> V_83 = V_82 ;
return 0 ;
}
static unsigned int F_69 ( struct V_74 * V_74 , T_7 * V_95 )
{
struct V_81 * V_82 = V_74 -> V_83 ;
unsigned int V_68 = 0 ;
if ( V_82 ) {
F_61 ( & V_82 -> V_71 -> V_88 ) ;
F_70 ( V_74 , & V_82 -> V_71 -> V_93 , V_95 ) ;
if ( V_82 -> V_86 < V_82 -> V_71 -> V_89 )
V_68 |= V_96 | V_97 ;
F_62 ( & V_82 -> V_71 -> V_88 ) ;
}
return V_68 ;
}
void F_71 ( struct V_70 * V_71 )
{
V_71 -> V_89 ++ ;
F_72 ( & V_71 -> V_93 ) ;
}
static void F_73 ( struct V_98 * V_99 , struct V_100 * V_101 ,
const char * V_102 , T_3 V_103 )
{
struct V_100 V_104 ;
struct V_105 * V_106 ;
unsigned int V_107 = 0 ;
if ( F_74 ( V_99 ) )
return;
if ( V_99 -> V_74 . V_106 && * V_102 == V_108 ) {
V_106 = V_99 -> V_74 . V_106 ;
V_107 = F_75 ( V_106 , V_99 -> V_74 . V_109 ,
V_102 + 1 , V_103 - 1 ) ;
V_104 = V_110 ;
if ( V_107 ) {
struct V_111 V_112 = { } ;
V_104 = F_76 ( V_106 , V_107 , & V_112 ) ;
}
} else if ( V_99 -> V_113 . V_106 ) {
if ( ! F_77 ( V_99 , * V_102 ) )
return;
V_106 = V_99 -> V_113 . V_106 ;
V_107 = F_75 ( V_106 , V_99 -> V_113 . V_109 [ 0 ] ,
V_102 , V_103 ) ;
if ( V_107 )
F_78 ( V_106 , V_107 , & V_104 ) ;
else
V_104 = V_110 ;
}
F_79 ( V_99 , & V_104 ) ;
F_80 ( V_101 , & V_104 ) ;
}
static T_5 F_81 ( char * V_69 , T_3 V_114 ,
char * V_115 , T_3 V_116 )
{
char * V_80 ;
const char * V_117 ;
struct V_118 V_119 ;
struct V_72 * V_73 , * V_120 ;
struct V_98 * V_99 ;
struct V_121 * V_16 ;
T_6 V_122 , V_123 ;
T_8 V_124 ;
if ( ! V_116 )
return - V_125 ;
V_117 = V_115 + F_82 ( V_115 , V_116 ) + 1 ;
if ( V_117 + 1 >= V_115 + V_116 )
return - V_125 ;
if ( V_117 + F_82 ( V_117 , V_115 + V_116 - V_117 ) >= V_115 + V_116 )
return - V_125 ;
if ( V_114 < sizeof( V_122 ) + sizeof( V_123 ) )
return - V_125 ;
V_120 = F_47 () ;
V_73 = F_83 ( V_120 , V_115 , V_57 , false , false ) ;
F_52 ( V_120 ) ;
if ( F_28 ( V_73 ) )
return F_49 ( V_73 ) ;
memset ( V_69 , 0 , sizeof( V_122 ) + sizeof( V_123 ) ) ;
V_80 = V_69 + sizeof( V_122 ) + sizeof( V_123 ) ;
V_123 = 0 ;
F_84 (i, label, profile) {
if ( ! V_99 -> V_16 )
continue;
V_16 = F_85 ( V_99 -> V_16 , & V_117 ,
V_99 -> V_16 -> V_126 ) ;
if ( V_16 ) {
if ( V_80 + sizeof( V_124 ) + V_16 -> V_66 > V_69 +
V_114 ) {
F_86 ( V_73 ) ;
return - V_125 ;
}
V_124 = F_87 ( V_16 -> V_66 ) ;
memcpy ( V_80 , & V_124 , sizeof( V_124 ) ) ;
V_80 += sizeof( V_124 ) ;
memcpy ( V_80 , V_16 -> V_16 , V_16 -> V_66 ) ;
V_80 += V_16 -> V_66 ;
V_123 ++ ;
}
}
F_86 ( V_73 ) ;
V_124 = F_87 ( V_80 - V_69 - sizeof( V_122 ) ) ;
memcpy ( V_69 , & V_124 , sizeof( V_124 ) ) ;
V_124 = F_87 ( V_123 ) ;
memcpy ( V_69 + sizeof( V_122 ) , & V_124 , sizeof( V_124 ) ) ;
return V_80 - V_69 ;
}
static T_5 F_88 ( char * V_69 , T_3 V_114 ,
char * V_115 , T_3 V_116 , bool V_127 )
{
struct V_98 * V_99 ;
struct V_72 * V_73 , * V_120 ;
char * V_128 , * V_102 ;
T_3 V_129 , V_103 ;
struct V_100 V_101 ;
struct V_118 V_119 ;
if ( ! V_116 )
return - V_125 ;
V_128 = V_115 ;
V_129 = F_82 ( V_115 , V_116 ) ;
if ( ! V_129 || V_129 == V_116 )
return - V_125 ;
V_102 = V_128 + V_129 + 1 ;
V_103 = V_116 - V_129 - 1 ;
V_120 = F_47 () ;
V_73 = F_83 ( V_120 , V_128 , V_57 , false , false ) ;
F_52 ( V_120 ) ;
if ( F_28 ( V_73 ) )
return F_49 ( V_73 ) ;
V_101 = V_130 ;
if ( V_127 ) {
F_89 (i, labels_ns(label), label, profile) {
F_73 ( V_99 , & V_101 , V_102 , V_103 ) ;
}
} else {
F_90 (i, label, profile) {
F_73 ( V_99 , & V_101 , V_102 , V_103 ) ;
}
}
F_86 ( V_73 ) ;
return F_91 ( V_69 , V_114 ,
L_6 ,
V_101 . V_131 , V_101 . V_132 , V_101 . V_133 , V_101 . V_134 ) ;
}
static void F_92 ( struct V_135 * V_135 )
{
struct V_136 * V_3 ;
V_3 = F_93 ( V_135 , struct V_136 , V_137 ) ;
F_94 ( ( unsigned long ) V_3 ) ;
}
static struct V_136 *
F_95 ( struct V_136 * V_3 )
{
if ( V_3 )
F_96 ( & ( V_3 -> V_137 ) ) ;
return V_3 ;
}
static void F_97 ( struct V_136 * V_3 )
{
if ( V_3 )
F_98 ( & ( V_3 -> V_137 ) , F_92 ) ;
}
static void F_99 ( struct V_74 * V_74 ,
struct V_136 * V_138 , T_3 V_139 )
{
struct V_136 * V_140 ;
F_16 ( V_139 > V_141 ) ;
V_138 -> V_66 = V_139 ;
F_100 ( & V_142 ) ;
V_140 = (struct V_136 * ) V_74 -> V_83 ;
V_74 -> V_83 = V_138 ;
F_101 ( & V_142 ) ;
F_97 ( V_140 ) ;
}
static struct V_136 * F_102 ( struct V_74 * V_74 ,
const char T_2 * V_69 ,
T_3 V_66 )
{
struct V_136 * V_3 ;
if ( V_66 > V_141 - 1 )
return F_25 ( - V_143 ) ;
V_3 = (struct V_136 * ) F_103 ( V_57 ) ;
if ( ! V_3 )
return F_25 ( - V_35 ) ;
F_104 ( & V_3 -> V_137 ) ;
if ( F_44 ( V_3 -> V_16 , V_69 , V_66 ) )
return F_25 ( - V_67 ) ;
return V_3 ;
}
static T_5 F_105 ( struct V_74 * V_74 , char T_2 * V_69 ,
T_3 V_66 , T_4 * V_64 )
{
struct V_136 * V_3 ;
T_5 V_144 ;
F_100 ( & V_142 ) ;
V_3 = F_95 ( V_74 -> V_83 ) ;
F_101 ( & V_142 ) ;
if ( ! V_3 )
return 0 ;
V_144 = F_65 ( V_69 , V_66 , V_64 , V_3 -> V_16 , V_3 -> V_66 ) ;
F_97 ( V_3 ) ;
return V_144 ;
}
static int F_106 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
F_97 ( V_74 -> V_83 ) ;
return 0 ;
}
static T_5 F_107 ( struct V_74 * V_74 , const char T_2 * V_145 ,
T_3 V_137 , T_4 * V_84 )
{
struct V_136 * V_3 ;
T_5 V_4 ;
if ( * V_84 )
return - V_65 ;
V_3 = F_102 ( V_74 , V_145 , V_137 ) ;
if ( F_28 ( V_3 ) )
return F_49 ( V_3 ) ;
if ( V_137 > V_146 &&
! memcmp ( V_3 -> V_16 , V_147 , V_146 ) ) {
V_4 = F_88 ( V_3 -> V_16 , V_141 ,
V_3 -> V_16 + V_146 ,
V_137 - V_146 , true ) ;
} else if ( V_137 > V_148 &&
! memcmp ( V_3 -> V_16 , V_149 , V_148 ) ) {
V_4 = F_88 ( V_3 -> V_16 , V_141 ,
V_3 -> V_16 + V_148 ,
V_137 - V_148 , true ) ;
} else if ( V_137 > V_150 &&
! memcmp ( V_3 -> V_16 , V_151 ,
V_150 ) ) {
V_4 = F_88 ( V_3 -> V_16 , V_141 ,
V_3 -> V_16 + V_150 ,
V_137 - V_150 , false ) ;
} else if ( V_137 > V_152 &&
! memcmp ( V_3 -> V_16 , V_153 , V_152 ) ) {
V_4 = F_81 ( V_3 -> V_16 , V_141 ,
V_3 -> V_16 + V_152 ,
V_137 - V_152 ) ;
} else
V_4 = - V_125 ;
if ( V_4 < 0 ) {
F_97 ( V_3 ) ;
return V_4 ;
}
F_99 ( V_74 , V_3 , V_4 ) ;
return V_137 ;
}
static int F_108 ( struct V_5 * V_6 , void * V_154 )
{
struct V_155 * V_156 = V_6 -> V_157 ;
if ( ! V_156 )
return 0 ;
switch ( V_156 -> V_158 ) {
case V_159 :
F_4 ( V_6 , L_7 , V_156 -> V_154 . boolean ? L_8 : L_9 ) ;
break;
case V_160 :
F_4 ( V_6 , L_7 , V_156 -> V_154 . string ) ;
break;
case V_161 :
F_4 ( V_6 , L_10 , V_156 -> V_154 . V_162 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_109 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
return F_110 ( V_74 , F_108 , V_8 -> V_39 ) ;
}
int (* F_111)( struct V_5 * , void * )
static int F_112 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
struct V_5 * V_6 = (struct V_5 * ) V_74 -> V_83 ;
if ( V_6 )
F_113 ( V_6 -> V_157 ) ;
return F_114 ( V_8 , V_74 ) ;
}
static int F_115 ( struct V_5 * V_6 , void * V_154 )
{
struct V_163 * V_164 = V_6 -> V_157 ;
struct V_72 * V_73 = F_116 ( & V_164 -> V_73 ) ;
struct V_98 * V_99 = F_117 ( V_73 ) ;
F_4 ( V_6 , L_7 , V_99 -> V_165 . V_1 ) ;
F_86 ( V_73 ) ;
return 0 ;
}
static int F_118 ( struct V_5 * V_6 , void * V_154 )
{
struct V_163 * V_164 = V_6 -> V_157 ;
struct V_72 * V_73 = F_116 ( & V_164 -> V_73 ) ;
struct V_98 * V_99 = F_117 ( V_73 ) ;
F_4 ( V_6 , L_7 , V_166 [ V_99 -> V_28 ] ) ;
F_86 ( V_73 ) ;
return 0 ;
}
static int F_119 ( struct V_5 * V_6 , void * V_154 )
{
struct V_163 * V_164 = V_6 -> V_157 ;
struct V_72 * V_73 = F_116 ( & V_164 -> V_73 ) ;
struct V_98 * V_99 = F_117 ( V_73 ) ;
if ( V_99 -> V_167 )
F_4 ( V_6 , L_7 , V_99 -> V_167 ) ;
else if ( V_99 -> V_168 )
F_120 ( V_6 , L_11 ) ;
else
F_4 ( V_6 , L_7 , V_99 -> V_165 . V_1 ) ;
F_86 ( V_73 ) ;
return 0 ;
}
static int F_121 ( struct V_5 * V_6 , void * V_154 )
{
struct V_163 * V_164 = V_6 -> V_157 ;
struct V_72 * V_73 = F_116 ( & V_164 -> V_73 ) ;
struct V_98 * V_99 = F_117 ( V_73 ) ;
unsigned int V_119 , V_66 = F_122 () ;
if ( V_99 -> V_169 ) {
for ( V_119 = 0 ; V_119 < V_66 ; V_119 ++ )
F_4 ( V_6 , L_12 , V_99 -> V_169 [ V_119 ] ) ;
F_123 ( V_6 , '\n' ) ;
}
F_86 ( V_73 ) ;
return 0 ;
}
static int F_124 ( struct V_5 * V_6 , void * V_154 )
{
struct V_72 * V_73 ;
struct V_98 * V_99 ;
struct V_118 V_170 ;
int V_137 = 1 ;
V_73 = F_47 () ;
if ( V_73 -> V_66 > 1 ) {
F_90 (it, label, profile)
if ( V_99 -> V_71 != F_125 ( V_73 ) ) {
V_137 ++ ;
break;
}
}
F_4 ( V_6 , L_7 , V_137 > 1 ? L_8 : L_9 ) ;
F_52 ( V_73 ) ;
return 0 ;
}
static int F_126 ( struct V_5 * V_6 , void * V_154 )
{
struct V_72 * V_73 ;
V_73 = F_47 () ;
F_4 ( V_6 , L_13 , F_125 ( V_73 ) -> V_171 ) ;
F_52 ( V_73 ) ;
return 0 ;
}
static int F_127 ( struct V_5 * V_6 , void * V_154 )
{
struct V_72 * V_73 = F_47 () ;
F_4 ( V_6 , L_7 , F_128 ( F_125 ( V_73 ) ,
F_125 ( V_73 ) , true ) ) ;
F_52 ( V_73 ) ;
return 0 ;
}
int (* F_111)( struct V_5 * , void * )
static int F_129 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
struct V_5 * V_6 = (struct V_5 * ) V_74 -> V_83 ;
if ( V_6 )
F_51 ( V_6 -> V_157 ) ;
return F_114 ( V_8 , V_74 ) ;
}
static int F_130 ( struct V_5 * V_6 , void * V_154 )
{
struct V_60 * V_16 = V_6 -> V_157 ;
F_4 ( V_6 , L_14 , V_16 -> V_172 ) ;
return 0 ;
}
static int F_131 ( struct V_5 * V_6 , void * V_154 )
{
struct V_60 * V_16 = V_6 -> V_157 ;
F_4 ( V_6 , L_5 , V_16 -> V_89 ) ;
return 0 ;
}
static int F_132 ( struct V_5 * V_6 , void * V_154 )
{
struct V_60 * V_16 = V_6 -> V_157 ;
unsigned int V_119 , V_66 = F_122 () ;
if ( V_16 -> V_169 ) {
for ( V_119 = 0 ; V_119 < V_66 ; V_119 ++ )
F_4 ( V_6 , L_12 , V_16 -> V_169 [ V_119 ] ) ;
F_123 ( V_6 , '\n' ) ;
}
return 0 ;
}
static T_5 F_133 ( struct V_74 * V_74 , char T_2 * V_69 , T_3 V_66 ,
T_4 * V_84 )
{
struct V_60 * V_173 = V_74 -> V_83 ;
return F_65 ( V_69 , V_66 , V_84 , V_173 -> V_16 ,
V_173 -> V_66 ) ;
}
static int F_134 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
F_51 ( V_74 -> V_83 ) ;
return 0 ;
}
static int F_135 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
if ( ! F_136 ( NULL ) )
return - V_174 ;
V_74 -> V_83 = F_137 ( V_8 -> V_39 ) ;
if ( ! V_74 -> V_83 )
return - V_175 ;
return 0 ;
}
static void F_138 ( struct V_60 * V_173 )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_176 ; V_119 ++ ) {
if ( ! F_139 ( V_173 -> V_177 [ V_119 ] ) ) {
F_37 ( V_173 -> V_177 [ V_119 ] ) ;
V_173 -> V_177 [ V_119 ] = NULL ;
}
}
}
void F_140 ( struct V_60 * V_173 )
{
F_16 ( V_173 -> V_71 && ! F_141 ( & V_173 -> V_71 -> V_88 ) ) ;
if ( V_173 -> V_71 ) {
F_138 ( V_173 ) ;
F_142 ( & V_173 -> V_178 ) ;
F_55 ( V_173 -> V_71 ) ;
V_173 -> V_71 = NULL ;
}
}
int F_143 ( struct V_70 * V_71 , struct V_60 * V_173 )
{
struct V_7 * V_56 , * V_27 ;
F_16 ( ! V_71 ) ;
F_16 ( ! V_173 ) ;
F_16 ( ! F_141 ( & V_71 -> V_88 ) ) ;
F_16 ( ! F_144 ( V_71 ) ) ;
V_173 -> V_1 = F_145 ( V_57 , L_15 , V_71 -> V_89 ) ;
if ( ! V_173 -> V_1 )
return - V_35 ;
V_27 = F_34 ( V_173 -> V_1 , F_144 ( V_71 ) ) ;
if ( F_28 ( V_27 ) )
return F_49 ( V_27 ) ;
V_173 -> V_177 [ V_179 ] = V_27 ;
V_56 = F_33 ( L_16 , V_48 | 0444 , V_27 , V_173 ,
& V_180 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_173 -> V_177 [ V_182 ] = V_56 ;
V_56 = F_33 ( L_17 , V_48 | 0444 , V_27 , V_173 ,
& V_183 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_173 -> V_177 [ V_184 ] = V_56 ;
if ( V_185 ) {
V_56 = F_33 ( L_18 , V_48 | 0444 , V_27 ,
V_173 , & V_186 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_173 -> V_177 [ V_187 ] = V_56 ;
}
V_56 = F_33 ( L_19 , V_48 | 0444 ,
V_27 , V_173 , & V_188 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_173 -> V_177 [ V_189 ] = V_56 ;
F_3 ( V_56 ) -> V_190 = V_173 -> V_66 ;
V_173 -> V_71 = F_54 ( V_71 ) ;
F_146 ( & V_173 -> V_178 , & V_71 -> V_191 ) ;
return 0 ;
V_181:
F_138 ( V_173 ) ;
return F_49 ( V_56 ) ;
}
void F_147 ( struct V_98 * V_99 )
{
struct V_98 * V_192 ;
int V_119 ;
if ( ! V_99 )
return;
F_148 (child, &profile->base.profiles, base.list)
F_147 ( V_192 ) ;
for ( V_119 = V_193 - 1 ; V_119 >= 0 ; -- V_119 ) {
struct V_163 * V_164 ;
if ( ! V_99 -> V_177 [ V_119 ] )
continue;
V_164 = F_3 ( V_99 -> V_177 [ V_119 ] ) -> V_39 ;
F_37 ( V_99 -> V_177 [ V_119 ] ) ;
F_113 ( V_164 ) ;
V_99 -> V_177 [ V_119 ] = NULL ;
}
}
void F_149 ( struct V_98 * V_140 ,
struct V_98 * V_138 )
{
int V_119 ;
for ( V_119 = 0 ; V_119 < V_193 ; V_119 ++ ) {
V_138 -> V_177 [ V_119 ] = V_140 -> V_177 [ V_119 ] ;
if ( V_138 -> V_177 [ V_119 ] )
V_138 -> V_177 [ V_119 ] -> F_3 -> V_37 = F_18 ( V_138 -> V_177 [ V_119 ] -> F_3 ) ;
V_140 -> V_177 [ V_119 ] = NULL ;
}
}
static struct V_7 * F_150 ( struct V_7 * V_27 , const char * V_1 ,
struct V_98 * V_99 ,
const struct V_30 * V_31 )
{
struct V_163 * V_164 = F_151 ( V_99 -> V_73 . V_164 ) ;
struct V_7 * V_56 ;
V_56 = F_33 ( V_1 , V_48 | 0444 , V_27 , V_164 , V_31 ) ;
if ( F_28 ( V_56 ) )
F_113 ( V_164 ) ;
return V_56 ;
}
static int F_152 ( struct V_98 * V_99 )
{
int V_194 = 0 ;
F_153 () ;
for ( V_194 = 0 ; V_99 ; V_99 = F_154 ( V_99 -> V_45 ) )
V_194 ++ ;
F_155 () ;
return V_194 ;
}
static int F_156 ( char * V_85 , T_3 V_195 , int V_194 ,
const char * V_196 , const char * V_197 )
{
int error ;
for (; V_194 > 0 ; V_194 -- ) {
if ( V_195 < 7 )
return - V_198 ;
strcpy ( V_85 , L_20 ) ;
V_85 += 6 ;
V_195 -= 6 ;
}
error = snprintf ( V_85 , V_195 , L_21 , V_196 , V_197 ) ;
if ( error >= V_195 || error < 0 )
return - V_198 ;
return 0 ;
}
int F_157 ( struct V_98 * V_99 , struct V_7 * V_45 )
{
struct V_98 * V_192 ;
struct V_7 * V_56 = NULL , * V_27 ;
int error ;
if ( ! V_45 ) {
struct V_98 * V_126 ;
V_126 = F_158 ( V_99 ) ;
V_56 = F_159 ( V_126 ) ;
V_56 = F_34 ( L_22 , V_56 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
F_160 ( V_126 ) = V_45 = V_56 ;
}
if ( ! V_99 -> V_196 ) {
int V_4 , V_199 ;
V_4 = F_1 ( V_99 -> V_165 . V_1 , NULL ) ;
V_199 = snprintf ( NULL , 0 , L_23 , V_99 -> V_71 -> V_200 ) ;
V_99 -> V_196 = F_161 ( V_4 + V_199 + 1 , V_57 ) ;
if ( ! V_99 -> V_196 ) {
error = - V_35 ;
goto V_201;
}
F_1 ( V_99 -> V_165 . V_1 , V_99 -> V_196 ) ;
sprintf ( V_99 -> V_196 + V_4 , L_23 , V_99 -> V_71 -> V_200 ++ ) ;
}
V_56 = F_34 ( V_99 -> V_196 , V_45 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
F_159 ( V_99 ) = V_27 = V_56 ;
V_56 = F_150 ( V_27 , L_24 , V_99 ,
& V_202 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_99 -> V_177 [ V_203 ] = V_56 ;
V_56 = F_150 ( V_27 , L_25 , V_99 ,
& V_204 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_99 -> V_177 [ V_205 ] = V_56 ;
V_56 = F_150 ( V_27 , L_26 , V_99 ,
& V_206 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_99 -> V_177 [ V_207 ] = V_56 ;
if ( V_99 -> V_169 ) {
V_56 = F_150 ( V_27 , L_18 , V_99 ,
& V_208 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_99 -> V_177 [ V_209 ] = V_56 ;
}
if ( V_99 -> V_173 ) {
char V_2 [ 64 ] ;
int V_194 = F_152 ( V_99 ) ;
error = F_156 ( V_2 , sizeof( V_2 ) , V_194 ,
V_99 -> V_173 -> V_1 , L_18 ) ;
if ( error < 0 )
goto V_201;
V_56 = F_35 ( L_27 , V_27 , V_2 , NULL ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_99 -> V_177 [ V_210 ] = V_56 ;
error = F_156 ( V_2 , sizeof( V_2 ) , V_194 ,
V_99 -> V_173 -> V_1 , L_16 ) ;
if ( error < 0 )
goto V_201;
V_56 = F_35 ( L_28 , V_27 , V_2 , NULL ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_99 -> V_177 [ V_211 ] = V_56 ;
error = F_156 ( V_2 , sizeof( V_2 ) , V_194 ,
V_99 -> V_173 -> V_1 , L_19 ) ;
if ( error < 0 )
goto V_201;
V_56 = F_35 ( L_19 , V_27 , V_2 , NULL ) ;
if ( F_28 ( V_56 ) )
goto V_181;
V_99 -> V_177 [ V_212 ] = V_56 ;
}
F_148 (child, &profile->base.profiles, base.list) {
error = F_157 ( V_192 , F_160 ( V_99 ) ) ;
if ( error )
goto V_201;
}
return 0 ;
V_181:
error = F_49 ( V_56 ) ;
V_201:
F_147 ( V_99 ) ;
return error ;
}
static int F_162 ( struct V_8 * V_27 , struct V_7 * V_7 , T_1 V_28 )
{
struct V_70 * V_71 , * V_45 ;
struct V_72 * V_73 ;
int error ;
V_73 = F_47 () ;
error = F_48 ( V_73 , NULL , V_77 ) ;
F_52 ( V_73 ) ;
if ( error )
return error ;
V_45 = F_54 ( V_27 -> V_39 ) ;
F_16 ( F_3 ( F_163 ( V_45 ) ) != V_27 ) ;
F_30 ( V_27 ) ;
error = F_24 ( & V_49 , & V_50 , & V_51 ) ;
F_61 ( & V_45 -> V_88 ) ;
F_164 ( V_27 , V_213 ) ;
if ( error )
goto V_80;
error = F_14 ( V_27 , V_7 , V_28 | V_55 , NULL ,
NULL , NULL , NULL ) ;
if ( error )
goto V_214;
V_71 = F_165 ( V_45 , F_64 ( V_7 -> V_215 . V_1 ) ,
V_7 ) ;
if ( F_28 ( V_71 ) ) {
error = F_49 ( V_71 ) ;
V_71 = NULL ;
}
F_55 ( V_71 ) ;
V_214:
if ( error )
F_32 ( & V_50 , & V_51 ) ;
V_80:
F_62 ( & V_45 -> V_88 ) ;
F_55 ( V_45 ) ;
return error ;
}
static int F_166 ( struct V_8 * V_27 , struct V_7 * V_7 )
{
struct V_70 * V_71 , * V_45 ;
struct V_72 * V_73 ;
int error ;
V_73 = F_47 () ;
error = F_48 ( V_73 , NULL , V_77 ) ;
F_52 ( V_73 ) ;
if ( error )
return error ;
V_45 = F_54 ( V_27 -> V_39 ) ;
F_30 ( V_27 ) ;
F_30 ( V_7 -> F_3 ) ;
F_61 ( & V_45 -> V_88 ) ;
V_71 = F_54 ( F_167 ( & V_45 -> V_216 , V_7 -> V_215 . V_1 ,
V_7 -> V_215 . V_4 ) ) ;
if ( ! V_71 ) {
error = - V_175 ;
goto V_80;
}
F_16 ( F_168 ( V_71 ) != V_7 ) ;
F_169 ( V_71 ) ;
F_55 ( V_71 ) ;
V_80:
F_62 ( & V_45 -> V_88 ) ;
F_164 ( V_27 , V_213 ) ;
F_26 ( V_7 -> F_3 ) ;
F_55 ( V_45 ) ;
return error ;
}
static void F_170 ( struct V_70 * V_71 )
{
struct V_60 * V_217 , * V_104 ;
F_16 ( ! F_141 ( & V_71 -> V_88 ) ) ;
F_171 (ent, tmp, &ns->rawdata_list, list)
F_140 ( V_217 ) ;
}
void F_172 ( struct V_70 * V_71 )
{
struct V_70 * V_218 ;
struct V_98 * V_192 ;
int V_119 ;
if ( ! V_71 )
return;
F_148 (child, &ns->base.profiles, base.list)
F_147 ( V_192 ) ;
F_148 (sub, &ns->sub_ns, base.list) {
F_61 ( & V_218 -> V_88 ) ;
F_172 ( V_218 ) ;
F_62 ( & V_218 -> V_88 ) ;
}
F_170 ( V_71 ) ;
if ( F_163 ( V_71 ) ) {
V_218 = F_3 ( F_163 ( V_71 ) ) -> V_39 ;
F_55 ( V_218 ) ;
}
if ( F_173 ( V_71 ) ) {
V_218 = F_3 ( F_173 ( V_71 ) ) -> V_39 ;
F_55 ( V_218 ) ;
}
if ( F_174 ( V_71 ) ) {
V_218 = F_3 ( F_174 ( V_71 ) ) -> V_39 ;
F_55 ( V_218 ) ;
}
if ( F_175 ( V_71 ) ) {
V_218 = F_3 ( F_175 ( V_71 ) ) -> V_39 ;
F_55 ( V_218 ) ;
}
if ( F_176 ( V_71 ) ) {
V_218 = F_3 ( F_176 ( V_71 ) ) -> V_39 ;
F_55 ( V_218 ) ;
}
for ( V_119 = V_219 - 1 ; V_119 >= 0 ; -- V_119 ) {
F_37 ( V_71 -> V_177 [ V_119 ] ) ;
V_71 -> V_177 [ V_119 ] = NULL ;
}
}
static int F_177 ( struct V_70 * V_71 , struct V_7 * V_27 )
{
struct V_7 * V_56 ;
F_16 ( ! V_71 ) ;
F_16 ( ! V_27 ) ;
V_56 = F_34 ( L_22 , V_27 ) ;
if ( F_28 ( V_56 ) )
return F_49 ( V_56 ) ;
F_178 ( V_71 ) = V_56 ;
V_56 = F_34 ( L_19 , V_27 ) ;
if ( F_28 ( V_56 ) )
return F_49 ( V_56 ) ;
F_144 ( V_71 ) = V_56 ;
V_56 = F_33 ( L_17 , 0444 , V_27 , V_71 ,
& V_220 ) ;
if ( F_28 ( V_56 ) )
return F_49 ( V_56 ) ;
F_54 ( V_71 ) ;
F_176 ( V_71 ) = V_56 ;
V_56 = F_33 ( L_29 , 0640 , V_27 , V_71 ,
& V_221 ) ;
if ( F_28 ( V_56 ) )
return F_49 ( V_56 ) ;
F_54 ( V_71 ) ;
F_173 ( V_71 ) = V_56 ;
V_56 = F_33 ( L_30 , 0640 , V_27 , V_71 ,
& V_222 ) ;
if ( F_28 ( V_56 ) )
return F_49 ( V_56 ) ;
F_54 ( V_71 ) ;
F_174 ( V_71 ) = V_56 ;
V_56 = F_33 ( L_31 , 0640 , V_27 , V_71 ,
& V_223 ) ;
if ( F_28 ( V_56 ) )
return F_49 ( V_56 ) ;
F_54 ( V_71 ) ;
F_175 ( V_71 ) = V_56 ;
V_56 = F_23 ( L_32 , V_55 | 0755 , V_27 , V_71 , NULL , NULL ,
& V_224 ) ;
if ( F_28 ( V_56 ) )
return F_49 ( V_56 ) ;
F_54 ( V_71 ) ;
F_163 ( V_71 ) = V_56 ;
return 0 ;
}
int F_179 ( struct V_70 * V_71 , struct V_7 * V_45 , const char * V_1 ,
struct V_7 * V_56 )
{
struct V_70 * V_218 ;
struct V_98 * V_192 ;
struct V_7 * V_27 ;
int error ;
F_16 ( ! V_71 ) ;
F_16 ( ! V_45 ) ;
F_16 ( ! F_141 ( & V_71 -> V_88 ) ) ;
if ( ! V_1 )
V_1 = V_71 -> V_165 . V_1 ;
if ( ! V_56 ) {
V_56 = F_34 ( V_1 , V_45 ) ;
if ( F_28 ( V_56 ) )
goto V_181;
} else
F_22 ( V_56 ) ;
F_168 ( V_71 ) = V_27 = V_56 ;
error = F_177 ( V_71 , V_27 ) ;
if ( error )
goto V_201;
F_148 (child, &ns->base.profiles, base.list) {
error = F_157 ( V_192 , F_178 ( V_71 ) ) ;
if ( error )
goto V_201;
}
F_148 (sub, &ns->sub_ns, base.list) {
F_61 ( & V_218 -> V_88 ) ;
error = F_179 ( V_218 , F_163 ( V_71 ) , NULL , NULL ) ;
F_62 ( & V_218 -> V_88 ) ;
if ( error )
goto V_201;
}
return 0 ;
V_181:
error = F_49 ( V_56 ) ;
V_201:
F_172 ( V_71 ) ;
return error ;
}
static struct V_70 * F_180 ( struct V_70 * V_225 , struct V_70 * V_71 )
{
struct V_70 * V_45 , * V_226 ;
if ( ! F_181 ( & V_71 -> V_216 ) ) {
V_226 = F_182 ( & V_71 -> V_216 , F_183 ( * V_71 ) , V_165 . V_178 ) ;
F_61 ( & V_226 -> V_88 ) ;
return V_226 ;
}
V_45 = V_71 -> V_45 ;
while ( V_71 != V_225 ) {
F_62 ( & V_71 -> V_88 ) ;
V_226 = F_184 ( V_71 , V_165 . V_178 ) ;
if ( ! F_185 ( V_226 , & V_45 -> V_216 , V_165 . V_178 ) ) {
F_61 ( & V_226 -> V_88 ) ;
return V_226 ;
}
V_71 = V_45 ;
V_45 = V_45 -> V_45 ;
}
return NULL ;
}
static struct V_98 * F_186 ( struct V_70 * V_225 ,
struct V_70 * V_71 )
{
for (; V_71 ; V_71 = F_180 ( V_225 , V_71 ) ) {
if ( ! F_181 ( & V_71 -> V_165 . V_227 ) )
return F_182 ( & V_71 -> V_165 . V_227 ,
struct V_98 , V_165 . V_178 ) ;
}
return NULL ;
}
static struct V_98 * F_187 ( struct V_98 * V_126 )
{
struct V_98 * V_45 ;
struct V_70 * V_71 = V_126 -> V_71 ;
if ( ! F_181 ( & V_126 -> V_165 . V_227 ) )
return F_182 ( & V_126 -> V_165 . V_227 , F_183 ( * V_126 ) ,
V_165 . V_178 ) ;
V_45 = F_188 ( V_126 -> V_45 ,
F_141 ( & V_126 -> V_71 -> V_88 ) ) ;
while ( V_45 ) {
V_126 = F_184 ( V_126 , V_165 . V_178 ) ;
if ( ! F_185 ( V_126 , & V_45 -> V_165 . V_227 , V_165 . V_178 ) )
return V_126 ;
V_126 = V_45 ;
V_45 = F_188 ( V_45 -> V_45 ,
F_141 ( & V_45 -> V_71 -> V_88 ) ) ;
}
V_126 = F_184 ( V_126 , V_165 . V_178 ) ;
if ( ! F_185 ( V_126 , & V_71 -> V_165 . V_227 , V_165 . V_178 ) )
return V_126 ;
return NULL ;
}
static struct V_98 * F_189 ( struct V_70 * V_225 ,
struct V_98 * V_99 )
{
struct V_98 * V_226 = F_187 ( V_99 ) ;
if ( V_226 )
return V_226 ;
return F_186 ( V_225 , F_180 ( V_225 , V_99 -> V_71 ) ) ;
}
static void * F_190 ( struct V_5 * V_75 , T_4 * V_64 )
{
struct V_98 * V_99 = NULL ;
struct V_70 * V_225 = F_68 () ;
T_4 V_228 = * V_64 ;
V_75 -> V_157 = V_225 ;
F_61 ( & V_225 -> V_88 ) ;
V_99 = F_186 ( V_225 , V_225 ) ;
for (; V_99 && V_228 > 0 ; V_228 -- )
V_99 = F_189 ( V_225 , V_99 ) ;
return V_99 ;
}
static void * F_191 ( struct V_5 * V_75 , void * V_126 , T_4 * V_64 )
{
struct V_98 * V_99 = V_126 ;
struct V_70 * V_71 = V_75 -> V_157 ;
( * V_64 ) ++ ;
return F_189 ( V_71 , V_99 ) ;
}
static void F_192 ( struct V_5 * V_75 , void * V_126 )
{
struct V_98 * V_99 = V_126 ;
struct V_70 * V_225 = V_75 -> V_157 , * V_71 ;
if ( V_99 ) {
for ( V_71 = V_99 -> V_71 ; V_71 && V_71 != V_225 ; V_71 = V_71 -> V_45 )
F_62 ( & V_71 -> V_88 ) ;
}
F_62 ( & V_225 -> V_88 ) ;
F_55 ( V_225 ) ;
}
static int F_193 ( struct V_5 * V_75 , void * V_126 )
{
struct V_98 * V_99 = (struct V_98 * ) V_126 ;
struct V_70 * V_225 = V_75 -> V_157 ;
F_194 ( V_75 , V_225 , & V_99 -> V_73 ,
V_229 | V_230 , V_57 ) ;
F_123 ( V_75 , '\n' ) ;
return 0 ;
}
static int F_195 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
if ( ! F_136 ( NULL ) )
return - V_174 ;
return F_196 ( V_74 , & V_231 ) ;
}
static int F_197 ( struct V_8 * V_8 , struct V_74 * V_74 )
{
return F_198 ( V_8 , V_74 ) ;
}
static int T_9 F_199 ( struct V_155 * V_156 ,
struct V_7 * V_45 )
{
int error = 0 ;
V_156 -> V_7 = F_200 ( V_156 -> V_1 ,
V_48 | V_156 -> V_28 ,
V_45 , V_156 ,
V_156 -> V_232 ) ;
if ( F_28 ( V_156 -> V_7 ) ) {
error = F_49 ( V_156 -> V_7 ) ;
V_156 -> V_7 = NULL ;
}
return error ;
}
static int T_9 F_201 ( struct V_155 * V_233 ,
struct V_7 * V_45 )
{
struct V_155 * V_156 ;
struct V_7 * V_27 ;
int error ;
V_27 = F_202 ( V_233 -> V_1 , V_45 ) ;
if ( F_28 ( V_27 ) )
return F_49 ( V_27 ) ;
V_233 -> V_7 = V_27 ;
for ( V_156 = V_233 -> V_154 . V_19 ; V_156 && V_156 -> V_1 ; ++ V_156 ) {
if ( V_156 -> V_158 == V_234 )
error = F_201 ( V_156 , V_233 -> V_7 ) ;
else
error = F_199 ( V_156 , V_233 -> V_7 ) ;
if ( error )
goto V_235;
}
return 0 ;
V_235:
F_203 ( V_233 ) ;
return error ;
}
static void T_9 F_204 ( struct V_155 * V_156 )
{
if ( ! V_156 -> V_7 )
return;
F_205 ( V_156 -> V_7 ) ;
V_156 -> V_7 = NULL ;
}
static void T_9 F_203 ( struct V_155 * V_233 )
{
struct V_155 * V_156 ;
for ( V_156 = V_233 -> V_154 . V_19 ; V_156 && V_156 -> V_1 ; ++ V_156 ) {
if ( V_156 -> V_158 == V_234 )
F_203 ( V_156 ) ;
else
F_204 ( V_156 ) ;
}
F_204 ( V_233 ) ;
}
void T_9 F_206 ( void )
{
F_203 ( & V_155 ) ;
}
static int F_207 ( struct V_7 * V_45 )
{
struct V_236 * V_237 = NULL ;
struct V_7 * V_7 ;
struct V_8 * V_8 ;
int V_137 = 0 ;
int error = F_24 ( V_45 -> V_238 -> V_239 , & V_237 , & V_137 ) ;
if ( error )
return error ;
F_26 ( F_3 ( V_45 ) ) ;
V_7 = F_27 ( V_240 , V_45 , strlen ( V_240 ) ) ;
if ( F_28 ( V_7 ) ) {
error = F_49 ( V_7 ) ;
goto V_80;
}
V_8 = F_15 ( V_45 -> F_3 -> V_34 ) ;
if ( ! V_8 ) {
error = - V_35 ;
goto V_241;
}
V_8 -> V_10 = F_17 () ;
V_8 -> V_12 = V_242 | V_243 | V_244 ;
V_8 -> V_36 = V_8 -> V_37 = V_8 -> V_38 = F_18 ( V_8 ) ;
F_208 ( V_8 , V_242 | V_243 | V_244 ,
F_209 ( V_245 , 3 ) ) ;
F_21 ( V_7 , V_8 ) ;
V_246 . V_7 = F_22 ( V_7 ) ;
V_246 . V_247 = F_210 ( V_237 ) ;
error = 0 ;
V_241:
F_31 ( V_7 ) ;
V_80:
F_30 ( F_3 ( V_45 ) ) ;
F_32 ( & V_237 , & V_137 ) ;
return error ;
}
static const char * F_211 ( struct V_7 * V_7 ,
struct V_8 * V_8 ,
struct V_248 * V_249 )
{
struct V_70 * V_71 ;
struct V_250 V_250 ;
if ( ! V_7 )
return F_25 ( - V_251 ) ;
V_71 = F_68 () ;
V_250 . V_247 = F_210 ( V_50 ) ;
V_250 . V_7 = F_22 ( F_168 ( V_71 ) ) ;
F_212 ( & V_250 ) ;
F_55 ( V_71 ) ;
return NULL ;
}
static int F_213 ( char * V_69 , T_3 V_66 , struct V_70 * V_71 ,
struct V_8 * V_8 )
{
int V_252 = snprintf ( V_69 , V_66 , L_3 , V_9 , V_8 -> V_10 ) ;
if ( V_252 < 0 || V_252 >= V_66 )
V_252 = - V_175 ;
return V_252 ;
}
static int F_214 ( struct V_7 * V_7 , char T_2 * V_85 ,
int V_253 )
{
struct V_70 * V_71 ;
char V_1 [ 32 ] ;
int V_252 ;
V_71 = F_68 () ;
V_252 = F_213 ( V_1 , sizeof( V_1 ) , V_71 , F_3 ( V_7 ) ) ;
if ( V_252 >= 0 )
V_252 = F_215 ( V_85 , V_253 , V_1 ) ;
F_55 ( V_71 ) ;
return V_252 ;
}
static int T_9 F_216 ( void )
{
struct V_7 * V_56 ;
int error ;
if ( ! V_254 )
return 0 ;
if ( V_155 . V_7 ) {
F_217 ( L_33 , V_255 ) ;
return - V_53 ;
}
V_50 = F_218 ( & V_49 ) ;
if ( F_28 ( V_50 ) )
F_219 ( L_34 ) ;
V_50 -> V_256 -> V_257 &= ~ V_258 ;
error = F_201 ( & V_155 , NULL ) ;
if ( error )
goto error;
V_56 = F_200 ( L_29 , 0666 , V_155 . V_7 ,
NULL , & V_221 ) ;
if ( F_28 ( V_56 ) ) {
error = F_49 ( V_56 ) ;
goto error;
}
F_173 ( V_259 ) = V_56 ;
V_56 = F_200 ( L_30 , 0666 , V_155 . V_7 ,
NULL , & V_222 ) ;
if ( F_28 ( V_56 ) ) {
error = F_49 ( V_56 ) ;
goto error;
}
F_174 ( V_259 ) = V_56 ;
V_56 = F_200 ( L_31 , 0666 , V_155 . V_7 ,
NULL , & V_223 ) ;
if ( F_28 ( V_56 ) ) {
error = F_49 ( V_56 ) ;
goto error;
}
F_175 ( V_259 ) = V_56 ;
V_56 = F_200 ( L_17 , 0444 , V_155 . V_7 ,
NULL , & V_220 ) ;
if ( F_28 ( V_56 ) ) {
error = F_49 ( V_56 ) ;
goto error;
}
F_176 ( V_259 ) = V_56 ;
F_61 ( & V_259 -> V_88 ) ;
error = F_179 ( V_259 , V_50 -> V_260 , L_35 ,
V_50 -> V_260 ) ;
F_62 ( & V_259 -> V_88 ) ;
if ( error )
goto error;
V_56 = F_220 ( L_36 , V_155 . V_7 ,
NULL , & V_261 ) ;
if ( F_28 ( V_56 ) ) {
error = F_49 ( V_56 ) ;
goto error;
}
error = F_207 ( V_155 . V_7 ) ;
if ( error )
goto error;
F_221 ( L_37 ) ;
return 0 ;
error:
F_206 () ;
F_217 ( L_38 ) ;
return error ;
}
