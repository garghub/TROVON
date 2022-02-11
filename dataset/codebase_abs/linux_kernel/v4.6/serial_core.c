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
if ( V_21 && F_18 ( V_8 ) )
F_19 ( V_2 , V_35 | V_36 ) ;
}
if ( V_23 && F_20 ( V_37 ) )
return 1 ;
return V_23 ;
}
static int F_21 ( struct V_9 * V_8 , struct V_6 * V_7 ,
int V_21 )
{
struct V_38 * V_5 = & V_7 -> V_5 ;
int V_23 ;
if ( V_5 -> V_11 & V_39 )
return 0 ;
F_22 ( V_40 , & V_8 -> V_11 ) ;
V_23 = F_12 ( V_8 , V_7 , V_21 ) ;
if ( ! V_23 ) {
F_22 ( V_41 , & V_5 -> V_11 ) ;
F_23 ( V_40 , & V_8 -> V_11 ) ;
} else if ( V_23 > 0 )
V_23 = 0 ;
return V_23 ;
}
static void F_24 ( struct V_9 * V_8 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
if ( V_8 )
F_22 ( V_40 , & V_8 -> V_11 ) ;
if ( F_25 ( V_41 , & V_5 -> V_11 ) ) {
if ( F_16 ( V_2 ) && V_8 )
V_2 -> V_31 -> V_32 = V_8 -> V_33 . V_34 ;
if ( ! V_8 || F_26 ( V_8 ) )
F_27 ( V_2 , V_36 | V_35 ) ;
F_28 ( V_5 ) ;
}
F_23 ( V_42 , & V_5 -> V_11 ) ;
if ( V_7 -> V_26 . V_27 ) {
F_29 ( ( unsigned long ) V_7 -> V_26 . V_27 ) ;
V_7 -> V_26 . V_27 = NULL ;
}
}
void
F_30 ( struct V_1 * V_5 , unsigned int V_32 ,
unsigned int V_43 )
{
unsigned int V_44 ;
switch ( V_32 & V_45 ) {
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
if ( V_32 & V_49 )
V_44 ++ ;
if ( V_32 & V_50 )
V_44 ++ ;
V_44 = V_44 * V_5 -> V_51 ;
V_5 -> V_52 = ( V_53 * V_44 ) / V_43 + V_53 / 50 ;
}
unsigned int
F_31 ( struct V_1 * V_5 , struct V_54 * V_33 ,
struct V_54 * V_18 , unsigned int V_55 , unsigned int V_56 )
{
unsigned int V_57 ;
unsigned int V_43 ;
unsigned int V_58 ;
int V_59 = 0 ;
T_1 V_11 = V_5 -> V_11 & V_60 ;
switch ( V_11 ) {
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
V_43 = F_32 ( V_33 ) ;
if ( V_57 == 0 && V_43 == 38400 )
V_43 = V_58 ;
if ( V_43 == 0 ) {
V_59 = 1 ;
V_43 = 9600 ;
}
if ( V_43 >= V_55 && V_43 <= V_56 )
return V_43 ;
V_33 -> V_34 &= ~ V_65 ;
if ( V_18 ) {
V_43 = F_32 ( V_18 ) ;
if ( ! V_59 )
F_33 ( V_33 ,
V_43 , V_43 ) ;
V_18 = NULL ;
continue;
}
if ( ! V_59 ) {
if ( V_43 <= V_55 )
F_33 ( V_33 ,
V_55 + 1 , V_55 + 1 ) ;
else
F_33 ( V_33 ,
V_56 - 1 , V_56 - 1 ) ;
}
}
F_34 ( 1 ) ;
return 0 ;
}
unsigned int
F_35 ( struct V_1 * V_5 , unsigned int V_43 )
{
unsigned int V_66 ;
if ( V_43 == 38400 && ( V_5 -> V_11 & V_60 ) == V_67 )
V_66 = V_5 -> V_68 ;
else
V_66 = F_36 ( V_5 -> V_69 , 16 * V_43 ) ;
return V_66 ;
}
static void F_17 ( struct V_9 * V_8 , struct V_6 * V_7 ,
struct V_54 * V_70 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_54 * V_33 ;
int V_71 ;
if ( ! V_8 || V_2 -> type == V_24 )
return;
V_33 = & V_8 -> V_33 ;
V_2 -> V_13 -> V_72 ( V_2 , V_33 , V_70 ) ;
F_37 ( & V_2 -> V_12 ) ;
if ( V_33 -> V_34 & V_73 )
V_2 -> V_3 |= V_74 ;
else
V_2 -> V_3 &= ~ V_74 ;
if ( V_33 -> V_34 & V_75 )
V_2 -> V_3 &= ~ V_4 ;
else
V_2 -> V_3 |= V_4 ;
V_71 = V_2 -> V_71 ;
V_2 -> V_71 = F_38 ( V_2 ) &&
! ( V_2 -> V_13 -> V_76 ( V_2 ) & V_77 ) ;
if ( V_2 -> V_71 ) {
if ( ! V_71 )
V_2 -> V_13 -> V_14 ( V_2 ) ;
} else {
if ( V_71 )
F_8 ( V_8 ) ;
}
F_39 ( & V_2 -> V_12 ) ;
}
static int F_40 ( struct V_9 * V_8 , unsigned char V_78 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
struct V_79 * V_80 ;
unsigned long V_11 ;
int V_81 = 0 ;
V_80 = & V_7 -> V_26 ;
if ( ! V_80 -> V_27 )
return 0 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
if ( F_41 ( V_80 ) != 0 ) {
V_80 -> V_27 [ V_80 -> V_82 ] = V_78 ;
V_80 -> V_82 = ( V_80 -> V_82 + 1 ) & ( V_83 - 1 ) ;
V_81 = 1 ;
}
F_7 ( & V_5 -> V_12 , V_11 ) ;
return V_81 ;
}
static void F_42 ( struct V_9 * V_8 )
{
F_10 ( V_8 ) ;
}
static int F_43 ( struct V_9 * V_8 ,
const unsigned char * V_27 , int V_84 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 ;
struct V_79 * V_80 ;
unsigned long V_11 ;
int V_78 , V_81 = 0 ;
if ( ! V_7 ) {
F_34 ( 1 ) ;
return - V_85 ;
}
V_5 = V_7 -> V_1 ;
V_80 = & V_7 -> V_26 ;
if ( ! V_80 -> V_27 )
return 0 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
while ( 1 ) {
V_78 = F_44 ( V_80 -> V_82 , V_80 -> V_86 , V_83 ) ;
if ( V_84 < V_78 )
V_78 = V_84 ;
if ( V_78 <= 0 )
break;
memcpy ( V_80 -> V_27 + V_80 -> V_82 , V_27 , V_78 ) ;
V_80 -> V_82 = ( V_80 -> V_82 + V_78 ) & ( V_83 - 1 ) ;
V_27 += V_78 ;
V_84 -= V_78 ;
V_81 += V_78 ;
}
F_8 ( V_8 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
return V_81 ;
}
static int F_45 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
unsigned long V_11 ;
int V_81 ;
F_6 ( & V_7 -> V_1 -> V_12 , V_11 ) ;
V_81 = F_41 ( & V_7 -> V_26 ) ;
F_7 ( & V_7 -> V_1 -> V_12 , V_11 ) ;
return V_81 ;
}
static int F_46 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
unsigned long V_11 ;
int V_81 ;
F_6 ( & V_7 -> V_1 -> V_12 , V_11 ) ;
V_81 = F_47 ( & V_7 -> V_26 ) ;
F_7 ( & V_7 -> V_1 -> V_12 , V_11 ) ;
return V_81 ;
}
static void F_48 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 ;
unsigned long V_11 ;
if ( ! V_7 ) {
F_34 ( 1 ) ;
return;
}
V_5 = V_7 -> V_1 ;
F_49 ( L_1 , V_8 -> V_87 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
F_15 ( & V_7 -> V_26 ) ;
if ( V_5 -> V_13 -> V_88 )
V_5 -> V_13 -> V_88 ( V_5 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
F_4 ( V_8 ) ;
}
static void F_50 ( struct V_9 * V_8 , char V_89 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
unsigned long V_11 ;
if ( V_5 -> V_13 -> V_90 )
V_5 -> V_13 -> V_90 ( V_5 , V_89 ) ;
else {
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_5 -> V_91 = V_89 ;
if ( V_89 )
V_5 -> V_13 -> V_15 ( V_5 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
}
}
static void F_51 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
T_2 V_92 = 0 ;
if ( F_52 ( V_8 ) )
V_92 |= V_93 ;
if ( F_53 ( V_8 ) )
V_92 |= V_94 ;
if ( V_5 -> V_3 & V_92 ) {
V_5 -> V_13 -> V_95 ( V_5 ) ;
V_92 &= ~ V_5 -> V_3 ;
}
if ( V_92 & V_94 )
F_27 ( V_5 , V_35 ) ;
if ( V_92 & V_93 )
F_50 ( V_8 , F_54 ( V_8 ) ) ;
}
static void F_55 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
T_2 V_92 = 0 ;
if ( F_52 ( V_8 ) )
V_92 |= V_93 ;
if ( F_53 ( V_8 ) )
V_92 |= V_94 ;
if ( V_5 -> V_3 & V_92 ) {
V_5 -> V_13 -> V_96 ( V_5 ) ;
V_92 &= ~ V_5 -> V_3 ;
}
if ( V_92 & V_94 )
F_19 ( V_5 , V_35 ) ;
if ( V_92 & V_93 )
F_50 ( V_8 , F_56 ( V_8 ) ) ;
}
static void F_57 ( struct V_38 * V_5 , struct V_97 * V_98 )
{
struct V_6 * V_7 = F_58 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
F_59 ( & V_5 -> V_99 ) ;
V_98 -> type = V_2 -> type ;
V_98 -> line = V_2 -> line ;
V_98 -> V_5 = V_2 -> V_100 ;
if ( V_101 )
V_98 -> V_102 = ( long ) V_2 -> V_100 >> V_101 ;
V_98 -> V_103 = V_2 -> V_103 ;
V_98 -> V_11 = V_2 -> V_11 ;
V_98 -> V_104 = V_2 -> V_51 ;
V_98 -> V_105 = V_2 -> V_69 / 16 ;
V_98 -> V_106 = F_60 ( V_5 -> V_106 ) / 10 ;
V_98 -> V_107 = V_5 -> V_107 == V_108 ?
V_108 :
F_60 ( V_5 -> V_107 ) / 10 ;
V_98 -> V_68 = V_2 -> V_68 ;
V_98 -> V_109 = V_2 -> V_109 ;
V_98 -> V_110 = V_2 -> V_111 ;
V_98 -> V_112 = V_2 -> V_113 ;
V_98 -> V_114 = ( void * ) ( unsigned long ) V_2 -> V_115 ;
F_61 ( & V_5 -> V_99 ) ;
}
static int F_62 ( struct V_38 * V_5 ,
struct V_97 T_3 * V_98 )
{
struct V_97 V_116 ;
F_57 ( V_5 , & V_116 ) ;
if ( F_63 ( V_98 , & V_116 , sizeof( * V_98 ) ) )
return - V_117 ;
return 0 ;
}
static int F_64 ( struct V_9 * V_8 , struct V_38 * V_5 ,
struct V_6 * V_7 ,
struct V_97 * V_118 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
unsigned long V_119 ;
unsigned int V_120 , V_121 , V_107 ;
unsigned int V_122 , V_106 ;
T_1 V_123 , V_124 ;
int V_23 = 0 ;
V_119 = V_118 -> V_5 ;
if ( V_101 )
V_119 += ( unsigned long ) V_118 -> V_102 << V_101 ;
V_118 -> V_103 = F_65 ( V_118 -> V_103 ) ;
V_106 = F_66 ( V_118 -> V_106 * 10 ) ;
V_107 = V_118 -> V_107 == V_108 ?
V_108 :
F_66 ( V_118 -> V_107 * 10 ) ;
V_120 = ! ( V_2 -> V_11 & V_125 )
&& V_118 -> V_103 != V_2 -> V_103 ;
V_121 = ! ( V_2 -> V_11 & V_125 )
&& ( V_119 != V_2 -> V_100 ||
( unsigned long ) V_118 -> V_114 != V_2 -> V_115 ||
V_118 -> V_109 != V_2 -> V_109 ||
V_118 -> V_110 != V_2 -> V_111 ||
V_118 -> V_112 != V_2 -> V_113 ||
V_118 -> type != V_2 -> type ) ;
V_123 = V_2 -> V_11 ;
V_124 = V_118 -> V_11 ;
V_122 = V_2 -> V_68 ;
if ( ! F_20 ( V_37 ) ) {
V_23 = - V_126 ;
if ( V_120 || V_121 ||
( V_118 -> V_105 != V_2 -> V_69 / 16 ) ||
( V_106 != V_5 -> V_106 ) ||
( V_107 != V_5 -> V_107 ) ||
( V_118 -> V_104 &&
V_118 -> V_104 != V_2 -> V_51 ) ||
( ( ( V_124 ^ V_123 ) & ~ V_127 ) != 0 ) )
goto exit;
V_2 -> V_11 = ( ( V_2 -> V_11 & ~ V_127 ) |
( V_124 & V_127 ) ) ;
V_2 -> V_68 = V_118 -> V_68 ;
goto V_128;
}
if ( V_2 -> V_13 -> V_129 )
V_23 = V_2 -> V_13 -> V_129 ( V_2 , V_118 ) ;
if ( ( V_118 -> V_103 >= V_130 ) || ( V_118 -> V_103 < 0 ) ||
( V_118 -> V_105 < 9600 ) )
V_23 = - V_131 ;
if ( V_23 )
goto exit;
if ( V_121 || V_120 ) {
V_23 = - V_132 ;
if ( F_67 ( V_5 ) > 1 )
goto exit;
F_24 ( V_8 , V_7 ) ;
}
if ( V_121 ) {
unsigned long V_133 , V_134 ;
unsigned int V_135 , V_136 , V_137 , V_138 ;
V_133 = V_2 -> V_100 ;
V_134 = V_2 -> V_115 ;
V_135 = V_2 -> type ;
V_137 = V_2 -> V_109 ;
V_136 = V_2 -> V_111 ;
V_138 = V_2 -> V_113 ;
if ( V_135 != V_24 )
V_2 -> V_13 -> V_139 ( V_2 ) ;
V_2 -> V_100 = V_119 ;
V_2 -> type = V_118 -> type ;
V_2 -> V_109 = V_118 -> V_109 ;
V_2 -> V_111 = V_118 -> V_110 ;
V_2 -> V_113 = V_118 -> V_112 ;
V_2 -> V_115 = ( unsigned long ) V_118 -> V_114 ;
if ( V_2 -> type != V_24 ) {
V_23 = V_2 -> V_13 -> V_140 ( V_2 ) ;
} else {
V_23 = 0 ;
}
if ( V_23 ) {
V_2 -> V_100 = V_133 ;
V_2 -> type = V_135 ;
V_2 -> V_109 = V_137 ;
V_2 -> V_111 = V_136 ;
V_2 -> V_113 = V_138 ;
V_2 -> V_115 = V_134 ;
if ( V_135 != V_24 ) {
V_23 = V_2 -> V_13 -> V_140 ( V_2 ) ;
if ( V_23 )
V_2 -> type = V_24 ;
V_23 = - V_132 ;
}
goto exit;
}
}
if ( V_120 )
V_2 -> V_103 = V_118 -> V_103 ;
if ( ! ( V_2 -> V_11 & V_125 ) )
V_2 -> V_69 = V_118 -> V_105 * 16 ;
V_2 -> V_11 = ( V_2 -> V_11 & ~ V_141 ) |
( V_124 & V_141 ) ;
V_2 -> V_68 = V_118 -> V_68 ;
V_5 -> V_106 = V_106 ;
V_5 -> V_107 = V_107 ;
if ( V_118 -> V_104 )
V_2 -> V_51 = V_118 -> V_104 ;
V_5 -> V_142 = ( V_2 -> V_11 & V_143 ) ? 1 : 0 ;
V_128:
V_23 = 0 ;
if ( V_2 -> type == V_24 )
goto exit;
if ( V_5 -> V_11 & V_39 ) {
if ( ( ( V_123 ^ V_2 -> V_11 ) & V_60 ) ||
V_122 != V_2 -> V_68 ) {
if ( V_2 -> V_11 & V_60 ) {
F_68 ( V_2 -> V_144 ,
L_2 ,
V_145 -> V_146 ,
F_69 ( V_5 -> V_8 ) ) ;
}
F_17 ( V_8 , V_7 , NULL ) ;
}
} else
V_23 = F_21 ( V_8 , V_7 , 1 ) ;
exit:
return V_23 ;
}
static int F_70 ( struct V_9 * V_8 , struct V_6 * V_7 ,
struct V_97 T_3 * V_147 )
{
struct V_97 V_148 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
int V_23 ;
if ( F_71 ( & V_148 , V_147 , sizeof( V_148 ) ) )
return - V_117 ;
F_59 ( & V_5 -> V_99 ) ;
V_23 = F_64 ( V_8 , V_5 , V_7 , & V_148 ) ;
F_61 ( & V_5 -> V_99 ) ;
return V_23 ;
}
static int F_72 ( struct V_9 * V_8 ,
struct V_6 * V_7 , unsigned int T_3 * V_149 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
unsigned int V_150 ;
V_150 = V_2 -> V_13 -> V_151 ( V_2 ) ;
if ( V_2 -> V_91 ||
( ( F_47 ( & V_7 -> V_26 ) > 0 ) &&
! F_9 ( V_2 ) ) )
V_150 &= ~ V_152 ;
return F_73 ( V_150 , V_149 ) ;
}
static int F_74 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
struct V_1 * V_2 = V_7 -> V_1 ;
int V_150 = - V_153 ;
F_59 ( & V_5 -> V_99 ) ;
if ( ! ( V_8 -> V_11 & ( 1 << V_40 ) ) ) {
V_150 = V_2 -> V_19 ;
F_37 ( & V_2 -> V_12 ) ;
V_150 |= V_2 -> V_13 -> V_76 ( V_2 ) ;
F_39 ( & V_2 -> V_12 ) ;
}
F_61 ( & V_5 -> V_99 ) ;
return V_150 ;
}
static int
F_75 ( struct V_9 * V_8 , unsigned int V_16 , unsigned int V_17 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
int V_81 = - V_153 ;
F_59 ( & V_5 -> V_99 ) ;
if ( ! ( V_8 -> V_11 & ( 1 << V_40 ) ) ) {
F_11 ( V_2 , V_16 , V_17 ) ;
V_81 = 0 ;
}
F_61 ( & V_5 -> V_99 ) ;
return V_81 ;
}
static int F_76 ( struct V_9 * V_8 , int V_154 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
struct V_1 * V_2 = V_7 -> V_1 ;
F_59 ( & V_5 -> V_99 ) ;
if ( V_2 -> type != V_24 )
V_2 -> V_13 -> V_155 ( V_2 , V_154 ) ;
F_61 ( & V_5 -> V_99 ) ;
return 0 ;
}
static int F_77 ( struct V_9 * V_8 , struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
int V_11 , V_81 ;
if ( ! F_20 ( V_37 ) )
return - V_126 ;
if ( F_78 ( & V_5 -> V_99 ) )
return - V_156 ;
V_81 = - V_132 ;
if ( F_67 ( V_5 ) == 1 ) {
F_24 ( V_8 , V_7 ) ;
if ( V_2 -> type != V_24 )
V_2 -> V_13 -> V_139 ( V_2 ) ;
V_11 = V_157 ;
if ( V_2 -> V_11 & V_158 )
V_11 |= V_159 ;
V_2 -> V_13 -> V_160 ( V_2 , V_11 ) ;
V_81 = F_21 ( V_8 , V_7 , 1 ) ;
}
F_61 ( & V_5 -> V_99 ) ;
return V_81 ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 -> V_161 )
V_2 -> V_13 -> V_161 ( V_2 ) ;
}
static int
F_80 ( struct V_6 * V_7 , unsigned long V_162 )
{
struct V_1 * V_2 = V_7 -> V_1 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
F_81 ( V_163 , V_145 ) ;
struct V_164 V_165 , V_166 ;
int V_81 ;
F_37 ( & V_2 -> V_12 ) ;
memcpy ( & V_165 , & V_2 -> V_167 , sizeof( struct V_164 ) ) ;
F_79 ( V_2 ) ;
F_39 ( & V_2 -> V_12 ) ;
F_82 ( & V_5 -> V_168 , & V_163 ) ;
for (; ; ) {
F_37 ( & V_2 -> V_12 ) ;
memcpy ( & V_166 , & V_2 -> V_167 , sizeof( struct V_164 ) ) ;
F_39 ( & V_2 -> V_12 ) ;
F_83 ( V_169 ) ;
if ( ( ( V_162 & V_170 ) && ( V_166 . V_171 != V_165 . V_171 ) ) ||
( ( V_162 & V_172 ) && ( V_166 . V_173 != V_165 . V_173 ) ) ||
( ( V_162 & V_174 ) && ( V_166 . V_175 != V_165 . V_175 ) ) ||
( ( V_162 & V_77 ) && ( V_166 . V_176 != V_165 . V_176 ) ) ) {
V_81 = 0 ;
break;
}
F_84 () ;
if ( F_85 ( V_145 ) ) {
V_81 = - V_156 ;
break;
}
V_165 = V_166 ;
}
F_86 ( V_177 ) ;
F_87 ( & V_5 -> V_168 , & V_163 ) ;
return V_81 ;
}
static int F_88 ( struct V_9 * V_8 ,
struct V_178 * V_167 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_164 V_166 ;
struct V_1 * V_2 = V_7 -> V_1 ;
F_37 ( & V_2 -> V_12 ) ;
memcpy ( & V_166 , & V_2 -> V_167 , sizeof( struct V_164 ) ) ;
F_39 ( & V_2 -> V_12 ) ;
V_167 -> V_176 = V_166 . V_176 ;
V_167 -> V_173 = V_166 . V_173 ;
V_167 -> V_171 = V_166 . V_171 ;
V_167 -> V_175 = V_166 . V_175 ;
V_167 -> V_179 = V_166 . V_179 ;
V_167 -> V_180 = V_166 . V_180 ;
V_167 -> V_181 = V_166 . V_181 ;
V_167 -> V_182 = V_166 . V_182 ;
V_167 -> V_183 = V_166 . V_183 ;
V_167 -> V_184 = V_166 . V_184 ;
V_167 -> V_185 = V_166 . V_185 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_5 ,
struct V_186 T_3 * V_187 )
{
unsigned long V_11 ;
struct V_186 V_188 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_188 = V_5 -> V_187 ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
if ( F_63 ( V_187 , & V_188 , sizeof( V_188 ) ) )
return - V_117 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_5 ,
struct V_186 T_3 * V_189 )
{
struct V_186 V_187 ;
int V_81 ;
unsigned long V_11 ;
if ( ! V_5 -> V_190 )
return - V_191 ;
if ( F_71 ( & V_187 , V_189 , sizeof( * V_189 ) ) )
return - V_117 ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_81 = V_5 -> V_190 ( V_5 , & V_187 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
if ( V_81 )
return V_81 ;
if ( F_63 ( V_189 , & V_5 -> V_187 , sizeof( V_5 -> V_187 ) ) )
return - V_117 ;
return 0 ;
}
static int
F_91 ( struct V_9 * V_8 , unsigned int V_192 ,
unsigned long V_162 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
void T_3 * V_193 = ( void T_3 * ) V_162 ;
int V_81 = - V_191 ;
switch ( V_192 ) {
case V_194 :
V_81 = F_62 ( V_5 , V_193 ) ;
break;
case V_195 :
F_92 ( & V_8 -> V_196 ) ;
V_81 = F_70 ( V_8 , V_7 , V_193 ) ;
F_93 ( & V_8 -> V_196 ) ;
break;
case V_197 :
F_92 ( & V_8 -> V_196 ) ;
V_81 = F_77 ( V_8 , V_7 ) ;
F_93 ( & V_8 -> V_196 ) ;
break;
case V_198 :
case V_199 :
V_81 = 0 ;
break;
}
if ( V_81 != - V_191 )
goto V_200;
if ( V_8 -> V_11 & ( 1 << V_40 ) ) {
V_81 = - V_153 ;
goto V_200;
}
switch ( V_192 ) {
case V_201 :
V_81 = F_80 ( V_7 , V_162 ) ;
break;
}
if ( V_81 != - V_191 )
goto V_200;
F_59 ( & V_5 -> V_99 ) ;
if ( V_8 -> V_11 & ( 1 << V_40 ) ) {
V_81 = - V_153 ;
goto V_202;
}
switch ( V_192 ) {
case V_203 :
V_81 = F_72 ( V_8 , V_7 , V_193 ) ;
break;
case V_204 :
V_81 = F_89 ( V_7 -> V_1 , V_193 ) ;
break;
case V_205 :
V_81 = F_90 ( V_7 -> V_1 , V_193 ) ;
break;
default: {
struct V_1 * V_2 = V_7 -> V_1 ;
if ( V_2 -> V_13 -> V_206 )
V_81 = V_2 -> V_13 -> V_206 ( V_2 , V_192 , V_162 ) ;
break;
}
}
V_202:
F_61 ( & V_5 -> V_99 ) ;
V_200:
return V_81 ;
}
static void F_94 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_1 ;
if ( V_2 -> V_13 -> V_207 ) {
F_59 ( & V_7 -> V_5 . V_99 ) ;
V_2 -> V_13 -> V_207 ( V_2 , & V_8 -> V_33 ) ;
F_61 ( & V_7 -> V_5 . V_99 ) ;
}
}
static void F_95 ( struct V_9 * V_8 ,
struct V_54 * V_70 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_2 = V_7 -> V_1 ;
unsigned int V_32 = V_8 -> V_33 . V_34 ;
unsigned int V_208 = V_209 | V_210 | V_211 | V_212 | V_213 ;
bool V_214 = false ;
if ( V_2 -> V_11 & V_215 ) {
V_208 |= V_216 | V_217 | V_218 ;
V_214 =
V_8 -> V_33 . V_219 [ V_220 ] != V_70 -> V_219 [ V_220 ] ||
V_8 -> V_33 . V_219 [ V_221 ] != V_70 -> V_219 [ V_221 ] ;
}
if ( ( V_32 ^ V_70 -> V_34 ) == 0 &&
V_8 -> V_33 . V_222 == V_70 -> V_222 &&
V_8 -> V_33 . V_223 == V_70 -> V_223 &&
( ( V_8 -> V_33 . V_224 ^ V_70 -> V_224 ) & V_208 ) == 0 &&
! V_214 ) {
return;
}
F_59 ( & V_7 -> V_5 . V_99 ) ;
F_17 ( V_8 , V_7 , V_70 ) ;
F_61 ( & V_7 -> V_5 . V_99 ) ;
V_32 = V_8 -> V_33 . V_34 ;
if ( ( V_70 -> V_34 & V_65 ) && ! ( V_32 & V_65 ) )
F_27 ( V_2 , V_35 | V_36 ) ;
else if ( ! ( V_70 -> V_34 & V_65 ) && ( V_32 & V_65 ) ) {
unsigned int V_92 = V_36 ;
if ( ! ( V_32 & V_73 ) || ! F_96 ( V_225 , & V_8 -> V_11 ) )
V_92 |= V_35 ;
F_19 ( V_2 , V_92 ) ;
}
}
static void F_97 ( struct V_9 * V_8 , struct V_226 * V_227 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_38 * V_5 ;
struct V_1 * V_2 ;
if ( ! V_7 ) {
struct V_228 * V_229 = V_8 -> V_230 -> V_231 ;
V_7 = V_229 -> V_7 + V_8 -> V_87 ;
V_5 = & V_7 -> V_5 ;
F_37 ( & V_5 -> V_12 ) ;
-- V_5 -> V_84 ;
F_39 ( & V_5 -> V_12 ) ;
return;
}
V_2 = V_7 -> V_1 ;
V_5 = & V_7 -> V_5 ;
F_49 ( L_3 , V_8 -> V_87 ) ;
if ( ! V_5 -> V_84 || F_98 ( V_5 , V_8 , V_227 ) == 0 )
return;
if ( V_5 -> V_11 & V_39 ) {
F_37 ( & V_2 -> V_12 ) ;
V_2 -> V_13 -> V_232 ( V_2 ) ;
F_39 ( & V_2 -> V_12 ) ;
F_99 ( V_8 , V_2 -> V_52 ) ;
}
F_59 ( & V_5 -> V_99 ) ;
F_24 ( V_8 , V_7 ) ;
F_100 ( V_5 , NULL ) ;
F_37 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_233 ) {
F_39 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_106 )
F_101 ( F_60 ( V_5 -> V_106 ) ) ;
F_37 ( & V_5 -> V_12 ) ;
} else if ( ! F_16 ( V_2 ) ) {
F_39 ( & V_5 -> V_12 ) ;
F_13 ( V_7 , V_234 ) ;
F_37 ( & V_5 -> V_12 ) ;
}
F_23 ( V_235 , & V_5 -> V_11 ) ;
F_39 ( & V_5 -> V_12 ) ;
F_102 ( & V_5 -> V_236 ) ;
F_61 ( & V_5 -> V_99 ) ;
F_103 ( V_8 ) ;
V_8 -> V_237 = 0 ;
}
static void F_99 ( struct V_9 * V_8 , int V_52 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_1 * V_5 = V_7 -> V_1 ;
unsigned long V_238 , V_239 ;
if ( V_5 -> type == V_24 || V_5 -> V_51 == 0 )
return;
V_238 = ( V_5 -> V_52 - V_53 / 50 ) / V_5 -> V_51 ;
V_238 = V_238 / 5 ;
if ( V_238 == 0 )
V_238 = 1 ;
if ( V_52 && V_52 < V_238 )
V_238 = V_52 ;
if ( V_52 == 0 || V_52 > 2 * V_5 -> V_52 )
V_52 = 2 * V_5 -> V_52 ;
V_239 = V_240 + V_52 ;
F_49 ( L_4 ,
V_5 -> line , V_240 , V_239 ) ;
while ( ! V_5 -> V_13 -> V_151 ( V_5 ) ) {
F_101 ( F_60 ( V_238 ) ) ;
if ( F_85 ( V_145 ) )
break;
if ( F_104 ( V_240 , V_239 ) )
break;
}
}
static void F_105 ( struct V_9 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_10 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
unsigned long V_11 ;
F_49 ( L_5 , V_8 -> V_87 ) ;
F_59 ( & V_5 -> V_99 ) ;
if ( V_5 -> V_11 & V_241 ) {
F_48 ( V_8 ) ;
F_24 ( V_8 , V_7 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_5 -> V_84 = 0 ;
F_23 ( V_235 , & V_5 -> V_11 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
F_100 ( V_5 , NULL ) ;
if ( ! F_16 ( V_7 -> V_1 ) )
F_13 ( V_7 , V_234 ) ;
F_102 ( & V_5 -> V_236 ) ;
F_102 ( & V_5 -> V_168 ) ;
}
F_61 ( & V_5 -> V_99 ) ;
}
static void F_28 ( struct V_38 * V_5 )
{
struct V_6 * V_7 = F_58 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
F_102 ( & V_5 -> V_168 ) ;
V_2 -> V_13 -> V_242 ( V_2 ) ;
F_106 ( V_2 -> V_103 ) ;
}
static int F_107 ( struct V_38 * V_5 )
{
struct V_6 * V_7 = F_58 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
int V_19 ;
F_37 ( & V_2 -> V_12 ) ;
F_79 ( V_2 ) ;
V_19 = V_2 -> V_13 -> V_76 ( V_2 ) ;
F_39 ( & V_2 -> V_12 ) ;
if ( V_19 & V_243 )
return 1 ;
return 0 ;
}
static void F_108 ( struct V_38 * V_5 , int V_244 )
{
struct V_6 * V_7 = F_58 ( V_5 , struct V_6 , V_5 ) ;
struct V_1 * V_2 = V_7 -> V_1 ;
if ( V_244 )
F_19 ( V_2 , V_36 | V_35 ) ;
else
F_27 ( V_2 , V_36 | V_35 ) ;
}
static int F_109 ( struct V_9 * V_8 , struct V_226 * V_227 )
{
struct V_228 * V_229 = V_8 -> V_230 -> V_231 ;
int V_23 , line = V_8 -> V_87 ;
struct V_6 * V_7 = V_229 -> V_7 + line ;
struct V_38 * V_5 = & V_7 -> V_5 ;
F_49 ( L_6 , line ) ;
F_37 ( & V_5 -> V_12 ) ;
++ V_5 -> V_84 ;
F_39 ( & V_5 -> V_12 ) ;
if ( F_78 ( & V_5 -> V_99 ) ) {
V_23 = - V_156 ;
goto V_245;
}
if ( ! V_7 -> V_1 || V_7 -> V_1 -> V_11 & V_246 ) {
V_23 = - V_247 ;
goto V_248;
}
V_8 -> V_10 = V_7 ;
V_7 -> V_1 -> V_7 = V_7 ;
V_7 -> V_5 . V_142 =
( V_7 -> V_1 -> V_11 & V_143 ) ? 1 : 0 ;
F_100 ( V_5 , V_8 ) ;
V_23 = F_21 ( V_8 , V_7 , 0 ) ;
V_248:
F_61 ( & V_5 -> V_99 ) ;
if ( V_23 == 0 )
V_23 = F_110 ( V_5 , V_8 , V_227 ) ;
V_245:
return V_23 ;
}
static const char * F_111 ( struct V_1 * V_5 )
{
const char * V_249 = NULL ;
if ( V_5 -> V_13 -> type )
V_249 = V_5 -> V_13 -> type ( V_5 ) ;
if ( ! V_249 )
V_249 = L_7 ;
return V_249 ;
}
static void F_112 ( struct V_250 * V_251 , struct V_228 * V_229 , int V_252 )
{
struct V_6 * V_7 = V_229 -> V_7 + V_252 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
enum V_253 V_254 ;
struct V_1 * V_2 = V_7 -> V_1 ;
char V_255 [ 32 ] ;
unsigned int V_3 ;
int V_256 ;
if ( ! V_2 )
return;
V_256 = V_2 -> V_111 >= V_257 ;
F_113 ( V_251 , L_8 ,
V_2 -> line , F_111 ( V_2 ) ,
V_256 ? L_9 : L_10 ,
V_256 ? ( unsigned long long ) V_2 -> V_115
: ( unsigned long long ) V_2 -> V_100 ,
V_2 -> V_103 ) ;
if ( V_2 -> type == V_24 ) {
F_114 ( V_251 , '\n' ) ;
return;
}
if ( F_20 ( V_37 ) ) {
F_59 ( & V_5 -> V_99 ) ;
V_254 = V_7 -> V_254 ;
if ( V_254 != V_25 )
F_13 ( V_7 , V_25 ) ;
F_37 ( & V_2 -> V_12 ) ;
V_3 = V_2 -> V_13 -> V_76 ( V_2 ) ;
F_39 ( & V_2 -> V_12 ) ;
if ( V_254 != V_25 )
F_13 ( V_7 , V_254 ) ;
F_61 ( & V_5 -> V_99 ) ;
F_113 ( V_251 , L_11 ,
V_2 -> V_167 . V_180 , V_2 -> V_167 . V_179 ) ;
if ( V_2 -> V_167 . V_181 )
F_113 ( V_251 , L_12 , V_2 -> V_167 . V_181 ) ;
if ( V_2 -> V_167 . V_183 )
F_113 ( V_251 , L_13 , V_2 -> V_167 . V_183 ) ;
if ( V_2 -> V_167 . V_184 )
F_113 ( V_251 , L_14 , V_2 -> V_167 . V_184 ) ;
if ( V_2 -> V_167 . V_182 )
F_113 ( V_251 , L_15 , V_2 -> V_167 . V_182 ) ;
#define F_115 ( T_4 , V_249 ) \
if (uport->mctrl & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
#define F_116 ( T_4 , V_249 ) \
if (status & (bit)) \
strncat(stat_buf, (str), sizeof(stat_buf) - \
strlen(stat_buf) - 2)
V_255 [ 0 ] = '\0' ;
V_255 [ 1 ] = '\0' ;
F_115 ( V_35 , L_16 ) ;
F_116 ( V_77 , L_17 ) ;
F_115 ( V_36 , L_18 ) ;
F_116 ( V_172 , L_19 ) ;
F_116 ( V_243 , L_20 ) ;
F_116 ( V_170 , L_21 ) ;
if ( V_255 [ 0 ] )
V_255 [ 0 ] = ' ' ;
F_117 ( V_251 , V_255 ) ;
}
F_114 ( V_251 , '\n' ) ;
#undef F_116
#undef F_115
}
static int F_118 ( struct V_250 * V_251 , void * V_258 )
{
struct V_259 * V_260 = V_251 -> V_261 ;
struct V_228 * V_229 = V_260 -> V_231 ;
int V_252 ;
F_113 ( V_251 , L_22 , L_23 , L_23 , L_23 ) ;
for ( V_252 = 0 ; V_252 < V_229 -> V_262 ; V_252 ++ )
F_112 ( V_251 , V_229 , V_252 ) ;
return 0 ;
}
static int F_119 ( struct V_263 * V_263 , struct V_226 * V_226 )
{
return F_120 ( V_226 , F_118 , F_121 ( V_263 ) ) ;
}
void F_122 ( struct V_1 * V_5 , const char * V_264 ,
unsigned int V_84 ,
void (* putchar)( struct V_1 * , int ) )
{
unsigned int V_252 ;
for ( V_252 = 0 ; V_252 < V_84 ; V_252 ++ , V_264 ++ ) {
if ( * V_264 == '\n' )
putchar ( V_5 , '\r' ) ;
putchar ( V_5 , * V_264 ) ;
}
}
struct V_1 * T_5
F_123 ( struct V_1 * V_265 , int V_262 , struct V_266 * V_267 )
{
int V_268 = V_267 -> V_87 ;
if ( V_268 < 0 || V_268 >= V_262 || ( V_265 [ V_268 ] . V_100 == 0 &&
V_265 [ V_268 ] . V_269 == NULL ) )
for ( V_268 = 0 ; V_268 < V_262 ; V_268 ++ )
if ( V_265 [ V_268 ] . V_100 != 0 ||
V_265 [ V_268 ] . V_269 != NULL )
break;
V_267 -> V_87 = V_268 ;
return V_265 + V_268 ;
}
int F_124 ( char * V_270 , unsigned char * V_111 , unsigned long * V_271 ,
char * * V_272 )
{
if ( strncmp ( V_270 , L_24 , 5 ) == 0 ) {
* V_111 = V_257 ;
V_270 += 5 ;
} else if ( strncmp ( V_270 , L_25 , 7 ) == 0 ) {
* V_111 = V_273 ;
V_270 += 7 ;
} else if ( strncmp ( V_270 , L_26 , 7 ) == 0 ) {
* V_111 = V_274 ;
V_270 += 7 ;
} else if ( strncmp ( V_270 , L_27 , 9 ) == 0 ) {
* V_111 = V_275 ;
V_270 += 9 ;
} else if ( strncmp ( V_270 , L_28 , 13 ) == 0 ) {
* V_111 = F_125 ( V_276 ) ?
V_275 : V_274 ;
V_270 += 13 ;
} else if ( strncmp ( V_270 , L_29 , 3 ) == 0 ) {
* V_111 = V_277 ;
V_270 += 3 ;
} else if ( strncmp ( V_270 , L_30 , 2 ) == 0 ) {
* V_111 = V_257 ;
} else {
return - V_131 ;
}
* V_271 = F_126 ( V_270 , NULL , 0 ) ;
V_270 = strchr ( V_270 , ',' ) ;
if ( V_270 )
V_270 ++ ;
* V_272 = V_270 ;
return 0 ;
}
void
F_127 ( char * V_272 , int * V_43 , int * V_183 , int * V_44 , int * V_278 )
{
char * V_264 = V_272 ;
* V_43 = F_126 ( V_264 , NULL , 10 ) ;
while ( * V_264 >= '0' && * V_264 <= '9' )
V_264 ++ ;
if ( * V_264 )
* V_183 = * V_264 ++ ;
if ( * V_264 )
* V_44 = * V_264 ++ - '0' ;
if ( * V_264 )
* V_278 = * V_264 ;
}
int
F_128 ( struct V_1 * V_5 , struct V_266 * V_267 ,
int V_43 , int V_183 , int V_44 , int V_278 )
{
struct V_54 V_33 ;
static struct V_54 V_279 ;
if ( ! ( F_16 ( V_5 ) && ( V_5 -> V_31 -> V_11 & V_280 ) ) ) {
F_129 ( & V_5 -> V_12 ) ;
F_130 ( & V_5 -> V_12 , & V_281 ) ;
}
memset ( & V_33 , 0 , sizeof( struct V_54 ) ) ;
V_33 . V_34 |= V_282 | V_283 | V_75 ;
F_33 ( & V_33 , V_43 , V_43 ) ;
if ( V_44 == 7 )
V_33 . V_34 |= V_48 ;
else
V_33 . V_34 |= V_284 ;
switch ( V_183 ) {
case 'o' : case 'O' :
V_33 . V_34 |= V_285 ;
case 'e' : case 'E' :
V_33 . V_34 |= V_50 ;
break;
}
if ( V_278 == 'r' )
V_33 . V_34 |= V_73 ;
V_5 -> V_19 |= V_36 ;
V_5 -> V_13 -> V_72 ( V_5 , & V_33 , & V_279 ) ;
if ( V_267 )
V_267 -> V_32 = V_33 . V_34 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_7 ,
enum V_253 V_254 )
{
struct V_1 * V_5 = V_7 -> V_1 ;
if ( V_7 -> V_254 != V_254 ) {
if ( V_5 -> V_13 -> V_286 )
V_5 -> V_13 -> V_286 ( V_5 , V_254 , V_7 -> V_254 ) ;
V_7 -> V_254 = V_254 ;
}
}
static int F_131 ( struct V_287 * V_144 , void * V_288 )
{
struct V_289 * V_290 = V_288 ;
struct V_259 * V_291 = V_290 -> V_230 -> V_259 ;
T_6 V_292 = F_132 ( V_291 -> V_293 , V_291 -> V_294 ) +
V_290 -> V_5 -> line ;
return V_144 -> V_292 == V_292 ;
}
int F_133 ( struct V_228 * V_229 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_229 -> V_7 + V_2 -> line ;
struct V_38 * V_5 = & V_7 -> V_5 ;
struct V_287 * V_295 ;
struct V_289 V_290 = { V_2 , V_229 } ;
F_59 ( & V_5 -> V_99 ) ;
V_295 = F_134 ( V_2 -> V_144 , & V_290 , F_131 ) ;
if ( F_135 ( V_295 ) ) {
if ( ! F_136 ( V_2 -> V_103 ) )
V_2 -> V_296 = 1 ;
F_137 ( V_295 ) ;
F_61 ( & V_5 -> V_99 ) ;
return 0 ;
}
F_137 ( V_295 ) ;
if ( ! V_297 && F_16 ( V_2 ) )
goto V_298;
V_2 -> V_299 = 1 ;
if ( V_5 -> V_11 & V_39 ) {
const struct V_300 * V_13 = V_2 -> V_13 ;
int V_301 ;
F_22 ( V_42 , & V_5 -> V_11 ) ;
F_23 ( V_41 , & V_5 -> V_11 ) ;
F_37 ( & V_2 -> V_12 ) ;
V_13 -> V_14 ( V_2 ) ;
V_13 -> V_20 ( V_2 , 0 ) ;
V_13 -> V_232 ( V_2 ) ;
F_39 ( & V_2 -> V_12 ) ;
for ( V_301 = 3 ; ! V_13 -> V_151 ( V_2 ) && V_301 ; V_301 -- )
F_138 ( 10 ) ;
if ( ! V_301 )
F_139 ( V_2 -> V_144 , L_31 ,
V_229 -> V_302 ,
V_229 -> V_259 -> V_303 + V_2 -> line ) ;
V_13 -> V_242 ( V_2 ) ;
}
if ( F_16 ( V_2 ) )
F_140 ( V_2 -> V_31 ) ;
F_13 ( V_7 , V_234 ) ;
V_298:
F_61 ( & V_5 -> V_99 ) ;
return 0 ;
}
int F_141 ( struct V_228 * V_229 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_229 -> V_7 + V_2 -> line ;
struct V_38 * V_5 = & V_7 -> V_5 ;
struct V_287 * V_295 ;
struct V_289 V_290 = { V_2 , V_229 } ;
struct V_54 V_33 ;
F_59 ( & V_5 -> V_99 ) ;
V_295 = F_134 ( V_2 -> V_144 , & V_290 , F_131 ) ;
if ( ! V_2 -> V_299 && F_135 ( V_295 ) ) {
if ( V_2 -> V_296 ) {
F_142 ( V_2 -> V_103 ) ;
V_2 -> V_296 = 0 ;
}
F_137 ( V_295 ) ;
F_61 ( & V_5 -> V_99 ) ;
return 0 ;
}
F_137 ( V_295 ) ;
V_2 -> V_299 = 0 ;
if ( F_16 ( V_2 ) ) {
memset ( & V_33 , 0 , sizeof( struct V_54 ) ) ;
V_33 . V_34 = V_2 -> V_31 -> V_32 ;
if ( V_5 -> V_8 && V_33 . V_34 == 0 )
V_33 = V_5 -> V_8 -> V_33 ;
if ( V_297 )
F_13 ( V_7 , V_25 ) ;
V_2 -> V_13 -> V_72 ( V_2 , & V_33 , NULL ) ;
if ( V_297 )
F_143 ( V_2 -> V_31 ) ;
}
if ( V_5 -> V_11 & V_304 ) {
const struct V_300 * V_13 = V_2 -> V_13 ;
int V_81 ;
F_13 ( V_7 , V_25 ) ;
F_37 ( & V_2 -> V_12 ) ;
V_13 -> V_20 ( V_2 , 0 ) ;
F_39 ( & V_2 -> V_12 ) ;
if ( V_297 || ! F_16 ( V_2 ) ) {
struct V_9 * V_8 = V_5 -> V_8 ;
V_81 = V_13 -> V_30 ( V_2 ) ;
if ( V_81 == 0 ) {
if ( V_8 )
F_17 ( V_8 , V_7 , NULL ) ;
F_37 ( & V_2 -> V_12 ) ;
V_13 -> V_20 ( V_2 , V_2 -> V_19 ) ;
V_13 -> V_15 ( V_2 ) ;
F_39 ( & V_2 -> V_12 ) ;
F_22 ( V_41 , & V_5 -> V_11 ) ;
} else {
F_24 ( V_8 , V_7 ) ;
}
}
F_23 ( V_42 , & V_5 -> V_11 ) ;
}
F_61 ( & V_5 -> V_99 ) ;
return 0 ;
}
static inline void
F_144 ( struct V_228 * V_229 , struct V_1 * V_5 )
{
char V_305 [ 64 ] ;
switch ( V_5 -> V_111 ) {
case V_277 :
snprintf ( V_305 , sizeof( V_305 ) , L_32 , V_5 -> V_100 ) ;
break;
case V_306 :
snprintf ( V_305 , sizeof( V_305 ) ,
L_33 , V_5 -> V_100 , V_5 -> V_109 ) ;
break;
case V_257 :
case V_273 :
case V_274 :
case V_275 :
case V_307 :
case V_308 :
snprintf ( V_305 , sizeof( V_305 ) ,
L_34 , ( unsigned long long ) V_5 -> V_115 ) ;
break;
default:
F_145 ( V_305 , L_35 , sizeof( V_305 ) ) ;
break;
}
F_146 ( V_309 L_36 ,
V_5 -> V_144 ? V_302 ( V_5 -> V_144 ) : L_23 ,
V_5 -> V_144 ? L_37 : L_23 ,
V_229 -> V_302 ,
V_229 -> V_259 -> V_303 + V_5 -> line ,
V_305 , V_5 -> V_103 , V_5 -> V_69 / 16 , F_111 ( V_5 ) ) ;
}
static void
F_147 ( struct V_228 * V_229 , struct V_6 * V_7 ,
struct V_1 * V_5 )
{
unsigned int V_11 ;
if ( ! V_5 -> V_100 && ! V_5 -> V_115 && ! V_5 -> V_269 )
return;
V_11 = 0 ;
if ( V_5 -> V_11 & V_158 )
V_11 |= V_159 ;
if ( V_5 -> V_11 & V_310 ) {
if ( ! ( V_5 -> V_11 & V_311 ) ) {
V_5 -> type = V_24 ;
V_11 |= V_157 ;
}
V_5 -> V_13 -> V_160 ( V_5 , V_11 ) ;
}
if ( V_5 -> type != V_24 ) {
unsigned long V_11 ;
F_144 ( V_229 , V_5 ) ;
F_13 ( V_7 , V_25 ) ;
F_6 ( & V_5 -> V_12 , V_11 ) ;
V_5 -> V_13 -> V_20 ( V_5 , V_5 -> V_19 & V_36 ) ;
F_7 ( & V_5 -> V_12 , V_11 ) ;
if ( V_5 -> V_31 && ! ( V_5 -> V_31 -> V_11 & V_280 ) )
F_148 ( V_5 -> V_31 ) ;
if ( ! F_16 ( V_5 ) )
F_13 ( V_7 , V_234 ) ;
}
}
static int F_149 ( struct V_259 * V_230 , int line , char * V_272 )
{
struct V_228 * V_229 = V_230 -> V_231 ;
struct V_6 * V_7 = V_229 -> V_7 + line ;
struct V_1 * V_5 ;
int V_43 = 9600 ;
int V_44 = 8 ;
int V_183 = 'n' ;
int V_278 = 'n' ;
int V_81 ;
if ( ! V_7 || ! V_7 -> V_1 )
return - 1 ;
V_5 = V_7 -> V_1 ;
if ( ! ( V_5 -> V_13 -> V_312 && V_5 -> V_13 -> V_313 ) )
return - 1 ;
if ( V_5 -> V_13 -> V_314 ) {
struct V_38 * V_315 = & V_7 -> V_5 ;
V_81 = 0 ;
F_59 ( & V_315 -> V_99 ) ;
if ( ! F_96 ( V_41 , & V_315 -> V_11 ) )
V_81 = V_5 -> V_13 -> V_314 ( V_5 ) ;
F_61 ( & V_315 -> V_99 ) ;
if ( V_81 )
return V_81 ;
}
if ( V_272 ) {
F_127 ( V_272 , & V_43 , & V_183 , & V_44 , & V_278 ) ;
return F_128 ( V_5 , NULL , V_43 , V_183 , V_44 , V_278 ) ;
}
return 0 ;
}
static int F_150 ( struct V_259 * V_230 , int line )
{
struct V_228 * V_229 = V_230 -> V_231 ;
struct V_6 * V_7 = V_229 -> V_7 + line ;
struct V_1 * V_5 ;
if ( ! V_7 || ! V_7 -> V_1 )
return - 1 ;
V_5 = V_7 -> V_1 ;
return V_5 -> V_13 -> V_312 ( V_5 ) ;
}
static void F_151 ( struct V_259 * V_230 , int line , char V_89 )
{
struct V_228 * V_229 = V_230 -> V_231 ;
struct V_6 * V_7 = V_229 -> V_7 + line ;
struct V_1 * V_5 ;
if ( ! V_7 || ! V_7 -> V_1 )
return;
V_5 = V_7 -> V_1 ;
if ( V_89 == '\n' )
V_5 -> V_13 -> V_313 ( V_5 , '\r' ) ;
V_5 -> V_13 -> V_313 ( V_5 , V_89 ) ;
}
int F_152 ( struct V_228 * V_229 )
{
struct V_259 * V_316 ;
int V_252 , V_23 ;
F_3 ( V_229 -> V_7 ) ;
V_229 -> V_7 = F_153 ( sizeof( struct V_6 ) * V_229 -> V_262 , V_28 ) ;
if ( ! V_229 -> V_7 )
goto V_200;
V_316 = F_154 ( V_229 -> V_262 ) ;
if ( ! V_316 )
goto V_317;
V_229 -> V_259 = V_316 ;
V_316 -> V_318 = V_229 -> V_318 ;
V_316 -> V_319 = V_229 -> V_302 ;
V_316 -> V_293 = V_229 -> V_293 ;
V_316 -> V_294 = V_229 -> V_320 ;
V_316 -> type = V_321 ;
V_316 -> V_322 = V_323 ;
V_316 -> V_324 = V_325 ;
V_316 -> V_324 . V_34 = V_326 | V_284 | V_282 | V_283 | V_75 ;
V_316 -> V_324 . V_223 = V_316 -> V_324 . V_222 = 9600 ;
V_316 -> V_11 = V_327 | V_328 ;
V_316 -> V_231 = V_229 ;
F_155 ( V_316 , & V_300 ) ;
for ( V_252 = 0 ; V_252 < V_229 -> V_262 ; V_252 ++ ) {
struct V_6 * V_7 = V_229 -> V_7 + V_252 ;
struct V_38 * V_5 = & V_7 -> V_5 ;
F_156 ( V_5 ) ;
V_5 -> V_13 = & V_329 ;
}
V_23 = F_157 ( V_316 ) ;
if ( V_23 >= 0 )
return V_23 ;
for ( V_252 = 0 ; V_252 < V_229 -> V_262 ; V_252 ++ )
F_158 ( & V_229 -> V_7 [ V_252 ] . V_5 ) ;
F_159 ( V_316 ) ;
V_317:
F_160 ( V_229 -> V_7 ) ;
V_200:
return - V_29 ;
}
void F_161 ( struct V_228 * V_229 )
{
struct V_259 * V_270 = V_229 -> V_259 ;
unsigned int V_252 ;
F_162 ( V_270 ) ;
F_159 ( V_270 ) ;
for ( V_252 = 0 ; V_252 < V_229 -> V_262 ; V_252 ++ )
F_158 ( & V_229 -> V_7 [ V_252 ] . V_5 ) ;
F_160 ( V_229 -> V_7 ) ;
V_229 -> V_7 = NULL ;
V_229 -> V_259 = NULL ;
}
struct V_259 * F_163 ( struct V_266 * V_267 , int * V_87 )
{
struct V_228 * V_270 = V_267 -> V_288 ;
* V_87 = V_267 -> V_87 ;
return V_270 -> V_259 ;
}
static T_7 F_164 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . V_105 * 16 ) ;
}
static T_7 F_166 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . type ) ;
}
static T_7 F_167 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . line ) ;
}
static T_7 F_168 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
unsigned long V_333 ;
F_57 ( V_5 , & V_116 ) ;
V_333 = V_116 . V_5 ;
if ( V_101 )
V_333 |= ( unsigned long ) V_116 . V_102 << V_101 ;
return snprintf ( V_27 , V_332 , L_39 , V_333 ) ;
}
static T_7 F_169 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . V_103 ) ;
}
static T_7 F_170 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_40 , V_116 . V_11 ) ;
}
static T_7 F_171 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . V_104 ) ;
}
static T_7 F_172 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . V_106 ) ;
}
static T_7 F_173 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . V_107 ) ;
}
static T_7 F_174 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . V_68 ) ;
}
static T_7 F_175 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . V_110 ) ;
}
static T_7 F_176 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_39 , ( unsigned long ) V_116 . V_114 ) ;
}
static T_7 F_177 ( struct V_287 * V_144 ,
struct V_330 * V_331 , char * V_27 )
{
struct V_97 V_116 ;
struct V_38 * V_5 = F_165 ( V_144 ) ;
F_57 ( V_5 , & V_116 ) ;
return snprintf ( V_27 , V_332 , L_38 , V_116 . V_112 ) ;
}
int F_178 ( struct V_228 * V_229 , struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_38 * V_5 ;
int V_81 = 0 ;
struct V_287 * V_295 ;
int V_334 ;
F_3 ( F_179 () ) ;
if ( V_2 -> line >= V_229 -> V_262 )
return - V_131 ;
V_7 = V_229 -> V_7 + V_2 -> line ;
V_5 = & V_7 -> V_5 ;
F_59 ( & V_335 ) ;
F_59 ( & V_5 -> V_99 ) ;
if ( V_7 -> V_1 ) {
V_81 = - V_131 ;
goto V_200;
}
V_7 -> V_1 = V_2 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_254 = V_336 ;
V_2 -> V_31 = V_229 -> V_31 ;
V_2 -> V_320 = V_229 -> V_259 -> V_294 + V_2 -> line ;
if ( ! ( F_16 ( V_2 ) && ( V_2 -> V_31 -> V_11 & V_280 ) ) ) {
F_129 ( & V_2 -> V_12 ) ;
F_130 ( & V_2 -> V_12 , & V_281 ) ;
}
if ( V_2 -> V_31 && V_2 -> V_144 )
F_180 ( V_2 -> V_144 -> V_337 , V_2 -> V_31 -> V_319 , V_2 -> line ) ;
F_147 ( V_229 , V_7 , V_2 ) ;
V_334 = 2 ;
if ( V_2 -> V_338 )
V_334 ++ ;
V_2 -> V_339 = F_181 ( V_334 , sizeof( * V_2 -> V_339 ) ,
V_28 ) ;
if ( ! V_2 -> V_339 ) {
V_81 = - V_29 ;
goto V_200;
}
V_2 -> V_339 [ 0 ] = & V_340 ;
if ( V_2 -> V_338 )
V_2 -> V_339 [ 1 ] = V_2 -> V_338 ;
V_295 = F_182 ( V_5 , V_229 -> V_259 ,
V_2 -> line , V_2 -> V_144 , V_5 , V_2 -> V_339 ) ;
if ( F_183 ( ! F_184 ( V_295 ) ) ) {
F_185 ( V_295 , 1 ) ;
} else {
F_139 ( V_2 -> V_144 , L_41 ,
V_2 -> line ) ;
}
V_2 -> V_11 &= ~ V_246 ;
V_200:
F_61 ( & V_5 -> V_99 ) ;
F_61 ( & V_335 ) ;
return V_81 ;
}
int F_186 ( struct V_228 * V_229 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_229 -> V_7 + V_2 -> line ;
struct V_38 * V_5 = & V_7 -> V_5 ;
struct V_9 * V_8 ;
int V_81 = 0 ;
F_3 ( F_179 () ) ;
if ( V_7 -> V_1 != V_2 )
F_187 ( V_2 -> V_144 , L_42 ,
V_7 -> V_1 , V_2 ) ;
F_59 ( & V_335 ) ;
F_59 ( & V_5 -> V_99 ) ;
if ( ! V_7 -> V_1 ) {
F_61 ( & V_5 -> V_99 ) ;
V_81 = - V_131 ;
goto V_200;
}
V_2 -> V_11 |= V_246 ;
F_61 ( & V_5 -> V_99 ) ;
F_188 ( V_229 -> V_259 , V_2 -> line ) ;
V_8 = F_189 ( V_5 ) ;
if ( V_8 ) {
F_190 ( V_5 -> V_8 ) ;
F_191 ( V_8 ) ;
}
if ( F_16 ( V_2 ) )
F_192 ( V_2 -> V_31 ) ;
if ( V_2 -> type != V_24 )
V_2 -> V_13 -> V_139 ( V_2 ) ;
F_160 ( V_2 -> V_339 ) ;
V_2 -> type = V_24 ;
V_7 -> V_1 = NULL ;
V_200:
F_61 ( & V_335 ) ;
return V_81 ;
}
int F_193 ( struct V_1 * V_341 , struct V_1 * V_342 )
{
if ( V_341 -> V_111 != V_342 -> V_111 )
return 0 ;
switch ( V_341 -> V_111 ) {
case V_277 :
return ( V_341 -> V_100 == V_342 -> V_100 ) ;
case V_306 :
return ( V_341 -> V_100 == V_342 -> V_100 ) &&
( V_341 -> V_109 == V_342 -> V_109 ) ;
case V_257 :
case V_273 :
case V_274 :
case V_275 :
case V_307 :
case V_308 :
return ( V_341 -> V_115 == V_342 -> V_115 ) ;
}
return 0 ;
}
void F_194 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_38 * V_5 = & V_2 -> V_7 -> V_5 ;
struct V_9 * V_8 = V_5 -> V_8 ;
struct V_343 * V_344 ;
F_195 ( & V_2 -> V_12 ) ;
if ( V_8 ) {
V_344 = F_196 ( V_8 ) ;
if ( V_344 ) {
if ( V_344 -> V_13 -> V_345 )
V_344 -> V_13 -> V_345 ( V_8 , V_3 ) ;
F_197 ( V_344 ) ;
}
}
V_2 -> V_167 . V_175 ++ ;
if ( F_1 ( V_2 ) ) {
if ( V_3 )
F_102 ( & V_5 -> V_236 ) ;
else if ( V_8 )
F_198 ( V_8 ) ;
}
}
void F_199 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_195 ( & V_2 -> V_12 ) ;
V_2 -> V_167 . V_176 ++ ;
if ( F_38 ( V_2 ) ) {
if ( V_2 -> V_71 ) {
if ( V_3 ) {
V_2 -> V_71 = 0 ;
V_2 -> V_13 -> V_15 ( V_2 ) ;
F_2 ( V_2 ) ;
}
} else {
if ( ! V_3 ) {
V_2 -> V_71 = 1 ;
V_2 -> V_13 -> V_14 ( V_2 ) ;
}
}
}
}
void F_200 ( struct V_1 * V_5 , unsigned int V_3 ,
unsigned int V_182 , unsigned int V_89 , unsigned int V_346 )
{
struct V_38 * V_315 = & V_5 -> V_7 -> V_5 ;
if ( ( V_3 & V_5 -> V_347 & ~ V_182 ) == 0 )
if ( F_201 ( V_315 , V_89 , V_346 ) == 0 )
++ V_5 -> V_167 . V_185 ;
if ( V_3 & ~ V_5 -> V_347 & V_182 )
if ( F_201 ( V_315 , 0 , V_348 ) == 0 )
++ V_5 -> V_167 . V_185 ;
}
