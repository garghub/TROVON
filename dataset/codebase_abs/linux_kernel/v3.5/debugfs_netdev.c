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
static int F_11 ( struct V_1 * V_2 ,
enum V_16 V_17 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
int V_20 ;
if ( ! ( V_19 -> V_21 . V_22 & V_23 ) &&
V_17 == V_24 )
return - V_8 ;
if ( ! ( V_19 -> V_21 . V_22 & V_25 ) &&
( V_17 == V_26 ||
V_17 == V_27 ) )
return - V_8 ;
if ( V_2 -> V_28 . type != V_29 )
return - V_30 ;
F_12 ( & V_2 -> V_31 . V_32 . V_33 ) ;
V_20 = F_13 ( V_2 , V_17 ) ;
F_14 ( & V_2 -> V_31 . V_32 . V_33 ) ;
return V_20 ;
}
static T_1 F_15 ( const struct V_1 * V_2 ,
char * V_6 , int V_34 )
{
if ( V_2 -> V_28 . type != V_29 )
return - V_30 ;
return snprintf ( V_6 , V_34 , L_1 ,
V_35 [ V_2 -> V_31 . V_32 . V_36 ] ,
V_35 [ V_2 -> V_31 . V_32 . V_37 ] ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
const char * V_6 , int V_34 )
{
enum V_16 V_38 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
if ( strncmp ( V_6 , V_35 [ V_38 ] , V_34 ) == 0 ) {
int V_20 = F_11 ( V_2 , V_38 ) ;
if ( ! V_20 )
return V_34 ;
return V_20 ;
}
}
return - V_8 ;
}
static T_1 F_17 (
const struct V_1 * V_2 , char * V_6 , int V_34 )
{
return - V_30 ;
}
static int F_18 ( const char * V_40 , T_5 * V_41 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
int V_44 , V_45 ;
V_44 = F_19 ( * V_40 ++ ) ;
if ( V_44 < 0 )
return - 1 ;
V_45 = F_19 ( * V_40 ++ ) ;
if ( V_45 < 0 )
return - 1 ;
* V_41 ++ = ( V_44 << 4 ) | V_45 ;
if ( V_42 < 5 && * V_40 ++ != ':' )
return - 1 ;
}
return 0 ;
}
static T_1 F_20 (
struct V_1 * V_2 , const char * V_6 , int V_34 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_5 V_41 [ V_43 ] ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
T_6 V_50 ;
if ( V_34 < 3 * V_43 - 1 )
return - V_8 ;
if ( F_18 ( V_6 , V_41 ) < 0 )
return - V_8 ;
if ( ! F_21 ( V_2 ) )
return - V_51 ;
V_47 = F_22 ( V_19 -> V_21 . V_52 + 24 + 100 ) ;
if ( ! V_47 )
return - V_53 ;
F_23 ( V_47 , V_19 -> V_21 . V_52 ) ;
V_49 = (struct V_48 * ) F_24 ( V_47 , 24 ) ;
memset ( V_49 , 0 , 24 ) ;
V_50 = F_25 ( V_54 | V_55 ) ;
switch ( V_2 -> V_28 . type ) {
case V_56 :
V_50 |= F_25 ( V_57 ) ;
memcpy ( V_49 -> V_58 , V_41 , V_43 ) ;
memcpy ( V_49 -> V_59 , V_2 -> V_28 . V_41 , V_43 ) ;
memcpy ( V_49 -> V_60 , V_2 -> V_28 . V_41 , V_43 ) ;
break;
case V_29 :
V_50 |= F_25 ( V_61 ) ;
if ( V_2 -> V_28 . V_62 . V_63 == NULL ) {
F_26 ( V_47 ) ;
return - V_51 ;
}
memcpy ( V_49 -> V_58 , V_2 -> V_28 . V_62 . V_63 , V_43 ) ;
memcpy ( V_49 -> V_59 , V_2 -> V_28 . V_41 , V_43 ) ;
memcpy ( V_49 -> V_60 , V_41 , V_43 ) ;
break;
default:
F_26 ( V_47 ) ;
return - V_30 ;
}
V_49 -> V_64 = V_50 ;
memset ( F_24 ( V_47 , 50 ) , 0 , 50 ) ;
F_27 ( V_47 ) -> V_22 |= V_65 ;
F_28 ( V_2 , V_47 ) ;
return V_34 ;
}
static T_1 F_29 (
const struct V_1 * V_2 , char * V_6 , int V_34 )
{
const struct V_66 * V_67 = & V_2 -> V_31 . V_32 ;
return snprintf ( V_6 , V_34 , L_2 , V_67 -> V_68 ) ;
}
static T_1 F_30 (
struct V_1 * V_2 , const char * V_6 , int V_34 )
{
struct V_66 * V_67 = & V_2 -> V_31 . V_32 ;
T_5 V_69 ;
int V_7 ;
V_7 = F_31 ( V_6 , 0 , & V_69 ) ;
if ( V_7 )
return V_7 ;
if ( V_69 & ~ V_70 )
return - V_71 ;
V_67 -> V_68 = V_69 ;
return V_34 ;
}
static T_1 F_32 (
const struct V_1 * V_2 , char * V_6 , int V_34 )
{
const struct V_66 * V_67 = & V_2 -> V_31 . V_32 ;
return snprintf ( V_6 , V_34 , L_2 , V_67 -> V_72 ) ;
}
static T_1 F_33 (
struct V_1 * V_2 , const char * V_6 , int V_34 )
{
struct V_66 * V_67 = & V_2 -> V_31 . V_32 ;
unsigned long V_69 ;
int V_7 ;
V_7 = F_34 ( V_6 , 0 , & V_69 ) ;
if ( V_7 )
return - V_8 ;
if ( V_69 & ~ V_73 )
return - V_71 ;
V_67 -> V_72 = V_69 ;
return V_34 ;
}
static T_1 F_35 (
const struct V_1 * V_2 , char * V_6 , int V_34 )
{
return F_36 ( V_6 , V_34 , L_3 ,
F_37 ( & V_2 -> V_31 . V_74 . V_75 ) ) ;
}
static T_1 F_38 (
const struct V_1 * V_2 , char * V_6 , int V_34 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_7 V_76 ;
V_76 = F_39 ( V_19 , (struct V_1 * ) V_2 ) ;
return F_36 ( V_6 , V_34 , L_4 , ( unsigned long long ) V_76 ) ;
}
static T_1 F_40 (
struct V_1 * V_2 , const char * V_6 , int V_34 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
unsigned long long V_76 ;
int V_7 ;
int V_77 = 0 ;
if ( strncmp ( V_6 , L_5 , 5 ) == 0 ) {
if ( V_19 -> V_78 -> V_79 ) {
F_41 ( V_19 , V_2 ) ;
F_42 ( V_19 -> V_21 . V_80 , L_6 ) ;
}
} else {
if ( V_34 > 10 && V_6 [ 1 ] == '=' ) {
if ( V_6 [ 0 ] == '+' )
V_77 = 1 ;
else if ( V_6 [ 0 ] == '-' )
V_77 = - 1 ;
else
return - V_8 ;
V_6 += 2 ;
}
V_7 = F_43 ( V_6 , 10 , & V_76 ) ;
if ( V_7 < 0 )
return - V_8 ;
if ( V_77 )
V_76 = F_39 ( V_19 , V_2 ) + V_77 * V_76 ;
if ( V_19 -> V_78 -> V_81 ) {
F_44 ( V_19 , V_2 , V_76 ) ;
F_42 ( V_19 -> V_21 . V_80 ,
L_7 , V_76 ) ;
}
}
return V_34 ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_82 ) ;
F_46 ( V_83 ) ;
F_46 ( V_84 ) ;
F_46 ( V_85 ) ;
F_46 ( V_86 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_46 ( V_63 ) ;
F_46 ( V_87 ) ;
F_46 ( V_88 ) ;
F_46 ( V_89 ) ;
F_48 ( V_90 , 0600 ) ;
F_48 ( V_91 , 0200 ) ;
F_48 ( V_68 , 0600 ) ;
F_48 ( V_72 , 0600 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_46 ( V_92 ) ;
F_46 ( V_93 ) ;
F_46 ( V_94 ) ;
F_46 ( V_95 ) ;
F_48 ( V_91 , 0200 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_48 ( V_76 , 0600 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_46 ( V_96 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_48 ( V_76 , 0600 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = F_54 ( L_8 ,
V_2 -> V_99 . V_98 ) ;
#define F_55 ( T_8 ) \
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
F_55 ( V_100 ) ;
F_55 ( V_101 ) ;
F_55 ( V_102 ) ;
F_55 ( V_103 ) ;
F_55 ( V_104 ) ;
F_55 ( V_105 ) ;
F_55 ( V_106 ) ;
#undef F_55
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = F_54 ( L_9 ,
V_2 -> V_99 . V_98 ) ;
#define F_57 ( T_8 ) \
debugfs_create_file(#name, 0600, dir, sdata, &name##_ops);
F_57 ( V_107 ) ;
F_57 ( V_108 ) ;
F_57 ( V_109 ) ;
F_57 ( V_110 ) ;
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
#undef F_57
}
static void F_58 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_99 . V_98 )
return;
F_46 ( V_22 ) ;
F_46 ( V_127 ) ;
F_46 ( V_128 ) ;
if ( V_2 -> V_28 . type != V_129 )
F_45 ( V_2 ) ;
switch ( V_2 -> V_28 . type ) {
case V_130 :
#ifdef F_59
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_56 ( V_2 ) ;
#endif
break;
case V_29 :
F_47 ( V_2 ) ;
break;
case V_131 :
F_50 ( V_2 ) ;
break;
case V_56 :
F_49 ( V_2 ) ;
break;
case V_132 :
F_51 ( V_2 ) ;
break;
default:
break;
}
}
void F_60 ( struct V_1 * V_2 )
{
char V_6 [ 10 + V_133 ] ;
sprintf ( V_6 , L_10 , V_2 -> T_8 ) ;
V_2 -> V_99 . V_98 = F_54 ( V_6 ,
V_2 -> V_19 -> V_21 . V_80 -> V_134 ) ;
if ( V_2 -> V_99 . V_98 )
V_2 -> V_99 . V_135 = F_54 ( L_11 ,
V_2 -> V_99 . V_98 ) ;
F_58 ( V_2 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_99 . V_98 )
return;
F_62 ( V_2 -> V_99 . V_98 ) ;
V_2 -> V_99 . V_98 = NULL ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
char V_6 [ 10 + V_133 ] ;
V_98 = V_2 -> V_99 . V_98 ;
if ( ! V_98 )
return;
sprintf ( V_6 , L_10 , V_2 -> T_8 ) ;
if ( ! F_64 ( V_98 -> V_136 , V_98 , V_98 -> V_136 , V_6 ) )
F_65 ( V_137 L_12
L_13 , V_6 ) ;
}
