void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( ! V_4 ) ;
F_3 ( & V_4 -> V_5 ) ;
}
static void F_4 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_2 -> V_11 -> V_12 ( V_2 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( ! F_8 ( & V_4 -> V_13 ) && V_4 -> V_13 . V_14 &&
! V_7 -> V_15 && ! V_7 -> V_16 )
V_2 -> V_11 -> V_17 ( V_2 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_9 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
F_7 ( V_7 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_10 ( unsigned long V_18 )
{
struct V_3 * V_4 = (struct V_3 * ) V_18 ;
F_11 ( V_4 -> V_2 . V_7 ) ;
}
static inline void
F_12 ( struct V_1 * V_2 , unsigned int V_19 , unsigned int V_20 )
{
unsigned long V_9 ;
unsigned int V_21 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_21 = V_2 -> V_22 ;
V_2 -> V_22 = ( V_21 & ~ V_20 ) | V_19 ;
if ( V_21 != V_2 -> V_22 )
V_2 -> V_11 -> V_23 ( V_2 , V_2 -> V_22 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
}
static int F_13 ( struct V_6 * V_7 , struct V_3 * V_4 , int V_24 )
{
struct V_1 * V_25 = V_4 -> V_1 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
unsigned long V_27 ;
int V_28 = 0 ;
if ( V_2 -> V_9 & V_29 )
return 0 ;
F_14 ( V_30 , & V_7 -> V_9 ) ;
if ( V_25 -> type == V_31 )
return 0 ;
if ( ! V_4 -> V_13 . V_14 ) {
V_27 = F_15 ( V_32 ) ;
if ( ! V_27 )
return - V_33 ;
V_4 -> V_13 . V_14 = ( unsigned char * ) V_27 ;
F_16 ( & V_4 -> V_13 ) ;
}
V_28 = V_25 -> V_11 -> V_34 ( V_25 ) ;
if ( V_28 == 0 ) {
if ( F_17 ( V_25 ) && V_25 -> V_35 -> V_36 ) {
V_7 -> V_37 -> V_38 = V_25 -> V_35 -> V_36 ;
V_25 -> V_35 -> V_36 = 0 ;
}
F_18 ( V_7 , V_4 , NULL ) ;
if ( V_24 ) {
if ( V_7 -> V_37 -> V_38 & V_39 )
F_19 ( V_25 , V_40 | V_41 ) ;
}
if ( V_2 -> V_9 & V_42 ) {
F_20 ( & V_25 -> V_10 ) ;
if ( ! ( V_25 -> V_11 -> V_43 ( V_25 ) & V_44 ) )
V_7 -> V_16 = 1 ;
F_21 ( & V_25 -> V_10 ) ;
}
F_14 ( V_45 , & V_2 -> V_9 ) ;
F_22 ( V_30 , & V_7 -> V_9 ) ;
}
if ( V_28 && F_23 ( V_46 ) )
V_28 = 0 ;
return V_28 ;
}
static void F_24 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_25 = V_4 -> V_1 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
if ( V_7 )
F_14 ( V_30 , & V_7 -> V_9 ) ;
if ( F_25 ( V_45 , & V_2 -> V_9 ) ) {
if ( ! V_7 || ( V_7 -> V_37 -> V_38 & V_47 ) )
F_26 ( V_25 , V_41 | V_40 ) ;
F_27 ( & V_2 -> V_48 ) ;
V_25 -> V_11 -> V_49 ( V_25 ) ;
F_28 ( V_25 -> V_50 ) ;
}
F_29 ( & V_4 -> V_5 ) ;
if ( V_4 -> V_13 . V_14 ) {
F_30 ( ( unsigned long ) V_4 -> V_13 . V_14 ) ;
V_4 -> V_13 . V_14 = NULL ;
}
}
void
F_31 ( struct V_1 * V_2 , unsigned int V_36 ,
unsigned int V_51 )
{
unsigned int V_52 ;
switch ( V_36 & V_53 ) {
case V_54 :
V_52 = 7 ;
break;
case V_55 :
V_52 = 8 ;
break;
case V_56 :
V_52 = 9 ;
break;
default:
V_52 = 10 ;
break;
}
if ( V_36 & V_57 )
V_52 ++ ;
if ( V_36 & V_58 )
V_52 ++ ;
V_52 = V_52 * V_2 -> V_59 ;
V_2 -> V_60 = ( V_61 * V_52 ) / V_51 + V_61 / 50 ;
}
unsigned int
F_32 ( struct V_1 * V_2 , struct V_62 * V_37 ,
struct V_62 * V_21 , unsigned int V_63 , unsigned int V_64 )
{
unsigned int V_65 , V_51 , V_66 = 38400 ;
int V_67 = 0 ;
T_1 V_9 = V_2 -> V_9 & V_68 ;
if ( V_9 == V_69 )
V_66 = 57600 ;
else if ( V_9 == V_70 )
V_66 = 115200 ;
else if ( V_9 == V_71 )
V_66 = 230400 ;
else if ( V_9 == V_72 )
V_66 = 460800 ;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
V_51 = F_33 ( V_37 ) ;
if ( V_51 == 38400 )
V_51 = V_66 ;
if ( V_51 == 0 ) {
V_67 = 1 ;
V_51 = 9600 ;
}
if ( V_51 >= V_63 && V_51 <= V_64 )
return V_51 ;
V_37 -> V_38 &= ~ V_39 ;
if ( V_21 ) {
V_51 = F_33 ( V_21 ) ;
if ( ! V_67 )
F_34 ( V_37 ,
V_51 , V_51 ) ;
V_21 = NULL ;
continue;
}
if ( ! V_67 ) {
if ( V_51 <= V_63 )
F_34 ( V_37 ,
V_63 + 1 , V_63 + 1 ) ;
else
F_34 ( V_37 ,
V_64 - 1 , V_64 - 1 ) ;
}
}
F_35 ( 1 ) ;
return 0 ;
}
unsigned int
F_36 ( struct V_1 * V_2 , unsigned int V_51 )
{
unsigned int V_73 ;
if ( V_51 == 38400 && ( V_2 -> V_9 & V_68 ) == V_74 )
V_73 = V_2 -> V_75 ;
else
V_73 = ( V_2 -> V_76 + ( 8 * V_51 ) ) / ( 16 * V_51 ) ;
return V_73 ;
}
static void F_18 ( struct V_6 * V_7 , struct V_3 * V_4 ,
struct V_62 * V_77 )
{
struct V_26 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_25 = V_4 -> V_1 ;
struct V_62 * V_37 ;
if ( ! V_7 || ! V_7 -> V_37 || V_25 -> type == V_31 )
return;
V_37 = V_7 -> V_37 ;
if ( V_37 -> V_38 & V_78 )
F_14 ( V_79 , & V_2 -> V_9 ) ;
else
F_22 ( V_79 , & V_2 -> V_9 ) ;
if ( V_37 -> V_38 & V_80 )
F_22 ( V_81 , & V_2 -> V_9 ) ;
else
F_14 ( V_81 , & V_2 -> V_9 ) ;
V_25 -> V_11 -> V_82 ( V_25 , V_37 , V_77 ) ;
}
static inline int F_37 ( struct V_1 * V_2 ,
struct V_83 * V_84 , unsigned char V_85 )
{
unsigned long V_9 ;
int V_86 = 0 ;
if ( ! V_84 -> V_14 )
return 0 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
if ( F_38 ( V_84 ) != 0 ) {
V_84 -> V_14 [ V_84 -> V_87 ] = V_85 ;
V_84 -> V_87 = ( V_84 -> V_87 + 1 ) & ( V_88 - 1 ) ;
V_86 = 1 ;
}
F_6 ( & V_2 -> V_10 , V_9 ) ;
return V_86 ;
}
static int F_39 ( struct V_6 * V_7 , unsigned char V_89 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
return F_37 ( V_4 -> V_1 , & V_4 -> V_13 , V_89 ) ;
}
static void F_40 ( struct V_6 * V_7 )
{
F_9 ( V_7 ) ;
}
static int F_41 ( struct V_6 * V_7 ,
const unsigned char * V_14 , int V_90 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
unsigned long V_9 ;
int V_85 , V_86 = 0 ;
if ( ! V_4 ) {
F_35 ( 1 ) ;
return - V_91 ;
}
V_2 = V_4 -> V_1 ;
V_84 = & V_4 -> V_13 ;
if ( ! V_84 -> V_14 )
return 0 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
while ( 1 ) {
V_85 = F_42 ( V_84 -> V_87 , V_84 -> V_92 , V_88 ) ;
if ( V_90 < V_85 )
V_85 = V_90 ;
if ( V_85 <= 0 )
break;
memcpy ( V_84 -> V_14 + V_84 -> V_87 , V_14 , V_85 ) ;
V_84 -> V_87 = ( V_84 -> V_87 + V_85 ) & ( V_88 - 1 ) ;
V_14 += V_85 ;
V_90 -= V_85 ;
V_86 += V_85 ;
}
F_6 ( & V_2 -> V_10 , V_9 ) ;
F_9 ( V_7 ) ;
return V_86 ;
}
static int F_43 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
unsigned long V_9 ;
int V_86 ;
F_5 ( & V_4 -> V_1 -> V_10 , V_9 ) ;
V_86 = F_38 ( & V_4 -> V_13 ) ;
F_6 ( & V_4 -> V_1 -> V_10 , V_9 ) ;
return V_86 ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
unsigned long V_9 ;
int V_86 ;
F_5 ( & V_4 -> V_1 -> V_10 , V_9 ) ;
V_86 = F_45 ( & V_4 -> V_13 ) ;
F_6 ( & V_4 -> V_1 -> V_10 , V_9 ) ;
return V_86 ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_2 ;
unsigned long V_9 ;
if ( ! V_4 ) {
F_35 ( 1 ) ;
return;
}
V_2 = V_4 -> V_1 ;
F_47 ( L_1 , V_7 -> V_93 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
F_16 ( & V_4 -> V_13 ) ;
if ( V_2 -> V_11 -> V_94 )
V_2 -> V_11 -> V_94 ( V_2 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
F_11 ( V_7 ) ;
}
static void F_48 ( struct V_6 * V_7 , char V_89 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_9 ;
if ( V_2 -> V_11 -> V_95 )
V_2 -> V_11 -> V_95 ( V_2 , V_89 ) ;
else {
V_2 -> V_96 = V_89 ;
if ( V_89 ) {
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_2 -> V_11 -> V_17 ( V_2 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
}
}
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
if ( F_50 ( V_7 ) )
F_48 ( V_7 , F_51 ( V_7 ) ) ;
if ( V_7 -> V_37 -> V_38 & V_78 )
F_26 ( V_4 -> V_1 , V_40 ) ;
}
static void F_52 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( F_50 ( V_7 ) ) {
if ( V_2 -> V_96 )
V_2 -> V_96 = 0 ;
else
F_48 ( V_7 , F_53 ( V_7 ) ) ;
}
if ( V_7 -> V_37 -> V_38 & V_78 )
F_19 ( V_2 , V_40 ) ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_97 T_2 * V_98 )
{
struct V_1 * V_25 = V_4 -> V_1 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
struct V_97 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
F_55 ( & V_2 -> V_100 ) ;
V_99 . type = V_25 -> type ;
V_99 . line = V_25 -> line ;
V_99 . V_2 = V_25 -> V_101 ;
if ( V_102 )
V_99 . V_103 = ( long ) V_25 -> V_101 >> V_102 ;
V_99 . V_50 = V_25 -> V_50 ;
V_99 . V_9 = V_25 -> V_9 ;
V_99 . V_104 = V_25 -> V_59 ;
V_99 . V_105 = V_25 -> V_76 / 16 ;
V_99 . V_106 = V_2 -> V_106 / 10 ;
V_99 . V_107 = V_2 -> V_107 == V_108 ?
V_108 :
V_2 -> V_107 / 10 ;
V_99 . V_75 = V_25 -> V_75 ;
V_99 . V_109 = V_25 -> V_109 ;
V_99 . V_110 = V_25 -> V_111 ;
V_99 . V_112 = V_25 -> V_113 ;
V_99 . V_114 = ( void * ) ( unsigned long ) V_25 -> V_115 ;
F_56 ( & V_2 -> V_100 ) ;
if ( F_57 ( V_98 , & V_99 , sizeof( * V_98 ) ) )
return - V_116 ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 , struct V_3 * V_4 ,
struct V_97 T_2 * V_117 )
{
struct V_97 V_118 ;
struct V_1 * V_25 = V_4 -> V_1 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
unsigned long V_119 ;
unsigned int V_120 , V_121 , V_107 ;
unsigned int V_122 , V_106 ;
T_1 V_123 , V_124 ;
int V_28 = 0 ;
if ( F_59 ( & V_118 , V_117 , sizeof( V_118 ) ) )
return - V_116 ;
V_119 = V_118 . V_2 ;
if ( V_102 )
V_119 += ( unsigned long ) V_118 . V_103 << V_102 ;
V_118 . V_50 = F_60 ( V_118 . V_50 ) ;
V_106 = V_118 . V_106 * 10 ;
V_107 = V_118 . V_107 == V_108 ?
V_108 : V_118 . V_107 * 10 ;
F_55 ( & V_2 -> V_100 ) ;
V_120 = ! ( V_25 -> V_9 & V_125 )
&& V_118 . V_50 != V_25 -> V_50 ;
V_121 = ! ( V_25 -> V_9 & V_125 )
&& ( V_119 != V_25 -> V_101 ||
( unsigned long ) V_118 . V_114 != V_25 -> V_115 ||
V_118 . V_109 != V_25 -> V_109 ||
V_118 . V_110 != V_25 -> V_111 ||
V_118 . V_112 != V_25 -> V_113 ||
V_118 . type != V_25 -> type ) ;
V_123 = V_25 -> V_9 ;
V_124 = V_118 . V_9 ;
V_122 = V_25 -> V_75 ;
if ( ! F_23 ( V_46 ) ) {
V_28 = - V_126 ;
if ( V_120 || V_121 ||
( V_118 . V_105 != V_25 -> V_76 / 16 ) ||
( V_106 != V_2 -> V_106 ) ||
( V_107 != V_2 -> V_107 ) ||
( V_118 . V_104 &&
V_118 . V_104 != V_25 -> V_59 ) ||
( ( ( V_124 ^ V_123 ) & ~ V_127 ) != 0 ) )
goto exit;
V_25 -> V_9 = ( ( V_25 -> V_9 & ~ V_127 ) |
( V_124 & V_127 ) ) ;
V_25 -> V_75 = V_118 . V_75 ;
goto V_128;
}
if ( V_25 -> V_11 -> V_129 )
V_28 = V_25 -> V_11 -> V_129 ( V_25 , & V_118 ) ;
if ( ( V_118 . V_50 >= V_130 ) || ( V_118 . V_50 < 0 ) ||
( V_118 . V_105 < 9600 ) )
V_28 = - V_131 ;
if ( V_28 )
goto exit;
if ( V_121 || V_120 ) {
V_28 = - V_132 ;
if ( F_61 ( V_2 ) > 1 )
goto exit;
F_24 ( V_7 , V_4 ) ;
}
if ( V_121 ) {
unsigned long V_133 , V_134 ;
unsigned int V_135 , V_136 , V_137 , V_138 ;
V_133 = V_25 -> V_101 ;
V_134 = V_25 -> V_115 ;
V_135 = V_25 -> type ;
V_137 = V_25 -> V_109 ;
V_136 = V_25 -> V_111 ;
V_138 = V_25 -> V_113 ;
if ( V_135 != V_31 )
V_25 -> V_11 -> V_139 ( V_25 ) ;
V_25 -> V_101 = V_119 ;
V_25 -> type = V_118 . type ;
V_25 -> V_109 = V_118 . V_109 ;
V_25 -> V_111 = V_118 . V_110 ;
V_25 -> V_113 = V_118 . V_112 ;
V_25 -> V_115 = ( unsigned long ) V_118 . V_114 ;
if ( V_25 -> type != V_31 ) {
V_28 = V_25 -> V_11 -> V_140 ( V_25 ) ;
} else {
V_28 = 0 ;
}
if ( V_28 && V_135 != V_31 ) {
V_25 -> V_101 = V_133 ;
V_25 -> type = V_135 ;
V_25 -> V_109 = V_137 ;
V_25 -> V_111 = V_136 ;
V_25 -> V_113 = V_138 ;
V_25 -> V_115 = V_134 ;
V_28 = V_25 -> V_11 -> V_140 ( V_25 ) ;
if ( V_28 )
V_25 -> type = V_31 ;
V_28 = - V_132 ;
goto exit;
}
}
if ( V_120 )
V_25 -> V_50 = V_118 . V_50 ;
if ( ! ( V_25 -> V_9 & V_125 ) )
V_25 -> V_76 = V_118 . V_105 * 16 ;
V_25 -> V_9 = ( V_25 -> V_9 & ~ V_141 ) |
( V_124 & V_141 ) ;
V_25 -> V_75 = V_118 . V_75 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_107 = V_107 ;
if ( V_118 . V_104 )
V_25 -> V_59 = V_118 . V_104 ;
if ( V_2 -> V_7 )
V_2 -> V_7 -> V_142 =
( V_25 -> V_9 & V_143 ) ? 1 : 0 ;
V_128:
V_28 = 0 ;
if ( V_25 -> type == V_31 )
goto exit;
if ( V_2 -> V_9 & V_29 ) {
if ( ( ( V_123 ^ V_25 -> V_9 ) & V_68 ) ||
V_122 != V_25 -> V_75 ) {
if ( V_25 -> V_9 & V_68 ) {
char V_14 [ 64 ] ;
F_62 ( V_144
L_2
L_3 , V_145 -> V_146 ,
F_63 ( V_2 -> V_7 , V_14 ) ) ;
}
F_18 ( V_7 , V_4 , NULL ) ;
}
} else
V_28 = F_13 ( V_7 , V_4 , 1 ) ;
exit:
F_56 ( & V_2 -> V_100 ) ;
return V_28 ;
}
static int F_64 ( struct V_6 * V_7 ,
struct V_3 * V_4 , unsigned int T_2 * V_147 )
{
struct V_1 * V_25 = V_4 -> V_1 ;
unsigned int V_148 ;
V_148 = V_25 -> V_11 -> V_149 ( V_25 ) ;
if ( V_25 -> V_96 ||
( ( F_45 ( & V_4 -> V_13 ) > 0 ) &&
! V_7 -> V_15 && ! V_7 -> V_16 ) )
V_148 &= ~ V_150 ;
return F_65 ( V_148 , V_147 ) ;
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_25 = V_4 -> V_1 ;
int V_148 = - V_151 ;
F_55 ( & V_2 -> V_100 ) ;
if ( ! ( V_7 -> V_9 & ( 1 << V_30 ) ) ) {
V_148 = V_25 -> V_22 ;
F_20 ( & V_25 -> V_10 ) ;
V_148 |= V_25 -> V_11 -> V_43 ( V_25 ) ;
F_21 ( & V_25 -> V_10 ) ;
}
F_56 ( & V_2 -> V_100 ) ;
return V_148 ;
}
static int
F_67 ( struct V_6 * V_7 , unsigned int V_19 , unsigned int V_20 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_25 = V_4 -> V_1 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
int V_86 = - V_151 ;
F_55 ( & V_2 -> V_100 ) ;
if ( ! ( V_7 -> V_9 & ( 1 << V_30 ) ) ) {
F_12 ( V_25 , V_19 , V_20 ) ;
V_86 = 0 ;
}
F_56 ( & V_2 -> V_100 ) ;
return V_86 ;
}
static int F_68 ( struct V_6 * V_7 , int V_152 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_25 = V_4 -> V_1 ;
F_55 ( & V_2 -> V_100 ) ;
if ( V_25 -> type != V_31 )
V_25 -> V_11 -> V_153 ( V_25 , V_152 ) ;
F_56 ( & V_2 -> V_100 ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_25 = V_4 -> V_1 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
int V_9 , V_86 ;
if ( ! F_23 ( V_46 ) )
return - V_126 ;
if ( F_70 ( & V_2 -> V_100 ) )
return - V_154 ;
V_86 = - V_132 ;
if ( F_61 ( V_2 ) == 1 ) {
F_24 ( V_7 , V_4 ) ;
if ( V_25 -> type != V_31 )
V_25 -> V_11 -> V_139 ( V_25 ) ;
V_9 = V_155 ;
if ( V_25 -> V_9 & V_156 )
V_9 |= V_157 ;
V_25 -> V_11 -> V_158 ( V_25 , V_9 ) ;
V_86 = F_13 ( V_7 , V_4 , 1 ) ;
}
F_56 ( & V_2 -> V_100 ) ;
return V_86 ;
}
static int
F_71 ( struct V_3 * V_4 , unsigned long V_159 )
{
struct V_1 * V_25 = V_4 -> V_1 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
F_72 ( V_160 , V_145 ) ;
struct V_161 V_162 , V_163 ;
int V_86 ;
F_20 ( & V_25 -> V_10 ) ;
memcpy ( & V_162 , & V_25 -> V_164 , sizeof( struct V_161 ) ) ;
V_25 -> V_11 -> V_165 ( V_25 ) ;
F_21 ( & V_25 -> V_10 ) ;
F_73 ( & V_2 -> V_48 , & V_160 ) ;
for (; ; ) {
F_20 ( & V_25 -> V_10 ) ;
memcpy ( & V_163 , & V_25 -> V_164 , sizeof( struct V_161 ) ) ;
F_21 ( & V_25 -> V_10 ) ;
F_74 ( V_166 ) ;
if ( ( ( V_159 & V_167 ) && ( V_163 . V_168 != V_162 . V_168 ) ) ||
( ( V_159 & V_169 ) && ( V_163 . V_170 != V_162 . V_170 ) ) ||
( ( V_159 & V_171 ) && ( V_163 . V_172 != V_162 . V_172 ) ) ||
( ( V_159 & V_44 ) && ( V_163 . V_173 != V_162 . V_173 ) ) ) {
V_86 = 0 ;
break;
}
F_75 () ;
if ( F_76 ( V_145 ) ) {
V_86 = - V_154 ;
break;
}
V_162 = V_163 ;
}
V_145 -> V_4 = V_174 ;
F_77 ( & V_2 -> V_48 , & V_160 ) ;
return V_86 ;
}
static int F_78 ( struct V_6 * V_7 ,
struct V_175 * V_164 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_161 V_163 ;
struct V_1 * V_25 = V_4 -> V_1 ;
F_20 ( & V_25 -> V_10 ) ;
memcpy ( & V_163 , & V_25 -> V_164 , sizeof( struct V_161 ) ) ;
F_21 ( & V_25 -> V_10 ) ;
V_164 -> V_173 = V_163 . V_173 ;
V_164 -> V_170 = V_163 . V_170 ;
V_164 -> V_168 = V_163 . V_168 ;
V_164 -> V_172 = V_163 . V_172 ;
V_164 -> V_176 = V_163 . V_176 ;
V_164 -> V_177 = V_163 . V_177 ;
V_164 -> V_178 = V_163 . V_178 ;
V_164 -> V_179 = V_163 . V_179 ;
V_164 -> V_180 = V_163 . V_180 ;
V_164 -> V_181 = V_163 . V_181 ;
V_164 -> V_182 = V_163 . V_182 ;
return 0 ;
}
static int
F_79 ( struct V_6 * V_7 , unsigned int V_183 ,
unsigned long V_159 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
void T_2 * V_184 = ( void T_2 * ) V_159 ;
int V_86 = - V_185 ;
switch ( V_183 ) {
case V_186 :
V_86 = F_54 ( V_4 , V_184 ) ;
break;
case V_187 :
V_86 = F_58 ( V_7 , V_4 , V_184 ) ;
break;
case V_188 :
V_86 = F_69 ( V_7 , V_4 ) ;
break;
case V_189 :
case V_190 :
V_86 = 0 ;
break;
}
if ( V_86 != - V_185 )
goto V_191;
if ( V_7 -> V_9 & ( 1 << V_30 ) ) {
V_86 = - V_151 ;
goto V_191;
}
switch ( V_183 ) {
case V_192 :
V_86 = F_71 ( V_4 , V_159 ) ;
break;
}
if ( V_86 != - V_185 )
goto V_191;
F_55 ( & V_2 -> V_100 ) ;
if ( V_7 -> V_9 & ( 1 << V_30 ) ) {
V_86 = - V_151 ;
goto V_193;
}
switch ( V_183 ) {
case V_194 :
V_86 = F_64 ( V_7 , V_4 , V_184 ) ;
break;
default: {
struct V_1 * V_25 = V_4 -> V_1 ;
if ( V_25 -> V_11 -> V_195 )
V_86 = V_25 -> V_11 -> V_195 ( V_25 , V_183 , V_159 ) ;
break;
}
}
V_193:
F_56 ( & V_2 -> V_100 ) ;
V_191:
return V_86 ;
}
static void F_80 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_25 = V_4 -> V_1 ;
if ( V_25 -> V_11 -> V_196 )
V_25 -> V_11 -> V_196 ( V_25 , V_7 -> V_37 -> V_197 ) ;
}
static void F_81 ( struct V_6 * V_7 ,
struct V_62 * V_77 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
unsigned long V_9 ;
unsigned int V_36 = V_7 -> V_37 -> V_38 ;
#define F_82 ( T_3 ) ((iflag) & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK))
if ( ( V_36 ^ V_77 -> V_38 ) == 0 &&
V_7 -> V_37 -> V_198 == V_77 -> V_198 &&
V_7 -> V_37 -> V_199 == V_77 -> V_199 &&
F_82 ( V_7 -> V_37 -> V_200 ^ V_77 -> V_200 ) == 0 ) {
return;
}
F_18 ( V_7 , V_4 , V_77 ) ;
if ( ( V_77 -> V_38 & V_39 ) && ! ( V_36 & V_39 ) )
F_26 ( V_4 -> V_1 , V_40 | V_41 ) ;
else if ( ! ( V_77 -> V_38 & V_39 ) && ( V_36 & V_39 ) ) {
unsigned int V_201 = V_41 ;
if ( ! ( V_36 & V_78 ) ||
! F_83 ( V_202 , & V_7 -> V_9 ) )
V_201 |= V_40 ;
F_19 ( V_4 -> V_1 , V_201 ) ;
}
if ( ( V_77 -> V_38 & V_78 ) && ! ( V_36 & V_78 ) ) {
F_5 ( & V_4 -> V_1 -> V_10 , V_9 ) ;
V_7 -> V_16 = 0 ;
F_7 ( V_7 ) ;
F_6 ( & V_4 -> V_1 -> V_10 , V_9 ) ;
}
else if ( ! ( V_77 -> V_38 & V_78 ) && ( V_36 & V_78 ) ) {
F_5 ( & V_4 -> V_1 -> V_10 , V_9 ) ;
if ( ! ( V_4 -> V_1 -> V_11 -> V_43 ( V_4 -> V_1 ) & V_44 ) ) {
V_7 -> V_16 = 1 ;
V_4 -> V_1 -> V_11 -> V_12 ( V_4 -> V_1 ) ;
}
F_6 ( & V_4 -> V_1 -> V_10 , V_9 ) ;
}
}
static void F_84 ( struct V_6 * V_7 , struct V_203 * V_204 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_26 * V_2 ;
struct V_1 * V_25 ;
unsigned long V_9 ;
F_2 ( ! F_85 () ) ;
if ( ! V_4 )
return;
V_25 = V_4 -> V_1 ;
V_2 = & V_4 -> V_2 ;
F_47 ( L_4 , V_25 -> line ) ;
F_55 ( & V_2 -> V_100 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
if ( F_86 ( V_204 ) ) {
F_6 ( & V_2 -> V_10 , V_9 ) ;
goto V_205;
}
if ( ( V_7 -> V_90 == 1 ) && ( V_2 -> V_90 != 1 ) ) {
F_62 ( V_206 L_5
L_6 , V_2 -> V_90 ) ;
V_2 -> V_90 = 1 ;
}
if ( -- V_2 -> V_90 < 0 ) {
F_62 ( V_206 L_7 ,
V_7 -> V_207 , V_2 -> V_90 ) ;
V_2 -> V_90 = 0 ;
}
if ( V_2 -> V_90 ) {
F_6 ( & V_2 -> V_10 , V_9 ) ;
goto V_205;
}
V_7 -> V_208 = 1 ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
if ( V_2 -> V_107 != V_108 ) {
long V_60 = F_87 ( V_2 -> V_107 ) ;
if ( F_88 ( V_7 -> V_209 ,
! F_89 ( V_7 ) , V_60 ) >= 0 )
F_90 ( V_25 , V_60 ) ;
}
if ( V_2 -> V_9 & V_29 ) {
unsigned long V_9 ;
F_5 ( & V_25 -> V_10 , V_9 ) ;
V_25 -> V_11 -> V_210 ( V_25 ) ;
F_6 ( & V_25 -> V_10 , V_9 ) ;
F_90 ( V_25 , V_25 -> V_60 ) ;
}
F_24 ( V_7 , V_4 ) ;
F_46 ( V_7 ) ;
F_91 ( V_7 ) ;
F_92 ( V_2 , NULL ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_7 -> V_208 = 0 ;
if ( V_2 -> V_211 ) {
F_6 ( & V_2 -> V_10 , V_9 ) ;
if ( V_2 -> V_106 )
F_93 ( V_2 -> V_106 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
} else if ( ! F_17 ( V_25 ) ) {
F_6 ( & V_2 -> V_10 , V_9 ) ;
F_94 ( V_4 , 3 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
}
F_22 ( V_212 , & V_2 -> V_9 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
F_27 ( & V_2 -> V_213 ) ;
V_205:
F_56 ( & V_2 -> V_100 ) ;
}
static void F_90 ( struct V_1 * V_2 , int V_60 )
{
unsigned long V_214 , V_215 ;
if ( V_2 -> type == V_31 || V_2 -> V_59 == 0 )
return;
V_214 = ( V_2 -> V_60 - V_61 / 50 ) / V_2 -> V_59 ;
V_214 = V_214 / 5 ;
if ( V_214 == 0 )
V_214 = 1 ;
if ( V_60 && V_60 < V_214 )
V_214 = V_60 ;
if ( V_60 == 0 || V_60 > 2 * V_2 -> V_60 )
V_60 = 2 * V_2 -> V_60 ;
V_215 = V_216 + V_60 ;
F_47 ( L_8 ,
V_2 -> line , V_216 , V_215 ) ;
while ( ! V_2 -> V_11 -> V_149 ( V_2 ) ) {
F_93 ( F_95 ( V_214 ) ) ;
if ( F_76 ( V_145 ) )
break;
if ( F_96 ( V_216 , V_215 ) )
break;
}
}
static void F_97 ( struct V_6 * V_7 , int V_60 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_1 * V_2 = V_4 -> V_1 ;
F_98 () ;
F_90 ( V_2 , V_60 ) ;
F_99 () ;
}
static void F_100 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_8 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
unsigned long V_9 ;
F_2 ( ! F_85 () ) ;
F_47 ( L_9 , V_4 -> V_1 -> line ) ;
F_55 ( & V_2 -> V_100 ) ;
if ( V_2 -> V_9 & V_217 ) {
F_46 ( V_7 ) ;
F_24 ( V_7 , V_4 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_2 -> V_90 = 0 ;
F_22 ( V_212 , & V_2 -> V_9 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
F_92 ( V_2 , NULL ) ;
F_27 ( & V_2 -> V_213 ) ;
F_27 ( & V_2 -> V_48 ) ;
}
F_56 ( & V_2 -> V_100 ) ;
}
static int F_101 ( struct V_26 * V_2 )
{
struct V_3 * V_4 = F_102 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_25 = V_4 -> V_1 ;
int V_22 ;
F_20 ( & V_25 -> V_10 ) ;
V_25 -> V_11 -> V_165 ( V_25 ) ;
V_22 = V_25 -> V_11 -> V_43 ( V_25 ) ;
F_21 ( & V_25 -> V_10 ) ;
if ( V_22 & V_218 )
return 1 ;
return 0 ;
}
static void F_103 ( struct V_26 * V_2 , int V_219 )
{
struct V_3 * V_4 = F_102 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_25 = V_4 -> V_1 ;
if ( V_219 )
F_19 ( V_25 , V_41 | V_40 ) ;
else
F_26 ( V_25 , V_41 | V_40 ) ;
}
static struct V_3 * F_104 ( struct V_220 * V_221 , int line )
{
struct V_3 * V_4 ;
struct V_26 * V_2 ;
int V_86 = 0 ;
V_4 = V_221 -> V_4 + line ;
V_2 = & V_4 -> V_2 ;
if ( F_70 ( & V_2 -> V_100 ) ) {
V_86 = - V_154 ;
goto V_222;
}
V_2 -> V_90 ++ ;
if ( ! V_4 -> V_1 || V_4 -> V_1 -> V_9 & V_223 ) {
V_86 = - V_224 ;
goto V_225;
}
return V_4 ;
V_225:
V_2 -> V_90 -- ;
F_56 ( & V_2 -> V_100 ) ;
V_222:
return F_105 ( V_86 ) ;
}
static int F_106 ( struct V_6 * V_7 , struct V_203 * V_204 )
{
struct V_220 * V_221 = (struct V_220 * ) V_7 -> V_226 -> V_227 ;
struct V_3 * V_4 ;
struct V_26 * V_2 ;
int V_28 , line = V_7 -> V_93 ;
F_2 ( ! F_85 () ) ;
F_47 ( L_10 , line ) ;
V_4 = F_104 ( V_221 , line ) ;
if ( F_107 ( V_4 ) ) {
V_28 = F_108 ( V_4 ) ;
goto V_228;
}
V_2 = & V_4 -> V_2 ;
V_7 -> V_8 = V_4 ;
V_4 -> V_1 -> V_4 = V_4 ;
V_7 -> V_142 = ( V_4 -> V_1 -> V_9 & V_143 ) ? 1 : 0 ;
V_7 -> V_229 = 0 ;
F_92 ( V_2 , V_7 ) ;
if ( F_86 ( V_204 ) ) {
V_28 = - V_230 ;
V_2 -> V_90 -- ;
F_56 ( & V_2 -> V_100 ) ;
goto V_228;
}
if ( V_2 -> V_90 == 1 )
F_94 ( V_4 , 0 ) ;
V_28 = F_13 ( V_7 , V_4 , 0 ) ;
F_56 ( & V_2 -> V_100 ) ;
if ( V_28 == 0 )
V_28 = F_109 ( V_2 , V_7 , V_204 ) ;
V_228:
return V_28 ;
}
static const char * F_110 ( struct V_1 * V_2 )
{
const char * V_231 = NULL ;
if ( V_2 -> V_11 -> type )
V_231 = V_2 -> V_11 -> type ( V_2 ) ;
if ( ! V_231 )
V_231 = L_11 ;
return V_231 ;
}
static void F_111 ( struct V_232 * V_233 , struct V_220 * V_221 , int V_234 )
{
struct V_3 * V_4 = V_221 -> V_4 + V_234 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
int V_235 ;
struct V_1 * V_25 = V_4 -> V_1 ;
char V_236 [ 32 ] ;
unsigned int V_237 ;
int V_238 ;
if ( ! V_25 )
return;
V_238 = V_25 -> V_111 >= V_239 ;
F_112 ( V_233 , L_12 ,
V_25 -> line , F_110 ( V_25 ) ,
V_238 ? L_13 : L_14 ,
V_238 ? ( unsigned long long ) V_25 -> V_115
: ( unsigned long long ) V_25 -> V_101 ,
V_25 -> V_50 ) ;
if ( V_25 -> type == V_31 ) {
F_113 ( V_233 , '\n' ) ;
return;
}
if ( F_23 ( V_46 ) ) {
F_55 ( & V_2 -> V_100 ) ;
V_235 = V_4 -> V_235 ;
if ( V_235 )
F_94 ( V_4 , 0 ) ;
F_20 ( & V_25 -> V_10 ) ;
V_237 = V_25 -> V_11 -> V_43 ( V_25 ) ;
F_21 ( & V_25 -> V_10 ) ;
if ( V_235 )
F_94 ( V_4 , V_235 ) ;
F_56 ( & V_2 -> V_100 ) ;
F_112 ( V_233 , L_15 ,
V_25 -> V_164 . V_177 , V_25 -> V_164 . V_176 ) ;
if ( V_25 -> V_164 . V_178 )
F_112 ( V_233 , L_16 ,
V_25 -> V_164 . V_178 ) ;
if ( V_25 -> V_164 . V_180 )
F_112 ( V_233 , L_17 ,
V_25 -> V_164 . V_180 ) ;
if ( V_25 -> V_164 . V_181 )
F_112 ( V_233 , L_18 ,
V_25 -> V_164 . V_181 ) ;
if ( V_25 -> V_164 . V_179 )
F_112 ( V_233 , L_19 ,
V_25 -> V_164 . V_179 ) ;
#define F_114 ( T_4 , V_231 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_115 ( T_4 , V_231 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_236 [ 0 ] = '\0' ;
V_236 [ 1 ] = '\0' ;
F_114 ( V_40 , L_20 ) ;
F_115 ( V_44 , L_21 ) ;
F_114 ( V_41 , L_22 ) ;
F_115 ( V_169 , L_23 ) ;
F_115 ( V_218 , L_24 ) ;
F_115 ( V_167 , L_25 ) ;
if ( V_236 [ 0 ] )
V_236 [ 0 ] = ' ' ;
F_116 ( V_233 , V_236 ) ;
}
F_113 ( V_233 , '\n' ) ;
#undef F_115
#undef F_114
}
static int F_117 ( struct V_232 * V_233 , void * V_240 )
{
struct V_241 * V_242 = V_233 -> V_243 ;
struct V_220 * V_221 = V_242 -> V_227 ;
int V_234 ;
F_112 ( V_233 , L_26 ,
L_27 , L_27 , L_27 ) ;
for ( V_234 = 0 ; V_234 < V_221 -> V_244 ; V_234 ++ )
F_111 ( V_233 , V_221 , V_234 ) ;
return 0 ;
}
static int F_118 ( struct V_245 * V_245 , struct V_203 * V_203 )
{
return F_119 ( V_203 , F_117 , F_120 ( V_245 ) -> V_18 ) ;
}
void F_121 ( struct V_1 * V_2 , const char * V_246 ,
unsigned int V_90 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_234 ;
for ( V_234 = 0 ; V_234 < V_90 ; V_234 ++ , V_246 ++ ) {
if ( * V_246 == '\n' )
putchar ( V_2 , '\r' ) ;
putchar ( V_2 , * V_246 ) ;
}
}
struct V_1 * T_5
F_122 ( struct V_1 * V_247 , int V_244 , struct V_248 * V_249 )
{
int V_250 = V_249 -> V_93 ;
if ( V_250 < 0 || V_250 >= V_244 || ( V_247 [ V_250 ] . V_101 == 0 &&
V_247 [ V_250 ] . V_251 == NULL ) )
for ( V_250 = 0 ; V_250 < V_244 ; V_250 ++ )
if ( V_247 [ V_250 ] . V_101 != 0 ||
V_247 [ V_250 ] . V_251 != NULL )
break;
V_249 -> V_93 = V_250 ;
return V_247 + V_250 ;
}
void
F_123 ( char * V_252 , int * V_51 , int * V_180 , int * V_52 , int * V_253 )
{
char * V_246 = V_252 ;
* V_51 = F_124 ( V_246 , NULL , 10 ) ;
while ( * V_246 >= '0' && * V_246 <= '9' )
V_246 ++ ;
if ( * V_246 )
* V_180 = * V_246 ++ ;
if ( * V_246 )
* V_52 = * V_246 ++ - '0' ;
if ( * V_246 )
* V_253 = * V_246 ;
}
int
F_125 ( struct V_1 * V_2 , struct V_248 * V_249 ,
int V_51 , int V_180 , int V_52 , int V_253 )
{
struct V_62 V_37 ;
static struct V_62 V_254 ;
int V_234 ;
F_126 ( & V_2 -> V_10 ) ;
F_127 ( & V_2 -> V_10 , & V_255 ) ;
memset ( & V_37 , 0 , sizeof( struct V_62 ) ) ;
V_37 . V_38 = V_256 | V_47 | V_80 ;
for ( V_234 = 0 ; V_257 [ V_234 ] . V_258 ; V_234 ++ )
if ( V_257 [ V_234 ] . V_258 <= V_51 )
break;
V_37 . V_38 |= V_257 [ V_234 ] . V_36 ;
if ( V_52 == 7 )
V_37 . V_38 |= V_56 ;
else
V_37 . V_38 |= V_259 ;
switch ( V_180 ) {
case 'o' : case 'O' :
V_37 . V_38 |= V_260 ;
case 'e' : case 'E' :
V_37 . V_38 |= V_58 ;
break;
}
if ( V_253 == 'r' )
V_37 . V_38 |= V_78 ;
V_2 -> V_22 |= V_41 ;
V_2 -> V_11 -> V_82 ( V_2 , & V_37 , & V_254 ) ;
if ( V_249 )
V_249 -> V_36 = V_37 . V_38 ;
return 0 ;
}
static void F_94 ( struct V_3 * V_4 , int V_235 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
if ( V_4 -> V_235 != V_235 ) {
if ( V_2 -> V_11 -> V_261 )
V_2 -> V_11 -> V_261 ( V_2 , V_235 , V_4 -> V_235 ) ;
V_4 -> V_235 = V_235 ;
}
}
static int F_128 ( struct V_262 * V_263 , void * V_18 )
{
struct V_264 * V_265 = V_18 ;
struct V_241 * V_266 = V_265 -> V_226 -> V_241 ;
T_6 V_267 = F_129 ( V_266 -> V_268 , V_266 -> V_269 ) +
V_265 -> V_2 -> line ;
return V_263 -> V_267 == V_267 ;
}
int F_130 ( struct V_220 * V_221 , struct V_1 * V_25 )
{
struct V_3 * V_4 = V_221 -> V_4 + V_25 -> line ;
struct V_26 * V_2 = & V_4 -> V_2 ;
struct V_262 * V_270 ;
struct V_264 V_265 = { V_25 , V_221 } ;
F_55 ( & V_2 -> V_100 ) ;
V_270 = F_131 ( V_25 -> V_263 , & V_265 , F_128 ) ;
if ( F_132 ( V_270 ) ) {
if ( ! F_133 ( V_25 -> V_50 ) )
V_25 -> V_271 = 1 ;
F_134 ( V_270 ) ;
F_56 ( & V_2 -> V_100 ) ;
return 0 ;
}
if ( V_272 || ! F_17 ( V_25 ) )
V_25 -> V_273 = 1 ;
if ( V_2 -> V_9 & V_29 ) {
const struct V_274 * V_11 = V_25 -> V_11 ;
int V_275 ;
if ( V_272 || ! F_17 ( V_25 ) ) {
F_14 ( V_276 , & V_2 -> V_9 ) ;
F_22 ( V_45 , & V_2 -> V_9 ) ;
F_20 ( & V_25 -> V_10 ) ;
V_11 -> V_12 ( V_25 ) ;
V_11 -> V_23 ( V_25 , 0 ) ;
V_11 -> V_210 ( V_25 ) ;
F_21 ( & V_25 -> V_10 ) ;
}
for ( V_275 = 3 ; ! V_11 -> V_149 ( V_25 ) && V_275 ; V_275 -- )
F_135 ( 10 ) ;
if ( ! V_275 )
F_62 ( V_206 L_28
L_29 ,
V_25 -> V_263 ? F_136 ( V_25 -> V_263 ) : L_27 ,
V_25 -> V_263 ? L_30 : L_27 ,
V_221 -> F_136 ,
V_221 -> V_241 -> V_277 + V_25 -> line ) ;
if ( V_272 || ! F_17 ( V_25 ) )
V_11 -> V_49 ( V_25 ) ;
}
if ( V_272 && F_17 ( V_25 ) )
F_137 ( V_25 -> V_35 ) ;
if ( V_272 || ! F_17 ( V_25 ) )
F_94 ( V_4 , 3 ) ;
F_56 ( & V_2 -> V_100 ) ;
return 0 ;
}
int F_138 ( struct V_220 * V_221 , struct V_1 * V_25 )
{
struct V_3 * V_4 = V_221 -> V_4 + V_25 -> line ;
struct V_26 * V_2 = & V_4 -> V_2 ;
struct V_262 * V_270 ;
struct V_264 V_265 = { V_25 , V_221 } ;
struct V_62 V_37 ;
F_55 ( & V_2 -> V_100 ) ;
V_270 = F_131 ( V_25 -> V_263 , & V_265 , F_128 ) ;
if ( ! V_25 -> V_273 && F_132 ( V_270 ) ) {
if ( V_25 -> V_271 ) {
F_139 ( V_25 -> V_50 ) ;
V_25 -> V_271 = 0 ;
}
F_56 ( & V_2 -> V_100 ) ;
return 0 ;
}
V_25 -> V_273 = 0 ;
if ( F_17 ( V_25 ) ) {
memset ( & V_37 , 0 , sizeof( struct V_62 ) ) ;
V_37 . V_38 = V_25 -> V_35 -> V_36 ;
if ( V_2 -> V_7 && V_2 -> V_7 -> V_37 && V_37 . V_38 == 0 )
V_37 = * ( V_2 -> V_7 -> V_37 ) ;
V_25 -> V_11 -> V_82 ( V_25 , & V_37 , NULL ) ;
if ( V_272 )
F_140 ( V_25 -> V_35 ) ;
}
if ( V_2 -> V_9 & V_278 ) {
const struct V_274 * V_11 = V_25 -> V_11 ;
int V_86 ;
F_94 ( V_4 , 0 ) ;
F_20 ( & V_25 -> V_10 ) ;
V_11 -> V_23 ( V_25 , 0 ) ;
F_21 ( & V_25 -> V_10 ) ;
if ( V_272 || ! F_17 ( V_25 ) ) {
struct V_6 * V_7 = V_2 -> V_7 ;
V_86 = V_11 -> V_34 ( V_25 ) ;
if ( V_86 == 0 ) {
if ( V_7 )
F_18 ( V_7 , V_4 , NULL ) ;
F_20 ( & V_25 -> V_10 ) ;
V_11 -> V_23 ( V_25 , V_25 -> V_22 ) ;
V_11 -> V_17 ( V_25 ) ;
F_21 ( & V_25 -> V_10 ) ;
F_14 ( V_45 , & V_2 -> V_9 ) ;
} else {
F_24 ( V_7 , V_4 ) ;
}
}
F_22 ( V_276 , & V_2 -> V_9 ) ;
}
F_56 ( & V_2 -> V_100 ) ;
return 0 ;
}
static inline void
F_141 ( struct V_220 * V_221 , struct V_1 * V_2 )
{
char V_279 [ 64 ] ;
switch ( V_2 -> V_111 ) {
case V_280 :
snprintf ( V_279 , sizeof( V_279 ) , L_31 , V_2 -> V_101 ) ;
break;
case V_281 :
snprintf ( V_279 , sizeof( V_279 ) ,
L_32 , V_2 -> V_101 , V_2 -> V_109 ) ;
break;
case V_239 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
snprintf ( V_279 , sizeof( V_279 ) ,
L_33 , ( unsigned long long ) V_2 -> V_115 ) ;
break;
default:
F_142 ( V_279 , L_34 , sizeof( V_279 ) ) ;
break;
}
F_62 ( V_287 L_35 ,
V_2 -> V_263 ? F_136 ( V_2 -> V_263 ) : L_27 ,
V_2 -> V_263 ? L_30 : L_27 ,
V_221 -> F_136 ,
V_221 -> V_241 -> V_277 + V_2 -> line ,
V_279 , V_2 -> V_50 , F_110 ( V_2 ) ) ;
}
static void
F_143 ( struct V_220 * V_221 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
unsigned int V_9 ;
if ( ! V_2 -> V_101 && ! V_2 -> V_115 && ! V_2 -> V_251 )
return;
V_9 = 0 ;
if ( V_2 -> V_9 & V_156 )
V_9 |= V_157 ;
if ( V_2 -> V_9 & V_288 ) {
if ( ! ( V_2 -> V_9 & V_289 ) ) {
V_2 -> type = V_31 ;
V_9 |= V_155 ;
}
V_2 -> V_11 -> V_158 ( V_2 , V_9 ) ;
}
if ( V_2 -> type != V_31 ) {
unsigned long V_9 ;
F_141 ( V_221 , V_2 ) ;
F_94 ( V_4 , 0 ) ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_2 -> V_11 -> V_23 ( V_2 , V_2 -> V_22 & V_41 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
if ( V_2 -> V_35 && ! ( V_2 -> V_35 -> V_9 & V_290 ) )
F_144 ( V_2 -> V_35 ) ;
if ( ! F_17 ( V_2 ) )
F_94 ( V_4 , 3 ) ;
}
}
static int F_145 ( struct V_241 * V_226 , int line , char * V_252 )
{
struct V_220 * V_221 = V_226 -> V_227 ;
struct V_3 * V_4 = V_221 -> V_4 + line ;
struct V_1 * V_2 ;
int V_51 = 9600 ;
int V_52 = 8 ;
int V_180 = 'n' ;
int V_253 = 'n' ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
if ( ! ( V_2 -> V_11 -> V_291 && V_2 -> V_11 -> V_292 ) )
return - 1 ;
if ( V_252 ) {
F_123 ( V_252 , & V_51 , & V_180 , & V_52 , & V_253 ) ;
return F_125 ( V_2 , NULL , V_51 , V_180 , V_52 , V_253 ) ;
}
return 0 ;
}
static int F_146 ( struct V_241 * V_226 , int line )
{
struct V_220 * V_221 = V_226 -> V_227 ;
struct V_3 * V_4 = V_221 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
return V_2 -> V_11 -> V_291 ( V_2 ) ;
}
static void F_147 ( struct V_241 * V_226 , int line , char V_89 )
{
struct V_220 * V_221 = V_226 -> V_227 ;
struct V_3 * V_4 = V_221 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return;
V_2 = V_4 -> V_1 ;
V_2 -> V_11 -> V_292 ( V_2 , V_89 ) ;
}
int F_148 ( struct V_220 * V_221 )
{
struct V_241 * V_293 ;
int V_234 , V_28 ;
F_2 ( V_221 -> V_4 ) ;
V_221 -> V_4 = F_149 ( sizeof( struct V_3 ) * V_221 -> V_244 , V_32 ) ;
if ( ! V_221 -> V_4 )
goto V_191;
V_293 = F_150 ( V_221 -> V_244 ) ;
if ( ! V_293 )
goto V_294;
V_221 -> V_241 = V_293 ;
V_293 -> V_295 = V_221 -> V_295 ;
V_293 -> V_296 = V_221 -> V_296 ;
V_293 -> V_207 = V_221 -> F_136 ;
V_293 -> V_268 = V_221 -> V_268 ;
V_293 -> V_269 = V_221 -> V_297 ;
V_293 -> type = V_298 ;
V_293 -> V_299 = V_300 ;
V_293 -> V_301 = V_302 ;
V_293 -> V_301 . V_38 = V_303 | V_259 | V_256 | V_47 | V_80 ;
V_293 -> V_301 . V_199 = V_293 -> V_301 . V_198 = 9600 ;
V_293 -> V_9 = V_304 | V_305 ;
V_293 -> V_227 = V_221 ;
F_151 ( V_293 , & V_274 ) ;
for ( V_234 = 0 ; V_234 < V_221 -> V_244 ; V_234 ++ ) {
struct V_3 * V_4 = V_221 -> V_4 + V_234 ;
struct V_26 * V_2 = & V_4 -> V_2 ;
F_152 ( V_2 ) ;
V_2 -> V_11 = & V_306 ;
V_2 -> V_106 = 500 ;
V_2 -> V_107 = 30000 ;
F_153 ( & V_4 -> V_5 , F_10 ,
( unsigned long ) V_4 ) ;
}
V_28 = F_154 ( V_293 ) ;
if ( V_28 >= 0 )
return V_28 ;
F_155 ( V_293 ) ;
V_294:
F_156 ( V_221 -> V_4 ) ;
V_191:
return - V_33 ;
}
void F_157 ( struct V_220 * V_221 )
{
struct V_241 * V_307 = V_221 -> V_241 ;
F_158 ( V_307 ) ;
F_155 ( V_307 ) ;
F_156 ( V_221 -> V_4 ) ;
V_221 -> V_241 = NULL ;
}
struct V_241 * F_159 ( struct V_248 * V_249 , int * V_93 )
{
struct V_220 * V_307 = V_249 -> V_18 ;
* V_93 = V_249 -> V_93 ;
return V_307 -> V_241 ;
}
int F_160 ( struct V_220 * V_221 , struct V_1 * V_25 )
{
struct V_3 * V_4 ;
struct V_26 * V_2 ;
int V_86 = 0 ;
struct V_262 * V_270 ;
F_2 ( F_161 () ) ;
if ( V_25 -> line >= V_221 -> V_244 )
return - V_131 ;
V_4 = V_221 -> V_4 + V_25 -> line ;
V_2 = & V_4 -> V_2 ;
F_55 ( & V_308 ) ;
F_55 ( & V_2 -> V_100 ) ;
if ( V_4 -> V_1 ) {
V_86 = - V_131 ;
goto V_191;
}
V_4 -> V_1 = V_25 ;
V_4 -> V_235 = - 1 ;
V_25 -> V_35 = V_221 -> V_35 ;
V_25 -> V_4 = V_4 ;
if ( ! ( F_17 ( V_25 ) && ( V_25 -> V_35 -> V_9 & V_290 ) ) ) {
F_126 ( & V_25 -> V_10 ) ;
F_127 ( & V_25 -> V_10 , & V_255 ) ;
}
F_143 ( V_221 , V_4 , V_25 ) ;
V_270 = F_162 ( V_221 -> V_241 , V_25 -> line , V_25 -> V_263 ) ;
if ( F_163 ( ! F_107 ( V_270 ) ) ) {
F_164 ( V_270 , 1 ) ;
F_165 ( V_270 , 0 ) ;
} else
F_62 ( V_206 L_36 ,
V_25 -> line ) ;
V_25 -> V_9 &= ~ V_223 ;
V_191:
F_56 ( & V_2 -> V_100 ) ;
F_56 ( & V_308 ) ;
return V_86 ;
}
int F_166 ( struct V_220 * V_221 , struct V_1 * V_25 )
{
struct V_3 * V_4 = V_221 -> V_4 + V_25 -> line ;
struct V_26 * V_2 = & V_4 -> V_2 ;
F_2 ( F_161 () ) ;
if ( V_4 -> V_1 != V_25 )
F_62 ( V_309 L_37 ,
V_4 -> V_1 , V_25 ) ;
F_55 ( & V_308 ) ;
F_55 ( & V_2 -> V_100 ) ;
V_25 -> V_9 |= V_223 ;
F_56 ( & V_2 -> V_100 ) ;
F_167 ( V_221 -> V_241 , V_25 -> line ) ;
if ( V_2 -> V_7 )
F_168 ( V_2 -> V_7 ) ;
if ( V_25 -> type != V_31 )
V_25 -> V_11 -> V_139 ( V_25 ) ;
V_25 -> type = V_31 ;
F_29 ( & V_4 -> V_5 ) ;
V_4 -> V_1 = NULL ;
F_56 ( & V_308 ) ;
return 0 ;
}
int F_169 ( struct V_1 * V_310 , struct V_1 * V_311 )
{
if ( V_310 -> V_111 != V_311 -> V_111 )
return 0 ;
switch ( V_310 -> V_111 ) {
case V_280 :
return ( V_310 -> V_101 == V_311 -> V_101 ) ;
case V_281 :
return ( V_310 -> V_101 == V_311 -> V_101 ) &&
( V_310 -> V_109 == V_311 -> V_109 ) ;
case V_239 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
return ( V_310 -> V_115 == V_311 -> V_115 ) ;
}
return 0 ;
}
