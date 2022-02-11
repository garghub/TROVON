static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( L_1
L_2 , V_2 -> V_4 ,
V_5 , V_6 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
}
static void * F_4 ( struct V_1 * V_2 , const char * V_7 )
{
struct V_8 * V_9 = NULL ;
V_9 = F_5 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_9 ) {
F_6 ( L_3 ) ;
return NULL ;
}
F_2 ( L_4 , V_7 ) ;
return V_9 ;
}
static struct V_11 * F_7 (
struct V_1 * V_2 ,
struct V_12 * V_13 ,
void * V_14 )
{
struct V_8 * V_9 = V_14 ;
struct V_11 * V_15 ;
struct V_16 V_17 ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
T_1 V_24 = 0 ;
int V_25 = - V_26 ;
if ( ! V_9 ) {
F_6 ( L_5 ) ;
return F_8 ( V_25 ) ;
}
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_9 -> V_27 = F_9 ( V_28 , 0 ) ;
if ( ! V_9 -> V_27 ) {
F_6 ( L_6 ) ;
return F_8 ( - V_29 ) ;
}
F_2 ( L_7 ) ;
F_2 ( L_8 ,
V_9 -> V_30 ) ;
V_19 = F_10 ( V_9 -> V_30 ,
V_31 | V_32 | V_33 , V_9 ) ;
if ( F_11 ( V_19 ) ) {
V_25 = F_12 ( V_19 ) ;
goto V_34;
}
V_21 = F_13 ( V_19 ) ;
V_23 = & V_17 . V_23 ;
V_23 -> V_35 = F_14 ( V_19 ) ;
V_23 -> V_36 = V_37 ;
V_23 -> V_38 = V_37 ;
V_17 . V_39 = V_21 -> V_40 ;
V_17 . V_41 = V_21 -> V_40 ;
V_9 -> V_42 = V_19 ;
V_15 = F_15 ( V_2 ,
& V_43 , V_13 , V_24 , V_9 ,
& V_17 , L_9 , V_5 ) ;
if ( ! V_15 )
goto V_34;
if ( F_16 ( V_21 ) ) {
V_15 -> V_44 -> V_45 . V_46 =
V_21 -> V_23 . V_47 ;
V_15 -> V_44 -> V_45 . V_48 = 1 ;
V_15 -> V_44 -> V_45 . V_49 =
V_21 -> V_23 . V_50 >> 9 ;
V_15 -> V_44 -> V_45 . V_51 =
V_21 -> V_23 . V_52 ;
F_2 ( L_10
L_11 ) ;
}
if ( F_17 ( V_21 ) )
V_15 -> V_44 -> V_45 . V_53 = 1 ;
return V_15 ;
V_34:
if ( V_9 -> V_27 ) {
F_18 ( V_9 -> V_27 ) ;
V_9 -> V_27 = NULL ;
}
V_9 -> V_42 = NULL ;
return F_8 ( V_25 ) ;
}
static void F_19 ( void * V_14 )
{
struct V_8 * V_9 = V_14 ;
if ( V_9 -> V_42 != NULL )
F_20 ( V_9 -> V_42 , V_31 | V_32 | V_33 ) ;
if ( V_9 -> V_27 != NULL )
F_18 ( V_9 -> V_27 ) ;
F_21 ( V_9 ) ;
}
static unsigned long long F_22 (
struct V_11 * V_15 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
unsigned long long V_54 = ( F_23 ( F_24 ( V_19 -> V_55 ) ,
F_14 ( V_19 ) ) - 1 ) ;
T_1 V_56 = F_14 ( V_19 ) ;
if ( V_56 == V_15 -> V_44 -> V_45 . V_56 )
return V_54 ;
switch ( V_56 ) {
case 4096 :
switch ( V_15 -> V_44 -> V_45 . V_56 ) {
case 2048 :
V_54 <<= 1 ;
break;
case 1024 :
V_54 <<= 2 ;
break;
case 512 :
V_54 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_15 -> V_44 -> V_45 . V_56 ) {
case 4096 :
V_54 >>= 1 ;
break;
case 1024 :
V_54 <<= 1 ;
break;
case 512 :
V_54 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_15 -> V_44 -> V_45 . V_56 ) {
case 4096 :
V_54 >>= 2 ;
break;
case 2048 :
V_54 >>= 1 ;
break;
case 512 :
V_54 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_15 -> V_44 -> V_45 . V_56 ) {
case 4096 :
V_54 >>= 3 ;
break;
case 2048 :
V_54 >>= 2 ;
break;
case 1024 :
V_54 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_54 ;
}
static void F_25 ( struct V_57 * V_57 , int V_58 )
{
struct V_59 * V_60 = V_57 -> V_61 ;
if ( V_58 )
F_6 ( L_12 , V_58 ) ;
if ( V_60 ) {
if ( V_58 ) {
V_60 -> V_62 =
V_63 ;
F_26 ( V_60 , V_64 ) ;
} else {
F_26 ( V_60 , V_65 ) ;
}
}
F_27 ( V_57 ) ;
}
static void F_28 ( struct V_59 * V_60 )
{
struct V_8 * V_9 = V_60 -> V_13 -> V_66 ;
int V_67 = ( V_60 -> V_68 [ 1 ] & 0x2 ) ;
struct V_57 * V_57 ;
if ( V_67 )
F_26 ( V_60 , V_65 ) ;
V_57 = F_29 ( V_10 , 0 ) ;
V_57 -> V_69 = F_25 ;
V_57 -> V_70 = V_9 -> V_42 ;
if ( ! V_67 )
V_57 -> V_61 = V_60 ;
F_30 ( V_71 , V_57 ) ;
}
static int F_31 ( struct V_11 * V_15 , T_2 V_72 , T_1 V_73 )
{
struct V_8 * V_74 = V_15 -> V_66 ;
struct V_18 * V_19 = V_74 -> V_42 ;
int V_75 = 0 ;
return F_32 ( V_19 , V_72 , V_73 , V_10 , V_75 ) ;
}
static T_3 F_33 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
const char * V_76 , T_3 V_77 )
{
struct V_8 * V_9 = V_13 -> V_78 ;
char * V_79 , * V_80 , * V_81 , * V_82 ;
T_4 args [ V_83 ] ;
int V_25 = 0 , V_84 ;
V_82 = F_34 ( V_76 , V_10 ) ;
if ( ! V_82 )
return - V_29 ;
V_79 = V_82 ;
while ( ( V_80 = F_35 ( & V_82 , L_13 ) ) != NULL ) {
if ( ! * V_80 )
continue;
V_84 = F_36 ( V_80 , V_85 , args ) ;
switch ( V_84 ) {
case V_86 :
if ( V_9 -> V_42 ) {
F_6 ( L_14
L_15 ) ;
V_25 = - V_87 ;
goto V_88;
}
V_81 = F_37 ( & args [ 0 ] ) ;
if ( ! V_81 ) {
V_25 = - V_29 ;
break;
}
snprintf ( V_9 -> V_30 , V_89 ,
L_16 , V_81 ) ;
F_21 ( V_81 ) ;
F_2 ( L_17 ,
V_9 -> V_30 ) ;
V_9 -> V_90 |= V_91 ;
break;
case V_92 :
break;
default:
break;
}
}
V_88:
F_21 ( V_79 ) ;
return ( ! V_25 ) ? V_77 : V_25 ;
}
static T_3 F_38 (
struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_8 * V_74 = V_13 -> V_78 ;
if ( ! ( V_74 -> V_90 & V_91 ) ) {
F_6 ( L_18 ) ;
return - V_26 ;
}
return 0 ;
}
static T_3 F_39 (
struct V_1 * V_2 ,
struct V_12 * V_13 ,
char * V_93 )
{
struct V_8 * V_74 = V_13 -> V_78 ;
struct V_18 * V_19 = V_74 -> V_42 ;
char V_94 [ V_95 ] ;
T_3 V_96 = 0 ;
if ( V_19 )
V_96 += sprintf ( V_93 + V_96 , L_19 ,
F_40 ( V_19 , V_94 ) ) ;
if ( V_74 -> V_90 & V_91 ) {
V_96 += sprintf ( V_93 + V_96 , L_20 ,
V_74 -> V_30 ) ;
} else
V_96 += sprintf ( V_93 + V_96 , L_21 ) ;
V_96 += sprintf ( V_93 + V_96 , L_22 ) ;
if ( V_19 ) {
V_96 += sprintf ( V_93 + V_96 , L_23 ,
F_41 ( V_19 -> V_97 ) , F_42 ( V_19 -> V_97 ) , ( ! V_19 -> V_98 ) ?
L_24 : ( V_19 -> V_99 == V_74 ) ?
L_25 : L_26 ) ;
} else {
V_96 += sprintf ( V_93 + V_96 , L_27 ) ;
}
return V_96 ;
}
static void F_43 ( struct V_59 * V_60 )
{
struct V_100 * V_101 = V_60 -> V_102 ;
T_5 V_103 ;
if ( ! F_44 ( & V_101 -> V_104 ) )
return;
if ( F_45 ( & V_101 -> V_105 ) )
V_103 = V_64 ;
else
V_103 = V_65 ;
F_26 ( V_60 , V_103 ) ;
F_21 ( V_101 ) ;
}
static void F_46 ( struct V_57 * V_57 )
{
struct V_59 * V_60 = V_57 -> V_61 ;
struct V_8 * V_9 = V_60 -> V_13 -> V_66 ;
F_47 ( V_57 , V_9 -> V_27 ) ;
}
static struct V_57 *
F_48 ( struct V_59 * V_60 , T_2 V_72 , T_1 V_106 )
{
struct V_8 * V_9 = V_60 -> V_13 -> V_66 ;
struct V_57 * V_57 ;
if ( V_106 > V_107 )
V_106 = V_107 ;
V_57 = F_49 ( V_108 , V_106 , V_9 -> V_27 ) ;
if ( ! V_57 ) {
F_6 ( L_28 ) ;
return NULL ;
}
V_57 -> V_70 = V_9 -> V_42 ;
V_57 -> V_61 = V_60 ;
V_57 -> V_109 = F_46 ;
V_57 -> V_69 = & V_110 ;
V_57 -> V_111 = V_72 ;
return V_57 ;
}
static void F_50 ( struct V_112 * V_113 , int V_114 )
{
struct V_115 V_116 ;
struct V_57 * V_57 ;
F_51 ( & V_116 ) ;
while ( ( V_57 = F_52 ( V_113 ) ) )
F_30 ( V_114 , V_57 ) ;
F_53 ( & V_116 ) ;
}
static int F_54 ( struct V_59 * V_60 , struct V_117 * V_118 ,
T_1 V_119 , enum V_120 V_121 )
{
struct V_11 * V_15 = V_60 -> V_13 ;
struct V_100 * V_101 ;
struct V_57 * V_57 ;
struct V_112 V_113 ;
struct V_117 * V_122 ;
T_1 V_106 = V_119 ;
T_2 V_123 ;
unsigned V_124 ;
int V_114 ;
int V_125 ;
if ( V_121 == V_126 ) {
if ( V_15 -> V_44 -> V_45 . V_127 == 0 ||
( V_15 -> V_44 -> V_45 . V_128 > 0 &&
( V_60 -> V_129 & V_130 ) ) )
V_114 = V_131 ;
else
V_114 = V_132 ;
} else {
V_114 = V_133 ;
}
if ( V_15 -> V_44 -> V_45 . V_56 == 4096 )
V_123 = ( V_60 -> V_134 << 3 ) ;
else if ( V_15 -> V_44 -> V_45 . V_56 == 2048 )
V_123 = ( V_60 -> V_134 << 2 ) ;
else if ( V_15 -> V_44 -> V_45 . V_56 == 1024 )
V_123 = ( V_60 -> V_134 << 1 ) ;
else if ( V_15 -> V_44 -> V_45 . V_56 == 512 )
V_123 = V_60 -> V_134 ;
else {
F_6 ( L_29
L_30 , V_15 -> V_44 -> V_45 . V_56 ) ;
V_60 -> V_62 = V_63 ;
return - V_135 ;
}
V_101 = F_5 ( sizeof( struct V_100 ) , V_10 ) ;
if ( ! V_101 )
goto V_136;
V_60 -> V_102 = V_101 ;
V_57 = F_48 ( V_60 , V_123 , V_119 ) ;
if ( ! V_57 )
goto V_137;
F_55 ( & V_113 ) ;
F_56 ( & V_113 , V_57 ) ;
F_57 ( & V_101 -> V_104 , 2 ) ;
V_124 = 1 ;
F_58 (sgl, sg, sgl_nents, i) {
while ( F_59 ( V_57 , F_60 ( V_122 ) , V_122 -> V_138 , V_122 -> V_139 )
!= V_122 -> V_138 ) {
if ( V_124 >= V_140 ) {
F_50 ( & V_113 , V_114 ) ;
V_124 = 0 ;
}
V_57 = F_48 ( V_60 , V_123 , V_106 ) ;
if ( ! V_57 )
goto V_141;
F_61 ( & V_101 -> V_104 ) ;
F_56 ( & V_113 , V_57 ) ;
V_124 ++ ;
}
V_123 += V_122 -> V_138 >> V_142 ;
V_106 -- ;
}
F_50 ( & V_113 , V_114 ) ;
F_43 ( V_60 ) ;
return 0 ;
V_141:
while ( ( V_57 = F_52 ( & V_113 ) ) )
F_27 ( V_57 ) ;
V_137:
F_21 ( V_101 ) ;
V_60 -> V_62 = V_63 ;
V_136:
return - V_29 ;
}
static T_1 F_62 ( struct V_11 * V_15 )
{
return V_143 ;
}
static T_1 F_63 ( struct V_11 * V_15 )
{
return V_144 ;
}
static T_2 F_64 ( struct V_11 * V_15 )
{
struct V_8 * V_74 = V_15 -> V_66 ;
struct V_18 * V_19 = V_74 -> V_42 ;
struct V_20 * V_21 = F_13 ( V_19 ) ;
return F_22 ( V_15 , V_19 , V_21 ) ;
}
static void V_110 ( struct V_57 * V_57 , int V_58 )
{
struct V_59 * V_60 = V_57 -> V_61 ;
struct V_100 * V_101 = V_60 -> V_102 ;
if ( ! F_65 ( V_145 , & V_57 -> V_146 ) && ! V_58 )
V_58 = - V_147 ;
if ( V_58 != 0 ) {
F_6 ( L_31
L_32 , V_57 , V_58 ) ;
F_61 ( & V_101 -> V_105 ) ;
F_66 () ;
}
F_27 ( V_57 ) ;
F_43 ( V_60 ) ;
}
static int T_6 F_67 ( void )
{
return F_68 ( & V_43 ) ;
}
static void F_69 ( void )
{
F_70 ( & V_43 ) ;
}
