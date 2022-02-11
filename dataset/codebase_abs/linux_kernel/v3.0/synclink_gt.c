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
if ( ( line < 0 ) || ( line >= V_31 ) ) {
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
if ( F_14 ( V_28 ) || V_2 -> V_38 . V_22 & V_39 ) {
if ( V_2 -> V_38 . V_22 & V_39 )
F_15 ( & V_2 -> V_38 . V_40 ) ;
V_29 = ( ( V_2 -> V_38 . V_22 & V_41 ) ?
- V_42 : - V_43 ) ;
goto V_44;
}
F_16 ( & V_2 -> V_38 . V_45 ) ;
V_2 -> V_38 . V_21 -> V_46 = ( V_2 -> V_38 . V_22 & V_47 ) ? 1 : 0 ;
F_17 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_49 ) {
V_29 = - V_50 ;
F_18 ( & V_2 -> V_48 , V_22 ) ;
F_19 ( & V_2 -> V_38 . V_45 ) ;
goto V_44;
}
V_2 -> V_38 . V_4 ++ ;
F_18 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_38 . V_4 == 1 ) {
V_29 = F_20 ( V_2 ) ;
if ( V_29 < 0 ) {
F_19 ( & V_2 -> V_38 . V_45 ) ;
goto V_44;
}
}
F_19 ( & V_2 -> V_38 . V_45 ) ;
V_29 = F_21 ( V_21 , V_28 , V_2 ) ;
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
static void F_22 ( struct V_20 * V_21 , struct V_27 * V_28 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_18 ) )
return;
F_13 ( ( L_19 , V_2 -> V_8 , V_2 -> V_38 . V_4 ) ) ;
if ( F_23 ( & V_2 -> V_38 , V_21 , V_28 ) == 0 )
goto V_44;
F_16 ( & V_2 -> V_38 . V_45 ) ;
if ( V_2 -> V_38 . V_22 & V_51 )
F_24 ( V_21 , V_2 -> V_52 ) ;
F_25 ( V_21 ) ;
F_26 ( V_21 ) ;
F_27 ( V_2 ) ;
F_19 ( & V_2 -> V_38 . V_45 ) ;
F_28 ( & V_2 -> V_38 , V_21 ) ;
V_2 -> V_38 . V_21 = NULL ;
V_44:
F_13 ( ( L_20 , V_21 -> V_53 -> V_17 , V_2 -> V_38 . V_4 ) ) ;
}
static void F_29 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_21 ) )
return;
F_13 ( ( L_22 , V_2 -> V_8 ) ) ;
F_25 ( V_21 ) ;
F_16 ( & V_2 -> V_38 . V_45 ) ;
F_27 ( V_2 ) ;
F_17 ( & V_2 -> V_38 . V_54 , V_22 ) ;
V_2 -> V_38 . V_4 = 0 ;
V_2 -> V_38 . V_22 &= ~ V_55 ;
V_2 -> V_38 . V_21 = NULL ;
F_18 ( & V_2 -> V_38 . V_54 , V_22 ) ;
F_19 ( & V_2 -> V_38 . V_45 ) ;
F_30 ( & V_2 -> V_38 . V_56 ) ;
}
static void F_31 ( struct V_20 * V_21 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
F_13 ( ( L_23 , V_21 -> V_53 -> V_17 ) ) ;
F_32 ( V_2 ) ;
if ( V_58 -> V_59 & V_60 &&
! ( V_21 -> V_61 -> V_59 & V_60 ) ) {
V_2 -> V_62 &= ~ ( V_63 + V_64 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_33 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
if ( ! ( V_58 -> V_59 & V_60 ) &&
V_21 -> V_61 -> V_59 & V_60 ) {
V_2 -> V_62 |= V_64 ;
if ( ! ( V_21 -> V_61 -> V_59 & V_65 ) ||
! F_34 ( V_66 , & V_21 -> V_22 ) ) {
V_2 -> V_62 |= V_63 ;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_33 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
if ( V_58 -> V_59 & V_65 &&
! ( V_21 -> V_61 -> V_59 & V_65 ) ) {
V_21 -> V_67 = 0 ;
F_35 ( V_21 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 . V_69 == V_70 ) {
int V_52 = ( F_37 ( V_2 ) * 7 ) + 1000 ;
F_38 ( & V_2 -> V_71 , V_72 + F_39 ( V_52 ) ) ;
}
}
static int F_40 ( struct V_20 * V_21 ,
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
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_79 ) {
if ( ! F_41 ( V_2 , V_2 -> V_76 , V_2 -> V_79 ) )
goto V_44;
V_2 -> V_79 = 0 ;
}
if ( F_41 ( V_2 , V_73 , V_4 ) )
V_74 = V_4 ;
V_44:
F_18 ( & V_2 -> V_54 , V_22 ) ;
F_13 ( ( L_26 , V_2 -> V_8 , V_74 ) ) ;
return V_74 ;
}
static int F_42 ( struct V_20 * V_21 , unsigned char V_80 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
int V_74 = 0 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_27 ) )
return 0 ;
F_13 ( ( L_28 , V_2 -> V_8 , V_80 ) ) ;
if ( ! V_2 -> V_76 )
return 0 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_79 < V_2 -> V_77 ) {
V_2 -> V_76 [ V_2 -> V_79 ++ ] = V_80 ;
V_74 = 1 ;
}
F_18 ( & V_2 -> V_54 , V_22 ) ;
return V_74 ;
}
static void F_43 ( struct V_20 * V_21 , char V_80 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_29 ) )
return;
F_13 ( ( L_30 , V_2 -> V_8 , V_80 ) ) ;
V_2 -> V_81 = V_80 ;
if ( V_80 ) {
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( ! V_2 -> V_82 )
F_44 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
}
static void F_24 ( struct V_20 * V_21 , int V_52 )
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
V_84 = F_45 (unsigned long, char_time, timeout) ;
while ( V_2 -> V_86 ) {
F_46 ( F_47 ( V_84 ) ) ;
if ( F_48 ( V_87 ) )
break;
if ( V_52 && F_49 ( V_72 , V_83 + V_52 ) )
break;
}
exit:
F_13 ( ( L_33 , V_2 -> V_8 ) ) ;
}
static int F_50 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_74 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_34 ) )
return 0 ;
V_74 = ( V_2 -> V_86 ) ? 0 : V_88 ;
F_13 ( ( L_35 , V_2 -> V_8 , V_74 ) ) ;
return V_74 ;
}
static void F_51 ( struct V_20 * V_21 )
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
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_79 && F_41 ( V_2 , V_2 -> V_76 , V_2 -> V_79 ) )
V_2 -> V_79 = 0 ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
static void F_25 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_39 ) )
return;
F_13 ( ( L_40 , V_2 -> V_8 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_79 = 0 ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
F_52 ( V_21 ) ;
}
static void F_53 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_41 ) )
return;
F_13 ( ( L_42 , V_2 -> V_8 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_82 && V_2 -> V_68 . V_69 == V_89 )
F_54 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
static void F_35 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_43 ) )
return;
F_13 ( ( L_44 , V_2 -> V_8 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_79 && F_41 ( V_2 , V_2 -> V_76 , V_2 -> V_79 ) )
V_2 -> V_79 = 0 ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
static int F_55 ( struct V_20 * V_21 ,
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
return F_56 ( V_2 , V_92 ) ;
case V_95 :
return F_57 ( V_2 , ( int ) V_91 ) ;
case V_98 :
return F_58 ( V_2 , V_92 ) ;
case V_99 :
return F_59 ( V_2 , V_92 ) ;
case V_100 :
return F_60 ( V_2 , V_92 ) ;
case V_101 :
return F_61 ( V_2 , V_92 ) ;
case V_102 :
return F_62 ( V_2 , ( int ) V_91 ) ;
case V_103 :
return F_63 ( V_2 , V_92 ) ;
case V_104 :
return F_64 ( V_2 , ( int ) V_91 ) ;
}
F_16 ( & V_2 -> V_38 . V_45 ) ;
switch ( V_90 ) {
case V_105 :
V_74 = F_65 ( V_2 , V_92 ) ;
break;
case V_106 :
V_74 = F_66 ( V_2 , V_92 ) ;
break;
case V_107 :
V_74 = F_67 ( V_2 , V_92 ) ;
break;
case V_108 :
V_74 = F_68 ( V_2 , ( int ) V_91 ) ;
break;
case V_109 :
V_74 = F_69 ( V_2 , ( int ) V_91 ) ;
break;
case V_110 :
V_74 = F_70 ( V_2 , ( int ) V_91 ) ;
break;
case V_111 :
V_74 = F_71 ( V_2 ) ;
break;
case V_112 :
V_74 = F_72 ( V_2 , V_92 ) ;
break;
case V_113 :
V_74 = F_73 ( V_2 , V_92 ) ;
break;
case V_114 :
V_74 = F_74 ( V_2 , ( int ) V_91 ) ;
break;
default:
V_74 = - V_115 ;
}
F_19 ( & V_2 -> V_38 . V_45 ) ;
return V_74 ;
}
static int F_75 ( struct V_20 * V_21 ,
struct V_116 * V_117 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
struct V_118 V_119 ;
unsigned long V_22 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_119 = V_2 -> V_117 ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
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
static long F_76 ( struct V_1 * V_2 , struct V_131 T_2 * V_132 )
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
if ( F_77 ( V_132 , & V_133 , sizeof( struct V_131 ) ) )
return - V_144 ;
return 0 ;
}
static long F_78 ( struct V_1 * V_2 , struct V_131 T_2 * V_145 )
{
struct V_131 V_133 ;
F_13 ( ( L_48 , V_2 -> V_8 ) ) ;
if ( F_79 ( & V_133 , V_145 , sizeof( struct V_131 ) ) )
return - V_144 ;
F_80 ( & V_2 -> V_54 ) ;
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
F_81 ( & V_2 -> V_54 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static long F_83 ( struct V_20 * V_21 ,
unsigned int V_90 , unsigned long V_91 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_148 = - V_115 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_49 ) )
return - V_33 ;
F_13 ( ( L_50 , V_2 -> V_8 , V_90 ) ) ;
switch ( V_90 ) {
case V_149 :
V_148 = F_78 ( V_2 , F_84 ( V_91 ) ) ;
break;
case V_150 :
V_148 = F_76 ( V_2 , F_84 ( V_91 ) ) ;
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
V_148 = F_55 ( V_21 , V_90 , V_91 ) ;
break;
}
F_13 ( ( L_51 , V_2 -> V_8 , V_90 , V_148 ) ) ;
return V_148 ;
}
static inline void F_85 ( struct V_151 * V_152 , struct V_1 * V_2 )
{
char V_153 [ 30 ] ;
unsigned long V_22 ;
F_86 ( V_152 , L_52 ,
V_2 -> V_8 , V_2 -> V_154 ,
V_2 -> V_155 , V_2 -> V_77 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_87 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
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
F_86 ( V_152 , L_59 ,
V_2 -> V_117 . V_160 , V_2 -> V_117 . V_161 ) ;
if ( V_2 -> V_117 . V_162 )
F_86 ( V_152 , L_60 , V_2 -> V_117 . V_162 ) ;
if ( V_2 -> V_117 . V_163 )
F_86 ( V_152 , L_61 , V_2 -> V_117 . V_163 ) ;
if ( V_2 -> V_117 . V_164 )
F_86 ( V_152 , L_62 , V_2 -> V_117 . V_164 ) ;
if ( V_2 -> V_117 . V_165 )
F_86 ( V_152 , L_63 , V_2 -> V_117 . V_165 ) ;
if ( V_2 -> V_117 . V_166 )
F_86 ( V_152 , L_64 , V_2 -> V_117 . V_166 ) ;
if ( V_2 -> V_117 . V_167 )
F_86 ( V_152 , L_65 , V_2 -> V_117 . V_167 ) ;
} else {
F_86 ( V_152 , L_66 ,
V_2 -> V_117 . V_125 , V_2 -> V_117 . V_124 ) ;
if ( V_2 -> V_117 . V_126 )
F_86 ( V_152 , L_67 , V_2 -> V_117 . V_126 ) ;
if ( V_2 -> V_117 . V_128 )
F_86 ( V_152 , L_68 , V_2 -> V_117 . V_128 ) ;
if ( V_2 -> V_117 . V_129 )
F_86 ( V_152 , L_69 , V_2 -> V_117 . V_129 ) ;
if ( V_2 -> V_117 . V_127 )
F_86 ( V_152 , L_70 , V_2 -> V_117 . V_127 ) ;
}
F_86 ( V_152 , L_71 , V_153 + 1 ) ;
F_86 ( V_152 , L_72 ,
V_2 -> V_86 , V_2 -> V_168 , V_2 -> V_169 ,
V_2 -> V_170 ) ;
}
static int F_88 ( struct V_151 * V_152 , void * V_171 )
{
struct V_1 * V_2 ;
F_89 ( V_152 , L_73 ) ;
V_2 = V_34 ;
while( V_2 ) {
F_85 ( V_152 , V_2 ) ;
V_2 = V_2 -> V_35 ;
}
return 0 ;
}
static int F_90 ( struct V_172 * V_172 , struct V_27 * V_27 )
{
return F_91 ( V_27 , F_88 , NULL ) ;
}
static int F_92 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_4 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_74 ) )
return 0 ;
V_4 = F_37 ( V_2 ) ;
F_13 ( ( L_75 , V_2 -> V_8 , V_4 ) ) ;
return V_4 ;
}
static void F_93 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_76 ) )
return;
F_13 ( ( L_77 , V_2 -> V_8 ) ) ;
if ( F_94 ( V_21 ) )
F_43 ( V_21 , F_95 ( V_21 ) ) ;
if ( V_21 -> V_61 -> V_59 & V_65 ) {
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_62 &= ~ V_63 ;
F_33 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
}
static void F_96 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_78 ) )
return;
F_13 ( ( L_79 , V_2 -> V_8 ) ) ;
if ( F_94 ( V_21 ) ) {
if ( V_2 -> V_81 )
V_2 -> V_81 = 0 ;
else
F_43 ( V_21 , F_97 ( V_21 ) ) ;
}
if ( V_21 -> V_61 -> V_59 & V_65 ) {
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_62 |= V_63 ;
F_33 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
}
static int F_98 ( struct V_20 * V_21 , int V_173 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned short V_174 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_80 ) )
return - V_175 ;
F_13 ( ( L_81 , V_2 -> V_8 , V_173 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_174 = F_99 ( V_2 , V_176 ) ;
if ( V_173 == - 1 )
V_174 |= V_177 ;
else
V_174 &= ~ V_177 ;
F_100 ( V_2 , V_176 , V_174 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_101 ( struct V_178 * V_179 , unsigned short V_136 ,
unsigned short V_128 )
{
struct V_1 * V_2 = F_102 ( V_179 ) ;
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
F_82 ( V_2 ) ;
return 0 ;
}
static T_3 F_103 ( struct V_198 * V_199 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 = F_102 ( V_179 ) ;
unsigned long V_22 ;
F_13 ( ( L_83 , V_179 -> V_17 ) ) ;
if ( ! V_199 -> V_200 )
return V_201 ;
F_104 ( V_179 ) ;
V_179 -> V_202 . V_203 ++ ;
V_179 -> V_202 . V_204 += V_199 -> V_200 ;
V_179 -> V_205 = V_72 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_41 ( V_2 , V_199 -> V_3 , V_199 -> V_200 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
F_105 ( V_199 ) ;
return V_201 ;
}
static int F_106 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = F_102 ( V_179 ) ;
int V_148 ;
unsigned long V_22 ;
if ( ! F_107 ( V_206 ) )
return - V_50 ;
F_13 ( ( L_84 , V_179 -> V_17 ) ) ;
if ( ( V_148 = F_108 ( V_179 ) ) )
return V_148 ;
F_17 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_38 . V_4 != 0 || V_2 -> V_49 != 0 ) {
F_13 ( ( L_85 , V_179 -> V_17 ) ) ;
F_18 ( & V_2 -> V_48 , V_22 ) ;
return - V_50 ;
}
V_2 -> V_49 = 1 ;
F_18 ( & V_2 -> V_48 , V_22 ) ;
if ( ( V_148 = F_20 ( V_2 ) ) != 0 ) {
F_17 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_49 = 0 ;
F_18 ( & V_2 -> V_48 , V_22 ) ;
return V_148 ;
}
V_2 -> V_62 |= V_63 + V_64 ;
F_82 ( V_2 ) ;
V_179 -> V_205 = V_72 ;
F_109 ( V_179 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_87 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_62 & V_158 )
F_110 ( V_179 ) ;
else
F_111 ( V_179 ) ;
return 0 ;
}
static int F_112 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = F_102 ( V_179 ) ;
unsigned long V_22 ;
F_13 ( ( L_86 , V_179 -> V_17 ) ) ;
F_104 ( V_179 ) ;
F_27 ( V_2 ) ;
F_113 ( V_179 ) ;
F_17 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_49 = 0 ;
F_18 ( & V_2 -> V_48 , V_22 ) ;
F_114 ( V_206 ) ;
return 0 ;
}
static int F_115 ( struct V_178 * V_179 , struct V_207 * V_208 , int V_90 )
{
const T_4 V_209 = sizeof( V_210 ) ;
V_210 V_211 ;
V_210 T_2 * line = V_208 -> V_212 . V_213 . V_214 ;
struct V_1 * V_2 = F_102 ( V_179 ) ;
unsigned int V_22 ;
F_13 ( ( L_87 , V_179 -> V_17 ) ) ;
if ( V_2 -> V_38 . V_4 )
return - V_50 ;
if ( V_90 != V_215 )
return F_116 ( V_179 , V_208 , V_90 ) ;
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
if ( F_77 ( line , & V_211 , V_209 ) )
return - V_144 ;
return 0 ;
case V_217 :
if( ! F_117 ( V_234 ) )
return - V_235 ;
if ( F_79 ( & V_211 , line , V_209 ) )
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
F_82 ( V_2 ) ;
return 0 ;
default:
return F_116 ( V_179 , V_208 , V_90 ) ;
}
}
static void F_118 ( struct V_178 * V_179 )
{
struct V_1 * V_2 = F_102 ( V_179 ) ;
unsigned long V_22 ;
F_13 ( ( L_88 , V_179 -> V_17 ) ) ;
V_179 -> V_202 . V_236 ++ ;
V_179 -> V_202 . V_237 ++ ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_54 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
F_119 ( V_179 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
if ( F_121 ( V_2 -> V_238 ) )
F_119 ( V_2 -> V_238 ) ;
}
static void F_122 ( struct V_1 * V_2 , char * V_73 , int V_209 )
{
struct V_198 * V_199 = F_123 ( V_209 ) ;
struct V_178 * V_179 = V_2 -> V_238 ;
F_13 ( ( L_89 , V_179 -> V_17 ) ) ;
if ( V_199 == NULL ) {
F_12 ( ( L_90 , V_179 -> V_17 ) ) ;
V_179 -> V_202 . V_239 ++ ;
return;
}
memcpy ( F_124 ( V_199 , V_209 ) , V_73 , V_209 ) ;
V_199 -> V_240 = F_125 ( V_199 , V_179 ) ;
V_179 -> V_202 . V_241 ++ ;
V_179 -> V_202 . V_242 += V_209 ;
F_126 ( V_199 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_148 ;
struct V_178 * V_179 ;
T_5 * V_243 ;
if ( ! ( V_179 = F_128 ( V_2 ) ) ) {
F_2 ( V_244 L_91 , V_2 -> V_8 ) ;
return - V_245 ;
}
V_179 -> V_246 = V_2 -> V_154 ;
V_179 -> V_247 = V_2 -> V_154 + V_248 - 1 ;
V_179 -> V_249 = V_2 -> V_155 ;
V_179 -> V_250 = & V_251 ;
V_179 -> V_252 = 10 * V_253 ;
V_179 -> V_254 = 50 ;
V_243 = F_129 ( V_179 ) ;
V_243 -> V_255 = F_101 ;
V_243 -> V_256 = F_103 ;
if ( ( V_148 = F_130 ( V_179 ) ) ) {
F_2 ( V_257 L_92 , __FILE__ ) ;
F_131 ( V_179 ) ;
return V_148 ;
}
V_2 -> V_238 = V_179 ;
return 0 ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_133 ( V_2 -> V_238 ) ;
F_131 ( V_2 -> V_238 ) ;
V_2 -> V_238 = NULL ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_38 . V_21 ;
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
while( F_135 ( V_262 [ V_259 ] ) ) {
V_4 = F_136 ( V_262 [ V_259 ] ) - V_2 -> V_265 ;
V_260 = V_262 [ V_259 ] . V_73 + V_2 -> V_265 ;
F_137 ( ( L_93 , V_2 -> V_8 , V_4 ) ) ;
F_138 ( V_2 , V_260 , V_4 , L_94 ) ;
for( V_6 = 0 ; V_6 < V_4 ; V_6 += 2 , V_260 += 2 ) {
V_80 = * V_260 ;
V_117 -> V_124 ++ ;
V_264 = 0 ;
if ( ( V_12 = * ( V_260 + 1 ) & ( V_266 + V_267 ) ) ) {
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
if ( V_21 ) {
F_139 ( V_21 , V_80 , V_264 ) ;
V_263 ++ ;
}
}
if ( V_6 < V_4 ) {
V_2 -> V_265 += V_6 ;
F_38 ( & V_2 -> V_271 , V_72 + 1 ) ;
break;
}
V_2 -> V_265 = 0 ;
F_140 ( V_2 , V_259 , V_259 ) ;
if ( ++ V_259 == V_2 -> V_14 )
V_259 = 0 ;
if ( V_259 == V_258 )
break;
}
if ( V_21 && V_263 )
F_141 ( V_21 ) ;
}
static int F_142 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
int V_148 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
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
F_18 ( & V_2 -> V_54 , V_22 ) ;
return V_148 ;
}
static void F_143 ( struct V_275 * V_276 )
{
struct V_1 * V_2 = F_144 ( V_276 , struct V_1 , V_277 ) ;
int V_278 ;
if ( ! V_2 )
return;
V_2 -> V_169 = true ;
while( ( V_278 = F_142 ( V_2 ) ) ) {
switch ( V_278 ) {
case V_272 :
F_145 ( ( L_95 , V_2 -> V_8 ) ) ;
switch( V_2 -> V_68 . V_69 ) {
case V_89 :
F_134 ( V_2 ) ;
break;
case V_70 :
while( F_146 ( V_2 ) ) ;
break;
case V_279 :
case V_280 :
case V_281 :
case V_282 :
while( F_147 ( V_2 ) ) ;
break;
}
if ( V_2 -> V_283 )
F_148 ( V_2 ) ;
break;
case V_273 :
F_149 ( V_2 ) ;
break;
case V_274 :
F_145 ( ( L_96 , V_2 -> V_8 ) ) ;
V_2 -> V_284 = 0 ;
V_2 -> V_285 = 0 ;
V_2 -> V_286 = 0 ;
V_2 -> V_287 = 0 ;
break;
default:
F_145 ( ( L_97 , V_2 -> V_8 ) ) ;
break;
}
}
F_145 ( ( L_98 , V_2 -> V_8 ) ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_38 . V_21 ;
F_145 ( ( L_99 , V_2 -> V_8 ) ) ;
if ( V_21 )
F_52 ( V_21 ) ;
}
static void F_150 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_288 ) {
V_2 -> V_62 |= V_157 ;
V_2 -> V_289 . V_290 ++ ;
} else {
V_2 -> V_62 &= ~ V_157 ;
V_2 -> V_289 . V_291 ++ ;
}
F_137 ( ( L_100 , V_2 -> V_8 , V_2 -> V_62 ) ) ;
if ( ( V_2 -> V_285 ) ++ == V_292 ) {
F_151 ( V_2 , V_293 ) ;
return;
}
V_2 -> V_117 . V_121 ++ ;
F_30 ( & V_2 -> V_294 ) ;
F_30 ( & V_2 -> V_295 ) ;
V_2 -> V_170 |= V_274 ;
}
static void F_152 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_296 ) {
V_2 -> V_62 |= V_156 ;
V_2 -> V_289 . V_297 ++ ;
} else {
V_2 -> V_62 &= ~ V_156 ;
V_2 -> V_289 . V_298 ++ ;
}
F_137 ( ( L_101 , V_2 -> V_8 , V_2 -> V_62 ) ) ;
if ( ( V_2 -> V_287 ) ++ == V_292 ) {
F_151 ( V_2 , V_299 ) ;
return;
}
V_2 -> V_117 . V_120 ++ ;
F_30 ( & V_2 -> V_294 ) ;
F_30 ( & V_2 -> V_295 ) ;
V_2 -> V_170 |= V_274 ;
if ( V_2 -> V_38 . V_22 & V_300 ) {
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
V_2 -> V_289 . V_301 ++ ;
} else {
V_2 -> V_62 &= ~ V_158 ;
V_2 -> V_289 . V_302 ++ ;
}
F_137 ( ( L_102 , V_2 -> V_8 , V_2 -> V_62 ) ) ;
if ( ( V_2 -> V_286 ) ++ == V_292 ) {
F_151 ( V_2 , V_303 ) ;
return;
}
V_2 -> V_117 . V_123 ++ ;
#if V_304
if ( V_2 -> V_49 ) {
if ( V_2 -> V_62 & V_158 )
F_110 ( V_2 -> V_238 ) ;
else
F_111 ( V_2 -> V_238 ) ;
}
#endif
F_30 ( & V_2 -> V_294 ) ;
F_30 ( & V_2 -> V_295 ) ;
V_2 -> V_170 |= V_274 ;
if ( V_2 -> V_38 . V_22 & V_305 ) {
if ( V_2 -> V_62 & V_158 )
F_30 ( & V_2 -> V_38 . V_56 ) ;
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
V_2 -> V_289 . V_306 ++ ;
} else {
V_2 -> V_62 &= ~ V_159 ;
V_2 -> V_289 . V_307 ++ ;
}
F_137 ( ( L_103 , V_2 -> V_8 , V_2 -> V_62 ) ) ;
if ( ( V_2 -> V_284 ) ++ == V_292 ) {
F_151 ( V_2 , V_308 ) ;
return;
}
V_2 -> V_117 . V_122 ++ ;
F_30 ( & V_2 -> V_294 ) ;
F_30 ( & V_2 -> V_295 ) ;
V_2 -> V_170 |= V_274 ;
}
static void F_156 ( struct V_1 * V_2 )
{
unsigned int V_4 = V_2 -> V_309 ;
unsigned int V_6 = V_2 -> V_310 ;
unsigned short V_311 ;
while ( F_99 ( V_2 , V_312 ) & V_313 ) {
V_311 = F_99 ( V_2 , V_314 ) ;
F_137 ( ( L_104 , V_2 -> V_8 , V_311 ) ) ;
if ( F_135 ( V_2 -> V_15 [ V_6 ] ) ) {
F_157 ( V_2 ) ;
V_2 -> V_283 = 1 ;
continue;
}
V_2 -> V_15 [ V_6 ] . V_73 [ V_4 ++ ] = ( unsigned char ) V_311 ;
if ( V_2 -> V_68 . V_69 == V_89 )
V_2 -> V_15 [ V_6 ] . V_73 [ V_4 ++ ] = ( unsigned char ) ( V_311 >> 8 ) ;
if ( V_4 == V_2 -> V_315 || ( V_311 & V_316 ) ) {
F_158 ( V_2 -> V_15 [ V_6 ] , V_4 ) ;
F_159 ( V_2 -> V_15 [ V_6 ] , V_317 | ( V_311 >> 8 ) ) ;
V_2 -> V_309 = V_4 = 0 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
V_2 -> V_170 |= V_272 ;
}
}
V_2 -> V_310 = V_6 ;
V_2 -> V_309 = V_4 ;
}
static void F_160 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_99 ( V_2 , V_312 ) ;
F_137 ( ( L_105 , V_2 -> V_8 , V_12 ) ) ;
F_100 ( V_2 , V_312 , V_12 ) ;
V_2 -> V_318 = true ;
if ( V_2 -> V_68 . V_69 == V_89 ) {
if ( V_12 & V_319 ) {
if ( V_2 -> V_86 )
F_161 ( V_2 , V_12 ) ;
}
if ( V_2 -> V_320 && ( V_12 & V_313 ) )
F_156 ( V_2 ) ;
if ( ( V_12 & V_321 ) && ( V_12 & V_322 ) ) {
V_2 -> V_117 . V_129 ++ ;
if ( V_2 -> V_38 . V_21 ) {
if ( ! ( V_12 & V_2 -> V_268 ) ) {
if ( V_2 -> V_323 & V_324 ) {
F_139 ( V_2 -> V_38 . V_21 , 0 , V_325 ) ;
if ( V_2 -> V_38 . V_22 & V_326 )
F_162 ( V_2 -> V_38 . V_21 ) ;
}
}
}
}
} else {
if ( V_12 & ( V_319 + V_327 ) )
F_161 ( V_2 , V_12 ) ;
if ( V_2 -> V_320 && ( V_12 & V_313 ) )
F_156 ( V_2 ) ;
if ( V_12 & V_328 ) {
if ( V_12 & V_329 )
V_2 -> V_117 . V_330 ++ ;
else
V_2 -> V_117 . V_331 ++ ;
F_30 ( & V_2 -> V_295 ) ;
}
if ( V_12 & V_332 )
F_148 ( V_2 ) ;
}
if ( V_12 & V_293 )
F_150 ( V_2 , V_12 ) ;
if ( V_12 & V_299 )
F_152 ( V_2 , V_12 ) ;
if ( V_12 & V_303 )
F_153 ( V_2 , V_12 ) ;
if ( V_12 & V_308 )
F_155 ( V_2 , V_12 ) ;
}
static void F_163 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_164 ( V_2 , V_333 ) ;
F_137 ( ( L_106 , V_2 -> V_8 , V_12 ) ) ;
F_165 ( V_2 , V_333 , V_12 ) ;
if ( V_12 & ( V_334 + V_335 ) ) {
F_137 ( ( L_107 , V_2 -> V_8 ) ) ;
V_2 -> V_283 = true ;
}
V_2 -> V_170 |= V_272 ;
}
static void F_166 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_164 ( V_2 , V_336 ) ;
F_137 ( ( L_108 , V_2 -> V_8 , V_12 ) ) ;
F_165 ( V_2 , V_336 , V_12 ) ;
if ( V_12 & ( V_334 + V_335 + V_288 ) ) {
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
if ( ! F_136 ( V_2 -> V_11 [ V_6 ] ) )
break;
V_2 -> V_337 = V_6 ;
V_148 = true ;
} while ( V_6 != V_2 -> V_9 );
return V_148 ;
}
static void F_161 ( struct V_1 * V_2 , unsigned short V_12 )
{
F_137 ( ( L_109 , V_2 -> V_8 , V_12 ) ) ;
F_151 ( V_2 , V_338 + V_319 + V_327 ) ;
F_168 ( V_2 ) ;
if ( V_12 & V_327 ) {
unsigned short V_339 = F_99 ( V_2 , V_176 ) ;
F_100 ( V_2 , V_176 , ( unsigned short ) ( V_339 | V_296 ) ) ;
F_100 ( V_2 , V_176 , V_339 ) ;
}
if ( V_2 -> V_86 ) {
if ( V_2 -> V_68 . V_69 != V_89 ) {
if ( V_12 & V_327 )
V_2 -> V_117 . V_162 ++ ;
else if ( V_12 & V_319 )
V_2 -> V_117 . V_160 ++ ;
}
if ( F_167 ( V_2 ) ) {
F_44 ( V_2 ) ;
F_36 ( V_2 ) ;
return;
}
V_2 -> V_86 = false ;
F_169 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_68 . V_69 != V_89 && V_2 -> V_340 ) {
V_2 -> V_62 &= ~ V_63 ;
V_2 -> V_340 = false ;
F_33 ( V_2 ) ;
}
#if V_304
if ( V_2 -> V_49 )
F_120 ( V_2 ) ;
else
#endif
{
if ( V_2 -> V_38 . V_21 && ( V_2 -> V_38 . V_21 -> V_78 || V_2 -> V_38 . V_21 -> V_67 ) ) {
F_54 ( V_2 ) ;
return;
}
V_2 -> V_170 |= V_273 ;
}
}
}
static void F_170 ( struct V_1 * V_2 , unsigned int V_341 , unsigned int V_342 )
{
struct V_343 * V_344 , * V_345 ;
for ( V_344 = V_2 -> V_346 , V_345 = NULL ; V_344 != NULL ; V_344 = V_344 -> V_347 ) {
if ( V_344 -> V_3 & V_341 ) {
V_344 -> V_3 = V_342 ;
F_30 ( & V_344 -> V_348 ) ;
if ( V_345 != NULL )
V_345 -> V_347 = V_344 -> V_347 ;
else
V_2 -> V_346 = V_344 -> V_347 ;
} else
V_345 = V_344 ;
}
}
static T_6 F_171 ( int V_349 , void * V_350 )
{
struct V_1 * V_2 = V_350 ;
unsigned int V_351 ;
unsigned int V_6 ;
F_137 ( ( L_110 , V_2 -> V_155 ) ) ;
while( ( V_351 = F_164 ( V_2 , V_352 ) & 0xffffff00 ) ) {
F_137 ( ( L_111 , V_2 -> V_8 , V_351 ) ) ;
V_2 -> V_318 = true ;
for( V_6 = 0 ; V_6 < V_2 -> V_353 ; V_6 ++ ) {
if ( V_2 -> V_354 [ V_6 ] == NULL )
continue;
F_80 ( & V_2 -> V_354 [ V_6 ] -> V_54 ) ;
if ( V_351 & ( V_355 << V_6 ) )
F_160 ( V_2 -> V_354 [ V_6 ] ) ;
if ( V_351 & ( V_356 << ( V_6 * 2 ) ) )
F_163 ( V_2 -> V_354 [ V_6 ] ) ;
if ( V_351 & ( V_357 << ( V_6 * 2 ) ) )
F_166 ( V_2 -> V_354 [ V_6 ] ) ;
F_81 ( & V_2 -> V_354 [ V_6 ] -> V_54 ) ;
}
}
if ( V_2 -> V_358 ) {
unsigned int V_342 ;
unsigned int V_341 ;
F_80 ( & V_2 -> V_54 ) ;
while ( ( V_341 = F_164 ( V_2 , V_359 ) ) != 0 ) {
F_137 ( ( L_112 , V_2 -> V_8 , V_341 ) ) ;
V_342 = F_164 ( V_2 , V_360 ) ;
F_165 ( V_2 , V_359 , V_341 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_353 ; V_6 ++ ) {
if ( V_2 -> V_354 [ V_6 ] != NULL )
F_170 ( V_2 -> V_354 [ V_6 ] , V_341 , V_342 ) ;
}
}
F_81 ( & V_2 -> V_54 ) ;
}
for( V_6 = 0 ; V_6 < V_2 -> V_353 ; V_6 ++ ) {
struct V_1 * V_38 = V_2 -> V_354 [ V_6 ] ;
if ( V_38 == NULL )
continue;
F_80 ( & V_38 -> V_54 ) ;
if ( ( V_38 -> V_38 . V_4 || V_38 -> V_49 ) &&
V_38 -> V_170 && ! V_38 -> V_169 &&
! V_38 -> V_168 ) {
F_137 ( ( L_113 , V_38 -> V_8 ) ) ;
F_172 ( & V_38 -> V_277 ) ;
V_38 -> V_168 = true ;
}
F_81 ( & V_38 -> V_54 ) ;
}
F_137 ( ( L_114 , V_2 -> V_155 ) ) ;
return V_361 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_13 ( ( L_115 , V_2 -> V_8 ) ) ;
if ( V_2 -> V_38 . V_22 & V_51 )
return 0 ;
if ( ! V_2 -> V_76 ) {
V_2 -> V_76 = F_173 ( V_2 -> V_77 , V_362 ) ;
if ( ! V_2 -> V_76 ) {
F_12 ( ( L_116 , V_2 -> V_8 ) ) ;
return - V_245 ;
}
}
V_2 -> V_170 = 0 ;
memset ( & V_2 -> V_117 , 0 , sizeof( V_2 -> V_117 ) ) ;
F_32 ( V_2 ) ;
if ( V_2 -> V_38 . V_21 )
F_174 ( V_96 , & V_2 -> V_38 . V_21 -> V_22 ) ;
V_2 -> V_38 . V_22 |= V_51 ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
if ( ! ( V_2 -> V_38 . V_22 & V_51 ) )
return;
F_13 ( ( L_117 , V_2 -> V_8 ) ) ;
F_30 ( & V_2 -> V_294 ) ;
F_30 ( & V_2 -> V_295 ) ;
F_175 ( & V_2 -> V_71 ) ;
F_175 ( & V_2 -> V_271 ) ;
F_176 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_54 ( V_2 ) ;
F_157 ( V_2 ) ;
F_151 ( V_2 , V_363 | V_364 ) ;
if ( ! V_2 -> V_38 . V_21 || V_2 -> V_38 . V_21 -> V_61 -> V_59 & V_365 ) {
V_2 -> V_62 &= ~ ( V_64 + V_63 ) ;
F_33 ( V_2 ) ;
}
F_177 ( & V_2 -> V_346 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
if ( V_2 -> V_38 . V_21 )
F_178 ( V_96 , & V_2 -> V_38 . V_21 -> V_22 ) ;
V_2 -> V_38 . V_22 &= ~ V_51 ;
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_157 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_68 . V_69 != V_89 ||
V_2 -> V_49 )
F_179 ( V_2 ) ;
else
F_180 ( V_2 ) ;
F_33 ( V_2 ) ;
V_2 -> V_286 = 0 ;
V_2 -> V_287 = 0 ;
V_2 -> V_284 = 0 ;
V_2 -> V_285 = 0 ;
F_181 ( V_2 , V_303 | V_299 | V_293 | V_308 ) ;
F_87 ( V_2 ) ;
if ( V_2 -> V_49 ||
( V_2 -> V_38 . V_21 && V_2 -> V_38 . V_21 -> V_61 -> V_59 & V_366 ) )
F_148 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned V_367 ;
int V_368 ;
if ( ! V_2 -> V_38 . V_21 || ! V_2 -> V_38 . V_21 -> V_61 )
return;
F_13 ( ( L_118 , V_2 -> V_8 ) ) ;
V_367 = V_2 -> V_38 . V_21 -> V_61 -> V_59 ;
if ( V_367 & V_60 )
V_2 -> V_62 |= V_63 + V_64 ;
else
V_2 -> V_62 &= ~ ( V_63 + V_64 ) ;
switch ( V_367 & V_369 ) {
case V_370 : V_2 -> V_68 . V_142 = 5 ; break;
case V_371 : V_2 -> V_68 . V_142 = 6 ; break;
case V_372 : V_2 -> V_68 . V_142 = 7 ; break;
case V_373 : V_2 -> V_68 . V_142 = 8 ; break;
default: V_2 -> V_68 . V_142 = 7 ; break;
}
V_2 -> V_68 . V_143 = ( V_367 & V_374 ) ? 2 : 1 ;
if ( V_367 & V_375 )
V_2 -> V_68 . V_128 = ( V_367 & V_376 ) ? V_377 : V_378 ;
else
V_2 -> V_68 . V_128 = V_379 ;
V_368 = V_2 -> V_68 . V_142 +
V_2 -> V_68 . V_143 + 1 ;
V_2 -> V_68 . V_85 = F_182 ( V_2 -> V_38 . V_21 ) ;
if ( V_2 -> V_68 . V_85 ) {
V_2 -> V_52 = ( 32 * V_253 * V_368 ) /
V_2 -> V_68 . V_85 ;
}
V_2 -> V_52 += V_253 / 50 ;
if ( V_367 & V_65 )
V_2 -> V_38 . V_22 |= V_300 ;
else
V_2 -> V_38 . V_22 &= ~ V_300 ;
if ( V_367 & V_380 )
V_2 -> V_38 . V_22 &= ~ V_305 ;
else
V_2 -> V_38 . V_22 |= V_305 ;
V_2 -> V_323 = V_332 ;
if ( F_183 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_323 |= V_381 | V_382 ;
if ( F_184 ( V_2 -> V_38 . V_21 ) || F_185 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_323 |= V_324 ;
if ( F_186 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_268 |= V_381 | V_382 ;
if ( F_187 ( V_2 -> V_38 . V_21 ) ) {
V_2 -> V_268 |= V_324 ;
if ( F_186 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_268 |= V_383 ;
}
F_82 ( V_2 ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_118 T_2 * V_384 )
{
F_13 ( ( L_119 , V_2 -> V_8 ) ) ;
if ( ! V_384 ) {
memset ( & V_2 -> V_117 , 0 , sizeof( V_2 -> V_117 ) ) ;
} else {
if ( F_77 ( V_384 , & V_2 -> V_117 , sizeof( struct V_118 ) ) )
return - V_144 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , T_7 T_2 * V_132 )
{
F_13 ( ( L_120 , V_2 -> V_8 ) ) ;
if ( F_77 ( V_132 , & V_2 -> V_68 , sizeof( T_7 ) ) )
return - V_144 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , T_7 T_2 * V_145 )
{
unsigned long V_22 ;
T_7 V_133 ;
F_13 ( ( L_121 , V_2 -> V_8 ) ) ;
if ( F_79 ( & V_133 , V_145 , sizeof( T_7 ) ) )
return - V_144 ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_133 . V_69 == V_146 )
V_2 -> V_147 = V_133 . V_137 ;
else
memcpy ( & V_2 -> V_68 , & V_133 , sizeof( T_7 ) ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , int T_2 * V_385 )
{
F_13 ( ( L_122 , V_2 -> V_8 , V_2 -> V_385 ) ) ;
if ( F_188 ( V_2 -> V_385 , V_385 ) )
return - V_144 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_385 )
{
unsigned long V_22 ;
F_13 ( ( L_123 , V_2 -> V_8 , V_385 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_385 = V_385 ;
if ( V_2 -> V_68 . V_69 != V_89 )
F_189 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , int V_386 )
{
unsigned long V_22 ;
F_13 ( ( L_124 , V_2 -> V_8 , V_386 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_386 ) {
if ( ! V_2 -> V_82 )
F_44 ( V_2 ) ;
} else {
if ( V_2 -> V_82 )
F_54 ( V_2 ) ;
}
F_18 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_13 ( ( L_125 , V_2 -> V_8 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_168 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , int V_386 )
{
unsigned long V_22 ;
unsigned int V_315 ;
F_13 ( ( L_126 , V_2 -> V_8 , V_386 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_315 = ( ( unsigned int ) V_386 ) >> 16 ;
if ( V_315 ) {
if ( ( V_315 > V_387 ) || ( V_315 % 4 ) ) {
F_18 ( & V_2 -> V_54 , V_22 ) ;
return - V_175 ;
}
V_2 -> V_315 = V_315 ;
if ( V_315 < 128 )
V_2 -> V_320 = 1 ;
else
V_2 -> V_320 = 0 ;
F_157 ( V_2 ) ;
}
V_386 &= 3 ;
if ( V_386 ) {
if ( ! V_2 -> V_388 )
F_148 ( V_2 ) ;
else if ( V_386 == 2 ) {
F_100 ( V_2 , V_389 , F_99 ( V_2 , V_389 ) | V_288 ) ;
}
} else {
if ( V_2 -> V_388 )
F_157 ( V_2 ) ;
}
F_18 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , int T_2 * V_390 )
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
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_87 ( V_2 ) ;
V_391 = V_2 -> V_62 ;
V_393 = V_394 &
( ( ( V_391 & V_157 ) ? V_399 : V_400 ) +
( ( V_391 & V_158 ) ? V_401 : V_402 ) +
( ( V_391 & V_156 ) ? V_403 : V_404 ) +
( ( V_391 & V_159 ) ? V_405 : V_406 ) ) ;
if ( V_393 ) {
F_18 ( & V_2 -> V_54 , V_22 ) ;
goto exit;
}
V_392 = V_2 -> V_117 ;
V_396 = V_2 -> V_289 ;
if ( V_394 & ( V_407 + V_408 ) ) {
unsigned short V_339 = F_99 ( V_2 , V_409 ) ;
if ( ! ( V_339 & V_328 ) )
F_100 ( V_2 , V_409 , ( unsigned short ) ( V_339 | V_328 ) ) ;
}
F_192 ( V_410 ) ;
F_193 ( & V_2 -> V_295 , & V_398 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
for(; ; ) {
F_194 () ;
if ( F_48 ( V_87 ) ) {
V_148 = - V_43 ;
break;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_119 = V_2 -> V_117 ;
V_397 = V_2 -> V_289 ;
F_192 ( V_410 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
if ( V_397 . V_290 == V_396 . V_290 &&
V_397 . V_291 == V_396 . V_291 &&
V_397 . V_301 == V_396 . V_301 &&
V_397 . V_302 == V_396 . V_302 &&
V_397 . V_297 == V_396 . V_297 &&
V_397 . V_298 == V_396 . V_298 &&
V_397 . V_306 == V_396 . V_306 &&
V_397 . V_307 == V_396 . V_307 &&
V_119 . V_331 == V_392 . V_331 &&
V_119 . V_330 == V_392 . V_330 ) {
V_148 = - V_75 ;
break;
}
V_393 = V_394 &
( ( V_397 . V_290 != V_396 . V_290 ? V_399 : 0 ) +
( V_397 . V_291 != V_396 . V_291 ? V_400 : 0 ) +
( V_397 . V_301 != V_396 . V_301 ? V_401 : 0 ) +
( V_397 . V_302 != V_396 . V_302 ? V_402 : 0 ) +
( V_397 . V_297 != V_396 . V_297 ? V_403 : 0 ) +
( V_397 . V_298 != V_396 . V_298 ? V_404 : 0 ) +
( V_397 . V_306 != V_396 . V_306 ? V_405 : 0 ) +
( V_397 . V_307 != V_396 . V_307 ? V_406 : 0 ) +
( V_119 . V_331 != V_392 . V_331 ? V_407 : 0 ) +
( V_119 . V_330 != V_392 . V_330 ? V_408 : 0 ) ) ;
if ( V_393 )
break;
V_392 = V_119 ;
V_396 = V_397 ;
}
F_195 ( & V_2 -> V_295 , & V_398 ) ;
F_192 ( V_411 ) ;
if ( V_394 & ( V_407 + V_408 ) ) {
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( ! F_196 ( & V_2 -> V_295 ) ) {
F_100 ( V_2 , V_409 ,
( unsigned short ) ( F_99 ( V_2 , V_409 ) & ~ V_328 ) ) ;
}
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
exit:
if ( V_148 == 0 )
V_148 = F_188 ( V_393 , V_390 ) ;
return V_148 ;
}
static int F_73 ( struct V_1 * V_2 , int T_2 * V_412 )
{
F_13 ( ( L_128 , V_2 -> V_8 , V_2 -> V_412 ) ) ;
if ( F_188 ( V_2 -> V_412 , V_412 ) )
return - V_144 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , int V_412 )
{
unsigned long V_22 ;
unsigned short V_339 ;
F_13 ( ( L_129 , V_2 -> V_8 , V_412 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_412 = V_412 ;
F_197 ( V_2 ) ;
V_339 = F_99 ( V_2 , V_176 ) ;
if ( V_2 -> V_412 & V_413 )
V_339 |= V_414 ;
else
V_339 &= ~ V_414 ;
F_100 ( V_2 , V_176 , V_339 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , int T_2 * V_415 )
{
F_13 ( ( L_130 , V_2 -> V_8 , V_2 -> V_415 ) ) ;
if ( F_188 ( V_2 -> V_415 , V_415 ) )
return - V_144 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_415 )
{
unsigned long V_22 ;
F_13 ( ( L_131 , V_2 -> V_8 , V_415 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_415 = V_415 ;
F_165 ( V_2 , V_416 , V_415 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , int T_2 * V_417 )
{
F_13 ( ( L_132 , V_2 -> V_8 , V_2 -> V_417 ) ) ;
if ( F_188 ( V_2 -> V_417 , V_417 ) )
return - V_144 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , int V_417 )
{
unsigned long V_22 ;
F_13 ( ( L_133 , V_2 -> V_8 , V_417 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_417 = V_417 ;
F_165 ( V_2 , V_418 , V_417 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_419 T_2 * V_420 )
{
unsigned long V_22 ;
struct V_419 V_421 ;
T_8 V_3 ;
if ( ! V_2 -> V_358 )
return - V_175 ;
if ( F_79 ( & V_421 , V_420 , sizeof( V_421 ) ) )
return - V_144 ;
F_13 ( ( L_134 ,
V_2 -> V_8 , V_421 . V_342 , V_421 . V_422 ,
V_421 . V_423 , V_421 . V_424 ) ) ;
F_17 ( & V_2 -> V_354 [ 0 ] -> V_54 , V_22 ) ;
if ( V_421 . V_424 ) {
V_3 = F_164 ( V_2 , V_425 ) ;
V_3 |= V_421 . V_424 & V_421 . V_423 ;
V_3 &= ~ ( V_421 . V_424 & ~ V_421 . V_423 ) ;
F_165 ( V_2 , V_425 , V_3 ) ;
}
if ( V_421 . V_422 ) {
V_3 = F_164 ( V_2 , V_360 ) ;
V_3 |= V_421 . V_422 & V_421 . V_342 ;
V_3 &= ~ ( V_421 . V_422 & ~ V_421 . V_342 ) ;
F_165 ( V_2 , V_360 , V_3 ) ;
}
F_18 ( & V_2 -> V_354 [ 0 ] -> V_54 , V_22 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_419 T_2 * V_420 )
{
struct V_419 V_421 ;
if ( ! V_2 -> V_358 )
return - V_175 ;
V_421 . V_342 = F_164 ( V_2 , V_360 ) ;
V_421 . V_422 = 0xffffffff ;
V_421 . V_423 = F_164 ( V_2 , V_425 ) ;
V_421 . V_424 = 0xffffffff ;
if ( F_77 ( V_420 , & V_421 , sizeof( V_421 ) ) )
return - V_144 ;
F_13 ( ( L_135 ,
V_2 -> V_8 , V_421 . V_342 , V_421 . V_423 ) ) ;
return 0 ;
}
static void F_198 ( struct V_343 * V_344 , unsigned int V_3 )
{
F_199 ( & V_344 -> V_348 ) ;
F_200 ( & V_344 -> V_398 , V_87 ) ;
V_344 -> V_3 = V_3 ;
}
static void F_201 ( struct V_343 * * V_426 , struct V_343 * V_344 )
{
F_192 ( V_410 ) ;
F_193 ( & V_344 -> V_348 , & V_344 -> V_398 ) ;
V_344 -> V_347 = * V_426 ;
* V_426 = V_344 ;
}
static void F_202 ( struct V_343 * * V_426 , struct V_343 * V_427 )
{
struct V_343 * V_344 , * V_345 ;
F_195 ( & V_427 -> V_348 , & V_427 -> V_398 ) ;
F_192 ( V_411 ) ;
for ( V_344 = * V_426 , V_345 = NULL ; V_344 != NULL ; V_345 = V_344 , V_344 = V_344 -> V_347 ) {
if ( V_344 == V_427 ) {
if ( V_345 != NULL )
V_345 -> V_347 = V_344 -> V_347 ;
else
* V_426 = V_344 -> V_347 ;
break;
}
}
}
static void F_177 ( struct V_343 * * V_426 )
{
while ( * V_426 != NULL ) {
F_30 ( & ( * V_426 ) -> V_348 ) ;
* V_426 = ( * V_426 ) -> V_347 ;
}
}
static int F_60 ( struct V_1 * V_2 , struct V_419 T_2 * V_420 )
{
unsigned long V_22 ;
int V_148 = 0 ;
struct V_419 V_421 ;
struct V_343 V_398 ;
T_9 V_342 ;
if ( ! V_2 -> V_358 )
return - V_175 ;
if ( F_79 ( & V_421 , V_420 , sizeof( V_421 ) ) )
return - V_144 ;
F_13 ( ( L_136 ,
V_2 -> V_8 , V_421 . V_342 , V_421 . V_422 ) ) ;
if ( ( V_421 . V_422 &= ~ F_164 ( V_2 , V_425 ) ) == 0 )
return - V_175 ;
F_198 ( & V_398 , V_421 . V_422 ) ;
F_17 ( & V_2 -> V_354 [ 0 ] -> V_54 , V_22 ) ;
F_165 ( V_2 , V_428 , F_164 ( V_2 , V_428 ) | V_421 . V_422 ) ;
V_342 = F_164 ( V_2 , V_360 ) ;
if ( V_421 . V_422 & ~ ( V_342 ^ V_421 . V_342 ) ) {
V_421 . V_342 = V_342 ;
} else {
F_201 ( & V_2 -> V_346 , & V_398 ) ;
F_18 ( & V_2 -> V_354 [ 0 ] -> V_54 , V_22 ) ;
F_194 () ;
if ( F_48 ( V_87 ) )
V_148 = - V_43 ;
else
V_421 . V_342 = V_398 . V_3 ;
F_17 ( & V_2 -> V_354 [ 0 ] -> V_54 , V_22 ) ;
F_202 ( & V_2 -> V_346 , & V_398 ) ;
}
if ( V_2 -> V_346 == NULL )
F_165 ( V_2 , V_428 , 0 ) ;
F_18 ( & V_2 -> V_354 [ 0 ] -> V_54 , V_22 ) ;
if ( ( V_148 == 0 ) && F_77 ( V_420 , & V_421 , sizeof( V_421 ) ) )
V_148 = - V_144 ;
return V_148 ;
}
static int F_57 ( struct V_1 * V_2 , int V_91 )
{
unsigned long V_22 ;
int V_148 ;
struct V_118 V_392 , V_119 ;
F_190 ( V_398 , V_87 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_392 = V_2 -> V_117 ;
F_193 ( & V_2 -> V_294 , & V_398 ) ;
F_192 ( V_410 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
for(; ; ) {
F_194 () ;
if ( F_48 ( V_87 ) ) {
V_148 = - V_43 ;
break;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_119 = V_2 -> V_117 ;
F_192 ( V_410 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
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
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_87 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
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
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_33 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
return 0 ;
}
static int F_205 ( struct V_439 * V_38 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_144 ( V_38 , struct V_1 , V_38 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_87 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
return ( V_2 -> V_62 & V_158 ) ? 1 : 0 ;
}
static void F_206 ( struct V_439 * V_38 , int V_440 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_144 ( V_38 , struct V_1 , V_38 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( V_440 )
V_2 -> V_62 |= V_63 + V_64 ;
else
V_2 -> V_62 &= ~ ( V_63 + V_64 ) ;
F_33 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
static int F_21 ( struct V_20 * V_21 , struct V_27 * V_28 ,
struct V_1 * V_2 )
{
F_190 ( V_398 , V_87 ) ;
int V_29 ;
bool V_441 = false ;
bool V_442 = false ;
unsigned long V_22 ;
int V_443 ;
struct V_439 * V_38 = & V_2 -> V_38 ;
F_13 ( ( L_139 , V_21 -> V_53 -> V_17 ) ) ;
if ( V_28 -> V_444 & V_445 || V_21 -> V_22 & ( 1 << V_96 ) ) {
V_38 -> V_22 |= V_55 ;
return 0 ;
}
if ( V_21 -> V_61 -> V_59 & V_380 )
V_441 = true ;
V_29 = 0 ;
F_193 ( & V_38 -> V_56 , & V_398 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
if ( ! F_14 ( V_28 ) ) {
V_442 = true ;
V_38 -> V_4 -- ;
}
F_18 ( & V_2 -> V_54 , V_22 ) ;
V_38 -> V_446 ++ ;
while ( 1 ) {
if ( ( V_21 -> V_61 -> V_59 & V_60 ) )
F_207 ( V_38 ) ;
F_192 ( V_410 ) ;
if ( F_14 ( V_28 ) || ! ( V_38 -> V_22 & V_51 ) ) {
V_29 = ( V_38 -> V_22 & V_41 ) ?
- V_42 : - V_43 ;
break;
}
V_443 = F_208 ( V_38 ) ;
if ( ! ( V_38 -> V_22 & V_39 ) && ( V_441 || V_443 ) )
break;
if ( F_48 ( V_87 ) ) {
V_29 = - V_43 ;
break;
}
F_13 ( ( L_140 , V_21 -> V_53 -> V_17 ) ) ;
F_209 () ;
F_194 () ;
F_210 () ;
}
F_192 ( V_411 ) ;
F_195 ( & V_38 -> V_56 , & V_398 ) ;
if ( V_442 )
V_38 -> V_4 ++ ;
V_38 -> V_446 -- ;
if ( ! V_29 )
V_38 -> V_22 |= V_55 ;
F_13 ( ( L_141 , V_21 -> V_53 -> V_17 , V_29 ) ) ;
return V_29 ;
}
static int F_211 ( struct V_1 * V_2 )
{
V_2 -> V_447 = F_173 ( V_2 -> V_77 + 5 , V_362 ) ;
if ( V_2 -> V_447 == NULL )
return - V_245 ;
return 0 ;
}
static void F_212 ( struct V_1 * V_2 )
{
F_176 ( V_2 -> V_447 ) ;
V_2 -> V_447 = NULL ;
}
static int F_213 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
unsigned int V_448 ;
V_2 -> V_262 = F_214 ( V_2 -> V_449 , V_450 , & V_2 -> V_451 ) ;
if ( V_2 -> V_262 == NULL )
return - V_245 ;
memset ( V_2 -> V_262 , 0 , V_450 ) ;
V_2 -> V_15 = (struct V_261 * ) V_2 -> V_262 ;
V_2 -> V_11 = ( (struct V_261 * ) V_2 -> V_262 ) + V_2 -> V_14 ;
V_448 = ( unsigned int ) V_2 -> V_451 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_14 ; V_6 ++ ) {
V_2 -> V_15 [ V_6 ] . V_452 = V_448 + ( V_6 * sizeof( struct V_261 ) ) ;
if ( V_6 == V_2 -> V_14 - 1 )
V_2 -> V_15 [ V_6 ] . V_347 = F_215 ( V_448 ) ;
else
V_2 -> V_15 [ V_6 ] . V_347 = F_215 ( V_448 + ( ( V_6 + 1 ) * sizeof( struct V_261 ) ) ) ;
F_158 ( V_2 -> V_15 [ V_6 ] , V_387 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_452 = V_448 + ( ( V_2 -> V_14 + V_6 ) * sizeof( struct V_261 ) ) ;
if ( V_6 == V_2 -> V_10 - 1 )
V_2 -> V_11 [ V_6 ] . V_347 = F_215 ( V_448 + V_2 -> V_14 * sizeof( struct V_261 ) ) ;
else
V_2 -> V_11 [ V_6 ] . V_347 = F_215 ( V_448 + ( ( V_2 -> V_14 + V_6 + 1 ) * sizeof( struct V_261 ) ) ) ;
}
return 0 ;
}
static void F_216 ( struct V_1 * V_2 )
{
if ( V_2 -> V_262 != NULL ) {
F_217 ( V_2 -> V_449 , V_450 , V_2 -> V_262 , V_2 -> V_451 ) ;
V_2 -> V_262 = NULL ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
}
}
static int F_218 ( struct V_1 * V_2 , struct V_261 * V_262 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( ( V_262 [ V_6 ] . V_73 = F_214 ( V_2 -> V_449 , V_387 , & V_262 [ V_6 ] . V_453 ) ) == NULL )
return - V_245 ;
V_262 [ V_6 ] . V_454 = F_215 ( ( unsigned int ) V_262 [ V_6 ] . V_453 ) ;
}
return 0 ;
}
static void F_219 ( struct V_1 * V_2 , struct V_261 * V_262 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( V_262 [ V_6 ] . V_73 == NULL )
continue;
F_217 ( V_2 -> V_449 , V_387 , V_262 [ V_6 ] . V_73 , V_262 [ V_6 ] . V_453 ) ;
V_262 [ V_6 ] . V_73 = NULL ;
}
}
static int F_220 ( struct V_1 * V_2 )
{
V_2 -> V_14 = 32 ;
V_2 -> V_10 = 32 ;
if ( F_213 ( V_2 ) < 0 ||
F_218 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) < 0 ||
F_218 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) < 0 ||
F_211 ( V_2 ) < 0 ) {
F_12 ( ( L_142 , V_2 -> V_8 ) ) ;
return - V_245 ;
}
F_221 ( V_2 ) ;
return 0 ;
}
static void F_222 ( struct V_1 * V_2 )
{
if ( V_2 -> V_262 ) {
F_219 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) ;
F_219 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) ;
F_216 ( V_2 ) ;
}
F_212 ( V_2 ) ;
}
static int F_223 ( struct V_1 * V_2 )
{
if ( F_224 ( V_2 -> V_154 , V_248 , L_143 ) == NULL ) {
F_12 ( ( L_144 ,
V_2 -> V_8 , V_2 -> V_154 ) ) ;
V_2 -> V_36 = V_455 ;
goto V_456;
}
else
V_2 -> V_457 = true ;
V_2 -> V_458 = F_225 ( V_2 -> V_154 , V_248 ) ;
if ( ! V_2 -> V_458 ) {
F_12 ( ( L_145 ,
V_2 -> V_8 , V_2 -> V_154 ) ) ;
V_2 -> V_36 = V_459 ;
goto V_456;
}
return 0 ;
V_456:
F_226 ( V_2 ) ;
return - V_33 ;
}
static void F_226 ( struct V_1 * V_2 )
{
if ( V_2 -> V_460 ) {
F_227 ( V_2 -> V_155 , V_2 ) ;
V_2 -> V_460 = false ;
}
if ( V_2 -> V_457 ) {
F_228 ( V_2 -> V_154 , V_248 ) ;
V_2 -> V_457 = false ;
}
if ( V_2 -> V_458 ) {
F_229 ( V_2 -> V_458 ) ;
V_2 -> V_458 = NULL ;
}
}
static void F_230 ( struct V_1 * V_2 )
{
char * V_461 ;
V_2 -> V_35 = NULL ;
V_2 -> line = V_31 ;
sprintf ( V_2 -> V_8 , L_146 , V_462 , V_2 -> line ) ;
if ( V_2 -> line < V_463 ) {
if ( V_464 [ V_2 -> line ] )
V_2 -> V_77 = V_464 [ V_2 -> line ] ;
}
V_31 ++ ;
if ( ! V_34 )
V_34 = V_2 ;
else {
struct V_1 * V_465 = V_34 ;
while( V_465 -> V_35 )
V_465 = V_465 -> V_35 ;
V_465 -> V_35 = V_2 ;
}
if ( V_2 -> V_77 < 4096 )
V_2 -> V_77 = 4096 ;
else if ( V_2 -> V_77 > 65535 )
V_2 -> V_77 = 65535 ;
switch( V_2 -> V_449 -> V_466 ) {
case V_467 :
V_461 = L_147 ;
break;
case V_468 :
V_461 = L_148 ;
break;
case V_469 :
V_461 = L_149 ;
break;
case V_470 :
V_461 = L_150 ;
V_2 -> V_68 . V_69 = V_89 ;
break;
default:
V_461 = L_151 ;
}
F_2 ( L_152 ,
V_461 , V_2 -> V_8 , V_2 -> V_154 ,
V_2 -> V_155 , V_2 -> V_77 ) ;
#if V_304
F_127 ( V_2 ) ;
#endif
}
static struct V_1 * F_231 ( int V_471 , int V_472 , struct V_473 * V_449 )
{
struct V_1 * V_2 ;
V_2 = F_232 ( sizeof( struct V_1 ) , V_362 ) ;
if ( ! V_2 ) {
F_12 ( ( L_153 ,
V_32 , V_471 , V_472 ) ) ;
} else {
F_233 ( & V_2 -> V_38 ) ;
V_2 -> V_38 . V_25 = & V_474 ;
V_2 -> V_18 = V_19 ;
F_234 ( & V_2 -> V_277 , F_143 ) ;
V_2 -> V_77 = 4096 ;
V_2 -> V_147 = 14745600 ;
V_2 -> V_315 = V_387 ;
V_2 -> V_38 . V_475 = 5 * V_253 / 10 ;
V_2 -> V_38 . V_476 = 30 * V_253 ;
F_199 ( & V_2 -> V_294 ) ;
F_199 ( & V_2 -> V_295 ) ;
F_235 ( & V_2 -> V_48 ) ;
memcpy ( & V_2 -> V_68 , & V_477 , sizeof( T_7 ) ) ;
V_2 -> V_385 = V_478 ;
V_2 -> V_471 = V_471 ;
V_2 -> V_472 = V_472 ;
F_236 ( & V_2 -> V_71 , V_479 , ( unsigned long ) V_2 ) ;
F_236 ( & V_2 -> V_271 , V_480 , ( unsigned long ) V_2 ) ;
V_2 -> V_449 = V_449 ;
V_2 -> V_155 = V_449 -> V_249 ;
V_2 -> V_154 = F_237 ( V_449 , 0 ) ;
V_2 -> V_481 = V_482 ;
V_2 -> V_483 = V_484 ;
V_2 -> V_36 = - 1 ;
}
return V_2 ;
}
static void F_238 ( int V_471 , struct V_473 * V_449 )
{
struct V_1 * V_354 [ V_485 ] ;
int V_6 ;
int V_353 = 1 ;
if ( V_449 -> V_466 == V_468 )
V_353 = 2 ;
else if ( V_449 -> V_466 == V_469 )
V_353 = 4 ;
for ( V_6 = 0 ; V_6 < V_353 ; ++ V_6 ) {
V_354 [ V_6 ] = F_231 ( V_471 , V_6 , V_449 ) ;
if ( V_354 [ V_6 ] == NULL ) {
for ( -- V_6 ; V_6 >= 0 ; -- V_6 )
F_176 ( V_354 [ V_6 ] ) ;
return;
}
}
for ( V_6 = 0 ; V_6 < V_353 ; ++ V_6 ) {
memcpy ( V_354 [ V_6 ] -> V_354 , V_354 , sizeof( V_354 ) ) ;
F_230 ( V_354 [ V_6 ] ) ;
V_354 [ V_6 ] -> V_353 = V_353 ;
F_235 ( & V_354 [ V_6 ] -> V_54 ) ;
}
if ( ! F_223 ( V_354 [ 0 ] ) ) {
F_220 ( V_354 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_353 ; ++ V_6 ) {
V_354 [ V_6 ] -> V_155 = V_354 [ 0 ] -> V_155 ;
V_354 [ V_6 ] -> V_458 = V_354 [ 0 ] -> V_458 ;
F_220 ( V_354 [ V_6 ] ) ;
}
if ( F_239 ( V_354 [ 0 ] -> V_155 ,
F_171 ,
V_354 [ 0 ] -> V_483 ,
V_354 [ 0 ] -> V_8 ,
V_354 [ 0 ] ) < 0 ) {
F_12 ( ( L_154 ,
V_354 [ 0 ] -> V_8 ,
V_354 [ 0 ] -> V_155 ) ) ;
} else {
V_354 [ 0 ] -> V_460 = true ;
F_240 ( V_354 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_353 ; V_6 ++ ) {
V_354 [ V_6 ] -> V_36 = V_354 [ 0 ] -> V_36 ;
V_354 [ V_6 ] -> V_358 = V_354 [ 0 ] -> V_358 ;
}
}
}
for ( V_6 = 0 ; V_6 < V_353 ; ++ V_6 )
F_241 ( V_486 , V_354 [ V_6 ] -> line , & ( V_354 [ V_6 ] -> V_449 -> V_179 ) ) ;
}
static int T_10 F_242 ( struct V_473 * V_179 ,
const struct V_487 * V_488 )
{
if ( F_243 ( V_179 ) ) {
F_2 ( L_155 , V_179 ) ;
return - V_75 ;
}
F_244 ( V_179 ) ;
F_238 ( V_31 , V_179 ) ;
return 0 ;
}
static void T_11 F_245 ( struct V_473 * V_179 )
{
}
static void F_246 ( void )
{
int V_148 ;
struct V_1 * V_2 ;
struct V_1 * V_489 ;
F_2 ( V_490 L_156 , V_32 ) ;
if ( V_486 ) {
for ( V_2 = V_34 ; V_2 != NULL ; V_2 = V_2 -> V_35 )
F_247 ( V_486 , V_2 -> line ) ;
if ( ( V_148 = F_248 ( V_486 ) ) )
F_12 ( ( L_157 , V_148 ) ) ;
F_249 ( V_486 ) ;
}
V_2 = V_34 ;
while( V_2 ) {
F_250 ( V_2 ) ;
V_2 = V_2 -> V_35 ;
}
V_2 = V_34 ;
while( V_2 ) {
#if V_304
F_132 ( V_2 ) ;
#endif
F_222 ( V_2 ) ;
F_212 ( V_2 ) ;
if ( V_2 -> V_472 == 0 )
F_226 ( V_2 ) ;
V_489 = V_2 ;
V_2 = V_2 -> V_35 ;
F_176 ( V_489 ) ;
}
if ( V_491 )
F_251 ( & V_492 ) ;
}
static int T_12 F_252 ( void )
{
int V_148 ;
F_2 ( V_490 L_158 , V_32 ) ;
V_486 = F_253 ( V_463 ) ;
if ( ! V_486 ) {
F_2 ( L_159 , V_32 ) ;
return - V_245 ;
}
V_486 -> V_493 = V_206 ;
V_486 -> V_32 = V_494 ;
V_486 -> V_17 = V_462 ;
V_486 -> V_495 = V_496 ;
V_486 -> V_497 = 64 ;
V_486 -> type = V_498 ;
V_486 -> V_499 = V_500 ;
V_486 -> V_501 = V_502 ;
V_486 -> V_501 . V_59 =
V_503 | V_373 | V_366 | V_365 | V_380 ;
V_486 -> V_501 . V_504 = 9600 ;
V_486 -> V_501 . V_505 = 9600 ;
V_486 -> V_22 = V_506 | V_507 ;
F_254 ( V_486 , & V_25 ) ;
if ( ( V_148 = F_255 ( V_486 ) ) < 0 ) {
F_12 ( ( L_160 , V_32 ) ) ;
F_249 ( V_486 ) ;
V_486 = NULL ;
goto error;
}
F_2 ( V_490 L_161 ,
V_32 , V_486 -> V_495 ) ;
V_31 = 0 ;
if ( ( V_148 = F_256 ( & V_492 ) ) < 0 ) {
F_2 ( L_162 , V_32 , V_148 ) ;
goto error;
}
V_491 = true ;
if ( ! V_34 )
F_2 ( L_163 , V_32 ) ;
return 0 ;
error:
F_246 () ;
return V_148 ;
}
static void T_13 F_257 ( void )
{
F_246 () ;
}
static T_1 F_258 ( struct V_1 * V_2 , unsigned int V_508 )
{
F_259 () ;
return F_260 ( ( void V_509 * ) V_458 ) ;
}
static void F_261 ( struct V_1 * V_2 , unsigned int V_508 , T_1 V_174 )
{
F_259 () ;
F_262 ( V_174 , ( void V_509 * ) V_458 ) ;
}
static T_14 F_99 ( struct V_1 * V_2 , unsigned int V_508 )
{
F_259 () ;
return F_263 ( ( void V_509 * ) V_458 ) ;
}
static void F_100 ( struct V_1 * V_2 , unsigned int V_508 , T_14 V_174 )
{
F_259 () ;
F_264 ( V_174 , ( void V_509 * ) V_458 ) ;
}
static T_8 F_164 ( struct V_1 * V_2 , unsigned int V_508 )
{
F_259 () ;
return F_265 ( ( void V_509 * ) V_458 ) ;
}
static void F_165 ( struct V_1 * V_2 , unsigned int V_508 , T_8 V_174 )
{
F_259 () ;
F_266 ( V_174 , ( void V_509 * ) V_458 ) ;
}
static void F_267 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_165 ( V_2 , V_333 , V_266 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_164 ( V_2 , V_333 ) & V_267 ) )
break;
}
static void F_168 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_165 ( V_2 , V_336 , V_266 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_164 ( V_2 , V_336 ) & V_267 ) )
break;
}
static void F_268 ( struct V_1 * V_2 )
{
F_100 ( V_2 , V_409 , ( unsigned short ) ( F_99 ( V_2 , V_409 ) | V_296 ) ) ;
if ( V_2 -> V_68 . V_69 != V_89 ) {
F_261 ( V_2 , V_510 , 0x49 ) ;
if ( V_2 -> V_68 . V_137 )
F_269 ( V_2 , V_2 -> V_68 . V_137 ) ;
else
F_269 ( V_2 , 3686400 ) ;
}
}
static void F_269 ( struct V_1 * V_2 , T_9 V_511 )
{
unsigned int div ;
unsigned int V_512 = V_2 -> V_147 ;
if ( V_511 ) {
div = V_512 / V_511 ;
if ( ! ( V_512 % V_511 ) && div )
div -- ;
F_100 ( V_2 , V_513 , ( unsigned short ) div ) ;
}
}
static void F_157 ( struct V_1 * V_2 )
{
unsigned short V_339 ;
V_339 = F_99 ( V_2 , V_389 ) & ~ V_266 ;
F_100 ( V_2 , V_389 , ( unsigned short ) ( V_339 | V_296 ) ) ;
F_100 ( V_2 , V_389 , V_339 ) ;
F_151 ( V_2 , V_332 + V_313 + V_328 ) ;
F_100 ( V_2 , V_312 , V_328 + V_332 ) ;
F_267 ( V_2 ) ;
V_2 -> V_388 = false ;
V_2 -> V_283 = false ;
}
static void F_148 ( struct V_1 * V_2 )
{
unsigned short V_339 ;
F_151 ( V_2 , V_332 + V_313 ) ;
F_100 ( V_2 , V_312 , V_332 ) ;
V_339 = F_99 ( V_2 , V_389 ) & ~ V_266 ;
F_100 ( V_2 , V_389 , ( unsigned short ) ( V_339 | V_296 ) ) ;
F_100 ( V_2 , V_389 , V_339 ) ;
F_267 ( V_2 ) ;
F_221 ( V_2 ) ;
if ( V_2 -> V_320 ) {
F_100 ( V_2 , V_409 , ( unsigned short ) ( F_99 ( V_2 , V_409 ) & ~ V_514 ) ) ;
F_181 ( V_2 , V_313 ) ;
if ( V_2 -> V_68 . V_69 == V_89 ) {
F_165 ( V_2 , V_333 , V_177 ) ;
}
} else {
F_100 ( V_2 , V_409 , ( unsigned short ) ( F_99 ( V_2 , V_409 ) | V_514 ) ) ;
F_165 ( V_2 , V_515 , V_2 -> V_15 [ 0 ] . V_452 ) ;
if ( V_2 -> V_68 . V_69 != V_89 ) {
F_165 ( V_2 , V_333 , ( V_296 + V_267 ) ) ;
} else {
F_165 ( V_2 , V_333 , ( V_177 + V_296 + V_267 ) ) ;
}
}
F_181 ( V_2 , V_332 ) ;
F_100 ( V_2 , V_389 , ( unsigned short ) ( F_99 ( V_2 , V_389 ) | V_266 ) ) ;
V_2 -> V_283 = false ;
V_2 -> V_388 = true ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_82 ) {
F_100 ( V_2 , V_176 ,
( unsigned short ) ( ( F_99 ( V_2 , V_176 ) | V_266 ) & ~ V_296 ) ) ;
V_2 -> V_82 = true ;
}
if ( F_136 ( V_2 -> V_11 [ V_2 -> V_337 ] ) ) {
V_2 -> V_340 = false ;
if ( V_2 -> V_68 . V_69 != V_89 ) {
if ( V_2 -> V_68 . V_22 & V_516 ) {
F_87 ( V_2 ) ;
if ( ! ( V_2 -> V_62 & V_63 ) ) {
V_2 -> V_62 |= V_63 ;
F_33 ( V_2 ) ;
V_2 -> V_340 = true ;
}
}
F_151 ( V_2 , V_338 ) ;
F_181 ( V_2 , V_327 + V_319 ) ;
F_100 ( V_2 , V_312 , ( unsigned short ) ( V_319 + V_327 ) ) ;
} else {
F_151 ( V_2 , V_338 ) ;
F_181 ( V_2 , V_319 ) ;
F_100 ( V_2 , V_312 , V_319 ) ;
}
F_165 ( V_2 , V_517 , V_2 -> V_11 [ V_2 -> V_337 ] . V_452 ) ;
F_165 ( V_2 , V_336 , V_296 + V_267 ) ;
V_2 -> V_86 = true ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned short V_339 ;
F_169 ( & V_2 -> V_71 ) ;
F_168 ( V_2 ) ;
V_339 = F_99 ( V_2 , V_176 ) & ~ V_266 ;
F_100 ( V_2 , V_176 , ( unsigned short ) ( V_339 | V_296 ) ) ;
F_151 ( V_2 , V_338 + V_319 + V_327 ) ;
F_100 ( V_2 , V_312 , ( unsigned short ) ( V_319 + V_327 ) ) ;
F_270 ( V_2 ) ;
V_2 -> V_82 = false ;
V_2 -> V_86 = false ;
}
static void F_250 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_458 )
return;
F_54 ( V_2 ) ;
F_157 ( V_2 ) ;
V_2 -> V_62 &= ~ ( V_64 + V_63 ) ;
F_33 ( V_2 ) ;
F_151 ( V_2 , V_363 | V_364 ) ;
}
static void F_271 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_353 ; ++ V_6 ) {
if ( V_2 -> V_354 [ V_6 ] )
F_250 ( V_2 -> V_354 [ V_6 ] ) ;
}
}
static void F_180 ( struct V_1 * V_2 )
{
unsigned short V_339 ;
F_151 ( V_2 , V_363 | V_364 ) ;
F_54 ( V_2 ) ;
F_157 ( V_2 ) ;
V_339 = 0x4000 ;
if ( V_2 -> V_412 & V_413 )
V_339 |= V_414 ;
if ( V_2 -> V_68 . V_128 != V_379 ) {
V_339 |= V_518 ;
if ( V_2 -> V_68 . V_128 == V_377 )
V_339 |= V_355 ;
}
switch ( V_2 -> V_68 . V_142 )
{
case 6 : V_339 |= V_335 ; break;
case 7 : V_339 |= V_334 ; break;
case 8 : V_339 |= V_334 + V_335 ; break;
}
if ( V_2 -> V_68 . V_143 != 1 )
V_339 |= V_288 ;
if ( V_2 -> V_68 . V_22 & V_519 )
V_339 |= V_267 ;
F_100 ( V_2 , V_176 , V_339 ) ;
V_339 = 0x4000 ;
if ( V_2 -> V_68 . V_128 != V_379 ) {
V_339 |= V_518 ;
if ( V_2 -> V_68 . V_128 == V_377 )
V_339 |= V_355 ;
}
switch ( V_2 -> V_68 . V_142 )
{
case 6 : V_339 |= V_335 ; break;
case 7 : V_339 |= V_334 ; break;
case 8 : V_339 |= V_334 + V_335 ; break;
}
if ( V_2 -> V_68 . V_22 & V_520 )
V_339 |= V_267 ;
F_100 ( V_2 , V_389 , V_339 ) ;
F_261 ( V_2 , V_510 , 0x69 ) ;
F_197 ( V_2 ) ;
V_339 = V_317 + V_514 + V_267 ;
if ( ( F_164 ( V_2 , V_521 ) & V_355 ) && V_2 -> V_68 . V_85 &&
( ( V_2 -> V_147 < ( V_2 -> V_68 . V_85 * 16 ) ) ||
( V_2 -> V_147 % ( V_2 -> V_68 . V_85 * 16 ) ) ) ) {
V_339 |= V_288 ;
F_269 ( V_2 , V_2 -> V_68 . V_85 * 8 ) ;
} else {
F_269 ( V_2 , V_2 -> V_68 . V_85 * 16 ) ;
}
F_100 ( V_2 , V_409 , V_339 ) ;
F_181 ( V_2 , V_321 | V_332 ) ;
if ( V_2 -> V_68 . V_135 )
F_268 ( V_2 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
unsigned short V_339 ;
F_151 ( V_2 , V_363 | V_364 ) ;
F_54 ( V_2 ) ;
F_157 ( V_2 ) ;
V_339 = V_296 ;
switch( V_2 -> V_68 . V_69 ) {
case V_282 :
V_339 |= V_317 + V_522 ;
break;
case V_280 : V_339 |= V_514 + V_522 ; break;
case V_281 : V_339 |= V_317 ; break;
case V_279 : V_339 |= V_522 ; break;
}
if ( V_2 -> V_412 & V_413 )
V_339 |= V_414 ;
switch( V_2 -> V_68 . V_136 )
{
case V_523 : V_339 |= V_316 ; break;
case V_524 : V_339 |= V_525 ; break;
case V_526 : V_339 |= V_525 + V_316 ; break;
case V_187 : V_339 |= V_527 ; break;
case V_189 : V_339 |= V_527 + V_316 ; break;
case V_191 : V_339 |= V_527 + V_525 ; break;
case V_528 : V_339 |= V_527 + V_525 + V_316 ; break;
}
switch ( V_2 -> V_68 . V_139 & V_529 )
{
case V_195 : V_339 |= V_518 ; break;
case V_197 : V_339 |= V_518 + V_355 ; break;
}
if ( V_2 -> V_68 . V_141 != V_530 )
V_339 |= V_177 ;
switch ( V_2 -> V_68 . V_140 )
{
case V_531 : V_339 |= V_334 ; break;
case V_532 : V_339 |= V_335 ; break;
case V_533 : V_339 |= V_334 + V_335 ; break;
}
if ( V_2 -> V_68 . V_22 & V_519 )
V_339 |= V_267 ;
F_100 ( V_2 , V_176 , V_339 ) ;
switch ( V_2 -> V_68 . V_141 )
{
case V_534 : V_339 = 0x7e ; break;
case V_535 : V_339 = 0xff ; break;
case V_536 : V_339 = 0x00 ; break;
case V_537 : V_339 = 0x55 ; break;
case V_538 : V_339 = 0xaa ; break;
default: V_339 = 0x7e ; break;
}
F_261 ( V_2 , V_539 , ( unsigned char ) V_339 ) ;
V_339 = 0 ;
switch( V_2 -> V_68 . V_69 ) {
case V_282 :
V_339 |= V_317 + V_522 ;
break;
case V_280 : V_339 |= V_514 + V_522 ; break;
case V_281 : V_339 |= V_317 ; break;
case V_279 : V_339 |= V_522 ; break;
}
switch( V_2 -> V_68 . V_136 )
{
case V_523 : V_339 |= V_316 ; break;
case V_524 : V_339 |= V_525 ; break;
case V_526 : V_339 |= V_525 + V_316 ; break;
case V_187 : V_339 |= V_527 ; break;
case V_189 : V_339 |= V_527 + V_316 ; break;
case V_191 : V_339 |= V_527 + V_525 ; break;
case V_528 : V_339 |= V_527 + V_525 + V_316 ; break;
}
switch ( V_2 -> V_68 . V_139 & V_529 )
{
case V_195 : V_339 |= V_518 ; break;
case V_197 : V_339 |= V_518 + V_355 ; break;
}
if ( V_2 -> V_68 . V_22 & V_520 )
V_339 |= V_267 ;
F_100 ( V_2 , V_389 , V_339 ) ;
V_339 = 0 ;
if ( V_2 -> V_68 . V_22 & V_225 )
{
if ( V_2 -> V_68 . V_22 & V_220 )
V_339 |= V_177 + V_334 ;
else
V_339 |= V_177 ;
}
else if ( V_2 -> V_68 . V_22 & V_224 )
V_339 |= V_414 ;
else if ( V_2 -> V_68 . V_22 & V_226 )
V_339 |= V_334 ;
if ( V_2 -> V_68 . V_22 & V_221 )
V_339 |= V_288 ;
else if ( V_2 -> V_68 . V_22 & V_220 )
V_339 |= V_335 ;
else if ( V_2 -> V_68 . V_22 & V_222 )
V_339 |= V_296 ;
if ( V_2 -> V_68 . V_137 )
V_339 |= V_266 + V_267 ;
F_261 ( V_2 , V_510 , ( unsigned char ) V_339 ) ;
if ( V_2 -> V_68 . V_22 & ( V_224 + V_220 ) )
{
switch( V_2 -> V_68 . V_136 )
{
case V_187 :
case V_189 :
V_339 = V_414 ; break;
case V_191 :
case V_528 :
V_339 = V_414 + V_177 ; break;
default: V_339 = V_177 ;
}
F_100 ( V_2 , V_389 , ( unsigned short ) ( F_99 ( V_2 , V_389 ) | V_339 ) ) ;
F_269 ( V_2 , V_2 -> V_68 . V_137 * 16 ) ;
}
else
F_269 ( V_2 , V_2 -> V_68 . V_137 ) ;
F_189 ( V_2 ) ;
F_197 ( V_2 ) ;
F_100 ( V_2 , V_409 , V_317 + V_514 + V_267 ) ;
if ( V_2 -> V_68 . V_135 )
F_268 ( V_2 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
unsigned char V_339 ;
unsigned short V_540 ;
V_540 = F_99 ( V_2 , V_176 ) ;
if ( V_2 -> V_385 & V_541 ) {
V_540 = ( V_540 & ~ ( V_177 + V_334 ) ) | V_335 ;
F_261 ( V_2 , V_539 , ( unsigned char ) ( ( V_2 -> V_385 >> 8 ) & 0xff ) ) ;
} else if ( ! ( V_540 & V_177 ) ) {
V_540 &= ~ ( V_334 + V_335 ) ;
}
F_100 ( V_2 , V_176 , V_540 ) ;
if ( V_2 -> V_385 & ( V_542 | V_541 ) ) {
V_339 = ( unsigned char ) ( V_2 -> V_385 & 0xff ) ;
} else {
switch( V_2 -> V_385 )
{
case V_478 : V_339 = 0x7e ; break;
case V_543 :
case V_544 : V_339 = 0xaa ; break;
case V_545 :
case V_546 : V_339 = 0x00 ; break;
default: V_339 = 0xff ;
}
}
F_261 ( V_2 , V_547 , V_339 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_99 ( V_2 , V_312 ) ;
V_2 -> V_62 &= V_64 + V_63 ;
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
unsigned char V_339 = 0 ;
switch( V_2 -> V_412 & V_548 )
{
case V_549 :
V_339 |= V_334 ;
break;
case V_550 :
V_339 |= V_414 + V_177 + V_334 ;
break;
case V_551 :
V_339 |= V_177 ;
break;
}
if ( V_2 -> V_412 & V_552 )
V_339 |= V_335 ;
if ( V_2 -> V_62 & V_64 )
V_339 |= V_288 ;
if ( V_2 -> V_62 & V_63 )
V_339 |= V_296 ;
if ( V_2 -> V_412 & V_553 )
V_339 |= V_266 ;
if ( V_2 -> V_412 & V_554 )
V_339 |= V_267 ;
F_261 ( V_2 , V_555 , V_339 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned char V_339 = F_258 ( V_2 , V_555 ) ;
if ( V_2 -> V_62 & V_64 )
V_339 |= V_288 ;
else
V_339 &= ~ V_288 ;
if ( V_2 -> V_62 & V_63 )
V_339 |= V_296 ;
else
V_339 &= ~ V_296 ;
F_261 ( V_2 , V_555 , V_339 ) ;
}
static void F_140 ( struct V_1 * V_2 , unsigned int V_6 , unsigned int V_556 )
{
int V_557 = 0 ;
while( ! V_557 ) {
V_2 -> V_15 [ V_6 ] . V_12 = 0 ;
F_158 ( V_2 -> V_15 [ V_6 ] , V_2 -> V_315 ) ;
if ( V_6 == V_556 )
V_557 = 1 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
}
V_2 -> V_13 = V_6 ;
}
static void F_221 ( struct V_1 * V_2 )
{
F_140 ( V_2 , 0 , V_2 -> V_14 - 1 ) ;
V_2 -> V_310 = 0 ;
V_2 -> V_309 = 0 ;
}
static bool F_146 ( struct V_1 * V_2 )
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
if ( ! F_135 ( V_2 -> V_15 [ V_259 ] ) )
goto V_44;
if ( V_558 == 0 && V_2 -> V_68 . V_138 != 0xff )
V_559 = V_2 -> V_15 [ V_259 ] . V_73 [ 0 ] ;
V_558 += F_136 ( V_2 -> V_15 [ V_259 ] ) ;
if ( F_272 ( V_2 -> V_15 [ V_259 ] ) )
break;
if ( ++ V_259 == V_2 -> V_14 )
V_259 = 0 ;
if ( V_259 == V_2 -> V_13 ) {
if ( V_2 -> V_388 ) {
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_148 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
}
goto V_44;
}
}
V_12 = F_273 ( V_2 -> V_15 [ V_259 ] ) ;
if ( ( V_2 -> V_68 . V_139 & V_529 ) == V_193 )
V_12 &= ~ V_266 ;
if ( V_558 == 0 ||
( V_559 != 0xff && V_559 != V_2 -> V_68 . V_138 ) ) {
F_140 ( V_2 , V_258 , V_259 ) ;
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
#if V_304
if ( V_558 == 0 ) {
V_2 -> V_238 -> V_202 . V_563 ++ ;
V_2 -> V_238 -> V_202 . V_564 ++ ;
}
#endif
F_145 ( ( L_164 ,
V_2 -> V_8 , V_12 , V_558 ) ) ;
F_138 ( V_2 , V_2 -> V_15 [ V_258 ] . V_73 , F_45 ( int , V_558 , V_2 -> V_315 ) , L_94 ) ;
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
int V_567 = F_45 ( int , V_565 , V_2 -> V_315 ) ;
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
#if V_304
if ( V_2 -> V_49 )
F_122 ( V_2 , V_2 -> V_447 , V_558 ) ;
else
#endif
F_8 ( V_21 , V_2 -> V_447 , V_2 -> V_570 , V_558 ) ;
}
}
F_140 ( V_2 , V_258 , V_259 ) ;
return true ;
V_44:
return false ;
}
static bool F_147 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_2 -> V_13 ;
unsigned int V_4 ;
if ( ! F_135 ( V_2 -> V_15 [ V_6 ] ) )
return false ;
V_4 = F_136 ( V_2 -> V_15 [ V_6 ] ) ;
switch( V_2 -> V_68 . V_69 ) {
case V_280 :
case V_281 :
case V_282 :
if ( F_274 ( V_2 -> V_15 [ V_6 ] ) )
V_4 -- ;
break;
}
F_138 ( V_2 , V_2 -> V_15 [ V_6 ] . V_73 , V_4 , L_94 ) ;
F_13 ( ( L_165 , V_4 ) ) ;
if ( V_4 )
F_8 ( V_2 -> V_38 . V_21 , V_2 -> V_15 [ V_6 ] . V_73 ,
V_2 -> V_570 , V_4 ) ;
F_140 ( V_2 , V_6 , V_6 ) ;
return true ;
}
static void F_270 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_2 -> V_9 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_12 = 0 ;
V_2 -> V_11 [ V_6 ] . V_4 = 0 ;
}
}
static unsigned int F_275 ( struct V_1 * V_2 )
{
unsigned int V_4 = 0 ;
unsigned int V_6 = V_2 -> V_9 ;
do
{
if ( F_136 ( V_2 -> V_11 [ V_6 ] ) )
break;
++ V_4 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
} while ( V_6 != V_2 -> V_9 );
if ( V_4 && ( F_164 ( V_2 , V_336 ) & V_267 ) )
-- V_4 ;
return V_4 ;
}
static unsigned int F_37 ( struct V_1 * V_2 )
{
unsigned int V_571 = 0 ;
unsigned int V_6 = V_2 -> V_9 ;
unsigned int V_572 ;
unsigned int V_4 ;
unsigned int V_573 = 0 ;
do {
V_4 = F_136 ( V_2 -> V_11 [ V_6 ] ) ;
if ( V_4 )
V_571 += V_4 ;
else if ( ! V_571 )
V_573 = V_2 -> V_11 [ V_6 ] . V_574 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
} while ( V_6 != V_2 -> V_9 );
V_572 = F_164 ( V_2 , V_336 ) ;
if ( V_572 & V_267 )
V_571 += V_573 ;
V_571 += ( V_572 >> 8 ) & 0xff ;
if ( V_2 -> V_86 )
V_571 ++ ;
return V_571 ;
}
static bool F_41 ( struct V_1 * V_2 , const char * V_73 , unsigned int V_209 )
{
unsigned short V_4 ;
unsigned int V_6 ;
struct V_261 * V_575 ;
if ( F_276 ( V_209 , V_387 ) > F_275 ( V_2 ) )
return false ;
F_138 ( V_2 , V_73 , V_209 , L_166 ) ;
V_2 -> V_337 = V_6 = V_2 -> V_9 ;
while ( V_209 ) {
V_575 = & V_2 -> V_11 [ V_6 ] ;
V_4 = ( unsigned short ) ( ( V_209 > V_387 ) ? V_387 : V_209 ) ;
memcpy ( V_575 -> V_73 , V_73 , V_4 ) ;
V_209 -= V_4 ;
V_73 += V_4 ;
if ( ( ! V_209 && V_2 -> V_68 . V_69 == V_70 ) ||
V_2 -> V_68 . V_69 == V_279 )
F_277 ( * V_575 , 1 ) ;
else
F_277 ( * V_575 , 0 ) ;
if ( V_6 != V_2 -> V_337 )
F_158 ( * V_575 , V_4 ) ;
V_575 -> V_574 = V_4 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
}
V_2 -> V_9 = V_6 ;
V_575 = & V_2 -> V_11 [ V_2 -> V_337 ] ;
F_158 ( * V_575 , V_575 -> V_574 ) ;
if ( ! V_2 -> V_86 )
F_44 ( V_2 ) ;
F_36 ( V_2 ) ;
return true ;
}
static int F_278 ( struct V_1 * V_2 )
{
static unsigned short V_576 [] =
{ 0x0000 , 0xffff , 0xaaaa , 0x5555 , 0x6969 , 0x9696 } ;
static unsigned int V_4 = F_279 ( V_576 ) ;
unsigned int V_6 ;
int V_148 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
F_100 ( V_2 , V_547 , V_576 [ V_6 ] ) ;
F_100 ( V_2 , V_513 , V_576 [ ( V_6 + 1 ) % V_4 ] ) ;
if ( ( F_99 ( V_2 , V_547 ) != V_576 [ V_6 ] ) ||
( F_99 ( V_2 , V_513 ) != V_576 [ ( V_6 + 1 ) % V_4 ] ) ) {
V_148 = - V_33 ;
break;
}
}
V_2 -> V_358 = ( F_164 ( V_2 , V_521 ) & V_334 ) ? 1 : 0 ;
V_2 -> V_36 = V_148 ? 0 : V_577 ;
return V_148 ;
}
static int F_280 ( struct V_1 * V_2 )
{
unsigned long V_52 ;
unsigned long V_22 ;
struct V_20 * V_578 = V_2 -> V_38 . V_21 ;
T_9 V_579 = V_2 -> V_68 . V_85 ;
V_2 -> V_68 . V_85 = 921600 ;
V_2 -> V_38 . V_21 = NULL ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_180 ( V_2 ) ;
F_181 ( V_2 , V_319 ) ;
F_100 ( V_2 , V_176 ,
( unsigned short ) ( F_99 ( V_2 , V_176 ) | V_266 ) ) ;
F_100 ( V_2 , V_580 , 0 ) ;
V_2 -> V_36 = V_581 ;
V_2 -> V_318 = false ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
V_52 = 100 ;
while( V_52 -- && ! V_2 -> V_318 )
F_46 ( 10 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_250 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_68 . V_85 = V_579 ;
V_2 -> V_38 . V_21 = V_578 ;
V_2 -> V_36 = V_2 -> V_318 ? 0 : V_581 ;
return V_2 -> V_318 ? 0 : - V_33 ;
}
static int F_281 ( struct V_1 * V_2 )
{
unsigned char * V_582 , * V_583 ;
int V_4 ;
if ( F_135 ( V_2 -> V_15 [ 0 ] ) ) {
V_4 = F_136 ( V_2 -> V_15 [ 0 ] ) ;
V_582 = V_2 -> V_15 [ 0 ] . V_73 ;
V_583 = V_2 -> V_447 ;
for( ; V_4 ; V_4 -= 2 , V_582 += 2 ) {
if ( ! ( * ( V_582 + 1 ) & ( V_518 + V_355 ) ) ) {
* V_583 = * V_582 ;
V_583 ++ ;
V_2 -> V_566 ++ ;
}
}
F_138 ( V_2 , V_2 -> V_447 , V_2 -> V_566 , L_94 ) ;
return 1 ;
}
return 0 ;
}
static int F_282 ( struct V_1 * V_2 )
{
#define F_283 20
unsigned long V_52 ;
T_15 V_4 = F_283 ;
unsigned char V_73 [ F_283 ] ;
int V_148 = - V_33 ;
unsigned long V_22 ;
struct V_20 * V_578 = V_2 -> V_38 . V_21 ;
T_7 V_68 ;
memcpy ( & V_68 , & V_2 -> V_68 , sizeof( V_68 ) ) ;
V_2 -> V_68 . V_69 = V_89 ;
V_2 -> V_68 . V_85 = 921600 ;
V_2 -> V_68 . V_135 = 1 ;
V_2 -> V_38 . V_21 = NULL ;
for ( V_4 = 0 ; V_4 < F_283 ; ++ V_4 )
V_73 [ V_4 ] = ( unsigned char ) V_4 ;
V_2 -> V_566 = 0 ;
memset ( V_2 -> V_447 , 0 , F_283 ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_180 ( V_2 ) ;
F_148 ( V_2 ) ;
F_41 ( V_2 , V_73 , V_4 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
for ( V_52 = 100 ; V_52 ; -- V_52 ) {
F_46 ( 10 ) ;
if ( F_281 ( V_2 ) ) {
V_148 = 0 ;
break;
}
}
if ( ! V_148 && ( V_2 -> V_566 != V_4 ||
memcmp ( V_73 , V_2 -> V_447 , V_4 ) ) ) {
V_148 = - V_33 ;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_271 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
memcpy ( & V_2 -> V_68 , & V_68 , sizeof( V_2 -> V_68 ) ) ;
V_2 -> V_38 . V_21 = V_578 ;
V_2 -> V_36 = V_148 ? V_584 : 0 ;
return V_148 ;
}
static int F_240 ( struct V_1 * V_2 )
{
F_13 ( ( L_167 , V_2 -> V_8 ) ) ;
if ( F_278 ( V_2 ) < 0 ) {
F_2 ( L_168 ,
V_2 -> V_8 , V_2 -> V_154 ) ;
} else if ( F_280 ( V_2 ) < 0 ) {
F_2 ( L_169 ,
V_2 -> V_8 , V_2 -> V_155 ) ;
} else if ( F_282 ( V_2 ) < 0 ) {
F_2 ( L_170 , V_2 -> V_8 ) ;
}
return V_2 -> V_36 ;
}
static void V_479 ( unsigned long V_585 )
{
struct V_1 * V_2 = (struct V_1 * ) V_585 ;
unsigned long V_22 ;
F_13 ( ( L_171 , V_2 -> V_8 ) ) ;
if( V_2 -> V_86 && V_2 -> V_68 . V_69 == V_70 ) {
V_2 -> V_117 . V_586 ++ ;
}
F_17 ( & V_2 -> V_54 , V_22 ) ;
F_54 ( V_2 ) ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
#if V_304
if ( V_2 -> V_49 )
F_120 ( V_2 ) ;
else
#endif
F_149 ( V_2 ) ;
}
static void V_480 ( unsigned long V_585 )
{
struct V_1 * V_2 = (struct V_1 * ) V_585 ;
unsigned long V_22 ;
F_13 ( ( L_172 , V_2 -> V_8 ) ) ;
F_17 ( & V_2 -> V_54 , V_22 ) ;
V_2 -> V_170 |= V_272 ;
F_18 ( & V_2 -> V_54 , V_22 ) ;
F_143 ( & V_2 -> V_277 ) ;
}
