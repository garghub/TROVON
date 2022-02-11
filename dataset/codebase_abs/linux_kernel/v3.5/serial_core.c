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
V_5 -> V_33 -> V_34 = V_23 -> V_31 -> V_32 ;
V_23 -> V_31 -> V_32 = 0 ;
}
F_15 ( V_5 , V_4 , NULL ) ;
if ( V_22 ) {
if ( V_5 -> V_33 -> V_34 & V_35 )
F_16 ( V_23 , V_36 | V_37 ) ;
}
if ( V_2 -> V_8 & V_38 ) {
F_17 ( & V_23 -> V_9 ) ;
if ( ! ( V_23 -> V_10 -> V_39 ( V_23 ) & V_40 ) )
V_5 -> V_15 = 1 ;
F_18 ( & V_23 -> V_9 ) ;
}
}
if ( V_26 && F_19 ( V_41 ) )
return 1 ;
return V_26 ;
}
static int F_20 ( struct V_6 * V_5 , struct V_3 * V_4 ,
int V_22 )
{
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_26 ;
if ( V_2 -> V_8 & V_42 )
return 0 ;
F_21 ( V_43 , & V_5 -> V_8 ) ;
V_26 = F_11 ( V_5 , V_4 , V_22 ) ;
if ( ! V_26 ) {
F_21 ( V_44 , & V_2 -> V_8 ) ;
F_22 ( V_43 , & V_5 -> V_8 ) ;
} else if ( V_26 > 0 )
V_26 = 0 ;
return V_26 ;
}
static void F_23 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
if ( V_5 )
F_21 ( V_43 , & V_5 -> V_8 ) ;
if ( F_24 ( V_44 , & V_2 -> V_8 ) ) {
if ( ! V_5 || ( V_5 -> V_33 -> V_34 & V_45 ) )
F_25 ( V_23 , V_37 | V_36 ) ;
F_26 ( V_2 ) ;
}
F_22 ( V_46 , & V_2 -> V_8 ) ;
if ( V_4 -> V_12 . V_13 ) {
F_27 ( ( unsigned long ) V_4 -> V_12 . V_13 ) ;
V_4 -> V_12 . V_13 = NULL ;
}
}
void
F_28 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned int V_47 )
{
unsigned int V_48 ;
switch ( V_32 & V_49 ) {
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
if ( V_32 & V_53 )
V_48 ++ ;
if ( V_32 & V_54 )
V_48 ++ ;
V_48 = V_48 * V_2 -> V_55 ;
V_2 -> V_56 = ( V_57 * V_48 ) / V_47 + V_57 / 50 ;
}
unsigned int
F_29 ( struct V_1 * V_2 , struct V_58 * V_33 ,
struct V_58 * V_19 , unsigned int V_59 , unsigned int V_60 )
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
V_47 = F_30 ( V_33 ) ;
if ( V_47 == 38400 )
V_47 = V_62 ;
if ( V_47 == 0 ) {
V_63 = 1 ;
V_47 = 9600 ;
}
if ( V_47 >= V_59 && V_47 <= V_60 )
return V_47 ;
V_33 -> V_34 &= ~ V_35 ;
if ( V_19 ) {
V_47 = F_30 ( V_19 ) ;
if ( ! V_63 )
F_31 ( V_33 ,
V_47 , V_47 ) ;
V_19 = NULL ;
continue;
}
if ( ! V_63 ) {
if ( V_47 <= V_59 )
F_31 ( V_33 ,
V_59 + 1 , V_59 + 1 ) ;
else
F_31 ( V_33 ,
V_60 - 1 , V_60 - 1 ) ;
}
}
F_32 ( 1 ) ;
return 0 ;
}
unsigned int
F_33 ( struct V_1 * V_2 , unsigned int V_47 )
{
unsigned int V_69 ;
if ( V_47 == 38400 && ( V_2 -> V_8 & V_64 ) == V_70 )
V_69 = V_2 -> V_71 ;
else
V_69 = F_34 ( V_2 -> V_72 , 16 * V_47 ) ;
return V_69 ;
}
static void F_15 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_58 * V_73 )
{
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_58 * V_33 ;
if ( ! V_5 || ! V_5 -> V_33 || V_23 -> type == V_27 )
return;
V_33 = V_5 -> V_33 ;
if ( V_33 -> V_34 & V_74 )
F_21 ( V_75 , & V_2 -> V_8 ) ;
else
F_22 ( V_75 , & V_2 -> V_8 ) ;
if ( V_33 -> V_34 & V_76 )
F_22 ( V_77 , & V_2 -> V_8 ) ;
else
F_21 ( V_77 , & V_2 -> V_8 ) ;
V_23 -> V_10 -> V_78 ( V_23 , V_33 , V_73 ) ;
}
static inline int F_35 ( struct V_1 * V_2 ,
struct V_79 * V_80 , unsigned char V_81 )
{
unsigned long V_8 ;
int V_82 = 0 ;
if ( ! V_80 -> V_13 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
if ( F_36 ( V_80 ) != 0 ) {
V_80 -> V_13 [ V_80 -> V_83 ] = V_81 ;
V_80 -> V_83 = ( V_80 -> V_83 + 1 ) & ( V_84 - 1 ) ;
V_82 = 1 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
return V_82 ;
}
static int F_37 ( struct V_6 * V_5 , unsigned char V_85 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
return F_35 ( V_4 -> V_1 , & V_4 -> V_12 , V_85 ) ;
}
static void F_38 ( struct V_6 * V_5 )
{
F_9 ( V_5 ) ;
}
static int F_39 ( struct V_6 * V_5 ,
const unsigned char * V_13 , int V_86 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 ;
struct V_79 * V_80 ;
unsigned long V_8 ;
int V_81 , V_82 = 0 ;
if ( ! V_4 ) {
F_32 ( 1 ) ;
return - V_87 ;
}
V_2 = V_4 -> V_1 ;
V_80 = & V_4 -> V_12 ;
if ( ! V_80 -> V_13 )
return 0 ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
while ( 1 ) {
V_81 = F_40 ( V_80 -> V_83 , V_80 -> V_88 , V_84 ) ;
if ( V_86 < V_81 )
V_81 = V_86 ;
if ( V_81 <= 0 )
break;
memcpy ( V_80 -> V_13 + V_80 -> V_83 , V_13 , V_81 ) ;
V_80 -> V_83 = ( V_80 -> V_83 + V_81 ) & ( V_84 - 1 ) ;
V_13 += V_81 ;
V_86 -= V_81 ;
V_82 += V_81 ;
}
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_9 ( V_5 ) ;
return V_82 ;
}
static int F_41 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_82 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_82 = F_36 ( & V_4 -> V_12 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_82 ;
}
static int F_42 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
int V_82 ;
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_82 = F_43 ( & V_4 -> V_12 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
return V_82 ;
}
static void F_44 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 ;
unsigned long V_8 ;
if ( ! V_4 ) {
F_32 ( 1 ) ;
return;
}
V_2 = V_4 -> V_1 ;
F_45 ( L_1 , V_5 -> V_89 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
F_13 ( & V_4 -> V_12 ) ;
if ( V_2 -> V_10 -> V_90 )
V_2 -> V_10 -> V_90 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_3 ( V_5 ) ;
}
static void F_46 ( struct V_6 * V_5 , char V_85 )
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
V_2 -> V_10 -> V_16 ( V_2 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
}
}
}
static void F_47 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
if ( F_48 ( V_5 ) )
F_46 ( V_5 , F_49 ( V_5 ) ) ;
if ( V_5 -> V_33 -> V_34 & V_74 )
F_25 ( V_4 -> V_1 , V_36 ) ;
}
static void F_50 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( F_48 ( V_5 ) ) {
if ( V_2 -> V_92 )
V_2 -> V_92 = 0 ;
else
F_46 ( V_5 , F_51 ( V_5 ) ) ;
}
if ( V_5 -> V_33 -> V_34 & V_74 )
F_16 ( V_2 , V_36 ) ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_93 T_2 * V_94 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_93 V_95 ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
F_53 ( & V_2 -> V_96 ) ;
V_95 . type = V_23 -> type ;
V_95 . line = V_23 -> line ;
V_95 . V_2 = V_23 -> V_97 ;
if ( V_98 )
V_95 . V_99 = ( long ) V_23 -> V_97 >> V_98 ;
V_95 . V_100 = V_23 -> V_100 ;
V_95 . V_8 = V_23 -> V_8 ;
V_95 . V_101 = V_23 -> V_55 ;
V_95 . V_102 = V_23 -> V_72 / 16 ;
V_95 . V_103 = F_54 ( V_2 -> V_103 ) / 10 ;
V_95 . V_104 = V_2 -> V_104 == V_105 ?
V_105 :
F_54 ( V_2 -> V_104 ) / 10 ;
V_95 . V_71 = V_23 -> V_71 ;
V_95 . V_106 = V_23 -> V_106 ;
V_95 . V_107 = V_23 -> V_108 ;
V_95 . V_109 = V_23 -> V_110 ;
V_95 . V_111 = ( void * ) ( unsigned long ) V_23 -> V_112 ;
F_55 ( & V_2 -> V_96 ) ;
if ( F_56 ( V_94 , & V_95 , sizeof( * V_94 ) ) )
return - V_113 ;
return 0 ;
}
static int F_57 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_93 T_2 * V_114 )
{
struct V_93 V_115 ;
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
unsigned long V_116 ;
unsigned int V_117 , V_118 , V_104 ;
unsigned int V_119 , V_103 ;
T_1 V_120 , V_121 ;
int V_26 = 0 ;
if ( F_58 ( & V_115 , V_114 , sizeof( V_115 ) ) )
return - V_113 ;
V_116 = V_115 . V_2 ;
if ( V_98 )
V_116 += ( unsigned long ) V_115 . V_99 << V_98 ;
V_115 . V_100 = F_59 ( V_115 . V_100 ) ;
V_103 = F_60 ( V_115 . V_103 * 10 ) ;
V_104 = V_115 . V_104 == V_105 ?
V_105 :
F_60 ( V_115 . V_104 * 10 ) ;
F_53 ( & V_2 -> V_96 ) ;
V_117 = ! ( V_23 -> V_8 & V_122 )
&& V_115 . V_100 != V_23 -> V_100 ;
V_118 = ! ( V_23 -> V_8 & V_122 )
&& ( V_116 != V_23 -> V_97 ||
( unsigned long ) V_115 . V_111 != V_23 -> V_112 ||
V_115 . V_106 != V_23 -> V_106 ||
V_115 . V_107 != V_23 -> V_108 ||
V_115 . V_109 != V_23 -> V_110 ||
V_115 . type != V_23 -> type ) ;
V_120 = V_23 -> V_8 ;
V_121 = V_115 . V_8 ;
V_119 = V_23 -> V_71 ;
if ( ! F_19 ( V_41 ) ) {
V_26 = - V_123 ;
if ( V_117 || V_118 ||
( V_115 . V_102 != V_23 -> V_72 / 16 ) ||
( V_103 != V_2 -> V_103 ) ||
( V_104 != V_2 -> V_104 ) ||
( V_115 . V_101 &&
V_115 . V_101 != V_23 -> V_55 ) ||
( ( ( V_121 ^ V_120 ) & ~ V_124 ) != 0 ) )
goto exit;
V_23 -> V_8 = ( ( V_23 -> V_8 & ~ V_124 ) |
( V_121 & V_124 ) ) ;
V_23 -> V_71 = V_115 . V_71 ;
goto V_125;
}
if ( V_23 -> V_10 -> V_126 )
V_26 = V_23 -> V_10 -> V_126 ( V_23 , & V_115 ) ;
if ( ( V_115 . V_100 >= V_127 ) || ( V_115 . V_100 < 0 ) ||
( V_115 . V_102 < 9600 ) )
V_26 = - V_128 ;
if ( V_26 )
goto exit;
if ( V_118 || V_117 ) {
V_26 = - V_129 ;
if ( F_61 ( V_2 ) > 1 )
goto exit;
F_23 ( V_5 , V_4 ) ;
}
if ( V_118 ) {
unsigned long V_130 , V_131 ;
unsigned int V_132 , V_133 , V_134 , V_135 ;
V_130 = V_23 -> V_97 ;
V_131 = V_23 -> V_112 ;
V_132 = V_23 -> type ;
V_134 = V_23 -> V_106 ;
V_133 = V_23 -> V_108 ;
V_135 = V_23 -> V_110 ;
if ( V_132 != V_27 )
V_23 -> V_10 -> V_136 ( V_23 ) ;
V_23 -> V_97 = V_116 ;
V_23 -> type = V_115 . type ;
V_23 -> V_106 = V_115 . V_106 ;
V_23 -> V_108 = V_115 . V_107 ;
V_23 -> V_110 = V_115 . V_109 ;
V_23 -> V_112 = ( unsigned long ) V_115 . V_111 ;
if ( V_23 -> type != V_27 ) {
V_26 = V_23 -> V_10 -> V_137 ( V_23 ) ;
} else {
V_26 = 0 ;
}
if ( V_26 && V_132 != V_27 ) {
V_23 -> V_97 = V_130 ;
V_23 -> type = V_132 ;
V_23 -> V_106 = V_134 ;
V_23 -> V_108 = V_133 ;
V_23 -> V_110 = V_135 ;
V_23 -> V_112 = V_131 ;
V_26 = V_23 -> V_10 -> V_137 ( V_23 ) ;
if ( V_26 )
V_23 -> type = V_27 ;
V_26 = - V_129 ;
goto exit;
}
}
if ( V_117 )
V_23 -> V_100 = V_115 . V_100 ;
if ( ! ( V_23 -> V_8 & V_122 ) )
V_23 -> V_72 = V_115 . V_102 * 16 ;
V_23 -> V_8 = ( V_23 -> V_8 & ~ V_138 ) |
( V_121 & V_138 ) ;
V_23 -> V_71 = V_115 . V_71 ;
V_2 -> V_103 = V_103 ;
V_2 -> V_104 = V_104 ;
if ( V_115 . V_101 )
V_23 -> V_55 = V_115 . V_101 ;
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_139 =
( V_23 -> V_8 & V_140 ) ? 1 : 0 ;
V_125:
V_26 = 0 ;
if ( V_23 -> type == V_27 )
goto exit;
if ( V_2 -> V_8 & V_42 ) {
if ( ( ( V_120 ^ V_23 -> V_8 ) & V_64 ) ||
V_119 != V_23 -> V_71 ) {
if ( V_23 -> V_8 & V_64 ) {
char V_13 [ 64 ] ;
F_62 ( V_141
L_2
L_3 , V_142 -> V_143 ,
F_63 ( V_2 -> V_5 , V_13 ) ) ;
}
F_15 ( V_5 , V_4 , NULL ) ;
}
} else
V_26 = F_20 ( V_5 , V_4 , 1 ) ;
exit:
F_55 ( & V_2 -> V_96 ) ;
return V_26 ;
}
static int F_64 ( struct V_6 * V_5 ,
struct V_3 * V_4 , unsigned int T_2 * V_144 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
unsigned int V_145 ;
V_145 = V_23 -> V_10 -> V_146 ( V_23 ) ;
if ( V_23 -> V_92 ||
( ( F_43 ( & V_4 -> V_12 ) > 0 ) &&
! V_5 -> V_14 && ! V_5 -> V_15 ) )
V_145 &= ~ V_147 ;
return F_65 ( V_145 , V_144 ) ;
}
static int F_66 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
int V_145 = - V_148 ;
F_53 ( & V_2 -> V_96 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_43 ) ) ) {
V_145 = V_23 -> V_20 ;
F_17 ( & V_23 -> V_9 ) ;
V_145 |= V_23 -> V_10 -> V_39 ( V_23 ) ;
F_18 ( & V_23 -> V_9 ) ;
}
F_55 ( & V_2 -> V_96 ) ;
return V_145 ;
}
static int
F_67 ( struct V_6 * V_5 , unsigned int V_17 , unsigned int V_18 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_82 = - V_148 ;
F_53 ( & V_2 -> V_96 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_43 ) ) ) {
F_10 ( V_23 , V_17 , V_18 ) ;
V_82 = 0 ;
}
F_55 ( & V_2 -> V_96 ) ;
return V_82 ;
}
static int F_68 ( struct V_6 * V_5 , int V_149 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_53 ( & V_2 -> V_96 ) ;
if ( V_23 -> type != V_27 )
V_23 -> V_10 -> V_150 ( V_23 , V_149 ) ;
F_55 ( & V_2 -> V_96 ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_8 , V_82 ;
if ( ! F_19 ( V_41 ) )
return - V_123 ;
if ( F_70 ( & V_2 -> V_96 ) )
return - V_151 ;
V_82 = - V_129 ;
if ( F_61 ( V_2 ) == 1 ) {
F_23 ( V_5 , V_4 ) ;
if ( V_23 -> type != V_27 )
V_23 -> V_10 -> V_136 ( V_23 ) ;
V_8 = V_152 ;
if ( V_23 -> V_8 & V_153 )
V_8 |= V_154 ;
V_23 -> V_10 -> V_155 ( V_23 , V_8 ) ;
V_82 = F_20 ( V_5 , V_4 , 1 ) ;
}
F_55 ( & V_2 -> V_96 ) ;
return V_82 ;
}
static int
F_71 ( struct V_3 * V_4 , unsigned long V_156 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_72 ( V_157 , V_142 ) ;
struct V_158 V_159 , V_160 ;
int V_82 ;
F_17 ( & V_23 -> V_9 ) ;
memcpy ( & V_159 , & V_23 -> V_161 , sizeof( struct V_158 ) ) ;
V_23 -> V_10 -> V_162 ( V_23 ) ;
F_18 ( & V_23 -> V_9 ) ;
F_73 ( & V_2 -> V_163 , & V_157 ) ;
for (; ; ) {
F_17 ( & V_23 -> V_9 ) ;
memcpy ( & V_160 , & V_23 -> V_161 , sizeof( struct V_158 ) ) ;
F_18 ( & V_23 -> V_9 ) ;
F_74 ( V_164 ) ;
if ( ( ( V_156 & V_165 ) && ( V_160 . V_166 != V_159 . V_166 ) ) ||
( ( V_156 & V_167 ) && ( V_160 . V_168 != V_159 . V_168 ) ) ||
( ( V_156 & V_169 ) && ( V_160 . V_170 != V_159 . V_170 ) ) ||
( ( V_156 & V_40 ) && ( V_160 . V_171 != V_159 . V_171 ) ) ) {
V_82 = 0 ;
break;
}
F_75 () ;
if ( F_76 ( V_142 ) ) {
V_82 = - V_151 ;
break;
}
V_159 = V_160 ;
}
V_142 -> V_4 = V_172 ;
F_77 ( & V_2 -> V_163 , & V_157 ) ;
return V_82 ;
}
static int F_78 ( struct V_6 * V_5 ,
struct V_173 * V_161 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_158 V_160 ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_17 ( & V_23 -> V_9 ) ;
memcpy ( & V_160 , & V_23 -> V_161 , sizeof( struct V_158 ) ) ;
F_18 ( & V_23 -> V_9 ) ;
V_161 -> V_171 = V_160 . V_171 ;
V_161 -> V_168 = V_160 . V_168 ;
V_161 -> V_166 = V_160 . V_166 ;
V_161 -> V_170 = V_160 . V_170 ;
V_161 -> V_174 = V_160 . V_174 ;
V_161 -> V_175 = V_160 . V_175 ;
V_161 -> V_176 = V_160 . V_176 ;
V_161 -> V_177 = V_160 . V_177 ;
V_161 -> V_178 = V_160 . V_178 ;
V_161 -> V_179 = V_160 . V_179 ;
V_161 -> V_180 = V_160 . V_180 ;
return 0 ;
}
static int
F_79 ( struct V_6 * V_5 , unsigned int V_181 ,
unsigned long V_156 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
void T_2 * V_182 = ( void T_2 * ) V_156 ;
int V_82 = - V_183 ;
switch ( V_181 ) {
case V_184 :
V_82 = F_52 ( V_4 , V_182 ) ;
break;
case V_185 :
V_82 = F_57 ( V_5 , V_4 , V_182 ) ;
break;
case V_186 :
V_82 = F_69 ( V_5 , V_4 ) ;
break;
case V_187 :
case V_188 :
V_82 = 0 ;
break;
}
if ( V_82 != - V_183 )
goto V_189;
if ( V_5 -> V_8 & ( 1 << V_43 ) ) {
V_82 = - V_148 ;
goto V_189;
}
switch ( V_181 ) {
case V_190 :
V_82 = F_71 ( V_4 , V_156 ) ;
break;
}
if ( V_82 != - V_183 )
goto V_189;
F_53 ( & V_2 -> V_96 ) ;
if ( V_5 -> V_8 & ( 1 << V_43 ) ) {
V_82 = - V_148 ;
goto V_191;
}
switch ( V_181 ) {
case V_192 :
V_82 = F_64 ( V_5 , V_4 , V_182 ) ;
break;
default: {
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_23 -> V_10 -> V_193 )
V_82 = V_23 -> V_10 -> V_193 ( V_23 , V_181 , V_156 ) ;
break;
}
}
V_191:
F_55 ( & V_2 -> V_96 ) ;
V_189:
return V_82 ;
}
static void F_80 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_23 -> V_10 -> V_194 )
V_23 -> V_10 -> V_194 ( V_23 , V_5 -> V_33 -> V_195 ) ;
}
static void F_81 ( struct V_6 * V_5 ,
struct V_58 * V_73 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
unsigned int V_32 = V_5 -> V_33 -> V_34 ;
#define F_82 ( T_3 ) ((iflag) & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK))
if ( ( V_32 ^ V_73 -> V_34 ) == 0 &&
V_5 -> V_33 -> V_196 == V_73 -> V_196 &&
V_5 -> V_33 -> V_197 == V_73 -> V_197 &&
F_82 ( V_5 -> V_33 -> V_198 ^ V_73 -> V_198 ) == 0 ) {
return;
}
F_15 ( V_5 , V_4 , V_73 ) ;
if ( ( V_73 -> V_34 & V_35 ) && ! ( V_32 & V_35 ) )
F_25 ( V_4 -> V_1 , V_36 | V_37 ) ;
else if ( ! ( V_73 -> V_34 & V_35 ) && ( V_32 & V_35 ) ) {
unsigned int V_199 = V_37 ;
if ( ! ( V_32 & V_74 ) ||
! F_83 ( V_200 , & V_5 -> V_8 ) )
V_199 |= V_36 ;
F_16 ( V_4 -> V_1 , V_199 ) ;
}
if ( ( V_73 -> V_34 & V_74 ) && ! ( V_32 & V_74 ) ) {
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_5 -> V_15 = 0 ;
F_7 ( V_5 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
}
else if ( ! ( V_73 -> V_34 & V_74 ) && ( V_32 & V_74 ) ) {
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
if ( ! ( V_4 -> V_1 -> V_10 -> V_39 ( V_4 -> V_1 ) & V_40 ) ) {
V_5 -> V_15 = 1 ;
V_4 -> V_1 -> V_10 -> V_11 ( V_4 -> V_1 ) ;
}
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
}
}
static void F_84 ( struct V_6 * V_5 , struct V_201 * V_202 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 ;
struct V_1 * V_23 ;
unsigned long V_8 ;
if ( ! V_4 )
return;
V_23 = V_4 -> V_1 ;
V_2 = & V_4 -> V_2 ;
F_45 ( L_4 , V_23 -> line ) ;
if ( F_85 ( V_2 , V_5 , V_202 ) == 0 )
return;
if ( V_2 -> V_8 & V_42 ) {
unsigned long V_8 ;
F_5 ( & V_23 -> V_9 , V_8 ) ;
V_23 -> V_10 -> V_203 ( V_23 ) ;
F_6 ( & V_23 -> V_9 , V_8 ) ;
F_86 ( V_5 , V_23 -> V_56 ) ;
}
F_53 ( & V_2 -> V_96 ) ;
F_23 ( V_5 , V_4 ) ;
F_44 ( V_5 ) ;
F_87 ( V_5 ) ;
F_88 ( V_2 , NULL ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_5 -> V_204 = 0 ;
if ( V_2 -> V_205 ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_103 )
F_89 (
F_54 ( V_2 -> V_103 ) ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
} else if ( ! F_14 ( V_23 ) ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_90 ( V_4 , 3 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
}
F_22 ( V_206 , & V_2 -> V_8 ) ;
F_22 ( V_207 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_91 ( & V_2 -> V_208 ) ;
F_91 ( & V_2 -> V_209 ) ;
F_55 ( & V_2 -> V_96 ) ;
}
static void F_86 ( struct V_6 * V_5 , int V_56 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_210 , V_211 ;
if ( V_2 -> type == V_27 || V_2 -> V_55 == 0 )
return;
V_210 = ( V_2 -> V_56 - V_57 / 50 ) / V_2 -> V_55 ;
V_210 = V_210 / 5 ;
if ( V_210 == 0 )
V_210 = 1 ;
if ( V_56 && V_56 < V_210 )
V_210 = V_56 ;
if ( V_56 == 0 || V_56 > 2 * V_2 -> V_56 )
V_56 = 2 * V_2 -> V_56 ;
V_211 = V_212 + V_56 ;
F_45 ( L_5 ,
V_2 -> line , V_212 , V_211 ) ;
while ( ! V_2 -> V_10 -> V_146 ( V_2 ) ) {
F_89 ( F_54 ( V_210 ) ) ;
if ( F_76 ( V_142 ) )
break;
if ( F_92 ( V_212 , V_211 ) )
break;
}
}
static void F_93 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
unsigned long V_8 ;
F_45 ( L_6 , V_4 -> V_1 -> line ) ;
F_53 ( & V_2 -> V_96 ) ;
if ( V_2 -> V_8 & V_213 ) {
F_44 ( V_5 ) ;
F_23 ( V_5 , V_4 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_86 = 0 ;
F_22 ( V_206 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_88 ( V_2 , NULL ) ;
F_91 ( & V_2 -> V_208 ) ;
F_91 ( & V_2 -> V_163 ) ;
}
F_55 ( & V_2 -> V_96 ) ;
}
static int F_94 ( struct V_24 * V_2 , struct V_6 * V_5 )
{
return 0 ;
}
static void F_26 ( struct V_24 * V_2 )
{
struct V_3 * V_4 = F_95 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_91 ( & V_2 -> V_163 ) ;
V_23 -> V_10 -> V_214 ( V_23 ) ;
F_96 ( V_23 -> V_100 ) ;
}
static int F_97 ( struct V_24 * V_2 )
{
struct V_3 * V_4 = F_95 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
int V_20 ;
F_17 ( & V_23 -> V_9 ) ;
V_23 -> V_10 -> V_162 ( V_23 ) ;
V_20 = V_23 -> V_10 -> V_39 ( V_23 ) ;
F_18 ( & V_23 -> V_9 ) ;
if ( V_20 & V_215 )
return 1 ;
return 0 ;
}
static void F_98 ( struct V_24 * V_2 , int V_216 )
{
struct V_3 * V_4 = F_95 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_216 )
F_16 ( V_23 , V_37 | V_36 ) ;
else
F_25 ( V_23 , V_37 | V_36 ) ;
}
static int F_99 ( struct V_6 * V_5 , struct V_201 * V_202 )
{
struct V_217 * V_218 = (struct V_217 * ) V_5 -> V_219 -> V_220 ;
int V_26 , line = V_5 -> V_89 ;
struct V_3 * V_4 = V_218 -> V_4 + line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_45 ( L_7 , line ) ;
if ( F_70 ( & V_2 -> V_96 ) ) {
V_26 = - V_151 ;
goto V_221;
}
V_2 -> V_86 ++ ;
if ( ! V_4 -> V_1 || V_4 -> V_1 -> V_8 & V_222 ) {
V_26 = - V_223 ;
goto V_224;
}
V_5 -> V_7 = V_4 ;
V_4 -> V_1 -> V_4 = V_4 ;
V_5 -> V_139 = ( V_4 -> V_1 -> V_8 & V_140 ) ? 1 : 0 ;
F_88 ( V_2 , V_5 ) ;
if ( F_100 ( V_202 ) ) {
V_26 = - V_225 ;
goto V_224;
}
if ( V_2 -> V_86 == 1 )
F_90 ( V_4 , 0 ) ;
V_26 = F_20 ( V_5 , V_4 , 0 ) ;
F_55 ( & V_2 -> V_96 ) ;
if ( V_26 == 0 )
V_26 = F_101 ( V_2 , V_5 , V_202 ) ;
V_221:
return V_26 ;
V_224:
V_2 -> V_86 -- ;
F_55 ( & V_2 -> V_96 ) ;
goto V_221;
}
static const char * F_102 ( struct V_1 * V_2 )
{
const char * V_226 = NULL ;
if ( V_2 -> V_10 -> type )
V_226 = V_2 -> V_10 -> type ( V_2 ) ;
if ( ! V_226 )
V_226 = L_8 ;
return V_226 ;
}
static void F_103 ( struct V_227 * V_228 , struct V_217 * V_218 , int V_229 )
{
struct V_3 * V_4 = V_218 -> V_4 + V_229 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_230 ;
struct V_1 * V_23 = V_4 -> V_1 ;
char V_231 [ 32 ] ;
unsigned int V_232 ;
int V_233 ;
if ( ! V_23 )
return;
V_233 = V_23 -> V_108 >= V_234 ;
F_104 ( V_228 , L_9 ,
V_23 -> line , F_102 ( V_23 ) ,
V_233 ? L_10 : L_11 ,
V_233 ? ( unsigned long long ) V_23 -> V_112
: ( unsigned long long ) V_23 -> V_97 ,
V_23 -> V_100 ) ;
if ( V_23 -> type == V_27 ) {
F_105 ( V_228 , '\n' ) ;
return;
}
if ( F_19 ( V_41 ) ) {
F_53 ( & V_2 -> V_96 ) ;
V_230 = V_4 -> V_230 ;
if ( V_230 )
F_90 ( V_4 , 0 ) ;
F_17 ( & V_23 -> V_9 ) ;
V_232 = V_23 -> V_10 -> V_39 ( V_23 ) ;
F_18 ( & V_23 -> V_9 ) ;
if ( V_230 )
F_90 ( V_4 , V_230 ) ;
F_55 ( & V_2 -> V_96 ) ;
F_104 ( V_228 , L_12 ,
V_23 -> V_161 . V_175 , V_23 -> V_161 . V_174 ) ;
if ( V_23 -> V_161 . V_176 )
F_104 ( V_228 , L_13 ,
V_23 -> V_161 . V_176 ) ;
if ( V_23 -> V_161 . V_178 )
F_104 ( V_228 , L_14 ,
V_23 -> V_161 . V_178 ) ;
if ( V_23 -> V_161 . V_179 )
F_104 ( V_228 , L_15 ,
V_23 -> V_161 . V_179 ) ;
if ( V_23 -> V_161 . V_177 )
F_104 ( V_228 , L_16 ,
V_23 -> V_161 . V_177 ) ;
#define F_106 ( T_4 , V_226 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_107 ( T_4 , V_226 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_231 [ 0 ] = '\0' ;
V_231 [ 1 ] = '\0' ;
F_106 ( V_36 , L_17 ) ;
F_107 ( V_40 , L_18 ) ;
F_106 ( V_37 , L_19 ) ;
F_107 ( V_167 , L_20 ) ;
F_107 ( V_215 , L_21 ) ;
F_107 ( V_165 , L_22 ) ;
if ( V_231 [ 0 ] )
V_231 [ 0 ] = ' ' ;
F_108 ( V_228 , V_231 ) ;
}
F_105 ( V_228 , '\n' ) ;
#undef F_107
#undef F_106
}
static int F_109 ( struct V_227 * V_228 , void * V_235 )
{
struct V_236 * V_237 = V_228 -> V_238 ;
struct V_217 * V_218 = V_237 -> V_220 ;
int V_229 ;
F_104 ( V_228 , L_23 ,
L_24 , L_24 , L_24 ) ;
for ( V_229 = 0 ; V_229 < V_218 -> V_239 ; V_229 ++ )
F_103 ( V_228 , V_218 , V_229 ) ;
return 0 ;
}
static int F_110 ( struct V_240 * V_240 , struct V_201 * V_201 )
{
return F_111 ( V_201 , F_109 , F_112 ( V_240 ) -> V_241 ) ;
}
void F_113 ( struct V_1 * V_2 , const char * V_242 ,
unsigned int V_86 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_229 ;
for ( V_229 = 0 ; V_229 < V_86 ; V_229 ++ , V_242 ++ ) {
if ( * V_242 == '\n' )
putchar ( V_2 , '\r' ) ;
putchar ( V_2 , * V_242 ) ;
}
}
struct V_1 * T_5
F_114 ( struct V_1 * V_243 , int V_239 , struct V_244 * V_245 )
{
int V_246 = V_245 -> V_89 ;
if ( V_246 < 0 || V_246 >= V_239 || ( V_243 [ V_246 ] . V_97 == 0 &&
V_243 [ V_246 ] . V_247 == NULL ) )
for ( V_246 = 0 ; V_246 < V_239 ; V_246 ++ )
if ( V_243 [ V_246 ] . V_97 != 0 ||
V_243 [ V_246 ] . V_247 != NULL )
break;
V_245 -> V_89 = V_246 ;
return V_243 + V_246 ;
}
void
F_115 ( char * V_248 , int * V_47 , int * V_178 , int * V_48 , int * V_249 )
{
char * V_242 = V_248 ;
* V_47 = F_116 ( V_242 , NULL , 10 ) ;
while ( * V_242 >= '0' && * V_242 <= '9' )
V_242 ++ ;
if ( * V_242 )
* V_178 = * V_242 ++ ;
if ( * V_242 )
* V_48 = * V_242 ++ - '0' ;
if ( * V_242 )
* V_249 = * V_242 ;
}
int
F_117 ( struct V_1 * V_2 , struct V_244 * V_245 ,
int V_47 , int V_178 , int V_48 , int V_249 )
{
struct V_58 V_33 ;
static struct V_58 V_250 ;
int V_229 ;
F_118 ( & V_2 -> V_9 ) ;
F_119 ( & V_2 -> V_9 , & V_251 ) ;
memset ( & V_33 , 0 , sizeof( struct V_58 ) ) ;
V_33 . V_34 = V_252 | V_45 | V_76 ;
for ( V_229 = 0 ; V_253 [ V_229 ] . V_254 ; V_229 ++ )
if ( V_253 [ V_229 ] . V_254 <= V_47 )
break;
V_33 . V_34 |= V_253 [ V_229 ] . V_32 ;
if ( V_48 == 7 )
V_33 . V_34 |= V_52 ;
else
V_33 . V_34 |= V_255 ;
switch ( V_178 ) {
case 'o' : case 'O' :
V_33 . V_34 |= V_256 ;
case 'e' : case 'E' :
V_33 . V_34 |= V_54 ;
break;
}
if ( V_249 == 'r' )
V_33 . V_34 |= V_74 ;
V_2 -> V_20 |= V_37 ;
V_2 -> V_10 -> V_78 ( V_2 , & V_33 , & V_250 ) ;
if ( V_245 )
V_245 -> V_32 = V_33 . V_34 ;
return 0 ;
}
static void F_90 ( struct V_3 * V_4 , int V_230 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
if ( V_4 -> V_230 != V_230 ) {
if ( V_2 -> V_10 -> V_257 )
V_2 -> V_10 -> V_257 ( V_2 , V_230 , V_4 -> V_230 ) ;
V_4 -> V_230 = V_230 ;
}
}
static int F_120 ( struct V_258 * V_259 , void * V_241 )
{
struct V_260 * V_261 = V_241 ;
struct V_236 * V_262 = V_261 -> V_219 -> V_236 ;
T_6 V_263 = F_121 ( V_262 -> V_264 , V_262 -> V_265 ) +
V_261 -> V_2 -> line ;
return V_259 -> V_263 == V_263 ;
}
int F_122 ( struct V_217 * V_218 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_218 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_258 * V_266 ;
struct V_260 V_261 = { V_23 , V_218 } ;
F_53 ( & V_2 -> V_96 ) ;
V_266 = F_123 ( V_23 -> V_259 , & V_261 , F_120 ) ;
if ( F_124 ( V_266 ) ) {
if ( ! F_125 ( V_23 -> V_100 ) )
V_23 -> V_267 = 1 ;
F_126 ( V_266 ) ;
F_55 ( & V_2 -> V_96 ) ;
return 0 ;
}
if ( V_268 || ! F_14 ( V_23 ) )
V_23 -> V_269 = 1 ;
if ( V_2 -> V_8 & V_42 ) {
const struct V_270 * V_10 = V_23 -> V_10 ;
int V_271 ;
if ( V_268 || ! F_14 ( V_23 ) ) {
F_21 ( V_46 , & V_2 -> V_8 ) ;
F_22 ( V_44 , & V_2 -> V_8 ) ;
F_17 ( & V_23 -> V_9 ) ;
V_10 -> V_11 ( V_23 ) ;
V_10 -> V_21 ( V_23 , 0 ) ;
V_10 -> V_203 ( V_23 ) ;
F_18 ( & V_23 -> V_9 ) ;
}
for ( V_271 = 3 ; ! V_10 -> V_146 ( V_23 ) && V_271 ; V_271 -- )
F_127 ( 10 ) ;
if ( ! V_271 )
F_62 ( V_272 L_25
L_26 ,
V_23 -> V_259 ? F_128 ( V_23 -> V_259 ) : L_24 ,
V_23 -> V_259 ? L_27 : L_24 ,
V_218 -> F_128 ,
V_218 -> V_236 -> V_273 + V_23 -> line ) ;
if ( V_268 || ! F_14 ( V_23 ) )
V_10 -> V_214 ( V_23 ) ;
}
if ( V_268 && F_14 ( V_23 ) )
F_129 ( V_23 -> V_31 ) ;
if ( V_268 || ! F_14 ( V_23 ) )
F_90 ( V_4 , 3 ) ;
F_55 ( & V_2 -> V_96 ) ;
return 0 ;
}
int F_130 ( struct V_217 * V_218 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_218 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_258 * V_266 ;
struct V_260 V_261 = { V_23 , V_218 } ;
struct V_58 V_33 ;
F_53 ( & V_2 -> V_96 ) ;
V_266 = F_123 ( V_23 -> V_259 , & V_261 , F_120 ) ;
if ( ! V_23 -> V_269 && F_124 ( V_266 ) ) {
if ( V_23 -> V_267 ) {
F_131 ( V_23 -> V_100 ) ;
V_23 -> V_267 = 0 ;
}
F_55 ( & V_2 -> V_96 ) ;
return 0 ;
}
V_23 -> V_269 = 0 ;
if ( F_14 ( V_23 ) ) {
memset ( & V_33 , 0 , sizeof( struct V_58 ) ) ;
V_33 . V_34 = V_23 -> V_31 -> V_32 ;
if ( V_2 -> V_5 && V_2 -> V_5 -> V_33 && V_33 . V_34 == 0 )
V_33 = * ( V_2 -> V_5 -> V_33 ) ;
if ( V_268 )
F_90 ( V_4 , 0 ) ;
V_23 -> V_10 -> V_78 ( V_23 , & V_33 , NULL ) ;
if ( V_268 )
F_132 ( V_23 -> V_31 ) ;
}
if ( V_2 -> V_8 & V_274 ) {
const struct V_270 * V_10 = V_23 -> V_10 ;
int V_82 ;
F_90 ( V_4 , 0 ) ;
F_17 ( & V_23 -> V_9 ) ;
V_10 -> V_21 ( V_23 , 0 ) ;
F_18 ( & V_23 -> V_9 ) ;
if ( V_268 || ! F_14 ( V_23 ) ) {
struct V_6 * V_5 = V_2 -> V_5 ;
V_82 = V_10 -> V_30 ( V_23 ) ;
if ( V_82 == 0 ) {
if ( V_5 )
F_15 ( V_5 , V_4 , NULL ) ;
F_17 ( & V_23 -> V_9 ) ;
V_10 -> V_21 ( V_23 , V_23 -> V_20 ) ;
V_10 -> V_16 ( V_23 ) ;
F_18 ( & V_23 -> V_9 ) ;
F_21 ( V_44 , & V_2 -> V_8 ) ;
} else {
F_23 ( V_5 , V_4 ) ;
}
}
F_22 ( V_46 , & V_2 -> V_8 ) ;
}
F_55 ( & V_2 -> V_96 ) ;
return 0 ;
}
static inline void
F_133 ( struct V_217 * V_218 , struct V_1 * V_2 )
{
char V_275 [ 64 ] ;
switch ( V_2 -> V_108 ) {
case V_276 :
snprintf ( V_275 , sizeof( V_275 ) , L_28 , V_2 -> V_97 ) ;
break;
case V_277 :
snprintf ( V_275 , sizeof( V_275 ) ,
L_29 , V_2 -> V_97 , V_2 -> V_106 ) ;
break;
case V_234 :
case V_278 :
case V_279 :
case V_280 :
snprintf ( V_275 , sizeof( V_275 ) ,
L_30 , ( unsigned long long ) V_2 -> V_112 ) ;
break;
default:
F_134 ( V_275 , L_31 , sizeof( V_275 ) ) ;
break;
}
F_62 ( V_281 L_32 ,
V_2 -> V_259 ? F_128 ( V_2 -> V_259 ) : L_24 ,
V_2 -> V_259 ? L_27 : L_24 ,
V_218 -> F_128 ,
V_218 -> V_236 -> V_273 + V_2 -> line ,
V_275 , V_2 -> V_100 , F_102 ( V_2 ) ) ;
}
static void
F_135 ( struct V_217 * V_218 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
unsigned int V_8 ;
if ( ! V_2 -> V_97 && ! V_2 -> V_112 && ! V_2 -> V_247 )
return;
V_8 = 0 ;
if ( V_2 -> V_8 & V_153 )
V_8 |= V_154 ;
if ( V_2 -> V_8 & V_282 ) {
if ( ! ( V_2 -> V_8 & V_283 ) ) {
V_2 -> type = V_27 ;
V_8 |= V_152 ;
}
V_2 -> V_10 -> V_155 ( V_2 , V_8 ) ;
}
if ( V_2 -> type != V_27 ) {
unsigned long V_8 ;
F_133 ( V_218 , V_2 ) ;
F_90 ( V_4 , 0 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_10 -> V_21 ( V_2 , V_2 -> V_20 & V_37 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_31 && ! ( V_2 -> V_31 -> V_8 & V_284 ) )
F_136 ( V_2 -> V_31 ) ;
if ( ! F_14 ( V_2 ) )
F_90 ( V_4 , 3 ) ;
}
}
static int F_137 ( struct V_236 * V_219 , int line , char * V_248 )
{
struct V_217 * V_218 = V_219 -> V_220 ;
struct V_3 * V_4 = V_218 -> V_4 + line ;
struct V_1 * V_2 ;
int V_47 = 9600 ;
int V_48 = 8 ;
int V_178 = 'n' ;
int V_249 = 'n' ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
if ( ! ( V_2 -> V_10 -> V_285 && V_2 -> V_10 -> V_286 ) )
return - 1 ;
if ( V_248 ) {
F_115 ( V_248 , & V_47 , & V_178 , & V_48 , & V_249 ) ;
return F_117 ( V_2 , NULL , V_47 , V_178 , V_48 , V_249 ) ;
}
return 0 ;
}
static int F_138 ( struct V_236 * V_219 , int line )
{
struct V_217 * V_218 = V_219 -> V_220 ;
struct V_3 * V_4 = V_218 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
return V_2 -> V_10 -> V_285 ( V_2 ) ;
}
static void F_139 ( struct V_236 * V_219 , int line , char V_85 )
{
struct V_217 * V_218 = V_219 -> V_220 ;
struct V_3 * V_4 = V_218 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return;
V_2 = V_4 -> V_1 ;
V_2 -> V_10 -> V_286 ( V_2 , V_85 ) ;
}
int F_140 ( struct V_217 * V_218 )
{
struct V_236 * V_287 ;
int V_229 , V_26 ;
F_2 ( V_218 -> V_4 ) ;
V_218 -> V_4 = F_141 ( sizeof( struct V_3 ) * V_218 -> V_239 , V_28 ) ;
if ( ! V_218 -> V_4 )
goto V_189;
V_287 = F_142 ( V_218 -> V_239 ) ;
if ( ! V_287 )
goto V_288;
V_218 -> V_236 = V_287 ;
V_287 -> V_289 = V_218 -> V_289 ;
V_287 -> V_290 = V_218 -> F_128 ;
V_287 -> V_264 = V_218 -> V_264 ;
V_287 -> V_265 = V_218 -> V_291 ;
V_287 -> type = V_292 ;
V_287 -> V_293 = V_294 ;
V_287 -> V_295 = V_296 ;
V_287 -> V_295 . V_34 = V_297 | V_255 | V_252 | V_45 | V_76 ;
V_287 -> V_295 . V_197 = V_287 -> V_295 . V_196 = 9600 ;
V_287 -> V_8 = V_298 | V_299 ;
V_287 -> V_220 = V_218 ;
F_143 ( V_287 , & V_270 ) ;
for ( V_229 = 0 ; V_229 < V_218 -> V_239 ; V_229 ++ ) {
struct V_3 * V_4 = V_218 -> V_4 + V_229 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_144 ( V_2 ) ;
V_2 -> V_10 = & V_300 ;
V_2 -> V_103 = V_57 / 2 ;
V_2 -> V_104 = 30 * V_57 ;
}
V_26 = F_145 ( V_287 ) ;
if ( V_26 >= 0 )
return V_26 ;
F_146 ( V_287 ) ;
V_288:
F_147 ( V_218 -> V_4 ) ;
V_189:
return - V_29 ;
}
void F_148 ( struct V_217 * V_218 )
{
struct V_236 * V_301 = V_218 -> V_236 ;
F_149 ( V_301 ) ;
F_146 ( V_301 ) ;
F_147 ( V_218 -> V_4 ) ;
V_218 -> V_4 = NULL ;
V_218 -> V_236 = NULL ;
}
struct V_236 * F_150 ( struct V_244 * V_245 , int * V_89 )
{
struct V_217 * V_301 = V_245 -> V_241 ;
* V_89 = V_245 -> V_89 ;
return V_301 -> V_236 ;
}
int F_151 ( struct V_217 * V_218 , struct V_1 * V_23 )
{
struct V_3 * V_4 ;
struct V_24 * V_2 ;
int V_82 = 0 ;
struct V_258 * V_266 ;
F_2 ( F_152 () ) ;
if ( V_23 -> line >= V_218 -> V_239 )
return - V_128 ;
V_4 = V_218 -> V_4 + V_23 -> line ;
V_2 = & V_4 -> V_2 ;
F_53 ( & V_302 ) ;
F_53 ( & V_2 -> V_96 ) ;
if ( V_4 -> V_1 ) {
V_82 = - V_128 ;
goto V_189;
}
V_4 -> V_1 = V_23 ;
V_4 -> V_230 = - 1 ;
V_23 -> V_31 = V_218 -> V_31 ;
V_23 -> V_4 = V_4 ;
if ( ! ( F_14 ( V_23 ) && ( V_23 -> V_31 -> V_8 & V_284 ) ) ) {
F_118 ( & V_23 -> V_9 ) ;
F_119 ( & V_23 -> V_9 , & V_251 ) ;
}
F_135 ( V_218 , V_4 , V_23 ) ;
V_266 = F_153 ( V_218 -> V_236 , V_23 -> line , V_23 -> V_259 ) ;
if ( F_154 ( ! F_155 ( V_266 ) ) ) {
F_156 ( V_266 , 1 ) ;
} else {
F_62 ( V_272 L_33 ,
V_23 -> line ) ;
}
V_23 -> V_8 &= ~ V_222 ;
V_189:
F_55 ( & V_2 -> V_96 ) ;
F_55 ( & V_302 ) ;
return V_82 ;
}
int F_157 ( struct V_217 * V_218 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_218 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_2 ( F_152 () ) ;
if ( V_4 -> V_1 != V_23 )
F_62 ( V_303 L_34 ,
V_4 -> V_1 , V_23 ) ;
F_53 ( & V_302 ) ;
F_53 ( & V_2 -> V_96 ) ;
V_23 -> V_8 |= V_222 ;
F_55 ( & V_2 -> V_96 ) ;
F_158 ( V_218 -> V_236 , V_23 -> line ) ;
if ( V_2 -> V_5 )
F_159 ( V_2 -> V_5 ) ;
if ( V_23 -> type != V_27 )
V_23 -> V_10 -> V_136 ( V_23 ) ;
V_23 -> type = V_27 ;
V_4 -> V_1 = NULL ;
F_55 ( & V_302 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_304 , struct V_1 * V_305 )
{
if ( V_304 -> V_108 != V_305 -> V_108 )
return 0 ;
switch ( V_304 -> V_108 ) {
case V_276 :
return ( V_304 -> V_97 == V_305 -> V_97 ) ;
case V_277 :
return ( V_304 -> V_97 == V_305 -> V_97 ) &&
( V_304 -> V_106 == V_305 -> V_106 ) ;
case V_234 :
case V_278 :
case V_279 :
case V_280 :
return ( V_304 -> V_112 == V_305 -> V_112 ) ;
}
return 0 ;
}
void F_161 ( struct V_1 * V_23 , unsigned int V_232 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_306 * V_307 = F_162 ( V_2 -> V_5 ) ;
struct V_308 V_309 ;
if ( V_307 && V_307 -> V_10 -> V_310 )
F_163 ( & V_309 ) ;
V_23 -> V_161 . V_170 ++ ;
#ifdef F_164
if ( ( V_23 -> V_8 & V_311 ) && V_232 )
F_165 () ;
#endif
if ( V_2 -> V_8 & V_312 ) {
if ( V_232 )
F_91 ( & V_2 -> V_208 ) ;
else if ( V_2 -> V_5 )
F_166 ( V_2 -> V_5 ) ;
}
if ( V_307 && V_307 -> V_10 -> V_310 )
V_307 -> V_10 -> V_310 ( V_2 -> V_5 , V_232 , & V_309 ) ;
if ( V_307 )
F_167 ( V_307 ) ;
}
void F_168 ( struct V_1 * V_23 , unsigned int V_232 )
{
struct V_24 * V_2 = & V_23 -> V_4 -> V_2 ;
struct V_6 * V_5 = V_2 -> V_5 ;
V_23 -> V_161 . V_171 ++ ;
if ( V_2 -> V_8 & V_38 ) {
if ( V_5 -> V_15 ) {
if ( V_232 ) {
V_5 -> V_15 = 0 ;
V_23 -> V_10 -> V_16 ( V_23 ) ;
F_1 ( V_23 ) ;
}
} else {
if ( ! V_232 ) {
V_5 -> V_15 = 1 ;
V_23 -> V_10 -> V_11 ( V_23 ) ;
}
}
}
}
void F_169 ( struct V_1 * V_2 , unsigned int V_232 ,
unsigned int V_177 , unsigned int V_85 , unsigned int V_313 )
{
struct V_6 * V_5 = V_2 -> V_4 -> V_2 . V_5 ;
if ( ( V_232 & V_2 -> V_314 & ~ V_177 ) == 0 )
F_170 ( V_5 , V_85 , V_313 ) ;
if ( V_232 & ~ V_2 -> V_314 & V_177 )
F_170 ( V_5 , 0 , V_315 ) ;
}
