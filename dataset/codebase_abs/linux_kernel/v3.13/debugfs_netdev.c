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
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
return - V_39 ;
}
static T_1 F_21 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
T_5 V_47 [ V_48 ] ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
T_6 V_53 ;
if ( ! F_22 ( V_6 , V_47 ) )
return - V_8 ;
if ( ! F_23 ( V_2 ) )
return - V_54 ;
V_50 = F_24 ( V_29 -> V_31 . V_55 + 24 + 100 ) ;
if ( ! V_50 )
return - V_56 ;
F_25 ( V_50 , V_29 -> V_31 . V_55 ) ;
V_52 = (struct V_51 * ) F_26 ( V_50 , 24 ) ;
memset ( V_52 , 0 , 24 ) ;
V_53 = F_27 ( V_57 | V_58 ) ;
switch ( V_2 -> V_18 . type ) {
case V_24 :
V_53 |= F_27 ( V_59 ) ;
memcpy ( V_52 -> V_60 , V_47 , V_48 ) ;
memcpy ( V_52 -> V_61 , V_2 -> V_18 . V_47 , V_48 ) ;
memcpy ( V_52 -> V_62 , V_2 -> V_18 . V_47 , V_48 ) ;
break;
case V_38 :
V_53 |= F_27 ( V_63 ) ;
F_14 ( V_2 ) ;
if ( ! V_2 -> V_41 . V_42 . V_64 ) {
F_17 ( V_2 ) ;
F_28 ( V_50 ) ;
return - V_54 ;
}
memcpy ( V_52 -> V_60 , V_2 -> V_41 . V_42 . V_64 -> V_65 , V_48 ) ;
memcpy ( V_52 -> V_61 , V_2 -> V_18 . V_47 , V_48 ) ;
memcpy ( V_52 -> V_62 , V_47 , V_48 ) ;
F_17 ( V_2 ) ;
break;
default:
F_28 ( V_50 ) ;
return - V_39 ;
}
V_52 -> V_66 = V_53 ;
memset ( F_26 ( V_50 , 50 ) , 0 , 50 ) ;
F_29 ( V_50 ) -> V_32 |= V_67 ;
F_30 ( V_2 , V_50 ) ;
return V_16 ;
}
static T_1 F_31 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
const struct V_68 * V_69 = & V_2 -> V_41 . V_42 ;
return snprintf ( V_6 , V_16 , L_4 , V_69 -> V_70 ) ;
}
static T_1 F_32 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_68 * V_69 = & V_2 -> V_41 . V_42 ;
T_5 V_71 ;
int V_7 ;
V_7 = F_33 ( V_6 , 0 , & V_71 ) ;
if ( V_7 )
return V_7 ;
if ( V_71 & ~ V_72 )
return - V_73 ;
V_69 -> V_70 = V_71 ;
return V_16 ;
}
static T_1 F_34 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
const struct V_68 * V_69 = & V_2 -> V_41 . V_42 ;
return snprintf ( V_6 , V_16 , L_4 , V_69 -> V_74 ) ;
}
static T_1 F_35 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_68 * V_69 = & V_2 -> V_41 . V_42 ;
unsigned long V_71 ;
int V_7 ;
V_7 = F_36 ( V_6 , 0 , & V_71 ) ;
if ( V_7 )
return - V_8 ;
if ( V_71 & ~ V_75 )
return - V_73 ;
V_69 -> V_74 = V_71 ;
return V_16 ;
}
static T_1 F_37 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
return F_12 ( V_6 , V_16 , L_5 ,
F_38 ( & V_2 -> V_41 . V_44 . V_76 . V_77 ) ) ;
}
static T_1 F_39 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
T_7 V_78 ;
V_78 = F_40 ( V_29 , (struct V_1 * ) V_2 ) ;
return F_12 ( V_6 , V_16 , L_6 , ( unsigned long long ) V_78 ) ;
}
static T_1 F_41 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
unsigned long long V_78 ;
int V_7 ;
int V_79 = 0 ;
if ( strncmp ( V_6 , L_7 , 5 ) == 0 ) {
if ( V_29 -> V_80 -> V_81 ) {
F_42 ( V_29 , V_2 ) ;
F_43 ( V_29 -> V_31 . V_82 , L_8 ) ;
}
} else {
if ( V_16 > 10 && V_6 [ 1 ] == '=' ) {
if ( V_6 [ 0 ] == '+' )
V_79 = 1 ;
else if ( V_6 [ 0 ] == '-' )
V_79 = - 1 ;
else
return - V_8 ;
V_6 += 2 ;
}
V_7 = F_44 ( V_6 , 10 , & V_78 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_79 )
V_78 = F_40 ( V_29 , V_2 ) + V_79 * V_78 ;
if ( V_29 -> V_80 -> V_83 ) {
F_45 ( V_29 , V_2 , V_78 ) ;
F_43 ( V_29 -> V_31 . V_82 ,
L_9 , V_78 ) ;
}
}
return V_16 ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_84 ) ;
F_47 ( V_85 ) ;
F_47 ( V_86 ) ;
F_47 ( V_87 ) ;
F_47 ( V_88 ) ;
F_47 ( V_89 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_47 ( V_65 ) ;
F_47 ( V_90 ) ;
F_47 ( V_91 ) ;
F_47 ( V_92 ) ;
F_47 ( V_93 ) ;
F_49 ( V_94 , 0600 ) ;
F_49 ( V_95 , 0200 ) ;
F_49 ( V_70 , 0600 ) ;
F_49 ( V_74 , 0600 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_47 ( V_96 ) ;
F_49 ( V_94 , 0600 ) ;
F_47 ( V_97 ) ;
F_47 ( V_98 ) ;
F_47 ( V_99 ) ;
F_49 ( V_95 , 0200 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_49 ( V_78 , 0600 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_47 ( V_100 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_49 ( V_78 , 0600 ) ;
F_49 ( V_101 , 0400 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_102 * V_103 = F_55 ( L_10 ,
V_2 -> V_18 . V_104 ) ;
#define F_56 ( T_8 ) \
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
F_56 ( V_105 ) ;
F_56 ( V_106 ) ;
F_56 ( V_107 ) ;
F_56 ( V_108 ) ;
F_56 ( V_109 ) ;
F_56 ( V_110 ) ;
#undef F_56
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_102 * V_103 = F_55 ( L_11 ,
V_2 -> V_18 . V_104 ) ;
#define F_58 ( T_8 ) \
debugfs_create_file(#name, 0600, dir, sdata, &name##_ops);
F_58 ( V_111 ) ;
F_58 ( V_112 ) ;
F_58 ( V_113 ) ;
F_58 ( V_114 ) ;
F_58 ( V_115 ) ;
F_58 ( V_116 ) ;
F_58 ( V_117 ) ;
F_58 ( V_118 ) ;
F_58 ( V_119 ) ;
F_58 ( V_120 ) ;
F_58 ( V_121 ) ;
F_58 ( V_122 ) ;
F_58 ( V_123 ) ;
F_58 ( V_124 ) ;
F_58 ( V_125 ) ;
F_58 ( V_126 ) ;
F_58 ( V_127 ) ;
F_58 ( V_128 ) ;
F_58 ( V_129 ) ;
F_58 ( V_130 ) ;
F_58 ( V_131 ) ;
F_58 ( V_132 ) ;
F_58 ( V_133 ) ;
F_58 ( V_134 ) ;
F_58 ( V_135 ) ;
F_58 ( V_136 ) ;
#undef F_58
}
static void F_59 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 . V_104 )
return;
F_47 ( V_32 ) ;
F_47 ( V_137 ) ;
F_47 ( V_138 ) ;
F_47 ( V_139 ) ;
F_47 ( V_140 ) ;
if ( V_2 -> V_18 . type != V_141 )
F_46 ( V_2 ) ;
switch ( V_2 -> V_18 . type ) {
case V_142 :
#ifdef F_60
F_53 ( V_2 ) ;
F_54 ( V_2 ) ;
F_57 ( V_2 ) ;
#endif
break;
case V_38 :
F_48 ( V_2 ) ;
break;
case V_143 :
F_51 ( V_2 ) ;
break;
case V_24 :
F_50 ( V_2 ) ;
break;
case V_144 :
F_52 ( V_2 ) ;
break;
default:
break;
}
}
void F_61 ( struct V_1 * V_2 )
{
char V_6 [ 10 + V_145 ] ;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
V_2 -> V_18 . V_104 = F_55 ( V_6 ,
V_2 -> V_29 -> V_31 . V_82 -> V_146 ) ;
if ( V_2 -> V_18 . V_104 )
V_2 -> V_147 . V_148 = F_55 ( L_13 ,
V_2 -> V_18 . V_104 ) ;
F_59 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 . V_104 )
return;
F_63 ( V_2 -> V_18 . V_104 ) ;
V_2 -> V_18 . V_104 = NULL ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_102 * V_103 ;
char V_6 [ 10 + V_145 ] ;
V_103 = V_2 -> V_18 . V_104 ;
if ( ! V_103 )
return;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
if ( ! F_65 ( V_103 -> V_149 , V_103 , V_103 -> V_149 , V_6 ) )
F_66 ( V_2 ,
L_14 ,
V_6 ) ;
}
