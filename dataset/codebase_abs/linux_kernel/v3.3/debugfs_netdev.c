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
T_5 * V_6 ;
T_1 V_7 ;
V_6 = F_8 ( V_4 , V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_7 = - V_15 ;
if ( F_9 ( V_6 , V_3 , V_4 ) )
goto V_16;
V_7 = - V_17 ;
F_10 () ;
if ( V_2 -> V_10 -> V_11 == V_12 )
V_7 = (* F_7)( V_2 , V_6 , V_4 ) ;
F_11 () ;
V_16:
F_12 ( V_6 ) ;
return V_7 ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_18 V_19 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
int V_22 ;
if ( ! ( V_21 -> V_23 . V_24 & V_25 ) &&
V_19 == V_26 )
return - V_8 ;
if ( ! ( V_21 -> V_23 . V_24 & V_27 ) &&
( V_19 == V_28 ||
V_19 == V_29 ) )
return - V_8 ;
if ( V_2 -> V_30 . type != V_31 )
return - V_32 ;
F_14 ( & V_2 -> V_33 . V_34 . V_35 ) ;
V_22 = F_15 ( V_2 , V_19 ) ;
F_16 ( & V_2 -> V_33 . V_34 . V_35 ) ;
return V_22 ;
}
static T_1 F_17 ( const struct V_1 * V_2 ,
char * V_6 , int V_36 )
{
if ( V_2 -> V_30 . type != V_31 )
return - V_32 ;
return snprintf ( V_6 , V_36 , L_1 ,
V_37 [ V_2 -> V_33 . V_34 . V_38 ] ,
V_37 [ V_2 -> V_33 . V_34 . V_39 ] ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
const char * V_6 , int V_36 )
{
enum V_18 V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
if ( strncmp ( V_6 , V_37 [ V_40 ] , V_36 ) == 0 ) {
int V_22 = F_13 ( V_2 , V_40 ) ;
if ( ! V_22 )
return V_36 ;
return V_22 ;
}
}
return - V_8 ;
}
static T_1 F_19 (
const struct V_1 * V_2 , char * V_6 , int V_36 )
{
return - V_32 ;
}
static int F_20 ( const char * V_42 , T_5 * V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
int V_46 , V_47 ;
V_46 = F_21 ( * V_42 ++ ) ;
if ( V_46 < 0 )
return - 1 ;
V_47 = F_21 ( * V_42 ++ ) ;
if ( V_47 < 0 )
return - 1 ;
* V_43 ++ = ( V_46 << 4 ) | V_47 ;
if ( V_44 < 5 && * V_42 ++ != ':' )
return - 1 ;
}
return 0 ;
}
static T_1 F_22 (
struct V_1 * V_2 , const char * V_6 , int V_36 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
T_5 V_43 [ V_45 ] ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
T_6 V_52 ;
if ( V_36 < 3 * V_45 - 1 )
return - V_8 ;
if ( F_20 ( V_6 , V_43 ) < 0 )
return - V_8 ;
if ( ! F_23 ( V_2 ) )
return - V_53 ;
V_49 = F_24 ( V_21 -> V_23 . V_54 + 24 + 100 ) ;
if ( ! V_49 )
return - V_14 ;
F_25 ( V_49 , V_21 -> V_23 . V_54 ) ;
V_51 = (struct V_50 * ) F_26 ( V_49 , 24 ) ;
memset ( V_51 , 0 , 24 ) ;
V_52 = F_27 ( V_55 | V_56 ) ;
switch ( V_2 -> V_30 . type ) {
case V_57 :
V_52 |= F_27 ( V_58 ) ;
memcpy ( V_51 -> V_59 , V_43 , V_45 ) ;
memcpy ( V_51 -> V_60 , V_2 -> V_30 . V_43 , V_45 ) ;
memcpy ( V_51 -> V_61 , V_2 -> V_30 . V_43 , V_45 ) ;
break;
case V_31 :
V_52 |= F_27 ( V_62 ) ;
if ( V_2 -> V_30 . V_63 . V_64 == NULL ) {
F_28 ( V_49 ) ;
return - V_53 ;
}
memcpy ( V_51 -> V_59 , V_2 -> V_30 . V_63 . V_64 , V_45 ) ;
memcpy ( V_51 -> V_60 , V_2 -> V_30 . V_43 , V_45 ) ;
memcpy ( V_51 -> V_61 , V_43 , V_45 ) ;
break;
default:
F_28 ( V_49 ) ;
return - V_32 ;
}
V_51 -> V_65 = V_52 ;
memset ( F_26 ( V_49 , 50 ) , 0 , 50 ) ;
F_29 ( V_49 ) -> V_24 |= V_66 ;
F_30 ( V_2 , V_49 ) ;
return V_36 ;
}
static T_1 F_31 (
const struct V_1 * V_2 , char * V_6 , int V_36 )
{
return F_32 ( V_6 , V_36 , L_2 ,
F_33 ( & V_2 -> V_33 . V_67 . V_68 ) ) ;
}
static T_1 F_34 (
const struct V_1 * V_2 , char * V_6 , int V_36 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
T_7 V_69 ;
V_69 = F_35 ( V_21 , (struct V_1 * ) V_2 ) ;
return F_32 ( V_6 , V_36 , L_3 , ( unsigned long long ) V_69 ) ;
}
static T_1 F_36 (
struct V_1 * V_2 , const char * V_6 , int V_36 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
unsigned long long V_69 ;
int V_7 ;
if ( strncmp ( V_6 , L_4 , 5 ) == 0 ) {
if ( V_21 -> V_70 -> V_71 ) {
F_37 ( V_21 , V_2 ) ;
F_38 ( V_21 -> V_23 . V_72 , L_5 ) ;
}
} else {
V_7 = F_39 ( V_6 , 10 , & V_69 ) ;
if ( V_7 < 0 )
return - V_8 ;
if ( V_21 -> V_70 -> V_73 ) {
F_40 ( V_21 , V_2 , V_69 ) ;
F_38 ( V_21 -> V_23 . V_72 ,
L_6 , V_69 ) ;
}
}
return V_36 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_42 ( V_74 ) ;
F_42 ( V_24 ) ;
F_42 ( V_75 ) ;
F_42 ( V_76 ) ;
F_42 ( V_77 ) ;
F_42 ( V_78 ) ;
F_42 ( V_64 ) ;
F_42 ( V_79 ) ;
F_42 ( V_80 ) ;
F_42 ( V_81 ) ;
F_43 ( V_82 , 0600 ) ;
F_43 ( V_83 , 0200 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_42 ( V_74 ) ;
F_42 ( V_24 ) ;
F_42 ( V_75 ) ;
F_42 ( V_76 ) ;
F_42 ( V_77 ) ;
F_42 ( V_78 ) ;
F_42 ( V_84 ) ;
F_42 ( V_85 ) ;
F_42 ( V_86 ) ;
F_42 ( V_87 ) ;
F_43 ( V_83 , 0200 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_43 ( V_69 , 0600 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_42 ( V_74 ) ;
F_42 ( V_24 ) ;
F_42 ( V_75 ) ;
F_42 ( V_76 ) ;
F_42 ( V_77 ) ;
F_42 ( V_78 ) ;
F_42 ( V_88 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_42 ( V_74 ) ;
F_42 ( V_24 ) ;
F_42 ( V_75 ) ;
F_42 ( V_76 ) ;
F_42 ( V_77 ) ;
F_42 ( V_78 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_42 ( V_24 ) ;
F_42 ( V_75 ) ;
F_42 ( V_76 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_89 * V_90 = F_50 ( L_7 ,
V_2 -> V_91 . V_90 ) ;
#define F_51 ( T_8 ) \
debugfs_create_file(#name, 0400, dir, sdata, &name##_ops);
F_51 ( V_92 ) ;
F_51 ( V_93 ) ;
F_51 ( V_94 ) ;
F_51 ( V_95 ) ;
F_51 ( V_96 ) ;
F_51 ( V_97 ) ;
F_51 ( V_98 ) ;
#undef F_51
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_89 * V_90 = F_50 ( L_8 ,
V_2 -> V_91 . V_90 ) ;
#define F_53 ( T_8 ) \
debugfs_create_file(#name, 0600, dir, sdata, &name##_ops);
F_53 ( V_99 ) ;
F_53 ( V_100 ) ;
F_53 ( V_101 ) ;
F_53 ( V_102 ) ;
F_53 ( V_103 ) ;
F_53 ( V_104 ) ;
F_53 ( V_105 ) ;
F_53 ( V_106 ) ;
F_53 ( V_107 ) ;
F_53 ( V_108 ) ;
F_53 ( V_109 ) ;
F_53 ( V_110 ) ;
F_53 ( V_111 ) ;
F_53 ( V_112 ) ;
F_53 ( V_113 ) ;
F_53 ( V_114 ) ;
F_53 ( V_115 ) ;
F_53 ( V_116 ) ;
#undef F_53
}
static void F_54 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_91 . V_90 )
return;
switch ( V_2 -> V_30 . type ) {
case V_117 :
#ifdef F_55
F_49 ( V_2 ) ;
F_52 ( V_2 ) ;
#endif
break;
case V_31 :
F_41 ( V_2 ) ;
break;
case V_118 :
F_45 ( V_2 ) ;
break;
case V_57 :
F_44 ( V_2 ) ;
break;
case V_119 :
F_46 ( V_2 ) ;
break;
case V_120 :
F_48 ( V_2 ) ;
break;
case V_121 :
F_47 ( V_2 ) ;
break;
default:
break;
}
}
void F_56 ( struct V_1 * V_2 )
{
char V_6 [ 10 + V_122 ] ;
sprintf ( V_6 , L_9 , V_2 -> T_8 ) ;
V_2 -> V_91 . V_90 = F_50 ( V_6 ,
V_2 -> V_21 -> V_23 . V_72 -> V_123 ) ;
if ( V_2 -> V_91 . V_90 )
V_2 -> V_91 . V_124 = F_50 ( L_10 ,
V_2 -> V_91 . V_90 ) ;
F_54 ( V_2 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_91 . V_90 )
return;
F_58 ( V_2 -> V_91 . V_90 ) ;
V_2 -> V_91 . V_90 = NULL ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
char V_6 [ 10 + V_122 ] ;
V_90 = V_2 -> V_91 . V_90 ;
if ( ! V_90 )
return;
sprintf ( V_6 , L_9 , V_2 -> T_8 ) ;
if ( ! F_60 ( V_90 -> V_125 , V_90 , V_90 -> V_125 , V_6 ) )
F_61 ( V_126 L_11
L_12 , V_6 ) ;
}
