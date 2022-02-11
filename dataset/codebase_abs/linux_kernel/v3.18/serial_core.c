static int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ;
}
void F_2 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
F_3 ( ! V_7 ) ;
F_4 ( V_7 -> V_5 . V_8 ) ;
}
static void F_5 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
unsigned long V_11 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_5 -> V_13 -> V_14 ( V_5 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
}
static void F_8 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
if ( ! F_9 ( V_5 ) )
V_5 -> V_13 -> V_15 ( V_5 ) ;
}
static void F_10 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
unsigned long V_11 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
F_8 ( V_8 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
}
static inline void
F_11 ( struct V_1 * V_5 , unsigned int V_16 , unsigned int V_17 )
{
unsigned long V_11 ;
unsigned int V_18 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_18 = V_5 -> V_19 ;
V_5 -> V_19 = ( V_18 & ~ V_17 ) | V_16 ;
if ( V_18 != V_5 -> V_19 )
V_5 -> V_13 -> V_20 ( V_5 , V_5 -> V_19 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
}
static int F_12 ( struct V_9 * V_8 , struct V_6 * V_7 ,
int V_21 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
unsigned long V_22 ;
int V_23 = 0 ;
if ( V_2 -> type == V_24 )
return 1 ;
F_13 ( V_7 , V_25 ) ;
if ( ! V_7 -> V_26 . V_27 ) {
V_22 = F_14 ( V_28 ) ;
if ( ! V_22 )
return - V_29 ;
V_7 -> V_26 . V_27 = ( unsigned char * ) V_22 ;
F_15 ( & V_7 -> V_26 ) ;
}
V_23 = V_2 -> V_13 -> V_30 ( V_2 ) ;
if ( V_23 == 0 ) {
if ( F_16 ( V_2 ) && V_2 -> V_31 -> V_32 ) {
V_8 -> V_33 . V_34 = V_2 -> V_31 -> V_32 ;
V_2 -> V_31 -> V_32 = 0 ;
}
F_17 ( V_8 , V_7 , NULL ) ;
if ( V_21 ) {
if ( V_8 -> V_33 . V_34 & V_35 )
F_18 ( V_2 , V_36 | V_37 ) ;
}
F_19 ( & V_2 -> V_12 ) ;
if ( F_20 ( V_2 ) &&
! ( V_2 -> V_13 -> V_38 ( V_2 ) & V_39 ) )
V_2 -> V_40 = 1 ;
else
V_2 -> V_40 = 0 ;
F_21 ( & V_2 -> V_12 ) ;
}
if ( V_23 && F_22 ( V_41 ) )
return 1 ;
return V_23 ;
}
static int F_23 ( struct V_9 * V_8 , struct V_6 * V_7 ,
int V_21 )
{
struct V_42 * V_5 = & V_7 -> V_5 ;
int V_23 ;
if ( V_5 -> V_11 & V_43 )
return 0 ;
F_24 ( V_44 , & V_8 -> V_11 ) ;
V_23 = F_12 ( V_8 , V_7 , V_21 ) ;
if ( ! V_23 ) {
F_24 ( V_45 , & V_5 -> V_11 ) ;
F_25 ( V_44 , & V_8 -> V_11 ) ;
} else if ( V_23 > 0 )
V_23 = 0 ;
return V_23 ;
}
static void F_26 ( struct V_9 * V_8 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
if ( V_8 )
F_24 ( V_44 , & V_8 -> V_11 ) ;
if ( F_27 ( V_45 , & V_5 -> V_11 ) ) {
if ( F_16 ( V_2 ) && V_8 )
V_2 -> V_31 -> V_32 = V_8 -> V_33 . V_34 ;
if ( ! V_8 || ( V_8 -> V_33 . V_34 & V_46 ) )
F_28 ( V_2 , V_37 | V_36 ) ;
F_29 ( V_5 ) ;
}
F_25 ( V_47 , & V_5 -> V_11 ) ;
if ( V_7 -> V_26 . V_27 ) {
F_30 ( ( unsigned long ) V_7 -> V_26 . V_27 ) ;
V_7 -> V_26 . V_27 = NULL ;
}
}
void
F_31 ( struct V_1 * V_5 , unsigned int V_32 ,
unsigned int V_48 )
{
unsigned int V_49 ;
switch ( V_32 & V_50 ) {
case V_51 :
V_49 = 7 ;
break;
case V_52 :
V_49 = 8 ;
break;
case V_53 :
V_49 = 9 ;
break;
default:
V_49 = 10 ;
break;
}
if ( V_32 & V_54 )
V_49 ++ ;
if ( V_32 & V_55 )
V_49 ++ ;
V_49 = V_49 * V_5 -> V_56 ;
V_5 -> V_57 = ( V_58 * V_49 ) / V_48 + V_58 / 50 ;
}
unsigned int
F_32 ( struct V_1 * V_5 , struct V_59 * V_33 ,
struct V_59 * V_18 , unsigned int V_60 , unsigned int V_61 )
{
unsigned int V_62 , V_48 , V_63 = 38400 ;
int V_64 = 0 ;
T_1 V_11 = V_5 -> V_11 & V_65 ;
if ( V_11 == V_66 )
V_63 = 57600 ;
else if ( V_11 == V_67 )
V_63 = 115200 ;
else if ( V_11 == V_68 )
V_63 = 230400 ;
else if ( V_11 == V_69 )
V_63 = 460800 ;
for ( V_62 = 0 ; V_62 < 2 ; V_62 ++ ) {
V_48 = F_33 ( V_33 ) ;
if ( V_62 == 0 && V_48 == 38400 )
V_48 = V_63 ;
if ( V_48 == 0 ) {
V_64 = 1 ;
V_48 = 9600 ;
}
if ( V_48 >= V_60 && V_48 <= V_61 )
return V_48 ;
V_33 -> V_34 &= ~ V_35 ;
if ( V_18 ) {
V_48 = F_33 ( V_18 ) ;
if ( ! V_64 )
F_34 ( V_33 ,
V_48 , V_48 ) ;
V_18 = NULL ;
continue;
}
if ( ! V_64 ) {
if ( V_48 <= V_60 )
F_34 ( V_33 ,
V_60 + 1 , V_60 + 1 ) ;
else
F_34 ( V_33 ,
V_61 - 1 , V_61 - 1 ) ;
}
}
F_35 ( 1 ) ;
return 0 ;
}
unsigned int
F_36 ( struct V_1 * V_5 , unsigned int V_48 )
{
unsigned int V_70 ;
if ( V_48 == 38400 && ( V_5 -> V_11 & V_65 ) == V_71 )
V_70 = V_5 -> V_72 ;
else
V_70 = F_37 ( V_5 -> V_73 , 16 * V_48 ) ;
return V_70 ;
}
static void F_17 ( struct V_9 * V_8 , struct V_6 * V_7 ,
struct V_59 * V_74 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_59 * V_33 ;
if ( ! V_8 || V_2 -> type == V_24 )
return;
V_33 = & V_8 -> V_33 ;
V_2 -> V_13 -> V_75 ( V_2 , V_33 , V_74 ) ;
F_19 ( & V_2 -> V_12 ) ;
if ( V_33 -> V_34 & V_76 )
V_2 -> V_3 |= V_77 ;
else
V_2 -> V_3 &= ~ V_77 ;
if ( V_33 -> V_34 & V_78 )
V_2 -> V_3 &= ~ V_4 ;
else
V_2 -> V_3 |= V_4 ;
F_21 ( & V_2 -> V_12 ) ;
}
static inline int F_38 ( struct V_1 * V_5 ,
struct V_79 * V_80 , unsigned char V_81 )
{
unsigned long V_11 ;
int V_82 = 0 ;
if ( ! V_80 -> V_27 )
return 0 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
if ( F_39 ( V_80 ) != 0 ) {
V_80 -> V_27 [ V_80 -> V_83 ] = V_81 ;
V_80 -> V_83 = ( V_80 -> V_83 + 1 ) & ( V_84 - 1 ) ;
V_82 = 1 ;
}
F_7 ( & V_5 -> V_12 , V_11 ) ;
return V_82 ;
}
static int F_40 ( struct V_9 * V_8 , unsigned char V_85 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
return F_38 ( V_7 -> V_1 , & V_7 -> V_26 , V_85 ) ;
}
static void F_41 ( struct V_9 * V_8 )
{
F_10 ( V_8 ) ;
}
static int F_42 ( struct V_9 * V_8 ,
const unsigned char * V_27 , int V_86 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 ;
struct V_79 * V_80 ;
unsigned long V_11 ;
int V_81 , V_82 = 0 ;
if ( ! V_7 ) {
F_35 ( 1 ) ;
return - V_87 ;
}
V_5 = V_7 -> V_1 ;
V_80 = & V_7 -> V_26 ;
if ( ! V_80 -> V_27 )
return 0 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
while ( 1 ) {
V_81 = F_43 ( V_80 -> V_83 , V_80 -> V_88 , V_84 ) ;
if ( V_86 < V_81 )
V_81 = V_86 ;
if ( V_81 <= 0 )
break;
memcpy ( V_80 -> V_27 + V_80 -> V_83 , V_27 , V_81 ) ;
V_80 -> V_83 = ( V_80 -> V_83 + V_81 ) & ( V_84 - 1 ) ;
V_27 += V_81 ;
V_86 -= V_81 ;
V_82 += V_81 ;
}
F_7 ( & V_5 -> V_12 , V_11 ) ;
F_10 ( V_8 ) ;
return V_82 ;
}
static int F_44 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
unsigned long V_11 ;
int V_82 ;
F_6 ( & V_7 -> V_1 -> V_12 , V_11 ) ;
V_82 = F_39 ( & V_7 -> V_26 ) ;
F_7 ( & V_7 -> V_1 -> V_12 , V_11 ) ;
return V_82 ;
}
static int F_45 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
unsigned long V_11 ;
int V_82 ;
F_6 ( & V_7 -> V_1 -> V_12 , V_11 ) ;
V_82 = F_46 ( & V_7 -> V_26 ) ;
F_7 ( & V_7 -> V_1 -> V_12 , V_11 ) ;
return V_82 ;
}
static void F_47 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 ;
unsigned long V_11 ;
if ( ! V_7 ) {
F_35 ( 1 ) ;
return;
}
V_5 = V_7 -> V_1 ;
F_48 ( L_1 , V_8 -> V_89 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
F_15 ( & V_7 -> V_26 ) ;
if ( V_5 -> V_13 -> V_90 )
V_5 -> V_13 -> V_90 ( V_5 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
F_4 ( V_8 ) ;
}
static void F_49 ( struct V_9 * V_8 , char V_85 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
unsigned long V_11 ;
if ( V_5 -> V_13 -> V_91 )
V_5 -> V_13 -> V_91 ( V_5 , V_85 ) ;
else {
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_5 -> V_92 = V_85 ;
if ( V_85 )
V_5 -> V_13 -> V_15 ( V_5 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
}
}
static void F_50 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
T_2 V_93 = 0 ;
if ( F_51 ( V_8 ) )
V_93 |= V_94 ;
if ( V_8 -> V_33 . V_34 & V_76 )
V_93 |= V_95 ;
if ( V_5 -> V_11 & V_93 ) {
V_5 -> V_13 -> V_96 ( V_5 ) ;
V_93 &= ~ V_5 -> V_11 ;
}
if ( V_93 & V_94 )
F_49 ( V_8 , F_52 ( V_8 ) ) ;
if ( V_93 & V_95 )
F_28 ( V_5 , V_36 ) ;
}
static void F_53 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
T_2 V_93 = 0 ;
if ( F_51 ( V_8 ) )
V_93 |= V_94 ;
if ( V_8 -> V_33 . V_34 & V_76 )
V_93 |= V_95 ;
if ( V_5 -> V_11 & V_93 ) {
V_5 -> V_13 -> V_97 ( V_5 ) ;
V_93 &= ~ V_5 -> V_11 ;
}
if ( V_93 & V_94 )
F_49 ( V_8 , F_54 ( V_8 ) ) ;
if ( V_93 & V_95 )
F_18 ( V_5 , V_36 ) ;
}
static void F_55 ( struct V_42 * V_5 ,
struct V_98 * V_99 )
{
struct V_6 * V_7 = F_56 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> type = V_2 -> type ;
V_99 -> line = V_2 -> line ;
V_99 -> V_5 = V_2 -> V_100 ;
if ( V_101 )
V_99 -> V_102 = ( long ) V_2 -> V_100 >> V_101 ;
V_99 -> V_103 = V_2 -> V_103 ;
V_99 -> V_11 = V_2 -> V_11 ;
V_99 -> V_104 = V_2 -> V_56 ;
V_99 -> V_105 = V_2 -> V_73 / 16 ;
V_99 -> V_106 = F_57 ( V_5 -> V_106 ) / 10 ;
V_99 -> V_107 = V_5 -> V_107 == V_108 ?
V_108 :
F_57 ( V_5 -> V_107 ) / 10 ;
V_99 -> V_72 = V_2 -> V_72 ;
V_99 -> V_109 = V_2 -> V_109 ;
V_99 -> V_110 = V_2 -> V_111 ;
V_99 -> V_112 = V_2 -> V_113 ;
V_99 -> V_114 = ( void * ) ( unsigned long ) V_2 -> V_115 ;
}
static void F_58 ( struct V_42 * V_5 ,
struct V_98 * V_99 )
{
F_59 ( & V_5 -> V_116 ) ;
F_55 ( V_5 , V_99 ) ;
F_60 ( & V_5 -> V_116 ) ;
}
static int F_61 ( struct V_42 * V_5 ,
struct V_98 T_3 * V_99 )
{
struct V_98 V_117 ;
F_58 ( V_5 , & V_117 ) ;
if ( F_62 ( V_99 , & V_117 , sizeof( * V_99 ) ) )
return - V_118 ;
return 0 ;
}
static int F_63 ( struct V_9 * V_8 , struct V_42 * V_5 ,
struct V_6 * V_7 ,
struct V_98 * V_119 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
unsigned long V_120 ;
unsigned int V_121 , V_122 , V_107 ;
unsigned int V_123 , V_106 ;
T_1 V_124 , V_125 ;
int V_23 = 0 ;
V_120 = V_119 -> V_5 ;
if ( V_101 )
V_120 += ( unsigned long ) V_119 -> V_102 << V_101 ;
V_119 -> V_103 = F_64 ( V_119 -> V_103 ) ;
V_106 = F_65 ( V_119 -> V_106 * 10 ) ;
V_107 = V_119 -> V_107 == V_108 ?
V_108 :
F_65 ( V_119 -> V_107 * 10 ) ;
V_121 = ! ( V_2 -> V_11 & V_126 )
&& V_119 -> V_103 != V_2 -> V_103 ;
V_122 = ! ( V_2 -> V_11 & V_126 )
&& ( V_120 != V_2 -> V_100 ||
( unsigned long ) V_119 -> V_114 != V_2 -> V_115 ||
V_119 -> V_109 != V_2 -> V_109 ||
V_119 -> V_110 != V_2 -> V_111 ||
V_119 -> V_112 != V_2 -> V_113 ||
V_119 -> type != V_2 -> type ) ;
V_124 = V_2 -> V_11 ;
V_125 = V_119 -> V_11 ;
V_123 = V_2 -> V_72 ;
if ( ! F_22 ( V_41 ) ) {
V_23 = - V_127 ;
if ( V_121 || V_122 ||
( V_119 -> V_105 != V_2 -> V_73 / 16 ) ||
( V_106 != V_5 -> V_106 ) ||
( V_107 != V_5 -> V_107 ) ||
( V_119 -> V_104 &&
V_119 -> V_104 != V_2 -> V_56 ) ||
( ( ( V_125 ^ V_124 ) & ~ V_128 ) != 0 ) )
goto exit;
V_2 -> V_11 = ( ( V_2 -> V_11 & ~ V_128 ) |
( V_125 & V_128 ) ) ;
V_2 -> V_72 = V_119 -> V_72 ;
goto V_129;
}
if ( V_2 -> V_13 -> V_130 )
V_23 = V_2 -> V_13 -> V_130 ( V_2 , V_119 ) ;
if ( ( V_119 -> V_103 >= V_131 ) || ( V_119 -> V_103 < 0 ) ||
( V_119 -> V_105 < 9600 ) )
V_23 = - V_132 ;
if ( V_23 )
goto exit;
if ( V_122 || V_121 ) {
V_23 = - V_133 ;
if ( F_66 ( V_5 ) > 1 )
goto exit;
F_26 ( V_8 , V_7 ) ;
}
if ( V_122 ) {
unsigned long V_134 , V_135 ;
unsigned int V_136 , V_137 , V_138 , V_139 ;
V_134 = V_2 -> V_100 ;
V_135 = V_2 -> V_115 ;
V_136 = V_2 -> type ;
V_138 = V_2 -> V_109 ;
V_137 = V_2 -> V_111 ;
V_139 = V_2 -> V_113 ;
if ( V_136 != V_24 )
V_2 -> V_13 -> V_140 ( V_2 ) ;
V_2 -> V_100 = V_120 ;
V_2 -> type = V_119 -> type ;
V_2 -> V_109 = V_119 -> V_109 ;
V_2 -> V_111 = V_119 -> V_110 ;
V_2 -> V_113 = V_119 -> V_112 ;
V_2 -> V_115 = ( unsigned long ) V_119 -> V_114 ;
if ( V_2 -> type != V_24 ) {
V_23 = V_2 -> V_13 -> V_141 ( V_2 ) ;
} else {
V_23 = 0 ;
}
if ( V_23 ) {
V_2 -> V_100 = V_134 ;
V_2 -> type = V_136 ;
V_2 -> V_109 = V_138 ;
V_2 -> V_111 = V_137 ;
V_2 -> V_113 = V_139 ;
V_2 -> V_115 = V_135 ;
if ( V_136 != V_24 ) {
V_23 = V_2 -> V_13 -> V_141 ( V_2 ) ;
if ( V_23 )
V_2 -> type = V_24 ;
V_23 = - V_133 ;
}
goto exit;
}
}
if ( V_121 )
V_2 -> V_103 = V_119 -> V_103 ;
if ( ! ( V_2 -> V_11 & V_126 ) )
V_2 -> V_73 = V_119 -> V_105 * 16 ;
V_2 -> V_11 = ( V_2 -> V_11 & ~ V_142 ) |
( V_125 & V_142 ) ;
V_2 -> V_72 = V_119 -> V_72 ;
V_5 -> V_106 = V_106 ;
V_5 -> V_107 = V_107 ;
if ( V_119 -> V_104 )
V_2 -> V_56 = V_119 -> V_104 ;
V_5 -> V_143 = ( V_2 -> V_11 & V_144 ) ? 1 : 0 ;
V_129:
V_23 = 0 ;
if ( V_2 -> type == V_24 )
goto exit;
if ( V_5 -> V_11 & V_43 ) {
if ( ( ( V_124 ^ V_2 -> V_11 ) & V_65 ) ||
V_123 != V_2 -> V_72 ) {
if ( V_2 -> V_11 & V_65 ) {
char V_27 [ 64 ] ;
F_67 ( V_2 -> V_145 ,
L_2 ,
V_146 -> V_147 ,
F_68 ( V_5 -> V_8 , V_27 ) ) ;
}
F_17 ( V_8 , V_7 , NULL ) ;
}
} else
V_23 = F_23 ( V_8 , V_7 , 1 ) ;
exit:
return V_23 ;
}
static int F_69 ( struct V_9 * V_8 , struct V_6 * V_7 ,
struct V_98 T_3 * V_148 )
{
struct V_98 V_149 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
int V_23 ;
if ( F_70 ( & V_149 , V_148 , sizeof( V_149 ) ) )
return - V_118 ;
F_59 ( & V_5 -> V_116 ) ;
V_23 = F_63 ( V_8 , V_5 , V_7 , & V_149 ) ;
F_60 ( & V_5 -> V_116 ) ;
return V_23 ;
}
static int F_71 ( struct V_9 * V_8 ,
struct V_6 * V_7 , unsigned int T_3 * V_150 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
unsigned int V_151 ;
V_151 = V_2 -> V_13 -> V_152 ( V_2 ) ;
if ( V_2 -> V_92 ||
( ( F_46 ( & V_7 -> V_26 ) > 0 ) &&
! F_9 ( V_2 ) ) )
V_151 &= ~ V_153 ;
return F_72 ( V_151 , V_150 ) ;
}
static int F_73 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
struct V_1 * V_2 = V_7 -> V_1 ;
int V_151 = - V_154 ;
F_59 ( & V_5 -> V_116 ) ;
if ( ! ( V_8 -> V_11 & ( 1 << V_44 ) ) ) {
V_151 = V_2 -> V_19 ;
F_19 ( & V_2 -> V_12 ) ;
V_151 |= V_2 -> V_13 -> V_38 ( V_2 ) ;
F_21 ( & V_2 -> V_12 ) ;
}
F_60 ( & V_5 -> V_116 ) ;
return V_151 ;
}
static int
F_74 ( struct V_9 * V_8 , unsigned int V_16 , unsigned int V_17 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
int V_82 = - V_154 ;
F_59 ( & V_5 -> V_116 ) ;
if ( ! ( V_8 -> V_11 & ( 1 << V_44 ) ) ) {
F_11 ( V_2 , V_16 , V_17 ) ;
V_82 = 0 ;
}
F_60 ( & V_5 -> V_116 ) ;
return V_82 ;
}
static int F_75 ( struct V_9 * V_8 , int V_155 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
struct V_1 * V_2 = V_7 -> V_1 ;
F_59 ( & V_5 -> V_116 ) ;
if ( V_2 -> type != V_24 )
V_2 -> V_13 -> V_156 ( V_2 , V_155 ) ;
F_60 ( & V_5 -> V_116 ) ;
return 0 ;
}
static int F_76 ( struct V_9 * V_8 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
int V_11 , V_82 ;
if ( ! F_22 ( V_41 ) )
return - V_127 ;
if ( F_77 ( & V_5 -> V_116 ) )
return - V_157 ;
V_82 = - V_133 ;
if ( F_66 ( V_5 ) == 1 ) {
F_26 ( V_8 , V_7 ) ;
if ( V_2 -> type != V_24 )
V_2 -> V_13 -> V_140 ( V_2 ) ;
V_11 = V_158 ;
if ( V_2 -> V_11 & V_159 )
V_11 |= V_160 ;
V_2 -> V_13 -> V_161 ( V_2 , V_11 ) ;
V_82 = F_23 ( V_8 , V_7 , 1 ) ;
}
F_60 ( & V_5 -> V_116 ) ;
return V_82 ;
}
static void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 -> V_162 )
V_2 -> V_13 -> V_162 ( V_2 ) ;
}
static int
F_79 ( struct V_6 * V_7 , unsigned long V_163 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
F_80 ( V_164 , V_146 ) ;
struct V_165 V_166 , V_167 ;
int V_82 ;
F_19 ( & V_2 -> V_12 ) ;
memcpy ( & V_166 , & V_2 -> V_168 , sizeof( struct V_165 ) ) ;
F_78 ( V_2 ) ;
F_21 ( & V_2 -> V_12 ) ;
F_81 ( & V_5 -> V_169 , & V_164 ) ;
for (; ; ) {
F_19 ( & V_2 -> V_12 ) ;
memcpy ( & V_167 , & V_2 -> V_168 , sizeof( struct V_165 ) ) ;
F_21 ( & V_2 -> V_12 ) ;
F_82 ( V_170 ) ;
if ( ( ( V_163 & V_171 ) && ( V_167 . V_172 != V_166 . V_172 ) ) ||
( ( V_163 & V_173 ) && ( V_167 . V_174 != V_166 . V_174 ) ) ||
( ( V_163 & V_175 ) && ( V_167 . V_176 != V_166 . V_176 ) ) ||
( ( V_163 & V_39 ) && ( V_167 . V_177 != V_166 . V_177 ) ) ) {
V_82 = 0 ;
break;
}
F_83 () ;
if ( F_84 ( V_146 ) ) {
V_82 = - V_157 ;
break;
}
V_166 = V_167 ;
}
V_146 -> V_7 = V_178 ;
F_85 ( & V_5 -> V_169 , & V_164 ) ;
return V_82 ;
}
static int F_86 ( struct V_9 * V_8 ,
struct V_179 * V_168 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_165 V_167 ;
struct V_1 * V_2 = V_7 -> V_1 ;
F_19 ( & V_2 -> V_12 ) ;
memcpy ( & V_167 , & V_2 -> V_168 , sizeof( struct V_165 ) ) ;
F_21 ( & V_2 -> V_12 ) ;
V_168 -> V_177 = V_167 . V_177 ;
V_168 -> V_174 = V_167 . V_174 ;
V_168 -> V_172 = V_167 . V_172 ;
V_168 -> V_176 = V_167 . V_176 ;
V_168 -> V_180 = V_167 . V_180 ;
V_168 -> V_181 = V_167 . V_181 ;
V_168 -> V_182 = V_167 . V_182 ;
V_168 -> V_183 = V_167 . V_183 ;
V_168 -> V_184 = V_167 . V_184 ;
V_168 -> V_185 = V_167 . V_185 ;
V_168 -> V_186 = V_167 . V_186 ;
return 0 ;
}
static int
F_87 ( struct V_9 * V_8 , unsigned int V_187 ,
unsigned long V_163 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
void T_3 * V_188 = ( void T_3 * ) V_163 ;
int V_82 = - V_189 ;
switch ( V_187 ) {
case V_190 :
V_82 = F_61 ( V_5 , V_188 ) ;
break;
case V_191 :
V_82 = F_69 ( V_8 , V_7 , V_188 ) ;
break;
case V_192 :
V_82 = F_76 ( V_8 , V_7 ) ;
break;
case V_193 :
case V_194 :
V_82 = 0 ;
break;
}
if ( V_82 != - V_189 )
goto V_195;
if ( V_8 -> V_11 & ( 1 << V_44 ) ) {
V_82 = - V_154 ;
goto V_195;
}
switch ( V_187 ) {
case V_196 :
V_82 = F_79 ( V_7 , V_163 ) ;
break;
}
if ( V_82 != - V_189 )
goto V_195;
F_59 ( & V_5 -> V_116 ) ;
if ( V_8 -> V_11 & ( 1 << V_44 ) ) {
V_82 = - V_154 ;
goto V_197;
}
switch ( V_187 ) {
case V_198 :
V_82 = F_71 ( V_8 , V_7 , V_188 ) ;
break;
default: {
struct V_1 * V_2 = V_7 -> V_1 ;
if ( V_2 -> V_13 -> V_199 )
V_82 = V_2 -> V_13 -> V_199 ( V_2 , V_187 , V_163 ) ;
break;
}
}
V_197:
F_60 ( & V_5 -> V_116 ) ;
V_195:
return V_82 ;
}
static void F_88 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_1 ;
if ( V_2 -> V_13 -> V_200 )
V_2 -> V_13 -> V_200 ( V_2 , V_8 -> V_33 . V_201 ) ;
}
static void F_89 ( struct V_9 * V_8 ,
struct V_59 * V_74 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_1 ;
unsigned int V_32 = V_8 -> V_33 . V_34 ;
unsigned int V_202 = V_203 | V_204 | V_205 | V_206 | V_207 ;
bool V_208 = false ;
if ( V_2 -> V_11 & V_94 ) {
V_202 |= V_209 | V_210 | V_211 ;
V_208 =
V_8 -> V_33 . V_212 [ V_213 ] != V_74 -> V_212 [ V_213 ] ||
V_8 -> V_33 . V_212 [ V_214 ] != V_74 -> V_212 [ V_214 ] ;
}
if ( ( V_32 ^ V_74 -> V_34 ) == 0 &&
V_8 -> V_33 . V_215 == V_74 -> V_215 &&
V_8 -> V_33 . V_216 == V_74 -> V_216 &&
( ( V_8 -> V_33 . V_217 ^ V_74 -> V_217 ) & V_202 ) == 0 &&
! V_208 ) {
return;
}
F_17 ( V_8 , V_7 , V_74 ) ;
V_32 = V_8 -> V_33 . V_34 ;
if ( ( V_74 -> V_34 & V_35 ) && ! ( V_32 & V_35 ) )
F_28 ( V_2 , V_36 | V_37 ) ;
else if ( ! ( V_74 -> V_34 & V_35 ) && ( V_32 & V_35 ) ) {
unsigned int V_93 = V_37 ;
if ( ! ( V_32 & V_76 ) || ! F_90 ( V_218 , & V_8 -> V_11 ) )
V_93 |= V_36 ;
F_18 ( V_2 , V_93 ) ;
}
if ( V_2 -> V_11 & V_95 )
return;
if ( ( V_74 -> V_34 & V_76 ) && ! ( V_32 & V_76 ) ) {
F_19 ( & V_2 -> V_12 ) ;
V_2 -> V_40 = 0 ;
F_8 ( V_8 ) ;
F_21 ( & V_2 -> V_12 ) ;
}
else if ( ! ( V_74 -> V_34 & V_76 ) && ( V_32 & V_76 ) ) {
F_19 ( & V_2 -> V_12 ) ;
if ( ! ( V_2 -> V_13 -> V_38 ( V_2 ) & V_39 ) ) {
V_2 -> V_40 = 1 ;
V_2 -> V_13 -> V_14 ( V_2 ) ;
}
F_21 ( & V_2 -> V_12 ) ;
}
}
static void F_91 ( struct V_9 * V_8 , struct V_219 * V_220 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_42 * V_5 ;
struct V_1 * V_2 ;
unsigned long V_11 ;
if ( ! V_7 )
return;
V_2 = V_7 -> V_1 ;
V_5 = & V_7 -> V_5 ;
F_48 ( L_3 , V_2 ? V_2 -> line : - 1 ) ;
if ( ! V_5 -> V_86 || F_92 ( V_5 , V_8 , V_220 ) == 0 )
return;
if ( V_5 -> V_11 & V_43 ) {
unsigned long V_11 ;
F_6 ( & V_2 -> V_12 , V_11 ) ;
V_2 -> V_13 -> V_221 ( V_2 ) ;
F_7 ( & V_2 -> V_12 , V_11 ) ;
F_93 ( V_8 , V_2 -> V_57 ) ;
}
F_59 ( & V_5 -> V_116 ) ;
F_26 ( V_8 , V_7 ) ;
F_47 ( V_8 ) ;
F_94 ( V_8 ) ;
F_95 ( V_5 , NULL ) ;
V_8 -> V_222 = 0 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
if ( V_5 -> V_223 ) {
F_7 ( & V_5 -> V_12 , V_11 ) ;
if ( V_5 -> V_106 )
F_96 (
F_57 ( V_5 -> V_106 ) ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
} else if ( ! F_16 ( V_2 ) ) {
F_7 ( & V_5 -> V_12 , V_11 ) ;
F_13 ( V_7 , V_224 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
}
F_25 ( V_225 , & V_5 -> V_11 ) ;
F_25 ( V_226 , & V_5 -> V_11 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
F_97 ( & V_5 -> V_227 ) ;
F_97 ( & V_5 -> V_228 ) ;
F_60 ( & V_5 -> V_116 ) ;
}
static void F_93 ( struct V_9 * V_8 , int V_57 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
unsigned long V_229 , V_230 ;
if ( V_5 -> type == V_24 || V_5 -> V_56 == 0 )
return;
V_229 = ( V_5 -> V_57 - V_58 / 50 ) / V_5 -> V_56 ;
V_229 = V_229 / 5 ;
if ( V_229 == 0 )
V_229 = 1 ;
if ( V_57 && V_57 < V_229 )
V_229 = V_57 ;
if ( V_57 == 0 || V_57 > 2 * V_5 -> V_57 )
V_57 = 2 * V_5 -> V_57 ;
V_230 = V_231 + V_57 ;
F_48 ( L_4 ,
V_5 -> line , V_231 , V_230 ) ;
while ( ! V_5 -> V_13 -> V_152 ( V_5 ) ) {
F_96 ( F_57 ( V_229 ) ) ;
if ( F_84 ( V_146 ) )
break;
if ( F_98 ( V_231 , V_230 ) )
break;
}
}
static void F_99 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
unsigned long V_11 ;
F_48 ( L_5 , V_7 -> V_1 -> line ) ;
F_59 ( & V_5 -> V_116 ) ;
if ( V_5 -> V_11 & V_232 ) {
F_47 ( V_8 ) ;
F_26 ( V_8 , V_7 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_5 -> V_86 = 0 ;
F_25 ( V_225 , & V_5 -> V_11 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
F_95 ( V_5 , NULL ) ;
if ( ! F_16 ( V_7 -> V_1 ) )
F_13 ( V_7 , V_224 ) ;
F_97 ( & V_5 -> V_227 ) ;
F_97 ( & V_5 -> V_169 ) ;
}
F_60 ( & V_5 -> V_116 ) ;
}
static int F_100 ( struct V_42 * V_5 , struct V_9 * V_8 )
{
return 0 ;
}
static void F_29 ( struct V_42 * V_5 )
{
struct V_6 * V_7 = F_56 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
F_97 ( & V_5 -> V_169 ) ;
V_2 -> V_13 -> V_233 ( V_2 ) ;
F_101 ( V_2 -> V_103 ) ;
}
static int F_102 ( struct V_42 * V_5 )
{
struct V_6 * V_7 = F_56 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
int V_19 ;
F_19 ( & V_2 -> V_12 ) ;
F_78 ( V_2 ) ;
V_19 = V_2 -> V_13 -> V_38 ( V_2 ) ;
F_21 ( & V_2 -> V_12 ) ;
if ( V_19 & V_234 )
return 1 ;
return 0 ;
}
static void F_103 ( struct V_42 * V_5 , int V_235 )
{
struct V_6 * V_7 = F_56 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
if ( V_235 )
F_18 ( V_2 , V_37 | V_36 ) ;
else
F_28 ( V_2 , V_37 | V_36 ) ;
}
static int F_104 ( struct V_9 * V_8 , struct V_219 * V_220 )
{
struct V_236 * V_237 = (struct V_236 * ) V_8 -> V_238 -> V_239 ;
int V_23 , line = V_8 -> V_89 ;
struct V_6 * V_7 = V_237 -> V_7 + line ;
struct V_42 * V_5 = & V_7 -> V_5 ;
F_48 ( L_6 , line ) ;
if ( F_77 ( & V_5 -> V_116 ) ) {
V_23 = - V_157 ;
goto V_240;
}
V_5 -> V_86 ++ ;
if ( ! V_7 -> V_1 || V_7 -> V_1 -> V_11 & V_241 ) {
V_23 = - V_242 ;
goto V_243;
}
V_8 -> V_10 = V_7 ;
V_7 -> V_1 -> V_7 = V_7 ;
V_7 -> V_5 . V_143 =
( V_7 -> V_1 -> V_11 & V_144 ) ? 1 : 0 ;
F_95 ( V_5 , V_8 ) ;
V_23 = F_23 ( V_8 , V_7 , 0 ) ;
F_60 ( & V_5 -> V_116 ) ;
if ( V_23 == 0 )
V_23 = F_105 ( V_5 , V_8 , V_220 ) ;
V_240:
return V_23 ;
V_243:
V_5 -> V_86 -- ;
F_60 ( & V_5 -> V_116 ) ;
goto V_240;
}
static const char * F_106 ( struct V_1 * V_5 )
{
const char * V_244 = NULL ;
if ( V_5 -> V_13 -> type )
V_244 = V_5 -> V_13 -> type ( V_5 ) ;
if ( ! V_244 )
V_244 = L_7 ;
return V_244 ;
}
static void F_107 ( struct V_245 * V_246 , struct V_236 * V_237 , int V_247 )
{
struct V_6 * V_7 = V_237 -> V_7 + V_247 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
enum V_248 V_249 ;
struct V_1 * V_2 = V_7 -> V_1 ;
char V_250 [ 32 ] ;
unsigned int V_3 ;
int V_251 ;
if ( ! V_2 )
return;
V_251 = V_2 -> V_111 >= V_252 ;
F_108 ( V_246 , L_8 ,
V_2 -> line , F_106 ( V_2 ) ,
V_251 ? L_9 : L_10 ,
V_251 ? ( unsigned long long ) V_2 -> V_115
: ( unsigned long long ) V_2 -> V_100 ,
V_2 -> V_103 ) ;
if ( V_2 -> type == V_24 ) {
F_109 ( V_246 , '\n' ) ;
return;
}
if ( F_22 ( V_41 ) ) {
F_59 ( & V_5 -> V_116 ) ;
V_249 = V_7 -> V_249 ;
if ( V_249 != V_25 )
F_13 ( V_7 , V_25 ) ;
F_19 ( & V_2 -> V_12 ) ;
V_3 = V_2 -> V_13 -> V_38 ( V_2 ) ;
F_21 ( & V_2 -> V_12 ) ;
if ( V_249 != V_25 )
F_13 ( V_7 , V_249 ) ;
F_60 ( & V_5 -> V_116 ) ;
F_108 ( V_246 , L_11 ,
V_2 -> V_168 . V_181 , V_2 -> V_168 . V_180 ) ;
if ( V_2 -> V_168 . V_182 )
F_108 ( V_246 , L_12 ,
V_2 -> V_168 . V_182 ) ;
if ( V_2 -> V_168 . V_184 )
F_108 ( V_246 , L_13 ,
V_2 -> V_168 . V_184 ) ;
if ( V_2 -> V_168 . V_185 )
F_108 ( V_246 , L_14 ,
V_2 -> V_168 . V_185 ) ;
if ( V_2 -> V_168 . V_183 )
F_108 ( V_246 , L_15 ,
V_2 -> V_168 . V_183 ) ;
#define F_110 ( T_4 , V_244 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_111 ( T_4 , V_244 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_250 [ 0 ] = '\0' ;
V_250 [ 1 ] = '\0' ;
F_110 ( V_36 , L_16 ) ;
F_111 ( V_39 , L_17 ) ;
F_110 ( V_37 , L_18 ) ;
F_111 ( V_173 , L_19 ) ;
F_111 ( V_234 , L_20 ) ;
F_111 ( V_171 , L_21 ) ;
if ( V_250 [ 0 ] )
V_250 [ 0 ] = ' ' ;
F_112 ( V_246 , V_250 ) ;
}
F_109 ( V_246 , '\n' ) ;
#undef F_111
#undef F_110
}
static int F_113 ( struct V_245 * V_246 , void * V_253 )
{
struct V_254 * V_255 = V_246 -> V_256 ;
struct V_236 * V_237 = V_255 -> V_239 ;
int V_247 ;
F_108 ( V_246 , L_22 ,
L_23 , L_23 , L_23 ) ;
for ( V_247 = 0 ; V_247 < V_237 -> V_257 ; V_247 ++ )
F_107 ( V_246 , V_237 , V_247 ) ;
return 0 ;
}
static int F_114 ( struct V_258 * V_258 , struct V_219 * V_219 )
{
return F_115 ( V_219 , F_113 , F_116 ( V_258 ) ) ;
}
void F_117 ( struct V_1 * V_5 , const char * V_259 ,
unsigned int V_86 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_247 ;
for ( V_247 = 0 ; V_247 < V_86 ; V_247 ++ , V_259 ++ ) {
if ( * V_259 == '\n' )
putchar ( V_5 , '\r' ) ;
putchar ( V_5 , * V_259 ) ;
}
}
struct V_1 * T_5
F_118 ( struct V_1 * V_260 , int V_257 , struct V_261 * V_262 )
{
int V_263 = V_262 -> V_89 ;
if ( V_263 < 0 || V_263 >= V_257 || ( V_260 [ V_263 ] . V_100 == 0 &&
V_260 [ V_263 ] . V_264 == NULL ) )
for ( V_263 = 0 ; V_263 < V_257 ; V_263 ++ )
if ( V_260 [ V_263 ] . V_100 != 0 ||
V_260 [ V_263 ] . V_264 != NULL )
break;
V_262 -> V_89 = V_263 ;
return V_260 + V_263 ;
}
void
F_119 ( char * V_265 , int * V_48 , int * V_184 , int * V_49 , int * V_266 )
{
char * V_259 = V_265 ;
* V_48 = F_120 ( V_259 , NULL , 10 ) ;
while ( * V_259 >= '0' && * V_259 <= '9' )
V_259 ++ ;
if ( * V_259 )
* V_184 = * V_259 ++ ;
if ( * V_259 )
* V_49 = * V_259 ++ - '0' ;
if ( * V_259 )
* V_266 = * V_259 ;
}
int
F_121 ( struct V_1 * V_5 , struct V_261 * V_262 ,
int V_48 , int V_184 , int V_49 , int V_266 )
{
struct V_59 V_33 ;
static struct V_59 V_267 ;
int V_247 ;
if ( ! ( F_16 ( V_5 ) && ( V_5 -> V_31 -> V_11 & V_268 ) ) ) {
F_122 ( & V_5 -> V_12 ) ;
F_123 ( & V_5 -> V_12 , & V_269 ) ;
}
memset ( & V_33 , 0 , sizeof( struct V_59 ) ) ;
V_33 . V_34 = V_270 | V_46 | V_78 ;
for ( V_247 = 0 ; V_271 [ V_247 ] . V_272 ; V_247 ++ )
if ( V_271 [ V_247 ] . V_272 <= V_48 )
break;
V_33 . V_34 |= V_271 [ V_247 ] . V_32 ;
if ( V_49 == 7 )
V_33 . V_34 |= V_53 ;
else
V_33 . V_34 |= V_273 ;
switch ( V_184 ) {
case 'o' : case 'O' :
V_33 . V_34 |= V_274 ;
case 'e' : case 'E' :
V_33 . V_34 |= V_55 ;
break;
}
if ( V_266 == 'r' )
V_33 . V_34 |= V_76 ;
V_5 -> V_19 |= V_37 ;
V_5 -> V_13 -> V_75 ( V_5 , & V_33 , & V_267 ) ;
if ( V_262 )
V_262 -> V_32 = V_33 . V_34 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_7 ,
enum V_248 V_249 )
{
struct V_1 * V_5 = V_7 -> V_1 ;
if ( V_7 -> V_249 != V_249 ) {
if ( V_5 -> V_13 -> V_275 )
V_5 -> V_13 -> V_275 ( V_5 , V_249 , V_7 -> V_249 ) ;
V_7 -> V_249 = V_249 ;
}
}
static int F_124 ( struct V_276 * V_145 , void * V_277 )
{
struct V_278 * V_279 = V_277 ;
struct V_254 * V_280 = V_279 -> V_238 -> V_254 ;
T_6 V_281 = F_125 ( V_280 -> V_282 , V_280 -> V_283 ) +
V_279 -> V_5 -> line ;
return V_145 -> V_281 == V_281 ;
}
int F_126 ( struct V_236 * V_237 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_237 -> V_7 + V_2 -> line ;
struct V_42 * V_5 = & V_7 -> V_5 ;
struct V_276 * V_284 ;
struct V_278 V_279 = { V_2 , V_237 } ;
F_59 ( & V_5 -> V_116 ) ;
V_284 = F_127 ( V_2 -> V_145 , & V_279 , F_124 ) ;
if ( F_128 ( V_284 ) ) {
if ( ! F_129 ( V_2 -> V_103 ) )
V_2 -> V_285 = 1 ;
F_130 ( V_284 ) ;
F_60 ( & V_5 -> V_116 ) ;
return 0 ;
}
F_130 ( V_284 ) ;
if ( V_286 || ! F_16 ( V_2 ) )
V_2 -> V_287 = 1 ;
if ( V_5 -> V_11 & V_43 ) {
const struct V_288 * V_13 = V_2 -> V_13 ;
int V_289 ;
if ( V_286 || ! F_16 ( V_2 ) ) {
F_24 ( V_47 , & V_5 -> V_11 ) ;
F_25 ( V_45 , & V_5 -> V_11 ) ;
F_19 ( & V_2 -> V_12 ) ;
V_13 -> V_14 ( V_2 ) ;
V_13 -> V_20 ( V_2 , 0 ) ;
V_13 -> V_221 ( V_2 ) ;
F_21 ( & V_2 -> V_12 ) ;
}
for ( V_289 = 3 ; ! V_13 -> V_152 ( V_2 ) && V_289 ; V_289 -- )
F_131 ( 10 ) ;
if ( ! V_289 )
F_132 ( V_2 -> V_145 , L_24 ,
V_237 -> V_290 ,
V_237 -> V_254 -> V_291 + V_2 -> line ) ;
if ( V_286 || ! F_16 ( V_2 ) )
V_13 -> V_233 ( V_2 ) ;
}
if ( V_286 && F_16 ( V_2 ) )
F_133 ( V_2 -> V_31 ) ;
if ( V_286 || ! F_16 ( V_2 ) )
F_13 ( V_7 , V_224 ) ;
F_60 ( & V_5 -> V_116 ) ;
return 0 ;
}
int F_134 ( struct V_236 * V_237 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_237 -> V_7 + V_2 -> line ;
struct V_42 * V_5 = & V_7 -> V_5 ;
struct V_276 * V_284 ;
struct V_278 V_279 = { V_2 , V_237 } ;
struct V_59 V_33 ;
F_59 ( & V_5 -> V_116 ) ;
V_284 = F_127 ( V_2 -> V_145 , & V_279 , F_124 ) ;
if ( ! V_2 -> V_287 && F_128 ( V_284 ) ) {
if ( V_2 -> V_285 ) {
F_135 ( V_2 -> V_103 ) ;
V_2 -> V_285 = 0 ;
}
F_130 ( V_284 ) ;
F_60 ( & V_5 -> V_116 ) ;
return 0 ;
}
F_130 ( V_284 ) ;
V_2 -> V_287 = 0 ;
if ( F_16 ( V_2 ) ) {
memset ( & V_33 , 0 , sizeof( struct V_59 ) ) ;
V_33 . V_34 = V_2 -> V_31 -> V_32 ;
if ( V_5 -> V_8 && V_33 . V_34 == 0 )
V_33 = V_5 -> V_8 -> V_33 ;
if ( V_286 )
F_13 ( V_7 , V_25 ) ;
V_2 -> V_13 -> V_75 ( V_2 , & V_33 , NULL ) ;
if ( V_286 )
F_136 ( V_2 -> V_31 ) ;
}
if ( V_5 -> V_11 & V_292 ) {
const struct V_288 * V_13 = V_2 -> V_13 ;
int V_82 ;
F_13 ( V_7 , V_25 ) ;
F_19 ( & V_2 -> V_12 ) ;
V_13 -> V_20 ( V_2 , 0 ) ;
F_21 ( & V_2 -> V_12 ) ;
if ( V_286 || ! F_16 ( V_2 ) ) {
struct V_9 * V_8 = V_5 -> V_8 ;
V_82 = V_13 -> V_30 ( V_2 ) ;
if ( V_82 == 0 ) {
if ( V_8 )
F_17 ( V_8 , V_7 , NULL ) ;
F_19 ( & V_2 -> V_12 ) ;
V_13 -> V_20 ( V_2 , V_2 -> V_19 ) ;
V_13 -> V_15 ( V_2 ) ;
F_21 ( & V_2 -> V_12 ) ;
F_24 ( V_45 , & V_5 -> V_11 ) ;
} else {
F_26 ( V_8 , V_7 ) ;
}
}
F_25 ( V_47 , & V_5 -> V_11 ) ;
}
F_60 ( & V_5 -> V_116 ) ;
return 0 ;
}
static inline void
F_137 ( struct V_236 * V_237 , struct V_1 * V_5 )
{
char V_293 [ 64 ] ;
switch ( V_5 -> V_111 ) {
case V_294 :
snprintf ( V_293 , sizeof( V_293 ) , L_25 , V_5 -> V_100 ) ;
break;
case V_295 :
snprintf ( V_293 , sizeof( V_293 ) ,
L_26 , V_5 -> V_100 , V_5 -> V_109 ) ;
break;
case V_252 :
case V_296 :
case V_297 :
case V_298 :
snprintf ( V_293 , sizeof( V_293 ) ,
L_27 , ( unsigned long long ) V_5 -> V_115 ) ;
break;
default:
F_138 ( V_293 , L_28 , sizeof( V_293 ) ) ;
break;
}
F_139 ( V_5 -> V_145 , L_29 ,
V_237 -> V_290 ,
V_237 -> V_254 -> V_291 + V_5 -> line ,
V_293 , V_5 -> V_103 , V_5 -> V_73 / 16 , F_106 ( V_5 ) ) ;
}
static void
F_140 ( struct V_236 * V_237 , struct V_6 * V_7 ,
struct V_1 * V_5 )
{
unsigned int V_11 ;
if ( ! V_5 -> V_100 && ! V_5 -> V_115 && ! V_5 -> V_264 )
return;
V_11 = 0 ;
if ( V_5 -> V_11 & V_159 )
V_11 |= V_160 ;
if ( V_5 -> V_11 & V_299 ) {
if ( ! ( V_5 -> V_11 & V_300 ) ) {
V_5 -> type = V_24 ;
V_11 |= V_158 ;
}
V_5 -> V_13 -> V_161 ( V_5 , V_11 ) ;
}
if ( V_5 -> type != V_24 ) {
unsigned long V_11 ;
F_137 ( V_237 , V_5 ) ;
F_13 ( V_7 , V_25 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_5 -> V_13 -> V_20 ( V_5 , V_5 -> V_19 & V_37 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
if ( V_5 -> V_31 && ! ( V_5 -> V_31 -> V_11 & V_268 ) )
F_141 ( V_5 -> V_31 ) ;
if ( ! F_16 ( V_5 ) )
F_13 ( V_7 , V_224 ) ;
}
}
static int F_142 ( struct V_254 * V_238 , int line , char * V_265 )
{
struct V_236 * V_237 = V_238 -> V_239 ;
struct V_6 * V_7 = V_237 -> V_7 + line ;
struct V_1 * V_5 ;
int V_48 = 9600 ;
int V_49 = 8 ;
int V_184 = 'n' ;
int V_266 = 'n' ;
int V_82 ;
if ( ! V_7 || ! V_7 -> V_1 )
return - 1 ;
V_5 = V_7 -> V_1 ;
if ( ! ( V_5 -> V_13 -> V_301 && V_5 -> V_13 -> V_302 ) )
return - 1 ;
if ( V_5 -> V_13 -> V_303 ) {
struct V_42 * V_304 = & V_7 -> V_5 ;
V_82 = 0 ;
F_59 ( & V_304 -> V_116 ) ;
if ( ! F_90 ( V_45 , & V_304 -> V_11 ) )
V_82 = V_5 -> V_13 -> V_303 ( V_5 ) ;
F_60 ( & V_304 -> V_116 ) ;
if ( V_82 )
return V_82 ;
}
if ( V_265 ) {
F_119 ( V_265 , & V_48 , & V_184 , & V_49 , & V_266 ) ;
return F_121 ( V_5 , NULL , V_48 , V_184 , V_49 , V_266 ) ;
}
return 0 ;
}
static int F_143 ( struct V_254 * V_238 , int line )
{
struct V_236 * V_237 = V_238 -> V_239 ;
struct V_6 * V_7 = V_237 -> V_7 + line ;
struct V_1 * V_5 ;
if ( ! V_7 || ! V_7 -> V_1 )
return - 1 ;
V_5 = V_7 -> V_1 ;
return V_5 -> V_13 -> V_301 ( V_5 ) ;
}
static void F_144 ( struct V_254 * V_238 , int line , char V_85 )
{
struct V_236 * V_237 = V_238 -> V_239 ;
struct V_6 * V_7 = V_237 -> V_7 + line ;
struct V_1 * V_5 ;
if ( ! V_7 || ! V_7 -> V_1 )
return;
V_5 = V_7 -> V_1 ;
if ( V_85 == '\n' )
V_5 -> V_13 -> V_302 ( V_5 , '\r' ) ;
V_5 -> V_13 -> V_302 ( V_5 , V_85 ) ;
}
int F_145 ( struct V_236 * V_237 )
{
struct V_254 * V_305 ;
int V_247 , V_23 ;
F_3 ( V_237 -> V_7 ) ;
V_237 -> V_7 = F_146 ( sizeof( struct V_6 ) * V_237 -> V_257 , V_28 ) ;
if ( ! V_237 -> V_7 )
goto V_195;
V_305 = F_147 ( V_237 -> V_257 ) ;
if ( ! V_305 )
goto V_306;
V_237 -> V_254 = V_305 ;
V_305 -> V_307 = V_237 -> V_307 ;
V_305 -> V_308 = V_237 -> V_290 ;
V_305 -> V_282 = V_237 -> V_282 ;
V_305 -> V_283 = V_237 -> V_309 ;
V_305 -> type = V_310 ;
V_305 -> V_311 = V_312 ;
V_305 -> V_313 = V_314 ;
V_305 -> V_313 . V_34 = V_315 | V_273 | V_270 | V_46 | V_78 ;
V_305 -> V_313 . V_216 = V_305 -> V_313 . V_215 = 9600 ;
V_305 -> V_11 = V_316 | V_317 ;
V_305 -> V_239 = V_237 ;
F_148 ( V_305 , & V_288 ) ;
for ( V_247 = 0 ; V_247 < V_237 -> V_257 ; V_247 ++ ) {
struct V_6 * V_7 = V_237 -> V_7 + V_247 ;
struct V_42 * V_5 = & V_7 -> V_5 ;
F_149 ( V_5 ) ;
V_5 -> V_13 = & V_318 ;
V_5 -> V_106 = V_58 / 2 ;
V_5 -> V_107 = 30 * V_58 ;
}
V_23 = F_150 ( V_305 ) ;
if ( V_23 >= 0 )
return V_23 ;
for ( V_247 = 0 ; V_247 < V_237 -> V_257 ; V_247 ++ )
F_151 ( & V_237 -> V_7 [ V_247 ] . V_5 ) ;
F_152 ( V_305 ) ;
V_306:
F_153 ( V_237 -> V_7 ) ;
V_195:
return - V_29 ;
}
void F_154 ( struct V_236 * V_237 )
{
struct V_254 * V_319 = V_237 -> V_254 ;
unsigned int V_247 ;
F_155 ( V_319 ) ;
F_152 ( V_319 ) ;
for ( V_247 = 0 ; V_247 < V_237 -> V_257 ; V_247 ++ )
F_151 ( & V_237 -> V_7 [ V_247 ] . V_5 ) ;
F_153 ( V_237 -> V_7 ) ;
V_237 -> V_7 = NULL ;
V_237 -> V_254 = NULL ;
}
struct V_254 * F_156 ( struct V_261 * V_262 , int * V_89 )
{
struct V_236 * V_319 = V_262 -> V_277 ;
* V_89 = V_262 -> V_89 ;
return V_319 -> V_254 ;
}
static T_7 F_157 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . V_105 * 16 ) ;
}
static T_7 F_159 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . type ) ;
}
static T_7 F_160 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . line ) ;
}
static T_7 F_161 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
unsigned long V_323 ;
F_58 ( V_5 , & V_117 ) ;
V_323 = V_117 . V_5 ;
if ( V_101 )
V_323 |= ( unsigned long ) V_117 . V_102 << V_101 ;
return snprintf ( V_27 , V_322 , L_31 , V_323 ) ;
}
static T_7 F_162 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . V_103 ) ;
}
static T_7 F_163 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_32 , V_117 . V_11 ) ;
}
static T_7 F_164 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . V_104 ) ;
}
static T_7 F_165 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . V_106 ) ;
}
static T_7 F_166 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . V_107 ) ;
}
static T_7 F_167 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . V_72 ) ;
}
static T_7 F_168 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . V_110 ) ;
}
static T_7 F_169 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_31 , ( unsigned long ) V_117 . V_114 ) ;
}
static T_7 F_170 ( struct V_276 * V_145 ,
struct V_320 * V_321 , char * V_27 )
{
struct V_98 V_117 ;
struct V_42 * V_5 = F_158 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_322 , L_30 , V_117 . V_112 ) ;
}
int F_171 ( struct V_236 * V_237 , struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_42 * V_5 ;
int V_82 = 0 ;
struct V_276 * V_284 ;
int V_324 ;
F_3 ( F_172 () ) ;
if ( V_2 -> line >= V_237 -> V_257 )
return - V_132 ;
V_7 = V_237 -> V_7 + V_2 -> line ;
V_5 = & V_7 -> V_5 ;
F_59 ( & V_325 ) ;
F_59 ( & V_5 -> V_116 ) ;
if ( V_7 -> V_1 ) {
V_82 = - V_132 ;
goto V_195;
}
V_7 -> V_1 = V_2 ;
V_7 -> V_249 = V_326 ;
V_2 -> V_31 = V_237 -> V_31 ;
V_2 -> V_7 = V_7 ;
if ( ! ( F_16 ( V_2 ) && ( V_2 -> V_31 -> V_11 & V_268 ) ) ) {
F_122 ( & V_2 -> V_12 ) ;
F_123 ( & V_2 -> V_12 , & V_269 ) ;
}
if ( V_2 -> V_31 && V_2 -> V_145 )
F_173 ( V_2 -> V_145 -> V_327 , V_2 -> V_31 -> V_308 , V_2 -> line ) ;
F_140 ( V_237 , V_7 , V_2 ) ;
V_324 = 2 ;
if ( V_2 -> V_328 )
V_324 ++ ;
V_2 -> V_329 = F_174 ( V_324 , sizeof( * V_2 -> V_329 ) ,
V_28 ) ;
if ( ! V_2 -> V_329 ) {
V_82 = - V_29 ;
goto V_195;
}
V_2 -> V_329 [ 0 ] = & V_330 ;
if ( V_2 -> V_328 )
V_2 -> V_329 [ 1 ] = V_2 -> V_328 ;
V_284 = F_175 ( V_5 , V_237 -> V_254 ,
V_2 -> line , V_2 -> V_145 , V_5 , V_2 -> V_329 ) ;
if ( F_176 ( ! F_177 ( V_284 ) ) ) {
F_178 ( V_284 , 1 ) ;
} else {
F_132 ( V_2 -> V_145 , L_33 ,
V_2 -> line ) ;
}
V_2 -> V_11 &= ~ V_241 ;
V_195:
F_60 ( & V_5 -> V_116 ) ;
F_60 ( & V_325 ) ;
return V_82 ;
}
int F_179 ( struct V_236 * V_237 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_237 -> V_7 + V_2 -> line ;
struct V_42 * V_5 = & V_7 -> V_5 ;
struct V_9 * V_8 ;
int V_82 = 0 ;
F_3 ( F_172 () ) ;
if ( V_7 -> V_1 != V_2 )
F_180 ( V_2 -> V_145 , L_34 ,
V_7 -> V_1 , V_2 ) ;
F_59 ( & V_325 ) ;
F_59 ( & V_5 -> V_116 ) ;
if ( ! V_7 -> V_1 ) {
F_60 ( & V_5 -> V_116 ) ;
V_82 = - V_132 ;
goto V_195;
}
V_2 -> V_11 |= V_241 ;
F_60 ( & V_5 -> V_116 ) ;
F_181 ( V_237 -> V_254 , V_2 -> line ) ;
V_8 = F_182 ( V_5 ) ;
if ( V_8 ) {
F_183 ( V_5 -> V_8 ) ;
F_184 ( V_8 ) ;
}
if ( F_16 ( V_2 ) )
F_185 ( V_2 -> V_31 ) ;
if ( V_2 -> type != V_24 )
V_2 -> V_13 -> V_140 ( V_2 ) ;
F_153 ( V_2 -> V_329 ) ;
V_2 -> type = V_24 ;
V_7 -> V_1 = NULL ;
V_195:
F_60 ( & V_325 ) ;
return V_82 ;
}
int F_186 ( struct V_1 * V_331 , struct V_1 * V_332 )
{
if ( V_331 -> V_111 != V_332 -> V_111 )
return 0 ;
switch ( V_331 -> V_111 ) {
case V_294 :
return ( V_331 -> V_100 == V_332 -> V_100 ) ;
case V_295 :
return ( V_331 -> V_100 == V_332 -> V_100 ) &&
( V_331 -> V_109 == V_332 -> V_109 ) ;
case V_252 :
case V_296 :
case V_297 :
case V_298 :
return ( V_331 -> V_115 == V_332 -> V_115 ) ;
}
return 0 ;
}
void F_187 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_42 * V_5 = & V_2 -> V_7 -> V_5 ;
struct V_9 * V_8 = V_5 -> V_8 ;
struct V_333 * V_334 ;
F_188 ( & V_2 -> V_12 ) ;
if ( V_8 ) {
V_334 = F_189 ( V_8 ) ;
if ( V_334 ) {
if ( V_334 -> V_13 -> V_335 )
V_334 -> V_13 -> V_335 ( V_8 , V_3 ) ;
F_190 ( V_334 ) ;
}
}
V_2 -> V_168 . V_176 ++ ;
if ( F_1 ( V_2 ) ) {
if ( V_3 )
F_97 ( & V_5 -> V_227 ) ;
else if ( V_8 )
F_191 ( V_8 ) ;
}
}
void F_192 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_188 ( & V_2 -> V_12 ) ;
V_2 -> V_168 . V_177 ++ ;
if ( F_20 ( V_2 ) ) {
if ( V_2 -> V_40 ) {
if ( V_3 ) {
V_2 -> V_40 = 0 ;
V_2 -> V_13 -> V_15 ( V_2 ) ;
F_2 ( V_2 ) ;
}
} else {
if ( ! V_3 ) {
V_2 -> V_40 = 1 ;
V_2 -> V_13 -> V_14 ( V_2 ) ;
}
}
}
}
void F_193 ( struct V_1 * V_5 , unsigned int V_3 ,
unsigned int V_183 , unsigned int V_85 , unsigned int V_336 )
{
struct V_42 * V_304 = & V_5 -> V_7 -> V_5 ;
if ( ( V_3 & V_5 -> V_337 & ~ V_183 ) == 0 )
if ( F_194 ( V_304 , V_85 , V_336 ) == 0 )
++ V_5 -> V_168 . V_186 ;
if ( V_3 & ~ V_5 -> V_337 & V_183 )
if ( F_194 ( V_304 , 0 , V_338 ) == 0 )
++ V_5 -> V_168 . V_186 ;
}
