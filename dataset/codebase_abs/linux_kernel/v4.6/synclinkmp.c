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
if ( ( V_46 -> V_47 & V_48 ) && ! F_28 ( V_9 ) ) {
V_1 -> V_49 &= ~ ( V_50 | V_51 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_29 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
if ( ! ( V_46 -> V_47 & V_48 ) && F_28 ( V_9 ) ) {
V_1 -> V_49 |= V_51 ;
if ( ! F_30 ( V_9 ) || ! F_31 ( V_52 , & V_9 -> V_11 ) )
V_1 -> V_49 |= V_50 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_29 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
if ( V_46 -> V_47 & V_53 && ! F_30 ( V_9 ) ) {
V_9 -> V_54 = 0 ;
F_32 ( V_9 ) ;
}
}
static int F_33 ( struct V_8 * V_9 ,
const unsigned char * V_55 , int V_12 )
{
int V_56 , V_57 = 0 ;
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_15 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_12 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_16 ) )
goto V_38;
if ( ! V_1 -> V_58 )
goto V_38;
if ( V_1 -> V_59 . V_60 == V_61 ) {
if ( V_12 > V_1 -> V_62 ) {
V_57 = - V_63 ;
goto V_38;
}
if ( V_1 -> V_64 )
goto V_38;
if ( V_1 -> V_65 ) {
F_34 ( V_1 , V_1 -> V_58 , V_1 -> V_65 ) ;
goto V_66;
}
V_57 = V_1 -> V_65 = V_12 ;
F_34 ( V_1 , V_55 , V_12 ) ;
goto V_66;
}
for (; ; ) {
V_56 = F_35 ( int , V_12 ,
F_36 ( V_1 -> V_62 - V_1 -> V_65 - 1 ,
V_1 -> V_62 - V_1 -> V_67 ) ) ;
if ( V_56 <= 0 )
break;
memcpy ( V_1 -> V_58 + V_1 -> V_67 , V_55 , V_56 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_67 += V_56 ;
if ( V_1 -> V_67 >= V_1 -> V_62 )
V_1 -> V_67 -= V_1 -> V_62 ;
V_1 -> V_65 += V_56 ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_55 += V_56 ;
V_12 -= V_56 ;
V_57 += V_56 ;
}
if ( V_1 -> V_59 . V_60 == V_61 ) {
if ( V_12 ) {
V_57 = V_1 -> V_65 = 0 ;
goto V_38;
}
F_34 ( V_1 , V_1 -> V_58 , V_1 -> V_65 ) ;
}
V_66:
if ( V_1 -> V_65 && ! V_9 -> V_68 && ! V_9 -> V_54 ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_64 )
F_37 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
V_38:
if ( V_31 >= V_32 )
F_4 ( L_17 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_57 ) ;
return V_57 ;
}
static int F_38 ( struct V_8 * V_9 , unsigned char V_69 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
int V_57 = 0 ;
if ( V_31 >= V_32 ) {
F_4 ( L_18 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_69 ) ;
}
if ( F_2 ( V_1 , V_9 -> V_2 , L_19 ) )
return 0 ;
if ( ! V_1 -> V_58 )
return 0 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ( V_1 -> V_59 . V_60 != V_61 ) ||
! V_1 -> V_64 ) {
if ( V_1 -> V_65 < V_1 -> V_62 - 1 ) {
V_1 -> V_58 [ V_1 -> V_67 ++ ] = V_69 ;
if ( V_1 -> V_67 >= V_1 -> V_62 )
V_1 -> V_67 -= V_1 -> V_62 ;
V_1 -> V_65 ++ ;
V_57 = 1 ;
}
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_57 ;
}
static void F_39 ( struct V_8 * V_9 , char V_69 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_20 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_69 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_21 ) )
return;
V_1 -> V_70 = V_69 ;
if ( V_69 ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_71 )
F_37 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
}
static void F_18 ( struct V_8 * V_9 , int V_41 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_72 , V_73 ;
if ( ! V_1 )
return;
if ( V_31 >= V_32 )
F_4 ( L_22 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_23 ) )
return;
if ( ! F_31 ( V_74 , & V_1 -> V_27 . V_11 ) )
goto exit;
V_72 = V_75 ;
if ( V_1 -> V_59 . V_76 ) {
V_73 = V_1 -> V_41 / ( 32 * 5 ) ;
if ( ! V_73 )
V_73 ++ ;
} else
V_73 = 1 ;
if ( V_41 )
V_73 = F_35 (unsigned long, char_time, timeout) ;
if ( V_1 -> V_59 . V_60 == V_61 ) {
while ( V_1 -> V_64 ) {
F_40 ( F_41 ( V_73 ) ) ;
if ( F_42 ( V_77 ) )
break;
if ( V_41 && F_43 ( V_75 , V_72 + V_41 ) )
break;
}
} else {
while ( V_1 -> V_64 && V_1 -> V_71 ) {
F_40 ( F_41 ( V_73 ) ) ;
if ( F_42 ( V_77 ) )
break;
if ( V_41 && F_43 ( V_75 , V_72 + V_41 ) )
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
int V_57 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_25 ) )
return 0 ;
if ( V_1 -> V_59 . V_60 == V_61 ) {
V_57 = ( V_1 -> V_64 ) ? 0 : V_78 ;
} else {
V_57 = V_1 -> V_62 - V_1 -> V_65 - 1 ;
if ( V_57 < 0 )
V_57 = 0 ;
}
if ( V_31 >= V_32 )
F_4 ( L_26 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_57 ) ;
return V_57 ;
}
static void F_45 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_27 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_65 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_28 ) )
return;
if ( V_1 -> V_65 <= 0 || V_9 -> V_68 || V_9 -> V_54 ||
! V_1 -> V_58 )
return;
if ( V_31 >= V_32 )
F_4 ( L_29 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_64 ) {
if ( ( V_1 -> V_59 . V_60 == V_61 ) &&
V_1 -> V_65 ) {
F_34 ( V_1 ,
V_1 -> V_58 , V_1 -> V_65 ) ;
}
F_37 ( V_1 ) ;
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
V_1 -> V_65 = V_1 -> V_67 = V_1 -> V_79 = 0 ;
F_46 ( & V_1 -> V_80 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
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
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_71 )
F_49 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
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
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_71 )
F_37 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
static int F_50 ( struct V_8 * V_9 ,
unsigned int V_81 , unsigned long V_82 )
{
T_1 * V_1 = V_9 -> V_26 ;
void T_3 * V_83 = ( void T_3 * ) V_82 ;
if ( V_31 >= V_32 )
F_4 ( L_36 , __FILE__ , __LINE__ ,
V_1 -> V_25 , V_81 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_37 ) )
return - V_21 ;
if ( ( V_81 != V_84 ) && ( V_81 != V_85 ) &&
( V_81 != V_86 ) ) {
if ( V_9 -> V_11 & ( 1 << V_87 ) )
return - V_63 ;
}
switch ( V_81 ) {
case V_88 :
return F_51 ( V_1 , V_83 ) ;
case V_89 :
return F_52 ( V_1 , V_83 ) ;
case V_90 :
return F_53 ( V_1 , V_83 ) ;
case V_91 :
return F_54 ( V_1 , ( int ) V_82 ) ;
case V_92 :
return F_55 ( V_1 , ( int ) V_82 ) ;
case V_93 :
return F_56 ( V_1 , ( int ) V_82 ) ;
case V_94 :
return F_57 ( V_1 ) ;
case V_95 :
return F_58 ( V_1 , V_83 ) ;
case V_96 :
return F_59 ( V_1 , V_83 ) ;
case V_97 :
return 0 ;
case V_86 :
return F_60 ( V_1 , ( int ) V_82 ) ;
default:
return - V_98 ;
}
return 0 ;
}
static int F_61 ( struct V_8 * V_9 ,
struct V_99 * V_100 )
{
T_1 * V_1 = V_9 -> V_26 ;
struct V_101 V_102 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_102 = V_1 -> V_100 ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_100 -> V_103 = V_102 . V_103 ;
V_100 -> V_104 = V_102 . V_104 ;
V_100 -> V_105 = V_102 . V_105 ;
V_100 -> V_106 = V_102 . V_106 ;
V_100 -> V_107 = V_102 . V_107 ;
V_100 -> V_108 = V_102 . V_108 ;
V_100 -> V_109 = V_102 . V_109 ;
V_100 -> V_110 = V_102 . V_110 ;
V_100 -> V_111 = V_102 . V_111 ;
V_100 -> V_112 = V_102 . V_112 ;
V_100 -> V_113 = V_102 . V_113 ;
return 0 ;
}
static inline void F_62 ( struct V_114 * V_115 , T_1 * V_1 )
{
char V_116 [ 30 ] ;
unsigned long V_11 ;
F_63 ( V_115 , L_38
L_39 ,
V_1 -> V_25 ,
V_1 -> V_117 ,
V_1 -> V_118 ,
V_1 -> V_119 ,
V_1 -> V_120 ,
V_1 -> V_121 ,
V_1 -> V_62 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_64 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_116 [ 0 ] = 0 ;
V_116 [ 1 ] = 0 ;
if ( V_1 -> V_49 & V_50 )
strcat ( V_116 , L_40 ) ;
if ( V_1 -> V_49 & V_122 )
strcat ( V_116 , L_41 ) ;
if ( V_1 -> V_49 & V_51 )
strcat ( V_116 , L_42 ) ;
if ( V_1 -> V_49 & V_123 )
strcat ( V_116 , L_43 ) ;
if ( V_1 -> V_49 & V_124 )
strcat ( V_116 , L_44 ) ;
if ( V_1 -> V_49 & V_125 )
strcat ( V_116 , L_45 ) ;
if ( V_1 -> V_59 . V_60 == V_61 ) {
F_63 ( V_115 , L_46 ,
V_1 -> V_100 . V_126 , V_1 -> V_100 . V_127 ) ;
if ( V_1 -> V_100 . V_128 )
F_63 ( V_115 , L_47 , V_1 -> V_100 . V_128 ) ;
if ( V_1 -> V_100 . V_129 )
F_63 ( V_115 , L_48 , V_1 -> V_100 . V_129 ) ;
if ( V_1 -> V_100 . V_130 )
F_63 ( V_115 , L_49 , V_1 -> V_100 . V_130 ) ;
if ( V_1 -> V_100 . V_131 )
F_63 ( V_115 , L_50 , V_1 -> V_100 . V_131 ) ;
if ( V_1 -> V_100 . V_132 )
F_63 ( V_115 , L_51 , V_1 -> V_100 . V_132 ) ;
if ( V_1 -> V_100 . V_133 )
F_63 ( V_115 , L_50 , V_1 -> V_100 . V_133 ) ;
} else {
F_63 ( V_115 , L_52 ,
V_1 -> V_100 . V_108 , V_1 -> V_100 . V_107 ) ;
if ( V_1 -> V_100 . V_109 )
F_63 ( V_115 , L_53 , V_1 -> V_100 . V_109 ) ;
if ( V_1 -> V_100 . V_111 )
F_63 ( V_115 , L_54 , V_1 -> V_100 . V_111 ) ;
if ( V_1 -> V_100 . V_112 )
F_63 ( V_115 , L_55 , V_1 -> V_100 . V_112 ) ;
if ( V_1 -> V_100 . V_110 )
F_63 ( V_115 , L_56 , V_1 -> V_100 . V_110 ) ;
}
F_63 ( V_115 , L_57 , V_116 + 1 ) ;
F_63 ( V_115 , L_58 ,
V_1 -> V_64 , V_1 -> V_134 , V_1 -> V_135 ,
V_1 -> V_136 ) ;
}
static int F_65 ( struct V_114 * V_115 , void * V_137 )
{
T_1 * V_1 ;
F_63 ( V_115 , L_59 , V_138 ) ;
V_1 = V_22 ;
while( V_1 ) {
F_62 ( V_115 , V_1 ) ;
V_1 = V_1 -> V_23 ;
}
return 0 ;
}
static int F_66 ( struct V_139 * V_139 , struct V_28 * V_28 )
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
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_65 ) ;
return V_1 -> V_65 ;
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
if ( F_30 ( V_9 ) ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_49 &= ~ V_50 ;
F_29 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
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
if ( V_1 -> V_70 )
V_1 -> V_70 = 0 ;
else
F_39 ( V_9 , F_73 ( V_9 ) ) ;
}
if ( F_30 ( V_9 ) ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_49 |= V_50 ;
F_29 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
}
static int F_74 ( struct V_8 * V_9 , int V_140 )
{
unsigned char V_141 ;
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_66 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_140 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_67 ) )
return - V_142 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_141 = F_75 ( V_1 , V_143 ) ;
if ( V_140 == - 1 )
V_141 |= V_144 ;
else
V_141 &= ~ V_144 ;
F_76 ( V_1 , V_143 , V_141 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_77 ( struct V_145 * V_146 , unsigned short V_147 ,
unsigned short V_111 )
{
T_1 * V_1 = F_78 ( V_146 ) ;
unsigned char V_148 ;
unsigned short V_149 ;
if ( V_1 -> V_27 . V_12 )
return - V_37 ;
switch ( V_147 )
{
case V_150 : V_148 = V_151 ; break;
case V_152 : V_148 = V_153 ; break;
case V_154 : V_148 = V_155 ; break;
case V_156 : V_148 = V_157 ; break;
case V_158 : V_148 = V_159 ; break;
default: return - V_142 ;
}
switch ( V_111 )
{
case V_160 : V_149 = V_161 ; break;
case V_162 : V_149 = V_163 ; break;
case V_164 : V_149 = V_165 ; break;
default: return - V_142 ;
}
V_1 -> V_59 . V_147 = V_148 ;
V_1 -> V_59 . V_166 = V_149 ;
if ( V_1 -> V_36 )
F_79 ( V_1 ) ;
return 0 ;
}
static T_4 F_80 ( struct V_167 * V_168 ,
struct V_145 * V_146 )
{
T_1 * V_1 = F_78 ( V_146 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( V_169 L_68 , __FILE__ , V_146 -> V_2 ) ;
F_81 ( V_146 ) ;
V_1 -> V_65 = V_168 -> V_170 ;
F_34 ( V_1 , V_168 -> V_10 , V_168 -> V_170 ) ;
V_146 -> V_171 . V_172 ++ ;
V_146 -> V_171 . V_173 += V_168 -> V_170 ;
F_82 ( V_168 ) ;
V_146 -> V_174 = V_75 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! V_1 -> V_64 )
F_37 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_175 ;
}
static int F_83 ( struct V_145 * V_146 )
{
T_1 * V_1 = F_78 ( V_146 ) ;
int V_176 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_69 , __FILE__ , V_146 -> V_2 ) ;
V_176 = F_84 ( V_146 ) ;
if ( V_176 )
return V_176 ;
F_11 ( & V_1 -> V_35 , V_11 ) ;
if ( V_1 -> V_27 . V_12 != 0 || V_1 -> V_36 != 0 ) {
F_4 ( V_177 L_70 , V_146 -> V_2 ) ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
return - V_37 ;
}
V_1 -> V_36 = 1 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
if ( ( V_176 = F_13 ( V_1 ) ) != 0 ) {
F_11 ( & V_1 -> V_35 , V_11 ) ;
V_1 -> V_36 = 0 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
return V_176 ;
}
V_1 -> V_49 |= V_50 | V_51 ;
F_79 ( V_1 ) ;
V_146 -> V_174 = V_75 ;
F_85 ( V_146 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_64 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_49 & V_124 )
F_86 ( V_146 ) ;
else
F_87 ( V_146 ) ;
return 0 ;
}
static int F_88 ( struct V_145 * V_146 )
{
T_1 * V_1 = F_78 ( V_146 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_71 , __FILE__ , V_146 -> V_2 ) ;
F_81 ( V_146 ) ;
F_21 ( V_1 ) ;
F_89 ( V_146 ) ;
F_11 ( & V_1 -> V_35 , V_11 ) ;
V_1 -> V_36 = 0 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
return 0 ;
}
static int F_90 ( struct V_145 * V_146 , struct V_178 * V_179 , int V_81 )
{
const T_5 V_180 = sizeof( V_181 ) ;
V_181 V_182 ;
V_181 T_3 * line = V_179 -> V_183 . V_184 . V_185 ;
T_1 * V_1 = F_78 ( V_146 ) ;
unsigned int V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_72 , __FILE__ , V_146 -> V_2 ) ;
if ( V_1 -> V_27 . V_12 )
return - V_37 ;
if ( V_81 != V_186 )
return F_91 ( V_146 , V_179 , V_81 ) ;
switch( V_179 -> V_183 . type ) {
case V_187 :
V_179 -> V_183 . type = V_188 ;
if ( V_179 -> V_183 . V_180 < V_180 ) {
V_179 -> V_183 . V_180 = V_180 ;
return - V_189 ;
}
V_11 = V_1 -> V_59 . V_11 & ( V_190 | V_191 |
V_192 | V_193 |
V_194 | V_195 |
V_196 | V_197 ) ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
switch ( V_11 ) {
case ( V_190 | V_194 ) : V_182 . V_198 = V_199 ; break;
case ( V_192 | V_196 ) : V_182 . V_198 = V_200 ; break;
case ( V_190 | V_196 ) : V_182 . V_198 = V_201 ; break;
case ( V_190 | V_197 ) : V_182 . V_198 = V_202 ; break;
default: V_182 . V_198 = V_203 ;
}
V_182 . V_204 = V_1 -> V_59 . V_205 ;
V_182 . V_206 = V_1 -> V_59 . V_206 ? 1 : 0 ;
if ( F_92 ( line , & V_182 , V_180 ) )
return - V_207 ;
return 0 ;
case V_188 :
if( ! F_93 ( V_208 ) )
return - V_209 ;
if ( F_94 ( & V_182 , line , V_180 ) )
return - V_207 ;
switch ( V_182 . V_198 )
{
case V_199 : V_11 = V_190 | V_194 ; break;
case V_202 : V_11 = V_190 | V_197 ; break;
case V_200 : V_11 = V_192 | V_196 ; break;
case V_201 : V_11 = V_190 | V_196 ; break;
case V_203 : V_11 = V_1 -> V_59 . V_11 &
( V_190 | V_191 |
V_192 | V_193 |
V_194 | V_195 |
V_196 | V_197 ) ; break;
default: return - V_142 ;
}
if ( V_182 . V_206 != 0 && V_182 . V_206 != 1 )
return - V_142 ;
V_1 -> V_59 . V_11 &= ~ ( V_190 | V_191 |
V_192 | V_193 |
V_194 | V_195 |
V_196 | V_197 ) ;
V_1 -> V_59 . V_11 |= V_11 ;
V_1 -> V_59 . V_206 = V_182 . V_206 ;
if ( V_11 & ( V_192 | V_196 ) )
V_1 -> V_59 . V_205 = V_182 . V_204 ;
else
V_1 -> V_59 . V_205 = 0 ;
if ( V_1 -> V_36 )
F_79 ( V_1 ) ;
return 0 ;
default:
return F_91 ( V_146 , V_179 , V_81 ) ;
}
}
static void F_95 ( struct V_145 * V_146 )
{
T_1 * V_1 = F_78 ( V_146 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_73 , V_146 -> V_2 ) ;
V_146 -> V_171 . V_210 ++ ;
V_146 -> V_171 . V_211 ++ ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_49 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
F_96 ( V_146 ) ;
}
static void F_97 ( T_1 * V_1 )
{
if ( F_98 ( V_1 -> V_212 ) )
F_96 ( V_1 -> V_212 ) ;
}
static void F_99 ( T_1 * V_1 , char * V_55 , int V_180 )
{
struct V_167 * V_168 = F_100 ( V_180 ) ;
struct V_145 * V_146 = V_1 -> V_212 ;
if ( V_31 >= V_32 )
F_4 ( L_74 , V_146 -> V_2 ) ;
if ( V_168 == NULL ) {
F_4 ( V_213 L_75 ,
V_146 -> V_2 ) ;
V_146 -> V_171 . V_214 ++ ;
return;
}
memcpy ( F_101 ( V_168 , V_180 ) , V_55 , V_180 ) ;
V_168 -> V_215 = F_102 ( V_168 , V_146 ) ;
V_146 -> V_171 . V_216 ++ ;
V_146 -> V_171 . V_217 += V_180 ;
F_103 ( V_168 ) ;
}
static int F_104 ( T_1 * V_1 )
{
int V_176 ;
struct V_145 * V_146 ;
T_6 * V_218 ;
V_146 = F_105 ( V_1 ) ;
if ( ! V_146 ) {
F_4 ( V_219 L_76 , __FILE__ ) ;
return - V_220 ;
}
V_146 -> V_221 = V_1 -> V_117 ;
V_146 -> V_222 = V_1 -> V_117 + V_223 - 1 ;
V_146 -> V_224 = V_1 -> V_121 ;
V_146 -> V_225 = & V_226 ;
V_146 -> V_227 = 10 * V_228 ;
V_146 -> V_229 = 50 ;
V_218 = F_106 ( V_146 ) ;
V_218 -> V_230 = F_77 ;
V_218 -> V_231 = F_80 ;
V_176 = F_107 ( V_146 ) ;
if ( V_176 ) {
F_4 ( V_177 L_77 , __FILE__ ) ;
F_108 ( V_146 ) ;
return V_176 ;
}
V_1 -> V_212 = V_146 ;
return 0 ;
}
static void F_109 ( T_1 * V_1 )
{
F_110 ( V_1 -> V_212 ) ;
F_108 ( V_1 -> V_212 ) ;
V_1 -> V_212 = NULL ;
}
static int F_111 ( T_1 * V_1 )
{
unsigned long V_11 ;
int V_176 = 0 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_136 & V_232 ) {
V_1 -> V_136 &= ~ V_232 ;
V_176 = V_232 ;
} else if ( V_1 -> V_136 & V_233 ) {
V_1 -> V_136 &= ~ V_233 ;
V_176 = V_233 ;
} else if ( V_1 -> V_136 & V_234 ) {
V_1 -> V_136 &= ~ V_234 ;
V_176 = V_234 ;
}
if ( ! V_176 ) {
V_1 -> V_135 = false ;
V_1 -> V_134 = false ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_176 ;
}
static void F_112 ( struct V_235 * V_236 )
{
T_1 * V_1 = F_113 ( V_236 , T_1 , V_237 ) ;
int V_238 ;
if ( V_31 >= V_239 )
F_4 ( L_78 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_135 = true ;
while( ( V_238 = F_111 ( V_1 ) ) != 0 ) {
if ( V_31 >= V_239 )
F_4 ( L_79 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_238 ) ;
switch ( V_238 ) {
case V_232 :
F_114 ( V_1 ) ;
break;
case V_233 :
F_115 ( V_1 ) ;
break;
case V_234 :
F_116 ( V_1 ) ;
break;
default:
F_4 ( L_80 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_238 ) ;
break;
}
}
if ( V_31 >= V_239 )
F_4 ( L_81 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_114 ( T_1 * V_1 )
{
if ( V_31 >= V_239 )
F_4 ( L_82 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
while( F_117 ( V_1 ) ) ;
}
static void F_115 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
if ( V_31 >= V_239 )
F_4 ( L_83 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_9 )
F_47 ( V_9 ) ;
}
static void F_116 ( T_1 * V_1 )
{
if ( V_31 >= V_239 )
F_4 ( L_84 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_240 = 0 ;
V_1 -> V_241 = 0 ;
V_1 -> V_242 = 0 ;
V_1 -> V_243 = 0 ;
}
static void F_118 ( T_1 * V_1 )
{
unsigned char V_244 = ( V_1 -> V_245 & 1 ) ? V_246 : V_247 ;
F_76 ( V_1 , V_248 , 0 ) ;
F_76 ( V_1 , ( unsigned char ) ( V_244 + V_249 ) , 0 ) ;
V_1 -> V_250 = true ;
if ( V_31 >= V_251 )
F_4 ( L_85 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_119 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
struct V_101 * V_100 = & V_1 -> V_100 ;
unsigned char V_252 = F_75 ( V_1 , V_253 ) & V_1 -> V_254 & ( V_255 + V_256 + V_257 + V_258 ) ;
unsigned char V_259 = F_75 ( V_1 , V_260 ) & V_1 -> V_261 & V_262 ;
if ( V_252 )
F_76 ( V_1 , V_253 , V_252 ) ;
if ( V_259 )
F_76 ( V_1 , V_260 , V_259 ) ;
if ( V_31 >= V_251 )
F_4 ( L_86 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_252 , V_259 ) ;
if ( V_1 -> V_59 . V_60 == V_263 ) {
if ( V_252 & V_258 ) {
V_100 -> V_112 ++ ;
if ( ! ( V_252 & V_1 -> V_264 ) ) {
if ( V_1 -> V_265 & V_258 ) {
F_120 ( & V_1 -> V_27 , 0 , V_266 ) ;
if ( V_9 && ( V_1 -> V_27 . V_11 & V_267 ) )
F_121 ( V_9 ) ;
}
}
}
}
else {
if ( V_252 & ( V_255 | V_256 ) ) {
if ( V_252 & V_255 )
V_1 -> V_100 . V_268 ++ ;
else if ( V_252 & V_256 )
V_1 -> V_100 . V_269 ++ ;
F_25 ( & V_1 -> V_270 ) ;
}
}
if ( V_252 & V_257 ) {
F_64 ( V_1 ) ;
F_122 ( V_1 ,
V_271 | ( V_1 -> V_49 & V_124 ) ) ;
}
}
static void F_123 ( T_1 * V_1 )
{
T_7 V_252 ;
unsigned char V_272 ;
struct V_101 * V_100 = & V_1 -> V_100 ;
if ( V_31 >= V_251 )
F_4 ( L_87 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
while( ( V_252 = F_75 ( V_1 , V_273 ) ) & V_274 )
{
int V_275 = 0 ;
bool V_276 = false ;
V_272 = F_75 ( V_1 , V_277 ) ;
V_100 -> V_107 ++ ;
if ( V_252 & ( V_278 + V_279 + V_262 ) ) {
F_4 ( L_88 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_252 ) ;
if ( V_252 & V_278 )
V_100 -> V_111 ++ ;
else if ( V_252 & V_279 )
V_100 -> V_109 ++ ;
else if ( V_252 & V_262 )
V_100 -> V_110 ++ ;
if ( V_252 & V_1 -> V_280 )
continue;
V_252 &= V_1 -> V_281 ;
if ( V_252 & V_278 )
V_275 = V_282 ;
else if ( V_252 & V_279 )
V_275 = V_283 ;
if ( V_252 & V_262 ) {
V_276 = true ;
}
}
F_120 ( & V_1 -> V_27 , V_272 , V_275 ) ;
if ( V_276 )
F_120 ( & V_1 -> V_27 , 0 , V_284 ) ;
}
if ( V_31 >= V_251 ) {
F_4 ( L_89 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_100 -> V_107 , V_100 -> V_112 , V_100 -> V_111 ,
V_100 -> V_109 , V_100 -> V_110 ) ;
}
F_124 ( & V_1 -> V_27 ) ;
}
static void F_125 ( T_1 * V_1 , unsigned char V_252 )
{
if ( V_31 >= V_251 )
F_4 ( L_90 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_252 ) ;
F_76 ( V_1 , V_285 + V_286 , 0x00 ) ;
F_76 ( V_1 , V_285 + V_287 , 0xc0 ) ;
F_76 ( V_1 , V_285 + V_288 , V_289 ) ;
if ( V_252 & V_290 ) {
F_76 ( V_1 , V_291 , V_292 ) ;
F_76 ( V_1 , V_291 , V_293 ) ;
} else
F_76 ( V_1 , V_291 , V_294 ) ;
V_1 -> V_295 &= ~ V_296 ;
V_1 -> V_254 &= ~ ( V_297 + V_290 ) ;
F_126 ( V_1 , V_298 , ( unsigned short ) ( ( V_1 -> V_254 << 8 ) + V_1 -> V_295 ) ) ;
F_76 ( V_1 , V_253 , ( unsigned char ) ( V_290 + V_297 ) ) ;
if ( V_1 -> V_64 ) {
if ( V_1 -> V_59 . V_60 != V_263 ) {
if ( V_252 & V_290 )
V_1 -> V_100 . V_128 ++ ;
else if ( V_252 & V_297 )
V_1 -> V_100 . V_126 ++ ;
}
V_1 -> V_64 = false ;
V_1 -> V_65 = V_1 -> V_67 = V_1 -> V_79 = 0 ;
F_46 ( & V_1 -> V_80 ) ;
if ( V_1 -> V_59 . V_60 != V_263 && V_1 -> V_299 ) {
V_1 -> V_49 &= ~ V_50 ;
V_1 -> V_299 = false ;
F_29 ( V_1 ) ;
}
#if V_300
if ( V_1 -> V_36 )
F_97 ( V_1 ) ;
else
#endif
{
if ( V_1 -> V_27 . V_9 && ( V_1 -> V_27 . V_9 -> V_68 || V_1 -> V_27 . V_9 -> V_54 ) ) {
F_49 ( V_1 ) ;
return;
}
V_1 -> V_136 |= V_233 ;
}
}
}
static void F_127 ( T_1 * V_1 )
{
unsigned char V_252 = F_75 ( V_1 , V_253 ) & V_1 -> V_254 & ( V_290 + V_297 + V_301 ) ;
F_76 ( V_1 , V_253 , V_252 ) ;
if ( V_31 >= V_251 )
F_4 ( L_91 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_252 ) ;
if ( V_252 & ( V_290 + V_297 ) )
F_125 ( V_1 , V_252 ) ;
if ( V_252 & V_301 ) {
F_64 ( V_1 ) ;
F_122 ( V_1 ,
V_302 | ( V_1 -> V_49 & V_122 ) ) ;
}
}
static void F_128 ( T_1 * V_1 )
{
if ( V_31 >= V_251 )
F_4 ( L_92 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_65 ) ;
if ( V_1 -> V_59 . V_60 != V_263 ) {
V_1 -> V_295 &= ~ V_296 ;
V_1 -> V_254 |= V_297 ;
F_126 ( V_1 , V_298 , ( unsigned short ) ( ( V_1 -> V_254 << 8 ) + V_1 -> V_295 ) ) ;
return;
}
if ( V_1 -> V_27 . V_9 && ( V_1 -> V_27 . V_9 -> V_68 || V_1 -> V_27 . V_9 -> V_54 ) ) {
F_49 ( V_1 ) ;
return;
}
if ( V_1 -> V_65 )
F_129 ( V_1 ) ;
else {
V_1 -> V_64 = false ;
V_1 -> V_295 &= ~ V_296 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
}
if ( V_1 -> V_65 < V_303 )
V_1 -> V_136 |= V_233 ;
}
static void F_130 ( T_1 * V_1 )
{
unsigned char V_252 = F_75 ( V_1 , V_304 + V_287 ) & 0xc0 ;
F_76 ( V_1 , V_304 + V_287 , ( unsigned char ) ( V_252 | 1 ) ) ;
if ( V_31 >= V_251 )
F_4 ( L_93 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_252 ) ;
V_1 -> V_136 |= V_232 ;
}
static void F_131 ( T_1 * V_1 )
{
unsigned char V_252 = F_75 ( V_1 , V_304 + V_287 ) & 0x30 ;
F_76 ( V_1 , V_304 + V_287 , ( unsigned char ) ( V_252 | 1 ) ) ;
if ( V_31 >= V_251 )
F_4 ( L_94 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_252 ) ;
V_1 -> V_305 = true ;
V_1 -> V_136 |= V_232 ;
}
static void F_132 ( T_1 * V_1 )
{
unsigned char V_306 = F_75 ( V_1 , V_253 ) ;
F_76 ( V_1 , V_285 + V_286 , 0x00 ) ;
F_76 ( V_1 , V_285 + V_287 , 0xc0 ) ;
F_76 ( V_1 , V_285 + V_288 , V_289 ) ;
if ( V_31 >= V_251 )
F_4 ( L_95 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_306 ) ;
F_126 ( V_1 , V_307 , 0 ) ;
V_1 -> V_295 |= V_296 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
}
static void F_133 ( T_1 * V_1 )
{
unsigned char V_252 = F_75 ( V_1 , V_285 + V_287 ) & 0x30 ;
F_76 ( V_1 , V_285 + V_287 , ( unsigned char ) ( V_252 | 1 ) ) ;
if ( V_31 >= V_251 )
F_4 ( L_96 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_252 ) ;
}
static void F_122 ( T_1 * V_1 , T_7 V_252 )
{
struct V_101 * V_100 ;
if ( V_31 >= V_251 )
F_4 ( L_97 ,
__FILE__ , __LINE__ , V_252 ) ;
if ( V_252 & ( V_302 | V_271 |
V_308 | V_309 ) ) {
V_100 = & V_1 -> V_100 ;
if ( V_252 & V_309 ) {
V_100 -> V_105 ++ ;
if ( V_252 & V_125 )
V_1 -> V_310 . V_311 ++ ;
else
V_1 -> V_310 . V_312 ++ ;
}
if ( V_252 & V_308 ) {
V_100 -> V_104 ++ ;
if ( V_252 & V_123 )
V_1 -> V_310 . V_313 ++ ;
else
V_1 -> V_310 . V_314 ++ ;
}
if ( V_252 & V_271 ) {
if ( ( V_1 -> V_242 ) ++ >= V_315 ) {
V_1 -> V_254 &= ~ V_257 ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
}
V_100 -> V_106 ++ ;
if ( V_252 & V_124 ) {
V_1 -> V_310 . V_317 ++ ;
} else
V_1 -> V_310 . V_318 ++ ;
#if V_300
if ( V_1 -> V_36 ) {
if ( V_252 & V_124 )
F_86 ( V_1 -> V_212 ) ;
else
F_87 ( V_1 -> V_212 ) ;
}
#endif
}
if ( V_252 & V_302 )
{
if ( ( V_1 -> V_243 ) ++ >= V_315 ) {
V_1 -> V_254 &= ~ V_301 ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
}
V_100 -> V_103 ++ ;
if ( V_252 & V_122 )
V_1 -> V_310 . V_319 ++ ;
else
V_1 -> V_310 . V_320 ++ ;
}
F_25 ( & V_1 -> V_321 ) ;
F_25 ( & V_1 -> V_270 ) ;
if ( ( V_1 -> V_27 . V_11 & V_322 ) &&
( V_252 & V_271 ) ) {
if ( V_31 >= V_251 )
F_4 ( L_98 , V_1 -> V_25 ,
( V_252 & V_124 ) ? L_99 : L_100 ) ;
if ( V_252 & V_124 )
F_25 ( & V_1 -> V_27 . V_44 ) ;
else {
if ( V_31 >= V_251 )
F_4 ( L_101 ) ;
if ( V_1 -> V_27 . V_9 )
F_134 ( V_1 -> V_27 . V_9 ) ;
}
}
if ( F_135 ( & V_1 -> V_27 ) &&
( V_252 & V_302 ) ) {
if ( V_1 -> V_27 . V_9 ) {
if ( V_1 -> V_27 . V_9 -> V_54 ) {
if ( V_252 & V_122 ) {
if ( V_31 >= V_251 )
F_4 ( L_102 ) ;
V_1 -> V_27 . V_9 -> V_54 = 0 ;
F_37 ( V_1 ) ;
V_1 -> V_136 |= V_233 ;
return;
}
} else {
if ( ! ( V_252 & V_122 ) ) {
if ( V_31 >= V_251 )
F_4 ( L_103 ) ;
V_1 -> V_27 . V_9 -> V_54 = 1 ;
F_49 ( V_1 ) ;
}
}
}
}
}
V_1 -> V_136 |= V_234 ;
}
static T_8 F_136 ( int V_323 , void * V_324 )
{
T_1 * V_1 = V_324 ;
unsigned char V_252 , V_325 , V_326 = 0 ;
unsigned char V_327 , V_328 , V_329 = 0 ;
unsigned char V_330 , V_331 = 0 ;
unsigned char V_332 ;
unsigned int V_333 ;
unsigned short V_334 ;
if ( V_31 >= V_251 )
F_4 ( V_335 L_104 ,
__FILE__ , __LINE__ , V_1 -> V_121 ) ;
F_137 ( & V_1 -> V_42 ) ;
for(; ; ) {
V_334 = F_138 ( V_1 , V_336 ) ;
V_325 = ( unsigned char ) V_334 ;
V_328 = ( unsigned char ) ( V_334 >> 8 ) ;
V_330 = F_75 ( V_1 , V_337 ) ;
if ( V_31 >= V_251 )
F_4 ( V_335 L_105 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_325 , V_328 , V_330 ) ;
if ( V_1 -> V_338 == 4 ) {
V_334 = F_138 ( V_1 -> V_339 [ 2 ] , V_336 ) ;
V_326 = ( unsigned char ) V_334 ;
V_329 = ( unsigned char ) ( V_334 >> 8 ) ;
V_331 = F_75 ( V_1 -> V_339 [ 2 ] , V_337 ) ;
if ( V_31 >= V_251 )
F_4 ( L_106 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_326 , V_329 , V_331 ) ;
}
if ( ! V_325 && ! V_328 && ! V_330 &&
! V_326 && ! V_329 && ! V_331 )
break;
for( V_333 = 0 ; V_333 < V_1 -> V_338 ; V_333 ++ ) {
if ( V_1 -> V_339 [ V_333 ] == NULL )
continue;
if ( V_333 < 2 ) {
V_252 = V_325 ;
V_327 = V_328 ;
} else {
V_252 = V_326 ;
V_327 = V_329 ;
}
V_332 = V_333 & 1 ? 4 : 0 ;
if ( V_252 & V_274 << V_332 )
F_123 ( V_1 -> V_339 [ V_333 ] ) ;
if ( V_252 & V_340 << V_332 )
F_128 ( V_1 -> V_339 [ V_333 ] ) ;
if ( V_252 & V_341 << V_332 )
F_119 ( V_1 -> V_339 [ V_333 ] ) ;
if ( V_252 & V_144 << V_332 )
F_127 ( V_1 -> V_339 [ V_333 ] ) ;
if ( V_327 & V_274 << V_332 )
F_131 ( V_1 -> V_339 [ V_333 ] ) ;
if ( V_327 & V_340 << V_332 )
F_130 ( V_1 -> V_339 [ V_333 ] ) ;
if ( V_327 & V_341 << V_332 )
F_133 ( V_1 -> V_339 [ V_333 ] ) ;
if ( V_327 & V_144 << V_332 )
F_132 ( V_1 -> V_339 [ V_333 ] ) ;
}
if ( V_330 & ( V_342 | V_343 ) )
F_118 ( V_1 -> V_339 [ 0 ] ) ;
if ( V_330 & ( V_344 | V_345 ) )
F_118 ( V_1 -> V_339 [ 1 ] ) ;
if ( V_331 & ( V_342 | V_343 ) )
F_118 ( V_1 -> V_339 [ 2 ] ) ;
if ( V_331 & ( V_344 | V_345 ) )
F_118 ( V_1 -> V_339 [ 3 ] ) ;
}
for( V_333 = 0 ; V_333 < V_1 -> V_338 ; V_333 ++ ) {
T_1 * V_27 = V_1 -> V_339 [ V_333 ] ;
if ( V_27 && ( V_27 -> V_27 . V_12 || V_27 -> V_36 ) &&
V_27 -> V_136 && ! V_27 -> V_135 &&
! V_27 -> V_134 ) {
if ( V_31 >= V_251 )
F_4 ( L_107 ,
__FILE__ , __LINE__ , V_27 -> V_25 ) ;
F_139 ( & V_27 -> V_237 ) ;
V_27 -> V_134 = true ;
}
}
F_140 ( & V_1 -> V_42 ) ;
if ( V_31 >= V_251 )
F_4 ( V_335 L_108 ,
__FILE__ , __LINE__ , V_1 -> V_121 ) ;
return V_346 ;
}
static int F_13 ( T_1 * V_1 )
{
if ( V_31 >= V_32 )
F_4 ( L_109 , __FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_1 -> V_27 . V_11 & V_40 )
return 0 ;
if ( ! V_1 -> V_58 ) {
V_1 -> V_58 = F_141 ( V_1 -> V_62 , V_347 ) ;
if ( ! V_1 -> V_58 ) {
F_4 ( V_219 L_110 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_220 ;
}
}
V_1 -> V_136 = 0 ;
memset ( & V_1 -> V_100 , 0 , sizeof( V_1 -> V_100 ) ) ;
F_142 ( V_1 ) ;
F_27 ( V_1 ) ;
F_143 ( & V_1 -> V_348 , V_75 + F_144 ( 10 ) ) ;
if ( V_1 -> V_27 . V_9 )
F_145 ( V_87 , & V_1 -> V_27 . V_9 -> V_11 ) ;
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
F_25 ( & V_1 -> V_321 ) ;
F_25 ( & V_1 -> V_270 ) ;
F_46 ( & V_1 -> V_80 ) ;
F_46 ( & V_1 -> V_348 ) ;
F_146 ( V_1 -> V_58 ) ;
V_1 -> V_58 = NULL ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_142 ( V_1 ) ;
if ( ! V_1 -> V_27 . V_9 || V_1 -> V_27 . V_9 -> V_349 . V_47 & V_350 ) {
V_1 -> V_49 &= ~ ( V_50 | V_51 ) ;
F_29 ( V_1 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_27 . V_9 )
F_147 ( V_87 , & V_1 -> V_27 . V_9 -> V_11 ) ;
V_1 -> V_27 . V_11 &= ~ V_40 ;
}
static void F_79 ( T_1 * V_1 )
{
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_148 ( V_1 ) ;
F_49 ( V_1 ) ;
V_1 -> V_65 = V_1 -> V_67 = V_1 -> V_79 = 0 ;
if ( V_1 -> V_59 . V_60 == V_61 || V_1 -> V_36 )
F_149 ( V_1 ) ;
else
F_150 ( V_1 ) ;
F_29 ( V_1 ) ;
V_1 -> V_242 = 0 ;
V_1 -> V_243 = 0 ;
V_1 -> V_240 = 0 ;
V_1 -> V_241 = 0 ;
V_1 -> V_254 |= ( V_257 | V_301 ) ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
F_64 ( V_1 ) ;
if ( V_1 -> V_36 || ( V_1 -> V_27 . V_9 && V_1 -> V_27 . V_9 -> V_349 . V_47 & V_351 ) )
F_151 ( V_1 ) ;
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
V_352 = V_1 -> V_27 . V_9 -> V_349 . V_47 ;
if ( V_352 & V_48 )
V_1 -> V_49 |= V_50 | V_51 ;
else
V_1 -> V_49 &= ~ ( V_50 | V_51 ) ;
switch ( V_352 & V_354 ) {
case V_355 : V_1 -> V_59 . V_356 = 5 ; break;
case V_357 : V_1 -> V_59 . V_356 = 6 ; break;
case V_358 : V_1 -> V_59 . V_356 = 7 ; break;
case V_359 : V_1 -> V_59 . V_356 = 8 ; break;
default: V_1 -> V_59 . V_356 = 7 ; break;
}
if ( V_352 & V_360 )
V_1 -> V_59 . V_361 = 2 ;
else
V_1 -> V_59 . V_361 = 1 ;
V_1 -> V_59 . V_111 = V_362 ;
if ( V_352 & V_363 ) {
if ( V_352 & V_364 )
V_1 -> V_59 . V_111 = V_365 ;
else
V_1 -> V_59 . V_111 = V_366 ;
#ifdef F_152
if ( V_352 & F_152 )
V_1 -> V_59 . V_111 = V_367 ;
#endif
}
V_353 = V_1 -> V_59 . V_356 +
V_1 -> V_59 . V_361 + 1 ;
if ( V_1 -> V_59 . V_76 <= 460800 ) {
V_1 -> V_59 . V_76 = F_153 ( V_1 -> V_27 . V_9 ) ;
}
if ( V_1 -> V_59 . V_76 ) {
V_1 -> V_41 = ( 32 * V_228 * V_353 ) /
V_1 -> V_59 . V_76 ;
}
V_1 -> V_41 += V_228 / 50 ;
if ( V_352 & V_53 )
V_1 -> V_27 . V_11 |= V_368 ;
else
V_1 -> V_27 . V_11 &= ~ V_368 ;
if ( V_352 & V_369 )
V_1 -> V_27 . V_11 &= ~ V_322 ;
else
V_1 -> V_27 . V_11 |= V_322 ;
V_1 -> V_281 = V_262 ;
if ( F_154 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_281 |= V_278 | V_279 ;
if ( F_155 ( V_1 -> V_27 . V_9 ) || F_156 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_265 |= V_258 ;
if ( F_157 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_280 |= V_278 | V_279 ;
if ( F_158 ( V_1 -> V_27 . V_9 ) ) {
V_1 -> V_264 |= V_258 ;
if ( F_157 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_280 |= V_262 ;
}
F_79 ( V_1 ) ;
}
static int F_58 ( T_1 * V_1 , struct V_101 T_3 * V_370 )
{
int V_371 ;
if ( V_31 >= V_32 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( ! V_370 ) {
memset ( & V_1 -> V_100 , 0 , sizeof( V_1 -> V_100 ) ) ;
} else {
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_159 ( V_371 , V_370 , & V_1 -> V_100 , sizeof( struct V_101 ) ) ;
F_22 ( & V_1 -> V_27 . V_39 ) ;
if ( V_371 )
return - V_207 ;
}
return 0 ;
}
static int F_51 ( T_1 * V_1 , T_9 T_3 * V_372 )
{
int V_371 ;
if ( V_31 >= V_32 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_159 ( V_371 , V_372 , & V_1 -> V_59 , sizeof( T_9 ) ) ;
F_22 ( & V_1 -> V_27 . V_39 ) ;
if ( V_371 ) {
if ( V_31 >= V_32 )
F_4 ( L_114 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_207 ;
}
return 0 ;
}
static int F_52 ( T_1 * V_1 , T_9 T_3 * V_373 )
{
unsigned long V_11 ;
T_9 V_374 ;
int V_371 ;
if ( V_31 >= V_32 )
F_4 ( L_115 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_160 ( V_371 , & V_374 , V_373 , sizeof( T_9 ) ) ;
if ( V_371 ) {
if ( V_31 >= V_32 )
F_4 ( L_116 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_207 ;
}
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
memcpy ( & V_1 -> V_59 , & V_374 , sizeof( T_9 ) ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
F_27 ( V_1 ) ;
F_22 ( & V_1 -> V_27 . V_39 ) ;
return 0 ;
}
static int F_53 ( T_1 * V_1 , int T_3 * V_375 )
{
int V_371 ;
if ( V_31 >= V_32 )
F_4 ( L_117 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_375 ) ;
F_159 ( V_371 , V_375 , & V_1 -> V_375 , sizeof( int ) ) ;
if ( V_371 ) {
if ( V_31 >= V_32 )
F_4 ( L_118 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_207 ;
}
return 0 ;
}
static int F_54 ( T_1 * V_1 , int V_375 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_119 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_375 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_375 = V_375 ;
F_161 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_55 ( T_1 * V_1 , int V_376 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_120 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_376 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_376 ) {
if ( ! V_1 -> V_71 ) {
F_37 ( V_1 ) ;
}
} else {
if ( V_1 -> V_71 )
F_49 ( V_1 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_57 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_121 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_1 -> V_64 && V_1 -> V_59 . V_60 == V_61 ) {
V_1 -> V_254 &= ~ V_290 ;
V_1 -> V_254 |= V_297 ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
F_76 ( V_1 , V_253 , ( unsigned char ) ( V_297 + V_290 ) ) ;
F_76 ( V_1 , V_285 + V_287 , 0 ) ;
F_76 ( V_1 , V_285 + V_288 , V_289 ) ;
F_76 ( V_1 , V_291 , V_377 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_56 ( T_1 * V_1 , int V_376 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_122 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_376 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_376 ) {
if ( ! V_1 -> V_378 )
F_151 ( V_1 ) ;
} else {
if ( V_1 -> V_378 )
F_148 ( V_1 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_59 ( T_1 * V_1 , int T_3 * V_379 )
{
unsigned long V_11 ;
int V_380 ;
int V_176 = 0 ;
struct V_101 V_381 , V_102 ;
int V_382 ;
int V_383 ;
struct V_384 V_385 , V_386 ;
F_162 ( V_387 , V_77 ) ;
F_160 ( V_176 , & V_383 , V_379 , sizeof( int ) ) ;
if ( V_176 ) {
return - V_207 ;
}
if ( V_31 >= V_32 )
F_4 ( L_123 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_383 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_64 ( V_1 ) ;
V_380 = V_1 -> V_49 ;
V_382 = V_383 &
( ( ( V_380 & V_123 ) ? V_388 : V_389 ) +
( ( V_380 & V_124 ) ? V_390 : V_391 ) +
( ( V_380 & V_122 ) ? V_392 : V_393 ) +
( ( V_380 & V_125 ) ? V_394 : V_395 ) ) ;
if ( V_382 ) {
F_12 ( & V_1 -> V_42 , V_11 ) ;
goto exit;
}
V_381 = V_1 -> V_100 ;
V_385 = V_1 -> V_310 ;
if ( V_383 & ( V_396 + V_397 ) ) {
unsigned char V_398 = V_1 -> V_254 ;
unsigned char V_399 = V_398 +
( V_383 & V_396 ? V_255 : 0 ) +
( V_383 & V_397 ? V_256 : 0 ) ;
if ( V_398 != V_399 ) {
V_1 -> V_254 = V_399 ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
}
}
F_163 ( V_400 ) ;
F_164 ( & V_1 -> V_270 , & V_387 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
for(; ; ) {
F_165 () ;
if ( F_42 ( V_77 ) ) {
V_176 = - V_401 ;
break;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_102 = V_1 -> V_100 ;
V_386 = V_1 -> V_310 ;
F_163 ( V_400 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
if ( V_386 . V_313 == V_385 . V_313 &&
V_386 . V_314 == V_385 . V_314 &&
V_386 . V_317 == V_385 . V_317 &&
V_386 . V_318 == V_385 . V_318 &&
V_386 . V_319 == V_385 . V_319 &&
V_386 . V_320 == V_385 . V_320 &&
V_386 . V_311 == V_385 . V_311 &&
V_386 . V_312 == V_385 . V_312 &&
V_102 . V_268 == V_381 . V_268 &&
V_102 . V_269 == V_381 . V_269 ) {
V_176 = - V_63 ;
break;
}
V_382 = V_383 &
( ( V_386 . V_313 != V_385 . V_313 ? V_388 : 0 ) +
( V_386 . V_314 != V_385 . V_314 ? V_389 : 0 ) +
( V_386 . V_317 != V_385 . V_317 ? V_390 : 0 ) +
( V_386 . V_318 != V_385 . V_318 ? V_391 : 0 ) +
( V_386 . V_319 != V_385 . V_319 ? V_392 : 0 ) +
( V_386 . V_320 != V_385 . V_320 ? V_393 : 0 ) +
( V_386 . V_311 != V_385 . V_311 ? V_394 : 0 ) +
( V_386 . V_312 != V_385 . V_312 ? V_395 : 0 ) +
( V_102 . V_268 != V_381 . V_268 ? V_396 : 0 ) +
( V_102 . V_269 != V_381 . V_269 ? V_397 : 0 ) ) ;
if ( V_382 )
break;
V_381 = V_102 ;
V_385 = V_386 ;
}
F_166 ( & V_1 -> V_270 , & V_387 ) ;
F_163 ( V_402 ) ;
if ( V_383 & ( V_396 + V_397 ) ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( ! F_167 ( & V_1 -> V_270 ) ) {
V_1 -> V_254 &= ~ ( V_255 | V_256 ) ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
}
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
exit:
if ( V_176 == 0 )
F_168 ( V_176 , V_382 , V_379 ) ;
return V_176 ;
}
static int F_60 ( T_1 * V_1 , int V_82 )
{
unsigned long V_11 ;
int V_176 ;
struct V_101 V_381 , V_102 ;
F_162 ( V_387 , V_77 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_381 = V_1 -> V_100 ;
F_164 ( & V_1 -> V_321 , & V_387 ) ;
F_163 ( V_400 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
for(; ; ) {
F_165 () ;
if ( F_42 ( V_77 ) ) {
V_176 = - V_401 ;
break;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_102 = V_1 -> V_100 ;
F_163 ( V_400 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
if ( V_102 . V_105 == V_381 . V_105 && V_102 . V_104 == V_381 . V_104 &&
V_102 . V_106 == V_381 . V_106 && V_102 . V_103 == V_381 . V_103 ) {
V_176 = - V_63 ;
break;
}
if ( ( V_82 & V_403 && V_102 . V_105 != V_381 . V_105 ) ||
( V_82 & V_404 && V_102 . V_104 != V_381 . V_104 ) ||
( V_82 & V_405 && V_102 . V_106 != V_381 . V_106 ) ||
( V_82 & V_406 && V_102 . V_103 != V_381 . V_103 ) ) {
V_176 = 0 ;
break;
}
V_381 = V_102 ;
}
F_166 ( & V_1 -> V_321 , & V_387 ) ;
F_163 ( V_402 ) ;
return V_176 ;
}
static int F_169 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned int V_407 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_64 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_407 = ( ( V_1 -> V_49 & V_50 ) ? V_408 : 0 ) |
( ( V_1 -> V_49 & V_51 ) ? V_409 : 0 ) |
( ( V_1 -> V_49 & V_124 ) ? V_410 : 0 ) |
( ( V_1 -> V_49 & V_125 ) ? V_403 : 0 ) |
( ( V_1 -> V_49 & V_123 ) ? V_404 : 0 ) |
( ( V_1 -> V_49 & V_122 ) ? V_406 : 0 ) ;
if ( V_31 >= V_32 )
F_4 ( L_124 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_407 ) ;
return V_407 ;
}
static int F_170 ( struct V_8 * V_9 ,
unsigned int V_411 , unsigned int V_412 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_125 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_411 , V_412 ) ;
if ( V_411 & V_408 )
V_1 -> V_49 |= V_50 ;
if ( V_411 & V_409 )
V_1 -> V_49 |= V_51 ;
if ( V_412 & V_408 )
V_1 -> V_49 &= ~ V_50 ;
if ( V_412 & V_409 )
V_1 -> V_49 &= ~ V_51 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_29 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return 0 ;
}
static int F_171 ( struct V_413 * V_27 )
{
T_1 * V_1 = F_113 ( V_27 , T_1 , V_27 ) ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_64 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return ( V_1 -> V_49 & V_124 ) ? 1 : 0 ;
}
static void F_172 ( struct V_413 * V_27 , int V_414 )
{
T_1 * V_1 = F_113 ( V_27 , T_1 , V_27 ) ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
if ( V_414 )
V_1 -> V_49 |= V_50 | V_51 ;
else
V_1 -> V_49 &= ~ ( V_50 | V_51 ) ;
F_29 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
static int F_14 ( struct V_8 * V_9 , struct V_28 * V_29 ,
T_1 * V_1 )
{
F_162 ( V_387 , V_77 ) ;
int V_30 ;
bool V_415 = false ;
unsigned long V_11 ;
int V_416 ;
struct V_413 * V_27 = & V_1 -> V_27 ;
if ( V_31 >= V_32 )
F_4 ( L_126 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 ) ;
if ( V_29 -> V_417 & V_418 || V_9 -> V_11 & ( 1 << V_87 ) ) {
V_27 -> V_11 |= V_43 ;
return 0 ;
}
if ( F_173 ( V_9 ) )
V_415 = true ;
V_30 = 0 ;
F_164 ( & V_27 -> V_44 , & V_387 ) ;
if ( V_31 >= V_32 )
F_4 ( L_127 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_27 -> V_12 -- ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_27 -> V_419 ++ ;
while ( 1 ) {
if ( F_28 ( V_9 ) && F_31 ( V_74 , & V_27 -> V_11 ) )
F_174 ( V_27 ) ;
F_163 ( V_400 ) ;
if ( F_175 ( V_29 ) || ! ( V_27 -> V_11 & V_40 ) ) {
V_30 = ( V_27 -> V_11 & V_420 ) ?
- V_421 : - V_401 ;
break;
}
V_416 = F_176 ( V_27 ) ;
if ( V_415 || V_416 )
break;
if ( F_42 ( V_77 ) ) {
V_30 = - V_401 ;
break;
}
if ( V_31 >= V_32 )
F_4 ( L_128 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
F_177 ( V_9 ) ;
F_165 () ;
F_178 ( V_9 ) ;
}
F_163 ( V_402 ) ;
F_166 ( & V_27 -> V_44 , & V_387 ) ;
if ( ! F_175 ( V_29 ) )
V_27 -> V_12 ++ ;
V_27 -> V_419 -- ;
if ( V_31 >= V_32 )
F_4 ( L_129 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
if ( ! V_30 )
V_27 -> V_11 |= V_43 ;
return V_30 ;
}
static int F_179 ( T_1 * V_1 )
{
unsigned short V_422 ;
unsigned short V_423 ;
V_1 -> V_339 [ 0 ] -> V_424 = ( V_425 / 4 ) * V_1 -> V_245 ;
V_422 = ( unsigned short ) ( V_1 -> V_62 / V_426 ) ;
if ( V_1 -> V_62 % V_426 )
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
if ( F_180 ( V_1 ) < 0 ||
F_181 ( V_1 ,
V_1 -> V_432 ,
V_1 -> V_433 ,
V_1 -> V_431 ) < 0 ||
F_181 ( V_1 ,
V_1 -> V_434 ,
V_1 -> V_435 ,
V_1 -> V_429 ) < 0 ||
F_182 ( V_1 ) < 0 ) {
F_4 ( L_131 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_220 ;
}
F_183 ( V_1 ) ;
return 0 ;
}
static int F_180 ( T_1 * V_1 )
{
unsigned int V_333 ;
V_1 -> V_436 = V_1 -> V_437 + V_1 -> V_339 [ 0 ] -> V_424 ;
V_1 -> V_438 = V_1 -> V_339 [ 0 ] -> V_424 ;
V_1 -> V_339 [ 0 ] -> V_424 += V_427 ;
memset ( V_1 -> V_436 , 0 , V_427 ) ;
V_1 -> V_432 = ( V_428 * ) V_1 -> V_436 ;
V_1 -> V_434 = ( V_428 * ) V_1 -> V_436 ;
V_1 -> V_434 += V_1 -> V_431 ;
for ( V_333 = 0 ; V_333 < V_1 -> V_431 ; V_333 ++ ) {
V_1 -> V_433 [ V_333 ] . V_439 =
V_1 -> V_438 + ( V_333 * V_426 ) ;
V_1 -> V_432 [ V_333 ] . V_440 = V_1 -> V_438 ;
if ( V_333 < V_1 -> V_431 - 1 )
V_1 -> V_432 [ V_333 ] . V_440 += ( V_333 + 1 ) * sizeof( V_428 ) ;
V_1 -> V_432 [ V_333 ] . V_441 = V_426 ;
}
for ( V_333 = 0 ; V_333 < V_1 -> V_429 ; V_333 ++ ) {
V_1 -> V_435 [ V_333 ] . V_439 = V_1 -> V_438 +
( ( V_1 -> V_431 + V_333 ) * sizeof( V_428 ) ) ;
V_1 -> V_434 [ V_333 ] . V_440 = V_1 -> V_438 +
V_1 -> V_431 * sizeof( V_428 ) ;
if ( V_333 < V_1 -> V_429 - 1 )
V_1 -> V_434 [ V_333 ] . V_440 += ( V_333 + 1 ) * sizeof( V_428 ) ;
}
return 0 ;
}
static int F_181 ( T_1 * V_1 , V_428 * V_442 , T_10 * V_443 , int V_12 )
{
int V_333 ;
unsigned long V_444 ;
for ( V_333 = 0 ; V_333 < V_12 ; V_333 ++ ) {
V_443 [ V_333 ] . V_445 = V_1 -> V_437 + V_1 -> V_339 [ 0 ] -> V_424 ;
V_444 = V_1 -> V_339 [ 0 ] -> V_424 ;
V_1 -> V_339 [ 0 ] -> V_424 += V_426 ;
V_442 [ V_333 ] . V_446 = ( unsigned short ) V_444 ;
V_442 [ V_333 ] . V_447 = ( unsigned char ) ( V_444 >> 16 ) ;
}
return 0 ;
}
static void F_184 ( T_1 * V_1 )
{
V_1 -> V_436 = NULL ;
V_1 -> V_432 = NULL ;
V_1 -> V_434 = NULL ;
}
static int F_182 ( T_1 * V_1 )
{
V_1 -> V_448 = F_141 ( V_1 -> V_62 , V_347 ) ;
if ( V_1 -> V_448 == NULL )
return - V_220 ;
V_1 -> V_449 = F_185 ( V_1 -> V_62 , V_347 ) ;
if ( ! V_1 -> V_449 ) {
F_146 ( V_1 -> V_448 ) ;
V_1 -> V_448 = NULL ;
return - V_220 ;
}
return 0 ;
}
static void F_186 ( T_1 * V_1 )
{
F_146 ( V_1 -> V_448 ) ;
V_1 -> V_448 = NULL ;
F_146 ( V_1 -> V_449 ) ;
V_1 -> V_449 = NULL ;
}
static int F_187 ( T_1 * V_1 )
{
if ( F_188 ( V_1 -> V_118 , V_425 , L_132 ) == NULL ) {
F_4 ( L_133 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_118 ) ;
V_1 -> V_24 = V_450 ;
goto V_451;
}
else
V_1 -> V_452 = true ;
if ( F_188 ( V_1 -> V_120 + V_1 -> V_453 , 128 , L_132 ) == NULL ) {
F_4 ( L_134 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_120 ) ;
V_1 -> V_24 = V_450 ;
goto V_451;
}
else
V_1 -> V_454 = true ;
if ( F_188 ( V_1 -> V_117 + V_1 -> V_455 , V_223 , L_132 ) == NULL ) {
F_4 ( L_135 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_117 ) ;
V_1 -> V_24 = V_450 ;
goto V_451;
}
else
V_1 -> V_456 = true ;
if ( F_188 ( V_1 -> V_119 + V_1 -> V_457 , V_458 , L_132 ) == NULL ) {
F_4 ( L_136 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_119 ) ;
V_1 -> V_24 = V_450 ;
goto V_451;
}
else
V_1 -> V_459 = true ;
V_1 -> V_437 = F_189 ( V_1 -> V_118 ,
V_425 ) ;
if ( ! V_1 -> V_437 ) {
F_4 ( L_137 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_118 ) ;
V_1 -> V_24 = V_460 ;
goto V_451;
}
V_1 -> V_461 = F_189 ( V_1 -> V_120 , V_462 ) ;
if ( ! V_1 -> V_461 ) {
F_4 ( L_138 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_120 ) ;
V_1 -> V_24 = V_460 ;
goto V_451;
}
V_1 -> V_461 += V_1 -> V_453 ;
V_1 -> V_463 = F_189 ( V_1 -> V_117 , V_462 ) ;
if ( ! V_1 -> V_463 ) {
F_4 ( L_139 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_117 ) ;
V_1 -> V_24 = V_460 ;
goto V_451;
}
V_1 -> V_463 += V_1 -> V_455 ;
V_1 -> V_464 = F_189 ( V_1 -> V_119 ,
V_462 ) ;
if ( ! V_1 -> V_464 ) {
F_4 ( L_140 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_119 ) ;
V_1 -> V_24 = V_460 ;
goto V_451;
}
V_1 -> V_464 += V_1 -> V_457 ;
if ( ! F_190 ( V_1 ) ) {
F_4 ( L_141 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_118 ) ;
V_1 -> V_24 = V_465 ;
goto V_451;
}
return 0 ;
V_451:
F_191 ( V_1 ) ;
return - V_21 ;
}
static void F_191 ( T_1 * V_1 )
{
if ( V_31 >= V_32 )
F_4 ( L_142 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_1 -> V_466 ) {
F_192 ( V_1 -> V_121 , V_1 ) ;
V_1 -> V_466 = false ;
}
if ( V_1 -> V_452 ) {
F_193 ( V_1 -> V_118 , V_425 ) ;
V_1 -> V_452 = false ;
}
if ( V_1 -> V_454 ) {
F_193 ( V_1 -> V_120 + V_1 -> V_453 , 128 ) ;
V_1 -> V_454 = false ;
}
if ( V_1 -> V_456 ) {
F_193 ( V_1 -> V_117 + V_1 -> V_455 , V_223 ) ;
V_1 -> V_456 = false ;
}
if ( V_1 -> V_459 ) {
F_193 ( V_1 -> V_119 + V_1 -> V_457 , V_458 ) ;
V_1 -> V_459 = false ;
}
if ( V_1 -> V_437 ) {
F_194 ( V_1 -> V_437 ) ;
V_1 -> V_437 = NULL ;
}
if ( V_1 -> V_463 ) {
F_194 ( V_1 -> V_463 - V_1 -> V_455 ) ;
V_1 -> V_463 = NULL ;
}
if ( V_1 -> V_464 ) {
F_194 ( V_1 -> V_464 - V_1 -> V_457 ) ;
V_1 -> V_464 = NULL ;
}
if ( V_1 -> V_461 ) {
F_194 ( V_1 -> V_461 - V_1 -> V_453 ) ;
V_1 -> V_461 = NULL ;
}
if ( V_31 >= V_32 )
F_4 ( L_143 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static int F_195 ( T_1 * V_1 )
{
V_1 -> V_23 = NULL ;
V_1 -> line = V_20 ;
sprintf ( V_1 -> V_25 , L_144 , V_1 -> V_467 , V_1 -> V_245 ) ;
if ( V_1 -> line < V_468 ) {
if ( V_469 [ V_1 -> line ] )
V_1 -> V_62 = V_469 [ V_1 -> line ] ;
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
if ( V_1 -> V_62 < 4096 )
V_1 -> V_62 = 4096 ;
else if ( V_1 -> V_62 > 65535 )
V_1 -> V_62 = 65535 ;
F_4 ( L_145
L_146 ,
V_1 -> V_25 ,
V_1 -> V_117 ,
V_1 -> V_118 ,
V_1 -> V_119 ,
V_1 -> V_120 ,
V_1 -> V_121 ,
V_1 -> V_62 ) ;
#if V_300
return F_104 ( V_1 ) ;
#else
return 0 ;
#endif
}
static T_1 * F_196 ( int V_467 , int V_245 , struct V_471 * V_472 )
{
T_1 * V_1 ;
V_1 = F_185 ( sizeof( T_1 ) ,
V_347 ) ;
if ( ! V_1 ) {
F_4 ( L_147 ,
__FILE__ , __LINE__ , V_467 , V_245 ) ;
} else {
F_197 ( & V_1 -> V_27 ) ;
V_1 -> V_27 . V_15 = & V_473 ;
V_1 -> V_6 = V_7 ;
F_198 ( & V_1 -> V_237 , F_112 ) ;
V_1 -> V_62 = 4096 ;
V_1 -> V_27 . V_474 = 5 * V_228 / 10 ;
V_1 -> V_27 . V_475 = 30 * V_228 ;
F_199 ( & V_1 -> V_321 ) ;
F_199 ( & V_1 -> V_270 ) ;
F_200 ( & V_1 -> V_35 ) ;
memcpy ( & V_1 -> V_59 , & V_476 , sizeof( T_9 ) ) ;
V_1 -> V_375 = V_477 ;
V_1 -> V_467 = V_467 ;
V_1 -> V_245 = V_245 ;
V_1 -> V_121 = V_472 -> V_224 ;
V_1 -> V_120 = F_201 ( V_472 , 0 ) ;
V_1 -> V_117 = F_201 ( V_472 , 2 ) ;
V_1 -> V_118 = F_201 ( V_472 , 3 ) ;
V_1 -> V_119 = F_201 ( V_472 , 4 ) ;
V_1 -> V_453 = V_1 -> V_120 & ( V_462 - 1 ) ;
V_1 -> V_120 &= ~ ( V_462 - 1 ) ;
V_1 -> V_455 = V_1 -> V_117 & ( V_462 - 1 ) ;
V_1 -> V_117 &= ~ ( V_462 - 1 ) ;
V_1 -> V_457 = V_1 -> V_119 & ( V_462 - 1 ) ;
V_1 -> V_119 &= ~ ( V_462 - 1 ) ;
V_1 -> V_478 = V_479 ;
V_1 -> V_480 = V_481 ;
F_202 ( & V_1 -> V_80 , V_482 , ( unsigned long ) V_1 ) ;
F_202 ( & V_1 -> V_348 , V_483 ,
( unsigned long ) V_1 ) ;
V_1 -> V_484 = 0x087e4546 ;
V_1 -> V_24 = - 1 ;
}
return V_1 ;
}
static int F_203 ( int V_467 , struct V_471 * V_472 )
{
T_1 * V_339 [ V_485 ] ;
int V_27 , V_176 ;
for ( V_27 = 0 ; V_27 < V_485 ; ++ V_27 ) {
V_339 [ V_27 ] = F_196 ( V_467 , V_27 , V_472 ) ;
if( V_339 [ V_27 ] == NULL ) {
for ( -- V_27 ; V_27 >= 0 ; -- V_27 ) {
F_204 ( & V_339 [ V_27 ] -> V_27 ) ;
F_146 ( V_339 [ V_27 ] ) ;
}
return - V_220 ;
}
}
for ( V_27 = 0 ; V_27 < V_485 ; ++ V_27 ) {
memcpy ( V_339 [ V_27 ] -> V_339 , V_339 , sizeof( V_339 ) ) ;
V_176 = F_195 ( V_339 [ V_27 ] ) ;
if ( V_176 )
goto V_486;
F_200 ( & V_339 [ V_27 ] -> V_42 ) ;
}
if ( ! F_187 ( V_339 [ 0 ] ) ) {
F_179 ( V_339 [ 0 ] ) ;
for ( V_27 = 1 ; V_27 < V_485 ; ++ V_27 ) {
V_339 [ V_27 ] -> V_42 = V_339 [ 0 ] -> V_42 ;
V_339 [ V_27 ] -> V_121 = V_339 [ 0 ] -> V_121 ;
V_339 [ V_27 ] -> V_437 = V_339 [ 0 ] -> V_437 ;
V_339 [ V_27 ] -> V_463 = V_339 [ 0 ] -> V_463 ;
V_339 [ V_27 ] -> V_464 = V_339 [ 0 ] -> V_464 ;
V_339 [ V_27 ] -> V_461 = V_339 [ 0 ] -> V_461 ;
F_179 ( V_339 [ V_27 ] ) ;
}
V_176 = F_205 ( V_339 [ 0 ] -> V_121 ,
F_136 ,
V_339 [ 0 ] -> V_480 ,
V_339 [ 0 ] -> V_25 ,
V_339 [ 0 ] ) ;
if ( V_176 ) {
F_4 ( L_148 ,
__FILE__ , __LINE__ ,
V_339 [ 0 ] -> V_25 ,
V_339 [ 0 ] -> V_121 ) ;
goto V_487;
}
V_339 [ 0 ] -> V_466 = true ;
F_206 ( V_339 [ 0 ] ) ;
}
return 0 ;
V_487:
F_191 ( V_339 [ 0 ] ) ;
V_486:
for ( V_27 = 0 ; V_27 < V_485 ; ++ V_27 ) {
F_204 ( & V_339 [ V_27 ] -> V_27 ) ;
F_146 ( V_339 [ V_27 ] ) ;
}
return V_176 ;
}
static void F_207 ( void )
{
int V_176 ;
T_1 * V_1 ;
T_1 * V_334 ;
F_4 ( L_149 , V_488 , V_138 ) ;
if ( V_489 ) {
V_176 = F_208 ( V_489 ) ;
if ( V_176 )
F_4 ( L_150 ,
__FILE__ , __LINE__ , V_176 ) ;
F_209 ( V_489 ) ;
}
V_1 = V_22 ;
while( V_1 ) {
F_142 ( V_1 ) ;
V_1 = V_1 -> V_23 ;
}
V_1 = V_22 ;
while( V_1 ) {
#if V_300
F_109 ( V_1 ) ;
#endif
F_184 ( V_1 ) ;
F_186 ( V_1 ) ;
if ( V_1 -> V_245 == 0 ) {
if ( V_1 -> V_463 )
F_76 ( V_1 , V_490 , 1 ) ;
F_191 ( V_1 ) ;
}
V_334 = V_1 ;
V_1 = V_1 -> V_23 ;
F_204 ( & V_334 -> V_27 ) ;
F_146 ( V_334 ) ;
}
F_210 ( & V_491 ) ;
}
static int T_11 F_211 ( void )
{
int V_176 ;
if ( V_492 ) {
F_1 () ;
F_212 () ;
}
F_4 ( L_151 , V_488 , V_138 ) ;
if ( ( V_176 = F_213 ( & V_491 ) ) < 0 ) {
F_4 ( L_152 , __FILE__ , V_176 ) ;
return V_176 ;
}
V_489 = F_214 ( 128 ) ;
if ( ! V_489 ) {
V_176 = - V_220 ;
goto error;
}
V_489 -> V_488 = L_132 ;
V_489 -> V_2 = L_153 ;
V_489 -> V_493 = V_494 ;
V_489 -> V_495 = 64 ;
V_489 -> type = V_496 ;
V_489 -> V_497 = V_498 ;
V_489 -> V_499 = V_500 ;
V_489 -> V_499 . V_47 =
V_501 | V_359 | V_351 | V_350 | V_369 ;
V_489 -> V_499 . V_502 = 9600 ;
V_489 -> V_499 . V_503 = 9600 ;
V_489 -> V_11 = V_504 ;
F_215 ( V_489 , & V_15 ) ;
if ( ( V_176 = F_216 ( V_489 ) ) < 0 ) {
F_4 ( L_154 ,
__FILE__ , __LINE__ ) ;
F_209 ( V_489 ) ;
V_489 = NULL ;
goto error;
}
F_4 ( L_155 ,
V_488 , V_138 ,
V_489 -> V_493 ) ;
return 0 ;
error:
F_207 () ;
return V_176 ;
}
static void T_12 F_217 ( void )
{
F_207 () ;
}
static void F_218 ( T_1 * V_1 , int V_376 )
{
if ( V_376 ) {
F_76 ( V_1 , V_505 , ( unsigned char ) ( F_75 ( V_1 , V_505 ) | ( V_340 + V_274 ) ) ) ;
V_1 -> V_339 [ 0 ] -> V_506 |= ( V_274 << ( V_1 -> V_245 * 2 ) ) ;
F_219 ( V_1 ) ;
F_76 ( V_1 , V_507 , 0x40 ) ;
F_76 ( V_1 , V_508 , 0x40 ) ;
} else {
F_76 ( V_1 , V_505 , ( unsigned char ) ( F_75 ( V_1 , V_505 ) & ~ ( V_340 + V_274 ) ) ) ;
F_76 ( V_1 , V_507 , 0x00 ) ;
F_76 ( V_1 , V_508 , 0x00 ) ;
}
if ( V_1 -> V_59 . V_205 )
F_220 ( V_1 , V_1 -> V_59 . V_205 ) ;
else
F_220 ( V_1 , 3686400 ) ;
}
static void F_220 ( T_1 * V_1 , T_13 V_76 )
{
T_13 V_509 ;
unsigned char V_510 ;
T_13 V_511 = 0 ;
if ( V_76 != 0 ) {
V_511 = 14745600 / V_76 ;
if ( ! V_511 )
V_511 = 1 ;
V_509 = V_511 ;
V_510 = 0 ;
if ( V_509 != 1 && V_509 != 2 ) {
V_510 = 1 ;
V_509 >>= 1 ;
}
for(; V_509 > 256 && V_510 < 10 ; V_510 ++ )
V_509 >>= 1 ;
F_76 ( V_1 , V_508 ,
( unsigned char ) ( ( F_75 ( V_1 , V_508 ) & 0xf0 ) | V_510 ) ) ;
F_76 ( V_1 , V_507 ,
( unsigned char ) ( ( F_75 ( V_1 , V_507 ) & 0xf0 ) | V_510 ) ) ;
F_76 ( V_1 , V_512 , ( unsigned char ) V_509 ) ;
}
else {
F_76 ( V_1 , V_508 , 0 ) ;
F_76 ( V_1 , V_507 , 0 ) ;
F_76 ( V_1 , V_512 , 0 ) ;
}
}
static void F_148 ( T_1 * V_1 )
{
if ( V_31 >= V_251 )
F_4 ( L_156 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_76 ( V_1 , V_291 , V_513 ) ;
V_1 -> V_295 &= ~ V_514 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
F_76 ( V_1 , V_304 + V_287 , 0 ) ;
F_76 ( V_1 , V_304 + V_288 , V_289 ) ;
F_76 ( V_1 , V_304 + V_286 , 0 ) ;
V_1 -> V_378 = false ;
V_1 -> V_305 = false ;
}
static void F_151 ( T_1 * V_1 )
{
int V_333 ;
if ( V_31 >= V_251 )
F_4 ( L_157 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_76 ( V_1 , V_291 , V_513 ) ;
if ( V_1 -> V_59 . V_60 == V_61 ) {
V_1 -> V_295 &= ~ V_514 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
F_76 ( V_1 , V_304 + V_287 , 0 ) ;
F_76 ( V_1 , V_304 + V_288 , V_289 ) ;
for ( V_333 = 0 ; V_333 < V_1 -> V_431 ; V_333 ++ ) {
V_1 -> V_432 [ V_333 ] . V_252 = 0xff ;
if ( ! ( V_333 % 4 ) )
F_221 ( V_1 ) ;
}
V_1 -> V_515 = 0 ;
F_126 ( V_1 , V_304 + V_516 ,
V_1 -> V_433 [ 0 ] . V_439 ) ;
F_126 ( V_1 , V_304 + V_517 ,
V_1 -> V_433 [ V_1 -> V_431 - 1 ] . V_439 ) ;
F_126 ( V_1 , V_304 + V_518 , V_426 ) ;
F_76 ( V_1 , V_304 + V_286 , 0x60 ) ;
F_76 ( V_1 , V_304 + V_287 , 0xf2 ) ;
} else {
V_1 -> V_295 |= V_514 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
}
F_76 ( V_1 , V_291 , V_519 ) ;
V_1 -> V_305 = false ;
V_1 -> V_378 = true ;
}
static void F_37 ( T_1 * V_1 )
{
if ( V_31 >= V_251 )
F_4 ( L_158 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_65 ) ;
if ( ! V_1 -> V_71 ) {
F_76 ( V_1 , V_291 , V_292 ) ;
F_76 ( V_1 , V_291 , V_293 ) ;
V_1 -> V_71 = true ;
}
if ( V_1 -> V_65 ) {
V_1 -> V_299 = false ;
if ( V_1 -> V_59 . V_60 != V_263 ) {
if ( V_1 -> V_59 . V_11 & V_520 ) {
F_64 ( V_1 ) ;
if ( ! ( V_1 -> V_49 & V_50 ) ) {
V_1 -> V_49 |= V_50 ;
F_29 ( V_1 ) ;
V_1 -> V_299 = true ;
}
}
F_126 ( V_1 , V_307 ,
( unsigned short ) ( ( ( V_521 - 1 ) << 8 ) + V_522 ) ) ;
F_76 ( V_1 , V_285 + V_287 , 0 ) ;
F_76 ( V_1 , V_285 + V_288 , V_289 ) ;
F_126 ( V_1 , V_285 + V_516 ,
V_1 -> V_435 [ 0 ] . V_439 ) ;
F_126 ( V_1 , V_285 + V_517 ,
V_1 -> V_435 [ V_1 -> V_523 ] . V_439 ) ;
V_1 -> V_254 &= ~ V_297 ;
V_1 -> V_254 |= V_290 ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
F_76 ( V_1 , V_253 , ( unsigned char ) ( V_297 + V_290 ) ) ;
F_76 ( V_1 , V_285 + V_286 , 0x40 ) ;
F_76 ( V_1 , V_285 + V_287 , 0xf2 ) ;
F_143 ( & V_1 -> V_80 , V_75 +
F_144 ( 5000 ) ) ;
}
else {
F_129 ( V_1 ) ;
V_1 -> V_295 |= V_296 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
}
V_1 -> V_64 = true ;
}
}
static void F_49 ( T_1 * V_1 )
{
if ( V_31 >= V_251 )
F_4 ( L_159 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_46 ( & V_1 -> V_80 ) ;
F_76 ( V_1 , V_285 + V_287 , 0 ) ;
F_76 ( V_1 , V_285 + V_288 , V_289 ) ;
F_76 ( V_1 , V_291 , V_292 ) ;
V_1 -> V_254 &= ~ ( V_290 + V_297 ) ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
F_76 ( V_1 , V_253 , ( unsigned char ) ( V_297 + V_290 ) ) ;
V_1 -> V_295 &= ~ V_296 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
V_1 -> V_71 = false ;
V_1 -> V_64 = false ;
}
static void F_129 ( T_1 * V_1 )
{
T_14 V_524 [ 2 ] ;
if ( ! V_1 -> V_65 && ! V_1 -> V_70 )
return;
while( V_1 -> V_65 && ( F_75 ( V_1 , V_525 ) & V_340 ) ) {
if ( ( V_1 -> V_65 > 1 ) && ! V_1 -> V_70 ) {
V_524 [ 0 ] = V_1 -> V_58 [ V_1 -> V_79 ++ ] ;
if ( V_1 -> V_79 >= V_1 -> V_62 )
V_1 -> V_79 -= V_1 -> V_62 ;
V_524 [ 1 ] = V_1 -> V_58 [ V_1 -> V_79 ++ ] ;
if ( V_1 -> V_79 >= V_1 -> V_62 )
V_1 -> V_79 -= V_1 -> V_62 ;
F_126 ( V_1 , V_277 , * ( ( T_7 * ) V_524 ) ) ;
V_1 -> V_65 -= 2 ;
V_1 -> V_100 . V_108 += 2 ;
} else {
if ( V_1 -> V_70 ) {
F_76 ( V_1 , V_277 , V_1 -> V_70 ) ;
V_1 -> V_70 = 0 ;
} else {
F_76 ( V_1 , V_277 , V_1 -> V_58 [ V_1 -> V_79 ++ ] ) ;
if ( V_1 -> V_79 >= V_1 -> V_62 )
V_1 -> V_79 -= V_1 -> V_62 ;
V_1 -> V_65 -- ;
}
V_1 -> V_100 . V_108 ++ ;
}
}
}
static void F_142 ( T_1 * V_1 )
{
if ( V_1 -> V_463 ) {
F_49 ( V_1 ) ;
F_148 ( V_1 ) ;
V_1 -> V_49 &= ~ ( V_50 | V_51 ) ;
F_29 ( V_1 ) ;
V_1 -> V_295 = 0 ;
V_1 -> V_254 = 0 ;
V_1 -> V_261 = 0 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
F_76 ( V_1 , V_526 , V_1 -> V_261 ) ;
F_76 ( V_1 , V_291 , V_527 ) ;
}
}
static void F_222 ( T_1 * V_1 )
{
int V_333 ;
for ( V_333 = 0 ; V_333 < V_485 ; ++ V_333 ) {
if ( V_1 -> V_339 [ V_333 ] )
F_142 ( V_1 -> V_339 [ V_333 ] ) ;
}
}
static void F_150 ( T_1 * V_1 )
{
unsigned char V_141 ;
F_49 ( V_1 ) ;
F_148 ( V_1 ) ;
V_141 = 0x00 ;
if ( V_1 -> V_59 . V_361 != 1 )
V_141 |= V_340 ;
F_76 ( V_1 , V_528 , V_141 ) ;
V_141 = 0x40 ;
switch ( V_1 -> V_59 . V_356 ) {
case 7 : V_141 |= V_343 + V_341 ; break;
case 6 : V_141 |= V_342 + V_144 ; break;
case 5 : V_141 |= V_342 + V_343 + V_144 + V_341 ; break;
}
if ( V_1 -> V_59 . V_111 != V_362 ) {
V_141 |= V_340 ;
if ( V_1 -> V_59 . V_111 == V_365 )
V_141 |= V_274 ;
}
F_76 ( V_1 , V_529 , V_141 ) ;
V_141 = 0x00 ;
if ( V_1 -> V_59 . V_206 )
V_141 |= ( V_340 + V_274 ) ;
F_76 ( V_1 , V_505 , V_141 ) ;
V_141 = V_345 ;
F_76 ( V_1 , V_507 , V_141 ) ;
V_141 = V_345 ;
F_76 ( V_1 , V_508 , V_141 ) ;
V_1 -> V_339 [ 0 ] -> V_506 |= ( V_274 << ( V_1 -> V_245 * 2 ) ) ;
F_219 ( V_1 ) ;
F_161 ( V_1 ) ;
F_76 ( V_1 , V_530 , 0x00 ) ;
F_76 ( V_1 , V_307 , 0x10 ) ;
F_76 ( V_1 , V_531 , 0x1e ) ;
V_141 = 0x10 ;
if ( ! ( V_1 -> V_49 & V_50 ) )
V_141 |= 0x01 ;
F_76 ( V_1 , V_143 , V_141 ) ;
V_1 -> V_295 |= V_532 + V_533 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
V_1 -> V_254 = V_258 ;
F_76 ( V_1 , V_316 , V_1 -> V_254 ) ;
V_1 -> V_261 = V_262 ;
F_76 ( V_1 , V_526 , V_1 -> V_261 ) ;
F_220 ( V_1 , V_1 -> V_59 . V_76 * 16 ) ;
}
static void F_149 ( T_1 * V_1 )
{
unsigned char V_141 ;
T_13 V_534 ;
V_1 -> V_59 . V_11 &= ~ ( V_195 + V_191 ) ;
F_76 ( V_1 , V_285 + V_286 , 0 ) ;
F_76 ( V_1 , V_304 + V_286 , 0 ) ;
V_141 = 0x81 ;
if ( V_1 -> V_59 . V_11 & V_535 )
V_141 |= V_343 ;
if ( V_1 -> V_59 . V_11 & V_536 )
V_141 |= V_343 ;
if ( V_1 -> V_59 . V_166 == V_163 )
V_141 |= V_341 + V_340 ;
F_76 ( V_1 , V_528 , V_141 ) ;
V_141 = 0x00 ;
F_76 ( V_1 , V_529 , V_141 ) ;
V_141 = 0x00 ;
switch( V_1 -> V_59 . V_147 ) {
case V_537 : V_141 |= V_342 ; break;
case V_155 : V_141 |= V_344 + V_342 ; break;
case V_157 : V_141 |= V_344 + V_345 ; break;
case V_159 : V_141 |= V_344 ; break;
#if 0
case HDLC_ENCODING_NRZB:
case HDLC_ENCODING_NRZI_MARK:
case HDLC_ENCODING_DIFF_BIPHASE_LEVEL:
#endif
}
if ( V_1 -> V_59 . V_11 & V_538 ) {
V_534 = 16 ;
V_141 |= V_144 ;
} else if ( V_1 -> V_59 . V_11 & V_539 ) {
V_534 = 8 ;
} else {
V_534 = 32 ;
V_141 |= V_343 ;
}
F_76 ( V_1 , V_505 , V_141 ) ;
V_141 = 0 ;
if ( V_1 -> V_59 . V_11 & V_192 )
V_141 |= V_345 ;
if ( V_1 -> V_59 . V_11 & V_191 )
V_141 |= V_345 + V_342 ;
F_76 ( V_1 , V_507 , V_141 ) ;
V_141 = 0 ;
if ( V_1 -> V_59 . V_11 & V_196 )
V_141 |= V_345 ;
if ( V_1 -> V_59 . V_11 & V_195 )
V_141 |= V_345 + V_342 ;
F_76 ( V_1 , V_508 , V_141 ) ;
if ( V_1 -> V_59 . V_11 & V_191 )
F_220 ( V_1 , V_1 -> V_59 . V_205 * V_534 ) ;
else
F_220 ( V_1 , V_1 -> V_59 . V_205 ) ;
if ( V_1 -> V_59 . V_11 & V_196 )
V_1 -> V_339 [ 0 ] -> V_506 |= ( V_274 << ( V_1 -> V_245 * 2 ) ) ;
else
V_1 -> V_339 [ 0 ] -> V_506 &= ~ ( V_274 << ( V_1 -> V_245 * 2 ) ) ;
F_219 ( V_1 ) ;
F_76 ( V_1 , V_530 , V_540 ) ;
F_76 ( V_1 , V_307 , V_522 ) ;
F_76 ( V_1 , V_531 , ( unsigned char ) ( V_521 - 1 ) ) ;
F_76 ( V_1 , V_285 + V_541 , 0x14 ) ;
F_76 ( V_1 , V_304 + V_541 , 0x14 ) ;
F_76 ( V_1 , V_304 + V_542 ,
( unsigned char ) ( V_1 -> V_438 >> 16 ) ) ;
F_76 ( V_1 , V_285 + V_542 ,
( unsigned char ) ( V_1 -> V_438 >> 16 ) ) ;
V_1 -> V_295 |= V_532 + V_533 ;
F_76 ( V_1 , V_298 , V_1 -> V_295 ) ;
V_141 = 0x10 ;
if ( ! ( V_1 -> V_49 & V_50 ) )
V_141 |= 0x01 ;
F_76 ( V_1 , V_143 , V_141 ) ;
F_161 ( V_1 ) ;
F_49 ( V_1 ) ;
F_148 ( V_1 ) ;
F_220 ( V_1 , V_1 -> V_59 . V_205 ) ;
if ( V_1 -> V_59 . V_206 )
F_218 ( V_1 , 1 ) ;
}
static void F_161 ( T_1 * V_1 )
{
unsigned char V_141 = 0xff ;
switch( V_1 -> V_375 ) {
case V_477 : V_141 = 0x7e ; break;
case V_543 : V_141 = 0xaa ; break;
case V_544 : V_141 = 0x00 ; break;
case V_545 : V_141 = 0xff ; break;
case V_546 : V_141 = 0xaa ; break;
case V_547 : V_141 = 0x00 ; break;
case V_548 : V_141 = 0xff ; break;
}
F_76 ( V_1 , V_549 , V_141 ) ;
}
static void F_64 ( T_1 * V_1 )
{
T_7 V_252 = F_75 ( V_1 , V_550 ) ;
T_7 V_551 = F_221 ( V_1 ) ;
T_7 V_552 ;
V_1 -> V_49 &= V_50 | V_51 ;
if ( ! ( V_252 & V_144 ) )
V_1 -> V_49 |= V_122 ;
if ( ! ( V_252 & V_341 ) )
V_1 -> V_49 |= V_124 ;
V_552 = V_340 << ( V_1 -> V_245 * 2 ) ;
if ( ! ( V_551 & V_552 ) )
V_1 -> V_49 |= V_125 ;
V_552 = V_274 << ( V_1 -> V_245 * 2 ) ;
if ( ! ( V_551 & V_552 ) )
V_1 -> V_49 |= V_123 ;
}
static void F_29 ( T_1 * V_1 )
{
unsigned char V_141 ;
T_7 V_553 ;
V_141 = F_75 ( V_1 , V_143 ) ;
if ( V_1 -> V_49 & V_50 )
V_141 &= ~ V_274 ;
else
V_141 |= V_274 ;
F_76 ( V_1 , V_143 , V_141 ) ;
V_553 = V_340 << ( V_1 -> V_245 * 2 ) ;
if ( V_1 -> V_49 & V_51 )
V_1 -> V_339 [ 0 ] -> V_506 &= ~ V_553 ;
else
V_1 -> V_339 [ 0 ] -> V_506 |= V_553 ;
F_219 ( V_1 ) ;
}
static void F_183 ( T_1 * V_1 )
{
F_223 ( V_1 , 0 , V_1 -> V_431 - 1 ) ;
}
static void F_223 ( T_1 * V_1 , unsigned int V_554 , unsigned int V_555 )
{
bool V_556 = false ;
while( ! V_556 ) {
V_1 -> V_432 [ V_554 ] . V_252 = 0xff ;
if ( V_554 == V_555 ) {
V_556 = true ;
F_126 ( V_1 , V_304 + V_517 , V_1 -> V_433 [ V_554 ] . V_439 ) ;
}
V_554 ++ ;
if ( V_554 == V_1 -> V_431 )
V_554 = 0 ;
}
V_1 -> V_515 = V_554 ;
}
static bool F_117 ( T_1 * V_1 )
{
unsigned int V_557 , V_558 ;
unsigned short V_252 ;
unsigned int V_559 = 0 ;
bool V_560 = false ;
unsigned long V_11 ;
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
unsigned char V_561 = 0xff ;
V_428 * V_562 ;
T_10 * V_563 ;
V_564:
V_559 = 0 ;
V_561 = 0xff ;
V_557 = V_558 = V_1 -> V_515 ;
for ( ; ; ) {
V_562 = & V_1 -> V_432 [ V_558 ] ;
V_563 = & V_1 -> V_433 [ V_558 ] ;
if ( V_562 -> V_252 == 0xff )
goto V_565;
if ( V_559 == 0 && V_1 -> V_59 . V_566 != 0xff )
V_561 = V_563 -> V_445 [ 0 ] ;
V_559 += V_562 -> V_441 ;
if ( V_562 -> V_252 )
break;
V_558 ++ ;
if ( V_558 == V_1 -> V_431 )
V_558 = 0 ;
if ( V_558 == V_1 -> V_515 ) {
if ( V_1 -> V_378 ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_151 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
goto V_565;
}
}
V_252 = V_562 -> V_252 ;
if ( V_1 -> V_59 . V_166 == V_161 )
V_252 &= ~ V_341 ;
if ( V_559 == 0 ||
( V_561 != 0xff && V_561 != V_1 -> V_59 . V_566 ) ) {
F_223 ( V_1 , V_557 , V_558 ) ;
goto V_564;
}
if ( V_559 < 2 )
V_252 |= V_345 ;
if ( V_252 & ( V_345 + V_342 + V_144 + V_341 ) ) {
if ( V_252 & V_345 )
V_1 -> V_100 . V_130 ++ ;
else if ( V_252 & V_342 )
V_1 -> V_100 . V_567 ++ ;
else if ( V_252 & V_144 )
V_1 -> V_100 . V_132 ++ ;
else
V_1 -> V_100 . V_133 ++ ;
V_559 = 0 ;
#if V_300
{
V_1 -> V_212 -> V_171 . V_568 ++ ;
V_1 -> V_212 -> V_171 . V_569 ++ ;
}
#endif
}
if ( V_31 >= V_239 )
F_4 ( L_160 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_252 , V_559 ) ;
if ( V_31 >= V_570 )
F_224 ( V_1 , V_1 -> V_433 [ V_557 ] . V_445 ,
F_35 (unsigned int, framesize, SCABUFSIZE) , 0 ) ;
if ( V_559 ) {
if ( V_559 > V_1 -> V_62 )
V_1 -> V_100 . V_131 ++ ;
else {
int V_571 = V_559 ;
int V_19 = V_557 ;
unsigned char * V_572 = V_1 -> V_448 ;
V_1 -> V_573 = V_559 ;
V_1 -> V_100 . V_127 ++ ;
while( V_571 ) {
int V_574 = F_36 ( V_571 , V_426 ) ;
memcpy ( V_572 ,
V_1 -> V_433 [ V_19 ] . V_445 ,
V_574 ) ;
V_572 += V_574 ;
V_571 -= V_574 ;
if ( ++ V_19 == V_1 -> V_431 )
V_19 = 0 ;
}
#if V_300
if ( V_1 -> V_36 )
F_99 ( V_1 , V_1 -> V_448 , V_559 ) ;
else
#endif
F_5 ( V_9 , V_1 -> V_448 ,
V_1 -> V_449 , V_559 ) ;
}
}
F_223 ( V_1 , V_557 , V_558 ) ;
V_560 = true ;
V_565:
if ( V_1 -> V_378 && V_1 -> V_305 ) {
if ( V_1 -> V_432 [ V_558 ] . V_252 == 0xff ) {
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_151 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
}
}
return V_560 ;
}
static void F_34 ( T_1 * V_1 , const char * V_55 , unsigned int V_12 )
{
unsigned short V_571 ;
unsigned int V_333 = 0 ;
V_428 * V_562 ;
T_10 * V_563 ;
if ( V_31 >= V_570 )
F_224 ( V_1 , V_55 , F_35 (unsigned int, count, SCABUFSIZE) , 1 ) ;
for( V_333 = 0 ; ; )
{
V_571 = F_35 (unsigned int, count, SCABUFSIZE) ;
V_562 = & V_1 -> V_434 [ V_333 ] ;
V_563 = & V_1 -> V_435 [ V_333 ] ;
F_225 ( V_1 , V_563 -> V_445 , V_55 , V_571 ) ;
V_562 -> V_441 = V_571 ;
V_562 -> V_252 = 0 ;
V_55 += V_571 ;
V_12 -= V_571 ;
if ( ! V_12 )
break;
V_333 ++ ;
if ( V_333 >= V_1 -> V_429 )
V_333 = 0 ;
}
V_1 -> V_434 [ V_333 ] . V_252 = 0x81 ;
V_1 -> V_523 = ++ V_333 ;
}
static bool F_226 ( T_1 * V_1 )
{
static unsigned char V_575 [] = { 0x00 , 0xff , 0xaa , 0x55 , 0x69 , 0x96 } ;
static unsigned int V_12 = F_227 ( V_575 ) ;
unsigned int V_333 ;
bool V_176 = true ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_142 ( V_1 ) ;
V_1 -> V_24 = V_576 ;
for ( V_333 = 0 ; V_333 < V_12 ; V_333 ++ ) {
F_76 ( V_1 , V_512 , V_575 [ V_333 ] ) ;
F_76 ( V_1 , V_549 , V_575 [ ( V_333 + 1 ) % V_12 ] ) ;
F_76 ( V_1 , V_577 , V_575 [ ( V_333 + 2 ) % V_12 ] ) ;
F_76 ( V_1 , V_578 , V_575 [ ( V_333 + 3 ) % V_12 ] ) ;
if ( ( F_75 ( V_1 , V_512 ) != V_575 [ V_333 ] ) ||
( F_75 ( V_1 , V_549 ) != V_575 [ ( V_333 + 1 ) % V_12 ] ) ||
( F_75 ( V_1 , V_577 ) != V_575 [ ( V_333 + 2 ) % V_12 ] ) ||
( F_75 ( V_1 , V_578 ) != V_575 [ ( V_333 + 3 ) % V_12 ] ) )
{
V_176 = false ;
break;
}
}
F_142 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_176 ;
}
static bool F_228 ( T_1 * V_1 )
{
unsigned long V_41 ;
unsigned long V_11 ;
unsigned char V_244 = ( V_1 -> V_245 & 1 ) ? V_246 : V_247 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_142 ( V_1 ) ;
V_1 -> V_24 = V_579 ;
V_1 -> V_250 = false ;
F_76 ( V_1 , V_248 , ( unsigned char ) ( ( V_1 -> V_245 & 1 ) ? V_345 : V_343 ) ) ;
F_76 ( V_1 , ( unsigned char ) ( V_244 + V_580 ) , 0 ) ;
F_126 ( V_1 , ( unsigned char ) ( V_244 + V_581 ) , 1 ) ;
F_76 ( V_1 , ( unsigned char ) ( V_244 + V_249 ) , 0x50 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_41 = 100 ;
while( V_41 -- && ! V_1 -> V_250 ) {
F_40 ( 10 ) ;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_142 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
return V_1 -> V_250 ;
}
static bool F_229 ( T_1 * V_1 )
{
F_76 ( V_1 , V_582 , 0 ) ;
F_76 ( V_1 , V_583 , 0 ) ;
F_76 ( V_1 , V_584 , 0 ) ;
F_76 ( V_1 , V_585 , 0 ) ;
F_76 ( V_1 , V_586 , 0 ) ;
F_76 ( V_1 , V_587 , V_588 ) ;
F_76 ( V_1 , V_589 , 0x80 ) ;
F_76 ( V_1 , V_590 , 0xff ) ;
F_76 ( V_1 , V_591 , 0xff ) ;
F_76 ( V_1 , V_248 , 0xf0 ) ;
F_76 ( V_1 , V_592 , 0 ) ;
return true ;
}
static bool F_230 ( T_1 * V_1 )
{
int V_333 ;
volatile T_13 * V_593 = ( T_13 * ) ( V_1 -> V_461 + 0x50 ) ;
T_13 V_594 ;
V_1 -> V_484 |= V_595 ;
* V_593 = V_1 -> V_484 ;
for( V_333 = 0 ; V_333 < 10 ; V_333 ++ )
V_594 = * V_593 ;
V_1 -> V_484 &= ~ V_595 ;
* V_593 = V_1 -> V_484 ;
V_1 -> V_506 = 0xaa ;
F_219 ( V_1 ) ;
{
volatile T_13 * V_596 = ( T_13 * ) ( V_1 -> V_461 + 0x2c ) ;
V_597 &= ~ ( V_342 + V_343 + V_144 ) ;
switch( V_598 )
{
case 16 :
V_597 |= V_342 + V_343 + V_144 ;
break;
case 8 :
V_597 |= V_342 + V_343 ;
break;
case 4 :
V_597 |= V_342 + V_144 ;
break;
case 0 :
V_597 |= V_342 ;
break;
}
* V_596 = V_597 ;
* V_593 = V_484 ;
}
F_229 ( V_1 -> V_339 [ 0 ] ) ;
F_229 ( V_1 -> V_339 [ 2 ] ) ;
return true ;
}
static bool F_231 ( T_1 * V_1 )
{
#define F_232 20
unsigned long V_41 ;
T_7 V_12 = F_232 ;
unsigned char V_55 [ F_232 ] ;
bool V_176 = false ;
unsigned long V_11 ;
struct V_8 * V_599 = V_1 -> V_27 . V_9 ;
T_13 V_600 = V_1 -> V_59 . V_205 ;
V_1 -> V_59 . V_205 = 3686400 ;
V_1 -> V_27 . V_9 = NULL ;
V_1 -> V_24 = V_601 ;
for ( V_12 = 0 ; V_12 < F_232 ; ++ V_12 )
V_55 [ V_12 ] = ( unsigned char ) V_12 ;
memset ( V_1 -> V_448 , 0 , F_232 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_149 ( V_1 ) ;
F_218 ( V_1 , 1 ) ;
F_151 ( V_1 ) ;
V_1 -> V_65 = V_12 ;
F_34 ( V_1 , V_55 , V_12 ) ;
F_37 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
for ( V_41 = 100 ; V_41 ; -- V_41 ) {
F_40 ( 10 ) ;
if ( F_117 ( V_1 ) ) {
V_176 = true ;
break;
}
}
if ( V_176 &&
( V_1 -> V_573 != V_12 ||
memcmp ( V_55 , V_1 -> V_448 , V_12 ) ) ) {
V_176 = false ;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_222 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_59 . V_205 = V_600 ;
V_1 -> V_27 . V_9 = V_599 ;
return V_176 ;
}
static int F_206 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_161 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_230 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_339 [ 0 ] -> V_338 = 0 ;
if ( F_226 ( V_1 -> V_339 [ 0 ] ) &&
F_226 ( V_1 -> V_339 [ 1 ] ) ) {
V_1 -> V_339 [ 0 ] -> V_338 = 2 ;
if ( F_226 ( V_1 -> V_339 [ 2 ] ) &&
F_226 ( V_1 -> V_339 [ 3 ] ) )
V_1 -> V_339 [ 0 ] -> V_338 += 2 ;
}
else {
F_4 ( L_162 ,
__FILE__ , __LINE__ , V_1 -> V_25 , ( unsigned long ) ( V_1 -> V_117 ) ) ;
return - V_21 ;
}
if ( ! F_228 ( V_1 -> V_339 [ 0 ] ) ||
! F_228 ( V_1 -> V_339 [ 1 ] ) ||
( V_1 -> V_338 == 4 && ! F_228 ( V_1 -> V_339 [ 2 ] ) ) ||
( V_1 -> V_338 == 4 && ! F_228 ( V_1 -> V_339 [ 3 ] ) ) ) {
F_4 ( L_163 ,
__FILE__ , __LINE__ , V_1 -> V_25 , ( unsigned short ) ( V_1 -> V_121 ) ) ;
return - V_21 ;
}
if ( ! F_231 ( V_1 -> V_339 [ 0 ] ) ||
! F_231 ( V_1 -> V_339 [ 1 ] ) ||
( V_1 -> V_338 == 4 && ! F_231 ( V_1 -> V_339 [ 2 ] ) ) ||
( V_1 -> V_338 == 4 && ! F_231 ( V_1 -> V_339 [ 3 ] ) ) ) {
F_4 ( L_164 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_21 ;
}
if ( V_31 >= V_32 )
F_4 ( L_165 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_339 [ 0 ] -> V_24 = 0 ;
V_1 -> V_339 [ 1 ] -> V_24 = 0 ;
if ( V_1 -> V_338 > 2 ) {
V_1 -> V_339 [ 2 ] -> V_24 = 0 ;
V_1 -> V_339 [ 3 ] -> V_24 = 0 ;
}
return 0 ;
}
static bool F_190 ( T_1 * V_1 )
{
static unsigned long V_575 [] = { 0x0 , 0x55555555 , 0xaaaaaaaa ,
0x66666666 , 0x99999999 , 0xffffffff , 0x12345678 } ;
unsigned long V_12 = F_227 ( V_575 ) ;
unsigned long V_333 ;
unsigned long V_602 = V_425 /sizeof( unsigned long ) ;
unsigned long * V_603 = ( unsigned long * ) V_1 -> V_437 ;
for ( V_333 = 0 ; V_333 < V_12 ; V_333 ++ ) {
* V_603 = V_575 [ V_333 ] ;
if ( * V_603 != V_575 [ V_333 ] )
return false ;
}
for ( V_333 = 0 ; V_333 < V_602 ; V_333 ++ ) {
* V_603 = V_333 * 4 ;
V_603 ++ ;
}
V_603 = ( unsigned long * ) V_1 -> V_437 ;
for ( V_333 = 0 ; V_333 < V_602 ; V_333 ++ ) {
if ( * V_603 != V_333 * 4 )
return false ;
V_603 ++ ;
}
memset ( V_1 -> V_437 , 0 , V_425 ) ;
return true ;
}
static void F_225 ( T_1 * V_1 , char * V_604 , const char * V_605 , unsigned short V_12 )
{
unsigned short V_606 = V_12 / V_607 ;
unsigned short V_333 ;
for ( V_333 = 0 ; V_333 < V_606 ; V_333 ++ )
{
memcpy ( V_604 , V_605 , V_607 ) ;
F_221 ( V_1 ) ;
V_604 += V_607 ;
V_605 += V_607 ;
}
memcpy ( V_604 , V_605 , V_12 % V_607 ) ;
}
static void F_224 ( T_1 * V_1 , const char * V_10 , int V_12 , int V_231 )
{
int V_333 ;
int V_608 ;
if ( V_231 )
F_4 ( L_166 , V_1 -> V_25 ) ;
else
F_4 ( L_167 , V_1 -> V_25 ) ;
while( V_12 ) {
if ( V_12 > 16 )
V_608 = 16 ;
else
V_608 = V_12 ;
for( V_333 = 0 ; V_333 < V_608 ; V_333 ++ )
F_4 ( L_168 , ( unsigned char ) V_10 [ V_333 ] ) ;
for(; V_333 < 17 ; V_333 ++ )
F_4 ( L_169 ) ;
for( V_333 = 0 ; V_333 < V_608 ; V_333 ++ ) {
if ( V_10 [ V_333 ] >= 040 && V_10 [ V_333 ] <= 0176 )
F_4 ( L_170 , V_10 [ V_333 ] ) ;
else
F_4 ( L_171 ) ;
}
F_4 ( L_172 ) ;
V_10 += V_608 ;
V_12 -= V_608 ;
}
}
static void V_482 ( unsigned long V_609 )
{
T_1 * V_1 = ( T_1 * ) V_609 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_173 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if( V_1 -> V_64 && V_1 -> V_59 . V_60 == V_61 ) {
V_1 -> V_100 . V_610 ++ ;
}
F_11 ( & V_1 -> V_42 , V_11 ) ;
V_1 -> V_64 = false ;
V_1 -> V_65 = V_1 -> V_67 = V_1 -> V_79 = 0 ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
#if V_300
if ( V_1 -> V_36 )
F_97 ( V_1 ) ;
else
#endif
F_115 ( V_1 ) ;
}
static void V_483 ( unsigned long V_609 )
{
T_7 V_252 = 0 ;
T_1 * V_1 = ( T_1 * ) V_609 ;
unsigned long V_11 ;
unsigned char V_611 ;
F_11 ( & V_1 -> V_42 , V_11 ) ;
F_64 ( V_1 ) ;
F_12 ( & V_1 -> V_42 , V_11 ) ;
V_611 = V_1 -> V_612 ^ V_1 -> V_49 ;
V_1 -> V_612 = V_1 -> V_49 ;
if ( V_611 & V_123 )
V_252 |= V_308 | ( V_1 -> V_49 & V_123 ) ;
if ( V_611 & V_125 )
V_252 |= V_309 | ( V_1 -> V_49 & V_125 ) ;
if ( V_611 & V_124 )
V_252 |= V_271 | ( V_1 -> V_49 & V_124 ) ;
if ( V_611 & V_122 )
V_252 |= V_302 | ( V_1 -> V_49 & V_122 ) ;
if ( V_252 )
F_122 ( V_1 , V_252 ) ;
F_143 ( & V_1 -> V_348 , V_75 + F_144 ( 10 ) ) ;
}
static unsigned char F_75 ( T_1 * V_1 , unsigned char V_613 )
{
F_233 () ;
return * V_614 ;
}
static void F_76 ( T_1 * V_1 , unsigned char V_613 , unsigned char V_615 )
{
F_233 () ;
* V_614 = V_615 ;
}
static T_7 F_138 ( T_1 * V_1 , unsigned char V_613 )
{
F_233 () ;
return * ( ( T_7 * ) V_614 ) ;
}
static void F_126 ( T_1 * V_1 , unsigned char V_613 , T_7 V_615 )
{
F_233 () ;
* ( ( T_7 * ) V_614 ) = V_615 ;
}
static unsigned char F_221 ( T_1 * V_1 )
{
unsigned char * V_614 = ( unsigned char * ) V_1 -> V_464 ;
return * V_614 ;
}
static void F_219 ( T_1 * V_1 )
{
unsigned char * V_614 = ( unsigned char * ) V_1 -> V_464 ;
* V_614 = V_1 -> V_339 [ 0 ] -> V_506 ;
}
static int F_234 ( struct V_471 * V_146 ,
const struct V_616 * V_617 )
{
if ( F_235 ( V_146 ) ) {
F_4 ( L_174 , V_146 ) ;
return - V_63 ;
}
return F_203 ( ++ V_618 , V_146 ) ;
}
static void F_236 ( struct V_471 * V_146 )
{
}
