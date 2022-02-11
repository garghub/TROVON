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
static void F_68 ( struct V_1 * V_2 ,
void (* F_69)( struct V_13 * ) )
{
V_2 -> V_19 = F_69 ;
}
int F_70 ( struct V_13 * V_4 , struct V_1 * V_2 ,
void (* F_69)( struct V_13 * ) ,
T_3 V_71 )
{
int V_103 ;
V_103 = F_71 ( V_4 , V_2 , V_2 -> V_104 , V_71 ) ;
if ( V_103 )
return V_103 ;
F_68 ( V_2 , F_69 ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_75 > 0 )
F_72 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_73 ( struct V_13 * V_4 , const char * V_25 ,
void (* F_69)( struct V_13 * ) ,
T_3 V_71 )
{
struct V_1 * V_2 ;
struct V_7 * V_105 ;
int V_103 ;
V_105 = F_74 ( & V_60 , NULL , V_25 ) ;
if ( ! V_105 ) {
F_62 ( L_7 , V_25 ) ;
return F_43 ( - V_40 ) ;
}
V_2 = F_7 ( V_105 ) ;
V_103 = F_70 ( V_4 , V_2 , F_69 , V_71 ) ;
F_2 ( V_105 ) ;
if ( V_103 )
return F_43 ( V_103 ) ;
return V_2 ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 > 0 )
F_76 ( V_2 ) ;
F_14 ( V_2 ) ;
V_2 -> V_19 = NULL ;
F_77 ( V_2 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
unsigned int V_106 = 12 ;
int V_20 ;
do {
F_79 ( 50 ) ;
V_20 = F_80 ( V_2 , V_107 ) ;
if ( V_20 < 0 )
return V_20 ;
} while ( V_20 & V_108 && -- V_106 );
if ( V_20 & V_108 )
return - V_109 ;
F_79 ( 1 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
if ( ! V_2 -> V_9 || ! V_2 -> V_9 -> V_110 )
return 0 ;
if ( V_2 -> V_9 -> V_111 )
V_20 = V_2 -> V_9 -> V_111 ( V_2 ) ;
else
V_20 = F_81 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_38 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
return V_2 -> V_9 -> V_110 ( V_2 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
F_83 ( V_2 , NULL ) ;
}
void F_83 ( struct V_1 * V_2 , const char * V_112 , ... )
{
const char * V_113 = V_2 -> V_9 ? V_2 -> V_9 -> V_114 : L_8 ;
if ( ! V_112 ) {
F_84 ( & V_2 -> V_3 . V_4 , V_115 L_9 ,
V_113 , F_37 ( V_2 ) ,
V_2 -> V_75 ) ;
} else {
T_4 V_116 ;
F_84 ( & V_2 -> V_3 . V_4 , V_115 ,
V_113 , F_37 ( V_2 ) ,
V_2 -> V_75 ) ;
va_start ( V_116 , V_112 ) ;
F_85 ( V_112 , V_116 ) ;
va_end ( V_116 ) ;
}
}
int F_71 ( struct V_13 * V_4 , struct V_1 * V_2 ,
T_1 V_49 , T_3 V_71 )
{
struct V_117 * V_118 = V_4 -> V_4 . V_18 -> V_10 -> V_119 ;
struct V_55 * V_56 = V_2 -> V_3 . V_56 ;
struct V_7 * V_105 = & V_2 -> V_3 . V_4 ;
bool V_120 = false ;
int V_42 ;
if ( V_118 != V_56 -> V_119 && ! F_86 ( V_56 -> V_119 ) ) {
F_87 ( & V_4 -> V_4 , L_10 ) ;
return - V_89 ;
}
F_88 ( V_105 ) ;
if ( ! V_105 -> V_10 ) {
if ( V_2 -> V_52 )
V_105 -> V_10 = & V_121 . V_48 . V_10 ;
else
V_105 -> V_10 = & V_122 . V_48 . V_10 ;
V_120 = true ;
}
if ( ! F_86 ( V_105 -> V_10 -> V_119 ) ) {
F_87 ( & V_4 -> V_4 , L_11 ) ;
V_42 = - V_89 ;
goto V_123;
}
if ( V_120 ) {
V_42 = V_105 -> V_10 -> V_124 ( V_105 ) ;
if ( V_42 >= 0 )
V_42 = F_89 ( V_105 ) ;
if ( V_42 )
goto V_125;
}
if ( V_2 -> V_15 ) {
F_87 ( & V_4 -> V_4 , L_12 ) ;
V_42 = - V_126 ;
goto error;
}
V_2 -> V_15 = V_4 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_127 = false ;
V_42 = F_90 ( & V_2 -> V_3 . V_4 . V_128 , & V_4 -> V_4 . V_128 ,
L_13 ) ;
if ( ! V_42 ) {
V_42 = F_90 ( & V_4 -> V_4 . V_128 , & V_2 -> V_3 . V_4 . V_128 ,
L_14 ) ;
if ( V_42 )
goto error;
V_2 -> V_127 = true ;
}
V_2 -> V_104 = V_49 ;
V_2 -> V_71 = V_71 ;
V_2 -> V_23 = V_129 ;
F_91 ( V_2 -> V_15 ) ;
V_42 = F_20 ( V_2 ) ;
if ( V_42 )
goto error;
F_17 ( V_2 ) ;
F_92 ( V_2 ) ;
return V_42 ;
error:
F_77 ( V_2 ) ;
return V_42 ;
V_125:
F_93 ( V_105 -> V_10 -> V_119 ) ;
V_123:
F_2 ( V_105 ) ;
if ( V_118 != V_56 -> V_119 )
F_93 ( V_56 -> V_119 ) ;
return V_42 ;
}
struct V_1 * F_94 ( struct V_13 * V_4 , const char * V_25 ,
T_3 V_71 )
{
struct V_130 * V_56 = & V_60 ;
struct V_1 * V_2 ;
struct V_7 * V_105 ;
int V_103 ;
V_105 = F_74 ( V_56 , NULL , V_25 ) ;
if ( ! V_105 ) {
F_62 ( L_7 , V_25 ) ;
return F_43 ( - V_40 ) ;
}
V_2 = F_7 ( V_105 ) ;
V_103 = F_71 ( V_4 , V_2 , V_2 -> V_104 , V_71 ) ;
F_2 ( V_105 ) ;
if ( V_103 )
return F_43 ( V_103 ) ;
return V_2 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_13 * V_4 = V_2 -> V_15 ;
struct V_117 * V_118 = V_4 -> V_4 . V_18 -> V_10 -> V_119 ;
struct V_55 * V_56 ;
if ( V_2 -> V_127 ) {
F_95 ( & V_4 -> V_4 . V_128 , L_14 ) ;
F_95 ( & V_2 -> V_3 . V_4 . V_128 , L_13 ) ;
}
V_2 -> V_15 -> V_2 = NULL ;
V_2 -> V_15 = NULL ;
F_15 ( V_2 ) ;
F_96 ( V_2 ) ;
F_93 ( V_2 -> V_3 . V_4 . V_10 -> V_119 ) ;
if ( V_2 -> V_3 . V_4 . V_10 == & V_121 . V_48 . V_10 ||
V_2 -> V_3 . V_4 . V_10 == & V_122 . V_48 . V_10 )
F_97 ( & V_2 -> V_3 . V_4 ) ;
V_56 = V_2 -> V_3 . V_56 ;
F_2 ( & V_2 -> V_3 . V_4 ) ;
if ( V_118 != V_56 -> V_119 )
F_93 ( V_56 -> V_119 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_11 ( V_2 -> V_3 . V_4 . V_10 ) ;
struct V_131 V_132 = { . V_133 = V_134 } ;
int V_20 = 0 ;
F_98 ( V_2 , & V_132 ) ;
if ( V_132 . V_135 )
return - V_126 ;
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
if ( V_2 -> V_9 && V_12 -> V_136 )
V_20 = V_12 -> V_136 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_17 = false ;
return V_20 ;
}
int F_99 ( struct V_1 * V_2 , bool V_137 )
{
struct V_11 * V_12 = F_11 ( V_2 -> V_3 . V_4 . V_10 ) ;
int V_20 = 0 ;
F_25 ( & V_2 -> V_79 ) ;
if ( V_137 && V_2 -> V_138 ) {
V_20 = - V_126 ;
goto V_99;
}
if ( ! V_137 && ! V_2 -> V_138 ) {
V_20 = - V_139 ;
goto V_99;
}
if ( V_2 -> V_9 && V_12 -> V_140 )
V_20 = V_12 -> V_140 ( V_2 , V_137 ) ;
else
V_20 = - V_141 ;
if ( V_20 )
goto V_99;
V_2 -> V_138 = V_137 ;
V_99:
F_27 ( & V_2 -> V_79 ) ;
return V_20 ;
}
static int F_100 ( struct V_1 * V_2 )
{
T_1 V_142 ;
int V_143 , V_144 , V_145 ;
int V_42 , V_146 = 0 ;
V_2 -> V_147 &= V_2 -> V_148 ;
V_142 = V_2 -> V_147 ;
V_144 = F_80 ( V_2 , V_149 ) ;
if ( V_144 < 0 )
return V_144 ;
V_143 = V_144 ;
V_144 &= ~ ( V_150 | V_151 | V_152 |
V_153 ) ;
V_144 |= F_101 ( V_142 ) ;
if ( V_144 != V_143 ) {
V_42 = F_102 ( V_2 , V_149 , V_144 ) ;
if ( V_42 < 0 )
return V_42 ;
V_146 = 1 ;
}
V_145 = F_80 ( V_2 , V_154 ) ;
if ( V_145 < 0 )
return V_145 ;
if ( ! ( V_145 & V_155 ) )
return V_146 ;
V_144 = F_80 ( V_2 , V_156 ) ;
if ( V_144 < 0 )
return V_144 ;
V_143 = V_144 ;
V_144 &= ~ ( V_157 | V_158 ) ;
if ( V_2 -> V_148 & ( V_159 |
V_160 ) ) {
V_144 |= F_103 ( V_142 ) ;
}
if ( V_144 != V_143 )
V_146 = 1 ;
V_42 = F_102 ( V_2 , V_156 , V_144 ) ;
if ( V_42 < 0 )
return V_42 ;
return V_146 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_161 = V_2 -> V_162 ;
int V_163 , V_144 ;
if ( ! V_161 )
return 0 ;
V_144 = F_105 ( V_2 , V_164 , V_165 ) ;
if ( V_144 <= 0 )
return 0 ;
V_163 = V_144 ;
V_144 &= ~ V_161 ;
if ( V_163 == V_144 )
return 0 ;
F_106 ( V_2 , V_164 , V_165 , V_144 ) ;
return 1 ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_166 = F_80 ( V_2 , V_107 ) ;
V_166 &= V_167 | V_168 | V_169 ;
V_2 -> V_69 = 0 ;
V_2 -> V_70 = 0 ;
if ( V_170 == V_2 -> V_67 )
V_166 |= V_171 ;
else if ( V_172 == V_2 -> V_67 )
V_166 |= V_173 ;
if ( V_174 == V_2 -> V_68 )
V_166 |= V_175 ;
return F_102 ( V_2 , V_107 , V_166 ) ;
}
int F_108 ( struct V_1 * V_2 )
{
int V_166 = F_80 ( V_2 , V_107 ) ;
if ( V_166 < 0 )
return V_166 ;
V_166 |= V_176 | V_177 ;
V_166 &= ~ V_168 ;
return F_102 ( V_2 , V_107 , V_166 ) ;
}
int F_109 ( struct V_1 * V_2 )
{
int V_42 , V_146 ;
V_146 = F_104 ( V_2 ) ;
if ( V_74 != V_2 -> V_73 )
return F_107 ( V_2 ) ;
V_42 = F_100 ( V_2 ) ;
if ( V_42 < 0 )
return V_42 ;
V_146 |= V_42 ;
if ( V_146 == 0 ) {
int V_166 = F_80 ( V_2 , V_107 ) ;
if ( V_166 < 0 )
return V_166 ;
if ( ! ( V_166 & V_176 ) || ( V_166 & V_168 ) )
V_146 = 1 ;
}
if ( V_146 > 0 )
return F_108 ( V_2 ) ;
return 0 ;
}
int F_110 ( struct V_1 * V_2 )
{
int V_178 = F_80 ( V_2 , V_154 ) ;
return ( V_178 < 0 ) ? V_178 : ( V_178 & V_179 ) ;
}
int F_111 ( struct V_1 * V_2 )
{
int V_180 ;
V_180 = F_80 ( V_2 , V_154 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_80 ( V_2 , V_154 ) ;
if ( V_180 < 0 )
return V_180 ;
if ( ( V_180 & V_181 ) == 0 )
V_2 -> V_22 = 0 ;
else
V_2 -> V_22 = 1 ;
return 0 ;
}
int F_112 ( struct V_1 * V_2 )
{
int V_144 ;
int V_42 ;
int V_182 ;
int V_183 = 0 ;
int V_184 ;
int V_185 = 0 ;
V_42 = F_111 ( V_2 ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_186 = 0 ;
if ( V_74 == V_2 -> V_73 ) {
if ( V_2 -> V_148 & ( V_159
| V_160 ) ) {
V_183 = F_80 ( V_2 , V_187 ) ;
if ( V_183 < 0 )
return V_183 ;
V_144 = F_80 ( V_2 , V_156 ) ;
if ( V_144 < 0 )
return V_144 ;
V_2 -> V_186 =
F_113 ( V_183 ) ;
V_185 = V_183 & V_144 << 2 ;
}
V_182 = F_80 ( V_2 , V_188 ) ;
if ( V_182 < 0 )
return V_182 ;
V_2 -> V_186 |= F_114 ( V_182 ) ;
V_144 = F_80 ( V_2 , V_149 ) ;
if ( V_144 < 0 )
return V_144 ;
V_184 = V_182 & V_144 ;
V_2 -> V_67 = V_189 ;
V_2 -> V_68 = V_190 ;
V_2 -> V_69 = 0 ;
V_2 -> V_70 = 0 ;
if ( V_185 & ( V_191 | V_192 ) ) {
V_2 -> V_67 = V_170 ;
if ( V_185 & V_191 )
V_2 -> V_68 = V_174 ;
} else if ( V_184 & ( V_193 | V_194 ) ) {
V_2 -> V_67 = V_172 ;
if ( V_184 & V_193 )
V_2 -> V_68 = V_174 ;
} else
if ( V_184 & V_195 )
V_2 -> V_68 = V_174 ;
if ( V_2 -> V_68 == V_174 ) {
V_2 -> V_69 = V_182 & V_196 ? 1 : 0 ;
V_2 -> V_70 = V_182 & V_197 ? 1 : 0 ;
}
} else {
int V_198 = F_80 ( V_2 , V_107 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_198 & V_175 )
V_2 -> V_68 = V_174 ;
else
V_2 -> V_68 = V_190 ;
if ( V_198 & V_171 )
V_2 -> V_67 = V_170 ;
else if ( V_198 & V_173 )
V_2 -> V_67 = V_172 ;
else
V_2 -> V_67 = V_189 ;
V_2 -> V_69 = 0 ;
V_2 -> V_70 = 0 ;
}
return 0 ;
}
int F_81 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_102 ( V_2 , V_107 , V_108 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_78 ( V_2 ) ;
}
int F_115 ( struct V_1 * V_2 )
{
int V_199 ;
T_1 V_200 ;
V_200 = ( V_201 | V_202
| V_203 | V_204 |
V_205 | V_206 | V_207 ) ;
V_199 = F_80 ( V_2 , V_154 ) ;
if ( V_199 < 0 )
return V_199 ;
if ( V_199 & V_208 )
V_200 |= V_209 ;
if ( V_199 & V_210 )
V_200 |= V_211 ;
if ( V_199 & V_212 )
V_200 |= V_213 ;
if ( V_199 & V_214 )
V_200 |= V_215 ;
if ( V_199 & V_216 )
V_200 |= V_217 ;
if ( V_199 & V_155 ) {
V_199 = F_80 ( V_2 , V_218 ) ;
if ( V_199 < 0 )
return V_199 ;
if ( V_199 & V_219 )
V_200 |= V_160 ;
if ( V_199 & V_220 )
V_200 |= V_159 ;
}
V_2 -> V_148 &= V_200 ;
V_2 -> V_147 &= V_200 ;
return 0 ;
}
int F_116 ( struct V_1 * V_2 )
{
int V_221 ;
F_25 ( & V_2 -> V_79 ) ;
V_221 = F_80 ( V_2 , V_107 ) ;
F_102 ( V_2 , V_107 , V_221 | V_169 ) ;
F_27 ( & V_2 -> V_79 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 )
{
int V_221 ;
F_25 ( & V_2 -> V_79 ) ;
V_221 = F_80 ( V_2 , V_107 ) ;
F_102 ( V_2 , V_107 , V_221 & ~ V_169 ) ;
F_27 ( & V_2 -> V_79 ) ;
return 0 ;
}
int F_118 ( struct V_1 * V_2 , bool V_137 )
{
int V_221 ;
V_221 = F_80 ( V_2 , V_107 ) ;
if ( V_221 < 0 )
return V_221 ;
if ( V_137 )
V_221 |= V_167 ;
else
V_221 &= ~ V_167 ;
return F_102 ( V_2 , V_107 , V_221 ) ;
}
static int F_119 ( struct V_1 * V_2 , T_1 V_222 )
{
V_2 -> V_148 &= V_223 ;
switch ( V_222 ) {
default:
return - V_224 ;
case V_170 :
V_2 -> V_148 |= V_225 ;
case V_172 :
V_2 -> V_148 |= V_226 ;
case V_189 :
V_2 -> V_148 |= V_227 ;
}
return 0 ;
}
int F_120 ( struct V_1 * V_2 , T_1 V_222 )
{
int V_42 ;
V_42 = F_119 ( V_2 , V_222 ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_147 = V_2 -> V_148 ;
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
struct V_228 * V_229 = V_2 -> V_3 . V_4 . V_230 ;
T_1 V_222 ;
if ( ! F_122 ( V_231 ) )
return;
if ( ! V_229 )
return;
if ( ! F_123 ( V_229 , L_15 , & V_222 ) )
F_119 ( V_2 , V_222 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_228 * V_229 = V_2 -> V_3 . V_4 . V_230 ;
T_1 V_161 = 0 ;
if ( ! F_122 ( V_231 ) )
return;
if ( ! V_229 )
return;
if ( F_125 ( V_229 , L_16 ) )
V_161 |= V_232 ;
if ( F_125 ( V_229 , L_17 ) )
V_161 |= V_233 ;
if ( F_125 ( V_229 , L_18 ) )
V_161 |= V_234 ;
if ( F_125 ( V_229 , L_19 ) )
V_161 |= V_235 ;
if ( F_125 ( V_229 , L_20 ) )
V_161 |= V_236 ;
if ( F_125 ( V_229 , L_21 ) )
V_161 |= V_237 ;
V_2 -> V_162 = V_161 ;
}
static int F_126 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_8 * V_9 = V_2 -> V_3 . V_4 . V_10 ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
int V_42 = 0 ;
V_2 -> V_9 = V_12 ;
if ( ! ( V_12 -> V_49 & V_238 ) &&
F_127 ( V_2 ) )
V_2 -> V_75 = V_239 ;
if ( V_12 -> V_49 & V_240 )
V_2 -> V_241 = true ;
F_25 ( & V_2 -> V_79 ) ;
V_2 -> V_148 = V_12 -> V_200 ;
F_121 ( V_2 ) ;
V_2 -> V_147 = V_2 -> V_148 ;
F_124 ( V_2 ) ;
if ( V_12 -> V_200 & ( V_206 | V_207 ) ) {
V_2 -> V_148 &= ~ ( V_206 | V_207 ) ;
V_2 -> V_148 |= V_12 -> V_200 &
( V_206 | V_207 ) ;
} else {
V_2 -> V_148 |= V_206 | V_207 ;
}
V_2 -> V_23 = V_129 ;
if ( V_2 -> V_9 -> V_124 )
V_42 = V_2 -> V_9 -> V_124 ( V_2 ) ;
F_27 ( & V_2 -> V_79 ) ;
return V_42 ;
}
static int F_128 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
F_129 ( & V_2 -> V_80 ) ;
F_25 ( & V_2 -> V_79 ) ;
V_2 -> V_23 = V_78 ;
F_27 ( & V_2 -> V_79 ) ;
if ( V_2 -> V_9 && V_2 -> V_9 -> remove )
V_2 -> V_9 -> remove ( V_2 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
int F_130 ( struct V_11 * V_242 , struct V_117 * V_119 )
{
int V_178 ;
V_242 -> V_48 . V_49 |= V_50 ;
V_242 -> V_48 . V_10 . V_114 = V_242 -> V_114 ;
V_242 -> V_48 . V_10 . V_56 = & V_60 ;
V_242 -> V_48 . V_10 . V_124 = F_126 ;
V_242 -> V_48 . V_10 . remove = F_128 ;
V_242 -> V_48 . V_10 . V_119 = V_119 ;
V_178 = F_131 ( & V_242 -> V_48 . V_10 ) ;
if ( V_178 ) {
F_62 ( L_22 ,
V_242 -> V_114 , V_178 ) ;
return V_178 ;
}
F_132 ( L_23 , V_242 -> V_114 ) ;
return 0 ;
}
int F_133 ( struct V_11 * V_242 , int V_39 ,
struct V_117 * V_119 )
{
int V_47 , V_20 = 0 ;
for ( V_47 = 0 ; V_47 < V_39 ; V_47 ++ ) {
V_20 = F_130 ( V_242 + V_47 , V_119 ) ;
if ( V_20 ) {
while ( V_47 -- > 0 )
F_134 ( V_242 + V_47 ) ;
break;
}
}
return V_20 ;
}
void F_134 ( struct V_11 * V_9 )
{
F_135 ( & V_9 -> V_48 . V_10 ) ;
}
void F_136 ( struct V_11 * V_9 , int V_39 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_39 ; V_47 ++ )
F_134 ( V_9 + V_47 ) ;
}
static int T_5 F_137 ( void )
{
int V_103 ;
V_103 = F_138 () ;
if ( V_103 )
return V_103 ;
V_103 = F_130 ( & V_121 , V_243 ) ;
if ( V_103 )
goto V_244;
V_103 = F_130 ( & V_122 , V_243 ) ;
if ( V_103 ) {
F_134 ( & V_121 ) ;
V_244:
F_139 () ;
}
return V_103 ;
}
static void T_6 F_140 ( void )
{
F_134 ( & V_121 ) ;
F_134 ( & V_122 ) ;
F_139 () ;
}
