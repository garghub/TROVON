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
static int F_11 ( struct V_6 * V_5 , struct V_3 * V_4 ,
int V_22 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
unsigned long V_25 ;
int V_26 = 0 ;
if ( V_23 -> type == V_27 )
return 1 ;
if ( ! V_4 -> V_12 . V_13 ) {
V_25 = F_12 ( V_28 ) ;
if ( ! V_25 )
return - V_29 ;
V_4 -> V_12 . V_13 = ( unsigned char * ) V_25 ;
F_13 ( & V_4 -> V_12 ) ;
}
V_26 = V_23 -> V_10 -> V_30 ( V_23 ) ;
if ( V_26 == 0 ) {
if ( F_14 ( V_23 ) && V_23 -> V_31 -> V_32 ) {
V_5 -> V_33 . V_34 = V_23 -> V_31 -> V_32 ;
V_23 -> V_31 -> V_32 = 0 ;
}
F_15 ( V_5 , V_4 , NULL ) ;
if ( V_22 ) {
if ( V_5 -> V_33 . V_34 & V_35 )
F_16 ( V_23 , V_36 | V_37 ) ;
}
if ( F_17 ( V_2 ) ) {
F_18 ( & V_23 -> V_9 ) ;
if ( ! ( V_23 -> V_10 -> V_38 ( V_23 ) & V_39 ) )
V_5 -> V_15 = 1 ;
F_19 ( & V_23 -> V_9 ) ;
}
}
if ( V_26 && F_20 ( V_40 ) )
return 1 ;
return V_26 ;
}
static int F_21 ( struct V_6 * V_5 , struct V_3 * V_4 ,
int V_22 )
{
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_26 ;
if ( V_2 -> V_8 & V_41 )
return 0 ;
F_22 ( V_42 , & V_5 -> V_8 ) ;
V_26 = F_11 ( V_5 , V_4 , V_22 ) ;
if ( ! V_26 ) {
F_22 ( V_43 , & V_2 -> V_8 ) ;
F_23 ( V_42 , & V_5 -> V_8 ) ;
} else if ( V_26 > 0 )
V_26 = 0 ;
return V_26 ;
}
static void F_24 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
if ( V_5 )
F_22 ( V_42 , & V_5 -> V_8 ) ;
if ( F_25 ( V_43 , & V_2 -> V_8 ) ) {
if ( ! V_5 || ( V_5 -> V_33 . V_34 & V_44 ) )
F_26 ( V_23 , V_37 | V_36 ) ;
F_27 ( V_2 ) ;
}
F_23 ( V_45 , & V_2 -> V_8 ) ;
if ( V_4 -> V_12 . V_13 ) {
F_28 ( ( unsigned long ) V_4 -> V_12 . V_13 ) ;
V_4 -> V_12 . V_13 = NULL ;
}
}
void
F_29 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned int V_46 )
{
unsigned int V_47 ;
switch ( V_32 & V_48 ) {
case V_49 :
V_47 = 7 ;
break;
case V_50 :
V_47 = 8 ;
break;
case V_51 :
V_47 = 9 ;
break;
default:
V_47 = 10 ;
break;
}
if ( V_32 & V_52 )
V_47 ++ ;
if ( V_32 & V_53 )
V_47 ++ ;
V_47 = V_47 * V_2 -> V_54 ;
V_2 -> V_55 = ( V_56 * V_47 ) / V_46 + V_56 / 50 ;
}
unsigned int
F_30 ( struct V_1 * V_2 , struct V_57 * V_33 ,
struct V_57 * V_19 , unsigned int V_58 , unsigned int V_59 )
{
unsigned int V_60 , V_46 , V_61 = 38400 ;
int V_62 = 0 ;
T_1 V_8 = V_2 -> V_8 & V_63 ;
if ( V_8 == V_64 )
V_61 = 57600 ;
else if ( V_8 == V_65 )
V_61 = 115200 ;
else if ( V_8 == V_66 )
V_61 = 230400 ;
else if ( V_8 == V_67 )
V_61 = 460800 ;
for ( V_60 = 0 ; V_60 < 2 ; V_60 ++ ) {
V_46 = F_31 ( V_33 ) ;
if ( V_46 == 38400 )
V_46 = V_61 ;
if ( V_46 == 0 ) {
V_62 = 1 ;
V_46 = 9600 ;
}
if ( V_46 >= V_58 && V_46 <= V_59 )
return V_46 ;
V_33 -> V_34 &= ~ V_35 ;
if ( V_19 ) {
V_46 = F_31 ( V_19 ) ;
if ( ! V_62 )
F_32 ( V_33 ,
V_46 , V_46 ) ;
V_19 = NULL ;
continue;
}
if ( ! V_62 ) {
if ( V_46 <= V_58 )
F_32 ( V_33 ,
V_58 + 1 , V_58 + 1 ) ;
else
F_32 ( V_33 ,
V_59 - 1 , V_59 - 1 ) ;
}
}
F_33 ( 1 ) ;
return 0 ;
}
unsigned int
F_34 ( struct V_1 * V_2 , unsigned int V_46 )
{
unsigned int V_68 ;
if ( V_46 == 38400 && ( V_2 -> V_8 & V_63 ) == V_69 )
V_68 = V_2 -> V_70 ;
else
V_68 = F_35 ( V_2 -> V_71 , 16 * V_46 ) ;
return V_68 ;
}
static void F_15 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_57 * V_72 )
{
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_57 * V_33 ;
if ( ! V_5 || V_23 -> type == V_27 )
return;
V_33 = & V_5 -> V_33 ;
if ( V_33 -> V_34 & V_73 )
F_22 ( V_74 , & V_2 -> V_8 ) ;
else
F_23 ( V_74 , & V_2 -> V_8 ) ;
if ( V_33 -> V_34 & V_75 )
F_23 ( V_76 , & V_2 -> V_8 ) ;
else
F_22 ( V_76 , & V_2 -> V_8 ) ;
V_23 -> V_10 -> V_77 ( V_23 , V_33 , V_72 ) ;
}
static inline int F_36 ( struct V_1 * V_2 ,
struct V_78 * V_79 , unsigned char V_80 )
{
unsigned long V_8 ;
int V_81 = 0 ;
if ( ! V_79 -> V_13 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
if ( F_37 ( V_79 ) != 0 ) {
V_79 -> V_13 [ V_79 -> V_82 ] = V_80 ;
V_79 -> V_82 = ( V_79 -> V_82 + 1 ) & ( V_83 - 1 ) ;
V_81 = 1 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
return V_81 ;
}
static int F_38 ( struct V_6 * V_5 , unsigned char V_84 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
return F_36 ( V_4 -> V_1 , & V_4 -> V_12 , V_84 ) ;
}
static void F_39 ( struct V_6 * V_5 )
{
F_9 ( V_5 ) ;
}
static int F_40 ( struct V_6 * V_5 ,
const unsigned char * V_13 , int V_85 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 ;
struct V_78 * V_79 ;
unsigned long V_8 ;
int V_80 , V_81 = 0 ;
if ( ! V_4 ) {
F_33 ( 1 ) ;
return - V_86 ;
}
V_2 = V_4 -> V_1 ;
V_79 = & V_4 -> V_12 ;
if ( ! V_79 -> V_13 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
while ( 1 ) {
V_80 = F_41 ( V_79 -> V_82 , V_79 -> V_87 , V_83 ) ;
if ( V_85 < V_80 )
V_80 = V_85 ;
if ( V_80 <= 0 )
break;
memcpy ( V_79 -> V_13 + V_79 -> V_82 , V_13 , V_80 ) ;
V_79 -> V_82 = ( V_79 -> V_82 + V_80 ) & ( V_83 - 1 ) ;
V_13 += V_80 ;
V_85 -= V_80 ;
V_81 += V_80 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_9 ( V_5 ) ;
return V_81 ;
}
static int F_42 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_81 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_81 = F_37 ( & V_4 -> V_12 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_81 ;
}
static int F_43 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_81 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_81 = F_44 ( & V_4 -> V_12 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_81 ;
}
static void F_45 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 ;
unsigned long V_8 ;
if ( ! V_4 ) {
F_33 ( 1 ) ;
return;
}
V_2 = V_4 -> V_1 ;
F_46 ( L_1 , V_5 -> V_88 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
F_13 ( & V_4 -> V_12 ) ;
if ( V_2 -> V_10 -> V_89 )
V_2 -> V_10 -> V_89 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_3 ( V_5 ) ;
}
static void F_47 ( struct V_6 * V_5 , char V_84 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_8 ;
if ( V_2 -> V_10 -> V_90 )
V_2 -> V_10 -> V_90 ( V_2 , V_84 ) ;
else {
V_2 -> V_91 = V_84 ;
if ( V_84 ) {
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_10 -> V_16 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
}
}
}
static void F_48 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
T_2 V_92 = 0 ;
if ( F_49 ( V_5 ) )
V_92 |= V_93 ;
if ( V_5 -> V_33 . V_34 & V_73 )
V_92 |= V_94 ;
if ( V_2 -> V_8 & V_92 ) {
V_2 -> V_10 -> V_95 ( V_2 ) ;
V_92 &= ~ V_2 -> V_8 ;
}
if ( V_92 & V_93 )
F_47 ( V_5 , F_50 ( V_5 ) ) ;
if ( V_92 & V_94 )
F_26 ( V_2 , V_36 ) ;
}
static void F_51 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
T_2 V_92 = 0 ;
if ( F_49 ( V_5 ) )
V_92 |= V_93 ;
if ( V_5 -> V_33 . V_34 & V_73 )
V_92 |= V_94 ;
if ( V_2 -> V_8 & V_92 ) {
V_2 -> V_10 -> V_96 ( V_2 ) ;
V_92 &= ~ V_2 -> V_8 ;
}
if ( V_92 & V_93 ) {
if ( V_2 -> V_91 )
V_2 -> V_91 = 0 ;
else
F_47 ( V_5 , F_52 ( V_5 ) ) ;
}
if ( V_92 & V_94 )
F_16 ( V_2 , V_36 ) ;
}
static void F_53 ( struct V_24 * V_2 ,
struct V_97 * V_98 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> type = V_23 -> type ;
V_98 -> line = V_23 -> line ;
V_98 -> V_2 = V_23 -> V_99 ;
if ( V_100 )
V_98 -> V_101 = ( long ) V_23 -> V_99 >> V_100 ;
V_98 -> V_102 = V_23 -> V_102 ;
V_98 -> V_8 = V_23 -> V_8 ;
V_98 -> V_103 = V_23 -> V_54 ;
V_98 -> V_104 = V_23 -> V_71 / 16 ;
V_98 -> V_105 = F_55 ( V_2 -> V_105 ) / 10 ;
V_98 -> V_106 = V_2 -> V_106 == V_107 ?
V_107 :
F_55 ( V_2 -> V_106 ) / 10 ;
V_98 -> V_70 = V_23 -> V_70 ;
V_98 -> V_108 = V_23 -> V_108 ;
V_98 -> V_109 = V_23 -> V_110 ;
V_98 -> V_111 = V_23 -> V_112 ;
V_98 -> V_113 = ( void * ) ( unsigned long ) V_23 -> V_114 ;
}
static void F_56 ( struct V_24 * V_2 ,
struct V_97 * V_98 )
{
F_57 ( & V_2 -> V_115 ) ;
F_53 ( V_2 , V_98 ) ;
F_58 ( & V_2 -> V_115 ) ;
}
static int F_59 ( struct V_24 * V_2 ,
struct V_97 T_3 * V_98 )
{
struct V_97 V_116 ;
F_56 ( V_2 , & V_116 ) ;
if ( F_60 ( V_98 , & V_116 , sizeof( * V_98 ) ) )
return - V_117 ;
return 0 ;
}
static int F_61 ( struct V_6 * V_5 , struct V_24 * V_2 ,
struct V_3 * V_4 ,
struct V_97 * V_118 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
unsigned long V_119 ;
unsigned int V_120 , V_121 , V_106 ;
unsigned int V_122 , V_105 ;
T_1 V_123 , V_124 ;
int V_26 = 0 ;
V_119 = V_118 -> V_2 ;
if ( V_100 )
V_119 += ( unsigned long ) V_118 -> V_101 << V_100 ;
V_118 -> V_102 = F_62 ( V_118 -> V_102 ) ;
V_105 = F_63 ( V_118 -> V_105 * 10 ) ;
V_106 = V_118 -> V_106 == V_107 ?
V_107 :
F_63 ( V_118 -> V_106 * 10 ) ;
V_120 = ! ( V_23 -> V_8 & V_125 )
&& V_118 -> V_102 != V_23 -> V_102 ;
V_121 = ! ( V_23 -> V_8 & V_125 )
&& ( V_119 != V_23 -> V_99 ||
( unsigned long ) V_118 -> V_113 != V_23 -> V_114 ||
V_118 -> V_108 != V_23 -> V_108 ||
V_118 -> V_109 != V_23 -> V_110 ||
V_118 -> V_111 != V_23 -> V_112 ||
V_118 -> type != V_23 -> type ) ;
V_123 = V_23 -> V_8 ;
V_124 = V_118 -> V_8 ;
V_122 = V_23 -> V_70 ;
if ( ! F_20 ( V_40 ) ) {
V_26 = - V_126 ;
if ( V_120 || V_121 ||
( V_118 -> V_104 != V_23 -> V_71 / 16 ) ||
( V_105 != V_2 -> V_105 ) ||
( V_106 != V_2 -> V_106 ) ||
( V_118 -> V_103 &&
V_118 -> V_103 != V_23 -> V_54 ) ||
( ( ( V_124 ^ V_123 ) & ~ V_127 ) != 0 ) )
goto exit;
V_23 -> V_8 = ( ( V_23 -> V_8 & ~ V_127 ) |
( V_124 & V_127 ) ) ;
V_23 -> V_70 = V_118 -> V_70 ;
goto V_128;
}
if ( V_23 -> V_10 -> V_129 )
V_26 = V_23 -> V_10 -> V_129 ( V_23 , V_118 ) ;
if ( ( V_118 -> V_102 >= V_130 ) || ( V_118 -> V_102 < 0 ) ||
( V_118 -> V_104 < 9600 ) )
V_26 = - V_131 ;
if ( V_26 )
goto exit;
if ( V_121 || V_120 ) {
V_26 = - V_132 ;
if ( F_64 ( V_2 ) > 1 )
goto exit;
F_24 ( V_5 , V_4 ) ;
}
if ( V_121 ) {
unsigned long V_133 , V_134 ;
unsigned int V_135 , V_136 , V_137 , V_138 ;
V_133 = V_23 -> V_99 ;
V_134 = V_23 -> V_114 ;
V_135 = V_23 -> type ;
V_137 = V_23 -> V_108 ;
V_136 = V_23 -> V_110 ;
V_138 = V_23 -> V_112 ;
if ( V_135 != V_27 )
V_23 -> V_10 -> V_139 ( V_23 ) ;
V_23 -> V_99 = V_119 ;
V_23 -> type = V_118 -> type ;
V_23 -> V_108 = V_118 -> V_108 ;
V_23 -> V_110 = V_118 -> V_109 ;
V_23 -> V_112 = V_118 -> V_111 ;
V_23 -> V_114 = ( unsigned long ) V_118 -> V_113 ;
if ( V_23 -> type != V_27 ) {
V_26 = V_23 -> V_10 -> V_140 ( V_23 ) ;
} else {
V_26 = 0 ;
}
if ( V_26 && V_135 != V_27 ) {
V_23 -> V_99 = V_133 ;
V_23 -> type = V_135 ;
V_23 -> V_108 = V_137 ;
V_23 -> V_110 = V_136 ;
V_23 -> V_112 = V_138 ;
V_23 -> V_114 = V_134 ;
V_26 = V_23 -> V_10 -> V_140 ( V_23 ) ;
if ( V_26 )
V_23 -> type = V_27 ;
V_26 = - V_132 ;
goto exit;
}
}
if ( V_120 )
V_23 -> V_102 = V_118 -> V_102 ;
if ( ! ( V_23 -> V_8 & V_125 ) )
V_23 -> V_71 = V_118 -> V_104 * 16 ;
V_23 -> V_8 = ( V_23 -> V_8 & ~ V_141 ) |
( V_124 & V_141 ) ;
V_23 -> V_70 = V_118 -> V_70 ;
V_2 -> V_105 = V_105 ;
V_2 -> V_106 = V_106 ;
if ( V_118 -> V_103 )
V_23 -> V_54 = V_118 -> V_103 ;
V_2 -> V_142 = ( V_23 -> V_8 & V_143 ) ? 1 : 0 ;
V_128:
V_26 = 0 ;
if ( V_23 -> type == V_27 )
goto exit;
if ( V_2 -> V_8 & V_41 ) {
if ( ( ( V_123 ^ V_23 -> V_8 ) & V_63 ) ||
V_122 != V_23 -> V_70 ) {
if ( V_23 -> V_8 & V_63 ) {
char V_13 [ 64 ] ;
F_65 ( V_144
L_2
L_3 , V_145 -> V_146 ,
F_66 ( V_2 -> V_5 , V_13 ) ) ;
}
F_15 ( V_5 , V_4 , NULL ) ;
}
} else
V_26 = F_21 ( V_5 , V_4 , 1 ) ;
exit:
return V_26 ;
}
static int F_67 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_97 T_3 * V_147 )
{
struct V_97 V_148 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_26 ;
if ( F_68 ( & V_148 , V_147 , sizeof( V_148 ) ) )
return - V_117 ;
F_57 ( & V_2 -> V_115 ) ;
V_26 = F_61 ( V_5 , V_2 , V_4 , & V_148 ) ;
F_58 ( & V_2 -> V_115 ) ;
return V_26 ;
}
static int F_69 ( struct V_6 * V_5 ,
struct V_3 * V_4 , unsigned int T_3 * V_149 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
unsigned int V_150 ;
V_150 = V_23 -> V_10 -> V_151 ( V_23 ) ;
if ( V_23 -> V_91 ||
( ( F_44 ( & V_4 -> V_12 ) > 0 ) &&
! V_5 -> V_14 && ! V_5 -> V_15 ) )
V_150 &= ~ V_152 ;
return F_70 ( V_150 , V_149 ) ;
}
static int F_71 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
int V_150 = - V_153 ;
F_57 ( & V_2 -> V_115 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_42 ) ) ) {
V_150 = V_23 -> V_20 ;
F_18 ( & V_23 -> V_9 ) ;
V_150 |= V_23 -> V_10 -> V_38 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
}
F_58 ( & V_2 -> V_115 ) ;
return V_150 ;
}
static int
F_72 ( struct V_6 * V_5 , unsigned int V_17 , unsigned int V_18 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_81 = - V_153 ;
F_57 ( & V_2 -> V_115 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_42 ) ) ) {
F_10 ( V_23 , V_17 , V_18 ) ;
V_81 = 0 ;
}
F_58 ( & V_2 -> V_115 ) ;
return V_81 ;
}
static int F_73 ( struct V_6 * V_5 , int V_154 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_57 ( & V_2 -> V_115 ) ;
if ( V_23 -> type != V_27 )
V_23 -> V_10 -> V_155 ( V_23 , V_154 ) ;
F_58 ( & V_2 -> V_115 ) ;
return 0 ;
}
static int F_74 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_8 , V_81 ;
if ( ! F_20 ( V_40 ) )
return - V_126 ;
if ( F_75 ( & V_2 -> V_115 ) )
return - V_156 ;
V_81 = - V_132 ;
if ( F_64 ( V_2 ) == 1 ) {
F_24 ( V_5 , V_4 ) ;
if ( V_23 -> type != V_27 )
V_23 -> V_10 -> V_139 ( V_23 ) ;
V_8 = V_157 ;
if ( V_23 -> V_8 & V_158 )
V_8 |= V_159 ;
V_23 -> V_10 -> V_160 ( V_23 , V_8 ) ;
V_81 = F_21 ( V_5 , V_4 , 1 ) ;
}
F_58 ( & V_2 -> V_115 ) ;
return V_81 ;
}
static int
F_76 ( struct V_3 * V_4 , unsigned long V_161 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_77 ( V_162 , V_145 ) ;
struct V_163 V_164 , V_165 ;
int V_81 ;
F_18 ( & V_23 -> V_9 ) ;
memcpy ( & V_164 , & V_23 -> V_166 , sizeof( struct V_163 ) ) ;
V_23 -> V_10 -> V_167 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
F_78 ( & V_2 -> V_168 , & V_162 ) ;
for (; ; ) {
F_18 ( & V_23 -> V_9 ) ;
memcpy ( & V_165 , & V_23 -> V_166 , sizeof( struct V_163 ) ) ;
F_19 ( & V_23 -> V_9 ) ;
F_79 ( V_169 ) ;
if ( ( ( V_161 & V_170 ) && ( V_165 . V_171 != V_164 . V_171 ) ) ||
( ( V_161 & V_172 ) && ( V_165 . V_173 != V_164 . V_173 ) ) ||
( ( V_161 & V_174 ) && ( V_165 . V_175 != V_164 . V_175 ) ) ||
( ( V_161 & V_39 ) && ( V_165 . V_176 != V_164 . V_176 ) ) ) {
V_81 = 0 ;
break;
}
F_80 () ;
if ( F_81 ( V_145 ) ) {
V_81 = - V_156 ;
break;
}
V_164 = V_165 ;
}
V_145 -> V_4 = V_177 ;
F_82 ( & V_2 -> V_168 , & V_162 ) ;
return V_81 ;
}
static int F_83 ( struct V_6 * V_5 ,
struct V_178 * V_166 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_163 V_165 ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_18 ( & V_23 -> V_9 ) ;
memcpy ( & V_165 , & V_23 -> V_166 , sizeof( struct V_163 ) ) ;
F_19 ( & V_23 -> V_9 ) ;
V_166 -> V_176 = V_165 . V_176 ;
V_166 -> V_173 = V_165 . V_173 ;
V_166 -> V_171 = V_165 . V_171 ;
V_166 -> V_175 = V_165 . V_175 ;
V_166 -> V_179 = V_165 . V_179 ;
V_166 -> V_180 = V_165 . V_180 ;
V_166 -> V_181 = V_165 . V_181 ;
V_166 -> V_182 = V_165 . V_182 ;
V_166 -> V_183 = V_165 . V_183 ;
V_166 -> V_184 = V_165 . V_184 ;
V_166 -> V_185 = V_165 . V_185 ;
return 0 ;
}
static int
F_84 ( struct V_6 * V_5 , unsigned int V_186 ,
unsigned long V_161 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
void T_3 * V_187 = ( void T_3 * ) V_161 ;
int V_81 = - V_188 ;
switch ( V_186 ) {
case V_189 :
V_81 = F_59 ( V_2 , V_187 ) ;
break;
case V_190 :
V_81 = F_67 ( V_5 , V_4 , V_187 ) ;
break;
case V_191 :
V_81 = F_74 ( V_5 , V_4 ) ;
break;
case V_192 :
case V_193 :
V_81 = 0 ;
break;
}
if ( V_81 != - V_188 )
goto V_194;
if ( V_5 -> V_8 & ( 1 << V_42 ) ) {
V_81 = - V_153 ;
goto V_194;
}
switch ( V_186 ) {
case V_195 :
V_81 = F_76 ( V_4 , V_161 ) ;
break;
}
if ( V_81 != - V_188 )
goto V_194;
F_57 ( & V_2 -> V_115 ) ;
if ( V_5 -> V_8 & ( 1 << V_42 ) ) {
V_81 = - V_153 ;
goto V_196;
}
switch ( V_186 ) {
case V_197 :
V_81 = F_69 ( V_5 , V_4 , V_187 ) ;
break;
default: {
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_23 -> V_10 -> V_198 )
V_81 = V_23 -> V_10 -> V_198 ( V_23 , V_186 , V_161 ) ;
break;
}
}
V_196:
F_58 ( & V_2 -> V_115 ) ;
V_194:
return V_81 ;
}
static void F_85 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_23 -> V_10 -> V_199 )
V_23 -> V_10 -> V_199 ( V_23 , V_5 -> V_33 . V_200 ) ;
}
static void F_86 ( struct V_6 * V_5 ,
struct V_57 * V_72 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_23 = V_4 -> V_1 ;
unsigned long V_8 ;
unsigned int V_32 = V_5 -> V_33 . V_34 ;
unsigned int V_201 = V_202 | V_203 | V_204 | V_205 | V_206 ;
bool V_207 = false ;
if ( V_23 -> V_8 & V_93 ) {
V_201 |= V_208 | V_209 | V_210 ;
V_207 =
V_5 -> V_33 . V_211 [ V_212 ] != V_72 -> V_211 [ V_212 ] ||
V_5 -> V_33 . V_211 [ V_213 ] != V_72 -> V_211 [ V_213 ] ;
}
if ( ( V_32 ^ V_72 -> V_34 ) == 0 &&
V_5 -> V_33 . V_214 == V_72 -> V_214 &&
V_5 -> V_33 . V_215 == V_72 -> V_215 &&
( ( V_5 -> V_33 . V_216 ^ V_72 -> V_216 ) & V_201 ) == 0 &&
! V_207 ) {
return;
}
F_15 ( V_5 , V_4 , V_72 ) ;
if ( ( V_72 -> V_34 & V_35 ) && ! ( V_32 & V_35 ) )
F_26 ( V_23 , V_36 | V_37 ) ;
else if ( ! ( V_72 -> V_34 & V_35 ) && ( V_32 & V_35 ) ) {
unsigned int V_92 = V_37 ;
if ( ! ( V_32 & V_73 ) ||
! F_87 ( V_217 , & V_5 -> V_8 ) )
V_92 |= V_36 ;
F_16 ( V_23 , V_92 ) ;
}
if ( V_23 -> V_8 & V_94 )
return;
if ( ( V_72 -> V_34 & V_73 ) && ! ( V_32 & V_73 ) ) {
F_5 ( & V_23 -> V_9 , V_8 ) ;
V_5 -> V_15 = 0 ;
F_7 ( V_5 ) ;
F_6 ( & V_23 -> V_9 , V_8 ) ;
}
else if ( ! ( V_72 -> V_34 & V_73 ) && ( V_32 & V_73 ) ) {
F_5 ( & V_23 -> V_9 , V_8 ) ;
if ( ! ( V_23 -> V_10 -> V_38 ( V_23 ) & V_39 ) ) {
V_5 -> V_15 = 1 ;
V_23 -> V_10 -> V_11 ( V_23 ) ;
}
F_6 ( & V_23 -> V_9 , V_8 ) ;
}
}
static void F_88 ( struct V_6 * V_5 , struct V_218 * V_219 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 ;
struct V_1 * V_23 ;
unsigned long V_8 ;
if ( ! V_4 )
return;
V_23 = V_4 -> V_1 ;
V_2 = & V_4 -> V_2 ;
F_46 ( L_4 , V_23 -> line ) ;
if ( F_89 ( V_2 , V_5 , V_219 ) == 0 )
return;
if ( V_2 -> V_8 & V_41 ) {
unsigned long V_8 ;
F_5 ( & V_23 -> V_9 , V_8 ) ;
V_23 -> V_10 -> V_220 ( V_23 ) ;
F_6 ( & V_23 -> V_9 , V_8 ) ;
F_90 ( V_5 , V_23 -> V_55 ) ;
}
F_57 ( & V_2 -> V_115 ) ;
F_24 ( V_5 , V_4 ) ;
F_45 ( V_5 ) ;
F_91 ( V_5 ) ;
F_92 ( V_2 , NULL ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_5 -> V_221 = 0 ;
if ( V_2 -> V_222 ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_105 )
F_93 (
F_55 ( V_2 -> V_105 ) ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
} else if ( ! F_14 ( V_23 ) ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_94 ( V_4 , V_223 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
}
F_23 ( V_224 , & V_2 -> V_8 ) ;
F_23 ( V_225 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_95 ( & V_2 -> V_226 ) ;
F_95 ( & V_2 -> V_227 ) ;
F_58 ( & V_2 -> V_115 ) ;
}
static void F_90 ( struct V_6 * V_5 , int V_55 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_228 , V_229 ;
if ( V_2 -> type == V_27 || V_2 -> V_54 == 0 )
return;
V_228 = ( V_2 -> V_55 - V_56 / 50 ) / V_2 -> V_54 ;
V_228 = V_228 / 5 ;
if ( V_228 == 0 )
V_228 = 1 ;
if ( V_55 && V_55 < V_228 )
V_228 = V_55 ;
if ( V_55 == 0 || V_55 > 2 * V_2 -> V_55 )
V_55 = 2 * V_2 -> V_55 ;
V_229 = V_230 + V_55 ;
F_46 ( L_5 ,
V_2 -> line , V_230 , V_229 ) ;
while ( ! V_2 -> V_10 -> V_151 ( V_2 ) ) {
F_93 ( F_55 ( V_228 ) ) ;
if ( F_81 ( V_145 ) )
break;
if ( F_96 ( V_230 , V_229 ) )
break;
}
}
static void F_97 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
unsigned long V_8 ;
F_46 ( L_6 , V_4 -> V_1 -> line ) ;
F_57 ( & V_2 -> V_115 ) ;
if ( V_2 -> V_8 & V_231 ) {
F_45 ( V_5 ) ;
F_24 ( V_5 , V_4 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_85 = 0 ;
F_23 ( V_224 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_92 ( V_2 , NULL ) ;
F_95 ( & V_2 -> V_226 ) ;
F_95 ( & V_2 -> V_168 ) ;
}
F_58 ( & V_2 -> V_115 ) ;
}
static int F_98 ( struct V_24 * V_2 , struct V_6 * V_5 )
{
return 0 ;
}
static void F_27 ( struct V_24 * V_2 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_95 ( & V_2 -> V_168 ) ;
V_23 -> V_10 -> V_232 ( V_23 ) ;
F_99 ( V_23 -> V_102 ) ;
}
static int F_100 ( struct V_24 * V_2 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
int V_20 ;
F_18 ( & V_23 -> V_9 ) ;
V_23 -> V_10 -> V_167 ( V_23 ) ;
V_20 = V_23 -> V_10 -> V_38 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
if ( V_20 & V_233 )
return 1 ;
return 0 ;
}
static void F_101 ( struct V_24 * V_2 , int V_234 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_234 )
F_16 ( V_23 , V_37 | V_36 ) ;
else
F_26 ( V_23 , V_37 | V_36 ) ;
}
static int F_102 ( struct V_6 * V_5 , struct V_218 * V_219 )
{
struct V_235 * V_236 = (struct V_235 * ) V_5 -> V_237 -> V_238 ;
int V_26 , line = V_5 -> V_88 ;
struct V_3 * V_4 = V_236 -> V_4 + line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_46 ( L_7 , line ) ;
if ( F_75 ( & V_2 -> V_115 ) ) {
V_26 = - V_156 ;
goto V_239;
}
V_2 -> V_85 ++ ;
if ( ! V_4 -> V_1 || V_4 -> V_1 -> V_8 & V_240 ) {
V_26 = - V_241 ;
goto V_242;
}
V_5 -> V_7 = V_4 ;
V_4 -> V_1 -> V_4 = V_4 ;
V_4 -> V_2 . V_142 =
( V_4 -> V_1 -> V_8 & V_143 ) ? 1 : 0 ;
F_92 ( V_2 , V_5 ) ;
if ( F_103 ( V_219 ) ) {
V_26 = - V_243 ;
goto V_242;
}
if ( V_2 -> V_85 == 1 )
F_94 ( V_4 , V_244 ) ;
V_26 = F_21 ( V_5 , V_4 , 0 ) ;
F_58 ( & V_2 -> V_115 ) ;
if ( V_26 == 0 )
V_26 = F_104 ( V_2 , V_5 , V_219 ) ;
V_239:
return V_26 ;
V_242:
V_2 -> V_85 -- ;
F_58 ( & V_2 -> V_115 ) ;
goto V_239;
}
static const char * F_105 ( struct V_1 * V_2 )
{
const char * V_245 = NULL ;
if ( V_2 -> V_10 -> type )
V_245 = V_2 -> V_10 -> type ( V_2 ) ;
if ( ! V_245 )
V_245 = L_8 ;
return V_245 ;
}
static void F_106 ( struct V_246 * V_247 , struct V_235 * V_236 , int V_248 )
{
struct V_3 * V_4 = V_236 -> V_4 + V_248 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
enum V_249 V_250 ;
struct V_1 * V_23 = V_4 -> V_1 ;
char V_251 [ 32 ] ;
unsigned int V_252 ;
int V_253 ;
if ( ! V_23 )
return;
V_253 = V_23 -> V_110 >= V_254 ;
F_107 ( V_247 , L_9 ,
V_23 -> line , F_105 ( V_23 ) ,
V_253 ? L_10 : L_11 ,
V_253 ? ( unsigned long long ) V_23 -> V_114
: ( unsigned long long ) V_23 -> V_99 ,
V_23 -> V_102 ) ;
if ( V_23 -> type == V_27 ) {
F_108 ( V_247 , '\n' ) ;
return;
}
if ( F_20 ( V_40 ) ) {
F_57 ( & V_2 -> V_115 ) ;
V_250 = V_4 -> V_250 ;
if ( V_250 != V_244 )
F_94 ( V_4 , V_244 ) ;
F_18 ( & V_23 -> V_9 ) ;
V_252 = V_23 -> V_10 -> V_38 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
if ( V_250 != V_244 )
F_94 ( V_4 , V_250 ) ;
F_58 ( & V_2 -> V_115 ) ;
F_107 ( V_247 , L_12 ,
V_23 -> V_166 . V_180 , V_23 -> V_166 . V_179 ) ;
if ( V_23 -> V_166 . V_181 )
F_107 ( V_247 , L_13 ,
V_23 -> V_166 . V_181 ) ;
if ( V_23 -> V_166 . V_183 )
F_107 ( V_247 , L_14 ,
V_23 -> V_166 . V_183 ) ;
if ( V_23 -> V_166 . V_184 )
F_107 ( V_247 , L_15 ,
V_23 -> V_166 . V_184 ) ;
if ( V_23 -> V_166 . V_182 )
F_107 ( V_247 , L_16 ,
V_23 -> V_166 . V_182 ) ;
#define F_109 ( T_4 , V_245 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_110 ( T_4 , V_245 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_251 [ 0 ] = '\0' ;
V_251 [ 1 ] = '\0' ;
F_109 ( V_36 , L_17 ) ;
F_110 ( V_39 , L_18 ) ;
F_109 ( V_37 , L_19 ) ;
F_110 ( V_172 , L_20 ) ;
F_110 ( V_233 , L_21 ) ;
F_110 ( V_170 , L_22 ) ;
if ( V_251 [ 0 ] )
V_251 [ 0 ] = ' ' ;
F_111 ( V_247 , V_251 ) ;
}
F_108 ( V_247 , '\n' ) ;
#undef F_110
#undef F_109
}
static int F_112 ( struct V_246 * V_247 , void * V_255 )
{
struct V_256 * V_257 = V_247 -> V_258 ;
struct V_235 * V_236 = V_257 -> V_238 ;
int V_248 ;
F_107 ( V_247 , L_23 ,
L_24 , L_24 , L_24 ) ;
for ( V_248 = 0 ; V_248 < V_236 -> V_259 ; V_248 ++ )
F_106 ( V_247 , V_236 , V_248 ) ;
return 0 ;
}
static int F_113 ( struct V_260 * V_260 , struct V_218 * V_218 )
{
return F_114 ( V_218 , F_112 , F_115 ( V_260 ) ) ;
}
void F_116 ( struct V_1 * V_2 , const char * V_261 ,
unsigned int V_85 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_248 ;
for ( V_248 = 0 ; V_248 < V_85 ; V_248 ++ , V_261 ++ ) {
if ( * V_261 == '\n' )
putchar ( V_2 , '\r' ) ;
putchar ( V_2 , * V_261 ) ;
}
}
struct V_1 * T_5
F_117 ( struct V_1 * V_262 , int V_259 , struct V_263 * V_264 )
{
int V_265 = V_264 -> V_88 ;
if ( V_265 < 0 || V_265 >= V_259 || ( V_262 [ V_265 ] . V_99 == 0 &&
V_262 [ V_265 ] . V_266 == NULL ) )
for ( V_265 = 0 ; V_265 < V_259 ; V_265 ++ )
if ( V_262 [ V_265 ] . V_99 != 0 ||
V_262 [ V_265 ] . V_266 != NULL )
break;
V_264 -> V_88 = V_265 ;
return V_262 + V_265 ;
}
void
F_118 ( char * V_267 , int * V_46 , int * V_183 , int * V_47 , int * V_268 )
{
char * V_261 = V_267 ;
* V_46 = F_119 ( V_261 , NULL , 10 ) ;
while ( * V_261 >= '0' && * V_261 <= '9' )
V_261 ++ ;
if ( * V_261 )
* V_183 = * V_261 ++ ;
if ( * V_261 )
* V_47 = * V_261 ++ - '0' ;
if ( * V_261 )
* V_268 = * V_261 ;
}
int
F_120 ( struct V_1 * V_2 , struct V_263 * V_264 ,
int V_46 , int V_183 , int V_47 , int V_268 )
{
struct V_57 V_33 ;
static struct V_57 V_269 ;
int V_248 ;
if ( ! ( F_14 ( V_2 ) && ( V_2 -> V_31 -> V_8 & V_270 ) ) ) {
F_121 ( & V_2 -> V_9 ) ;
F_122 ( & V_2 -> V_9 , & V_271 ) ;
}
memset ( & V_33 , 0 , sizeof( struct V_57 ) ) ;
V_33 . V_34 = V_272 | V_44 | V_75 ;
for ( V_248 = 0 ; V_273 [ V_248 ] . V_274 ; V_248 ++ )
if ( V_273 [ V_248 ] . V_274 <= V_46 )
break;
V_33 . V_34 |= V_273 [ V_248 ] . V_32 ;
if ( V_47 == 7 )
V_33 . V_34 |= V_51 ;
else
V_33 . V_34 |= V_275 ;
switch ( V_183 ) {
case 'o' : case 'O' :
V_33 . V_34 |= V_276 ;
case 'e' : case 'E' :
V_33 . V_34 |= V_53 ;
break;
}
if ( V_268 == 'r' )
V_33 . V_34 |= V_73 ;
V_2 -> V_20 |= V_37 ;
V_2 -> V_10 -> V_77 ( V_2 , & V_33 , & V_269 ) ;
if ( V_264 )
V_264 -> V_32 = V_33 . V_34 ;
return 0 ;
}
static void F_94 ( struct V_3 * V_4 ,
enum V_249 V_250 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
if ( V_4 -> V_250 != V_250 ) {
if ( V_2 -> V_10 -> V_277 )
V_2 -> V_10 -> V_277 ( V_2 , V_250 , V_4 -> V_250 ) ;
V_4 -> V_250 = V_250 ;
}
}
static int F_123 ( struct V_278 * V_279 , void * V_280 )
{
struct V_281 * V_282 = V_280 ;
struct V_256 * V_283 = V_282 -> V_237 -> V_256 ;
T_6 V_284 = F_124 ( V_283 -> V_285 , V_283 -> V_286 ) +
V_282 -> V_2 -> line ;
return V_279 -> V_284 == V_284 ;
}
int F_125 ( struct V_235 * V_236 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_236 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_278 * V_287 ;
struct V_281 V_282 = { V_23 , V_236 } ;
F_57 ( & V_2 -> V_115 ) ;
V_287 = F_126 ( V_23 -> V_279 , & V_282 , F_123 ) ;
if ( F_127 ( V_287 ) ) {
if ( ! F_128 ( V_23 -> V_102 ) )
V_23 -> V_288 = 1 ;
F_129 ( V_287 ) ;
F_58 ( & V_2 -> V_115 ) ;
return 0 ;
}
F_129 ( V_287 ) ;
if ( V_289 || ! F_14 ( V_23 ) )
V_23 -> V_290 = 1 ;
if ( V_2 -> V_8 & V_41 ) {
const struct V_291 * V_10 = V_23 -> V_10 ;
int V_292 ;
if ( V_289 || ! F_14 ( V_23 ) ) {
F_22 ( V_45 , & V_2 -> V_8 ) ;
F_23 ( V_43 , & V_2 -> V_8 ) ;
F_18 ( & V_23 -> V_9 ) ;
V_10 -> V_11 ( V_23 ) ;
V_10 -> V_21 ( V_23 , 0 ) ;
V_10 -> V_220 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
}
for ( V_292 = 3 ; ! V_10 -> V_151 ( V_23 ) && V_292 ; V_292 -- )
F_130 ( 10 ) ;
if ( ! V_292 )
F_65 ( V_293 L_25
L_26 ,
V_23 -> V_279 ? F_131 ( V_23 -> V_279 ) : L_24 ,
V_23 -> V_279 ? L_27 : L_24 ,
V_236 -> F_131 ,
V_236 -> V_256 -> V_294 + V_23 -> line ) ;
if ( V_289 || ! F_14 ( V_23 ) )
V_10 -> V_232 ( V_23 ) ;
}
if ( V_289 && F_14 ( V_23 ) )
F_132 ( V_23 -> V_31 ) ;
if ( V_289 || ! F_14 ( V_23 ) )
F_94 ( V_4 , V_223 ) ;
F_58 ( & V_2 -> V_115 ) ;
return 0 ;
}
int F_133 ( struct V_235 * V_236 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_236 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_278 * V_287 ;
struct V_281 V_282 = { V_23 , V_236 } ;
struct V_57 V_33 ;
F_57 ( & V_2 -> V_115 ) ;
V_287 = F_126 ( V_23 -> V_279 , & V_282 , F_123 ) ;
if ( ! V_23 -> V_290 && F_127 ( V_287 ) ) {
if ( V_23 -> V_288 ) {
F_134 ( V_23 -> V_102 ) ;
V_23 -> V_288 = 0 ;
}
F_129 ( V_287 ) ;
F_58 ( & V_2 -> V_115 ) ;
return 0 ;
}
F_129 ( V_287 ) ;
V_23 -> V_290 = 0 ;
if ( F_14 ( V_23 ) ) {
memset ( & V_33 , 0 , sizeof( struct V_57 ) ) ;
V_33 . V_34 = V_23 -> V_31 -> V_32 ;
if ( V_2 -> V_5 && V_33 . V_34 == 0 )
V_33 = V_2 -> V_5 -> V_33 ;
if ( V_289 )
F_94 ( V_4 , V_244 ) ;
V_23 -> V_10 -> V_77 ( V_23 , & V_33 , NULL ) ;
if ( V_289 )
F_135 ( V_23 -> V_31 ) ;
}
if ( V_2 -> V_8 & V_295 ) {
const struct V_291 * V_10 = V_23 -> V_10 ;
int V_81 ;
F_94 ( V_4 , V_244 ) ;
F_18 ( & V_23 -> V_9 ) ;
V_10 -> V_21 ( V_23 , 0 ) ;
F_19 ( & V_23 -> V_9 ) ;
if ( V_289 || ! F_14 ( V_23 ) ) {
struct V_6 * V_5 = V_2 -> V_5 ;
V_81 = V_10 -> V_30 ( V_23 ) ;
if ( V_81 == 0 ) {
if ( V_5 )
F_15 ( V_5 , V_4 , NULL ) ;
F_18 ( & V_23 -> V_9 ) ;
V_10 -> V_21 ( V_23 , V_23 -> V_20 ) ;
V_10 -> V_16 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
F_22 ( V_43 , & V_2 -> V_8 ) ;
} else {
F_24 ( V_5 , V_4 ) ;
}
}
F_23 ( V_45 , & V_2 -> V_8 ) ;
}
F_58 ( & V_2 -> V_115 ) ;
return 0 ;
}
static inline void
F_136 ( struct V_235 * V_236 , struct V_1 * V_2 )
{
char V_296 [ 64 ] ;
switch ( V_2 -> V_110 ) {
case V_297 :
snprintf ( V_296 , sizeof( V_296 ) , L_28 , V_2 -> V_99 ) ;
break;
case V_298 :
snprintf ( V_296 , sizeof( V_296 ) ,
L_29 , V_2 -> V_99 , V_2 -> V_108 ) ;
break;
case V_254 :
case V_299 :
case V_300 :
case V_301 :
snprintf ( V_296 , sizeof( V_296 ) ,
L_30 , ( unsigned long long ) V_2 -> V_114 ) ;
break;
default:
F_137 ( V_296 , L_31 , sizeof( V_296 ) ) ;
break;
}
F_65 ( V_302 L_32 ,
V_2 -> V_279 ? F_131 ( V_2 -> V_279 ) : L_24 ,
V_2 -> V_279 ? L_27 : L_24 ,
V_236 -> F_131 ,
V_236 -> V_256 -> V_294 + V_2 -> line ,
V_296 , V_2 -> V_102 , V_2 -> V_71 / 16 , F_105 ( V_2 ) ) ;
}
static void
F_138 ( struct V_235 * V_236 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
unsigned int V_8 ;
if ( ! V_2 -> V_99 && ! V_2 -> V_114 && ! V_2 -> V_266 )
return;
V_8 = 0 ;
if ( V_2 -> V_8 & V_158 )
V_8 |= V_159 ;
if ( V_2 -> V_8 & V_303 ) {
if ( ! ( V_2 -> V_8 & V_304 ) ) {
V_2 -> type = V_27 ;
V_8 |= V_157 ;
}
V_2 -> V_10 -> V_160 ( V_2 , V_8 ) ;
}
if ( V_2 -> type != V_27 ) {
unsigned long V_8 ;
F_136 ( V_236 , V_2 ) ;
F_94 ( V_4 , V_244 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_10 -> V_21 ( V_2 , V_2 -> V_20 & V_37 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_31 && ! ( V_2 -> V_31 -> V_8 & V_270 ) )
F_139 ( V_2 -> V_31 ) ;
if ( ! F_14 ( V_2 ) )
F_94 ( V_4 , V_223 ) ;
}
}
static int F_140 ( struct V_256 * V_237 , int line , char * V_267 )
{
struct V_235 * V_236 = V_237 -> V_238 ;
struct V_3 * V_4 = V_236 -> V_4 + line ;
struct V_1 * V_2 ;
int V_46 = 9600 ;
int V_47 = 8 ;
int V_183 = 'n' ;
int V_268 = 'n' ;
int V_81 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
if ( ! ( V_2 -> V_10 -> V_305 && V_2 -> V_10 -> V_306 ) )
return - 1 ;
if ( V_2 -> V_10 -> V_307 ) {
struct V_24 * V_308 = & V_4 -> V_2 ;
V_81 = 0 ;
F_57 ( & V_308 -> V_115 ) ;
if ( ! F_87 ( V_43 , & V_308 -> V_8 ) )
V_81 = V_2 -> V_10 -> V_307 ( V_2 ) ;
F_58 ( & V_308 -> V_115 ) ;
if ( V_81 )
return V_81 ;
}
if ( V_267 ) {
F_118 ( V_267 , & V_46 , & V_183 , & V_47 , & V_268 ) ;
return F_120 ( V_2 , NULL , V_46 , V_183 , V_47 , V_268 ) ;
}
return 0 ;
}
static int F_141 ( struct V_256 * V_237 , int line )
{
struct V_235 * V_236 = V_237 -> V_238 ;
struct V_3 * V_4 = V_236 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
return V_2 -> V_10 -> V_305 ( V_2 ) ;
}
static void F_142 ( struct V_256 * V_237 , int line , char V_84 )
{
struct V_235 * V_236 = V_237 -> V_238 ;
struct V_3 * V_4 = V_236 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return;
V_2 = V_4 -> V_1 ;
V_2 -> V_10 -> V_306 ( V_2 , V_84 ) ;
}
int F_143 ( struct V_235 * V_236 )
{
struct V_256 * V_309 ;
int V_248 , V_26 ;
F_2 ( V_236 -> V_4 ) ;
V_236 -> V_4 = F_144 ( sizeof( struct V_3 ) * V_236 -> V_259 , V_28 ) ;
if ( ! V_236 -> V_4 )
goto V_194;
V_309 = F_145 ( V_236 -> V_259 ) ;
if ( ! V_309 )
goto V_310;
V_236 -> V_256 = V_309 ;
V_309 -> V_311 = V_236 -> V_311 ;
V_309 -> V_312 = V_236 -> F_131 ;
V_309 -> V_285 = V_236 -> V_285 ;
V_309 -> V_286 = V_236 -> V_313 ;
V_309 -> type = V_314 ;
V_309 -> V_315 = V_316 ;
V_309 -> V_317 = V_318 ;
V_309 -> V_317 . V_34 = V_319 | V_275 | V_272 | V_44 | V_75 ;
V_309 -> V_317 . V_215 = V_309 -> V_317 . V_214 = 9600 ;
V_309 -> V_8 = V_320 | V_321 ;
V_309 -> V_238 = V_236 ;
F_146 ( V_309 , & V_291 ) ;
for ( V_248 = 0 ; V_248 < V_236 -> V_259 ; V_248 ++ ) {
struct V_3 * V_4 = V_236 -> V_4 + V_248 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_147 ( V_2 ) ;
V_2 -> V_10 = & V_322 ;
V_2 -> V_105 = V_56 / 2 ;
V_2 -> V_106 = 30 * V_56 ;
}
V_26 = F_148 ( V_309 ) ;
if ( V_26 >= 0 )
return V_26 ;
for ( V_248 = 0 ; V_248 < V_236 -> V_259 ; V_248 ++ )
F_149 ( & V_236 -> V_4 [ V_248 ] . V_2 ) ;
F_150 ( V_309 ) ;
V_310:
F_151 ( V_236 -> V_4 ) ;
V_194:
return - V_29 ;
}
void F_152 ( struct V_235 * V_236 )
{
struct V_256 * V_323 = V_236 -> V_256 ;
unsigned int V_248 ;
F_153 ( V_323 ) ;
F_150 ( V_323 ) ;
for ( V_248 = 0 ; V_248 < V_236 -> V_259 ; V_248 ++ )
F_149 ( & V_236 -> V_4 [ V_248 ] . V_2 ) ;
F_151 ( V_236 -> V_4 ) ;
V_236 -> V_4 = NULL ;
V_236 -> V_256 = NULL ;
}
struct V_256 * F_154 ( struct V_263 * V_264 , int * V_88 )
{
struct V_235 * V_323 = V_264 -> V_280 ;
* V_88 = V_264 -> V_88 ;
return V_323 -> V_256 ;
}
static T_7 F_155 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . V_104 * 16 ) ;
}
static T_7 F_157 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . type ) ;
}
static T_7 F_158 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . line ) ;
}
static T_7 F_159 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
unsigned long V_327 ;
F_56 ( V_2 , & V_116 ) ;
V_327 = V_116 . V_2 ;
if ( V_100 )
V_327 |= ( unsigned long ) V_116 . V_101 << V_100 ;
return snprintf ( V_13 , V_326 , L_34 , V_327 ) ;
}
static T_7 F_160 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . V_102 ) ;
}
static T_7 F_161 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_35 , V_116 . V_8 ) ;
}
static T_7 F_162 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . V_103 ) ;
}
static T_7 F_163 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . V_105 ) ;
}
static T_7 F_164 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . V_106 ) ;
}
static T_7 F_165 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . V_70 ) ;
}
static T_7 F_166 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . V_109 ) ;
}
static T_7 F_167 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_34 , ( unsigned long ) V_116 . V_113 ) ;
}
static T_7 F_168 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_13 )
{
struct V_97 V_116 ;
struct V_24 * V_2 = F_156 ( V_279 ) ;
F_56 ( V_2 , & V_116 ) ;
return snprintf ( V_13 , V_326 , L_33 , V_116 . V_111 ) ;
}
int F_169 ( struct V_235 * V_236 , struct V_1 * V_23 )
{
struct V_3 * V_4 ;
struct V_24 * V_2 ;
int V_81 = 0 ;
struct V_278 * V_287 ;
F_2 ( F_170 () ) ;
if ( V_23 -> line >= V_236 -> V_259 )
return - V_131 ;
V_4 = V_236 -> V_4 + V_23 -> line ;
V_2 = & V_4 -> V_2 ;
F_57 ( & V_328 ) ;
F_57 ( & V_2 -> V_115 ) ;
if ( V_4 -> V_1 ) {
V_81 = - V_131 ;
goto V_194;
}
V_4 -> V_1 = V_23 ;
V_4 -> V_250 = V_329 ;
V_23 -> V_31 = V_236 -> V_31 ;
V_23 -> V_4 = V_4 ;
if ( ! ( F_14 ( V_23 ) && ( V_23 -> V_31 -> V_8 & V_270 ) ) ) {
F_121 ( & V_23 -> V_9 ) ;
F_122 ( & V_23 -> V_9 , & V_271 ) ;
}
F_138 ( V_236 , V_4 , V_23 ) ;
V_287 = F_171 ( V_2 , V_236 -> V_256 ,
V_23 -> line , V_23 -> V_279 , V_2 , V_330 ) ;
if ( F_172 ( ! F_173 ( V_287 ) ) ) {
F_174 ( V_287 , 1 ) ;
} else {
F_65 ( V_293 L_36 ,
V_23 -> line ) ;
}
V_23 -> V_8 &= ~ V_240 ;
V_194:
F_58 ( & V_2 -> V_115 ) ;
F_58 ( & V_328 ) ;
return V_81 ;
}
int F_175 ( struct V_235 * V_236 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_236 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_81 = 0 ;
F_2 ( F_170 () ) ;
if ( V_4 -> V_1 != V_23 )
F_65 ( V_331 L_37 ,
V_4 -> V_1 , V_23 ) ;
F_57 ( & V_328 ) ;
F_57 ( & V_2 -> V_115 ) ;
if ( ! V_4 -> V_1 ) {
F_58 ( & V_2 -> V_115 ) ;
V_81 = - V_131 ;
goto V_194;
}
V_23 -> V_8 |= V_240 ;
F_58 ( & V_2 -> V_115 ) ;
F_176 ( V_236 -> V_256 , V_23 -> line ) ;
if ( V_2 -> V_5 )
F_177 ( V_2 -> V_5 ) ;
if ( V_23 -> type != V_27 )
V_23 -> V_10 -> V_139 ( V_23 ) ;
V_23 -> type = V_27 ;
V_4 -> V_1 = NULL ;
V_194:
F_58 ( & V_328 ) ;
return V_81 ;
}
int F_178 ( struct V_1 * V_332 , struct V_1 * V_333 )
{
if ( V_332 -> V_110 != V_333 -> V_110 )
return 0 ;
switch ( V_332 -> V_110 ) {
case V_297 :
return ( V_332 -> V_99 == V_333 -> V_99 ) ;
case V_298 :
return ( V_332 -> V_99 == V_333 -> V_99 ) &&
( V_332 -> V_108 == V_333 -> V_108 ) ;
case V_254 :
case V_299 :
case V_300 :
case V_301 :
return ( V_332 -> V_114 == V_333 -> V_114 ) ;
}
return 0 ;
}
void F_179 ( struct V_1 * V_23 , unsigned int V_252 )
{
struct V_24 * V_2 = & V_23 -> V_4 -> V_2 ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_334 * V_335 = V_5 ? F_180 ( V_5 ) : NULL ;
if ( V_335 ) {
if ( V_335 -> V_10 -> V_336 )
V_335 -> V_10 -> V_336 ( V_5 , V_252 ) ;
F_181 ( V_335 ) ;
}
V_23 -> V_166 . V_175 ++ ;
if ( V_2 -> V_8 & V_337 ) {
if ( V_252 )
F_95 ( & V_2 -> V_226 ) ;
else if ( V_5 )
F_182 ( V_5 ) ;
}
}
void F_183 ( struct V_1 * V_23 , unsigned int V_252 )
{
struct V_24 * V_2 = & V_23 -> V_4 -> V_2 ;
struct V_6 * V_5 = V_2 -> V_5 ;
V_23 -> V_166 . V_176 ++ ;
if ( F_17 ( V_2 ) ) {
if ( V_5 -> V_15 ) {
if ( V_252 ) {
V_5 -> V_15 = 0 ;
V_23 -> V_10 -> V_16 ( V_23 ) ;
F_1 ( V_23 ) ;
}
} else {
if ( ! V_252 ) {
V_5 -> V_15 = 1 ;
V_23 -> V_10 -> V_11 ( V_23 ) ;
}
}
}
}
void F_184 ( struct V_1 * V_2 , unsigned int V_252 ,
unsigned int V_182 , unsigned int V_84 , unsigned int V_338 )
{
struct V_24 * V_308 = & V_2 -> V_4 -> V_2 ;
if ( ( V_252 & V_2 -> V_339 & ~ V_182 ) == 0 )
if ( F_185 ( V_308 , V_84 , V_338 ) == 0 )
++ V_2 -> V_166 . V_185 ;
if ( V_252 & ~ V_2 -> V_339 & V_182 )
if ( F_185 ( V_308 , 0 , V_340 ) == 0 )
++ V_2 -> V_166 . V_185 ;
}
