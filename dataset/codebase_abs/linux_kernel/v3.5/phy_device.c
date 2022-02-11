void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
F_1 ( F_4 ( V_4 ) ) ;
}
int F_5 ( const char * V_5 , T_1 V_6 , T_1 V_7 ,
int (* F_6)( struct V_1 * ) )
{
struct V_8 * V_9 ;
V_9 = F_7 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
F_8 ( V_9 -> V_5 , V_5 , sizeof( V_9 -> V_5 ) ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_7 = V_7 ;
V_9 -> F_6 = F_6 ;
F_9 ( & V_12 ) ;
F_10 ( & V_9 -> V_13 , & V_14 ) ;
F_11 ( & V_12 ) ;
return 0 ;
}
int F_12 ( T_1 V_6 , T_1 V_7 ,
int (* F_6)( struct V_1 * ) )
{
return F_5 ( V_15 , V_6 , V_7 , F_6 ) ;
}
int F_13 ( const char * V_5 ,
int (* F_6)( struct V_1 * ) )
{
return F_5 ( V_5 , V_16 , 0xffffffff , F_6 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( strcmp ( V_9 -> V_5 , F_15 ( & V_2 -> V_4 ) ) != 0 )
if ( strcmp ( V_9 -> V_5 , V_15 ) != 0 )
return 0 ;
if ( ( V_9 -> V_6 & V_9 -> V_7 ) !=
( V_2 -> V_17 & V_9 -> V_7 ) )
if ( V_9 -> V_6 != V_16 )
return 0 ;
return 1 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_9 ( & V_12 ) ;
F_17 (fixup, &phy_fixup_list, list) {
if ( F_14 ( V_2 , V_9 ) ) {
int V_18 ;
V_18 = V_9 -> F_6 ( V_2 ) ;
if ( V_18 < 0 ) {
F_11 ( & V_12 ) ;
return V_18 ;
}
}
}
F_11 ( & V_12 ) ;
return 0 ;
}
static struct V_1 * F_18 ( struct V_19 * V_20 ,
int V_21 , int V_17 )
{
struct V_1 * V_4 ;
V_4 = F_7 ( sizeof( * V_4 ) , V_10 ) ;
if ( NULL == V_4 )
return (struct V_1 * ) F_19 ( ( void * ) - V_11 ) ;
V_4 -> V_4 . V_22 = F_3 ;
V_4 -> V_23 = 0 ;
V_4 -> V_24 = - 1 ;
V_4 -> V_25 = V_4 -> V_26 = 0 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = V_29 ;
V_4 -> V_30 = V_31 ;
V_4 -> V_21 = V_21 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_4 . V_32 = V_20 -> V_32 ;
V_4 -> V_4 . V_20 = & V_33 ;
V_4 -> V_34 = V_20 -> V_34 != NULL ? V_20 -> V_34 [ V_21 ] : V_35 ;
F_20 ( & V_4 -> V_4 , V_36 , V_20 -> V_37 , V_21 ) ;
V_4 -> V_38 = V_39 ;
F_21 ( & V_4 -> V_40 ) ;
F_22 ( & V_4 -> V_41 , V_42 ) ;
F_23 (MDIO_MODULE_PREFIX MDIO_ID_FMT, MDIO_ID_ARGS(phy_id)) ;
return V_4 ;
}
static int F_24 ( struct V_19 * V_20 , int V_21 , T_1 * V_17 )
{
int V_43 ;
V_43 = F_25 ( V_20 , V_21 , V_44 ) ;
if ( V_43 < 0 )
return - V_45 ;
* V_17 = ( V_43 & 0xffff ) << 16 ;
V_43 = F_25 ( V_20 , V_21 , V_46 ) ;
if ( V_43 < 0 )
return - V_45 ;
* V_17 |= ( V_43 & 0xffff ) ;
return 0 ;
}
struct V_1 * F_26 ( struct V_19 * V_20 , int V_21 )
{
struct V_1 * V_4 = NULL ;
T_1 V_17 ;
int V_47 ;
V_47 = F_24 ( V_20 , V_21 , & V_17 ) ;
if ( V_47 )
return F_27 ( V_47 ) ;
if ( ( V_17 & 0x1fffffff ) == 0x1fffffff )
return NULL ;
V_4 = F_18 ( V_20 , V_21 , V_17 ) ;
return V_4 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_20 -> V_48 [ V_2 -> V_21 ] )
return - V_49 ;
V_2 -> V_20 -> V_48 [ V_2 -> V_21 ] = V_2 ;
F_16 ( V_2 ) ;
V_18 = F_29 ( & V_2 -> V_4 ) ;
if ( V_18 ) {
F_30 ( L_1 , V_2 -> V_21 ) ;
goto V_50;
}
return 0 ;
V_50:
V_2 -> V_20 -> V_48 [ V_2 -> V_21 ] = NULL ;
return V_18 ;
}
struct V_1 * F_31 ( struct V_19 * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_51 ; V_21 ++ ) {
if ( V_20 -> V_48 [ V_21 ] )
return V_20 -> V_48 [ V_21 ] ;
}
return NULL ;
}
static void F_32 ( struct V_1 * V_2 ,
void (* F_33)( struct V_52 * ) )
{
V_2 -> V_53 = F_33 ;
}
int F_34 ( struct V_52 * V_4 , struct V_1 * V_2 ,
void (* F_33)( struct V_52 * ) , T_1 V_54 ,
T_2 V_28 )
{
int V_55 ;
V_55 = F_35 ( V_4 , V_2 , V_54 , V_28 ) ;
if ( V_55 )
return V_55 ;
F_32 ( V_2 , F_33 ) ;
F_36 ( V_2 , NULL ) ;
if ( V_2 -> V_34 > 0 )
F_37 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_38 ( struct V_52 * V_4 , const char * V_5 ,
void (* F_33)( struct V_52 * ) , T_1 V_54 ,
T_2 V_28 )
{
struct V_1 * V_2 ;
struct V_3 * V_56 ;
int V_55 ;
V_56 = F_39 ( & V_33 , NULL , V_5 ) ;
if ( ! V_56 ) {
F_30 ( L_2 , V_5 ) ;
return F_27 ( - V_57 ) ;
}
V_2 = F_4 ( V_56 ) ;
V_55 = F_34 ( V_4 , V_2 , F_33 , V_54 , V_28 ) ;
if ( V_55 )
return F_27 ( V_55 ) ;
return V_2 ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 > 0 )
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
V_2 -> V_53 = NULL ;
F_43 ( V_2 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_58 ;
if ( ! V_2 -> V_59 || ! V_2 -> V_59 -> V_60 )
return 0 ;
V_58 = F_16 ( V_2 ) ;
if ( V_58 < 0 )
return V_58 ;
return V_2 -> V_59 -> V_60 ( V_2 ) ;
}
static int F_35 ( struct V_52 * V_4 , struct V_1 * V_2 ,
T_1 V_54 , T_2 V_28 )
{
struct V_3 * V_56 = & V_2 -> V_4 ;
int V_18 ;
if ( NULL == V_56 -> V_61 ) {
V_56 -> V_61 = & V_62 . V_61 ;
V_18 = V_56 -> V_61 -> V_63 ( V_56 ) ;
if ( V_18 >= 0 )
V_18 = F_45 ( V_56 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_64 ) {
F_46 ( & V_4 -> V_4 , L_3 ) ;
return - V_65 ;
}
V_2 -> V_64 = V_4 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_66 = V_54 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_38 = V_67 ;
V_18 = F_44 ( V_2 ) ;
if ( V_18 )
F_43 ( V_2 ) ;
return V_18 ;
}
struct V_1 * F_47 ( struct V_52 * V_4 ,
const char * V_5 , T_1 V_54 , T_2 V_28 )
{
struct V_68 * V_20 = & V_33 ;
struct V_1 * V_2 ;
struct V_3 * V_56 ;
int V_55 ;
V_56 = F_39 ( V_20 , NULL , V_5 ) ;
if ( ! V_56 ) {
F_30 ( L_2 , V_5 ) ;
return F_27 ( - V_57 ) ;
}
V_2 = F_4 ( V_56 ) ;
V_55 = F_35 ( V_4 , V_2 , V_54 , V_28 ) ;
if ( V_55 )
return F_27 ( V_55 ) ;
return V_2 ;
}
void F_43 ( struct V_1 * V_2 )
{
V_2 -> V_64 -> V_2 = NULL ;
V_2 -> V_64 = NULL ;
if ( V_2 -> V_4 . V_61 == & V_62 . V_61 )
F_48 ( & V_2 -> V_4 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
T_1 V_69 ;
int V_70 , V_71 ;
int V_18 , V_72 = 0 ;
V_2 -> V_73 &= V_2 -> V_74 ;
V_69 = V_2 -> V_73 ;
V_70 = V_71 = F_50 ( V_2 , V_75 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 &= ~ ( V_76 | V_77 | V_78 |
V_79 ) ;
V_71 |= F_51 ( V_69 ) ;
if ( V_71 != V_70 ) {
V_18 = F_52 ( V_2 , V_75 , V_71 ) ;
if ( V_18 < 0 )
return V_18 ;
V_72 = 1 ;
}
if ( V_2 -> V_74 & ( V_80 |
V_81 ) ) {
V_70 = V_71 = F_50 ( V_2 , V_82 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 &= ~ ( V_83 | V_84 ) ;
V_71 |= F_53 ( V_69 ) ;
if ( V_71 != V_70 ) {
V_18 = F_52 ( V_2 , V_82 , V_71 ) ;
if ( V_18 < 0 )
return V_18 ;
V_72 = 1 ;
}
}
return V_72 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_18 ;
int V_85 = 0 ;
V_2 -> V_25 = V_2 -> V_26 = 0 ;
if ( V_86 == V_2 -> V_23 )
V_85 |= V_87 ;
else if ( V_88 == V_2 -> V_23 )
V_85 |= V_89 ;
if ( V_90 == V_2 -> V_24 )
V_85 |= V_91 ;
V_18 = F_52 ( V_2 , V_92 , V_85 ) ;
return V_18 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_85 ;
V_85 = F_50 ( V_2 , V_92 ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 |= ( V_93 | V_94 ) ;
V_85 &= ~ ( V_95 ) ;
V_85 = F_52 ( V_2 , V_92 , V_85 ) ;
return V_85 ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_96 ;
if ( V_31 != V_2 -> V_30 )
return F_54 ( V_2 ) ;
V_96 = F_49 ( V_2 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_96 == 0 ) {
int V_85 = F_50 ( V_2 , V_92 ) ;
if ( V_85 < 0 )
return V_85 ;
if ( ! ( V_85 & V_93 ) || ( V_85 & V_95 ) )
V_96 = 1 ;
}
if ( V_96 > 0 )
V_96 = F_55 ( V_2 ) ;
return V_96 ;
}
int F_57 ( struct V_1 * V_2 )
{
int V_97 ;
V_97 = F_50 ( V_2 , V_98 ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_50 ( V_2 , V_98 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( ( V_97 & V_99 ) == 0 )
V_2 -> V_27 = 0 ;
else
V_2 -> V_27 = 1 ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
int V_71 ;
int V_18 ;
int V_100 ;
int V_101 = 0 ;
V_18 = F_57 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_31 == V_2 -> V_30 ) {
if ( V_2 -> V_74 & ( V_80
| V_81 ) ) {
V_101 = F_50 ( V_2 , V_102 ) ;
if ( V_101 < 0 )
return V_101 ;
V_71 = F_50 ( V_2 , V_82 ) ;
if ( V_71 < 0 )
return V_71 ;
V_101 &= V_71 << 2 ;
}
V_100 = F_50 ( V_2 , V_103 ) ;
if ( V_100 < 0 )
return V_100 ;
V_71 = F_50 ( V_2 , V_75 ) ;
if ( V_71 < 0 )
return V_71 ;
V_100 &= V_71 ;
V_2 -> V_23 = V_104 ;
V_2 -> V_24 = V_105 ;
V_2 -> V_25 = V_2 -> V_26 = 0 ;
if ( V_101 & ( V_106 | V_107 ) ) {
V_2 -> V_23 = V_86 ;
if ( V_101 & V_106 )
V_2 -> V_24 = V_90 ;
} else if ( V_100 & ( V_108 | V_109 ) ) {
V_2 -> V_23 = V_88 ;
if ( V_100 & V_108 )
V_2 -> V_24 = V_90 ;
} else
if ( V_100 & V_110 )
V_2 -> V_24 = V_90 ;
if ( V_2 -> V_24 == V_90 ) {
V_2 -> V_25 = V_100 & V_111 ? 1 : 0 ;
V_2 -> V_26 = V_100 & V_112 ? 1 : 0 ;
}
} else {
int V_113 = F_50 ( V_2 , V_92 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_113 & V_91 )
V_2 -> V_24 = V_90 ;
else
V_2 -> V_24 = V_105 ;
if ( V_113 & V_87 )
V_2 -> V_23 = V_86 ;
else if ( V_113 & V_89 )
V_2 -> V_23 = V_88 ;
else
V_2 -> V_23 = V_104 ;
V_2 -> V_25 = V_2 -> V_26 = 0 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_114 ;
T_1 V_115 ;
V_115 = ( V_116 | V_117
| V_118 | V_119 |
V_120 ) ;
V_114 = F_50 ( V_2 , V_98 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( V_114 & V_121 )
V_115 |= V_122 ;
if ( V_114 & V_123 )
V_115 |= V_124 ;
if ( V_114 & V_125 )
V_115 |= V_126 ;
if ( V_114 & V_127 )
V_115 |= V_128 ;
if ( V_114 & V_129 )
V_115 |= V_130 ;
if ( V_114 & V_131 ) {
V_114 = F_50 ( V_2 , V_132 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( V_114 & V_133 )
V_115 |= V_81 ;
if ( V_114 & V_134 )
V_115 |= V_80 ;
}
V_2 -> V_74 = V_115 ;
V_2 -> V_73 = V_115 ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_135 ;
F_9 ( & V_2 -> V_40 ) ;
V_135 = F_50 ( V_2 , V_92 ) ;
F_52 ( V_2 , V_92 , ( V_135 | V_136 ) ) ;
F_11 ( & V_2 -> V_40 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_135 ;
F_9 ( & V_2 -> V_40 ) ;
V_135 = F_50 ( V_2 , V_92 ) ;
F_52 ( V_2 , V_92 , ( V_135 & ~ V_136 ) ) ;
F_11 ( & V_2 -> V_40 ) ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_137 * V_138 ;
struct V_139 * V_59 ;
int V_18 = 0 ;
V_2 = F_4 ( V_4 ) ;
V_59 = V_2 -> V_4 . V_61 ;
V_138 = F_63 ( V_59 ) ;
V_2 -> V_59 = V_138 ;
if ( ! ( V_138 -> V_54 & V_140 ) )
V_2 -> V_34 = V_35 ;
F_9 ( & V_2 -> V_40 ) ;
V_2 -> V_74 = V_138 -> V_115 ;
V_2 -> V_73 = V_138 -> V_115 ;
V_2 -> V_38 = V_67 ;
if ( V_2 -> V_59 -> V_63 )
V_18 = V_2 -> V_59 -> V_63 ( V_2 ) ;
F_11 ( & V_2 -> V_40 ) ;
return V_18 ;
}
static int F_64 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_4 ) ;
F_9 ( & V_2 -> V_40 ) ;
V_2 -> V_38 = V_39 ;
F_11 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_59 -> remove )
V_2 -> V_59 -> remove ( V_2 ) ;
V_2 -> V_59 = NULL ;
return 0 ;
}
int F_65 ( struct V_137 * V_141 )
{
int V_142 ;
V_141 -> V_61 . V_143 = V_141 -> V_143 ;
V_141 -> V_61 . V_20 = & V_33 ;
V_141 -> V_61 . V_63 = F_62 ;
V_141 -> V_61 . remove = F_64 ;
V_142 = F_66 ( & V_141 -> V_61 ) ;
if ( V_142 ) {
F_67 ( V_144 L_4 ,
V_141 -> V_143 , V_142 ) ;
return V_142 ;
}
F_68 ( L_5 , V_141 -> V_143 ) ;
return 0 ;
}
void F_69 ( struct V_137 * V_59 )
{
F_70 ( & V_59 -> V_61 ) ;
}
static int T_3 F_71 ( void )
{
int V_55 ;
V_55 = F_72 () ;
if ( V_55 )
return V_55 ;
V_55 = F_65 ( & V_62 ) ;
if ( V_55 )
F_73 () ;
return V_55 ;
}
static void T_4 F_74 ( void )
{
F_69 ( & V_62 ) ;
F_73 () ;
}
