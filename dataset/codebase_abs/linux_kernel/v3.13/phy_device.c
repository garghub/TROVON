void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_4 * V_3 )
{
F_4 ( F_5 ( V_3 ) ) ;
}
int F_6 ( const char * V_5 , T_1 V_6 , T_1 V_7 ,
int (* F_7)( struct V_1 * ) )
{
struct V_8 * V_9 ;
V_9 = F_8 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
F_9 ( V_9 -> V_5 , V_5 , sizeof( V_9 -> V_5 ) ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_7 = V_7 ;
V_9 -> F_7 = F_7 ;
F_10 ( & V_12 ) ;
F_11 ( & V_9 -> V_13 , & V_14 ) ;
F_12 ( & V_12 ) ;
return 0 ;
}
int F_13 ( T_1 V_6 , T_1 V_7 ,
int (* F_7)( struct V_1 * ) )
{
return F_6 ( V_15 , V_6 , V_7 , F_7 ) ;
}
int F_14 ( const char * V_5 ,
int (* F_7)( struct V_1 * ) )
{
return F_6 ( V_5 , V_16 , 0xffffffff , F_7 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( strcmp ( V_9 -> V_5 , F_16 ( & V_2 -> V_3 ) ) != 0 )
if ( strcmp ( V_9 -> V_5 , V_15 ) != 0 )
return 0 ;
if ( ( V_9 -> V_6 & V_9 -> V_7 ) !=
( V_2 -> V_17 & V_9 -> V_7 ) )
if ( V_9 -> V_6 != V_16 )
return 0 ;
return 1 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_10 ( & V_12 ) ;
F_18 (fixup, &phy_fixup_list, list) {
if ( F_15 ( V_2 , V_9 ) ) {
int V_18 ;
V_18 = V_9 -> F_7 ( V_2 ) ;
if ( V_18 < 0 ) {
F_12 ( & V_12 ) ;
return V_18 ;
}
}
}
F_12 ( & V_12 ) ;
return 0 ;
}
struct V_1 * F_19 ( struct V_19 * V_20 , int V_21 , int V_17 ,
bool V_22 , struct V_23 * V_24 )
{
struct V_1 * V_3 ;
V_3 = F_8 ( sizeof( * V_3 ) , V_10 ) ;
if ( NULL == V_3 )
return (struct V_1 * ) F_20 ( ( void * ) - V_11 ) ;
V_3 -> V_3 . V_25 = F_3 ;
V_3 -> V_26 = 0 ;
V_3 -> V_27 = - 1 ;
V_3 -> V_28 = V_3 -> V_29 = 0 ;
V_3 -> V_30 = 1 ;
V_3 -> V_31 = V_32 ;
V_3 -> V_33 = V_34 ;
V_3 -> V_22 = V_22 ;
V_3 -> V_21 = V_21 ;
V_3 -> V_17 = V_17 ;
if ( V_24 )
V_3 -> V_24 = * V_24 ;
V_3 -> V_20 = V_20 ;
V_3 -> V_3 . V_35 = V_20 -> V_35 ;
V_3 -> V_3 . V_20 = & V_36 ;
V_3 -> V_37 = V_20 -> V_37 != NULL ? V_20 -> V_37 [ V_21 ] : V_38 ;
F_21 ( & V_3 -> V_3 , V_39 , V_20 -> V_40 , V_21 ) ;
V_3 -> V_41 = V_42 ;
F_22 ( & V_3 -> V_43 ) ;
F_23 ( & V_3 -> V_44 , V_45 ) ;
F_24 ( & V_3 -> V_46 , V_47 ) ;
F_25 (MDIO_MODULE_PREFIX MDIO_ID_FMT, MDIO_ID_ARGS(phy_id)) ;
F_26 ( & V_3 -> V_3 ) ;
return V_3 ;
}
static int F_27 ( struct V_19 * V_20 , int V_21 , T_1 * V_17 ,
struct V_23 * V_24 ) {
int V_48 ;
int V_49 , V_50 ;
const int V_51 = F_28 ( V_24 -> V_52 ) ;
for ( V_49 = 1 ;
V_49 < V_51 && V_24 -> V_53 == 0 ;
V_49 ++ ) {
V_50 = V_54 | V_49 << 16 | 6 ;
V_48 = F_29 ( V_20 , V_21 , V_50 ) ;
if ( V_48 < 0 )
return - V_55 ;
V_24 -> V_53 = ( V_48 & 0xffff ) << 16 ;
V_50 = V_54 | V_49 << 16 | 5 ;
V_48 = F_29 ( V_20 , V_21 , V_50 ) ;
if ( V_48 < 0 )
return - V_55 ;
V_24 -> V_53 |= ( V_48 & 0xffff ) ;
if ( ( V_24 -> V_53 & 0x1fffffff ) == 0x1fffffff ) {
* V_17 = 0xffffffff ;
return 0 ;
}
}
for ( V_49 = 1 ; V_49 < V_51 ; V_49 ++ ) {
if ( ! ( V_24 -> V_53 & ( 1 << V_49 ) ) )
continue;
V_50 = V_54 | V_49 << 16 | V_56 ;
V_48 = F_29 ( V_20 , V_21 , V_50 ) ;
if ( V_48 < 0 )
return - V_55 ;
V_24 -> V_52 [ V_49 ] = ( V_48 & 0xffff ) << 16 ;
V_50 = V_54 | V_49 << 16 | V_57 ;
V_48 = F_29 ( V_20 , V_21 , V_50 ) ;
if ( V_48 < 0 )
return - V_55 ;
V_24 -> V_52 [ V_49 ] |= ( V_48 & 0xffff ) ;
}
* V_17 = 0 ;
return 0 ;
}
static int F_30 ( struct V_19 * V_20 , int V_21 , T_1 * V_17 ,
bool V_22 , struct V_23 * V_24 )
{
int V_48 ;
if ( V_22 )
return F_27 ( V_20 , V_21 , V_17 , V_24 ) ;
V_48 = F_29 ( V_20 , V_21 , V_56 ) ;
if ( V_48 < 0 )
return - V_55 ;
* V_17 = ( V_48 & 0xffff ) << 16 ;
V_48 = F_29 ( V_20 , V_21 , V_57 ) ;
if ( V_48 < 0 )
return - V_55 ;
* V_17 |= ( V_48 & 0xffff ) ;
return 0 ;
}
struct V_1 * F_31 ( struct V_19 * V_20 , int V_21 , bool V_22 )
{
struct V_23 V_24 = { 0 } ;
struct V_1 * V_3 = NULL ;
T_1 V_17 = 0 ;
int V_58 ;
V_58 = F_30 ( V_20 , V_21 , & V_17 , V_22 , & V_24 ) ;
if ( V_58 )
return F_32 ( V_58 ) ;
if ( ( V_17 & 0x1fffffff ) == 0x1fffffff )
return NULL ;
V_3 = F_19 ( V_20 , V_21 , V_17 , V_22 , & V_24 ) ;
return V_3 ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_20 -> V_59 [ V_2 -> V_21 ] )
return - V_60 ;
V_2 -> V_20 -> V_59 [ V_2 -> V_21 ] = V_2 ;
F_17 ( V_2 ) ;
V_18 = F_34 ( & V_2 -> V_3 ) ;
if ( V_18 ) {
F_35 ( L_1 , V_2 -> V_21 ) ;
goto V_61;
}
return 0 ;
V_61:
V_2 -> V_20 -> V_59 [ V_2 -> V_21 ] = NULL ;
return V_18 ;
}
struct V_1 * F_36 ( struct V_19 * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_62 ; V_21 ++ ) {
if ( V_20 -> V_59 [ V_21 ] )
return V_20 -> V_59 [ V_21 ] ;
}
return NULL ;
}
static void F_37 ( struct V_1 * V_2 ,
void (* F_38)( struct V_63 * ) )
{
V_2 -> V_64 = F_38 ;
}
int F_39 ( struct V_63 * V_3 , struct V_1 * V_2 ,
void (* F_38)( struct V_63 * ) ,
T_2 V_31 )
{
int V_65 ;
V_65 = F_40 ( V_3 , V_2 , V_2 -> V_66 , V_31 ) ;
if ( V_65 )
return V_65 ;
F_37 ( V_2 , F_38 ) ;
F_41 ( V_2 , NULL ) ;
if ( V_2 -> V_37 > 0 )
F_42 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_43 ( struct V_63 * V_3 , const char * V_5 ,
void (* F_38)( struct V_63 * ) ,
T_2 V_31 )
{
struct V_1 * V_2 ;
struct V_4 * V_67 ;
int V_65 ;
V_67 = F_44 ( & V_36 , NULL , V_5 ) ;
if ( ! V_67 ) {
F_35 ( L_2 , V_5 ) ;
return F_32 ( - V_68 ) ;
}
V_2 = F_5 ( V_67 ) ;
V_65 = F_39 ( V_3 , V_2 , F_38 , V_31 ) ;
if ( V_65 )
return F_32 ( V_65 ) ;
return V_2 ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 > 0 )
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
V_2 -> V_64 = NULL ;
F_48 ( V_2 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
int V_69 ;
if ( ! V_2 -> V_70 || ! V_2 -> V_70 -> V_71 )
return 0 ;
V_69 = F_17 ( V_2 ) ;
if ( V_69 < 0 )
return V_69 ;
return V_2 -> V_70 -> V_71 ( V_2 ) ;
}
static int F_40 ( struct V_63 * V_3 , struct V_1 * V_2 ,
T_1 V_72 , T_2 V_31 )
{
struct V_4 * V_67 = & V_2 -> V_3 ;
int V_18 ;
if ( NULL == V_67 -> V_73 ) {
if ( V_2 -> V_22 ) {
F_35 ( L_3 , V_2 -> V_17 ) ;
return - V_68 ;
}
V_67 -> V_73 = & V_74 . V_73 ;
V_18 = V_67 -> V_73 -> V_75 ( V_67 ) ;
if ( V_18 >= 0 )
V_18 = F_50 ( V_67 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_76 ) {
F_51 ( & V_3 -> V_3 , L_4 ) ;
return - V_77 ;
}
V_2 -> V_76 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_66 = V_72 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_41 = V_78 ;
V_18 = F_49 ( V_2 ) ;
if ( V_18 )
F_48 ( V_2 ) ;
return V_18 ;
}
struct V_1 * F_52 ( struct V_63 * V_3 ,
const char * V_5 , T_2 V_31 )
{
struct V_79 * V_20 = & V_36 ;
struct V_1 * V_2 ;
struct V_4 * V_67 ;
int V_65 ;
V_67 = F_44 ( V_20 , NULL , V_5 ) ;
if ( ! V_67 ) {
F_35 ( L_2 , V_5 ) ;
return F_32 ( - V_68 ) ;
}
V_2 = F_5 ( V_67 ) ;
V_65 = F_40 ( V_3 , V_2 , V_2 -> V_66 , V_31 ) ;
if ( V_65 )
return F_32 ( V_65 ) ;
return V_2 ;
}
void F_48 ( struct V_1 * V_2 )
{
V_2 -> V_76 -> V_2 = NULL ;
V_2 -> V_76 = NULL ;
if ( V_2 -> V_3 . V_73 == & V_74 . V_73 )
F_53 ( & V_2 -> V_3 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
T_1 V_80 ;
int V_81 , V_82 ;
int V_18 , V_83 = 0 ;
V_2 -> V_84 &= V_2 -> V_85 ;
V_80 = V_2 -> V_84 ;
V_81 = V_82 = F_55 ( V_2 , V_86 ) ;
if ( V_82 < 0 )
return V_82 ;
V_82 &= ~ ( V_87 | V_88 | V_89 |
V_90 ) ;
V_82 |= F_56 ( V_80 ) ;
if ( V_82 != V_81 ) {
V_18 = F_57 ( V_2 , V_86 , V_82 ) ;
if ( V_18 < 0 )
return V_18 ;
V_83 = 1 ;
}
if ( V_2 -> V_85 & ( V_91 |
V_92 ) ) {
V_81 = V_82 = F_55 ( V_2 , V_93 ) ;
if ( V_82 < 0 )
return V_82 ;
V_82 &= ~ ( V_94 | V_95 ) ;
V_82 |= F_58 ( V_80 ) ;
if ( V_82 != V_81 ) {
V_18 = F_57 ( V_2 , V_93 , V_82 ) ;
if ( V_18 < 0 )
return V_18 ;
V_83 = 1 ;
}
}
return V_83 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_18 ;
int V_96 = 0 ;
V_2 -> V_28 = V_2 -> V_29 = 0 ;
if ( V_97 == V_2 -> V_26 )
V_96 |= V_98 ;
else if ( V_99 == V_2 -> V_26 )
V_96 |= V_100 ;
if ( V_101 == V_2 -> V_27 )
V_96 |= V_102 ;
V_18 = F_57 ( V_2 , V_103 , V_96 ) ;
return V_18 ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_96 ;
V_96 = F_55 ( V_2 , V_103 ) ;
if ( V_96 < 0 )
return V_96 ;
V_96 |= ( V_104 | V_105 ) ;
V_96 &= ~ ( V_106 ) ;
V_96 = F_57 ( V_2 , V_103 , V_96 ) ;
return V_96 ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_107 ;
if ( V_34 != V_2 -> V_33 )
return F_59 ( V_2 ) ;
V_107 = F_54 ( V_2 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( V_107 == 0 ) {
int V_96 = F_55 ( V_2 , V_103 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! ( V_96 & V_104 ) || ( V_96 & V_106 ) )
V_107 = 1 ;
}
if ( V_107 > 0 )
V_107 = F_60 ( V_2 ) ;
return V_107 ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_108 ;
V_108 = F_55 ( V_2 , V_109 ) ;
if ( V_108 < 0 )
return V_108 ;
V_108 = F_55 ( V_2 , V_109 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( ( V_108 & V_110 ) == 0 )
V_2 -> V_30 = 0 ;
else
V_2 -> V_30 = 1 ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 )
{
int V_82 ;
int V_18 ;
int V_111 ;
int V_112 = 0 ;
V_18 = F_62 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_34 == V_2 -> V_33 ) {
if ( V_2 -> V_85 & ( V_91
| V_92 ) ) {
V_112 = F_55 ( V_2 , V_113 ) ;
if ( V_112 < 0 )
return V_112 ;
V_82 = F_55 ( V_2 , V_93 ) ;
if ( V_82 < 0 )
return V_82 ;
V_112 &= V_82 << 2 ;
}
V_111 = F_55 ( V_2 , V_114 ) ;
if ( V_111 < 0 )
return V_111 ;
V_82 = F_55 ( V_2 , V_86 ) ;
if ( V_82 < 0 )
return V_82 ;
V_111 &= V_82 ;
V_2 -> V_26 = V_115 ;
V_2 -> V_27 = V_116 ;
V_2 -> V_28 = V_2 -> V_29 = 0 ;
if ( V_112 & ( V_117 | V_118 ) ) {
V_2 -> V_26 = V_97 ;
if ( V_112 & V_117 )
V_2 -> V_27 = V_101 ;
} else if ( V_111 & ( V_119 | V_120 ) ) {
V_2 -> V_26 = V_99 ;
if ( V_111 & V_119 )
V_2 -> V_27 = V_101 ;
} else
if ( V_111 & V_121 )
V_2 -> V_27 = V_101 ;
if ( V_2 -> V_27 == V_101 ) {
V_2 -> V_28 = V_111 & V_122 ? 1 : 0 ;
V_2 -> V_29 = V_111 & V_123 ? 1 : 0 ;
}
} else {
int V_124 = F_55 ( V_2 , V_103 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_124 & V_102 )
V_2 -> V_27 = V_101 ;
else
V_2 -> V_27 = V_116 ;
if ( V_124 & V_98 )
V_2 -> V_26 = V_97 ;
else if ( V_124 & V_100 )
V_2 -> V_26 = V_99 ;
else
V_2 -> V_26 = V_115 ;
V_2 -> V_28 = V_2 -> V_29 = 0 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_125 ;
T_1 V_126 ;
V_126 = ( V_127 | V_128
| V_129 | V_130 |
V_131 ) ;
V_125 = F_55 ( V_2 , V_109 ) ;
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
V_125 = F_55 ( V_2 , V_143 ) ;
if ( V_125 < 0 )
return V_125 ;
if ( V_125 & V_144 )
V_126 |= V_92 ;
if ( V_125 & V_145 )
V_126 |= V_91 ;
}
V_2 -> V_85 = V_126 ;
V_2 -> V_84 = V_126 ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 )
{
int V_146 ;
F_10 ( & V_2 -> V_43 ) ;
V_146 = F_55 ( V_2 , V_103 ) ;
F_57 ( V_2 , V_103 , ( V_146 | V_147 ) ) ;
F_12 ( & V_2 -> V_43 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_146 ;
F_10 ( & V_2 -> V_43 ) ;
V_146 = F_55 ( V_2 , V_103 ) ;
F_57 ( V_2 , V_103 , ( V_146 & ~ V_147 ) ) ;
F_12 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_67 ( struct V_4 * V_3 )
{
struct V_1 * V_2 ;
struct V_148 * V_149 ;
struct V_150 * V_70 ;
int V_18 = 0 ;
V_2 = F_5 ( V_3 ) ;
V_70 = V_2 -> V_3 . V_73 ;
V_149 = F_68 ( V_70 ) ;
V_2 -> V_70 = V_149 ;
if ( ! ( V_149 -> V_72 & V_151 ) &&
F_69 ( V_2 ) )
V_2 -> V_37 = V_38 ;
if ( V_149 -> V_72 & V_152 )
V_2 -> V_153 = true ;
F_10 ( & V_2 -> V_43 ) ;
V_2 -> V_85 = V_149 -> V_126 ;
V_2 -> V_84 = V_149 -> V_126 ;
V_2 -> V_41 = V_78 ;
if ( V_2 -> V_70 -> V_75 )
V_18 = V_2 -> V_70 -> V_75 ( V_2 ) ;
F_12 ( & V_2 -> V_43 ) ;
return V_18 ;
}
static int F_70 ( struct V_4 * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_3 ) ;
F_10 ( & V_2 -> V_43 ) ;
V_2 -> V_41 = V_42 ;
F_12 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_70 -> remove )
V_2 -> V_70 -> remove ( V_2 ) ;
V_2 -> V_70 = NULL ;
return 0 ;
}
int F_71 ( struct V_148 * V_154 )
{
int V_155 ;
V_154 -> V_73 . V_156 = V_154 -> V_156 ;
V_154 -> V_73 . V_20 = & V_36 ;
V_154 -> V_73 . V_75 = F_67 ;
V_154 -> V_73 . remove = F_70 ;
V_155 = F_72 ( & V_154 -> V_73 ) ;
if ( V_155 ) {
F_35 ( L_5 ,
V_154 -> V_156 , V_155 ) ;
return V_155 ;
}
F_73 ( L_6 , V_154 -> V_156 ) ;
return 0 ;
}
int F_74 ( struct V_148 * V_154 , int V_157 )
{
int V_49 , V_69 = 0 ;
for ( V_49 = 0 ; V_49 < V_157 ; V_49 ++ ) {
V_69 = F_71 ( V_154 + V_49 ) ;
if ( V_69 ) {
while ( V_49 -- > 0 )
F_75 ( V_154 + V_49 ) ;
break;
}
}
return V_69 ;
}
void F_75 ( struct V_148 * V_70 )
{
F_76 ( & V_70 -> V_73 ) ;
}
void F_77 ( struct V_148 * V_70 , int V_157 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_157 ; V_49 ++ ) {
F_75 ( V_70 + V_49 ) ;
}
}
static int T_3 F_78 ( void )
{
int V_65 ;
V_65 = F_79 () ;
if ( V_65 )
return V_65 ;
V_65 = F_71 ( & V_74 ) ;
if ( V_65 )
F_80 () ;
return V_65 ;
}
static void T_4 F_81 ( void )
{
F_75 ( & V_74 ) ;
F_80 () ;
}
