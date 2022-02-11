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
struct V_57 V_58 ;
V_56 = F_23 ( V_23 , V_20 L_2 , V_12 ) ;
if ( V_56 == NULL )
return - V_24 ;
V_4 = F_24 ( V_12 ) ;
if ( ! V_4 ) {
F_25 ( V_59 L_3 , V_56 ) ;
F_14 ( V_56 ) ;
return - V_60 ;
}
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_61 = F_18 ;
V_58 . V_18 = ( V_2 -> V_18 & V_62 ) ? V_63 : 0 ;
V_58 . V_50 = V_2 ;
V_5 = F_26 ( V_4 , V_56 , & V_58 , V_12 ) ;
F_27 ( V_4 ) ;
if ( ! V_5 ) {
F_25 ( V_59 L_4 , V_56 ) ;
F_14 ( V_56 ) ;
return - V_60 ;
}
V_2 -> V_5 = V_5 ;
F_28 ( & V_5 -> V_64 , L_5 ) ;
return 0 ;
}
static enum V_65 F_29 ( int V_17 )
{
switch ( V_17 & ~ ( V_26
| V_27 ) ) {
case V_66 :
case V_67 :
return V_68 ;
}
return V_69 ;
}
static int F_30 ( struct V_55 * V_5 , long V_70 , int V_71 )
{
long V_72 ;
if ( ( V_70 < 0 ) || ( V_71 < 0 ) )
return - V_21 ;
V_72 = F_31 ( V_71 ) ;
V_72 += V_70 * V_73 ;
if ( V_72 <= 0 )
return - V_21 ;
V_5 -> V_74 = V_72 ;
return 0 ;
}
static int F_32 ( struct V_8 * V_8 , unsigned int V_75 , unsigned long V_76 )
{
unsigned int V_12 = F_3 ( F_4 ( V_8 ) ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
struct V_3 * V_4 ;
void T_2 * V_77 = ( void T_2 * ) V_76 ;
switch ( V_75 ) {
case V_78 :
{
struct V_79 * V_80 ;
int V_81 ;
if ( V_2 -> V_18 & V_19 ) {
F_28 ( & V_2 -> V_5 -> V_64 , L_6 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_5 ) {
int V_82 = F_22 ( V_12 , V_2 ) ;
if ( V_82 )
return V_82 ;
}
V_81 = F_33 ( V_2 -> V_5 ) ;
if ( V_81 < 0 )
return V_81 ;
V_2 -> V_18 |= V_19 ;
F_1 ( V_2 ) ;
V_80 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_83 . V_17 = V_80 -> V_17 ;
V_2 -> V_83 . V_84 = V_80 -> V_84 ;
V_80 -> V_17 = V_2 -> V_85 . V_17 ;
V_80 -> V_84 = V_2 -> V_85 . V_84 ;
V_2 -> V_31 = F_8 ( V_2 -> V_5 , 0 ) ;
F_8 ( V_2 -> V_5 , V_2 -> V_31 ) ;
return 0 ;
}
case V_86 :
if ( V_2 -> V_5 ) {
F_28 ( & V_2 -> V_5 -> V_64 ,
L_7 ) ;
if ( V_2 -> V_18 & V_62 )
return 0 ;
return - V_21 ;
}
V_2 -> V_18 |= V_62 ;
return 0 ;
case V_87 :
{
int V_17 ;
if ( F_16 ( & V_17 , V_77 , sizeof( V_17 ) ) )
return - V_43 ;
V_2 -> V_85 . V_17 = V_17 ;
V_2 -> V_85 . V_84 = F_29 ( V_17 ) ;
if ( V_2 -> V_18 & V_19 ) {
V_2 -> V_5 -> V_4 -> V_25 . V_17 = V_17 ;
V_2 -> V_5 -> V_4 -> V_25 . V_84 = V_2 -> V_85 . V_84 ;
}
return 0 ;
}
case V_88 :
{
int V_17 ;
if ( V_2 -> V_18 & V_19 )
V_17 = V_2 -> V_5 -> V_4 -> V_25 . V_17 ;
else
V_17 = V_2 -> V_85 . V_17 ;
if ( F_13 ( V_77 , & V_17 , sizeof( V_17 ) ) )
return - V_43 ;
return 0 ;
}
case V_89 :
{
int V_84 ;
if ( F_16 ( & V_84 , V_77 , sizeof( V_84 ) ) )
return - V_43 ;
V_2 -> V_85 . V_84 = V_84 ;
if ( V_2 -> V_18 & V_19 )
V_2 -> V_5 -> V_4 -> V_25 . V_84 = V_84 ;
return 0 ;
}
case V_90 :
{
int V_84 ;
if ( V_2 -> V_18 & V_19 )
V_84 = V_2 -> V_5 -> V_4 -> V_25 . V_84 ;
else
V_84 = V_2 -> V_85 . V_84 ;
if ( F_13 ( V_77 , & V_84 , sizeof( V_84 ) ) )
return - V_43 ;
return 0 ;
}
case V_91 :
{
unsigned int V_92 ;
V_4 = F_24 ( V_12 ) ;
if ( ! V_4 )
return - V_93 ;
V_92 = V_4 -> V_92 ;
F_27 ( V_4 ) ;
if ( F_13 ( V_77 , & V_92 , sizeof( V_92 ) ) )
return - V_43 ;
return 0 ;
}
case V_94 :
{
int V_95 ;
if ( F_16 ( & V_95 , V_77 , sizeof( V_95 ) ) )
return - V_43 ;
V_2 -> V_18 &= ~ V_96 ;
V_2 -> V_18 |= ( V_95 & V_96 ) ;
return 0 ;
}
case V_97 :
{
int V_95 ;
V_95 = V_2 -> V_18 & V_96 ;
if ( F_13 ( V_77 , & V_95 , sizeof( V_95 ) ) )
return - V_43 ;
return 0 ;
}
}
if ( ( V_2 -> V_18 & V_19 ) == 0 ) {
F_5 ( V_20 L_1 , V_12 ) ;
return - V_21 ;
}
V_4 = V_2 -> V_5 -> V_4 ;
switch ( V_75 ) {
struct V_79 * V_80 ;
unsigned char V_98 ;
unsigned char V_99 ;
int V_17 ;
T_5 V_100 [ 2 ] ;
T_6 time64 [ 2 ] ;
struct V_101 V_102 ;
int V_81 ;
case V_103 :
V_98 = F_34 ( V_4 ) ;
if ( F_13 ( V_77 , & V_98 , sizeof( V_98 ) ) )
return - V_43 ;
return 0 ;
case V_104 :
V_98 = F_35 ( V_4 ) ;
if ( F_13 ( V_77 , & V_98 , sizeof( V_98 ) ) )
return - V_43 ;
return 0 ;
case V_105 :
V_98 = F_36 ( V_4 ) ;
if ( F_13 ( V_77 , & V_98 , sizeof( V_98 ) ) )
return - V_43 ;
return 0 ;
case V_106 :
F_37 ( V_2 -> V_5 ) ;
return 0 ;
case V_107 :
V_80 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_85 . V_17 = V_80 -> V_17 ;
V_2 -> V_85 . V_84 = V_80 -> V_84 ;
V_80 -> V_17 = V_2 -> V_83 . V_17 ;
V_80 -> V_84 = V_2 -> V_83 . V_84 ;
F_38 ( V_2 -> V_5 ) ;
V_2 -> V_18 &= ~ V_19 ;
return 0 ;
case V_108 :
if ( F_16 ( & V_98 , V_77 , sizeof( V_98 ) ) )
return - V_43 ;
F_19 ( V_4 , V_98 ) ;
return 0 ;
case V_109 :
if ( F_16 ( & V_98 , V_77 , sizeof( V_98 ) ) )
return - V_43 ;
F_39 ( V_4 , V_98 ) ;
return 0 ;
case V_110 :
if ( F_16 ( & V_99 , V_77 ,
sizeof( V_99 ) ) )
return - V_43 ;
if ( F_16 ( & V_98 , 1 + ( unsigned char T_2 * ) V_76 ,
sizeof( V_98 ) ) )
return - V_43 ;
F_40 ( V_4 , V_99 , V_98 ) ;
return 0 ;
case V_111 :
if ( F_16 ( & V_17 , V_77 , sizeof( V_17 ) ) )
return - V_43 ;
if ( V_17 )
V_4 -> V_6 -> V_112 ( V_4 ) ;
else
V_4 -> V_6 -> V_113 ( V_4 ) ;
return 0 ;
case V_114 :
if ( F_16 ( & V_17 , V_77 , sizeof( V_17 ) ) )
return - V_43 ;
switch ( ( V_81 = F_41 ( V_4 , V_17 ) ) ) {
case 0 : break;
case - 1 :
V_81 = - V_115 ;
break;
case 1 :
V_81 = - V_60 ;
break;
}
F_1 ( V_2 ) ;
return V_81 ;
case V_116 :
if ( F_16 ( & V_98 , V_77 , sizeof( V_98 ) ) )
return - V_43 ;
V_2 -> V_52 = V_98 ;
V_2 -> V_51 = 1 ;
return 0 ;
case V_117 :
V_81 = F_42 ( & V_2 -> V_53 ) ;
if ( F_13 ( V_77 , & V_81 , sizeof( V_81 ) ) )
return - V_43 ;
F_43 ( V_81 , & V_2 -> V_53 ) ;
return 0 ;
case V_118 :
if ( F_16 ( V_100 , V_77 , sizeof( V_100 ) ) )
return - V_43 ;
return F_30 ( V_2 -> V_5 , V_100 [ 0 ] , V_100 [ 1 ] ) ;
case V_119 :
if ( F_16 ( time64 , V_77 , sizeof( time64 ) ) )
return - V_43 ;
return F_30 ( V_2 -> V_5 , time64 [ 0 ] , time64 [ 1 ] ) ;
case V_120 :
F_44 ( V_2 -> V_5 -> V_74 , & V_102 ) ;
V_100 [ 0 ] = V_102 . V_70 ;
V_100 [ 1 ] = V_102 . V_121 / V_122 ;
if ( ( V_100 [ 0 ] < 0 ) || ( V_100 [ 1 ] < 0 ) )
return - V_21 ;
if ( F_13 ( V_77 , V_100 , sizeof( V_100 ) ) )
return - V_43 ;
return 0 ;
case V_123 :
F_44 ( V_2 -> V_5 -> V_74 , & V_102 ) ;
time64 [ 0 ] = V_102 . V_70 ;
time64 [ 1 ] = V_102 . V_121 / V_122 ;
if ( ( time64 [ 0 ] < 0 ) || ( time64 [ 1 ] < 0 ) )
return - V_21 ;
if ( F_13 ( V_77 , time64 , sizeof( time64 ) ) )
return - V_43 ;
return 0 ;
default:
F_28 ( & V_2 -> V_5 -> V_64 , L_8 , V_75 ) ;
return - V_21 ;
}
return 0 ;
}
static long F_45 ( struct V_8 * V_8 , unsigned int V_75 , unsigned long V_76 )
{
long V_81 ;
F_46 ( & V_124 ) ;
V_81 = F_32 ( V_8 , V_75 , V_76 ) ;
F_47 ( & V_124 ) ;
return V_81 ;
}
static long F_48 ( struct V_8 * V_8 , unsigned int V_75 ,
unsigned long V_76 )
{
return F_45 ( V_8 , V_75 , ( unsigned long ) F_49 ( V_76 ) ) ;
}
static int F_50 ( struct V_125 * V_125 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_125 ) ;
struct V_1 * V_2 ;
if ( V_12 >= V_126 )
return - V_60 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_85 . V_17 = V_127 ;
V_2 -> V_85 . V_84 = F_29 ( V_2 -> V_85 . V_17 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_51 = 0 ;
F_51 ( & V_2 -> V_53 , 0 ) ;
F_52 ( & V_2 -> V_54 ) ;
V_2 -> V_5 = NULL ;
V_8 -> V_13 = V_2 ;
return 0 ;
}
static int F_53 ( struct V_125 * V_125 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_125 ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
int V_128 ;
V_128 = 0 ;
if ( ! ( V_2 -> V_18 & V_19 ) && V_2 -> V_5 &&
( V_2 -> V_85 . V_17 != V_127 ) ) {
struct V_79 * V_80 ;
F_33 ( V_2 -> V_5 ) ;
V_2 -> V_18 |= V_19 ;
V_80 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_83 . V_17 = V_80 -> V_17 ;
V_2 -> V_83 . V_84 = V_80 -> V_84 ;
V_80 -> V_17 = V_2 -> V_85 . V_17 ;
V_80 -> V_84 = V_2 -> V_85 . V_84 ;
V_128 = 1 ;
} else if ( ( V_2 -> V_18 & V_19 ) && V_2 -> V_5 &&
( V_2 -> V_5 -> V_4 -> V_25 . V_17 != V_127 ) ) {
V_128 = 2 ;
}
if ( V_128 ) {
F_41 ( V_2 -> V_5 -> V_4 , V_127 ) ;
F_28 ( & V_2 -> V_5 -> V_64 ,
L_9 ) ;
}
if ( V_2 -> V_18 & V_19 ) {
struct V_79 * V_80 ;
V_80 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_85 . V_17 = V_80 -> V_17 ;
V_2 -> V_85 . V_84 = V_80 -> V_84 ;
V_80 -> V_17 = V_2 -> V_83 . V_17 ;
V_80 -> V_84 = V_2 -> V_83 . V_84 ;
F_38 ( V_2 -> V_5 ) ;
if ( V_128 != 1 ) {
F_5 ( V_20 L_10
L_11 , V_12 ) ;
}
}
if ( V_2 -> V_5 ) {
F_54 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_5 ( V_20 L_12 , V_12 ) ;
}
F_14 ( V_2 ) ;
return 0 ;
}
static unsigned int F_55 ( struct V_8 * V_8 , T_7 * V_129 )
{
struct V_1 * V_2 = V_8 -> V_13 ;
unsigned int V_99 = 0 ;
F_56 ( V_8 , & V_2 -> V_54 , V_129 ) ;
if ( F_42 ( & V_2 -> V_53 ) )
V_99 |= V_130 | V_131 ;
return V_99 ;
}
static void F_57 ( struct V_3 * V_4 )
{
F_58 ( V_132 , V_4 -> V_64 , F_59 ( V_133 , V_4 -> V_134 ) ,
NULL , L_13 , V_4 -> V_134 ) ;
}
static void F_60 ( struct V_3 * V_4 )
{
F_61 ( V_132 , F_59 ( V_133 , V_4 -> V_134 ) ) ;
}
static int F_62 ( struct V_55 * V_135 )
{
struct V_136 * V_137 = V_135 -> V_64 . V_138 ;
int V_139 = strlen ( V_137 -> V_56 ) ;
if ( strncmp ( V_135 -> V_56 , V_137 -> V_56 , V_139 ) )
return - V_93 ;
return 0 ;
}
static int T_8 F_63 ( void )
{
int V_82 = 0 ;
if ( F_64 ( V_133 , V_20 , & V_140 ) ) {
F_25 (KERN_WARNING CHRDEV L_14 ,
PP_MAJOR) ;
return - V_115 ;
}
V_132 = F_65 ( V_141 , V_20 ) ;
if ( F_66 ( V_132 ) ) {
V_82 = F_67 ( V_132 ) ;
goto V_142;
}
V_82 = F_68 ( & V_143 ) ;
if ( V_82 < 0 ) {
F_25 (KERN_WARNING CHRDEV L_15 ) ;
goto V_144;
}
F_25 (KERN_INFO PP_VERSION L_16 ) ;
goto V_145;
V_144:
F_69 ( V_132 ) ;
V_142:
F_70 ( V_133 , V_20 ) ;
V_145:
return V_82 ;
}
static void T_9 F_71 ( void )
{
F_72 ( & V_143 ) ;
F_69 ( V_132 ) ;
F_70 ( V_133 , V_20 ) ;
}
