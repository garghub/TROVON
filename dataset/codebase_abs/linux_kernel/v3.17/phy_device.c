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
V_18 = F_17 ( V_2 ) ;
if ( V_18 ) {
F_34 ( L_1 , V_2 -> V_22 ) ;
goto V_62;
}
V_18 = F_35 ( & V_2 -> V_3 ) ;
if ( V_18 ) {
F_34 ( L_2 , V_2 -> V_22 ) ;
goto V_62;
}
return 0 ;
V_62:
V_2 -> V_21 -> V_60 [ V_2 -> V_22 ] = NULL ;
return V_18 ;
}
struct V_1 * F_36 ( struct V_20 * V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_63 ; V_22 ++ ) {
if ( V_21 -> V_60 [ V_22 ] )
return V_21 -> V_60 [ V_22 ] ;
}
return NULL ;
}
static void F_37 ( struct V_1 * V_2 ,
void (* F_38)( struct V_64 * ) )
{
V_2 -> V_65 = F_38 ;
}
int F_39 ( struct V_64 * V_3 , struct V_1 * V_2 ,
void (* F_38)( struct V_64 * ) ,
T_2 V_32 )
{
int V_66 ;
V_66 = F_40 ( V_3 , V_2 , V_2 -> V_67 , V_32 ) ;
if ( V_66 )
return V_66 ;
F_37 ( V_2 , F_38 ) ;
F_41 ( V_2 ) ;
if ( V_2 -> V_38 > 0 )
F_42 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_43 ( struct V_64 * V_3 , const char * V_5 ,
void (* F_38)( struct V_64 * ) ,
T_2 V_32 )
{
struct V_1 * V_2 ;
struct V_4 * V_68 ;
int V_66 ;
V_68 = F_44 ( & V_37 , NULL , V_5 ) ;
if ( ! V_68 ) {
F_34 ( L_3 , V_5 ) ;
return F_32 ( - V_69 ) ;
}
V_2 = F_5 ( V_68 ) ;
V_66 = F_39 ( V_3 , V_2 , F_38 , V_32 ) ;
if ( V_66 )
return F_32 ( V_66 ) ;
return V_2 ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 > 0 )
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
V_2 -> V_65 = NULL ;
F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
unsigned int V_70 = 12 ;
int V_71 ;
do {
F_50 ( 50 ) ;
V_71 = F_51 ( V_2 , V_72 ) ;
if ( V_71 < 0 )
return V_71 ;
} while ( V_71 & V_73 && -- V_70 );
if ( V_71 & V_73 )
return - V_74 ;
F_50 ( 1 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
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
int F_40 ( struct V_64 * V_3 , struct V_1 * V_2 ,
T_1 V_78 , T_2 V_32 )
{
struct V_4 * V_68 = & V_2 -> V_3 ;
struct V_79 * V_80 ;
int V_18 ;
if ( NULL == V_68 -> V_81 ) {
if ( V_2 -> V_23 )
V_68 -> V_81 = & V_82 [ V_83 ] . V_81 ;
else
V_68 -> V_81 = & V_82 [ V_84 ] . V_81 ;
V_18 = V_68 -> V_81 -> V_85 ( V_68 ) ;
if ( V_18 >= 0 )
V_18 = F_54 ( V_68 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_86 ) {
F_55 ( & V_3 -> V_3 , L_4 ) ;
return - V_87 ;
}
V_80 = V_2 -> V_21 -> V_3 . V_81 ?
V_2 -> V_21 -> V_3 . V_81 -> V_88 : NULL ;
if ( ! F_56 ( V_80 ) ) {
F_55 ( & V_3 -> V_3 , L_5 ) ;
return - V_56 ;
}
V_2 -> V_86 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_67 = V_78 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_42 = V_89 ;
V_18 = F_52 ( V_2 ) ;
if ( V_18 )
F_48 ( V_2 ) ;
else
F_57 ( V_2 ) ;
return V_18 ;
}
struct V_1 * F_58 ( struct V_64 * V_3 , const char * V_5 ,
T_2 V_32 )
{
struct V_90 * V_21 = & V_37 ;
struct V_1 * V_2 ;
struct V_4 * V_68 ;
int V_66 ;
V_68 = F_44 ( V_21 , NULL , V_5 ) ;
if ( ! V_68 ) {
F_34 ( L_3 , V_5 ) ;
return F_32 ( - V_69 ) ;
}
V_2 = F_5 ( V_68 ) ;
V_66 = F_40 ( V_3 , V_2 , V_2 -> V_67 , V_32 ) ;
if ( V_66 )
return F_32 ( V_66 ) ;
return V_2 ;
}
void F_48 ( struct V_1 * V_2 )
{
int V_50 ;
if ( V_2 -> V_21 -> V_3 . V_81 )
F_59 ( V_2 -> V_21 -> V_3 . V_81 -> V_88 ) ;
V_2 -> V_86 -> V_2 = NULL ;
V_2 -> V_86 = NULL ;
F_60 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < F_28 ( V_82 ) ; V_50 ++ ) {
if ( V_2 -> V_3 . V_81 == & V_82 [ V_50 ] . V_81 ) {
F_61 ( & V_2 -> V_3 ) ;
break;
}
}
}
int F_60 ( struct V_1 * V_2 )
{
struct V_91 * V_92 = F_62 ( V_2 -> V_3 . V_81 ) ;
struct V_93 V_94 = { . V_95 = V_96 } ;
F_63 ( V_2 , & V_94 ) ;
if ( V_94 . V_97 )
return - V_87 ;
if ( V_92 -> V_98 )
return V_92 -> V_98 ( V_2 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_91 * V_92 = F_62 ( V_2 -> V_3 . V_81 ) ;
if ( V_92 -> V_99 )
return V_92 -> V_99 ( V_2 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
T_1 V_100 ;
int V_101 , V_102 , V_103 ;
int V_18 , V_104 = 0 ;
V_2 -> V_105 &= V_2 -> V_106 ;
V_100 = V_2 -> V_105 ;
V_102 = F_51 ( V_2 , V_107 ) ;
if ( V_102 < 0 )
return V_102 ;
V_101 = V_102 ;
V_102 &= ~ ( V_108 | V_109 | V_110 |
V_111 ) ;
V_102 |= F_65 ( V_100 ) ;
if ( V_102 != V_101 ) {
V_18 = F_66 ( V_2 , V_107 , V_102 ) ;
if ( V_18 < 0 )
return V_18 ;
V_104 = 1 ;
}
V_103 = F_51 ( V_2 , V_112 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( ! ( V_103 & V_113 ) )
return V_104 ;
V_102 = F_51 ( V_2 , V_114 ) ;
if ( V_102 < 0 )
return V_102 ;
V_101 = V_102 ;
V_102 &= ~ ( V_115 | V_116 ) ;
if ( V_2 -> V_106 & ( V_117 |
V_118 ) ) {
V_102 |= F_67 ( V_100 ) ;
if ( V_102 != V_101 )
V_104 = 1 ;
}
V_18 = F_66 ( V_2 , V_114 , V_102 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_104 ;
}
int F_68 ( struct V_1 * V_2 )
{
int V_119 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_120 == V_2 -> V_27 )
V_119 |= V_121 ;
else if ( V_122 == V_2 -> V_27 )
V_119 |= V_123 ;
if ( V_124 == V_2 -> V_28 )
V_119 |= V_125 ;
return F_66 ( V_2 , V_72 , V_119 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_119 = F_51 ( V_2 , V_72 ) ;
if ( V_119 < 0 )
return V_119 ;
V_119 |= V_126 | V_127 ;
V_119 &= ~ V_128 ;
return F_66 ( V_2 , V_72 , V_119 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
int V_129 ;
if ( V_35 != V_2 -> V_34 )
return F_68 ( V_2 ) ;
V_129 = F_64 ( V_2 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_129 == 0 ) {
int V_119 = F_51 ( V_2 , V_72 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( ! ( V_119 & V_126 ) || ( V_119 & V_128 ) )
V_129 = 1 ;
}
if ( V_129 > 0 )
V_129 = F_69 ( V_2 ) ;
return V_129 ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_130 = F_51 ( V_2 , V_112 ) ;
return ( V_130 < 0 ) ? V_130 : ( V_130 & V_131 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_132 ;
V_132 = F_51 ( V_2 , V_112 ) ;
if ( V_132 < 0 )
return V_132 ;
V_132 = F_51 ( V_2 , V_112 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( ( V_132 & V_133 ) == 0 )
V_2 -> V_31 = 0 ;
else
V_2 -> V_31 = 1 ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 )
{
int V_102 ;
int V_18 ;
int V_134 ;
int V_135 = 0 ;
int V_136 ;
int V_137 = 0 ;
V_18 = F_73 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_138 = 0 ;
if ( V_35 == V_2 -> V_34 ) {
if ( V_2 -> V_106 & ( V_117
| V_118 ) ) {
V_135 = F_51 ( V_2 , V_139 ) ;
if ( V_135 < 0 )
return V_135 ;
V_102 = F_51 ( V_2 , V_114 ) ;
if ( V_102 < 0 )
return V_102 ;
V_2 -> V_138 =
F_75 ( V_135 ) ;
V_137 = V_135 & V_102 << 2 ;
}
V_134 = F_51 ( V_2 , V_140 ) ;
if ( V_134 < 0 )
return V_134 ;
V_2 -> V_138 |= F_76 ( V_134 ) ;
V_102 = F_51 ( V_2 , V_107 ) ;
if ( V_102 < 0 )
return V_102 ;
V_136 = V_134 & V_102 ;
V_2 -> V_27 = V_141 ;
V_2 -> V_28 = V_142 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
if ( V_137 & ( V_143 | V_144 ) ) {
V_2 -> V_27 = V_120 ;
if ( V_137 & V_143 )
V_2 -> V_28 = V_124 ;
} else if ( V_136 & ( V_145 | V_146 ) ) {
V_2 -> V_27 = V_122 ;
if ( V_136 & V_145 )
V_2 -> V_28 = V_124 ;
} else
if ( V_136 & V_147 )
V_2 -> V_28 = V_124 ;
if ( V_2 -> V_28 == V_124 ) {
V_2 -> V_29 = V_134 & V_148 ? 1 : 0 ;
V_2 -> V_30 = V_134 & V_149 ? 1 : 0 ;
}
} else {
int V_150 = F_51 ( V_2 , V_72 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_150 & V_125 )
V_2 -> V_28 = V_124 ;
else
V_2 -> V_28 = V_142 ;
if ( V_150 & V_121 )
V_2 -> V_27 = V_120 ;
else if ( V_150 & V_123 )
V_2 -> V_27 = V_122 ;
else
V_2 -> V_27 = V_141 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_151 , V_152 ;
T_1 V_153 = V_2 -> V_25 . V_54 ;
V_2 -> V_31 = 1 ;
V_2 -> V_27 = V_154 ;
V_2 -> V_28 = V_124 ;
for ( V_151 = 0 ; V_153 ; V_151 ++ , V_153 = V_153 >> 1 ) {
if ( ! ( V_153 & 1 ) )
continue;
F_78 ( V_2 , V_151 , V_155 ) ;
V_152 = F_78 ( V_2 , V_151 , V_155 ) ;
if ( V_152 < 0 || ! ( V_152 & V_156 ) )
V_2 -> V_31 = 0 ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_71 ;
V_71 = F_66 ( V_2 , V_72 , V_73 ) ;
if ( V_71 < 0 )
return V_71 ;
return F_49 ( V_2 ) ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_157 ;
T_1 V_158 ;
V_158 = ( V_159 | V_160
| V_161 | V_162 |
V_163 ) ;
V_157 = F_51 ( V_2 , V_112 ) ;
if ( V_157 < 0 )
return V_157 ;
if ( V_157 & V_164 )
V_158 |= V_165 ;
if ( V_157 & V_166 )
V_158 |= V_167 ;
if ( V_157 & V_168 )
V_158 |= V_169 ;
if ( V_157 & V_170 )
V_158 |= V_171 ;
if ( V_157 & V_172 )
V_158 |= V_173 ;
if ( V_157 & V_113 ) {
V_157 = F_51 ( V_2 , V_174 ) ;
if ( V_157 < 0 )
return V_157 ;
if ( V_157 & V_175 )
V_158 |= V_118 ;
if ( V_157 & V_176 )
V_158 |= V_117 ;
}
V_2 -> V_106 &= V_158 ;
V_2 -> V_105 &= V_158 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
V_2 -> V_106 = V_177 ;
V_2 -> V_105 = V_177 ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_178 ;
F_10 ( & V_2 -> V_44 ) ;
V_178 = F_51 ( V_2 , V_72 ) ;
F_66 ( V_2 , V_72 , V_178 | V_179 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_178 ;
F_10 ( & V_2 -> V_44 ) ;
V_178 = F_51 ( V_2 , V_72 ) ;
F_66 ( V_2 , V_72 , V_178 & ~ V_179 ) ;
F_12 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_180 * V_181 = V_2 -> V_3 . V_182 ;
T_1 V_183 ;
if ( ! F_87 ( V_184 ) )
return;
if ( ! V_181 )
return;
if ( ! F_88 ( V_181 , L_6 , & V_183 ) ) {
V_2 -> V_106 &= V_185 ;
switch ( V_183 ) {
default:
return;
case V_120 :
V_2 -> V_106 |= V_186 ;
case V_122 :
V_2 -> V_106 |= V_187 ;
case V_141 :
V_2 -> V_106 |= V_188 ;
}
}
}
static int F_89 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_189 * V_75 = V_2 -> V_3 . V_81 ;
struct V_91 * V_92 = F_62 ( V_75 ) ;
int V_18 = 0 ;
V_2 -> V_75 = V_92 ;
if ( ! ( V_92 -> V_78 & V_190 ) &&
F_90 ( V_2 ) )
V_2 -> V_38 = V_39 ;
if ( V_92 -> V_78 & V_191 )
V_2 -> V_192 = true ;
F_10 ( & V_2 -> V_44 ) ;
V_2 -> V_106 = V_92 -> V_158 ;
F_86 ( V_2 ) ;
V_2 -> V_105 = V_2 -> V_106 ;
V_2 -> V_42 = V_89 ;
if ( V_2 -> V_75 -> V_85 )
V_18 = V_2 -> V_75 -> V_85 ( V_2 ) ;
F_12 ( & V_2 -> V_44 ) ;
return V_18 ;
}
static int F_91 ( struct V_4 * V_3 )
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
int F_92 ( struct V_91 * V_193 )
{
int V_130 ;
V_193 -> V_81 . V_194 = V_193 -> V_194 ;
V_193 -> V_81 . V_21 = & V_37 ;
V_193 -> V_81 . V_85 = F_89 ;
V_193 -> V_81 . remove = F_91 ;
V_130 = F_93 ( & V_193 -> V_81 ) ;
if ( V_130 ) {
F_34 ( L_7 ,
V_193 -> V_194 , V_130 ) ;
return V_130 ;
}
F_94 ( L_8 , V_193 -> V_194 ) ;
return 0 ;
}
int F_95 ( struct V_91 * V_193 , int V_195 )
{
int V_50 , V_71 = 0 ;
for ( V_50 = 0 ; V_50 < V_195 ; V_50 ++ ) {
V_71 = F_92 ( V_193 + V_50 ) ;
if ( V_71 ) {
while ( V_50 -- > 0 )
F_96 ( V_193 + V_50 ) ;
break;
}
}
return V_71 ;
}
void F_96 ( struct V_91 * V_75 )
{
F_97 ( & V_75 -> V_81 ) ;
}
void F_98 ( struct V_91 * V_75 , int V_195 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_195 ; V_50 ++ )
F_96 ( V_75 + V_50 ) ;
}
static int T_3 F_99 ( void )
{
int V_66 ;
V_66 = F_100 () ;
if ( V_66 )
return V_66 ;
V_66 = F_95 ( V_82 ,
F_28 ( V_82 ) ) ;
if ( V_66 )
F_101 () ;
return V_66 ;
}
static void T_4 F_102 ( void )
{
F_98 ( V_82 ,
F_28 ( V_82 ) ) ;
F_101 () ;
}
