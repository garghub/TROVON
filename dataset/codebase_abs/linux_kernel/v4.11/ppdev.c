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
int V_59 = 0 , V_60 ;
V_56 = F_23 ( V_23 , V_20 L_2 , V_12 ) ;
if ( V_56 == NULL )
return - V_24 ;
V_4 = F_24 ( V_12 ) ;
if ( ! V_4 ) {
F_25 ( L_3 , V_56 ) ;
V_59 = - V_61 ;
goto V_62;
}
V_60 = F_26 ( & V_63 , 0 , 0 , V_23 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_64 = F_18 ;
V_58 . V_18 = ( V_2 -> V_18 & V_65 ) ? V_66 : 0 ;
V_58 . V_50 = V_2 ;
V_5 = F_27 ( V_4 , V_56 , & V_58 , V_60 ) ;
F_28 ( V_4 ) ;
if ( ! V_5 ) {
F_25 ( L_4 , V_56 ) ;
V_59 = - V_61 ;
F_29 ( & V_63 , V_60 ) ;
goto V_62;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_60 = V_60 ;
F_30 ( & V_5 -> V_67 , L_5 ) ;
V_62:
F_14 ( V_56 ) ;
return V_59 ;
}
static enum V_68 F_31 ( int V_17 )
{
switch ( V_17 & ~ ( V_26
| V_27 ) ) {
case V_69 :
case V_70 :
return V_71 ;
}
return V_72 ;
}
static int F_32 ( struct V_55 * V_5 , long V_73 , int V_74 )
{
long V_75 ;
if ( ( V_73 < 0 ) || ( V_74 < 0 ) )
return - V_21 ;
V_75 = F_33 ( V_74 ) ;
V_75 += V_73 * V_76 ;
if ( V_75 <= 0 )
return - V_21 ;
V_5 -> V_77 = V_75 ;
return 0 ;
}
static int F_34 ( struct V_8 * V_8 , unsigned int V_78 , unsigned long V_79 )
{
unsigned int V_12 = F_3 ( F_4 ( V_8 ) ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
struct V_3 * V_4 ;
void T_2 * V_80 = ( void T_2 * ) V_79 ;
switch ( V_78 ) {
case V_81 :
{
struct V_82 * V_83 ;
int V_84 ;
if ( V_2 -> V_18 & V_19 ) {
F_30 ( & V_2 -> V_5 -> V_67 , L_6 ) ;
return - V_21 ;
}
if ( ! V_2 -> V_5 ) {
int V_62 = F_22 ( V_12 , V_2 ) ;
if ( V_62 )
return V_62 ;
}
V_84 = F_35 ( V_2 -> V_5 ) ;
if ( V_84 < 0 )
return V_84 ;
V_2 -> V_18 |= V_19 ;
F_1 ( V_2 ) ;
V_83 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_85 . V_17 = V_83 -> V_17 ;
V_2 -> V_85 . V_86 = V_83 -> V_86 ;
V_83 -> V_17 = V_2 -> V_87 . V_17 ;
V_83 -> V_86 = V_2 -> V_87 . V_86 ;
V_2 -> V_31 = F_8 ( V_2 -> V_5 , 0 ) ;
F_8 ( V_2 -> V_5 , V_2 -> V_31 ) ;
return 0 ;
}
case V_88 :
if ( V_2 -> V_5 ) {
F_30 ( & V_2 -> V_5 -> V_67 ,
L_7 ) ;
if ( V_2 -> V_18 & V_65 )
return 0 ;
return - V_21 ;
}
V_2 -> V_18 |= V_65 ;
return 0 ;
case V_89 :
{
int V_17 ;
if ( F_16 ( & V_17 , V_80 , sizeof( V_17 ) ) )
return - V_43 ;
V_2 -> V_87 . V_17 = V_17 ;
V_2 -> V_87 . V_86 = F_31 ( V_17 ) ;
if ( V_2 -> V_18 & V_19 ) {
V_2 -> V_5 -> V_4 -> V_25 . V_17 = V_17 ;
V_2 -> V_5 -> V_4 -> V_25 . V_86 = V_2 -> V_87 . V_86 ;
}
return 0 ;
}
case V_90 :
{
int V_17 ;
if ( V_2 -> V_18 & V_19 )
V_17 = V_2 -> V_5 -> V_4 -> V_25 . V_17 ;
else
V_17 = V_2 -> V_87 . V_17 ;
if ( F_13 ( V_80 , & V_17 , sizeof( V_17 ) ) )
return - V_43 ;
return 0 ;
}
case V_91 :
{
int V_86 ;
if ( F_16 ( & V_86 , V_80 , sizeof( V_86 ) ) )
return - V_43 ;
V_2 -> V_87 . V_86 = V_86 ;
if ( V_2 -> V_18 & V_19 )
V_2 -> V_5 -> V_4 -> V_25 . V_86 = V_86 ;
return 0 ;
}
case V_92 :
{
int V_86 ;
if ( V_2 -> V_18 & V_19 )
V_86 = V_2 -> V_5 -> V_4 -> V_25 . V_86 ;
else
V_86 = V_2 -> V_87 . V_86 ;
if ( F_13 ( V_80 , & V_86 , sizeof( V_86 ) ) )
return - V_43 ;
return 0 ;
}
case V_93 :
{
unsigned int V_94 ;
V_4 = F_24 ( V_12 ) ;
if ( ! V_4 )
return - V_95 ;
V_94 = V_4 -> V_94 ;
F_28 ( V_4 ) ;
if ( F_13 ( V_80 , & V_94 , sizeof( V_94 ) ) )
return - V_43 ;
return 0 ;
}
case V_96 :
{
int V_97 ;
if ( F_16 ( & V_97 , V_80 , sizeof( V_97 ) ) )
return - V_43 ;
V_2 -> V_18 &= ~ V_98 ;
V_2 -> V_18 |= ( V_97 & V_98 ) ;
return 0 ;
}
case V_99 :
{
int V_97 ;
V_97 = V_2 -> V_18 & V_98 ;
if ( F_13 ( V_80 , & V_97 , sizeof( V_97 ) ) )
return - V_43 ;
return 0 ;
}
}
if ( ( V_2 -> V_18 & V_19 ) == 0 ) {
F_5 ( V_20 L_1 , V_12 ) ;
return - V_21 ;
}
V_4 = V_2 -> V_5 -> V_4 ;
switch ( V_78 ) {
struct V_82 * V_83 ;
unsigned char V_100 ;
unsigned char V_101 ;
int V_17 ;
T_5 V_102 [ 2 ] ;
T_6 time64 [ 2 ] ;
struct V_103 V_104 ;
int V_84 ;
case V_105 :
V_100 = F_36 ( V_4 ) ;
if ( F_13 ( V_80 , & V_100 , sizeof( V_100 ) ) )
return - V_43 ;
return 0 ;
case V_106 :
V_100 = F_37 ( V_4 ) ;
if ( F_13 ( V_80 , & V_100 , sizeof( V_100 ) ) )
return - V_43 ;
return 0 ;
case V_107 :
V_100 = F_38 ( V_4 ) ;
if ( F_13 ( V_80 , & V_100 , sizeof( V_100 ) ) )
return - V_43 ;
return 0 ;
case V_108 :
F_39 ( V_2 -> V_5 ) ;
return 0 ;
case V_109 :
V_83 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_87 . V_17 = V_83 -> V_17 ;
V_2 -> V_87 . V_86 = V_83 -> V_86 ;
V_83 -> V_17 = V_2 -> V_85 . V_17 ;
V_83 -> V_86 = V_2 -> V_85 . V_86 ;
F_40 ( V_2 -> V_5 ) ;
V_2 -> V_18 &= ~ V_19 ;
return 0 ;
case V_110 :
if ( F_16 ( & V_100 , V_80 , sizeof( V_100 ) ) )
return - V_43 ;
F_19 ( V_4 , V_100 ) ;
return 0 ;
case V_111 :
if ( F_16 ( & V_100 , V_80 , sizeof( V_100 ) ) )
return - V_43 ;
F_41 ( V_4 , V_100 ) ;
return 0 ;
case V_112 :
if ( F_16 ( & V_101 , V_80 ,
sizeof( V_101 ) ) )
return - V_43 ;
if ( F_16 ( & V_100 , 1 + ( unsigned char T_2 * ) V_79 ,
sizeof( V_100 ) ) )
return - V_43 ;
F_42 ( V_4 , V_101 , V_100 ) ;
return 0 ;
case V_113 :
if ( F_16 ( & V_17 , V_80 , sizeof( V_17 ) ) )
return - V_43 ;
if ( V_17 )
V_4 -> V_6 -> V_114 ( V_4 ) ;
else
V_4 -> V_6 -> V_115 ( V_4 ) ;
return 0 ;
case V_116 :
if ( F_16 ( & V_17 , V_80 , sizeof( V_17 ) ) )
return - V_43 ;
switch ( ( V_84 = F_43 ( V_4 , V_17 ) ) ) {
case 0 : break;
case - 1 :
V_84 = - V_117 ;
break;
case 1 :
V_84 = - V_61 ;
break;
}
F_1 ( V_2 ) ;
return V_84 ;
case V_118 :
if ( F_16 ( & V_100 , V_80 , sizeof( V_100 ) ) )
return - V_43 ;
V_2 -> V_52 = V_100 ;
V_2 -> V_51 = 1 ;
return 0 ;
case V_119 :
V_84 = F_44 ( & V_2 -> V_53 ) ;
if ( F_13 ( V_80 , & V_84 , sizeof( V_84 ) ) )
return - V_43 ;
F_45 ( V_84 , & V_2 -> V_53 ) ;
return 0 ;
case V_120 :
if ( F_16 ( V_102 , V_80 , sizeof( V_102 ) ) )
return - V_43 ;
return F_32 ( V_2 -> V_5 , V_102 [ 0 ] , V_102 [ 1 ] ) ;
case V_121 :
if ( F_16 ( time64 , V_80 , sizeof( time64 ) ) )
return - V_43 ;
return F_32 ( V_2 -> V_5 , time64 [ 0 ] , time64 [ 1 ] ) ;
case V_122 :
F_46 ( V_2 -> V_5 -> V_77 , & V_104 ) ;
V_102 [ 0 ] = V_104 . V_73 ;
V_102 [ 1 ] = V_104 . V_123 / V_124 ;
if ( ( V_102 [ 0 ] < 0 ) || ( V_102 [ 1 ] < 0 ) )
return - V_21 ;
if ( F_13 ( V_80 , V_102 , sizeof( V_102 ) ) )
return - V_43 ;
return 0 ;
case V_125 :
F_46 ( V_2 -> V_5 -> V_77 , & V_104 ) ;
time64 [ 0 ] = V_104 . V_73 ;
time64 [ 1 ] = V_104 . V_123 / V_124 ;
if ( ( time64 [ 0 ] < 0 ) || ( time64 [ 1 ] < 0 ) )
return - V_21 ;
if ( F_13 ( V_80 , time64 , sizeof( time64 ) ) )
return - V_43 ;
return 0 ;
default:
F_30 ( & V_2 -> V_5 -> V_67 , L_8 , V_78 ) ;
return - V_21 ;
}
return 0 ;
}
static long F_47 ( struct V_8 * V_8 , unsigned int V_78 , unsigned long V_79 )
{
long V_84 ;
F_48 ( & V_126 ) ;
V_84 = F_34 ( V_8 , V_78 , V_79 ) ;
F_49 ( & V_126 ) ;
return V_84 ;
}
static long F_50 ( struct V_8 * V_8 , unsigned int V_78 ,
unsigned long V_79 )
{
return F_47 ( V_8 , V_78 , ( unsigned long ) F_51 ( V_79 ) ) ;
}
static int F_52 ( struct V_127 * V_127 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_127 ) ;
struct V_1 * V_2 ;
if ( V_12 >= V_128 )
return - V_61 ;
V_2 = F_6 ( sizeof( struct V_1 ) , V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_2 -> V_87 . V_17 = V_129 ;
V_2 -> V_87 . V_86 = F_31 ( V_2 -> V_87 . V_17 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_51 = 0 ;
F_53 ( & V_2 -> V_53 , 0 ) ;
F_54 ( & V_2 -> V_54 ) ;
V_2 -> V_5 = NULL ;
V_8 -> V_13 = V_2 ;
return 0 ;
}
static int F_55 ( struct V_127 * V_127 , struct V_8 * V_8 )
{
unsigned int V_12 = F_3 ( V_127 ) ;
struct V_1 * V_2 = V_8 -> V_13 ;
int V_130 ;
V_130 = 0 ;
if ( ! ( V_2 -> V_18 & V_19 ) && V_2 -> V_5 &&
( V_2 -> V_87 . V_17 != V_129 ) ) {
struct V_82 * V_83 ;
F_35 ( V_2 -> V_5 ) ;
V_2 -> V_18 |= V_19 ;
V_83 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_85 . V_17 = V_83 -> V_17 ;
V_2 -> V_85 . V_86 = V_83 -> V_86 ;
V_83 -> V_17 = V_2 -> V_87 . V_17 ;
V_83 -> V_86 = V_2 -> V_87 . V_86 ;
V_130 = 1 ;
} else if ( ( V_2 -> V_18 & V_19 ) && V_2 -> V_5 &&
( V_2 -> V_5 -> V_4 -> V_25 . V_17 != V_129 ) ) {
V_130 = 2 ;
}
if ( V_130 ) {
F_43 ( V_2 -> V_5 -> V_4 , V_129 ) ;
F_30 ( & V_2 -> V_5 -> V_67 ,
L_9 ) ;
}
if ( V_2 -> V_18 & V_19 ) {
struct V_82 * V_83 ;
V_83 = & V_2 -> V_5 -> V_4 -> V_25 ;
V_2 -> V_87 . V_17 = V_83 -> V_17 ;
V_2 -> V_87 . V_86 = V_83 -> V_86 ;
V_83 -> V_17 = V_2 -> V_85 . V_17 ;
V_83 -> V_86 = V_2 -> V_85 . V_86 ;
F_40 ( V_2 -> V_5 ) ;
if ( V_130 != 1 ) {
F_5 ( V_20 L_10
L_11 , V_12 ) ;
}
}
if ( V_2 -> V_5 ) {
F_56 ( V_2 -> V_5 ) ;
F_29 ( & V_63 , V_2 -> V_60 ) ;
V_2 -> V_5 = NULL ;
F_5 ( V_20 L_12 , V_12 ) ;
}
F_14 ( V_2 ) ;
return 0 ;
}
static unsigned int F_57 ( struct V_8 * V_8 , T_7 * V_131 )
{
struct V_1 * V_2 = V_8 -> V_13 ;
unsigned int V_101 = 0 ;
F_58 ( V_8 , & V_2 -> V_54 , V_131 ) ;
if ( F_44 ( & V_2 -> V_53 ) )
V_101 |= V_132 | V_133 ;
return V_101 ;
}
static void F_59 ( struct V_3 * V_4 )
{
struct V_134 * V_84 ;
if ( V_135 [ V_4 -> V_136 ] )
return;
V_84 = F_60 ( V_137 , V_4 -> V_67 ,
F_61 ( V_138 , V_4 -> V_136 ) , NULL ,
L_13 , V_4 -> V_136 ) ;
if ( F_62 ( V_84 ) ) {
F_63 ( L_14 ,
V_4 -> V_136 ) ;
return;
}
V_135 [ V_4 -> V_136 ] = V_84 ;
}
static void F_64 ( struct V_3 * V_4 )
{
if ( ! V_135 [ V_4 -> V_136 ] )
return;
F_65 ( V_137 , F_61 ( V_138 , V_4 -> V_136 ) ) ;
V_135 [ V_4 -> V_136 ] = NULL ;
}
static int F_66 ( struct V_55 * V_139 )
{
struct V_140 * V_141 = V_139 -> V_67 . V_142 ;
int V_143 = strlen ( V_141 -> V_56 ) ;
if ( strncmp ( V_139 -> V_56 , V_141 -> V_56 , V_143 ) )
return - V_95 ;
return 0 ;
}
static int T_8 F_67 ( void )
{
int V_62 = 0 ;
if ( F_68 ( V_138 , V_20 , & V_144 ) ) {
F_25 ( V_20 L_15 , V_138 ) ;
return - V_117 ;
}
V_137 = F_69 ( V_145 , V_20 ) ;
if ( F_62 ( V_137 ) ) {
V_62 = F_70 ( V_137 ) ;
goto V_146;
}
V_62 = F_71 ( & V_147 ) ;
if ( V_62 < 0 ) {
F_25 ( V_20 L_16 ) ;
goto V_148;
}
F_72 ( V_149 L_17 ) ;
goto V_150;
V_148:
F_73 ( V_137 ) ;
V_146:
F_74 ( V_138 , V_20 ) ;
V_150:
return V_62 ;
}
static void T_9 F_75 ( void )
{
F_76 ( & V_147 ) ;
F_73 ( V_137 ) ;
F_74 ( V_138 , V_20 ) ;
}
