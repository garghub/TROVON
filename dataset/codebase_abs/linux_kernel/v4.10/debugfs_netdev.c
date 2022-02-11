static T_1 F_1 (
struct V_1 * V_2 ,
char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 ,
T_1 (* F_2)( const struct V_1 * , char * , int ) )
{
char V_6 [ 200 ] ;
T_1 V_7 = - V_8 ;
F_3 ( & V_9 ) ;
V_7 = (* F_2)( V_2 , V_6 , sizeof( V_6 ) ) ;
F_4 ( & V_9 ) ;
if ( V_7 >= 0 )
V_7 = F_5 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ;
return V_7 ;
}
static T_1 F_6 (
struct V_1 * V_2 ,
const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 ,
T_1 (* F_7)( struct V_1 * , const char * , int ) )
{
char V_6 [ 64 ] ;
T_1 V_7 ;
if ( V_4 >= sizeof( V_6 ) )
return - V_10 ;
if ( F_8 ( V_6 , V_3 , V_4 ) )
return - V_11 ;
V_6 [ V_4 ] = '\0' ;
V_7 = - V_12 ;
F_9 () ;
V_7 = (* F_7)( V_2 , V_6 , V_4 ) ;
F_10 () ;
return V_7 ;
}
static T_1 F_11 (
const struct V_1 * V_2 ,
char * V_6 , int V_13 )
{
int V_14 , V_15 = 0 ;
const T_5 * V_16 = V_2 -> V_17 [ V_18 ] ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ )
V_15 += F_12 ( V_6 + V_15 , V_13 - V_15 , L_1 , V_16 [ V_14 ] ) ;
V_15 += F_12 ( V_6 + V_15 , V_13 - V_15 , L_2 ) ;
return V_15 ;
}
static T_1 F_13 (
const struct V_1 * V_2 ,
char * V_6 , int V_13 )
{
int V_14 , V_15 = 0 ;
const T_5 * V_16 = V_2 -> V_17 [ V_20 ] ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ )
V_15 += F_12 ( V_6 + V_15 , V_13 - V_15 , L_1 , V_16 [ V_14 ] ) ;
V_15 += F_12 ( V_6 + V_15 , V_13 - V_15 , L_2 ) ;
return V_15 ;
}
static T_1
F_14 ( const struct V_1 * V_2 ,
char * V_6 , int V_13 )
{
int V_15 ;
V_15 = F_12 ( V_6 , V_13 , L_3 ,
V_2 -> V_21 . V_22 [ V_23 ] ,
V_2 -> V_21 . V_22 [ V_24 ] ,
V_2 -> V_21 . V_22 [ V_25 ] ,
V_2 -> V_21 . V_22 [ V_26 ] ) ;
if ( V_2 -> V_21 . type == V_27 )
V_15 += F_12 ( V_6 + V_15 , V_13 - V_15 , L_4 ,
V_2 -> V_21 . V_28 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_29 V_30 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
int V_33 ;
if ( ! ( V_32 -> V_34 . V_35 -> V_36 & V_37 ) &&
V_30 == V_38 )
return - V_8 ;
if ( ! ( V_32 -> V_34 . V_35 -> V_36 & V_39 ) &&
( V_30 == V_40 ||
V_30 == V_41 ) )
return - V_8 ;
if ( V_2 -> V_21 . type != V_42 &&
V_2 -> V_21 . type != V_27 )
return - V_43 ;
F_16 ( V_2 ) ;
if ( V_2 -> V_21 . type == V_42 )
V_33 = F_17 ( V_2 , V_30 ) ;
else
V_33 = F_18 ( V_2 , V_30 ) ;
F_19 ( V_2 ) ;
return V_33 ;
}
static T_1 F_20 ( const struct V_1 * V_2 ,
char * V_6 , int V_13 )
{
if ( V_2 -> V_21 . type == V_42 )
return snprintf ( V_6 , V_13 , L_5 ,
V_44 [ V_2 -> V_45 . V_46 . V_47 ] ,
V_44 [ V_2 -> V_30 ] ) ;
if ( V_2 -> V_21 . type == V_27 )
return snprintf ( V_6 , V_13 , L_5 ,
V_44 [ V_2 -> V_45 . V_48 . V_47 ] ,
V_44 [ V_2 -> V_30 ] ) ;
return - V_8 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
const char * V_6 , int V_13 )
{
enum V_29 V_49 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
if ( strncmp ( V_6 , V_44 [ V_49 ] , V_13 ) == 0 ) {
int V_33 = F_15 ( V_2 , V_49 ) ;
if ( ! V_33 )
return V_13 ;
return V_33 ;
}
}
return - V_8 ;
}
static T_1 F_22 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
T_6 V_51 [ V_52 ] ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
T_7 V_57 ;
if ( ! F_23 ( V_6 , V_51 ) )
return - V_8 ;
if ( ! F_24 ( V_2 ) )
return - V_58 ;
V_54 = F_25 ( V_32 -> V_34 . V_59 + 24 + 100 ) ;
if ( ! V_54 )
return - V_60 ;
F_26 ( V_54 , V_32 -> V_34 . V_59 ) ;
V_56 = (struct V_55 * ) F_27 ( V_54 , 24 ) ;
memset ( V_56 , 0 , 24 ) ;
V_57 = F_28 ( V_61 | V_62 ) ;
switch ( V_2 -> V_21 . type ) {
case V_27 :
V_57 |= F_28 ( V_63 ) ;
memcpy ( V_56 -> V_64 , V_51 , V_52 ) ;
memcpy ( V_56 -> V_65 , V_2 -> V_21 . V_51 , V_52 ) ;
memcpy ( V_56 -> V_66 , V_2 -> V_21 . V_51 , V_52 ) ;
break;
case V_42 :
V_57 |= F_28 ( V_67 ) ;
F_16 ( V_2 ) ;
if ( ! V_2 -> V_45 . V_46 . V_68 ) {
F_19 ( V_2 ) ;
F_29 ( V_54 ) ;
return - V_58 ;
}
memcpy ( V_56 -> V_64 , V_2 -> V_45 . V_46 . V_68 -> V_69 , V_52 ) ;
memcpy ( V_56 -> V_65 , V_2 -> V_21 . V_51 , V_52 ) ;
memcpy ( V_56 -> V_66 , V_51 , V_52 ) ;
F_19 ( V_2 ) ;
break;
default:
F_29 ( V_54 ) ;
return - V_43 ;
}
V_56 -> V_70 = V_57 ;
memset ( F_27 ( V_54 , 50 ) , 0 , 50 ) ;
F_30 ( V_54 ) -> V_71 |= V_72 ;
F_31 ( V_2 , V_54 ) ;
return V_13 ;
}
static T_1 F_32 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
if ( ! F_24 ( V_2 ) || ! V_2 -> V_21 . V_73 . V_74 )
return - V_58 ;
F_33 ( & V_2 -> V_21 ) ;
return V_13 ;
}
static T_1 F_34 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
const struct V_75 * V_76 = & V_2 -> V_45 . V_46 ;
return snprintf ( V_6 , V_13 , L_6 , V_76 -> V_77 ) ;
}
static T_1 F_35 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_75 * V_76 = & V_2 -> V_45 . V_46 ;
T_6 V_78 ;
int V_7 ;
V_7 = F_36 ( V_6 , 0 , & V_78 ) ;
if ( V_7 )
return V_7 ;
if ( V_78 & ~ V_79 )
return - V_80 ;
V_76 -> V_77 = V_78 ;
return V_13 ;
}
static T_1 F_37 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
const struct V_75 * V_76 = & V_2 -> V_45 . V_46 ;
return snprintf ( V_6 , V_13 , L_6 , V_76 -> V_81 ) ;
}
static T_1 F_38 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_75 * V_76 = & V_2 -> V_45 . V_46 ;
unsigned long V_78 ;
int V_7 ;
V_7 = F_39 ( V_6 , 0 , & V_78 ) ;
if ( V_7 )
return - V_8 ;
if ( V_78 & ~ V_82 )
return - V_80 ;
V_76 -> V_81 = V_78 ;
return V_13 ;
}
static T_1 F_40 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
const struct V_75 * V_76 = & V_2 -> V_45 . V_46 ;
bool V_83 ;
V_83 = F_41 ( & V_2 -> V_32 -> V_34 , V_84 ) &&
! V_76 -> V_85 ;
return snprintf ( V_6 , V_13 , L_7 , V_83 ) ;
}
static T_1 F_42 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_75 * V_76 = & V_2 -> V_45 . V_46 ;
T_6 V_78 ;
int V_7 ;
V_7 = F_36 ( V_6 , 0 , & V_78 ) ;
if ( V_7 )
return V_7 ;
V_76 -> V_85 = ! V_78 ;
return V_13 ;
}
static T_1 F_43 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
return F_12 ( V_6 , V_13 , L_8 ,
F_44 ( & V_2 -> V_45 . V_48 . V_86 . V_87 ) ) ;
}
static T_1 F_45 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_88 * V_89 = F_46 ( V_2 -> V_21 . V_90 ) ;
int V_15 ;
F_47 ( & V_32 -> V_91 . V_92 ) ;
F_48 () ;
V_15 = F_12 ( V_6 ,
V_13 ,
L_9
L_10 ,
V_89 -> V_90 . V_93 ,
V_89 -> V_94 . V_95 ,
V_89 -> V_94 . V_96 ,
V_89 -> V_94 . V_97 ,
V_89 -> V_98 . V_99 ,
V_89 -> V_98 . V_100 ,
V_89 -> V_94 . V_101 ,
V_89 -> V_94 . V_102 ,
V_89 -> V_94 . V_103 ,
V_89 -> V_94 . V_104 ) ;
F_49 () ;
F_50 ( & V_32 -> V_91 . V_92 ) ;
return V_15 ;
}
static T_1 F_51 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
T_8 V_105 ;
V_105 = F_52 ( V_32 , (struct V_1 * ) V_2 ) ;
return F_12 ( V_6 , V_13 , L_11 , ( unsigned long long ) V_105 ) ;
}
static T_1 F_53 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
unsigned long long V_105 ;
int V_7 ;
int V_106 = 0 ;
if ( strncmp ( V_6 , L_12 , 5 ) == 0 ) {
if ( V_32 -> V_107 -> V_108 ) {
F_54 ( V_32 , V_2 ) ;
F_55 ( V_32 -> V_34 . V_35 , L_13 ) ;
}
} else {
if ( V_13 > 10 && V_6 [ 1 ] == '=' ) {
if ( V_6 [ 0 ] == '+' )
V_106 = 1 ;
else if ( V_6 [ 0 ] == '-' )
V_106 = - 1 ;
else
return - V_8 ;
V_6 += 2 ;
}
V_7 = F_56 ( V_6 , 10 , & V_105 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_106 && V_32 -> V_107 -> V_109 ) {
F_57 ( V_32 , V_2 , V_106 * V_105 ) ;
F_55 ( V_32 -> V_34 . V_35 ,
L_14 ,
V_106 * V_105 ) ;
} else if ( V_32 -> V_107 -> V_110 ) {
if ( V_106 )
V_105 = F_52 ( V_32 , V_2 ) +
V_106 * V_105 ;
F_58 ( V_32 , V_2 , V_105 ) ;
F_55 ( V_32 -> V_34 . V_35 ,
L_15 , V_105 ) ;
}
}
F_59 ( V_32 , V_2 ) ;
return V_13 ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_61 ( V_111 ) ;
F_61 ( V_112 ) ;
F_61 ( V_113 ) ;
F_61 ( V_114 ) ;
F_61 ( V_115 ) ;
F_61 ( V_116 ) ;
F_61 ( V_117 ) ;
if ( V_2 -> V_32 -> V_107 -> V_118 )
F_61 ( V_119 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_61 ( V_69 ) ;
F_61 ( V_120 ) ;
F_61 ( V_121 ) ;
F_63 ( V_122 , 0600 ) ;
F_63 ( V_123 , 0200 ) ;
F_63 ( V_124 , 0200 ) ;
F_63 ( V_77 , 0600 ) ;
F_63 ( V_81 , 0600 ) ;
F_63 ( V_83 , 0600 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_61 ( V_125 ) ;
F_63 ( V_122 , 0600 ) ;
F_61 ( V_126 ) ;
F_61 ( V_127 ) ;
F_61 ( V_128 ) ;
F_63 ( V_123 , 0200 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_66 ( L_16 , 0400 , V_2 -> V_21 . V_129 ,
V_2 , & V_130 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_63 ( V_105 , 0600 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_61 ( V_131 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_63 ( V_105 , 0600 ) ;
F_63 ( V_132 , 0400 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_71 ( L_17 ,
V_2 -> V_21 . V_129 ) ;
#define F_72 ( T_9 ) \
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
F_72 ( V_135 ) ;
F_72 ( V_136 ) ;
F_72 ( V_137 ) ;
F_72 ( V_138 ) ;
F_72 ( V_139 ) ;
F_72 ( V_140 ) ;
#undef F_72
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_71 ( L_18 ,
V_2 -> V_21 . V_129 ) ;
#define F_74 ( T_9 ) \
debugfs_create_file(#name, 0600, dir, sdata, &name##_ops);
F_74 ( V_141 ) ;
F_74 ( V_142 ) ;
F_74 ( V_143 ) ;
F_74 ( V_144 ) ;
F_74 ( V_145 ) ;
F_74 ( V_146 ) ;
F_74 ( V_147 ) ;
F_74 ( V_148 ) ;
F_74 ( V_149 ) ;
F_74 ( V_150 ) ;
F_74 ( V_151 ) ;
F_74 ( V_152 ) ;
F_74 ( V_153 ) ;
F_74 ( V_154 ) ;
F_74 ( V_155 ) ;
F_74 ( V_156 ) ;
F_74 ( V_157 ) ;
F_74 ( V_158 ) ;
F_74 ( V_159 ) ;
F_74 ( V_160 ) ;
F_74 ( V_161 ) ;
F_74 ( V_162 ) ;
F_74 ( V_163 ) ;
F_74 ( V_164 ) ;
F_74 ( V_165 ) ;
F_74 ( V_166 ) ;
#undef F_74
}
static void F_75 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_21 . V_129 )
return;
F_61 ( V_71 ) ;
F_61 ( V_167 ) ;
F_61 ( V_168 ) ;
F_61 ( V_169 ) ;
F_61 ( V_170 ) ;
if ( V_2 -> V_21 . type != V_171 )
F_60 ( V_2 ) ;
switch ( V_2 -> V_21 . type ) {
case V_172 :
#ifdef F_76
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
F_73 ( V_2 ) ;
#endif
break;
case V_42 :
F_62 ( V_2 ) ;
break;
case V_173 :
F_67 ( V_2 ) ;
break;
case V_27 :
F_64 ( V_2 ) ;
break;
case V_174 :
F_65 ( V_2 ) ;
break;
case V_175 :
F_68 ( V_2 ) ;
break;
default:
break;
}
}
void F_77 ( struct V_1 * V_2 )
{
char V_6 [ 10 + V_176 ] ;
sprintf ( V_6 , L_19 , V_2 -> T_9 ) ;
V_2 -> V_21 . V_129 = F_71 ( V_6 ,
V_2 -> V_32 -> V_34 . V_35 -> V_177 ) ;
if ( V_2 -> V_21 . V_129 )
V_2 -> V_178 . V_179 = F_71 ( L_20 ,
V_2 -> V_21 . V_129 ) ;
F_75 ( V_2 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_21 . V_129 )
return;
F_79 ( V_2 -> V_21 . V_129 ) ;
V_2 -> V_21 . V_129 = NULL ;
V_2 -> V_178 . V_179 = NULL ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_133 * V_134 ;
char V_6 [ 10 + V_176 ] ;
V_134 = V_2 -> V_21 . V_129 ;
if ( ! V_134 )
return;
sprintf ( V_6 , L_19 , V_2 -> T_9 ) ;
if ( ! F_81 ( V_134 -> V_180 , V_134 , V_134 -> V_180 , V_6 ) )
F_82 ( V_2 ,
L_21 ,
V_6 ) ;
}
