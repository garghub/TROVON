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
V_1 -> V_27 . V_33 = ( V_1 -> V_27 . V_11 & V_34 ) ? 1 : 0 ;
F_11 ( & V_1 -> V_35 , V_11 ) ;
if ( V_1 -> V_36 ) {
V_30 = - V_37 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
goto V_38;
}
V_1 -> V_27 . V_12 ++ ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
if ( V_1 -> V_27 . V_12 == 1 ) {
V_30 = F_13 ( V_1 ) ;
if ( V_30 < 0 )
goto V_38;
}
V_30 = F_14 ( V_9 , V_29 , V_1 ) ;
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
static void F_15 ( struct V_8 * V_9 , struct V_28 * V_29 )
{
T_1 * V_1 = V_9 -> V_26 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_9 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_10 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_27 . V_12 ) ;
if ( F_16 ( & V_1 -> V_27 , V_9 , V_29 ) == 0 )
goto V_38;
F_17 ( & V_1 -> V_27 . V_39 ) ;
if ( V_1 -> V_27 . V_11 & V_40 )
F_18 ( V_9 , V_1 -> V_41 ) ;
F_19 ( V_9 ) ;
F_20 ( V_9 ) ;
F_21 ( V_1 ) ;
F_22 ( & V_1 -> V_27 . V_39 ) ;
F_23 ( & V_1 -> V_27 , V_9 ) ;
V_1 -> V_27 . V_9 = NULL ;
V_38:
if ( V_31 >= V_32 )
F_4 ( L_11 , __FILE__ , __LINE__ ,
V_9 -> V_18 -> V_2 , V_1 -> V_27 . V_12 ) ;
}
static void F_24 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_12 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_13 ) )
return;
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_19 ( V_9 ) ;
F_21 ( V_1 ) ;
F_11 ( & V_1 -> V_27 . V_42 , V_11 ) ;
V_1 -> V_27 . V_12 = 0 ;
V_1 -> V_27 . V_11 &= ~ V_43 ;
V_1 -> V_27 . V_9 = NULL ;
F_12 ( & V_1 -> V_27 . V_42 , V_11 ) ;
F_22 ( & V_1 -> V_27 . V_39 ) ;
F_25 ( & V_1 -> V_27 . V_44 ) ;
}
static void F_26 ( struct V_8 * V_9 , struct V_45 * V_46 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_14 , __FILE__ , __LINE__ ,
V_9 -> V_18 -> V_2 ) ;
F_27 ( V_1 ) ;
if ( V_46 -> V_47 & V_48 &&
! ( V_9 -> V_49 . V_47 & V_48 ) ) {
V_1 -> V_50 &= ~ ( V_51 | V_52 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
if ( ! ( V_46 -> V_47 & V_48 ) &&
V_9 -> V_49 . V_47 & V_48 ) {
V_1 -> V_50 |= V_52 ;
if ( ! ( V_9 -> V_49 . V_47 & V_53 ) ||
! F_29 ( V_54 , & V_9 -> V_11 ) ) {
V_1 -> V_50 |= V_51 ;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
if ( V_46 -> V_47 & V_53 &&
! ( V_9 -> V_49 . V_47 & V_53 ) ) {
V_9 -> V_55 = 0 ;
F_30 ( V_9 ) ;
}
}
static int F_31 ( struct V_8 * V_9 ,
const unsigned char * V_56 , int V_12 )
{
int V_57 , V_58 = 0 ;
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_15 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_12 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_16 ) )
goto V_38;
if ( ! V_1 -> V_59 )
goto V_38;
if ( V_1 -> V_60 . V_61 == V_62 ) {
if ( V_12 > V_1 -> V_63 ) {
V_58 = - V_64 ;
goto V_38;
}
if ( V_1 -> V_65 )
goto V_38;
if ( V_1 -> V_66 ) {
F_32 ( V_1 , V_1 -> V_59 , V_1 -> V_66 ) ;
goto V_67;
}
V_58 = V_1 -> V_66 = V_12 ;
F_32 ( V_1 , V_56 , V_12 ) ;
goto V_67;
}
for (; ; ) {
V_57 = F_33 ( int , V_12 ,
F_34 ( V_1 -> V_63 - V_1 -> V_66 - 1 ,
V_1 -> V_63 - V_1 -> V_68 ) ) ;
if ( V_57 <= 0 )
break;
memcpy ( V_1 -> V_59 + V_1 -> V_68 , V_56 , V_57 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_68 += V_57 ;
if ( V_1 -> V_68 >= V_1 -> V_63 )
V_1 -> V_68 -= V_1 -> V_63 ;
V_1 -> V_66 += V_57 ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_56 += V_57 ;
V_12 -= V_57 ;
V_58 += V_57 ;
}
if ( V_1 -> V_60 . V_61 == V_62 ) {
if ( V_12 ) {
V_58 = V_1 -> V_66 = 0 ;
goto V_38;
}
F_32 ( V_1 , V_1 -> V_59 , V_1 -> V_66 ) ;
}
V_67:
if ( V_1 -> V_66 && ! V_9 -> V_69 && ! V_9 -> V_55 ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_65 )
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
V_38:
if ( V_31 >= V_32 )
F_4 ( L_17 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_58 ) ;
return V_58 ;
}
static int F_36 ( struct V_8 * V_9 , unsigned char V_70 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
int V_58 = 0 ;
if ( V_31 >= V_32 ) {
F_4 ( L_18 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_70 ) ;
}
if ( F_2 ( V_1 , V_9 -> V_2 , L_19 ) )
return 0 ;
if ( ! V_1 -> V_59 )
return 0 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ( V_1 -> V_60 . V_61 != V_62 ) ||
! V_1 -> V_65 ) {
if ( V_1 -> V_66 < V_1 -> V_63 - 1 ) {
V_1 -> V_59 [ V_1 -> V_68 ++ ] = V_70 ;
if ( V_1 -> V_68 >= V_1 -> V_63 )
V_1 -> V_68 -= V_1 -> V_63 ;
V_1 -> V_66 ++ ;
V_58 = 1 ;
}
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_58 ;
}
static void F_37 ( struct V_8 * V_9 , char V_70 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_20 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_70 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_21 ) )
return;
V_1 -> V_71 = V_70 ;
if ( V_70 ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_72 )
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
}
static void F_18 ( struct V_8 * V_9 , int V_41 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_73 , V_74 ;
if ( ! V_1 )
return;
if ( V_31 >= V_32 )
F_4 ( L_22 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_23 ) )
return;
if ( ! F_29 ( V_75 , & V_1 -> V_27 . V_11 ) )
goto exit;
V_73 = V_76 ;
if ( V_1 -> V_60 . V_77 ) {
V_74 = V_1 -> V_41 / ( 32 * 5 ) ;
if ( ! V_74 )
V_74 ++ ;
} else
V_74 = 1 ;
if ( V_41 )
V_74 = F_33 (unsigned long, char_time, timeout) ;
if ( V_1 -> V_60 . V_61 == V_62 ) {
while ( V_1 -> V_65 ) {
F_38 ( F_39 ( V_74 ) ) ;
if ( F_40 ( V_78 ) )
break;
if ( V_41 && F_41 ( V_76 , V_73 + V_41 ) )
break;
}
} else {
while ( V_1 -> V_65 && V_1 -> V_72 ) {
F_38 ( F_39 ( V_74 ) ) ;
if ( F_40 ( V_78 ) )
break;
if ( V_41 && F_41 ( V_76 , V_73 + V_41 ) )
break;
}
}
exit:
if ( V_31 >= V_32 )
F_4 ( L_24 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
int V_58 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_25 ) )
return 0 ;
if ( V_1 -> V_60 . V_61 == V_62 ) {
V_58 = ( V_1 -> V_65 ) ? 0 : V_79 ;
} else {
V_58 = V_1 -> V_63 - V_1 -> V_66 - 1 ;
if ( V_58 < 0 )
V_58 = 0 ;
}
if ( V_31 >= V_32 )
F_4 ( L_26 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_58 ) ;
return V_58 ;
}
static void F_43 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_27 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_66 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_28 ) )
return;
if ( V_1 -> V_66 <= 0 || V_9 -> V_69 || V_9 -> V_55 ||
! V_1 -> V_59 )
return;
if ( V_31 >= V_32 )
F_4 ( L_29 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_65 ) {
if ( ( V_1 -> V_60 . V_61 == V_62 ) &&
V_1 -> V_66 ) {
F_32 ( V_1 ,
V_1 -> V_59 , V_1 -> V_66 ) ;
}
F_35 ( V_1 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_30 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_31 ) )
return;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_66 = V_1 -> V_68 = V_1 -> V_80 = 0 ;
F_44 ( & V_1 -> V_81 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
F_45 ( V_9 ) ;
}
static void F_46 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_32 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_33 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_72 )
F_47 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_34 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_35 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_72 )
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
static int F_48 ( struct V_8 * V_9 ,
unsigned int V_82 , unsigned long V_83 )
{
T_1 * V_1 = V_9 -> V_26 ;
void T_3 * V_84 = ( void T_3 * ) V_83 ;
if ( V_31 >= V_32 )
F_4 ( L_36 , __FILE__ , __LINE__ ,
V_1 -> V_25 , V_82 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_37 ) )
return - V_21 ;
if ( ( V_82 != V_85 ) && ( V_82 != V_86 ) &&
( V_82 != V_87 ) ) {
if ( V_9 -> V_11 & ( 1 << V_88 ) )
return - V_64 ;
}
switch ( V_82 ) {
case V_89 :
return F_49 ( V_1 , V_84 ) ;
case V_90 :
return F_50 ( V_1 , V_84 ) ;
case V_91 :
return F_51 ( V_1 , V_84 ) ;
case V_92 :
return F_52 ( V_1 , ( int ) V_83 ) ;
case V_93 :
return F_53 ( V_1 , ( int ) V_83 ) ;
case V_94 :
return F_54 ( V_1 , ( int ) V_83 ) ;
case V_95 :
return F_55 ( V_1 ) ;
case V_96 :
return F_56 ( V_1 , V_84 ) ;
case V_97 :
return F_57 ( V_1 , V_84 ) ;
case V_98 :
return 0 ;
case V_87 :
return F_58 ( V_1 , ( int ) V_83 ) ;
default:
return - V_99 ;
}
return 0 ;
}
static int F_59 ( struct V_8 * V_9 ,
struct V_100 * V_101 )
{
T_1 * V_1 = V_9 -> V_26 ;
struct V_102 V_103 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_103 = V_1 -> V_101 ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_101 -> V_104 = V_103 . V_104 ;
V_101 -> V_105 = V_103 . V_105 ;
V_101 -> V_106 = V_103 . V_106 ;
V_101 -> V_107 = V_103 . V_107 ;
V_101 -> V_108 = V_103 . V_108 ;
V_101 -> V_109 = V_103 . V_109 ;
V_101 -> V_110 = V_103 . V_110 ;
V_101 -> V_111 = V_103 . V_111 ;
V_101 -> V_112 = V_103 . V_112 ;
V_101 -> V_113 = V_103 . V_113 ;
V_101 -> V_114 = V_103 . V_114 ;
return 0 ;
}
static inline void F_60 ( struct V_115 * V_116 , T_1 * V_1 )
{
char V_117 [ 30 ] ;
unsigned long V_11 ;
F_61 ( V_116 , L_38
L_39 ,
V_1 -> V_25 ,
V_1 -> V_118 ,
V_1 -> V_119 ,
V_1 -> V_120 ,
V_1 -> V_121 ,
V_1 -> V_122 ,
V_1 -> V_63 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_117 [ 0 ] = 0 ;
V_117 [ 1 ] = 0 ;
if ( V_1 -> V_50 & V_51 )
strcat ( V_117 , L_40 ) ;
if ( V_1 -> V_50 & V_123 )
strcat ( V_117 , L_41 ) ;
if ( V_1 -> V_50 & V_52 )
strcat ( V_117 , L_42 ) ;
if ( V_1 -> V_50 & V_124 )
strcat ( V_117 , L_43 ) ;
if ( V_1 -> V_50 & V_125 )
strcat ( V_117 , L_44 ) ;
if ( V_1 -> V_50 & V_126 )
strcat ( V_117 , L_45 ) ;
if ( V_1 -> V_60 . V_61 == V_62 ) {
F_61 ( V_116 , L_46 ,
V_1 -> V_101 . V_127 , V_1 -> V_101 . V_128 ) ;
if ( V_1 -> V_101 . V_129 )
F_61 ( V_116 , L_47 , V_1 -> V_101 . V_129 ) ;
if ( V_1 -> V_101 . V_130 )
F_61 ( V_116 , L_48 , V_1 -> V_101 . V_130 ) ;
if ( V_1 -> V_101 . V_131 )
F_61 ( V_116 , L_49 , V_1 -> V_101 . V_131 ) ;
if ( V_1 -> V_101 . V_132 )
F_61 ( V_116 , L_50 , V_1 -> V_101 . V_132 ) ;
if ( V_1 -> V_101 . V_133 )
F_61 ( V_116 , L_51 , V_1 -> V_101 . V_133 ) ;
if ( V_1 -> V_101 . V_134 )
F_61 ( V_116 , L_50 , V_1 -> V_101 . V_134 ) ;
} else {
F_61 ( V_116 , L_52 ,
V_1 -> V_101 . V_109 , V_1 -> V_101 . V_108 ) ;
if ( V_1 -> V_101 . V_110 )
F_61 ( V_116 , L_53 , V_1 -> V_101 . V_110 ) ;
if ( V_1 -> V_101 . V_112 )
F_61 ( V_116 , L_54 , V_1 -> V_101 . V_112 ) ;
if ( V_1 -> V_101 . V_113 )
F_61 ( V_116 , L_55 , V_1 -> V_101 . V_113 ) ;
if ( V_1 -> V_101 . V_111 )
F_61 ( V_116 , L_56 , V_1 -> V_101 . V_111 ) ;
}
F_61 ( V_116 , L_57 , V_117 + 1 ) ;
F_61 ( V_116 , L_58 ,
V_1 -> V_65 , V_1 -> V_135 , V_1 -> V_136 ,
V_1 -> V_137 ) ;
}
static int F_63 ( struct V_115 * V_116 , void * V_138 )
{
T_1 * V_1 ;
F_61 ( V_116 , L_59 , V_139 ) ;
V_1 = V_22 ;
while( V_1 ) {
F_60 ( V_116 , V_1 ) ;
V_1 = V_1 -> V_23 ;
}
return 0 ;
}
static int F_64 ( struct V_140 * V_140 , struct V_28 * V_28 )
{
return F_65 ( V_28 , F_63 , NULL ) ;
}
static int F_66 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_60 ) )
return 0 ;
if ( V_31 >= V_32 )
F_4 ( L_61 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_66 ) ;
return V_1 -> V_66 ;
}
static void F_67 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_63 ) )
return;
if ( F_68 ( V_9 ) )
F_37 ( V_9 , F_69 ( V_9 ) ) ;
if ( V_9 -> V_49 . V_47 & V_53 ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_50 &= ~ V_51 ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
}
static void F_70 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_64 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_65 ) )
return;
if ( F_68 ( V_9 ) ) {
if ( V_1 -> V_71 )
V_1 -> V_71 = 0 ;
else
F_37 ( V_9 , F_71 ( V_9 ) ) ;
}
if ( V_9 -> V_49 . V_47 & V_53 ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_50 |= V_51 ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
}
static int F_72 ( struct V_8 * V_9 , int V_141 )
{
unsigned char V_142 ;
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_66 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_141 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_67 ) )
return - V_143 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_142 = F_73 ( V_1 , V_144 ) ;
if ( V_141 == - 1 )
V_142 |= V_145 ;
else
V_142 &= ~ V_145 ;
F_74 ( V_1 , V_144 , V_142 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_75 ( struct V_146 * V_147 , unsigned short V_148 ,
unsigned short V_112 )
{
T_1 * V_1 = F_76 ( V_147 ) ;
unsigned char V_149 ;
unsigned short V_150 ;
if ( V_1 -> V_27 . V_12 )
return - V_37 ;
switch ( V_148 )
{
case V_151 : V_149 = V_152 ; break;
case V_153 : V_149 = V_154 ; break;
case V_155 : V_149 = V_156 ; break;
case V_157 : V_149 = V_158 ; break;
case V_159 : V_149 = V_160 ; break;
default: return - V_143 ;
}
switch ( V_112 )
{
case V_161 : V_150 = V_162 ; break;
case V_163 : V_150 = V_164 ; break;
case V_165 : V_150 = V_166 ; break;
default: return - V_143 ;
}
V_1 -> V_60 . V_148 = V_149 ;
V_1 -> V_60 . V_167 = V_150 ;
if ( V_1 -> V_36 )
F_77 ( V_1 ) ;
return 0 ;
}
static T_4 F_78 ( struct V_168 * V_169 ,
struct V_146 * V_147 )
{
T_1 * V_1 = F_76 ( V_147 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( V_170 L_68 , __FILE__ , V_147 -> V_2 ) ;
F_79 ( V_147 ) ;
V_1 -> V_66 = V_169 -> V_171 ;
F_32 ( V_1 , V_169 -> V_10 , V_169 -> V_171 ) ;
V_147 -> V_172 . V_173 ++ ;
V_147 -> V_172 . V_174 += V_169 -> V_171 ;
F_80 ( V_169 ) ;
V_147 -> V_175 = V_76 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_65 )
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_176 ;
}
static int F_81 ( struct V_146 * V_147 )
{
T_1 * V_1 = F_76 ( V_147 ) ;
int V_177 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_69 , __FILE__ , V_147 -> V_2 ) ;
V_177 = F_82 ( V_147 ) ;
if ( V_177 )
return V_177 ;
F_11 ( & V_1 -> V_35 , V_11 ) ;
if ( V_1 -> V_27 . V_12 != 0 || V_1 -> V_36 != 0 ) {
F_4 ( V_178 L_70 , V_147 -> V_2 ) ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
return - V_37 ;
}
V_1 -> V_36 = 1 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
if ( ( V_177 = F_13 ( V_1 ) ) != 0 ) {
F_11 ( & V_1 -> V_35 , V_11 ) ;
V_1 -> V_36 = 0 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
return V_177 ;
}
V_1 -> V_50 |= V_51 | V_52 ;
F_77 ( V_1 ) ;
V_147 -> V_175 = V_76 ;
F_83 ( V_147 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_50 & V_125 )
F_84 ( V_147 ) ;
else
F_85 ( V_147 ) ;
return 0 ;
}
static int F_86 ( struct V_146 * V_147 )
{
T_1 * V_1 = F_76 ( V_147 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_71 , __FILE__ , V_147 -> V_2 ) ;
F_79 ( V_147 ) ;
F_21 ( V_1 ) ;
F_87 ( V_147 ) ;
F_11 ( & V_1 -> V_35 , V_11 ) ;
V_1 -> V_36 = 0 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
return 0 ;
}
static int F_88 ( struct V_146 * V_147 , struct V_179 * V_180 , int V_82 )
{
const T_5 V_181 = sizeof( V_182 ) ;
V_182 V_183 ;
V_182 T_3 * line = V_180 -> V_184 . V_185 . V_186 ;
T_1 * V_1 = F_76 ( V_147 ) ;
unsigned int V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_72 , __FILE__ , V_147 -> V_2 ) ;
if ( V_1 -> V_27 . V_12 )
return - V_37 ;
if ( V_82 != V_187 )
return F_89 ( V_147 , V_180 , V_82 ) ;
switch( V_180 -> V_184 . type ) {
case V_188 :
V_180 -> V_184 . type = V_189 ;
if ( V_180 -> V_184 . V_181 < V_181 ) {
V_180 -> V_184 . V_181 = V_181 ;
return - V_190 ;
}
V_11 = V_1 -> V_60 . V_11 & ( V_191 | V_192 |
V_193 | V_194 |
V_195 | V_196 |
V_197 | V_198 ) ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
switch ( V_11 ) {
case ( V_191 | V_195 ) : V_183 . V_199 = V_200 ; break;
case ( V_193 | V_197 ) : V_183 . V_199 = V_201 ; break;
case ( V_191 | V_197 ) : V_183 . V_199 = V_202 ; break;
case ( V_191 | V_198 ) : V_183 . V_199 = V_203 ; break;
default: V_183 . V_199 = V_204 ;
}
V_183 . V_205 = V_1 -> V_60 . V_206 ;
V_183 . V_207 = V_1 -> V_60 . V_207 ? 1 : 0 ;
if ( F_90 ( line , & V_183 , V_181 ) )
return - V_208 ;
return 0 ;
case V_189 :
if( ! F_91 ( V_209 ) )
return - V_210 ;
if ( F_92 ( & V_183 , line , V_181 ) )
return - V_208 ;
switch ( V_183 . V_199 )
{
case V_200 : V_11 = V_191 | V_195 ; break;
case V_203 : V_11 = V_191 | V_198 ; break;
case V_201 : V_11 = V_193 | V_197 ; break;
case V_202 : V_11 = V_191 | V_197 ; break;
case V_204 : V_11 = V_1 -> V_60 . V_11 &
( V_191 | V_192 |
V_193 | V_194 |
V_195 | V_196 |
V_197 | V_198 ) ; break;
default: return - V_143 ;
}
if ( V_183 . V_207 != 0 && V_183 . V_207 != 1 )
return - V_143 ;
V_1 -> V_60 . V_11 &= ~ ( V_191 | V_192 |
V_193 | V_194 |
V_195 | V_196 |
V_197 | V_198 ) ;
V_1 -> V_60 . V_11 |= V_11 ;
V_1 -> V_60 . V_207 = V_183 . V_207 ;
if ( V_11 & ( V_193 | V_197 ) )
V_1 -> V_60 . V_206 = V_183 . V_205 ;
else
V_1 -> V_60 . V_206 = 0 ;
if ( V_1 -> V_36 )
F_77 ( V_1 ) ;
return 0 ;
default:
return F_89 ( V_147 , V_180 , V_82 ) ;
}
}
static void F_93 ( struct V_146 * V_147 )
{
T_1 * V_1 = F_76 ( V_147 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_73 , V_147 -> V_2 ) ;
V_147 -> V_172 . V_211 ++ ;
V_147 -> V_172 . V_212 ++ ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_47 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
F_94 ( V_147 ) ;
}
static void F_95 ( T_1 * V_1 )
{
if ( F_96 ( V_1 -> V_213 ) )
F_94 ( V_1 -> V_213 ) ;
}
static void F_97 ( T_1 * V_1 , char * V_56 , int V_181 )
{
struct V_168 * V_169 = F_98 ( V_181 ) ;
struct V_146 * V_147 = V_1 -> V_213 ;
if ( V_31 >= V_32 )
F_4 ( L_74 , V_147 -> V_2 ) ;
if ( V_169 == NULL ) {
F_4 ( V_214 L_75 ,
V_147 -> V_2 ) ;
V_147 -> V_172 . V_215 ++ ;
return;
}
memcpy ( F_99 ( V_169 , V_181 ) , V_56 , V_181 ) ;
V_169 -> V_216 = F_100 ( V_169 , V_147 ) ;
V_147 -> V_172 . V_217 ++ ;
V_147 -> V_172 . V_218 += V_181 ;
F_101 ( V_169 ) ;
}
static int F_102 ( T_1 * V_1 )
{
int V_177 ;
struct V_146 * V_147 ;
T_6 * V_219 ;
V_147 = F_103 ( V_1 ) ;
if ( ! V_147 ) {
F_4 ( V_220 L_76 , __FILE__ ) ;
return - V_221 ;
}
V_147 -> V_222 = V_1 -> V_118 ;
V_147 -> V_223 = V_1 -> V_118 + V_224 - 1 ;
V_147 -> V_225 = V_1 -> V_122 ;
V_147 -> V_226 = & V_227 ;
V_147 -> V_228 = 10 * V_229 ;
V_147 -> V_230 = 50 ;
V_219 = F_104 ( V_147 ) ;
V_219 -> V_231 = F_75 ;
V_219 -> V_232 = F_78 ;
V_177 = F_105 ( V_147 ) ;
if ( V_177 ) {
F_4 ( V_178 L_77 , __FILE__ ) ;
F_106 ( V_147 ) ;
return V_177 ;
}
V_1 -> V_213 = V_147 ;
return 0 ;
}
static void F_107 ( T_1 * V_1 )
{
F_108 ( V_1 -> V_213 ) ;
F_106 ( V_1 -> V_213 ) ;
V_1 -> V_213 = NULL ;
}
static int F_109 ( T_1 * V_1 )
{
unsigned long V_11 ;
int V_177 = 0 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_137 & V_233 ) {
V_1 -> V_137 &= ~ V_233 ;
V_177 = V_233 ;
} else if ( V_1 -> V_137 & V_234 ) {
V_1 -> V_137 &= ~ V_234 ;
V_177 = V_234 ;
} else if ( V_1 -> V_137 & V_235 ) {
V_1 -> V_137 &= ~ V_235 ;
V_177 = V_235 ;
}
if ( ! V_177 ) {
V_1 -> V_136 = false ;
V_1 -> V_135 = false ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_177 ;
}
static void F_110 ( struct V_236 * V_237 )
{
T_1 * V_1 = F_111 ( V_237 , T_1 , V_238 ) ;
int V_239 ;
if ( V_31 >= V_240 )
F_4 ( L_78 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_136 = true ;
while( ( V_239 = F_109 ( V_1 ) ) != 0 ) {
if ( V_31 >= V_240 )
F_4 ( L_79 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_239 ) ;
switch ( V_239 ) {
case V_233 :
F_112 ( V_1 ) ;
break;
case V_234 :
F_113 ( V_1 ) ;
break;
case V_235 :
F_114 ( V_1 ) ;
break;
default:
F_4 ( L_80 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_239 ) ;
break;
}
}
if ( V_31 >= V_240 )
F_4 ( L_81 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_112 ( T_1 * V_1 )
{
if ( V_31 >= V_240 )
F_4 ( L_82 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
while( F_115 ( V_1 ) ) ;
}
static void F_113 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
if ( V_31 >= V_240 )
F_4 ( L_83 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_9 )
F_45 ( V_9 ) ;
}
static void F_114 ( T_1 * V_1 )
{
if ( V_31 >= V_240 )
F_4 ( L_84 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_241 = 0 ;
V_1 -> V_242 = 0 ;
V_1 -> V_243 = 0 ;
V_1 -> V_244 = 0 ;
}
static void F_116 ( T_1 * V_1 )
{
unsigned char V_245 = ( V_1 -> V_246 & 1 ) ? V_247 : V_248 ;
F_74 ( V_1 , V_249 , 0 ) ;
F_74 ( V_1 , ( unsigned char ) ( V_245 + V_250 ) , 0 ) ;
V_1 -> V_251 = true ;
if ( V_31 >= V_252 )
F_4 ( L_85 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_117 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
struct V_102 * V_101 = & V_1 -> V_101 ;
unsigned char V_253 = F_73 ( V_1 , V_254 ) & V_1 -> V_255 & ( V_256 + V_257 + V_258 + V_259 ) ;
unsigned char V_260 = F_73 ( V_1 , V_261 ) & V_1 -> V_262 & V_263 ;
if ( V_253 )
F_74 ( V_1 , V_254 , V_253 ) ;
if ( V_260 )
F_74 ( V_1 , V_261 , V_260 ) ;
if ( V_31 >= V_252 )
F_4 ( L_86 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_253 , V_260 ) ;
if ( V_1 -> V_60 . V_61 == V_264 ) {
if ( V_253 & V_259 ) {
V_101 -> V_113 ++ ;
if ( ! ( V_253 & V_1 -> V_265 ) ) {
if ( V_1 -> V_266 & V_259 ) {
F_118 ( & V_1 -> V_27 , 0 , V_267 ) ;
if ( V_9 && ( V_1 -> V_27 . V_11 & V_268 ) )
F_119 ( V_9 ) ;
}
}
}
}
else {
if ( V_253 & ( V_256 | V_257 ) ) {
if ( V_253 & V_256 )
V_1 -> V_101 . V_269 ++ ;
else if ( V_253 & V_257 )
V_1 -> V_101 . V_270 ++ ;
F_25 ( & V_1 -> V_271 ) ;
}
}
if ( V_253 & V_258 ) {
F_62 ( V_1 ) ;
F_120 ( V_1 ,
V_272 | ( V_1 -> V_50 & V_125 ) ) ;
}
}
static void F_121 ( T_1 * V_1 )
{
T_7 V_253 ;
unsigned char V_273 ;
struct V_102 * V_101 = & V_1 -> V_101 ;
if ( V_31 >= V_252 )
F_4 ( L_87 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
while( ( V_253 = F_73 ( V_1 , V_274 ) ) & V_275 )
{
int V_276 = 0 ;
bool V_277 = false ;
V_273 = F_73 ( V_1 , V_278 ) ;
V_101 -> V_108 ++ ;
if ( V_253 & ( V_279 + V_280 + V_263 ) ) {
F_4 ( L_88 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_253 ) ;
if ( V_253 & V_279 )
V_101 -> V_112 ++ ;
else if ( V_253 & V_280 )
V_101 -> V_110 ++ ;
else if ( V_253 & V_263 )
V_101 -> V_111 ++ ;
if ( V_253 & V_1 -> V_281 )
continue;
V_253 &= V_1 -> V_282 ;
if ( V_253 & V_279 )
V_276 = V_283 ;
else if ( V_253 & V_280 )
V_276 = V_284 ;
if ( V_253 & V_263 ) {
V_277 = true ;
}
}
F_118 ( & V_1 -> V_27 , V_273 , V_276 ) ;
if ( V_277 )
F_118 ( & V_1 -> V_27 , 0 , V_285 ) ;
}
if ( V_31 >= V_252 ) {
F_4 ( L_89 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_101 -> V_108 , V_101 -> V_113 , V_101 -> V_112 ,
V_101 -> V_110 , V_101 -> V_111 ) ;
}
F_122 ( & V_1 -> V_27 ) ;
}
static void F_123 ( T_1 * V_1 , unsigned char V_253 )
{
if ( V_31 >= V_252 )
F_4 ( L_90 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_253 ) ;
F_74 ( V_1 , V_286 + V_287 , 0x00 ) ;
F_74 ( V_1 , V_286 + V_288 , 0xc0 ) ;
F_74 ( V_1 , V_286 + V_289 , V_290 ) ;
if ( V_253 & V_291 ) {
F_74 ( V_1 , V_292 , V_293 ) ;
F_74 ( V_1 , V_292 , V_294 ) ;
} else
F_74 ( V_1 , V_292 , V_295 ) ;
V_1 -> V_296 &= ~ V_297 ;
V_1 -> V_255 &= ~ ( V_298 + V_291 ) ;
F_124 ( V_1 , V_299 , ( unsigned short ) ( ( V_1 -> V_255 << 8 ) + V_1 -> V_296 ) ) ;
F_74 ( V_1 , V_254 , ( unsigned char ) ( V_291 + V_298 ) ) ;
if ( V_1 -> V_65 ) {
if ( V_1 -> V_60 . V_61 != V_264 ) {
if ( V_253 & V_291 )
V_1 -> V_101 . V_129 ++ ;
else if ( V_253 & V_298 )
V_1 -> V_101 . V_127 ++ ;
}
V_1 -> V_65 = false ;
V_1 -> V_66 = V_1 -> V_68 = V_1 -> V_80 = 0 ;
F_44 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_60 . V_61 != V_264 && V_1 -> V_300 ) {
V_1 -> V_50 &= ~ V_51 ;
V_1 -> V_300 = false ;
F_28 ( V_1 ) ;
}
#if V_301
if ( V_1 -> V_36 )
F_95 ( V_1 ) ;
else
#endif
{
if ( V_1 -> V_27 . V_9 && ( V_1 -> V_27 . V_9 -> V_69 || V_1 -> V_27 . V_9 -> V_55 ) ) {
F_47 ( V_1 ) ;
return;
}
V_1 -> V_137 |= V_234 ;
}
}
}
static void F_125 ( T_1 * V_1 )
{
unsigned char V_253 = F_73 ( V_1 , V_254 ) & V_1 -> V_255 & ( V_291 + V_298 + V_302 ) ;
F_74 ( V_1 , V_254 , V_253 ) ;
if ( V_31 >= V_252 )
F_4 ( L_91 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_253 ) ;
if ( V_253 & ( V_291 + V_298 ) )
F_123 ( V_1 , V_253 ) ;
if ( V_253 & V_302 ) {
F_62 ( V_1 ) ;
F_120 ( V_1 ,
V_303 | ( V_1 -> V_50 & V_123 ) ) ;
}
}
static void F_126 ( T_1 * V_1 )
{
if ( V_31 >= V_252 )
F_4 ( L_92 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_66 ) ;
if ( V_1 -> V_60 . V_61 != V_264 ) {
V_1 -> V_296 &= ~ V_297 ;
V_1 -> V_255 |= V_298 ;
F_124 ( V_1 , V_299 , ( unsigned short ) ( ( V_1 -> V_255 << 8 ) + V_1 -> V_296 ) ) ;
return;
}
if ( V_1 -> V_27 . V_9 && ( V_1 -> V_27 . V_9 -> V_69 || V_1 -> V_27 . V_9 -> V_55 ) ) {
F_47 ( V_1 ) ;
return;
}
if ( V_1 -> V_66 )
F_127 ( V_1 ) ;
else {
V_1 -> V_65 = false ;
V_1 -> V_296 &= ~ V_297 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
}
if ( V_1 -> V_66 < V_304 )
V_1 -> V_137 |= V_234 ;
}
static void F_128 ( T_1 * V_1 )
{
unsigned char V_253 = F_73 ( V_1 , V_305 + V_288 ) & 0xc0 ;
F_74 ( V_1 , V_305 + V_288 , ( unsigned char ) ( V_253 | 1 ) ) ;
if ( V_31 >= V_252 )
F_4 ( L_93 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_253 ) ;
V_1 -> V_137 |= V_233 ;
}
static void F_129 ( T_1 * V_1 )
{
unsigned char V_253 = F_73 ( V_1 , V_305 + V_288 ) & 0x30 ;
F_74 ( V_1 , V_305 + V_288 , ( unsigned char ) ( V_253 | 1 ) ) ;
if ( V_31 >= V_252 )
F_4 ( L_94 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_253 ) ;
V_1 -> V_306 = true ;
V_1 -> V_137 |= V_233 ;
}
static void F_130 ( T_1 * V_1 )
{
unsigned char V_307 = F_73 ( V_1 , V_254 ) ;
F_74 ( V_1 , V_286 + V_287 , 0x00 ) ;
F_74 ( V_1 , V_286 + V_288 , 0xc0 ) ;
F_74 ( V_1 , V_286 + V_289 , V_290 ) ;
if ( V_31 >= V_252 )
F_4 ( L_95 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_307 ) ;
F_124 ( V_1 , V_308 , 0 ) ;
V_1 -> V_296 |= V_297 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
}
static void F_131 ( T_1 * V_1 )
{
unsigned char V_253 = F_73 ( V_1 , V_286 + V_288 ) & 0x30 ;
F_74 ( V_1 , V_286 + V_288 , ( unsigned char ) ( V_253 | 1 ) ) ;
if ( V_31 >= V_252 )
F_4 ( L_96 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_253 ) ;
}
static void F_120 ( T_1 * V_1 , T_7 V_253 )
{
struct V_102 * V_101 ;
if ( V_31 >= V_252 )
F_4 ( L_97 ,
__FILE__ , __LINE__ , V_253 ) ;
if ( V_253 & ( V_303 | V_272 |
V_309 | V_310 ) ) {
V_101 = & V_1 -> V_101 ;
if ( V_253 & V_310 ) {
V_101 -> V_106 ++ ;
if ( V_253 & V_126 )
V_1 -> V_311 . V_312 ++ ;
else
V_1 -> V_311 . V_313 ++ ;
}
if ( V_253 & V_309 ) {
V_101 -> V_105 ++ ;
if ( V_253 & V_124 )
V_1 -> V_311 . V_314 ++ ;
else
V_1 -> V_311 . V_315 ++ ;
}
if ( V_253 & V_272 ) {
if ( ( V_1 -> V_243 ) ++ >= V_316 ) {
V_1 -> V_255 &= ~ V_258 ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
}
V_101 -> V_107 ++ ;
if ( V_253 & V_125 ) {
V_1 -> V_311 . V_318 ++ ;
} else
V_1 -> V_311 . V_319 ++ ;
#if V_301
if ( V_1 -> V_36 ) {
if ( V_253 & V_125 )
F_84 ( V_1 -> V_213 ) ;
else
F_85 ( V_1 -> V_213 ) ;
}
#endif
}
if ( V_253 & V_303 )
{
if ( ( V_1 -> V_244 ) ++ >= V_316 ) {
V_1 -> V_255 &= ~ V_302 ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
}
V_101 -> V_104 ++ ;
if ( V_253 & V_123 )
V_1 -> V_311 . V_320 ++ ;
else
V_1 -> V_311 . V_321 ++ ;
}
F_25 ( & V_1 -> V_322 ) ;
F_25 ( & V_1 -> V_271 ) ;
if ( ( V_1 -> V_27 . V_11 & V_323 ) &&
( V_253 & V_272 ) ) {
if ( V_31 >= V_252 )
F_4 ( L_98 , V_1 -> V_25 ,
( V_253 & V_125 ) ? L_99 : L_100 ) ;
if ( V_253 & V_125 )
F_25 ( & V_1 -> V_27 . V_44 ) ;
else {
if ( V_31 >= V_252 )
F_4 ( L_101 ) ;
if ( V_1 -> V_27 . V_9 )
F_132 ( V_1 -> V_27 . V_9 ) ;
}
}
if ( F_133 ( & V_1 -> V_27 ) &&
( V_253 & V_303 ) ) {
if ( V_1 -> V_27 . V_9 ) {
if ( V_1 -> V_27 . V_9 -> V_55 ) {
if ( V_253 & V_123 ) {
if ( V_31 >= V_252 )
F_4 ( L_102 ) ;
V_1 -> V_27 . V_9 -> V_55 = 0 ;
F_35 ( V_1 ) ;
V_1 -> V_137 |= V_234 ;
return;
}
} else {
if ( ! ( V_253 & V_123 ) ) {
if ( V_31 >= V_252 )
F_4 ( L_103 ) ;
V_1 -> V_27 . V_9 -> V_55 = 1 ;
F_47 ( V_1 ) ;
}
}
}
}
}
V_1 -> V_137 |= V_235 ;
}
static T_8 F_134 ( int V_324 , void * V_325 )
{
T_1 * V_1 = V_325 ;
unsigned char V_253 , V_326 , V_327 = 0 ;
unsigned char V_328 , V_329 , V_330 = 0 ;
unsigned char V_331 , V_332 = 0 ;
unsigned char V_333 ;
unsigned int V_334 ;
unsigned short V_335 ;
if ( V_31 >= V_252 )
F_4 ( V_336 L_104 ,
__FILE__ , __LINE__ , V_1 -> V_122 ) ;
F_135 ( & V_1 -> V_42 ) ;
for(; ; ) {
V_335 = F_136 ( V_1 , V_337 ) ;
V_326 = ( unsigned char ) V_335 ;
V_329 = ( unsigned char ) ( V_335 >> 8 ) ;
V_331 = F_73 ( V_1 , V_338 ) ;
if ( V_31 >= V_252 )
F_4 ( V_336 L_105 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_326 , V_329 , V_331 ) ;
if ( V_1 -> V_339 == 4 ) {
V_335 = F_136 ( V_1 -> V_340 [ 2 ] , V_337 ) ;
V_327 = ( unsigned char ) V_335 ;
V_330 = ( unsigned char ) ( V_335 >> 8 ) ;
V_332 = F_73 ( V_1 -> V_340 [ 2 ] , V_338 ) ;
if ( V_31 >= V_252 )
F_4 ( L_106 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_327 , V_330 , V_332 ) ;
}
if ( ! V_326 && ! V_329 && ! V_331 &&
! V_327 && ! V_330 && ! V_332 )
break;
for( V_334 = 0 ; V_334 < V_1 -> V_339 ; V_334 ++ ) {
if ( V_1 -> V_340 [ V_334 ] == NULL )
continue;
if ( V_334 < 2 ) {
V_253 = V_326 ;
V_328 = V_329 ;
} else {
V_253 = V_327 ;
V_328 = V_330 ;
}
V_333 = V_334 & 1 ? 4 : 0 ;
if ( V_253 & V_275 << V_333 )
F_121 ( V_1 -> V_340 [ V_334 ] ) ;
if ( V_253 & V_341 << V_333 )
F_126 ( V_1 -> V_340 [ V_334 ] ) ;
if ( V_253 & V_342 << V_333 )
F_117 ( V_1 -> V_340 [ V_334 ] ) ;
if ( V_253 & V_145 << V_333 )
F_125 ( V_1 -> V_340 [ V_334 ] ) ;
if ( V_328 & V_275 << V_333 )
F_129 ( V_1 -> V_340 [ V_334 ] ) ;
if ( V_328 & V_341 << V_333 )
F_128 ( V_1 -> V_340 [ V_334 ] ) ;
if ( V_328 & V_342 << V_333 )
F_131 ( V_1 -> V_340 [ V_334 ] ) ;
if ( V_328 & V_145 << V_333 )
F_130 ( V_1 -> V_340 [ V_334 ] ) ;
}
if ( V_331 & ( V_343 | V_344 ) )
F_116 ( V_1 -> V_340 [ 0 ] ) ;
if ( V_331 & ( V_345 | V_346 ) )
F_116 ( V_1 -> V_340 [ 1 ] ) ;
if ( V_332 & ( V_343 | V_344 ) )
F_116 ( V_1 -> V_340 [ 2 ] ) ;
if ( V_332 & ( V_345 | V_346 ) )
F_116 ( V_1 -> V_340 [ 3 ] ) ;
}
for( V_334 = 0 ; V_334 < V_1 -> V_339 ; V_334 ++ ) {
T_1 * V_27 = V_1 -> V_340 [ V_334 ] ;
if ( V_27 && ( V_27 -> V_27 . V_12 || V_27 -> V_36 ) &&
V_27 -> V_137 && ! V_27 -> V_136 &&
! V_27 -> V_135 ) {
if ( V_31 >= V_252 )
F_4 ( L_107 ,
__FILE__ , __LINE__ , V_27 -> V_25 ) ;
F_137 ( & V_27 -> V_238 ) ;
V_27 -> V_135 = true ;
}
}
F_138 ( & V_1 -> V_42 ) ;
if ( V_31 >= V_252 )
F_4 ( V_336 L_108 ,
__FILE__ , __LINE__ , V_1 -> V_122 ) ;
return V_347 ;
}
static int F_13 ( T_1 * V_1 )
{
if ( V_31 >= V_32 )
F_4 ( L_109 , __FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_1 -> V_27 . V_11 & V_40 )
return 0 ;
if ( ! V_1 -> V_59 ) {
V_1 -> V_59 = F_139 ( V_1 -> V_63 , V_348 ) ;
if ( ! V_1 -> V_59 ) {
F_4 ( V_220 L_110 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_221 ;
}
}
V_1 -> V_137 = 0 ;
memset ( & V_1 -> V_101 , 0 , sizeof( V_1 -> V_101 ) ) ;
F_140 ( V_1 ) ;
F_27 ( V_1 ) ;
F_141 ( & V_1 -> V_349 , V_76 + F_142 ( 10 ) ) ;
if ( V_1 -> V_27 . V_9 )
F_143 ( V_88 , & V_1 -> V_27 . V_9 -> V_11 ) ;
V_1 -> V_27 . V_11 |= V_40 ;
return 0 ;
}
static void F_21 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( ! ( V_1 -> V_27 . V_11 & V_40 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_111 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_25 ( & V_1 -> V_322 ) ;
F_25 ( & V_1 -> V_271 ) ;
F_44 ( & V_1 -> V_81 ) ;
F_44 ( & V_1 -> V_349 ) ;
F_144 ( V_1 -> V_59 ) ;
V_1 -> V_59 = NULL ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_140 ( V_1 ) ;
if ( ! V_1 -> V_27 . V_9 || V_1 -> V_27 . V_9 -> V_49 . V_47 & V_350 ) {
V_1 -> V_50 &= ~ ( V_51 | V_52 ) ;
F_28 ( V_1 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_27 . V_9 )
F_145 ( V_88 , & V_1 -> V_27 . V_9 -> V_11 ) ;
V_1 -> V_27 . V_11 &= ~ V_40 ;
}
static void F_77 ( T_1 * V_1 )
{
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_146 ( V_1 ) ;
F_47 ( V_1 ) ;
V_1 -> V_66 = V_1 -> V_68 = V_1 -> V_80 = 0 ;
if ( V_1 -> V_60 . V_61 == V_62 || V_1 -> V_36 )
F_147 ( V_1 ) ;
else
F_148 ( V_1 ) ;
F_28 ( V_1 ) ;
V_1 -> V_243 = 0 ;
V_1 -> V_244 = 0 ;
V_1 -> V_241 = 0 ;
V_1 -> V_242 = 0 ;
V_1 -> V_255 |= ( V_258 | V_302 ) ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
F_62 ( V_1 ) ;
if ( V_1 -> V_36 || ( V_1 -> V_27 . V_9 && V_1 -> V_27 . V_9 -> V_49 . V_47 & V_351 ) )
F_149 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
static void F_27 ( T_1 * V_1 )
{
unsigned V_352 ;
int V_353 ;
if ( ! V_1 -> V_27 . V_9 )
return;
if ( V_31 >= V_32 )
F_4 ( L_112 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_352 = V_1 -> V_27 . V_9 -> V_49 . V_47 ;
if ( V_352 & V_48 )
V_1 -> V_50 |= V_51 | V_52 ;
else
V_1 -> V_50 &= ~ ( V_51 | V_52 ) ;
switch ( V_352 & V_354 ) {
case V_355 : V_1 -> V_60 . V_356 = 5 ; break;
case V_357 : V_1 -> V_60 . V_356 = 6 ; break;
case V_358 : V_1 -> V_60 . V_356 = 7 ; break;
case V_359 : V_1 -> V_60 . V_356 = 8 ; break;
default: V_1 -> V_60 . V_356 = 7 ; break;
}
if ( V_352 & V_360 )
V_1 -> V_60 . V_361 = 2 ;
else
V_1 -> V_60 . V_361 = 1 ;
V_1 -> V_60 . V_112 = V_362 ;
if ( V_352 & V_363 ) {
if ( V_352 & V_364 )
V_1 -> V_60 . V_112 = V_365 ;
else
V_1 -> V_60 . V_112 = V_366 ;
#ifdef F_150
if ( V_352 & F_150 )
V_1 -> V_60 . V_112 = V_367 ;
#endif
}
V_353 = V_1 -> V_60 . V_356 +
V_1 -> V_60 . V_361 + 1 ;
if ( V_1 -> V_60 . V_77 <= 460800 ) {
V_1 -> V_60 . V_77 = F_151 ( V_1 -> V_27 . V_9 ) ;
}
if ( V_1 -> V_60 . V_77 ) {
V_1 -> V_41 = ( 32 * V_229 * V_353 ) /
V_1 -> V_60 . V_77 ;
}
V_1 -> V_41 += V_229 / 50 ;
if ( V_352 & V_53 )
V_1 -> V_27 . V_11 |= V_368 ;
else
V_1 -> V_27 . V_11 &= ~ V_368 ;
if ( V_352 & V_369 )
V_1 -> V_27 . V_11 &= ~ V_323 ;
else
V_1 -> V_27 . V_11 |= V_323 ;
V_1 -> V_282 = V_263 ;
if ( F_152 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_282 |= V_279 | V_280 ;
if ( F_153 ( V_1 -> V_27 . V_9 ) || F_154 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_266 |= V_259 ;
if ( F_155 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_281 |= V_279 | V_280 ;
if ( F_156 ( V_1 -> V_27 . V_9 ) ) {
V_1 -> V_265 |= V_259 ;
if ( F_155 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_281 |= V_263 ;
}
F_77 ( V_1 ) ;
}
static int F_56 ( T_1 * V_1 , struct V_102 T_3 * V_370 )
{
int V_371 ;
if ( V_31 >= V_32 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( ! V_370 ) {
memset ( & V_1 -> V_101 , 0 , sizeof( V_1 -> V_101 ) ) ;
} else {
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_157 ( V_371 , V_370 , & V_1 -> V_101 , sizeof( struct V_102 ) ) ;
F_22 ( & V_1 -> V_27 . V_39 ) ;
if ( V_371 )
return - V_208 ;
}
return 0 ;
}
static int F_49 ( T_1 * V_1 , T_9 T_3 * V_372 )
{
int V_371 ;
if ( V_31 >= V_32 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_157 ( V_371 , V_372 , & V_1 -> V_60 , sizeof( T_9 ) ) ;
F_22 ( & V_1 -> V_27 . V_39 ) ;
if ( V_371 ) {
if ( V_31 >= V_32 )
F_4 ( L_114 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_208 ;
}
return 0 ;
}
static int F_50 ( T_1 * V_1 , T_9 T_3 * V_373 )
{
unsigned long V_11 ;
T_9 V_374 ;
int V_371 ;
if ( V_31 >= V_32 )
F_4 ( L_115 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_158 ( V_371 , & V_374 , V_373 , sizeof( T_9 ) ) ;
if ( V_371 ) {
if ( V_31 >= V_32 )
F_4 ( L_116 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_208 ;
}
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
memcpy ( & V_1 -> V_60 , & V_374 , sizeof( T_9 ) ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
F_27 ( V_1 ) ;
F_22 ( & V_1 -> V_27 . V_39 ) ;
return 0 ;
}
static int F_51 ( T_1 * V_1 , int T_3 * V_375 )
{
int V_371 ;
if ( V_31 >= V_32 )
F_4 ( L_117 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_375 ) ;
F_157 ( V_371 , V_375 , & V_1 -> V_375 , sizeof( int ) ) ;
if ( V_371 ) {
if ( V_31 >= V_32 )
F_4 ( L_118 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_208 ;
}
return 0 ;
}
static int F_52 ( T_1 * V_1 , int V_375 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_119 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_375 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_375 = V_375 ;
F_159 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_53 ( T_1 * V_1 , int V_376 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_120 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_376 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_376 ) {
if ( ! V_1 -> V_72 ) {
F_35 ( V_1 ) ;
}
} else {
if ( V_1 -> V_72 )
F_47 ( V_1 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_55 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_121 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_65 && V_1 -> V_60 . V_61 == V_62 ) {
V_1 -> V_255 &= ~ V_291 ;
V_1 -> V_255 |= V_298 ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
F_74 ( V_1 , V_254 , ( unsigned char ) ( V_298 + V_291 ) ) ;
F_74 ( V_1 , V_286 + V_288 , 0 ) ;
F_74 ( V_1 , V_286 + V_289 , V_290 ) ;
F_74 ( V_1 , V_292 , V_377 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_54 ( T_1 * V_1 , int V_376 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_122 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_376 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_376 ) {
if ( ! V_1 -> V_378 )
F_149 ( V_1 ) ;
} else {
if ( V_1 -> V_378 )
F_146 ( V_1 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_57 ( T_1 * V_1 , int T_3 * V_379 )
{
unsigned long V_11 ;
int V_380 ;
int V_177 = 0 ;
struct V_102 V_381 , V_103 ;
int V_382 ;
int V_383 ;
struct V_384 V_385 , V_386 ;
F_160 ( V_387 , V_78 ) ;
F_158 ( V_177 , & V_383 , V_379 , sizeof( int ) ) ;
if ( V_177 ) {
return - V_208 ;
}
if ( V_31 >= V_32 )
F_4 ( L_123 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_383 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_62 ( V_1 ) ;
V_380 = V_1 -> V_50 ;
V_382 = V_383 &
( ( ( V_380 & V_124 ) ? V_388 : V_389 ) +
( ( V_380 & V_125 ) ? V_390 : V_391 ) +
( ( V_380 & V_123 ) ? V_392 : V_393 ) +
( ( V_380 & V_126 ) ? V_394 : V_395 ) ) ;
if ( V_382 ) {
F_12 ( & V_1 -> V_42 , V_11 ) ;
goto exit;
}
V_381 = V_1 -> V_101 ;
V_385 = V_1 -> V_311 ;
if ( V_383 & ( V_396 + V_397 ) ) {
unsigned char V_398 = V_1 -> V_255 ;
unsigned char V_399 = V_398 +
( V_383 & V_396 ? V_256 : 0 ) +
( V_383 & V_397 ? V_257 : 0 ) ;
if ( V_398 != V_399 ) {
V_1 -> V_255 = V_399 ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
}
}
F_161 ( V_400 ) ;
F_162 ( & V_1 -> V_271 , & V_387 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
for(; ; ) {
F_163 () ;
if ( F_40 ( V_78 ) ) {
V_177 = - V_401 ;
break;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_103 = V_1 -> V_101 ;
V_386 = V_1 -> V_311 ;
F_161 ( V_400 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
if ( V_386 . V_314 == V_385 . V_314 &&
V_386 . V_315 == V_385 . V_315 &&
V_386 . V_318 == V_385 . V_318 &&
V_386 . V_319 == V_385 . V_319 &&
V_386 . V_320 == V_385 . V_320 &&
V_386 . V_321 == V_385 . V_321 &&
V_386 . V_312 == V_385 . V_312 &&
V_386 . V_313 == V_385 . V_313 &&
V_103 . V_269 == V_381 . V_269 &&
V_103 . V_270 == V_381 . V_270 ) {
V_177 = - V_64 ;
break;
}
V_382 = V_383 &
( ( V_386 . V_314 != V_385 . V_314 ? V_388 : 0 ) +
( V_386 . V_315 != V_385 . V_315 ? V_389 : 0 ) +
( V_386 . V_318 != V_385 . V_318 ? V_390 : 0 ) +
( V_386 . V_319 != V_385 . V_319 ? V_391 : 0 ) +
( V_386 . V_320 != V_385 . V_320 ? V_392 : 0 ) +
( V_386 . V_321 != V_385 . V_321 ? V_393 : 0 ) +
( V_386 . V_312 != V_385 . V_312 ? V_394 : 0 ) +
( V_386 . V_313 != V_385 . V_313 ? V_395 : 0 ) +
( V_103 . V_269 != V_381 . V_269 ? V_396 : 0 ) +
( V_103 . V_270 != V_381 . V_270 ? V_397 : 0 ) ) ;
if ( V_382 )
break;
V_381 = V_103 ;
V_385 = V_386 ;
}
F_164 ( & V_1 -> V_271 , & V_387 ) ;
F_161 ( V_402 ) ;
if ( V_383 & ( V_396 + V_397 ) ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! F_165 ( & V_1 -> V_271 ) ) {
V_1 -> V_255 &= ~ ( V_256 | V_257 ) ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
exit:
if ( V_177 == 0 )
F_166 ( V_177 , V_382 , V_379 ) ;
return V_177 ;
}
static int F_58 ( T_1 * V_1 , int V_83 )
{
unsigned long V_11 ;
int V_177 ;
struct V_102 V_381 , V_103 ;
F_160 ( V_387 , V_78 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_381 = V_1 -> V_101 ;
F_162 ( & V_1 -> V_322 , & V_387 ) ;
F_161 ( V_400 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
for(; ; ) {
F_163 () ;
if ( F_40 ( V_78 ) ) {
V_177 = - V_401 ;
break;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_103 = V_1 -> V_101 ;
F_161 ( V_400 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
if ( V_103 . V_106 == V_381 . V_106 && V_103 . V_105 == V_381 . V_105 &&
V_103 . V_107 == V_381 . V_107 && V_103 . V_104 == V_381 . V_104 ) {
V_177 = - V_64 ;
break;
}
if ( ( V_83 & V_403 && V_103 . V_106 != V_381 . V_106 ) ||
( V_83 & V_404 && V_103 . V_105 != V_381 . V_105 ) ||
( V_83 & V_405 && V_103 . V_107 != V_381 . V_107 ) ||
( V_83 & V_406 && V_103 . V_104 != V_381 . V_104 ) ) {
V_177 = 0 ;
break;
}
V_381 = V_103 ;
}
F_164 ( & V_1 -> V_322 , & V_387 ) ;
F_161 ( V_402 ) ;
return V_177 ;
}
static int F_167 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned int V_407 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_407 = ( ( V_1 -> V_50 & V_51 ) ? V_408 : 0 ) |
( ( V_1 -> V_50 & V_52 ) ? V_409 : 0 ) |
( ( V_1 -> V_50 & V_125 ) ? V_410 : 0 ) |
( ( V_1 -> V_50 & V_126 ) ? V_403 : 0 ) |
( ( V_1 -> V_50 & V_124 ) ? V_404 : 0 ) |
( ( V_1 -> V_50 & V_123 ) ? V_406 : 0 ) ;
if ( V_31 >= V_32 )
F_4 ( L_124 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_407 ) ;
return V_407 ;
}
static int F_168 ( struct V_8 * V_9 ,
unsigned int V_411 , unsigned int V_412 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_125 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_411 , V_412 ) ;
if ( V_411 & V_408 )
V_1 -> V_50 |= V_51 ;
if ( V_411 & V_409 )
V_1 -> V_50 |= V_52 ;
if ( V_412 & V_408 )
V_1 -> V_50 &= ~ V_51 ;
if ( V_412 & V_409 )
V_1 -> V_50 &= ~ V_52 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_169 ( struct V_413 * V_27 )
{
T_1 * V_1 = F_111 ( V_27 , T_1 , V_27 ) ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return ( V_1 -> V_50 & V_125 ) ? 1 : 0 ;
}
static void F_170 ( struct V_413 * V_27 , int V_414 )
{
T_1 * V_1 = F_111 ( V_27 , T_1 , V_27 ) ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_414 )
V_1 -> V_50 |= V_51 | V_52 ;
else
V_1 -> V_50 &= ~ ( V_51 | V_52 ) ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
static int F_14 ( struct V_8 * V_9 , struct V_28 * V_29 ,
T_1 * V_1 )
{
F_160 ( V_387 , V_78 ) ;
int V_30 ;
bool V_415 = false ;
unsigned long V_11 ;
int V_416 ;
struct V_413 * V_27 = & V_1 -> V_27 ;
if ( V_31 >= V_32 )
F_4 ( L_126 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 ) ;
if ( V_29 -> V_417 & V_418 || V_9 -> V_11 & ( 1 << V_88 ) ) {
V_27 -> V_11 |= V_43 ;
return 0 ;
}
if ( V_9 -> V_49 . V_47 & V_369 )
V_415 = true ;
V_30 = 0 ;
F_162 ( & V_27 -> V_44 , & V_387 ) ;
if ( V_31 >= V_32 )
F_4 ( L_127 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_27 -> V_12 -- ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_27 -> V_419 ++ ;
while ( 1 ) {
if ( F_171 ( V_9 ) && F_29 ( V_75 , & V_27 -> V_11 ) )
F_172 ( V_27 ) ;
F_161 ( V_400 ) ;
if ( F_173 ( V_29 ) || ! ( V_27 -> V_11 & V_40 ) ) {
V_30 = ( V_27 -> V_11 & V_420 ) ?
- V_421 : - V_401 ;
break;
}
V_416 = F_174 ( V_27 ) ;
if ( V_415 || V_416 )
break;
if ( F_40 ( V_78 ) ) {
V_30 = - V_401 ;
break;
}
if ( V_31 >= V_32 )
F_4 ( L_128 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
F_175 ( V_9 ) ;
F_163 () ;
F_176 ( V_9 ) ;
}
F_161 ( V_402 ) ;
F_164 ( & V_27 -> V_44 , & V_387 ) ;
if ( ! F_173 ( V_29 ) )
V_27 -> V_12 ++ ;
V_27 -> V_419 -- ;
if ( V_31 >= V_32 )
F_4 ( L_129 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
if ( ! V_30 )
V_27 -> V_11 |= V_43 ;
return V_30 ;
}
static int F_177 ( T_1 * V_1 )
{
unsigned short V_422 ;
unsigned short V_423 ;
V_1 -> V_340 [ 0 ] -> V_424 = ( V_425 / 4 ) * V_1 -> V_246 ;
V_422 = ( unsigned short ) ( V_1 -> V_63 / V_426 ) ;
if ( V_1 -> V_63 % V_426 )
V_422 ++ ;
V_423 = ( V_425 / 4 - V_427 ) / V_426 ;
if ( V_423 > V_427 / sizeof( V_428 ) )
V_423 = V_427 / sizeof( V_428 ) ;
V_1 -> V_429 = V_422 + 1 ;
if ( V_1 -> V_429 > ( V_423 / 2 ) )
V_1 -> V_429 = V_423 / 2 ;
if ( V_1 -> V_429 > V_430 )
V_1 -> V_429 = V_430 ;
V_1 -> V_431 = V_423 - V_1 -> V_429 ;
if ( V_1 -> V_431 > V_430 )
V_1 -> V_431 = V_430 ;
if ( V_31 >= V_32 )
F_4 ( L_130 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_1 -> V_429 , V_1 -> V_431 ) ;
if ( F_178 ( V_1 ) < 0 ||
F_179 ( V_1 ,
V_1 -> V_432 ,
V_1 -> V_433 ,
V_1 -> V_431 ) < 0 ||
F_179 ( V_1 ,
V_1 -> V_434 ,
V_1 -> V_435 ,
V_1 -> V_429 ) < 0 ||
F_180 ( V_1 ) < 0 ) {
F_4 ( L_131 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_221 ;
}
F_181 ( V_1 ) ;
return 0 ;
}
static int F_178 ( T_1 * V_1 )
{
unsigned int V_334 ;
V_1 -> V_436 = V_1 -> V_437 + V_1 -> V_340 [ 0 ] -> V_424 ;
V_1 -> V_438 = V_1 -> V_340 [ 0 ] -> V_424 ;
V_1 -> V_340 [ 0 ] -> V_424 += V_427 ;
memset ( V_1 -> V_436 , 0 , V_427 ) ;
V_1 -> V_432 = ( V_428 * ) V_1 -> V_436 ;
V_1 -> V_434 = ( V_428 * ) V_1 -> V_436 ;
V_1 -> V_434 += V_1 -> V_431 ;
for ( V_334 = 0 ; V_334 < V_1 -> V_431 ; V_334 ++ ) {
V_1 -> V_433 [ V_334 ] . V_439 =
V_1 -> V_438 + ( V_334 * V_426 ) ;
V_1 -> V_432 [ V_334 ] . V_440 = V_1 -> V_438 ;
if ( V_334 < V_1 -> V_431 - 1 )
V_1 -> V_432 [ V_334 ] . V_440 += ( V_334 + 1 ) * sizeof( V_428 ) ;
V_1 -> V_432 [ V_334 ] . V_441 = V_426 ;
}
for ( V_334 = 0 ; V_334 < V_1 -> V_429 ; V_334 ++ ) {
V_1 -> V_435 [ V_334 ] . V_439 = V_1 -> V_438 +
( ( V_1 -> V_431 + V_334 ) * sizeof( V_428 ) ) ;
V_1 -> V_434 [ V_334 ] . V_440 = V_1 -> V_438 +
V_1 -> V_431 * sizeof( V_428 ) ;
if ( V_334 < V_1 -> V_429 - 1 )
V_1 -> V_434 [ V_334 ] . V_440 += ( V_334 + 1 ) * sizeof( V_428 ) ;
}
return 0 ;
}
static int F_179 ( T_1 * V_1 , V_428 * V_442 , T_10 * V_443 , int V_12 )
{
int V_334 ;
unsigned long V_444 ;
for ( V_334 = 0 ; V_334 < V_12 ; V_334 ++ ) {
V_443 [ V_334 ] . V_445 = V_1 -> V_437 + V_1 -> V_340 [ 0 ] -> V_424 ;
V_444 = V_1 -> V_340 [ 0 ] -> V_424 ;
V_1 -> V_340 [ 0 ] -> V_424 += V_426 ;
V_442 [ V_334 ] . V_446 = ( unsigned short ) V_444 ;
V_442 [ V_334 ] . V_447 = ( unsigned char ) ( V_444 >> 16 ) ;
}
return 0 ;
}
static void F_182 ( T_1 * V_1 )
{
V_1 -> V_436 = NULL ;
V_1 -> V_432 = NULL ;
V_1 -> V_434 = NULL ;
}
static int F_180 ( T_1 * V_1 )
{
V_1 -> V_448 = F_139 ( V_1 -> V_63 , V_348 ) ;
if ( V_1 -> V_448 == NULL )
return - V_221 ;
V_1 -> V_449 = F_183 ( V_1 -> V_63 , V_348 ) ;
if ( ! V_1 -> V_449 ) {
F_144 ( V_1 -> V_448 ) ;
V_1 -> V_448 = NULL ;
return - V_221 ;
}
return 0 ;
}
static void F_184 ( T_1 * V_1 )
{
F_144 ( V_1 -> V_448 ) ;
V_1 -> V_448 = NULL ;
F_144 ( V_1 -> V_449 ) ;
V_1 -> V_449 = NULL ;
}
static int F_185 ( T_1 * V_1 )
{
if ( F_186 ( V_1 -> V_119 , V_425 , L_132 ) == NULL ) {
F_4 ( L_133 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_119 ) ;
V_1 -> V_24 = V_450 ;
goto V_451;
}
else
V_1 -> V_452 = true ;
if ( F_186 ( V_1 -> V_121 + V_1 -> V_453 , 128 , L_132 ) == NULL ) {
F_4 ( L_134 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_121 ) ;
V_1 -> V_24 = V_450 ;
goto V_451;
}
else
V_1 -> V_454 = true ;
if ( F_186 ( V_1 -> V_118 + V_1 -> V_455 , V_224 , L_132 ) == NULL ) {
F_4 ( L_135 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_118 ) ;
V_1 -> V_24 = V_450 ;
goto V_451;
}
else
V_1 -> V_456 = true ;
if ( F_186 ( V_1 -> V_120 + V_1 -> V_457 , V_458 , L_132 ) == NULL ) {
F_4 ( L_136 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_120 ) ;
V_1 -> V_24 = V_450 ;
goto V_451;
}
else
V_1 -> V_459 = true ;
V_1 -> V_437 = F_187 ( V_1 -> V_119 ,
V_425 ) ;
if ( ! V_1 -> V_437 ) {
F_4 ( L_137 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_119 ) ;
V_1 -> V_24 = V_460 ;
goto V_451;
}
V_1 -> V_461 = F_187 ( V_1 -> V_121 , V_462 ) ;
if ( ! V_1 -> V_461 ) {
F_4 ( L_138 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_121 ) ;
V_1 -> V_24 = V_460 ;
goto V_451;
}
V_1 -> V_461 += V_1 -> V_453 ;
V_1 -> V_463 = F_187 ( V_1 -> V_118 , V_462 ) ;
if ( ! V_1 -> V_463 ) {
F_4 ( L_139 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_118 ) ;
V_1 -> V_24 = V_460 ;
goto V_451;
}
V_1 -> V_463 += V_1 -> V_455 ;
V_1 -> V_464 = F_187 ( V_1 -> V_120 ,
V_462 ) ;
if ( ! V_1 -> V_464 ) {
F_4 ( L_140 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_120 ) ;
V_1 -> V_24 = V_460 ;
goto V_451;
}
V_1 -> V_464 += V_1 -> V_457 ;
if ( ! F_188 ( V_1 ) ) {
F_4 ( L_141 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_119 ) ;
V_1 -> V_24 = V_465 ;
goto V_451;
}
return 0 ;
V_451:
F_189 ( V_1 ) ;
return - V_21 ;
}
static void F_189 ( T_1 * V_1 )
{
if ( V_31 >= V_32 )
F_4 ( L_142 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_1 -> V_466 ) {
F_190 ( V_1 -> V_122 , V_1 ) ;
V_1 -> V_466 = false ;
}
if ( V_1 -> V_452 ) {
F_191 ( V_1 -> V_119 , V_425 ) ;
V_1 -> V_452 = false ;
}
if ( V_1 -> V_454 ) {
F_191 ( V_1 -> V_121 + V_1 -> V_453 , 128 ) ;
V_1 -> V_454 = false ;
}
if ( V_1 -> V_456 ) {
F_191 ( V_1 -> V_118 + V_1 -> V_455 , V_224 ) ;
V_1 -> V_456 = false ;
}
if ( V_1 -> V_459 ) {
F_191 ( V_1 -> V_120 + V_1 -> V_457 , V_458 ) ;
V_1 -> V_459 = false ;
}
if ( V_1 -> V_437 ) {
F_192 ( V_1 -> V_437 ) ;
V_1 -> V_437 = NULL ;
}
if ( V_1 -> V_463 ) {
F_192 ( V_1 -> V_463 - V_1 -> V_455 ) ;
V_1 -> V_463 = NULL ;
}
if ( V_1 -> V_464 ) {
F_192 ( V_1 -> V_464 - V_1 -> V_457 ) ;
V_1 -> V_464 = NULL ;
}
if ( V_1 -> V_461 ) {
F_192 ( V_1 -> V_461 - V_1 -> V_453 ) ;
V_1 -> V_461 = NULL ;
}
if ( V_31 >= V_32 )
F_4 ( L_143 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_193 ( T_1 * V_1 )
{
V_1 -> V_23 = NULL ;
V_1 -> line = V_20 ;
sprintf ( V_1 -> V_25 , L_144 , V_1 -> V_467 , V_1 -> V_246 ) ;
if ( V_1 -> line < V_468 ) {
if ( V_469 [ V_1 -> line ] )
V_1 -> V_63 = V_469 [ V_1 -> line ] ;
}
V_20 ++ ;
if ( ! V_22 )
V_22 = V_1 ;
else {
T_1 * V_470 = V_22 ;
while( V_470 -> V_23 )
V_470 = V_470 -> V_23 ;
V_470 -> V_23 = V_1 ;
}
if ( V_1 -> V_63 < 4096 )
V_1 -> V_63 = 4096 ;
else if ( V_1 -> V_63 > 65535 )
V_1 -> V_63 = 65535 ;
F_4 ( L_145
L_146 ,
V_1 -> V_25 ,
V_1 -> V_118 ,
V_1 -> V_119 ,
V_1 -> V_120 ,
V_1 -> V_121 ,
V_1 -> V_122 ,
V_1 -> V_63 ) ;
#if V_301
F_102 ( V_1 ) ;
#endif
}
static T_1 * F_194 ( int V_467 , int V_246 , struct V_471 * V_472 )
{
T_1 * V_1 ;
V_1 = F_183 ( sizeof( T_1 ) ,
V_348 ) ;
if ( ! V_1 ) {
F_4 ( L_147 ,
__FILE__ , __LINE__ , V_467 , V_246 ) ;
} else {
F_195 ( & V_1 -> V_27 ) ;
V_1 -> V_27 . V_15 = & V_473 ;
V_1 -> V_6 = V_7 ;
F_196 ( & V_1 -> V_238 , F_110 ) ;
V_1 -> V_63 = 4096 ;
V_1 -> V_27 . V_474 = 5 * V_229 / 10 ;
V_1 -> V_27 . V_475 = 30 * V_229 ;
F_197 ( & V_1 -> V_322 ) ;
F_197 ( & V_1 -> V_271 ) ;
F_198 ( & V_1 -> V_35 ) ;
memcpy ( & V_1 -> V_60 , & V_476 , sizeof( T_9 ) ) ;
V_1 -> V_375 = V_477 ;
V_1 -> V_467 = V_467 ;
V_1 -> V_246 = V_246 ;
V_1 -> V_122 = V_472 -> V_225 ;
V_1 -> V_121 = F_199 ( V_472 , 0 ) ;
V_1 -> V_118 = F_199 ( V_472 , 2 ) ;
V_1 -> V_119 = F_199 ( V_472 , 3 ) ;
V_1 -> V_120 = F_199 ( V_472 , 4 ) ;
V_1 -> V_453 = V_1 -> V_121 & ( V_462 - 1 ) ;
V_1 -> V_121 &= ~ ( V_462 - 1 ) ;
V_1 -> V_455 = V_1 -> V_118 & ( V_462 - 1 ) ;
V_1 -> V_118 &= ~ ( V_462 - 1 ) ;
V_1 -> V_457 = V_1 -> V_120 & ( V_462 - 1 ) ;
V_1 -> V_120 &= ~ ( V_462 - 1 ) ;
V_1 -> V_478 = V_479 ;
V_1 -> V_480 = V_481 ;
F_200 ( & V_1 -> V_81 , V_482 , ( unsigned long ) V_1 ) ;
F_200 ( & V_1 -> V_349 , V_483 ,
( unsigned long ) V_1 ) ;
V_1 -> V_484 = 0x087e4546 ;
V_1 -> V_24 = - 1 ;
}
return V_1 ;
}
static void F_201 ( int V_467 , struct V_471 * V_472 )
{
T_1 * V_340 [ V_485 ] ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_485 ; ++ V_27 ) {
V_340 [ V_27 ] = F_194 ( V_467 , V_27 , V_472 ) ;
if( V_340 [ V_27 ] == NULL ) {
for ( -- V_27 ; V_27 >= 0 ; -- V_27 ) {
F_202 ( & V_340 [ V_27 ] -> V_27 ) ;
F_144 ( V_340 [ V_27 ] ) ;
}
return;
}
}
for ( V_27 = 0 ; V_27 < V_485 ; ++ V_27 ) {
memcpy ( V_340 [ V_27 ] -> V_340 , V_340 , sizeof( V_340 ) ) ;
F_193 ( V_340 [ V_27 ] ) ;
F_198 ( & V_340 [ V_27 ] -> V_42 ) ;
}
if ( ! F_185 ( V_340 [ 0 ] ) ) {
F_177 ( V_340 [ 0 ] ) ;
for ( V_27 = 1 ; V_27 < V_485 ; ++ V_27 ) {
V_340 [ V_27 ] -> V_42 = V_340 [ 0 ] -> V_42 ;
V_340 [ V_27 ] -> V_122 = V_340 [ 0 ] -> V_122 ;
V_340 [ V_27 ] -> V_437 = V_340 [ 0 ] -> V_437 ;
V_340 [ V_27 ] -> V_463 = V_340 [ 0 ] -> V_463 ;
V_340 [ V_27 ] -> V_464 = V_340 [ 0 ] -> V_464 ;
V_340 [ V_27 ] -> V_461 = V_340 [ 0 ] -> V_461 ;
F_177 ( V_340 [ V_27 ] ) ;
}
if ( F_203 ( V_340 [ 0 ] -> V_122 ,
F_134 ,
V_340 [ 0 ] -> V_480 ,
V_340 [ 0 ] -> V_25 ,
V_340 [ 0 ] ) < 0 ) {
F_4 ( L_148 ,
__FILE__ , __LINE__ ,
V_340 [ 0 ] -> V_25 ,
V_340 [ 0 ] -> V_122 ) ;
}
else {
V_340 [ 0 ] -> V_466 = true ;
F_204 ( V_340 [ 0 ] ) ;
}
}
}
static void F_205 ( void )
{
int V_177 ;
T_1 * V_1 ;
T_1 * V_335 ;
F_4 ( L_149 , V_486 , V_139 ) ;
if ( V_487 ) {
V_177 = F_206 ( V_487 ) ;
if ( V_177 )
F_4 ( L_150 ,
__FILE__ , __LINE__ , V_177 ) ;
F_207 ( V_487 ) ;
}
V_1 = V_22 ;
while( V_1 ) {
F_140 ( V_1 ) ;
V_1 = V_1 -> V_23 ;
}
V_1 = V_22 ;
while( V_1 ) {
#if V_301
F_107 ( V_1 ) ;
#endif
F_182 ( V_1 ) ;
F_184 ( V_1 ) ;
if ( V_1 -> V_246 == 0 ) {
if ( V_1 -> V_463 )
F_74 ( V_1 , V_488 , 1 ) ;
F_189 ( V_1 ) ;
}
V_335 = V_1 ;
V_1 = V_1 -> V_23 ;
F_202 ( & V_335 -> V_27 ) ;
F_144 ( V_335 ) ;
}
F_208 ( & V_489 ) ;
}
static int T_11 F_209 ( void )
{
int V_177 ;
if ( V_490 ) {
F_1 () ;
F_210 () ;
}
F_4 ( L_151 , V_486 , V_139 ) ;
if ( ( V_177 = F_211 ( & V_489 ) ) < 0 ) {
F_4 ( L_152 , __FILE__ , V_177 ) ;
return V_177 ;
}
V_487 = F_212 ( 128 ) ;
if ( ! V_487 ) {
V_177 = - V_221 ;
goto error;
}
V_487 -> V_486 = L_132 ;
V_487 -> V_2 = L_153 ;
V_487 -> V_491 = V_492 ;
V_487 -> V_493 = 64 ;
V_487 -> type = V_494 ;
V_487 -> V_495 = V_496 ;
V_487 -> V_497 = V_498 ;
V_487 -> V_497 . V_47 =
V_499 | V_359 | V_351 | V_350 | V_369 ;
V_487 -> V_497 . V_500 = 9600 ;
V_487 -> V_497 . V_501 = 9600 ;
V_487 -> V_11 = V_502 ;
F_213 ( V_487 , & V_15 ) ;
if ( ( V_177 = F_214 ( V_487 ) ) < 0 ) {
F_4 ( L_154 ,
__FILE__ , __LINE__ ) ;
F_207 ( V_487 ) ;
V_487 = NULL ;
goto error;
}
F_4 ( L_155 ,
V_486 , V_139 ,
V_487 -> V_491 ) ;
return 0 ;
error:
F_205 () ;
return V_177 ;
}
static void T_12 F_215 ( void )
{
F_205 () ;
}
static void F_216 ( T_1 * V_1 , int V_376 )
{
if ( V_376 ) {
F_74 ( V_1 , V_503 , ( unsigned char ) ( F_73 ( V_1 , V_503 ) | ( V_341 + V_275 ) ) ) ;
V_1 -> V_340 [ 0 ] -> V_504 |= ( V_275 << ( V_1 -> V_246 * 2 ) ) ;
F_217 ( V_1 ) ;
F_74 ( V_1 , V_505 , 0x40 ) ;
F_74 ( V_1 , V_506 , 0x40 ) ;
} else {
F_74 ( V_1 , V_503 , ( unsigned char ) ( F_73 ( V_1 , V_503 ) & ~ ( V_341 + V_275 ) ) ) ;
F_74 ( V_1 , V_505 , 0x00 ) ;
F_74 ( V_1 , V_506 , 0x00 ) ;
}
if ( V_1 -> V_60 . V_206 )
F_218 ( V_1 , V_1 -> V_60 . V_206 ) ;
else
F_218 ( V_1 , 3686400 ) ;
}
static void F_218 ( T_1 * V_1 , T_13 V_77 )
{
T_13 V_507 ;
unsigned char V_508 ;
T_13 V_509 = 0 ;
if ( V_77 != 0 ) {
V_509 = 14745600 / V_77 ;
if ( ! V_509 )
V_509 = 1 ;
V_507 = V_509 ;
V_508 = 0 ;
if ( V_507 != 1 && V_507 != 2 ) {
V_508 = 1 ;
V_507 >>= 1 ;
}
for(; V_507 > 256 && V_508 < 10 ; V_508 ++ )
V_507 >>= 1 ;
F_74 ( V_1 , V_506 ,
( unsigned char ) ( ( F_73 ( V_1 , V_506 ) & 0xf0 ) | V_508 ) ) ;
F_74 ( V_1 , V_505 ,
( unsigned char ) ( ( F_73 ( V_1 , V_505 ) & 0xf0 ) | V_508 ) ) ;
F_74 ( V_1 , V_510 , ( unsigned char ) V_507 ) ;
}
else {
F_74 ( V_1 , V_506 , 0 ) ;
F_74 ( V_1 , V_505 , 0 ) ;
F_74 ( V_1 , V_510 , 0 ) ;
}
}
static void F_146 ( T_1 * V_1 )
{
if ( V_31 >= V_252 )
F_4 ( L_156 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_74 ( V_1 , V_292 , V_511 ) ;
V_1 -> V_296 &= ~ V_512 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
F_74 ( V_1 , V_305 + V_288 , 0 ) ;
F_74 ( V_1 , V_305 + V_289 , V_290 ) ;
F_74 ( V_1 , V_305 + V_287 , 0 ) ;
V_1 -> V_378 = false ;
V_1 -> V_306 = false ;
}
static void F_149 ( T_1 * V_1 )
{
int V_334 ;
if ( V_31 >= V_252 )
F_4 ( L_157 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_74 ( V_1 , V_292 , V_511 ) ;
if ( V_1 -> V_60 . V_61 == V_62 ) {
V_1 -> V_296 &= ~ V_512 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
F_74 ( V_1 , V_305 + V_288 , 0 ) ;
F_74 ( V_1 , V_305 + V_289 , V_290 ) ;
for ( V_334 = 0 ; V_334 < V_1 -> V_431 ; V_334 ++ ) {
V_1 -> V_432 [ V_334 ] . V_253 = 0xff ;
if ( ! ( V_334 % 4 ) )
F_219 ( V_1 ) ;
}
V_1 -> V_513 = 0 ;
F_124 ( V_1 , V_305 + V_514 ,
V_1 -> V_433 [ 0 ] . V_439 ) ;
F_124 ( V_1 , V_305 + V_515 ,
V_1 -> V_433 [ V_1 -> V_431 - 1 ] . V_439 ) ;
F_124 ( V_1 , V_305 + V_516 , V_426 ) ;
F_74 ( V_1 , V_305 + V_287 , 0x60 ) ;
F_74 ( V_1 , V_305 + V_288 , 0xf2 ) ;
} else {
V_1 -> V_296 |= V_512 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
}
F_74 ( V_1 , V_292 , V_517 ) ;
V_1 -> V_306 = false ;
V_1 -> V_378 = true ;
}
static void F_35 ( T_1 * V_1 )
{
if ( V_31 >= V_252 )
F_4 ( L_158 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_66 ) ;
if ( ! V_1 -> V_72 ) {
F_74 ( V_1 , V_292 , V_293 ) ;
F_74 ( V_1 , V_292 , V_294 ) ;
V_1 -> V_72 = true ;
}
if ( V_1 -> V_66 ) {
V_1 -> V_300 = false ;
if ( V_1 -> V_60 . V_61 != V_264 ) {
if ( V_1 -> V_60 . V_11 & V_518 ) {
F_62 ( V_1 ) ;
if ( ! ( V_1 -> V_50 & V_51 ) ) {
V_1 -> V_50 |= V_51 ;
F_28 ( V_1 ) ;
V_1 -> V_300 = true ;
}
}
F_124 ( V_1 , V_308 ,
( unsigned short ) ( ( ( V_519 - 1 ) << 8 ) + V_520 ) ) ;
F_74 ( V_1 , V_286 + V_288 , 0 ) ;
F_74 ( V_1 , V_286 + V_289 , V_290 ) ;
F_124 ( V_1 , V_286 + V_514 ,
V_1 -> V_435 [ 0 ] . V_439 ) ;
F_124 ( V_1 , V_286 + V_515 ,
V_1 -> V_435 [ V_1 -> V_521 ] . V_439 ) ;
V_1 -> V_255 &= ~ V_298 ;
V_1 -> V_255 |= V_291 ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
F_74 ( V_1 , V_254 , ( unsigned char ) ( V_298 + V_291 ) ) ;
F_74 ( V_1 , V_286 + V_287 , 0x40 ) ;
F_74 ( V_1 , V_286 + V_288 , 0xf2 ) ;
F_141 ( & V_1 -> V_81 , V_76 +
F_142 ( 5000 ) ) ;
}
else {
F_127 ( V_1 ) ;
V_1 -> V_296 |= V_297 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
}
V_1 -> V_65 = true ;
}
}
static void F_47 ( T_1 * V_1 )
{
if ( V_31 >= V_252 )
F_4 ( L_159 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_44 ( & V_1 -> V_81 ) ;
F_74 ( V_1 , V_286 + V_288 , 0 ) ;
F_74 ( V_1 , V_286 + V_289 , V_290 ) ;
F_74 ( V_1 , V_292 , V_293 ) ;
V_1 -> V_255 &= ~ ( V_291 + V_298 ) ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
F_74 ( V_1 , V_254 , ( unsigned char ) ( V_298 + V_291 ) ) ;
V_1 -> V_296 &= ~ V_297 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
V_1 -> V_72 = false ;
V_1 -> V_65 = false ;
}
static void F_127 ( T_1 * V_1 )
{
T_14 V_522 [ 2 ] ;
if ( ! V_1 -> V_66 && ! V_1 -> V_71 )
return;
while( V_1 -> V_66 && ( F_73 ( V_1 , V_523 ) & V_341 ) ) {
if ( ( V_1 -> V_66 > 1 ) && ! V_1 -> V_71 ) {
V_522 [ 0 ] = V_1 -> V_59 [ V_1 -> V_80 ++ ] ;
if ( V_1 -> V_80 >= V_1 -> V_63 )
V_1 -> V_80 -= V_1 -> V_63 ;
V_522 [ 1 ] = V_1 -> V_59 [ V_1 -> V_80 ++ ] ;
if ( V_1 -> V_80 >= V_1 -> V_63 )
V_1 -> V_80 -= V_1 -> V_63 ;
F_124 ( V_1 , V_278 , * ( ( T_7 * ) V_522 ) ) ;
V_1 -> V_66 -= 2 ;
V_1 -> V_101 . V_109 += 2 ;
} else {
if ( V_1 -> V_71 ) {
F_74 ( V_1 , V_278 , V_1 -> V_71 ) ;
V_1 -> V_71 = 0 ;
} else {
F_74 ( V_1 , V_278 , V_1 -> V_59 [ V_1 -> V_80 ++ ] ) ;
if ( V_1 -> V_80 >= V_1 -> V_63 )
V_1 -> V_80 -= V_1 -> V_63 ;
V_1 -> V_66 -- ;
}
V_1 -> V_101 . V_109 ++ ;
}
}
}
static void F_140 ( T_1 * V_1 )
{
if ( V_1 -> V_463 ) {
F_47 ( V_1 ) ;
F_146 ( V_1 ) ;
V_1 -> V_50 &= ~ ( V_51 | V_52 ) ;
F_28 ( V_1 ) ;
V_1 -> V_296 = 0 ;
V_1 -> V_255 = 0 ;
V_1 -> V_262 = 0 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
F_74 ( V_1 , V_524 , V_1 -> V_262 ) ;
F_74 ( V_1 , V_292 , V_525 ) ;
}
}
static void F_220 ( T_1 * V_1 )
{
int V_334 ;
for ( V_334 = 0 ; V_334 < V_485 ; ++ V_334 ) {
if ( V_1 -> V_340 [ V_334 ] )
F_140 ( V_1 -> V_340 [ V_334 ] ) ;
}
}
static void F_148 ( T_1 * V_1 )
{
unsigned char V_142 ;
F_47 ( V_1 ) ;
F_146 ( V_1 ) ;
V_142 = 0x00 ;
if ( V_1 -> V_60 . V_361 != 1 )
V_142 |= V_341 ;
F_74 ( V_1 , V_526 , V_142 ) ;
V_142 = 0x40 ;
switch ( V_1 -> V_60 . V_356 ) {
case 7 : V_142 |= V_344 + V_342 ; break;
case 6 : V_142 |= V_343 + V_145 ; break;
case 5 : V_142 |= V_343 + V_344 + V_145 + V_342 ; break;
}
if ( V_1 -> V_60 . V_112 != V_362 ) {
V_142 |= V_341 ;
if ( V_1 -> V_60 . V_112 == V_365 )
V_142 |= V_275 ;
}
F_74 ( V_1 , V_527 , V_142 ) ;
V_142 = 0x00 ;
if ( V_1 -> V_60 . V_207 )
V_142 |= ( V_341 + V_275 ) ;
F_74 ( V_1 , V_503 , V_142 ) ;
V_142 = V_346 ;
F_74 ( V_1 , V_505 , V_142 ) ;
V_142 = V_346 ;
F_74 ( V_1 , V_506 , V_142 ) ;
V_1 -> V_340 [ 0 ] -> V_504 |= ( V_275 << ( V_1 -> V_246 * 2 ) ) ;
F_217 ( V_1 ) ;
F_159 ( V_1 ) ;
F_74 ( V_1 , V_528 , 0x00 ) ;
F_74 ( V_1 , V_308 , 0x10 ) ;
F_74 ( V_1 , V_529 , 0x1e ) ;
V_142 = 0x10 ;
if ( ! ( V_1 -> V_50 & V_51 ) )
V_142 |= 0x01 ;
F_74 ( V_1 , V_144 , V_142 ) ;
V_1 -> V_296 |= V_530 + V_531 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
V_1 -> V_255 = V_259 ;
F_74 ( V_1 , V_317 , V_1 -> V_255 ) ;
V_1 -> V_262 = V_263 ;
F_74 ( V_1 , V_524 , V_1 -> V_262 ) ;
F_218 ( V_1 , V_1 -> V_60 . V_77 * 16 ) ;
}
static void F_147 ( T_1 * V_1 )
{
unsigned char V_142 ;
T_13 V_532 ;
V_1 -> V_60 . V_11 &= ~ ( V_196 + V_192 ) ;
F_74 ( V_1 , V_286 + V_287 , 0 ) ;
F_74 ( V_1 , V_305 + V_287 , 0 ) ;
V_142 = 0x81 ;
if ( V_1 -> V_60 . V_11 & V_533 )
V_142 |= V_344 ;
if ( V_1 -> V_60 . V_11 & V_534 )
V_142 |= V_344 ;
if ( V_1 -> V_60 . V_167 == V_164 )
V_142 |= V_342 + V_341 ;
F_74 ( V_1 , V_526 , V_142 ) ;
V_142 = 0x00 ;
F_74 ( V_1 , V_527 , V_142 ) ;
V_142 = 0x00 ;
switch( V_1 -> V_60 . V_148 ) {
case V_535 : V_142 |= V_343 ; break;
case V_156 : V_142 |= V_345 + V_343 ; break;
case V_158 : V_142 |= V_345 + V_346 ; break;
case V_160 : V_142 |= V_345 ; break;
#if 0
case HDLC_ENCODING_NRZB:
case HDLC_ENCODING_NRZI_MARK:
case HDLC_ENCODING_DIFF_BIPHASE_LEVEL:
#endif
}
if ( V_1 -> V_60 . V_11 & V_536 ) {
V_532 = 16 ;
V_142 |= V_145 ;
} else if ( V_1 -> V_60 . V_11 & V_537 ) {
V_532 = 8 ;
} else {
V_532 = 32 ;
V_142 |= V_344 ;
}
F_74 ( V_1 , V_503 , V_142 ) ;
V_142 = 0 ;
if ( V_1 -> V_60 . V_11 & V_193 )
V_142 |= V_346 ;
if ( V_1 -> V_60 . V_11 & V_192 )
V_142 |= V_346 + V_343 ;
F_74 ( V_1 , V_505 , V_142 ) ;
V_142 = 0 ;
if ( V_1 -> V_60 . V_11 & V_197 )
V_142 |= V_346 ;
if ( V_1 -> V_60 . V_11 & V_196 )
V_142 |= V_346 + V_343 ;
F_74 ( V_1 , V_506 , V_142 ) ;
if ( V_1 -> V_60 . V_11 & V_192 )
F_218 ( V_1 , V_1 -> V_60 . V_206 * V_532 ) ;
else
F_218 ( V_1 , V_1 -> V_60 . V_206 ) ;
if ( V_1 -> V_60 . V_11 & V_197 )
V_1 -> V_340 [ 0 ] -> V_504 |= ( V_275 << ( V_1 -> V_246 * 2 ) ) ;
else
V_1 -> V_340 [ 0 ] -> V_504 &= ~ ( V_275 << ( V_1 -> V_246 * 2 ) ) ;
F_217 ( V_1 ) ;
F_74 ( V_1 , V_528 , V_538 ) ;
F_74 ( V_1 , V_308 , V_520 ) ;
F_74 ( V_1 , V_529 , ( unsigned char ) ( V_519 - 1 ) ) ;
F_74 ( V_1 , V_286 + V_539 , 0x14 ) ;
F_74 ( V_1 , V_305 + V_539 , 0x14 ) ;
F_74 ( V_1 , V_305 + V_540 ,
( unsigned char ) ( V_1 -> V_438 >> 16 ) ) ;
F_74 ( V_1 , V_286 + V_540 ,
( unsigned char ) ( V_1 -> V_438 >> 16 ) ) ;
V_1 -> V_296 |= V_530 + V_531 ;
F_74 ( V_1 , V_299 , V_1 -> V_296 ) ;
V_142 = 0x10 ;
if ( ! ( V_1 -> V_50 & V_51 ) )
V_142 |= 0x01 ;
F_74 ( V_1 , V_144 , V_142 ) ;
F_159 ( V_1 ) ;
F_47 ( V_1 ) ;
F_146 ( V_1 ) ;
F_218 ( V_1 , V_1 -> V_60 . V_206 ) ;
if ( V_1 -> V_60 . V_207 )
F_216 ( V_1 , 1 ) ;
}
static void F_159 ( T_1 * V_1 )
{
unsigned char V_142 = 0xff ;
switch( V_1 -> V_375 ) {
case V_477 : V_142 = 0x7e ; break;
case V_541 : V_142 = 0xaa ; break;
case V_542 : V_142 = 0x00 ; break;
case V_543 : V_142 = 0xff ; break;
case V_544 : V_142 = 0xaa ; break;
case V_545 : V_142 = 0x00 ; break;
case V_546 : V_142 = 0xff ; break;
}
F_74 ( V_1 , V_547 , V_142 ) ;
}
static void F_62 ( T_1 * V_1 )
{
T_7 V_253 = F_73 ( V_1 , V_548 ) ;
T_7 V_549 = F_219 ( V_1 ) ;
T_7 V_550 ;
V_1 -> V_50 &= V_51 | V_52 ;
if ( ! ( V_253 & V_145 ) )
V_1 -> V_50 |= V_123 ;
if ( ! ( V_253 & V_342 ) )
V_1 -> V_50 |= V_125 ;
V_550 = V_341 << ( V_1 -> V_246 * 2 ) ;
if ( ! ( V_549 & V_550 ) )
V_1 -> V_50 |= V_126 ;
V_550 = V_275 << ( V_1 -> V_246 * 2 ) ;
if ( ! ( V_549 & V_550 ) )
V_1 -> V_50 |= V_124 ;
}
static void F_28 ( T_1 * V_1 )
{
unsigned char V_142 ;
T_7 V_551 ;
V_142 = F_73 ( V_1 , V_144 ) ;
if ( V_1 -> V_50 & V_51 )
V_142 &= ~ V_275 ;
else
V_142 |= V_275 ;
F_74 ( V_1 , V_144 , V_142 ) ;
V_551 = V_341 << ( V_1 -> V_246 * 2 ) ;
if ( V_1 -> V_50 & V_52 )
V_1 -> V_340 [ 0 ] -> V_504 &= ~ V_551 ;
else
V_1 -> V_340 [ 0 ] -> V_504 |= V_551 ;
F_217 ( V_1 ) ;
}
static void F_181 ( T_1 * V_1 )
{
F_221 ( V_1 , 0 , V_1 -> V_431 - 1 ) ;
}
static void F_221 ( T_1 * V_1 , unsigned int V_552 , unsigned int V_553 )
{
bool V_554 = false ;
while( ! V_554 ) {
V_1 -> V_432 [ V_552 ] . V_253 = 0xff ;
if ( V_552 == V_553 ) {
V_554 = true ;
F_124 ( V_1 , V_305 + V_515 , V_1 -> V_433 [ V_552 ] . V_439 ) ;
}
V_552 ++ ;
if ( V_552 == V_1 -> V_431 )
V_552 = 0 ;
}
V_1 -> V_513 = V_552 ;
}
static bool F_115 ( T_1 * V_1 )
{
unsigned int V_555 , V_556 ;
unsigned short V_253 ;
unsigned int V_557 = 0 ;
bool V_558 = false ;
unsigned long V_11 ;
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
unsigned char V_559 = 0xff ;
V_428 * V_560 ;
T_10 * V_561 ;
V_562:
V_557 = 0 ;
V_559 = 0xff ;
V_555 = V_556 = V_1 -> V_513 ;
for ( ; ; ) {
V_560 = & V_1 -> V_432 [ V_556 ] ;
V_561 = & V_1 -> V_433 [ V_556 ] ;
if ( V_560 -> V_253 == 0xff )
goto V_563;
if ( V_557 == 0 && V_1 -> V_60 . V_564 != 0xff )
V_559 = V_561 -> V_445 [ 0 ] ;
V_557 += V_560 -> V_441 ;
if ( V_560 -> V_253 )
break;
V_556 ++ ;
if ( V_556 == V_1 -> V_431 )
V_556 = 0 ;
if ( V_556 == V_1 -> V_513 ) {
if ( V_1 -> V_378 ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_149 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
goto V_563;
}
}
V_253 = V_560 -> V_253 ;
if ( V_1 -> V_60 . V_167 == V_162 )
V_253 &= ~ V_342 ;
if ( V_557 == 0 ||
( V_559 != 0xff && V_559 != V_1 -> V_60 . V_564 ) ) {
F_221 ( V_1 , V_555 , V_556 ) ;
goto V_562;
}
if ( V_557 < 2 )
V_253 |= V_346 ;
if ( V_253 & ( V_346 + V_343 + V_145 + V_342 ) ) {
if ( V_253 & V_346 )
V_1 -> V_101 . V_131 ++ ;
else if ( V_253 & V_343 )
V_1 -> V_101 . V_565 ++ ;
else if ( V_253 & V_145 )
V_1 -> V_101 . V_133 ++ ;
else
V_1 -> V_101 . V_134 ++ ;
V_557 = 0 ;
#if V_301
{
V_1 -> V_213 -> V_172 . V_566 ++ ;
V_1 -> V_213 -> V_172 . V_567 ++ ;
}
#endif
}
if ( V_31 >= V_240 )
F_4 ( L_160 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_253 , V_557 ) ;
if ( V_31 >= V_568 )
F_222 ( V_1 , V_1 -> V_433 [ V_555 ] . V_445 ,
F_33 (unsigned int, framesize, SCABUFSIZE) , 0 ) ;
if ( V_557 ) {
if ( V_557 > V_1 -> V_63 )
V_1 -> V_101 . V_132 ++ ;
else {
int V_569 = V_557 ;
int V_19 = V_555 ;
unsigned char * V_570 = V_1 -> V_448 ;
V_1 -> V_571 = V_557 ;
V_1 -> V_101 . V_128 ++ ;
while( V_569 ) {
int V_572 = F_34 ( V_569 , V_426 ) ;
memcpy ( V_570 ,
V_1 -> V_433 [ V_19 ] . V_445 ,
V_572 ) ;
V_570 += V_572 ;
V_569 -= V_572 ;
if ( ++ V_19 == V_1 -> V_431 )
V_19 = 0 ;
}
#if V_301
if ( V_1 -> V_36 )
F_97 ( V_1 , V_1 -> V_448 , V_557 ) ;
else
#endif
F_5 ( V_9 , V_1 -> V_448 ,
V_1 -> V_449 , V_557 ) ;
}
}
F_221 ( V_1 , V_555 , V_556 ) ;
V_558 = true ;
V_563:
if ( V_1 -> V_378 && V_1 -> V_306 ) {
if ( V_1 -> V_432 [ V_556 ] . V_253 == 0xff ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_149 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
}
return V_558 ;
}
static void F_32 ( T_1 * V_1 , const char * V_56 , unsigned int V_12 )
{
unsigned short V_569 ;
unsigned int V_334 = 0 ;
V_428 * V_560 ;
T_10 * V_561 ;
if ( V_31 >= V_568 )
F_222 ( V_1 , V_56 , F_33 (unsigned int, count, SCABUFSIZE) , 1 ) ;
for( V_334 = 0 ; ; )
{
V_569 = F_33 (unsigned int, count, SCABUFSIZE) ;
V_560 = & V_1 -> V_434 [ V_334 ] ;
V_561 = & V_1 -> V_435 [ V_334 ] ;
F_223 ( V_1 , V_561 -> V_445 , V_56 , V_569 ) ;
V_560 -> V_441 = V_569 ;
V_560 -> V_253 = 0 ;
V_56 += V_569 ;
V_12 -= V_569 ;
if ( ! V_12 )
break;
V_334 ++ ;
if ( V_334 >= V_1 -> V_429 )
V_334 = 0 ;
}
V_1 -> V_434 [ V_334 ] . V_253 = 0x81 ;
V_1 -> V_521 = ++ V_334 ;
}
static bool F_224 ( T_1 * V_1 )
{
static unsigned char V_573 [] = { 0x00 , 0xff , 0xaa , 0x55 , 0x69 , 0x96 } ;
static unsigned int V_12 = F_225 ( V_573 ) ;
unsigned int V_334 ;
bool V_177 = true ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_140 ( V_1 ) ;
V_1 -> V_24 = V_574 ;
for ( V_334 = 0 ; V_334 < V_12 ; V_334 ++ ) {
F_74 ( V_1 , V_510 , V_573 [ V_334 ] ) ;
F_74 ( V_1 , V_547 , V_573 [ ( V_334 + 1 ) % V_12 ] ) ;
F_74 ( V_1 , V_575 , V_573 [ ( V_334 + 2 ) % V_12 ] ) ;
F_74 ( V_1 , V_576 , V_573 [ ( V_334 + 3 ) % V_12 ] ) ;
if ( ( F_73 ( V_1 , V_510 ) != V_573 [ V_334 ] ) ||
( F_73 ( V_1 , V_547 ) != V_573 [ ( V_334 + 1 ) % V_12 ] ) ||
( F_73 ( V_1 , V_575 ) != V_573 [ ( V_334 + 2 ) % V_12 ] ) ||
( F_73 ( V_1 , V_576 ) != V_573 [ ( V_334 + 3 ) % V_12 ] ) )
{
V_177 = false ;
break;
}
}
F_140 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_177 ;
}
static bool F_226 ( T_1 * V_1 )
{
unsigned long V_41 ;
unsigned long V_11 ;
unsigned char V_245 = ( V_1 -> V_246 & 1 ) ? V_247 : V_248 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_140 ( V_1 ) ;
V_1 -> V_24 = V_577 ;
V_1 -> V_251 = false ;
F_74 ( V_1 , V_249 , ( unsigned char ) ( ( V_1 -> V_246 & 1 ) ? V_346 : V_344 ) ) ;
F_74 ( V_1 , ( unsigned char ) ( V_245 + V_578 ) , 0 ) ;
F_124 ( V_1 , ( unsigned char ) ( V_245 + V_579 ) , 1 ) ;
F_74 ( V_1 , ( unsigned char ) ( V_245 + V_250 ) , 0x50 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_41 = 100 ;
while( V_41 -- && ! V_1 -> V_251 ) {
F_38 ( 10 ) ;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_140 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_1 -> V_251 ;
}
static bool F_227 ( T_1 * V_1 )
{
F_74 ( V_1 , V_580 , 0 ) ;
F_74 ( V_1 , V_581 , 0 ) ;
F_74 ( V_1 , V_582 , 0 ) ;
F_74 ( V_1 , V_583 , 0 ) ;
F_74 ( V_1 , V_584 , 0 ) ;
F_74 ( V_1 , V_585 , V_586 ) ;
F_74 ( V_1 , V_587 , 0x80 ) ;
F_74 ( V_1 , V_588 , 0xff ) ;
F_74 ( V_1 , V_589 , 0xff ) ;
F_74 ( V_1 , V_249 , 0xf0 ) ;
F_74 ( V_1 , V_590 , 0 ) ;
return true ;
}
static bool F_228 ( T_1 * V_1 )
{
int V_334 ;
volatile T_13 * V_591 = ( T_13 * ) ( V_1 -> V_461 + 0x50 ) ;
T_13 V_592 ;
V_1 -> V_484 |= V_593 ;
* V_591 = V_1 -> V_484 ;
for( V_334 = 0 ; V_334 < 10 ; V_334 ++ )
V_592 = * V_591 ;
V_1 -> V_484 &= ~ V_593 ;
* V_591 = V_1 -> V_484 ;
V_1 -> V_504 = 0xaa ;
F_217 ( V_1 ) ;
{
volatile T_13 * V_594 = ( T_13 * ) ( V_1 -> V_461 + 0x2c ) ;
V_595 &= ~ ( V_343 + V_344 + V_145 ) ;
switch( V_596 )
{
case 16 :
V_595 |= V_343 + V_344 + V_145 ;
break;
case 8 :
V_595 |= V_343 + V_344 ;
break;
case 4 :
V_595 |= V_343 + V_145 ;
break;
case 0 :
V_595 |= V_343 ;
break;
}
* V_594 = V_595 ;
* V_591 = V_484 ;
}
F_227 ( V_1 -> V_340 [ 0 ] ) ;
F_227 ( V_1 -> V_340 [ 2 ] ) ;
return true ;
}
static bool F_229 ( T_1 * V_1 )
{
#define F_230 20
unsigned long V_41 ;
T_7 V_12 = F_230 ;
unsigned char V_56 [ F_230 ] ;
bool V_177 = false ;
unsigned long V_11 ;
struct V_8 * V_597 = V_1 -> V_27 . V_9 ;
T_13 V_598 = V_1 -> V_60 . V_206 ;
V_1 -> V_60 . V_206 = 3686400 ;
V_1 -> V_27 . V_9 = NULL ;
V_1 -> V_24 = V_599 ;
for ( V_12 = 0 ; V_12 < F_230 ; ++ V_12 )
V_56 [ V_12 ] = ( unsigned char ) V_12 ;
memset ( V_1 -> V_448 , 0 , F_230 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_147 ( V_1 ) ;
F_216 ( V_1 , 1 ) ;
F_149 ( V_1 ) ;
V_1 -> V_66 = V_12 ;
F_32 ( V_1 , V_56 , V_12 ) ;
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
for ( V_41 = 100 ; V_41 ; -- V_41 ) {
F_38 ( 10 ) ;
if ( F_115 ( V_1 ) ) {
V_177 = true ;
break;
}
}
if ( V_177 &&
( V_1 -> V_571 != V_12 ||
memcmp ( V_56 , V_1 -> V_448 , V_12 ) ) ) {
V_177 = false ;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_220 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_60 . V_206 = V_598 ;
V_1 -> V_27 . V_9 = V_597 ;
return V_177 ;
}
static int F_204 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_161 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_228 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_340 [ 0 ] -> V_339 = 0 ;
if ( F_224 ( V_1 -> V_340 [ 0 ] ) &&
F_224 ( V_1 -> V_340 [ 1 ] ) ) {
V_1 -> V_340 [ 0 ] -> V_339 = 2 ;
if ( F_224 ( V_1 -> V_340 [ 2 ] ) &&
F_224 ( V_1 -> V_340 [ 3 ] ) )
V_1 -> V_340 [ 0 ] -> V_339 += 2 ;
}
else {
F_4 ( L_162 ,
__FILE__ , __LINE__ , V_1 -> V_25 , ( unsigned long ) ( V_1 -> V_118 ) ) ;
return - V_21 ;
}
if ( ! F_226 ( V_1 -> V_340 [ 0 ] ) ||
! F_226 ( V_1 -> V_340 [ 1 ] ) ||
( V_1 -> V_339 == 4 && ! F_226 ( V_1 -> V_340 [ 2 ] ) ) ||
( V_1 -> V_339 == 4 && ! F_226 ( V_1 -> V_340 [ 3 ] ) ) ) {
F_4 ( L_163 ,
__FILE__ , __LINE__ , V_1 -> V_25 , ( unsigned short ) ( V_1 -> V_122 ) ) ;
return - V_21 ;
}
if ( ! F_229 ( V_1 -> V_340 [ 0 ] ) ||
! F_229 ( V_1 -> V_340 [ 1 ] ) ||
( V_1 -> V_339 == 4 && ! F_229 ( V_1 -> V_340 [ 2 ] ) ) ||
( V_1 -> V_339 == 4 && ! F_229 ( V_1 -> V_340 [ 3 ] ) ) ) {
F_4 ( L_164 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_21 ;
}
if ( V_31 >= V_32 )
F_4 ( L_165 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_340 [ 0 ] -> V_24 = 0 ;
V_1 -> V_340 [ 1 ] -> V_24 = 0 ;
if ( V_1 -> V_339 > 2 ) {
V_1 -> V_340 [ 2 ] -> V_24 = 0 ;
V_1 -> V_340 [ 3 ] -> V_24 = 0 ;
}
return 0 ;
}
static bool F_188 ( T_1 * V_1 )
{
static unsigned long V_573 [] = { 0x0 , 0x55555555 , 0xaaaaaaaa ,
0x66666666 , 0x99999999 , 0xffffffff , 0x12345678 } ;
unsigned long V_12 = F_225 ( V_573 ) ;
unsigned long V_334 ;
unsigned long V_600 = V_425 /sizeof( unsigned long ) ;
unsigned long * V_601 = ( unsigned long * ) V_1 -> V_437 ;
for ( V_334 = 0 ; V_334 < V_12 ; V_334 ++ ) {
* V_601 = V_573 [ V_334 ] ;
if ( * V_601 != V_573 [ V_334 ] )
return false ;
}
for ( V_334 = 0 ; V_334 < V_600 ; V_334 ++ ) {
* V_601 = V_334 * 4 ;
V_601 ++ ;
}
V_601 = ( unsigned long * ) V_1 -> V_437 ;
for ( V_334 = 0 ; V_334 < V_600 ; V_334 ++ ) {
if ( * V_601 != V_334 * 4 )
return false ;
V_601 ++ ;
}
memset ( V_1 -> V_437 , 0 , V_425 ) ;
return true ;
}
static void F_223 ( T_1 * V_1 , char * V_602 , const char * V_603 , unsigned short V_12 )
{
unsigned short V_604 = V_12 / V_605 ;
unsigned short V_334 ;
for ( V_334 = 0 ; V_334 < V_604 ; V_334 ++ )
{
memcpy ( V_602 , V_603 , V_605 ) ;
F_219 ( V_1 ) ;
V_602 += V_605 ;
V_603 += V_605 ;
}
memcpy ( V_602 , V_603 , V_12 % V_605 ) ;
}
static void F_222 ( T_1 * V_1 , const char * V_10 , int V_12 , int V_232 )
{
int V_334 ;
int V_606 ;
if ( V_232 )
F_4 ( L_166 , V_1 -> V_25 ) ;
else
F_4 ( L_167 , V_1 -> V_25 ) ;
while( V_12 ) {
if ( V_12 > 16 )
V_606 = 16 ;
else
V_606 = V_12 ;
for( V_334 = 0 ; V_334 < V_606 ; V_334 ++ )
F_4 ( L_168 , ( unsigned char ) V_10 [ V_334 ] ) ;
for(; V_334 < 17 ; V_334 ++ )
F_4 ( L_169 ) ;
for( V_334 = 0 ; V_334 < V_606 ; V_334 ++ ) {
if ( V_10 [ V_334 ] >= 040 && V_10 [ V_334 ] <= 0176 )
F_4 ( L_170 , V_10 [ V_334 ] ) ;
else
F_4 ( L_171 ) ;
}
F_4 ( L_172 ) ;
V_10 += V_606 ;
V_12 -= V_606 ;
}
}
static void V_482 ( unsigned long V_607 )
{
T_1 * V_1 = ( T_1 * ) V_607 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_173 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if( V_1 -> V_65 && V_1 -> V_60 . V_61 == V_62 ) {
V_1 -> V_101 . V_608 ++ ;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_65 = false ;
V_1 -> V_66 = V_1 -> V_68 = V_1 -> V_80 = 0 ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
#if V_301
if ( V_1 -> V_36 )
F_95 ( V_1 ) ;
else
#endif
F_113 ( V_1 ) ;
}
static void V_483 ( unsigned long V_607 )
{
T_7 V_253 = 0 ;
T_1 * V_1 = ( T_1 * ) V_607 ;
unsigned long V_11 ;
unsigned char V_609 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_609 = V_1 -> V_610 ^ V_1 -> V_50 ;
V_1 -> V_610 = V_1 -> V_50 ;
if ( V_609 & V_124 )
V_253 |= V_309 | ( V_1 -> V_50 & V_124 ) ;
if ( V_609 & V_126 )
V_253 |= V_310 | ( V_1 -> V_50 & V_126 ) ;
if ( V_609 & V_125 )
V_253 |= V_272 | ( V_1 -> V_50 & V_125 ) ;
if ( V_609 & V_123 )
V_253 |= V_303 | ( V_1 -> V_50 & V_123 ) ;
if ( V_253 )
F_120 ( V_1 , V_253 ) ;
F_141 ( & V_1 -> V_349 , V_76 + F_142 ( 10 ) ) ;
}
static unsigned char F_73 ( T_1 * V_1 , unsigned char V_611 )
{
F_231 () ;
return * V_612 ;
}
static void F_74 ( T_1 * V_1 , unsigned char V_611 , unsigned char V_613 )
{
F_231 () ;
* V_612 = V_613 ;
}
static T_7 F_136 ( T_1 * V_1 , unsigned char V_611 )
{
F_231 () ;
return * ( ( T_7 * ) V_612 ) ;
}
static void F_124 ( T_1 * V_1 , unsigned char V_611 , T_7 V_613 )
{
F_231 () ;
* ( ( T_7 * ) V_612 ) = V_613 ;
}
static unsigned char F_219 ( T_1 * V_1 )
{
unsigned char * V_612 = ( unsigned char * ) V_1 -> V_464 ;
return * V_612 ;
}
static void F_217 ( T_1 * V_1 )
{
unsigned char * V_612 = ( unsigned char * ) V_1 -> V_464 ;
* V_612 = V_1 -> V_340 [ 0 ] -> V_504 ;
}
static int F_232 ( struct V_471 * V_147 ,
const struct V_614 * V_615 )
{
if ( F_233 ( V_147 ) ) {
F_4 ( L_174 , V_147 ) ;
return - V_64 ;
}
F_201 ( ++ V_616 , V_147 ) ;
return 0 ;
}
static void F_234 ( struct V_471 * V_147 )
{
}
