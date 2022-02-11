static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
const int V_6 = V_2 -> V_6 ;
T_1 V_7 ;
int V_8 ;
struct V_9 * V_10 = & V_4 -> V_11 -> V_10 [ V_2 -> V_6 ] ;
T_2 V_12 = F_2 ( V_4 -> V_13 , V_10 , sizeof( * V_10 ) ,
V_14 ) ;
F_3 ( & V_4 -> V_15 [ V_6 ] ) ;
F_4 ( 0xffffffff , V_4 -> V_16 + F_5 ( V_6 ) ) ;
F_4 ( V_12 , V_4 -> V_16 + F_6 ( V_6 ) ) ;
F_4 ( 1 , V_4 -> V_16 + F_7 ( V_6 ) ) ;
V_8 = F_8 ( & V_4 -> V_15 [ V_6 ] ,
F_9 ( 1000 ) ) ;
if ( ! V_8 ) {
F_10 ( V_4 -> V_13 , L_1 ,
V_6 , F_11 ( V_4 -> V_16 + V_17 ) ) ;
return - V_18 ;
}
V_7 = F_11 ( V_4 -> V_16 + F_12 ( V_6 ) ) ;
if ( V_7 & 0xff ) {
F_10 ( V_4 -> V_13 , L_2 ,
V_6 , V_7 ) ;
return - V_19 ;
}
F_13 ( V_4 -> V_13 , V_12 , sizeof( * V_10 ) , V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_20 )
{
struct V_3 * V_4 = V_5 ;
struct V_9 * V_10 = & V_4 -> V_11 -> V_10 [ V_2 -> V_6 ] ;
int V_8 ;
T_2 V_21 = F_2 ( V_4 -> V_13 , V_4 -> V_11 -> V_22 ,
2 * V_23 ,
V_14 ) ;
T_2 V_24 = F_2 ( V_4 -> V_13 , V_4 -> V_11 -> V_25 ,
V_26 , V_14 ) ;
T_2 V_27 = F_2 ( V_4 -> V_13 , V_4 -> V_11 -> V_28 ,
V_26 , V_29 ) ;
V_10 -> V_30 = V_31 |
V_32 |
V_33 ;
V_10 -> V_30 |= V_34 ;
if ( V_2 -> V_35 )
V_10 -> V_30 |= V_36 ;
if ( V_20 )
V_10 -> V_30 |= V_37 ;
V_10 -> V_38 = V_39 ;
if ( V_2 -> V_40 )
V_10 -> V_38 |= V_41 ;
else
V_10 -> V_38 |= V_42 ;
V_10 -> V_43 = 0 ;
V_10 -> V_44 = V_24 ;
V_10 -> V_45 = V_27 ;
V_10 -> V_46 = V_2 -> V_47 ;
V_10 -> V_48 = V_21 ;
V_10 -> V_49 = 0 ;
V_8 = F_1 ( V_2 ) ;
F_13 ( V_4 -> V_13 , V_21 , 2 * V_23 ,
V_14 ) ;
F_13 ( V_4 -> V_13 , V_24 , V_26 , V_14 ) ;
F_13 ( V_4 -> V_13 , V_27 , V_26 , V_29 ) ;
return V_8 ;
}
static int F_15 ( struct V_50 * V_51 )
{
struct V_3 * V_4 = V_5 ;
struct V_52 * V_53 = F_16 ( V_51 ) ;
struct V_1 * V_2 = F_17 ( V_51 -> V_54 ) ;
struct V_55 * V_56 = V_53 -> V_56 ;
struct V_55 * V_57 = V_53 -> V_57 ;
const int V_58 = F_18 ( V_53 -> V_57 ) ;
const int V_59 = V_26 ;
T_3 * V_60 = V_4 -> V_11 -> V_25 ;
T_3 * V_61 = V_4 -> V_11 -> V_28 ;
T_3 * V_62 , * V_63 , * V_64 = NULL ;
T_1 V_65 = 0 ;
T_3 * V_66 = V_4 -> V_11 -> V_22 ;
int V_8 = 0 ;
int V_67 = 0 ;
unsigned int V_68 , V_69 , V_70 , V_71 = 0 ;
int V_20 = 0 ;
V_2 -> V_47 = 0 ;
memcpy ( V_66 , V_2 -> V_66 , V_2 -> V_72 ) ;
if ( ! V_2 -> V_40 ) {
memcpy ( V_66 + V_23 , V_53 -> V_73 , V_23 ) ;
V_20 = 1 ;
} else {
memset ( V_66 + V_23 , 0 , V_23 ) ;
}
F_19 (req->src, src, nents, i) {
V_63 = F_20 ( V_57 ) ;
V_69 = F_21 ( V_57 ) ;
do {
if ( V_2 -> V_47 + V_69 > V_59 )
V_70 = V_59 - V_2 -> V_47 ;
else
V_70 = V_69 ;
memcpy ( V_60 + V_2 -> V_47 , V_63 , V_70 ) ;
V_69 -= V_70 ;
V_63 += V_70 ;
V_2 -> V_47 += V_70 ;
if ( V_2 -> V_47 == V_59 || F_22 ( V_57 ) ) {
V_8 = F_14 ( V_2 , V_20 ) ;
if ( V_8 )
return V_8 ;
V_20 = 0 ;
V_62 = V_61 ;
while ( V_56 && V_2 -> V_47 ) {
if ( ! V_67 ) {
V_64 = F_20 ( V_56 ) ;
V_65 = 0 ;
}
V_71 = F_23 ( F_21 ( V_56 ) - V_65 ,
V_2 -> V_47 ) ;
memcpy ( V_64 + V_65 , V_62 , V_71 ) ;
V_62 += V_71 ;
V_65 += V_71 ;
V_2 -> V_47 -= V_71 ;
if ( V_65 == F_21 ( V_56 ) ) {
V_56 = F_24 ( V_56 ) ;
V_67 = 0 ;
} else {
V_67 = 1 ;
}
}
}
} while ( V_69 );
}
return V_8 ;
}
static int F_25 ( void * V_74 )
{
struct V_3 * V_4 = V_5 ;
const int V_6 = V_75 ;
struct V_50 * V_76 ;
struct V_50 * V_51 ;
int V_8 ;
do {
F_26 ( V_77 ) ;
F_27 ( & V_4 -> V_78 [ V_6 ] ) ;
V_76 = F_28 ( & V_4 -> V_79 [ V_6 ] ) ;
V_51 = F_29 ( & V_4 -> V_79 [ V_6 ] ) ;
F_30 ( & V_4 -> V_78 [ V_6 ] ) ;
if ( V_76 )
V_76 -> V_80 ( V_76 , - V_81 ) ;
if ( V_51 ) {
V_8 = F_15 ( V_51 ) ;
V_51 -> V_80 ( V_51 , V_8 ) ;
continue;
}
F_31 () ;
} while ( ! F_32 () );
return 0 ;
}
static int F_33 ( struct V_52 * V_53 , int V_35 )
{
struct V_82 * V_54 =
F_34 ( F_35 ( V_53 ) ) ;
struct V_1 * V_83 = F_36 (
F_35 ( V_53 ) ) ;
int V_8 ;
F_37 ( V_53 , V_83 -> V_84 ) ;
if ( V_35 )
V_8 = F_38 ( V_53 ) ;
else
V_8 = F_39 ( V_53 ) ;
F_37 ( V_53 , F_40 ( V_54 ) ) ;
return V_8 ;
}
static int F_41 ( struct V_52 * V_53 , int V_35 , int V_40 )
{
struct V_3 * V_4 = V_5 ;
struct V_50 * V_51 = & V_53 -> V_16 ;
struct V_1 * V_2 = F_17 ( V_51 -> V_54 ) ;
int V_8 ;
if ( F_42 ( V_2 -> V_72 != V_23 ) )
return F_33 ( V_53 , V_35 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_6 = V_75 ;
F_27 ( & V_4 -> V_78 [ V_2 -> V_6 ] ) ;
V_8 = F_43 ( & V_4 -> V_79 [ V_2 -> V_6 ] , & V_53 -> V_16 ) ;
F_30 ( & V_4 -> V_78 [ V_2 -> V_6 ] ) ;
F_44 ( V_4 -> V_85 [ V_2 -> V_6 ] ) ;
return - V_81 ;
}
static int F_45 ( struct V_52 * V_53 )
{
return F_41 ( V_53 , 0 , 1 ) ;
}
static int F_46 ( struct V_52 * V_53 )
{
return F_41 ( V_53 , 1 , 1 ) ;
}
static int F_47 ( struct V_52 * V_53 )
{
return F_41 ( V_53 , 0 , 0 ) ;
}
static int F_48 ( struct V_52 * V_53 )
{
return F_41 ( V_53 , 1 , 0 ) ;
}
static int F_49 ( struct V_86 * V_54 , const T_4 * V_66 ,
unsigned int V_69 )
{
struct V_1 * V_2 = F_36 ( V_54 ) ;
unsigned int V_8 ;
V_2 -> V_72 = V_69 ;
if ( V_69 == V_23 ) {
memcpy ( V_2 -> V_66 , V_66 , V_69 ) ;
return 0 ;
}
if ( V_69 != V_87 && V_69 != V_88 ) {
V_54 -> V_16 . V_89 |= V_90 ;
return - V_19 ;
}
V_2 -> V_84 -> V_16 . V_89 &= ~ V_91 ;
V_2 -> V_84 -> V_16 . V_89 |=
V_54 -> V_16 . V_89 & V_91 ;
V_8 = F_50 ( V_2 -> V_84 , V_66 , V_69 ) ;
if ( ! V_8 )
return 0 ;
V_54 -> V_16 . V_89 &= ~ V_92 ;
V_54 -> V_16 . V_89 |=
V_2 -> V_84 -> V_16 . V_89 & V_92 ;
return V_8 ;
}
static int F_51 ( struct V_82 * V_54 )
{
const char * V_93 = V_54 -> V_94 -> V_95 ;
const T_1 V_96 = V_97 | V_98 ;
struct V_1 * V_2 = F_17 ( V_54 ) ;
struct V_86 * V_99 ;
V_99 = F_52 ( V_93 , 0 , V_96 ) ;
if ( F_53 ( V_99 ) )
return F_54 ( V_99 ) ;
V_2 -> V_84 = V_99 ;
V_54 -> V_100 . V_101 = sizeof( struct V_1 ) ;
return 0 ;
}
static void F_55 ( struct V_82 * V_54 )
{
struct V_1 * V_2 = F_17 ( V_54 ) ;
F_56 ( V_2 -> V_84 ) ;
V_2 -> V_84 = NULL ;
}
static int F_57 ( struct V_102 * V_53 )
{
struct V_3 * V_4 = V_5 ;
int V_8 ;
struct V_103 * V_54 = F_58 ( V_53 ) ;
struct V_1 * V_2 = F_59 ( V_54 ) ;
struct V_104 * V_105 = F_60 ( V_53 ) ;
struct V_9 * V_10 = & V_4 -> V_11 -> V_10 [ V_2 -> V_6 ] ;
T_2 V_106 = F_2 ( V_4 -> V_13 ,
V_4 -> V_11 -> V_107 ,
V_108 ,
V_29 ) ;
T_2 V_109 = F_2 ( V_4 -> V_13 , V_4 -> V_11 -> V_110 ,
V_26 , V_14 ) ;
V_10 -> V_30 = V_31 |
V_32 |
V_111 ;
if ( V_105 -> V_20 )
V_10 -> V_30 |= V_112 ;
V_10 -> V_38 = V_2 -> V_113 ;
V_10 -> V_43 = 0 ;
V_10 -> V_44 = V_109 ;
V_10 -> V_45 = 0 ;
V_10 -> V_46 = V_2 -> V_47 ;
V_10 -> V_48 = 0 ;
V_10 -> V_49 = 0 ;
if ( V_105 -> V_114 ) {
V_10 -> V_30 |= V_115 ;
V_10 -> V_48 = V_106 ;
}
V_8 = F_1 ( V_2 ) ;
F_13 ( V_4 -> V_13 , V_106 , V_108 ,
V_29 ) ;
F_13 ( V_4 -> V_13 , V_109 , V_26 , V_14 ) ;
return V_8 ;
}
static int F_61 ( struct V_50 * V_51 )
{
struct V_3 * V_4 = V_5 ;
struct V_102 * V_53 = F_62 ( V_51 ) ;
struct V_103 * V_54 = F_58 ( V_53 ) ;
struct V_1 * V_2 = F_59 ( V_54 ) ;
struct V_104 * V_105 = F_60 ( V_53 ) ;
struct V_116 * V_117 = F_63 ( V_54 ) ;
const int V_58 = F_18 ( V_53 -> V_57 ) ;
T_3 * V_118 = V_4 -> V_11 -> V_107 ;
T_3 * V_60 = V_4 -> V_11 -> V_110 ;
T_3 * V_63 ;
struct V_55 * V_57 ;
unsigned int V_68 , V_69 , V_70 ;
int V_8 ;
int V_119 = V_105 -> V_114 ;
if ( V_119 )
V_105 -> V_114 = 0 ;
F_19 (req->src, src, nents, i) {
V_63 = F_20 ( V_57 ) ;
V_69 = F_21 ( V_57 ) ;
do {
if ( V_2 -> V_47 + V_69 > V_26 )
V_70 = V_26 - V_2 -> V_47 ;
else
V_70 = V_69 ;
memcpy ( V_60 + V_2 -> V_47 , V_63 , V_70 ) ;
V_69 -= V_70 ;
V_63 += V_70 ;
V_2 -> V_47 += V_70 ;
if ( V_69 && V_2 -> V_47 == V_26 ) {
V_8 = F_57 ( V_53 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_47 = 0 ;
V_105 -> V_20 = 0 ;
}
} while ( V_69 );
}
if ( V_119 ) {
V_105 -> V_114 = 1 ;
V_8 = F_57 ( V_53 ) ;
if ( V_8 || ! V_53 -> V_120 )
return V_8 ;
V_2 -> V_47 = 0 ;
for ( V_68 = 0 ; V_68 < V_117 -> V_121 ; V_68 ++ )
V_53 -> V_120 [ V_68 ] = V_118 [ V_117 -> V_121 - V_68 - 1 ] ;
}
return 0 ;
}
static int F_64 ( void * V_74 )
{
struct V_3 * V_4 = V_5 ;
const int V_6 = V_122 ;
struct V_50 * V_76 ;
struct V_50 * V_51 ;
struct V_104 * V_105 ;
struct V_102 * V_53 ;
int V_8 , V_114 ;
do {
F_26 ( V_77 ) ;
F_27 ( & V_4 -> V_78 [ V_6 ] ) ;
V_76 = F_28 ( & V_4 -> V_79 [ V_6 ] ) ;
V_51 = F_29 ( & V_4 -> V_79 [ V_6 ] ) ;
F_30 ( & V_4 -> V_78 [ V_6 ] ) ;
if ( V_76 )
V_76 -> V_80 ( V_76 , - V_81 ) ;
if ( V_51 ) {
V_53 = F_62 ( V_51 ) ;
V_105 = F_60 ( V_53 ) ;
V_8 = F_61 ( V_51 ) ;
V_114 = V_105 -> V_114 ;
V_51 -> V_80 ( V_51 , V_8 ) ;
if ( ! V_114 )
continue;
}
F_31 () ;
} while ( ! F_32 () );
return 0 ;
}
static int F_65 ( struct V_102 * V_53 )
{
struct V_103 * V_54 = F_58 ( V_53 ) ;
struct V_1 * V_2 = F_59 ( V_54 ) ;
struct V_116 * V_117 = F_63 ( V_54 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
if ( strcmp ( V_117 -> V_16 . V_95 , L_3 ) == 0 )
V_2 -> V_113 = V_123 ;
else
V_2 -> V_113 = V_124 ;
V_2 -> V_47 = 0 ;
V_2 -> V_125 = 0 ;
V_2 -> V_6 = V_122 ;
F_66 ( & V_2 -> V_78 ) ;
return 0 ;
}
static int F_67 ( struct V_102 * V_53 , int V_114 )
{
struct V_3 * V_4 = V_5 ;
struct V_104 * V_105 = F_60 ( V_53 ) ;
struct V_103 * V_54 = F_58 ( V_53 ) ;
struct V_1 * V_2 = F_59 ( V_54 ) ;
int V_8 ;
if ( ! V_53 -> V_126 && ! V_114 )
return 0 ;
F_27 ( & V_2 -> V_78 ) ;
V_105 -> V_114 = V_114 ;
if ( ! V_2 -> V_125 ) {
V_2 -> V_125 = 1 ;
V_105 -> V_20 = 1 ;
}
F_27 ( & V_4 -> V_78 [ V_2 -> V_6 ] ) ;
V_8 = F_43 ( & V_4 -> V_79 [ V_2 -> V_6 ] , & V_53 -> V_16 ) ;
F_30 ( & V_4 -> V_78 [ V_2 -> V_6 ] ) ;
F_44 ( V_4 -> V_85 [ V_2 -> V_6 ] ) ;
F_30 ( & V_2 -> V_78 ) ;
return - V_81 ;
}
static int F_68 ( struct V_102 * V_53 )
{
return F_67 ( V_53 , 0 ) ;
}
static int F_69 ( struct V_102 * V_53 )
{
F_70 ( V_53 , NULL , V_53 -> V_120 , 0 ) ;
V_53 -> V_126 = 0 ;
return F_67 ( V_53 , 1 ) ;
}
static int F_71 ( struct V_102 * V_53 )
{
return F_67 ( V_53 , 1 ) ;
}
static int F_72 ( struct V_102 * V_53 )
{
int V_8 ;
V_8 = F_65 ( V_53 ) ;
if ( V_8 )
return V_8 ;
return F_71 ( V_53 ) ;
}
static int F_73 ( struct V_82 * V_54 )
{
F_74 ( F_75 ( V_54 ) ,
sizeof( struct V_104 ) ) ;
return 0 ;
}
static void F_76 ( struct V_82 * V_54 )
{
}
static T_5 F_77 ( int V_127 , void * V_128 )
{
struct V_3 * V_4 = V_128 ;
T_1 V_7 ;
int V_68 ;
V_7 = F_11 ( V_4 -> V_16 + V_17 ) ;
V_7 &= V_129 ;
if ( ! V_7 )
return V_130 ;
F_4 ( V_7 , V_4 -> V_16 + V_131 ) ;
for ( V_68 = 0 ; V_68 < V_132 ; V_68 ++ )
if ( V_7 & ( 1 << V_68 ) )
V_80 ( & V_4 -> V_15 [ V_68 ] ) ;
return V_133 ;
}
static int F_78 ( struct V_134 * V_135 )
{
struct V_136 * V_13 = & V_135 -> V_13 ;
struct V_3 * V_4 = NULL ;
int V_68 , V_8 ;
struct V_137 * V_138 ;
int V_139 , V_140 ;
F_27 ( & V_141 ) ;
if ( V_5 ) {
F_10 ( V_13 , L_4 ) ;
V_8 = - V_142 ;
goto V_143;
}
V_138 = F_79 ( V_135 , V_144 , 0 ) ;
V_139 = F_80 ( V_135 , 0 ) ;
V_140 = F_80 ( V_135 , 1 ) ;
if ( V_139 < 0 || V_140 < 0 ) {
V_8 = - V_19 ;
goto V_143;
}
V_4 = F_81 ( V_13 , sizeof( * V_4 ) , V_145 ) ;
if ( ! V_4 ) {
V_8 = - V_146 ;
goto V_143;
}
V_4 -> V_13 = V_13 ;
V_4 -> V_16 = F_82 ( V_13 , V_138 ) ;
if ( F_53 ( V_4 -> V_16 ) ) {
V_8 = F_54 ( V_4 -> V_16 ) ;
goto V_143;
}
V_8 = F_83 ( V_13 , V_139 , F_77 , 0 ,
L_5 , V_4 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_6 ) ;
goto V_143;
}
V_8 = F_83 ( V_13 , V_140 , F_77 , 0 ,
L_7 , V_4 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_8 ) ;
goto V_143;
}
V_4 -> V_11 = F_84 ( sizeof( struct V_147 ) , V_145 ) ;
if ( ! V_4 -> V_11 ) {
F_10 ( V_13 , L_9 ) ;
V_8 = - V_146 ;
goto V_143;
}
F_85 ( V_4 -> V_16 ) ;
F_4 ( V_148 |
V_149 | 0xf ,
V_4 -> V_16 + V_150 ) ;
F_4 ( V_151 ,
V_4 -> V_16 + V_152 ) ;
F_4 ( 0xffff0000 , V_4 -> V_16 + V_153 ) ;
for ( V_68 = 0 ; V_68 < V_132 ; V_68 ++ )
F_4 ( 0xffffffff , V_4 -> V_16 + F_5 ( V_68 ) ) ;
F_4 ( 0xffffffff , V_4 -> V_16 + V_131 ) ;
V_5 = V_4 ;
F_86 ( V_135 , V_4 ) ;
for ( V_68 = 0 ; V_68 < V_132 ; V_68 ++ ) {
F_66 ( & V_4 -> V_78 [ V_68 ] ) ;
F_87 ( & V_4 -> V_15 [ V_68 ] ) ;
F_88 ( & V_4 -> V_79 [ V_68 ] , 50 ) ;
}
V_4 -> V_85 [ V_122 ] = F_89 ( F_64 ,
NULL , L_10 ) ;
if ( F_53 ( V_4 -> V_85 [ V_122 ] ) ) {
F_10 ( V_13 , L_11 ) ;
V_8 = F_54 ( V_4 -> V_85 [ V_122 ] ) ;
goto V_154;
}
V_4 -> V_85 [ V_75 ] = F_89 ( F_25 ,
NULL , L_12 ) ;
if ( F_53 ( V_4 -> V_85 [ V_75 ] ) ) {
F_10 ( V_13 , L_11 ) ;
V_8 = F_54 ( V_4 -> V_85 [ V_75 ] ) ;
goto V_155;
}
V_4 -> V_156 = F_11 ( V_4 -> V_16 + V_157 ) ;
if ( V_4 -> V_156 & V_158 ) {
V_8 = F_90 ( V_159 ,
F_91 ( V_159 ) ) ;
if ( V_8 ) {
F_10 ( V_13 , L_13 ) ;
goto V_160;
}
}
if ( V_4 -> V_156 & V_161 ) {
V_8 = F_92 ( & V_162 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_14 ,
V_162 . V_117 . V_16 . V_95 ) ;
goto V_163;
}
}
if ( V_4 -> V_156 & V_164 ) {
V_8 = F_92 ( & V_165 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_14 ,
V_165 . V_117 . V_16 . V_95 ) ;
goto V_166;
}
}
return 0 ;
V_166:
if ( V_4 -> V_156 & V_161 )
F_93 ( & V_162 ) ;
V_163:
if ( V_4 -> V_156 & V_158 )
F_94 ( V_159 , F_91 ( V_159 ) ) ;
V_160:
F_95 ( V_4 -> V_85 [ V_75 ] ) ;
V_155:
F_95 ( V_4 -> V_85 [ V_122 ] ) ;
V_154:
F_96 ( V_4 -> V_11 ) ;
V_143:
F_30 ( & V_141 ) ;
return V_8 ;
}
static int F_97 ( struct V_134 * V_135 )
{
struct V_3 * V_4 = F_98 ( V_135 ) ;
F_96 ( V_4 -> V_11 ) ;
if ( V_4 -> V_156 & V_164 )
F_93 ( & V_165 ) ;
if ( V_4 -> V_156 & V_161 )
F_93 ( & V_162 ) ;
if ( V_4 -> V_156 & V_158 )
F_94 ( V_159 , F_91 ( V_159 ) ) ;
F_95 ( V_4 -> V_85 [ V_122 ] ) ;
F_95 ( V_4 -> V_85 [ V_75 ] ) ;
F_86 ( V_135 , NULL ) ;
F_27 ( & V_141 ) ;
V_5 = NULL ;
F_30 ( & V_141 ) ;
return 0 ;
}
