static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
const int V_6 = V_2 -> V_6 ;
T_1 V_7 ;
unsigned long V_8 ;
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
struct V_84 * V_56 = F_35 ( V_21 ) ;
struct V_1 * V_85 = F_36 ( V_56 ) ;
F_37 ( V_86 , V_85 -> V_87 ) ;
int V_8 ;
F_38 ( V_86 , V_85 -> V_87 ) ;
F_39 ( V_86 , V_21 -> V_16 . V_88 , NULL , NULL ) ;
F_40 ( V_86 , V_21 -> V_59 , V_21 -> V_58 ,
V_21 -> V_89 , V_21 -> V_75 ) ;
if ( V_39 )
V_8 = F_41 ( V_86 ) ;
else
V_8 = F_42 ( V_86 ) ;
F_43 ( V_86 ) ;
return V_8 ;
}
static int F_44 ( struct V_20 * V_21 , int V_39 , int V_44 )
{
struct V_3 * V_4 = V_5 ;
struct V_54 * V_55 = & V_21 -> V_16 ;
struct V_1 * V_2 = F_18 ( V_55 -> V_56 ) ;
struct V_23 * V_24 = F_15 ( V_21 ) ;
int V_8 ;
if ( F_45 ( V_2 -> V_74 != V_27 ) )
return F_34 ( V_21 , V_39 ) ;
V_24 -> V_39 = V_39 ;
V_24 -> V_44 = V_44 ;
V_2 -> V_6 = V_77 ;
F_28 ( & V_4 -> V_80 [ V_2 -> V_6 ] ) ;
V_8 = F_46 ( & V_4 -> V_81 [ V_2 -> V_6 ] , & V_21 -> V_16 ) ;
F_31 ( & V_4 -> V_80 [ V_2 -> V_6 ] ) ;
F_47 ( V_4 -> V_90 [ V_2 -> V_6 ] ) ;
return - V_83 ;
}
static int F_48 ( struct V_20 * V_21 )
{
return F_44 ( V_21 , 0 , 1 ) ;
}
static int F_49 ( struct V_20 * V_21 )
{
return F_44 ( V_21 , 1 , 1 ) ;
}
static int F_50 ( struct V_20 * V_21 )
{
return F_44 ( V_21 , 0 , 0 ) ;
}
static int F_51 ( struct V_20 * V_21 )
{
return F_44 ( V_21 , 1 , 0 ) ;
}
static int F_52 ( struct V_84 * V_56 , const T_4 * V_68 ,
unsigned int V_71 )
{
struct V_1 * V_2 = F_36 ( V_56 ) ;
unsigned int V_8 ;
V_2 -> V_74 = V_71 ;
if ( V_71 == V_27 ) {
memcpy ( V_2 -> V_68 , V_68 , V_71 ) ;
return 0 ;
}
F_53 ( V_2 -> V_87 , V_91 ) ;
F_54 ( V_2 -> V_87 ,
V_56 -> V_16 . V_92 & V_91 ) ;
V_8 = F_55 ( V_2 -> V_87 , V_68 , V_71 ) ;
if ( ! V_8 )
return 0 ;
V_56 -> V_16 . V_92 &= ~ V_93 ;
V_56 -> V_16 . V_92 |= F_56 ( V_2 -> V_87 ) &
V_93 ;
return V_8 ;
}
static int F_57 ( struct V_94 * V_56 )
{
const char * V_95 = F_58 ( V_56 ) ;
const T_1 V_88 = V_96 | V_97 ;
struct V_1 * V_2 = F_18 ( V_56 ) ;
struct V_98 * V_99 ;
V_99 = F_59 ( V_95 , 0 , V_88 ) ;
if ( F_60 ( V_99 ) )
return F_61 ( V_99 ) ;
V_2 -> V_87 = V_99 ;
V_56 -> V_100 . V_101 = sizeof( struct V_23 ) ;
return 0 ;
}
static void F_62 ( struct V_94 * V_56 )
{
struct V_1 * V_2 = F_18 ( V_56 ) ;
F_63 ( V_2 -> V_87 ) ;
}
static int F_64 ( struct V_102 * V_21 )
{
struct V_3 * V_4 = V_5 ;
int V_8 ;
struct V_103 * V_56 = F_65 ( V_21 ) ;
struct V_1 * V_2 = F_66 ( V_56 ) ;
struct V_104 * V_24 = F_67 ( V_21 ) ;
struct V_105 * V_106 = F_68 ( V_56 ) ;
struct V_9 * V_10 = & V_4 -> V_11 -> V_10 [ V_2 -> V_6 ] ;
T_2 V_107 = 0 ;
T_2 V_108 = F_2 ( V_4 -> V_13 , V_4 -> V_11 -> V_109 ,
V_30 , V_14 ) ;
V_10 -> V_34 = V_35 |
V_36 |
V_110 ;
if ( V_24 -> V_22 )
V_10 -> V_34 |= V_111 ;
V_10 -> V_42 = V_2 -> V_112 ;
V_10 -> V_47 = 0 ;
V_10 -> V_48 = V_108 ;
V_10 -> V_49 = 0 ;
V_10 -> V_50 = V_2 -> V_51 ;
V_10 -> V_52 = 0 ;
V_10 -> V_53 = 0 ;
if ( V_24 -> V_113 ) {
V_107 = F_2 ( V_4 -> V_13 , V_21 -> V_114 ,
V_106 -> V_115 , V_33 ) ;
V_10 -> V_34 |= V_116 ;
V_10 -> V_52 = V_107 ;
}
V_8 = F_1 ( V_2 ) ;
if ( V_24 -> V_113 )
F_13 ( V_4 -> V_13 , V_107 , V_106 -> V_115 ,
V_33 ) ;
F_13 ( V_4 -> V_13 , V_108 , V_30 , V_14 ) ;
return V_8 ;
}
static int F_69 ( struct V_54 * V_55 )
{
struct V_3 * V_4 = V_5 ;
struct V_102 * V_21 = F_70 ( V_55 ) ;
struct V_103 * V_56 = F_65 ( V_21 ) ;
struct V_1 * V_2 = F_66 ( V_56 ) ;
struct V_104 * V_24 = F_67 ( V_21 ) ;
struct V_105 * V_106 = F_68 ( V_56 ) ;
const int V_60 = F_19 ( V_21 -> V_59 ) ;
T_3 * V_62 = V_4 -> V_11 -> V_109 ;
T_3 * V_65 ;
struct V_57 * V_59 ;
unsigned int V_70 , V_71 , V_72 ;
int V_8 ;
int V_117 = V_24 -> V_113 ;
if ( V_117 )
V_24 -> V_113 = 0 ;
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
V_8 = F_64 ( V_21 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_51 = 0 ;
V_24 -> V_22 = 0 ;
}
} while ( V_71 );
}
if ( V_117 ) {
V_24 -> V_113 = 1 ;
if ( ! V_21 -> V_114 )
return - V_19 ;
V_8 = F_64 ( V_21 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_51 = 0 ;
for ( V_70 = 0 ; V_70 < V_106 -> V_115 / 2 ; V_70 ++ ) {
F_71 ( V_21 -> V_114 [ V_70 ] ,
V_21 -> V_114 [ V_106 -> V_115 - V_70 - 1 ] ) ;
}
}
return 0 ;
}
static int F_72 ( void * V_76 )
{
struct V_3 * V_4 = V_5 ;
const int V_6 = V_118 ;
struct V_54 * V_78 ;
struct V_54 * V_55 ;
struct V_104 * V_24 ;
struct V_102 * V_21 ;
int V_8 , V_113 ;
do {
F_27 ( V_79 ) ;
F_28 ( & V_4 -> V_80 [ V_6 ] ) ;
V_78 = F_29 ( & V_4 -> V_81 [ V_6 ] ) ;
V_55 = F_30 ( & V_4 -> V_81 [ V_6 ] ) ;
F_31 ( & V_4 -> V_80 [ V_6 ] ) ;
if ( V_78 )
V_78 -> V_82 ( V_78 , - V_83 ) ;
if ( V_55 ) {
V_21 = F_70 ( V_55 ) ;
V_24 = F_67 ( V_21 ) ;
V_8 = F_69 ( V_55 ) ;
V_113 = V_24 -> V_113 ;
V_55 -> V_82 ( V_55 , V_8 ) ;
if ( ! V_113 )
continue;
}
F_32 () ;
} while ( ! F_33 () );
return 0 ;
}
static int F_73 ( struct V_102 * V_21 )
{
struct V_103 * V_56 = F_65 ( V_21 ) ;
struct V_1 * V_2 = F_66 ( V_56 ) ;
struct V_105 * V_106 = F_68 ( V_56 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
if ( strcmp ( V_106 -> V_16 . V_119 , L_3 ) == 0 )
V_2 -> V_112 = V_120 ;
else
V_2 -> V_112 = V_121 ;
V_2 -> V_51 = 0 ;
V_2 -> V_122 = 0 ;
V_2 -> V_6 = V_118 ;
F_74 ( & V_2 -> V_80 ) ;
return 0 ;
}
static int F_75 ( struct V_102 * V_21 , int V_113 )
{
struct V_3 * V_4 = V_5 ;
struct V_104 * V_24 = F_67 ( V_21 ) ;
struct V_103 * V_56 = F_65 ( V_21 ) ;
struct V_1 * V_2 = F_66 ( V_56 ) ;
int V_8 ;
if ( ! V_21 -> V_89 && ! V_113 )
return 0 ;
F_28 ( & V_2 -> V_80 ) ;
V_24 -> V_113 = V_113 ;
if ( ! V_2 -> V_122 ) {
V_2 -> V_122 = 1 ;
V_24 -> V_22 = 1 ;
}
F_28 ( & V_4 -> V_80 [ V_2 -> V_6 ] ) ;
V_8 = F_46 ( & V_4 -> V_81 [ V_2 -> V_6 ] , & V_21 -> V_16 ) ;
F_31 ( & V_4 -> V_80 [ V_2 -> V_6 ] ) ;
F_47 ( V_4 -> V_90 [ V_2 -> V_6 ] ) ;
F_31 ( & V_2 -> V_80 ) ;
return - V_83 ;
}
static int F_76 ( struct V_102 * V_21 )
{
return F_75 ( V_21 , 0 ) ;
}
static int F_77 ( struct V_102 * V_21 )
{
F_78 ( V_21 , NULL , V_21 -> V_114 , 0 ) ;
V_21 -> V_89 = 0 ;
return F_75 ( V_21 , 1 ) ;
}
static int F_79 ( struct V_102 * V_21 )
{
return F_75 ( V_21 , 1 ) ;
}
static int F_80 ( struct V_102 * V_21 )
{
int V_8 ;
V_8 = F_73 ( V_21 ) ;
if ( V_8 )
return V_8 ;
return F_79 ( V_21 ) ;
}
static int F_81 ( struct V_94 * V_56 )
{
F_82 ( F_83 ( V_56 ) ,
sizeof( struct V_104 ) ) ;
return 0 ;
}
static void F_84 ( struct V_94 * V_56 )
{
}
static T_5 F_85 ( int V_123 , void * V_124 )
{
struct V_3 * V_4 = V_124 ;
T_1 V_7 ;
int V_70 ;
V_7 = F_11 ( V_4 -> V_16 + V_17 ) ;
V_7 &= V_125 ;
if ( ! V_7 )
return V_126 ;
F_4 ( V_7 , V_4 -> V_16 + V_127 ) ;
for ( V_70 = 0 ; V_70 < V_128 ; V_70 ++ )
if ( V_7 & ( 1 << V_70 ) )
V_82 ( & V_4 -> V_15 [ V_70 ] ) ;
return V_129 ;
}
static int F_86 ( struct V_130 * V_131 )
{
struct V_132 * V_13 = & V_131 -> V_13 ;
struct V_3 * V_4 = NULL ;
int V_70 , V_8 ;
struct V_133 * V_134 ;
int V_135 , V_136 ;
if ( V_5 ) {
F_10 ( V_13 , L_4 ) ;
return - V_137 ;
}
V_134 = F_87 ( V_131 , V_138 , 0 ) ;
V_135 = F_88 ( V_131 , 0 ) ;
if ( V_135 < 0 )
return V_135 ;
V_136 = F_88 ( V_131 , 1 ) ;
if ( V_136 < 0 )
return V_136 ;
V_4 = F_89 ( V_13 , sizeof( * V_4 ) , V_139 ) ;
if ( ! V_4 )
return - V_140 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_16 = F_90 ( V_13 , V_134 ) ;
if ( F_60 ( V_4 -> V_16 ) )
return F_61 ( V_4 -> V_16 ) ;
V_8 = F_91 ( V_13 , V_135 , F_85 , 0 ,
L_5 , V_4 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_6 ) ;
return V_8 ;
}
V_8 = F_91 ( V_13 , V_136 , F_85 , 0 ,
L_7 , V_4 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_8 ) ;
return V_8 ;
}
V_4 -> V_11 = F_89 ( V_13 , sizeof( * V_4 -> V_11 ) + V_141 ,
V_139 ) ;
if ( ! V_4 -> V_11 )
return - V_140 ;
V_4 -> V_11 = F_92 ( V_4 -> V_11 , V_141 ) ;
V_8 = F_93 ( V_4 -> V_16 ) ;
if ( V_8 )
return V_8 ;
F_4 ( V_142 |
V_143 | 0xf ,
V_4 -> V_16 + V_144 ) ;
F_4 ( V_145 ,
V_4 -> V_16 + V_146 ) ;
F_4 ( 0xffff0000 , V_4 -> V_16 + V_147 ) ;
for ( V_70 = 0 ; V_70 < V_128 ; V_70 ++ )
F_4 ( 0xffffffff , V_4 -> V_16 + F_5 ( V_70 ) ) ;
F_4 ( 0xffffffff , V_4 -> V_16 + V_127 ) ;
V_5 = V_4 ;
F_94 ( V_131 , V_4 ) ;
for ( V_70 = 0 ; V_70 < V_128 ; V_70 ++ ) {
F_74 ( & V_4 -> V_80 [ V_70 ] ) ;
F_95 ( & V_4 -> V_15 [ V_70 ] ) ;
F_96 ( & V_4 -> V_81 [ V_70 ] , 50 ) ;
}
V_4 -> V_90 [ V_118 ] = F_97 ( F_72 ,
NULL , L_9 ) ;
if ( F_60 ( V_4 -> V_90 [ V_118 ] ) ) {
F_10 ( V_13 , L_10 ) ;
return F_61 ( V_4 -> V_90 [ V_118 ] ) ;
}
V_4 -> V_90 [ V_77 ] = F_97 ( F_26 ,
NULL , L_11 ) ;
if ( F_60 ( V_4 -> V_90 [ V_77 ] ) ) {
F_10 ( V_13 , L_10 ) ;
V_8 = F_61 ( V_4 -> V_90 [ V_77 ] ) ;
goto V_148;
}
V_4 -> V_149 = F_11 ( V_4 -> V_16 + V_150 ) ;
if ( V_4 -> V_149 & V_151 ) {
V_8 = F_98 ( V_152 ,
F_99 ( V_152 ) ) ;
if ( V_8 ) {
F_10 ( V_13 , L_12 ) ;
goto V_153;
}
}
if ( V_4 -> V_149 & V_154 ) {
V_8 = F_100 ( & V_155 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_13 ,
V_155 . V_106 . V_16 . V_119 ) ;
goto V_156;
}
}
if ( V_4 -> V_149 & V_157 ) {
V_8 = F_100 ( & V_158 ) ;
if ( V_8 ) {
F_10 ( V_13 , L_13 ,
V_158 . V_106 . V_16 . V_119 ) ;
goto V_159;
}
}
return 0 ;
V_159:
if ( V_4 -> V_149 & V_154 )
F_101 ( & V_155 ) ;
V_156:
if ( V_4 -> V_149 & V_151 )
F_102 ( V_152 , F_99 ( V_152 ) ) ;
V_153:
F_103 ( V_4 -> V_90 [ V_77 ] ) ;
V_148:
F_103 ( V_4 -> V_90 [ V_118 ] ) ;
return V_8 ;
}
static int F_104 ( struct V_130 * V_131 )
{
struct V_3 * V_4 = F_105 ( V_131 ) ;
if ( V_4 -> V_149 & V_157 )
F_101 ( & V_158 ) ;
if ( V_4 -> V_149 & V_154 )
F_101 ( & V_155 ) ;
if ( V_4 -> V_149 & V_151 )
F_102 ( V_152 , F_99 ( V_152 ) ) ;
F_103 ( V_4 -> V_90 [ V_118 ] ) ;
F_103 ( V_4 -> V_90 [ V_77 ] ) ;
F_94 ( V_131 , NULL ) ;
V_5 = NULL ;
return 0 ;
}
