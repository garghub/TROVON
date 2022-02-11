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
if ( ( V_53 -> V_54 & V_55 ) && ! F_31 ( V_21 ) ) {
V_2 -> V_56 &= ~ ( V_57 | V_58 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_32 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
if ( ! ( V_53 -> V_54 & V_55 ) && F_31 ( V_21 ) ) {
V_2 -> V_56 |= V_58 ;
if ( ! F_33 ( V_21 ) || ! F_34 ( V_59 , & V_21 -> V_22 ) )
V_2 -> V_56 |= V_57 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_32 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
if ( ( V_53 -> V_54 & V_60 ) && ! F_33 ( V_21 ) ) {
V_21 -> V_61 = 0 ;
F_35 ( V_21 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_62 . V_63 == V_64 ) {
int V_47 = ( F_37 ( V_2 ) * 7 ) + 1000 ;
F_38 ( & V_2 -> V_65 , V_66 + F_39 ( V_47 ) ) ;
}
}
static int F_40 ( struct V_20 * V_21 ,
const unsigned char * V_67 , int V_4 )
{
int V_68 = 0 ;
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_24 ) )
return - V_69 ;
F_13 ( ( L_25 , V_2 -> V_8 , V_4 ) ) ;
if ( ! V_2 -> V_70 || ( V_4 > V_2 -> V_71 ) )
return - V_69 ;
if ( ! V_4 || V_21 -> V_72 || V_21 -> V_61 )
return 0 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_73 ) {
if ( ! F_41 ( V_2 , V_2 -> V_70 , V_2 -> V_73 ) )
goto V_45;
V_2 -> V_73 = 0 ;
}
if ( F_41 ( V_2 , V_67 , V_4 ) )
V_68 = V_4 ;
V_45:
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_13 ( ( L_26 , V_2 -> V_8 , V_68 ) ) ;
return V_68 ;
}
static int F_42 ( struct V_20 * V_21 , unsigned char V_74 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
int V_68 = 0 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_27 ) )
return 0 ;
F_13 ( ( L_28 , V_2 -> V_8 , V_74 ) ) ;
if ( ! V_2 -> V_70 )
return 0 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_73 < V_2 -> V_71 ) {
V_2 -> V_70 [ V_2 -> V_73 ++ ] = V_74 ;
V_68 = 1 ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
return V_68 ;
}
static void F_43 ( struct V_20 * V_21 , char V_74 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_29 ) )
return;
F_13 ( ( L_30 , V_2 -> V_8 , V_74 ) ) ;
V_2 -> V_75 = V_74 ;
if ( V_74 ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( ! V_2 -> V_76 )
F_44 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
}
static void F_22 ( struct V_20 * V_21 , int V_47 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_77 , V_78 ;
if ( ! V_2 )
return;
if ( F_6 ( V_2 , V_21 -> V_17 , L_31 ) )
return;
F_13 ( ( L_32 , V_2 -> V_8 ) ) ;
if ( ! ( V_2 -> V_38 . V_22 & V_46 ) )
goto exit;
V_77 = V_66 ;
if ( V_2 -> V_62 . V_79 ) {
V_78 = V_2 -> V_47 / ( 32 * 5 ) ;
if ( ! V_78 )
V_78 ++ ;
} else
V_78 = 1 ;
if ( V_47 )
V_78 = F_45 (unsigned long, char_time, timeout) ;
while ( V_2 -> V_80 ) {
F_46 ( F_47 ( V_78 ) ) ;
if ( F_48 ( V_81 ) )
break;
if ( V_47 && F_49 ( V_66 , V_77 + V_47 ) )
break;
}
exit:
F_13 ( ( L_33 , V_2 -> V_8 ) ) ;
}
static int F_50 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_68 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_34 ) )
return 0 ;
V_68 = ( V_2 -> V_80 ) ? 0 : V_82 ;
F_13 ( ( L_35 , V_2 -> V_8 , V_68 ) ) ;
return V_68 ;
}
static void F_51 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_36 ) )
return;
F_13 ( ( L_37 , V_2 -> V_8 , V_2 -> V_73 ) ) ;
if ( V_2 -> V_73 <= 0 || V_21 -> V_72 ||
V_21 -> V_61 || ! V_2 -> V_70 )
return;
F_13 ( ( L_38 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_73 && F_41 ( V_2 , V_2 -> V_70 , V_2 -> V_73 ) )
V_2 -> V_73 = 0 ;
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
V_2 -> V_73 = 0 ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_52 ( V_21 ) ;
}
static void F_53 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_41 ) )
return;
F_13 ( ( L_42 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_76 && V_2 -> V_62 . V_63 == V_83 )
F_54 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
static void F_35 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_43 ) )
return;
F_13 ( ( L_44 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_73 && F_41 ( V_2 , V_2 -> V_70 , V_2 -> V_73 ) )
V_2 -> V_73 = 0 ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
static int F_55 ( struct V_20 * V_21 ,
unsigned int V_84 , unsigned long V_85 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
void T_2 * V_86 = ( void T_2 * ) V_85 ;
int V_68 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_45 ) )
return - V_33 ;
F_13 ( ( L_46 , V_2 -> V_8 , V_84 ) ) ;
if ( ( V_84 != V_87 ) && ( V_84 != V_88 ) &&
( V_84 != V_89 ) ) {
if ( V_21 -> V_22 & ( 1 << V_90 ) )
return - V_69 ;
}
switch ( V_84 ) {
case V_91 :
return F_56 ( V_2 , V_86 ) ;
case V_89 :
return F_57 ( V_2 , ( int ) V_85 ) ;
case V_92 :
return F_58 ( V_2 , V_86 ) ;
case V_93 :
return F_59 ( V_2 , V_86 ) ;
case V_94 :
return F_60 ( V_2 , V_86 ) ;
case V_95 :
return F_61 ( V_2 , V_86 ) ;
case V_96 :
return F_62 ( V_2 , ( int ) V_85 ) ;
case V_97 :
return F_63 ( V_2 , V_86 ) ;
case V_98 :
return F_64 ( V_2 , ( int ) V_85 ) ;
}
F_14 ( & V_2 -> V_38 . V_39 ) ;
switch ( V_84 ) {
case V_99 :
V_68 = F_65 ( V_2 , V_86 ) ;
break;
case V_100 :
V_68 = F_66 ( V_2 , V_86 ) ;
break;
case V_101 :
V_68 = F_67 ( V_2 , V_86 ) ;
break;
case V_102 :
V_68 = F_68 ( V_2 , ( int ) V_85 ) ;
break;
case V_103 :
V_68 = F_69 ( V_2 , ( int ) V_85 ) ;
break;
case V_104 :
V_68 = F_70 ( V_2 , ( int ) V_85 ) ;
break;
case V_105 :
V_68 = F_71 ( V_2 ) ;
break;
case V_106 :
V_68 = F_72 ( V_2 , V_86 ) ;
break;
case V_107 :
V_68 = F_73 ( V_2 , V_86 ) ;
break;
case V_108 :
V_68 = F_74 ( V_2 , ( int ) V_85 ) ;
break;
default:
V_68 = - V_109 ;
}
F_17 ( & V_2 -> V_38 . V_39 ) ;
return V_68 ;
}
static int F_75 ( struct V_20 * V_21 ,
struct V_110 * V_111 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
struct V_112 V_113 ;
unsigned long V_22 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_113 = V_2 -> V_111 ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_111 -> V_114 = V_113 . V_114 ;
V_111 -> V_115 = V_113 . V_115 ;
V_111 -> V_116 = V_113 . V_116 ;
V_111 -> V_117 = V_113 . V_117 ;
V_111 -> V_118 = V_113 . V_118 ;
V_111 -> V_119 = V_113 . V_119 ;
V_111 -> V_120 = V_113 . V_120 ;
V_111 -> V_121 = V_113 . V_121 ;
V_111 -> V_122 = V_113 . V_122 ;
V_111 -> V_123 = V_113 . V_123 ;
V_111 -> V_124 = V_113 . V_124 ;
return 0 ;
}
static long F_76 ( struct V_1 * V_2 , struct V_125 T_2 * V_126 )
{
struct V_125 V_127 ;
F_13 ( ( L_47 , V_2 -> V_8 ) ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_63 = ( V_128 ) V_2 -> V_62 . V_63 ;
V_127 . V_129 = V_2 -> V_62 . V_129 ;
V_127 . V_22 = V_2 -> V_62 . V_22 ;
V_127 . V_130 = V_2 -> V_62 . V_130 ;
V_127 . V_131 = ( V_128 ) V_2 -> V_62 . V_131 ;
V_127 . V_132 = V_2 -> V_62 . V_132 ;
V_127 . V_133 = V_2 -> V_62 . V_133 ;
V_127 . V_134 = V_2 -> V_62 . V_134 ;
V_127 . V_135 = V_2 -> V_62 . V_135 ;
V_127 . V_79 = ( V_128 ) V_2 -> V_62 . V_79 ;
V_127 . V_136 = V_2 -> V_62 . V_136 ;
V_127 . V_137 = V_2 -> V_62 . V_137 ;
V_127 . V_122 = V_2 -> V_62 . V_122 ;
if ( F_77 ( V_126 , & V_127 , sizeof( struct V_125 ) ) )
return - V_138 ;
return 0 ;
}
static long F_78 ( struct V_1 * V_2 , struct V_125 T_2 * V_139 )
{
struct V_125 V_127 ;
F_13 ( ( L_48 , V_2 -> V_8 ) ) ;
if ( F_79 ( & V_127 , V_139 , sizeof( struct V_125 ) ) )
return - V_138 ;
F_80 ( & V_2 -> V_49 ) ;
if ( V_127 . V_63 == V_140 ) {
V_2 -> V_141 = V_127 . V_131 ;
} else {
V_2 -> V_62 . V_63 = V_127 . V_63 ;
V_2 -> V_62 . V_129 = V_127 . V_129 ;
V_2 -> V_62 . V_22 = V_127 . V_22 ;
V_2 -> V_62 . V_130 = V_127 . V_130 ;
V_2 -> V_62 . V_131 = V_127 . V_131 ;
V_2 -> V_62 . V_132 = V_127 . V_132 ;
V_2 -> V_62 . V_133 = V_127 . V_133 ;
V_2 -> V_62 . V_134 = V_127 . V_134 ;
V_2 -> V_62 . V_135 = V_127 . V_135 ;
V_2 -> V_62 . V_79 = V_127 . V_79 ;
V_2 -> V_62 . V_136 = V_127 . V_136 ;
V_2 -> V_62 . V_137 = V_127 . V_137 ;
V_2 -> V_62 . V_122 = V_127 . V_122 ;
}
F_81 ( & V_2 -> V_49 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static long F_83 ( struct V_20 * V_21 ,
unsigned int V_84 , unsigned long V_85 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_142 = - V_109 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_49 ) )
return - V_33 ;
F_13 ( ( L_50 , V_2 -> V_8 , V_84 ) ) ;
switch ( V_84 ) {
case V_143 :
V_142 = F_78 ( V_2 , F_84 ( V_85 ) ) ;
break;
case V_144 :
V_142 = F_76 ( V_2 , F_84 ( V_85 ) ) ;
break;
case V_99 :
case V_100 :
case V_101 :
case V_106 :
case V_91 :
case V_107 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_97 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_89 :
case V_108 :
case V_96 :
case V_98 :
V_142 = F_55 ( V_21 , V_84 , V_85 ) ;
break;
}
F_13 ( ( L_51 , V_2 -> V_8 , V_84 , V_142 ) ) ;
return V_142 ;
}
static inline void F_85 ( struct V_145 * V_146 , struct V_1 * V_2 )
{
char V_147 [ 30 ] ;
unsigned long V_22 ;
F_86 ( V_146 , L_52 ,
V_2 -> V_8 , V_2 -> V_148 ,
V_2 -> V_149 , V_2 -> V_71 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_87 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_147 [ 0 ] = 0 ;
V_147 [ 1 ] = 0 ;
if ( V_2 -> V_56 & V_57 )
strcat ( V_147 , L_53 ) ;
if ( V_2 -> V_56 & V_150 )
strcat ( V_147 , L_54 ) ;
if ( V_2 -> V_56 & V_58 )
strcat ( V_147 , L_55 ) ;
if ( V_2 -> V_56 & V_151 )
strcat ( V_147 , L_56 ) ;
if ( V_2 -> V_56 & V_152 )
strcat ( V_147 , L_57 ) ;
if ( V_2 -> V_56 & V_153 )
strcat ( V_147 , L_58 ) ;
if ( V_2 -> V_62 . V_63 != V_83 ) {
F_86 ( V_146 , L_59 ,
V_2 -> V_111 . V_154 , V_2 -> V_111 . V_155 ) ;
if ( V_2 -> V_111 . V_156 )
F_86 ( V_146 , L_60 , V_2 -> V_111 . V_156 ) ;
if ( V_2 -> V_111 . V_157 )
F_86 ( V_146 , L_61 , V_2 -> V_111 . V_157 ) ;
if ( V_2 -> V_111 . V_158 )
F_86 ( V_146 , L_62 , V_2 -> V_111 . V_158 ) ;
if ( V_2 -> V_111 . V_159 )
F_86 ( V_146 , L_63 , V_2 -> V_111 . V_159 ) ;
if ( V_2 -> V_111 . V_160 )
F_86 ( V_146 , L_64 , V_2 -> V_111 . V_160 ) ;
if ( V_2 -> V_111 . V_161 )
F_86 ( V_146 , L_65 , V_2 -> V_111 . V_161 ) ;
} else {
F_86 ( V_146 , L_66 ,
V_2 -> V_111 . V_119 , V_2 -> V_111 . V_118 ) ;
if ( V_2 -> V_111 . V_120 )
F_86 ( V_146 , L_67 , V_2 -> V_111 . V_120 ) ;
if ( V_2 -> V_111 . V_122 )
F_86 ( V_146 , L_68 , V_2 -> V_111 . V_122 ) ;
if ( V_2 -> V_111 . V_123 )
F_86 ( V_146 , L_69 , V_2 -> V_111 . V_123 ) ;
if ( V_2 -> V_111 . V_121 )
F_86 ( V_146 , L_70 , V_2 -> V_111 . V_121 ) ;
}
F_86 ( V_146 , L_71 , V_147 + 1 ) ;
F_86 ( V_146 , L_72 ,
V_2 -> V_80 , V_2 -> V_162 , V_2 -> V_163 ,
V_2 -> V_164 ) ;
}
static int F_88 ( struct V_145 * V_146 , void * V_165 )
{
struct V_1 * V_2 ;
F_89 ( V_146 , L_73 ) ;
V_2 = V_34 ;
while( V_2 ) {
F_85 ( V_146 , V_2 ) ;
V_2 = V_2 -> V_35 ;
}
return 0 ;
}
static int F_90 ( struct V_166 * V_166 , struct V_27 * V_27 )
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
if ( F_33 ( V_21 ) ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_56 &= ~ V_57 ;
F_32 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
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
if ( V_2 -> V_75 )
V_2 -> V_75 = 0 ;
else
F_43 ( V_21 , F_97 ( V_21 ) ) ;
}
if ( F_33 ( V_21 ) ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_56 |= V_57 ;
F_32 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
}
static int F_98 ( struct V_20 * V_21 , int V_167 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned short V_168 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_80 ) )
return - V_169 ;
F_13 ( ( L_81 , V_2 -> V_8 , V_167 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_168 = F_99 ( V_2 , V_170 ) ;
if ( V_167 == - 1 )
V_168 |= V_171 ;
else
V_168 &= ~ V_171 ;
F_100 ( V_2 , V_170 , V_168 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_101 ( struct V_172 * V_173 , unsigned short V_130 ,
unsigned short V_122 )
{
struct V_1 * V_2 = F_102 ( V_173 ) ;
unsigned char V_174 ;
unsigned short V_175 ;
if ( V_2 -> V_38 . V_4 )
return - V_44 ;
F_13 ( ( L_82 , V_2 -> V_8 ) ) ;
switch ( V_130 )
{
case V_176 : V_174 = V_177 ; break;
case V_178 : V_174 = V_179 ; break;
case V_180 : V_174 = V_181 ; break;
case V_182 : V_174 = V_183 ; break;
case V_184 : V_174 = V_185 ; break;
default: return - V_169 ;
}
switch ( V_122 )
{
case V_186 : V_175 = V_187 ; break;
case V_188 : V_175 = V_189 ; break;
case V_190 : V_175 = V_191 ; break;
default: return - V_169 ;
}
V_2 -> V_62 . V_130 = V_174 ;
V_2 -> V_62 . V_133 = V_175 ;
if ( V_2 -> V_43 )
F_82 ( V_2 ) ;
return 0 ;
}
static T_3 F_103 ( struct V_192 * V_193 ,
struct V_172 * V_173 )
{
struct V_1 * V_2 = F_102 ( V_173 ) ;
unsigned long V_22 ;
F_13 ( ( L_83 , V_173 -> V_17 ) ) ;
if ( ! V_193 -> V_194 )
return V_195 ;
F_104 ( V_173 ) ;
V_173 -> V_196 . V_197 ++ ;
V_173 -> V_196 . V_198 += V_193 -> V_194 ;
V_173 -> V_199 = V_66 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_41 ( V_2 , V_193 -> V_3 , V_193 -> V_194 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_105 ( V_193 ) ;
return V_195 ;
}
static int F_106 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = F_102 ( V_173 ) ;
int V_142 ;
unsigned long V_22 ;
if ( ! F_107 ( V_200 ) )
return - V_44 ;
F_13 ( ( L_84 , V_173 -> V_17 ) ) ;
V_142 = F_108 ( V_173 ) ;
if ( V_142 )
return V_142 ;
F_15 ( & V_2 -> V_42 , V_22 ) ;
if ( V_2 -> V_38 . V_4 != 0 || V_2 -> V_43 != 0 ) {
F_13 ( ( L_85 , V_173 -> V_17 ) ) ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
return - V_44 ;
}
V_2 -> V_43 = 1 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
if ( ( V_142 = F_18 ( V_2 ) ) != 0 ) {
F_15 ( & V_2 -> V_42 , V_22 ) ;
V_2 -> V_43 = 0 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
return V_142 ;
}
V_2 -> V_56 |= V_57 | V_58 ;
F_82 ( V_2 ) ;
V_173 -> V_199 = V_66 ;
F_109 ( V_173 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_87 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_56 & V_152 )
F_110 ( V_173 ) ;
else
F_111 ( V_173 ) ;
return 0 ;
}
static int F_112 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = F_102 ( V_173 ) ;
unsigned long V_22 ;
F_13 ( ( L_86 , V_173 -> V_17 ) ) ;
F_104 ( V_173 ) ;
F_25 ( V_2 ) ;
F_113 ( V_173 ) ;
F_15 ( & V_2 -> V_42 , V_22 ) ;
V_2 -> V_43 = 0 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
F_114 ( V_200 ) ;
return 0 ;
}
static int F_115 ( struct V_172 * V_173 , struct V_201 * V_202 , int V_84 )
{
const T_4 V_203 = sizeof( V_204 ) ;
V_204 V_205 ;
V_204 T_2 * line = V_202 -> V_206 . V_207 . V_208 ;
struct V_1 * V_2 = F_102 ( V_173 ) ;
unsigned int V_22 ;
F_13 ( ( L_87 , V_173 -> V_17 ) ) ;
if ( V_2 -> V_38 . V_4 )
return - V_44 ;
if ( V_84 != V_209 )
return F_116 ( V_173 , V_202 , V_84 ) ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
switch( V_202 -> V_206 . type ) {
case V_210 :
V_202 -> V_206 . type = V_211 ;
if ( V_202 -> V_206 . V_203 < V_203 ) {
V_202 -> V_206 . V_203 = V_203 ;
return - V_212 ;
}
V_22 = V_2 -> V_62 . V_22 & ( V_213 | V_214 |
V_215 | V_216 |
V_217 | V_218 |
V_219 | V_220 ) ;
switch ( V_22 ) {
case ( V_213 | V_217 ) : V_205 . V_221 = V_222 ; break;
case ( V_215 | V_219 ) : V_205 . V_221 = V_223 ; break;
case ( V_213 | V_219 ) : V_205 . V_221 = V_224 ; break;
case ( V_213 | V_220 ) : V_205 . V_221 = V_225 ; break;
default: V_205 . V_221 = V_226 ;
}
V_205 . V_227 = V_2 -> V_62 . V_131 ;
V_205 . V_129 = V_2 -> V_62 . V_129 ? 1 : 0 ;
if ( F_77 ( line , & V_205 , V_203 ) )
return - V_138 ;
return 0 ;
case V_211 :
if( ! F_117 ( V_228 ) )
return - V_229 ;
if ( F_79 ( & V_205 , line , V_203 ) )
return - V_138 ;
switch ( V_205 . V_221 )
{
case V_222 : V_22 = V_213 | V_217 ; break;
case V_225 : V_22 = V_213 | V_220 ; break;
case V_223 : V_22 = V_215 | V_219 ; break;
case V_224 : V_22 = V_213 | V_219 ; break;
case V_226 : V_22 = V_2 -> V_62 . V_22 &
( V_213 | V_214 |
V_215 | V_216 |
V_217 | V_218 |
V_219 | V_220 ) ; break;
default: return - V_169 ;
}
if ( V_205 . V_129 != 0 && V_205 . V_129 != 1 )
return - V_169 ;
V_2 -> V_62 . V_22 &= ~ ( V_213 | V_214 |
V_215 | V_216 |
V_217 | V_218 |
V_219 | V_220 ) ;
V_2 -> V_62 . V_22 |= V_22 ;
V_2 -> V_62 . V_129 = V_205 . V_129 ;
if ( V_22 & ( V_215 | V_219 ) )
V_2 -> V_62 . V_131 = V_205 . V_227 ;
else
V_2 -> V_62 . V_131 = 0 ;
if ( V_2 -> V_43 )
F_82 ( V_2 ) ;
return 0 ;
default:
return F_116 ( V_173 , V_202 , V_84 ) ;
}
}
static void F_118 ( struct V_172 * V_173 )
{
struct V_1 * V_2 = F_102 ( V_173 ) ;
unsigned long V_22 ;
F_13 ( ( L_88 , V_173 -> V_17 ) ) ;
V_173 -> V_196 . V_230 ++ ;
V_173 -> V_196 . V_231 ++ ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_54 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_119 ( V_173 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
if ( F_121 ( V_2 -> V_232 ) )
F_119 ( V_2 -> V_232 ) ;
}
static void F_122 ( struct V_1 * V_2 , char * V_67 , int V_203 )
{
struct V_192 * V_193 = F_123 ( V_203 ) ;
struct V_172 * V_173 = V_2 -> V_232 ;
F_13 ( ( L_89 , V_173 -> V_17 ) ) ;
if ( V_193 == NULL ) {
F_12 ( ( L_90 , V_173 -> V_17 ) ) ;
V_173 -> V_196 . V_233 ++ ;
return;
}
memcpy ( F_124 ( V_193 , V_203 ) , V_67 , V_203 ) ;
V_193 -> V_234 = F_125 ( V_193 , V_173 ) ;
V_173 -> V_196 . V_235 ++ ;
V_173 -> V_196 . V_236 += V_203 ;
F_126 ( V_193 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_142 ;
struct V_172 * V_173 ;
T_5 * V_237 ;
V_173 = F_128 ( V_2 ) ;
if ( ! V_173 ) {
F_2 ( V_238 L_91 , V_2 -> V_8 ) ;
return - V_239 ;
}
V_173 -> V_240 = V_2 -> V_148 ;
V_173 -> V_241 = V_2 -> V_148 + V_242 - 1 ;
V_173 -> V_243 = V_2 -> V_149 ;
V_173 -> V_244 = & V_245 ;
V_173 -> V_246 = 10 * V_247 ;
V_173 -> V_248 = 50 ;
V_237 = F_129 ( V_173 ) ;
V_237 -> V_249 = F_101 ;
V_237 -> V_250 = F_103 ;
V_142 = F_130 ( V_173 ) ;
if ( V_142 ) {
F_2 ( V_251 L_92 , __FILE__ ) ;
F_131 ( V_173 ) ;
return V_142 ;
}
V_2 -> V_232 = V_173 ;
return 0 ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_133 ( V_2 -> V_232 ) ;
F_131 ( V_2 -> V_232 ) ;
V_2 -> V_232 = NULL ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_112 * V_111 = & V_2 -> V_111 ;
unsigned int V_252 , V_253 ;
unsigned char * V_254 ;
unsigned char V_12 ;
struct V_255 * V_256 = V_2 -> V_15 ;
int V_6 , V_4 ;
int V_257 = 0 ;
int V_258 ;
unsigned char V_74 ;
V_252 = V_253 = V_2 -> V_13 ;
while( F_135 ( V_256 [ V_253 ] ) ) {
V_4 = F_136 ( V_256 [ V_253 ] ) - V_2 -> V_259 ;
V_254 = V_256 [ V_253 ] . V_67 + V_2 -> V_259 ;
F_137 ( ( L_93 , V_2 -> V_8 , V_4 ) ) ;
F_138 ( V_2 , V_254 , V_4 , L_94 ) ;
for( V_6 = 0 ; V_6 < V_4 ; V_6 += 2 , V_254 += 2 ) {
V_74 = * V_254 ;
V_111 -> V_118 ++ ;
V_258 = 0 ;
V_12 = * ( V_254 + 1 ) & ( V_260 + V_261 ) ;
if ( V_12 ) {
if ( V_12 & V_260 )
V_111 -> V_122 ++ ;
else if ( V_12 & V_261 )
V_111 -> V_120 ++ ;
if ( V_12 & V_2 -> V_262 )
continue;
if ( V_12 & V_260 )
V_258 = V_263 ;
else if ( V_12 & V_261 )
V_258 = V_264 ;
}
F_139 ( & V_2 -> V_38 , V_74 , V_258 ) ;
V_257 ++ ;
}
if ( V_6 < V_4 ) {
V_2 -> V_259 += V_6 ;
F_38 ( & V_2 -> V_265 , V_66 + 1 ) ;
break;
}
V_2 -> V_259 = 0 ;
F_140 ( V_2 , V_253 , V_253 ) ;
if ( ++ V_253 == V_2 -> V_14 )
V_253 = 0 ;
if ( V_253 == V_252 )
break;
}
if ( V_257 )
F_141 ( & V_2 -> V_38 ) ;
}
static int F_142 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
int V_142 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_164 & V_266 ) {
V_2 -> V_164 &= ~ V_266 ;
V_142 = V_266 ;
} else if ( V_2 -> V_164 & V_267 ) {
V_2 -> V_164 &= ~ V_267 ;
V_142 = V_267 ;
} else if ( V_2 -> V_164 & V_268 ) {
V_2 -> V_164 &= ~ V_268 ;
V_142 = V_268 ;
} else {
V_2 -> V_163 = false ;
V_2 -> V_162 = false ;
V_142 = 0 ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
return V_142 ;
}
static void F_143 ( struct V_269 * V_270 )
{
struct V_1 * V_2 = F_144 ( V_270 , struct V_1 , V_271 ) ;
int V_272 ;
V_2 -> V_163 = true ;
while( ( V_272 = F_142 ( V_2 ) ) ) {
switch ( V_272 ) {
case V_266 :
F_145 ( ( L_95 , V_2 -> V_8 ) ) ;
switch( V_2 -> V_62 . V_63 ) {
case V_83 :
F_134 ( V_2 ) ;
break;
case V_64 :
while( F_146 ( V_2 ) ) ;
break;
case V_273 :
case V_274 :
case V_275 :
case V_276 :
while( F_147 ( V_2 ) ) ;
break;
}
if ( V_2 -> V_277 )
F_148 ( V_2 ) ;
break;
case V_267 :
F_149 ( V_2 ) ;
break;
case V_268 :
F_145 ( ( L_96 , V_2 -> V_8 ) ) ;
V_2 -> V_278 = 0 ;
V_2 -> V_279 = 0 ;
V_2 -> V_280 = 0 ;
V_2 -> V_281 = 0 ;
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
if ( V_12 & V_282 ) {
V_2 -> V_56 |= V_151 ;
V_2 -> V_283 . V_284 ++ ;
} else {
V_2 -> V_56 &= ~ V_151 ;
V_2 -> V_283 . V_285 ++ ;
}
F_137 ( ( L_100 , V_2 -> V_8 , V_2 -> V_56 ) ) ;
if ( ( V_2 -> V_279 ) ++ == V_286 ) {
F_151 ( V_2 , V_287 ) ;
return;
}
V_2 -> V_111 . V_115 ++ ;
F_28 ( & V_2 -> V_288 ) ;
F_28 ( & V_2 -> V_289 ) ;
V_2 -> V_164 |= V_268 ;
}
static void F_152 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_290 ) {
V_2 -> V_56 |= V_150 ;
V_2 -> V_283 . V_291 ++ ;
} else {
V_2 -> V_56 &= ~ V_150 ;
V_2 -> V_283 . V_292 ++ ;
}
F_137 ( ( L_101 , V_2 -> V_8 , V_2 -> V_56 ) ) ;
if ( ( V_2 -> V_281 ) ++ == V_286 ) {
F_151 ( V_2 , V_293 ) ;
return;
}
V_2 -> V_111 . V_114 ++ ;
F_28 ( & V_2 -> V_288 ) ;
F_28 ( & V_2 -> V_289 ) ;
V_2 -> V_164 |= V_268 ;
if ( F_153 ( & V_2 -> V_38 ) ) {
if ( V_2 -> V_38 . V_21 ) {
if ( V_2 -> V_38 . V_21 -> V_61 ) {
if ( V_2 -> V_56 & V_150 ) {
V_2 -> V_38 . V_21 -> V_61 = 0 ;
V_2 -> V_164 |= V_267 ;
return;
}
} else {
if ( ! ( V_2 -> V_56 & V_150 ) )
V_2 -> V_38 . V_21 -> V_61 = 1 ;
}
}
}
}
static void F_154 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_260 ) {
V_2 -> V_56 |= V_152 ;
V_2 -> V_283 . V_294 ++ ;
} else {
V_2 -> V_56 &= ~ V_152 ;
V_2 -> V_283 . V_295 ++ ;
}
F_137 ( ( L_102 , V_2 -> V_8 , V_2 -> V_56 ) ) ;
if ( ( V_2 -> V_280 ) ++ == V_286 ) {
F_151 ( V_2 , V_296 ) ;
return;
}
V_2 -> V_111 . V_117 ++ ;
#if V_297
if ( V_2 -> V_43 ) {
if ( V_2 -> V_56 & V_152 )
F_110 ( V_2 -> V_232 ) ;
else
F_111 ( V_2 -> V_232 ) ;
}
#endif
F_28 ( & V_2 -> V_288 ) ;
F_28 ( & V_2 -> V_289 ) ;
V_2 -> V_164 |= V_268 ;
if ( V_2 -> V_38 . V_22 & V_298 ) {
if ( V_2 -> V_56 & V_152 )
F_28 ( & V_2 -> V_38 . V_51 ) ;
else {
if ( V_2 -> V_38 . V_21 )
F_155 ( V_2 -> V_38 . V_21 ) ;
}
}
}
static void F_156 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_261 ) {
V_2 -> V_56 |= V_153 ;
V_2 -> V_283 . V_299 ++ ;
} else {
V_2 -> V_56 &= ~ V_153 ;
V_2 -> V_283 . V_300 ++ ;
}
F_137 ( ( L_103 , V_2 -> V_8 , V_2 -> V_56 ) ) ;
if ( ( V_2 -> V_278 ) ++ == V_286 ) {
F_151 ( V_2 , V_301 ) ;
return;
}
V_2 -> V_111 . V_116 ++ ;
F_28 ( & V_2 -> V_288 ) ;
F_28 ( & V_2 -> V_289 ) ;
V_2 -> V_164 |= V_268 ;
}
static void F_157 ( struct V_1 * V_2 )
{
unsigned int V_4 = V_2 -> V_302 ;
unsigned int V_6 = V_2 -> V_303 ;
unsigned short V_304 ;
while ( F_99 ( V_2 , V_305 ) & V_306 ) {
V_304 = F_99 ( V_2 , V_307 ) ;
F_137 ( ( L_104 , V_2 -> V_8 , V_304 ) ) ;
if ( F_135 ( V_2 -> V_15 [ V_6 ] ) ) {
F_158 ( V_2 ) ;
V_2 -> V_277 = 1 ;
continue;
}
V_2 -> V_15 [ V_6 ] . V_67 [ V_4 ++ ] = ( unsigned char ) V_304 ;
if ( V_2 -> V_62 . V_63 == V_83 )
V_2 -> V_15 [ V_6 ] . V_67 [ V_4 ++ ] = ( unsigned char ) ( V_304 >> 8 ) ;
if ( V_4 == V_2 -> V_308 || ( V_304 & V_309 ) ) {
F_159 ( V_2 -> V_15 [ V_6 ] , V_4 ) ;
F_160 ( V_2 -> V_15 [ V_6 ] , V_310 | ( V_304 >> 8 ) ) ;
V_2 -> V_302 = V_4 = 0 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
V_2 -> V_164 |= V_266 ;
}
}
V_2 -> V_303 = V_6 ;
V_2 -> V_302 = V_4 ;
}
static void F_161 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_99 ( V_2 , V_305 ) ;
F_137 ( ( L_105 , V_2 -> V_8 , V_12 ) ) ;
F_100 ( V_2 , V_305 , V_12 ) ;
V_2 -> V_311 = true ;
if ( V_2 -> V_62 . V_63 == V_83 ) {
if ( V_12 & V_312 ) {
if ( V_2 -> V_80 )
F_162 ( V_2 , V_12 ) ;
}
if ( V_2 -> V_313 && ( V_12 & V_306 ) )
F_157 ( V_2 ) ;
if ( ( V_12 & V_314 ) && ( V_12 & V_315 ) ) {
V_2 -> V_111 . V_123 ++ ;
if ( V_2 -> V_38 . V_21 ) {
if ( ! ( V_12 & V_2 -> V_262 ) ) {
if ( V_2 -> V_316 & V_317 ) {
F_139 ( & V_2 -> V_38 , 0 , V_318 ) ;
if ( V_2 -> V_38 . V_22 & V_319 )
F_163 ( V_2 -> V_38 . V_21 ) ;
}
}
}
}
} else {
if ( V_12 & ( V_312 + V_320 ) )
F_162 ( V_2 , V_12 ) ;
if ( V_2 -> V_313 && ( V_12 & V_306 ) )
F_157 ( V_2 ) ;
if ( V_12 & V_321 ) {
if ( V_12 & V_322 )
V_2 -> V_111 . V_323 ++ ;
else
V_2 -> V_111 . V_324 ++ ;
F_28 ( & V_2 -> V_289 ) ;
}
if ( V_12 & V_325 )
F_148 ( V_2 ) ;
}
if ( V_12 & V_287 )
F_150 ( V_2 , V_12 ) ;
if ( V_12 & V_293 )
F_152 ( V_2 , V_12 ) ;
if ( V_12 & V_296 )
F_154 ( V_2 , V_12 ) ;
if ( V_12 & V_301 )
F_156 ( V_2 , V_12 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_165 ( V_2 , V_326 ) ;
F_137 ( ( L_106 , V_2 -> V_8 , V_12 ) ) ;
F_166 ( V_2 , V_326 , V_12 ) ;
if ( V_12 & ( V_327 + V_328 ) ) {
F_137 ( ( L_107 , V_2 -> V_8 ) ) ;
V_2 -> V_277 = true ;
}
V_2 -> V_164 |= V_266 ;
}
static void F_167 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_165 ( V_2 , V_329 ) ;
F_137 ( ( L_108 , V_2 -> V_8 , V_12 ) ) ;
F_166 ( V_2 , V_329 , V_12 ) ;
if ( V_12 & ( V_327 + V_328 + V_282 ) ) {
V_2 -> V_164 |= V_267 ;
}
}
static bool F_168 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_2 -> V_9 ;
bool V_142 = false ;
do {
if ( V_6 )
V_6 -- ;
else
V_6 = V_2 -> V_10 - 1 ;
if ( ! F_136 ( V_2 -> V_11 [ V_6 ] ) )
break;
V_2 -> V_330 = V_6 ;
V_142 = true ;
} while ( V_6 != V_2 -> V_9 );
return V_142 ;
}
static void F_162 ( struct V_1 * V_2 , unsigned short V_12 )
{
F_137 ( ( L_109 , V_2 -> V_8 , V_12 ) ) ;
F_151 ( V_2 , V_331 + V_312 + V_320 ) ;
F_169 ( V_2 ) ;
if ( V_12 & V_320 ) {
unsigned short V_332 = F_99 ( V_2 , V_170 ) ;
F_100 ( V_2 , V_170 , ( unsigned short ) ( V_332 | V_290 ) ) ;
F_100 ( V_2 , V_170 , V_332 ) ;
}
if ( V_2 -> V_80 ) {
if ( V_2 -> V_62 . V_63 != V_83 ) {
if ( V_12 & V_320 )
V_2 -> V_111 . V_156 ++ ;
else if ( V_12 & V_312 )
V_2 -> V_111 . V_154 ++ ;
}
if ( F_168 ( V_2 ) ) {
F_44 ( V_2 ) ;
F_36 ( V_2 ) ;
return;
}
V_2 -> V_80 = false ;
F_170 ( & V_2 -> V_65 ) ;
if ( V_2 -> V_62 . V_63 != V_83 && V_2 -> V_333 ) {
V_2 -> V_56 &= ~ V_57 ;
V_2 -> V_333 = false ;
F_32 ( V_2 ) ;
}
#if V_297
if ( V_2 -> V_43 )
F_120 ( V_2 ) ;
else
#endif
{
if ( V_2 -> V_38 . V_21 && ( V_2 -> V_38 . V_21 -> V_72 || V_2 -> V_38 . V_21 -> V_61 ) ) {
F_54 ( V_2 ) ;
return;
}
V_2 -> V_164 |= V_267 ;
}
}
}
static void F_171 ( struct V_1 * V_2 , unsigned int V_334 , unsigned int V_335 )
{
struct V_336 * V_337 , * V_338 ;
for ( V_337 = V_2 -> V_339 , V_338 = NULL ; V_337 != NULL ; V_337 = V_337 -> V_340 ) {
if ( V_337 -> V_3 & V_334 ) {
V_337 -> V_3 = V_335 ;
F_28 ( & V_337 -> V_341 ) ;
if ( V_338 != NULL )
V_338 -> V_340 = V_337 -> V_340 ;
else
V_2 -> V_339 = V_337 -> V_340 ;
} else
V_338 = V_337 ;
}
}
static T_6 F_172 ( int V_342 , void * V_343 )
{
struct V_1 * V_2 = V_343 ;
unsigned int V_344 ;
unsigned int V_6 ;
F_137 ( ( L_110 , V_2 -> V_149 ) ) ;
while( ( V_344 = F_165 ( V_2 , V_345 ) & 0xffffff00 ) ) {
F_137 ( ( L_111 , V_2 -> V_8 , V_344 ) ) ;
V_2 -> V_311 = true ;
for( V_6 = 0 ; V_6 < V_2 -> V_346 ; V_6 ++ ) {
if ( V_2 -> V_347 [ V_6 ] == NULL )
continue;
F_80 ( & V_2 -> V_347 [ V_6 ] -> V_49 ) ;
if ( V_344 & ( V_348 << V_6 ) )
F_161 ( V_2 -> V_347 [ V_6 ] ) ;
if ( V_344 & ( V_349 << ( V_6 * 2 ) ) )
F_164 ( V_2 -> V_347 [ V_6 ] ) ;
if ( V_344 & ( V_350 << ( V_6 * 2 ) ) )
F_167 ( V_2 -> V_347 [ V_6 ] ) ;
F_81 ( & V_2 -> V_347 [ V_6 ] -> V_49 ) ;
}
}
if ( V_2 -> V_351 ) {
unsigned int V_335 ;
unsigned int V_334 ;
F_80 ( & V_2 -> V_49 ) ;
while ( ( V_334 = F_165 ( V_2 , V_352 ) ) != 0 ) {
F_137 ( ( L_112 , V_2 -> V_8 , V_334 ) ) ;
V_335 = F_165 ( V_2 , V_353 ) ;
F_166 ( V_2 , V_352 , V_334 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_346 ; V_6 ++ ) {
if ( V_2 -> V_347 [ V_6 ] != NULL )
F_171 ( V_2 -> V_347 [ V_6 ] , V_334 , V_335 ) ;
}
}
F_81 ( & V_2 -> V_49 ) ;
}
for( V_6 = 0 ; V_6 < V_2 -> V_346 ; V_6 ++ ) {
struct V_1 * V_38 = V_2 -> V_347 [ V_6 ] ;
if ( V_38 == NULL )
continue;
F_80 ( & V_38 -> V_49 ) ;
if ( ( V_38 -> V_38 . V_4 || V_38 -> V_43 ) &&
V_38 -> V_164 && ! V_38 -> V_163 &&
! V_38 -> V_162 ) {
F_137 ( ( L_113 , V_38 -> V_8 ) ) ;
F_173 ( & V_38 -> V_271 ) ;
V_38 -> V_162 = true ;
}
F_81 ( & V_38 -> V_49 ) ;
}
F_137 ( ( L_114 , V_2 -> V_149 ) ) ;
return V_354 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_13 ( ( L_115 , V_2 -> V_8 ) ) ;
if ( V_2 -> V_38 . V_22 & V_46 )
return 0 ;
if ( ! V_2 -> V_70 ) {
V_2 -> V_70 = F_174 ( V_2 -> V_71 , V_355 ) ;
if ( ! V_2 -> V_70 ) {
F_12 ( ( L_116 , V_2 -> V_8 ) ) ;
return - V_239 ;
}
}
V_2 -> V_164 = 0 ;
memset ( & V_2 -> V_111 , 0 , sizeof( V_2 -> V_111 ) ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_38 . V_21 )
F_175 ( V_90 , & V_2 -> V_38 . V_21 -> V_22 ) ;
V_2 -> V_38 . V_22 |= V_46 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
if ( ! ( V_2 -> V_38 . V_22 & V_46 ) )
return;
F_13 ( ( L_117 , V_2 -> V_8 ) ) ;
F_28 ( & V_2 -> V_288 ) ;
F_28 ( & V_2 -> V_289 ) ;
F_176 ( & V_2 -> V_65 ) ;
F_176 ( & V_2 -> V_265 ) ;
F_177 ( V_2 -> V_70 ) ;
V_2 -> V_70 = NULL ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_54 ( V_2 ) ;
F_158 ( V_2 ) ;
F_151 ( V_2 , V_356 | V_357 ) ;
if ( ! V_2 -> V_38 . V_21 || V_2 -> V_38 . V_21 -> V_358 . V_54 & V_359 ) {
V_2 -> V_56 &= ~ ( V_57 | V_58 ) ;
F_32 ( V_2 ) ;
}
F_178 ( & V_2 -> V_339 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
if ( V_2 -> V_38 . V_21 )
F_179 ( V_90 , & V_2 -> V_38 . V_21 -> V_22 ) ;
V_2 -> V_38 . V_22 &= ~ V_46 ;
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_158 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_62 . V_63 != V_83 ||
V_2 -> V_43 )
F_180 ( V_2 ) ;
else
F_181 ( V_2 ) ;
F_32 ( V_2 ) ;
V_2 -> V_280 = 0 ;
V_2 -> V_281 = 0 ;
V_2 -> V_278 = 0 ;
V_2 -> V_279 = 0 ;
F_182 ( V_2 , V_296 | V_293 | V_287 | V_301 ) ;
F_87 ( V_2 ) ;
if ( V_2 -> V_43 ||
( V_2 -> V_38 . V_21 && V_2 -> V_38 . V_21 -> V_358 . V_54 & V_360 ) )
F_148 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned V_361 ;
int V_362 ;
if ( ! V_2 -> V_38 . V_21 )
return;
F_13 ( ( L_118 , V_2 -> V_8 ) ) ;
V_361 = V_2 -> V_38 . V_21 -> V_358 . V_54 ;
if ( V_361 & V_55 )
V_2 -> V_56 |= V_57 | V_58 ;
else
V_2 -> V_56 &= ~ ( V_57 | V_58 ) ;
switch ( V_361 & V_363 ) {
case V_364 : V_2 -> V_62 . V_136 = 5 ; break;
case V_365 : V_2 -> V_62 . V_136 = 6 ; break;
case V_366 : V_2 -> V_62 . V_136 = 7 ; break;
case V_367 : V_2 -> V_62 . V_136 = 8 ; break;
default: V_2 -> V_62 . V_136 = 7 ; break;
}
V_2 -> V_62 . V_137 = ( V_361 & V_368 ) ? 2 : 1 ;
if ( V_361 & V_369 )
V_2 -> V_62 . V_122 = ( V_361 & V_370 ) ? V_371 : V_372 ;
else
V_2 -> V_62 . V_122 = V_373 ;
V_362 = V_2 -> V_62 . V_136 +
V_2 -> V_62 . V_137 + 1 ;
V_2 -> V_62 . V_79 = F_183 ( V_2 -> V_38 . V_21 ) ;
if ( V_2 -> V_62 . V_79 ) {
V_2 -> V_47 = ( 32 * V_247 * V_362 ) /
V_2 -> V_62 . V_79 ;
}
V_2 -> V_47 += V_247 / 50 ;
if ( V_361 & V_60 )
V_2 -> V_38 . V_22 |= V_374 ;
else
V_2 -> V_38 . V_22 &= ~ V_374 ;
if ( V_361 & V_375 )
V_2 -> V_38 . V_22 &= ~ V_298 ;
else
V_2 -> V_38 . V_22 |= V_298 ;
V_2 -> V_316 = V_325 ;
if ( F_184 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_316 |= V_376 | V_377 ;
if ( F_185 ( V_2 -> V_38 . V_21 ) || F_186 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_316 |= V_317 ;
if ( F_187 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_262 |= V_376 | V_377 ;
if ( F_188 ( V_2 -> V_38 . V_21 ) ) {
V_2 -> V_262 |= V_317 ;
if ( F_187 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_262 |= V_378 ;
}
F_82 ( V_2 ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_112 T_2 * V_379 )
{
F_13 ( ( L_119 , V_2 -> V_8 ) ) ;
if ( ! V_379 ) {
memset ( & V_2 -> V_111 , 0 , sizeof( V_2 -> V_111 ) ) ;
} else {
if ( F_77 ( V_379 , & V_2 -> V_111 , sizeof( struct V_112 ) ) )
return - V_138 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , T_7 T_2 * V_126 )
{
F_13 ( ( L_120 , V_2 -> V_8 ) ) ;
if ( F_77 ( V_126 , & V_2 -> V_62 , sizeof( T_7 ) ) )
return - V_138 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , T_7 T_2 * V_139 )
{
unsigned long V_22 ;
T_7 V_127 ;
F_13 ( ( L_121 , V_2 -> V_8 ) ) ;
if ( F_79 ( & V_127 , V_139 , sizeof( T_7 ) ) )
return - V_138 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_127 . V_63 == V_140 )
V_2 -> V_141 = V_127 . V_131 ;
else
memcpy ( & V_2 -> V_62 , & V_127 , sizeof( T_7 ) ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , int T_2 * V_380 )
{
F_13 ( ( L_122 , V_2 -> V_8 , V_2 -> V_380 ) ) ;
if ( F_189 ( V_2 -> V_380 , V_380 ) )
return - V_138 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_380 )
{
unsigned long V_22 ;
F_13 ( ( L_123 , V_2 -> V_8 , V_380 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_380 = V_380 ;
if ( V_2 -> V_62 . V_63 != V_83 )
F_190 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , int V_381 )
{
unsigned long V_22 ;
F_13 ( ( L_124 , V_2 -> V_8 , V_381 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_381 ) {
if ( ! V_2 -> V_76 )
F_44 ( V_2 ) ;
} else {
if ( V_2 -> V_76 )
F_54 ( V_2 ) ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_13 ( ( L_125 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_169 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , int V_381 )
{
unsigned long V_22 ;
unsigned int V_308 ;
F_13 ( ( L_126 , V_2 -> V_8 , V_381 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_308 = ( ( unsigned int ) V_381 ) >> 16 ;
if ( V_308 ) {
if ( ( V_308 > V_382 ) || ( V_308 % 4 ) ) {
F_16 ( & V_2 -> V_49 , V_22 ) ;
return - V_169 ;
}
V_2 -> V_308 = V_308 ;
if ( V_308 < 128 )
V_2 -> V_313 = 1 ;
else
V_2 -> V_313 = 0 ;
F_158 ( V_2 ) ;
}
V_381 &= 3 ;
if ( V_381 ) {
if ( ! V_2 -> V_383 )
F_148 ( V_2 ) ;
else if ( V_381 == 2 ) {
F_100 ( V_2 , V_384 , F_99 ( V_2 , V_384 ) | V_282 ) ;
}
} else {
if ( V_2 -> V_383 )
F_158 ( V_2 ) ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , int T_2 * V_385 )
{
unsigned long V_22 ;
int V_386 ;
int V_142 = 0 ;
struct V_112 V_387 , V_113 ;
int V_388 ;
int V_389 ;
struct V_390 V_391 , V_392 ;
F_191 ( V_393 , V_81 ) ;
if ( F_192 ( V_389 , V_385 ) )
return - V_138 ;
F_13 ( ( L_127 , V_2 -> V_8 , V_389 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_87 ( V_2 ) ;
V_386 = V_2 -> V_56 ;
V_388 = V_389 &
( ( ( V_386 & V_151 ) ? V_394 : V_395 ) +
( ( V_386 & V_152 ) ? V_396 : V_397 ) +
( ( V_386 & V_150 ) ? V_398 : V_399 ) +
( ( V_386 & V_153 ) ? V_400 : V_401 ) ) ;
if ( V_388 ) {
F_16 ( & V_2 -> V_49 , V_22 ) ;
goto exit;
}
V_387 = V_2 -> V_111 ;
V_391 = V_2 -> V_283 ;
if ( V_389 & ( V_402 + V_403 ) ) {
unsigned short V_332 = F_99 ( V_2 , V_404 ) ;
if ( ! ( V_332 & V_321 ) )
F_100 ( V_2 , V_404 , ( unsigned short ) ( V_332 | V_321 ) ) ;
}
F_193 ( V_405 ) ;
F_194 ( & V_2 -> V_289 , & V_393 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
for(; ; ) {
F_195 () ;
if ( F_48 ( V_81 ) ) {
V_142 = - V_406 ;
break;
}
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_113 = V_2 -> V_111 ;
V_392 = V_2 -> V_283 ;
F_193 ( V_405 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
if ( V_392 . V_284 == V_391 . V_284 &&
V_392 . V_285 == V_391 . V_285 &&
V_392 . V_294 == V_391 . V_294 &&
V_392 . V_295 == V_391 . V_295 &&
V_392 . V_291 == V_391 . V_291 &&
V_392 . V_292 == V_391 . V_292 &&
V_392 . V_299 == V_391 . V_299 &&
V_392 . V_300 == V_391 . V_300 &&
V_113 . V_324 == V_387 . V_324 &&
V_113 . V_323 == V_387 . V_323 ) {
V_142 = - V_69 ;
break;
}
V_388 = V_389 &
( ( V_392 . V_284 != V_391 . V_284 ? V_394 : 0 ) +
( V_392 . V_285 != V_391 . V_285 ? V_395 : 0 ) +
( V_392 . V_294 != V_391 . V_294 ? V_396 : 0 ) +
( V_392 . V_295 != V_391 . V_295 ? V_397 : 0 ) +
( V_392 . V_291 != V_391 . V_291 ? V_398 : 0 ) +
( V_392 . V_292 != V_391 . V_292 ? V_399 : 0 ) +
( V_392 . V_299 != V_391 . V_299 ? V_400 : 0 ) +
( V_392 . V_300 != V_391 . V_300 ? V_401 : 0 ) +
( V_113 . V_324 != V_387 . V_324 ? V_402 : 0 ) +
( V_113 . V_323 != V_387 . V_323 ? V_403 : 0 ) ) ;
if ( V_388 )
break;
V_387 = V_113 ;
V_391 = V_392 ;
}
F_196 ( & V_2 -> V_289 , & V_393 ) ;
F_193 ( V_407 ) ;
if ( V_389 & ( V_402 + V_403 ) ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( ! F_197 ( & V_2 -> V_289 ) ) {
F_100 ( V_2 , V_404 ,
( unsigned short ) ( F_99 ( V_2 , V_404 ) & ~ V_321 ) ) ;
}
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
exit:
if ( V_142 == 0 )
V_142 = F_189 ( V_388 , V_385 ) ;
return V_142 ;
}
static int F_73 ( struct V_1 * V_2 , int T_2 * V_408 )
{
F_13 ( ( L_128 , V_2 -> V_8 , V_2 -> V_408 ) ) ;
if ( F_189 ( V_2 -> V_408 , V_408 ) )
return - V_138 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , int V_408 )
{
unsigned long V_22 ;
unsigned short V_332 ;
F_13 ( ( L_129 , V_2 -> V_8 , V_408 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_408 = V_408 ;
F_198 ( V_2 ) ;
V_332 = F_99 ( V_2 , V_170 ) ;
if ( V_2 -> V_408 & V_409 )
V_332 |= V_410 ;
else
V_332 &= ~ V_410 ;
F_100 ( V_2 , V_170 , V_332 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , int T_2 * V_411 )
{
F_13 ( ( L_130 , V_2 -> V_8 , V_2 -> V_411 ) ) ;
if ( F_189 ( V_2 -> V_411 , V_411 ) )
return - V_138 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_411 )
{
unsigned long V_22 ;
F_13 ( ( L_131 , V_2 -> V_8 , V_411 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_411 = V_411 ;
F_166 ( V_2 , V_412 , V_411 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , int T_2 * V_413 )
{
F_13 ( ( L_132 , V_2 -> V_8 , V_2 -> V_413 ) ) ;
if ( F_189 ( V_2 -> V_413 , V_413 ) )
return - V_138 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , int V_413 )
{
unsigned long V_22 ;
F_13 ( ( L_133 , V_2 -> V_8 , V_413 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_413 = V_413 ;
F_166 ( V_2 , V_414 , V_413 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_415 T_2 * V_416 )
{
unsigned long V_22 ;
struct V_415 V_417 ;
T_8 V_3 ;
if ( ! V_2 -> V_351 )
return - V_169 ;
if ( F_79 ( & V_417 , V_416 , sizeof( V_417 ) ) )
return - V_138 ;
F_13 ( ( L_134 ,
V_2 -> V_8 , V_417 . V_335 , V_417 . V_418 ,
V_417 . V_419 , V_417 . V_420 ) ) ;
F_15 ( & V_2 -> V_347 [ 0 ] -> V_49 , V_22 ) ;
if ( V_417 . V_420 ) {
V_3 = F_165 ( V_2 , V_421 ) ;
V_3 |= V_417 . V_420 & V_417 . V_419 ;
V_3 &= ~ ( V_417 . V_420 & ~ V_417 . V_419 ) ;
F_166 ( V_2 , V_421 , V_3 ) ;
}
if ( V_417 . V_418 ) {
V_3 = F_165 ( V_2 , V_353 ) ;
V_3 |= V_417 . V_418 & V_417 . V_335 ;
V_3 &= ~ ( V_417 . V_418 & ~ V_417 . V_335 ) ;
F_166 ( V_2 , V_353 , V_3 ) ;
}
F_16 ( & V_2 -> V_347 [ 0 ] -> V_49 , V_22 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_415 T_2 * V_416 )
{
struct V_415 V_417 ;
if ( ! V_2 -> V_351 )
return - V_169 ;
V_417 . V_335 = F_165 ( V_2 , V_353 ) ;
V_417 . V_418 = 0xffffffff ;
V_417 . V_419 = F_165 ( V_2 , V_421 ) ;
V_417 . V_420 = 0xffffffff ;
if ( F_77 ( V_416 , & V_417 , sizeof( V_417 ) ) )
return - V_138 ;
F_13 ( ( L_135 ,
V_2 -> V_8 , V_417 . V_335 , V_417 . V_419 ) ) ;
return 0 ;
}
static void F_199 ( struct V_336 * V_337 , unsigned int V_3 )
{
F_200 ( & V_337 -> V_341 ) ;
F_201 ( & V_337 -> V_393 , V_81 ) ;
V_337 -> V_3 = V_3 ;
}
static void F_202 ( struct V_336 * * V_422 , struct V_336 * V_337 )
{
F_193 ( V_405 ) ;
F_194 ( & V_337 -> V_341 , & V_337 -> V_393 ) ;
V_337 -> V_340 = * V_422 ;
* V_422 = V_337 ;
}
static void F_203 ( struct V_336 * * V_422 , struct V_336 * V_423 )
{
struct V_336 * V_337 , * V_338 ;
F_196 ( & V_423 -> V_341 , & V_423 -> V_393 ) ;
F_193 ( V_407 ) ;
for ( V_337 = * V_422 , V_338 = NULL ; V_337 != NULL ; V_338 = V_337 , V_337 = V_337 -> V_340 ) {
if ( V_337 == V_423 ) {
if ( V_338 != NULL )
V_338 -> V_340 = V_337 -> V_340 ;
else
* V_422 = V_337 -> V_340 ;
break;
}
}
}
static void F_178 ( struct V_336 * * V_422 )
{
while ( * V_422 != NULL ) {
F_28 ( & ( * V_422 ) -> V_341 ) ;
* V_422 = ( * V_422 ) -> V_340 ;
}
}
static int F_60 ( struct V_1 * V_2 , struct V_415 T_2 * V_416 )
{
unsigned long V_22 ;
int V_142 = 0 ;
struct V_415 V_417 ;
struct V_336 V_393 ;
T_9 V_335 ;
if ( ! V_2 -> V_351 )
return - V_169 ;
if ( F_79 ( & V_417 , V_416 , sizeof( V_417 ) ) )
return - V_138 ;
F_13 ( ( L_136 ,
V_2 -> V_8 , V_417 . V_335 , V_417 . V_418 ) ) ;
if ( ( V_417 . V_418 &= ~ F_165 ( V_2 , V_421 ) ) == 0 )
return - V_169 ;
F_199 ( & V_393 , V_417 . V_418 ) ;
F_15 ( & V_2 -> V_347 [ 0 ] -> V_49 , V_22 ) ;
F_166 ( V_2 , V_424 , F_165 ( V_2 , V_424 ) | V_417 . V_418 ) ;
V_335 = F_165 ( V_2 , V_353 ) ;
if ( V_417 . V_418 & ~ ( V_335 ^ V_417 . V_335 ) ) {
V_417 . V_335 = V_335 ;
} else {
F_202 ( & V_2 -> V_339 , & V_393 ) ;
F_16 ( & V_2 -> V_347 [ 0 ] -> V_49 , V_22 ) ;
F_195 () ;
if ( F_48 ( V_81 ) )
V_142 = - V_406 ;
else
V_417 . V_335 = V_393 . V_3 ;
F_15 ( & V_2 -> V_347 [ 0 ] -> V_49 , V_22 ) ;
F_203 ( & V_2 -> V_339 , & V_393 ) ;
}
if ( V_2 -> V_339 == NULL )
F_166 ( V_2 , V_424 , 0 ) ;
F_16 ( & V_2 -> V_347 [ 0 ] -> V_49 , V_22 ) ;
if ( ( V_142 == 0 ) && F_77 ( V_416 , & V_417 , sizeof( V_417 ) ) )
V_142 = - V_138 ;
return V_142 ;
}
static int F_57 ( struct V_1 * V_2 , int V_85 )
{
unsigned long V_22 ;
int V_142 ;
struct V_112 V_387 , V_113 ;
F_191 ( V_393 , V_81 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_387 = V_2 -> V_111 ;
F_194 ( & V_2 -> V_288 , & V_393 ) ;
F_193 ( V_405 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
for(; ; ) {
F_195 () ;
if ( F_48 ( V_81 ) ) {
V_142 = - V_406 ;
break;
}
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_113 = V_2 -> V_111 ;
F_193 ( V_405 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
if ( V_113 . V_116 == V_387 . V_116 && V_113 . V_115 == V_387 . V_115 &&
V_113 . V_117 == V_387 . V_117 && V_113 . V_114 == V_387 . V_114 ) {
V_142 = - V_69 ;
break;
}
if ( ( V_85 & V_425 && V_113 . V_116 != V_387 . V_116 ) ||
( V_85 & V_426 && V_113 . V_115 != V_387 . V_115 ) ||
( V_85 & V_427 && V_113 . V_117 != V_387 . V_117 ) ||
( V_85 & V_428 && V_113 . V_114 != V_387 . V_114 ) ) {
V_142 = 0 ;
break;
}
V_387 = V_113 ;
}
F_196 ( & V_2 -> V_288 , & V_393 ) ;
F_193 ( V_407 ) ;
return V_142 ;
}
static int F_204 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned int V_429 ;
unsigned long V_22 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_87 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_429 = ( ( V_2 -> V_56 & V_57 ) ? V_430 : 0 ) +
( ( V_2 -> V_56 & V_58 ) ? V_431 : 0 ) +
( ( V_2 -> V_56 & V_152 ) ? V_432 : 0 ) +
( ( V_2 -> V_56 & V_153 ) ? V_425 : 0 ) +
( ( V_2 -> V_56 & V_151 ) ? V_426 : 0 ) +
( ( V_2 -> V_56 & V_150 ) ? V_428 : 0 ) ;
F_13 ( ( L_137 , V_2 -> V_8 , V_429 ) ) ;
return V_429 ;
}
static int F_205 ( struct V_20 * V_21 ,
unsigned int V_433 , unsigned int V_434 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
F_13 ( ( L_138 , V_2 -> V_8 , V_433 , V_434 ) ) ;
if ( V_433 & V_430 )
V_2 -> V_56 |= V_57 ;
if ( V_433 & V_431 )
V_2 -> V_56 |= V_58 ;
if ( V_434 & V_430 )
V_2 -> V_56 &= ~ V_57 ;
if ( V_434 & V_431 )
V_2 -> V_56 &= ~ V_58 ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_32 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return 0 ;
}
static int F_206 ( struct V_435 * V_38 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_144 ( V_38 , struct V_1 , V_38 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_87 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
return ( V_2 -> V_56 & V_152 ) ? 1 : 0 ;
}
static void F_207 ( struct V_435 * V_38 , int V_436 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_144 ( V_38 , struct V_1 , V_38 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
if ( V_436 )
V_2 -> V_56 |= V_57 | V_58 ;
else
V_2 -> V_56 &= ~ ( V_57 | V_58 ) ;
F_32 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
static int F_19 ( struct V_20 * V_21 , struct V_27 * V_28 ,
struct V_1 * V_2 )
{
F_191 ( V_393 , V_81 ) ;
int V_29 ;
bool V_437 = false ;
unsigned long V_22 ;
int V_438 ;
struct V_435 * V_38 = & V_2 -> V_38 ;
F_13 ( ( L_139 , V_21 -> V_48 -> V_17 ) ) ;
if ( V_28 -> V_439 & V_440 || V_21 -> V_22 & ( 1 << V_90 ) ) {
V_38 -> V_22 |= V_50 ;
return 0 ;
}
if ( F_208 ( V_21 ) )
V_437 = true ;
V_29 = 0 ;
F_194 ( & V_38 -> V_51 , & V_393 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_38 -> V_4 -- ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_38 -> V_441 ++ ;
while ( 1 ) {
if ( F_31 ( V_21 ) && F_34 ( V_442 , & V_38 -> V_22 ) )
F_209 ( V_38 ) ;
F_193 ( V_405 ) ;
if ( F_210 ( V_28 ) || ! ( V_38 -> V_22 & V_46 ) ) {
V_29 = ( V_38 -> V_22 & V_443 ) ?
- V_444 : - V_406 ;
break;
}
V_438 = F_211 ( V_38 ) ;
if ( V_437 || V_438 )
break;
if ( F_48 ( V_81 ) ) {
V_29 = - V_406 ;
break;
}
F_13 ( ( L_140 , V_21 -> V_48 -> V_17 ) ) ;
F_212 ( V_21 ) ;
F_195 () ;
F_213 ( V_21 ) ;
}
F_193 ( V_407 ) ;
F_196 ( & V_38 -> V_51 , & V_393 ) ;
if ( ! F_210 ( V_28 ) )
V_38 -> V_4 ++ ;
V_38 -> V_441 -- ;
if ( ! V_29 )
V_38 -> V_22 |= V_50 ;
F_13 ( ( L_141 , V_21 -> V_48 -> V_17 , V_29 ) ) ;
return V_29 ;
}
static int F_214 ( struct V_1 * V_2 )
{
V_2 -> V_445 = F_174 ( V_2 -> V_71 + 5 , V_355 ) ;
if ( V_2 -> V_445 == NULL )
return - V_239 ;
V_2 -> V_446 = F_215 ( V_2 -> V_71 + 5 , V_355 ) ;
if ( ! V_2 -> V_446 ) {
F_177 ( V_2 -> V_445 ) ;
V_2 -> V_445 = NULL ;
return - V_239 ;
}
return 0 ;
}
static void F_216 ( struct V_1 * V_2 )
{
F_177 ( V_2 -> V_445 ) ;
V_2 -> V_445 = NULL ;
F_177 ( V_2 -> V_446 ) ;
V_2 -> V_446 = NULL ;
}
static int F_217 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
unsigned int V_447 ;
V_2 -> V_256 = F_218 ( V_2 -> V_448 , V_449 ,
& V_2 -> V_450 ) ;
if ( V_2 -> V_256 == NULL )
return - V_239 ;
V_2 -> V_15 = (struct V_255 * ) V_2 -> V_256 ;
V_2 -> V_11 = ( (struct V_255 * ) V_2 -> V_256 ) + V_2 -> V_14 ;
V_447 = ( unsigned int ) V_2 -> V_450 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_14 ; V_6 ++ ) {
V_2 -> V_15 [ V_6 ] . V_451 = V_447 + ( V_6 * sizeof( struct V_255 ) ) ;
if ( V_6 == V_2 -> V_14 - 1 )
V_2 -> V_15 [ V_6 ] . V_340 = F_219 ( V_447 ) ;
else
V_2 -> V_15 [ V_6 ] . V_340 = F_219 ( V_447 + ( ( V_6 + 1 ) * sizeof( struct V_255 ) ) ) ;
F_159 ( V_2 -> V_15 [ V_6 ] , V_382 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_451 = V_447 + ( ( V_2 -> V_14 + V_6 ) * sizeof( struct V_255 ) ) ;
if ( V_6 == V_2 -> V_10 - 1 )
V_2 -> V_11 [ V_6 ] . V_340 = F_219 ( V_447 + V_2 -> V_14 * sizeof( struct V_255 ) ) ;
else
V_2 -> V_11 [ V_6 ] . V_340 = F_219 ( V_447 + ( ( V_2 -> V_14 + V_6 + 1 ) * sizeof( struct V_255 ) ) ) ;
}
return 0 ;
}
static void F_220 ( struct V_1 * V_2 )
{
if ( V_2 -> V_256 != NULL ) {
F_221 ( V_2 -> V_448 , V_449 , V_2 -> V_256 , V_2 -> V_450 ) ;
V_2 -> V_256 = NULL ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
}
}
static int F_222 ( struct V_1 * V_2 , struct V_255 * V_256 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( ( V_256 [ V_6 ] . V_67 = F_223 ( V_2 -> V_448 , V_382 , & V_256 [ V_6 ] . V_452 ) ) == NULL )
return - V_239 ;
V_256 [ V_6 ] . V_453 = F_219 ( ( unsigned int ) V_256 [ V_6 ] . V_452 ) ;
}
return 0 ;
}
static void F_224 ( struct V_1 * V_2 , struct V_255 * V_256 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( V_256 [ V_6 ] . V_67 == NULL )
continue;
F_221 ( V_2 -> V_448 , V_382 , V_256 [ V_6 ] . V_67 , V_256 [ V_6 ] . V_452 ) ;
V_256 [ V_6 ] . V_67 = NULL ;
}
}
static int F_225 ( struct V_1 * V_2 )
{
V_2 -> V_14 = 32 ;
V_2 -> V_10 = 32 ;
if ( F_217 ( V_2 ) < 0 ||
F_222 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) < 0 ||
F_222 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) < 0 ||
F_214 ( V_2 ) < 0 ) {
F_12 ( ( L_142 , V_2 -> V_8 ) ) ;
return - V_239 ;
}
F_226 ( V_2 ) ;
return 0 ;
}
static void F_227 ( struct V_1 * V_2 )
{
if ( V_2 -> V_256 ) {
F_224 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) ;
F_224 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) ;
F_220 ( V_2 ) ;
}
F_216 ( V_2 ) ;
}
static int F_228 ( struct V_1 * V_2 )
{
if ( F_229 ( V_2 -> V_148 , V_242 , L_143 ) == NULL ) {
F_12 ( ( L_144 ,
V_2 -> V_8 , V_2 -> V_148 ) ) ;
V_2 -> V_36 = V_454 ;
goto V_455;
}
else
V_2 -> V_456 = true ;
V_2 -> V_457 = F_230 ( V_2 -> V_148 , V_242 ) ;
if ( ! V_2 -> V_457 ) {
F_12 ( ( L_145 ,
V_2 -> V_8 , V_2 -> V_148 ) ) ;
V_2 -> V_36 = V_458 ;
goto V_455;
}
return 0 ;
V_455:
F_231 ( V_2 ) ;
return - V_33 ;
}
static void F_231 ( struct V_1 * V_2 )
{
if ( V_2 -> V_459 ) {
F_232 ( V_2 -> V_149 , V_2 ) ;
V_2 -> V_459 = false ;
}
if ( V_2 -> V_456 ) {
F_233 ( V_2 -> V_148 , V_242 ) ;
V_2 -> V_456 = false ;
}
if ( V_2 -> V_457 ) {
F_234 ( V_2 -> V_457 ) ;
V_2 -> V_457 = NULL ;
}
}
static void F_235 ( struct V_1 * V_2 )
{
char * V_460 ;
V_2 -> V_35 = NULL ;
V_2 -> line = V_31 ;
sprintf ( V_2 -> V_8 , L_146 , V_461 , V_2 -> line ) ;
if ( V_2 -> line < V_462 ) {
if ( V_463 [ V_2 -> line ] )
V_2 -> V_71 = V_463 [ V_2 -> line ] ;
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
if ( V_2 -> V_71 < 4096 )
V_2 -> V_71 = 4096 ;
else if ( V_2 -> V_71 > 65535 )
V_2 -> V_71 = 65535 ;
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
V_2 -> V_62 . V_63 = V_83 ;
break;
default:
V_460 = L_151 ;
}
F_2 ( L_152 ,
V_460 , V_2 -> V_8 , V_2 -> V_148 ,
V_2 -> V_149 , V_2 -> V_71 ) ;
#if V_297
F_127 ( V_2 ) ;
#endif
}
static struct V_1 * F_236 ( int V_470 , int V_471 , struct V_472 * V_448 )
{
struct V_1 * V_2 ;
V_2 = F_215 ( sizeof( struct V_1 ) , V_355 ) ;
if ( ! V_2 ) {
F_12 ( ( L_153 ,
V_32 , V_470 , V_471 ) ) ;
} else {
F_237 ( & V_2 -> V_38 ) ;
V_2 -> V_38 . V_25 = & V_473 ;
V_2 -> V_18 = V_19 ;
F_238 ( & V_2 -> V_271 , F_143 ) ;
V_2 -> V_71 = 4096 ;
V_2 -> V_141 = 14745600 ;
V_2 -> V_308 = V_382 ;
V_2 -> V_38 . V_474 = 5 * V_247 / 10 ;
V_2 -> V_38 . V_475 = 30 * V_247 ;
F_200 ( & V_2 -> V_288 ) ;
F_200 ( & V_2 -> V_289 ) ;
F_239 ( & V_2 -> V_42 ) ;
memcpy ( & V_2 -> V_62 , & V_476 , sizeof( T_7 ) ) ;
V_2 -> V_380 = V_477 ;
V_2 -> V_470 = V_470 ;
V_2 -> V_471 = V_471 ;
F_240 ( & V_2 -> V_65 , V_478 , ( unsigned long ) V_2 ) ;
F_240 ( & V_2 -> V_265 , V_479 , ( unsigned long ) V_2 ) ;
V_2 -> V_448 = V_448 ;
V_2 -> V_149 = V_448 -> V_243 ;
V_2 -> V_148 = F_241 ( V_448 , 0 ) ;
V_2 -> V_480 = V_481 ;
V_2 -> V_482 = V_483 ;
V_2 -> V_36 = - 1 ;
}
return V_2 ;
}
static void F_242 ( int V_470 , struct V_472 * V_448 )
{
struct V_1 * V_347 [ V_484 ] ;
int V_6 ;
int V_346 = 1 ;
if ( V_448 -> V_465 == V_467 )
V_346 = 2 ;
else if ( V_448 -> V_465 == V_468 )
V_346 = 4 ;
for ( V_6 = 0 ; V_6 < V_346 ; ++ V_6 ) {
V_347 [ V_6 ] = F_236 ( V_470 , V_6 , V_448 ) ;
if ( V_347 [ V_6 ] == NULL ) {
for ( -- V_6 ; V_6 >= 0 ; -- V_6 ) {
F_243 ( & V_347 [ V_6 ] -> V_38 ) ;
F_177 ( V_347 [ V_6 ] ) ;
}
return;
}
}
for ( V_6 = 0 ; V_6 < V_346 ; ++ V_6 ) {
memcpy ( V_347 [ V_6 ] -> V_347 , V_347 , sizeof( V_347 ) ) ;
F_235 ( V_347 [ V_6 ] ) ;
V_347 [ V_6 ] -> V_346 = V_346 ;
F_239 ( & V_347 [ V_6 ] -> V_49 ) ;
}
if ( ! F_228 ( V_347 [ 0 ] ) ) {
F_225 ( V_347 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_346 ; ++ V_6 ) {
V_347 [ V_6 ] -> V_149 = V_347 [ 0 ] -> V_149 ;
V_347 [ V_6 ] -> V_457 = V_347 [ 0 ] -> V_457 ;
F_225 ( V_347 [ V_6 ] ) ;
}
if ( F_244 ( V_347 [ 0 ] -> V_149 ,
F_172 ,
V_347 [ 0 ] -> V_482 ,
V_347 [ 0 ] -> V_8 ,
V_347 [ 0 ] ) < 0 ) {
F_12 ( ( L_154 ,
V_347 [ 0 ] -> V_8 ,
V_347 [ 0 ] -> V_149 ) ) ;
} else {
V_347 [ 0 ] -> V_459 = true ;
F_245 ( V_347 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_346 ; V_6 ++ ) {
V_347 [ V_6 ] -> V_36 = V_347 [ 0 ] -> V_36 ;
V_347 [ V_6 ] -> V_351 = V_347 [ 0 ] -> V_351 ;
}
}
}
for ( V_6 = 0 ; V_6 < V_346 ; ++ V_6 ) {
struct V_1 * V_2 = V_347 [ V_6 ] ;
F_246 ( & V_2 -> V_38 , V_485 , V_2 -> line ,
& V_2 -> V_448 -> V_173 ) ;
}
}
static int F_247 ( struct V_472 * V_173 ,
const struct V_486 * V_487 )
{
if ( F_248 ( V_173 ) ) {
F_2 ( L_155 , V_173 ) ;
return - V_69 ;
}
F_249 ( V_173 ) ;
F_242 ( V_31 , V_173 ) ;
return 0 ;
}
static void F_250 ( struct V_472 * V_173 )
{
}
static void F_251 ( void )
{
int V_142 ;
struct V_1 * V_2 ;
struct V_1 * V_488 ;
F_2 ( V_489 L_156 , V_32 ) ;
if ( V_485 ) {
for ( V_2 = V_34 ; V_2 != NULL ; V_2 = V_2 -> V_35 )
F_252 ( V_485 , V_2 -> line ) ;
V_142 = F_253 ( V_485 ) ;
if ( V_142 )
F_12 ( ( L_157 , V_142 ) ) ;
F_254 ( V_485 ) ;
}
V_2 = V_34 ;
while( V_2 ) {
F_255 ( V_2 ) ;
V_2 = V_2 -> V_35 ;
}
V_2 = V_34 ;
while( V_2 ) {
#if V_297
F_132 ( V_2 ) ;
#endif
F_227 ( V_2 ) ;
F_216 ( V_2 ) ;
if ( V_2 -> V_471 == 0 )
F_231 ( V_2 ) ;
V_488 = V_2 ;
V_2 = V_2 -> V_35 ;
F_243 ( & V_488 -> V_38 ) ;
F_177 ( V_488 ) ;
}
if ( V_490 )
F_256 ( & V_491 ) ;
}
static int T_10 F_257 ( void )
{
int V_142 ;
F_2 ( V_489 L_158 , V_32 ) ;
V_485 = F_258 ( V_462 ) ;
if ( ! V_485 ) {
F_2 ( L_159 , V_32 ) ;
return - V_239 ;
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
F_259 ( V_485 , & V_25 ) ;
if ( ( V_142 = F_260 ( V_485 ) ) < 0 ) {
F_12 ( ( L_160 , V_32 ) ) ;
F_254 ( V_485 ) ;
V_485 = NULL ;
goto error;
}
F_2 ( V_489 L_161 ,
V_32 , V_485 -> V_493 ) ;
V_31 = 0 ;
if ( ( V_142 = F_261 ( & V_491 ) ) < 0 ) {
F_2 ( L_162 , V_32 , V_142 ) ;
goto error;
}
V_490 = true ;
if ( ! V_34 )
F_2 ( L_163 , V_32 ) ;
return 0 ;
error:
F_251 () ;
return V_142 ;
}
static void T_11 F_262 ( void )
{
F_251 () ;
}
static T_1 F_263 ( struct V_1 * V_2 , unsigned int V_506 )
{
F_264 () ;
return F_265 ( ( void V_507 * ) V_457 ) ;
}
static void F_266 ( struct V_1 * V_2 , unsigned int V_506 , T_1 V_168 )
{
F_264 () ;
F_267 ( V_168 , ( void V_507 * ) V_457 ) ;
}
static T_12 F_99 ( struct V_1 * V_2 , unsigned int V_506 )
{
F_264 () ;
return F_268 ( ( void V_507 * ) V_457 ) ;
}
static void F_100 ( struct V_1 * V_2 , unsigned int V_506 , T_12 V_168 )
{
F_264 () ;
F_269 ( V_168 , ( void V_507 * ) V_457 ) ;
}
static T_8 F_165 ( struct V_1 * V_2 , unsigned int V_506 )
{
F_264 () ;
return F_270 ( ( void V_507 * ) V_457 ) ;
}
static void F_166 ( struct V_1 * V_2 , unsigned int V_506 , T_8 V_168 )
{
F_264 () ;
F_271 ( V_168 , ( void V_507 * ) V_457 ) ;
}
static void F_272 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_166 ( V_2 , V_326 , V_260 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_165 ( V_2 , V_326 ) & V_261 ) )
break;
}
static void F_169 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_166 ( V_2 , V_329 , V_260 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_165 ( V_2 , V_329 ) & V_261 ) )
break;
}
static void F_273 ( struct V_1 * V_2 )
{
F_100 ( V_2 , V_404 , ( unsigned short ) ( F_99 ( V_2 , V_404 ) | V_290 ) ) ;
if ( V_2 -> V_62 . V_63 != V_83 ) {
F_266 ( V_2 , V_508 , 0x49 ) ;
if ( V_2 -> V_62 . V_131 )
F_274 ( V_2 , V_2 -> V_62 . V_131 ) ;
else
F_274 ( V_2 , 3686400 ) ;
}
}
static void F_274 ( struct V_1 * V_2 , T_9 V_509 )
{
unsigned int div ;
unsigned int V_510 = V_2 -> V_141 ;
if ( V_509 ) {
div = V_510 / V_509 ;
if ( ! ( V_510 % V_509 ) && div )
div -- ;
F_100 ( V_2 , V_511 , ( unsigned short ) div ) ;
}
}
static void F_158 ( struct V_1 * V_2 )
{
unsigned short V_332 ;
V_332 = F_99 ( V_2 , V_384 ) & ~ V_260 ;
F_100 ( V_2 , V_384 , ( unsigned short ) ( V_332 | V_290 ) ) ;
F_100 ( V_2 , V_384 , V_332 ) ;
F_151 ( V_2 , V_325 + V_306 + V_321 ) ;
F_100 ( V_2 , V_305 , V_321 + V_325 ) ;
F_272 ( V_2 ) ;
V_2 -> V_383 = false ;
V_2 -> V_277 = false ;
}
static void F_148 ( struct V_1 * V_2 )
{
unsigned short V_332 ;
F_151 ( V_2 , V_325 + V_306 ) ;
F_100 ( V_2 , V_305 , V_325 ) ;
V_332 = F_99 ( V_2 , V_384 ) & ~ V_260 ;
F_100 ( V_2 , V_384 , ( unsigned short ) ( V_332 | V_290 ) ) ;
F_100 ( V_2 , V_384 , V_332 ) ;
F_272 ( V_2 ) ;
F_226 ( V_2 ) ;
if ( V_2 -> V_313 ) {
F_100 ( V_2 , V_404 , ( unsigned short ) ( F_99 ( V_2 , V_404 ) & ~ V_512 ) ) ;
F_182 ( V_2 , V_306 ) ;
if ( V_2 -> V_62 . V_63 == V_83 ) {
F_166 ( V_2 , V_326 , V_171 ) ;
}
} else {
F_100 ( V_2 , V_404 , ( unsigned short ) ( F_99 ( V_2 , V_404 ) | V_512 ) ) ;
F_166 ( V_2 , V_513 , V_2 -> V_15 [ 0 ] . V_451 ) ;
if ( V_2 -> V_62 . V_63 != V_83 ) {
F_166 ( V_2 , V_326 , ( V_290 + V_261 ) ) ;
} else {
F_166 ( V_2 , V_326 , ( V_171 + V_290 + V_261 ) ) ;
}
}
F_182 ( V_2 , V_325 ) ;
F_100 ( V_2 , V_384 , ( unsigned short ) ( F_99 ( V_2 , V_384 ) | V_260 ) ) ;
V_2 -> V_277 = false ;
V_2 -> V_383 = true ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_76 ) {
F_100 ( V_2 , V_170 ,
( unsigned short ) ( ( F_99 ( V_2 , V_170 ) | V_260 ) & ~ V_290 ) ) ;
V_2 -> V_76 = true ;
}
if ( F_136 ( V_2 -> V_11 [ V_2 -> V_330 ] ) ) {
V_2 -> V_333 = false ;
if ( V_2 -> V_62 . V_63 != V_83 ) {
if ( V_2 -> V_62 . V_22 & V_514 ) {
F_87 ( V_2 ) ;
if ( ! ( V_2 -> V_56 & V_57 ) ) {
V_2 -> V_56 |= V_57 ;
F_32 ( V_2 ) ;
V_2 -> V_333 = true ;
}
}
F_151 ( V_2 , V_331 ) ;
F_182 ( V_2 , V_320 + V_312 ) ;
F_100 ( V_2 , V_305 , ( unsigned short ) ( V_312 + V_320 ) ) ;
} else {
F_151 ( V_2 , V_331 ) ;
F_182 ( V_2 , V_312 ) ;
F_100 ( V_2 , V_305 , V_312 ) ;
}
F_166 ( V_2 , V_515 , V_2 -> V_11 [ V_2 -> V_330 ] . V_451 ) ;
F_166 ( V_2 , V_329 , V_290 + V_261 ) ;
V_2 -> V_80 = true ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned short V_332 ;
F_170 ( & V_2 -> V_65 ) ;
F_169 ( V_2 ) ;
V_332 = F_99 ( V_2 , V_170 ) & ~ V_260 ;
F_100 ( V_2 , V_170 , ( unsigned short ) ( V_332 | V_290 ) ) ;
F_151 ( V_2 , V_331 + V_312 + V_320 ) ;
F_100 ( V_2 , V_305 , ( unsigned short ) ( V_312 + V_320 ) ) ;
F_275 ( V_2 ) ;
V_2 -> V_76 = false ;
V_2 -> V_80 = false ;
}
static void F_255 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_457 )
return;
F_54 ( V_2 ) ;
F_158 ( V_2 ) ;
V_2 -> V_56 &= ~ ( V_57 | V_58 ) ;
F_32 ( V_2 ) ;
F_151 ( V_2 , V_356 | V_357 ) ;
}
static void F_276 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_346 ; ++ V_6 ) {
if ( V_2 -> V_347 [ V_6 ] )
F_255 ( V_2 -> V_347 [ V_6 ] ) ;
}
}
static void F_181 ( struct V_1 * V_2 )
{
unsigned short V_332 ;
F_151 ( V_2 , V_356 | V_357 ) ;
F_54 ( V_2 ) ;
F_158 ( V_2 ) ;
V_332 = 0x4000 ;
if ( V_2 -> V_408 & V_409 )
V_332 |= V_410 ;
if ( V_2 -> V_62 . V_122 != V_373 ) {
V_332 |= V_516 ;
if ( V_2 -> V_62 . V_122 == V_371 )
V_332 |= V_348 ;
}
switch ( V_2 -> V_62 . V_136 )
{
case 6 : V_332 |= V_328 ; break;
case 7 : V_332 |= V_327 ; break;
case 8 : V_332 |= V_327 + V_328 ; break;
}
if ( V_2 -> V_62 . V_137 != 1 )
V_332 |= V_282 ;
if ( V_2 -> V_62 . V_22 & V_517 )
V_332 |= V_261 ;
F_100 ( V_2 , V_170 , V_332 ) ;
V_332 = 0x4000 ;
if ( V_2 -> V_62 . V_122 != V_373 ) {
V_332 |= V_516 ;
if ( V_2 -> V_62 . V_122 == V_371 )
V_332 |= V_348 ;
}
switch ( V_2 -> V_62 . V_136 )
{
case 6 : V_332 |= V_328 ; break;
case 7 : V_332 |= V_327 ; break;
case 8 : V_332 |= V_327 + V_328 ; break;
}
if ( V_2 -> V_62 . V_22 & V_518 )
V_332 |= V_261 ;
F_100 ( V_2 , V_384 , V_332 ) ;
F_266 ( V_2 , V_508 , 0x69 ) ;
F_198 ( V_2 ) ;
V_332 = V_310 + V_512 + V_261 ;
if ( ( F_165 ( V_2 , V_519 ) & V_348 ) && V_2 -> V_62 . V_79 &&
( ( V_2 -> V_141 < ( V_2 -> V_62 . V_79 * 16 ) ) ||
( V_2 -> V_141 % ( V_2 -> V_62 . V_79 * 16 ) ) ) ) {
V_332 |= V_282 ;
F_274 ( V_2 , V_2 -> V_62 . V_79 * 8 ) ;
} else {
F_274 ( V_2 , V_2 -> V_62 . V_79 * 16 ) ;
}
F_100 ( V_2 , V_404 , V_332 ) ;
F_182 ( V_2 , V_314 | V_325 ) ;
if ( V_2 -> V_62 . V_129 )
F_273 ( V_2 ) ;
}
static void F_180 ( struct V_1 * V_2 )
{
unsigned short V_332 ;
F_151 ( V_2 , V_356 | V_357 ) ;
F_54 ( V_2 ) ;
F_158 ( V_2 ) ;
V_332 = V_290 ;
switch( V_2 -> V_62 . V_63 ) {
case V_276 :
V_332 |= V_310 + V_520 ;
break;
case V_274 : V_332 |= V_512 + V_520 ; break;
case V_275 : V_332 |= V_310 ; break;
case V_273 : V_332 |= V_520 ; break;
}
if ( V_2 -> V_408 & V_409 )
V_332 |= V_410 ;
switch( V_2 -> V_62 . V_130 )
{
case V_521 : V_332 |= V_309 ; break;
case V_522 : V_332 |= V_523 ; break;
case V_524 : V_332 |= V_523 + V_309 ; break;
case V_181 : V_332 |= V_525 ; break;
case V_183 : V_332 |= V_525 + V_309 ; break;
case V_185 : V_332 |= V_525 + V_523 ; break;
case V_526 : V_332 |= V_525 + V_523 + V_309 ; break;
}
switch ( V_2 -> V_62 . V_133 & V_527 )
{
case V_189 : V_332 |= V_516 ; break;
case V_191 : V_332 |= V_516 + V_348 ; break;
}
if ( V_2 -> V_62 . V_135 != V_528 )
V_332 |= V_171 ;
switch ( V_2 -> V_62 . V_134 )
{
case V_529 : V_332 |= V_327 ; break;
case V_530 : V_332 |= V_328 ; break;
case V_531 : V_332 |= V_327 + V_328 ; break;
}
if ( V_2 -> V_62 . V_22 & V_517 )
V_332 |= V_261 ;
F_100 ( V_2 , V_170 , V_332 ) ;
switch ( V_2 -> V_62 . V_135 )
{
case V_532 : V_332 = 0x7e ; break;
case V_533 : V_332 = 0xff ; break;
case V_534 : V_332 = 0x00 ; break;
case V_535 : V_332 = 0x55 ; break;
case V_536 : V_332 = 0xaa ; break;
default: V_332 = 0x7e ; break;
}
F_266 ( V_2 , V_537 , ( unsigned char ) V_332 ) ;
V_332 = 0 ;
switch( V_2 -> V_62 . V_63 ) {
case V_276 :
V_332 |= V_310 + V_520 ;
break;
case V_274 : V_332 |= V_512 + V_520 ; break;
case V_275 : V_332 |= V_310 ; break;
case V_273 : V_332 |= V_520 ; break;
}
switch( V_2 -> V_62 . V_130 )
{
case V_521 : V_332 |= V_309 ; break;
case V_522 : V_332 |= V_523 ; break;
case V_524 : V_332 |= V_523 + V_309 ; break;
case V_181 : V_332 |= V_525 ; break;
case V_183 : V_332 |= V_525 + V_309 ; break;
case V_185 : V_332 |= V_525 + V_523 ; break;
case V_526 : V_332 |= V_525 + V_523 + V_309 ; break;
}
switch ( V_2 -> V_62 . V_133 & V_527 )
{
case V_189 : V_332 |= V_516 ; break;
case V_191 : V_332 |= V_516 + V_348 ; break;
}
if ( V_2 -> V_62 . V_22 & V_518 )
V_332 |= V_261 ;
F_100 ( V_2 , V_384 , V_332 ) ;
V_332 = 0 ;
if ( V_2 -> V_62 . V_22 & V_219 )
{
if ( V_2 -> V_62 . V_22 & V_214 )
V_332 |= V_171 + V_327 ;
else
V_332 |= V_171 ;
}
else if ( V_2 -> V_62 . V_22 & V_218 )
V_332 |= V_410 ;
else if ( V_2 -> V_62 . V_22 & V_220 )
V_332 |= V_327 ;
if ( V_2 -> V_62 . V_22 & V_215 )
V_332 |= V_282 ;
else if ( V_2 -> V_62 . V_22 & V_214 )
V_332 |= V_328 ;
else if ( V_2 -> V_62 . V_22 & V_216 )
V_332 |= V_290 ;
if ( V_2 -> V_62 . V_131 )
V_332 |= V_260 + V_261 ;
F_266 ( V_2 , V_508 , ( unsigned char ) V_332 ) ;
if ( V_2 -> V_62 . V_22 & ( V_218 + V_214 ) )
{
switch( V_2 -> V_62 . V_130 )
{
case V_181 :
case V_183 :
V_332 = V_410 ; break;
case V_185 :
case V_526 :
V_332 = V_410 + V_171 ; break;
default: V_332 = V_171 ;
}
F_100 ( V_2 , V_384 , ( unsigned short ) ( F_99 ( V_2 , V_384 ) | V_332 ) ) ;
F_274 ( V_2 , V_2 -> V_62 . V_131 * 16 ) ;
}
else
F_274 ( V_2 , V_2 -> V_62 . V_131 ) ;
F_190 ( V_2 ) ;
F_198 ( V_2 ) ;
F_100 ( V_2 , V_404 , V_310 + V_512 + V_261 ) ;
if ( V_2 -> V_62 . V_129 )
F_273 ( V_2 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
unsigned char V_332 ;
unsigned short V_538 ;
V_538 = F_99 ( V_2 , V_170 ) ;
if ( V_2 -> V_380 & V_539 ) {
V_538 = ( V_538 & ~ ( V_171 + V_327 ) ) | V_328 ;
F_266 ( V_2 , V_537 , ( unsigned char ) ( ( V_2 -> V_380 >> 8 ) & 0xff ) ) ;
} else if ( ! ( V_538 & V_171 ) ) {
V_538 &= ~ ( V_327 + V_328 ) ;
}
F_100 ( V_2 , V_170 , V_538 ) ;
if ( V_2 -> V_380 & ( V_540 | V_539 ) ) {
V_332 = ( unsigned char ) ( V_2 -> V_380 & 0xff ) ;
} else {
switch( V_2 -> V_380 )
{
case V_477 : V_332 = 0x7e ; break;
case V_541 :
case V_542 : V_332 = 0xaa ; break;
case V_543 :
case V_544 : V_332 = 0x00 ; break;
default: V_332 = 0xff ;
}
}
F_266 ( V_2 , V_545 , V_332 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_99 ( V_2 , V_305 ) ;
V_2 -> V_56 &= V_57 | V_58 ;
if ( V_12 & V_282 )
V_2 -> V_56 |= V_151 ;
if ( V_12 & V_290 )
V_2 -> V_56 |= V_150 ;
if ( V_12 & V_260 )
V_2 -> V_56 |= V_152 ;
if ( V_12 & V_261 )
V_2 -> V_56 |= V_153 ;
}
static void F_198 ( struct V_1 * V_2 )
{
unsigned char V_332 = 0 ;
switch( V_2 -> V_408 & V_546 )
{
case V_547 :
V_332 |= V_327 ;
break;
case V_548 :
V_332 |= V_410 + V_171 + V_327 ;
break;
case V_549 :
V_332 |= V_171 ;
break;
}
if ( V_2 -> V_408 & V_550 )
V_332 |= V_328 ;
if ( V_2 -> V_56 & V_58 )
V_332 |= V_282 ;
if ( V_2 -> V_56 & V_57 )
V_332 |= V_290 ;
if ( V_2 -> V_408 & V_551 )
V_332 |= V_260 ;
if ( V_2 -> V_408 & V_552 )
V_332 |= V_261 ;
F_266 ( V_2 , V_553 , V_332 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned char V_332 = F_263 ( V_2 , V_553 ) ;
if ( V_2 -> V_56 & V_58 )
V_332 |= V_282 ;
else
V_332 &= ~ V_282 ;
if ( V_2 -> V_56 & V_57 )
V_332 |= V_290 ;
else
V_332 &= ~ V_290 ;
F_266 ( V_2 , V_553 , V_332 ) ;
}
static void F_140 ( struct V_1 * V_2 , unsigned int V_6 , unsigned int V_554 )
{
int V_555 = 0 ;
while( ! V_555 ) {
V_2 -> V_15 [ V_6 ] . V_12 = 0 ;
F_159 ( V_2 -> V_15 [ V_6 ] , V_2 -> V_308 ) ;
if ( V_6 == V_554 )
V_555 = 1 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
}
V_2 -> V_13 = V_6 ;
}
static void F_226 ( struct V_1 * V_2 )
{
F_140 ( V_2 , 0 , V_2 -> V_14 - 1 ) ;
V_2 -> V_303 = 0 ;
V_2 -> V_302 = 0 ;
}
static bool F_146 ( struct V_1 * V_2 )
{
unsigned int V_252 , V_253 ;
unsigned short V_12 ;
unsigned int V_556 = 0 ;
unsigned long V_22 ;
struct V_20 * V_21 = V_2 -> V_38 . V_21 ;
unsigned char V_557 = 0xff ;
unsigned int V_558 = 0 ;
switch ( V_2 -> V_62 . V_133 & V_527 ) {
case V_189 : V_558 = 2 ; break;
case V_191 : V_558 = 4 ; break;
}
V_559:
V_556 = 0 ;
V_557 = 0xff ;
V_252 = V_253 = V_2 -> V_13 ;
for (; ; ) {
if ( ! F_135 ( V_2 -> V_15 [ V_253 ] ) )
goto V_45;
if ( V_556 == 0 && V_2 -> V_62 . V_132 != 0xff )
V_557 = V_2 -> V_15 [ V_253 ] . V_67 [ 0 ] ;
V_556 += F_136 ( V_2 -> V_15 [ V_253 ] ) ;
if ( F_277 ( V_2 -> V_15 [ V_253 ] ) )
break;
if ( ++ V_253 == V_2 -> V_14 )
V_253 = 0 ;
if ( V_253 == V_2 -> V_13 ) {
if ( V_2 -> V_383 ) {
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_148 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
}
goto V_45;
}
}
V_12 = F_278 ( V_2 -> V_15 [ V_253 ] ) ;
if ( ( V_2 -> V_62 . V_133 & V_527 ) == V_187 )
V_12 &= ~ V_260 ;
if ( V_556 == 0 ||
( V_557 != 0xff && V_557 != V_2 -> V_62 . V_132 ) ) {
F_140 ( V_2 , V_252 , V_253 ) ;
goto V_559;
}
if ( V_556 < ( 2 + V_558 ) || V_12 & V_261 ) {
V_2 -> V_111 . V_158 ++ ;
V_556 = 0 ;
} else if ( V_12 & V_260 ) {
V_2 -> V_111 . V_161 ++ ;
if ( ! ( V_2 -> V_62 . V_133 & V_560 ) )
V_556 = 0 ;
}
#if V_297
if ( V_556 == 0 ) {
V_2 -> V_232 -> V_196 . V_561 ++ ;
V_2 -> V_232 -> V_196 . V_562 ++ ;
}
#endif
F_145 ( ( L_164 ,
V_2 -> V_8 , V_12 , V_556 ) ) ;
F_138 ( V_2 , V_2 -> V_15 [ V_252 ] . V_67 , F_45 ( int , V_556 , V_2 -> V_308 ) , L_94 ) ;
if ( V_556 ) {
if ( ! ( V_2 -> V_62 . V_133 & V_560 ) ) {
V_556 -= V_558 ;
V_558 = 0 ;
}
if ( V_556 > V_2 -> V_71 + V_558 )
V_2 -> V_111 . V_159 ++ ;
else {
int V_563 = V_556 ;
int V_6 = V_252 ;
unsigned char * V_254 = V_2 -> V_445 ;
V_2 -> V_564 = V_556 ;
V_2 -> V_111 . V_155 ++ ;
while( V_563 ) {
int V_565 = F_45 ( int , V_563 , V_2 -> V_308 ) ;
memcpy ( V_254 , V_2 -> V_15 [ V_6 ] . V_67 , V_565 ) ;
V_254 += V_565 ;
V_563 -= V_565 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
}
if ( V_2 -> V_62 . V_133 & V_560 ) {
* V_254 = ( V_12 & V_260 ) ? V_566 : V_567 ;
V_556 ++ ;
}
#if V_297
if ( V_2 -> V_43 )
F_122 ( V_2 , V_2 -> V_445 , V_556 ) ;
else
#endif
F_8 ( V_21 , V_2 -> V_445 , V_2 -> V_446 , V_556 ) ;
}
}
F_140 ( V_2 , V_252 , V_253 ) ;
return true ;
V_45:
return false ;
}
static bool F_147 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_2 -> V_13 ;
unsigned int V_4 ;
if ( ! F_135 ( V_2 -> V_15 [ V_6 ] ) )
return false ;
V_4 = F_136 ( V_2 -> V_15 [ V_6 ] ) ;
switch( V_2 -> V_62 . V_63 ) {
case V_274 :
case V_275 :
case V_276 :
if ( F_279 ( V_2 -> V_15 [ V_6 ] ) )
V_4 -- ;
break;
}
F_138 ( V_2 , V_2 -> V_15 [ V_6 ] . V_67 , V_4 , L_94 ) ;
F_13 ( ( L_165 , V_4 ) ) ;
if ( V_4 )
F_8 ( V_2 -> V_38 . V_21 , V_2 -> V_15 [ V_6 ] . V_67 ,
V_2 -> V_446 , V_4 ) ;
F_140 ( V_2 , V_6 , V_6 ) ;
return true ;
}
static void F_275 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_2 -> V_9 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_12 = 0 ;
V_2 -> V_11 [ V_6 ] . V_4 = 0 ;
}
}
static unsigned int F_280 ( struct V_1 * V_2 )
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
if ( V_4 && ( F_165 ( V_2 , V_329 ) & V_261 ) )
-- V_4 ;
return V_4 ;
}
static unsigned int F_37 ( struct V_1 * V_2 )
{
unsigned int V_568 = 0 ;
unsigned int V_6 = V_2 -> V_9 ;
unsigned int V_569 ;
unsigned int V_4 ;
unsigned int V_570 = 0 ;
do {
V_4 = F_136 ( V_2 -> V_11 [ V_6 ] ) ;
if ( V_4 )
V_568 += V_4 ;
else if ( ! V_568 )
V_570 = V_2 -> V_11 [ V_6 ] . V_571 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
} while ( V_6 != V_2 -> V_9 );
V_569 = F_165 ( V_2 , V_329 ) ;
if ( V_569 & V_261 )
V_568 += V_570 ;
V_568 += ( V_569 >> 8 ) & 0xff ;
if ( V_2 -> V_80 )
V_568 ++ ;
return V_568 ;
}
static bool F_41 ( struct V_1 * V_2 , const char * V_67 , unsigned int V_203 )
{
unsigned short V_4 ;
unsigned int V_6 ;
struct V_255 * V_572 ;
if ( F_281 ( V_203 , V_382 ) > F_280 ( V_2 ) )
return false ;
F_138 ( V_2 , V_67 , V_203 , L_166 ) ;
V_2 -> V_330 = V_6 = V_2 -> V_9 ;
while ( V_203 ) {
V_572 = & V_2 -> V_11 [ V_6 ] ;
V_4 = ( unsigned short ) ( ( V_203 > V_382 ) ? V_382 : V_203 ) ;
memcpy ( V_572 -> V_67 , V_67 , V_4 ) ;
V_203 -= V_4 ;
V_67 += V_4 ;
if ( ( ! V_203 && V_2 -> V_62 . V_63 == V_64 ) ||
V_2 -> V_62 . V_63 == V_273 )
F_282 ( * V_572 , 1 ) ;
else
F_282 ( * V_572 , 0 ) ;
if ( V_6 != V_2 -> V_330 )
F_159 ( * V_572 , V_4 ) ;
V_572 -> V_571 = V_4 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
}
V_2 -> V_9 = V_6 ;
V_572 = & V_2 -> V_11 [ V_2 -> V_330 ] ;
F_159 ( * V_572 , V_572 -> V_571 ) ;
if ( ! V_2 -> V_80 )
F_44 ( V_2 ) ;
F_36 ( V_2 ) ;
return true ;
}
static int F_283 ( struct V_1 * V_2 )
{
static unsigned short V_573 [] =
{ 0x0000 , 0xffff , 0xaaaa , 0x5555 , 0x6969 , 0x9696 } ;
static unsigned int V_4 = F_284 ( V_573 ) ;
unsigned int V_6 ;
int V_142 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
F_100 ( V_2 , V_545 , V_573 [ V_6 ] ) ;
F_100 ( V_2 , V_511 , V_573 [ ( V_6 + 1 ) % V_4 ] ) ;
if ( ( F_99 ( V_2 , V_545 ) != V_573 [ V_6 ] ) ||
( F_99 ( V_2 , V_511 ) != V_573 [ ( V_6 + 1 ) % V_4 ] ) ) {
V_142 = - V_33 ;
break;
}
}
V_2 -> V_351 = ( F_165 ( V_2 , V_519 ) & V_327 ) ? 1 : 0 ;
V_2 -> V_36 = V_142 ? 0 : V_574 ;
return V_142 ;
}
static int F_285 ( struct V_1 * V_2 )
{
unsigned long V_47 ;
unsigned long V_22 ;
struct V_20 * V_575 = V_2 -> V_38 . V_21 ;
T_9 V_576 = V_2 -> V_62 . V_79 ;
V_2 -> V_62 . V_79 = 921600 ;
V_2 -> V_38 . V_21 = NULL ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_181 ( V_2 ) ;
F_182 ( V_2 , V_312 ) ;
F_100 ( V_2 , V_170 ,
( unsigned short ) ( F_99 ( V_2 , V_170 ) | V_260 ) ) ;
F_100 ( V_2 , V_577 , 0 ) ;
V_2 -> V_36 = V_578 ;
V_2 -> V_311 = false ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_47 = 100 ;
while( V_47 -- && ! V_2 -> V_311 )
F_46 ( 10 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_255 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_62 . V_79 = V_576 ;
V_2 -> V_38 . V_21 = V_575 ;
V_2 -> V_36 = V_2 -> V_311 ? 0 : V_578 ;
return V_2 -> V_311 ? 0 : - V_33 ;
}
static int F_286 ( struct V_1 * V_2 )
{
unsigned char * V_579 , * V_580 ;
int V_4 ;
if ( F_135 ( V_2 -> V_15 [ 0 ] ) ) {
V_4 = F_136 ( V_2 -> V_15 [ 0 ] ) ;
V_579 = V_2 -> V_15 [ 0 ] . V_67 ;
V_580 = V_2 -> V_445 ;
for( ; V_4 ; V_4 -= 2 , V_579 += 2 ) {
if ( ! ( * ( V_579 + 1 ) & ( V_516 + V_348 ) ) ) {
* V_580 = * V_579 ;
V_580 ++ ;
V_2 -> V_564 ++ ;
}
}
F_138 ( V_2 , V_2 -> V_445 , V_2 -> V_564 , L_94 ) ;
return 1 ;
}
return 0 ;
}
static int F_287 ( struct V_1 * V_2 )
{
#define F_288 20
unsigned long V_47 ;
T_13 V_4 = F_288 ;
unsigned char V_67 [ F_288 ] ;
int V_142 = - V_33 ;
unsigned long V_22 ;
struct V_20 * V_575 = V_2 -> V_38 . V_21 ;
T_7 V_62 ;
memcpy ( & V_62 , & V_2 -> V_62 , sizeof( V_62 ) ) ;
V_2 -> V_62 . V_63 = V_83 ;
V_2 -> V_62 . V_79 = 921600 ;
V_2 -> V_62 . V_129 = 1 ;
V_2 -> V_38 . V_21 = NULL ;
for ( V_4 = 0 ; V_4 < F_288 ; ++ V_4 )
V_67 [ V_4 ] = ( unsigned char ) V_4 ;
V_2 -> V_564 = 0 ;
memset ( V_2 -> V_445 , 0 , F_288 ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_181 ( V_2 ) ;
F_148 ( V_2 ) ;
F_41 ( V_2 , V_67 , V_4 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
for ( V_47 = 100 ; V_47 ; -- V_47 ) {
F_46 ( 10 ) ;
if ( F_286 ( V_2 ) ) {
V_142 = 0 ;
break;
}
}
if ( ! V_142 && ( V_2 -> V_564 != V_4 ||
memcmp ( V_67 , V_2 -> V_445 , V_4 ) ) ) {
V_142 = - V_33 ;
}
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_276 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
memcpy ( & V_2 -> V_62 , & V_62 , sizeof( V_2 -> V_62 ) ) ;
V_2 -> V_38 . V_21 = V_575 ;
V_2 -> V_36 = V_142 ? V_581 : 0 ;
return V_142 ;
}
static int F_245 ( struct V_1 * V_2 )
{
F_13 ( ( L_167 , V_2 -> V_8 ) ) ;
if ( F_283 ( V_2 ) < 0 ) {
F_2 ( L_168 ,
V_2 -> V_8 , V_2 -> V_148 ) ;
} else if ( F_285 ( V_2 ) < 0 ) {
F_2 ( L_169 ,
V_2 -> V_8 , V_2 -> V_149 ) ;
} else if ( F_287 ( V_2 ) < 0 ) {
F_2 ( L_170 , V_2 -> V_8 ) ;
}
return V_2 -> V_36 ;
}
static void V_478 ( unsigned long V_582 )
{
struct V_1 * V_2 = (struct V_1 * ) V_582 ;
unsigned long V_22 ;
F_13 ( ( L_171 , V_2 -> V_8 ) ) ;
if( V_2 -> V_80 && V_2 -> V_62 . V_63 == V_64 ) {
V_2 -> V_111 . V_583 ++ ;
}
F_15 ( & V_2 -> V_49 , V_22 ) ;
F_54 ( V_2 ) ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
#if V_297
if ( V_2 -> V_43 )
F_120 ( V_2 ) ;
else
#endif
F_149 ( V_2 ) ;
}
static void V_479 ( unsigned long V_582 )
{
struct V_1 * V_2 = (struct V_1 * ) V_582 ;
unsigned long V_22 ;
F_13 ( ( L_172 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_49 , V_22 ) ;
V_2 -> V_164 |= V_266 ;
F_16 ( & V_2 -> V_49 , V_22 ) ;
F_143 ( & V_2 -> V_271 ) ;
}
