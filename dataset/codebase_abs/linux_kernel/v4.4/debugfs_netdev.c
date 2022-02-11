static T_1 F_1 (
struct V_1 * V_2 ,
char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 ,
T_1 (* F_2)( const struct V_1 * , char * , int ) )
{
char V_6 [ 70 ] ;
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
T_8 V_88 ;
V_88 = F_46 ( V_32 , (struct V_1 * ) V_2 ) ;
return F_12 ( V_6 , V_13 , L_9 , ( unsigned long long ) V_88 ) ;
}
static T_1 F_47 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
unsigned long long V_88 ;
int V_7 ;
int V_89 = 0 ;
if ( strncmp ( V_6 , L_10 , 5 ) == 0 ) {
if ( V_32 -> V_90 -> V_91 ) {
F_48 ( V_32 , V_2 ) ;
F_49 ( V_32 -> V_34 . V_35 , L_11 ) ;
}
} else {
if ( V_13 > 10 && V_6 [ 1 ] == '=' ) {
if ( V_6 [ 0 ] == '+' )
V_89 = 1 ;
else if ( V_6 [ 0 ] == '-' )
V_89 = - 1 ;
else
return - V_8 ;
V_6 += 2 ;
}
V_7 = F_50 ( V_6 , 10 , & V_88 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_89 )
V_88 = F_46 ( V_32 , V_2 ) + V_89 * V_88 ;
if ( V_32 -> V_90 -> V_92 ) {
F_51 ( V_32 , V_2 , V_88 ) ;
F_49 ( V_32 -> V_34 . V_35 ,
L_12 , V_88 ) ;
}
}
F_52 ( V_32 , V_2 ) ;
return V_13 ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_54 ( V_93 ) ;
F_54 ( V_94 ) ;
F_54 ( V_95 ) ;
F_54 ( V_96 ) ;
F_54 ( V_97 ) ;
F_54 ( V_98 ) ;
F_54 ( V_99 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_54 ( V_69 ) ;
F_54 ( V_100 ) ;
F_54 ( V_101 ) ;
F_56 ( V_102 , 0600 ) ;
F_56 ( V_103 , 0200 ) ;
F_56 ( V_104 , 0200 ) ;
F_56 ( V_77 , 0600 ) ;
F_56 ( V_81 , 0600 ) ;
F_56 ( V_83 , 0600 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_54 ( V_105 ) ;
F_56 ( V_102 , 0600 ) ;
F_54 ( V_106 ) ;
F_54 ( V_107 ) ;
F_54 ( V_108 ) ;
F_56 ( V_103 , 0200 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_56 ( V_88 , 0600 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_54 ( V_109 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_56 ( V_88 , 0600 ) ;
F_56 ( V_110 , 0400 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_111 * V_112 = F_62 ( L_13 ,
V_2 -> V_21 . V_113 ) ;
#define F_63 ( T_9 ) \
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
F_63 ( V_114 ) ;
F_63 ( V_115 ) ;
F_63 ( V_116 ) ;
F_63 ( V_117 ) ;
F_63 ( V_118 ) ;
F_63 ( V_119 ) ;
#undef F_63
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_111 * V_112 = F_62 ( L_14 ,
V_2 -> V_21 . V_113 ) ;
#define F_65 ( T_9 ) \
debugfs_create_file(#name, 0600, dir, sdata, &name##_ops);
F_65 ( V_120 ) ;
F_65 ( V_121 ) ;
F_65 ( V_122 ) ;
F_65 ( V_123 ) ;
F_65 ( V_124 ) ;
F_65 ( V_125 ) ;
F_65 ( V_126 ) ;
F_65 ( V_127 ) ;
F_65 ( V_128 ) ;
F_65 ( V_129 ) ;
F_65 ( V_130 ) ;
F_65 ( V_131 ) ;
F_65 ( V_132 ) ;
F_65 ( V_133 ) ;
F_65 ( V_134 ) ;
F_65 ( V_135 ) ;
F_65 ( V_136 ) ;
F_65 ( V_137 ) ;
F_65 ( V_138 ) ;
F_65 ( V_139 ) ;
F_65 ( V_140 ) ;
F_65 ( V_141 ) ;
F_65 ( V_142 ) ;
F_65 ( V_143 ) ;
F_65 ( V_144 ) ;
F_65 ( V_145 ) ;
#undef F_65
}
static void F_66 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_21 . V_113 )
return;
F_54 ( V_71 ) ;
F_54 ( V_146 ) ;
F_54 ( V_147 ) ;
F_54 ( V_148 ) ;
F_54 ( V_149 ) ;
if ( V_2 -> V_21 . type != V_150 )
F_53 ( V_2 ) ;
switch ( V_2 -> V_21 . type ) {
case V_151 :
#ifdef F_67
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
F_64 ( V_2 ) ;
#endif
break;
case V_42 :
F_55 ( V_2 ) ;
break;
case V_152 :
F_58 ( V_2 ) ;
break;
case V_27 :
F_57 ( V_2 ) ;
break;
case V_153 :
F_59 ( V_2 ) ;
break;
default:
break;
}
}
void F_68 ( struct V_1 * V_2 )
{
char V_6 [ 10 + V_154 ] ;
sprintf ( V_6 , L_15 , V_2 -> T_9 ) ;
V_2 -> V_21 . V_113 = F_62 ( V_6 ,
V_2 -> V_32 -> V_34 . V_35 -> V_155 ) ;
if ( V_2 -> V_21 . V_113 )
V_2 -> V_156 . V_157 = F_62 ( L_16 ,
V_2 -> V_21 . V_113 ) ;
F_66 ( V_2 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_21 . V_113 )
return;
F_70 ( V_2 -> V_21 . V_113 ) ;
V_2 -> V_21 . V_113 = NULL ;
V_2 -> V_156 . V_157 = NULL ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
char V_6 [ 10 + V_154 ] ;
V_112 = V_2 -> V_21 . V_113 ;
if ( ! V_112 )
return;
sprintf ( V_6 , L_15 , V_2 -> T_9 ) ;
if ( ! F_72 ( V_112 -> V_158 , V_112 , V_112 -> V_158 , V_6 ) )
F_73 ( V_2 ,
L_17 ,
V_6 ) ;
}
