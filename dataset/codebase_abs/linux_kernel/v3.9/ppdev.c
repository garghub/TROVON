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
if ( ! V_14 ) {
return - V_24 ;
}
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
if ( V_2 -> V_18 & V_34 ) {
V_18 |= V_35 ;
}
if ( V_2 -> V_18 & V_36 ) {
V_18 |= V_37 ;
}
if ( V_16 -> V_25 . V_17 & V_27 ) {
F_9 = V_16 -> V_6 -> V_38 ;
} else {
F_9 = V_16 -> V_6 -> V_39 ;
}
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
if ( ! V_14 ) {
return - V_24 ;
}
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
if ( ! V_44 ) {
V_44 = V_45 ;
}
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
F_5 ( L_5 , V_56 ) ;
return 0 ;
}
static enum V_62 F_28 ( int V_17 )
{
switch ( V_17 & ~ ( V_26
| V_27 ) ) {
case V_63 :
case V_64 :
return V_65 ;
}
return V_66 ;
}
static int F_29 ( struct V_8 * V_8 , unsigned int V_67 , unsigned long V_68 )
{
unsigned int V_12 = F_3 ( F_4 ( V_8 ) ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
struct V_3 * V_4 ;
void T_2 * V_69 = ( void T_2 * ) V_68 ;
switch ( V_67 ) {
case V_70 :
{
struct V_71 * V_72 ;
int V_73 ;
if ( V_2 -> V_18 & V_19 ) {
F_5 ( V_20 L_6 , V_12 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_5 ) {
int V_74 = F_22 ( V_12 , V_2 ) ;
if ( V_74 ) {
return V_74 ;
}
}
V_73 = F_30 ( V_2 -> V_5 ) ;
if ( V_73 < 0 )
return V_73 ;
V_2 -> V_18 |= V_19 ;
F_1 ( V_2 ) ;
V_72 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_75 . V_17 = V_72 -> V_17 ;
V_2 -> V_75 . V_76 = V_72 -> V_76 ;
V_72 -> V_17 = V_2 -> V_77 . V_17 ;
V_72 -> V_76 = V_2 -> V_77 . V_76 ;
V_2 -> V_31 = F_8 ( V_2 -> V_5 , 0 ) ;
F_8 ( V_2 -> V_5 , V_2 -> V_31 ) ;
return 0 ;
}
case V_78 :
if ( V_2 -> V_5 ) {
F_5 ( V_20 L_7
L_8 , V_12 ) ;
if ( V_2 -> V_18 & V_60 )
return 0 ;
return - V_21 ;
}
V_2 -> V_18 |= V_60 ;
return 0 ;
case V_79 :
{
int V_17 ;
if ( F_16 ( & V_17 , V_69 , sizeof ( V_17 ) ) )
return - V_43 ;
V_2 -> V_77 . V_17 = V_17 ;
V_2 -> V_77 . V_76 = F_28 ( V_17 ) ;
if ( V_2 -> V_18 & V_19 ) {
V_2 -> V_5 -> V_4 -> V_25 . V_17 = V_17 ;
V_2 -> V_5 -> V_4 -> V_25 . V_76 = V_2 -> V_77 . V_76 ;
}
return 0 ;
}
case V_80 :
{
int V_17 ;
if ( V_2 -> V_18 & V_19 ) {
V_17 = V_2 -> V_5 -> V_4 -> V_25 . V_17 ;
} else {
V_17 = V_2 -> V_77 . V_17 ;
}
if ( F_13 ( V_69 , & V_17 , sizeof ( V_17 ) ) ) {
return - V_43 ;
}
return 0 ;
}
case V_81 :
{
int V_76 ;
if ( F_16 ( & V_76 , V_69 , sizeof ( V_76 ) ) ) {
return - V_43 ;
}
V_2 -> V_77 . V_76 = V_76 ;
if ( V_2 -> V_18 & V_19 ) {
V_2 -> V_5 -> V_4 -> V_25 . V_76 = V_76 ;
}
return 0 ;
}
case V_82 :
{
int V_76 ;
if ( V_2 -> V_18 & V_19 ) {
V_76 = V_2 -> V_5 -> V_4 -> V_25 . V_76 ;
} else {
V_76 = V_2 -> V_77 . V_76 ;
}
if ( F_13 ( V_69 , & V_76 , sizeof ( V_76 ) ) ) {
return - V_43 ;
}
return 0 ;
}
case V_83 :
{
unsigned int V_84 ;
V_4 = F_24 ( V_12 ) ;
if ( ! V_4 )
return - V_85 ;
V_84 = V_4 -> V_84 ;
F_27 ( V_4 ) ;
if ( F_13 ( V_69 , & V_84 , sizeof ( V_84 ) ) ) {
return - V_43 ;
}
return 0 ;
}
case V_86 :
{
int V_87 ;
if ( F_16 ( & V_87 , V_69 , sizeof ( V_87 ) ) ) {
return - V_43 ;
}
V_2 -> V_18 &= ~ V_88 ;
V_2 -> V_18 |= ( V_87 & V_88 ) ;
return 0 ;
}
case V_89 :
{
int V_87 ;
V_87 = V_2 -> V_18 & V_88 ;
if ( F_13 ( V_69 , & V_87 , sizeof ( V_87 ) ) ) {
return - V_43 ;
}
return 0 ;
}
}
if ( ( V_2 -> V_18 & V_19 ) == 0 ) {
F_5 ( V_20 L_1 , V_12 ) ;
return - V_21 ;
}
V_4 = V_2 -> V_5 -> V_4 ;
switch ( V_67 ) {
struct V_71 * V_72 ;
unsigned char V_90 ;
unsigned char V_91 ;
int V_17 ;
int V_73 ;
struct V_92 V_93 ;
long V_94 ;
case V_95 :
V_90 = F_31 ( V_4 ) ;
if ( F_13 ( V_69 , & V_90 , sizeof ( V_90 ) ) )
return - V_43 ;
return 0 ;
case V_96 :
V_90 = F_32 ( V_4 ) ;
if ( F_13 ( V_69 , & V_90 , sizeof ( V_90 ) ) )
return - V_43 ;
return 0 ;
case V_97 :
V_90 = F_33 ( V_4 ) ;
if ( F_13 ( V_69 , & V_90 , sizeof ( V_90 ) ) )
return - V_43 ;
return 0 ;
case V_98 :
F_34 ( V_2 -> V_5 ) ;
return 0 ;
case V_99 :
V_72 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_77 . V_17 = V_72 -> V_17 ;
V_2 -> V_77 . V_76 = V_72 -> V_76 ;
V_72 -> V_17 = V_2 -> V_75 . V_17 ;
V_72 -> V_76 = V_2 -> V_75 . V_76 ;
F_35 ( V_2 -> V_5 ) ;
V_2 -> V_18 &= ~ V_19 ;
return 0 ;
case V_100 :
if ( F_16 ( & V_90 , V_69 , sizeof ( V_90 ) ) )
return - V_43 ;
F_19 ( V_4 , V_90 ) ;
return 0 ;
case V_101 :
if ( F_16 ( & V_90 , V_69 , sizeof ( V_90 ) ) )
return - V_43 ;
F_36 ( V_4 , V_90 ) ;
return 0 ;
case V_102 :
if ( F_16 ( & V_91 , V_69 ,
sizeof ( V_91 ) ) )
return - V_43 ;
if ( F_16 ( & V_90 , 1 + ( unsigned char T_2 * ) V_68 ,
sizeof ( V_90 ) ) )
return - V_43 ;
F_37 ( V_4 , V_91 , V_90 ) ;
return 0 ;
case V_103 :
if ( F_16 ( & V_17 , V_69 , sizeof ( V_17 ) ) )
return - V_43 ;
if ( V_17 )
V_4 -> V_6 -> V_104 ( V_4 ) ;
else
V_4 -> V_6 -> V_105 ( V_4 ) ;
return 0 ;
case V_106 :
if ( F_16 ( & V_17 , V_69 , sizeof ( V_17 ) ) )
return - V_43 ;
switch ( ( V_73 = F_38 ( V_4 , V_17 ) ) ) {
case 0 : break;
case - 1 :
V_73 = - V_107 ;
break;
case 1 :
V_73 = - V_59 ;
break;
}
F_1 ( V_2 ) ;
return V_73 ;
case V_108 :
if ( F_16 ( & V_90 , V_69 , sizeof ( V_90 ) ) )
return - V_43 ;
V_2 -> V_52 = V_90 ;
V_2 -> V_51 = 1 ;
return 0 ;
case V_109 :
V_73 = F_39 ( & V_2 -> V_53 ) ;
if ( F_13 ( V_69 , & V_73 , sizeof ( V_73 ) ) )
return - V_43 ;
F_40 ( V_73 , & V_2 -> V_53 ) ;
return 0 ;
case V_110 :
if ( F_16 ( & V_93 , V_69 , sizeof( struct V_92 ) ) ) {
return - V_43 ;
}
if ( ( V_93 . V_111 < 0 ) || ( V_93 . V_112 < 0 ) ) {
return - V_21 ;
}
V_94 = F_41 ( V_93 . V_112 , 1000000 / V_113 ) ;
V_94 += V_93 . V_111 * ( long ) V_113 ;
if ( V_94 <= 0 ) {
return - V_21 ;
}
V_2 -> V_5 -> V_114 = V_94 ;
return 0 ;
case V_115 :
V_94 = V_2 -> V_5 -> V_114 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_111 = V_94 / V_113 ;
V_93 . V_112 = ( V_94 % ( long ) V_113 ) * ( 1000000 / V_113 ) ;
if ( F_13 ( V_69 , & V_93 , sizeof( struct V_92 ) ) )
return - V_43 ;
return 0 ;
default:
F_5 ( V_20 L_9 , V_12 , V_67 ) ;
return - V_21 ;
}
return 0 ;
}
static long F_42 ( struct V_8 * V_8 , unsigned int V_67 , unsigned long V_68 )
{
long V_73 ;
F_43 ( & V_116 ) ;
V_73 = F_29 ( V_8 , V_67 , V_68 ) ;
F_44 ( & V_116 ) ;
return V_73 ;
}
static int F_45 ( struct V_117 * V_117 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_117 ) ;
struct V_1 * V_2 ;
if ( V_12 >= V_118 )
return - V_59 ;
V_2 = F_6 ( sizeof ( struct V_1 ) , V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_77 . V_17 = V_119 ;
V_2 -> V_77 . V_76 = F_28 ( V_2 -> V_77 . V_17 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_51 = 0 ;
F_46 ( & V_2 -> V_53 , 0 ) ;
F_47 ( & V_2 -> V_54 ) ;
V_2 -> V_5 = NULL ;
V_8 -> V_13 = V_2 ;
return 0 ;
}
static int F_48 ( struct V_117 * V_117 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_117 ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
int V_120 ;
V_120 = 0 ;
if ( ! ( V_2 -> V_18 & V_19 ) && V_2 -> V_5 &&
( V_2 -> V_77 . V_17 != V_119 ) ) {
struct V_71 * V_72 ;
F_30 ( V_2 -> V_5 ) ;
V_2 -> V_18 |= V_19 ;
V_72 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_75 . V_17 = V_72 -> V_17 ;
V_2 -> V_75 . V_76 = V_72 -> V_76 ;
V_72 -> V_17 = V_2 -> V_77 . V_17 ;
V_72 -> V_76 = V_2 -> V_77 . V_76 ;
V_120 = 1 ;
} else if ( ( V_2 -> V_18 & V_19 ) && V_2 -> V_5 &&
( V_2 -> V_5 -> V_4 -> V_25 . V_17 != V_119 ) ) {
V_120 = 2 ;
}
if ( V_120 ) {
F_38 ( V_2 -> V_5 -> V_4 , V_119 ) ;
F_5 ( V_20 L_10
L_11 , V_12 ) ;
}
if ( V_2 -> V_18 & V_19 ) {
struct V_71 * V_72 ;
V_72 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_77 . V_17 = V_72 -> V_17 ;
V_2 -> V_77 . V_76 = V_72 -> V_76 ;
V_72 -> V_17 = V_2 -> V_75 . V_17 ;
V_72 -> V_76 = V_2 -> V_75 . V_76 ;
F_35 ( V_2 -> V_5 ) ;
if ( V_120 != 1 ) {
F_5 ( V_20 L_12
L_13 , V_12 ) ;
}
}
if ( V_2 -> V_5 ) {
const char * V_56 = V_2 -> V_5 -> V_56 ;
F_49 ( V_2 -> V_5 ) ;
F_14 ( V_56 ) ;
V_2 -> V_5 = NULL ;
F_5 ( V_20 L_14 , V_12 ) ;
}
F_14 ( V_2 ) ;
return 0 ;
}
static unsigned int F_50 ( struct V_8 * V_8 , T_5 * V_121 )
{
struct V_1 * V_2 = V_8 -> V_13 ;
unsigned int V_91 = 0 ;
F_51 ( V_8 , & V_2 -> V_54 , V_121 ) ;
if ( F_39 ( & V_2 -> V_53 ) )
V_91 |= V_122 | V_123 ;
return V_91 ;
}
static void F_52 ( struct V_3 * V_4 )
{
F_53 ( V_124 , V_4 -> V_125 , F_54 ( V_126 , V_4 -> V_127 ) ,
NULL , L_15 , V_4 -> V_127 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
F_56 ( V_124 , F_54 ( V_126 , V_4 -> V_127 ) ) ;
}
static int T_6 F_57 ( void )
{
int V_74 = 0 ;
if ( F_58 ( V_126 , V_20 , & V_128 ) ) {
F_25 (KERN_WARNING CHRDEV L_16 ,
PP_MAJOR) ;
return - V_107 ;
}
V_124 = F_59 ( V_129 , V_20 ) ;
if ( F_60 ( V_124 ) ) {
V_74 = F_61 ( V_124 ) ;
goto V_130;
}
V_74 = F_62 ( & V_131 ) ;
if ( V_74 < 0 ) {
F_25 (KERN_WARNING CHRDEV L_17 ) ;
goto V_132;
}
F_25 (KERN_INFO PP_VERSION L_18 ) ;
goto V_133;
V_132:
F_63 ( V_124 ) ;
V_130:
F_64 ( V_126 , V_20 ) ;
V_133:
return V_74 ;
}
static void T_7 F_65 ( void )
{
F_66 ( & V_131 ) ;
F_63 ( V_124 ) ;
F_64 ( V_126 , V_20 ) ;
}
