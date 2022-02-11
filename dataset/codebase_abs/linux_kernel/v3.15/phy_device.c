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
V_3 -> V_3 . V_36 = V_21 -> V_36 ;
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
V_51 = V_55 | V_50 << 16 | 6 ;
V_49 = F_29 ( V_21 , V_22 , V_51 ) ;
if ( V_49 < 0 )
return - V_56 ;
V_25 -> V_54 = ( V_49 & 0xffff ) << 16 ;
V_51 = V_55 | V_50 << 16 | 5 ;
V_49 = F_29 ( V_21 , V_22 , V_51 ) ;
if ( V_49 < 0 )
return - V_56 ;
V_25 -> V_54 |= ( V_49 & 0xffff ) ;
if ( ( V_25 -> V_54 & 0x1fffffff ) == 0x1fffffff ) {
* V_17 = 0xffffffff ;
return 0 ;
}
}
for ( V_50 = 1 ; V_50 < V_52 ; V_50 ++ ) {
if ( ! ( V_25 -> V_54 & ( 1 << V_50 ) ) )
continue;
V_51 = V_55 | V_50 << 16 | V_57 ;
V_49 = F_29 ( V_21 , V_22 , V_51 ) ;
if ( V_49 < 0 )
return - V_56 ;
V_25 -> V_53 [ V_50 ] = ( V_49 & 0xffff ) << 16 ;
V_51 = V_55 | V_50 << 16 | V_58 ;
V_49 = F_29 ( V_21 , V_22 , V_51 ) ;
if ( V_49 < 0 )
return - V_56 ;
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
V_49 = F_29 ( V_21 , V_22 , V_57 ) ;
if ( V_49 < 0 )
return - V_56 ;
* V_17 = ( V_49 & 0xffff ) << 16 ;
V_49 = F_29 ( V_21 , V_22 , V_58 ) ;
if ( V_49 < 0 )
return - V_56 ;
* V_17 |= ( V_49 & 0xffff ) ;
return 0 ;
}
struct V_1 * F_31 ( struct V_20 * V_21 , int V_22 , bool V_23 )
{
struct V_24 V_25 = { 0 } ;
T_1 V_17 = 0 ;
int V_59 ;
V_59 = F_30 ( V_21 , V_22 , & V_17 , V_23 , & V_25 ) ;
if ( V_59 )
return F_32 ( V_59 ) ;
if ( ( V_17 & 0x1fffffff ) == 0x1fffffff )
return NULL ;
return F_19 ( V_21 , V_22 , V_17 , V_23 , & V_25 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_21 -> V_60 [ V_2 -> V_22 ] )
return - V_61 ;
V_2 -> V_21 -> V_60 [ V_2 -> V_22 ] = V_2 ;
V_18 = F_34 ( V_2 ) ;
if ( V_18 ) {
F_35 ( L_1 , V_2 -> V_22 ) ;
goto V_62;
}
V_18 = F_36 ( & V_2 -> V_3 ) ;
if ( V_18 ) {
F_35 ( L_2 , V_2 -> V_22 ) ;
goto V_62;
}
return 0 ;
V_62:
V_2 -> V_21 -> V_60 [ V_2 -> V_22 ] = NULL ;
return V_18 ;
}
struct V_1 * F_37 ( struct V_20 * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_63 ; V_22 ++ ) {
if ( V_21 -> V_60 [ V_22 ] )
return V_21 -> V_60 [ V_22 ] ;
}
return NULL ;
}
static void F_38 ( struct V_1 * V_2 ,
void (* F_39)( struct V_64 * ) )
{
V_2 -> V_65 = F_39 ;
}
int F_40 ( struct V_64 * V_3 , struct V_1 * V_2 ,
void (* F_39)( struct V_64 * ) ,
T_2 V_32 )
{
int V_66 ;
V_66 = F_41 ( V_3 , V_2 , V_2 -> V_67 , V_32 ) ;
if ( V_66 )
return V_66 ;
F_38 ( V_2 , F_39 ) ;
F_42 ( V_2 ) ;
if ( V_2 -> V_38 > 0 )
F_43 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_44 ( struct V_64 * V_3 , const char * V_5 ,
void (* F_39)( struct V_64 * ) ,
T_2 V_32 )
{
struct V_1 * V_2 ;
struct V_4 * V_68 ;
int V_66 ;
V_68 = F_45 ( & V_37 , NULL , V_5 ) ;
if ( ! V_68 ) {
F_35 ( L_3 , V_5 ) ;
return F_32 ( - V_69 ) ;
}
V_2 = F_5 ( V_68 ) ;
V_66 = F_40 ( V_3 , V_2 , F_39 , V_32 ) ;
if ( V_66 )
return F_32 ( V_66 ) ;
return V_2 ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 > 0 )
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
V_2 -> V_65 = NULL ;
F_49 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
unsigned int V_70 = 12 ;
int V_71 ;
do {
F_51 ( 50 ) ;
V_71 = F_52 ( V_2 , V_72 ) ;
if ( V_71 < 0 )
return V_71 ;
} while ( V_71 & V_73 && -- V_70 );
if ( V_71 & V_73 )
return - V_74 ;
F_51 ( 1 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_71 = 0 ;
if ( ! V_2 -> V_75 || ! V_2 -> V_75 -> V_76 )
return 0 ;
if ( V_2 -> V_75 -> V_77 )
V_71 = V_2 -> V_75 -> V_77 ( V_2 ) ;
else
V_71 = F_53 ( V_2 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_17 ( V_2 ) ;
if ( V_71 < 0 )
return V_71 ;
return V_2 -> V_75 -> V_76 ( V_2 ) ;
}
int F_41 ( struct V_64 * V_3 , struct V_1 * V_2 ,
T_1 V_78 , T_2 V_32 )
{
struct V_4 * V_68 = & V_2 -> V_3 ;
int V_18 ;
if ( NULL == V_68 -> V_79 ) {
if ( V_2 -> V_23 )
V_68 -> V_79 = & V_80 [ V_81 ] . V_79 ;
else
V_68 -> V_79 = & V_80 [ V_82 ] . V_79 ;
V_18 = V_68 -> V_79 -> V_83 ( V_68 ) ;
if ( V_18 >= 0 )
V_18 = F_54 ( V_68 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_84 ) {
F_55 ( & V_3 -> V_3 , L_4 ) ;
return - V_85 ;
}
V_2 -> V_84 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_67 = V_78 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_42 = V_86 ;
V_18 = F_34 ( V_2 ) ;
if ( V_18 )
F_49 ( V_2 ) ;
else
F_56 ( V_2 ) ;
return V_18 ;
}
struct V_1 * F_57 ( struct V_64 * V_3 , const char * V_5 ,
T_2 V_32 )
{
struct V_87 * V_21 = & V_37 ;
struct V_1 * V_2 ;
struct V_4 * V_68 ;
int V_66 ;
V_68 = F_45 ( V_21 , NULL , V_5 ) ;
if ( ! V_68 ) {
F_35 ( L_3 , V_5 ) ;
return F_32 ( - V_69 ) ;
}
V_2 = F_5 ( V_68 ) ;
V_66 = F_41 ( V_3 , V_2 , V_2 -> V_67 , V_32 ) ;
if ( V_66 )
return F_32 ( V_66 ) ;
return V_2 ;
}
void F_49 ( struct V_1 * V_2 )
{
int V_50 ;
V_2 -> V_84 -> V_2 = NULL ;
V_2 -> V_84 = NULL ;
F_58 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < F_28 ( V_80 ) ; V_50 ++ ) {
if ( V_2 -> V_3 . V_79 == & V_80 [ V_50 ] . V_79 ) {
F_59 ( & V_2 -> V_3 ) ;
break;
}
}
}
int F_58 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = F_60 ( V_2 -> V_3 . V_79 ) ;
struct V_90 V_91 = { . V_92 = V_93 } ;
F_61 ( V_2 , & V_91 ) ;
if ( V_91 . V_94 )
return - V_85 ;
if ( V_89 -> V_95 )
return V_89 -> V_95 ( V_2 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = F_60 ( V_2 -> V_3 . V_79 ) ;
if ( V_89 -> V_96 )
return V_89 -> V_96 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
T_1 V_97 ;
int V_98 , V_99 , V_100 ;
int V_18 , V_101 = 0 ;
V_2 -> V_102 &= V_2 -> V_103 ;
V_97 = V_2 -> V_102 ;
V_99 = F_52 ( V_2 , V_104 ) ;
if ( V_99 < 0 )
return V_99 ;
V_98 = V_99 ;
V_99 &= ~ ( V_105 | V_106 | V_107 |
V_108 ) ;
V_99 |= F_63 ( V_97 ) ;
if ( V_99 != V_98 ) {
V_18 = F_64 ( V_2 , V_104 , V_99 ) ;
if ( V_18 < 0 )
return V_18 ;
V_101 = 1 ;
}
V_100 = F_52 ( V_2 , V_109 ) ;
if ( V_100 < 0 )
return V_100 ;
if ( ! ( V_100 & V_110 ) )
return V_101 ;
V_99 = F_52 ( V_2 , V_111 ) ;
if ( V_99 < 0 )
return V_99 ;
V_98 = V_99 ;
V_99 &= ~ ( V_112 | V_113 ) ;
if ( V_2 -> V_103 & ( V_114 |
V_115 ) ) {
V_99 |= F_65 ( V_97 ) ;
if ( V_99 != V_98 )
V_101 = 1 ;
}
V_18 = F_64 ( V_2 , V_111 , V_99 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_101 ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_116 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_117 == V_2 -> V_27 )
V_116 |= V_118 ;
else if ( V_119 == V_2 -> V_27 )
V_116 |= V_120 ;
if ( V_121 == V_2 -> V_28 )
V_116 |= V_122 ;
return F_64 ( V_2 , V_72 , V_116 ) ;
}
int F_67 ( struct V_1 * V_2 )
{
int V_116 = F_52 ( V_2 , V_72 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 |= V_123 | V_124 ;
V_116 &= ~ V_125 ;
return F_64 ( V_2 , V_72 , V_116 ) ;
}
int F_68 ( struct V_1 * V_2 )
{
int V_126 ;
if ( V_35 != V_2 -> V_34 )
return F_66 ( V_2 ) ;
V_126 = F_62 ( V_2 ) ;
if ( V_126 < 0 )
return V_126 ;
if ( V_126 == 0 ) {
int V_116 = F_52 ( V_2 , V_72 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( ! ( V_116 & V_123 ) || ( V_116 & V_125 ) )
V_126 = 1 ;
}
if ( V_126 > 0 )
V_126 = F_67 ( V_2 ) ;
return V_126 ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_127 = F_52 ( V_2 , V_109 ) ;
return ( V_127 < 0 ) ? V_127 : ( V_127 & V_128 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_129 ;
V_129 = F_52 ( V_2 , V_109 ) ;
if ( V_129 < 0 )
return V_129 ;
V_129 = F_52 ( V_2 , V_109 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( ( V_129 & V_130 ) == 0 )
V_2 -> V_31 = 0 ;
else
V_2 -> V_31 = 1 ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_99 ;
int V_18 ;
int V_131 ;
int V_132 = 0 ;
int V_133 ;
int V_134 = 0 ;
V_18 = F_71 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_135 = 0 ;
if ( V_35 == V_2 -> V_34 ) {
if ( V_2 -> V_103 & ( V_114
| V_115 ) ) {
V_132 = F_52 ( V_2 , V_136 ) ;
if ( V_132 < 0 )
return V_132 ;
V_99 = F_52 ( V_2 , V_111 ) ;
if ( V_99 < 0 )
return V_99 ;
V_2 -> V_135 =
F_73 ( V_132 ) ;
V_134 = V_132 & V_99 << 2 ;
}
V_131 = F_52 ( V_2 , V_137 ) ;
if ( V_131 < 0 )
return V_131 ;
V_2 -> V_135 |= F_74 ( V_131 ) ;
V_99 = F_52 ( V_2 , V_104 ) ;
if ( V_99 < 0 )
return V_99 ;
V_133 = V_131 & V_99 ;
V_2 -> V_27 = V_138 ;
V_2 -> V_28 = V_139 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_134 & ( V_140 | V_141 ) ) {
V_2 -> V_27 = V_117 ;
if ( V_134 & V_140 )
V_2 -> V_28 = V_121 ;
} else if ( V_133 & ( V_142 | V_143 ) ) {
V_2 -> V_27 = V_119 ;
if ( V_133 & V_142 )
V_2 -> V_28 = V_121 ;
} else
if ( V_133 & V_144 )
V_2 -> V_28 = V_121 ;
if ( V_2 -> V_28 == V_121 ) {
V_2 -> V_29 = V_131 & V_145 ? 1 : 0 ;
V_2 -> V_30 = V_131 & V_146 ? 1 : 0 ;
}
} else {
int V_147 = F_52 ( V_2 , V_72 ) ;
if ( V_147 < 0 )
return V_147 ;
if ( V_147 & V_122 )
V_2 -> V_28 = V_121 ;
else
V_2 -> V_28 = V_139 ;
if ( V_147 & V_118 )
V_2 -> V_27 = V_117 ;
else if ( V_147 & V_120 )
V_2 -> V_27 = V_119 ;
else
V_2 -> V_27 = V_138 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_148 , V_149 ;
T_1 V_150 = V_2 -> V_25 . V_54 ;
V_2 -> V_31 = 1 ;
V_2 -> V_27 = V_151 ;
V_2 -> V_28 = V_121 ;
for ( V_148 = 0 ; V_150 ; V_148 ++ , V_150 = V_150 >> 1 ) {
if ( ! ( V_150 & 1 ) )
continue;
F_76 ( V_2 , V_148 , V_152 ) ;
V_149 = F_76 ( V_2 , V_148 , V_152 ) ;
if ( V_149 < 0 || ! ( V_149 & V_153 ) )
V_2 -> V_31 = 0 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_71 ;
V_71 = F_64 ( V_2 , V_72 , V_73 ) ;
if ( V_71 < 0 )
return V_71 ;
return F_50 ( V_2 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_154 ;
T_1 V_155 ;
V_155 = ( V_156 | V_157
| V_158 | V_159 |
V_160 ) ;
V_154 = F_52 ( V_2 , V_109 ) ;
if ( V_154 < 0 )
return V_154 ;
if ( V_154 & V_161 )
V_155 |= V_162 ;
if ( V_154 & V_163 )
V_155 |= V_164 ;
if ( V_154 & V_165 )
V_155 |= V_166 ;
if ( V_154 & V_167 )
V_155 |= V_168 ;
if ( V_154 & V_169 )
V_155 |= V_170 ;
if ( V_154 & V_110 ) {
V_154 = F_52 ( V_2 , V_171 ) ;
if ( V_154 < 0 )
return V_154 ;
if ( V_154 & V_172 )
V_155 |= V_115 ;
if ( V_154 & V_173 )
V_155 |= V_114 ;
}
V_2 -> V_103 = V_155 ;
V_2 -> V_102 = V_155 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
V_2 -> V_103 = V_174 ;
V_2 -> V_102 = V_174 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_175 ;
F_10 ( & V_2 -> V_44 ) ;
V_175 = F_52 ( V_2 , V_72 ) ;
F_64 ( V_2 , V_72 , V_175 | V_176 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_175 ;
F_10 ( & V_2 -> V_44 ) ;
V_175 = F_52 ( V_2 , V_72 ) ;
F_64 ( V_2 , V_72 , V_175 & ~ V_176 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_84 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_177 * V_75 = V_2 -> V_3 . V_79 ;
struct V_88 * V_89 = F_60 ( V_75 ) ;
int V_18 = 0 ;
V_2 -> V_75 = V_89 ;
if ( ! ( V_89 -> V_78 & V_178 ) &&
F_85 ( V_2 ) )
V_2 -> V_38 = V_39 ;
if ( V_89 -> V_78 & V_179 )
V_2 -> V_180 = true ;
F_10 ( & V_2 -> V_44 ) ;
V_2 -> V_103 = V_89 -> V_155 ;
V_2 -> V_102 = V_89 -> V_155 ;
V_2 -> V_42 = V_86 ;
if ( V_2 -> V_75 -> V_83 )
V_18 = V_2 -> V_75 -> V_83 ( V_2 ) ;
F_12 ( & V_2 -> V_44 ) ;
return V_18 ;
}
static int F_86 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
F_10 ( & V_2 -> V_44 ) ;
V_2 -> V_42 = V_43 ;
F_12 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_75 -> remove )
V_2 -> V_75 -> remove ( V_2 ) ;
V_2 -> V_75 = NULL ;
return 0 ;
}
int F_87 ( struct V_88 * V_181 )
{
int V_127 ;
V_181 -> V_79 . V_182 = V_181 -> V_182 ;
V_181 -> V_79 . V_21 = & V_37 ;
V_181 -> V_79 . V_83 = F_84 ;
V_181 -> V_79 . remove = F_86 ;
V_127 = F_88 ( & V_181 -> V_79 ) ;
if ( V_127 ) {
F_35 ( L_5 ,
V_181 -> V_182 , V_127 ) ;
return V_127 ;
}
F_89 ( L_6 , V_181 -> V_182 ) ;
return 0 ;
}
int F_90 ( struct V_88 * V_181 , int V_183 )
{
int V_50 , V_71 = 0 ;
for ( V_50 = 0 ; V_50 < V_183 ; V_50 ++ ) {
V_71 = F_87 ( V_181 + V_50 ) ;
if ( V_71 ) {
while ( V_50 -- > 0 )
F_91 ( V_181 + V_50 ) ;
break;
}
}
return V_71 ;
}
void F_91 ( struct V_88 * V_75 )
{
F_92 ( & V_75 -> V_79 ) ;
}
void F_93 ( struct V_88 * V_75 , int V_183 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_183 ; V_50 ++ )
F_91 ( V_75 + V_50 ) ;
}
static int T_3 F_94 ( void )
{
int V_66 ;
V_66 = F_95 () ;
if ( V_66 )
return V_66 ;
V_66 = F_90 ( V_80 ,
F_28 ( V_80 ) ) ;
if ( V_66 )
F_96 () ;
return V_66 ;
}
static void T_4 F_97 ( void )
{
F_93 ( V_80 ,
F_28 ( V_80 ) ) ;
F_96 () ;
}
