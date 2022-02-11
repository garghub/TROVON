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
static int F_27 ( struct V_20 * V_21 , int V_22 , T_1 * V_17 ,
struct V_24 * V_25 ) {
int V_49 ;
int V_50 , V_51 ;
const int V_52 = F_28 ( V_25 -> V_53 ) ;
for ( V_50 = 1 ;
V_50 < V_52 && V_25 -> V_54 == 0 ;
V_50 ++ ) {
V_55: V_51 = V_56 | V_50 << 16 | V_57 ;
V_49 = F_29 ( V_21 , V_22 , V_51 ) ;
if ( V_49 < 0 )
return - V_58 ;
V_25 -> V_54 = ( V_49 & 0xffff ) << 16 ;
V_51 = V_56 | V_50 << 16 | V_59 ;
V_49 = F_29 ( V_21 , V_22 , V_51 ) ;
if ( V_49 < 0 )
return - V_58 ;
V_25 -> V_54 |= ( V_49 & 0xffff ) ;
if ( ( V_25 -> V_54 & 0x1fffffff ) == 0x1fffffff ) {
if ( V_50 ) {
V_50 = 0 ;
goto V_55;
} else {
* V_17 = 0xffffffff ;
return 0 ;
}
}
}
for ( V_50 = 1 ; V_50 < V_52 ; V_50 ++ ) {
if ( ! ( V_25 -> V_54 & ( 1 << V_50 ) ) )
continue;
V_51 = V_56 | V_50 << 16 | V_60 ;
V_49 = F_29 ( V_21 , V_22 , V_51 ) ;
if ( V_49 < 0 )
return - V_58 ;
V_25 -> V_53 [ V_50 ] = ( V_49 & 0xffff ) << 16 ;
V_51 = V_56 | V_50 << 16 | V_61 ;
V_49 = F_29 ( V_21 , V_22 , V_51 ) ;
if ( V_49 < 0 )
return - V_58 ;
V_25 -> V_53 [ V_50 ] |= ( V_49 & 0xffff ) ;
}
* V_17 = 0 ;
return 0 ;
}
static int F_30 ( struct V_20 * V_21 , int V_22 , T_1 * V_17 ,
bool V_23 , struct V_24 * V_25 )
{
int V_49 ;
if ( V_23 )
return F_27 ( V_21 , V_22 , V_17 , V_25 ) ;
V_49 = F_29 ( V_21 , V_22 , V_60 ) ;
if ( V_49 < 0 )
return - V_58 ;
* V_17 = ( V_49 & 0xffff ) << 16 ;
V_49 = F_29 ( V_21 , V_22 , V_61 ) ;
if ( V_49 < 0 )
return - V_58 ;
* V_17 |= ( V_49 & 0xffff ) ;
return 0 ;
}
struct V_1 * F_31 ( struct V_20 * V_21 , int V_22 , bool V_23 )
{
struct V_24 V_25 = { 0 } ;
T_1 V_17 = 0 ;
int V_62 ;
V_62 = F_30 ( V_21 , V_22 , & V_17 , V_23 , & V_25 ) ;
if ( V_62 )
return F_20 ( V_62 ) ;
if ( ( V_17 & 0x1fffffff ) == 0x1fffffff )
return NULL ;
return F_19 ( V_21 , V_22 , V_17 , V_23 , & V_25 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_21 -> V_63 [ V_2 -> V_22 ] )
return - V_64 ;
V_2 -> V_21 -> V_63 [ V_2 -> V_22 ] = V_2 ;
V_18 = F_17 ( V_2 ) ;
if ( V_18 ) {
F_33 ( L_1 , V_2 -> V_22 ) ;
goto V_65;
}
V_18 = F_34 ( & V_2 -> V_3 ) ;
if ( V_18 ) {
F_33 ( L_2 , V_2 -> V_22 ) ;
goto V_65;
}
return 0 ;
V_65:
V_2 -> V_21 -> V_63 [ V_2 -> V_22 ] = NULL ;
return V_18 ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
int V_22 = V_2 -> V_22 ;
F_36 ( & V_2 -> V_3 ) ;
V_21 -> V_63 [ V_22 ] = NULL ;
}
struct V_1 * F_37 ( struct V_20 * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_66 ; V_22 ++ ) {
if ( V_21 -> V_63 [ V_22 ] )
return V_21 -> V_63 [ V_22 ] ;
}
return NULL ;
}
static void F_38 ( struct V_1 * V_2 ,
void (* F_39)( struct V_67 * ) )
{
V_2 -> V_68 = F_39 ;
}
int F_40 ( struct V_67 * V_3 , struct V_1 * V_2 ,
void (* F_39)( struct V_67 * ) ,
T_2 V_32 )
{
int V_69 ;
V_69 = F_41 ( V_3 , V_2 , V_2 -> V_70 , V_32 ) ;
if ( V_69 )
return V_69 ;
F_38 ( V_2 , F_39 ) ;
F_42 ( V_2 ) ;
if ( V_2 -> V_38 > 0 )
F_43 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_44 ( struct V_67 * V_3 , const char * V_5 ,
void (* F_39)( struct V_67 * ) ,
T_2 V_32 )
{
struct V_1 * V_2 ;
struct V_4 * V_71 ;
int V_69 ;
V_71 = F_45 ( & V_37 , NULL , V_5 ) ;
if ( ! V_71 ) {
F_33 ( L_3 , V_5 ) ;
return F_20 ( - V_72 ) ;
}
V_2 = F_5 ( V_71 ) ;
V_69 = F_40 ( V_3 , V_2 , F_39 , V_32 ) ;
if ( V_69 )
return F_20 ( V_69 ) ;
return V_2 ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 > 0 )
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
V_2 -> V_68 = NULL ;
F_49 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
unsigned int V_73 = 12 ;
int V_74 ;
do {
F_51 ( 50 ) ;
V_74 = F_52 ( V_2 , V_75 ) ;
if ( V_74 < 0 )
return V_74 ;
} while ( V_74 & V_76 && -- V_73 );
if ( V_74 & V_76 )
return - V_77 ;
F_51 ( 1 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_74 = 0 ;
if ( ! V_2 -> V_78 || ! V_2 -> V_78 -> V_79 )
return 0 ;
if ( V_2 -> V_78 -> V_80 )
V_74 = V_2 -> V_78 -> V_80 ( V_2 ) ;
else
V_74 = F_54 ( V_2 ) ;
if ( V_74 < 0 )
return V_74 ;
V_74 = F_17 ( V_2 ) ;
if ( V_74 < 0 )
return V_74 ;
return V_2 -> V_78 -> V_79 ( V_2 ) ;
}
int F_41 ( struct V_67 * V_3 , struct V_1 * V_2 ,
T_1 V_81 , T_2 V_32 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_4 * V_71 = & V_2 -> V_3 ;
int V_18 ;
if ( ! F_55 ( V_21 -> V_82 ) ) {
F_56 ( & V_3 -> V_3 , L_4 ) ;
return - V_58 ;
}
F_57 ( V_71 ) ;
if ( ! V_71 -> V_83 ) {
if ( V_2 -> V_23 )
V_71 -> V_83 = & V_84 [ V_85 ] . V_83 ;
else
V_71 -> V_83 = & V_84 [ V_86 ] . V_83 ;
V_18 = V_71 -> V_83 -> V_87 ( V_71 ) ;
if ( V_18 >= 0 )
V_18 = F_58 ( V_71 ) ;
if ( V_18 )
goto error;
}
if ( V_2 -> V_88 ) {
F_56 ( & V_3 -> V_3 , L_5 ) ;
V_18 = - V_89 ;
goto error;
}
V_2 -> V_88 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_70 = V_81 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_42 = V_90 ;
V_18 = F_53 ( V_2 ) ;
if ( V_18 )
F_49 ( V_2 ) ;
else
F_59 ( V_2 ) ;
return V_18 ;
error:
F_2 ( V_71 ) ;
F_60 ( V_21 -> V_82 ) ;
return V_18 ;
}
struct V_1 * F_61 ( struct V_67 * V_3 , const char * V_5 ,
T_2 V_32 )
{
struct V_91 * V_21 = & V_37 ;
struct V_1 * V_2 ;
struct V_4 * V_71 ;
int V_69 ;
V_71 = F_45 ( V_21 , NULL , V_5 ) ;
if ( ! V_71 ) {
F_33 ( L_3 , V_5 ) ;
return F_20 ( - V_72 ) ;
}
V_2 = F_5 ( V_71 ) ;
V_69 = F_41 ( V_3 , V_2 , V_2 -> V_70 , V_32 ) ;
if ( V_69 )
return F_20 ( V_69 ) ;
return V_2 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_50 ;
V_2 -> V_88 -> V_2 = NULL ;
V_2 -> V_88 = NULL ;
F_62 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < F_28 ( V_84 ) ; V_50 ++ ) {
if ( V_2 -> V_3 . V_83 == & V_84 [ V_50 ] . V_83 ) {
F_63 ( & V_2 -> V_3 ) ;
break;
}
}
V_21 = V_2 -> V_21 ;
F_2 ( & V_2 -> V_3 ) ;
F_60 ( V_21 -> V_82 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = F_64 ( V_2 -> V_3 . V_83 ) ;
struct V_94 V_95 = { . V_96 = V_97 } ;
int V_74 = 0 ;
F_65 ( V_2 , & V_95 ) ;
if ( V_95 . V_98 )
return - V_89 ;
if ( V_93 -> V_99 )
V_74 = V_93 -> V_99 ( V_2 ) ;
if ( V_74 )
return V_74 ;
V_2 -> V_100 = true ;
return V_74 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_92 * V_93 = F_64 ( V_2 -> V_3 . V_83 ) ;
int V_74 = 0 ;
if ( V_93 -> V_101 )
V_74 = V_93 -> V_101 ( V_2 ) ;
if ( V_74 )
return V_74 ;
V_2 -> V_100 = false ;
return V_74 ;
}
static int F_66 ( struct V_1 * V_2 )
{
T_1 V_102 ;
int V_103 , V_104 , V_105 ;
int V_18 , V_106 = 0 ;
V_2 -> V_107 &= V_2 -> V_108 ;
V_102 = V_2 -> V_107 ;
V_104 = F_52 ( V_2 , V_109 ) ;
if ( V_104 < 0 )
return V_104 ;
V_103 = V_104 ;
V_104 &= ~ ( V_110 | V_111 | V_112 |
V_113 ) ;
V_104 |= F_67 ( V_102 ) ;
if ( V_104 != V_103 ) {
V_18 = F_68 ( V_2 , V_109 , V_104 ) ;
if ( V_18 < 0 )
return V_18 ;
V_106 = 1 ;
}
V_105 = F_52 ( V_2 , V_114 ) ;
if ( V_105 < 0 )
return V_105 ;
if ( ! ( V_105 & V_115 ) )
return V_106 ;
V_104 = F_52 ( V_2 , V_116 ) ;
if ( V_104 < 0 )
return V_104 ;
V_103 = V_104 ;
V_104 &= ~ ( V_117 | V_118 ) ;
if ( V_2 -> V_108 & ( V_119 |
V_120 ) ) {
V_104 |= F_69 ( V_102 ) ;
}
if ( V_104 != V_103 )
V_106 = 1 ;
V_18 = F_68 ( V_2 , V_116 , V_104 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_106 ;
}
int F_70 ( struct V_1 * V_2 )
{
int V_121 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_122 == V_2 -> V_27 )
V_121 |= V_123 ;
else if ( V_124 == V_2 -> V_27 )
V_121 |= V_125 ;
if ( V_126 == V_2 -> V_28 )
V_121 |= V_127 ;
return F_68 ( V_2 , V_75 , V_121 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_121 = F_52 ( V_2 , V_75 ) ;
if ( V_121 < 0 )
return V_121 ;
V_121 |= V_128 | V_129 ;
V_121 &= ~ V_130 ;
return F_68 ( V_2 , V_75 , V_121 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_131 ;
if ( V_35 != V_2 -> V_34 )
return F_70 ( V_2 ) ;
V_131 = F_66 ( V_2 ) ;
if ( V_131 < 0 )
return V_131 ;
if ( V_131 == 0 ) {
int V_121 = F_52 ( V_2 , V_75 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( ! ( V_121 & V_128 ) || ( V_121 & V_130 ) )
V_131 = 1 ;
}
if ( V_131 > 0 )
V_131 = F_71 ( V_2 ) ;
return V_131 ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_132 = F_52 ( V_2 , V_114 ) ;
return ( V_132 < 0 ) ? V_132 : ( V_132 & V_133 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_75 ( struct V_1 * V_2 )
{
int V_134 ;
V_134 = F_52 ( V_2 , V_114 ) ;
if ( V_134 < 0 )
return V_134 ;
V_134 = F_52 ( V_2 , V_114 ) ;
if ( V_134 < 0 )
return V_134 ;
if ( ( V_134 & V_135 ) == 0 )
V_2 -> V_31 = 0 ;
else
V_2 -> V_31 = 1 ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_104 ;
int V_18 ;
int V_136 ;
int V_137 = 0 ;
int V_138 ;
int V_139 = 0 ;
V_18 = F_75 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_140 = 0 ;
if ( V_35 == V_2 -> V_34 ) {
if ( V_2 -> V_108 & ( V_119
| V_120 ) ) {
V_137 = F_52 ( V_2 , V_141 ) ;
if ( V_137 < 0 )
return V_137 ;
V_104 = F_52 ( V_2 , V_116 ) ;
if ( V_104 < 0 )
return V_104 ;
V_2 -> V_140 =
F_77 ( V_137 ) ;
V_139 = V_137 & V_104 << 2 ;
}
V_136 = F_52 ( V_2 , V_142 ) ;
if ( V_136 < 0 )
return V_136 ;
V_2 -> V_140 |= F_78 ( V_136 ) ;
V_104 = F_52 ( V_2 , V_109 ) ;
if ( V_104 < 0 )
return V_104 ;
V_138 = V_136 & V_104 ;
V_2 -> V_27 = V_143 ;
V_2 -> V_28 = V_144 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_139 & ( V_145 | V_146 ) ) {
V_2 -> V_27 = V_122 ;
if ( V_139 & V_145 )
V_2 -> V_28 = V_126 ;
} else if ( V_138 & ( V_147 | V_148 ) ) {
V_2 -> V_27 = V_124 ;
if ( V_138 & V_147 )
V_2 -> V_28 = V_126 ;
} else
if ( V_138 & V_149 )
V_2 -> V_28 = V_126 ;
if ( V_2 -> V_28 == V_126 ) {
V_2 -> V_29 = V_136 & V_150 ? 1 : 0 ;
V_2 -> V_30 = V_136 & V_151 ? 1 : 0 ;
}
} else {
int V_152 = F_52 ( V_2 , V_75 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_152 & V_127 )
V_2 -> V_28 = V_126 ;
else
V_2 -> V_28 = V_144 ;
if ( V_152 & V_123 )
V_2 -> V_27 = V_122 ;
else if ( V_152 & V_125 )
V_2 -> V_27 = V_124 ;
else
V_2 -> V_27 = V_143 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_153 , V_154 ;
T_1 V_155 = V_2 -> V_25 . V_54 ;
V_2 -> V_31 = 1 ;
V_2 -> V_27 = V_156 ;
V_2 -> V_28 = V_126 ;
for ( V_153 = 0 ; V_155 ; V_153 ++ , V_155 = V_155 >> 1 ) {
if ( ! ( V_155 & 1 ) )
continue;
F_80 ( V_2 , V_153 , V_157 ) ;
V_154 = F_80 ( V_2 , V_153 , V_157 ) ;
if ( V_154 < 0 || ! ( V_154 & V_158 ) )
V_2 -> V_31 = 0 ;
}
return 0 ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_74 ;
V_74 = F_68 ( V_2 , V_75 , V_76 ) ;
if ( V_74 < 0 )
return V_74 ;
return F_50 ( V_2 ) ;
}
int F_81 ( struct V_1 * V_2 )
{
int V_159 ;
T_1 V_160 ;
V_160 = ( V_161 | V_162
| V_163 | V_164 |
V_165 ) ;
V_159 = F_52 ( V_2 , V_114 ) ;
if ( V_159 < 0 )
return V_159 ;
if ( V_159 & V_166 )
V_160 |= V_167 ;
if ( V_159 & V_168 )
V_160 |= V_169 ;
if ( V_159 & V_170 )
V_160 |= V_171 ;
if ( V_159 & V_172 )
V_160 |= V_173 ;
if ( V_159 & V_174 )
V_160 |= V_175 ;
if ( V_159 & V_115 ) {
V_159 = F_52 ( V_2 , V_176 ) ;
if ( V_159 < 0 )
return V_159 ;
if ( V_159 & V_177 )
V_160 |= V_120 ;
if ( V_159 & V_178 )
V_160 |= V_119 ;
}
V_2 -> V_108 &= V_160 ;
V_2 -> V_107 &= V_160 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
V_2 -> V_108 = V_179 ;
V_2 -> V_107 = V_179 ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_180 ;
F_10 ( & V_2 -> V_44 ) ;
V_180 = F_52 ( V_2 , V_75 ) ;
F_68 ( V_2 , V_75 , V_180 | V_181 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_86 ( struct V_1 * V_2 )
{
int V_180 ;
F_10 ( & V_2 -> V_44 ) ;
V_180 = F_52 ( V_2 , V_75 ) ;
F_68 ( V_2 , V_75 , V_180 & ~ V_181 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_182 * V_183 = V_2 -> V_3 . V_184 ;
T_1 V_185 ;
if ( ! F_89 ( V_186 ) )
return;
if ( ! V_183 )
return;
if ( ! F_90 ( V_183 , L_6 , & V_185 ) ) {
V_2 -> V_108 &= V_187 ;
switch ( V_185 ) {
default:
return;
case V_122 :
V_2 -> V_108 |= V_188 ;
case V_124 :
V_2 -> V_108 |= V_189 ;
case V_143 :
V_2 -> V_108 |= V_190 ;
}
}
}
static int F_91 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_191 * V_78 = V_2 -> V_3 . V_83 ;
struct V_92 * V_93 = F_64 ( V_78 ) ;
int V_18 = 0 ;
V_2 -> V_78 = V_93 ;
if ( ! ( V_93 -> V_81 & V_192 ) &&
F_92 ( V_2 ) )
V_2 -> V_38 = V_39 ;
if ( V_93 -> V_81 & V_193 )
V_2 -> V_194 = true ;
F_10 ( & V_2 -> V_44 ) ;
V_2 -> V_108 = V_93 -> V_160 ;
F_88 ( V_2 ) ;
V_2 -> V_107 = V_2 -> V_108 ;
V_2 -> V_42 = V_90 ;
if ( V_2 -> V_78 -> V_87 )
V_18 = V_2 -> V_78 -> V_87 ( V_2 ) ;
F_12 ( & V_2 -> V_44 ) ;
return V_18 ;
}
static int F_93 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
F_10 ( & V_2 -> V_44 ) ;
V_2 -> V_42 = V_43 ;
F_12 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_78 -> remove )
V_2 -> V_78 -> remove ( V_2 ) ;
V_2 -> V_78 = NULL ;
return 0 ;
}
int F_94 ( struct V_92 * V_195 )
{
int V_132 ;
V_195 -> V_83 . V_196 = V_195 -> V_196 ;
V_195 -> V_83 . V_21 = & V_37 ;
V_195 -> V_83 . V_87 = F_91 ;
V_195 -> V_83 . remove = F_93 ;
V_132 = F_95 ( & V_195 -> V_83 ) ;
if ( V_132 ) {
F_33 ( L_7 ,
V_195 -> V_196 , V_132 ) ;
return V_132 ;
}
F_96 ( L_8 , V_195 -> V_196 ) ;
return 0 ;
}
int F_97 ( struct V_92 * V_195 , int V_197 )
{
int V_50 , V_74 = 0 ;
for ( V_50 = 0 ; V_50 < V_197 ; V_50 ++ ) {
V_74 = F_94 ( V_195 + V_50 ) ;
if ( V_74 ) {
while ( V_50 -- > 0 )
F_98 ( V_195 + V_50 ) ;
break;
}
}
return V_74 ;
}
void F_98 ( struct V_92 * V_78 )
{
F_99 ( & V_78 -> V_83 ) ;
}
void F_100 ( struct V_92 * V_78 , int V_197 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_197 ; V_50 ++ )
F_98 ( V_78 + V_50 ) ;
}
static int T_3 F_101 ( void )
{
int V_69 ;
V_69 = F_102 () ;
if ( V_69 )
return V_69 ;
V_69 = F_97 ( V_84 ,
F_28 ( V_84 ) ) ;
if ( V_69 )
F_103 () ;
return V_69 ;
}
static void T_4 F_104 ( void )
{
F_100 ( V_84 ,
F_28 ( V_84 ) ) ;
F_103 () ;
}
