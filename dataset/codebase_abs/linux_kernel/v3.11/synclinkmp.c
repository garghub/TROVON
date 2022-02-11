static void * F_1 ( void ) { return F_1 ; }
static inline int F_2 ( T_1 * V_1 ,
char * V_2 , const char * V_3 )
{
#ifdef F_3
static const char * V_4 =
L_1 ;
static const char * V_5 =
L_2 ;
if ( ! V_1 ) {
F_4 ( V_5 , V_2 , V_3 ) ;
return 1 ;
}
if ( V_1 -> V_6 != V_7 ) {
F_4 ( V_4 , V_2 , V_3 ) ;
return 1 ;
}
#else
if ( ! V_1 )
return 1 ;
#endif
return 0 ;
}
static void F_5 ( struct V_8 * V_9 ,
const T_2 * V_10 , char * V_11 , int V_12 )
{
struct V_13 * V_14 ;
if ( ! V_9 )
return;
V_14 = F_6 ( V_9 ) ;
if ( V_14 ) {
if ( V_14 -> V_15 -> V_16 )
V_14 -> V_15 -> V_16 ( V_9 , V_10 , V_11 , V_12 ) ;
F_7 ( V_14 ) ;
}
}
static int F_8 ( struct V_17 * V_18 , struct V_8 * V_9 )
{
T_1 * V_1 ;
int line = V_9 -> V_19 ;
if ( line >= V_20 ) {
F_4 ( L_3 ,
__FILE__ , __LINE__ , line ) ;
return - V_21 ;
}
V_1 = V_22 ;
while ( V_1 && V_1 -> line != line )
V_1 = V_1 -> V_23 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_4 ) )
return - V_21 ;
if ( V_1 -> V_24 ) {
F_4 ( L_5 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_1 -> V_24 ) ;
return - V_21 ;
}
V_9 -> V_26 = V_1 ;
return F_9 ( & V_1 -> V_27 , V_18 , V_9 ) ;
}
static int F_10 ( struct V_8 * V_9 , struct V_28 * V_29 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
int V_30 ;
V_1 -> V_27 . V_9 = V_9 ;
if ( V_31 >= V_32 )
F_4 ( L_6 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_1 -> V_27 . V_12 ) ;
if ( F_11 ( V_29 ) || V_1 -> V_27 . V_11 & V_33 ) {
if ( V_1 -> V_27 . V_11 & V_33 )
F_12 ( & V_1 -> V_27 . V_34 ) ;
V_30 = ( ( V_1 -> V_27 . V_11 & V_35 ) ?
- V_36 : - V_37 ) ;
goto V_38;
}
V_1 -> V_27 . V_39 = ( V_1 -> V_27 . V_11 & V_40 ) ? 1 : 0 ;
F_13 ( & V_1 -> V_41 , V_11 ) ;
if ( V_1 -> V_42 ) {
V_30 = - V_43 ;
F_14 ( & V_1 -> V_41 , V_11 ) ;
goto V_38;
}
V_1 -> V_27 . V_12 ++ ;
F_14 ( & V_1 -> V_41 , V_11 ) ;
if ( V_1 -> V_27 . V_12 == 1 ) {
V_30 = F_15 ( V_1 ) ;
if ( V_30 < 0 )
goto V_38;
}
V_30 = F_16 ( V_9 , V_29 , V_1 ) ;
if ( V_30 ) {
if ( V_31 >= V_32 )
F_4 ( L_7 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_30 ) ;
goto V_38;
}
if ( V_31 >= V_32 )
F_4 ( L_8 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_30 = 0 ;
V_38:
if ( V_30 ) {
if ( V_9 -> V_12 == 1 )
V_1 -> V_27 . V_9 = NULL ;
if( V_1 -> V_27 . V_12 )
V_1 -> V_27 . V_12 -- ;
}
return V_30 ;
}
static void F_17 ( struct V_8 * V_9 , struct V_28 * V_29 )
{
T_1 * V_1 = V_9 -> V_26 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_9 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_10 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_27 . V_12 ) ;
if ( F_18 ( & V_1 -> V_27 , V_9 , V_29 ) == 0 )
goto V_38;
F_19 ( & V_1 -> V_27 . V_44 ) ;
if ( V_1 -> V_27 . V_11 & V_45 )
F_20 ( V_9 , V_1 -> V_46 ) ;
F_21 ( V_9 ) ;
F_22 ( V_9 ) ;
F_23 ( V_1 ) ;
F_24 ( & V_1 -> V_27 . V_44 ) ;
F_25 ( & V_1 -> V_27 , V_9 ) ;
V_1 -> V_27 . V_9 = NULL ;
V_38:
if ( V_31 >= V_32 )
F_4 ( L_11 , __FILE__ , __LINE__ ,
V_9 -> V_18 -> V_2 , V_1 -> V_27 . V_12 ) ;
}
static void F_26 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_12 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_13 ) )
return;
F_19 ( & V_1 -> V_27 . V_44 ) ;
F_21 ( V_9 ) ;
F_23 ( V_1 ) ;
F_13 ( & V_1 -> V_27 . V_47 , V_11 ) ;
V_1 -> V_27 . V_12 = 0 ;
V_1 -> V_27 . V_11 &= ~ V_48 ;
V_1 -> V_27 . V_9 = NULL ;
F_14 ( & V_1 -> V_27 . V_47 , V_11 ) ;
F_24 ( & V_1 -> V_27 . V_44 ) ;
F_27 ( & V_1 -> V_27 . V_49 ) ;
}
static void F_28 ( struct V_8 * V_9 , struct V_50 * V_51 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_14 , __FILE__ , __LINE__ ,
V_9 -> V_18 -> V_2 ) ;
F_29 ( V_1 ) ;
if ( V_51 -> V_52 & V_53 &&
! ( V_9 -> V_54 . V_52 & V_53 ) ) {
V_1 -> V_55 &= ~ ( V_56 | V_57 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_30 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
if ( ! ( V_51 -> V_52 & V_53 ) &&
V_9 -> V_54 . V_52 & V_53 ) {
V_1 -> V_55 |= V_57 ;
if ( ! ( V_9 -> V_54 . V_52 & V_58 ) ||
! F_31 ( V_59 , & V_9 -> V_11 ) ) {
V_1 -> V_55 |= V_56 ;
}
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_30 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
if ( V_51 -> V_52 & V_58 &&
! ( V_9 -> V_54 . V_52 & V_58 ) ) {
V_9 -> V_60 = 0 ;
F_32 ( V_9 ) ;
}
}
static int F_33 ( struct V_8 * V_9 ,
const unsigned char * V_61 , int V_12 )
{
int V_62 , V_63 = 0 ;
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_15 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_12 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_16 ) )
goto V_38;
if ( ! V_1 -> V_64 )
goto V_38;
if ( V_1 -> V_65 . V_66 == V_67 ) {
if ( V_12 > V_1 -> V_68 ) {
V_63 = - V_69 ;
goto V_38;
}
if ( V_1 -> V_70 )
goto V_38;
if ( V_1 -> V_71 ) {
F_34 ( V_1 , V_1 -> V_64 , V_1 -> V_71 ) ;
goto V_72;
}
V_63 = V_1 -> V_71 = V_12 ;
F_34 ( V_1 , V_61 , V_12 ) ;
goto V_72;
}
for (; ; ) {
V_62 = F_35 ( int , V_12 ,
F_36 ( V_1 -> V_68 - V_1 -> V_71 - 1 ,
V_1 -> V_68 - V_1 -> V_73 ) ) ;
if ( V_62 <= 0 )
break;
memcpy ( V_1 -> V_64 + V_1 -> V_73 , V_61 , V_62 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_1 -> V_73 += V_62 ;
if ( V_1 -> V_73 >= V_1 -> V_68 )
V_1 -> V_73 -= V_1 -> V_68 ;
V_1 -> V_71 += V_62 ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
V_61 += V_62 ;
V_12 -= V_62 ;
V_63 += V_62 ;
}
if ( V_1 -> V_65 . V_66 == V_67 ) {
if ( V_12 ) {
V_63 = V_1 -> V_71 = 0 ;
goto V_38;
}
F_34 ( V_1 , V_1 -> V_64 , V_1 -> V_71 ) ;
}
V_72:
if ( V_1 -> V_71 && ! V_9 -> V_74 && ! V_9 -> V_60 ) {
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( ! V_1 -> V_70 )
F_37 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
V_38:
if ( V_31 >= V_32 )
F_4 ( L_17 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_63 ) ;
return V_63 ;
}
static int F_38 ( struct V_8 * V_9 , unsigned char V_75 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
int V_63 = 0 ;
if ( V_31 >= V_32 ) {
F_4 ( L_18 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_75 ) ;
}
if ( F_2 ( V_1 , V_9 -> V_2 , L_19 ) )
return 0 ;
if ( ! V_1 -> V_64 )
return 0 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( ( V_1 -> V_65 . V_66 != V_67 ) ||
! V_1 -> V_70 ) {
if ( V_1 -> V_71 < V_1 -> V_68 - 1 ) {
V_1 -> V_64 [ V_1 -> V_73 ++ ] = V_75 ;
if ( V_1 -> V_73 >= V_1 -> V_68 )
V_1 -> V_73 -= V_1 -> V_68 ;
V_1 -> V_71 ++ ;
V_63 = 1 ;
}
}
F_14 ( & V_1 -> V_47 , V_11 ) ;
return V_63 ;
}
static void F_39 ( struct V_8 * V_9 , char V_75 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_20 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_75 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_21 ) )
return;
V_1 -> V_76 = V_75 ;
if ( V_75 ) {
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( ! V_1 -> V_77 )
F_37 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
}
static void F_20 ( struct V_8 * V_9 , int V_46 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_78 , V_79 ;
if ( ! V_1 )
return;
if ( V_31 >= V_32 )
F_4 ( L_22 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_23 ) )
return;
if ( ! F_31 ( V_80 , & V_1 -> V_27 . V_11 ) )
goto exit;
V_78 = V_81 ;
if ( V_1 -> V_65 . V_82 ) {
V_79 = V_1 -> V_46 / ( 32 * 5 ) ;
if ( ! V_79 )
V_79 ++ ;
} else
V_79 = 1 ;
if ( V_46 )
V_79 = F_35 (unsigned long, char_time, timeout) ;
if ( V_1 -> V_65 . V_66 == V_67 ) {
while ( V_1 -> V_70 ) {
F_40 ( F_41 ( V_79 ) ) ;
if ( F_42 ( V_83 ) )
break;
if ( V_46 && F_43 ( V_81 , V_78 + V_46 ) )
break;
}
} else {
while ( V_1 -> V_70 && V_1 -> V_77 ) {
F_40 ( F_41 ( V_79 ) ) ;
if ( F_42 ( V_83 ) )
break;
if ( V_46 && F_43 ( V_81 , V_78 + V_46 ) )
break;
}
}
exit:
if ( V_31 >= V_32 )
F_4 ( L_24 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static int F_44 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
int V_63 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_25 ) )
return 0 ;
if ( V_1 -> V_65 . V_66 == V_67 ) {
V_63 = ( V_1 -> V_70 ) ? 0 : V_84 ;
} else {
V_63 = V_1 -> V_68 - V_1 -> V_71 - 1 ;
if ( V_63 < 0 )
V_63 = 0 ;
}
if ( V_31 >= V_32 )
F_4 ( L_26 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_63 ) ;
return V_63 ;
}
static void F_45 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_27 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_71 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_28 ) )
return;
if ( V_1 -> V_71 <= 0 || V_9 -> V_74 || V_9 -> V_60 ||
! V_1 -> V_64 )
return;
if ( V_31 >= V_32 )
F_4 ( L_29 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( ! V_1 -> V_70 ) {
if ( ( V_1 -> V_65 . V_66 == V_67 ) &&
V_1 -> V_71 ) {
F_34 ( V_1 ,
V_1 -> V_64 , V_1 -> V_71 ) ;
}
F_37 ( V_1 ) ;
}
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
static void F_21 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_30 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_31 ) )
return;
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_1 -> V_71 = V_1 -> V_73 = V_1 -> V_85 = 0 ;
F_46 ( & V_1 -> V_86 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
F_47 ( V_9 ) ;
}
static void F_48 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_32 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_33 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( V_1 -> V_77 )
F_49 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
static void F_32 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_34 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_35 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( ! V_1 -> V_77 )
F_37 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
static int F_50 ( struct V_8 * V_9 ,
unsigned int V_87 , unsigned long V_88 )
{
T_1 * V_1 = V_9 -> V_26 ;
void T_3 * V_89 = ( void T_3 * ) V_88 ;
if ( V_31 >= V_32 )
F_4 ( L_36 , __FILE__ , __LINE__ ,
V_1 -> V_25 , V_87 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_37 ) )
return - V_21 ;
if ( ( V_87 != V_90 ) && ( V_87 != V_91 ) &&
( V_87 != V_92 ) ) {
if ( V_9 -> V_11 & ( 1 << V_93 ) )
return - V_69 ;
}
switch ( V_87 ) {
case V_94 :
return F_51 ( V_1 , V_89 ) ;
case V_95 :
return F_52 ( V_1 , V_89 ) ;
case V_96 :
return F_53 ( V_1 , V_89 ) ;
case V_97 :
return F_54 ( V_1 , ( int ) V_88 ) ;
case V_98 :
return F_55 ( V_1 , ( int ) V_88 ) ;
case V_99 :
return F_56 ( V_1 , ( int ) V_88 ) ;
case V_100 :
return F_57 ( V_1 ) ;
case V_101 :
return F_58 ( V_1 , V_89 ) ;
case V_102 :
return F_59 ( V_1 , V_89 ) ;
case V_103 :
return 0 ;
case V_92 :
return F_60 ( V_1 , ( int ) V_88 ) ;
default:
return - V_104 ;
}
return 0 ;
}
static int F_61 ( struct V_8 * V_9 ,
struct V_105 * V_106 )
{
T_1 * V_1 = V_9 -> V_26 ;
struct V_107 V_108 ;
unsigned long V_11 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_108 = V_1 -> V_106 ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
V_106 -> V_109 = V_108 . V_109 ;
V_106 -> V_110 = V_108 . V_110 ;
V_106 -> V_111 = V_108 . V_111 ;
V_106 -> V_112 = V_108 . V_112 ;
V_106 -> V_113 = V_108 . V_113 ;
V_106 -> V_114 = V_108 . V_114 ;
V_106 -> V_115 = V_108 . V_115 ;
V_106 -> V_116 = V_108 . V_116 ;
V_106 -> V_117 = V_108 . V_117 ;
V_106 -> V_118 = V_108 . V_118 ;
V_106 -> V_119 = V_108 . V_119 ;
return 0 ;
}
static inline void F_62 ( struct V_120 * V_121 , T_1 * V_1 )
{
char V_122 [ 30 ] ;
unsigned long V_11 ;
F_63 ( V_121 , L_38
L_39 ,
V_1 -> V_25 ,
V_1 -> V_123 ,
V_1 -> V_124 ,
V_1 -> V_125 ,
V_1 -> V_126 ,
V_1 -> V_127 ,
V_1 -> V_68 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_64 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
V_122 [ 0 ] = 0 ;
V_122 [ 1 ] = 0 ;
if ( V_1 -> V_55 & V_56 )
strcat ( V_122 , L_40 ) ;
if ( V_1 -> V_55 & V_128 )
strcat ( V_122 , L_41 ) ;
if ( V_1 -> V_55 & V_57 )
strcat ( V_122 , L_42 ) ;
if ( V_1 -> V_55 & V_129 )
strcat ( V_122 , L_43 ) ;
if ( V_1 -> V_55 & V_130 )
strcat ( V_122 , L_44 ) ;
if ( V_1 -> V_55 & V_131 )
strcat ( V_122 , L_45 ) ;
if ( V_1 -> V_65 . V_66 == V_67 ) {
F_63 ( V_121 , L_46 ,
V_1 -> V_106 . V_132 , V_1 -> V_106 . V_133 ) ;
if ( V_1 -> V_106 . V_134 )
F_63 ( V_121 , L_47 , V_1 -> V_106 . V_134 ) ;
if ( V_1 -> V_106 . V_135 )
F_63 ( V_121 , L_48 , V_1 -> V_106 . V_135 ) ;
if ( V_1 -> V_106 . V_136 )
F_63 ( V_121 , L_49 , V_1 -> V_106 . V_136 ) ;
if ( V_1 -> V_106 . V_137 )
F_63 ( V_121 , L_50 , V_1 -> V_106 . V_137 ) ;
if ( V_1 -> V_106 . V_138 )
F_63 ( V_121 , L_51 , V_1 -> V_106 . V_138 ) ;
if ( V_1 -> V_106 . V_139 )
F_63 ( V_121 , L_50 , V_1 -> V_106 . V_139 ) ;
} else {
F_63 ( V_121 , L_52 ,
V_1 -> V_106 . V_114 , V_1 -> V_106 . V_113 ) ;
if ( V_1 -> V_106 . V_115 )
F_63 ( V_121 , L_53 , V_1 -> V_106 . V_115 ) ;
if ( V_1 -> V_106 . V_117 )
F_63 ( V_121 , L_54 , V_1 -> V_106 . V_117 ) ;
if ( V_1 -> V_106 . V_118 )
F_63 ( V_121 , L_55 , V_1 -> V_106 . V_118 ) ;
if ( V_1 -> V_106 . V_116 )
F_63 ( V_121 , L_56 , V_1 -> V_106 . V_116 ) ;
}
F_63 ( V_121 , L_57 , V_122 + 1 ) ;
F_63 ( V_121 , L_58 ,
V_1 -> V_70 , V_1 -> V_140 , V_1 -> V_141 ,
V_1 -> V_142 ) ;
}
static int F_65 ( struct V_120 * V_121 , void * V_143 )
{
T_1 * V_1 ;
F_63 ( V_121 , L_59 , V_144 ) ;
V_1 = V_22 ;
while( V_1 ) {
F_62 ( V_121 , V_1 ) ;
V_1 = V_1 -> V_23 ;
}
return 0 ;
}
static int F_66 ( struct V_145 * V_145 , struct V_28 * V_28 )
{
return F_67 ( V_28 , F_65 , NULL ) ;
}
static int F_68 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_60 ) )
return 0 ;
if ( V_31 >= V_32 )
F_4 ( L_61 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_71 ) ;
return V_1 -> V_71 ;
}
static void F_69 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_63 ) )
return;
if ( F_70 ( V_9 ) )
F_39 ( V_9 , F_71 ( V_9 ) ) ;
if ( V_9 -> V_54 . V_52 & V_58 ) {
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_1 -> V_55 &= ~ V_56 ;
F_30 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
}
static void F_72 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_64 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_65 ) )
return;
if ( F_70 ( V_9 ) ) {
if ( V_1 -> V_76 )
V_1 -> V_76 = 0 ;
else
F_39 ( V_9 , F_73 ( V_9 ) ) ;
}
if ( V_9 -> V_54 . V_52 & V_58 ) {
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_1 -> V_55 |= V_56 ;
F_30 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
}
static int F_74 ( struct V_8 * V_9 , int V_146 )
{
unsigned char V_147 ;
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_66 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_146 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_67 ) )
return - V_148 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_147 = F_75 ( V_1 , V_149 ) ;
if ( V_146 == - 1 )
V_147 |= V_150 ;
else
V_147 &= ~ V_150 ;
F_76 ( V_1 , V_149 , V_147 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
return 0 ;
}
static int F_77 ( struct V_151 * V_152 , unsigned short V_153 ,
unsigned short V_117 )
{
T_1 * V_1 = F_78 ( V_152 ) ;
unsigned char V_154 ;
unsigned short V_155 ;
if ( V_1 -> V_27 . V_12 )
return - V_43 ;
switch ( V_153 )
{
case V_156 : V_154 = V_157 ; break;
case V_158 : V_154 = V_159 ; break;
case V_160 : V_154 = V_161 ; break;
case V_162 : V_154 = V_163 ; break;
case V_164 : V_154 = V_165 ; break;
default: return - V_148 ;
}
switch ( V_117 )
{
case V_166 : V_155 = V_167 ; break;
case V_168 : V_155 = V_169 ; break;
case V_170 : V_155 = V_171 ; break;
default: return - V_148 ;
}
V_1 -> V_65 . V_153 = V_154 ;
V_1 -> V_65 . V_172 = V_155 ;
if ( V_1 -> V_42 )
F_79 ( V_1 ) ;
return 0 ;
}
static T_4 F_80 ( struct V_173 * V_174 ,
struct V_151 * V_152 )
{
T_1 * V_1 = F_78 ( V_152 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( V_175 L_68 , __FILE__ , V_152 -> V_2 ) ;
F_81 ( V_152 ) ;
V_1 -> V_71 = V_174 -> V_176 ;
F_34 ( V_1 , V_174 -> V_10 , V_174 -> V_176 ) ;
V_152 -> V_177 . V_178 ++ ;
V_152 -> V_177 . V_179 += V_174 -> V_176 ;
F_82 ( V_174 ) ;
V_152 -> V_180 = V_81 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( ! V_1 -> V_70 )
F_37 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
return V_181 ;
}
static int F_83 ( struct V_151 * V_152 )
{
T_1 * V_1 = F_78 ( V_152 ) ;
int V_182 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_69 , __FILE__ , V_152 -> V_2 ) ;
if ( ( V_182 = F_84 ( V_152 ) ) )
return V_182 ;
F_13 ( & V_1 -> V_41 , V_11 ) ;
if ( V_1 -> V_27 . V_12 != 0 || V_1 -> V_42 != 0 ) {
F_4 ( V_183 L_70 , V_152 -> V_2 ) ;
F_14 ( & V_1 -> V_41 , V_11 ) ;
return - V_43 ;
}
V_1 -> V_42 = 1 ;
F_14 ( & V_1 -> V_41 , V_11 ) ;
if ( ( V_182 = F_15 ( V_1 ) ) != 0 ) {
F_13 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_42 = 0 ;
F_14 ( & V_1 -> V_41 , V_11 ) ;
return V_182 ;
}
V_1 -> V_55 |= V_56 | V_57 ;
F_79 ( V_1 ) ;
V_152 -> V_180 = V_81 ;
F_85 ( V_152 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_64 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
if ( V_1 -> V_55 & V_130 )
F_86 ( V_152 ) ;
else
F_87 ( V_152 ) ;
return 0 ;
}
static int F_88 ( struct V_151 * V_152 )
{
T_1 * V_1 = F_78 ( V_152 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_71 , __FILE__ , V_152 -> V_2 ) ;
F_81 ( V_152 ) ;
F_23 ( V_1 ) ;
F_89 ( V_152 ) ;
F_13 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_42 = 0 ;
F_14 ( & V_1 -> V_41 , V_11 ) ;
return 0 ;
}
static int F_90 ( struct V_151 * V_152 , struct V_184 * V_185 , int V_87 )
{
const T_5 V_186 = sizeof( V_187 ) ;
V_187 V_188 ;
V_187 T_3 * line = V_185 -> V_189 . V_190 . V_191 ;
T_1 * V_1 = F_78 ( V_152 ) ;
unsigned int V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_72 , __FILE__ , V_152 -> V_2 ) ;
if ( V_1 -> V_27 . V_12 )
return - V_43 ;
if ( V_87 != V_192 )
return F_91 ( V_152 , V_185 , V_87 ) ;
switch( V_185 -> V_189 . type ) {
case V_193 :
V_185 -> V_189 . type = V_194 ;
if ( V_185 -> V_189 . V_186 < V_186 ) {
V_185 -> V_189 . V_186 = V_186 ;
return - V_195 ;
}
V_11 = V_1 -> V_65 . V_11 & ( V_196 | V_197 |
V_198 | V_199 |
V_200 | V_201 |
V_202 | V_203 ) ;
switch ( V_11 ) {
case ( V_196 | V_200 ) : V_188 . V_204 = V_205 ; break;
case ( V_198 | V_202 ) : V_188 . V_204 = V_206 ; break;
case ( V_196 | V_202 ) : V_188 . V_204 = V_207 ; break;
case ( V_196 | V_203 ) : V_188 . V_204 = V_208 ; break;
default: V_188 . V_204 = V_209 ;
}
V_188 . V_210 = V_1 -> V_65 . V_211 ;
V_188 . V_212 = V_1 -> V_65 . V_212 ? 1 : 0 ;
if ( F_92 ( line , & V_188 , V_186 ) )
return - V_213 ;
return 0 ;
case V_194 :
if( ! F_93 ( V_214 ) )
return - V_215 ;
if ( F_94 ( & V_188 , line , V_186 ) )
return - V_213 ;
switch ( V_188 . V_204 )
{
case V_205 : V_11 = V_196 | V_200 ; break;
case V_208 : V_11 = V_196 | V_203 ; break;
case V_206 : V_11 = V_198 | V_202 ; break;
case V_207 : V_11 = V_196 | V_202 ; break;
case V_209 : V_11 = V_1 -> V_65 . V_11 &
( V_196 | V_197 |
V_198 | V_199 |
V_200 | V_201 |
V_202 | V_203 ) ; break;
default: return - V_148 ;
}
if ( V_188 . V_212 != 0 && V_188 . V_212 != 1 )
return - V_148 ;
V_1 -> V_65 . V_11 &= ~ ( V_196 | V_197 |
V_198 | V_199 |
V_200 | V_201 |
V_202 | V_203 ) ;
V_1 -> V_65 . V_11 |= V_11 ;
V_1 -> V_65 . V_212 = V_188 . V_212 ;
if ( V_11 & ( V_198 | V_202 ) )
V_1 -> V_65 . V_211 = V_188 . V_210 ;
else
V_1 -> V_65 . V_211 = 0 ;
if ( V_1 -> V_42 )
F_79 ( V_1 ) ;
return 0 ;
default:
return F_91 ( V_152 , V_185 , V_87 ) ;
}
}
static void F_95 ( struct V_151 * V_152 )
{
T_1 * V_1 = F_78 ( V_152 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_73 , V_152 -> V_2 ) ;
V_152 -> V_177 . V_216 ++ ;
V_152 -> V_177 . V_217 ++ ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_49 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
F_96 ( V_152 ) ;
}
static void F_97 ( T_1 * V_1 )
{
if ( F_98 ( V_1 -> V_218 ) )
F_96 ( V_1 -> V_218 ) ;
}
static void F_99 ( T_1 * V_1 , char * V_61 , int V_186 )
{
struct V_173 * V_174 = F_100 ( V_186 ) ;
struct V_151 * V_152 = V_1 -> V_218 ;
if ( V_31 >= V_32 )
F_4 ( L_74 , V_152 -> V_2 ) ;
if ( V_174 == NULL ) {
F_4 ( V_219 L_75 ,
V_152 -> V_2 ) ;
V_152 -> V_177 . V_220 ++ ;
return;
}
memcpy ( F_101 ( V_174 , V_186 ) , V_61 , V_186 ) ;
V_174 -> V_221 = F_102 ( V_174 , V_152 ) ;
V_152 -> V_177 . V_222 ++ ;
V_152 -> V_177 . V_223 += V_186 ;
F_103 ( V_174 ) ;
}
static int F_104 ( T_1 * V_1 )
{
int V_182 ;
struct V_151 * V_152 ;
T_6 * V_224 ;
if ( ! ( V_152 = F_105 ( V_1 ) ) ) {
F_4 ( V_225 L_76 , __FILE__ ) ;
return - V_226 ;
}
V_152 -> V_227 = V_1 -> V_123 ;
V_152 -> V_228 = V_1 -> V_123 + V_229 - 1 ;
V_152 -> V_230 = V_1 -> V_127 ;
V_152 -> V_231 = & V_232 ;
V_152 -> V_233 = 10 * V_234 ;
V_152 -> V_235 = 50 ;
V_224 = F_106 ( V_152 ) ;
V_224 -> V_236 = F_77 ;
V_224 -> V_237 = F_80 ;
if ( ( V_182 = F_107 ( V_152 ) ) ) {
F_4 ( V_183 L_77 , __FILE__ ) ;
F_108 ( V_152 ) ;
return V_182 ;
}
V_1 -> V_218 = V_152 ;
return 0 ;
}
static void F_109 ( T_1 * V_1 )
{
F_110 ( V_1 -> V_218 ) ;
F_108 ( V_1 -> V_218 ) ;
V_1 -> V_218 = NULL ;
}
static int F_111 ( T_1 * V_1 )
{
unsigned long V_11 ;
int V_182 = 0 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( V_1 -> V_142 & V_238 ) {
V_1 -> V_142 &= ~ V_238 ;
V_182 = V_238 ;
} else if ( V_1 -> V_142 & V_239 ) {
V_1 -> V_142 &= ~ V_239 ;
V_182 = V_239 ;
} else if ( V_1 -> V_142 & V_240 ) {
V_1 -> V_142 &= ~ V_240 ;
V_182 = V_240 ;
}
if ( ! V_182 ) {
V_1 -> V_141 = false ;
V_1 -> V_140 = false ;
}
F_14 ( & V_1 -> V_47 , V_11 ) ;
return V_182 ;
}
static void F_112 ( struct V_241 * V_242 )
{
T_1 * V_1 = F_113 ( V_242 , T_1 , V_243 ) ;
int V_244 ;
if ( V_31 >= V_245 )
F_4 ( L_78 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_141 = true ;
while( ( V_244 = F_111 ( V_1 ) ) != 0 ) {
if ( V_31 >= V_245 )
F_4 ( L_79 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_244 ) ;
switch ( V_244 ) {
case V_238 :
F_114 ( V_1 ) ;
break;
case V_239 :
F_115 ( V_1 ) ;
break;
case V_240 :
F_116 ( V_1 ) ;
break;
default:
F_4 ( L_80 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_244 ) ;
break;
}
}
if ( V_31 >= V_245 )
F_4 ( L_81 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_114 ( T_1 * V_1 )
{
if ( V_31 >= V_245 )
F_4 ( L_82 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
while( F_117 ( V_1 ) ) ;
}
static void F_115 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
if ( V_31 >= V_245 )
F_4 ( L_83 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_9 )
F_47 ( V_9 ) ;
}
static void F_116 ( T_1 * V_1 )
{
if ( V_31 >= V_245 )
F_4 ( L_84 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_246 = 0 ;
V_1 -> V_247 = 0 ;
V_1 -> V_248 = 0 ;
V_1 -> V_249 = 0 ;
}
static void F_118 ( T_1 * V_1 )
{
unsigned char V_250 = ( V_1 -> V_251 & 1 ) ? V_252 : V_253 ;
F_76 ( V_1 , V_254 , 0 ) ;
F_76 ( V_1 , ( unsigned char ) ( V_250 + V_255 ) , 0 ) ;
V_1 -> V_256 = true ;
if ( V_31 >= V_257 )
F_4 ( L_85 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_119 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
struct V_107 * V_106 = & V_1 -> V_106 ;
unsigned char V_258 = F_75 ( V_1 , V_259 ) & V_1 -> V_260 & ( V_261 + V_262 + V_263 + V_264 ) ;
unsigned char V_265 = F_75 ( V_1 , V_266 ) & V_1 -> V_267 & V_268 ;
if ( V_258 )
F_76 ( V_1 , V_259 , V_258 ) ;
if ( V_265 )
F_76 ( V_1 , V_266 , V_265 ) ;
if ( V_31 >= V_257 )
F_4 ( L_86 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_258 , V_265 ) ;
if ( V_1 -> V_65 . V_66 == V_269 ) {
if ( V_258 & V_264 ) {
V_106 -> V_118 ++ ;
if ( ! ( V_258 & V_1 -> V_270 ) ) {
if ( V_1 -> V_271 & V_264 ) {
F_120 ( & V_1 -> V_27 , 0 , V_272 ) ;
if ( V_9 && ( V_1 -> V_27 . V_11 & V_273 ) )
F_121 ( V_9 ) ;
}
}
}
}
else {
if ( V_258 & ( V_261 | V_262 ) ) {
if ( V_258 & V_261 )
V_1 -> V_106 . V_274 ++ ;
else if ( V_258 & V_262 )
V_1 -> V_106 . V_275 ++ ;
F_27 ( & V_1 -> V_276 ) ;
}
}
if ( V_258 & V_263 ) {
F_64 ( V_1 ) ;
F_122 ( V_1 ,
V_277 | ( V_1 -> V_55 & V_130 ) ) ;
}
}
static void F_123 ( T_1 * V_1 )
{
T_7 V_258 ;
unsigned char V_278 ;
struct V_107 * V_106 = & V_1 -> V_106 ;
if ( V_31 >= V_257 )
F_4 ( L_87 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
while( ( V_258 = F_75 ( V_1 , V_279 ) ) & V_280 )
{
int V_281 = 0 ;
bool V_282 = false ;
V_278 = F_75 ( V_1 , V_283 ) ;
V_106 -> V_113 ++ ;
if ( V_258 & ( V_284 + V_285 + V_268 ) ) {
F_4 ( L_88 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_258 ) ;
if ( V_258 & V_284 )
V_106 -> V_117 ++ ;
else if ( V_258 & V_285 )
V_106 -> V_115 ++ ;
else if ( V_258 & V_268 )
V_106 -> V_116 ++ ;
if ( V_258 & V_1 -> V_286 )
continue;
V_258 &= V_1 -> V_287 ;
if ( V_258 & V_284 )
V_281 = V_288 ;
else if ( V_258 & V_285 )
V_281 = V_289 ;
if ( V_258 & V_268 ) {
V_282 = true ;
}
}
F_120 ( & V_1 -> V_27 , V_278 , V_281 ) ;
if ( V_282 )
F_120 ( & V_1 -> V_27 , 0 , V_290 ) ;
}
if ( V_31 >= V_257 ) {
F_4 ( L_89 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_106 -> V_113 , V_106 -> V_118 , V_106 -> V_117 ,
V_106 -> V_115 , V_106 -> V_116 ) ;
}
F_124 ( & V_1 -> V_27 ) ;
}
static void F_125 ( T_1 * V_1 , unsigned char V_258 )
{
if ( V_31 >= V_257 )
F_4 ( L_90 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_258 ) ;
F_76 ( V_1 , V_291 + V_292 , 0x00 ) ;
F_76 ( V_1 , V_291 + V_293 , 0xc0 ) ;
F_76 ( V_1 , V_291 + V_294 , V_295 ) ;
if ( V_258 & V_296 ) {
F_76 ( V_1 , V_297 , V_298 ) ;
F_76 ( V_1 , V_297 , V_299 ) ;
} else
F_76 ( V_1 , V_297 , V_300 ) ;
V_1 -> V_301 &= ~ V_302 ;
V_1 -> V_260 &= ~ ( V_303 + V_296 ) ;
F_126 ( V_1 , V_304 , ( unsigned short ) ( ( V_1 -> V_260 << 8 ) + V_1 -> V_301 ) ) ;
F_76 ( V_1 , V_259 , ( unsigned char ) ( V_296 + V_303 ) ) ;
if ( V_1 -> V_70 ) {
if ( V_1 -> V_65 . V_66 != V_269 ) {
if ( V_258 & V_296 )
V_1 -> V_106 . V_134 ++ ;
else if ( V_258 & V_303 )
V_1 -> V_106 . V_132 ++ ;
}
V_1 -> V_70 = false ;
V_1 -> V_71 = V_1 -> V_73 = V_1 -> V_85 = 0 ;
F_46 ( & V_1 -> V_86 ) ;
if ( V_1 -> V_65 . V_66 != V_269 && V_1 -> V_305 ) {
V_1 -> V_55 &= ~ V_56 ;
V_1 -> V_305 = false ;
F_30 ( V_1 ) ;
}
#if V_306
if ( V_1 -> V_42 )
F_97 ( V_1 ) ;
else
#endif
{
if ( V_1 -> V_27 . V_9 && ( V_1 -> V_27 . V_9 -> V_74 || V_1 -> V_27 . V_9 -> V_60 ) ) {
F_49 ( V_1 ) ;
return;
}
V_1 -> V_142 |= V_239 ;
}
}
}
static void F_127 ( T_1 * V_1 )
{
unsigned char V_258 = F_75 ( V_1 , V_259 ) & V_1 -> V_260 & ( V_296 + V_303 + V_307 ) ;
F_76 ( V_1 , V_259 , V_258 ) ;
if ( V_31 >= V_257 )
F_4 ( L_91 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_258 ) ;
if ( V_258 & ( V_296 + V_303 ) )
F_125 ( V_1 , V_258 ) ;
if ( V_258 & V_307 ) {
F_64 ( V_1 ) ;
F_122 ( V_1 ,
V_308 | ( V_1 -> V_55 & V_128 ) ) ;
}
}
static void F_128 ( T_1 * V_1 )
{
if ( V_31 >= V_257 )
F_4 ( L_92 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_71 ) ;
if ( V_1 -> V_65 . V_66 != V_269 ) {
V_1 -> V_301 &= ~ V_302 ;
V_1 -> V_260 |= V_303 ;
F_126 ( V_1 , V_304 , ( unsigned short ) ( ( V_1 -> V_260 << 8 ) + V_1 -> V_301 ) ) ;
return;
}
if ( V_1 -> V_27 . V_9 && ( V_1 -> V_27 . V_9 -> V_74 || V_1 -> V_27 . V_9 -> V_60 ) ) {
F_49 ( V_1 ) ;
return;
}
if ( V_1 -> V_71 )
F_129 ( V_1 ) ;
else {
V_1 -> V_70 = false ;
V_1 -> V_301 &= ~ V_302 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
}
if ( V_1 -> V_71 < V_309 )
V_1 -> V_142 |= V_239 ;
}
static void F_130 ( T_1 * V_1 )
{
unsigned char V_258 = F_75 ( V_1 , V_310 + V_293 ) & 0xc0 ;
F_76 ( V_1 , V_310 + V_293 , ( unsigned char ) ( V_258 | 1 ) ) ;
if ( V_31 >= V_257 )
F_4 ( L_93 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_258 ) ;
V_1 -> V_142 |= V_238 ;
}
static void F_131 ( T_1 * V_1 )
{
unsigned char V_258 = F_75 ( V_1 , V_310 + V_293 ) & 0x30 ;
F_76 ( V_1 , V_310 + V_293 , ( unsigned char ) ( V_258 | 1 ) ) ;
if ( V_31 >= V_257 )
F_4 ( L_94 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_258 ) ;
V_1 -> V_311 = true ;
V_1 -> V_142 |= V_238 ;
}
static void F_132 ( T_1 * V_1 )
{
unsigned char V_312 = F_75 ( V_1 , V_259 ) ;
F_76 ( V_1 , V_291 + V_292 , 0x00 ) ;
F_76 ( V_1 , V_291 + V_293 , 0xc0 ) ;
F_76 ( V_1 , V_291 + V_294 , V_295 ) ;
if ( V_31 >= V_257 )
F_4 ( L_95 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_312 ) ;
F_126 ( V_1 , V_313 , 0 ) ;
V_1 -> V_301 |= V_302 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
}
static void F_133 ( T_1 * V_1 )
{
unsigned char V_258 = F_75 ( V_1 , V_291 + V_293 ) & 0x30 ;
F_76 ( V_1 , V_291 + V_293 , ( unsigned char ) ( V_258 | 1 ) ) ;
if ( V_31 >= V_257 )
F_4 ( L_96 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_258 ) ;
}
static void F_122 ( T_1 * V_1 , T_7 V_258 )
{
struct V_107 * V_106 ;
if ( V_31 >= V_257 )
F_4 ( L_97 ,
__FILE__ , __LINE__ , V_258 ) ;
if ( V_258 & ( V_308 | V_277 |
V_314 | V_315 ) ) {
V_106 = & V_1 -> V_106 ;
if ( V_258 & V_315 ) {
V_106 -> V_111 ++ ;
if ( V_258 & V_131 )
V_1 -> V_316 . V_317 ++ ;
else
V_1 -> V_316 . V_318 ++ ;
}
if ( V_258 & V_314 ) {
V_106 -> V_110 ++ ;
if ( V_258 & V_129 )
V_1 -> V_316 . V_319 ++ ;
else
V_1 -> V_316 . V_320 ++ ;
}
if ( V_258 & V_277 ) {
if ( ( V_1 -> V_248 ) ++ >= V_321 ) {
V_1 -> V_260 &= ~ V_263 ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
}
V_106 -> V_112 ++ ;
if ( V_258 & V_130 ) {
V_1 -> V_316 . V_323 ++ ;
} else
V_1 -> V_316 . V_324 ++ ;
#if V_306
if ( V_1 -> V_42 ) {
if ( V_258 & V_130 )
F_86 ( V_1 -> V_218 ) ;
else
F_87 ( V_1 -> V_218 ) ;
}
#endif
}
if ( V_258 & V_308 )
{
if ( ( V_1 -> V_249 ) ++ >= V_321 ) {
V_1 -> V_260 &= ~ V_307 ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
}
V_106 -> V_109 ++ ;
if ( V_258 & V_128 )
V_1 -> V_316 . V_325 ++ ;
else
V_1 -> V_316 . V_326 ++ ;
}
F_27 ( & V_1 -> V_327 ) ;
F_27 ( & V_1 -> V_276 ) ;
if ( ( V_1 -> V_27 . V_11 & V_328 ) &&
( V_258 & V_277 ) ) {
if ( V_31 >= V_257 )
F_4 ( L_98 , V_1 -> V_25 ,
( V_258 & V_130 ) ? L_99 : L_100 ) ;
if ( V_258 & V_130 )
F_27 ( & V_1 -> V_27 . V_49 ) ;
else {
if ( V_31 >= V_257 )
F_4 ( L_101 ) ;
if ( V_1 -> V_27 . V_9 )
F_134 ( V_1 -> V_27 . V_9 ) ;
}
}
if ( F_135 ( & V_1 -> V_27 ) &&
( V_258 & V_308 ) ) {
if ( V_1 -> V_27 . V_9 ) {
if ( V_1 -> V_27 . V_9 -> V_60 ) {
if ( V_258 & V_128 ) {
if ( V_31 >= V_257 )
F_4 ( L_102 ) ;
V_1 -> V_27 . V_9 -> V_60 = 0 ;
F_37 ( V_1 ) ;
V_1 -> V_142 |= V_239 ;
return;
}
} else {
if ( ! ( V_258 & V_128 ) ) {
if ( V_31 >= V_257 )
F_4 ( L_103 ) ;
V_1 -> V_27 . V_9 -> V_60 = 1 ;
F_49 ( V_1 ) ;
}
}
}
}
}
V_1 -> V_142 |= V_240 ;
}
static T_8 F_136 ( int V_329 , void * V_330 )
{
T_1 * V_1 = V_330 ;
unsigned char V_258 , V_331 , V_332 = 0 ;
unsigned char V_333 , V_334 , V_335 = 0 ;
unsigned char V_336 , V_337 = 0 ;
unsigned char V_338 ;
unsigned int V_339 ;
unsigned short V_340 ;
if ( V_31 >= V_257 )
F_4 ( V_341 L_104 ,
__FILE__ , __LINE__ , V_1 -> V_127 ) ;
F_137 ( & V_1 -> V_47 ) ;
for(; ; ) {
V_340 = F_138 ( V_1 , V_342 ) ;
V_331 = ( unsigned char ) V_340 ;
V_334 = ( unsigned char ) ( V_340 >> 8 ) ;
V_336 = F_75 ( V_1 , V_343 ) ;
if ( V_31 >= V_257 )
F_4 ( V_341 L_105 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_331 , V_334 , V_336 ) ;
if ( V_1 -> V_344 == 4 ) {
V_340 = F_138 ( V_1 -> V_345 [ 2 ] , V_342 ) ;
V_332 = ( unsigned char ) V_340 ;
V_335 = ( unsigned char ) ( V_340 >> 8 ) ;
V_337 = F_75 ( V_1 -> V_345 [ 2 ] , V_343 ) ;
if ( V_31 >= V_257 )
F_4 ( L_106 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_332 , V_335 , V_337 ) ;
}
if ( ! V_331 && ! V_334 && ! V_336 &&
! V_332 && ! V_335 && ! V_337 )
break;
for( V_339 = 0 ; V_339 < V_1 -> V_344 ; V_339 ++ ) {
if ( V_1 -> V_345 [ V_339 ] == NULL )
continue;
if ( V_339 < 2 ) {
V_258 = V_331 ;
V_333 = V_334 ;
} else {
V_258 = V_332 ;
V_333 = V_335 ;
}
V_338 = V_339 & 1 ? 4 : 0 ;
if ( V_258 & V_280 << V_338 )
F_123 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_258 & V_346 << V_338 )
F_128 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_258 & V_347 << V_338 )
F_119 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_258 & V_150 << V_338 )
F_127 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_333 & V_280 << V_338 )
F_131 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_333 & V_346 << V_338 )
F_130 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_333 & V_347 << V_338 )
F_133 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_333 & V_150 << V_338 )
F_132 ( V_1 -> V_345 [ V_339 ] ) ;
}
if ( V_336 & ( V_348 | V_349 ) )
F_118 ( V_1 -> V_345 [ 0 ] ) ;
if ( V_336 & ( V_350 | V_351 ) )
F_118 ( V_1 -> V_345 [ 1 ] ) ;
if ( V_337 & ( V_348 | V_349 ) )
F_118 ( V_1 -> V_345 [ 2 ] ) ;
if ( V_337 & ( V_350 | V_351 ) )
F_118 ( V_1 -> V_345 [ 3 ] ) ;
}
for( V_339 = 0 ; V_339 < V_1 -> V_344 ; V_339 ++ ) {
T_1 * V_27 = V_1 -> V_345 [ V_339 ] ;
if ( V_27 && ( V_27 -> V_27 . V_12 || V_27 -> V_42 ) &&
V_27 -> V_142 && ! V_27 -> V_141 &&
! V_27 -> V_140 ) {
if ( V_31 >= V_257 )
F_4 ( L_107 ,
__FILE__ , __LINE__ , V_27 -> V_25 ) ;
F_139 ( & V_27 -> V_243 ) ;
V_27 -> V_140 = true ;
}
}
F_140 ( & V_1 -> V_47 ) ;
if ( V_31 >= V_257 )
F_4 ( V_341 L_108 ,
__FILE__ , __LINE__ , V_1 -> V_127 ) ;
return V_352 ;
}
static int F_15 ( T_1 * V_1 )
{
if ( V_31 >= V_32 )
F_4 ( L_109 , __FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_1 -> V_27 . V_11 & V_45 )
return 0 ;
if ( ! V_1 -> V_64 ) {
V_1 -> V_64 = F_141 ( V_1 -> V_68 , V_353 ) ;
if ( ! V_1 -> V_64 ) {
F_4 ( V_225 L_110 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_226 ;
}
}
V_1 -> V_142 = 0 ;
memset ( & V_1 -> V_106 , 0 , sizeof( V_1 -> V_106 ) ) ;
F_142 ( V_1 ) ;
F_29 ( V_1 ) ;
F_143 ( & V_1 -> V_354 , V_81 + F_144 ( 10 ) ) ;
if ( V_1 -> V_27 . V_9 )
F_145 ( V_93 , & V_1 -> V_27 . V_9 -> V_11 ) ;
V_1 -> V_27 . V_11 |= V_45 ;
return 0 ;
}
static void F_23 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( ! ( V_1 -> V_27 . V_11 & V_45 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_111 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_27 ( & V_1 -> V_327 ) ;
F_27 ( & V_1 -> V_276 ) ;
F_46 ( & V_1 -> V_86 ) ;
F_46 ( & V_1 -> V_354 ) ;
F_146 ( V_1 -> V_64 ) ;
V_1 -> V_64 = NULL ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_142 ( V_1 ) ;
if ( ! V_1 -> V_27 . V_9 || V_1 -> V_27 . V_9 -> V_54 . V_52 & V_355 ) {
V_1 -> V_55 &= ~ ( V_56 | V_57 ) ;
F_30 ( V_1 ) ;
}
F_14 ( & V_1 -> V_47 , V_11 ) ;
if ( V_1 -> V_27 . V_9 )
F_147 ( V_93 , & V_1 -> V_27 . V_9 -> V_11 ) ;
V_1 -> V_27 . V_11 &= ~ V_45 ;
}
static void F_79 ( T_1 * V_1 )
{
unsigned long V_11 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_148 ( V_1 ) ;
F_49 ( V_1 ) ;
V_1 -> V_71 = V_1 -> V_73 = V_1 -> V_85 = 0 ;
if ( V_1 -> V_65 . V_66 == V_67 || V_1 -> V_42 )
F_149 ( V_1 ) ;
else
F_150 ( V_1 ) ;
F_30 ( V_1 ) ;
V_1 -> V_248 = 0 ;
V_1 -> V_249 = 0 ;
V_1 -> V_246 = 0 ;
V_1 -> V_247 = 0 ;
V_1 -> V_260 |= ( V_263 | V_307 ) ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
F_64 ( V_1 ) ;
if ( V_1 -> V_42 || ( V_1 -> V_27 . V_9 && V_1 -> V_27 . V_9 -> V_54 . V_52 & V_356 ) )
F_151 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
static void F_29 ( T_1 * V_1 )
{
unsigned V_357 ;
int V_358 ;
if ( ! V_1 -> V_27 . V_9 )
return;
if ( V_31 >= V_32 )
F_4 ( L_112 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_357 = V_1 -> V_27 . V_9 -> V_54 . V_52 ;
if ( V_357 & V_53 )
V_1 -> V_55 |= V_56 | V_57 ;
else
V_1 -> V_55 &= ~ ( V_56 | V_57 ) ;
switch ( V_357 & V_359 ) {
case V_360 : V_1 -> V_65 . V_361 = 5 ; break;
case V_362 : V_1 -> V_65 . V_361 = 6 ; break;
case V_363 : V_1 -> V_65 . V_361 = 7 ; break;
case V_364 : V_1 -> V_65 . V_361 = 8 ; break;
default: V_1 -> V_65 . V_361 = 7 ; break;
}
if ( V_357 & V_365 )
V_1 -> V_65 . V_366 = 2 ;
else
V_1 -> V_65 . V_366 = 1 ;
V_1 -> V_65 . V_117 = V_367 ;
if ( V_357 & V_368 ) {
if ( V_357 & V_369 )
V_1 -> V_65 . V_117 = V_370 ;
else
V_1 -> V_65 . V_117 = V_371 ;
#ifdef F_152
if ( V_357 & F_152 )
V_1 -> V_65 . V_117 = V_372 ;
#endif
}
V_358 = V_1 -> V_65 . V_361 +
V_1 -> V_65 . V_366 + 1 ;
if ( V_1 -> V_65 . V_82 <= 460800 ) {
V_1 -> V_65 . V_82 = F_153 ( V_1 -> V_27 . V_9 ) ;
}
if ( V_1 -> V_65 . V_82 ) {
V_1 -> V_46 = ( 32 * V_234 * V_358 ) /
V_1 -> V_65 . V_82 ;
}
V_1 -> V_46 += V_234 / 50 ;
if ( V_357 & V_58 )
V_1 -> V_27 . V_11 |= V_373 ;
else
V_1 -> V_27 . V_11 &= ~ V_373 ;
if ( V_357 & V_374 )
V_1 -> V_27 . V_11 &= ~ V_328 ;
else
V_1 -> V_27 . V_11 |= V_328 ;
V_1 -> V_287 = V_268 ;
if ( F_154 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_287 |= V_284 | V_285 ;
if ( F_155 ( V_1 -> V_27 . V_9 ) || F_156 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_271 |= V_264 ;
if ( F_157 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_286 |= V_284 | V_285 ;
if ( F_158 ( V_1 -> V_27 . V_9 ) ) {
V_1 -> V_270 |= V_264 ;
if ( F_157 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_286 |= V_268 ;
}
F_79 ( V_1 ) ;
}
static int F_58 ( T_1 * V_1 , struct V_107 T_3 * V_375 )
{
int V_376 ;
if ( V_31 >= V_32 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( ! V_375 ) {
memset ( & V_1 -> V_106 , 0 , sizeof( V_1 -> V_106 ) ) ;
} else {
F_19 ( & V_1 -> V_27 . V_44 ) ;
F_159 ( V_376 , V_375 , & V_1 -> V_106 , sizeof( struct V_107 ) ) ;
F_24 ( & V_1 -> V_27 . V_44 ) ;
if ( V_376 )
return - V_213 ;
}
return 0 ;
}
static int F_51 ( T_1 * V_1 , T_9 T_3 * V_377 )
{
int V_376 ;
if ( V_31 >= V_32 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_19 ( & V_1 -> V_27 . V_44 ) ;
F_159 ( V_376 , V_377 , & V_1 -> V_65 , sizeof( T_9 ) ) ;
F_24 ( & V_1 -> V_27 . V_44 ) ;
if ( V_376 ) {
if ( V_31 >= V_32 )
F_4 ( L_114 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_213 ;
}
return 0 ;
}
static int F_52 ( T_1 * V_1 , T_9 T_3 * V_378 )
{
unsigned long V_11 ;
T_9 V_379 ;
int V_376 ;
if ( V_31 >= V_32 )
F_4 ( L_115 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_160 ( V_376 , & V_379 , V_378 , sizeof( T_9 ) ) ;
if ( V_376 ) {
if ( V_31 >= V_32 )
F_4 ( L_116 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_213 ;
}
F_19 ( & V_1 -> V_27 . V_44 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
memcpy ( & V_1 -> V_65 , & V_379 , sizeof( T_9 ) ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
F_29 ( V_1 ) ;
F_24 ( & V_1 -> V_27 . V_44 ) ;
return 0 ;
}
static int F_53 ( T_1 * V_1 , int T_3 * V_380 )
{
int V_376 ;
if ( V_31 >= V_32 )
F_4 ( L_117 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_380 ) ;
F_159 ( V_376 , V_380 , & V_1 -> V_380 , sizeof( int ) ) ;
if ( V_376 ) {
if ( V_31 >= V_32 )
F_4 ( L_118 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_213 ;
}
return 0 ;
}
static int F_54 ( T_1 * V_1 , int V_380 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_119 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_380 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_1 -> V_380 = V_380 ;
F_161 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
return 0 ;
}
static int F_55 ( T_1 * V_1 , int V_381 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_120 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_381 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( V_381 ) {
if ( ! V_1 -> V_77 ) {
F_37 ( V_1 ) ;
}
} else {
if ( V_1 -> V_77 )
F_49 ( V_1 ) ;
}
F_14 ( & V_1 -> V_47 , V_11 ) ;
return 0 ;
}
static int F_57 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_121 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( V_1 -> V_70 && V_1 -> V_65 . V_66 == V_67 ) {
V_1 -> V_260 &= ~ V_296 ;
V_1 -> V_260 |= V_303 ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
F_76 ( V_1 , V_259 , ( unsigned char ) ( V_303 + V_296 ) ) ;
F_76 ( V_1 , V_291 + V_293 , 0 ) ;
F_76 ( V_1 , V_291 + V_294 , V_295 ) ;
F_76 ( V_1 , V_297 , V_382 ) ;
}
F_14 ( & V_1 -> V_47 , V_11 ) ;
return 0 ;
}
static int F_56 ( T_1 * V_1 , int V_381 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_122 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_381 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( V_381 ) {
if ( ! V_1 -> V_383 )
F_151 ( V_1 ) ;
} else {
if ( V_1 -> V_383 )
F_148 ( V_1 ) ;
}
F_14 ( & V_1 -> V_47 , V_11 ) ;
return 0 ;
}
static int F_59 ( T_1 * V_1 , int T_3 * V_384 )
{
unsigned long V_11 ;
int V_385 ;
int V_182 = 0 ;
struct V_107 V_386 , V_108 ;
int V_387 ;
int V_388 ;
struct V_389 V_390 , V_391 ;
F_162 ( V_392 , V_83 ) ;
F_160 ( V_182 , & V_388 , V_384 , sizeof( int ) ) ;
if ( V_182 ) {
return - V_213 ;
}
if ( V_31 >= V_32 )
F_4 ( L_123 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_388 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_64 ( V_1 ) ;
V_385 = V_1 -> V_55 ;
V_387 = V_388 &
( ( ( V_385 & V_129 ) ? V_393 : V_394 ) +
( ( V_385 & V_130 ) ? V_395 : V_396 ) +
( ( V_385 & V_128 ) ? V_397 : V_398 ) +
( ( V_385 & V_131 ) ? V_399 : V_400 ) ) ;
if ( V_387 ) {
F_14 ( & V_1 -> V_47 , V_11 ) ;
goto exit;
}
V_386 = V_1 -> V_106 ;
V_390 = V_1 -> V_316 ;
if ( V_388 & ( V_401 + V_402 ) ) {
unsigned char V_403 = V_1 -> V_260 ;
unsigned char V_404 = V_403 +
( V_388 & V_401 ? V_261 : 0 ) +
( V_388 & V_402 ? V_262 : 0 ) ;
if ( V_403 != V_404 ) {
V_1 -> V_260 = V_404 ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
}
}
F_163 ( V_405 ) ;
F_164 ( & V_1 -> V_276 , & V_392 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
for(; ; ) {
F_165 () ;
if ( F_42 ( V_83 ) ) {
V_182 = - V_37 ;
break;
}
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_108 = V_1 -> V_106 ;
V_391 = V_1 -> V_316 ;
F_163 ( V_405 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
if ( V_391 . V_319 == V_390 . V_319 &&
V_391 . V_320 == V_390 . V_320 &&
V_391 . V_323 == V_390 . V_323 &&
V_391 . V_324 == V_390 . V_324 &&
V_391 . V_325 == V_390 . V_325 &&
V_391 . V_326 == V_390 . V_326 &&
V_391 . V_317 == V_390 . V_317 &&
V_391 . V_318 == V_390 . V_318 &&
V_108 . V_274 == V_386 . V_274 &&
V_108 . V_275 == V_386 . V_275 ) {
V_182 = - V_69 ;
break;
}
V_387 = V_388 &
( ( V_391 . V_319 != V_390 . V_319 ? V_393 : 0 ) +
( V_391 . V_320 != V_390 . V_320 ? V_394 : 0 ) +
( V_391 . V_323 != V_390 . V_323 ? V_395 : 0 ) +
( V_391 . V_324 != V_390 . V_324 ? V_396 : 0 ) +
( V_391 . V_325 != V_390 . V_325 ? V_397 : 0 ) +
( V_391 . V_326 != V_390 . V_326 ? V_398 : 0 ) +
( V_391 . V_317 != V_390 . V_317 ? V_399 : 0 ) +
( V_391 . V_318 != V_390 . V_318 ? V_400 : 0 ) +
( V_108 . V_274 != V_386 . V_274 ? V_401 : 0 ) +
( V_108 . V_275 != V_386 . V_275 ? V_402 : 0 ) ) ;
if ( V_387 )
break;
V_386 = V_108 ;
V_390 = V_391 ;
}
F_166 ( & V_1 -> V_276 , & V_392 ) ;
F_163 ( V_406 ) ;
if ( V_388 & ( V_401 + V_402 ) ) {
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( ! F_167 ( & V_1 -> V_276 ) ) {
V_1 -> V_260 &= ~ ( V_261 | V_262 ) ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
}
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
exit:
if ( V_182 == 0 )
F_168 ( V_182 , V_387 , V_384 ) ;
return V_182 ;
}
static int F_60 ( T_1 * V_1 , int V_88 )
{
unsigned long V_11 ;
int V_182 ;
struct V_107 V_386 , V_108 ;
F_162 ( V_392 , V_83 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_386 = V_1 -> V_106 ;
F_164 ( & V_1 -> V_327 , & V_392 ) ;
F_163 ( V_405 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
for(; ; ) {
F_165 () ;
if ( F_42 ( V_83 ) ) {
V_182 = - V_37 ;
break;
}
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_108 = V_1 -> V_106 ;
F_163 ( V_405 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
if ( V_108 . V_111 == V_386 . V_111 && V_108 . V_110 == V_386 . V_110 &&
V_108 . V_112 == V_386 . V_112 && V_108 . V_109 == V_386 . V_109 ) {
V_182 = - V_69 ;
break;
}
if ( ( V_88 & V_407 && V_108 . V_111 != V_386 . V_111 ) ||
( V_88 & V_408 && V_108 . V_110 != V_386 . V_110 ) ||
( V_88 & V_409 && V_108 . V_112 != V_386 . V_112 ) ||
( V_88 & V_410 && V_108 . V_109 != V_386 . V_109 ) ) {
V_182 = 0 ;
break;
}
V_386 = V_108 ;
}
F_166 ( & V_1 -> V_327 , & V_392 ) ;
F_163 ( V_406 ) ;
return V_182 ;
}
static int F_169 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned int V_411 ;
unsigned long V_11 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_64 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
V_411 = ( ( V_1 -> V_55 & V_56 ) ? V_412 : 0 ) |
( ( V_1 -> V_55 & V_57 ) ? V_413 : 0 ) |
( ( V_1 -> V_55 & V_130 ) ? V_414 : 0 ) |
( ( V_1 -> V_55 & V_131 ) ? V_407 : 0 ) |
( ( V_1 -> V_55 & V_129 ) ? V_408 : 0 ) |
( ( V_1 -> V_55 & V_128 ) ? V_410 : 0 ) ;
if ( V_31 >= V_32 )
F_4 ( L_124 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_411 ) ;
return V_411 ;
}
static int F_170 ( struct V_8 * V_9 ,
unsigned int V_415 , unsigned int V_416 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_125 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_415 , V_416 ) ;
if ( V_415 & V_412 )
V_1 -> V_55 |= V_56 ;
if ( V_415 & V_413 )
V_1 -> V_55 |= V_57 ;
if ( V_416 & V_412 )
V_1 -> V_55 &= ~ V_56 ;
if ( V_416 & V_413 )
V_1 -> V_55 &= ~ V_57 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_30 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
return 0 ;
}
static int F_171 ( struct V_417 * V_27 )
{
T_1 * V_1 = F_113 ( V_27 , T_1 , V_27 ) ;
unsigned long V_11 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_64 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
return ( V_1 -> V_55 & V_130 ) ? 1 : 0 ;
}
static void F_172 ( struct V_417 * V_27 , int V_418 )
{
T_1 * V_1 = F_113 ( V_27 , T_1 , V_27 ) ;
unsigned long V_11 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( V_418 )
V_1 -> V_55 |= V_56 | V_57 ;
else
V_1 -> V_55 &= ~ ( V_56 | V_57 ) ;
F_30 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
static int F_16 ( struct V_8 * V_9 , struct V_28 * V_29 ,
T_1 * V_1 )
{
F_162 ( V_392 , V_83 ) ;
int V_30 ;
bool V_419 = false ;
bool V_420 = false ;
unsigned long V_11 ;
int V_421 ;
struct V_417 * V_27 = & V_1 -> V_27 ;
if ( V_31 >= V_32 )
F_4 ( L_126 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 ) ;
if ( V_29 -> V_422 & V_423 || V_9 -> V_11 & ( 1 << V_93 ) ) {
V_27 -> V_11 |= V_48 ;
return 0 ;
}
if ( V_9 -> V_54 . V_52 & V_374 )
V_419 = true ;
V_30 = 0 ;
F_164 ( & V_27 -> V_49 , & V_392 ) ;
if ( V_31 >= V_32 )
F_4 ( L_127 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
if ( ! F_11 ( V_29 ) ) {
V_420 = true ;
V_27 -> V_12 -- ;
}
F_14 ( & V_1 -> V_47 , V_11 ) ;
V_27 -> V_424 ++ ;
while ( 1 ) {
if ( F_173 ( V_9 ) && F_31 ( V_80 , & V_27 -> V_11 ) )
F_174 ( V_27 ) ;
F_163 ( V_405 ) ;
if ( F_11 ( V_29 ) || ! ( V_27 -> V_11 & V_45 ) ) {
V_30 = ( V_27 -> V_11 & V_35 ) ?
- V_36 : - V_37 ;
break;
}
V_421 = F_175 ( V_27 ) ;
if ( ! ( V_27 -> V_11 & V_33 ) && ( V_419 || V_421 ) )
break;
if ( F_42 ( V_83 ) ) {
V_30 = - V_37 ;
break;
}
if ( V_31 >= V_32 )
F_4 ( L_128 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
F_176 ( V_9 ) ;
F_165 () ;
F_177 ( V_9 ) ;
}
F_163 ( V_406 ) ;
F_166 ( & V_27 -> V_49 , & V_392 ) ;
if ( V_420 )
V_27 -> V_12 ++ ;
V_27 -> V_424 -- ;
if ( V_31 >= V_32 )
F_4 ( L_129 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
if ( ! V_30 )
V_27 -> V_11 |= V_48 ;
return V_30 ;
}
static int F_178 ( T_1 * V_1 )
{
unsigned short V_425 ;
unsigned short V_426 ;
V_1 -> V_345 [ 0 ] -> V_427 = ( V_428 / 4 ) * V_1 -> V_251 ;
V_425 = ( unsigned short ) ( V_1 -> V_68 / V_429 ) ;
if ( V_1 -> V_68 % V_429 )
V_425 ++ ;
V_426 = ( V_428 / 4 - V_430 ) / V_429 ;
if ( V_426 > V_430 / sizeof( V_431 ) )
V_426 = V_430 / sizeof( V_431 ) ;
V_1 -> V_432 = V_425 + 1 ;
if ( V_1 -> V_432 > ( V_426 / 2 ) )
V_1 -> V_432 = V_426 / 2 ;
if ( V_1 -> V_432 > V_433 )
V_1 -> V_432 = V_433 ;
V_1 -> V_434 = V_426 - V_1 -> V_432 ;
if ( V_1 -> V_434 > V_433 )
V_1 -> V_434 = V_433 ;
if ( V_31 >= V_32 )
F_4 ( L_130 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_1 -> V_432 , V_1 -> V_434 ) ;
if ( F_179 ( V_1 ) < 0 ||
F_180 ( V_1 ,
V_1 -> V_435 ,
V_1 -> V_436 ,
V_1 -> V_434 ) < 0 ||
F_180 ( V_1 ,
V_1 -> V_437 ,
V_1 -> V_438 ,
V_1 -> V_432 ) < 0 ||
F_181 ( V_1 ) < 0 ) {
F_4 ( L_131 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_226 ;
}
F_182 ( V_1 ) ;
return 0 ;
}
static int F_179 ( T_1 * V_1 )
{
unsigned int V_339 ;
V_1 -> V_439 = V_1 -> V_440 + V_1 -> V_345 [ 0 ] -> V_427 ;
V_1 -> V_441 = V_1 -> V_345 [ 0 ] -> V_427 ;
V_1 -> V_345 [ 0 ] -> V_427 += V_430 ;
memset ( V_1 -> V_439 , 0 , V_430 ) ;
V_1 -> V_435 = ( V_431 * ) V_1 -> V_439 ;
V_1 -> V_437 = ( V_431 * ) V_1 -> V_439 ;
V_1 -> V_437 += V_1 -> V_434 ;
for ( V_339 = 0 ; V_339 < V_1 -> V_434 ; V_339 ++ ) {
V_1 -> V_436 [ V_339 ] . V_442 =
V_1 -> V_441 + ( V_339 * V_429 ) ;
V_1 -> V_435 [ V_339 ] . V_443 = V_1 -> V_441 ;
if ( V_339 < V_1 -> V_434 - 1 )
V_1 -> V_435 [ V_339 ] . V_443 += ( V_339 + 1 ) * sizeof( V_431 ) ;
V_1 -> V_435 [ V_339 ] . V_444 = V_429 ;
}
for ( V_339 = 0 ; V_339 < V_1 -> V_432 ; V_339 ++ ) {
V_1 -> V_438 [ V_339 ] . V_442 = V_1 -> V_441 +
( ( V_1 -> V_434 + V_339 ) * sizeof( V_431 ) ) ;
V_1 -> V_437 [ V_339 ] . V_443 = V_1 -> V_441 +
V_1 -> V_434 * sizeof( V_431 ) ;
if ( V_339 < V_1 -> V_432 - 1 )
V_1 -> V_437 [ V_339 ] . V_443 += ( V_339 + 1 ) * sizeof( V_431 ) ;
}
return 0 ;
}
static int F_180 ( T_1 * V_1 , V_431 * V_445 , T_10 * V_446 , int V_12 )
{
int V_339 ;
unsigned long V_447 ;
for ( V_339 = 0 ; V_339 < V_12 ; V_339 ++ ) {
V_446 [ V_339 ] . V_448 = V_1 -> V_440 + V_1 -> V_345 [ 0 ] -> V_427 ;
V_447 = V_1 -> V_345 [ 0 ] -> V_427 ;
V_1 -> V_345 [ 0 ] -> V_427 += V_429 ;
V_445 [ V_339 ] . V_449 = ( unsigned short ) V_447 ;
V_445 [ V_339 ] . V_450 = ( unsigned char ) ( V_447 >> 16 ) ;
}
return 0 ;
}
static void F_183 ( T_1 * V_1 )
{
V_1 -> V_439 = NULL ;
V_1 -> V_435 = NULL ;
V_1 -> V_437 = NULL ;
}
static int F_181 ( T_1 * V_1 )
{
V_1 -> V_451 = F_141 ( V_1 -> V_68 , V_353 ) ;
if ( V_1 -> V_451 == NULL )
return - V_226 ;
V_1 -> V_452 = F_184 ( V_1 -> V_68 , V_353 ) ;
if ( ! V_1 -> V_452 ) {
F_146 ( V_1 -> V_451 ) ;
V_1 -> V_451 = NULL ;
return - V_226 ;
}
return 0 ;
}
static void F_185 ( T_1 * V_1 )
{
F_146 ( V_1 -> V_451 ) ;
V_1 -> V_451 = NULL ;
F_146 ( V_1 -> V_452 ) ;
V_1 -> V_452 = NULL ;
}
static int F_186 ( T_1 * V_1 )
{
if ( F_187 ( V_1 -> V_124 , V_428 , L_132 ) == NULL ) {
F_4 ( L_133 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_124 ) ;
V_1 -> V_24 = V_453 ;
goto V_454;
}
else
V_1 -> V_455 = true ;
if ( F_187 ( V_1 -> V_126 + V_1 -> V_456 , 128 , L_132 ) == NULL ) {
F_4 ( L_134 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_126 ) ;
V_1 -> V_24 = V_453 ;
goto V_454;
}
else
V_1 -> V_457 = true ;
if ( F_187 ( V_1 -> V_123 + V_1 -> V_458 , V_229 , L_132 ) == NULL ) {
F_4 ( L_135 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_123 ) ;
V_1 -> V_24 = V_453 ;
goto V_454;
}
else
V_1 -> V_459 = true ;
if ( F_187 ( V_1 -> V_125 + V_1 -> V_460 , V_461 , L_132 ) == NULL ) {
F_4 ( L_136 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_125 ) ;
V_1 -> V_24 = V_453 ;
goto V_454;
}
else
V_1 -> V_462 = true ;
V_1 -> V_440 = F_188 ( V_1 -> V_124 ,
V_428 ) ;
if ( ! V_1 -> V_440 ) {
F_4 ( L_137 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_124 ) ;
V_1 -> V_24 = V_463 ;
goto V_454;
}
V_1 -> V_464 = F_188 ( V_1 -> V_126 , V_465 ) ;
if ( ! V_1 -> V_464 ) {
F_4 ( L_138 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_126 ) ;
V_1 -> V_24 = V_463 ;
goto V_454;
}
V_1 -> V_464 += V_1 -> V_456 ;
V_1 -> V_466 = F_188 ( V_1 -> V_123 , V_465 ) ;
if ( ! V_1 -> V_466 ) {
F_4 ( L_139 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_123 ) ;
V_1 -> V_24 = V_463 ;
goto V_454;
}
V_1 -> V_466 += V_1 -> V_458 ;
V_1 -> V_467 = F_188 ( V_1 -> V_125 ,
V_465 ) ;
if ( ! V_1 -> V_467 ) {
F_4 ( L_140 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_125 ) ;
V_1 -> V_24 = V_463 ;
goto V_454;
}
V_1 -> V_467 += V_1 -> V_460 ;
if ( ! F_189 ( V_1 ) ) {
F_4 ( L_141 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_124 ) ;
V_1 -> V_24 = V_468 ;
goto V_454;
}
return 0 ;
V_454:
F_190 ( V_1 ) ;
return - V_21 ;
}
static void F_190 ( T_1 * V_1 )
{
if ( V_31 >= V_32 )
F_4 ( L_142 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_1 -> V_469 ) {
F_191 ( V_1 -> V_127 , V_1 ) ;
V_1 -> V_469 = false ;
}
if ( V_1 -> V_455 ) {
F_192 ( V_1 -> V_124 , V_428 ) ;
V_1 -> V_455 = false ;
}
if ( V_1 -> V_457 ) {
F_192 ( V_1 -> V_126 + V_1 -> V_456 , 128 ) ;
V_1 -> V_457 = false ;
}
if ( V_1 -> V_459 ) {
F_192 ( V_1 -> V_123 + V_1 -> V_458 , V_229 ) ;
V_1 -> V_459 = false ;
}
if ( V_1 -> V_462 ) {
F_192 ( V_1 -> V_125 + V_1 -> V_460 , V_461 ) ;
V_1 -> V_462 = false ;
}
if ( V_1 -> V_440 ) {
F_193 ( V_1 -> V_440 ) ;
V_1 -> V_440 = NULL ;
}
if ( V_1 -> V_466 ) {
F_193 ( V_1 -> V_466 - V_1 -> V_458 ) ;
V_1 -> V_466 = NULL ;
}
if ( V_1 -> V_467 ) {
F_193 ( V_1 -> V_467 - V_1 -> V_460 ) ;
V_1 -> V_467 = NULL ;
}
if ( V_1 -> V_464 ) {
F_193 ( V_1 -> V_464 - V_1 -> V_456 ) ;
V_1 -> V_464 = NULL ;
}
if ( V_31 >= V_32 )
F_4 ( L_143 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_194 ( T_1 * V_1 )
{
V_1 -> V_23 = NULL ;
V_1 -> line = V_20 ;
sprintf ( V_1 -> V_25 , L_144 , V_1 -> V_470 , V_1 -> V_251 ) ;
if ( V_1 -> line < V_471 ) {
if ( V_472 [ V_1 -> line ] )
V_1 -> V_68 = V_472 [ V_1 -> line ] ;
}
V_20 ++ ;
if ( ! V_22 )
V_22 = V_1 ;
else {
T_1 * V_473 = V_22 ;
while( V_473 -> V_23 )
V_473 = V_473 -> V_23 ;
V_473 -> V_23 = V_1 ;
}
if ( V_1 -> V_68 < 4096 )
V_1 -> V_68 = 4096 ;
else if ( V_1 -> V_68 > 65535 )
V_1 -> V_68 = 65535 ;
F_4 ( L_145
L_146 ,
V_1 -> V_25 ,
V_1 -> V_123 ,
V_1 -> V_124 ,
V_1 -> V_125 ,
V_1 -> V_126 ,
V_1 -> V_127 ,
V_1 -> V_68 ) ;
#if V_306
F_104 ( V_1 ) ;
#endif
}
static T_1 * F_195 ( int V_470 , int V_251 , struct V_474 * V_475 )
{
T_1 * V_1 ;
V_1 = F_184 ( sizeof( T_1 ) ,
V_353 ) ;
if ( ! V_1 ) {
F_4 ( L_147 ,
__FILE__ , __LINE__ , V_470 , V_251 ) ;
} else {
F_196 ( & V_1 -> V_27 ) ;
V_1 -> V_27 . V_15 = & V_476 ;
V_1 -> V_6 = V_7 ;
F_197 ( & V_1 -> V_243 , F_112 ) ;
V_1 -> V_68 = 4096 ;
V_1 -> V_27 . V_477 = 5 * V_234 / 10 ;
V_1 -> V_27 . V_478 = 30 * V_234 ;
F_198 ( & V_1 -> V_327 ) ;
F_198 ( & V_1 -> V_276 ) ;
F_199 ( & V_1 -> V_41 ) ;
memcpy ( & V_1 -> V_65 , & V_479 , sizeof( T_9 ) ) ;
V_1 -> V_380 = V_480 ;
V_1 -> V_470 = V_470 ;
V_1 -> V_251 = V_251 ;
V_1 -> V_127 = V_475 -> V_230 ;
V_1 -> V_126 = F_200 ( V_475 , 0 ) ;
V_1 -> V_123 = F_200 ( V_475 , 2 ) ;
V_1 -> V_124 = F_200 ( V_475 , 3 ) ;
V_1 -> V_125 = F_200 ( V_475 , 4 ) ;
V_1 -> V_456 = V_1 -> V_126 & ( V_465 - 1 ) ;
V_1 -> V_126 &= ~ ( V_465 - 1 ) ;
V_1 -> V_458 = V_1 -> V_123 & ( V_465 - 1 ) ;
V_1 -> V_123 &= ~ ( V_465 - 1 ) ;
V_1 -> V_460 = V_1 -> V_125 & ( V_465 - 1 ) ;
V_1 -> V_125 &= ~ ( V_465 - 1 ) ;
V_1 -> V_481 = V_482 ;
V_1 -> V_483 = V_484 ;
F_201 ( & V_1 -> V_86 , V_485 , ( unsigned long ) V_1 ) ;
F_201 ( & V_1 -> V_354 , V_486 ,
( unsigned long ) V_1 ) ;
V_1 -> V_487 = 0x087e4546 ;
V_1 -> V_24 = - 1 ;
}
return V_1 ;
}
static void F_202 ( int V_470 , struct V_474 * V_475 )
{
T_1 * V_345 [ V_488 ] ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_488 ; ++ V_27 ) {
V_345 [ V_27 ] = F_195 ( V_470 , V_27 , V_475 ) ;
if( V_345 [ V_27 ] == NULL ) {
for ( -- V_27 ; V_27 >= 0 ; -- V_27 ) {
F_203 ( & V_345 [ V_27 ] -> V_27 ) ;
F_146 ( V_345 [ V_27 ] ) ;
}
return;
}
}
for ( V_27 = 0 ; V_27 < V_488 ; ++ V_27 ) {
memcpy ( V_345 [ V_27 ] -> V_345 , V_345 , sizeof( V_345 ) ) ;
F_194 ( V_345 [ V_27 ] ) ;
F_199 ( & V_345 [ V_27 ] -> V_47 ) ;
}
if ( ! F_186 ( V_345 [ 0 ] ) ) {
F_178 ( V_345 [ 0 ] ) ;
for ( V_27 = 1 ; V_27 < V_488 ; ++ V_27 ) {
V_345 [ V_27 ] -> V_47 = V_345 [ 0 ] -> V_47 ;
V_345 [ V_27 ] -> V_127 = V_345 [ 0 ] -> V_127 ;
V_345 [ V_27 ] -> V_440 = V_345 [ 0 ] -> V_440 ;
V_345 [ V_27 ] -> V_466 = V_345 [ 0 ] -> V_466 ;
V_345 [ V_27 ] -> V_467 = V_345 [ 0 ] -> V_467 ;
V_345 [ V_27 ] -> V_464 = V_345 [ 0 ] -> V_464 ;
F_178 ( V_345 [ V_27 ] ) ;
}
if ( F_204 ( V_345 [ 0 ] -> V_127 ,
F_136 ,
V_345 [ 0 ] -> V_483 ,
V_345 [ 0 ] -> V_25 ,
V_345 [ 0 ] ) < 0 ) {
F_4 ( L_148 ,
__FILE__ , __LINE__ ,
V_345 [ 0 ] -> V_25 ,
V_345 [ 0 ] -> V_127 ) ;
}
else {
V_345 [ 0 ] -> V_469 = true ;
F_205 ( V_345 [ 0 ] ) ;
}
}
}
static void F_206 ( void )
{
int V_182 ;
T_1 * V_1 ;
T_1 * V_340 ;
F_4 ( L_149 , V_489 , V_144 ) ;
if ( V_490 ) {
if ( ( V_182 = F_207 ( V_490 ) ) )
F_4 ( L_150 ,
__FILE__ , __LINE__ , V_182 ) ;
F_208 ( V_490 ) ;
}
V_1 = V_22 ;
while( V_1 ) {
F_142 ( V_1 ) ;
V_1 = V_1 -> V_23 ;
}
V_1 = V_22 ;
while( V_1 ) {
#if V_306
F_109 ( V_1 ) ;
#endif
F_183 ( V_1 ) ;
F_185 ( V_1 ) ;
if ( V_1 -> V_251 == 0 ) {
if ( V_1 -> V_466 )
F_76 ( V_1 , V_491 , 1 ) ;
F_190 ( V_1 ) ;
}
V_340 = V_1 ;
V_1 = V_1 -> V_23 ;
F_203 ( & V_340 -> V_27 ) ;
F_146 ( V_340 ) ;
}
F_209 ( & V_492 ) ;
}
static int T_11 F_210 ( void )
{
int V_182 ;
if ( V_493 ) {
F_1 () ;
F_211 () ;
}
F_4 ( L_151 , V_489 , V_144 ) ;
if ( ( V_182 = F_212 ( & V_492 ) ) < 0 ) {
F_4 ( L_152 , __FILE__ , V_182 ) ;
return V_182 ;
}
V_490 = F_213 ( 128 ) ;
if ( ! V_490 ) {
V_182 = - V_226 ;
goto error;
}
V_490 -> V_489 = L_132 ;
V_490 -> V_2 = L_153 ;
V_490 -> V_494 = V_495 ;
V_490 -> V_496 = 64 ;
V_490 -> type = V_497 ;
V_490 -> V_498 = V_499 ;
V_490 -> V_500 = V_501 ;
V_490 -> V_500 . V_52 =
V_502 | V_364 | V_356 | V_355 | V_374 ;
V_490 -> V_500 . V_503 = 9600 ;
V_490 -> V_500 . V_504 = 9600 ;
V_490 -> V_11 = V_505 ;
F_214 ( V_490 , & V_15 ) ;
if ( ( V_182 = F_215 ( V_490 ) ) < 0 ) {
F_4 ( L_154 ,
__FILE__ , __LINE__ ) ;
F_208 ( V_490 ) ;
V_490 = NULL ;
goto error;
}
F_4 ( L_155 ,
V_489 , V_144 ,
V_490 -> V_494 ) ;
return 0 ;
error:
F_206 () ;
return V_182 ;
}
static void T_12 F_216 ( void )
{
F_206 () ;
}
static void F_217 ( T_1 * V_1 , int V_381 )
{
if ( V_381 ) {
F_76 ( V_1 , V_506 , ( unsigned char ) ( F_75 ( V_1 , V_506 ) | ( V_346 + V_280 ) ) ) ;
V_1 -> V_345 [ 0 ] -> V_507 |= ( V_280 << ( V_1 -> V_251 * 2 ) ) ;
F_218 ( V_1 ) ;
F_76 ( V_1 , V_508 , 0x40 ) ;
F_76 ( V_1 , V_509 , 0x40 ) ;
} else {
F_76 ( V_1 , V_506 , ( unsigned char ) ( F_75 ( V_1 , V_506 ) & ~ ( V_346 + V_280 ) ) ) ;
F_76 ( V_1 , V_508 , 0x00 ) ;
F_76 ( V_1 , V_509 , 0x00 ) ;
}
if ( V_1 -> V_65 . V_211 )
F_219 ( V_1 , V_1 -> V_65 . V_211 ) ;
else
F_219 ( V_1 , 3686400 ) ;
}
static void F_219 ( T_1 * V_1 , T_13 V_82 )
{
T_13 V_510 ;
unsigned char V_511 ;
T_13 V_512 = 0 ;
if ( V_82 != 0 ) {
V_512 = 14745600 / V_82 ;
if ( ! V_512 )
V_512 = 1 ;
V_510 = V_512 ;
V_511 = 0 ;
if ( V_510 != 1 && V_510 != 2 ) {
V_511 = 1 ;
V_510 >>= 1 ;
}
for(; V_510 > 256 && V_511 < 10 ; V_511 ++ )
V_510 >>= 1 ;
F_76 ( V_1 , V_509 ,
( unsigned char ) ( ( F_75 ( V_1 , V_509 ) & 0xf0 ) | V_511 ) ) ;
F_76 ( V_1 , V_508 ,
( unsigned char ) ( ( F_75 ( V_1 , V_508 ) & 0xf0 ) | V_511 ) ) ;
F_76 ( V_1 , V_513 , ( unsigned char ) V_510 ) ;
}
else {
F_76 ( V_1 , V_509 , 0 ) ;
F_76 ( V_1 , V_508 , 0 ) ;
F_76 ( V_1 , V_513 , 0 ) ;
}
}
static void F_148 ( T_1 * V_1 )
{
if ( V_31 >= V_257 )
F_4 ( L_156 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_76 ( V_1 , V_297 , V_514 ) ;
V_1 -> V_301 &= ~ V_515 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
F_76 ( V_1 , V_310 + V_293 , 0 ) ;
F_76 ( V_1 , V_310 + V_294 , V_295 ) ;
F_76 ( V_1 , V_310 + V_292 , 0 ) ;
V_1 -> V_383 = false ;
V_1 -> V_311 = false ;
}
static void F_151 ( T_1 * V_1 )
{
int V_339 ;
if ( V_31 >= V_257 )
F_4 ( L_157 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_76 ( V_1 , V_297 , V_514 ) ;
if ( V_1 -> V_65 . V_66 == V_67 ) {
V_1 -> V_301 &= ~ V_515 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
F_76 ( V_1 , V_310 + V_293 , 0 ) ;
F_76 ( V_1 , V_310 + V_294 , V_295 ) ;
for ( V_339 = 0 ; V_339 < V_1 -> V_434 ; V_339 ++ ) {
V_1 -> V_435 [ V_339 ] . V_258 = 0xff ;
if ( ! ( V_339 % 4 ) )
F_220 ( V_1 ) ;
}
V_1 -> V_516 = 0 ;
F_126 ( V_1 , V_310 + V_517 ,
V_1 -> V_436 [ 0 ] . V_442 ) ;
F_126 ( V_1 , V_310 + V_518 ,
V_1 -> V_436 [ V_1 -> V_434 - 1 ] . V_442 ) ;
F_126 ( V_1 , V_310 + V_519 , V_429 ) ;
F_76 ( V_1 , V_310 + V_292 , 0x60 ) ;
F_76 ( V_1 , V_310 + V_293 , 0xf2 ) ;
} else {
V_1 -> V_301 |= V_515 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
}
F_76 ( V_1 , V_297 , V_520 ) ;
V_1 -> V_311 = false ;
V_1 -> V_383 = true ;
}
static void F_37 ( T_1 * V_1 )
{
if ( V_31 >= V_257 )
F_4 ( L_158 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_71 ) ;
if ( ! V_1 -> V_77 ) {
F_76 ( V_1 , V_297 , V_298 ) ;
F_76 ( V_1 , V_297 , V_299 ) ;
V_1 -> V_77 = true ;
}
if ( V_1 -> V_71 ) {
V_1 -> V_305 = false ;
if ( V_1 -> V_65 . V_66 != V_269 ) {
if ( V_1 -> V_65 . V_11 & V_521 ) {
F_64 ( V_1 ) ;
if ( ! ( V_1 -> V_55 & V_56 ) ) {
V_1 -> V_55 |= V_56 ;
F_30 ( V_1 ) ;
V_1 -> V_305 = true ;
}
}
F_126 ( V_1 , V_313 ,
( unsigned short ) ( ( ( V_522 - 1 ) << 8 ) + V_523 ) ) ;
F_76 ( V_1 , V_291 + V_293 , 0 ) ;
F_76 ( V_1 , V_291 + V_294 , V_295 ) ;
F_126 ( V_1 , V_291 + V_517 ,
V_1 -> V_438 [ 0 ] . V_442 ) ;
F_126 ( V_1 , V_291 + V_518 ,
V_1 -> V_438 [ V_1 -> V_524 ] . V_442 ) ;
V_1 -> V_260 &= ~ V_303 ;
V_1 -> V_260 |= V_296 ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
F_76 ( V_1 , V_259 , ( unsigned char ) ( V_303 + V_296 ) ) ;
F_76 ( V_1 , V_291 + V_292 , 0x40 ) ;
F_76 ( V_1 , V_291 + V_293 , 0xf2 ) ;
F_143 ( & V_1 -> V_86 , V_81 +
F_144 ( 5000 ) ) ;
}
else {
F_129 ( V_1 ) ;
V_1 -> V_301 |= V_302 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
}
V_1 -> V_70 = true ;
}
}
static void F_49 ( T_1 * V_1 )
{
if ( V_31 >= V_257 )
F_4 ( L_159 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_46 ( & V_1 -> V_86 ) ;
F_76 ( V_1 , V_291 + V_293 , 0 ) ;
F_76 ( V_1 , V_291 + V_294 , V_295 ) ;
F_76 ( V_1 , V_297 , V_298 ) ;
V_1 -> V_260 &= ~ ( V_296 + V_303 ) ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
F_76 ( V_1 , V_259 , ( unsigned char ) ( V_303 + V_296 ) ) ;
V_1 -> V_301 &= ~ V_302 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
V_1 -> V_77 = false ;
V_1 -> V_70 = false ;
}
static void F_129 ( T_1 * V_1 )
{
T_14 V_525 [ 2 ] ;
if ( ! V_1 -> V_71 && ! V_1 -> V_76 )
return;
while( V_1 -> V_71 && ( F_75 ( V_1 , V_526 ) & V_346 ) ) {
if ( ( V_1 -> V_71 > 1 ) && ! V_1 -> V_76 ) {
V_525 [ 0 ] = V_1 -> V_64 [ V_1 -> V_85 ++ ] ;
if ( V_1 -> V_85 >= V_1 -> V_68 )
V_1 -> V_85 -= V_1 -> V_68 ;
V_525 [ 1 ] = V_1 -> V_64 [ V_1 -> V_85 ++ ] ;
if ( V_1 -> V_85 >= V_1 -> V_68 )
V_1 -> V_85 -= V_1 -> V_68 ;
F_126 ( V_1 , V_283 , * ( ( T_7 * ) V_525 ) ) ;
V_1 -> V_71 -= 2 ;
V_1 -> V_106 . V_114 += 2 ;
} else {
if ( V_1 -> V_76 ) {
F_76 ( V_1 , V_283 , V_1 -> V_76 ) ;
V_1 -> V_76 = 0 ;
} else {
F_76 ( V_1 , V_283 , V_1 -> V_64 [ V_1 -> V_85 ++ ] ) ;
if ( V_1 -> V_85 >= V_1 -> V_68 )
V_1 -> V_85 -= V_1 -> V_68 ;
V_1 -> V_71 -- ;
}
V_1 -> V_106 . V_114 ++ ;
}
}
}
static void F_142 ( T_1 * V_1 )
{
if ( V_1 -> V_466 ) {
F_49 ( V_1 ) ;
F_148 ( V_1 ) ;
V_1 -> V_55 &= ~ ( V_56 | V_57 ) ;
F_30 ( V_1 ) ;
V_1 -> V_301 = 0 ;
V_1 -> V_260 = 0 ;
V_1 -> V_267 = 0 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
F_76 ( V_1 , V_527 , V_1 -> V_267 ) ;
F_76 ( V_1 , V_297 , V_528 ) ;
}
}
static void F_221 ( T_1 * V_1 )
{
int V_339 ;
for ( V_339 = 0 ; V_339 < V_488 ; ++ V_339 ) {
if ( V_1 -> V_345 [ V_339 ] )
F_142 ( V_1 -> V_345 [ V_339 ] ) ;
}
}
static void F_150 ( T_1 * V_1 )
{
unsigned char V_147 ;
F_49 ( V_1 ) ;
F_148 ( V_1 ) ;
V_147 = 0x00 ;
if ( V_1 -> V_65 . V_366 != 1 )
V_147 |= V_346 ;
F_76 ( V_1 , V_529 , V_147 ) ;
V_147 = 0x40 ;
switch ( V_1 -> V_65 . V_361 ) {
case 7 : V_147 |= V_349 + V_347 ; break;
case 6 : V_147 |= V_348 + V_150 ; break;
case 5 : V_147 |= V_348 + V_349 + V_150 + V_347 ; break;
}
if ( V_1 -> V_65 . V_117 != V_367 ) {
V_147 |= V_346 ;
if ( V_1 -> V_65 . V_117 == V_370 )
V_147 |= V_280 ;
}
F_76 ( V_1 , V_530 , V_147 ) ;
V_147 = 0x00 ;
if ( V_1 -> V_65 . V_212 )
V_147 |= ( V_346 + V_280 ) ;
F_76 ( V_1 , V_506 , V_147 ) ;
V_147 = V_351 ;
F_76 ( V_1 , V_508 , V_147 ) ;
V_147 = V_351 ;
F_76 ( V_1 , V_509 , V_147 ) ;
V_1 -> V_345 [ 0 ] -> V_507 |= ( V_280 << ( V_1 -> V_251 * 2 ) ) ;
F_218 ( V_1 ) ;
F_161 ( V_1 ) ;
F_76 ( V_1 , V_531 , 0x00 ) ;
F_76 ( V_1 , V_313 , 0x10 ) ;
F_76 ( V_1 , V_532 , 0x1e ) ;
V_147 = 0x10 ;
if ( ! ( V_1 -> V_55 & V_56 ) )
V_147 |= 0x01 ;
F_76 ( V_1 , V_149 , V_147 ) ;
V_1 -> V_301 |= V_533 + V_534 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
V_1 -> V_260 = V_264 ;
F_76 ( V_1 , V_322 , V_1 -> V_260 ) ;
V_1 -> V_267 = V_268 ;
F_76 ( V_1 , V_527 , V_1 -> V_267 ) ;
F_219 ( V_1 , V_1 -> V_65 . V_82 * 16 ) ;
}
static void F_149 ( T_1 * V_1 )
{
unsigned char V_147 ;
T_13 V_535 ;
V_1 -> V_65 . V_11 &= ~ ( V_201 + V_197 ) ;
F_76 ( V_1 , V_291 + V_292 , 0 ) ;
F_76 ( V_1 , V_310 + V_292 , 0 ) ;
V_147 = 0x81 ;
if ( V_1 -> V_65 . V_11 & V_536 )
V_147 |= V_349 ;
if ( V_1 -> V_65 . V_11 & V_537 )
V_147 |= V_349 ;
if ( V_1 -> V_65 . V_172 == V_169 )
V_147 |= V_347 + V_346 ;
F_76 ( V_1 , V_529 , V_147 ) ;
V_147 = 0x00 ;
F_76 ( V_1 , V_530 , V_147 ) ;
V_147 = 0x00 ;
switch( V_1 -> V_65 . V_153 ) {
case V_538 : V_147 |= V_348 ; break;
case V_161 : V_147 |= V_350 + V_348 ; break;
case V_163 : V_147 |= V_350 + V_351 ; break;
case V_165 : V_147 |= V_350 ; break;
#if 0
case HDLC_ENCODING_NRZB:
case HDLC_ENCODING_NRZI_MARK:
case HDLC_ENCODING_DIFF_BIPHASE_LEVEL:
#endif
}
if ( V_1 -> V_65 . V_11 & V_539 ) {
V_535 = 16 ;
V_147 |= V_150 ;
} else if ( V_1 -> V_65 . V_11 & V_540 ) {
V_535 = 8 ;
} else {
V_535 = 32 ;
V_147 |= V_349 ;
}
F_76 ( V_1 , V_506 , V_147 ) ;
V_147 = 0 ;
if ( V_1 -> V_65 . V_11 & V_198 )
V_147 |= V_351 ;
if ( V_1 -> V_65 . V_11 & V_197 )
V_147 |= V_351 + V_348 ;
F_76 ( V_1 , V_508 , V_147 ) ;
V_147 = 0 ;
if ( V_1 -> V_65 . V_11 & V_202 )
V_147 |= V_351 ;
if ( V_1 -> V_65 . V_11 & V_201 )
V_147 |= V_351 + V_348 ;
F_76 ( V_1 , V_509 , V_147 ) ;
if ( V_1 -> V_65 . V_11 & V_197 )
F_219 ( V_1 , V_1 -> V_65 . V_211 * V_535 ) ;
else
F_219 ( V_1 , V_1 -> V_65 . V_211 ) ;
if ( V_1 -> V_65 . V_11 & V_202 )
V_1 -> V_345 [ 0 ] -> V_507 |= ( V_280 << ( V_1 -> V_251 * 2 ) ) ;
else
V_1 -> V_345 [ 0 ] -> V_507 &= ~ ( V_280 << ( V_1 -> V_251 * 2 ) ) ;
F_218 ( V_1 ) ;
F_76 ( V_1 , V_531 , V_541 ) ;
F_76 ( V_1 , V_313 , V_523 ) ;
F_76 ( V_1 , V_532 , ( unsigned char ) ( V_522 - 1 ) ) ;
F_76 ( V_1 , V_291 + V_542 , 0x14 ) ;
F_76 ( V_1 , V_310 + V_542 , 0x14 ) ;
F_76 ( V_1 , V_310 + V_543 ,
( unsigned char ) ( V_1 -> V_441 >> 16 ) ) ;
F_76 ( V_1 , V_291 + V_543 ,
( unsigned char ) ( V_1 -> V_441 >> 16 ) ) ;
V_1 -> V_301 |= V_533 + V_534 ;
F_76 ( V_1 , V_304 , V_1 -> V_301 ) ;
V_147 = 0x10 ;
if ( ! ( V_1 -> V_55 & V_56 ) )
V_147 |= 0x01 ;
F_76 ( V_1 , V_149 , V_147 ) ;
F_161 ( V_1 ) ;
F_49 ( V_1 ) ;
F_148 ( V_1 ) ;
F_219 ( V_1 , V_1 -> V_65 . V_211 ) ;
if ( V_1 -> V_65 . V_212 )
F_217 ( V_1 , 1 ) ;
}
static void F_161 ( T_1 * V_1 )
{
unsigned char V_147 = 0xff ;
switch( V_1 -> V_380 ) {
case V_480 : V_147 = 0x7e ; break;
case V_544 : V_147 = 0xaa ; break;
case V_545 : V_147 = 0x00 ; break;
case V_546 : V_147 = 0xff ; break;
case V_547 : V_147 = 0xaa ; break;
case V_548 : V_147 = 0x00 ; break;
case V_549 : V_147 = 0xff ; break;
}
F_76 ( V_1 , V_550 , V_147 ) ;
}
static void F_64 ( T_1 * V_1 )
{
T_7 V_258 = F_75 ( V_1 , V_551 ) ;
T_7 V_552 = F_220 ( V_1 ) ;
T_7 V_553 ;
V_1 -> V_55 &= V_56 | V_57 ;
if ( ! ( V_258 & V_150 ) )
V_1 -> V_55 |= V_128 ;
if ( ! ( V_258 & V_347 ) )
V_1 -> V_55 |= V_130 ;
V_553 = V_346 << ( V_1 -> V_251 * 2 ) ;
if ( ! ( V_552 & V_553 ) )
V_1 -> V_55 |= V_131 ;
V_553 = V_280 << ( V_1 -> V_251 * 2 ) ;
if ( ! ( V_552 & V_553 ) )
V_1 -> V_55 |= V_129 ;
}
static void F_30 ( T_1 * V_1 )
{
unsigned char V_147 ;
T_7 V_554 ;
V_147 = F_75 ( V_1 , V_149 ) ;
if ( V_1 -> V_55 & V_56 )
V_147 &= ~ V_280 ;
else
V_147 |= V_280 ;
F_76 ( V_1 , V_149 , V_147 ) ;
V_554 = V_346 << ( V_1 -> V_251 * 2 ) ;
if ( V_1 -> V_55 & V_57 )
V_1 -> V_345 [ 0 ] -> V_507 &= ~ V_554 ;
else
V_1 -> V_345 [ 0 ] -> V_507 |= V_554 ;
F_218 ( V_1 ) ;
}
static void F_182 ( T_1 * V_1 )
{
F_222 ( V_1 , 0 , V_1 -> V_434 - 1 ) ;
}
static void F_222 ( T_1 * V_1 , unsigned int V_555 , unsigned int V_556 )
{
bool V_557 = false ;
while( ! V_557 ) {
V_1 -> V_435 [ V_555 ] . V_258 = 0xff ;
if ( V_555 == V_556 ) {
V_557 = true ;
F_126 ( V_1 , V_310 + V_518 , V_1 -> V_436 [ V_555 ] . V_442 ) ;
}
V_555 ++ ;
if ( V_555 == V_1 -> V_434 )
V_555 = 0 ;
}
V_1 -> V_516 = V_555 ;
}
static bool F_117 ( T_1 * V_1 )
{
unsigned int V_558 , V_559 ;
unsigned short V_258 ;
unsigned int V_560 = 0 ;
bool V_561 = false ;
unsigned long V_11 ;
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
unsigned char V_562 = 0xff ;
V_431 * V_563 ;
T_10 * V_564 ;
V_565:
V_560 = 0 ;
V_562 = 0xff ;
V_558 = V_559 = V_1 -> V_516 ;
for ( ; ; ) {
V_563 = & V_1 -> V_435 [ V_559 ] ;
V_564 = & V_1 -> V_436 [ V_559 ] ;
if ( V_563 -> V_258 == 0xff )
goto V_566;
if ( V_560 == 0 && V_1 -> V_65 . V_567 != 0xff )
V_562 = V_564 -> V_448 [ 0 ] ;
V_560 += V_563 -> V_444 ;
if ( V_563 -> V_258 )
break;
V_559 ++ ;
if ( V_559 == V_1 -> V_434 )
V_559 = 0 ;
if ( V_559 == V_1 -> V_516 ) {
if ( V_1 -> V_383 ) {
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_151 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
goto V_566;
}
}
V_258 = V_563 -> V_258 ;
if ( V_1 -> V_65 . V_172 == V_167 )
V_258 &= ~ V_347 ;
if ( V_560 == 0 ||
( V_562 != 0xff && V_562 != V_1 -> V_65 . V_567 ) ) {
F_222 ( V_1 , V_558 , V_559 ) ;
goto V_565;
}
if ( V_560 < 2 )
V_258 |= V_351 ;
if ( V_258 & ( V_351 + V_348 + V_150 + V_347 ) ) {
if ( V_258 & V_351 )
V_1 -> V_106 . V_136 ++ ;
else if ( V_258 & V_348 )
V_1 -> V_106 . V_568 ++ ;
else if ( V_258 & V_150 )
V_1 -> V_106 . V_138 ++ ;
else
V_1 -> V_106 . V_139 ++ ;
V_560 = 0 ;
#if V_306
{
V_1 -> V_218 -> V_177 . V_569 ++ ;
V_1 -> V_218 -> V_177 . V_570 ++ ;
}
#endif
}
if ( V_31 >= V_245 )
F_4 ( L_160 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_258 , V_560 ) ;
if ( V_31 >= V_571 )
F_223 ( V_1 , V_1 -> V_436 [ V_558 ] . V_448 ,
F_35 (unsigned int, framesize, SCABUFSIZE) , 0 ) ;
if ( V_560 ) {
if ( V_560 > V_1 -> V_68 )
V_1 -> V_106 . V_137 ++ ;
else {
int V_572 = V_560 ;
int V_19 = V_558 ;
unsigned char * V_573 = V_1 -> V_451 ;
V_1 -> V_574 = V_560 ;
V_1 -> V_106 . V_133 ++ ;
while( V_572 ) {
int V_575 = F_36 ( V_572 , V_429 ) ;
memcpy ( V_573 ,
V_1 -> V_436 [ V_19 ] . V_448 ,
V_575 ) ;
V_573 += V_575 ;
V_572 -= V_575 ;
if ( ++ V_19 == V_1 -> V_434 )
V_19 = 0 ;
}
#if V_306
if ( V_1 -> V_42 )
F_99 ( V_1 , V_1 -> V_451 , V_560 ) ;
else
#endif
F_5 ( V_9 , V_1 -> V_451 ,
V_1 -> V_452 , V_560 ) ;
}
}
F_222 ( V_1 , V_558 , V_559 ) ;
V_561 = true ;
V_566:
if ( V_1 -> V_383 && V_1 -> V_311 ) {
if ( V_1 -> V_435 [ V_559 ] . V_258 == 0xff ) {
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_151 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
}
}
return V_561 ;
}
static void F_34 ( T_1 * V_1 , const char * V_61 , unsigned int V_12 )
{
unsigned short V_572 ;
unsigned int V_339 = 0 ;
V_431 * V_563 ;
T_10 * V_564 ;
if ( V_31 >= V_571 )
F_223 ( V_1 , V_61 , F_35 (unsigned int, count, SCABUFSIZE) , 1 ) ;
for( V_339 = 0 ; ; )
{
V_572 = F_35 (unsigned int, count, SCABUFSIZE) ;
V_563 = & V_1 -> V_437 [ V_339 ] ;
V_564 = & V_1 -> V_438 [ V_339 ] ;
F_224 ( V_1 , V_564 -> V_448 , V_61 , V_572 ) ;
V_563 -> V_444 = V_572 ;
V_563 -> V_258 = 0 ;
V_61 += V_572 ;
V_12 -= V_572 ;
if ( ! V_12 )
break;
V_339 ++ ;
if ( V_339 >= V_1 -> V_432 )
V_339 = 0 ;
}
V_1 -> V_437 [ V_339 ] . V_258 = 0x81 ;
V_1 -> V_524 = ++ V_339 ;
}
static bool F_225 ( T_1 * V_1 )
{
static unsigned char V_576 [] = { 0x00 , 0xff , 0xaa , 0x55 , 0x69 , 0x96 } ;
static unsigned int V_12 = F_226 ( V_576 ) ;
unsigned int V_339 ;
bool V_182 = true ;
unsigned long V_11 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_142 ( V_1 ) ;
V_1 -> V_24 = V_577 ;
for ( V_339 = 0 ; V_339 < V_12 ; V_339 ++ ) {
F_76 ( V_1 , V_513 , V_576 [ V_339 ] ) ;
F_76 ( V_1 , V_550 , V_576 [ ( V_339 + 1 ) % V_12 ] ) ;
F_76 ( V_1 , V_578 , V_576 [ ( V_339 + 2 ) % V_12 ] ) ;
F_76 ( V_1 , V_579 , V_576 [ ( V_339 + 3 ) % V_12 ] ) ;
if ( ( F_75 ( V_1 , V_513 ) != V_576 [ V_339 ] ) ||
( F_75 ( V_1 , V_550 ) != V_576 [ ( V_339 + 1 ) % V_12 ] ) ||
( F_75 ( V_1 , V_578 ) != V_576 [ ( V_339 + 2 ) % V_12 ] ) ||
( F_75 ( V_1 , V_579 ) != V_576 [ ( V_339 + 3 ) % V_12 ] ) )
{
V_182 = false ;
break;
}
}
F_142 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
return V_182 ;
}
static bool F_227 ( T_1 * V_1 )
{
unsigned long V_46 ;
unsigned long V_11 ;
unsigned char V_250 = ( V_1 -> V_251 & 1 ) ? V_252 : V_253 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_142 ( V_1 ) ;
V_1 -> V_24 = V_580 ;
V_1 -> V_256 = false ;
F_76 ( V_1 , V_254 , ( unsigned char ) ( ( V_1 -> V_251 & 1 ) ? V_351 : V_349 ) ) ;
F_76 ( V_1 , ( unsigned char ) ( V_250 + V_581 ) , 0 ) ;
F_126 ( V_1 , ( unsigned char ) ( V_250 + V_582 ) , 1 ) ;
F_76 ( V_1 , ( unsigned char ) ( V_250 + V_255 ) , 0x50 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
V_46 = 100 ;
while( V_46 -- && ! V_1 -> V_256 ) {
F_40 ( 10 ) ;
}
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_142 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
return V_1 -> V_256 ;
}
static bool F_228 ( T_1 * V_1 )
{
F_76 ( V_1 , V_583 , 0 ) ;
F_76 ( V_1 , V_584 , 0 ) ;
F_76 ( V_1 , V_585 , 0 ) ;
F_76 ( V_1 , V_586 , 0 ) ;
F_76 ( V_1 , V_587 , 0 ) ;
F_76 ( V_1 , V_588 , V_589 ) ;
F_76 ( V_1 , V_590 , 0x80 ) ;
F_76 ( V_1 , V_591 , 0xff ) ;
F_76 ( V_1 , V_592 , 0xff ) ;
F_76 ( V_1 , V_254 , 0xf0 ) ;
F_76 ( V_1 , V_593 , 0 ) ;
return true ;
}
static bool F_229 ( T_1 * V_1 )
{
int V_339 ;
volatile T_13 * V_594 = ( T_13 * ) ( V_1 -> V_464 + 0x50 ) ;
T_13 V_595 ;
V_1 -> V_487 |= V_596 ;
* V_594 = V_1 -> V_487 ;
for( V_339 = 0 ; V_339 < 10 ; V_339 ++ )
V_595 = * V_594 ;
V_1 -> V_487 &= ~ V_596 ;
* V_594 = V_1 -> V_487 ;
V_1 -> V_507 = 0xaa ;
F_218 ( V_1 ) ;
{
volatile T_13 * V_597 = ( T_13 * ) ( V_1 -> V_464 + 0x2c ) ;
V_598 &= ~ ( V_348 + V_349 + V_150 ) ;
switch( V_599 )
{
case 16 :
V_598 |= V_348 + V_349 + V_150 ;
break;
case 8 :
V_598 |= V_348 + V_349 ;
break;
case 4 :
V_598 |= V_348 + V_150 ;
break;
case 0 :
V_598 |= V_348 ;
break;
}
* V_597 = V_598 ;
* V_594 = V_487 ;
}
F_228 ( V_1 -> V_345 [ 0 ] ) ;
F_228 ( V_1 -> V_345 [ 2 ] ) ;
return true ;
}
static bool F_230 ( T_1 * V_1 )
{
#define F_231 20
unsigned long V_46 ;
T_7 V_12 = F_231 ;
unsigned char V_61 [ F_231 ] ;
bool V_182 = false ;
unsigned long V_11 ;
struct V_8 * V_600 = V_1 -> V_27 . V_9 ;
T_13 V_601 = V_1 -> V_65 . V_211 ;
V_1 -> V_65 . V_211 = 3686400 ;
V_1 -> V_27 . V_9 = NULL ;
V_1 -> V_24 = V_602 ;
for ( V_12 = 0 ; V_12 < F_231 ; ++ V_12 )
V_61 [ V_12 ] = ( unsigned char ) V_12 ;
memset ( V_1 -> V_451 , 0 , F_231 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_149 ( V_1 ) ;
F_217 ( V_1 , 1 ) ;
F_151 ( V_1 ) ;
V_1 -> V_71 = V_12 ;
F_34 ( V_1 , V_61 , V_12 ) ;
F_37 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
for ( V_46 = 100 ; V_46 ; -- V_46 ) {
F_40 ( 10 ) ;
if ( F_117 ( V_1 ) ) {
V_182 = true ;
break;
}
}
if ( V_182 &&
( V_1 -> V_574 != V_12 ||
memcmp ( V_61 , V_1 -> V_451 , V_12 ) ) ) {
V_182 = false ;
}
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_221 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
V_1 -> V_65 . V_211 = V_601 ;
V_1 -> V_27 . V_9 = V_600 ;
return V_182 ;
}
static int F_205 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_161 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_229 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
V_1 -> V_345 [ 0 ] -> V_344 = 0 ;
if ( F_225 ( V_1 -> V_345 [ 0 ] ) &&
F_225 ( V_1 -> V_345 [ 1 ] ) ) {
V_1 -> V_345 [ 0 ] -> V_344 = 2 ;
if ( F_225 ( V_1 -> V_345 [ 2 ] ) &&
F_225 ( V_1 -> V_345 [ 3 ] ) )
V_1 -> V_345 [ 0 ] -> V_344 += 2 ;
}
else {
F_4 ( L_162 ,
__FILE__ , __LINE__ , V_1 -> V_25 , ( unsigned long ) ( V_1 -> V_123 ) ) ;
return - V_21 ;
}
if ( ! F_227 ( V_1 -> V_345 [ 0 ] ) ||
! F_227 ( V_1 -> V_345 [ 1 ] ) ||
( V_1 -> V_344 == 4 && ! F_227 ( V_1 -> V_345 [ 2 ] ) ) ||
( V_1 -> V_344 == 4 && ! F_227 ( V_1 -> V_345 [ 3 ] ) ) ) {
F_4 ( L_163 ,
__FILE__ , __LINE__ , V_1 -> V_25 , ( unsigned short ) ( V_1 -> V_127 ) ) ;
return - V_21 ;
}
if ( ! F_230 ( V_1 -> V_345 [ 0 ] ) ||
! F_230 ( V_1 -> V_345 [ 1 ] ) ||
( V_1 -> V_344 == 4 && ! F_230 ( V_1 -> V_345 [ 2 ] ) ) ||
( V_1 -> V_344 == 4 && ! F_230 ( V_1 -> V_345 [ 3 ] ) ) ) {
F_4 ( L_164 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_21 ;
}
if ( V_31 >= V_32 )
F_4 ( L_165 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_345 [ 0 ] -> V_24 = 0 ;
V_1 -> V_345 [ 1 ] -> V_24 = 0 ;
if ( V_1 -> V_344 > 2 ) {
V_1 -> V_345 [ 2 ] -> V_24 = 0 ;
V_1 -> V_345 [ 3 ] -> V_24 = 0 ;
}
return 0 ;
}
static bool F_189 ( T_1 * V_1 )
{
static unsigned long V_576 [] = { 0x0 , 0x55555555 , 0xaaaaaaaa ,
0x66666666 , 0x99999999 , 0xffffffff , 0x12345678 } ;
unsigned long V_12 = F_226 ( V_576 ) ;
unsigned long V_339 ;
unsigned long V_603 = V_428 /sizeof( unsigned long ) ;
unsigned long * V_604 = ( unsigned long * ) V_1 -> V_440 ;
for ( V_339 = 0 ; V_339 < V_12 ; V_339 ++ ) {
* V_604 = V_576 [ V_339 ] ;
if ( * V_604 != V_576 [ V_339 ] )
return false ;
}
for ( V_339 = 0 ; V_339 < V_603 ; V_339 ++ ) {
* V_604 = V_339 * 4 ;
V_604 ++ ;
}
V_604 = ( unsigned long * ) V_1 -> V_440 ;
for ( V_339 = 0 ; V_339 < V_603 ; V_339 ++ ) {
if ( * V_604 != V_339 * 4 )
return false ;
V_604 ++ ;
}
memset ( V_1 -> V_440 , 0 , V_428 ) ;
return true ;
}
static void F_224 ( T_1 * V_1 , char * V_605 , const char * V_606 , unsigned short V_12 )
{
unsigned short V_607 = V_12 / V_608 ;
unsigned short V_339 ;
for ( V_339 = 0 ; V_339 < V_607 ; V_339 ++ )
{
memcpy ( V_605 , V_606 , V_608 ) ;
F_220 ( V_1 ) ;
V_605 += V_608 ;
V_606 += V_608 ;
}
memcpy ( V_605 , V_606 , V_12 % V_608 ) ;
}
static void F_223 ( T_1 * V_1 , const char * V_10 , int V_12 , int V_237 )
{
int V_339 ;
int V_609 ;
if ( V_237 )
F_4 ( L_166 , V_1 -> V_25 ) ;
else
F_4 ( L_167 , V_1 -> V_25 ) ;
while( V_12 ) {
if ( V_12 > 16 )
V_609 = 16 ;
else
V_609 = V_12 ;
for( V_339 = 0 ; V_339 < V_609 ; V_339 ++ )
F_4 ( L_168 , ( unsigned char ) V_10 [ V_339 ] ) ;
for(; V_339 < 17 ; V_339 ++ )
F_4 ( L_169 ) ;
for( V_339 = 0 ; V_339 < V_609 ; V_339 ++ ) {
if ( V_10 [ V_339 ] >= 040 && V_10 [ V_339 ] <= 0176 )
F_4 ( L_170 , V_10 [ V_339 ] ) ;
else
F_4 ( L_171 ) ;
}
F_4 ( L_172 ) ;
V_10 += V_609 ;
V_12 -= V_609 ;
}
}
static void V_485 ( unsigned long V_610 )
{
T_1 * V_1 = ( T_1 * ) V_610 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_173 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if( V_1 -> V_70 && V_1 -> V_65 . V_66 == V_67 ) {
V_1 -> V_106 . V_611 ++ ;
}
F_13 ( & V_1 -> V_47 , V_11 ) ;
V_1 -> V_70 = false ;
V_1 -> V_71 = V_1 -> V_73 = V_1 -> V_85 = 0 ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
#if V_306
if ( V_1 -> V_42 )
F_97 ( V_1 ) ;
else
#endif
F_115 ( V_1 ) ;
}
static void V_486 ( unsigned long V_610 )
{
T_7 V_258 = 0 ;
T_1 * V_1 = ( T_1 * ) V_610 ;
unsigned long V_11 ;
unsigned char V_612 ;
F_13 ( & V_1 -> V_47 , V_11 ) ;
F_64 ( V_1 ) ;
F_14 ( & V_1 -> V_47 , V_11 ) ;
V_612 = V_1 -> V_613 ^ V_1 -> V_55 ;
V_1 -> V_613 = V_1 -> V_55 ;
if ( V_612 & V_129 )
V_258 |= V_314 | ( V_1 -> V_55 & V_129 ) ;
if ( V_612 & V_131 )
V_258 |= V_315 | ( V_1 -> V_55 & V_131 ) ;
if ( V_612 & V_130 )
V_258 |= V_277 | ( V_1 -> V_55 & V_130 ) ;
if ( V_612 & V_128 )
V_258 |= V_308 | ( V_1 -> V_55 & V_128 ) ;
if ( V_258 )
F_122 ( V_1 , V_258 ) ;
F_143 ( & V_1 -> V_354 , V_81 + F_144 ( 10 ) ) ;
}
static unsigned char F_75 ( T_1 * V_1 , unsigned char V_614 )
{
F_232 () ;
return * V_615 ;
}
static void F_76 ( T_1 * V_1 , unsigned char V_614 , unsigned char V_616 )
{
F_232 () ;
* V_615 = V_616 ;
}
static T_7 F_138 ( T_1 * V_1 , unsigned char V_614 )
{
F_232 () ;
return * ( ( T_7 * ) V_615 ) ;
}
static void F_126 ( T_1 * V_1 , unsigned char V_614 , T_7 V_616 )
{
F_232 () ;
* ( ( T_7 * ) V_615 ) = V_616 ;
}
static unsigned char F_220 ( T_1 * V_1 )
{
unsigned char * V_615 = ( unsigned char * ) V_1 -> V_467 ;
return * V_615 ;
}
static void F_218 ( T_1 * V_1 )
{
unsigned char * V_615 = ( unsigned char * ) V_1 -> V_467 ;
* V_615 = V_1 -> V_345 [ 0 ] -> V_507 ;
}
static int F_233 ( struct V_474 * V_152 ,
const struct V_617 * V_618 )
{
if ( F_234 ( V_152 ) ) {
F_4 ( L_174 , V_152 ) ;
return - V_69 ;
}
F_202 ( ++ V_619 , V_152 ) ;
return 0 ;
}
static void F_235 ( struct V_474 * V_152 )
{
}
