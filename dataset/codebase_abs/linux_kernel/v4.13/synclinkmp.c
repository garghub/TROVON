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
if ( F_18 ( & V_1 -> V_27 ) )
F_19 ( V_9 , V_1 -> V_40 ) ;
F_20 ( V_9 ) ;
F_21 ( V_9 ) ;
F_22 ( V_1 ) ;
F_23 ( & V_1 -> V_27 . V_39 ) ;
F_24 ( & V_1 -> V_27 , V_9 ) ;
V_1 -> V_27 . V_9 = NULL ;
V_38:
if ( V_31 >= V_32 )
F_4 ( L_11 , __FILE__ , __LINE__ ,
V_9 -> V_18 -> V_2 , V_1 -> V_27 . V_12 ) ;
}
static void F_25 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_12 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_13 ) )
return;
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_20 ( V_9 ) ;
F_22 ( V_1 ) ;
F_11 ( & V_1 -> V_27 . V_41 , V_11 ) ;
V_1 -> V_27 . V_12 = 0 ;
V_1 -> V_27 . V_9 = NULL ;
F_12 ( & V_1 -> V_27 . V_41 , V_11 ) ;
F_26 ( & V_1 -> V_27 , 1 ) ;
F_23 ( & V_1 -> V_27 . V_39 ) ;
F_27 ( & V_1 -> V_27 . V_42 ) ;
}
static void F_28 ( struct V_8 * V_9 , struct V_43 * V_44 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_14 , __FILE__ , __LINE__ ,
V_9 -> V_18 -> V_2 ) ;
F_29 ( V_1 ) ;
if ( ( V_44 -> V_45 & V_46 ) && ! F_30 ( V_9 ) ) {
V_1 -> V_47 &= ~ ( V_48 | V_49 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_31 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
if ( ! ( V_44 -> V_45 & V_46 ) && F_30 ( V_9 ) ) {
V_1 -> V_47 |= V_49 ;
if ( ! F_32 ( V_9 ) || ! F_33 ( V_9 ) )
V_1 -> V_47 |= V_48 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_31 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
if ( V_44 -> V_45 & V_50 && ! F_32 ( V_9 ) ) {
V_9 -> V_51 = 0 ;
F_34 ( V_9 ) ;
}
}
static int F_35 ( struct V_8 * V_9 ,
const unsigned char * V_52 , int V_12 )
{
int V_53 , V_54 = 0 ;
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_15 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_12 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_16 ) )
goto V_38;
if ( ! V_1 -> V_55 )
goto V_38;
if ( V_1 -> V_56 . V_57 == V_58 ) {
if ( V_12 > V_1 -> V_59 ) {
V_54 = - V_60 ;
goto V_38;
}
if ( V_1 -> V_61 )
goto V_38;
if ( V_1 -> V_62 ) {
F_36 ( V_1 , V_1 -> V_55 , V_1 -> V_62 ) ;
goto V_63;
}
V_54 = V_1 -> V_62 = V_12 ;
F_36 ( V_1 , V_52 , V_12 ) ;
goto V_63;
}
for (; ; ) {
V_53 = F_37 ( int , V_12 ,
F_38 ( V_1 -> V_59 - V_1 -> V_62 - 1 ,
V_1 -> V_59 - V_1 -> V_64 ) ) ;
if ( V_53 <= 0 )
break;
memcpy ( V_1 -> V_55 + V_1 -> V_64 , V_52 , V_53 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_64 += V_53 ;
if ( V_1 -> V_64 >= V_1 -> V_59 )
V_1 -> V_64 -= V_1 -> V_59 ;
V_1 -> V_62 += V_53 ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
V_52 += V_53 ;
V_12 -= V_53 ;
V_54 += V_53 ;
}
if ( V_1 -> V_56 . V_57 == V_58 ) {
if ( V_12 ) {
V_54 = V_1 -> V_62 = 0 ;
goto V_38;
}
F_36 ( V_1 , V_1 -> V_55 , V_1 -> V_62 ) ;
}
V_63:
if ( V_1 -> V_62 && ! V_9 -> V_65 && ! V_9 -> V_51 ) {
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( ! V_1 -> V_61 )
F_39 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
V_38:
if ( V_31 >= V_32 )
F_4 ( L_17 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_54 ) ;
return V_54 ;
}
static int F_40 ( struct V_8 * V_9 , unsigned char V_66 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
int V_54 = 0 ;
if ( V_31 >= V_32 ) {
F_4 ( L_18 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_66 ) ;
}
if ( F_2 ( V_1 , V_9 -> V_2 , L_19 ) )
return 0 ;
if ( ! V_1 -> V_55 )
return 0 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( ( V_1 -> V_56 . V_57 != V_58 ) ||
! V_1 -> V_61 ) {
if ( V_1 -> V_62 < V_1 -> V_59 - 1 ) {
V_1 -> V_55 [ V_1 -> V_64 ++ ] = V_66 ;
if ( V_1 -> V_64 >= V_1 -> V_59 )
V_1 -> V_64 -= V_1 -> V_59 ;
V_1 -> V_62 ++ ;
V_54 = 1 ;
}
}
F_12 ( & V_1 -> V_41 , V_11 ) ;
return V_54 ;
}
static void F_41 ( struct V_8 * V_9 , char V_66 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_20 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_66 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_21 ) )
return;
V_1 -> V_67 = V_66 ;
if ( V_66 ) {
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( ! V_1 -> V_68 )
F_39 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
}
static void F_19 ( struct V_8 * V_9 , int V_40 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_69 , V_70 ;
if ( ! V_1 )
return;
if ( V_31 >= V_32 )
F_4 ( L_22 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_23 ) )
return;
if ( ! F_18 ( & V_1 -> V_27 ) )
goto exit;
V_69 = V_71 ;
if ( V_1 -> V_56 . V_72 ) {
V_70 = V_1 -> V_40 / ( 32 * 5 ) ;
if ( ! V_70 )
V_70 ++ ;
} else
V_70 = 1 ;
if ( V_40 )
V_70 = F_37 (unsigned long, char_time, timeout) ;
if ( V_1 -> V_56 . V_57 == V_58 ) {
while ( V_1 -> V_61 ) {
F_42 ( F_43 ( V_70 ) ) ;
if ( F_44 ( V_73 ) )
break;
if ( V_40 && F_45 ( V_71 , V_69 + V_40 ) )
break;
}
} else {
while ( V_1 -> V_61 && V_1 -> V_68 ) {
F_42 ( F_43 ( V_70 ) ) ;
if ( F_44 ( V_73 ) )
break;
if ( V_40 && F_45 ( V_71 , V_69 + V_40 ) )
break;
}
}
exit:
if ( V_31 >= V_32 )
F_4 ( L_24 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static int F_46 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
int V_54 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_25 ) )
return 0 ;
if ( V_1 -> V_56 . V_57 == V_58 ) {
V_54 = ( V_1 -> V_61 ) ? 0 : V_74 ;
} else {
V_54 = V_1 -> V_59 - V_1 -> V_62 - 1 ;
if ( V_54 < 0 )
V_54 = 0 ;
}
if ( V_31 >= V_32 )
F_4 ( L_26 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_54 ) ;
return V_54 ;
}
static void F_47 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_27 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_62 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_28 ) )
return;
if ( V_1 -> V_62 <= 0 || V_9 -> V_65 || V_9 -> V_51 ||
! V_1 -> V_55 )
return;
if ( V_31 >= V_32 )
F_4 ( L_29 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( ! V_1 -> V_61 ) {
if ( ( V_1 -> V_56 . V_57 == V_58 ) &&
V_1 -> V_62 ) {
F_36 ( V_1 ,
V_1 -> V_55 , V_1 -> V_62 ) ;
}
F_39 ( V_1 ) ;
}
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
static void F_20 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_30 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_31 ) )
return;
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_62 = V_1 -> V_64 = V_1 -> V_75 = 0 ;
F_48 ( & V_1 -> V_76 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
F_49 ( V_9 ) ;
}
static void F_50 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_32 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_33 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( V_1 -> V_68 )
F_51 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
static void F_34 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_34 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_35 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( ! V_1 -> V_68 )
F_39 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
static int F_52 ( struct V_8 * V_9 ,
unsigned int V_77 , unsigned long V_78 )
{
T_1 * V_1 = V_9 -> V_26 ;
void T_3 * V_79 = ( void T_3 * ) V_78 ;
if ( V_31 >= V_32 )
F_4 ( L_36 , __FILE__ , __LINE__ ,
V_1 -> V_25 , V_77 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_37 ) )
return - V_21 ;
if ( ( V_77 != V_80 ) && ( V_77 != V_81 ) &&
( V_77 != V_82 ) ) {
if ( F_53 ( V_9 ) )
return - V_60 ;
}
switch ( V_77 ) {
case V_83 :
return F_54 ( V_1 , V_79 ) ;
case V_84 :
return F_55 ( V_1 , V_79 ) ;
case V_85 :
return F_56 ( V_1 , V_79 ) ;
case V_86 :
return F_57 ( V_1 , ( int ) V_78 ) ;
case V_87 :
return F_58 ( V_1 , ( int ) V_78 ) ;
case V_88 :
return F_59 ( V_1 , ( int ) V_78 ) ;
case V_89 :
return F_60 ( V_1 ) ;
case V_90 :
return F_61 ( V_1 , V_79 ) ;
case V_91 :
return F_62 ( V_1 , V_79 ) ;
case V_92 :
return 0 ;
case V_82 :
return F_63 ( V_1 , ( int ) V_78 ) ;
default:
return - V_93 ;
}
return 0 ;
}
static int F_64 ( struct V_8 * V_9 ,
struct V_94 * V_95 )
{
T_1 * V_1 = V_9 -> V_26 ;
struct V_96 V_97 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_97 = V_1 -> V_95 ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
V_95 -> V_98 = V_97 . V_98 ;
V_95 -> V_99 = V_97 . V_99 ;
V_95 -> V_100 = V_97 . V_100 ;
V_95 -> V_101 = V_97 . V_101 ;
V_95 -> V_102 = V_97 . V_102 ;
V_95 -> V_103 = V_97 . V_103 ;
V_95 -> V_104 = V_97 . V_104 ;
V_95 -> V_105 = V_97 . V_105 ;
V_95 -> V_106 = V_97 . V_106 ;
V_95 -> V_107 = V_97 . V_107 ;
V_95 -> V_108 = V_97 . V_108 ;
return 0 ;
}
static inline void F_65 ( struct V_109 * V_110 , T_1 * V_1 )
{
char V_111 [ 30 ] ;
unsigned long V_11 ;
F_66 ( V_110 , L_38
L_39 ,
V_1 -> V_25 ,
V_1 -> V_112 ,
V_1 -> V_113 ,
V_1 -> V_114 ,
V_1 -> V_115 ,
V_1 -> V_116 ,
V_1 -> V_59 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_67 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
V_111 [ 0 ] = 0 ;
V_111 [ 1 ] = 0 ;
if ( V_1 -> V_47 & V_48 )
strcat ( V_111 , L_40 ) ;
if ( V_1 -> V_47 & V_117 )
strcat ( V_111 , L_41 ) ;
if ( V_1 -> V_47 & V_49 )
strcat ( V_111 , L_42 ) ;
if ( V_1 -> V_47 & V_118 )
strcat ( V_111 , L_43 ) ;
if ( V_1 -> V_47 & V_119 )
strcat ( V_111 , L_44 ) ;
if ( V_1 -> V_47 & V_120 )
strcat ( V_111 , L_45 ) ;
if ( V_1 -> V_56 . V_57 == V_58 ) {
F_66 ( V_110 , L_46 ,
V_1 -> V_95 . V_121 , V_1 -> V_95 . V_122 ) ;
if ( V_1 -> V_95 . V_123 )
F_66 ( V_110 , L_47 , V_1 -> V_95 . V_123 ) ;
if ( V_1 -> V_95 . V_124 )
F_66 ( V_110 , L_48 , V_1 -> V_95 . V_124 ) ;
if ( V_1 -> V_95 . V_125 )
F_66 ( V_110 , L_49 , V_1 -> V_95 . V_125 ) ;
if ( V_1 -> V_95 . V_126 )
F_66 ( V_110 , L_50 , V_1 -> V_95 . V_126 ) ;
if ( V_1 -> V_95 . V_127 )
F_66 ( V_110 , L_51 , V_1 -> V_95 . V_127 ) ;
if ( V_1 -> V_95 . V_128 )
F_66 ( V_110 , L_50 , V_1 -> V_95 . V_128 ) ;
} else {
F_66 ( V_110 , L_52 ,
V_1 -> V_95 . V_103 , V_1 -> V_95 . V_102 ) ;
if ( V_1 -> V_95 . V_104 )
F_66 ( V_110 , L_53 , V_1 -> V_95 . V_104 ) ;
if ( V_1 -> V_95 . V_106 )
F_66 ( V_110 , L_54 , V_1 -> V_95 . V_106 ) ;
if ( V_1 -> V_95 . V_107 )
F_66 ( V_110 , L_55 , V_1 -> V_95 . V_107 ) ;
if ( V_1 -> V_95 . V_105 )
F_66 ( V_110 , L_56 , V_1 -> V_95 . V_105 ) ;
}
F_66 ( V_110 , L_57 , V_111 + 1 ) ;
F_66 ( V_110 , L_58 ,
V_1 -> V_61 , V_1 -> V_129 , V_1 -> V_130 ,
V_1 -> V_131 ) ;
}
static int F_68 ( struct V_109 * V_110 , void * V_132 )
{
T_1 * V_1 ;
F_66 ( V_110 , L_59 , V_133 ) ;
V_1 = V_22 ;
while( V_1 ) {
F_65 ( V_110 , V_1 ) ;
V_1 = V_1 -> V_23 ;
}
return 0 ;
}
static int F_69 ( struct V_134 * V_134 , struct V_28 * V_28 )
{
return F_70 ( V_28 , F_68 , NULL ) ;
}
static int F_71 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_60 ) )
return 0 ;
if ( V_31 >= V_32 )
F_4 ( L_61 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_62 ) ;
return V_1 -> V_62 ;
}
static void F_72 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_63 ) )
return;
if ( F_73 ( V_9 ) )
F_41 ( V_9 , F_74 ( V_9 ) ) ;
if ( F_32 ( V_9 ) ) {
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_47 &= ~ V_48 ;
F_31 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
}
static void F_75 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_64 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_65 ) )
return;
if ( F_73 ( V_9 ) ) {
if ( V_1 -> V_67 )
V_1 -> V_67 = 0 ;
else
F_41 ( V_9 , F_76 ( V_9 ) ) ;
}
if ( F_32 ( V_9 ) ) {
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_47 |= V_48 ;
F_31 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
}
static int F_77 ( struct V_8 * V_9 , int V_135 )
{
unsigned char V_136 ;
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_66 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_135 ) ;
if ( F_2 ( V_1 , V_9 -> V_2 , L_67 ) )
return - V_137 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_136 = F_78 ( V_1 , V_138 ) ;
if ( V_135 == - 1 )
V_136 |= V_139 ;
else
V_136 &= ~ V_139 ;
F_79 ( V_1 , V_138 , V_136 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
return 0 ;
}
static int F_80 ( struct V_140 * V_141 , unsigned short V_142 ,
unsigned short V_106 )
{
T_1 * V_1 = F_81 ( V_141 ) ;
unsigned char V_143 ;
unsigned short V_144 ;
if ( V_1 -> V_27 . V_12 )
return - V_37 ;
switch ( V_142 )
{
case V_145 : V_143 = V_146 ; break;
case V_147 : V_143 = V_148 ; break;
case V_149 : V_143 = V_150 ; break;
case V_151 : V_143 = V_152 ; break;
case V_153 : V_143 = V_154 ; break;
default: return - V_137 ;
}
switch ( V_106 )
{
case V_155 : V_144 = V_156 ; break;
case V_157 : V_144 = V_158 ; break;
case V_159 : V_144 = V_160 ; break;
default: return - V_137 ;
}
V_1 -> V_56 . V_142 = V_143 ;
V_1 -> V_56 . V_161 = V_144 ;
if ( V_1 -> V_36 )
F_82 ( V_1 ) ;
return 0 ;
}
static T_4 F_83 ( struct V_162 * V_163 ,
struct V_140 * V_141 )
{
T_1 * V_1 = F_81 ( V_141 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( V_164 L_68 , __FILE__ , V_141 -> V_2 ) ;
F_84 ( V_141 ) ;
V_1 -> V_62 = V_163 -> V_165 ;
F_36 ( V_1 , V_163 -> V_10 , V_163 -> V_165 ) ;
V_141 -> V_166 . V_167 ++ ;
V_141 -> V_166 . V_168 += V_163 -> V_165 ;
F_85 ( V_163 ) ;
F_86 ( V_141 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( ! V_1 -> V_61 )
F_39 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
return V_169 ;
}
static int F_87 ( struct V_140 * V_141 )
{
T_1 * V_1 = F_81 ( V_141 ) ;
int V_170 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_69 , __FILE__ , V_141 -> V_2 ) ;
V_170 = F_88 ( V_141 ) ;
if ( V_170 )
return V_170 ;
F_11 ( & V_1 -> V_35 , V_11 ) ;
if ( V_1 -> V_27 . V_12 != 0 || V_1 -> V_36 != 0 ) {
F_4 ( V_171 L_70 , V_141 -> V_2 ) ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
return - V_37 ;
}
V_1 -> V_36 = 1 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
if ( ( V_170 = F_13 ( V_1 ) ) != 0 ) {
F_11 ( & V_1 -> V_35 , V_11 ) ;
V_1 -> V_36 = 0 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
return V_170 ;
}
V_1 -> V_47 |= V_48 | V_49 ;
F_82 ( V_1 ) ;
F_86 ( V_141 ) ;
F_89 ( V_141 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_67 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
if ( V_1 -> V_47 & V_119 )
F_90 ( V_141 ) ;
else
F_91 ( V_141 ) ;
return 0 ;
}
static int F_92 ( struct V_140 * V_141 )
{
T_1 * V_1 = F_81 ( V_141 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_71 , __FILE__ , V_141 -> V_2 ) ;
F_84 ( V_141 ) ;
F_22 ( V_1 ) ;
F_93 ( V_141 ) ;
F_11 ( & V_1 -> V_35 , V_11 ) ;
V_1 -> V_36 = 0 ;
F_12 ( & V_1 -> V_35 , V_11 ) ;
return 0 ;
}
static int F_94 ( struct V_140 * V_141 , struct V_172 * V_173 , int V_77 )
{
const T_5 V_174 = sizeof( V_175 ) ;
V_175 V_176 ;
V_175 T_3 * line = V_173 -> V_177 . V_178 . V_179 ;
T_1 * V_1 = F_81 ( V_141 ) ;
unsigned int V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_72 , __FILE__ , V_141 -> V_2 ) ;
if ( V_1 -> V_27 . V_12 )
return - V_37 ;
if ( V_77 != V_180 )
return F_95 ( V_141 , V_173 , V_77 ) ;
switch( V_173 -> V_177 . type ) {
case V_181 :
V_173 -> V_177 . type = V_182 ;
if ( V_173 -> V_177 . V_174 < V_174 ) {
V_173 -> V_177 . V_174 = V_174 ;
return - V_183 ;
}
V_11 = V_1 -> V_56 . V_11 & ( V_184 | V_185 |
V_186 | V_187 |
V_188 | V_189 |
V_190 | V_191 ) ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
switch ( V_11 ) {
case ( V_184 | V_188 ) : V_176 . V_192 = V_193 ; break;
case ( V_186 | V_190 ) : V_176 . V_192 = V_194 ; break;
case ( V_184 | V_190 ) : V_176 . V_192 = V_195 ; break;
case ( V_184 | V_191 ) : V_176 . V_192 = V_196 ; break;
default: V_176 . V_192 = V_197 ;
}
V_176 . V_198 = V_1 -> V_56 . V_199 ;
V_176 . V_200 = V_1 -> V_56 . V_200 ? 1 : 0 ;
if ( F_96 ( line , & V_176 , V_174 ) )
return - V_201 ;
return 0 ;
case V_182 :
if( ! F_97 ( V_202 ) )
return - V_203 ;
if ( F_98 ( & V_176 , line , V_174 ) )
return - V_201 ;
switch ( V_176 . V_192 )
{
case V_193 : V_11 = V_184 | V_188 ; break;
case V_196 : V_11 = V_184 | V_191 ; break;
case V_194 : V_11 = V_186 | V_190 ; break;
case V_195 : V_11 = V_184 | V_190 ; break;
case V_197 : V_11 = V_1 -> V_56 . V_11 &
( V_184 | V_185 |
V_186 | V_187 |
V_188 | V_189 |
V_190 | V_191 ) ; break;
default: return - V_137 ;
}
if ( V_176 . V_200 != 0 && V_176 . V_200 != 1 )
return - V_137 ;
V_1 -> V_56 . V_11 &= ~ ( V_184 | V_185 |
V_186 | V_187 |
V_188 | V_189 |
V_190 | V_191 ) ;
V_1 -> V_56 . V_11 |= V_11 ;
V_1 -> V_56 . V_200 = V_176 . V_200 ;
if ( V_11 & ( V_186 | V_190 ) )
V_1 -> V_56 . V_199 = V_176 . V_198 ;
else
V_1 -> V_56 . V_199 = 0 ;
if ( V_1 -> V_36 )
F_82 ( V_1 ) ;
return 0 ;
default:
return F_95 ( V_141 , V_173 , V_77 ) ;
}
}
static void F_99 ( struct V_140 * V_141 )
{
T_1 * V_1 = F_81 ( V_141 ) ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_73 , V_141 -> V_2 ) ;
V_141 -> V_166 . V_204 ++ ;
V_141 -> V_166 . V_205 ++ ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_51 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
F_100 ( V_141 ) ;
}
static void F_101 ( T_1 * V_1 )
{
if ( F_102 ( V_1 -> V_206 ) )
F_100 ( V_1 -> V_206 ) ;
}
static void F_103 ( T_1 * V_1 , char * V_52 , int V_174 )
{
struct V_162 * V_163 = F_104 ( V_174 ) ;
struct V_140 * V_141 = V_1 -> V_206 ;
if ( V_31 >= V_32 )
F_4 ( L_74 , V_141 -> V_2 ) ;
if ( V_163 == NULL ) {
F_4 ( V_207 L_75 ,
V_141 -> V_2 ) ;
V_141 -> V_166 . V_208 ++ ;
return;
}
F_105 ( V_163 , V_52 , V_174 ) ;
V_163 -> V_209 = F_106 ( V_163 , V_141 ) ;
V_141 -> V_166 . V_210 ++ ;
V_141 -> V_166 . V_211 += V_174 ;
F_107 ( V_163 ) ;
}
static int F_108 ( T_1 * V_1 )
{
int V_170 ;
struct V_140 * V_141 ;
T_6 * V_212 ;
V_141 = F_109 ( V_1 ) ;
if ( ! V_141 ) {
F_4 ( V_213 L_76 , __FILE__ ) ;
return - V_214 ;
}
V_141 -> V_215 = V_1 -> V_112 ;
V_141 -> V_216 = V_1 -> V_112 + V_217 - 1 ;
V_141 -> V_218 = V_1 -> V_116 ;
V_141 -> V_219 = & V_220 ;
V_141 -> V_221 = 10 * V_222 ;
V_141 -> V_223 = 50 ;
V_212 = F_110 ( V_141 ) ;
V_212 -> V_224 = F_80 ;
V_212 -> V_225 = F_83 ;
V_170 = F_111 ( V_141 ) ;
if ( V_170 ) {
F_4 ( V_171 L_77 , __FILE__ ) ;
F_112 ( V_141 ) ;
return V_170 ;
}
V_1 -> V_206 = V_141 ;
return 0 ;
}
static void F_113 ( T_1 * V_1 )
{
F_114 ( V_1 -> V_206 ) ;
F_112 ( V_1 -> V_206 ) ;
V_1 -> V_206 = NULL ;
}
static int F_115 ( T_1 * V_1 )
{
unsigned long V_11 ;
int V_170 = 0 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( V_1 -> V_131 & V_226 ) {
V_1 -> V_131 &= ~ V_226 ;
V_170 = V_226 ;
} else if ( V_1 -> V_131 & V_227 ) {
V_1 -> V_131 &= ~ V_227 ;
V_170 = V_227 ;
} else if ( V_1 -> V_131 & V_228 ) {
V_1 -> V_131 &= ~ V_228 ;
V_170 = V_228 ;
}
if ( ! V_170 ) {
V_1 -> V_130 = false ;
V_1 -> V_129 = false ;
}
F_12 ( & V_1 -> V_41 , V_11 ) ;
return V_170 ;
}
static void F_116 ( struct V_229 * V_230 )
{
T_1 * V_1 = F_117 ( V_230 , T_1 , V_231 ) ;
int V_232 ;
if ( V_31 >= V_233 )
F_4 ( L_78 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_130 = true ;
while( ( V_232 = F_115 ( V_1 ) ) != 0 ) {
if ( V_31 >= V_233 )
F_4 ( L_79 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_232 ) ;
switch ( V_232 ) {
case V_226 :
F_118 ( V_1 ) ;
break;
case V_227 :
F_119 ( V_1 ) ;
break;
case V_228 :
F_120 ( V_1 ) ;
break;
default:
F_4 ( L_80 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_232 ) ;
break;
}
}
if ( V_31 >= V_233 )
F_4 ( L_81 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_118 ( T_1 * V_1 )
{
if ( V_31 >= V_233 )
F_4 ( L_82 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
while( F_121 ( V_1 ) ) ;
}
static void F_119 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
if ( V_31 >= V_233 )
F_4 ( L_83 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_9 )
F_49 ( V_9 ) ;
}
static void F_120 ( T_1 * V_1 )
{
if ( V_31 >= V_233 )
F_4 ( L_84 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_234 = 0 ;
V_1 -> V_235 = 0 ;
V_1 -> V_236 = 0 ;
V_1 -> V_237 = 0 ;
}
static void F_122 ( T_1 * V_1 )
{
unsigned char V_238 = ( V_1 -> V_239 & 1 ) ? V_240 : V_241 ;
F_79 ( V_1 , V_242 , 0 ) ;
F_79 ( V_1 , ( unsigned char ) ( V_238 + V_243 ) , 0 ) ;
V_1 -> V_244 = true ;
if ( V_31 >= V_245 )
F_4 ( L_85 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static void F_123 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
struct V_96 * V_95 = & V_1 -> V_95 ;
unsigned char V_246 = F_78 ( V_1 , V_247 ) & V_1 -> V_248 & ( V_249 + V_250 + V_251 + V_252 ) ;
unsigned char V_253 = F_78 ( V_1 , V_254 ) & V_1 -> V_255 & V_256 ;
if ( V_246 )
F_79 ( V_1 , V_247 , V_246 ) ;
if ( V_253 )
F_79 ( V_1 , V_254 , V_253 ) ;
if ( V_31 >= V_245 )
F_4 ( L_86 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_246 , V_253 ) ;
if ( V_1 -> V_56 . V_57 == V_257 ) {
if ( V_246 & V_252 ) {
V_95 -> V_107 ++ ;
if ( ! ( V_246 & V_1 -> V_258 ) ) {
if ( V_1 -> V_259 & V_252 ) {
F_124 ( & V_1 -> V_27 , 0 , V_260 ) ;
if ( V_9 && ( V_1 -> V_27 . V_11 & V_261 ) )
F_125 ( V_9 ) ;
}
}
}
}
else {
if ( V_246 & ( V_249 | V_250 ) ) {
if ( V_246 & V_249 )
V_1 -> V_95 . V_262 ++ ;
else if ( V_246 & V_250 )
V_1 -> V_95 . V_263 ++ ;
F_27 ( & V_1 -> V_264 ) ;
}
}
if ( V_246 & V_251 ) {
F_67 ( V_1 ) ;
F_126 ( V_1 ,
V_265 | ( V_1 -> V_47 & V_119 ) ) ;
}
}
static void F_127 ( T_1 * V_1 )
{
T_7 V_246 ;
unsigned char V_266 ;
struct V_96 * V_95 = & V_1 -> V_95 ;
if ( V_31 >= V_245 )
F_4 ( L_87 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
while( ( V_246 = F_78 ( V_1 , V_267 ) ) & V_268 )
{
int V_269 = 0 ;
bool V_270 = false ;
V_266 = F_78 ( V_1 , V_271 ) ;
V_95 -> V_102 ++ ;
if ( V_246 & ( V_272 + V_273 + V_256 ) ) {
F_4 ( L_88 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_246 ) ;
if ( V_246 & V_272 )
V_95 -> V_106 ++ ;
else if ( V_246 & V_273 )
V_95 -> V_104 ++ ;
else if ( V_246 & V_256 )
V_95 -> V_105 ++ ;
if ( V_246 & V_1 -> V_274 )
continue;
V_246 &= V_1 -> V_275 ;
if ( V_246 & V_272 )
V_269 = V_276 ;
else if ( V_246 & V_273 )
V_269 = V_277 ;
if ( V_246 & V_256 ) {
V_270 = true ;
}
}
F_124 ( & V_1 -> V_27 , V_266 , V_269 ) ;
if ( V_270 )
F_124 ( & V_1 -> V_27 , 0 , V_278 ) ;
}
if ( V_31 >= V_245 ) {
F_4 ( L_89 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_95 -> V_102 , V_95 -> V_107 , V_95 -> V_106 ,
V_95 -> V_104 , V_95 -> V_105 ) ;
}
F_128 ( & V_1 -> V_27 ) ;
}
static void F_129 ( T_1 * V_1 , unsigned char V_246 )
{
if ( V_31 >= V_245 )
F_4 ( L_90 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_246 ) ;
F_79 ( V_1 , V_279 + V_280 , 0x00 ) ;
F_79 ( V_1 , V_279 + V_281 , 0xc0 ) ;
F_79 ( V_1 , V_279 + V_282 , V_283 ) ;
if ( V_246 & V_284 ) {
F_79 ( V_1 , V_285 , V_286 ) ;
F_79 ( V_1 , V_285 , V_287 ) ;
} else
F_79 ( V_1 , V_285 , V_288 ) ;
V_1 -> V_289 &= ~ V_290 ;
V_1 -> V_248 &= ~ ( V_291 + V_284 ) ;
F_130 ( V_1 , V_292 , ( unsigned short ) ( ( V_1 -> V_248 << 8 ) + V_1 -> V_289 ) ) ;
F_79 ( V_1 , V_247 , ( unsigned char ) ( V_284 + V_291 ) ) ;
if ( V_1 -> V_61 ) {
if ( V_1 -> V_56 . V_57 != V_257 ) {
if ( V_246 & V_284 )
V_1 -> V_95 . V_123 ++ ;
else if ( V_246 & V_291 )
V_1 -> V_95 . V_121 ++ ;
}
V_1 -> V_61 = false ;
V_1 -> V_62 = V_1 -> V_64 = V_1 -> V_75 = 0 ;
F_48 ( & V_1 -> V_76 ) ;
if ( V_1 -> V_56 . V_57 != V_257 && V_1 -> V_293 ) {
V_1 -> V_47 &= ~ V_48 ;
V_1 -> V_293 = false ;
F_31 ( V_1 ) ;
}
#if V_294
if ( V_1 -> V_36 )
F_101 ( V_1 ) ;
else
#endif
{
if ( V_1 -> V_27 . V_9 && ( V_1 -> V_27 . V_9 -> V_65 || V_1 -> V_27 . V_9 -> V_51 ) ) {
F_51 ( V_1 ) ;
return;
}
V_1 -> V_131 |= V_227 ;
}
}
}
static void F_131 ( T_1 * V_1 )
{
unsigned char V_246 = F_78 ( V_1 , V_247 ) & V_1 -> V_248 & ( V_284 + V_291 + V_295 ) ;
F_79 ( V_1 , V_247 , V_246 ) ;
if ( V_31 >= V_245 )
F_4 ( L_91 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_246 ) ;
if ( V_246 & ( V_284 + V_291 ) )
F_129 ( V_1 , V_246 ) ;
if ( V_246 & V_295 ) {
F_67 ( V_1 ) ;
F_126 ( V_1 ,
V_296 | ( V_1 -> V_47 & V_117 ) ) ;
}
}
static void F_132 ( T_1 * V_1 )
{
if ( V_31 >= V_245 )
F_4 ( L_92 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_62 ) ;
if ( V_1 -> V_56 . V_57 != V_257 ) {
V_1 -> V_289 &= ~ V_290 ;
V_1 -> V_248 |= V_291 ;
F_130 ( V_1 , V_292 , ( unsigned short ) ( ( V_1 -> V_248 << 8 ) + V_1 -> V_289 ) ) ;
return;
}
if ( V_1 -> V_27 . V_9 && ( V_1 -> V_27 . V_9 -> V_65 || V_1 -> V_27 . V_9 -> V_51 ) ) {
F_51 ( V_1 ) ;
return;
}
if ( V_1 -> V_62 )
F_133 ( V_1 ) ;
else {
V_1 -> V_61 = false ;
V_1 -> V_289 &= ~ V_290 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
}
if ( V_1 -> V_62 < V_297 )
V_1 -> V_131 |= V_227 ;
}
static void F_134 ( T_1 * V_1 )
{
unsigned char V_246 = F_78 ( V_1 , V_298 + V_281 ) & 0xc0 ;
F_79 ( V_1 , V_298 + V_281 , ( unsigned char ) ( V_246 | 1 ) ) ;
if ( V_31 >= V_245 )
F_4 ( L_93 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_246 ) ;
V_1 -> V_131 |= V_226 ;
}
static void F_135 ( T_1 * V_1 )
{
unsigned char V_246 = F_78 ( V_1 , V_298 + V_281 ) & 0x30 ;
F_79 ( V_1 , V_298 + V_281 , ( unsigned char ) ( V_246 | 1 ) ) ;
if ( V_31 >= V_245 )
F_4 ( L_94 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_246 ) ;
V_1 -> V_299 = true ;
V_1 -> V_131 |= V_226 ;
}
static void F_136 ( T_1 * V_1 )
{
unsigned char V_300 = F_78 ( V_1 , V_247 ) ;
F_79 ( V_1 , V_279 + V_280 , 0x00 ) ;
F_79 ( V_1 , V_279 + V_281 , 0xc0 ) ;
F_79 ( V_1 , V_279 + V_282 , V_283 ) ;
if ( V_31 >= V_245 )
F_4 ( L_95 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_300 ) ;
F_130 ( V_1 , V_301 , 0 ) ;
V_1 -> V_289 |= V_290 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
}
static void F_137 ( T_1 * V_1 )
{
unsigned char V_246 = F_78 ( V_1 , V_279 + V_281 ) & 0x30 ;
F_79 ( V_1 , V_279 + V_281 , ( unsigned char ) ( V_246 | 1 ) ) ;
if ( V_31 >= V_245 )
F_4 ( L_96 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_246 ) ;
}
static void F_126 ( T_1 * V_1 , T_7 V_246 )
{
struct V_96 * V_95 ;
if ( V_31 >= V_245 )
F_4 ( L_97 ,
__FILE__ , __LINE__ , V_246 ) ;
if ( V_246 & ( V_296 | V_265 |
V_302 | V_303 ) ) {
V_95 = & V_1 -> V_95 ;
if ( V_246 & V_303 ) {
V_95 -> V_100 ++ ;
if ( V_246 & V_120 )
V_1 -> V_304 . V_305 ++ ;
else
V_1 -> V_304 . V_306 ++ ;
}
if ( V_246 & V_302 ) {
V_95 -> V_99 ++ ;
if ( V_246 & V_118 )
V_1 -> V_304 . V_307 ++ ;
else
V_1 -> V_304 . V_308 ++ ;
}
if ( V_246 & V_265 ) {
if ( ( V_1 -> V_236 ) ++ >= V_309 ) {
V_1 -> V_248 &= ~ V_251 ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
}
V_95 -> V_101 ++ ;
if ( V_246 & V_119 ) {
V_1 -> V_304 . V_311 ++ ;
} else
V_1 -> V_304 . V_312 ++ ;
#if V_294
if ( V_1 -> V_36 ) {
if ( V_246 & V_119 )
F_90 ( V_1 -> V_206 ) ;
else
F_91 ( V_1 -> V_206 ) ;
}
#endif
}
if ( V_246 & V_296 )
{
if ( ( V_1 -> V_237 ) ++ >= V_309 ) {
V_1 -> V_248 &= ~ V_295 ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
}
V_95 -> V_98 ++ ;
if ( V_246 & V_117 )
V_1 -> V_304 . V_313 ++ ;
else
V_1 -> V_304 . V_314 ++ ;
}
F_27 ( & V_1 -> V_315 ) ;
F_27 ( & V_1 -> V_264 ) ;
if ( F_138 ( & V_1 -> V_27 ) &&
( V_246 & V_265 ) ) {
if ( V_31 >= V_245 )
F_4 ( L_98 , V_1 -> V_25 ,
( V_246 & V_119 ) ? L_99 : L_100 ) ;
if ( V_246 & V_119 )
F_27 ( & V_1 -> V_27 . V_42 ) ;
else {
if ( V_31 >= V_245 )
F_4 ( L_101 ) ;
if ( V_1 -> V_27 . V_9 )
F_139 ( V_1 -> V_27 . V_9 ) ;
}
}
if ( F_140 ( & V_1 -> V_27 ) &&
( V_246 & V_296 ) ) {
if ( V_1 -> V_27 . V_9 ) {
if ( V_1 -> V_27 . V_9 -> V_51 ) {
if ( V_246 & V_117 ) {
if ( V_31 >= V_245 )
F_4 ( L_102 ) ;
V_1 -> V_27 . V_9 -> V_51 = 0 ;
F_39 ( V_1 ) ;
V_1 -> V_131 |= V_227 ;
return;
}
} else {
if ( ! ( V_246 & V_117 ) ) {
if ( V_31 >= V_245 )
F_4 ( L_103 ) ;
V_1 -> V_27 . V_9 -> V_51 = 1 ;
F_51 ( V_1 ) ;
}
}
}
}
}
V_1 -> V_131 |= V_228 ;
}
static T_8 F_141 ( int V_316 , void * V_317 )
{
T_1 * V_1 = V_317 ;
unsigned char V_246 , V_318 , V_319 = 0 ;
unsigned char V_320 , V_321 , V_322 = 0 ;
unsigned char V_323 , V_324 = 0 ;
unsigned char V_325 ;
unsigned int V_326 ;
unsigned short V_327 ;
if ( V_31 >= V_245 )
F_4 ( V_328 L_104 ,
__FILE__ , __LINE__ , V_1 -> V_116 ) ;
F_142 ( & V_1 -> V_41 ) ;
for(; ; ) {
V_327 = F_143 ( V_1 , V_329 ) ;
V_318 = ( unsigned char ) V_327 ;
V_321 = ( unsigned char ) ( V_327 >> 8 ) ;
V_323 = F_78 ( V_1 , V_330 ) ;
if ( V_31 >= V_245 )
F_4 ( V_328 L_105 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_318 , V_321 , V_323 ) ;
if ( V_1 -> V_331 == 4 ) {
V_327 = F_143 ( V_1 -> V_332 [ 2 ] , V_329 ) ;
V_319 = ( unsigned char ) V_327 ;
V_322 = ( unsigned char ) ( V_327 >> 8 ) ;
V_324 = F_78 ( V_1 -> V_332 [ 2 ] , V_330 ) ;
if ( V_31 >= V_245 )
F_4 ( L_106 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_319 , V_322 , V_324 ) ;
}
if ( ! V_318 && ! V_321 && ! V_323 &&
! V_319 && ! V_322 && ! V_324 )
break;
for( V_326 = 0 ; V_326 < V_1 -> V_331 ; V_326 ++ ) {
if ( V_1 -> V_332 [ V_326 ] == NULL )
continue;
if ( V_326 < 2 ) {
V_246 = V_318 ;
V_320 = V_321 ;
} else {
V_246 = V_319 ;
V_320 = V_322 ;
}
V_325 = V_326 & 1 ? 4 : 0 ;
if ( V_246 & V_268 << V_325 )
F_127 ( V_1 -> V_332 [ V_326 ] ) ;
if ( V_246 & V_333 << V_325 )
F_132 ( V_1 -> V_332 [ V_326 ] ) ;
if ( V_246 & V_334 << V_325 )
F_123 ( V_1 -> V_332 [ V_326 ] ) ;
if ( V_246 & V_139 << V_325 )
F_131 ( V_1 -> V_332 [ V_326 ] ) ;
if ( V_320 & V_268 << V_325 )
F_135 ( V_1 -> V_332 [ V_326 ] ) ;
if ( V_320 & V_333 << V_325 )
F_134 ( V_1 -> V_332 [ V_326 ] ) ;
if ( V_320 & V_334 << V_325 )
F_137 ( V_1 -> V_332 [ V_326 ] ) ;
if ( V_320 & V_139 << V_325 )
F_136 ( V_1 -> V_332 [ V_326 ] ) ;
}
if ( V_323 & ( V_335 | V_336 ) )
F_122 ( V_1 -> V_332 [ 0 ] ) ;
if ( V_323 & ( V_337 | V_338 ) )
F_122 ( V_1 -> V_332 [ 1 ] ) ;
if ( V_324 & ( V_335 | V_336 ) )
F_122 ( V_1 -> V_332 [ 2 ] ) ;
if ( V_324 & ( V_337 | V_338 ) )
F_122 ( V_1 -> V_332 [ 3 ] ) ;
}
for( V_326 = 0 ; V_326 < V_1 -> V_331 ; V_326 ++ ) {
T_1 * V_27 = V_1 -> V_332 [ V_326 ] ;
if ( V_27 && ( V_27 -> V_27 . V_12 || V_27 -> V_36 ) &&
V_27 -> V_131 && ! V_27 -> V_130 &&
! V_27 -> V_129 ) {
if ( V_31 >= V_245 )
F_4 ( L_107 ,
__FILE__ , __LINE__ , V_27 -> V_25 ) ;
F_144 ( & V_27 -> V_231 ) ;
V_27 -> V_129 = true ;
}
}
F_145 ( & V_1 -> V_41 ) ;
if ( V_31 >= V_245 )
F_4 ( V_328 L_108 ,
__FILE__ , __LINE__ , V_1 -> V_116 ) ;
return V_339 ;
}
static int F_13 ( T_1 * V_1 )
{
if ( V_31 >= V_32 )
F_4 ( L_109 , __FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( F_18 ( & V_1 -> V_27 ) )
return 0 ;
if ( ! V_1 -> V_55 ) {
V_1 -> V_55 = F_146 ( V_1 -> V_59 , V_340 ) ;
if ( ! V_1 -> V_55 ) {
F_4 ( V_213 L_110 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_214 ;
}
}
V_1 -> V_131 = 0 ;
memset ( & V_1 -> V_95 , 0 , sizeof( V_1 -> V_95 ) ) ;
F_147 ( V_1 ) ;
F_29 ( V_1 ) ;
F_148 ( & V_1 -> V_341 , V_71 + F_149 ( 10 ) ) ;
if ( V_1 -> V_27 . V_9 )
F_150 ( V_342 , & V_1 -> V_27 . V_9 -> V_11 ) ;
F_151 ( & V_1 -> V_27 , 1 ) ;
return 0 ;
}
static void F_22 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( ! F_18 ( & V_1 -> V_27 ) )
return;
if ( V_31 >= V_32 )
F_4 ( L_111 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_27 ( & V_1 -> V_315 ) ;
F_27 ( & V_1 -> V_264 ) ;
F_48 ( & V_1 -> V_76 ) ;
F_48 ( & V_1 -> V_341 ) ;
F_152 ( V_1 -> V_55 ) ;
V_1 -> V_55 = NULL ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_147 ( V_1 ) ;
if ( ! V_1 -> V_27 . V_9 || V_1 -> V_27 . V_9 -> V_343 . V_45 & V_344 ) {
V_1 -> V_47 &= ~ ( V_48 | V_49 ) ;
F_31 ( V_1 ) ;
}
F_12 ( & V_1 -> V_41 , V_11 ) ;
if ( V_1 -> V_27 . V_9 )
F_153 ( V_342 , & V_1 -> V_27 . V_9 -> V_11 ) ;
F_151 ( & V_1 -> V_27 , 0 ) ;
}
static void F_82 ( T_1 * V_1 )
{
unsigned long V_11 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_154 ( V_1 ) ;
F_51 ( V_1 ) ;
V_1 -> V_62 = V_1 -> V_64 = V_1 -> V_75 = 0 ;
if ( V_1 -> V_56 . V_57 == V_58 || V_1 -> V_36 )
F_155 ( V_1 ) ;
else
F_156 ( V_1 ) ;
F_31 ( V_1 ) ;
V_1 -> V_236 = 0 ;
V_1 -> V_237 = 0 ;
V_1 -> V_234 = 0 ;
V_1 -> V_235 = 0 ;
V_1 -> V_248 |= ( V_251 | V_295 ) ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
F_67 ( V_1 ) ;
if ( V_1 -> V_36 || ( V_1 -> V_27 . V_9 && V_1 -> V_27 . V_9 -> V_343 . V_45 & V_345 ) )
F_157 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
static void F_29 ( T_1 * V_1 )
{
unsigned V_346 ;
int V_347 ;
if ( ! V_1 -> V_27 . V_9 )
return;
if ( V_31 >= V_32 )
F_4 ( L_112 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_346 = V_1 -> V_27 . V_9 -> V_343 . V_45 ;
if ( V_346 & V_46 )
V_1 -> V_47 |= V_48 | V_49 ;
else
V_1 -> V_47 &= ~ ( V_48 | V_49 ) ;
switch ( V_346 & V_348 ) {
case V_349 : V_1 -> V_56 . V_350 = 5 ; break;
case V_351 : V_1 -> V_56 . V_350 = 6 ; break;
case V_352 : V_1 -> V_56 . V_350 = 7 ; break;
case V_353 : V_1 -> V_56 . V_350 = 8 ; break;
default: V_1 -> V_56 . V_350 = 7 ; break;
}
if ( V_346 & V_354 )
V_1 -> V_56 . V_355 = 2 ;
else
V_1 -> V_56 . V_355 = 1 ;
V_1 -> V_56 . V_106 = V_356 ;
if ( V_346 & V_357 ) {
if ( V_346 & V_358 )
V_1 -> V_56 . V_106 = V_359 ;
else
V_1 -> V_56 . V_106 = V_360 ;
#ifdef F_158
if ( V_346 & F_158 )
V_1 -> V_56 . V_106 = V_361 ;
#endif
}
V_347 = V_1 -> V_56 . V_350 +
V_1 -> V_56 . V_355 + 1 ;
if ( V_1 -> V_56 . V_72 <= 460800 ) {
V_1 -> V_56 . V_72 = F_159 ( V_1 -> V_27 . V_9 ) ;
}
if ( V_1 -> V_56 . V_72 ) {
V_1 -> V_40 = ( 32 * V_222 * V_347 ) /
V_1 -> V_56 . V_72 ;
}
V_1 -> V_40 += V_222 / 50 ;
F_160 ( & V_1 -> V_27 , V_346 & V_50 ) ;
F_161 ( & V_1 -> V_27 , ~ V_346 & V_362 ) ;
V_1 -> V_275 = V_256 ;
if ( F_162 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_275 |= V_272 | V_273 ;
if ( F_163 ( V_1 -> V_27 . V_9 ) || F_164 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_259 |= V_252 ;
if ( F_165 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_274 |= V_272 | V_273 ;
if ( F_166 ( V_1 -> V_27 . V_9 ) ) {
V_1 -> V_258 |= V_252 ;
if ( F_165 ( V_1 -> V_27 . V_9 ) )
V_1 -> V_274 |= V_256 ;
}
F_82 ( V_1 ) ;
}
static int F_61 ( T_1 * V_1 , struct V_96 T_3 * V_363 )
{
int V_364 ;
if ( V_31 >= V_32 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( ! V_363 ) {
memset ( & V_1 -> V_95 , 0 , sizeof( V_1 -> V_95 ) ) ;
} else {
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_167 ( V_364 , V_363 , & V_1 -> V_95 , sizeof( struct V_96 ) ) ;
F_23 ( & V_1 -> V_27 . V_39 ) ;
if ( V_364 )
return - V_201 ;
}
return 0 ;
}
static int F_54 ( T_1 * V_1 , T_9 T_3 * V_365 )
{
int V_364 ;
if ( V_31 >= V_32 )
F_4 ( L_113 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_167 ( V_364 , V_365 , & V_1 -> V_56 , sizeof( T_9 ) ) ;
F_23 ( & V_1 -> V_27 . V_39 ) ;
if ( V_364 ) {
if ( V_31 >= V_32 )
F_4 ( L_114 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_201 ;
}
return 0 ;
}
static int F_55 ( T_1 * V_1 , T_9 T_3 * V_366 )
{
unsigned long V_11 ;
T_9 V_367 ;
int V_364 ;
if ( V_31 >= V_32 )
F_4 ( L_115 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_168 ( V_364 , & V_367 , V_366 , sizeof( T_9 ) ) ;
if ( V_364 ) {
if ( V_31 >= V_32 )
F_4 ( L_116 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_201 ;
}
F_17 ( & V_1 -> V_27 . V_39 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
memcpy ( & V_1 -> V_56 , & V_367 , sizeof( T_9 ) ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
F_29 ( V_1 ) ;
F_23 ( & V_1 -> V_27 . V_39 ) ;
return 0 ;
}
static int F_56 ( T_1 * V_1 , int T_3 * V_368 )
{
int V_364 ;
if ( V_31 >= V_32 )
F_4 ( L_117 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_368 ) ;
F_167 ( V_364 , V_368 , & V_1 -> V_368 , sizeof( int ) ) ;
if ( V_364 ) {
if ( V_31 >= V_32 )
F_4 ( L_118 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_201 ;
}
return 0 ;
}
static int F_57 ( T_1 * V_1 , int V_368 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_119 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_368 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_368 = V_368 ;
F_169 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
return 0 ;
}
static int F_58 ( T_1 * V_1 , int V_369 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_120 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_369 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( V_369 ) {
if ( ! V_1 -> V_68 ) {
F_39 ( V_1 ) ;
}
} else {
if ( V_1 -> V_68 )
F_51 ( V_1 ) ;
}
F_12 ( & V_1 -> V_41 , V_11 ) ;
return 0 ;
}
static int F_60 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_121 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( V_1 -> V_61 && V_1 -> V_56 . V_57 == V_58 ) {
V_1 -> V_248 &= ~ V_284 ;
V_1 -> V_248 |= V_291 ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
F_79 ( V_1 , V_247 , ( unsigned char ) ( V_291 + V_284 ) ) ;
F_79 ( V_1 , V_279 + V_281 , 0 ) ;
F_79 ( V_1 , V_279 + V_282 , V_283 ) ;
F_79 ( V_1 , V_285 , V_370 ) ;
}
F_12 ( & V_1 -> V_41 , V_11 ) ;
return 0 ;
}
static int F_59 ( T_1 * V_1 , int V_369 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_122 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_369 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( V_369 ) {
if ( ! V_1 -> V_371 )
F_157 ( V_1 ) ;
} else {
if ( V_1 -> V_371 )
F_154 ( V_1 ) ;
}
F_12 ( & V_1 -> V_41 , V_11 ) ;
return 0 ;
}
static int F_62 ( T_1 * V_1 , int T_3 * V_372 )
{
unsigned long V_11 ;
int V_373 ;
int V_170 = 0 ;
struct V_96 V_374 , V_97 ;
int V_375 ;
int V_376 ;
struct V_377 V_378 , V_379 ;
F_170 ( V_380 , V_73 ) ;
F_168 ( V_170 , & V_376 , V_372 , sizeof( int ) ) ;
if ( V_170 ) {
return - V_201 ;
}
if ( V_31 >= V_32 )
F_4 ( L_123 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_376 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_67 ( V_1 ) ;
V_373 = V_1 -> V_47 ;
V_375 = V_376 &
( ( ( V_373 & V_118 ) ? V_381 : V_382 ) +
( ( V_373 & V_119 ) ? V_383 : V_384 ) +
( ( V_373 & V_117 ) ? V_385 : V_386 ) +
( ( V_373 & V_120 ) ? V_387 : V_388 ) ) ;
if ( V_375 ) {
F_12 ( & V_1 -> V_41 , V_11 ) ;
goto exit;
}
V_374 = V_1 -> V_95 ;
V_378 = V_1 -> V_304 ;
if ( V_376 & ( V_389 + V_390 ) ) {
unsigned char V_391 = V_1 -> V_248 ;
unsigned char V_392 = V_391 +
( V_376 & V_389 ? V_249 : 0 ) +
( V_376 & V_390 ? V_250 : 0 ) ;
if ( V_391 != V_392 ) {
V_1 -> V_248 = V_392 ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
}
}
F_171 ( V_393 ) ;
F_172 ( & V_1 -> V_264 , & V_380 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
for(; ; ) {
F_173 () ;
if ( F_44 ( V_73 ) ) {
V_170 = - V_394 ;
break;
}
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_97 = V_1 -> V_95 ;
V_379 = V_1 -> V_304 ;
F_171 ( V_393 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
if ( V_379 . V_307 == V_378 . V_307 &&
V_379 . V_308 == V_378 . V_308 &&
V_379 . V_311 == V_378 . V_311 &&
V_379 . V_312 == V_378 . V_312 &&
V_379 . V_313 == V_378 . V_313 &&
V_379 . V_314 == V_378 . V_314 &&
V_379 . V_305 == V_378 . V_305 &&
V_379 . V_306 == V_378 . V_306 &&
V_97 . V_262 == V_374 . V_262 &&
V_97 . V_263 == V_374 . V_263 ) {
V_170 = - V_60 ;
break;
}
V_375 = V_376 &
( ( V_379 . V_307 != V_378 . V_307 ? V_381 : 0 ) +
( V_379 . V_308 != V_378 . V_308 ? V_382 : 0 ) +
( V_379 . V_311 != V_378 . V_311 ? V_383 : 0 ) +
( V_379 . V_312 != V_378 . V_312 ? V_384 : 0 ) +
( V_379 . V_313 != V_378 . V_313 ? V_385 : 0 ) +
( V_379 . V_314 != V_378 . V_314 ? V_386 : 0 ) +
( V_379 . V_305 != V_378 . V_305 ? V_387 : 0 ) +
( V_379 . V_306 != V_378 . V_306 ? V_388 : 0 ) +
( V_97 . V_262 != V_374 . V_262 ? V_389 : 0 ) +
( V_97 . V_263 != V_374 . V_263 ? V_390 : 0 ) ) ;
if ( V_375 )
break;
V_374 = V_97 ;
V_378 = V_379 ;
}
F_174 ( & V_1 -> V_264 , & V_380 ) ;
F_171 ( V_395 ) ;
if ( V_376 & ( V_389 + V_390 ) ) {
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( ! F_175 ( & V_1 -> V_264 ) ) {
V_1 -> V_248 &= ~ ( V_249 | V_250 ) ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
}
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
exit:
if ( V_170 == 0 )
F_176 ( V_170 , V_375 , V_372 ) ;
return V_170 ;
}
static int F_63 ( T_1 * V_1 , int V_78 )
{
unsigned long V_11 ;
int V_170 ;
struct V_96 V_374 , V_97 ;
F_170 ( V_380 , V_73 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_374 = V_1 -> V_95 ;
F_172 ( & V_1 -> V_315 , & V_380 ) ;
F_171 ( V_393 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
for(; ; ) {
F_173 () ;
if ( F_44 ( V_73 ) ) {
V_170 = - V_394 ;
break;
}
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_97 = V_1 -> V_95 ;
F_171 ( V_393 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
if ( V_97 . V_100 == V_374 . V_100 && V_97 . V_99 == V_374 . V_99 &&
V_97 . V_101 == V_374 . V_101 && V_97 . V_98 == V_374 . V_98 ) {
V_170 = - V_60 ;
break;
}
if ( ( V_78 & V_396 && V_97 . V_100 != V_374 . V_100 ) ||
( V_78 & V_397 && V_97 . V_99 != V_374 . V_99 ) ||
( V_78 & V_398 && V_97 . V_101 != V_374 . V_101 ) ||
( V_78 & V_399 && V_97 . V_98 != V_374 . V_98 ) ) {
V_170 = 0 ;
break;
}
V_374 = V_97 ;
}
F_174 ( & V_1 -> V_315 , & V_380 ) ;
F_171 ( V_395 ) ;
return V_170 ;
}
static int F_177 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned int V_400 ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_67 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
V_400 = ( ( V_1 -> V_47 & V_48 ) ? V_401 : 0 ) |
( ( V_1 -> V_47 & V_49 ) ? V_402 : 0 ) |
( ( V_1 -> V_47 & V_119 ) ? V_403 : 0 ) |
( ( V_1 -> V_47 & V_120 ) ? V_396 : 0 ) |
( ( V_1 -> V_47 & V_118 ) ? V_397 : 0 ) |
( ( V_1 -> V_47 & V_117 ) ? V_399 : 0 ) ;
if ( V_31 >= V_32 )
F_4 ( L_124 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_400 ) ;
return V_400 ;
}
static int F_178 ( struct V_8 * V_9 ,
unsigned int V_404 , unsigned int V_405 )
{
T_1 * V_1 = V_9 -> V_26 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_125 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_404 , V_405 ) ;
if ( V_404 & V_401 )
V_1 -> V_47 |= V_48 ;
if ( V_404 & V_402 )
V_1 -> V_47 |= V_49 ;
if ( V_405 & V_401 )
V_1 -> V_47 &= ~ V_48 ;
if ( V_405 & V_402 )
V_1 -> V_47 &= ~ V_49 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_31 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
return 0 ;
}
static int F_179 ( struct V_406 * V_27 )
{
T_1 * V_1 = F_117 ( V_27 , T_1 , V_27 ) ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_67 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
return ( V_1 -> V_47 & V_119 ) ? 1 : 0 ;
}
static void F_180 ( struct V_406 * V_27 , int V_407 )
{
T_1 * V_1 = F_117 ( V_27 , T_1 , V_27 ) ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
if ( V_407 )
V_1 -> V_47 |= V_48 | V_49 ;
else
V_1 -> V_47 &= ~ ( V_48 | V_49 ) ;
F_31 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
static int F_14 ( struct V_8 * V_9 , struct V_28 * V_29 ,
T_1 * V_1 )
{
F_170 ( V_380 , V_73 ) ;
int V_30 ;
bool V_408 = false ;
unsigned long V_11 ;
int V_409 ;
struct V_406 * V_27 = & V_1 -> V_27 ;
if ( V_31 >= V_32 )
F_4 ( L_126 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 ) ;
if ( V_29 -> V_410 & V_411 || F_53 ( V_9 ) ) {
F_26 ( V_27 , 1 ) ;
return 0 ;
}
if ( F_181 ( V_9 ) )
V_408 = true ;
V_30 = 0 ;
F_172 ( & V_27 -> V_42 , & V_380 ) ;
if ( V_31 >= V_32 )
F_4 ( L_127 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_27 -> V_12 -- ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
V_27 -> V_412 ++ ;
while ( 1 ) {
if ( F_30 ( V_9 ) && F_18 ( V_27 ) )
F_182 ( V_27 ) ;
F_171 ( V_393 ) ;
if ( F_183 ( V_29 ) || ! F_18 ( V_27 ) ) {
V_30 = ( V_27 -> V_11 & V_413 ) ?
- V_414 : - V_394 ;
break;
}
V_409 = F_184 ( V_27 ) ;
if ( V_408 || V_409 )
break;
if ( F_44 ( V_73 ) ) {
V_30 = - V_394 ;
break;
}
if ( V_31 >= V_32 )
F_4 ( L_128 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
F_185 ( V_9 ) ;
F_173 () ;
F_186 ( V_9 ) ;
}
F_171 ( V_395 ) ;
F_174 ( & V_27 -> V_42 , & V_380 ) ;
if ( ! F_183 ( V_29 ) )
V_27 -> V_12 ++ ;
V_27 -> V_412 -- ;
if ( V_31 >= V_32 )
F_4 ( L_129 ,
__FILE__ , __LINE__ , V_9 -> V_18 -> V_2 , V_27 -> V_12 ) ;
if ( ! V_30 )
F_26 ( V_27 , 1 ) ;
return V_30 ;
}
static int F_187 ( T_1 * V_1 )
{
unsigned short V_415 ;
unsigned short V_416 ;
V_1 -> V_332 [ 0 ] -> V_417 = ( V_418 / 4 ) * V_1 -> V_239 ;
V_415 = ( unsigned short ) ( V_1 -> V_59 / V_419 ) ;
if ( V_1 -> V_59 % V_419 )
V_415 ++ ;
V_416 = ( V_418 / 4 - V_420 ) / V_419 ;
if ( V_416 > V_420 / sizeof( V_421 ) )
V_416 = V_420 / sizeof( V_421 ) ;
V_1 -> V_422 = V_415 + 1 ;
if ( V_1 -> V_422 > ( V_416 / 2 ) )
V_1 -> V_422 = V_416 / 2 ;
if ( V_1 -> V_422 > V_423 )
V_1 -> V_422 = V_423 ;
V_1 -> V_424 = V_416 - V_1 -> V_422 ;
if ( V_1 -> V_424 > V_423 )
V_1 -> V_424 = V_423 ;
if ( V_31 >= V_32 )
F_4 ( L_130 ,
__FILE__ , __LINE__ , V_1 -> V_25 ,
V_1 -> V_422 , V_1 -> V_424 ) ;
if ( F_188 ( V_1 ) < 0 ||
F_189 ( V_1 ,
V_1 -> V_425 ,
V_1 -> V_426 ,
V_1 -> V_424 ) < 0 ||
F_189 ( V_1 ,
V_1 -> V_427 ,
V_1 -> V_428 ,
V_1 -> V_422 ) < 0 ||
F_190 ( V_1 ) < 0 ) {
F_4 ( L_131 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_214 ;
}
F_191 ( V_1 ) ;
return 0 ;
}
static int F_188 ( T_1 * V_1 )
{
unsigned int V_326 ;
V_1 -> V_429 = V_1 -> V_430 + V_1 -> V_332 [ 0 ] -> V_417 ;
V_1 -> V_431 = V_1 -> V_332 [ 0 ] -> V_417 ;
V_1 -> V_332 [ 0 ] -> V_417 += V_420 ;
memset ( V_1 -> V_429 , 0 , V_420 ) ;
V_1 -> V_425 = ( V_421 * ) V_1 -> V_429 ;
V_1 -> V_427 = ( V_421 * ) V_1 -> V_429 ;
V_1 -> V_427 += V_1 -> V_424 ;
for ( V_326 = 0 ; V_326 < V_1 -> V_424 ; V_326 ++ ) {
V_1 -> V_426 [ V_326 ] . V_432 =
V_1 -> V_431 + ( V_326 * V_419 ) ;
V_1 -> V_425 [ V_326 ] . V_433 = V_1 -> V_431 ;
if ( V_326 < V_1 -> V_424 - 1 )
V_1 -> V_425 [ V_326 ] . V_433 += ( V_326 + 1 ) * sizeof( V_421 ) ;
V_1 -> V_425 [ V_326 ] . V_434 = V_419 ;
}
for ( V_326 = 0 ; V_326 < V_1 -> V_422 ; V_326 ++ ) {
V_1 -> V_428 [ V_326 ] . V_432 = V_1 -> V_431 +
( ( V_1 -> V_424 + V_326 ) * sizeof( V_421 ) ) ;
V_1 -> V_427 [ V_326 ] . V_433 = V_1 -> V_431 +
V_1 -> V_424 * sizeof( V_421 ) ;
if ( V_326 < V_1 -> V_422 - 1 )
V_1 -> V_427 [ V_326 ] . V_433 += ( V_326 + 1 ) * sizeof( V_421 ) ;
}
return 0 ;
}
static int F_189 ( T_1 * V_1 , V_421 * V_435 , T_10 * V_436 , int V_12 )
{
int V_326 ;
unsigned long V_437 ;
for ( V_326 = 0 ; V_326 < V_12 ; V_326 ++ ) {
V_436 [ V_326 ] . V_438 = V_1 -> V_430 + V_1 -> V_332 [ 0 ] -> V_417 ;
V_437 = V_1 -> V_332 [ 0 ] -> V_417 ;
V_1 -> V_332 [ 0 ] -> V_417 += V_419 ;
V_435 [ V_326 ] . V_439 = ( unsigned short ) V_437 ;
V_435 [ V_326 ] . V_440 = ( unsigned char ) ( V_437 >> 16 ) ;
}
return 0 ;
}
static void F_192 ( T_1 * V_1 )
{
V_1 -> V_429 = NULL ;
V_1 -> V_425 = NULL ;
V_1 -> V_427 = NULL ;
}
static int F_190 ( T_1 * V_1 )
{
V_1 -> V_441 = F_146 ( V_1 -> V_59 , V_340 ) ;
if ( V_1 -> V_441 == NULL )
return - V_214 ;
V_1 -> V_442 = F_193 ( V_1 -> V_59 , V_340 ) ;
if ( ! V_1 -> V_442 ) {
F_152 ( V_1 -> V_441 ) ;
V_1 -> V_441 = NULL ;
return - V_214 ;
}
return 0 ;
}
static void F_194 ( T_1 * V_1 )
{
F_152 ( V_1 -> V_441 ) ;
V_1 -> V_441 = NULL ;
F_152 ( V_1 -> V_442 ) ;
V_1 -> V_442 = NULL ;
}
static int F_195 ( T_1 * V_1 )
{
if ( F_196 ( V_1 -> V_113 , V_418 , L_132 ) == NULL ) {
F_4 ( L_133 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_113 ) ;
V_1 -> V_24 = V_443 ;
goto V_444;
}
else
V_1 -> V_445 = true ;
if ( F_196 ( V_1 -> V_115 + V_1 -> V_446 , 128 , L_132 ) == NULL ) {
F_4 ( L_134 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_115 ) ;
V_1 -> V_24 = V_443 ;
goto V_444;
}
else
V_1 -> V_447 = true ;
if ( F_196 ( V_1 -> V_112 + V_1 -> V_448 , V_217 , L_132 ) == NULL ) {
F_4 ( L_135 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_112 ) ;
V_1 -> V_24 = V_443 ;
goto V_444;
}
else
V_1 -> V_449 = true ;
if ( F_196 ( V_1 -> V_114 + V_1 -> V_450 , V_451 , L_132 ) == NULL ) {
F_4 ( L_136 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_114 ) ;
V_1 -> V_24 = V_443 ;
goto V_444;
}
else
V_1 -> V_452 = true ;
V_1 -> V_430 = F_197 ( V_1 -> V_113 ,
V_418 ) ;
if ( ! V_1 -> V_430 ) {
F_4 ( L_137 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_113 ) ;
V_1 -> V_24 = V_453 ;
goto V_444;
}
V_1 -> V_454 = F_197 ( V_1 -> V_115 , V_455 ) ;
if ( ! V_1 -> V_454 ) {
F_4 ( L_138 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_115 ) ;
V_1 -> V_24 = V_453 ;
goto V_444;
}
V_1 -> V_454 += V_1 -> V_446 ;
V_1 -> V_456 = F_197 ( V_1 -> V_112 , V_455 ) ;
if ( ! V_1 -> V_456 ) {
F_4 ( L_139 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_112 ) ;
V_1 -> V_24 = V_453 ;
goto V_444;
}
V_1 -> V_456 += V_1 -> V_448 ;
V_1 -> V_457 = F_197 ( V_1 -> V_114 ,
V_455 ) ;
if ( ! V_1 -> V_457 ) {
F_4 ( L_140 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_114 ) ;
V_1 -> V_24 = V_453 ;
goto V_444;
}
V_1 -> V_457 += V_1 -> V_450 ;
if ( ! F_198 ( V_1 ) ) {
F_4 ( L_141 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_113 ) ;
V_1 -> V_24 = V_458 ;
goto V_444;
}
return 0 ;
V_444:
F_199 ( V_1 ) ;
return - V_21 ;
}
static void F_199 ( T_1 * V_1 )
{
if ( V_31 >= V_32 )
F_4 ( L_142 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if ( V_1 -> V_459 ) {
F_200 ( V_1 -> V_116 , V_1 ) ;
V_1 -> V_459 = false ;
}
if ( V_1 -> V_445 ) {
F_201 ( V_1 -> V_113 , V_418 ) ;
V_1 -> V_445 = false ;
}
if ( V_1 -> V_447 ) {
F_201 ( V_1 -> V_115 + V_1 -> V_446 , 128 ) ;
V_1 -> V_447 = false ;
}
if ( V_1 -> V_449 ) {
F_201 ( V_1 -> V_112 + V_1 -> V_448 , V_217 ) ;
V_1 -> V_449 = false ;
}
if ( V_1 -> V_452 ) {
F_201 ( V_1 -> V_114 + V_1 -> V_450 , V_451 ) ;
V_1 -> V_452 = false ;
}
if ( V_1 -> V_430 ) {
F_202 ( V_1 -> V_430 ) ;
V_1 -> V_430 = NULL ;
}
if ( V_1 -> V_456 ) {
F_202 ( V_1 -> V_456 - V_1 -> V_448 ) ;
V_1 -> V_456 = NULL ;
}
if ( V_1 -> V_457 ) {
F_202 ( V_1 -> V_457 - V_1 -> V_450 ) ;
V_1 -> V_457 = NULL ;
}
if ( V_1 -> V_454 ) {
F_202 ( V_1 -> V_454 - V_1 -> V_446 ) ;
V_1 -> V_454 = NULL ;
}
if ( V_31 >= V_32 )
F_4 ( L_143 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
}
static int F_203 ( T_1 * V_1 )
{
V_1 -> V_23 = NULL ;
V_1 -> line = V_20 ;
sprintf ( V_1 -> V_25 , L_144 , V_1 -> V_460 , V_1 -> V_239 ) ;
if ( V_1 -> line < V_461 ) {
if ( V_462 [ V_1 -> line ] )
V_1 -> V_59 = V_462 [ V_1 -> line ] ;
}
V_20 ++ ;
if ( ! V_22 )
V_22 = V_1 ;
else {
T_1 * V_463 = V_22 ;
while( V_463 -> V_23 )
V_463 = V_463 -> V_23 ;
V_463 -> V_23 = V_1 ;
}
if ( V_1 -> V_59 < 4096 )
V_1 -> V_59 = 4096 ;
else if ( V_1 -> V_59 > 65535 )
V_1 -> V_59 = 65535 ;
F_4 ( L_145
L_146 ,
V_1 -> V_25 ,
V_1 -> V_112 ,
V_1 -> V_113 ,
V_1 -> V_114 ,
V_1 -> V_115 ,
V_1 -> V_116 ,
V_1 -> V_59 ) ;
#if V_294
return F_108 ( V_1 ) ;
#else
return 0 ;
#endif
}
static T_1 * F_204 ( int V_460 , int V_239 , struct V_464 * V_465 )
{
T_1 * V_1 ;
V_1 = F_193 ( sizeof( T_1 ) ,
V_340 ) ;
if ( ! V_1 ) {
F_4 ( L_147 ,
__FILE__ , __LINE__ , V_460 , V_239 ) ;
} else {
F_205 ( & V_1 -> V_27 ) ;
V_1 -> V_27 . V_15 = & V_466 ;
V_1 -> V_6 = V_7 ;
F_206 ( & V_1 -> V_231 , F_116 ) ;
V_1 -> V_59 = 4096 ;
V_1 -> V_27 . V_467 = 5 * V_222 / 10 ;
V_1 -> V_27 . V_468 = 30 * V_222 ;
F_207 ( & V_1 -> V_315 ) ;
F_207 ( & V_1 -> V_264 ) ;
F_208 ( & V_1 -> V_35 ) ;
memcpy ( & V_1 -> V_56 , & V_469 , sizeof( T_9 ) ) ;
V_1 -> V_368 = V_470 ;
V_1 -> V_460 = V_460 ;
V_1 -> V_239 = V_239 ;
V_1 -> V_116 = V_465 -> V_218 ;
V_1 -> V_115 = F_209 ( V_465 , 0 ) ;
V_1 -> V_112 = F_209 ( V_465 , 2 ) ;
V_1 -> V_113 = F_209 ( V_465 , 3 ) ;
V_1 -> V_114 = F_209 ( V_465 , 4 ) ;
V_1 -> V_446 = V_1 -> V_115 & ( V_455 - 1 ) ;
V_1 -> V_115 &= ~ ( V_455 - 1 ) ;
V_1 -> V_448 = V_1 -> V_112 & ( V_455 - 1 ) ;
V_1 -> V_112 &= ~ ( V_455 - 1 ) ;
V_1 -> V_450 = V_1 -> V_114 & ( V_455 - 1 ) ;
V_1 -> V_114 &= ~ ( V_455 - 1 ) ;
V_1 -> V_471 = V_472 ;
V_1 -> V_473 = V_474 ;
F_210 ( & V_1 -> V_76 , V_475 , ( unsigned long ) V_1 ) ;
F_210 ( & V_1 -> V_341 , V_476 ,
( unsigned long ) V_1 ) ;
V_1 -> V_477 = 0x087e4546 ;
V_1 -> V_24 = - 1 ;
}
return V_1 ;
}
static int F_211 ( int V_460 , struct V_464 * V_465 )
{
T_1 * V_332 [ V_478 ] ;
int V_27 , V_170 ;
for ( V_27 = 0 ; V_27 < V_478 ; ++ V_27 ) {
V_332 [ V_27 ] = F_204 ( V_460 , V_27 , V_465 ) ;
if( V_332 [ V_27 ] == NULL ) {
for ( -- V_27 ; V_27 >= 0 ; -- V_27 ) {
F_212 ( & V_332 [ V_27 ] -> V_27 ) ;
F_152 ( V_332 [ V_27 ] ) ;
}
return - V_214 ;
}
}
for ( V_27 = 0 ; V_27 < V_478 ; ++ V_27 ) {
memcpy ( V_332 [ V_27 ] -> V_332 , V_332 , sizeof( V_332 ) ) ;
V_170 = F_203 ( V_332 [ V_27 ] ) ;
if ( V_170 )
goto V_479;
F_208 ( & V_332 [ V_27 ] -> V_41 ) ;
}
if ( ! F_195 ( V_332 [ 0 ] ) ) {
F_187 ( V_332 [ 0 ] ) ;
for ( V_27 = 1 ; V_27 < V_478 ; ++ V_27 ) {
V_332 [ V_27 ] -> V_41 = V_332 [ 0 ] -> V_41 ;
V_332 [ V_27 ] -> V_116 = V_332 [ 0 ] -> V_116 ;
V_332 [ V_27 ] -> V_430 = V_332 [ 0 ] -> V_430 ;
V_332 [ V_27 ] -> V_456 = V_332 [ 0 ] -> V_456 ;
V_332 [ V_27 ] -> V_457 = V_332 [ 0 ] -> V_457 ;
V_332 [ V_27 ] -> V_454 = V_332 [ 0 ] -> V_454 ;
F_187 ( V_332 [ V_27 ] ) ;
}
V_170 = F_213 ( V_332 [ 0 ] -> V_116 ,
F_141 ,
V_332 [ 0 ] -> V_473 ,
V_332 [ 0 ] -> V_25 ,
V_332 [ 0 ] ) ;
if ( V_170 ) {
F_4 ( L_148 ,
__FILE__ , __LINE__ ,
V_332 [ 0 ] -> V_25 ,
V_332 [ 0 ] -> V_116 ) ;
goto V_480;
}
V_332 [ 0 ] -> V_459 = true ;
F_214 ( V_332 [ 0 ] ) ;
}
return 0 ;
V_480:
F_199 ( V_332 [ 0 ] ) ;
V_479:
for ( V_27 = 0 ; V_27 < V_478 ; ++ V_27 ) {
F_212 ( & V_332 [ V_27 ] -> V_27 ) ;
F_152 ( V_332 [ V_27 ] ) ;
}
return V_170 ;
}
static void F_215 ( void )
{
int V_170 ;
T_1 * V_1 ;
T_1 * V_327 ;
F_4 ( L_149 , V_481 , V_133 ) ;
if ( V_482 ) {
V_170 = F_216 ( V_482 ) ;
if ( V_170 )
F_4 ( L_150 ,
__FILE__ , __LINE__ , V_170 ) ;
F_217 ( V_482 ) ;
}
V_1 = V_22 ;
while( V_1 ) {
F_147 ( V_1 ) ;
V_1 = V_1 -> V_23 ;
}
V_1 = V_22 ;
while( V_1 ) {
#if V_294
F_113 ( V_1 ) ;
#endif
F_192 ( V_1 ) ;
F_194 ( V_1 ) ;
if ( V_1 -> V_239 == 0 ) {
if ( V_1 -> V_456 )
F_79 ( V_1 , V_483 , 1 ) ;
F_199 ( V_1 ) ;
}
V_327 = V_1 ;
V_1 = V_1 -> V_23 ;
F_212 ( & V_327 -> V_27 ) ;
F_152 ( V_327 ) ;
}
F_218 ( & V_484 ) ;
}
static int T_11 F_219 ( void )
{
int V_170 ;
if ( V_485 ) {
F_1 () ;
F_220 () ;
}
F_4 ( L_151 , V_481 , V_133 ) ;
if ( ( V_170 = F_221 ( & V_484 ) ) < 0 ) {
F_4 ( L_152 , __FILE__ , V_170 ) ;
return V_170 ;
}
V_482 = F_222 ( 128 ) ;
if ( ! V_482 ) {
V_170 = - V_214 ;
goto error;
}
V_482 -> V_481 = L_132 ;
V_482 -> V_2 = L_153 ;
V_482 -> V_486 = V_487 ;
V_482 -> V_488 = 64 ;
V_482 -> type = V_489 ;
V_482 -> V_490 = V_491 ;
V_482 -> V_492 = V_493 ;
V_482 -> V_492 . V_45 =
V_494 | V_353 | V_345 | V_344 | V_362 ;
V_482 -> V_492 . V_495 = 9600 ;
V_482 -> V_492 . V_496 = 9600 ;
V_482 -> V_11 = V_497 ;
F_223 ( V_482 , & V_15 ) ;
if ( ( V_170 = F_224 ( V_482 ) ) < 0 ) {
F_4 ( L_154 ,
__FILE__ , __LINE__ ) ;
F_217 ( V_482 ) ;
V_482 = NULL ;
goto error;
}
F_4 ( L_155 ,
V_481 , V_133 ,
V_482 -> V_486 ) ;
return 0 ;
error:
F_215 () ;
return V_170 ;
}
static void T_12 F_225 ( void )
{
F_215 () ;
}
static void F_226 ( T_1 * V_1 , int V_369 )
{
if ( V_369 ) {
F_79 ( V_1 , V_498 , ( unsigned char ) ( F_78 ( V_1 , V_498 ) | ( V_333 + V_268 ) ) ) ;
V_1 -> V_332 [ 0 ] -> V_499 |= ( V_268 << ( V_1 -> V_239 * 2 ) ) ;
F_227 ( V_1 ) ;
F_79 ( V_1 , V_500 , 0x40 ) ;
F_79 ( V_1 , V_501 , 0x40 ) ;
} else {
F_79 ( V_1 , V_498 , ( unsigned char ) ( F_78 ( V_1 , V_498 ) & ~ ( V_333 + V_268 ) ) ) ;
F_79 ( V_1 , V_500 , 0x00 ) ;
F_79 ( V_1 , V_501 , 0x00 ) ;
}
if ( V_1 -> V_56 . V_199 )
F_228 ( V_1 , V_1 -> V_56 . V_199 ) ;
else
F_228 ( V_1 , 3686400 ) ;
}
static void F_228 ( T_1 * V_1 , T_13 V_72 )
{
T_13 V_502 ;
unsigned char V_503 ;
T_13 V_504 = 0 ;
if ( V_72 != 0 ) {
V_504 = 14745600 / V_72 ;
if ( ! V_504 )
V_504 = 1 ;
V_502 = V_504 ;
V_503 = 0 ;
if ( V_502 != 1 && V_502 != 2 ) {
V_503 = 1 ;
V_502 >>= 1 ;
}
for(; V_502 > 256 && V_503 < 10 ; V_503 ++ )
V_502 >>= 1 ;
F_79 ( V_1 , V_501 ,
( unsigned char ) ( ( F_78 ( V_1 , V_501 ) & 0xf0 ) | V_503 ) ) ;
F_79 ( V_1 , V_500 ,
( unsigned char ) ( ( F_78 ( V_1 , V_500 ) & 0xf0 ) | V_503 ) ) ;
F_79 ( V_1 , V_505 , ( unsigned char ) V_502 ) ;
}
else {
F_79 ( V_1 , V_501 , 0 ) ;
F_79 ( V_1 , V_500 , 0 ) ;
F_79 ( V_1 , V_505 , 0 ) ;
}
}
static void F_154 ( T_1 * V_1 )
{
if ( V_31 >= V_245 )
F_4 ( L_156 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_79 ( V_1 , V_285 , V_506 ) ;
V_1 -> V_289 &= ~ V_507 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
F_79 ( V_1 , V_298 + V_281 , 0 ) ;
F_79 ( V_1 , V_298 + V_282 , V_283 ) ;
F_79 ( V_1 , V_298 + V_280 , 0 ) ;
V_1 -> V_371 = false ;
V_1 -> V_299 = false ;
}
static void F_157 ( T_1 * V_1 )
{
int V_326 ;
if ( V_31 >= V_245 )
F_4 ( L_157 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_79 ( V_1 , V_285 , V_506 ) ;
if ( V_1 -> V_56 . V_57 == V_58 ) {
V_1 -> V_289 &= ~ V_507 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
F_79 ( V_1 , V_298 + V_281 , 0 ) ;
F_79 ( V_1 , V_298 + V_282 , V_283 ) ;
for ( V_326 = 0 ; V_326 < V_1 -> V_424 ; V_326 ++ ) {
V_1 -> V_425 [ V_326 ] . V_246 = 0xff ;
if ( ! ( V_326 % 4 ) )
F_229 ( V_1 ) ;
}
V_1 -> V_508 = 0 ;
F_130 ( V_1 , V_298 + V_509 ,
V_1 -> V_426 [ 0 ] . V_432 ) ;
F_130 ( V_1 , V_298 + V_510 ,
V_1 -> V_426 [ V_1 -> V_424 - 1 ] . V_432 ) ;
F_130 ( V_1 , V_298 + V_511 , V_419 ) ;
F_79 ( V_1 , V_298 + V_280 , 0x60 ) ;
F_79 ( V_1 , V_298 + V_281 , 0xf2 ) ;
} else {
V_1 -> V_289 |= V_507 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
}
F_79 ( V_1 , V_285 , V_512 ) ;
V_1 -> V_299 = false ;
V_1 -> V_371 = true ;
}
static void F_39 ( T_1 * V_1 )
{
if ( V_31 >= V_245 )
F_4 ( L_158 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_1 -> V_62 ) ;
if ( ! V_1 -> V_68 ) {
F_79 ( V_1 , V_285 , V_286 ) ;
F_79 ( V_1 , V_285 , V_287 ) ;
V_1 -> V_68 = true ;
}
if ( V_1 -> V_62 ) {
V_1 -> V_293 = false ;
if ( V_1 -> V_56 . V_57 != V_257 ) {
if ( V_1 -> V_56 . V_11 & V_513 ) {
F_67 ( V_1 ) ;
if ( ! ( V_1 -> V_47 & V_48 ) ) {
V_1 -> V_47 |= V_48 ;
F_31 ( V_1 ) ;
V_1 -> V_293 = true ;
}
}
F_130 ( V_1 , V_301 ,
( unsigned short ) ( ( ( V_514 - 1 ) << 8 ) + V_515 ) ) ;
F_79 ( V_1 , V_279 + V_281 , 0 ) ;
F_79 ( V_1 , V_279 + V_282 , V_283 ) ;
F_130 ( V_1 , V_279 + V_509 ,
V_1 -> V_428 [ 0 ] . V_432 ) ;
F_130 ( V_1 , V_279 + V_510 ,
V_1 -> V_428 [ V_1 -> V_516 ] . V_432 ) ;
V_1 -> V_248 &= ~ V_291 ;
V_1 -> V_248 |= V_284 ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
F_79 ( V_1 , V_247 , ( unsigned char ) ( V_291 + V_284 ) ) ;
F_79 ( V_1 , V_279 + V_280 , 0x40 ) ;
F_79 ( V_1 , V_279 + V_281 , 0xf2 ) ;
F_148 ( & V_1 -> V_76 , V_71 +
F_149 ( 5000 ) ) ;
}
else {
F_133 ( V_1 ) ;
V_1 -> V_289 |= V_290 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
}
V_1 -> V_61 = true ;
}
}
static void F_51 ( T_1 * V_1 )
{
if ( V_31 >= V_245 )
F_4 ( L_159 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_48 ( & V_1 -> V_76 ) ;
F_79 ( V_1 , V_279 + V_281 , 0 ) ;
F_79 ( V_1 , V_279 + V_282 , V_283 ) ;
F_79 ( V_1 , V_285 , V_286 ) ;
V_1 -> V_248 &= ~ ( V_284 + V_291 ) ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
F_79 ( V_1 , V_247 , ( unsigned char ) ( V_291 + V_284 ) ) ;
V_1 -> V_289 &= ~ V_290 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
V_1 -> V_68 = false ;
V_1 -> V_61 = false ;
}
static void F_133 ( T_1 * V_1 )
{
T_14 V_517 [ 2 ] ;
if ( ! V_1 -> V_62 && ! V_1 -> V_67 )
return;
while( V_1 -> V_62 && ( F_78 ( V_1 , V_518 ) & V_333 ) ) {
if ( ( V_1 -> V_62 > 1 ) && ! V_1 -> V_67 ) {
V_517 [ 0 ] = V_1 -> V_55 [ V_1 -> V_75 ++ ] ;
if ( V_1 -> V_75 >= V_1 -> V_59 )
V_1 -> V_75 -= V_1 -> V_59 ;
V_517 [ 1 ] = V_1 -> V_55 [ V_1 -> V_75 ++ ] ;
if ( V_1 -> V_75 >= V_1 -> V_59 )
V_1 -> V_75 -= V_1 -> V_59 ;
F_130 ( V_1 , V_271 , * ( ( T_7 * ) V_517 ) ) ;
V_1 -> V_62 -= 2 ;
V_1 -> V_95 . V_103 += 2 ;
} else {
if ( V_1 -> V_67 ) {
F_79 ( V_1 , V_271 , V_1 -> V_67 ) ;
V_1 -> V_67 = 0 ;
} else {
F_79 ( V_1 , V_271 , V_1 -> V_55 [ V_1 -> V_75 ++ ] ) ;
if ( V_1 -> V_75 >= V_1 -> V_59 )
V_1 -> V_75 -= V_1 -> V_59 ;
V_1 -> V_62 -- ;
}
V_1 -> V_95 . V_103 ++ ;
}
}
}
static void F_147 ( T_1 * V_1 )
{
if ( V_1 -> V_456 ) {
F_51 ( V_1 ) ;
F_154 ( V_1 ) ;
V_1 -> V_47 &= ~ ( V_48 | V_49 ) ;
F_31 ( V_1 ) ;
V_1 -> V_289 = 0 ;
V_1 -> V_248 = 0 ;
V_1 -> V_255 = 0 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
F_79 ( V_1 , V_519 , V_1 -> V_255 ) ;
F_79 ( V_1 , V_285 , V_520 ) ;
}
}
static void F_230 ( T_1 * V_1 )
{
int V_326 ;
for ( V_326 = 0 ; V_326 < V_478 ; ++ V_326 ) {
if ( V_1 -> V_332 [ V_326 ] )
F_147 ( V_1 -> V_332 [ V_326 ] ) ;
}
}
static void F_156 ( T_1 * V_1 )
{
unsigned char V_136 ;
F_51 ( V_1 ) ;
F_154 ( V_1 ) ;
V_136 = 0x00 ;
if ( V_1 -> V_56 . V_355 != 1 )
V_136 |= V_333 ;
F_79 ( V_1 , V_521 , V_136 ) ;
V_136 = 0x40 ;
switch ( V_1 -> V_56 . V_350 ) {
case 7 : V_136 |= V_336 + V_334 ; break;
case 6 : V_136 |= V_335 + V_139 ; break;
case 5 : V_136 |= V_335 + V_336 + V_139 + V_334 ; break;
}
if ( V_1 -> V_56 . V_106 != V_356 ) {
V_136 |= V_333 ;
if ( V_1 -> V_56 . V_106 == V_359 )
V_136 |= V_268 ;
}
F_79 ( V_1 , V_522 , V_136 ) ;
V_136 = 0x00 ;
if ( V_1 -> V_56 . V_200 )
V_136 |= ( V_333 + V_268 ) ;
F_79 ( V_1 , V_498 , V_136 ) ;
V_136 = V_338 ;
F_79 ( V_1 , V_500 , V_136 ) ;
V_136 = V_338 ;
F_79 ( V_1 , V_501 , V_136 ) ;
V_1 -> V_332 [ 0 ] -> V_499 |= ( V_268 << ( V_1 -> V_239 * 2 ) ) ;
F_227 ( V_1 ) ;
F_169 ( V_1 ) ;
F_79 ( V_1 , V_523 , 0x00 ) ;
F_79 ( V_1 , V_301 , 0x10 ) ;
F_79 ( V_1 , V_524 , 0x1e ) ;
V_136 = 0x10 ;
if ( ! ( V_1 -> V_47 & V_48 ) )
V_136 |= 0x01 ;
F_79 ( V_1 , V_138 , V_136 ) ;
V_1 -> V_289 |= V_525 + V_526 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
V_1 -> V_248 = V_252 ;
F_79 ( V_1 , V_310 , V_1 -> V_248 ) ;
V_1 -> V_255 = V_256 ;
F_79 ( V_1 , V_519 , V_1 -> V_255 ) ;
F_228 ( V_1 , V_1 -> V_56 . V_72 * 16 ) ;
}
static void F_155 ( T_1 * V_1 )
{
unsigned char V_136 ;
T_13 V_527 ;
V_1 -> V_56 . V_11 &= ~ ( V_189 + V_185 ) ;
F_79 ( V_1 , V_279 + V_280 , 0 ) ;
F_79 ( V_1 , V_298 + V_280 , 0 ) ;
V_136 = 0x81 ;
if ( V_1 -> V_56 . V_11 & V_528 )
V_136 |= V_336 ;
if ( V_1 -> V_56 . V_11 & V_529 )
V_136 |= V_336 ;
if ( V_1 -> V_56 . V_161 == V_158 )
V_136 |= V_334 + V_333 ;
F_79 ( V_1 , V_521 , V_136 ) ;
V_136 = 0x00 ;
F_79 ( V_1 , V_522 , V_136 ) ;
V_136 = 0x00 ;
switch( V_1 -> V_56 . V_142 ) {
case V_530 : V_136 |= V_335 ; break;
case V_150 : V_136 |= V_337 + V_335 ; break;
case V_152 : V_136 |= V_337 + V_338 ; break;
case V_154 : V_136 |= V_337 ; break;
#if 0
case HDLC_ENCODING_NRZB:
case HDLC_ENCODING_NRZI_MARK:
case HDLC_ENCODING_DIFF_BIPHASE_LEVEL:
#endif
}
if ( V_1 -> V_56 . V_11 & V_531 ) {
V_527 = 16 ;
V_136 |= V_139 ;
} else if ( V_1 -> V_56 . V_11 & V_532 ) {
V_527 = 8 ;
} else {
V_527 = 32 ;
V_136 |= V_336 ;
}
F_79 ( V_1 , V_498 , V_136 ) ;
V_136 = 0 ;
if ( V_1 -> V_56 . V_11 & V_186 )
V_136 |= V_338 ;
if ( V_1 -> V_56 . V_11 & V_185 )
V_136 |= V_338 + V_335 ;
F_79 ( V_1 , V_500 , V_136 ) ;
V_136 = 0 ;
if ( V_1 -> V_56 . V_11 & V_190 )
V_136 |= V_338 ;
if ( V_1 -> V_56 . V_11 & V_189 )
V_136 |= V_338 + V_335 ;
F_79 ( V_1 , V_501 , V_136 ) ;
if ( V_1 -> V_56 . V_11 & V_185 )
F_228 ( V_1 , V_1 -> V_56 . V_199 * V_527 ) ;
else
F_228 ( V_1 , V_1 -> V_56 . V_199 ) ;
if ( V_1 -> V_56 . V_11 & V_190 )
V_1 -> V_332 [ 0 ] -> V_499 |= ( V_268 << ( V_1 -> V_239 * 2 ) ) ;
else
V_1 -> V_332 [ 0 ] -> V_499 &= ~ ( V_268 << ( V_1 -> V_239 * 2 ) ) ;
F_227 ( V_1 ) ;
F_79 ( V_1 , V_523 , V_533 ) ;
F_79 ( V_1 , V_301 , V_515 ) ;
F_79 ( V_1 , V_524 , ( unsigned char ) ( V_514 - 1 ) ) ;
F_79 ( V_1 , V_279 + V_534 , 0x14 ) ;
F_79 ( V_1 , V_298 + V_534 , 0x14 ) ;
F_79 ( V_1 , V_298 + V_535 ,
( unsigned char ) ( V_1 -> V_431 >> 16 ) ) ;
F_79 ( V_1 , V_279 + V_535 ,
( unsigned char ) ( V_1 -> V_431 >> 16 ) ) ;
V_1 -> V_289 |= V_525 + V_526 ;
F_79 ( V_1 , V_292 , V_1 -> V_289 ) ;
V_136 = 0x10 ;
if ( ! ( V_1 -> V_47 & V_48 ) )
V_136 |= 0x01 ;
F_79 ( V_1 , V_138 , V_136 ) ;
F_169 ( V_1 ) ;
F_51 ( V_1 ) ;
F_154 ( V_1 ) ;
F_228 ( V_1 , V_1 -> V_56 . V_199 ) ;
if ( V_1 -> V_56 . V_200 )
F_226 ( V_1 , 1 ) ;
}
static void F_169 ( T_1 * V_1 )
{
unsigned char V_136 = 0xff ;
switch( V_1 -> V_368 ) {
case V_470 : V_136 = 0x7e ; break;
case V_536 : V_136 = 0xaa ; break;
case V_537 : V_136 = 0x00 ; break;
case V_538 : V_136 = 0xff ; break;
case V_539 : V_136 = 0xaa ; break;
case V_540 : V_136 = 0x00 ; break;
case V_541 : V_136 = 0xff ; break;
}
F_79 ( V_1 , V_542 , V_136 ) ;
}
static void F_67 ( T_1 * V_1 )
{
T_7 V_246 = F_78 ( V_1 , V_543 ) ;
T_7 V_544 = F_229 ( V_1 ) ;
T_7 V_545 ;
V_1 -> V_47 &= V_48 | V_49 ;
if ( ! ( V_246 & V_139 ) )
V_1 -> V_47 |= V_117 ;
if ( ! ( V_246 & V_334 ) )
V_1 -> V_47 |= V_119 ;
V_545 = V_333 << ( V_1 -> V_239 * 2 ) ;
if ( ! ( V_544 & V_545 ) )
V_1 -> V_47 |= V_120 ;
V_545 = V_268 << ( V_1 -> V_239 * 2 ) ;
if ( ! ( V_544 & V_545 ) )
V_1 -> V_47 |= V_118 ;
}
static void F_31 ( T_1 * V_1 )
{
unsigned char V_136 ;
T_7 V_546 ;
V_136 = F_78 ( V_1 , V_138 ) ;
if ( V_1 -> V_47 & V_48 )
V_136 &= ~ V_268 ;
else
V_136 |= V_268 ;
F_79 ( V_1 , V_138 , V_136 ) ;
V_546 = V_333 << ( V_1 -> V_239 * 2 ) ;
if ( V_1 -> V_47 & V_49 )
V_1 -> V_332 [ 0 ] -> V_499 &= ~ V_546 ;
else
V_1 -> V_332 [ 0 ] -> V_499 |= V_546 ;
F_227 ( V_1 ) ;
}
static void F_191 ( T_1 * V_1 )
{
F_231 ( V_1 , 0 , V_1 -> V_424 - 1 ) ;
}
static void F_231 ( T_1 * V_1 , unsigned int V_547 , unsigned int V_548 )
{
bool V_549 = false ;
while( ! V_549 ) {
V_1 -> V_425 [ V_547 ] . V_246 = 0xff ;
if ( V_547 == V_548 ) {
V_549 = true ;
F_130 ( V_1 , V_298 + V_510 , V_1 -> V_426 [ V_547 ] . V_432 ) ;
}
V_547 ++ ;
if ( V_547 == V_1 -> V_424 )
V_547 = 0 ;
}
V_1 -> V_508 = V_547 ;
}
static bool F_121 ( T_1 * V_1 )
{
unsigned int V_550 , V_551 ;
unsigned short V_246 ;
unsigned int V_552 = 0 ;
bool V_553 = false ;
unsigned long V_11 ;
struct V_8 * V_9 = V_1 -> V_27 . V_9 ;
unsigned char V_554 = 0xff ;
V_421 * V_555 ;
T_10 * V_556 ;
V_557:
V_552 = 0 ;
V_554 = 0xff ;
V_550 = V_551 = V_1 -> V_508 ;
for ( ; ; ) {
V_555 = & V_1 -> V_425 [ V_551 ] ;
V_556 = & V_1 -> V_426 [ V_551 ] ;
if ( V_555 -> V_246 == 0xff )
goto V_558;
if ( V_552 == 0 && V_1 -> V_56 . V_559 != 0xff )
V_554 = V_556 -> V_438 [ 0 ] ;
V_552 += V_555 -> V_434 ;
if ( V_555 -> V_246 )
break;
V_551 ++ ;
if ( V_551 == V_1 -> V_424 )
V_551 = 0 ;
if ( V_551 == V_1 -> V_508 ) {
if ( V_1 -> V_371 ) {
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_157 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
goto V_558;
}
}
V_246 = V_555 -> V_246 ;
if ( V_1 -> V_56 . V_161 == V_156 )
V_246 &= ~ V_334 ;
if ( V_552 == 0 ||
( V_554 != 0xff && V_554 != V_1 -> V_56 . V_559 ) ) {
F_231 ( V_1 , V_550 , V_551 ) ;
goto V_557;
}
if ( V_552 < 2 )
V_246 |= V_338 ;
if ( V_246 & ( V_338 + V_335 + V_139 + V_334 ) ) {
if ( V_246 & V_338 )
V_1 -> V_95 . V_125 ++ ;
else if ( V_246 & V_335 )
V_1 -> V_95 . V_560 ++ ;
else if ( V_246 & V_139 )
V_1 -> V_95 . V_127 ++ ;
else
V_1 -> V_95 . V_128 ++ ;
V_552 = 0 ;
#if V_294
{
V_1 -> V_206 -> V_166 . V_561 ++ ;
V_1 -> V_206 -> V_166 . V_562 ++ ;
}
#endif
}
if ( V_31 >= V_233 )
F_4 ( L_160 ,
__FILE__ , __LINE__ , V_1 -> V_25 , V_246 , V_552 ) ;
if ( V_31 >= V_563 )
F_232 ( V_1 , V_1 -> V_426 [ V_550 ] . V_438 ,
F_37 (unsigned int, framesize, SCABUFSIZE) , 0 ) ;
if ( V_552 ) {
if ( V_552 > V_1 -> V_59 )
V_1 -> V_95 . V_126 ++ ;
else {
int V_564 = V_552 ;
int V_19 = V_550 ;
unsigned char * V_565 = V_1 -> V_441 ;
V_1 -> V_566 = V_552 ;
V_1 -> V_95 . V_122 ++ ;
while( V_564 ) {
int V_567 = F_38 ( V_564 , V_419 ) ;
memcpy ( V_565 ,
V_1 -> V_426 [ V_19 ] . V_438 ,
V_567 ) ;
V_565 += V_567 ;
V_564 -= V_567 ;
if ( ++ V_19 == V_1 -> V_424 )
V_19 = 0 ;
}
#if V_294
if ( V_1 -> V_36 )
F_103 ( V_1 , V_1 -> V_441 , V_552 ) ;
else
#endif
F_5 ( V_9 , V_1 -> V_441 ,
V_1 -> V_442 , V_552 ) ;
}
}
F_231 ( V_1 , V_550 , V_551 ) ;
V_553 = true ;
V_558:
if ( V_1 -> V_371 && V_1 -> V_299 ) {
if ( V_1 -> V_425 [ V_551 ] . V_246 == 0xff ) {
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_157 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
}
}
return V_553 ;
}
static void F_36 ( T_1 * V_1 , const char * V_52 , unsigned int V_12 )
{
unsigned short V_564 ;
unsigned int V_326 = 0 ;
V_421 * V_555 ;
T_10 * V_556 ;
if ( V_31 >= V_563 )
F_232 ( V_1 , V_52 , F_37 (unsigned int, count, SCABUFSIZE) , 1 ) ;
for( V_326 = 0 ; ; )
{
V_564 = F_37 (unsigned int, count, SCABUFSIZE) ;
V_555 = & V_1 -> V_427 [ V_326 ] ;
V_556 = & V_1 -> V_428 [ V_326 ] ;
F_233 ( V_1 , V_556 -> V_438 , V_52 , V_564 ) ;
V_555 -> V_434 = V_564 ;
V_555 -> V_246 = 0 ;
V_52 += V_564 ;
V_12 -= V_564 ;
if ( ! V_12 )
break;
V_326 ++ ;
if ( V_326 >= V_1 -> V_422 )
V_326 = 0 ;
}
V_1 -> V_427 [ V_326 ] . V_246 = 0x81 ;
V_1 -> V_516 = ++ V_326 ;
}
static bool F_234 ( T_1 * V_1 )
{
static unsigned char V_568 [] = { 0x00 , 0xff , 0xaa , 0x55 , 0x69 , 0x96 } ;
static unsigned int V_12 = F_235 ( V_568 ) ;
unsigned int V_326 ;
bool V_170 = true ;
unsigned long V_11 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_147 ( V_1 ) ;
V_1 -> V_24 = V_569 ;
for ( V_326 = 0 ; V_326 < V_12 ; V_326 ++ ) {
F_79 ( V_1 , V_505 , V_568 [ V_326 ] ) ;
F_79 ( V_1 , V_542 , V_568 [ ( V_326 + 1 ) % V_12 ] ) ;
F_79 ( V_1 , V_570 , V_568 [ ( V_326 + 2 ) % V_12 ] ) ;
F_79 ( V_1 , V_571 , V_568 [ ( V_326 + 3 ) % V_12 ] ) ;
if ( ( F_78 ( V_1 , V_505 ) != V_568 [ V_326 ] ) ||
( F_78 ( V_1 , V_542 ) != V_568 [ ( V_326 + 1 ) % V_12 ] ) ||
( F_78 ( V_1 , V_570 ) != V_568 [ ( V_326 + 2 ) % V_12 ] ) ||
( F_78 ( V_1 , V_571 ) != V_568 [ ( V_326 + 3 ) % V_12 ] ) )
{
V_170 = false ;
break;
}
}
F_147 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
return V_170 ;
}
static bool F_236 ( T_1 * V_1 )
{
unsigned long V_40 ;
unsigned long V_11 ;
unsigned char V_238 = ( V_1 -> V_239 & 1 ) ? V_240 : V_241 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_147 ( V_1 ) ;
V_1 -> V_24 = V_572 ;
V_1 -> V_244 = false ;
F_79 ( V_1 , V_242 , ( unsigned char ) ( ( V_1 -> V_239 & 1 ) ? V_338 : V_336 ) ) ;
F_79 ( V_1 , ( unsigned char ) ( V_238 + V_573 ) , 0 ) ;
F_130 ( V_1 , ( unsigned char ) ( V_238 + V_574 ) , 1 ) ;
F_79 ( V_1 , ( unsigned char ) ( V_238 + V_243 ) , 0x50 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
V_40 = 100 ;
while( V_40 -- && ! V_1 -> V_244 ) {
F_42 ( 10 ) ;
}
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_147 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
return V_1 -> V_244 ;
}
static bool F_237 ( T_1 * V_1 )
{
F_79 ( V_1 , V_575 , 0 ) ;
F_79 ( V_1 , V_576 , 0 ) ;
F_79 ( V_1 , V_577 , 0 ) ;
F_79 ( V_1 , V_578 , 0 ) ;
F_79 ( V_1 , V_579 , 0 ) ;
F_79 ( V_1 , V_580 , V_581 ) ;
F_79 ( V_1 , V_582 , 0x80 ) ;
F_79 ( V_1 , V_583 , 0xff ) ;
F_79 ( V_1 , V_584 , 0xff ) ;
F_79 ( V_1 , V_242 , 0xf0 ) ;
F_79 ( V_1 , V_585 , 0 ) ;
return true ;
}
static bool F_238 ( T_1 * V_1 )
{
int V_326 ;
volatile T_13 * V_586 = ( T_13 * ) ( V_1 -> V_454 + 0x50 ) ;
T_13 V_587 ;
V_1 -> V_477 |= V_588 ;
* V_586 = V_1 -> V_477 ;
for( V_326 = 0 ; V_326 < 10 ; V_326 ++ )
V_587 = * V_586 ;
V_1 -> V_477 &= ~ V_588 ;
* V_586 = V_1 -> V_477 ;
V_1 -> V_499 = 0xaa ;
F_227 ( V_1 ) ;
{
volatile T_13 * V_589 = ( T_13 * ) ( V_1 -> V_454 + 0x2c ) ;
V_590 &= ~ ( V_335 + V_336 + V_139 ) ;
switch( V_591 )
{
case 16 :
V_590 |= V_335 + V_336 + V_139 ;
break;
case 8 :
V_590 |= V_335 + V_336 ;
break;
case 4 :
V_590 |= V_335 + V_139 ;
break;
case 0 :
V_590 |= V_335 ;
break;
}
* V_589 = V_590 ;
* V_586 = V_477 ;
}
F_237 ( V_1 -> V_332 [ 0 ] ) ;
F_237 ( V_1 -> V_332 [ 2 ] ) ;
return true ;
}
static bool F_239 ( T_1 * V_1 )
{
#define F_240 20
unsigned long V_40 ;
T_7 V_12 = F_240 ;
unsigned char V_52 [ F_240 ] ;
bool V_170 = false ;
unsigned long V_11 ;
struct V_8 * V_592 = V_1 -> V_27 . V_9 ;
T_13 V_593 = V_1 -> V_56 . V_199 ;
V_1 -> V_56 . V_199 = 3686400 ;
V_1 -> V_27 . V_9 = NULL ;
V_1 -> V_24 = V_594 ;
for ( V_12 = 0 ; V_12 < F_240 ; ++ V_12 )
V_52 [ V_12 ] = ( unsigned char ) V_12 ;
memset ( V_1 -> V_441 , 0 , F_240 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_155 ( V_1 ) ;
F_226 ( V_1 , 1 ) ;
F_157 ( V_1 ) ;
V_1 -> V_62 = V_12 ;
F_36 ( V_1 , V_52 , V_12 ) ;
F_39 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
for ( V_40 = 100 ; V_40 ; -- V_40 ) {
F_42 ( 10 ) ;
if ( F_121 ( V_1 ) ) {
V_170 = true ;
break;
}
}
if ( V_170 &&
( V_1 -> V_566 != V_12 ||
memcmp ( V_52 , V_1 -> V_441 , V_12 ) ) ) {
V_170 = false ;
}
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_230 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_56 . V_199 = V_593 ;
V_1 -> V_27 . V_9 = V_592 ;
return V_170 ;
}
static int F_214 ( T_1 * V_1 )
{
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_161 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_238 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_332 [ 0 ] -> V_331 = 0 ;
if ( F_234 ( V_1 -> V_332 [ 0 ] ) &&
F_234 ( V_1 -> V_332 [ 1 ] ) ) {
V_1 -> V_332 [ 0 ] -> V_331 = 2 ;
if ( F_234 ( V_1 -> V_332 [ 2 ] ) &&
F_234 ( V_1 -> V_332 [ 3 ] ) )
V_1 -> V_332 [ 0 ] -> V_331 += 2 ;
}
else {
F_4 ( L_162 ,
__FILE__ , __LINE__ , V_1 -> V_25 , ( unsigned long ) ( V_1 -> V_112 ) ) ;
return - V_21 ;
}
if ( ! F_236 ( V_1 -> V_332 [ 0 ] ) ||
! F_236 ( V_1 -> V_332 [ 1 ] ) ||
( V_1 -> V_331 == 4 && ! F_236 ( V_1 -> V_332 [ 2 ] ) ) ||
( V_1 -> V_331 == 4 && ! F_236 ( V_1 -> V_332 [ 3 ] ) ) ) {
F_4 ( L_163 ,
__FILE__ , __LINE__ , V_1 -> V_25 , ( unsigned short ) ( V_1 -> V_116 ) ) ;
return - V_21 ;
}
if ( ! F_239 ( V_1 -> V_332 [ 0 ] ) ||
! F_239 ( V_1 -> V_332 [ 1 ] ) ||
( V_1 -> V_331 == 4 && ! F_239 ( V_1 -> V_332 [ 2 ] ) ) ||
( V_1 -> V_331 == 4 && ! F_239 ( V_1 -> V_332 [ 3 ] ) ) ) {
F_4 ( L_164 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
return - V_21 ;
}
if ( V_31 >= V_32 )
F_4 ( L_165 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
V_1 -> V_332 [ 0 ] -> V_24 = 0 ;
V_1 -> V_332 [ 1 ] -> V_24 = 0 ;
if ( V_1 -> V_331 > 2 ) {
V_1 -> V_332 [ 2 ] -> V_24 = 0 ;
V_1 -> V_332 [ 3 ] -> V_24 = 0 ;
}
return 0 ;
}
static bool F_198 ( T_1 * V_1 )
{
static unsigned long V_568 [] = { 0x0 , 0x55555555 , 0xaaaaaaaa ,
0x66666666 , 0x99999999 , 0xffffffff , 0x12345678 } ;
unsigned long V_12 = F_235 ( V_568 ) ;
unsigned long V_326 ;
unsigned long V_595 = V_418 /sizeof( unsigned long ) ;
unsigned long * V_596 = ( unsigned long * ) V_1 -> V_430 ;
for ( V_326 = 0 ; V_326 < V_12 ; V_326 ++ ) {
* V_596 = V_568 [ V_326 ] ;
if ( * V_596 != V_568 [ V_326 ] )
return false ;
}
for ( V_326 = 0 ; V_326 < V_595 ; V_326 ++ ) {
* V_596 = V_326 * 4 ;
V_596 ++ ;
}
V_596 = ( unsigned long * ) V_1 -> V_430 ;
for ( V_326 = 0 ; V_326 < V_595 ; V_326 ++ ) {
if ( * V_596 != V_326 * 4 )
return false ;
V_596 ++ ;
}
memset ( V_1 -> V_430 , 0 , V_418 ) ;
return true ;
}
static void F_233 ( T_1 * V_1 , char * V_597 , const char * V_598 , unsigned short V_12 )
{
unsigned short V_599 = V_12 / V_600 ;
unsigned short V_326 ;
for ( V_326 = 0 ; V_326 < V_599 ; V_326 ++ )
{
memcpy ( V_597 , V_598 , V_600 ) ;
F_229 ( V_1 ) ;
V_597 += V_600 ;
V_598 += V_600 ;
}
memcpy ( V_597 , V_598 , V_12 % V_600 ) ;
}
static void F_232 ( T_1 * V_1 , const char * V_10 , int V_12 , int V_225 )
{
int V_326 ;
int V_601 ;
if ( V_225 )
F_4 ( L_166 , V_1 -> V_25 ) ;
else
F_4 ( L_167 , V_1 -> V_25 ) ;
while( V_12 ) {
if ( V_12 > 16 )
V_601 = 16 ;
else
V_601 = V_12 ;
for( V_326 = 0 ; V_326 < V_601 ; V_326 ++ )
F_4 ( L_168 , ( unsigned char ) V_10 [ V_326 ] ) ;
for(; V_326 < 17 ; V_326 ++ )
F_4 ( L_169 ) ;
for( V_326 = 0 ; V_326 < V_601 ; V_326 ++ ) {
if ( V_10 [ V_326 ] >= 040 && V_10 [ V_326 ] <= 0176 )
F_4 ( L_170 , V_10 [ V_326 ] ) ;
else
F_4 ( L_171 ) ;
}
F_4 ( L_172 ) ;
V_10 += V_601 ;
V_12 -= V_601 ;
}
}
static void V_475 ( unsigned long V_602 )
{
T_1 * V_1 = ( T_1 * ) V_602 ;
unsigned long V_11 ;
if ( V_31 >= V_32 )
F_4 ( L_173 ,
__FILE__ , __LINE__ , V_1 -> V_25 ) ;
if( V_1 -> V_61 && V_1 -> V_56 . V_57 == V_58 ) {
V_1 -> V_95 . V_603 ++ ;
}
F_11 ( & V_1 -> V_41 , V_11 ) ;
V_1 -> V_61 = false ;
V_1 -> V_62 = V_1 -> V_64 = V_1 -> V_75 = 0 ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
#if V_294
if ( V_1 -> V_36 )
F_101 ( V_1 ) ;
else
#endif
F_119 ( V_1 ) ;
}
static void V_476 ( unsigned long V_602 )
{
T_7 V_246 = 0 ;
T_1 * V_1 = ( T_1 * ) V_602 ;
unsigned long V_11 ;
unsigned char V_604 ;
F_11 ( & V_1 -> V_41 , V_11 ) ;
F_67 ( V_1 ) ;
F_12 ( & V_1 -> V_41 , V_11 ) ;
V_604 = V_1 -> V_605 ^ V_1 -> V_47 ;
V_1 -> V_605 = V_1 -> V_47 ;
if ( V_604 & V_118 )
V_246 |= V_302 | ( V_1 -> V_47 & V_118 ) ;
if ( V_604 & V_120 )
V_246 |= V_303 | ( V_1 -> V_47 & V_120 ) ;
if ( V_604 & V_119 )
V_246 |= V_265 | ( V_1 -> V_47 & V_119 ) ;
if ( V_604 & V_117 )
V_246 |= V_296 | ( V_1 -> V_47 & V_117 ) ;
if ( V_246 )
F_126 ( V_1 , V_246 ) ;
F_148 ( & V_1 -> V_341 , V_71 + F_149 ( 10 ) ) ;
}
static unsigned char F_78 ( T_1 * V_1 , unsigned char V_606 )
{
F_241 () ;
return * V_607 ;
}
static void F_79 ( T_1 * V_1 , unsigned char V_606 , unsigned char V_608 )
{
F_241 () ;
* V_607 = V_608 ;
}
static T_7 F_143 ( T_1 * V_1 , unsigned char V_606 )
{
F_241 () ;
return * ( ( T_7 * ) V_607 ) ;
}
static void F_130 ( T_1 * V_1 , unsigned char V_606 , T_7 V_608 )
{
F_241 () ;
* ( ( T_7 * ) V_607 ) = V_608 ;
}
static unsigned char F_229 ( T_1 * V_1 )
{
unsigned char * V_607 = ( unsigned char * ) V_1 -> V_457 ;
return * V_607 ;
}
static void F_227 ( T_1 * V_1 )
{
unsigned char * V_607 = ( unsigned char * ) V_1 -> V_457 ;
* V_607 = V_1 -> V_332 [ 0 ] -> V_499 ;
}
static int F_242 ( struct V_464 * V_141 ,
const struct V_609 * V_610 )
{
if ( F_243 ( V_141 ) ) {
F_4 ( L_174 , V_141 ) ;
return - V_60 ;
}
return F_211 ( ++ V_611 , V_141 ) ;
}
static void F_244 ( struct V_464 * V_141 )
{
}
