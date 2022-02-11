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
}
}
F_12 ( & V_12 ) ;
return 0 ;
}
struct V_1 * F_19 ( struct V_19 * V_20 , int V_21 , int V_17 ,
bool V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_3 ;
V_3 = F_8 ( sizeof( * V_3 ) , V_10 ) ;
if ( NULL == V_3 )
return (struct V_1 * ) F_20 ( ( void * ) - V_11 ) ;
V_3 -> V_3 . V_25 = F_3 ;
V_3 -> V_26 = 0 ;
V_3 -> V_27 = - 1 ;
V_3 -> V_28 = 0 ;
V_3 -> V_29 = 0 ;
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
T_1 V_17 = 0 ;
int V_58 ;
V_58 = F_30 ( V_20 , V_21 , & V_17 , V_22 , & V_24 ) ;
if ( V_58 )
return F_32 ( V_58 ) ;
if ( ( V_17 & 0x1fffffff ) == 0x1fffffff )
return NULL ;
return F_19 ( V_20 , V_21 , V_17 , V_22 , & V_24 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_20 -> V_59 [ V_2 -> V_21 ] )
return - V_60 ;
V_2 -> V_20 -> V_59 [ V_2 -> V_21 ] = V_2 ;
V_18 = F_34 ( V_2 ) ;
if ( V_18 ) {
F_35 ( L_1 , V_2 -> V_21 ) ;
goto V_61;
}
V_18 = F_36 ( & V_2 -> V_3 ) ;
if ( V_18 ) {
F_35 ( L_2 , V_2 -> V_21 ) ;
goto V_61;
}
return 0 ;
V_61:
V_2 -> V_20 -> V_59 [ V_2 -> V_21 ] = NULL ;
return V_18 ;
}
struct V_1 * F_37 ( struct V_19 * V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_62 ; V_21 ++ ) {
if ( V_20 -> V_59 [ V_21 ] )
return V_20 -> V_59 [ V_21 ] ;
}
return NULL ;
}
static void F_38 ( struct V_1 * V_2 ,
void (* F_39)( struct V_63 * ) )
{
V_2 -> V_64 = F_39 ;
}
int F_40 ( struct V_63 * V_3 , struct V_1 * V_2 ,
void (* F_39)( struct V_63 * ) ,
T_2 V_31 )
{
int V_65 ;
V_65 = F_41 ( V_3 , V_2 , V_2 -> V_66 , V_31 ) ;
if ( V_65 )
return V_65 ;
F_38 ( V_2 , F_39 ) ;
F_42 ( V_2 ) ;
if ( V_2 -> V_37 > 0 )
F_43 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_44 ( struct V_63 * V_3 , const char * V_5 ,
void (* F_39)( struct V_63 * ) ,
T_2 V_31 )
{
struct V_1 * V_2 ;
struct V_4 * V_67 ;
int V_65 ;
V_67 = F_45 ( & V_36 , NULL , V_5 ) ;
if ( ! V_67 ) {
F_35 ( L_3 , V_5 ) ;
return F_32 ( - V_68 ) ;
}
V_2 = F_5 ( V_67 ) ;
V_65 = F_40 ( V_3 , V_2 , F_39 , V_31 ) ;
if ( V_65 )
return F_32 ( V_65 ) ;
return V_2 ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 > 0 )
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
V_2 -> V_64 = NULL ;
F_49 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
unsigned int V_69 = 12 ;
int V_70 ;
do {
F_51 ( 50 ) ;
V_70 = F_52 ( V_2 , V_71 ) ;
if ( V_70 < 0 )
return V_70 ;
} while ( V_70 & V_72 && -- V_69 );
if ( V_70 & V_72 )
return - V_73 ;
F_51 ( 1 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_70 ;
if ( ! V_2 -> V_74 || ! V_2 -> V_74 -> V_75 )
return 0 ;
V_70 = F_53 ( V_2 , V_71 , V_72 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_50 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_17 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
return V_2 -> V_74 -> V_75 ( V_2 ) ;
}
int F_41 ( struct V_63 * V_3 , struct V_1 * V_2 ,
T_1 V_76 , T_2 V_31 )
{
struct V_4 * V_67 = & V_2 -> V_3 ;
int V_18 ;
if ( NULL == V_67 -> V_77 ) {
if ( V_2 -> V_22 )
V_67 -> V_77 = & V_78 [ V_79 ] . V_77 ;
else
V_67 -> V_77 = & V_78 [ V_80 ] . V_77 ;
V_18 = V_67 -> V_77 -> V_81 ( V_67 ) ;
if ( V_18 >= 0 )
V_18 = F_54 ( V_67 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_82 ) {
F_55 ( & V_3 -> V_3 , L_4 ) ;
return - V_83 ;
}
V_2 -> V_82 = V_3 ;
V_3 -> V_2 = V_2 ;
V_2 -> V_66 = V_76 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_41 = V_84 ;
V_18 = F_34 ( V_2 ) ;
if ( V_18 )
F_49 ( V_2 ) ;
F_56 ( V_2 ) ;
return V_18 ;
}
struct V_1 * F_57 ( struct V_63 * V_3 , const char * V_5 ,
T_2 V_31 )
{
struct V_85 * V_20 = & V_36 ;
struct V_1 * V_2 ;
struct V_4 * V_67 ;
int V_65 ;
V_67 = F_45 ( V_20 , NULL , V_5 ) ;
if ( ! V_67 ) {
F_35 ( L_3 , V_5 ) ;
return F_32 ( - V_68 ) ;
}
V_2 = F_5 ( V_67 ) ;
V_65 = F_41 ( V_3 , V_2 , V_2 -> V_66 , V_31 ) ;
if ( V_65 )
return F_32 ( V_65 ) ;
return V_2 ;
}
void F_49 ( struct V_1 * V_2 )
{
int V_49 ;
V_2 -> V_82 -> V_2 = NULL ;
V_2 -> V_82 = NULL ;
F_58 ( V_2 ) ;
for ( V_49 = 0 ; V_49 < F_28 ( V_78 ) ; V_49 ++ ) {
if ( V_2 -> V_3 . V_77 == & V_78 [ V_49 ] . V_77 ) {
F_59 ( & V_2 -> V_3 ) ;
break;
}
}
}
int F_58 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = F_60 ( V_2 -> V_3 . V_77 ) ;
struct V_88 V_89 = { . V_90 = V_91 } ;
F_61 ( V_2 , & V_89 ) ;
if ( V_89 . V_92 )
return - V_83 ;
if ( V_87 -> V_93 )
return V_87 -> V_93 ( V_2 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_86 * V_87 = F_60 ( V_2 -> V_3 . V_77 ) ;
if ( V_87 -> V_94 )
return V_87 -> V_94 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
T_1 V_95 ;
int V_96 , V_97 , V_98 ;
int V_18 , V_99 = 0 ;
V_2 -> V_100 &= V_2 -> V_101 ;
V_95 = V_2 -> V_100 ;
V_97 = F_52 ( V_2 , V_102 ) ;
if ( V_97 < 0 )
return V_97 ;
V_96 = V_97 ;
V_97 &= ~ ( V_103 | V_104 | V_105 |
V_106 ) ;
V_97 |= F_63 ( V_95 ) ;
if ( V_97 != V_96 ) {
V_18 = F_53 ( V_2 , V_102 , V_97 ) ;
if ( V_18 < 0 )
return V_18 ;
V_99 = 1 ;
}
V_98 = F_52 ( V_2 , V_107 ) ;
if ( V_98 < 0 )
return V_98 ;
if ( ! ( V_98 & V_108 ) )
return V_99 ;
V_97 = F_52 ( V_2 , V_109 ) ;
if ( V_97 < 0 )
return V_97 ;
V_96 = V_97 ;
V_97 &= ~ ( V_110 | V_111 ) ;
if ( V_2 -> V_101 & ( V_112 |
V_113 ) ) {
V_97 |= F_64 ( V_95 ) ;
if ( V_97 != V_96 )
V_99 = 1 ;
}
V_18 = F_53 ( V_2 , V_109 , V_97 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_99 ;
}
int F_65 ( struct V_1 * V_2 )
{
int V_114 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
if ( V_115 == V_2 -> V_26 )
V_114 |= V_116 ;
else if ( V_117 == V_2 -> V_26 )
V_114 |= V_118 ;
if ( V_119 == V_2 -> V_27 )
V_114 |= V_120 ;
return F_53 ( V_2 , V_71 , V_114 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_114 = F_52 ( V_2 , V_71 ) ;
if ( V_114 < 0 )
return V_114 ;
V_114 |= V_121 | V_122 ;
V_114 &= ~ V_123 ;
return F_53 ( V_2 , V_71 , V_114 ) ;
}
int F_67 ( struct V_1 * V_2 )
{
int V_124 ;
if ( V_34 != V_2 -> V_33 )
return F_65 ( V_2 ) ;
V_124 = F_62 ( V_2 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_124 == 0 ) {
int V_114 = F_52 ( V_2 , V_71 ) ;
if ( V_114 < 0 )
return V_114 ;
if ( ! ( V_114 & V_121 ) || ( V_114 & V_123 ) )
V_124 = 1 ;
}
if ( V_124 > 0 )
V_124 = F_66 ( V_2 ) ;
return V_124 ;
}
static int F_68 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_125 ;
V_125 = F_52 ( V_2 , V_107 ) ;
if ( V_125 < 0 )
return V_125 ;
V_125 = F_52 ( V_2 , V_107 ) ;
if ( V_125 < 0 )
return V_125 ;
if ( ( V_125 & V_126 ) == 0 )
V_2 -> V_30 = 0 ;
else
V_2 -> V_30 = 1 ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 )
{
int V_97 ;
int V_18 ;
int V_127 ;
int V_128 = 0 ;
int V_129 ;
int V_130 = 0 ;
V_18 = F_69 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_131 = 0 ;
if ( V_34 == V_2 -> V_33 ) {
if ( V_2 -> V_101 & ( V_112
| V_113 ) ) {
V_128 = F_52 ( V_2 , V_132 ) ;
if ( V_128 < 0 )
return V_128 ;
V_97 = F_52 ( V_2 , V_109 ) ;
if ( V_97 < 0 )
return V_97 ;
V_2 -> V_131 =
F_71 ( V_128 ) ;
V_130 = V_128 & V_97 << 2 ;
}
V_127 = F_52 ( V_2 , V_133 ) ;
if ( V_127 < 0 )
return V_127 ;
V_2 -> V_131 |= F_72 ( V_127 ) ;
V_97 = F_52 ( V_2 , V_102 ) ;
if ( V_97 < 0 )
return V_97 ;
V_129 = V_127 & V_97 ;
V_2 -> V_26 = V_134 ;
V_2 -> V_27 = V_135 ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
if ( V_130 & ( V_136 | V_137 ) ) {
V_2 -> V_26 = V_115 ;
if ( V_130 & V_136 )
V_2 -> V_27 = V_119 ;
} else if ( V_129 & ( V_138 | V_139 ) ) {
V_2 -> V_26 = V_117 ;
if ( V_129 & V_138 )
V_2 -> V_27 = V_119 ;
} else
if ( V_129 & V_140 )
V_2 -> V_27 = V_119 ;
if ( V_2 -> V_27 == V_119 ) {
V_2 -> V_28 = V_127 & V_141 ? 1 : 0 ;
V_2 -> V_29 = V_127 & V_142 ? 1 : 0 ;
}
} else {
int V_143 = F_52 ( V_2 , V_71 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_143 & V_120 )
V_2 -> V_27 = V_119 ;
else
V_2 -> V_27 = V_135 ;
if ( V_143 & V_116 )
V_2 -> V_26 = V_115 ;
else if ( V_143 & V_118 )
V_2 -> V_26 = V_117 ;
else
V_2 -> V_26 = V_134 ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_144 , V_145 ;
T_1 V_146 = V_2 -> V_24 . V_53 ;
V_2 -> V_30 = 1 ;
V_2 -> V_26 = V_147 ;
V_2 -> V_27 = V_119 ;
for ( V_144 = 0 ; V_146 ; V_144 ++ , V_146 = V_146 >> 1 ) {
if ( ! ( V_146 & 1 ) )
continue;
F_74 ( V_2 , V_144 , V_148 ) ;
V_145 = F_74 ( V_2 , V_144 , V_148 ) ;
if ( V_145 < 0 || ! ( V_145 & V_149 ) )
V_2 -> V_30 = 0 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_150 ;
T_1 V_151 ;
V_151 = ( V_152 | V_153
| V_154 | V_155 |
V_156 ) ;
V_150 = F_52 ( V_2 , V_107 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_150 & V_157 )
V_151 |= V_158 ;
if ( V_150 & V_159 )
V_151 |= V_160 ;
if ( V_150 & V_161 )
V_151 |= V_162 ;
if ( V_150 & V_163 )
V_151 |= V_164 ;
if ( V_150 & V_165 )
V_151 |= V_166 ;
if ( V_150 & V_108 ) {
V_150 = F_52 ( V_2 , V_167 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_150 & V_168 )
V_151 |= V_113 ;
if ( V_150 & V_169 )
V_151 |= V_112 ;
}
V_2 -> V_101 = V_151 ;
V_2 -> V_100 = V_151 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
V_2 -> V_101 = V_170 ;
V_2 -> V_100 = V_170 ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 )
{
int V_171 ;
F_10 ( & V_2 -> V_43 ) ;
V_171 = F_52 ( V_2 , V_71 ) ;
F_53 ( V_2 , V_71 , V_171 | V_172 ) ;
F_12 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_171 ;
F_10 ( & V_2 -> V_43 ) ;
V_171 = F_52 ( V_2 , V_71 ) ;
F_53 ( V_2 , V_71 , V_171 & ~ V_172 ) ;
F_12 ( & V_2 -> V_43 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_81 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
struct V_173 * V_74 = V_2 -> V_3 . V_77 ;
struct V_86 * V_87 = F_60 ( V_74 ) ;
int V_18 = 0 ;
V_2 -> V_74 = V_87 ;
if ( ! ( V_87 -> V_76 & V_174 ) &&
F_82 ( V_2 ) )
V_2 -> V_37 = V_38 ;
if ( V_87 -> V_76 & V_175 )
V_2 -> V_176 = true ;
F_10 ( & V_2 -> V_43 ) ;
V_2 -> V_101 = V_87 -> V_151 ;
V_2 -> V_100 = V_87 -> V_151 ;
V_2 -> V_41 = V_84 ;
if ( V_2 -> V_74 -> V_81 )
V_18 = V_2 -> V_74 -> V_81 ( V_2 ) ;
F_12 ( & V_2 -> V_43 ) ;
return V_18 ;
}
static int F_83 ( struct V_4 * V_3 )
{
struct V_1 * V_2 = F_5 ( V_3 ) ;
F_10 ( & V_2 -> V_43 ) ;
V_2 -> V_41 = V_42 ;
F_12 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_74 -> remove )
V_2 -> V_74 -> remove ( V_2 ) ;
V_2 -> V_74 = NULL ;
return 0 ;
}
int F_84 ( struct V_86 * V_177 )
{
int V_178 ;
V_177 -> V_77 . V_179 = V_177 -> V_179 ;
V_177 -> V_77 . V_20 = & V_36 ;
V_177 -> V_77 . V_81 = F_81 ;
V_177 -> V_77 . remove = F_83 ;
V_178 = F_85 ( & V_177 -> V_77 ) ;
if ( V_178 ) {
F_35 ( L_5 ,
V_177 -> V_179 , V_178 ) ;
return V_178 ;
}
F_86 ( L_6 , V_177 -> V_179 ) ;
return 0 ;
}
int F_87 ( struct V_86 * V_177 , int V_180 )
{
int V_49 , V_70 = 0 ;
for ( V_49 = 0 ; V_49 < V_180 ; V_49 ++ ) {
V_70 = F_84 ( V_177 + V_49 ) ;
if ( V_70 ) {
while ( V_49 -- > 0 )
F_88 ( V_177 + V_49 ) ;
break;
}
}
return V_70 ;
}
void F_88 ( struct V_86 * V_74 )
{
F_89 ( & V_74 -> V_77 ) ;
}
void F_90 ( struct V_86 * V_74 , int V_180 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_180 ; V_49 ++ )
F_88 ( V_74 + V_49 ) ;
}
static int T_3 F_91 ( void )
{
int V_65 ;
V_65 = F_92 () ;
if ( V_65 )
return V_65 ;
V_65 = F_87 ( V_78 ,
F_28 ( V_78 ) ) ;
if ( V_65 )
F_93 () ;
return V_65 ;
}
static void T_4 F_94 ( void )
{
F_90 ( V_78 ,
F_28 ( V_78 ) ) ;
F_93 () ;
}
