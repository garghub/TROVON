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
F_18 ( V_23 , F_17 ( V_22 -> V_33 ) ) ;
F_19 ( V_23 , F_17 ( V_22 -> V_34 ) ) ;
V_23 -> V_35 = F_12 ( V_22 -> V_36 ) ;
F_20 ( V_23 , F_12 ( V_22 -> V_37 ) ) ;
V_23 -> V_38 = F_10 ( V_22 -> V_39 ) ;
V_23 -> V_40 = F_10 ( V_22 -> V_41 ) ;
V_23 -> V_42 = F_10 ( V_22 -> V_43 ) ;
F_21 ( V_23 , F_17 ( V_22 -> V_44 ) ) ;
V_23 -> V_45 = F_17 ( V_22 -> V_46 ) ;
switch ( V_23 -> V_27 & V_47 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_23 -> V_52 = F_12 ( V_22 -> V_53 [ 0 ] ) ;
break;
case V_54 :
case V_55 :
case V_56 :
for ( V_26 = 0 ; V_26 < V_57 ; V_26 ++ )
V_25 -> V_58 [ V_26 ] = F_12 ( V_22 -> V_53 [ V_26 ] ) ;
break;
default:
F_22 () ;
}
}
static void F_23 ( struct V_23 * V_23 , struct V_21 * V_22 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
int V_26 ;
V_22 -> V_28 = F_24 ( V_23 -> V_27 ) ;
V_22 -> V_30 = V_25 -> V_29 ;
V_22 -> V_59 = 0 ;
V_22 -> V_32 = F_25 ( V_25 -> V_31 ) ;
V_22 -> V_33 = F_25 ( F_26 ( V_23 ) ) ;
V_22 -> V_34 = F_25 ( F_27 ( V_23 ) ) ;
V_22 -> V_36 = F_14 ( F_28 ( V_23 ) ) ;
V_22 -> V_37 = F_14 ( V_25 -> V_60 ) ;
V_22 -> V_39 = F_13 ( V_23 -> V_38 ) ;
V_22 -> V_41 = F_13 ( V_23 -> V_40 ) ;
V_22 -> V_43 = F_13 ( V_23 -> V_42 ) ;
V_22 -> V_44 = F_25 ( V_23 -> V_61 ) ;
V_22 -> V_46 = F_25 ( V_23 -> V_45 ) ;
switch ( V_23 -> V_27 & V_47 ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_22 -> V_53 [ 0 ] = F_14 ( V_23 -> V_52 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
for ( V_26 = 0 ; V_26 < V_57 ; V_26 ++ )
V_22 -> V_53 [ V_26 ] = F_14 ( V_25 -> V_58 [ V_26 ] ) ;
break;
default:
F_22 () ;
}
}
static void F_29 ( struct V_23 * V_23 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
struct V_24 * V_25 = V_24 ( V_23 ) ;
V_23 -> V_65 = V_66 ;
if ( V_25 -> V_60 >> V_63 -> V_67 < V_66 )
V_23 -> V_65 = F_30 ( V_25 -> V_60 , 512 ) >> 9 ;
}
void F_20 ( struct V_23 * V_23 , T_1 V_68 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
V_25 -> V_60 = V_68 ;
F_29 ( V_23 ) ;
}
static void F_31 ( struct V_62 * V_63 , struct V_69 * V_69 , int V_70 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
F_8 ( ! F_32 ( V_69 ) ) ;
if ( V_70 ) {
F_8 ( F_33 ( V_69 ) ) ;
F_34 ( V_69 ) ;
} else {
if ( F_33 ( V_69 ) )
V_72 -> V_73 ++ ;
else
F_34 ( V_69 ) ;
}
}
static void F_35 ( struct V_62 * V_63 , struct V_69 * V_69 , int V_70 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
F_8 ( ! F_32 ( V_69 ) ) ;
if ( V_70 )
F_36 ( V_69 ) ;
else {
F_8 ( ! F_33 ( V_69 ) ) ;
if ( V_72 -> V_73 )
V_72 -> V_73 -- ;
else
F_36 ( V_69 ) ;
}
}
void F_37 ( struct V_62 * V_63 , struct V_69 * V_69 , int V_70 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
if ( V_69 )
F_31 ( V_63 , V_69 , V_70 ) ;
if ( V_70 ) {
F_38 ( & V_72 -> V_74 ) ;
F_39 ( V_63 ) ;
}
}
void F_40 ( struct V_62 * V_63 , struct V_69 * V_69 , int V_70 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
if ( V_69 )
F_35 ( V_63 , V_69 , V_70 ) ;
if ( V_70 )
F_41 ( & V_72 -> V_74 ) ;
}
static struct V_69 * F_42 ( struct V_23 * V_23 , T_1 V_1 ,
T_2 V_2 )
{
return F_43 ( V_23 -> V_75 ,
F_7 ( V_1 , V_2 ) , V_76 ) ;
}
static void F_44 ( struct V_69 * V_69 )
{
F_45 ( V_69 ) ;
F_46 ( V_69 ) ;
}
static void F_47 ( struct V_69 * V_69 )
{
int V_77 = 0 ;
while ( F_48 ( ! F_49 ( V_69 ) ) ) {
if ( V_77 ++ > 0x1000 ) {
F_50 ( V_78 L_1 , & V_77 ) ;
F_22 () ;
}
if ( F_33 ( V_69 ) ) {
break;
}
F_51 () ;
}
F_8 ( ! F_32 ( V_69 ) ) ;
}
static struct V_69 * F_52 ( struct V_23 * V_23 , T_1 V_1 ,
T_2 V_2 )
{
struct V_79 * V_80 = V_23 -> V_75 ;
T_4 V_12 = F_7 ( V_1 , V_2 ) ;
struct V_69 * V_69 ;
int V_81 ;
V_82:
V_69 = F_53 ( V_80 , V_12 ) ;
if ( ! V_69 ) {
V_69 = F_54 ( V_76 ) ;
if ( ! V_69 )
return NULL ;
V_81 = F_55 ( V_69 , V_80 , V_12 , V_76 ) ;
if ( F_48 ( V_81 ) ) {
F_46 ( V_69 ) ;
if ( V_81 == - V_83 )
goto V_82;
return NULL ;
}
} else F_47 ( V_69 ) ;
F_8 ( ! F_32 ( V_69 ) ) ;
return V_69 ;
}
static void F_56 ( struct V_69 * V_69 )
{
if ( ! F_33 ( V_69 ) )
F_45 ( V_69 ) ;
}
static void F_57 ( struct V_69 * V_69 )
{
F_56 ( V_69 ) ;
F_46 ( V_69 ) ;
}
static struct V_69 * F_58 ( struct V_23 * V_23 , T_1 V_1 , T_2 V_2 ,
int V_84 )
{
if ( V_84 == V_85 )
return F_42 ( V_23 , V_1 , V_2 ) ;
else
return F_52 ( V_23 , V_1 , V_2 ) ;
}
static void F_59 ( struct V_69 * V_69 , int V_84 )
{
if ( V_84 == V_85 )
F_44 ( V_69 ) ;
else
F_57 ( V_69 ) ;
}
static unsigned long F_60 ( T_1 V_86 , int V_87 , int V_88 )
{
T_1 V_89 = V_86 ;
V_89 >>= V_87 * V_88 ;
V_89 <<= 64 - V_88 ;
V_89 >>= 64 - V_88 ;
return V_89 ;
}
static unsigned long F_61 ( T_1 V_86 , T_2 V_87 )
{
return F_60 ( V_86 , ( V_13 int ) V_87 , V_9 ) ;
}
static inline void F_62 ( struct V_62 * V_63 ,
struct V_90 * V_91 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
F_63 ( & V_91 -> V_92 , V_72 -> V_93 ) ;
F_63 ( & V_91 -> V_94 , V_72 -> V_93 ) ;
}
static void F_64 ( struct V_95 * V_96 )
{
struct V_69 * V_69 ;
struct V_23 * V_23 ;
int V_89 ;
V_69 = V_96 -> V_69 ;
V_23 = V_69 -> V_80 -> V_97 ;
F_47 ( V_69 ) ;
V_89 = F_65 ( V_23 , V_69 , 0 ) ;
F_56 ( V_69 ) ;
F_8 ( V_89 ) ;
}
static void F_66 ( struct V_95 * V_96 )
{
struct V_23 * V_23 ;
int V_89 ;
V_23 = V_96 -> V_23 ;
if ( V_23 -> V_98 == V_99 )
F_67 ( V_23 -> V_64 ) ;
else {
V_89 = F_68 ( V_23 , NULL , 0 ) ;
F_8 ( V_89 ) ;
}
}
static unsigned long F_69 ( const unsigned long * V_100 ,
unsigned long V_101 , unsigned long V_102 )
{
return F_70 ( V_100 , V_101 , V_102 ) ;
}
static T_5 F_71 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_86 ;
F_72 ( F_73 ( struct V_21 , V_28 ) != 0 ) ;
F_72 ( F_73 ( struct V_21 , V_30 ) != 2 ) ;
F_72 ( F_73 ( struct V_21 , V_32 ) != 4 ) ;
V_86 = ( T_1 ) V_23 -> V_27 << 48 |
( T_1 ) V_25 -> V_29 << 40 |
( T_1 ) V_25 -> V_31 ;
return F_14 ( V_86 ) ;
}
static int F_74 ( struct V_62 * V_63 ,
struct V_95 * V_96 , T_6 * V_103 )
{
struct V_23 * V_23 = V_96 -> V_23 ;
struct V_24 * V_25 = V_24 ( V_23 ) ;
unsigned long V_104 ;
T_1 V_105 , V_1 ;
T_5 V_86 ;
T_2 V_2 ;
int V_81 ;
for ( V_104 = 0 ; ; V_104 ++ ) {
V_104 = F_69 ( V_96 -> V_106 , V_107 , V_104 ) ;
if ( V_104 >= V_57 + V_108 )
return 0 ;
switch ( V_104 ) {
case V_109 :
V_86 = F_71 ( V_23 ) ;
break;
case V_110 :
V_86 = F_14 ( V_25 -> V_60 ) ;
break;
case V_111 :
V_86 = F_14 ( F_28 ( V_23 ) ) ;
break;
case V_108 ... V_108 + V_57 - 1 :
V_86 = F_14 ( V_25 -> V_58 [ V_104 - V_108 ] ) ;
break;
default:
F_22 () ;
}
V_105 = V_99 ;
V_1 = V_23 -> V_98 ;
V_2 = F_2 ( 0 ) ;
V_81 = V_103 ( V_63 , V_105 , V_1 , V_2 , V_104 , V_86 ) ;
if ( V_81 )
return V_81 ;
}
}
static int F_75 ( struct V_62 * V_63 ,
struct V_95 * V_96 , T_6 * V_103 )
{
unsigned long V_104 ;
struct V_69 * V_69 = V_96 -> V_69 ;
T_1 V_105 , V_1 ;
T_5 * V_112 , V_86 ;
T_2 V_2 ;
int V_81 ;
for ( V_104 = 0 ; ; V_104 ++ ) {
V_104 = F_69 ( V_96 -> V_106 , V_107 , V_104 ) ;
if ( V_104 >= V_107 )
return 0 ;
V_105 = V_69 -> V_80 -> V_97 -> V_98 ;
F_9 ( V_69 -> V_12 , & V_1 , & V_2 ) ;
V_112 = F_76 ( V_69 ) ;
V_86 = V_112 [ V_104 ] ;
F_77 ( V_112 ) ;
V_81 = V_103 ( V_63 , V_105 , V_1 , V_2 , V_104 , V_86 ) ;
if ( V_81 )
return V_81 ;
}
}
int F_78 ( struct V_62 * V_63 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
struct V_95 * V_96 ;
int V_81 ;
F_79 (block, &super->s_object_alias, alias_list) {
V_81 = V_96 -> V_113 -> V_114 ( V_63 , V_96 , V_115 ) ;
if ( V_81 )
return V_81 ;
}
return 0 ;
}
void F_80 ( struct V_62 * V_63 , struct V_95 * V_96 )
{
F_8 ( ! F_81 ( & V_96 -> V_116 ) ) ;
F_82 ( & V_96 -> V_117 ) ;
F_83 ( V_96 , V_71 ( V_63 ) -> V_118 ) ;
}
static void F_84 ( struct V_62 * V_63 , struct V_95 * V_96 )
{
struct V_23 * V_23 = V_96 -> V_23 ;
V_24 ( V_23 ) -> V_119 = NULL ;
F_80 ( V_63 , V_96 ) ;
}
static void F_85 ( struct V_62 * V_63 ,
struct V_95 * V_96 )
{
struct V_69 * V_69 = V_96 -> V_69 ;
if ( F_86 ( V_69 ) ) {
F_87 ( V_69 ) ;
F_46 ( V_69 ) ;
F_88 ( V_69 , 0 ) ;
}
F_80 ( V_63 , V_96 ) ;
}
struct V_95 * F_89 ( struct V_62 * V_63 ,
T_1 V_105 , T_1 V_1 , T_2 V_2 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
struct V_95 * V_96 ;
V_96 = F_90 ( V_72 -> V_118 , V_76 ) ;
memset ( V_96 , 0 , sizeof( * V_96 ) ) ;
F_91 ( & V_96 -> V_117 ) ;
F_91 ( & V_96 -> V_116 ) ;
V_96 -> V_63 = V_63 ;
V_96 -> V_105 = V_105 ;
V_96 -> V_1 = V_1 ;
V_96 -> V_2 = V_2 ;
return V_96 ;
}
static void F_92 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_95 * V_96 ;
if ( V_25 -> V_119 )
return;
V_96 = F_89 ( V_23 -> V_64 , V_99 , V_23 -> V_98 , 0 ) ;
V_96 -> V_23 = V_23 ;
V_25 -> V_119 = V_96 ;
V_96 -> V_113 = & V_120 ;
}
void F_93 ( struct V_69 * V_69 , struct V_95 * V_96 ,
T_5 * V_121 , int V_122 )
{
T_1 V_123 ;
int V_26 , V_124 ;
V_96 -> V_125 = 0 ;
V_96 -> V_126 = 0 ;
V_124 = 0 ;
if ( V_69 -> V_12 < F_6 () ) {
return;
}
if ( V_69 -> V_12 == F_6 () ) {
V_124 = V_3 ;
V_96 -> V_126 = V_3 ;
}
if ( ! V_122 ) {
for ( V_26 = V_124 ; V_26 < V_107 ; V_26 ++ ) {
V_123 = F_12 ( V_121 [ V_26 ] ) ;
if ( V_123 )
V_96 -> V_125 ++ ;
if ( V_123 & V_127 )
V_96 -> V_126 ++ ;
}
}
}
static void F_94 ( struct V_23 * V_23 , struct V_69 * V_69 )
{
struct V_95 * V_96 ;
T_1 V_1 ;
T_2 V_2 ;
if ( F_86 ( V_69 ) )
return;
F_9 ( V_69 -> V_12 , & V_1 , & V_2 ) ;
V_96 = F_89 ( V_23 -> V_64 , V_23 -> V_98 , V_1 , V_2 ) ;
V_96 -> V_69 = V_69 ;
F_95 ( V_69 ) ;
F_96 ( V_69 ) ;
F_88 ( V_69 , ( unsigned long ) V_96 ) ;
V_96 -> V_113 = & V_128 ;
}
static void F_97 ( struct V_23 * V_23 , struct V_69 * V_69 ,
int V_122 )
{
struct V_95 * V_96 ;
T_5 * V_121 ;
if ( F_86 ( V_69 ) )
return;
F_94 ( V_23 , V_69 ) ;
V_96 = V_95 ( V_69 ) ;
V_121 = F_76 ( V_69 ) ;
F_93 ( V_69 , V_96 , V_121 , V_122 ) ;
F_77 ( V_121 ) ;
}
static void F_98 ( struct V_69 * V_69 , int V_12 , T_1 V_123 )
{
struct V_95 * V_96 = V_95 ( V_69 ) ;
T_5 * V_121 ;
T_1 V_129 ;
F_8 ( ! V_96 ) ;
V_121 = F_76 ( V_69 ) ;
V_129 = F_12 ( V_121 [ V_12 ] ) ;
V_121 [ V_12 ] = F_14 ( V_123 ) ;
F_77 ( V_121 ) ;
F_99 ( V_69 ) ;
V_96 -> V_126 += ! ! ( V_123 & V_127 )
- ! ! ( V_129 & V_127 ) ;
V_96 -> V_125 += ! ! V_123 - ! ! V_129 ;
}
static T_1 F_100 ( struct V_69 * V_69 , int V_12 )
{
T_5 * V_96 ;
T_1 V_123 ;
V_96 = F_76 ( V_69 ) ;
V_123 = F_12 ( V_96 [ V_12 ] ) ;
F_77 ( V_96 ) ;
return V_123 ;
}
static int F_101 ( struct V_69 * V_69 )
{
F_102 ( V_69 , 0 , V_130 ) ;
return 0 ;
}
static int F_103 ( struct V_23 * V_23 , struct V_69 * V_69 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_4 V_12 = V_69 -> V_12 ;
T_1 V_96 ;
V_96 = V_25 -> V_58 [ V_12 ] ;
if ( ! V_96 )
return F_101 ( V_69 ) ;
return F_104 ( V_23 , V_69 , V_96 , V_12 , 0 ) ;
}
static int F_105 ( struct V_23 * V_23 , struct V_69 * V_69 ,
int V_131 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_1 , V_132 = V_25 -> V_58 [ V_133 ] ;
T_2 V_2 , V_134 ;
int V_89 ;
struct V_69 * V_135 ;
F_9 ( V_69 -> V_12 , & V_1 , & V_134 ) ;
if ( ! V_132 )
return F_101 ( V_69 ) ;
if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return F_101 ( V_69 ) ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ;
( V_13 T_3 ) V_2 > ( V_13 T_3 ) V_134 ;
V_2 = F_106 ( V_2 ) ) {
V_135 = F_58 ( V_23 , V_1 , V_2 , V_131 ) ;
if ( ! V_135 )
return - V_136 ;
V_89 = F_104 ( V_23 , V_135 , V_132 , V_1 , V_2 ) ;
if ( V_89 ) {
F_44 ( V_135 ) ;
return V_89 ;
}
V_132 = F_100 ( V_135 , F_61 ( V_1 , F_106 ( V_2 ) ) ) ;
F_59 ( V_135 , V_131 ) ;
if ( ! V_132 )
return F_101 ( V_69 ) ;
}
return F_104 ( V_23 , V_69 , V_132 , V_1 , 0 ) ;
}
static int F_107 ( struct V_23 * V_23 , struct V_69 * V_69 ,
int V_131 )
{
T_4 V_12 = V_69 -> V_12 ;
if ( V_12 < V_3 )
return F_103 ( V_23 , V_69 ) ;
return F_105 ( V_23 , V_69 , V_131 ) ;
}
static int F_108 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_132 = V_25 -> V_58 [ V_133 ] ;
T_2 V_2 ;
int V_89 ;
struct V_69 * V_135 ;
if ( ! V_132 )
return 0 ;
if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return 0 ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ; V_2 != 0 ; V_2 = F_106 ( V_2 ) ) {
V_135 = F_42 ( V_23 , V_1 , V_2 ) ;
if ( ! V_135 )
return - V_136 ;
V_89 = F_104 ( V_23 , V_135 , V_132 , V_1 , V_2 ) ;
if ( V_89 ) {
F_44 ( V_135 ) ;
return V_89 ;
}
V_132 = F_100 ( V_135 , F_61 ( V_1 , F_106 ( V_2 ) ) ) ;
F_44 ( V_135 ) ;
if ( ! V_132 )
return 0 ;
}
return 1 ;
}
int F_109 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_1 < V_3 )
return ! ! V_25 -> V_58 [ V_1 ] ;
return F_108 ( V_23 , V_1 ) ;
}
static T_1 F_110 ( struct V_23 * V_23 , T_1 V_1 , int V_137 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
for (; V_1 < V_3 ; V_1 ++ )
if ( V_137 ^ ( V_25 -> V_58 [ V_1 ] == 0 ) )
return V_1 ;
return V_3 ;
}
static T_1 F_111 ( struct V_23 * V_23 , T_1 V_1 , int V_137 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_5 * V_138 ;
T_1 V_139 , V_132 = V_25 -> V_58 [ V_133 ] ;
T_2 V_2 ;
int V_89 , V_140 ;
struct V_69 * V_69 ;
F_8 ( ! V_132 ) ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ; V_2 != 0 ; V_2 = F_106 ( V_2 ) ) {
V_139 = 1 << ( V_9 * ( ( V_13 T_3 ) V_2 - 1 ) ) ;
V_69 = F_42 ( V_23 , V_1 , V_2 ) ;
if ( ! V_69 )
return V_1 ;
V_89 = F_104 ( V_23 , V_69 , V_132 , V_1 , V_2 ) ;
if ( V_89 ) {
F_44 ( V_69 ) ;
return V_1 ;
}
V_140 = F_61 ( V_1 , F_106 ( V_2 ) ) ;
V_138 = F_76 ( V_69 ) ;
while ( V_140 < V_107 ) {
if ( V_137 && ( V_138 [ V_140 ] != 0 ) )
break;
if ( ! V_137 && ! ( F_12 ( V_138 [ V_140 ] ) & V_127 ) )
break;
V_140 ++ ;
V_1 += V_139 ;
V_1 &= ~ ( V_139 - 1 ) ;
}
if ( V_140 >= V_107 ) {
F_77 ( V_138 ) ;
F_44 ( V_69 ) ;
return V_1 ;
}
V_132 = F_12 ( V_138 [ V_140 ] ) ;
F_77 ( V_138 ) ;
F_44 ( V_69 ) ;
if ( ! V_132 ) {
F_8 ( V_137 ) ;
return V_1 ;
}
}
return V_1 ;
}
T_1 F_112 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_1 < V_3 ) {
V_1 = F_110 ( V_23 , V_1 , 0 ) ;
if ( V_1 < V_3 )
return V_1 ;
}
if ( ! V_25 -> V_58 [ V_133 ] )
return V_1 ;
else if ( V_25 -> V_58 [ V_133 ] & V_127 )
V_1 = F_5 ( V_25 -> V_29 ) ;
else if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return V_1 ;
else {
V_1 = F_111 ( V_23 , V_1 , 0 ) ;
if ( V_1 < F_5 ( V_25 -> V_29 ) )
return V_1 ;
F_113 ( V_1 == F_5 ( V_25 -> V_29 ) ) ;
}
return V_1 ;
}
static T_1 F_114 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_1 < V_3 ) {
V_1 = F_110 ( V_23 , V_1 , 1 ) ;
if ( V_1 < V_3 )
return V_1 ;
}
if ( V_1 < F_5 ( V_25 -> V_29 ) ) {
if ( ! V_25 -> V_58 [ V_133 ] )
V_1 = F_5 ( V_25 -> V_29 ) ;
else
return F_111 ( V_23 , V_1 , 1 ) ;
}
return V_1 ;
}
T_1 F_115 ( struct V_23 * V_23 , T_1 V_1 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
T_1 V_89 , V_141 ;
V_89 = F_114 ( V_23 , V_1 ) ;
V_141 = F_28 ( V_23 ) >> V_63 -> V_67 ;
if ( V_89 >= V_141 )
V_89 = F_116 ( V_1 , V_141 ) ;
return V_89 ;
}
static int F_117 ( struct V_24 * V_25 , T_1 V_1 , T_1 V_142 )
{
return F_118 ( V_25 -> V_58 [ V_1 ] ) == V_142 ;
}
static int F_119 ( struct V_23 * V_23 , T_1 V_1 ,
T_1 V_142 , T_1 V_132 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_2 V_2 ;
int V_89 ;
struct V_69 * V_69 ;
for ( V_2 = F_2 ( V_25 -> V_29 ) ; V_2 != 0 ; V_2 = F_106 ( V_2 ) ) {
V_69 = F_52 ( V_23 , V_1 , V_2 ) ;
F_8 ( ! V_69 ) ;
V_89 = F_104 ( V_23 , V_69 , V_132 , V_1 , V_2 ) ;
if ( V_89 ) {
F_57 ( V_69 ) ;
return 0 ;
}
V_132 = F_100 ( V_69 , F_61 ( V_1 , F_106 ( V_2 ) ) ) ;
F_57 ( V_69 ) ;
if ( ! V_132 )
return 0 ;
if ( F_118 ( V_132 ) == V_142 )
return 1 ;
}
return 0 ;
}
static int F_120 ( struct V_23 * V_23 , T_1 V_1 , T_1 V_142 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_1 V_132 = V_25 -> V_58 [ V_133 ] ;
if ( ! V_132 )
return 0 ;
if ( V_1 >= F_5 ( V_25 -> V_29 ) )
return 0 ;
if ( F_118 ( V_132 ) == V_142 )
return 1 ;
return F_119 ( V_23 , V_1 , V_142 , V_132 ) ;
}
static int F_121 ( struct V_23 * V_23 , T_1 V_1 , T_1 V_142 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( ( V_23 -> V_61 == 0 ) && F_122 ( & V_23 -> V_143 ) == 1 )
return 0 ;
if ( V_1 < V_3 )
return F_117 ( V_25 , V_1 , V_142 ) ;
return F_120 ( V_23 , V_1 , V_142 ) ;
}
int F_123 ( struct V_62 * V_63 , T_1 V_142 , T_1 V_105 , T_1 V_1 ,
T_7 V_144 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
struct V_23 * V_23 ;
int V_89 , V_145 ;
if ( V_105 == - 1 )
return 0 ;
F_124 ( ( T_1 ) ( V_146 ) V_105 != V_105 , V_63 ) ;
V_23 = F_125 ( V_63 , V_105 , & V_145 ) ;
if ( F_126 ( V_23 ) )
goto V_147;
V_89 = F_121 ( V_23 , V_1 , V_142 ) ;
F_127 ( V_23 , V_145 ) ;
if ( V_89 )
return V_89 ;
V_147:
if ( F_128 ( & V_72 -> V_148 . V_94 , V_142 ) )
return 2 ;
return 0 ;
}
int F_129 ( struct V_69 * V_69 )
{
struct V_23 * V_23 = V_69 -> V_80 -> V_97 ;
int V_89 = - V_149 ;
V_89 = F_107 ( V_23 , V_69 , V_85 ) ;
if ( V_89 ) {
F_130 ( V_69 ) ;
F_131 ( V_69 ) ;
} else {
F_99 ( V_69 ) ;
F_132 ( V_69 ) ;
}
F_133 ( V_69 ) ;
return V_89 ;
}
static int F_134 ( struct V_23 * V_23 , int V_68 )
{
struct V_71 * V_72 = V_71 ( V_23 -> V_64 ) ;
T_1 V_150 = V_72 -> V_151 + V_72 -> V_152
- V_72 -> V_153 - V_72 -> V_154 ;
if ( ! V_68 )
return 0 ;
if ( V_150 < V_68 )
return - V_155 ;
if ( V_150 < V_68 + V_72 -> V_156 &&
! F_135 ( V_157 ) )
return - V_155 ;
return 0 ;
}
int F_136 ( struct V_23 * V_23 , struct V_69 * V_69 )
{
struct V_71 * V_72 = V_71 ( V_23 -> V_64 ) ;
struct V_95 * V_96 = V_95 ( V_69 ) ;
int V_89 ;
if ( V_96 && V_96 -> V_158 )
return 0 ;
F_37 ( V_23 -> V_64 , V_69 , V_159 ) ;
while ( ( V_89 = F_134 ( V_23 , 6 * V_160 ) ) &&
! F_81 ( & V_72 -> V_161 ) ) {
V_96 = F_137 ( V_72 -> V_161 . V_162 ,
struct V_95 , V_117 ) ;
V_96 -> V_113 -> V_163 ( V_96 ) ;
}
if ( ! V_89 ) {
F_94 ( V_23 , V_69 ) ;
V_96 = V_95 ( V_69 ) ;
V_96 -> V_158 += 6 * V_160 ;
V_72 -> V_154 += 6 * V_160 ;
F_138 ( & V_96 -> V_117 , & V_72 -> V_161 ) ;
}
F_40 ( V_23 -> V_64 , V_69 , V_159 ) ;
return V_89 ;
}
static void F_139 ( struct V_23 * V_23 ,
struct V_164 * V_165 )
{
struct V_71 * V_72 = V_71 ( V_23 -> V_64 ) ;
if ( ! V_165 )
return;
V_24 ( V_23 ) -> V_119 -> V_165 = NULL ;
if ( V_23 -> V_98 != V_99 ) {
F_22 () ;
return;
}
switch ( V_165 -> V_166 ) {
case V_167 :
case V_168 :
F_8 ( V_72 -> V_169 ) ;
V_72 -> V_169 = V_165 -> V_105 ;
break;
case V_170 :
case V_171 :
F_8 ( V_72 -> V_169 != V_165 -> V_105 ) ;
V_72 -> V_169 = 0 ;
F_140 ( V_165 ) ;
break;
case V_172 :
F_8 ( V_72 -> V_173 ) ;
F_8 ( V_72 -> V_174 ) ;
V_72 -> V_173 = V_165 -> V_175 ;
V_72 -> V_174 = V_165 -> V_104 ;
break;
case V_176 :
F_8 ( V_72 -> V_173 != V_165 -> V_175 ) ;
F_8 ( V_72 -> V_174 != V_165 -> V_104 ) ;
V_72 -> V_173 = 0 ;
V_72 -> V_174 = 0 ;
F_140 ( V_165 ) ;
break;
case V_177 :
F_8 ( V_72 -> V_173 ) ;
F_8 ( V_72 -> V_174 ) ;
F_8 ( V_72 -> V_169 ) ;
V_72 -> V_173 = V_165 -> V_175 ;
V_72 -> V_174 = V_165 -> V_104 ;
V_72 -> V_169 = V_165 -> V_105 ;
break;
case V_178 :
F_8 ( V_72 -> V_173 != V_165 -> V_175 ) ;
F_8 ( V_72 -> V_174 != V_165 -> V_104 ) ;
F_8 ( V_72 -> V_169 != V_165 -> V_105 ) ;
V_72 -> V_173 = 0 ;
V_72 -> V_174 = 0 ;
break;
case V_179 :
F_8 ( V_72 -> V_173 ) ;
F_8 ( V_72 -> V_174 ) ;
F_8 ( V_72 -> V_169 != V_165 -> V_105 ) ;
V_72 -> V_169 = 0 ;
F_140 ( V_165 ) ;
break;
default:
F_22 () ;
}
}
static int F_141 ( struct V_23 * V_23 , int V_180 )
{
return F_134 ( V_23 , V_180 * V_160 ) ;
}
static struct V_181 * F_142 ( struct V_23 * V_23 , T_1 V_1 ,
T_2 V_2 , T_1 V_182 )
{
struct V_71 * V_72 = V_71 ( V_23 -> V_64 ) ;
struct V_181 * V_183 ;
V_183 = F_90 ( V_72 -> V_184 , V_76 ) ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_105 = V_23 -> V_98 ;
V_183 -> V_1 = V_1 ;
V_183 -> V_144 = F_143 ( V_23 -> V_98 , V_2 ) ;
V_183 -> V_182 = V_182 & ~ V_127 ;
return V_183 ;
}
static void F_144 ( struct V_23 * V_23 , struct V_181 * V_183 )
{
struct V_71 * V_72 = V_71 ( V_23 -> V_64 ) ;
F_83 ( V_183 , V_72 -> V_184 ) ;
}
static void F_145 ( struct V_90 * V_91 , T_8 V_185 )
{
int V_81 ;
if ( ! F_146 ( & V_91 -> V_186 , V_185 ) ) {
V_81 = F_147 ( & V_91 -> V_186 , V_185 , ( void * ) 1 ,
V_76 ) ;
F_8 ( V_81 ) ;
V_91 -> V_187 ++ ;
}
}
static void F_148 ( struct V_23 * V_23 , struct V_69 * V_69 ,
struct V_181 * V_183 )
{
struct V_71 * V_72 = V_71 ( V_23 -> V_64 ) ;
struct V_95 * V_96 = V_95 ( V_69 ) ;
struct V_90 * V_91 = & V_72 -> V_148 ;
if ( F_86 ( V_69 ) ) {
if ( V_96 -> V_106 )
V_72 -> V_188 -= F_149 (
V_96 -> V_106 , V_107 ) ;
F_139 ( V_23 , V_96 -> V_165 ) ;
V_96 -> V_113 -> V_189 ( V_23 -> V_64 , V_96 ) ;
}
if ( V_183 ) {
if ( V_183 -> V_182 )
F_150 ( & V_91 -> V_94 , V_183 -> V_182 , V_183 ,
V_76 ) ;
else
F_150 ( & V_91 -> V_92 , V_183 -> V_190 , V_183 ,
V_76 ) ;
V_72 -> V_153 += V_183 -> V_191 ;
V_72 -> V_152 += V_183 -> V_192 ;
F_145 ( V_91 , V_183 -> V_182 >> V_72 -> V_193 ) ;
F_145 ( V_91 , V_183 -> V_190 >> V_72 -> V_193 ) ;
}
}
static void F_151 ( struct V_62 * V_63 , struct V_95 * V_96 ,
long V_194 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
if ( V_96 -> V_23 && V_96 -> V_23 -> V_98 == V_99 ) {
return;
}
if ( ! F_152 ( V_194 , V_96 -> V_106 ) ) {
F_153 ( V_194 , V_96 -> V_106 ) ;
V_72 -> V_188 ++ ;
}
F_138 ( & V_96 -> V_117 , & V_72 -> V_195 ) ;
}
static void F_154 ( struct V_23 * V_23 , struct V_181 * V_183 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
if ( V_183 -> V_191 == V_183 -> V_192 )
return;
F_92 ( V_23 ) ;
V_25 -> V_60 += V_183 -> V_191 - V_183 -> V_192 ;
F_29 ( V_23 ) ;
F_151 ( V_23 -> V_64 , V_25 -> V_119 , V_110 ) ;
F_151 ( V_23 -> V_64 , V_25 -> V_119 , V_111 ) ;
}
static int F_155 ( struct V_23 * V_23 , struct V_69 * V_69 ,
struct V_196 * V_197 )
{
struct V_181 * V_183 ;
T_1 V_1 ;
T_2 V_2 ;
int V_126 , V_81 = 0 ;
F_9 ( V_69 -> V_12 , & V_1 , & V_2 ) ;
if ( V_197 -> V_142 == 0 )
if ( F_141 ( V_23 , 1 ) )
return - V_155 ;
V_183 = F_142 ( V_23 , V_1 , V_2 , V_197 -> V_142 ) ;
if ( V_197 -> V_198 & V_199 )
V_81 = F_156 ( V_23 , V_69 , V_183 ) ;
if ( V_197 -> V_198 & V_200 )
F_157 ( V_23 , V_183 ) ;
if ( V_81 ) {
F_144 ( V_23 , V_183 ) ;
return V_81 ;
}
F_154 ( V_23 , V_183 ) ;
V_126 = 1 ;
if ( V_2 != 0 ) {
F_97 ( V_23 , V_69 , 0 ) ;
V_126 = V_95 ( V_69 ) -> V_126 == V_107 ;
}
F_148 ( V_23 , V_69 , V_183 ) ;
V_197 -> V_142 = V_183 -> V_190 ;
if ( V_197 -> V_142 && V_126 )
V_197 -> V_142 |= V_127 ;
return 0 ;
}
static int F_158 ( struct V_23 * V_23 , struct V_69 * V_69 ,
long V_198 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_196 V_197 = {
. V_142 = V_25 -> V_58 [ V_69 -> V_12 ] ,
. V_198 = V_198 ,
} ;
int V_81 ;
F_92 ( V_23 ) ;
V_81 = F_155 ( V_23 , V_69 , & V_197 ) ;
if ( V_81 )
return V_81 ;
V_25 -> V_58 [ V_69 -> V_12 ] = V_197 . V_142 ;
F_151 ( V_23 -> V_64 , V_25 -> V_119 ,
V_69 -> V_12 + V_108 ) ;
return 0 ;
}
static int F_159 ( T_1 V_142 , struct V_69 * V_69 )
{
struct V_95 * V_96 = V_95 ( V_69 ) ;
int V_201 , V_202 , V_203 , V_204 ;
V_201 = V_142 == 0 ;
V_202 = V_96 -> V_125 == 0 ;
if ( V_201 != V_202 )
return 1 ;
V_203 = ! ! ( V_142 & V_127 ) ;
V_204 = V_96 -> V_126 == V_107 ;
if ( V_203 != V_204 )
return 1 ;
return 0 ;
}
static int F_160 ( struct V_23 * V_23 , struct V_69 * V_69 ,
struct V_196 * V_205 ,
T_4 V_1 , T_2 V_134 , T_2 V_2 )
{
int V_89 , V_206 = 0 ;
int V_194 = F_61 ( V_1 , F_106 ( V_2 ) ) ;
struct V_69 * V_135 ;
struct V_196 V_207 = {
. V_198 = V_205 -> V_198 ,
} ;
V_135 = F_52 ( V_23 , V_1 , V_2 ) ;
if ( ! V_135 )
return - V_136 ;
if ( V_205 -> V_142 ) {
V_89 = F_104 ( V_23 , V_135 , V_205 -> V_142 , V_1 , V_2 ) ;
if ( V_89 )
goto V_208;
} else if ( ! F_161 ( V_135 ) ) {
V_206 = 1 ;
F_101 ( V_135 ) ;
}
V_207 . V_142 = F_100 ( V_135 , V_194 ) ;
if ( ( V_13 T_3 ) V_2 - 1 > ( V_13 T_3 ) V_134 )
V_89 = F_160 ( V_23 , V_69 , & V_207 , V_1 ,
V_134 , F_106 ( V_2 ) ) ;
else
V_89 = F_155 ( V_23 , V_69 , & V_207 ) ;
if ( V_89 )
goto V_208;
F_97 ( V_23 , V_135 , V_206 ) ;
F_98 ( V_135 , V_194 , V_207 . V_142 ) ;
if ( V_207 . V_142 || V_95 ( V_135 ) -> V_125 )
V_205 -> V_198 |= V_199 ;
if ( ! V_205 -> V_142 || F_159 ( V_205 -> V_142 , V_135 ) )
V_89 = F_155 ( V_23 , V_135 , V_205 ) ;
else
F_151 ( V_23 -> V_64 , V_95 ( V_135 ) , V_194 ) ;
V_208:
F_57 ( V_135 ) ;
return V_89 ;
}
static int F_162 ( struct V_23 * V_23 , struct V_69 * V_69 ,
T_4 V_1 , T_2 V_134 , long V_198 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_196 V_197 = {
. V_142 = V_25 -> V_58 [ V_133 ] ,
. V_198 = V_198 ,
} ;
int V_89 ;
F_92 ( V_23 ) ;
if ( V_25 -> V_29 > ( V_13 T_3 ) V_134 )
V_89 = F_160 ( V_23 , V_69 , & V_197 , V_1 , V_134 ,
F_2 ( V_25 -> V_29 ) ) ;
else
V_89 = F_155 ( V_23 , V_69 , & V_197 ) ;
if ( V_89 )
return V_89 ;
if ( V_25 -> V_58 [ V_133 ] != V_197 . V_142 ) {
V_25 -> V_58 [ V_133 ] = V_197 . V_142 ;
F_151 ( V_23 -> V_64 , V_25 -> V_119 ,
V_133 + V_108 ) ;
}
return V_89 ;
}
void F_163 ( struct V_23 * V_23 , struct V_164 * V_165 )
{
F_92 ( V_23 ) ;
V_24 ( V_23 ) -> V_119 -> V_165 = V_165 ;
}
void F_164 ( struct V_23 * V_23 , struct V_164 * V_165 )
{
struct V_95 * V_96 = V_24 ( V_23 ) -> V_119 ;
if ( V_96 && V_96 -> V_165 )
V_96 -> V_165 = NULL ;
}
static int F_165 ( struct V_23 * V_23 , T_1 V_1 , T_2 V_2 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
T_3 V_8 = ( V_13 T_3 ) V_2 ;
struct V_69 * V_69 ;
struct V_196 V_197 = {
. V_198 = V_199 ,
} ;
int V_81 ;
F_8 ( V_8 > 5 || V_25 -> V_29 > 5 ) ;
while ( V_8 > V_25 -> V_29 || V_1 >= F_5 ( V_25 -> V_29 ) ) {
V_69 = F_52 ( V_23 , V_3 + 1 ,
F_2 ( V_25 -> V_29 + 1 ) ) ;
if ( ! V_69 )
return - V_136 ;
F_101 ( V_69 ) ;
F_97 ( V_23 , V_69 , 1 ) ;
F_98 ( V_69 , 0 , V_25 -> V_58 [ V_133 ] ) ;
V_81 = F_155 ( V_23 , V_69 , & V_197 ) ;
F_57 ( V_69 ) ;
if ( V_81 )
return V_81 ;
V_25 -> V_58 [ V_133 ] = V_197 . V_142 ;
V_197 . V_142 = 0 ;
V_25 -> V_29 ++ ;
F_151 ( V_23 -> V_64 , V_25 -> V_119 , V_109 ) ;
}
return 0 ;
}
static int F_166 ( struct V_23 * V_23 , struct V_69 * V_69 , long V_198 )
{
struct V_71 * V_72 = V_71 ( V_23 -> V_64 ) ;
T_4 V_12 = V_69 -> V_12 ;
T_1 V_1 ;
T_2 V_2 ;
int V_81 ;
V_198 |= V_199 | V_200 ;
V_23 -> V_40 = V_23 -> V_42 = V_209 ;
F_9 ( V_12 , & V_1 , & V_2 ) ;
if ( V_95 ( V_69 ) && V_95 ( V_69 ) -> V_158 )
V_72 -> V_154 -= V_95 ( V_69 ) -> V_158 ;
if ( V_12 < V_3 )
return F_158 ( V_23 , V_69 , V_198 ) ;
V_1 = F_1 ( V_1 , V_2 ) ;
V_81 = F_165 ( V_23 , V_1 , V_2 ) ;
if ( V_81 )
return V_81 ;
return F_162 ( V_23 , V_69 , V_1 , V_2 , V_198 ) ;
}
int F_65 ( struct V_23 * V_23 , struct V_69 * V_69 , long V_198 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
int V_89 ;
F_37 ( V_63 , V_69 , V_198 & V_159 ) ;
V_89 = F_166 ( V_23 , V_69 , V_198 ) ;
F_40 ( V_63 , V_69 , V_198 & V_159 ) ;
return V_89 ;
}
static int F_167 ( struct V_23 * V_23 , struct V_69 * V_69 )
{
long V_198 = V_200 ;
int V_81 ;
V_23 -> V_40 = V_23 -> V_42 = V_209 ;
if ( V_69 -> V_12 < V_3 )
return F_158 ( V_23 , V_69 , V_198 ) ;
V_81 = F_165 ( V_23 , V_69 -> V_12 , 0 ) ;
if ( V_81 )
return V_81 ;
return F_162 ( V_23 , V_69 , V_69 -> V_12 , 0 , V_198 ) ;
}
int F_168 ( struct V_23 * V_23 , T_4 V_12 ,
struct V_90 * V_90 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
struct V_69 * V_69 ;
int V_89 ;
V_69 = F_42 ( V_23 , V_12 , 0 ) ;
if ( ! V_69 )
return - V_136 ;
F_37 ( V_63 , V_69 , 1 ) ;
V_89 = F_167 ( V_23 , V_69 ) ;
F_40 ( V_63 , V_69 , 1 ) ;
F_44 ( V_69 ) ;
return V_89 ;
}
int F_169 ( struct V_23 * V_23 , T_1 V_1 , T_1 V_142 ,
T_7 V_144 , long V_198 )
{
T_2 V_2 = F_170 ( V_144 ) ;
struct V_69 * V_69 ;
int V_81 ;
V_69 = F_52 ( V_23 , V_1 , V_2 ) ;
if ( ! V_69 )
return - V_136 ;
V_81 = F_104 ( V_23 , V_69 , V_142 , V_1 , V_2 ) ;
if ( ! V_81 ) {
if ( V_2 != 0 )
F_97 ( V_23 , V_69 , 0 ) ;
V_81 = F_65 ( V_23 , V_69 , V_198 ) ;
if ( ! V_81 && F_170 ( V_144 ) == 0 ) {
if ( V_23 -> V_98 == V_99 )
F_67 ( V_23 -> V_64 ) ;
else {
V_81 = F_68 ( V_23 , V_69 , V_198 ) ;
}
}
}
F_57 ( V_69 ) ;
return V_81 ;
}
static int F_171 ( struct V_23 * V_23 , struct V_69 * V_69 ,
T_1 V_142 , struct V_181 * V_183 , T_1 V_101 )
{
T_9 V_210 = V_69 -> V_12 << V_23 -> V_64 -> V_67 ;
T_1 V_1 ;
T_2 V_2 ;
int V_81 ;
if ( V_101 <= V_210 || V_101 - V_210 >= V_130 )
return 0 ;
F_9 ( V_69 -> V_12 , & V_1 , & V_2 ) ;
F_8 ( V_2 != 0 ) ;
V_81 = F_104 ( V_23 , V_69 , V_142 , V_1 , V_2 ) ;
if ( V_81 )
return V_81 ;
F_102 ( V_69 , V_101 - V_210 , V_130 ) ;
return F_156 ( V_23 , V_69 , V_183 ) ;
}
static int F_172 ( struct V_23 * V_23 , struct V_69 * V_69 ,
struct V_196 * V_197 , T_1 V_101 )
{
struct V_181 * V_183 ;
T_1 V_1 ;
T_2 V_2 ;
int V_81 = 0 ;
F_9 ( V_69 -> V_12 , & V_1 , & V_2 ) ;
F_8 ( V_2 != 0 ) ;
V_183 = F_142 ( V_23 , V_1 , V_2 , V_197 -> V_142 ) ;
V_81 = F_171 ( V_23 , V_69 , V_197 -> V_142 , V_183 , V_101 ) ;
if ( V_81 ) {
F_144 ( V_23 , V_183 ) ;
return V_81 ;
}
F_157 ( V_23 , V_183 ) ;
F_154 ( V_23 , V_183 ) ;
F_148 ( V_23 , V_69 , V_183 ) ;
V_197 -> V_142 = V_183 -> V_190 ;
return 0 ;
}
static int F_173 ( struct V_23 * V_23 , T_1 V_101 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_196 V_197 ;
struct V_69 * V_69 ;
int V_211 ;
int V_81 ;
F_92 ( V_23 ) ;
for ( V_211 = V_3 - 1 ; V_211 >= 0 ; V_211 -- ) {
if ( V_101 > ( V_211 + 1 ) * V_212 )
break;
V_197 . V_142 = V_25 -> V_58 [ V_211 ] ;
if ( ! V_197 . V_142 )
continue;
V_69 = F_52 ( V_23 , V_211 , 0 ) ;
if ( ! V_69 )
return - V_136 ;
V_81 = F_104 ( V_23 , V_69 , V_197 . V_142 , V_211 , 0 ) ;
if ( V_81 ) {
F_57 ( V_69 ) ;
return V_81 ;
}
V_81 = F_172 ( V_23 , V_69 , & V_197 , V_101 ) ;
F_57 ( V_69 ) ;
if ( V_81 )
return V_81 ;
V_25 -> V_58 [ V_211 ] = V_197 . V_142 ;
}
return 0 ;
}
static inline T_1 F_174 ( T_2 V_2 )
{
return V_213 [ ( V_13 T_3 ) V_2 ] ;
}
static inline T_1 F_175 ( T_3 V_2 )
{
return V_213 [ V_2 ] * V_212 ;
}
static inline T_1 F_176 ( T_2 V_2 )
{
return V_214 [ ( V_13 T_3 ) V_2 ] ;
}
static void F_177 ( T_4 V_12 , T_1 * V_1 , T_2 * V_2 )
{
F_9 ( V_12 , V_1 , V_2 ) ;
if ( * V_1 <= F_176 ( F_106 ( * V_2 ) ) )
* V_1 = 0 ;
}
static int F_178 ( struct V_23 * V_23 , struct V_69 * V_135 ,
struct V_196 * V_205 , T_1 V_101 )
{
int V_215 = 0 ;
int V_211 , V_81 = 0 ;
T_1 V_1 , V_216 , V_217 ;
T_2 V_2 ;
struct V_69 * V_69 ;
struct V_196 V_207 = { } ;
F_177 ( V_135 -> V_12 , & V_1 , & V_2 ) ;
V_81 = F_104 ( V_23 , V_135 , V_205 -> V_142 , V_1 , V_2 ) ;
if ( V_81 )
return V_81 ;
for ( V_211 = V_107 - 1 ; V_211 >= 0 ; V_211 -- ) {
V_216 = V_1 + V_211 * F_174 ( F_106 ( V_2 ) ) ;
V_217 = V_216 + F_174 ( F_106 ( V_2 ) ) ;
if ( V_101 > V_217 * V_212 )
break;
V_207 . V_142 = F_118 ( F_100 ( V_135 , V_211 ) ) ;
if ( ! V_207 . V_142 )
continue;
V_69 = F_52 ( V_23 , V_216 , F_106 ( V_2 ) ) ;
if ( ! V_69 )
return - V_136 ;
if ( ( V_13 T_3 ) V_2 > 1 )
V_81 = F_178 ( V_23 , V_69 , & V_207 , V_101 ) ;
else
V_81 = F_172 ( V_23 , V_69 , & V_207 , V_101 ) ;
F_57 ( V_69 ) ;
if ( V_81 )
return V_81 ;
V_215 = 1 ;
F_97 ( V_23 , V_135 , 0 ) ;
F_98 ( V_135 , V_211 , V_207 . V_142 ) ;
}
if ( ! V_215 ) {
F_50 ( L_2 , V_23 -> V_98 , V_135 -> V_12 , V_101 ) ;
return 0 ;
}
V_205 -> V_198 = V_200 ;
if ( V_95 ( V_135 ) -> V_125 )
V_205 -> V_198 |= V_199 ;
return F_155 ( V_23 , V_135 , V_205 ) ;
}
static int F_179 ( struct V_23 * V_23 , T_1 V_101 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_196 V_197 = {
. V_142 = V_25 -> V_58 [ V_133 ] ,
} ;
struct V_69 * V_69 ;
int V_81 ;
F_92 ( V_23 ) ;
if ( ! V_197 . V_142 )
return 0 ;
V_69 = F_52 ( V_23 , 0 , F_2 ( V_25 -> V_29 ) ) ;
if ( ! V_69 )
return - V_136 ;
V_81 = F_178 ( V_23 , V_69 , & V_197 , V_101 ) ;
F_57 ( V_69 ) ;
if ( V_81 )
return V_81 ;
if ( V_25 -> V_58 [ V_133 ] != V_197 . V_142 )
V_25 -> V_58 [ V_133 ] = V_197 . V_142 ;
return 0 ;
}
static int F_180 ( struct V_23 * V_23 , T_1 V_101 )
{
int V_89 ;
if ( V_101 >= F_175 ( V_24 ( V_23 ) -> V_29 ) )
return 0 ;
V_89 = F_179 ( V_23 , V_101 ) ;
if ( V_89 )
return V_89 ;
return F_173 ( V_23 , V_101 ) ;
}
int F_181 ( struct V_23 * V_23 , T_1 V_218 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
T_1 V_101 = F_28 ( V_23 ) ;
int V_81 = 0 ;
V_101 = F_30 ( V_101 , V_219 ) ;
while ( V_101 > V_218 ) {
if ( V_101 > V_219 )
V_101 -= V_219 ;
else
V_101 = 0 ;
if ( V_101 < V_218 )
V_101 = V_218 ;
F_37 ( V_63 , NULL , 1 ) ;
V_81 = F_180 ( V_23 , V_101 ) ;
if ( ! V_81 )
V_81 = F_68 ( V_23 , NULL , 0 ) ;
F_40 ( V_63 , NULL , 1 ) ;
}
if ( ! V_81 ) {
V_81 = F_182 ( V_23 , V_218 ) ;
if ( V_81 )
goto V_208;
F_183 ( V_23 , V_218 ) ;
}
V_208:
F_4 ( V_81 ) ;
return V_81 ;
}
static void F_184 ( struct V_23 * V_23 , struct V_69 * V_69 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_95 * V_96 = V_95 ( V_69 ) ;
if ( ! V_96 )
return;
F_185 ( L_3 ,
V_96 -> V_105 , V_96 -> V_1 , V_96 -> V_2 ) ;
F_8 ( V_25 -> V_119 ) ;
V_96 -> V_113 = & V_120 ;
V_96 -> V_23 = V_23 ;
V_25 -> V_119 = V_96 ;
V_96 -> V_69 = NULL ;
if ( F_86 ( V_69 ) ) {
F_87 ( V_69 ) ;
F_46 ( V_69 ) ;
F_88 ( V_69 , 0 ) ;
}
}
static void F_186 ( struct V_69 * V_69 , struct V_23 * V_23 )
{
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_95 * V_96 = V_25 -> V_119 ;
if ( ! V_96 )
return;
F_185 ( L_4 ,
V_96 -> V_105 , V_96 -> V_1 , V_96 -> V_2 ) ;
F_8 ( F_86 ( V_69 ) ) ;
V_96 -> V_113 = & V_128 ;
V_96 -> V_69 = V_69 ;
if ( ! F_86 ( V_69 ) ) {
F_95 ( V_69 ) ;
F_96 ( V_69 ) ;
F_88 ( V_69 , ( unsigned long ) V_96 ) ;
}
V_96 -> V_23 = NULL ;
V_25 -> V_119 = NULL ;
}
int F_187 ( struct V_23 * V_23 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
struct V_71 * V_72 = V_71 ( V_63 ) ;
struct V_23 * V_220 = V_72 -> V_221 ;
struct V_69 * V_69 ;
struct V_21 * V_22 ;
T_1 V_105 = V_23 -> V_98 ;
if ( V_105 << V_63 -> V_67 > F_28 ( V_220 ) )
return - V_222 ;
if ( ! F_109 ( V_220 , V_105 ) )
return - V_222 ;
V_69 = F_188 ( V_220 -> V_75 , V_105 ,
( V_223 * ) V_224 , NULL ) ;
if ( F_126 ( V_69 ) )
return F_189 ( V_69 ) ;
V_22 = F_76 ( V_69 ) ;
F_15 ( V_22 , V_23 ) ;
F_77 ( V_22 ) ;
F_184 ( V_23 , V_69 ) ;
F_46 ( V_69 ) ;
return 0 ;
}
static struct V_69 * F_190 ( struct V_23 * V_23 )
{
struct V_23 * V_220 = V_71 ( V_23 -> V_64 ) -> V_221 ;
struct V_21 * V_22 ;
struct V_69 * V_69 ;
F_8 ( V_23 -> V_98 == V_99 ) ;
V_69 = F_52 ( V_220 , V_23 -> V_98 , 0 ) ;
if ( ! V_69 )
return NULL ;
V_22 = F_76 ( V_69 ) ;
F_23 ( V_23 , V_22 ) ;
F_77 ( V_22 ) ;
F_186 ( V_69 , V_23 ) ;
return V_69 ;
}
static int F_191 ( struct V_23 * V_23 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
struct V_23 * V_220 = V_71 ( V_63 ) -> V_221 ;
T_9 V_101 = ( V_23 -> V_98 + 1 ) << V_23 -> V_64 -> V_67 ;
struct V_69 * V_69 ;
int V_81 ;
F_8 ( V_23 -> V_98 == V_99 ) ;
if ( F_28 ( V_220 ) < V_101 )
F_192 ( V_220 , V_101 ) ;
V_69 = F_190 ( V_23 ) ;
if ( ! V_69 )
return - V_136 ;
V_81 = F_65 ( V_220 , V_69 , 0 ) ;
if ( V_81 )
F_184 ( V_23 , V_69 ) ;
F_57 ( V_69 ) ;
return V_81 ;
}
static void F_193 ( struct V_62 * V_63 , T_8 V_185 ,
int V_225 ,
void (* F_194)( struct V_226 * , long ) ,
long V_227 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
struct V_23 * V_23 ;
struct V_69 * V_69 ;
struct V_226 * V_228 ;
T_4 V_229 ;
int V_194 ;
V_229 = V_185 >> ( V_63 -> V_67 - 3 ) ;
V_194 = V_185 & ( ( V_63 -> V_230 >> 3 ) - 1 ) ;
V_23 = V_72 -> V_231 ;
V_69 = F_52 ( V_23 , V_229 , 0 ) ;
F_8 ( ! V_69 ) ;
if ( ! F_161 ( V_69 ) )
F_107 ( V_23 , V_69 , V_232 ) ;
if ( V_225 )
F_97 ( V_23 , V_69 , 0 ) ;
V_228 = F_76 ( V_69 ) ;
F_194 ( V_228 + V_194 , V_227 ) ;
if ( V_225 ) {
F_151 ( V_63 , V_95 ( V_69 ) , V_194 ) ;
F_8 ( ( int ) F_17 ( V_228 [ V_194 ] . V_233 ) > V_72 -> V_234 ) ;
}
F_77 ( V_228 ) ;
F_57 ( V_69 ) ;
}
static void F_195 ( struct V_226 * V_228 , long V_235 )
{
struct V_226 * V_218 = ( void * ) V_235 ;
* V_218 = * V_228 ;
}
void F_196 ( struct V_62 * V_63 , T_8 V_185 ,
struct V_226 * V_228 )
{
F_193 ( V_63 , V_185 , 0 , F_195 , ( long ) V_228 ) ;
}
static void F_197 ( struct V_226 * V_228 , long V_139 )
{
T_8 V_233 ;
V_233 = F_17 ( V_228 -> V_233 ) ;
V_233 += V_139 ;
V_228 -> V_233 = F_25 ( V_233 ) ;
}
void F_198 ( struct V_62 * V_63 , T_1 V_142 , int V_139 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
T_8 V_185 = V_142 >> V_72 -> V_193 ;
if ( ! V_139 )
return;
F_193 ( V_63 , V_185 , 1 , F_197 , V_139 ) ;
}
static void F_199 ( struct V_226 * V_228 , long V_236 )
{
V_228 -> V_236 = F_25 ( V_236 ) ;
}
void F_200 ( struct V_62 * V_63 , T_8 V_185 , T_8 V_237 ,
T_7 V_144 )
{
T_8 V_236 = V_237 << 4 | ( V_13 T_3 ) V_144 ;
F_193 ( V_63 , V_185 , 1 , F_199 , V_236 ) ;
}
static void F_201 ( struct V_226 * V_228 , long V_238 )
{
V_228 -> V_233 = F_25 ( V_239 ) ;
}
void F_202 ( struct V_62 * V_63 , T_8 V_185 )
{
F_193 ( V_63 , V_185 , 1 , F_201 , 0 ) ;
}
static void F_203 ( struct V_226 * V_228 ,
long V_236 )
{
V_228 -> V_233 = 0 ;
V_228 -> V_236 = F_25 ( V_236 ) ;
}
void F_204 ( struct V_62 * V_63 , T_8 V_185 , T_8 V_237 )
{
T_8 V_236 = V_237 << 4 ;
F_193 ( V_63 , V_185 , 1 , F_203 ,
V_236 ) ;
}
int F_68 ( struct V_23 * V_23 , struct V_69 * V_69 , long V_198 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
int V_89 ;
F_37 ( V_63 , V_69 , V_198 & V_159 ) ;
V_89 = F_191 ( V_23 ) ;
F_40 ( V_63 , V_69 , V_198 & V_159 ) ;
return V_89 ;
}
static int F_205 ( struct V_23 * V_23 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
struct V_23 * V_220 = V_71 ( V_63 ) -> V_221 ;
struct V_69 * V_69 ;
int V_89 ;
V_69 = F_52 ( V_220 , V_23 -> V_98 , 0 ) ;
if ( ! V_69 )
return - V_136 ;
F_186 ( V_69 , V_23 ) ;
F_37 ( V_63 , V_69 , 1 ) ;
V_89 = F_167 ( V_220 , V_69 ) ;
F_40 ( V_63 , V_69 , 1 ) ;
F_57 ( V_69 ) ;
return V_89 ;
}
void F_206 ( struct V_23 * V_23 )
{
struct V_62 * V_63 = V_23 -> V_64 ;
struct V_24 * V_25 = V_24 ( V_23 ) ;
struct V_95 * V_96 = V_25 -> V_119 ;
struct V_69 * V_69 ;
if ( ! V_23 -> V_61 ) {
if ( ! ( V_25 -> V_31 & V_240 ) ) {
V_25 -> V_31 |= V_240 ;
if ( F_28 ( V_23 ) > 0 )
F_181 ( V_23 , 0 ) ;
F_205 ( V_23 ) ;
}
}
F_207 ( & V_23 -> V_241 ) ;
F_208 ( V_23 ) ;
F_8 ( V_23 -> V_242 & V_243 && V_23 -> V_61 ) ;
if ( ! V_96 )
return;
if ( ( V_71 ( V_63 ) -> V_244 & V_245 ) ) {
V_96 -> V_113 -> V_189 ( V_23 -> V_64 , V_96 ) ;
return;
}
V_69 = F_190 ( V_23 ) ;
F_8 ( ! V_69 ) ;
F_57 ( V_69 ) ;
}
void F_209 ( struct V_95 * V_96 )
{
struct V_23 * V_23 ;
struct V_69 * V_69 ;
int V_81 , V_145 ;
V_23 = F_125 ( V_96 -> V_63 , V_96 -> V_105 , & V_145 ) ;
V_69 = F_52 ( V_23 , V_96 -> V_1 , V_96 -> V_2 ) ;
V_81 = F_129 ( V_69 ) ;
F_8 ( V_81 ) ;
F_8 ( ! F_86 ( V_69 ) ) ;
F_8 ( V_95 ( V_69 ) != V_96 ) ;
V_81 = F_166 ( V_23 , V_69 , 0 ) ;
F_8 ( V_81 ) ;
F_8 ( F_86 ( V_69 ) || V_69 -> V_246 ) ;
F_57 ( V_69 ) ;
F_127 ( V_23 , V_145 ) ;
}
int F_210 ( struct V_23 * V_23 , const void * V_247 , T_10 V_248 ,
T_9 V_1 , long V_198 , struct V_90 * V_90 )
{
T_9 V_104 = V_1 << V_23 -> V_64 -> V_67 ;
int V_81 ;
struct V_69 * V_69 ;
void * V_249 ;
F_8 ( V_104 & ( V_212 - 1 ) ) ;
F_8 ( V_248 > V_212 ) ;
V_69 = F_52 ( V_23 , V_1 , 0 ) ;
if ( ! V_69 )
return - V_136 ;
V_249 = F_76 ( V_69 ) ;
memcpy ( V_249 , V_247 , V_248 ) ;
F_133 ( V_69 ) ;
F_77 ( V_249 ) ;
if ( F_28 ( V_23 ) < V_104 + V_212 )
F_192 ( V_23 , V_104 + V_212 ) ;
V_81 = F_65 ( V_23 , V_69 , V_198 ) ;
F_57 ( V_69 ) ;
return V_81 ;
}
int F_211 ( struct V_62 * V_63 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
struct V_23 * V_23 ;
V_23 = F_212 ( V_63 , V_250 ) ;
if ( F_126 ( V_23 ) )
return F_189 ( V_23 ) ;
V_72 -> V_231 = V_23 ;
return 0 ;
}
int F_213 ( struct V_62 * V_63 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
int V_251 = 3 * V_72 -> V_252 ;
F_91 ( & V_72 -> V_195 ) ;
F_91 ( & V_72 -> V_161 ) ;
F_214 ( & V_72 -> V_74 ) ;
V_72 -> V_118 = F_215 ( V_251 ,
sizeof( struct V_95 ) ) ;
V_72 -> V_184 = F_215 ( V_251 ,
sizeof( struct V_181 ) ) ;
return 0 ;
}
void F_216 ( struct V_62 * V_63 )
{
struct V_71 * V_72 = V_71 ( V_63 ) ;
F_217 ( V_72 -> V_118 ) ;
F_217 ( V_72 -> V_184 ) ;
}
