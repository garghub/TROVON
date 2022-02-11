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
V_68 = F_57 ( F_58 ( & V_9 -> V_71 ) , V_72 ) ;
V_33 = F_49 ( V_3 , V_7 , V_9 , V_68 + V_9 -> V_71 . V_73 ) ;
F_59 ( V_68 , V_72 ) ;
} else
memset ( V_7 , 0 , V_3 -> V_10 ) ;
return V_33 ;
}
static int F_60 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_74 ;
int V_33 ;
if ( F_56 ( V_9 -> V_60 -> V_69 ) == V_70 )
return 0 ;
V_74 = F_57 ( F_58 ( & V_9 -> V_75 ) , V_72 ) ;
V_33 = F_49 ( V_3 , V_7 , V_9 , V_74 + V_9 -> V_75 . V_73 ) ;
if ( ! V_33 )
F_61 ( V_74 + V_9 -> V_75 . V_73 , V_7 , V_3 -> V_10 ) ;
F_59 ( V_74 , V_72 ) ;
return V_33 ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_76 * V_60 ,
struct V_77 * V_78 , struct V_77 * V_69 ,
T_4 V_79 )
{
V_60 -> V_69 = V_69 ;
V_60 -> V_78 = V_78 ;
V_60 -> V_80 = 0 ;
V_60 -> V_81 = 0 ;
V_60 -> V_82 = V_69 ? V_69 -> V_83 : 0 ;
V_60 -> V_84 = V_78 ? V_78 -> V_83 : 0 ;
V_60 -> V_79 = V_79 + V_3 -> V_85 ;
F_63 ( & V_60 -> V_86 ) ;
}
static struct V_8 * F_64 ( struct V_2 * V_3 ,
struct V_87 * V_88 )
{
return (struct V_8 * ) ( ( char * ) V_88 + V_3 -> V_89 ) ;
}
static struct V_87 * F_65 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return (struct V_87 * ) ( ( char * ) V_9 - V_3 -> V_89 ) ;
}
static T_1 * F_66 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return ( T_1 * ) F_67 ( ( unsigned long ) ( V_9 + 1 ) ,
F_68 ( F_3 ( V_3 ) ) + 1 ) ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_76 * V_60 ,
struct V_87 * V_88 )
{
struct V_90 * V_91 = F_70 ( V_60 -> V_69 , V_60 -> V_82 ) ;
struct V_90 * V_92 = F_70 ( V_60 -> V_78 , V_60 -> V_84 ) ;
struct V_8 * V_9 ;
T_1 * V_7 ;
int V_33 = 0 ;
V_9 = F_64 ( V_3 , V_88 ) ;
V_7 = F_66 ( V_3 , V_9 ) ;
V_9 -> V_12 = V_60 -> V_79 ;
V_9 -> V_60 = V_60 ;
F_71 ( & V_9 -> V_71 , 1 ) ;
F_72 ( & V_9 -> V_71 , V_91 -> V_93 , 1 << V_94 ,
V_91 -> V_95 + V_60 -> V_80 ) ;
F_71 ( & V_9 -> V_75 , 1 ) ;
F_72 ( & V_9 -> V_75 , V_92 -> V_93 , 1 << V_94 ,
V_92 -> V_95 + V_60 -> V_81 ) ;
V_60 -> V_80 += 1 << V_94 ;
if ( V_60 -> V_80 >= V_91 -> V_96 ) {
V_60 -> V_80 = 0 ;
V_60 -> V_82 ++ ;
}
V_60 -> V_81 += 1 << V_94 ;
if ( V_60 -> V_81 >= V_92 -> V_96 ) {
V_60 -> V_81 = 0 ;
V_60 -> V_84 ++ ;
}
if ( V_3 -> V_97 ) {
V_33 = V_3 -> V_97 -> V_98 ( V_3 , V_7 , V_9 ) ;
if ( V_33 < 0 )
return V_33 ;
}
F_73 ( V_88 , & V_9 -> V_71 , & V_9 -> V_75 ,
1 << V_94 , V_7 ) ;
if ( F_56 ( V_60 -> V_69 ) == V_70 )
V_33 = F_74 ( V_88 ) ;
else
V_33 = F_75 ( V_88 ) ;
if ( ! V_33 && V_3 -> V_97 && V_3 -> V_97 -> V_99 )
V_33 = V_3 -> V_97 -> V_99 ( V_3 , V_7 , V_9 ) ;
return V_33 ;
}
static void F_76 ( struct V_2 * V_3 ,
struct V_76 * V_60 )
{
struct V_1 * V_100 = F_1 ( V_3 ) ;
unsigned V_101 = V_60 -> V_79 & ( V_3 -> V_55 - 1 ) ;
if ( ! V_100 -> V_88 )
V_100 -> V_88 = F_77 ( V_3 -> V_102 , V_103 ) ;
F_78 ( V_100 -> V_88 , V_100 -> V_6 [ V_101 ] ) ;
F_79 ( V_100 -> V_88 ,
V_104 | V_29 ,
V_105 , F_64 ( V_3 , V_100 -> V_88 ) ) ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_76 * V_60 )
{
struct V_1 * V_100 = F_1 ( V_3 ) ;
int V_33 ;
F_81 ( & V_60 -> V_106 , 1 ) ;
while( V_60 -> V_82 < V_60 -> V_69 -> V_107 &&
V_60 -> V_84 < V_60 -> V_78 -> V_107 ) {
F_76 ( V_3 , V_60 ) ;
F_82 ( & V_60 -> V_106 ) ;
V_33 = F_69 ( V_3 , V_60 , V_100 -> V_88 ) ;
switch ( V_33 ) {
case - V_108 :
F_83 ( & V_60 -> V_86 ) ;
F_84 ( V_60 -> V_86 ) ;
case - V_109 :
V_100 -> V_88 = NULL ;
V_60 -> V_79 ++ ;
continue;
case 0 :
F_85 ( & V_60 -> V_106 ) ;
V_60 -> V_79 ++ ;
F_86 () ;
continue;
default:
F_85 ( & V_60 -> V_106 ) ;
return V_33 ;
}
}
return 0 ;
}
static void F_87 ( struct V_77 * V_77 )
{
struct V_110 * V_111 = V_77 -> V_112 ;
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
F_88 ( V_77 , V_3 -> V_46 ) ;
}
static struct V_77 * F_89 ( struct V_110 * V_111 , unsigned V_115 ,
unsigned * V_116 )
{
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
struct V_77 * V_117 ;
unsigned int V_118 = ( V_115 + V_119 - 1 ) >> V_120 ;
T_5 V_121 = V_103 | V_122 ;
unsigned V_65 , V_123 ;
struct V_124 * V_124 ;
V_117 = F_90 ( V_103 , V_118 , V_3 -> V_46 ) ;
if ( ! V_117 )
return NULL ;
F_91 ( V_111 , V_117 ) ;
* V_116 = 0 ;
for ( V_65 = 0 ; V_65 < V_118 ; V_65 ++ ) {
V_124 = F_77 ( V_3 -> V_125 , V_121 ) ;
if ( ! V_124 ) {
* V_116 = 1 ;
break;
}
if ( V_65 == ( V_126 - 1 ) )
V_121 = ( V_121 | V_127 ) & ~ V_128 ;
V_123 = ( V_115 > V_119 ) ? V_119 : V_115 ;
if ( ! F_92 ( V_117 , V_124 , V_123 , 0 ) ) {
F_93 ( V_124 , V_3 -> V_125 ) ;
break;
}
V_115 -= V_123 ;
}
if ( ! V_117 -> V_129 ) {
F_94 ( V_117 ) ;
return NULL ;
}
return V_117 ;
}
static void F_95 ( struct V_2 * V_3 , struct V_77 * V_117 )
{
unsigned int V_65 ;
struct V_90 * V_130 ;
for ( V_65 = 0 ; V_65 < V_117 -> V_107 ; V_65 ++ ) {
V_130 = F_70 ( V_117 , V_65 ) ;
F_96 ( ! V_130 -> V_93 ) ;
F_93 ( V_130 -> V_93 , V_3 -> V_125 ) ;
V_130 -> V_93 = NULL ;
}
}
static struct V_110 * F_97 ( struct V_34 * V_35 ,
struct V_77 * V_77 , T_4 V_79 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
struct V_110 * V_111 ;
V_111 = F_77 ( V_3 -> V_131 , V_103 ) ;
V_111 -> V_113 = V_35 ;
V_111 -> V_132 = V_77 ;
V_111 -> V_79 = V_79 ;
V_111 -> error = 0 ;
V_111 -> V_133 = NULL ;
F_81 ( & V_111 -> V_106 , 0 ) ;
return V_111 ;
}
static void F_98 ( struct V_110 * V_111 )
{
F_82 ( & V_111 -> V_106 ) ;
}
static void F_99 ( struct V_110 * V_111 )
{
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
struct V_77 * V_132 = V_111 -> V_132 ;
struct V_110 * V_133 = V_111 -> V_133 ;
int error = V_111 -> error ;
if ( ! F_100 ( & V_111 -> V_106 ) )
return;
F_93 ( V_111 , V_3 -> V_131 ) ;
if ( F_101 ( ! V_133 ) )
F_102 ( V_132 , error ) ;
else {
if ( error && ! V_133 -> error )
V_133 -> error = error ;
F_99 ( V_133 ) ;
}
}
static void F_103 ( struct V_77 * V_117 , int error )
{
struct V_110 * V_111 = V_117 -> V_112 ;
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
unsigned V_134 = F_56 ( V_117 ) ;
if ( F_104 ( ! F_105 ( V_117 , V_135 ) && ! error ) )
error = - V_136 ;
if ( V_134 == V_70 )
F_95 ( V_3 , V_117 ) ;
F_94 ( V_117 ) ;
if ( V_134 == V_137 && ! error ) {
F_106 ( V_111 ) ;
return;
}
if ( F_104 ( error ) )
V_111 -> error = error ;
F_99 ( V_111 ) ;
}
static void F_91 ( struct V_110 * V_111 , struct V_77 * V_117 )
{
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
V_117 -> V_112 = V_111 ;
V_117 -> V_138 = F_103 ;
V_117 -> V_139 = V_3 -> V_140 -> V_141 ;
V_117 -> V_142 = V_111 -> V_132 -> V_142 ;
V_117 -> V_143 = F_87 ;
}
static int F_107 ( struct V_110 * V_111 , T_5 V_144 )
{
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
struct V_77 * V_132 = V_111 -> V_132 ;
struct V_77 * V_117 ;
V_117 = F_90 ( V_144 , F_108 ( V_132 ) , V_3 -> V_46 ) ;
if ( ! V_117 )
return 1 ;
F_98 ( V_111 ) ;
F_91 ( V_111 , V_117 ) ;
V_117 -> V_83 = 0 ;
V_117 -> V_107 = F_108 ( V_132 ) ;
V_117 -> V_129 = V_132 -> V_129 ;
V_117 -> V_145 = V_3 -> V_146 + V_111 -> V_79 ;
memcpy ( V_117 -> V_147 , F_109 ( V_132 ) ,
sizeof( struct V_90 ) * V_117 -> V_107 ) ;
F_110 ( V_117 ) ;
return 0 ;
}
static void F_111 ( struct V_110 * V_111 )
{
struct V_77 * V_117 = V_111 -> V_60 . V_78 ;
F_110 ( V_117 ) ;
}
static void F_112 ( struct V_148 * V_149 )
{
struct V_110 * V_111 = F_113 ( V_149 , struct V_110 , V_149 ) ;
if ( F_56 ( V_111 -> V_132 ) == V_137 ) {
F_98 ( V_111 ) ;
if ( F_107 ( V_111 , V_103 ) )
V_111 -> error = - V_45 ;
F_99 ( V_111 ) ;
} else
F_111 ( V_111 ) ;
}
static void F_114 ( struct V_110 * V_111 )
{
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
F_115 ( & V_111 -> V_149 , F_112 ) ;
F_116 ( V_3 -> V_150 , & V_111 -> V_149 ) ;
}
static void F_117 ( struct V_110 * V_111 ,
int error , int V_151 )
{
struct V_77 * V_117 = V_111 -> V_60 . V_78 ;
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
if ( F_104 ( error < 0 ) ) {
F_95 ( V_3 , V_117 ) ;
F_94 ( V_117 ) ;
V_111 -> error = - V_136 ;
F_99 ( V_111 ) ;
return;
}
F_96 ( V_111 -> V_60 . V_84 < V_117 -> V_107 ) ;
V_117 -> V_145 = V_3 -> V_146 + V_111 -> V_79 ;
if ( V_151 )
F_114 ( V_111 ) ;
else
F_110 ( V_117 ) ;
}
static void F_118 ( struct V_110 * V_111 )
{
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
struct V_77 * V_117 ;
struct V_110 * V_152 ;
int V_153 ;
unsigned V_116 = 0 ;
unsigned V_154 = V_111 -> V_132 -> V_129 ;
T_4 V_79 = V_111 -> V_79 ;
int V_33 ;
F_98 ( V_111 ) ;
F_62 ( V_3 , & V_111 -> V_60 , NULL , V_111 -> V_132 , V_79 ) ;
while ( V_154 ) {
V_117 = F_89 ( V_111 , V_154 , & V_116 ) ;
if ( F_104 ( ! V_117 ) ) {
V_111 -> error = - V_45 ;
break;
}
V_111 -> V_60 . V_78 = V_117 ;
V_111 -> V_60 . V_84 = 0 ;
V_154 -= V_117 -> V_129 ;
V_79 += F_119 ( V_117 ) ;
F_98 ( V_111 ) ;
V_33 = F_80 ( V_3 , & V_111 -> V_60 ) ;
V_153 = F_100 ( & V_111 -> V_60 . V_106 ) ;
if ( V_153 ) {
F_117 ( V_111 , V_33 , 0 ) ;
if ( F_104 ( V_33 < 0 ) )
break;
V_111 -> V_79 = V_79 ;
}
if ( F_104 ( V_116 ) )
F_120 ( V_155 , V_156 / 100 ) ;
if ( F_104 ( ! V_153 && V_154 ) ) {
V_152 = F_97 ( V_111 -> V_113 , V_111 -> V_132 ,
V_79 ) ;
F_98 ( V_152 ) ;
F_62 ( V_3 , & V_152 -> V_60 , NULL ,
V_111 -> V_132 , V_79 ) ;
V_152 -> V_60 . V_82 = V_111 -> V_60 . V_82 ;
V_152 -> V_60 . V_80 = V_111 -> V_60 . V_80 ;
if ( ! V_111 -> V_133 )
V_152 -> V_133 = V_111 ;
else {
V_152 -> V_133 = V_111 -> V_133 ;
F_98 ( V_111 -> V_133 ) ;
F_99 ( V_111 ) ;
}
V_111 = V_152 ;
}
}
F_99 ( V_111 ) ;
}
static void F_121 ( struct V_110 * V_111 , int error )
{
if ( F_104 ( error < 0 ) )
V_111 -> error = - V_136 ;
F_99 ( V_111 ) ;
}
static void F_122 ( struct V_110 * V_111 )
{
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
int V_33 = 0 ;
F_98 ( V_111 ) ;
F_62 ( V_3 , & V_111 -> V_60 , V_111 -> V_132 , V_111 -> V_132 ,
V_111 -> V_79 ) ;
V_33 = F_80 ( V_3 , & V_111 -> V_60 ) ;
if ( F_100 ( & V_111 -> V_60 . V_106 ) )
F_121 ( V_111 , V_33 ) ;
F_99 ( V_111 ) ;
}
static void V_105 ( struct V_157 * V_158 ,
int error )
{
struct V_8 * V_9 = V_158 -> V_58 ;
struct V_76 * V_60 = V_9 -> V_60 ;
struct V_110 * V_111 = F_113 ( V_60 , struct V_110 , V_60 ) ;
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
if ( error == - V_109 ) {
F_123 ( & V_60 -> V_86 ) ;
return;
}
if ( ! error && V_3 -> V_97 && V_3 -> V_97 -> V_99 )
error = V_3 -> V_97 -> V_99 ( V_3 , F_66 ( V_3 , V_9 ) , V_9 ) ;
F_93 ( F_65 ( V_3 , V_9 ) , V_3 -> V_102 ) ;
if ( ! F_100 ( & V_60 -> V_106 ) )
return;
if ( F_56 ( V_111 -> V_132 ) == V_137 )
F_121 ( V_111 , error ) ;
else
F_117 ( V_111 , error , 1 ) ;
}
static void F_124 ( struct V_148 * V_149 )
{
struct V_110 * V_111 = F_113 ( V_149 , struct V_110 , V_149 ) ;
if ( F_56 ( V_111 -> V_132 ) == V_137 )
F_122 ( V_111 ) ;
else
F_118 ( V_111 ) ;
}
static void F_106 ( struct V_110 * V_111 )
{
struct V_2 * V_3 = V_111 -> V_113 -> V_114 ;
F_115 ( & V_111 -> V_149 , F_124 ) ;
F_116 ( V_3 -> V_159 , & V_111 -> V_149 ) ;
}
static int F_125 ( T_1 * V_24 , char * V_160 , unsigned int V_115 )
{
char V_161 [ 3 ] ;
char * V_162 ;
unsigned int V_65 ;
V_161 [ 2 ] = '\0' ;
for ( V_65 = 0 ; V_65 < V_115 ; V_65 ++ ) {
V_161 [ 0 ] = * V_160 ++ ;
V_161 [ 1 ] = * V_160 ++ ;
V_24 [ V_65 ] = ( T_1 ) F_126 ( V_161 , & V_162 , 16 ) ;
if ( V_162 != & V_161 [ 2 ] )
return - V_39 ;
}
if ( * V_160 != '\0' )
return - V_39 ;
return 0 ;
}
static void F_127 ( char * V_160 , T_1 * V_24 , unsigned int V_115 )
{
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < V_115 ; V_65 ++ ) {
sprintf ( V_160 , L_13 , * V_24 ) ;
V_160 += 2 ;
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
static int F_130 ( struct V_2 * V_3 , int V_4 , char * V_163 )
{
struct V_1 * V_40 = F_13 ( V_3 -> V_4 , V_4 ) ;
unsigned V_65 ;
int V_23 ;
for ( V_65 = 0 ; V_65 < V_3 -> V_55 ; V_65 ++ ) {
V_40 -> V_6 [ V_65 ] = F_131 ( V_163 , 0 , 0 ) ;
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
int V_164 = strlen ( V_24 ) ;
if ( V_3 -> V_25 != ( V_164 >> 1 ) )
goto V_165;
if ( ! V_3 -> V_25 && strcmp ( V_24 , L_14 ) )
goto V_165;
if ( V_3 -> V_25 && F_125 ( V_3 -> V_24 , V_24 , V_3 -> V_25 ) < 0 )
goto V_165;
F_135 ( V_166 , & V_3 -> V_28 ) ;
V_33 = F_132 ( V_3 ) ;
V_165:
memset ( V_24 , '0' , V_164 ) ;
return V_33 ;
}
static int F_136 ( struct V_2 * V_3 )
{
F_137 ( V_166 , & V_3 -> V_28 ) ;
memset ( & V_3 -> V_24 , 0 , V_3 -> V_25 * sizeof( T_1 ) ) ;
return F_132 ( V_3 ) ;
}
static void F_138 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
struct V_1 * V_40 ;
int V_4 ;
V_35 -> V_114 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_150 )
F_139 ( V_3 -> V_150 ) ;
if ( V_3 -> V_159 )
F_139 ( V_3 -> V_159 ) ;
if ( V_3 -> V_4 )
F_12 (cpu) {
V_40 = F_13 ( V_3 -> V_4 , V_4 ) ;
if ( V_40 -> V_88 )
F_93 ( V_40 -> V_88 , V_3 -> V_102 ) ;
F_128 ( V_3 , V_4 ) ;
}
if ( V_3 -> V_46 )
F_140 ( V_3 -> V_46 ) ;
if ( V_3 -> V_125 )
F_141 ( V_3 -> V_125 ) ;
if ( V_3 -> V_102 )
F_141 ( V_3 -> V_102 ) ;
if ( V_3 -> V_131 )
F_141 ( V_3 -> V_131 ) ;
if ( V_3 -> V_97 && V_3 -> V_97 -> V_167 )
V_3 -> V_97 -> V_167 ( V_3 ) ;
if ( V_3 -> V_140 )
F_142 ( V_35 , V_3 -> V_140 ) ;
if ( V_3 -> V_4 )
F_143 ( V_3 -> V_4 ) ;
F_26 ( V_3 -> V_37 ) ;
F_26 ( V_3 -> V_168 ) ;
F_26 ( V_3 ) ;
}
static int F_144 ( struct V_34 * V_35 ,
char * V_169 , char * V_24 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
char * V_170 , * V_37 , * V_171 , * V_172 , * V_173 , * V_174 ;
char * V_175 = NULL ;
int V_4 , V_176 = - V_39 ;
if ( strchr ( V_169 , '(' ) ) {
V_35 -> error = L_15 ;
return - V_39 ;
}
V_3 -> V_168 = F_145 ( V_169 , V_44 ) ;
if ( ! V_3 -> V_168 )
goto V_177;
V_170 = V_169 ;
V_174 = F_146 ( & V_170 , L_14 ) ;
V_37 = F_146 ( & V_174 , L_16 ) ;
if ( ! V_174 )
V_3 -> V_55 = 1 ;
else if ( sscanf ( V_174 , L_17 , & V_3 -> V_55 ) != 1 ||
! F_147 ( V_3 -> V_55 ) ) {
V_35 -> error = L_18 ;
return - V_39 ;
}
V_3 -> V_54 = V_3 -> V_55 ;
V_3 -> V_37 = F_145 ( V_37 , V_44 ) ;
if ( ! V_3 -> V_37 )
goto V_177;
V_171 = F_146 ( & V_170 , L_14 ) ;
V_173 = F_146 ( & V_170 , L_14 ) ;
V_172 = F_146 ( & V_173 , L_16 ) ;
if ( V_170 )
F_148 ( L_19 ) ;
V_3 -> V_4 = F_149 ( sizeof( * ( V_3 -> V_4 ) ) +
V_3 -> V_55 * sizeof( * ( V_3 -> V_4 -> V_6 ) ) ,
F_150 ( struct V_1 ) ) ;
if ( ! V_3 -> V_4 ) {
V_35 -> error = L_20 ;
goto V_177;
}
if ( ! V_171 || ( ! strcmp ( V_171 , L_21 ) && ! V_172 ) ) {
V_171 = L_22 ;
V_172 = L_21 ;
}
if ( strcmp ( V_171 , L_23 ) && ! V_172 ) {
V_35 -> error = L_24 ;
return - V_39 ;
}
V_175 = F_151 ( V_178 , V_44 ) ;
if ( ! V_175 )
goto V_177;
V_176 = snprintf ( V_175 , V_178 ,
L_25 , V_171 , V_37 ) ;
if ( V_176 < 0 ) {
F_31 ( V_175 ) ;
goto V_177;
}
F_12 (cpu) {
V_176 = F_130 ( V_3 , V_4 , V_175 ) ;
if ( V_176 < 0 ) {
V_35 -> error = L_26 ;
goto V_43;
}
}
V_176 = F_134 ( V_3 , V_24 ) ;
if ( V_176 < 0 ) {
V_35 -> error = L_27 ;
goto V_43;
}
V_3 -> V_10 = F_21 ( F_3 ( V_3 ) ) ;
if ( V_3 -> V_10 )
V_3 -> V_10 = F_152 ( V_3 -> V_10 ,
( unsigned int ) ( sizeof( V_50 ) / sizeof( T_1 ) ) ) ;
else if ( V_172 ) {
F_148 ( L_28 ) ;
V_172 = NULL ;
}
if ( V_172 == NULL )
V_3 -> V_97 = NULL ;
else if ( strcmp ( V_172 , L_21 ) == 0 )
V_3 -> V_97 = & V_179 ;
else if ( strcmp ( V_172 , L_29 ) == 0 )
V_3 -> V_97 = & V_180 ;
else if ( strcmp ( V_172 , L_30 ) == 0 )
V_3 -> V_97 = & V_181 ;
else if ( strcmp ( V_172 , L_31 ) == 0 )
V_3 -> V_97 = & V_182 ;
else if ( strcmp ( V_172 , L_32 ) == 0 )
V_3 -> V_97 = & V_183 ;
else if ( strcmp ( V_172 , L_33 ) == 0 ) {
V_3 -> V_97 = & V_184 ;
if ( V_3 -> V_25 % V_3 -> V_54 )
V_3 -> V_54 ++ ;
} else {
V_176 = - V_39 ;
V_35 -> error = L_34 ;
goto V_43;
}
if ( V_3 -> V_97 && V_3 -> V_97 -> V_185 ) {
V_176 = V_3 -> V_97 -> V_185 ( V_3 , V_35 , V_173 ) ;
if ( V_176 < 0 ) {
V_35 -> error = L_35 ;
goto V_43;
}
}
if ( V_3 -> V_97 && V_3 -> V_97 -> V_186 ) {
V_176 = V_3 -> V_97 -> V_186 ( V_3 ) ;
if ( V_176 < 0 ) {
V_35 -> error = L_36 ;
goto V_43;
}
}
V_176 = 0 ;
V_43:
F_31 ( V_175 ) ;
return V_176 ;
V_177:
V_35 -> error = L_37 ;
return - V_45 ;
}
static int F_153 ( struct V_34 * V_35 , unsigned int V_187 , char * * V_188 )
{
struct V_2 * V_3 ;
unsigned int V_25 , V_189 ;
unsigned long long V_190 ;
int V_176 ;
struct V_191 V_192 ;
const char * V_193 ;
static struct V_194 V_195 [] = {
{ 0 , 1 , L_38 } ,
} ;
if ( V_187 < 5 ) {
V_35 -> error = L_39 ;
return - V_39 ;
}
V_25 = strlen ( V_188 [ 1 ] ) >> 1 ;
V_3 = F_30 ( sizeof( * V_3 ) + V_25 * sizeof( T_1 ) , V_44 ) ;
if ( ! V_3 ) {
V_35 -> error = L_40 ;
return - V_45 ;
}
V_3 -> V_25 = V_25 ;
V_35 -> V_114 = V_3 ;
V_176 = F_144 ( V_35 , V_188 [ 0 ] , V_188 [ 1 ] ) ;
if ( V_176 < 0 )
goto V_43;
V_176 = - V_45 ;
V_3 -> V_131 = F_154 ( V_196 , V_197 ) ;
if ( ! V_3 -> V_131 ) {
V_35 -> error = L_41 ;
goto V_43;
}
V_3 -> V_89 = sizeof( struct V_87 ) ;
V_3 -> V_89 += F_155 ( F_3 ( V_3 ) ) ;
V_3 -> V_89 = F_67 ( V_3 -> V_89 , F_156 () ) ;
V_3 -> V_89 += F_68 ( F_3 ( V_3 ) ) &
~ ( F_156 () - 1 ) ;
V_3 -> V_102 = F_157 ( V_196 , V_3 -> V_89 +
sizeof( struct V_8 ) + V_3 -> V_10 ) ;
if ( ! V_3 -> V_102 ) {
V_35 -> error = L_42 ;
goto V_43;
}
V_3 -> V_125 = F_158 ( V_198 , 0 ) ;
if ( ! V_3 -> V_125 ) {
V_35 -> error = L_43 ;
goto V_43;
}
V_3 -> V_46 = F_159 ( V_196 , 0 ) ;
if ( ! V_3 -> V_46 ) {
V_35 -> error = L_44 ;
goto V_43;
}
V_176 = - V_39 ;
if ( sscanf ( V_188 [ 2 ] , L_45 , & V_190 ) != 1 ) {
V_35 -> error = L_46 ;
goto V_43;
}
V_3 -> V_85 = V_190 ;
if ( F_160 ( V_35 , V_188 [ 3 ] , F_161 ( V_35 -> V_199 ) , & V_3 -> V_140 ) ) {
V_35 -> error = L_47 ;
goto V_43;
}
if ( sscanf ( V_188 [ 4 ] , L_45 , & V_190 ) != 1 ) {
V_35 -> error = L_48 ;
goto V_43;
}
V_3 -> V_146 = V_190 ;
V_188 += 5 ;
V_187 -= 5 ;
if ( V_187 ) {
V_192 . V_187 = V_187 ;
V_192 . V_188 = V_188 ;
V_176 = F_162 ( V_195 , & V_192 , & V_189 , & V_35 -> error ) ;
if ( V_176 )
goto V_43;
V_193 = F_163 ( & V_192 ) ;
if ( V_189 == 1 && V_193 &&
! strcasecmp ( V_193 , L_49 ) )
V_35 -> V_200 = 1 ;
else if ( V_189 ) {
V_176 = - V_39 ;
V_35 -> error = L_50 ;
goto V_43;
}
}
V_176 = - V_45 ;
V_3 -> V_150 = F_164 ( L_51 ,
V_201 |
V_202 ,
1 ) ;
if ( ! V_3 -> V_150 ) {
V_35 -> error = L_52 ;
goto V_43;
}
V_3 -> V_159 = F_164 ( L_53 ,
V_201 |
V_203 |
V_202 ,
1 ) ;
if ( ! V_3 -> V_159 ) {
V_35 -> error = L_54 ;
goto V_43;
}
V_35 -> V_204 = 1 ;
V_35 -> V_205 = 1 ;
return 0 ;
V_43:
F_138 ( V_35 ) ;
return V_176 ;
}
static int F_165 ( struct V_34 * V_35 , struct V_77 * V_77 ,
union V_206 * V_207 )
{
struct V_110 * V_111 ;
struct V_2 * V_3 ;
if ( F_104 ( V_77 -> V_142 & ( V_208 | V_209 ) ) ) {
V_3 = V_35 -> V_114 ;
V_77 -> V_139 = V_3 -> V_140 -> V_141 ;
if ( F_119 ( V_77 ) )
V_77 -> V_145 = V_3 -> V_146 + F_166 ( V_35 , V_77 -> V_145 ) ;
return V_210 ;
}
V_111 = F_97 ( V_35 , V_77 , F_166 ( V_35 , V_77 -> V_145 ) ) ;
if ( F_56 ( V_111 -> V_132 ) == V_137 ) {
if ( F_107 ( V_111 , V_211 ) )
F_114 ( V_111 ) ;
} else
F_106 ( V_111 ) ;
return V_212 ;
}
static int F_167 ( struct V_34 * V_35 , T_6 type ,
char * V_213 , unsigned int V_214 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
unsigned int V_215 = 0 ;
switch ( type ) {
case V_216 :
V_213 [ 0 ] = '\0' ;
break;
case V_217 :
F_168 ( L_55 , V_3 -> V_168 ) ;
if ( V_3 -> V_25 > 0 ) {
if ( ( V_214 - V_215 ) < ( ( V_3 -> V_25 << 1 ) + 1 ) )
return - V_45 ;
F_127 ( V_213 + V_215 , V_3 -> V_24 , V_3 -> V_25 ) ;
V_215 += V_3 -> V_25 << 1 ;
} else {
if ( V_215 >= V_214 )
return - V_45 ;
V_213 [ V_215 ++ ] = '-' ;
}
F_168 ( L_56 , ( unsigned long long ) V_3 -> V_85 ,
V_3 -> V_140 -> V_218 , ( unsigned long long ) V_3 -> V_146 ) ;
if ( V_35 -> V_200 )
F_168 ( L_57 ) ;
break;
}
return 0 ;
}
static void F_169 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
F_135 ( V_219 , & V_3 -> V_28 ) ;
}
static int F_170 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
if ( ! F_171 ( V_166 , & V_3 -> V_28 ) ) {
F_172 ( L_58 ) ;
return - V_220 ;
}
return 0 ;
}
static void F_173 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
F_137 ( V_219 , & V_3 -> V_28 ) ;
}
static int F_174 ( struct V_34 * V_35 , unsigned V_187 , char * * V_188 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
int V_176 = - V_39 ;
if ( V_187 < 2 )
goto error;
if ( ! strcasecmp ( V_188 [ 0 ] , L_59 ) ) {
if ( ! F_171 ( V_219 , & V_3 -> V_28 ) ) {
F_148 ( L_60 ) ;
return - V_39 ;
}
if ( V_187 == 3 && ! strcasecmp ( V_188 [ 1 ] , L_61 ) ) {
V_176 = F_134 ( V_3 , V_188 [ 2 ] ) ;
if ( V_176 )
return V_176 ;
if ( V_3 -> V_97 && V_3 -> V_97 -> V_186 )
V_176 = V_3 -> V_97 -> V_186 ( V_3 ) ;
return V_176 ;
}
if ( V_187 == 2 && ! strcasecmp ( V_188 [ 1 ] , L_62 ) ) {
if ( V_3 -> V_97 && V_3 -> V_97 -> V_221 ) {
V_176 = V_3 -> V_97 -> V_221 ( V_3 ) ;
if ( V_176 )
return V_176 ;
}
return F_136 ( V_3 ) ;
}
}
error:
F_148 ( L_63 ) ;
return - V_39 ;
}
static int F_175 ( struct V_34 * V_35 , struct V_222 * V_223 ,
struct V_90 * V_224 , int V_225 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
struct V_226 * V_227 = F_176 ( V_3 -> V_140 -> V_141 ) ;
if ( ! V_227 -> V_228 )
return V_225 ;
V_223 -> V_139 = V_3 -> V_140 -> V_141 ;
V_223 -> V_145 = V_3 -> V_146 + F_166 ( V_35 , V_223 -> V_145 ) ;
return F_177 ( V_225 , V_227 -> V_228 ( V_227 , V_223 , V_224 ) ) ;
}
static int F_178 ( struct V_34 * V_35 ,
T_7 V_229 , void * V_58 )
{
struct V_2 * V_3 = V_35 -> V_114 ;
return V_229 ( V_35 , V_3 -> V_140 , V_3 -> V_146 , V_35 -> V_123 , V_58 ) ;
}
static int T_8 F_179 ( void )
{
int V_33 ;
V_197 = F_180 ( V_110 , 0 ) ;
if ( ! V_197 )
return - V_45 ;
V_33 = F_181 ( & V_230 ) ;
if ( V_33 < 0 ) {
F_172 ( L_64 , V_33 ) ;
F_182 ( V_197 ) ;
}
return V_33 ;
}
static void T_9 F_183 ( void )
{
F_184 ( & V_230 ) ;
F_182 ( V_197 ) ;
}
