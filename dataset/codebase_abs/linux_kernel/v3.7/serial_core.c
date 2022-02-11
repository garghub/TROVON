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
if ( F_49 ( V_5 ) )
F_47 ( V_5 , F_50 ( V_5 ) ) ;
if ( V_5 -> V_33 . V_34 & V_73 )
F_26 ( V_4 -> V_1 , V_36 ) ;
}
static void F_51 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
if ( F_49 ( V_5 ) ) {
if ( V_2 -> V_91 )
V_2 -> V_91 = 0 ;
else
F_47 ( V_5 , F_52 ( V_5 ) ) ;
}
if ( V_5 -> V_33 . V_34 & V_73 )
F_16 ( V_2 , V_36 ) ;
}
static void F_53 ( struct V_24 * V_2 ,
struct V_3 * V_4 ,
struct V_92 * V_93 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
V_93 -> type = V_23 -> type ;
V_93 -> line = V_23 -> line ;
V_93 -> V_2 = V_23 -> V_94 ;
if ( V_95 )
V_93 -> V_96 = ( long ) V_23 -> V_94 >> V_95 ;
V_93 -> V_97 = V_23 -> V_97 ;
V_93 -> V_8 = V_23 -> V_8 ;
V_93 -> V_98 = V_23 -> V_54 ;
V_93 -> V_99 = V_23 -> V_71 / 16 ;
V_93 -> V_100 = F_54 ( V_2 -> V_100 ) / 10 ;
V_93 -> V_101 = V_2 -> V_101 == V_102 ?
V_102 :
F_54 ( V_2 -> V_101 ) / 10 ;
V_93 -> V_70 = V_23 -> V_70 ;
V_93 -> V_103 = V_23 -> V_103 ;
V_93 -> V_104 = V_23 -> V_105 ;
V_93 -> V_106 = V_23 -> V_107 ;
V_93 -> V_108 = ( void * ) ( unsigned long ) V_23 -> V_109 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_92 T_2 * V_93 )
{
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_92 V_110 ;
F_56 ( & V_2 -> V_111 ) ;
F_53 ( V_2 , V_4 , & V_110 ) ;
F_57 ( & V_2 -> V_111 ) ;
if ( F_58 ( V_93 , & V_110 , sizeof( * V_93 ) ) )
return - V_112 ;
return 0 ;
}
static int F_59 ( struct V_6 * V_5 , struct V_24 * V_2 ,
struct V_3 * V_4 ,
struct V_92 * V_113 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
unsigned long V_114 ;
unsigned int V_115 , V_116 , V_101 ;
unsigned int V_117 , V_100 ;
T_1 V_118 , V_119 ;
int V_26 = 0 ;
V_114 = V_113 -> V_2 ;
if ( V_95 )
V_114 += ( unsigned long ) V_113 -> V_96 << V_95 ;
V_113 -> V_97 = F_60 ( V_113 -> V_97 ) ;
V_100 = F_61 ( V_113 -> V_100 * 10 ) ;
V_101 = V_113 -> V_101 == V_102 ?
V_102 :
F_61 ( V_113 -> V_101 * 10 ) ;
V_115 = ! ( V_23 -> V_8 & V_120 )
&& V_113 -> V_97 != V_23 -> V_97 ;
V_116 = ! ( V_23 -> V_8 & V_120 )
&& ( V_114 != V_23 -> V_94 ||
( unsigned long ) V_113 -> V_108 != V_23 -> V_109 ||
V_113 -> V_103 != V_23 -> V_103 ||
V_113 -> V_104 != V_23 -> V_105 ||
V_113 -> V_106 != V_23 -> V_107 ||
V_113 -> type != V_23 -> type ) ;
V_118 = V_23 -> V_8 ;
V_119 = V_113 -> V_8 ;
V_117 = V_23 -> V_70 ;
if ( ! F_20 ( V_40 ) ) {
V_26 = - V_121 ;
if ( V_115 || V_116 ||
( V_113 -> V_99 != V_23 -> V_71 / 16 ) ||
( V_100 != V_2 -> V_100 ) ||
( V_101 != V_2 -> V_101 ) ||
( V_113 -> V_98 &&
V_113 -> V_98 != V_23 -> V_54 ) ||
( ( ( V_119 ^ V_118 ) & ~ V_122 ) != 0 ) )
goto exit;
V_23 -> V_8 = ( ( V_23 -> V_8 & ~ V_122 ) |
( V_119 & V_122 ) ) ;
V_23 -> V_70 = V_113 -> V_70 ;
goto V_123;
}
if ( V_23 -> V_10 -> V_124 )
V_26 = V_23 -> V_10 -> V_124 ( V_23 , V_113 ) ;
if ( ( V_113 -> V_97 >= V_125 ) || ( V_113 -> V_97 < 0 ) ||
( V_113 -> V_99 < 9600 ) )
V_26 = - V_126 ;
if ( V_26 )
goto exit;
if ( V_116 || V_115 ) {
V_26 = - V_127 ;
if ( F_62 ( V_2 ) > 1 )
goto exit;
F_24 ( V_5 , V_4 ) ;
}
if ( V_116 ) {
unsigned long V_128 , V_129 ;
unsigned int V_130 , V_131 , V_132 , V_133 ;
V_128 = V_23 -> V_94 ;
V_129 = V_23 -> V_109 ;
V_130 = V_23 -> type ;
V_132 = V_23 -> V_103 ;
V_131 = V_23 -> V_105 ;
V_133 = V_23 -> V_107 ;
if ( V_130 != V_27 )
V_23 -> V_10 -> V_134 ( V_23 ) ;
V_23 -> V_94 = V_114 ;
V_23 -> type = V_113 -> type ;
V_23 -> V_103 = V_113 -> V_103 ;
V_23 -> V_105 = V_113 -> V_104 ;
V_23 -> V_107 = V_113 -> V_106 ;
V_23 -> V_109 = ( unsigned long ) V_113 -> V_108 ;
if ( V_23 -> type != V_27 ) {
V_26 = V_23 -> V_10 -> V_135 ( V_23 ) ;
} else {
V_26 = 0 ;
}
if ( V_26 && V_130 != V_27 ) {
V_23 -> V_94 = V_128 ;
V_23 -> type = V_130 ;
V_23 -> V_103 = V_132 ;
V_23 -> V_105 = V_131 ;
V_23 -> V_107 = V_133 ;
V_23 -> V_109 = V_129 ;
V_26 = V_23 -> V_10 -> V_135 ( V_23 ) ;
if ( V_26 )
V_23 -> type = V_27 ;
V_26 = - V_127 ;
goto exit;
}
}
if ( V_115 )
V_23 -> V_97 = V_113 -> V_97 ;
if ( ! ( V_23 -> V_8 & V_120 ) )
V_23 -> V_71 = V_113 -> V_99 * 16 ;
V_23 -> V_8 = ( V_23 -> V_8 & ~ V_136 ) |
( V_119 & V_136 ) ;
V_23 -> V_70 = V_113 -> V_70 ;
V_2 -> V_100 = V_100 ;
V_2 -> V_101 = V_101 ;
if ( V_113 -> V_98 )
V_23 -> V_54 = V_113 -> V_98 ;
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_137 =
( V_23 -> V_8 & V_138 ) ? 1 : 0 ;
V_123:
V_26 = 0 ;
if ( V_23 -> type == V_27 )
goto exit;
if ( V_2 -> V_8 & V_41 ) {
if ( ( ( V_118 ^ V_23 -> V_8 ) & V_63 ) ||
V_117 != V_23 -> V_70 ) {
if ( V_23 -> V_8 & V_63 ) {
char V_13 [ 64 ] ;
F_63 ( V_139
L_2
L_3 , V_140 -> V_141 ,
F_64 ( V_2 -> V_5 , V_13 ) ) ;
}
F_15 ( V_5 , V_4 , NULL ) ;
}
} else
V_26 = F_21 ( V_5 , V_4 , 1 ) ;
exit:
return V_26 ;
}
static int F_65 ( struct V_6 * V_5 , struct V_3 * V_4 ,
struct V_92 T_2 * V_142 )
{
struct V_92 V_143 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_26 ;
if ( F_66 ( & V_143 , V_142 , sizeof( V_143 ) ) )
return - V_112 ;
F_56 ( & V_2 -> V_111 ) ;
V_26 = F_59 ( V_5 , V_2 , V_4 , & V_143 ) ;
F_57 ( & V_2 -> V_111 ) ;
return V_26 ;
}
static int F_67 ( struct V_6 * V_5 ,
struct V_3 * V_4 , unsigned int T_2 * V_144 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
unsigned int V_145 ;
V_145 = V_23 -> V_10 -> V_146 ( V_23 ) ;
if ( V_23 -> V_91 ||
( ( F_44 ( & V_4 -> V_12 ) > 0 ) &&
! V_5 -> V_14 && ! V_5 -> V_15 ) )
V_145 &= ~ V_147 ;
return F_68 ( V_145 , V_144 ) ;
}
static int F_69 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
int V_145 = - V_148 ;
F_56 ( & V_2 -> V_111 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_42 ) ) ) {
V_145 = V_23 -> V_20 ;
F_18 ( & V_23 -> V_9 ) ;
V_145 |= V_23 -> V_10 -> V_38 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
}
F_57 ( & V_2 -> V_111 ) ;
return V_145 ;
}
static int
F_70 ( struct V_6 * V_5 , unsigned int V_17 , unsigned int V_18 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_81 = - V_148 ;
F_56 ( & V_2 -> V_111 ) ;
if ( ! ( V_5 -> V_8 & ( 1 << V_42 ) ) ) {
F_10 ( V_23 , V_17 , V_18 ) ;
V_81 = 0 ;
}
F_57 ( & V_2 -> V_111 ) ;
return V_81 ;
}
static int F_71 ( struct V_6 * V_5 , int V_149 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_56 ( & V_2 -> V_111 ) ;
if ( V_23 -> type != V_27 )
V_23 -> V_10 -> V_150 ( V_23 , V_149 ) ;
F_57 ( & V_2 -> V_111 ) ;
return 0 ;
}
static int F_72 ( struct V_6 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
int V_8 , V_81 ;
if ( ! F_20 ( V_40 ) )
return - V_121 ;
if ( F_73 ( & V_2 -> V_111 ) )
return - V_151 ;
V_81 = - V_127 ;
if ( F_62 ( V_2 ) == 1 ) {
F_24 ( V_5 , V_4 ) ;
if ( V_23 -> type != V_27 )
V_23 -> V_10 -> V_134 ( V_23 ) ;
V_8 = V_152 ;
if ( V_23 -> V_8 & V_153 )
V_8 |= V_154 ;
V_23 -> V_10 -> V_155 ( V_23 , V_8 ) ;
V_81 = F_21 ( V_5 , V_4 , 1 ) ;
}
F_57 ( & V_2 -> V_111 ) ;
return V_81 ;
}
static int
F_74 ( struct V_3 * V_4 , unsigned long V_156 )
{
struct V_1 * V_23 = V_4 -> V_1 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_75 ( V_157 , V_140 ) ;
struct V_158 V_159 , V_160 ;
int V_81 ;
F_18 ( & V_23 -> V_9 ) ;
memcpy ( & V_159 , & V_23 -> V_161 , sizeof( struct V_158 ) ) ;
V_23 -> V_10 -> V_162 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
F_76 ( & V_2 -> V_163 , & V_157 ) ;
for (; ; ) {
F_18 ( & V_23 -> V_9 ) ;
memcpy ( & V_160 , & V_23 -> V_161 , sizeof( struct V_158 ) ) ;
F_19 ( & V_23 -> V_9 ) ;
F_77 ( V_164 ) ;
if ( ( ( V_156 & V_165 ) && ( V_160 . V_166 != V_159 . V_166 ) ) ||
( ( V_156 & V_167 ) && ( V_160 . V_168 != V_159 . V_168 ) ) ||
( ( V_156 & V_169 ) && ( V_160 . V_170 != V_159 . V_170 ) ) ||
( ( V_156 & V_39 ) && ( V_160 . V_171 != V_159 . V_171 ) ) ) {
V_81 = 0 ;
break;
}
F_78 () ;
if ( F_79 ( V_140 ) ) {
V_81 = - V_151 ;
break;
}
V_159 = V_160 ;
}
V_140 -> V_4 = V_172 ;
F_80 ( & V_2 -> V_163 , & V_157 ) ;
return V_81 ;
}
static int F_81 ( struct V_6 * V_5 ,
struct V_173 * V_161 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_158 V_160 ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_18 ( & V_23 -> V_9 ) ;
memcpy ( & V_160 , & V_23 -> V_161 , sizeof( struct V_158 ) ) ;
F_19 ( & V_23 -> V_9 ) ;
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
F_82 ( struct V_6 * V_5 , unsigned int V_181 ,
unsigned long V_156 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
void T_2 * V_182 = ( void T_2 * ) V_156 ;
int V_81 = - V_183 ;
switch ( V_181 ) {
case V_184 :
V_81 = F_55 ( V_4 , V_182 ) ;
break;
case V_185 :
V_81 = F_65 ( V_5 , V_4 , V_182 ) ;
break;
case V_186 :
V_81 = F_72 ( V_5 , V_4 ) ;
break;
case V_187 :
case V_188 :
V_81 = 0 ;
break;
}
if ( V_81 != - V_183 )
goto V_189;
if ( V_5 -> V_8 & ( 1 << V_42 ) ) {
V_81 = - V_148 ;
goto V_189;
}
switch ( V_181 ) {
case V_190 :
V_81 = F_74 ( V_4 , V_156 ) ;
break;
}
if ( V_81 != - V_183 )
goto V_189;
F_56 ( & V_2 -> V_111 ) ;
if ( V_5 -> V_8 & ( 1 << V_42 ) ) {
V_81 = - V_148 ;
goto V_191;
}
switch ( V_181 ) {
case V_192 :
V_81 = F_67 ( V_5 , V_4 , V_182 ) ;
break;
default: {
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_23 -> V_10 -> V_193 )
V_81 = V_23 -> V_10 -> V_193 ( V_23 , V_181 , V_156 ) ;
break;
}
}
V_191:
F_57 ( & V_2 -> V_111 ) ;
V_189:
return V_81 ;
}
static void F_83 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_23 -> V_10 -> V_194 )
V_23 -> V_10 -> V_194 ( V_23 , V_5 -> V_33 . V_195 ) ;
}
static void F_84 ( struct V_6 * V_5 ,
struct V_57 * V_72 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
unsigned long V_8 ;
unsigned int V_32 = V_5 -> V_33 . V_34 ;
#define F_85 ( T_3 ) ((iflag) & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK))
if ( ( V_32 ^ V_72 -> V_34 ) == 0 &&
V_5 -> V_33 . V_196 == V_72 -> V_196 &&
V_5 -> V_33 . V_197 == V_72 -> V_197 &&
F_85 ( V_5 -> V_33 . V_198 ^ V_72 -> V_198 ) == 0 ) {
return;
}
F_15 ( V_5 , V_4 , V_72 ) ;
if ( ( V_72 -> V_34 & V_35 ) && ! ( V_32 & V_35 ) )
F_26 ( V_4 -> V_1 , V_36 | V_37 ) ;
else if ( ! ( V_72 -> V_34 & V_35 ) && ( V_32 & V_35 ) ) {
unsigned int V_199 = V_37 ;
if ( ! ( V_32 & V_73 ) ||
! F_86 ( V_200 , & V_5 -> V_8 ) )
V_199 |= V_36 ;
F_16 ( V_4 -> V_1 , V_199 ) ;
}
if ( ( V_72 -> V_34 & V_73 ) && ! ( V_32 & V_73 ) ) {
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
V_5 -> V_15 = 0 ;
F_7 ( V_5 ) ;
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
}
else if ( ! ( V_72 -> V_34 & V_73 ) && ( V_32 & V_73 ) ) {
F_5 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
if ( ! ( V_4 -> V_1 -> V_10 -> V_38 ( V_4 -> V_1 ) & V_39 ) ) {
V_5 -> V_15 = 1 ;
V_4 -> V_1 -> V_10 -> V_11 ( V_4 -> V_1 ) ;
}
F_6 ( & V_4 -> V_1 -> V_9 , V_8 ) ;
}
}
static void F_87 ( struct V_6 * V_5 , struct V_201 * V_202 )
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
if ( F_88 ( V_2 , V_5 , V_202 ) == 0 )
return;
if ( V_2 -> V_8 & V_41 ) {
unsigned long V_8 ;
F_5 ( & V_23 -> V_9 , V_8 ) ;
V_23 -> V_10 -> V_203 ( V_23 ) ;
F_6 ( & V_23 -> V_9 , V_8 ) ;
F_89 ( V_5 , V_23 -> V_55 ) ;
}
F_56 ( & V_2 -> V_111 ) ;
F_24 ( V_5 , V_4 ) ;
F_45 ( V_5 ) ;
F_90 ( V_5 ) ;
F_91 ( V_2 , NULL ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_5 -> V_204 = 0 ;
if ( V_2 -> V_205 ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_100 )
F_92 (
F_54 ( V_2 -> V_100 ) ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
} else if ( ! F_14 ( V_23 ) ) {
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_93 ( V_4 , 3 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
}
F_23 ( V_206 , & V_2 -> V_8 ) ;
F_23 ( V_207 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_94 ( & V_2 -> V_208 ) ;
F_94 ( & V_2 -> V_209 ) ;
F_57 ( & V_2 -> V_111 ) ;
}
static void F_89 ( struct V_6 * V_5 , int V_55 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_1 * V_2 = V_4 -> V_1 ;
unsigned long V_210 , V_211 ;
if ( V_2 -> type == V_27 || V_2 -> V_54 == 0 )
return;
V_210 = ( V_2 -> V_55 - V_56 / 50 ) / V_2 -> V_54 ;
V_210 = V_210 / 5 ;
if ( V_210 == 0 )
V_210 = 1 ;
if ( V_55 && V_55 < V_210 )
V_210 = V_55 ;
if ( V_55 == 0 || V_55 > 2 * V_2 -> V_55 )
V_55 = 2 * V_2 -> V_55 ;
V_211 = V_212 + V_55 ;
F_46 ( L_5 ,
V_2 -> line , V_212 , V_211 ) ;
while ( ! V_2 -> V_10 -> V_146 ( V_2 ) ) {
F_92 ( F_54 ( V_210 ) ) ;
if ( F_79 ( V_140 ) )
break;
if ( F_95 ( V_212 , V_211 ) )
break;
}
}
static void F_96 ( struct V_6 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_7 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
unsigned long V_8 ;
F_46 ( L_6 , V_4 -> V_1 -> line ) ;
F_56 ( & V_2 -> V_111 ) ;
if ( V_2 -> V_8 & V_213 ) {
F_45 ( V_5 ) ;
F_24 ( V_5 , V_4 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_85 = 0 ;
F_23 ( V_206 , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
F_91 ( V_2 , NULL ) ;
F_94 ( & V_2 -> V_208 ) ;
F_94 ( & V_2 -> V_163 ) ;
}
F_57 ( & V_2 -> V_111 ) ;
}
static int F_97 ( struct V_24 * V_2 , struct V_6 * V_5 )
{
return 0 ;
}
static void F_27 ( struct V_24 * V_2 )
{
struct V_3 * V_4 = F_98 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
F_94 ( & V_2 -> V_163 ) ;
V_23 -> V_10 -> V_214 ( V_23 ) ;
F_99 ( V_23 -> V_97 ) ;
}
static int F_100 ( struct V_24 * V_2 )
{
struct V_3 * V_4 = F_98 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
int V_20 ;
F_18 ( & V_23 -> V_9 ) ;
V_23 -> V_10 -> V_162 ( V_23 ) ;
V_20 = V_23 -> V_10 -> V_38 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
if ( V_20 & V_215 )
return 1 ;
return 0 ;
}
static void F_101 ( struct V_24 * V_2 , int V_216 )
{
struct V_3 * V_4 = F_98 ( V_2 , struct V_3 , V_2 ) ;
struct V_1 * V_23 = V_4 -> V_1 ;
if ( V_216 )
F_16 ( V_23 , V_37 | V_36 ) ;
else
F_26 ( V_23 , V_37 | V_36 ) ;
}
static int F_102 ( struct V_6 * V_5 , struct V_201 * V_202 )
{
struct V_217 * V_218 = (struct V_217 * ) V_5 -> V_219 -> V_220 ;
int V_26 , line = V_5 -> V_88 ;
struct V_3 * V_4 = V_218 -> V_4 + line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_46 ( L_7 , line ) ;
if ( F_73 ( & V_2 -> V_111 ) ) {
V_26 = - V_151 ;
goto V_221;
}
V_2 -> V_85 ++ ;
if ( ! V_4 -> V_1 || V_4 -> V_1 -> V_8 & V_222 ) {
V_26 = - V_223 ;
goto V_224;
}
V_5 -> V_7 = V_4 ;
V_4 -> V_1 -> V_4 = V_4 ;
V_5 -> V_137 = ( V_4 -> V_1 -> V_8 & V_138 ) ? 1 : 0 ;
F_91 ( V_2 , V_5 ) ;
if ( F_103 ( V_202 ) ) {
V_26 = - V_225 ;
goto V_224;
}
if ( V_2 -> V_85 == 1 )
F_93 ( V_4 , 0 ) ;
V_26 = F_21 ( V_5 , V_4 , 0 ) ;
F_57 ( & V_2 -> V_111 ) ;
if ( V_26 == 0 )
V_26 = F_104 ( V_2 , V_5 , V_202 ) ;
V_221:
return V_26 ;
V_224:
V_2 -> V_85 -- ;
F_57 ( & V_2 -> V_111 ) ;
goto V_221;
}
static const char * F_105 ( struct V_1 * V_2 )
{
const char * V_226 = NULL ;
if ( V_2 -> V_10 -> type )
V_226 = V_2 -> V_10 -> type ( V_2 ) ;
if ( ! V_226 )
V_226 = L_8 ;
return V_226 ;
}
static void F_106 ( struct V_227 * V_228 , struct V_217 * V_218 , int V_229 )
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
V_233 = V_23 -> V_105 >= V_234 ;
F_107 ( V_228 , L_9 ,
V_23 -> line , F_105 ( V_23 ) ,
V_233 ? L_10 : L_11 ,
V_233 ? ( unsigned long long ) V_23 -> V_109
: ( unsigned long long ) V_23 -> V_94 ,
V_23 -> V_97 ) ;
if ( V_23 -> type == V_27 ) {
F_108 ( V_228 , '\n' ) ;
return;
}
if ( F_20 ( V_40 ) ) {
F_56 ( & V_2 -> V_111 ) ;
V_230 = V_4 -> V_230 ;
if ( V_230 )
F_93 ( V_4 , 0 ) ;
F_18 ( & V_23 -> V_9 ) ;
V_232 = V_23 -> V_10 -> V_38 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
if ( V_230 )
F_93 ( V_4 , V_230 ) ;
F_57 ( & V_2 -> V_111 ) ;
F_107 ( V_228 , L_12 ,
V_23 -> V_161 . V_175 , V_23 -> V_161 . V_174 ) ;
if ( V_23 -> V_161 . V_176 )
F_107 ( V_228 , L_13 ,
V_23 -> V_161 . V_176 ) ;
if ( V_23 -> V_161 . V_178 )
F_107 ( V_228 , L_14 ,
V_23 -> V_161 . V_178 ) ;
if ( V_23 -> V_161 . V_179 )
F_107 ( V_228 , L_15 ,
V_23 -> V_161 . V_179 ) ;
if ( V_23 -> V_161 . V_177 )
F_107 ( V_228 , L_16 ,
V_23 -> V_161 . V_177 ) ;
#define F_109 ( T_4 , V_226 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_110 ( T_4 , V_226 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_231 [ 0 ] = '\0' ;
V_231 [ 1 ] = '\0' ;
F_109 ( V_36 , L_17 ) ;
F_110 ( V_39 , L_18 ) ;
F_109 ( V_37 , L_19 ) ;
F_110 ( V_167 , L_20 ) ;
F_110 ( V_215 , L_21 ) ;
F_110 ( V_165 , L_22 ) ;
if ( V_231 [ 0 ] )
V_231 [ 0 ] = ' ' ;
F_111 ( V_228 , V_231 ) ;
}
F_108 ( V_228 , '\n' ) ;
#undef F_110
#undef F_109
}
static int F_112 ( struct V_227 * V_228 , void * V_235 )
{
struct V_236 * V_237 = V_228 -> V_238 ;
struct V_217 * V_218 = V_237 -> V_220 ;
int V_229 ;
F_107 ( V_228 , L_23 ,
L_24 , L_24 , L_24 ) ;
for ( V_229 = 0 ; V_229 < V_218 -> V_239 ; V_229 ++ )
F_106 ( V_228 , V_218 , V_229 ) ;
return 0 ;
}
static int F_113 ( struct V_240 * V_240 , struct V_201 * V_201 )
{
return F_114 ( V_201 , F_112 , F_115 ( V_240 ) -> V_241 ) ;
}
void F_116 ( struct V_1 * V_2 , const char * V_242 ,
unsigned int V_85 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_229 ;
for ( V_229 = 0 ; V_229 < V_85 ; V_229 ++ , V_242 ++ ) {
if ( * V_242 == '\n' )
putchar ( V_2 , '\r' ) ;
putchar ( V_2 , * V_242 ) ;
}
}
struct V_1 * T_5
F_117 ( struct V_1 * V_243 , int V_239 , struct V_244 * V_245 )
{
int V_246 = V_245 -> V_88 ;
if ( V_246 < 0 || V_246 >= V_239 || ( V_243 [ V_246 ] . V_94 == 0 &&
V_243 [ V_246 ] . V_247 == NULL ) )
for ( V_246 = 0 ; V_246 < V_239 ; V_246 ++ )
if ( V_243 [ V_246 ] . V_94 != 0 ||
V_243 [ V_246 ] . V_247 != NULL )
break;
V_245 -> V_88 = V_246 ;
return V_243 + V_246 ;
}
void
F_118 ( char * V_248 , int * V_46 , int * V_178 , int * V_47 , int * V_249 )
{
char * V_242 = V_248 ;
* V_46 = F_119 ( V_242 , NULL , 10 ) ;
while ( * V_242 >= '0' && * V_242 <= '9' )
V_242 ++ ;
if ( * V_242 )
* V_178 = * V_242 ++ ;
if ( * V_242 )
* V_47 = * V_242 ++ - '0' ;
if ( * V_242 )
* V_249 = * V_242 ;
}
int
F_120 ( struct V_1 * V_2 , struct V_244 * V_245 ,
int V_46 , int V_178 , int V_47 , int V_249 )
{
struct V_57 V_33 ;
static struct V_57 V_250 ;
int V_229 ;
F_121 ( & V_2 -> V_9 ) ;
F_122 ( & V_2 -> V_9 , & V_251 ) ;
memset ( & V_33 , 0 , sizeof( struct V_57 ) ) ;
V_33 . V_34 = V_252 | V_44 | V_75 ;
for ( V_229 = 0 ; V_253 [ V_229 ] . V_254 ; V_229 ++ )
if ( V_253 [ V_229 ] . V_254 <= V_46 )
break;
V_33 . V_34 |= V_253 [ V_229 ] . V_32 ;
if ( V_47 == 7 )
V_33 . V_34 |= V_51 ;
else
V_33 . V_34 |= V_255 ;
switch ( V_178 ) {
case 'o' : case 'O' :
V_33 . V_34 |= V_256 ;
case 'e' : case 'E' :
V_33 . V_34 |= V_53 ;
break;
}
if ( V_249 == 'r' )
V_33 . V_34 |= V_73 ;
V_2 -> V_20 |= V_37 ;
V_2 -> V_10 -> V_77 ( V_2 , & V_33 , & V_250 ) ;
if ( V_245 )
V_245 -> V_32 = V_33 . V_34 ;
return 0 ;
}
static void F_93 ( struct V_3 * V_4 , int V_230 )
{
struct V_1 * V_2 = V_4 -> V_1 ;
if ( V_4 -> V_230 != V_230 ) {
if ( V_2 -> V_10 -> V_257 )
V_2 -> V_10 -> V_257 ( V_2 , V_230 , V_4 -> V_230 ) ;
V_4 -> V_230 = V_230 ;
}
}
static int F_123 ( struct V_258 * V_259 , void * V_241 )
{
struct V_260 * V_261 = V_241 ;
struct V_236 * V_262 = V_261 -> V_219 -> V_236 ;
T_6 V_263 = F_124 ( V_262 -> V_264 , V_262 -> V_265 ) +
V_261 -> V_2 -> line ;
return V_259 -> V_263 == V_263 ;
}
int F_125 ( struct V_217 * V_218 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_218 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_258 * V_266 ;
struct V_260 V_261 = { V_23 , V_218 } ;
F_56 ( & V_2 -> V_111 ) ;
V_266 = F_126 ( V_23 -> V_259 , & V_261 , F_123 ) ;
if ( F_127 ( V_266 ) ) {
if ( ! F_128 ( V_23 -> V_97 ) )
V_23 -> V_267 = 1 ;
F_129 ( V_266 ) ;
F_57 ( & V_2 -> V_111 ) ;
return 0 ;
}
if ( V_268 || ! F_14 ( V_23 ) )
V_23 -> V_269 = 1 ;
if ( V_2 -> V_8 & V_41 ) {
const struct V_270 * V_10 = V_23 -> V_10 ;
int V_271 ;
if ( V_268 || ! F_14 ( V_23 ) ) {
F_22 ( V_45 , & V_2 -> V_8 ) ;
F_23 ( V_43 , & V_2 -> V_8 ) ;
F_18 ( & V_23 -> V_9 ) ;
V_10 -> V_11 ( V_23 ) ;
V_10 -> V_21 ( V_23 , 0 ) ;
V_10 -> V_203 ( V_23 ) ;
F_19 ( & V_23 -> V_9 ) ;
}
for ( V_271 = 3 ; ! V_10 -> V_146 ( V_23 ) && V_271 ; V_271 -- )
F_130 ( 10 ) ;
if ( ! V_271 )
F_63 ( V_272 L_25
L_26 ,
V_23 -> V_259 ? F_131 ( V_23 -> V_259 ) : L_24 ,
V_23 -> V_259 ? L_27 : L_24 ,
V_218 -> F_131 ,
V_218 -> V_236 -> V_273 + V_23 -> line ) ;
if ( V_268 || ! F_14 ( V_23 ) )
V_10 -> V_214 ( V_23 ) ;
}
if ( V_268 && F_14 ( V_23 ) )
F_132 ( V_23 -> V_31 ) ;
if ( V_268 || ! F_14 ( V_23 ) )
F_93 ( V_4 , 3 ) ;
F_57 ( & V_2 -> V_111 ) ;
return 0 ;
}
int F_133 ( struct V_217 * V_218 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_218 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_258 * V_266 ;
struct V_260 V_261 = { V_23 , V_218 } ;
struct V_57 V_33 ;
F_56 ( & V_2 -> V_111 ) ;
V_266 = F_126 ( V_23 -> V_259 , & V_261 , F_123 ) ;
if ( ! V_23 -> V_269 && F_127 ( V_266 ) ) {
if ( V_23 -> V_267 ) {
F_134 ( V_23 -> V_97 ) ;
V_23 -> V_267 = 0 ;
}
F_57 ( & V_2 -> V_111 ) ;
return 0 ;
}
V_23 -> V_269 = 0 ;
if ( F_14 ( V_23 ) ) {
memset ( & V_33 , 0 , sizeof( struct V_57 ) ) ;
V_33 . V_34 = V_23 -> V_31 -> V_32 ;
if ( V_2 -> V_5 && V_33 . V_34 == 0 )
V_33 = V_2 -> V_5 -> V_33 ;
if ( V_268 )
F_93 ( V_4 , 0 ) ;
V_23 -> V_10 -> V_77 ( V_23 , & V_33 , NULL ) ;
if ( V_268 )
F_135 ( V_23 -> V_31 ) ;
}
if ( V_2 -> V_8 & V_274 ) {
const struct V_270 * V_10 = V_23 -> V_10 ;
int V_81 ;
F_93 ( V_4 , 0 ) ;
F_18 ( & V_23 -> V_9 ) ;
V_10 -> V_21 ( V_23 , 0 ) ;
F_19 ( & V_23 -> V_9 ) ;
if ( V_268 || ! F_14 ( V_23 ) ) {
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
F_57 ( & V_2 -> V_111 ) ;
return 0 ;
}
static inline void
F_136 ( struct V_217 * V_218 , struct V_1 * V_2 )
{
char V_275 [ 64 ] ;
switch ( V_2 -> V_105 ) {
case V_276 :
snprintf ( V_275 , sizeof( V_275 ) , L_28 , V_2 -> V_94 ) ;
break;
case V_277 :
snprintf ( V_275 , sizeof( V_275 ) ,
L_29 , V_2 -> V_94 , V_2 -> V_103 ) ;
break;
case V_234 :
case V_278 :
case V_279 :
case V_280 :
snprintf ( V_275 , sizeof( V_275 ) ,
L_30 , ( unsigned long long ) V_2 -> V_109 ) ;
break;
default:
F_137 ( V_275 , L_31 , sizeof( V_275 ) ) ;
break;
}
F_63 ( V_281 L_32 ,
V_2 -> V_259 ? F_131 ( V_2 -> V_259 ) : L_24 ,
V_2 -> V_259 ? L_27 : L_24 ,
V_218 -> F_131 ,
V_218 -> V_236 -> V_273 + V_2 -> line ,
V_275 , V_2 -> V_97 , F_105 ( V_2 ) ) ;
}
static void
F_138 ( struct V_217 * V_218 , struct V_3 * V_4 ,
struct V_1 * V_2 )
{
unsigned int V_8 ;
if ( ! V_2 -> V_94 && ! V_2 -> V_109 && ! V_2 -> V_247 )
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
F_136 ( V_218 , V_2 ) ;
F_93 ( V_4 , 0 ) ;
F_5 ( & V_2 -> V_9 , V_8 ) ;
V_2 -> V_10 -> V_21 ( V_2 , V_2 -> V_20 & V_37 ) ;
F_6 ( & V_2 -> V_9 , V_8 ) ;
if ( V_2 -> V_31 && ! ( V_2 -> V_31 -> V_8 & V_284 ) )
F_139 ( V_2 -> V_31 ) ;
if ( ! F_14 ( V_2 ) )
F_93 ( V_4 , 3 ) ;
}
}
static int F_140 ( struct V_236 * V_219 , int line , char * V_248 )
{
struct V_217 * V_218 = V_219 -> V_220 ;
struct V_3 * V_4 = V_218 -> V_4 + line ;
struct V_1 * V_2 ;
int V_46 = 9600 ;
int V_47 = 8 ;
int V_178 = 'n' ;
int V_249 = 'n' ;
int V_81 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
if ( ! ( V_2 -> V_10 -> V_285 && V_2 -> V_10 -> V_286 ) )
return - 1 ;
if ( V_2 -> V_10 -> V_287 ) {
struct V_24 * V_288 = & V_4 -> V_2 ;
V_81 = 0 ;
F_56 ( & V_288 -> V_111 ) ;
if ( ! F_86 ( V_43 , & V_288 -> V_8 ) )
V_81 = V_2 -> V_10 -> V_287 ( V_2 ) ;
F_57 ( & V_288 -> V_111 ) ;
if ( V_81 )
return V_81 ;
}
if ( V_248 ) {
F_118 ( V_248 , & V_46 , & V_178 , & V_47 , & V_249 ) ;
return F_120 ( V_2 , NULL , V_46 , V_178 , V_47 , V_249 ) ;
}
return 0 ;
}
static int F_141 ( struct V_236 * V_219 , int line )
{
struct V_217 * V_218 = V_219 -> V_220 ;
struct V_3 * V_4 = V_218 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return - 1 ;
V_2 = V_4 -> V_1 ;
return V_2 -> V_10 -> V_285 ( V_2 ) ;
}
static void F_142 ( struct V_236 * V_219 , int line , char V_84 )
{
struct V_217 * V_218 = V_219 -> V_220 ;
struct V_3 * V_4 = V_218 -> V_4 + line ;
struct V_1 * V_2 ;
if ( ! V_4 || ! V_4 -> V_1 )
return;
V_2 = V_4 -> V_1 ;
V_2 -> V_10 -> V_286 ( V_2 , V_84 ) ;
}
int F_143 ( struct V_217 * V_218 )
{
struct V_236 * V_289 ;
int V_229 , V_26 ;
F_2 ( V_218 -> V_4 ) ;
V_218 -> V_4 = F_144 ( sizeof( struct V_3 ) * V_218 -> V_239 , V_28 ) ;
if ( ! V_218 -> V_4 )
goto V_189;
V_289 = F_145 ( V_218 -> V_239 ) ;
if ( ! V_289 )
goto V_290;
V_218 -> V_236 = V_289 ;
V_289 -> V_291 = V_218 -> V_291 ;
V_289 -> V_292 = V_218 -> F_131 ;
V_289 -> V_264 = V_218 -> V_264 ;
V_289 -> V_265 = V_218 -> V_293 ;
V_289 -> type = V_294 ;
V_289 -> V_295 = V_296 ;
V_289 -> V_297 = V_298 ;
V_289 -> V_297 . V_34 = V_299 | V_255 | V_252 | V_44 | V_75 ;
V_289 -> V_297 . V_197 = V_289 -> V_297 . V_196 = 9600 ;
V_289 -> V_8 = V_300 | V_301 ;
V_289 -> V_220 = V_218 ;
F_146 ( V_289 , & V_270 ) ;
for ( V_229 = 0 ; V_229 < V_218 -> V_239 ; V_229 ++ ) {
struct V_3 * V_4 = V_218 -> V_4 + V_229 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_147 ( V_2 ) ;
V_2 -> V_10 = & V_302 ;
V_2 -> V_100 = V_56 / 2 ;
V_2 -> V_101 = 30 * V_56 ;
}
V_26 = F_148 ( V_289 ) ;
if ( V_26 >= 0 )
return V_26 ;
F_149 ( V_289 ) ;
V_290:
F_150 ( V_218 -> V_4 ) ;
V_189:
return - V_29 ;
}
void F_151 ( struct V_217 * V_218 )
{
struct V_236 * V_303 = V_218 -> V_236 ;
F_152 ( V_303 ) ;
F_149 ( V_303 ) ;
F_150 ( V_218 -> V_4 ) ;
V_218 -> V_4 = NULL ;
V_218 -> V_236 = NULL ;
}
struct V_236 * F_153 ( struct V_244 * V_245 , int * V_88 )
{
struct V_217 * V_303 = V_245 -> V_241 ;
* V_88 = V_245 -> V_88 ;
return V_303 -> V_236 ;
}
static T_7 F_154 ( struct V_258 * V_259 ,
struct V_304 * V_305 , char * V_13 )
{
int V_81 ;
struct V_24 * V_2 = F_155 ( V_259 ) ;
struct V_3 * V_4 = F_98 ( V_2 , struct V_3 , V_2 ) ;
F_56 ( & V_4 -> V_2 . V_111 ) ;
V_81 = snprintf ( V_13 , V_306 , L_33 , V_4 -> V_1 -> V_71 ) ;
F_57 ( & V_4 -> V_2 . V_111 ) ;
return V_81 ;
}
int F_156 ( struct V_217 * V_218 , struct V_1 * V_23 )
{
struct V_3 * V_4 ;
struct V_24 * V_2 ;
int V_81 = 0 ;
struct V_258 * V_266 ;
F_2 ( F_157 () ) ;
if ( V_23 -> line >= V_218 -> V_239 )
return - V_126 ;
V_4 = V_218 -> V_4 + V_23 -> line ;
V_2 = & V_4 -> V_2 ;
F_56 ( & V_307 ) ;
F_56 ( & V_2 -> V_111 ) ;
if ( V_4 -> V_1 ) {
V_81 = - V_126 ;
goto V_189;
}
V_4 -> V_1 = V_23 ;
V_4 -> V_230 = - 1 ;
V_23 -> V_31 = V_218 -> V_31 ;
V_23 -> V_4 = V_4 ;
if ( ! ( F_14 ( V_23 ) && ( V_23 -> V_31 -> V_8 & V_284 ) ) ) {
F_121 ( & V_23 -> V_9 ) ;
F_122 ( & V_23 -> V_9 , & V_251 ) ;
}
F_138 ( V_218 , V_4 , V_23 ) ;
V_266 = F_158 ( V_2 , V_218 -> V_236 ,
V_23 -> line , V_23 -> V_259 , V_2 , V_308 ) ;
if ( F_159 ( ! F_160 ( V_266 ) ) ) {
F_161 ( V_266 , 1 ) ;
} else {
F_63 ( V_272 L_34 ,
V_23 -> line ) ;
}
V_23 -> V_8 &= ~ V_222 ;
V_189:
F_57 ( & V_2 -> V_111 ) ;
F_57 ( & V_307 ) ;
return V_81 ;
}
int F_162 ( struct V_217 * V_218 , struct V_1 * V_23 )
{
struct V_3 * V_4 = V_218 -> V_4 + V_23 -> line ;
struct V_24 * V_2 = & V_4 -> V_2 ;
F_2 ( F_157 () ) ;
if ( V_4 -> V_1 != V_23 )
F_63 ( V_309 L_35 ,
V_4 -> V_1 , V_23 ) ;
F_56 ( & V_307 ) ;
F_56 ( & V_2 -> V_111 ) ;
V_23 -> V_8 |= V_222 ;
F_57 ( & V_2 -> V_111 ) ;
F_163 ( V_218 -> V_236 , V_23 -> line ) ;
if ( V_2 -> V_5 )
F_164 ( V_2 -> V_5 ) ;
if ( V_23 -> type != V_27 )
V_23 -> V_10 -> V_134 ( V_23 ) ;
V_23 -> type = V_27 ;
V_4 -> V_1 = NULL ;
F_57 ( & V_307 ) ;
return 0 ;
}
int F_165 ( struct V_1 * V_310 , struct V_1 * V_311 )
{
if ( V_310 -> V_105 != V_311 -> V_105 )
return 0 ;
switch ( V_310 -> V_105 ) {
case V_276 :
return ( V_310 -> V_94 == V_311 -> V_94 ) ;
case V_277 :
return ( V_310 -> V_94 == V_311 -> V_94 ) &&
( V_310 -> V_103 == V_311 -> V_103 ) ;
case V_234 :
case V_278 :
case V_279 :
case V_280 :
return ( V_310 -> V_109 == V_311 -> V_109 ) ;
}
return 0 ;
}
void F_166 ( struct V_1 * V_23 , unsigned int V_232 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
struct V_24 * V_2 = & V_4 -> V_2 ;
struct V_312 * V_313 = NULL ;
struct V_314 V_315 ;
struct V_6 * V_5 = V_2 -> V_5 ;
if ( V_5 )
V_313 = F_167 ( V_5 ) ;
if ( V_313 && V_313 -> V_10 -> V_316 )
F_168 ( & V_315 ) ;
V_23 -> V_161 . V_170 ++ ;
#ifdef F_169
if ( ( V_23 -> V_8 & V_317 ) && V_232 )
F_170 () ;
#endif
if ( V_2 -> V_8 & V_318 ) {
if ( V_232 )
F_94 ( & V_2 -> V_208 ) ;
else if ( V_5 )
F_171 ( V_5 ) ;
}
if ( V_313 && V_313 -> V_10 -> V_316 )
V_313 -> V_10 -> V_316 ( V_5 , V_232 , & V_315 ) ;
if ( V_313 )
F_172 ( V_313 ) ;
}
void F_173 ( struct V_1 * V_23 , unsigned int V_232 )
{
struct V_24 * V_2 = & V_23 -> V_4 -> V_2 ;
struct V_6 * V_5 = V_2 -> V_5 ;
V_23 -> V_161 . V_171 ++ ;
if ( F_17 ( V_2 ) ) {
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
void F_174 ( struct V_1 * V_2 , unsigned int V_232 ,
unsigned int V_177 , unsigned int V_84 , unsigned int V_319 )
{
struct V_6 * V_5 = V_2 -> V_4 -> V_2 . V_5 ;
if ( ( V_232 & V_2 -> V_320 & ~ V_177 ) == 0 )
if ( F_175 ( V_5 , V_84 , V_319 ) == 0 )
++ V_2 -> V_161 . V_180 ;
if ( V_232 & ~ V_2 -> V_320 & V_177 )
if ( F_175 ( V_5 , 0 , V_321 ) == 0 )
++ V_2 -> V_161 . V_180 ;
}
