static struct V_1 * F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
return V_2 ;
}
static void * F_2 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_6 ;
if ( V_2 -> V_3 + sizeof( * V_6 ) > V_2 -> V_7 )
return NULL ;
V_6 = V_2 -> V_8 + V_2 -> V_3 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_9 = F_3 ( V_2 -> V_10 , V_4 ) ;
V_2 -> V_3 += sizeof( * V_6 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_12 ) {
V_11 = V_2 -> V_12 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = V_2 -> V_13 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( V_2 -> V_14 )
V_11 = V_2 -> V_14 ( V_2 ) ;
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_2 ( F_1 ( V_2 ) , V_15 ) ;
return F_4 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_11 ;
F_2 ( F_1 ( V_2 ) , V_16 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 )
V_2 -> V_17 . V_18 = V_19 ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_11 ;
F_2 ( F_1 ( V_2 ) , V_20 ) ;
V_11 = F_4 ( V_2 ) ;
if ( ! V_11 )
V_2 -> V_17 . V_18 = V_19 ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
struct V_23 * V_6 ;
V_6 = F_2 ( F_1 ( V_2 ) , V_24 ) ;
V_6 -> V_25 = F_9 ( V_22 -> V_26 - 1 ,
V_2 -> V_17 . V_27 & V_28 ) ;
V_6 -> V_29 = F_10 ( V_22 -> V_30 + V_22 -> V_31 - 1 ) ;
V_6 -> V_32 = F_11 ( V_22 -> V_33 - 1 ) ;
V_6 -> V_34 = F_12 ( F_13 ( V_22 -> V_34 - 1 ) ) ;
V_6 -> V_35 = 96 ;
F_14 ( V_2 -> V_36 ,
L_1 ,
F_15 ( V_6 -> V_34 ) , V_6 -> V_29 , V_6 -> V_32 , V_6 -> V_25 ) ;
return F_4 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
struct V_37 * V_6 ;
V_6 = F_2 ( F_1 ( V_2 ) , V_38 ) ;
V_6 -> V_26 = F_17 ( V_22 -> V_26 - 1 ) ;
V_6 -> V_29 = F_18 ( V_22 -> V_30 + V_22 -> V_31 - 1 ) ;
V_6 -> V_32 = F_19 ( V_22 -> V_33 - 1 ) ;
V_6 -> V_34 = F_12 ( F_20 ( V_22 -> V_34 - 1 ) ) ;
F_14 ( V_2 -> V_36 ,
L_2 ,
F_15 ( V_6 -> V_34 ) , V_6 -> V_29 , V_6 -> V_32 , V_6 -> V_26 ) ;
return F_4 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_39 , T_2 V_40 )
{
struct V_41 * V_6 ;
V_6 = F_2 ( F_1 ( V_2 ) , V_42 ) ;
V_6 -> V_43 = V_39 ;
V_6 -> V_40 = F_22 ( V_40 ) ;
return F_4 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_3 V_44 )
{
struct F_23 * V_6 ;
V_6 = F_2 ( F_1 ( V_2 ) , V_45 ) ;
V_6 -> V_44 = F_12 ( V_44 ) ;
return F_4 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_46 * V_6 ;
V_6 = F_2 ( F_1 ( V_2 ) , V_47 ) ;
V_6 -> V_48 = F_12 ( V_49 | V_50 ) ;
V_6 -> V_51 = 0 ;
V_6 -> V_52 = 0 ;
return F_4 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_3 V_53 )
{
struct V_54 * V_6 ;
V_6 = F_2 ( F_1 ( V_2 ) , V_55 ) ;
V_6 -> V_56 = F_12 ( V_53 ) ;
return F_4 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_3 V_53 )
{
struct V_54 * V_6 ;
V_6 = F_2 ( F_1 ( V_2 ) , V_57 ) ;
V_6 -> V_56 = F_12 ( V_53 ) ;
return F_4 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
F_2 ( F_1 ( V_2 ) , V_58 ) ;
return F_4 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = & V_2 -> V_36 -> V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
const T_3 V_67 = F_15 ( V_60 -> V_44 ) ;
T_1 V_68 ;
if ( V_67 & V_69 )
V_68 = F_29 ( F_30 ( F_31 ( V_60 ) ) ) ;
else
V_68 = F_32 ( F_31 ( V_60 ) ) ;
if ( ( V_67 & V_70 ) &&
! ( V_67 & V_71 ) ) {
int V_72 ;
unsigned long V_44 ;
F_33 ( & V_2 -> V_73 , V_44 ) ;
V_72 = F_34 ( V_2 -> V_36 , V_60 -> V_74 ) ;
F_35 ( & V_2 -> V_73 , V_44 ) ;
V_62 -> V_75 += V_68 ;
V_62 -> V_76 ++ ;
if ( V_72 ) {
F_36 ( V_2 -> V_36 ) ;
}
return 0 ;
}
if ( V_67 & V_69 ) {
V_66 = F_37 ( V_2 -> V_36 , & V_64 ) ;
if ( ! V_66 )
return - V_77 ;
if ( V_67 & V_78 )
V_64 -> V_44 |= V_79 ;
if ( V_67 & V_80 )
V_64 -> V_44 |= V_81 ;
} else {
V_66 = F_38 ( V_2 -> V_36 , (struct V_82 * * ) & V_64 ) ;
if ( ! V_66 )
return - V_77 ;
}
V_64 -> V_83 = F_39 ( V_60 -> V_83 ) ;
V_64 -> V_84 = V_68 ;
if ( V_67 & V_85 )
V_64 -> V_83 |= V_86 ;
if ( V_67 & V_87 )
V_64 -> V_83 |= V_88 ;
else
memcpy ( V_64 -> V_89 , V_60 -> V_90 , V_64 -> V_84 ) ;
V_62 -> V_91 += V_64 -> V_84 ;
V_62 -> V_92 ++ ;
F_40 ( V_66 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_93 * V_60 )
{
V_2 -> V_94 . V_95 = V_60 -> V_96 ;
V_2 -> V_94 . V_97 = V_60 -> V_98 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_99 * V_60 )
{
struct V_100 * V_36 = V_2 -> V_36 ;
struct V_61 * V_62 = & V_36 -> V_62 ;
struct V_82 * V_64 ;
struct V_65 * V_66 ;
if ( F_43 ( V_60 ) ) {
unsigned long V_44 ;
if ( V_2 -> V_101 ) {
int V_11 = V_2 -> V_101 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
F_33 ( & V_2 -> V_73 , V_44 ) ;
if ( ! V_2 -> V_17 . V_102 [ V_2 -> V_103 ] ) {
F_35 ( & V_2 -> V_73 , V_44 ) ;
F_36 ( V_36 ) ;
} else {
F_35 ( & V_2 -> V_73 , V_44 ) ;
}
return 0 ;
}
V_66 = F_44 ( V_36 , & V_64 ) ;
if ( F_45 ( V_60 ) ) {
F_14 ( V_36 , L_3 ) ;
V_2 -> V_17 . V_18 = V_104 ;
V_2 -> V_17 . V_105 . V_106 ++ ;
F_46 ( V_36 ) ;
if ( V_66 )
V_64 -> V_83 |= V_107 ;
} else if ( F_47 ( V_60 ) ) {
F_14 ( V_36 , L_4 ) ;
V_2 -> V_17 . V_18 = V_108 ;
V_2 -> V_17 . V_105 . V_109 ++ ;
if ( V_66 ) {
V_64 -> V_83 |= V_110 ;
V_64 -> V_89 [ 1 ] = ( V_2 -> V_94 . V_95 > V_2 -> V_94 . V_97 ) ?
V_111 :
V_112 ;
V_64 -> V_89 [ 6 ] = V_2 -> V_94 . V_95 ;
V_64 -> V_89 [ 7 ] = V_2 -> V_94 . V_97 ;
}
} else if ( F_48 ( V_60 ) ) {
F_14 ( V_36 , L_5 ) ;
V_2 -> V_17 . V_18 = V_113 ;
V_2 -> V_17 . V_105 . V_114 ++ ;
if ( V_66 ) {
V_64 -> V_83 |= V_110 ;
V_64 -> V_89 [ 1 ] = ( V_2 -> V_94 . V_95 > V_2 -> V_94 . V_97 ) ?
V_115 :
V_116 ;
V_64 -> V_89 [ 6 ] = V_2 -> V_94 . V_95 ;
V_64 -> V_89 [ 7 ] = V_2 -> V_94 . V_97 ;
}
} else if ( V_2 -> V_17 . V_18 != V_19 ) {
F_14 ( V_36 , L_6 ) ;
F_49 ( V_36 , V_64 , V_19 ,
V_19 ) ;
} else {
F_50 ( V_66 ) ;
return 0 ;
}
if ( ! V_66 ) {
V_62 -> V_117 ++ ;
return - V_77 ;
}
V_62 -> V_92 ++ ;
V_62 -> V_91 += V_64 -> V_118 ;
F_40 ( V_66 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = & V_2 -> V_36 -> V_62 ;
struct V_82 * V_64 ;
struct V_65 * V_66 ;
V_62 -> V_119 ++ ;
V_62 -> V_120 ++ ;
V_66 = F_44 ( V_2 -> V_36 , & V_64 ) ;
if ( ! V_66 ) {
V_62 -> V_117 ++ ;
return - V_77 ;
}
V_64 -> V_83 |= V_110 ;
V_64 -> V_89 [ 1 ] = V_121 ;
V_64 -> V_89 [ 6 ] = V_2 -> V_94 . V_95 ;
V_64 -> V_89 [ 7 ] = V_2 -> V_94 . V_97 ;
V_62 -> V_91 += V_64 -> V_118 ;
V_62 -> V_92 ++ ;
F_40 ( V_66 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
T_3 V_122 = F_15 ( V_60 -> type ) ;
int V_123 = F_15 ( V_60 -> V_124 ) ;
int V_11 ;
if ( ! V_123 || ! V_122 ) {
goto exit;
}
switch ( V_122 ) {
case V_125 :
V_11 = F_28 ( V_2 , (struct V_59 * ) V_60 ) ;
break;
case V_126 :
V_11 = F_41 ( V_2 , (struct V_93 * ) V_60 ) ;
break;
case V_127 :
V_11 = F_42 ( V_2 , (struct V_99 * ) V_60 ) ;
break;
case V_128 :
V_11 = F_51 ( V_2 ) ;
break;
default:
V_11 = 0 ;
}
if ( V_11 < 0 )
return V_11 ;
exit:
return V_123 ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_59 * V_129 , int V_130 )
{
void * V_131 = V_129 ;
int V_132 , V_123 = 0 ;
for ( V_132 = 0 ; V_132 < V_130 ; V_132 ++ ) {
V_123 = F_52 ( V_2 , V_131 ) ;
if ( V_123 <= 0 )
break;
V_131 += V_123 ;
}
if ( V_123 < 0 )
return V_123 ;
return V_132 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_24 ( V_2 ) ;
if ( V_11 )
goto V_133;
V_2 -> V_103 = 0 ;
V_2 -> V_94 . V_95 = 0 ;
V_2 -> V_94 . V_97 = 0 ;
if ( V_2 -> V_17 . V_27 & V_134 )
V_11 = F_7 ( V_2 ) ;
else
V_11 = F_6 ( V_2 ) ;
V_133:
return V_11 ;
}
static void F_55 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_5 ( V_2 ) ;
if ( V_11 ) {
F_56 ( V_2 -> V_36 , L_7 ,
V_2 -> V_10 ) ;
} else {
F_23 ( V_2 , V_135 ) ;
}
}
static int F_57 ( struct V_100 * V_36 , enum V_136 V_137 )
{
struct V_1 * V_2 = F_58 ( V_36 ) ;
switch ( V_137 ) {
case V_138 :
F_54 ( V_2 ) ;
F_36 ( V_36 ) ;
break;
default:
return - V_139 ;
}
return 0 ;
}
static int F_59 ( const struct V_100 * V_36 ,
struct V_140 * V_94 )
{
struct V_1 * V_2 = F_58 ( V_36 ) ;
* V_94 = V_2 -> V_94 ;
return 0 ;
}
static int F_60 ( struct V_100 * V_36 )
{
struct V_1 * V_2 = F_58 ( V_36 ) ;
int V_132 , V_11 = 0 ;
V_11 = F_61 ( V_36 ) ;
if ( V_11 ) {
F_56 ( V_36 , L_8 , V_11 ) ;
goto V_133;
}
V_11 = F_5 ( V_2 ) ;
if ( V_11 )
goto V_141;
if ( V_2 -> V_17 . V_27 & V_142 ) {
if ( V_2 -> V_17 . V_27 & V_143 )
V_11 = F_26 ( V_2 , V_144 ) ;
else
V_11 = F_25 ( V_2 , V_144 ) ;
if ( V_11 )
goto V_141;
}
V_11 = F_25 ( V_2 , V_145 ) ;
if ( V_11 )
goto V_141;
for ( V_132 = 0 ; V_132 <= V_146 ; V_132 ++ )
F_21 ( V_2 , V_132 , 0xffffffff ) ;
V_11 = F_54 ( V_2 ) ;
if ( V_11 )
goto V_141;
V_11 = F_27 ( V_2 ) ;
if ( ! V_11 )
goto V_133;
V_141:
F_62 ( V_36 ) ;
V_133:
return V_11 ;
}
static int F_63 ( struct V_100 * V_36 )
{
struct V_1 * V_2 = F_58 ( V_36 ) ;
return F_8 ( V_2 , & V_2 -> V_17 . V_147 ) ;
}
static int F_64 ( struct V_100 * V_36 )
{
struct V_1 * V_2 = F_58 ( V_36 ) ;
return F_16 ( V_2 , & V_2 -> V_17 . V_148 ) ;
}
static int F_65 ( struct V_100 * V_36 )
{
struct V_1 * V_2 = F_58 ( V_36 ) ;
F_66 ( V_36 ) ;
F_55 ( V_2 ) ;
F_62 ( V_36 ) ;
return 0 ;
}
static T_4 F_67 ( struct V_65 * V_66 ,
struct V_100 * V_36 )
{
struct V_1 * V_2 = F_58 ( V_36 ) ;
struct V_61 * V_62 = & V_36 -> V_62 ;
struct V_63 * V_64 = (struct V_63 * ) V_66 -> V_89 ;
struct V_149 * V_60 ;
T_3 V_123 , V_150 ;
unsigned long V_44 ;
bool V_151 ;
int V_152 ;
T_1 V_118 ;
if ( F_68 ( V_36 , V_66 ) )
return V_153 ;
V_123 = F_69 ( sizeof( * V_60 ) + V_64 -> V_84 , 4 ) ;
V_60 = V_2 -> V_154 ( V_2 , V_123 , & V_152 ) ;
if ( ! V_60 ) {
V_62 -> V_155 ++ ;
F_66 ( V_36 ) ;
return V_156 ;
}
V_60 -> V_124 = F_12 ( V_123 ) ;
V_60 -> type = F_12 ( V_157 ) ;
V_150 = 0 ;
if ( V_64 -> V_83 & V_86 ) {
V_150 |= V_85 ;
V_60 -> V_83 = F_22 ( V_64 -> V_83 & V_158 ) ;
} else {
V_60 -> V_83 = F_22 ( V_64 -> V_83 & V_159 ) ;
}
if ( F_70 ( V_66 ) ) {
V_118 = F_71 ( V_64 -> V_84 ) ;
V_150 |= V_69 ;
if ( V_64 -> V_44 & V_79 )
V_150 |= V_78 ;
if ( V_64 -> V_44 & V_81 )
V_150 |= V_80 ;
} else {
V_118 = V_64 -> V_84 ;
if ( V_64 -> V_83 & V_88 )
V_150 |= V_87 ;
}
V_150 |= V_70 ;
if ( V_2 -> V_17 . V_27 & V_160 )
V_150 |= V_71 ;
V_60 -> V_44 = F_12 ( V_150 ) ;
V_60 -> V_161 = F_72 ( V_2 -> V_10 , V_118 ) ;
memcpy ( V_60 -> V_90 , V_64 -> V_89 , V_64 -> V_84 ) ;
V_60 -> V_74 = V_2 -> V_103 ;
F_33 ( & V_2 -> V_73 , V_44 ) ;
F_73 ( V_66 , V_36 , V_2 -> V_103 ) ;
V_2 -> V_103 = ( V_2 -> V_103 + 1 ) % V_2 -> V_17 . V_162 ;
V_151 = ! ! ( V_2 -> V_17 . V_102 [ V_2 -> V_103 ] ) ;
F_35 ( & V_2 -> V_73 , V_44 ) ;
V_2 -> V_163 ( V_2 , V_60 ) ;
if ( V_2 -> V_17 . V_27 & V_142 )
V_151 |= ( V_152 <
( sizeof( * V_60 ) + V_164 ) ) ;
else
V_151 |= ( V_152 <
( sizeof( * V_60 ) + V_165 ) ) ;
if ( V_151 )
F_66 ( V_36 ) ;
return V_153 ;
}
struct V_100 * F_74 ( int V_166 , int V_10 ,
int V_162 )
{
struct V_100 * V_36 ;
struct V_1 * V_2 ;
if ( V_162 < 0 )
V_162 = V_167 ;
V_36 = F_75 ( V_166 , V_162 ) ;
if ( ! V_36 )
return NULL ;
V_2 = F_58 ( V_36 ) ;
V_2 -> V_17 . V_18 = V_168 ;
V_2 -> V_17 . V_169 = & V_170 ;
V_2 -> V_17 . V_171 = & V_172 ;
V_2 -> V_17 . V_173 = F_57 ;
V_2 -> V_17 . V_174 = F_59 ;
V_2 -> V_17 . V_175 = F_63 ;
V_2 -> V_17 . V_176 = F_64 ;
V_2 -> V_17 . V_177 = V_160 |
V_134 |
V_28 |
V_142 |
V_143 |
V_178 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_3 = 0 ;
F_76 ( & V_2 -> V_73 ) ;
V_36 -> V_44 |= V_179 ;
V_36 -> V_180 = & V_181 ;
V_36 -> V_182 = V_10 ;
return V_36 ;
}
