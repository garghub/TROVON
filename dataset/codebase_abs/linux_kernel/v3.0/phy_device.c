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
int F_24 ( struct V_19 * V_20 , int V_21 , T_1 * V_17 )
{
int V_43 ;
V_43 = V_20 -> V_44 ( V_20 , V_21 , V_45 ) ;
if ( V_43 < 0 )
return - V_46 ;
* V_17 = ( V_43 & 0xffff ) << 16 ;
V_43 = V_20 -> V_44 ( V_20 , V_21 , V_47 ) ;
if ( V_43 < 0 )
return - V_46 ;
* V_17 |= ( V_43 & 0xffff ) ;
return 0 ;
}
struct V_1 * F_25 ( struct V_19 * V_20 , int V_21 )
{
struct V_1 * V_4 = NULL ;
T_1 V_17 ;
int V_48 ;
V_48 = F_24 ( V_20 , V_21 , & V_17 ) ;
if ( V_48 )
return F_26 ( V_48 ) ;
if ( ( V_17 & 0x1fffffff ) == 0x1fffffff )
return NULL ;
V_4 = F_18 ( V_20 , V_21 , V_17 ) ;
return V_4 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_20 -> V_49 [ V_2 -> V_21 ] )
return - V_50 ;
V_2 -> V_20 -> V_49 [ V_2 -> V_21 ] = V_2 ;
F_16 ( V_2 ) ;
V_18 = F_28 ( & V_2 -> V_4 ) ;
if ( V_18 ) {
F_29 ( L_1 , V_2 -> V_21 ) ;
goto V_51;
}
return 0 ;
V_51:
V_2 -> V_20 -> V_49 [ V_2 -> V_21 ] = NULL ;
return V_18 ;
}
struct V_1 * F_30 ( struct V_19 * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_52 ; V_21 ++ ) {
if ( V_20 -> V_49 [ V_21 ] )
return V_20 -> V_49 [ V_21 ] ;
}
return NULL ;
}
static void F_31 ( struct V_1 * V_2 ,
void (* F_32)( struct V_53 * ) )
{
V_2 -> V_54 = F_32 ;
}
int F_33 ( struct V_53 * V_4 , struct V_1 * V_2 ,
void (* F_32)( struct V_53 * ) , T_1 V_55 ,
T_2 V_28 )
{
int V_56 ;
V_56 = F_34 ( V_4 , V_2 , V_55 , V_28 ) ;
if ( V_56 )
return V_56 ;
F_31 ( V_2 , F_32 ) ;
F_35 ( V_2 , NULL ) ;
if ( V_2 -> V_34 > 0 )
F_36 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_37 ( struct V_53 * V_4 , const char * V_5 ,
void (* F_32)( struct V_53 * ) , T_1 V_55 ,
T_2 V_28 )
{
struct V_1 * V_2 ;
struct V_3 * V_57 ;
int V_56 ;
V_57 = F_38 ( & V_33 , NULL , V_5 ) ;
if ( ! V_57 ) {
F_29 ( L_2 , V_5 ) ;
return F_26 ( - V_58 ) ;
}
V_2 = F_4 ( V_57 ) ;
V_56 = F_33 ( V_4 , V_2 , F_32 , V_55 , V_28 ) ;
if ( V_56 )
return F_26 ( V_56 ) ;
return V_2 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 > 0 )
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
V_2 -> V_54 = NULL ;
F_42 ( V_2 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
int V_59 ;
if ( ! V_2 -> V_60 || ! V_2 -> V_60 -> V_61 )
return 0 ;
V_59 = F_16 ( V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
return V_2 -> V_60 -> V_61 ( V_2 ) ;
}
static int F_34 ( struct V_53 * V_4 , struct V_1 * V_2 ,
T_1 V_55 , T_2 V_28 )
{
struct V_3 * V_57 = & V_2 -> V_4 ;
int V_18 ;
if ( NULL == V_57 -> V_62 ) {
V_57 -> V_62 = & V_63 . V_62 ;
V_18 = V_57 -> V_62 -> V_64 ( V_57 ) ;
if ( V_18 >= 0 )
V_18 = F_44 ( V_57 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_65 ) {
F_45 ( & V_4 -> V_4 , L_3 ) ;
return - V_66 ;
}
V_2 -> V_65 = V_4 ;
V_4 -> V_2 = V_2 ;
V_2 -> V_67 = V_55 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_38 = V_68 ;
V_18 = F_43 ( V_2 ) ;
if ( V_18 )
F_42 ( V_2 ) ;
return V_18 ;
}
struct V_1 * F_46 ( struct V_53 * V_4 ,
const char * V_5 , T_1 V_55 , T_2 V_28 )
{
struct V_69 * V_20 = & V_33 ;
struct V_1 * V_2 ;
struct V_3 * V_57 ;
int V_56 ;
V_57 = F_38 ( V_20 , NULL , V_5 ) ;
if ( ! V_57 ) {
F_29 ( L_2 , V_5 ) ;
return F_26 ( - V_58 ) ;
}
V_2 = F_4 ( V_57 ) ;
V_56 = F_34 ( V_4 , V_2 , V_55 , V_28 ) ;
if ( V_56 )
return F_26 ( V_56 ) ;
return V_2 ;
}
void F_42 ( struct V_1 * V_2 )
{
V_2 -> V_65 -> V_2 = NULL ;
V_2 -> V_65 = NULL ;
if ( V_2 -> V_4 . V_62 == & V_63 . V_62 )
F_47 ( & V_2 -> V_4 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
T_1 V_70 ;
int V_71 , V_72 ;
int V_18 , V_73 = 0 ;
V_2 -> V_74 &= V_2 -> V_75 ;
V_70 = V_2 -> V_74 ;
V_71 = V_72 = F_49 ( V_2 , V_76 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 &= ~ ( V_77 | V_78 | V_79 |
V_80 ) ;
if ( V_70 & V_81 )
V_72 |= V_82 ;
if ( V_70 & V_83 )
V_72 |= V_84 ;
if ( V_70 & V_85 )
V_72 |= V_86 ;
if ( V_70 & V_87 )
V_72 |= V_88 ;
if ( V_70 & V_89 )
V_72 |= V_79 ;
if ( V_70 & V_90 )
V_72 |= V_80 ;
if ( V_72 != V_71 ) {
V_18 = F_50 ( V_2 , V_76 , V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
V_73 = 1 ;
}
if ( V_2 -> V_75 & ( V_91 |
V_92 ) ) {
V_71 = V_72 = F_49 ( V_2 , V_93 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 &= ~ ( V_94 | V_95 ) ;
if ( V_70 & V_91 )
V_72 |= V_95 ;
if ( V_70 & V_92 )
V_72 |= V_94 ;
if ( V_72 != V_71 ) {
V_18 = F_50 ( V_2 , V_93 , V_72 ) ;
if ( V_18 < 0 )
return V_18 ;
V_73 = 1 ;
}
}
return V_73 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_18 ;
int V_96 = 0 ;
V_2 -> V_25 = V_2 -> V_26 = 0 ;
if ( V_97 == V_2 -> V_23 )
V_96 |= V_98 ;
else if ( V_99 == V_2 -> V_23 )
V_96 |= V_100 ;
if ( V_101 == V_2 -> V_24 )
V_96 |= V_102 ;
V_18 = F_50 ( V_2 , V_103 , V_96 ) ;
return V_18 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_96 ;
V_96 = F_49 ( V_2 , V_103 ) ;
if ( V_96 < 0 )
return V_96 ;
V_96 |= ( V_104 | V_105 ) ;
V_96 &= ~ ( V_106 ) ;
V_96 = F_50 ( V_2 , V_103 , V_96 ) ;
return V_96 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_107 ;
if ( V_31 != V_2 -> V_30 )
return F_51 ( V_2 ) ;
V_107 = F_48 ( V_2 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( V_107 == 0 ) {
int V_96 = F_49 ( V_2 , V_103 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! ( V_96 & V_104 ) || ( V_96 & V_106 ) )
V_107 = 1 ;
}
if ( V_107 > 0 )
V_107 = F_52 ( V_2 ) ;
return V_107 ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_108 ;
V_108 = F_49 ( V_2 , V_109 ) ;
if ( V_108 < 0 )
return V_108 ;
V_108 = F_49 ( V_2 , V_109 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( ( V_108 & V_110 ) == 0 )
V_2 -> V_27 = 0 ;
else
V_2 -> V_27 = 1 ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_72 ;
int V_18 ;
int V_111 ;
int V_112 = 0 ;
V_18 = F_54 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_31 == V_2 -> V_30 ) {
if ( V_2 -> V_75 & ( V_91
| V_92 ) ) {
V_112 = F_49 ( V_2 , V_113 ) ;
if ( V_112 < 0 )
return V_112 ;
V_72 = F_49 ( V_2 , V_93 ) ;
if ( V_72 < 0 )
return V_72 ;
V_112 &= V_72 << 2 ;
}
V_111 = F_49 ( V_2 , V_114 ) ;
if ( V_111 < 0 )
return V_111 ;
V_72 = F_49 ( V_2 , V_76 ) ;
if ( V_72 < 0 )
return V_72 ;
V_111 &= V_72 ;
V_2 -> V_23 = V_115 ;
V_2 -> V_24 = V_116 ;
V_2 -> V_25 = V_2 -> V_26 = 0 ;
if ( V_112 & ( V_117 | V_118 ) ) {
V_2 -> V_23 = V_97 ;
if ( V_112 & V_117 )
V_2 -> V_24 = V_101 ;
} else if ( V_111 & ( V_119 | V_120 ) ) {
V_2 -> V_23 = V_99 ;
if ( V_111 & V_119 )
V_2 -> V_24 = V_101 ;
} else
if ( V_111 & V_121 )
V_2 -> V_24 = V_101 ;
if ( V_2 -> V_24 == V_101 ) {
V_2 -> V_25 = V_111 & V_122 ? 1 : 0 ;
V_2 -> V_26 = V_111 & V_123 ? 1 : 0 ;
}
} else {
int V_124 = F_49 ( V_2 , V_103 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_124 & V_102 )
V_2 -> V_24 = V_101 ;
else
V_2 -> V_24 = V_116 ;
if ( V_124 & V_98 )
V_2 -> V_23 = V_97 ;
else if ( V_124 & V_100 )
V_2 -> V_23 = V_99 ;
else
V_2 -> V_23 = V_115 ;
V_2 -> V_25 = V_2 -> V_26 = 0 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_125 ;
T_1 V_126 ;
V_126 = ( V_127 | V_128
| V_129 | V_130 |
V_131 ) ;
V_125 = F_49 ( V_2 , V_109 ) ;
if ( V_125 < 0 )
return V_125 ;
if ( V_125 & V_132 )
V_126 |= V_133 ;
if ( V_125 & V_134 )
V_126 |= V_135 ;
if ( V_125 & V_136 )
V_126 |= V_137 ;
if ( V_125 & V_138 )
V_126 |= V_139 ;
if ( V_125 & V_140 )
V_126 |= V_141 ;
if ( V_125 & V_142 ) {
V_125 = F_49 ( V_2 , V_143 ) ;
if ( V_125 < 0 )
return V_125 ;
if ( V_125 & V_144 )
V_126 |= V_92 ;
if ( V_125 & V_145 )
V_126 |= V_91 ;
}
V_2 -> V_75 = V_126 ;
V_2 -> V_74 = V_126 ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 )
{
int V_146 ;
F_9 ( & V_2 -> V_40 ) ;
V_146 = F_49 ( V_2 , V_103 ) ;
F_50 ( V_2 , V_103 , ( V_146 | V_147 ) ) ;
F_11 ( & V_2 -> V_40 ) ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
int V_146 ;
F_9 ( & V_2 -> V_40 ) ;
V_146 = F_49 ( V_2 , V_103 ) ;
F_50 ( V_2 , V_103 , ( V_146 & ~ V_147 ) ) ;
F_11 ( & V_2 -> V_40 ) ;
return 0 ;
}
static int F_59 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_148 * V_149 ;
struct V_150 * V_60 ;
int V_18 = 0 ;
V_2 = F_4 ( V_4 ) ;
V_60 = F_60 ( V_2 -> V_4 . V_62 ) ;
V_149 = F_61 ( V_60 ) ;
V_2 -> V_60 = V_149 ;
if ( ! ( V_149 -> V_55 & V_151 ) )
V_2 -> V_34 = V_35 ;
F_9 ( & V_2 -> V_40 ) ;
V_2 -> V_75 = V_149 -> V_126 ;
V_2 -> V_74 = V_149 -> V_126 ;
V_2 -> V_38 = V_68 ;
if ( V_2 -> V_60 -> V_64 )
V_18 = V_2 -> V_60 -> V_64 ( V_2 ) ;
F_11 ( & V_2 -> V_40 ) ;
return V_18 ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_4 ) ;
F_9 ( & V_2 -> V_40 ) ;
V_2 -> V_38 = V_39 ;
F_11 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_60 -> remove )
V_2 -> V_60 -> remove ( V_2 ) ;
F_63 ( V_4 -> V_62 ) ;
V_2 -> V_60 = NULL ;
return 0 ;
}
int F_64 ( struct V_148 * V_152 )
{
int V_153 ;
V_152 -> V_62 . V_154 = V_152 -> V_154 ;
V_152 -> V_62 . V_20 = & V_33 ;
V_152 -> V_62 . V_64 = F_59 ;
V_152 -> V_62 . remove = F_62 ;
V_153 = F_65 ( & V_152 -> V_62 ) ;
if ( V_153 ) {
F_66 ( V_155 L_4 ,
V_152 -> V_154 , V_153 ) ;
return V_153 ;
}
F_67 ( L_5 , V_152 -> V_154 ) ;
return 0 ;
}
void F_68 ( struct V_148 * V_60 )
{
F_69 ( & V_60 -> V_62 ) ;
}
static int T_3 F_70 ( void )
{
int V_56 ;
V_56 = F_71 () ;
if ( V_56 )
return V_56 ;
V_56 = F_64 ( & V_63 ) ;
if ( V_56 )
F_72 () ;
return V_56 ;
}
static void T_4 F_73 ( void )
{
F_68 ( & V_63 ) ;
F_72 () ;
}
