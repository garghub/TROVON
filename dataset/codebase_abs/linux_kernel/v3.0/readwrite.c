static T_1 F_1 ( T_1 V_1 , T_2 V_2 )
{
switch ( V_2 ) {
case 0 :
return V_1 ;
case F_2 ( 1 ) :
return F_3 ( T_1 , V_1 , V_3 ) ;
case F_2 ( 2 ) :
return F_3 ( T_1 , V_1 , V_4 ) ;
case F_2 ( 3 ) :
return F_3 ( T_1 , V_1 , V_5 ) ;
case F_2 ( 4 ) :
return F_3 ( T_1 , V_1 , V_6 ) ;
case F_2 ( 5 ) :
return F_3 ( T_1 , V_1 , V_7 ) ;
default:
F_4 ( 1 ) ;
return V_1 ;
}
}
static inline T_1 F_5 ( T_3 V_8 )
{
return 1ULL << ( V_9 * V_8 ) ;
}
static inline T_4 F_6 ( void )
{
return V_10 | ( 1ULL << V_11 ) ;
}
T_4 F_7 ( T_1 V_1 , T_2 V_2 )
{
T_4 V_12 ;
F_8 ( V_1 >= V_10 ) ;
if ( V_2 == 0 )
return V_1 ;
V_12 = V_10 ;
V_12 |= ( V_13 long ) V_2 << V_11 ;
V_12 |= V_1 >> ( ( V_13 T_3 ) V_2 * V_9 ) ;
return V_12 ;
}
void F_9 ( T_4 V_12 , T_1 * V_1 , T_2 * V_2 )
{
T_3 V_14 ;
if ( ! ( V_12 & V_10 ) ) {
* V_1 = V_12 ;
* V_2 = 0 ;
return;
}
V_14 = ( V_12 & ~ V_10 ) >> V_11 ;
* V_2 = F_2 ( V_14 ) ;
* V_1 = ( V_12 << ( V_14 * V_9 ) ) & ~ V_10 ;
* V_1 = F_1 ( * V_1 , * V_2 ) ;
return;
}
static struct V_15 F_10 ( T_5 V_16 )
{
return F_11 ( F_12 ( V_16 ) ) ;
}
static T_5 F_13 ( struct V_15 V_17 )
{
return F_14 ( ( T_1 ) V_17 . V_18 * V_19 + V_17 . V_20 ) ;
}
static void F_15 ( struct V_21 * V_22 , struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
int V_26 ;
V_23 -> V_27 = F_16 ( V_22 -> V_28 ) ;
V_25 -> V_29 = V_22 -> V_30 ;
V_25 -> V_31 = F_17 ( V_22 -> V_32 ) ;
V_23 -> V_33 = F_17 ( V_22 -> V_34 ) ;
V_23 -> V_35 = F_17 ( V_22 -> V_36 ) ;
V_23 -> V_37 = F_12 ( V_22 -> V_38 ) ;
F_18 ( V_23 , F_12 ( V_22 -> V_39 ) ) ;
V_23 -> V_40 = F_10 ( V_22 -> V_41 ) ;
V_23 -> V_42 = F_10 ( V_22 -> V_43 ) ;
V_23 -> V_44 = F_10 ( V_22 -> V_45 ) ;
V_23 -> V_46 = F_17 ( V_22 -> V_47 ) ;
V_23 -> V_48 = F_17 ( V_22 -> V_49 ) ;
switch ( V_23 -> V_27 & V_50 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_23 -> V_55 = F_12 ( V_22 -> V_56 [ 0 ] ) ;
break;
case V_57 :
case V_58 :
case V_59 :
for ( V_26 = 0 ; V_26 < V_60 ; V_26 ++ )
V_25 -> V_61 [ V_26 ] = F_12 ( V_22 -> V_56 [ V_26 ] ) ;
break;
default:
F_19 () ;
}
}
static void F_20 ( struct V_23 * V_23 , struct V_21 * V_22 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
int V_26 ;
V_22 -> V_28 = F_21 ( V_23 -> V_27 ) ;
V_22 -> V_30 = V_25 -> V_29 ;
V_22 -> V_62 = 0 ;
V_22 -> V_32 = F_22 ( V_25 -> V_31 ) ;
V_22 -> V_34 = F_22 ( V_23 -> V_33 ) ;
V_22 -> V_36 = F_22 ( V_23 -> V_35 ) ;
V_22 -> V_38 = F_14 ( F_23 ( V_23 ) ) ;
V_22 -> V_39 = F_14 ( V_25 -> V_63 ) ;
V_22 -> V_41 = F_13 ( V_23 -> V_40 ) ;
V_22 -> V_43 = F_13 ( V_23 -> V_42 ) ;
V_22 -> V_45 = F_13 ( V_23 -> V_44 ) ;
V_22 -> V_47 = F_22 ( V_23 -> V_46 ) ;
V_22 -> V_49 = F_22 ( V_23 -> V_48 ) ;
switch ( V_23 -> V_27 & V_50 ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_22 -> V_56 [ 0 ] = F_14 ( V_23 -> V_55 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
for ( V_26 = 0 ; V_26 < V_60 ; V_26 ++ )
V_22 -> V_56 [ V_26 ] = F_14 ( V_25 -> V_61 [ V_26 ] ) ;
break;
default:
F_19 () ;
}
}
static void F_24 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_24 * V_25 = V_24 ( V_23 ) ;
V_23 -> V_67 = V_68 ;
if ( V_25 -> V_63 >> V_65 -> V_69 < V_68 )
V_23 -> V_67 = F_25 ( V_25 -> V_63 , 512 ) >> 9 ;
}
void F_18 ( struct V_23 * V_23 , T_1 V_70 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
V_25 -> V_63 = V_70 ;
F_24 ( V_23 ) ;
}
static void F_26 ( struct V_64 * V_65 , struct V_71 * V_71 , int V_72 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
F_8 ( ! F_27 ( V_71 ) ) ;
if ( V_72 ) {
F_8 ( F_28 ( V_71 ) ) ;
F_29 ( V_71 ) ;
} else {
if ( F_28 ( V_71 ) )
V_74 -> V_75 ++ ;
else
F_29 ( V_71 ) ;
}
}
static void F_30 ( struct V_64 * V_65 , struct V_71 * V_71 , int V_72 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
F_8 ( ! F_27 ( V_71 ) ) ;
if ( V_72 )
F_31 ( V_71 ) ;
else {
F_8 ( ! F_28 ( V_71 ) ) ;
if ( V_74 -> V_75 )
V_74 -> V_75 -- ;
else
F_31 ( V_71 ) ;
}
}
static void F_32 ( struct V_64 * V_65 , struct V_71 * V_71 ,
int V_72 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
if ( V_71 )
F_26 ( V_65 , V_71 , V_72 ) ;
if ( V_72 ) {
F_33 ( & V_74 -> V_76 ) ;
F_34 ( V_65 ) ;
}
}
static void F_35 ( struct V_64 * V_65 , struct V_71 * V_71 ,
int V_72 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
if ( V_71 )
F_30 ( V_65 , V_71 , V_72 ) ;
if ( V_72 )
F_36 ( & V_74 -> V_76 ) ;
}
static struct V_71 * F_37 ( struct V_23 * V_23 , T_1 V_1 ,
T_2 V_2 )
{
return F_38 ( V_23 -> V_77 ,
F_7 ( V_1 , V_2 ) , V_78 ) ;
}
static void F_39 ( struct V_71 * V_71 )
{
F_40 ( V_71 ) ;
F_41 ( V_71 ) ;
}
static void F_42 ( struct V_71 * V_71 )
{
int V_79 = 0 ;
while ( F_43 ( ! F_44 ( V_71 ) ) ) {
if ( V_79 ++ > 0x1000 ) {
F_45 ( V_80 L_1 , & V_79 ) ;
F_19 () ;
}
if ( F_28 ( V_71 ) ) {
break;
}
F_46 () ;
}
F_8 ( ! F_27 ( V_71 ) ) ;
}
static struct V_71 * F_47 ( struct V_23 * V_23 , T_1 V_1 ,
T_2 V_2 )
{
struct V_81 * V_82 = V_23 -> V_77 ;
T_4 V_12 = F_7 ( V_1 , V_2 ) ;
struct V_71 * V_71 ;
int V_83 ;
V_84:
V_71 = F_48 ( V_82 , V_12 ) ;
if ( ! V_71 ) {
V_71 = F_49 ( V_78 ) ;
if ( ! V_71 )
return NULL ;
V_83 = F_50 ( V_71 , V_82 , V_12 , V_78 ) ;
if ( F_43 ( V_83 ) ) {
F_41 ( V_71 ) ;
if ( V_83 == - V_85 )
goto V_84;
return NULL ;
}
} else F_42 ( V_71 ) ;
F_8 ( ! F_27 ( V_71 ) ) ;
return V_71 ;
}
static void F_51 ( struct V_71 * V_71 )
{
if ( ! F_28 ( V_71 ) )
F_40 ( V_71 ) ;
}
static void F_52 ( struct V_71 * V_71 )
{
F_51 ( V_71 ) ;
F_41 ( V_71 ) ;
}
static struct V_71 * F_53 ( struct V_23 * V_23 , T_1 V_1 , T_2 V_2 ,
int V_86 )
{
if ( V_86 == V_87 )
return F_37 ( V_23 , V_1 , V_2 ) ;
else
return F_47 ( V_23 , V_1 , V_2 ) ;
}
static void F_54 ( struct V_71 * V_71 , int V_86 )
{
if ( V_86 == V_87 )
F_39 ( V_71 ) ;
else
F_52 ( V_71 ) ;
}
static unsigned long F_55 ( T_1 V_88 , int V_89 , int V_90 )
{
T_1 V_91 = V_88 ;
V_91 >>= V_89 * V_90 ;
V_91 <<= 64 - V_90 ;
V_91 >>= 64 - V_90 ;
return V_91 ;
}
static unsigned long F_56 ( T_1 V_88 , T_2 V_89 )
{
return F_55 ( V_88 , ( V_13 int ) V_89 , V_9 ) ;
}
static inline void F_57 ( struct V_64 * V_65 ,
struct V_92 * V_93 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
F_58 ( & V_93 -> V_94 , V_74 -> V_95 ) ;
F_58 ( & V_93 -> V_96 , V_74 -> V_95 ) ;
}
static void F_59 ( struct V_97 * V_98 )
{
struct V_71 * V_71 ;
struct V_23 * V_23 ;
int V_91 ;
V_71 = V_98 -> V_71 ;
V_23 = V_71 -> V_82 -> V_99 ;
F_42 ( V_71 ) ;
V_91 = F_60 ( V_23 , V_71 , 0 ) ;
F_51 ( V_71 ) ;
F_8 ( V_91 ) ;
}
static void F_61 ( struct V_97 * V_98 )
{
struct V_23 * V_23 ;
int V_91 ;
V_23 = V_98 -> V_23 ;
if ( V_23 -> V_100 == V_101 )
F_62 ( V_23 -> V_66 ) ;
else {
V_91 = F_63 ( V_23 , 0 ) ;
F_8 ( V_91 ) ;
}
}
static unsigned long F_64 ( const unsigned long * V_102 ,
unsigned long V_103 , unsigned long V_104 )
{
return F_65 ( V_102 , V_103 , V_104 ) ;
}
static T_5 F_66 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_88 ;
F_67 ( F_68 ( struct V_21 , V_28 ) != 0 ) ;
F_67 ( F_68 ( struct V_21 , V_30 ) != 2 ) ;
F_67 ( F_68 ( struct V_21 , V_32 ) != 4 ) ;
V_88 = ( T_1 ) V_23 -> V_27 << 48 |
( T_1 ) V_25 -> V_29 << 40 |
( T_1 ) V_25 -> V_31 ;
return F_14 ( V_88 ) ;
}
static int F_69 ( struct V_64 * V_65 ,
struct V_97 * V_98 , T_6 * V_105 )
{
struct V_23 * V_23 = V_98 -> V_23 ;
struct V_24 * V_25 = V_24 ( V_23 ) ;
unsigned long V_106 ;
T_1 V_107 , V_1 ;
T_5 V_88 ;
T_2 V_2 ;
int V_83 ;
for ( V_106 = 0 ; ; V_106 ++ ) {
V_106 = F_64 ( V_98 -> V_108 , V_109 , V_106 ) ;
if ( V_106 >= V_60 + V_110 )
return 0 ;
switch ( V_106 ) {
case V_111 :
V_88 = F_66 ( V_23 ) ;
break;
case V_112 :
V_88 = F_14 ( V_25 -> V_63 ) ;
break;
case V_113 :
V_88 = F_14 ( F_23 ( V_23 ) ) ;
break;
case V_110 ... V_110 + V_60 - 1 :
V_88 = F_14 ( V_25 -> V_61 [ V_106 - V_110 ] ) ;
break;
default:
F_19 () ;
}
V_107 = V_101 ;
V_1 = V_23 -> V_100 ;
V_2 = F_2 ( 0 ) ;
V_83 = V_105 ( V_65 , V_107 , V_1 , V_2 , V_106 , V_88 ) ;
if ( V_83 )
return V_83 ;
}
}
static int F_70 ( struct V_64 * V_65 ,
struct V_97 * V_98 , T_6 * V_105 )
{
unsigned long V_106 ;
struct V_71 * V_71 = V_98 -> V_71 ;
T_1 V_107 , V_1 ;
T_5 * V_114 , V_88 ;
T_2 V_2 ;
int V_83 ;
for ( V_106 = 0 ; ; V_106 ++ ) {
V_106 = F_64 ( V_98 -> V_108 , V_109 , V_106 ) ;
if ( V_106 >= V_109 )
return 0 ;
V_107 = V_71 -> V_82 -> V_99 -> V_100 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
V_114 = F_71 ( V_71 , V_115 ) ;
V_88 = V_114 [ V_106 ] ;
F_72 ( V_114 , V_115 ) ;
V_83 = V_105 ( V_65 , V_107 , V_1 , V_2 , V_106 , V_88 ) ;
if ( V_83 )
return V_83 ;
}
}
int F_73 ( struct V_64 * V_65 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_97 * V_98 ;
int V_83 ;
F_74 (block, &super->s_object_alias, alias_list) {
V_83 = V_98 -> V_116 -> V_117 ( V_65 , V_98 , V_118 ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
void F_75 ( struct V_64 * V_65 , struct V_97 * V_98 )
{
F_8 ( ! F_76 ( & V_98 -> V_119 ) ) ;
F_77 ( & V_98 -> V_120 ) ;
F_78 ( V_98 , V_73 ( V_65 ) -> V_121 ) ;
}
static void F_79 ( struct V_64 * V_65 , struct V_97 * V_98 )
{
struct V_23 * V_23 = V_98 -> V_23 ;
V_24 ( V_23 ) -> V_122 = NULL ;
F_75 ( V_65 , V_98 ) ;
}
static void F_80 ( struct V_64 * V_65 ,
struct V_97 * V_98 )
{
F_81 ( V_98 -> V_71 ) ;
V_98 -> V_71 -> V_123 = 0 ;
F_75 ( V_65 , V_98 ) ;
}
struct V_97 * F_82 ( struct V_64 * V_65 ,
T_1 V_107 , T_1 V_1 , T_2 V_2 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_97 * V_98 ;
V_98 = F_83 ( V_74 -> V_121 , V_78 ) ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
F_84 ( & V_98 -> V_120 ) ;
F_84 ( & V_98 -> V_119 ) ;
V_98 -> V_65 = V_65 ;
V_98 -> V_107 = V_107 ;
V_98 -> V_1 = V_1 ;
V_98 -> V_2 = V_2 ;
return V_98 ;
}
static void F_85 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_97 * V_98 ;
if ( V_25 -> V_122 )
return;
V_98 = F_82 ( V_23 -> V_66 , V_101 , V_23 -> V_100 , 0 ) ;
V_98 -> V_23 = V_23 ;
V_25 -> V_122 = V_98 ;
V_98 -> V_116 = & V_124 ;
}
void F_86 ( struct V_71 * V_71 , struct V_97 * V_98 ,
T_5 * V_125 , int V_126 )
{
T_1 V_127 ;
int V_26 , V_128 ;
V_98 -> V_129 = 0 ;
V_98 -> V_130 = 0 ;
V_128 = 0 ;
if ( V_71 -> V_12 < F_6 () ) {
return;
}
if ( V_71 -> V_12 == F_6 () ) {
V_128 = V_3 ;
V_98 -> V_130 = V_3 ;
}
if ( ! V_126 ) {
for ( V_26 = V_128 ; V_26 < V_109 ; V_26 ++ ) {
V_127 = F_12 ( V_125 [ V_26 ] ) ;
if ( V_127 )
V_98 -> V_129 ++ ;
if ( V_127 & V_131 )
V_98 -> V_130 ++ ;
}
}
}
static void F_87 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
struct V_97 * V_98 ;
T_1 V_1 ;
T_2 V_2 ;
if ( F_88 ( V_71 ) )
return;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
V_98 = F_82 ( V_23 -> V_66 , V_23 -> V_100 , V_1 , V_2 ) ;
V_98 -> V_71 = V_71 ;
F_89 ( V_71 ) ;
V_71 -> V_123 = ( unsigned long ) V_98 ;
V_98 -> V_116 = & V_132 ;
}
static void F_90 ( struct V_23 * V_23 , struct V_71 * V_71 ,
int V_126 )
{
struct V_97 * V_98 ;
T_5 * V_125 ;
if ( F_88 ( V_71 ) )
return;
F_87 ( V_23 , V_71 ) ;
V_98 = V_97 ( V_71 ) ;
V_125 = F_71 ( V_71 , V_115 ) ;
F_86 ( V_71 , V_98 , V_125 , V_126 ) ;
F_72 ( V_125 , V_115 ) ;
}
static void F_91 ( struct V_71 * V_71 , int V_12 , T_1 V_127 )
{
struct V_97 * V_98 = V_97 ( V_71 ) ;
T_5 * V_125 ;
T_1 V_133 ;
F_8 ( ! V_98 ) ;
V_125 = F_71 ( V_71 , V_115 ) ;
V_133 = F_12 ( V_125 [ V_12 ] ) ;
V_125 [ V_12 ] = F_14 ( V_127 ) ;
F_72 ( V_125 , V_115 ) ;
F_92 ( V_71 ) ;
V_98 -> V_130 += ! ! ( V_127 & V_131 )
- ! ! ( V_133 & V_131 ) ;
V_98 -> V_129 += ! ! V_127 - ! ! V_133 ;
}
static T_1 F_93 ( struct V_71 * V_71 , int V_12 )
{
T_5 * V_98 ;
T_1 V_127 ;
V_98 = F_71 ( V_71 , V_115 ) ;
V_127 = F_12 ( V_98 [ V_12 ] ) ;
F_72 ( V_98 , V_115 ) ;
return V_127 ;
}
static int F_94 ( struct V_71 * V_71 )
{
F_95 ( V_71 , 0 , V_134 ) ;
return 0 ;
}
static int F_96 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_4 V_12 = V_71 -> V_12 ;
T_1 V_98 ;
V_98 = V_25 -> V_61 [ V_12 ] ;
if ( ! V_98 )
return F_94 ( V_71 ) ;
return F_97 ( V_23 , V_71 , V_98 , V_12 , 0 ) ;
}
static int F_98 ( struct V_23 * V_23 , struct V_71 * V_71 ,
int V_135 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_1 , V_136 = V_25 -> V_61 [ V_137 ] ;
T_2 V_2 , V_138 ;
int V_91 ;
struct V_71 * V_139 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_138 ) ;
if ( ! V_136 )
return F_94 ( V_71 ) ;
if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return F_94 ( V_71 ) ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ;
( V_13 T_3 ) V_2 > ( V_13 T_3 ) V_138 ;
V_2 = F_99 ( V_2 ) ) {
V_139 = F_53 ( V_23 , V_1 , V_2 , V_135 ) ;
if ( ! V_139 )
return - V_140 ;
V_91 = F_97 ( V_23 , V_139 , V_136 , V_1 , V_2 ) ;
if ( V_91 ) {
F_39 ( V_139 ) ;
return V_91 ;
}
V_136 = F_93 ( V_139 , F_56 ( V_1 , F_99 ( V_2 ) ) ) ;
F_54 ( V_139 , V_135 ) ;
if ( ! V_136 )
return F_94 ( V_71 ) ;
}
return F_97 ( V_23 , V_71 , V_136 , V_1 , 0 ) ;
}
static int F_100 ( struct V_23 * V_23 , struct V_71 * V_71 ,
int V_135 )
{
T_4 V_12 = V_71 -> V_12 ;
if ( V_12 < V_3 )
return F_96 ( V_23 , V_71 ) ;
return F_98 ( V_23 , V_71 , V_135 ) ;
}
static int F_101 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_136 = V_25 -> V_61 [ V_137 ] ;
T_2 V_2 ;
int V_91 ;
struct V_71 * V_139 ;
if ( ! V_136 )
return 0 ;
if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return 0 ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ; V_2 != 0 ; V_2 = F_99 ( V_2 ) ) {
V_139 = F_37 ( V_23 , V_1 , V_2 ) ;
if ( ! V_139 )
return - V_140 ;
V_91 = F_97 ( V_23 , V_139 , V_136 , V_1 , V_2 ) ;
if ( V_91 ) {
F_39 ( V_139 ) ;
return V_91 ;
}
V_136 = F_93 ( V_139 , F_56 ( V_1 , F_99 ( V_2 ) ) ) ;
F_39 ( V_139 ) ;
if ( ! V_136 )
return 0 ;
}
return 1 ;
}
int F_102 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_1 < V_3 )
return ! ! V_25 -> V_61 [ V_1 ] ;
return F_101 ( V_23 , V_1 ) ;
}
static T_1 F_103 ( struct V_23 * V_23 , T_1 V_1 , int V_141 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
for (; V_1 < V_3 ; V_1 ++ )
if ( V_141 ^ ( V_25 -> V_61 [ V_1 ] == 0 ) )
return V_1 ;
return V_3 ;
}
static T_1 F_104 ( struct V_23 * V_23 , T_1 V_1 , int V_141 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_5 * V_142 ;
T_1 V_143 , V_136 = V_25 -> V_61 [ V_137 ] ;
T_2 V_2 ;
int V_91 , V_144 ;
struct V_71 * V_71 ;
F_8 ( ! V_136 ) ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ; V_2 != 0 ; V_2 = F_99 ( V_2 ) ) {
V_143 = 1 << ( V_9 * ( ( V_13 T_3 ) V_2 - 1 ) ) ;
V_71 = F_37 ( V_23 , V_1 , V_2 ) ;
if ( ! V_71 )
return V_1 ;
V_91 = F_97 ( V_23 , V_71 , V_136 , V_1 , V_2 ) ;
if ( V_91 ) {
F_39 ( V_71 ) ;
return V_1 ;
}
V_144 = F_56 ( V_1 , F_99 ( V_2 ) ) ;
V_142 = F_71 ( V_71 , V_115 ) ;
while ( V_144 < V_109 ) {
if ( V_141 && ( V_142 [ V_144 ] != 0 ) )
break;
if ( ! V_141 && ! ( F_12 ( V_142 [ V_144 ] ) & V_131 ) )
break;
V_144 ++ ;
V_1 += V_143 ;
V_1 &= ~ ( V_143 - 1 ) ;
}
if ( V_144 >= V_109 ) {
F_72 ( V_142 , V_115 ) ;
F_39 ( V_71 ) ;
return V_1 ;
}
V_136 = F_12 ( V_142 [ V_144 ] ) ;
F_72 ( V_142 , V_115 ) ;
F_39 ( V_71 ) ;
if ( ! V_136 ) {
F_8 ( V_141 ) ;
return V_1 ;
}
}
return V_1 ;
}
T_1 F_105 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_1 < V_3 ) {
V_1 = F_103 ( V_23 , V_1 , 0 ) ;
if ( V_1 < V_3 )
return V_1 ;
}
if ( ! V_25 -> V_61 [ V_137 ] )
return V_1 ;
else if ( V_25 -> V_61 [ V_137 ] & V_131 )
V_1 = F_5 ( V_25 -> V_29 ) ;
else if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return V_1 ;
else {
V_1 = F_104 ( V_23 , V_1 , 0 ) ;
if ( V_1 < F_5 ( V_25 -> V_29 ) )
return V_1 ;
F_106 ( V_1 == F_5 ( V_25 -> V_29 ) ) ;
}
return V_1 ;
}
static T_1 F_107 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_1 < V_3 ) {
V_1 = F_103 ( V_23 , V_1 , 1 ) ;
if ( V_1 < V_3 )
return V_1 ;
}
if ( V_1 < F_5 ( V_25 -> V_29 ) ) {
if ( ! V_25 -> V_61 [ V_137 ] )
V_1 = F_5 ( V_25 -> V_29 ) ;
else
return F_104 ( V_23 , V_1 , 1 ) ;
}
return V_1 ;
}
T_1 F_108 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
T_1 V_91 , V_145 ;
V_91 = F_107 ( V_23 , V_1 ) ;
V_145 = F_23 ( V_23 ) >> V_65 -> V_69 ;
if ( V_91 >= V_145 )
V_91 = F_109 ( V_1 , V_145 ) ;
return V_91 ;
}
static int F_110 ( struct V_24 * V_25 , T_1 V_1 , T_1 V_146 )
{
return F_111 ( V_25 -> V_61 [ V_1 ] ) == V_146 ;
}
static int F_112 ( struct V_23 * V_23 , T_1 V_1 ,
T_1 V_146 , T_1 V_136 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_2 V_2 ;
int V_91 ;
struct V_71 * V_71 ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ; V_2 != 0 ; V_2 = F_99 ( V_2 ) ) {
V_71 = F_47 ( V_23 , V_1 , V_2 ) ;
F_8 ( ! V_71 ) ;
V_91 = F_97 ( V_23 , V_71 , V_136 , V_1 , V_2 ) ;
if ( V_91 ) {
F_52 ( V_71 ) ;
return 0 ;
}
V_136 = F_93 ( V_71 , F_56 ( V_1 , F_99 ( V_2 ) ) ) ;
F_52 ( V_71 ) ;
if ( ! V_136 )
return 0 ;
if ( F_111 ( V_136 ) == V_146 )
return 1 ;
}
return 0 ;
}
static int F_113 ( struct V_23 * V_23 , T_1 V_1 , T_1 V_146 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_136 = V_25 -> V_61 [ V_137 ] ;
if ( ! V_136 )
return 0 ;
if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return 0 ;
if ( F_111 ( V_136 ) == V_146 )
return 1 ;
return F_112 ( V_23 , V_1 , V_146 , V_136 ) ;
}
static int F_114 ( struct V_23 * V_23 , T_1 V_1 , T_1 V_146 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( ( V_23 -> V_46 == 0 ) && F_115 ( & V_23 -> V_147 ) == 1 )
return 0 ;
if ( V_1 < V_3 )
return F_110 ( V_25 , V_1 , V_146 ) ;
return F_113 ( V_23 , V_1 , V_146 ) ;
}
int F_116 ( struct V_64 * V_65 , T_1 V_146 , T_1 V_107 , T_1 V_1 ,
T_7 V_148 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_23 * V_23 ;
int V_91 , V_149 ;
if ( V_107 == - 1 )
return 0 ;
F_117 ( ( T_1 ) ( V_150 ) V_107 != V_107 , V_65 ) ;
V_23 = F_118 ( V_65 , V_107 , & V_149 ) ;
if ( F_119 ( V_23 ) )
goto V_151;
V_91 = F_114 ( V_23 , V_1 , V_146 ) ;
F_120 ( V_23 , V_149 ) ;
if ( V_91 )
return V_91 ;
V_151:
if ( F_121 ( & V_74 -> V_152 . V_96 , V_146 ) )
return 2 ;
return 0 ;
}
int F_122 ( struct V_71 * V_71 )
{
struct V_23 * V_23 = V_71 -> V_82 -> V_99 ;
int V_91 = - V_153 ;
V_91 = F_100 ( V_23 , V_71 , V_87 ) ;
if ( V_91 ) {
F_123 ( V_71 ) ;
F_124 ( V_71 ) ;
} else {
F_92 ( V_71 ) ;
F_125 ( V_71 ) ;
}
F_126 ( V_71 ) ;
return V_91 ;
}
static int F_127 ( struct V_23 * V_23 , int V_70 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
T_1 V_154 = V_74 -> V_155 + V_74 -> V_156
- V_74 -> V_157 - V_74 -> V_158 ;
if ( ! V_70 )
return 0 ;
if ( V_154 < V_70 )
return - V_159 ;
if ( V_154 < V_70 + V_74 -> V_160 &&
! F_128 ( V_161 ) )
return - V_159 ;
return 0 ;
}
int F_129 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
struct V_97 * V_98 = V_97 ( V_71 ) ;
int V_91 ;
if ( V_98 && V_98 -> V_162 )
return 0 ;
F_32 ( V_23 -> V_66 , V_71 , V_163 ) ;
while ( ( V_91 = F_127 ( V_23 , 6 * V_164 ) ) &&
! F_76 ( & V_74 -> V_165 ) ) {
V_98 = F_130 ( V_74 -> V_165 . V_166 ,
struct V_97 , V_120 ) ;
V_98 -> V_116 -> V_167 ( V_98 ) ;
}
if ( ! V_91 ) {
F_87 ( V_23 , V_71 ) ;
V_98 = V_97 ( V_71 ) ;
V_98 -> V_162 += 6 * V_164 ;
V_74 -> V_158 += 6 * V_164 ;
F_131 ( & V_98 -> V_120 , & V_74 -> V_165 ) ;
}
F_35 ( V_23 -> V_66 , V_71 , V_163 ) ;
return V_91 ;
}
static void F_132 ( struct V_23 * V_23 ,
struct V_168 * V_169 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
if ( ! V_169 )
return;
V_24 ( V_23 ) -> V_122 -> V_169 = NULL ;
if ( V_23 -> V_100 != V_101 ) {
F_19 () ;
return;
}
switch ( V_169 -> V_170 ) {
case V_171 :
case V_172 :
F_8 ( V_74 -> V_173 ) ;
V_74 -> V_173 = V_169 -> V_107 ;
break;
case V_174 :
case V_175 :
F_8 ( V_74 -> V_173 != V_169 -> V_107 ) ;
V_74 -> V_173 = 0 ;
F_133 ( V_169 ) ;
break;
case V_176 :
F_8 ( V_74 -> V_177 ) ;
F_8 ( V_74 -> V_178 ) ;
V_74 -> V_177 = V_169 -> V_179 ;
V_74 -> V_178 = V_169 -> V_106 ;
break;
case V_180 :
F_8 ( V_74 -> V_177 != V_169 -> V_179 ) ;
F_8 ( V_74 -> V_178 != V_169 -> V_106 ) ;
V_74 -> V_177 = 0 ;
V_74 -> V_178 = 0 ;
F_133 ( V_169 ) ;
break;
case V_181 :
F_8 ( V_74 -> V_177 ) ;
F_8 ( V_74 -> V_178 ) ;
F_8 ( V_74 -> V_173 ) ;
V_74 -> V_177 = V_169 -> V_179 ;
V_74 -> V_178 = V_169 -> V_106 ;
V_74 -> V_173 = V_169 -> V_107 ;
break;
case V_182 :
F_8 ( V_74 -> V_177 != V_169 -> V_179 ) ;
F_8 ( V_74 -> V_178 != V_169 -> V_106 ) ;
F_8 ( V_74 -> V_173 != V_169 -> V_107 ) ;
V_74 -> V_177 = 0 ;
V_74 -> V_178 = 0 ;
break;
case V_183 :
F_8 ( V_74 -> V_177 ) ;
F_8 ( V_74 -> V_178 ) ;
F_8 ( V_74 -> V_173 != V_169 -> V_107 ) ;
V_74 -> V_173 = 0 ;
F_133 ( V_169 ) ;
break;
default:
F_19 () ;
}
}
static int F_134 ( struct V_23 * V_23 , int V_184 )
{
return F_127 ( V_23 , V_184 * V_164 ) ;
}
static struct V_185 * F_135 ( struct V_23 * V_23 , T_1 V_1 ,
T_2 V_2 , T_1 V_186 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
struct V_185 * V_187 ;
V_187 = F_83 ( V_74 -> V_188 , V_78 ) ;
memset ( V_187 , 0 , sizeof( * V_187 ) ) ;
V_187 -> V_107 = V_23 -> V_100 ;
V_187 -> V_1 = V_1 ;
V_187 -> V_148 = F_136 ( V_23 -> V_100 , V_2 ) ;
V_187 -> V_186 = V_186 & ~ V_131 ;
return V_187 ;
}
static void F_137 ( struct V_23 * V_23 , struct V_185 * V_187 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
F_78 ( V_187 , V_74 -> V_188 ) ;
}
static void F_138 ( struct V_92 * V_93 , T_8 V_189 )
{
int V_83 ;
if ( ! F_139 ( & V_93 -> V_190 , V_189 ) ) {
V_83 = F_140 ( & V_93 -> V_190 , V_189 , ( void * ) 1 ,
V_78 ) ;
F_8 ( V_83 ) ;
V_93 -> V_191 ++ ;
}
}
static void F_141 ( struct V_23 * V_23 , struct V_71 * V_71 ,
struct V_185 * V_187 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
struct V_97 * V_98 = V_97 ( V_71 ) ;
struct V_92 * V_93 = & V_74 -> V_152 ;
if ( F_88 ( V_71 ) ) {
if ( V_98 -> V_108 )
V_74 -> V_192 -= F_142 (
V_98 -> V_108 , V_109 ) ;
F_132 ( V_23 , V_98 -> V_169 ) ;
V_98 -> V_116 -> V_193 ( V_23 -> V_66 , V_98 ) ;
}
if ( V_187 ) {
if ( V_187 -> V_186 )
F_143 ( & V_93 -> V_96 , V_187 -> V_186 , V_187 ,
V_78 ) ;
else
F_143 ( & V_93 -> V_94 , V_187 -> V_194 , V_187 ,
V_78 ) ;
V_74 -> V_157 += V_187 -> V_195 ;
V_74 -> V_156 += V_187 -> V_196 ;
F_138 ( V_93 , V_187 -> V_186 >> V_74 -> V_197 ) ;
F_138 ( V_93 , V_187 -> V_194 >> V_74 -> V_197 ) ;
}
}
static void F_144 ( struct V_64 * V_65 , struct V_97 * V_98 ,
long V_198 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
if ( V_98 -> V_23 && V_98 -> V_23 -> V_100 == V_101 ) {
return;
}
if ( ! F_145 ( V_198 , V_98 -> V_108 ) ) {
F_146 ( V_198 , V_98 -> V_108 ) ;
V_74 -> V_192 ++ ;
}
F_131 ( & V_98 -> V_120 , & V_74 -> V_199 ) ;
}
static void F_147 ( struct V_23 * V_23 , struct V_185 * V_187 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_187 -> V_195 == V_187 -> V_196 )
return;
F_85 ( V_23 ) ;
V_25 -> V_63 += V_187 -> V_195 - V_187 -> V_196 ;
F_24 ( V_23 ) ;
F_144 ( V_23 -> V_66 , V_25 -> V_122 , V_112 ) ;
F_144 ( V_23 -> V_66 , V_25 -> V_122 , V_113 ) ;
}
static int F_148 ( struct V_23 * V_23 , struct V_71 * V_71 ,
struct V_200 * V_201 )
{
struct V_185 * V_187 ;
T_1 V_1 ;
T_2 V_2 ;
int V_130 , V_83 = 0 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
if ( V_201 -> V_146 == 0 )
if ( F_134 ( V_23 , 1 ) )
return - V_159 ;
V_187 = F_135 ( V_23 , V_1 , V_2 , V_201 -> V_146 ) ;
if ( V_201 -> V_202 & V_203 )
V_83 = F_149 ( V_23 , V_71 , V_187 ) ;
if ( V_201 -> V_202 & V_204 )
F_150 ( V_23 , V_187 ) ;
if ( V_83 ) {
F_137 ( V_23 , V_187 ) ;
return V_83 ;
}
F_147 ( V_23 , V_187 ) ;
V_130 = 1 ;
if ( V_2 != 0 ) {
F_90 ( V_23 , V_71 , 0 ) ;
V_130 = V_97 ( V_71 ) -> V_130 == V_109 ;
}
F_141 ( V_23 , V_71 , V_187 ) ;
V_201 -> V_146 = V_187 -> V_194 ;
if ( V_201 -> V_146 && V_130 )
V_201 -> V_146 |= V_131 ;
return 0 ;
}
static int F_151 ( struct V_23 * V_23 , struct V_71 * V_71 ,
long V_202 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_200 V_201 = {
. V_146 = V_25 -> V_61 [ V_71 -> V_12 ] ,
. V_202 = V_202 ,
} ;
int V_83 ;
F_85 ( V_23 ) ;
V_83 = F_148 ( V_23 , V_71 , & V_201 ) ;
if ( V_83 )
return V_83 ;
V_25 -> V_61 [ V_71 -> V_12 ] = V_201 . V_146 ;
F_144 ( V_23 -> V_66 , V_25 -> V_122 ,
V_71 -> V_12 + V_110 ) ;
return 0 ;
}
static int F_152 ( T_1 V_146 , struct V_71 * V_71 )
{
struct V_97 * V_98 = V_97 ( V_71 ) ;
int V_205 , V_206 , V_207 , V_208 ;
V_205 = V_146 == 0 ;
V_206 = V_98 -> V_129 == 0 ;
if ( V_205 != V_206 )
return 1 ;
V_207 = ! ! ( V_146 & V_131 ) ;
V_208 = V_98 -> V_130 == V_109 ;
if ( V_207 != V_208 )
return 1 ;
return 0 ;
}
static int F_153 ( struct V_23 * V_23 , struct V_71 * V_71 ,
struct V_200 * V_209 ,
T_4 V_1 , T_2 V_138 , T_2 V_2 )
{
int V_91 , V_210 = 0 ;
int V_198 = F_56 ( V_1 , F_99 ( V_2 ) ) ;
struct V_71 * V_139 ;
struct V_200 V_211 = {
. V_202 = V_209 -> V_202 ,
} ;
V_139 = F_47 ( V_23 , V_1 , V_2 ) ;
if ( ! V_139 )
return - V_140 ;
if ( V_209 -> V_146 ) {
V_91 = F_97 ( V_23 , V_139 , V_209 -> V_146 , V_1 , V_2 ) ;
if ( V_91 )
goto V_212;
} else if ( ! F_154 ( V_139 ) ) {
V_210 = 1 ;
F_94 ( V_139 ) ;
}
V_211 . V_146 = F_93 ( V_139 , V_198 ) ;
if ( ( V_13 T_3 ) V_2 - 1 > ( V_13 T_3 ) V_138 )
V_91 = F_153 ( V_23 , V_71 , & V_211 , V_1 ,
V_138 , F_99 ( V_2 ) ) ;
else
V_91 = F_148 ( V_23 , V_71 , & V_211 ) ;
if ( V_91 )
goto V_212;
F_90 ( V_23 , V_139 , V_210 ) ;
F_91 ( V_139 , V_198 , V_211 . V_146 ) ;
if ( V_211 . V_146 || V_97 ( V_139 ) -> V_129 )
V_209 -> V_202 |= V_203 ;
if ( ! V_209 -> V_146 || F_152 ( V_209 -> V_146 , V_139 ) )
V_91 = F_148 ( V_23 , V_139 , V_209 ) ;
else
F_144 ( V_23 -> V_66 , V_97 ( V_139 ) , V_198 ) ;
V_212:
F_52 ( V_139 ) ;
return V_91 ;
}
static int F_155 ( struct V_23 * V_23 , struct V_71 * V_71 ,
T_4 V_1 , T_2 V_138 , long V_202 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_200 V_201 = {
. V_146 = V_25 -> V_61 [ V_137 ] ,
. V_202 = V_202 ,
} ;
int V_91 ;
F_85 ( V_23 ) ;
if ( V_25 -> V_29 > ( V_13 T_3 ) V_138 )
V_91 = F_153 ( V_23 , V_71 , & V_201 , V_1 , V_138 ,
F_2 ( V_25 -> V_29 ) ) ;
else
V_91 = F_148 ( V_23 , V_71 , & V_201 ) ;
if ( V_91 )
return V_91 ;
if ( V_25 -> V_61 [ V_137 ] != V_201 . V_146 ) {
V_25 -> V_61 [ V_137 ] = V_201 . V_146 ;
F_144 ( V_23 -> V_66 , V_25 -> V_122 ,
V_137 + V_110 ) ;
}
return V_91 ;
}
void F_156 ( struct V_23 * V_23 , struct V_168 * V_169 )
{
F_85 ( V_23 ) ;
V_24 ( V_23 ) -> V_122 -> V_169 = V_169 ;
}
void F_157 ( struct V_23 * V_23 , struct V_168 * V_169 )
{
struct V_97 * V_98 = V_24 ( V_23 ) -> V_122 ;
if ( V_98 && V_98 -> V_169 )
V_98 -> V_169 = NULL ;
}
static int F_158 ( struct V_23 * V_23 , T_1 V_1 , T_2 V_2 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_3 V_8 = ( V_13 T_3 ) V_2 ;
struct V_71 * V_71 ;
struct V_200 V_201 = {
. V_202 = V_203 ,
} ;
int V_83 ;
F_8 ( V_8 > 5 || V_25 -> V_29 > 5 ) ;
while ( V_8 > V_25 -> V_29 || V_1 >= F_5 ( V_25 -> V_29 ) ) {
V_71 = F_47 ( V_23 , V_3 + 1 ,
F_2 ( V_25 -> V_29 + 1 ) ) ;
if ( ! V_71 )
return - V_140 ;
F_94 ( V_71 ) ;
F_90 ( V_23 , V_71 , 1 ) ;
F_91 ( V_71 , 0 , V_25 -> V_61 [ V_137 ] ) ;
V_83 = F_148 ( V_23 , V_71 , & V_201 ) ;
F_52 ( V_71 ) ;
if ( V_83 )
return V_83 ;
V_25 -> V_61 [ V_137 ] = V_201 . V_146 ;
V_201 . V_146 = 0 ;
V_25 -> V_29 ++ ;
F_144 ( V_23 -> V_66 , V_25 -> V_122 , V_111 ) ;
}
return 0 ;
}
static int F_159 ( struct V_23 * V_23 , struct V_71 * V_71 , long V_202 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
T_4 V_12 = V_71 -> V_12 ;
T_1 V_1 ;
T_2 V_2 ;
int V_83 ;
V_202 |= V_203 | V_204 ;
V_23 -> V_42 = V_23 -> V_44 = V_213 ;
F_9 ( V_12 , & V_1 , & V_2 ) ;
if ( V_97 ( V_71 ) && V_97 ( V_71 ) -> V_162 )
V_74 -> V_158 -= V_97 ( V_71 ) -> V_162 ;
if ( V_12 < V_3 )
return F_151 ( V_23 , V_71 , V_202 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
V_83 = F_158 ( V_23 , V_1 , V_2 ) ;
if ( V_83 )
return V_83 ;
return F_155 ( V_23 , V_71 , V_1 , V_2 , V_202 ) ;
}
int F_60 ( struct V_23 * V_23 , struct V_71 * V_71 , long V_202 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
int V_91 ;
F_32 ( V_65 , V_71 , V_202 & V_163 ) ;
V_91 = F_159 ( V_23 , V_71 , V_202 ) ;
F_35 ( V_65 , V_71 , V_202 & V_163 ) ;
return V_91 ;
}
static int F_160 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
long V_202 = V_204 ;
V_23 -> V_42 = V_23 -> V_44 = V_213 ;
if ( V_71 -> V_12 < V_3 )
return F_151 ( V_23 , V_71 , V_202 ) ;
return F_155 ( V_23 , V_71 , V_71 -> V_12 , 0 , V_202 ) ;
}
int F_161 ( struct V_23 * V_23 , T_4 V_12 ,
struct V_92 * V_92 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_71 * V_71 ;
int V_91 ;
V_71 = F_37 ( V_23 , V_12 , 0 ) ;
if ( ! V_71 )
return - V_140 ;
F_32 ( V_65 , V_71 , 1 ) ;
V_91 = F_160 ( V_23 , V_71 ) ;
F_35 ( V_65 , V_71 , 1 ) ;
F_39 ( V_71 ) ;
return V_91 ;
}
int F_162 ( struct V_23 * V_23 , T_1 V_1 , T_1 V_146 ,
T_7 V_148 , long V_202 )
{
T_2 V_2 = F_163 ( V_148 ) ;
struct V_71 * V_71 ;
int V_83 ;
V_71 = F_47 ( V_23 , V_1 , V_2 ) ;
if ( ! V_71 )
return - V_140 ;
V_83 = F_97 ( V_23 , V_71 , V_146 , V_1 , V_2 ) ;
if ( ! V_83 ) {
if ( V_2 != 0 )
F_90 ( V_23 , V_71 , 0 ) ;
V_83 = F_60 ( V_23 , V_71 , V_202 ) ;
if ( ! V_83 && F_163 ( V_148 ) == 0 ) {
if ( V_23 -> V_100 == V_101 )
F_62 ( V_23 -> V_66 ) ;
else {
V_83 = F_63 ( V_23 , V_202 ) ;
}
}
}
F_52 ( V_71 ) ;
return V_83 ;
}
static int F_164 ( struct V_23 * V_23 , struct V_71 * V_71 ,
T_1 V_146 , struct V_185 * V_187 , T_1 V_103 )
{
T_9 V_214 = V_71 -> V_12 << V_23 -> V_66 -> V_69 ;
T_1 V_1 ;
T_2 V_2 ;
int V_83 ;
if ( V_103 <= V_214 || V_103 - V_214 >= V_215 )
return 0 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
F_8 ( V_2 != 0 ) ;
V_83 = F_97 ( V_23 , V_71 , V_146 , V_1 , V_2 ) ;
if ( V_83 )
return V_83 ;
F_95 ( V_71 , V_103 - V_214 , V_134 ) ;
return F_149 ( V_23 , V_71 , V_187 ) ;
}
static int F_165 ( struct V_23 * V_23 , struct V_71 * V_71 ,
struct V_200 * V_201 , T_1 V_103 )
{
struct V_185 * V_187 ;
T_1 V_1 ;
T_2 V_2 ;
int V_83 = 0 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
F_8 ( V_2 != 0 ) ;
V_187 = F_135 ( V_23 , V_1 , V_2 , V_201 -> V_146 ) ;
V_83 = F_164 ( V_23 , V_71 , V_201 -> V_146 , V_187 , V_103 ) ;
if ( V_83 ) {
F_137 ( V_23 , V_187 ) ;
return V_83 ;
}
F_150 ( V_23 , V_187 ) ;
F_147 ( V_23 , V_187 ) ;
F_141 ( V_23 , V_71 , V_187 ) ;
V_201 -> V_146 = V_187 -> V_194 ;
return 0 ;
}
static int F_166 ( struct V_23 * V_23 , T_1 V_103 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_200 V_201 ;
struct V_71 * V_71 ;
int V_216 ;
int V_83 ;
F_85 ( V_23 ) ;
for ( V_216 = V_3 - 1 ; V_216 >= 0 ; V_216 -- ) {
if ( V_103 > ( V_216 + 1 ) * V_217 )
break;
V_201 . V_146 = V_25 -> V_61 [ V_216 ] ;
if ( ! V_201 . V_146 )
continue;
V_71 = F_47 ( V_23 , V_216 , 0 ) ;
if ( ! V_71 )
return - V_140 ;
V_83 = F_97 ( V_23 , V_71 , V_201 . V_146 , V_216 , 0 ) ;
if ( V_83 ) {
F_52 ( V_71 ) ;
return V_83 ;
}
V_83 = F_165 ( V_23 , V_71 , & V_201 , V_103 ) ;
F_52 ( V_71 ) ;
if ( V_83 )
return V_83 ;
V_25 -> V_61 [ V_216 ] = V_201 . V_146 ;
}
return 0 ;
}
static inline T_1 F_167 ( T_2 V_2 )
{
return V_218 [ ( V_13 T_3 ) V_2 ] ;
}
static inline T_1 F_168 ( T_3 V_2 )
{
return V_218 [ V_2 ] * V_217 ;
}
static inline T_1 F_169 ( T_2 V_2 )
{
return V_219 [ ( V_13 T_3 ) V_2 ] ;
}
static void F_170 ( T_4 V_12 , T_1 * V_1 , T_2 * V_2 )
{
F_9 ( V_12 , V_1 , V_2 ) ;
if ( * V_1 <= F_169 ( F_99 ( * V_2 ) ) )
* V_1 = 0 ;
}
static int F_171 ( struct V_23 * V_23 , struct V_71 * V_139 ,
struct V_200 * V_209 , T_1 V_103 )
{
int V_220 = 0 ;
int V_216 , V_83 = 0 ;
T_1 V_1 , V_221 , V_222 ;
T_2 V_2 ;
struct V_71 * V_71 ;
struct V_200 V_211 = { } ;
F_170 ( V_139 -> V_12 , & V_1 , & V_2 ) ;
V_83 = F_97 ( V_23 , V_139 , V_209 -> V_146 , V_1 , V_2 ) ;
if ( V_83 )
return V_83 ;
for ( V_216 = V_109 - 1 ; V_216 >= 0 ; V_216 -- ) {
V_221 = V_1 + V_216 * F_167 ( F_99 ( V_2 ) ) ;
V_222 = V_221 + F_167 ( F_99 ( V_2 ) ) ;
if ( V_103 > V_222 * V_217 )
break;
V_211 . V_146 = F_111 ( F_93 ( V_139 , V_216 ) ) ;
if ( ! V_211 . V_146 )
continue;
V_71 = F_47 ( V_23 , V_221 , F_99 ( V_2 ) ) ;
if ( ! V_71 )
return - V_140 ;
if ( ( V_13 T_3 ) V_2 > 1 )
V_83 = F_171 ( V_23 , V_71 , & V_211 , V_103 ) ;
else
V_83 = F_165 ( V_23 , V_71 , & V_211 , V_103 ) ;
F_52 ( V_71 ) ;
if ( V_83 )
return V_83 ;
V_220 = 1 ;
F_90 ( V_23 , V_139 , 0 ) ;
F_91 ( V_139 , V_216 , V_211 . V_146 ) ;
}
if ( ! V_220 ) {
F_45 ( L_2 , V_23 -> V_100 , V_139 -> V_12 , V_103 ) ;
return 0 ;
}
V_209 -> V_202 = V_204 ;
if ( V_97 ( V_139 ) -> V_129 )
V_209 -> V_202 |= V_203 ;
return F_148 ( V_23 , V_139 , V_209 ) ;
}
static int F_172 ( struct V_23 * V_23 , T_1 V_103 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_200 V_201 = {
. V_146 = V_25 -> V_61 [ V_137 ] ,
} ;
struct V_71 * V_71 ;
int V_83 ;
F_85 ( V_23 ) ;
if ( ! V_201 . V_146 )
return 0 ;
V_71 = F_47 ( V_23 , 0 , F_2 ( V_25 -> V_29 ) ) ;
if ( ! V_71 )
return - V_140 ;
V_83 = F_171 ( V_23 , V_71 , & V_201 , V_103 ) ;
F_52 ( V_71 ) ;
if ( V_83 )
return V_83 ;
if ( V_25 -> V_61 [ V_137 ] != V_201 . V_146 )
V_25 -> V_61 [ V_137 ] = V_201 . V_146 ;
return 0 ;
}
static int F_173 ( struct V_23 * V_23 , T_1 V_103 )
{
int V_91 ;
if ( V_103 >= F_168 ( V_24 ( V_23 ) -> V_29 ) )
return 0 ;
V_91 = F_172 ( V_23 , V_103 ) ;
if ( V_91 )
return V_91 ;
return F_166 ( V_23 , V_103 ) ;
}
int F_174 ( struct V_23 * V_23 , T_1 V_223 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
T_1 V_103 = F_23 ( V_23 ) ;
int V_83 = 0 ;
V_103 = F_25 ( V_103 , V_224 ) ;
while ( V_103 > V_223 ) {
if ( V_103 > V_224 )
V_103 -= V_224 ;
else
V_103 = 0 ;
if ( V_103 < V_223 )
V_103 = V_223 ;
F_32 ( V_65 , NULL , 1 ) ;
V_83 = F_173 ( V_23 , V_103 ) ;
if ( ! V_83 )
V_83 = F_63 ( V_23 , 0 ) ;
F_35 ( V_65 , NULL , 1 ) ;
}
if ( ! V_83 )
V_83 = F_175 ( V_23 , V_223 ) ;
F_4 ( V_83 ) ;
return V_83 ;
}
static void F_176 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_97 * V_98 = V_97 ( V_71 ) ;
if ( ! V_98 )
return;
F_177 ( L_3 ,
V_98 -> V_107 , V_98 -> V_1 , V_98 -> V_2 ) ;
F_8 ( V_25 -> V_122 ) ;
V_98 -> V_116 = & V_124 ;
V_98 -> V_23 = V_23 ;
V_25 -> V_122 = V_98 ;
V_98 -> V_71 = NULL ;
V_71 -> V_123 = 0 ;
F_81 ( V_71 ) ;
}
static void F_178 ( struct V_71 * V_71 , struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_97 * V_98 = V_25 -> V_122 ;
if ( ! V_98 )
return;
F_177 ( L_4 ,
V_98 -> V_107 , V_98 -> V_1 , V_98 -> V_2 ) ;
F_8 ( F_88 ( V_71 ) ) ;
V_98 -> V_116 = & V_132 ;
V_98 -> V_71 = V_71 ;
V_71 -> V_123 = ( unsigned long ) V_98 ;
F_89 ( V_71 ) ;
V_98 -> V_23 = NULL ;
V_25 -> V_122 = NULL ;
}
int F_179 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_23 * V_225 = V_74 -> V_226 ;
struct V_71 * V_71 ;
struct V_21 * V_22 ;
T_1 V_107 = V_23 -> V_100 ;
if ( V_107 << V_65 -> V_69 > F_23 ( V_225 ) )
return - V_227 ;
if ( ! F_102 ( V_225 , V_107 ) )
return - V_227 ;
V_71 = F_180 ( V_225 -> V_77 , V_107 ,
( V_228 * ) V_229 , NULL ) ;
if ( F_119 ( V_71 ) )
return F_181 ( V_71 ) ;
V_22 = F_71 ( V_71 , V_115 ) ;
F_15 ( V_22 , V_23 ) ;
F_72 ( V_22 , V_115 ) ;
F_176 ( V_23 , V_71 ) ;
F_41 ( V_71 ) ;
return 0 ;
}
static struct V_71 * F_182 ( struct V_23 * V_23 )
{
struct V_23 * V_225 = V_73 ( V_23 -> V_66 ) -> V_226 ;
struct V_21 * V_22 ;
struct V_71 * V_71 ;
F_8 ( V_23 -> V_100 == V_101 ) ;
V_71 = F_47 ( V_225 , V_23 -> V_100 , 0 ) ;
if ( ! V_71 )
return NULL ;
V_22 = F_71 ( V_71 , V_115 ) ;
F_20 ( V_23 , V_22 ) ;
F_72 ( V_22 , V_115 ) ;
F_178 ( V_71 , V_23 ) ;
return V_71 ;
}
static int F_183 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_23 * V_225 = V_73 ( V_65 ) -> V_226 ;
T_9 V_103 = ( V_23 -> V_100 + 1 ) << V_23 -> V_66 -> V_69 ;
struct V_71 * V_71 ;
int V_83 ;
F_8 ( V_23 -> V_100 == V_101 ) ;
if ( F_23 ( V_225 ) < V_103 )
F_184 ( V_225 , V_103 ) ;
V_71 = F_182 ( V_23 ) ;
if ( ! V_71 )
return - V_140 ;
V_83 = F_60 ( V_225 , V_71 , 0 ) ;
if ( V_83 )
F_176 ( V_23 , V_71 ) ;
F_52 ( V_71 ) ;
return V_83 ;
}
static void F_185 ( struct V_64 * V_65 , T_8 V_189 ,
int V_230 ,
void (* F_186)( struct V_231 * , long ) ,
long V_232 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_23 * V_23 ;
struct V_71 * V_71 ;
struct V_231 * V_233 ;
T_4 V_234 ;
int V_198 ;
V_234 = V_189 >> ( V_65 -> V_69 - 3 ) ;
V_198 = V_189 & ( ( V_65 -> V_235 >> 3 ) - 1 ) ;
V_23 = V_74 -> V_236 ;
V_71 = F_47 ( V_23 , V_234 , 0 ) ;
F_8 ( ! V_71 ) ;
if ( ! F_154 ( V_71 ) )
F_100 ( V_23 , V_71 , V_237 ) ;
if ( V_230 )
F_90 ( V_23 , V_71 , 0 ) ;
V_233 = F_71 ( V_71 , V_115 ) ;
F_186 ( V_233 + V_198 , V_232 ) ;
if ( V_230 ) {
F_144 ( V_65 , V_97 ( V_71 ) , V_198 ) ;
F_8 ( ( int ) F_17 ( V_233 [ V_198 ] . V_238 ) > V_74 -> V_239 ) ;
}
F_72 ( V_233 , V_115 ) ;
F_52 ( V_71 ) ;
}
static void F_187 ( struct V_231 * V_233 , long V_240 )
{
struct V_231 * V_223 = ( void * ) V_240 ;
* V_223 = * V_233 ;
}
void F_188 ( struct V_64 * V_65 , T_8 V_189 ,
struct V_231 * V_233 )
{
F_185 ( V_65 , V_189 , 0 , F_187 , ( long ) V_233 ) ;
}
static void F_189 ( struct V_231 * V_233 , long V_143 )
{
T_8 V_238 ;
V_238 = F_17 ( V_233 -> V_238 ) ;
V_238 += V_143 ;
V_233 -> V_238 = F_22 ( V_238 ) ;
}
void F_190 ( struct V_64 * V_65 , T_1 V_146 , int V_143 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
T_8 V_189 = V_146 >> V_74 -> V_197 ;
if ( ! V_143 )
return;
F_185 ( V_65 , V_189 , 1 , F_189 , V_143 ) ;
}
static void F_191 ( struct V_231 * V_233 , long V_241 )
{
V_233 -> V_241 = F_22 ( V_241 ) ;
}
void F_192 ( struct V_64 * V_65 , T_8 V_189 , T_8 V_242 ,
T_7 V_148 )
{
T_8 V_241 = V_242 << 4 | ( V_13 T_3 ) V_148 ;
F_185 ( V_65 , V_189 , 1 , F_191 , V_241 ) ;
}
static void F_193 ( struct V_231 * V_233 , long V_243 )
{
V_233 -> V_238 = F_22 ( V_244 ) ;
}
void F_194 ( struct V_64 * V_65 , T_8 V_189 )
{
F_185 ( V_65 , V_189 , 1 , F_193 , 0 ) ;
}
static void F_195 ( struct V_231 * V_233 ,
long V_241 )
{
V_233 -> V_238 = 0 ;
V_233 -> V_241 = F_22 ( V_241 ) ;
}
void F_196 ( struct V_64 * V_65 , T_8 V_189 , T_8 V_242 )
{
T_8 V_241 = V_242 << 4 ;
F_185 ( V_65 , V_189 , 1 , F_195 ,
V_241 ) ;
}
int F_63 ( struct V_23 * V_23 , long V_202 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
int V_91 ;
F_32 ( V_65 , NULL , V_202 & V_163 ) ;
V_91 = F_183 ( V_23 ) ;
F_35 ( V_65 , NULL , V_202 & V_163 ) ;
return V_91 ;
}
static int F_197 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_23 * V_225 = V_73 ( V_65 ) -> V_226 ;
struct V_71 * V_71 ;
int V_91 ;
V_71 = F_47 ( V_225 , V_23 -> V_100 , 0 ) ;
if ( ! V_71 )
return - V_140 ;
F_178 ( V_71 , V_23 ) ;
F_32 ( V_65 , V_71 , 1 ) ;
V_91 = F_160 ( V_225 , V_71 ) ;
F_35 ( V_65 , V_71 , 1 ) ;
F_52 ( V_71 ) ;
return V_91 ;
}
void F_198 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_97 * V_98 = V_25 -> V_122 ;
struct V_71 * V_71 ;
if ( ! V_23 -> V_46 ) {
if ( ! ( V_25 -> V_31 & V_245 ) ) {
V_25 -> V_31 |= V_245 ;
if ( F_23 ( V_23 ) > 0 )
F_174 ( V_23 , 0 ) ;
F_197 ( V_23 ) ;
}
}
F_199 ( & V_23 -> V_246 , 0 ) ;
F_200 ( V_23 ) ;
F_8 ( V_23 -> V_247 & V_248 && V_23 -> V_46 ) ;
if ( ! V_98 )
return;
if ( ( V_73 ( V_65 ) -> V_249 & V_250 ) ) {
V_98 -> V_116 -> V_193 ( V_23 -> V_66 , V_98 ) ;
return;
}
F_8 ( V_23 -> V_100 < V_251 ) ;
V_71 = F_182 ( V_23 ) ;
F_8 ( ! V_71 ) ;
F_52 ( V_71 ) ;
}
void F_201 ( struct V_97 * V_98 )
{
struct V_23 * V_23 ;
struct V_71 * V_71 ;
int V_83 , V_149 ;
V_23 = F_118 ( V_98 -> V_65 , V_98 -> V_107 , & V_149 ) ;
V_71 = F_47 ( V_23 , V_98 -> V_1 , V_98 -> V_2 ) ;
V_83 = F_122 ( V_71 ) ;
F_8 ( V_83 ) ;
F_8 ( ! F_88 ( V_71 ) ) ;
F_8 ( V_97 ( V_71 ) != V_98 ) ;
V_83 = F_159 ( V_23 , V_71 , 0 ) ;
F_8 ( V_83 ) ;
F_8 ( F_88 ( V_71 ) || V_71 -> V_123 ) ;
F_52 ( V_71 ) ;
F_120 ( V_23 , V_149 ) ;
}
int F_202 ( struct V_23 * V_23 , const void * V_252 , T_10 V_253 ,
T_9 V_1 , long V_202 , struct V_92 * V_92 )
{
T_9 V_106 = V_1 << V_23 -> V_66 -> V_69 ;
int V_83 ;
struct V_71 * V_71 ;
void * V_254 ;
F_8 ( V_106 & ( V_217 - 1 ) ) ;
F_8 ( V_253 > V_217 ) ;
V_71 = F_47 ( V_23 , V_1 , 0 ) ;
if ( ! V_71 )
return - V_140 ;
V_254 = F_71 ( V_71 , V_115 ) ;
memcpy ( V_254 , V_252 , V_253 ) ;
F_126 ( V_71 ) ;
F_72 ( V_254 , V_115 ) ;
if ( F_23 ( V_23 ) < V_106 + V_217 )
F_184 ( V_23 , V_106 + V_217 ) ;
V_83 = F_60 ( V_23 , V_71 , V_202 ) ;
F_52 ( V_71 ) ;
return V_83 ;
}
int F_203 ( struct V_64 * V_65 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_23 * V_23 ;
V_23 = F_204 ( V_65 , V_255 ) ;
if ( F_119 ( V_23 ) )
return F_181 ( V_23 ) ;
V_74 -> V_236 = V_23 ;
return 0 ;
}
int F_205 ( struct V_64 * V_65 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
int V_256 = 3 * V_74 -> V_257 ;
F_84 ( & V_74 -> V_199 ) ;
F_84 ( & V_74 -> V_165 ) ;
F_206 ( & V_74 -> V_76 ) ;
V_74 -> V_121 = F_207 ( V_256 ,
sizeof( struct V_97 ) ) ;
V_74 -> V_188 = F_207 ( V_256 ,
sizeof( struct V_185 ) ) ;
return 0 ;
}
void F_208 ( struct V_64 * V_65 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
F_209 ( V_74 -> V_121 ) ;
F_209 ( V_74 -> V_188 ) ;
}
