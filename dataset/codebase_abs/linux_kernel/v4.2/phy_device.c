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
if ( NULL == V_3 )
return (struct V_1 * ) F_20 ( ( void * ) - V_11 ) ;
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
V_3 -> V_38 = V_21 -> V_38 != NULL ? V_21 -> V_38 [ V_22 ] : V_39 ;
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
return F_32 ( V_62 ) ;
if ( ( V_17 & 0x1fffffff ) == 0x1fffffff )
return NULL ;
return F_19 ( V_21 , V_22 , V_17 , V_23 , & V_25 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_21 -> V_63 [ V_2 -> V_22 ] )
return - V_64 ;
V_2 -> V_21 -> V_63 [ V_2 -> V_22 ] = V_2 ;
V_18 = F_17 ( V_2 ) ;
if ( V_18 ) {
F_34 ( L_1 , V_2 -> V_22 ) ;
goto V_65;
}
V_18 = F_35 ( & V_2 -> V_3 ) ;
if ( V_18 ) {
F_34 ( L_2 , V_2 -> V_22 ) ;
goto V_65;
}
return 0 ;
V_65:
V_2 -> V_21 -> V_63 [ V_2 -> V_22 ] = NULL ;
return V_18 ;
}
struct V_1 * F_36 ( struct V_20 * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_66 ; V_22 ++ ) {
if ( V_21 -> V_63 [ V_22 ] )
return V_21 -> V_63 [ V_22 ] ;
}
return NULL ;
}
static void F_37 ( struct V_1 * V_2 ,
void (* F_38)( struct V_67 * ) )
{
V_2 -> V_68 = F_38 ;
}
int F_39 ( struct V_67 * V_3 , struct V_1 * V_2 ,
void (* F_38)( struct V_67 * ) ,
T_2 V_32 )
{
int V_69 ;
V_69 = F_40 ( V_3 , V_2 , V_2 -> V_70 , V_32 ) ;
if ( V_69 )
return V_69 ;
F_37 ( V_2 , F_38 ) ;
F_41 ( V_2 ) ;
if ( V_2 -> V_38 > 0 )
F_42 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_43 ( struct V_67 * V_3 , const char * V_5 ,
void (* F_38)( struct V_67 * ) ,
T_2 V_32 )
{
struct V_1 * V_2 ;
struct V_4 * V_71 ;
int V_69 ;
V_71 = F_44 ( & V_37 , NULL , V_5 ) ;
if ( ! V_71 ) {
F_34 ( L_3 , V_5 ) ;
return F_32 ( - V_72 ) ;
}
V_2 = F_5 ( V_71 ) ;
V_69 = F_39 ( V_3 , V_2 , F_38 , V_32 ) ;
if ( V_69 )
return F_32 ( V_69 ) ;
return V_2 ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 > 0 )
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
V_2 -> V_68 = NULL ;
F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
unsigned int V_73 = 12 ;
int V_74 ;
do {
F_50 ( 50 ) ;
V_74 = F_51 ( V_2 , V_75 ) ;
if ( V_74 < 0 )
return V_74 ;
} while ( V_74 & V_76 && -- V_73 );
if ( V_74 & V_76 )
return - V_77 ;
F_50 ( 1 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_74 = 0 ;
if ( ! V_2 -> V_78 || ! V_2 -> V_78 -> V_79 )
return 0 ;
if ( V_2 -> V_78 -> V_80 )
V_74 = V_2 -> V_78 -> V_80 ( V_2 ) ;
else
V_74 = F_53 ( V_2 ) ;
if ( V_74 < 0 )
return V_74 ;
V_74 = F_17 ( V_2 ) ;
if ( V_74 < 0 )
return V_74 ;
return V_2 -> V_78 -> V_79 ( V_2 ) ;
}
int F_40 ( struct V_67 * V_3 , struct V_1 * V_2 ,
T_1 V_81 , T_2 V_32 )
{
struct V_4 * V_71 = & V_2 -> V_3 ;
struct V_82 * V_83 ;
int V_18 ;
if ( NULL == V_71 -> V_84 ) {
if ( V_2 -> V_23 )
V_71 -> V_84 = & V_85 [ V_86 ] . V_84 ;
else
V_71 -> V_84 = & V_85 [ V_87 ] . V_84 ;
V_18 = V_71 -> V_84 -> V_88 ( V_71 ) ;
if ( V_18 >= 0 )
V_18 = F_54 ( V_71 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_89 ) {
F_55 ( & V_3 -> V_3 , L_4 ) ;
return - V_90 ;
}
V_83 = V_2 -> V_21 -> V_3 . V_84 ?
V_2 -> V_21 -> V_3 . V_84 -> V_91 : NULL ;
if ( ! F_56 ( V_83 ) ) {
F_55 ( & V_3 -> V_3 , L_5 ) ;
return - V_58 ;
}
V_2 -> V_89 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_70 = V_81 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_42 = V_92 ;
V_18 = F_52 ( V_2 ) ;
if ( V_18 )
F_48 ( V_2 ) ;
else
F_57 ( V_2 ) ;
return V_18 ;
}
struct V_1 * F_58 ( struct V_67 * V_3 , const char * V_5 ,
T_2 V_32 )
{
struct V_93 * V_21 = & V_37 ;
struct V_1 * V_2 ;
struct V_4 * V_71 ;
int V_69 ;
V_71 = F_44 ( V_21 , NULL , V_5 ) ;
if ( ! V_71 ) {
F_34 ( L_3 , V_5 ) ;
return F_32 ( - V_72 ) ;
}
V_2 = F_5 ( V_71 ) ;
V_69 = F_40 ( V_3 , V_2 , V_2 -> V_70 , V_32 ) ;
if ( V_69 )
return F_32 ( V_69 ) ;
return V_2 ;
}
void F_48 ( struct V_1 * V_2 )
{
int V_50 ;
if ( V_2 -> V_21 -> V_3 . V_84 )
F_59 ( V_2 -> V_21 -> V_3 . V_84 -> V_91 ) ;
V_2 -> V_89 -> V_2 = NULL ;
V_2 -> V_89 = NULL ;
F_60 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < F_28 ( V_85 ) ; V_50 ++ ) {
if ( V_2 -> V_3 . V_84 == & V_85 [ V_50 ] . V_84 ) {
F_61 ( & V_2 -> V_3 ) ;
break;
}
}
}
int F_60 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = F_62 ( V_2 -> V_3 . V_84 ) ;
struct V_96 V_97 = { . V_98 = V_99 } ;
int V_74 = 0 ;
F_63 ( V_2 , & V_97 ) ;
if ( V_97 . V_100 )
return - V_90 ;
if ( V_95 -> V_101 )
V_74 = V_95 -> V_101 ( V_2 ) ;
if ( V_74 )
return V_74 ;
V_2 -> V_102 = true ;
return V_74 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = F_62 ( V_2 -> V_3 . V_84 ) ;
int V_74 = 0 ;
if ( V_95 -> V_103 )
V_74 = V_95 -> V_103 ( V_2 ) ;
if ( V_74 )
return V_74 ;
V_2 -> V_102 = false ;
return V_74 ;
}
static int F_64 ( struct V_1 * V_2 )
{
T_1 V_104 ;
int V_105 , V_106 , V_107 ;
int V_18 , V_108 = 0 ;
V_2 -> V_109 &= V_2 -> V_110 ;
V_104 = V_2 -> V_109 ;
V_106 = F_51 ( V_2 , V_111 ) ;
if ( V_106 < 0 )
return V_106 ;
V_105 = V_106 ;
V_106 &= ~ ( V_112 | V_113 | V_114 |
V_115 ) ;
V_106 |= F_65 ( V_104 ) ;
if ( V_106 != V_105 ) {
V_18 = F_66 ( V_2 , V_111 , V_106 ) ;
if ( V_18 < 0 )
return V_18 ;
V_108 = 1 ;
}
V_107 = F_51 ( V_2 , V_116 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( ! ( V_107 & V_117 ) )
return V_108 ;
V_106 = F_51 ( V_2 , V_118 ) ;
if ( V_106 < 0 )
return V_106 ;
V_105 = V_106 ;
V_106 &= ~ ( V_119 | V_120 ) ;
if ( V_2 -> V_110 & ( V_121 |
V_122 ) ) {
V_106 |= F_67 ( V_104 ) ;
}
if ( V_106 != V_105 )
V_108 = 1 ;
V_18 = F_66 ( V_2 , V_118 , V_106 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_108 ;
}
int F_68 ( struct V_1 * V_2 )
{
int V_123 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_124 == V_2 -> V_27 )
V_123 |= V_125 ;
else if ( V_126 == V_2 -> V_27 )
V_123 |= V_127 ;
if ( V_128 == V_2 -> V_28 )
V_123 |= V_129 ;
return F_66 ( V_2 , V_75 , V_123 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_123 = F_51 ( V_2 , V_75 ) ;
if ( V_123 < 0 )
return V_123 ;
V_123 |= V_130 | V_131 ;
V_123 &= ~ V_132 ;
return F_66 ( V_2 , V_75 , V_123 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
int V_133 ;
if ( V_35 != V_2 -> V_34 )
return F_68 ( V_2 ) ;
V_133 = F_64 ( V_2 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_133 == 0 ) {
int V_123 = F_51 ( V_2 , V_75 ) ;
if ( V_123 < 0 )
return V_123 ;
if ( ! ( V_123 & V_130 ) || ( V_123 & V_132 ) )
V_133 = 1 ;
}
if ( V_133 > 0 )
V_133 = F_69 ( V_2 ) ;
return V_133 ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_134 = F_51 ( V_2 , V_116 ) ;
return ( V_134 < 0 ) ? V_134 : ( V_134 & V_135 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_136 ;
V_136 = F_51 ( V_2 , V_116 ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_51 ( V_2 , V_116 ) ;
if ( V_136 < 0 )
return V_136 ;
if ( ( V_136 & V_137 ) == 0 )
V_2 -> V_31 = 0 ;
else
V_2 -> V_31 = 1 ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 )
{
int V_106 ;
int V_18 ;
int V_138 ;
int V_139 = 0 ;
int V_140 ;
int V_141 = 0 ;
V_18 = F_73 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_142 = 0 ;
if ( V_35 == V_2 -> V_34 ) {
if ( V_2 -> V_110 & ( V_121
| V_122 ) ) {
V_139 = F_51 ( V_2 , V_143 ) ;
if ( V_139 < 0 )
return V_139 ;
V_106 = F_51 ( V_2 , V_118 ) ;
if ( V_106 < 0 )
return V_106 ;
V_2 -> V_142 =
F_75 ( V_139 ) ;
V_141 = V_139 & V_106 << 2 ;
}
V_138 = F_51 ( V_2 , V_144 ) ;
if ( V_138 < 0 )
return V_138 ;
V_2 -> V_142 |= F_76 ( V_138 ) ;
V_106 = F_51 ( V_2 , V_111 ) ;
if ( V_106 < 0 )
return V_106 ;
V_140 = V_138 & V_106 ;
V_2 -> V_27 = V_145 ;
V_2 -> V_28 = V_146 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_141 & ( V_147 | V_148 ) ) {
V_2 -> V_27 = V_124 ;
if ( V_141 & V_147 )
V_2 -> V_28 = V_128 ;
} else if ( V_140 & ( V_149 | V_150 ) ) {
V_2 -> V_27 = V_126 ;
if ( V_140 & V_149 )
V_2 -> V_28 = V_128 ;
} else
if ( V_140 & V_151 )
V_2 -> V_28 = V_128 ;
if ( V_2 -> V_28 == V_128 ) {
V_2 -> V_29 = V_138 & V_152 ? 1 : 0 ;
V_2 -> V_30 = V_138 & V_153 ? 1 : 0 ;
}
} else {
int V_154 = F_51 ( V_2 , V_75 ) ;
if ( V_154 < 0 )
return V_154 ;
if ( V_154 & V_129 )
V_2 -> V_28 = V_128 ;
else
V_2 -> V_28 = V_146 ;
if ( V_154 & V_125 )
V_2 -> V_27 = V_124 ;
else if ( V_154 & V_127 )
V_2 -> V_27 = V_126 ;
else
V_2 -> V_27 = V_145 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_155 , V_156 ;
T_1 V_157 = V_2 -> V_25 . V_54 ;
V_2 -> V_31 = 1 ;
V_2 -> V_27 = V_158 ;
V_2 -> V_28 = V_128 ;
for ( V_155 = 0 ; V_157 ; V_155 ++ , V_157 = V_157 >> 1 ) {
if ( ! ( V_157 & 1 ) )
continue;
F_78 ( V_2 , V_155 , V_159 ) ;
V_156 = F_78 ( V_2 , V_155 , V_159 ) ;
if ( V_156 < 0 || ! ( V_156 & V_160 ) )
V_2 -> V_31 = 0 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_74 ;
V_74 = F_66 ( V_2 , V_75 , V_76 ) ;
if ( V_74 < 0 )
return V_74 ;
return F_49 ( V_2 ) ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_161 ;
T_1 V_162 ;
V_162 = ( V_163 | V_164
| V_165 | V_166 |
V_167 ) ;
V_161 = F_51 ( V_2 , V_116 ) ;
if ( V_161 < 0 )
return V_161 ;
if ( V_161 & V_168 )
V_162 |= V_169 ;
if ( V_161 & V_170 )
V_162 |= V_171 ;
if ( V_161 & V_172 )
V_162 |= V_173 ;
if ( V_161 & V_174 )
V_162 |= V_175 ;
if ( V_161 & V_176 )
V_162 |= V_177 ;
if ( V_161 & V_117 ) {
V_161 = F_51 ( V_2 , V_178 ) ;
if ( V_161 < 0 )
return V_161 ;
if ( V_161 & V_179 )
V_162 |= V_122 ;
if ( V_161 & V_180 )
V_162 |= V_121 ;
}
V_2 -> V_110 &= V_162 ;
V_2 -> V_109 &= V_162 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
V_2 -> V_110 = V_181 ;
V_2 -> V_109 = V_181 ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_182 ;
F_10 ( & V_2 -> V_44 ) ;
V_182 = F_51 ( V_2 , V_75 ) ;
F_66 ( V_2 , V_75 , V_182 | V_183 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_182 ;
F_10 ( & V_2 -> V_44 ) ;
V_182 = F_51 ( V_2 , V_75 ) ;
F_66 ( V_2 , V_75 , V_182 & ~ V_183 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_184 * V_185 = V_2 -> V_3 . V_186 ;
T_1 V_187 ;
if ( ! F_87 ( V_188 ) )
return;
if ( ! V_185 )
return;
if ( ! F_88 ( V_185 , L_6 , & V_187 ) ) {
V_2 -> V_110 &= V_189 ;
switch ( V_187 ) {
default:
return;
case V_124 :
V_2 -> V_110 |= V_190 ;
case V_126 :
V_2 -> V_110 |= V_191 ;
case V_145 :
V_2 -> V_110 |= V_192 ;
}
}
}
static int F_89 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_193 * V_78 = V_2 -> V_3 . V_84 ;
struct V_94 * V_95 = F_62 ( V_78 ) ;
int V_18 = 0 ;
V_2 -> V_78 = V_95 ;
if ( ! ( V_95 -> V_81 & V_194 ) &&
F_90 ( V_2 ) )
V_2 -> V_38 = V_39 ;
if ( V_95 -> V_81 & V_195 )
V_2 -> V_196 = true ;
F_10 ( & V_2 -> V_44 ) ;
V_2 -> V_110 = V_95 -> V_162 ;
F_86 ( V_2 ) ;
V_2 -> V_109 = V_2 -> V_110 ;
V_2 -> V_42 = V_92 ;
if ( V_2 -> V_78 -> V_88 )
V_18 = V_2 -> V_78 -> V_88 ( V_2 ) ;
F_12 ( & V_2 -> V_44 ) ;
return V_18 ;
}
static int F_91 ( struct V_4 * V_3 )
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
int F_92 ( struct V_94 * V_197 )
{
int V_134 ;
V_197 -> V_84 . V_198 = V_197 -> V_198 ;
V_197 -> V_84 . V_21 = & V_37 ;
V_197 -> V_84 . V_88 = F_89 ;
V_197 -> V_84 . remove = F_91 ;
V_134 = F_93 ( & V_197 -> V_84 ) ;
if ( V_134 ) {
F_34 ( L_7 ,
V_197 -> V_198 , V_134 ) ;
return V_134 ;
}
F_94 ( L_8 , V_197 -> V_198 ) ;
return 0 ;
}
int F_95 ( struct V_94 * V_197 , int V_199 )
{
int V_50 , V_74 = 0 ;
for ( V_50 = 0 ; V_50 < V_199 ; V_50 ++ ) {
V_74 = F_92 ( V_197 + V_50 ) ;
if ( V_74 ) {
while ( V_50 -- > 0 )
F_96 ( V_197 + V_50 ) ;
break;
}
}
return V_74 ;
}
void F_96 ( struct V_94 * V_78 )
{
F_97 ( & V_78 -> V_84 ) ;
}
void F_98 ( struct V_94 * V_78 , int V_199 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_199 ; V_50 ++ )
F_96 ( V_78 + V_50 ) ;
}
static int T_3 F_99 ( void )
{
int V_69 ;
V_69 = F_100 () ;
if ( V_69 )
return V_69 ;
V_69 = F_95 ( V_85 ,
F_28 ( V_85 ) ) ;
if ( V_69 )
F_101 () ;
return V_69 ;
}
static void T_4 F_102 ( void )
{
F_98 ( V_85 ,
F_28 ( V_85 ) ) ;
F_101 () ;
}
