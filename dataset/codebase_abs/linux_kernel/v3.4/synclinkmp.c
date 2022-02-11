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
static int F_8 ( struct V_8 * V_9 , struct V_17 * V_18 )
{
T_1 * V_1 ;
int V_19 , line ;
unsigned long V_11 ;
line = V_9 -> V_20 ;
if ( line >= V_21 ) {
F_4 ( L_3 ,
__FILE__ , __LINE__ , line ) ;
return - V_22 ;
}
V_1 = V_23 ;
while( V_1 && V_1 -> line != line )
V_1 = V_1 -> V_24 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_4 ) )
return - V_22 ;
if ( V_1 -> V_25 ) {
F_4 ( L_5 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_25 ) ;
return - V_22 ;
}
V_9 -> V_27 = V_1 ;
V_1 -> V_28 . V_9 = V_9 ;
if ( V_29 >= V_30 )
F_4 ( L_6 ,
__FILE__ , __LINE__ , V_9 -> V_31 -> V_2 , V_1 -> V_28 . V_12 ) ;
if ( F_9 ( V_18 ) || V_1 -> V_28 . V_11 & V_32 ) {
if ( V_1 -> V_28 . V_11 & V_32 )
F_10 ( & V_1 -> V_28 . V_33 ) ;
V_19 = ( ( V_1 -> V_28 . V_11 & V_34 ) ?
- V_35 : - V_36 ) ;
goto V_37;
}
V_1 -> V_28 . V_9 -> V_38 = ( V_1 -> V_28 . V_11 & V_39 ) ? 1 : 0 ;
F_11 ( & V_1 -> V_40 , V_11 ) ;
if ( V_1 -> V_41 ) {
V_19 = - V_42 ;
F_12 ( & V_1 -> V_40 , V_11 ) ;
goto V_37;
}
V_1 -> V_28 . V_12 ++ ;
F_12 ( & V_1 -> V_40 , V_11 ) ;
if ( V_1 -> V_28 . V_12 == 1 ) {
V_19 = F_13 ( V_1 ) ;
if ( V_19 < 0 )
goto V_37;
}
V_19 = F_14 ( V_9 , V_18 , V_1 ) ;
if ( V_19 ) {
if ( V_29 >= V_30 )
F_4 ( L_7 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_19 ) ;
goto V_37;
}
if ( V_29 >= V_30 )
F_4 ( L_8 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
V_19 = 0 ;
V_37:
if ( V_19 ) {
if ( V_9 -> V_12 == 1 )
V_1 -> V_28 . V_9 = NULL ;
if( V_1 -> V_28 . V_12 )
V_1 -> V_28 . V_12 -- ;
}
return V_19 ;
}
static void F_15 ( struct V_8 * V_9 , struct V_17 * V_18 )
{
T_1 * V_1 = V_9 -> V_27 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_9 ) )
return;
if ( V_29 >= V_30 )
F_4 ( L_10 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_28 . V_12 ) ;
if ( F_16 ( & V_1 -> V_28 , V_9 , V_18 ) == 0 )
goto V_37;
F_17 ( & V_1 -> V_28 . V_43 ) ;
if ( V_1 -> V_28 . V_11 & V_44 )
F_18 ( V_9 , V_1 -> V_45 ) ;
F_19 ( V_9 ) ;
F_20 ( V_9 ) ;
F_21 ( V_1 ) ;
F_22 ( & V_1 -> V_28 . V_43 ) ;
F_23 ( & V_1 -> V_28 , V_9 ) ;
V_1 -> V_28 . V_9 = NULL ;
V_37:
if ( V_29 >= V_30 )
F_4 ( L_11 , __FILE__ , __LINE__ ,
V_9 -> V_31 -> V_2 , V_1 -> V_28 . V_12 ) ;
}
static void F_24 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_12 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_13 ) )
return;
F_17 ( & V_1 -> V_28 . V_43 ) ;
F_19 ( V_9 ) ;
F_21 ( V_1 ) ;
F_11 ( & V_1 -> V_28 . V_46 , V_11 ) ;
V_1 -> V_28 . V_12 = 0 ;
V_1 -> V_28 . V_11 &= ~ V_47 ;
V_1 -> V_28 . V_9 = NULL ;
F_12 ( & V_1 -> V_28 . V_46 , V_11 ) ;
F_22 ( & V_1 -> V_28 . V_43 ) ;
F_25 ( & V_1 -> V_28 . V_48 ) ;
}
static void F_26 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_14 , __FILE__ , __LINE__ ,
V_9 -> V_31 -> V_2 ) ;
F_27 ( V_1 ) ;
if ( V_50 -> V_51 & V_52 &&
! ( V_9 -> V_53 -> V_51 & V_52 ) ) {
V_1 -> V_54 &= ~ ( V_55 + V_56 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
if ( ! ( V_50 -> V_51 & V_52 ) &&
V_9 -> V_53 -> V_51 & V_52 ) {
V_1 -> V_54 |= V_56 ;
if ( ! ( V_9 -> V_53 -> V_51 & V_57 ) ||
! F_29 ( V_58 , & V_9 -> V_11 ) ) {
V_1 -> V_54 |= V_55 ;
}
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
if ( V_50 -> V_51 & V_57 &&
! ( V_9 -> V_53 -> V_51 & V_57 ) ) {
V_9 -> V_59 = 0 ;
F_30 ( V_9 ) ;
}
}
static int F_31 ( struct V_8 * V_9 ,
const unsigned char * V_60 , int V_12 )
{
int V_61 , V_62 = 0 ;
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_15 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_12 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_16 ) )
goto V_37;
if ( ! V_1 -> V_63 )
goto V_37;
if ( V_1 -> V_64 . V_65 == V_66 ) {
if ( V_12 > V_1 -> V_67 ) {
V_62 = - V_68 ;
goto V_37;
}
if ( V_1 -> V_69 )
goto V_37;
if ( V_1 -> V_70 ) {
F_32 ( V_1 , V_1 -> V_63 , V_1 -> V_70 ) ;
goto V_71;
}
V_62 = V_1 -> V_70 = V_12 ;
F_32 ( V_1 , V_60 , V_12 ) ;
goto V_71;
}
for (; ; ) {
V_61 = F_33 ( int , V_12 ,
F_34 ( V_1 -> V_67 - V_1 -> V_70 - 1 ,
V_1 -> V_67 - V_1 -> V_72 ) ) ;
if ( V_61 <= 0 )
break;
memcpy ( V_1 -> V_63 + V_1 -> V_72 , V_60 , V_61 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_1 -> V_72 += V_61 ;
if ( V_1 -> V_72 >= V_1 -> V_67 )
V_1 -> V_72 -= V_1 -> V_67 ;
V_1 -> V_70 += V_61 ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
V_60 += V_61 ;
V_12 -= V_61 ;
V_62 += V_61 ;
}
if ( V_1 -> V_64 . V_65 == V_66 ) {
if ( V_12 ) {
V_62 = V_1 -> V_70 = 0 ;
goto V_37;
}
F_32 ( V_1 , V_1 -> V_63 , V_1 -> V_70 ) ;
}
V_71:
if ( V_1 -> V_70 && ! V_9 -> V_73 && ! V_9 -> V_59 ) {
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( ! V_1 -> V_69 )
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
V_37:
if ( V_29 >= V_30 )
F_4 ( L_17 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_62 ) ;
return V_62 ;
}
static int F_36 ( struct V_8 * V_9 , unsigned char V_74 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
int V_62 = 0 ;
if ( V_29 >= V_30 ) {
F_4 ( L_18 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_74 ) ;
}
if ( F_2 ( V_1 , V_9 -> V_2 , L_19 ) )
return 0 ;
if ( ! V_1 -> V_63 )
return 0 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( ( V_1 -> V_64 . V_65 != V_66 ) ||
! V_1 -> V_69 ) {
if ( V_1 -> V_70 < V_1 -> V_67 - 1 ) {
V_1 -> V_63 [ V_1 -> V_72 ++ ] = V_74 ;
if ( V_1 -> V_72 >= V_1 -> V_67 )
V_1 -> V_72 -= V_1 -> V_67 ;
V_1 -> V_70 ++ ;
V_62 = 1 ;
}
}
F_12 ( & V_1 -> V_46 , V_11 ) ;
return V_62 ;
}
static void F_37 ( struct V_8 * V_9 , char V_74 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_20 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_74 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_21 ) )
return;
V_1 -> V_75 = V_74 ;
if ( V_74 ) {
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( ! V_1 -> V_76 )
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
}
static void F_18 ( struct V_8 * V_9 , int V_45 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_77 , V_78 ;
if ( ! V_1 )
return;
if ( V_29 >= V_30 )
F_4 ( L_22 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_23 ) )
return;
if ( ! F_29 ( V_79 , & V_1 -> V_28 . V_11 ) )
goto exit;
V_77 = V_80 ;
if ( V_1 -> V_64 . V_81 ) {
V_78 = V_1 -> V_45 / ( 32 * 5 ) ;
if ( ! V_78 )
V_78 ++ ;
} else
V_78 = 1 ;
if ( V_45 )
V_78 = F_33 (unsigned long, char_time, timeout) ;
if ( V_1 -> V_64 . V_65 == V_66 ) {
while ( V_1 -> V_69 ) {
F_38 ( F_39 ( V_78 ) ) ;
if ( F_40 ( V_82 ) )
break;
if ( V_45 && F_41 ( V_80 , V_77 + V_45 ) )
break;
}
} else {
while ( V_1 -> V_69 && V_1 -> V_76 ) {
F_38 ( F_39 ( V_78 ) ) ;
if ( F_40 ( V_82 ) )
break;
if ( V_45 && F_41 ( V_80 , V_77 + V_45 ) )
break;
}
}
exit:
if ( V_29 >= V_30 )
F_4 ( L_24 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
int V_62 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_25 ) )
return 0 ;
if ( V_1 -> V_64 . V_65 == V_66 ) {
V_62 = ( V_1 -> V_69 ) ? 0 : V_83 ;
} else {
V_62 = V_1 -> V_67 - V_1 -> V_70 - 1 ;
if ( V_62 < 0 )
V_62 = 0 ;
}
if ( V_29 >= V_30 )
F_4 ( L_26 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_62 ) ;
return V_62 ;
}
static void F_43 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_27 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_70 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_28 ) )
return;
if ( V_1 -> V_70 <= 0 || V_9 -> V_73 || V_9 -> V_59 ||
! V_1 -> V_63 )
return;
if ( V_29 >= V_30 )
F_4 ( L_29 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( ! V_1 -> V_69 ) {
if ( ( V_1 -> V_64 . V_65 == V_66 ) &&
V_1 -> V_70 ) {
F_32 ( V_1 ,
V_1 -> V_63 , V_1 -> V_70 ) ;
}
F_35 ( V_1 ) ;
}
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_30 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_31 ) )
return;
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_1 -> V_70 = V_1 -> V_72 = V_1 -> V_84 = 0 ;
F_44 ( & V_1 -> V_85 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
F_45 ( V_9 ) ;
}
static void F_46 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_32 ) )
return;
if ( V_29 >= V_30 )
F_4 ( L_33 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( V_1 -> V_76 )
F_47 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_34 ) )
return;
if ( V_29 >= V_30 )
F_4 ( L_35 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( ! V_1 -> V_76 )
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
static int F_48 ( struct V_8 * V_9 ,
unsigned int V_86 , unsigned long V_87 )
{
T_1 * V_1 = V_9 -> V_27 ;
void T_3 * V_88 = ( void T_3 * ) V_87 ;
if ( V_29 >= V_30 )
F_4 ( L_36 , __FILE__ , __LINE__ ,
V_1 -> V_26 , V_86 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_37 ) )
return - V_22 ;
if ( ( V_86 != V_89 ) && ( V_86 != V_90 ) &&
( V_86 != V_91 ) ) {
if ( V_9 -> V_11 & ( 1 << V_92 ) )
return - V_68 ;
}
switch ( V_86 ) {
case V_93 :
return F_49 ( V_1 , V_88 ) ;
case V_94 :
return F_50 ( V_1 , V_88 ) ;
case V_95 :
return F_51 ( V_1 , V_88 ) ;
case V_96 :
return F_52 ( V_1 , ( int ) V_87 ) ;
case V_97 :
return F_53 ( V_1 , ( int ) V_87 ) ;
case V_98 :
return F_54 ( V_1 , ( int ) V_87 ) ;
case V_99 :
return F_55 ( V_1 ) ;
case V_100 :
return F_56 ( V_1 , V_88 ) ;
case V_101 :
return F_57 ( V_1 , V_88 ) ;
case V_102 :
return 0 ;
case V_91 :
return F_58 ( V_1 , ( int ) V_87 ) ;
default:
return - V_103 ;
}
return 0 ;
}
static int F_59 ( struct V_8 * V_9 ,
struct V_104 * V_105 )
{
T_1 * V_1 = V_9 -> V_27 ;
struct V_106 V_107 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_107 = V_1 -> V_105 ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
V_105 -> V_108 = V_107 . V_108 ;
V_105 -> V_109 = V_107 . V_109 ;
V_105 -> V_110 = V_107 . V_110 ;
V_105 -> V_111 = V_107 . V_111 ;
V_105 -> V_112 = V_107 . V_112 ;
V_105 -> V_113 = V_107 . V_113 ;
V_105 -> V_114 = V_107 . V_114 ;
V_105 -> V_115 = V_107 . V_115 ;
V_105 -> V_116 = V_107 . V_116 ;
V_105 -> V_117 = V_107 . V_117 ;
V_105 -> V_118 = V_107 . V_118 ;
return 0 ;
}
static inline void F_60 ( struct V_119 * V_120 , T_1 * V_1 )
{
char V_121 [ 30 ] ;
unsigned long V_11 ;
F_61 ( V_120 , L_38
L_39 ,
V_1 -> V_26 ,
V_1 -> V_122 ,
V_1 -> V_123 ,
V_1 -> V_124 ,
V_1 -> V_125 ,
V_1 -> V_126 ,
V_1 -> V_67 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
V_121 [ 0 ] = 0 ;
V_121 [ 1 ] = 0 ;
if ( V_1 -> V_54 & V_55 )
strcat ( V_121 , L_40 ) ;
if ( V_1 -> V_54 & V_127 )
strcat ( V_121 , L_41 ) ;
if ( V_1 -> V_54 & V_56 )
strcat ( V_121 , L_42 ) ;
if ( V_1 -> V_54 & V_128 )
strcat ( V_121 , L_43 ) ;
if ( V_1 -> V_54 & V_129 )
strcat ( V_121 , L_44 ) ;
if ( V_1 -> V_54 & V_130 )
strcat ( V_121 , L_45 ) ;
if ( V_1 -> V_64 . V_65 == V_66 ) {
F_61 ( V_120 , L_46 ,
V_1 -> V_105 . V_131 , V_1 -> V_105 . V_132 ) ;
if ( V_1 -> V_105 . V_133 )
F_61 ( V_120 , L_47 , V_1 -> V_105 . V_133 ) ;
if ( V_1 -> V_105 . V_134 )
F_61 ( V_120 , L_48 , V_1 -> V_105 . V_134 ) ;
if ( V_1 -> V_105 . V_135 )
F_61 ( V_120 , L_49 , V_1 -> V_105 . V_135 ) ;
if ( V_1 -> V_105 . V_136 )
F_61 ( V_120 , L_50 , V_1 -> V_105 . V_136 ) ;
if ( V_1 -> V_105 . V_137 )
F_61 ( V_120 , L_51 , V_1 -> V_105 . V_137 ) ;
if ( V_1 -> V_105 . V_138 )
F_61 ( V_120 , L_50 , V_1 -> V_105 . V_138 ) ;
} else {
F_61 ( V_120 , L_52 ,
V_1 -> V_105 . V_113 , V_1 -> V_105 . V_112 ) ;
if ( V_1 -> V_105 . V_114 )
F_61 ( V_120 , L_53 , V_1 -> V_105 . V_114 ) ;
if ( V_1 -> V_105 . V_116 )
F_61 ( V_120 , L_54 , V_1 -> V_105 . V_116 ) ;
if ( V_1 -> V_105 . V_117 )
F_61 ( V_120 , L_55 , V_1 -> V_105 . V_117 ) ;
if ( V_1 -> V_105 . V_115 )
F_61 ( V_120 , L_56 , V_1 -> V_105 . V_115 ) ;
}
F_61 ( V_120 , L_57 , V_121 + 1 ) ;
F_61 ( V_120 , L_58 ,
V_1 -> V_69 , V_1 -> V_139 , V_1 -> V_140 ,
V_1 -> V_141 ) ;
}
static int F_63 ( struct V_119 * V_120 , void * V_142 )
{
T_1 * V_1 ;
F_61 ( V_120 , L_59 , V_143 ) ;
V_1 = V_23 ;
while( V_1 ) {
F_60 ( V_120 , V_1 ) ;
V_1 = V_1 -> V_24 ;
}
return 0 ;
}
static int F_64 ( struct V_144 * V_144 , struct V_17 * V_17 )
{
return F_65 ( V_17 , F_63 , NULL ) ;
}
static int F_66 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_60 ) )
return 0 ;
if ( V_29 >= V_30 )
F_4 ( L_61 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_70 ) ;
return V_1 -> V_70 ;
}
static void F_67 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_63 ) )
return;
if ( F_68 ( V_9 ) )
F_37 ( V_9 , F_69 ( V_9 ) ) ;
if ( V_9 -> V_53 -> V_51 & V_57 ) {
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_1 -> V_54 &= ~ V_55 ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
}
static void F_70 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_64 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_65 ) )
return;
if ( F_68 ( V_9 ) ) {
if ( V_1 -> V_75 )
V_1 -> V_75 = 0 ;
else
F_37 ( V_9 , F_71 ( V_9 ) ) ;
}
if ( V_9 -> V_53 -> V_51 & V_57 ) {
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_1 -> V_54 |= V_55 ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
}
static int F_72 ( struct V_8 * V_9 , int V_145 )
{
unsigned char V_146 ;
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_66 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_145 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_67 ) )
return - V_147 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_146 = F_73 ( V_1 , V_148 ) ;
if ( V_145 == - 1 )
V_146 |= V_149 ;
else
V_146 &= ~ V_149 ;
F_74 ( V_1 , V_148 , V_146 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
return 0 ;
}
static int F_75 ( struct V_150 * V_151 , unsigned short V_152 ,
unsigned short V_116 )
{
T_1 * V_1 = F_76 ( V_151 ) ;
unsigned char V_153 ;
unsigned short V_154 ;
if ( V_1 -> V_28 . V_12 )
return - V_42 ;
switch ( V_152 )
{
case V_155 : V_153 = V_156 ; break;
case V_157 : V_153 = V_158 ; break;
case V_159 : V_153 = V_160 ; break;
case V_161 : V_153 = V_162 ; break;
case V_163 : V_153 = V_164 ; break;
default: return - V_147 ;
}
switch ( V_116 )
{
case V_165 : V_154 = V_166 ; break;
case V_167 : V_154 = V_168 ; break;
case V_169 : V_154 = V_170 ; break;
default: return - V_147 ;
}
V_1 -> V_64 . V_152 = V_153 ;
V_1 -> V_64 . V_171 = V_154 ;
if ( V_1 -> V_41 )
F_77 ( V_1 ) ;
return 0 ;
}
static T_4 F_78 ( struct V_172 * V_173 ,
struct V_150 * V_151 )
{
T_1 * V_1 = F_76 ( V_151 ) ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( V_174 L_68 , __FILE__ , V_151 -> V_2 ) ;
F_79 ( V_151 ) ;
V_1 -> V_70 = V_173 -> V_175 ;
F_32 ( V_1 , V_173 -> V_10 , V_173 -> V_175 ) ;
V_151 -> V_176 . V_177 ++ ;
V_151 -> V_176 . V_178 += V_173 -> V_175 ;
F_80 ( V_173 ) ;
V_151 -> V_179 = V_80 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( ! V_1 -> V_69 )
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
return V_180 ;
}
static int F_81 ( struct V_150 * V_151 )
{
T_1 * V_1 = F_76 ( V_151 ) ;
int V_181 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_69 , __FILE__ , V_151 -> V_2 ) ;
if ( ( V_181 = F_82 ( V_151 ) ) )
return V_181 ;
F_11 ( & V_1 -> V_40 , V_11 ) ;
if ( V_1 -> V_28 . V_12 != 0 || V_1 -> V_41 != 0 ) {
F_4 ( V_182 L_70 , V_151 -> V_2 ) ;
F_12 ( & V_1 -> V_40 , V_11 ) ;
return - V_42 ;
}
V_1 -> V_41 = 1 ;
F_12 ( & V_1 -> V_40 , V_11 ) ;
if ( ( V_181 = F_13 ( V_1 ) ) != 0 ) {
F_11 ( & V_1 -> V_40 , V_11 ) ;
V_1 -> V_41 = 0 ;
F_12 ( & V_1 -> V_40 , V_11 ) ;
return V_181 ;
}
V_1 -> V_54 |= V_55 + V_56 ;
F_77 ( V_1 ) ;
V_151 -> V_179 = V_80 ;
F_83 ( V_151 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
if ( V_1 -> V_54 & V_129 )
F_84 ( V_151 ) ;
else
F_85 ( V_151 ) ;
return 0 ;
}
static int F_86 ( struct V_150 * V_151 )
{
T_1 * V_1 = F_76 ( V_151 ) ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_71 , __FILE__ , V_151 -> V_2 ) ;
F_79 ( V_151 ) ;
F_21 ( V_1 ) ;
F_87 ( V_151 ) ;
F_11 ( & V_1 -> V_40 , V_11 ) ;
V_1 -> V_41 = 0 ;
F_12 ( & V_1 -> V_40 , V_11 ) ;
return 0 ;
}
static int F_88 ( struct V_150 * V_151 , struct V_183 * V_184 , int V_86 )
{
const T_5 V_185 = sizeof( V_186 ) ;
V_186 V_187 ;
V_186 T_3 * line = V_184 -> V_188 . V_189 . V_190 ;
T_1 * V_1 = F_76 ( V_151 ) ;
unsigned int V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_72 , __FILE__ , V_151 -> V_2 ) ;
if ( V_1 -> V_28 . V_12 )
return - V_42 ;
if ( V_86 != V_191 )
return F_89 ( V_151 , V_184 , V_86 ) ;
switch( V_184 -> V_188 . type ) {
case V_192 :
V_184 -> V_188 . type = V_193 ;
if ( V_184 -> V_188 . V_185 < V_185 ) {
V_184 -> V_188 . V_185 = V_185 ;
return - V_194 ;
}
V_11 = V_1 -> V_64 . V_11 & ( V_195 | V_196 |
V_197 | V_198 |
V_199 | V_200 |
V_201 | V_202 ) ;
switch ( V_11 ) {
case ( V_195 | V_199 ) : V_187 . V_203 = V_204 ; break;
case ( V_197 | V_201 ) : V_187 . V_203 = V_205 ; break;
case ( V_195 | V_201 ) : V_187 . V_203 = V_206 ; break;
case ( V_195 | V_202 ) : V_187 . V_203 = V_207 ; break;
default: V_187 . V_203 = V_208 ;
}
V_187 . V_209 = V_1 -> V_64 . V_210 ;
V_187 . V_211 = V_1 -> V_64 . V_211 ? 1 : 0 ;
if ( F_90 ( line , & V_187 , V_185 ) )
return - V_212 ;
return 0 ;
case V_193 :
if( ! F_91 ( V_213 ) )
return - V_214 ;
if ( F_92 ( & V_187 , line , V_185 ) )
return - V_212 ;
switch ( V_187 . V_203 )
{
case V_204 : V_11 = V_195 | V_199 ; break;
case V_207 : V_11 = V_195 | V_202 ; break;
case V_205 : V_11 = V_197 | V_201 ; break;
case V_206 : V_11 = V_195 | V_201 ; break;
case V_208 : V_11 = V_1 -> V_64 . V_11 &
( V_195 | V_196 |
V_197 | V_198 |
V_199 | V_200 |
V_201 | V_202 ) ; break;
default: return - V_147 ;
}
if ( V_187 . V_211 != 0 && V_187 . V_211 != 1 )
return - V_147 ;
V_1 -> V_64 . V_11 &= ~ ( V_195 | V_196 |
V_197 | V_198 |
V_199 | V_200 |
V_201 | V_202 ) ;
V_1 -> V_64 . V_11 |= V_11 ;
V_1 -> V_64 . V_211 = V_187 . V_211 ;
if ( V_11 & ( V_197 | V_201 ) )
V_1 -> V_64 . V_210 = V_187 . V_209 ;
else
V_1 -> V_64 . V_210 = 0 ;
if ( V_1 -> V_41 )
F_77 ( V_1 ) ;
return 0 ;
default:
return F_89 ( V_151 , V_184 , V_86 ) ;
}
}
static void F_93 ( struct V_150 * V_151 )
{
T_1 * V_1 = F_76 ( V_151 ) ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_73 , V_151 -> V_2 ) ;
V_151 -> V_176 . V_215 ++ ;
V_151 -> V_176 . V_216 ++ ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_47 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
F_94 ( V_151 ) ;
}
static void F_95 ( T_1 * V_1 )
{
if ( F_96 ( V_1 -> V_217 ) )
F_94 ( V_1 -> V_217 ) ;
}
static void F_97 ( T_1 * V_1 , char * V_60 , int V_185 )
{
struct V_172 * V_173 = F_98 ( V_185 ) ;
struct V_150 * V_151 = V_1 -> V_217 ;
if ( V_29 >= V_30 )
F_4 ( L_74 , V_151 -> V_2 ) ;
if ( V_173 == NULL ) {
F_4 ( V_218 L_75 ,
V_151 -> V_2 ) ;
V_151 -> V_176 . V_219 ++ ;
return;
}
memcpy ( F_99 ( V_173 , V_185 ) , V_60 , V_185 ) ;
V_173 -> V_220 = F_100 ( V_173 , V_151 ) ;
V_151 -> V_176 . V_221 ++ ;
V_151 -> V_176 . V_222 += V_185 ;
F_101 ( V_173 ) ;
}
static int F_102 ( T_1 * V_1 )
{
int V_181 ;
struct V_150 * V_151 ;
T_6 * V_223 ;
if ( ! ( V_151 = F_103 ( V_1 ) ) ) {
F_4 ( V_224 L_76 , __FILE__ ) ;
return - V_225 ;
}
V_151 -> V_226 = V_1 -> V_122 ;
V_151 -> V_227 = V_1 -> V_122 + V_228 - 1 ;
V_151 -> V_229 = V_1 -> V_126 ;
V_151 -> V_230 = & V_231 ;
V_151 -> V_232 = 10 * V_233 ;
V_151 -> V_234 = 50 ;
V_223 = F_104 ( V_151 ) ;
V_223 -> V_235 = F_75 ;
V_223 -> V_236 = F_78 ;
if ( ( V_181 = F_105 ( V_151 ) ) ) {
F_4 ( V_182 L_77 , __FILE__ ) ;
F_106 ( V_151 ) ;
return V_181 ;
}
V_1 -> V_217 = V_151 ;
return 0 ;
}
static void F_107 ( T_1 * V_1 )
{
F_108 ( V_1 -> V_217 ) ;
F_106 ( V_1 -> V_217 ) ;
V_1 -> V_217 = NULL ;
}
static int F_109 ( T_1 * V_1 )
{
unsigned long V_11 ;
int V_181 = 0 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( V_1 -> V_141 & V_237 ) {
V_1 -> V_141 &= ~ V_237 ;
V_181 = V_237 ;
} else if ( V_1 -> V_141 & V_238 ) {
V_1 -> V_141 &= ~ V_238 ;
V_181 = V_238 ;
} else if ( V_1 -> V_141 & V_239 ) {
V_1 -> V_141 &= ~ V_239 ;
V_181 = V_239 ;
}
if ( ! V_181 ) {
V_1 -> V_140 = false ;
V_1 -> V_139 = false ;
}
F_12 ( & V_1 -> V_46 , V_11 ) ;
return V_181 ;
}
static void F_110 ( struct V_240 * V_241 )
{
T_1 * V_1 = F_111 ( V_241 , T_1 , V_242 ) ;
int V_243 ;
if ( ! V_1 )
return;
if ( V_29 >= V_244 )
F_4 ( L_78 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
V_1 -> V_140 = true ;
while( ( V_243 = F_109 ( V_1 ) ) != 0 ) {
if ( V_29 >= V_244 )
F_4 ( L_79 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_243 ) ;
switch ( V_243 ) {
case V_237 :
F_112 ( V_1 ) ;
break;
case V_238 :
F_113 ( V_1 ) ;
break;
case V_239 :
F_114 ( V_1 ) ;
break;
default:
F_4 ( L_80 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_243 ) ;
break;
}
}
if ( V_29 >= V_244 )
F_4 ( L_81 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
}
static void F_112 ( T_1 * V_1 )
{
if ( V_29 >= V_244 )
F_4 ( L_82 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
while( F_115 ( V_1 ) ) ;
}
static void F_113 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_28 . V_9 ;
if ( V_29 >= V_244 )
F_4 ( L_83 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
if ( V_9 )
F_45 ( V_9 ) ;
}
static void F_114 ( T_1 * V_1 )
{
if ( V_29 >= V_244 )
F_4 ( L_84 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
V_1 -> V_245 = 0 ;
V_1 -> V_246 = 0 ;
V_1 -> V_247 = 0 ;
V_1 -> V_248 = 0 ;
}
static void F_116 ( T_1 * V_1 )
{
unsigned char V_249 = ( V_1 -> V_250 & 1 ) ? V_251 : V_252 ;
F_74 ( V_1 , V_253 , 0 ) ;
F_74 ( V_1 , ( unsigned char ) ( V_249 + V_254 ) , 0 ) ;
V_1 -> V_255 = true ;
if ( V_29 >= V_256 )
F_4 ( L_85 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
}
static void F_117 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_28 . V_9 ;
struct V_106 * V_105 = & V_1 -> V_105 ;
unsigned char V_257 = F_73 ( V_1 , V_258 ) & V_1 -> V_259 & ( V_260 + V_261 + V_262 + V_263 ) ;
unsigned char V_264 = F_73 ( V_1 , V_265 ) & V_1 -> V_266 & V_267 ;
if ( V_257 )
F_74 ( V_1 , V_258 , V_257 ) ;
if ( V_264 )
F_74 ( V_1 , V_265 , V_264 ) ;
if ( V_29 >= V_256 )
F_4 ( L_86 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_257 , V_264 ) ;
if ( V_1 -> V_64 . V_65 == V_268 ) {
if ( V_257 & V_263 ) {
V_105 -> V_117 ++ ;
if ( V_9 ) {
if ( ! ( V_257 & V_1 -> V_269 ) ) {
if ( V_1 -> V_270 & V_263 ) {
F_118 ( V_9 , 0 , V_271 ) ;
if ( V_1 -> V_28 . V_11 & V_272 )
F_119 ( V_9 ) ;
}
}
}
}
}
else {
if ( V_257 & ( V_260 | V_261 ) ) {
if ( V_257 & V_260 )
V_1 -> V_105 . V_273 ++ ;
else if ( V_257 & V_261 )
V_1 -> V_105 . V_274 ++ ;
F_25 ( & V_1 -> V_275 ) ;
}
}
if ( V_257 & V_262 ) {
F_62 ( V_1 ) ;
F_120 ( V_1 ,
V_276 | ( V_1 -> V_54 & V_129 ) ) ;
}
}
static void F_121 ( T_1 * V_1 )
{
T_7 V_257 ;
unsigned char V_277 ;
struct V_8 * V_9 = V_1 -> V_28 . V_9 ;
struct V_106 * V_105 = & V_1 -> V_105 ;
if ( V_29 >= V_256 )
F_4 ( L_87 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
while( ( V_257 = F_73 ( V_1 , V_278 ) ) & V_279 )
{
int V_280 = 0 ;
bool V_281 = false ;
V_277 = F_73 ( V_1 , V_282 ) ;
V_105 -> V_112 ++ ;
if ( V_257 & ( V_283 + V_284 + V_267 ) ) {
F_4 ( L_88 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_257 ) ;
if ( V_257 & V_283 )
V_105 -> V_116 ++ ;
else if ( V_257 & V_284 )
V_105 -> V_114 ++ ;
else if ( V_257 & V_267 )
V_105 -> V_115 ++ ;
if ( V_257 & V_1 -> V_285 )
continue;
V_257 &= V_1 -> V_286 ;
if ( V_9 ) {
if ( V_257 & V_283 )
V_280 = V_287 ;
else if ( V_257 & V_284 )
V_280 = V_288 ;
if ( V_257 & V_267 ) {
V_281 = true ;
}
}
}
if ( V_9 ) {
F_118 ( V_9 , V_277 , V_280 ) ;
if ( V_281 )
F_118 ( V_9 , 0 , V_289 ) ;
}
}
if ( V_29 >= V_256 ) {
F_4 ( L_89 ,
__FILE__ , __LINE__ , V_1 -> V_26 ,
V_105 -> V_112 , V_105 -> V_117 , V_105 -> V_116 ,
V_105 -> V_114 , V_105 -> V_115 ) ;
}
if ( V_9 )
F_122 ( V_9 ) ;
}
static void F_123 ( T_1 * V_1 , unsigned char V_257 )
{
if ( V_29 >= V_256 )
F_4 ( L_90 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_257 ) ;
F_74 ( V_1 , V_290 + V_291 , 0x00 ) ;
F_74 ( V_1 , V_290 + V_292 , 0xc0 ) ;
F_74 ( V_1 , V_290 + V_293 , V_294 ) ;
if ( V_257 & V_295 ) {
F_74 ( V_1 , V_296 , V_297 ) ;
F_74 ( V_1 , V_296 , V_298 ) ;
} else
F_74 ( V_1 , V_296 , V_299 ) ;
V_1 -> V_300 &= ~ V_301 ;
V_1 -> V_259 &= ~ ( V_302 + V_295 ) ;
F_124 ( V_1 , V_303 , ( unsigned short ) ( ( V_1 -> V_259 << 8 ) + V_1 -> V_300 ) ) ;
F_74 ( V_1 , V_258 , ( unsigned char ) ( V_295 + V_302 ) ) ;
if ( V_1 -> V_69 ) {
if ( V_1 -> V_64 . V_65 != V_268 ) {
if ( V_257 & V_295 )
V_1 -> V_105 . V_133 ++ ;
else if ( V_257 & V_302 )
V_1 -> V_105 . V_131 ++ ;
}
V_1 -> V_69 = false ;
V_1 -> V_70 = V_1 -> V_72 = V_1 -> V_84 = 0 ;
F_44 ( & V_1 -> V_85 ) ;
if ( V_1 -> V_64 . V_65 != V_268 && V_1 -> V_304 ) {
V_1 -> V_54 &= ~ V_55 ;
V_1 -> V_304 = false ;
F_28 ( V_1 ) ;
}
#if V_305
if ( V_1 -> V_41 )
F_95 ( V_1 ) ;
else
#endif
{
if ( V_1 -> V_28 . V_9 && ( V_1 -> V_28 . V_9 -> V_73 || V_1 -> V_28 . V_9 -> V_59 ) ) {
F_47 ( V_1 ) ;
return;
}
V_1 -> V_141 |= V_238 ;
}
}
}
static void F_125 ( T_1 * V_1 )
{
unsigned char V_257 = F_73 ( V_1 , V_258 ) & V_1 -> V_259 & ( V_295 + V_302 + V_306 ) ;
F_74 ( V_1 , V_258 , V_257 ) ;
if ( V_29 >= V_256 )
F_4 ( L_91 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_257 ) ;
if ( V_257 & ( V_295 + V_302 ) )
F_123 ( V_1 , V_257 ) ;
if ( V_257 & V_306 ) {
F_62 ( V_1 ) ;
F_120 ( V_1 ,
V_307 | ( V_1 -> V_54 & V_127 ) ) ;
}
}
static void F_126 ( T_1 * V_1 )
{
if ( V_29 >= V_256 )
F_4 ( L_92 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_70 ) ;
if ( V_1 -> V_64 . V_65 != V_268 ) {
V_1 -> V_300 &= ~ V_301 ;
V_1 -> V_259 |= V_302 ;
F_124 ( V_1 , V_303 , ( unsigned short ) ( ( V_1 -> V_259 << 8 ) + V_1 -> V_300 ) ) ;
return;
}
if ( V_1 -> V_28 . V_9 && ( V_1 -> V_28 . V_9 -> V_73 || V_1 -> V_28 . V_9 -> V_59 ) ) {
F_47 ( V_1 ) ;
return;
}
if ( V_1 -> V_70 )
F_127 ( V_1 ) ;
else {
V_1 -> V_69 = false ;
V_1 -> V_300 &= ~ V_301 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
}
if ( V_1 -> V_70 < V_308 )
V_1 -> V_141 |= V_238 ;
}
static void F_128 ( T_1 * V_1 )
{
unsigned char V_257 = F_73 ( V_1 , V_309 + V_292 ) & 0xc0 ;
F_74 ( V_1 , V_309 + V_292 , ( unsigned char ) ( V_257 | 1 ) ) ;
if ( V_29 >= V_256 )
F_4 ( L_93 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_257 ) ;
V_1 -> V_141 |= V_237 ;
}
static void F_129 ( T_1 * V_1 )
{
unsigned char V_257 = F_73 ( V_1 , V_309 + V_292 ) & 0x30 ;
F_74 ( V_1 , V_309 + V_292 , ( unsigned char ) ( V_257 | 1 ) ) ;
if ( V_29 >= V_256 )
F_4 ( L_94 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_257 ) ;
V_1 -> V_310 = true ;
V_1 -> V_141 |= V_237 ;
}
static void F_130 ( T_1 * V_1 )
{
unsigned char V_311 = F_73 ( V_1 , V_258 ) ;
F_74 ( V_1 , V_290 + V_291 , 0x00 ) ;
F_74 ( V_1 , V_290 + V_292 , 0xc0 ) ;
F_74 ( V_1 , V_290 + V_293 , V_294 ) ;
if ( V_29 >= V_256 )
F_4 ( L_95 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_311 ) ;
F_124 ( V_1 , V_312 , 0 ) ;
V_1 -> V_300 |= V_301 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
}
static void F_131 ( T_1 * V_1 )
{
unsigned char V_257 = F_73 ( V_1 , V_290 + V_292 ) & 0x30 ;
F_74 ( V_1 , V_290 + V_292 , ( unsigned char ) ( V_257 | 1 ) ) ;
if ( V_29 >= V_256 )
F_4 ( L_96 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_257 ) ;
}
static void F_120 ( T_1 * V_1 , T_7 V_257 )
{
struct V_106 * V_105 ;
if ( V_29 >= V_256 )
F_4 ( L_97 ,
__FILE__ , __LINE__ , V_257 ) ;
if ( V_257 & ( V_307 | V_276 |
V_313 | V_314 ) ) {
V_105 = & V_1 -> V_105 ;
if ( V_257 & V_314 ) {
V_105 -> V_110 ++ ;
if ( V_257 & V_130 )
V_1 -> V_315 . V_316 ++ ;
else
V_1 -> V_315 . V_317 ++ ;
}
if ( V_257 & V_313 ) {
V_105 -> V_109 ++ ;
if ( V_257 & V_128 )
V_1 -> V_315 . V_318 ++ ;
else
V_1 -> V_315 . V_319 ++ ;
}
if ( V_257 & V_276 ) {
if ( ( V_1 -> V_247 ) ++ >= V_320 ) {
V_1 -> V_259 &= ~ V_262 ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
}
V_105 -> V_111 ++ ;
if ( V_257 & V_129 ) {
V_1 -> V_315 . V_322 ++ ;
} else
V_1 -> V_315 . V_323 ++ ;
#if V_305
if ( V_1 -> V_41 ) {
if ( V_257 & V_129 )
F_84 ( V_1 -> V_217 ) ;
else
F_85 ( V_1 -> V_217 ) ;
}
#endif
}
if ( V_257 & V_307 )
{
if ( ( V_1 -> V_248 ) ++ >= V_320 ) {
V_1 -> V_259 &= ~ V_306 ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
}
V_105 -> V_108 ++ ;
if ( V_257 & V_127 )
V_1 -> V_315 . V_324 ++ ;
else
V_1 -> V_315 . V_325 ++ ;
}
F_25 ( & V_1 -> V_326 ) ;
F_25 ( & V_1 -> V_275 ) ;
if ( ( V_1 -> V_28 . V_11 & V_327 ) &&
( V_257 & V_276 ) ) {
if ( V_29 >= V_256 )
F_4 ( L_98 , V_1 -> V_26 ,
( V_257 & V_129 ) ? L_99 : L_100 ) ;
if ( V_257 & V_129 )
F_25 ( & V_1 -> V_28 . V_48 ) ;
else {
if ( V_29 >= V_256 )
F_4 ( L_101 ) ;
if ( V_1 -> V_28 . V_9 )
F_132 ( V_1 -> V_28 . V_9 ) ;
}
}
if ( ( V_1 -> V_28 . V_11 & V_328 ) &&
( V_257 & V_307 ) ) {
if ( V_1 -> V_28 . V_9 ) {
if ( V_1 -> V_28 . V_9 -> V_59 ) {
if ( V_257 & V_127 ) {
if ( V_29 >= V_256 )
F_4 ( L_102 ) ;
V_1 -> V_28 . V_9 -> V_59 = 0 ;
F_35 ( V_1 ) ;
V_1 -> V_141 |= V_238 ;
return;
}
} else {
if ( ! ( V_257 & V_127 ) ) {
if ( V_29 >= V_256 )
F_4 ( L_103 ) ;
V_1 -> V_28 . V_9 -> V_59 = 1 ;
F_47 ( V_1 ) ;
}
}
}
}
}
V_1 -> V_141 |= V_239 ;
}
static T_8 F_133 ( int V_329 , void * V_330 )
{
T_1 * V_1 = V_330 ;
unsigned char V_257 , V_331 , V_332 = 0 ;
unsigned char V_333 , V_334 , V_335 = 0 ;
unsigned char V_336 , V_337 = 0 ;
unsigned char V_338 ;
unsigned int V_339 ;
unsigned short V_340 ;
if ( V_29 >= V_256 )
F_4 ( V_341 L_104 ,
__FILE__ , __LINE__ , V_1 -> V_126 ) ;
F_134 ( & V_1 -> V_46 ) ;
for(; ; ) {
V_340 = F_135 ( V_1 , V_342 ) ;
V_331 = ( unsigned char ) V_340 ;
V_334 = ( unsigned char ) ( V_340 >> 8 ) ;
V_336 = F_73 ( V_1 , V_343 ) ;
if ( V_29 >= V_256 )
F_4 ( V_341 L_105 ,
__FILE__ , __LINE__ , V_1 -> V_26 ,
V_331 , V_334 , V_336 ) ;
if ( V_1 -> V_344 == 4 ) {
V_340 = F_135 ( V_1 -> V_345 [ 2 ] , V_342 ) ;
V_332 = ( unsigned char ) V_340 ;
V_335 = ( unsigned char ) ( V_340 >> 8 ) ;
V_337 = F_73 ( V_1 -> V_345 [ 2 ] , V_343 ) ;
if ( V_29 >= V_256 )
F_4 ( L_106 ,
__FILE__ , __LINE__ , V_1 -> V_26 ,
V_332 , V_335 , V_337 ) ;
}
if ( ! V_331 && ! V_334 && ! V_336 &&
! V_332 && ! V_335 && ! V_337 )
break;
for( V_339 = 0 ; V_339 < V_1 -> V_344 ; V_339 ++ ) {
if ( V_1 -> V_345 [ V_339 ] == NULL )
continue;
if ( V_339 < 2 ) {
V_257 = V_331 ;
V_333 = V_334 ;
} else {
V_257 = V_332 ;
V_333 = V_335 ;
}
V_338 = V_339 & 1 ? 4 : 0 ;
if ( V_257 & V_279 << V_338 )
F_121 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_257 & V_346 << V_338 )
F_126 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_257 & V_347 << V_338 )
F_117 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_257 & V_149 << V_338 )
F_125 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_333 & V_279 << V_338 )
F_129 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_333 & V_346 << V_338 )
F_128 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_333 & V_347 << V_338 )
F_131 ( V_1 -> V_345 [ V_339 ] ) ;
if ( V_333 & V_149 << V_338 )
F_130 ( V_1 -> V_345 [ V_339 ] ) ;
}
if ( V_336 & ( V_348 | V_349 ) )
F_116 ( V_1 -> V_345 [ 0 ] ) ;
if ( V_336 & ( V_350 | V_351 ) )
F_116 ( V_1 -> V_345 [ 1 ] ) ;
if ( V_337 & ( V_348 | V_349 ) )
F_116 ( V_1 -> V_345 [ 2 ] ) ;
if ( V_337 & ( V_350 | V_351 ) )
F_116 ( V_1 -> V_345 [ 3 ] ) ;
}
for( V_339 = 0 ; V_339 < V_1 -> V_344 ; V_339 ++ ) {
T_1 * V_28 = V_1 -> V_345 [ V_339 ] ;
if ( V_28 && ( V_28 -> V_28 . V_12 || V_28 -> V_41 ) &&
V_28 -> V_141 && ! V_28 -> V_140 &&
! V_28 -> V_139 ) {
if ( V_29 >= V_256 )
F_4 ( L_107 ,
__FILE__ , __LINE__ , V_28 -> V_26 ) ;
F_136 ( & V_28 -> V_242 ) ;
V_28 -> V_139 = true ;
}
}
F_137 ( & V_1 -> V_46 ) ;
if ( V_29 >= V_256 )
F_4 ( V_341 L_108 ,
__FILE__ , __LINE__ , V_1 -> V_126 ) ;
return V_352 ;
}
static int F_13 ( T_1 * V_1 )
{
if ( V_29 >= V_30 )
F_4 ( L_109 , __FILE__ , __LINE__ , V_1 -> V_26 ) ;
if ( V_1 -> V_28 . V_11 & V_44 )
return 0 ;
if ( ! V_1 -> V_63 ) {
V_1 -> V_63 = F_138 ( V_1 -> V_67 , V_353 ) ;
if ( ! V_1 -> V_63 ) {
F_4 ( V_224 L_110 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
return - V_225 ;
}
}
V_1 -> V_141 = 0 ;
memset ( & V_1 -> V_105 , 0 , sizeof( V_1 -> V_105 ) ) ;
F_139 ( V_1 ) ;
F_27 ( V_1 ) ;
F_140 ( & V_1 -> V_354 , V_80 + F_141 ( 10 ) ) ;
if ( V_1 -> V_28 . V_9 )
F_142 ( V_92 , & V_1 -> V_28 . V_9 -> V_11 ) ;
V_1 -> V_28 . V_11 |= V_44 ;
return 0 ;
}
static void F_21 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( ! ( V_1 -> V_28 . V_11 & V_44 ) )
return;
if ( V_29 >= V_30 )
F_4 ( L_111 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_25 ( & V_1 -> V_326 ) ;
F_25 ( & V_1 -> V_275 ) ;
F_44 ( & V_1 -> V_85 ) ;
F_44 ( & V_1 -> V_354 ) ;
F_143 ( V_1 -> V_63 ) ;
V_1 -> V_63 = NULL ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_139 ( V_1 ) ;
if ( ! V_1 -> V_28 . V_9 || V_1 -> V_28 . V_9 -> V_53 -> V_51 & V_355 ) {
V_1 -> V_54 &= ~ ( V_56 + V_55 ) ;
F_28 ( V_1 ) ;
}
F_12 ( & V_1 -> V_46 , V_11 ) ;
if ( V_1 -> V_28 . V_9 )
F_144 ( V_92 , & V_1 -> V_28 . V_9 -> V_11 ) ;
V_1 -> V_28 . V_11 &= ~ V_44 ;
}
static void F_77 ( T_1 * V_1 )
{
unsigned long V_11 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_145 ( V_1 ) ;
F_47 ( V_1 ) ;
V_1 -> V_70 = V_1 -> V_72 = V_1 -> V_84 = 0 ;
if ( V_1 -> V_64 . V_65 == V_66 || V_1 -> V_41 )
F_146 ( V_1 ) ;
else
F_147 ( V_1 ) ;
F_28 ( V_1 ) ;
V_1 -> V_247 = 0 ;
V_1 -> V_248 = 0 ;
V_1 -> V_245 = 0 ;
V_1 -> V_246 = 0 ;
V_1 -> V_259 |= ( V_262 | V_306 ) ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
F_62 ( V_1 ) ;
if ( V_1 -> V_41 || ( V_1 -> V_28 . V_9 && V_1 -> V_28 . V_9 -> V_53 -> V_51 & V_356 ) )
F_148 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
static void F_27 ( T_1 * V_1 )
{
unsigned V_357 ;
int V_358 ;
if ( ! V_1 -> V_28 . V_9 || ! V_1 -> V_28 . V_9 -> V_53 )
return;
if ( V_29 >= V_30 )
F_4 ( L_112 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
V_357 = V_1 -> V_28 . V_9 -> V_53 -> V_51 ;
if ( V_357 & V_52 )
V_1 -> V_54 |= V_55 + V_56 ;
else
V_1 -> V_54 &= ~ ( V_55 + V_56 ) ;
switch ( V_357 & V_359 ) {
case V_360 : V_1 -> V_64 . V_361 = 5 ; break;
case V_362 : V_1 -> V_64 . V_361 = 6 ; break;
case V_363 : V_1 -> V_64 . V_361 = 7 ; break;
case V_364 : V_1 -> V_64 . V_361 = 8 ; break;
default: V_1 -> V_64 . V_361 = 7 ; break;
}
if ( V_357 & V_365 )
V_1 -> V_64 . V_366 = 2 ;
else
V_1 -> V_64 . V_366 = 1 ;
V_1 -> V_64 . V_116 = V_367 ;
if ( V_357 & V_368 ) {
if ( V_357 & V_369 )
V_1 -> V_64 . V_116 = V_370 ;
else
V_1 -> V_64 . V_116 = V_371 ;
#ifdef F_149
if ( V_357 & F_149 )
V_1 -> V_64 . V_116 = V_372 ;
#endif
}
V_358 = V_1 -> V_64 . V_361 +
V_1 -> V_64 . V_366 + 1 ;
if ( V_1 -> V_64 . V_81 <= 460800 ) {
V_1 -> V_64 . V_81 = F_150 ( V_1 -> V_28 . V_9 ) ;
}
if ( V_1 -> V_64 . V_81 ) {
V_1 -> V_45 = ( 32 * V_233 * V_358 ) /
V_1 -> V_64 . V_81 ;
}
V_1 -> V_45 += V_233 / 50 ;
if ( V_357 & V_57 )
V_1 -> V_28 . V_11 |= V_328 ;
else
V_1 -> V_28 . V_11 &= ~ V_328 ;
if ( V_357 & V_373 )
V_1 -> V_28 . V_11 &= ~ V_327 ;
else
V_1 -> V_28 . V_11 |= V_327 ;
V_1 -> V_286 = V_267 ;
if ( F_151 ( V_1 -> V_28 . V_9 ) )
V_1 -> V_286 |= V_283 | V_284 ;
if ( F_152 ( V_1 -> V_28 . V_9 ) || F_153 ( V_1 -> V_28 . V_9 ) )
V_1 -> V_270 |= V_263 ;
if ( F_154 ( V_1 -> V_28 . V_9 ) )
V_1 -> V_285 |= V_283 | V_284 ;
if ( F_155 ( V_1 -> V_28 . V_9 ) ) {
V_1 -> V_269 |= V_263 ;
if ( F_154 ( V_1 -> V_28 . V_9 ) )
V_1 -> V_285 |= V_267 ;
}
F_77 ( V_1 ) ;
}
static int F_56 ( T_1 * V_1 , struct V_106 T_3 * V_374 )
{
int V_375 ;
if ( V_29 >= V_30 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
if ( ! V_374 ) {
memset ( & V_1 -> V_105 , 0 , sizeof( V_1 -> V_105 ) ) ;
} else {
F_17 ( & V_1 -> V_28 . V_43 ) ;
F_156 ( V_375 , V_374 , & V_1 -> V_105 , sizeof( struct V_106 ) ) ;
F_22 ( & V_1 -> V_28 . V_43 ) ;
if ( V_375 )
return - V_212 ;
}
return 0 ;
}
static int F_49 ( T_1 * V_1 , T_9 T_3 * V_376 )
{
int V_375 ;
if ( V_29 >= V_30 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_17 ( & V_1 -> V_28 . V_43 ) ;
F_156 ( V_375 , V_376 , & V_1 -> V_64 , sizeof( T_9 ) ) ;
F_22 ( & V_1 -> V_28 . V_43 ) ;
if ( V_375 ) {
if ( V_29 >= V_30 )
F_4 ( L_114 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
return - V_212 ;
}
return 0 ;
}
static int F_50 ( T_1 * V_1 , T_9 T_3 * V_377 )
{
unsigned long V_11 ;
T_9 V_378 ;
int V_375 ;
if ( V_29 >= V_30 )
F_4 ( L_115 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_157 ( V_375 , & V_378 , V_377 , sizeof( T_9 ) ) ;
if ( V_375 ) {
if ( V_29 >= V_30 )
F_4 ( L_116 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
return - V_212 ;
}
F_17 ( & V_1 -> V_28 . V_43 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
memcpy ( & V_1 -> V_64 , & V_378 , sizeof( T_9 ) ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
F_27 ( V_1 ) ;
F_22 ( & V_1 -> V_28 . V_43 ) ;
return 0 ;
}
static int F_51 ( T_1 * V_1 , int T_3 * V_379 )
{
int V_375 ;
if ( V_29 >= V_30 )
F_4 ( L_117 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_379 ) ;
F_156 ( V_375 , V_379 , & V_1 -> V_379 , sizeof( int ) ) ;
if ( V_375 ) {
if ( V_29 >= V_30 )
F_4 ( L_118 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
return - V_212 ;
}
return 0 ;
}
static int F_52 ( T_1 * V_1 , int V_379 )
{
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_119 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_379 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_1 -> V_379 = V_379 ;
F_158 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
return 0 ;
}
static int F_53 ( T_1 * V_1 , int V_380 )
{
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_120 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_380 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( V_380 ) {
if ( ! V_1 -> V_76 ) {
F_35 ( V_1 ) ;
}
} else {
if ( V_1 -> V_76 )
F_47 ( V_1 ) ;
}
F_12 ( & V_1 -> V_46 , V_11 ) ;
return 0 ;
}
static int F_55 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_121 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( V_1 -> V_69 && V_1 -> V_64 . V_65 == V_66 ) {
V_1 -> V_259 &= ~ V_295 ;
V_1 -> V_259 |= V_302 ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
F_74 ( V_1 , V_258 , ( unsigned char ) ( V_302 + V_295 ) ) ;
F_74 ( V_1 , V_290 + V_292 , 0 ) ;
F_74 ( V_1 , V_290 + V_293 , V_294 ) ;
F_74 ( V_1 , V_296 , V_381 ) ;
}
F_12 ( & V_1 -> V_46 , V_11 ) ;
return 0 ;
}
static int F_54 ( T_1 * V_1 , int V_380 )
{
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_122 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_380 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( V_380 ) {
if ( ! V_1 -> V_382 )
F_148 ( V_1 ) ;
} else {
if ( V_1 -> V_382 )
F_145 ( V_1 ) ;
}
F_12 ( & V_1 -> V_46 , V_11 ) ;
return 0 ;
}
static int F_57 ( T_1 * V_1 , int T_3 * V_383 )
{
unsigned long V_11 ;
int V_384 ;
int V_181 = 0 ;
struct V_106 V_385 , V_107 ;
int V_386 ;
int V_387 ;
struct V_388 V_389 , V_390 ;
F_159 ( V_391 , V_82 ) ;
F_157 ( V_181 , & V_387 , V_383 , sizeof( int ) ) ;
if ( V_181 ) {
return - V_212 ;
}
if ( V_29 >= V_30 )
F_4 ( L_123 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_387 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_62 ( V_1 ) ;
V_384 = V_1 -> V_54 ;
V_386 = V_387 &
( ( ( V_384 & V_128 ) ? V_392 : V_393 ) +
( ( V_384 & V_129 ) ? V_394 : V_395 ) +
( ( V_384 & V_127 ) ? V_396 : V_397 ) +
( ( V_384 & V_130 ) ? V_398 : V_399 ) ) ;
if ( V_386 ) {
F_12 ( & V_1 -> V_46 , V_11 ) ;
goto exit;
}
V_385 = V_1 -> V_105 ;
V_389 = V_1 -> V_315 ;
if ( V_387 & ( V_400 + V_401 ) ) {
unsigned char V_402 = V_1 -> V_259 ;
unsigned char V_403 = V_402 +
( V_387 & V_400 ? V_260 : 0 ) +
( V_387 & V_401 ? V_261 : 0 ) ;
if ( V_402 != V_403 ) {
V_1 -> V_259 = V_403 ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
}
}
F_160 ( V_404 ) ;
F_161 ( & V_1 -> V_275 , & V_391 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
for(; ; ) {
F_162 () ;
if ( F_40 ( V_82 ) ) {
V_181 = - V_36 ;
break;
}
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_107 = V_1 -> V_105 ;
V_390 = V_1 -> V_315 ;
F_160 ( V_404 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
if ( V_390 . V_318 == V_389 . V_318 &&
V_390 . V_319 == V_389 . V_319 &&
V_390 . V_322 == V_389 . V_322 &&
V_390 . V_323 == V_389 . V_323 &&
V_390 . V_324 == V_389 . V_324 &&
V_390 . V_325 == V_389 . V_325 &&
V_390 . V_316 == V_389 . V_316 &&
V_390 . V_317 == V_389 . V_317 &&
V_107 . V_273 == V_385 . V_273 &&
V_107 . V_274 == V_385 . V_274 ) {
V_181 = - V_68 ;
break;
}
V_386 = V_387 &
( ( V_390 . V_318 != V_389 . V_318 ? V_392 : 0 ) +
( V_390 . V_319 != V_389 . V_319 ? V_393 : 0 ) +
( V_390 . V_322 != V_389 . V_322 ? V_394 : 0 ) +
( V_390 . V_323 != V_389 . V_323 ? V_395 : 0 ) +
( V_390 . V_324 != V_389 . V_324 ? V_396 : 0 ) +
( V_390 . V_325 != V_389 . V_325 ? V_397 : 0 ) +
( V_390 . V_316 != V_389 . V_316 ? V_398 : 0 ) +
( V_390 . V_317 != V_389 . V_317 ? V_399 : 0 ) +
( V_107 . V_273 != V_385 . V_273 ? V_400 : 0 ) +
( V_107 . V_274 != V_385 . V_274 ? V_401 : 0 ) ) ;
if ( V_386 )
break;
V_385 = V_107 ;
V_389 = V_390 ;
}
F_163 ( & V_1 -> V_275 , & V_391 ) ;
F_160 ( V_405 ) ;
if ( V_387 & ( V_400 + V_401 ) ) {
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( ! F_164 ( & V_1 -> V_275 ) ) {
V_1 -> V_259 &= ~ ( V_260 | V_261 ) ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
}
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
exit:
if ( V_181 == 0 )
F_165 ( V_181 , V_386 , V_383 ) ;
return V_181 ;
}
static int F_58 ( T_1 * V_1 , int V_87 )
{
unsigned long V_11 ;
int V_181 ;
struct V_106 V_385 , V_107 ;
F_159 ( V_391 , V_82 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_385 = V_1 -> V_105 ;
F_161 ( & V_1 -> V_326 , & V_391 ) ;
F_160 ( V_404 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
for(; ; ) {
F_162 () ;
if ( F_40 ( V_82 ) ) {
V_181 = - V_36 ;
break;
}
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_107 = V_1 -> V_105 ;
F_160 ( V_404 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
if ( V_107 . V_110 == V_385 . V_110 && V_107 . V_109 == V_385 . V_109 &&
V_107 . V_111 == V_385 . V_111 && V_107 . V_108 == V_385 . V_108 ) {
V_181 = - V_68 ;
break;
}
if ( ( V_87 & V_406 && V_107 . V_110 != V_385 . V_110 ) ||
( V_87 & V_407 && V_107 . V_109 != V_385 . V_109 ) ||
( V_87 & V_408 && V_107 . V_111 != V_385 . V_111 ) ||
( V_87 & V_409 && V_107 . V_108 != V_385 . V_108 ) ) {
V_181 = 0 ;
break;
}
V_385 = V_107 ;
}
F_163 ( & V_1 -> V_326 , & V_391 ) ;
F_160 ( V_405 ) ;
return V_181 ;
}
static int F_166 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned int V_410 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
V_410 = ( ( V_1 -> V_54 & V_55 ) ? V_411 : 0 ) +
( ( V_1 -> V_54 & V_56 ) ? V_412 : 0 ) +
( ( V_1 -> V_54 & V_129 ) ? V_413 : 0 ) +
( ( V_1 -> V_54 & V_130 ) ? V_406 : 0 ) +
( ( V_1 -> V_54 & V_128 ) ? V_407 : 0 ) +
( ( V_1 -> V_54 & V_127 ) ? V_409 : 0 ) ;
if ( V_29 >= V_30 )
F_4 ( L_124 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_410 ) ;
return V_410 ;
}
static int F_167 ( struct V_8 * V_9 ,
unsigned int V_414 , unsigned int V_415 )
{
T_1 * V_1 = V_9 -> V_27 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_125 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_414 , V_415 ) ;
if ( V_414 & V_411 )
V_1 -> V_54 |= V_55 ;
if ( V_414 & V_412 )
V_1 -> V_54 |= V_56 ;
if ( V_415 & V_411 )
V_1 -> V_54 &= ~ V_55 ;
if ( V_415 & V_412 )
V_1 -> V_54 &= ~ V_56 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
return 0 ;
}
static int F_168 ( struct V_416 * V_28 )
{
T_1 * V_1 = F_111 ( V_28 , T_1 , V_28 ) ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
return ( V_1 -> V_54 & V_129 ) ? 1 : 0 ;
}
static void F_169 ( struct V_416 * V_28 , int V_417 )
{
T_1 * V_1 = F_111 ( V_28 , T_1 , V_28 ) ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( V_417 )
V_1 -> V_54 |= V_55 + V_56 ;
else
V_1 -> V_54 &= ~ ( V_55 + V_56 ) ;
F_28 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
static int F_14 ( struct V_8 * V_9 , struct V_17 * V_18 ,
T_1 * V_1 )
{
F_159 ( V_391 , V_82 ) ;
int V_19 ;
bool V_418 = false ;
bool V_419 = false ;
unsigned long V_11 ;
int V_420 ;
struct V_416 * V_28 = & V_1 -> V_28 ;
if ( V_29 >= V_30 )
F_4 ( L_126 ,
__FILE__ , __LINE__ , V_9 -> V_31 -> V_2 ) ;
if ( V_18 -> V_421 & V_422 || V_9 -> V_11 & ( 1 << V_92 ) ) {
V_28 -> V_11 |= V_47 ;
return 0 ;
}
if ( V_9 -> V_53 -> V_51 & V_373 )
V_418 = true ;
V_19 = 0 ;
F_161 ( & V_28 -> V_48 , & V_391 ) ;
if ( V_29 >= V_30 )
F_4 ( L_127 ,
__FILE__ , __LINE__ , V_9 -> V_31 -> V_2 , V_28 -> V_12 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
if ( ! F_9 ( V_18 ) ) {
V_419 = true ;
V_28 -> V_12 -- ;
}
F_12 ( & V_1 -> V_46 , V_11 ) ;
V_28 -> V_423 ++ ;
while ( 1 ) {
if ( V_9 -> V_53 -> V_51 & V_52 )
F_170 ( V_28 ) ;
F_160 ( V_404 ) ;
if ( F_9 ( V_18 ) || ! ( V_28 -> V_11 & V_44 ) ) {
V_19 = ( V_28 -> V_11 & V_34 ) ?
- V_35 : - V_36 ;
break;
}
V_420 = F_171 ( V_28 ) ;
if ( ! ( V_28 -> V_11 & V_32 ) && ( V_418 || V_420 ) )
break;
if ( F_40 ( V_82 ) ) {
V_19 = - V_36 ;
break;
}
if ( V_29 >= V_30 )
F_4 ( L_128 ,
__FILE__ , __LINE__ , V_9 -> V_31 -> V_2 , V_28 -> V_12 ) ;
F_172 () ;
F_162 () ;
F_173 () ;
}
F_160 ( V_405 ) ;
F_163 ( & V_28 -> V_48 , & V_391 ) ;
if ( V_419 )
V_28 -> V_12 ++ ;
V_28 -> V_423 -- ;
if ( V_29 >= V_30 )
F_4 ( L_129 ,
__FILE__ , __LINE__ , V_9 -> V_31 -> V_2 , V_28 -> V_12 ) ;
if ( ! V_19 )
V_28 -> V_11 |= V_47 ;
return V_19 ;
}
static int F_174 ( T_1 * V_1 )
{
unsigned short V_424 ;
unsigned short V_425 ;
V_1 -> V_345 [ 0 ] -> V_426 = ( V_427 / 4 ) * V_1 -> V_250 ;
V_424 = ( unsigned short ) ( V_1 -> V_67 / V_428 ) ;
if ( V_1 -> V_67 % V_428 )
V_424 ++ ;
V_425 = ( V_427 / 4 - V_429 ) / V_428 ;
if ( V_425 > V_429 / sizeof( V_430 ) )
V_425 = V_429 / sizeof( V_430 ) ;
V_1 -> V_431 = V_424 + 1 ;
if ( V_1 -> V_431 > ( V_425 / 2 ) )
V_1 -> V_431 = V_425 / 2 ;
if ( V_1 -> V_431 > V_432 )
V_1 -> V_431 = V_432 ;
V_1 -> V_433 = V_425 - V_1 -> V_431 ;
if ( V_1 -> V_433 > V_432 )
V_1 -> V_433 = V_432 ;
if ( V_29 >= V_30 )
F_4 ( L_130 ,
__FILE__ , __LINE__ , V_1 -> V_26 ,
V_1 -> V_431 , V_1 -> V_433 ) ;
if ( F_175 ( V_1 ) < 0 ||
F_176 ( V_1 ,
V_1 -> V_434 ,
V_1 -> V_435 ,
V_1 -> V_433 ) < 0 ||
F_176 ( V_1 ,
V_1 -> V_436 ,
V_1 -> V_437 ,
V_1 -> V_431 ) < 0 ||
F_177 ( V_1 ) < 0 ) {
F_4 ( L_131 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
return - V_225 ;
}
F_178 ( V_1 ) ;
return 0 ;
}
static int F_175 ( T_1 * V_1 )
{
unsigned int V_339 ;
V_1 -> V_438 = V_1 -> V_439 + V_1 -> V_345 [ 0 ] -> V_426 ;
V_1 -> V_440 = V_1 -> V_345 [ 0 ] -> V_426 ;
V_1 -> V_345 [ 0 ] -> V_426 += V_429 ;
memset ( V_1 -> V_438 , 0 , V_429 ) ;
V_1 -> V_434 = ( V_430 * ) V_1 -> V_438 ;
V_1 -> V_436 = ( V_430 * ) V_1 -> V_438 ;
V_1 -> V_436 += V_1 -> V_433 ;
for ( V_339 = 0 ; V_339 < V_1 -> V_433 ; V_339 ++ ) {
V_1 -> V_435 [ V_339 ] . V_441 =
V_1 -> V_440 + ( V_339 * sizeof( V_428 ) ) ;
V_1 -> V_434 [ V_339 ] . V_442 = V_1 -> V_440 ;
if ( V_339 < V_1 -> V_433 - 1 )
V_1 -> V_434 [ V_339 ] . V_442 += ( V_339 + 1 ) * sizeof( V_430 ) ;
V_1 -> V_434 [ V_339 ] . V_443 = V_428 ;
}
for ( V_339 = 0 ; V_339 < V_1 -> V_431 ; V_339 ++ ) {
V_1 -> V_437 [ V_339 ] . V_441 = V_1 -> V_440 +
( ( V_1 -> V_433 + V_339 ) * sizeof( V_430 ) ) ;
V_1 -> V_436 [ V_339 ] . V_442 = V_1 -> V_440 +
V_1 -> V_433 * sizeof( V_430 ) ;
if ( V_339 < V_1 -> V_431 - 1 )
V_1 -> V_436 [ V_339 ] . V_442 += ( V_339 + 1 ) * sizeof( V_430 ) ;
}
return 0 ;
}
static int F_176 ( T_1 * V_1 , V_430 * V_444 , T_10 * V_445 , int V_12 )
{
int V_339 ;
unsigned long V_446 ;
for ( V_339 = 0 ; V_339 < V_12 ; V_339 ++ ) {
V_445 [ V_339 ] . V_447 = V_1 -> V_439 + V_1 -> V_345 [ 0 ] -> V_426 ;
V_446 = V_1 -> V_345 [ 0 ] -> V_426 ;
V_1 -> V_345 [ 0 ] -> V_426 += V_428 ;
V_444 [ V_339 ] . V_448 = ( unsigned short ) V_446 ;
V_444 [ V_339 ] . V_449 = ( unsigned char ) ( V_446 >> 16 ) ;
}
return 0 ;
}
static void F_179 ( T_1 * V_1 )
{
V_1 -> V_438 = NULL ;
V_1 -> V_434 = NULL ;
V_1 -> V_436 = NULL ;
}
static int F_177 ( T_1 * V_1 )
{
V_1 -> V_450 = F_138 ( V_1 -> V_67 , V_353 ) ;
if ( V_1 -> V_450 == NULL )
return - V_225 ;
return 0 ;
}
static void F_180 ( T_1 * V_1 )
{
F_143 ( V_1 -> V_450 ) ;
V_1 -> V_450 = NULL ;
}
static int F_181 ( T_1 * V_1 )
{
if ( F_182 ( V_1 -> V_123 , V_427 , L_132 ) == NULL ) {
F_4 ( L_133 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_123 ) ;
V_1 -> V_25 = V_451 ;
goto V_452;
}
else
V_1 -> V_453 = true ;
if ( F_182 ( V_1 -> V_125 + V_1 -> V_454 , 128 , L_132 ) == NULL ) {
F_4 ( L_134 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_125 ) ;
V_1 -> V_25 = V_451 ;
goto V_452;
}
else
V_1 -> V_455 = true ;
if ( F_182 ( V_1 -> V_122 + V_1 -> V_456 , V_228 , L_132 ) == NULL ) {
F_4 ( L_135 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_122 ) ;
V_1 -> V_25 = V_451 ;
goto V_452;
}
else
V_1 -> V_457 = true ;
if ( F_182 ( V_1 -> V_124 + V_1 -> V_458 , V_459 , L_132 ) == NULL ) {
F_4 ( L_136 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_124 ) ;
V_1 -> V_25 = V_451 ;
goto V_452;
}
else
V_1 -> V_460 = true ;
V_1 -> V_439 = F_183 ( V_1 -> V_123 ,
V_427 ) ;
if ( ! V_1 -> V_439 ) {
F_4 ( L_137 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_123 ) ;
V_1 -> V_25 = V_461 ;
goto V_452;
}
V_1 -> V_462 = F_183 ( V_1 -> V_125 , V_463 ) ;
if ( ! V_1 -> V_462 ) {
F_4 ( L_138 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_125 ) ;
V_1 -> V_25 = V_461 ;
goto V_452;
}
V_1 -> V_462 += V_1 -> V_454 ;
V_1 -> V_464 = F_183 ( V_1 -> V_122 , V_463 ) ;
if ( ! V_1 -> V_464 ) {
F_4 ( L_139 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_122 ) ;
V_1 -> V_25 = V_461 ;
goto V_452;
}
V_1 -> V_464 += V_1 -> V_456 ;
V_1 -> V_465 = F_183 ( V_1 -> V_124 ,
V_463 ) ;
if ( ! V_1 -> V_465 ) {
F_4 ( L_140 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_124 ) ;
V_1 -> V_25 = V_461 ;
goto V_452;
}
V_1 -> V_465 += V_1 -> V_458 ;
if ( ! F_184 ( V_1 ) ) {
F_4 ( L_141 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_123 ) ;
V_1 -> V_25 = V_466 ;
goto V_452;
}
return 0 ;
V_452:
F_185 ( V_1 ) ;
return - V_22 ;
}
static void F_185 ( T_1 * V_1 )
{
if ( V_29 >= V_30 )
F_4 ( L_142 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
if ( V_1 -> V_467 ) {
F_186 ( V_1 -> V_126 , V_1 ) ;
V_1 -> V_467 = false ;
}
if ( V_1 -> V_453 ) {
F_187 ( V_1 -> V_123 , V_427 ) ;
V_1 -> V_453 = false ;
}
if ( V_1 -> V_455 ) {
F_187 ( V_1 -> V_125 + V_1 -> V_454 , 128 ) ;
V_1 -> V_455 = false ;
}
if ( V_1 -> V_457 ) {
F_187 ( V_1 -> V_122 + V_1 -> V_456 , V_228 ) ;
V_1 -> V_457 = false ;
}
if ( V_1 -> V_460 ) {
F_187 ( V_1 -> V_124 + V_1 -> V_458 , V_459 ) ;
V_1 -> V_460 = false ;
}
if ( V_1 -> V_439 ) {
F_188 ( V_1 -> V_439 ) ;
V_1 -> V_439 = NULL ;
}
if ( V_1 -> V_464 ) {
F_188 ( V_1 -> V_464 - V_1 -> V_456 ) ;
V_1 -> V_464 = NULL ;
}
if ( V_1 -> V_465 ) {
F_188 ( V_1 -> V_465 - V_1 -> V_458 ) ;
V_1 -> V_465 = NULL ;
}
if ( V_1 -> V_462 ) {
F_188 ( V_1 -> V_462 - V_1 -> V_454 ) ;
V_1 -> V_462 = NULL ;
}
if ( V_29 >= V_30 )
F_4 ( L_143 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
}
static void F_189 ( T_1 * V_1 )
{
V_1 -> V_24 = NULL ;
V_1 -> line = V_21 ;
sprintf ( V_1 -> V_26 , L_144 , V_1 -> V_468 , V_1 -> V_250 ) ;
if ( V_1 -> line < V_469 ) {
if ( V_470 [ V_1 -> line ] )
V_1 -> V_67 = V_470 [ V_1 -> line ] ;
}
V_21 ++ ;
if ( ! V_23 )
V_23 = V_1 ;
else {
T_1 * V_471 = V_23 ;
while( V_471 -> V_24 )
V_471 = V_471 -> V_24 ;
V_471 -> V_24 = V_1 ;
}
if ( V_1 -> V_67 < 4096 )
V_1 -> V_67 = 4096 ;
else if ( V_1 -> V_67 > 65535 )
V_1 -> V_67 = 65535 ;
F_4 ( L_145
L_146 ,
V_1 -> V_26 ,
V_1 -> V_122 ,
V_1 -> V_123 ,
V_1 -> V_124 ,
V_1 -> V_125 ,
V_1 -> V_126 ,
V_1 -> V_67 ) ;
#if V_305
F_102 ( V_1 ) ;
#endif
}
static T_1 * F_190 ( int V_468 , int V_250 , struct V_472 * V_473 )
{
T_1 * V_1 ;
V_1 = F_191 ( sizeof( T_1 ) ,
V_353 ) ;
if ( ! V_1 ) {
F_4 ( L_147 ,
__FILE__ , __LINE__ , V_468 , V_250 ) ;
} else {
F_192 ( & V_1 -> V_28 ) ;
V_1 -> V_28 . V_15 = & V_474 ;
V_1 -> V_6 = V_7 ;
F_193 ( & V_1 -> V_242 , F_110 ) ;
V_1 -> V_67 = 4096 ;
V_1 -> V_28 . V_475 = 5 * V_233 / 10 ;
V_1 -> V_28 . V_476 = 30 * V_233 ;
F_194 ( & V_1 -> V_326 ) ;
F_194 ( & V_1 -> V_275 ) ;
F_195 ( & V_1 -> V_40 ) ;
memcpy ( & V_1 -> V_64 , & V_477 , sizeof( T_9 ) ) ;
V_1 -> V_379 = V_478 ;
V_1 -> V_468 = V_468 ;
V_1 -> V_250 = V_250 ;
V_1 -> V_126 = V_473 -> V_229 ;
V_1 -> V_125 = F_196 ( V_473 , 0 ) ;
V_1 -> V_122 = F_196 ( V_473 , 2 ) ;
V_1 -> V_123 = F_196 ( V_473 , 3 ) ;
V_1 -> V_124 = F_196 ( V_473 , 4 ) ;
V_1 -> V_454 = V_1 -> V_125 & ( V_463 - 1 ) ;
V_1 -> V_125 &= ~ ( V_463 - 1 ) ;
V_1 -> V_456 = V_1 -> V_122 & ( V_463 - 1 ) ;
V_1 -> V_122 &= ~ ( V_463 - 1 ) ;
V_1 -> V_458 = V_1 -> V_124 & ( V_463 - 1 ) ;
V_1 -> V_124 &= ~ ( V_463 - 1 ) ;
V_1 -> V_479 = V_480 ;
V_1 -> V_481 = V_482 ;
F_197 ( & V_1 -> V_85 , V_483 , ( unsigned long ) V_1 ) ;
F_197 ( & V_1 -> V_354 , V_484 ,
( unsigned long ) V_1 ) ;
V_1 -> V_485 = 0x087e4546 ;
V_1 -> V_25 = - 1 ;
}
return V_1 ;
}
static void F_198 ( int V_468 , struct V_472 * V_473 )
{
T_1 * V_345 [ V_486 ] ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_486 ; ++ V_28 ) {
V_345 [ V_28 ] = F_190 ( V_468 , V_28 , V_473 ) ;
if( V_345 [ V_28 ] == NULL ) {
for ( -- V_28 ; V_28 >= 0 ; -- V_28 )
F_143 ( V_345 [ V_28 ] ) ;
return;
}
}
for ( V_28 = 0 ; V_28 < V_486 ; ++ V_28 ) {
memcpy ( V_345 [ V_28 ] -> V_345 , V_345 , sizeof( V_345 ) ) ;
F_189 ( V_345 [ V_28 ] ) ;
F_195 ( & V_345 [ V_28 ] -> V_46 ) ;
}
if ( ! F_181 ( V_345 [ 0 ] ) ) {
F_174 ( V_345 [ 0 ] ) ;
for ( V_28 = 1 ; V_28 < V_486 ; ++ V_28 ) {
V_345 [ V_28 ] -> V_46 = V_345 [ 0 ] -> V_46 ;
V_345 [ V_28 ] -> V_126 = V_345 [ 0 ] -> V_126 ;
V_345 [ V_28 ] -> V_439 = V_345 [ 0 ] -> V_439 ;
V_345 [ V_28 ] -> V_464 = V_345 [ 0 ] -> V_464 ;
V_345 [ V_28 ] -> V_465 = V_345 [ 0 ] -> V_465 ;
V_345 [ V_28 ] -> V_462 = V_345 [ 0 ] -> V_462 ;
F_174 ( V_345 [ V_28 ] ) ;
}
if ( F_199 ( V_345 [ 0 ] -> V_126 ,
F_133 ,
V_345 [ 0 ] -> V_481 ,
V_345 [ 0 ] -> V_26 ,
V_345 [ 0 ] ) < 0 ) {
F_4 ( L_148 ,
__FILE__ , __LINE__ ,
V_345 [ 0 ] -> V_26 ,
V_345 [ 0 ] -> V_126 ) ;
}
else {
V_345 [ 0 ] -> V_467 = true ;
F_200 ( V_345 [ 0 ] ) ;
}
}
}
static void F_201 ( void )
{
int V_181 ;
T_1 * V_1 ;
T_1 * V_340 ;
F_4 ( L_149 , V_487 , V_143 ) ;
if ( V_488 ) {
if ( ( V_181 = F_202 ( V_488 ) ) )
F_4 ( L_150 ,
__FILE__ , __LINE__ , V_181 ) ;
F_203 ( V_488 ) ;
}
V_1 = V_23 ;
while( V_1 ) {
F_139 ( V_1 ) ;
V_1 = V_1 -> V_24 ;
}
V_1 = V_23 ;
while( V_1 ) {
#if V_305
F_107 ( V_1 ) ;
#endif
F_179 ( V_1 ) ;
F_180 ( V_1 ) ;
if ( V_1 -> V_250 == 0 ) {
if ( V_1 -> V_464 )
F_74 ( V_1 , V_489 , 1 ) ;
F_185 ( V_1 ) ;
}
V_340 = V_1 ;
V_1 = V_1 -> V_24 ;
F_143 ( V_340 ) ;
}
F_204 ( & V_490 ) ;
}
static int T_11 F_205 ( void )
{
int V_181 ;
if ( V_491 ) {
F_1 () ;
F_206 () ;
}
F_4 ( L_151 , V_487 , V_143 ) ;
if ( ( V_181 = F_207 ( & V_490 ) ) < 0 ) {
F_4 ( L_152 , __FILE__ , V_181 ) ;
return V_181 ;
}
V_488 = F_208 ( 128 ) ;
if ( ! V_488 ) {
V_181 = - V_225 ;
goto error;
}
V_488 -> V_487 = L_132 ;
V_488 -> V_2 = L_153 ;
V_488 -> V_492 = V_493 ;
V_488 -> V_494 = 64 ;
V_488 -> type = V_495 ;
V_488 -> V_496 = V_497 ;
V_488 -> V_498 = V_499 ;
V_488 -> V_498 . V_51 =
V_500 | V_364 | V_356 | V_355 | V_373 ;
V_488 -> V_498 . V_501 = 9600 ;
V_488 -> V_498 . V_502 = 9600 ;
V_488 -> V_11 = V_503 ;
F_209 ( V_488 , & V_15 ) ;
if ( ( V_181 = F_210 ( V_488 ) ) < 0 ) {
F_4 ( L_154 ,
__FILE__ , __LINE__ ) ;
F_203 ( V_488 ) ;
V_488 = NULL ;
goto error;
}
F_4 ( L_155 ,
V_487 , V_143 ,
V_488 -> V_492 ) ;
return 0 ;
error:
F_201 () ;
return V_181 ;
}
static void T_12 F_211 ( void )
{
F_201 () ;
}
static void F_212 ( T_1 * V_1 , int V_380 )
{
if ( V_380 ) {
F_74 ( V_1 , V_504 , ( unsigned char ) ( F_73 ( V_1 , V_504 ) | ( V_346 + V_279 ) ) ) ;
V_1 -> V_345 [ 0 ] -> V_505 |= ( V_279 << ( V_1 -> V_250 * 2 ) ) ;
F_213 ( V_1 ) ;
F_74 ( V_1 , V_506 , 0x40 ) ;
F_74 ( V_1 , V_507 , 0x40 ) ;
} else {
F_74 ( V_1 , V_504 , ( unsigned char ) ( F_73 ( V_1 , V_504 ) & ~ ( V_346 + V_279 ) ) ) ;
F_74 ( V_1 , V_506 , 0x00 ) ;
F_74 ( V_1 , V_507 , 0x00 ) ;
}
if ( V_1 -> V_64 . V_210 )
F_214 ( V_1 , V_1 -> V_64 . V_210 ) ;
else
F_214 ( V_1 , 3686400 ) ;
}
static void F_214 ( T_1 * V_1 , T_13 V_81 )
{
T_13 V_508 ;
unsigned char V_509 ;
T_13 V_510 = 0 ;
if ( V_81 != 0 ) {
V_510 = 14745600 / V_81 ;
if ( ! V_510 )
V_510 = 1 ;
V_508 = V_510 ;
V_509 = 0 ;
if ( V_508 != 1 && V_508 != 2 ) {
V_509 = 1 ;
V_508 >>= 1 ;
}
for(; V_508 > 256 && V_509 < 10 ; V_509 ++ )
V_508 >>= 1 ;
F_74 ( V_1 , V_507 ,
( unsigned char ) ( ( F_73 ( V_1 , V_507 ) & 0xf0 ) | V_509 ) ) ;
F_74 ( V_1 , V_506 ,
( unsigned char ) ( ( F_73 ( V_1 , V_506 ) & 0xf0 ) | V_509 ) ) ;
F_74 ( V_1 , V_511 , ( unsigned char ) V_508 ) ;
}
else {
F_74 ( V_1 , V_507 , 0 ) ;
F_74 ( V_1 , V_506 , 0 ) ;
F_74 ( V_1 , V_511 , 0 ) ;
}
}
static void F_145 ( T_1 * V_1 )
{
if ( V_29 >= V_256 )
F_4 ( L_156 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_74 ( V_1 , V_296 , V_512 ) ;
V_1 -> V_300 &= ~ V_513 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
F_74 ( V_1 , V_309 + V_292 , 0 ) ;
F_74 ( V_1 , V_309 + V_293 , V_294 ) ;
F_74 ( V_1 , V_309 + V_291 , 0 ) ;
V_1 -> V_382 = false ;
V_1 -> V_310 = false ;
}
static void F_148 ( T_1 * V_1 )
{
int V_339 ;
if ( V_29 >= V_256 )
F_4 ( L_157 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_74 ( V_1 , V_296 , V_512 ) ;
if ( V_1 -> V_64 . V_65 == V_66 ) {
V_1 -> V_300 &= ~ V_513 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
F_74 ( V_1 , V_309 + V_292 , 0 ) ;
F_74 ( V_1 , V_309 + V_293 , V_294 ) ;
for ( V_339 = 0 ; V_339 < V_1 -> V_433 ; V_339 ++ ) {
V_1 -> V_434 [ V_339 ] . V_257 = 0xff ;
if ( ! ( V_339 % 4 ) )
F_215 ( V_1 ) ;
}
V_1 -> V_514 = 0 ;
F_124 ( V_1 , V_309 + V_515 ,
V_1 -> V_435 [ 0 ] . V_441 ) ;
F_124 ( V_1 , V_309 + V_516 ,
V_1 -> V_435 [ V_1 -> V_433 - 1 ] . V_441 ) ;
F_124 ( V_1 , V_309 + V_517 , V_428 ) ;
F_74 ( V_1 , V_309 + V_291 , 0x60 ) ;
F_74 ( V_1 , V_309 + V_292 , 0xf2 ) ;
} else {
V_1 -> V_300 |= V_513 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
}
F_74 ( V_1 , V_296 , V_518 ) ;
V_1 -> V_310 = false ;
V_1 -> V_382 = true ;
}
static void F_35 ( T_1 * V_1 )
{
if ( V_29 >= V_256 )
F_4 ( L_158 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_1 -> V_70 ) ;
if ( ! V_1 -> V_76 ) {
F_74 ( V_1 , V_296 , V_297 ) ;
F_74 ( V_1 , V_296 , V_298 ) ;
V_1 -> V_76 = true ;
}
if ( V_1 -> V_70 ) {
V_1 -> V_304 = false ;
if ( V_1 -> V_64 . V_65 != V_268 ) {
if ( V_1 -> V_64 . V_11 & V_519 ) {
F_62 ( V_1 ) ;
if ( ! ( V_1 -> V_54 & V_55 ) ) {
V_1 -> V_54 |= V_55 ;
F_28 ( V_1 ) ;
V_1 -> V_304 = true ;
}
}
F_124 ( V_1 , V_312 ,
( unsigned short ) ( ( ( V_520 - 1 ) << 8 ) + V_521 ) ) ;
F_74 ( V_1 , V_290 + V_292 , 0 ) ;
F_74 ( V_1 , V_290 + V_293 , V_294 ) ;
F_124 ( V_1 , V_290 + V_515 ,
V_1 -> V_437 [ 0 ] . V_441 ) ;
F_124 ( V_1 , V_290 + V_516 ,
V_1 -> V_437 [ V_1 -> V_522 ] . V_441 ) ;
V_1 -> V_259 &= ~ V_302 ;
V_1 -> V_259 |= V_295 ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
F_74 ( V_1 , V_258 , ( unsigned char ) ( V_302 + V_295 ) ) ;
F_74 ( V_1 , V_290 + V_291 , 0x40 ) ;
F_74 ( V_1 , V_290 + V_292 , 0xf2 ) ;
F_140 ( & V_1 -> V_85 , V_80 +
F_141 ( 5000 ) ) ;
}
else {
F_127 ( V_1 ) ;
V_1 -> V_300 |= V_301 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
}
V_1 -> V_69 = true ;
}
}
static void F_47 ( T_1 * V_1 )
{
if ( V_29 >= V_256 )
F_4 ( L_159 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_44 ( & V_1 -> V_85 ) ;
F_74 ( V_1 , V_290 + V_292 , 0 ) ;
F_74 ( V_1 , V_290 + V_293 , V_294 ) ;
F_74 ( V_1 , V_296 , V_297 ) ;
V_1 -> V_259 &= ~ ( V_295 + V_302 ) ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
F_74 ( V_1 , V_258 , ( unsigned char ) ( V_302 + V_295 ) ) ;
V_1 -> V_300 &= ~ V_301 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
V_1 -> V_76 = false ;
V_1 -> V_69 = false ;
}
static void F_127 ( T_1 * V_1 )
{
T_14 V_523 [ 2 ] ;
if ( ! V_1 -> V_70 && ! V_1 -> V_75 )
return;
while( V_1 -> V_70 && ( F_73 ( V_1 , V_524 ) & V_346 ) ) {
if ( ( V_1 -> V_70 > 1 ) && ! V_1 -> V_75 ) {
V_523 [ 0 ] = V_1 -> V_63 [ V_1 -> V_84 ++ ] ;
if ( V_1 -> V_84 >= V_1 -> V_67 )
V_1 -> V_84 -= V_1 -> V_67 ;
V_523 [ 1 ] = V_1 -> V_63 [ V_1 -> V_84 ++ ] ;
if ( V_1 -> V_84 >= V_1 -> V_67 )
V_1 -> V_84 -= V_1 -> V_67 ;
F_124 ( V_1 , V_282 , * ( ( T_7 * ) V_523 ) ) ;
V_1 -> V_70 -= 2 ;
V_1 -> V_105 . V_113 += 2 ;
} else {
if ( V_1 -> V_75 ) {
F_74 ( V_1 , V_282 , V_1 -> V_75 ) ;
V_1 -> V_75 = 0 ;
} else {
F_74 ( V_1 , V_282 , V_1 -> V_63 [ V_1 -> V_84 ++ ] ) ;
if ( V_1 -> V_84 >= V_1 -> V_67 )
V_1 -> V_84 -= V_1 -> V_67 ;
V_1 -> V_70 -- ;
}
V_1 -> V_105 . V_113 ++ ;
}
}
}
static void F_139 ( T_1 * V_1 )
{
if ( V_1 -> V_464 ) {
F_47 ( V_1 ) ;
F_145 ( V_1 ) ;
V_1 -> V_54 &= ~ ( V_56 + V_55 ) ;
F_28 ( V_1 ) ;
V_1 -> V_300 = 0 ;
V_1 -> V_259 = 0 ;
V_1 -> V_266 = 0 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
F_74 ( V_1 , V_525 , V_1 -> V_266 ) ;
F_74 ( V_1 , V_296 , V_526 ) ;
}
}
static void F_216 ( T_1 * V_1 )
{
int V_339 ;
for ( V_339 = 0 ; V_339 < V_486 ; ++ V_339 ) {
if ( V_1 -> V_345 [ V_339 ] )
F_139 ( V_1 -> V_345 [ V_339 ] ) ;
}
}
static void F_147 ( T_1 * V_1 )
{
unsigned char V_146 ;
F_47 ( V_1 ) ;
F_145 ( V_1 ) ;
V_146 = 0x00 ;
if ( V_1 -> V_64 . V_366 != 1 )
V_146 |= V_346 ;
F_74 ( V_1 , V_527 , V_146 ) ;
V_146 = 0x40 ;
switch ( V_1 -> V_64 . V_361 ) {
case 7 : V_146 |= V_349 + V_347 ; break;
case 6 : V_146 |= V_348 + V_149 ; break;
case 5 : V_146 |= V_348 + V_349 + V_149 + V_347 ; break;
}
if ( V_1 -> V_64 . V_116 != V_367 ) {
V_146 |= V_346 ;
if ( V_1 -> V_64 . V_116 == V_370 )
V_146 |= V_279 ;
}
F_74 ( V_1 , V_528 , V_146 ) ;
V_146 = 0x00 ;
if ( V_1 -> V_64 . V_211 )
V_146 |= ( V_346 + V_279 ) ;
F_74 ( V_1 , V_504 , V_146 ) ;
V_146 = V_351 ;
F_74 ( V_1 , V_506 , V_146 ) ;
V_146 = V_351 ;
F_74 ( V_1 , V_507 , V_146 ) ;
V_1 -> V_345 [ 0 ] -> V_505 |= ( V_279 << ( V_1 -> V_250 * 2 ) ) ;
F_213 ( V_1 ) ;
F_158 ( V_1 ) ;
F_74 ( V_1 , V_529 , 0x00 ) ;
F_74 ( V_1 , V_312 , 0x10 ) ;
F_74 ( V_1 , V_530 , 0x1e ) ;
V_146 = 0x10 ;
if ( ! ( V_1 -> V_54 & V_55 ) )
V_146 |= 0x01 ;
F_74 ( V_1 , V_148 , V_146 ) ;
V_1 -> V_300 |= V_531 + V_532 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
V_1 -> V_259 = V_263 ;
F_74 ( V_1 , V_321 , V_1 -> V_259 ) ;
V_1 -> V_266 = V_267 ;
F_74 ( V_1 , V_525 , V_1 -> V_266 ) ;
F_214 ( V_1 , V_1 -> V_64 . V_81 * 16 ) ;
}
static void F_146 ( T_1 * V_1 )
{
unsigned char V_146 ;
T_13 V_533 ;
V_1 -> V_64 . V_11 &= ~ ( V_200 + V_196 ) ;
F_74 ( V_1 , V_290 + V_291 , 0 ) ;
F_74 ( V_1 , V_309 + V_291 , 0 ) ;
V_146 = 0x81 ;
if ( V_1 -> V_64 . V_11 & V_534 )
V_146 |= V_349 ;
if ( V_1 -> V_64 . V_11 & V_535 )
V_146 |= V_349 ;
if ( V_1 -> V_64 . V_171 == V_168 )
V_146 |= V_347 + V_346 ;
F_74 ( V_1 , V_527 , V_146 ) ;
V_146 = 0x00 ;
F_74 ( V_1 , V_528 , V_146 ) ;
V_146 = 0x00 ;
switch( V_1 -> V_64 . V_152 ) {
case V_536 : V_146 |= V_348 ; break;
case V_160 : V_146 |= V_350 + V_348 ; break;
case V_162 : V_146 |= V_350 + V_351 ; break;
case V_164 : V_146 |= V_350 ; break;
#if 0
case HDLC_ENCODING_NRZB:
case HDLC_ENCODING_NRZI_MARK:
case HDLC_ENCODING_DIFF_BIPHASE_LEVEL:
#endif
}
if ( V_1 -> V_64 . V_11 & V_537 ) {
V_533 = 16 ;
V_146 |= V_149 ;
} else if ( V_1 -> V_64 . V_11 & V_538 ) {
V_533 = 8 ;
} else {
V_533 = 32 ;
V_146 |= V_349 ;
}
F_74 ( V_1 , V_504 , V_146 ) ;
V_146 = 0 ;
if ( V_1 -> V_64 . V_11 & V_197 )
V_146 |= V_351 ;
if ( V_1 -> V_64 . V_11 & V_196 )
V_146 |= V_351 + V_348 ;
F_74 ( V_1 , V_506 , V_146 ) ;
V_146 = 0 ;
if ( V_1 -> V_64 . V_11 & V_201 )
V_146 |= V_351 ;
if ( V_1 -> V_64 . V_11 & V_200 )
V_146 |= V_351 + V_348 ;
F_74 ( V_1 , V_507 , V_146 ) ;
if ( V_1 -> V_64 . V_11 & V_196 )
F_214 ( V_1 , V_1 -> V_64 . V_210 * V_533 ) ;
else
F_214 ( V_1 , V_1 -> V_64 . V_210 ) ;
if ( V_1 -> V_64 . V_11 & V_201 )
V_1 -> V_345 [ 0 ] -> V_505 |= ( V_279 << ( V_1 -> V_250 * 2 ) ) ;
else
V_1 -> V_345 [ 0 ] -> V_505 &= ~ ( V_279 << ( V_1 -> V_250 * 2 ) ) ;
F_213 ( V_1 ) ;
F_74 ( V_1 , V_529 , V_539 ) ;
F_74 ( V_1 , V_312 , V_521 ) ;
F_74 ( V_1 , V_530 , ( unsigned char ) ( V_520 - 1 ) ) ;
F_74 ( V_1 , V_290 + V_540 , 0x14 ) ;
F_74 ( V_1 , V_309 + V_540 , 0x14 ) ;
F_74 ( V_1 , V_309 + V_541 ,
( unsigned char ) ( V_1 -> V_440 >> 16 ) ) ;
F_74 ( V_1 , V_290 + V_541 ,
( unsigned char ) ( V_1 -> V_440 >> 16 ) ) ;
V_1 -> V_300 |= V_531 + V_532 ;
F_74 ( V_1 , V_303 , V_1 -> V_300 ) ;
V_146 = 0x10 ;
if ( ! ( V_1 -> V_54 & V_55 ) )
V_146 |= 0x01 ;
F_74 ( V_1 , V_148 , V_146 ) ;
F_158 ( V_1 ) ;
F_47 ( V_1 ) ;
F_145 ( V_1 ) ;
F_214 ( V_1 , V_1 -> V_64 . V_210 ) ;
if ( V_1 -> V_64 . V_211 )
F_212 ( V_1 , 1 ) ;
}
static void F_158 ( T_1 * V_1 )
{
unsigned char V_146 = 0xff ;
switch( V_1 -> V_379 ) {
case V_478 : V_146 = 0x7e ; break;
case V_542 : V_146 = 0xaa ; break;
case V_543 : V_146 = 0x00 ; break;
case V_544 : V_146 = 0xff ; break;
case V_545 : V_146 = 0xaa ; break;
case V_546 : V_146 = 0x00 ; break;
case V_547 : V_146 = 0xff ; break;
}
F_74 ( V_1 , V_548 , V_146 ) ;
}
static void F_62 ( T_1 * V_1 )
{
T_7 V_257 = F_73 ( V_1 , V_549 ) ;
T_7 V_550 = F_215 ( V_1 ) ;
T_7 V_551 ;
V_1 -> V_54 &= V_56 + V_55 ;
if ( ! ( V_257 & V_149 ) )
V_1 -> V_54 |= V_127 ;
if ( ! ( V_257 & V_347 ) )
V_1 -> V_54 |= V_129 ;
V_551 = V_346 << ( V_1 -> V_250 * 2 ) ;
if ( ! ( V_550 & V_551 ) )
V_1 -> V_54 |= V_130 ;
V_551 = V_279 << ( V_1 -> V_250 * 2 ) ;
if ( ! ( V_550 & V_551 ) )
V_1 -> V_54 |= V_128 ;
}
static void F_28 ( T_1 * V_1 )
{
unsigned char V_146 ;
T_7 V_552 ;
V_146 = F_73 ( V_1 , V_148 ) ;
if ( V_1 -> V_54 & V_55 )
V_146 &= ~ V_279 ;
else
V_146 |= V_279 ;
F_74 ( V_1 , V_148 , V_146 ) ;
V_552 = V_346 << ( V_1 -> V_250 * 2 ) ;
if ( V_1 -> V_54 & V_56 )
V_1 -> V_345 [ 0 ] -> V_505 &= ~ V_552 ;
else
V_1 -> V_345 [ 0 ] -> V_505 |= V_552 ;
F_213 ( V_1 ) ;
}
static void F_178 ( T_1 * V_1 )
{
F_217 ( V_1 , 0 , V_1 -> V_433 - 1 ) ;
}
static void F_217 ( T_1 * V_1 , unsigned int V_553 , unsigned int V_554 )
{
bool V_555 = false ;
while( ! V_555 ) {
V_1 -> V_434 [ V_553 ] . V_257 = 0xff ;
if ( V_553 == V_554 ) {
V_555 = true ;
F_124 ( V_1 , V_309 + V_516 , V_1 -> V_435 [ V_553 ] . V_441 ) ;
}
V_553 ++ ;
if ( V_553 == V_1 -> V_433 )
V_553 = 0 ;
}
V_1 -> V_514 = V_553 ;
}
static bool F_115 ( T_1 * V_1 )
{
unsigned int V_556 , V_557 ;
unsigned short V_257 ;
unsigned int V_558 = 0 ;
bool V_559 = false ;
unsigned long V_11 ;
struct V_8 * V_9 = V_1 -> V_28 . V_9 ;
unsigned char V_560 = 0xff ;
V_430 * V_561 ;
T_10 * V_562 ;
V_563:
V_558 = 0 ;
V_560 = 0xff ;
V_556 = V_557 = V_1 -> V_514 ;
for ( ; ; ) {
V_561 = & V_1 -> V_434 [ V_557 ] ;
V_562 = & V_1 -> V_435 [ V_557 ] ;
if ( V_561 -> V_257 == 0xff )
goto V_564;
if ( V_558 == 0 && V_1 -> V_64 . V_565 != 0xff )
V_560 = V_562 -> V_447 [ 0 ] ;
V_558 += V_561 -> V_443 ;
if ( V_561 -> V_257 )
break;
V_557 ++ ;
if ( V_557 == V_1 -> V_433 )
V_557 = 0 ;
if ( V_557 == V_1 -> V_514 ) {
if ( V_1 -> V_382 ) {
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_148 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
goto V_564;
}
}
V_257 = V_561 -> V_257 ;
if ( V_1 -> V_64 . V_171 == V_166 )
V_257 &= ~ V_347 ;
if ( V_558 == 0 ||
( V_560 != 0xff && V_560 != V_1 -> V_64 . V_565 ) ) {
F_217 ( V_1 , V_556 , V_557 ) ;
goto V_563;
}
if ( V_558 < 2 )
V_257 |= V_351 ;
if ( V_257 & ( V_351 + V_348 + V_149 + V_347 ) ) {
if ( V_257 & V_351 )
V_1 -> V_105 . V_135 ++ ;
else if ( V_257 & V_348 )
V_1 -> V_105 . V_566 ++ ;
else if ( V_257 & V_149 )
V_1 -> V_105 . V_137 ++ ;
else
V_1 -> V_105 . V_138 ++ ;
V_558 = 0 ;
#if V_305
{
V_1 -> V_217 -> V_176 . V_567 ++ ;
V_1 -> V_217 -> V_176 . V_568 ++ ;
}
#endif
}
if ( V_29 >= V_244 )
F_4 ( L_160 ,
__FILE__ , __LINE__ , V_1 -> V_26 , V_257 , V_558 ) ;
if ( V_29 >= V_569 )
F_218 ( V_1 , V_1 -> V_435 [ V_556 ] . V_447 ,
F_33 (unsigned int, framesize, SCABUFSIZE) , 0 ) ;
if ( V_558 ) {
if ( V_558 > V_1 -> V_67 )
V_1 -> V_105 . V_136 ++ ;
else {
int V_570 = V_558 ;
int V_20 = V_556 ;
unsigned char * V_571 = V_1 -> V_450 ;
V_1 -> V_572 = V_558 ;
V_1 -> V_105 . V_132 ++ ;
while( V_570 ) {
int V_573 = F_34 ( V_570 , V_428 ) ;
memcpy ( V_571 ,
V_1 -> V_435 [ V_20 ] . V_447 ,
V_573 ) ;
V_571 += V_573 ;
V_570 -= V_573 ;
if ( ++ V_20 == V_1 -> V_433 )
V_20 = 0 ;
}
#if V_305
if ( V_1 -> V_41 )
F_97 ( V_1 , V_1 -> V_450 , V_558 ) ;
else
#endif
F_5 ( V_9 , V_1 -> V_450 ,
V_1 -> V_574 , V_558 ) ;
}
}
F_217 ( V_1 , V_556 , V_557 ) ;
V_559 = true ;
V_564:
if ( V_1 -> V_382 && V_1 -> V_310 ) {
if ( V_1 -> V_434 [ V_557 ] . V_257 == 0xff ) {
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_148 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
}
}
return V_559 ;
}
static void F_32 ( T_1 * V_1 , const char * V_60 , unsigned int V_12 )
{
unsigned short V_570 ;
unsigned int V_339 = 0 ;
V_430 * V_561 ;
T_10 * V_562 ;
if ( V_29 >= V_569 )
F_218 ( V_1 , V_60 , F_33 (unsigned int, count, SCABUFSIZE) , 1 ) ;
for( V_339 = 0 ; ; )
{
V_570 = F_33 (unsigned int, count, SCABUFSIZE) ;
V_561 = & V_1 -> V_436 [ V_339 ] ;
V_562 = & V_1 -> V_437 [ V_339 ] ;
F_219 ( V_1 , V_562 -> V_447 , V_60 , V_570 ) ;
V_561 -> V_443 = V_570 ;
V_561 -> V_257 = 0 ;
V_60 += V_570 ;
V_12 -= V_570 ;
if ( ! V_12 )
break;
V_339 ++ ;
if ( V_339 >= V_1 -> V_431 )
V_339 = 0 ;
}
V_1 -> V_436 [ V_339 ] . V_257 = 0x81 ;
V_1 -> V_522 = ++ V_339 ;
}
static bool F_220 ( T_1 * V_1 )
{
static unsigned char V_575 [] = { 0x00 , 0xff , 0xaa , 0x55 , 0x69 , 0x96 } ;
static unsigned int V_12 = F_221 ( V_575 ) ;
unsigned int V_339 ;
bool V_181 = true ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_139 ( V_1 ) ;
V_1 -> V_25 = V_576 ;
for ( V_339 = 0 ; V_339 < V_12 ; V_339 ++ ) {
F_74 ( V_1 , V_511 , V_575 [ V_339 ] ) ;
F_74 ( V_1 , V_548 , V_575 [ ( V_339 + 1 ) % V_12 ] ) ;
F_74 ( V_1 , V_577 , V_575 [ ( V_339 + 2 ) % V_12 ] ) ;
F_74 ( V_1 , V_578 , V_575 [ ( V_339 + 3 ) % V_12 ] ) ;
if ( ( F_73 ( V_1 , V_511 ) != V_575 [ V_339 ] ) ||
( F_73 ( V_1 , V_548 ) != V_575 [ ( V_339 + 1 ) % V_12 ] ) ||
( F_73 ( V_1 , V_577 ) != V_575 [ ( V_339 + 2 ) % V_12 ] ) ||
( F_73 ( V_1 , V_578 ) != V_575 [ ( V_339 + 3 ) % V_12 ] ) )
{
V_181 = false ;
break;
}
}
F_139 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
return V_181 ;
}
static bool F_222 ( T_1 * V_1 )
{
unsigned long V_45 ;
unsigned long V_11 ;
unsigned char V_249 = ( V_1 -> V_250 & 1 ) ? V_251 : V_252 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_139 ( V_1 ) ;
V_1 -> V_25 = V_579 ;
V_1 -> V_255 = false ;
F_74 ( V_1 , V_253 , ( unsigned char ) ( ( V_1 -> V_250 & 1 ) ? V_351 : V_349 ) ) ;
F_74 ( V_1 , ( unsigned char ) ( V_249 + V_580 ) , 0 ) ;
F_124 ( V_1 , ( unsigned char ) ( V_249 + V_581 ) , 1 ) ;
F_74 ( V_1 , ( unsigned char ) ( V_249 + V_254 ) , 0x50 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
V_45 = 100 ;
while( V_45 -- && ! V_1 -> V_255 ) {
F_38 ( 10 ) ;
}
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_139 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
return V_1 -> V_255 ;
}
static bool F_223 ( T_1 * V_1 )
{
F_74 ( V_1 , V_582 , 0 ) ;
F_74 ( V_1 , V_583 , 0 ) ;
F_74 ( V_1 , V_584 , 0 ) ;
F_74 ( V_1 , V_585 , 0 ) ;
F_74 ( V_1 , V_586 , 0 ) ;
F_74 ( V_1 , V_587 , V_588 ) ;
F_74 ( V_1 , V_589 , 0x80 ) ;
F_74 ( V_1 , V_590 , 0xff ) ;
F_74 ( V_1 , V_591 , 0xff ) ;
F_74 ( V_1 , V_253 , 0xf0 ) ;
F_74 ( V_1 , V_592 , 0 ) ;
return true ;
}
static bool F_224 ( T_1 * V_1 )
{
int V_339 ;
volatile T_13 * V_593 = ( T_13 * ) ( V_1 -> V_462 + 0x50 ) ;
T_13 V_594 ;
V_1 -> V_485 |= V_595 ;
* V_593 = V_1 -> V_485 ;
for( V_339 = 0 ; V_339 < 10 ; V_339 ++ )
V_594 = * V_593 ;
V_1 -> V_485 &= ~ V_595 ;
* V_593 = V_1 -> V_485 ;
V_1 -> V_505 = 0xaa ;
F_213 ( V_1 ) ;
{
volatile T_13 * V_596 = ( T_13 * ) ( V_1 -> V_462 + 0x2c ) ;
V_597 &= ~ ( V_348 + V_349 + V_149 ) ;
switch( V_598 )
{
case 16 :
V_597 |= V_348 + V_349 + V_149 ;
break;
case 8 :
V_597 |= V_348 + V_349 ;
break;
case 4 :
V_597 |= V_348 + V_149 ;
break;
case 0 :
V_597 |= V_348 ;
break;
}
* V_596 = V_597 ;
* V_593 = V_485 ;
}
F_223 ( V_1 -> V_345 [ 0 ] ) ;
F_223 ( V_1 -> V_345 [ 2 ] ) ;
return true ;
}
static bool F_225 ( T_1 * V_1 )
{
#define F_226 20
unsigned long V_45 ;
T_7 V_12 = F_226 ;
unsigned char V_60 [ F_226 ] ;
bool V_181 = false ;
unsigned long V_11 ;
struct V_8 * V_599 = V_1 -> V_28 . V_9 ;
T_13 V_600 = V_1 -> V_64 . V_210 ;
V_1 -> V_64 . V_210 = 3686400 ;
V_1 -> V_28 . V_9 = NULL ;
V_1 -> V_25 = V_601 ;
for ( V_12 = 0 ; V_12 < F_226 ; ++ V_12 )
V_60 [ V_12 ] = ( unsigned char ) V_12 ;
memset ( V_1 -> V_450 , 0 , F_226 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_146 ( V_1 ) ;
F_212 ( V_1 , 1 ) ;
F_148 ( V_1 ) ;
V_1 -> V_70 = V_12 ;
F_32 ( V_1 , V_60 , V_12 ) ;
F_35 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
for ( V_45 = 100 ; V_45 ; -- V_45 ) {
F_38 ( 10 ) ;
if ( F_115 ( V_1 ) ) {
V_181 = true ;
break;
}
}
if ( V_181 &&
( V_1 -> V_572 != V_12 ||
memcmp ( V_60 , V_1 -> V_450 , V_12 ) ) ) {
V_181 = false ;
}
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_216 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
V_1 -> V_64 . V_210 = V_600 ;
V_1 -> V_28 . V_9 = V_599 ;
return V_181 ;
}
static int F_200 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_161 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_224 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
V_1 -> V_345 [ 0 ] -> V_344 = 0 ;
if ( F_220 ( V_1 -> V_345 [ 0 ] ) &&
F_220 ( V_1 -> V_345 [ 1 ] ) ) {
V_1 -> V_345 [ 0 ] -> V_344 = 2 ;
if ( F_220 ( V_1 -> V_345 [ 2 ] ) &&
F_220 ( V_1 -> V_345 [ 3 ] ) )
V_1 -> V_345 [ 0 ] -> V_344 += 2 ;
}
else {
F_4 ( L_162 ,
__FILE__ , __LINE__ , V_1 -> V_26 , ( unsigned long ) ( V_1 -> V_122 ) ) ;
return - V_22 ;
}
if ( ! F_222 ( V_1 -> V_345 [ 0 ] ) ||
! F_222 ( V_1 -> V_345 [ 1 ] ) ||
( V_1 -> V_344 == 4 && ! F_222 ( V_1 -> V_345 [ 2 ] ) ) ||
( V_1 -> V_344 == 4 && ! F_222 ( V_1 -> V_345 [ 3 ] ) ) ) {
F_4 ( L_163 ,
__FILE__ , __LINE__ , V_1 -> V_26 , ( unsigned short ) ( V_1 -> V_126 ) ) ;
return - V_22 ;
}
if ( ! F_225 ( V_1 -> V_345 [ 0 ] ) ||
! F_225 ( V_1 -> V_345 [ 1 ] ) ||
( V_1 -> V_344 == 4 && ! F_225 ( V_1 -> V_345 [ 2 ] ) ) ||
( V_1 -> V_344 == 4 && ! F_225 ( V_1 -> V_345 [ 3 ] ) ) ) {
F_4 ( L_164 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
return - V_22 ;
}
if ( V_29 >= V_30 )
F_4 ( L_165 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
V_1 -> V_345 [ 0 ] -> V_25 = 0 ;
V_1 -> V_345 [ 1 ] -> V_25 = 0 ;
if ( V_1 -> V_344 > 2 ) {
V_1 -> V_345 [ 2 ] -> V_25 = 0 ;
V_1 -> V_345 [ 3 ] -> V_25 = 0 ;
}
return 0 ;
}
static bool F_184 ( T_1 * V_1 )
{
static unsigned long V_575 [] = { 0x0 , 0x55555555 , 0xaaaaaaaa ,
0x66666666 , 0x99999999 , 0xffffffff , 0x12345678 } ;
unsigned long V_12 = F_221 ( V_575 ) ;
unsigned long V_339 ;
unsigned long V_602 = V_427 /sizeof( unsigned long ) ;
unsigned long * V_603 = ( unsigned long * ) V_1 -> V_439 ;
for ( V_339 = 0 ; V_339 < V_12 ; V_339 ++ ) {
* V_603 = V_575 [ V_339 ] ;
if ( * V_603 != V_575 [ V_339 ] )
return false ;
}
for ( V_339 = 0 ; V_339 < V_602 ; V_339 ++ ) {
* V_603 = V_339 * 4 ;
V_603 ++ ;
}
V_603 = ( unsigned long * ) V_1 -> V_439 ;
for ( V_339 = 0 ; V_339 < V_602 ; V_339 ++ ) {
if ( * V_603 != V_339 * 4 )
return false ;
V_603 ++ ;
}
memset ( V_1 -> V_439 , 0 , V_427 ) ;
return true ;
}
static void F_219 ( T_1 * V_1 , char * V_604 , const char * V_605 , unsigned short V_12 )
{
unsigned short V_606 = V_12 / V_607 ;
unsigned short V_339 ;
for ( V_339 = 0 ; V_339 < V_606 ; V_339 ++ )
{
memcpy ( V_604 , V_605 , V_607 ) ;
F_215 ( V_1 ) ;
V_604 += V_607 ;
V_605 += V_607 ;
}
memcpy ( V_604 , V_605 , V_12 % V_607 ) ;
}
static void F_218 ( T_1 * V_1 , const char * V_10 , int V_12 , int V_236 )
{
int V_339 ;
int V_608 ;
if ( V_236 )
F_4 ( L_166 , V_1 -> V_26 ) ;
else
F_4 ( L_167 , V_1 -> V_26 ) ;
while( V_12 ) {
if ( V_12 > 16 )
V_608 = 16 ;
else
V_608 = V_12 ;
for( V_339 = 0 ; V_339 < V_608 ; V_339 ++ )
F_4 ( L_168 , ( unsigned char ) V_10 [ V_339 ] ) ;
for(; V_339 < 17 ; V_339 ++ )
F_4 ( L_169 ) ;
for( V_339 = 0 ; V_339 < V_608 ; V_339 ++ ) {
if ( V_10 [ V_339 ] >= 040 && V_10 [ V_339 ] <= 0176 )
F_4 ( L_170 , V_10 [ V_339 ] ) ;
else
F_4 ( L_171 ) ;
}
F_4 ( L_172 ) ;
V_10 += V_608 ;
V_12 -= V_608 ;
}
}
static void V_483 ( unsigned long V_609 )
{
T_1 * V_1 = ( T_1 * ) V_609 ;
unsigned long V_11 ;
if ( V_29 >= V_30 )
F_4 ( L_173 ,
__FILE__ , __LINE__ , V_1 -> V_26 ) ;
if( V_1 -> V_69 && V_1 -> V_64 . V_65 == V_66 ) {
V_1 -> V_105 . V_610 ++ ;
}
F_11 ( & V_1 -> V_46 , V_11 ) ;
V_1 -> V_69 = false ;
V_1 -> V_70 = V_1 -> V_72 = V_1 -> V_84 = 0 ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
#if V_305
if ( V_1 -> V_41 )
F_95 ( V_1 ) ;
else
#endif
F_113 ( V_1 ) ;
}
static void V_484 ( unsigned long V_609 )
{
T_7 V_257 = 0 ;
T_1 * V_1 = ( T_1 * ) V_609 ;
unsigned long V_11 ;
unsigned char V_611 ;
F_11 ( & V_1 -> V_46 , V_11 ) ;
F_62 ( V_1 ) ;
F_12 ( & V_1 -> V_46 , V_11 ) ;
V_611 = V_1 -> V_612 ^ V_1 -> V_54 ;
V_1 -> V_612 = V_1 -> V_54 ;
if ( V_611 & V_128 )
V_257 |= V_313 | ( V_1 -> V_54 & V_128 ) ;
if ( V_611 & V_130 )
V_257 |= V_314 | ( V_1 -> V_54 & V_130 ) ;
if ( V_611 & V_129 )
V_257 |= V_276 | ( V_1 -> V_54 & V_129 ) ;
if ( V_611 & V_127 )
V_257 |= V_307 | ( V_1 -> V_54 & V_127 ) ;
if ( V_257 )
F_120 ( V_1 , V_257 ) ;
F_140 ( & V_1 -> V_354 , V_80 + F_141 ( 10 ) ) ;
}
static unsigned char F_73 ( T_1 * V_1 , unsigned char V_613 )
{
F_227 () ;
return * V_614 ;
}
static void F_74 ( T_1 * V_1 , unsigned char V_613 , unsigned char V_615 )
{
F_227 () ;
* V_614 = V_615 ;
}
static T_7 F_135 ( T_1 * V_1 , unsigned char V_613 )
{
F_227 () ;
return * ( ( T_7 * ) V_614 ) ;
}
static void F_124 ( T_1 * V_1 , unsigned char V_613 , T_7 V_615 )
{
F_227 () ;
* ( ( T_7 * ) V_614 ) = V_615 ;
}
static unsigned char F_215 ( T_1 * V_1 )
{
unsigned char * V_614 = ( unsigned char * ) V_1 -> V_465 ;
return * V_614 ;
}
static void F_213 ( T_1 * V_1 )
{
unsigned char * V_614 = ( unsigned char * ) V_1 -> V_465 ;
* V_614 = V_1 -> V_345 [ 0 ] -> V_505 ;
}
static int T_15 F_228 ( struct V_472 * V_151 ,
const struct V_616 * V_617 )
{
if ( F_229 ( V_151 ) ) {
F_4 ( L_174 , V_151 ) ;
return - V_68 ;
}
F_198 ( ++ V_618 , V_151 ) ;
return 0 ;
}
static void T_16 F_230 ( struct V_472 * V_151 )
{
}
