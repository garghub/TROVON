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
F_24 (MDIO_MODULE_PREFIX MDIO_ID_FMT, MDIO_ID_ARGS(phy_id)) ;
F_25 ( & V_3 -> V_3 ) ;
return V_3 ;
}
static int F_26 ( struct V_19 * V_20 , int V_21 , T_1 * V_17 ,
struct V_23 * V_24 ) {
int V_46 ;
int V_47 , V_48 ;
const int V_49 = F_27 ( V_24 -> V_50 ) ;
for ( V_47 = 1 ;
V_47 < V_49 && V_24 -> V_51 == 0 ;
V_47 ++ ) {
V_48 = V_52 | V_47 << 16 | 6 ;
V_46 = F_28 ( V_20 , V_21 , V_48 ) ;
if ( V_46 < 0 )
return - V_53 ;
V_24 -> V_51 = ( V_46 & 0xffff ) << 16 ;
V_48 = V_52 | V_47 << 16 | 5 ;
V_46 = F_28 ( V_20 , V_21 , V_48 ) ;
if ( V_46 < 0 )
return - V_53 ;
V_24 -> V_51 |= ( V_46 & 0xffff ) ;
if ( ( V_24 -> V_51 & 0x1fffffff ) == 0x1fffffff ) {
* V_17 = 0xffffffff ;
return 0 ;
}
}
for ( V_47 = 1 ; V_47 < V_49 ; V_47 ++ ) {
if ( ! ( V_24 -> V_51 & ( 1 << V_47 ) ) )
continue;
V_48 = V_52 | V_47 << 16 | V_54 ;
V_46 = F_28 ( V_20 , V_21 , V_48 ) ;
if ( V_46 < 0 )
return - V_53 ;
V_24 -> V_50 [ V_47 ] = ( V_46 & 0xffff ) << 16 ;
V_48 = V_52 | V_47 << 16 | V_55 ;
V_46 = F_28 ( V_20 , V_21 , V_48 ) ;
if ( V_46 < 0 )
return - V_53 ;
V_24 -> V_50 [ V_47 ] |= ( V_46 & 0xffff ) ;
}
* V_17 = 0 ;
return 0 ;
}
static int F_29 ( struct V_19 * V_20 , int V_21 , T_1 * V_17 ,
bool V_22 , struct V_23 * V_24 )
{
int V_46 ;
if ( V_22 )
return F_26 ( V_20 , V_21 , V_17 , V_24 ) ;
V_46 = F_28 ( V_20 , V_21 , V_54 ) ;
if ( V_46 < 0 )
return - V_53 ;
* V_17 = ( V_46 & 0xffff ) << 16 ;
V_46 = F_28 ( V_20 , V_21 , V_55 ) ;
if ( V_46 < 0 )
return - V_53 ;
* V_17 |= ( V_46 & 0xffff ) ;
return 0 ;
}
struct V_1 * F_30 ( struct V_19 * V_20 , int V_21 , bool V_22 )
{
struct V_23 V_24 = { 0 } ;
struct V_1 * V_3 = NULL ;
T_1 V_17 = 0 ;
int V_56 ;
V_56 = F_29 ( V_20 , V_21 , & V_17 , V_22 , & V_24 ) ;
if ( V_56 )
return F_31 ( V_56 ) ;
if ( ( V_17 & 0x1fffffff ) == 0x1fffffff )
return NULL ;
V_3 = F_19 ( V_20 , V_21 , V_17 , V_22 , & V_24 ) ;
return V_3 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_20 -> V_57 [ V_2 -> V_21 ] )
return - V_58 ;
V_2 -> V_20 -> V_57 [ V_2 -> V_21 ] = V_2 ;
F_17 ( V_2 ) ;
V_18 = F_33 ( & V_2 -> V_3 ) ;
if ( V_18 ) {
F_34 ( L_1 , V_2 -> V_21 ) ;
goto V_59;
}
return 0 ;
V_59:
V_2 -> V_20 -> V_57 [ V_2 -> V_21 ] = NULL ;
return V_18 ;
}
struct V_1 * F_35 ( struct V_19 * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_60 ; V_21 ++ ) {
if ( V_20 -> V_57 [ V_21 ] )
return V_20 -> V_57 [ V_21 ] ;
}
return NULL ;
}
static void F_36 ( struct V_1 * V_2 ,
void (* F_37)( struct V_61 * ) )
{
V_2 -> V_62 = F_37 ;
}
int F_38 ( struct V_61 * V_3 , struct V_1 * V_2 ,
void (* F_37)( struct V_61 * ) ,
T_2 V_31 )
{
int V_63 ;
V_63 = F_39 ( V_3 , V_2 , V_2 -> V_64 , V_31 ) ;
if ( V_63 )
return V_63 ;
F_36 ( V_2 , F_37 ) ;
F_40 ( V_2 , NULL ) ;
if ( V_2 -> V_37 > 0 )
F_41 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_42 ( struct V_61 * V_3 , const char * V_5 ,
void (* F_37)( struct V_61 * ) ,
T_2 V_31 )
{
struct V_1 * V_2 ;
struct V_4 * V_65 ;
int V_63 ;
V_65 = F_43 ( & V_36 , NULL , V_5 ) ;
if ( ! V_65 ) {
F_34 ( L_2 , V_5 ) ;
return F_31 ( - V_66 ) ;
}
V_2 = F_5 ( V_65 ) ;
V_63 = F_38 ( V_3 , V_2 , F_37 , V_31 ) ;
if ( V_63 )
return F_31 ( V_63 ) ;
return V_2 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 > 0 )
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
V_2 -> V_62 = NULL ;
F_47 ( V_2 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_67 ;
if ( ! V_2 -> V_68 || ! V_2 -> V_68 -> V_69 )
return 0 ;
V_67 = F_17 ( V_2 ) ;
if ( V_67 < 0 )
return V_67 ;
return V_2 -> V_68 -> V_69 ( V_2 ) ;
}
static int F_39 ( struct V_61 * V_3 , struct V_1 * V_2 ,
T_1 V_70 , T_2 V_31 )
{
struct V_4 * V_65 = & V_2 -> V_3 ;
int V_18 ;
if ( NULL == V_65 -> V_71 ) {
if ( V_2 -> V_22 ) {
F_34 ( L_3 , V_2 -> V_17 ) ;
return - V_66 ;
}
V_65 -> V_71 = & V_72 . V_71 ;
V_18 = V_65 -> V_71 -> V_73 ( V_65 ) ;
if ( V_18 >= 0 )
V_18 = F_49 ( V_65 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_74 ) {
F_50 ( & V_3 -> V_3 , L_4 ) ;
return - V_75 ;
}
V_2 -> V_74 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_64 = V_70 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_41 = V_76 ;
V_18 = F_48 ( V_2 ) ;
if ( V_18 )
F_47 ( V_2 ) ;
return V_18 ;
}
struct V_1 * F_51 ( struct V_61 * V_3 ,
const char * V_5 , T_2 V_31 )
{
struct V_77 * V_20 = & V_36 ;
struct V_1 * V_2 ;
struct V_4 * V_65 ;
int V_63 ;
V_65 = F_43 ( V_20 , NULL , V_5 ) ;
if ( ! V_65 ) {
F_34 ( L_2 , V_5 ) ;
return F_31 ( - V_66 ) ;
}
V_2 = F_5 ( V_65 ) ;
V_63 = F_39 ( V_3 , V_2 , V_2 -> V_64 , V_31 ) ;
if ( V_63 )
return F_31 ( V_63 ) ;
return V_2 ;
}
void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_74 -> V_2 = NULL ;
V_2 -> V_74 = NULL ;
if ( V_2 -> V_3 . V_71 == & V_72 . V_71 )
F_52 ( & V_2 -> V_3 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
T_1 V_78 ;
int V_79 , V_80 ;
int V_18 , V_81 = 0 ;
V_2 -> V_82 &= V_2 -> V_83 ;
V_78 = V_2 -> V_82 ;
V_79 = V_80 = F_54 ( V_2 , V_84 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 &= ~ ( V_85 | V_86 | V_87 |
V_88 ) ;
V_80 |= F_55 ( V_78 ) ;
if ( V_80 != V_79 ) {
V_18 = F_56 ( V_2 , V_84 , V_80 ) ;
if ( V_18 < 0 )
return V_18 ;
V_81 = 1 ;
}
if ( V_2 -> V_83 & ( V_89 |
V_90 ) ) {
V_79 = V_80 = F_54 ( V_2 , V_91 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 &= ~ ( V_92 | V_93 ) ;
V_80 |= F_57 ( V_78 ) ;
if ( V_80 != V_79 ) {
V_18 = F_56 ( V_2 , V_91 , V_80 ) ;
if ( V_18 < 0 )
return V_18 ;
V_81 = 1 ;
}
}
return V_81 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_18 ;
int V_94 = 0 ;
V_2 -> V_28 = V_2 -> V_29 = 0 ;
if ( V_95 == V_2 -> V_26 )
V_94 |= V_96 ;
else if ( V_97 == V_2 -> V_26 )
V_94 |= V_98 ;
if ( V_99 == V_2 -> V_27 )
V_94 |= V_100 ;
V_18 = F_56 ( V_2 , V_101 , V_94 ) ;
return V_18 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_94 ;
V_94 = F_54 ( V_2 , V_101 ) ;
if ( V_94 < 0 )
return V_94 ;
V_94 |= ( V_102 | V_103 ) ;
V_94 &= ~ ( V_104 ) ;
V_94 = F_56 ( V_2 , V_101 , V_94 ) ;
return V_94 ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_105 ;
if ( V_34 != V_2 -> V_33 )
return F_58 ( V_2 ) ;
V_105 = F_53 ( V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
if ( V_105 == 0 ) {
int V_94 = F_54 ( V_2 , V_101 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( ! ( V_94 & V_102 ) || ( V_94 & V_104 ) )
V_105 = 1 ;
}
if ( V_105 > 0 )
V_105 = F_59 ( V_2 ) ;
return V_105 ;
}
int F_61 ( struct V_1 * V_2 )
{
int V_106 ;
V_106 = F_54 ( V_2 , V_107 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_54 ( V_2 , V_107 ) ;
if ( V_106 < 0 )
return V_106 ;
if ( ( V_106 & V_108 ) == 0 )
V_2 -> V_30 = 0 ;
else
V_2 -> V_30 = 1 ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_80 ;
int V_18 ;
int V_109 ;
int V_110 = 0 ;
V_18 = F_61 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_34 == V_2 -> V_33 ) {
if ( V_2 -> V_83 & ( V_89
| V_90 ) ) {
V_110 = F_54 ( V_2 , V_111 ) ;
if ( V_110 < 0 )
return V_110 ;
V_80 = F_54 ( V_2 , V_91 ) ;
if ( V_80 < 0 )
return V_80 ;
V_110 &= V_80 << 2 ;
}
V_109 = F_54 ( V_2 , V_112 ) ;
if ( V_109 < 0 )
return V_109 ;
V_80 = F_54 ( V_2 , V_84 ) ;
if ( V_80 < 0 )
return V_80 ;
V_109 &= V_80 ;
V_2 -> V_26 = V_113 ;
V_2 -> V_27 = V_114 ;
V_2 -> V_28 = V_2 -> V_29 = 0 ;
if ( V_110 & ( V_115 | V_116 ) ) {
V_2 -> V_26 = V_95 ;
if ( V_110 & V_115 )
V_2 -> V_27 = V_99 ;
} else if ( V_109 & ( V_117 | V_118 ) ) {
V_2 -> V_26 = V_97 ;
if ( V_109 & V_117 )
V_2 -> V_27 = V_99 ;
} else
if ( V_109 & V_119 )
V_2 -> V_27 = V_99 ;
if ( V_2 -> V_27 == V_99 ) {
V_2 -> V_28 = V_109 & V_120 ? 1 : 0 ;
V_2 -> V_29 = V_109 & V_121 ? 1 : 0 ;
}
} else {
int V_122 = F_54 ( V_2 , V_101 ) ;
if ( V_122 < 0 )
return V_122 ;
if ( V_122 & V_100 )
V_2 -> V_27 = V_99 ;
else
V_2 -> V_27 = V_114 ;
if ( V_122 & V_96 )
V_2 -> V_26 = V_95 ;
else if ( V_122 & V_98 )
V_2 -> V_26 = V_97 ;
else
V_2 -> V_26 = V_113 ;
V_2 -> V_28 = V_2 -> V_29 = 0 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_123 ;
T_1 V_124 ;
V_124 = ( V_125 | V_126
| V_127 | V_128 |
V_129 ) ;
V_123 = F_54 ( V_2 , V_107 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_123 & V_130 )
V_124 |= V_131 ;
if ( V_123 & V_132 )
V_124 |= V_133 ;
if ( V_123 & V_134 )
V_124 |= V_135 ;
if ( V_123 & V_136 )
V_124 |= V_137 ;
if ( V_123 & V_138 )
V_124 |= V_139 ;
if ( V_123 & V_140 ) {
V_123 = F_54 ( V_2 , V_141 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( V_123 & V_142 )
V_124 |= V_90 ;
if ( V_123 & V_143 )
V_124 |= V_89 ;
}
V_2 -> V_83 = V_124 ;
V_2 -> V_82 = V_124 ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_144 ;
F_10 ( & V_2 -> V_43 ) ;
V_144 = F_54 ( V_2 , V_101 ) ;
F_56 ( V_2 , V_101 , ( V_144 | V_145 ) ) ;
F_12 ( & V_2 -> V_43 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 )
{
int V_144 ;
F_10 ( & V_2 -> V_43 ) ;
V_144 = F_54 ( V_2 , V_101 ) ;
F_56 ( V_2 , V_101 , ( V_144 & ~ V_145 ) ) ;
F_12 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_66 ( struct V_4 * V_3 )
{
struct V_1 * V_2 ;
struct V_146 * V_147 ;
struct V_148 * V_68 ;
int V_18 = 0 ;
V_2 = F_5 ( V_3 ) ;
V_68 = V_2 -> V_3 . V_71 ;
V_147 = F_67 ( V_68 ) ;
V_2 -> V_68 = V_147 ;
if ( ! ( V_147 -> V_70 & V_149 ) )
V_2 -> V_37 = V_38 ;
F_10 ( & V_2 -> V_43 ) ;
V_2 -> V_83 = V_147 -> V_124 ;
V_2 -> V_82 = V_147 -> V_124 ;
V_2 -> V_41 = V_76 ;
if ( V_2 -> V_68 -> V_73 )
V_18 = V_2 -> V_68 -> V_73 ( V_2 ) ;
F_12 ( & V_2 -> V_43 ) ;
return V_18 ;
}
static int F_68 ( struct V_4 * V_3 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_3 ) ;
F_10 ( & V_2 -> V_43 ) ;
V_2 -> V_41 = V_42 ;
F_12 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_68 -> remove )
V_2 -> V_68 -> remove ( V_2 ) ;
V_2 -> V_68 = NULL ;
return 0 ;
}
int F_69 ( struct V_146 * V_150 )
{
int V_151 ;
V_150 -> V_71 . V_152 = V_150 -> V_152 ;
V_150 -> V_71 . V_20 = & V_36 ;
V_150 -> V_71 . V_73 = F_66 ;
V_150 -> V_71 . remove = F_68 ;
V_151 = F_70 ( & V_150 -> V_71 ) ;
if ( V_151 ) {
F_34 ( L_5 ,
V_150 -> V_152 , V_151 ) ;
return V_151 ;
}
F_71 ( L_6 , V_150 -> V_152 ) ;
return 0 ;
}
int F_72 ( struct V_146 * V_150 , int V_153 )
{
int V_47 , V_67 = 0 ;
for ( V_47 = 0 ; V_47 < V_153 ; V_47 ++ ) {
V_67 = F_69 ( V_150 + V_47 ) ;
if ( V_67 ) {
while ( V_47 -- > 0 )
F_73 ( V_150 + V_47 ) ;
break;
}
}
return V_67 ;
}
void F_73 ( struct V_146 * V_68 )
{
F_74 ( & V_68 -> V_71 ) ;
}
void F_75 ( struct V_146 * V_68 , int V_153 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_153 ; V_47 ++ ) {
F_73 ( V_68 + V_47 ) ;
}
}
static int T_3 F_76 ( void )
{
int V_63 ;
V_63 = F_77 () ;
if ( V_63 )
return V_63 ;
V_63 = F_69 ( & V_72 ) ;
if ( V_63 )
F_78 () ;
return V_63 ;
}
static void T_4 F_79 ( void )
{
F_73 ( & V_72 ) ;
F_78 () ;
}
