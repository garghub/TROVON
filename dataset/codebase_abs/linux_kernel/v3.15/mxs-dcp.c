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
static int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 , int V_22 )
{
struct V_3 * V_4 = V_5 ;
struct V_9 * V_10 = & V_4 -> V_11 -> V_10 [ V_2 -> V_6 ] ;
struct V_23 * V_24 = F_15 ( V_21 ) ;
int V_8 ;
T_2 V_25 = F_2 ( V_4 -> V_13 , V_4 -> V_11 -> V_26 ,
2 * V_27 ,
V_14 ) ;
T_2 V_28 = F_2 ( V_4 -> V_13 , V_4 -> V_11 -> V_29 ,
V_30 , V_14 ) ;
T_2 V_31 = F_2 ( V_4 -> V_13 , V_4 -> V_11 -> V_32 ,
V_30 , V_33 ) ;
V_10 -> V_34 = V_35 |
V_36 |
V_37 ;
V_10 -> V_34 |= V_38 ;
if ( V_24 -> V_39 )
V_10 -> V_34 |= V_40 ;
if ( V_22 )
V_10 -> V_34 |= V_41 ;
V_10 -> V_42 = V_43 ;
if ( V_24 -> V_44 )
V_10 -> V_42 |= V_45 ;
else
V_10 -> V_42 |= V_46 ;
V_10 -> V_47 = 0 ;
V_10 -> V_48 = V_28 ;
V_10 -> V_49 = V_31 ;
V_10 -> V_50 = V_2 -> V_51 ;
V_10 -> V_52 = V_25 ;
V_10 -> V_53 = 0 ;
V_8 = F_1 ( V_2 ) ;
F_13 ( V_4 -> V_13 , V_25 , 2 * V_27 ,
V_14 ) ;
F_13 ( V_4 -> V_13 , V_28 , V_30 , V_14 ) ;
F_13 ( V_4 -> V_13 , V_31 , V_30 , V_33 ) ;
return V_8 ;
}
static int F_16 ( struct V_54 * V_55 )
{
struct V_3 * V_4 = V_5 ;
struct V_20 * V_21 = F_17 ( V_55 ) ;
struct V_1 * V_2 = F_18 ( V_55 -> V_56 ) ;
struct V_23 * V_24 = F_15 ( V_21 ) ;
struct V_57 * V_58 = V_21 -> V_58 ;
struct V_57 * V_59 = V_21 -> V_59 ;
const int V_60 = F_19 ( V_21 -> V_59 ) ;
const int V_61 = V_30 ;
T_3 * V_62 = V_4 -> V_11 -> V_29 ;
T_3 * V_63 = V_4 -> V_11 -> V_32 ;
T_3 * V_64 , * V_65 , * V_66 = NULL ;
T_1 V_67 = 0 ;
T_3 * V_68 = V_4 -> V_11 -> V_26 ;
int V_8 = 0 ;
int V_69 = 0 ;
unsigned int V_70 , V_71 , V_72 , V_73 = 0 ;
int V_22 = 0 ;
V_2 -> V_51 = 0 ;
memcpy ( V_68 , V_2 -> V_68 , V_2 -> V_74 ) ;
if ( ! V_24 -> V_44 ) {
memcpy ( V_68 + V_27 , V_21 -> V_75 , V_27 ) ;
V_22 = 1 ;
} else {
memset ( V_68 + V_27 , 0 , V_27 ) ;
}
F_20 (req->src, src, nents, i) {
V_65 = F_21 ( V_59 ) ;
V_71 = F_22 ( V_59 ) ;
do {
if ( V_2 -> V_51 + V_71 > V_61 )
V_72 = V_61 - V_2 -> V_51 ;
else
V_72 = V_71 ;
memcpy ( V_62 + V_2 -> V_51 , V_65 , V_72 ) ;
V_71 -= V_72 ;
V_65 += V_72 ;
V_2 -> V_51 += V_72 ;
if ( V_2 -> V_51 == V_61 || F_23 ( V_59 ) ) {
V_8 = F_14 ( V_2 , V_21 , V_22 ) ;
if ( V_8 )
return V_8 ;
V_22 = 0 ;
V_64 = V_63 ;
while ( V_58 && V_2 -> V_51 ) {
if ( ! V_69 ) {
V_66 = F_21 ( V_58 ) ;
V_67 = 0 ;
}
V_73 = F_24 ( F_22 ( V_58 ) - V_67 ,
V_2 -> V_51 ) ;
memcpy ( V_66 + V_67 , V_64 , V_73 ) ;
V_64 += V_73 ;
V_67 += V_73 ;
V_2 -> V_51 -= V_73 ;
if ( V_67 == F_22 ( V_58 ) ) {
V_58 = F_25 ( V_58 ) ;
V_69 = 0 ;
} else {
V_69 = 1 ;
}
}
}
} while ( V_71 );
}
return V_8 ;
}
static int F_26 ( void * V_76 )
{
struct V_3 * V_4 = V_5 ;
const int V_6 = V_77 ;
struct V_54 * V_78 ;
struct V_54 * V_55 ;
int V_8 ;
do {
F_27 ( V_79 ) ;
F_28 ( & V_4 -> V_80 [ V_6 ] ) ;
V_78 = F_29 ( & V_4 -> V_81 [ V_6 ] ) ;
V_55 = F_30 ( & V_4 -> V_81 [ V_6 ] ) ;
F_31 ( & V_4 -> V_80 [ V_6 ] ) ;
if ( V_78 )
V_78 -> V_82 ( V_78 , - V_83 ) ;
if ( V_55 ) {
V_8 = F_16 ( V_55 ) ;
V_55 -> V_82 ( V_55 , V_8 ) ;
continue;
}
F_32 () ;
} while ( ! F_33 () );
return 0 ;
}
static int F_34 ( struct V_20 * V_21 , int V_39 )
{
struct V_84 * V_56 =
F_35 ( F_36 ( V_21 ) ) ;
struct V_1 * V_85 = F_37 (
F_36 ( V_21 ) ) ;
int V_8 ;
F_38 ( V_21 , V_85 -> V_86 ) ;
if ( V_39 )
V_8 = F_39 ( V_21 ) ;
else
V_8 = F_40 ( V_21 ) ;
F_38 ( V_21 , F_41 ( V_56 ) ) ;
return V_8 ;
}
static int F_42 ( struct V_20 * V_21 , int V_39 , int V_44 )
{
struct V_3 * V_4 = V_5 ;
struct V_54 * V_55 = & V_21 -> V_16 ;
struct V_1 * V_2 = F_18 ( V_55 -> V_56 ) ;
struct V_23 * V_24 = F_15 ( V_21 ) ;
int V_8 ;
if ( F_43 ( V_2 -> V_74 != V_27 ) )
return F_34 ( V_21 , V_39 ) ;
V_24 -> V_39 = V_39 ;
V_24 -> V_44 = V_44 ;
V_2 -> V_6 = V_77 ;
F_28 ( & V_4 -> V_80 [ V_2 -> V_6 ] ) ;
V_8 = F_44 ( & V_4 -> V_81 [ V_2 -> V_6 ] , & V_21 -> V_16 ) ;
F_31 ( & V_4 -> V_80 [ V_2 -> V_6 ] ) ;
F_45 ( V_4 -> V_87 [ V_2 -> V_6 ] ) ;
return - V_83 ;
}
static int F_46 ( struct V_20 * V_21 )
{
return F_42 ( V_21 , 0 , 1 ) ;
}
static int F_47 ( struct V_20 * V_21 )
{
return F_42 ( V_21 , 1 , 1 ) ;
}
static int F_48 ( struct V_20 * V_21 )
{
return F_42 ( V_21 , 0 , 0 ) ;
}
static int F_49 ( struct V_20 * V_21 )
{
return F_42 ( V_21 , 1 , 0 ) ;
}
static int F_50 ( struct V_88 * V_56 , const T_4 * V_68 ,
unsigned int V_71 )
{
struct V_1 * V_2 = F_37 ( V_56 ) ;
unsigned int V_8 ;
V_2 -> V_74 = V_71 ;
if ( V_71 == V_27 ) {
memcpy ( V_2 -> V_68 , V_68 , V_71 ) ;
return 0 ;
}
if ( V_71 != V_89 && V_71 != V_90 ) {
V_56 -> V_16 . V_91 |= V_92 ;
return - V_19 ;
}
V_2 -> V_86 -> V_16 . V_91 &= ~ V_93 ;
V_2 -> V_86 -> V_16 . V_91 |=
V_56 -> V_16 . V_91 & V_93 ;
V_8 = F_51 ( V_2 -> V_86 , V_68 , V_71 ) ;
if ( ! V_8 )
return 0 ;
V_56 -> V_16 . V_91 &= ~ V_94 ;
V_56 -> V_16 . V_91 |=
V_2 -> V_86 -> V_16 . V_91 & V_94 ;
return V_8 ;
}
static int F_52 ( struct V_84 * V_56 )
{
const char * V_95 = V_56 -> V_96 -> V_97 ;
const T_1 V_98 = V_99 | V_100 ;
struct V_1 * V_2 = F_18 ( V_56 ) ;
struct V_88 * V_101 ;
V_101 = F_53 ( V_95 , 0 , V_98 ) ;
if ( F_54 ( V_101 ) )
return F_55 ( V_101 ) ;
V_2 -> V_86 = V_101 ;
V_56 -> V_102 . V_103 = sizeof( struct V_23 ) ;
return 0 ;
}
static void F_56 ( struct V_84 * V_56 )
{
struct V_1 * V_2 = F_18 ( V_56 ) ;
F_57 ( V_2 -> V_86 ) ;
V_2 -> V_86 = NULL ;
}
static int F_58 ( struct V_104 * V_21 )
{
struct V_3 * V_4 = V_5 ;
int V_8 ;
struct V_105 * V_56 = F_59 ( V_21 ) ;
struct V_1 * V_2 = F_60 ( V_56 ) ;
struct V_106 * V_24 = F_61 ( V_21 ) ;
struct V_107 * V_108 = F_62 ( V_56 ) ;
struct V_9 * V_10 = & V_4 -> V_11 -> V_10 [ V_2 -> V_6 ] ;
T_2 V_109 = 0 ;
T_2 V_110 = F_2 ( V_4 -> V_13 , V_4 -> V_11 -> V_111 ,
V_30 , V_14 ) ;
V_10 -> V_34 = V_35 |
V_36 |
V_112 ;
if ( V_24 -> V_22 )
V_10 -> V_34 |= V_113 ;
V_10 -> V_42 = V_2 -> V_114 ;
V_10 -> V_47 = 0 ;
V_10 -> V_48 = V_110 ;
V_10 -> V_49 = 0 ;
V_10 -> V_50 = V_2 -> V_51 ;
V_10 -> V_52 = 0 ;
V_10 -> V_53 = 0 ;
if ( V_24 -> V_115 ) {
V_109 = F_2 ( V_4 -> V_13 , V_21 -> V_116 ,
V_108 -> V_117 , V_33 ) ;
V_10 -> V_34 |= V_118 ;
V_10 -> V_52 = V_109 ;
}
V_8 = F_1 ( V_2 ) ;
if ( V_24 -> V_115 )
F_13 ( V_4 -> V_13 , V_109 , V_108 -> V_117 ,
V_33 ) ;
F_13 ( V_4 -> V_13 , V_110 , V_30 , V_14 ) ;
return V_8 ;
}
static int F_63 ( struct V_54 * V_55 )
{
struct V_3 * V_4 = V_5 ;
struct V_104 * V_21 = F_64 ( V_55 ) ;
struct V_105 * V_56 = F_59 ( V_21 ) ;
struct V_1 * V_2 = F_60 ( V_56 ) ;
struct V_106 * V_24 = F_61 ( V_21 ) ;
struct V_107 * V_108 = F_62 ( V_56 ) ;
const int V_60 = F_19 ( V_21 -> V_59 ) ;
T_3 * V_62 = V_4 -> V_11 -> V_111 ;
T_3 * V_65 ;
struct V_57 * V_59 ;
unsigned int V_70 , V_71 , V_72 ;
int V_8 ;
int V_119 = V_24 -> V_115 ;
if ( V_119 )
V_24 -> V_115 = 0 ;
F_20 (req->src, src, nents, i) {
V_65 = F_21 ( V_59 ) ;
V_71 = F_22 ( V_59 ) ;
do {
if ( V_2 -> V_51 + V_71 > V_30 )
V_72 = V_30 - V_2 -> V_51 ;
else
V_72 = V_71 ;
memcpy ( V_62 + V_2 -> V_51 , V_65 , V_72 ) ;
V_71 -= V_72 ;
V_65 += V_72 ;
V_2 -> V_51 += V_72 ;
if ( V_71 && V_2 -> V_51 == V_30 ) {
V_8 = F_58 ( V_21 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_51 = 0 ;
V_24 -> V_22 = 0 ;
}
} while ( V_71 );
}
if ( V_119 ) {
V_24 -> V_115 = 1 ;
if ( ! V_21 -> V_116 )
return - V_19 ;
V_8 = F_58 ( V_21 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_51 = 0 ;
for ( V_70 = 0 ; V_70 < V_108 -> V_117 / 2 ; V_70 ++ ) {
F_65 ( V_21 -> V_116 [ V_70 ] ,
V_21 -> V_116 [ V_108 -> V_117 - V_70 - 1 ] ) ;
}
}
return 0 ;
}
static int F_66 ( void * V_76 )
{
struct V_3 * V_4 = V_5 ;
const int V_6 = V_120 ;
struct V_54 * V_78 ;
struct V_54 * V_55 ;
struct V_106 * V_24 ;
struct V_104 * V_21 ;
int V_8 , V_115 ;
do {
F_27 ( V_79 ) ;
F_28 ( & V_4 -> V_80 [ V_6 ] ) ;
V_78 = F_29 ( & V_4 -> V_81 [ V_6 ] ) ;
V_55 = F_30 ( & V_4 -> V_81 [ V_6 ] ) ;
F_31 ( & V_4 -> V_80 [ V_6 ] ) ;
if ( V_78 )
V_78 -> V_82 ( V_78 , - V_83 ) ;
if ( V_55 ) {
V_21 = F_64 ( V_55 ) ;
V_24 = F_61 ( V_21 ) ;
V_8 = F_63 ( V_55 ) ;
V_115 = V_24 -> V_115 ;
V_55 -> V_82 ( V_55 , V_8 ) ;
if ( ! V_115 )
continue;
}
F_32 () ;
} while ( ! F_33 () );
return 0 ;
}
static int F_67 ( struct V_104 * V_21 )
{
struct V_105 * V_56 = F_59 ( V_21 ) ;
struct V_1 * V_2 = F_60 ( V_56 ) ;
struct V_107 * V_108 = F_62 ( V_56 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
if ( strcmp ( V_108 -> V_16 . V_97 , L_3 ) == 0 )
V_2 -> V_114 = V_121 ;
else
V_2 -> V_114 = V_122 ;
V_2 -> V_51 = 0 ;
V_2 -> V_123 = 0 ;
V_2 -> V_6 = V_120 ;
F_68 ( & V_2 -> V_80 ) ;
return 0 ;
}
static int F_69 ( struct V_104 * V_21 , int V_115 )
{
struct V_3 * V_4 = V_5 ;
struct V_106 * V_24 = F_61 ( V_21 ) ;
struct V_105 * V_56 = F_59 ( V_21 ) ;
struct V_1 * V_2 = F_60 ( V_56 ) ;
int V_8 ;
if ( ! V_21 -> V_124 && ! V_115 )
return 0 ;
F_28 ( & V_2 -> V_80 ) ;
V_24 -> V_115 = V_115 ;
if ( ! V_2 -> V_123 ) {
V_2 -> V_123 = 1 ;
V_24 -> V_22 = 1 ;
}
F_28 ( & V_4 -> V_80 [ V_2 -> V_6 ] ) ;
V_8 = F_44 ( & V_4 -> V_81 [ V_2 -> V_6 ] , & V_21 -> V_16 ) ;
F_31 ( & V_4 -> V_80 [ V_2 -> V_6 ] ) ;
F_45 ( V_4 -> V_87 [ V_2 -> V_6 ] ) ;
F_31 ( & V_2 -> V_80 ) ;
return - V_83 ;
}
static int F_70 ( struct V_104 * V_21 )
{
return F_69 ( V_21 , 0 ) ;
}
static int F_71 ( struct V_104 * V_21 )
{
F_72 ( V_21 , NULL , V_21 -> V_116 , 0 ) ;
V_21 -> V_124 = 0 ;
return F_69 ( V_21 , 1 ) ;
}
static int F_73 ( struct V_104 * V_21 )
{
return F_69 ( V_21 , 1 ) ;
}
static int F_74 ( struct V_104 * V_21 )
{
int V_8 ;
V_8 = F_67 ( V_21 ) ;
if ( V_8 )
return V_8 ;
return F_73 ( V_21 ) ;
}
static int F_75 ( struct V_84 * V_56 )
{
F_76 ( F_77 ( V_56 ) ,
sizeof( struct V_106 ) ) ;
return 0 ;
}
static void F_78 ( struct V_84 * V_56 )
{
}
static T_5 F_79 ( int V_125 , void * V_126 )
{
struct V_3 * V_4 = V_126 ;
T_1 V_7 ;
int V_70 ;
V_7 = F_11 ( V_4 -> V_16 + V_17 ) ;
V_7 &= V_127 ;
if ( ! V_7 )
return V_128 ;
F_4 ( V_7 , V_4 -> V_16 + V_129 ) ;
for ( V_70 = 0 ; V_70 < V_130 ; V_70 ++ )
if ( V_7 & ( 1 << V_70 ) )
V_82 ( & V_4 -> V_15 [ V_70 ] ) ;
return V_131 ;
}
static int F_80 ( struct V_132 * V_133 )
{
struct V_134 * V_13 = & V_133 -> V_13 ;
struct V_3 * V_4 = NULL ;
int V_70 , V_8 ;
struct V_135 * V_136 ;
int V_137 , V_138 ;
F_28 ( & V_139 ) ;
if ( V_5 ) {
F_10 ( V_13 , L_4 ) ;
V_8 = - V_140 ;
goto V_141;
}
V_136 = F_81 ( V_133 , V_142 , 0 ) ;
V_137 = F_82 ( V_133 , 0 ) ;
if ( V_137 < 0 ) {
V_8 = V_137 ;
goto V_141;
}
V_138 = F_82 ( V_133 , 1 ) ;
if ( V_138 < 0 ) {
V_8 = V_138 ;
goto V_141;
}
V_4 = F_83 ( V_13 , sizeof( * V_4 ) , V_143 ) ;
if ( ! V_4 ) {
V_8 = - V_144 ;
goto V_141;
}
V_4 -> V_13 = V_13 ;
V_4 -> V_16 = F_84 ( V_13 , V_136 ) ;
if ( F_54 ( V_4 -> V_16 ) ) {
V_8 = F_55 ( V_4 -> V_16 ) ;
goto V_141;
}
V_8 = F_85 ( V_13 , V_137 , F_79 , 0 ,
L_5 , V_4 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_6 ) ;
goto V_141;
}
V_8 = F_85 ( V_13 , V_138 , F_79 , 0 ,
L_7 , V_4 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_8 ) ;
goto V_141;
}
V_4 -> V_11 = F_83 ( V_13 , sizeof( * V_4 -> V_11 ) + V_145 ,
V_143 ) ;
if ( ! V_4 -> V_11 ) {
V_8 = - V_144 ;
goto V_141;
}
V_4 -> V_11 = F_86 ( V_4 -> V_11 , V_145 ) ;
V_8 = F_87 ( V_4 -> V_16 ) ;
if ( V_8 )
goto V_141;
F_4 ( V_146 |
V_147 | 0xf ,
V_4 -> V_16 + V_148 ) ;
F_4 ( V_149 ,
V_4 -> V_16 + V_150 ) ;
F_4 ( 0xffff0000 , V_4 -> V_16 + V_151 ) ;
for ( V_70 = 0 ; V_70 < V_130 ; V_70 ++ )
F_4 ( 0xffffffff , V_4 -> V_16 + F_5 ( V_70 ) ) ;
F_4 ( 0xffffffff , V_4 -> V_16 + V_129 ) ;
V_5 = V_4 ;
F_88 ( V_133 , V_4 ) ;
for ( V_70 = 0 ; V_70 < V_130 ; V_70 ++ ) {
F_68 ( & V_4 -> V_80 [ V_70 ] ) ;
F_89 ( & V_4 -> V_15 [ V_70 ] ) ;
F_90 ( & V_4 -> V_81 [ V_70 ] , 50 ) ;
}
V_4 -> V_87 [ V_120 ] = F_91 ( F_66 ,
NULL , L_9 ) ;
if ( F_54 ( V_4 -> V_87 [ V_120 ] ) ) {
F_10 ( V_13 , L_10 ) ;
V_8 = F_55 ( V_4 -> V_87 [ V_120 ] ) ;
goto V_141;
}
V_4 -> V_87 [ V_77 ] = F_91 ( F_26 ,
NULL , L_11 ) ;
if ( F_54 ( V_4 -> V_87 [ V_77 ] ) ) {
F_10 ( V_13 , L_10 ) ;
V_8 = F_55 ( V_4 -> V_87 [ V_77 ] ) ;
goto V_152;
}
V_4 -> V_153 = F_11 ( V_4 -> V_16 + V_154 ) ;
if ( V_4 -> V_153 & V_155 ) {
V_8 = F_92 ( V_156 ,
F_93 ( V_156 ) ) ;
if ( V_8 ) {
F_10 ( V_13 , L_12 ) ;
goto V_157;
}
}
if ( V_4 -> V_153 & V_158 ) {
V_8 = F_94 ( & V_159 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_13 ,
V_159 . V_108 . V_16 . V_97 ) ;
goto V_160;
}
}
if ( V_4 -> V_153 & V_161 ) {
V_8 = F_94 ( & V_162 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_13 ,
V_162 . V_108 . V_16 . V_97 ) ;
goto V_163;
}
}
return 0 ;
V_163:
if ( V_4 -> V_153 & V_158 )
F_95 ( & V_159 ) ;
V_160:
if ( V_4 -> V_153 & V_155 )
F_96 ( V_156 , F_93 ( V_156 ) ) ;
V_157:
F_97 ( V_4 -> V_87 [ V_77 ] ) ;
V_152:
F_97 ( V_4 -> V_87 [ V_120 ] ) ;
V_141:
F_31 ( & V_139 ) ;
return V_8 ;
}
static int F_98 ( struct V_132 * V_133 )
{
struct V_3 * V_4 = F_99 ( V_133 ) ;
if ( V_4 -> V_153 & V_161 )
F_95 ( & V_162 ) ;
if ( V_4 -> V_153 & V_158 )
F_95 ( & V_159 ) ;
if ( V_4 -> V_153 & V_155 )
F_96 ( V_156 , F_93 ( V_156 ) ) ;
F_97 ( V_4 -> V_87 [ V_120 ] ) ;
F_97 ( V_4 -> V_87 [ V_77 ] ) ;
F_88 ( V_133 , NULL ) ;
F_28 ( & V_139 ) ;
V_5 = NULL ;
F_31 ( & V_139 ) ;
return 0 ;
}
