static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
F_2 ( V_5 , F_3 ( V_2 -> V_6 ) ) ;
F_4 ( 1000 ) ;
F_2 ( 0 , F_5 ( V_2 -> V_6 ) ) ;
F_2 ( 0 , F_6 ( V_2 -> V_6 ) ) ;
F_2 ( ( V_7 | V_8 ) ,
F_7 ( V_2 -> V_6 ) ) ;
V_3 = F_8 ( V_2 -> V_9 ) ;
if ( V_3 == 0 )
V_3 = V_10 ;
V_4 = F_9 ( V_2 -> V_11 -> V_12 ) |
F_10 ( 1 + ( V_3 / V_2 -> V_11 -> V_13 ) ) |
F_11 ( 1 + ( V_3 / V_2 -> V_11 -> V_14 ) ) |
F_12 ( 1 + ( V_3 / V_2 -> V_11 -> V_15 ) ) |
F_13 ( V_2 -> V_11 -> V_16 ) |
F_14 ( 1 + ( V_3 / V_2 -> V_11 -> V_17 ) ) |
F_15 ( 1 + ( V_3 / V_2 -> V_11 -> V_18 ) ) |
F_16 ( 1 + ( V_3 / V_2 -> V_11 -> V_19 ) ) ;
F_2 ( V_4 , F_17 ( V_2 -> V_6 ) ) ;
}
static void F_18 ( struct V_20 * V_21 , int V_22 ,
unsigned int V_23 )
{
T_1 V_4 ;
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_1 * V_2 = V_25 -> V_26 ;
V_4 = F_19 ( F_5 ( V_2 -> V_6 ) ) ;
if ( V_23 & V_27 )
V_4 |= V_28 ;
else
V_4 &= ~ V_28 ;
F_2 ( V_4 , F_5 ( V_2 -> V_6 ) ) ;
if ( V_22 != V_29 ) {
if ( V_23 & V_30 )
F_2 ( V_22 , F_20 ( V_2 -> V_6 ) ) ;
else
F_2 ( V_22 , F_21 ( V_2 -> V_6 ) ) ;
}
}
static int F_22 ( struct V_20 * V_21 )
{
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_1 * V_2 = V_25 -> V_26 ;
int V_31 = 0 ;
if ( ( F_19 ( F_23 ( V_2 -> V_6 ) ) & V_32 ) != 0 )
V_31 = 1 ;
return V_31 ;
}
static void F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 -> V_11 -> V_33 ) )
F_26 ( V_2 -> V_11 -> V_33 , 0 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 -> V_11 -> V_33 ) )
F_26 ( V_2 -> V_11 -> V_33 , 1 ) ;
}
static void F_28 ( struct V_20 * V_21 , int V_34 )
{
}
static int F_29 ( struct V_20 * V_21 ,
const unsigned char * V_35 ,
unsigned char * V_36 )
{
return 0 ;
}
static T_2 F_30 ( struct V_20 * V_21 )
{
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_1 * V_2 = V_25 -> V_26 ;
return ( T_2 ) F_19 ( F_31 ( V_2 -> V_6 ) ) ;
}
static void F_32 ( struct V_20 * V_21 , T_3 * V_35 , int V_37 )
{
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_1 * V_2 = V_25 -> V_26 ;
while ( V_37 -- > 0 )
* V_35 ++ = ( T_2 ) F_19 ( F_31 ( V_2 -> V_6 ) ) ;
}
static void F_33 ( struct V_20 * V_21 , const T_2 * V_35 , int V_37 )
{
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_1 * V_2 = V_25 -> V_26 ;
while ( V_37 -- > 0 )
F_2 ( ( T_1 ) * V_35 ++ , F_31 ( V_2 -> V_6 ) ) ;
}
static int F_34 ( struct V_20 * V_21 ,
struct V_24 * V_25 , int V_38 )
{
V_25 -> V_39 ( V_21 , V_40 , 0 , V_38 ) ;
V_25 -> V_41 ( V_21 , V_25 -> V_42 , V_21 -> V_43 ) ;
return 0 ;
}
static int F_35 ( struct V_20 * V_21 ,
struct V_24 * V_25 , int V_38 )
{
int V_44 ;
V_25 -> V_39 ( V_21 , V_45 , V_21 -> V_46 , V_38 ) ;
V_25 -> V_47 ( V_21 , V_25 -> V_42 , V_21 -> V_43 ) ;
V_25 -> V_39 ( V_21 , V_48 , - 1 , - 1 ) ;
V_44 = V_25 -> V_49 ( V_21 , V_25 ) ;
return V_44 & V_50 ? - V_51 : 0 ;
}
static void F_36 ( T_2 * V_52 , const T_1 * V_53 , int V_54 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < ( V_54 * 3 ) ; V_55 += 3 ) {
T_1 V_56 = V_53 [ V_55 / 3 ] ;
V_56 = ~ ( V_56 << 2 ) & 0xFFFFFF ;
V_52 [ V_55 + 2 ] = ( T_2 ) ( V_56 & 0xFF ) ;
V_56 >>= 8 ;
V_52 [ V_55 + 1 ] = ( T_2 ) ( V_56 & 0xFF ) ;
V_56 >>= 8 ;
V_52 [ V_55 ] = ( T_2 ) ( V_56 & 0xFF ) ;
}
}
static void F_37 ( void * V_57 )
{
F_38 ( V_57 ) ;
}
static int F_39 ( struct V_20 * V_21 , T_4 V_58 ,
void * V_59 , int V_37 , enum V_60 V_61 )
{
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_62 * V_63 ;
int V_64 = V_65 | V_66 ;
int V_67 ;
V_2 -> V_68 . V_69 = V_61 ;
V_2 -> V_68 . V_70 = V_58 ;
V_2 -> V_68 . V_71 = V_58 ;
V_2 -> V_68 . V_72 = V_73 ;
V_2 -> V_68 . V_74 = V_73 ;
V_2 -> V_68 . V_75 = 4 ;
V_2 -> V_68 . V_76 = 4 ;
V_2 -> V_68 . V_77 = false ;
if ( F_40 ( V_2 -> V_78 , & V_2 -> V_68 ) ) {
F_41 ( V_21 -> V_79 . V_80 , L_1 ) ;
return - V_81 ;
}
F_42 ( & V_2 -> V_82 , V_59 , V_37 ) ;
V_67 = F_43 ( V_2 -> V_78 -> V_83 -> V_79 , & V_2 -> V_82 , 1 ,
V_84 ) ;
if ( V_67 != 1 ) {
F_41 ( V_21 -> V_79 . V_80 , L_2 ) ;
return - V_81 ;
}
V_63 = F_44 ( V_2 -> V_78 , & V_2 -> V_82 , 1 , V_61 ,
V_64 ) ;
if ( ! V_63 ) {
F_41 ( V_21 -> V_79 . V_80 , L_3 ) ;
goto V_85;
}
F_45 ( & V_2 -> V_86 ) ;
V_63 -> V_87 = F_37 ;
V_63 -> V_88 = & V_2 -> V_86 ;
F_46 ( V_63 ) ;
F_47 ( V_2 -> V_78 ) ;
F_48 ( & V_2 -> V_86 , F_49 ( 1000 ) ) ;
F_50 ( V_2 -> V_78 -> V_83 -> V_79 , & V_2 -> V_82 , 1 ,
V_84 ) ;
return 0 ;
V_85:
F_50 ( V_2 -> V_78 -> V_83 -> V_79 , & V_2 -> V_82 , 1 ,
V_84 ) ;
return - V_81 ;
}
static int F_51 ( struct V_20 * V_21 , T_2 * V_35 , int V_89 ,
int V_90 )
{
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_1 * V_2 = V_25 -> V_26 ;
int V_55 , V_44 = 0 ;
unsigned long V_91 ;
int V_67 ;
enum V_60 V_61 =
V_90 ? V_92 : V_93 ;
T_2 * V_94 ;
bool V_95 ;
if ( ( void * ) V_35 <= V_96 ) {
V_94 = V_35 ;
V_95 = true ;
} else {
V_94 = V_2 -> V_97 ;
V_95 = false ;
if ( ! V_90 )
memcpy ( V_2 -> V_97 , V_35 , V_21 -> V_46 ) ;
}
if ( V_90 ) {
F_2 ( F_19 ( F_5 ( V_2 -> V_6 ) ) |
V_98 | V_99 | V_100 |
V_101 , F_5 ( V_2 -> V_6 ) ) ;
} else {
F_2 ( ( F_19 ( F_5 ( V_2 -> V_6 ) ) |
V_99 | V_100 | V_101 ) &
~ V_98 ,
F_5 ( V_2 -> V_6 ) ) ;
}
F_2 ( V_102 , F_3 ( V_2 -> V_6 ) ) ;
F_2 ( V_21 -> V_46 , F_52 ( V_2 -> V_6 ) ) ;
F_2 ( F_19 ( F_3 ( V_2 -> V_6 ) ) | V_103 ,
F_3 ( V_2 -> V_6 ) ) ;
for ( V_55 = 0 ; V_55 < V_25 -> V_53 . V_104 ; V_55 ++ ) {
V_67 = F_39 ( V_21 , F_53 ( V_2 -> V_105 ) ,
V_94 + V_55 * V_25 -> V_53 . V_106 ,
V_21 -> V_46 / V_25 -> V_53 . V_104 , V_61 ) ;
if ( V_67 )
return V_67 ;
if ( V_55 == V_25 -> V_53 . V_104 - 1 )
break;
if ( ! V_90 )
F_4 ( 10 ) ;
V_67 = F_39 ( V_21 , F_54 ( V_2 -> V_105 ) ,
& V_2 -> V_107 [ V_55 ] , 4 , V_92 ) ;
if ( V_67 )
return V_67 ;
}
if ( F_19 ( F_23 ( V_2 -> V_6 ) ) & V_108 ) {
F_55 ( V_21 -> V_79 . V_80 , L_4 ) ;
V_91 = V_109 + F_49 ( V_110 ) ;
while ( ( F_19 ( F_23 ( V_2 -> V_6 ) ) & V_108 ) &&
F_56 ( V_109 , V_91 ) )
F_57 () ;
if ( ! F_56 ( V_109 , V_91 ) ) {
F_41 ( V_21 -> V_79 . V_80 , L_5 ) ;
V_44 = - V_51 ;
}
}
if ( ! V_90 )
F_4 ( 10 ) ;
V_2 -> V_107 [ V_25 -> V_53 . V_104 - 1 ] =
F_19 ( F_54 ( V_2 -> V_6 ) ) ;
F_58 ( V_2 -> V_78 ) ;
if ( F_19 ( F_23 ( V_2 -> V_6 ) ) & V_108 ||
F_19 ( F_52 ( V_2 -> V_6 ) ) ) {
F_41 ( V_21 -> V_79 . V_80 , L_6 ) ;
V_44 = - V_51 ;
}
F_2 ( F_19 ( F_3 ( V_2 -> V_6 ) ) & ~ V_103 ,
F_3 ( V_2 -> V_6 ) ) ;
F_2 ( F_19 ( F_5 ( V_2 -> V_6 ) ) &
~ ( V_98 | V_99 | V_100 |
V_101 ) , F_5 ( V_2 -> V_6 ) ) ;
if ( ! V_95 && V_90 )
memcpy ( V_35 , V_2 -> V_97 , V_21 -> V_46 ) ;
return V_44 ;
}
static int F_59 ( struct V_20 * V_21 ,
struct V_24 * V_25 , T_2 * V_35 ,
int V_111 , int V_38 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_112 , V_55 , V_44 ;
T_2 * V_113 , V_114 [ V_115 ] ;
V_25 -> V_39 ( V_21 , V_116 , 0 , V_38 ) ;
V_44 = F_51 ( V_21 , V_35 , V_25 -> V_53 . V_104 , 1 ) ;
V_25 -> V_41 ( V_21 , V_25 -> V_42 , V_21 -> V_43 ) ;
F_36 ( V_114 , ( T_1 * ) V_2 -> V_107 , V_25 -> V_53 . V_104 ) ;
V_113 = V_25 -> V_42 + V_25 -> V_53 . V_117 -> V_118 [ 0 ] ;
for ( V_55 = 0 ; V_55 < V_25 -> V_53 . V_104 ; V_55 ++ ) {
V_112 = V_25 -> V_53 . V_119 ( V_21 , V_35 , V_113 ,
& V_114 [ V_55 * V_25 -> V_53 . V_120 ] ) ;
if ( V_112 < 0 )
V_21 -> V_121 . V_122 ++ ;
else
V_21 -> V_121 . V_123 += V_112 ;
V_35 += V_25 -> V_53 . V_106 ;
V_113 += V_25 -> V_53 . V_120 ;
}
return V_44 ;
}
static int F_60 ( struct V_20 * V_21 ,
struct V_24 * V_25 ,
T_2 * V_35 , int V_111 ,
int V_38 )
{
V_25 -> V_39 ( V_21 , V_116 , 0 , V_38 ) ;
V_25 -> V_41 ( V_21 , V_35 , V_25 -> V_53 . V_106 * V_25 -> V_53 . V_104 ) ;
V_25 -> V_41 ( V_21 , V_25 -> V_42 , V_21 -> V_43 ) ;
return 0 ;
}
static int F_61 ( struct V_20 * V_21 ,
struct V_24 * V_25 ,
const T_2 * V_35 , int V_111 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
T_2 * V_124 = V_25 -> V_42 + V_25 -> V_53 . V_117 -> V_118 [ 0 ] ;
int error ;
error = F_51 ( V_21 , ( T_2 * ) V_35 , V_25 -> V_53 . V_104 , 0 ) ;
if ( error )
return error ;
F_36 ( V_124 , ( T_1 * ) V_2 -> V_107 , V_25 -> V_53 . V_104 ) ;
V_25 -> V_47 ( V_21 , V_25 -> V_42 , V_21 -> V_43 ) ;
return 0 ;
}
static int F_62 ( struct V_20 * V_21 ,
struct V_24 * V_25 ,
const T_2 * V_35 ,
int V_111 )
{
V_25 -> V_47 ( V_21 , V_35 , V_25 -> V_53 . V_106 * V_25 -> V_53 . V_104 ) ;
V_25 -> V_47 ( V_21 , V_25 -> V_42 , V_21 -> V_43 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_5 V_125 ;
if ( ! V_2 -> V_126 || ! V_2 -> V_126 -> V_127 ) {
F_41 ( V_21 -> V_79 . V_80 , L_7 ) ;
return - V_128 ;
}
F_64 ( V_125 ) ;
F_65 ( V_129 , V_125 ) ;
V_2 -> V_78 = F_66 ( V_125 , V_2 -> V_126 -> V_127 ,
L_8 ) ;
if ( ! V_2 -> V_78 ) {
F_41 ( V_21 -> V_79 . V_80 , L_9 ) ;
return - V_130 ;
}
return 0 ;
}
static struct V_131 * F_67 ( struct V_83 * V_79 )
{
struct V_131 * V_11 ;
struct V_132 * V_133 = V_79 -> V_134 ;
V_11 = F_68 ( V_79 , sizeof( * V_11 ) , V_135 ) ;
if ( ! V_11 ) {
F_41 ( V_79 , L_10 ) ;
return NULL ;
}
F_69 ( V_133 , L_11 , & V_11 -> V_12 ) ;
F_69 ( V_133 , L_12 , & V_11 -> V_13 ) ;
F_69 ( V_133 , L_13 , & V_11 -> V_14 ) ;
F_69 ( V_133 , L_14 , & V_11 -> V_15 ) ;
F_69 ( V_133 , L_15 , & V_11 -> V_16 ) ;
F_69 ( V_133 , L_16 , & V_11 -> V_17 ) ;
F_69 ( V_133 , L_17 , & V_11 -> V_18 ) ;
F_69 ( V_133 , L_18 , & V_11 -> V_19 ) ;
if ( ! V_11 -> V_12 || ! V_11 -> V_13 || ! V_11 -> V_14 ||
! V_11 -> V_15 || ! V_11 -> V_16 || ! V_11 -> V_17 ||
! V_11 -> V_18 || ! V_11 -> V_19 ) {
F_41 ( V_79 , L_19 ) ;
return NULL ;
}
V_11 -> V_136 = F_70 ( V_133 ) ;
V_11 -> V_33 = F_71 ( V_133 , L_20 , 0 ) ;
return V_11 ;
}
static int T_6 F_72 ( struct V_137 * V_138 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_24 * V_25 ;
struct V_139 * V_140 ;
struct V_141 V_142 = {} ;
int V_67 ;
V_140 = F_73 ( V_138 , V_143 , 0 ) ;
if ( V_140 == NULL ) {
F_41 ( & V_138 -> V_79 , L_21 ) ;
return - V_130 ;
}
V_2 = F_68 ( & V_138 -> V_79 , sizeof( * V_2 ) , V_135 ) ;
if ( ! V_2 ) {
F_41 ( & V_138 -> V_79 , L_22 ) ;
return - V_144 ;
}
V_2 -> V_105 = V_140 -> V_145 ;
V_2 -> V_6 = F_74 ( & V_138 -> V_79 , V_140 ) ;
if ( V_2 -> V_6 == NULL ) {
F_41 ( & V_138 -> V_79 , L_23 ) ;
return - V_144 ;
}
if ( V_138 -> V_79 . V_134 )
V_2 -> V_11 = F_67 ( & V_138 -> V_79 ) ;
if ( ! V_2 -> V_11 ) {
F_41 ( & V_138 -> V_79 ,
L_24 ) ;
return - V_128 ;
}
if ( V_2 -> V_11 -> V_33 == - V_146 )
return - V_146 ;
if ( F_25 ( V_2 -> V_11 -> V_33 ) &&
F_75 ( V_2 -> V_11 -> V_33 , L_25 ) ) {
F_41 ( & V_138 -> V_79 , L_26 ) ;
return - V_130 ;
}
F_27 ( V_2 ) ;
V_2 -> V_126 = V_138 -> V_79 . V_147 ;
V_21 = & V_2 -> V_21 ;
V_25 = & V_2 -> V_24 ;
V_25 -> V_26 = V_2 ;
V_21 -> V_26 = V_25 ;
V_21 -> V_148 = V_149 ;
V_21 -> V_79 . V_80 = & V_138 -> V_79 ;
V_2 -> V_9 = F_76 ( & V_138 -> V_79 , NULL ) ;
if ( F_77 ( V_2 -> V_9 ) ) {
F_41 ( & V_138 -> V_79 , L_27 ) ;
V_67 = - V_128 ;
goto V_150;
}
F_78 ( V_2 -> V_9 ) ;
V_25 -> V_151 = F_31 ( V_2 -> V_6 ) ;
V_25 -> V_152 = F_31 ( V_2 -> V_6 ) ;
V_25 -> V_153 = F_18 ;
V_25 -> V_154 = F_22 ;
V_25 -> V_155 = 20 ;
F_1 ( V_2 ) ;
F_79 ( V_138 , V_2 ) ;
V_25 -> V_53 . V_34 = V_156 ;
V_25 -> V_157 = F_30 ;
V_25 -> V_41 = F_32 ;
V_25 -> V_47 = F_33 ;
V_25 -> V_53 . V_158 = F_60 ;
V_25 -> V_53 . V_159 = F_59 ;
V_25 -> V_53 . V_160 = F_62 ;
V_25 -> V_53 . V_161 = F_61 ;
V_25 -> V_53 . V_162 = F_35 ;
V_25 -> V_53 . V_163 = F_34 ;
V_25 -> V_53 . V_164 = F_29 ;
V_25 -> V_53 . V_119 = V_165 ;
V_25 -> V_53 . V_166 = 1 ;
V_25 -> V_53 . V_167 = F_28 ;
V_21 -> V_168 = V_25 -> V_53 . V_166 ;
V_2 -> V_169 = V_170 + V_115 ;
V_2 -> V_97 = F_68 ( & V_138 -> V_79 , V_2 -> V_169 ,
V_135 ) ;
if ( V_2 -> V_97 == NULL ) {
F_41 ( & V_138 -> V_79 , L_28 ) ;
V_67 = - V_144 ;
goto V_171;
}
V_67 = F_63 ( V_2 ) ;
if ( V_67 ) {
V_67 = - V_51 ;
goto V_171;
}
if ( F_80 ( V_21 , 1 , NULL ) ) {
V_67 = - V_81 ;
goto V_172;
}
V_2 -> V_107 = ( T_1 * ) ( V_2 -> V_97 + V_170 ) ;
if ( V_21 -> V_46 <= 512 )
V_25 -> V_53 . V_117 = & V_173 ;
V_25 -> V_53 . V_106 = 256 ;
V_25 -> V_53 . V_120 = V_174 ;
V_25 -> V_53 . V_175 = V_25 -> V_53 . V_176 = 0 ;
if ( V_2 -> V_11 -> V_136 ) {
V_25 -> V_177 |= V_178 ;
V_25 -> V_179 |= V_180 ;
if ( V_21 -> V_46 <= 512 ) {
V_25 -> V_181 = & V_182 ;
V_25 -> V_183 = & V_184 ;
}
}
if ( F_81 ( V_21 ) ) {
V_67 = - V_81 ;
goto V_172;
}
if ( V_2 -> V_11 -> V_136 ) {
if ( F_82 ( V_21 ) < 0 )
F_41 ( & V_138 -> V_79 ,
L_29 ) ;
}
V_21 -> V_185 = L_30 ;
V_142 . V_134 = V_138 -> V_79 . V_134 ;
V_67 = F_83 ( V_21 , NULL , & V_142 , V_2 -> V_11 -> V_186 ,
V_2 -> V_11 -> V_187 ) ;
if ( ! V_67 )
return V_67 ;
F_84 ( V_21 ) ;
V_172:
F_85 ( V_2 -> V_78 ) ;
V_171:
F_86 ( V_2 -> V_9 ) ;
F_87 ( V_2 -> V_9 ) ;
F_79 ( V_138 , NULL ) ;
V_150:
F_24 ( V_2 ) ;
F_88 ( V_2 -> V_11 -> V_33 ) ;
return V_67 ;
}
static int T_7 F_89 ( struct V_137 * V_138 )
{
T_1 V_4 ;
struct V_1 * V_2 = F_90 ( V_138 ) ;
struct V_20 * V_21 = & V_2 -> V_21 ;
F_84 ( V_21 ) ;
F_85 ( V_2 -> V_78 ) ;
V_4 = F_19 ( F_3 ( V_2 -> V_6 ) ) ;
V_4 &= ~ V_28 ;
F_2 ( V_4 , F_3 ( V_2 -> V_6 ) ) ;
F_86 ( V_2 -> V_9 ) ;
F_87 ( V_2 -> V_9 ) ;
F_79 ( V_138 , NULL ) ;
F_24 ( V_2 ) ;
F_88 ( V_2 -> V_11 -> V_33 ) ;
return 0 ;
}
static int F_91 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_90 ( V_138 ) ;
F_78 ( V_2 -> V_9 ) ;
F_1 ( V_2 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_137 * V_138 , T_8 V_188 )
{
T_1 V_4 ;
struct V_1 * V_2 = F_90 ( V_138 ) ;
V_4 = F_19 ( F_3 ( V_2 -> V_6 ) ) ;
V_4 &= ~ V_28 ;
F_2 ( V_4 , F_3 ( V_2 -> V_6 ) ) ;
F_24 ( V_2 ) ;
F_86 ( V_2 -> V_9 ) ;
return 0 ;
}
