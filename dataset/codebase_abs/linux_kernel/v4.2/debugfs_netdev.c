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
static T_1
F_11 ( const struct V_1 * V_2 ,
char * V_6 , int V_13 )
{
int V_14 ;
V_14 = F_12 ( V_6 , V_13 , L_1 ,
V_2 -> V_15 . V_16 [ V_17 ] ,
V_2 -> V_15 . V_16 [ V_18 ] ,
V_2 -> V_15 . V_16 [ V_19 ] ,
V_2 -> V_15 . V_16 [ V_20 ] ) ;
if ( V_2 -> V_15 . type == V_21 )
V_14 += F_12 ( V_6 + V_14 , V_13 - V_14 , L_2 ,
V_2 -> V_15 . V_22 ) ;
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_23 V_24 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_27 ;
if ( ! ( V_26 -> V_28 . V_29 -> V_30 & V_31 ) &&
V_24 == V_32 )
return - V_8 ;
if ( ! ( V_26 -> V_28 . V_29 -> V_30 & V_33 ) &&
( V_24 == V_34 ||
V_24 == V_35 ) )
return - V_8 ;
if ( V_2 -> V_15 . type != V_36 &&
V_2 -> V_15 . type != V_21 )
return - V_37 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_15 . type == V_36 )
V_27 = F_15 ( V_2 , V_24 ) ;
else
V_27 = F_16 ( V_2 , V_24 ) ;
F_17 ( V_2 ) ;
return V_27 ;
}
static T_1 F_18 ( const struct V_1 * V_2 ,
char * V_6 , int V_13 )
{
if ( V_2 -> V_15 . type == V_36 )
return snprintf ( V_6 , V_13 , L_3 ,
V_38 [ V_2 -> V_39 . V_40 . V_41 ] ,
V_38 [ V_2 -> V_24 ] ) ;
if ( V_2 -> V_15 . type == V_21 )
return snprintf ( V_6 , V_13 , L_3 ,
V_38 [ V_2 -> V_39 . V_42 . V_41 ] ,
V_38 [ V_2 -> V_24 ] ) ;
return - V_8 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
const char * V_6 , int V_13 )
{
enum V_23 V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( strncmp ( V_6 , V_38 [ V_43 ] , V_13 ) == 0 ) {
int V_27 = F_13 ( V_2 , V_43 ) ;
if ( ! V_27 )
return V_13 ;
return V_27 ;
}
}
return - V_8 ;
}
static T_1 F_20 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
T_5 V_45 [ V_46 ] ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
T_6 V_51 ;
if ( ! F_21 ( V_6 , V_45 ) )
return - V_8 ;
if ( ! F_22 ( V_2 ) )
return - V_52 ;
V_48 = F_23 ( V_26 -> V_28 . V_53 + 24 + 100 ) ;
if ( ! V_48 )
return - V_54 ;
F_24 ( V_48 , V_26 -> V_28 . V_53 ) ;
V_50 = (struct V_49 * ) F_25 ( V_48 , 24 ) ;
memset ( V_50 , 0 , 24 ) ;
V_51 = F_26 ( V_55 | V_56 ) ;
switch ( V_2 -> V_15 . type ) {
case V_21 :
V_51 |= F_26 ( V_57 ) ;
memcpy ( V_50 -> V_58 , V_45 , V_46 ) ;
memcpy ( V_50 -> V_59 , V_2 -> V_15 . V_45 , V_46 ) ;
memcpy ( V_50 -> V_60 , V_2 -> V_15 . V_45 , V_46 ) ;
break;
case V_36 :
V_51 |= F_26 ( V_61 ) ;
F_14 ( V_2 ) ;
if ( ! V_2 -> V_39 . V_40 . V_62 ) {
F_17 ( V_2 ) ;
F_27 ( V_48 ) ;
return - V_52 ;
}
memcpy ( V_50 -> V_58 , V_2 -> V_39 . V_40 . V_62 -> V_63 , V_46 ) ;
memcpy ( V_50 -> V_59 , V_2 -> V_15 . V_45 , V_46 ) ;
memcpy ( V_50 -> V_60 , V_45 , V_46 ) ;
F_17 ( V_2 ) ;
break;
default:
F_27 ( V_48 ) ;
return - V_37 ;
}
V_50 -> V_64 = V_51 ;
memset ( F_25 ( V_48 , 50 ) , 0 , 50 ) ;
F_28 ( V_48 ) -> V_65 |= V_66 ;
F_29 ( V_2 , V_48 ) ;
return V_13 ;
}
static T_1 F_30 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
if ( ! F_22 ( V_2 ) || ! V_2 -> V_15 . V_67 . V_68 )
return - V_52 ;
F_31 ( & V_2 -> V_15 ) ;
return V_13 ;
}
static T_1 F_32 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
const struct V_69 * V_70 = & V_2 -> V_39 . V_40 ;
return snprintf ( V_6 , V_13 , L_4 , V_70 -> V_71 ) ;
}
static T_1 F_33 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_69 * V_70 = & V_2 -> V_39 . V_40 ;
T_5 V_72 ;
int V_7 ;
V_7 = F_34 ( V_6 , 0 , & V_72 ) ;
if ( V_7 )
return V_7 ;
if ( V_72 & ~ V_73 )
return - V_74 ;
V_70 -> V_71 = V_72 ;
return V_13 ;
}
static T_1 F_35 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
const struct V_69 * V_70 = & V_2 -> V_39 . V_40 ;
return snprintf ( V_6 , V_13 , L_4 , V_70 -> V_75 ) ;
}
static T_1 F_36 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_69 * V_70 = & V_2 -> V_39 . V_40 ;
unsigned long V_72 ;
int V_7 ;
V_7 = F_37 ( V_6 , 0 , & V_72 ) ;
if ( V_7 )
return - V_8 ;
if ( V_72 & ~ V_76 )
return - V_74 ;
V_70 -> V_75 = V_72 ;
return V_13 ;
}
static T_1 F_38 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
return F_12 ( V_6 , V_13 , L_5 ,
F_39 ( & V_2 -> V_39 . V_42 . V_77 . V_78 ) ) ;
}
static T_1 F_40 (
const struct V_1 * V_2 , char * V_6 , int V_13 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
T_7 V_79 ;
V_79 = F_41 ( V_26 , (struct V_1 * ) V_2 ) ;
return F_12 ( V_6 , V_13 , L_6 , ( unsigned long long ) V_79 ) ;
}
static T_1 F_42 (
struct V_1 * V_2 , const char * V_6 , int V_13 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
unsigned long long V_79 ;
int V_7 ;
int V_80 = 0 ;
if ( strncmp ( V_6 , L_7 , 5 ) == 0 ) {
if ( V_26 -> V_81 -> V_82 ) {
F_43 ( V_26 , V_2 ) ;
F_44 ( V_26 -> V_28 . V_29 , L_8 ) ;
}
} else {
if ( V_13 > 10 && V_6 [ 1 ] == '=' ) {
if ( V_6 [ 0 ] == '+' )
V_80 = 1 ;
else if ( V_6 [ 0 ] == '-' )
V_80 = - 1 ;
else
return - V_8 ;
V_6 += 2 ;
}
V_7 = F_45 ( V_6 , 10 , & V_79 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_80 )
V_79 = F_41 ( V_26 , V_2 ) + V_80 * V_79 ;
if ( V_26 -> V_81 -> V_83 ) {
F_46 ( V_26 , V_2 , V_79 ) ;
F_44 ( V_26 -> V_28 . V_29 ,
L_9 , V_79 ) ;
}
}
F_47 ( V_26 , V_2 ) ;
return V_13 ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( V_84 ) ;
F_49 ( V_85 ) ;
F_49 ( V_86 ) ;
F_49 ( V_87 ) ;
F_49 ( V_88 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_49 ( V_63 ) ;
F_49 ( V_89 ) ;
F_49 ( V_90 ) ;
F_49 ( V_91 ) ;
F_49 ( V_92 ) ;
F_51 ( V_93 , 0600 ) ;
F_51 ( V_94 , 0200 ) ;
F_51 ( V_95 , 0200 ) ;
F_51 ( V_71 , 0600 ) ;
F_51 ( V_75 , 0600 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_49 ( V_96 ) ;
F_51 ( V_93 , 0600 ) ;
F_49 ( V_97 ) ;
F_49 ( V_98 ) ;
F_49 ( V_99 ) ;
F_51 ( V_94 , 0200 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_51 ( V_79 , 0600 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_49 ( V_100 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_51 ( V_79 , 0600 ) ;
F_51 ( V_101 , 0400 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_102 * V_103 = F_57 ( L_10 ,
V_2 -> V_15 . V_104 ) ;
#define F_58 ( T_8 ) \
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
F_58 ( V_105 ) ;
F_58 ( V_106 ) ;
F_58 ( V_107 ) ;
F_58 ( V_108 ) ;
F_58 ( V_109 ) ;
F_58 ( V_110 ) ;
#undef F_58
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_102 * V_103 = F_57 ( L_11 ,
V_2 -> V_15 . V_104 ) ;
#define F_60 ( T_8 ) \
debugfs_create_file(#name, 0600, dir, sdata, &name##_ops);
F_60 ( V_111 ) ;
F_60 ( V_112 ) ;
F_60 ( V_113 ) ;
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
#undef F_60
}
static void F_61 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_15 . V_104 )
return;
F_49 ( V_65 ) ;
F_49 ( V_137 ) ;
F_49 ( V_138 ) ;
F_49 ( V_139 ) ;
F_49 ( V_140 ) ;
if ( V_2 -> V_15 . type != V_141 )
F_48 ( V_2 ) ;
switch ( V_2 -> V_15 . type ) {
case V_142 :
#ifdef F_62
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
F_59 ( V_2 ) ;
#endif
break;
case V_36 :
F_50 ( V_2 ) ;
break;
case V_143 :
F_53 ( V_2 ) ;
break;
case V_21 :
F_52 ( V_2 ) ;
break;
case V_144 :
F_54 ( V_2 ) ;
break;
default:
break;
}
}
void F_63 ( struct V_1 * V_2 )
{
char V_6 [ 10 + V_145 ] ;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
V_2 -> V_15 . V_104 = F_57 ( V_6 ,
V_2 -> V_26 -> V_28 . V_29 -> V_146 ) ;
if ( V_2 -> V_15 . V_104 )
V_2 -> V_147 . V_148 = F_57 ( L_13 ,
V_2 -> V_15 . V_104 ) ;
F_61 ( V_2 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_15 . V_104 )
return;
F_65 ( V_2 -> V_15 . V_104 ) ;
V_2 -> V_15 . V_104 = NULL ;
V_2 -> V_147 . V_148 = NULL ;
}
void F_66 ( struct V_1 * V_2 )
{
struct V_102 * V_103 ;
char V_6 [ 10 + V_145 ] ;
V_103 = V_2 -> V_15 . V_104 ;
if ( ! V_103 )
return;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
if ( ! F_67 ( V_103 -> V_149 , V_103 , V_103 -> V_149 , V_6 ) )
F_68 ( V_2 ,
L_14 ,
V_6 ) ;
}
