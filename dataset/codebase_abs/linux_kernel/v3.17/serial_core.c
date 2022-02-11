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
if ( F_17 ( V_2 ) &&
! ( V_21 -> V_8 & V_39 ) ) {
F_18 ( & V_21 -> V_9 ) ;
if ( ! ( V_21 -> V_10 -> V_40 ( V_21 ) & V_41 ) )
V_5 -> V_13 = 1 ;
F_19 ( & V_21 -> V_9 ) ;
}
}
if ( V_24 && F_20 ( V_42 ) )
return 1 ;
return V_24 ;
}
static int F_21 ( struct V_6 * V_5 , struct V_3 * V_4 ,
int V_20 )
{
struct V_22 * V_2 = & V_4 -> V_2 ;
int V_24 ;
if ( V_2 -> V_8 & V_43 )
return 0 ;
F_22 ( V_44 , & V_5 -> V_8 ) ;
V_24 = F_10 ( V_5 , V_4 , V_20 ) ;
if ( ! V_24 ) {
F_22 ( V_45 , & V_2 -> V_8 ) ;
F_23 ( V_44 , & V_5 -> V_8 ) ;
} else if ( V_24 > 0 )
V_24 = 0 ;
return V_24 ;
}
static void F_24 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_21 = V_4 -> V_1 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
if ( V_5 )
F_22 ( V_44 , & V_5 -> V_8 ) ;
if ( F_25 ( V_45 , & V_2 -> V_8 ) ) {
if ( F_14 ( V_21 ) && V_5 )
V_21 -> V_32 -> V_33 = V_5 -> V_34 . V_35 ;
if ( ! V_5 || ( V_5 -> V_34 . V_35 & V_46 ) )
F_26 ( V_21 , V_38 | V_37 ) ;
F_27 ( V_2 ) ;
}
F_23 ( V_47 , & V_2 -> V_8 ) ;
if ( V_4 -> V_27 . V_28 ) {
F_28 ( ( unsigned long ) V_4 -> V_27 . V_28 ) ;
V_4 -> V_27 . V_28 = NULL ;
}
}
void
F_29 ( struct V_1 * V_2 , unsigned int V_33 ,
unsigned int V_48 )
{
unsigned int V_49 ;
switch ( V_33 & V_50 ) {
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
if ( V_33 & V_54 )
V_49 ++ ;
if ( V_33 & V_55 )
V_49 ++ ;
V_49 = V_49 * V_2 -> V_56 ;
V_2 -> V_57 = ( V_58 * V_49 ) / V_48 + V_58 / 50 ;
}
unsigned int
F_30 ( struct V_1 * V_2 , struct V_59 * V_34 ,
struct V_59 * V_17 , unsigned int V_60 , unsigned int V_61 )
{
unsigned int V_62 , V_48 , V_63 = 38400 ;
int V_64 = 0 ;
T_1 V_8 = V_2 -> V_8 & V_65 ;
if ( V_8 == V_66 )
V_63 = 57600 ;
else if ( V_8 == V_67 )
V_63 = 115200 ;
else if ( V_8 == V_68 )
V_63 = 230400 ;
else if ( V_8 == V_69 )
V_63 = 460800 ;
for ( V_62 = 0 ; V_62 < 2 ; V_62 ++ ) {
V_48 = F_31 ( V_34 ) ;
if ( V_48 == 38400 )
V_48 = V_63 ;
if ( V_48 == 0 ) {
V_64 = 1 ;
V_48 = 9600 ;
}
if ( V_48 >= V_60 && V_48 <= V_61 )
return V_48 ;
V_34 -> V_35 &= ~ V_36 ;
if ( V_17 ) {
V_48 = F_31 ( V_17 ) ;
if ( ! V_64 )
F_32 ( V_34 ,
V_48 , V_48 ) ;
V_17 = NULL ;
continue;
}
if ( ! V_64 ) {
if ( V_48 <= V_60 )
F_32 ( V_34 ,
V_60 + 1 , V_60 + 1 ) ;
else
F_32 ( V_34 ,
V_61 - 1 , V_61 - 1 ) ;
}
}
F_33 ( 1 ) ;
return 0 ;
}
unsigned int
F_34 ( struct V_1 * V_2 , unsigned int V_48 )
{
unsigned int V_70 ;
if ( V_48 == 38400 && ( V_2 -> V_8 & V_65 ) == V_71 )
V_70 = V_2 -> V_72 ;
else
V_70 = F_35 ( V_2 -> V_73 , 16 * V_48 ) ;
return V_70 ;
}
static void F_15 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_59 * V_74 )
{
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_21 = V_4 -> V_1 ;
struct V_59 * V_34 ;
if ( ! V_5 || V_21 -> type == V_25 )
return;
V_34 = & V_5 -> V_34 ;
V_21 -> V_10 -> V_75 ( V_21 , V_34 , V_74 ) ;
if ( V_34 -> V_35 & V_76 )
F_22 ( V_77 , & V_2 -> V_8 ) ;
else
F_23 ( V_77 , & V_2 -> V_8 ) ;
if ( V_34 -> V_35 & V_78 )
F_23 ( V_79 , & V_2 -> V_8 ) ;
else
F_22 ( V_79 , & V_2 -> V_8 ) ;
}
static inline int F_36 ( struct V_1 * V_2 ,
struct V_80 * V_81 , unsigned char V_82 )
{
unsigned long V_8 ;
int V_83 = 0 ;
if ( ! V_81 -> V_28 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
if ( F_37 ( V_81 ) != 0 ) {
V_81 -> V_28 [ V_81 -> V_84 ] = V_82 ;
V_81 -> V_84 = ( V_81 -> V_84 + 1 ) & ( V_85 - 1 ) ;
V_83 = 1 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
return V_83 ;
}
static int F_38 ( struct V_6 * V_5 , unsigned char V_86 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
return F_36 ( V_4 -> V_1 , & V_4 -> V_27 , V_86 ) ;
}
static void F_39 ( struct V_6 * V_5 )
{
F_8 ( V_5 ) ;
}
static int F_40 ( struct V_6 * V_5 ,
const unsigned char * V_28 , int V_87 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 ;
struct V_80 * V_81 ;
unsigned long V_8 ;
int V_82 , V_83 = 0 ;
if ( ! V_4 ) {
F_33 ( 1 ) ;
return - V_88 ;
}
V_2 = V_4 -> V_1 ;
V_81 = & V_4 -> V_27 ;
if ( ! V_81 -> V_28 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
while ( 1 ) {
V_82 = F_41 ( V_81 -> V_84 , V_81 -> V_89 , V_85 ) ;
if ( V_87 < V_82 )
V_82 = V_87 ;
if ( V_82 <= 0 )
break;
memcpy ( V_81 -> V_28 + V_81 -> V_84 , V_28 , V_82 ) ;
V_81 -> V_84 = ( V_81 -> V_84 + V_82 ) & ( V_85 - 1 ) ;
V_28 += V_82 ;
V_87 -= V_82 ;
V_83 += V_82 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_8 ( V_5 ) ;
return V_83 ;
}
static int F_42 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_83 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_83 = F_37 ( & V_4 -> V_27 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_83 ;
}
static int F_43 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_83 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_83 = F_44 ( & V_4 -> V_27 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_83 ;
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
F_46 ( L_1 , V_5 -> V_90 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
F_13 ( & V_4 -> V_27 ) ;
if ( V_2 -> V_10 -> V_91 )
V_2 -> V_10 -> V_91 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_3 ( V_5 ) ;
}
static void F_47 ( struct V_6 * V_5 , char V_86 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_8 ;
if ( V_2 -> V_10 -> V_92 )
V_2 -> V_10 -> V_92 ( V_2 , V_86 ) ;
else {
V_2 -> V_93 = V_86 ;
if ( V_86 ) {
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
T_2 V_94 = 0 ;
if ( F_49 ( V_5 ) )
V_94 |= V_95 ;
if ( V_5 -> V_34 . V_35 & V_76 )
V_94 |= V_39 ;
if ( V_2 -> V_8 & V_94 ) {
V_2 -> V_10 -> V_96 ( V_2 ) ;
V_94 &= ~ V_2 -> V_8 ;
}
if ( V_94 & V_95 )
F_47 ( V_5 , F_50 ( V_5 ) ) ;
if ( V_94 & V_39 )
F_26 ( V_2 , V_37 ) ;
}
static void F_51 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
T_2 V_94 = 0 ;
if ( F_49 ( V_5 ) )
V_94 |= V_95 ;
if ( V_5 -> V_34 . V_35 & V_76 )
V_94 |= V_39 ;
if ( V_2 -> V_8 & V_94 ) {
V_2 -> V_10 -> V_97 ( V_2 ) ;
V_94 &= ~ V_2 -> V_8 ;
}
if ( V_94 & V_95 ) {
if ( V_2 -> V_93 )
V_2 -> V_93 = 0 ;
else
F_47 ( V_5 , F_52 ( V_5 ) ) ;
}
if ( V_94 & V_39 )
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
V_99 -> V_104 = V_21 -> V_56 ;
V_99 -> V_105 = V_21 -> V_73 / 16 ;
V_99 -> V_106 = F_55 ( V_2 -> V_106 ) / 10 ;
V_99 -> V_107 = V_2 -> V_107 == V_108 ?
V_108 :
F_55 ( V_2 -> V_107 ) / 10 ;
V_99 -> V_72 = V_21 -> V_72 ;
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
V_123 = V_21 -> V_72 ;
if ( ! F_20 ( V_42 ) ) {
V_24 = - V_127 ;
if ( V_121 || V_122 ||
( V_119 -> V_105 != V_21 -> V_73 / 16 ) ||
( V_106 != V_2 -> V_106 ) ||
( V_107 != V_2 -> V_107 ) ||
( V_119 -> V_104 &&
V_119 -> V_104 != V_21 -> V_56 ) ||
( ( ( V_125 ^ V_124 ) & ~ V_128 ) != 0 ) )
goto exit;
V_21 -> V_8 = ( ( V_21 -> V_8 & ~ V_128 ) |
( V_125 & V_128 ) ) ;
V_21 -> V_72 = V_119 -> V_72 ;
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
V_21 -> V_73 = V_119 -> V_105 * 16 ;
V_21 -> V_8 = ( V_21 -> V_8 & ~ V_142 ) |
( V_125 & V_142 ) ;
V_21 -> V_72 = V_119 -> V_72 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_107 = V_107 ;
if ( V_119 -> V_104 )
V_21 -> V_56 = V_119 -> V_104 ;
V_2 -> V_143 = ( V_21 -> V_8 & V_144 ) ? 1 : 0 ;
V_129:
V_24 = 0 ;
if ( V_21 -> type == V_25 )
goto exit;
if ( V_2 -> V_8 & V_43 ) {
if ( ( ( V_124 ^ V_21 -> V_8 ) & V_65 ) ||
V_123 != V_21 -> V_72 ) {
if ( V_21 -> V_8 & V_65 ) {
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
if ( V_21 -> V_93 ||
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
if ( ! ( V_5 -> V_8 & ( 1 << V_44 ) ) ) {
V_151 = V_21 -> V_18 ;
F_18 ( & V_21 -> V_9 ) ;
V_151 |= V_21 -> V_10 -> V_40 ( V_21 ) ;
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
int V_83 = - V_154 ;
F_57 ( & V_2 -> V_116 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_44 ) ) ) {
F_9 ( V_21 , V_15 , V_16 ) ;
V_83 = 0 ;
}
F_58 ( & V_2 -> V_116 ) ;
return V_83 ;
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
int V_8 , V_83 ;
if ( ! F_20 ( V_42 ) )
return - V_127 ;
if ( F_75 ( & V_2 -> V_116 ) )
return - V_157 ;
V_83 = - V_133 ;
if ( F_64 ( V_2 ) == 1 ) {
F_24 ( V_5 , V_4 ) ;
if ( V_21 -> type != V_25 )
V_21 -> V_10 -> V_140 ( V_21 ) ;
V_8 = V_158 ;
if ( V_21 -> V_8 & V_159 )
V_8 |= V_160 ;
V_21 -> V_10 -> V_161 ( V_21 , V_8 ) ;
V_83 = F_21 ( V_5 , V_4 , 1 ) ;
}
F_58 ( & V_2 -> V_116 ) ;
return V_83 ;
}
static void F_76 ( struct V_1 * V_21 )
{
if ( V_21 -> V_10 -> V_162 )
V_21 -> V_10 -> V_162 ( V_21 ) ;
}
static int
F_77 ( struct V_3 * V_4 , unsigned long V_163 )
{
struct V_1 * V_21 = V_4 -> V_1 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
F_78 ( V_164 , V_146 ) ;
struct V_165 V_166 , V_167 ;
int V_83 ;
F_18 ( & V_21 -> V_9 ) ;
memcpy ( & V_166 , & V_21 -> V_168 , sizeof( struct V_165 ) ) ;
F_76 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
F_79 ( & V_2 -> V_169 , & V_164 ) ;
for (; ; ) {
F_18 ( & V_21 -> V_9 ) ;
memcpy ( & V_167 , & V_21 -> V_168 , sizeof( struct V_165 ) ) ;
F_19 ( & V_21 -> V_9 ) ;
F_80 ( V_170 ) ;
if ( ( ( V_163 & V_171 ) && ( V_167 . V_172 != V_166 . V_172 ) ) ||
( ( V_163 & V_173 ) && ( V_167 . V_174 != V_166 . V_174 ) ) ||
( ( V_163 & V_175 ) && ( V_167 . V_176 != V_166 . V_176 ) ) ||
( ( V_163 & V_41 ) && ( V_167 . V_177 != V_166 . V_177 ) ) ) {
V_83 = 0 ;
break;
}
F_81 () ;
if ( F_82 ( V_146 ) ) {
V_83 = - V_157 ;
break;
}
V_166 = V_167 ;
}
V_146 -> V_4 = V_178 ;
F_83 ( & V_2 -> V_169 , & V_164 ) ;
return V_83 ;
}
static int F_84 ( struct V_6 * V_5 ,
struct V_179 * V_168 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_165 V_167 ;
struct V_1 * V_21 = V_4 -> V_1 ;
F_18 ( & V_21 -> V_9 ) ;
memcpy ( & V_167 , & V_21 -> V_168 , sizeof( struct V_165 ) ) ;
F_19 ( & V_21 -> V_9 ) ;
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
F_85 ( struct V_6 * V_5 , unsigned int V_187 ,
unsigned long V_163 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
void T_3 * V_188 = ( void T_3 * ) V_163 ;
int V_83 = - V_189 ;
switch ( V_187 ) {
case V_190 :
V_83 = F_59 ( V_2 , V_188 ) ;
break;
case V_191 :
V_83 = F_67 ( V_5 , V_4 , V_188 ) ;
break;
case V_192 :
V_83 = F_74 ( V_5 , V_4 ) ;
break;
case V_193 :
case V_194 :
V_83 = 0 ;
break;
}
if ( V_83 != - V_189 )
goto V_195;
if ( V_5 -> V_8 & ( 1 << V_44 ) ) {
V_83 = - V_154 ;
goto V_195;
}
switch ( V_187 ) {
case V_196 :
V_83 = F_77 ( V_4 , V_163 ) ;
break;
}
if ( V_83 != - V_189 )
goto V_195;
F_57 ( & V_2 -> V_116 ) ;
if ( V_5 -> V_8 & ( 1 << V_44 ) ) {
V_83 = - V_154 ;
goto V_197;
}
switch ( V_187 ) {
case V_198 :
V_83 = F_69 ( V_5 , V_4 , V_188 ) ;
break;
default: {
struct V_1 * V_21 = V_4 -> V_1 ;
if ( V_21 -> V_10 -> V_199 )
V_83 = V_21 -> V_10 -> V_199 ( V_21 , V_187 , V_163 ) ;
break;
}
}
V_197:
F_58 ( & V_2 -> V_116 ) ;
V_195:
return V_83 ;
}
static void F_86 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_21 = V_4 -> V_1 ;
if ( V_21 -> V_10 -> V_200 )
V_21 -> V_10 -> V_200 ( V_21 , V_5 -> V_34 . V_201 ) ;
}
static void F_87 ( struct V_6 * V_5 ,
struct V_59 * V_74 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_21 = V_4 -> V_1 ;
unsigned long V_8 ;
unsigned int V_33 = V_5 -> V_34 . V_35 ;
unsigned int V_202 = V_203 | V_204 | V_205 | V_206 | V_207 ;
bool V_208 = false ;
if ( V_21 -> V_8 & V_95 ) {
V_202 |= V_209 | V_210 | V_211 ;
V_208 =
V_5 -> V_34 . V_212 [ V_213 ] != V_74 -> V_212 [ V_213 ] ||
V_5 -> V_34 . V_212 [ V_214 ] != V_74 -> V_212 [ V_214 ] ;
}
if ( ( V_33 ^ V_74 -> V_35 ) == 0 &&
V_5 -> V_34 . V_215 == V_74 -> V_215 &&
V_5 -> V_34 . V_216 == V_74 -> V_216 &&
( ( V_5 -> V_34 . V_217 ^ V_74 -> V_217 ) & V_202 ) == 0 &&
! V_208 ) {
return;
}
F_15 ( V_5 , V_4 , V_74 ) ;
V_33 = V_5 -> V_34 . V_35 ;
if ( ( V_74 -> V_35 & V_36 ) && ! ( V_33 & V_36 ) )
F_26 ( V_21 , V_37 | V_38 ) ;
else if ( ! ( V_74 -> V_35 & V_36 ) && ( V_33 & V_36 ) ) {
unsigned int V_94 = V_38 ;
if ( ! ( V_33 & V_76 ) ||
! F_88 ( V_218 , & V_5 -> V_8 ) )
V_94 |= V_37 ;
F_16 ( V_21 , V_94 ) ;
}
if ( V_21 -> V_8 & V_39 )
return;
if ( ( V_74 -> V_35 & V_76 ) && ! ( V_33 & V_76 ) ) {
F_5 ( & V_21 -> V_9 , V_8 ) ;
V_5 -> V_13 = 0 ;
F_7 ( V_5 ) ;
F_6 ( & V_21 -> V_9 , V_8 ) ;
}
else if ( ! ( V_74 -> V_35 & V_76 ) && ( V_33 & V_76 ) ) {
F_5 ( & V_21 -> V_9 , V_8 ) ;
if ( ! ( V_21 -> V_10 -> V_40 ( V_21 ) & V_41 ) ) {
V_5 -> V_13 = 1 ;
V_21 -> V_10 -> V_11 ( V_21 ) ;
}
F_6 ( & V_21 -> V_9 , V_8 ) ;
}
}
static void F_89 ( struct V_6 * V_5 , struct V_219 * V_220 )
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
if ( ! V_2 -> V_87 || F_90 ( V_2 , V_5 , V_220 ) == 0 )
return;
if ( V_2 -> V_8 & V_43 ) {
unsigned long V_8 ;
F_5 ( & V_21 -> V_9 , V_8 ) ;
V_21 -> V_10 -> V_221 ( V_21 ) ;
F_6 ( & V_21 -> V_9 , V_8 ) ;
F_91 ( V_5 , V_21 -> V_57 ) ;
}
F_57 ( & V_2 -> V_116 ) ;
F_24 ( V_5 , V_4 ) ;
F_45 ( V_5 ) ;
F_92 ( V_5 ) ;
F_93 ( V_2 , NULL ) ;
V_5 -> V_222 = 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_223 ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_106 )
F_94 (
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
F_95 ( & V_2 -> V_227 ) ;
F_95 ( & V_2 -> V_228 ) ;
F_58 ( & V_2 -> V_116 ) ;
}
static void F_91 ( struct V_6 * V_5 , int V_57 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_229 , V_230 ;
if ( V_2 -> type == V_25 || V_2 -> V_56 == 0 )
return;
V_229 = ( V_2 -> V_57 - V_58 / 50 ) / V_2 -> V_56 ;
V_229 = V_229 / 5 ;
if ( V_229 == 0 )
V_229 = 1 ;
if ( V_57 && V_57 < V_229 )
V_229 = V_57 ;
if ( V_57 == 0 || V_57 > 2 * V_2 -> V_57 )
V_57 = 2 * V_2 -> V_57 ;
V_230 = V_231 + V_57 ;
F_46 ( L_5 ,
V_2 -> line , V_231 , V_230 ) ;
while ( ! V_2 -> V_10 -> V_152 ( V_2 ) ) {
F_94 ( F_55 ( V_229 ) ) ;
if ( F_82 ( V_146 ) )
break;
if ( F_96 ( V_231 , V_230 ) )
break;
}
}
static void F_97 ( struct V_6 * V_5 )
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
V_2 -> V_87 = 0 ;
F_23 ( V_225 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_93 ( V_2 , NULL ) ;
if ( ! F_14 ( V_4 -> V_1 ) )
F_11 ( V_4 , V_224 ) ;
F_95 ( & V_2 -> V_227 ) ;
F_95 ( & V_2 -> V_169 ) ;
}
F_58 ( & V_2 -> V_116 ) ;
}
static int F_98 ( struct V_22 * V_2 , struct V_6 * V_5 )
{
return 0 ;
}
static void F_27 ( struct V_22 * V_2 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_21 = V_4 -> V_1 ;
F_95 ( & V_2 -> V_169 ) ;
V_21 -> V_10 -> V_233 ( V_21 ) ;
F_99 ( V_21 -> V_103 ) ;
}
static int F_100 ( struct V_22 * V_2 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_21 = V_4 -> V_1 ;
int V_18 ;
F_18 ( & V_21 -> V_9 ) ;
F_76 ( V_21 ) ;
V_18 = V_21 -> V_10 -> V_40 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
if ( V_18 & V_234 )
return 1 ;
return 0 ;
}
static void F_101 ( struct V_22 * V_2 , int V_235 )
{
struct V_3 * V_4 = F_54 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_21 = V_4 -> V_1 ;
if ( V_235 )
F_16 ( V_21 , V_38 | V_37 ) ;
else
F_26 ( V_21 , V_38 | V_37 ) ;
}
static int F_102 ( struct V_6 * V_5 , struct V_219 * V_220 )
{
struct V_236 * V_237 = (struct V_236 * ) V_5 -> V_238 -> V_239 ;
int V_24 , line = V_5 -> V_90 ;
struct V_3 * V_4 = V_237 -> V_4 + line ;
struct V_22 * V_2 = & V_4 -> V_2 ;
F_46 ( L_7 , line ) ;
if ( F_75 ( & V_2 -> V_116 ) ) {
V_24 = - V_157 ;
goto V_240;
}
V_2 -> V_87 ++ ;
if ( ! V_4 -> V_1 || V_4 -> V_1 -> V_8 & V_241 ) {
V_24 = - V_242 ;
goto V_243;
}
V_5 -> V_7 = V_4 ;
V_4 -> V_1 -> V_4 = V_4 ;
V_4 -> V_2 . V_143 =
( V_4 -> V_1 -> V_8 & V_144 ) ? 1 : 0 ;
F_93 ( V_2 , V_5 ) ;
V_24 = F_21 ( V_5 , V_4 , 0 ) ;
F_58 ( & V_2 -> V_116 ) ;
if ( V_24 == 0 )
V_24 = F_103 ( V_2 , V_5 , V_220 ) ;
V_240:
return V_24 ;
V_243:
V_2 -> V_87 -- ;
F_58 ( & V_2 -> V_116 ) ;
goto V_240;
}
static const char * F_104 ( struct V_1 * V_2 )
{
const char * V_244 = NULL ;
if ( V_2 -> V_10 -> type )
V_244 = V_2 -> V_10 -> type ( V_2 ) ;
if ( ! V_244 )
V_244 = L_8 ;
return V_244 ;
}
static void F_105 ( struct V_245 * V_246 , struct V_236 * V_237 , int V_247 )
{
struct V_3 * V_4 = V_237 -> V_4 + V_247 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
enum V_248 V_249 ;
struct V_1 * V_21 = V_4 -> V_1 ;
char V_250 [ 32 ] ;
unsigned int V_251 ;
int V_252 ;
if ( ! V_21 )
return;
V_252 = V_21 -> V_111 >= V_253 ;
F_106 ( V_246 , L_9 ,
V_21 -> line , F_104 ( V_21 ) ,
V_252 ? L_10 : L_11 ,
V_252 ? ( unsigned long long ) V_21 -> V_115
: ( unsigned long long ) V_21 -> V_100 ,
V_21 -> V_103 ) ;
if ( V_21 -> type == V_25 ) {
F_107 ( V_246 , '\n' ) ;
return;
}
if ( F_20 ( V_42 ) ) {
F_57 ( & V_2 -> V_116 ) ;
V_249 = V_4 -> V_249 ;
if ( V_249 != V_26 )
F_11 ( V_4 , V_26 ) ;
F_18 ( & V_21 -> V_9 ) ;
V_251 = V_21 -> V_10 -> V_40 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
if ( V_249 != V_26 )
F_11 ( V_4 , V_249 ) ;
F_58 ( & V_2 -> V_116 ) ;
F_106 ( V_246 , L_12 ,
V_21 -> V_168 . V_181 , V_21 -> V_168 . V_180 ) ;
if ( V_21 -> V_168 . V_182 )
F_106 ( V_246 , L_13 ,
V_21 -> V_168 . V_182 ) ;
if ( V_21 -> V_168 . V_184 )
F_106 ( V_246 , L_14 ,
V_21 -> V_168 . V_184 ) ;
if ( V_21 -> V_168 . V_185 )
F_106 ( V_246 , L_15 ,
V_21 -> V_168 . V_185 ) ;
if ( V_21 -> V_168 . V_183 )
F_106 ( V_246 , L_16 ,
V_21 -> V_168 . V_183 ) ;
#define F_108 ( T_4 , V_244 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_109 ( T_4 , V_244 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_250 [ 0 ] = '\0' ;
V_250 [ 1 ] = '\0' ;
F_108 ( V_37 , L_17 ) ;
F_109 ( V_41 , L_18 ) ;
F_108 ( V_38 , L_19 ) ;
F_109 ( V_173 , L_20 ) ;
F_109 ( V_234 , L_21 ) ;
F_109 ( V_171 , L_22 ) ;
if ( V_250 [ 0 ] )
V_250 [ 0 ] = ' ' ;
F_110 ( V_246 , V_250 ) ;
}
F_107 ( V_246 , '\n' ) ;
#undef F_109
#undef F_108
}
static int F_111 ( struct V_245 * V_246 , void * V_254 )
{
struct V_255 * V_256 = V_246 -> V_257 ;
struct V_236 * V_237 = V_256 -> V_239 ;
int V_247 ;
F_106 ( V_246 , L_23 ,
L_24 , L_24 , L_24 ) ;
for ( V_247 = 0 ; V_247 < V_237 -> V_258 ; V_247 ++ )
F_105 ( V_246 , V_237 , V_247 ) ;
return 0 ;
}
static int F_112 ( struct V_259 * V_259 , struct V_219 * V_219 )
{
return F_113 ( V_219 , F_111 , F_114 ( V_259 ) ) ;
}
void F_115 ( struct V_1 * V_2 , const char * V_260 ,
unsigned int V_87 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_247 ;
for ( V_247 = 0 ; V_247 < V_87 ; V_247 ++ , V_260 ++ ) {
if ( * V_260 == '\n' )
putchar ( V_2 , '\r' ) ;
putchar ( V_2 , * V_260 ) ;
}
}
struct V_1 * T_5
F_116 ( struct V_1 * V_261 , int V_258 , struct V_262 * V_263 )
{
int V_264 = V_263 -> V_90 ;
if ( V_264 < 0 || V_264 >= V_258 || ( V_261 [ V_264 ] . V_100 == 0 &&
V_261 [ V_264 ] . V_265 == NULL ) )
for ( V_264 = 0 ; V_264 < V_258 ; V_264 ++ )
if ( V_261 [ V_264 ] . V_100 != 0 ||
V_261 [ V_264 ] . V_265 != NULL )
break;
V_263 -> V_90 = V_264 ;
return V_261 + V_264 ;
}
void
F_117 ( char * V_266 , int * V_48 , int * V_184 , int * V_49 , int * V_267 )
{
char * V_260 = V_266 ;
* V_48 = F_118 ( V_260 , NULL , 10 ) ;
while ( * V_260 >= '0' && * V_260 <= '9' )
V_260 ++ ;
if ( * V_260 )
* V_184 = * V_260 ++ ;
if ( * V_260 )
* V_49 = * V_260 ++ - '0' ;
if ( * V_260 )
* V_267 = * V_260 ;
}
int
F_119 ( struct V_1 * V_2 , struct V_262 * V_263 ,
int V_48 , int V_184 , int V_49 , int V_267 )
{
struct V_59 V_34 ;
static struct V_59 V_268 ;
int V_247 ;
if ( ! ( F_14 ( V_2 ) && ( V_2 -> V_32 -> V_8 & V_269 ) ) ) {
F_120 ( & V_2 -> V_9 ) ;
F_121 ( & V_2 -> V_9 , & V_270 ) ;
}
memset ( & V_34 , 0 , sizeof( struct V_59 ) ) ;
V_34 . V_35 = V_271 | V_46 | V_78 ;
for ( V_247 = 0 ; V_272 [ V_247 ] . V_273 ; V_247 ++ )
if ( V_272 [ V_247 ] . V_273 <= V_48 )
break;
V_34 . V_35 |= V_272 [ V_247 ] . V_33 ;
if ( V_49 == 7 )
V_34 . V_35 |= V_53 ;
else
V_34 . V_35 |= V_274 ;
switch ( V_184 ) {
case 'o' : case 'O' :
V_34 . V_35 |= V_275 ;
case 'e' : case 'E' :
V_34 . V_35 |= V_55 ;
break;
}
if ( V_267 == 'r' )
V_34 . V_35 |= V_76 ;
V_2 -> V_18 |= V_38 ;
V_2 -> V_10 -> V_75 ( V_2 , & V_34 , & V_268 ) ;
if ( V_263 )
V_263 -> V_33 = V_34 . V_35 ;
return 0 ;
}
static void F_11 ( struct V_3 * V_4 ,
enum V_248 V_249 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
if ( V_4 -> V_249 != V_249 ) {
if ( V_2 -> V_10 -> V_276 )
V_2 -> V_10 -> V_276 ( V_2 , V_249 , V_4 -> V_249 ) ;
V_4 -> V_249 = V_249 ;
}
}
static int F_122 ( struct V_277 * V_278 , void * V_279 )
{
struct V_280 * V_281 = V_279 ;
struct V_255 * V_282 = V_281 -> V_238 -> V_255 ;
T_6 V_283 = F_123 ( V_282 -> V_284 , V_282 -> V_285 ) +
V_281 -> V_2 -> line ;
return V_278 -> V_283 == V_283 ;
}
int F_124 ( struct V_236 * V_237 , struct V_1 * V_21 )
{
struct V_3 * V_4 = V_237 -> V_4 + V_21 -> line ;
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_277 * V_286 ;
struct V_280 V_281 = { V_21 , V_237 } ;
F_57 ( & V_2 -> V_116 ) ;
V_286 = F_125 ( V_21 -> V_278 , & V_281 , F_122 ) ;
if ( F_126 ( V_286 ) ) {
if ( ! F_127 ( V_21 -> V_103 ) )
V_21 -> V_287 = 1 ;
F_128 ( V_286 ) ;
F_58 ( & V_2 -> V_116 ) ;
return 0 ;
}
F_128 ( V_286 ) ;
if ( V_288 || ! F_14 ( V_21 ) )
V_21 -> V_289 = 1 ;
if ( V_2 -> V_8 & V_43 ) {
const struct V_290 * V_10 = V_21 -> V_10 ;
int V_291 ;
if ( V_288 || ! F_14 ( V_21 ) ) {
F_22 ( V_47 , & V_2 -> V_8 ) ;
F_23 ( V_45 , & V_2 -> V_8 ) ;
F_18 ( & V_21 -> V_9 ) ;
V_10 -> V_11 ( V_21 ) ;
V_10 -> V_19 ( V_21 , 0 ) ;
V_10 -> V_221 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
}
for ( V_291 = 3 ; ! V_10 -> V_152 ( V_21 ) && V_291 ; V_291 -- )
F_129 ( 10 ) ;
if ( ! V_291 )
F_65 ( V_292 L_25
L_26 ,
V_21 -> V_278 ? F_130 ( V_21 -> V_278 ) : L_24 ,
V_21 -> V_278 ? L_27 : L_24 ,
V_237 -> F_130 ,
V_237 -> V_255 -> V_293 + V_21 -> line ) ;
if ( V_288 || ! F_14 ( V_21 ) )
V_10 -> V_233 ( V_21 ) ;
}
if ( V_288 && F_14 ( V_21 ) )
F_131 ( V_21 -> V_32 ) ;
if ( V_288 || ! F_14 ( V_21 ) )
F_11 ( V_4 , V_224 ) ;
F_58 ( & V_2 -> V_116 ) ;
return 0 ;
}
int F_132 ( struct V_236 * V_237 , struct V_1 * V_21 )
{
struct V_3 * V_4 = V_237 -> V_4 + V_21 -> line ;
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_277 * V_286 ;
struct V_280 V_281 = { V_21 , V_237 } ;
struct V_59 V_34 ;
F_57 ( & V_2 -> V_116 ) ;
V_286 = F_125 ( V_21 -> V_278 , & V_281 , F_122 ) ;
if ( ! V_21 -> V_289 && F_126 ( V_286 ) ) {
if ( V_21 -> V_287 ) {
F_133 ( V_21 -> V_103 ) ;
V_21 -> V_287 = 0 ;
}
F_128 ( V_286 ) ;
F_58 ( & V_2 -> V_116 ) ;
return 0 ;
}
F_128 ( V_286 ) ;
V_21 -> V_289 = 0 ;
if ( F_14 ( V_21 ) ) {
memset ( & V_34 , 0 , sizeof( struct V_59 ) ) ;
V_34 . V_35 = V_21 -> V_32 -> V_33 ;
if ( V_2 -> V_5 && V_34 . V_35 == 0 )
V_34 = V_2 -> V_5 -> V_34 ;
if ( V_288 )
F_11 ( V_4 , V_26 ) ;
V_21 -> V_10 -> V_75 ( V_21 , & V_34 , NULL ) ;
if ( V_288 )
F_134 ( V_21 -> V_32 ) ;
}
if ( V_2 -> V_8 & V_294 ) {
const struct V_290 * V_10 = V_21 -> V_10 ;
int V_83 ;
F_11 ( V_4 , V_26 ) ;
F_18 ( & V_21 -> V_9 ) ;
V_10 -> V_19 ( V_21 , 0 ) ;
F_19 ( & V_21 -> V_9 ) ;
if ( V_288 || ! F_14 ( V_21 ) ) {
struct V_6 * V_5 = V_2 -> V_5 ;
V_83 = V_10 -> V_31 ( V_21 ) ;
if ( V_83 == 0 ) {
if ( V_5 )
F_15 ( V_5 , V_4 , NULL ) ;
F_18 ( & V_21 -> V_9 ) ;
V_10 -> V_19 ( V_21 , V_21 -> V_18 ) ;
V_10 -> V_14 ( V_21 ) ;
F_19 ( & V_21 -> V_9 ) ;
F_22 ( V_45 , & V_2 -> V_8 ) ;
} else {
F_24 ( V_5 , V_4 ) ;
}
}
F_23 ( V_47 , & V_2 -> V_8 ) ;
}
F_58 ( & V_2 -> V_116 ) ;
return 0 ;
}
static inline void
F_135 ( struct V_236 * V_237 , struct V_1 * V_2 )
{
char V_295 [ 64 ] ;
switch ( V_2 -> V_111 ) {
case V_296 :
snprintf ( V_295 , sizeof( V_295 ) , L_28 , V_2 -> V_100 ) ;
break;
case V_297 :
snprintf ( V_295 , sizeof( V_295 ) ,
L_29 , V_2 -> V_100 , V_2 -> V_109 ) ;
break;
case V_253 :
case V_298 :
case V_299 :
case V_300 :
snprintf ( V_295 , sizeof( V_295 ) ,
L_30 , ( unsigned long long ) V_2 -> V_115 ) ;
break;
default:
F_136 ( V_295 , L_31 , sizeof( V_295 ) ) ;
break;
}
F_65 ( V_301 L_32 ,
V_2 -> V_278 ? F_130 ( V_2 -> V_278 ) : L_24 ,
V_2 -> V_278 ? L_27 : L_24 ,
V_237 -> F_130 ,
V_237 -> V_255 -> V_293 + V_2 -> line ,
V_295 , V_2 -> V_103 , V_2 -> V_73 / 16 , F_104 ( V_2 ) ) ;
}
static void
F_137 ( struct V_236 * V_237 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
unsigned int V_8 ;
if ( ! V_2 -> V_100 && ! V_2 -> V_115 && ! V_2 -> V_265 )
return;
V_8 = 0 ;
if ( V_2 -> V_8 & V_159 )
V_8 |= V_160 ;
if ( V_2 -> V_8 & V_302 ) {
if ( ! ( V_2 -> V_8 & V_303 ) ) {
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
if ( V_2 -> V_32 && ! ( V_2 -> V_32 -> V_8 & V_269 ) )
F_138 ( V_2 -> V_32 ) ;
if ( ! F_14 ( V_2 ) )
F_11 ( V_4 , V_224 ) ;
}
}
static int F_139 ( struct V_255 * V_238 , int line , char * V_266 )
{
struct V_236 * V_237 = V_238 -> V_239 ;
struct V_3 * V_4 = V_237 -> V_4 + line ;
struct V_1 * V_2 ;
int V_48 = 9600 ;
int V_49 = 8 ;
int V_184 = 'n' ;
int V_267 = 'n' ;
int V_83 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
if ( ! ( V_2 -> V_10 -> V_304 && V_2 -> V_10 -> V_305 ) )
return - 1 ;
if ( V_2 -> V_10 -> V_306 ) {
struct V_22 * V_307 = & V_4 -> V_2 ;
V_83 = 0 ;
F_57 ( & V_307 -> V_116 ) ;
if ( ! F_88 ( V_45 , & V_307 -> V_8 ) )
V_83 = V_2 -> V_10 -> V_306 ( V_2 ) ;
F_58 ( & V_307 -> V_116 ) ;
if ( V_83 )
return V_83 ;
}
if ( V_266 ) {
F_117 ( V_266 , & V_48 , & V_184 , & V_49 , & V_267 ) ;
return F_119 ( V_2 , NULL , V_48 , V_184 , V_49 , V_267 ) ;
}
return 0 ;
}
static int F_140 ( struct V_255 * V_238 , int line )
{
struct V_236 * V_237 = V_238 -> V_239 ;
struct V_3 * V_4 = V_237 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
return V_2 -> V_10 -> V_304 ( V_2 ) ;
}
static void F_141 ( struct V_255 * V_238 , int line , char V_86 )
{
struct V_236 * V_237 = V_238 -> V_239 ;
struct V_3 * V_4 = V_237 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return;
V_2 = V_4 -> V_1 ;
if ( V_86 == '\n' )
V_2 -> V_10 -> V_305 ( V_2 , '\r' ) ;
V_2 -> V_10 -> V_305 ( V_2 , V_86 ) ;
}
int F_142 ( struct V_236 * V_237 )
{
struct V_255 * V_308 ;
int V_247 , V_24 ;
F_2 ( V_237 -> V_4 ) ;
V_237 -> V_4 = F_143 ( sizeof( struct V_3 ) * V_237 -> V_258 , V_29 ) ;
if ( ! V_237 -> V_4 )
goto V_195;
V_308 = F_144 ( V_237 -> V_258 ) ;
if ( ! V_308 )
goto V_309;
V_237 -> V_255 = V_308 ;
V_308 -> V_310 = V_237 -> V_310 ;
V_308 -> V_311 = V_237 -> F_130 ;
V_308 -> V_284 = V_237 -> V_284 ;
V_308 -> V_285 = V_237 -> V_312 ;
V_308 -> type = V_313 ;
V_308 -> V_314 = V_315 ;
V_308 -> V_316 = V_317 ;
V_308 -> V_316 . V_35 = V_318 | V_274 | V_271 | V_46 | V_78 ;
V_308 -> V_316 . V_216 = V_308 -> V_316 . V_215 = 9600 ;
V_308 -> V_8 = V_319 | V_320 ;
V_308 -> V_239 = V_237 ;
F_145 ( V_308 , & V_290 ) ;
for ( V_247 = 0 ; V_247 < V_237 -> V_258 ; V_247 ++ ) {
struct V_3 * V_4 = V_237 -> V_4 + V_247 ;
struct V_22 * V_2 = & V_4 -> V_2 ;
F_146 ( V_2 ) ;
V_2 -> V_10 = & V_321 ;
V_2 -> V_106 = V_58 / 2 ;
V_2 -> V_107 = 30 * V_58 ;
}
V_24 = F_147 ( V_308 ) ;
if ( V_24 >= 0 )
return V_24 ;
for ( V_247 = 0 ; V_247 < V_237 -> V_258 ; V_247 ++ )
F_148 ( & V_237 -> V_4 [ V_247 ] . V_2 ) ;
F_149 ( V_308 ) ;
V_309:
F_150 ( V_237 -> V_4 ) ;
V_195:
return - V_30 ;
}
void F_151 ( struct V_236 * V_237 )
{
struct V_255 * V_322 = V_237 -> V_255 ;
unsigned int V_247 ;
F_152 ( V_322 ) ;
F_149 ( V_322 ) ;
for ( V_247 = 0 ; V_247 < V_237 -> V_258 ; V_247 ++ )
F_148 ( & V_237 -> V_4 [ V_247 ] . V_2 ) ;
F_150 ( V_237 -> V_4 ) ;
V_237 -> V_4 = NULL ;
V_237 -> V_255 = NULL ;
}
struct V_255 * F_153 ( struct V_262 * V_263 , int * V_90 )
{
struct V_236 * V_322 = V_263 -> V_279 ;
* V_90 = V_263 -> V_90 ;
return V_322 -> V_255 ;
}
static T_7 F_154 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . V_105 * 16 ) ;
}
static T_7 F_156 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . type ) ;
}
static T_7 F_157 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . line ) ;
}
static T_7 F_158 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
unsigned long V_326 ;
F_56 ( V_2 , & V_117 ) ;
V_326 = V_117 . V_2 ;
if ( V_101 )
V_326 |= ( unsigned long ) V_117 . V_102 << V_101 ;
return snprintf ( V_28 , V_325 , L_34 , V_326 ) ;
}
static T_7 F_159 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . V_103 ) ;
}
static T_7 F_160 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_35 , V_117 . V_8 ) ;
}
static T_7 F_161 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . V_104 ) ;
}
static T_7 F_162 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . V_106 ) ;
}
static T_7 F_163 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . V_107 ) ;
}
static T_7 F_164 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . V_72 ) ;
}
static T_7 F_165 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . V_110 ) ;
}
static T_7 F_166 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_34 , ( unsigned long ) V_117 . V_114 ) ;
}
static T_7 F_167 ( struct V_277 * V_278 ,
struct V_323 * V_324 , char * V_28 )
{
struct V_98 V_117 ;
struct V_22 * V_2 = F_155 ( V_278 ) ;
F_56 ( V_2 , & V_117 ) ;
return snprintf ( V_28 , V_325 , L_33 , V_117 . V_112 ) ;
}
int F_168 ( struct V_236 * V_237 , struct V_1 * V_21 )
{
struct V_3 * V_4 ;
struct V_22 * V_2 ;
int V_83 = 0 ;
struct V_277 * V_286 ;
int V_327 ;
F_2 ( F_169 () ) ;
if ( V_21 -> line >= V_237 -> V_258 )
return - V_132 ;
V_4 = V_237 -> V_4 + V_21 -> line ;
V_2 = & V_4 -> V_2 ;
F_57 ( & V_328 ) ;
F_57 ( & V_2 -> V_116 ) ;
if ( V_4 -> V_1 ) {
V_83 = - V_132 ;
goto V_195;
}
V_4 -> V_1 = V_21 ;
V_4 -> V_249 = V_329 ;
V_21 -> V_32 = V_237 -> V_32 ;
V_21 -> V_4 = V_4 ;
if ( ! ( F_14 ( V_21 ) && ( V_21 -> V_32 -> V_8 & V_269 ) ) ) {
F_120 ( & V_21 -> V_9 ) ;
F_121 ( & V_21 -> V_9 , & V_270 ) ;
}
if ( V_21 -> V_32 && V_21 -> V_278 )
F_170 ( V_21 -> V_278 -> V_330 , V_21 -> V_32 -> V_311 , V_21 -> line ) ;
F_137 ( V_237 , V_4 , V_21 ) ;
V_327 = 2 ;
if ( V_21 -> V_331 )
V_327 ++ ;
V_21 -> V_332 = F_171 ( V_327 , sizeof( * V_21 -> V_332 ) ,
V_29 ) ;
if ( ! V_21 -> V_332 ) {
V_83 = - V_30 ;
goto V_195;
}
V_21 -> V_332 [ 0 ] = & V_333 ;
if ( V_21 -> V_331 )
V_21 -> V_332 [ 1 ] = V_21 -> V_331 ;
V_286 = F_172 ( V_2 , V_237 -> V_255 ,
V_21 -> line , V_21 -> V_278 , V_2 , V_21 -> V_332 ) ;
if ( F_173 ( ! F_174 ( V_286 ) ) ) {
F_175 ( V_286 , 1 ) ;
} else {
F_65 ( V_292 L_36 ,
V_21 -> line ) ;
}
V_21 -> V_8 &= ~ V_241 ;
V_195:
F_58 ( & V_2 -> V_116 ) ;
F_58 ( & V_328 ) ;
return V_83 ;
}
int F_176 ( struct V_236 * V_237 , struct V_1 * V_21 )
{
struct V_3 * V_4 = V_237 -> V_4 + V_21 -> line ;
struct V_22 * V_2 = & V_4 -> V_2 ;
struct V_6 * V_5 ;
int V_83 = 0 ;
F_2 ( F_169 () ) ;
if ( V_4 -> V_1 != V_21 )
F_65 ( V_334 L_37 ,
V_4 -> V_1 , V_21 ) ;
F_57 ( & V_328 ) ;
F_57 ( & V_2 -> V_116 ) ;
if ( ! V_4 -> V_1 ) {
F_58 ( & V_2 -> V_116 ) ;
V_83 = - V_132 ;
goto V_195;
}
V_21 -> V_8 |= V_241 ;
F_58 ( & V_2 -> V_116 ) ;
F_177 ( V_237 -> V_255 , V_21 -> line ) ;
V_5 = F_178 ( V_2 ) ;
if ( V_5 ) {
F_179 ( V_2 -> V_5 ) ;
F_180 ( V_5 ) ;
}
if ( F_14 ( V_21 ) )
F_181 ( V_21 -> V_32 ) ;
if ( V_21 -> type != V_25 )
V_21 -> V_10 -> V_140 ( V_21 ) ;
F_150 ( V_21 -> V_332 ) ;
V_21 -> type = V_25 ;
V_4 -> V_1 = NULL ;
V_195:
F_58 ( & V_328 ) ;
return V_83 ;
}
int F_182 ( struct V_1 * V_335 , struct V_1 * V_336 )
{
if ( V_335 -> V_111 != V_336 -> V_111 )
return 0 ;
switch ( V_335 -> V_111 ) {
case V_296 :
return ( V_335 -> V_100 == V_336 -> V_100 ) ;
case V_297 :
return ( V_335 -> V_100 == V_336 -> V_100 ) &&
( V_335 -> V_109 == V_336 -> V_109 ) ;
case V_253 :
case V_298 :
case V_299 :
case V_300 :
return ( V_335 -> V_115 == V_336 -> V_115 ) ;
}
return 0 ;
}
void F_183 ( struct V_1 * V_21 , unsigned int V_251 )
{
struct V_22 * V_2 = & V_21 -> V_4 -> V_2 ;
struct V_6 * V_5 = V_2 -> V_5 ;
struct V_337 * V_338 = V_5 ? F_184 ( V_5 ) : NULL ;
if ( V_338 ) {
if ( V_338 -> V_10 -> V_339 )
V_338 -> V_10 -> V_339 ( V_5 , V_251 ) ;
F_185 ( V_338 ) ;
}
V_21 -> V_168 . V_176 ++ ;
if ( V_2 -> V_8 & V_340 ) {
if ( V_251 )
F_95 ( & V_2 -> V_227 ) ;
else if ( V_5 )
F_186 ( V_5 ) ;
}
}
void F_187 ( struct V_1 * V_21 , unsigned int V_251 )
{
struct V_22 * V_2 = & V_21 -> V_4 -> V_2 ;
struct V_6 * V_5 = V_2 -> V_5 ;
V_21 -> V_168 . V_177 ++ ;
if ( F_17 ( V_2 ) &&
! ( V_21 -> V_8 & V_39 ) ) {
if ( V_5 -> V_13 ) {
if ( V_251 ) {
V_5 -> V_13 = 0 ;
V_21 -> V_10 -> V_14 ( V_21 ) ;
F_1 ( V_21 ) ;
}
} else {
if ( ! V_251 ) {
V_5 -> V_13 = 1 ;
V_21 -> V_10 -> V_11 ( V_21 ) ;
}
}
}
}
void F_188 ( struct V_1 * V_2 , unsigned int V_251 ,
unsigned int V_183 , unsigned int V_86 , unsigned int V_341 )
{
struct V_22 * V_307 = & V_2 -> V_4 -> V_2 ;
if ( ( V_251 & V_2 -> V_342 & ~ V_183 ) == 0 )
if ( F_189 ( V_307 , V_86 , V_341 ) == 0 )
++ V_2 -> V_168 . V_186 ;
if ( V_251 & ~ V_2 -> V_342 & V_183 )
if ( F_189 ( V_307 , 0 , V_343 ) == 0 )
++ V_2 -> V_168 . V_186 ;
}
