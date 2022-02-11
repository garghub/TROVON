static void F_1 ( struct V_1 * V_2 , const char * V_3 , int V_4 , const char * V_5 )
{
int V_6 ;
int V_7 ;
F_2 ( L_1 , V_2 -> V_8 , V_5 ) ;
while( V_4 ) {
V_7 = ( V_4 > 16 ) ? 16 : V_4 ;
for( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
F_2 ( L_2 , ( unsigned char ) V_3 [ V_6 ] ) ;
for(; V_6 < 17 ; V_6 ++ )
F_2 ( L_3 ) ;
for( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
if ( V_3 [ V_6 ] >= 040 && V_3 [ V_6 ] <= 0176 )
F_2 ( L_4 , V_3 [ V_6 ] ) ;
else
F_2 ( L_5 ) ;
}
F_2 ( L_6 ) ;
V_3 += V_7 ;
V_4 -= V_7 ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
int V_6 ;
F_2 ( L_7 , V_2 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
F_2 ( L_8 ,
V_6 , F_4 ( V_2 -> V_11 [ V_6 ] . V_4 ) , F_4 ( V_2 -> V_11 [ V_6 ] . V_12 ) ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
int V_6 ;
F_2 ( L_9 , V_2 -> V_13 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_14 ; V_6 ++ ) {
F_2 ( L_8 ,
V_6 , F_4 ( V_2 -> V_15 [ V_6 ] . V_4 ) , F_4 ( V_2 -> V_15 [ V_6 ] . V_12 ) ) ;
}
}
static inline int F_6 ( struct V_1 * V_2 , char * V_16 , const char * V_17 )
{
#ifdef F_7
if ( ! V_2 ) {
F_2 ( L_10 , V_16 , V_17 ) ;
return 1 ;
}
if ( V_2 -> V_18 != V_19 ) {
F_2 ( L_11 , V_16 , V_17 ) ;
return 1 ;
}
#else
if ( ! V_2 )
return 1 ;
#endif
return 0 ;
}
static void F_8 ( struct V_20 * V_21 ,
const T_1 * V_3 , char * V_22 , int V_4 )
{
struct V_23 * V_24 ;
if ( ! V_21 )
return;
V_24 = F_9 ( V_21 ) ;
if ( V_24 ) {
if ( V_24 -> V_25 -> V_26 )
V_24 -> V_25 -> V_26 ( V_21 , V_3 , V_22 , V_4 ) ;
F_10 ( V_24 ) ;
}
}
static int F_11 ( struct V_20 * V_21 , struct V_27 * V_28 )
{
struct V_1 * V_2 ;
int V_29 , line ;
unsigned long V_22 ;
line = V_21 -> V_30 ;
if ( line >= V_31 ) {
F_12 ( ( L_12 , V_32 , line ) ) ;
return - V_33 ;
}
V_2 = V_34 ;
while( V_2 && V_2 -> line != line )
V_2 = V_2 -> V_35 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_13 ) )
return - V_33 ;
if ( V_2 -> V_36 ) {
F_12 ( ( L_14 , V_2 -> V_8 , V_2 -> V_36 ) ) ;
return - V_33 ;
}
V_21 -> V_37 = V_2 ;
V_2 -> V_38 . V_21 = V_21 ;
F_13 ( ( L_15 , V_2 -> V_8 , V_2 -> V_38 . V_4 ) ) ;
if ( V_2 -> V_38 . V_22 & V_39 ) {
F_14 ( V_21 , V_2 -> V_38 . V_40 ,
! ( V_2 -> V_38 . V_22 & V_39 ) ) ;
V_29 = ( ( V_2 -> V_38 . V_22 & V_41 ) ?
- V_42 : - V_43 ) ;
goto V_44;
}
F_15 ( & V_2 -> V_38 . V_45 ) ;
V_2 -> V_38 . V_46 = ( V_2 -> V_38 . V_22 & V_47 ) ? 1 : 0 ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_49 ) {
V_29 = - V_50 ;
F_17 ( & V_2 -> V_48 , V_22 ) ;
F_18 ( & V_2 -> V_38 . V_45 ) ;
goto V_44;
}
V_2 -> V_38 . V_4 ++ ;
F_17 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_38 . V_4 == 1 ) {
V_29 = F_19 ( V_2 ) ;
if ( V_29 < 0 ) {
F_18 ( & V_2 -> V_38 . V_45 ) ;
goto V_44;
}
}
F_18 ( & V_2 -> V_38 . V_45 ) ;
V_29 = F_20 ( V_21 , V_28 , V_2 ) ;
if ( V_29 ) {
F_13 ( ( L_16 , V_2 -> V_8 , V_29 ) ) ;
goto V_44;
}
V_29 = 0 ;
V_44:
if ( V_29 ) {
if ( V_21 -> V_4 == 1 )
V_2 -> V_38 . V_21 = NULL ;
if( V_2 -> V_38 . V_4 )
V_2 -> V_38 . V_4 -- ;
}
F_13 ( ( L_17 , V_2 -> V_8 , V_29 ) ) ;
return V_29 ;
}
static void F_21 ( struct V_20 * V_21 , struct V_27 * V_28 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_18 ) )
return;
F_13 ( ( L_19 , V_2 -> V_8 , V_2 -> V_38 . V_4 ) ) ;
if ( F_22 ( & V_2 -> V_38 , V_21 , V_28 ) == 0 )
goto V_44;
F_15 ( & V_2 -> V_38 . V_45 ) ;
if ( V_2 -> V_38 . V_22 & V_51 )
F_23 ( V_21 , V_2 -> V_52 ) ;
F_24 ( V_21 ) ;
F_25 ( V_21 ) ;
F_26 ( V_2 ) ;
F_18 ( & V_2 -> V_38 . V_45 ) ;
F_27 ( & V_2 -> V_38 , V_21 ) ;
V_2 -> V_38 . V_21 = NULL ;
V_44:
F_13 ( ( L_20 , V_21 -> V_53 -> V_17 , V_2 -> V_38 . V_4 ) ) ;
}
static void F_28 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_21 ) )
return;
F_13 ( ( L_22 , V_2 -> V_8 ) ) ;
F_24 ( V_21 ) ;
F_15 ( & V_2 -> V_38 . V_45 ) ;
F_26 ( V_2 ) ;
F_16 ( & V_2 -> V_38 . V_54 , V_22 ) ;
V_2 -> V_38 . V_4 = 0 ;
V_2 -> V_38 . V_22 &= ~ V_55 ;
V_2 -> V_38 . V_21 = NULL ;
F_17 ( & V_2 -> V_38 . V_54 , V_22 ) ;
F_18 ( & V_2 -> V_38 . V_45 ) ;
F_29 ( & V_2 -> V_38 . V_56 ) ;
}
static void F_30 ( struct V_20 * V_21 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
F_13 ( ( L_23 , V_21 -> V_53 -> V_17 ) ) ;
F_31 ( V_2 ) ;
if ( V_58 -> V_59 & V_60 &&
! ( V_21 -> V_61 . V_59 & V_60 ) ) {
V_2 -> V_62 &= ~ ( V_63 | V_64 ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_32 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
if ( ! ( V_58 -> V_59 & V_60 ) &&
V_21 -> V_61 . V_59 & V_60 ) {
V_2 -> V_62 |= V_64 ;
if ( ! ( V_21 -> V_61 . V_59 & V_65 ) ||
! F_33 ( V_66 , & V_21 -> V_22 ) ) {
V_2 -> V_62 |= V_63 ;
}
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_32 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
if ( V_58 -> V_59 & V_65 &&
! ( V_21 -> V_61 . V_59 & V_65 ) ) {
V_21 -> V_67 = 0 ;
F_34 ( V_21 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 . V_69 == V_70 ) {
int V_52 = ( F_36 ( V_2 ) * 7 ) + 1000 ;
F_37 ( & V_2 -> V_71 , V_72 + F_38 ( V_52 ) ) ;
}
}
static int F_39 ( struct V_20 * V_21 ,
const unsigned char * V_73 , int V_4 )
{
int V_74 = 0 ;
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_24 ) )
return - V_75 ;
F_13 ( ( L_25 , V_2 -> V_8 , V_4 ) ) ;
if ( ! V_2 -> V_76 || ( V_4 > V_2 -> V_77 ) )
return - V_75 ;
if ( ! V_4 || V_21 -> V_78 || V_21 -> V_67 )
return 0 ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_79 ) {
if ( ! F_40 ( V_2 , V_2 -> V_76 , V_2 -> V_79 ) )
goto V_44;
V_2 -> V_79 = 0 ;
}
if ( F_40 ( V_2 , V_73 , V_4 ) )
V_74 = V_4 ;
V_44:
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_13 ( ( L_26 , V_2 -> V_8 , V_74 ) ) ;
return V_74 ;
}
static int F_41 ( struct V_20 * V_21 , unsigned char V_80 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
int V_74 = 0 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_27 ) )
return 0 ;
F_13 ( ( L_28 , V_2 -> V_8 , V_80 ) ) ;
if ( ! V_2 -> V_76 )
return 0 ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_79 < V_2 -> V_77 ) {
V_2 -> V_76 [ V_2 -> V_79 ++ ] = V_80 ;
V_74 = 1 ;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
return V_74 ;
}
static void F_42 ( struct V_20 * V_21 , char V_80 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_29 ) )
return;
F_13 ( ( L_30 , V_2 -> V_8 , V_80 ) ) ;
V_2 -> V_81 = V_80 ;
if ( V_80 ) {
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( ! V_2 -> V_82 )
F_43 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
}
static void F_23 ( struct V_20 * V_21 , int V_52 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_83 , V_84 ;
if ( ! V_2 )
return;
if ( F_6 ( V_2 , V_21 -> V_17 , L_31 ) )
return;
F_13 ( ( L_32 , V_2 -> V_8 ) ) ;
if ( ! ( V_2 -> V_38 . V_22 & V_51 ) )
goto exit;
V_83 = V_72 ;
if ( V_2 -> V_68 . V_85 ) {
V_84 = V_2 -> V_52 / ( 32 * 5 ) ;
if ( ! V_84 )
V_84 ++ ;
} else
V_84 = 1 ;
if ( V_52 )
V_84 = F_44 (unsigned long, char_time, timeout) ;
while ( V_2 -> V_86 ) {
F_45 ( F_46 ( V_84 ) ) ;
if ( F_47 ( V_87 ) )
break;
if ( V_52 && F_48 ( V_72 , V_83 + V_52 ) )
break;
}
exit:
F_13 ( ( L_33 , V_2 -> V_8 ) ) ;
}
static int F_49 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_74 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_34 ) )
return 0 ;
V_74 = ( V_2 -> V_86 ) ? 0 : V_88 ;
F_13 ( ( L_35 , V_2 -> V_8 , V_74 ) ) ;
return V_74 ;
}
static void F_50 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_36 ) )
return;
F_13 ( ( L_37 , V_2 -> V_8 , V_2 -> V_79 ) ) ;
if ( V_2 -> V_79 <= 0 || V_21 -> V_78 ||
V_21 -> V_67 || ! V_2 -> V_76 )
return;
F_13 ( ( L_38 , V_2 -> V_8 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_79 && F_40 ( V_2 , V_2 -> V_76 , V_2 -> V_79 ) )
V_2 -> V_79 = 0 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
static void F_24 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_39 ) )
return;
F_13 ( ( L_40 , V_2 -> V_8 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_79 = 0 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_51 ( V_21 ) ;
}
static void F_52 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_41 ) )
return;
F_13 ( ( L_42 , V_2 -> V_8 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_82 && V_2 -> V_68 . V_69 == V_89 )
F_53 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
static void F_34 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_43 ) )
return;
F_13 ( ( L_44 , V_2 -> V_8 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_79 && F_40 ( V_2 , V_2 -> V_76 , V_2 -> V_79 ) )
V_2 -> V_79 = 0 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
static int F_54 ( struct V_20 * V_21 ,
unsigned int V_90 , unsigned long V_91 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
void T_2 * V_92 = ( void T_2 * ) V_91 ;
int V_74 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_45 ) )
return - V_33 ;
F_13 ( ( L_46 , V_2 -> V_8 , V_90 ) ) ;
if ( ( V_90 != V_93 ) && ( V_90 != V_94 ) &&
( V_90 != V_95 ) ) {
if ( V_21 -> V_22 & ( 1 << V_96 ) )
return - V_75 ;
}
switch ( V_90 ) {
case V_97 :
return F_55 ( V_2 , V_92 ) ;
case V_95 :
return F_56 ( V_2 , ( int ) V_91 ) ;
case V_98 :
return F_57 ( V_2 , V_92 ) ;
case V_99 :
return F_58 ( V_2 , V_92 ) ;
case V_100 :
return F_59 ( V_2 , V_92 ) ;
case V_101 :
return F_60 ( V_2 , V_92 ) ;
case V_102 :
return F_61 ( V_2 , ( int ) V_91 ) ;
case V_103 :
return F_62 ( V_2 , V_92 ) ;
case V_104 :
return F_63 ( V_2 , ( int ) V_91 ) ;
}
F_15 ( & V_2 -> V_38 . V_45 ) ;
switch ( V_90 ) {
case V_105 :
V_74 = F_64 ( V_2 , V_92 ) ;
break;
case V_106 :
V_74 = F_65 ( V_2 , V_92 ) ;
break;
case V_107 :
V_74 = F_66 ( V_2 , V_92 ) ;
break;
case V_108 :
V_74 = F_67 ( V_2 , ( int ) V_91 ) ;
break;
case V_109 :
V_74 = F_68 ( V_2 , ( int ) V_91 ) ;
break;
case V_110 :
V_74 = F_69 ( V_2 , ( int ) V_91 ) ;
break;
case V_111 :
V_74 = F_70 ( V_2 ) ;
break;
case V_112 :
V_74 = F_71 ( V_2 , V_92 ) ;
break;
case V_113 :
V_74 = F_72 ( V_2 , V_92 ) ;
break;
case V_114 :
V_74 = F_73 ( V_2 , ( int ) V_91 ) ;
break;
default:
V_74 = - V_115 ;
}
F_18 ( & V_2 -> V_38 . V_45 ) ;
return V_74 ;
}
static int F_74 ( struct V_20 * V_21 ,
struct V_116 * V_117 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
struct V_118 V_119 ;
unsigned long V_22 ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_119 = V_2 -> V_117 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_117 -> V_120 = V_119 . V_120 ;
V_117 -> V_121 = V_119 . V_121 ;
V_117 -> V_122 = V_119 . V_122 ;
V_117 -> V_123 = V_119 . V_123 ;
V_117 -> V_124 = V_119 . V_124 ;
V_117 -> V_125 = V_119 . V_125 ;
V_117 -> V_126 = V_119 . V_126 ;
V_117 -> V_127 = V_119 . V_127 ;
V_117 -> V_128 = V_119 . V_128 ;
V_117 -> V_129 = V_119 . V_129 ;
V_117 -> V_130 = V_119 . V_130 ;
return 0 ;
}
static long F_75 ( struct V_1 * V_2 , struct V_131 T_2 * V_132 )
{
struct V_131 V_133 ;
F_13 ( ( L_47 , V_2 -> V_8 ) ) ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_69 = ( V_134 ) V_2 -> V_68 . V_69 ;
V_133 . V_135 = V_2 -> V_68 . V_135 ;
V_133 . V_22 = V_2 -> V_68 . V_22 ;
V_133 . V_136 = V_2 -> V_68 . V_136 ;
V_133 . V_137 = ( V_134 ) V_2 -> V_68 . V_137 ;
V_133 . V_138 = V_2 -> V_68 . V_138 ;
V_133 . V_139 = V_2 -> V_68 . V_139 ;
V_133 . V_140 = V_2 -> V_68 . V_140 ;
V_133 . V_141 = V_2 -> V_68 . V_141 ;
V_133 . V_85 = ( V_134 ) V_2 -> V_68 . V_85 ;
V_133 . V_142 = V_2 -> V_68 . V_142 ;
V_133 . V_143 = V_2 -> V_68 . V_143 ;
V_133 . V_128 = V_2 -> V_68 . V_128 ;
if ( F_76 ( V_132 , & V_133 , sizeof( struct V_131 ) ) )
return - V_144 ;
return 0 ;
}
static long F_77 ( struct V_1 * V_2 , struct V_131 T_2 * V_145 )
{
struct V_131 V_133 ;
F_13 ( ( L_48 , V_2 -> V_8 ) ) ;
if ( F_78 ( & V_133 , V_145 , sizeof( struct V_131 ) ) )
return - V_144 ;
F_79 ( & V_2 -> V_54 ) ;
if ( V_133 . V_69 == V_146 ) {
V_2 -> V_147 = V_133 . V_137 ;
} else {
V_2 -> V_68 . V_69 = V_133 . V_69 ;
V_2 -> V_68 . V_135 = V_133 . V_135 ;
V_2 -> V_68 . V_22 = V_133 . V_22 ;
V_2 -> V_68 . V_136 = V_133 . V_136 ;
V_2 -> V_68 . V_137 = V_133 . V_137 ;
V_2 -> V_68 . V_138 = V_133 . V_138 ;
V_2 -> V_68 . V_139 = V_133 . V_139 ;
V_2 -> V_68 . V_140 = V_133 . V_140 ;
V_2 -> V_68 . V_141 = V_133 . V_141 ;
V_2 -> V_68 . V_85 = V_133 . V_85 ;
V_2 -> V_68 . V_142 = V_133 . V_142 ;
V_2 -> V_68 . V_143 = V_133 . V_143 ;
V_2 -> V_68 . V_128 = V_133 . V_128 ;
}
F_80 ( & V_2 -> V_54 ) ;
F_81 ( V_2 ) ;
return 0 ;
}
static long F_82 ( struct V_20 * V_21 ,
unsigned int V_90 , unsigned long V_91 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_148 = - V_115 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_49 ) )
return - V_33 ;
F_13 ( ( L_50 , V_2 -> V_8 , V_90 ) ) ;
switch ( V_90 ) {
case V_149 :
V_148 = F_77 ( V_2 , F_83 ( V_91 ) ) ;
break;
case V_150 :
V_148 = F_75 ( V_2 , F_83 ( V_91 ) ) ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_112 :
case V_97 :
case V_113 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_103 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_95 :
case V_114 :
case V_102 :
case V_104 :
V_148 = F_54 ( V_21 , V_90 , V_91 ) ;
break;
}
F_13 ( ( L_51 , V_2 -> V_8 , V_90 , V_148 ) ) ;
return V_148 ;
}
static inline void F_84 ( struct V_151 * V_152 , struct V_1 * V_2 )
{
char V_153 [ 30 ] ;
unsigned long V_22 ;
F_85 ( V_152 , L_52 ,
V_2 -> V_8 , V_2 -> V_154 ,
V_2 -> V_155 , V_2 -> V_77 ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_86 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_153 [ 0 ] = 0 ;
V_153 [ 1 ] = 0 ;
if ( V_2 -> V_62 & V_63 )
strcat ( V_153 , L_53 ) ;
if ( V_2 -> V_62 & V_156 )
strcat ( V_153 , L_54 ) ;
if ( V_2 -> V_62 & V_64 )
strcat ( V_153 , L_55 ) ;
if ( V_2 -> V_62 & V_157 )
strcat ( V_153 , L_56 ) ;
if ( V_2 -> V_62 & V_158 )
strcat ( V_153 , L_57 ) ;
if ( V_2 -> V_62 & V_159 )
strcat ( V_153 , L_58 ) ;
if ( V_2 -> V_68 . V_69 != V_89 ) {
F_85 ( V_152 , L_59 ,
V_2 -> V_117 . V_160 , V_2 -> V_117 . V_161 ) ;
if ( V_2 -> V_117 . V_162 )
F_85 ( V_152 , L_60 , V_2 -> V_117 . V_162 ) ;
if ( V_2 -> V_117 . V_163 )
F_85 ( V_152 , L_61 , V_2 -> V_117 . V_163 ) ;
if ( V_2 -> V_117 . V_164 )
F_85 ( V_152 , L_62 , V_2 -> V_117 . V_164 ) ;
if ( V_2 -> V_117 . V_165 )
F_85 ( V_152 , L_63 , V_2 -> V_117 . V_165 ) ;
if ( V_2 -> V_117 . V_166 )
F_85 ( V_152 , L_64 , V_2 -> V_117 . V_166 ) ;
if ( V_2 -> V_117 . V_167 )
F_85 ( V_152 , L_65 , V_2 -> V_117 . V_167 ) ;
} else {
F_85 ( V_152 , L_66 ,
V_2 -> V_117 . V_125 , V_2 -> V_117 . V_124 ) ;
if ( V_2 -> V_117 . V_126 )
F_85 ( V_152 , L_67 , V_2 -> V_117 . V_126 ) ;
if ( V_2 -> V_117 . V_128 )
F_85 ( V_152 , L_68 , V_2 -> V_117 . V_128 ) ;
if ( V_2 -> V_117 . V_129 )
F_85 ( V_152 , L_69 , V_2 -> V_117 . V_129 ) ;
if ( V_2 -> V_117 . V_127 )
F_85 ( V_152 , L_70 , V_2 -> V_117 . V_127 ) ;
}
F_85 ( V_152 , L_71 , V_153 + 1 ) ;
F_85 ( V_152 , L_72 ,
V_2 -> V_86 , V_2 -> V_168 , V_2 -> V_169 ,
V_2 -> V_170 ) ;
}
static int F_87 ( struct V_151 * V_152 , void * V_171 )
{
struct V_1 * V_2 ;
F_88 ( V_152 , L_73 ) ;
V_2 = V_34 ;
while( V_2 ) {
F_84 ( V_152 , V_2 ) ;
V_2 = V_2 -> V_35 ;
}
return 0 ;
}
static int F_89 ( struct V_172 * V_172 , struct V_27 * V_27 )
{
return F_90 ( V_27 , F_87 , NULL ) ;
}
static int F_91 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_4 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_74 ) )
return 0 ;
V_4 = F_36 ( V_2 ) ;
F_13 ( ( L_75 , V_2 -> V_8 , V_4 ) ) ;
return V_4 ;
}
static void F_92 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_76 ) )
return;
F_13 ( ( L_77 , V_2 -> V_8 ) ) ;
if ( F_93 ( V_21 ) )
F_42 ( V_21 , F_94 ( V_21 ) ) ;
if ( V_21 -> V_61 . V_59 & V_65 ) {
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_62 &= ~ V_63 ;
F_32 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
}
static void F_95 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_78 ) )
return;
F_13 ( ( L_79 , V_2 -> V_8 ) ) ;
if ( F_93 ( V_21 ) ) {
if ( V_2 -> V_81 )
V_2 -> V_81 = 0 ;
else
F_42 ( V_21 , F_96 ( V_21 ) ) ;
}
if ( V_21 -> V_61 . V_59 & V_65 ) {
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_62 |= V_63 ;
F_32 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
}
static int F_97 ( struct V_20 * V_21 , int V_173 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned short V_174 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_80 ) )
return - V_175 ;
F_13 ( ( L_81 , V_2 -> V_8 , V_173 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_174 = F_98 ( V_2 , V_176 ) ;
if ( V_173 == - 1 )
V_174 |= V_177 ;
else
V_174 &= ~ V_177 ;
F_99 ( V_2 , V_176 , V_174 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_100 ( struct V_178 * V_179 , unsigned short V_136 ,
unsigned short V_128 )
{
struct V_1 * V_2 = F_101 ( V_179 ) ;
unsigned char V_180 ;
unsigned short V_181 ;
if ( V_2 -> V_38 . V_4 )
return - V_50 ;
F_13 ( ( L_82 , V_2 -> V_8 ) ) ;
switch ( V_136 )
{
case V_182 : V_180 = V_183 ; break;
case V_184 : V_180 = V_185 ; break;
case V_186 : V_180 = V_187 ; break;
case V_188 : V_180 = V_189 ; break;
case V_190 : V_180 = V_191 ; break;
default: return - V_175 ;
}
switch ( V_128 )
{
case V_192 : V_181 = V_193 ; break;
case V_194 : V_181 = V_195 ; break;
case V_196 : V_181 = V_197 ; break;
default: return - V_175 ;
}
V_2 -> V_68 . V_136 = V_180 ;
V_2 -> V_68 . V_139 = V_181 ;
if ( V_2 -> V_49 )
F_81 ( V_2 ) ;
return 0 ;
}
static T_3 F_102 ( struct V_198 * V_199 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 = F_101 ( V_179 ) ;
unsigned long V_22 ;
F_13 ( ( L_83 , V_179 -> V_17 ) ) ;
if ( ! V_199 -> V_200 )
return V_201 ;
F_103 ( V_179 ) ;
V_179 -> V_202 . V_203 ++ ;
V_179 -> V_202 . V_204 += V_199 -> V_200 ;
V_179 -> V_205 = V_72 ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_40 ( V_2 , V_199 -> V_3 , V_199 -> V_200 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_104 ( V_199 ) ;
return V_201 ;
}
static int F_105 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = F_101 ( V_179 ) ;
int V_148 ;
unsigned long V_22 ;
if ( ! F_106 ( V_206 ) )
return - V_50 ;
F_13 ( ( L_84 , V_179 -> V_17 ) ) ;
V_148 = F_107 ( V_179 ) ;
if ( V_148 )
return V_148 ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_38 . V_4 != 0 || V_2 -> V_49 != 0 ) {
F_13 ( ( L_85 , V_179 -> V_17 ) ) ;
F_17 ( & V_2 -> V_48 , V_22 ) ;
return - V_50 ;
}
V_2 -> V_49 = 1 ;
F_17 ( & V_2 -> V_48 , V_22 ) ;
if ( ( V_148 = F_19 ( V_2 ) ) != 0 ) {
F_16 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_49 = 0 ;
F_17 ( & V_2 -> V_48 , V_22 ) ;
return V_148 ;
}
V_2 -> V_62 |= V_63 | V_64 ;
F_81 ( V_2 ) ;
V_179 -> V_205 = V_72 ;
F_108 ( V_179 ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_86 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_62 & V_158 )
F_109 ( V_179 ) ;
else
F_110 ( V_179 ) ;
return 0 ;
}
static int F_111 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = F_101 ( V_179 ) ;
unsigned long V_22 ;
F_13 ( ( L_86 , V_179 -> V_17 ) ) ;
F_103 ( V_179 ) ;
F_26 ( V_2 ) ;
F_112 ( V_179 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_49 = 0 ;
F_17 ( & V_2 -> V_48 , V_22 ) ;
F_113 ( V_206 ) ;
return 0 ;
}
static int F_114 ( struct V_178 * V_179 , struct V_207 * V_208 , int V_90 )
{
const T_4 V_209 = sizeof( V_210 ) ;
V_210 V_211 ;
V_210 T_2 * line = V_208 -> V_212 . V_213 . V_214 ;
struct V_1 * V_2 = F_101 ( V_179 ) ;
unsigned int V_22 ;
F_13 ( ( L_87 , V_179 -> V_17 ) ) ;
if ( V_2 -> V_38 . V_4 )
return - V_50 ;
if ( V_90 != V_215 )
return F_115 ( V_179 , V_208 , V_90 ) ;
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
switch( V_208 -> V_212 . type ) {
case V_216 :
V_208 -> V_212 . type = V_217 ;
if ( V_208 -> V_212 . V_209 < V_209 ) {
V_208 -> V_212 . V_209 = V_209 ;
return - V_218 ;
}
V_22 = V_2 -> V_68 . V_22 & ( V_219 | V_220 |
V_221 | V_222 |
V_223 | V_224 |
V_225 | V_226 ) ;
switch ( V_22 ) {
case ( V_219 | V_223 ) : V_211 . V_227 = V_228 ; break;
case ( V_221 | V_225 ) : V_211 . V_227 = V_229 ; break;
case ( V_219 | V_225 ) : V_211 . V_227 = V_230 ; break;
case ( V_219 | V_226 ) : V_211 . V_227 = V_231 ; break;
default: V_211 . V_227 = V_232 ;
}
V_211 . V_233 = V_2 -> V_68 . V_137 ;
V_211 . V_135 = V_2 -> V_68 . V_135 ? 1 : 0 ;
if ( F_76 ( line , & V_211 , V_209 ) )
return - V_144 ;
return 0 ;
case V_217 :
if( ! F_116 ( V_234 ) )
return - V_235 ;
if ( F_78 ( & V_211 , line , V_209 ) )
return - V_144 ;
switch ( V_211 . V_227 )
{
case V_228 : V_22 = V_219 | V_223 ; break;
case V_231 : V_22 = V_219 | V_226 ; break;
case V_229 : V_22 = V_221 | V_225 ; break;
case V_230 : V_22 = V_219 | V_225 ; break;
case V_232 : V_22 = V_2 -> V_68 . V_22 &
( V_219 | V_220 |
V_221 | V_222 |
V_223 | V_224 |
V_225 | V_226 ) ; break;
default: return - V_175 ;
}
if ( V_211 . V_135 != 0 && V_211 . V_135 != 1 )
return - V_175 ;
V_2 -> V_68 . V_22 &= ~ ( V_219 | V_220 |
V_221 | V_222 |
V_223 | V_224 |
V_225 | V_226 ) ;
V_2 -> V_68 . V_22 |= V_22 ;
V_2 -> V_68 . V_135 = V_211 . V_135 ;
if ( V_22 & ( V_221 | V_225 ) )
V_2 -> V_68 . V_137 = V_211 . V_233 ;
else
V_2 -> V_68 . V_137 = 0 ;
if ( V_2 -> V_49 )
F_81 ( V_2 ) ;
return 0 ;
default:
return F_115 ( V_179 , V_208 , V_90 ) ;
}
}
static void F_117 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = F_101 ( V_179 ) ;
unsigned long V_22 ;
F_13 ( ( L_88 , V_179 -> V_17 ) ) ;
V_179 -> V_202 . V_236 ++ ;
V_179 -> V_202 . V_237 ++ ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_53 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_118 ( V_179 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
if ( F_120 ( V_2 -> V_238 ) )
F_118 ( V_2 -> V_238 ) ;
}
static void F_121 ( struct V_1 * V_2 , char * V_73 , int V_209 )
{
struct V_198 * V_199 = F_122 ( V_209 ) ;
struct V_178 * V_179 = V_2 -> V_238 ;
F_13 ( ( L_89 , V_179 -> V_17 ) ) ;
if ( V_199 == NULL ) {
F_12 ( ( L_90 , V_179 -> V_17 ) ) ;
V_179 -> V_202 . V_239 ++ ;
return;
}
memcpy ( F_123 ( V_199 , V_209 ) , V_73 , V_209 ) ;
V_199 -> V_240 = F_124 ( V_199 , V_179 ) ;
V_179 -> V_202 . V_241 ++ ;
V_179 -> V_202 . V_242 += V_209 ;
F_125 ( V_199 ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
int V_148 ;
struct V_178 * V_179 ;
T_5 * V_243 ;
V_179 = F_127 ( V_2 ) ;
if ( ! V_179 ) {
F_2 ( V_244 L_91 , V_2 -> V_8 ) ;
return - V_245 ;
}
V_179 -> V_246 = V_2 -> V_154 ;
V_179 -> V_247 = V_2 -> V_154 + V_248 - 1 ;
V_179 -> V_249 = V_2 -> V_155 ;
V_179 -> V_250 = & V_251 ;
V_179 -> V_252 = 10 * V_253 ;
V_179 -> V_254 = 50 ;
V_243 = F_128 ( V_179 ) ;
V_243 -> V_255 = F_100 ;
V_243 -> V_256 = F_102 ;
V_148 = F_129 ( V_179 ) ;
if ( V_148 ) {
F_2 ( V_257 L_92 , __FILE__ ) ;
F_130 ( V_179 ) ;
return V_148 ;
}
V_2 -> V_238 = V_179 ;
return 0 ;
}
static void F_131 ( struct V_1 * V_2 )
{
F_132 ( V_2 -> V_238 ) ;
F_130 ( V_2 -> V_238 ) ;
V_2 -> V_238 = NULL ;
}
static void F_133 ( struct V_1 * V_2 )
{
struct V_118 * V_117 = & V_2 -> V_117 ;
unsigned int V_258 , V_259 ;
unsigned char * V_260 ;
unsigned char V_12 ;
struct V_261 * V_262 = V_2 -> V_15 ;
int V_6 , V_4 ;
int V_263 = 0 ;
int V_264 ;
unsigned char V_80 ;
V_258 = V_259 = V_2 -> V_13 ;
while( F_134 ( V_262 [ V_259 ] ) ) {
V_4 = F_135 ( V_262 [ V_259 ] ) - V_2 -> V_265 ;
V_260 = V_262 [ V_259 ] . V_73 + V_2 -> V_265 ;
F_136 ( ( L_93 , V_2 -> V_8 , V_4 ) ) ;
F_137 ( V_2 , V_260 , V_4 , L_94 ) ;
for( V_6 = 0 ; V_6 < V_4 ; V_6 += 2 , V_260 += 2 ) {
V_80 = * V_260 ;
V_117 -> V_124 ++ ;
V_264 = 0 ;
V_12 = * ( V_260 + 1 ) & ( V_266 + V_267 ) ;
if ( V_12 ) {
if ( V_12 & V_266 )
V_117 -> V_128 ++ ;
else if ( V_12 & V_267 )
V_117 -> V_126 ++ ;
if ( V_12 & V_2 -> V_268 )
continue;
if ( V_12 & V_266 )
V_264 = V_269 ;
else if ( V_12 & V_267 )
V_264 = V_270 ;
}
F_138 ( & V_2 -> V_38 , V_80 , V_264 ) ;
V_263 ++ ;
}
if ( V_6 < V_4 ) {
V_2 -> V_265 += V_6 ;
F_37 ( & V_2 -> V_271 , V_72 + 1 ) ;
break;
}
V_2 -> V_265 = 0 ;
F_139 ( V_2 , V_259 , V_259 ) ;
if ( ++ V_259 == V_2 -> V_14 )
V_259 = 0 ;
if ( V_259 == V_258 )
break;
}
if ( V_263 )
F_140 ( & V_2 -> V_38 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
int V_148 ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_170 & V_272 ) {
V_2 -> V_170 &= ~ V_272 ;
V_148 = V_272 ;
} else if ( V_2 -> V_170 & V_273 ) {
V_2 -> V_170 &= ~ V_273 ;
V_148 = V_273 ;
} else if ( V_2 -> V_170 & V_274 ) {
V_2 -> V_170 &= ~ V_274 ;
V_148 = V_274 ;
} else {
V_2 -> V_169 = false ;
V_2 -> V_168 = false ;
V_148 = 0 ;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
return V_148 ;
}
static void F_142 ( struct V_275 * V_276 )
{
struct V_1 * V_2 = F_143 ( V_276 , struct V_1 , V_277 ) ;
int V_278 ;
V_2 -> V_169 = true ;
while( ( V_278 = F_141 ( V_2 ) ) ) {
switch ( V_278 ) {
case V_272 :
F_144 ( ( L_95 , V_2 -> V_8 ) ) ;
switch( V_2 -> V_68 . V_69 ) {
case V_89 :
F_133 ( V_2 ) ;
break;
case V_70 :
while( F_145 ( V_2 ) ) ;
break;
case V_279 :
case V_280 :
case V_281 :
case V_282 :
while( F_146 ( V_2 ) ) ;
break;
}
if ( V_2 -> V_283 )
F_147 ( V_2 ) ;
break;
case V_273 :
F_148 ( V_2 ) ;
break;
case V_274 :
F_144 ( ( L_96 , V_2 -> V_8 ) ) ;
V_2 -> V_284 = 0 ;
V_2 -> V_285 = 0 ;
V_2 -> V_286 = 0 ;
V_2 -> V_287 = 0 ;
break;
default:
F_144 ( ( L_97 , V_2 -> V_8 ) ) ;
break;
}
}
F_144 ( ( L_98 , V_2 -> V_8 ) ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_38 . V_21 ;
F_144 ( ( L_99 , V_2 -> V_8 ) ) ;
if ( V_21 )
F_51 ( V_21 ) ;
}
static void F_149 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_288 ) {
V_2 -> V_62 |= V_157 ;
V_2 -> V_289 . V_290 ++ ;
} else {
V_2 -> V_62 &= ~ V_157 ;
V_2 -> V_289 . V_291 ++ ;
}
F_136 ( ( L_100 , V_2 -> V_8 , V_2 -> V_62 ) ) ;
if ( ( V_2 -> V_285 ) ++ == V_292 ) {
F_150 ( V_2 , V_293 ) ;
return;
}
V_2 -> V_117 . V_121 ++ ;
F_29 ( & V_2 -> V_294 ) ;
F_29 ( & V_2 -> V_295 ) ;
V_2 -> V_170 |= V_274 ;
}
static void F_151 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_296 ) {
V_2 -> V_62 |= V_156 ;
V_2 -> V_289 . V_297 ++ ;
} else {
V_2 -> V_62 &= ~ V_156 ;
V_2 -> V_289 . V_298 ++ ;
}
F_136 ( ( L_101 , V_2 -> V_8 , V_2 -> V_62 ) ) ;
if ( ( V_2 -> V_287 ) ++ == V_292 ) {
F_150 ( V_2 , V_299 ) ;
return;
}
V_2 -> V_117 . V_120 ++ ;
F_29 ( & V_2 -> V_294 ) ;
F_29 ( & V_2 -> V_295 ) ;
V_2 -> V_170 |= V_274 ;
if ( F_152 ( & V_2 -> V_38 ) ) {
if ( V_2 -> V_38 . V_21 ) {
if ( V_2 -> V_38 . V_21 -> V_67 ) {
if ( V_2 -> V_62 & V_156 ) {
V_2 -> V_38 . V_21 -> V_67 = 0 ;
V_2 -> V_170 |= V_273 ;
return;
}
} else {
if ( ! ( V_2 -> V_62 & V_156 ) )
V_2 -> V_38 . V_21 -> V_67 = 1 ;
}
}
}
}
static void F_153 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_266 ) {
V_2 -> V_62 |= V_158 ;
V_2 -> V_289 . V_300 ++ ;
} else {
V_2 -> V_62 &= ~ V_158 ;
V_2 -> V_289 . V_301 ++ ;
}
F_136 ( ( L_102 , V_2 -> V_8 , V_2 -> V_62 ) ) ;
if ( ( V_2 -> V_286 ) ++ == V_292 ) {
F_150 ( V_2 , V_302 ) ;
return;
}
V_2 -> V_117 . V_123 ++ ;
#if V_303
if ( V_2 -> V_49 ) {
if ( V_2 -> V_62 & V_158 )
F_109 ( V_2 -> V_238 ) ;
else
F_110 ( V_2 -> V_238 ) ;
}
#endif
F_29 ( & V_2 -> V_294 ) ;
F_29 ( & V_2 -> V_295 ) ;
V_2 -> V_170 |= V_274 ;
if ( V_2 -> V_38 . V_22 & V_304 ) {
if ( V_2 -> V_62 & V_158 )
F_29 ( & V_2 -> V_38 . V_56 ) ;
else {
if ( V_2 -> V_38 . V_21 )
F_154 ( V_2 -> V_38 . V_21 ) ;
}
}
}
static void F_155 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_267 ) {
V_2 -> V_62 |= V_159 ;
V_2 -> V_289 . V_305 ++ ;
} else {
V_2 -> V_62 &= ~ V_159 ;
V_2 -> V_289 . V_306 ++ ;
}
F_136 ( ( L_103 , V_2 -> V_8 , V_2 -> V_62 ) ) ;
if ( ( V_2 -> V_284 ) ++ == V_292 ) {
F_150 ( V_2 , V_307 ) ;
return;
}
V_2 -> V_117 . V_122 ++ ;
F_29 ( & V_2 -> V_294 ) ;
F_29 ( & V_2 -> V_295 ) ;
V_2 -> V_170 |= V_274 ;
}
static void F_156 ( struct V_1 * V_2 )
{
unsigned int V_4 = V_2 -> V_308 ;
unsigned int V_6 = V_2 -> V_309 ;
unsigned short V_310 ;
while ( F_98 ( V_2 , V_311 ) & V_312 ) {
V_310 = F_98 ( V_2 , V_313 ) ;
F_136 ( ( L_104 , V_2 -> V_8 , V_310 ) ) ;
if ( F_134 ( V_2 -> V_15 [ V_6 ] ) ) {
F_157 ( V_2 ) ;
V_2 -> V_283 = 1 ;
continue;
}
V_2 -> V_15 [ V_6 ] . V_73 [ V_4 ++ ] = ( unsigned char ) V_310 ;
if ( V_2 -> V_68 . V_69 == V_89 )
V_2 -> V_15 [ V_6 ] . V_73 [ V_4 ++ ] = ( unsigned char ) ( V_310 >> 8 ) ;
if ( V_4 == V_2 -> V_314 || ( V_310 & V_315 ) ) {
F_158 ( V_2 -> V_15 [ V_6 ] , V_4 ) ;
F_159 ( V_2 -> V_15 [ V_6 ] , V_316 | ( V_310 >> 8 ) ) ;
V_2 -> V_308 = V_4 = 0 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
V_2 -> V_170 |= V_272 ;
}
}
V_2 -> V_309 = V_6 ;
V_2 -> V_308 = V_4 ;
}
static void F_160 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_98 ( V_2 , V_311 ) ;
F_136 ( ( L_105 , V_2 -> V_8 , V_12 ) ) ;
F_99 ( V_2 , V_311 , V_12 ) ;
V_2 -> V_317 = true ;
if ( V_2 -> V_68 . V_69 == V_89 ) {
if ( V_12 & V_318 ) {
if ( V_2 -> V_86 )
F_161 ( V_2 , V_12 ) ;
}
if ( V_2 -> V_319 && ( V_12 & V_312 ) )
F_156 ( V_2 ) ;
if ( ( V_12 & V_320 ) && ( V_12 & V_321 ) ) {
V_2 -> V_117 . V_129 ++ ;
if ( V_2 -> V_38 . V_21 ) {
if ( ! ( V_12 & V_2 -> V_268 ) ) {
if ( V_2 -> V_322 & V_323 ) {
F_138 ( & V_2 -> V_38 , 0 , V_324 ) ;
if ( V_2 -> V_38 . V_22 & V_325 )
F_162 ( V_2 -> V_38 . V_21 ) ;
}
}
}
}
} else {
if ( V_12 & ( V_318 + V_326 ) )
F_161 ( V_2 , V_12 ) ;
if ( V_2 -> V_319 && ( V_12 & V_312 ) )
F_156 ( V_2 ) ;
if ( V_12 & V_327 ) {
if ( V_12 & V_328 )
V_2 -> V_117 . V_329 ++ ;
else
V_2 -> V_117 . V_330 ++ ;
F_29 ( & V_2 -> V_295 ) ;
}
if ( V_12 & V_331 )
F_147 ( V_2 ) ;
}
if ( V_12 & V_293 )
F_149 ( V_2 , V_12 ) ;
if ( V_12 & V_299 )
F_151 ( V_2 , V_12 ) ;
if ( V_12 & V_302 )
F_153 ( V_2 , V_12 ) ;
if ( V_12 & V_307 )
F_155 ( V_2 , V_12 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_164 ( V_2 , V_332 ) ;
F_136 ( ( L_106 , V_2 -> V_8 , V_12 ) ) ;
F_165 ( V_2 , V_332 , V_12 ) ;
if ( V_12 & ( V_333 + V_334 ) ) {
F_136 ( ( L_107 , V_2 -> V_8 ) ) ;
V_2 -> V_283 = true ;
}
V_2 -> V_170 |= V_272 ;
}
static void F_166 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_164 ( V_2 , V_335 ) ;
F_136 ( ( L_108 , V_2 -> V_8 , V_12 ) ) ;
F_165 ( V_2 , V_335 , V_12 ) ;
if ( V_12 & ( V_333 + V_334 + V_288 ) ) {
V_2 -> V_170 |= V_273 ;
}
}
static bool F_167 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_2 -> V_9 ;
bool V_148 = false ;
do {
if ( V_6 )
V_6 -- ;
else
V_6 = V_2 -> V_10 - 1 ;
if ( ! F_135 ( V_2 -> V_11 [ V_6 ] ) )
break;
V_2 -> V_336 = V_6 ;
V_148 = true ;
} while ( V_6 != V_2 -> V_9 );
return V_148 ;
}
static void F_161 ( struct V_1 * V_2 , unsigned short V_12 )
{
F_136 ( ( L_109 , V_2 -> V_8 , V_12 ) ) ;
F_150 ( V_2 , V_337 + V_318 + V_326 ) ;
F_168 ( V_2 ) ;
if ( V_12 & V_326 ) {
unsigned short V_338 = F_98 ( V_2 , V_176 ) ;
F_99 ( V_2 , V_176 , ( unsigned short ) ( V_338 | V_296 ) ) ;
F_99 ( V_2 , V_176 , V_338 ) ;
}
if ( V_2 -> V_86 ) {
if ( V_2 -> V_68 . V_69 != V_89 ) {
if ( V_12 & V_326 )
V_2 -> V_117 . V_162 ++ ;
else if ( V_12 & V_318 )
V_2 -> V_117 . V_160 ++ ;
}
if ( F_167 ( V_2 ) ) {
F_43 ( V_2 ) ;
F_35 ( V_2 ) ;
return;
}
V_2 -> V_86 = false ;
F_169 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_68 . V_69 != V_89 && V_2 -> V_339 ) {
V_2 -> V_62 &= ~ V_63 ;
V_2 -> V_339 = false ;
F_32 ( V_2 ) ;
}
#if V_303
if ( V_2 -> V_49 )
F_119 ( V_2 ) ;
else
#endif
{
if ( V_2 -> V_38 . V_21 && ( V_2 -> V_38 . V_21 -> V_78 || V_2 -> V_38 . V_21 -> V_67 ) ) {
F_53 ( V_2 ) ;
return;
}
V_2 -> V_170 |= V_273 ;
}
}
}
static void F_170 ( struct V_1 * V_2 , unsigned int V_340 , unsigned int V_341 )
{
struct V_342 * V_343 , * V_344 ;
for ( V_343 = V_2 -> V_345 , V_344 = NULL ; V_343 != NULL ; V_343 = V_343 -> V_346 ) {
if ( V_343 -> V_3 & V_340 ) {
V_343 -> V_3 = V_341 ;
F_29 ( & V_343 -> V_347 ) ;
if ( V_344 != NULL )
V_344 -> V_346 = V_343 -> V_346 ;
else
V_2 -> V_345 = V_343 -> V_346 ;
} else
V_344 = V_343 ;
}
}
static T_6 F_171 ( int V_348 , void * V_349 )
{
struct V_1 * V_2 = V_349 ;
unsigned int V_350 ;
unsigned int V_6 ;
F_136 ( ( L_110 , V_2 -> V_155 ) ) ;
while( ( V_350 = F_164 ( V_2 , V_351 ) & 0xffffff00 ) ) {
F_136 ( ( L_111 , V_2 -> V_8 , V_350 ) ) ;
V_2 -> V_317 = true ;
for( V_6 = 0 ; V_6 < V_2 -> V_352 ; V_6 ++ ) {
if ( V_2 -> V_353 [ V_6 ] == NULL )
continue;
F_79 ( & V_2 -> V_353 [ V_6 ] -> V_54 ) ;
if ( V_350 & ( V_354 << V_6 ) )
F_160 ( V_2 -> V_353 [ V_6 ] ) ;
if ( V_350 & ( V_355 << ( V_6 * 2 ) ) )
F_163 ( V_2 -> V_353 [ V_6 ] ) ;
if ( V_350 & ( V_356 << ( V_6 * 2 ) ) )
F_166 ( V_2 -> V_353 [ V_6 ] ) ;
F_80 ( & V_2 -> V_353 [ V_6 ] -> V_54 ) ;
}
}
if ( V_2 -> V_357 ) {
unsigned int V_341 ;
unsigned int V_340 ;
F_79 ( & V_2 -> V_54 ) ;
while ( ( V_340 = F_164 ( V_2 , V_358 ) ) != 0 ) {
F_136 ( ( L_112 , V_2 -> V_8 , V_340 ) ) ;
V_341 = F_164 ( V_2 , V_359 ) ;
F_165 ( V_2 , V_358 , V_340 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_352 ; V_6 ++ ) {
if ( V_2 -> V_353 [ V_6 ] != NULL )
F_170 ( V_2 -> V_353 [ V_6 ] , V_340 , V_341 ) ;
}
}
F_80 ( & V_2 -> V_54 ) ;
}
for( V_6 = 0 ; V_6 < V_2 -> V_352 ; V_6 ++ ) {
struct V_1 * V_38 = V_2 -> V_353 [ V_6 ] ;
if ( V_38 == NULL )
continue;
F_79 ( & V_38 -> V_54 ) ;
if ( ( V_38 -> V_38 . V_4 || V_38 -> V_49 ) &&
V_38 -> V_170 && ! V_38 -> V_169 &&
! V_38 -> V_168 ) {
F_136 ( ( L_113 , V_38 -> V_8 ) ) ;
F_172 ( & V_38 -> V_277 ) ;
V_38 -> V_168 = true ;
}
F_80 ( & V_38 -> V_54 ) ;
}
F_136 ( ( L_114 , V_2 -> V_155 ) ) ;
return V_360 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_13 ( ( L_115 , V_2 -> V_8 ) ) ;
if ( V_2 -> V_38 . V_22 & V_51 )
return 0 ;
if ( ! V_2 -> V_76 ) {
V_2 -> V_76 = F_173 ( V_2 -> V_77 , V_361 ) ;
if ( ! V_2 -> V_76 ) {
F_12 ( ( L_116 , V_2 -> V_8 ) ) ;
return - V_245 ;
}
}
V_2 -> V_170 = 0 ;
memset ( & V_2 -> V_117 , 0 , sizeof( V_2 -> V_117 ) ) ;
F_31 ( V_2 ) ;
if ( V_2 -> V_38 . V_21 )
F_174 ( V_96 , & V_2 -> V_38 . V_21 -> V_22 ) ;
V_2 -> V_38 . V_22 |= V_51 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
if ( ! ( V_2 -> V_38 . V_22 & V_51 ) )
return;
F_13 ( ( L_117 , V_2 -> V_8 ) ) ;
F_29 ( & V_2 -> V_294 ) ;
F_29 ( & V_2 -> V_295 ) ;
F_175 ( & V_2 -> V_71 ) ;
F_175 ( & V_2 -> V_271 ) ;
F_176 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_53 ( V_2 ) ;
F_157 ( V_2 ) ;
F_150 ( V_2 , V_362 | V_363 ) ;
if ( ! V_2 -> V_38 . V_21 || V_2 -> V_38 . V_21 -> V_61 . V_59 & V_364 ) {
V_2 -> V_62 &= ~ ( V_63 | V_64 ) ;
F_32 ( V_2 ) ;
}
F_177 ( & V_2 -> V_345 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_38 . V_21 )
F_178 ( V_96 , & V_2 -> V_38 . V_21 -> V_22 ) ;
V_2 -> V_38 . V_22 &= ~ V_51 ;
}
static void F_81 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_157 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_68 . V_69 != V_89 ||
V_2 -> V_49 )
F_179 ( V_2 ) ;
else
F_180 ( V_2 ) ;
F_32 ( V_2 ) ;
V_2 -> V_286 = 0 ;
V_2 -> V_287 = 0 ;
V_2 -> V_284 = 0 ;
V_2 -> V_285 = 0 ;
F_181 ( V_2 , V_302 | V_299 | V_293 | V_307 ) ;
F_86 ( V_2 ) ;
if ( V_2 -> V_49 ||
( V_2 -> V_38 . V_21 && V_2 -> V_38 . V_21 -> V_61 . V_59 & V_365 ) )
F_147 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned V_366 ;
int V_367 ;
if ( ! V_2 -> V_38 . V_21 )
return;
F_13 ( ( L_118 , V_2 -> V_8 ) ) ;
V_366 = V_2 -> V_38 . V_21 -> V_61 . V_59 ;
if ( V_366 & V_60 )
V_2 -> V_62 |= V_63 | V_64 ;
else
V_2 -> V_62 &= ~ ( V_63 | V_64 ) ;
switch ( V_366 & V_368 ) {
case V_369 : V_2 -> V_68 . V_142 = 5 ; break;
case V_370 : V_2 -> V_68 . V_142 = 6 ; break;
case V_371 : V_2 -> V_68 . V_142 = 7 ; break;
case V_372 : V_2 -> V_68 . V_142 = 8 ; break;
default: V_2 -> V_68 . V_142 = 7 ; break;
}
V_2 -> V_68 . V_143 = ( V_366 & V_373 ) ? 2 : 1 ;
if ( V_366 & V_374 )
V_2 -> V_68 . V_128 = ( V_366 & V_375 ) ? V_376 : V_377 ;
else
V_2 -> V_68 . V_128 = V_378 ;
V_367 = V_2 -> V_68 . V_142 +
V_2 -> V_68 . V_143 + 1 ;
V_2 -> V_68 . V_85 = F_182 ( V_2 -> V_38 . V_21 ) ;
if ( V_2 -> V_68 . V_85 ) {
V_2 -> V_52 = ( 32 * V_253 * V_367 ) /
V_2 -> V_68 . V_85 ;
}
V_2 -> V_52 += V_253 / 50 ;
if ( V_366 & V_65 )
V_2 -> V_38 . V_22 |= V_379 ;
else
V_2 -> V_38 . V_22 &= ~ V_379 ;
if ( V_366 & V_380 )
V_2 -> V_38 . V_22 &= ~ V_304 ;
else
V_2 -> V_38 . V_22 |= V_304 ;
V_2 -> V_322 = V_331 ;
if ( F_183 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_322 |= V_381 | V_382 ;
if ( F_184 ( V_2 -> V_38 . V_21 ) || F_185 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_322 |= V_323 ;
if ( F_186 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_268 |= V_381 | V_382 ;
if ( F_187 ( V_2 -> V_38 . V_21 ) ) {
V_2 -> V_268 |= V_323 ;
if ( F_186 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_268 |= V_383 ;
}
F_81 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_118 T_2 * V_384 )
{
F_13 ( ( L_119 , V_2 -> V_8 ) ) ;
if ( ! V_384 ) {
memset ( & V_2 -> V_117 , 0 , sizeof( V_2 -> V_117 ) ) ;
} else {
if ( F_76 ( V_384 , & V_2 -> V_117 , sizeof( struct V_118 ) ) )
return - V_144 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , T_7 T_2 * V_132 )
{
F_13 ( ( L_120 , V_2 -> V_8 ) ) ;
if ( F_76 ( V_132 , & V_2 -> V_68 , sizeof( T_7 ) ) )
return - V_144 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , T_7 T_2 * V_145 )
{
unsigned long V_22 ;
T_7 V_133 ;
F_13 ( ( L_121 , V_2 -> V_8 ) ) ;
if ( F_78 ( & V_133 , V_145 , sizeof( T_7 ) ) )
return - V_144 ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( V_133 . V_69 == V_146 )
V_2 -> V_147 = V_133 . V_137 ;
else
memcpy ( & V_2 -> V_68 , & V_133 , sizeof( T_7 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_81 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , int T_2 * V_385 )
{
F_13 ( ( L_122 , V_2 -> V_8 , V_2 -> V_385 ) ) ;
if ( F_188 ( V_2 -> V_385 , V_385 ) )
return - V_144 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , int V_385 )
{
unsigned long V_22 ;
F_13 ( ( L_123 , V_2 -> V_8 , V_385 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_385 = V_385 ;
if ( V_2 -> V_68 . V_69 != V_89 )
F_189 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_386 )
{
unsigned long V_22 ;
F_13 ( ( L_124 , V_2 -> V_8 , V_386 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( V_386 ) {
if ( ! V_2 -> V_82 )
F_43 ( V_2 ) ;
} else {
if ( V_2 -> V_82 )
F_53 ( V_2 ) ;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_13 ( ( L_125 , V_2 -> V_8 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_168 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , int V_386 )
{
unsigned long V_22 ;
unsigned int V_314 ;
F_13 ( ( L_126 , V_2 -> V_8 , V_386 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_314 = ( ( unsigned int ) V_386 ) >> 16 ;
if ( V_314 ) {
if ( ( V_314 > V_387 ) || ( V_314 % 4 ) ) {
F_17 ( & V_2 -> V_54 , V_22 ) ;
return - V_175 ;
}
V_2 -> V_314 = V_314 ;
if ( V_314 < 128 )
V_2 -> V_319 = 1 ;
else
V_2 -> V_319 = 0 ;
F_157 ( V_2 ) ;
}
V_386 &= 3 ;
if ( V_386 ) {
if ( ! V_2 -> V_388 )
F_147 ( V_2 ) ;
else if ( V_386 == 2 ) {
F_99 ( V_2 , V_389 , F_98 ( V_2 , V_389 ) | V_288 ) ;
}
} else {
if ( V_2 -> V_388 )
F_157 ( V_2 ) ;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , int T_2 * V_390 )
{
unsigned long V_22 ;
int V_391 ;
int V_148 = 0 ;
struct V_118 V_392 , V_119 ;
int V_393 ;
int V_394 ;
struct V_395 V_396 , V_397 ;
F_190 ( V_398 , V_87 ) ;
if ( F_191 ( V_394 , V_390 ) )
return - V_144 ;
F_13 ( ( L_127 , V_2 -> V_8 , V_394 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_86 ( V_2 ) ;
V_391 = V_2 -> V_62 ;
V_393 = V_394 &
( ( ( V_391 & V_157 ) ? V_399 : V_400 ) +
( ( V_391 & V_158 ) ? V_401 : V_402 ) +
( ( V_391 & V_156 ) ? V_403 : V_404 ) +
( ( V_391 & V_159 ) ? V_405 : V_406 ) ) ;
if ( V_393 ) {
F_17 ( & V_2 -> V_54 , V_22 ) ;
goto exit;
}
V_392 = V_2 -> V_117 ;
V_396 = V_2 -> V_289 ;
if ( V_394 & ( V_407 + V_408 ) ) {
unsigned short V_338 = F_98 ( V_2 , V_409 ) ;
if ( ! ( V_338 & V_327 ) )
F_99 ( V_2 , V_409 , ( unsigned short ) ( V_338 | V_327 ) ) ;
}
F_192 ( V_410 ) ;
F_193 ( & V_2 -> V_295 , & V_398 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
for(; ; ) {
F_194 () ;
if ( F_47 ( V_87 ) ) {
V_148 = - V_43 ;
break;
}
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_119 = V_2 -> V_117 ;
V_397 = V_2 -> V_289 ;
F_192 ( V_410 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_397 . V_290 == V_396 . V_290 &&
V_397 . V_291 == V_396 . V_291 &&
V_397 . V_300 == V_396 . V_300 &&
V_397 . V_301 == V_396 . V_301 &&
V_397 . V_297 == V_396 . V_297 &&
V_397 . V_298 == V_396 . V_298 &&
V_397 . V_305 == V_396 . V_305 &&
V_397 . V_306 == V_396 . V_306 &&
V_119 . V_330 == V_392 . V_330 &&
V_119 . V_329 == V_392 . V_329 ) {
V_148 = - V_75 ;
break;
}
V_393 = V_394 &
( ( V_397 . V_290 != V_396 . V_290 ? V_399 : 0 ) +
( V_397 . V_291 != V_396 . V_291 ? V_400 : 0 ) +
( V_397 . V_300 != V_396 . V_300 ? V_401 : 0 ) +
( V_397 . V_301 != V_396 . V_301 ? V_402 : 0 ) +
( V_397 . V_297 != V_396 . V_297 ? V_403 : 0 ) +
( V_397 . V_298 != V_396 . V_298 ? V_404 : 0 ) +
( V_397 . V_305 != V_396 . V_305 ? V_405 : 0 ) +
( V_397 . V_306 != V_396 . V_306 ? V_406 : 0 ) +
( V_119 . V_330 != V_392 . V_330 ? V_407 : 0 ) +
( V_119 . V_329 != V_392 . V_329 ? V_408 : 0 ) ) ;
if ( V_393 )
break;
V_392 = V_119 ;
V_396 = V_397 ;
}
F_195 ( & V_2 -> V_295 , & V_398 ) ;
F_192 ( V_411 ) ;
if ( V_394 & ( V_407 + V_408 ) ) {
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( ! F_196 ( & V_2 -> V_295 ) ) {
F_99 ( V_2 , V_409 ,
( unsigned short ) ( F_98 ( V_2 , V_409 ) & ~ V_327 ) ) ;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
exit:
if ( V_148 == 0 )
V_148 = F_188 ( V_393 , V_390 ) ;
return V_148 ;
}
static int F_72 ( struct V_1 * V_2 , int T_2 * V_412 )
{
F_13 ( ( L_128 , V_2 -> V_8 , V_2 -> V_412 ) ) ;
if ( F_188 ( V_2 -> V_412 , V_412 ) )
return - V_144 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , int V_412 )
{
unsigned long V_22 ;
unsigned short V_338 ;
F_13 ( ( L_129 , V_2 -> V_8 , V_412 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_412 = V_412 ;
F_197 ( V_2 ) ;
V_338 = F_98 ( V_2 , V_176 ) ;
if ( V_2 -> V_412 & V_413 )
V_338 |= V_414 ;
else
V_338 &= ~ V_414 ;
F_99 ( V_2 , V_176 , V_338 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int T_2 * V_415 )
{
F_13 ( ( L_130 , V_2 -> V_8 , V_2 -> V_415 ) ) ;
if ( F_188 ( V_2 -> V_415 , V_415 ) )
return - V_144 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , int V_415 )
{
unsigned long V_22 ;
F_13 ( ( L_131 , V_2 -> V_8 , V_415 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_415 = V_415 ;
F_165 ( V_2 , V_416 , V_415 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int T_2 * V_417 )
{
F_13 ( ( L_132 , V_2 -> V_8 , V_2 -> V_417 ) ) ;
if ( F_188 ( V_2 -> V_417 , V_417 ) )
return - V_144 ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , int V_417 )
{
unsigned long V_22 ;
F_13 ( ( L_133 , V_2 -> V_8 , V_417 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_417 = V_417 ;
F_165 ( V_2 , V_418 , V_417 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_419 T_2 * V_420 )
{
unsigned long V_22 ;
struct V_419 V_421 ;
T_8 V_3 ;
if ( ! V_2 -> V_357 )
return - V_175 ;
if ( F_78 ( & V_421 , V_420 , sizeof( V_421 ) ) )
return - V_144 ;
F_13 ( ( L_134 ,
V_2 -> V_8 , V_421 . V_341 , V_421 . V_422 ,
V_421 . V_423 , V_421 . V_424 ) ) ;
F_16 ( & V_2 -> V_353 [ 0 ] -> V_54 , V_22 ) ;
if ( V_421 . V_424 ) {
V_3 = F_164 ( V_2 , V_425 ) ;
V_3 |= V_421 . V_424 & V_421 . V_423 ;
V_3 &= ~ ( V_421 . V_424 & ~ V_421 . V_423 ) ;
F_165 ( V_2 , V_425 , V_3 ) ;
}
if ( V_421 . V_422 ) {
V_3 = F_164 ( V_2 , V_359 ) ;
V_3 |= V_421 . V_422 & V_421 . V_341 ;
V_3 &= ~ ( V_421 . V_422 & ~ V_421 . V_341 ) ;
F_165 ( V_2 , V_359 , V_3 ) ;
}
F_17 ( & V_2 -> V_353 [ 0 ] -> V_54 , V_22 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_419 T_2 * V_420 )
{
struct V_419 V_421 ;
if ( ! V_2 -> V_357 )
return - V_175 ;
V_421 . V_341 = F_164 ( V_2 , V_359 ) ;
V_421 . V_422 = 0xffffffff ;
V_421 . V_423 = F_164 ( V_2 , V_425 ) ;
V_421 . V_424 = 0xffffffff ;
if ( F_76 ( V_420 , & V_421 , sizeof( V_421 ) ) )
return - V_144 ;
F_13 ( ( L_135 ,
V_2 -> V_8 , V_421 . V_341 , V_421 . V_423 ) ) ;
return 0 ;
}
static void F_198 ( struct V_342 * V_343 , unsigned int V_3 )
{
F_199 ( & V_343 -> V_347 ) ;
F_200 ( & V_343 -> V_398 , V_87 ) ;
V_343 -> V_3 = V_3 ;
}
static void F_201 ( struct V_342 * * V_426 , struct V_342 * V_343 )
{
F_192 ( V_410 ) ;
F_193 ( & V_343 -> V_347 , & V_343 -> V_398 ) ;
V_343 -> V_346 = * V_426 ;
* V_426 = V_343 ;
}
static void F_202 ( struct V_342 * * V_426 , struct V_342 * V_427 )
{
struct V_342 * V_343 , * V_344 ;
F_195 ( & V_427 -> V_347 , & V_427 -> V_398 ) ;
F_192 ( V_411 ) ;
for ( V_343 = * V_426 , V_344 = NULL ; V_343 != NULL ; V_344 = V_343 , V_343 = V_343 -> V_346 ) {
if ( V_343 == V_427 ) {
if ( V_344 != NULL )
V_344 -> V_346 = V_343 -> V_346 ;
else
* V_426 = V_343 -> V_346 ;
break;
}
}
}
static void F_177 ( struct V_342 * * V_426 )
{
while ( * V_426 != NULL ) {
F_29 ( & ( * V_426 ) -> V_347 ) ;
* V_426 = ( * V_426 ) -> V_346 ;
}
}
static int F_59 ( struct V_1 * V_2 , struct V_419 T_2 * V_420 )
{
unsigned long V_22 ;
int V_148 = 0 ;
struct V_419 V_421 ;
struct V_342 V_398 ;
T_9 V_341 ;
if ( ! V_2 -> V_357 )
return - V_175 ;
if ( F_78 ( & V_421 , V_420 , sizeof( V_421 ) ) )
return - V_144 ;
F_13 ( ( L_136 ,
V_2 -> V_8 , V_421 . V_341 , V_421 . V_422 ) ) ;
if ( ( V_421 . V_422 &= ~ F_164 ( V_2 , V_425 ) ) == 0 )
return - V_175 ;
F_198 ( & V_398 , V_421 . V_422 ) ;
F_16 ( & V_2 -> V_353 [ 0 ] -> V_54 , V_22 ) ;
F_165 ( V_2 , V_428 , F_164 ( V_2 , V_428 ) | V_421 . V_422 ) ;
V_341 = F_164 ( V_2 , V_359 ) ;
if ( V_421 . V_422 & ~ ( V_341 ^ V_421 . V_341 ) ) {
V_421 . V_341 = V_341 ;
} else {
F_201 ( & V_2 -> V_345 , & V_398 ) ;
F_17 ( & V_2 -> V_353 [ 0 ] -> V_54 , V_22 ) ;
F_194 () ;
if ( F_47 ( V_87 ) )
V_148 = - V_43 ;
else
V_421 . V_341 = V_398 . V_3 ;
F_16 ( & V_2 -> V_353 [ 0 ] -> V_54 , V_22 ) ;
F_202 ( & V_2 -> V_345 , & V_398 ) ;
}
if ( V_2 -> V_345 == NULL )
F_165 ( V_2 , V_428 , 0 ) ;
F_17 ( & V_2 -> V_353 [ 0 ] -> V_54 , V_22 ) ;
if ( ( V_148 == 0 ) && F_76 ( V_420 , & V_421 , sizeof( V_421 ) ) )
V_148 = - V_144 ;
return V_148 ;
}
static int F_56 ( struct V_1 * V_2 , int V_91 )
{
unsigned long V_22 ;
int V_148 ;
struct V_118 V_392 , V_119 ;
F_190 ( V_398 , V_87 ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_392 = V_2 -> V_117 ;
F_193 ( & V_2 -> V_294 , & V_398 ) ;
F_192 ( V_410 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
for(; ; ) {
F_194 () ;
if ( F_47 ( V_87 ) ) {
V_148 = - V_43 ;
break;
}
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_119 = V_2 -> V_117 ;
F_192 ( V_410 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_119 . V_122 == V_392 . V_122 && V_119 . V_121 == V_392 . V_121 &&
V_119 . V_123 == V_392 . V_123 && V_119 . V_120 == V_392 . V_120 ) {
V_148 = - V_75 ;
break;
}
if ( ( V_91 & V_429 && V_119 . V_122 != V_392 . V_122 ) ||
( V_91 & V_430 && V_119 . V_121 != V_392 . V_121 ) ||
( V_91 & V_431 && V_119 . V_123 != V_392 . V_123 ) ||
( V_91 & V_432 && V_119 . V_120 != V_392 . V_120 ) ) {
V_148 = 0 ;
break;
}
V_392 = V_119 ;
}
F_195 ( & V_2 -> V_294 , & V_398 ) ;
F_192 ( V_411 ) ;
return V_148 ;
}
static int F_203 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned int V_433 ;
unsigned long V_22 ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_86 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_433 = ( ( V_2 -> V_62 & V_63 ) ? V_434 : 0 ) +
( ( V_2 -> V_62 & V_64 ) ? V_435 : 0 ) +
( ( V_2 -> V_62 & V_158 ) ? V_436 : 0 ) +
( ( V_2 -> V_62 & V_159 ) ? V_429 : 0 ) +
( ( V_2 -> V_62 & V_157 ) ? V_430 : 0 ) +
( ( V_2 -> V_62 & V_156 ) ? V_432 : 0 ) ;
F_13 ( ( L_137 , V_2 -> V_8 , V_433 ) ) ;
return V_433 ;
}
static int F_204 ( struct V_20 * V_21 ,
unsigned int V_437 , unsigned int V_438 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
F_13 ( ( L_138 , V_2 -> V_8 , V_437 , V_438 ) ) ;
if ( V_437 & V_434 )
V_2 -> V_62 |= V_63 ;
if ( V_437 & V_435 )
V_2 -> V_62 |= V_64 ;
if ( V_438 & V_434 )
V_2 -> V_62 &= ~ V_63 ;
if ( V_438 & V_435 )
V_2 -> V_62 &= ~ V_64 ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_32 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_205 ( struct V_439 * V_38 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_143 ( V_38 , struct V_1 , V_38 ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_86 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
return ( V_2 -> V_62 & V_158 ) ? 1 : 0 ;
}
static void F_206 ( struct V_439 * V_38 , int V_440 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_143 ( V_38 , struct V_1 , V_38 ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
if ( V_440 )
V_2 -> V_62 |= V_63 | V_64 ;
else
V_2 -> V_62 &= ~ ( V_63 | V_64 ) ;
F_32 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
static int F_20 ( struct V_20 * V_21 , struct V_27 * V_28 ,
struct V_1 * V_2 )
{
F_190 ( V_398 , V_87 ) ;
int V_29 ;
bool V_441 = false ;
unsigned long V_22 ;
int V_442 ;
struct V_439 * V_38 = & V_2 -> V_38 ;
F_13 ( ( L_139 , V_21 -> V_53 -> V_17 ) ) ;
if ( V_28 -> V_443 & V_444 || V_21 -> V_22 & ( 1 << V_96 ) ) {
V_38 -> V_22 |= V_55 ;
return 0 ;
}
if ( V_21 -> V_61 . V_59 & V_380 )
V_441 = true ;
V_29 = 0 ;
F_193 ( & V_38 -> V_56 , & V_398 ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_38 -> V_4 -- ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_38 -> V_445 ++ ;
while ( 1 ) {
if ( F_207 ( V_21 ) && F_33 ( V_446 , & V_38 -> V_22 ) )
F_208 ( V_38 ) ;
F_192 ( V_410 ) ;
if ( F_209 ( V_28 ) || ! ( V_38 -> V_22 & V_51 ) ) {
V_29 = ( V_38 -> V_22 & V_41 ) ?
- V_42 : - V_43 ;
break;
}
V_442 = F_210 ( V_38 ) ;
if ( ! ( V_38 -> V_22 & V_39 ) && ( V_441 || V_442 ) )
break;
if ( F_47 ( V_87 ) ) {
V_29 = - V_43 ;
break;
}
F_13 ( ( L_140 , V_21 -> V_53 -> V_17 ) ) ;
F_211 ( V_21 ) ;
F_194 () ;
F_212 ( V_21 ) ;
}
F_192 ( V_411 ) ;
F_195 ( & V_38 -> V_56 , & V_398 ) ;
if ( ! F_209 ( V_28 ) )
V_38 -> V_4 ++ ;
V_38 -> V_445 -- ;
if ( ! V_29 )
V_38 -> V_22 |= V_55 ;
F_13 ( ( L_141 , V_21 -> V_53 -> V_17 , V_29 ) ) ;
return V_29 ;
}
static int F_213 ( struct V_1 * V_2 )
{
V_2 -> V_447 = F_173 ( V_2 -> V_77 + 5 , V_361 ) ;
if ( V_2 -> V_447 == NULL )
return - V_245 ;
V_2 -> V_448 = F_214 ( V_2 -> V_77 + 5 , V_361 ) ;
if ( ! V_2 -> V_448 ) {
F_176 ( V_2 -> V_447 ) ;
V_2 -> V_447 = NULL ;
return - V_245 ;
}
return 0 ;
}
static void F_215 ( struct V_1 * V_2 )
{
F_176 ( V_2 -> V_447 ) ;
V_2 -> V_447 = NULL ;
F_176 ( V_2 -> V_448 ) ;
V_2 -> V_448 = NULL ;
}
static int F_216 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
unsigned int V_449 ;
V_2 -> V_262 = F_217 ( V_2 -> V_450 , V_451 ,
& V_2 -> V_452 ) ;
if ( V_2 -> V_262 == NULL )
return - V_245 ;
V_2 -> V_15 = (struct V_261 * ) V_2 -> V_262 ;
V_2 -> V_11 = ( (struct V_261 * ) V_2 -> V_262 ) + V_2 -> V_14 ;
V_449 = ( unsigned int ) V_2 -> V_452 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_14 ; V_6 ++ ) {
V_2 -> V_15 [ V_6 ] . V_453 = V_449 + ( V_6 * sizeof( struct V_261 ) ) ;
if ( V_6 == V_2 -> V_14 - 1 )
V_2 -> V_15 [ V_6 ] . V_346 = F_218 ( V_449 ) ;
else
V_2 -> V_15 [ V_6 ] . V_346 = F_218 ( V_449 + ( ( V_6 + 1 ) * sizeof( struct V_261 ) ) ) ;
F_158 ( V_2 -> V_15 [ V_6 ] , V_387 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_453 = V_449 + ( ( V_2 -> V_14 + V_6 ) * sizeof( struct V_261 ) ) ;
if ( V_6 == V_2 -> V_10 - 1 )
V_2 -> V_11 [ V_6 ] . V_346 = F_218 ( V_449 + V_2 -> V_14 * sizeof( struct V_261 ) ) ;
else
V_2 -> V_11 [ V_6 ] . V_346 = F_218 ( V_449 + ( ( V_2 -> V_14 + V_6 + 1 ) * sizeof( struct V_261 ) ) ) ;
}
return 0 ;
}
static void F_219 ( struct V_1 * V_2 )
{
if ( V_2 -> V_262 != NULL ) {
F_220 ( V_2 -> V_450 , V_451 , V_2 -> V_262 , V_2 -> V_452 ) ;
V_2 -> V_262 = NULL ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
}
}
static int F_221 ( struct V_1 * V_2 , struct V_261 * V_262 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( ( V_262 [ V_6 ] . V_73 = F_222 ( V_2 -> V_450 , V_387 , & V_262 [ V_6 ] . V_454 ) ) == NULL )
return - V_245 ;
V_262 [ V_6 ] . V_455 = F_218 ( ( unsigned int ) V_262 [ V_6 ] . V_454 ) ;
}
return 0 ;
}
static void F_223 ( struct V_1 * V_2 , struct V_261 * V_262 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( V_262 [ V_6 ] . V_73 == NULL )
continue;
F_220 ( V_2 -> V_450 , V_387 , V_262 [ V_6 ] . V_73 , V_262 [ V_6 ] . V_454 ) ;
V_262 [ V_6 ] . V_73 = NULL ;
}
}
static int F_224 ( struct V_1 * V_2 )
{
V_2 -> V_14 = 32 ;
V_2 -> V_10 = 32 ;
if ( F_216 ( V_2 ) < 0 ||
F_221 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) < 0 ||
F_221 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) < 0 ||
F_213 ( V_2 ) < 0 ) {
F_12 ( ( L_142 , V_2 -> V_8 ) ) ;
return - V_245 ;
}
F_225 ( V_2 ) ;
return 0 ;
}
static void F_226 ( struct V_1 * V_2 )
{
if ( V_2 -> V_262 ) {
F_223 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) ;
F_223 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) ;
F_219 ( V_2 ) ;
}
F_215 ( V_2 ) ;
}
static int F_227 ( struct V_1 * V_2 )
{
if ( F_228 ( V_2 -> V_154 , V_248 , L_143 ) == NULL ) {
F_12 ( ( L_144 ,
V_2 -> V_8 , V_2 -> V_154 ) ) ;
V_2 -> V_36 = V_456 ;
goto V_457;
}
else
V_2 -> V_458 = true ;
V_2 -> V_459 = F_229 ( V_2 -> V_154 , V_248 ) ;
if ( ! V_2 -> V_459 ) {
F_12 ( ( L_145 ,
V_2 -> V_8 , V_2 -> V_154 ) ) ;
V_2 -> V_36 = V_460 ;
goto V_457;
}
return 0 ;
V_457:
F_230 ( V_2 ) ;
return - V_33 ;
}
static void F_230 ( struct V_1 * V_2 )
{
if ( V_2 -> V_461 ) {
F_231 ( V_2 -> V_155 , V_2 ) ;
V_2 -> V_461 = false ;
}
if ( V_2 -> V_458 ) {
F_232 ( V_2 -> V_154 , V_248 ) ;
V_2 -> V_458 = false ;
}
if ( V_2 -> V_459 ) {
F_233 ( V_2 -> V_459 ) ;
V_2 -> V_459 = NULL ;
}
}
static void F_234 ( struct V_1 * V_2 )
{
char * V_462 ;
V_2 -> V_35 = NULL ;
V_2 -> line = V_31 ;
sprintf ( V_2 -> V_8 , L_146 , V_463 , V_2 -> line ) ;
if ( V_2 -> line < V_464 ) {
if ( V_465 [ V_2 -> line ] )
V_2 -> V_77 = V_465 [ V_2 -> line ] ;
}
V_31 ++ ;
if ( ! V_34 )
V_34 = V_2 ;
else {
struct V_1 * V_466 = V_34 ;
while( V_466 -> V_35 )
V_466 = V_466 -> V_35 ;
V_466 -> V_35 = V_2 ;
}
if ( V_2 -> V_77 < 4096 )
V_2 -> V_77 = 4096 ;
else if ( V_2 -> V_77 > 65535 )
V_2 -> V_77 = 65535 ;
switch( V_2 -> V_450 -> V_467 ) {
case V_468 :
V_462 = L_147 ;
break;
case V_469 :
V_462 = L_148 ;
break;
case V_470 :
V_462 = L_149 ;
break;
case V_471 :
V_462 = L_150 ;
V_2 -> V_68 . V_69 = V_89 ;
break;
default:
V_462 = L_151 ;
}
F_2 ( L_152 ,
V_462 , V_2 -> V_8 , V_2 -> V_154 ,
V_2 -> V_155 , V_2 -> V_77 ) ;
#if V_303
F_126 ( V_2 ) ;
#endif
}
static struct V_1 * F_235 ( int V_472 , int V_473 , struct V_474 * V_450 )
{
struct V_1 * V_2 ;
V_2 = F_214 ( sizeof( struct V_1 ) , V_361 ) ;
if ( ! V_2 ) {
F_12 ( ( L_153 ,
V_32 , V_472 , V_473 ) ) ;
} else {
F_236 ( & V_2 -> V_38 ) ;
V_2 -> V_38 . V_25 = & V_475 ;
V_2 -> V_18 = V_19 ;
F_237 ( & V_2 -> V_277 , F_142 ) ;
V_2 -> V_77 = 4096 ;
V_2 -> V_147 = 14745600 ;
V_2 -> V_314 = V_387 ;
V_2 -> V_38 . V_476 = 5 * V_253 / 10 ;
V_2 -> V_38 . V_477 = 30 * V_253 ;
F_199 ( & V_2 -> V_294 ) ;
F_199 ( & V_2 -> V_295 ) ;
F_238 ( & V_2 -> V_48 ) ;
memcpy ( & V_2 -> V_68 , & V_478 , sizeof( T_7 ) ) ;
V_2 -> V_385 = V_479 ;
V_2 -> V_472 = V_472 ;
V_2 -> V_473 = V_473 ;
F_239 ( & V_2 -> V_71 , V_480 , ( unsigned long ) V_2 ) ;
F_239 ( & V_2 -> V_271 , V_481 , ( unsigned long ) V_2 ) ;
V_2 -> V_450 = V_450 ;
V_2 -> V_155 = V_450 -> V_249 ;
V_2 -> V_154 = F_240 ( V_450 , 0 ) ;
V_2 -> V_482 = V_483 ;
V_2 -> V_484 = V_485 ;
V_2 -> V_36 = - 1 ;
}
return V_2 ;
}
static void F_241 ( int V_472 , struct V_474 * V_450 )
{
struct V_1 * V_353 [ V_486 ] ;
int V_6 ;
int V_352 = 1 ;
if ( V_450 -> V_467 == V_469 )
V_352 = 2 ;
else if ( V_450 -> V_467 == V_470 )
V_352 = 4 ;
for ( V_6 = 0 ; V_6 < V_352 ; ++ V_6 ) {
V_353 [ V_6 ] = F_235 ( V_472 , V_6 , V_450 ) ;
if ( V_353 [ V_6 ] == NULL ) {
for ( -- V_6 ; V_6 >= 0 ; -- V_6 ) {
F_242 ( & V_353 [ V_6 ] -> V_38 ) ;
F_176 ( V_353 [ V_6 ] ) ;
}
return;
}
}
for ( V_6 = 0 ; V_6 < V_352 ; ++ V_6 ) {
memcpy ( V_353 [ V_6 ] -> V_353 , V_353 , sizeof( V_353 ) ) ;
F_234 ( V_353 [ V_6 ] ) ;
V_353 [ V_6 ] -> V_352 = V_352 ;
F_238 ( & V_353 [ V_6 ] -> V_54 ) ;
}
if ( ! F_227 ( V_353 [ 0 ] ) ) {
F_224 ( V_353 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_352 ; ++ V_6 ) {
V_353 [ V_6 ] -> V_155 = V_353 [ 0 ] -> V_155 ;
V_353 [ V_6 ] -> V_459 = V_353 [ 0 ] -> V_459 ;
F_224 ( V_353 [ V_6 ] ) ;
}
if ( F_243 ( V_353 [ 0 ] -> V_155 ,
F_171 ,
V_353 [ 0 ] -> V_484 ,
V_353 [ 0 ] -> V_8 ,
V_353 [ 0 ] ) < 0 ) {
F_12 ( ( L_154 ,
V_353 [ 0 ] -> V_8 ,
V_353 [ 0 ] -> V_155 ) ) ;
} else {
V_353 [ 0 ] -> V_461 = true ;
F_244 ( V_353 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_352 ; V_6 ++ ) {
V_353 [ V_6 ] -> V_36 = V_353 [ 0 ] -> V_36 ;
V_353 [ V_6 ] -> V_357 = V_353 [ 0 ] -> V_357 ;
}
}
}
for ( V_6 = 0 ; V_6 < V_352 ; ++ V_6 ) {
struct V_1 * V_2 = V_353 [ V_6 ] ;
F_245 ( & V_2 -> V_38 , V_487 , V_2 -> line ,
& V_2 -> V_450 -> V_179 ) ;
}
}
static int F_246 ( struct V_474 * V_179 ,
const struct V_488 * V_489 )
{
if ( F_247 ( V_179 ) ) {
F_2 ( L_155 , V_179 ) ;
return - V_75 ;
}
F_248 ( V_179 ) ;
F_241 ( V_31 , V_179 ) ;
return 0 ;
}
static void F_249 ( struct V_474 * V_179 )
{
}
static void F_250 ( void )
{
int V_148 ;
struct V_1 * V_2 ;
struct V_1 * V_490 ;
F_2 ( V_491 L_156 , V_32 ) ;
if ( V_487 ) {
for ( V_2 = V_34 ; V_2 != NULL ; V_2 = V_2 -> V_35 )
F_251 ( V_487 , V_2 -> line ) ;
V_148 = F_252 ( V_487 ) ;
if ( V_148 )
F_12 ( ( L_157 , V_148 ) ) ;
F_253 ( V_487 ) ;
}
V_2 = V_34 ;
while( V_2 ) {
F_254 ( V_2 ) ;
V_2 = V_2 -> V_35 ;
}
V_2 = V_34 ;
while( V_2 ) {
#if V_303
F_131 ( V_2 ) ;
#endif
F_226 ( V_2 ) ;
F_215 ( V_2 ) ;
if ( V_2 -> V_473 == 0 )
F_230 ( V_2 ) ;
V_490 = V_2 ;
V_2 = V_2 -> V_35 ;
F_242 ( & V_490 -> V_38 ) ;
F_176 ( V_490 ) ;
}
if ( V_492 )
F_255 ( & V_493 ) ;
}
static int T_10 F_256 ( void )
{
int V_148 ;
F_2 ( V_491 L_158 , V_32 ) ;
V_487 = F_257 ( V_464 ) ;
if ( ! V_487 ) {
F_2 ( L_159 , V_32 ) ;
return - V_245 ;
}
V_487 -> V_32 = V_494 ;
V_487 -> V_17 = V_463 ;
V_487 -> V_495 = V_496 ;
V_487 -> V_497 = 64 ;
V_487 -> type = V_498 ;
V_487 -> V_499 = V_500 ;
V_487 -> V_501 = V_502 ;
V_487 -> V_501 . V_59 =
V_503 | V_372 | V_365 | V_364 | V_380 ;
V_487 -> V_501 . V_504 = 9600 ;
V_487 -> V_501 . V_505 = 9600 ;
V_487 -> V_22 = V_506 | V_507 ;
F_258 ( V_487 , & V_25 ) ;
if ( ( V_148 = F_259 ( V_487 ) ) < 0 ) {
F_12 ( ( L_160 , V_32 ) ) ;
F_253 ( V_487 ) ;
V_487 = NULL ;
goto error;
}
F_2 ( V_491 L_161 ,
V_32 , V_487 -> V_495 ) ;
V_31 = 0 ;
if ( ( V_148 = F_260 ( & V_493 ) ) < 0 ) {
F_2 ( L_162 , V_32 , V_148 ) ;
goto error;
}
V_492 = true ;
if ( ! V_34 )
F_2 ( L_163 , V_32 ) ;
return 0 ;
error:
F_250 () ;
return V_148 ;
}
static void T_11 F_261 ( void )
{
F_250 () ;
}
static T_1 F_262 ( struct V_1 * V_2 , unsigned int V_508 )
{
F_263 () ;
return F_264 ( ( void V_509 * ) V_459 ) ;
}
static void F_265 ( struct V_1 * V_2 , unsigned int V_508 , T_1 V_174 )
{
F_263 () ;
F_266 ( V_174 , ( void V_509 * ) V_459 ) ;
}
static T_12 F_98 ( struct V_1 * V_2 , unsigned int V_508 )
{
F_263 () ;
return F_267 ( ( void V_509 * ) V_459 ) ;
}
static void F_99 ( struct V_1 * V_2 , unsigned int V_508 , T_12 V_174 )
{
F_263 () ;
F_268 ( V_174 , ( void V_509 * ) V_459 ) ;
}
static T_8 F_164 ( struct V_1 * V_2 , unsigned int V_508 )
{
F_263 () ;
return F_269 ( ( void V_509 * ) V_459 ) ;
}
static void F_165 ( struct V_1 * V_2 , unsigned int V_508 , T_8 V_174 )
{
F_263 () ;
F_270 ( V_174 , ( void V_509 * ) V_459 ) ;
}
static void F_271 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_165 ( V_2 , V_332 , V_266 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_164 ( V_2 , V_332 ) & V_267 ) )
break;
}
static void F_168 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_165 ( V_2 , V_335 , V_266 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_164 ( V_2 , V_335 ) & V_267 ) )
break;
}
static void F_272 ( struct V_1 * V_2 )
{
F_99 ( V_2 , V_409 , ( unsigned short ) ( F_98 ( V_2 , V_409 ) | V_296 ) ) ;
if ( V_2 -> V_68 . V_69 != V_89 ) {
F_265 ( V_2 , V_510 , 0x49 ) ;
if ( V_2 -> V_68 . V_137 )
F_273 ( V_2 , V_2 -> V_68 . V_137 ) ;
else
F_273 ( V_2 , 3686400 ) ;
}
}
static void F_273 ( struct V_1 * V_2 , T_9 V_511 )
{
unsigned int div ;
unsigned int V_512 = V_2 -> V_147 ;
if ( V_511 ) {
div = V_512 / V_511 ;
if ( ! ( V_512 % V_511 ) && div )
div -- ;
F_99 ( V_2 , V_513 , ( unsigned short ) div ) ;
}
}
static void F_157 ( struct V_1 * V_2 )
{
unsigned short V_338 ;
V_338 = F_98 ( V_2 , V_389 ) & ~ V_266 ;
F_99 ( V_2 , V_389 , ( unsigned short ) ( V_338 | V_296 ) ) ;
F_99 ( V_2 , V_389 , V_338 ) ;
F_150 ( V_2 , V_331 + V_312 + V_327 ) ;
F_99 ( V_2 , V_311 , V_327 + V_331 ) ;
F_271 ( V_2 ) ;
V_2 -> V_388 = false ;
V_2 -> V_283 = false ;
}
static void F_147 ( struct V_1 * V_2 )
{
unsigned short V_338 ;
F_150 ( V_2 , V_331 + V_312 ) ;
F_99 ( V_2 , V_311 , V_331 ) ;
V_338 = F_98 ( V_2 , V_389 ) & ~ V_266 ;
F_99 ( V_2 , V_389 , ( unsigned short ) ( V_338 | V_296 ) ) ;
F_99 ( V_2 , V_389 , V_338 ) ;
F_271 ( V_2 ) ;
F_225 ( V_2 ) ;
if ( V_2 -> V_319 ) {
F_99 ( V_2 , V_409 , ( unsigned short ) ( F_98 ( V_2 , V_409 ) & ~ V_514 ) ) ;
F_181 ( V_2 , V_312 ) ;
if ( V_2 -> V_68 . V_69 == V_89 ) {
F_165 ( V_2 , V_332 , V_177 ) ;
}
} else {
F_99 ( V_2 , V_409 , ( unsigned short ) ( F_98 ( V_2 , V_409 ) | V_514 ) ) ;
F_165 ( V_2 , V_515 , V_2 -> V_15 [ 0 ] . V_453 ) ;
if ( V_2 -> V_68 . V_69 != V_89 ) {
F_165 ( V_2 , V_332 , ( V_296 + V_267 ) ) ;
} else {
F_165 ( V_2 , V_332 , ( V_177 + V_296 + V_267 ) ) ;
}
}
F_181 ( V_2 , V_331 ) ;
F_99 ( V_2 , V_389 , ( unsigned short ) ( F_98 ( V_2 , V_389 ) | V_266 ) ) ;
V_2 -> V_283 = false ;
V_2 -> V_388 = true ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_82 ) {
F_99 ( V_2 , V_176 ,
( unsigned short ) ( ( F_98 ( V_2 , V_176 ) | V_266 ) & ~ V_296 ) ) ;
V_2 -> V_82 = true ;
}
if ( F_135 ( V_2 -> V_11 [ V_2 -> V_336 ] ) ) {
V_2 -> V_339 = false ;
if ( V_2 -> V_68 . V_69 != V_89 ) {
if ( V_2 -> V_68 . V_22 & V_516 ) {
F_86 ( V_2 ) ;
if ( ! ( V_2 -> V_62 & V_63 ) ) {
V_2 -> V_62 |= V_63 ;
F_32 ( V_2 ) ;
V_2 -> V_339 = true ;
}
}
F_150 ( V_2 , V_337 ) ;
F_181 ( V_2 , V_326 + V_318 ) ;
F_99 ( V_2 , V_311 , ( unsigned short ) ( V_318 + V_326 ) ) ;
} else {
F_150 ( V_2 , V_337 ) ;
F_181 ( V_2 , V_318 ) ;
F_99 ( V_2 , V_311 , V_318 ) ;
}
F_165 ( V_2 , V_517 , V_2 -> V_11 [ V_2 -> V_336 ] . V_453 ) ;
F_165 ( V_2 , V_335 , V_296 + V_267 ) ;
V_2 -> V_86 = true ;
}
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned short V_338 ;
F_169 ( & V_2 -> V_71 ) ;
F_168 ( V_2 ) ;
V_338 = F_98 ( V_2 , V_176 ) & ~ V_266 ;
F_99 ( V_2 , V_176 , ( unsigned short ) ( V_338 | V_296 ) ) ;
F_150 ( V_2 , V_337 + V_318 + V_326 ) ;
F_99 ( V_2 , V_311 , ( unsigned short ) ( V_318 + V_326 ) ) ;
F_274 ( V_2 ) ;
V_2 -> V_82 = false ;
V_2 -> V_86 = false ;
}
static void F_254 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_459 )
return;
F_53 ( V_2 ) ;
F_157 ( V_2 ) ;
V_2 -> V_62 &= ~ ( V_63 | V_64 ) ;
F_32 ( V_2 ) ;
F_150 ( V_2 , V_362 | V_363 ) ;
}
static void F_275 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_352 ; ++ V_6 ) {
if ( V_2 -> V_353 [ V_6 ] )
F_254 ( V_2 -> V_353 [ V_6 ] ) ;
}
}
static void F_180 ( struct V_1 * V_2 )
{
unsigned short V_338 ;
F_150 ( V_2 , V_362 | V_363 ) ;
F_53 ( V_2 ) ;
F_157 ( V_2 ) ;
V_338 = 0x4000 ;
if ( V_2 -> V_412 & V_413 )
V_338 |= V_414 ;
if ( V_2 -> V_68 . V_128 != V_378 ) {
V_338 |= V_518 ;
if ( V_2 -> V_68 . V_128 == V_376 )
V_338 |= V_354 ;
}
switch ( V_2 -> V_68 . V_142 )
{
case 6 : V_338 |= V_334 ; break;
case 7 : V_338 |= V_333 ; break;
case 8 : V_338 |= V_333 + V_334 ; break;
}
if ( V_2 -> V_68 . V_143 != 1 )
V_338 |= V_288 ;
if ( V_2 -> V_68 . V_22 & V_519 )
V_338 |= V_267 ;
F_99 ( V_2 , V_176 , V_338 ) ;
V_338 = 0x4000 ;
if ( V_2 -> V_68 . V_128 != V_378 ) {
V_338 |= V_518 ;
if ( V_2 -> V_68 . V_128 == V_376 )
V_338 |= V_354 ;
}
switch ( V_2 -> V_68 . V_142 )
{
case 6 : V_338 |= V_334 ; break;
case 7 : V_338 |= V_333 ; break;
case 8 : V_338 |= V_333 + V_334 ; break;
}
if ( V_2 -> V_68 . V_22 & V_520 )
V_338 |= V_267 ;
F_99 ( V_2 , V_389 , V_338 ) ;
F_265 ( V_2 , V_510 , 0x69 ) ;
F_197 ( V_2 ) ;
V_338 = V_316 + V_514 + V_267 ;
if ( ( F_164 ( V_2 , V_521 ) & V_354 ) && V_2 -> V_68 . V_85 &&
( ( V_2 -> V_147 < ( V_2 -> V_68 . V_85 * 16 ) ) ||
( V_2 -> V_147 % ( V_2 -> V_68 . V_85 * 16 ) ) ) ) {
V_338 |= V_288 ;
F_273 ( V_2 , V_2 -> V_68 . V_85 * 8 ) ;
} else {
F_273 ( V_2 , V_2 -> V_68 . V_85 * 16 ) ;
}
F_99 ( V_2 , V_409 , V_338 ) ;
F_181 ( V_2 , V_320 | V_331 ) ;
if ( V_2 -> V_68 . V_135 )
F_272 ( V_2 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
unsigned short V_338 ;
F_150 ( V_2 , V_362 | V_363 ) ;
F_53 ( V_2 ) ;
F_157 ( V_2 ) ;
V_338 = V_296 ;
switch( V_2 -> V_68 . V_69 ) {
case V_282 :
V_338 |= V_316 + V_522 ;
break;
case V_280 : V_338 |= V_514 + V_522 ; break;
case V_281 : V_338 |= V_316 ; break;
case V_279 : V_338 |= V_522 ; break;
}
if ( V_2 -> V_412 & V_413 )
V_338 |= V_414 ;
switch( V_2 -> V_68 . V_136 )
{
case V_523 : V_338 |= V_315 ; break;
case V_524 : V_338 |= V_525 ; break;
case V_526 : V_338 |= V_525 + V_315 ; break;
case V_187 : V_338 |= V_527 ; break;
case V_189 : V_338 |= V_527 + V_315 ; break;
case V_191 : V_338 |= V_527 + V_525 ; break;
case V_528 : V_338 |= V_527 + V_525 + V_315 ; break;
}
switch ( V_2 -> V_68 . V_139 & V_529 )
{
case V_195 : V_338 |= V_518 ; break;
case V_197 : V_338 |= V_518 + V_354 ; break;
}
if ( V_2 -> V_68 . V_141 != V_530 )
V_338 |= V_177 ;
switch ( V_2 -> V_68 . V_140 )
{
case V_531 : V_338 |= V_333 ; break;
case V_532 : V_338 |= V_334 ; break;
case V_533 : V_338 |= V_333 + V_334 ; break;
}
if ( V_2 -> V_68 . V_22 & V_519 )
V_338 |= V_267 ;
F_99 ( V_2 , V_176 , V_338 ) ;
switch ( V_2 -> V_68 . V_141 )
{
case V_534 : V_338 = 0x7e ; break;
case V_535 : V_338 = 0xff ; break;
case V_536 : V_338 = 0x00 ; break;
case V_537 : V_338 = 0x55 ; break;
case V_538 : V_338 = 0xaa ; break;
default: V_338 = 0x7e ; break;
}
F_265 ( V_2 , V_539 , ( unsigned char ) V_338 ) ;
V_338 = 0 ;
switch( V_2 -> V_68 . V_69 ) {
case V_282 :
V_338 |= V_316 + V_522 ;
break;
case V_280 : V_338 |= V_514 + V_522 ; break;
case V_281 : V_338 |= V_316 ; break;
case V_279 : V_338 |= V_522 ; break;
}
switch( V_2 -> V_68 . V_136 )
{
case V_523 : V_338 |= V_315 ; break;
case V_524 : V_338 |= V_525 ; break;
case V_526 : V_338 |= V_525 + V_315 ; break;
case V_187 : V_338 |= V_527 ; break;
case V_189 : V_338 |= V_527 + V_315 ; break;
case V_191 : V_338 |= V_527 + V_525 ; break;
case V_528 : V_338 |= V_527 + V_525 + V_315 ; break;
}
switch ( V_2 -> V_68 . V_139 & V_529 )
{
case V_195 : V_338 |= V_518 ; break;
case V_197 : V_338 |= V_518 + V_354 ; break;
}
if ( V_2 -> V_68 . V_22 & V_520 )
V_338 |= V_267 ;
F_99 ( V_2 , V_389 , V_338 ) ;
V_338 = 0 ;
if ( V_2 -> V_68 . V_22 & V_225 )
{
if ( V_2 -> V_68 . V_22 & V_220 )
V_338 |= V_177 + V_333 ;
else
V_338 |= V_177 ;
}
else if ( V_2 -> V_68 . V_22 & V_224 )
V_338 |= V_414 ;
else if ( V_2 -> V_68 . V_22 & V_226 )
V_338 |= V_333 ;
if ( V_2 -> V_68 . V_22 & V_221 )
V_338 |= V_288 ;
else if ( V_2 -> V_68 . V_22 & V_220 )
V_338 |= V_334 ;
else if ( V_2 -> V_68 . V_22 & V_222 )
V_338 |= V_296 ;
if ( V_2 -> V_68 . V_137 )
V_338 |= V_266 + V_267 ;
F_265 ( V_2 , V_510 , ( unsigned char ) V_338 ) ;
if ( V_2 -> V_68 . V_22 & ( V_224 + V_220 ) )
{
switch( V_2 -> V_68 . V_136 )
{
case V_187 :
case V_189 :
V_338 = V_414 ; break;
case V_191 :
case V_528 :
V_338 = V_414 + V_177 ; break;
default: V_338 = V_177 ;
}
F_99 ( V_2 , V_389 , ( unsigned short ) ( F_98 ( V_2 , V_389 ) | V_338 ) ) ;
F_273 ( V_2 , V_2 -> V_68 . V_137 * 16 ) ;
}
else
F_273 ( V_2 , V_2 -> V_68 . V_137 ) ;
F_189 ( V_2 ) ;
F_197 ( V_2 ) ;
F_99 ( V_2 , V_409 , V_316 + V_514 + V_267 ) ;
if ( V_2 -> V_68 . V_135 )
F_272 ( V_2 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
unsigned char V_338 ;
unsigned short V_540 ;
V_540 = F_98 ( V_2 , V_176 ) ;
if ( V_2 -> V_385 & V_541 ) {
V_540 = ( V_540 & ~ ( V_177 + V_333 ) ) | V_334 ;
F_265 ( V_2 , V_539 , ( unsigned char ) ( ( V_2 -> V_385 >> 8 ) & 0xff ) ) ;
} else if ( ! ( V_540 & V_177 ) ) {
V_540 &= ~ ( V_333 + V_334 ) ;
}
F_99 ( V_2 , V_176 , V_540 ) ;
if ( V_2 -> V_385 & ( V_542 | V_541 ) ) {
V_338 = ( unsigned char ) ( V_2 -> V_385 & 0xff ) ;
} else {
switch( V_2 -> V_385 )
{
case V_479 : V_338 = 0x7e ; break;
case V_543 :
case V_544 : V_338 = 0xaa ; break;
case V_545 :
case V_546 : V_338 = 0x00 ; break;
default: V_338 = 0xff ;
}
}
F_265 ( V_2 , V_547 , V_338 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_98 ( V_2 , V_311 ) ;
V_2 -> V_62 &= V_63 | V_64 ;
if ( V_12 & V_288 )
V_2 -> V_62 |= V_157 ;
if ( V_12 & V_296 )
V_2 -> V_62 |= V_156 ;
if ( V_12 & V_266 )
V_2 -> V_62 |= V_158 ;
if ( V_12 & V_267 )
V_2 -> V_62 |= V_159 ;
}
static void F_197 ( struct V_1 * V_2 )
{
unsigned char V_338 = 0 ;
switch( V_2 -> V_412 & V_548 )
{
case V_549 :
V_338 |= V_333 ;
break;
case V_550 :
V_338 |= V_414 + V_177 + V_333 ;
break;
case V_551 :
V_338 |= V_177 ;
break;
}
if ( V_2 -> V_412 & V_552 )
V_338 |= V_334 ;
if ( V_2 -> V_62 & V_64 )
V_338 |= V_288 ;
if ( V_2 -> V_62 & V_63 )
V_338 |= V_296 ;
if ( V_2 -> V_412 & V_553 )
V_338 |= V_266 ;
if ( V_2 -> V_412 & V_554 )
V_338 |= V_267 ;
F_265 ( V_2 , V_555 , V_338 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned char V_338 = F_262 ( V_2 , V_555 ) ;
if ( V_2 -> V_62 & V_64 )
V_338 |= V_288 ;
else
V_338 &= ~ V_288 ;
if ( V_2 -> V_62 & V_63 )
V_338 |= V_296 ;
else
V_338 &= ~ V_296 ;
F_265 ( V_2 , V_555 , V_338 ) ;
}
static void F_139 ( struct V_1 * V_2 , unsigned int V_6 , unsigned int V_556 )
{
int V_557 = 0 ;
while( ! V_557 ) {
V_2 -> V_15 [ V_6 ] . V_12 = 0 ;
F_158 ( V_2 -> V_15 [ V_6 ] , V_2 -> V_314 ) ;
if ( V_6 == V_556 )
V_557 = 1 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
}
V_2 -> V_13 = V_6 ;
}
static void F_225 ( struct V_1 * V_2 )
{
F_139 ( V_2 , 0 , V_2 -> V_14 - 1 ) ;
V_2 -> V_309 = 0 ;
V_2 -> V_308 = 0 ;
}
static bool F_145 ( struct V_1 * V_2 )
{
unsigned int V_258 , V_259 ;
unsigned short V_12 ;
unsigned int V_558 = 0 ;
unsigned long V_22 ;
struct V_20 * V_21 = V_2 -> V_38 . V_21 ;
unsigned char V_559 = 0xff ;
unsigned int V_560 = 0 ;
switch ( V_2 -> V_68 . V_139 & V_529 ) {
case V_195 : V_560 = 2 ; break;
case V_197 : V_560 = 4 ; break;
}
V_561:
V_558 = 0 ;
V_559 = 0xff ;
V_258 = V_259 = V_2 -> V_13 ;
for (; ; ) {
if ( ! F_134 ( V_2 -> V_15 [ V_259 ] ) )
goto V_44;
if ( V_558 == 0 && V_2 -> V_68 . V_138 != 0xff )
V_559 = V_2 -> V_15 [ V_259 ] . V_73 [ 0 ] ;
V_558 += F_135 ( V_2 -> V_15 [ V_259 ] ) ;
if ( F_276 ( V_2 -> V_15 [ V_259 ] ) )
break;
if ( ++ V_259 == V_2 -> V_14 )
V_259 = 0 ;
if ( V_259 == V_2 -> V_13 ) {
if ( V_2 -> V_388 ) {
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_147 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
}
goto V_44;
}
}
V_12 = F_277 ( V_2 -> V_15 [ V_259 ] ) ;
if ( ( V_2 -> V_68 . V_139 & V_529 ) == V_193 )
V_12 &= ~ V_266 ;
if ( V_558 == 0 ||
( V_559 != 0xff && V_559 != V_2 -> V_68 . V_138 ) ) {
F_139 ( V_2 , V_258 , V_259 ) ;
goto V_561;
}
if ( V_558 < ( 2 + V_560 ) || V_12 & V_267 ) {
V_2 -> V_117 . V_164 ++ ;
V_558 = 0 ;
} else if ( V_12 & V_266 ) {
V_2 -> V_117 . V_167 ++ ;
if ( ! ( V_2 -> V_68 . V_139 & V_562 ) )
V_558 = 0 ;
}
#if V_303
if ( V_558 == 0 ) {
V_2 -> V_238 -> V_202 . V_563 ++ ;
V_2 -> V_238 -> V_202 . V_564 ++ ;
}
#endif
F_144 ( ( L_164 ,
V_2 -> V_8 , V_12 , V_558 ) ) ;
F_137 ( V_2 , V_2 -> V_15 [ V_258 ] . V_73 , F_44 ( int , V_558 , V_2 -> V_314 ) , L_94 ) ;
if ( V_558 ) {
if ( ! ( V_2 -> V_68 . V_139 & V_562 ) ) {
V_558 -= V_560 ;
V_560 = 0 ;
}
if ( V_558 > V_2 -> V_77 + V_560 )
V_2 -> V_117 . V_165 ++ ;
else {
int V_565 = V_558 ;
int V_6 = V_258 ;
unsigned char * V_260 = V_2 -> V_447 ;
V_2 -> V_566 = V_558 ;
V_2 -> V_117 . V_161 ++ ;
while( V_565 ) {
int V_567 = F_44 ( int , V_565 , V_2 -> V_314 ) ;
memcpy ( V_260 , V_2 -> V_15 [ V_6 ] . V_73 , V_567 ) ;
V_260 += V_567 ;
V_565 -= V_567 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
}
if ( V_2 -> V_68 . V_139 & V_562 ) {
* V_260 = ( V_12 & V_266 ) ? V_568 : V_569 ;
V_558 ++ ;
}
#if V_303
if ( V_2 -> V_49 )
F_121 ( V_2 , V_2 -> V_447 , V_558 ) ;
else
#endif
F_8 ( V_21 , V_2 -> V_447 , V_2 -> V_448 , V_558 ) ;
}
}
F_139 ( V_2 , V_258 , V_259 ) ;
return true ;
V_44:
return false ;
}
static bool F_146 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_2 -> V_13 ;
unsigned int V_4 ;
if ( ! F_134 ( V_2 -> V_15 [ V_6 ] ) )
return false ;
V_4 = F_135 ( V_2 -> V_15 [ V_6 ] ) ;
switch( V_2 -> V_68 . V_69 ) {
case V_280 :
case V_281 :
case V_282 :
if ( F_278 ( V_2 -> V_15 [ V_6 ] ) )
V_4 -- ;
break;
}
F_137 ( V_2 , V_2 -> V_15 [ V_6 ] . V_73 , V_4 , L_94 ) ;
F_13 ( ( L_165 , V_4 ) ) ;
if ( V_4 )
F_8 ( V_2 -> V_38 . V_21 , V_2 -> V_15 [ V_6 ] . V_73 ,
V_2 -> V_448 , V_4 ) ;
F_139 ( V_2 , V_6 , V_6 ) ;
return true ;
}
static void F_274 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_2 -> V_9 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_12 = 0 ;
V_2 -> V_11 [ V_6 ] . V_4 = 0 ;
}
}
static unsigned int F_279 ( struct V_1 * V_2 )
{
unsigned int V_4 = 0 ;
unsigned int V_6 = V_2 -> V_9 ;
do
{
if ( F_135 ( V_2 -> V_11 [ V_6 ] ) )
break;
++ V_4 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
} while ( V_6 != V_2 -> V_9 );
if ( V_4 && ( F_164 ( V_2 , V_335 ) & V_267 ) )
-- V_4 ;
return V_4 ;
}
static unsigned int F_36 ( struct V_1 * V_2 )
{
unsigned int V_570 = 0 ;
unsigned int V_6 = V_2 -> V_9 ;
unsigned int V_571 ;
unsigned int V_4 ;
unsigned int V_572 = 0 ;
do {
V_4 = F_135 ( V_2 -> V_11 [ V_6 ] ) ;
if ( V_4 )
V_570 += V_4 ;
else if ( ! V_570 )
V_572 = V_2 -> V_11 [ V_6 ] . V_573 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
} while ( V_6 != V_2 -> V_9 );
V_571 = F_164 ( V_2 , V_335 ) ;
if ( V_571 & V_267 )
V_570 += V_572 ;
V_570 += ( V_571 >> 8 ) & 0xff ;
if ( V_2 -> V_86 )
V_570 ++ ;
return V_570 ;
}
static bool F_40 ( struct V_1 * V_2 , const char * V_73 , unsigned int V_209 )
{
unsigned short V_4 ;
unsigned int V_6 ;
struct V_261 * V_574 ;
if ( F_280 ( V_209 , V_387 ) > F_279 ( V_2 ) )
return false ;
F_137 ( V_2 , V_73 , V_209 , L_166 ) ;
V_2 -> V_336 = V_6 = V_2 -> V_9 ;
while ( V_209 ) {
V_574 = & V_2 -> V_11 [ V_6 ] ;
V_4 = ( unsigned short ) ( ( V_209 > V_387 ) ? V_387 : V_209 ) ;
memcpy ( V_574 -> V_73 , V_73 , V_4 ) ;
V_209 -= V_4 ;
V_73 += V_4 ;
if ( ( ! V_209 && V_2 -> V_68 . V_69 == V_70 ) ||
V_2 -> V_68 . V_69 == V_279 )
F_281 ( * V_574 , 1 ) ;
else
F_281 ( * V_574 , 0 ) ;
if ( V_6 != V_2 -> V_336 )
F_158 ( * V_574 , V_4 ) ;
V_574 -> V_573 = V_4 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
}
V_2 -> V_9 = V_6 ;
V_574 = & V_2 -> V_11 [ V_2 -> V_336 ] ;
F_158 ( * V_574 , V_574 -> V_573 ) ;
if ( ! V_2 -> V_86 )
F_43 ( V_2 ) ;
F_35 ( V_2 ) ;
return true ;
}
static int F_282 ( struct V_1 * V_2 )
{
static unsigned short V_575 [] =
{ 0x0000 , 0xffff , 0xaaaa , 0x5555 , 0x6969 , 0x9696 } ;
static unsigned int V_4 = F_283 ( V_575 ) ;
unsigned int V_6 ;
int V_148 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
F_99 ( V_2 , V_547 , V_575 [ V_6 ] ) ;
F_99 ( V_2 , V_513 , V_575 [ ( V_6 + 1 ) % V_4 ] ) ;
if ( ( F_98 ( V_2 , V_547 ) != V_575 [ V_6 ] ) ||
( F_98 ( V_2 , V_513 ) != V_575 [ ( V_6 + 1 ) % V_4 ] ) ) {
V_148 = - V_33 ;
break;
}
}
V_2 -> V_357 = ( F_164 ( V_2 , V_521 ) & V_333 ) ? 1 : 0 ;
V_2 -> V_36 = V_148 ? 0 : V_576 ;
return V_148 ;
}
static int F_284 ( struct V_1 * V_2 )
{
unsigned long V_52 ;
unsigned long V_22 ;
struct V_20 * V_577 = V_2 -> V_38 . V_21 ;
T_9 V_578 = V_2 -> V_68 . V_85 ;
V_2 -> V_68 . V_85 = 921600 ;
V_2 -> V_38 . V_21 = NULL ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_180 ( V_2 ) ;
F_181 ( V_2 , V_318 ) ;
F_99 ( V_2 , V_176 ,
( unsigned short ) ( F_98 ( V_2 , V_176 ) | V_266 ) ) ;
F_99 ( V_2 , V_579 , 0 ) ;
V_2 -> V_36 = V_580 ;
V_2 -> V_317 = false ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_52 = 100 ;
while( V_52 -- && ! V_2 -> V_317 )
F_45 ( 10 ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_254 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_68 . V_85 = V_578 ;
V_2 -> V_38 . V_21 = V_577 ;
V_2 -> V_36 = V_2 -> V_317 ? 0 : V_580 ;
return V_2 -> V_317 ? 0 : - V_33 ;
}
static int F_285 ( struct V_1 * V_2 )
{
unsigned char * V_581 , * V_582 ;
int V_4 ;
if ( F_134 ( V_2 -> V_15 [ 0 ] ) ) {
V_4 = F_135 ( V_2 -> V_15 [ 0 ] ) ;
V_581 = V_2 -> V_15 [ 0 ] . V_73 ;
V_582 = V_2 -> V_447 ;
for( ; V_4 ; V_4 -= 2 , V_581 += 2 ) {
if ( ! ( * ( V_581 + 1 ) & ( V_518 + V_354 ) ) ) {
* V_582 = * V_581 ;
V_582 ++ ;
V_2 -> V_566 ++ ;
}
}
F_137 ( V_2 , V_2 -> V_447 , V_2 -> V_566 , L_94 ) ;
return 1 ;
}
return 0 ;
}
static int F_286 ( struct V_1 * V_2 )
{
#define F_287 20
unsigned long V_52 ;
T_13 V_4 = F_287 ;
unsigned char V_73 [ F_287 ] ;
int V_148 = - V_33 ;
unsigned long V_22 ;
struct V_20 * V_577 = V_2 -> V_38 . V_21 ;
T_7 V_68 ;
memcpy ( & V_68 , & V_2 -> V_68 , sizeof( V_68 ) ) ;
V_2 -> V_68 . V_69 = V_89 ;
V_2 -> V_68 . V_85 = 921600 ;
V_2 -> V_68 . V_135 = 1 ;
V_2 -> V_38 . V_21 = NULL ;
for ( V_4 = 0 ; V_4 < F_287 ; ++ V_4 )
V_73 [ V_4 ] = ( unsigned char ) V_4 ;
V_2 -> V_566 = 0 ;
memset ( V_2 -> V_447 , 0 , F_287 ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_180 ( V_2 ) ;
F_147 ( V_2 ) ;
F_40 ( V_2 , V_73 , V_4 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
for ( V_52 = 100 ; V_52 ; -- V_52 ) {
F_45 ( 10 ) ;
if ( F_285 ( V_2 ) ) {
V_148 = 0 ;
break;
}
}
if ( ! V_148 && ( V_2 -> V_566 != V_4 ||
memcmp ( V_73 , V_2 -> V_447 , V_4 ) ) ) {
V_148 = - V_33 ;
}
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_275 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
memcpy ( & V_2 -> V_68 , & V_68 , sizeof( V_2 -> V_68 ) ) ;
V_2 -> V_38 . V_21 = V_577 ;
V_2 -> V_36 = V_148 ? V_583 : 0 ;
return V_148 ;
}
static int F_244 ( struct V_1 * V_2 )
{
F_13 ( ( L_167 , V_2 -> V_8 ) ) ;
if ( F_282 ( V_2 ) < 0 ) {
F_2 ( L_168 ,
V_2 -> V_8 , V_2 -> V_154 ) ;
} else if ( F_284 ( V_2 ) < 0 ) {
F_2 ( L_169 ,
V_2 -> V_8 , V_2 -> V_155 ) ;
} else if ( F_286 ( V_2 ) < 0 ) {
F_2 ( L_170 , V_2 -> V_8 ) ;
}
return V_2 -> V_36 ;
}
static void V_480 ( unsigned long V_584 )
{
struct V_1 * V_2 = (struct V_1 * ) V_584 ;
unsigned long V_22 ;
F_13 ( ( L_171 , V_2 -> V_8 ) ) ;
if( V_2 -> V_86 && V_2 -> V_68 . V_69 == V_70 ) {
V_2 -> V_117 . V_585 ++ ;
}
F_16 ( & V_2 -> V_54 , V_22 ) ;
F_53 ( V_2 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
#if V_303
if ( V_2 -> V_49 )
F_119 ( V_2 ) ;
else
#endif
F_148 ( V_2 ) ;
}
static void V_481 ( unsigned long V_584 )
{
struct V_1 * V_2 = (struct V_1 * ) V_584 ;
unsigned long V_22 ;
F_13 ( ( L_172 , V_2 -> V_8 ) ) ;
F_16 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_170 |= V_272 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_142 ( & V_2 -> V_277 ) ;
}
