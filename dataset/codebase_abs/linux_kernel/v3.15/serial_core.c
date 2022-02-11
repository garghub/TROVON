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
if ( ! V_5 -> V_12 && ! V_5 -> V_13 )
V_2 -> V_10 -> V_14 ( V_2 ) ;
}
static void F_8 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_8 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
F_7 ( V_5 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 , unsigned int V_15 , unsigned int V_16 )
{
unsigned long V_8 ;
unsigned int V_17 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_17 = V_2 -> V_18 ;
V_2 -> V_18 = ( V_17 & ~ V_16 ) | V_15 ;
if ( V_17 != V_2 -> V_18 )
V_2 -> V_10 -> V_19 ( V_2 , V_2 -> V_18 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
}
static int F_10 ( struct V_6 * V_5 , struct V_3 * V_4 ,
int V_20 )
{
struct V_1 * V_21 = V_4 -> V_1 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
unsigned long V_23 ;
int V_24 = 0 ;
if ( V_21 -> type == V_25 )
return 1 ;
F_11 ( V_4 , V_26 ) ;
if ( ! V_4 -> V_27 . V_28 ) {
V_23 = F_12 ( V_29 ) ;
if ( ! V_23 )
return - V_30 ;
V_4 -> V_27 . V_28 = ( unsigned char * ) V_23 ;
F_13 ( & V_4 -> V_27 ) ;
}
V_24 = V_21 -> V_10 -> V_31 ( V_21 ) ;
if ( V_24 == 0 ) {
if ( F_14 ( V_21 ) && V_21 -> V_32 -> V_33 ) {
V_5 -> V_34 . V_35 = V_21 -> V_32 -> V_33 ;
V_21 -> V_32 -> V_33 = 0 ;
}
F_15 ( V_5 , V_4 , NULL ) ;
if ( V_20 ) {
if ( V_5 -> V_34 . V_35 & V_36 )
F_16 ( V_21 , V_37 | V_38 ) ;
}
if ( F_17 ( V_2 ) ) {
F_18 ( & V_21 -> V_9 ) ;
if ( ! ( V_21 -> V_10 -> V_39 ( V_21 ) & V_40 ) )
V_5 -> V_13 = 1 ;
F_19 ( & V_21 -> V_9 ) ;
}
}
if ( V_24 && F_20 ( V_41 ) )
return 1 ;
return V_24 ;
}
static int F_21 ( struct V_6 * V_5 , struct V_3 * V_4 ,
int V_20 )
{
struct V_22 * V_2 = & V_4 -> V_2 ;
int V_24 ;
if ( V_2 -> V_8 & V_42 )
return 0 ;
F_22 ( V_43 , & V_5 -> V_8 ) ;
V_24 = F_10 ( V_5 , V_4 , V_20 ) ;
if ( ! V_24 ) {
F_22 ( V_44 , & V_2 -> V_8 ) ;
F_23 ( V_43 , & V_5 -> V_8 ) ;
} else if ( V_24 > 0 )
V_24 = 0 ;
return V_24 ;
}
static void F_24 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_21 = V_4 -> V_1 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
if ( V_5 )
F_22 ( V_43 , & V_5 -> V_8 ) ;
if ( F_25 ( V_44 , & V_2 -> V_8 ) ) {
if ( ! V_5 || ( V_5 -> V_34 . V_35 & V_45 ) )
F_26 ( V_21 , V_38 | V_37 ) ;
F_27 ( V_2 ) ;
}
F_23 ( V_46 , & V_2 -> V_8 ) ;
if ( V_4 -> V_27 . V_28 ) {
F_28 ( ( unsigned long ) V_4 -> V_27 . V_28 ) ;
V_4 -> V_27 . V_28 = NULL ;
}
}
void
F_29 ( struct V_1 * V_2 , unsigned int V_33 ,
unsigned int V_47 )
{
unsigned int V_48 ;
switch ( V_33 & V_49 ) {
case V_50 :
V_48 = 7 ;
break;
case V_51 :
V_48 = 8 ;
break;
case V_52 :
V_48 = 9 ;
break;
default:
V_48 = 10 ;
break;
}
if ( V_33 & V_53 )
V_48 ++ ;
if ( V_33 & V_54 )
V_48 ++ ;
V_48 = V_48 * V_2 -> V_55 ;
V_2 -> V_56 = ( V_57 * V_48 ) / V_47 + V_57 / 50 ;
}
unsigned int
F_30 ( struct V_1 * V_2 , struct V_58 * V_34 ,
struct V_58 * V_17 , unsigned int V_59 , unsigned int V_60 )
{
unsigned int V_61 , V_47 , V_62 = 38400 ;
int V_63 = 0 ;
T_1 V_8 = V_2 -> V_8 & V_64 ;
if ( V_8 == V_65 )
V_62 = 57600 ;
else if ( V_8 == V_66 )
V_62 = 115200 ;
else if ( V_8 == V_67 )
V_62 = 230400 ;
else if ( V_8 == V_68 )
V_62 = 460800 ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
V_47 = F_31 ( V_34 ) ;
if ( V_47 == 38400 )
V_47 = V_62 ;
if ( V_47 == 0 ) {
V_63 = 1 ;
V_47 = 9600 ;
}
if ( V_47 >= V_59 && V_47 <= V_60 )
return V_47 ;
V_34 -> V_35 &= ~ V_36 ;
if ( V_17 ) {
V_47 = F_31 ( V_17 ) ;
if ( ! V_63 )
F_32 ( V_34 ,
V_47 , V_47 ) ;
V_17 = NULL ;
continue;
}
if ( ! V_63 ) {
if ( V_47 <= V_59 )
F_32 ( V_34 ,
V_59 + 1 , V_59 + 1 ) ;
else
F_32 ( V_34 ,
V_60 - 1 , V_60 - 1 ) ;
}
}
F_33 ( 1 ) ;
return 0 ;
}
unsigned int
F_34 ( struct V_1 * V_2 , unsigned int V_47 )
{
unsigned int V_69 ;
if ( V_47 == 38400 && ( V_2 -> V_8 & V_64 ) == V_70 )
V_69 = V_2 -> V_71 ;
else
V_69 = F_35 ( V_2 -> V_72 , 16 * V_47 ) ;
return V_69 ;
}
static void F_15 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_58 * V_73 )
{
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_21 = V_4 -> V_1 ;
struct V_58 * V_34 ;
if ( ! V_5 || V_21 -> type == V_25 )
return;
V_34 = & V_5 -> V_34 ;
if ( V_34 -> V_35 & V_74 )
F_22 ( V_75 , & V_2 -> V_8 ) ;
else
F_23 ( V_75 , & V_2 -> V_8 ) ;
if ( V_34 -> V_35 & V_76 )
F_23 ( V_77 , & V_2 -> V_8 ) ;
else
F_22 ( V_77 , & V_2 -> V_8 ) ;
V_21 -> V_10 -> V_78 ( V_21 , V_34 , V_73 ) ;
}
static inline int F_36 ( struct V_1 * V_2 ,
struct V_79 * V_80 , unsigned char V_81 )
{
unsigned long V_8 ;
int V_82 = 0 ;
if ( ! V_80 -> V_28 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
if ( F_37 ( V_80 ) != 0 ) {
V_80 -> V_28 [ V_80 -> V_83 ] = V_81 ;
V_80 -> V_83 = ( V_80 -> V_83 + 1 ) & ( V_84 - 1 ) ;
V_82 = 1 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
return V_82 ;
}
static int F_38 ( struct V_6 * V_5 , unsigned char V_85 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
return F_36 ( V_4 -> V_1 , & V_4 -> V_27 , V_85 ) ;
}
static void F_39 ( struct V_6 * V_5 )
{
F_8 ( V_5 ) ;
}
static int F_40 ( struct V_6 * V_5 ,
const unsigned char * V_28 , int V_86 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 ;
struct V_79 * V_80 ;
unsigned long V_8 ;
int V_81 , V_82 = 0 ;
if ( ! V_4 ) {
F_33 ( 1 ) ;
return - V_87 ;
}
V_2 = V_4 -> V_1 ;
V_80 = & V_4 -> V_27 ;
if ( ! V_80 -> V_28 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
while ( 1 ) {
V_81 = F_41 ( V_80 -> V_83 , V_80 -> V_88 , V_84 ) ;
if ( V_86 < V_81 )
V_81 = V_86 ;
if ( V_81 <= 0 )
break;
memcpy ( V_80 -> V_28 + V_80 -> V_83 , V_28 , V_81 ) ;
V_80 -> V_83 = ( V_80 -> V_83 + V_81 ) & ( V_84 - 1 ) ;
V_28 += V_81 ;
V_86 -= V_81 ;
V_82 += V_81 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_8 ( V_5 ) ;
return V_82 ;
}
static int F_42 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_82 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_82 = F_37 ( & V_4 -> V_27 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_82 ;
}
static int F_43 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_82 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_82 = F_44 ( & V_4 -> V_27 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_82 ;
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
F_46 ( L_1 , V_5 -> V_89 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
F_13 ( & V_4 -> V_27 ) ;
if ( V_2 -> V_10 -> V_90 )
V_2 -> V_10 -> V_90 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_3 ( V_5 ) ;
}
static void F_47 ( struct V_6 * V_5 , char V_85 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_8 ;
if ( V_2 -> V_10 -> V_91 )
V_2 -> V_10 -> V_91 ( V_2 , V_85 ) ;
else {
V_2 -> V_92 = V_85 ;
if ( V_85 ) {
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_10 -> V_14 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
}
}
}
static void F_48 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
T_2 V_93 = 0 ;
if ( F_49 ( V_5 ) )
V_93 |= V_94 ;
if ( V_5 -> V_34 . V_35 & V_74 )
V_93 |= V_95 ;
if ( V_2 -> V_8 & V_93 ) {
V_2 -> V_10 -> V_96 ( V_2 ) ;
V_93 &= ~ V_2 -> V_8 ;
}
if ( V_93 & V_94 )
F_47 ( V_5 , F_50 ( V_5 ) ) ;
if ( V_93 & V_95 )
F_26 ( V_2 , V_37 ) ;
}
static void F_51 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
T_2 V_93 = 0 ;
if ( F_49 ( V_5 ) )
V_93 |= V_94 ;
if ( V_5 -> V_34 . V_35 & V_74 )
V_93 |= V_95 ;
if ( V_2 -> V_8 & V_93 ) {
V_2 -> V_10 -> V_97 ( V_2 ) ;
V_93 &= ~ V_2 -> V_8 ;
}
if ( V_93 & V_94 ) {
if ( V_2 -> V_92 )
V_2 -> V_92 = 0 ;
else
F_47 ( V_5 , F_52 ( V_5 ) ) ;
}
if ( V_93 & V_95 )
F_16 ( V_2 , V_37 ) ;
}
static void F_53 ( struct V_22 * V_2 ,
struct V_98 * V_99 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_21 = V_4 -> V_1 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> type = V_21 -> type ;
V_99 -> line = V_21 -> line ;
V_99 -> V_2 = V_21 -> V_100 ;
if ( V_101 )
V_99 -> V_102 = ( long ) V_21 -> V_100 >> V_101 ;
V_99 -> V_103 = V_21 -> V_103 ;
V_99 -> V_8 = V_21 -> V_8 ;
V_99 -> V_104 = V_21 -> V_55 ;
V_99 -> V_105 = V_21 -> V_72 / 16 ;
V_99 -> V_106 = F_55 ( V_2 -> V_106 ) / 10 ;
V_99 -> V_107 = V_2 -> V_107 == V_108 ?
V_108 :
F_55 ( V_2 -> V_107 ) / 10 ;
V_99 -> V_71 = V_21 -> V_71 ;
V_99 -> V_109 = V_21 -> V_109 ;
V_99 -> V_110 = V_21 -> V_111 ;
V_99 -> V_112 = V_21 -> V_113 ;
V_99 -> V_114 = ( void * ) ( unsigned long ) V_21 -> V_115 ;
}
static void F_56 ( struct V_22 * V_2 ,
struct V_98 * V_99 )
{
F_57 ( & V_2 -> V_116 ) ;
F_53 ( V_2 , V_99 ) ;
F_58 ( & V_2 -> V_116 ) ;
}
static int F_59 ( struct V_22 * V_2 ,
struct V_98 T_3 * V_99 )
{
struct V_98 V_117 ;
F_56 ( V_2 , & V_117 ) ;
if ( F_60 ( V_99 , & V_117 , sizeof( * V_99 ) ) )
return - V_118 ;
return 0 ;
}
static int F_61 ( struct V_6 * V_5 , struct V_22 * V_2 ,
struct V_3 * V_4 ,
struct V_98 * V_119 )
{
struct V_1 * V_21 = V_4 -> V_1 ;
unsigned long V_120 ;
unsigned int V_121 , V_122 , V_107 ;
unsigned int V_123 , V_106 ;
T_1 V_124 , V_125 ;
int V_24 = 0 ;
V_120 = V_119 -> V_2 ;
if ( V_101 )
V_120 += ( unsigned long ) V_119 -> V_102 << V_101 ;
V_119 -> V_103 = F_62 ( V_119 -> V_103 ) ;
V_106 = F_63 ( V_119 -> V_106 * 10 ) ;
V_107 = V_119 -> V_107 == V_108 ?
V_108 :
F_63 ( V_119 -> V_107 * 10 ) ;
V_121 = ! ( V_21 -> V_8 & V_126 )
&& V_119 -> V_103 != V_21 -> V_103 ;
V_122 = ! ( V_21 -> V_8 & V_126 )
&& ( V_120 != V_21 -> V_100 ||
( unsigned long ) V_119 -> V_114 != V_21 -> V_115 ||
V_119 -> V_109 != V_21 -> V_109 ||
V_119 -> V_110 != V_21 -> V_111 ||
V_119 -> V_112 != V_21 -> V_113 ||
V_119 -> type != V_21 -> type ) ;
V_124 = V_21 -> V_8 ;
V_125 = V_119 -> V_8 ;
V_123 = V_21 -> V_71 ;
if ( ! F_20 ( V_41 ) ) {
V_24 = - V_127 ;
if ( V_121 || V_122 ||
( V_119 -> V_105 != V_21 -> V_72 / 16 ) ||
( V_106 != V_2 -> V_106 ) ||
( V_107 != V_2 -> V_107 ) ||
( V_119 -> V_104 &&
V_119 -> V_104 != V_21 -> V_55 ) ||
( ( ( V_125 ^ V_124 ) & ~ V_128 ) != 0 ) )
goto exit;
V_21 -> V_8 = ( ( V_21 -> V_8 & ~ V_128 ) |
( V_125 & V_128 ) ) ;
V_21 -> V_71 = V_119 -> V_71 ;
goto V_129;
}
if ( V_21 -> V_10 -> V_130 )
V_24 = V_21 -> V_10 -> V_130 ( V_21 , V_119 ) ;
if ( ( V_119 -> V_103 >= V_131 ) || ( V_119 -> V_103 < 0 ) ||
( V_119 -> V_105 < 9600 ) )
V_24 = - V_132 ;
if ( V_24 )
goto exit;
if ( V_122 || V_121 ) {
V_24 = - V_133 ;
if ( F_64 ( V_2 ) > 1 )
goto exit;
F_24 ( V_5 , V_4 ) ;
}
if ( V_122 ) {
unsigned long V_134 , V_135 ;
unsigned int V_136 , V_137 , V_138 , V_139 ;
V_134 = V_21 -> V_100 ;
V_135 = V_21 -> V_115 ;
V_136 = V_21 -> type ;
V_138 = V_21 -> V_109 ;
V_137 = V_21 -> V_111 ;
V_139 = V_21 -> V_113 ;
if ( V_136 != V_25 )
V_21 -> V_10 -> V_140 ( V_21 ) ;
V_21 -> V_100 = V_120 ;
V_21 -> type = V_119 -> type ;
V_21 -> V_109 = V_119 -> V_109 ;
V_21 -> V_111 = V_119 -> V_110 ;
V_21 -> V_113 = V_119 -> V_112 ;
V_21 -> V_115 = ( unsigned long ) V_119 -> V_114 ;
if ( V_21 -> type != V_25 ) {
V_24 = V_21 -> V_10 -> V_141 ( V_21 ) ;
} else {
V_24 = 0 ;
}
if ( V_24 ) {
V_21 -> V_100 = V_134 ;
V_21 -> type = V_136 ;
V_21 -> V_109 = V_138 ;
V_21 -> V_111 = V_137 ;
V_21 -> V_113 = V_139 ;
V_21 -> V_115 = V_135 ;
if ( V_136 != V_25 ) {
V_24 = V_21 -> V_10 -> V_141 ( V_21 ) ;
if ( V_24 )
V_21 -> type = V_25 ;
V_24 = - V_133 ;
}
goto exit;
}
}
if ( V_121 )
V_21 -> V_103 = V_119 -> V_103 ;
if ( ! ( V_21 -> V_8 & V_126 ) )
V_21 -> V_72 = V_119 -> V_105 * 16 ;
V_21 -> V_8 = ( V_21 -> V_8 & ~ V_142 ) |
( V_125 & V_142 ) ;
V_21 -> V_71 = V_119 -> V_71 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_107 = V_107 ;
if ( V_119 -> V_104 )
V_21 -> V_55 = V_119 -> V_104 ;
V_2 -> V_143 = ( V_21 -> V_8 & V_144 ) ? 1 : 0 ;
V_129:
V_24 = 0 ;
if ( V_21 -> type == V_25 )
goto exit;
if ( V_2 -> V_8 & V_42 ) {
if ( ( ( V_124 ^ V_21 -> V_8 ) & V_64 ) ||
V_123 != V_21 -> V_71 ) {
if ( V_21 -> V_8 & V_64 ) {
char V_28 [ 64 ] ;
F_65 ( V_145
L_2
L_3 , V_146 -> V_147 ,
F_66 ( V_2 -> V_5 , V_28 ) ) ;
}
F_15 ( V_5 , V_4 , NULL ) ;
}
} else
V_24 = F_21 ( V_5 , V_4 , 1 ) ;
exit:
return V_24 ;
}
static int F_67 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_98 T_3 * V_148 )
{
struct V_98 V_149 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
int V_24 ;
if ( F_68 ( & V_149 , V_148 , sizeof( V_149 ) ) )
return - V_118 ;
F_57 ( & V_2 -> V_116 ) ;
V_24 = F_61 ( V_5 , V_2 , V_4 , & V_149 ) ;
F_58 ( & V_2 -> V_116 ) ;
return V_24 ;
}
static int F_69 ( struct V_6 * V_5 ,
struct V_3 * V_4 , unsigned int T_3 * V_150 )
{
struct V_1 * V_21 = V_4 -> V_1 ;
unsigned int V_151 ;
V_151 = V_21 -> V_10 -> V_152 ( V_21 ) ;
if ( V_21 -> V_92 ||
( ( F_44 ( & V_4 -> V_27 ) > 0 ) &&
! V_5 -> V_12 && ! V_5 -> V_13 ) )
V_151 &= ~ V_153 ;
return F_70 ( V_151 , V_150 ) ;
}
static int F_71 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_21 = V_4 -> V_1 ;
int V_151 = - V_154 ;
F_57 ( & V_2 -> V_116 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_43 ) ) ) {
V_151 = V_21 -> V_18 ;
F_18 ( & V_21 -> V_9 ) ;
V_151 |= V_21 -> V_10 -> V_39 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
}
F_58 ( & V_2 -> V_116 ) ;
return V_151 ;
}
static int
F_72 ( struct V_6 * V_5 , unsigned int V_15 , unsigned int V_16 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_21 = V_4 -> V_1 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
int V_82 = - V_154 ;
F_57 ( & V_2 -> V_116 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_43 ) ) ) {
F_9 ( V_21 , V_15 , V_16 ) ;
V_82 = 0 ;
}
F_58 ( & V_2 -> V_116 ) ;
return V_82 ;
}
static int F_73 ( struct V_6 * V_5 , int V_155 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_21 = V_4 -> V_1 ;
F_57 ( & V_2 -> V_116 ) ;
if ( V_21 -> type != V_25 )
V_21 -> V_10 -> V_156 ( V_21 , V_155 ) ;
F_58 ( & V_2 -> V_116 ) ;
return 0 ;
}
static int F_74 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_21 = V_4 -> V_1 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
int V_8 , V_82 ;
if ( ! F_20 ( V_41 ) )
return - V_127 ;
if ( F_75 ( & V_2 -> V_116 ) )
return - V_157 ;
V_82 = - V_133 ;
if ( F_64 ( V_2 ) == 1 ) {
F_24 ( V_5 , V_4 ) ;
if ( V_21 -> type != V_25 )
V_21 -> V_10 -> V_140 ( V_21 ) ;
V_8 = V_158 ;
if ( V_21 -> V_8 & V_159 )
V_8 |= V_160 ;
V_21 -> V_10 -> V_161 ( V_21 , V_8 ) ;
V_82 = F_21 ( V_5 , V_4 , 1 ) ;
}
F_58 ( & V_2 -> V_116 ) ;
return V_82 ;
}
static int
F_76 ( struct V_3 * V_4 , unsigned long V_162 )
{
struct V_1 * V_21 = V_4 -> V_1 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
F_77 ( V_163 , V_146 ) ;
struct V_164 V_165 , V_166 ;
int V_82 ;
F_18 ( & V_21 -> V_9 ) ;
memcpy ( & V_165 , & V_21 -> V_167 , sizeof( struct V_164 ) ) ;
V_21 -> V_10 -> V_168 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
F_78 ( & V_2 -> V_169 , & V_163 ) ;
for (; ; ) {
F_18 ( & V_21 -> V_9 ) ;
memcpy ( & V_166 , & V_21 -> V_167 , sizeof( struct V_164 ) ) ;
F_19 ( & V_21 -> V_9 ) ;
F_79 ( V_170 ) ;
if ( ( ( V_162 & V_171 ) && ( V_166 . V_172 != V_165 . V_172 ) ) ||
( ( V_162 & V_173 ) && ( V_166 . V_174 != V_165 . V_174 ) ) ||
( ( V_162 & V_175 ) && ( V_166 . V_176 != V_165 . V_176 ) ) ||
( ( V_162 & V_40 ) && ( V_166 . V_177 != V_165 . V_177 ) ) ) {
V_82 = 0 ;
break;
}
F_80 () ;
if ( F_81 ( V_146 ) ) {
V_82 = - V_157 ;
break;
}
V_165 = V_166 ;
}
V_146 -> V_4 = V_178 ;
F_82 ( & V_2 -> V_169 , & V_163 ) ;
return V_82 ;
}
static int F_83 ( struct V_6 * V_5 ,
struct V_179 * V_167 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_164 V_166 ;
struct V_1 * V_21 = V_4 -> V_1 ;
F_18 ( & V_21 -> V_9 ) ;
memcpy ( & V_166 , & V_21 -> V_167 , sizeof( struct V_164 ) ) ;
F_19 ( & V_21 -> V_9 ) ;
V_167 -> V_177 = V_166 . V_177 ;
V_167 -> V_174 = V_166 . V_174 ;
V_167 -> V_172 = V_166 . V_172 ;
V_167 -> V_176 = V_166 . V_176 ;
V_167 -> V_180 = V_166 . V_180 ;
V_167 -> V_181 = V_166 . V_181 ;
V_167 -> V_182 = V_166 . V_182 ;
V_167 -> V_183 = V_166 . V_183 ;
V_167 -> V_184 = V_166 . V_184 ;
V_167 -> V_185 = V_166 . V_185 ;
V_167 -> V_186 = V_166 . V_186 ;
return 0 ;
}
static int
F_84 ( struct V_6 * V_5 , unsigned int V_187 ,
unsigned long V_162 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
void T_3 * V_188 = ( void T_3 * ) V_162 ;
int V_82 = - V_189 ;
switch ( V_187 ) {
case V_190 :
V_82 = F_59 ( V_2 , V_188 ) ;
break;
case V_191 :
V_82 = F_67 ( V_5 , V_4 , V_188 ) ;
break;
case V_192 :
V_82 = F_74 ( V_5 , V_4 ) ;
break;
case V_193 :
case V_194 :
V_82 = 0 ;
break;
}
if ( V_82 != - V_189 )
goto V_195;
if ( V_5 -> V_8 & ( 1 << V_43 ) ) {
V_82 = - V_154 ;
goto V_195;
}
switch ( V_187 ) {
case V_196 :
V_82 = F_76 ( V_4 , V_162 ) ;
break;
}
if ( V_82 != - V_189 )
goto V_195;
F_57 ( & V_2 -> V_116 ) ;
if ( V_5 -> V_8 & ( 1 << V_43 ) ) {
V_82 = - V_154 ;
goto V_197;
}
switch ( V_187 ) {
case V_198 :
V_82 = F_69 ( V_5 , V_4 , V_188 ) ;
break;
default: {
struct V_1 * V_21 = V_4 -> V_1 ;
if ( V_21 -> V_10 -> V_199 )
V_82 = V_21 -> V_10 -> V_199 ( V_21 , V_187 , V_162 ) ;
break;
}
}
V_197:
F_58 ( & V_2 -> V_116 ) ;
V_195:
return V_82 ;
}
static void F_85 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_21 = V_4 -> V_1 ;
if ( V_21 -> V_10 -> V_200 )
V_21 -> V_10 -> V_200 ( V_21 , V_5 -> V_34 . V_201 ) ;
}
static void F_86 ( struct V_6 * V_5 ,
struct V_58 * V_73 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_21 = V_4 -> V_1 ;
unsigned long V_8 ;
unsigned int V_33 = V_5 -> V_34 . V_35 ;
unsigned int V_202 = V_203 | V_204 | V_205 | V_206 | V_207 ;
bool V_208 = false ;
if ( V_21 -> V_8 & V_94 ) {
V_202 |= V_209 | V_210 | V_211 ;
V_208 =
V_5 -> V_34 . V_212 [ V_213 ] != V_73 -> V_212 [ V_213 ] ||
V_5 -> V_34 . V_212 [ V_214 ] != V_73 -> V_212 [ V_214 ] ;
}
if ( ( V_33 ^ V_73 -> V_35 ) == 0 &&
V_5 -> V_34 . V_215 == V_73 -> V_215 &&
V_5 -> V_34 . V_216 == V_73 -> V_216 &&
( ( V_5 -> V_34 . V_217 ^ V_73 -> V_217 ) & V_202 ) == 0 &&
! V_208 ) {
return;
}
F_15 ( V_5 , V_4 , V_73 ) ;
if ( ( V_73 -> V_35 & V_36 ) && ! ( V_33 & V_36 ) )
F_26 ( V_21 , V_37 | V_38 ) ;
else if ( ! ( V_73 -> V_35 & V_36 ) && ( V_33 & V_36 ) ) {
unsigned int V_93 = V_38 ;
if ( ! ( V_33 & V_74 ) ||
! F_87 ( V_218 , & V_5 -> V_8 ) )
V_93 |= V_37 ;
F_16 ( V_21 , V_93 ) ;
}
if ( V_21 -> V_8 & V_95 )
return;
if ( ( V_73 -> V_35 & V_74 ) && ! ( V_33 & V_74 ) ) {
F_5 ( & V_21 -> V_9 , V_8 ) ;
V_5 -> V_13 = 0 ;
F_7 ( V_5 ) ;
F_6 ( & V_21 -> V_9 , V_8 ) ;
}
else if ( ! ( V_73 -> V_35 & V_74 ) && ( V_33 & V_74 ) ) {
F_5 ( & V_21 -> V_9 , V_8 ) ;
if ( ! ( V_21 -> V_10 -> V_39 ( V_21 ) & V_40 ) ) {
V_5 -> V_13 = 1 ;
V_21 -> V_10 -> V_11 ( V_21 ) ;
}
F_6 ( & V_21 -> V_9 , V_8 ) ;
}
}
static void F_88 ( struct V_6 * V_5 , struct V_219 * V_220 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_22 * V_2 ;
struct V_1 * V_21 ;
unsigned long V_8 ;
if ( ! V_4 )
return;
V_21 = V_4 -> V_1 ;
V_2 = & V_4 -> V_2 ;
F_46 ( L_4 , V_21 ? V_21 -> line : - 1 ) ;
if ( ! V_2 -> V_86 || F_89 ( V_2 , V_5 , V_220 ) == 0 )
return;
if ( V_2 -> V_8 & V_42 ) {
unsigned long V_8 ;
F_5 ( & V_21 -> V_9 , V_8 ) ;
V_21 -> V_10 -> V_221 ( V_21 ) ;
F_6 ( & V_21 -> V_9 , V_8 ) ;
F_90 ( V_5 , V_21 -> V_56 ) ;
}
F_57 ( & V_2 -> V_116 ) ;
F_24 ( V_5 , V_4 ) ;
F_45 ( V_5 ) ;
F_91 ( V_5 ) ;
F_92 ( V_2 , NULL ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_5 -> V_222 = 0 ;
if ( V_2 -> V_223 ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_106 )
F_93 (
F_55 ( V_2 -> V_106 ) ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
} else if ( ! F_14 ( V_21 ) ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_11 ( V_4 , V_224 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
}
F_23 ( V_225 , & V_2 -> V_8 ) ;
F_23 ( V_226 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_94 ( & V_2 -> V_227 ) ;
F_94 ( & V_2 -> V_228 ) ;
F_58 ( & V_2 -> V_116 ) ;
}
static void F_90 ( struct V_6 * V_5 , int V_56 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_229 , V_230 ;
if ( V_2 -> type == V_25 || V_2 -> V_55 == 0 )
return;
V_229 = ( V_2 -> V_56 - V_57 / 50 ) / V_2 -> V_55 ;
V_229 = V_229 / 5 ;
if ( V_229 == 0 )
V_229 = 1 ;
if ( V_56 && V_56 < V_229 )
V_229 = V_56 ;
if ( V_56 == 0 || V_56 > 2 * V_2 -> V_56 )
V_56 = 2 * V_2 -> V_56 ;
V_230 = V_231 + V_56 ;
F_46 ( L_5 ,
V_2 -> line , V_231 , V_230 ) ;
while ( ! V_2 -> V_10 -> V_152 ( V_2 ) ) {
F_93 ( F_55 ( V_229 ) ) ;
if ( F_81 ( V_146 ) )
break;
if ( F_95 ( V_231 , V_230 ) )
break;
}
}
static void F_96 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
unsigned long V_8 ;
F_46 ( L_6 , V_4 -> V_1 -> line ) ;
F_57 ( & V_2 -> V_116 ) ;
if ( V_2 -> V_8 & V_232 ) {
F_45 ( V_5 ) ;
F_24 ( V_5 , V_4 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_86 = 0 ;
F_23 ( V_225 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_92 ( V_2 , NULL ) ;
if ( ! F_14 ( V_4 -> V_1 ) )
F_11 ( V_4 , V_224 ) ;
F_94 ( & V_2 -> V_227 ) ;
F_94 ( & V_2 -> V_169 ) ;
}
F_58 ( & V_2 -> V_116 ) ;
}
static int F_97 ( struct V_22 * V_2 , struct V_6 * V_5 )
{
return 0 ;
}
static void F_27 ( struct V_22 * V_2 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_21 = V_4 -> V_1 ;
F_94 ( & V_2 -> V_169 ) ;
V_21 -> V_10 -> V_233 ( V_21 ) ;
F_98 ( V_21 -> V_103 ) ;
}
static int F_99 ( struct V_22 * V_2 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_21 = V_4 -> V_1 ;
int V_18 ;
F_18 ( & V_21 -> V_9 ) ;
V_21 -> V_10 -> V_168 ( V_21 ) ;
V_18 = V_21 -> V_10 -> V_39 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
if ( V_18 & V_234 )
return 1 ;
return 0 ;
}
static void F_100 ( struct V_22 * V_2 , int V_235 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_21 = V_4 -> V_1 ;
if ( V_235 )
F_16 ( V_21 , V_38 | V_37 ) ;
else
F_26 ( V_21 , V_38 | V_37 ) ;
}
static int F_101 ( struct V_6 * V_5 , struct V_219 * V_220 )
{
struct V_236 * V_237 = (struct V_236 * ) V_5 -> V_238 -> V_239 ;
int V_24 , line = V_5 -> V_89 ;
struct V_3 * V_4 = V_237 -> V_4 + line ;
struct V_22 * V_2 = & V_4 -> V_2 ;
F_46 ( L_7 , line ) ;
if ( F_75 ( & V_2 -> V_116 ) ) {
V_24 = - V_157 ;
goto V_240;
}
V_2 -> V_86 ++ ;
if ( ! V_4 -> V_1 || V_4 -> V_1 -> V_8 & V_241 ) {
V_24 = - V_242 ;
goto V_243;
}
V_5 -> V_7 = V_4 ;
V_4 -> V_1 -> V_4 = V_4 ;
V_4 -> V_2 . V_143 =
( V_4 -> V_1 -> V_8 & V_144 ) ? 1 : 0 ;
F_92 ( V_2 , V_5 ) ;
if ( F_102 ( V_220 ) ) {
V_24 = - V_244 ;
goto V_243;
}
V_24 = F_21 ( V_5 , V_4 , 0 ) ;
F_58 ( & V_2 -> V_116 ) ;
if ( V_24 == 0 )
V_24 = F_103 ( V_2 , V_5 , V_220 ) ;
V_240:
return V_24 ;
V_243:
V_2 -> V_86 -- ;
F_58 ( & V_2 -> V_116 ) ;
goto V_240;
}
static const char * F_104 ( struct V_1 * V_2 )
{
const char * V_245 = NULL ;
if ( V_2 -> V_10 -> type )
V_245 = V_2 -> V_10 -> type ( V_2 ) ;
if ( ! V_245 )
V_245 = L_8 ;
return V_245 ;
}
static void F_105 ( struct V_246 * V_247 , struct V_236 * V_237 , int V_248 )
{
struct V_3 * V_4 = V_237 -> V_4 + V_248 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
enum V_249 V_250 ;
struct V_1 * V_21 = V_4 -> V_1 ;
char V_251 [ 32 ] ;
unsigned int V_252 ;
int V_253 ;
if ( ! V_21 )
return;
V_253 = V_21 -> V_111 >= V_254 ;
F_106 ( V_247 , L_9 ,
V_21 -> line , F_104 ( V_21 ) ,
V_253 ? L_10 : L_11 ,
V_253 ? ( unsigned long long ) V_21 -> V_115
: ( unsigned long long ) V_21 -> V_100 ,
V_21 -> V_103 ) ;
if ( V_21 -> type == V_25 ) {
F_107 ( V_247 , '\n' ) ;
return;
}
if ( F_20 ( V_41 ) ) {
F_57 ( & V_2 -> V_116 ) ;
V_250 = V_4 -> V_250 ;
if ( V_250 != V_26 )
F_11 ( V_4 , V_26 ) ;
F_18 ( & V_21 -> V_9 ) ;
V_252 = V_21 -> V_10 -> V_39 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
if ( V_250 != V_26 )
F_11 ( V_4 , V_250 ) ;
F_58 ( & V_2 -> V_116 ) ;
F_106 ( V_247 , L_12 ,
V_21 -> V_167 . V_181 , V_21 -> V_167 . V_180 ) ;
if ( V_21 -> V_167 . V_182 )
F_106 ( V_247 , L_13 ,
V_21 -> V_167 . V_182 ) ;
if ( V_21 -> V_167 . V_184 )
F_106 ( V_247 , L_14 ,
V_21 -> V_167 . V_184 ) ;
if ( V_21 -> V_167 . V_185 )
F_106 ( V_247 , L_15 ,
V_21 -> V_167 . V_185 ) ;
if ( V_21 -> V_167 . V_183 )
F_106 ( V_247 , L_16 ,
V_21 -> V_167 . V_183 ) ;
#define F_108 ( T_4 , V_245 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_109 ( T_4 , V_245 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_251 [ 0 ] = '\0' ;
V_251 [ 1 ] = '\0' ;
F_108 ( V_37 , L_17 ) ;
F_109 ( V_40 , L_18 ) ;
F_108 ( V_38 , L_19 ) ;
F_109 ( V_173 , L_20 ) ;
F_109 ( V_234 , L_21 ) ;
F_109 ( V_171 , L_22 ) ;
if ( V_251 [ 0 ] )
V_251 [ 0 ] = ' ' ;
F_110 ( V_247 , V_251 ) ;
}
F_107 ( V_247 , '\n' ) ;
#undef F_109
#undef F_108
}
static int F_111 ( struct V_246 * V_247 , void * V_255 )
{
struct V_256 * V_257 = V_247 -> V_258 ;
struct V_236 * V_237 = V_257 -> V_239 ;
int V_248 ;
F_106 ( V_247 , L_23 ,
L_24 , L_24 , L_24 ) ;
for ( V_248 = 0 ; V_248 < V_237 -> V_259 ; V_248 ++ )
F_105 ( V_247 , V_237 , V_248 ) ;
return 0 ;
}
static int F_112 ( struct V_260 * V_260 , struct V_219 * V_219 )
{
return F_113 ( V_219 , F_111 , F_114 ( V_260 ) ) ;
}
void F_115 ( struct V_1 * V_2 , const char * V_261 ,
unsigned int V_86 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_248 ;
for ( V_248 = 0 ; V_248 < V_86 ; V_248 ++ , V_261 ++ ) {
if ( * V_261 == '\n' )
putchar ( V_2 , '\r' ) ;
putchar ( V_2 , * V_261 ) ;
}
}
struct V_1 * T_5
F_116 ( struct V_1 * V_262 , int V_259 , struct V_263 * V_264 )
{
int V_265 = V_264 -> V_89 ;
if ( V_265 < 0 || V_265 >= V_259 || ( V_262 [ V_265 ] . V_100 == 0 &&
V_262 [ V_265 ] . V_266 == NULL ) )
for ( V_265 = 0 ; V_265 < V_259 ; V_265 ++ )
if ( V_262 [ V_265 ] . V_100 != 0 ||
V_262 [ V_265 ] . V_266 != NULL )
break;
V_264 -> V_89 = V_265 ;
return V_262 + V_265 ;
}
void
F_117 ( char * V_267 , int * V_47 , int * V_184 , int * V_48 , int * V_268 )
{
char * V_261 = V_267 ;
* V_47 = F_118 ( V_261 , NULL , 10 ) ;
while ( * V_261 >= '0' && * V_261 <= '9' )
V_261 ++ ;
if ( * V_261 )
* V_184 = * V_261 ++ ;
if ( * V_261 )
* V_48 = * V_261 ++ - '0' ;
if ( * V_261 )
* V_268 = * V_261 ;
}
int
F_119 ( struct V_1 * V_2 , struct V_263 * V_264 ,
int V_47 , int V_184 , int V_48 , int V_268 )
{
struct V_58 V_34 ;
static struct V_58 V_269 ;
int V_248 ;
if ( ! ( F_14 ( V_2 ) && ( V_2 -> V_32 -> V_8 & V_270 ) ) ) {
F_120 ( & V_2 -> V_9 ) ;
F_121 ( & V_2 -> V_9 , & V_271 ) ;
}
memset ( & V_34 , 0 , sizeof( struct V_58 ) ) ;
V_34 . V_35 = V_272 | V_45 | V_76 ;
for ( V_248 = 0 ; V_273 [ V_248 ] . V_274 ; V_248 ++ )
if ( V_273 [ V_248 ] . V_274 <= V_47 )
break;
V_34 . V_35 |= V_273 [ V_248 ] . V_33 ;
if ( V_48 == 7 )
V_34 . V_35 |= V_52 ;
else
V_34 . V_35 |= V_275 ;
switch ( V_184 ) {
case 'o' : case 'O' :
V_34 . V_35 |= V_276 ;
case 'e' : case 'E' :
V_34 . V_35 |= V_54 ;
break;
}
if ( V_268 == 'r' )
V_34 . V_35 |= V_74 ;
V_2 -> V_18 |= V_38 ;
V_2 -> V_10 -> V_78 ( V_2 , & V_34 , & V_269 ) ;
if ( V_264 )
V_264 -> V_33 = V_34 . V_35 ;
return 0 ;
}
static void F_11 ( struct V_3 * V_4 ,
enum V_249 V_250 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
if ( V_4 -> V_250 != V_250 ) {
if ( V_2 -> V_10 -> V_277 )
V_2 -> V_10 -> V_277 ( V_2 , V_250 , V_4 -> V_250 ) ;
V_4 -> V_250 = V_250 ;
}
}
static int F_122 ( struct V_278 * V_279 , void * V_280 )
{
struct V_281 * V_282 = V_280 ;
struct V_256 * V_283 = V_282 -> V_238 -> V_256 ;
T_6 V_284 = F_123 ( V_283 -> V_285 , V_283 -> V_286 ) +
V_282 -> V_2 -> line ;
return V_279 -> V_284 == V_284 ;
}
int F_124 ( struct V_236 * V_237 , struct V_1 * V_21 )
{
struct V_3 * V_4 = V_237 -> V_4 + V_21 -> line ;
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_278 * V_287 ;
struct V_281 V_282 = { V_21 , V_237 } ;
F_57 ( & V_2 -> V_116 ) ;
V_287 = F_125 ( V_21 -> V_279 , & V_282 , F_122 ) ;
if ( F_126 ( V_287 ) ) {
if ( ! F_127 ( V_21 -> V_103 ) )
V_21 -> V_288 = 1 ;
F_128 ( V_287 ) ;
F_58 ( & V_2 -> V_116 ) ;
return 0 ;
}
F_128 ( V_287 ) ;
if ( V_289 || ! F_14 ( V_21 ) )
V_21 -> V_290 = 1 ;
if ( V_2 -> V_8 & V_42 ) {
const struct V_291 * V_10 = V_21 -> V_10 ;
int V_292 ;
if ( V_289 || ! F_14 ( V_21 ) ) {
F_22 ( V_46 , & V_2 -> V_8 ) ;
F_23 ( V_44 , & V_2 -> V_8 ) ;
F_18 ( & V_21 -> V_9 ) ;
V_10 -> V_11 ( V_21 ) ;
V_10 -> V_19 ( V_21 , 0 ) ;
V_10 -> V_221 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
}
for ( V_292 = 3 ; ! V_10 -> V_152 ( V_21 ) && V_292 ; V_292 -- )
F_129 ( 10 ) ;
if ( ! V_292 )
F_65 ( V_293 L_25
L_26 ,
V_21 -> V_279 ? F_130 ( V_21 -> V_279 ) : L_24 ,
V_21 -> V_279 ? L_27 : L_24 ,
V_237 -> F_130 ,
V_237 -> V_256 -> V_294 + V_21 -> line ) ;
if ( V_289 || ! F_14 ( V_21 ) )
V_10 -> V_233 ( V_21 ) ;
}
if ( V_289 && F_14 ( V_21 ) )
F_131 ( V_21 -> V_32 ) ;
if ( V_289 || ! F_14 ( V_21 ) )
F_11 ( V_4 , V_224 ) ;
F_58 ( & V_2 -> V_116 ) ;
return 0 ;
}
int F_132 ( struct V_236 * V_237 , struct V_1 * V_21 )
{
struct V_3 * V_4 = V_237 -> V_4 + V_21 -> line ;
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_278 * V_287 ;
struct V_281 V_282 = { V_21 , V_237 } ;
struct V_58 V_34 ;
F_57 ( & V_2 -> V_116 ) ;
V_287 = F_125 ( V_21 -> V_279 , & V_282 , F_122 ) ;
if ( ! V_21 -> V_290 && F_126 ( V_287 ) ) {
if ( V_21 -> V_288 ) {
F_133 ( V_21 -> V_103 ) ;
V_21 -> V_288 = 0 ;
}
F_128 ( V_287 ) ;
F_58 ( & V_2 -> V_116 ) ;
return 0 ;
}
F_128 ( V_287 ) ;
V_21 -> V_290 = 0 ;
if ( F_14 ( V_21 ) ) {
memset ( & V_34 , 0 , sizeof( struct V_58 ) ) ;
V_34 . V_35 = V_21 -> V_32 -> V_33 ;
if ( V_2 -> V_5 && V_34 . V_35 == 0 )
V_34 = V_2 -> V_5 -> V_34 ;
if ( V_289 )
F_11 ( V_4 , V_26 ) ;
V_21 -> V_10 -> V_78 ( V_21 , & V_34 , NULL ) ;
if ( V_289 )
F_134 ( V_21 -> V_32 ) ;
}
if ( V_2 -> V_8 & V_295 ) {
const struct V_291 * V_10 = V_21 -> V_10 ;
int V_82 ;
F_11 ( V_4 , V_26 ) ;
F_18 ( & V_21 -> V_9 ) ;
V_10 -> V_19 ( V_21 , 0 ) ;
F_19 ( & V_21 -> V_9 ) ;
if ( V_289 || ! F_14 ( V_21 ) ) {
struct V_6 * V_5 = V_2 -> V_5 ;
V_82 = V_10 -> V_31 ( V_21 ) ;
if ( V_82 == 0 ) {
if ( V_5 )
F_15 ( V_5 , V_4 , NULL ) ;
F_18 ( & V_21 -> V_9 ) ;
V_10 -> V_19 ( V_21 , V_21 -> V_18 ) ;
V_10 -> V_14 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
F_22 ( V_44 , & V_2 -> V_8 ) ;
} else {
F_24 ( V_5 , V_4 ) ;
}
}
F_23 ( V_46 , & V_2 -> V_8 ) ;
}
F_58 ( & V_2 -> V_116 ) ;
return 0 ;
}
static inline void
F_135 ( struct V_236 * V_237 , struct V_1 * V_2 )
{
char V_296 [ 64 ] ;
switch ( V_2 -> V_111 ) {
case V_297 :
snprintf ( V_296 , sizeof( V_296 ) , L_28 , V_2 -> V_100 ) ;
break;
case V_298 :
snprintf ( V_296 , sizeof( V_296 ) ,
L_29 , V_2 -> V_100 , V_2 -> V_109 ) ;
break;
case V_254 :
case V_299 :
case V_300 :
case V_301 :
snprintf ( V_296 , sizeof( V_296 ) ,
L_30 , ( unsigned long long ) V_2 -> V_115 ) ;
break;
default:
F_136 ( V_296 , L_31 , sizeof( V_296 ) ) ;
break;
}
F_65 ( V_302 L_32 ,
V_2 -> V_279 ? F_130 ( V_2 -> V_279 ) : L_24 ,
V_2 -> V_279 ? L_27 : L_24 ,
V_237 -> F_130 ,
V_237 -> V_256 -> V_294 + V_2 -> line ,
V_296 , V_2 -> V_103 , V_2 -> V_72 / 16 , F_104 ( V_2 ) ) ;
}
static void
F_137 ( struct V_236 * V_237 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
unsigned int V_8 ;
if ( ! V_2 -> V_100 && ! V_2 -> V_115 && ! V_2 -> V_266 )
return;
V_8 = 0 ;
if ( V_2 -> V_8 & V_159 )
V_8 |= V_160 ;
if ( V_2 -> V_8 & V_303 ) {
if ( ! ( V_2 -> V_8 & V_304 ) ) {
V_2 -> type = V_25 ;
V_8 |= V_158 ;
}
V_2 -> V_10 -> V_161 ( V_2 , V_8 ) ;
}
if ( V_2 -> type != V_25 ) {
unsigned long V_8 ;
F_135 ( V_237 , V_2 ) ;
F_11 ( V_4 , V_26 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_10 -> V_19 ( V_2 , V_2 -> V_18 & V_38 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_32 && ! ( V_2 -> V_32 -> V_8 & V_270 ) )
F_138 ( V_2 -> V_32 ) ;
if ( ! F_14 ( V_2 ) )
F_11 ( V_4 , V_224 ) ;
}
}
static int F_139 ( struct V_256 * V_238 , int line , char * V_267 )
{
struct V_236 * V_237 = V_238 -> V_239 ;
struct V_3 * V_4 = V_237 -> V_4 + line ;
struct V_1 * V_2 ;
int V_47 = 9600 ;
int V_48 = 8 ;
int V_184 = 'n' ;
int V_268 = 'n' ;
int V_82 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
if ( ! ( V_2 -> V_10 -> V_305 && V_2 -> V_10 -> V_306 ) )
return - 1 ;
if ( V_2 -> V_10 -> V_307 ) {
struct V_22 * V_308 = & V_4 -> V_2 ;
V_82 = 0 ;
F_57 ( & V_308 -> V_116 ) ;
if ( ! F_87 ( V_44 , & V_308 -> V_8 ) )
V_82 = V_2 -> V_10 -> V_307 ( V_2 ) ;
F_58 ( & V_308 -> V_116 ) ;
if ( V_82 )
return V_82 ;
}
if ( V_267 ) {
F_117 ( V_267 , & V_47 , & V_184 , & V_48 , & V_268 ) ;
return F_119 ( V_2 , NULL , V_47 , V_184 , V_48 , V_268 ) ;
}
return 0 ;
}
static int F_140 ( struct V_256 * V_238 , int line )
{
struct V_236 * V_237 = V_238 -> V_239 ;
struct V_3 * V_4 = V_237 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
return V_2 -> V_10 -> V_305 ( V_2 ) ;
}
static void F_141 ( struct V_256 * V_238 , int line , char V_85 )
{
struct V_236 * V_237 = V_238 -> V_239 ;
struct V_3 * V_4 = V_237 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return;
V_2 = V_4 -> V_1 ;
V_2 -> V_10 -> V_306 ( V_2 , V_85 ) ;
}
int F_142 ( struct V_236 * V_237 )
{
struct V_256 * V_309 ;
int V_248 , V_24 ;
F_2 ( V_237 -> V_4 ) ;
V_237 -> V_4 = F_143 ( sizeof( struct V_3 ) * V_237 -> V_259 , V_29 ) ;
if ( ! V_237 -> V_4 )
goto V_195;
V_309 = F_144 ( V_237 -> V_259 ) ;
if ( ! V_309 )
goto V_310;
V_237 -> V_256 = V_309 ;
V_309 -> V_311 = V_237 -> V_311 ;
V_309 -> V_312 = V_237 -> F_130 ;
V_309 -> V_285 = V_237 -> V_285 ;
V_309 -> V_286 = V_237 -> V_313 ;
V_309 -> type = V_314 ;
V_309 -> V_315 = V_316 ;
V_309 -> V_317 = V_318 ;
V_309 -> V_317 . V_35 = V_319 | V_275 | V_272 | V_45 | V_76 ;
V_309 -> V_317 . V_216 = V_309 -> V_317 . V_215 = 9600 ;
V_309 -> V_8 = V_320 | V_321 ;
V_309 -> V_239 = V_237 ;
F_145 ( V_309 , & V_291 ) ;
for ( V_248 = 0 ; V_248 < V_237 -> V_259 ; V_248 ++ ) {
struct V_3 * V_4 = V_237 -> V_4 + V_248 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
F_146 ( V_2 ) ;
V_2 -> V_10 = & V_322 ;
V_2 -> V_106 = V_57 / 2 ;
V_2 -> V_107 = 30 * V_57 ;
}
V_24 = F_147 ( V_309 ) ;
if ( V_24 >= 0 )
return V_24 ;
for ( V_248 = 0 ; V_248 < V_237 -> V_259 ; V_248 ++ )
F_148 ( & V_237 -> V_4 [ V_248 ] . V_2 ) ;
F_149 ( V_309 ) ;
V_310:
F_150 ( V_237 -> V_4 ) ;
V_195:
return - V_30 ;
}
void F_151 ( struct V_236 * V_237 )
{
struct V_256 * V_323 = V_237 -> V_256 ;
unsigned int V_248 ;
F_152 ( V_323 ) ;
F_149 ( V_323 ) ;
for ( V_248 = 0 ; V_248 < V_237 -> V_259 ; V_248 ++ )
F_148 ( & V_237 -> V_4 [ V_248 ] . V_2 ) ;
F_150 ( V_237 -> V_4 ) ;
V_237 -> V_4 = NULL ;
V_237 -> V_256 = NULL ;
}
struct V_256 * F_153 ( struct V_263 * V_264 , int * V_89 )
{
struct V_236 * V_323 = V_264 -> V_280 ;
* V_89 = V_264 -> V_89 ;
return V_323 -> V_256 ;
}
static T_7 F_154 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . V_105 * 16 ) ;
}
static T_7 F_156 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . type ) ;
}
static T_7 F_157 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . line ) ;
}
static T_7 F_158 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
unsigned long V_327 ;
F_56 ( V_2 , & V_117 ) ;
V_327 = V_117 . V_2 ;
if ( V_101 )
V_327 |= ( unsigned long ) V_117 . V_102 << V_101 ;
return snprintf ( V_28 , V_326 , L_34 , V_327 ) ;
}
static T_7 F_159 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . V_103 ) ;
}
static T_7 F_160 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_35 , V_117 . V_8 ) ;
}
static T_7 F_161 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . V_104 ) ;
}
static T_7 F_162 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . V_106 ) ;
}
static T_7 F_163 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . V_107 ) ;
}
static T_7 F_164 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . V_71 ) ;
}
static T_7 F_165 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . V_110 ) ;
}
static T_7 F_166 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_34 , ( unsigned long ) V_117 . V_114 ) ;
}
static T_7 F_167 ( struct V_278 * V_279 ,
struct V_324 * V_325 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_279 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_326 , L_33 , V_117 . V_112 ) ;
}
int F_168 ( struct V_236 * V_237 , struct V_1 * V_21 )
{
struct V_3 * V_4 ;
struct V_22 * V_2 ;
int V_82 = 0 ;
struct V_278 * V_287 ;
F_2 ( F_169 () ) ;
if ( V_21 -> line >= V_237 -> V_259 )
return - V_132 ;
V_4 = V_237 -> V_4 + V_21 -> line ;
V_2 = & V_4 -> V_2 ;
F_57 ( & V_328 ) ;
F_57 ( & V_2 -> V_116 ) ;
if ( V_4 -> V_1 ) {
V_82 = - V_132 ;
goto V_195;
}
V_4 -> V_1 = V_21 ;
V_4 -> V_250 = V_329 ;
V_21 -> V_32 = V_237 -> V_32 ;
V_21 -> V_4 = V_4 ;
if ( ! ( F_14 ( V_21 ) && ( V_21 -> V_32 -> V_8 & V_270 ) ) ) {
F_120 ( & V_21 -> V_9 ) ;
F_121 ( & V_21 -> V_9 , & V_271 ) ;
}
F_137 ( V_237 , V_4 , V_21 ) ;
V_287 = F_170 ( V_2 , V_237 -> V_256 ,
V_21 -> line , V_21 -> V_279 , V_2 , V_330 ) ;
if ( F_171 ( ! F_172 ( V_287 ) ) ) {
F_173 ( V_287 , 1 ) ;
} else {
F_65 ( V_293 L_36 ,
V_21 -> line ) ;
}
V_21 -> V_8 &= ~ V_241 ;
V_195:
F_58 ( & V_2 -> V_116 ) ;
F_58 ( & V_328 ) ;
return V_82 ;
}
int F_174 ( struct V_236 * V_237 , struct V_1 * V_21 )
{
struct V_3 * V_4 = V_237 -> V_4 + V_21 -> line ;
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_6 * V_5 ;
int V_82 = 0 ;
F_2 ( F_169 () ) ;
if ( V_4 -> V_1 != V_21 )
F_65 ( V_331 L_37 ,
V_4 -> V_1 , V_21 ) ;
F_57 ( & V_328 ) ;
F_57 ( & V_2 -> V_116 ) ;
if ( ! V_4 -> V_1 ) {
F_58 ( & V_2 -> V_116 ) ;
V_82 = - V_132 ;
goto V_195;
}
V_21 -> V_8 |= V_241 ;
F_58 ( & V_2 -> V_116 ) ;
F_175 ( V_237 -> V_256 , V_21 -> line ) ;
V_5 = F_176 ( V_2 ) ;
if ( V_5 ) {
F_177 ( V_2 -> V_5 ) ;
F_178 ( V_5 ) ;
}
if ( F_14 ( V_21 ) )
F_179 ( V_21 -> V_32 ) ;
if ( V_21 -> type != V_25 )
V_21 -> V_10 -> V_140 ( V_21 ) ;
V_21 -> type = V_25 ;
V_4 -> V_1 = NULL ;
V_195:
F_58 ( & V_328 ) ;
return V_82 ;
}
int F_180 ( struct V_1 * V_332 , struct V_1 * V_333 )
{
if ( V_332 -> V_111 != V_333 -> V_111 )
return 0 ;
switch ( V_332 -> V_111 ) {
case V_297 :
return ( V_332 -> V_100 == V_333 -> V_100 ) ;
case V_298 :
return ( V_332 -> V_100 == V_333 -> V_100 ) &&
( V_332 -> V_109 == V_333 -> V_109 ) ;
case V_254 :
case V_299 :
case V_300 :
case V_301 :
return ( V_332 -> V_115 == V_333 -> V_115 ) ;
}
return 0 ;
}
void F_181 ( struct V_1 * V_21 , unsigned int V_252 )
{
struct V_22 * V_2 = & V_21 -> V_4 -> V_2 ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_334 * V_335 = V_5 ? F_182 ( V_5 ) : NULL ;
if ( V_335 ) {
if ( V_335 -> V_10 -> V_336 )
V_335 -> V_10 -> V_336 ( V_5 , V_252 ) ;
F_183 ( V_335 ) ;
}
V_21 -> V_167 . V_176 ++ ;
if ( V_2 -> V_8 & V_337 ) {
if ( V_252 )
F_94 ( & V_2 -> V_227 ) ;
else if ( V_5 )
F_184 ( V_5 ) ;
}
}
void F_185 ( struct V_1 * V_21 , unsigned int V_252 )
{
struct V_22 * V_2 = & V_21 -> V_4 -> V_2 ;
struct V_6 * V_5 = V_2 -> V_5 ;
V_21 -> V_167 . V_177 ++ ;
if ( F_17 ( V_2 ) ) {
if ( V_5 -> V_13 ) {
if ( V_252 ) {
V_5 -> V_13 = 0 ;
V_21 -> V_10 -> V_14 ( V_21 ) ;
F_1 ( V_21 ) ;
}
} else {
if ( ! V_252 ) {
V_5 -> V_13 = 1 ;
V_21 -> V_10 -> V_11 ( V_21 ) ;
}
}
}
}
void F_186 ( struct V_1 * V_2 , unsigned int V_252 ,
unsigned int V_183 , unsigned int V_85 , unsigned int V_338 )
{
struct V_22 * V_308 = & V_2 -> V_4 -> V_2 ;
if ( ( V_252 & V_2 -> V_339 & ~ V_183 ) == 0 )
if ( F_187 ( V_308 , V_85 , V_338 ) == 0 )
++ V_2 -> V_167 . V_186 ;
if ( V_252 & ~ V_2 -> V_339 & V_183 )
if ( F_187 ( V_308 , 0 , V_340 ) == 0 )
++ V_2 -> V_167 . V_186 ;
}
