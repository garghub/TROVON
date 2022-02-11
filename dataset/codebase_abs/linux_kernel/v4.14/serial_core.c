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
static void F_21 ( struct V_1 * V_2 , int raise )
{
int V_24 = V_2 -> V_25 &&
( V_2 -> V_26 . V_14 & V_27 ) ;
int V_28 = ! ! ( V_2 -> V_26 . V_14 & V_29 ) ;
if ( raise ) {
if ( V_24 && ! V_28 ) {
F_22 ( V_2 , V_30 ) ;
F_23 ( V_2 , V_31 ) ;
} else {
F_22 ( V_2 , V_30 | V_31 ) ;
}
} else {
unsigned int V_19 = V_30 ;
V_19 |= ( ! V_24 || ! V_28 ) ? V_31 : 0 ;
F_23 ( V_2 , V_19 ) ;
}
}
static int F_24 ( struct V_11 * V_12 , struct V_5 * V_6 ,
int V_32 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned long V_33 ;
int V_34 = 0 ;
if ( V_2 -> type == V_35 )
return 1 ;
F_25 ( V_6 , V_36 ) ;
if ( ! V_6 -> V_37 . V_38 ) {
V_33 = F_26 ( V_39 ) ;
if ( ! V_33 )
return - V_40 ;
V_6 -> V_37 . V_38 = ( unsigned char * ) V_33 ;
F_27 ( & V_6 -> V_37 ) ;
}
V_34 = V_2 -> V_15 -> V_41 ( V_2 ) ;
if ( V_34 == 0 ) {
if ( F_28 ( V_2 ) && V_2 -> V_42 -> V_43 ) {
V_12 -> V_44 . V_45 = V_2 -> V_42 -> V_43 ;
V_2 -> V_42 -> V_43 = 0 ;
}
F_29 ( V_12 , V_6 , NULL ) ;
if ( V_32 && F_30 ( V_12 ) )
F_21 ( V_2 , 1 ) ;
}
if ( V_34 && F_31 ( V_46 ) )
return 1 ;
return V_34 ;
}
static int F_32 ( struct V_11 * V_12 , struct V_5 * V_6 ,
int V_32 )
{
struct V_47 * V_9 = & V_6 -> V_9 ;
int V_34 ;
if ( F_33 ( V_9 ) )
return 0 ;
V_34 = F_24 ( V_12 , V_6 , V_32 ) ;
if ( V_34 )
F_34 ( V_48 , & V_12 -> V_14 ) ;
return V_34 ;
}
static void F_35 ( struct V_11 * V_12 , struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_47 * V_9 = & V_6 -> V_9 ;
if ( V_12 )
F_34 ( V_48 , & V_12 -> V_14 ) ;
if ( F_33 ( V_9 ) ) {
F_36 ( V_9 , 0 ) ;
if ( V_2 && F_28 ( V_2 ) && V_12 )
V_2 -> V_42 -> V_43 = V_12 -> V_44 . V_45 ;
if ( ! V_12 || F_37 ( V_12 ) )
F_21 ( V_2 , 0 ) ;
F_38 ( V_9 ) ;
}
F_39 ( V_9 , 0 ) ;
if ( V_6 -> V_37 . V_38 ) {
F_40 ( ( unsigned long ) V_6 -> V_37 . V_38 ) ;
V_6 -> V_37 . V_38 = NULL ;
}
}
void
F_41 ( struct V_1 * V_9 , unsigned int V_43 ,
unsigned int V_49 )
{
unsigned int V_50 ;
switch ( V_43 & V_51 ) {
case V_52 :
V_50 = 7 ;
break;
case V_53 :
V_50 = 8 ;
break;
case V_54 :
V_50 = 9 ;
break;
default:
V_50 = 10 ;
break;
}
if ( V_43 & V_55 )
V_50 ++ ;
if ( V_43 & V_56 )
V_50 ++ ;
V_50 = V_50 * V_9 -> V_57 ;
V_9 -> V_58 = ( V_59 * V_50 ) / V_49 + V_59 / 50 ;
}
unsigned int
F_42 ( struct V_1 * V_9 , struct V_60 * V_44 ,
struct V_60 * V_20 , unsigned int V_61 , unsigned int V_62 )
{
unsigned int V_63 ;
unsigned int V_49 ;
unsigned int V_64 ;
int V_65 = 0 ;
T_1 V_14 = V_9 -> V_14 & V_66 ;
switch ( V_14 ) {
case V_67 :
V_64 = 57600 ;
break;
case V_68 :
V_64 = 115200 ;
break;
case V_69 :
V_64 = 230400 ;
break;
case V_70 :
V_64 = 460800 ;
break;
default:
V_64 = 38400 ;
break;
}
for ( V_63 = 0 ; V_63 < 2 ; V_63 ++ ) {
V_49 = F_43 ( V_44 ) ;
if ( V_63 == 0 && V_49 == 38400 )
V_49 = V_64 ;
if ( V_49 == 0 ) {
V_65 = 1 ;
V_49 = 9600 ;
}
if ( V_49 >= V_61 && V_49 <= V_62 )
return V_49 ;
V_44 -> V_45 &= ~ V_71 ;
if ( V_20 ) {
V_49 = F_43 ( V_20 ) ;
if ( ! V_65 )
F_44 ( V_44 ,
V_49 , V_49 ) ;
V_20 = NULL ;
continue;
}
if ( ! V_65 ) {
if ( V_49 <= V_61 )
F_44 ( V_44 ,
V_61 + 1 , V_61 + 1 ) ;
else
F_44 ( V_44 ,
V_62 - 1 , V_62 - 1 ) ;
}
}
F_45 ( 1 ) ;
return 0 ;
}
unsigned int
F_46 ( struct V_1 * V_9 , unsigned int V_49 )
{
unsigned int V_72 ;
if ( V_49 == 38400 && ( V_9 -> V_14 & V_66 ) == V_73 )
V_72 = V_9 -> V_74 ;
else
V_72 = F_47 ( V_9 -> V_75 , 16 * V_49 ) ;
return V_72 ;
}
static void F_29 ( struct V_11 * V_12 , struct V_5 * V_6 ,
struct V_60 * V_76 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_60 * V_44 ;
int V_77 ;
if ( ! V_12 || V_2 -> type == V_35 )
return;
V_44 = & V_12 -> V_44 ;
V_2 -> V_15 -> V_78 ( V_2 , V_44 , V_76 ) ;
F_48 ( & V_2 -> V_21 ) ;
if ( V_44 -> V_45 & V_79 )
V_2 -> V_3 |= V_80 ;
else
V_2 -> V_3 &= ~ V_80 ;
if ( V_44 -> V_45 & V_81 )
V_2 -> V_3 &= ~ V_4 ;
else
V_2 -> V_3 |= V_4 ;
V_77 = V_2 -> V_77 ;
V_2 -> V_77 = F_49 ( V_2 ) &&
! ( V_2 -> V_15 -> V_82 ( V_2 ) & V_83 ) ;
if ( V_2 -> V_77 ) {
if ( ! V_77 )
V_2 -> V_15 -> V_16 ( V_2 ) ;
} else {
if ( V_77 )
F_15 ( V_12 ) ;
}
F_50 ( & V_2 -> V_21 ) ;
}
static int F_51 ( struct V_11 * V_12 , unsigned char V_84 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
struct V_85 * V_86 ;
unsigned long V_14 ;
int V_87 = 0 ;
V_86 = & V_6 -> V_37 ;
if ( ! V_86 -> V_38 )
return 0 ;
V_9 = F_13 ( V_6 , V_14 ) ;
if ( V_9 && F_52 ( V_86 ) != 0 ) {
V_86 -> V_38 [ V_86 -> V_88 ] = V_84 ;
V_86 -> V_88 = ( V_86 -> V_88 + 1 ) & ( V_89 - 1 ) ;
V_87 = 1 ;
}
F_14 ( V_9 , V_14 ) ;
return V_87 ;
}
static void F_53 ( struct V_11 * V_12 )
{
F_17 ( V_12 ) ;
}
static int F_54 ( struct V_11 * V_12 ,
const unsigned char * V_38 , int V_90 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
struct V_85 * V_86 ;
unsigned long V_14 ;
int V_84 , V_87 = 0 ;
if ( ! V_6 ) {
F_45 ( 1 ) ;
return - V_91 ;
}
V_86 = & V_6 -> V_37 ;
if ( ! V_86 -> V_38 )
return 0 ;
V_9 = F_13 ( V_6 , V_14 ) ;
while ( V_9 ) {
V_84 = F_55 ( V_86 -> V_88 , V_86 -> V_92 , V_89 ) ;
if ( V_90 < V_84 )
V_84 = V_90 ;
if ( V_84 <= 0 )
break;
memcpy ( V_86 -> V_38 + V_86 -> V_88 , V_38 , V_84 ) ;
V_86 -> V_88 = ( V_86 -> V_88 + V_84 ) & ( V_89 - 1 ) ;
V_38 += V_84 ;
V_90 -= V_84 ;
V_87 += V_84 ;
}
F_15 ( V_12 ) ;
F_14 ( V_9 , V_14 ) ;
return V_87 ;
}
static int F_56 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
int V_87 ;
V_9 = F_13 ( V_6 , V_14 ) ;
V_87 = F_52 ( & V_6 -> V_37 ) ;
F_14 ( V_9 , V_14 ) ;
return V_87 ;
}
static int F_57 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
int V_87 ;
V_9 = F_13 ( V_6 , V_14 ) ;
V_87 = F_58 ( & V_6 -> V_37 ) ;
F_14 ( V_9 , V_14 ) ;
return V_87 ;
}
static void F_59 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
if ( ! V_6 ) {
F_45 ( 1 ) ;
return;
}
F_60 ( L_1 , V_12 -> V_93 ) ;
V_9 = F_13 ( V_6 , V_14 ) ;
if ( ! V_9 )
return;
F_27 ( & V_6 -> V_37 ) ;
if ( V_9 -> V_15 -> V_94 )
V_9 -> V_15 -> V_94 ( V_9 ) ;
F_14 ( V_9 , V_14 ) ;
F_11 ( & V_6 -> V_9 ) ;
}
static void F_61 ( struct V_11 * V_12 , char V_95 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_14 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( V_9 -> V_15 -> V_96 )
V_9 -> V_15 -> V_96 ( V_9 , V_95 ) ;
else {
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_9 -> V_97 = V_95 ;
if ( V_95 )
V_9 -> V_15 -> V_17 ( V_9 ) ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
}
F_4 ( V_9 ) ;
}
static void F_62 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
T_2 V_98 = 0 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( F_63 ( V_12 ) )
V_98 |= V_99 ;
if ( F_64 ( V_12 ) )
V_98 |= V_100 ;
if ( V_9 -> V_3 & V_98 ) {
V_9 -> V_15 -> V_101 ( V_9 ) ;
V_98 &= ~ V_9 -> V_3 ;
}
if ( V_98 & V_100 )
F_23 ( V_9 , V_31 ) ;
if ( V_98 & V_99 )
F_61 ( V_12 , F_65 ( V_12 ) ) ;
F_4 ( V_9 ) ;
}
static void F_66 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
T_2 V_98 = 0 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( F_63 ( V_12 ) )
V_98 |= V_99 ;
if ( F_64 ( V_12 ) )
V_98 |= V_100 ;
if ( V_9 -> V_3 & V_98 ) {
V_9 -> V_15 -> V_102 ( V_9 ) ;
V_98 &= ~ V_9 -> V_3 ;
}
if ( V_98 & V_100 )
F_22 ( V_9 , V_31 ) ;
if ( V_98 & V_99 )
F_61 ( V_12 , F_67 ( V_12 ) ) ;
F_4 ( V_9 ) ;
}
static int F_68 ( struct V_47 * V_9 , struct V_103 * V_104 )
{
struct V_5 * V_6 = F_69 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 ;
int V_87 = - V_105 ;
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
F_70 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_106;
V_104 -> type = V_2 -> type ;
V_104 -> line = V_2 -> line ;
V_104 -> V_9 = V_2 -> V_107 ;
if ( V_108 )
V_104 -> V_109 = ( long ) V_2 -> V_107 >> V_108 ;
V_104 -> V_110 = V_2 -> V_110 ;
V_104 -> V_14 = ( V_111 int ) V_2 -> V_14 ;
V_104 -> V_112 = V_2 -> V_57 ;
V_104 -> V_113 = V_2 -> V_75 / 16 ;
V_104 -> V_114 = F_71 ( V_9 -> V_114 ) / 10 ;
V_104 -> V_115 = V_9 -> V_115 == V_116 ?
V_116 :
F_71 ( V_9 -> V_115 ) / 10 ;
V_104 -> V_74 = V_2 -> V_74 ;
V_104 -> V_117 = V_2 -> V_117 ;
V_104 -> V_118 = V_2 -> V_119 ;
V_104 -> V_120 = V_2 -> V_121 ;
V_104 -> V_122 = ( void * ) ( unsigned long ) V_2 -> V_123 ;
V_87 = 0 ;
V_106:
F_72 ( & V_9 -> V_10 ) ;
return V_87 ;
}
static int F_73 ( struct V_47 * V_9 ,
struct V_103 T_3 * V_104 )
{
struct V_103 V_124 ;
if ( F_68 ( V_9 , & V_124 ) < 0 )
return - V_125 ;
if ( F_74 ( V_104 , & V_124 , sizeof( * V_104 ) ) )
return - V_126 ;
return 0 ;
}
static int F_75 ( struct V_11 * V_12 , struct V_47 * V_9 ,
struct V_5 * V_6 ,
struct V_103 * V_127 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned long V_128 ;
unsigned int V_129 , V_130 , V_115 ;
unsigned int V_131 , V_114 ;
T_1 V_132 , V_133 ;
int V_34 = 0 ;
if ( ! V_2 )
return - V_125 ;
V_128 = V_127 -> V_9 ;
if ( V_108 )
V_128 += ( unsigned long ) V_127 -> V_109 << V_108 ;
V_127 -> V_110 = F_76 ( V_127 -> V_110 ) ;
V_114 = F_77 ( V_127 -> V_114 * 10 ) ;
V_115 = V_127 -> V_115 == V_116 ?
V_116 :
F_77 ( V_127 -> V_115 * 10 ) ;
V_129 = ! ( V_2 -> V_14 & V_134 )
&& V_127 -> V_110 != V_2 -> V_110 ;
V_130 = ! ( V_2 -> V_14 & V_134 )
&& ( V_128 != V_2 -> V_107 ||
( unsigned long ) V_127 -> V_122 != V_2 -> V_123 ||
V_127 -> V_117 != V_2 -> V_117 ||
V_127 -> V_118 != V_2 -> V_119 ||
V_127 -> V_120 != V_2 -> V_121 ||
V_127 -> type != V_2 -> type ) ;
V_132 = V_2 -> V_14 ;
V_133 = ( V_111 T_1 ) V_127 -> V_14 ;
V_131 = V_2 -> V_74 ;
if ( ! F_31 ( V_46 ) ) {
V_34 = - V_135 ;
if ( V_129 || V_130 ||
( V_127 -> V_113 != V_2 -> V_75 / 16 ) ||
( V_114 != V_9 -> V_114 ) ||
( V_115 != V_9 -> V_115 ) ||
( V_127 -> V_112 &&
V_127 -> V_112 != V_2 -> V_57 ) ||
( ( ( V_133 ^ V_132 ) & ~ V_136 ) != 0 ) )
goto exit;
V_2 -> V_14 = ( ( V_2 -> V_14 & ~ V_136 ) |
( V_133 & V_136 ) ) ;
V_2 -> V_74 = V_127 -> V_74 ;
goto V_137;
}
if ( V_2 -> V_15 -> V_138 )
V_34 = V_2 -> V_15 -> V_138 ( V_2 , V_127 ) ;
if ( ( V_127 -> V_110 >= V_139 ) || ( V_127 -> V_110 < 0 ) ||
( V_127 -> V_113 < 9600 ) )
V_34 = - V_140 ;
if ( V_34 )
goto exit;
if ( V_130 || V_129 ) {
V_34 = - V_141 ;
if ( F_78 ( V_9 ) > 1 )
goto exit;
F_35 ( V_12 , V_6 ) ;
}
if ( V_130 ) {
unsigned long V_142 , V_143 ;
unsigned int V_144 , V_145 , V_146 , V_147 ;
V_142 = V_2 -> V_107 ;
V_143 = V_2 -> V_123 ;
V_144 = V_2 -> type ;
V_146 = V_2 -> V_117 ;
V_145 = V_2 -> V_119 ;
V_147 = V_2 -> V_121 ;
if ( V_144 != V_35 && V_2 -> V_15 -> V_148 )
V_2 -> V_15 -> V_148 ( V_2 ) ;
V_2 -> V_107 = V_128 ;
V_2 -> type = V_127 -> type ;
V_2 -> V_117 = V_127 -> V_117 ;
V_2 -> V_119 = V_127 -> V_118 ;
V_2 -> V_121 = V_127 -> V_120 ;
V_2 -> V_123 = ( unsigned long ) V_127 -> V_122 ;
if ( V_2 -> type != V_35 && V_2 -> V_15 -> V_149 ) {
V_34 = V_2 -> V_15 -> V_149 ( V_2 ) ;
} else {
V_34 = 0 ;
}
if ( V_34 ) {
V_2 -> V_107 = V_142 ;
V_2 -> type = V_144 ;
V_2 -> V_117 = V_146 ;
V_2 -> V_119 = V_145 ;
V_2 -> V_121 = V_147 ;
V_2 -> V_123 = V_143 ;
if ( V_144 != V_35 ) {
V_34 = V_2 -> V_15 -> V_149 ( V_2 ) ;
if ( V_34 )
V_2 -> type = V_35 ;
V_34 = - V_141 ;
}
goto exit;
}
}
if ( V_129 )
V_2 -> V_110 = V_127 -> V_110 ;
if ( ! ( V_2 -> V_14 & V_134 ) )
V_2 -> V_75 = V_127 -> V_113 * 16 ;
V_2 -> V_14 = ( V_2 -> V_14 & ~ V_150 ) |
( V_133 & V_150 ) ;
V_2 -> V_74 = V_127 -> V_74 ;
V_9 -> V_114 = V_114 ;
V_9 -> V_115 = V_115 ;
if ( V_127 -> V_112 )
V_2 -> V_57 = V_127 -> V_112 ;
V_9 -> V_151 = ( V_2 -> V_14 & V_152 ) ? 1 : 0 ;
V_137:
V_34 = 0 ;
if ( V_2 -> type == V_35 )
goto exit;
if ( F_33 ( V_9 ) ) {
if ( ( ( V_132 ^ V_2 -> V_14 ) & V_66 ) ||
V_131 != V_2 -> V_74 ) {
if ( V_2 -> V_14 & V_66 ) {
F_79 ( V_2 -> V_153 ,
L_2 ,
V_154 -> V_155 ,
F_80 ( V_9 -> V_12 ) ) ;
}
F_29 ( V_12 , V_6 , NULL ) ;
}
} else {
V_34 = F_32 ( V_12 , V_6 , 1 ) ;
if ( V_34 > 0 )
V_34 = 0 ;
}
exit:
return V_34 ;
}
static int F_81 ( struct V_11 * V_12 , struct V_5 * V_6 ,
struct V_103 T_3 * V_156 )
{
struct V_103 V_157 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
int V_34 ;
if ( F_82 ( & V_157 , V_156 , sizeof( V_157 ) ) )
return - V_126 ;
F_70 ( & V_9 -> V_10 ) ;
V_34 = F_75 ( V_12 , V_9 , V_6 , & V_157 ) ;
F_72 ( & V_9 -> V_10 ) ;
return V_34 ;
}
static int F_83 ( struct V_11 * V_12 ,
struct V_5 * V_6 , unsigned int T_3 * V_158 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned int V_159 ;
V_159 = V_2 -> V_15 -> V_160 ( V_2 ) ;
if ( V_2 -> V_97 ||
( ( F_58 ( & V_6 -> V_37 ) > 0 ) &&
! F_16 ( V_2 ) ) )
V_159 &= ~ V_161 ;
return F_84 ( V_159 , V_158 ) ;
}
static int F_85 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
int V_159 = - V_125 ;
F_70 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_106;
if ( ! F_86 ( V_12 ) ) {
V_159 = V_2 -> V_22 ;
F_48 ( & V_2 -> V_21 ) ;
V_159 |= V_2 -> V_15 -> V_82 ( V_2 ) ;
F_50 ( & V_2 -> V_21 ) ;
}
V_106:
F_72 ( & V_9 -> V_10 ) ;
return V_159 ;
}
static int
F_87 ( struct V_11 * V_12 , unsigned int V_18 , unsigned int V_19 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
int V_87 = - V_125 ;
F_70 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_106;
if ( ! F_86 ( V_12 ) ) {
F_18 ( V_2 , V_18 , V_19 ) ;
V_87 = 0 ;
}
V_106:
F_72 ( & V_9 -> V_10 ) ;
return V_87 ;
}
static int F_88 ( struct V_11 * V_12 , int V_162 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
int V_87 = - V_125 ;
F_70 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_106;
if ( V_2 -> type != V_35 )
V_2 -> V_15 -> V_163 ( V_2 , V_162 ) ;
V_87 = 0 ;
V_106:
F_72 ( & V_9 -> V_10 ) ;
return V_87 ;
}
static int F_89 ( struct V_11 * V_12 , struct V_5 * V_6 )
{
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
int V_14 , V_87 ;
if ( ! F_31 ( V_46 ) )
return - V_135 ;
if ( F_90 ( & V_9 -> V_10 ) )
return - V_164 ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 ) {
V_87 = - V_125 ;
goto V_106;
}
V_87 = - V_141 ;
if ( F_78 ( V_9 ) == 1 ) {
F_35 ( V_12 , V_6 ) ;
if ( V_2 -> type != V_35 && V_2 -> V_15 -> V_148 )
V_2 -> V_15 -> V_148 ( V_2 ) ;
V_14 = V_165 ;
if ( V_2 -> V_14 & V_166 )
V_14 |= V_167 ;
V_2 -> V_15 -> V_168 ( V_2 , V_14 ) ;
V_87 = F_32 ( V_12 , V_6 , 1 ) ;
if ( V_87 > 0 )
V_87 = 0 ;
}
V_106:
F_72 ( & V_9 -> V_10 ) ;
return V_87 ;
}
static void F_91 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 -> V_169 )
V_2 -> V_15 -> V_169 ( V_2 ) ;
}
static int F_92 ( struct V_5 * V_6 , unsigned long V_170 )
{
struct V_1 * V_2 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
F_93 ( V_171 , V_154 ) ;
struct V_172 V_173 , V_174 ;
int V_87 ;
V_2 = F_2 ( V_6 ) ;
if ( ! V_2 )
return - V_125 ;
F_48 ( & V_2 -> V_21 ) ;
memcpy ( & V_173 , & V_2 -> V_175 , sizeof( struct V_172 ) ) ;
F_91 ( V_2 ) ;
F_50 ( & V_2 -> V_21 ) ;
F_94 ( & V_9 -> V_176 , & V_171 ) ;
for (; ; ) {
F_48 ( & V_2 -> V_21 ) ;
memcpy ( & V_174 , & V_2 -> V_175 , sizeof( struct V_172 ) ) ;
F_50 ( & V_2 -> V_21 ) ;
F_95 ( V_177 ) ;
if ( ( ( V_170 & V_178 ) && ( V_174 . V_179 != V_173 . V_179 ) ) ||
( ( V_170 & V_180 ) && ( V_174 . V_181 != V_173 . V_181 ) ) ||
( ( V_170 & V_182 ) && ( V_174 . V_183 != V_173 . V_183 ) ) ||
( ( V_170 & V_83 ) && ( V_174 . V_184 != V_173 . V_184 ) ) ) {
V_87 = 0 ;
break;
}
F_96 () ;
if ( F_97 ( V_154 ) ) {
V_87 = - V_164 ;
break;
}
V_173 = V_174 ;
}
F_98 ( V_185 ) ;
F_99 ( & V_9 -> V_176 , & V_171 ) ;
F_4 ( V_2 ) ;
return V_87 ;
}
static int F_100 ( struct V_11 * V_12 ,
struct V_186 * V_175 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_172 V_174 ;
struct V_1 * V_2 ;
V_2 = F_2 ( V_6 ) ;
if ( ! V_2 )
return - V_125 ;
F_48 ( & V_2 -> V_21 ) ;
memcpy ( & V_174 , & V_2 -> V_175 , sizeof( struct V_172 ) ) ;
F_50 ( & V_2 -> V_21 ) ;
F_4 ( V_2 ) ;
V_175 -> V_184 = V_174 . V_184 ;
V_175 -> V_181 = V_174 . V_181 ;
V_175 -> V_179 = V_174 . V_179 ;
V_175 -> V_183 = V_174 . V_183 ;
V_175 -> V_187 = V_174 . V_187 ;
V_175 -> V_188 = V_174 . V_188 ;
V_175 -> V_189 = V_174 . V_189 ;
V_175 -> V_190 = V_174 . V_190 ;
V_175 -> V_191 = V_174 . V_191 ;
V_175 -> V_192 = V_174 . V_192 ;
V_175 -> V_193 = V_174 . V_193 ;
return 0 ;
}
static int F_101 ( struct V_1 * V_9 ,
struct V_194 T_3 * V_26 )
{
unsigned long V_14 ;
struct V_194 V_195 ;
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_195 = V_9 -> V_26 ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
if ( F_74 ( V_26 , & V_195 , sizeof( V_195 ) ) )
return - V_126 ;
return 0 ;
}
static int F_102 ( struct V_1 * V_9 ,
struct V_194 T_3 * V_196 )
{
struct V_194 V_26 ;
int V_87 ;
unsigned long V_14 ;
if ( ! V_9 -> V_25 )
return - V_197 ;
if ( F_82 ( & V_26 , V_196 , sizeof( * V_196 ) ) )
return - V_126 ;
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_87 = V_9 -> V_25 ( V_9 , & V_26 ) ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
if ( V_87 )
return V_87 ;
if ( F_74 ( V_196 , & V_9 -> V_26 , sizeof( V_9 -> V_26 ) ) )
return - V_126 ;
return 0 ;
}
static int
F_103 ( struct V_11 * V_12 , unsigned int V_198 , unsigned long V_170 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
void T_3 * V_199 = ( void T_3 * ) V_170 ;
int V_87 = - V_197 ;
switch ( V_198 ) {
case V_200 :
V_87 = F_73 ( V_9 , V_199 ) ;
break;
case V_201 :
F_104 ( & V_12 -> V_202 ) ;
V_87 = F_81 ( V_12 , V_6 , V_199 ) ;
F_105 ( & V_12 -> V_202 ) ;
break;
case V_203 :
F_104 ( & V_12 -> V_202 ) ;
V_87 = F_89 ( V_12 , V_6 ) ;
F_105 ( & V_12 -> V_202 ) ;
break;
case V_204 :
case V_205 :
V_87 = 0 ;
break;
}
if ( V_87 != - V_197 )
goto V_106;
if ( F_86 ( V_12 ) ) {
V_87 = - V_125 ;
goto V_106;
}
switch ( V_198 ) {
case V_206 :
V_87 = F_92 ( V_6 , V_170 ) ;
break;
}
if ( V_87 != - V_197 )
goto V_106;
F_70 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 || F_86 ( V_12 ) ) {
V_87 = - V_125 ;
goto V_207;
}
switch ( V_198 ) {
case V_208 :
V_87 = F_83 ( V_12 , V_6 , V_199 ) ;
break;
case V_209 :
V_87 = F_101 ( V_2 , V_199 ) ;
break;
case V_210 :
V_87 = F_102 ( V_2 , V_199 ) ;
break;
default:
if ( V_2 -> V_15 -> V_211 )
V_87 = V_2 -> V_15 -> V_211 ( V_2 , V_198 , V_170 ) ;
break;
}
V_207:
F_72 ( & V_9 -> V_10 ) ;
V_106:
return V_87 ;
}
static void F_106 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_2 ;
F_70 ( & V_6 -> V_9 . V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( V_2 && V_2 -> V_15 -> V_212 )
V_2 -> V_15 -> V_212 ( V_2 , & V_12 -> V_44 ) ;
F_72 ( & V_6 -> V_9 . V_10 ) ;
}
static void F_107 ( struct V_11 * V_12 ,
struct V_60 * V_76 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_2 ;
unsigned int V_43 = V_12 -> V_44 . V_45 ;
unsigned int V_213 = V_214 | V_215 | V_216 | V_217 | V_218 ;
bool V_219 = false ;
F_70 ( & V_6 -> V_9 . V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_106;
if ( V_2 -> V_14 & V_220 ) {
V_213 |= V_221 | V_222 | V_223 ;
V_219 =
V_12 -> V_44 . V_224 [ V_225 ] != V_76 -> V_224 [ V_225 ] ||
V_12 -> V_44 . V_224 [ V_226 ] != V_76 -> V_224 [ V_226 ] ;
}
if ( ( V_43 ^ V_76 -> V_45 ) == 0 &&
V_12 -> V_44 . V_227 == V_76 -> V_227 &&
V_12 -> V_44 . V_228 == V_76 -> V_228 &&
( ( V_12 -> V_44 . V_229 ^ V_76 -> V_229 ) & V_213 ) == 0 &&
! V_219 ) {
goto V_106;
}
F_29 ( V_12 , V_6 , V_76 ) ;
V_43 = V_12 -> V_44 . V_45 ;
if ( ( V_76 -> V_45 & V_71 ) && ! ( V_43 & V_71 ) )
F_23 ( V_2 , V_31 | V_30 ) ;
else if ( ! ( V_76 -> V_45 & V_71 ) && ( V_43 & V_71 ) ) {
unsigned int V_98 = V_30 ;
if ( ! ( V_43 & V_79 ) || ! F_108 ( V_12 ) )
V_98 |= V_31 ;
F_22 ( V_2 , V_98 ) ;
}
V_106:
F_72 ( & V_6 -> V_9 . V_10 ) ;
}
static void F_109 ( struct V_11 * V_12 , struct V_230 * V_231 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_47 * V_9 ;
if ( ! V_6 ) {
struct V_232 * V_233 = V_12 -> V_234 -> V_235 ;
V_6 = V_233 -> V_6 + V_12 -> V_93 ;
V_9 = & V_6 -> V_9 ;
F_48 ( & V_9 -> V_21 ) ;
-- V_9 -> V_90 ;
F_50 ( & V_9 -> V_21 ) ;
return;
}
V_9 = & V_6 -> V_9 ;
F_60 ( L_3 , V_12 -> V_93 ) ;
F_110 ( V_12 -> V_9 , V_12 , V_231 ) ;
}
static void F_111 ( struct V_47 * V_9 )
{
struct V_5 * V_6 = F_69 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 = F_7 ( V_6 ) ;
if ( F_112 ( ! V_2 , L_4 ) )
return;
F_48 ( & V_2 -> V_21 ) ;
V_2 -> V_15 -> V_236 ( V_2 ) ;
F_50 ( & V_2 -> V_21 ) ;
F_38 ( V_9 ) ;
F_39 ( V_9 , 0 ) ;
F_25 ( V_6 , V_237 ) ;
}
static void F_113 ( struct V_11 * V_12 , int V_58 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_1 * V_9 ;
unsigned long V_238 , V_239 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( V_9 -> type == V_35 || V_9 -> V_57 == 0 ) {
F_4 ( V_9 ) ;
return;
}
V_238 = ( V_9 -> V_58 - V_59 / 50 ) / V_9 -> V_57 ;
V_238 = V_238 / 5 ;
if ( V_238 == 0 )
V_238 = 1 ;
if ( V_58 && V_58 < V_238 )
V_238 = V_58 ;
if ( V_58 == 0 || V_58 > 2 * V_9 -> V_58 )
V_58 = 2 * V_9 -> V_58 ;
V_239 = V_240 + V_58 ;
F_60 ( L_5 ,
V_9 -> line , V_240 , V_239 ) ;
while ( ! V_9 -> V_15 -> V_160 ( V_9 ) ) {
F_114 ( F_71 ( V_238 ) ) ;
if ( F_97 ( V_154 ) )
break;
if ( F_115 ( V_240 , V_239 ) )
break;
}
F_4 ( V_9 ) ;
}
static void F_116 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = V_12 -> V_13 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_2 ;
unsigned long V_14 ;
F_60 ( L_6 , V_12 -> V_93 ) ;
F_70 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
F_112 ( ! V_2 , L_7 ) ;
if ( F_117 ( V_9 ) ) {
F_59 ( V_12 ) ;
F_35 ( V_12 , V_6 ) ;
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_9 -> V_90 = 0 ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
F_118 ( V_9 , 0 ) ;
F_119 ( V_9 , NULL ) ;
if ( V_2 && ! F_28 ( V_2 ) )
F_25 ( V_6 , V_237 ) ;
F_120 ( & V_9 -> V_241 ) ;
F_120 ( & V_9 -> V_176 ) ;
}
F_72 ( & V_9 -> V_10 ) ;
}
static void F_38 ( struct V_47 * V_9 )
{
struct V_5 * V_6 = F_69 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 = F_7 ( V_6 ) ;
F_120 ( & V_9 -> V_176 ) ;
if ( V_2 )
V_2 -> V_15 -> V_242 ( V_2 ) ;
if ( V_2 )
F_121 ( V_2 -> V_110 ) ;
}
static int F_122 ( struct V_47 * V_9 )
{
struct V_5 * V_6 = F_69 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 ;
int V_22 ;
V_2 = F_2 ( V_6 ) ;
if ( F_45 ( ! V_2 ) )
return 1 ;
F_48 ( & V_2 -> V_21 ) ;
F_91 ( V_2 ) ;
V_22 = V_2 -> V_15 -> V_82 ( V_2 ) ;
F_50 ( & V_2 -> V_21 ) ;
F_4 ( V_2 ) ;
if ( V_22 & V_243 )
return 1 ;
return 0 ;
}
static void F_123 ( struct V_47 * V_9 , int raise )
{
struct V_5 * V_6 = F_69 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_2 ( V_6 ) ;
if ( ! V_2 )
return;
F_21 ( V_2 , raise ) ;
F_4 ( V_2 ) ;
}
static int F_124 ( struct V_11 * V_12 , struct V_230 * V_231 )
{
struct V_232 * V_233 = V_12 -> V_234 -> V_235 ;
int V_34 , line = V_12 -> V_93 ;
struct V_5 * V_6 = V_233 -> V_6 + line ;
V_12 -> V_13 = V_6 ;
V_34 = F_125 ( & V_6 -> V_9 , V_12 , V_231 ) ;
if ( V_34 > 0 )
V_34 = 0 ;
return V_34 ;
}
static int F_126 ( struct V_47 * V_9 , struct V_11 * V_12 )
{
struct V_5 * V_6 = F_69 ( V_9 , struct V_5 , V_9 ) ;
struct V_1 * V_2 ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 || V_2 -> V_14 & V_244 )
return - V_245 ;
V_9 -> V_151 = ( V_2 -> V_14 & V_152 ) ? 1 : 0 ;
return F_32 ( V_12 , V_6 , 0 ) ;
}
static const char * F_127 ( struct V_1 * V_9 )
{
const char * V_246 = NULL ;
if ( V_9 -> V_15 -> type )
V_246 = V_9 -> V_15 -> type ( V_9 ) ;
if ( ! V_246 )
V_246 = L_8 ;
return V_246 ;
}
static void F_128 ( struct V_247 * V_248 , struct V_232 * V_233 , int V_249 )
{
struct V_5 * V_6 = V_233 -> V_6 + V_249 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
enum V_250 V_251 ;
struct V_1 * V_2 ;
char V_252 [ 32 ] ;
unsigned int V_3 ;
int V_253 ;
F_70 ( & V_9 -> V_10 ) ;
V_2 = F_7 ( V_6 ) ;
if ( ! V_2 )
goto V_106;
V_253 = V_2 -> V_119 >= V_254 ;
F_129 ( V_248 , L_9 ,
V_2 -> line , F_127 ( V_2 ) ,
V_253 ? L_10 : L_11 ,
V_253 ? ( unsigned long long ) V_2 -> V_123
: ( unsigned long long ) V_2 -> V_107 ,
V_2 -> V_110 ) ;
if ( V_2 -> type == V_35 ) {
F_130 ( V_248 , '\n' ) ;
goto V_106;
}
if ( F_31 ( V_46 ) ) {
V_251 = V_6 -> V_251 ;
if ( V_251 != V_36 )
F_25 ( V_6 , V_36 ) ;
F_48 ( & V_2 -> V_21 ) ;
V_3 = V_2 -> V_15 -> V_82 ( V_2 ) ;
F_50 ( & V_2 -> V_21 ) ;
if ( V_251 != V_36 )
F_25 ( V_6 , V_251 ) ;
F_129 ( V_248 , L_12 ,
V_2 -> V_175 . V_188 , V_2 -> V_175 . V_187 ) ;
if ( V_2 -> V_175 . V_189 )
F_129 ( V_248 , L_13 , V_2 -> V_175 . V_189 ) ;
if ( V_2 -> V_175 . V_191 )
F_129 ( V_248 , L_14 , V_2 -> V_175 . V_191 ) ;
if ( V_2 -> V_175 . V_192 )
F_129 ( V_248 , L_15 , V_2 -> V_175 . V_192 ) ;
if ( V_2 -> V_175 . V_190 )
F_129 ( V_248 , L_16 , V_2 -> V_175 . V_190 ) ;
#define F_131 ( T_4 , V_246 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_132 ( T_4 , V_246 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_252 [ 0 ] = '\0' ;
V_252 [ 1 ] = '\0' ;
F_131 ( V_31 , L_17 ) ;
F_132 ( V_83 , L_18 ) ;
F_131 ( V_30 , L_19 ) ;
F_132 ( V_180 , L_20 ) ;
F_132 ( V_243 , L_21 ) ;
F_132 ( V_178 , L_22 ) ;
if ( V_252 [ 0 ] )
V_252 [ 0 ] = ' ' ;
F_133 ( V_248 , V_252 ) ;
}
F_130 ( V_248 , '\n' ) ;
#undef F_132
#undef F_131
V_106:
F_72 ( & V_9 -> V_10 ) ;
}
static int F_134 ( struct V_247 * V_248 , void * V_255 )
{
struct V_256 * V_257 = V_248 -> V_258 ;
struct V_232 * V_233 = V_257 -> V_235 ;
int V_249 ;
F_129 ( V_248 , L_23 , L_24 , L_24 , L_24 ) ;
for ( V_249 = 0 ; V_249 < V_233 -> V_259 ; V_249 ++ )
F_128 ( V_248 , V_233 , V_249 ) ;
return 0 ;
}
static int F_135 ( struct V_260 * V_260 , struct V_230 * V_230 )
{
return F_136 ( V_230 , F_134 , F_137 ( V_260 ) ) ;
}
void F_138 ( struct V_1 * V_9 , const char * V_261 ,
unsigned int V_90 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_249 ;
for ( V_249 = 0 ; V_249 < V_90 ; V_249 ++ , V_261 ++ ) {
if ( * V_261 == '\n' )
putchar ( V_9 , '\r' ) ;
putchar ( V_9 , * V_261 ) ;
}
}
struct V_1 * T_5
F_139 ( struct V_1 * V_262 , int V_259 , struct V_263 * V_264 )
{
int V_265 = V_264 -> V_93 ;
if ( V_265 < 0 || V_265 >= V_259 || ( V_262 [ V_265 ] . V_107 == 0 &&
V_262 [ V_265 ] . V_266 == NULL ) )
for ( V_265 = 0 ; V_265 < V_259 ; V_265 ++ )
if ( V_262 [ V_265 ] . V_107 != 0 ||
V_262 [ V_265 ] . V_266 != NULL )
break;
V_264 -> V_93 = V_265 ;
return V_262 + V_265 ;
}
int F_140 ( char * V_267 , unsigned char * V_119 , T_6 * V_268 ,
char * * V_269 )
{
if ( strncmp ( V_267 , L_25 , 5 ) == 0 ) {
* V_119 = V_254 ;
V_267 += 5 ;
} else if ( strncmp ( V_267 , L_26 , 7 ) == 0 ) {
* V_119 = V_270 ;
V_267 += 7 ;
} else if ( strncmp ( V_267 , L_27 , 7 ) == 0 ) {
* V_119 = V_271 ;
V_267 += 7 ;
} else if ( strncmp ( V_267 , L_28 , 9 ) == 0 ) {
* V_119 = V_272 ;
V_267 += 9 ;
} else if ( strncmp ( V_267 , L_29 , 13 ) == 0 ) {
* V_119 = F_141 ( V_273 ) ?
V_272 : V_271 ;
V_267 += 13 ;
} else if ( strncmp ( V_267 , L_30 , 3 ) == 0 ) {
* V_119 = V_274 ;
V_267 += 3 ;
} else if ( strncmp ( V_267 , L_31 , 2 ) == 0 ) {
* V_119 = V_254 ;
} else {
return - V_140 ;
}
* V_268 = F_142 ( V_267 , NULL , 0 ) ;
V_267 = strchr ( V_267 , ',' ) ;
if ( V_267 )
V_267 ++ ;
* V_269 = V_267 ;
return 0 ;
}
void
F_143 ( char * V_269 , int * V_49 , int * V_191 , int * V_50 , int * V_275 )
{
char * V_261 = V_269 ;
* V_49 = F_144 ( V_261 , NULL , 10 ) ;
while ( * V_261 >= '0' && * V_261 <= '9' )
V_261 ++ ;
if ( * V_261 )
* V_191 = * V_261 ++ ;
if ( * V_261 )
* V_50 = * V_261 ++ - '0' ;
if ( * V_261 )
* V_275 = * V_261 ;
}
int
F_145 ( struct V_1 * V_9 , struct V_263 * V_264 ,
int V_49 , int V_191 , int V_50 , int V_275 )
{
struct V_60 V_44 ;
static struct V_60 V_276 ;
if ( ! ( F_28 ( V_9 ) && ( V_9 -> V_42 -> V_14 & V_277 ) ) ) {
F_146 ( & V_9 -> V_21 ) ;
F_147 ( & V_9 -> V_21 , & V_278 ) ;
}
memset ( & V_44 , 0 , sizeof( struct V_60 ) ) ;
V_44 . V_45 |= V_279 | V_280 | V_81 ;
F_44 ( & V_44 , V_49 , V_49 ) ;
if ( V_50 == 7 )
V_44 . V_45 |= V_54 ;
else
V_44 . V_45 |= V_281 ;
switch ( V_191 ) {
case 'o' : case 'O' :
V_44 . V_45 |= V_282 ;
case 'e' : case 'E' :
V_44 . V_45 |= V_56 ;
break;
}
if ( V_275 == 'r' )
V_44 . V_45 |= V_79 ;
V_9 -> V_22 |= V_30 ;
V_9 -> V_15 -> V_78 ( V_9 , & V_44 , & V_276 ) ;
if ( V_264 )
V_264 -> V_43 = V_44 . V_45 ;
return 0 ;
}
static void F_25 ( struct V_5 * V_6 ,
enum V_250 V_251 )
{
struct V_1 * V_9 = F_7 ( V_6 ) ;
if ( V_6 -> V_251 != V_251 ) {
if ( V_9 && V_9 -> V_15 -> V_283 )
V_9 -> V_15 -> V_283 ( V_9 , V_251 , V_6 -> V_251 ) ;
V_6 -> V_251 = V_251 ;
}
}
static int F_148 ( struct V_284 * V_153 , void * V_285 )
{
struct V_286 * V_287 = V_285 ;
struct V_256 * V_288 = V_287 -> V_234 -> V_256 ;
T_7 V_289 = F_149 ( V_288 -> V_290 , V_288 -> V_291 ) +
V_287 -> V_9 -> line ;
return V_153 -> V_289 == V_289 ;
}
int F_150 ( struct V_232 * V_233 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_233 -> V_6 + V_2 -> line ;
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_284 * V_292 ;
struct V_286 V_287 = { V_2 , V_233 } ;
F_70 ( & V_9 -> V_10 ) ;
V_292 = F_151 ( V_2 -> V_153 , & V_287 , F_148 ) ;
if ( V_292 && F_152 ( V_292 ) ) {
F_153 ( V_2 -> V_110 ) ;
F_154 ( V_292 ) ;
F_72 ( & V_9 -> V_10 ) ;
return 0 ;
}
F_154 ( V_292 ) ;
if ( ! V_293 && F_28 ( V_2 ) )
goto V_294;
V_2 -> V_295 = 1 ;
if ( F_33 ( V_9 ) ) {
const struct V_296 * V_15 = V_2 -> V_15 ;
int V_297 ;
F_39 ( V_9 , 1 ) ;
F_36 ( V_9 , 0 ) ;
F_48 ( & V_2 -> V_21 ) ;
V_15 -> V_16 ( V_2 ) ;
V_15 -> V_23 ( V_2 , 0 ) ;
V_15 -> V_236 ( V_2 ) ;
F_50 ( & V_2 -> V_21 ) ;
for ( V_297 = 3 ; ! V_15 -> V_160 ( V_2 ) && V_297 ; V_297 -- )
F_155 ( 10 ) ;
if ( ! V_297 )
F_156 ( V_2 -> V_153 , L_32 ,
V_2 -> V_298 ) ;
V_15 -> V_242 ( V_2 ) ;
}
if ( F_28 ( V_2 ) )
F_157 ( V_2 -> V_42 ) ;
F_25 ( V_6 , V_237 ) ;
V_294:
F_72 ( & V_9 -> V_10 ) ;
return 0 ;
}
int F_158 ( struct V_232 * V_233 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_233 -> V_6 + V_2 -> line ;
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_284 * V_292 ;
struct V_286 V_287 = { V_2 , V_233 } ;
struct V_60 V_44 ;
F_70 ( & V_9 -> V_10 ) ;
V_292 = F_151 ( V_2 -> V_153 , & V_287 , F_148 ) ;
if ( ! V_2 -> V_295 && F_152 ( V_292 ) ) {
if ( F_159 ( F_160 ( ( V_2 -> V_110 ) ) ) )
F_161 ( V_2 -> V_110 ) ;
F_154 ( V_292 ) ;
F_72 ( & V_9 -> V_10 ) ;
return 0 ;
}
F_154 ( V_292 ) ;
V_2 -> V_295 = 0 ;
if ( F_28 ( V_2 ) ) {
memset ( & V_44 , 0 , sizeof( struct V_60 ) ) ;
V_44 . V_45 = V_2 -> V_42 -> V_43 ;
if ( V_9 -> V_12 && V_44 . V_45 == 0 )
V_44 = V_9 -> V_12 -> V_44 ;
if ( V_293 )
F_25 ( V_6 , V_36 ) ;
V_2 -> V_15 -> V_78 ( V_2 , & V_44 , NULL ) ;
if ( V_293 )
F_162 ( V_2 -> V_42 ) ;
}
if ( F_163 ( V_9 ) ) {
const struct V_296 * V_15 = V_2 -> V_15 ;
int V_87 ;
F_25 ( V_6 , V_36 ) ;
F_48 ( & V_2 -> V_21 ) ;
V_15 -> V_23 ( V_2 , 0 ) ;
F_50 ( & V_2 -> V_21 ) ;
if ( V_293 || ! F_28 ( V_2 ) ) {
struct V_11 * V_12 = V_9 -> V_12 ;
V_87 = V_15 -> V_41 ( V_2 ) ;
if ( V_87 == 0 ) {
if ( V_12 )
F_29 ( V_12 , V_6 , NULL ) ;
F_48 ( & V_2 -> V_21 ) ;
V_15 -> V_23 ( V_2 , V_2 -> V_22 ) ;
V_15 -> V_17 ( V_2 ) ;
F_50 ( & V_2 -> V_21 ) ;
F_36 ( V_9 , 1 ) ;
} else {
F_35 ( V_12 , V_6 ) ;
}
}
F_39 ( V_9 , 0 ) ;
}
F_72 ( & V_9 -> V_10 ) ;
return 0 ;
}
static inline void
F_164 ( struct V_232 * V_233 , struct V_1 * V_9 )
{
char V_299 [ 64 ] ;
switch ( V_9 -> V_119 ) {
case V_274 :
snprintf ( V_299 , sizeof( V_299 ) , L_33 , V_9 -> V_107 ) ;
break;
case V_300 :
snprintf ( V_299 , sizeof( V_299 ) ,
L_34 , V_9 -> V_107 , V_9 -> V_117 ) ;
break;
case V_254 :
case V_270 :
case V_271 :
case V_272 :
case V_301 :
case V_302 :
snprintf ( V_299 , sizeof( V_299 ) ,
L_35 , ( unsigned long long ) V_9 -> V_123 ) ;
break;
default:
F_165 ( V_299 , L_36 , sizeof( V_299 ) ) ;
break;
}
F_166 ( L_37 ,
V_9 -> V_153 ? F_167 ( V_9 -> V_153 ) : L_24 ,
V_9 -> V_153 ? L_38 : L_24 ,
V_9 -> V_298 ,
V_299 , V_9 -> V_110 , V_9 -> V_75 / 16 , F_127 ( V_9 ) ) ;
}
static void
F_168 ( struct V_232 * V_233 , struct V_5 * V_6 ,
struct V_1 * V_9 )
{
unsigned int V_14 ;
if ( ! V_9 -> V_107 && ! V_9 -> V_123 && ! V_9 -> V_266 )
return;
V_14 = 0 ;
if ( V_9 -> V_14 & V_166 )
V_14 |= V_167 ;
if ( V_9 -> V_14 & V_303 ) {
if ( ! ( V_9 -> V_14 & V_304 ) ) {
V_9 -> type = V_35 ;
V_14 |= V_165 ;
}
V_9 -> V_15 -> V_168 ( V_9 , V_14 ) ;
}
if ( V_9 -> type != V_35 ) {
unsigned long V_14 ;
F_164 ( V_233 , V_9 ) ;
F_25 ( V_6 , V_36 ) ;
F_19 ( & V_9 -> V_21 , V_14 ) ;
V_9 -> V_15 -> V_23 ( V_9 , V_9 -> V_22 & V_30 ) ;
F_20 ( & V_9 -> V_21 , V_14 ) ;
if ( V_9 -> V_42 && ! ( V_9 -> V_42 -> V_14 & V_277 ) )
F_169 ( V_9 -> V_42 ) ;
if ( ! F_28 ( V_9 ) )
F_25 ( V_6 , V_237 ) ;
}
}
static int F_170 ( struct V_256 * V_234 , int line , char * V_269 )
{
struct V_232 * V_233 = V_234 -> V_235 ;
struct V_5 * V_6 = V_233 -> V_6 + line ;
struct V_47 * V_305 ;
struct V_1 * V_9 ;
int V_49 = 9600 ;
int V_50 = 8 ;
int V_191 = 'n' ;
int V_275 = 'n' ;
int V_87 = 0 ;
V_305 = & V_6 -> V_9 ;
F_70 ( & V_305 -> V_10 ) ;
V_9 = F_7 ( V_6 ) ;
if ( ! V_9 || ! ( V_9 -> V_15 -> V_306 && V_9 -> V_15 -> V_307 ) ) {
V_87 = - 1 ;
goto V_106;
}
if ( V_9 -> V_15 -> V_308 ) {
if ( ! F_33 ( V_305 ) )
V_87 = V_9 -> V_15 -> V_308 ( V_9 ) ;
}
if ( ! V_87 && V_269 ) {
F_143 ( V_269 , & V_49 , & V_191 , & V_50 , & V_275 ) ;
V_87 = F_145 ( V_9 , NULL , V_49 , V_191 , V_50 , V_275 ) ;
}
V_106:
F_72 ( & V_305 -> V_10 ) ;
return V_87 ;
}
static int F_171 ( struct V_256 * V_234 , int line )
{
struct V_232 * V_233 = V_234 -> V_235 ;
struct V_5 * V_6 = V_233 -> V_6 + line ;
struct V_1 * V_9 ;
int V_87 = - 1 ;
V_9 = F_2 ( V_6 ) ;
if ( V_9 ) {
V_87 = V_9 -> V_15 -> V_306 ( V_9 ) ;
F_4 ( V_9 ) ;
}
return V_87 ;
}
static void F_172 ( struct V_256 * V_234 , int line , char V_95 )
{
struct V_232 * V_233 = V_234 -> V_235 ;
struct V_5 * V_6 = V_233 -> V_6 + line ;
struct V_1 * V_9 ;
V_9 = F_2 ( V_6 ) ;
if ( ! V_9 )
return;
if ( V_95 == '\n' )
V_9 -> V_15 -> V_307 ( V_9 , '\r' ) ;
V_9 -> V_15 -> V_307 ( V_9 , V_95 ) ;
F_4 ( V_9 ) ;
}
int F_173 ( struct V_232 * V_233 )
{
struct V_256 * V_309 ;
int V_249 , V_34 ;
F_10 ( V_233 -> V_6 ) ;
V_233 -> V_6 = F_174 ( sizeof( struct V_5 ) * V_233 -> V_259 , V_39 ) ;
if ( ! V_233 -> V_6 )
goto V_106;
V_309 = F_175 ( V_233 -> V_259 ) ;
if ( ! V_309 )
goto V_310;
V_233 -> V_256 = V_309 ;
V_309 -> V_311 = V_233 -> V_311 ;
V_309 -> V_298 = V_233 -> F_167 ;
V_309 -> V_290 = V_233 -> V_290 ;
V_309 -> V_291 = V_233 -> V_312 ;
V_309 -> type = V_313 ;
V_309 -> V_314 = V_315 ;
V_309 -> V_316 = V_317 ;
V_309 -> V_316 . V_45 = V_318 | V_281 | V_279 | V_280 | V_81 ;
V_309 -> V_316 . V_228 = V_309 -> V_316 . V_227 = 9600 ;
V_309 -> V_14 = V_319 | V_320 ;
V_309 -> V_235 = V_233 ;
F_176 ( V_309 , & V_296 ) ;
for ( V_249 = 0 ; V_249 < V_233 -> V_259 ; V_249 ++ ) {
struct V_5 * V_6 = V_233 -> V_6 + V_249 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
F_177 ( V_9 ) ;
V_9 -> V_15 = & V_321 ;
}
V_34 = F_178 ( V_309 ) ;
if ( V_34 >= 0 )
return V_34 ;
for ( V_249 = 0 ; V_249 < V_233 -> V_259 ; V_249 ++ )
F_179 ( & V_233 -> V_6 [ V_249 ] . V_9 ) ;
F_180 ( V_309 ) ;
V_310:
F_181 ( V_233 -> V_6 ) ;
V_106:
return - V_40 ;
}
void F_182 ( struct V_232 * V_233 )
{
struct V_256 * V_267 = V_233 -> V_256 ;
unsigned int V_249 ;
F_183 ( V_267 ) ;
F_180 ( V_267 ) ;
for ( V_249 = 0 ; V_249 < V_233 -> V_259 ; V_249 ++ )
F_179 ( & V_233 -> V_6 [ V_249 ] . V_9 ) ;
F_181 ( V_233 -> V_6 ) ;
V_233 -> V_6 = NULL ;
V_233 -> V_256 = NULL ;
}
struct V_256 * F_184 ( struct V_263 * V_264 , int * V_93 )
{
struct V_232 * V_267 = V_264 -> V_285 ;
* V_93 = V_264 -> V_93 ;
return V_267 -> V_256 ;
}
static T_8 F_185 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . V_113 * 16 ) ;
}
static T_8 F_187 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . type ) ;
}
static T_8 F_188 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . line ) ;
}
static T_8 F_189 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
unsigned long V_325 ;
F_68 ( V_9 , & V_124 ) ;
V_325 = V_124 . V_9 ;
if ( V_108 )
V_325 |= ( unsigned long ) V_124 . V_109 << V_108 ;
return snprintf ( V_38 , V_324 , L_40 , V_325 ) ;
}
static T_8 F_190 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . V_110 ) ;
}
static T_8 F_191 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_41 , V_124 . V_14 ) ;
}
static T_8 F_192 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . V_112 ) ;
}
static T_8 F_193 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . V_114 ) ;
}
static T_8 F_194 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . V_115 ) ;
}
static T_8 F_195 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . V_74 ) ;
}
static T_8 F_196 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . V_118 ) ;
}
static T_8 F_197 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_40 , ( unsigned long ) V_124 . V_122 ) ;
}
static T_8 F_198 ( struct V_284 * V_153 ,
struct V_322 * V_323 , char * V_38 )
{
struct V_103 V_124 ;
struct V_47 * V_9 = F_186 ( V_153 ) ;
F_68 ( V_9 , & V_124 ) ;
return snprintf ( V_38 , V_324 , L_39 , V_124 . V_120 ) ;
}
int F_199 ( struct V_232 * V_233 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_47 * V_9 ;
int V_87 = 0 ;
struct V_284 * V_292 ;
int V_326 ;
F_10 ( F_200 () ) ;
if ( V_2 -> line >= V_233 -> V_259 )
return - V_140 ;
V_6 = V_233 -> V_6 + V_2 -> line ;
V_9 = & V_6 -> V_9 ;
F_70 ( & V_327 ) ;
F_70 ( & V_9 -> V_10 ) ;
if ( V_6 -> V_1 ) {
V_87 = - V_140 ;
goto V_106;
}
F_201 ( & V_6 -> V_7 , 1 ) ;
F_202 ( & V_6 -> V_8 ) ;
V_6 -> V_1 = V_2 ;
V_2 -> V_6 = V_6 ;
V_6 -> V_251 = V_328 ;
V_2 -> V_42 = V_233 -> V_42 ;
V_2 -> V_312 = V_233 -> V_256 -> V_291 + V_2 -> line ;
V_2 -> V_298 = F_203 ( V_39 , L_42 , V_233 -> F_167 ,
V_233 -> V_256 -> V_329 + V_2 -> line ) ;
if ( ! V_2 -> V_298 ) {
V_87 = - V_40 ;
goto V_106;
}
if ( ! ( F_28 ( V_2 ) && ( V_2 -> V_42 -> V_14 & V_277 ) ) ) {
F_146 ( & V_2 -> V_21 ) ;
F_147 ( & V_2 -> V_21 , & V_278 ) ;
}
if ( V_2 -> V_42 && V_2 -> V_153 )
F_204 ( V_2 -> V_153 -> V_330 , V_2 -> V_42 -> V_298 , V_2 -> line ) ;
F_168 ( V_233 , V_6 , V_2 ) ;
V_9 -> V_263 = F_28 ( V_2 ) ;
V_326 = 2 ;
if ( V_2 -> V_331 )
V_326 ++ ;
V_2 -> V_332 = F_205 ( V_326 , sizeof( * V_2 -> V_332 ) ,
V_39 ) ;
if ( ! V_2 -> V_332 ) {
V_87 = - V_40 ;
goto V_106;
}
V_2 -> V_332 [ 0 ] = & V_333 ;
if ( V_2 -> V_331 )
V_2 -> V_332 [ 1 ] = V_2 -> V_331 ;
V_292 = F_206 ( V_9 , V_233 -> V_256 ,
V_2 -> line , V_2 -> V_153 , V_9 , V_2 -> V_332 ) ;
if ( F_207 ( ! F_208 ( V_292 ) ) ) {
F_209 ( V_292 , 1 ) ;
} else {
F_156 ( V_2 -> V_153 , L_43 ,
V_2 -> line ) ;
}
V_2 -> V_14 &= ~ V_244 ;
V_106:
F_72 ( & V_9 -> V_10 ) ;
F_72 ( & V_327 ) ;
return V_87 ;
}
int F_210 ( struct V_232 * V_233 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_233 -> V_6 + V_2 -> line ;
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_1 * V_1 ;
struct V_11 * V_12 ;
int V_87 = 0 ;
F_10 ( F_200 () ) ;
F_70 ( & V_327 ) ;
F_70 ( & V_9 -> V_10 ) ;
V_1 = F_7 ( V_6 ) ;
if ( V_1 != V_2 )
F_211 ( V_2 -> V_153 , L_44 ,
V_1 , V_2 ) ;
if ( ! V_1 ) {
F_72 ( & V_9 -> V_10 ) ;
V_87 = - V_140 ;
goto V_106;
}
V_2 -> V_14 |= V_244 ;
F_72 ( & V_9 -> V_10 ) ;
F_212 ( V_9 , V_233 -> V_256 , V_2 -> line ) ;
V_12 = F_213 ( V_9 ) ;
if ( V_12 ) {
F_214 ( V_9 -> V_12 ) ;
F_215 ( V_12 ) ;
}
if ( F_28 ( V_2 ) )
F_216 ( V_2 -> V_42 ) ;
if ( V_2 -> type != V_35 && V_2 -> V_15 -> V_148 )
V_2 -> V_15 -> V_148 ( V_2 ) ;
F_181 ( V_2 -> V_332 ) ;
F_181 ( V_2 -> V_298 ) ;
V_2 -> type = V_35 ;
F_70 ( & V_9 -> V_10 ) ;
F_45 ( F_217 ( & V_6 -> V_7 ) < 0 ) ;
F_218 ( V_6 -> V_8 , ! F_219 ( & V_6 -> V_7 ) ) ;
V_6 -> V_1 = NULL ;
F_72 ( & V_9 -> V_10 ) ;
V_106:
F_72 ( & V_327 ) ;
return V_87 ;
}
int F_220 ( struct V_1 * V_334 , struct V_1 * V_335 )
{
if ( V_334 -> V_119 != V_335 -> V_119 )
return 0 ;
switch ( V_334 -> V_119 ) {
case V_274 :
return ( V_334 -> V_107 == V_335 -> V_107 ) ;
case V_300 :
return ( V_334 -> V_107 == V_335 -> V_107 ) &&
( V_334 -> V_117 == V_335 -> V_117 ) ;
case V_254 :
case V_270 :
case V_271 :
case V_272 :
case V_301 :
case V_302 :
return ( V_334 -> V_123 == V_335 -> V_123 ) ;
}
return 0 ;
}
void F_221 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_47 * V_9 = & V_2 -> V_6 -> V_9 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_336 * V_337 ;
F_222 ( & V_2 -> V_21 ) ;
if ( V_12 ) {
V_337 = F_223 ( V_12 ) ;
if ( V_337 ) {
if ( V_337 -> V_15 -> V_338 )
V_337 -> V_15 -> V_338 ( V_12 , V_3 ) ;
F_224 ( V_337 ) ;
}
}
V_2 -> V_175 . V_183 ++ ;
if ( F_1 ( V_2 ) ) {
if ( V_3 )
F_120 ( & V_9 -> V_241 ) ;
else if ( V_12 )
F_225 ( V_12 ) ;
}
}
void F_226 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_222 ( & V_2 -> V_21 ) ;
V_2 -> V_175 . V_184 ++ ;
if ( F_49 ( V_2 ) ) {
if ( V_2 -> V_77 ) {
if ( V_3 ) {
V_2 -> V_77 = 0 ;
V_2 -> V_15 -> V_17 ( V_2 ) ;
F_9 ( V_2 ) ;
}
} else {
if ( ! V_3 ) {
V_2 -> V_77 = 1 ;
V_2 -> V_15 -> V_16 ( V_2 ) ;
}
}
}
}
void F_227 ( struct V_1 * V_9 , unsigned int V_3 ,
unsigned int V_190 , unsigned int V_95 , unsigned int V_339 )
{
struct V_47 * V_305 = & V_9 -> V_6 -> V_9 ;
if ( ( V_3 & V_9 -> V_340 & ~ V_190 ) == 0 )
if ( F_228 ( V_305 , V_95 , V_339 ) == 0 )
++ V_9 -> V_175 . V_193 ;
if ( V_3 & ~ V_9 -> V_340 & V_190 )
if ( F_228 ( V_305 , 0 , V_341 ) == 0 )
++ V_9 -> V_175 . V_193 ;
}
