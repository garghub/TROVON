static T_1 F_1 (
struct V_1 * V_2 ,
char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 ,
T_1 (* F_2)( const struct V_1 * , char * , int ) )
{
char V_6 [ 70 ] ;
T_1 V_7 = - V_8 ;
F_3 ( & V_9 ) ;
if ( V_2 -> V_10 -> V_11 == V_12 )
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
return - V_13 ;
if ( F_8 ( V_6 , V_3 , V_4 ) )
return - V_14 ;
V_6 [ V_4 ] = '\0' ;
V_7 = - V_15 ;
F_9 () ;
if ( V_2 -> V_10 -> V_11 == V_12 )
V_7 = (* F_7)( V_2 , V_6 , V_4 ) ;
F_10 () ;
return V_7 ;
}
static T_1
F_11 ( const struct V_1 * V_2 ,
char * V_6 , int V_16 )
{
int V_17 ;
V_17 = F_12 ( V_6 , V_16 , L_1 ,
V_2 -> V_18 . V_19 [ V_20 ] ,
V_2 -> V_18 . V_19 [ V_21 ] ,
V_2 -> V_18 . V_19 [ V_22 ] ,
V_2 -> V_18 . V_19 [ V_23 ] ) ;
if ( V_2 -> V_18 . type == V_24 )
V_17 += F_12 ( V_6 + V_17 , V_16 - V_17 , L_2 ,
V_2 -> V_18 . V_25 ) ;
return V_17 ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_26 V_27 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
int V_30 ;
if ( ! ( V_29 -> V_31 . V_32 & V_33 ) &&
V_27 == V_34 )
return - V_8 ;
if ( ! ( V_29 -> V_31 . V_32 & V_35 ) &&
( V_27 == V_36 ||
V_27 == V_37 ) )
return - V_8 ;
if ( V_2 -> V_18 . type != V_38 &&
V_2 -> V_18 . type != V_24 )
return - V_39 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_18 . type == V_38 )
V_30 = F_15 ( V_2 , V_27 ) ;
else
V_30 = F_16 ( V_2 , V_27 ) ;
F_17 ( V_2 ) ;
return V_30 ;
}
static T_1 F_18 ( const struct V_1 * V_2 ,
char * V_6 , int V_16 )
{
if ( V_2 -> V_18 . type == V_38 )
return snprintf ( V_6 , V_16 , L_3 ,
V_40 [ V_2 -> V_41 . V_42 . V_43 ] ,
V_40 [ V_2 -> V_27 ] ) ;
if ( V_2 -> V_18 . type == V_24 )
return snprintf ( V_6 , V_16 , L_3 ,
V_40 [ V_2 -> V_41 . V_44 . V_43 ] ,
V_40 [ V_2 -> V_27 ] ) ;
return - V_8 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
const char * V_6 , int V_16 )
{
enum V_26 V_45 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
if ( strncmp ( V_6 , V_40 [ V_45 ] , V_16 ) == 0 ) {
int V_30 = F_13 ( V_2 , V_45 ) ;
if ( ! V_30 )
return V_16 ;
return V_30 ;
}
}
return - V_8 ;
}
static T_1 F_20 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
T_5 V_47 [ V_48 ] ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
T_6 V_53 ;
if ( ! F_21 ( V_6 , V_47 ) )
return - V_8 ;
if ( ! F_22 ( V_2 ) )
return - V_54 ;
V_50 = F_23 ( V_29 -> V_31 . V_55 + 24 + 100 ) ;
if ( ! V_50 )
return - V_56 ;
F_24 ( V_50 , V_29 -> V_31 . V_55 ) ;
V_52 = (struct V_51 * ) F_25 ( V_50 , 24 ) ;
memset ( V_52 , 0 , 24 ) ;
V_53 = F_26 ( V_57 | V_58 ) ;
switch ( V_2 -> V_18 . type ) {
case V_24 :
V_53 |= F_26 ( V_59 ) ;
memcpy ( V_52 -> V_60 , V_47 , V_48 ) ;
memcpy ( V_52 -> V_61 , V_2 -> V_18 . V_47 , V_48 ) ;
memcpy ( V_52 -> V_62 , V_2 -> V_18 . V_47 , V_48 ) ;
break;
case V_38 :
V_53 |= F_26 ( V_63 ) ;
F_14 ( V_2 ) ;
if ( ! V_2 -> V_41 . V_42 . V_64 ) {
F_17 ( V_2 ) ;
F_27 ( V_50 ) ;
return - V_54 ;
}
memcpy ( V_52 -> V_60 , V_2 -> V_41 . V_42 . V_64 -> V_65 , V_48 ) ;
memcpy ( V_52 -> V_61 , V_2 -> V_18 . V_47 , V_48 ) ;
memcpy ( V_52 -> V_62 , V_47 , V_48 ) ;
F_17 ( V_2 ) ;
break;
default:
F_27 ( V_50 ) ;
return - V_39 ;
}
V_52 -> V_66 = V_53 ;
memset ( F_25 ( V_50 , 50 ) , 0 , 50 ) ;
F_28 ( V_50 ) -> V_32 |= V_67 ;
F_29 ( V_2 , V_50 ) ;
return V_16 ;
}
static T_1 F_30 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
if ( ! F_22 ( V_2 ) || ! V_2 -> V_18 . V_68 . V_69 )
return - V_54 ;
F_31 ( & V_2 -> V_18 ) ;
return V_16 ;
}
static T_1 F_32 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
const struct V_70 * V_71 = & V_2 -> V_41 . V_42 ;
return snprintf ( V_6 , V_16 , L_4 , V_71 -> V_72 ) ;
}
static T_1 F_33 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_70 * V_71 = & V_2 -> V_41 . V_42 ;
T_5 V_73 ;
int V_7 ;
V_7 = F_34 ( V_6 , 0 , & V_73 ) ;
if ( V_7 )
return V_7 ;
if ( V_73 & ~ V_74 )
return - V_75 ;
V_71 -> V_72 = V_73 ;
return V_16 ;
}
static T_1 F_35 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
const struct V_70 * V_71 = & V_2 -> V_41 . V_42 ;
return snprintf ( V_6 , V_16 , L_4 , V_71 -> V_76 ) ;
}
static T_1 F_36 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_70 * V_71 = & V_2 -> V_41 . V_42 ;
unsigned long V_73 ;
int V_7 ;
V_7 = F_37 ( V_6 , 0 , & V_73 ) ;
if ( V_7 )
return - V_8 ;
if ( V_73 & ~ V_77 )
return - V_75 ;
V_71 -> V_76 = V_73 ;
return V_16 ;
}
static T_1 F_38 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
return F_12 ( V_6 , V_16 , L_5 ,
F_39 ( & V_2 -> V_41 . V_44 . V_78 . V_79 ) ) ;
}
static T_1 F_40 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
T_7 V_80 ;
V_80 = F_41 ( V_29 , (struct V_1 * ) V_2 ) ;
return F_12 ( V_6 , V_16 , L_6 , ( unsigned long long ) V_80 ) ;
}
static T_1 F_42 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
unsigned long long V_80 ;
int V_7 ;
int V_81 = 0 ;
if ( strncmp ( V_6 , L_7 , 5 ) == 0 ) {
if ( V_29 -> V_82 -> V_83 ) {
F_43 ( V_29 , V_2 ) ;
F_44 ( V_29 -> V_31 . V_84 , L_8 ) ;
}
} else {
if ( V_16 > 10 && V_6 [ 1 ] == '=' ) {
if ( V_6 [ 0 ] == '+' )
V_81 = 1 ;
else if ( V_6 [ 0 ] == '-' )
V_81 = - 1 ;
else
return - V_8 ;
V_6 += 2 ;
}
V_7 = F_45 ( V_6 , 10 , & V_80 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_81 )
V_80 = F_41 ( V_29 , V_2 ) + V_81 * V_80 ;
if ( V_29 -> V_82 -> V_85 ) {
F_46 ( V_29 , V_2 , V_80 ) ;
F_44 ( V_29 -> V_31 . V_84 ,
L_9 , V_80 ) ;
}
}
F_47 ( V_29 , V_2 ) ;
return V_16 ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( V_86 ) ;
F_49 ( V_87 ) ;
F_49 ( V_88 ) ;
F_49 ( V_89 ) ;
F_49 ( V_90 ) ;
F_49 ( V_91 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_49 ( V_65 ) ;
F_49 ( V_92 ) ;
F_49 ( V_93 ) ;
F_49 ( V_94 ) ;
F_49 ( V_95 ) ;
F_51 ( V_96 , 0600 ) ;
F_51 ( V_97 , 0200 ) ;
F_51 ( V_98 , 0200 ) ;
F_51 ( V_72 , 0600 ) ;
F_51 ( V_76 , 0600 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_49 ( V_99 ) ;
F_51 ( V_96 , 0600 ) ;
F_49 ( V_100 ) ;
F_49 ( V_101 ) ;
F_49 ( V_102 ) ;
F_51 ( V_97 , 0200 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_51 ( V_80 , 0600 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_49 ( V_103 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_51 ( V_80 , 0600 ) ;
F_51 ( V_104 , 0400 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_105 * V_106 = F_57 ( L_10 ,
V_2 -> V_18 . V_107 ) ;
#define F_58 ( T_8 ) \
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
F_58 ( V_108 ) ;
F_58 ( V_109 ) ;
F_58 ( V_110 ) ;
F_58 ( V_111 ) ;
F_58 ( V_112 ) ;
F_58 ( V_113 ) ;
#undef F_58
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_105 * V_106 = F_57 ( L_11 ,
V_2 -> V_18 . V_107 ) ;
#define F_60 ( T_8 ) \
debugfs_create_file(#name, 0600, dir, sdata, &name##_ops);
F_60 ( V_114 ) ;
F_60 ( V_115 ) ;
F_60 ( V_116 ) ;
F_60 ( V_117 ) ;
F_60 ( V_118 ) ;
F_60 ( V_119 ) ;
F_60 ( V_120 ) ;
F_60 ( V_121 ) ;
F_60 ( V_122 ) ;
F_60 ( V_123 ) ;
F_60 ( V_124 ) ;
F_60 ( V_125 ) ;
F_60 ( V_126 ) ;
F_60 ( V_127 ) ;
F_60 ( V_128 ) ;
F_60 ( V_129 ) ;
F_60 ( V_130 ) ;
F_60 ( V_131 ) ;
F_60 ( V_132 ) ;
F_60 ( V_133 ) ;
F_60 ( V_134 ) ;
F_60 ( V_135 ) ;
F_60 ( V_136 ) ;
F_60 ( V_137 ) ;
F_60 ( V_138 ) ;
F_60 ( V_139 ) ;
#undef F_60
}
static void F_61 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 . V_107 )
return;
F_49 ( V_32 ) ;
F_49 ( V_140 ) ;
F_49 ( V_141 ) ;
F_49 ( V_142 ) ;
F_49 ( V_143 ) ;
if ( V_2 -> V_18 . type != V_144 )
F_48 ( V_2 ) ;
switch ( V_2 -> V_18 . type ) {
case V_145 :
#ifdef F_62
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_59 ( V_2 ) ;
#endif
break;
case V_38 :
F_50 ( V_2 ) ;
break;
case V_146 :
F_53 ( V_2 ) ;
break;
case V_24 :
F_52 ( V_2 ) ;
break;
case V_147 :
F_54 ( V_2 ) ;
break;
default:
break;
}
}
void F_63 ( struct V_1 * V_2 )
{
char V_6 [ 10 + V_148 ] ;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
V_2 -> V_18 . V_107 = F_57 ( V_6 ,
V_2 -> V_29 -> V_31 . V_84 -> V_149 ) ;
if ( V_2 -> V_18 . V_107 )
V_2 -> V_150 . V_151 = F_57 ( L_13 ,
V_2 -> V_18 . V_107 ) ;
F_61 ( V_2 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 . V_107 )
return;
F_65 ( V_2 -> V_18 . V_107 ) ;
V_2 -> V_18 . V_107 = NULL ;
}
void F_66 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
char V_6 [ 10 + V_148 ] ;
V_106 = V_2 -> V_18 . V_107 ;
if ( ! V_106 )
return;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
if ( ! F_67 ( V_106 -> V_152 , V_106 , V_106 -> V_152 , V_6 ) )
F_68 ( V_2 ,
L_14 ,
V_6 ) ;
}
