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
if ( F_10 ( V_44 ) ) {
if ( ! V_47 ) {
V_47 = - V_53 ;
}
break;
}
F_11 () ;
}
F_7 ( V_2 -> V_5 , V_2 -> V_34 ) ;
F_13 ( V_17 ) ;
F_1 ( V_2 ) ;
return V_47 ;
}
static void F_17 ( void * V_54 )
{
struct V_1 * V_2 = V_54 ;
if ( V_2 -> V_55 ) {
F_18 ( V_2 -> V_5 -> V_4 , V_2 -> V_56 ) ;
V_2 -> V_55 = 0 ;
}
F_19 ( & V_2 -> V_57 ) ;
F_20 ( & V_2 -> V_58 ) ;
}
static int F_21 ( int V_12 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_59 * V_5 = NULL ;
char * V_60 ;
int V_61 ;
V_60 = F_22 ( V_26 , V_23 L_2 , V_12 ) ;
if ( V_60 == NULL )
return - V_27 ;
V_4 = F_23 ( V_12 ) ;
if ( ! V_4 ) {
F_24 ( V_62 L_3 , V_60 ) ;
F_13 ( V_60 ) ;
return - V_63 ;
}
V_61 = ( V_2 -> V_21 & V_64 ) ? V_65 : 0 ;
V_5 = F_25 ( V_4 , V_60 , NULL ,
NULL , F_17 , V_61 , V_2 ) ;
F_26 ( V_4 ) ;
if ( ! V_5 ) {
F_24 ( V_62 L_4 , V_60 ) ;
F_13 ( V_60 ) ;
return - V_63 ;
}
V_2 -> V_5 = V_5 ;
F_4 ( L_5 , V_60 ) ;
return 0 ;
}
static enum V_66 F_27 ( int V_20 )
{
switch ( V_20 & ~ ( V_29
| V_30 ) ) {
case V_67 :
case V_68 :
return V_69 ;
}
return V_70 ;
}
static int F_28 ( struct V_8 * V_8 , unsigned int V_71 , unsigned long V_72 )
{
unsigned int V_12 = F_3 ( V_8 -> V_13 . V_14 -> V_15 ) ;
struct V_1 * V_2 = V_8 -> V_16 ;
struct V_3 * V_4 ;
void T_2 * V_73 = ( void T_2 * ) V_72 ;
switch ( V_71 ) {
case V_74 :
{
struct V_75 * V_76 ;
int V_77 ;
if ( V_2 -> V_21 & V_22 ) {
F_4 ( V_23 L_6 , V_12 ) ;
return - V_24 ;
}
if ( ! V_2 -> V_5 ) {
int V_78 = F_21 ( V_12 , V_2 ) ;
if ( V_78 ) {
return V_78 ;
}
}
V_77 = F_29 ( V_2 -> V_5 ) ;
if ( V_77 < 0 )
return V_77 ;
V_2 -> V_21 |= V_22 ;
F_1 ( V_2 ) ;
V_76 = & V_2 -> V_5 -> V_4 -> V_28 ;
V_2 -> V_79 . V_20 = V_76 -> V_20 ;
V_2 -> V_79 . V_80 = V_76 -> V_80 ;
V_76 -> V_20 = V_2 -> V_81 . V_20 ;
V_76 -> V_80 = V_2 -> V_81 . V_80 ;
V_2 -> V_34 = F_7 ( V_2 -> V_5 , 0 ) ;
F_7 ( V_2 -> V_5 , V_2 -> V_34 ) ;
return 0 ;
}
case V_82 :
if ( V_2 -> V_5 ) {
F_4 ( V_23 L_7
L_8 , V_12 ) ;
if ( V_2 -> V_21 & V_64 )
return 0 ;
return - V_24 ;
}
V_2 -> V_21 |= V_64 ;
return 0 ;
case V_83 :
{
int V_20 ;
if ( F_15 ( & V_20 , V_73 , sizeof ( V_20 ) ) )
return - V_46 ;
V_2 -> V_81 . V_20 = V_20 ;
V_2 -> V_81 . V_80 = F_27 ( V_20 ) ;
if ( V_2 -> V_21 & V_22 ) {
V_2 -> V_5 -> V_4 -> V_28 . V_20 = V_20 ;
V_2 -> V_5 -> V_4 -> V_28 . V_80 = V_2 -> V_81 . V_80 ;
}
return 0 ;
}
case V_84 :
{
int V_20 ;
if ( V_2 -> V_21 & V_22 ) {
V_20 = V_2 -> V_5 -> V_4 -> V_28 . V_20 ;
} else {
V_20 = V_2 -> V_81 . V_20 ;
}
if ( F_12 ( V_73 , & V_20 , sizeof ( V_20 ) ) ) {
return - V_46 ;
}
return 0 ;
}
case V_85 :
{
int V_80 ;
if ( F_15 ( & V_80 , V_73 , sizeof ( V_80 ) ) ) {
return - V_46 ;
}
V_2 -> V_81 . V_80 = V_80 ;
if ( V_2 -> V_21 & V_22 ) {
V_2 -> V_5 -> V_4 -> V_28 . V_80 = V_80 ;
}
return 0 ;
}
case V_86 :
{
int V_80 ;
if ( V_2 -> V_21 & V_22 ) {
V_80 = V_2 -> V_5 -> V_4 -> V_28 . V_80 ;
} else {
V_80 = V_2 -> V_81 . V_80 ;
}
if ( F_12 ( V_73 , & V_80 , sizeof ( V_80 ) ) ) {
return - V_46 ;
}
return 0 ;
}
case V_87 :
{
unsigned int V_88 ;
V_4 = F_23 ( V_12 ) ;
if ( ! V_4 )
return - V_89 ;
V_88 = V_4 -> V_88 ;
F_26 ( V_4 ) ;
if ( F_12 ( V_73 , & V_88 , sizeof ( V_88 ) ) ) {
return - V_46 ;
}
return 0 ;
}
case V_90 :
{
int V_91 ;
if ( F_15 ( & V_91 , V_73 , sizeof ( V_91 ) ) ) {
return - V_46 ;
}
V_2 -> V_21 &= ~ V_92 ;
V_2 -> V_21 |= ( V_91 & V_92 ) ;
return 0 ;
}
case V_93 :
{
int V_91 ;
V_91 = V_2 -> V_21 & V_92 ;
if ( F_12 ( V_73 , & V_91 , sizeof ( V_91 ) ) ) {
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
switch ( V_71 ) {
struct V_75 * V_76 ;
unsigned char V_94 ;
unsigned char V_95 ;
int V_20 ;
int V_77 ;
struct V_96 V_97 ;
long V_98 ;
case V_99 :
V_94 = F_30 ( V_4 ) ;
if ( F_12 ( V_73 , & V_94 , sizeof ( V_94 ) ) )
return - V_46 ;
return 0 ;
case V_100 :
V_94 = F_31 ( V_4 ) ;
if ( F_12 ( V_73 , & V_94 , sizeof ( V_94 ) ) )
return - V_46 ;
return 0 ;
case V_101 :
V_94 = F_32 ( V_4 ) ;
if ( F_12 ( V_73 , & V_94 , sizeof ( V_94 ) ) )
return - V_46 ;
return 0 ;
case V_102 :
F_33 ( V_2 -> V_5 ) ;
return 0 ;
case V_103 :
V_76 = & V_2 -> V_5 -> V_4 -> V_28 ;
V_2 -> V_81 . V_20 = V_76 -> V_20 ;
V_2 -> V_81 . V_80 = V_76 -> V_80 ;
V_76 -> V_20 = V_2 -> V_79 . V_20 ;
V_76 -> V_80 = V_2 -> V_79 . V_80 ;
F_34 ( V_2 -> V_5 ) ;
V_2 -> V_21 &= ~ V_22 ;
return 0 ;
case V_104 :
if ( F_15 ( & V_94 , V_73 , sizeof ( V_94 ) ) )
return - V_46 ;
F_18 ( V_4 , V_94 ) ;
return 0 ;
case V_105 :
if ( F_15 ( & V_94 , V_73 , sizeof ( V_94 ) ) )
return - V_46 ;
F_35 ( V_4 , V_94 ) ;
return 0 ;
case V_106 :
if ( F_15 ( & V_95 , V_73 ,
sizeof ( V_95 ) ) )
return - V_46 ;
if ( F_15 ( & V_94 , 1 + ( unsigned char T_2 * ) V_72 ,
sizeof ( V_94 ) ) )
return - V_46 ;
F_36 ( V_4 , V_95 , V_94 ) ;
return 0 ;
case V_107 :
if ( F_15 ( & V_20 , V_73 , sizeof ( V_20 ) ) )
return - V_46 ;
if ( V_20 )
V_4 -> V_6 -> V_108 ( V_4 ) ;
else
V_4 -> V_6 -> V_109 ( V_4 ) ;
return 0 ;
case V_110 :
if ( F_15 ( & V_20 , V_73 , sizeof ( V_20 ) ) )
return - V_46 ;
switch ( ( V_77 = F_37 ( V_4 , V_20 ) ) ) {
case 0 : break;
case - 1 :
V_77 = - V_111 ;
break;
case 1 :
V_77 = - V_63 ;
break;
}
F_1 ( V_2 ) ;
return V_77 ;
case V_112 :
if ( F_15 ( & V_94 , V_73 , sizeof ( V_94 ) ) )
return - V_46 ;
V_2 -> V_56 = V_94 ;
V_2 -> V_55 = 1 ;
return 0 ;
case V_113 :
V_77 = F_38 ( & V_2 -> V_57 ) ;
if ( F_12 ( V_73 , & V_77 , sizeof ( V_77 ) ) )
return - V_46 ;
F_39 ( V_77 , & V_2 -> V_57 ) ;
return 0 ;
case V_114 :
if ( F_15 ( & V_97 , V_73 , sizeof( struct V_96 ) ) ) {
return - V_46 ;
}
if ( ( V_97 . V_115 < 0 ) || ( V_97 . V_116 < 0 ) ) {
return - V_24 ;
}
V_98 = F_40 ( V_97 . V_116 , 1000000 / V_117 ) ;
V_98 += V_97 . V_115 * ( long ) V_117 ;
if ( V_98 <= 0 ) {
return - V_24 ;
}
V_2 -> V_5 -> V_118 = V_98 ;
return 0 ;
case V_119 :
V_98 = V_2 -> V_5 -> V_118 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_115 = V_98 / V_117 ;
V_97 . V_116 = ( V_98 % ( long ) V_117 ) * ( 1000000 / V_117 ) ;
if ( F_12 ( V_73 , & V_97 , sizeof( struct V_96 ) ) )
return - V_46 ;
return 0 ;
default:
F_4 ( V_23 L_9 , V_12 , V_71 ) ;
return - V_24 ;
}
return 0 ;
}
static long F_41 ( struct V_8 * V_8 , unsigned int V_71 , unsigned long V_72 )
{
long V_77 ;
F_42 ( & V_120 ) ;
V_77 = F_28 ( V_8 , V_71 , V_72 ) ;
F_43 ( & V_120 ) ;
return V_77 ;
}
static int F_44 ( struct V_121 * V_121 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_121 ) ;
struct V_1 * V_2 ;
if ( V_12 >= V_122 )
return - V_63 ;
V_2 = F_5 ( sizeof ( struct V_1 ) , V_26 ) ;
if ( ! V_2 )
return - V_27 ;
V_2 -> V_81 . V_20 = V_123 ;
V_2 -> V_81 . V_80 = F_27 ( V_2 -> V_81 . V_20 ) ;
V_2 -> V_21 = 0 ;
V_2 -> V_55 = 0 ;
F_45 ( & V_2 -> V_57 , 0 ) ;
F_46 ( & V_2 -> V_58 ) ;
V_2 -> V_5 = NULL ;
V_8 -> V_16 = V_2 ;
return 0 ;
}
static int F_47 ( struct V_121 * V_121 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_121 ) ;
struct V_1 * V_2 = V_8 -> V_16 ;
int V_124 ;
V_124 = 0 ;
if ( ! ( V_2 -> V_21 & V_22 ) && V_2 -> V_5 &&
( V_2 -> V_81 . V_20 != V_123 ) ) {
struct V_75 * V_76 ;
F_29 ( V_2 -> V_5 ) ;
V_2 -> V_21 |= V_22 ;
V_76 = & V_2 -> V_5 -> V_4 -> V_28 ;
V_2 -> V_79 . V_20 = V_76 -> V_20 ;
V_2 -> V_79 . V_80 = V_76 -> V_80 ;
V_76 -> V_20 = V_2 -> V_81 . V_20 ;
V_76 -> V_80 = V_2 -> V_81 . V_80 ;
V_124 = 1 ;
} else if ( ( V_2 -> V_21 & V_22 ) && V_2 -> V_5 &&
( V_2 -> V_5 -> V_4 -> V_28 . V_20 != V_123 ) ) {
V_124 = 2 ;
}
if ( V_124 ) {
F_37 ( V_2 -> V_5 -> V_4 , V_123 ) ;
F_4 ( V_23 L_10
L_11 , V_12 ) ;
}
if ( V_2 -> V_21 & V_22 ) {
struct V_75 * V_76 ;
V_76 = & V_2 -> V_5 -> V_4 -> V_28 ;
V_2 -> V_81 . V_20 = V_76 -> V_20 ;
V_2 -> V_81 . V_80 = V_76 -> V_80 ;
V_76 -> V_20 = V_2 -> V_79 . V_20 ;
V_76 -> V_80 = V_2 -> V_79 . V_80 ;
F_34 ( V_2 -> V_5 ) ;
if ( V_124 != 1 ) {
F_4 ( V_23 L_12
L_13 , V_12 ) ;
}
}
if ( V_2 -> V_5 ) {
const char * V_60 = V_2 -> V_5 -> V_60 ;
F_48 ( V_2 -> V_5 ) ;
F_13 ( V_60 ) ;
V_2 -> V_5 = NULL ;
F_4 ( V_23 L_14 , V_12 ) ;
}
F_13 ( V_2 ) ;
return 0 ;
}
static unsigned int F_49 ( struct V_8 * V_8 , T_5 * V_125 )
{
struct V_1 * V_2 = V_8 -> V_16 ;
unsigned int V_95 = 0 ;
F_50 ( V_8 , & V_2 -> V_58 , V_125 ) ;
if ( F_38 ( & V_2 -> V_57 ) )
V_95 |= V_126 | V_127 ;
return V_95 ;
}
static void F_51 ( struct V_3 * V_4 )
{
F_52 ( V_128 , V_4 -> V_129 , F_53 ( V_130 , V_4 -> V_131 ) ,
NULL , L_15 , V_4 -> V_131 ) ;
}
static void F_54 ( struct V_3 * V_4 )
{
F_55 ( V_128 , F_53 ( V_130 , V_4 -> V_131 ) ) ;
}
static int T_6 F_56 ( void )
{
int V_78 = 0 ;
if ( F_57 ( V_130 , V_23 , & V_132 ) ) {
F_24 (KERN_WARNING CHRDEV L_16 ,
PP_MAJOR) ;
return - V_111 ;
}
V_128 = F_58 ( V_133 , V_23 ) ;
if ( F_59 ( V_128 ) ) {
V_78 = F_60 ( V_128 ) ;
goto V_134;
}
if ( F_61 ( & V_135 ) ) {
F_24 (KERN_WARNING CHRDEV L_17 ) ;
goto V_136;
}
F_24 (KERN_INFO PP_VERSION L_18 ) ;
goto V_137;
V_136:
F_62 ( V_128 ) ;
V_134:
F_63 ( V_130 , V_23 ) ;
V_137:
return V_78 ;
}
static void T_7 F_64 ( void )
{
F_65 ( & V_135 ) ;
F_62 ( V_128 ) ;
F_63 ( V_130 , V_23 ) ;
}
