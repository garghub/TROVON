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
if ( F_22 ( & V_2 -> V_38 ) )
F_23 ( V_21 , V_2 -> V_46 ) ;
F_24 ( V_21 ) ;
F_25 ( V_21 ) ;
F_26 ( V_2 ) ;
F_17 ( & V_2 -> V_38 . V_39 ) ;
F_27 ( & V_2 -> V_38 , V_21 ) ;
V_2 -> V_38 . V_21 = NULL ;
V_45:
F_13 ( ( L_20 , V_21 -> V_47 -> V_17 , V_2 -> V_38 . V_4 ) ) ;
}
static void F_28 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_21 ) )
return;
F_13 ( ( L_22 , V_2 -> V_8 ) ) ;
F_24 ( V_21 ) ;
F_14 ( & V_2 -> V_38 . V_39 ) ;
F_26 ( V_2 ) ;
F_15 ( & V_2 -> V_38 . V_48 , V_22 ) ;
V_2 -> V_38 . V_4 = 0 ;
V_2 -> V_38 . V_21 = NULL ;
F_16 ( & V_2 -> V_38 . V_48 , V_22 ) ;
F_29 ( & V_2 -> V_38 , 0 ) ;
F_17 ( & V_2 -> V_38 . V_39 ) ;
F_30 ( & V_2 -> V_38 . V_49 ) ;
}
static void F_31 ( struct V_20 * V_21 , struct V_50 * V_51 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
F_13 ( ( L_23 , V_21 -> V_47 -> V_17 ) ) ;
F_32 ( V_2 ) ;
if ( ( V_51 -> V_52 & V_53 ) && ! F_33 ( V_21 ) ) {
V_2 -> V_54 &= ~ ( V_55 | V_56 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_34 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
if ( ! ( V_51 -> V_52 & V_53 ) && F_33 ( V_21 ) ) {
V_2 -> V_54 |= V_56 ;
if ( ! F_35 ( V_21 ) || ! F_36 ( V_21 ) )
V_2 -> V_54 |= V_55 ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_34 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
if ( ( V_51 -> V_52 & V_57 ) && ! F_35 ( V_21 ) ) {
V_21 -> V_58 = 0 ;
F_37 ( V_21 ) ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_59 . V_60 == V_61 ) {
int V_46 = ( F_39 ( V_2 ) * 7 ) + 1000 ;
F_40 ( & V_2 -> V_62 , V_63 + F_41 ( V_46 ) ) ;
}
}
static int F_42 ( struct V_20 * V_21 ,
const unsigned char * V_64 , int V_4 )
{
int V_65 = 0 ;
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_24 ) )
return - V_66 ;
F_13 ( ( L_25 , V_2 -> V_8 , V_4 ) ) ;
if ( ! V_2 -> V_67 || ( V_4 > V_2 -> V_68 ) )
return - V_66 ;
if ( ! V_4 || V_21 -> V_69 || V_21 -> V_58 )
return 0 ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_70 ) {
if ( ! F_43 ( V_2 , V_2 -> V_67 , V_2 -> V_70 ) )
goto V_45;
V_2 -> V_70 = 0 ;
}
if ( F_43 ( V_2 , V_64 , V_4 ) )
V_65 = V_4 ;
V_45:
F_16 ( & V_2 -> V_48 , V_22 ) ;
F_13 ( ( L_26 , V_2 -> V_8 , V_65 ) ) ;
return V_65 ;
}
static int F_44 ( struct V_20 * V_21 , unsigned char V_71 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
int V_65 = 0 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_27 ) )
return 0 ;
F_13 ( ( L_28 , V_2 -> V_8 , V_71 ) ) ;
if ( ! V_2 -> V_67 )
return 0 ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_70 < V_2 -> V_68 ) {
V_2 -> V_67 [ V_2 -> V_70 ++ ] = V_71 ;
V_65 = 1 ;
}
F_16 ( & V_2 -> V_48 , V_22 ) ;
return V_65 ;
}
static void F_45 ( struct V_20 * V_21 , char V_71 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_29 ) )
return;
F_13 ( ( L_30 , V_2 -> V_8 , V_71 ) ) ;
V_2 -> V_72 = V_71 ;
if ( V_71 ) {
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( ! V_2 -> V_73 )
F_46 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
}
static void F_23 ( struct V_20 * V_21 , int V_46 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_74 , V_75 ;
if ( ! V_2 )
return;
if ( F_6 ( V_2 , V_21 -> V_17 , L_31 ) )
return;
F_13 ( ( L_32 , V_2 -> V_8 ) ) ;
if ( ! F_22 ( & V_2 -> V_38 ) )
goto exit;
V_74 = V_63 ;
if ( V_2 -> V_59 . V_76 ) {
V_75 = V_2 -> V_46 / ( 32 * 5 ) ;
if ( ! V_75 )
V_75 ++ ;
} else
V_75 = 1 ;
if ( V_46 )
V_75 = F_47 (unsigned long, char_time, timeout) ;
while ( V_2 -> V_77 ) {
F_48 ( F_49 ( V_75 ) ) ;
if ( F_50 ( V_78 ) )
break;
if ( V_46 && F_51 ( V_63 , V_74 + V_46 ) )
break;
}
exit:
F_13 ( ( L_33 , V_2 -> V_8 ) ) ;
}
static int F_52 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_65 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_34 ) )
return 0 ;
V_65 = ( V_2 -> V_77 ) ? 0 : V_79 ;
F_13 ( ( L_35 , V_2 -> V_8 , V_65 ) ) ;
return V_65 ;
}
static void F_53 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_36 ) )
return;
F_13 ( ( L_37 , V_2 -> V_8 , V_2 -> V_70 ) ) ;
if ( V_2 -> V_70 <= 0 || V_21 -> V_69 ||
V_21 -> V_58 || ! V_2 -> V_67 )
return;
F_13 ( ( L_38 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_70 && F_43 ( V_2 , V_2 -> V_67 , V_2 -> V_70 ) )
V_2 -> V_70 = 0 ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
static void F_24 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_39 ) )
return;
F_13 ( ( L_40 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_70 = 0 ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
F_54 ( V_21 ) ;
}
static void F_55 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_41 ) )
return;
F_13 ( ( L_42 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_73 && V_2 -> V_59 . V_60 == V_80 )
F_56 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
static void F_37 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_43 ) )
return;
F_13 ( ( L_44 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_70 && F_43 ( V_2 , V_2 -> V_67 , V_2 -> V_70 ) )
V_2 -> V_70 = 0 ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
static int F_57 ( struct V_20 * V_21 ,
unsigned int V_81 , unsigned long V_82 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
void T_2 * V_83 = ( void T_2 * ) V_82 ;
int V_65 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_45 ) )
return - V_33 ;
F_13 ( ( L_46 , V_2 -> V_8 , V_81 ) ) ;
if ( ( V_81 != V_84 ) && ( V_81 != V_85 ) &&
( V_81 != V_86 ) ) {
if ( F_58 ( V_21 ) )
return - V_66 ;
}
switch ( V_81 ) {
case V_87 :
return F_59 ( V_2 , V_83 ) ;
case V_86 :
return F_60 ( V_2 , ( int ) V_82 ) ;
case V_88 :
return F_61 ( V_2 , V_83 ) ;
case V_89 :
return F_62 ( V_2 , V_83 ) ;
case V_90 :
return F_63 ( V_2 , V_83 ) ;
case V_91 :
return F_64 ( V_2 , V_83 ) ;
case V_92 :
return F_65 ( V_2 , ( int ) V_82 ) ;
case V_93 :
return F_66 ( V_2 , V_83 ) ;
case V_94 :
return F_67 ( V_2 , ( int ) V_82 ) ;
}
F_14 ( & V_2 -> V_38 . V_39 ) ;
switch ( V_81 ) {
case V_95 :
V_65 = F_68 ( V_2 , V_83 ) ;
break;
case V_96 :
V_65 = F_69 ( V_2 , V_83 ) ;
break;
case V_97 :
V_65 = F_70 ( V_2 , V_83 ) ;
break;
case V_98 :
V_65 = F_71 ( V_2 , ( int ) V_82 ) ;
break;
case V_99 :
V_65 = F_72 ( V_2 , ( int ) V_82 ) ;
break;
case V_100 :
V_65 = F_73 ( V_2 , ( int ) V_82 ) ;
break;
case V_101 :
V_65 = F_74 ( V_2 ) ;
break;
case V_102 :
V_65 = F_75 ( V_2 , V_83 ) ;
break;
case V_103 :
V_65 = F_76 ( V_2 , V_83 ) ;
break;
case V_104 :
V_65 = F_77 ( V_2 , ( int ) V_82 ) ;
break;
default:
V_65 = - V_105 ;
}
F_17 ( & V_2 -> V_38 . V_39 ) ;
return V_65 ;
}
static int F_78 ( struct V_20 * V_21 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
struct V_108 V_109 ;
unsigned long V_22 ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_109 = V_2 -> V_107 ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
V_107 -> V_110 = V_109 . V_110 ;
V_107 -> V_111 = V_109 . V_111 ;
V_107 -> V_112 = V_109 . V_112 ;
V_107 -> V_113 = V_109 . V_113 ;
V_107 -> V_114 = V_109 . V_114 ;
V_107 -> V_115 = V_109 . V_115 ;
V_107 -> V_116 = V_109 . V_116 ;
V_107 -> V_117 = V_109 . V_117 ;
V_107 -> V_118 = V_109 . V_118 ;
V_107 -> V_119 = V_109 . V_119 ;
V_107 -> V_120 = V_109 . V_120 ;
return 0 ;
}
static long F_79 ( struct V_1 * V_2 , struct V_121 T_2 * V_122 )
{
struct V_121 V_123 ;
F_13 ( ( L_47 , V_2 -> V_8 ) ) ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_60 = ( V_124 ) V_2 -> V_59 . V_60 ;
V_123 . V_125 = V_2 -> V_59 . V_125 ;
V_123 . V_22 = V_2 -> V_59 . V_22 ;
V_123 . V_126 = V_2 -> V_59 . V_126 ;
V_123 . V_127 = ( V_124 ) V_2 -> V_59 . V_127 ;
V_123 . V_128 = V_2 -> V_59 . V_128 ;
V_123 . V_129 = V_2 -> V_59 . V_129 ;
V_123 . V_130 = V_2 -> V_59 . V_130 ;
V_123 . V_131 = V_2 -> V_59 . V_131 ;
V_123 . V_76 = ( V_124 ) V_2 -> V_59 . V_76 ;
V_123 . V_132 = V_2 -> V_59 . V_132 ;
V_123 . V_133 = V_2 -> V_59 . V_133 ;
V_123 . V_118 = V_2 -> V_59 . V_118 ;
if ( F_80 ( V_122 , & V_123 , sizeof( struct V_121 ) ) )
return - V_134 ;
return 0 ;
}
static long F_81 ( struct V_1 * V_2 , struct V_121 T_2 * V_135 )
{
struct V_121 V_123 ;
F_13 ( ( L_48 , V_2 -> V_8 ) ) ;
if ( F_82 ( & V_123 , V_135 , sizeof( struct V_121 ) ) )
return - V_134 ;
F_83 ( & V_2 -> V_48 ) ;
if ( V_123 . V_60 == V_136 ) {
V_2 -> V_137 = V_123 . V_127 ;
} else {
V_2 -> V_59 . V_60 = V_123 . V_60 ;
V_2 -> V_59 . V_125 = V_123 . V_125 ;
V_2 -> V_59 . V_22 = V_123 . V_22 ;
V_2 -> V_59 . V_126 = V_123 . V_126 ;
V_2 -> V_59 . V_127 = V_123 . V_127 ;
V_2 -> V_59 . V_128 = V_123 . V_128 ;
V_2 -> V_59 . V_129 = V_123 . V_129 ;
V_2 -> V_59 . V_130 = V_123 . V_130 ;
V_2 -> V_59 . V_131 = V_123 . V_131 ;
V_2 -> V_59 . V_76 = V_123 . V_76 ;
V_2 -> V_59 . V_132 = V_123 . V_132 ;
V_2 -> V_59 . V_133 = V_123 . V_133 ;
V_2 -> V_59 . V_118 = V_123 . V_118 ;
}
F_84 ( & V_2 -> V_48 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static long F_86 ( struct V_20 * V_21 ,
unsigned int V_81 , unsigned long V_82 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_138 = - V_105 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_49 ) )
return - V_33 ;
F_13 ( ( L_50 , V_2 -> V_8 , V_81 ) ) ;
switch ( V_81 ) {
case V_139 :
V_138 = F_81 ( V_2 , F_87 ( V_82 ) ) ;
break;
case V_140 :
V_138 = F_79 ( V_2 , F_87 ( V_82 ) ) ;
break;
case V_95 :
case V_96 :
case V_97 :
case V_102 :
case V_87 :
case V_103 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_93 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_86 :
case V_104 :
case V_92 :
case V_94 :
V_138 = F_57 ( V_21 , V_81 , V_82 ) ;
break;
}
F_13 ( ( L_51 , V_2 -> V_8 , V_81 , V_138 ) ) ;
return V_138 ;
}
static inline void F_88 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
char V_143 [ 30 ] ;
unsigned long V_22 ;
F_89 ( V_142 , L_52 ,
V_2 -> V_8 , V_2 -> V_144 ,
V_2 -> V_145 , V_2 -> V_68 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_90 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
V_143 [ 0 ] = 0 ;
V_143 [ 1 ] = 0 ;
if ( V_2 -> V_54 & V_55 )
strcat ( V_143 , L_53 ) ;
if ( V_2 -> V_54 & V_146 )
strcat ( V_143 , L_54 ) ;
if ( V_2 -> V_54 & V_56 )
strcat ( V_143 , L_55 ) ;
if ( V_2 -> V_54 & V_147 )
strcat ( V_143 , L_56 ) ;
if ( V_2 -> V_54 & V_148 )
strcat ( V_143 , L_57 ) ;
if ( V_2 -> V_54 & V_149 )
strcat ( V_143 , L_58 ) ;
if ( V_2 -> V_59 . V_60 != V_80 ) {
F_89 ( V_142 , L_59 ,
V_2 -> V_107 . V_150 , V_2 -> V_107 . V_151 ) ;
if ( V_2 -> V_107 . V_152 )
F_89 ( V_142 , L_60 , V_2 -> V_107 . V_152 ) ;
if ( V_2 -> V_107 . V_153 )
F_89 ( V_142 , L_61 , V_2 -> V_107 . V_153 ) ;
if ( V_2 -> V_107 . V_154 )
F_89 ( V_142 , L_62 , V_2 -> V_107 . V_154 ) ;
if ( V_2 -> V_107 . V_155 )
F_89 ( V_142 , L_63 , V_2 -> V_107 . V_155 ) ;
if ( V_2 -> V_107 . V_156 )
F_89 ( V_142 , L_64 , V_2 -> V_107 . V_156 ) ;
if ( V_2 -> V_107 . V_157 )
F_89 ( V_142 , L_65 , V_2 -> V_107 . V_157 ) ;
} else {
F_89 ( V_142 , L_66 ,
V_2 -> V_107 . V_115 , V_2 -> V_107 . V_114 ) ;
if ( V_2 -> V_107 . V_116 )
F_89 ( V_142 , L_67 , V_2 -> V_107 . V_116 ) ;
if ( V_2 -> V_107 . V_118 )
F_89 ( V_142 , L_68 , V_2 -> V_107 . V_118 ) ;
if ( V_2 -> V_107 . V_119 )
F_89 ( V_142 , L_69 , V_2 -> V_107 . V_119 ) ;
if ( V_2 -> V_107 . V_117 )
F_89 ( V_142 , L_70 , V_2 -> V_107 . V_117 ) ;
}
F_89 ( V_142 , L_71 , V_143 + 1 ) ;
F_89 ( V_142 , L_72 ,
V_2 -> V_77 , V_2 -> V_158 , V_2 -> V_159 ,
V_2 -> V_160 ) ;
}
static int F_91 ( struct V_141 * V_142 , void * V_161 )
{
struct V_1 * V_2 ;
F_92 ( V_142 , L_73 ) ;
V_2 = V_34 ;
while( V_2 ) {
F_88 ( V_142 , V_2 ) ;
V_2 = V_2 -> V_35 ;
}
return 0 ;
}
static int F_93 ( struct V_162 * V_162 , struct V_27 * V_27 )
{
return F_94 ( V_27 , F_91 , NULL ) ;
}
static int F_95 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
int V_4 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_74 ) )
return 0 ;
V_4 = F_39 ( V_2 ) ;
F_13 ( ( L_75 , V_2 -> V_8 , V_4 ) ) ;
return V_4 ;
}
static void F_96 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_76 ) )
return;
F_13 ( ( L_77 , V_2 -> V_8 ) ) ;
if ( F_97 ( V_21 ) )
F_45 ( V_21 , F_98 ( V_21 ) ) ;
if ( F_35 ( V_21 ) ) {
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_54 &= ~ V_55 ;
F_34 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
}
static void F_99 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_78 ) )
return;
F_13 ( ( L_79 , V_2 -> V_8 ) ) ;
if ( F_97 ( V_21 ) ) {
if ( V_2 -> V_72 )
V_2 -> V_72 = 0 ;
else
F_45 ( V_21 , F_100 ( V_21 ) ) ;
}
if ( F_35 ( V_21 ) ) {
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_54 |= V_55 ;
F_34 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
}
static int F_101 ( struct V_20 * V_21 , int V_163 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned short V_164 ;
unsigned long V_22 ;
if ( F_6 ( V_2 , V_21 -> V_17 , L_80 ) )
return - V_165 ;
F_13 ( ( L_81 , V_2 -> V_8 , V_163 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_164 = F_102 ( V_2 , V_166 ) ;
if ( V_163 == - 1 )
V_164 |= V_167 ;
else
V_164 &= ~ V_167 ;
F_103 ( V_2 , V_166 , V_164 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
return 0 ;
}
static int F_104 ( struct V_168 * V_169 , unsigned short V_126 ,
unsigned short V_118 )
{
struct V_1 * V_2 = F_105 ( V_169 ) ;
unsigned char V_170 ;
unsigned short V_171 ;
if ( V_2 -> V_38 . V_4 )
return - V_44 ;
F_13 ( ( L_82 , V_2 -> V_8 ) ) ;
switch ( V_126 )
{
case V_172 : V_170 = V_173 ; break;
case V_174 : V_170 = V_175 ; break;
case V_176 : V_170 = V_177 ; break;
case V_178 : V_170 = V_179 ; break;
case V_180 : V_170 = V_181 ; break;
default: return - V_165 ;
}
switch ( V_118 )
{
case V_182 : V_171 = V_183 ; break;
case V_184 : V_171 = V_185 ; break;
case V_186 : V_171 = V_187 ; break;
default: return - V_165 ;
}
V_2 -> V_59 . V_126 = V_170 ;
V_2 -> V_59 . V_129 = V_171 ;
if ( V_2 -> V_43 )
F_85 ( V_2 ) ;
return 0 ;
}
static T_3 F_106 ( struct V_188 * V_189 ,
struct V_168 * V_169 )
{
struct V_1 * V_2 = F_105 ( V_169 ) ;
unsigned long V_22 ;
F_13 ( ( L_83 , V_169 -> V_17 ) ) ;
if ( ! V_189 -> V_190 )
return V_191 ;
F_107 ( V_169 ) ;
V_169 -> V_192 . V_193 ++ ;
V_169 -> V_192 . V_194 += V_189 -> V_190 ;
F_108 ( V_169 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_43 ( V_2 , V_189 -> V_3 , V_189 -> V_190 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
F_109 ( V_189 ) ;
return V_191 ;
}
static int F_110 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = F_105 ( V_169 ) ;
int V_138 ;
unsigned long V_22 ;
if ( ! F_111 ( V_195 ) )
return - V_44 ;
F_13 ( ( L_84 , V_169 -> V_17 ) ) ;
V_138 = F_112 ( V_169 ) ;
if ( V_138 )
return V_138 ;
F_15 ( & V_2 -> V_42 , V_22 ) ;
if ( V_2 -> V_38 . V_4 != 0 || V_2 -> V_43 != 0 ) {
F_13 ( ( L_85 , V_169 -> V_17 ) ) ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
return - V_44 ;
}
V_2 -> V_43 = 1 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
if ( ( V_138 = F_18 ( V_2 ) ) != 0 ) {
F_15 ( & V_2 -> V_42 , V_22 ) ;
V_2 -> V_43 = 0 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
return V_138 ;
}
V_2 -> V_54 |= V_55 | V_56 ;
F_85 ( V_2 ) ;
F_108 ( V_169 ) ;
F_113 ( V_169 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_90 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_54 & V_148 )
F_114 ( V_169 ) ;
else
F_115 ( V_169 ) ;
return 0 ;
}
static int F_116 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = F_105 ( V_169 ) ;
unsigned long V_22 ;
F_13 ( ( L_86 , V_169 -> V_17 ) ) ;
F_107 ( V_169 ) ;
F_26 ( V_2 ) ;
F_117 ( V_169 ) ;
F_15 ( & V_2 -> V_42 , V_22 ) ;
V_2 -> V_43 = 0 ;
F_16 ( & V_2 -> V_42 , V_22 ) ;
F_118 ( V_195 ) ;
return 0 ;
}
static int F_119 ( struct V_168 * V_169 , struct V_196 * V_197 , int V_81 )
{
const T_4 V_198 = sizeof( V_199 ) ;
V_199 V_200 ;
V_199 T_2 * line = V_197 -> V_201 . V_202 . V_203 ;
struct V_1 * V_2 = F_105 ( V_169 ) ;
unsigned int V_22 ;
F_13 ( ( L_87 , V_169 -> V_17 ) ) ;
if ( V_2 -> V_38 . V_4 )
return - V_44 ;
if ( V_81 != V_204 )
return F_120 ( V_169 , V_197 , V_81 ) ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
switch( V_197 -> V_201 . type ) {
case V_205 :
V_197 -> V_201 . type = V_206 ;
if ( V_197 -> V_201 . V_198 < V_198 ) {
V_197 -> V_201 . V_198 = V_198 ;
return - V_207 ;
}
V_22 = V_2 -> V_59 . V_22 & ( V_208 | V_209 |
V_210 | V_211 |
V_212 | V_213 |
V_214 | V_215 ) ;
switch ( V_22 ) {
case ( V_208 | V_212 ) : V_200 . V_216 = V_217 ; break;
case ( V_210 | V_214 ) : V_200 . V_216 = V_218 ; break;
case ( V_208 | V_214 ) : V_200 . V_216 = V_219 ; break;
case ( V_208 | V_215 ) : V_200 . V_216 = V_220 ; break;
default: V_200 . V_216 = V_221 ;
}
V_200 . V_222 = V_2 -> V_59 . V_127 ;
V_200 . V_125 = V_2 -> V_59 . V_125 ? 1 : 0 ;
if ( F_80 ( line , & V_200 , V_198 ) )
return - V_134 ;
return 0 ;
case V_206 :
if( ! F_121 ( V_223 ) )
return - V_224 ;
if ( F_82 ( & V_200 , line , V_198 ) )
return - V_134 ;
switch ( V_200 . V_216 )
{
case V_217 : V_22 = V_208 | V_212 ; break;
case V_220 : V_22 = V_208 | V_215 ; break;
case V_218 : V_22 = V_210 | V_214 ; break;
case V_219 : V_22 = V_208 | V_214 ; break;
case V_221 : V_22 = V_2 -> V_59 . V_22 &
( V_208 | V_209 |
V_210 | V_211 |
V_212 | V_213 |
V_214 | V_215 ) ; break;
default: return - V_165 ;
}
if ( V_200 . V_125 != 0 && V_200 . V_125 != 1 )
return - V_165 ;
V_2 -> V_59 . V_22 &= ~ ( V_208 | V_209 |
V_210 | V_211 |
V_212 | V_213 |
V_214 | V_215 ) ;
V_2 -> V_59 . V_22 |= V_22 ;
V_2 -> V_59 . V_125 = V_200 . V_125 ;
if ( V_22 & ( V_210 | V_214 ) )
V_2 -> V_59 . V_127 = V_200 . V_222 ;
else
V_2 -> V_59 . V_127 = 0 ;
if ( V_2 -> V_43 )
F_85 ( V_2 ) ;
return 0 ;
default:
return F_120 ( V_169 , V_197 , V_81 ) ;
}
}
static void F_122 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = F_105 ( V_169 ) ;
unsigned long V_22 ;
F_13 ( ( L_88 , V_169 -> V_17 ) ) ;
V_169 -> V_192 . V_225 ++ ;
V_169 -> V_192 . V_226 ++ ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_56 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
F_123 ( V_169 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
if ( F_125 ( V_2 -> V_227 ) )
F_123 ( V_2 -> V_227 ) ;
}
static void F_126 ( struct V_1 * V_2 , char * V_64 , int V_198 )
{
struct V_188 * V_189 = F_127 ( V_198 ) ;
struct V_168 * V_169 = V_2 -> V_227 ;
F_13 ( ( L_89 , V_169 -> V_17 ) ) ;
if ( V_189 == NULL ) {
F_12 ( ( L_90 , V_169 -> V_17 ) ) ;
V_169 -> V_192 . V_228 ++ ;
return;
}
memcpy ( F_128 ( V_189 , V_198 ) , V_64 , V_198 ) ;
V_189 -> V_229 = F_129 ( V_189 , V_169 ) ;
V_169 -> V_192 . V_230 ++ ;
V_169 -> V_192 . V_231 += V_198 ;
F_130 ( V_189 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
int V_138 ;
struct V_168 * V_169 ;
T_5 * V_232 ;
V_169 = F_132 ( V_2 ) ;
if ( ! V_169 ) {
F_2 ( V_233 L_91 , V_2 -> V_8 ) ;
return - V_234 ;
}
V_169 -> V_235 = V_2 -> V_144 ;
V_169 -> V_236 = V_2 -> V_144 + V_237 - 1 ;
V_169 -> V_238 = V_2 -> V_145 ;
V_169 -> V_239 = & V_240 ;
V_169 -> V_241 = 10 * V_242 ;
V_169 -> V_243 = 50 ;
V_232 = F_133 ( V_169 ) ;
V_232 -> V_244 = F_104 ;
V_232 -> V_245 = F_106 ;
V_138 = F_134 ( V_169 ) ;
if ( V_138 ) {
F_2 ( V_246 L_92 , __FILE__ ) ;
F_135 ( V_169 ) ;
return V_138 ;
}
V_2 -> V_227 = V_169 ;
return 0 ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_137 ( V_2 -> V_227 ) ;
F_135 ( V_2 -> V_227 ) ;
V_2 -> V_227 = NULL ;
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_108 * V_107 = & V_2 -> V_107 ;
unsigned int V_247 , V_248 ;
unsigned char * V_249 ;
unsigned char V_12 ;
struct V_250 * V_251 = V_2 -> V_15 ;
int V_6 , V_4 ;
int V_252 = 0 ;
int V_253 ;
unsigned char V_71 ;
V_247 = V_248 = V_2 -> V_13 ;
while( F_139 ( V_251 [ V_248 ] ) ) {
V_4 = F_140 ( V_251 [ V_248 ] ) - V_2 -> V_254 ;
V_249 = V_251 [ V_248 ] . V_64 + V_2 -> V_254 ;
F_141 ( ( L_93 , V_2 -> V_8 , V_4 ) ) ;
F_142 ( V_2 , V_249 , V_4 , L_94 ) ;
for( V_6 = 0 ; V_6 < V_4 ; V_6 += 2 , V_249 += 2 ) {
V_71 = * V_249 ;
V_107 -> V_114 ++ ;
V_253 = 0 ;
V_12 = * ( V_249 + 1 ) & ( V_255 + V_256 ) ;
if ( V_12 ) {
if ( V_12 & V_255 )
V_107 -> V_118 ++ ;
else if ( V_12 & V_256 )
V_107 -> V_116 ++ ;
if ( V_12 & V_2 -> V_257 )
continue;
if ( V_12 & V_255 )
V_253 = V_258 ;
else if ( V_12 & V_256 )
V_253 = V_259 ;
}
F_143 ( & V_2 -> V_38 , V_71 , V_253 ) ;
V_252 ++ ;
}
if ( V_6 < V_4 ) {
V_2 -> V_254 += V_6 ;
F_40 ( & V_2 -> V_260 , V_63 + 1 ) ;
break;
}
V_2 -> V_254 = 0 ;
F_144 ( V_2 , V_248 , V_248 ) ;
if ( ++ V_248 == V_2 -> V_14 )
V_248 = 0 ;
if ( V_248 == V_247 )
break;
}
if ( V_252 )
F_145 ( & V_2 -> V_38 ) ;
}
static int F_146 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
int V_138 ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_160 & V_261 ) {
V_2 -> V_160 &= ~ V_261 ;
V_138 = V_261 ;
} else if ( V_2 -> V_160 & V_262 ) {
V_2 -> V_160 &= ~ V_262 ;
V_138 = V_262 ;
} else if ( V_2 -> V_160 & V_263 ) {
V_2 -> V_160 &= ~ V_263 ;
V_138 = V_263 ;
} else {
V_2 -> V_159 = false ;
V_2 -> V_158 = false ;
V_138 = 0 ;
}
F_16 ( & V_2 -> V_48 , V_22 ) ;
return V_138 ;
}
static void F_147 ( struct V_264 * V_265 )
{
struct V_1 * V_2 = F_148 ( V_265 , struct V_1 , V_266 ) ;
int V_267 ;
V_2 -> V_159 = true ;
while( ( V_267 = F_146 ( V_2 ) ) ) {
switch ( V_267 ) {
case V_261 :
F_149 ( ( L_95 , V_2 -> V_8 ) ) ;
switch( V_2 -> V_59 . V_60 ) {
case V_80 :
F_138 ( V_2 ) ;
break;
case V_61 :
while( F_150 ( V_2 ) ) ;
break;
case V_268 :
case V_269 :
case V_270 :
case V_271 :
while( F_151 ( V_2 ) ) ;
break;
}
if ( V_2 -> V_272 )
F_152 ( V_2 ) ;
break;
case V_262 :
F_153 ( V_2 ) ;
break;
case V_263 :
F_149 ( ( L_96 , V_2 -> V_8 ) ) ;
V_2 -> V_273 = 0 ;
V_2 -> V_274 = 0 ;
V_2 -> V_275 = 0 ;
V_2 -> V_276 = 0 ;
break;
default:
F_149 ( ( L_97 , V_2 -> V_8 ) ) ;
break;
}
}
F_149 ( ( L_98 , V_2 -> V_8 ) ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_38 . V_21 ;
F_149 ( ( L_99 , V_2 -> V_8 ) ) ;
if ( V_21 )
F_54 ( V_21 ) ;
}
static void F_154 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_277 ) {
V_2 -> V_54 |= V_147 ;
V_2 -> V_278 . V_279 ++ ;
} else {
V_2 -> V_54 &= ~ V_147 ;
V_2 -> V_278 . V_280 ++ ;
}
F_141 ( ( L_100 , V_2 -> V_8 , V_2 -> V_54 ) ) ;
if ( ( V_2 -> V_274 ) ++ == V_281 ) {
F_155 ( V_2 , V_282 ) ;
return;
}
V_2 -> V_107 . V_111 ++ ;
F_30 ( & V_2 -> V_283 ) ;
F_30 ( & V_2 -> V_284 ) ;
V_2 -> V_160 |= V_263 ;
}
static void F_156 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_285 ) {
V_2 -> V_54 |= V_146 ;
V_2 -> V_278 . V_286 ++ ;
} else {
V_2 -> V_54 &= ~ V_146 ;
V_2 -> V_278 . V_287 ++ ;
}
F_141 ( ( L_101 , V_2 -> V_8 , V_2 -> V_54 ) ) ;
if ( ( V_2 -> V_276 ) ++ == V_281 ) {
F_155 ( V_2 , V_288 ) ;
return;
}
V_2 -> V_107 . V_110 ++ ;
F_30 ( & V_2 -> V_283 ) ;
F_30 ( & V_2 -> V_284 ) ;
V_2 -> V_160 |= V_263 ;
if ( F_157 ( & V_2 -> V_38 ) ) {
if ( V_2 -> V_38 . V_21 ) {
if ( V_2 -> V_38 . V_21 -> V_58 ) {
if ( V_2 -> V_54 & V_146 ) {
V_2 -> V_38 . V_21 -> V_58 = 0 ;
V_2 -> V_160 |= V_262 ;
return;
}
} else {
if ( ! ( V_2 -> V_54 & V_146 ) )
V_2 -> V_38 . V_21 -> V_58 = 1 ;
}
}
}
}
static void F_158 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_255 ) {
V_2 -> V_54 |= V_148 ;
V_2 -> V_278 . V_289 ++ ;
} else {
V_2 -> V_54 &= ~ V_148 ;
V_2 -> V_278 . V_290 ++ ;
}
F_141 ( ( L_102 , V_2 -> V_8 , V_2 -> V_54 ) ) ;
if ( ( V_2 -> V_275 ) ++ == V_281 ) {
F_155 ( V_2 , V_291 ) ;
return;
}
V_2 -> V_107 . V_113 ++ ;
#if V_292
if ( V_2 -> V_43 ) {
if ( V_2 -> V_54 & V_148 )
F_114 ( V_2 -> V_227 ) ;
else
F_115 ( V_2 -> V_227 ) ;
}
#endif
F_30 ( & V_2 -> V_283 ) ;
F_30 ( & V_2 -> V_284 ) ;
V_2 -> V_160 |= V_263 ;
if ( F_159 ( & V_2 -> V_38 ) ) {
if ( V_2 -> V_54 & V_148 )
F_30 ( & V_2 -> V_38 . V_49 ) ;
else {
if ( V_2 -> V_38 . V_21 )
F_160 ( V_2 -> V_38 . V_21 ) ;
}
}
}
static void F_161 ( struct V_1 * V_2 , unsigned short V_12 )
{
if ( V_12 & V_256 ) {
V_2 -> V_54 |= V_149 ;
V_2 -> V_278 . V_293 ++ ;
} else {
V_2 -> V_54 &= ~ V_149 ;
V_2 -> V_278 . V_294 ++ ;
}
F_141 ( ( L_103 , V_2 -> V_8 , V_2 -> V_54 ) ) ;
if ( ( V_2 -> V_273 ) ++ == V_281 ) {
F_155 ( V_2 , V_295 ) ;
return;
}
V_2 -> V_107 . V_112 ++ ;
F_30 ( & V_2 -> V_283 ) ;
F_30 ( & V_2 -> V_284 ) ;
V_2 -> V_160 |= V_263 ;
}
static void F_162 ( struct V_1 * V_2 )
{
unsigned int V_4 = V_2 -> V_296 ;
unsigned int V_6 = V_2 -> V_297 ;
unsigned short V_298 ;
while ( F_102 ( V_2 , V_299 ) & V_300 ) {
V_298 = F_102 ( V_2 , V_301 ) ;
F_141 ( ( L_104 , V_2 -> V_8 , V_298 ) ) ;
if ( F_139 ( V_2 -> V_15 [ V_6 ] ) ) {
F_163 ( V_2 ) ;
V_2 -> V_272 = 1 ;
continue;
}
V_2 -> V_15 [ V_6 ] . V_64 [ V_4 ++ ] = ( unsigned char ) V_298 ;
if ( V_2 -> V_59 . V_60 == V_80 )
V_2 -> V_15 [ V_6 ] . V_64 [ V_4 ++ ] = ( unsigned char ) ( V_298 >> 8 ) ;
if ( V_4 == V_2 -> V_302 || ( V_298 & V_303 ) ) {
F_164 ( V_2 -> V_15 [ V_6 ] , V_4 ) ;
F_165 ( V_2 -> V_15 [ V_6 ] , V_304 | ( V_298 >> 8 ) ) ;
V_2 -> V_296 = V_4 = 0 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
V_2 -> V_160 |= V_261 ;
}
}
V_2 -> V_297 = V_6 ;
V_2 -> V_296 = V_4 ;
}
static void F_166 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_102 ( V_2 , V_299 ) ;
F_141 ( ( L_105 , V_2 -> V_8 , V_12 ) ) ;
F_103 ( V_2 , V_299 , V_12 ) ;
V_2 -> V_305 = true ;
if ( V_2 -> V_59 . V_60 == V_80 ) {
if ( V_12 & V_306 ) {
if ( V_2 -> V_77 )
F_167 ( V_2 , V_12 ) ;
}
if ( V_2 -> V_307 && ( V_12 & V_300 ) )
F_162 ( V_2 ) ;
if ( ( V_12 & V_308 ) && ( V_12 & V_309 ) ) {
V_2 -> V_107 . V_119 ++ ;
if ( V_2 -> V_38 . V_21 ) {
if ( ! ( V_12 & V_2 -> V_257 ) ) {
if ( V_2 -> V_310 & V_311 ) {
F_143 ( & V_2 -> V_38 , 0 , V_312 ) ;
if ( V_2 -> V_38 . V_22 & V_313 )
F_168 ( V_2 -> V_38 . V_21 ) ;
}
}
}
}
} else {
if ( V_12 & ( V_306 + V_314 ) )
F_167 ( V_2 , V_12 ) ;
if ( V_2 -> V_307 && ( V_12 & V_300 ) )
F_162 ( V_2 ) ;
if ( V_12 & V_315 ) {
if ( V_12 & V_316 )
V_2 -> V_107 . V_317 ++ ;
else
V_2 -> V_107 . V_318 ++ ;
F_30 ( & V_2 -> V_284 ) ;
}
if ( V_12 & V_319 )
F_152 ( V_2 ) ;
}
if ( V_12 & V_282 )
F_154 ( V_2 , V_12 ) ;
if ( V_12 & V_288 )
F_156 ( V_2 , V_12 ) ;
if ( V_12 & V_291 )
F_158 ( V_2 , V_12 ) ;
if ( V_12 & V_295 )
F_161 ( V_2 , V_12 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_170 ( V_2 , V_320 ) ;
F_141 ( ( L_106 , V_2 -> V_8 , V_12 ) ) ;
F_171 ( V_2 , V_320 , V_12 ) ;
if ( V_12 & ( V_321 + V_322 ) ) {
F_141 ( ( L_107 , V_2 -> V_8 ) ) ;
V_2 -> V_272 = true ;
}
V_2 -> V_160 |= V_261 ;
}
static void F_172 ( struct V_1 * V_2 )
{
unsigned int V_12 = F_170 ( V_2 , V_323 ) ;
F_141 ( ( L_108 , V_2 -> V_8 , V_12 ) ) ;
F_171 ( V_2 , V_323 , V_12 ) ;
if ( V_12 & ( V_321 + V_322 + V_277 ) ) {
V_2 -> V_160 |= V_262 ;
}
}
static bool F_173 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_2 -> V_9 ;
bool V_138 = false ;
do {
if ( V_6 )
V_6 -- ;
else
V_6 = V_2 -> V_10 - 1 ;
if ( ! F_140 ( V_2 -> V_11 [ V_6 ] ) )
break;
V_2 -> V_324 = V_6 ;
V_138 = true ;
} while ( V_6 != V_2 -> V_9 );
return V_138 ;
}
static void F_167 ( struct V_1 * V_2 , unsigned short V_12 )
{
F_141 ( ( L_109 , V_2 -> V_8 , V_12 ) ) ;
F_155 ( V_2 , V_325 + V_306 + V_314 ) ;
F_174 ( V_2 ) ;
if ( V_12 & V_314 ) {
unsigned short V_326 = F_102 ( V_2 , V_166 ) ;
F_103 ( V_2 , V_166 , ( unsigned short ) ( V_326 | V_285 ) ) ;
F_103 ( V_2 , V_166 , V_326 ) ;
}
if ( V_2 -> V_77 ) {
if ( V_2 -> V_59 . V_60 != V_80 ) {
if ( V_12 & V_314 )
V_2 -> V_107 . V_152 ++ ;
else if ( V_12 & V_306 )
V_2 -> V_107 . V_150 ++ ;
}
if ( F_173 ( V_2 ) ) {
F_46 ( V_2 ) ;
F_38 ( V_2 ) ;
return;
}
V_2 -> V_77 = false ;
F_175 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_59 . V_60 != V_80 && V_2 -> V_327 ) {
V_2 -> V_54 &= ~ V_55 ;
V_2 -> V_327 = false ;
F_34 ( V_2 ) ;
}
#if V_292
if ( V_2 -> V_43 )
F_124 ( V_2 ) ;
else
#endif
{
if ( V_2 -> V_38 . V_21 && ( V_2 -> V_38 . V_21 -> V_69 || V_2 -> V_38 . V_21 -> V_58 ) ) {
F_56 ( V_2 ) ;
return;
}
V_2 -> V_160 |= V_262 ;
}
}
}
static void F_176 ( struct V_1 * V_2 , unsigned int V_328 , unsigned int V_329 )
{
struct V_330 * V_331 , * V_332 ;
for ( V_331 = V_2 -> V_333 , V_332 = NULL ; V_331 != NULL ; V_331 = V_331 -> V_334 ) {
if ( V_331 -> V_3 & V_328 ) {
V_331 -> V_3 = V_329 ;
F_30 ( & V_331 -> V_335 ) ;
if ( V_332 != NULL )
V_332 -> V_334 = V_331 -> V_334 ;
else
V_2 -> V_333 = V_331 -> V_334 ;
} else
V_332 = V_331 ;
}
}
static T_6 F_177 ( int V_336 , void * V_337 )
{
struct V_1 * V_2 = V_337 ;
unsigned int V_338 ;
unsigned int V_6 ;
F_141 ( ( L_110 , V_2 -> V_145 ) ) ;
while( ( V_338 = F_170 ( V_2 , V_339 ) & 0xffffff00 ) ) {
F_141 ( ( L_111 , V_2 -> V_8 , V_338 ) ) ;
V_2 -> V_305 = true ;
for( V_6 = 0 ; V_6 < V_2 -> V_340 ; V_6 ++ ) {
if ( V_2 -> V_341 [ V_6 ] == NULL )
continue;
F_83 ( & V_2 -> V_341 [ V_6 ] -> V_48 ) ;
if ( V_338 & ( V_342 << V_6 ) )
F_166 ( V_2 -> V_341 [ V_6 ] ) ;
if ( V_338 & ( V_343 << ( V_6 * 2 ) ) )
F_169 ( V_2 -> V_341 [ V_6 ] ) ;
if ( V_338 & ( V_344 << ( V_6 * 2 ) ) )
F_172 ( V_2 -> V_341 [ V_6 ] ) ;
F_84 ( & V_2 -> V_341 [ V_6 ] -> V_48 ) ;
}
}
if ( V_2 -> V_345 ) {
unsigned int V_329 ;
unsigned int V_328 ;
F_83 ( & V_2 -> V_48 ) ;
while ( ( V_328 = F_170 ( V_2 , V_346 ) ) != 0 ) {
F_141 ( ( L_112 , V_2 -> V_8 , V_328 ) ) ;
V_329 = F_170 ( V_2 , V_347 ) ;
F_171 ( V_2 , V_346 , V_328 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_340 ; V_6 ++ ) {
if ( V_2 -> V_341 [ V_6 ] != NULL )
F_176 ( V_2 -> V_341 [ V_6 ] , V_328 , V_329 ) ;
}
}
F_84 ( & V_2 -> V_48 ) ;
}
for( V_6 = 0 ; V_6 < V_2 -> V_340 ; V_6 ++ ) {
struct V_1 * V_38 = V_2 -> V_341 [ V_6 ] ;
if ( V_38 == NULL )
continue;
F_83 ( & V_38 -> V_48 ) ;
if ( ( V_38 -> V_38 . V_4 || V_38 -> V_43 ) &&
V_38 -> V_160 && ! V_38 -> V_159 &&
! V_38 -> V_158 ) {
F_141 ( ( L_113 , V_38 -> V_8 ) ) ;
F_178 ( & V_38 -> V_266 ) ;
V_38 -> V_158 = true ;
}
F_84 ( & V_38 -> V_48 ) ;
}
F_141 ( ( L_114 , V_2 -> V_145 ) ) ;
return V_348 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_13 ( ( L_115 , V_2 -> V_8 ) ) ;
if ( F_22 ( & V_2 -> V_38 ) )
return 0 ;
if ( ! V_2 -> V_67 ) {
V_2 -> V_67 = F_179 ( V_2 -> V_68 , V_349 ) ;
if ( ! V_2 -> V_67 ) {
F_12 ( ( L_116 , V_2 -> V_8 ) ) ;
return - V_234 ;
}
}
V_2 -> V_160 = 0 ;
memset ( & V_2 -> V_107 , 0 , sizeof( V_2 -> V_107 ) ) ;
F_32 ( V_2 ) ;
if ( V_2 -> V_38 . V_21 )
F_180 ( V_350 , & V_2 -> V_38 . V_21 -> V_22 ) ;
F_181 ( & V_2 -> V_38 , 1 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
if ( ! F_22 ( & V_2 -> V_38 ) )
return;
F_13 ( ( L_117 , V_2 -> V_8 ) ) ;
F_30 ( & V_2 -> V_283 ) ;
F_30 ( & V_2 -> V_284 ) ;
F_182 ( & V_2 -> V_62 ) ;
F_182 ( & V_2 -> V_260 ) ;
F_183 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_56 ( V_2 ) ;
F_163 ( V_2 ) ;
F_155 ( V_2 , V_351 | V_352 ) ;
if ( ! V_2 -> V_38 . V_21 || V_2 -> V_38 . V_21 -> V_353 . V_52 & V_354 ) {
V_2 -> V_54 &= ~ ( V_55 | V_56 ) ;
F_34 ( V_2 ) ;
}
F_184 ( & V_2 -> V_333 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
if ( V_2 -> V_38 . V_21 )
F_185 ( V_350 , & V_2 -> V_38 . V_21 -> V_22 ) ;
F_181 ( & V_2 -> V_38 , 0 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_163 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_59 . V_60 != V_80 ||
V_2 -> V_43 )
F_186 ( V_2 ) ;
else
F_187 ( V_2 ) ;
F_34 ( V_2 ) ;
V_2 -> V_275 = 0 ;
V_2 -> V_276 = 0 ;
V_2 -> V_273 = 0 ;
V_2 -> V_274 = 0 ;
F_188 ( V_2 , V_291 | V_288 | V_282 | V_295 ) ;
F_90 ( V_2 ) ;
if ( V_2 -> V_43 ||
( V_2 -> V_38 . V_21 && V_2 -> V_38 . V_21 -> V_353 . V_52 & V_355 ) )
F_152 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned V_356 ;
int V_357 ;
if ( ! V_2 -> V_38 . V_21 )
return;
F_13 ( ( L_118 , V_2 -> V_8 ) ) ;
V_356 = V_2 -> V_38 . V_21 -> V_353 . V_52 ;
if ( V_356 & V_53 )
V_2 -> V_54 |= V_55 | V_56 ;
else
V_2 -> V_54 &= ~ ( V_55 | V_56 ) ;
switch ( V_356 & V_358 ) {
case V_359 : V_2 -> V_59 . V_132 = 5 ; break;
case V_360 : V_2 -> V_59 . V_132 = 6 ; break;
case V_361 : V_2 -> V_59 . V_132 = 7 ; break;
case V_362 : V_2 -> V_59 . V_132 = 8 ; break;
default: V_2 -> V_59 . V_132 = 7 ; break;
}
V_2 -> V_59 . V_133 = ( V_356 & V_363 ) ? 2 : 1 ;
if ( V_356 & V_364 )
V_2 -> V_59 . V_118 = ( V_356 & V_365 ) ? V_366 : V_367 ;
else
V_2 -> V_59 . V_118 = V_368 ;
V_357 = V_2 -> V_59 . V_132 +
V_2 -> V_59 . V_133 + 1 ;
V_2 -> V_59 . V_76 = F_189 ( V_2 -> V_38 . V_21 ) ;
if ( V_2 -> V_59 . V_76 ) {
V_2 -> V_46 = ( 32 * V_242 * V_357 ) /
V_2 -> V_59 . V_76 ;
}
V_2 -> V_46 += V_242 / 50 ;
F_190 ( & V_2 -> V_38 , V_356 & V_57 ) ;
F_191 ( & V_2 -> V_38 , ~ V_356 & V_369 ) ;
V_2 -> V_310 = V_319 ;
if ( F_192 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_310 |= V_370 | V_371 ;
if ( F_193 ( V_2 -> V_38 . V_21 ) || F_194 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_310 |= V_311 ;
if ( F_195 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_257 |= V_370 | V_371 ;
if ( F_196 ( V_2 -> V_38 . V_21 ) ) {
V_2 -> V_257 |= V_311 ;
if ( F_195 ( V_2 -> V_38 . V_21 ) )
V_2 -> V_257 |= V_372 ;
}
F_85 ( V_2 ) ;
}
static int F_75 ( struct V_1 * V_2 , struct V_108 T_2 * V_373 )
{
F_13 ( ( L_119 , V_2 -> V_8 ) ) ;
if ( ! V_373 ) {
memset ( & V_2 -> V_107 , 0 , sizeof( V_2 -> V_107 ) ) ;
} else {
if ( F_80 ( V_373 , & V_2 -> V_107 , sizeof( struct V_108 ) ) )
return - V_134 ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_7 T_2 * V_122 )
{
F_13 ( ( L_120 , V_2 -> V_8 ) ) ;
if ( F_80 ( V_122 , & V_2 -> V_59 , sizeof( T_7 ) ) )
return - V_134 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , T_7 T_2 * V_135 )
{
unsigned long V_22 ;
T_7 V_123 ;
F_13 ( ( L_121 , V_2 -> V_8 ) ) ;
if ( F_82 ( & V_123 , V_135 , sizeof( T_7 ) ) )
return - V_134 ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( V_123 . V_60 == V_136 )
V_2 -> V_137 = V_123 . V_127 ;
else
memcpy ( & V_2 -> V_59 , & V_123 , sizeof( T_7 ) ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , int T_2 * V_374 )
{
F_13 ( ( L_122 , V_2 -> V_8 , V_2 -> V_374 ) ) ;
if ( F_197 ( V_2 -> V_374 , V_374 ) )
return - V_134 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , int V_374 )
{
unsigned long V_22 ;
F_13 ( ( L_123 , V_2 -> V_8 , V_374 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_374 = V_374 ;
if ( V_2 -> V_59 . V_60 != V_80 )
F_198 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , int V_375 )
{
unsigned long V_22 ;
F_13 ( ( L_124 , V_2 -> V_8 , V_375 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( V_375 ) {
if ( ! V_2 -> V_73 )
F_46 ( V_2 ) ;
} else {
if ( V_2 -> V_73 )
F_56 ( V_2 ) ;
}
F_16 ( & V_2 -> V_48 , V_22 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_13 ( ( L_125 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_174 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , int V_375 )
{
unsigned long V_22 ;
unsigned int V_302 ;
F_13 ( ( L_126 , V_2 -> V_8 , V_375 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_302 = ( ( unsigned int ) V_375 ) >> 16 ;
if ( V_302 ) {
if ( ( V_302 > V_376 ) || ( V_302 % 4 ) ) {
F_16 ( & V_2 -> V_48 , V_22 ) ;
return - V_165 ;
}
V_2 -> V_302 = V_302 ;
if ( V_302 < 128 )
V_2 -> V_307 = 1 ;
else
V_2 -> V_307 = 0 ;
F_163 ( V_2 ) ;
}
V_375 &= 3 ;
if ( V_375 ) {
if ( ! V_2 -> V_377 )
F_152 ( V_2 ) ;
else if ( V_375 == 2 ) {
F_103 ( V_2 , V_378 , F_102 ( V_2 , V_378 ) | V_277 ) ;
}
} else {
if ( V_2 -> V_377 )
F_163 ( V_2 ) ;
}
F_16 ( & V_2 -> V_48 , V_22 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int T_2 * V_379 )
{
unsigned long V_22 ;
int V_380 ;
int V_138 = 0 ;
struct V_108 V_381 , V_109 ;
int V_382 ;
int V_383 ;
struct V_384 V_385 , V_386 ;
F_199 ( V_387 , V_78 ) ;
if ( F_200 ( V_383 , V_379 ) )
return - V_134 ;
F_13 ( ( L_127 , V_2 -> V_8 , V_383 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_90 ( V_2 ) ;
V_380 = V_2 -> V_54 ;
V_382 = V_383 &
( ( ( V_380 & V_147 ) ? V_388 : V_389 ) +
( ( V_380 & V_148 ) ? V_390 : V_391 ) +
( ( V_380 & V_146 ) ? V_392 : V_393 ) +
( ( V_380 & V_149 ) ? V_394 : V_395 ) ) ;
if ( V_382 ) {
F_16 ( & V_2 -> V_48 , V_22 ) ;
goto exit;
}
V_381 = V_2 -> V_107 ;
V_385 = V_2 -> V_278 ;
if ( V_383 & ( V_396 + V_397 ) ) {
unsigned short V_326 = F_102 ( V_2 , V_398 ) ;
if ( ! ( V_326 & V_315 ) )
F_103 ( V_2 , V_398 , ( unsigned short ) ( V_326 | V_315 ) ) ;
}
F_201 ( V_399 ) ;
F_202 ( & V_2 -> V_284 , & V_387 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
for(; ; ) {
F_203 () ;
if ( F_50 ( V_78 ) ) {
V_138 = - V_400 ;
break;
}
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_109 = V_2 -> V_107 ;
V_386 = V_2 -> V_278 ;
F_201 ( V_399 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
if ( V_386 . V_279 == V_385 . V_279 &&
V_386 . V_280 == V_385 . V_280 &&
V_386 . V_289 == V_385 . V_289 &&
V_386 . V_290 == V_385 . V_290 &&
V_386 . V_286 == V_385 . V_286 &&
V_386 . V_287 == V_385 . V_287 &&
V_386 . V_293 == V_385 . V_293 &&
V_386 . V_294 == V_385 . V_294 &&
V_109 . V_318 == V_381 . V_318 &&
V_109 . V_317 == V_381 . V_317 ) {
V_138 = - V_66 ;
break;
}
V_382 = V_383 &
( ( V_386 . V_279 != V_385 . V_279 ? V_388 : 0 ) +
( V_386 . V_280 != V_385 . V_280 ? V_389 : 0 ) +
( V_386 . V_289 != V_385 . V_289 ? V_390 : 0 ) +
( V_386 . V_290 != V_385 . V_290 ? V_391 : 0 ) +
( V_386 . V_286 != V_385 . V_286 ? V_392 : 0 ) +
( V_386 . V_287 != V_385 . V_287 ? V_393 : 0 ) +
( V_386 . V_293 != V_385 . V_293 ? V_394 : 0 ) +
( V_386 . V_294 != V_385 . V_294 ? V_395 : 0 ) +
( V_109 . V_318 != V_381 . V_318 ? V_396 : 0 ) +
( V_109 . V_317 != V_381 . V_317 ? V_397 : 0 ) ) ;
if ( V_382 )
break;
V_381 = V_109 ;
V_385 = V_386 ;
}
F_204 ( & V_2 -> V_284 , & V_387 ) ;
F_201 ( V_401 ) ;
if ( V_383 & ( V_396 + V_397 ) ) {
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( ! F_205 ( & V_2 -> V_284 ) ) {
F_103 ( V_2 , V_398 ,
( unsigned short ) ( F_102 ( V_2 , V_398 ) & ~ V_315 ) ) ;
}
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
exit:
if ( V_138 == 0 )
V_138 = F_197 ( V_382 , V_379 ) ;
return V_138 ;
}
static int F_76 ( struct V_1 * V_2 , int T_2 * V_402 )
{
F_13 ( ( L_128 , V_2 -> V_8 , V_2 -> V_402 ) ) ;
if ( F_197 ( V_2 -> V_402 , V_402 ) )
return - V_134 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , int V_402 )
{
unsigned long V_22 ;
unsigned short V_326 ;
F_13 ( ( L_129 , V_2 -> V_8 , V_402 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_402 = V_402 ;
F_206 ( V_2 ) ;
V_326 = F_102 ( V_2 , V_166 ) ;
if ( V_2 -> V_402 & V_403 )
V_326 |= V_404 ;
else
V_326 &= ~ V_404 ;
F_103 ( V_2 , V_166 , V_326 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , int T_2 * V_405 )
{
F_13 ( ( L_130 , V_2 -> V_8 , V_2 -> V_405 ) ) ;
if ( F_197 ( V_2 -> V_405 , V_405 ) )
return - V_134 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , int V_405 )
{
unsigned long V_22 ;
F_13 ( ( L_131 , V_2 -> V_8 , V_405 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_405 = V_405 ;
F_171 ( V_2 , V_406 , V_405 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , int T_2 * V_407 )
{
F_13 ( ( L_132 , V_2 -> V_8 , V_2 -> V_407 ) ) ;
if ( F_197 ( V_2 -> V_407 , V_407 ) )
return - V_134 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , int V_407 )
{
unsigned long V_22 ;
F_13 ( ( L_133 , V_2 -> V_8 , V_407 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_407 = V_407 ;
F_171 ( V_2 , V_408 , V_407 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_409 T_2 * V_410 )
{
unsigned long V_22 ;
struct V_409 V_411 ;
T_8 V_3 ;
if ( ! V_2 -> V_345 )
return - V_165 ;
if ( F_82 ( & V_411 , V_410 , sizeof( V_411 ) ) )
return - V_134 ;
F_13 ( ( L_134 ,
V_2 -> V_8 , V_411 . V_329 , V_411 . V_412 ,
V_411 . V_413 , V_411 . V_414 ) ) ;
F_15 ( & V_2 -> V_341 [ 0 ] -> V_48 , V_22 ) ;
if ( V_411 . V_414 ) {
V_3 = F_170 ( V_2 , V_415 ) ;
V_3 |= V_411 . V_414 & V_411 . V_413 ;
V_3 &= ~ ( V_411 . V_414 & ~ V_411 . V_413 ) ;
F_171 ( V_2 , V_415 , V_3 ) ;
}
if ( V_411 . V_412 ) {
V_3 = F_170 ( V_2 , V_347 ) ;
V_3 |= V_411 . V_412 & V_411 . V_329 ;
V_3 &= ~ ( V_411 . V_412 & ~ V_411 . V_329 ) ;
F_171 ( V_2 , V_347 , V_3 ) ;
}
F_16 ( & V_2 -> V_341 [ 0 ] -> V_48 , V_22 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_409 T_2 * V_410 )
{
struct V_409 V_411 ;
if ( ! V_2 -> V_345 )
return - V_165 ;
V_411 . V_329 = F_170 ( V_2 , V_347 ) ;
V_411 . V_412 = 0xffffffff ;
V_411 . V_413 = F_170 ( V_2 , V_415 ) ;
V_411 . V_414 = 0xffffffff ;
if ( F_80 ( V_410 , & V_411 , sizeof( V_411 ) ) )
return - V_134 ;
F_13 ( ( L_135 ,
V_2 -> V_8 , V_411 . V_329 , V_411 . V_413 ) ) ;
return 0 ;
}
static void F_207 ( struct V_330 * V_331 , unsigned int V_3 )
{
F_208 ( & V_331 -> V_335 ) ;
F_209 ( & V_331 -> V_387 , V_78 ) ;
V_331 -> V_3 = V_3 ;
}
static void F_210 ( struct V_330 * * V_416 , struct V_330 * V_331 )
{
F_201 ( V_399 ) ;
F_202 ( & V_331 -> V_335 , & V_331 -> V_387 ) ;
V_331 -> V_334 = * V_416 ;
* V_416 = V_331 ;
}
static void F_211 ( struct V_330 * * V_416 , struct V_330 * V_417 )
{
struct V_330 * V_331 , * V_332 ;
F_204 ( & V_417 -> V_335 , & V_417 -> V_387 ) ;
F_201 ( V_401 ) ;
for ( V_331 = * V_416 , V_332 = NULL ; V_331 != NULL ; V_332 = V_331 , V_331 = V_331 -> V_334 ) {
if ( V_331 == V_417 ) {
if ( V_332 != NULL )
V_332 -> V_334 = V_331 -> V_334 ;
else
* V_416 = V_331 -> V_334 ;
break;
}
}
}
static void F_184 ( struct V_330 * * V_416 )
{
while ( * V_416 != NULL ) {
F_30 ( & ( * V_416 ) -> V_335 ) ;
* V_416 = ( * V_416 ) -> V_334 ;
}
}
static int F_63 ( struct V_1 * V_2 , struct V_409 T_2 * V_410 )
{
unsigned long V_22 ;
int V_138 = 0 ;
struct V_409 V_411 ;
struct V_330 V_387 ;
T_9 V_329 ;
if ( ! V_2 -> V_345 )
return - V_165 ;
if ( F_82 ( & V_411 , V_410 , sizeof( V_411 ) ) )
return - V_134 ;
F_13 ( ( L_136 ,
V_2 -> V_8 , V_411 . V_329 , V_411 . V_412 ) ) ;
if ( ( V_411 . V_412 &= ~ F_170 ( V_2 , V_415 ) ) == 0 )
return - V_165 ;
F_207 ( & V_387 , V_411 . V_412 ) ;
F_15 ( & V_2 -> V_341 [ 0 ] -> V_48 , V_22 ) ;
F_171 ( V_2 , V_418 , F_170 ( V_2 , V_418 ) | V_411 . V_412 ) ;
V_329 = F_170 ( V_2 , V_347 ) ;
if ( V_411 . V_412 & ~ ( V_329 ^ V_411 . V_329 ) ) {
V_411 . V_329 = V_329 ;
} else {
F_210 ( & V_2 -> V_333 , & V_387 ) ;
F_16 ( & V_2 -> V_341 [ 0 ] -> V_48 , V_22 ) ;
F_203 () ;
if ( F_50 ( V_78 ) )
V_138 = - V_400 ;
else
V_411 . V_329 = V_387 . V_3 ;
F_15 ( & V_2 -> V_341 [ 0 ] -> V_48 , V_22 ) ;
F_211 ( & V_2 -> V_333 , & V_387 ) ;
}
if ( V_2 -> V_333 == NULL )
F_171 ( V_2 , V_418 , 0 ) ;
F_16 ( & V_2 -> V_341 [ 0 ] -> V_48 , V_22 ) ;
if ( ( V_138 == 0 ) && F_80 ( V_410 , & V_411 , sizeof( V_411 ) ) )
V_138 = - V_134 ;
return V_138 ;
}
static int F_60 ( struct V_1 * V_2 , int V_82 )
{
unsigned long V_22 ;
int V_138 ;
struct V_108 V_381 , V_109 ;
F_199 ( V_387 , V_78 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_381 = V_2 -> V_107 ;
F_202 ( & V_2 -> V_283 , & V_387 ) ;
F_201 ( V_399 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
for(; ; ) {
F_203 () ;
if ( F_50 ( V_78 ) ) {
V_138 = - V_400 ;
break;
}
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_109 = V_2 -> V_107 ;
F_201 ( V_399 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
if ( V_109 . V_112 == V_381 . V_112 && V_109 . V_111 == V_381 . V_111 &&
V_109 . V_113 == V_381 . V_113 && V_109 . V_110 == V_381 . V_110 ) {
V_138 = - V_66 ;
break;
}
if ( ( V_82 & V_419 && V_109 . V_112 != V_381 . V_112 ) ||
( V_82 & V_420 && V_109 . V_111 != V_381 . V_111 ) ||
( V_82 & V_421 && V_109 . V_113 != V_381 . V_113 ) ||
( V_82 & V_422 && V_109 . V_110 != V_381 . V_110 ) ) {
V_138 = 0 ;
break;
}
V_381 = V_109 ;
}
F_204 ( & V_2 -> V_283 , & V_387 ) ;
F_201 ( V_401 ) ;
return V_138 ;
}
static int F_212 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned int V_423 ;
unsigned long V_22 ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_90 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
V_423 = ( ( V_2 -> V_54 & V_55 ) ? V_424 : 0 ) +
( ( V_2 -> V_54 & V_56 ) ? V_425 : 0 ) +
( ( V_2 -> V_54 & V_148 ) ? V_426 : 0 ) +
( ( V_2 -> V_54 & V_149 ) ? V_419 : 0 ) +
( ( V_2 -> V_54 & V_147 ) ? V_420 : 0 ) +
( ( V_2 -> V_54 & V_146 ) ? V_422 : 0 ) ;
F_13 ( ( L_137 , V_2 -> V_8 , V_423 ) ) ;
return V_423 ;
}
static int F_213 ( struct V_20 * V_21 ,
unsigned int V_427 , unsigned int V_428 )
{
struct V_1 * V_2 = V_21 -> V_37 ;
unsigned long V_22 ;
F_13 ( ( L_138 , V_2 -> V_8 , V_427 , V_428 ) ) ;
if ( V_427 & V_424 )
V_2 -> V_54 |= V_55 ;
if ( V_427 & V_425 )
V_2 -> V_54 |= V_56 ;
if ( V_428 & V_424 )
V_2 -> V_54 &= ~ V_55 ;
if ( V_428 & V_425 )
V_2 -> V_54 &= ~ V_56 ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_34 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
return 0 ;
}
static int F_214 ( struct V_429 * V_38 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_148 ( V_38 , struct V_1 , V_38 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_90 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
return ( V_2 -> V_54 & V_148 ) ? 1 : 0 ;
}
static void F_215 ( struct V_429 * V_38 , int V_430 )
{
unsigned long V_22 ;
struct V_1 * V_2 = F_148 ( V_38 , struct V_1 , V_38 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
if ( V_430 )
V_2 -> V_54 |= V_55 | V_56 ;
else
V_2 -> V_54 &= ~ ( V_55 | V_56 ) ;
F_34 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
static int F_19 ( struct V_20 * V_21 , struct V_27 * V_28 ,
struct V_1 * V_2 )
{
F_199 ( V_387 , V_78 ) ;
int V_29 ;
bool V_431 = false ;
unsigned long V_22 ;
int V_432 ;
struct V_429 * V_38 = & V_2 -> V_38 ;
F_13 ( ( L_139 , V_21 -> V_47 -> V_17 ) ) ;
if ( V_28 -> V_433 & V_434 || F_58 ( V_21 ) ) {
F_29 ( V_38 , 1 ) ;
return 0 ;
}
if ( F_216 ( V_21 ) )
V_431 = true ;
V_29 = 0 ;
F_202 ( & V_38 -> V_49 , & V_387 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_38 -> V_4 -- ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
V_38 -> V_435 ++ ;
while ( 1 ) {
if ( F_33 ( V_21 ) && F_22 ( V_38 ) )
F_217 ( V_38 ) ;
F_201 ( V_399 ) ;
if ( F_218 ( V_28 ) || ! F_22 ( V_38 ) ) {
V_29 = ( V_38 -> V_22 & V_436 ) ?
- V_437 : - V_400 ;
break;
}
V_432 = F_219 ( V_38 ) ;
if ( V_431 || V_432 )
break;
if ( F_50 ( V_78 ) ) {
V_29 = - V_400 ;
break;
}
F_13 ( ( L_140 , V_21 -> V_47 -> V_17 ) ) ;
F_220 ( V_21 ) ;
F_203 () ;
F_221 ( V_21 ) ;
}
F_201 ( V_401 ) ;
F_204 ( & V_38 -> V_49 , & V_387 ) ;
if ( ! F_218 ( V_28 ) )
V_38 -> V_4 ++ ;
V_38 -> V_435 -- ;
if ( ! V_29 )
F_29 ( V_38 , 1 ) ;
F_13 ( ( L_141 , V_21 -> V_47 -> V_17 , V_29 ) ) ;
return V_29 ;
}
static int F_222 ( struct V_1 * V_2 )
{
V_2 -> V_438 = F_179 ( V_2 -> V_68 + 5 , V_349 ) ;
if ( V_2 -> V_438 == NULL )
return - V_234 ;
V_2 -> V_439 = F_223 ( V_2 -> V_68 + 5 , V_349 ) ;
if ( ! V_2 -> V_439 ) {
F_183 ( V_2 -> V_438 ) ;
V_2 -> V_438 = NULL ;
return - V_234 ;
}
return 0 ;
}
static void F_224 ( struct V_1 * V_2 )
{
F_183 ( V_2 -> V_438 ) ;
V_2 -> V_438 = NULL ;
F_183 ( V_2 -> V_439 ) ;
V_2 -> V_439 = NULL ;
}
static int F_225 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
unsigned int V_440 ;
V_2 -> V_251 = F_226 ( V_2 -> V_441 , V_442 ,
& V_2 -> V_443 ) ;
if ( V_2 -> V_251 == NULL )
return - V_234 ;
V_2 -> V_15 = (struct V_250 * ) V_2 -> V_251 ;
V_2 -> V_11 = ( (struct V_250 * ) V_2 -> V_251 ) + V_2 -> V_14 ;
V_440 = ( unsigned int ) V_2 -> V_443 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_14 ; V_6 ++ ) {
V_2 -> V_15 [ V_6 ] . V_444 = V_440 + ( V_6 * sizeof( struct V_250 ) ) ;
if ( V_6 == V_2 -> V_14 - 1 )
V_2 -> V_15 [ V_6 ] . V_334 = F_227 ( V_440 ) ;
else
V_2 -> V_15 [ V_6 ] . V_334 = F_227 ( V_440 + ( ( V_6 + 1 ) * sizeof( struct V_250 ) ) ) ;
F_164 ( V_2 -> V_15 [ V_6 ] , V_376 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_444 = V_440 + ( ( V_2 -> V_14 + V_6 ) * sizeof( struct V_250 ) ) ;
if ( V_6 == V_2 -> V_10 - 1 )
V_2 -> V_11 [ V_6 ] . V_334 = F_227 ( V_440 + V_2 -> V_14 * sizeof( struct V_250 ) ) ;
else
V_2 -> V_11 [ V_6 ] . V_334 = F_227 ( V_440 + ( ( V_2 -> V_14 + V_6 + 1 ) * sizeof( struct V_250 ) ) ) ;
}
return 0 ;
}
static void F_228 ( struct V_1 * V_2 )
{
if ( V_2 -> V_251 != NULL ) {
F_229 ( V_2 -> V_441 , V_442 , V_2 -> V_251 , V_2 -> V_443 ) ;
V_2 -> V_251 = NULL ;
V_2 -> V_15 = NULL ;
V_2 -> V_11 = NULL ;
}
}
static int F_230 ( struct V_1 * V_2 , struct V_250 * V_251 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( ( V_251 [ V_6 ] . V_64 = F_231 ( V_2 -> V_441 , V_376 , & V_251 [ V_6 ] . V_445 ) ) == NULL )
return - V_234 ;
V_251 [ V_6 ] . V_446 = F_227 ( ( unsigned int ) V_251 [ V_6 ] . V_445 ) ;
}
return 0 ;
}
static void F_232 ( struct V_1 * V_2 , struct V_250 * V_251 , int V_4 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
if ( V_251 [ V_6 ] . V_64 == NULL )
continue;
F_229 ( V_2 -> V_441 , V_376 , V_251 [ V_6 ] . V_64 , V_251 [ V_6 ] . V_445 ) ;
V_251 [ V_6 ] . V_64 = NULL ;
}
}
static int F_233 ( struct V_1 * V_2 )
{
V_2 -> V_14 = 32 ;
V_2 -> V_10 = 32 ;
if ( F_225 ( V_2 ) < 0 ||
F_230 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) < 0 ||
F_230 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) < 0 ||
F_222 ( V_2 ) < 0 ) {
F_12 ( ( L_142 , V_2 -> V_8 ) ) ;
return - V_234 ;
}
F_234 ( V_2 ) ;
return 0 ;
}
static void F_235 ( struct V_1 * V_2 )
{
if ( V_2 -> V_251 ) {
F_232 ( V_2 , V_2 -> V_15 , V_2 -> V_14 ) ;
F_232 ( V_2 , V_2 -> V_11 , V_2 -> V_10 ) ;
F_228 ( V_2 ) ;
}
F_224 ( V_2 ) ;
}
static int F_236 ( struct V_1 * V_2 )
{
if ( F_237 ( V_2 -> V_144 , V_237 , L_143 ) == NULL ) {
F_12 ( ( L_144 ,
V_2 -> V_8 , V_2 -> V_144 ) ) ;
V_2 -> V_36 = V_447 ;
goto V_448;
}
else
V_2 -> V_449 = true ;
V_2 -> V_450 = F_238 ( V_2 -> V_144 , V_237 ) ;
if ( ! V_2 -> V_450 ) {
F_12 ( ( L_145 ,
V_2 -> V_8 , V_2 -> V_144 ) ) ;
V_2 -> V_36 = V_451 ;
goto V_448;
}
return 0 ;
V_448:
F_239 ( V_2 ) ;
return - V_33 ;
}
static void F_239 ( struct V_1 * V_2 )
{
if ( V_2 -> V_452 ) {
F_240 ( V_2 -> V_145 , V_2 ) ;
V_2 -> V_452 = false ;
}
if ( V_2 -> V_449 ) {
F_241 ( V_2 -> V_144 , V_237 ) ;
V_2 -> V_449 = false ;
}
if ( V_2 -> V_450 ) {
F_242 ( V_2 -> V_450 ) ;
V_2 -> V_450 = NULL ;
}
}
static void F_243 ( struct V_1 * V_2 )
{
char * V_453 ;
V_2 -> V_35 = NULL ;
V_2 -> line = V_31 ;
sprintf ( V_2 -> V_8 , L_146 , V_454 , V_2 -> line ) ;
if ( V_2 -> line < V_455 ) {
if ( V_456 [ V_2 -> line ] )
V_2 -> V_68 = V_456 [ V_2 -> line ] ;
}
V_31 ++ ;
if ( ! V_34 )
V_34 = V_2 ;
else {
struct V_1 * V_457 = V_34 ;
while( V_457 -> V_35 )
V_457 = V_457 -> V_35 ;
V_457 -> V_35 = V_2 ;
}
if ( V_2 -> V_68 < 4096 )
V_2 -> V_68 = 4096 ;
else if ( V_2 -> V_68 > 65535 )
V_2 -> V_68 = 65535 ;
switch( V_2 -> V_441 -> V_458 ) {
case V_459 :
V_453 = L_147 ;
break;
case V_460 :
V_453 = L_148 ;
break;
case V_461 :
V_453 = L_149 ;
break;
case V_462 :
V_453 = L_150 ;
V_2 -> V_59 . V_60 = V_80 ;
break;
default:
V_453 = L_151 ;
}
F_2 ( L_152 ,
V_453 , V_2 -> V_8 , V_2 -> V_144 ,
V_2 -> V_145 , V_2 -> V_68 ) ;
#if V_292
F_131 ( V_2 ) ;
#endif
}
static struct V_1 * F_244 ( int V_463 , int V_464 , struct V_465 * V_441 )
{
struct V_1 * V_2 ;
V_2 = F_223 ( sizeof( struct V_1 ) , V_349 ) ;
if ( ! V_2 ) {
F_12 ( ( L_153 ,
V_32 , V_463 , V_464 ) ) ;
} else {
F_245 ( & V_2 -> V_38 ) ;
V_2 -> V_38 . V_25 = & V_466 ;
V_2 -> V_18 = V_19 ;
F_246 ( & V_2 -> V_266 , F_147 ) ;
V_2 -> V_68 = 4096 ;
V_2 -> V_137 = 14745600 ;
V_2 -> V_302 = V_376 ;
V_2 -> V_38 . V_467 = 5 * V_242 / 10 ;
V_2 -> V_38 . V_468 = 30 * V_242 ;
F_208 ( & V_2 -> V_283 ) ;
F_208 ( & V_2 -> V_284 ) ;
F_247 ( & V_2 -> V_42 ) ;
memcpy ( & V_2 -> V_59 , & V_469 , sizeof( T_7 ) ) ;
V_2 -> V_374 = V_470 ;
V_2 -> V_463 = V_463 ;
V_2 -> V_464 = V_464 ;
F_248 ( & V_2 -> V_62 , V_471 , ( unsigned long ) V_2 ) ;
F_248 ( & V_2 -> V_260 , V_472 , ( unsigned long ) V_2 ) ;
V_2 -> V_441 = V_441 ;
V_2 -> V_145 = V_441 -> V_238 ;
V_2 -> V_144 = F_249 ( V_441 , 0 ) ;
V_2 -> V_473 = V_474 ;
V_2 -> V_475 = V_476 ;
V_2 -> V_36 = - 1 ;
}
return V_2 ;
}
static void F_250 ( int V_463 , struct V_465 * V_441 )
{
struct V_1 * V_341 [ V_477 ] ;
int V_6 ;
int V_340 = 1 ;
if ( V_441 -> V_458 == V_460 )
V_340 = 2 ;
else if ( V_441 -> V_458 == V_461 )
V_340 = 4 ;
for ( V_6 = 0 ; V_6 < V_340 ; ++ V_6 ) {
V_341 [ V_6 ] = F_244 ( V_463 , V_6 , V_441 ) ;
if ( V_341 [ V_6 ] == NULL ) {
for ( -- V_6 ; V_6 >= 0 ; -- V_6 ) {
F_251 ( & V_341 [ V_6 ] -> V_38 ) ;
F_183 ( V_341 [ V_6 ] ) ;
}
return;
}
}
for ( V_6 = 0 ; V_6 < V_340 ; ++ V_6 ) {
memcpy ( V_341 [ V_6 ] -> V_341 , V_341 , sizeof( V_341 ) ) ;
F_243 ( V_341 [ V_6 ] ) ;
V_341 [ V_6 ] -> V_340 = V_340 ;
F_247 ( & V_341 [ V_6 ] -> V_48 ) ;
}
if ( ! F_236 ( V_341 [ 0 ] ) ) {
F_233 ( V_341 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_340 ; ++ V_6 ) {
V_341 [ V_6 ] -> V_145 = V_341 [ 0 ] -> V_145 ;
V_341 [ V_6 ] -> V_450 = V_341 [ 0 ] -> V_450 ;
F_233 ( V_341 [ V_6 ] ) ;
}
if ( F_252 ( V_341 [ 0 ] -> V_145 ,
F_177 ,
V_341 [ 0 ] -> V_475 ,
V_341 [ 0 ] -> V_8 ,
V_341 [ 0 ] ) < 0 ) {
F_12 ( ( L_154 ,
V_341 [ 0 ] -> V_8 ,
V_341 [ 0 ] -> V_145 ) ) ;
} else {
V_341 [ 0 ] -> V_452 = true ;
F_253 ( V_341 [ 0 ] ) ;
for ( V_6 = 1 ; V_6 < V_340 ; V_6 ++ ) {
V_341 [ V_6 ] -> V_36 = V_341 [ 0 ] -> V_36 ;
V_341 [ V_6 ] -> V_345 = V_341 [ 0 ] -> V_345 ;
}
}
}
for ( V_6 = 0 ; V_6 < V_340 ; ++ V_6 ) {
struct V_1 * V_2 = V_341 [ V_6 ] ;
F_254 ( & V_2 -> V_38 , V_478 , V_2 -> line ,
& V_2 -> V_441 -> V_169 ) ;
}
}
static int F_255 ( struct V_465 * V_169 ,
const struct V_479 * V_480 )
{
if ( F_256 ( V_169 ) ) {
F_2 ( L_155 , V_169 ) ;
return - V_66 ;
}
F_257 ( V_169 ) ;
F_250 ( V_31 , V_169 ) ;
return 0 ;
}
static void F_258 ( struct V_465 * V_169 )
{
}
static void F_259 ( void )
{
int V_138 ;
struct V_1 * V_2 ;
struct V_1 * V_481 ;
F_2 ( V_482 L_156 , V_32 ) ;
if ( V_478 ) {
for ( V_2 = V_34 ; V_2 != NULL ; V_2 = V_2 -> V_35 )
F_260 ( V_478 , V_2 -> line ) ;
V_138 = F_261 ( V_478 ) ;
if ( V_138 )
F_12 ( ( L_157 , V_138 ) ) ;
F_262 ( V_478 ) ;
}
V_2 = V_34 ;
while( V_2 ) {
F_263 ( V_2 ) ;
V_2 = V_2 -> V_35 ;
}
V_2 = V_34 ;
while( V_2 ) {
#if V_292
F_136 ( V_2 ) ;
#endif
F_235 ( V_2 ) ;
F_224 ( V_2 ) ;
if ( V_2 -> V_464 == 0 )
F_239 ( V_2 ) ;
V_481 = V_2 ;
V_2 = V_2 -> V_35 ;
F_251 ( & V_481 -> V_38 ) ;
F_183 ( V_481 ) ;
}
if ( V_483 )
F_264 ( & V_484 ) ;
}
static int T_10 F_265 ( void )
{
int V_138 ;
F_2 ( V_482 L_158 , V_32 ) ;
V_478 = F_266 ( V_455 ) ;
if ( ! V_478 ) {
F_2 ( L_159 , V_32 ) ;
return - V_234 ;
}
V_478 -> V_32 = V_485 ;
V_478 -> V_17 = V_454 ;
V_478 -> V_486 = V_487 ;
V_478 -> V_488 = 64 ;
V_478 -> type = V_489 ;
V_478 -> V_490 = V_491 ;
V_478 -> V_492 = V_493 ;
V_478 -> V_492 . V_52 =
V_494 | V_362 | V_355 | V_354 | V_369 ;
V_478 -> V_492 . V_495 = 9600 ;
V_478 -> V_492 . V_496 = 9600 ;
V_478 -> V_22 = V_497 | V_498 ;
F_267 ( V_478 , & V_25 ) ;
if ( ( V_138 = F_268 ( V_478 ) ) < 0 ) {
F_12 ( ( L_160 , V_32 ) ) ;
F_262 ( V_478 ) ;
V_478 = NULL ;
goto error;
}
F_2 ( V_482 L_161 ,
V_32 , V_478 -> V_486 ) ;
V_31 = 0 ;
if ( ( V_138 = F_269 ( & V_484 ) ) < 0 ) {
F_2 ( L_162 , V_32 , V_138 ) ;
goto error;
}
V_483 = true ;
if ( ! V_34 )
F_2 ( L_163 , V_32 ) ;
return 0 ;
error:
F_259 () ;
return V_138 ;
}
static void T_11 F_270 ( void )
{
F_259 () ;
}
static T_1 F_271 ( struct V_1 * V_2 , unsigned int V_499 )
{
F_272 () ;
return F_273 ( ( void V_500 * ) V_450 ) ;
}
static void F_274 ( struct V_1 * V_2 , unsigned int V_499 , T_1 V_164 )
{
F_272 () ;
F_275 ( V_164 , ( void V_500 * ) V_450 ) ;
}
static T_12 F_102 ( struct V_1 * V_2 , unsigned int V_499 )
{
F_272 () ;
return F_276 ( ( void V_500 * ) V_450 ) ;
}
static void F_103 ( struct V_1 * V_2 , unsigned int V_499 , T_12 V_164 )
{
F_272 () ;
F_277 ( V_164 , ( void V_500 * ) V_450 ) ;
}
static T_8 F_170 ( struct V_1 * V_2 , unsigned int V_499 )
{
F_272 () ;
return F_278 ( ( void V_500 * ) V_450 ) ;
}
static void F_171 ( struct V_1 * V_2 , unsigned int V_499 , T_8 V_164 )
{
F_272 () ;
F_279 ( V_164 , ( void V_500 * ) V_450 ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_171 ( V_2 , V_320 , V_255 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_170 ( V_2 , V_320 ) & V_256 ) )
break;
}
static void F_174 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
F_171 ( V_2 , V_323 , V_255 ) ;
for( V_6 = 0 ; V_6 < 1000 ; V_6 ++ )
if ( ! ( F_170 ( V_2 , V_323 ) & V_256 ) )
break;
}
static void F_281 ( struct V_1 * V_2 )
{
F_103 ( V_2 , V_398 , ( unsigned short ) ( F_102 ( V_2 , V_398 ) | V_285 ) ) ;
if ( V_2 -> V_59 . V_60 != V_80 ) {
F_274 ( V_2 , V_501 , 0x49 ) ;
if ( V_2 -> V_59 . V_127 )
F_282 ( V_2 , V_2 -> V_59 . V_127 ) ;
else
F_282 ( V_2 , 3686400 ) ;
}
}
static void F_282 ( struct V_1 * V_2 , T_9 V_502 )
{
unsigned int div ;
unsigned int V_503 = V_2 -> V_137 ;
if ( V_502 ) {
div = V_503 / V_502 ;
if ( ! ( V_503 % V_502 ) && div )
div -- ;
F_103 ( V_2 , V_504 , ( unsigned short ) div ) ;
}
}
static void F_163 ( struct V_1 * V_2 )
{
unsigned short V_326 ;
V_326 = F_102 ( V_2 , V_378 ) & ~ V_255 ;
F_103 ( V_2 , V_378 , ( unsigned short ) ( V_326 | V_285 ) ) ;
F_103 ( V_2 , V_378 , V_326 ) ;
F_155 ( V_2 , V_319 + V_300 + V_315 ) ;
F_103 ( V_2 , V_299 , V_315 + V_319 ) ;
F_280 ( V_2 ) ;
V_2 -> V_377 = false ;
V_2 -> V_272 = false ;
}
static void F_152 ( struct V_1 * V_2 )
{
unsigned short V_326 ;
F_155 ( V_2 , V_319 + V_300 ) ;
F_103 ( V_2 , V_299 , V_319 ) ;
V_326 = F_102 ( V_2 , V_378 ) & ~ V_255 ;
F_103 ( V_2 , V_378 , ( unsigned short ) ( V_326 | V_285 ) ) ;
F_103 ( V_2 , V_378 , V_326 ) ;
F_280 ( V_2 ) ;
F_234 ( V_2 ) ;
if ( V_2 -> V_307 ) {
F_103 ( V_2 , V_398 , ( unsigned short ) ( F_102 ( V_2 , V_398 ) & ~ V_505 ) ) ;
F_188 ( V_2 , V_300 ) ;
if ( V_2 -> V_59 . V_60 == V_80 ) {
F_171 ( V_2 , V_320 , V_167 ) ;
}
} else {
F_103 ( V_2 , V_398 , ( unsigned short ) ( F_102 ( V_2 , V_398 ) | V_505 ) ) ;
F_171 ( V_2 , V_506 , V_2 -> V_15 [ 0 ] . V_444 ) ;
if ( V_2 -> V_59 . V_60 != V_80 ) {
F_171 ( V_2 , V_320 , ( V_285 + V_256 ) ) ;
} else {
F_171 ( V_2 , V_320 , ( V_167 + V_285 + V_256 ) ) ;
}
}
F_188 ( V_2 , V_319 ) ;
F_103 ( V_2 , V_378 , ( unsigned short ) ( F_102 ( V_2 , V_378 ) | V_255 ) ) ;
V_2 -> V_272 = false ;
V_2 -> V_377 = true ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_73 ) {
F_103 ( V_2 , V_166 ,
( unsigned short ) ( ( F_102 ( V_2 , V_166 ) | V_255 ) & ~ V_285 ) ) ;
V_2 -> V_73 = true ;
}
if ( F_140 ( V_2 -> V_11 [ V_2 -> V_324 ] ) ) {
V_2 -> V_327 = false ;
if ( V_2 -> V_59 . V_60 != V_80 ) {
if ( V_2 -> V_59 . V_22 & V_507 ) {
F_90 ( V_2 ) ;
if ( ! ( V_2 -> V_54 & V_55 ) ) {
V_2 -> V_54 |= V_55 ;
F_34 ( V_2 ) ;
V_2 -> V_327 = true ;
}
}
F_155 ( V_2 , V_325 ) ;
F_188 ( V_2 , V_314 + V_306 ) ;
F_103 ( V_2 , V_299 , ( unsigned short ) ( V_306 + V_314 ) ) ;
} else {
F_155 ( V_2 , V_325 ) ;
F_188 ( V_2 , V_306 ) ;
F_103 ( V_2 , V_299 , V_306 ) ;
}
F_171 ( V_2 , V_508 , V_2 -> V_11 [ V_2 -> V_324 ] . V_444 ) ;
F_171 ( V_2 , V_323 , V_285 + V_256 ) ;
V_2 -> V_77 = true ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
unsigned short V_326 ;
F_175 ( & V_2 -> V_62 ) ;
F_174 ( V_2 ) ;
V_326 = F_102 ( V_2 , V_166 ) & ~ V_255 ;
F_103 ( V_2 , V_166 , ( unsigned short ) ( V_326 | V_285 ) ) ;
F_155 ( V_2 , V_325 + V_306 + V_314 ) ;
F_103 ( V_2 , V_299 , ( unsigned short ) ( V_306 + V_314 ) ) ;
F_283 ( V_2 ) ;
V_2 -> V_73 = false ;
V_2 -> V_77 = false ;
}
static void F_263 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_450 )
return;
F_56 ( V_2 ) ;
F_163 ( V_2 ) ;
V_2 -> V_54 &= ~ ( V_55 | V_56 ) ;
F_34 ( V_2 ) ;
F_155 ( V_2 , V_351 | V_352 ) ;
}
static void F_284 ( struct V_1 * V_2 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_340 ; ++ V_6 ) {
if ( V_2 -> V_341 [ V_6 ] )
F_263 ( V_2 -> V_341 [ V_6 ] ) ;
}
}
static void F_187 ( struct V_1 * V_2 )
{
unsigned short V_326 ;
F_155 ( V_2 , V_351 | V_352 ) ;
F_56 ( V_2 ) ;
F_163 ( V_2 ) ;
V_326 = 0x4000 ;
if ( V_2 -> V_402 & V_403 )
V_326 |= V_404 ;
if ( V_2 -> V_59 . V_118 != V_368 ) {
V_326 |= V_509 ;
if ( V_2 -> V_59 . V_118 == V_366 )
V_326 |= V_342 ;
}
switch ( V_2 -> V_59 . V_132 )
{
case 6 : V_326 |= V_322 ; break;
case 7 : V_326 |= V_321 ; break;
case 8 : V_326 |= V_321 + V_322 ; break;
}
if ( V_2 -> V_59 . V_133 != 1 )
V_326 |= V_277 ;
if ( V_2 -> V_59 . V_22 & V_510 )
V_326 |= V_256 ;
F_103 ( V_2 , V_166 , V_326 ) ;
V_326 = 0x4000 ;
if ( V_2 -> V_59 . V_118 != V_368 ) {
V_326 |= V_509 ;
if ( V_2 -> V_59 . V_118 == V_366 )
V_326 |= V_342 ;
}
switch ( V_2 -> V_59 . V_132 )
{
case 6 : V_326 |= V_322 ; break;
case 7 : V_326 |= V_321 ; break;
case 8 : V_326 |= V_321 + V_322 ; break;
}
if ( V_2 -> V_59 . V_22 & V_511 )
V_326 |= V_256 ;
F_103 ( V_2 , V_378 , V_326 ) ;
F_274 ( V_2 , V_501 , 0x69 ) ;
F_206 ( V_2 ) ;
V_326 = V_304 + V_505 + V_256 ;
if ( ( F_170 ( V_2 , V_512 ) & V_342 ) && V_2 -> V_59 . V_76 &&
( ( V_2 -> V_137 < ( V_2 -> V_59 . V_76 * 16 ) ) ||
( V_2 -> V_137 % ( V_2 -> V_59 . V_76 * 16 ) ) ) ) {
V_326 |= V_277 ;
F_282 ( V_2 , V_2 -> V_59 . V_76 * 8 ) ;
} else {
F_282 ( V_2 , V_2 -> V_59 . V_76 * 16 ) ;
}
F_103 ( V_2 , V_398 , V_326 ) ;
F_188 ( V_2 , V_308 | V_319 ) ;
if ( V_2 -> V_59 . V_125 )
F_281 ( V_2 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
unsigned short V_326 ;
F_155 ( V_2 , V_351 | V_352 ) ;
F_56 ( V_2 ) ;
F_163 ( V_2 ) ;
V_326 = V_285 ;
switch( V_2 -> V_59 . V_60 ) {
case V_271 :
V_326 |= V_304 + V_513 ;
break;
case V_269 : V_326 |= V_505 + V_513 ; break;
case V_270 : V_326 |= V_304 ; break;
case V_268 : V_326 |= V_513 ; break;
}
if ( V_2 -> V_402 & V_403 )
V_326 |= V_404 ;
switch( V_2 -> V_59 . V_126 )
{
case V_514 : V_326 |= V_303 ; break;
case V_515 : V_326 |= V_516 ; break;
case V_517 : V_326 |= V_516 + V_303 ; break;
case V_177 : V_326 |= V_518 ; break;
case V_179 : V_326 |= V_518 + V_303 ; break;
case V_181 : V_326 |= V_518 + V_516 ; break;
case V_519 : V_326 |= V_518 + V_516 + V_303 ; break;
}
switch ( V_2 -> V_59 . V_129 & V_520 )
{
case V_185 : V_326 |= V_509 ; break;
case V_187 : V_326 |= V_509 + V_342 ; break;
}
if ( V_2 -> V_59 . V_131 != V_521 )
V_326 |= V_167 ;
switch ( V_2 -> V_59 . V_130 )
{
case V_522 : V_326 |= V_321 ; break;
case V_523 : V_326 |= V_322 ; break;
case V_524 : V_326 |= V_321 + V_322 ; break;
}
if ( V_2 -> V_59 . V_22 & V_510 )
V_326 |= V_256 ;
F_103 ( V_2 , V_166 , V_326 ) ;
switch ( V_2 -> V_59 . V_131 )
{
case V_525 : V_326 = 0x7e ; break;
case V_526 : V_326 = 0xff ; break;
case V_527 : V_326 = 0x00 ; break;
case V_528 : V_326 = 0x55 ; break;
case V_529 : V_326 = 0xaa ; break;
default: V_326 = 0x7e ; break;
}
F_274 ( V_2 , V_530 , ( unsigned char ) V_326 ) ;
V_326 = 0 ;
switch( V_2 -> V_59 . V_60 ) {
case V_271 :
V_326 |= V_304 + V_513 ;
break;
case V_269 : V_326 |= V_505 + V_513 ; break;
case V_270 : V_326 |= V_304 ; break;
case V_268 : V_326 |= V_513 ; break;
}
switch( V_2 -> V_59 . V_126 )
{
case V_514 : V_326 |= V_303 ; break;
case V_515 : V_326 |= V_516 ; break;
case V_517 : V_326 |= V_516 + V_303 ; break;
case V_177 : V_326 |= V_518 ; break;
case V_179 : V_326 |= V_518 + V_303 ; break;
case V_181 : V_326 |= V_518 + V_516 ; break;
case V_519 : V_326 |= V_518 + V_516 + V_303 ; break;
}
switch ( V_2 -> V_59 . V_129 & V_520 )
{
case V_185 : V_326 |= V_509 ; break;
case V_187 : V_326 |= V_509 + V_342 ; break;
}
if ( V_2 -> V_59 . V_22 & V_511 )
V_326 |= V_256 ;
F_103 ( V_2 , V_378 , V_326 ) ;
V_326 = 0 ;
if ( V_2 -> V_59 . V_22 & V_214 )
{
if ( V_2 -> V_59 . V_22 & V_209 )
V_326 |= V_167 + V_321 ;
else
V_326 |= V_167 ;
}
else if ( V_2 -> V_59 . V_22 & V_213 )
V_326 |= V_404 ;
else if ( V_2 -> V_59 . V_22 & V_215 )
V_326 |= V_321 ;
if ( V_2 -> V_59 . V_22 & V_210 )
V_326 |= V_277 ;
else if ( V_2 -> V_59 . V_22 & V_209 )
V_326 |= V_322 ;
else if ( V_2 -> V_59 . V_22 & V_211 )
V_326 |= V_285 ;
if ( V_2 -> V_59 . V_127 )
V_326 |= V_255 + V_256 ;
F_274 ( V_2 , V_501 , ( unsigned char ) V_326 ) ;
if ( V_2 -> V_59 . V_22 & ( V_213 + V_209 ) )
{
switch( V_2 -> V_59 . V_126 )
{
case V_177 :
case V_179 :
V_326 = V_404 ; break;
case V_181 :
case V_519 :
V_326 = V_404 + V_167 ; break;
default: V_326 = V_167 ;
}
F_103 ( V_2 , V_378 , ( unsigned short ) ( F_102 ( V_2 , V_378 ) | V_326 ) ) ;
F_282 ( V_2 , V_2 -> V_59 . V_127 * 16 ) ;
}
else
F_282 ( V_2 , V_2 -> V_59 . V_127 ) ;
F_198 ( V_2 ) ;
F_206 ( V_2 ) ;
F_103 ( V_2 , V_398 , V_304 + V_505 + V_256 ) ;
if ( V_2 -> V_59 . V_125 )
F_281 ( V_2 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
unsigned char V_326 ;
unsigned short V_531 ;
V_531 = F_102 ( V_2 , V_166 ) ;
if ( V_2 -> V_374 & V_532 ) {
V_531 = ( V_531 & ~ ( V_167 + V_321 ) ) | V_322 ;
F_274 ( V_2 , V_530 , ( unsigned char ) ( ( V_2 -> V_374 >> 8 ) & 0xff ) ) ;
} else if ( ! ( V_531 & V_167 ) ) {
V_531 &= ~ ( V_321 + V_322 ) ;
}
F_103 ( V_2 , V_166 , V_531 ) ;
if ( V_2 -> V_374 & ( V_533 | V_532 ) ) {
V_326 = ( unsigned char ) ( V_2 -> V_374 & 0xff ) ;
} else {
switch( V_2 -> V_374 )
{
case V_470 : V_326 = 0x7e ; break;
case V_534 :
case V_535 : V_326 = 0xaa ; break;
case V_536 :
case V_537 : V_326 = 0x00 ; break;
default: V_326 = 0xff ;
}
}
F_274 ( V_2 , V_538 , V_326 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
unsigned short V_12 = F_102 ( V_2 , V_299 ) ;
V_2 -> V_54 &= V_55 | V_56 ;
if ( V_12 & V_277 )
V_2 -> V_54 |= V_147 ;
if ( V_12 & V_285 )
V_2 -> V_54 |= V_146 ;
if ( V_12 & V_255 )
V_2 -> V_54 |= V_148 ;
if ( V_12 & V_256 )
V_2 -> V_54 |= V_149 ;
}
static void F_206 ( struct V_1 * V_2 )
{
unsigned char V_326 = 0 ;
switch( V_2 -> V_402 & V_539 )
{
case V_540 :
V_326 |= V_321 ;
break;
case V_541 :
V_326 |= V_404 + V_167 + V_321 ;
break;
case V_542 :
V_326 |= V_167 ;
break;
}
if ( V_2 -> V_402 & V_543 )
V_326 |= V_322 ;
if ( V_2 -> V_54 & V_56 )
V_326 |= V_277 ;
if ( V_2 -> V_54 & V_55 )
V_326 |= V_285 ;
if ( V_2 -> V_402 & V_544 )
V_326 |= V_255 ;
if ( V_2 -> V_402 & V_545 )
V_326 |= V_256 ;
F_274 ( V_2 , V_546 , V_326 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned char V_326 = F_271 ( V_2 , V_546 ) ;
if ( V_2 -> V_54 & V_56 )
V_326 |= V_277 ;
else
V_326 &= ~ V_277 ;
if ( V_2 -> V_54 & V_55 )
V_326 |= V_285 ;
else
V_326 &= ~ V_285 ;
F_274 ( V_2 , V_546 , V_326 ) ;
}
static void F_144 ( struct V_1 * V_2 , unsigned int V_6 , unsigned int V_547 )
{
int V_548 = 0 ;
while( ! V_548 ) {
V_2 -> V_15 [ V_6 ] . V_12 = 0 ;
F_164 ( V_2 -> V_15 [ V_6 ] , V_2 -> V_302 ) ;
if ( V_6 == V_547 )
V_548 = 1 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
}
V_2 -> V_13 = V_6 ;
}
static void F_234 ( struct V_1 * V_2 )
{
F_144 ( V_2 , 0 , V_2 -> V_14 - 1 ) ;
V_2 -> V_297 = 0 ;
V_2 -> V_296 = 0 ;
}
static bool F_150 ( struct V_1 * V_2 )
{
unsigned int V_247 , V_248 ;
unsigned short V_12 ;
unsigned int V_549 = 0 ;
unsigned long V_22 ;
struct V_20 * V_21 = V_2 -> V_38 . V_21 ;
unsigned char V_550 = 0xff ;
unsigned int V_551 = 0 ;
switch ( V_2 -> V_59 . V_129 & V_520 ) {
case V_185 : V_551 = 2 ; break;
case V_187 : V_551 = 4 ; break;
}
V_552:
V_549 = 0 ;
V_550 = 0xff ;
V_247 = V_248 = V_2 -> V_13 ;
for (; ; ) {
if ( ! F_139 ( V_2 -> V_15 [ V_248 ] ) )
goto V_45;
if ( V_549 == 0 && V_2 -> V_59 . V_128 != 0xff )
V_550 = V_2 -> V_15 [ V_248 ] . V_64 [ 0 ] ;
V_549 += F_140 ( V_2 -> V_15 [ V_248 ] ) ;
if ( F_285 ( V_2 -> V_15 [ V_248 ] ) )
break;
if ( ++ V_248 == V_2 -> V_14 )
V_248 = 0 ;
if ( V_248 == V_2 -> V_13 ) {
if ( V_2 -> V_377 ) {
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_152 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
}
goto V_45;
}
}
V_12 = F_286 ( V_2 -> V_15 [ V_248 ] ) ;
if ( ( V_2 -> V_59 . V_129 & V_520 ) == V_183 )
V_12 &= ~ V_255 ;
if ( V_549 == 0 ||
( V_550 != 0xff && V_550 != V_2 -> V_59 . V_128 ) ) {
F_144 ( V_2 , V_247 , V_248 ) ;
goto V_552;
}
if ( V_549 < ( 2 + V_551 ) || V_12 & V_256 ) {
V_2 -> V_107 . V_154 ++ ;
V_549 = 0 ;
} else if ( V_12 & V_255 ) {
V_2 -> V_107 . V_157 ++ ;
if ( ! ( V_2 -> V_59 . V_129 & V_553 ) )
V_549 = 0 ;
}
#if V_292
if ( V_549 == 0 ) {
V_2 -> V_227 -> V_192 . V_554 ++ ;
V_2 -> V_227 -> V_192 . V_555 ++ ;
}
#endif
F_149 ( ( L_164 ,
V_2 -> V_8 , V_12 , V_549 ) ) ;
F_142 ( V_2 , V_2 -> V_15 [ V_247 ] . V_64 , F_47 ( int , V_549 , V_2 -> V_302 ) , L_94 ) ;
if ( V_549 ) {
if ( ! ( V_2 -> V_59 . V_129 & V_553 ) ) {
V_549 -= V_551 ;
V_551 = 0 ;
}
if ( V_549 > V_2 -> V_68 + V_551 )
V_2 -> V_107 . V_155 ++ ;
else {
int V_556 = V_549 ;
int V_6 = V_247 ;
unsigned char * V_249 = V_2 -> V_438 ;
V_2 -> V_557 = V_549 ;
V_2 -> V_107 . V_151 ++ ;
while( V_556 ) {
int V_558 = F_47 ( int , V_556 , V_2 -> V_302 ) ;
memcpy ( V_249 , V_2 -> V_15 [ V_6 ] . V_64 , V_558 ) ;
V_249 += V_558 ;
V_556 -= V_558 ;
if ( ++ V_6 == V_2 -> V_14 )
V_6 = 0 ;
}
if ( V_2 -> V_59 . V_129 & V_553 ) {
* V_249 = ( V_12 & V_255 ) ? V_559 : V_560 ;
V_549 ++ ;
}
#if V_292
if ( V_2 -> V_43 )
F_126 ( V_2 , V_2 -> V_438 , V_549 ) ;
else
#endif
F_8 ( V_21 , V_2 -> V_438 , V_2 -> V_439 , V_549 ) ;
}
}
F_144 ( V_2 , V_247 , V_248 ) ;
return true ;
V_45:
return false ;
}
static bool F_151 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_2 -> V_13 ;
unsigned int V_4 ;
if ( ! F_139 ( V_2 -> V_15 [ V_6 ] ) )
return false ;
V_4 = F_140 ( V_2 -> V_15 [ V_6 ] ) ;
switch( V_2 -> V_59 . V_60 ) {
case V_269 :
case V_270 :
case V_271 :
if ( F_287 ( V_2 -> V_15 [ V_6 ] ) )
V_4 -- ;
break;
}
F_142 ( V_2 , V_2 -> V_15 [ V_6 ] . V_64 , V_4 , L_94 ) ;
F_13 ( ( L_165 , V_4 ) ) ;
if ( V_4 )
F_8 ( V_2 -> V_38 . V_21 , V_2 -> V_15 [ V_6 ] . V_64 ,
V_2 -> V_439 , V_4 ) ;
F_144 ( V_2 , V_6 , V_6 ) ;
return true ;
}
static void F_283 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
V_2 -> V_9 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] . V_12 = 0 ;
V_2 -> V_11 [ V_6 ] . V_4 = 0 ;
}
}
static unsigned int F_288 ( struct V_1 * V_2 )
{
unsigned int V_4 = 0 ;
unsigned int V_6 = V_2 -> V_9 ;
do
{
if ( F_140 ( V_2 -> V_11 [ V_6 ] ) )
break;
++ V_4 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
} while ( V_6 != V_2 -> V_9 );
if ( V_4 && ( F_170 ( V_2 , V_323 ) & V_256 ) )
-- V_4 ;
return V_4 ;
}
static unsigned int F_39 ( struct V_1 * V_2 )
{
unsigned int V_561 = 0 ;
unsigned int V_6 = V_2 -> V_9 ;
unsigned int V_562 ;
unsigned int V_4 ;
unsigned int V_563 = 0 ;
do {
V_4 = F_140 ( V_2 -> V_11 [ V_6 ] ) ;
if ( V_4 )
V_561 += V_4 ;
else if ( ! V_561 )
V_563 = V_2 -> V_11 [ V_6 ] . V_564 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
} while ( V_6 != V_2 -> V_9 );
V_562 = F_170 ( V_2 , V_323 ) ;
if ( V_562 & V_256 )
V_561 += V_563 ;
V_561 += ( V_562 >> 8 ) & 0xff ;
if ( V_2 -> V_77 )
V_561 ++ ;
return V_561 ;
}
static bool F_43 ( struct V_1 * V_2 , const char * V_64 , unsigned int V_198 )
{
unsigned short V_4 ;
unsigned int V_6 ;
struct V_250 * V_565 ;
if ( F_289 ( V_198 , V_376 ) > F_288 ( V_2 ) )
return false ;
F_142 ( V_2 , V_64 , V_198 , L_166 ) ;
V_2 -> V_324 = V_6 = V_2 -> V_9 ;
while ( V_198 ) {
V_565 = & V_2 -> V_11 [ V_6 ] ;
V_4 = ( unsigned short ) ( ( V_198 > V_376 ) ? V_376 : V_198 ) ;
memcpy ( V_565 -> V_64 , V_64 , V_4 ) ;
V_198 -= V_4 ;
V_64 += V_4 ;
if ( ( ! V_198 && V_2 -> V_59 . V_60 == V_61 ) ||
V_2 -> V_59 . V_60 == V_268 )
F_290 ( * V_565 , 1 ) ;
else
F_290 ( * V_565 , 0 ) ;
if ( V_6 != V_2 -> V_324 )
F_164 ( * V_565 , V_4 ) ;
V_565 -> V_564 = V_4 ;
if ( ++ V_6 == V_2 -> V_10 )
V_6 = 0 ;
}
V_2 -> V_9 = V_6 ;
V_565 = & V_2 -> V_11 [ V_2 -> V_324 ] ;
F_164 ( * V_565 , V_565 -> V_564 ) ;
if ( ! V_2 -> V_77 )
F_46 ( V_2 ) ;
F_38 ( V_2 ) ;
return true ;
}
static int F_291 ( struct V_1 * V_2 )
{
static unsigned short V_566 [] =
{ 0x0000 , 0xffff , 0xaaaa , 0x5555 , 0x6969 , 0x9696 } ;
static unsigned int V_4 = F_292 ( V_566 ) ;
unsigned int V_6 ;
int V_138 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
F_103 ( V_2 , V_538 , V_566 [ V_6 ] ) ;
F_103 ( V_2 , V_504 , V_566 [ ( V_6 + 1 ) % V_4 ] ) ;
if ( ( F_102 ( V_2 , V_538 ) != V_566 [ V_6 ] ) ||
( F_102 ( V_2 , V_504 ) != V_566 [ ( V_6 + 1 ) % V_4 ] ) ) {
V_138 = - V_33 ;
break;
}
}
V_2 -> V_345 = ( F_170 ( V_2 , V_512 ) & V_321 ) ? 1 : 0 ;
V_2 -> V_36 = V_138 ? 0 : V_567 ;
return V_138 ;
}
static int F_293 ( struct V_1 * V_2 )
{
unsigned long V_46 ;
unsigned long V_22 ;
struct V_20 * V_568 = V_2 -> V_38 . V_21 ;
T_9 V_569 = V_2 -> V_59 . V_76 ;
V_2 -> V_59 . V_76 = 921600 ;
V_2 -> V_38 . V_21 = NULL ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_187 ( V_2 ) ;
F_188 ( V_2 , V_306 ) ;
F_103 ( V_2 , V_166 ,
( unsigned short ) ( F_102 ( V_2 , V_166 ) | V_255 ) ) ;
F_103 ( V_2 , V_570 , 0 ) ;
V_2 -> V_36 = V_571 ;
V_2 -> V_305 = false ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
V_46 = 100 ;
while( V_46 -- && ! V_2 -> V_305 )
F_48 ( 10 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_263 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_59 . V_76 = V_569 ;
V_2 -> V_38 . V_21 = V_568 ;
V_2 -> V_36 = V_2 -> V_305 ? 0 : V_571 ;
return V_2 -> V_305 ? 0 : - V_33 ;
}
static int F_294 ( struct V_1 * V_2 )
{
unsigned char * V_572 , * V_573 ;
int V_4 ;
if ( F_139 ( V_2 -> V_15 [ 0 ] ) ) {
V_4 = F_140 ( V_2 -> V_15 [ 0 ] ) ;
V_572 = V_2 -> V_15 [ 0 ] . V_64 ;
V_573 = V_2 -> V_438 ;
for( ; V_4 ; V_4 -= 2 , V_572 += 2 ) {
if ( ! ( * ( V_572 + 1 ) & ( V_509 + V_342 ) ) ) {
* V_573 = * V_572 ;
V_573 ++ ;
V_2 -> V_557 ++ ;
}
}
F_142 ( V_2 , V_2 -> V_438 , V_2 -> V_557 , L_94 ) ;
return 1 ;
}
return 0 ;
}
static int F_295 ( struct V_1 * V_2 )
{
#define F_296 20
unsigned long V_46 ;
T_13 V_4 = F_296 ;
unsigned char V_64 [ F_296 ] ;
int V_138 = - V_33 ;
unsigned long V_22 ;
struct V_20 * V_568 = V_2 -> V_38 . V_21 ;
T_7 V_59 ;
memcpy ( & V_59 , & V_2 -> V_59 , sizeof( V_59 ) ) ;
V_2 -> V_59 . V_60 = V_80 ;
V_2 -> V_59 . V_76 = 921600 ;
V_2 -> V_59 . V_125 = 1 ;
V_2 -> V_38 . V_21 = NULL ;
for ( V_4 = 0 ; V_4 < F_296 ; ++ V_4 )
V_64 [ V_4 ] = ( unsigned char ) V_4 ;
V_2 -> V_557 = 0 ;
memset ( V_2 -> V_438 , 0 , F_296 ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_187 ( V_2 ) ;
F_152 ( V_2 ) ;
F_43 ( V_2 , V_64 , V_4 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
for ( V_46 = 100 ; V_46 ; -- V_46 ) {
F_48 ( 10 ) ;
if ( F_294 ( V_2 ) ) {
V_138 = 0 ;
break;
}
}
if ( ! V_138 && ( V_2 -> V_557 != V_4 ||
memcmp ( V_64 , V_2 -> V_438 , V_4 ) ) ) {
V_138 = - V_33 ;
}
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_284 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
memcpy ( & V_2 -> V_59 , & V_59 , sizeof( V_2 -> V_59 ) ) ;
V_2 -> V_38 . V_21 = V_568 ;
V_2 -> V_36 = V_138 ? V_574 : 0 ;
return V_138 ;
}
static int F_253 ( struct V_1 * V_2 )
{
F_13 ( ( L_167 , V_2 -> V_8 ) ) ;
if ( F_291 ( V_2 ) < 0 ) {
F_2 ( L_168 ,
V_2 -> V_8 , V_2 -> V_144 ) ;
} else if ( F_293 ( V_2 ) < 0 ) {
F_2 ( L_169 ,
V_2 -> V_8 , V_2 -> V_145 ) ;
} else if ( F_295 ( V_2 ) < 0 ) {
F_2 ( L_170 , V_2 -> V_8 ) ;
}
return V_2 -> V_36 ;
}
static void V_471 ( unsigned long V_575 )
{
struct V_1 * V_2 = (struct V_1 * ) V_575 ;
unsigned long V_22 ;
F_13 ( ( L_171 , V_2 -> V_8 ) ) ;
if( V_2 -> V_77 && V_2 -> V_59 . V_60 == V_61 ) {
V_2 -> V_107 . V_576 ++ ;
}
F_15 ( & V_2 -> V_48 , V_22 ) ;
F_56 ( V_2 ) ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
#if V_292
if ( V_2 -> V_43 )
F_124 ( V_2 ) ;
else
#endif
F_153 ( V_2 ) ;
}
static void V_472 ( unsigned long V_575 )
{
struct V_1 * V_2 = (struct V_1 * ) V_575 ;
unsigned long V_22 ;
F_13 ( ( L_172 , V_2 -> V_8 ) ) ;
F_15 ( & V_2 -> V_48 , V_22 ) ;
V_2 -> V_160 |= V_261 ;
F_16 ( & V_2 -> V_48 , V_22 ) ;
F_147 ( & V_2 -> V_266 ) ;
}
