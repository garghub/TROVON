static int F_1 ( int V_1 , struct V_2 * V_3 )
{
enum V_4 V_5 = V_6 ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_11 -> V_10 ;
unsigned long V_12 ;
int V_13 , V_14 = 0 ;
F_2 ( & V_8 -> V_15 , V_12 ) ;
for ( V_13 = V_16 ; V_13 < V_17 ; V_13 ++ ) {
if ( V_8 -> V_3 [ V_13 ] != NULL )
continue;
V_5 = V_13 ;
if ( V_13 != V_18 )
break;
}
if ( V_5 == V_6 ) {
F_3 ( V_10 , L_1 ) ;
V_14 = - V_19 ;
} else if ( V_8 -> V_20 < V_1 ) {
F_3 ( V_10 , L_2 , V_1 ) ;
V_14 = - V_21 ;
} else {
V_8 -> V_20 -= V_1 ;
V_8 -> V_3 [ V_5 ] = V_3 ;
V_3 -> V_1 = V_1 ;
V_3 -> V_5 = V_5 ;
}
F_4 ( & V_8 -> V_15 , V_12 ) ;
return V_14 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
enum V_4 V_5 = V_3 -> V_5 ;
unsigned long V_12 ;
F_6 ( V_8 -> V_22 , V_23 ,
F_7 ( V_5 ) , 0 ) ;
F_2 ( & V_8 -> V_15 , V_12 ) ;
V_8 -> V_20 += V_3 -> V_1 ;
V_8 -> V_3 [ V_5 ] = NULL ;
V_3 -> error = 0 ;
F_4 ( & V_8 -> V_15 , V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 , T_1 V_24 , T_1 V_25 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
enum V_4 V_5 = V_3 -> V_5 ;
F_6 ( V_8 -> V_22 , F_9 ( V_5 ) ,
V_26 |
V_27 |
V_28 ,
V_29 |
F_10 ( V_24 ) |
F_11 ( V_25 ) ) ;
}
static T_1 F_12 ( struct V_2 * V_3 , T_1 div )
{
T_1 V_30 ;
for ( V_30 = 0 ; div > 8 ; V_30 ++ )
div >>= 1 ;
return ( ( div - 1 ) << V_31 ) | V_30 ;
}
static int F_13 ( struct V_2 * V_3 ,
int V_32 , int V_33 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
enum V_4 V_5 = V_3 -> V_5 ;
unsigned long V_34 ;
int V_13 ;
if ( ! V_33 ) {
F_14 ( L_3 ) ;
return - V_21 ;
}
V_34 = ( V_32 / V_33 ) << V_35 ;
V_32 %= V_33 ;
for ( V_13 = 1 ; V_13 <= V_35 ; V_13 ++ ) {
V_32 <<= 1 ;
if ( V_32 < V_33 )
continue;
V_34 |= 1 << ( V_35 - V_13 ) ;
V_32 -= V_33 ;
if ( ! V_32 )
break;
}
F_15 ( V_8 -> V_22 , F_16 ( V_5 ) , V_34 ) ;
F_15 ( V_8 -> V_22 , F_17 ( V_5 ) , V_34 >> 24 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = V_3 -> V_37 ;
struct V_7 * V_8 = V_3 -> V_8 ;
enum V_4 V_5 = V_3 -> V_5 ;
T_1 V_32 , V_33 , V_38 , V_39 ;
T_1 V_40 [ 2 ] , div [ 2 ] ;
int V_24 , V_25 , V_1 ;
struct V_41 * V_41 ;
bool V_42 ;
if ( ! V_37 ) {
F_14 ( L_4 ) ;
return - V_21 ;
}
if ( V_37 -> V_43 < 1 || V_37 -> V_43 > 10 ) {
F_14 ( L_5 , V_37 -> V_43 ) ;
return - V_21 ;
}
if ( V_37 -> V_44 == V_45 ) {
F_14 ( L_6 ) ;
return - V_21 ;
}
V_32 = V_37 -> V_46 ;
V_33 = V_37 -> V_47 ;
V_42 = V_37 -> V_48 == V_49 ;
for ( V_24 = 0 ; V_24 < F_19 ( V_50 ) ; V_24 ++ )
if ( V_32 == V_50 [ V_24 ] )
break;
if ( V_24 == F_19 ( V_50 ) ) {
F_14 ( L_7 , V_32 ) ;
return - V_21 ;
}
for ( V_25 = 0 ; V_25 < F_19 ( V_51 ) ; V_25 ++ )
if ( V_33 == V_51 [ V_25 ] )
break;
if ( V_25 == F_19 ( V_51 ) ) {
F_14 ( L_8 , V_33 ) ;
return - V_21 ;
}
V_40 [ V_52 ] = V_53 [ V_52 ] [ V_37 -> V_48 ] ;
V_40 [ V_54 ] = V_53 [ V_54 ] [ V_37 -> V_55 ] ;
V_41 = V_8 -> V_56 [ V_40 [ V_42 ? V_54 : V_52 ] ] ;
div [ V_52 ] = F_20 ( V_41 ) / V_32 ;
if ( div [ V_52 ] == 0 ) {
F_14 ( L_9 ,
V_32 , V_40 [ V_42 ? V_54 : V_52 ] ) ;
return - V_21 ;
}
V_41 = V_8 -> V_56 [ V_40 [ V_54 ] ] ;
if ( V_42 )
div [ V_54 ] = F_20 ( V_41 ) / V_57 ;
else
div [ V_54 ] = F_20 ( V_41 ) / V_33 ;
if ( div [ V_54 ] == 0 ) {
F_14 ( L_10 ,
V_33 , V_40 [ V_54 ] ) ;
return - V_21 ;
}
V_1 = V_37 -> V_43 ;
if ( V_8 -> V_58 < 4 )
V_1 /= 2 ;
F_6 ( V_8 -> V_22 , V_59 ,
F_21 ( V_5 , V_8 -> V_58 ) ,
F_22 ( V_5 , V_1 , V_8 -> V_58 ) ) ;
F_6 ( V_8 -> V_22 , V_23 ,
F_23 ( V_5 ) , F_24 ( V_5 ) ) ;
F_6 ( V_8 -> V_22 , V_23 ,
F_25 ( V_5 ) , 0 ) ;
F_6 ( V_8 -> V_22 , V_60 ,
F_26 ( V_5 ) | F_27 ( V_5 ) ,
F_28 ( V_5 , V_40 [ V_52 ] ) |
F_29 ( V_5 , V_40 [ V_54 ] ) ) ;
V_38 = F_12 ( V_3 , div [ V_52 ] ) ;
V_39 = F_12 ( V_3 , div [ V_54 ] ) ;
F_6 ( V_8 -> V_22 , F_30 ( V_5 ) ,
F_31 ( V_5 ) | F_32 ( V_5 ) |
F_33 ( V_5 ) | F_34 ( V_5 ) ,
F_35 ( V_5 , V_39 ) | F_36 ( V_5 , V_38 ) ) ;
F_6 ( V_8 -> V_22 , F_37 ( V_5 ) ,
V_61 | V_62 ,
F_38 ( V_37 -> V_44 ) |
F_39 ( V_37 -> V_63 ) ) ;
F_6 ( V_8 -> V_22 , F_9 ( V_5 ) ,
V_64 , V_65 ) ;
F_8 ( V_3 , V_66 ,
V_66 ) ;
if ( ! V_42 )
return 0 ;
F_6 ( V_8 -> V_22 , V_23 ,
F_23 ( V_5 ) , 0 ) ;
F_6 ( V_8 -> V_22 , V_23 ,
F_40 ( V_5 ) | F_25 ( V_5 ) ,
F_41 ( V_5 ) | F_42 ( V_5 ) ) ;
F_6 ( V_8 -> V_22 , V_67 ,
F_43 ( V_5 ) | F_44 ( V_5 ) ,
F_45 ( V_5 , V_68 [ V_24 ] [ V_25 ] [ 0 ] ) |
F_46 ( V_5 , V_68 [ V_24 ] [ V_25 ] [ 1 ] ) ) ;
return F_13 ( V_3 , V_32 , V_33 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
enum V_4 V_5 = V_3 -> V_5 ;
int V_69 , V_70 = 10 , V_13 ;
F_6 ( V_8 -> V_22 , V_23 ,
F_7 ( V_5 ) , F_48 ( V_5 ) ) ;
do {
F_49 ( 5 ) ;
F_50 ( V_8 -> V_22 , V_67 , & V_69 ) ;
V_69 &= F_51 ( V_5 ) ;
} while ( ! V_69 && -- V_70 );
F_50 ( V_8 -> V_22 , V_59 , & V_69 ) ;
for ( V_13 = 0 ; V_13 < V_3 -> V_1 * 4 ; V_13 ++ )
F_15 ( V_8 -> V_22 , F_52 ( V_5 ) , 0 ) ;
F_15 ( V_8 -> V_22 , V_71 , V_72 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
enum V_4 V_5 = V_3 -> V_5 ;
F_6 ( V_8 -> V_22 , V_23 ,
F_7 ( V_5 ) , 0 ) ;
}
struct V_73 * F_54 ( struct V_2 * V_3 , bool V_74 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
enum V_4 V_5 = V_3 -> V_5 ;
char V_75 [ 4 ] ;
sprintf ( V_75 , L_11 , V_74 == V_52 ? 'r' : 't' , V_5 + 'a' ) ;
return F_55 ( & V_8 -> V_11 -> V_10 , V_75 ) ;
}
static int F_56 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
struct V_7 * V_8 = F_57 ( V_81 ) ;
int V_82 = F_58 ( F_59 ( V_79 ) ) ;
struct V_83 * V_84 = V_77 -> V_84 ;
struct V_2 * V_3 = V_84 -> V_85 ;
unsigned int V_1 = F_60 ( V_79 ) ;
unsigned int V_86 = F_61 ( V_79 ) ;
struct V_36 V_37 ;
int V_87 , V_14 ;
V_14 = F_1 ( V_1 , V_3 ) ;
if ( V_14 ) {
F_3 ( V_81 -> V_10 , L_12 ) ;
return V_14 ;
}
V_3 -> V_37 = & V_37 ;
if ( V_82 == 16 )
V_82 = V_88 ;
else
V_82 = V_89 ;
if ( V_8 -> V_90 == 16 )
V_87 = V_88 ;
else
V_87 = V_89 ;
V_37 . V_3 = V_3 -> V_5 ;
V_37 . V_43 = V_1 ;
V_37 . V_48 = V_49 ;
V_37 . V_55 = V_91 ;
if ( V_77 -> V_92 == V_93 ) {
V_37 . V_63 = V_82 ;
V_37 . V_44 = V_87 ;
V_37 . V_46 = V_86 ;
V_37 . V_47 = V_8 -> V_94 ;
} else {
V_37 . V_63 = V_87 ;
V_37 . V_44 = V_82 ;
V_37 . V_46 = V_8 -> V_94 ;
V_37 . V_47 = V_86 ;
}
V_14 = F_18 ( V_3 ) ;
if ( V_14 ) {
F_3 ( V_81 -> V_10 , L_13 ) ;
return V_14 ;
}
return 0 ;
}
static int F_62 ( struct V_76 * V_77 ,
struct V_80 * V_81 )
{
struct V_83 * V_84 = V_77 -> V_84 ;
struct V_2 * V_3 = V_84 -> V_85 ;
if ( V_3 )
F_5 ( V_3 ) ;
return 0 ;
}
static int F_63 ( struct V_76 * V_77 , int V_95 ,
struct V_80 * V_81 )
{
struct V_83 * V_84 = V_77 -> V_84 ;
struct V_2 * V_3 = V_84 -> V_85 ;
switch ( V_95 ) {
case V_96 :
case V_97 :
case V_98 :
F_47 ( V_3 ) ;
break;
case V_99 :
case V_100 :
case V_101 :
F_53 ( V_3 ) ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_64 ( struct V_80 * V_81 )
{
struct V_7 * V_8 = F_57 ( V_81 ) ;
F_65 ( V_81 , & V_8 -> V_102 ,
& V_8 -> V_103 ) ;
return 0 ;
}
static bool F_66 ( struct V_9 * V_10 , unsigned int V_69 )
{
switch ( V_69 ) {
case V_23 :
case V_71 :
case V_59 :
case V_67 :
case V_60 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
return true ;
default:
return false ;
}
}
static bool F_67 ( struct V_9 * V_10 , unsigned int V_69 )
{
switch ( V_69 ) {
case V_106 :
case V_134 :
case V_135 :
case V_136 :
case V_114 :
case V_115 :
case V_116 :
case V_126 :
case V_128 :
case V_130 :
case V_67 :
return true ;
default:
return false ;
}
}
static bool F_68 ( struct V_9 * V_10 , unsigned int V_69 )
{
switch ( V_69 ) {
case V_23 :
case V_71 :
case V_59 :
case V_67 :
case V_60 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_134 :
case V_135 :
case V_136 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_127 :
case V_129 :
case V_131 :
case V_132 :
case V_133 :
return true ;
default:
return false ;
}
}
static int F_69 ( struct V_7 * V_8 )
{
F_15 ( V_8 -> V_22 , V_23 , V_137 ) ;
F_15 ( V_8 -> V_22 , V_71 , 0x0 ) ;
F_15 ( V_8 -> V_22 , V_107 , 0x7fffff ) ;
F_15 ( V_8 -> V_22 , V_108 , 0x255555 ) ;
F_15 ( V_8 -> V_22 , V_109 , 0xff7280 ) ;
F_15 ( V_8 -> V_22 , V_110 , 0xff7280 ) ;
F_15 ( V_8 -> V_22 , V_111 , 0xff7280 ) ;
F_6 ( V_8 -> V_22 , V_112 ,
V_138 , F_70 ( 0xfc ) ) ;
F_15 ( V_8 -> V_22 , V_123 , 0x06D6 ) ;
return F_15 ( V_8 -> V_22 , V_124 , 0x0947 ) ;
}
static T_2 F_71 ( int V_139 , void * V_140 )
{
struct V_7 * V_8 = (struct V_7 * ) V_140 ;
struct V_9 * V_10 = & V_8 -> V_11 -> V_10 ;
enum V_4 V_5 ;
T_1 V_141 ;
F_50 ( V_8 -> V_22 , V_106 , & V_141 ) ;
F_15 ( V_8 -> V_22 , V_106 , V_142 ) ;
for ( V_5 = V_16 ; V_5 < V_17 ; V_5 ++ ) {
if ( ! V_8 -> V_3 [ V_5 ] )
continue;
if ( V_141 & V_143 ) {
V_8 -> V_3 [ V_5 ] -> error |= V_144 ;
F_72 ( V_10 , L_14 ) ;
}
if ( V_141 & F_73 ( V_5 ) ) {
V_8 -> V_3 [ V_5 ] -> error |= V_145 ;
F_74 ( L_15 ) ;
}
if ( V_141 & F_75 ( V_5 ) ) {
V_8 -> V_3 [ V_5 ] -> error |= V_146 ;
F_74 ( L_16 ) ;
}
if ( V_141 & F_76 ( V_5 ) ) {
V_8 -> V_3 [ V_5 ] -> error |= V_147 ;
F_74 ( L_17 ) ;
}
if ( V_141 & F_77 ( V_5 ) ) {
V_8 -> V_3 [ V_5 ] -> error |= V_148 ;
F_74 ( L_18 ) ;
}
}
return V_149 ;
}
static int F_78 ( struct V_150 * V_11 )
{
struct V_151 * V_152 = V_11 -> V_10 . V_153 ;
struct V_7 * V_8 ;
struct V_154 * V_155 ;
void T_3 * V_156 ;
int V_139 , V_14 , V_13 ;
char V_157 [ 16 ] ;
V_8 = F_79 ( & V_11 -> V_10 , sizeof( * V_8 ) , V_158 ) ;
if ( ! V_8 )
return - V_159 ;
V_8 -> V_11 = V_11 ;
strncpy ( V_8 -> V_75 , V_152 -> V_75 , sizeof( V_8 -> V_75 ) - 1 ) ;
V_155 = F_80 ( V_11 , V_160 , 0 ) ;
V_156 = F_81 ( & V_11 -> V_10 , V_155 ) ;
if ( F_82 ( V_156 ) )
return F_83 ( V_156 ) ;
V_8 -> V_161 = V_155 -> V_162 ;
V_8 -> V_22 = F_84 ( & V_11 -> V_10 , L_19 , V_156 ,
& V_163 ) ;
if ( F_82 ( V_8 -> V_22 ) ) {
F_3 ( & V_11 -> V_10 , L_20 ) ;
return F_83 ( V_8 -> V_22 ) ;
}
V_139 = F_85 ( V_11 , 0 ) ;
if ( V_139 < 0 ) {
F_3 ( & V_11 -> V_10 , L_21 , V_152 -> V_164 ) ;
return V_139 ;
}
V_14 = F_86 ( & V_11 -> V_10 , V_139 , F_71 , 0 ,
V_8 -> V_75 , V_8 ) ;
if ( V_14 ) {
F_3 ( & V_11 -> V_10 , L_22 , V_139 , V_14 ) ;
return V_14 ;
}
V_8 -> V_165 = F_87 ( & V_11 -> V_10 , L_19 ) ;
if ( F_82 ( V_8 -> V_165 ) ) {
F_3 ( & V_11 -> V_10 , L_23 ) ;
return F_83 ( V_8 -> V_165 ) ;
}
V_8 -> V_166 = F_87 ( & V_11 -> V_10 , L_24 ) ;
if ( F_82 ( V_8 -> V_166 ) ) {
F_3 ( & V_11 -> V_10 , L_25 ) ;
return F_83 ( V_8 -> V_166 ) ;
}
for ( V_13 = 0 ; V_13 < V_167 ; V_13 ++ ) {
sprintf ( V_157 , L_26 , V_13 ) ;
V_8 -> V_56 [ V_13 ] = F_87 ( & V_11 -> V_10 , V_157 ) ;
if ( F_82 ( V_8 -> V_56 [ V_13 ] ) ) {
F_3 ( & V_11 -> V_10 , L_27 , V_157 ) ;
return F_83 ( V_8 -> V_56 [ V_13 ] ) ;
}
}
if ( F_88 ( V_11 -> V_10 . V_153 , L_28 ) ) {
V_8 -> V_58 = 3 ;
V_53 [ V_52 ] = V_168 ;
V_53 [ V_54 ] = V_169 ;
} else {
V_8 -> V_58 = 4 ;
V_53 [ V_52 ] = V_170 ;
V_53 [ V_54 ] = V_171 ;
}
V_14 = F_69 ( V_8 ) ;
if ( V_14 ) {
F_3 ( & V_11 -> V_10 , L_29 , V_14 ) ;
return - V_21 ;
}
V_8 -> V_20 = 10 ;
V_14 = F_89 ( V_152 , L_30 ,
& V_8 -> V_94 ) ;
if ( V_14 ) {
F_3 ( & V_11 -> V_10 , L_31 ) ;
return - V_21 ;
}
V_14 = F_89 ( V_152 , L_32 ,
& V_8 -> V_90 ) ;
if ( V_14 ) {
F_3 ( & V_11 -> V_10 , L_33 ) ;
return - V_21 ;
}
if ( V_8 -> V_90 != 16 && V_8 -> V_90 != 24 ) {
F_90 ( & V_11 -> V_10 , L_34 ) ;
V_8 -> V_90 = 24 ;
}
F_91 ( V_11 , V_8 ) ;
F_92 ( & V_11 -> V_10 ) ;
F_93 ( & V_8 -> V_15 ) ;
V_14 = F_94 ( & V_11 -> V_10 , & V_172 ,
& V_173 , 1 ) ;
if ( V_14 ) {
F_3 ( & V_11 -> V_10 , L_35 ) ;
return V_14 ;
}
V_14 = F_95 ( & V_11 -> V_10 , & V_174 ) ;
if ( V_14 ) {
F_3 ( & V_11 -> V_10 , L_36 ) ;
return V_14 ;
}
F_96 ( & V_11 -> V_10 , L_37 ) ;
return 0 ;
}
static int F_97 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = F_98 ( V_10 ) ;
int V_13 ;
F_99 ( V_8 -> V_165 ) ;
F_99 ( V_8 -> V_166 ) ;
for ( V_13 = 0 ; V_13 < V_167 ; V_13 ++ )
F_99 ( V_8 -> V_56 [ V_13 ] ) ;
return 0 ;
}
static int F_100 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = F_98 ( V_10 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_167 ; V_13 ++ )
F_101 ( V_8 -> V_56 [ V_13 ] ) ;
F_101 ( V_8 -> V_166 ) ;
F_101 ( V_8 -> V_165 ) ;
return 0 ;
}
static int F_102 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = F_98 ( V_10 ) ;
F_103 ( V_8 -> V_22 , true ) ;
F_104 ( V_8 -> V_22 ) ;
return 0 ;
}
static int F_105 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = F_98 ( V_10 ) ;
T_1 V_175 ;
F_50 ( V_8 -> V_22 , V_23 , & V_175 ) ;
F_6 ( V_8 -> V_22 , V_23 ,
V_176 , 0 ) ;
F_103 ( V_8 -> V_22 , false ) ;
F_106 ( V_8 -> V_22 ) ;
F_6 ( V_8 -> V_22 , V_23 ,
V_176 , V_175 ) ;
return 0 ;
}
