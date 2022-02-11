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
static int F_30 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
if ( strcmp ( V_29 -> V_25 , F_31 ( V_2 ) ) != 0 )
if ( strcmp ( V_29 -> V_25 , V_35 ) != 0 )
return 0 ;
if ( ( V_29 -> V_26 & V_29 -> V_27 ) !=
( V_2 -> V_37 & V_29 -> V_27 ) )
if ( V_29 -> V_26 != V_36 )
return 0 ;
return 1 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
F_25 ( & V_32 ) ;
F_33 (fixup, &phy_fixup_list, list) {
if ( F_30 ( V_2 , V_29 ) ) {
int V_38 = V_29 -> F_22 ( V_2 ) ;
if ( V_38 < 0 ) {
F_27 ( & V_32 ) ;
return V_38 ;
}
V_2 -> V_39 = true ;
}
}
F_27 ( & V_32 ) ;
return 0 ;
}
static int F_34 ( struct V_7 * V_4 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const int V_40 = F_35 ( V_2 -> V_41 . V_42 ) ;
int V_43 ;
if ( ! ( V_12 -> V_44 . V_45 & V_46 ) )
return 0 ;
if ( V_12 -> V_47 )
return V_12 -> V_47 ( V_2 ) ;
if ( V_2 -> V_48 ) {
for ( V_43 = 1 ; V_43 < V_40 ; V_43 ++ ) {
if ( ! ( V_2 -> V_41 . V_49 & ( 1 << V_43 ) ) )
continue;
if ( ( V_12 -> V_37 & V_12 -> V_50 ) ==
( V_2 -> V_41 . V_42 [ V_43 ] &
V_12 -> V_50 ) )
return 1 ;
}
return 0 ;
} else {
return ( V_12 -> V_37 & V_12 -> V_50 ) ==
( V_2 -> V_37 & V_12 -> V_50 ) ;
}
}
struct V_1 * F_36 ( struct V_51 * V_52 , int V_53 , int V_37 ,
bool V_48 ,
struct V_54 * V_41 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return F_37 ( - V_31 ) ;
V_6 = & V_4 -> V_3 ;
V_6 -> V_4 . V_55 = F_5 ;
V_6 -> V_4 . V_18 = & V_52 -> V_4 ;
V_6 -> V_4 . V_52 = & V_56 ;
V_6 -> V_52 = V_52 ;
V_6 -> V_57 = V_58 ;
V_6 -> V_59 = F_34 ;
V_6 -> V_53 = V_53 ;
V_6 -> V_45 = V_60 ;
V_6 -> V_61 = F_3 ;
V_6 -> V_62 = F_8 ;
V_4 -> V_63 = 0 ;
V_4 -> V_64 = - 1 ;
V_4 -> V_65 = 0 ;
V_4 -> V_66 = 0 ;
V_4 -> V_22 = 1 ;
V_4 -> V_67 = V_68 ;
V_4 -> V_69 = V_70 ;
V_4 -> V_48 = V_48 ;
V_4 -> V_37 = V_37 ;
if ( V_41 )
V_4 -> V_41 = * V_41 ;
V_4 -> V_71 = V_52 -> V_71 [ V_53 ] ;
F_38 ( & V_6 -> V_4 , V_72 , V_52 -> V_73 , V_53 ) ;
V_4 -> V_23 = V_74 ;
F_39 ( & V_4 -> V_75 ) ;
F_40 ( & V_4 -> V_76 , V_77 ) ;
F_41 ( & V_4 -> V_78 , V_79 ) ;
F_42 (MDIO_MODULE_PREFIX MDIO_ID_FMT, MDIO_ID_ARGS(phy_id)) ;
F_43 ( & V_6 -> V_4 ) ;
return V_4 ;
}
static int F_44 ( struct V_51 * V_52 , int V_53 , int V_80 ,
T_1 * V_49 )
{
int V_81 , V_82 ;
V_82 = V_83 | V_80 << 16 | V_84 ;
V_81 = F_45 ( V_52 , V_53 , V_82 ) ;
if ( V_81 < 0 )
return - V_85 ;
* V_49 = ( V_81 & 0xffff ) << 16 ;
V_82 = V_83 | V_80 << 16 | V_86 ;
V_81 = F_45 ( V_52 , V_53 , V_82 ) ;
if ( V_81 < 0 )
return - V_85 ;
* V_49 |= ( V_81 & 0xffff ) ;
return 0 ;
}
static int F_46 ( struct V_51 * V_52 , int V_53 , T_1 * V_37 ,
struct V_54 * V_41 ) {
int V_81 ;
int V_43 , V_82 ;
const int V_40 = F_35 ( V_41 -> V_42 ) ;
T_1 * V_87 = & V_41 -> V_49 ;
for ( V_43 = 1 ; V_43 < V_40 && * V_87 == 0 ; V_43 ++ ) {
V_81 = F_44 ( V_52 , V_53 , V_43 , V_87 ) ;
if ( V_81 < 0 )
return - V_85 ;
if ( ( * V_87 & 0x1fffffff ) == 0x1fffffff ) {
V_81 = F_44 ( V_52 , V_53 , 0 , V_87 ) ;
if ( V_81 < 0 )
return - V_85 ;
if ( ( * V_87 & 0x1fffffff ) == 0x1fffffff ) {
* V_37 = 0xffffffff ;
return 0 ;
} else {
break;
}
}
}
for ( V_43 = 1 ; V_43 < V_40 ; V_43 ++ ) {
if ( ! ( V_41 -> V_49 & ( 1 << V_43 ) ) )
continue;
V_82 = V_83 | V_43 << 16 | V_88 ;
V_81 = F_45 ( V_52 , V_53 , V_82 ) ;
if ( V_81 < 0 )
return - V_85 ;
V_41 -> V_42 [ V_43 ] = ( V_81 & 0xffff ) << 16 ;
V_82 = V_83 | V_43 << 16 | V_89 ;
V_81 = F_45 ( V_52 , V_53 , V_82 ) ;
if ( V_81 < 0 )
return - V_85 ;
V_41 -> V_42 [ V_43 ] |= ( V_81 & 0xffff ) ;
}
* V_37 = 0 ;
return 0 ;
}
static int F_47 ( struct V_51 * V_52 , int V_53 , T_1 * V_37 ,
bool V_48 , struct V_54 * V_41 )
{
int V_81 ;
if ( V_48 )
return F_46 ( V_52 , V_53 , V_37 , V_41 ) ;
V_81 = F_45 ( V_52 , V_53 , V_88 ) ;
if ( V_81 < 0 )
return - V_85 ;
* V_37 = ( V_81 & 0xffff ) << 16 ;
V_81 = F_45 ( V_52 , V_53 , V_89 ) ;
if ( V_81 < 0 )
return - V_85 ;
* V_37 |= ( V_81 & 0xffff ) ;
return 0 ;
}
struct V_1 * F_48 ( struct V_51 * V_52 , int V_53 , bool V_48 )
{
struct V_54 V_41 = { 0 } ;
T_1 V_37 = 0 ;
int V_90 ;
V_90 = F_47 ( V_52 , V_53 , & V_37 , V_48 , & V_41 ) ;
if ( V_90 )
return F_37 ( V_90 ) ;
if ( ( V_37 & 0x1fffffff ) == 0x1fffffff )
return F_37 ( - V_91 ) ;
return F_36 ( V_52 , V_53 , V_37 , V_48 , & V_41 ) ;
}
static T_2
F_49 ( struct V_7 * V_4 , struct V_92 * V_93 , char * V_94 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
return sprintf ( V_94 , L_1 , ( unsigned long ) V_2 -> V_37 ) ;
}
static T_2
F_50 ( struct V_7 * V_4 , struct V_92 * V_93 , char * V_94 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
const char * V_95 = NULL ;
if ( F_51 ( V_2 ) )
V_95 = L_2 ;
else
V_95 = F_52 ( V_2 -> V_67 ) ;
return sprintf ( V_94 , L_3 , V_95 ) ;
}
static T_2
F_53 ( struct V_7 * V_4 , struct V_92 * V_93 ,
char * V_94 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
return sprintf ( V_94 , L_4 , V_2 -> V_39 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_55 ( & V_2 -> V_3 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_32 ( V_2 ) ;
if ( V_38 ) {
F_56 ( L_5 , V_2 -> V_3 . V_53 ) ;
goto V_96;
}
V_2 -> V_3 . V_4 . V_97 = V_98 ;
V_38 = F_57 ( & V_2 -> V_3 . V_4 ) ;
if ( V_38 ) {
F_56 ( L_6 , V_2 -> V_3 . V_53 ) ;
goto V_96;
}
return 0 ;
V_96:
F_58 ( & V_2 -> V_3 ) ;
return V_38 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_3 . V_4 ) ;
F_58 ( & V_2 -> V_3 ) ;
}
struct V_1 * F_60 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_99 ; V_53 ++ ) {
V_2 = F_61 ( V_52 , V_53 ) ;
if ( V_2 )
return V_2 ;
}
return NULL ;
}
static void F_62 ( struct V_1 * V_2 ,
void (* F_63)( struct V_13 * ) )
{
V_2 -> V_19 = F_63 ;
}
int F_64 ( struct V_13 * V_4 , struct V_1 * V_2 ,
void (* F_63)( struct V_13 * ) ,
T_3 V_67 )
{
int V_100 ;
V_100 = F_65 ( V_4 , V_2 , V_2 -> V_101 , V_67 ) ;
if ( V_100 )
return V_100 ;
F_62 ( V_2 , F_63 ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_71 > 0 )
F_66 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_67 ( struct V_13 * V_4 , const char * V_25 ,
void (* F_63)( struct V_13 * ) ,
T_3 V_67 )
{
struct V_1 * V_2 ;
struct V_7 * V_102 ;
int V_100 ;
V_102 = F_68 ( & V_56 , NULL , V_25 ) ;
if ( ! V_102 ) {
F_56 ( L_7 , V_25 ) ;
return F_37 ( - V_91 ) ;
}
V_2 = F_7 ( V_102 ) ;
V_100 = F_64 ( V_4 , V_2 , F_63 , V_67 ) ;
if ( V_100 )
return F_37 ( V_100 ) ;
return V_2 ;
}
void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_71 > 0 )
F_70 ( V_2 ) ;
F_14 ( V_2 ) ;
V_2 -> V_19 = NULL ;
F_71 ( V_2 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
unsigned int V_103 = 12 ;
int V_20 ;
do {
F_73 ( 50 ) ;
V_20 = F_74 ( V_2 , V_104 ) ;
if ( V_20 < 0 )
return V_20 ;
} while ( V_20 & V_105 && -- V_103 );
if ( V_20 & V_105 )
return - V_106 ;
F_73 ( 1 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
if ( ! V_2 -> V_9 || ! V_2 -> V_9 -> V_107 )
return 0 ;
if ( V_2 -> V_9 -> V_108 )
V_20 = V_2 -> V_9 -> V_108 ( V_2 ) ;
else
V_20 = F_75 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_32 ( V_2 ) ;
if ( V_20 < 0 )
return V_20 ;
return V_2 -> V_9 -> V_107 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
F_77 ( V_2 , NULL ) ;
}
void F_77 ( struct V_1 * V_2 , const char * V_109 , ... )
{
if ( ! V_109 ) {
F_78 ( & V_2 -> V_3 . V_4 , V_110 L_8 ,
V_2 -> V_9 -> V_111 , F_31 ( V_2 ) ,
V_2 -> V_71 ) ;
} else {
T_4 V_112 ;
F_78 ( & V_2 -> V_3 . V_4 , V_110 ,
V_2 -> V_9 -> V_111 , F_31 ( V_2 ) ,
V_2 -> V_71 ) ;
va_start ( V_112 , V_109 ) ;
F_79 ( V_109 , V_112 ) ;
va_end ( V_112 ) ;
}
}
int F_65 ( struct V_13 * V_4 , struct V_1 * V_2 ,
T_1 V_45 , T_3 V_67 )
{
struct V_51 * V_52 = V_2 -> V_3 . V_52 ;
struct V_7 * V_102 = & V_2 -> V_3 . V_4 ;
int V_38 ;
if ( ! F_80 ( V_52 -> V_113 ) ) {
F_81 ( & V_4 -> V_4 , L_9 ) ;
return - V_85 ;
}
F_82 ( V_102 ) ;
if ( ! V_102 -> V_10 ) {
if ( V_2 -> V_48 )
V_102 -> V_10 =
& V_114 [ V_115 ] . V_44 . V_10 ;
else
V_102 -> V_10 =
& V_114 [ V_116 ] . V_44 . V_10 ;
V_38 = V_102 -> V_10 -> V_117 ( V_102 ) ;
if ( V_38 >= 0 )
V_38 = F_83 ( V_102 ) ;
if ( V_38 )
goto error;
}
if ( V_2 -> V_15 ) {
F_81 ( & V_4 -> V_4 , L_10 ) ;
V_38 = - V_118 ;
goto error;
}
V_2 -> V_15 = V_4 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_101 = V_45 ;
V_2 -> V_67 = V_67 ;
V_2 -> V_23 = V_119 ;
F_84 ( V_2 -> V_15 ) ;
V_38 = F_20 ( V_2 ) ;
if ( V_38 )
F_71 ( V_2 ) ;
else
F_17 ( V_2 ) ;
return V_38 ;
error:
F_2 ( V_102 ) ;
F_85 ( V_52 -> V_113 ) ;
return V_38 ;
}
struct V_1 * F_86 ( struct V_13 * V_4 , const char * V_25 ,
T_3 V_67 )
{
struct V_120 * V_52 = & V_56 ;
struct V_1 * V_2 ;
struct V_7 * V_102 ;
int V_100 ;
V_102 = F_68 ( V_52 , NULL , V_25 ) ;
if ( ! V_102 ) {
F_56 ( L_7 , V_25 ) ;
return F_37 ( - V_91 ) ;
}
V_2 = F_7 ( V_102 ) ;
V_100 = F_65 ( V_4 , V_2 , V_2 -> V_101 , V_67 ) ;
if ( V_100 )
return F_37 ( V_100 ) ;
return V_2 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
int V_43 ;
V_2 -> V_15 -> V_2 = NULL ;
V_2 -> V_15 = NULL ;
F_15 ( V_2 ) ;
for ( V_43 = 0 ; V_43 < F_35 ( V_114 ) ; V_43 ++ ) {
if ( V_2 -> V_3 . V_4 . V_10 ==
& V_114 [ V_43 ] . V_44 . V_10 ) {
F_87 ( & V_2 -> V_3 . V_4 ) ;
break;
}
}
V_52 = V_2 -> V_3 . V_52 ;
F_2 ( & V_2 -> V_3 . V_4 ) ;
F_85 ( V_52 -> V_113 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_11 ( V_2 -> V_3 . V_4 . V_10 ) ;
struct V_121 V_122 = { . V_123 = V_124 } ;
int V_20 = 0 ;
F_88 ( V_2 , & V_122 ) ;
if ( V_122 . V_125 )
return - V_118 ;
if ( V_12 -> V_16 )
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
if ( V_12 -> V_126 )
V_20 = V_12 -> V_126 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_17 = false ;
return V_20 ;
}
static int F_89 ( struct V_1 * V_2 )
{
T_1 V_127 ;
int V_128 , V_129 , V_130 ;
int V_38 , V_131 = 0 ;
V_2 -> V_132 &= V_2 -> V_133 ;
V_127 = V_2 -> V_132 ;
V_129 = F_74 ( V_2 , V_134 ) ;
if ( V_129 < 0 )
return V_129 ;
V_128 = V_129 ;
V_129 &= ~ ( V_135 | V_136 | V_137 |
V_138 ) ;
V_129 |= F_90 ( V_127 ) ;
if ( V_129 != V_128 ) {
V_38 = F_91 ( V_2 , V_134 , V_129 ) ;
if ( V_38 < 0 )
return V_38 ;
V_131 = 1 ;
}
V_130 = F_74 ( V_2 , V_139 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( ! ( V_130 & V_140 ) )
return V_131 ;
V_129 = F_74 ( V_2 , V_141 ) ;
if ( V_129 < 0 )
return V_129 ;
V_128 = V_129 ;
V_129 &= ~ ( V_142 | V_143 ) ;
if ( V_2 -> V_133 & ( V_144 |
V_145 ) ) {
V_129 |= F_92 ( V_127 ) ;
}
if ( V_129 != V_128 )
V_131 = 1 ;
V_38 = F_91 ( V_2 , V_141 , V_129 ) ;
if ( V_38 < 0 )
return V_38 ;
return V_131 ;
}
int F_93 ( struct V_1 * V_2 )
{
int V_146 = F_74 ( V_2 , V_104 ) ;
V_146 &= V_147 | V_148 | V_149 ;
V_2 -> V_65 = 0 ;
V_2 -> V_66 = 0 ;
if ( V_150 == V_2 -> V_63 )
V_146 |= V_151 ;
else if ( V_152 == V_2 -> V_63 )
V_146 |= V_153 ;
if ( V_154 == V_2 -> V_64 )
V_146 |= V_155 ;
return F_91 ( V_2 , V_104 , V_146 ) ;
}
int F_94 ( struct V_1 * V_2 )
{
int V_146 = F_74 ( V_2 , V_104 ) ;
if ( V_146 < 0 )
return V_146 ;
V_146 |= V_156 | V_157 ;
V_146 &= ~ V_148 ;
return F_91 ( V_2 , V_104 , V_146 ) ;
}
int F_95 ( struct V_1 * V_2 )
{
int V_158 ;
if ( V_70 != V_2 -> V_69 )
return F_93 ( V_2 ) ;
V_158 = F_89 ( V_2 ) ;
if ( V_158 < 0 )
return V_158 ;
if ( V_158 == 0 ) {
int V_146 = F_74 ( V_2 , V_104 ) ;
if ( V_146 < 0 )
return V_146 ;
if ( ! ( V_146 & V_156 ) || ( V_146 & V_148 ) )
V_158 = 1 ;
}
if ( V_158 > 0 )
V_158 = F_94 ( V_2 ) ;
return V_158 ;
}
int F_96 ( struct V_1 * V_2 )
{
int V_159 = F_74 ( V_2 , V_139 ) ;
return ( V_159 < 0 ) ? V_159 : ( V_159 & V_160 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_98 ( struct V_1 * V_2 )
{
int V_161 ;
V_161 = F_74 ( V_2 , V_139 ) ;
if ( V_161 < 0 )
return V_161 ;
V_161 = F_74 ( V_2 , V_139 ) ;
if ( V_161 < 0 )
return V_161 ;
if ( ( V_161 & V_162 ) == 0 )
V_2 -> V_22 = 0 ;
else
V_2 -> V_22 = 1 ;
return 0 ;
}
int F_99 ( struct V_1 * V_2 )
{
int V_129 ;
int V_38 ;
int V_163 ;
int V_164 = 0 ;
int V_165 ;
int V_166 = 0 ;
V_38 = F_98 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_167 = 0 ;
if ( V_70 == V_2 -> V_69 ) {
if ( V_2 -> V_133 & ( V_144
| V_145 ) ) {
V_164 = F_74 ( V_2 , V_168 ) ;
if ( V_164 < 0 )
return V_164 ;
V_129 = F_74 ( V_2 , V_141 ) ;
if ( V_129 < 0 )
return V_129 ;
V_2 -> V_167 =
F_100 ( V_164 ) ;
V_166 = V_164 & V_129 << 2 ;
}
V_163 = F_74 ( V_2 , V_169 ) ;
if ( V_163 < 0 )
return V_163 ;
V_2 -> V_167 |= F_101 ( V_163 ) ;
V_129 = F_74 ( V_2 , V_134 ) ;
if ( V_129 < 0 )
return V_129 ;
V_165 = V_163 & V_129 ;
V_2 -> V_63 = V_170 ;
V_2 -> V_64 = V_171 ;
V_2 -> V_65 = 0 ;
V_2 -> V_66 = 0 ;
if ( V_166 & ( V_172 | V_173 ) ) {
V_2 -> V_63 = V_150 ;
if ( V_166 & V_172 )
V_2 -> V_64 = V_154 ;
} else if ( V_165 & ( V_174 | V_175 ) ) {
V_2 -> V_63 = V_152 ;
if ( V_165 & V_174 )
V_2 -> V_64 = V_154 ;
} else
if ( V_165 & V_176 )
V_2 -> V_64 = V_154 ;
if ( V_2 -> V_64 == V_154 ) {
V_2 -> V_65 = V_163 & V_177 ? 1 : 0 ;
V_2 -> V_66 = V_163 & V_178 ? 1 : 0 ;
}
} else {
int V_179 = F_74 ( V_2 , V_104 ) ;
if ( V_179 < 0 )
return V_179 ;
if ( V_179 & V_155 )
V_2 -> V_64 = V_154 ;
else
V_2 -> V_64 = V_171 ;
if ( V_179 & V_151 )
V_2 -> V_63 = V_150 ;
else if ( V_179 & V_153 )
V_2 -> V_63 = V_152 ;
else
V_2 -> V_63 = V_170 ;
V_2 -> V_65 = 0 ;
V_2 -> V_66 = 0 ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_180 , V_181 ;
T_1 V_182 = V_2 -> V_41 . V_49 ;
V_2 -> V_22 = 1 ;
V_2 -> V_63 = V_183 ;
V_2 -> V_64 = V_154 ;
for ( V_180 = 0 ; V_182 ; V_180 ++ , V_182 = V_182 >> 1 ) {
if ( ! ( V_182 & 1 ) )
continue;
F_103 ( V_2 , V_180 , V_184 ) ;
V_181 = F_103 ( V_2 , V_180 , V_184 ) ;
if ( V_181 < 0 || ! ( V_181 & V_185 ) )
V_2 -> V_22 = 0 ;
}
return 0 ;
}
int F_75 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_91 ( V_2 , V_104 , V_105 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_72 ( V_2 ) ;
}
int F_104 ( struct V_1 * V_2 )
{
int V_186 ;
T_1 V_187 ;
V_187 = ( V_188 | V_189
| V_190 | V_191 |
V_192 | V_193 | V_194 ) ;
V_186 = F_74 ( V_2 , V_139 ) ;
if ( V_186 < 0 )
return V_186 ;
if ( V_186 & V_195 )
V_187 |= V_196 ;
if ( V_186 & V_197 )
V_187 |= V_198 ;
if ( V_186 & V_199 )
V_187 |= V_200 ;
if ( V_186 & V_201 )
V_187 |= V_202 ;
if ( V_186 & V_203 )
V_187 |= V_204 ;
if ( V_186 & V_140 ) {
V_186 = F_74 ( V_2 , V_205 ) ;
if ( V_186 < 0 )
return V_186 ;
if ( V_186 & V_206 )
V_187 |= V_145 ;
if ( V_186 & V_207 )
V_187 |= V_144 ;
}
V_2 -> V_133 &= V_187 ;
V_2 -> V_132 &= V_187 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_106 ( struct V_1 * V_2 )
{
V_2 -> V_133 = V_208 ;
V_2 -> V_132 = V_208 ;
return 0 ;
}
int F_107 ( struct V_1 * V_2 )
{
int V_209 ;
F_25 ( & V_2 -> V_75 ) ;
V_209 = F_74 ( V_2 , V_104 ) ;
F_91 ( V_2 , V_104 , V_209 | V_149 ) ;
F_27 ( & V_2 -> V_75 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_109 ( struct V_1 * V_2 )
{
int V_209 ;
F_25 ( & V_2 -> V_75 ) ;
V_209 = F_74 ( V_2 , V_104 ) ;
F_91 ( V_2 , V_104 , V_209 & ~ V_149 ) ;
F_27 ( & V_2 -> V_75 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , T_1 V_210 )
{
V_2 -> V_133 &= V_211 ;
switch ( V_210 ) {
default:
return - V_212 ;
case V_150 :
V_2 -> V_133 |= V_213 ;
case V_152 :
V_2 -> V_133 |= V_214 ;
case V_170 :
V_2 -> V_133 |= V_215 ;
}
return 0 ;
}
int F_112 ( struct V_1 * V_2 , T_1 V_210 )
{
int V_38 ;
V_38 = F_111 ( V_2 , V_210 ) ;
if ( V_38 )
return V_38 ;
V_2 -> V_132 = V_2 -> V_133 ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_216 * V_217 = V_2 -> V_3 . V_4 . V_218 ;
T_1 V_210 ;
if ( ! F_114 ( V_219 ) )
return;
if ( ! V_217 )
return;
if ( ! F_115 ( V_217 , L_11 , & V_210 ) )
F_111 ( V_2 , V_210 ) ;
}
static int F_116 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_8 * V_9 = V_2 -> V_3 . V_4 . V_10 ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
int V_38 = 0 ;
V_2 -> V_9 = V_12 ;
if ( ! ( V_12 -> V_45 & V_220 ) &&
F_117 ( V_2 ) )
V_2 -> V_71 = V_221 ;
if ( V_12 -> V_45 & V_222 )
V_2 -> V_223 = true ;
F_25 ( & V_2 -> V_75 ) ;
V_2 -> V_133 = V_12 -> V_187 ;
F_113 ( V_2 ) ;
V_2 -> V_132 = V_2 -> V_133 ;
V_2 -> V_23 = V_119 ;
if ( V_2 -> V_9 -> V_117 )
V_38 = V_2 -> V_9 -> V_117 ( V_2 ) ;
F_27 ( & V_2 -> V_75 ) ;
return V_38 ;
}
static int F_118 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
F_25 ( & V_2 -> V_75 ) ;
V_2 -> V_23 = V_74 ;
F_27 ( & V_2 -> V_75 ) ;
if ( V_2 -> V_9 -> remove )
V_2 -> V_9 -> remove ( V_2 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
int F_119 ( struct V_11 * V_224 , struct V_225 * V_113 )
{
int V_159 ;
V_224 -> V_44 . V_45 |= V_46 ;
V_224 -> V_44 . V_10 . V_111 = V_224 -> V_111 ;
V_224 -> V_44 . V_10 . V_52 = & V_56 ;
V_224 -> V_44 . V_10 . V_117 = F_116 ;
V_224 -> V_44 . V_10 . remove = F_118 ;
V_224 -> V_44 . V_10 . V_113 = V_113 ;
V_159 = F_120 ( & V_224 -> V_44 . V_10 ) ;
if ( V_159 ) {
F_56 ( L_12 ,
V_224 -> V_111 , V_159 ) ;
return V_159 ;
}
F_121 ( L_13 , V_224 -> V_111 ) ;
return 0 ;
}
int F_122 ( struct V_11 * V_224 , int V_226 ,
struct V_225 * V_113 )
{
int V_43 , V_20 = 0 ;
for ( V_43 = 0 ; V_43 < V_226 ; V_43 ++ ) {
V_20 = F_119 ( V_224 + V_43 , V_113 ) ;
if ( V_20 ) {
while ( V_43 -- > 0 )
F_123 ( V_224 + V_43 ) ;
break;
}
}
return V_20 ;
}
void F_123 ( struct V_11 * V_9 )
{
F_124 ( & V_9 -> V_44 . V_10 ) ;
}
void F_125 ( struct V_11 * V_9 , int V_226 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_226 ; V_43 ++ )
F_123 ( V_9 + V_43 ) ;
}
static int T_5 F_126 ( void )
{
int V_100 ;
V_100 = F_127 () ;
if ( V_100 )
return V_100 ;
V_100 = F_122 ( V_114 ,
F_35 ( V_114 ) , V_227 ) ;
if ( V_100 )
F_128 () ;
return V_100 ;
}
static void T_6 F_129 ( void )
{
F_125 ( V_114 ,
F_35 ( V_114 ) ) ;
F_128 () ;
}
