void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( ! V_4 ) ;
F_3 ( V_4 -> V_2 . V_5 ) ;
}
static void F_4 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_8 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_10 -> V_11 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
}
static void F_7 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( ! F_8 ( & V_4 -> V_12 ) && V_4 -> V_12 . V_13 &&
! V_5 -> V_14 && ! V_5 -> V_15 )
V_2 -> V_10 -> V_16 ( V_2 ) ;
}
static void F_9 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_8 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
F_7 ( V_5 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
}
static inline void
F_10 ( struct V_1 * V_2 , unsigned int V_17 , unsigned int V_18 )
{
unsigned long V_8 ;
unsigned int V_19 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_19 = V_2 -> V_20 ;
V_2 -> V_20 = ( V_19 & ~ V_18 ) | V_17 ;
if ( V_19 != V_2 -> V_20 )
V_2 -> V_10 -> V_21 ( V_2 , V_2 -> V_20 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
}
static int F_11 ( struct V_6 * V_5 , struct V_3 * V_4 , int V_22 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
unsigned long V_25 ;
int V_26 = 0 ;
if ( V_2 -> V_8 & V_27 )
return 0 ;
F_12 ( V_28 , & V_5 -> V_8 ) ;
if ( V_23 -> type == V_29 )
return 0 ;
if ( ! V_4 -> V_12 . V_13 ) {
V_25 = F_13 ( V_30 ) ;
if ( ! V_25 )
return - V_31 ;
V_4 -> V_12 . V_13 = ( unsigned char * ) V_25 ;
F_14 ( & V_4 -> V_12 ) ;
}
V_26 = V_23 -> V_10 -> V_32 ( V_23 ) ;
if ( V_26 == 0 ) {
if ( F_15 ( V_23 ) && V_23 -> V_33 -> V_34 ) {
V_5 -> V_35 -> V_36 = V_23 -> V_33 -> V_34 ;
V_23 -> V_33 -> V_34 = 0 ;
}
F_16 ( V_5 , V_4 , NULL ) ;
if ( V_22 ) {
if ( V_5 -> V_35 -> V_36 & V_37 )
F_17 ( V_23 , V_38 | V_39 ) ;
}
if ( V_2 -> V_8 & V_40 ) {
F_18 ( & V_23 -> V_9 ) ;
if ( ! ( V_23 -> V_10 -> V_41 ( V_23 ) & V_42 ) )
V_5 -> V_15 = 1 ;
F_19 ( & V_23 -> V_9 ) ;
}
F_12 ( V_43 , & V_2 -> V_8 ) ;
F_20 ( V_28 , & V_5 -> V_8 ) ;
}
if ( V_26 && F_21 ( V_44 ) )
V_26 = 0 ;
return V_26 ;
}
static void F_22 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
if ( V_5 )
F_12 ( V_28 , & V_5 -> V_8 ) ;
if ( F_23 ( V_43 , & V_2 -> V_8 ) ) {
if ( ! V_5 || ( V_5 -> V_35 -> V_36 & V_45 ) )
F_24 ( V_23 , V_39 | V_38 ) ;
F_25 ( & V_2 -> V_46 ) ;
V_23 -> V_10 -> V_47 ( V_23 ) ;
F_26 ( V_23 -> V_48 ) ;
}
F_20 ( V_49 , & V_2 -> V_8 ) ;
if ( V_4 -> V_12 . V_13 ) {
F_27 ( ( unsigned long ) V_4 -> V_12 . V_13 ) ;
V_4 -> V_12 . V_13 = NULL ;
}
}
void
F_28 ( struct V_1 * V_2 , unsigned int V_34 ,
unsigned int V_50 )
{
unsigned int V_51 ;
switch ( V_34 & V_52 ) {
case V_53 :
V_51 = 7 ;
break;
case V_54 :
V_51 = 8 ;
break;
case V_55 :
V_51 = 9 ;
break;
default:
V_51 = 10 ;
break;
}
if ( V_34 & V_56 )
V_51 ++ ;
if ( V_34 & V_57 )
V_51 ++ ;
V_51 = V_51 * V_2 -> V_58 ;
V_2 -> V_59 = ( V_60 * V_51 ) / V_50 + V_60 / 50 ;
}
unsigned int
F_29 ( struct V_1 * V_2 , struct V_61 * V_35 ,
struct V_61 * V_19 , unsigned int V_62 , unsigned int V_63 )
{
unsigned int V_64 , V_50 , V_65 = 38400 ;
int V_66 = 0 ;
T_1 V_8 = V_2 -> V_8 & V_67 ;
if ( V_8 == V_68 )
V_65 = 57600 ;
else if ( V_8 == V_69 )
V_65 = 115200 ;
else if ( V_8 == V_70 )
V_65 = 230400 ;
else if ( V_8 == V_71 )
V_65 = 460800 ;
for ( V_64 = 0 ; V_64 < 2 ; V_64 ++ ) {
V_50 = F_30 ( V_35 ) ;
if ( V_50 == 38400 )
V_50 = V_65 ;
if ( V_50 == 0 ) {
V_66 = 1 ;
V_50 = 9600 ;
}
if ( V_50 >= V_62 && V_50 <= V_63 )
return V_50 ;
V_35 -> V_36 &= ~ V_37 ;
if ( V_19 ) {
V_50 = F_30 ( V_19 ) ;
if ( ! V_66 )
F_31 ( V_35 ,
V_50 , V_50 ) ;
V_19 = NULL ;
continue;
}
if ( ! V_66 ) {
if ( V_50 <= V_62 )
F_31 ( V_35 ,
V_62 + 1 , V_62 + 1 ) ;
else
F_31 ( V_35 ,
V_63 - 1 , V_63 - 1 ) ;
}
}
F_32 ( 1 ) ;
return 0 ;
}
unsigned int
F_33 ( struct V_1 * V_2 , unsigned int V_50 )
{
unsigned int V_72 ;
if ( V_50 == 38400 && ( V_2 -> V_8 & V_67 ) == V_73 )
V_72 = V_2 -> V_74 ;
else
V_72 = ( V_2 -> V_75 + ( 8 * V_50 ) ) / ( 16 * V_50 ) ;
return V_72 ;
}
static void F_16 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_61 * V_76 )
{
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_61 * V_35 ;
if ( ! V_5 || ! V_5 -> V_35 || V_23 -> type == V_29 )
return;
V_35 = V_5 -> V_35 ;
if ( V_35 -> V_36 & V_77 )
F_12 ( V_78 , & V_2 -> V_8 ) ;
else
F_20 ( V_78 , & V_2 -> V_8 ) ;
if ( V_35 -> V_36 & V_79 )
F_20 ( V_80 , & V_2 -> V_8 ) ;
else
F_12 ( V_80 , & V_2 -> V_8 ) ;
V_23 -> V_10 -> V_81 ( V_23 , V_35 , V_76 ) ;
}
static inline int F_34 ( struct V_1 * V_2 ,
struct V_82 * V_83 , unsigned char V_84 )
{
unsigned long V_8 ;
int V_85 = 0 ;
if ( ! V_83 -> V_13 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
if ( F_35 ( V_83 ) != 0 ) {
V_83 -> V_13 [ V_83 -> V_86 ] = V_84 ;
V_83 -> V_86 = ( V_83 -> V_86 + 1 ) & ( V_87 - 1 ) ;
V_85 = 1 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
return V_85 ;
}
static int F_36 ( struct V_6 * V_5 , unsigned char V_88 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
return F_34 ( V_4 -> V_1 , & V_4 -> V_12 , V_88 ) ;
}
static void F_37 ( struct V_6 * V_5 )
{
F_9 ( V_5 ) ;
}
static int F_38 ( struct V_6 * V_5 ,
const unsigned char * V_13 , int V_89 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 ;
struct V_82 * V_83 ;
unsigned long V_8 ;
int V_84 , V_85 = 0 ;
if ( ! V_4 ) {
F_32 ( 1 ) ;
return - V_90 ;
}
V_2 = V_4 -> V_1 ;
V_83 = & V_4 -> V_12 ;
if ( ! V_83 -> V_13 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
while ( 1 ) {
V_84 = F_39 ( V_83 -> V_86 , V_83 -> V_91 , V_87 ) ;
if ( V_89 < V_84 )
V_84 = V_89 ;
if ( V_84 <= 0 )
break;
memcpy ( V_83 -> V_13 + V_83 -> V_86 , V_13 , V_84 ) ;
V_83 -> V_86 = ( V_83 -> V_86 + V_84 ) & ( V_87 - 1 ) ;
V_13 += V_84 ;
V_89 -= V_84 ;
V_85 += V_84 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_9 ( V_5 ) ;
return V_85 ;
}
static int F_40 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_85 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_85 = F_35 ( & V_4 -> V_12 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_85 ;
}
static int F_41 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_85 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_85 = F_42 ( & V_4 -> V_12 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_85 ;
}
static void F_43 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 ;
unsigned long V_8 ;
if ( ! V_4 ) {
F_32 ( 1 ) ;
return;
}
V_2 = V_4 -> V_1 ;
F_44 ( L_1 , V_5 -> V_92 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
F_14 ( & V_4 -> V_12 ) ;
if ( V_2 -> V_10 -> V_93 )
V_2 -> V_10 -> V_93 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_3 ( V_5 ) ;
}
static void F_45 ( struct V_6 * V_5 , char V_88 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_8 ;
if ( V_2 -> V_10 -> V_94 )
V_2 -> V_10 -> V_94 ( V_2 , V_88 ) ;
else {
V_2 -> V_95 = V_88 ;
if ( V_88 ) {
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_10 -> V_16 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
}
}
}
static void F_46 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
if ( F_47 ( V_5 ) )
F_45 ( V_5 , F_48 ( V_5 ) ) ;
if ( V_5 -> V_35 -> V_36 & V_77 )
F_24 ( V_4 -> V_1 , V_38 ) ;
}
static void F_49 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( F_47 ( V_5 ) ) {
if ( V_2 -> V_95 )
V_2 -> V_95 = 0 ;
else
F_45 ( V_5 , F_50 ( V_5 ) ) ;
}
if ( V_5 -> V_35 -> V_36 & V_77 )
F_17 ( V_2 , V_38 ) ;
}
static int F_51 ( struct V_3 * V_4 ,
struct V_96 T_2 * V_97 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_96 V_98 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
F_52 ( & V_2 -> V_99 ) ;
V_98 . type = V_23 -> type ;
V_98 . line = V_23 -> line ;
V_98 . V_2 = V_23 -> V_100 ;
if ( V_101 )
V_98 . V_102 = ( long ) V_23 -> V_100 >> V_101 ;
V_98 . V_48 = V_23 -> V_48 ;
V_98 . V_8 = V_23 -> V_8 ;
V_98 . V_103 = V_23 -> V_58 ;
V_98 . V_104 = V_23 -> V_75 / 16 ;
V_98 . V_105 = V_2 -> V_105 / 10 ;
V_98 . V_106 = V_2 -> V_106 == V_107 ?
V_107 :
V_2 -> V_106 / 10 ;
V_98 . V_74 = V_23 -> V_74 ;
V_98 . V_108 = V_23 -> V_108 ;
V_98 . V_109 = V_23 -> V_110 ;
V_98 . V_111 = V_23 -> V_112 ;
V_98 . V_113 = ( void * ) ( unsigned long ) V_23 -> V_114 ;
F_53 ( & V_2 -> V_99 ) ;
if ( F_54 ( V_97 , & V_98 , sizeof( * V_97 ) ) )
return - V_115 ;
return 0 ;
}
static int F_55 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_96 T_2 * V_116 )
{
struct V_96 V_117 ;
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
unsigned long V_118 ;
unsigned int V_119 , V_120 , V_106 ;
unsigned int V_121 , V_105 ;
T_1 V_122 , V_123 ;
int V_26 = 0 ;
if ( F_56 ( & V_117 , V_116 , sizeof( V_117 ) ) )
return - V_115 ;
V_118 = V_117 . V_2 ;
if ( V_101 )
V_118 += ( unsigned long ) V_117 . V_102 << V_101 ;
V_117 . V_48 = F_57 ( V_117 . V_48 ) ;
V_105 = V_117 . V_105 * 10 ;
V_106 = V_117 . V_106 == V_107 ?
V_107 : V_117 . V_106 * 10 ;
F_52 ( & V_2 -> V_99 ) ;
V_119 = ! ( V_23 -> V_8 & V_124 )
&& V_117 . V_48 != V_23 -> V_48 ;
V_120 = ! ( V_23 -> V_8 & V_124 )
&& ( V_118 != V_23 -> V_100 ||
( unsigned long ) V_117 . V_113 != V_23 -> V_114 ||
V_117 . V_108 != V_23 -> V_108 ||
V_117 . V_109 != V_23 -> V_110 ||
V_117 . V_111 != V_23 -> V_112 ||
V_117 . type != V_23 -> type ) ;
V_122 = V_23 -> V_8 ;
V_123 = V_117 . V_8 ;
V_121 = V_23 -> V_74 ;
if ( ! F_21 ( V_44 ) ) {
V_26 = - V_125 ;
if ( V_119 || V_120 ||
( V_117 . V_104 != V_23 -> V_75 / 16 ) ||
( V_105 != V_2 -> V_105 ) ||
( V_106 != V_2 -> V_106 ) ||
( V_117 . V_103 &&
V_117 . V_103 != V_23 -> V_58 ) ||
( ( ( V_123 ^ V_122 ) & ~ V_126 ) != 0 ) )
goto exit;
V_23 -> V_8 = ( ( V_23 -> V_8 & ~ V_126 ) |
( V_123 & V_126 ) ) ;
V_23 -> V_74 = V_117 . V_74 ;
goto V_127;
}
if ( V_23 -> V_10 -> V_128 )
V_26 = V_23 -> V_10 -> V_128 ( V_23 , & V_117 ) ;
if ( ( V_117 . V_48 >= V_129 ) || ( V_117 . V_48 < 0 ) ||
( V_117 . V_104 < 9600 ) )
V_26 = - V_130 ;
if ( V_26 )
goto exit;
if ( V_120 || V_119 ) {
V_26 = - V_131 ;
if ( F_58 ( V_2 ) > 1 )
goto exit;
F_22 ( V_5 , V_4 ) ;
}
if ( V_120 ) {
unsigned long V_132 , V_133 ;
unsigned int V_134 , V_135 , V_136 , V_137 ;
V_132 = V_23 -> V_100 ;
V_133 = V_23 -> V_114 ;
V_134 = V_23 -> type ;
V_136 = V_23 -> V_108 ;
V_135 = V_23 -> V_110 ;
V_137 = V_23 -> V_112 ;
if ( V_134 != V_29 )
V_23 -> V_10 -> V_138 ( V_23 ) ;
V_23 -> V_100 = V_118 ;
V_23 -> type = V_117 . type ;
V_23 -> V_108 = V_117 . V_108 ;
V_23 -> V_110 = V_117 . V_109 ;
V_23 -> V_112 = V_117 . V_111 ;
V_23 -> V_114 = ( unsigned long ) V_117 . V_113 ;
if ( V_23 -> type != V_29 ) {
V_26 = V_23 -> V_10 -> V_139 ( V_23 ) ;
} else {
V_26 = 0 ;
}
if ( V_26 && V_134 != V_29 ) {
V_23 -> V_100 = V_132 ;
V_23 -> type = V_134 ;
V_23 -> V_108 = V_136 ;
V_23 -> V_110 = V_135 ;
V_23 -> V_112 = V_137 ;
V_23 -> V_114 = V_133 ;
V_26 = V_23 -> V_10 -> V_139 ( V_23 ) ;
if ( V_26 )
V_23 -> type = V_29 ;
V_26 = - V_131 ;
goto exit;
}
}
if ( V_119 )
V_23 -> V_48 = V_117 . V_48 ;
if ( ! ( V_23 -> V_8 & V_124 ) )
V_23 -> V_75 = V_117 . V_104 * 16 ;
V_23 -> V_8 = ( V_23 -> V_8 & ~ V_140 ) |
( V_123 & V_140 ) ;
V_23 -> V_74 = V_117 . V_74 ;
V_2 -> V_105 = V_105 ;
V_2 -> V_106 = V_106 ;
if ( V_117 . V_103 )
V_23 -> V_58 = V_117 . V_103 ;
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_141 =
( V_23 -> V_8 & V_142 ) ? 1 : 0 ;
V_127:
V_26 = 0 ;
if ( V_23 -> type == V_29 )
goto exit;
if ( V_2 -> V_8 & V_27 ) {
if ( ( ( V_122 ^ V_23 -> V_8 ) & V_67 ) ||
V_121 != V_23 -> V_74 ) {
if ( V_23 -> V_8 & V_67 ) {
char V_13 [ 64 ] ;
F_59 ( V_143
L_2
L_3 , V_144 -> V_145 ,
F_60 ( V_2 -> V_5 , V_13 ) ) ;
}
F_16 ( V_5 , V_4 , NULL ) ;
}
} else
V_26 = F_11 ( V_5 , V_4 , 1 ) ;
exit:
F_53 ( & V_2 -> V_99 ) ;
return V_26 ;
}
static int F_61 ( struct V_6 * V_5 ,
struct V_3 * V_4 , unsigned int T_2 * V_146 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
unsigned int V_147 ;
V_147 = V_23 -> V_10 -> V_148 ( V_23 ) ;
if ( V_23 -> V_95 ||
( ( F_42 ( & V_4 -> V_12 ) > 0 ) &&
! V_5 -> V_14 && ! V_5 -> V_15 ) )
V_147 &= ~ V_149 ;
return F_62 ( V_147 , V_146 ) ;
}
static int F_63 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
int V_147 = - V_150 ;
F_52 ( & V_2 -> V_99 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_28 ) ) ) {
V_147 = V_23 -> V_20 ;
F_18 ( & V_23 -> V_9 ) ;
V_147 |= V_23 -> V_10 -> V_41 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
}
F_53 ( & V_2 -> V_99 ) ;
return V_147 ;
}
static int
F_64 ( struct V_6 * V_5 , unsigned int V_17 , unsigned int V_18 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_85 = - V_150 ;
F_52 ( & V_2 -> V_99 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_28 ) ) ) {
F_10 ( V_23 , V_17 , V_18 ) ;
V_85 = 0 ;
}
F_53 ( & V_2 -> V_99 ) ;
return V_85 ;
}
static int F_65 ( struct V_6 * V_5 , int V_151 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_52 ( & V_2 -> V_99 ) ;
if ( V_23 -> type != V_29 )
V_23 -> V_10 -> V_152 ( V_23 , V_151 ) ;
F_53 ( & V_2 -> V_99 ) ;
return 0 ;
}
static int F_66 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_8 , V_85 ;
if ( ! F_21 ( V_44 ) )
return - V_125 ;
if ( F_67 ( & V_2 -> V_99 ) )
return - V_153 ;
V_85 = - V_131 ;
if ( F_58 ( V_2 ) == 1 ) {
F_22 ( V_5 , V_4 ) ;
if ( V_23 -> type != V_29 )
V_23 -> V_10 -> V_138 ( V_23 ) ;
V_8 = V_154 ;
if ( V_23 -> V_8 & V_155 )
V_8 |= V_156 ;
V_23 -> V_10 -> V_157 ( V_23 , V_8 ) ;
V_85 = F_11 ( V_5 , V_4 , 1 ) ;
}
F_53 ( & V_2 -> V_99 ) ;
return V_85 ;
}
static int
F_68 ( struct V_3 * V_4 , unsigned long V_158 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_69 ( V_159 , V_144 ) ;
struct V_160 V_161 , V_162 ;
int V_85 ;
F_18 ( & V_23 -> V_9 ) ;
memcpy ( & V_161 , & V_23 -> V_163 , sizeof( struct V_160 ) ) ;
V_23 -> V_10 -> V_164 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
F_70 ( & V_2 -> V_46 , & V_159 ) ;
for (; ; ) {
F_18 ( & V_23 -> V_9 ) ;
memcpy ( & V_162 , & V_23 -> V_163 , sizeof( struct V_160 ) ) ;
F_19 ( & V_23 -> V_9 ) ;
F_71 ( V_165 ) ;
if ( ( ( V_158 & V_166 ) && ( V_162 . V_167 != V_161 . V_167 ) ) ||
( ( V_158 & V_168 ) && ( V_162 . V_169 != V_161 . V_169 ) ) ||
( ( V_158 & V_170 ) && ( V_162 . V_171 != V_161 . V_171 ) ) ||
( ( V_158 & V_42 ) && ( V_162 . V_172 != V_161 . V_172 ) ) ) {
V_85 = 0 ;
break;
}
F_72 () ;
if ( F_73 ( V_144 ) ) {
V_85 = - V_153 ;
break;
}
V_161 = V_162 ;
}
V_144 -> V_4 = V_173 ;
F_74 ( & V_2 -> V_46 , & V_159 ) ;
return V_85 ;
}
static int F_75 ( struct V_6 * V_5 ,
struct V_174 * V_163 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_160 V_162 ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_18 ( & V_23 -> V_9 ) ;
memcpy ( & V_162 , & V_23 -> V_163 , sizeof( struct V_160 ) ) ;
F_19 ( & V_23 -> V_9 ) ;
V_163 -> V_172 = V_162 . V_172 ;
V_163 -> V_169 = V_162 . V_169 ;
V_163 -> V_167 = V_162 . V_167 ;
V_163 -> V_171 = V_162 . V_171 ;
V_163 -> V_175 = V_162 . V_175 ;
V_163 -> V_176 = V_162 . V_176 ;
V_163 -> V_177 = V_162 . V_177 ;
V_163 -> V_178 = V_162 . V_178 ;
V_163 -> V_179 = V_162 . V_179 ;
V_163 -> V_180 = V_162 . V_180 ;
V_163 -> V_181 = V_162 . V_181 ;
return 0 ;
}
static int
F_76 ( struct V_6 * V_5 , unsigned int V_182 ,
unsigned long V_158 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
void T_2 * V_183 = ( void T_2 * ) V_158 ;
int V_85 = - V_184 ;
switch ( V_182 ) {
case V_185 :
V_85 = F_51 ( V_4 , V_183 ) ;
break;
case V_186 :
V_85 = F_55 ( V_5 , V_4 , V_183 ) ;
break;
case V_187 :
V_85 = F_66 ( V_5 , V_4 ) ;
break;
case V_188 :
case V_189 :
V_85 = 0 ;
break;
}
if ( V_85 != - V_184 )
goto V_190;
if ( V_5 -> V_8 & ( 1 << V_28 ) ) {
V_85 = - V_150 ;
goto V_190;
}
switch ( V_182 ) {
case V_191 :
V_85 = F_68 ( V_4 , V_158 ) ;
break;
}
if ( V_85 != - V_184 )
goto V_190;
F_52 ( & V_2 -> V_99 ) ;
if ( V_5 -> V_8 & ( 1 << V_28 ) ) {
V_85 = - V_150 ;
goto V_192;
}
switch ( V_182 ) {
case V_193 :
V_85 = F_61 ( V_5 , V_4 , V_183 ) ;
break;
default: {
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_23 -> V_10 -> V_194 )
V_85 = V_23 -> V_10 -> V_194 ( V_23 , V_182 , V_158 ) ;
break;
}
}
V_192:
F_53 ( & V_2 -> V_99 ) ;
V_190:
return V_85 ;
}
static void F_77 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_23 -> V_10 -> V_195 )
V_23 -> V_10 -> V_195 ( V_23 , V_5 -> V_35 -> V_196 ) ;
}
static void F_78 ( struct V_6 * V_5 ,
struct V_61 * V_76 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
unsigned int V_34 = V_5 -> V_35 -> V_36 ;
#define F_79 ( T_3 ) ((iflag) & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK))
if ( ( V_34 ^ V_76 -> V_36 ) == 0 &&
V_5 -> V_35 -> V_197 == V_76 -> V_197 &&
V_5 -> V_35 -> V_198 == V_76 -> V_198 &&
F_79 ( V_5 -> V_35 -> V_199 ^ V_76 -> V_199 ) == 0 ) {
return;
}
F_16 ( V_5 , V_4 , V_76 ) ;
if ( ( V_76 -> V_36 & V_37 ) && ! ( V_34 & V_37 ) )
F_24 ( V_4 -> V_1 , V_38 | V_39 ) ;
else if ( ! ( V_76 -> V_36 & V_37 ) && ( V_34 & V_37 ) ) {
unsigned int V_200 = V_39 ;
if ( ! ( V_34 & V_77 ) ||
! F_80 ( V_201 , & V_5 -> V_8 ) )
V_200 |= V_38 ;
F_17 ( V_4 -> V_1 , V_200 ) ;
}
if ( ( V_76 -> V_36 & V_77 ) && ! ( V_34 & V_77 ) ) {
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_5 -> V_15 = 0 ;
F_7 ( V_5 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
}
else if ( ! ( V_76 -> V_36 & V_77 ) && ( V_34 & V_77 ) ) {
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
if ( ! ( V_4 -> V_1 -> V_10 -> V_41 ( V_4 -> V_1 ) & V_42 ) ) {
V_5 -> V_15 = 1 ;
V_4 -> V_1 -> V_10 -> V_11 ( V_4 -> V_1 ) ;
}
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
}
}
static void F_81 ( struct V_6 * V_5 , struct V_202 * V_203 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 ;
struct V_1 * V_23 ;
unsigned long V_8 ;
if ( ! V_4 )
return;
V_23 = V_4 -> V_1 ;
V_2 = & V_4 -> V_2 ;
F_44 ( L_4 , V_23 -> line ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
if ( F_82 ( V_203 ) ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
return;
}
if ( ( V_5 -> V_89 == 1 ) && ( V_2 -> V_89 != 1 ) ) {
F_59 ( V_204 L_5
L_6 , V_2 -> V_89 ) ;
V_2 -> V_89 = 1 ;
}
if ( -- V_2 -> V_89 < 0 ) {
F_59 ( V_204 L_7 ,
V_5 -> V_205 , V_2 -> V_89 ) ;
V_2 -> V_89 = 0 ;
}
if ( V_2 -> V_89 ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
return;
}
F_12 ( V_206 , & V_2 -> V_8 ) ;
V_5 -> V_207 = 1 ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_106 != V_107 )
F_83 ( V_5 ,
F_84 ( V_2 -> V_106 ) ) ;
if ( V_2 -> V_8 & V_27 ) {
unsigned long V_8 ;
F_5 ( & V_23 -> V_9 , V_8 ) ;
V_23 -> V_10 -> V_208 ( V_23 ) ;
F_6 ( & V_23 -> V_9 , V_8 ) ;
F_85 ( V_5 , V_23 -> V_59 ) ;
}
F_52 ( & V_2 -> V_99 ) ;
F_22 ( V_5 , V_4 ) ;
F_43 ( V_5 ) ;
F_86 ( V_5 ) ;
F_87 ( V_2 , NULL ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_5 -> V_207 = 0 ;
if ( V_2 -> V_209 ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_105 )
F_88 ( V_2 -> V_105 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
} else if ( ! F_15 ( V_23 ) ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_89 ( V_4 , 3 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
}
F_20 ( V_210 , & V_2 -> V_8 ) ;
F_20 ( V_206 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_25 ( & V_2 -> V_211 ) ;
F_25 ( & V_2 -> V_212 ) ;
F_53 ( & V_2 -> V_99 ) ;
}
static void F_85 ( struct V_6 * V_5 , int V_59 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_213 , V_214 ;
if ( V_2 -> type == V_29 || V_2 -> V_58 == 0 )
return;
V_213 = ( V_2 -> V_59 - V_60 / 50 ) / V_2 -> V_58 ;
V_213 = V_213 / 5 ;
if ( V_213 == 0 )
V_213 = 1 ;
if ( V_59 && V_59 < V_213 )
V_213 = V_59 ;
if ( V_59 == 0 || V_59 > 2 * V_2 -> V_59 )
V_59 = 2 * V_2 -> V_59 ;
V_214 = V_215 + V_59 ;
F_44 ( L_8 ,
V_2 -> line , V_215 , V_214 ) ;
while ( ! V_2 -> V_10 -> V_148 ( V_2 ) ) {
F_88 ( F_90 ( V_213 ) ) ;
if ( F_73 ( V_144 ) )
break;
if ( F_91 ( V_215 , V_214 ) )
break;
}
}
static void F_92 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
unsigned long V_8 ;
F_44 ( L_9 , V_4 -> V_1 -> line ) ;
F_52 ( & V_2 -> V_99 ) ;
if ( V_2 -> V_8 & V_216 ) {
F_43 ( V_5 ) ;
F_22 ( V_5 , V_4 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_89 = 0 ;
F_20 ( V_210 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_87 ( V_2 , NULL ) ;
F_25 ( & V_2 -> V_211 ) ;
F_25 ( & V_2 -> V_46 ) ;
}
F_53 ( & V_2 -> V_99 ) ;
}
static int F_93 ( struct V_24 * V_2 )
{
struct V_3 * V_4 = F_94 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
int V_20 ;
F_18 ( & V_23 -> V_9 ) ;
V_23 -> V_10 -> V_164 ( V_23 ) ;
V_20 = V_23 -> V_10 -> V_41 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
if ( V_20 & V_217 )
return 1 ;
return 0 ;
}
static void F_95 ( struct V_24 * V_2 , int V_218 )
{
struct V_3 * V_4 = F_94 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_218 )
F_17 ( V_23 , V_39 | V_38 ) ;
else
F_24 ( V_23 , V_39 | V_38 ) ;
}
static struct V_3 * F_96 ( struct V_219 * V_220 , int line )
{
struct V_3 * V_4 ;
struct V_24 * V_2 ;
int V_85 = 0 ;
V_4 = V_220 -> V_4 + line ;
V_2 = & V_4 -> V_2 ;
if ( F_67 ( & V_2 -> V_99 ) ) {
V_85 = - V_153 ;
goto V_221;
}
V_2 -> V_89 ++ ;
if ( ! V_4 -> V_1 || V_4 -> V_1 -> V_8 & V_222 ) {
V_85 = - V_223 ;
goto V_224;
}
return V_4 ;
V_224:
V_2 -> V_89 -- ;
F_53 ( & V_2 -> V_99 ) ;
V_221:
return F_97 ( V_85 ) ;
}
static int F_98 ( struct V_6 * V_5 , struct V_202 * V_203 )
{
struct V_219 * V_220 = (struct V_219 * ) V_5 -> V_225 -> V_226 ;
struct V_3 * V_4 ;
struct V_24 * V_2 ;
int V_26 , line = V_5 -> V_92 ;
F_44 ( L_10 , line ) ;
V_4 = F_96 ( V_220 , line ) ;
if ( F_99 ( V_4 ) ) {
V_26 = F_100 ( V_4 ) ;
goto V_227;
}
V_2 = & V_4 -> V_2 ;
V_5 -> V_7 = V_4 ;
V_4 -> V_1 -> V_4 = V_4 ;
V_5 -> V_141 = ( V_4 -> V_1 -> V_8 & V_142 ) ? 1 : 0 ;
V_5 -> V_228 = 0 ;
F_87 ( V_2 , V_5 ) ;
if ( F_82 ( V_203 ) ) {
V_26 = - V_229 ;
V_2 -> V_89 -- ;
F_53 ( & V_2 -> V_99 ) ;
goto V_227;
}
if ( V_2 -> V_89 == 1 )
F_89 ( V_4 , 0 ) ;
V_26 = F_11 ( V_5 , V_4 , 0 ) ;
F_53 ( & V_2 -> V_99 ) ;
if ( V_26 == 0 )
V_26 = F_101 ( V_2 , V_5 , V_203 ) ;
V_227:
return V_26 ;
}
static const char * F_102 ( struct V_1 * V_2 )
{
const char * V_230 = NULL ;
if ( V_2 -> V_10 -> type )
V_230 = V_2 -> V_10 -> type ( V_2 ) ;
if ( ! V_230 )
V_230 = L_11 ;
return V_230 ;
}
static void F_103 ( struct V_231 * V_232 , struct V_219 * V_220 , int V_233 )
{
struct V_3 * V_4 = V_220 -> V_4 + V_233 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_234 ;
struct V_1 * V_23 = V_4 -> V_1 ;
char V_235 [ 32 ] ;
unsigned int V_236 ;
int V_237 ;
if ( ! V_23 )
return;
V_237 = V_23 -> V_110 >= V_238 ;
F_104 ( V_232 , L_12 ,
V_23 -> line , F_102 ( V_23 ) ,
V_237 ? L_13 : L_14 ,
V_237 ? ( unsigned long long ) V_23 -> V_114
: ( unsigned long long ) V_23 -> V_100 ,
V_23 -> V_48 ) ;
if ( V_23 -> type == V_29 ) {
F_105 ( V_232 , '\n' ) ;
return;
}
if ( F_21 ( V_44 ) ) {
F_52 ( & V_2 -> V_99 ) ;
V_234 = V_4 -> V_234 ;
if ( V_234 )
F_89 ( V_4 , 0 ) ;
F_18 ( & V_23 -> V_9 ) ;
V_236 = V_23 -> V_10 -> V_41 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
if ( V_234 )
F_89 ( V_4 , V_234 ) ;
F_53 ( & V_2 -> V_99 ) ;
F_104 ( V_232 , L_15 ,
V_23 -> V_163 . V_176 , V_23 -> V_163 . V_175 ) ;
if ( V_23 -> V_163 . V_177 )
F_104 ( V_232 , L_16 ,
V_23 -> V_163 . V_177 ) ;
if ( V_23 -> V_163 . V_179 )
F_104 ( V_232 , L_17 ,
V_23 -> V_163 . V_179 ) ;
if ( V_23 -> V_163 . V_180 )
F_104 ( V_232 , L_18 ,
V_23 -> V_163 . V_180 ) ;
if ( V_23 -> V_163 . V_178 )
F_104 ( V_232 , L_19 ,
V_23 -> V_163 . V_178 ) ;
#define F_106 ( T_4 , V_230 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_107 ( T_4 , V_230 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_235 [ 0 ] = '\0' ;
V_235 [ 1 ] = '\0' ;
F_106 ( V_38 , L_20 ) ;
F_107 ( V_42 , L_21 ) ;
F_106 ( V_39 , L_22 ) ;
F_107 ( V_168 , L_23 ) ;
F_107 ( V_217 , L_24 ) ;
F_107 ( V_166 , L_25 ) ;
if ( V_235 [ 0 ] )
V_235 [ 0 ] = ' ' ;
F_108 ( V_232 , V_235 ) ;
}
F_105 ( V_232 , '\n' ) ;
#undef F_107
#undef F_106
}
static int F_109 ( struct V_231 * V_232 , void * V_239 )
{
struct V_240 * V_241 = V_232 -> V_242 ;
struct V_219 * V_220 = V_241 -> V_226 ;
int V_233 ;
F_104 ( V_232 , L_26 ,
L_27 , L_27 , L_27 ) ;
for ( V_233 = 0 ; V_233 < V_220 -> V_243 ; V_233 ++ )
F_103 ( V_232 , V_220 , V_233 ) ;
return 0 ;
}
static int F_110 ( struct V_244 * V_244 , struct V_202 * V_202 )
{
return F_111 ( V_202 , F_109 , F_112 ( V_244 ) -> V_245 ) ;
}
void F_113 ( struct V_1 * V_2 , const char * V_246 ,
unsigned int V_89 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_233 ;
for ( V_233 = 0 ; V_233 < V_89 ; V_233 ++ , V_246 ++ ) {
if ( * V_246 == '\n' )
putchar ( V_2 , '\r' ) ;
putchar ( V_2 , * V_246 ) ;
}
}
struct V_1 * T_5
F_114 ( struct V_1 * V_247 , int V_243 , struct V_248 * V_249 )
{
int V_250 = V_249 -> V_92 ;
if ( V_250 < 0 || V_250 >= V_243 || ( V_247 [ V_250 ] . V_100 == 0 &&
V_247 [ V_250 ] . V_251 == NULL ) )
for ( V_250 = 0 ; V_250 < V_243 ; V_250 ++ )
if ( V_247 [ V_250 ] . V_100 != 0 ||
V_247 [ V_250 ] . V_251 != NULL )
break;
V_249 -> V_92 = V_250 ;
return V_247 + V_250 ;
}
void
F_115 ( char * V_252 , int * V_50 , int * V_179 , int * V_51 , int * V_253 )
{
char * V_246 = V_252 ;
* V_50 = F_116 ( V_246 , NULL , 10 ) ;
while ( * V_246 >= '0' && * V_246 <= '9' )
V_246 ++ ;
if ( * V_246 )
* V_179 = * V_246 ++ ;
if ( * V_246 )
* V_51 = * V_246 ++ - '0' ;
if ( * V_246 )
* V_253 = * V_246 ;
}
int
F_117 ( struct V_1 * V_2 , struct V_248 * V_249 ,
int V_50 , int V_179 , int V_51 , int V_253 )
{
struct V_61 V_35 ;
static struct V_61 V_254 ;
int V_233 ;
F_118 ( & V_2 -> V_9 ) ;
F_119 ( & V_2 -> V_9 , & V_255 ) ;
memset ( & V_35 , 0 , sizeof( struct V_61 ) ) ;
V_35 . V_36 = V_256 | V_45 | V_79 ;
for ( V_233 = 0 ; V_257 [ V_233 ] . V_258 ; V_233 ++ )
if ( V_257 [ V_233 ] . V_258 <= V_50 )
break;
V_35 . V_36 |= V_257 [ V_233 ] . V_34 ;
if ( V_51 == 7 )
V_35 . V_36 |= V_55 ;
else
V_35 . V_36 |= V_259 ;
switch ( V_179 ) {
case 'o' : case 'O' :
V_35 . V_36 |= V_260 ;
case 'e' : case 'E' :
V_35 . V_36 |= V_57 ;
break;
}
if ( V_253 == 'r' )
V_35 . V_36 |= V_77 ;
V_2 -> V_20 |= V_39 ;
V_2 -> V_10 -> V_81 ( V_2 , & V_35 , & V_254 ) ;
if ( V_249 )
V_249 -> V_34 = V_35 . V_36 ;
return 0 ;
}
static void F_89 ( struct V_3 * V_4 , int V_234 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
if ( V_4 -> V_234 != V_234 ) {
if ( V_2 -> V_10 -> V_261 )
V_2 -> V_10 -> V_261 ( V_2 , V_234 , V_4 -> V_234 ) ;
V_4 -> V_234 = V_234 ;
}
}
static int F_120 ( struct V_262 * V_263 , void * V_245 )
{
struct V_264 * V_265 = V_245 ;
struct V_240 * V_266 = V_265 -> V_225 -> V_240 ;
T_6 V_267 = F_121 ( V_266 -> V_268 , V_266 -> V_269 ) +
V_265 -> V_2 -> line ;
return V_263 -> V_267 == V_267 ;
}
int F_122 ( struct V_219 * V_220 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_220 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_262 * V_270 ;
struct V_264 V_265 = { V_23 , V_220 } ;
F_52 ( & V_2 -> V_99 ) ;
V_270 = F_123 ( V_23 -> V_263 , & V_265 , F_120 ) ;
if ( F_124 ( V_270 ) ) {
if ( ! F_125 ( V_23 -> V_48 ) )
V_23 -> V_271 = 1 ;
F_126 ( V_270 ) ;
F_53 ( & V_2 -> V_99 ) ;
return 0 ;
}
if ( V_272 || ! F_15 ( V_23 ) )
V_23 -> V_273 = 1 ;
if ( V_2 -> V_8 & V_27 ) {
const struct V_274 * V_10 = V_23 -> V_10 ;
int V_275 ;
if ( V_272 || ! F_15 ( V_23 ) ) {
F_12 ( V_49 , & V_2 -> V_8 ) ;
F_20 ( V_43 , & V_2 -> V_8 ) ;
F_18 ( & V_23 -> V_9 ) ;
V_10 -> V_11 ( V_23 ) ;
V_10 -> V_21 ( V_23 , 0 ) ;
V_10 -> V_208 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
}
for ( V_275 = 3 ; ! V_10 -> V_148 ( V_23 ) && V_275 ; V_275 -- )
F_127 ( 10 ) ;
if ( ! V_275 )
F_59 ( V_204 L_28
L_29 ,
V_23 -> V_263 ? F_128 ( V_23 -> V_263 ) : L_27 ,
V_23 -> V_263 ? L_30 : L_27 ,
V_220 -> F_128 ,
V_220 -> V_240 -> V_276 + V_23 -> line ) ;
if ( V_272 || ! F_15 ( V_23 ) )
V_10 -> V_47 ( V_23 ) ;
}
if ( V_272 && F_15 ( V_23 ) )
F_129 ( V_23 -> V_33 ) ;
if ( V_272 || ! F_15 ( V_23 ) )
F_89 ( V_4 , 3 ) ;
F_53 ( & V_2 -> V_99 ) ;
return 0 ;
}
int F_130 ( struct V_219 * V_220 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_220 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_262 * V_270 ;
struct V_264 V_265 = { V_23 , V_220 } ;
struct V_61 V_35 ;
F_52 ( & V_2 -> V_99 ) ;
V_270 = F_123 ( V_23 -> V_263 , & V_265 , F_120 ) ;
if ( ! V_23 -> V_273 && F_124 ( V_270 ) ) {
if ( V_23 -> V_271 ) {
F_131 ( V_23 -> V_48 ) ;
V_23 -> V_271 = 0 ;
}
F_53 ( & V_2 -> V_99 ) ;
return 0 ;
}
V_23 -> V_273 = 0 ;
if ( F_15 ( V_23 ) ) {
memset ( & V_35 , 0 , sizeof( struct V_61 ) ) ;
V_35 . V_36 = V_23 -> V_33 -> V_34 ;
if ( V_2 -> V_5 && V_2 -> V_5 -> V_35 && V_35 . V_36 == 0 )
V_35 = * ( V_2 -> V_5 -> V_35 ) ;
if ( V_272 )
F_89 ( V_4 , 0 ) ;
V_23 -> V_10 -> V_81 ( V_23 , & V_35 , NULL ) ;
if ( V_272 )
F_132 ( V_23 -> V_33 ) ;
}
if ( V_2 -> V_8 & V_277 ) {
const struct V_274 * V_10 = V_23 -> V_10 ;
int V_85 ;
F_89 ( V_4 , 0 ) ;
F_18 ( & V_23 -> V_9 ) ;
V_10 -> V_21 ( V_23 , 0 ) ;
F_19 ( & V_23 -> V_9 ) ;
if ( V_272 || ! F_15 ( V_23 ) ) {
struct V_6 * V_5 = V_2 -> V_5 ;
V_85 = V_10 -> V_32 ( V_23 ) ;
if ( V_85 == 0 ) {
if ( V_5 )
F_16 ( V_5 , V_4 , NULL ) ;
F_18 ( & V_23 -> V_9 ) ;
V_10 -> V_21 ( V_23 , V_23 -> V_20 ) ;
V_10 -> V_16 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
F_12 ( V_43 , & V_2 -> V_8 ) ;
} else {
F_22 ( V_5 , V_4 ) ;
}
}
F_20 ( V_49 , & V_2 -> V_8 ) ;
}
F_53 ( & V_2 -> V_99 ) ;
return 0 ;
}
static inline void
F_133 ( struct V_219 * V_220 , struct V_1 * V_2 )
{
char V_278 [ 64 ] ;
switch ( V_2 -> V_110 ) {
case V_279 :
snprintf ( V_278 , sizeof( V_278 ) , L_31 , V_2 -> V_100 ) ;
break;
case V_280 :
snprintf ( V_278 , sizeof( V_278 ) ,
L_32 , V_2 -> V_100 , V_2 -> V_108 ) ;
break;
case V_238 :
case V_281 :
case V_282 :
case V_283 :
snprintf ( V_278 , sizeof( V_278 ) ,
L_33 , ( unsigned long long ) V_2 -> V_114 ) ;
break;
default:
F_134 ( V_278 , L_34 , sizeof( V_278 ) ) ;
break;
}
F_59 ( V_284 L_35 ,
V_2 -> V_263 ? F_128 ( V_2 -> V_263 ) : L_27 ,
V_2 -> V_263 ? L_30 : L_27 ,
V_220 -> F_128 ,
V_220 -> V_240 -> V_276 + V_2 -> line ,
V_278 , V_2 -> V_48 , F_102 ( V_2 ) ) ;
}
static void
F_135 ( struct V_219 * V_220 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
unsigned int V_8 ;
if ( ! V_2 -> V_100 && ! V_2 -> V_114 && ! V_2 -> V_251 )
return;
V_8 = 0 ;
if ( V_2 -> V_8 & V_155 )
V_8 |= V_156 ;
if ( V_2 -> V_8 & V_285 ) {
if ( ! ( V_2 -> V_8 & V_286 ) ) {
V_2 -> type = V_29 ;
V_8 |= V_154 ;
}
V_2 -> V_10 -> V_157 ( V_2 , V_8 ) ;
}
if ( V_2 -> type != V_29 ) {
unsigned long V_8 ;
F_133 ( V_220 , V_2 ) ;
F_89 ( V_4 , 0 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_10 -> V_21 ( V_2 , V_2 -> V_20 & V_39 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_33 && ! ( V_2 -> V_33 -> V_8 & V_287 ) )
F_136 ( V_2 -> V_33 ) ;
if ( ! F_15 ( V_2 ) )
F_89 ( V_4 , 3 ) ;
}
}
static int F_137 ( struct V_240 * V_225 , int line , char * V_252 )
{
struct V_219 * V_220 = V_225 -> V_226 ;
struct V_3 * V_4 = V_220 -> V_4 + line ;
struct V_1 * V_2 ;
int V_50 = 9600 ;
int V_51 = 8 ;
int V_179 = 'n' ;
int V_253 = 'n' ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
if ( ! ( V_2 -> V_10 -> V_288 && V_2 -> V_10 -> V_289 ) )
return - 1 ;
if ( V_252 ) {
F_115 ( V_252 , & V_50 , & V_179 , & V_51 , & V_253 ) ;
return F_117 ( V_2 , NULL , V_50 , V_179 , V_51 , V_253 ) ;
}
return 0 ;
}
static int F_138 ( struct V_240 * V_225 , int line )
{
struct V_219 * V_220 = V_225 -> V_226 ;
struct V_3 * V_4 = V_220 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
return V_2 -> V_10 -> V_288 ( V_2 ) ;
}
static void F_139 ( struct V_240 * V_225 , int line , char V_88 )
{
struct V_219 * V_220 = V_225 -> V_226 ;
struct V_3 * V_4 = V_220 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return;
V_2 = V_4 -> V_1 ;
V_2 -> V_10 -> V_289 ( V_2 , V_88 ) ;
}
int F_140 ( struct V_219 * V_220 )
{
struct V_240 * V_290 ;
int V_233 , V_26 ;
F_2 ( V_220 -> V_4 ) ;
V_220 -> V_4 = F_141 ( sizeof( struct V_3 ) * V_220 -> V_243 , V_30 ) ;
if ( ! V_220 -> V_4 )
goto V_190;
V_290 = F_142 ( V_220 -> V_243 ) ;
if ( ! V_290 )
goto V_291;
V_220 -> V_240 = V_290 ;
V_290 -> V_292 = V_220 -> V_292 ;
V_290 -> V_293 = V_220 -> V_293 ;
V_290 -> V_205 = V_220 -> F_128 ;
V_290 -> V_268 = V_220 -> V_268 ;
V_290 -> V_269 = V_220 -> V_294 ;
V_290 -> type = V_295 ;
V_290 -> V_296 = V_297 ;
V_290 -> V_298 = V_299 ;
V_290 -> V_298 . V_36 = V_300 | V_259 | V_256 | V_45 | V_79 ;
V_290 -> V_298 . V_198 = V_290 -> V_298 . V_197 = 9600 ;
V_290 -> V_8 = V_301 | V_302 ;
V_290 -> V_226 = V_220 ;
F_143 ( V_290 , & V_274 ) ;
for ( V_233 = 0 ; V_233 < V_220 -> V_243 ; V_233 ++ ) {
struct V_3 * V_4 = V_220 -> V_4 + V_233 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_144 ( V_2 ) ;
V_2 -> V_10 = & V_303 ;
V_2 -> V_105 = 500 ;
V_2 -> V_106 = 30000 ;
}
V_26 = F_145 ( V_290 ) ;
if ( V_26 >= 0 )
return V_26 ;
F_146 ( V_290 ) ;
V_291:
F_147 ( V_220 -> V_4 ) ;
V_190:
return - V_31 ;
}
void F_148 ( struct V_219 * V_220 )
{
struct V_240 * V_304 = V_220 -> V_240 ;
F_149 ( V_304 ) ;
F_146 ( V_304 ) ;
F_147 ( V_220 -> V_4 ) ;
V_220 -> V_240 = NULL ;
}
struct V_240 * F_150 ( struct V_248 * V_249 , int * V_92 )
{
struct V_219 * V_304 = V_249 -> V_245 ;
* V_92 = V_249 -> V_92 ;
return V_304 -> V_240 ;
}
int F_151 ( struct V_219 * V_220 , struct V_1 * V_23 )
{
struct V_3 * V_4 ;
struct V_24 * V_2 ;
int V_85 = 0 ;
struct V_262 * V_270 ;
F_2 ( F_152 () ) ;
if ( V_23 -> line >= V_220 -> V_243 )
return - V_130 ;
V_4 = V_220 -> V_4 + V_23 -> line ;
V_2 = & V_4 -> V_2 ;
F_52 ( & V_305 ) ;
F_52 ( & V_2 -> V_99 ) ;
if ( V_4 -> V_1 ) {
V_85 = - V_130 ;
goto V_190;
}
V_4 -> V_1 = V_23 ;
V_4 -> V_234 = - 1 ;
V_23 -> V_33 = V_220 -> V_33 ;
V_23 -> V_4 = V_4 ;
if ( ! ( F_15 ( V_23 ) && ( V_23 -> V_33 -> V_8 & V_287 ) ) ) {
F_118 ( & V_23 -> V_9 ) ;
F_119 ( & V_23 -> V_9 , & V_255 ) ;
}
F_135 ( V_220 , V_4 , V_23 ) ;
V_270 = F_153 ( V_220 -> V_240 , V_23 -> line , V_23 -> V_263 ) ;
if ( F_154 ( ! F_99 ( V_270 ) ) ) {
F_155 ( V_270 , 1 ) ;
F_156 ( V_270 , 0 ) ;
} else
F_59 ( V_204 L_36 ,
V_23 -> line ) ;
V_23 -> V_8 &= ~ V_222 ;
V_190:
F_53 ( & V_2 -> V_99 ) ;
F_53 ( & V_305 ) ;
return V_85 ;
}
int F_157 ( struct V_219 * V_220 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_220 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_2 ( F_152 () ) ;
if ( V_4 -> V_1 != V_23 )
F_59 ( V_306 L_37 ,
V_4 -> V_1 , V_23 ) ;
F_52 ( & V_305 ) ;
F_52 ( & V_2 -> V_99 ) ;
V_23 -> V_8 |= V_222 ;
F_53 ( & V_2 -> V_99 ) ;
F_158 ( V_220 -> V_240 , V_23 -> line ) ;
if ( V_2 -> V_5 )
F_159 ( V_2 -> V_5 ) ;
if ( V_23 -> type != V_29 )
V_23 -> V_10 -> V_138 ( V_23 ) ;
V_23 -> type = V_29 ;
V_4 -> V_1 = NULL ;
F_53 ( & V_305 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_307 , struct V_1 * V_308 )
{
if ( V_307 -> V_110 != V_308 -> V_110 )
return 0 ;
switch ( V_307 -> V_110 ) {
case V_279 :
return ( V_307 -> V_100 == V_308 -> V_100 ) ;
case V_280 :
return ( V_307 -> V_100 == V_308 -> V_100 ) &&
( V_307 -> V_108 == V_308 -> V_108 ) ;
case V_238 :
case V_281 :
case V_282 :
case V_283 :
return ( V_307 -> V_114 == V_308 -> V_114 ) ;
}
return 0 ;
}
