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
struct V_8 * V_9 = F_8 ( sizeof( * V_9 ) , V_10 ) ;
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
static int F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_10 ( & V_12 ) ;
F_18 (fixup, &phy_fixup_list, list) {
if ( F_15 ( V_2 , V_9 ) ) {
int V_18 = V_9 -> F_7 ( V_2 ) ;
if ( V_18 < 0 ) {
F_12 ( & V_12 ) ;
return V_18 ;
}
V_2 -> V_19 = true ;
}
}
F_12 ( & V_12 ) ;
return 0 ;
}
struct V_1 * F_19 ( struct V_20 * V_21 , int V_22 , int V_17 ,
bool V_23 ,
struct V_24 * V_25 )
{
struct V_1 * V_3 ;
V_3 = F_8 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 )
return F_20 ( - V_11 ) ;
V_3 -> V_3 . V_26 = F_3 ;
V_3 -> V_27 = 0 ;
V_3 -> V_28 = - 1 ;
V_3 -> V_29 = 0 ;
V_3 -> V_30 = 0 ;
V_3 -> V_31 = 1 ;
V_3 -> V_32 = V_33 ;
V_3 -> V_34 = V_35 ;
V_3 -> V_23 = V_23 ;
V_3 -> V_22 = V_22 ;
V_3 -> V_17 = V_17 ;
if ( V_25 )
V_3 -> V_25 = * V_25 ;
V_3 -> V_21 = V_21 ;
V_3 -> V_3 . V_36 = & V_21 -> V_3 ;
V_3 -> V_3 . V_21 = & V_37 ;
V_3 -> V_38 = V_21 -> V_38 ? V_21 -> V_38 [ V_22 ] : V_39 ;
F_21 ( & V_3 -> V_3 , V_40 , V_21 -> V_41 , V_22 ) ;
V_3 -> V_42 = V_43 ;
F_22 ( & V_3 -> V_44 ) ;
F_23 ( & V_3 -> V_45 , V_46 ) ;
F_24 ( & V_3 -> V_47 , V_48 ) ;
F_25 (MDIO_MODULE_PREFIX MDIO_ID_FMT, MDIO_ID_ARGS(phy_id)) ;
F_26 ( & V_3 -> V_3 ) ;
return V_3 ;
}
static int F_27 ( struct V_20 * V_21 , int V_22 , int V_49 ,
T_1 * V_50 )
{
int V_51 , V_52 ;
V_52 = V_53 | V_49 << 16 | V_54 ;
V_51 = F_28 ( V_21 , V_22 , V_52 ) ;
if ( V_51 < 0 )
return - V_55 ;
* V_50 = ( V_51 & 0xffff ) << 16 ;
V_52 = V_53 | V_49 << 16 | V_56 ;
V_51 = F_28 ( V_21 , V_22 , V_52 ) ;
if ( V_51 < 0 )
return - V_55 ;
* V_50 |= ( V_51 & 0xffff ) ;
return 0 ;
}
static int F_29 ( struct V_20 * V_21 , int V_22 , T_1 * V_17 ,
struct V_24 * V_25 ) {
int V_51 ;
int V_57 , V_52 ;
const int V_58 = F_30 ( V_25 -> V_59 ) ;
T_1 * V_60 = & V_25 -> V_50 ;
for ( V_57 = 1 ; V_57 < V_58 && * V_60 == 0 ; V_57 ++ ) {
V_51 = F_27 ( V_21 , V_22 , V_57 , V_60 ) ;
if ( V_51 < 0 )
return - V_55 ;
if ( ( * V_60 & 0x1fffffff ) == 0x1fffffff ) {
V_51 = F_27 ( V_21 , V_22 , 0 , V_60 ) ;
if ( V_51 < 0 )
return - V_55 ;
if ( ( * V_60 & 0x1fffffff ) == 0x1fffffff ) {
* V_17 = 0xffffffff ;
return 0 ;
} else {
break;
}
}
}
for ( V_57 = 1 ; V_57 < V_58 ; V_57 ++ ) {
if ( ! ( V_25 -> V_50 & ( 1 << V_57 ) ) )
continue;
V_52 = V_53 | V_57 << 16 | V_61 ;
V_51 = F_28 ( V_21 , V_22 , V_52 ) ;
if ( V_51 < 0 )
return - V_55 ;
V_25 -> V_59 [ V_57 ] = ( V_51 & 0xffff ) << 16 ;
V_52 = V_53 | V_57 << 16 | V_62 ;
V_51 = F_28 ( V_21 , V_22 , V_52 ) ;
if ( V_51 < 0 )
return - V_55 ;
V_25 -> V_59 [ V_57 ] |= ( V_51 & 0xffff ) ;
}
* V_17 = 0 ;
return 0 ;
}
static int F_31 ( struct V_20 * V_21 , int V_22 , T_1 * V_17 ,
bool V_23 , struct V_24 * V_25 )
{
int V_51 ;
if ( V_23 )
return F_29 ( V_21 , V_22 , V_17 , V_25 ) ;
V_51 = F_28 ( V_21 , V_22 , V_61 ) ;
if ( V_51 < 0 )
return - V_55 ;
* V_17 = ( V_51 & 0xffff ) << 16 ;
V_51 = F_28 ( V_21 , V_22 , V_62 ) ;
if ( V_51 < 0 )
return - V_55 ;
* V_17 |= ( V_51 & 0xffff ) ;
return 0 ;
}
struct V_1 * F_32 ( struct V_20 * V_21 , int V_22 , bool V_23 )
{
struct V_24 V_25 = { 0 } ;
T_1 V_17 = 0 ;
int V_63 ;
V_63 = F_31 ( V_21 , V_22 , & V_17 , V_23 , & V_25 ) ;
if ( V_63 )
return F_20 ( V_63 ) ;
if ( ( V_17 & 0x1fffffff ) == 0x1fffffff )
return NULL ;
return F_19 ( V_21 , V_22 , V_17 , V_23 , & V_25 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_21 -> V_64 [ V_2 -> V_22 ] )
return - V_65 ;
V_2 -> V_21 -> V_64 [ V_2 -> V_22 ] = V_2 ;
V_18 = F_17 ( V_2 ) ;
if ( V_18 ) {
F_34 ( L_1 , V_2 -> V_22 ) ;
goto V_66;
}
V_18 = F_35 ( & V_2 -> V_3 ) ;
if ( V_18 ) {
F_34 ( L_2 , V_2 -> V_22 ) ;
goto V_66;
}
return 0 ;
V_66:
V_2 -> V_21 -> V_64 [ V_2 -> V_22 ] = NULL ;
return V_18 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
int V_22 = V_2 -> V_22 ;
F_37 ( & V_2 -> V_3 ) ;
V_21 -> V_64 [ V_22 ] = NULL ;
}
struct V_1 * F_38 ( struct V_20 * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_67 ; V_22 ++ ) {
if ( V_21 -> V_64 [ V_22 ] )
return V_21 -> V_64 [ V_22 ] ;
}
return NULL ;
}
static void F_39 ( struct V_1 * V_2 ,
void (* F_40)( struct V_68 * ) )
{
V_2 -> V_69 = F_40 ;
}
int F_41 ( struct V_68 * V_3 , struct V_1 * V_2 ,
void (* F_40)( struct V_68 * ) ,
T_2 V_32 )
{
int V_70 ;
V_70 = F_42 ( V_3 , V_2 , V_2 -> V_71 , V_32 ) ;
if ( V_70 )
return V_70 ;
F_39 ( V_2 , F_40 ) ;
F_43 ( V_2 ) ;
if ( V_2 -> V_38 > 0 )
F_44 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_45 ( struct V_68 * V_3 , const char * V_5 ,
void (* F_40)( struct V_68 * ) ,
T_2 V_32 )
{
struct V_1 * V_2 ;
struct V_4 * V_72 ;
int V_70 ;
V_72 = F_46 ( & V_37 , NULL , V_5 ) ;
if ( ! V_72 ) {
F_34 ( L_3 , V_5 ) ;
return F_20 ( - V_73 ) ;
}
V_2 = F_5 ( V_72 ) ;
V_70 = F_41 ( V_3 , V_2 , F_40 , V_32 ) ;
if ( V_70 )
return F_20 ( V_70 ) ;
return V_2 ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 > 0 )
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
V_2 -> V_69 = NULL ;
F_50 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
unsigned int V_74 = 12 ;
int V_75 ;
do {
F_52 ( 50 ) ;
V_75 = F_53 ( V_2 , V_76 ) ;
if ( V_75 < 0 )
return V_75 ;
} while ( V_75 & V_77 && -- V_74 );
if ( V_75 & V_77 )
return - V_78 ;
F_52 ( 1 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_75 = 0 ;
if ( ! V_2 -> V_79 || ! V_2 -> V_79 -> V_80 )
return 0 ;
if ( V_2 -> V_79 -> V_81 )
V_75 = V_2 -> V_79 -> V_81 ( V_2 ) ;
else
V_75 = F_55 ( V_2 ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_17 ( V_2 ) ;
if ( V_75 < 0 )
return V_75 ;
return V_2 -> V_79 -> V_80 ( V_2 ) ;
}
int F_42 ( struct V_68 * V_3 , struct V_1 * V_2 ,
T_1 V_82 , T_2 V_32 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_4 * V_72 = & V_2 -> V_3 ;
int V_18 ;
if ( ! F_56 ( V_21 -> V_83 ) ) {
F_57 ( & V_3 -> V_3 , L_4 ) ;
return - V_55 ;
}
F_58 ( V_72 ) ;
if ( ! V_72 -> V_84 ) {
if ( V_2 -> V_23 )
V_72 -> V_84 = & V_85 [ V_86 ] . V_84 ;
else
V_72 -> V_84 = & V_85 [ V_87 ] . V_84 ;
V_18 = V_72 -> V_84 -> V_88 ( V_72 ) ;
if ( V_18 >= 0 )
V_18 = F_59 ( V_72 ) ;
if ( V_18 )
goto error;
}
if ( V_2 -> V_89 ) {
F_57 ( & V_3 -> V_3 , L_5 ) ;
V_18 = - V_90 ;
goto error;
}
V_2 -> V_89 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_71 = V_82 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_42 = V_91 ;
V_18 = F_54 ( V_2 ) ;
if ( V_18 )
F_50 ( V_2 ) ;
else
F_60 ( V_2 ) ;
return V_18 ;
error:
F_2 ( V_72 ) ;
F_61 ( V_21 -> V_83 ) ;
return V_18 ;
}
struct V_1 * F_62 ( struct V_68 * V_3 , const char * V_5 ,
T_2 V_32 )
{
struct V_92 * V_21 = & V_37 ;
struct V_1 * V_2 ;
struct V_4 * V_72 ;
int V_70 ;
V_72 = F_46 ( V_21 , NULL , V_5 ) ;
if ( ! V_72 ) {
F_34 ( L_3 , V_5 ) ;
return F_20 ( - V_73 ) ;
}
V_2 = F_5 ( V_72 ) ;
V_70 = F_42 ( V_3 , V_2 , V_2 -> V_71 , V_32 ) ;
if ( V_70 )
return F_20 ( V_70 ) ;
return V_2 ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_57 ;
V_2 -> V_89 -> V_2 = NULL ;
V_2 -> V_89 = NULL ;
F_63 ( V_2 ) ;
for ( V_57 = 0 ; V_57 < F_30 ( V_85 ) ; V_57 ++ ) {
if ( V_2 -> V_3 . V_84 == & V_85 [ V_57 ] . V_84 ) {
F_64 ( & V_2 -> V_3 ) ;
break;
}
}
V_21 = V_2 -> V_21 ;
F_2 ( & V_2 -> V_3 ) ;
F_61 ( V_21 -> V_83 ) ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = F_65 ( V_2 -> V_3 . V_84 ) ;
struct V_95 V_96 = { . V_97 = V_98 } ;
int V_75 = 0 ;
F_66 ( V_2 , & V_96 ) ;
if ( V_96 . V_99 )
return - V_90 ;
if ( V_94 -> V_100 )
V_75 = V_94 -> V_100 ( V_2 ) ;
if ( V_75 )
return V_75 ;
V_2 -> V_101 = true ;
return V_75 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = F_65 ( V_2 -> V_3 . V_84 ) ;
int V_75 = 0 ;
if ( V_94 -> V_102 )
V_75 = V_94 -> V_102 ( V_2 ) ;
if ( V_75 )
return V_75 ;
V_2 -> V_101 = false ;
return V_75 ;
}
static int F_67 ( struct V_1 * V_2 )
{
T_1 V_103 ;
int V_104 , V_105 , V_106 ;
int V_18 , V_107 = 0 ;
V_2 -> V_108 &= V_2 -> V_109 ;
V_103 = V_2 -> V_108 ;
V_105 = F_53 ( V_2 , V_110 ) ;
if ( V_105 < 0 )
return V_105 ;
V_104 = V_105 ;
V_105 &= ~ ( V_111 | V_112 | V_113 |
V_114 ) ;
V_105 |= F_68 ( V_103 ) ;
if ( V_105 != V_104 ) {
V_18 = F_69 ( V_2 , V_110 , V_105 ) ;
if ( V_18 < 0 )
return V_18 ;
V_107 = 1 ;
}
V_106 = F_53 ( V_2 , V_115 ) ;
if ( V_106 < 0 )
return V_106 ;
if ( ! ( V_106 & V_116 ) )
return V_107 ;
V_105 = F_53 ( V_2 , V_117 ) ;
if ( V_105 < 0 )
return V_105 ;
V_104 = V_105 ;
V_105 &= ~ ( V_118 | V_119 ) ;
if ( V_2 -> V_109 & ( V_120 |
V_121 ) ) {
V_105 |= F_70 ( V_103 ) ;
}
if ( V_105 != V_104 )
V_107 = 1 ;
V_18 = F_69 ( V_2 , V_117 , V_105 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_107 ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_122 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_123 == V_2 -> V_27 )
V_122 |= V_124 ;
else if ( V_125 == V_2 -> V_27 )
V_122 |= V_126 ;
if ( V_127 == V_2 -> V_28 )
V_122 |= V_128 ;
return F_69 ( V_2 , V_76 , V_122 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_122 = F_53 ( V_2 , V_76 ) ;
if ( V_122 < 0 )
return V_122 ;
V_122 |= V_129 | V_130 ;
V_122 &= ~ V_131 ;
return F_69 ( V_2 , V_76 , V_122 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_132 ;
if ( V_35 != V_2 -> V_34 )
return F_71 ( V_2 ) ;
V_132 = F_67 ( V_2 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( V_132 == 0 ) {
int V_122 = F_53 ( V_2 , V_76 ) ;
if ( V_122 < 0 )
return V_122 ;
if ( ! ( V_122 & V_129 ) || ( V_122 & V_131 ) )
V_132 = 1 ;
}
if ( V_132 > 0 )
V_132 = F_72 ( V_2 ) ;
return V_132 ;
}
int F_74 ( struct V_1 * V_2 )
{
int V_133 = F_53 ( V_2 , V_115 ) ;
return ( V_133 < 0 ) ? V_133 : ( V_133 & V_134 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_135 ;
V_135 = F_53 ( V_2 , V_115 ) ;
if ( V_135 < 0 )
return V_135 ;
V_135 = F_53 ( V_2 , V_115 ) ;
if ( V_135 < 0 )
return V_135 ;
if ( ( V_135 & V_136 ) == 0 )
V_2 -> V_31 = 0 ;
else
V_2 -> V_31 = 1 ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 )
{
int V_105 ;
int V_18 ;
int V_137 ;
int V_138 = 0 ;
int V_139 ;
int V_140 = 0 ;
V_18 = F_76 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_141 = 0 ;
if ( V_35 == V_2 -> V_34 ) {
if ( V_2 -> V_109 & ( V_120
| V_121 ) ) {
V_138 = F_53 ( V_2 , V_142 ) ;
if ( V_138 < 0 )
return V_138 ;
V_105 = F_53 ( V_2 , V_117 ) ;
if ( V_105 < 0 )
return V_105 ;
V_2 -> V_141 =
F_78 ( V_138 ) ;
V_140 = V_138 & V_105 << 2 ;
}
V_137 = F_53 ( V_2 , V_143 ) ;
if ( V_137 < 0 )
return V_137 ;
V_2 -> V_141 |= F_79 ( V_137 ) ;
V_105 = F_53 ( V_2 , V_110 ) ;
if ( V_105 < 0 )
return V_105 ;
V_139 = V_137 & V_105 ;
V_2 -> V_27 = V_144 ;
V_2 -> V_28 = V_145 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_140 & ( V_146 | V_147 ) ) {
V_2 -> V_27 = V_123 ;
if ( V_140 & V_146 )
V_2 -> V_28 = V_127 ;
} else if ( V_139 & ( V_148 | V_149 ) ) {
V_2 -> V_27 = V_125 ;
if ( V_139 & V_148 )
V_2 -> V_28 = V_127 ;
} else
if ( V_139 & V_150 )
V_2 -> V_28 = V_127 ;
if ( V_2 -> V_28 == V_127 ) {
V_2 -> V_29 = V_137 & V_151 ? 1 : 0 ;
V_2 -> V_30 = V_137 & V_152 ? 1 : 0 ;
}
} else {
int V_153 = F_53 ( V_2 , V_76 ) ;
if ( V_153 < 0 )
return V_153 ;
if ( V_153 & V_128 )
V_2 -> V_28 = V_127 ;
else
V_2 -> V_28 = V_145 ;
if ( V_153 & V_124 )
V_2 -> V_27 = V_123 ;
else if ( V_153 & V_126 )
V_2 -> V_27 = V_125 ;
else
V_2 -> V_27 = V_144 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_154 , V_155 ;
T_1 V_156 = V_2 -> V_25 . V_50 ;
V_2 -> V_31 = 1 ;
V_2 -> V_27 = V_157 ;
V_2 -> V_28 = V_127 ;
for ( V_154 = 0 ; V_156 ; V_154 ++ , V_156 = V_156 >> 1 ) {
if ( ! ( V_156 & 1 ) )
continue;
F_81 ( V_2 , V_154 , V_158 ) ;
V_155 = F_81 ( V_2 , V_154 , V_158 ) ;
if ( V_155 < 0 || ! ( V_155 & V_159 ) )
V_2 -> V_31 = 0 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_75 ;
V_75 = F_69 ( V_2 , V_76 , V_77 ) ;
if ( V_75 < 0 )
return V_75 ;
return F_51 ( V_2 ) ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_160 ;
T_1 V_161 ;
V_161 = ( V_162 | V_163
| V_164 | V_165 |
V_166 ) ;
V_160 = F_53 ( V_2 , V_115 ) ;
if ( V_160 < 0 )
return V_160 ;
if ( V_160 & V_167 )
V_161 |= V_168 ;
if ( V_160 & V_169 )
V_161 |= V_170 ;
if ( V_160 & V_171 )
V_161 |= V_172 ;
if ( V_160 & V_173 )
V_161 |= V_174 ;
if ( V_160 & V_175 )
V_161 |= V_176 ;
if ( V_160 & V_116 ) {
V_160 = F_53 ( V_2 , V_177 ) ;
if ( V_160 < 0 )
return V_160 ;
if ( V_160 & V_178 )
V_161 |= V_121 ;
if ( V_160 & V_179 )
V_161 |= V_120 ;
}
V_2 -> V_109 &= V_161 ;
V_2 -> V_108 &= V_161 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
V_2 -> V_109 = V_180 ;
V_2 -> V_108 = V_180 ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 )
{
int V_181 ;
F_10 ( & V_2 -> V_44 ) ;
V_181 = F_53 ( V_2 , V_76 ) ;
F_69 ( V_2 , V_76 , V_181 | V_182 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_87 ( struct V_1 * V_2 )
{
int V_181 ;
F_10 ( & V_2 -> V_44 ) ;
V_181 = F_53 ( V_2 , V_76 ) ;
F_69 ( V_2 , V_76 , V_181 & ~ V_182 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , T_1 V_183 )
{
V_2 -> V_109 &= V_184 ;
switch ( V_183 ) {
default:
return - V_185 ;
case V_123 :
V_2 -> V_109 |= V_186 ;
case V_125 :
V_2 -> V_109 |= V_187 ;
case V_144 :
V_2 -> V_109 |= V_188 ;
}
return 0 ;
}
int F_90 ( struct V_1 * V_2 , T_1 V_183 )
{
int V_18 ;
V_18 = F_89 ( V_2 , V_183 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_108 = V_2 -> V_109 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_189 * V_190 = V_2 -> V_3 . V_191 ;
T_1 V_183 ;
if ( ! F_92 ( V_192 ) )
return;
if ( ! V_190 )
return;
if ( ! F_93 ( V_190 , L_6 , & V_183 ) )
F_89 ( V_2 , V_183 ) ;
}
static int F_94 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_193 * V_79 = V_2 -> V_3 . V_84 ;
struct V_93 * V_94 = F_65 ( V_79 ) ;
int V_18 = 0 ;
V_2 -> V_79 = V_94 ;
if ( ! ( V_94 -> V_82 & V_194 ) &&
F_95 ( V_2 ) )
V_2 -> V_38 = V_39 ;
if ( V_94 -> V_82 & V_195 )
V_2 -> V_196 = true ;
F_10 ( & V_2 -> V_44 ) ;
V_2 -> V_109 = V_94 -> V_161 ;
F_91 ( V_2 ) ;
V_2 -> V_108 = V_2 -> V_109 ;
V_2 -> V_42 = V_91 ;
if ( V_2 -> V_79 -> V_88 )
V_18 = V_2 -> V_79 -> V_88 ( V_2 ) ;
F_12 ( & V_2 -> V_44 ) ;
return V_18 ;
}
static int F_96 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
F_10 ( & V_2 -> V_44 ) ;
V_2 -> V_42 = V_43 ;
F_12 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_79 -> remove )
V_2 -> V_79 -> remove ( V_2 ) ;
V_2 -> V_79 = NULL ;
return 0 ;
}
int F_97 ( struct V_93 * V_197 )
{
int V_133 ;
V_197 -> V_84 . V_198 = V_197 -> V_198 ;
V_197 -> V_84 . V_21 = & V_37 ;
V_197 -> V_84 . V_88 = F_94 ;
V_197 -> V_84 . remove = F_96 ;
V_133 = F_98 ( & V_197 -> V_84 ) ;
if ( V_133 ) {
F_34 ( L_7 ,
V_197 -> V_198 , V_133 ) ;
return V_133 ;
}
F_99 ( L_8 , V_197 -> V_198 ) ;
return 0 ;
}
int F_100 ( struct V_93 * V_197 , int V_199 )
{
int V_57 , V_75 = 0 ;
for ( V_57 = 0 ; V_57 < V_199 ; V_57 ++ ) {
V_75 = F_97 ( V_197 + V_57 ) ;
if ( V_75 ) {
while ( V_57 -- > 0 )
F_101 ( V_197 + V_57 ) ;
break;
}
}
return V_75 ;
}
void F_101 ( struct V_93 * V_79 )
{
F_102 ( & V_79 -> V_84 ) ;
}
void F_103 ( struct V_93 * V_79 , int V_199 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_199 ; V_57 ++ )
F_101 ( V_79 + V_57 ) ;
}
static int T_3 F_104 ( void )
{
int V_70 ;
V_70 = F_105 () ;
if ( V_70 )
return V_70 ;
V_70 = F_100 ( V_85 ,
F_30 ( V_85 ) ) ;
if ( V_70 )
F_106 () ;
return V_70 ;
}
static void T_4 F_107 ( void )
{
F_103 ( V_85 ,
F_30 ( V_85 ) ) ;
F_106 () ;
}
