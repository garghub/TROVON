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
static void F_84 ( struct V_75 * V_75 )
{
struct V_109 * V_110 = V_75 -> V_111 ;
struct V_2 * V_3 = V_110 -> V_3 ;
F_85 ( V_75 , V_3 -> V_45 ) ;
}
static struct V_75 * F_86 ( struct V_109 * V_110 , unsigned V_112 ,
unsigned * V_113 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
struct V_75 * V_114 ;
unsigned int V_115 = ( V_112 + V_116 - 1 ) >> V_117 ;
T_5 V_118 = V_102 | V_119 ;
unsigned V_64 , V_120 ;
struct V_121 * V_121 ;
V_114 = F_87 ( V_102 , V_115 , V_3 -> V_45 ) ;
if ( ! V_114 )
return NULL ;
F_88 ( V_110 , V_114 ) ;
* V_113 = 0 ;
for ( V_64 = 0 ; V_64 < V_115 ; V_64 ++ ) {
V_121 = F_74 ( V_3 -> V_122 , V_118 ) ;
if ( ! V_121 ) {
* V_113 = 1 ;
break;
}
V_118 = ( V_118 | V_123 ) & ~ V_124 ;
V_120 = ( V_112 > V_116 ) ? V_116 : V_112 ;
if ( ! F_89 ( V_114 , V_121 , V_120 , 0 ) ) {
F_90 ( V_121 , V_3 -> V_122 ) ;
break;
}
V_112 -= V_120 ;
}
if ( ! V_114 -> V_125 ) {
F_91 ( V_114 ) ;
return NULL ;
}
return V_114 ;
}
static void F_92 ( struct V_2 * V_3 , struct V_75 * V_114 )
{
unsigned int V_64 ;
struct V_89 * V_126 ;
for ( V_64 = 0 ; V_64 < V_114 -> V_106 ; V_64 ++ ) {
V_126 = F_67 ( V_114 , V_64 ) ;
F_93 ( ! V_126 -> V_92 ) ;
F_90 ( V_126 -> V_92 , V_3 -> V_122 ) ;
V_126 -> V_92 = NULL ;
}
}
static struct V_109 * F_94 ( struct V_2 * V_3 ,
struct V_75 * V_75 , T_4 V_77 )
{
struct V_109 * V_110 ;
V_110 = F_74 ( V_3 -> V_127 , V_102 ) ;
V_110 -> V_3 = V_3 ;
V_110 -> V_128 = V_75 ;
V_110 -> V_77 = V_77 ;
V_110 -> error = 0 ;
V_110 -> V_129 = NULL ;
F_78 ( & V_110 -> V_130 , 0 ) ;
return V_110 ;
}
static void F_95 ( struct V_109 * V_110 )
{
F_79 ( & V_110 -> V_130 ) ;
}
static void F_96 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
struct V_75 * V_128 = V_110 -> V_128 ;
struct V_109 * V_129 = V_110 -> V_129 ;
int error = V_110 -> error ;
if ( ! F_97 ( & V_110 -> V_130 ) )
return;
F_90 ( V_110 , V_3 -> V_127 ) ;
if ( F_98 ( ! V_129 ) )
F_99 ( V_128 , error ) ;
else {
if ( error && ! V_129 -> error )
V_129 -> error = error ;
F_96 ( V_129 ) ;
}
}
static void F_100 ( struct V_75 * V_114 , int error )
{
struct V_109 * V_110 = V_114 -> V_111 ;
struct V_2 * V_3 = V_110 -> V_3 ;
unsigned V_131 = F_53 ( V_114 ) ;
if ( F_101 ( ! F_102 ( V_114 , V_132 ) && ! error ) )
error = - V_133 ;
if ( V_131 == V_69 )
F_92 ( V_3 , V_114 ) ;
F_91 ( V_114 ) ;
if ( V_131 == V_134 && ! error ) {
F_103 ( V_110 ) ;
return;
}
if ( F_101 ( error ) )
V_110 -> error = error ;
F_96 ( V_110 ) ;
}
static void F_88 ( struct V_109 * V_110 , struct V_75 * V_114 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
V_114 -> V_111 = V_110 ;
V_114 -> V_135 = F_100 ;
V_114 -> V_136 = V_3 -> V_137 -> V_138 ;
V_114 -> V_139 = V_110 -> V_128 -> V_139 ;
V_114 -> V_140 = F_84 ;
}
static int F_104 ( struct V_109 * V_110 , T_5 V_141 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
struct V_75 * V_128 = V_110 -> V_128 ;
struct V_75 * V_114 ;
V_114 = F_87 ( V_141 , F_105 ( V_128 ) , V_3 -> V_45 ) ;
if ( ! V_114 )
return 1 ;
F_95 ( V_110 ) ;
F_88 ( V_110 , V_114 ) ;
V_114 -> V_81 = 0 ;
V_114 -> V_106 = F_105 ( V_128 ) ;
V_114 -> V_125 = V_128 -> V_125 ;
V_114 -> V_142 = V_3 -> V_143 + V_110 -> V_77 ;
memcpy ( V_114 -> V_144 , F_106 ( V_128 ) ,
sizeof( struct V_89 ) * V_114 -> V_106 ) ;
F_107 ( V_114 ) ;
return 0 ;
}
static void F_108 ( struct V_109 * V_110 )
{
struct V_75 * V_114 = V_110 -> V_59 . V_76 ;
F_107 ( V_114 ) ;
}
static void F_109 ( struct V_145 * V_146 )
{
struct V_109 * V_110 = F_110 ( V_146 , struct V_109 , V_146 ) ;
if ( F_53 ( V_110 -> V_128 ) == V_134 ) {
F_95 ( V_110 ) ;
if ( F_104 ( V_110 , V_102 ) )
V_110 -> error = - V_44 ;
F_96 ( V_110 ) ;
} else
F_108 ( V_110 ) ;
}
static void F_111 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
F_112 ( & V_110 -> V_146 , F_109 ) ;
F_113 ( V_3 -> V_147 , & V_110 -> V_146 ) ;
}
static void F_114 ( struct V_109 * V_110 , int V_148 )
{
struct V_75 * V_114 = V_110 -> V_59 . V_76 ;
struct V_2 * V_3 = V_110 -> V_3 ;
if ( F_101 ( V_110 -> error < 0 ) ) {
F_92 ( V_3 , V_114 ) ;
F_91 ( V_114 ) ;
F_96 ( V_110 ) ;
return;
}
F_93 ( V_110 -> V_59 . V_82 < V_114 -> V_106 ) ;
V_114 -> V_142 = V_3 -> V_143 + V_110 -> V_77 ;
if ( V_148 )
F_111 ( V_110 ) ;
else
F_107 ( V_114 ) ;
}
static void F_115 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
struct V_75 * V_114 ;
struct V_109 * V_149 ;
int V_150 ;
unsigned V_113 = 0 ;
unsigned V_151 = V_110 -> V_128 -> V_125 ;
T_4 V_77 = V_110 -> V_77 ;
int V_33 ;
F_95 ( V_110 ) ;
F_59 ( V_3 , & V_110 -> V_59 , NULL , V_110 -> V_128 , V_77 ) ;
while ( V_151 ) {
V_114 = F_86 ( V_110 , V_151 , & V_113 ) ;
if ( F_101 ( ! V_114 ) ) {
V_110 -> error = - V_44 ;
break;
}
V_110 -> V_59 . V_76 = V_114 ;
V_110 -> V_59 . V_82 = 0 ;
V_151 -= V_114 -> V_125 ;
V_77 += F_116 ( V_114 ) ;
F_95 ( V_110 ) ;
V_33 = F_77 ( V_3 , & V_110 -> V_59 ) ;
if ( V_33 < 0 )
V_110 -> error = - V_133 ;
V_150 = F_97 ( & V_110 -> V_59 . V_105 ) ;
if ( V_150 ) {
F_114 ( V_110 , 0 ) ;
if ( F_101 ( V_33 < 0 ) )
break;
V_110 -> V_77 = V_77 ;
}
if ( F_101 ( V_113 ) )
F_117 ( V_152 , V_153 / 100 ) ;
if ( F_101 ( ! V_150 && V_151 ) ) {
V_149 = F_94 ( V_110 -> V_3 , V_110 -> V_128 ,
V_77 ) ;
F_95 ( V_149 ) ;
F_59 ( V_3 , & V_149 -> V_59 , NULL ,
V_110 -> V_128 , V_77 ) ;
V_149 -> V_59 . V_80 = V_110 -> V_59 . V_80 ;
V_149 -> V_59 . V_78 = V_110 -> V_59 . V_78 ;
if ( ! V_110 -> V_129 )
V_149 -> V_129 = V_110 ;
else {
V_149 -> V_129 = V_110 -> V_129 ;
F_95 ( V_110 -> V_129 ) ;
F_96 ( V_110 ) ;
}
V_110 = V_149 ;
}
}
F_96 ( V_110 ) ;
}
static void F_118 ( struct V_109 * V_110 )
{
F_96 ( V_110 ) ;
}
static void F_119 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
int V_33 = 0 ;
F_95 ( V_110 ) ;
F_59 ( V_3 , & V_110 -> V_59 , V_110 -> V_128 , V_110 -> V_128 ,
V_110 -> V_77 ) ;
V_33 = F_77 ( V_3 , & V_110 -> V_59 ) ;
if ( V_33 < 0 )
V_110 -> error = - V_133 ;
if ( F_97 ( & V_110 -> V_59 . V_105 ) )
F_118 ( V_110 ) ;
F_96 ( V_110 ) ;
}
static void V_104 ( struct V_154 * V_155 ,
int error )
{
struct V_8 * V_9 = V_155 -> V_57 ;
struct V_74 * V_59 = V_9 -> V_59 ;
struct V_109 * V_110 = F_110 ( V_59 , struct V_109 , V_59 ) ;
struct V_2 * V_3 = V_110 -> V_3 ;
if ( error == - V_108 ) {
F_120 ( & V_59 -> V_85 ) ;
return;
}
if ( ! error && V_3 -> V_96 && V_3 -> V_96 -> V_98 )
error = V_3 -> V_96 -> V_98 ( V_3 , F_63 ( V_3 , V_9 ) , V_9 ) ;
if ( error < 0 )
V_110 -> error = - V_133 ;
F_90 ( F_62 ( V_3 , V_9 ) , V_3 -> V_101 ) ;
if ( ! F_97 ( & V_59 -> V_105 ) )
return;
if ( F_53 ( V_110 -> V_128 ) == V_134 )
F_118 ( V_110 ) ;
else
F_114 ( V_110 , 1 ) ;
}
static void F_121 ( struct V_145 * V_146 )
{
struct V_109 * V_110 = F_110 ( V_146 , struct V_109 , V_146 ) ;
if ( F_53 ( V_110 -> V_128 ) == V_134 )
F_119 ( V_110 ) ;
else
F_115 ( V_110 ) ;
}
static void F_103 ( struct V_109 * V_110 )
{
struct V_2 * V_3 = V_110 -> V_3 ;
F_112 ( & V_110 -> V_146 , F_121 ) ;
F_113 ( V_3 -> V_156 , & V_110 -> V_146 ) ;
}
static int F_122 ( T_1 * V_24 , char * V_157 , unsigned int V_112 )
{
char V_158 [ 3 ] ;
unsigned int V_64 ;
V_158 [ 2 ] = '\0' ;
for ( V_64 = 0 ; V_64 < V_112 ; V_64 ++ ) {
V_158 [ 0 ] = * V_157 ++ ;
V_158 [ 1 ] = * V_157 ++ ;
if ( F_123 ( V_158 , 16 , & V_24 [ V_64 ] ) )
return - V_39 ;
}
if ( * V_157 != '\0' )
return - V_39 ;
return 0 ;
}
static void F_124 ( char * V_157 , T_1 * V_24 , unsigned int V_112 )
{
unsigned int V_64 ;
for ( V_64 = 0 ; V_64 < V_112 ; V_64 ++ ) {
sprintf ( V_157 , L_13 , * V_24 ) ;
V_157 += 2 ;
V_24 ++ ;
}
}
static void F_125 ( struct V_2 * V_3 )
{
unsigned V_64 ;
if ( ! V_3 -> V_6 )
return;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ )
if ( V_3 -> V_6 [ V_64 ] && ! F_16 ( V_3 -> V_6 [ V_64 ] ) ) {
F_126 ( V_3 -> V_6 [ V_64 ] ) ;
V_3 -> V_6 [ V_64 ] = NULL ;
}
F_28 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
static int F_127 ( struct V_2 * V_3 , char * V_159 )
{
unsigned V_64 ;
int V_23 ;
V_3 -> V_6 = F_128 ( V_3 -> V_54 * sizeof( struct V_5 * ) ,
V_43 ) ;
if ( ! V_3 -> V_6 )
return - V_44 ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_3 -> V_6 [ V_64 ] = F_129 ( V_159 , 0 , 0 ) ;
if ( F_16 ( V_3 -> V_6 [ V_64 ] ) ) {
V_23 = F_26 ( V_3 -> V_6 [ V_64 ] ) ;
F_125 ( V_3 ) ;
return V_23 ;
}
}
return 0 ;
}
static int F_130 ( struct V_2 * V_3 )
{
unsigned V_56 = V_3 -> V_25 >> F_33 ( V_3 -> V_54 ) ;
int V_23 = 0 , V_64 , V_33 ;
for ( V_64 = 0 ; V_64 < V_3 -> V_54 ; V_64 ++ ) {
V_33 = F_131 ( V_3 -> V_6 [ V_64 ] ,
V_3 -> V_24 + ( V_64 * V_56 ) ,
V_56 ) ;
if ( V_33 )
V_23 = V_33 ;
}
return V_23 ;
}
static int F_132 ( struct V_2 * V_3 , char * V_24 )
{
int V_33 = - V_39 ;
int V_160 = strlen ( V_24 ) ;
if ( V_3 -> V_25 != ( V_160 >> 1 ) )
goto V_161;
if ( ! V_3 -> V_25 && strcmp ( V_24 , L_14 ) )
goto V_161;
if ( V_3 -> V_25 && F_122 ( V_3 -> V_24 , V_24 , V_3 -> V_25 ) < 0 )
goto V_161;
F_133 ( V_162 , & V_3 -> V_28 ) ;
V_33 = F_130 ( V_3 ) ;
V_161:
memset ( V_24 , '0' , V_160 ) ;
return V_33 ;
}
static int F_134 ( struct V_2 * V_3 )
{
F_135 ( V_162 , & V_3 -> V_28 ) ;
memset ( & V_3 -> V_24 , 0 , V_3 -> V_25 * sizeof( T_1 ) ) ;
return F_130 ( V_3 ) ;
}
static void F_136 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_163 ;
struct V_1 * V_164 ;
int V_4 ;
V_35 -> V_163 = NULL ;
if ( ! V_3 )
return;
if ( V_3 -> V_147 )
F_137 ( V_3 -> V_147 ) ;
if ( V_3 -> V_156 )
F_137 ( V_3 -> V_156 ) ;
if ( V_3 -> V_4 )
F_138 (cpu) {
V_164 = F_139 ( V_3 -> V_4 , V_4 ) ;
if ( V_164 -> V_87 )
F_90 ( V_164 -> V_87 , V_3 -> V_101 ) ;
}
F_125 ( V_3 ) ;
if ( V_3 -> V_45 )
F_140 ( V_3 -> V_45 ) ;
if ( V_3 -> V_122 )
F_141 ( V_3 -> V_122 ) ;
if ( V_3 -> V_101 )
F_141 ( V_3 -> V_101 ) ;
if ( V_3 -> V_127 )
F_141 ( V_3 -> V_127 ) ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_165 )
V_3 -> V_96 -> V_165 ( V_3 ) ;
if ( V_3 -> V_137 )
F_142 ( V_35 , V_3 -> V_137 ) ;
if ( V_3 -> V_4 )
F_143 ( V_3 -> V_4 ) ;
F_23 ( V_3 -> V_37 ) ;
F_23 ( V_3 -> V_166 ) ;
F_23 ( V_3 ) ;
}
static int F_144 ( struct V_34 * V_35 ,
char * V_167 , char * V_24 )
{
struct V_2 * V_3 = V_35 -> V_163 ;
char * V_168 , * V_37 , * V_169 , * V_170 , * V_171 , * V_172 ;
char * V_173 = NULL ;
int V_174 = - V_39 ;
char V_175 ;
if ( strchr ( V_167 , '(' ) ) {
V_35 -> error = L_15 ;
return - V_39 ;
}
V_3 -> V_166 = F_145 ( V_167 , V_43 ) ;
if ( ! V_3 -> V_166 )
goto V_176;
V_168 = V_167 ;
V_172 = F_146 ( & V_168 , L_14 ) ;
V_37 = F_146 ( & V_172 , L_16 ) ;
if ( ! V_172 )
V_3 -> V_54 = 1 ;
else if ( sscanf ( V_172 , L_17 , & V_3 -> V_54 , & V_175 ) != 1 ||
! F_147 ( V_3 -> V_54 ) ) {
V_35 -> error = L_18 ;
return - V_39 ;
}
V_3 -> V_53 = V_3 -> V_54 ;
V_3 -> V_37 = F_145 ( V_37 , V_43 ) ;
if ( ! V_3 -> V_37 )
goto V_176;
V_169 = F_146 ( & V_168 , L_14 ) ;
V_171 = F_146 ( & V_168 , L_14 ) ;
V_170 = F_146 ( & V_171 , L_16 ) ;
if ( V_168 )
F_148 ( L_19 ) ;
V_3 -> V_4 = F_149 ( sizeof( * ( V_3 -> V_4 ) ) ,
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
V_173 = F_128 ( V_177 , V_43 ) ;
if ( ! V_173 )
goto V_176;
V_174 = snprintf ( V_173 , V_177 ,
L_25 , V_169 , V_37 ) ;
if ( V_174 < 0 ) {
F_28 ( V_173 ) ;
goto V_176;
}
V_174 = F_127 ( V_3 , V_173 ) ;
if ( V_174 < 0 ) {
V_35 -> error = L_26 ;
goto V_42;
}
V_174 = F_132 ( V_3 , V_24 ) ;
if ( V_174 < 0 ) {
V_35 -> error = L_27 ;
goto V_42;
}
V_3 -> V_10 = F_18 ( F_3 ( V_3 ) ) ;
if ( V_3 -> V_10 )
V_3 -> V_10 = F_151 ( V_3 -> V_10 ,
( unsigned int ) ( sizeof( V_49 ) / sizeof( T_1 ) ) ) ;
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
if ( V_3 -> V_25 % V_3 -> V_53 )
V_3 -> V_53 ++ ;
} else {
V_174 = - V_39 ;
V_35 -> error = L_34 ;
goto V_42;
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_184 ) {
V_174 = V_3 -> V_96 -> V_184 ( V_3 , V_35 , V_171 ) ;
if ( V_174 < 0 ) {
V_35 -> error = L_35 ;
goto V_42;
}
}
if ( V_3 -> V_96 && V_3 -> V_96 -> V_185 ) {
V_174 = V_3 -> V_96 -> V_185 ( V_3 ) ;
if ( V_174 < 0 ) {
V_35 -> error = L_36 ;
goto V_42;
}
}
V_174 = 0 ;
V_42:
F_28 ( V_173 ) ;
return V_174 ;
V_176:
V_35 -> error = L_37 ;
return - V_44 ;
}
static int F_152 ( struct V_34 * V_35 , unsigned int V_186 , char * * V_187 )
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
V_3 = F_27 ( sizeof( * V_3 ) + V_25 * sizeof( T_1 ) , V_43 ) ;
if ( ! V_3 ) {
V_35 -> error = L_40 ;
return - V_44 ;
}
V_3 -> V_25 = V_25 ;
V_35 -> V_163 = V_3 ;
V_174 = F_144 ( V_35 , V_187 [ 0 ] , V_187 [ 1 ] ) ;
if ( V_174 < 0 )
goto V_42;
V_174 = - V_44 ;
V_3 -> V_127 = F_153 ( V_195 , V_196 ) ;
if ( ! V_3 -> V_127 ) {
V_35 -> error = L_41 ;
goto V_42;
}
V_3 -> V_88 = sizeof( struct V_86 ) ;
V_3 -> V_88 += F_154 ( F_3 ( V_3 ) ) ;
V_3 -> V_88 = F_64 ( V_3 -> V_88 , F_155 () ) ;
V_3 -> V_88 += F_65 ( F_3 ( V_3 ) ) &
~ ( F_155 () - 1 ) ;
V_3 -> V_101 = F_156 ( V_195 , V_3 -> V_88 +
sizeof( struct V_8 ) + V_3 -> V_10 ) ;
if ( ! V_3 -> V_101 ) {
V_35 -> error = L_42 ;
goto V_42;
}
V_3 -> V_122 = F_157 ( V_197 , 0 ) ;
if ( ! V_3 -> V_122 ) {
V_35 -> error = L_43 ;
goto V_42;
}
V_3 -> V_45 = F_158 ( V_195 , 0 ) ;
if ( ! V_3 -> V_45 ) {
V_35 -> error = L_44 ;
goto V_42;
}
V_174 = - V_39 ;
if ( sscanf ( V_187 [ 2 ] , L_45 , & V_189 , & V_175 ) != 1 ) {
V_35 -> error = L_46 ;
goto V_42;
}
V_3 -> V_84 = V_189 ;
if ( F_159 ( V_35 , V_187 [ 3 ] , F_160 ( V_35 -> V_198 ) , & V_3 -> V_137 ) ) {
V_35 -> error = L_47 ;
goto V_42;
}
if ( sscanf ( V_187 [ 4 ] , L_45 , & V_189 , & V_175 ) != 1 ) {
V_35 -> error = L_48 ;
goto V_42;
}
V_3 -> V_143 = V_189 ;
V_187 += 5 ;
V_186 -= 5 ;
if ( V_186 ) {
V_191 . V_186 = V_186 ;
V_191 . V_187 = V_187 ;
V_174 = F_161 ( V_194 , & V_191 , & V_188 , & V_35 -> error ) ;
if ( V_174 )
goto V_42;
V_192 = F_162 ( & V_191 ) ;
if ( V_188 == 1 && V_192 &&
! strcasecmp ( V_192 , L_49 ) )
V_35 -> V_199 = 1 ;
else if ( V_188 ) {
V_174 = - V_39 ;
V_35 -> error = L_50 ;
goto V_42;
}
}
V_174 = - V_44 ;
V_3 -> V_147 = F_163 ( L_51 ,
V_200 |
V_201 ,
1 ) ;
if ( ! V_3 -> V_147 ) {
V_35 -> error = L_52 ;
goto V_42;
}
V_3 -> V_156 = F_163 ( L_53 ,
V_200 |
V_202 |
V_201 ,
1 ) ;
if ( ! V_3 -> V_156 ) {
V_35 -> error = L_54 ;
goto V_42;
}
V_35 -> V_203 = 1 ;
V_35 -> V_204 = true ;
return 0 ;
V_42:
F_136 ( V_35 ) ;
return V_174 ;
}
static int F_164 ( struct V_34 * V_35 , struct V_75 * V_75 ,
union V_205 * V_206 )
{
struct V_109 * V_110 ;
struct V_2 * V_3 = V_35 -> V_163 ;
if ( F_101 ( V_75 -> V_139 & ( V_207 | V_208 ) ) ) {
V_75 -> V_136 = V_3 -> V_137 -> V_138 ;
if ( F_116 ( V_75 ) )
V_75 -> V_142 = V_3 -> V_143 + F_165 ( V_35 , V_75 -> V_142 ) ;
return V_209 ;
}
V_110 = F_94 ( V_3 , V_75 , F_165 ( V_35 , V_75 -> V_142 ) ) ;
if ( F_53 ( V_110 -> V_128 ) == V_134 ) {
if ( F_104 ( V_110 , V_210 ) )
F_111 ( V_110 ) ;
} else
F_103 ( V_110 ) ;
return V_211 ;
}
static int F_166 ( struct V_34 * V_35 , T_6 type ,
unsigned V_212 , char * V_213 , unsigned V_214 )
{
struct V_2 * V_3 = V_35 -> V_163 ;
unsigned int V_215 = 0 ;
switch ( type ) {
case V_216 :
V_213 [ 0 ] = '\0' ;
break;
case V_217 :
F_167 ( L_55 , V_3 -> V_166 ) ;
if ( V_3 -> V_25 > 0 ) {
if ( ( V_214 - V_215 ) < ( ( V_3 -> V_25 << 1 ) + 1 ) )
return - V_44 ;
F_124 ( V_213 + V_215 , V_3 -> V_24 , V_3 -> V_25 ) ;
V_215 += V_3 -> V_25 << 1 ;
} else {
if ( V_215 >= V_214 )
return - V_44 ;
V_213 [ V_215 ++ ] = '-' ;
}
F_167 ( L_56 , ( unsigned long long ) V_3 -> V_84 ,
V_3 -> V_137 -> V_218 , ( unsigned long long ) V_3 -> V_143 ) ;
if ( V_35 -> V_199 )
F_167 ( L_57 ) ;
break;
}
return 0 ;
}
static void F_168 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_163 ;
F_133 ( V_219 , & V_3 -> V_28 ) ;
}
static int F_169 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_163 ;
if ( ! F_170 ( V_162 , & V_3 -> V_28 ) ) {
F_171 ( L_58 ) ;
return - V_220 ;
}
return 0 ;
}
static void F_172 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = V_35 -> V_163 ;
F_135 ( V_219 , & V_3 -> V_28 ) ;
}
static int F_173 ( struct V_34 * V_35 , unsigned V_186 , char * * V_187 )
{
struct V_2 * V_3 = V_35 -> V_163 ;
int V_174 = - V_39 ;
if ( V_186 < 2 )
goto error;
if ( ! strcasecmp ( V_187 [ 0 ] , L_59 ) ) {
if ( ! F_170 ( V_219 , & V_3 -> V_28 ) ) {
F_148 ( L_60 ) ;
return - V_39 ;
}
if ( V_186 == 3 && ! strcasecmp ( V_187 [ 1 ] , L_61 ) ) {
V_174 = F_132 ( V_3 , V_187 [ 2 ] ) ;
if ( V_174 )
return V_174 ;
if ( V_3 -> V_96 && V_3 -> V_96 -> V_185 )
V_174 = V_3 -> V_96 -> V_185 ( V_3 ) ;
return V_174 ;
}
if ( V_186 == 2 && ! strcasecmp ( V_187 [ 1 ] , L_62 ) ) {
if ( V_3 -> V_96 && V_3 -> V_96 -> V_221 ) {
V_174 = V_3 -> V_96 -> V_221 ( V_3 ) ;
if ( V_174 )
return V_174 ;
}
return F_134 ( V_3 ) ;
}
}
error:
F_148 ( L_63 ) ;
return - V_39 ;
}
static int F_174 ( struct V_34 * V_35 , struct V_222 * V_223 ,
struct V_89 * V_224 , int V_225 )
{
struct V_2 * V_3 = V_35 -> V_163 ;
struct V_226 * V_227 = F_175 ( V_3 -> V_137 -> V_138 ) ;
if ( ! V_227 -> V_228 )
return V_225 ;
V_223 -> V_136 = V_3 -> V_137 -> V_138 ;
V_223 -> V_142 = V_3 -> V_143 + F_165 ( V_35 , V_223 -> V_142 ) ;
return F_176 ( V_225 , V_227 -> V_228 ( V_227 , V_223 , V_224 ) ) ;
}
static int F_177 ( struct V_34 * V_35 ,
T_7 V_229 , void * V_57 )
{
struct V_2 * V_3 = V_35 -> V_163 ;
return V_229 ( V_35 , V_3 -> V_137 , V_3 -> V_143 , V_35 -> V_120 , V_57 ) ;
}
static int T_8 F_178 ( void )
{
int V_33 ;
V_196 = F_179 ( V_109 , 0 ) ;
if ( ! V_196 )
return - V_44 ;
V_33 = F_180 ( & V_230 ) ;
if ( V_33 < 0 ) {
F_171 ( L_64 , V_33 ) ;
F_181 ( V_196 ) ;
}
return V_33 ;
}
static void T_9 F_182 ( void )
{
F_183 ( & V_230 ) ;
F_181 ( V_196 ) ;
}
