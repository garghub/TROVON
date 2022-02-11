static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static struct V_5 * F_3 ( struct V_2 * V_3 )
{
return F_4 ( V_3 -> V_4 ) -> V_6 [ 0 ] ;
}
static int F_5 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
memset ( V_7 , 0 , V_3 -> V_10 ) ;
* ( V_11 * ) V_7 = F_6 ( V_9 -> V_12 & 0xffffffff ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
memset ( V_7 , 0 , V_3 -> V_10 ) ;
* ( V_13 * ) V_7 = F_8 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = & V_3 -> V_16 . V_15 ;
struct V_17 V_18 ;
struct V_19 V_20 ;
struct V_21 * V_22 ;
int V_23 , V_4 ;
F_10 ( & V_20 , V_3 -> V_24 , V_3 -> V_25 ) ;
V_18 . V_26 = V_15 -> V_27 ;
V_18 . V_28 = V_29 ;
V_23 = F_11 ( & V_18 , & V_20 , V_3 -> V_25 , V_15 -> V_30 ) ;
if ( V_23 )
return V_23 ;
F_12 (cpu) {
V_22 = F_13 ( V_3 -> V_4 , V_4 ) -> V_31 ,
V_23 = F_14 ( V_22 , V_15 -> V_30 ,
F_15 ( V_15 -> V_27 ) ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = & V_3 -> V_16 . V_15 ;
unsigned V_32 = F_15 ( V_15 -> V_27 ) ;
struct V_21 * V_22 ;
int V_4 , V_33 , V_23 = 0 ;
memset ( V_15 -> V_30 , 0 , V_32 ) ;
F_12 (cpu) {
V_22 = F_13 ( V_3 -> V_4 , V_4 ) -> V_31 ;
V_33 = F_14 ( V_22 , V_15 -> V_30 , V_32 ) ;
if ( V_33 )
V_23 = V_33 ;
}
return V_23 ;
}
static struct V_21 * F_17 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
T_1 * V_30 , unsigned V_36 )
{
struct V_21 * V_22 ;
int V_23 ;
V_22 = F_18 ( V_3 -> V_37 , 0 , V_38 ) ;
if ( F_19 ( V_22 ) ) {
V_35 -> error = L_1 ;
return V_22 ;
}
if ( F_20 ( V_22 ) !=
F_21 ( F_3 ( V_3 ) ) ) {
V_35 -> error = L_2
L_3 ;
F_22 ( V_22 ) ;
return F_23 ( - V_39 ) ;
}
V_23 = F_14 ( V_22 , V_30 , V_36 ) ;
if ( V_23 ) {
V_35 -> error = L_4 ;
F_22 ( V_22 ) ;
return F_23 ( V_23 ) ;
}
return V_22 ;
}
static void F_24 ( struct V_2 * V_3 )
{
int V_4 ;
struct V_1 * V_40 ;
struct V_21 * V_22 ;
struct V_14 * V_15 = & V_3 -> V_16 . V_15 ;
F_25 ( V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
F_26 ( V_15 -> V_30 ) ;
V_15 -> V_30 = NULL ;
F_12 (cpu) {
V_40 = F_13 ( V_3 -> V_4 , V_4 ) ;
V_22 = V_40 -> V_31 ;
if ( V_22 )
F_22 ( V_22 ) ;
V_40 -> V_31 = NULL ;
}
}
static int F_27 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_41 )
{
struct V_21 * V_22 = NULL ;
struct V_42 * V_27 = NULL ;
T_1 * V_30 = NULL ;
int V_23 , V_4 ;
if ( ! V_41 ) {
V_35 -> error = L_5 ;
return - V_39 ;
}
V_27 = F_28 ( V_41 , 0 , V_38 ) ;
if ( F_19 ( V_27 ) ) {
V_35 -> error = L_6 ;
V_23 = F_29 ( V_27 ) ;
goto V_43;
}
V_30 = F_30 ( F_15 ( V_27 ) , V_44 ) ;
if ( ! V_30 ) {
V_35 -> error = L_7 ;
V_23 = - V_45 ;
goto V_43;
}
V_3 -> V_16 . V_15 . V_30 = V_30 ;
V_3 -> V_16 . V_15 . V_27 = V_27 ;
F_12 (cpu) {
V_22 = F_17 ( V_3 , V_35 , V_30 ,
F_15 ( V_27 ) ) ;
if ( F_19 ( V_22 ) ) {
F_24 ( V_3 ) ;
return F_29 ( V_22 ) ;
}
F_13 ( V_3 -> V_4 , V_4 ) -> V_31 = V_22 ;
}
return 0 ;
V_43:
if ( V_27 && ! F_19 ( V_27 ) )
F_25 ( V_27 ) ;
F_31 ( V_30 ) ;
return V_23 ;
}
static int F_32 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
struct V_21 * V_22 = F_1 ( V_3 ) -> V_31 ;
memset ( V_7 , 0 , V_3 -> V_10 ) ;
* ( V_13 * ) V_7 = F_8 ( V_9 -> V_12 ) ;
F_33 ( V_22 , V_7 , V_7 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_41 )
{
unsigned V_46 = F_35 ( F_3 ( V_3 ) ) ;
int log = F_36 ( V_46 ) ;
if ( 1 << log != V_46 ) {
V_35 -> error = L_8 ;
return - V_39 ;
}
if ( log > 9 ) {
V_35 -> error = L_9 ;
return - V_39 ;
}
V_3 -> V_16 . V_47 . V_48 = 9 - log ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 )
{
}
static int F_38 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_2 V_49 ;
memset ( V_7 , 0 , V_3 -> V_10 - sizeof( V_50 ) ) ;
V_49 = F_39 ( ( ( V_50 ) V_9 -> V_12 << V_3 -> V_16 . V_47 . V_48 ) + 1 ) ;
F_40 ( V_49 , ( T_2 * ) ( V_7 + V_3 -> V_10 - sizeof( V_50 ) ) ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
memset ( V_7 , 0 , V_3 -> V_10 ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_51 * V_52 = & V_3 -> V_16 . V_52 ;
if ( V_52 -> V_27 && ! F_19 ( V_52 -> V_27 ) )
F_43 ( V_52 -> V_27 ) ;
V_52 -> V_27 = NULL ;
F_26 ( V_52 -> V_53 ) ;
V_52 -> V_53 = NULL ;
}
static int F_44 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_41 )
{
struct V_51 * V_52 = & V_3 -> V_16 . V_52 ;
V_52 -> V_27 = F_45 ( L_10 , 0 , 0 ) ;
if ( F_19 ( V_52 -> V_27 ) ) {
V_35 -> error = L_11 ;
return F_29 ( V_52 -> V_27 ) ;
}
if ( V_3 -> V_54 == V_3 -> V_55 ) {
V_52 -> V_53 = NULL ;
return 0 ;
}
V_52 -> V_53 = F_30 ( V_56 , V_44 ) ;
if ( ! V_52 -> V_53 ) {
F_42 ( V_3 ) ;
V_35 -> error = L_12 ;
return - V_45 ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_51 * V_52 = & V_3 -> V_16 . V_52 ;
int V_57 = V_3 -> V_25 / V_3 -> V_54 ;
if ( V_52 -> V_53 )
memcpy ( V_52 -> V_53 , V_3 -> V_24 + ( V_3 -> V_55 * V_57 ) ,
F_47 ( V_52 -> V_27 ) ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_51 * V_52 = & V_3 -> V_16 . V_52 ;
if ( V_52 -> V_53 )
memset ( V_52 -> V_53 , 0 , V_56 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_58 )
{
struct V_51 * V_52 = & V_3 -> V_16 . V_52 ;
struct {
struct V_59 V_18 ;
char V_60 [ F_50 ( V_52 -> V_27 ) ] ;
} V_61 ;
struct V_62 V_63 ;
T_3 V_64 [ 4 ] ;
int V_65 , V_33 ;
V_61 . V_18 . V_26 = V_52 -> V_27 ;
V_61 . V_18 . V_28 = V_29 ;
V_33 = F_51 ( & V_61 . V_18 ) ;
if ( V_33 )
return V_33 ;
if ( V_52 -> V_53 ) {
V_33 = F_52 ( & V_61 . V_18 , V_52 -> V_53 , V_56 ) ;
if ( V_33 )
return V_33 ;
}
V_33 = F_52 ( & V_61 . V_18 , V_58 + 16 , 16 * 31 ) ;
if ( V_33 )
return V_33 ;
V_64 [ 0 ] = F_6 ( V_9 -> V_12 & 0xFFFFFFFF ) ;
V_64 [ 1 ] = F_6 ( ( ( ( V_50 ) V_9 -> V_12 >> 32 ) & 0x00FFFFFF ) | 0x80000000 ) ;
V_64 [ 2 ] = F_6 ( 4024 ) ;
V_64 [ 3 ] = 0 ;
V_33 = F_52 ( & V_61 . V_18 , ( T_1 * ) V_64 , sizeof( V_64 ) ) ;
if ( V_33 )
return V_33 ;
V_33 = F_53 ( & V_61 . V_18 , & V_63 ) ;
if ( V_33 )
return V_33 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ )
F_54 ( & V_63 . V_67 [ V_65 ] ) ;
memcpy ( V_7 , & V_63 . V_67 , V_3 -> V_10 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_68 ;
int V_33 = 0 ;
if ( F_56 ( V_9 -> V_60 -> V_69 ) == V_70 ) {
V_68 = F_57 ( F_58 ( & V_9 -> V_71 ) ) ;
V_33 = F_49 ( V_3 , V_7 , V_9 , V_68 + V_9 -> V_71 . V_72 ) ;
F_59 ( V_68 ) ;
} else
memset ( V_7 , 0 , V_3 -> V_10 ) ;
return V_33 ;
}
static int F_60 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_73 ;
int V_33 ;
if ( F_56 ( V_9 -> V_60 -> V_69 ) == V_70 )
return 0 ;
V_73 = F_57 ( F_58 ( & V_9 -> V_74 ) ) ;
V_33 = F_49 ( V_3 , V_7 , V_9 , V_73 + V_9 -> V_74 . V_72 ) ;
if ( ! V_33 )
F_61 ( V_73 + V_9 -> V_74 . V_72 , V_7 , V_3 -> V_10 ) ;
F_59 ( V_73 ) ;
return V_33 ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_75 * V_60 ,
struct V_76 * V_77 , struct V_76 * V_69 ,
T_4 V_78 )
{
V_60 -> V_69 = V_69 ;
V_60 -> V_77 = V_77 ;
V_60 -> V_79 = 0 ;
V_60 -> V_80 = 0 ;
V_60 -> V_81 = V_69 ? V_69 -> V_82 : 0 ;
V_60 -> V_83 = V_77 ? V_77 -> V_82 : 0 ;
V_60 -> V_78 = V_78 + V_3 -> V_84 ;
F_63 ( & V_60 -> V_85 ) ;
}
static struct V_8 * F_64 ( struct V_2 * V_3 ,
struct V_86 * V_87 )
{
return (struct V_8 * ) ( ( char * ) V_87 + V_3 -> V_88 ) ;
}
static struct V_86 * F_65 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return (struct V_86 * ) ( ( char * ) V_9 - V_3 -> V_88 ) ;
}
static T_1 * F_66 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return ( T_1 * ) F_67 ( ( unsigned long ) ( V_9 + 1 ) ,
F_68 ( F_3 ( V_3 ) ) + 1 ) ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_75 * V_60 ,
struct V_86 * V_87 )
{
struct V_89 * V_90 = F_70 ( V_60 -> V_69 , V_60 -> V_81 ) ;
struct V_89 * V_91 = F_70 ( V_60 -> V_77 , V_60 -> V_83 ) ;
struct V_8 * V_9 ;
T_1 * V_7 ;
int V_33 = 0 ;
V_9 = F_64 ( V_3 , V_87 ) ;
V_7 = F_66 ( V_3 , V_9 ) ;
V_9 -> V_12 = V_60 -> V_78 ;
V_9 -> V_60 = V_60 ;
F_71 ( & V_9 -> V_71 , 1 ) ;
F_72 ( & V_9 -> V_71 , V_90 -> V_92 , 1 << V_93 ,
V_90 -> V_94 + V_60 -> V_79 ) ;
F_71 ( & V_9 -> V_74 , 1 ) ;
F_72 ( & V_9 -> V_74 , V_91 -> V_92 , 1 << V_93 ,
V_91 -> V_94 + V_60 -> V_80 ) ;
V_60 -> V_79 += 1 << V_93 ;
if ( V_60 -> V_79 >= V_90 -> V_95 ) {
V_60 -> V_79 = 0 ;
V_60 -> V_81 ++ ;
}
V_60 -> V_80 += 1 << V_93 ;
if ( V_60 -> V_80 >= V_91 -> V_95 ) {
V_60 -> V_80 = 0 ;
V_60 -> V_83 ++ ;
}
if ( V_3 -> V_96 ) {
V_33 = V_3 -> V_96 -> V_97 ( V_3 , V_7 , V_9 ) ;
if ( V_33 < 0 )
return V_33 ;
}
F_73 ( V_87 , & V_9 -> V_71 , & V_9 -> V_74 ,
1 << V_93 , V_7 ) ;
if ( F_56 ( V_60 -> V_69 ) == V_70 )
V_33 = F_74 ( V_87 ) ;
else
V_33 = F_75 ( V_87 ) ;
if ( ! V_33 && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
V_33 = V_3 -> V_96 -> V_98 ( V_3 , V_7 , V_9 ) ;
return V_33 ;
}
static void F_76 ( struct V_2 * V_3 ,
struct V_75 * V_60 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
unsigned V_100 = V_60 -> V_78 & ( V_3 -> V_55 - 1 ) ;
if ( ! V_99 -> V_87 )
V_99 -> V_87 = F_77 ( V_3 -> V_101 , V_102 ) ;
F_78 ( V_99 -> V_87 , V_99 -> V_6 [ V_100 ] ) ;
F_79 ( V_99 -> V_87 ,
V_103 | V_29 ,
V_104 , F_64 ( V_3 , V_99 -> V_87 ) ) ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_75 * V_60 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
int V_33 ;
F_81 ( & V_60 -> V_105 , 1 ) ;
while( V_60 -> V_81 < V_60 -> V_69 -> V_106 &&
V_60 -> V_83 < V_60 -> V_77 -> V_106 ) {
F_76 ( V_3 , V_60 ) ;
F_82 ( & V_60 -> V_105 ) ;
V_33 = F_69 ( V_3 , V_60 , V_99 -> V_87 ) ;
switch ( V_33 ) {
case - V_107 :
F_83 ( & V_60 -> V_85 ) ;
F_84 ( V_60 -> V_85 ) ;
case - V_108 :
V_99 -> V_87 = NULL ;
V_60 -> V_78 ++ ;
continue;
case 0 :
F_85 ( & V_60 -> V_105 ) ;
V_60 -> V_78 ++ ;
F_86 () ;
continue;
default:
F_85 ( & V_60 -> V_105 ) ;
return V_33 ;
}
}
return 0 ;
}
static void F_87 ( struct V_76 * V_76 )
{
struct V_109 * V_110 = V_76 -> V_111 ;
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
F_88 ( V_76 , V_3 -> V_46 ) ;
}
static struct V_76 * F_89 ( struct V_109 * V_110 , unsigned V_114 ,
unsigned * V_115 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
struct V_76 * V_116 ;
unsigned int V_117 = ( V_114 + V_118 - 1 ) >> V_119 ;
T_5 V_120 = V_102 | V_121 ;
unsigned V_65 , V_122 ;
struct V_123 * V_123 ;
V_116 = F_90 ( V_102 , V_117 , V_3 -> V_46 ) ;
if ( ! V_116 )
return NULL ;
F_91 ( V_110 , V_116 ) ;
* V_115 = 0 ;
for ( V_65 = 0 ; V_65 < V_117 ; V_65 ++ ) {
V_123 = F_77 ( V_3 -> V_124 , V_120 ) ;
if ( ! V_123 ) {
* V_115 = 1 ;
break;
}
V_120 = ( V_120 | V_125 ) & ~ V_126 ;
V_122 = ( V_114 > V_118 ) ? V_118 : V_114 ;
if ( ! F_92 ( V_116 , V_123 , V_122 , 0 ) ) {
F_93 ( V_123 , V_3 -> V_124 ) ;
break;
}
V_114 -= V_122 ;
}
if ( ! V_116 -> V_127 ) {
F_94 ( V_116 ) ;
return NULL ;
}
return V_116 ;
}
static void F_95 ( struct V_2 * V_3 , struct V_76 * V_116 )
{
unsigned int V_65 ;
struct V_89 * V_128 ;
for ( V_65 = 0 ; V_65 < V_116 -> V_106 ; V_65 ++ ) {
V_128 = F_70 ( V_116 , V_65 ) ;
F_96 ( ! V_128 -> V_92 ) ;
F_93 ( V_128 -> V_92 , V_3 -> V_124 ) ;
V_128 -> V_92 = NULL ;
}
}
static struct V_109 * F_97 ( struct V_34 * V_35 ,
struct V_76 * V_76 , T_4 V_78 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
struct V_109 * V_110 ;
V_110 = F_77 ( V_3 -> V_129 , V_102 ) ;
V_110 -> V_112 = V_35 ;
V_110 -> V_130 = V_76 ;
V_110 -> V_78 = V_78 ;
V_110 -> error = 0 ;
V_110 -> V_131 = NULL ;
F_81 ( & V_110 -> V_105 , 0 ) ;
return V_110 ;
}
static void F_98 ( struct V_109 * V_110 )
{
F_82 ( & V_110 -> V_105 ) ;
}
static void F_99 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
struct V_76 * V_130 = V_110 -> V_130 ;
struct V_109 * V_131 = V_110 -> V_131 ;
int error = V_110 -> error ;
if ( ! F_100 ( & V_110 -> V_105 ) )
return;
F_93 ( V_110 , V_3 -> V_129 ) ;
if ( F_101 ( ! V_131 ) )
F_102 ( V_130 , error ) ;
else {
if ( error && ! V_131 -> error )
V_131 -> error = error ;
F_99 ( V_131 ) ;
}
}
static void F_103 ( struct V_76 * V_116 , int error )
{
struct V_109 * V_110 = V_116 -> V_111 ;
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
unsigned V_132 = F_56 ( V_116 ) ;
if ( F_104 ( ! F_105 ( V_116 , V_133 ) && ! error ) )
error = - V_134 ;
if ( V_132 == V_70 )
F_95 ( V_3 , V_116 ) ;
F_94 ( V_116 ) ;
if ( V_132 == V_135 && ! error ) {
F_106 ( V_110 ) ;
return;
}
if ( F_104 ( error ) )
V_110 -> error = error ;
F_99 ( V_110 ) ;
}
static void F_91 ( struct V_109 * V_110 , struct V_76 * V_116 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
V_116 -> V_111 = V_110 ;
V_116 -> V_136 = F_103 ;
V_116 -> V_137 = V_3 -> V_138 -> V_139 ;
V_116 -> V_140 = V_110 -> V_130 -> V_140 ;
V_116 -> V_141 = F_87 ;
}
static int F_107 ( struct V_109 * V_110 , T_5 V_142 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
struct V_76 * V_130 = V_110 -> V_130 ;
struct V_76 * V_116 ;
V_116 = F_90 ( V_142 , F_108 ( V_130 ) , V_3 -> V_46 ) ;
if ( ! V_116 )
return 1 ;
F_98 ( V_110 ) ;
F_91 ( V_110 , V_116 ) ;
V_116 -> V_82 = 0 ;
V_116 -> V_106 = F_108 ( V_130 ) ;
V_116 -> V_127 = V_130 -> V_127 ;
V_116 -> V_143 = V_3 -> V_144 + V_110 -> V_78 ;
memcpy ( V_116 -> V_145 , F_109 ( V_130 ) ,
sizeof( struct V_89 ) * V_116 -> V_106 ) ;
F_110 ( V_116 ) ;
return 0 ;
}
static void F_111 ( struct V_109 * V_110 )
{
struct V_76 * V_116 = V_110 -> V_60 . V_77 ;
F_110 ( V_116 ) ;
}
static void F_112 ( struct V_146 * V_147 )
{
struct V_109 * V_110 = F_113 ( V_147 , struct V_109 , V_147 ) ;
if ( F_56 ( V_110 -> V_130 ) == V_135 ) {
F_98 ( V_110 ) ;
if ( F_107 ( V_110 , V_102 ) )
V_110 -> error = - V_45 ;
F_99 ( V_110 ) ;
} else
F_111 ( V_110 ) ;
}
static void F_114 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
F_115 ( & V_110 -> V_147 , F_112 ) ;
F_116 ( V_3 -> V_148 , & V_110 -> V_147 ) ;
}
static void F_117 ( struct V_109 * V_110 , int V_149 )
{
struct V_76 * V_116 = V_110 -> V_60 . V_77 ;
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
if ( F_104 ( V_110 -> error < 0 ) ) {
F_95 ( V_3 , V_116 ) ;
F_94 ( V_116 ) ;
F_99 ( V_110 ) ;
return;
}
F_96 ( V_110 -> V_60 . V_83 < V_116 -> V_106 ) ;
V_116 -> V_143 = V_3 -> V_144 + V_110 -> V_78 ;
if ( V_149 )
F_114 ( V_110 ) ;
else
F_110 ( V_116 ) ;
}
static void F_118 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
struct V_76 * V_116 ;
struct V_109 * V_150 ;
int V_151 ;
unsigned V_115 = 0 ;
unsigned V_152 = V_110 -> V_130 -> V_127 ;
T_4 V_78 = V_110 -> V_78 ;
int V_33 ;
F_98 ( V_110 ) ;
F_62 ( V_3 , & V_110 -> V_60 , NULL , V_110 -> V_130 , V_78 ) ;
while ( V_152 ) {
V_116 = F_89 ( V_110 , V_152 , & V_115 ) ;
if ( F_104 ( ! V_116 ) ) {
V_110 -> error = - V_45 ;
break;
}
V_110 -> V_60 . V_77 = V_116 ;
V_110 -> V_60 . V_83 = 0 ;
V_152 -= V_116 -> V_127 ;
V_78 += F_119 ( V_116 ) ;
F_98 ( V_110 ) ;
V_33 = F_80 ( V_3 , & V_110 -> V_60 ) ;
if ( V_33 < 0 )
V_110 -> error = - V_134 ;
V_151 = F_100 ( & V_110 -> V_60 . V_105 ) ;
if ( V_151 ) {
F_117 ( V_110 , 0 ) ;
if ( F_104 ( V_33 < 0 ) )
break;
V_110 -> V_78 = V_78 ;
}
if ( F_104 ( V_115 ) )
F_120 ( V_153 , V_154 / 100 ) ;
if ( F_104 ( ! V_151 && V_152 ) ) {
V_150 = F_97 ( V_110 -> V_112 , V_110 -> V_130 ,
V_78 ) ;
F_98 ( V_150 ) ;
F_62 ( V_3 , & V_150 -> V_60 , NULL ,
V_110 -> V_130 , V_78 ) ;
V_150 -> V_60 . V_81 = V_110 -> V_60 . V_81 ;
V_150 -> V_60 . V_79 = V_110 -> V_60 . V_79 ;
if ( ! V_110 -> V_131 )
V_150 -> V_131 = V_110 ;
else {
V_150 -> V_131 = V_110 -> V_131 ;
F_98 ( V_110 -> V_131 ) ;
F_99 ( V_110 ) ;
}
V_110 = V_150 ;
}
}
F_99 ( V_110 ) ;
}
static void F_121 ( struct V_109 * V_110 )
{
F_99 ( V_110 ) ;
}
static void F_122 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
int V_33 = 0 ;
F_98 ( V_110 ) ;
F_62 ( V_3 , & V_110 -> V_60 , V_110 -> V_130 , V_110 -> V_130 ,
V_110 -> V_78 ) ;
V_33 = F_80 ( V_3 , & V_110 -> V_60 ) ;
if ( V_33 < 0 )
V_110 -> error = - V_134 ;
if ( F_100 ( & V_110 -> V_60 . V_105 ) )
F_121 ( V_110 ) ;
F_99 ( V_110 ) ;
}
static void V_104 ( struct V_155 * V_156 ,
int error )
{
struct V_8 * V_9 = V_156 -> V_58 ;
struct V_75 * V_60 = V_9 -> V_60 ;
struct V_109 * V_110 = F_113 ( V_60 , struct V_109 , V_60 ) ;
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
if ( error == - V_108 ) {
F_123 ( & V_60 -> V_85 ) ;
return;
}
if ( ! error && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
error = V_3 -> V_96 -> V_98 ( V_3 , F_66 ( V_3 , V_9 ) , V_9 ) ;
if ( error < 0 )
V_110 -> error = - V_134 ;
F_93 ( F_65 ( V_3 , V_9 ) , V_3 -> V_101 ) ;
if ( ! F_100 ( & V_60 -> V_105 ) )
return;
if ( F_56 ( V_110 -> V_130 ) == V_135 )
F_121 ( V_110 ) ;
else
F_117 ( V_110 , 1 ) ;
}
static void F_124 ( struct V_146 * V_147 )
{
struct V_109 * V_110 = F_113 ( V_147 , struct V_109 , V_147 ) ;
if ( F_56 ( V_110 -> V_130 ) == V_135 )
F_122 ( V_110 ) ;
else
F_118 ( V_110 ) ;
}
static void F_106 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
F_115 ( & V_110 -> V_147 , F_124 ) ;
F_116 ( V_3 -> V_157 , & V_110 -> V_147 ) ;
}
static int F_125 ( T_1 * V_24 , char * V_158 , unsigned int V_114 )
{
char V_159 [ 3 ] ;
char * V_160 ;
unsigned int V_65 ;
V_159 [ 2 ] = '\0' ;
for ( V_65 = 0 ; V_65 < V_114 ; V_65 ++ ) {
V_159 [ 0 ] = * V_158 ++ ;
V_159 [ 1 ] = * V_158 ++ ;
V_24 [ V_65 ] = ( T_1 ) F_126 ( V_159 , & V_160 , 16 ) ;
if ( V_160 != & V_159 [ 2 ] )
return - V_39 ;
}
if ( * V_158 != '\0' )
return - V_39 ;
return 0 ;
}
static void F_127 ( char * V_158 , T_1 * V_24 , unsigned int V_114 )
{
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_114 ; V_65 ++ ) {
sprintf ( V_158 , L_13 , * V_24 ) ;
V_158 += 2 ;
V_24 ++ ;
}
}
static void F_128 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_40 = F_13 ( V_3 -> V_4 , V_4 ) ;
unsigned V_65 ;
for ( V_65 = 0 ; V_65 < V_3 -> V_55 ; V_65 ++ )
if ( V_40 -> V_6 [ V_65 ] && ! F_19 ( V_40 -> V_6 [ V_65 ] ) ) {
F_129 ( V_40 -> V_6 [ V_65 ] ) ;
V_40 -> V_6 [ V_65 ] = NULL ;
}
}
static int F_130 ( struct V_2 * V_3 , int V_4 , char * V_161 )
{
struct V_1 * V_40 = F_13 ( V_3 -> V_4 , V_4 ) ;
unsigned V_65 ;
int V_23 ;
for ( V_65 = 0 ; V_65 < V_3 -> V_55 ; V_65 ++ ) {
V_40 -> V_6 [ V_65 ] = F_131 ( V_161 , 0 , 0 ) ;
if ( F_19 ( V_40 -> V_6 [ V_65 ] ) ) {
V_23 = F_29 ( V_40 -> V_6 [ V_65 ] ) ;
F_128 ( V_3 , V_4 ) ;
return V_23 ;
}
}
return 0 ;
}
static int F_132 ( struct V_2 * V_3 )
{
unsigned V_57 = V_3 -> V_25 >> F_36 ( V_3 -> V_55 ) ;
int V_4 , V_23 = 0 , V_65 , V_33 ;
F_12 (cpu) {
for ( V_65 = 0 ; V_65 < V_3 -> V_55 ; V_65 ++ ) {
V_33 = F_133 ( F_13 ( V_3 -> V_4 , V_4 ) -> V_6 [ V_65 ] ,
V_3 -> V_24 + ( V_65 * V_57 ) , V_57 ) ;
if ( V_33 )
V_23 = V_33 ;
}
}
return V_23 ;
}
static int F_134 ( struct V_2 * V_3 , char * V_24 )
{
int V_33 = - V_39 ;
int V_162 = strlen ( V_24 ) ;
if ( V_3 -> V_25 != ( V_162 >> 1 ) )
goto V_163;
if ( ! V_3 -> V_25 && strcmp ( V_24 , L_14 ) )
goto V_163;
if ( V_3 -> V_25 && F_125 ( V_3 -> V_24 , V_24 , V_3 -> V_25 ) < 0 )
goto V_163;
F_135 ( V_164 , & V_3 -> V_28 ) ;
V_33 = F_132 ( V_3 ) ;
V_163:
memset ( V_24 , '0' , V_162 ) ;
return V_33 ;
}
static int F_136 ( struct V_2 * V_3 )
{
F_137 ( V_164 , & V_3 -> V_28 ) ;
memset ( & V_3 -> V_24 , 0 , V_3 -> V_25 * sizeof( T_1 ) ) ;
return F_132 ( V_3 ) ;
}
static void F_138 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
struct V_1 * V_40 ;
int V_4 ;
V_35 -> V_113 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_148 )
F_139 ( V_3 -> V_148 ) ;
if ( V_3 -> V_157 )
F_139 ( V_3 -> V_157 ) ;
if ( V_3 -> V_4 )
F_12 (cpu) {
V_40 = F_13 ( V_3 -> V_4 , V_4 ) ;
if ( V_40 -> V_87 )
F_93 ( V_40 -> V_87 , V_3 -> V_101 ) ;
F_128 ( V_3 , V_4 ) ;
}
if ( V_3 -> V_46 )
F_140 ( V_3 -> V_46 ) ;
if ( V_3 -> V_124 )
F_141 ( V_3 -> V_124 ) ;
if ( V_3 -> V_101 )
F_141 ( V_3 -> V_101 ) ;
if ( V_3 -> V_129 )
F_141 ( V_3 -> V_129 ) ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_165 )
V_3 -> V_96 -> V_165 ( V_3 ) ;
if ( V_3 -> V_138 )
F_142 ( V_35 , V_3 -> V_138 ) ;
if ( V_3 -> V_4 )
F_143 ( V_3 -> V_4 ) ;
F_26 ( V_3 -> V_37 ) ;
F_26 ( V_3 -> V_166 ) ;
F_26 ( V_3 ) ;
}
static int F_144 ( struct V_34 * V_35 ,
char * V_167 , char * V_24 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
char * V_168 , * V_37 , * V_169 , * V_170 , * V_171 , * V_172 ;
char * V_173 = NULL ;
int V_4 , V_174 = - V_39 ;
char V_175 ;
if ( strchr ( V_167 , '(' ) ) {
V_35 -> error = L_15 ;
return - V_39 ;
}
V_3 -> V_166 = F_145 ( V_167 , V_44 ) ;
if ( ! V_3 -> V_166 )
goto V_176;
V_168 = V_167 ;
V_172 = F_146 ( & V_168 , L_14 ) ;
V_37 = F_146 ( & V_172 , L_16 ) ;
if ( ! V_172 )
V_3 -> V_55 = 1 ;
else if ( sscanf ( V_172 , L_17 , & V_3 -> V_55 , & V_175 ) != 1 ||
! F_147 ( V_3 -> V_55 ) ) {
V_35 -> error = L_18 ;
return - V_39 ;
}
V_3 -> V_54 = V_3 -> V_55 ;
V_3 -> V_37 = F_145 ( V_37 , V_44 ) ;
if ( ! V_3 -> V_37 )
goto V_176;
V_169 = F_146 ( & V_168 , L_14 ) ;
V_171 = F_146 ( & V_168 , L_14 ) ;
V_170 = F_146 ( & V_171 , L_16 ) ;
if ( V_168 )
F_148 ( L_19 ) ;
V_3 -> V_4 = F_149 ( sizeof( * ( V_3 -> V_4 ) ) +
V_3 -> V_55 * sizeof( * ( V_3 -> V_4 -> V_6 ) ) ,
F_150 ( struct V_1 ) ) ;
if ( ! V_3 -> V_4 ) {
V_35 -> error = L_20 ;
goto V_176;
}
if ( ! V_169 || ( ! strcmp ( V_169 , L_21 ) && ! V_170 ) ) {
V_169 = L_22 ;
V_170 = L_21 ;
}
if ( strcmp ( V_169 , L_23 ) && ! V_170 ) {
V_35 -> error = L_24 ;
return - V_39 ;
}
V_173 = F_151 ( V_177 , V_44 ) ;
if ( ! V_173 )
goto V_176;
V_174 = snprintf ( V_173 , V_177 ,
L_25 , V_169 , V_37 ) ;
if ( V_174 < 0 ) {
F_31 ( V_173 ) ;
goto V_176;
}
F_12 (cpu) {
V_174 = F_130 ( V_3 , V_4 , V_173 ) ;
if ( V_174 < 0 ) {
V_35 -> error = L_26 ;
goto V_43;
}
}
V_174 = F_134 ( V_3 , V_24 ) ;
if ( V_174 < 0 ) {
V_35 -> error = L_27 ;
goto V_43;
}
V_3 -> V_10 = F_21 ( F_3 ( V_3 ) ) ;
if ( V_3 -> V_10 )
V_3 -> V_10 = F_152 ( V_3 -> V_10 ,
( unsigned int ) ( sizeof( V_50 ) / sizeof( T_1 ) ) ) ;
else if ( V_170 ) {
F_148 ( L_28 ) ;
V_170 = NULL ;
}
if ( V_170 == NULL )
V_3 -> V_96 = NULL ;
else if ( strcmp ( V_170 , L_21 ) == 0 )
V_3 -> V_96 = & V_178 ;
else if ( strcmp ( V_170 , L_29 ) == 0 )
V_3 -> V_96 = & V_179 ;
else if ( strcmp ( V_170 , L_30 ) == 0 )
V_3 -> V_96 = & V_180 ;
else if ( strcmp ( V_170 , L_31 ) == 0 )
V_3 -> V_96 = & V_181 ;
else if ( strcmp ( V_170 , L_32 ) == 0 )
V_3 -> V_96 = & V_182 ;
else if ( strcmp ( V_170 , L_33 ) == 0 ) {
V_3 -> V_96 = & V_183 ;
if ( V_3 -> V_25 % V_3 -> V_54 )
V_3 -> V_54 ++ ;
} else {
V_174 = - V_39 ;
V_35 -> error = L_34 ;
goto V_43;
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_184 ) {
V_174 = V_3 -> V_96 -> V_184 ( V_3 , V_35 , V_171 ) ;
if ( V_174 < 0 ) {
V_35 -> error = L_35 ;
goto V_43;
}
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_185 ) {
V_174 = V_3 -> V_96 -> V_185 ( V_3 ) ;
if ( V_174 < 0 ) {
V_35 -> error = L_36 ;
goto V_43;
}
}
V_174 = 0 ;
V_43:
F_31 ( V_173 ) ;
return V_174 ;
V_176:
V_35 -> error = L_37 ;
return - V_45 ;
}
static int F_153 ( struct V_34 * V_35 , unsigned int V_186 , char * * V_187 )
{
struct V_2 * V_3 ;
unsigned int V_25 , V_188 ;
unsigned long long V_189 ;
int V_174 ;
struct V_190 V_191 ;
const char * V_192 ;
char V_175 ;
static struct V_193 V_194 [] = {
{ 0 , 1 , L_38 } ,
} ;
if ( V_186 < 5 ) {
V_35 -> error = L_39 ;
return - V_39 ;
}
V_25 = strlen ( V_187 [ 1 ] ) >> 1 ;
V_3 = F_30 ( sizeof( * V_3 ) + V_25 * sizeof( T_1 ) , V_44 ) ;
if ( ! V_3 ) {
V_35 -> error = L_40 ;
return - V_45 ;
}
V_3 -> V_25 = V_25 ;
V_35 -> V_113 = V_3 ;
V_174 = F_144 ( V_35 , V_187 [ 0 ] , V_187 [ 1 ] ) ;
if ( V_174 < 0 )
goto V_43;
V_174 = - V_45 ;
V_3 -> V_129 = F_154 ( V_195 , V_196 ) ;
if ( ! V_3 -> V_129 ) {
V_35 -> error = L_41 ;
goto V_43;
}
V_3 -> V_88 = sizeof( struct V_86 ) ;
V_3 -> V_88 += F_155 ( F_3 ( V_3 ) ) ;
V_3 -> V_88 = F_67 ( V_3 -> V_88 , F_156 () ) ;
V_3 -> V_88 += F_68 ( F_3 ( V_3 ) ) &
~ ( F_156 () - 1 ) ;
V_3 -> V_101 = F_157 ( V_195 , V_3 -> V_88 +
sizeof( struct V_8 ) + V_3 -> V_10 ) ;
if ( ! V_3 -> V_101 ) {
V_35 -> error = L_42 ;
goto V_43;
}
V_3 -> V_124 = F_158 ( V_197 , 0 ) ;
if ( ! V_3 -> V_124 ) {
V_35 -> error = L_43 ;
goto V_43;
}
V_3 -> V_46 = F_159 ( V_195 , 0 ) ;
if ( ! V_3 -> V_46 ) {
V_35 -> error = L_44 ;
goto V_43;
}
V_174 = - V_39 ;
if ( sscanf ( V_187 [ 2 ] , L_45 , & V_189 , & V_175 ) != 1 ) {
V_35 -> error = L_46 ;
goto V_43;
}
V_3 -> V_84 = V_189 ;
if ( F_160 ( V_35 , V_187 [ 3 ] , F_161 ( V_35 -> V_198 ) , & V_3 -> V_138 ) ) {
V_35 -> error = L_47 ;
goto V_43;
}
if ( sscanf ( V_187 [ 4 ] , L_45 , & V_189 , & V_175 ) != 1 ) {
V_35 -> error = L_48 ;
goto V_43;
}
V_3 -> V_144 = V_189 ;
V_187 += 5 ;
V_186 -= 5 ;
if ( V_186 ) {
V_191 . V_186 = V_186 ;
V_191 . V_187 = V_187 ;
V_174 = F_162 ( V_194 , & V_191 , & V_188 , & V_35 -> error ) ;
if ( V_174 )
goto V_43;
V_192 = F_163 ( & V_191 ) ;
if ( V_188 == 1 && V_192 &&
! strcasecmp ( V_192 , L_49 ) )
V_35 -> V_199 = 1 ;
else if ( V_188 ) {
V_174 = - V_39 ;
V_35 -> error = L_50 ;
goto V_43;
}
}
V_174 = - V_45 ;
V_3 -> V_148 = F_164 ( L_51 ,
V_200 |
V_201 ,
1 ) ;
if ( ! V_3 -> V_148 ) {
V_35 -> error = L_52 ;
goto V_43;
}
V_3 -> V_157 = F_164 ( L_53 ,
V_200 |
V_202 |
V_201 ,
1 ) ;
if ( ! V_3 -> V_157 ) {
V_35 -> error = L_54 ;
goto V_43;
}
V_35 -> V_203 = 1 ;
V_35 -> V_204 = 1 ;
return 0 ;
V_43:
F_138 ( V_35 ) ;
return V_174 ;
}
static int F_165 ( struct V_34 * V_35 , struct V_76 * V_76 ,
union V_205 * V_206 )
{
struct V_109 * V_110 ;
struct V_2 * V_3 ;
if ( F_104 ( V_76 -> V_140 & ( V_207 | V_208 ) ) ) {
V_3 = V_35 -> V_113 ;
V_76 -> V_137 = V_3 -> V_138 -> V_139 ;
if ( F_119 ( V_76 ) )
V_76 -> V_143 = V_3 -> V_144 + F_166 ( V_35 , V_76 -> V_143 ) ;
return V_209 ;
}
V_110 = F_97 ( V_35 , V_76 , F_166 ( V_35 , V_76 -> V_143 ) ) ;
if ( F_56 ( V_110 -> V_130 ) == V_135 ) {
if ( F_107 ( V_110 , V_210 ) )
F_114 ( V_110 ) ;
} else
F_106 ( V_110 ) ;
return V_211 ;
}
static int F_167 ( struct V_34 * V_35 , T_6 type ,
char * V_212 , unsigned int V_213 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
unsigned int V_214 = 0 ;
switch ( type ) {
case V_215 :
V_212 [ 0 ] = '\0' ;
break;
case V_216 :
F_168 ( L_55 , V_3 -> V_166 ) ;
if ( V_3 -> V_25 > 0 ) {
if ( ( V_213 - V_214 ) < ( ( V_3 -> V_25 << 1 ) + 1 ) )
return - V_45 ;
F_127 ( V_212 + V_214 , V_3 -> V_24 , V_3 -> V_25 ) ;
V_214 += V_3 -> V_25 << 1 ;
} else {
if ( V_214 >= V_213 )
return - V_45 ;
V_212 [ V_214 ++ ] = '-' ;
}
F_168 ( L_56 , ( unsigned long long ) V_3 -> V_84 ,
V_3 -> V_138 -> V_217 , ( unsigned long long ) V_3 -> V_144 ) ;
if ( V_35 -> V_199 )
F_168 ( L_57 ) ;
break;
}
return 0 ;
}
static void F_169 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
F_135 ( V_218 , & V_3 -> V_28 ) ;
}
static int F_170 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
if ( ! F_171 ( V_164 , & V_3 -> V_28 ) ) {
F_172 ( L_58 ) ;
return - V_219 ;
}
return 0 ;
}
static void F_173 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
F_137 ( V_218 , & V_3 -> V_28 ) ;
}
static int F_174 ( struct V_34 * V_35 , unsigned V_186 , char * * V_187 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
int V_174 = - V_39 ;
if ( V_186 < 2 )
goto error;
if ( ! strcasecmp ( V_187 [ 0 ] , L_59 ) ) {
if ( ! F_171 ( V_218 , & V_3 -> V_28 ) ) {
F_148 ( L_60 ) ;
return - V_39 ;
}
if ( V_186 == 3 && ! strcasecmp ( V_187 [ 1 ] , L_61 ) ) {
V_174 = F_134 ( V_3 , V_187 [ 2 ] ) ;
if ( V_174 )
return V_174 ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_185 )
V_174 = V_3 -> V_96 -> V_185 ( V_3 ) ;
return V_174 ;
}
if ( V_186 == 2 && ! strcasecmp ( V_187 [ 1 ] , L_62 ) ) {
if ( V_3 -> V_96 && V_3 -> V_96 -> V_220 ) {
V_174 = V_3 -> V_96 -> V_220 ( V_3 ) ;
if ( V_174 )
return V_174 ;
}
return F_136 ( V_3 ) ;
}
}
error:
F_148 ( L_63 ) ;
return - V_39 ;
}
static int F_175 ( struct V_34 * V_35 , struct V_221 * V_222 ,
struct V_89 * V_223 , int V_224 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
struct V_225 * V_226 = F_176 ( V_3 -> V_138 -> V_139 ) ;
if ( ! V_226 -> V_227 )
return V_224 ;
V_222 -> V_137 = V_3 -> V_138 -> V_139 ;
V_222 -> V_143 = V_3 -> V_144 + F_166 ( V_35 , V_222 -> V_143 ) ;
return F_177 ( V_224 , V_226 -> V_227 ( V_226 , V_222 , V_223 ) ) ;
}
static int F_178 ( struct V_34 * V_35 ,
T_7 V_228 , void * V_58 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
return V_228 ( V_35 , V_3 -> V_138 , V_3 -> V_144 , V_35 -> V_122 , V_58 ) ;
}
static int T_8 F_179 ( void )
{
int V_33 ;
V_196 = F_180 ( V_109 , 0 ) ;
if ( ! V_196 )
return - V_45 ;
V_33 = F_181 ( & V_229 ) ;
if ( V_33 < 0 ) {
F_172 ( L_64 , V_33 ) ;
F_182 ( V_196 ) ;
}
return V_33 ;
}
static void T_9 F_183 ( void )
{
F_184 ( & V_229 ) ;
F_182 ( V_196 ) ;
}
