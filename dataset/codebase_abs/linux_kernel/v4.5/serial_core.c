static int F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 & V_4 ) ;
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
static void
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
}
if ( V_23 && F_19 ( V_38 ) )
return 1 ;
return V_23 ;
}
static int F_20 ( struct V_9 * V_8 , struct V_6 * V_7 ,
int V_21 )
{
struct V_39 * V_5 = & V_7 -> V_5 ;
int V_23 ;
if ( V_5 -> V_11 & V_40 )
return 0 ;
F_21 ( V_41 , & V_8 -> V_11 ) ;
V_23 = F_12 ( V_8 , V_7 , V_21 ) ;
if ( ! V_23 ) {
F_21 ( V_42 , & V_5 -> V_11 ) ;
F_22 ( V_41 , & V_8 -> V_11 ) ;
} else if ( V_23 > 0 )
V_23 = 0 ;
return V_23 ;
}
static void F_23 ( struct V_9 * V_8 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_39 * V_5 = & V_7 -> V_5 ;
if ( V_8 )
F_21 ( V_41 , & V_8 -> V_11 ) ;
if ( F_24 ( V_42 , & V_5 -> V_11 ) ) {
if ( F_16 ( V_2 ) && V_8 )
V_2 -> V_31 -> V_32 = V_8 -> V_33 . V_34 ;
if ( ! V_8 || ( V_8 -> V_33 . V_34 & V_43 ) )
F_25 ( V_2 , V_37 | V_36 ) ;
F_26 ( V_5 ) ;
}
F_22 ( V_44 , & V_5 -> V_11 ) ;
if ( V_7 -> V_26 . V_27 ) {
F_27 ( ( unsigned long ) V_7 -> V_26 . V_27 ) ;
V_7 -> V_26 . V_27 = NULL ;
}
}
void
F_28 ( struct V_1 * V_5 , unsigned int V_32 ,
unsigned int V_45 )
{
unsigned int V_46 ;
switch ( V_32 & V_47 ) {
case V_48 :
V_46 = 7 ;
break;
case V_49 :
V_46 = 8 ;
break;
case V_50 :
V_46 = 9 ;
break;
default:
V_46 = 10 ;
break;
}
if ( V_32 & V_51 )
V_46 ++ ;
if ( V_32 & V_52 )
V_46 ++ ;
V_46 = V_46 * V_5 -> V_53 ;
V_5 -> V_54 = ( V_55 * V_46 ) / V_45 + V_55 / 50 ;
}
unsigned int
F_29 ( struct V_1 * V_5 , struct V_56 * V_33 ,
struct V_56 * V_18 , unsigned int V_57 , unsigned int V_58 )
{
unsigned int V_59 ;
unsigned int V_45 ;
unsigned int V_60 ;
int V_61 = 0 ;
T_1 V_11 = V_5 -> V_11 & V_62 ;
switch ( V_11 ) {
case V_63 :
V_60 = 57600 ;
break;
case V_64 :
V_60 = 115200 ;
break;
case V_65 :
V_60 = 230400 ;
break;
case V_66 :
V_60 = 460800 ;
break;
default:
V_60 = 38400 ;
break;
}
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
V_45 = F_30 ( V_33 ) ;
if ( V_59 == 0 && V_45 == 38400 )
V_45 = V_60 ;
if ( V_45 == 0 ) {
V_61 = 1 ;
V_45 = 9600 ;
}
if ( V_45 >= V_57 && V_45 <= V_58 )
return V_45 ;
V_33 -> V_34 &= ~ V_35 ;
if ( V_18 ) {
V_45 = F_30 ( V_18 ) ;
if ( ! V_61 )
F_31 ( V_33 ,
V_45 , V_45 ) ;
V_18 = NULL ;
continue;
}
if ( ! V_61 ) {
if ( V_45 <= V_57 )
F_31 ( V_33 ,
V_57 + 1 , V_57 + 1 ) ;
else
F_31 ( V_33 ,
V_58 - 1 , V_58 - 1 ) ;
}
}
F_32 ( 1 ) ;
return 0 ;
}
unsigned int
F_33 ( struct V_1 * V_5 , unsigned int V_45 )
{
unsigned int V_67 ;
if ( V_45 == 38400 && ( V_5 -> V_11 & V_62 ) == V_68 )
V_67 = V_5 -> V_69 ;
else
V_67 = F_34 ( V_5 -> V_70 , 16 * V_45 ) ;
return V_67 ;
}
static void F_17 ( struct V_9 * V_8 , struct V_6 * V_7 ,
struct V_56 * V_71 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_56 * V_33 ;
int V_72 ;
if ( ! V_8 || V_2 -> type == V_24 )
return;
V_33 = & V_8 -> V_33 ;
V_2 -> V_13 -> V_73 ( V_2 , V_33 , V_71 ) ;
F_35 ( & V_2 -> V_12 ) ;
if ( V_33 -> V_34 & V_74 )
V_2 -> V_3 |= V_75 ;
else
V_2 -> V_3 &= ~ V_75 ;
if ( V_33 -> V_34 & V_76 )
V_2 -> V_3 &= ~ V_4 ;
else
V_2 -> V_3 |= V_4 ;
V_72 = V_2 -> V_72 ;
V_2 -> V_72 = F_36 ( V_2 ) &&
! ( V_2 -> V_13 -> V_77 ( V_2 ) & V_78 ) ;
if ( V_2 -> V_72 ) {
if ( ! V_72 )
V_2 -> V_13 -> V_14 ( V_2 ) ;
} else {
if ( V_72 )
F_8 ( V_8 ) ;
}
F_37 ( & V_2 -> V_12 ) ;
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
F_32 ( 1 ) ;
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
F_8 ( V_8 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
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
F_32 ( 1 ) ;
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
if ( V_8 -> V_33 . V_34 & V_74 )
V_93 |= V_95 ;
if ( V_5 -> V_3 & V_93 ) {
V_5 -> V_13 -> V_96 ( V_5 ) ;
V_93 &= ~ V_5 -> V_3 ;
}
if ( V_93 & V_94 )
F_49 ( V_8 , F_52 ( V_8 ) ) ;
if ( V_93 & V_95 )
F_25 ( V_5 , V_36 ) ;
}
static void F_53 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
T_2 V_93 = 0 ;
if ( F_51 ( V_8 ) )
V_93 |= V_94 ;
if ( V_8 -> V_33 . V_34 & V_74 )
V_93 |= V_95 ;
if ( V_5 -> V_3 & V_93 ) {
V_5 -> V_13 -> V_97 ( V_5 ) ;
V_93 &= ~ V_5 -> V_3 ;
}
if ( V_93 & V_94 )
F_49 ( V_8 , F_54 ( V_8 ) ) ;
if ( V_93 & V_95 )
F_18 ( V_5 , V_36 ) ;
}
static void F_55 ( struct V_39 * V_5 ,
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
V_99 -> V_104 = V_2 -> V_53 ;
V_99 -> V_105 = V_2 -> V_70 / 16 ;
V_99 -> V_106 = F_57 ( V_5 -> V_106 ) / 10 ;
V_99 -> V_107 = V_5 -> V_107 == V_108 ?
V_108 :
F_57 ( V_5 -> V_107 ) / 10 ;
V_99 -> V_69 = V_2 -> V_69 ;
V_99 -> V_109 = V_2 -> V_109 ;
V_99 -> V_110 = V_2 -> V_111 ;
V_99 -> V_112 = V_2 -> V_113 ;
V_99 -> V_114 = ( void * ) ( unsigned long ) V_2 -> V_115 ;
}
static void F_58 ( struct V_39 * V_5 ,
struct V_98 * V_99 )
{
F_59 ( & V_5 -> V_116 ) ;
F_55 ( V_5 , V_99 ) ;
F_60 ( & V_5 -> V_116 ) ;
}
static int F_61 ( struct V_39 * V_5 ,
struct V_98 T_3 * V_99 )
{
struct V_98 V_117 ;
F_58 ( V_5 , & V_117 ) ;
if ( F_62 ( V_99 , & V_117 , sizeof( * V_99 ) ) )
return - V_118 ;
return 0 ;
}
static int F_63 ( struct V_9 * V_8 , struct V_39 * V_5 ,
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
V_123 = V_2 -> V_69 ;
if ( ! F_19 ( V_38 ) ) {
V_23 = - V_127 ;
if ( V_121 || V_122 ||
( V_119 -> V_105 != V_2 -> V_70 / 16 ) ||
( V_106 != V_5 -> V_106 ) ||
( V_107 != V_5 -> V_107 ) ||
( V_119 -> V_104 &&
V_119 -> V_104 != V_2 -> V_53 ) ||
( ( ( V_125 ^ V_124 ) & ~ V_128 ) != 0 ) )
goto exit;
V_2 -> V_11 = ( ( V_2 -> V_11 & ~ V_128 ) |
( V_125 & V_128 ) ) ;
V_2 -> V_69 = V_119 -> V_69 ;
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
F_23 ( V_8 , V_7 ) ;
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
V_2 -> V_70 = V_119 -> V_105 * 16 ;
V_2 -> V_11 = ( V_2 -> V_11 & ~ V_142 ) |
( V_125 & V_142 ) ;
V_2 -> V_69 = V_119 -> V_69 ;
V_5 -> V_106 = V_106 ;
V_5 -> V_107 = V_107 ;
if ( V_119 -> V_104 )
V_2 -> V_53 = V_119 -> V_104 ;
V_5 -> V_143 = ( V_2 -> V_11 & V_144 ) ? 1 : 0 ;
V_129:
V_23 = 0 ;
if ( V_2 -> type == V_24 )
goto exit;
if ( V_5 -> V_11 & V_40 ) {
if ( ( ( V_124 ^ V_2 -> V_11 ) & V_62 ) ||
V_123 != V_2 -> V_69 ) {
if ( V_2 -> V_11 & V_62 ) {
F_67 ( V_2 -> V_145 ,
L_2 ,
V_146 -> V_147 ,
F_68 ( V_5 -> V_8 ) ) ;
}
F_17 ( V_8 , V_7 , NULL ) ;
}
} else
V_23 = F_20 ( V_8 , V_7 , 1 ) ;
exit:
return V_23 ;
}
static int F_69 ( struct V_9 * V_8 , struct V_6 * V_7 ,
struct V_98 T_3 * V_148 )
{
struct V_98 V_149 ;
struct V_39 * V_5 = & V_7 -> V_5 ;
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
struct V_39 * V_5 = & V_7 -> V_5 ;
struct V_1 * V_2 = V_7 -> V_1 ;
int V_151 = - V_154 ;
F_59 ( & V_5 -> V_116 ) ;
if ( ! ( V_8 -> V_11 & ( 1 << V_41 ) ) ) {
V_151 = V_2 -> V_19 ;
F_35 ( & V_2 -> V_12 ) ;
V_151 |= V_2 -> V_13 -> V_77 ( V_2 ) ;
F_37 ( & V_2 -> V_12 ) ;
}
F_60 ( & V_5 -> V_116 ) ;
return V_151 ;
}
static int
F_74 ( struct V_9 * V_8 , unsigned int V_16 , unsigned int V_17 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_39 * V_5 = & V_7 -> V_5 ;
int V_82 = - V_154 ;
F_59 ( & V_5 -> V_116 ) ;
if ( ! ( V_8 -> V_11 & ( 1 << V_41 ) ) ) {
F_11 ( V_2 , V_16 , V_17 ) ;
V_82 = 0 ;
}
F_60 ( & V_5 -> V_116 ) ;
return V_82 ;
}
static int F_75 ( struct V_9 * V_8 , int V_155 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_39 * V_5 = & V_7 -> V_5 ;
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
struct V_39 * V_5 = & V_7 -> V_5 ;
int V_11 , V_82 ;
if ( ! F_19 ( V_38 ) )
return - V_127 ;
if ( F_77 ( & V_5 -> V_116 ) )
return - V_157 ;
V_82 = - V_133 ;
if ( F_66 ( V_5 ) == 1 ) {
F_23 ( V_8 , V_7 ) ;
if ( V_2 -> type != V_24 )
V_2 -> V_13 -> V_140 ( V_2 ) ;
V_11 = V_158 ;
if ( V_2 -> V_11 & V_159 )
V_11 |= V_160 ;
V_2 -> V_13 -> V_161 ( V_2 , V_11 ) ;
V_82 = F_20 ( V_8 , V_7 , 1 ) ;
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
struct V_39 * V_5 = & V_7 -> V_5 ;
F_80 ( V_164 , V_146 ) ;
struct V_165 V_166 , V_167 ;
int V_82 ;
F_35 ( & V_2 -> V_12 ) ;
memcpy ( & V_166 , & V_2 -> V_168 , sizeof( struct V_165 ) ) ;
F_78 ( V_2 ) ;
F_37 ( & V_2 -> V_12 ) ;
F_81 ( & V_5 -> V_169 , & V_164 ) ;
for (; ; ) {
F_35 ( & V_2 -> V_12 ) ;
memcpy ( & V_167 , & V_2 -> V_168 , sizeof( struct V_165 ) ) ;
F_37 ( & V_2 -> V_12 ) ;
F_82 ( V_170 ) ;
if ( ( ( V_163 & V_171 ) && ( V_167 . V_172 != V_166 . V_172 ) ) ||
( ( V_163 & V_173 ) && ( V_167 . V_174 != V_166 . V_174 ) ) ||
( ( V_163 & V_175 ) && ( V_167 . V_176 != V_166 . V_176 ) ) ||
( ( V_163 & V_78 ) && ( V_167 . V_177 != V_166 . V_177 ) ) ) {
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
F_85 ( V_178 ) ;
F_86 ( & V_5 -> V_169 , & V_164 ) ;
return V_82 ;
}
static int F_87 ( struct V_9 * V_8 ,
struct V_179 * V_168 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_165 V_167 ;
struct V_1 * V_2 = V_7 -> V_1 ;
F_35 ( & V_2 -> V_12 ) ;
memcpy ( & V_167 , & V_2 -> V_168 , sizeof( struct V_165 ) ) ;
F_37 ( & V_2 -> V_12 ) ;
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
static int F_88 ( struct V_1 * V_5 ,
struct V_187 T_3 * V_188 )
{
unsigned long V_11 ;
struct V_187 V_189 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_189 = V_5 -> V_188 ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
if ( F_62 ( V_188 , & V_189 , sizeof( V_189 ) ) )
return - V_118 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_5 ,
struct V_187 T_3 * V_190 )
{
struct V_187 V_188 ;
int V_82 ;
unsigned long V_11 ;
if ( ! V_5 -> V_191 )
return - V_192 ;
if ( F_70 ( & V_188 , V_190 , sizeof( * V_190 ) ) )
return - V_118 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_82 = V_5 -> V_191 ( V_5 , & V_188 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
if ( V_82 )
return V_82 ;
if ( F_62 ( V_190 , & V_5 -> V_188 , sizeof( V_5 -> V_188 ) ) )
return - V_118 ;
return 0 ;
}
static int
F_90 ( struct V_9 * V_8 , unsigned int V_193 ,
unsigned long V_163 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_39 * V_5 = & V_7 -> V_5 ;
void T_3 * V_194 = ( void T_3 * ) V_163 ;
int V_82 = - V_192 ;
switch ( V_193 ) {
case V_195 :
V_82 = F_61 ( V_5 , V_194 ) ;
break;
case V_196 :
F_91 ( & V_8 -> V_197 ) ;
V_82 = F_69 ( V_8 , V_7 , V_194 ) ;
F_92 ( & V_8 -> V_197 ) ;
break;
case V_198 :
F_91 ( & V_8 -> V_197 ) ;
V_82 = F_76 ( V_8 , V_7 ) ;
F_92 ( & V_8 -> V_197 ) ;
break;
case V_199 :
case V_200 :
V_82 = 0 ;
break;
}
if ( V_82 != - V_192 )
goto V_201;
if ( V_8 -> V_11 & ( 1 << V_41 ) ) {
V_82 = - V_154 ;
goto V_201;
}
switch ( V_193 ) {
case V_202 :
V_82 = F_79 ( V_7 , V_163 ) ;
break;
}
if ( V_82 != - V_192 )
goto V_201;
F_59 ( & V_5 -> V_116 ) ;
if ( V_8 -> V_11 & ( 1 << V_41 ) ) {
V_82 = - V_154 ;
goto V_203;
}
switch ( V_193 ) {
case V_204 :
V_82 = F_71 ( V_8 , V_7 , V_194 ) ;
break;
case V_205 :
V_82 = F_88 ( V_7 -> V_1 , V_194 ) ;
break;
case V_206 :
V_82 = F_89 ( V_7 -> V_1 , V_194 ) ;
break;
default: {
struct V_1 * V_2 = V_7 -> V_1 ;
if ( V_2 -> V_13 -> V_207 )
V_82 = V_2 -> V_13 -> V_207 ( V_2 , V_193 , V_163 ) ;
break;
}
}
V_203:
F_60 ( & V_5 -> V_116 ) ;
V_201:
return V_82 ;
}
static void F_93 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_1 ;
if ( V_2 -> V_13 -> V_208 ) {
F_59 ( & V_7 -> V_5 . V_116 ) ;
V_2 -> V_13 -> V_208 ( V_2 , & V_8 -> V_33 ) ;
F_60 ( & V_7 -> V_5 . V_116 ) ;
}
}
static void F_94 ( struct V_9 * V_8 ,
struct V_56 * V_71 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_1 ;
unsigned int V_32 = V_8 -> V_33 . V_34 ;
unsigned int V_209 = V_210 | V_211 | V_212 | V_213 | V_214 ;
bool V_215 = false ;
if ( V_2 -> V_11 & V_216 ) {
V_209 |= V_217 | V_218 | V_219 ;
V_215 =
V_8 -> V_33 . V_220 [ V_221 ] != V_71 -> V_220 [ V_221 ] ||
V_8 -> V_33 . V_220 [ V_222 ] != V_71 -> V_220 [ V_222 ] ;
}
if ( ( V_32 ^ V_71 -> V_34 ) == 0 &&
V_8 -> V_33 . V_223 == V_71 -> V_223 &&
V_8 -> V_33 . V_224 == V_71 -> V_224 &&
( ( V_8 -> V_33 . V_225 ^ V_71 -> V_225 ) & V_209 ) == 0 &&
! V_215 ) {
return;
}
F_59 ( & V_7 -> V_5 . V_116 ) ;
F_17 ( V_8 , V_7 , V_71 ) ;
F_60 ( & V_7 -> V_5 . V_116 ) ;
V_32 = V_8 -> V_33 . V_34 ;
if ( ( V_71 -> V_34 & V_35 ) && ! ( V_32 & V_35 ) )
F_25 ( V_2 , V_36 | V_37 ) ;
else if ( ! ( V_71 -> V_34 & V_35 ) && ( V_32 & V_35 ) ) {
unsigned int V_93 = V_37 ;
if ( ! ( V_32 & V_74 ) || ! F_95 ( V_226 , & V_8 -> V_11 ) )
V_93 |= V_36 ;
F_18 ( V_2 , V_93 ) ;
}
}
static void F_96 ( struct V_9 * V_8 , struct V_227 * V_228 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_39 * V_5 ;
struct V_1 * V_2 ;
if ( ! V_7 ) {
struct V_229 * V_230 = V_8 -> V_231 -> V_232 ;
V_7 = V_230 -> V_7 + V_8 -> V_89 ;
V_5 = & V_7 -> V_5 ;
F_35 ( & V_5 -> V_12 ) ;
-- V_5 -> V_86 ;
F_37 ( & V_5 -> V_12 ) ;
return;
}
V_2 = V_7 -> V_1 ;
V_5 = & V_7 -> V_5 ;
F_48 ( L_3 , V_2 ? V_2 -> line : - 1 ) ;
if ( ! V_5 -> V_86 || F_97 ( V_5 , V_8 , V_228 ) == 0 )
return;
if ( V_5 -> V_11 & V_40 ) {
F_35 ( & V_2 -> V_12 ) ;
V_2 -> V_13 -> V_233 ( V_2 ) ;
F_37 ( & V_2 -> V_12 ) ;
F_98 ( V_8 , V_2 -> V_54 ) ;
}
F_59 ( & V_5 -> V_116 ) ;
F_23 ( V_8 , V_7 ) ;
F_99 ( V_5 , NULL ) ;
F_35 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_234 ) {
F_37 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_106 )
F_100 ( F_57 ( V_5 -> V_106 ) ) ;
F_35 ( & V_5 -> V_12 ) ;
} else if ( ! F_16 ( V_2 ) ) {
F_37 ( & V_5 -> V_12 ) ;
F_13 ( V_7 , V_235 ) ;
F_35 ( & V_5 -> V_12 ) ;
}
F_22 ( V_236 , & V_5 -> V_11 ) ;
F_22 ( V_237 , & V_5 -> V_11 ) ;
F_37 ( & V_5 -> V_12 ) ;
F_101 ( & V_5 -> V_238 ) ;
F_60 ( & V_5 -> V_116 ) ;
F_102 ( V_8 ) ;
V_8 -> V_239 = 0 ;
}
static void F_98 ( struct V_9 * V_8 , int V_54 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
unsigned long V_240 , V_241 ;
if ( V_5 -> type == V_24 || V_5 -> V_53 == 0 )
return;
V_240 = ( V_5 -> V_54 - V_55 / 50 ) / V_5 -> V_53 ;
V_240 = V_240 / 5 ;
if ( V_240 == 0 )
V_240 = 1 ;
if ( V_54 && V_54 < V_240 )
V_240 = V_54 ;
if ( V_54 == 0 || V_54 > 2 * V_5 -> V_54 )
V_54 = 2 * V_5 -> V_54 ;
V_241 = V_242 + V_54 ;
F_48 ( L_4 ,
V_5 -> line , V_242 , V_241 ) ;
while ( ! V_5 -> V_13 -> V_152 ( V_5 ) ) {
F_100 ( F_57 ( V_240 ) ) ;
if ( F_84 ( V_146 ) )
break;
if ( F_103 ( V_242 , V_241 ) )
break;
}
}
static void F_104 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_39 * V_5 = & V_7 -> V_5 ;
unsigned long V_11 ;
F_48 ( L_5 , V_7 -> V_1 -> line ) ;
F_59 ( & V_5 -> V_116 ) ;
if ( V_5 -> V_11 & V_243 ) {
F_47 ( V_8 ) ;
F_23 ( V_8 , V_7 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_5 -> V_86 = 0 ;
F_22 ( V_236 , & V_5 -> V_11 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
F_99 ( V_5 , NULL ) ;
if ( ! F_16 ( V_7 -> V_1 ) )
F_13 ( V_7 , V_235 ) ;
F_101 ( & V_5 -> V_238 ) ;
F_101 ( & V_5 -> V_169 ) ;
}
F_60 ( & V_5 -> V_116 ) ;
}
static void F_26 ( struct V_39 * V_5 )
{
struct V_6 * V_7 = F_56 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
F_101 ( & V_5 -> V_169 ) ;
V_2 -> V_13 -> V_244 ( V_2 ) ;
F_105 ( V_2 -> V_103 ) ;
}
static int F_106 ( struct V_39 * V_5 )
{
struct V_6 * V_7 = F_56 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
int V_19 ;
F_35 ( & V_2 -> V_12 ) ;
F_78 ( V_2 ) ;
V_19 = V_2 -> V_13 -> V_77 ( V_2 ) ;
F_37 ( & V_2 -> V_12 ) ;
if ( V_19 & V_245 )
return 1 ;
return 0 ;
}
static void F_107 ( struct V_39 * V_5 , int V_246 )
{
struct V_6 * V_7 = F_56 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
if ( V_246 )
F_18 ( V_2 , V_37 | V_36 ) ;
else
F_25 ( V_2 , V_37 | V_36 ) ;
}
static int F_108 ( struct V_9 * V_8 , struct V_227 * V_228 )
{
struct V_229 * V_230 = (struct V_229 * ) V_8 -> V_231 -> V_232 ;
int V_23 , line = V_8 -> V_89 ;
struct V_6 * V_7 = V_230 -> V_7 + line ;
struct V_39 * V_5 = & V_7 -> V_5 ;
F_48 ( L_6 , line ) ;
F_35 ( & V_5 -> V_12 ) ;
++ V_5 -> V_86 ;
F_37 ( & V_5 -> V_12 ) ;
if ( F_77 ( & V_5 -> V_116 ) ) {
V_23 = - V_157 ;
goto V_247;
}
if ( ! V_7 -> V_1 || V_7 -> V_1 -> V_11 & V_248 ) {
V_23 = - V_249 ;
goto V_250;
}
V_8 -> V_10 = V_7 ;
V_7 -> V_1 -> V_7 = V_7 ;
V_7 -> V_5 . V_143 =
( V_7 -> V_1 -> V_11 & V_144 ) ? 1 : 0 ;
F_99 ( V_5 , V_8 ) ;
V_23 = F_20 ( V_8 , V_7 , 0 ) ;
F_60 ( & V_5 -> V_116 ) ;
if ( V_23 == 0 )
V_23 = F_109 ( V_5 , V_8 , V_228 ) ;
V_247:
return V_23 ;
V_250:
F_60 ( & V_5 -> V_116 ) ;
goto V_247;
}
static const char * F_110 ( struct V_1 * V_5 )
{
const char * V_251 = NULL ;
if ( V_5 -> V_13 -> type )
V_251 = V_5 -> V_13 -> type ( V_5 ) ;
if ( ! V_251 )
V_251 = L_7 ;
return V_251 ;
}
static void F_111 ( struct V_252 * V_253 , struct V_229 * V_230 , int V_254 )
{
struct V_6 * V_7 = V_230 -> V_7 + V_254 ;
struct V_39 * V_5 = & V_7 -> V_5 ;
enum V_255 V_256 ;
struct V_1 * V_2 = V_7 -> V_1 ;
char V_257 [ 32 ] ;
unsigned int V_3 ;
int V_258 ;
if ( ! V_2 )
return;
V_258 = V_2 -> V_111 >= V_259 ;
F_112 ( V_253 , L_8 ,
V_2 -> line , F_110 ( V_2 ) ,
V_258 ? L_9 : L_10 ,
V_258 ? ( unsigned long long ) V_2 -> V_115
: ( unsigned long long ) V_2 -> V_100 ,
V_2 -> V_103 ) ;
if ( V_2 -> type == V_24 ) {
F_113 ( V_253 , '\n' ) ;
return;
}
if ( F_19 ( V_38 ) ) {
F_59 ( & V_5 -> V_116 ) ;
V_256 = V_7 -> V_256 ;
if ( V_256 != V_25 )
F_13 ( V_7 , V_25 ) ;
F_35 ( & V_2 -> V_12 ) ;
V_3 = V_2 -> V_13 -> V_77 ( V_2 ) ;
F_37 ( & V_2 -> V_12 ) ;
if ( V_256 != V_25 )
F_13 ( V_7 , V_256 ) ;
F_60 ( & V_5 -> V_116 ) ;
F_112 ( V_253 , L_11 ,
V_2 -> V_168 . V_181 , V_2 -> V_168 . V_180 ) ;
if ( V_2 -> V_168 . V_182 )
F_112 ( V_253 , L_12 ,
V_2 -> V_168 . V_182 ) ;
if ( V_2 -> V_168 . V_184 )
F_112 ( V_253 , L_13 ,
V_2 -> V_168 . V_184 ) ;
if ( V_2 -> V_168 . V_185 )
F_112 ( V_253 , L_14 ,
V_2 -> V_168 . V_185 ) ;
if ( V_2 -> V_168 . V_183 )
F_112 ( V_253 , L_15 ,
V_2 -> V_168 . V_183 ) ;
#define F_114 ( T_4 , V_251 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_115 ( T_4 , V_251 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_257 [ 0 ] = '\0' ;
V_257 [ 1 ] = '\0' ;
F_114 ( V_36 , L_16 ) ;
F_115 ( V_78 , L_17 ) ;
F_114 ( V_37 , L_18 ) ;
F_115 ( V_173 , L_19 ) ;
F_115 ( V_245 , L_20 ) ;
F_115 ( V_171 , L_21 ) ;
if ( V_257 [ 0 ] )
V_257 [ 0 ] = ' ' ;
F_116 ( V_253 , V_257 ) ;
}
F_113 ( V_253 , '\n' ) ;
#undef F_115
#undef F_114
}
static int F_117 ( struct V_252 * V_253 , void * V_260 )
{
struct V_261 * V_262 = V_253 -> V_263 ;
struct V_229 * V_230 = V_262 -> V_232 ;
int V_254 ;
F_112 ( V_253 , L_22 ,
L_23 , L_23 , L_23 ) ;
for ( V_254 = 0 ; V_254 < V_230 -> V_264 ; V_254 ++ )
F_111 ( V_253 , V_230 , V_254 ) ;
return 0 ;
}
static int F_118 ( struct V_265 * V_265 , struct V_227 * V_227 )
{
return F_119 ( V_227 , F_117 , F_120 ( V_265 ) ) ;
}
void F_121 ( struct V_1 * V_5 , const char * V_266 ,
unsigned int V_86 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_254 ;
for ( V_254 = 0 ; V_254 < V_86 ; V_254 ++ , V_266 ++ ) {
if ( * V_266 == '\n' )
putchar ( V_5 , '\r' ) ;
putchar ( V_5 , * V_266 ) ;
}
}
struct V_1 * T_5
F_122 ( struct V_1 * V_267 , int V_264 , struct V_268 * V_269 )
{
int V_270 = V_269 -> V_89 ;
if ( V_270 < 0 || V_270 >= V_264 || ( V_267 [ V_270 ] . V_100 == 0 &&
V_267 [ V_270 ] . V_271 == NULL ) )
for ( V_270 = 0 ; V_270 < V_264 ; V_270 ++ )
if ( V_267 [ V_270 ] . V_100 != 0 ||
V_267 [ V_270 ] . V_271 != NULL )
break;
V_269 -> V_89 = V_270 ;
return V_267 + V_270 ;
}
int F_123 ( char * V_272 , unsigned char * V_111 , unsigned long * V_273 ,
char * * V_274 )
{
if ( strncmp ( V_272 , L_24 , 5 ) == 0 ) {
* V_111 = V_259 ;
V_272 += 5 ;
} else if ( strncmp ( V_272 , L_25 , 7 ) == 0 ) {
* V_111 = V_275 ;
V_272 += 7 ;
} else if ( strncmp ( V_272 , L_26 , 7 ) == 0 ) {
* V_111 = V_276 ;
V_272 += 7 ;
} else if ( strncmp ( V_272 , L_27 , 9 ) == 0 ) {
* V_111 = V_277 ;
V_272 += 9 ;
} else if ( strncmp ( V_272 , L_28 , 13 ) == 0 ) {
* V_111 = F_124 ( V_278 ) ?
V_277 : V_276 ;
V_272 += 13 ;
} else if ( strncmp ( V_272 , L_29 , 3 ) == 0 ) {
* V_111 = V_279 ;
V_272 += 3 ;
} else if ( strncmp ( V_272 , L_30 , 2 ) == 0 ) {
* V_111 = V_259 ;
} else {
return - V_132 ;
}
* V_273 = F_125 ( V_272 , NULL , 0 ) ;
V_272 = strchr ( V_272 , ',' ) ;
if ( V_272 )
V_272 ++ ;
* V_274 = V_272 ;
return 0 ;
}
void
F_126 ( char * V_274 , int * V_45 , int * V_184 , int * V_46 , int * V_280 )
{
char * V_266 = V_274 ;
* V_45 = F_125 ( V_266 , NULL , 10 ) ;
while ( * V_266 >= '0' && * V_266 <= '9' )
V_266 ++ ;
if ( * V_266 )
* V_184 = * V_266 ++ ;
if ( * V_266 )
* V_46 = * V_266 ++ - '0' ;
if ( * V_266 )
* V_280 = * V_266 ;
}
int
F_127 ( struct V_1 * V_5 , struct V_268 * V_269 ,
int V_45 , int V_184 , int V_46 , int V_280 )
{
struct V_56 V_33 ;
static struct V_56 V_281 ;
int V_254 ;
if ( ! ( F_16 ( V_5 ) && ( V_5 -> V_31 -> V_11 & V_282 ) ) ) {
F_128 ( & V_5 -> V_12 ) ;
F_129 ( & V_5 -> V_12 , & V_283 ) ;
}
memset ( & V_33 , 0 , sizeof( struct V_56 ) ) ;
V_33 . V_34 = V_284 | V_43 | V_76 ;
for ( V_254 = 0 ; V_285 [ V_254 ] . V_286 ; V_254 ++ )
if ( V_285 [ V_254 ] . V_286 <= V_45 )
break;
V_33 . V_34 |= V_285 [ V_254 ] . V_32 ;
if ( V_46 == 7 )
V_33 . V_34 |= V_50 ;
else
V_33 . V_34 |= V_287 ;
switch ( V_184 ) {
case 'o' : case 'O' :
V_33 . V_34 |= V_288 ;
case 'e' : case 'E' :
V_33 . V_34 |= V_52 ;
break;
}
if ( V_280 == 'r' )
V_33 . V_34 |= V_74 ;
V_5 -> V_19 |= V_37 ;
V_5 -> V_13 -> V_73 ( V_5 , & V_33 , & V_281 ) ;
if ( V_269 )
V_269 -> V_32 = V_33 . V_34 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_7 ,
enum V_255 V_256 )
{
struct V_1 * V_5 = V_7 -> V_1 ;
if ( V_7 -> V_256 != V_256 ) {
if ( V_5 -> V_13 -> V_289 )
V_5 -> V_13 -> V_289 ( V_5 , V_256 , V_7 -> V_256 ) ;
V_7 -> V_256 = V_256 ;
}
}
static int F_130 ( struct V_290 * V_145 , void * V_291 )
{
struct V_292 * V_293 = V_291 ;
struct V_261 * V_294 = V_293 -> V_231 -> V_261 ;
T_6 V_295 = F_131 ( V_294 -> V_296 , V_294 -> V_297 ) +
V_293 -> V_5 -> line ;
return V_145 -> V_295 == V_295 ;
}
int F_132 ( struct V_229 * V_230 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_230 -> V_7 + V_2 -> line ;
struct V_39 * V_5 = & V_7 -> V_5 ;
struct V_290 * V_298 ;
struct V_292 V_293 = { V_2 , V_230 } ;
F_59 ( & V_5 -> V_116 ) ;
V_298 = F_133 ( V_2 -> V_145 , & V_293 , F_130 ) ;
if ( F_134 ( V_298 ) ) {
if ( ! F_135 ( V_2 -> V_103 ) )
V_2 -> V_299 = 1 ;
F_136 ( V_298 ) ;
F_60 ( & V_5 -> V_116 ) ;
return 0 ;
}
F_136 ( V_298 ) ;
if ( ! V_300 && F_16 ( V_2 ) )
goto V_301;
V_2 -> V_302 = 1 ;
if ( V_5 -> V_11 & V_40 ) {
const struct V_303 * V_13 = V_2 -> V_13 ;
int V_304 ;
F_21 ( V_44 , & V_5 -> V_11 ) ;
F_22 ( V_42 , & V_5 -> V_11 ) ;
F_35 ( & V_2 -> V_12 ) ;
V_13 -> V_14 ( V_2 ) ;
V_13 -> V_20 ( V_2 , 0 ) ;
V_13 -> V_233 ( V_2 ) ;
F_37 ( & V_2 -> V_12 ) ;
for ( V_304 = 3 ; ! V_13 -> V_152 ( V_2 ) && V_304 ; V_304 -- )
F_137 ( 10 ) ;
if ( ! V_304 )
F_138 ( V_2 -> V_145 , L_31 ,
V_230 -> V_305 ,
V_230 -> V_261 -> V_306 + V_2 -> line ) ;
V_13 -> V_244 ( V_2 ) ;
}
if ( F_16 ( V_2 ) )
F_139 ( V_2 -> V_31 ) ;
F_13 ( V_7 , V_235 ) ;
V_301:
F_60 ( & V_5 -> V_116 ) ;
return 0 ;
}
int F_140 ( struct V_229 * V_230 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_230 -> V_7 + V_2 -> line ;
struct V_39 * V_5 = & V_7 -> V_5 ;
struct V_290 * V_298 ;
struct V_292 V_293 = { V_2 , V_230 } ;
struct V_56 V_33 ;
F_59 ( & V_5 -> V_116 ) ;
V_298 = F_133 ( V_2 -> V_145 , & V_293 , F_130 ) ;
if ( ! V_2 -> V_302 && F_134 ( V_298 ) ) {
if ( V_2 -> V_299 ) {
F_141 ( V_2 -> V_103 ) ;
V_2 -> V_299 = 0 ;
}
F_136 ( V_298 ) ;
F_60 ( & V_5 -> V_116 ) ;
return 0 ;
}
F_136 ( V_298 ) ;
V_2 -> V_302 = 0 ;
if ( F_16 ( V_2 ) ) {
memset ( & V_33 , 0 , sizeof( struct V_56 ) ) ;
V_33 . V_34 = V_2 -> V_31 -> V_32 ;
if ( V_5 -> V_8 && V_33 . V_34 == 0 )
V_33 = V_5 -> V_8 -> V_33 ;
if ( V_300 )
F_13 ( V_7 , V_25 ) ;
V_2 -> V_13 -> V_73 ( V_2 , & V_33 , NULL ) ;
if ( V_300 )
F_142 ( V_2 -> V_31 ) ;
}
if ( V_5 -> V_11 & V_307 ) {
const struct V_303 * V_13 = V_2 -> V_13 ;
int V_82 ;
F_13 ( V_7 , V_25 ) ;
F_35 ( & V_2 -> V_12 ) ;
V_13 -> V_20 ( V_2 , 0 ) ;
F_37 ( & V_2 -> V_12 ) ;
if ( V_300 || ! F_16 ( V_2 ) ) {
struct V_9 * V_8 = V_5 -> V_8 ;
V_82 = V_13 -> V_30 ( V_2 ) ;
if ( V_82 == 0 ) {
if ( V_8 )
F_17 ( V_8 , V_7 , NULL ) ;
F_35 ( & V_2 -> V_12 ) ;
V_13 -> V_20 ( V_2 , V_2 -> V_19 ) ;
V_13 -> V_15 ( V_2 ) ;
F_37 ( & V_2 -> V_12 ) ;
F_21 ( V_42 , & V_5 -> V_11 ) ;
} else {
F_23 ( V_8 , V_7 ) ;
}
}
F_22 ( V_44 , & V_5 -> V_11 ) ;
}
F_60 ( & V_5 -> V_116 ) ;
return 0 ;
}
static inline void
F_143 ( struct V_229 * V_230 , struct V_1 * V_5 )
{
char V_308 [ 64 ] ;
switch ( V_5 -> V_111 ) {
case V_279 :
snprintf ( V_308 , sizeof( V_308 ) , L_32 , V_5 -> V_100 ) ;
break;
case V_309 :
snprintf ( V_308 , sizeof( V_308 ) ,
L_33 , V_5 -> V_100 , V_5 -> V_109 ) ;
break;
case V_259 :
case V_275 :
case V_276 :
case V_277 :
case V_310 :
case V_311 :
snprintf ( V_308 , sizeof( V_308 ) ,
L_34 , ( unsigned long long ) V_5 -> V_115 ) ;
break;
default:
F_144 ( V_308 , L_35 , sizeof( V_308 ) ) ;
break;
}
F_145 ( V_312 L_36 ,
V_5 -> V_145 ? V_305 ( V_5 -> V_145 ) : L_23 ,
V_5 -> V_145 ? L_37 : L_23 ,
V_230 -> V_305 ,
V_230 -> V_261 -> V_306 + V_5 -> line ,
V_308 , V_5 -> V_103 , V_5 -> V_70 / 16 , F_110 ( V_5 ) ) ;
}
static void
F_146 ( struct V_229 * V_230 , struct V_6 * V_7 ,
struct V_1 * V_5 )
{
unsigned int V_11 ;
if ( ! V_5 -> V_100 && ! V_5 -> V_115 && ! V_5 -> V_271 )
return;
V_11 = 0 ;
if ( V_5 -> V_11 & V_159 )
V_11 |= V_160 ;
if ( V_5 -> V_11 & V_313 ) {
if ( ! ( V_5 -> V_11 & V_314 ) ) {
V_5 -> type = V_24 ;
V_11 |= V_158 ;
}
V_5 -> V_13 -> V_161 ( V_5 , V_11 ) ;
}
if ( V_5 -> type != V_24 ) {
unsigned long V_11 ;
F_143 ( V_230 , V_5 ) ;
F_13 ( V_7 , V_25 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_5 -> V_13 -> V_20 ( V_5 , V_5 -> V_19 & V_37 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
if ( V_5 -> V_31 && ! ( V_5 -> V_31 -> V_11 & V_282 ) )
F_147 ( V_5 -> V_31 ) ;
if ( ! F_16 ( V_5 ) )
F_13 ( V_7 , V_235 ) ;
}
}
static int F_148 ( struct V_261 * V_231 , int line , char * V_274 )
{
struct V_229 * V_230 = V_231 -> V_232 ;
struct V_6 * V_7 = V_230 -> V_7 + line ;
struct V_1 * V_5 ;
int V_45 = 9600 ;
int V_46 = 8 ;
int V_184 = 'n' ;
int V_280 = 'n' ;
int V_82 ;
if ( ! V_7 || ! V_7 -> V_1 )
return - 1 ;
V_5 = V_7 -> V_1 ;
if ( ! ( V_5 -> V_13 -> V_315 && V_5 -> V_13 -> V_316 ) )
return - 1 ;
if ( V_5 -> V_13 -> V_317 ) {
struct V_39 * V_318 = & V_7 -> V_5 ;
V_82 = 0 ;
F_59 ( & V_318 -> V_116 ) ;
if ( ! F_95 ( V_42 , & V_318 -> V_11 ) )
V_82 = V_5 -> V_13 -> V_317 ( V_5 ) ;
F_60 ( & V_318 -> V_116 ) ;
if ( V_82 )
return V_82 ;
}
if ( V_274 ) {
F_126 ( V_274 , & V_45 , & V_184 , & V_46 , & V_280 ) ;
return F_127 ( V_5 , NULL , V_45 , V_184 , V_46 , V_280 ) ;
}
return 0 ;
}
static int F_149 ( struct V_261 * V_231 , int line )
{
struct V_229 * V_230 = V_231 -> V_232 ;
struct V_6 * V_7 = V_230 -> V_7 + line ;
struct V_1 * V_5 ;
if ( ! V_7 || ! V_7 -> V_1 )
return - 1 ;
V_5 = V_7 -> V_1 ;
return V_5 -> V_13 -> V_315 ( V_5 ) ;
}
static void F_150 ( struct V_261 * V_231 , int line , char V_85 )
{
struct V_229 * V_230 = V_231 -> V_232 ;
struct V_6 * V_7 = V_230 -> V_7 + line ;
struct V_1 * V_5 ;
if ( ! V_7 || ! V_7 -> V_1 )
return;
V_5 = V_7 -> V_1 ;
if ( V_85 == '\n' )
V_5 -> V_13 -> V_316 ( V_5 , '\r' ) ;
V_5 -> V_13 -> V_316 ( V_5 , V_85 ) ;
}
int F_151 ( struct V_229 * V_230 )
{
struct V_261 * V_319 ;
int V_254 , V_23 ;
F_3 ( V_230 -> V_7 ) ;
V_230 -> V_7 = F_152 ( sizeof( struct V_6 ) * V_230 -> V_264 , V_28 ) ;
if ( ! V_230 -> V_7 )
goto V_201;
V_319 = F_153 ( V_230 -> V_264 ) ;
if ( ! V_319 )
goto V_320;
V_230 -> V_261 = V_319 ;
V_319 -> V_321 = V_230 -> V_321 ;
V_319 -> V_322 = V_230 -> V_305 ;
V_319 -> V_296 = V_230 -> V_296 ;
V_319 -> V_297 = V_230 -> V_323 ;
V_319 -> type = V_324 ;
V_319 -> V_325 = V_326 ;
V_319 -> V_327 = V_328 ;
V_319 -> V_327 . V_34 = V_329 | V_287 | V_284 | V_43 | V_76 ;
V_319 -> V_327 . V_224 = V_319 -> V_327 . V_223 = 9600 ;
V_319 -> V_11 = V_330 | V_331 ;
V_319 -> V_232 = V_230 ;
F_154 ( V_319 , & V_303 ) ;
for ( V_254 = 0 ; V_254 < V_230 -> V_264 ; V_254 ++ ) {
struct V_6 * V_7 = V_230 -> V_7 + V_254 ;
struct V_39 * V_5 = & V_7 -> V_5 ;
F_155 ( V_5 ) ;
V_5 -> V_13 = & V_332 ;
}
V_23 = F_156 ( V_319 ) ;
if ( V_23 >= 0 )
return V_23 ;
for ( V_254 = 0 ; V_254 < V_230 -> V_264 ; V_254 ++ )
F_157 ( & V_230 -> V_7 [ V_254 ] . V_5 ) ;
F_158 ( V_319 ) ;
V_320:
F_159 ( V_230 -> V_7 ) ;
V_201:
return - V_29 ;
}
void F_160 ( struct V_229 * V_230 )
{
struct V_261 * V_272 = V_230 -> V_261 ;
unsigned int V_254 ;
F_161 ( V_272 ) ;
F_158 ( V_272 ) ;
for ( V_254 = 0 ; V_254 < V_230 -> V_264 ; V_254 ++ )
F_157 ( & V_230 -> V_7 [ V_254 ] . V_5 ) ;
F_159 ( V_230 -> V_7 ) ;
V_230 -> V_7 = NULL ;
V_230 -> V_261 = NULL ;
}
struct V_261 * F_162 ( struct V_268 * V_269 , int * V_89 )
{
struct V_229 * V_272 = V_269 -> V_291 ;
* V_89 = V_269 -> V_89 ;
return V_272 -> V_261 ;
}
static T_7 F_163 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . V_105 * 16 ) ;
}
static T_7 F_165 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . type ) ;
}
static T_7 F_166 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . line ) ;
}
static T_7 F_167 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
unsigned long V_336 ;
F_58 ( V_5 , & V_117 ) ;
V_336 = V_117 . V_5 ;
if ( V_101 )
V_336 |= ( unsigned long ) V_117 . V_102 << V_101 ;
return snprintf ( V_27 , V_335 , L_39 , V_336 ) ;
}
static T_7 F_168 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . V_103 ) ;
}
static T_7 F_169 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_40 , V_117 . V_11 ) ;
}
static T_7 F_170 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . V_104 ) ;
}
static T_7 F_171 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . V_106 ) ;
}
static T_7 F_172 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . V_107 ) ;
}
static T_7 F_173 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . V_69 ) ;
}
static T_7 F_174 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . V_110 ) ;
}
static T_7 F_175 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_39 , ( unsigned long ) V_117 . V_114 ) ;
}
static T_7 F_176 ( struct V_290 * V_145 ,
struct V_333 * V_334 , char * V_27 )
{
struct V_98 V_117 ;
struct V_39 * V_5 = F_164 ( V_145 ) ;
F_58 ( V_5 , & V_117 ) ;
return snprintf ( V_27 , V_335 , L_38 , V_117 . V_112 ) ;
}
int F_177 ( struct V_229 * V_230 , struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_39 * V_5 ;
int V_82 = 0 ;
struct V_290 * V_298 ;
int V_337 ;
F_3 ( F_178 () ) ;
if ( V_2 -> line >= V_230 -> V_264 )
return - V_132 ;
V_7 = V_230 -> V_7 + V_2 -> line ;
V_5 = & V_7 -> V_5 ;
F_59 ( & V_338 ) ;
F_59 ( & V_5 -> V_116 ) ;
if ( V_7 -> V_1 ) {
V_82 = - V_132 ;
goto V_201;
}
V_7 -> V_1 = V_2 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_256 = V_339 ;
V_2 -> V_31 = V_230 -> V_31 ;
V_2 -> V_323 = V_230 -> V_261 -> V_297 + V_2 -> line ;
if ( ! ( F_16 ( V_2 ) && ( V_2 -> V_31 -> V_11 & V_282 ) ) ) {
F_128 ( & V_2 -> V_12 ) ;
F_129 ( & V_2 -> V_12 , & V_283 ) ;
}
if ( V_2 -> V_31 && V_2 -> V_145 )
F_179 ( V_2 -> V_145 -> V_340 , V_2 -> V_31 -> V_322 , V_2 -> line ) ;
F_146 ( V_230 , V_7 , V_2 ) ;
V_337 = 2 ;
if ( V_2 -> V_341 )
V_337 ++ ;
V_2 -> V_342 = F_180 ( V_337 , sizeof( * V_2 -> V_342 ) ,
V_28 ) ;
if ( ! V_2 -> V_342 ) {
V_82 = - V_29 ;
goto V_201;
}
V_2 -> V_342 [ 0 ] = & V_343 ;
if ( V_2 -> V_341 )
V_2 -> V_342 [ 1 ] = V_2 -> V_341 ;
V_298 = F_181 ( V_5 , V_230 -> V_261 ,
V_2 -> line , V_2 -> V_145 , V_5 , V_2 -> V_342 ) ;
if ( F_182 ( ! F_183 ( V_298 ) ) ) {
F_184 ( V_298 , 1 ) ;
} else {
F_138 ( V_2 -> V_145 , L_41 ,
V_2 -> line ) ;
}
V_2 -> V_11 &= ~ V_248 ;
V_201:
F_60 ( & V_5 -> V_116 ) ;
F_60 ( & V_338 ) ;
return V_82 ;
}
int F_185 ( struct V_229 * V_230 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_230 -> V_7 + V_2 -> line ;
struct V_39 * V_5 = & V_7 -> V_5 ;
struct V_9 * V_8 ;
int V_82 = 0 ;
F_3 ( F_178 () ) ;
if ( V_7 -> V_1 != V_2 )
F_186 ( V_2 -> V_145 , L_42 ,
V_7 -> V_1 , V_2 ) ;
F_59 ( & V_338 ) ;
F_59 ( & V_5 -> V_116 ) ;
if ( ! V_7 -> V_1 ) {
F_60 ( & V_5 -> V_116 ) ;
V_82 = - V_132 ;
goto V_201;
}
V_2 -> V_11 |= V_248 ;
F_60 ( & V_5 -> V_116 ) ;
F_187 ( V_230 -> V_261 , V_2 -> line ) ;
V_8 = F_188 ( V_5 ) ;
if ( V_8 ) {
F_189 ( V_5 -> V_8 ) ;
F_190 ( V_8 ) ;
}
if ( F_16 ( V_2 ) )
F_191 ( V_2 -> V_31 ) ;
if ( V_2 -> type != V_24 )
V_2 -> V_13 -> V_140 ( V_2 ) ;
F_159 ( V_2 -> V_342 ) ;
V_2 -> type = V_24 ;
V_7 -> V_1 = NULL ;
V_201:
F_60 ( & V_338 ) ;
return V_82 ;
}
int F_192 ( struct V_1 * V_344 , struct V_1 * V_345 )
{
if ( V_344 -> V_111 != V_345 -> V_111 )
return 0 ;
switch ( V_344 -> V_111 ) {
case V_279 :
return ( V_344 -> V_100 == V_345 -> V_100 ) ;
case V_309 :
return ( V_344 -> V_100 == V_345 -> V_100 ) &&
( V_344 -> V_109 == V_345 -> V_109 ) ;
case V_259 :
case V_275 :
case V_276 :
case V_277 :
case V_310 :
case V_311 :
return ( V_344 -> V_115 == V_345 -> V_115 ) ;
}
return 0 ;
}
void F_193 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_39 * V_5 = & V_2 -> V_7 -> V_5 ;
struct V_9 * V_8 = V_5 -> V_8 ;
struct V_346 * V_347 ;
F_194 ( & V_2 -> V_12 ) ;
if ( V_8 ) {
V_347 = F_195 ( V_8 ) ;
if ( V_347 ) {
if ( V_347 -> V_13 -> V_348 )
V_347 -> V_13 -> V_348 ( V_8 , V_3 ) ;
F_196 ( V_347 ) ;
}
}
V_2 -> V_168 . V_176 ++ ;
if ( F_1 ( V_2 ) ) {
if ( V_3 )
F_101 ( & V_5 -> V_238 ) ;
else if ( V_8 )
F_197 ( V_8 ) ;
}
}
void F_198 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_194 ( & V_2 -> V_12 ) ;
V_2 -> V_168 . V_177 ++ ;
if ( F_36 ( V_2 ) ) {
if ( V_2 -> V_72 ) {
if ( V_3 ) {
V_2 -> V_72 = 0 ;
V_2 -> V_13 -> V_15 ( V_2 ) ;
F_2 ( V_2 ) ;
}
} else {
if ( ! V_3 ) {
V_2 -> V_72 = 1 ;
V_2 -> V_13 -> V_14 ( V_2 ) ;
}
}
}
}
void F_199 ( struct V_1 * V_5 , unsigned int V_3 ,
unsigned int V_183 , unsigned int V_85 , unsigned int V_349 )
{
struct V_39 * V_318 = & V_5 -> V_7 -> V_5 ;
if ( ( V_3 & V_5 -> V_350 & ~ V_183 ) == 0 )
if ( F_200 ( V_318 , V_85 , V_349 ) == 0 )
++ V_5 -> V_168 . V_186 ;
if ( V_3 & ~ V_5 -> V_350 & V_183 )
if ( F_200 ( V_318 , 0 , V_351 ) == 0 )
++ V_5 -> V_168 . V_186 ;
}
