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
if ( V_2 -> V_18 . type != V_38 )
return - V_39 ;
F_14 ( & V_2 -> V_40 . V_41 . V_42 ) ;
V_30 = F_15 ( V_2 , V_27 ) ;
F_16 ( & V_2 -> V_40 . V_41 . V_42 ) ;
return V_30 ;
}
static T_1 F_17 ( const struct V_1 * V_2 ,
char * V_6 , int V_16 )
{
if ( V_2 -> V_18 . type != V_38 )
return - V_39 ;
return snprintf ( V_6 , V_16 , L_3 ,
V_43 [ V_2 -> V_40 . V_41 . V_44 ] ,
V_43 [ V_2 -> V_27 ] ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
const char * V_6 , int V_16 )
{
enum V_26 V_45 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
if ( strncmp ( V_6 , V_43 [ V_45 ] , V_16 ) == 0 ) {
int V_30 = F_13 ( V_2 , V_45 ) ;
if ( ! V_30 )
return V_16 ;
return V_30 ;
}
}
return - V_8 ;
}
static T_1 F_19 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
return - V_39 ;
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
F_14 ( & V_2 -> V_40 . V_41 . V_42 ) ;
if ( ! V_2 -> V_40 . V_41 . V_64 ) {
F_16 ( & V_2 -> V_40 . V_41 . V_42 ) ;
F_27 ( V_50 ) ;
return - V_54 ;
}
memcpy ( V_52 -> V_60 , V_2 -> V_40 . V_41 . V_64 -> V_65 , V_48 ) ;
memcpy ( V_52 -> V_61 , V_2 -> V_18 . V_47 , V_48 ) ;
memcpy ( V_52 -> V_62 , V_47 , V_48 ) ;
F_16 ( & V_2 -> V_40 . V_41 . V_42 ) ;
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
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
const struct V_68 * V_69 = & V_2 -> V_40 . V_41 ;
return snprintf ( V_6 , V_16 , L_4 , V_69 -> V_70 ) ;
}
static T_1 F_31 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_68 * V_69 = & V_2 -> V_40 . V_41 ;
T_5 V_71 ;
int V_7 ;
V_7 = F_32 ( V_6 , 0 , & V_71 ) ;
if ( V_7 )
return V_7 ;
if ( V_71 & ~ V_72 )
return - V_73 ;
V_69 -> V_70 = V_71 ;
return V_16 ;
}
static T_1 F_33 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
const struct V_68 * V_69 = & V_2 -> V_40 . V_41 ;
return snprintf ( V_6 , V_16 , L_4 , V_69 -> V_74 ) ;
}
static T_1 F_34 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_68 * V_69 = & V_2 -> V_40 . V_41 ;
unsigned long V_71 ;
int V_7 ;
V_7 = F_35 ( V_6 , 0 , & V_71 ) ;
if ( V_7 )
return - V_8 ;
if ( V_71 & ~ V_75 )
return - V_73 ;
V_69 -> V_74 = V_71 ;
return V_16 ;
}
static T_1 F_36 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
return F_12 ( V_6 , V_16 , L_5 ,
F_37 ( & V_2 -> V_40 . V_76 . V_77 . V_78 ) ) ;
}
static T_1 F_38 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
T_7 V_79 ;
V_79 = F_39 ( V_29 , (struct V_1 * ) V_2 ) ;
return F_12 ( V_6 , V_16 , L_6 , ( unsigned long long ) V_79 ) ;
}
static T_1 F_40 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
unsigned long long V_79 ;
int V_7 ;
int V_80 = 0 ;
if ( strncmp ( V_6 , L_7 , 5 ) == 0 ) {
if ( V_29 -> V_81 -> V_82 ) {
F_41 ( V_29 , V_2 ) ;
F_42 ( V_29 -> V_31 . V_83 , L_8 ) ;
}
} else {
if ( V_16 > 10 && V_6 [ 1 ] == '=' ) {
if ( V_6 [ 0 ] == '+' )
V_80 = 1 ;
else if ( V_6 [ 0 ] == '-' )
V_80 = - 1 ;
else
return - V_8 ;
V_6 += 2 ;
}
V_7 = F_43 ( V_6 , 10 , & V_79 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_80 )
V_79 = F_39 ( V_29 , V_2 ) + V_80 * V_79 ;
if ( V_29 -> V_81 -> V_84 ) {
F_44 ( V_29 , V_2 , V_79 ) ;
F_42 ( V_29 -> V_31 . V_83 ,
L_9 , V_79 ) ;
}
}
return V_16 ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_85 ) ;
F_46 ( V_86 ) ;
F_46 ( V_87 ) ;
F_46 ( V_88 ) ;
F_46 ( V_89 ) ;
F_46 ( V_90 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_46 ( V_65 ) ;
F_46 ( V_91 ) ;
F_46 ( V_92 ) ;
F_46 ( V_93 ) ;
F_48 ( V_94 , 0600 ) ;
F_48 ( V_95 , 0200 ) ;
F_48 ( V_70 , 0600 ) ;
F_48 ( V_74 , 0600 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_46 ( V_96 ) ;
F_46 ( V_97 ) ;
F_46 ( V_98 ) ;
F_46 ( V_99 ) ;
F_48 ( V_95 , 0200 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_48 ( V_79 , 0600 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_46 ( V_100 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_48 ( V_79 , 0600 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = F_54 ( L_10 ,
V_2 -> V_103 . V_102 ) ;
#define F_55 ( T_8 ) \
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
F_55 ( V_104 ) ;
F_55 ( V_105 ) ;
F_55 ( V_106 ) ;
F_55 ( V_107 ) ;
F_55 ( V_108 ) ;
F_55 ( V_109 ) ;
F_55 ( V_110 ) ;
#undef F_55
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = F_54 ( L_11 ,
V_2 -> V_103 . V_102 ) ;
#define F_57 ( T_8 ) \
debugfs_create_file(#name, 0600, dir, sdata, &name##_ops);
F_57 ( V_111 ) ;
F_57 ( V_112 ) ;
F_57 ( V_113 ) ;
F_57 ( V_114 ) ;
F_57 ( V_115 ) ;
F_57 ( V_116 ) ;
F_57 ( V_117 ) ;
F_57 ( V_118 ) ;
F_57 ( V_119 ) ;
F_57 ( V_120 ) ;
F_57 ( V_121 ) ;
F_57 ( V_122 ) ;
F_57 ( V_123 ) ;
F_57 ( V_124 ) ;
F_57 ( V_125 ) ;
F_57 ( V_126 ) ;
F_57 ( V_127 ) ;
F_57 ( V_128 ) ;
F_57 ( V_129 ) ;
F_57 ( V_130 ) ;
F_57 ( V_131 ) ;
F_57 ( V_132 ) ;
F_57 ( V_133 ) ;
F_57 ( V_134 ) ;
#undef F_57
}
static void F_58 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_103 . V_102 )
return;
F_46 ( V_32 ) ;
F_46 ( V_135 ) ;
F_46 ( V_136 ) ;
F_46 ( V_137 ) ;
F_46 ( V_138 ) ;
if ( V_2 -> V_18 . type != V_139 )
F_45 ( V_2 ) ;
switch ( V_2 -> V_18 . type ) {
case V_140 :
#ifdef F_59
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_56 ( V_2 ) ;
#endif
break;
case V_38 :
F_47 ( V_2 ) ;
break;
case V_141 :
F_50 ( V_2 ) ;
break;
case V_24 :
F_49 ( V_2 ) ;
break;
case V_142 :
F_51 ( V_2 ) ;
break;
default:
break;
}
}
void F_60 ( struct V_1 * V_2 )
{
char V_6 [ 10 + V_143 ] ;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
V_2 -> V_103 . V_102 = F_54 ( V_6 ,
V_2 -> V_29 -> V_31 . V_83 -> V_144 ) ;
if ( V_2 -> V_103 . V_102 )
V_2 -> V_103 . V_145 = F_54 ( L_13 ,
V_2 -> V_103 . V_102 ) ;
F_58 ( V_2 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_103 . V_102 )
return;
F_62 ( V_2 -> V_103 . V_102 ) ;
V_2 -> V_103 . V_102 = NULL ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_101 * V_102 ;
char V_6 [ 10 + V_143 ] ;
V_102 = V_2 -> V_103 . V_102 ;
if ( ! V_102 )
return;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
if ( ! F_64 ( V_102 -> V_146 , V_102 , V_102 -> V_146 , V_6 ) )
F_65 ( V_2 ,
L_14 ,
V_6 ) ;
}
