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
F_14 ( V_2 ) ;
V_30 = F_15 ( V_2 , V_27 ) ;
F_16 ( V_2 ) ;
return V_30 ;
}
static T_1 F_17 ( const struct V_1 * V_2 ,
char * V_6 , int V_16 )
{
if ( V_2 -> V_18 . type != V_38 )
return - V_39 ;
return snprintf ( V_6 , V_16 , L_3 ,
V_40 [ V_2 -> V_41 . V_42 . V_43 ] ,
V_40 [ V_2 -> V_27 ] ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
const char * V_6 , int V_16 )
{
enum V_26 V_44 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
if ( strncmp ( V_6 , V_40 [ V_44 ] , V_16 ) == 0 ) {
int V_30 = F_13 ( V_2 , V_44 ) ;
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
T_5 V_46 [ V_47 ] ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
T_6 V_52 ;
if ( ! F_21 ( V_6 , V_46 ) )
return - V_8 ;
if ( ! F_22 ( V_2 ) )
return - V_53 ;
V_49 = F_23 ( V_29 -> V_31 . V_54 + 24 + 100 ) ;
if ( ! V_49 )
return - V_55 ;
F_24 ( V_49 , V_29 -> V_31 . V_54 ) ;
V_51 = (struct V_50 * ) F_25 ( V_49 , 24 ) ;
memset ( V_51 , 0 , 24 ) ;
V_52 = F_26 ( V_56 | V_57 ) ;
switch ( V_2 -> V_18 . type ) {
case V_24 :
V_52 |= F_26 ( V_58 ) ;
memcpy ( V_51 -> V_59 , V_46 , V_47 ) ;
memcpy ( V_51 -> V_60 , V_2 -> V_18 . V_46 , V_47 ) ;
memcpy ( V_51 -> V_61 , V_2 -> V_18 . V_46 , V_47 ) ;
break;
case V_38 :
V_52 |= F_26 ( V_62 ) ;
F_14 ( V_2 ) ;
if ( ! V_2 -> V_41 . V_42 . V_63 ) {
F_16 ( V_2 ) ;
F_27 ( V_49 ) ;
return - V_53 ;
}
memcpy ( V_51 -> V_59 , V_2 -> V_41 . V_42 . V_63 -> V_64 , V_47 ) ;
memcpy ( V_51 -> V_60 , V_2 -> V_18 . V_46 , V_47 ) ;
memcpy ( V_51 -> V_61 , V_46 , V_47 ) ;
F_16 ( V_2 ) ;
break;
default:
F_27 ( V_49 ) ;
return - V_39 ;
}
V_51 -> V_65 = V_52 ;
memset ( F_25 ( V_49 , 50 ) , 0 , 50 ) ;
F_28 ( V_49 ) -> V_32 |= V_66 ;
F_29 ( V_2 , V_49 ) ;
return V_16 ;
}
static T_1 F_30 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
const struct V_67 * V_68 = & V_2 -> V_41 . V_42 ;
return snprintf ( V_6 , V_16 , L_4 , V_68 -> V_69 ) ;
}
static T_1 F_31 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_67 * V_68 = & V_2 -> V_41 . V_42 ;
T_5 V_70 ;
int V_7 ;
V_7 = F_32 ( V_6 , 0 , & V_70 ) ;
if ( V_7 )
return V_7 ;
if ( V_70 & ~ V_71 )
return - V_72 ;
V_68 -> V_69 = V_70 ;
return V_16 ;
}
static T_1 F_33 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
const struct V_67 * V_68 = & V_2 -> V_41 . V_42 ;
return snprintf ( V_6 , V_16 , L_4 , V_68 -> V_73 ) ;
}
static T_1 F_34 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_67 * V_68 = & V_2 -> V_41 . V_42 ;
unsigned long V_70 ;
int V_7 ;
V_7 = F_35 ( V_6 , 0 , & V_70 ) ;
if ( V_7 )
return - V_8 ;
if ( V_70 & ~ V_74 )
return - V_72 ;
V_68 -> V_73 = V_70 ;
return V_16 ;
}
static T_1 F_36 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
return F_12 ( V_6 , V_16 , L_5 ,
F_37 ( & V_2 -> V_41 . V_75 . V_76 . V_77 ) ) ;
}
static T_1 F_38 (
const struct V_1 * V_2 , char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
T_7 V_78 ;
V_78 = F_39 ( V_29 , (struct V_1 * ) V_2 ) ;
return F_12 ( V_6 , V_16 , L_6 , ( unsigned long long ) V_78 ) ;
}
static T_1 F_40 (
struct V_1 * V_2 , const char * V_6 , int V_16 )
{
struct V_28 * V_29 = V_2 -> V_29 ;
unsigned long long V_78 ;
int V_7 ;
int V_79 = 0 ;
if ( strncmp ( V_6 , L_7 , 5 ) == 0 ) {
if ( V_29 -> V_80 -> V_81 ) {
F_41 ( V_29 , V_2 ) ;
F_42 ( V_29 -> V_31 . V_82 , L_8 ) ;
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
V_7 = F_43 ( V_6 , 10 , & V_78 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_79 )
V_78 = F_39 ( V_29 , V_2 ) + V_79 * V_78 ;
if ( V_29 -> V_80 -> V_83 ) {
F_44 ( V_29 , V_2 , V_78 ) ;
F_42 ( V_29 -> V_31 . V_82 ,
L_9 , V_78 ) ;
}
}
return V_16 ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_84 ) ;
F_46 ( V_85 ) ;
F_46 ( V_86 ) ;
F_46 ( V_87 ) ;
F_46 ( V_88 ) ;
F_46 ( V_89 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_46 ( V_64 ) ;
F_46 ( V_90 ) ;
F_46 ( V_91 ) ;
F_46 ( V_92 ) ;
F_46 ( V_93 ) ;
F_48 ( V_94 , 0600 ) ;
F_48 ( V_95 , 0200 ) ;
F_48 ( V_69 , 0600 ) ;
F_48 ( V_73 , 0600 ) ;
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
F_48 ( V_78 , 0600 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_46 ( V_100 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_48 ( V_78 , 0600 ) ;
F_48 ( V_101 , 0400 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_102 * V_103 = F_54 ( L_10 ,
V_2 -> V_18 . V_104 ) ;
#define F_55 ( T_8 ) \
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
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
struct V_102 * V_103 = F_54 ( L_11 ,
V_2 -> V_18 . V_104 ) ;
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
F_57 ( V_135 ) ;
F_57 ( V_136 ) ;
#undef F_57
}
static void F_58 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 . V_104 )
return;
F_46 ( V_32 ) ;
F_46 ( V_137 ) ;
F_46 ( V_138 ) ;
F_46 ( V_139 ) ;
F_46 ( V_140 ) ;
if ( V_2 -> V_18 . type != V_141 )
F_45 ( V_2 ) ;
switch ( V_2 -> V_18 . type ) {
case V_142 :
#ifdef F_59
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_56 ( V_2 ) ;
#endif
break;
case V_38 :
F_47 ( V_2 ) ;
break;
case V_143 :
F_50 ( V_2 ) ;
break;
case V_24 :
F_49 ( V_2 ) ;
break;
case V_144 :
F_51 ( V_2 ) ;
break;
default:
break;
}
}
void F_60 ( struct V_1 * V_2 )
{
char V_6 [ 10 + V_145 ] ;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
V_2 -> V_18 . V_104 = F_54 ( V_6 ,
V_2 -> V_29 -> V_31 . V_82 -> V_146 ) ;
if ( V_2 -> V_18 . V_104 )
V_2 -> V_147 . V_148 = F_54 ( L_13 ,
V_2 -> V_18 . V_104 ) ;
F_58 ( V_2 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 . V_104 )
return;
F_62 ( V_2 -> V_18 . V_104 ) ;
V_2 -> V_18 . V_104 = NULL ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_102 * V_103 ;
char V_6 [ 10 + V_145 ] ;
V_103 = V_2 -> V_18 . V_104 ;
if ( ! V_103 )
return;
sprintf ( V_6 , L_12 , V_2 -> T_8 ) ;
if ( ! F_64 ( V_103 -> V_149 , V_103 , V_103 -> V_149 , V_6 ) )
F_65 ( V_2 ,
L_14 ,
V_6 ) ;
}
