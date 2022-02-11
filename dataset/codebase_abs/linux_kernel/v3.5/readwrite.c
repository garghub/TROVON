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
F_19 ( V_23 , F_17 ( V_22 -> V_46 ) ) ;
V_23 -> V_47 = F_17 ( V_22 -> V_48 ) ;
switch ( V_23 -> V_27 & V_49 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_23 -> V_54 = F_12 ( V_22 -> V_55 [ 0 ] ) ;
break;
case V_56 :
case V_57 :
case V_58 :
for ( V_26 = 0 ; V_26 < V_59 ; V_26 ++ )
V_25 -> V_60 [ V_26 ] = F_12 ( V_22 -> V_55 [ V_26 ] ) ;
break;
default:
F_20 () ;
}
}
static void F_21 ( struct V_23 * V_23 , struct V_21 * V_22 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
int V_26 ;
V_22 -> V_28 = F_22 ( V_23 -> V_27 ) ;
V_22 -> V_30 = V_25 -> V_29 ;
V_22 -> V_61 = 0 ;
V_22 -> V_32 = F_23 ( V_25 -> V_31 ) ;
V_22 -> V_34 = F_23 ( V_23 -> V_33 ) ;
V_22 -> V_36 = F_23 ( V_23 -> V_35 ) ;
V_22 -> V_38 = F_14 ( F_24 ( V_23 ) ) ;
V_22 -> V_39 = F_14 ( V_25 -> V_62 ) ;
V_22 -> V_41 = F_13 ( V_23 -> V_40 ) ;
V_22 -> V_43 = F_13 ( V_23 -> V_42 ) ;
V_22 -> V_45 = F_13 ( V_23 -> V_44 ) ;
V_22 -> V_46 = F_23 ( V_23 -> V_63 ) ;
V_22 -> V_48 = F_23 ( V_23 -> V_47 ) ;
switch ( V_23 -> V_27 & V_49 ) {
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_22 -> V_55 [ 0 ] = F_14 ( V_23 -> V_54 ) ;
break;
case V_56 :
case V_57 :
case V_58 :
for ( V_26 = 0 ; V_26 < V_59 ; V_26 ++ )
V_22 -> V_55 [ V_26 ] = F_14 ( V_25 -> V_60 [ V_26 ] ) ;
break;
default:
F_20 () ;
}
}
static void F_25 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_24 * V_25 = V_24 ( V_23 ) ;
V_23 -> V_67 = V_68 ;
if ( V_25 -> V_62 >> V_65 -> V_69 < V_68 )
V_23 -> V_67 = F_26 ( V_25 -> V_62 , 512 ) >> 9 ;
}
void F_18 ( struct V_23 * V_23 , T_1 V_70 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
V_25 -> V_62 = V_70 ;
F_25 ( V_23 ) ;
}
static void F_27 ( struct V_64 * V_65 , struct V_71 * V_71 , int V_72 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
F_8 ( ! F_28 ( V_71 ) ) ;
if ( V_72 ) {
F_8 ( F_29 ( V_71 ) ) ;
F_30 ( V_71 ) ;
} else {
if ( F_29 ( V_71 ) )
V_74 -> V_75 ++ ;
else
F_30 ( V_71 ) ;
}
}
static void F_31 ( struct V_64 * V_65 , struct V_71 * V_71 , int V_72 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
F_8 ( ! F_28 ( V_71 ) ) ;
if ( V_72 )
F_32 ( V_71 ) ;
else {
F_8 ( ! F_29 ( V_71 ) ) ;
if ( V_74 -> V_75 )
V_74 -> V_75 -- ;
else
F_32 ( V_71 ) ;
}
}
void F_33 ( struct V_64 * V_65 , struct V_71 * V_71 , int V_72 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
if ( V_71 )
F_27 ( V_65 , V_71 , V_72 ) ;
if ( V_72 ) {
F_34 ( & V_74 -> V_76 ) ;
F_35 ( V_65 ) ;
}
}
void F_36 ( struct V_64 * V_65 , struct V_71 * V_71 , int V_72 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
if ( V_71 )
F_31 ( V_65 , V_71 , V_72 ) ;
if ( V_72 )
F_37 ( & V_74 -> V_76 ) ;
}
static struct V_71 * F_38 ( struct V_23 * V_23 , T_1 V_1 ,
T_2 V_2 )
{
return F_39 ( V_23 -> V_77 ,
F_7 ( V_1 , V_2 ) , V_78 ) ;
}
static void F_40 ( struct V_71 * V_71 )
{
F_41 ( V_71 ) ;
F_42 ( V_71 ) ;
}
static void F_43 ( struct V_71 * V_71 )
{
int V_79 = 0 ;
while ( F_44 ( ! F_45 ( V_71 ) ) ) {
if ( V_79 ++ > 0x1000 ) {
F_46 ( V_80 L_1 , & V_79 ) ;
F_20 () ;
}
if ( F_29 ( V_71 ) ) {
break;
}
F_47 () ;
}
F_8 ( ! F_28 ( V_71 ) ) ;
}
static struct V_71 * F_48 ( struct V_23 * V_23 , T_1 V_1 ,
T_2 V_2 )
{
struct V_81 * V_82 = V_23 -> V_77 ;
T_4 V_12 = F_7 ( V_1 , V_2 ) ;
struct V_71 * V_71 ;
int V_83 ;
V_84:
V_71 = F_49 ( V_82 , V_12 ) ;
if ( ! V_71 ) {
V_71 = F_50 ( V_78 ) ;
if ( ! V_71 )
return NULL ;
V_83 = F_51 ( V_71 , V_82 , V_12 , V_78 ) ;
if ( F_44 ( V_83 ) ) {
F_42 ( V_71 ) ;
if ( V_83 == - V_85 )
goto V_84;
return NULL ;
}
} else F_43 ( V_71 ) ;
F_8 ( ! F_28 ( V_71 ) ) ;
return V_71 ;
}
static void F_52 ( struct V_71 * V_71 )
{
if ( ! F_29 ( V_71 ) )
F_41 ( V_71 ) ;
}
static void F_53 ( struct V_71 * V_71 )
{
F_52 ( V_71 ) ;
F_42 ( V_71 ) ;
}
static struct V_71 * F_54 ( struct V_23 * V_23 , T_1 V_1 , T_2 V_2 ,
int V_86 )
{
if ( V_86 == V_87 )
return F_38 ( V_23 , V_1 , V_2 ) ;
else
return F_48 ( V_23 , V_1 , V_2 ) ;
}
static void F_55 ( struct V_71 * V_71 , int V_86 )
{
if ( V_86 == V_87 )
F_40 ( V_71 ) ;
else
F_53 ( V_71 ) ;
}
static unsigned long F_56 ( T_1 V_88 , int V_89 , int V_90 )
{
T_1 V_91 = V_88 ;
V_91 >>= V_89 * V_90 ;
V_91 <<= 64 - V_90 ;
V_91 >>= 64 - V_90 ;
return V_91 ;
}
static unsigned long F_57 ( T_1 V_88 , T_2 V_89 )
{
return F_56 ( V_88 , ( V_13 int ) V_89 , V_9 ) ;
}
static inline void F_58 ( struct V_64 * V_65 ,
struct V_92 * V_93 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
F_59 ( & V_93 -> V_94 , V_74 -> V_95 ) ;
F_59 ( & V_93 -> V_96 , V_74 -> V_95 ) ;
}
static void F_60 ( struct V_97 * V_98 )
{
struct V_71 * V_71 ;
struct V_23 * V_23 ;
int V_91 ;
V_71 = V_98 -> V_71 ;
V_23 = V_71 -> V_82 -> V_99 ;
F_43 ( V_71 ) ;
V_91 = F_61 ( V_23 , V_71 , 0 ) ;
F_52 ( V_71 ) ;
F_8 ( V_91 ) ;
}
static void F_62 ( struct V_97 * V_98 )
{
struct V_23 * V_23 ;
int V_91 ;
V_23 = V_98 -> V_23 ;
if ( V_23 -> V_100 == V_101 )
F_63 ( V_23 -> V_66 ) ;
else {
V_91 = F_64 ( V_23 , NULL , 0 ) ;
F_8 ( V_91 ) ;
}
}
static unsigned long F_65 ( const unsigned long * V_102 ,
unsigned long V_103 , unsigned long V_104 )
{
return F_66 ( V_102 , V_103 , V_104 ) ;
}
static T_5 F_67 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_88 ;
F_68 ( F_69 ( struct V_21 , V_28 ) != 0 ) ;
F_68 ( F_69 ( struct V_21 , V_30 ) != 2 ) ;
F_68 ( F_69 ( struct V_21 , V_32 ) != 4 ) ;
V_88 = ( T_1 ) V_23 -> V_27 << 48 |
( T_1 ) V_25 -> V_29 << 40 |
( T_1 ) V_25 -> V_31 ;
return F_14 ( V_88 ) ;
}
static int F_70 ( struct V_64 * V_65 ,
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
V_106 = F_65 ( V_98 -> V_108 , V_109 , V_106 ) ;
if ( V_106 >= V_59 + V_110 )
return 0 ;
switch ( V_106 ) {
case V_111 :
V_88 = F_67 ( V_23 ) ;
break;
case V_112 :
V_88 = F_14 ( V_25 -> V_62 ) ;
break;
case V_113 :
V_88 = F_14 ( F_24 ( V_23 ) ) ;
break;
case V_110 ... V_110 + V_59 - 1 :
V_88 = F_14 ( V_25 -> V_60 [ V_106 - V_110 ] ) ;
break;
default:
F_20 () ;
}
V_107 = V_101 ;
V_1 = V_23 -> V_100 ;
V_2 = F_2 ( 0 ) ;
V_83 = V_105 ( V_65 , V_107 , V_1 , V_2 , V_106 , V_88 ) ;
if ( V_83 )
return V_83 ;
}
}
static int F_71 ( struct V_64 * V_65 ,
struct V_97 * V_98 , T_6 * V_105 )
{
unsigned long V_106 ;
struct V_71 * V_71 = V_98 -> V_71 ;
T_1 V_107 , V_1 ;
T_5 * V_114 , V_88 ;
T_2 V_2 ;
int V_83 ;
for ( V_106 = 0 ; ; V_106 ++ ) {
V_106 = F_65 ( V_98 -> V_108 , V_109 , V_106 ) ;
if ( V_106 >= V_109 )
return 0 ;
V_107 = V_71 -> V_82 -> V_99 -> V_100 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
V_114 = F_72 ( V_71 ) ;
V_88 = V_114 [ V_106 ] ;
F_73 ( V_114 ) ;
V_83 = V_105 ( V_65 , V_107 , V_1 , V_2 , V_106 , V_88 ) ;
if ( V_83 )
return V_83 ;
}
}
int F_74 ( struct V_64 * V_65 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_97 * V_98 ;
int V_83 ;
F_75 (block, &super->s_object_alias, alias_list) {
V_83 = V_98 -> V_115 -> V_116 ( V_65 , V_98 , V_117 ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
void F_76 ( struct V_64 * V_65 , struct V_97 * V_98 )
{
F_8 ( ! F_77 ( & V_98 -> V_118 ) ) ;
F_78 ( & V_98 -> V_119 ) ;
F_79 ( V_98 , V_73 ( V_65 ) -> V_120 ) ;
}
static void F_80 ( struct V_64 * V_65 , struct V_97 * V_98 )
{
struct V_23 * V_23 = V_98 -> V_23 ;
V_24 ( V_23 ) -> V_121 = NULL ;
F_76 ( V_65 , V_98 ) ;
}
static void F_81 ( struct V_64 * V_65 ,
struct V_97 * V_98 )
{
struct V_71 * V_71 = V_98 -> V_71 ;
if ( F_82 ( V_71 ) ) {
F_83 ( V_71 ) ;
F_42 ( V_71 ) ;
F_84 ( V_71 , 0 ) ;
}
F_76 ( V_65 , V_98 ) ;
}
struct V_97 * F_85 ( struct V_64 * V_65 ,
T_1 V_107 , T_1 V_1 , T_2 V_2 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_97 * V_98 ;
V_98 = F_86 ( V_74 -> V_120 , V_78 ) ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
F_87 ( & V_98 -> V_119 ) ;
F_87 ( & V_98 -> V_118 ) ;
V_98 -> V_65 = V_65 ;
V_98 -> V_107 = V_107 ;
V_98 -> V_1 = V_1 ;
V_98 -> V_2 = V_2 ;
return V_98 ;
}
static void F_88 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_97 * V_98 ;
if ( V_25 -> V_121 )
return;
V_98 = F_85 ( V_23 -> V_66 , V_101 , V_23 -> V_100 , 0 ) ;
V_98 -> V_23 = V_23 ;
V_25 -> V_121 = V_98 ;
V_98 -> V_115 = & V_122 ;
}
void F_89 ( struct V_71 * V_71 , struct V_97 * V_98 ,
T_5 * V_123 , int V_124 )
{
T_1 V_125 ;
int V_26 , V_126 ;
V_98 -> V_127 = 0 ;
V_98 -> V_128 = 0 ;
V_126 = 0 ;
if ( V_71 -> V_12 < F_6 () ) {
return;
}
if ( V_71 -> V_12 == F_6 () ) {
V_126 = V_3 ;
V_98 -> V_128 = V_3 ;
}
if ( ! V_124 ) {
for ( V_26 = V_126 ; V_26 < V_109 ; V_26 ++ ) {
V_125 = F_12 ( V_123 [ V_26 ] ) ;
if ( V_125 )
V_98 -> V_127 ++ ;
if ( V_125 & V_129 )
V_98 -> V_128 ++ ;
}
}
}
static void F_90 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
struct V_97 * V_98 ;
T_1 V_1 ;
T_2 V_2 ;
if ( F_82 ( V_71 ) )
return;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
V_98 = F_85 ( V_23 -> V_66 , V_23 -> V_100 , V_1 , V_2 ) ;
V_98 -> V_71 = V_71 ;
F_91 ( V_71 ) ;
F_92 ( V_71 ) ;
F_84 ( V_71 , ( unsigned long ) V_98 ) ;
V_98 -> V_115 = & V_130 ;
}
static void F_93 ( struct V_23 * V_23 , struct V_71 * V_71 ,
int V_124 )
{
struct V_97 * V_98 ;
T_5 * V_123 ;
if ( F_82 ( V_71 ) )
return;
F_90 ( V_23 , V_71 ) ;
V_98 = V_97 ( V_71 ) ;
V_123 = F_72 ( V_71 ) ;
F_89 ( V_71 , V_98 , V_123 , V_124 ) ;
F_73 ( V_123 ) ;
}
static void F_94 ( struct V_71 * V_71 , int V_12 , T_1 V_125 )
{
struct V_97 * V_98 = V_97 ( V_71 ) ;
T_5 * V_123 ;
T_1 V_131 ;
F_8 ( ! V_98 ) ;
V_123 = F_72 ( V_71 ) ;
V_131 = F_12 ( V_123 [ V_12 ] ) ;
V_123 [ V_12 ] = F_14 ( V_125 ) ;
F_73 ( V_123 ) ;
F_95 ( V_71 ) ;
V_98 -> V_128 += ! ! ( V_125 & V_129 )
- ! ! ( V_131 & V_129 ) ;
V_98 -> V_127 += ! ! V_125 - ! ! V_131 ;
}
static T_1 F_96 ( struct V_71 * V_71 , int V_12 )
{
T_5 * V_98 ;
T_1 V_125 ;
V_98 = F_72 ( V_71 ) ;
V_125 = F_12 ( V_98 [ V_12 ] ) ;
F_73 ( V_98 ) ;
return V_125 ;
}
static int F_97 ( struct V_71 * V_71 )
{
F_98 ( V_71 , 0 , V_132 ) ;
return 0 ;
}
static int F_99 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_4 V_12 = V_71 -> V_12 ;
T_1 V_98 ;
V_98 = V_25 -> V_60 [ V_12 ] ;
if ( ! V_98 )
return F_97 ( V_71 ) ;
return F_100 ( V_23 , V_71 , V_98 , V_12 , 0 ) ;
}
static int F_101 ( struct V_23 * V_23 , struct V_71 * V_71 ,
int V_133 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_1 , V_134 = V_25 -> V_60 [ V_135 ] ;
T_2 V_2 , V_136 ;
int V_91 ;
struct V_71 * V_137 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_136 ) ;
if ( ! V_134 )
return F_97 ( V_71 ) ;
if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return F_97 ( V_71 ) ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ;
( V_13 T_3 ) V_2 > ( V_13 T_3 ) V_136 ;
V_2 = F_102 ( V_2 ) ) {
V_137 = F_54 ( V_23 , V_1 , V_2 , V_133 ) ;
if ( ! V_137 )
return - V_138 ;
V_91 = F_100 ( V_23 , V_137 , V_134 , V_1 , V_2 ) ;
if ( V_91 ) {
F_40 ( V_137 ) ;
return V_91 ;
}
V_134 = F_96 ( V_137 , F_57 ( V_1 , F_102 ( V_2 ) ) ) ;
F_55 ( V_137 , V_133 ) ;
if ( ! V_134 )
return F_97 ( V_71 ) ;
}
return F_100 ( V_23 , V_71 , V_134 , V_1 , 0 ) ;
}
static int F_103 ( struct V_23 * V_23 , struct V_71 * V_71 ,
int V_133 )
{
T_4 V_12 = V_71 -> V_12 ;
if ( V_12 < V_3 )
return F_99 ( V_23 , V_71 ) ;
return F_101 ( V_23 , V_71 , V_133 ) ;
}
static int F_104 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_134 = V_25 -> V_60 [ V_135 ] ;
T_2 V_2 ;
int V_91 ;
struct V_71 * V_137 ;
if ( ! V_134 )
return 0 ;
if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return 0 ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ; V_2 != 0 ; V_2 = F_102 ( V_2 ) ) {
V_137 = F_38 ( V_23 , V_1 , V_2 ) ;
if ( ! V_137 )
return - V_138 ;
V_91 = F_100 ( V_23 , V_137 , V_134 , V_1 , V_2 ) ;
if ( V_91 ) {
F_40 ( V_137 ) ;
return V_91 ;
}
V_134 = F_96 ( V_137 , F_57 ( V_1 , F_102 ( V_2 ) ) ) ;
F_40 ( V_137 ) ;
if ( ! V_134 )
return 0 ;
}
return 1 ;
}
int F_105 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_1 < V_3 )
return ! ! V_25 -> V_60 [ V_1 ] ;
return F_104 ( V_23 , V_1 ) ;
}
static T_1 F_106 ( struct V_23 * V_23 , T_1 V_1 , int V_139 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
for (; V_1 < V_3 ; V_1 ++ )
if ( V_139 ^ ( V_25 -> V_60 [ V_1 ] == 0 ) )
return V_1 ;
return V_3 ;
}
static T_1 F_107 ( struct V_23 * V_23 , T_1 V_1 , int V_139 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_5 * V_140 ;
T_1 V_141 , V_134 = V_25 -> V_60 [ V_135 ] ;
T_2 V_2 ;
int V_91 , V_142 ;
struct V_71 * V_71 ;
F_8 ( ! V_134 ) ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ; V_2 != 0 ; V_2 = F_102 ( V_2 ) ) {
V_141 = 1 << ( V_9 * ( ( V_13 T_3 ) V_2 - 1 ) ) ;
V_71 = F_38 ( V_23 , V_1 , V_2 ) ;
if ( ! V_71 )
return V_1 ;
V_91 = F_100 ( V_23 , V_71 , V_134 , V_1 , V_2 ) ;
if ( V_91 ) {
F_40 ( V_71 ) ;
return V_1 ;
}
V_142 = F_57 ( V_1 , F_102 ( V_2 ) ) ;
V_140 = F_72 ( V_71 ) ;
while ( V_142 < V_109 ) {
if ( V_139 && ( V_140 [ V_142 ] != 0 ) )
break;
if ( ! V_139 && ! ( F_12 ( V_140 [ V_142 ] ) & V_129 ) )
break;
V_142 ++ ;
V_1 += V_141 ;
V_1 &= ~ ( V_141 - 1 ) ;
}
if ( V_142 >= V_109 ) {
F_73 ( V_140 ) ;
F_40 ( V_71 ) ;
return V_1 ;
}
V_134 = F_12 ( V_140 [ V_142 ] ) ;
F_73 ( V_140 ) ;
F_40 ( V_71 ) ;
if ( ! V_134 ) {
F_8 ( V_139 ) ;
return V_1 ;
}
}
return V_1 ;
}
T_1 F_108 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_1 < V_3 ) {
V_1 = F_106 ( V_23 , V_1 , 0 ) ;
if ( V_1 < V_3 )
return V_1 ;
}
if ( ! V_25 -> V_60 [ V_135 ] )
return V_1 ;
else if ( V_25 -> V_60 [ V_135 ] & V_129 )
V_1 = F_5 ( V_25 -> V_29 ) ;
else if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return V_1 ;
else {
V_1 = F_107 ( V_23 , V_1 , 0 ) ;
if ( V_1 < F_5 ( V_25 -> V_29 ) )
return V_1 ;
F_109 ( V_1 == F_5 ( V_25 -> V_29 ) ) ;
}
return V_1 ;
}
static T_1 F_110 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_1 < V_3 ) {
V_1 = F_106 ( V_23 , V_1 , 1 ) ;
if ( V_1 < V_3 )
return V_1 ;
}
if ( V_1 < F_5 ( V_25 -> V_29 ) ) {
if ( ! V_25 -> V_60 [ V_135 ] )
V_1 = F_5 ( V_25 -> V_29 ) ;
else
return F_107 ( V_23 , V_1 , 1 ) ;
}
return V_1 ;
}
T_1 F_111 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
T_1 V_91 , V_143 ;
V_91 = F_110 ( V_23 , V_1 ) ;
V_143 = F_24 ( V_23 ) >> V_65 -> V_69 ;
if ( V_91 >= V_143 )
V_91 = F_112 ( V_1 , V_143 ) ;
return V_91 ;
}
static int F_113 ( struct V_24 * V_25 , T_1 V_1 , T_1 V_144 )
{
return F_114 ( V_25 -> V_60 [ V_1 ] ) == V_144 ;
}
static int F_115 ( struct V_23 * V_23 , T_1 V_1 ,
T_1 V_144 , T_1 V_134 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_2 V_2 ;
int V_91 ;
struct V_71 * V_71 ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ; V_2 != 0 ; V_2 = F_102 ( V_2 ) ) {
V_71 = F_48 ( V_23 , V_1 , V_2 ) ;
F_8 ( ! V_71 ) ;
V_91 = F_100 ( V_23 , V_71 , V_134 , V_1 , V_2 ) ;
if ( V_91 ) {
F_53 ( V_71 ) ;
return 0 ;
}
V_134 = F_96 ( V_71 , F_57 ( V_1 , F_102 ( V_2 ) ) ) ;
F_53 ( V_71 ) ;
if ( ! V_134 )
return 0 ;
if ( F_114 ( V_134 ) == V_144 )
return 1 ;
}
return 0 ;
}
static int F_116 ( struct V_23 * V_23 , T_1 V_1 , T_1 V_144 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_134 = V_25 -> V_60 [ V_135 ] ;
if ( ! V_134 )
return 0 ;
if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return 0 ;
if ( F_114 ( V_134 ) == V_144 )
return 1 ;
return F_115 ( V_23 , V_1 , V_144 , V_134 ) ;
}
static int F_117 ( struct V_23 * V_23 , T_1 V_1 , T_1 V_144 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( ( V_23 -> V_63 == 0 ) && F_118 ( & V_23 -> V_145 ) == 1 )
return 0 ;
if ( V_1 < V_3 )
return F_113 ( V_25 , V_1 , V_144 ) ;
return F_116 ( V_23 , V_1 , V_144 ) ;
}
int F_119 ( struct V_64 * V_65 , T_1 V_144 , T_1 V_107 , T_1 V_1 ,
T_7 V_146 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_23 * V_23 ;
int V_91 , V_147 ;
if ( V_107 == - 1 )
return 0 ;
F_120 ( ( T_1 ) ( V_148 ) V_107 != V_107 , V_65 ) ;
V_23 = F_121 ( V_65 , V_107 , & V_147 ) ;
if ( F_122 ( V_23 ) )
goto V_149;
V_91 = F_117 ( V_23 , V_1 , V_144 ) ;
F_123 ( V_23 , V_147 ) ;
if ( V_91 )
return V_91 ;
V_149:
if ( F_124 ( & V_74 -> V_150 . V_96 , V_144 ) )
return 2 ;
return 0 ;
}
int F_125 ( struct V_71 * V_71 )
{
struct V_23 * V_23 = V_71 -> V_82 -> V_99 ;
int V_91 = - V_151 ;
V_91 = F_103 ( V_23 , V_71 , V_87 ) ;
if ( V_91 ) {
F_126 ( V_71 ) ;
F_127 ( V_71 ) ;
} else {
F_95 ( V_71 ) ;
F_128 ( V_71 ) ;
}
F_129 ( V_71 ) ;
return V_91 ;
}
static int F_130 ( struct V_23 * V_23 , int V_70 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
T_1 V_152 = V_74 -> V_153 + V_74 -> V_154
- V_74 -> V_155 - V_74 -> V_156 ;
if ( ! V_70 )
return 0 ;
if ( V_152 < V_70 )
return - V_157 ;
if ( V_152 < V_70 + V_74 -> V_158 &&
! F_131 ( V_159 ) )
return - V_157 ;
return 0 ;
}
int F_132 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
struct V_97 * V_98 = V_97 ( V_71 ) ;
int V_91 ;
if ( V_98 && V_98 -> V_160 )
return 0 ;
F_33 ( V_23 -> V_66 , V_71 , V_161 ) ;
while ( ( V_91 = F_130 ( V_23 , 6 * V_162 ) ) &&
! F_77 ( & V_74 -> V_163 ) ) {
V_98 = F_133 ( V_74 -> V_163 . V_164 ,
struct V_97 , V_119 ) ;
V_98 -> V_115 -> V_165 ( V_98 ) ;
}
if ( ! V_91 ) {
F_90 ( V_23 , V_71 ) ;
V_98 = V_97 ( V_71 ) ;
V_98 -> V_160 += 6 * V_162 ;
V_74 -> V_156 += 6 * V_162 ;
F_134 ( & V_98 -> V_119 , & V_74 -> V_163 ) ;
}
F_36 ( V_23 -> V_66 , V_71 , V_161 ) ;
return V_91 ;
}
static void F_135 ( struct V_23 * V_23 ,
struct V_166 * V_167 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
if ( ! V_167 )
return;
V_24 ( V_23 ) -> V_121 -> V_167 = NULL ;
if ( V_23 -> V_100 != V_101 ) {
F_20 () ;
return;
}
switch ( V_167 -> V_168 ) {
case V_169 :
case V_170 :
F_8 ( V_74 -> V_171 ) ;
V_74 -> V_171 = V_167 -> V_107 ;
break;
case V_172 :
case V_173 :
F_8 ( V_74 -> V_171 != V_167 -> V_107 ) ;
V_74 -> V_171 = 0 ;
F_136 ( V_167 ) ;
break;
case V_174 :
F_8 ( V_74 -> V_175 ) ;
F_8 ( V_74 -> V_176 ) ;
V_74 -> V_175 = V_167 -> V_177 ;
V_74 -> V_176 = V_167 -> V_106 ;
break;
case V_178 :
F_8 ( V_74 -> V_175 != V_167 -> V_177 ) ;
F_8 ( V_74 -> V_176 != V_167 -> V_106 ) ;
V_74 -> V_175 = 0 ;
V_74 -> V_176 = 0 ;
F_136 ( V_167 ) ;
break;
case V_179 :
F_8 ( V_74 -> V_175 ) ;
F_8 ( V_74 -> V_176 ) ;
F_8 ( V_74 -> V_171 ) ;
V_74 -> V_175 = V_167 -> V_177 ;
V_74 -> V_176 = V_167 -> V_106 ;
V_74 -> V_171 = V_167 -> V_107 ;
break;
case V_180 :
F_8 ( V_74 -> V_175 != V_167 -> V_177 ) ;
F_8 ( V_74 -> V_176 != V_167 -> V_106 ) ;
F_8 ( V_74 -> V_171 != V_167 -> V_107 ) ;
V_74 -> V_175 = 0 ;
V_74 -> V_176 = 0 ;
break;
case V_181 :
F_8 ( V_74 -> V_175 ) ;
F_8 ( V_74 -> V_176 ) ;
F_8 ( V_74 -> V_171 != V_167 -> V_107 ) ;
V_74 -> V_171 = 0 ;
F_136 ( V_167 ) ;
break;
default:
F_20 () ;
}
}
static int F_137 ( struct V_23 * V_23 , int V_182 )
{
return F_130 ( V_23 , V_182 * V_162 ) ;
}
static struct V_183 * F_138 ( struct V_23 * V_23 , T_1 V_1 ,
T_2 V_2 , T_1 V_184 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
struct V_183 * V_185 ;
V_185 = F_86 ( V_74 -> V_186 , V_78 ) ;
memset ( V_185 , 0 , sizeof( * V_185 ) ) ;
V_185 -> V_107 = V_23 -> V_100 ;
V_185 -> V_1 = V_1 ;
V_185 -> V_146 = F_139 ( V_23 -> V_100 , V_2 ) ;
V_185 -> V_184 = V_184 & ~ V_129 ;
return V_185 ;
}
static void F_140 ( struct V_23 * V_23 , struct V_183 * V_185 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
F_79 ( V_185 , V_74 -> V_186 ) ;
}
static void F_141 ( struct V_92 * V_93 , T_8 V_187 )
{
int V_83 ;
if ( ! F_142 ( & V_93 -> V_188 , V_187 ) ) {
V_83 = F_143 ( & V_93 -> V_188 , V_187 , ( void * ) 1 ,
V_78 ) ;
F_8 ( V_83 ) ;
V_93 -> V_189 ++ ;
}
}
static void F_144 ( struct V_23 * V_23 , struct V_71 * V_71 ,
struct V_183 * V_185 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
struct V_97 * V_98 = V_97 ( V_71 ) ;
struct V_92 * V_93 = & V_74 -> V_150 ;
if ( F_82 ( V_71 ) ) {
if ( V_98 -> V_108 )
V_74 -> V_190 -= F_145 (
V_98 -> V_108 , V_109 ) ;
F_135 ( V_23 , V_98 -> V_167 ) ;
V_98 -> V_115 -> V_191 ( V_23 -> V_66 , V_98 ) ;
}
if ( V_185 ) {
if ( V_185 -> V_184 )
F_146 ( & V_93 -> V_96 , V_185 -> V_184 , V_185 ,
V_78 ) ;
else
F_146 ( & V_93 -> V_94 , V_185 -> V_192 , V_185 ,
V_78 ) ;
V_74 -> V_155 += V_185 -> V_193 ;
V_74 -> V_154 += V_185 -> V_194 ;
F_141 ( V_93 , V_185 -> V_184 >> V_74 -> V_195 ) ;
F_141 ( V_93 , V_185 -> V_192 >> V_74 -> V_195 ) ;
}
}
static void F_147 ( struct V_64 * V_65 , struct V_97 * V_98 ,
long V_196 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
if ( V_98 -> V_23 && V_98 -> V_23 -> V_100 == V_101 ) {
return;
}
if ( ! F_148 ( V_196 , V_98 -> V_108 ) ) {
F_149 ( V_196 , V_98 -> V_108 ) ;
V_74 -> V_190 ++ ;
}
F_134 ( & V_98 -> V_119 , & V_74 -> V_197 ) ;
}
static void F_150 ( struct V_23 * V_23 , struct V_183 * V_185 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_185 -> V_193 == V_185 -> V_194 )
return;
F_88 ( V_23 ) ;
V_25 -> V_62 += V_185 -> V_193 - V_185 -> V_194 ;
F_25 ( V_23 ) ;
F_147 ( V_23 -> V_66 , V_25 -> V_121 , V_112 ) ;
F_147 ( V_23 -> V_66 , V_25 -> V_121 , V_113 ) ;
}
static int F_151 ( struct V_23 * V_23 , struct V_71 * V_71 ,
struct V_198 * V_199 )
{
struct V_183 * V_185 ;
T_1 V_1 ;
T_2 V_2 ;
int V_128 , V_83 = 0 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
if ( V_199 -> V_144 == 0 )
if ( F_137 ( V_23 , 1 ) )
return - V_157 ;
V_185 = F_138 ( V_23 , V_1 , V_2 , V_199 -> V_144 ) ;
if ( V_199 -> V_200 & V_201 )
V_83 = F_152 ( V_23 , V_71 , V_185 ) ;
if ( V_199 -> V_200 & V_202 )
F_153 ( V_23 , V_185 ) ;
if ( V_83 ) {
F_140 ( V_23 , V_185 ) ;
return V_83 ;
}
F_150 ( V_23 , V_185 ) ;
V_128 = 1 ;
if ( V_2 != 0 ) {
F_93 ( V_23 , V_71 , 0 ) ;
V_128 = V_97 ( V_71 ) -> V_128 == V_109 ;
}
F_144 ( V_23 , V_71 , V_185 ) ;
V_199 -> V_144 = V_185 -> V_192 ;
if ( V_199 -> V_144 && V_128 )
V_199 -> V_144 |= V_129 ;
return 0 ;
}
static int F_154 ( struct V_23 * V_23 , struct V_71 * V_71 ,
long V_200 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_198 V_199 = {
. V_144 = V_25 -> V_60 [ V_71 -> V_12 ] ,
. V_200 = V_200 ,
} ;
int V_83 ;
F_88 ( V_23 ) ;
V_83 = F_151 ( V_23 , V_71 , & V_199 ) ;
if ( V_83 )
return V_83 ;
V_25 -> V_60 [ V_71 -> V_12 ] = V_199 . V_144 ;
F_147 ( V_23 -> V_66 , V_25 -> V_121 ,
V_71 -> V_12 + V_110 ) ;
return 0 ;
}
static int F_155 ( T_1 V_144 , struct V_71 * V_71 )
{
struct V_97 * V_98 = V_97 ( V_71 ) ;
int V_203 , V_204 , V_205 , V_206 ;
V_203 = V_144 == 0 ;
V_204 = V_98 -> V_127 == 0 ;
if ( V_203 != V_204 )
return 1 ;
V_205 = ! ! ( V_144 & V_129 ) ;
V_206 = V_98 -> V_128 == V_109 ;
if ( V_205 != V_206 )
return 1 ;
return 0 ;
}
static int F_156 ( struct V_23 * V_23 , struct V_71 * V_71 ,
struct V_198 * V_207 ,
T_4 V_1 , T_2 V_136 , T_2 V_2 )
{
int V_91 , V_208 = 0 ;
int V_196 = F_57 ( V_1 , F_102 ( V_2 ) ) ;
struct V_71 * V_137 ;
struct V_198 V_209 = {
. V_200 = V_207 -> V_200 ,
} ;
V_137 = F_48 ( V_23 , V_1 , V_2 ) ;
if ( ! V_137 )
return - V_138 ;
if ( V_207 -> V_144 ) {
V_91 = F_100 ( V_23 , V_137 , V_207 -> V_144 , V_1 , V_2 ) ;
if ( V_91 )
goto V_210;
} else if ( ! F_157 ( V_137 ) ) {
V_208 = 1 ;
F_97 ( V_137 ) ;
}
V_209 . V_144 = F_96 ( V_137 , V_196 ) ;
if ( ( V_13 T_3 ) V_2 - 1 > ( V_13 T_3 ) V_136 )
V_91 = F_156 ( V_23 , V_71 , & V_209 , V_1 ,
V_136 , F_102 ( V_2 ) ) ;
else
V_91 = F_151 ( V_23 , V_71 , & V_209 ) ;
if ( V_91 )
goto V_210;
F_93 ( V_23 , V_137 , V_208 ) ;
F_94 ( V_137 , V_196 , V_209 . V_144 ) ;
if ( V_209 . V_144 || V_97 ( V_137 ) -> V_127 )
V_207 -> V_200 |= V_201 ;
if ( ! V_207 -> V_144 || F_155 ( V_207 -> V_144 , V_137 ) )
V_91 = F_151 ( V_23 , V_137 , V_207 ) ;
else
F_147 ( V_23 -> V_66 , V_97 ( V_137 ) , V_196 ) ;
V_210:
F_53 ( V_137 ) ;
return V_91 ;
}
static int F_158 ( struct V_23 * V_23 , struct V_71 * V_71 ,
T_4 V_1 , T_2 V_136 , long V_200 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_198 V_199 = {
. V_144 = V_25 -> V_60 [ V_135 ] ,
. V_200 = V_200 ,
} ;
int V_91 ;
F_88 ( V_23 ) ;
if ( V_25 -> V_29 > ( V_13 T_3 ) V_136 )
V_91 = F_156 ( V_23 , V_71 , & V_199 , V_1 , V_136 ,
F_2 ( V_25 -> V_29 ) ) ;
else
V_91 = F_151 ( V_23 , V_71 , & V_199 ) ;
if ( V_91 )
return V_91 ;
if ( V_25 -> V_60 [ V_135 ] != V_199 . V_144 ) {
V_25 -> V_60 [ V_135 ] = V_199 . V_144 ;
F_147 ( V_23 -> V_66 , V_25 -> V_121 ,
V_135 + V_110 ) ;
}
return V_91 ;
}
void F_159 ( struct V_23 * V_23 , struct V_166 * V_167 )
{
F_88 ( V_23 ) ;
V_24 ( V_23 ) -> V_121 -> V_167 = V_167 ;
}
void F_160 ( struct V_23 * V_23 , struct V_166 * V_167 )
{
struct V_97 * V_98 = V_24 ( V_23 ) -> V_121 ;
if ( V_98 && V_98 -> V_167 )
V_98 -> V_167 = NULL ;
}
static int F_161 ( struct V_23 * V_23 , T_1 V_1 , T_2 V_2 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_3 V_8 = ( V_13 T_3 ) V_2 ;
struct V_71 * V_71 ;
struct V_198 V_199 = {
. V_200 = V_201 ,
} ;
int V_83 ;
F_8 ( V_8 > 5 || V_25 -> V_29 > 5 ) ;
while ( V_8 > V_25 -> V_29 || V_1 >= F_5 ( V_25 -> V_29 ) ) {
V_71 = F_48 ( V_23 , V_3 + 1 ,
F_2 ( V_25 -> V_29 + 1 ) ) ;
if ( ! V_71 )
return - V_138 ;
F_97 ( V_71 ) ;
F_93 ( V_23 , V_71 , 1 ) ;
F_94 ( V_71 , 0 , V_25 -> V_60 [ V_135 ] ) ;
V_83 = F_151 ( V_23 , V_71 , & V_199 ) ;
F_53 ( V_71 ) ;
if ( V_83 )
return V_83 ;
V_25 -> V_60 [ V_135 ] = V_199 . V_144 ;
V_199 . V_144 = 0 ;
V_25 -> V_29 ++ ;
F_147 ( V_23 -> V_66 , V_25 -> V_121 , V_111 ) ;
}
return 0 ;
}
static int F_162 ( struct V_23 * V_23 , struct V_71 * V_71 , long V_200 )
{
struct V_73 * V_74 = V_73 ( V_23 -> V_66 ) ;
T_4 V_12 = V_71 -> V_12 ;
T_1 V_1 ;
T_2 V_2 ;
int V_83 ;
V_200 |= V_201 | V_202 ;
V_23 -> V_42 = V_23 -> V_44 = V_211 ;
F_9 ( V_12 , & V_1 , & V_2 ) ;
if ( V_97 ( V_71 ) && V_97 ( V_71 ) -> V_160 )
V_74 -> V_156 -= V_97 ( V_71 ) -> V_160 ;
if ( V_12 < V_3 )
return F_154 ( V_23 , V_71 , V_200 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
V_83 = F_161 ( V_23 , V_1 , V_2 ) ;
if ( V_83 )
return V_83 ;
return F_158 ( V_23 , V_71 , V_1 , V_2 , V_200 ) ;
}
int F_61 ( struct V_23 * V_23 , struct V_71 * V_71 , long V_200 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
int V_91 ;
F_33 ( V_65 , V_71 , V_200 & V_161 ) ;
V_91 = F_162 ( V_23 , V_71 , V_200 ) ;
F_36 ( V_65 , V_71 , V_200 & V_161 ) ;
return V_91 ;
}
static int F_163 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
long V_200 = V_202 ;
int V_83 ;
V_23 -> V_42 = V_23 -> V_44 = V_211 ;
if ( V_71 -> V_12 < V_3 )
return F_154 ( V_23 , V_71 , V_200 ) ;
V_83 = F_161 ( V_23 , V_71 -> V_12 , 0 ) ;
if ( V_83 )
return V_83 ;
return F_158 ( V_23 , V_71 , V_71 -> V_12 , 0 , V_200 ) ;
}
int F_164 ( struct V_23 * V_23 , T_4 V_12 ,
struct V_92 * V_92 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_71 * V_71 ;
int V_91 ;
V_71 = F_38 ( V_23 , V_12 , 0 ) ;
if ( ! V_71 )
return - V_138 ;
F_33 ( V_65 , V_71 , 1 ) ;
V_91 = F_163 ( V_23 , V_71 ) ;
F_36 ( V_65 , V_71 , 1 ) ;
F_40 ( V_71 ) ;
return V_91 ;
}
int F_165 ( struct V_23 * V_23 , T_1 V_1 , T_1 V_144 ,
T_7 V_146 , long V_200 )
{
T_2 V_2 = F_166 ( V_146 ) ;
struct V_71 * V_71 ;
int V_83 ;
V_71 = F_48 ( V_23 , V_1 , V_2 ) ;
if ( ! V_71 )
return - V_138 ;
V_83 = F_100 ( V_23 , V_71 , V_144 , V_1 , V_2 ) ;
if ( ! V_83 ) {
if ( V_2 != 0 )
F_93 ( V_23 , V_71 , 0 ) ;
V_83 = F_61 ( V_23 , V_71 , V_200 ) ;
if ( ! V_83 && F_166 ( V_146 ) == 0 ) {
if ( V_23 -> V_100 == V_101 )
F_63 ( V_23 -> V_66 ) ;
else {
V_83 = F_64 ( V_23 , V_71 , V_200 ) ;
}
}
}
F_53 ( V_71 ) ;
return V_83 ;
}
static int F_167 ( struct V_23 * V_23 , struct V_71 * V_71 ,
T_1 V_144 , struct V_183 * V_185 , T_1 V_103 )
{
T_9 V_212 = V_71 -> V_12 << V_23 -> V_66 -> V_69 ;
T_1 V_1 ;
T_2 V_2 ;
int V_83 ;
if ( V_103 <= V_212 || V_103 - V_212 >= V_213 )
return 0 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
F_8 ( V_2 != 0 ) ;
V_83 = F_100 ( V_23 , V_71 , V_144 , V_1 , V_2 ) ;
if ( V_83 )
return V_83 ;
F_98 ( V_71 , V_103 - V_212 , V_132 ) ;
return F_152 ( V_23 , V_71 , V_185 ) ;
}
static int F_168 ( struct V_23 * V_23 , struct V_71 * V_71 ,
struct V_198 * V_199 , T_1 V_103 )
{
struct V_183 * V_185 ;
T_1 V_1 ;
T_2 V_2 ;
int V_83 = 0 ;
F_9 ( V_71 -> V_12 , & V_1 , & V_2 ) ;
F_8 ( V_2 != 0 ) ;
V_185 = F_138 ( V_23 , V_1 , V_2 , V_199 -> V_144 ) ;
V_83 = F_167 ( V_23 , V_71 , V_199 -> V_144 , V_185 , V_103 ) ;
if ( V_83 ) {
F_140 ( V_23 , V_185 ) ;
return V_83 ;
}
F_153 ( V_23 , V_185 ) ;
F_150 ( V_23 , V_185 ) ;
F_144 ( V_23 , V_71 , V_185 ) ;
V_199 -> V_144 = V_185 -> V_192 ;
return 0 ;
}
static int F_169 ( struct V_23 * V_23 , T_1 V_103 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_198 V_199 ;
struct V_71 * V_71 ;
int V_214 ;
int V_83 ;
F_88 ( V_23 ) ;
for ( V_214 = V_3 - 1 ; V_214 >= 0 ; V_214 -- ) {
if ( V_103 > ( V_214 + 1 ) * V_215 )
break;
V_199 . V_144 = V_25 -> V_60 [ V_214 ] ;
if ( ! V_199 . V_144 )
continue;
V_71 = F_48 ( V_23 , V_214 , 0 ) ;
if ( ! V_71 )
return - V_138 ;
V_83 = F_100 ( V_23 , V_71 , V_199 . V_144 , V_214 , 0 ) ;
if ( V_83 ) {
F_53 ( V_71 ) ;
return V_83 ;
}
V_83 = F_168 ( V_23 , V_71 , & V_199 , V_103 ) ;
F_53 ( V_71 ) ;
if ( V_83 )
return V_83 ;
V_25 -> V_60 [ V_214 ] = V_199 . V_144 ;
}
return 0 ;
}
static inline T_1 F_170 ( T_2 V_2 )
{
return V_216 [ ( V_13 T_3 ) V_2 ] ;
}
static inline T_1 F_171 ( T_3 V_2 )
{
return V_216 [ V_2 ] * V_215 ;
}
static inline T_1 F_172 ( T_2 V_2 )
{
return V_217 [ ( V_13 T_3 ) V_2 ] ;
}
static void F_173 ( T_4 V_12 , T_1 * V_1 , T_2 * V_2 )
{
F_9 ( V_12 , V_1 , V_2 ) ;
if ( * V_1 <= F_172 ( F_102 ( * V_2 ) ) )
* V_1 = 0 ;
}
static int F_174 ( struct V_23 * V_23 , struct V_71 * V_137 ,
struct V_198 * V_207 , T_1 V_103 )
{
int V_218 = 0 ;
int V_214 , V_83 = 0 ;
T_1 V_1 , V_219 , V_220 ;
T_2 V_2 ;
struct V_71 * V_71 ;
struct V_198 V_209 = { } ;
F_173 ( V_137 -> V_12 , & V_1 , & V_2 ) ;
V_83 = F_100 ( V_23 , V_137 , V_207 -> V_144 , V_1 , V_2 ) ;
if ( V_83 )
return V_83 ;
for ( V_214 = V_109 - 1 ; V_214 >= 0 ; V_214 -- ) {
V_219 = V_1 + V_214 * F_170 ( F_102 ( V_2 ) ) ;
V_220 = V_219 + F_170 ( F_102 ( V_2 ) ) ;
if ( V_103 > V_220 * V_215 )
break;
V_209 . V_144 = F_114 ( F_96 ( V_137 , V_214 ) ) ;
if ( ! V_209 . V_144 )
continue;
V_71 = F_48 ( V_23 , V_219 , F_102 ( V_2 ) ) ;
if ( ! V_71 )
return - V_138 ;
if ( ( V_13 T_3 ) V_2 > 1 )
V_83 = F_174 ( V_23 , V_71 , & V_209 , V_103 ) ;
else
V_83 = F_168 ( V_23 , V_71 , & V_209 , V_103 ) ;
F_53 ( V_71 ) ;
if ( V_83 )
return V_83 ;
V_218 = 1 ;
F_93 ( V_23 , V_137 , 0 ) ;
F_94 ( V_137 , V_214 , V_209 . V_144 ) ;
}
if ( ! V_218 ) {
F_46 ( L_2 , V_23 -> V_100 , V_137 -> V_12 , V_103 ) ;
return 0 ;
}
V_207 -> V_200 = V_202 ;
if ( V_97 ( V_137 ) -> V_127 )
V_207 -> V_200 |= V_201 ;
return F_151 ( V_23 , V_137 , V_207 ) ;
}
static int F_175 ( struct V_23 * V_23 , T_1 V_103 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_198 V_199 = {
. V_144 = V_25 -> V_60 [ V_135 ] ,
} ;
struct V_71 * V_71 ;
int V_83 ;
F_88 ( V_23 ) ;
if ( ! V_199 . V_144 )
return 0 ;
V_71 = F_48 ( V_23 , 0 , F_2 ( V_25 -> V_29 ) ) ;
if ( ! V_71 )
return - V_138 ;
V_83 = F_174 ( V_23 , V_71 , & V_199 , V_103 ) ;
F_53 ( V_71 ) ;
if ( V_83 )
return V_83 ;
if ( V_25 -> V_60 [ V_135 ] != V_199 . V_144 )
V_25 -> V_60 [ V_135 ] = V_199 . V_144 ;
return 0 ;
}
static int F_176 ( struct V_23 * V_23 , T_1 V_103 )
{
int V_91 ;
if ( V_103 >= F_171 ( V_24 ( V_23 ) -> V_29 ) )
return 0 ;
V_91 = F_175 ( V_23 , V_103 ) ;
if ( V_91 )
return V_91 ;
return F_169 ( V_23 , V_103 ) ;
}
int F_177 ( struct V_23 * V_23 , T_1 V_221 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
T_1 V_103 = F_24 ( V_23 ) ;
int V_83 = 0 ;
V_103 = F_26 ( V_103 , V_222 ) ;
while ( V_103 > V_221 ) {
if ( V_103 > V_222 )
V_103 -= V_222 ;
else
V_103 = 0 ;
if ( V_103 < V_221 )
V_103 = V_221 ;
F_33 ( V_65 , NULL , 1 ) ;
V_83 = F_176 ( V_23 , V_103 ) ;
if ( ! V_83 )
V_83 = F_64 ( V_23 , NULL , 0 ) ;
F_36 ( V_65 , NULL , 1 ) ;
}
if ( ! V_83 )
V_83 = F_178 ( V_23 , V_221 ) ;
F_4 ( V_83 ) ;
return V_83 ;
}
static void F_179 ( struct V_23 * V_23 , struct V_71 * V_71 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_97 * V_98 = V_97 ( V_71 ) ;
if ( ! V_98 )
return;
F_180 ( L_3 ,
V_98 -> V_107 , V_98 -> V_1 , V_98 -> V_2 ) ;
F_8 ( V_25 -> V_121 ) ;
V_98 -> V_115 = & V_122 ;
V_98 -> V_23 = V_23 ;
V_25 -> V_121 = V_98 ;
V_98 -> V_71 = NULL ;
if ( F_82 ( V_71 ) ) {
F_83 ( V_71 ) ;
F_42 ( V_71 ) ;
F_84 ( V_71 , 0 ) ;
}
}
static void F_181 ( struct V_71 * V_71 , struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_97 * V_98 = V_25 -> V_121 ;
if ( ! V_98 )
return;
F_180 ( L_4 ,
V_98 -> V_107 , V_98 -> V_1 , V_98 -> V_2 ) ;
F_8 ( F_82 ( V_71 ) ) ;
V_98 -> V_115 = & V_130 ;
V_98 -> V_71 = V_71 ;
if ( ! F_82 ( V_71 ) ) {
F_91 ( V_71 ) ;
F_92 ( V_71 ) ;
F_84 ( V_71 , ( unsigned long ) V_98 ) ;
}
V_98 -> V_23 = NULL ;
V_25 -> V_121 = NULL ;
}
int F_182 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_23 * V_223 = V_74 -> V_224 ;
struct V_71 * V_71 ;
struct V_21 * V_22 ;
T_1 V_107 = V_23 -> V_100 ;
if ( V_107 << V_65 -> V_69 > F_24 ( V_223 ) )
return - V_225 ;
if ( ! F_105 ( V_223 , V_107 ) )
return - V_225 ;
V_71 = F_183 ( V_223 -> V_77 , V_107 ,
( V_226 * ) V_227 , NULL ) ;
if ( F_122 ( V_71 ) )
return F_184 ( V_71 ) ;
V_22 = F_72 ( V_71 ) ;
F_15 ( V_22 , V_23 ) ;
F_73 ( V_22 ) ;
F_179 ( V_23 , V_71 ) ;
F_42 ( V_71 ) ;
return 0 ;
}
static struct V_71 * F_185 ( struct V_23 * V_23 )
{
struct V_23 * V_223 = V_73 ( V_23 -> V_66 ) -> V_224 ;
struct V_21 * V_22 ;
struct V_71 * V_71 ;
F_8 ( V_23 -> V_100 == V_101 ) ;
V_71 = F_48 ( V_223 , V_23 -> V_100 , 0 ) ;
if ( ! V_71 )
return NULL ;
V_22 = F_72 ( V_71 ) ;
F_21 ( V_23 , V_22 ) ;
F_73 ( V_22 ) ;
F_181 ( V_71 , V_23 ) ;
return V_71 ;
}
static int F_186 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_23 * V_223 = V_73 ( V_65 ) -> V_224 ;
T_9 V_103 = ( V_23 -> V_100 + 1 ) << V_23 -> V_66 -> V_69 ;
struct V_71 * V_71 ;
int V_83 ;
F_8 ( V_23 -> V_100 == V_101 ) ;
if ( F_24 ( V_223 ) < V_103 )
F_187 ( V_223 , V_103 ) ;
V_71 = F_185 ( V_23 ) ;
if ( ! V_71 )
return - V_138 ;
V_83 = F_61 ( V_223 , V_71 , 0 ) ;
if ( V_83 )
F_179 ( V_23 , V_71 ) ;
F_53 ( V_71 ) ;
return V_83 ;
}
static void F_188 ( struct V_64 * V_65 , T_8 V_187 ,
int V_228 ,
void (* F_189)( struct V_229 * , long ) ,
long V_230 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_23 * V_23 ;
struct V_71 * V_71 ;
struct V_229 * V_231 ;
T_4 V_232 ;
int V_196 ;
V_232 = V_187 >> ( V_65 -> V_69 - 3 ) ;
V_196 = V_187 & ( ( V_65 -> V_233 >> 3 ) - 1 ) ;
V_23 = V_74 -> V_234 ;
V_71 = F_48 ( V_23 , V_232 , 0 ) ;
F_8 ( ! V_71 ) ;
if ( ! F_157 ( V_71 ) )
F_103 ( V_23 , V_71 , V_235 ) ;
if ( V_228 )
F_93 ( V_23 , V_71 , 0 ) ;
V_231 = F_72 ( V_71 ) ;
F_189 ( V_231 + V_196 , V_230 ) ;
if ( V_228 ) {
F_147 ( V_65 , V_97 ( V_71 ) , V_196 ) ;
F_8 ( ( int ) F_17 ( V_231 [ V_196 ] . V_236 ) > V_74 -> V_237 ) ;
}
F_73 ( V_231 ) ;
F_53 ( V_71 ) ;
}
static void F_190 ( struct V_229 * V_231 , long V_238 )
{
struct V_229 * V_221 = ( void * ) V_238 ;
* V_221 = * V_231 ;
}
void F_191 ( struct V_64 * V_65 , T_8 V_187 ,
struct V_229 * V_231 )
{
F_188 ( V_65 , V_187 , 0 , F_190 , ( long ) V_231 ) ;
}
static void F_192 ( struct V_229 * V_231 , long V_141 )
{
T_8 V_236 ;
V_236 = F_17 ( V_231 -> V_236 ) ;
V_236 += V_141 ;
V_231 -> V_236 = F_23 ( V_236 ) ;
}
void F_193 ( struct V_64 * V_65 , T_1 V_144 , int V_141 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
T_8 V_187 = V_144 >> V_74 -> V_195 ;
if ( ! V_141 )
return;
F_188 ( V_65 , V_187 , 1 , F_192 , V_141 ) ;
}
static void F_194 ( struct V_229 * V_231 , long V_239 )
{
V_231 -> V_239 = F_23 ( V_239 ) ;
}
void F_195 ( struct V_64 * V_65 , T_8 V_187 , T_8 V_240 ,
T_7 V_146 )
{
T_8 V_239 = V_240 << 4 | ( V_13 T_3 ) V_146 ;
F_188 ( V_65 , V_187 , 1 , F_194 , V_239 ) ;
}
static void F_196 ( struct V_229 * V_231 , long V_241 )
{
V_231 -> V_236 = F_23 ( V_242 ) ;
}
void F_197 ( struct V_64 * V_65 , T_8 V_187 )
{
F_188 ( V_65 , V_187 , 1 , F_196 , 0 ) ;
}
static void F_198 ( struct V_229 * V_231 ,
long V_239 )
{
V_231 -> V_236 = 0 ;
V_231 -> V_239 = F_23 ( V_239 ) ;
}
void F_199 ( struct V_64 * V_65 , T_8 V_187 , T_8 V_240 )
{
T_8 V_239 = V_240 << 4 ;
F_188 ( V_65 , V_187 , 1 , F_198 ,
V_239 ) ;
}
int F_64 ( struct V_23 * V_23 , struct V_71 * V_71 , long V_200 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
int V_91 ;
F_33 ( V_65 , V_71 , V_200 & V_161 ) ;
V_91 = F_186 ( V_23 ) ;
F_36 ( V_65 , V_71 , V_200 & V_161 ) ;
return V_91 ;
}
static int F_200 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_23 * V_223 = V_73 ( V_65 ) -> V_224 ;
struct V_71 * V_71 ;
int V_91 ;
V_71 = F_48 ( V_223 , V_23 -> V_100 , 0 ) ;
if ( ! V_71 )
return - V_138 ;
F_181 ( V_71 , V_23 ) ;
F_33 ( V_65 , V_71 , 1 ) ;
V_91 = F_163 ( V_223 , V_71 ) ;
F_36 ( V_65 , V_71 , 1 ) ;
F_53 ( V_71 ) ;
return V_91 ;
}
void F_201 ( struct V_23 * V_23 )
{
struct V_64 * V_65 = V_23 -> V_66 ;
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_97 * V_98 = V_25 -> V_121 ;
struct V_71 * V_71 ;
if ( ! V_23 -> V_63 ) {
if ( ! ( V_25 -> V_31 & V_243 ) ) {
V_25 -> V_31 |= V_243 ;
if ( F_24 ( V_23 ) > 0 )
F_177 ( V_23 , 0 ) ;
F_200 ( V_23 ) ;
}
}
F_202 ( & V_23 -> V_244 , 0 ) ;
F_203 ( V_23 ) ;
F_8 ( V_23 -> V_245 & V_246 && V_23 -> V_63 ) ;
if ( ! V_98 )
return;
if ( ( V_73 ( V_65 ) -> V_247 & V_248 ) ) {
V_98 -> V_115 -> V_191 ( V_23 -> V_66 , V_98 ) ;
return;
}
F_8 ( V_23 -> V_100 < V_249 ) ;
V_71 = F_185 ( V_23 ) ;
F_8 ( ! V_71 ) ;
F_53 ( V_71 ) ;
}
void F_204 ( struct V_97 * V_98 )
{
struct V_23 * V_23 ;
struct V_71 * V_71 ;
int V_83 , V_147 ;
V_23 = F_121 ( V_98 -> V_65 , V_98 -> V_107 , & V_147 ) ;
V_71 = F_48 ( V_23 , V_98 -> V_1 , V_98 -> V_2 ) ;
V_83 = F_125 ( V_71 ) ;
F_8 ( V_83 ) ;
F_8 ( ! F_82 ( V_71 ) ) ;
F_8 ( V_97 ( V_71 ) != V_98 ) ;
V_83 = F_162 ( V_23 , V_71 , 0 ) ;
F_8 ( V_83 ) ;
F_8 ( F_82 ( V_71 ) || V_71 -> V_250 ) ;
F_53 ( V_71 ) ;
F_123 ( V_23 , V_147 ) ;
}
int F_205 ( struct V_23 * V_23 , const void * V_251 , T_10 V_252 ,
T_9 V_1 , long V_200 , struct V_92 * V_92 )
{
T_9 V_106 = V_1 << V_23 -> V_66 -> V_69 ;
int V_83 ;
struct V_71 * V_71 ;
void * V_253 ;
F_8 ( V_106 & ( V_215 - 1 ) ) ;
F_8 ( V_252 > V_215 ) ;
V_71 = F_48 ( V_23 , V_1 , 0 ) ;
if ( ! V_71 )
return - V_138 ;
V_253 = F_72 ( V_71 ) ;
memcpy ( V_253 , V_251 , V_252 ) ;
F_129 ( V_71 ) ;
F_73 ( V_253 ) ;
if ( F_24 ( V_23 ) < V_106 + V_215 )
F_187 ( V_23 , V_106 + V_215 ) ;
V_83 = F_61 ( V_23 , V_71 , V_200 ) ;
F_53 ( V_71 ) ;
return V_83 ;
}
int F_206 ( struct V_64 * V_65 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
struct V_23 * V_23 ;
V_23 = F_207 ( V_65 , V_254 ) ;
if ( F_122 ( V_23 ) )
return F_184 ( V_23 ) ;
V_74 -> V_234 = V_23 ;
return 0 ;
}
int F_208 ( struct V_64 * V_65 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
int V_255 = 3 * V_74 -> V_256 ;
F_87 ( & V_74 -> V_197 ) ;
F_87 ( & V_74 -> V_163 ) ;
F_209 ( & V_74 -> V_76 ) ;
V_74 -> V_120 = F_210 ( V_255 ,
sizeof( struct V_97 ) ) ;
V_74 -> V_186 = F_210 ( V_255 ,
sizeof( struct V_183 ) ) ;
return 0 ;
}
void F_211 ( struct V_64 * V_65 )
{
struct V_73 * V_74 = V_73 ( V_65 ) ;
F_212 ( V_74 -> V_120 ) ;
F_212 ( V_74 -> V_186 ) ;
}
