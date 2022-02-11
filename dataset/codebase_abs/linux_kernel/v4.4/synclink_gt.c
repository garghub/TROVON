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
F_14 ( & V_2 -> V_38 . V_39 ) ;
V_2 -> V_38 . V_40 = ( V_2 -> V_38 . V_22 & V_41 ) ? 1 : 0 ;
F_15 ( & V_2 -> V_42 , V_22 ) ;
if ( V_2 -> V_43 ) {
V_29 = - V_44 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
F_17 ( & V_2 -> V_38 . V_39 ) ;
goto V_45;
}
V_2 -> V_38 . V_4 ++ ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
if ( V_2 -> V_38 . V_4 == 1 ) {
V_29 = F_18 ( V_2 ) ;
if ( V_29 < 0 ) {
F_17 ( & V_2 -> V_38 . V_39 ) ;
goto V_45;
}
}
F_17 ( & V_2 -> V_38 . V_39 ) ;
V_29 = F_19 ( V_21 , V_28 , V_2 ) ;
if ( V_29 ) {
F_13 ( ( L_16 , V_2 -> V_8 , V_29 ) ) ;
goto V_45;
}
V_29 = 0 ;
V_45:
if ( V_29 ) {
if ( V_21 -> V_4 == 1 )
V_2 -> V_38 . V_21 = NULL ;
if( V_2 -> V_38 . V_4 )
V_2 -> V_38 . V_4 -- ;
}
F_13 ( ( L_17 , V_2 -> V_8 , V_29 ) ) ;
return V_29 ;
}
static void F_20 ( struct V_20 * V_21 , struct V_27 * V_28 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_18 ) )
return;
F_13 ( ( L_19 , V_2 -> V_8 , V_2 -> V_38 . V_4 ) ) ;
if ( F_21 ( & V_2 -> V_38 , V_21 , V_28 ) == 0 )
goto V_45;
F_14 ( & V_2 -> V_38 . V_39 ) ;
if ( V_2 -> V_38 . V_22 & V_46 )
F_22 ( V_21 , V_2 -> V_47 ) ;
F_23 ( V_21 ) ;
F_24 ( V_21 ) ;
F_25 ( V_2 ) ;
F_17 ( & V_2 -> V_38 . V_39 ) ;
F_26 ( & V_2 -> V_38 , V_21 ) ;
V_2 -> V_38 . V_21 = NULL ;
V_45:
F_13 ( ( L_20 , V_21 -> V_48 -> V_17 , V_2 -> V_38 . V_4 ) ) ;
}
static void F_27 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_21 ) )
return;
F_13 ( ( L_22 , V_2 -> V_8 ) ) ;
F_23 ( V_21 ) ;
F_14 ( & V_2 -> V_38 . V_39 ) ;
F_25 ( V_2 ) ;
F_15 ( & V_2 -> V_38 . V_49 , V_22 ) ;
V_2 -> V_38 . V_4 = 0 ;
V_2 -> V_38 . V_22 &= ~ V_50 ;
V_2 -> V_38 . V_21 = NULL ;
F_16 ( & V_2 -> V_38 . V_49 , V_22 ) ;
F_17 ( & V_2 -> V_38 . V_39 ) ;
F_28 ( & V_2 -> V_38 . V_51 ) ;
}
static void F_29 ( struct V_20 * V_21 , struct V_52 * V_53 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
F_13 ( ( L_23 , V_21 -> V_48 -> V_17 ) ) ;
F_30 ( V_2 ) ;
if ( V_53 -> V_54 & V_55 &&
! ( V_21 -> V_56 . V_54 & V_55 ) ) {
V_2 -> V_57 &= ~ ( V_58 | V_59 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_31 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
if ( ! ( V_53 -> V_54 & V_55 ) &&
V_21 -> V_56 . V_54 & V_55 ) {
V_2 -> V_57 |= V_59 ;
if ( ! ( V_21 -> V_56 . V_54 & V_60 ) ||
! F_32 ( V_61 , & V_21 -> V_22 ) ) {
V_2 -> V_57 |= V_58 ;
}
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_31 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
if ( V_53 -> V_54 & V_60 &&
! ( V_21 -> V_56 . V_54 & V_60 ) ) {
V_21 -> V_62 = 0 ;
F_33 ( V_21 ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_63 . V_64 == V_65 ) {
int V_47 = ( F_35 ( V_2 ) * 7 ) + 1000 ;
F_36 ( & V_2 -> V_66 , V_67 + F_37 ( V_47 ) ) ;
}
}
static int F_38 ( struct V_20 * V_21 ,
const unsigned char * V_68 , int V_4 )
{
int V_69 = 0 ;
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_24 ) )
return - V_70 ;
F_13 ( ( L_25 , V_2 -> V_8 , V_4 ) ) ;
if ( ! V_2 -> V_71 || ( V_4 > V_2 -> V_72 ) )
return - V_70 ;
if ( ! V_4 || V_21 -> V_73 || V_21 -> V_62 )
return 0 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_74 ) {
if ( ! F_39 ( V_2 , V_2 -> V_71 , V_2 -> V_74 ) )
goto V_45;
V_2 -> V_74 = 0 ;
}
if ( F_39 ( V_2 , V_68 , V_4 ) )
V_69 = V_4 ;
V_45:
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_13 ( ( L_26 , V_2 -> V_8 , V_69 ) ) ;
return V_69 ;
}
static int F_40 ( struct V_20 * V_21 , unsigned char V_75 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
int V_69 = 0 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_27 ) )
return 0 ;
F_13 ( ( L_28 , V_2 -> V_8 , V_75 ) ) ;
if ( ! V_2 -> V_71 )
return 0 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_74 < V_2 -> V_72 ) {
V_2 -> V_71 [ V_2 -> V_74 ++ ] = V_75 ;
V_69 = 1 ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
return V_69 ;
}
static void F_41 ( struct V_20 * V_21 , char V_75 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_29 ) )
return;
F_13 ( ( L_30 , V_2 -> V_8 , V_75 ) ) ;
V_2 -> V_76 = V_75 ;
if ( V_75 ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( ! V_2 -> V_77 )
F_42 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
}
static void F_22 ( struct V_20 * V_21 , int V_47 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_78 , V_79 ;
if ( ! V_2 )
return;
if ( F_6 ( V_2 , V_21 -> V_17 , L_31 ) )
return;
F_13 ( ( L_32 , V_2 -> V_8 ) ) ;
if ( ! ( V_2 -> V_38 . V_22 & V_46 ) )
goto exit;
V_78 = V_67 ;
if ( V_2 -> V_63 . V_80 ) {
V_79 = V_2 -> V_47 / ( 32 * 5 ) ;
if ( ! V_79 )
V_79 ++ ;
} else
V_79 = 1 ;
if ( V_47 )
V_79 = F_43 (unsigned long, char_time, timeout) ;
while ( V_2 -> V_81 ) {
F_44 ( F_45 ( V_79 ) ) ;
if ( F_46 ( V_82 ) )
break;
if ( V_47 && F_47 ( V_67 , V_78 + V_47 ) )
break;
}
exit:
F_13 ( ( L_33 , V_2 -> V_8 ) ) ;
}
static int F_48 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_69 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_34 ) )
return 0 ;
V_69 = ( V_2 -> V_81 ) ? 0 : V_83 ;
F_13 ( ( L_35 , V_2 -> V_8 , V_69 ) ) ;
return V_69 ;
}
static void F_49 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_36 ) )
return;
F_13 ( ( L_37 , V_2 -> V_8 , V_2 -> V_74 ) ) ;
if ( V_2 -> V_74 <= 0 || V_21 -> V_73 ||
V_21 -> V_62 || ! V_2 -> V_71 )
return;
F_13 ( ( L_38 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_74 && F_39 ( V_2 , V_2 -> V_71 , V_2 -> V_74 ) )
V_2 -> V_74 = 0 ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
static void F_23 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_39 ) )
return;
F_13 ( ( L_40 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_74 = 0 ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_50 ( V_21 ) ;
}
static void F_51 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_41 ) )
return;
F_13 ( ( L_42 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_77 && V_2 -> V_63 . V_64 == V_84 )
F_52 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
static void F_33 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_43 ) )
return;
F_13 ( ( L_44 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_74 && F_39 ( V_2 , V_2 -> V_71 , V_2 -> V_74 ) )
V_2 -> V_74 = 0 ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
static int F_53 ( struct V_20 * V_21 ,
unsigned int V_85 , unsigned long V_86 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
void T_2 * V_87 = ( void T_2 * ) V_86 ;
int V_69 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_45 ) )
return - V_33 ;
F_13 ( ( L_46 , V_2 -> V_8 , V_85 ) ) ;
if ( ( V_85 != V_88 ) && ( V_85 != V_89 ) &&
( V_85 != V_90 ) ) {
if ( V_21 -> V_22 & ( 1 << V_91 ) )
return - V_70 ;
}
switch ( V_85 ) {
case V_92 :
return F_54 ( V_2 , V_87 ) ;
case V_90 :
return F_55 ( V_2 , ( int ) V_86 ) ;
case V_93 :
return F_56 ( V_2 , V_87 ) ;
case V_94 :
return F_57 ( V_2 , V_87 ) ;
case V_95 :
return F_58 ( V_2 , V_87 ) ;
case V_96 :
return F_59 ( V_2 , V_87 ) ;
case V_97 :
return F_60 ( V_2 , ( int ) V_86 ) ;
case V_98 :
return F_61 ( V_2 , V_87 ) ;
case V_99 :
return F_62 ( V_2 , ( int ) V_86 ) ;
}
F_14 ( & V_2 -> V_38 . V_39 ) ;
switch ( V_85 ) {
case V_100 :
V_69 = F_63 ( V_2 , V_87 ) ;
break;
case V_101 :
V_69 = F_64 ( V_2 , V_87 ) ;
break;
case V_102 :
V_69 = F_65 ( V_2 , V_87 ) ;
break;
case V_103 :
V_69 = F_66 ( V_2 , ( int ) V_86 ) ;
break;
case V_104 :
V_69 = F_67 ( V_2 , ( int ) V_86 ) ;
break;
case V_105 :
V_69 = F_68 ( V_2 , ( int ) V_86 ) ;
break;
case V_106 :
V_69 = F_69 ( V_2 ) ;
break;
case V_107 :
V_69 = F_70 ( V_2 , V_87 ) ;
break;
case V_108 :
V_69 = F_71 ( V_2 , V_87 ) ;
break;
case V_109 :
V_69 = F_72 ( V_2 , ( int ) V_86 ) ;
break;
default:
V_69 = - V_110 ;
}
F_17 ( & V_2 -> V_38 . V_39 ) ;
return V_69 ;
}
static int F_73 ( struct V_20 * V_21 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
struct V_113 V_114 ;
unsigned long V_22 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_114 = V_2 -> V_112 ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_112 -> V_115 = V_114 . V_115 ;
V_112 -> V_116 = V_114 . V_116 ;
V_112 -> V_117 = V_114 . V_117 ;
V_112 -> V_118 = V_114 . V_118 ;
V_112 -> V_119 = V_114 . V_119 ;
V_112 -> V_120 = V_114 . V_120 ;
V_112 -> V_121 = V_114 . V_121 ;
V_112 -> V_122 = V_114 . V_122 ;
V_112 -> V_123 = V_114 . V_123 ;
V_112 -> V_124 = V_114 . V_124 ;
V_112 -> V_125 = V_114 . V_125 ;
return 0 ;
}
static long F_74 ( struct V_1 * V_2 , struct V_126 T_2 * V_127 )
{
struct V_126 V_128 ;
F_13 ( ( L_47 , V_2 -> V_8 ) ) ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_64 = ( V_129 ) V_2 -> V_63 . V_64 ;
V_128 . V_130 = V_2 -> V_63 . V_130 ;
V_128 . V_22 = V_2 -> V_63 . V_22 ;
V_128 . V_131 = V_2 -> V_63 . V_131 ;
V_128 . V_132 = ( V_129 ) V_2 -> V_63 . V_132 ;
V_128 . V_133 = V_2 -> V_63 . V_133 ;
V_128 . V_134 = V_2 -> V_63 . V_134 ;
V_128 . V_135 = V_2 -> V_63 . V_135 ;
V_128 . V_136 = V_2 -> V_63 . V_136 ;
V_128 . V_80 = ( V_129 ) V_2 -> V_63 . V_80 ;
V_128 . V_137 = V_2 -> V_63 . V_137 ;
V_128 . V_138 = V_2 -> V_63 . V_138 ;
V_128 . V_123 = V_2 -> V_63 . V_123 ;
if ( F_75 ( V_127 , & V_128 , sizeof( struct V_126 ) ) )
return - V_139 ;
return 0 ;
}
static long F_76 ( struct V_1 * V_2 , struct V_126 T_2 * V_140 )
{
struct V_126 V_128 ;
F_13 ( ( L_48 , V_2 -> V_8 ) ) ;
if ( F_77 ( & V_128 , V_140 , sizeof( struct V_126 ) ) )
return - V_139 ;
F_78 ( & V_2 -> V_49 ) ;
if ( V_128 . V_64 == V_141 ) {
V_2 -> V_142 = V_128 . V_132 ;
} else {
V_2 -> V_63 . V_64 = V_128 . V_64 ;
V_2 -> V_63 . V_130 = V_128 . V_130 ;
V_2 -> V_63 . V_22 = V_128 . V_22 ;
V_2 -> V_63 . V_131 = V_128 . V_131 ;
V_2 -> V_63 . V_132 = V_128 . V_132 ;
V_2 -> V_63 . V_133 = V_128 . V_133 ;
V_2 -> V_63 . V_134 = V_128 . V_134 ;
V_2 -> V_63 . V_135 = V_128 . V_135 ;
V_2 -> V_63 . V_136 = V_128 . V_136 ;
V_2 -> V_63 . V_80 = V_128 . V_80 ;
V_2 -> V_63 . V_137 = V_128 . V_137 ;
V_2 -> V_63 . V_138 = V_128 . V_138 ;
V_2 -> V_63 . V_123 = V_128 . V_123 ;
}
F_79 ( & V_2 -> V_49 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static long F_81 ( struct V_20 * V_21 ,
unsigned int V_85 , unsigned long V_86 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_143 = - V_110 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_49 ) )
return - V_33 ;
F_13 ( ( L_50 , V_2 -> V_8 , V_85 ) ) ;
switch ( V_85 ) {
case V_144 :
V_143 = F_76 ( V_2 , F_82 ( V_86 ) ) ;
break;
case V_145 :
V_143 = F_74 ( V_2 , F_82 ( V_86 ) ) ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_107 :
case V_92 :
case V_108 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_98 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_90 :
case V_109 :
case V_97 :
case V_99 :
V_143 = F_53 ( V_21 , V_85 , V_86 ) ;
break;
}
F_13 ( ( L_51 , V_2 -> V_8 , V_85 , V_143 ) ) ;
return V_143 ;
}
static inline void F_83 ( struct V_146 * V_147 , struct V_1 * V_2 )
{
char V_148 [ 30 ] ;
unsigned long V_22 ;
F_84 ( V_147 , L_52 ,
V_2 -> V_8 , V_2 -> V_149 ,
V_2 -> V_150 , V_2 -> V_72 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_85 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_148 [ 0 ] = 0 ;
V_148 [ 1 ] = 0 ;
if ( V_2 -> V_57 & V_58 )
strcat ( V_148 , L_53 ) ;
if ( V_2 -> V_57 & V_151 )
strcat ( V_148 , L_54 ) ;
if ( V_2 -> V_57 & V_59 )
strcat ( V_148 , L_55 ) ;
if ( V_2 -> V_57 & V_152 )
strcat ( V_148 , L_56 ) ;
if ( V_2 -> V_57 & V_153 )
strcat ( V_148 , L_57 ) ;
if ( V_2 -> V_57 & V_154 )
strcat ( V_148 , L_58 ) ;
if ( V_2 -> V_63 . V_64 != V_84 ) {
F_84 ( V_147 , L_59 ,
V_2 -> V_112 . V_155 , V_2 -> V_112 . V_156 ) ;
if ( V_2 -> V_112 . V_157 )
F_84 ( V_147 , L_60 , V_2 -> V_112 . V_157 ) ;
if ( V_2 -> V_112 . V_158 )
F_84 ( V_147 , L_61 , V_2 -> V_112 . V_158 ) ;
if ( V_2 -> V_112 . V_159 )
F_84 ( V_147 , L_62 , V_2 -> V_112 . V_159 ) ;
if ( V_2 -> V_112 . V_160 )
F_84 ( V_147 , L_63 , V_2 -> V_112 . V_160 ) ;
if ( V_2 -> V_112 . V_161 )
F_84 ( V_147 , L_64 , V_2 -> V_112 . V_161 ) ;
if ( V_2 -> V_112 . V_162 )
F_84 ( V_147 , L_65 , V_2 -> V_112 . V_162 ) ;
} else {
F_84 ( V_147 , L_66 ,
V_2 -> V_112 . V_120 , V_2 -> V_112 . V_119 ) ;
if ( V_2 -> V_112 . V_121 )
F_84 ( V_147 , L_67 , V_2 -> V_112 . V_121 ) ;
if ( V_2 -> V_112 . V_123 )
F_84 ( V_147 , L_68 , V_2 -> V_112 . V_123 ) ;
if ( V_2 -> V_112 . V_124 )
F_84 ( V_147 , L_69 , V_2 -> V_112 . V_124 ) ;
if ( V_2 -> V_112 . V_122 )
F_84 ( V_147 , L_70 , V_2 -> V_112 . V_122 ) ;
}
F_84 ( V_147 , L_71 , V_148 + 1 ) ;
F_84 ( V_147 , L_72 ,
V_2 -> V_81 , V_2 -> V_163 , V_2 -> V_164 ,
V_2 -> V_165 ) ;
}
static int F_86 ( struct V_146 * V_147 , void * V_166 )
{
struct V_1 * V_2 ;
F_87 ( V_147 , L_73 ) ;
V_2 = V_34 ;
while( V_2 ) {
F_83 ( V_147 , V_2 ) ;
V_2 = V_2 -> V_35 ;
}
return 0 ;
}
static int F_88 ( struct V_167 * V_167 , struct V_27 * V_27 )
{
return F_89 ( V_27 , F_86 , NULL ) ;
}
static int F_90 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_4 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_74 ) )
return 0 ;
V_4 = F_35 ( V_2 ) ;
F_13 ( ( L_75 , V_2 -> V_8 , V_4 ) ) ;
return V_4 ;
}
static void F_91 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_76 ) )
return;
F_13 ( ( L_77 , V_2 -> V_8 ) ) ;
if ( F_92 ( V_21 ) )
F_41 ( V_21 , F_93 ( V_21 ) ) ;
if ( V_21 -> V_56 . V_54 & V_60 ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_57 &= ~ V_58 ;
F_31 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
}
static void F_94 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_78 ) )
return;
F_13 ( ( L_79 , V_2 -> V_8 ) ) ;
if ( F_92 ( V_21 ) ) {
if ( V_2 -> V_76 )
V_2 -> V_76 = 0 ;
else
F_41 ( V_21 , F_95 ( V_21 ) ) ;
}
if ( V_21 -> V_56 . V_54 & V_60 ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_57 |= V_58 ;
F_31 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
}
static int F_96 ( struct V_20 * V_21 , int V_168 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned short V_169 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_80 ) )
return - V_170 ;
F_13 ( ( L_81 , V_2 -> V_8 , V_168 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_169 = F_97 ( V_2 , V_171 ) ;
if ( V_168 == - 1 )
V_169 |= V_172 ;
else
V_169 &= ~ V_172 ;
F_98 ( V_2 , V_171 , V_169 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_99 ( struct V_173 * V_174 , unsigned short V_131 ,
unsigned short V_123 )
{
struct V_1 * V_2 = F_100 ( V_174 ) ;
unsigned char V_175 ;
unsigned short V_176 ;
if ( V_2 -> V_38 . V_4 )
return - V_44 ;
F_13 ( ( L_82 , V_2 -> V_8 ) ) ;
switch ( V_131 )
{
case V_177 : V_175 = V_178 ; break;
case V_179 : V_175 = V_180 ; break;
case V_181 : V_175 = V_182 ; break;
case V_183 : V_175 = V_184 ; break;
case V_185 : V_175 = V_186 ; break;
default: return - V_170 ;
}
switch ( V_123 )
{
case V_187 : V_176 = V_188 ; break;
case V_189 : V_176 = V_190 ; break;
case V_191 : V_176 = V_192 ; break;
default: return - V_170 ;
}
V_2 -> V_63 . V_131 = V_175 ;
V_2 -> V_63 . V_134 = V_176 ;
if ( V_2 -> V_43 )
F_80 ( V_2 ) ;
return 0 ;
}
static T_3 F_101 ( struct V_193 * V_194 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_100 ( V_174 ) ;
unsigned long V_22 ;
F_13 ( ( L_83 , V_174 -> V_17 ) ) ;
if ( ! V_194 -> V_195 )
return V_196 ;
F_102 ( V_174 ) ;
V_174 -> V_197 . V_198 ++ ;
V_174 -> V_197 . V_199 += V_194 -> V_195 ;
V_174 -> V_200 = V_67 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_39 ( V_2 , V_194 -> V_3 , V_194 -> V_195 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_103 ( V_194 ) ;
return V_196 ;
}
static int F_104 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = F_100 ( V_174 ) ;
int V_143 ;
unsigned long V_22 ;
if ( ! F_105 ( V_201 ) )
return - V_44 ;
F_13 ( ( L_84 , V_174 -> V_17 ) ) ;
V_143 = F_106 ( V_174 ) ;
if ( V_143 )
return V_143 ;
F_15 ( & V_2 -> V_42 , V_22 ) ;
if ( V_2 -> V_38 . V_4 != 0 || V_2 -> V_43 != 0 ) {
F_13 ( ( L_85 , V_174 -> V_17 ) ) ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
return - V_44 ;
}
V_2 -> V_43 = 1 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
if ( ( V_143 = F_18 ( V_2 ) ) != 0 ) {
F_15 ( & V_2 -> V_42 , V_22 ) ;
V_2 -> V_43 = 0 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
return V_143 ;
}
V_2 -> V_57 |= V_58 | V_59 ;
F_80 ( V_2 ) ;
V_174 -> V_200 = V_67 ;
F_107 ( V_174 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_85 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_57 & V_153 )
F_108 ( V_174 ) ;
else
F_109 ( V_174 ) ;
return 0 ;
}
static int F_110 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = F_100 ( V_174 ) ;
unsigned long V_22 ;
F_13 ( ( L_86 , V_174 -> V_17 ) ) ;
F_102 ( V_174 ) ;
F_25 ( V_2 ) ;
F_111 ( V_174 ) ;
F_15 ( & V_2 -> V_42 , V_22 ) ;
V_2 -> V_43 = 0 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
F_112 ( V_201 ) ;
return 0 ;
}
static int F_113 ( struct V_173 * V_174 , struct V_202 * V_203 , int V_85 )
{
const T_4 V_204 = sizeof( V_205 ) ;
V_205 V_206 ;
V_205 T_2 * line = V_203 -> V_207 . V_208 . V_209 ;
struct V_1 * V_2 = F_100 ( V_174 ) ;
unsigned int V_22 ;
F_13 ( ( L_87 , V_174 -> V_17 ) ) ;
if ( V_2 -> V_38 . V_4 )
return - V_44 ;
if ( V_85 != V_210 )
return F_114 ( V_174 , V_203 , V_85 ) ;
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
switch( V_203 -> V_207 . type ) {
case V_211 :
V_203 -> V_207 . type = V_212 ;
if ( V_203 -> V_207 . V_204 < V_204 ) {
V_203 -> V_207 . V_204 = V_204 ;
return - V_213 ;
}
V_22 = V_2 -> V_63 . V_22 & ( V_214 | V_215 |
V_216 | V_217 |
V_218 | V_219 |
V_220 | V_221 ) ;
switch ( V_22 ) {
case ( V_214 | V_218 ) : V_206 . V_222 = V_223 ; break;
case ( V_216 | V_220 ) : V_206 . V_222 = V_224 ; break;
case ( V_214 | V_220 ) : V_206 . V_222 = V_225 ; break;
case ( V_214 | V_221 ) : V_206 . V_222 = V_226 ; break;
default: V_206 . V_222 = V_227 ;
}
V_206 . V_228 = V_2 -> V_63 . V_132 ;
V_206 . V_130 = V_2 -> V_63 . V_130 ? 1 : 0 ;
if ( F_75 ( line , & V_206 , V_204 ) )
return - V_139 ;
return 0 ;
case V_212 :
if( ! F_115 ( V_229 ) )
return - V_230 ;
if ( F_77 ( & V_206 , line , V_204 ) )
return - V_139 ;
switch ( V_206 . V_222 )
{
case V_223 : V_22 = V_214 | V_218 ; break;
case V_226 : V_22 = V_214 | V_221 ; break;
case V_224 : V_22 = V_216 | V_220 ; break;
case V_225 : V_22 = V_214 | V_220 ; break;
case V_227 : V_22 = V_2 -> V_63 . V_22 &
( V_214 | V_215 |
V_216 | V_217 |
V_218 | V_219 |
V_220 | V_221 ) ; break;
default: return - V_170 ;
}
if ( V_206 . V_130 != 0 && V_206 . V_130 != 1 )
return - V_170 ;
V_2 -> V_63 . V_22 &= ~ ( V_214 | V_215 |
V_216 | V_217 |
V_218 | V_219 |
V_220 | V_221 ) ;
V_2 -> V_63 . V_22 |= V_22 ;
V_2 -> V_63 . V_130 = V_206 . V_130 ;
if ( V_22 & ( V_216 | V_220 ) )
V_2 -> V_63 . V_132 = V_206 . V_228 ;
else
V_2 -> V_63 . V_132 = 0 ;
if ( V_2 -> V_43 )
F_80 ( V_2 ) ;
return 0 ;
default:
return F_114 ( V_174 , V_203 , V_85 ) ;
}
}
static void F_116 ( struct V_173 * V_174 )
{
struct V_1 * V_2 = F_100 ( V_174 ) ;
unsigned long V_22 ;
F_13 ( ( L_88 , V_174 -> V_17 ) ) ;
V_174 -> V_197 . V_231 ++ ;
V_174 -> V_197 . V_232 ++ ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_52 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_117 ( V_174 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
if ( F_119 ( V_2 -> V_233 ) )
F_117 ( V_2 -> V_233 ) ;
}
static void F_120 ( struct V_1 * V_2 , char * V_68 , int V_204 )
{
struct V_193 * V_194 = F_121 ( V_204 ) ;
struct V_173 * V_174 = V_2 -> V_233 ;
F_13 ( ( L_89 , V_174 -> V_17 ) ) ;
if ( V_194 == NULL ) {
F_12 ( ( L_90 , V_174 -> V_17 ) ) ;
V_174 -> V_197 . V_234 ++ ;
return;
}
memcpy ( F_122 ( V_194 , V_204 ) , V_68 , V_204 ) ;
V_194 -> V_235 = F_123 ( V_194 , V_174 ) ;
V_174 -> V_197 . V_236 ++ ;
V_174 -> V_197 . V_237 += V_204 ;
F_124 ( V_194 ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
int V_143 ;
struct V_173 * V_174 ;
T_5 * V_238 ;
V_174 = F_126 ( V_2 ) ;
if ( ! V_174 ) {
F_2 ( V_239 L_91 , V_2 -> V_8 ) ;
return - V_240 ;
}
V_174 -> V_241 = V_2 -> V_149 ;
V_174 -> V_242 = V_2 -> V_149 + V_243 - 1 ;
V_174 -> V_244 = V_2 -> V_150 ;
V_174 -> V_245 = & V_246 ;
V_174 -> V_247 = 10 * V_248 ;
V_174 -> V_249 = 50 ;
V_238 = F_127 ( V_174 ) ;
V_238 -> V_250 = F_99 ;
V_238 -> V_251 = F_101 ;
V_143 = F_128 ( V_174 ) ;
if ( V_143 ) {
F_2 ( V_252 L_92 , __FILE__ ) ;
F_129 ( V_174 ) ;
return V_143 ;
}
V_2 -> V_233 = V_174 ;
return 0 ;
}
static void F_130 ( struct V_1 * V_2 )
{
F_131 ( V_2 -> V_233 ) ;
F_129 ( V_2 -> V_233 ) ;
V_2 -> V_233 = NULL ;
}
static void F_132 ( struct V_1 * V_2 )
{
struct V_113 * V_112 = & V_2 -> V_112 ;
unsigned int V_253 , V_254 ;
unsigned char * V_255 ;
unsigned char V_12 ;
struct V_256 * V_257 = V_2 -> V_15 ;
int V_6 , V_4 ;
int V_258 = 0 ;
int V_259 ;
unsigned char V_75 ;
V_253 = V_254 = V_2 -> V_13 ;
while( F_133 ( V_257 [ V_254 ] ) ) {
V_4 = F_134 ( V_257 [ V_254 ] ) - V_2 -> V_260 ;
V_255 = V_257 [ V_254 ] . V_68 + V_2 -> V_260 ;
F_135 ( ( L_93 , V_2 -> V_8 , V_4 ) ) ;
F_136 ( V_2 , V_255 , V_4 , L_94 ) ;
for( V_6 = 0 ; V_6 < V_4 ; V_6 += 2 , V_255 += 2 ) {
V_75 = * V_255 ;
V_112 -> V_119 ++ ;
V_259 = 0 ;
V_12 = * ( V_255 + 1 ) & ( V_261 + V_262 ) ;
if ( V_12 ) {
if ( V_12 & V_261 )
V_112 -> V_123 ++ ;
else if ( V_12 & V_262 )
V_112 -> V_121 ++ ;
if ( V_12 & V_2 -> V_263 )
continue;
if ( V_12 & V_261 )
V_259 = V_264 ;
else if ( V_12 & V_262 )
V_259 = V_265 ;
}
F_137 ( & V_2 -> V_38 , V_75 , V_259 ) ;
V_258 ++ ;
}
if ( V_6 < V_4 ) {
V_2 -> V_260 += V_6 ;
F_36 ( & V_2 -> V_266 , V_67 + 1 ) ;
break;
}
V_2 -> V_260 = 0 ;
F_138 ( V_2 , V_254 , V_254 ) ;
if ( ++ V_254 == V_2 -> V_14 )
V_254 = 0 ;
if ( V_254 == V_253 )
break;
}
if ( V_258 )
F_139 ( & V_2 -> V_38 ) ;
}
static int F_140 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
int V_143 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_165 & V_267 ) {
V_2 -> V_165 &= ~ V_267 ;
V_143 = V_267 ;
} else if ( V_2 -> V_165 & V_268 ) {
V_2 -> V_165 &= ~ V_268 ;
V_143 = V_268 ;
} else if ( V_2 -> V_165 & V_269 ) {
V_2 -> V_165 &= ~ V_269 ;
V_143 = V_269 ;
} else {
V_2 -> V_164 = false ;
V_2 -> V_163 = false ;
V_143 = 0 ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
return V_143 ;
}
static void F_141 ( struct V_270 * V_271 )
{
struct V_1 * V_2 = F_142 ( V_271 , struct V_1 , V_272 ) ;
int V_273 ;
V_2 -> V_164 = true ;
while( ( V_273 = F_140 ( V_2 ) ) ) {
switch ( V_273 ) {
case V_267 :
F_143 ( ( L_95 , V_2 -> V_8 ) ) ;
switch( V_2 -> V_63 . V_64 ) {
case V_84 :
F_132 ( V_2 ) ;
break;
case V_65 :
while( F_144 ( V_2 ) ) ;
break;
case V_274 :
case V_275 :
case V_276 :
case V_277 :
while( F_145 ( V_2 ) ) ;
break;
}
if ( V_2 -> V_278 )
F_146 ( V_2 ) ;
break;
case V_268 :
F_147 ( V_2 ) ;
break;
case V_269 :
F_143 ( ( L_96 , V_2 -> V_8 ) ) ;
V_2 -> V_279 = 0 ;
V_2 -> V_280 = 0 ;
V_2 -> V_281 = 0 ;
V_2 -> V_282 = 0 ;
break;
default:
F_143 ( ( L_97 , V_2 -> V_8 ) ) ;
break;
}
}
F_143 ( ( L_98 , V_2 -> V_8 ) ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_38 . V_21 ;
F_143 ( ( L_99 , V_2 -> V_8 ) ) ;
if ( V_21 )
F_50 ( V_21 ) ;
}
static void F_148 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_283 ) {
V_2 -> V_57 |= V_152 ;
V_2 -> V_284 . V_285 ++ ;
} else {
V_2 -> V_57 &= ~ V_152 ;
V_2 -> V_284 . V_286 ++ ;
}
F_135 ( ( L_100 , V_2 -> V_8 , V_2 -> V_57 ) ) ;
if ( ( V_2 -> V_280 ) ++ == V_287 ) {
F_149 ( V_2 , V_288 ) ;
return;
}
V_2 -> V_112 . V_116 ++ ;
F_28 ( & V_2 -> V_289 ) ;
F_28 ( & V_2 -> V_290 ) ;
V_2 -> V_165 |= V_269 ;
}
static void F_150 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_291 ) {
V_2 -> V_57 |= V_151 ;
V_2 -> V_284 . V_292 ++ ;
} else {
V_2 -> V_57 &= ~ V_151 ;
V_2 -> V_284 . V_293 ++ ;
}
F_135 ( ( L_101 , V_2 -> V_8 , V_2 -> V_57 ) ) ;
if ( ( V_2 -> V_282 ) ++ == V_287 ) {
F_149 ( V_2 , V_294 ) ;
return;
}
V_2 -> V_112 . V_115 ++ ;
F_28 ( & V_2 -> V_289 ) ;
F_28 ( & V_2 -> V_290 ) ;
V_2 -> V_165 |= V_269 ;
if ( F_151 ( & V_2 -> V_38 ) ) {
if ( V_2 -> V_38 . V_21 ) {
if ( V_2 -> V_38 . V_21 -> V_62 ) {
if ( V_2 -> V_57 & V_151 ) {
V_2 -> V_38 . V_21 -> V_62 = 0 ;
V_2 -> V_165 |= V_268 ;
return;
}
} else {
if ( ! ( V_2 -> V_57 & V_151 ) )
V_2 -> V_38 . V_21 -> V_62 = 1 ;
}
}
}
}
static void F_152 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_261 ) {
V_2 -> V_57 |= V_153 ;
V_2 -> V_284 . V_295 ++ ;
} else {
V_2 -> V_57 &= ~ V_153 ;
V_2 -> V_284 . V_296 ++ ;
}
F_135 ( ( L_102 , V_2 -> V_8 , V_2 -> V_57 ) ) ;
if ( ( V_2 -> V_281 ) ++ == V_287 ) {
F_149 ( V_2 , V_297 ) ;
return;
}
V_2 -> V_112 . V_118 ++ ;
#if V_298
if ( V_2 -> V_43 ) {
if ( V_2 -> V_57 & V_153 )
F_108 ( V_2 -> V_233 ) ;
else
F_109 ( V_2 -> V_233 ) ;
}
#endif
F_28 ( & V_2 -> V_289 ) ;
F_28 ( & V_2 -> V_290 ) ;
V_2 -> V_165 |= V_269 ;
if ( V_2 -> V_38 . V_22 & V_299 ) {
if ( V_2 -> V_57 & V_153 )
F_28 ( & V_2 -> V_38 . V_51 ) ;
else {
if ( V_2 -> V_38 . V_21 )
F_153 ( V_2 -> V_38 . V_21 ) ;
}
}
}
static void F_154 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_262 ) {
V_2 -> V_57 |= V_154 ;
V_2 -> V_284 . V_300 ++ ;
} else {
V_2 -> V_57 &= ~ V_154 ;
V_2 -> V_284 . V_301 ++ ;
}
F_135 ( ( L_103 , V_2 -> V_8 , V_2 -> V_57 ) ) ;
if ( ( V_2 -> V_279 ) ++ == V_287 ) {
F_149 ( V_2 , V_302 ) ;
return;
}
V_2 -> V_112 . V_117 ++ ;
F_28 ( & V_2 -> V_289 ) ;
F_28 ( & V_2 -> V_290 ) ;
V_2 -> V_165 |= V_269 ;
}
static void F_155 ( struct V_1 * V_2 )
{
unsigned int V_4 = V_2 -> V_303 ;
unsigned int V_6 = V_2 -> V_304 ;
unsigned short V_305 ;
while ( F_97 ( V_2 , V_306 ) & V_307 ) {
V_305 = F_97 ( V_2 , V_308 ) ;
F_135 ( ( L_104 , V_2 -> V_8 , V_305 ) ) ;
if ( F_133 ( V_2 -> V_15 [ V_6 ] ) ) {
F_156 ( V_2 ) ;
V_2 -> V_278 = 1 ;
continue;
}
V_2 -> V_15 [ V_6 ] . V_68 [ V_4 ++ ] = ( unsigned char ) V_305 ;
if ( V_2 -> V_63 . V_64 == V_84 )
V_2 -> V_15 [ V_6 ] . V_68 [ V_4 ++ ] = ( unsigned char ) ( V_305 >> 8 ) ;
if ( V_4 == V_2 -> V_309 || ( V_305 & V_310 ) ) {
F_157 ( V_2 -> V_15 [ V_6 ] , V_4 ) ;
F_158 ( V_2 -> V_15 [ V_6 ] , V_311 | ( V_305 >> 8 ) ) ;
V_2 -> V_303 = V_4 = 0 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
V_2 -> V_165 |= V_267 ;
}
}
V_2 -> V_304 = V_6 ;
V_2 -> V_303 = V_4 ;
}
static void F_159 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_97 ( V_2 , V_306 ) ;
F_135 ( ( L_105 , V_2 -> V_8 , V_12 ) ) ;
F_98 ( V_2 , V_306 , V_12 ) ;
V_2 -> V_312 = true ;
if ( V_2 -> V_63 . V_64 == V_84 ) {
if ( V_12 & V_313 ) {
if ( V_2 -> V_81 )
F_160 ( V_2 , V_12 ) ;
}
if ( V_2 -> V_314 && ( V_12 & V_307 ) )
F_155 ( V_2 ) ;
if ( ( V_12 & V_315 ) && ( V_12 & V_316 ) ) {
V_2 -> V_112 . V_124 ++ ;
if ( V_2 -> V_38 . V_21 ) {
if ( ! ( V_12 & V_2 -> V_263 ) ) {
if ( V_2 -> V_317 & V_318 ) {
F_137 ( & V_2 -> V_38 , 0 , V_319 ) ;
if ( V_2 -> V_38 . V_22 & V_320 )
F_161 ( V_2 -> V_38 . V_21 ) ;
}
}
}
}
} else {
if ( V_12 & ( V_313 + V_321 ) )
F_160 ( V_2 , V_12 ) ;
if ( V_2 -> V_314 && ( V_12 & V_307 ) )
F_155 ( V_2 ) ;
if ( V_12 & V_322 ) {
if ( V_12 & V_323 )
V_2 -> V_112 . V_324 ++ ;
else
V_2 -> V_112 . V_325 ++ ;
F_28 ( & V_2 -> V_290 ) ;
}
if ( V_12 & V_326 )
F_146 ( V_2 ) ;
}
if ( V_12 & V_288 )
F_148 ( V_2 , V_12 ) ;
if ( V_12 & V_294 )
F_150 ( V_2 , V_12 ) ;
if ( V_12 & V_297 )
F_152 ( V_2 , V_12 ) ;
if ( V_12 & V_302 )
F_154 ( V_2 , V_12 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_163 ( V_2 , V_327 ) ;
F_135 ( ( L_106 , V_2 -> V_8 , V_12 ) ) ;
F_164 ( V_2 , V_327 , V_12 ) ;
if ( V_12 & ( V_328 + V_329 ) ) {
F_135 ( ( L_107 , V_2 -> V_8 ) ) ;
V_2 -> V_278 = true ;
}
V_2 -> V_165 |= V_267 ;
}
static void F_165 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_163 ( V_2 , V_330 ) ;
F_135 ( ( L_108 , V_2 -> V_8 , V_12 ) ) ;
F_164 ( V_2 , V_330 , V_12 ) ;
if ( V_12 & ( V_328 + V_329 + V_283 ) ) {
V_2 -> V_165 |= V_268 ;
}
}
static bool F_166 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_2 -> V_9 ;
bool V_143 = false ;
do {
if ( V_6 )
V_6 -- ;
else
V_6 = V_2 -> V_10 - 1 ;
if ( ! F_134 ( V_2 -> V_11 [ V_6 ] ) )
break;
V_2 -> V_331 = V_6 ;
V_143 = true ;
} while ( V_6 != V_2 -> V_9 );
return V_143 ;
}
static void F_160 ( struct V_1 * V_2 , unsigned short V_12 )
{
F_135 ( ( L_109 , V_2 -> V_8 , V_12 ) ) ;
F_149 ( V_2 , V_332 + V_313 + V_321 ) ;
F_167 ( V_2 ) ;
if ( V_12 & V_321 ) {
unsigned short V_333 = F_97 ( V_2 , V_171 ) ;
F_98 ( V_2 , V_171 , ( unsigned short ) ( V_333 | V_291 ) ) ;
F_98 ( V_2 , V_171 , V_333 ) ;
}
if ( V_2 -> V_81 ) {
if ( V_2 -> V_63 . V_64 != V_84 ) {
if ( V_12 & V_321 )
V_2 -> V_112 . V_157 ++ ;
else if ( V_12 & V_313 )
V_2 -> V_112 . V_155 ++ ;
}
if ( F_166 ( V_2 ) ) {
F_42 ( V_2 ) ;
F_34 ( V_2 ) ;
return;
}
V_2 -> V_81 = false ;
F_168 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_63 . V_64 != V_84 && V_2 -> V_334 ) {
V_2 -> V_57 &= ~ V_58 ;
V_2 -> V_334 = false ;
F_31 ( V_2 ) ;
}
#if V_298
if ( V_2 -> V_43 )
F_118 ( V_2 ) ;
else
#endif
{
if ( V_2 -> V_38 . V_21 && ( V_2 -> V_38 . V_21 -> V_73 || V_2 -> V_38 . V_21 -> V_62 ) ) {
F_52 ( V_2 ) ;
return;
}
V_2 -> V_165 |= V_268 ;
}
}
}
static void F_169 ( struct V_1 * V_2 , unsigned int V_335 , unsigned int V_336 )
{
struct V_337 * V_338 , * V_339 ;
for ( V_338 = V_2 -> V_340 , V_339 = NULL ; V_338 != NULL ; V_338 = V_338 -> V_341 ) {
if ( V_338 -> V_3 & V_335 ) {
V_338 -> V_3 = V_336 ;
F_28 ( & V_338 -> V_342 ) ;
if ( V_339 != NULL )
V_339 -> V_341 = V_338 -> V_341 ;
else
V_2 -> V_340 = V_338 -> V_341 ;
} else
V_339 = V_338 ;
}
}
static T_6 F_170 ( int V_343 , void * V_344 )
{
struct V_1 * V_2 = V_344 ;
unsigned int V_345 ;
unsigned int V_6 ;
F_135 ( ( L_110 , V_2 -> V_150 ) ) ;
while( ( V_345 = F_163 ( V_2 , V_346 ) & 0xffffff00 ) ) {
F_135 ( ( L_111 , V_2 -> V_8 , V_345 ) ) ;
V_2 -> V_312 = true ;
for( V_6 = 0 ; V_6 < V_2 -> V_347 ; V_6 ++ ) {
if ( V_2 -> V_348 [ V_6 ] == NULL )
continue;
F_78 ( & V_2 -> V_348 [ V_6 ] -> V_49 ) ;
if ( V_345 & ( V_349 << V_6 ) )
F_159 ( V_2 -> V_348 [ V_6 ] ) ;
if ( V_345 & ( V_350 << ( V_6 * 2 ) ) )
F_162 ( V_2 -> V_348 [ V_6 ] ) ;
if ( V_345 & ( V_351 << ( V_6 * 2 ) ) )
F_165 ( V_2 -> V_348 [ V_6 ] ) ;
F_79 ( & V_2 -> V_348 [ V_6 ] -> V_49 ) ;
}
}
if ( V_2 -> V_352 ) {
unsigned int V_336 ;
unsigned int V_335 ;
F_78 ( & V_2 -> V_49 ) ;
while ( ( V_335 = F_163 ( V_2 , V_353 ) ) != 0 ) {
F_135 ( ( L_112 , V_2 -> V_8 , V_335 ) ) ;
V_336 = F_163 ( V_2 , V_354 ) ;
F_164 ( V_2 , V_353 , V_335 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_347 ; V_6 ++ ) {
if ( V_2 -> V_348 [ V_6 ] != NULL )
F_169 ( V_2 -> V_348 [ V_6 ] , V_335 , V_336 ) ;
}
}
F_79 ( & V_2 -> V_49 ) ;
}
for( V_6 = 0 ; V_6 < V_2 -> V_347 ; V_6 ++ ) {
struct V_1 * V_38 = V_2 -> V_348 [ V_6 ] ;
if ( V_38 == NULL )
continue;
F_78 ( & V_38 -> V_49 ) ;
if ( ( V_38 -> V_38 . V_4 || V_38 -> V_43 ) &&
V_38 -> V_165 && ! V_38 -> V_164 &&
! V_38 -> V_163 ) {
F_135 ( ( L_113 , V_38 -> V_8 ) ) ;
F_171 ( & V_38 -> V_272 ) ;
V_38 -> V_163 = true ;
}
F_79 ( & V_38 -> V_49 ) ;
}
F_135 ( ( L_114 , V_2 -> V_150 ) ) ;
return V_355 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_13 ( ( L_115 , V_2 -> V_8 ) ) ;
if ( V_2 -> V_38 . V_22 & V_46 )
return 0 ;
if ( ! V_2 -> V_71 ) {
V_2 -> V_71 = F_172 ( V_2 -> V_72 , V_356 ) ;
if ( ! V_2 -> V_71 ) {
F_12 ( ( L_116 , V_2 -> V_8 ) ) ;
return - V_240 ;
}
}
V_2 -> V_165 = 0 ;
memset ( & V_2 -> V_112 , 0 , sizeof( V_2 -> V_112 ) ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_38 . V_21 )
F_173 ( V_91 , & V_2 -> V_38 . V_21 -> V_22 ) ;
V_2 -> V_38 . V_22 |= V_46 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
if ( ! ( V_2 -> V_38 . V_22 & V_46 ) )
return;
F_13 ( ( L_117 , V_2 -> V_8 ) ) ;
F_28 ( & V_2 -> V_289 ) ;
F_28 ( & V_2 -> V_290 ) ;
F_174 ( & V_2 -> V_66 ) ;
F_174 ( & V_2 -> V_266 ) ;
F_175 ( V_2 -> V_71 ) ;
V_2 -> V_71 = NULL ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_52 ( V_2 ) ;
F_156 ( V_2 ) ;
F_149 ( V_2 , V_357 | V_358 ) ;
if ( ! V_2 -> V_38 . V_21 || V_2 -> V_38 . V_21 -> V_56 . V_54 & V_359 ) {
V_2 -> V_57 &= ~ ( V_58 | V_59 ) ;
F_31 ( V_2 ) ;
}
F_176 ( & V_2 -> V_340 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_38 . V_21 )
F_177 ( V_91 , & V_2 -> V_38 . V_21 -> V_22 ) ;
V_2 -> V_38 . V_22 &= ~ V_46 ;
}
static void F_80 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_156 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> V_63 . V_64 != V_84 ||
V_2 -> V_43 )
F_178 ( V_2 ) ;
else
F_179 ( V_2 ) ;
F_31 ( V_2 ) ;
V_2 -> V_281 = 0 ;
V_2 -> V_282 = 0 ;
V_2 -> V_279 = 0 ;
V_2 -> V_280 = 0 ;
F_180 ( V_2 , V_297 | V_294 | V_288 | V_302 ) ;
F_85 ( V_2 ) ;
if ( V_2 -> V_43 ||
( V_2 -> V_38 . V_21 && V_2 -> V_38 . V_21 -> V_56 . V_54 & V_360 ) )
F_146 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned V_361 ;
int V_362 ;
if ( ! V_2 -> V_38 . V_21 )
return;
F_13 ( ( L_118 , V_2 -> V_8 ) ) ;
V_361 = V_2 -> V_38 . V_21 -> V_56 . V_54 ;
if ( V_361 & V_55 )
V_2 -> V_57 |= V_58 | V_59 ;
else
V_2 -> V_57 &= ~ ( V_58 | V_59 ) ;
switch ( V_361 & V_363 ) {
case V_364 : V_2 -> V_63 . V_137 = 5 ; break;
case V_365 : V_2 -> V_63 . V_137 = 6 ; break;
case V_366 : V_2 -> V_63 . V_137 = 7 ; break;
case V_367 : V_2 -> V_63 . V_137 = 8 ; break;
default: V_2 -> V_63 . V_137 = 7 ; break;
}
V_2 -> V_63 . V_138 = ( V_361 & V_368 ) ? 2 : 1 ;
if ( V_361 & V_369 )
V_2 -> V_63 . V_123 = ( V_361 & V_370 ) ? V_371 : V_372 ;
else
V_2 -> V_63 . V_123 = V_373 ;
V_362 = V_2 -> V_63 . V_137 +
V_2 -> V_63 . V_138 + 1 ;
V_2 -> V_63 . V_80 = F_181 ( V_2 -> V_38 . V_21 ) ;
if ( V_2 -> V_63 . V_80 ) {
V_2 -> V_47 = ( 32 * V_248 * V_362 ) /
V_2 -> V_63 . V_80 ;
}
V_2 -> V_47 += V_248 / 50 ;
if ( V_361 & V_60 )
V_2 -> V_38 . V_22 |= V_374 ;
else
V_2 -> V_38 . V_22 &= ~ V_374 ;
if ( V_361 & V_375 )
V_2 -> V_38 . V_22 &= ~ V_299 ;
else
V_2 -> V_38 . V_22 |= V_299 ;
V_2 -> V_317 = V_326 ;
if ( F_182 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_317 |= V_376 | V_377 ;
if ( F_183 ( V_2 -> V_38 . V_21 ) || F_184 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_317 |= V_318 ;
if ( F_185 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_263 |= V_376 | V_377 ;
if ( F_186 ( V_2 -> V_38 . V_21 ) ) {
V_2 -> V_263 |= V_318 ;
if ( F_185 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_263 |= V_378 ;
}
F_80 ( V_2 ) ;
}
static int F_70 ( struct V_1 * V_2 , struct V_113 T_2 * V_379 )
{
F_13 ( ( L_119 , V_2 -> V_8 ) ) ;
if ( ! V_379 ) {
memset ( & V_2 -> V_112 , 0 , sizeof( V_2 -> V_112 ) ) ;
} else {
if ( F_75 ( V_379 , & V_2 -> V_112 , sizeof( struct V_113 ) ) )
return - V_139 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , T_7 T_2 * V_127 )
{
F_13 ( ( L_120 , V_2 -> V_8 ) ) ;
if ( F_75 ( V_127 , & V_2 -> V_63 , sizeof( T_7 ) ) )
return - V_139 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , T_7 T_2 * V_140 )
{
unsigned long V_22 ;
T_7 V_128 ;
F_13 ( ( L_121 , V_2 -> V_8 ) ) ;
if ( F_77 ( & V_128 , V_140 , sizeof( T_7 ) ) )
return - V_139 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_128 . V_64 == V_141 )
V_2 -> V_142 = V_128 . V_132 ;
else
memcpy ( & V_2 -> V_63 , & V_128 , sizeof( T_7 ) ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , int T_2 * V_380 )
{
F_13 ( ( L_122 , V_2 -> V_8 , V_2 -> V_380 ) ) ;
if ( F_187 ( V_2 -> V_380 , V_380 ) )
return - V_139 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , int V_380 )
{
unsigned long V_22 ;
F_13 ( ( L_123 , V_2 -> V_8 , V_380 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_380 = V_380 ;
if ( V_2 -> V_63 . V_64 != V_84 )
F_188 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , int V_381 )
{
unsigned long V_22 ;
F_13 ( ( L_124 , V_2 -> V_8 , V_381 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_381 ) {
if ( ! V_2 -> V_77 )
F_42 ( V_2 ) ;
} else {
if ( V_2 -> V_77 )
F_52 ( V_2 ) ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_13 ( ( L_125 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_167 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_381 )
{
unsigned long V_22 ;
unsigned int V_309 ;
F_13 ( ( L_126 , V_2 -> V_8 , V_381 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_309 = ( ( unsigned int ) V_381 ) >> 16 ;
if ( V_309 ) {
if ( ( V_309 > V_382 ) || ( V_309 % 4 ) ) {
F_16 ( & V_2 -> V_49 , V_22 ) ;
return - V_170 ;
}
V_2 -> V_309 = V_309 ;
if ( V_309 < 128 )
V_2 -> V_314 = 1 ;
else
V_2 -> V_314 = 0 ;
F_156 ( V_2 ) ;
}
V_381 &= 3 ;
if ( V_381 ) {
if ( ! V_2 -> V_383 )
F_146 ( V_2 ) ;
else if ( V_381 == 2 ) {
F_98 ( V_2 , V_384 , F_97 ( V_2 , V_384 ) | V_283 ) ;
}
} else {
if ( V_2 -> V_383 )
F_156 ( V_2 ) ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , int T_2 * V_385 )
{
unsigned long V_22 ;
int V_386 ;
int V_143 = 0 ;
struct V_113 V_387 , V_114 ;
int V_388 ;
int V_389 ;
struct V_390 V_391 , V_392 ;
F_189 ( V_393 , V_82 ) ;
if ( F_190 ( V_389 , V_385 ) )
return - V_139 ;
F_13 ( ( L_127 , V_2 -> V_8 , V_389 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_85 ( V_2 ) ;
V_386 = V_2 -> V_57 ;
V_388 = V_389 &
( ( ( V_386 & V_152 ) ? V_394 : V_395 ) +
( ( V_386 & V_153 ) ? V_396 : V_397 ) +
( ( V_386 & V_151 ) ? V_398 : V_399 ) +
( ( V_386 & V_154 ) ? V_400 : V_401 ) ) ;
if ( V_388 ) {
F_16 ( & V_2 -> V_49 , V_22 ) ;
goto exit;
}
V_387 = V_2 -> V_112 ;
V_391 = V_2 -> V_284 ;
if ( V_389 & ( V_402 + V_403 ) ) {
unsigned short V_333 = F_97 ( V_2 , V_404 ) ;
if ( ! ( V_333 & V_322 ) )
F_98 ( V_2 , V_404 , ( unsigned short ) ( V_333 | V_322 ) ) ;
}
F_191 ( V_405 ) ;
F_192 ( & V_2 -> V_290 , & V_393 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
for(; ; ) {
F_193 () ;
if ( F_46 ( V_82 ) ) {
V_143 = - V_406 ;
break;
}
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_114 = V_2 -> V_112 ;
V_392 = V_2 -> V_284 ;
F_191 ( V_405 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
if ( V_392 . V_285 == V_391 . V_285 &&
V_392 . V_286 == V_391 . V_286 &&
V_392 . V_295 == V_391 . V_295 &&
V_392 . V_296 == V_391 . V_296 &&
V_392 . V_292 == V_391 . V_292 &&
V_392 . V_293 == V_391 . V_293 &&
V_392 . V_300 == V_391 . V_300 &&
V_392 . V_301 == V_391 . V_301 &&
V_114 . V_325 == V_387 . V_325 &&
V_114 . V_324 == V_387 . V_324 ) {
V_143 = - V_70 ;
break;
}
V_388 = V_389 &
( ( V_392 . V_285 != V_391 . V_285 ? V_394 : 0 ) +
( V_392 . V_286 != V_391 . V_286 ? V_395 : 0 ) +
( V_392 . V_295 != V_391 . V_295 ? V_396 : 0 ) +
( V_392 . V_296 != V_391 . V_296 ? V_397 : 0 ) +
( V_392 . V_292 != V_391 . V_292 ? V_398 : 0 ) +
( V_392 . V_293 != V_391 . V_293 ? V_399 : 0 ) +
( V_392 . V_300 != V_391 . V_300 ? V_400 : 0 ) +
( V_392 . V_301 != V_391 . V_301 ? V_401 : 0 ) +
( V_114 . V_325 != V_387 . V_325 ? V_402 : 0 ) +
( V_114 . V_324 != V_387 . V_324 ? V_403 : 0 ) ) ;
if ( V_388 )
break;
V_387 = V_114 ;
V_391 = V_392 ;
}
F_194 ( & V_2 -> V_290 , & V_393 ) ;
F_191 ( V_407 ) ;
if ( V_389 & ( V_402 + V_403 ) ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( ! F_195 ( & V_2 -> V_290 ) ) {
F_98 ( V_2 , V_404 ,
( unsigned short ) ( F_97 ( V_2 , V_404 ) & ~ V_322 ) ) ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
exit:
if ( V_143 == 0 )
V_143 = F_187 ( V_388 , V_385 ) ;
return V_143 ;
}
static int F_71 ( struct V_1 * V_2 , int T_2 * V_408 )
{
F_13 ( ( L_128 , V_2 -> V_8 , V_2 -> V_408 ) ) ;
if ( F_187 ( V_2 -> V_408 , V_408 ) )
return - V_139 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , int V_408 )
{
unsigned long V_22 ;
unsigned short V_333 ;
F_13 ( ( L_129 , V_2 -> V_8 , V_408 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_408 = V_408 ;
F_196 ( V_2 ) ;
V_333 = F_97 ( V_2 , V_171 ) ;
if ( V_2 -> V_408 & V_409 )
V_333 |= V_410 ;
else
V_333 &= ~ V_410 ;
F_98 ( V_2 , V_171 , V_333 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int T_2 * V_411 )
{
F_13 ( ( L_130 , V_2 -> V_8 , V_2 -> V_411 ) ) ;
if ( F_187 ( V_2 -> V_411 , V_411 ) )
return - V_139 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_411 )
{
unsigned long V_22 ;
F_13 ( ( L_131 , V_2 -> V_8 , V_411 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_411 = V_411 ;
F_164 ( V_2 , V_412 , V_411 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , int T_2 * V_413 )
{
F_13 ( ( L_132 , V_2 -> V_8 , V_2 -> V_413 ) ) ;
if ( F_187 ( V_2 -> V_413 , V_413 ) )
return - V_139 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_413 )
{
unsigned long V_22 ;
F_13 ( ( L_133 , V_2 -> V_8 , V_413 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_413 = V_413 ;
F_164 ( V_2 , V_414 , V_413 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_415 T_2 * V_416 )
{
unsigned long V_22 ;
struct V_415 V_417 ;
T_8 V_3 ;
if ( ! V_2 -> V_352 )
return - V_170 ;
if ( F_77 ( & V_417 , V_416 , sizeof( V_417 ) ) )
return - V_139 ;
F_13 ( ( L_134 ,
V_2 -> V_8 , V_417 . V_336 , V_417 . V_418 ,
V_417 . V_419 , V_417 . V_420 ) ) ;
F_15 ( & V_2 -> V_348 [ 0 ] -> V_49 , V_22 ) ;
if ( V_417 . V_420 ) {
V_3 = F_163 ( V_2 , V_421 ) ;
V_3 |= V_417 . V_420 & V_417 . V_419 ;
V_3 &= ~ ( V_417 . V_420 & ~ V_417 . V_419 ) ;
F_164 ( V_2 , V_421 , V_3 ) ;
}
if ( V_417 . V_418 ) {
V_3 = F_163 ( V_2 , V_354 ) ;
V_3 |= V_417 . V_418 & V_417 . V_336 ;
V_3 &= ~ ( V_417 . V_418 & ~ V_417 . V_336 ) ;
F_164 ( V_2 , V_354 , V_3 ) ;
}
F_16 ( & V_2 -> V_348 [ 0 ] -> V_49 , V_22 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_415 T_2 * V_416 )
{
struct V_415 V_417 ;
if ( ! V_2 -> V_352 )
return - V_170 ;
V_417 . V_336 = F_163 ( V_2 , V_354 ) ;
V_417 . V_418 = 0xffffffff ;
V_417 . V_419 = F_163 ( V_2 , V_421 ) ;
V_417 . V_420 = 0xffffffff ;
if ( F_75 ( V_416 , & V_417 , sizeof( V_417 ) ) )
return - V_139 ;
F_13 ( ( L_135 ,
V_2 -> V_8 , V_417 . V_336 , V_417 . V_419 ) ) ;
return 0 ;
}
static void F_197 ( struct V_337 * V_338 , unsigned int V_3 )
{
F_198 ( & V_338 -> V_342 ) ;
F_199 ( & V_338 -> V_393 , V_82 ) ;
V_338 -> V_3 = V_3 ;
}
static void F_200 ( struct V_337 * * V_422 , struct V_337 * V_338 )
{
F_191 ( V_405 ) ;
F_192 ( & V_338 -> V_342 , & V_338 -> V_393 ) ;
V_338 -> V_341 = * V_422 ;
* V_422 = V_338 ;
}
static void F_201 ( struct V_337 * * V_422 , struct V_337 * V_423 )
{
struct V_337 * V_338 , * V_339 ;
F_194 ( & V_423 -> V_342 , & V_423 -> V_393 ) ;
F_191 ( V_407 ) ;
for ( V_338 = * V_422 , V_339 = NULL ; V_338 != NULL ; V_339 = V_338 , V_338 = V_338 -> V_341 ) {
if ( V_338 == V_423 ) {
if ( V_339 != NULL )
V_339 -> V_341 = V_338 -> V_341 ;
else
* V_422 = V_338 -> V_341 ;
break;
}
}
}
static void F_176 ( struct V_337 * * V_422 )
{
while ( * V_422 != NULL ) {
F_28 ( & ( * V_422 ) -> V_342 ) ;
* V_422 = ( * V_422 ) -> V_341 ;
}
}
static int F_58 ( struct V_1 * V_2 , struct V_415 T_2 * V_416 )
{
unsigned long V_22 ;
int V_143 = 0 ;
struct V_415 V_417 ;
struct V_337 V_393 ;
T_9 V_336 ;
if ( ! V_2 -> V_352 )
return - V_170 ;
if ( F_77 ( & V_417 , V_416 , sizeof( V_417 ) ) )
return - V_139 ;
F_13 ( ( L_136 ,
V_2 -> V_8 , V_417 . V_336 , V_417 . V_418 ) ) ;
if ( ( V_417 . V_418 &= ~ F_163 ( V_2 , V_421 ) ) == 0 )
return - V_170 ;
F_197 ( & V_393 , V_417 . V_418 ) ;
F_15 ( & V_2 -> V_348 [ 0 ] -> V_49 , V_22 ) ;
F_164 ( V_2 , V_424 , F_163 ( V_2 , V_424 ) | V_417 . V_418 ) ;
V_336 = F_163 ( V_2 , V_354 ) ;
if ( V_417 . V_418 & ~ ( V_336 ^ V_417 . V_336 ) ) {
V_417 . V_336 = V_336 ;
} else {
F_200 ( & V_2 -> V_340 , & V_393 ) ;
F_16 ( & V_2 -> V_348 [ 0 ] -> V_49 , V_22 ) ;
F_193 () ;
if ( F_46 ( V_82 ) )
V_143 = - V_406 ;
else
V_417 . V_336 = V_393 . V_3 ;
F_15 ( & V_2 -> V_348 [ 0 ] -> V_49 , V_22 ) ;
F_201 ( & V_2 -> V_340 , & V_393 ) ;
}
if ( V_2 -> V_340 == NULL )
F_164 ( V_2 , V_424 , 0 ) ;
F_16 ( & V_2 -> V_348 [ 0 ] -> V_49 , V_22 ) ;
if ( ( V_143 == 0 ) && F_75 ( V_416 , & V_417 , sizeof( V_417 ) ) )
V_143 = - V_139 ;
return V_143 ;
}
static int F_55 ( struct V_1 * V_2 , int V_86 )
{
unsigned long V_22 ;
int V_143 ;
struct V_113 V_387 , V_114 ;
F_189 ( V_393 , V_82 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_387 = V_2 -> V_112 ;
F_192 ( & V_2 -> V_289 , & V_393 ) ;
F_191 ( V_405 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
for(; ; ) {
F_193 () ;
if ( F_46 ( V_82 ) ) {
V_143 = - V_406 ;
break;
}
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_114 = V_2 -> V_112 ;
F_191 ( V_405 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
if ( V_114 . V_117 == V_387 . V_117 && V_114 . V_116 == V_387 . V_116 &&
V_114 . V_118 == V_387 . V_118 && V_114 . V_115 == V_387 . V_115 ) {
V_143 = - V_70 ;
break;
}
if ( ( V_86 & V_425 && V_114 . V_117 != V_387 . V_117 ) ||
( V_86 & V_426 && V_114 . V_116 != V_387 . V_116 ) ||
( V_86 & V_427 && V_114 . V_118 != V_387 . V_118 ) ||
( V_86 & V_428 && V_114 . V_115 != V_387 . V_115 ) ) {
V_143 = 0 ;
break;
}
V_387 = V_114 ;
}
F_194 ( & V_2 -> V_289 , & V_393 ) ;
F_191 ( V_407 ) ;
return V_143 ;
}
static int F_202 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned int V_429 ;
unsigned long V_22 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_85 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_429 = ( ( V_2 -> V_57 & V_58 ) ? V_430 : 0 ) +
( ( V_2 -> V_57 & V_59 ) ? V_431 : 0 ) +
( ( V_2 -> V_57 & V_153 ) ? V_432 : 0 ) +
( ( V_2 -> V_57 & V_154 ) ? V_425 : 0 ) +
( ( V_2 -> V_57 & V_152 ) ? V_426 : 0 ) +
( ( V_2 -> V_57 & V_151 ) ? V_428 : 0 ) ;
F_13 ( ( L_137 , V_2 -> V_8 , V_429 ) ) ;
return V_429 ;
}
static int F_203 ( struct V_20 * V_21 ,
unsigned int V_433 , unsigned int V_434 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
F_13 ( ( L_138 , V_2 -> V_8 , V_433 , V_434 ) ) ;
if ( V_433 & V_430 )
V_2 -> V_57 |= V_58 ;
if ( V_433 & V_431 )
V_2 -> V_57 |= V_59 ;
if ( V_434 & V_430 )
V_2 -> V_57 &= ~ V_58 ;
if ( V_434 & V_431 )
V_2 -> V_57 &= ~ V_59 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_31 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_204 ( struct V_435 * V_38 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_142 ( V_38 , struct V_1 , V_38 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_85 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return ( V_2 -> V_57 & V_153 ) ? 1 : 0 ;
}
static void F_205 ( struct V_435 * V_38 , int V_436 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_142 ( V_38 , struct V_1 , V_38 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_436 )
V_2 -> V_57 |= V_58 | V_59 ;
else
V_2 -> V_57 &= ~ ( V_58 | V_59 ) ;
F_31 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
static int F_19 ( struct V_20 * V_21 , struct V_27 * V_28 ,
struct V_1 * V_2 )
{
F_189 ( V_393 , V_82 ) ;
int V_29 ;
bool V_437 = false ;
unsigned long V_22 ;
int V_438 ;
struct V_435 * V_38 = & V_2 -> V_38 ;
F_13 ( ( L_139 , V_21 -> V_48 -> V_17 ) ) ;
if ( V_28 -> V_439 & V_440 || V_21 -> V_22 & ( 1 << V_91 ) ) {
V_38 -> V_22 |= V_50 ;
return 0 ;
}
if ( V_21 -> V_56 . V_54 & V_375 )
V_437 = true ;
V_29 = 0 ;
F_192 ( & V_38 -> V_51 , & V_393 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_38 -> V_4 -- ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_38 -> V_441 ++ ;
while ( 1 ) {
if ( F_206 ( V_21 ) && F_32 ( V_442 , & V_38 -> V_22 ) )
F_207 ( V_38 ) ;
F_191 ( V_405 ) ;
if ( F_208 ( V_28 ) || ! ( V_38 -> V_22 & V_46 ) ) {
V_29 = ( V_38 -> V_22 & V_443 ) ?
- V_444 : - V_406 ;
break;
}
V_438 = F_209 ( V_38 ) ;
if ( V_437 || V_438 )
break;
if ( F_46 ( V_82 ) ) {
V_29 = - V_406 ;
break;
}
F_13 ( ( L_140 , V_21 -> V_48 -> V_17 ) ) ;
F_210 ( V_21 ) ;
F_193 () ;
F_211 ( V_21 ) ;
}
F_191 ( V_407 ) ;
F_194 ( & V_38 -> V_51 , & V_393 ) ;
if ( ! F_208 ( V_28 ) )
V_38 -> V_4 ++ ;
V_38 -> V_441 -- ;
if ( ! V_29 )
V_38 -> V_22 |= V_50 ;
F_13 ( ( L_141 , V_21 -> V_48 -> V_17 , V_29 ) ) ;
return V_29 ;
}
static int F_212 ( struct V_1 * V_2 )
{
V_2 -> V_445 = F_172 ( V_2 -> V_72 + 5 , V_356 ) ;
if ( V_2 -> V_445 == NULL )
return - V_240 ;
V_2 -> V_446 = F_213 ( V_2 -> V_72 + 5 , V_356 ) ;
if ( ! V_2 -> V_446 ) {
F_175 ( V_2 -> V_445 ) ;
V_2 -> V_445 = NULL ;
return - V_240 ;
}
return 0 ;
}
static void F_214 ( struct V_1 * V_2 )
{
F_175 ( V_2 -> V_445 ) ;
V_2 -> V_445 = NULL ;
F_175 ( V_2 -> V_446 ) ;
V_2 -> V_446 = NULL ;
}
static int F_215 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
unsigned int V_447 ;
V_2 -> V_257 = F_216 ( V_2 -> V_448 , V_449 ,
& V_2 -> V_450 ) ;
if ( V_2 -> V_257 == NULL )
return - V_240 ;
V_2 -> V_15 = (struct V_256 * ) V_2 -> V_257 ;
V_2 -> V_11 = ( (struct V_256 * ) V_2 -> V_257 ) + V_2 -> V_14 ;
V_447 = ( unsigned int ) V_2 -> V_450 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_14 ; V_6 ++ ) {
V_2 -> V_15 [ V_6 ] . V_451 = V_447 + ( V_6 * sizeof( struct V_256 ) ) ;
if ( V_6 == V_2 -> V_14 - 1 )
V_2 -> V_15 [ V_6 ] . V_341 = F_217 ( V_447 ) ;
else
V_2 -> V_15 [ V_6 ] . V_341 = F_217 ( V_447 + ( ( V_6 + 1 ) * sizeof( struct V_256 ) ) ) ;
F_157 ( V_2 -> V_15 [ V_6 ] , V_382 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_451 = V_447 + ( ( V_2 -> V_14 + V_6 ) * sizeof( struct V_256 ) ) ;
if ( V_6 == V_2 -> V_10 - 1 )
V_2 -> V_11 [ V_6 ] . V_341 = F_217 ( V_447 + V_2 -> V_14 * sizeof( struct V_256 ) ) ;
else
V_2 -> V_11 [ V_6 ] . V_341 = F_217 ( V_447 + ( ( V_2 -> V_14 + V_6 + 1 ) * sizeof( struct V_256 ) ) ) ;
}
return 0 ;
}
static void F_218 ( struct V_1 * V_2 )
{
if ( V_2 -> V_257 != NULL ) {
F_219 ( V_2 -> V_448 , V_449 , V_2 -> V_257 , V_2 -> V_450 ) ;
V_2 -> V_257 = NULL ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
}
}
static int F_220 ( struct V_1 * V_2 , struct V_256 * V_257 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( ( V_257 [ V_6 ] . V_68 = F_221 ( V_2 -> V_448 , V_382 , & V_257 [ V_6 ] . V_452 ) ) == NULL )
return - V_240 ;
V_257 [ V_6 ] . V_453 = F_217 ( ( unsigned int ) V_257 [ V_6 ] . V_452 ) ;
}
return 0 ;
}
static void F_222 ( struct V_1 * V_2 , struct V_256 * V_257 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( V_257 [ V_6 ] . V_68 == NULL )
continue;
F_219 ( V_2 -> V_448 , V_382 , V_257 [ V_6 ] . V_68 , V_257 [ V_6 ] . V_452 ) ;
V_257 [ V_6 ] . V_68 = NULL ;
}
}
static int F_223 ( struct V_1 * V_2 )
{
V_2 -> V_14 = 32 ;
V_2 -> V_10 = 32 ;
if ( F_215 ( V_2 ) < 0 ||
F_220 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) < 0 ||
F_220 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) < 0 ||
F_212 ( V_2 ) < 0 ) {
F_12 ( ( L_142 , V_2 -> V_8 ) ) ;
return - V_240 ;
}
F_224 ( V_2 ) ;
return 0 ;
}
static void F_225 ( struct V_1 * V_2 )
{
if ( V_2 -> V_257 ) {
F_222 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) ;
F_222 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) ;
F_218 ( V_2 ) ;
}
F_214 ( V_2 ) ;
}
static int F_226 ( struct V_1 * V_2 )
{
if ( F_227 ( V_2 -> V_149 , V_243 , L_143 ) == NULL ) {
F_12 ( ( L_144 ,
V_2 -> V_8 , V_2 -> V_149 ) ) ;
V_2 -> V_36 = V_454 ;
goto V_455;
}
else
V_2 -> V_456 = true ;
V_2 -> V_457 = F_228 ( V_2 -> V_149 , V_243 ) ;
if ( ! V_2 -> V_457 ) {
F_12 ( ( L_145 ,
V_2 -> V_8 , V_2 -> V_149 ) ) ;
V_2 -> V_36 = V_458 ;
goto V_455;
}
return 0 ;
V_455:
F_229 ( V_2 ) ;
return - V_33 ;
}
static void F_229 ( struct V_1 * V_2 )
{
if ( V_2 -> V_459 ) {
F_230 ( V_2 -> V_150 , V_2 ) ;
V_2 -> V_459 = false ;
}
if ( V_2 -> V_456 ) {
F_231 ( V_2 -> V_149 , V_243 ) ;
V_2 -> V_456 = false ;
}
if ( V_2 -> V_457 ) {
F_232 ( V_2 -> V_457 ) ;
V_2 -> V_457 = NULL ;
}
}
static void F_233 ( struct V_1 * V_2 )
{
char * V_460 ;
V_2 -> V_35 = NULL ;
V_2 -> line = V_31 ;
sprintf ( V_2 -> V_8 , L_146 , V_461 , V_2 -> line ) ;
if ( V_2 -> line < V_462 ) {
if ( V_463 [ V_2 -> line ] )
V_2 -> V_72 = V_463 [ V_2 -> line ] ;
}
V_31 ++ ;
if ( ! V_34 )
V_34 = V_2 ;
else {
struct V_1 * V_464 = V_34 ;
while( V_464 -> V_35 )
V_464 = V_464 -> V_35 ;
V_464 -> V_35 = V_2 ;
}
if ( V_2 -> V_72 < 4096 )
V_2 -> V_72 = 4096 ;
else if ( V_2 -> V_72 > 65535 )
V_2 -> V_72 = 65535 ;
switch( V_2 -> V_448 -> V_465 ) {
case V_466 :
V_460 = L_147 ;
break;
case V_467 :
V_460 = L_148 ;
break;
case V_468 :
V_460 = L_149 ;
break;
case V_469 :
V_460 = L_150 ;
V_2 -> V_63 . V_64 = V_84 ;
break;
default:
V_460 = L_151 ;
}
F_2 ( L_152 ,
V_460 , V_2 -> V_8 , V_2 -> V_149 ,
V_2 -> V_150 , V_2 -> V_72 ) ;
#if V_298
F_125 ( V_2 ) ;
#endif
}
static struct V_1 * F_234 ( int V_470 , int V_471 , struct V_472 * V_448 )
{
struct V_1 * V_2 ;
V_2 = F_213 ( sizeof( struct V_1 ) , V_356 ) ;
if ( ! V_2 ) {
F_12 ( ( L_153 ,
V_32 , V_470 , V_471 ) ) ;
} else {
F_235 ( & V_2 -> V_38 ) ;
V_2 -> V_38 . V_25 = & V_473 ;
V_2 -> V_18 = V_19 ;
F_236 ( & V_2 -> V_272 , F_141 ) ;
V_2 -> V_72 = 4096 ;
V_2 -> V_142 = 14745600 ;
V_2 -> V_309 = V_382 ;
V_2 -> V_38 . V_474 = 5 * V_248 / 10 ;
V_2 -> V_38 . V_475 = 30 * V_248 ;
F_198 ( & V_2 -> V_289 ) ;
F_198 ( & V_2 -> V_290 ) ;
F_237 ( & V_2 -> V_42 ) ;
memcpy ( & V_2 -> V_63 , & V_476 , sizeof( T_7 ) ) ;
V_2 -> V_380 = V_477 ;
V_2 -> V_470 = V_470 ;
V_2 -> V_471 = V_471 ;
F_238 ( & V_2 -> V_66 , V_478 , ( unsigned long ) V_2 ) ;
F_238 ( & V_2 -> V_266 , V_479 , ( unsigned long ) V_2 ) ;
V_2 -> V_448 = V_448 ;
V_2 -> V_150 = V_448 -> V_244 ;
V_2 -> V_149 = F_239 ( V_448 , 0 ) ;
V_2 -> V_480 = V_481 ;
V_2 -> V_482 = V_483 ;
V_2 -> V_36 = - 1 ;
}
return V_2 ;
}
static void F_240 ( int V_470 , struct V_472 * V_448 )
{
struct V_1 * V_348 [ V_484 ] ;
int V_6 ;
int V_347 = 1 ;
if ( V_448 -> V_465 == V_467 )
V_347 = 2 ;
else if ( V_448 -> V_465 == V_468 )
V_347 = 4 ;
for ( V_6 = 0 ; V_6 < V_347 ; ++ V_6 ) {
V_348 [ V_6 ] = F_234 ( V_470 , V_6 , V_448 ) ;
if ( V_348 [ V_6 ] == NULL ) {
for ( -- V_6 ; V_6 >= 0 ; -- V_6 ) {
F_241 ( & V_348 [ V_6 ] -> V_38 ) ;
F_175 ( V_348 [ V_6 ] ) ;
}
return;
}
}
for ( V_6 = 0 ; V_6 < V_347 ; ++ V_6 ) {
memcpy ( V_348 [ V_6 ] -> V_348 , V_348 , sizeof( V_348 ) ) ;
F_233 ( V_348 [ V_6 ] ) ;
V_348 [ V_6 ] -> V_347 = V_347 ;
F_237 ( & V_348 [ V_6 ] -> V_49 ) ;
}
if ( ! F_226 ( V_348 [ 0 ] ) ) {
F_223 ( V_348 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_347 ; ++ V_6 ) {
V_348 [ V_6 ] -> V_150 = V_348 [ 0 ] -> V_150 ;
V_348 [ V_6 ] -> V_457 = V_348 [ 0 ] -> V_457 ;
F_223 ( V_348 [ V_6 ] ) ;
}
if ( F_242 ( V_348 [ 0 ] -> V_150 ,
F_170 ,
V_348 [ 0 ] -> V_482 ,
V_348 [ 0 ] -> V_8 ,
V_348 [ 0 ] ) < 0 ) {
F_12 ( ( L_154 ,
V_348 [ 0 ] -> V_8 ,
V_348 [ 0 ] -> V_150 ) ) ;
} else {
V_348 [ 0 ] -> V_459 = true ;
F_243 ( V_348 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_347 ; V_6 ++ ) {
V_348 [ V_6 ] -> V_36 = V_348 [ 0 ] -> V_36 ;
V_348 [ V_6 ] -> V_352 = V_348 [ 0 ] -> V_352 ;
}
}
}
for ( V_6 = 0 ; V_6 < V_347 ; ++ V_6 ) {
struct V_1 * V_2 = V_348 [ V_6 ] ;
F_244 ( & V_2 -> V_38 , V_485 , V_2 -> line ,
& V_2 -> V_448 -> V_174 ) ;
}
}
static int F_245 ( struct V_472 * V_174 ,
const struct V_486 * V_487 )
{
if ( F_246 ( V_174 ) ) {
F_2 ( L_155 , V_174 ) ;
return - V_70 ;
}
F_247 ( V_174 ) ;
F_240 ( V_31 , V_174 ) ;
return 0 ;
}
static void F_248 ( struct V_472 * V_174 )
{
}
static void F_249 ( void )
{
int V_143 ;
struct V_1 * V_2 ;
struct V_1 * V_488 ;
F_2 ( V_489 L_156 , V_32 ) ;
if ( V_485 ) {
for ( V_2 = V_34 ; V_2 != NULL ; V_2 = V_2 -> V_35 )
F_250 ( V_485 , V_2 -> line ) ;
V_143 = F_251 ( V_485 ) ;
if ( V_143 )
F_12 ( ( L_157 , V_143 ) ) ;
F_252 ( V_485 ) ;
}
V_2 = V_34 ;
while( V_2 ) {
F_253 ( V_2 ) ;
V_2 = V_2 -> V_35 ;
}
V_2 = V_34 ;
while( V_2 ) {
#if V_298
F_130 ( V_2 ) ;
#endif
F_225 ( V_2 ) ;
F_214 ( V_2 ) ;
if ( V_2 -> V_471 == 0 )
F_229 ( V_2 ) ;
V_488 = V_2 ;
V_2 = V_2 -> V_35 ;
F_241 ( & V_488 -> V_38 ) ;
F_175 ( V_488 ) ;
}
if ( V_490 )
F_254 ( & V_491 ) ;
}
static int T_10 F_255 ( void )
{
int V_143 ;
F_2 ( V_489 L_158 , V_32 ) ;
V_485 = F_256 ( V_462 ) ;
if ( ! V_485 ) {
F_2 ( L_159 , V_32 ) ;
return - V_240 ;
}
V_485 -> V_32 = V_492 ;
V_485 -> V_17 = V_461 ;
V_485 -> V_493 = V_494 ;
V_485 -> V_495 = 64 ;
V_485 -> type = V_496 ;
V_485 -> V_497 = V_498 ;
V_485 -> V_499 = V_500 ;
V_485 -> V_499 . V_54 =
V_501 | V_367 | V_360 | V_359 | V_375 ;
V_485 -> V_499 . V_502 = 9600 ;
V_485 -> V_499 . V_503 = 9600 ;
V_485 -> V_22 = V_504 | V_505 ;
F_257 ( V_485 , & V_25 ) ;
if ( ( V_143 = F_258 ( V_485 ) ) < 0 ) {
F_12 ( ( L_160 , V_32 ) ) ;
F_252 ( V_485 ) ;
V_485 = NULL ;
goto error;
}
F_2 ( V_489 L_161 ,
V_32 , V_485 -> V_493 ) ;
V_31 = 0 ;
if ( ( V_143 = F_259 ( & V_491 ) ) < 0 ) {
F_2 ( L_162 , V_32 , V_143 ) ;
goto error;
}
V_490 = true ;
if ( ! V_34 )
F_2 ( L_163 , V_32 ) ;
return 0 ;
error:
F_249 () ;
return V_143 ;
}
static void T_11 F_260 ( void )
{
F_249 () ;
}
static T_1 F_261 ( struct V_1 * V_2 , unsigned int V_506 )
{
F_262 () ;
return F_263 ( ( void V_507 * ) V_457 ) ;
}
static void F_264 ( struct V_1 * V_2 , unsigned int V_506 , T_1 V_169 )
{
F_262 () ;
F_265 ( V_169 , ( void V_507 * ) V_457 ) ;
}
static T_12 F_97 ( struct V_1 * V_2 , unsigned int V_506 )
{
F_262 () ;
return F_266 ( ( void V_507 * ) V_457 ) ;
}
static void F_98 ( struct V_1 * V_2 , unsigned int V_506 , T_12 V_169 )
{
F_262 () ;
F_267 ( V_169 , ( void V_507 * ) V_457 ) ;
}
static T_8 F_163 ( struct V_1 * V_2 , unsigned int V_506 )
{
F_262 () ;
return F_268 ( ( void V_507 * ) V_457 ) ;
}
static void F_164 ( struct V_1 * V_2 , unsigned int V_506 , T_8 V_169 )
{
F_262 () ;
F_269 ( V_169 , ( void V_507 * ) V_457 ) ;
}
static void F_270 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_164 ( V_2 , V_327 , V_261 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_163 ( V_2 , V_327 ) & V_262 ) )
break;
}
static void F_167 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_164 ( V_2 , V_330 , V_261 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_163 ( V_2 , V_330 ) & V_262 ) )
break;
}
static void F_271 ( struct V_1 * V_2 )
{
F_98 ( V_2 , V_404 , ( unsigned short ) ( F_97 ( V_2 , V_404 ) | V_291 ) ) ;
if ( V_2 -> V_63 . V_64 != V_84 ) {
F_264 ( V_2 , V_508 , 0x49 ) ;
if ( V_2 -> V_63 . V_132 )
F_272 ( V_2 , V_2 -> V_63 . V_132 ) ;
else
F_272 ( V_2 , 3686400 ) ;
}
}
static void F_272 ( struct V_1 * V_2 , T_9 V_509 )
{
unsigned int div ;
unsigned int V_510 = V_2 -> V_142 ;
if ( V_509 ) {
div = V_510 / V_509 ;
if ( ! ( V_510 % V_509 ) && div )
div -- ;
F_98 ( V_2 , V_511 , ( unsigned short ) div ) ;
}
}
static void F_156 ( struct V_1 * V_2 )
{
unsigned short V_333 ;
V_333 = F_97 ( V_2 , V_384 ) & ~ V_261 ;
F_98 ( V_2 , V_384 , ( unsigned short ) ( V_333 | V_291 ) ) ;
F_98 ( V_2 , V_384 , V_333 ) ;
F_149 ( V_2 , V_326 + V_307 + V_322 ) ;
F_98 ( V_2 , V_306 , V_322 + V_326 ) ;
F_270 ( V_2 ) ;
V_2 -> V_383 = false ;
V_2 -> V_278 = false ;
}
static void F_146 ( struct V_1 * V_2 )
{
unsigned short V_333 ;
F_149 ( V_2 , V_326 + V_307 ) ;
F_98 ( V_2 , V_306 , V_326 ) ;
V_333 = F_97 ( V_2 , V_384 ) & ~ V_261 ;
F_98 ( V_2 , V_384 , ( unsigned short ) ( V_333 | V_291 ) ) ;
F_98 ( V_2 , V_384 , V_333 ) ;
F_270 ( V_2 ) ;
F_224 ( V_2 ) ;
if ( V_2 -> V_314 ) {
F_98 ( V_2 , V_404 , ( unsigned short ) ( F_97 ( V_2 , V_404 ) & ~ V_512 ) ) ;
F_180 ( V_2 , V_307 ) ;
if ( V_2 -> V_63 . V_64 == V_84 ) {
F_164 ( V_2 , V_327 , V_172 ) ;
}
} else {
F_98 ( V_2 , V_404 , ( unsigned short ) ( F_97 ( V_2 , V_404 ) | V_512 ) ) ;
F_164 ( V_2 , V_513 , V_2 -> V_15 [ 0 ] . V_451 ) ;
if ( V_2 -> V_63 . V_64 != V_84 ) {
F_164 ( V_2 , V_327 , ( V_291 + V_262 ) ) ;
} else {
F_164 ( V_2 , V_327 , ( V_172 + V_291 + V_262 ) ) ;
}
}
F_180 ( V_2 , V_326 ) ;
F_98 ( V_2 , V_384 , ( unsigned short ) ( F_97 ( V_2 , V_384 ) | V_261 ) ) ;
V_2 -> V_278 = false ;
V_2 -> V_383 = true ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_77 ) {
F_98 ( V_2 , V_171 ,
( unsigned short ) ( ( F_97 ( V_2 , V_171 ) | V_261 ) & ~ V_291 ) ) ;
V_2 -> V_77 = true ;
}
if ( F_134 ( V_2 -> V_11 [ V_2 -> V_331 ] ) ) {
V_2 -> V_334 = false ;
if ( V_2 -> V_63 . V_64 != V_84 ) {
if ( V_2 -> V_63 . V_22 & V_514 ) {
F_85 ( V_2 ) ;
if ( ! ( V_2 -> V_57 & V_58 ) ) {
V_2 -> V_57 |= V_58 ;
F_31 ( V_2 ) ;
V_2 -> V_334 = true ;
}
}
F_149 ( V_2 , V_332 ) ;
F_180 ( V_2 , V_321 + V_313 ) ;
F_98 ( V_2 , V_306 , ( unsigned short ) ( V_313 + V_321 ) ) ;
} else {
F_149 ( V_2 , V_332 ) ;
F_180 ( V_2 , V_313 ) ;
F_98 ( V_2 , V_306 , V_313 ) ;
}
F_164 ( V_2 , V_515 , V_2 -> V_11 [ V_2 -> V_331 ] . V_451 ) ;
F_164 ( V_2 , V_330 , V_291 + V_262 ) ;
V_2 -> V_81 = true ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned short V_333 ;
F_168 ( & V_2 -> V_66 ) ;
F_167 ( V_2 ) ;
V_333 = F_97 ( V_2 , V_171 ) & ~ V_261 ;
F_98 ( V_2 , V_171 , ( unsigned short ) ( V_333 | V_291 ) ) ;
F_149 ( V_2 , V_332 + V_313 + V_321 ) ;
F_98 ( V_2 , V_306 , ( unsigned short ) ( V_313 + V_321 ) ) ;
F_273 ( V_2 ) ;
V_2 -> V_77 = false ;
V_2 -> V_81 = false ;
}
static void F_253 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_457 )
return;
F_52 ( V_2 ) ;
F_156 ( V_2 ) ;
V_2 -> V_57 &= ~ ( V_58 | V_59 ) ;
F_31 ( V_2 ) ;
F_149 ( V_2 , V_357 | V_358 ) ;
}
static void F_274 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_347 ; ++ V_6 ) {
if ( V_2 -> V_348 [ V_6 ] )
F_253 ( V_2 -> V_348 [ V_6 ] ) ;
}
}
static void F_179 ( struct V_1 * V_2 )
{
unsigned short V_333 ;
F_149 ( V_2 , V_357 | V_358 ) ;
F_52 ( V_2 ) ;
F_156 ( V_2 ) ;
V_333 = 0x4000 ;
if ( V_2 -> V_408 & V_409 )
V_333 |= V_410 ;
if ( V_2 -> V_63 . V_123 != V_373 ) {
V_333 |= V_516 ;
if ( V_2 -> V_63 . V_123 == V_371 )
V_333 |= V_349 ;
}
switch ( V_2 -> V_63 . V_137 )
{
case 6 : V_333 |= V_329 ; break;
case 7 : V_333 |= V_328 ; break;
case 8 : V_333 |= V_328 + V_329 ; break;
}
if ( V_2 -> V_63 . V_138 != 1 )
V_333 |= V_283 ;
if ( V_2 -> V_63 . V_22 & V_517 )
V_333 |= V_262 ;
F_98 ( V_2 , V_171 , V_333 ) ;
V_333 = 0x4000 ;
if ( V_2 -> V_63 . V_123 != V_373 ) {
V_333 |= V_516 ;
if ( V_2 -> V_63 . V_123 == V_371 )
V_333 |= V_349 ;
}
switch ( V_2 -> V_63 . V_137 )
{
case 6 : V_333 |= V_329 ; break;
case 7 : V_333 |= V_328 ; break;
case 8 : V_333 |= V_328 + V_329 ; break;
}
if ( V_2 -> V_63 . V_22 & V_518 )
V_333 |= V_262 ;
F_98 ( V_2 , V_384 , V_333 ) ;
F_264 ( V_2 , V_508 , 0x69 ) ;
F_196 ( V_2 ) ;
V_333 = V_311 + V_512 + V_262 ;
if ( ( F_163 ( V_2 , V_519 ) & V_349 ) && V_2 -> V_63 . V_80 &&
( ( V_2 -> V_142 < ( V_2 -> V_63 . V_80 * 16 ) ) ||
( V_2 -> V_142 % ( V_2 -> V_63 . V_80 * 16 ) ) ) ) {
V_333 |= V_283 ;
F_272 ( V_2 , V_2 -> V_63 . V_80 * 8 ) ;
} else {
F_272 ( V_2 , V_2 -> V_63 . V_80 * 16 ) ;
}
F_98 ( V_2 , V_404 , V_333 ) ;
F_180 ( V_2 , V_315 | V_326 ) ;
if ( V_2 -> V_63 . V_130 )
F_271 ( V_2 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
unsigned short V_333 ;
F_149 ( V_2 , V_357 | V_358 ) ;
F_52 ( V_2 ) ;
F_156 ( V_2 ) ;
V_333 = V_291 ;
switch( V_2 -> V_63 . V_64 ) {
case V_277 :
V_333 |= V_311 + V_520 ;
break;
case V_275 : V_333 |= V_512 + V_520 ; break;
case V_276 : V_333 |= V_311 ; break;
case V_274 : V_333 |= V_520 ; break;
}
if ( V_2 -> V_408 & V_409 )
V_333 |= V_410 ;
switch( V_2 -> V_63 . V_131 )
{
case V_521 : V_333 |= V_310 ; break;
case V_522 : V_333 |= V_523 ; break;
case V_524 : V_333 |= V_523 + V_310 ; break;
case V_182 : V_333 |= V_525 ; break;
case V_184 : V_333 |= V_525 + V_310 ; break;
case V_186 : V_333 |= V_525 + V_523 ; break;
case V_526 : V_333 |= V_525 + V_523 + V_310 ; break;
}
switch ( V_2 -> V_63 . V_134 & V_527 )
{
case V_190 : V_333 |= V_516 ; break;
case V_192 : V_333 |= V_516 + V_349 ; break;
}
if ( V_2 -> V_63 . V_136 != V_528 )
V_333 |= V_172 ;
switch ( V_2 -> V_63 . V_135 )
{
case V_529 : V_333 |= V_328 ; break;
case V_530 : V_333 |= V_329 ; break;
case V_531 : V_333 |= V_328 + V_329 ; break;
}
if ( V_2 -> V_63 . V_22 & V_517 )
V_333 |= V_262 ;
F_98 ( V_2 , V_171 , V_333 ) ;
switch ( V_2 -> V_63 . V_136 )
{
case V_532 : V_333 = 0x7e ; break;
case V_533 : V_333 = 0xff ; break;
case V_534 : V_333 = 0x00 ; break;
case V_535 : V_333 = 0x55 ; break;
case V_536 : V_333 = 0xaa ; break;
default: V_333 = 0x7e ; break;
}
F_264 ( V_2 , V_537 , ( unsigned char ) V_333 ) ;
V_333 = 0 ;
switch( V_2 -> V_63 . V_64 ) {
case V_277 :
V_333 |= V_311 + V_520 ;
break;
case V_275 : V_333 |= V_512 + V_520 ; break;
case V_276 : V_333 |= V_311 ; break;
case V_274 : V_333 |= V_520 ; break;
}
switch( V_2 -> V_63 . V_131 )
{
case V_521 : V_333 |= V_310 ; break;
case V_522 : V_333 |= V_523 ; break;
case V_524 : V_333 |= V_523 + V_310 ; break;
case V_182 : V_333 |= V_525 ; break;
case V_184 : V_333 |= V_525 + V_310 ; break;
case V_186 : V_333 |= V_525 + V_523 ; break;
case V_526 : V_333 |= V_525 + V_523 + V_310 ; break;
}
switch ( V_2 -> V_63 . V_134 & V_527 )
{
case V_190 : V_333 |= V_516 ; break;
case V_192 : V_333 |= V_516 + V_349 ; break;
}
if ( V_2 -> V_63 . V_22 & V_518 )
V_333 |= V_262 ;
F_98 ( V_2 , V_384 , V_333 ) ;
V_333 = 0 ;
if ( V_2 -> V_63 . V_22 & V_220 )
{
if ( V_2 -> V_63 . V_22 & V_215 )
V_333 |= V_172 + V_328 ;
else
V_333 |= V_172 ;
}
else if ( V_2 -> V_63 . V_22 & V_219 )
V_333 |= V_410 ;
else if ( V_2 -> V_63 . V_22 & V_221 )
V_333 |= V_328 ;
if ( V_2 -> V_63 . V_22 & V_216 )
V_333 |= V_283 ;
else if ( V_2 -> V_63 . V_22 & V_215 )
V_333 |= V_329 ;
else if ( V_2 -> V_63 . V_22 & V_217 )
V_333 |= V_291 ;
if ( V_2 -> V_63 . V_132 )
V_333 |= V_261 + V_262 ;
F_264 ( V_2 , V_508 , ( unsigned char ) V_333 ) ;
if ( V_2 -> V_63 . V_22 & ( V_219 + V_215 ) )
{
switch( V_2 -> V_63 . V_131 )
{
case V_182 :
case V_184 :
V_333 = V_410 ; break;
case V_186 :
case V_526 :
V_333 = V_410 + V_172 ; break;
default: V_333 = V_172 ;
}
F_98 ( V_2 , V_384 , ( unsigned short ) ( F_97 ( V_2 , V_384 ) | V_333 ) ) ;
F_272 ( V_2 , V_2 -> V_63 . V_132 * 16 ) ;
}
else
F_272 ( V_2 , V_2 -> V_63 . V_132 ) ;
F_188 ( V_2 ) ;
F_196 ( V_2 ) ;
F_98 ( V_2 , V_404 , V_311 + V_512 + V_262 ) ;
if ( V_2 -> V_63 . V_130 )
F_271 ( V_2 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
unsigned char V_333 ;
unsigned short V_538 ;
V_538 = F_97 ( V_2 , V_171 ) ;
if ( V_2 -> V_380 & V_539 ) {
V_538 = ( V_538 & ~ ( V_172 + V_328 ) ) | V_329 ;
F_264 ( V_2 , V_537 , ( unsigned char ) ( ( V_2 -> V_380 >> 8 ) & 0xff ) ) ;
} else if ( ! ( V_538 & V_172 ) ) {
V_538 &= ~ ( V_328 + V_329 ) ;
}
F_98 ( V_2 , V_171 , V_538 ) ;
if ( V_2 -> V_380 & ( V_540 | V_539 ) ) {
V_333 = ( unsigned char ) ( V_2 -> V_380 & 0xff ) ;
} else {
switch( V_2 -> V_380 )
{
case V_477 : V_333 = 0x7e ; break;
case V_541 :
case V_542 : V_333 = 0xaa ; break;
case V_543 :
case V_544 : V_333 = 0x00 ; break;
default: V_333 = 0xff ;
}
}
F_264 ( V_2 , V_545 , V_333 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_97 ( V_2 , V_306 ) ;
V_2 -> V_57 &= V_58 | V_59 ;
if ( V_12 & V_283 )
V_2 -> V_57 |= V_152 ;
if ( V_12 & V_291 )
V_2 -> V_57 |= V_151 ;
if ( V_12 & V_261 )
V_2 -> V_57 |= V_153 ;
if ( V_12 & V_262 )
V_2 -> V_57 |= V_154 ;
}
static void F_196 ( struct V_1 * V_2 )
{
unsigned char V_333 = 0 ;
switch( V_2 -> V_408 & V_546 )
{
case V_547 :
V_333 |= V_328 ;
break;
case V_548 :
V_333 |= V_410 + V_172 + V_328 ;
break;
case V_549 :
V_333 |= V_172 ;
break;
}
if ( V_2 -> V_408 & V_550 )
V_333 |= V_329 ;
if ( V_2 -> V_57 & V_59 )
V_333 |= V_283 ;
if ( V_2 -> V_57 & V_58 )
V_333 |= V_291 ;
if ( V_2 -> V_408 & V_551 )
V_333 |= V_261 ;
if ( V_2 -> V_408 & V_552 )
V_333 |= V_262 ;
F_264 ( V_2 , V_553 , V_333 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned char V_333 = F_261 ( V_2 , V_553 ) ;
if ( V_2 -> V_57 & V_59 )
V_333 |= V_283 ;
else
V_333 &= ~ V_283 ;
if ( V_2 -> V_57 & V_58 )
V_333 |= V_291 ;
else
V_333 &= ~ V_291 ;
F_264 ( V_2 , V_553 , V_333 ) ;
}
static void F_138 ( struct V_1 * V_2 , unsigned int V_6 , unsigned int V_554 )
{
int V_555 = 0 ;
while( ! V_555 ) {
V_2 -> V_15 [ V_6 ] . V_12 = 0 ;
F_157 ( V_2 -> V_15 [ V_6 ] , V_2 -> V_309 ) ;
if ( V_6 == V_554 )
V_555 = 1 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
}
V_2 -> V_13 = V_6 ;
}
static void F_224 ( struct V_1 * V_2 )
{
F_138 ( V_2 , 0 , V_2 -> V_14 - 1 ) ;
V_2 -> V_304 = 0 ;
V_2 -> V_303 = 0 ;
}
static bool F_144 ( struct V_1 * V_2 )
{
unsigned int V_253 , V_254 ;
unsigned short V_12 ;
unsigned int V_556 = 0 ;
unsigned long V_22 ;
struct V_20 * V_21 = V_2 -> V_38 . V_21 ;
unsigned char V_557 = 0xff ;
unsigned int V_558 = 0 ;
switch ( V_2 -> V_63 . V_134 & V_527 ) {
case V_190 : V_558 = 2 ; break;
case V_192 : V_558 = 4 ; break;
}
V_559:
V_556 = 0 ;
V_557 = 0xff ;
V_253 = V_254 = V_2 -> V_13 ;
for (; ; ) {
if ( ! F_133 ( V_2 -> V_15 [ V_254 ] ) )
goto V_45;
if ( V_556 == 0 && V_2 -> V_63 . V_133 != 0xff )
V_557 = V_2 -> V_15 [ V_254 ] . V_68 [ 0 ] ;
V_556 += F_134 ( V_2 -> V_15 [ V_254 ] ) ;
if ( F_275 ( V_2 -> V_15 [ V_254 ] ) )
break;
if ( ++ V_254 == V_2 -> V_14 )
V_254 = 0 ;
if ( V_254 == V_2 -> V_13 ) {
if ( V_2 -> V_383 ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_146 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
goto V_45;
}
}
V_12 = F_276 ( V_2 -> V_15 [ V_254 ] ) ;
if ( ( V_2 -> V_63 . V_134 & V_527 ) == V_188 )
V_12 &= ~ V_261 ;
if ( V_556 == 0 ||
( V_557 != 0xff && V_557 != V_2 -> V_63 . V_133 ) ) {
F_138 ( V_2 , V_253 , V_254 ) ;
goto V_559;
}
if ( V_556 < ( 2 + V_558 ) || V_12 & V_262 ) {
V_2 -> V_112 . V_159 ++ ;
V_556 = 0 ;
} else if ( V_12 & V_261 ) {
V_2 -> V_112 . V_162 ++ ;
if ( ! ( V_2 -> V_63 . V_134 & V_560 ) )
V_556 = 0 ;
}
#if V_298
if ( V_556 == 0 ) {
V_2 -> V_233 -> V_197 . V_561 ++ ;
V_2 -> V_233 -> V_197 . V_562 ++ ;
}
#endif
F_143 ( ( L_164 ,
V_2 -> V_8 , V_12 , V_556 ) ) ;
F_136 ( V_2 , V_2 -> V_15 [ V_253 ] . V_68 , F_43 ( int , V_556 , V_2 -> V_309 ) , L_94 ) ;
if ( V_556 ) {
if ( ! ( V_2 -> V_63 . V_134 & V_560 ) ) {
V_556 -= V_558 ;
V_558 = 0 ;
}
if ( V_556 > V_2 -> V_72 + V_558 )
V_2 -> V_112 . V_160 ++ ;
else {
int V_563 = V_556 ;
int V_6 = V_253 ;
unsigned char * V_255 = V_2 -> V_445 ;
V_2 -> V_564 = V_556 ;
V_2 -> V_112 . V_156 ++ ;
while( V_563 ) {
int V_565 = F_43 ( int , V_563 , V_2 -> V_309 ) ;
memcpy ( V_255 , V_2 -> V_15 [ V_6 ] . V_68 , V_565 ) ;
V_255 += V_565 ;
V_563 -= V_565 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
}
if ( V_2 -> V_63 . V_134 & V_560 ) {
* V_255 = ( V_12 & V_261 ) ? V_566 : V_567 ;
V_556 ++ ;
}
#if V_298
if ( V_2 -> V_43 )
F_120 ( V_2 , V_2 -> V_445 , V_556 ) ;
else
#endif
F_8 ( V_21 , V_2 -> V_445 , V_2 -> V_446 , V_556 ) ;
}
}
F_138 ( V_2 , V_253 , V_254 ) ;
return true ;
V_45:
return false ;
}
static bool F_145 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_2 -> V_13 ;
unsigned int V_4 ;
if ( ! F_133 ( V_2 -> V_15 [ V_6 ] ) )
return false ;
V_4 = F_134 ( V_2 -> V_15 [ V_6 ] ) ;
switch( V_2 -> V_63 . V_64 ) {
case V_275 :
case V_276 :
case V_277 :
if ( F_277 ( V_2 -> V_15 [ V_6 ] ) )
V_4 -- ;
break;
}
F_136 ( V_2 , V_2 -> V_15 [ V_6 ] . V_68 , V_4 , L_94 ) ;
F_13 ( ( L_165 , V_4 ) ) ;
if ( V_4 )
F_8 ( V_2 -> V_38 . V_21 , V_2 -> V_15 [ V_6 ] . V_68 ,
V_2 -> V_446 , V_4 ) ;
F_138 ( V_2 , V_6 , V_6 ) ;
return true ;
}
static void F_273 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_2 -> V_9 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_12 = 0 ;
V_2 -> V_11 [ V_6 ] . V_4 = 0 ;
}
}
static unsigned int F_278 ( struct V_1 * V_2 )
{
unsigned int V_4 = 0 ;
unsigned int V_6 = V_2 -> V_9 ;
do
{
if ( F_134 ( V_2 -> V_11 [ V_6 ] ) )
break;
++ V_4 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
} while ( V_6 != V_2 -> V_9 );
if ( V_4 && ( F_163 ( V_2 , V_330 ) & V_262 ) )
-- V_4 ;
return V_4 ;
}
static unsigned int F_35 ( struct V_1 * V_2 )
{
unsigned int V_568 = 0 ;
unsigned int V_6 = V_2 -> V_9 ;
unsigned int V_569 ;
unsigned int V_4 ;
unsigned int V_570 = 0 ;
do {
V_4 = F_134 ( V_2 -> V_11 [ V_6 ] ) ;
if ( V_4 )
V_568 += V_4 ;
else if ( ! V_568 )
V_570 = V_2 -> V_11 [ V_6 ] . V_571 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
} while ( V_6 != V_2 -> V_9 );
V_569 = F_163 ( V_2 , V_330 ) ;
if ( V_569 & V_262 )
V_568 += V_570 ;
V_568 += ( V_569 >> 8 ) & 0xff ;
if ( V_2 -> V_81 )
V_568 ++ ;
return V_568 ;
}
static bool F_39 ( struct V_1 * V_2 , const char * V_68 , unsigned int V_204 )
{
unsigned short V_4 ;
unsigned int V_6 ;
struct V_256 * V_572 ;
if ( F_279 ( V_204 , V_382 ) > F_278 ( V_2 ) )
return false ;
F_136 ( V_2 , V_68 , V_204 , L_166 ) ;
V_2 -> V_331 = V_6 = V_2 -> V_9 ;
while ( V_204 ) {
V_572 = & V_2 -> V_11 [ V_6 ] ;
V_4 = ( unsigned short ) ( ( V_204 > V_382 ) ? V_382 : V_204 ) ;
memcpy ( V_572 -> V_68 , V_68 , V_4 ) ;
V_204 -= V_4 ;
V_68 += V_4 ;
if ( ( ! V_204 && V_2 -> V_63 . V_64 == V_65 ) ||
V_2 -> V_63 . V_64 == V_274 )
F_280 ( * V_572 , 1 ) ;
else
F_280 ( * V_572 , 0 ) ;
if ( V_6 != V_2 -> V_331 )
F_157 ( * V_572 , V_4 ) ;
V_572 -> V_571 = V_4 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
}
V_2 -> V_9 = V_6 ;
V_572 = & V_2 -> V_11 [ V_2 -> V_331 ] ;
F_157 ( * V_572 , V_572 -> V_571 ) ;
if ( ! V_2 -> V_81 )
F_42 ( V_2 ) ;
F_34 ( V_2 ) ;
return true ;
}
static int F_281 ( struct V_1 * V_2 )
{
static unsigned short V_573 [] =
{ 0x0000 , 0xffff , 0xaaaa , 0x5555 , 0x6969 , 0x9696 } ;
static unsigned int V_4 = F_282 ( V_573 ) ;
unsigned int V_6 ;
int V_143 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
F_98 ( V_2 , V_545 , V_573 [ V_6 ] ) ;
F_98 ( V_2 , V_511 , V_573 [ ( V_6 + 1 ) % V_4 ] ) ;
if ( ( F_97 ( V_2 , V_545 ) != V_573 [ V_6 ] ) ||
( F_97 ( V_2 , V_511 ) != V_573 [ ( V_6 + 1 ) % V_4 ] ) ) {
V_143 = - V_33 ;
break;
}
}
V_2 -> V_352 = ( F_163 ( V_2 , V_519 ) & V_328 ) ? 1 : 0 ;
V_2 -> V_36 = V_143 ? 0 : V_574 ;
return V_143 ;
}
static int F_283 ( struct V_1 * V_2 )
{
unsigned long V_47 ;
unsigned long V_22 ;
struct V_20 * V_575 = V_2 -> V_38 . V_21 ;
T_9 V_576 = V_2 -> V_63 . V_80 ;
V_2 -> V_63 . V_80 = 921600 ;
V_2 -> V_38 . V_21 = NULL ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_179 ( V_2 ) ;
F_180 ( V_2 , V_313 ) ;
F_98 ( V_2 , V_171 ,
( unsigned short ) ( F_97 ( V_2 , V_171 ) | V_261 ) ) ;
F_98 ( V_2 , V_577 , 0 ) ;
V_2 -> V_36 = V_578 ;
V_2 -> V_312 = false ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_47 = 100 ;
while( V_47 -- && ! V_2 -> V_312 )
F_44 ( 10 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_253 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_63 . V_80 = V_576 ;
V_2 -> V_38 . V_21 = V_575 ;
V_2 -> V_36 = V_2 -> V_312 ? 0 : V_578 ;
return V_2 -> V_312 ? 0 : - V_33 ;
}
static int F_284 ( struct V_1 * V_2 )
{
unsigned char * V_579 , * V_580 ;
int V_4 ;
if ( F_133 ( V_2 -> V_15 [ 0 ] ) ) {
V_4 = F_134 ( V_2 -> V_15 [ 0 ] ) ;
V_579 = V_2 -> V_15 [ 0 ] . V_68 ;
V_580 = V_2 -> V_445 ;
for( ; V_4 ; V_4 -= 2 , V_579 += 2 ) {
if ( ! ( * ( V_579 + 1 ) & ( V_516 + V_349 ) ) ) {
* V_580 = * V_579 ;
V_580 ++ ;
V_2 -> V_564 ++ ;
}
}
F_136 ( V_2 , V_2 -> V_445 , V_2 -> V_564 , L_94 ) ;
return 1 ;
}
return 0 ;
}
static int F_285 ( struct V_1 * V_2 )
{
#define F_286 20
unsigned long V_47 ;
T_13 V_4 = F_286 ;
unsigned char V_68 [ F_286 ] ;
int V_143 = - V_33 ;
unsigned long V_22 ;
struct V_20 * V_575 = V_2 -> V_38 . V_21 ;
T_7 V_63 ;
memcpy ( & V_63 , & V_2 -> V_63 , sizeof( V_63 ) ) ;
V_2 -> V_63 . V_64 = V_84 ;
V_2 -> V_63 . V_80 = 921600 ;
V_2 -> V_63 . V_130 = 1 ;
V_2 -> V_38 . V_21 = NULL ;
for ( V_4 = 0 ; V_4 < F_286 ; ++ V_4 )
V_68 [ V_4 ] = ( unsigned char ) V_4 ;
V_2 -> V_564 = 0 ;
memset ( V_2 -> V_445 , 0 , F_286 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_179 ( V_2 ) ;
F_146 ( V_2 ) ;
F_39 ( V_2 , V_68 , V_4 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
for ( V_47 = 100 ; V_47 ; -- V_47 ) {
F_44 ( 10 ) ;
if ( F_284 ( V_2 ) ) {
V_143 = 0 ;
break;
}
}
if ( ! V_143 && ( V_2 -> V_564 != V_4 ||
memcmp ( V_68 , V_2 -> V_445 , V_4 ) ) ) {
V_143 = - V_33 ;
}
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_274 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
memcpy ( & V_2 -> V_63 , & V_63 , sizeof( V_2 -> V_63 ) ) ;
V_2 -> V_38 . V_21 = V_575 ;
V_2 -> V_36 = V_143 ? V_581 : 0 ;
return V_143 ;
}
static int F_243 ( struct V_1 * V_2 )
{
F_13 ( ( L_167 , V_2 -> V_8 ) ) ;
if ( F_281 ( V_2 ) < 0 ) {
F_2 ( L_168 ,
V_2 -> V_8 , V_2 -> V_149 ) ;
} else if ( F_283 ( V_2 ) < 0 ) {
F_2 ( L_169 ,
V_2 -> V_8 , V_2 -> V_150 ) ;
} else if ( F_285 ( V_2 ) < 0 ) {
F_2 ( L_170 , V_2 -> V_8 ) ;
}
return V_2 -> V_36 ;
}
static void V_478 ( unsigned long V_582 )
{
struct V_1 * V_2 = (struct V_1 * ) V_582 ;
unsigned long V_22 ;
F_13 ( ( L_171 , V_2 -> V_8 ) ) ;
if( V_2 -> V_81 && V_2 -> V_63 . V_64 == V_65 ) {
V_2 -> V_112 . V_583 ++ ;
}
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_52 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
#if V_298
if ( V_2 -> V_43 )
F_118 ( V_2 ) ;
else
#endif
F_147 ( V_2 ) ;
}
static void V_479 ( unsigned long V_582 )
{
struct V_1 * V_2 = (struct V_1 * ) V_582 ;
unsigned long V_22 ;
F_13 ( ( L_172 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_165 |= V_267 ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_141 ( & V_2 -> V_272 ) ;
}
