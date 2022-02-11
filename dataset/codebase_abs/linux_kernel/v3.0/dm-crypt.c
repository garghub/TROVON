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
memset ( V_7 , 0 , V_3 -> V_10 - sizeof( V_13 ) ) ;
V_49 = F_39 ( ( ( V_13 ) V_9 -> V_12 << V_3 -> V_16 . V_47 . V_48 ) + 1 ) ;
F_40 ( V_49 , ( T_2 * ) ( V_7 + V_3 -> V_10 - sizeof( V_13 ) ) ) ;
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
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
if ( V_51 -> V_27 && ! F_19 ( V_51 -> V_27 ) )
F_43 ( V_51 -> V_27 ) ;
V_51 -> V_27 = NULL ;
F_26 ( V_51 -> V_52 ) ;
V_51 -> V_52 = NULL ;
}
static int F_44 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_41 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
V_51 -> V_27 = F_45 ( L_10 , 0 , 0 ) ;
if ( F_19 ( V_51 -> V_27 ) ) {
V_35 -> error = L_11 ;
return F_29 ( V_51 -> V_27 ) ;
}
if ( V_3 -> V_53 == V_3 -> V_54 ) {
V_51 -> V_52 = NULL ;
return 0 ;
}
V_51 -> V_52 = F_30 ( V_55 , V_44 ) ;
if ( ! V_51 -> V_52 ) {
F_42 ( V_3 ) ;
V_35 -> error = L_12 ;
return - V_45 ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
int V_56 = V_3 -> V_25 / V_3 -> V_53 ;
if ( V_51 -> V_52 )
memcpy ( V_51 -> V_52 , V_3 -> V_24 + ( V_3 -> V_54 * V_56 ) ,
F_47 ( V_51 -> V_27 ) ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
if ( V_51 -> V_52 )
memset ( V_51 -> V_52 , 0 , V_55 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_57 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
struct {
struct V_58 V_18 ;
char V_59 [ F_50 ( V_51 -> V_27 ) ] ;
} V_60 ;
struct V_61 V_62 ;
V_11 V_63 [ 4 ] ;
int V_64 , V_33 ;
V_60 . V_18 . V_26 = V_51 -> V_27 ;
V_60 . V_18 . V_28 = V_29 ;
V_33 = F_51 ( & V_60 . V_18 ) ;
if ( V_33 )
return V_33 ;
if ( V_51 -> V_52 ) {
V_33 = F_52 ( & V_60 . V_18 , V_51 -> V_52 , V_55 ) ;
if ( V_33 )
return V_33 ;
}
V_33 = F_52 ( & V_60 . V_18 , V_57 + 16 , 16 * 31 ) ;
if ( V_33 )
return V_33 ;
V_63 [ 0 ] = F_6 ( V_9 -> V_12 & 0xFFFFFFFF ) ;
V_63 [ 1 ] = F_6 ( ( ( ( V_13 ) V_9 -> V_12 >> 32 ) & 0x00FFFFFF ) | 0x80000000 ) ;
V_63 [ 2 ] = F_6 ( 4024 ) ;
V_63 [ 3 ] = 0 ;
V_33 = F_52 ( & V_60 . V_18 , ( T_1 * ) V_63 , sizeof( V_63 ) ) ;
if ( V_33 )
return V_33 ;
V_33 = F_53 ( & V_60 . V_18 , & V_62 ) ;
if ( V_33 )
return V_33 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ )
F_54 ( & V_62 . V_66 [ V_64 ] ) ;
memcpy ( V_7 , & V_62 . V_66 , V_3 -> V_10 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_67 ;
int V_33 = 0 ;
if ( F_56 ( V_9 -> V_59 -> V_68 ) == V_69 ) {
V_67 = F_57 ( F_58 ( & V_9 -> V_70 ) , V_71 ) ;
V_33 = F_49 ( V_3 , V_7 , V_9 , V_67 + V_9 -> V_70 . V_72 ) ;
F_59 ( V_67 , V_71 ) ;
} else
memset ( V_7 , 0 , V_3 -> V_10 ) ;
return V_33 ;
}
static int F_60 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_73 ;
int V_33 ;
if ( F_56 ( V_9 -> V_59 -> V_68 ) == V_69 )
return 0 ;
V_73 = F_57 ( F_58 ( & V_9 -> V_74 ) , V_71 ) ;
V_33 = F_49 ( V_3 , V_7 , V_9 , V_73 + V_9 -> V_74 . V_72 ) ;
if ( ! V_33 )
F_61 ( V_73 + V_9 -> V_74 . V_72 , V_7 , V_3 -> V_10 ) ;
F_59 ( V_73 , V_71 ) ;
return V_33 ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_75 * V_59 ,
struct V_76 * V_77 , struct V_76 * V_68 ,
T_3 V_78 )
{
V_59 -> V_68 = V_68 ;
V_59 -> V_77 = V_77 ;
V_59 -> V_79 = 0 ;
V_59 -> V_80 = 0 ;
V_59 -> V_81 = V_68 ? V_68 -> V_82 : 0 ;
V_59 -> V_83 = V_77 ? V_77 -> V_82 : 0 ;
V_59 -> V_78 = V_78 + V_3 -> V_84 ;
F_63 ( & V_59 -> V_85 ) ;
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
struct V_75 * V_59 ,
struct V_86 * V_87 )
{
struct V_89 * V_90 = F_70 ( V_59 -> V_68 , V_59 -> V_81 ) ;
struct V_89 * V_91 = F_70 ( V_59 -> V_77 , V_59 -> V_83 ) ;
struct V_8 * V_9 ;
T_1 * V_7 ;
int V_33 = 0 ;
V_9 = F_64 ( V_3 , V_87 ) ;
V_7 = F_66 ( V_3 , V_9 ) ;
V_9 -> V_12 = V_59 -> V_78 ;
V_9 -> V_59 = V_59 ;
F_71 ( & V_9 -> V_70 , 1 ) ;
F_72 ( & V_9 -> V_70 , V_90 -> V_92 , 1 << V_93 ,
V_90 -> V_94 + V_59 -> V_79 ) ;
F_71 ( & V_9 -> V_74 , 1 ) ;
F_72 ( & V_9 -> V_74 , V_91 -> V_92 , 1 << V_93 ,
V_91 -> V_94 + V_59 -> V_80 ) ;
V_59 -> V_79 += 1 << V_93 ;
if ( V_59 -> V_79 >= V_90 -> V_95 ) {
V_59 -> V_79 = 0 ;
V_59 -> V_81 ++ ;
}
V_59 -> V_80 += 1 << V_93 ;
if ( V_59 -> V_80 >= V_91 -> V_95 ) {
V_59 -> V_80 = 0 ;
V_59 -> V_83 ++ ;
}
if ( V_3 -> V_96 ) {
V_33 = V_3 -> V_96 -> V_97 ( V_3 , V_7 , V_9 ) ;
if ( V_33 < 0 )
return V_33 ;
}
F_73 ( V_87 , & V_9 -> V_70 , & V_9 -> V_74 ,
1 << V_93 , V_7 ) ;
if ( F_56 ( V_59 -> V_68 ) == V_69 )
V_33 = F_74 ( V_87 ) ;
else
V_33 = F_75 ( V_87 ) ;
if ( ! V_33 && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
V_33 = V_3 -> V_96 -> V_98 ( V_3 , V_7 , V_9 ) ;
return V_33 ;
}
static void F_76 ( struct V_2 * V_3 ,
struct V_75 * V_59 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
unsigned V_100 = V_59 -> V_78 & ( V_3 -> V_54 - 1 ) ;
if ( ! V_99 -> V_87 )
V_99 -> V_87 = F_77 ( V_3 -> V_101 , V_102 ) ;
F_78 ( V_99 -> V_87 , V_99 -> V_6 [ V_100 ] ) ;
F_79 ( V_99 -> V_87 ,
V_103 | V_29 ,
V_104 , F_64 ( V_3 , V_99 -> V_87 ) ) ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_75 * V_59 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
int V_33 ;
F_81 ( & V_59 -> V_105 , 1 ) ;
while( V_59 -> V_81 < V_59 -> V_68 -> V_106 &&
V_59 -> V_83 < V_59 -> V_77 -> V_106 ) {
F_76 ( V_3 , V_59 ) ;
F_82 ( & V_59 -> V_105 ) ;
V_33 = F_69 ( V_3 , V_59 , V_99 -> V_87 ) ;
switch ( V_33 ) {
case - V_107 :
F_83 ( & V_59 -> V_85 ) ;
F_84 ( V_59 -> V_85 ) ;
case - V_108 :
V_99 -> V_87 = NULL ;
V_59 -> V_78 ++ ;
continue;
case 0 :
F_85 ( & V_59 -> V_105 ) ;
V_59 -> V_78 ++ ;
F_86 () ;
continue;
default:
F_85 ( & V_59 -> V_105 ) ;
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
T_4 V_120 = V_102 | V_121 ;
unsigned V_64 , V_122 ;
struct V_123 * V_123 ;
V_116 = F_90 ( V_102 , V_117 , V_3 -> V_46 ) ;
if ( ! V_116 )
return NULL ;
F_91 ( V_110 , V_116 ) ;
* V_115 = 0 ;
for ( V_64 = 0 ; V_64 < V_117 ; V_64 ++ ) {
V_123 = F_77 ( V_3 -> V_124 , V_120 ) ;
if ( ! V_123 ) {
* V_115 = 1 ;
break;
}
if ( V_64 == ( V_125 - 1 ) )
V_120 = ( V_120 | V_126 ) & ~ V_127 ;
V_122 = ( V_114 > V_118 ) ? V_118 : V_114 ;
if ( ! F_92 ( V_116 , V_123 , V_122 , 0 ) ) {
F_93 ( V_123 , V_3 -> V_124 ) ;
break;
}
V_114 -= V_122 ;
}
if ( ! V_116 -> V_128 ) {
F_94 ( V_116 ) ;
return NULL ;
}
return V_116 ;
}
static void F_95 ( struct V_2 * V_3 , struct V_76 * V_116 )
{
unsigned int V_64 ;
struct V_89 * V_129 ;
for ( V_64 = 0 ; V_64 < V_116 -> V_106 ; V_64 ++ ) {
V_129 = F_70 ( V_116 , V_64 ) ;
F_96 ( ! V_129 -> V_92 ) ;
F_93 ( V_129 -> V_92 , V_3 -> V_124 ) ;
V_129 -> V_92 = NULL ;
}
}
static struct V_109 * F_97 ( struct V_34 * V_35 ,
struct V_76 * V_76 , T_3 V_78 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
struct V_109 * V_110 ;
V_110 = F_77 ( V_3 -> V_130 , V_102 ) ;
V_110 -> V_112 = V_35 ;
V_110 -> V_131 = V_76 ;
V_110 -> V_78 = V_78 ;
V_110 -> error = 0 ;
V_110 -> V_132 = NULL ;
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
struct V_76 * V_131 = V_110 -> V_131 ;
struct V_109 * V_132 = V_110 -> V_132 ;
int error = V_110 -> error ;
if ( ! F_100 ( & V_110 -> V_105 ) )
return;
F_93 ( V_110 , V_3 -> V_130 ) ;
if ( F_101 ( ! V_132 ) )
F_102 ( V_131 , error ) ;
else {
if ( error && ! V_132 -> error )
V_132 -> error = error ;
F_99 ( V_132 ) ;
}
}
static void F_103 ( struct V_76 * V_116 , int error )
{
struct V_109 * V_110 = V_116 -> V_111 ;
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
unsigned V_133 = F_56 ( V_116 ) ;
if ( F_104 ( ! F_105 ( V_116 , V_134 ) && ! error ) )
error = - V_135 ;
if ( V_133 == V_69 )
F_95 ( V_3 , V_116 ) ;
F_94 ( V_116 ) ;
if ( V_133 == V_136 && ! error ) {
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
V_116 -> V_137 = F_103 ;
V_116 -> V_138 = V_3 -> V_139 -> V_140 ;
V_116 -> V_141 = V_110 -> V_131 -> V_141 ;
V_116 -> V_142 = F_87 ;
}
static int F_107 ( struct V_109 * V_110 , T_4 V_143 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
struct V_76 * V_131 = V_110 -> V_131 ;
struct V_76 * V_116 ;
V_116 = F_90 ( V_143 , F_108 ( V_131 ) , V_3 -> V_46 ) ;
if ( ! V_116 )
return 1 ;
F_98 ( V_110 ) ;
F_91 ( V_110 , V_116 ) ;
V_116 -> V_82 = 0 ;
V_116 -> V_106 = F_108 ( V_131 ) ;
V_116 -> V_128 = V_131 -> V_128 ;
V_116 -> V_144 = V_3 -> V_145 + V_110 -> V_78 ;
memcpy ( V_116 -> V_146 , F_109 ( V_131 ) ,
sizeof( struct V_89 ) * V_116 -> V_106 ) ;
F_110 ( V_116 ) ;
return 0 ;
}
static void F_111 ( struct V_109 * V_110 )
{
struct V_76 * V_116 = V_110 -> V_59 . V_77 ;
F_110 ( V_116 ) ;
}
static void F_112 ( struct V_147 * V_148 )
{
struct V_109 * V_110 = F_113 ( V_148 , struct V_109 , V_148 ) ;
if ( F_56 ( V_110 -> V_131 ) == V_136 ) {
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
F_115 ( & V_110 -> V_148 , F_112 ) ;
F_116 ( V_3 -> V_149 , & V_110 -> V_148 ) ;
}
static void F_117 ( struct V_109 * V_110 ,
int error , int V_150 )
{
struct V_76 * V_116 = V_110 -> V_59 . V_77 ;
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
if ( F_104 ( error < 0 ) ) {
F_95 ( V_3 , V_116 ) ;
F_94 ( V_116 ) ;
V_110 -> error = - V_135 ;
F_99 ( V_110 ) ;
return;
}
F_96 ( V_110 -> V_59 . V_83 < V_116 -> V_106 ) ;
V_116 -> V_144 = V_3 -> V_145 + V_110 -> V_78 ;
if ( V_150 )
F_114 ( V_110 ) ;
else
F_110 ( V_116 ) ;
}
static void F_118 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
struct V_76 * V_116 ;
struct V_109 * V_151 ;
int V_152 ;
unsigned V_115 = 0 ;
unsigned V_153 = V_110 -> V_131 -> V_128 ;
T_3 V_78 = V_110 -> V_78 ;
int V_33 ;
F_98 ( V_110 ) ;
F_62 ( V_3 , & V_110 -> V_59 , NULL , V_110 -> V_131 , V_78 ) ;
while ( V_153 ) {
V_116 = F_89 ( V_110 , V_153 , & V_115 ) ;
if ( F_104 ( ! V_116 ) ) {
V_110 -> error = - V_45 ;
break;
}
V_110 -> V_59 . V_77 = V_116 ;
V_110 -> V_59 . V_83 = 0 ;
V_153 -= V_116 -> V_128 ;
V_78 += F_119 ( V_116 ) ;
F_98 ( V_110 ) ;
V_33 = F_80 ( V_3 , & V_110 -> V_59 ) ;
V_152 = F_100 ( & V_110 -> V_59 . V_105 ) ;
if ( V_152 ) {
F_117 ( V_110 , V_33 , 0 ) ;
if ( F_104 ( V_33 < 0 ) )
break;
V_110 -> V_78 = V_78 ;
}
if ( F_104 ( V_115 ) )
F_120 ( V_154 , V_155 / 100 ) ;
if ( F_104 ( ! V_152 && V_153 ) ) {
V_151 = F_97 ( V_110 -> V_112 , V_110 -> V_131 ,
V_78 ) ;
F_98 ( V_151 ) ;
F_62 ( V_3 , & V_151 -> V_59 , NULL ,
V_110 -> V_131 , V_78 ) ;
V_151 -> V_59 . V_81 = V_110 -> V_59 . V_81 ;
V_151 -> V_59 . V_79 = V_110 -> V_59 . V_79 ;
if ( ! V_110 -> V_132 )
V_151 -> V_132 = V_110 ;
else {
V_151 -> V_132 = V_110 -> V_132 ;
F_98 ( V_110 -> V_132 ) ;
F_99 ( V_110 ) ;
}
V_110 = V_151 ;
}
}
F_99 ( V_110 ) ;
}
static void F_121 ( struct V_109 * V_110 , int error )
{
if ( F_104 ( error < 0 ) )
V_110 -> error = - V_135 ;
F_99 ( V_110 ) ;
}
static void F_122 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
int V_33 = 0 ;
F_98 ( V_110 ) ;
F_62 ( V_3 , & V_110 -> V_59 , V_110 -> V_131 , V_110 -> V_131 ,
V_110 -> V_78 ) ;
V_33 = F_80 ( V_3 , & V_110 -> V_59 ) ;
if ( F_100 ( & V_110 -> V_59 . V_105 ) )
F_121 ( V_110 , V_33 ) ;
F_99 ( V_110 ) ;
}
static void V_104 ( struct V_156 * V_157 ,
int error )
{
struct V_8 * V_9 = V_157 -> V_57 ;
struct V_75 * V_59 = V_9 -> V_59 ;
struct V_109 * V_110 = F_113 ( V_59 , struct V_109 , V_59 ) ;
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
if ( error == - V_108 ) {
F_123 ( & V_59 -> V_85 ) ;
return;
}
if ( ! error && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
error = V_3 -> V_96 -> V_98 ( V_3 , F_66 ( V_3 , V_9 ) , V_9 ) ;
F_93 ( F_65 ( V_3 , V_9 ) , V_3 -> V_101 ) ;
if ( ! F_100 ( & V_59 -> V_105 ) )
return;
if ( F_56 ( V_110 -> V_131 ) == V_136 )
F_121 ( V_110 , error ) ;
else
F_117 ( V_110 , error , 1 ) ;
}
static void F_124 ( struct V_147 * V_148 )
{
struct V_109 * V_110 = F_113 ( V_148 , struct V_109 , V_148 ) ;
if ( F_56 ( V_110 -> V_131 ) == V_136 )
F_122 ( V_110 ) ;
else
F_118 ( V_110 ) ;
}
static void F_106 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_112 -> V_113 ;
F_115 ( & V_110 -> V_148 , F_124 ) ;
F_116 ( V_3 -> V_158 , & V_110 -> V_148 ) ;
}
static int F_125 ( T_1 * V_24 , char * V_159 , unsigned int V_114 )
{
char V_160 [ 3 ] ;
char * V_161 ;
unsigned int V_64 ;
V_160 [ 2 ] = '\0' ;
for ( V_64 = 0 ; V_64 < V_114 ; V_64 ++ ) {
V_160 [ 0 ] = * V_159 ++ ;
V_160 [ 1 ] = * V_159 ++ ;
V_24 [ V_64 ] = ( T_1 ) F_126 ( V_160 , & V_161 , 16 ) ;
if ( V_161 != & V_160 [ 2 ] )
return - V_39 ;
}
if ( * V_159 != '\0' )
return - V_39 ;
return 0 ;
}
static void F_127 ( char * V_159 , T_1 * V_24 , unsigned int V_114 )
{
unsigned int V_64 ;
for ( V_64 = 0 ; V_64 < V_114 ; V_64 ++ ) {
sprintf ( V_159 , L_13 , * V_24 ) ;
V_159 += 2 ;
V_24 ++ ;
}
}
static void F_128 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_40 = F_13 ( V_3 -> V_4 , V_4 ) ;
unsigned V_64 ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ )
if ( V_40 -> V_6 [ V_64 ] && ! F_19 ( V_40 -> V_6 [ V_64 ] ) ) {
F_129 ( V_40 -> V_6 [ V_64 ] ) ;
V_40 -> V_6 [ V_64 ] = NULL ;
}
}
static int F_130 ( struct V_2 * V_3 , int V_4 , char * V_162 )
{
struct V_1 * V_40 = F_13 ( V_3 -> V_4 , V_4 ) ;
unsigned V_64 ;
int V_23 ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_40 -> V_6 [ V_64 ] = F_131 ( V_162 , 0 , 0 ) ;
if ( F_19 ( V_40 -> V_6 [ V_64 ] ) ) {
V_23 = F_29 ( V_40 -> V_6 [ V_64 ] ) ;
F_128 ( V_3 , V_4 ) ;
return V_23 ;
}
}
return 0 ;
}
static int F_132 ( struct V_2 * V_3 )
{
unsigned V_56 = V_3 -> V_25 >> F_36 ( V_3 -> V_54 ) ;
int V_4 , V_23 = 0 , V_64 , V_33 ;
F_12 (cpu) {
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_33 = F_133 ( F_13 ( V_3 -> V_4 , V_4 ) -> V_6 [ V_64 ] ,
V_3 -> V_24 + ( V_64 * V_56 ) , V_56 ) ;
if ( V_33 )
V_23 = V_33 ;
}
}
return V_23 ;
}
static int F_134 ( struct V_2 * V_3 , char * V_24 )
{
int V_33 = - V_39 ;
int V_163 = strlen ( V_24 ) ;
if ( V_3 -> V_25 != ( V_163 >> 1 ) )
goto V_164;
if ( ! V_3 -> V_25 && strcmp ( V_24 , L_14 ) )
goto V_164;
if ( V_3 -> V_25 && F_125 ( V_3 -> V_24 , V_24 , V_3 -> V_25 ) < 0 )
goto V_164;
F_135 ( V_165 , & V_3 -> V_28 ) ;
V_33 = F_132 ( V_3 ) ;
V_164:
memset ( V_24 , '0' , V_163 ) ;
return V_33 ;
}
static int F_136 ( struct V_2 * V_3 )
{
F_137 ( V_165 , & V_3 -> V_28 ) ;
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
if ( V_3 -> V_149 )
F_139 ( V_3 -> V_149 ) ;
if ( V_3 -> V_158 )
F_139 ( V_3 -> V_158 ) ;
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
if ( V_3 -> V_130 )
F_141 ( V_3 -> V_130 ) ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_166 )
V_3 -> V_96 -> V_166 ( V_3 ) ;
if ( V_3 -> V_139 )
F_142 ( V_35 , V_3 -> V_139 ) ;
if ( V_3 -> V_4 )
F_143 ( V_3 -> V_4 ) ;
F_26 ( V_3 -> V_37 ) ;
F_26 ( V_3 -> V_167 ) ;
F_26 ( V_3 ) ;
}
static int F_144 ( struct V_34 * V_35 ,
char * V_168 , char * V_24 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
char * V_169 , * V_37 , * V_170 , * V_171 , * V_172 , * V_173 ;
char * V_174 = NULL ;
int V_4 , V_175 = - V_39 ;
if ( strchr ( V_168 , '(' ) ) {
V_35 -> error = L_15 ;
return - V_39 ;
}
V_3 -> V_167 = F_145 ( V_168 , V_44 ) ;
if ( ! V_3 -> V_167 )
goto V_176;
V_169 = V_168 ;
V_173 = F_146 ( & V_169 , L_14 ) ;
V_37 = F_146 ( & V_173 , L_16 ) ;
if ( ! V_173 )
V_3 -> V_54 = 1 ;
else if ( sscanf ( V_173 , L_17 , & V_3 -> V_54 ) != 1 ||
! F_147 ( V_3 -> V_54 ) ) {
V_35 -> error = L_18 ;
return - V_39 ;
}
V_3 -> V_53 = V_3 -> V_54 ;
V_3 -> V_37 = F_145 ( V_37 , V_44 ) ;
if ( ! V_3 -> V_37 )
goto V_176;
V_170 = F_146 ( & V_169 , L_14 ) ;
V_172 = F_146 ( & V_169 , L_14 ) ;
V_171 = F_146 ( & V_172 , L_16 ) ;
if ( V_169 )
F_148 ( L_19 ) ;
V_3 -> V_4 = F_149 ( sizeof( * ( V_3 -> V_4 ) ) +
V_3 -> V_54 * sizeof( * ( V_3 -> V_4 -> V_6 ) ) ,
F_150 ( struct V_1 ) ) ;
if ( ! V_3 -> V_4 ) {
V_35 -> error = L_20 ;
goto V_176;
}
if ( ! V_170 || ( ! strcmp ( V_170 , L_21 ) && ! V_171 ) ) {
V_170 = L_22 ;
V_171 = L_21 ;
}
if ( strcmp ( V_170 , L_23 ) && ! V_171 ) {
V_35 -> error = L_24 ;
return - V_39 ;
}
V_174 = F_151 ( V_177 , V_44 ) ;
if ( ! V_174 )
goto V_176;
V_175 = snprintf ( V_174 , V_177 ,
L_25 , V_170 , V_37 ) ;
if ( V_175 < 0 ) {
F_31 ( V_174 ) ;
goto V_176;
}
F_12 (cpu) {
V_175 = F_130 ( V_3 , V_4 , V_174 ) ;
if ( V_175 < 0 ) {
V_35 -> error = L_26 ;
goto V_43;
}
}
V_175 = F_134 ( V_3 , V_24 ) ;
if ( V_175 < 0 ) {
V_35 -> error = L_27 ;
goto V_43;
}
V_3 -> V_10 = F_21 ( F_3 ( V_3 ) ) ;
if ( V_3 -> V_10 )
V_3 -> V_10 = F_152 ( V_3 -> V_10 ,
( unsigned int ) ( sizeof( V_13 ) / sizeof( T_1 ) ) ) ;
else if ( V_171 ) {
F_148 ( L_28 ) ;
V_171 = NULL ;
}
if ( V_171 == NULL )
V_3 -> V_96 = NULL ;
else if ( strcmp ( V_171 , L_21 ) == 0 )
V_3 -> V_96 = & V_178 ;
else if ( strcmp ( V_171 , L_29 ) == 0 )
V_3 -> V_96 = & V_179 ;
else if ( strcmp ( V_171 , L_30 ) == 0 )
V_3 -> V_96 = & V_180 ;
else if ( strcmp ( V_171 , L_31 ) == 0 )
V_3 -> V_96 = & V_181 ;
else if ( strcmp ( V_171 , L_32 ) == 0 )
V_3 -> V_96 = & V_182 ;
else if ( strcmp ( V_171 , L_33 ) == 0 ) {
V_3 -> V_96 = & V_183 ;
if ( V_3 -> V_25 % V_3 -> V_53 )
V_3 -> V_53 ++ ;
} else {
V_175 = - V_39 ;
V_35 -> error = L_34 ;
goto V_43;
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_184 ) {
V_175 = V_3 -> V_96 -> V_184 ( V_3 , V_35 , V_172 ) ;
if ( V_175 < 0 ) {
V_35 -> error = L_35 ;
goto V_43;
}
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_185 ) {
V_175 = V_3 -> V_96 -> V_185 ( V_3 ) ;
if ( V_175 < 0 ) {
V_35 -> error = L_36 ;
goto V_43;
}
}
V_175 = 0 ;
V_43:
F_31 ( V_174 ) ;
return V_175 ;
V_176:
V_35 -> error = L_37 ;
return - V_45 ;
}
static int F_153 ( struct V_34 * V_35 , unsigned int V_186 , char * * V_187 )
{
struct V_2 * V_3 ;
unsigned int V_25 ;
unsigned long long V_188 ;
int V_175 ;
if ( V_186 != 5 ) {
V_35 -> error = L_38 ;
return - V_39 ;
}
V_25 = strlen ( V_187 [ 1 ] ) >> 1 ;
V_3 = F_30 ( sizeof( * V_3 ) + V_25 * sizeof( T_1 ) , V_44 ) ;
if ( ! V_3 ) {
V_35 -> error = L_39 ;
return - V_45 ;
}
V_3 -> V_25 = V_25 ;
V_35 -> V_113 = V_3 ;
V_175 = F_144 ( V_35 , V_187 [ 0 ] , V_187 [ 1 ] ) ;
if ( V_175 < 0 )
goto V_43;
V_175 = - V_45 ;
V_3 -> V_130 = F_154 ( V_189 , V_190 ) ;
if ( ! V_3 -> V_130 ) {
V_35 -> error = L_40 ;
goto V_43;
}
V_3 -> V_88 = sizeof( struct V_86 ) ;
V_3 -> V_88 += F_155 ( F_3 ( V_3 ) ) ;
V_3 -> V_88 = F_67 ( V_3 -> V_88 , F_156 () ) ;
V_3 -> V_88 += F_68 ( F_3 ( V_3 ) ) &
~ ( F_156 () - 1 ) ;
V_3 -> V_101 = F_157 ( V_189 , V_3 -> V_88 +
sizeof( struct V_8 ) + V_3 -> V_10 ) ;
if ( ! V_3 -> V_101 ) {
V_35 -> error = L_41 ;
goto V_43;
}
V_3 -> V_124 = F_158 ( V_191 , 0 ) ;
if ( ! V_3 -> V_124 ) {
V_35 -> error = L_42 ;
goto V_43;
}
V_3 -> V_46 = F_159 ( V_189 , 0 ) ;
if ( ! V_3 -> V_46 ) {
V_35 -> error = L_43 ;
goto V_43;
}
V_175 = - V_39 ;
if ( sscanf ( V_187 [ 2 ] , L_44 , & V_188 ) != 1 ) {
V_35 -> error = L_45 ;
goto V_43;
}
V_3 -> V_84 = V_188 ;
if ( F_160 ( V_35 , V_187 [ 3 ] , F_161 ( V_35 -> V_192 ) , & V_3 -> V_139 ) ) {
V_35 -> error = L_46 ;
goto V_43;
}
if ( sscanf ( V_187 [ 4 ] , L_44 , & V_188 ) != 1 ) {
V_35 -> error = L_47 ;
goto V_43;
}
V_3 -> V_145 = V_188 ;
V_175 = - V_45 ;
V_3 -> V_149 = F_162 ( L_48 ,
V_193 |
V_194 ,
1 ) ;
if ( ! V_3 -> V_149 ) {
V_35 -> error = L_49 ;
goto V_43;
}
V_3 -> V_158 = F_162 ( L_50 ,
V_193 |
V_195 |
V_194 ,
1 ) ;
if ( ! V_3 -> V_158 ) {
V_35 -> error = L_51 ;
goto V_43;
}
V_35 -> V_196 = 1 ;
return 0 ;
V_43:
F_138 ( V_35 ) ;
return V_175 ;
}
static int F_163 ( struct V_34 * V_35 , struct V_76 * V_76 ,
union V_197 * V_198 )
{
struct V_109 * V_110 ;
struct V_2 * V_3 ;
if ( V_76 -> V_141 & V_199 ) {
V_3 = V_35 -> V_113 ;
V_76 -> V_138 = V_3 -> V_139 -> V_140 ;
return V_200 ;
}
V_110 = F_97 ( V_35 , V_76 , F_164 ( V_35 , V_76 -> V_144 ) ) ;
if ( F_56 ( V_110 -> V_131 ) == V_136 ) {
if ( F_107 ( V_110 , V_201 ) )
F_114 ( V_110 ) ;
} else
F_106 ( V_110 ) ;
return V_202 ;
}
static int F_165 ( struct V_34 * V_35 , T_5 type ,
char * V_203 , unsigned int V_204 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
unsigned int V_205 = 0 ;
switch ( type ) {
case V_206 :
V_203 [ 0 ] = '\0' ;
break;
case V_207 :
F_166 ( L_52 , V_3 -> V_167 ) ;
if ( V_3 -> V_25 > 0 ) {
if ( ( V_204 - V_205 ) < ( ( V_3 -> V_25 << 1 ) + 1 ) )
return - V_45 ;
F_127 ( V_203 + V_205 , V_3 -> V_24 , V_3 -> V_25 ) ;
V_205 += V_3 -> V_25 << 1 ;
} else {
if ( V_205 >= V_204 )
return - V_45 ;
V_203 [ V_205 ++ ] = '-' ;
}
F_166 ( L_53 , ( unsigned long long ) V_3 -> V_84 ,
V_3 -> V_139 -> V_208 , ( unsigned long long ) V_3 -> V_145 ) ;
break;
}
return 0 ;
}
static void F_167 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
F_135 ( V_209 , & V_3 -> V_28 ) ;
}
static int F_168 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
if ( ! F_169 ( V_165 , & V_3 -> V_28 ) ) {
F_170 ( L_54 ) ;
return - V_210 ;
}
return 0 ;
}
static void F_171 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
F_137 ( V_209 , & V_3 -> V_28 ) ;
}
static int F_172 ( struct V_34 * V_35 , unsigned V_186 , char * * V_187 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
int V_175 = - V_39 ;
if ( V_186 < 2 )
goto error;
if ( ! F_173 ( V_187 [ 0 ] , F_174 ( L_55 ) ) ) {
if ( ! F_169 ( V_209 , & V_3 -> V_28 ) ) {
F_148 ( L_56 ) ;
return - V_39 ;
}
if ( V_186 == 3 && ! F_173 ( V_187 [ 1 ] , F_174 ( L_57 ) ) ) {
V_175 = F_134 ( V_3 , V_187 [ 2 ] ) ;
if ( V_175 )
return V_175 ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_185 )
V_175 = V_3 -> V_96 -> V_185 ( V_3 ) ;
return V_175 ;
}
if ( V_186 == 2 && ! F_173 ( V_187 [ 1 ] , F_174 ( L_58 ) ) ) {
if ( V_3 -> V_96 && V_3 -> V_96 -> V_211 ) {
V_175 = V_3 -> V_96 -> V_211 ( V_3 ) ;
if ( V_175 )
return V_175 ;
}
return F_136 ( V_3 ) ;
}
}
error:
F_148 ( L_59 ) ;
return - V_39 ;
}
static int F_175 ( struct V_34 * V_35 , struct V_212 * V_213 ,
struct V_89 * V_214 , int V_215 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
struct V_216 * V_217 = F_176 ( V_3 -> V_139 -> V_140 ) ;
if ( ! V_217 -> V_218 )
return V_215 ;
V_213 -> V_138 = V_3 -> V_139 -> V_140 ;
V_213 -> V_144 = V_3 -> V_145 + F_164 ( V_35 , V_213 -> V_144 ) ;
return F_177 ( V_215 , V_217 -> V_218 ( V_217 , V_213 , V_214 ) ) ;
}
static int F_178 ( struct V_34 * V_35 ,
T_6 V_219 , void * V_57 )
{
struct V_2 * V_3 = V_35 -> V_113 ;
return V_219 ( V_35 , V_3 -> V_139 , V_3 -> V_145 , V_35 -> V_122 , V_57 ) ;
}
static int T_7 F_179 ( void )
{
int V_33 ;
V_190 = F_180 ( V_109 , 0 ) ;
if ( ! V_190 )
return - V_45 ;
V_33 = F_181 ( & V_220 ) ;
if ( V_33 < 0 ) {
F_170 ( L_60 , V_33 ) ;
F_182 ( V_190 ) ;
}
return V_33 ;
}
static void T_8 F_183 ( void )
{
F_184 ( & V_220 ) ;
F_182 ( V_190 ) ;
}
