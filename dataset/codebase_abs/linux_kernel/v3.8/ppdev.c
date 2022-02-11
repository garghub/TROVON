static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
V_4 -> V_6 -> V_7 ( V_4 ) ;
}
static T_1 F_2 ( struct V_8 * V_8 , char T_2 * V_9 , T_3 V_10 ,
T_4 * V_11 )
{
unsigned int V_12 = F_3 ( V_8 -> V_13 . V_14 -> V_15 ) ;
struct V_1 * V_2 = V_8 -> V_16 ;
char * V_17 ;
T_1 V_18 = 0 ;
struct V_3 * V_19 ;
int V_20 ;
if ( ! ( V_2 -> V_21 & V_22 ) ) {
F_4 ( V_23 L_1 , V_12 ) ;
return - V_24 ;
}
if ( V_10 == 0 )
return 0 ;
V_17 = F_5 ( F_6 ( T_3 , V_10 , V_25 ) , V_26 ) ;
if ( ! V_17 ) {
return - V_27 ;
}
V_19 = V_2 -> V_5 -> V_4 ;
V_20 = V_19 -> V_28 . V_20 & ~ ( V_29 | V_30 ) ;
F_7 ( V_2 -> V_5 ,
( V_8 -> V_31 & V_32 ) ?
V_33 :
V_2 -> V_34 ) ;
while ( V_18 == 0 ) {
T_1 V_35 = F_6 (unsigned long, count, PP_BUFFER_SIZE) ;
if ( V_20 == V_36 ) {
int V_21 = 0 ;
T_3 (* F_8)( struct V_3 * , void * , T_3 , int );
if ( V_2 -> V_21 & V_37 ) {
V_21 |= V_38 ;
}
if ( V_2 -> V_21 & V_39 ) {
V_21 |= V_40 ;
}
if ( V_19 -> V_28 . V_20 & V_30 ) {
F_8 = V_19 -> V_6 -> V_41 ;
} else {
F_8 = V_19 -> V_6 -> V_42 ;
}
V_18 = (* F_8)( V_19 , V_17 , V_35 , V_21 ) ;
} else {
V_18 = F_9 ( V_19 , V_17 , V_35 ) ;
}
if ( V_18 != 0 )
break;
if ( V_8 -> V_31 & V_32 ) {
V_18 = - V_43 ;
break;
}
if ( F_10 ( V_44 ) ) {
V_18 = - V_45 ;
break;
}
F_11 () ;
}
F_7 ( V_2 -> V_5 , V_2 -> V_34 ) ;
if ( V_18 > 0 && F_12 ( V_9 , V_17 , V_18 ) )
V_18 = - V_46 ;
F_13 ( V_17 ) ;
F_1 ( V_2 ) ;
return V_18 ;
}
static T_1 F_14 ( struct V_8 * V_8 , const char T_2 * V_9 ,
T_3 V_10 , T_4 * V_11 )
{
unsigned int V_12 = F_3 ( V_8 -> V_13 . V_14 -> V_15 ) ;
struct V_1 * V_2 = V_8 -> V_16 ;
char * V_17 ;
T_1 V_47 = 0 ;
T_1 V_48 ;
int V_20 ;
struct V_3 * V_19 ;
if ( ! ( V_2 -> V_21 & V_22 ) ) {
F_4 ( V_23 L_1 , V_12 ) ;
return - V_24 ;
}
V_17 = F_5 ( F_6 ( T_3 , V_10 , V_25 ) , V_26 ) ;
if ( ! V_17 ) {
return - V_27 ;
}
V_19 = V_2 -> V_5 -> V_4 ;
V_20 = V_19 -> V_28 . V_20 & ~ ( V_29 | V_30 ) ;
F_7 ( V_2 -> V_5 ,
( V_8 -> V_31 & V_32 ) ?
V_33 :
V_2 -> V_34 ) ;
while ( V_47 < V_10 ) {
T_1 V_49 = F_6 (unsigned long, count - bytes_written, PP_BUFFER_SIZE) ;
if ( F_15 ( V_17 , V_9 + V_47 , V_49 ) ) {
V_47 = - V_46 ;
break;
}
if ( ( V_2 -> V_21 & V_50 ) && ( V_20 == V_36 ) ) {
if ( V_19 -> V_28 . V_20 & V_30 ) {
V_48 = V_19 -> V_6 -> V_51 ( V_19 ,
V_17 , V_49 , V_40 ) ;
} else {
V_48 = V_19 -> V_6 -> V_52 ( V_19 ,
V_17 , V_49 , V_40 ) ;
}
} else {
V_48 = F_16 ( V_2 -> V_5 -> V_4 , V_17 , V_49 ) ;
}
if ( V_48 <= 0 ) {
if ( ! V_47 ) {
V_47 = V_48 ;
}
break;
}
V_47 += V_48 ;
if ( V_8 -> V_31 & V_32 ) {
if ( ! V_47 )
V_47 = - V_43 ;
break;
}
if ( F_10 ( V_44 ) )
break;
F_11 () ;
}
F_7 ( V_2 -> V_5 , V_2 -> V_34 ) ;
F_13 ( V_17 ) ;
F_1 ( V_2 ) ;
return V_47 ;
}
static void F_17 ( void * V_53 )
{
struct V_1 * V_2 = V_53 ;
if ( V_2 -> V_54 ) {
F_18 ( V_2 -> V_5 -> V_4 , V_2 -> V_55 ) ;
V_2 -> V_54 = 0 ;
}
F_19 ( & V_2 -> V_56 ) ;
F_20 ( & V_2 -> V_57 ) ;
}
static int F_21 ( int V_12 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_58 * V_5 = NULL ;
char * V_59 ;
int V_60 ;
V_59 = F_22 ( V_26 , V_23 L_2 , V_12 ) ;
if ( V_59 == NULL )
return - V_27 ;
V_4 = F_23 ( V_12 ) ;
if ( ! V_4 ) {
F_24 ( V_61 L_3 , V_59 ) ;
F_13 ( V_59 ) ;
return - V_62 ;
}
V_60 = ( V_2 -> V_21 & V_63 ) ? V_64 : 0 ;
V_5 = F_25 ( V_4 , V_59 , NULL ,
NULL , F_17 , V_60 , V_2 ) ;
F_26 ( V_4 ) ;
if ( ! V_5 ) {
F_24 ( V_61 L_4 , V_59 ) ;
F_13 ( V_59 ) ;
return - V_62 ;
}
V_2 -> V_5 = V_5 ;
F_4 ( L_5 , V_59 ) ;
return 0 ;
}
static enum V_65 F_27 ( int V_20 )
{
switch ( V_20 & ~ ( V_29
| V_30 ) ) {
case V_66 :
case V_67 :
return V_68 ;
}
return V_69 ;
}
static int F_28 ( struct V_8 * V_8 , unsigned int V_70 , unsigned long V_71 )
{
unsigned int V_12 = F_3 ( V_8 -> V_13 . V_14 -> V_15 ) ;
struct V_1 * V_2 = V_8 -> V_16 ;
struct V_3 * V_4 ;
void T_2 * V_72 = ( void T_2 * ) V_71 ;
switch ( V_70 ) {
case V_73 :
{
struct V_74 * V_75 ;
int V_76 ;
if ( V_2 -> V_21 & V_22 ) {
F_4 ( V_23 L_6 , V_12 ) ;
return - V_24 ;
}
if ( ! V_2 -> V_5 ) {
int V_77 = F_21 ( V_12 , V_2 ) ;
if ( V_77 ) {
return V_77 ;
}
}
V_76 = F_29 ( V_2 -> V_5 ) ;
if ( V_76 < 0 )
return V_76 ;
V_2 -> V_21 |= V_22 ;
F_1 ( V_2 ) ;
V_75 = & V_2 -> V_5 -> V_4 -> V_28 ;
V_2 -> V_78 . V_20 = V_75 -> V_20 ;
V_2 -> V_78 . V_79 = V_75 -> V_79 ;
V_75 -> V_20 = V_2 -> V_80 . V_20 ;
V_75 -> V_79 = V_2 -> V_80 . V_79 ;
V_2 -> V_34 = F_7 ( V_2 -> V_5 , 0 ) ;
F_7 ( V_2 -> V_5 , V_2 -> V_34 ) ;
return 0 ;
}
case V_81 :
if ( V_2 -> V_5 ) {
F_4 ( V_23 L_7
L_8 , V_12 ) ;
if ( V_2 -> V_21 & V_63 )
return 0 ;
return - V_24 ;
}
V_2 -> V_21 |= V_63 ;
return 0 ;
case V_82 :
{
int V_20 ;
if ( F_15 ( & V_20 , V_72 , sizeof ( V_20 ) ) )
return - V_46 ;
V_2 -> V_80 . V_20 = V_20 ;
V_2 -> V_80 . V_79 = F_27 ( V_20 ) ;
if ( V_2 -> V_21 & V_22 ) {
V_2 -> V_5 -> V_4 -> V_28 . V_20 = V_20 ;
V_2 -> V_5 -> V_4 -> V_28 . V_79 = V_2 -> V_80 . V_79 ;
}
return 0 ;
}
case V_83 :
{
int V_20 ;
if ( V_2 -> V_21 & V_22 ) {
V_20 = V_2 -> V_5 -> V_4 -> V_28 . V_20 ;
} else {
V_20 = V_2 -> V_80 . V_20 ;
}
if ( F_12 ( V_72 , & V_20 , sizeof ( V_20 ) ) ) {
return - V_46 ;
}
return 0 ;
}
case V_84 :
{
int V_79 ;
if ( F_15 ( & V_79 , V_72 , sizeof ( V_79 ) ) ) {
return - V_46 ;
}
V_2 -> V_80 . V_79 = V_79 ;
if ( V_2 -> V_21 & V_22 ) {
V_2 -> V_5 -> V_4 -> V_28 . V_79 = V_79 ;
}
return 0 ;
}
case V_85 :
{
int V_79 ;
if ( V_2 -> V_21 & V_22 ) {
V_79 = V_2 -> V_5 -> V_4 -> V_28 . V_79 ;
} else {
V_79 = V_2 -> V_80 . V_79 ;
}
if ( F_12 ( V_72 , & V_79 , sizeof ( V_79 ) ) ) {
return - V_46 ;
}
return 0 ;
}
case V_86 :
{
unsigned int V_87 ;
V_4 = F_23 ( V_12 ) ;
if ( ! V_4 )
return - V_88 ;
V_87 = V_4 -> V_87 ;
F_26 ( V_4 ) ;
if ( F_12 ( V_72 , & V_87 , sizeof ( V_87 ) ) ) {
return - V_46 ;
}
return 0 ;
}
case V_89 :
{
int V_90 ;
if ( F_15 ( & V_90 , V_72 , sizeof ( V_90 ) ) ) {
return - V_46 ;
}
V_2 -> V_21 &= ~ V_91 ;
V_2 -> V_21 |= ( V_90 & V_91 ) ;
return 0 ;
}
case V_92 :
{
int V_90 ;
V_90 = V_2 -> V_21 & V_91 ;
if ( F_12 ( V_72 , & V_90 , sizeof ( V_90 ) ) ) {
return - V_46 ;
}
return 0 ;
}
}
if ( ( V_2 -> V_21 & V_22 ) == 0 ) {
F_4 ( V_23 L_1 , V_12 ) ;
return - V_24 ;
}
V_4 = V_2 -> V_5 -> V_4 ;
switch ( V_70 ) {
struct V_74 * V_75 ;
unsigned char V_93 ;
unsigned char V_94 ;
int V_20 ;
int V_76 ;
struct V_95 V_96 ;
long V_97 ;
case V_98 :
V_93 = F_30 ( V_4 ) ;
if ( F_12 ( V_72 , & V_93 , sizeof ( V_93 ) ) )
return - V_46 ;
return 0 ;
case V_99 :
V_93 = F_31 ( V_4 ) ;
if ( F_12 ( V_72 , & V_93 , sizeof ( V_93 ) ) )
return - V_46 ;
return 0 ;
case V_100 :
V_93 = F_32 ( V_4 ) ;
if ( F_12 ( V_72 , & V_93 , sizeof ( V_93 ) ) )
return - V_46 ;
return 0 ;
case V_101 :
F_33 ( V_2 -> V_5 ) ;
return 0 ;
case V_102 :
V_75 = & V_2 -> V_5 -> V_4 -> V_28 ;
V_2 -> V_80 . V_20 = V_75 -> V_20 ;
V_2 -> V_80 . V_79 = V_75 -> V_79 ;
V_75 -> V_20 = V_2 -> V_78 . V_20 ;
V_75 -> V_79 = V_2 -> V_78 . V_79 ;
F_34 ( V_2 -> V_5 ) ;
V_2 -> V_21 &= ~ V_22 ;
return 0 ;
case V_103 :
if ( F_15 ( & V_93 , V_72 , sizeof ( V_93 ) ) )
return - V_46 ;
F_18 ( V_4 , V_93 ) ;
return 0 ;
case V_104 :
if ( F_15 ( & V_93 , V_72 , sizeof ( V_93 ) ) )
return - V_46 ;
F_35 ( V_4 , V_93 ) ;
return 0 ;
case V_105 :
if ( F_15 ( & V_94 , V_72 ,
sizeof ( V_94 ) ) )
return - V_46 ;
if ( F_15 ( & V_93 , 1 + ( unsigned char T_2 * ) V_71 ,
sizeof ( V_93 ) ) )
return - V_46 ;
F_36 ( V_4 , V_94 , V_93 ) ;
return 0 ;
case V_106 :
if ( F_15 ( & V_20 , V_72 , sizeof ( V_20 ) ) )
return - V_46 ;
if ( V_20 )
V_4 -> V_6 -> V_107 ( V_4 ) ;
else
V_4 -> V_6 -> V_108 ( V_4 ) ;
return 0 ;
case V_109 :
if ( F_15 ( & V_20 , V_72 , sizeof ( V_20 ) ) )
return - V_46 ;
switch ( ( V_76 = F_37 ( V_4 , V_20 ) ) ) {
case 0 : break;
case - 1 :
V_76 = - V_110 ;
break;
case 1 :
V_76 = - V_62 ;
break;
}
F_1 ( V_2 ) ;
return V_76 ;
case V_111 :
if ( F_15 ( & V_93 , V_72 , sizeof ( V_93 ) ) )
return - V_46 ;
V_2 -> V_55 = V_93 ;
V_2 -> V_54 = 1 ;
return 0 ;
case V_112 :
V_76 = F_38 ( & V_2 -> V_56 ) ;
if ( F_12 ( V_72 , & V_76 , sizeof ( V_76 ) ) )
return - V_46 ;
F_39 ( V_76 , & V_2 -> V_56 ) ;
return 0 ;
case V_113 :
if ( F_15 ( & V_96 , V_72 , sizeof( struct V_95 ) ) ) {
return - V_46 ;
}
if ( ( V_96 . V_114 < 0 ) || ( V_96 . V_115 < 0 ) ) {
return - V_24 ;
}
V_97 = F_40 ( V_96 . V_115 , 1000000 / V_116 ) ;
V_97 += V_96 . V_114 * ( long ) V_116 ;
if ( V_97 <= 0 ) {
return - V_24 ;
}
V_2 -> V_5 -> V_117 = V_97 ;
return 0 ;
case V_118 :
V_97 = V_2 -> V_5 -> V_117 ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_114 = V_97 / V_116 ;
V_96 . V_115 = ( V_97 % ( long ) V_116 ) * ( 1000000 / V_116 ) ;
if ( F_12 ( V_72 , & V_96 , sizeof( struct V_95 ) ) )
return - V_46 ;
return 0 ;
default:
F_4 ( V_23 L_9 , V_12 , V_70 ) ;
return - V_24 ;
}
return 0 ;
}
static long F_41 ( struct V_8 * V_8 , unsigned int V_70 , unsigned long V_71 )
{
long V_76 ;
F_42 ( & V_119 ) ;
V_76 = F_28 ( V_8 , V_70 , V_71 ) ;
F_43 ( & V_119 ) ;
return V_76 ;
}
static int F_44 ( struct V_120 * V_120 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_120 ) ;
struct V_1 * V_2 ;
if ( V_12 >= V_121 )
return - V_62 ;
V_2 = F_5 ( sizeof ( struct V_1 ) , V_26 ) ;
if ( ! V_2 )
return - V_27 ;
V_2 -> V_80 . V_20 = V_122 ;
V_2 -> V_80 . V_79 = F_27 ( V_2 -> V_80 . V_20 ) ;
V_2 -> V_21 = 0 ;
V_2 -> V_54 = 0 ;
F_45 ( & V_2 -> V_56 , 0 ) ;
F_46 ( & V_2 -> V_57 ) ;
V_2 -> V_5 = NULL ;
V_8 -> V_16 = V_2 ;
return 0 ;
}
static int F_47 ( struct V_120 * V_120 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_120 ) ;
struct V_1 * V_2 = V_8 -> V_16 ;
int V_123 ;
V_123 = 0 ;
if ( ! ( V_2 -> V_21 & V_22 ) && V_2 -> V_5 &&
( V_2 -> V_80 . V_20 != V_122 ) ) {
struct V_74 * V_75 ;
F_29 ( V_2 -> V_5 ) ;
V_2 -> V_21 |= V_22 ;
V_75 = & V_2 -> V_5 -> V_4 -> V_28 ;
V_2 -> V_78 . V_20 = V_75 -> V_20 ;
V_2 -> V_78 . V_79 = V_75 -> V_79 ;
V_75 -> V_20 = V_2 -> V_80 . V_20 ;
V_75 -> V_79 = V_2 -> V_80 . V_79 ;
V_123 = 1 ;
} else if ( ( V_2 -> V_21 & V_22 ) && V_2 -> V_5 &&
( V_2 -> V_5 -> V_4 -> V_28 . V_20 != V_122 ) ) {
V_123 = 2 ;
}
if ( V_123 ) {
F_37 ( V_2 -> V_5 -> V_4 , V_122 ) ;
F_4 ( V_23 L_10
L_11 , V_12 ) ;
}
if ( V_2 -> V_21 & V_22 ) {
struct V_74 * V_75 ;
V_75 = & V_2 -> V_5 -> V_4 -> V_28 ;
V_2 -> V_80 . V_20 = V_75 -> V_20 ;
V_2 -> V_80 . V_79 = V_75 -> V_79 ;
V_75 -> V_20 = V_2 -> V_78 . V_20 ;
V_75 -> V_79 = V_2 -> V_78 . V_79 ;
F_34 ( V_2 -> V_5 ) ;
if ( V_123 != 1 ) {
F_4 ( V_23 L_12
L_13 , V_12 ) ;
}
}
if ( V_2 -> V_5 ) {
const char * V_59 = V_2 -> V_5 -> V_59 ;
F_48 ( V_2 -> V_5 ) ;
F_13 ( V_59 ) ;
V_2 -> V_5 = NULL ;
F_4 ( V_23 L_14 , V_12 ) ;
}
F_13 ( V_2 ) ;
return 0 ;
}
static unsigned int F_49 ( struct V_8 * V_8 , T_5 * V_124 )
{
struct V_1 * V_2 = V_8 -> V_16 ;
unsigned int V_94 = 0 ;
F_50 ( V_8 , & V_2 -> V_57 , V_124 ) ;
if ( F_38 ( & V_2 -> V_56 ) )
V_94 |= V_125 | V_126 ;
return V_94 ;
}
static void F_51 ( struct V_3 * V_4 )
{
F_52 ( V_127 , V_4 -> V_128 , F_53 ( V_129 , V_4 -> V_130 ) ,
NULL , L_15 , V_4 -> V_130 ) ;
}
static void F_54 ( struct V_3 * V_4 )
{
F_55 ( V_127 , F_53 ( V_129 , V_4 -> V_130 ) ) ;
}
static int T_6 F_56 ( void )
{
int V_77 = 0 ;
if ( F_57 ( V_129 , V_23 , & V_131 ) ) {
F_24 (KERN_WARNING CHRDEV L_16 ,
PP_MAJOR) ;
return - V_110 ;
}
V_127 = F_58 ( V_132 , V_23 ) ;
if ( F_59 ( V_127 ) ) {
V_77 = F_60 ( V_127 ) ;
goto V_133;
}
V_77 = F_61 ( & V_134 ) ;
if ( V_77 < 0 ) {
F_24 (KERN_WARNING CHRDEV L_17 ) ;
goto V_135;
}
F_24 (KERN_INFO PP_VERSION L_18 ) ;
goto V_136;
V_135:
F_62 ( V_127 ) ;
V_133:
F_63 ( V_129 , V_23 ) ;
V_136:
return V_77 ;
}
static void T_7 F_64 ( void )
{
F_65 ( & V_134 ) ;
F_62 ( V_127 ) ;
F_63 ( V_129 , V_23 ) ;
}
