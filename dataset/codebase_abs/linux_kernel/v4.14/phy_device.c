void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 . V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_6 , struct V_1 , V_3 ) ;
F_1 ( V_2 ) ;
}
static void F_5 ( struct V_7 * V_4 )
{
F_6 ( F_7 ( V_4 ) ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_6 , struct V_1 , V_3 ) ;
F_9 ( V_2 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_3 . V_4 . V_10 ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
struct V_13 * V_14 = V_2 -> V_15 ;
if ( ! V_9 || ! V_12 -> V_16 )
return false ;
if ( ! V_14 )
return ! V_2 -> V_17 ;
if ( V_14 -> V_4 . V_18 && F_12 ( V_14 -> V_4 . V_18 ) )
return false ;
if ( F_12 ( & V_14 -> V_4 ) )
return false ;
return true ;
}
static int F_13 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
if ( V_2 -> V_15 && V_2 -> V_19 )
F_14 ( V_2 ) ;
if ( ! F_10 ( V_2 ) )
return 0 ;
return F_15 ( V_2 ) ;
}
static int F_16 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
int V_20 ;
if ( ! F_10 ( V_2 ) )
goto V_21;
V_20 = F_17 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_21:
if ( V_2 -> V_15 && V_2 -> V_19 )
F_18 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_13 * V_14 = V_2 -> V_15 ;
int V_20 ;
if ( ! V_14 )
return 0 ;
V_20 = F_20 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = V_24 ;
F_18 ( V_2 ) ;
return 0 ;
}
int F_21 ( const char * V_25 , T_1 V_26 , T_1 V_27 ,
int (* F_22)( struct V_1 * ) )
{
struct V_28 * V_29 = F_23 ( sizeof( * V_29 ) , V_30 ) ;
if ( ! V_29 )
return - V_31 ;
F_24 ( V_29 -> V_25 , V_25 , sizeof( V_29 -> V_25 ) ) ;
V_29 -> V_26 = V_26 ;
V_29 -> V_27 = V_27 ;
V_29 -> F_22 = F_22 ;
F_25 ( & V_32 ) ;
F_26 ( & V_29 -> V_33 , & V_34 ) ;
F_27 ( & V_32 ) ;
return 0 ;
}
int F_28 ( T_1 V_26 , T_1 V_27 ,
int (* F_22)( struct V_1 * ) )
{
return F_21 ( V_35 , V_26 , V_27 , F_22 ) ;
}
int F_29 ( const char * V_25 ,
int (* F_22)( struct V_1 * ) )
{
return F_21 ( V_25 , V_36 , 0xffffffff , F_22 ) ;
}
int F_30 ( const char * V_25 , T_1 V_26 , T_1 V_27 )
{
struct V_37 * V_38 , * V_39 ;
struct V_28 * V_29 ;
int V_20 ;
V_20 = - V_40 ;
F_25 ( & V_32 ) ;
F_31 (pos, n, &phy_fixup_list) {
V_29 = F_32 ( V_38 , struct V_28 , V_33 ) ;
if ( ( ! strcmp ( V_29 -> V_25 , V_25 ) ) &&
( ( V_29 -> V_26 & V_27 ) ==
( V_26 & V_27 ) ) ) {
F_33 ( & V_29 -> V_33 ) ;
F_6 ( V_29 ) ;
V_20 = 0 ;
break;
}
}
F_27 ( & V_32 ) ;
return V_20 ;
}
int F_34 ( T_1 V_26 , T_1 V_27 )
{
return F_30 ( V_35 , V_26 , V_27 ) ;
}
int F_35 ( const char * V_25 )
{
return F_30 ( V_25 , V_36 , 0xffffffff ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
if ( strcmp ( V_29 -> V_25 , F_37 ( V_2 ) ) != 0 )
if ( strcmp ( V_29 -> V_25 , V_35 ) != 0 )
return 0 ;
if ( ( V_29 -> V_26 & V_29 -> V_27 ) !=
( V_2 -> V_41 & V_29 -> V_27 ) )
if ( V_29 -> V_26 != V_36 )
return 0 ;
return 1 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
F_25 ( & V_32 ) ;
F_39 (fixup, &phy_fixup_list, list) {
if ( F_36 ( V_2 , V_29 ) ) {
int V_42 = V_29 -> F_22 ( V_2 ) ;
if ( V_42 < 0 ) {
F_27 ( & V_32 ) ;
return V_42 ;
}
V_2 -> V_43 = true ;
}
}
F_27 ( & V_32 ) ;
return 0 ;
}
static int F_40 ( struct V_7 * V_4 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const int V_44 = F_41 ( V_2 -> V_45 . V_46 ) ;
int V_47 ;
if ( ! ( V_12 -> V_48 . V_49 & V_50 ) )
return 0 ;
if ( V_12 -> V_51 )
return V_12 -> V_51 ( V_2 ) ;
if ( V_2 -> V_52 ) {
for ( V_47 = 1 ; V_47 < V_44 ; V_47 ++ ) {
if ( ! ( V_2 -> V_45 . V_53 & ( 1 << V_47 ) ) )
continue;
if ( ( V_12 -> V_41 & V_12 -> V_54 ) ==
( V_2 -> V_45 . V_46 [ V_47 ] &
V_12 -> V_54 ) )
return 1 ;
}
return 0 ;
} else {
return ( V_12 -> V_41 & V_12 -> V_54 ) ==
( V_2 -> V_41 & V_12 -> V_54 ) ;
}
}
struct V_1 * F_42 ( struct V_55 * V_56 , int V_57 , int V_41 ,
bool V_52 ,
struct V_58 * V_45 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return F_43 ( - V_31 ) ;
V_6 = & V_4 -> V_3 ;
V_6 -> V_4 . V_59 = F_5 ;
V_6 -> V_4 . V_18 = & V_56 -> V_4 ;
V_6 -> V_4 . V_56 = & V_60 ;
V_6 -> V_56 = V_56 ;
V_6 -> V_61 = V_62 ;
V_6 -> V_63 = F_40 ;
V_6 -> V_57 = V_57 ;
V_6 -> V_49 = V_64 ;
V_6 -> V_65 = F_3 ;
V_6 -> V_66 = F_8 ;
V_4 -> V_67 = 0 ;
V_4 -> V_68 = - 1 ;
V_4 -> V_69 = 0 ;
V_4 -> V_70 = 0 ;
V_4 -> V_22 = 1 ;
V_4 -> V_71 = V_72 ;
V_4 -> V_73 = V_74 ;
V_4 -> V_52 = V_52 ;
V_4 -> V_41 = V_41 ;
if ( V_45 )
V_4 -> V_45 = * V_45 ;
V_4 -> V_75 = V_56 -> V_75 [ V_57 ] ;
F_44 ( & V_6 -> V_4 , V_76 , V_56 -> V_77 , V_57 ) ;
V_4 -> V_23 = V_78 ;
F_45 ( & V_4 -> V_79 ) ;
F_46 ( & V_4 -> V_80 , V_81 ) ;
F_47 ( & V_4 -> V_82 , V_83 ) ;
F_48 (MDIO_MODULE_PREFIX MDIO_ID_FMT, MDIO_ID_ARGS(phy_id)) ;
F_49 ( & V_6 -> V_4 ) ;
return V_4 ;
}
static int F_50 ( struct V_55 * V_56 , int V_57 , int V_84 ,
T_1 * V_53 )
{
int V_85 , V_86 ;
V_86 = V_87 | V_84 << 16 | V_88 ;
V_85 = F_51 ( V_56 , V_57 , V_86 ) ;
if ( V_85 < 0 )
return - V_89 ;
* V_53 = ( V_85 & 0xffff ) << 16 ;
V_86 = V_87 | V_84 << 16 | V_90 ;
V_85 = F_51 ( V_56 , V_57 , V_86 ) ;
if ( V_85 < 0 )
return - V_89 ;
* V_53 |= ( V_85 & 0xffff ) ;
return 0 ;
}
static int F_52 ( struct V_55 * V_56 , int V_57 , T_1 * V_41 ,
struct V_58 * V_45 ) {
int V_85 ;
int V_47 , V_86 ;
const int V_44 = F_41 ( V_45 -> V_46 ) ;
T_1 * V_91 = & V_45 -> V_53 ;
for ( V_47 = 1 ; V_47 < V_44 && * V_91 == 0 ; V_47 ++ ) {
V_85 = F_50 ( V_56 , V_57 , V_47 , V_91 ) ;
if ( V_85 < 0 )
return - V_89 ;
if ( ( * V_91 & 0x1fffffff ) == 0x1fffffff ) {
V_85 = F_50 ( V_56 , V_57 , 0 , V_91 ) ;
if ( V_85 < 0 )
return - V_89 ;
if ( ( * V_91 & 0x1fffffff ) == 0x1fffffff ) {
* V_41 = 0xffffffff ;
return 0 ;
} else {
break;
}
}
}
for ( V_47 = 1 ; V_47 < V_44 ; V_47 ++ ) {
if ( ! ( V_45 -> V_53 & ( 1 << V_47 ) ) )
continue;
V_86 = V_87 | V_47 << 16 | V_92 ;
V_85 = F_51 ( V_56 , V_57 , V_86 ) ;
if ( V_85 < 0 )
return - V_89 ;
V_45 -> V_46 [ V_47 ] = ( V_85 & 0xffff ) << 16 ;
V_86 = V_87 | V_47 << 16 | V_93 ;
V_85 = F_51 ( V_56 , V_57 , V_86 ) ;
if ( V_85 < 0 )
return - V_89 ;
V_45 -> V_46 [ V_47 ] |= ( V_85 & 0xffff ) ;
}
* V_41 = 0 ;
return 0 ;
}
static int F_53 ( struct V_55 * V_56 , int V_57 , T_1 * V_41 ,
bool V_52 , struct V_58 * V_45 )
{
int V_85 ;
if ( V_52 )
return F_52 ( V_56 , V_57 , V_41 , V_45 ) ;
V_85 = F_51 ( V_56 , V_57 , V_92 ) ;
if ( V_85 < 0 )
return - V_89 ;
* V_41 = ( V_85 & 0xffff ) << 16 ;
V_85 = F_51 ( V_56 , V_57 , V_93 ) ;
if ( V_85 < 0 )
return - V_89 ;
* V_41 |= ( V_85 & 0xffff ) ;
return 0 ;
}
struct V_1 * F_54 ( struct V_55 * V_56 , int V_57 , bool V_52 )
{
struct V_58 V_45 = { 0 } ;
T_1 V_41 = 0 ;
int V_94 ;
V_94 = F_53 ( V_56 , V_57 , & V_41 , V_52 , & V_45 ) ;
if ( V_94 )
return F_43 ( V_94 ) ;
if ( ( V_41 & 0x1fffffff ) == 0x1fffffff )
return F_43 ( - V_40 ) ;
return F_42 ( V_56 , V_57 , V_41 , V_52 , & V_45 ) ;
}
static T_2
F_55 ( struct V_7 * V_4 , struct V_95 * V_96 , char * V_97 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
return sprintf ( V_97 , L_1 , ( unsigned long ) V_2 -> V_41 ) ;
}
static T_2
F_56 ( struct V_7 * V_4 , struct V_95 * V_96 , char * V_97 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
const char * V_98 = NULL ;
if ( F_57 ( V_2 ) )
V_98 = L_2 ;
else
V_98 = F_58 ( V_2 -> V_71 ) ;
return sprintf ( V_97 , L_3 , V_98 ) ;
}
static T_2
F_59 ( struct V_7 * V_4 , struct V_95 * V_96 ,
char * V_97 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
return sprintf ( V_97 , L_4 , V_2 -> V_43 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_42 ;
V_42 = F_61 ( & V_2 -> V_3 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_38 ( V_2 ) ;
if ( V_42 ) {
F_62 ( L_5 , V_2 -> V_3 . V_57 ) ;
goto V_99;
}
V_2 -> V_3 . V_4 . V_100 = V_101 ;
V_42 = F_63 ( & V_2 -> V_3 . V_4 ) ;
if ( V_42 ) {
F_62 ( L_6 , V_2 -> V_3 . V_57 ) ;
goto V_99;
}
return 0 ;
V_99:
F_64 ( & V_2 -> V_3 ) ;
return V_42 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_65 ( & V_2 -> V_3 . V_4 ) ;
F_64 ( & V_2 -> V_3 ) ;
}
struct V_1 * F_66 ( struct V_55 * V_56 )
{
struct V_1 * V_2 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_102 ; V_57 ++ ) {
V_2 = F_67 ( V_56 , V_57 ) ;
if ( V_2 )
return V_2 ;
}
return NULL ;
}
static void F_68 ( struct V_1 * V_2 , bool V_103 , bool V_104 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
if ( V_104 ) {
if ( V_103 )
F_69 ( V_14 ) ;
else
F_70 ( V_14 ) ;
}
V_2 -> V_19 ( V_14 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
void (* F_72)( struct V_13 * ) )
{
V_2 -> V_19 = F_72 ;
}
int F_73 ( struct V_13 * V_4 , struct V_1 * V_2 ,
void (* F_72)( struct V_13 * ) ,
T_3 V_71 )
{
int V_105 ;
V_105 = F_74 ( V_4 , V_2 , V_2 -> V_106 , V_71 ) ;
if ( V_105 )
return V_105 ;
F_71 ( V_2 , F_72 ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_75 > 0 )
F_75 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_76 ( struct V_13 * V_4 , const char * V_25 ,
void (* F_72)( struct V_13 * ) ,
T_3 V_71 )
{
struct V_1 * V_2 ;
struct V_7 * V_107 ;
int V_105 ;
V_107 = F_77 ( & V_60 , NULL , V_25 ) ;
if ( ! V_107 ) {
F_62 ( L_7 , V_25 ) ;
return F_43 ( - V_40 ) ;
}
V_2 = F_7 ( V_107 ) ;
V_105 = F_73 ( V_4 , V_2 , F_72 , V_71 ) ;
F_2 ( V_107 ) ;
if ( V_105 )
return F_43 ( V_105 ) ;
return V_2 ;
}
void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 > 0 )
F_79 ( V_2 ) ;
F_14 ( V_2 ) ;
V_2 -> V_19 = NULL ;
F_80 ( V_2 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
unsigned int V_108 = 12 ;
int V_20 ;
do {
F_82 ( 50 ) ;
V_20 = F_83 ( V_2 , V_109 ) ;
if ( V_20 < 0 )
return V_20 ;
} while ( V_20 & V_110 && -- V_108 );
if ( V_20 & V_110 )
return - V_111 ;
F_82 ( 1 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
if ( ! V_2 -> V_9 || ! V_2 -> V_9 -> V_112 )
return 0 ;
if ( V_2 -> V_9 -> V_113 )
V_20 = V_2 -> V_9 -> V_113 ( V_2 ) ;
else
V_20 = F_84 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_38 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
return V_2 -> V_9 -> V_112 ( V_2 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
F_86 ( V_2 , NULL ) ;
}
void F_86 ( struct V_1 * V_2 , const char * V_114 , ... )
{
const char * V_115 = V_2 -> V_9 ? V_2 -> V_9 -> V_116 : L_8 ;
char * V_117 ;
char V_118 [ 8 ] ;
switch( V_2 -> V_75 ) {
case V_119 :
V_117 = L_9 ;
break;
case V_120 :
V_117 = L_10 ;
break;
default:
snprintf ( V_118 , sizeof( V_118 ) , L_11 , V_2 -> V_75 ) ;
V_117 = V_118 ;
break;
}
if ( ! V_114 ) {
F_87 ( & V_2 -> V_3 . V_4 , V_121 L_12 ,
V_115 , F_37 ( V_2 ) ,
V_117 ) ;
} else {
T_4 V_122 ;
F_87 ( & V_2 -> V_3 . V_4 , V_121 ,
V_115 , F_37 ( V_2 ) ,
V_117 ) ;
va_start ( V_122 , V_114 ) ;
F_88 ( V_114 , V_122 ) ;
va_end ( V_122 ) ;
}
}
int F_74 ( struct V_13 * V_4 , struct V_1 * V_2 ,
T_1 V_49 , T_3 V_71 )
{
struct V_123 * V_124 = V_4 -> V_4 . V_18 -> V_10 -> V_125 ;
struct V_55 * V_56 = V_2 -> V_3 . V_56 ;
struct V_7 * V_107 = & V_2 -> V_3 . V_4 ;
bool V_126 = false ;
int V_42 ;
if ( V_124 != V_56 -> V_125 && ! F_89 ( V_56 -> V_125 ) ) {
F_90 ( & V_4 -> V_4 , L_13 ) ;
return - V_89 ;
}
F_91 ( V_107 ) ;
if ( ! V_107 -> V_10 ) {
if ( V_2 -> V_52 )
V_107 -> V_10 = & V_127 . V_48 . V_10 ;
else
V_107 -> V_10 = & V_128 . V_48 . V_10 ;
V_126 = true ;
}
if ( ! F_89 ( V_107 -> V_10 -> V_125 ) ) {
F_90 ( & V_4 -> V_4 , L_14 ) ;
V_42 = - V_89 ;
goto V_129;
}
if ( V_126 ) {
V_42 = V_107 -> V_10 -> V_130 ( V_107 ) ;
if ( V_42 >= 0 )
V_42 = F_92 ( V_107 ) ;
if ( V_42 )
goto V_131;
}
if ( V_2 -> V_15 ) {
F_90 ( & V_4 -> V_4 , L_15 ) ;
V_42 = - V_132 ;
goto error;
}
V_2 -> F_68 = F_68 ;
V_2 -> V_15 = V_4 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_133 = false ;
V_42 = F_93 ( & V_2 -> V_3 . V_4 . V_134 , & V_4 -> V_4 . V_134 ,
L_16 ) ;
if ( ! V_42 ) {
V_42 = F_93 ( & V_4 -> V_4 . V_134 , & V_2 -> V_3 . V_4 . V_134 ,
L_17 ) ;
if ( V_42 )
goto error;
V_2 -> V_133 = true ;
}
V_2 -> V_106 = V_49 ;
V_2 -> V_71 = V_71 ;
V_2 -> V_23 = V_135 ;
F_70 ( V_2 -> V_15 ) ;
V_42 = F_20 ( V_2 ) ;
if ( V_42 )
goto error;
F_17 ( V_2 ) ;
F_94 ( V_2 ) ;
return V_42 ;
error:
F_80 ( V_2 ) ;
return V_42 ;
V_131:
F_95 ( V_107 -> V_10 -> V_125 ) ;
V_129:
F_2 ( V_107 ) ;
if ( V_124 != V_56 -> V_125 )
F_95 ( V_56 -> V_125 ) ;
return V_42 ;
}
struct V_1 * F_96 ( struct V_13 * V_4 , const char * V_25 ,
T_3 V_71 )
{
struct V_136 * V_56 = & V_60 ;
struct V_1 * V_2 ;
struct V_7 * V_107 ;
int V_105 ;
V_107 = F_77 ( V_56 , NULL , V_25 ) ;
if ( ! V_107 ) {
F_62 ( L_7 , V_25 ) ;
return F_43 ( - V_40 ) ;
}
V_2 = F_7 ( V_107 ) ;
V_105 = F_74 ( V_4 , V_2 , V_2 -> V_106 , V_71 ) ;
F_2 ( V_107 ) ;
if ( V_105 )
return F_43 ( V_105 ) ;
return V_2 ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_13 * V_4 = V_2 -> V_15 ;
struct V_123 * V_124 = V_4 -> V_4 . V_18 -> V_10 -> V_125 ;
struct V_55 * V_56 ;
if ( V_2 -> V_133 ) {
F_97 ( & V_4 -> V_4 . V_134 , L_17 ) ;
F_97 ( & V_2 -> V_3 . V_4 . V_134 , L_16 ) ;
}
V_2 -> V_15 -> V_2 = NULL ;
V_2 -> V_15 = NULL ;
F_15 ( V_2 ) ;
V_2 -> V_137 = NULL ;
F_98 ( V_2 ) ;
F_95 ( V_2 -> V_3 . V_4 . V_10 -> V_125 ) ;
if ( V_2 -> V_3 . V_4 . V_10 == & V_127 . V_48 . V_10 ||
V_2 -> V_3 . V_4 . V_10 == & V_128 . V_48 . V_10 )
F_99 ( & V_2 -> V_3 . V_4 ) ;
V_56 = V_2 -> V_3 . V_56 ;
F_2 ( & V_2 -> V_3 . V_4 ) ;
if ( V_124 != V_56 -> V_125 )
F_95 ( V_56 -> V_125 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_11 ( V_2 -> V_3 . V_4 . V_10 ) ;
struct V_138 V_139 = { . V_140 = V_141 } ;
int V_20 = 0 ;
F_100 ( V_2 , & V_139 ) ;
if ( V_139 . V_142 )
return - V_132 ;
if ( V_2 -> V_9 && V_12 -> V_16 )
V_20 = V_12 -> V_16 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_17 = true ;
return V_20 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_11 ( V_2 -> V_3 . V_4 . V_10 ) ;
int V_20 = 0 ;
if ( V_2 -> V_9 && V_12 -> V_143 )
V_20 = V_12 -> V_143 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_17 = false ;
return V_20 ;
}
int F_101 ( struct V_1 * V_2 , bool V_144 )
{
struct V_11 * V_12 = F_11 ( V_2 -> V_3 . V_4 . V_10 ) ;
int V_20 = 0 ;
F_25 ( & V_2 -> V_79 ) ;
if ( V_144 && V_2 -> V_145 ) {
V_20 = - V_132 ;
goto V_99;
}
if ( ! V_144 && ! V_2 -> V_145 ) {
V_20 = - V_146 ;
goto V_99;
}
if ( V_2 -> V_9 && V_12 -> V_147 )
V_20 = V_12 -> V_147 ( V_2 , V_144 ) ;
else
V_20 = - V_148 ;
if ( V_20 )
goto V_99;
V_2 -> V_145 = V_144 ;
V_99:
F_27 ( & V_2 -> V_79 ) ;
return V_20 ;
}
static int F_102 ( struct V_1 * V_2 )
{
T_1 V_149 ;
int V_150 , V_151 , V_152 ;
int V_42 , V_153 = 0 ;
V_2 -> V_154 &= V_2 -> V_155 ;
V_149 = V_2 -> V_154 ;
V_151 = F_83 ( V_2 , V_156 ) ;
if ( V_151 < 0 )
return V_151 ;
V_150 = V_151 ;
V_151 &= ~ ( V_157 | V_158 | V_159 |
V_160 ) ;
V_151 |= F_103 ( V_149 ) ;
if ( V_151 != V_150 ) {
V_42 = F_104 ( V_2 , V_156 , V_151 ) ;
if ( V_42 < 0 )
return V_42 ;
V_153 = 1 ;
}
V_152 = F_83 ( V_2 , V_161 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( ! ( V_152 & V_162 ) )
return V_153 ;
V_151 = F_83 ( V_2 , V_163 ) ;
if ( V_151 < 0 )
return V_151 ;
V_150 = V_151 ;
V_151 &= ~ ( V_164 | V_165 ) ;
if ( V_2 -> V_155 & ( V_166 |
V_167 ) ) {
V_151 |= F_105 ( V_149 ) ;
}
if ( V_151 != V_150 )
V_153 = 1 ;
V_42 = F_104 ( V_2 , V_163 , V_151 ) ;
if ( V_42 < 0 )
return V_42 ;
return V_153 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_168 = V_2 -> V_169 ;
int V_170 , V_151 ;
if ( ! V_168 )
return 0 ;
V_151 = F_107 ( V_2 , V_171 , V_172 ) ;
if ( V_151 <= 0 )
return 0 ;
V_170 = V_151 ;
V_151 &= ~ V_168 ;
if ( V_170 == V_151 )
return 0 ;
F_108 ( V_2 , V_171 , V_172 , V_151 ) ;
return 1 ;
}
int F_109 ( struct V_1 * V_2 )
{
int V_173 = F_83 ( V_2 , V_109 ) ;
V_173 &= V_174 | V_175 | V_176 ;
V_2 -> V_69 = 0 ;
V_2 -> V_70 = 0 ;
if ( V_177 == V_2 -> V_67 )
V_173 |= V_178 ;
else if ( V_179 == V_2 -> V_67 )
V_173 |= V_180 ;
if ( V_181 == V_2 -> V_68 )
V_173 |= V_182 ;
return F_104 ( V_2 , V_109 , V_173 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
int V_173 = F_83 ( V_2 , V_109 ) ;
if ( V_173 < 0 )
return V_173 ;
V_173 |= V_183 | V_184 ;
V_173 &= ~ V_175 ;
return F_104 ( V_2 , V_109 , V_173 ) ;
}
int F_111 ( struct V_1 * V_2 )
{
int V_42 , V_153 ;
V_153 = F_106 ( V_2 ) ;
if ( V_74 != V_2 -> V_73 )
return F_109 ( V_2 ) ;
V_42 = F_102 ( V_2 ) ;
if ( V_42 < 0 )
return V_42 ;
V_153 |= V_42 ;
if ( V_153 == 0 ) {
int V_173 = F_83 ( V_2 , V_109 ) ;
if ( V_173 < 0 )
return V_173 ;
if ( ! ( V_173 & V_183 ) || ( V_173 & V_175 ) )
V_153 = 1 ;
}
if ( V_153 > 0 )
return F_110 ( V_2 ) ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 )
{
int V_185 = F_83 ( V_2 , V_161 ) ;
return ( V_185 < 0 ) ? V_185 : ( V_185 & V_186 ) ;
}
int F_113 ( struct V_1 * V_2 )
{
int V_187 ;
V_187 = F_83 ( V_2 , V_161 ) ;
if ( V_187 < 0 )
return V_187 ;
V_187 = F_83 ( V_2 , V_161 ) ;
if ( V_187 < 0 )
return V_187 ;
if ( ( V_187 & V_188 ) == 0 )
V_2 -> V_22 = 0 ;
else
V_2 -> V_22 = 1 ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 )
{
int V_151 ;
int V_42 ;
int V_189 ;
int V_190 = 0 ;
int V_191 ;
int V_192 = 0 ;
V_42 = F_113 ( V_2 ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_193 = 0 ;
if ( V_74 == V_2 -> V_73 ) {
if ( V_2 -> V_155 & ( V_166
| V_167 ) ) {
V_190 = F_83 ( V_2 , V_194 ) ;
if ( V_190 < 0 )
return V_190 ;
V_151 = F_83 ( V_2 , V_163 ) ;
if ( V_151 < 0 )
return V_151 ;
V_2 -> V_193 =
F_115 ( V_190 ) ;
V_192 = V_190 & V_151 << 2 ;
}
V_189 = F_83 ( V_2 , V_195 ) ;
if ( V_189 < 0 )
return V_189 ;
V_2 -> V_193 |= F_116 ( V_189 ) ;
V_151 = F_83 ( V_2 , V_156 ) ;
if ( V_151 < 0 )
return V_151 ;
V_191 = V_189 & V_151 ;
V_2 -> V_67 = V_196 ;
V_2 -> V_68 = V_197 ;
V_2 -> V_69 = 0 ;
V_2 -> V_70 = 0 ;
if ( V_192 & ( V_198 | V_199 ) ) {
V_2 -> V_67 = V_177 ;
if ( V_192 & V_198 )
V_2 -> V_68 = V_181 ;
} else if ( V_191 & ( V_200 | V_201 ) ) {
V_2 -> V_67 = V_179 ;
if ( V_191 & V_200 )
V_2 -> V_68 = V_181 ;
} else
if ( V_191 & V_202 )
V_2 -> V_68 = V_181 ;
if ( V_2 -> V_68 == V_181 ) {
V_2 -> V_69 = V_189 & V_203 ? 1 : 0 ;
V_2 -> V_70 = V_189 & V_204 ? 1 : 0 ;
}
} else {
int V_205 = F_83 ( V_2 , V_109 ) ;
if ( V_205 < 0 )
return V_205 ;
if ( V_205 & V_182 )
V_2 -> V_68 = V_181 ;
else
V_2 -> V_68 = V_197 ;
if ( V_205 & V_178 )
V_2 -> V_67 = V_177 ;
else if ( V_205 & V_180 )
V_2 -> V_67 = V_179 ;
else
V_2 -> V_67 = V_196 ;
V_2 -> V_69 = 0 ;
V_2 -> V_70 = 0 ;
}
return 0 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_104 ( V_2 , V_109 , V_110 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_81 ( V_2 ) ;
}
int F_117 ( struct V_1 * V_2 )
{
int V_206 ;
T_1 V_207 ;
V_207 = ( V_208 | V_209
| V_210 | V_211 |
V_212 | V_213 | V_214 ) ;
V_206 = F_83 ( V_2 , V_161 ) ;
if ( V_206 < 0 )
return V_206 ;
if ( V_206 & V_215 )
V_207 |= V_216 ;
if ( V_206 & V_217 )
V_207 |= V_218 ;
if ( V_206 & V_219 )
V_207 |= V_220 ;
if ( V_206 & V_221 )
V_207 |= V_222 ;
if ( V_206 & V_223 )
V_207 |= V_224 ;
if ( V_206 & V_162 ) {
V_206 = F_83 ( V_2 , V_225 ) ;
if ( V_206 < 0 )
return V_206 ;
if ( V_206 & V_226 )
V_207 |= V_167 ;
if ( V_206 & V_227 )
V_207 |= V_166 ;
}
V_2 -> V_155 &= V_207 ;
V_2 -> V_154 &= V_207 ;
return 0 ;
}
int F_118 ( struct V_1 * V_2 )
{
int V_228 ;
F_25 ( & V_2 -> V_79 ) ;
V_228 = F_83 ( V_2 , V_109 ) ;
F_104 ( V_2 , V_109 , V_228 | V_176 ) ;
F_27 ( & V_2 -> V_79 ) ;
return 0 ;
}
int F_119 ( struct V_1 * V_2 )
{
int V_228 ;
F_25 ( & V_2 -> V_79 ) ;
V_228 = F_83 ( V_2 , V_109 ) ;
F_104 ( V_2 , V_109 , V_228 & ~ V_176 ) ;
F_27 ( & V_2 -> V_79 ) ;
return 0 ;
}
int F_120 ( struct V_1 * V_2 , bool V_144 )
{
int V_228 ;
V_228 = F_83 ( V_2 , V_109 ) ;
if ( V_228 < 0 )
return V_228 ;
if ( V_144 )
V_228 |= V_174 ;
else
V_228 &= ~ V_174 ;
return F_104 ( V_2 , V_109 , V_228 ) ;
}
static int F_121 ( struct V_1 * V_2 , T_1 V_229 )
{
V_2 -> V_155 &= V_230 ;
switch ( V_229 ) {
default:
return - V_231 ;
case V_177 :
V_2 -> V_155 |= V_232 ;
case V_179 :
V_2 -> V_155 |= V_233 ;
case V_196 :
V_2 -> V_155 |= V_234 ;
}
return 0 ;
}
int F_122 ( struct V_1 * V_2 , T_1 V_229 )
{
int V_42 ;
V_42 = F_121 ( V_2 , V_229 ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_154 = V_2 -> V_155 ;
return 0 ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_235 * V_236 = V_2 -> V_3 . V_4 . V_237 ;
T_1 V_229 ;
if ( ! F_124 ( V_238 ) )
return;
if ( ! V_236 )
return;
if ( ! F_125 ( V_236 , L_18 , & V_229 ) )
F_121 ( V_2 , V_229 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_235 * V_236 = V_2 -> V_3 . V_4 . V_237 ;
T_1 V_168 = 0 ;
if ( ! F_124 ( V_238 ) )
return;
if ( ! V_236 )
return;
if ( F_127 ( V_236 , L_19 ) )
V_168 |= V_239 ;
if ( F_127 ( V_236 , L_20 ) )
V_168 |= V_240 ;
if ( F_127 ( V_236 , L_21 ) )
V_168 |= V_241 ;
if ( F_127 ( V_236 , L_22 ) )
V_168 |= V_242 ;
if ( F_127 ( V_236 , L_23 ) )
V_168 |= V_243 ;
if ( F_127 ( V_236 , L_24 ) )
V_168 |= V_244 ;
V_2 -> V_169 = V_168 ;
}
static int F_128 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_8 * V_9 = V_2 -> V_3 . V_4 . V_10 ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
int V_42 = 0 ;
V_2 -> V_9 = V_12 ;
if ( ! ( V_12 -> V_49 & V_245 ) &&
F_129 ( V_2 ) )
V_2 -> V_75 = V_119 ;
if ( V_12 -> V_49 & V_246 )
V_2 -> V_247 = true ;
F_25 ( & V_2 -> V_79 ) ;
V_2 -> V_155 = V_12 -> V_207 ;
F_123 ( V_2 ) ;
V_2 -> V_154 = V_2 -> V_155 ;
F_126 ( V_2 ) ;
if ( V_12 -> V_207 & ( V_213 | V_214 ) ) {
V_2 -> V_155 &= ~ ( V_213 | V_214 ) ;
V_2 -> V_155 |= V_12 -> V_207 &
( V_213 | V_214 ) ;
} else {
V_2 -> V_155 |= V_213 | V_214 ;
}
V_2 -> V_23 = V_135 ;
if ( V_2 -> V_9 -> V_130 )
V_42 = V_2 -> V_9 -> V_130 ( V_2 ) ;
F_27 ( & V_2 -> V_79 ) ;
return V_42 ;
}
static int F_130 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
F_131 ( & V_2 -> V_80 ) ;
F_25 ( & V_2 -> V_79 ) ;
V_2 -> V_23 = V_78 ;
F_27 ( & V_2 -> V_79 ) ;
if ( V_2 -> V_9 && V_2 -> V_9 -> remove )
V_2 -> V_9 -> remove ( V_2 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
int F_132 ( struct V_11 * V_248 , struct V_123 * V_125 )
{
int V_185 ;
V_248 -> V_48 . V_49 |= V_50 ;
V_248 -> V_48 . V_10 . V_116 = V_248 -> V_116 ;
V_248 -> V_48 . V_10 . V_56 = & V_60 ;
V_248 -> V_48 . V_10 . V_130 = F_128 ;
V_248 -> V_48 . V_10 . remove = F_130 ;
V_248 -> V_48 . V_10 . V_125 = V_125 ;
V_185 = F_133 ( & V_248 -> V_48 . V_10 ) ;
if ( V_185 ) {
F_62 ( L_25 ,
V_248 -> V_116 , V_185 ) ;
return V_185 ;
}
F_134 ( L_26 , V_248 -> V_116 ) ;
return 0 ;
}
int F_135 ( struct V_11 * V_248 , int V_39 ,
struct V_123 * V_125 )
{
int V_47 , V_20 = 0 ;
for ( V_47 = 0 ; V_47 < V_39 ; V_47 ++ ) {
V_20 = F_132 ( V_248 + V_47 , V_125 ) ;
if ( V_20 ) {
while ( V_47 -- > 0 )
F_136 ( V_248 + V_47 ) ;
break;
}
}
return V_20 ;
}
void F_136 ( struct V_11 * V_9 )
{
F_137 ( & V_9 -> V_48 . V_10 ) ;
}
void F_138 ( struct V_11 * V_9 , int V_39 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_39 ; V_47 ++ )
F_136 ( V_9 + V_47 ) ;
}
static int T_5 F_139 ( void )
{
int V_105 ;
V_105 = F_140 () ;
if ( V_105 )
return V_105 ;
V_105 = F_132 ( & V_127 , V_249 ) ;
if ( V_105 )
goto V_250;
V_105 = F_132 ( & V_128 , V_249 ) ;
if ( V_105 ) {
F_136 ( & V_127 ) ;
V_250:
F_141 () ;
}
return V_105 ;
}
static void T_6 F_142 ( void )
{
F_136 ( & V_127 ) ;
F_136 ( & V_128 ) ;
F_141 () ;
}
