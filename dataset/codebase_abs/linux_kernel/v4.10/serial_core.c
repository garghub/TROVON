static int F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 & V_4 ) ;
}
static inline struct V_1 * F_2 ( struct V_5 * V_6 )
{
if ( F_3 ( & V_6 -> V_7 , 1 , 0 ) )
return V_6 -> V_1 ;
return NULL ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
if ( F_5 ( & V_2 -> V_6 -> V_7 ) )
F_6 ( & V_2 -> V_6 -> V_8 ) ;
}
static inline struct V_1 * F_7 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_9 . V_10 ) ;
return V_6 -> V_1 ;
}
void F_9 ( struct V_1 * V_9 )
{
struct V_5 * V_6 = V_9 -> V_6 ;
F_10 ( ! V_6 ) ;
F_11 ( & V_6 -> V_9 ) ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
V_9 = F_13 ( V_6 , V_14 ) ;
if ( V_9 )
V_9 -> V_15 -> V_16 ( V_9 ) ;
F_14 ( V_9 , V_14 ) ;
}
static void F_15 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 = V_6 -> V_1 ;
if ( V_9 && ! F_16 ( V_9 ) )
V_9 -> V_15 -> V_17 ( V_9 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
V_9 = F_13 ( V_6 , V_14 ) ;
F_15 ( V_12 ) ;
F_14 ( V_9 , V_14 ) ;
}
static void
F_18 ( struct V_1 * V_9 , unsigned int V_18 , unsigned int V_19 )
{
unsigned long V_14 ;
unsigned int V_20 ;
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_20 = V_9 -> V_22 ;
V_9 -> V_22 = ( V_20 & ~ V_19 ) | V_18 ;
if ( V_20 != V_9 -> V_22 )
V_9 -> V_15 -> V_23 ( V_9 , V_9 -> V_22 ) ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
}
static int F_21 ( struct V_11 * V_12 , struct V_5 * V_6 ,
int V_24 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned long V_25 ;
int V_26 = 0 ;
if ( V_2 -> type == V_27 )
return 1 ;
F_22 ( V_6 , V_28 ) ;
if ( ! V_6 -> V_29 . V_30 ) {
V_25 = F_23 ( V_31 ) ;
if ( ! V_25 )
return - V_32 ;
V_6 -> V_29 . V_30 = ( unsigned char * ) V_25 ;
F_24 ( & V_6 -> V_29 ) ;
}
V_26 = V_2 -> V_15 -> V_33 ( V_2 ) ;
if ( V_26 == 0 ) {
if ( F_25 ( V_2 ) && V_2 -> V_34 -> V_35 ) {
V_12 -> V_36 . V_37 = V_2 -> V_34 -> V_35 ;
V_2 -> V_34 -> V_35 = 0 ;
}
F_26 ( V_12 , V_6 , NULL ) ;
if ( V_24 && F_27 ( V_12 ) )
F_28 ( V_2 , V_38 | V_39 ) ;
}
if ( V_26 && F_29 ( V_40 ) )
return 1 ;
return V_26 ;
}
static int F_30 ( struct V_11 * V_12 , struct V_5 * V_6 ,
int V_24 )
{
struct V_41 * V_9 = & V_6 -> V_9 ;
int V_26 ;
if ( F_31 ( V_9 ) )
return 0 ;
V_26 = F_21 ( V_12 , V_6 , V_24 ) ;
if ( V_26 )
F_32 ( V_42 , & V_12 -> V_14 ) ;
return V_26 ;
}
static void F_33 ( struct V_11 * V_12 , struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_41 * V_9 = & V_6 -> V_9 ;
if ( V_12 )
F_32 ( V_42 , & V_12 -> V_14 ) ;
if ( F_31 ( V_9 ) ) {
F_34 ( V_9 , 0 ) ;
if ( V_2 && F_25 ( V_2 ) && V_12 )
V_2 -> V_34 -> V_35 = V_12 -> V_36 . V_37 ;
if ( ! V_12 || F_35 ( V_12 ) )
F_36 ( V_2 , V_39 | V_38 ) ;
F_37 ( V_9 ) ;
}
F_38 ( V_9 , 0 ) ;
if ( V_6 -> V_29 . V_30 ) {
F_39 ( ( unsigned long ) V_6 -> V_29 . V_30 ) ;
V_6 -> V_29 . V_30 = NULL ;
}
}
void
F_40 ( struct V_1 * V_9 , unsigned int V_35 ,
unsigned int V_43 )
{
unsigned int V_44 ;
switch ( V_35 & V_45 ) {
case V_46 :
V_44 = 7 ;
break;
case V_47 :
V_44 = 8 ;
break;
case V_48 :
V_44 = 9 ;
break;
default:
V_44 = 10 ;
break;
}
if ( V_35 & V_49 )
V_44 ++ ;
if ( V_35 & V_50 )
V_44 ++ ;
V_44 = V_44 * V_9 -> V_51 ;
V_9 -> V_52 = ( V_53 * V_44 ) / V_43 + V_53 / 50 ;
}
unsigned int
F_41 ( struct V_1 * V_9 , struct V_54 * V_36 ,
struct V_54 * V_20 , unsigned int V_55 , unsigned int V_56 )
{
unsigned int V_57 ;
unsigned int V_43 ;
unsigned int V_58 ;
int V_59 = 0 ;
T_1 V_14 = V_9 -> V_14 & V_60 ;
switch ( V_14 ) {
case V_61 :
V_58 = 57600 ;
break;
case V_62 :
V_58 = 115200 ;
break;
case V_63 :
V_58 = 230400 ;
break;
case V_64 :
V_58 = 460800 ;
break;
default:
V_58 = 38400 ;
break;
}
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
V_43 = F_42 ( V_36 ) ;
if ( V_57 == 0 && V_43 == 38400 )
V_43 = V_58 ;
if ( V_43 == 0 ) {
V_59 = 1 ;
V_43 = 9600 ;
}
if ( V_43 >= V_55 && V_43 <= V_56 )
return V_43 ;
V_36 -> V_37 &= ~ V_65 ;
if ( V_20 ) {
V_43 = F_42 ( V_20 ) ;
if ( ! V_59 )
F_43 ( V_36 ,
V_43 , V_43 ) ;
V_20 = NULL ;
continue;
}
if ( ! V_59 ) {
if ( V_43 <= V_55 )
F_43 ( V_36 ,
V_55 + 1 , V_55 + 1 ) ;
else
F_43 ( V_36 ,
V_56 - 1 , V_56 - 1 ) ;
}
}
F_44 ( 1 ) ;
return 0 ;
}
unsigned int
F_45 ( struct V_1 * V_9 , unsigned int V_43 )
{
unsigned int V_66 ;
if ( V_43 == 38400 && ( V_9 -> V_14 & V_60 ) == V_67 )
V_66 = V_9 -> V_68 ;
else
V_66 = F_46 ( V_9 -> V_69 , 16 * V_43 ) ;
return V_66 ;
}
static void F_26 ( struct V_11 * V_12 , struct V_5 * V_6 ,
struct V_54 * V_70 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_54 * V_36 ;
int V_71 ;
if ( ! V_12 || V_2 -> type == V_27 )
return;
V_36 = & V_12 -> V_36 ;
V_2 -> V_15 -> V_72 ( V_2 , V_36 , V_70 ) ;
F_47 ( & V_2 -> V_21 ) ;
if ( V_36 -> V_37 & V_73 )
V_2 -> V_3 |= V_74 ;
else
V_2 -> V_3 &= ~ V_74 ;
if ( V_36 -> V_37 & V_75 )
V_2 -> V_3 &= ~ V_4 ;
else
V_2 -> V_3 |= V_4 ;
V_71 = V_2 -> V_71 ;
V_2 -> V_71 = F_48 ( V_2 ) &&
! ( V_2 -> V_15 -> V_76 ( V_2 ) & V_77 ) ;
if ( V_2 -> V_71 ) {
if ( ! V_71 )
V_2 -> V_15 -> V_16 ( V_2 ) ;
} else {
if ( V_71 )
F_15 ( V_12 ) ;
}
F_49 ( & V_2 -> V_21 ) ;
}
static int F_50 ( struct V_11 * V_12 , unsigned char V_78 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
struct V_79 * V_80 ;
unsigned long V_14 ;
int V_81 = 0 ;
V_80 = & V_6 -> V_29 ;
if ( ! V_80 -> V_30 )
return 0 ;
V_9 = F_13 ( V_6 , V_14 ) ;
if ( V_9 && F_51 ( V_80 ) != 0 ) {
V_80 -> V_30 [ V_80 -> V_82 ] = V_78 ;
V_80 -> V_82 = ( V_80 -> V_82 + 1 ) & ( V_83 - 1 ) ;
V_81 = 1 ;
}
F_14 ( V_9 , V_14 ) ;
return V_81 ;
}
static void F_52 ( struct V_11 * V_12 )
{
F_17 ( V_12 ) ;
}
static int F_53 ( struct V_11 * V_12 ,
const unsigned char * V_30 , int V_84 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
struct V_79 * V_80 ;
unsigned long V_14 ;
int V_78 , V_81 = 0 ;
if ( ! V_6 ) {
F_44 ( 1 ) ;
return - V_85 ;
}
V_80 = & V_6 -> V_29 ;
if ( ! V_80 -> V_30 )
return 0 ;
V_9 = F_13 ( V_6 , V_14 ) ;
while ( V_9 ) {
V_78 = F_54 ( V_80 -> V_82 , V_80 -> V_86 , V_83 ) ;
if ( V_84 < V_78 )
V_78 = V_84 ;
if ( V_78 <= 0 )
break;
memcpy ( V_80 -> V_30 + V_80 -> V_82 , V_30 , V_78 ) ;
V_80 -> V_82 = ( V_80 -> V_82 + V_78 ) & ( V_83 - 1 ) ;
V_30 += V_78 ;
V_84 -= V_78 ;
V_81 += V_78 ;
}
F_15 ( V_12 ) ;
F_14 ( V_9 , V_14 ) ;
return V_81 ;
}
static int F_55 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
int V_81 ;
V_9 = F_13 ( V_6 , V_14 ) ;
V_81 = F_51 ( & V_6 -> V_29 ) ;
F_14 ( V_9 , V_14 ) ;
return V_81 ;
}
static int F_56 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
int V_81 ;
V_9 = F_13 ( V_6 , V_14 ) ;
V_81 = F_57 ( & V_6 -> V_29 ) ;
F_14 ( V_9 , V_14 ) ;
return V_81 ;
}
static void F_58 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
if ( ! V_6 ) {
F_44 ( 1 ) ;
return;
}
F_59 ( L_1 , V_12 -> V_87 ) ;
V_9 = F_13 ( V_6 , V_14 ) ;
if ( ! V_9 )
return;
F_24 ( & V_6 -> V_29 ) ;
if ( V_9 -> V_15 -> V_88 )
V_9 -> V_15 -> V_88 ( V_9 ) ;
F_14 ( V_9 , V_14 ) ;
F_11 ( & V_6 -> V_9 ) ;
}
static void F_60 ( struct V_11 * V_12 , char V_89 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( V_9 -> V_15 -> V_90 )
V_9 -> V_15 -> V_90 ( V_9 , V_89 ) ;
else {
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_9 -> V_91 = V_89 ;
if ( V_89 )
V_9 -> V_15 -> V_17 ( V_9 ) ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
}
F_4 ( V_9 ) ;
}
static void F_61 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
T_2 V_92 = 0 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( F_62 ( V_12 ) )
V_92 |= V_93 ;
if ( F_63 ( V_12 ) )
V_92 |= V_94 ;
if ( V_9 -> V_3 & V_92 ) {
V_9 -> V_15 -> V_95 ( V_9 ) ;
V_92 &= ~ V_9 -> V_3 ;
}
if ( V_92 & V_94 )
F_36 ( V_9 , V_38 ) ;
if ( V_92 & V_93 )
F_60 ( V_12 , F_64 ( V_12 ) ) ;
F_4 ( V_9 ) ;
}
static void F_65 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
T_2 V_92 = 0 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( F_62 ( V_12 ) )
V_92 |= V_93 ;
if ( F_63 ( V_12 ) )
V_92 |= V_94 ;
if ( V_9 -> V_3 & V_92 ) {
V_9 -> V_15 -> V_96 ( V_9 ) ;
V_92 &= ~ V_9 -> V_3 ;
}
if ( V_92 & V_94 )
F_28 ( V_9 , V_38 ) ;
if ( V_92 & V_93 )
F_60 ( V_12 , F_66 ( V_12 ) ) ;
F_4 ( V_9 ) ;
}
static int F_67 ( struct V_41 * V_9 , struct V_97 * V_98 )
{
struct V_5 * V_6 = F_68 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 ;
int V_81 = - V_99 ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
F_69 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_100;
V_98 -> type = V_2 -> type ;
V_98 -> line = V_2 -> line ;
V_98 -> V_9 = V_2 -> V_101 ;
if ( V_102 )
V_98 -> V_103 = ( long ) V_2 -> V_101 >> V_102 ;
V_98 -> V_104 = V_2 -> V_104 ;
V_98 -> V_14 = V_2 -> V_14 ;
V_98 -> V_105 = V_2 -> V_51 ;
V_98 -> V_106 = V_2 -> V_69 / 16 ;
V_98 -> V_107 = F_70 ( V_9 -> V_107 ) / 10 ;
V_98 -> V_108 = V_9 -> V_108 == V_109 ?
V_109 :
F_70 ( V_9 -> V_108 ) / 10 ;
V_98 -> V_68 = V_2 -> V_68 ;
V_98 -> V_110 = V_2 -> V_110 ;
V_98 -> V_111 = V_2 -> V_112 ;
V_98 -> V_113 = V_2 -> V_114 ;
V_98 -> V_115 = ( void * ) ( unsigned long ) V_2 -> V_116 ;
V_81 = 0 ;
V_100:
F_71 ( & V_9 -> V_10 ) ;
return V_81 ;
}
static int F_72 ( struct V_41 * V_9 ,
struct V_97 T_3 * V_98 )
{
struct V_97 V_117 ;
if ( F_67 ( V_9 , & V_117 ) < 0 )
return - V_118 ;
if ( F_73 ( V_98 , & V_117 , sizeof( * V_98 ) ) )
return - V_119 ;
return 0 ;
}
static int F_74 ( struct V_11 * V_12 , struct V_41 * V_9 ,
struct V_5 * V_6 ,
struct V_97 * V_120 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned long V_121 ;
unsigned int V_122 , V_123 , V_108 ;
unsigned int V_124 , V_107 ;
T_1 V_125 , V_126 ;
int V_26 = 0 ;
if ( ! V_2 )
return - V_118 ;
V_121 = V_120 -> V_9 ;
if ( V_102 )
V_121 += ( unsigned long ) V_120 -> V_103 << V_102 ;
V_120 -> V_104 = F_75 ( V_120 -> V_104 ) ;
V_107 = F_76 ( V_120 -> V_107 * 10 ) ;
V_108 = V_120 -> V_108 == V_109 ?
V_109 :
F_76 ( V_120 -> V_108 * 10 ) ;
V_122 = ! ( V_2 -> V_14 & V_127 )
&& V_120 -> V_104 != V_2 -> V_104 ;
V_123 = ! ( V_2 -> V_14 & V_127 )
&& ( V_121 != V_2 -> V_101 ||
( unsigned long ) V_120 -> V_115 != V_2 -> V_116 ||
V_120 -> V_110 != V_2 -> V_110 ||
V_120 -> V_111 != V_2 -> V_112 ||
V_120 -> V_113 != V_2 -> V_114 ||
V_120 -> type != V_2 -> type ) ;
V_125 = V_2 -> V_14 ;
V_126 = V_120 -> V_14 ;
V_124 = V_2 -> V_68 ;
if ( ! F_29 ( V_40 ) ) {
V_26 = - V_128 ;
if ( V_122 || V_123 ||
( V_120 -> V_106 != V_2 -> V_69 / 16 ) ||
( V_107 != V_9 -> V_107 ) ||
( V_108 != V_9 -> V_108 ) ||
( V_120 -> V_105 &&
V_120 -> V_105 != V_2 -> V_51 ) ||
( ( ( V_126 ^ V_125 ) & ~ V_129 ) != 0 ) )
goto exit;
V_2 -> V_14 = ( ( V_2 -> V_14 & ~ V_129 ) |
( V_126 & V_129 ) ) ;
V_2 -> V_68 = V_120 -> V_68 ;
goto V_130;
}
if ( V_2 -> V_15 -> V_131 )
V_26 = V_2 -> V_15 -> V_131 ( V_2 , V_120 ) ;
if ( ( V_120 -> V_104 >= V_132 ) || ( V_120 -> V_104 < 0 ) ||
( V_120 -> V_106 < 9600 ) )
V_26 = - V_133 ;
if ( V_26 )
goto exit;
if ( V_123 || V_122 ) {
V_26 = - V_134 ;
if ( F_77 ( V_9 ) > 1 )
goto exit;
F_33 ( V_12 , V_6 ) ;
}
if ( V_123 ) {
unsigned long V_135 , V_136 ;
unsigned int V_137 , V_138 , V_139 , V_140 ;
V_135 = V_2 -> V_101 ;
V_136 = V_2 -> V_116 ;
V_137 = V_2 -> type ;
V_139 = V_2 -> V_110 ;
V_138 = V_2 -> V_112 ;
V_140 = V_2 -> V_114 ;
if ( V_137 != V_27 && V_2 -> V_15 -> V_141 )
V_2 -> V_15 -> V_141 ( V_2 ) ;
V_2 -> V_101 = V_121 ;
V_2 -> type = V_120 -> type ;
V_2 -> V_110 = V_120 -> V_110 ;
V_2 -> V_112 = V_120 -> V_111 ;
V_2 -> V_114 = V_120 -> V_113 ;
V_2 -> V_116 = ( unsigned long ) V_120 -> V_115 ;
if ( V_2 -> type != V_27 && V_2 -> V_15 -> V_142 ) {
V_26 = V_2 -> V_15 -> V_142 ( V_2 ) ;
} else {
V_26 = 0 ;
}
if ( V_26 ) {
V_2 -> V_101 = V_135 ;
V_2 -> type = V_137 ;
V_2 -> V_110 = V_139 ;
V_2 -> V_112 = V_138 ;
V_2 -> V_114 = V_140 ;
V_2 -> V_116 = V_136 ;
if ( V_137 != V_27 ) {
V_26 = V_2 -> V_15 -> V_142 ( V_2 ) ;
if ( V_26 )
V_2 -> type = V_27 ;
V_26 = - V_134 ;
}
goto exit;
}
}
if ( V_122 )
V_2 -> V_104 = V_120 -> V_104 ;
if ( ! ( V_2 -> V_14 & V_127 ) )
V_2 -> V_69 = V_120 -> V_106 * 16 ;
V_2 -> V_14 = ( V_2 -> V_14 & ~ V_143 ) |
( V_126 & V_143 ) ;
V_2 -> V_68 = V_120 -> V_68 ;
V_9 -> V_107 = V_107 ;
V_9 -> V_108 = V_108 ;
if ( V_120 -> V_105 )
V_2 -> V_51 = V_120 -> V_105 ;
V_9 -> V_144 = ( V_2 -> V_14 & V_145 ) ? 1 : 0 ;
V_130:
V_26 = 0 ;
if ( V_2 -> type == V_27 )
goto exit;
if ( F_31 ( V_9 ) ) {
if ( ( ( V_125 ^ V_2 -> V_14 ) & V_60 ) ||
V_124 != V_2 -> V_68 ) {
if ( V_2 -> V_14 & V_60 ) {
F_78 ( V_2 -> V_146 ,
L_2 ,
V_147 -> V_148 ,
F_79 ( V_9 -> V_12 ) ) ;
}
F_26 ( V_12 , V_6 , NULL ) ;
}
} else {
V_26 = F_30 ( V_12 , V_6 , 1 ) ;
if ( V_26 > 0 )
V_26 = 0 ;
}
exit:
return V_26 ;
}
static int F_80 ( struct V_11 * V_12 , struct V_5 * V_6 ,
struct V_97 T_3 * V_149 )
{
struct V_97 V_150 ;
struct V_41 * V_9 = & V_6 -> V_9 ;
int V_26 ;
if ( F_81 ( & V_150 , V_149 , sizeof( V_150 ) ) )
return - V_119 ;
F_69 ( & V_9 -> V_10 ) ;
V_26 = F_74 ( V_12 , V_9 , V_6 , & V_150 ) ;
F_71 ( & V_9 -> V_10 ) ;
return V_26 ;
}
static int F_82 ( struct V_11 * V_12 ,
struct V_5 * V_6 , unsigned int T_3 * V_151 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned int V_152 ;
V_152 = V_2 -> V_15 -> V_153 ( V_2 ) ;
if ( V_2 -> V_91 ||
( ( F_57 ( & V_6 -> V_29 ) > 0 ) &&
! F_16 ( V_2 ) ) )
V_152 &= ~ V_154 ;
return F_83 ( V_152 , V_151 ) ;
}
static int F_84 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_41 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
int V_152 = - V_118 ;
F_69 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_100;
if ( ! F_85 ( V_12 ) ) {
V_152 = V_2 -> V_22 ;
F_47 ( & V_2 -> V_21 ) ;
V_152 |= V_2 -> V_15 -> V_76 ( V_2 ) ;
F_49 ( & V_2 -> V_21 ) ;
}
V_100:
F_71 ( & V_9 -> V_10 ) ;
return V_152 ;
}
static int
F_86 ( struct V_11 * V_12 , unsigned int V_18 , unsigned int V_19 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_41 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
int V_81 = - V_118 ;
F_69 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_100;
if ( ! F_85 ( V_12 ) ) {
F_18 ( V_2 , V_18 , V_19 ) ;
V_81 = 0 ;
}
V_100:
F_71 ( & V_9 -> V_10 ) ;
return V_81 ;
}
static int F_87 ( struct V_11 * V_12 , int V_155 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_41 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
int V_81 = - V_118 ;
F_69 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_100;
if ( V_2 -> type != V_27 )
V_2 -> V_15 -> V_156 ( V_2 , V_155 ) ;
V_81 = 0 ;
V_100:
F_71 ( & V_9 -> V_10 ) ;
return V_81 ;
}
static int F_88 ( struct V_11 * V_12 , struct V_5 * V_6 )
{
struct V_41 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
int V_14 , V_81 ;
if ( ! F_29 ( V_40 ) )
return - V_128 ;
if ( F_89 ( & V_9 -> V_10 ) )
return - V_157 ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 ) {
V_81 = - V_118 ;
goto V_100;
}
V_81 = - V_134 ;
if ( F_77 ( V_9 ) == 1 ) {
F_33 ( V_12 , V_6 ) ;
if ( V_2 -> type != V_27 && V_2 -> V_15 -> V_141 )
V_2 -> V_15 -> V_141 ( V_2 ) ;
V_14 = V_158 ;
if ( V_2 -> V_14 & V_159 )
V_14 |= V_160 ;
V_2 -> V_15 -> V_161 ( V_2 , V_14 ) ;
V_81 = F_30 ( V_12 , V_6 , 1 ) ;
if ( V_81 > 0 )
V_81 = 0 ;
}
V_100:
F_71 ( & V_9 -> V_10 ) ;
return V_81 ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 -> V_162 )
V_2 -> V_15 -> V_162 ( V_2 ) ;
}
static int F_91 ( struct V_5 * V_6 , unsigned long V_163 )
{
struct V_1 * V_2 ;
struct V_41 * V_9 = & V_6 -> V_9 ;
F_92 ( V_164 , V_147 ) ;
struct V_165 V_166 , V_167 ;
int V_81 ;
V_2 = F_2 ( V_6 ) ;
if ( ! V_2 )
return - V_118 ;
F_47 ( & V_2 -> V_21 ) ;
memcpy ( & V_166 , & V_2 -> V_168 , sizeof( struct V_165 ) ) ;
F_90 ( V_2 ) ;
F_49 ( & V_2 -> V_21 ) ;
F_93 ( & V_9 -> V_169 , & V_164 ) ;
for (; ; ) {
F_47 ( & V_2 -> V_21 ) ;
memcpy ( & V_167 , & V_2 -> V_168 , sizeof( struct V_165 ) ) ;
F_49 ( & V_2 -> V_21 ) ;
F_94 ( V_170 ) ;
if ( ( ( V_163 & V_171 ) && ( V_167 . V_172 != V_166 . V_172 ) ) ||
( ( V_163 & V_173 ) && ( V_167 . V_174 != V_166 . V_174 ) ) ||
( ( V_163 & V_175 ) && ( V_167 . V_176 != V_166 . V_176 ) ) ||
( ( V_163 & V_77 ) && ( V_167 . V_177 != V_166 . V_177 ) ) ) {
V_81 = 0 ;
break;
}
F_95 () ;
if ( F_96 ( V_147 ) ) {
V_81 = - V_157 ;
break;
}
V_166 = V_167 ;
}
F_97 ( V_178 ) ;
F_98 ( & V_9 -> V_169 , & V_164 ) ;
F_4 ( V_2 ) ;
return V_81 ;
}
static int F_99 ( struct V_11 * V_12 ,
struct V_179 * V_168 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_165 V_167 ;
struct V_1 * V_2 ;
V_2 = F_2 ( V_6 ) ;
if ( ! V_2 )
return - V_118 ;
F_47 ( & V_2 -> V_21 ) ;
memcpy ( & V_167 , & V_2 -> V_168 , sizeof( struct V_165 ) ) ;
F_49 ( & V_2 -> V_21 ) ;
F_4 ( V_2 ) ;
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
static int F_100 ( struct V_1 * V_9 ,
struct V_187 T_3 * V_188 )
{
unsigned long V_14 ;
struct V_187 V_189 ;
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_189 = V_9 -> V_188 ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
if ( F_73 ( V_188 , & V_189 , sizeof( V_189 ) ) )
return - V_119 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_9 ,
struct V_187 T_3 * V_190 )
{
struct V_187 V_188 ;
int V_81 ;
unsigned long V_14 ;
if ( ! V_9 -> V_191 )
return - V_192 ;
if ( F_81 ( & V_188 , V_190 , sizeof( * V_190 ) ) )
return - V_119 ;
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_81 = V_9 -> V_191 ( V_9 , & V_188 ) ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
if ( V_81 )
return V_81 ;
if ( F_73 ( V_190 , & V_9 -> V_188 , sizeof( V_9 -> V_188 ) ) )
return - V_119 ;
return 0 ;
}
static int
F_102 ( struct V_11 * V_12 , unsigned int V_193 , unsigned long V_163 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_41 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
void T_3 * V_194 = ( void T_3 * ) V_163 ;
int V_81 = - V_192 ;
switch ( V_193 ) {
case V_195 :
V_81 = F_72 ( V_9 , V_194 ) ;
break;
case V_196 :
F_103 ( & V_12 -> V_197 ) ;
V_81 = F_80 ( V_12 , V_6 , V_194 ) ;
F_104 ( & V_12 -> V_197 ) ;
break;
case V_198 :
F_103 ( & V_12 -> V_197 ) ;
V_81 = F_88 ( V_12 , V_6 ) ;
F_104 ( & V_12 -> V_197 ) ;
break;
case V_199 :
case V_200 :
V_81 = 0 ;
break;
}
if ( V_81 != - V_192 )
goto V_100;
if ( F_85 ( V_12 ) ) {
V_81 = - V_118 ;
goto V_100;
}
switch ( V_193 ) {
case V_201 :
V_81 = F_91 ( V_6 , V_163 ) ;
break;
}
if ( V_81 != - V_192 )
goto V_100;
F_69 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 || F_85 ( V_12 ) ) {
V_81 = - V_118 ;
goto V_202;
}
switch ( V_193 ) {
case V_203 :
V_81 = F_82 ( V_12 , V_6 , V_194 ) ;
break;
case V_204 :
V_81 = F_100 ( V_2 , V_194 ) ;
break;
case V_205 :
V_81 = F_101 ( V_2 , V_194 ) ;
break;
default:
if ( V_2 -> V_15 -> V_206 )
V_81 = V_2 -> V_15 -> V_206 ( V_2 , V_193 , V_163 ) ;
break;
}
V_202:
F_71 ( & V_9 -> V_10 ) ;
V_100:
return V_81 ;
}
static void F_105 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_2 ;
F_69 ( & V_6 -> V_9 . V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( V_2 && V_2 -> V_15 -> V_207 )
V_2 -> V_15 -> V_207 ( V_2 , & V_12 -> V_36 ) ;
F_71 ( & V_6 -> V_9 . V_10 ) ;
}
static void F_106 ( struct V_11 * V_12 ,
struct V_54 * V_70 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_2 ;
unsigned int V_35 = V_12 -> V_36 . V_37 ;
unsigned int V_208 = V_209 | V_210 | V_211 | V_212 | V_213 ;
bool V_214 = false ;
F_69 ( & V_6 -> V_9 . V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_100;
if ( V_2 -> V_14 & V_215 ) {
V_208 |= V_216 | V_217 | V_218 ;
V_214 =
V_12 -> V_36 . V_219 [ V_220 ] != V_70 -> V_219 [ V_220 ] ||
V_12 -> V_36 . V_219 [ V_221 ] != V_70 -> V_219 [ V_221 ] ;
}
if ( ( V_35 ^ V_70 -> V_37 ) == 0 &&
V_12 -> V_36 . V_222 == V_70 -> V_222 &&
V_12 -> V_36 . V_223 == V_70 -> V_223 &&
( ( V_12 -> V_36 . V_224 ^ V_70 -> V_224 ) & V_208 ) == 0 &&
! V_214 ) {
goto V_100;
}
F_26 ( V_12 , V_6 , V_70 ) ;
V_35 = V_12 -> V_36 . V_37 ;
if ( ( V_70 -> V_37 & V_65 ) && ! ( V_35 & V_65 ) )
F_36 ( V_2 , V_38 | V_39 ) ;
else if ( ! ( V_70 -> V_37 & V_65 ) && ( V_35 & V_65 ) ) {
unsigned int V_92 = V_39 ;
if ( ! ( V_35 & V_73 ) || ! F_107 ( V_12 ) )
V_92 |= V_38 ;
F_28 ( V_2 , V_92 ) ;
}
V_100:
F_71 ( & V_6 -> V_9 . V_10 ) ;
}
static void F_108 ( struct V_11 * V_12 , struct V_225 * V_226 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_41 * V_9 ;
if ( ! V_6 ) {
struct V_227 * V_228 = V_12 -> V_229 -> V_230 ;
V_6 = V_228 -> V_6 + V_12 -> V_87 ;
V_9 = & V_6 -> V_9 ;
F_47 ( & V_9 -> V_21 ) ;
-- V_9 -> V_84 ;
F_49 ( & V_9 -> V_21 ) ;
return;
}
V_9 = & V_6 -> V_9 ;
F_59 ( L_3 , V_12 -> V_87 ) ;
F_109 ( V_12 -> V_9 , V_12 , V_226 ) ;
}
static void F_110 ( struct V_41 * V_9 )
{
struct V_5 * V_6 = F_68 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 = F_7 ( V_6 ) ;
if ( F_111 ( ! V_2 , L_4 ) )
return;
F_47 ( & V_2 -> V_21 ) ;
V_2 -> V_15 -> V_231 ( V_2 ) ;
F_49 ( & V_2 -> V_21 ) ;
F_37 ( V_9 ) ;
F_38 ( V_9 , 0 ) ;
F_22 ( V_6 , V_232 ) ;
}
static void F_112 ( struct V_11 * V_12 , int V_52 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_233 , V_234 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( V_9 -> type == V_27 || V_9 -> V_51 == 0 ) {
F_4 ( V_9 ) ;
return;
}
V_233 = ( V_9 -> V_52 - V_53 / 50 ) / V_9 -> V_51 ;
V_233 = V_233 / 5 ;
if ( V_233 == 0 )
V_233 = 1 ;
if ( V_52 && V_52 < V_233 )
V_233 = V_52 ;
if ( V_52 == 0 || V_52 > 2 * V_9 -> V_52 )
V_52 = 2 * V_9 -> V_52 ;
V_234 = V_235 + V_52 ;
F_59 ( L_5 ,
V_9 -> line , V_235 , V_234 ) ;
while ( ! V_9 -> V_15 -> V_153 ( V_9 ) ) {
F_113 ( F_70 ( V_233 ) ) ;
if ( F_96 ( V_147 ) )
break;
if ( F_114 ( V_235 , V_234 ) )
break;
}
F_4 ( V_9 ) ;
}
static void F_115 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_41 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
unsigned long V_14 ;
F_59 ( L_6 , V_12 -> V_87 ) ;
F_69 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
F_111 ( ! V_2 , L_7 ) ;
if ( F_116 ( V_9 ) ) {
F_58 ( V_12 ) ;
F_33 ( V_12 , V_6 ) ;
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_9 -> V_84 = 0 ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
F_117 ( V_9 , 0 ) ;
F_118 ( V_9 , NULL ) ;
if ( V_2 && ! F_25 ( V_2 ) )
F_22 ( V_6 , V_232 ) ;
F_119 ( & V_9 -> V_236 ) ;
F_119 ( & V_9 -> V_169 ) ;
}
F_71 ( & V_9 -> V_10 ) ;
}
static void F_37 ( struct V_41 * V_9 )
{
struct V_5 * V_6 = F_68 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 = F_7 ( V_6 ) ;
F_119 ( & V_9 -> V_169 ) ;
if ( V_2 )
V_2 -> V_15 -> V_237 ( V_2 ) ;
if ( V_2 )
F_120 ( V_2 -> V_104 ) ;
}
static int F_121 ( struct V_41 * V_9 )
{
struct V_5 * V_6 = F_68 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_2 ( V_6 ) ;
if ( F_44 ( ! V_2 ) )
return 1 ;
F_47 ( & V_2 -> V_21 ) ;
F_90 ( V_2 ) ;
V_22 = V_2 -> V_15 -> V_76 ( V_2 ) ;
F_49 ( & V_2 -> V_21 ) ;
F_4 ( V_2 ) ;
if ( V_22 & V_238 )
return 1 ;
return 0 ;
}
static void F_122 ( struct V_41 * V_9 , int V_239 )
{
struct V_5 * V_6 = F_68 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_2 ( V_6 ) ;
if ( ! V_2 )
return;
if ( V_239 )
F_28 ( V_2 , V_39 | V_38 ) ;
else
F_36 ( V_2 , V_39 | V_38 ) ;
F_4 ( V_2 ) ;
}
static int F_123 ( struct V_11 * V_12 , struct V_225 * V_226 )
{
struct V_227 * V_228 = V_12 -> V_229 -> V_230 ;
int V_26 , line = V_12 -> V_87 ;
struct V_5 * V_6 = V_228 -> V_6 + line ;
V_12 -> V_13 = V_6 ;
V_26 = F_124 ( & V_6 -> V_9 , V_12 , V_226 ) ;
if ( V_26 > 0 )
V_26 = 0 ;
return V_26 ;
}
static int F_125 ( struct V_41 * V_9 , struct V_11 * V_12 )
{
struct V_5 * V_6 = F_68 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 || V_2 -> V_14 & V_240 )
return - V_241 ;
V_9 -> V_144 = ( V_2 -> V_14 & V_145 ) ? 1 : 0 ;
return F_30 ( V_12 , V_6 , 0 ) ;
}
static const char * F_126 ( struct V_1 * V_9 )
{
const char * V_242 = NULL ;
if ( V_9 -> V_15 -> type )
V_242 = V_9 -> V_15 -> type ( V_9 ) ;
if ( ! V_242 )
V_242 = L_8 ;
return V_242 ;
}
static void F_127 ( struct V_243 * V_244 , struct V_227 * V_228 , int V_245 )
{
struct V_5 * V_6 = V_228 -> V_6 + V_245 ;
struct V_41 * V_9 = & V_6 -> V_9 ;
enum V_246 V_247 ;
struct V_1 * V_2 ;
char V_248 [ 32 ] ;
unsigned int V_3 ;
int V_249 ;
F_69 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_100;
V_249 = V_2 -> V_112 >= V_250 ;
F_128 ( V_244 , L_9 ,
V_2 -> line , F_126 ( V_2 ) ,
V_249 ? L_10 : L_11 ,
V_249 ? ( unsigned long long ) V_2 -> V_116
: ( unsigned long long ) V_2 -> V_101 ,
V_2 -> V_104 ) ;
if ( V_2 -> type == V_27 ) {
F_129 ( V_244 , '\n' ) ;
goto V_100;
}
if ( F_29 ( V_40 ) ) {
V_247 = V_6 -> V_247 ;
if ( V_247 != V_28 )
F_22 ( V_6 , V_28 ) ;
F_47 ( & V_2 -> V_21 ) ;
V_3 = V_2 -> V_15 -> V_76 ( V_2 ) ;
F_49 ( & V_2 -> V_21 ) ;
if ( V_247 != V_28 )
F_22 ( V_6 , V_247 ) ;
F_128 ( V_244 , L_12 ,
V_2 -> V_168 . V_181 , V_2 -> V_168 . V_180 ) ;
if ( V_2 -> V_168 . V_182 )
F_128 ( V_244 , L_13 , V_2 -> V_168 . V_182 ) ;
if ( V_2 -> V_168 . V_184 )
F_128 ( V_244 , L_14 , V_2 -> V_168 . V_184 ) ;
if ( V_2 -> V_168 . V_185 )
F_128 ( V_244 , L_15 , V_2 -> V_168 . V_185 ) ;
if ( V_2 -> V_168 . V_183 )
F_128 ( V_244 , L_16 , V_2 -> V_168 . V_183 ) ;
#define F_130 ( T_4 , V_242 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_131 ( T_4 , V_242 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_248 [ 0 ] = '\0' ;
V_248 [ 1 ] = '\0' ;
F_130 ( V_38 , L_17 ) ;
F_131 ( V_77 , L_18 ) ;
F_130 ( V_39 , L_19 ) ;
F_131 ( V_173 , L_20 ) ;
F_131 ( V_238 , L_21 ) ;
F_131 ( V_171 , L_22 ) ;
if ( V_248 [ 0 ] )
V_248 [ 0 ] = ' ' ;
F_132 ( V_244 , V_248 ) ;
}
F_129 ( V_244 , '\n' ) ;
#undef F_131
#undef F_130
V_100:
F_71 ( & V_9 -> V_10 ) ;
}
static int F_133 ( struct V_243 * V_244 , void * V_251 )
{
struct V_252 * V_253 = V_244 -> V_254 ;
struct V_227 * V_228 = V_253 -> V_230 ;
int V_245 ;
F_128 ( V_244 , L_23 , L_24 , L_24 , L_24 ) ;
for ( V_245 = 0 ; V_245 < V_228 -> V_255 ; V_245 ++ )
F_127 ( V_244 , V_228 , V_245 ) ;
return 0 ;
}
static int F_134 ( struct V_256 * V_256 , struct V_225 * V_225 )
{
return F_135 ( V_225 , F_133 , F_136 ( V_256 ) ) ;
}
void F_137 ( struct V_1 * V_9 , const char * V_257 ,
unsigned int V_84 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_245 ;
for ( V_245 = 0 ; V_245 < V_84 ; V_245 ++ , V_257 ++ ) {
if ( * V_257 == '\n' )
putchar ( V_9 , '\r' ) ;
putchar ( V_9 , * V_257 ) ;
}
}
struct V_1 * T_5
F_138 ( struct V_1 * V_258 , int V_255 , struct V_259 * V_260 )
{
int V_261 = V_260 -> V_87 ;
if ( V_261 < 0 || V_261 >= V_255 || ( V_258 [ V_261 ] . V_101 == 0 &&
V_258 [ V_261 ] . V_262 == NULL ) )
for ( V_261 = 0 ; V_261 < V_255 ; V_261 ++ )
if ( V_258 [ V_261 ] . V_101 != 0 ||
V_258 [ V_261 ] . V_262 != NULL )
break;
V_260 -> V_87 = V_261 ;
return V_258 + V_261 ;
}
int F_139 ( char * V_263 , unsigned char * V_112 , T_6 * V_264 ,
char * * V_265 )
{
if ( strncmp ( V_263 , L_25 , 5 ) == 0 ) {
* V_112 = V_250 ;
V_263 += 5 ;
} else if ( strncmp ( V_263 , L_26 , 7 ) == 0 ) {
* V_112 = V_266 ;
V_263 += 7 ;
} else if ( strncmp ( V_263 , L_27 , 7 ) == 0 ) {
* V_112 = V_267 ;
V_263 += 7 ;
} else if ( strncmp ( V_263 , L_28 , 9 ) == 0 ) {
* V_112 = V_268 ;
V_263 += 9 ;
} else if ( strncmp ( V_263 , L_29 , 13 ) == 0 ) {
* V_112 = F_140 ( V_269 ) ?
V_268 : V_267 ;
V_263 += 13 ;
} else if ( strncmp ( V_263 , L_30 , 3 ) == 0 ) {
* V_112 = V_270 ;
V_263 += 3 ;
} else if ( strncmp ( V_263 , L_31 , 2 ) == 0 ) {
* V_112 = V_250 ;
} else {
return - V_133 ;
}
* V_264 = F_141 ( V_263 , NULL , 0 ) ;
V_263 = strchr ( V_263 , ',' ) ;
if ( V_263 )
V_263 ++ ;
* V_265 = V_263 ;
return 0 ;
}
void
F_142 ( char * V_265 , int * V_43 , int * V_184 , int * V_44 , int * V_271 )
{
char * V_257 = V_265 ;
* V_43 = F_143 ( V_257 , NULL , 10 ) ;
while ( * V_257 >= '0' && * V_257 <= '9' )
V_257 ++ ;
if ( * V_257 )
* V_184 = * V_257 ++ ;
if ( * V_257 )
* V_44 = * V_257 ++ - '0' ;
if ( * V_257 )
* V_271 = * V_257 ;
}
int
F_144 ( struct V_1 * V_9 , struct V_259 * V_260 ,
int V_43 , int V_184 , int V_44 , int V_271 )
{
struct V_54 V_36 ;
static struct V_54 V_272 ;
if ( ! ( F_25 ( V_9 ) && ( V_9 -> V_34 -> V_14 & V_273 ) ) ) {
F_145 ( & V_9 -> V_21 ) ;
F_146 ( & V_9 -> V_21 , & V_274 ) ;
}
memset ( & V_36 , 0 , sizeof( struct V_54 ) ) ;
V_36 . V_37 |= V_275 | V_276 | V_75 ;
F_43 ( & V_36 , V_43 , V_43 ) ;
if ( V_44 == 7 )
V_36 . V_37 |= V_48 ;
else
V_36 . V_37 |= V_277 ;
switch ( V_184 ) {
case 'o' : case 'O' :
V_36 . V_37 |= V_278 ;
case 'e' : case 'E' :
V_36 . V_37 |= V_50 ;
break;
}
if ( V_271 == 'r' )
V_36 . V_37 |= V_73 ;
V_9 -> V_22 |= V_39 ;
V_9 -> V_15 -> V_72 ( V_9 , & V_36 , & V_272 ) ;
if ( V_260 )
V_260 -> V_35 = V_36 . V_37 ;
return 0 ;
}
static void F_22 ( struct V_5 * V_6 ,
enum V_246 V_247 )
{
struct V_1 * V_9 = F_7 ( V_6 ) ;
if ( V_6 -> V_247 != V_247 ) {
if ( V_9 && V_9 -> V_15 -> V_279 )
V_9 -> V_15 -> V_279 ( V_9 , V_247 , V_6 -> V_247 ) ;
V_6 -> V_247 = V_247 ;
}
}
static int F_147 ( struct V_280 * V_146 , void * V_281 )
{
struct V_282 * V_283 = V_281 ;
struct V_252 * V_284 = V_283 -> V_229 -> V_252 ;
T_7 V_285 = F_148 ( V_284 -> V_286 , V_284 -> V_287 ) +
V_283 -> V_9 -> line ;
return V_146 -> V_285 == V_285 ;
}
int F_149 ( struct V_227 * V_228 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_228 -> V_6 + V_2 -> line ;
struct V_41 * V_9 = & V_6 -> V_9 ;
struct V_280 * V_288 ;
struct V_282 V_283 = { V_2 , V_228 } ;
F_69 ( & V_9 -> V_10 ) ;
V_288 = F_150 ( V_2 -> V_146 , & V_283 , F_147 ) ;
if ( F_151 ( V_288 ) ) {
if ( ! F_152 ( V_2 -> V_104 ) )
V_2 -> V_289 = 1 ;
F_153 ( V_288 ) ;
F_71 ( & V_9 -> V_10 ) ;
return 0 ;
}
F_153 ( V_288 ) ;
if ( ! V_290 && F_25 ( V_2 ) )
goto V_291;
V_2 -> V_292 = 1 ;
if ( F_31 ( V_9 ) ) {
const struct V_293 * V_15 = V_2 -> V_15 ;
int V_294 ;
F_38 ( V_9 , 1 ) ;
F_34 ( V_9 , 0 ) ;
F_47 ( & V_2 -> V_21 ) ;
V_15 -> V_16 ( V_2 ) ;
V_15 -> V_23 ( V_2 , 0 ) ;
V_15 -> V_231 ( V_2 ) ;
F_49 ( & V_2 -> V_21 ) ;
for ( V_294 = 3 ; ! V_15 -> V_153 ( V_2 ) && V_294 ; V_294 -- )
F_154 ( 10 ) ;
if ( ! V_294 )
F_155 ( V_2 -> V_146 , L_32 ,
V_228 -> V_295 ,
V_228 -> V_252 -> V_296 + V_2 -> line ) ;
V_15 -> V_237 ( V_2 ) ;
}
if ( F_25 ( V_2 ) )
F_156 ( V_2 -> V_34 ) ;
F_22 ( V_6 , V_232 ) ;
V_291:
F_71 ( & V_9 -> V_10 ) ;
return 0 ;
}
int F_157 ( struct V_227 * V_228 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_228 -> V_6 + V_2 -> line ;
struct V_41 * V_9 = & V_6 -> V_9 ;
struct V_280 * V_288 ;
struct V_282 V_283 = { V_2 , V_228 } ;
struct V_54 V_36 ;
F_69 ( & V_9 -> V_10 ) ;
V_288 = F_150 ( V_2 -> V_146 , & V_283 , F_147 ) ;
if ( ! V_2 -> V_292 && F_151 ( V_288 ) ) {
if ( V_2 -> V_289 ) {
F_158 ( V_2 -> V_104 ) ;
V_2 -> V_289 = 0 ;
}
F_153 ( V_288 ) ;
F_71 ( & V_9 -> V_10 ) ;
return 0 ;
}
F_153 ( V_288 ) ;
V_2 -> V_292 = 0 ;
if ( F_25 ( V_2 ) ) {
memset ( & V_36 , 0 , sizeof( struct V_54 ) ) ;
V_36 . V_37 = V_2 -> V_34 -> V_35 ;
if ( V_9 -> V_12 && V_36 . V_37 == 0 )
V_36 = V_9 -> V_12 -> V_36 ;
if ( V_290 )
F_22 ( V_6 , V_28 ) ;
V_2 -> V_15 -> V_72 ( V_2 , & V_36 , NULL ) ;
if ( V_290 )
F_159 ( V_2 -> V_34 ) ;
}
if ( F_160 ( V_9 ) ) {
const struct V_293 * V_15 = V_2 -> V_15 ;
int V_81 ;
F_22 ( V_6 , V_28 ) ;
F_47 ( & V_2 -> V_21 ) ;
V_15 -> V_23 ( V_2 , 0 ) ;
F_49 ( & V_2 -> V_21 ) ;
if ( V_290 || ! F_25 ( V_2 ) ) {
struct V_11 * V_12 = V_9 -> V_12 ;
V_81 = V_15 -> V_33 ( V_2 ) ;
if ( V_81 == 0 ) {
if ( V_12 )
F_26 ( V_12 , V_6 , NULL ) ;
F_47 ( & V_2 -> V_21 ) ;
V_15 -> V_23 ( V_2 , V_2 -> V_22 ) ;
V_15 -> V_17 ( V_2 ) ;
F_49 ( & V_2 -> V_21 ) ;
F_34 ( V_9 , 1 ) ;
} else {
F_33 ( V_12 , V_6 ) ;
}
}
F_38 ( V_9 , 0 ) ;
}
F_71 ( & V_9 -> V_10 ) ;
return 0 ;
}
static inline void
F_161 ( struct V_227 * V_228 , struct V_1 * V_9 )
{
char V_297 [ 64 ] ;
switch ( V_9 -> V_112 ) {
case V_270 :
snprintf ( V_297 , sizeof( V_297 ) , L_33 , V_9 -> V_101 ) ;
break;
case V_298 :
snprintf ( V_297 , sizeof( V_297 ) ,
L_34 , V_9 -> V_101 , V_9 -> V_110 ) ;
break;
case V_250 :
case V_266 :
case V_267 :
case V_268 :
case V_299 :
case V_300 :
snprintf ( V_297 , sizeof( V_297 ) ,
L_35 , ( unsigned long long ) V_9 -> V_116 ) ;
break;
default:
F_162 ( V_297 , L_36 , sizeof( V_297 ) ) ;
break;
}
F_163 ( V_301 L_37 ,
V_9 -> V_146 ? V_295 ( V_9 -> V_146 ) : L_24 ,
V_9 -> V_146 ? L_38 : L_24 ,
V_228 -> V_295 ,
V_228 -> V_252 -> V_296 + V_9 -> line ,
V_297 , V_9 -> V_104 , V_9 -> V_69 / 16 , F_126 ( V_9 ) ) ;
}
static void
F_164 ( struct V_227 * V_228 , struct V_5 * V_6 ,
struct V_1 * V_9 )
{
unsigned int V_14 ;
if ( ! V_9 -> V_101 && ! V_9 -> V_116 && ! V_9 -> V_262 )
return;
V_14 = 0 ;
if ( V_9 -> V_14 & V_159 )
V_14 |= V_160 ;
if ( V_9 -> V_14 & V_302 ) {
if ( ! ( V_9 -> V_14 & V_303 ) ) {
V_9 -> type = V_27 ;
V_14 |= V_158 ;
}
V_9 -> V_15 -> V_161 ( V_9 , V_14 ) ;
}
if ( V_9 -> type != V_27 ) {
unsigned long V_14 ;
F_161 ( V_228 , V_9 ) ;
F_22 ( V_6 , V_28 ) ;
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_9 -> V_15 -> V_23 ( V_9 , V_9 -> V_22 & V_39 ) ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
if ( V_9 -> V_34 && ! ( V_9 -> V_34 -> V_14 & V_273 ) )
F_165 ( V_9 -> V_34 ) ;
if ( ! F_25 ( V_9 ) )
F_22 ( V_6 , V_232 ) ;
}
}
static int F_166 ( struct V_252 * V_229 , int line , char * V_265 )
{
struct V_227 * V_228 = V_229 -> V_230 ;
struct V_5 * V_6 = V_228 -> V_6 + line ;
struct V_41 * V_304 ;
struct V_1 * V_9 ;
int V_43 = 9600 ;
int V_44 = 8 ;
int V_184 = 'n' ;
int V_271 = 'n' ;
int V_81 = 0 ;
if ( ! V_6 )
return - 1 ;
V_304 = & V_6 -> V_9 ;
F_69 ( & V_304 -> V_10 ) ;
V_9 = F_7 ( V_6 ) ;
if ( ! V_9 || ! ( V_9 -> V_15 -> V_305 && V_9 -> V_15 -> V_306 ) ) {
V_81 = - 1 ;
goto V_100;
}
if ( V_9 -> V_15 -> V_307 ) {
if ( ! F_31 ( V_304 ) )
V_81 = V_9 -> V_15 -> V_307 ( V_9 ) ;
}
if ( ! V_81 && V_265 ) {
F_142 ( V_265 , & V_43 , & V_184 , & V_44 , & V_271 ) ;
V_81 = F_144 ( V_9 , NULL , V_43 , V_184 , V_44 , V_271 ) ;
}
V_100:
F_71 ( & V_304 -> V_10 ) ;
return V_81 ;
}
static int F_167 ( struct V_252 * V_229 , int line )
{
struct V_227 * V_228 = V_229 -> V_230 ;
struct V_5 * V_6 = V_228 -> V_6 + line ;
struct V_1 * V_9 ;
int V_81 = - 1 ;
if ( V_6 ) {
V_9 = F_2 ( V_6 ) ;
if ( V_9 ) {
V_81 = V_9 -> V_15 -> V_305 ( V_9 ) ;
F_4 ( V_9 ) ;
}
}
return V_81 ;
}
static void F_168 ( struct V_252 * V_229 , int line , char V_89 )
{
struct V_227 * V_228 = V_229 -> V_230 ;
struct V_5 * V_6 = V_228 -> V_6 + line ;
struct V_1 * V_9 ;
if ( ! V_6 )
return;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( V_89 == '\n' )
V_9 -> V_15 -> V_306 ( V_9 , '\r' ) ;
V_9 -> V_15 -> V_306 ( V_9 , V_89 ) ;
F_4 ( V_9 ) ;
}
int F_169 ( struct V_227 * V_228 )
{
struct V_252 * V_308 ;
int V_245 , V_26 ;
F_10 ( V_228 -> V_6 ) ;
V_228 -> V_6 = F_170 ( sizeof( struct V_5 ) * V_228 -> V_255 , V_31 ) ;
if ( ! V_228 -> V_6 )
goto V_100;
V_308 = F_171 ( V_228 -> V_255 ) ;
if ( ! V_308 )
goto V_309;
V_228 -> V_252 = V_308 ;
V_308 -> V_310 = V_228 -> V_310 ;
V_308 -> V_311 = V_228 -> V_295 ;
V_308 -> V_286 = V_228 -> V_286 ;
V_308 -> V_287 = V_228 -> V_312 ;
V_308 -> type = V_313 ;
V_308 -> V_314 = V_315 ;
V_308 -> V_316 = V_317 ;
V_308 -> V_316 . V_37 = V_318 | V_277 | V_275 | V_276 | V_75 ;
V_308 -> V_316 . V_223 = V_308 -> V_316 . V_222 = 9600 ;
V_308 -> V_14 = V_319 | V_320 ;
V_308 -> V_230 = V_228 ;
F_172 ( V_308 , & V_293 ) ;
for ( V_245 = 0 ; V_245 < V_228 -> V_255 ; V_245 ++ ) {
struct V_5 * V_6 = V_228 -> V_6 + V_245 ;
struct V_41 * V_9 = & V_6 -> V_9 ;
F_173 ( V_9 ) ;
V_9 -> V_15 = & V_321 ;
}
V_26 = F_174 ( V_308 ) ;
if ( V_26 >= 0 )
return V_26 ;
for ( V_245 = 0 ; V_245 < V_228 -> V_255 ; V_245 ++ )
F_175 ( & V_228 -> V_6 [ V_245 ] . V_9 ) ;
F_176 ( V_308 ) ;
V_309:
F_177 ( V_228 -> V_6 ) ;
V_100:
return - V_32 ;
}
void F_178 ( struct V_227 * V_228 )
{
struct V_252 * V_263 = V_228 -> V_252 ;
unsigned int V_245 ;
F_179 ( V_263 ) ;
F_176 ( V_263 ) ;
for ( V_245 = 0 ; V_245 < V_228 -> V_255 ; V_245 ++ )
F_175 ( & V_228 -> V_6 [ V_245 ] . V_9 ) ;
F_177 ( V_228 -> V_6 ) ;
V_228 -> V_6 = NULL ;
V_228 -> V_252 = NULL ;
}
struct V_252 * F_180 ( struct V_259 * V_260 , int * V_87 )
{
struct V_227 * V_263 = V_260 -> V_281 ;
* V_87 = V_260 -> V_87 ;
return V_263 -> V_252 ;
}
static T_8 F_181 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . V_106 * 16 ) ;
}
static T_8 F_183 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . type ) ;
}
static T_8 F_184 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . line ) ;
}
static T_8 F_185 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
unsigned long V_325 ;
F_67 ( V_9 , & V_117 ) ;
V_325 = V_117 . V_9 ;
if ( V_102 )
V_325 |= ( unsigned long ) V_117 . V_103 << V_102 ;
return snprintf ( V_30 , V_324 , L_40 , V_325 ) ;
}
static T_8 F_186 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . V_104 ) ;
}
static T_8 F_187 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_41 , V_117 . V_14 ) ;
}
static T_8 F_188 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . V_105 ) ;
}
static T_8 F_189 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . V_107 ) ;
}
static T_8 F_190 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . V_108 ) ;
}
static T_8 F_191 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . V_68 ) ;
}
static T_8 F_192 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . V_111 ) ;
}
static T_8 F_193 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_40 , ( unsigned long ) V_117 . V_115 ) ;
}
static T_8 F_194 ( struct V_280 * V_146 ,
struct V_322 * V_323 , char * V_30 )
{
struct V_97 V_117 ;
struct V_41 * V_9 = F_182 ( V_146 ) ;
F_67 ( V_9 , & V_117 ) ;
return snprintf ( V_30 , V_324 , L_39 , V_117 . V_113 ) ;
}
int F_195 ( struct V_227 * V_228 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_41 * V_9 ;
int V_81 = 0 ;
struct V_280 * V_288 ;
int V_326 ;
F_10 ( F_196 () ) ;
if ( V_2 -> line >= V_228 -> V_255 )
return - V_133 ;
V_6 = V_228 -> V_6 + V_2 -> line ;
V_9 = & V_6 -> V_9 ;
F_69 ( & V_327 ) ;
F_69 ( & V_9 -> V_10 ) ;
if ( V_6 -> V_1 ) {
V_81 = - V_133 ;
goto V_100;
}
F_197 ( & V_6 -> V_7 , 1 ) ;
F_198 ( & V_6 -> V_8 ) ;
V_6 -> V_1 = V_2 ;
V_2 -> V_6 = V_6 ;
V_6 -> V_247 = V_328 ;
V_2 -> V_34 = V_228 -> V_34 ;
V_2 -> V_312 = V_228 -> V_252 -> V_287 + V_2 -> line ;
if ( ! ( F_25 ( V_2 ) && ( V_2 -> V_34 -> V_14 & V_273 ) ) ) {
F_145 ( & V_2 -> V_21 ) ;
F_146 ( & V_2 -> V_21 , & V_274 ) ;
}
if ( V_2 -> V_34 && V_2 -> V_146 )
F_199 ( V_2 -> V_146 -> V_329 , V_2 -> V_34 -> V_311 , V_2 -> line ) ;
F_164 ( V_228 , V_6 , V_2 ) ;
V_9 -> V_259 = F_25 ( V_2 ) ;
V_326 = 2 ;
if ( V_2 -> V_330 )
V_326 ++ ;
V_2 -> V_331 = F_200 ( V_326 , sizeof( * V_2 -> V_331 ) ,
V_31 ) ;
if ( ! V_2 -> V_331 ) {
V_81 = - V_32 ;
goto V_100;
}
V_2 -> V_331 [ 0 ] = & V_332 ;
if ( V_2 -> V_330 )
V_2 -> V_331 [ 1 ] = V_2 -> V_330 ;
V_288 = F_201 ( V_9 , V_228 -> V_252 ,
V_2 -> line , V_2 -> V_146 , V_9 , V_2 -> V_331 ) ;
if ( F_202 ( ! F_203 ( V_288 ) ) ) {
F_204 ( V_288 , 1 ) ;
} else {
F_155 ( V_2 -> V_146 , L_42 ,
V_2 -> line ) ;
}
V_2 -> V_14 &= ~ V_240 ;
V_100:
F_71 ( & V_9 -> V_10 ) ;
F_71 ( & V_327 ) ;
return V_81 ;
}
int F_205 ( struct V_227 * V_228 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_228 -> V_6 + V_2 -> line ;
struct V_41 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_1 ;
struct V_11 * V_12 ;
int V_81 = 0 ;
F_10 ( F_196 () ) ;
F_69 ( & V_327 ) ;
F_69 ( & V_9 -> V_10 ) ;
V_1 = F_7 ( V_6 ) ;
if ( V_1 != V_2 )
F_206 ( V_2 -> V_146 , L_43 ,
V_1 , V_2 ) ;
if ( ! V_1 ) {
F_71 ( & V_9 -> V_10 ) ;
V_81 = - V_133 ;
goto V_100;
}
V_2 -> V_14 |= V_240 ;
F_71 ( & V_9 -> V_10 ) ;
F_207 ( V_228 -> V_252 , V_2 -> line ) ;
V_12 = F_208 ( V_9 ) ;
if ( V_12 ) {
F_209 ( V_9 -> V_12 ) ;
F_210 ( V_12 ) ;
}
if ( F_25 ( V_2 ) )
F_211 ( V_2 -> V_34 ) ;
if ( V_2 -> type != V_27 && V_2 -> V_15 -> V_141 )
V_2 -> V_15 -> V_141 ( V_2 ) ;
F_177 ( V_2 -> V_331 ) ;
V_2 -> type = V_27 ;
F_69 ( & V_9 -> V_10 ) ;
F_44 ( F_212 ( & V_6 -> V_7 ) < 0 ) ;
F_213 ( V_6 -> V_8 , ! F_214 ( & V_6 -> V_7 ) ) ;
V_6 -> V_1 = NULL ;
F_71 ( & V_9 -> V_10 ) ;
V_100:
F_71 ( & V_327 ) ;
return V_81 ;
}
int F_215 ( struct V_1 * V_333 , struct V_1 * V_334 )
{
if ( V_333 -> V_112 != V_334 -> V_112 )
return 0 ;
switch ( V_333 -> V_112 ) {
case V_270 :
return ( V_333 -> V_101 == V_334 -> V_101 ) ;
case V_298 :
return ( V_333 -> V_101 == V_334 -> V_101 ) &&
( V_333 -> V_110 == V_334 -> V_110 ) ;
case V_250 :
case V_266 :
case V_267 :
case V_268 :
case V_299 :
case V_300 :
return ( V_333 -> V_116 == V_334 -> V_116 ) ;
}
return 0 ;
}
void F_216 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_41 * V_9 = & V_2 -> V_6 -> V_9 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_335 * V_336 ;
F_217 ( & V_2 -> V_21 ) ;
if ( V_12 ) {
V_336 = F_218 ( V_12 ) ;
if ( V_336 ) {
if ( V_336 -> V_15 -> V_337 )
V_336 -> V_15 -> V_337 ( V_12 , V_3 ) ;
F_219 ( V_336 ) ;
}
}
V_2 -> V_168 . V_176 ++ ;
if ( F_1 ( V_2 ) ) {
if ( V_3 )
F_119 ( & V_9 -> V_236 ) ;
else if ( V_12 )
F_220 ( V_12 ) ;
}
}
void F_221 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_217 ( & V_2 -> V_21 ) ;
V_2 -> V_168 . V_177 ++ ;
if ( F_48 ( V_2 ) ) {
if ( V_2 -> V_71 ) {
if ( V_3 ) {
V_2 -> V_71 = 0 ;
V_2 -> V_15 -> V_17 ( V_2 ) ;
F_9 ( V_2 ) ;
}
} else {
if ( ! V_3 ) {
V_2 -> V_71 = 1 ;
V_2 -> V_15 -> V_16 ( V_2 ) ;
}
}
}
}
void F_222 ( struct V_1 * V_9 , unsigned int V_3 ,
unsigned int V_183 , unsigned int V_89 , unsigned int V_338 )
{
struct V_41 * V_304 = & V_9 -> V_6 -> V_9 ;
if ( ( V_3 & V_9 -> V_339 & ~ V_183 ) == 0 )
if ( F_223 ( V_304 , V_89 , V_338 ) == 0 )
++ V_9 -> V_168 . V_186 ;
if ( V_3 & ~ V_9 -> V_339 & V_183 )
if ( F_223 ( V_304 , 0 , V_340 ) == 0 )
++ V_9 -> V_168 . V_186 ;
}
