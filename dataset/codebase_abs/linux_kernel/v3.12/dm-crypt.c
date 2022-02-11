static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static struct V_5 * F_3 ( struct V_2 * V_3 )
{
return V_3 -> V_6 [ 0 ] ;
}
static int F_4 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
memset ( V_7 , 0 , V_3 -> V_10 ) ;
* ( V_11 * ) V_7 = F_5 ( V_9 -> V_12 & 0xffffffff ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
memset ( V_7 , 0 , V_3 -> V_10 ) ;
* ( V_13 * ) V_7 = F_7 ( V_9 -> V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = & V_3 -> V_16 . V_15 ;
struct V_17 V_18 ;
struct V_19 V_20 ;
struct V_21 * V_22 ;
int V_23 ;
F_9 ( & V_20 , V_3 -> V_24 , V_3 -> V_25 ) ;
V_18 . V_26 = V_15 -> V_27 ;
V_18 . V_28 = V_29 ;
V_23 = F_10 ( & V_18 , & V_20 , V_3 -> V_25 , V_15 -> V_30 ) ;
if ( V_23 )
return V_23 ;
V_22 = V_3 -> V_31 ;
V_23 = F_11 ( V_22 , V_15 -> V_30 ,
F_12 ( V_15 -> V_27 ) ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = & V_3 -> V_16 . V_15 ;
unsigned V_32 = F_12 ( V_15 -> V_27 ) ;
struct V_21 * V_22 ;
int V_33 , V_23 = 0 ;
memset ( V_15 -> V_30 , 0 , V_32 ) ;
V_22 = V_3 -> V_31 ;
V_33 = F_11 ( V_22 , V_15 -> V_30 , V_32 ) ;
if ( V_33 )
V_23 = V_33 ;
return V_23 ;
}
static struct V_21 * F_14 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
T_1 * V_30 , unsigned V_36 )
{
struct V_21 * V_22 ;
int V_23 ;
V_22 = F_15 ( V_3 -> V_37 , 0 , V_38 ) ;
if ( F_16 ( V_22 ) ) {
V_35 -> error = L_1 ;
return V_22 ;
}
if ( F_17 ( V_22 ) !=
F_18 ( F_3 ( V_3 ) ) ) {
V_35 -> error = L_2
L_3 ;
F_19 ( V_22 ) ;
return F_20 ( - V_39 ) ;
}
V_23 = F_11 ( V_22 , V_30 , V_36 ) ;
if ( V_23 ) {
V_35 -> error = L_4 ;
F_19 ( V_22 ) ;
return F_20 ( V_23 ) ;
}
return V_22 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
struct V_14 * V_15 = & V_3 -> V_16 . V_15 ;
F_22 ( V_15 -> V_27 ) ;
V_15 -> V_27 = NULL ;
F_23 ( V_15 -> V_30 ) ;
V_15 -> V_30 = NULL ;
V_22 = V_3 -> V_31 ;
if ( V_22 )
F_19 ( V_22 ) ;
V_3 -> V_31 = NULL ;
}
static int F_24 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
struct V_21 * V_22 = NULL ;
struct V_41 * V_27 = NULL ;
T_1 * V_30 = NULL ;
int V_23 ;
if ( ! V_40 ) {
V_35 -> error = L_5 ;
return - V_39 ;
}
V_27 = F_25 ( V_40 , 0 , V_38 ) ;
if ( F_16 ( V_27 ) ) {
V_35 -> error = L_6 ;
V_23 = F_26 ( V_27 ) ;
goto V_42;
}
V_30 = F_27 ( F_12 ( V_27 ) , V_43 ) ;
if ( ! V_30 ) {
V_35 -> error = L_7 ;
V_23 = - V_44 ;
goto V_42;
}
V_3 -> V_16 . V_15 . V_30 = V_30 ;
V_3 -> V_16 . V_15 . V_27 = V_27 ;
V_22 = F_14 ( V_3 , V_35 , V_30 ,
F_12 ( V_27 ) ) ;
if ( F_16 ( V_22 ) ) {
F_21 ( V_3 ) ;
return F_26 ( V_22 ) ;
}
V_3 -> V_31 = V_22 ;
return 0 ;
V_42:
if ( V_27 && ! F_16 ( V_27 ) )
F_22 ( V_27 ) ;
F_28 ( V_30 ) ;
return V_23 ;
}
static int F_29 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
struct V_21 * V_22 = V_3 -> V_31 ;
memset ( V_7 , 0 , V_3 -> V_10 ) ;
* ( V_13 * ) V_7 = F_7 ( V_9 -> V_12 ) ;
F_30 ( V_22 , V_7 , V_7 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
unsigned V_45 = F_32 ( F_3 ( V_3 ) ) ;
int log = F_33 ( V_45 ) ;
if ( 1 << log != V_45 ) {
V_35 -> error = L_8 ;
return - V_39 ;
}
if ( log > 9 ) {
V_35 -> error = L_9 ;
return - V_39 ;
}
V_3 -> V_16 . V_46 . V_47 = 9 - log ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 )
{
}
static int F_35 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_2 V_48 ;
memset ( V_7 , 0 , V_3 -> V_10 - sizeof( V_49 ) ) ;
V_48 = F_36 ( ( ( V_49 ) V_9 -> V_12 << V_3 -> V_16 . V_46 . V_47 ) + 1 ) ;
F_37 ( V_48 , ( T_2 * ) ( V_7 + V_3 -> V_10 - sizeof( V_49 ) ) ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
memset ( V_7 , 0 , V_3 -> V_10 ) ;
return 0 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
if ( V_51 -> V_27 && ! F_16 ( V_51 -> V_27 ) )
F_40 ( V_51 -> V_27 ) ;
V_51 -> V_27 = NULL ;
F_23 ( V_51 -> V_52 ) ;
V_51 -> V_52 = NULL ;
}
static int F_41 ( struct V_2 * V_3 , struct V_34 * V_35 ,
const char * V_40 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
V_51 -> V_27 = F_42 ( L_10 , 0 , 0 ) ;
if ( F_16 ( V_51 -> V_27 ) ) {
V_35 -> error = L_11 ;
return F_26 ( V_51 -> V_27 ) ;
}
if ( V_3 -> V_53 == V_3 -> V_54 ) {
V_51 -> V_52 = NULL ;
return 0 ;
}
V_51 -> V_52 = F_27 ( V_55 , V_43 ) ;
if ( ! V_51 -> V_52 ) {
F_39 ( V_3 ) ;
V_35 -> error = L_12 ;
return - V_44 ;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
int V_56 = V_3 -> V_25 / V_3 -> V_53 ;
if ( V_51 -> V_52 )
memcpy ( V_51 -> V_52 , V_3 -> V_24 + ( V_3 -> V_54 * V_56 ) ,
F_44 ( V_51 -> V_27 ) ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
if ( V_51 -> V_52 )
memset ( V_51 -> V_52 , 0 , V_55 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_57 )
{
struct V_50 * V_51 = & V_3 -> V_16 . V_51 ;
struct {
struct V_58 V_18 ;
char V_59 [ F_47 ( V_51 -> V_27 ) ] ;
} V_60 ;
struct V_61 V_62 ;
T_3 V_63 [ 4 ] ;
int V_64 , V_33 ;
V_60 . V_18 . V_26 = V_51 -> V_27 ;
V_60 . V_18 . V_28 = V_29 ;
V_33 = F_48 ( & V_60 . V_18 ) ;
if ( V_33 )
return V_33 ;
if ( V_51 -> V_52 ) {
V_33 = F_49 ( & V_60 . V_18 , V_51 -> V_52 , V_55 ) ;
if ( V_33 )
return V_33 ;
}
V_33 = F_49 ( & V_60 . V_18 , V_57 + 16 , 16 * 31 ) ;
if ( V_33 )
return V_33 ;
V_63 [ 0 ] = F_5 ( V_9 -> V_12 & 0xFFFFFFFF ) ;
V_63 [ 1 ] = F_5 ( ( ( ( V_49 ) V_9 -> V_12 >> 32 ) & 0x00FFFFFF ) | 0x80000000 ) ;
V_63 [ 2 ] = F_5 ( 4024 ) ;
V_63 [ 3 ] = 0 ;
V_33 = F_49 ( & V_60 . V_18 , ( T_1 * ) V_63 , sizeof( V_63 ) ) ;
if ( V_33 )
return V_33 ;
V_33 = F_50 ( & V_60 . V_18 , & V_62 ) ;
if ( V_33 )
return V_33 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ )
F_51 ( & V_62 . V_66 [ V_64 ] ) ;
memcpy ( V_7 , & V_62 . V_66 , V_3 -> V_10 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_67 ;
int V_33 = 0 ;
if ( F_53 ( V_9 -> V_59 -> V_68 ) == V_69 ) {
V_67 = F_54 ( F_55 ( & V_9 -> V_70 ) ) ;
V_33 = F_46 ( V_3 , V_7 , V_9 , V_67 + V_9 -> V_70 . V_71 ) ;
F_56 ( V_67 ) ;
} else
memset ( V_7 , 0 , V_3 -> V_10 ) ;
return V_33 ;
}
static int F_57 ( struct V_2 * V_3 , T_1 * V_7 ,
struct V_8 * V_9 )
{
T_1 * V_72 ;
int V_33 ;
if ( F_53 ( V_9 -> V_59 -> V_68 ) == V_69 )
return 0 ;
V_72 = F_54 ( F_55 ( & V_9 -> V_73 ) ) ;
V_33 = F_46 ( V_3 , V_7 , V_9 , V_72 + V_9 -> V_73 . V_71 ) ;
if ( ! V_33 )
F_58 ( V_72 + V_9 -> V_73 . V_71 , V_7 , V_3 -> V_10 ) ;
F_56 ( V_72 ) ;
return V_33 ;
}
static void F_59 ( struct V_2 * V_3 ,
struct V_74 * V_59 ,
struct V_75 * V_76 , struct V_75 * V_68 ,
T_4 V_77 )
{
V_59 -> V_68 = V_68 ;
V_59 -> V_76 = V_76 ;
V_59 -> V_78 = 0 ;
V_59 -> V_79 = 0 ;
V_59 -> V_80 = V_68 ? V_68 -> V_81 : 0 ;
V_59 -> V_82 = V_76 ? V_76 -> V_81 : 0 ;
V_59 -> V_83 = V_77 + V_3 -> V_84 ;
F_60 ( & V_59 -> V_85 ) ;
}
static struct V_8 * F_61 ( struct V_2 * V_3 ,
struct V_86 * V_87 )
{
return (struct V_8 * ) ( ( char * ) V_87 + V_3 -> V_88 ) ;
}
static struct V_86 * F_62 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return (struct V_86 * ) ( ( char * ) V_9 - V_3 -> V_88 ) ;
}
static T_1 * F_63 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return ( T_1 * ) F_64 ( ( unsigned long ) ( V_9 + 1 ) ,
F_65 ( F_3 ( V_3 ) ) + 1 ) ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_74 * V_59 ,
struct V_86 * V_87 )
{
struct V_89 * V_90 = F_67 ( V_59 -> V_68 , V_59 -> V_80 ) ;
struct V_89 * V_91 = F_67 ( V_59 -> V_76 , V_59 -> V_82 ) ;
struct V_8 * V_9 ;
T_1 * V_7 ;
int V_33 ;
V_9 = F_61 ( V_3 , V_87 ) ;
V_7 = F_63 ( V_3 , V_9 ) ;
V_9 -> V_12 = V_59 -> V_83 ;
V_9 -> V_59 = V_59 ;
F_68 ( & V_9 -> V_70 , 1 ) ;
F_69 ( & V_9 -> V_70 , V_90 -> V_92 , 1 << V_93 ,
V_90 -> V_94 + V_59 -> V_78 ) ;
F_68 ( & V_9 -> V_73 , 1 ) ;
F_69 ( & V_9 -> V_73 , V_91 -> V_92 , 1 << V_93 ,
V_91 -> V_94 + V_59 -> V_79 ) ;
V_59 -> V_78 += 1 << V_93 ;
if ( V_59 -> V_78 >= V_90 -> V_95 ) {
V_59 -> V_78 = 0 ;
V_59 -> V_80 ++ ;
}
V_59 -> V_79 += 1 << V_93 ;
if ( V_59 -> V_79 >= V_91 -> V_95 ) {
V_59 -> V_79 = 0 ;
V_59 -> V_82 ++ ;
}
if ( V_3 -> V_96 ) {
V_33 = V_3 -> V_96 -> V_97 ( V_3 , V_7 , V_9 ) ;
if ( V_33 < 0 )
return V_33 ;
}
F_70 ( V_87 , & V_9 -> V_70 , & V_9 -> V_73 ,
1 << V_93 , V_7 ) ;
if ( F_53 ( V_59 -> V_68 ) == V_69 )
V_33 = F_71 ( V_87 ) ;
else
V_33 = F_72 ( V_87 ) ;
if ( ! V_33 && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
V_33 = V_3 -> V_96 -> V_98 ( V_3 , V_7 , V_9 ) ;
return V_33 ;
}
static void F_73 ( struct V_2 * V_3 ,
struct V_74 * V_59 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
unsigned V_100 = V_59 -> V_83 & ( V_3 -> V_54 - 1 ) ;
if ( ! V_99 -> V_87 )
V_99 -> V_87 = F_74 ( V_3 -> V_101 , V_102 ) ;
F_75 ( V_99 -> V_87 , V_3 -> V_6 [ V_100 ] ) ;
F_76 ( V_99 -> V_87 ,
V_103 | V_29 ,
V_104 , F_61 ( V_3 , V_99 -> V_87 ) ) ;
}
static int F_77 ( struct V_2 * V_3 ,
struct V_74 * V_59 )
{
struct V_1 * V_99 = F_1 ( V_3 ) ;
int V_33 ;
F_78 ( & V_59 -> V_105 , 1 ) ;
while( V_59 -> V_80 < V_59 -> V_68 -> V_106 &&
V_59 -> V_82 < V_59 -> V_76 -> V_106 ) {
F_73 ( V_3 , V_59 ) ;
F_79 ( & V_59 -> V_105 ) ;
V_33 = F_66 ( V_3 , V_59 , V_99 -> V_87 ) ;
switch ( V_33 ) {
case - V_107 :
F_80 ( & V_59 -> V_85 ) ;
F_81 ( V_59 -> V_85 ) ;
case - V_108 :
V_99 -> V_87 = NULL ;
V_59 -> V_83 ++ ;
continue;
case 0 :
F_82 ( & V_59 -> V_105 ) ;
V_59 -> V_83 ++ ;
F_83 () ;
continue;
default:
F_82 ( & V_59 -> V_105 ) ;
return V_33 ;
}
}
return 0 ;
}
static struct V_75 * F_84 ( struct V_109 * V_110 , unsigned V_111 ,
unsigned * V_112 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
struct V_75 * V_113 ;
unsigned int V_114 = ( V_111 + V_115 - 1 ) >> V_116 ;
T_5 V_117 = V_102 | V_118 ;
unsigned V_64 , V_119 ;
struct V_120 * V_120 ;
V_113 = F_85 ( V_102 , V_114 , V_3 -> V_45 ) ;
if ( ! V_113 )
return NULL ;
F_86 ( V_110 , V_113 ) ;
* V_112 = 0 ;
for ( V_64 = 0 ; V_64 < V_114 ; V_64 ++ ) {
V_120 = F_74 ( V_3 -> V_121 , V_117 ) ;
if ( ! V_120 ) {
* V_112 = 1 ;
break;
}
V_117 = ( V_117 | V_122 ) & ~ V_123 ;
V_119 = ( V_111 > V_115 ) ? V_115 : V_111 ;
if ( ! F_87 ( V_113 , V_120 , V_119 , 0 ) ) {
F_88 ( V_120 , V_3 -> V_121 ) ;
break;
}
V_111 -= V_119 ;
}
if ( ! V_113 -> V_124 ) {
F_89 ( V_113 ) ;
return NULL ;
}
return V_113 ;
}
static void F_90 ( struct V_2 * V_3 , struct V_75 * V_113 )
{
unsigned int V_64 ;
struct V_89 * V_125 ;
F_91 (bv, clone, i) {
F_92 ( ! V_125 -> V_92 ) ;
F_88 ( V_125 -> V_92 , V_3 -> V_121 ) ;
V_125 -> V_92 = NULL ;
}
}
static struct V_109 * F_93 ( struct V_2 * V_3 ,
struct V_75 * V_75 , T_4 V_77 )
{
struct V_109 * V_110 ;
V_110 = F_74 ( V_3 -> V_126 , V_102 ) ;
V_110 -> V_3 = V_3 ;
V_110 -> V_127 = V_75 ;
V_110 -> V_77 = V_77 ;
V_110 -> error = 0 ;
V_110 -> V_128 = NULL ;
F_78 ( & V_110 -> V_129 , 0 ) ;
return V_110 ;
}
static void F_94 ( struct V_109 * V_110 )
{
F_79 ( & V_110 -> V_129 ) ;
}
static void F_95 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
struct V_75 * V_127 = V_110 -> V_127 ;
struct V_109 * V_128 = V_110 -> V_128 ;
int error = V_110 -> error ;
if ( ! F_96 ( & V_110 -> V_129 ) )
return;
F_88 ( V_110 , V_3 -> V_126 ) ;
if ( F_97 ( ! V_128 ) )
F_98 ( V_127 , error ) ;
else {
if ( error && ! V_128 -> error )
V_128 -> error = error ;
F_95 ( V_128 ) ;
}
}
static void F_99 ( struct V_75 * V_113 , int error )
{
struct V_109 * V_110 = V_113 -> V_130 ;
struct V_2 * V_3 = V_110 -> V_3 ;
unsigned V_131 = F_53 ( V_113 ) ;
if ( F_100 ( ! F_101 ( V_113 , V_132 ) && ! error ) )
error = - V_133 ;
if ( V_131 == V_69 )
F_90 ( V_3 , V_113 ) ;
F_89 ( V_113 ) ;
if ( V_131 == V_134 && ! error ) {
F_102 ( V_110 ) ;
return;
}
if ( F_100 ( error ) )
V_110 -> error = error ;
F_95 ( V_110 ) ;
}
static void F_86 ( struct V_109 * V_110 , struct V_75 * V_113 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
V_113 -> V_130 = V_110 ;
V_113 -> V_135 = F_99 ;
V_113 -> V_136 = V_3 -> V_137 -> V_138 ;
V_113 -> V_139 = V_110 -> V_127 -> V_139 ;
}
static int F_103 ( struct V_109 * V_110 , T_5 V_140 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
struct V_75 * V_127 = V_110 -> V_127 ;
struct V_75 * V_113 ;
V_113 = F_104 ( V_127 , V_140 , V_3 -> V_45 ) ;
if ( ! V_113 )
return 1 ;
F_94 ( V_110 ) ;
F_86 ( V_110 , V_113 ) ;
V_113 -> V_141 = V_3 -> V_142 + V_110 -> V_77 ;
F_105 ( V_113 ) ;
return 0 ;
}
static void F_106 ( struct V_109 * V_110 )
{
struct V_75 * V_113 = V_110 -> V_59 . V_76 ;
F_105 ( V_113 ) ;
}
static void F_107 ( struct V_143 * V_144 )
{
struct V_109 * V_110 = F_108 ( V_144 , struct V_109 , V_144 ) ;
if ( F_53 ( V_110 -> V_127 ) == V_134 ) {
F_94 ( V_110 ) ;
if ( F_103 ( V_110 , V_102 ) )
V_110 -> error = - V_44 ;
F_95 ( V_110 ) ;
} else
F_106 ( V_110 ) ;
}
static void F_109 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
F_110 ( & V_110 -> V_144 , F_107 ) ;
F_111 ( V_3 -> V_145 , & V_110 -> V_144 ) ;
}
static void F_112 ( struct V_109 * V_110 , int V_146 )
{
struct V_75 * V_113 = V_110 -> V_59 . V_76 ;
struct V_2 * V_3 = V_110 -> V_3 ;
if ( F_100 ( V_110 -> error < 0 ) ) {
F_90 ( V_3 , V_113 ) ;
F_89 ( V_113 ) ;
F_95 ( V_110 ) ;
return;
}
F_92 ( V_110 -> V_59 . V_82 < V_113 -> V_106 ) ;
V_113 -> V_141 = V_3 -> V_142 + V_110 -> V_77 ;
if ( V_146 )
F_109 ( V_110 ) ;
else
F_105 ( V_113 ) ;
}
static void F_113 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
struct V_75 * V_113 ;
struct V_109 * V_147 ;
int V_148 ;
unsigned V_112 = 0 ;
unsigned V_149 = V_110 -> V_127 -> V_124 ;
T_4 V_77 = V_110 -> V_77 ;
int V_33 ;
F_94 ( V_110 ) ;
F_59 ( V_3 , & V_110 -> V_59 , NULL , V_110 -> V_127 , V_77 ) ;
while ( V_149 ) {
V_113 = F_84 ( V_110 , V_149 , & V_112 ) ;
if ( F_100 ( ! V_113 ) ) {
V_110 -> error = - V_44 ;
break;
}
V_110 -> V_59 . V_76 = V_113 ;
V_110 -> V_59 . V_82 = 0 ;
V_149 -= V_113 -> V_124 ;
V_77 += F_114 ( V_113 ) ;
F_94 ( V_110 ) ;
V_33 = F_77 ( V_3 , & V_110 -> V_59 ) ;
if ( V_33 < 0 )
V_110 -> error = - V_133 ;
V_148 = F_96 ( & V_110 -> V_59 . V_105 ) ;
if ( V_148 ) {
F_112 ( V_110 , 0 ) ;
if ( F_100 ( V_33 < 0 ) )
break;
V_110 -> V_77 = V_77 ;
}
if ( F_100 ( V_112 ) )
F_115 ( V_150 , V_151 / 100 ) ;
if ( F_100 ( ! V_148 && V_149 ) ) {
V_147 = F_93 ( V_110 -> V_3 , V_110 -> V_127 ,
V_77 ) ;
F_94 ( V_147 ) ;
F_59 ( V_3 , & V_147 -> V_59 , NULL ,
V_110 -> V_127 , V_77 ) ;
V_147 -> V_59 . V_80 = V_110 -> V_59 . V_80 ;
V_147 -> V_59 . V_78 = V_110 -> V_59 . V_78 ;
if ( ! V_110 -> V_128 )
V_147 -> V_128 = V_110 ;
else {
V_147 -> V_128 = V_110 -> V_128 ;
F_94 ( V_110 -> V_128 ) ;
F_95 ( V_110 ) ;
}
V_110 = V_147 ;
}
}
F_95 ( V_110 ) ;
}
static void F_116 ( struct V_109 * V_110 )
{
F_95 ( V_110 ) ;
}
static void F_117 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
int V_33 = 0 ;
F_94 ( V_110 ) ;
F_59 ( V_3 , & V_110 -> V_59 , V_110 -> V_127 , V_110 -> V_127 ,
V_110 -> V_77 ) ;
V_33 = F_77 ( V_3 , & V_110 -> V_59 ) ;
if ( V_33 < 0 )
V_110 -> error = - V_133 ;
if ( F_96 ( & V_110 -> V_59 . V_105 ) )
F_116 ( V_110 ) ;
F_95 ( V_110 ) ;
}
static void V_104 ( struct V_152 * V_153 ,
int error )
{
struct V_8 * V_9 = V_153 -> V_57 ;
struct V_74 * V_59 = V_9 -> V_59 ;
struct V_109 * V_110 = F_108 ( V_59 , struct V_109 , V_59 ) ;
struct V_2 * V_3 = V_110 -> V_3 ;
if ( error == - V_108 ) {
F_118 ( & V_59 -> V_85 ) ;
return;
}
if ( ! error && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
error = V_3 -> V_96 -> V_98 ( V_3 , F_63 ( V_3 , V_9 ) , V_9 ) ;
if ( error < 0 )
V_110 -> error = - V_133 ;
F_88 ( F_62 ( V_3 , V_9 ) , V_3 -> V_101 ) ;
if ( ! F_96 ( & V_59 -> V_105 ) )
return;
if ( F_53 ( V_110 -> V_127 ) == V_134 )
F_116 ( V_110 ) ;
else
F_112 ( V_110 , 1 ) ;
}
static void F_119 ( struct V_143 * V_144 )
{
struct V_109 * V_110 = F_108 ( V_144 , struct V_109 , V_144 ) ;
if ( F_53 ( V_110 -> V_127 ) == V_134 )
F_117 ( V_110 ) ;
else
F_113 ( V_110 ) ;
}
static void F_102 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
F_110 ( & V_110 -> V_144 , F_119 ) ;
F_111 ( V_3 -> V_154 , & V_110 -> V_144 ) ;
}
static int F_120 ( T_1 * V_24 , char * V_155 , unsigned int V_111 )
{
char V_156 [ 3 ] ;
unsigned int V_64 ;
V_156 [ 2 ] = '\0' ;
for ( V_64 = 0 ; V_64 < V_111 ; V_64 ++ ) {
V_156 [ 0 ] = * V_155 ++ ;
V_156 [ 1 ] = * V_155 ++ ;
if ( F_121 ( V_156 , 16 , & V_24 [ V_64 ] ) )
return - V_39 ;
}
if ( * V_155 != '\0' )
return - V_39 ;
return 0 ;
}
static void F_122 ( struct V_2 * V_3 )
{
unsigned V_64 ;
if ( ! V_3 -> V_6 )
return;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ )
if ( V_3 -> V_6 [ V_64 ] && ! F_16 ( V_3 -> V_6 [ V_64 ] ) ) {
F_123 ( V_3 -> V_6 [ V_64 ] ) ;
V_3 -> V_6 [ V_64 ] = NULL ;
}
F_28 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
static int F_124 ( struct V_2 * V_3 , char * V_157 )
{
unsigned V_64 ;
int V_23 ;
V_3 -> V_6 = F_125 ( V_3 -> V_54 * sizeof( struct V_5 * ) ,
V_43 ) ;
if ( ! V_3 -> V_6 )
return - V_44 ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_3 -> V_6 [ V_64 ] = F_126 ( V_157 , 0 , 0 ) ;
if ( F_16 ( V_3 -> V_6 [ V_64 ] ) ) {
V_23 = F_26 ( V_3 -> V_6 [ V_64 ] ) ;
F_122 ( V_3 ) ;
return V_23 ;
}
}
return 0 ;
}
static int F_127 ( struct V_2 * V_3 )
{
unsigned V_56 = V_3 -> V_25 >> F_33 ( V_3 -> V_54 ) ;
int V_23 = 0 , V_64 , V_33 ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_33 = F_128 ( V_3 -> V_6 [ V_64 ] ,
V_3 -> V_24 + ( V_64 * V_56 ) ,
V_56 ) ;
if ( V_33 )
V_23 = V_33 ;
}
return V_23 ;
}
static int F_129 ( struct V_2 * V_3 , char * V_24 )
{
int V_33 = - V_39 ;
int V_158 = strlen ( V_24 ) ;
if ( V_3 -> V_25 != ( V_158 >> 1 ) )
goto V_159;
if ( ! V_3 -> V_25 && strcmp ( V_24 , L_13 ) )
goto V_159;
if ( V_3 -> V_25 && F_120 ( V_3 -> V_24 , V_24 , V_3 -> V_25 ) < 0 )
goto V_159;
F_130 ( V_160 , & V_3 -> V_28 ) ;
V_33 = F_127 ( V_3 ) ;
V_159:
memset ( V_24 , '0' , V_158 ) ;
return V_33 ;
}
static int F_131 ( struct V_2 * V_3 )
{
F_132 ( V_160 , & V_3 -> V_28 ) ;
memset ( & V_3 -> V_24 , 0 , V_3 -> V_25 * sizeof( T_1 ) ) ;
return F_127 ( V_3 ) ;
}
static void F_133 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_161 ;
struct V_1 * V_162 ;
int V_4 ;
V_35 -> V_161 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_145 )
F_134 ( V_3 -> V_145 ) ;
if ( V_3 -> V_154 )
F_134 ( V_3 -> V_154 ) ;
if ( V_3 -> V_4 )
F_135 (cpu) {
V_162 = F_136 ( V_3 -> V_4 , V_4 ) ;
if ( V_162 -> V_87 )
F_88 ( V_162 -> V_87 , V_3 -> V_101 ) ;
}
F_122 ( V_3 ) ;
if ( V_3 -> V_45 )
F_137 ( V_3 -> V_45 ) ;
if ( V_3 -> V_121 )
F_138 ( V_3 -> V_121 ) ;
if ( V_3 -> V_101 )
F_138 ( V_3 -> V_101 ) ;
if ( V_3 -> V_126 )
F_138 ( V_3 -> V_126 ) ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_163 )
V_3 -> V_96 -> V_163 ( V_3 ) ;
if ( V_3 -> V_137 )
F_139 ( V_35 , V_3 -> V_137 ) ;
if ( V_3 -> V_4 )
F_140 ( V_3 -> V_4 ) ;
F_23 ( V_3 -> V_37 ) ;
F_23 ( V_3 -> V_164 ) ;
F_23 ( V_3 ) ;
}
static int F_141 ( struct V_34 * V_35 ,
char * V_165 , char * V_24 )
{
struct V_2 * V_3 = V_35 -> V_161 ;
char * V_166 , * V_37 , * V_167 , * V_168 , * V_169 , * V_170 ;
char * V_171 = NULL ;
int V_172 = - V_39 ;
char V_173 ;
if ( strchr ( V_165 , '(' ) ) {
V_35 -> error = L_14 ;
return - V_39 ;
}
V_3 -> V_164 = F_142 ( V_165 , V_43 ) ;
if ( ! V_3 -> V_164 )
goto V_174;
V_166 = V_165 ;
V_170 = F_143 ( & V_166 , L_13 ) ;
V_37 = F_143 ( & V_170 , L_15 ) ;
if ( ! V_170 )
V_3 -> V_54 = 1 ;
else if ( sscanf ( V_170 , L_16 , & V_3 -> V_54 , & V_173 ) != 1 ||
! F_144 ( V_3 -> V_54 ) ) {
V_35 -> error = L_17 ;
return - V_39 ;
}
V_3 -> V_53 = V_3 -> V_54 ;
V_3 -> V_37 = F_142 ( V_37 , V_43 ) ;
if ( ! V_3 -> V_37 )
goto V_174;
V_167 = F_143 ( & V_166 , L_13 ) ;
V_169 = F_143 ( & V_166 , L_13 ) ;
V_168 = F_143 ( & V_169 , L_15 ) ;
if ( V_166 )
F_145 ( L_18 ) ;
V_3 -> V_4 = F_146 ( sizeof( * ( V_3 -> V_4 ) ) ,
F_147 ( struct V_1 ) ) ;
if ( ! V_3 -> V_4 ) {
V_35 -> error = L_19 ;
goto V_174;
}
if ( ! V_167 || ( ! strcmp ( V_167 , L_20 ) && ! V_168 ) ) {
V_167 = L_21 ;
V_168 = L_20 ;
}
if ( strcmp ( V_167 , L_22 ) && ! V_168 ) {
V_35 -> error = L_23 ;
return - V_39 ;
}
V_171 = F_125 ( V_175 , V_43 ) ;
if ( ! V_171 )
goto V_174;
V_172 = snprintf ( V_171 , V_175 ,
L_24 , V_167 , V_37 ) ;
if ( V_172 < 0 ) {
F_28 ( V_171 ) ;
goto V_174;
}
V_172 = F_124 ( V_3 , V_171 ) ;
if ( V_172 < 0 ) {
V_35 -> error = L_25 ;
goto V_42;
}
V_172 = F_129 ( V_3 , V_24 ) ;
if ( V_172 < 0 ) {
V_35 -> error = L_26 ;
goto V_42;
}
V_3 -> V_10 = F_18 ( F_3 ( V_3 ) ) ;
if ( V_3 -> V_10 )
V_3 -> V_10 = F_148 ( V_3 -> V_10 ,
( unsigned int ) ( sizeof( V_49 ) / sizeof( T_1 ) ) ) ;
else if ( V_168 ) {
F_145 ( L_27 ) ;
V_168 = NULL ;
}
if ( V_168 == NULL )
V_3 -> V_96 = NULL ;
else if ( strcmp ( V_168 , L_20 ) == 0 )
V_3 -> V_96 = & V_176 ;
else if ( strcmp ( V_168 , L_28 ) == 0 )
V_3 -> V_96 = & V_177 ;
else if ( strcmp ( V_168 , L_29 ) == 0 )
V_3 -> V_96 = & V_178 ;
else if ( strcmp ( V_168 , L_30 ) == 0 )
V_3 -> V_96 = & V_179 ;
else if ( strcmp ( V_168 , L_31 ) == 0 )
V_3 -> V_96 = & V_180 ;
else if ( strcmp ( V_168 , L_32 ) == 0 ) {
V_3 -> V_96 = & V_181 ;
if ( V_3 -> V_25 % V_3 -> V_53 )
V_3 -> V_53 ++ ;
} else {
V_172 = - V_39 ;
V_35 -> error = L_33 ;
goto V_42;
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_182 ) {
V_172 = V_3 -> V_96 -> V_182 ( V_3 , V_35 , V_169 ) ;
if ( V_172 < 0 ) {
V_35 -> error = L_34 ;
goto V_42;
}
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_183 ) {
V_172 = V_3 -> V_96 -> V_183 ( V_3 ) ;
if ( V_172 < 0 ) {
V_35 -> error = L_35 ;
goto V_42;
}
}
V_172 = 0 ;
V_42:
F_28 ( V_171 ) ;
return V_172 ;
V_174:
V_35 -> error = L_36 ;
return - V_44 ;
}
static int F_149 ( struct V_34 * V_35 , unsigned int V_184 , char * * V_185 )
{
struct V_2 * V_3 ;
unsigned int V_25 , V_186 ;
unsigned long long V_187 ;
int V_172 ;
struct V_188 V_189 ;
const char * V_190 ;
char V_173 ;
static struct V_191 V_192 [] = {
{ 0 , 1 , L_37 } ,
} ;
if ( V_184 < 5 ) {
V_35 -> error = L_38 ;
return - V_39 ;
}
V_25 = strlen ( V_185 [ 1 ] ) >> 1 ;
V_3 = F_27 ( sizeof( * V_3 ) + V_25 * sizeof( T_1 ) , V_43 ) ;
if ( ! V_3 ) {
V_35 -> error = L_39 ;
return - V_44 ;
}
V_3 -> V_25 = V_25 ;
V_35 -> V_161 = V_3 ;
V_172 = F_141 ( V_35 , V_185 [ 0 ] , V_185 [ 1 ] ) ;
if ( V_172 < 0 )
goto V_42;
V_172 = - V_44 ;
V_3 -> V_126 = F_150 ( V_193 , V_194 ) ;
if ( ! V_3 -> V_126 ) {
V_35 -> error = L_40 ;
goto V_42;
}
V_3 -> V_88 = sizeof( struct V_86 ) ;
V_3 -> V_88 += F_151 ( F_3 ( V_3 ) ) ;
V_3 -> V_88 = F_64 ( V_3 -> V_88 , F_152 () ) ;
V_3 -> V_88 += F_65 ( F_3 ( V_3 ) ) &
~ ( F_152 () - 1 ) ;
V_3 -> V_101 = F_153 ( V_193 , V_3 -> V_88 +
sizeof( struct V_8 ) + V_3 -> V_10 ) ;
if ( ! V_3 -> V_101 ) {
V_35 -> error = L_41 ;
goto V_42;
}
V_3 -> V_121 = F_154 ( V_195 , 0 ) ;
if ( ! V_3 -> V_121 ) {
V_35 -> error = L_42 ;
goto V_42;
}
V_3 -> V_45 = F_155 ( V_193 , 0 ) ;
if ( ! V_3 -> V_45 ) {
V_35 -> error = L_43 ;
goto V_42;
}
V_172 = - V_39 ;
if ( sscanf ( V_185 [ 2 ] , L_44 , & V_187 , & V_173 ) != 1 ) {
V_35 -> error = L_45 ;
goto V_42;
}
V_3 -> V_84 = V_187 ;
if ( F_156 ( V_35 , V_185 [ 3 ] , F_157 ( V_35 -> V_196 ) , & V_3 -> V_137 ) ) {
V_35 -> error = L_46 ;
goto V_42;
}
if ( sscanf ( V_185 [ 4 ] , L_44 , & V_187 , & V_173 ) != 1 ) {
V_35 -> error = L_47 ;
goto V_42;
}
V_3 -> V_142 = V_187 ;
V_185 += 5 ;
V_184 -= 5 ;
if ( V_184 ) {
V_189 . V_184 = V_184 ;
V_189 . V_185 = V_185 ;
V_172 = F_158 ( V_192 , & V_189 , & V_186 , & V_35 -> error ) ;
if ( V_172 )
goto V_42;
V_190 = F_159 ( & V_189 ) ;
if ( V_186 == 1 && V_190 &&
! strcasecmp ( V_190 , L_48 ) )
V_35 -> V_197 = 1 ;
else if ( V_186 ) {
V_172 = - V_39 ;
V_35 -> error = L_49 ;
goto V_42;
}
}
V_172 = - V_44 ;
V_3 -> V_145 = F_160 ( L_50 , V_198 , 1 ) ;
if ( ! V_3 -> V_145 ) {
V_35 -> error = L_51 ;
goto V_42;
}
V_3 -> V_154 = F_160 ( L_52 ,
V_199 | V_198 , 1 ) ;
if ( ! V_3 -> V_154 ) {
V_35 -> error = L_53 ;
goto V_42;
}
V_35 -> V_200 = 1 ;
V_35 -> V_201 = true ;
return 0 ;
V_42:
F_133 ( V_35 ) ;
return V_172 ;
}
static int F_161 ( struct V_34 * V_35 , struct V_75 * V_75 )
{
struct V_109 * V_110 ;
struct V_2 * V_3 = V_35 -> V_161 ;
if ( F_100 ( V_75 -> V_139 & ( V_202 | V_203 ) ) ) {
V_75 -> V_136 = V_3 -> V_137 -> V_138 ;
if ( F_114 ( V_75 ) )
V_75 -> V_141 = V_3 -> V_142 + F_162 ( V_35 , V_75 -> V_141 ) ;
return V_204 ;
}
V_110 = F_93 ( V_3 , V_75 , F_162 ( V_35 , V_75 -> V_141 ) ) ;
if ( F_53 ( V_110 -> V_127 ) == V_134 ) {
if ( F_103 ( V_110 , V_205 ) )
F_109 ( V_110 ) ;
} else
F_102 ( V_110 ) ;
return V_206 ;
}
static void F_163 ( struct V_34 * V_35 , T_6 type ,
unsigned V_207 , char * V_208 , unsigned V_209 )
{
struct V_2 * V_3 = V_35 -> V_161 ;
unsigned V_64 , V_210 = 0 ;
switch ( type ) {
case V_211 :
V_208 [ 0 ] = '\0' ;
break;
case V_212 :
F_164 ( L_54 , V_3 -> V_164 ) ;
if ( V_3 -> V_25 > 0 )
for ( V_64 = 0 ; V_64 < V_3 -> V_25 ; V_64 ++ )
F_164 ( L_55 , V_3 -> V_24 [ V_64 ] ) ;
else
F_164 ( L_13 ) ;
F_164 ( L_56 , ( unsigned long long ) V_3 -> V_84 ,
V_3 -> V_137 -> V_213 , ( unsigned long long ) V_3 -> V_142 ) ;
if ( V_35 -> V_197 )
F_164 ( L_57 ) ;
break;
}
}
static void F_165 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_161 ;
F_130 ( V_214 , & V_3 -> V_28 ) ;
}
static int F_166 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_161 ;
if ( ! F_167 ( V_160 , & V_3 -> V_28 ) ) {
F_168 ( L_58 ) ;
return - V_215 ;
}
return 0 ;
}
static void F_169 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_161 ;
F_132 ( V_214 , & V_3 -> V_28 ) ;
}
static int F_170 ( struct V_34 * V_35 , unsigned V_184 , char * * V_185 )
{
struct V_2 * V_3 = V_35 -> V_161 ;
int V_172 = - V_39 ;
if ( V_184 < 2 )
goto error;
if ( ! strcasecmp ( V_185 [ 0 ] , L_59 ) ) {
if ( ! F_167 ( V_214 , & V_3 -> V_28 ) ) {
F_145 ( L_60 ) ;
return - V_39 ;
}
if ( V_184 == 3 && ! strcasecmp ( V_185 [ 1 ] , L_61 ) ) {
V_172 = F_129 ( V_3 , V_185 [ 2 ] ) ;
if ( V_172 )
return V_172 ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_183 )
V_172 = V_3 -> V_96 -> V_183 ( V_3 ) ;
return V_172 ;
}
if ( V_184 == 2 && ! strcasecmp ( V_185 [ 1 ] , L_62 ) ) {
if ( V_3 -> V_96 && V_3 -> V_96 -> V_216 ) {
V_172 = V_3 -> V_96 -> V_216 ( V_3 ) ;
if ( V_172 )
return V_172 ;
}
return F_131 ( V_3 ) ;
}
}
error:
F_145 ( L_63 ) ;
return - V_39 ;
}
static int F_171 ( struct V_34 * V_35 , struct V_217 * V_218 ,
struct V_89 * V_219 , int V_220 )
{
struct V_2 * V_3 = V_35 -> V_161 ;
struct V_221 * V_222 = F_172 ( V_3 -> V_137 -> V_138 ) ;
if ( ! V_222 -> V_223 )
return V_220 ;
V_218 -> V_136 = V_3 -> V_137 -> V_138 ;
V_218 -> V_141 = V_3 -> V_142 + F_162 ( V_35 , V_218 -> V_141 ) ;
return F_173 ( V_220 , V_222 -> V_223 ( V_222 , V_218 , V_219 ) ) ;
}
static int F_174 ( struct V_34 * V_35 ,
T_7 V_224 , void * V_57 )
{
struct V_2 * V_3 = V_35 -> V_161 ;
return V_224 ( V_35 , V_3 -> V_137 , V_3 -> V_142 , V_35 -> V_119 , V_57 ) ;
}
static int T_8 F_175 ( void )
{
int V_33 ;
V_194 = F_176 ( V_109 , 0 ) ;
if ( ! V_194 )
return - V_44 ;
V_33 = F_177 ( & V_225 ) ;
if ( V_33 < 0 ) {
F_168 ( L_64 , V_33 ) ;
F_178 ( V_194 ) ;
}
return V_33 ;
}
static void T_9 F_179 ( void )
{
F_180 ( & V_225 ) ;
F_178 ( V_194 ) ;
}
