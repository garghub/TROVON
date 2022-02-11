static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
V_4 -> V_6 -> V_7 ( V_4 ) ;
}
static T_1 F_2 ( struct V_8 * V_8 , char T_2 * V_9 , T_3 V_10 ,
T_4 * V_11 )
{
unsigned int V_12 = F_3 ( F_4 ( V_8 ) ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
char * V_14 ;
T_1 V_15 = 0 ;
struct V_3 * V_16 ;
int V_17 ;
if ( ! ( V_2 -> V_18 & V_19 ) ) {
F_5 ( V_20 L_1 , V_12 ) ;
return - V_21 ;
}
if ( V_10 == 0 )
return 0 ;
V_14 = F_6 ( F_7 ( T_3 , V_10 , V_22 ) , V_23 ) ;
if ( ! V_14 )
return - V_24 ;
V_16 = V_2 -> V_5 -> V_4 ;
V_17 = V_16 -> V_25 . V_17 & ~ ( V_26 | V_27 ) ;
F_8 ( V_2 -> V_5 ,
( V_8 -> V_28 & V_29 ) ?
V_30 :
V_2 -> V_31 ) ;
while ( V_15 == 0 ) {
T_1 V_32 = F_7 (unsigned long, count, PP_BUFFER_SIZE) ;
if ( V_17 == V_33 ) {
int V_18 = 0 ;
T_3 (* F_9)( struct V_3 * , void * , T_3 , int );
if ( V_2 -> V_18 & V_34 )
V_18 |= V_35 ;
if ( V_2 -> V_18 & V_36 )
V_18 |= V_37 ;
if ( V_16 -> V_25 . V_17 & V_27 )
F_9 = V_16 -> V_6 -> V_38 ;
else
F_9 = V_16 -> V_6 -> V_39 ;
V_15 = (* F_9)( V_16 , V_14 , V_32 , V_18 ) ;
} else {
V_15 = F_10 ( V_16 , V_14 , V_32 ) ;
}
if ( V_15 != 0 )
break;
if ( V_8 -> V_28 & V_29 ) {
V_15 = - V_40 ;
break;
}
if ( F_11 ( V_41 ) ) {
V_15 = - V_42 ;
break;
}
F_12 () ;
}
F_8 ( V_2 -> V_5 , V_2 -> V_31 ) ;
if ( V_15 > 0 && F_13 ( V_9 , V_14 , V_15 ) )
V_15 = - V_43 ;
F_14 ( V_14 ) ;
F_1 ( V_2 ) ;
return V_15 ;
}
static T_1 F_15 ( struct V_8 * V_8 , const char T_2 * V_9 ,
T_3 V_10 , T_4 * V_11 )
{
unsigned int V_12 = F_3 ( F_4 ( V_8 ) ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
char * V_14 ;
T_1 V_44 = 0 ;
T_1 V_45 ;
int V_17 ;
struct V_3 * V_16 ;
if ( ! ( V_2 -> V_18 & V_19 ) ) {
F_5 ( V_20 L_1 , V_12 ) ;
return - V_21 ;
}
V_14 = F_6 ( F_7 ( T_3 , V_10 , V_22 ) , V_23 ) ;
if ( ! V_14 )
return - V_24 ;
V_16 = V_2 -> V_5 -> V_4 ;
V_17 = V_16 -> V_25 . V_17 & ~ ( V_26 | V_27 ) ;
F_8 ( V_2 -> V_5 ,
( V_8 -> V_28 & V_29 ) ?
V_30 :
V_2 -> V_31 ) ;
while ( V_44 < V_10 ) {
T_1 V_46 = F_7 (unsigned long, count - bytes_written, PP_BUFFER_SIZE) ;
if ( F_16 ( V_14 , V_9 + V_44 , V_46 ) ) {
V_44 = - V_43 ;
break;
}
if ( ( V_2 -> V_18 & V_47 ) && ( V_17 == V_33 ) ) {
if ( V_16 -> V_25 . V_17 & V_27 ) {
V_45 = V_16 -> V_6 -> V_48 ( V_16 ,
V_14 , V_46 , V_37 ) ;
} else {
V_45 = V_16 -> V_6 -> V_49 ( V_16 ,
V_14 , V_46 , V_37 ) ;
}
} else {
V_45 = F_17 ( V_2 -> V_5 -> V_4 , V_14 , V_46 ) ;
}
if ( V_45 <= 0 ) {
if ( ! V_44 )
V_44 = V_45 ;
break;
}
V_44 += V_45 ;
if ( V_8 -> V_28 & V_29 ) {
if ( ! V_44 )
V_44 = - V_40 ;
break;
}
if ( F_11 ( V_41 ) )
break;
F_12 () ;
}
F_8 ( V_2 -> V_5 , V_2 -> V_31 ) ;
F_14 ( V_14 ) ;
F_1 ( V_2 ) ;
return V_44 ;
}
static void F_18 ( void * V_50 )
{
struct V_1 * V_2 = V_50 ;
if ( V_2 -> V_51 ) {
F_19 ( V_2 -> V_5 -> V_4 , V_2 -> V_52 ) ;
V_2 -> V_51 = 0 ;
}
F_20 ( & V_2 -> V_53 ) ;
F_21 ( & V_2 -> V_54 ) ;
}
static int F_22 ( int V_12 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_55 * V_5 = NULL ;
char * V_56 ;
int V_57 ;
V_56 = F_23 ( V_23 , V_20 L_2 , V_12 ) ;
if ( V_56 == NULL )
return - V_24 ;
V_4 = F_24 ( V_12 ) ;
if ( ! V_4 ) {
F_25 ( V_58 L_3 , V_56 ) ;
F_14 ( V_56 ) ;
return - V_59 ;
}
V_57 = ( V_2 -> V_18 & V_60 ) ? V_61 : 0 ;
V_5 = F_26 ( V_4 , V_56 , NULL ,
NULL , F_18 , V_57 , V_2 ) ;
F_27 ( V_4 ) ;
if ( ! V_5 ) {
F_25 ( V_58 L_4 , V_56 ) ;
F_14 ( V_56 ) ;
return - V_59 ;
}
V_2 -> V_5 = V_5 ;
F_28 ( & V_5 -> V_62 , L_5 ) ;
return 0 ;
}
static enum V_63 F_29 ( int V_17 )
{
switch ( V_17 & ~ ( V_26
| V_27 ) ) {
case V_64 :
case V_65 :
return V_66 ;
}
return V_67 ;
}
static int F_30 ( struct V_55 * V_5 , long V_68 , int V_69 )
{
long V_70 ;
if ( ( V_68 < 0 ) || ( V_69 < 0 ) )
return - V_21 ;
V_70 = F_31 ( V_69 ) ;
V_70 += V_68 * V_71 ;
if ( V_70 <= 0 )
return - V_21 ;
V_5 -> V_72 = V_70 ;
return 0 ;
}
static int F_32 ( struct V_8 * V_8 , unsigned int V_73 , unsigned long V_74 )
{
unsigned int V_12 = F_3 ( F_4 ( V_8 ) ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
struct V_3 * V_4 ;
void T_2 * V_75 = ( void T_2 * ) V_74 ;
switch ( V_73 ) {
case V_76 :
{
struct V_77 * V_78 ;
int V_79 ;
if ( V_2 -> V_18 & V_19 ) {
F_28 ( & V_2 -> V_5 -> V_62 , L_6 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_5 ) {
int V_80 = F_22 ( V_12 , V_2 ) ;
if ( V_80 )
return V_80 ;
}
V_79 = F_33 ( V_2 -> V_5 ) ;
if ( V_79 < 0 )
return V_79 ;
V_2 -> V_18 |= V_19 ;
F_1 ( V_2 ) ;
V_78 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_81 . V_17 = V_78 -> V_17 ;
V_2 -> V_81 . V_82 = V_78 -> V_82 ;
V_78 -> V_17 = V_2 -> V_83 . V_17 ;
V_78 -> V_82 = V_2 -> V_83 . V_82 ;
V_2 -> V_31 = F_8 ( V_2 -> V_5 , 0 ) ;
F_8 ( V_2 -> V_5 , V_2 -> V_31 ) ;
return 0 ;
}
case V_84 :
if ( V_2 -> V_5 ) {
F_28 ( & V_2 -> V_5 -> V_62 ,
L_7 ) ;
if ( V_2 -> V_18 & V_60 )
return 0 ;
return - V_21 ;
}
V_2 -> V_18 |= V_60 ;
return 0 ;
case V_85 :
{
int V_17 ;
if ( F_16 ( & V_17 , V_75 , sizeof( V_17 ) ) )
return - V_43 ;
V_2 -> V_83 . V_17 = V_17 ;
V_2 -> V_83 . V_82 = F_29 ( V_17 ) ;
if ( V_2 -> V_18 & V_19 ) {
V_2 -> V_5 -> V_4 -> V_25 . V_17 = V_17 ;
V_2 -> V_5 -> V_4 -> V_25 . V_82 = V_2 -> V_83 . V_82 ;
}
return 0 ;
}
case V_86 :
{
int V_17 ;
if ( V_2 -> V_18 & V_19 )
V_17 = V_2 -> V_5 -> V_4 -> V_25 . V_17 ;
else
V_17 = V_2 -> V_83 . V_17 ;
if ( F_13 ( V_75 , & V_17 , sizeof( V_17 ) ) )
return - V_43 ;
return 0 ;
}
case V_87 :
{
int V_82 ;
if ( F_16 ( & V_82 , V_75 , sizeof( V_82 ) ) )
return - V_43 ;
V_2 -> V_83 . V_82 = V_82 ;
if ( V_2 -> V_18 & V_19 )
V_2 -> V_5 -> V_4 -> V_25 . V_82 = V_82 ;
return 0 ;
}
case V_88 :
{
int V_82 ;
if ( V_2 -> V_18 & V_19 )
V_82 = V_2 -> V_5 -> V_4 -> V_25 . V_82 ;
else
V_82 = V_2 -> V_83 . V_82 ;
if ( F_13 ( V_75 , & V_82 , sizeof( V_82 ) ) )
return - V_43 ;
return 0 ;
}
case V_89 :
{
unsigned int V_90 ;
V_4 = F_24 ( V_12 ) ;
if ( ! V_4 )
return - V_91 ;
V_90 = V_4 -> V_90 ;
F_27 ( V_4 ) ;
if ( F_13 ( V_75 , & V_90 , sizeof( V_90 ) ) )
return - V_43 ;
return 0 ;
}
case V_92 :
{
int V_93 ;
if ( F_16 ( & V_93 , V_75 , sizeof( V_93 ) ) )
return - V_43 ;
V_2 -> V_18 &= ~ V_94 ;
V_2 -> V_18 |= ( V_93 & V_94 ) ;
return 0 ;
}
case V_95 :
{
int V_93 ;
V_93 = V_2 -> V_18 & V_94 ;
if ( F_13 ( V_75 , & V_93 , sizeof( V_93 ) ) )
return - V_43 ;
return 0 ;
}
}
if ( ( V_2 -> V_18 & V_19 ) == 0 ) {
F_5 ( V_20 L_1 , V_12 ) ;
return - V_21 ;
}
V_4 = V_2 -> V_5 -> V_4 ;
switch ( V_73 ) {
struct V_77 * V_78 ;
unsigned char V_96 ;
unsigned char V_97 ;
int V_17 ;
T_5 V_98 [ 2 ] ;
T_6 time64 [ 2 ] ;
struct V_99 V_100 ;
int V_79 ;
case V_101 :
V_96 = F_34 ( V_4 ) ;
if ( F_13 ( V_75 , & V_96 , sizeof( V_96 ) ) )
return - V_43 ;
return 0 ;
case V_102 :
V_96 = F_35 ( V_4 ) ;
if ( F_13 ( V_75 , & V_96 , sizeof( V_96 ) ) )
return - V_43 ;
return 0 ;
case V_103 :
V_96 = F_36 ( V_4 ) ;
if ( F_13 ( V_75 , & V_96 , sizeof( V_96 ) ) )
return - V_43 ;
return 0 ;
case V_104 :
F_37 ( V_2 -> V_5 ) ;
return 0 ;
case V_105 :
V_78 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_83 . V_17 = V_78 -> V_17 ;
V_2 -> V_83 . V_82 = V_78 -> V_82 ;
V_78 -> V_17 = V_2 -> V_81 . V_17 ;
V_78 -> V_82 = V_2 -> V_81 . V_82 ;
F_38 ( V_2 -> V_5 ) ;
V_2 -> V_18 &= ~ V_19 ;
return 0 ;
case V_106 :
if ( F_16 ( & V_96 , V_75 , sizeof( V_96 ) ) )
return - V_43 ;
F_19 ( V_4 , V_96 ) ;
return 0 ;
case V_107 :
if ( F_16 ( & V_96 , V_75 , sizeof( V_96 ) ) )
return - V_43 ;
F_39 ( V_4 , V_96 ) ;
return 0 ;
case V_108 :
if ( F_16 ( & V_97 , V_75 ,
sizeof( V_97 ) ) )
return - V_43 ;
if ( F_16 ( & V_96 , 1 + ( unsigned char T_2 * ) V_74 ,
sizeof( V_96 ) ) )
return - V_43 ;
F_40 ( V_4 , V_97 , V_96 ) ;
return 0 ;
case V_109 :
if ( F_16 ( & V_17 , V_75 , sizeof( V_17 ) ) )
return - V_43 ;
if ( V_17 )
V_4 -> V_6 -> V_110 ( V_4 ) ;
else
V_4 -> V_6 -> V_111 ( V_4 ) ;
return 0 ;
case V_112 :
if ( F_16 ( & V_17 , V_75 , sizeof( V_17 ) ) )
return - V_43 ;
switch ( ( V_79 = F_41 ( V_4 , V_17 ) ) ) {
case 0 : break;
case - 1 :
V_79 = - V_113 ;
break;
case 1 :
V_79 = - V_59 ;
break;
}
F_1 ( V_2 ) ;
return V_79 ;
case V_114 :
if ( F_16 ( & V_96 , V_75 , sizeof( V_96 ) ) )
return - V_43 ;
V_2 -> V_52 = V_96 ;
V_2 -> V_51 = 1 ;
return 0 ;
case V_115 :
V_79 = F_42 ( & V_2 -> V_53 ) ;
if ( F_13 ( V_75 , & V_79 , sizeof( V_79 ) ) )
return - V_43 ;
F_43 ( V_79 , & V_2 -> V_53 ) ;
return 0 ;
case V_116 :
if ( F_16 ( V_98 , V_75 , sizeof( V_98 ) ) )
return - V_43 ;
return F_30 ( V_2 -> V_5 , V_98 [ 0 ] , V_98 [ 1 ] ) ;
case V_117 :
if ( F_16 ( time64 , V_75 , sizeof( time64 ) ) )
return - V_43 ;
return F_30 ( V_2 -> V_5 , time64 [ 0 ] , time64 [ 1 ] ) ;
case V_118 :
F_44 ( V_2 -> V_5 -> V_72 , & V_100 ) ;
V_98 [ 0 ] = V_100 . V_68 ;
V_98 [ 1 ] = V_100 . V_119 / V_120 ;
if ( ( V_98 [ 0 ] < 0 ) || ( V_98 [ 1 ] < 0 ) )
return - V_21 ;
if ( F_13 ( V_75 , V_98 , sizeof( V_98 ) ) )
return - V_43 ;
return 0 ;
case V_121 :
F_44 ( V_2 -> V_5 -> V_72 , & V_100 ) ;
time64 [ 0 ] = V_100 . V_68 ;
time64 [ 1 ] = V_100 . V_119 / V_120 ;
if ( ( time64 [ 0 ] < 0 ) || ( time64 [ 1 ] < 0 ) )
return - V_21 ;
if ( F_13 ( V_75 , time64 , sizeof( time64 ) ) )
return - V_43 ;
return 0 ;
default:
F_28 ( & V_2 -> V_5 -> V_62 , L_8 , V_73 ) ;
return - V_21 ;
}
return 0 ;
}
static long F_45 ( struct V_8 * V_8 , unsigned int V_73 , unsigned long V_74 )
{
long V_79 ;
F_46 ( & V_122 ) ;
V_79 = F_32 ( V_8 , V_73 , V_74 ) ;
F_47 ( & V_122 ) ;
return V_79 ;
}
static long F_48 ( struct V_8 * V_8 , unsigned int V_73 ,
unsigned long V_74 )
{
return F_45 ( V_8 , V_73 , ( unsigned long ) F_49 ( V_74 ) ) ;
}
static int F_50 ( struct V_123 * V_123 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_123 ) ;
struct V_1 * V_2 ;
if ( V_12 >= V_124 )
return - V_59 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_83 . V_17 = V_125 ;
V_2 -> V_83 . V_82 = F_29 ( V_2 -> V_83 . V_17 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_51 = 0 ;
F_51 ( & V_2 -> V_53 , 0 ) ;
F_52 ( & V_2 -> V_54 ) ;
V_2 -> V_5 = NULL ;
V_8 -> V_13 = V_2 ;
return 0 ;
}
static int F_53 ( struct V_123 * V_123 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_123 ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
int V_126 ;
V_126 = 0 ;
if ( ! ( V_2 -> V_18 & V_19 ) && V_2 -> V_5 &&
( V_2 -> V_83 . V_17 != V_125 ) ) {
struct V_77 * V_78 ;
F_33 ( V_2 -> V_5 ) ;
V_2 -> V_18 |= V_19 ;
V_78 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_81 . V_17 = V_78 -> V_17 ;
V_2 -> V_81 . V_82 = V_78 -> V_82 ;
V_78 -> V_17 = V_2 -> V_83 . V_17 ;
V_78 -> V_82 = V_2 -> V_83 . V_82 ;
V_126 = 1 ;
} else if ( ( V_2 -> V_18 & V_19 ) && V_2 -> V_5 &&
( V_2 -> V_5 -> V_4 -> V_25 . V_17 != V_125 ) ) {
V_126 = 2 ;
}
if ( V_126 ) {
F_41 ( V_2 -> V_5 -> V_4 , V_125 ) ;
F_28 ( & V_2 -> V_5 -> V_62 ,
L_9 ) ;
}
if ( V_2 -> V_18 & V_19 ) {
struct V_77 * V_78 ;
V_78 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_83 . V_17 = V_78 -> V_17 ;
V_2 -> V_83 . V_82 = V_78 -> V_82 ;
V_78 -> V_17 = V_2 -> V_81 . V_17 ;
V_78 -> V_82 = V_2 -> V_81 . V_82 ;
F_38 ( V_2 -> V_5 ) ;
if ( V_126 != 1 ) {
F_5 ( V_20 L_10
L_11 , V_12 ) ;
}
}
if ( V_2 -> V_5 ) {
const char * V_56 = V_2 -> V_5 -> V_56 ;
F_54 ( V_2 -> V_5 ) ;
F_14 ( V_56 ) ;
V_2 -> V_5 = NULL ;
F_5 ( V_20 L_12 , V_12 ) ;
}
F_14 ( V_2 ) ;
return 0 ;
}
static unsigned int F_55 ( struct V_8 * V_8 , T_7 * V_127 )
{
struct V_1 * V_2 = V_8 -> V_13 ;
unsigned int V_97 = 0 ;
F_56 ( V_8 , & V_2 -> V_54 , V_127 ) ;
if ( F_42 ( & V_2 -> V_53 ) )
V_97 |= V_128 | V_129 ;
return V_97 ;
}
static void F_57 ( struct V_3 * V_4 )
{
F_58 ( V_130 , V_4 -> V_62 , F_59 ( V_131 , V_4 -> V_132 ) ,
NULL , L_13 , V_4 -> V_132 ) ;
}
static void F_60 ( struct V_3 * V_4 )
{
F_61 ( V_130 , F_59 ( V_131 , V_4 -> V_132 ) ) ;
}
static int T_8 F_62 ( void )
{
int V_80 = 0 ;
if ( F_63 ( V_131 , V_20 , & V_133 ) ) {
F_25 (KERN_WARNING CHRDEV L_14 ,
PP_MAJOR) ;
return - V_113 ;
}
V_130 = F_64 ( V_134 , V_20 ) ;
if ( F_65 ( V_130 ) ) {
V_80 = F_66 ( V_130 ) ;
goto V_135;
}
V_80 = F_67 ( & V_136 ) ;
if ( V_80 < 0 ) {
F_25 (KERN_WARNING CHRDEV L_15 ) ;
goto V_137;
}
F_25 (KERN_INFO PP_VERSION L_16 ) ;
goto V_138;
V_137:
F_68 ( V_130 ) ;
V_135:
F_69 ( V_131 , V_20 ) ;
V_138:
return V_80 ;
}
static void T_9 F_70 ( void )
{
F_71 ( & V_136 ) ;
F_68 ( V_130 ) ;
F_69 ( V_131 , V_20 ) ;
}
