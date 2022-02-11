static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
F_4 ( L_1
L_2 , V_5 -> V_7 ,
V_8 , V_9 ) ;
return 0 ;
}
static void F_5 ( struct V_4 * V_5 )
{
}
static struct V_2 * F_6 ( struct V_4 * V_5 , const char * V_10 )
{
struct V_1 * V_11 = NULL ;
V_11 = F_7 ( sizeof( struct V_1 ) , V_12 ) ;
if ( ! V_11 ) {
F_8 ( L_3 ) ;
return NULL ;
}
F_4 ( L_4 , V_10 ) ;
return & V_11 -> V_3 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 = NULL ;
T_2 V_17 ;
int V_18 = - V_19 ;
if ( ! ( V_11 -> V_20 & V_21 ) ) {
F_8 ( L_5 ) ;
return - V_22 ;
}
V_11 -> V_23 = F_10 ( V_24 , 0 ) ;
if ( ! V_11 -> V_23 ) {
F_8 ( L_6 ) ;
goto V_25;
}
F_4 ( L_7 ,
V_11 -> V_26 ) ;
V_17 = V_27 | V_28 ;
if ( ! V_11 -> V_29 )
V_17 |= V_30 ;
V_16 = F_11 ( V_11 -> V_26 , V_17 , V_11 ) ;
if ( F_12 ( V_16 ) ) {
V_18 = F_13 ( V_16 ) ;
goto V_31;
}
V_11 -> V_32 = V_16 ;
V_14 = F_14 ( V_16 ) ;
V_3 -> V_33 . V_34 = F_15 ( V_16 ) ;
V_3 -> V_33 . V_35 = V_36 ;
V_3 -> V_33 . V_37 = V_14 -> V_38 ;
if ( F_16 ( V_14 ) ) {
V_3 -> V_33 . V_39 =
V_14 -> V_40 . V_41 ;
V_3 -> V_33 . V_42 = 1 ;
V_3 -> V_33 . V_43 =
V_14 -> V_40 . V_44 >> 9 ;
V_3 -> V_33 . V_45 =
V_14 -> V_40 . V_46 ;
F_4 ( L_8
L_9 ) ;
}
V_3 -> V_33 . V_47 = 0xFFFF ;
if ( F_17 ( V_14 ) )
V_3 -> V_33 . V_48 = 1 ;
return 0 ;
V_31:
F_18 ( V_11 -> V_23 ) ;
V_11 -> V_23 = NULL ;
V_25:
return V_18 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 -> V_32 != NULL )
F_20 ( V_11 -> V_32 , V_30 | V_27 | V_28 ) ;
if ( V_11 -> V_23 != NULL )
F_18 ( V_11 -> V_23 ) ;
F_21 ( V_11 ) ;
}
static unsigned long long F_22 (
struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_13 * V_14 )
{
unsigned long long V_49 = ( F_23 ( F_24 ( V_16 -> V_50 ) ,
F_15 ( V_16 ) ) - 1 ) ;
T_1 V_51 = F_15 ( V_16 ) ;
if ( V_51 == V_3 -> V_33 . V_51 )
return V_49 ;
switch ( V_51 ) {
case 4096 :
switch ( V_3 -> V_33 . V_51 ) {
case 2048 :
V_49 <<= 1 ;
break;
case 1024 :
V_49 <<= 2 ;
break;
case 512 :
V_49 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_3 -> V_33 . V_51 ) {
case 4096 :
V_49 >>= 1 ;
break;
case 1024 :
V_49 <<= 1 ;
break;
case 512 :
V_49 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_3 -> V_33 . V_51 ) {
case 4096 :
V_49 >>= 2 ;
break;
case 2048 :
V_49 >>= 1 ;
break;
case 512 :
V_49 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_3 -> V_33 . V_51 ) {
case 4096 :
V_49 >>= 3 ;
break;
case 2048 :
V_49 >>= 2 ;
break;
case 1024 :
V_49 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_49 ;
}
static void F_25 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_53 -> V_56 ;
T_3 V_57 ;
if ( ! F_26 ( & V_55 -> V_58 ) )
return;
if ( F_27 ( & V_55 -> V_59 ) )
V_57 = V_60 ;
else
V_57 = V_61 ;
F_28 ( V_53 , V_57 ) ;
F_21 ( V_55 ) ;
}
static void F_29 ( struct V_62 * V_62 , int V_63 )
{
struct V_52 * V_53 = V_62 -> V_64 ;
struct V_54 * V_55 = V_53 -> V_56 ;
if ( ! F_30 ( V_65 , & V_62 -> V_66 ) && ! V_63 )
V_63 = - V_67 ;
if ( V_63 != 0 ) {
F_8 ( L_10
L_11 , V_62 , V_63 ) ;
F_31 ( & V_55 -> V_59 ) ;
F_32 () ;
}
F_33 ( V_62 ) ;
F_25 ( V_53 ) ;
}
static struct V_62 *
F_34 ( struct V_52 * V_53 , T_4 V_68 , T_1 V_69 )
{
struct V_1 * V_11 = F_1 ( V_53 -> V_70 ) ;
struct V_62 * V_62 ;
if ( V_69 > V_71 )
V_69 = V_71 ;
V_62 = F_35 ( V_72 , V_69 , V_11 -> V_23 ) ;
if ( ! V_62 ) {
F_8 ( L_12 ) ;
return NULL ;
}
V_62 -> V_73 = V_11 -> V_32 ;
V_62 -> V_64 = V_53 ;
V_62 -> V_74 = & F_29 ;
V_62 -> V_75 = V_68 ;
return V_62 ;
}
static void F_36 ( struct V_76 * V_77 , int V_78 )
{
struct V_79 V_80 ;
struct V_62 * V_62 ;
F_37 ( & V_80 ) ;
while ( ( V_62 = F_38 ( V_77 ) ) )
F_39 ( V_78 , V_62 ) ;
F_40 ( & V_80 ) ;
}
static void F_41 ( struct V_62 * V_62 , int V_63 )
{
struct V_52 * V_53 = V_62 -> V_64 ;
if ( V_63 )
F_8 ( L_13 , V_63 ) ;
if ( V_53 ) {
if ( V_63 )
F_28 ( V_53 , V_60 ) ;
else
F_28 ( V_53 , V_61 ) ;
}
F_33 ( V_62 ) ;
}
static T_5
F_42 ( struct V_52 * V_53 )
{
struct V_1 * V_11 = F_1 ( V_53 -> V_70 ) ;
int V_81 = ( V_53 -> V_82 [ 1 ] & 0x2 ) ;
struct V_62 * V_62 ;
if ( V_81 )
F_28 ( V_53 , V_61 ) ;
V_62 = F_43 ( V_12 , 0 ) ;
V_62 -> V_74 = F_41 ;
V_62 -> V_73 = V_11 -> V_32 ;
if ( ! V_81 )
V_62 -> V_64 = V_53 ;
F_39 ( V_83 , V_62 ) ;
return 0 ;
}
static T_5
F_44 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = V_53 -> V_70 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
unsigned char * V_84 , * V_85 = NULL ;
T_4 V_68 ;
int V_86 ;
T_1 V_87 ;
T_5 V_18 = 0 ;
int V_88 , V_89 , V_63 ;
if ( V_53 -> V_82 [ 1 ] )
return V_90 ;
if ( V_53 -> V_91 == 0 ) {
F_28 ( V_53 , V_61 ) ;
return 0 ;
}
if ( V_53 -> V_91 < 8 ) {
F_45 ( L_14 ,
V_53 -> V_91 ) ;
return V_92 ;
}
V_84 = F_46 ( V_53 ) ;
if ( ! V_84 )
return V_93 ;
V_88 = F_47 ( & V_84 [ 0 ] ) ;
V_89 = F_47 ( & V_84 [ 2 ] ) ;
V_86 = V_53 -> V_91 - 8 ;
if ( V_89 > V_86 )
F_45 ( L_15 ,
V_53 -> V_91 , V_89 ) ;
else
V_86 = V_89 ;
if ( V_86 / 16 > V_3 -> V_33 . V_42 ) {
V_18 = V_94 ;
goto V_63;
}
V_85 = & V_84 [ 8 ] ;
F_4 ( L_16
L_17 , V_3 -> V_95 -> V_10 , V_88 , V_89 , V_86 , V_85 ) ;
while ( V_86 >= 16 ) {
V_68 = F_48 ( & V_85 [ 0 ] ) ;
V_87 = F_49 ( & V_85 [ 8 ] ) ;
F_4 ( L_18 ,
( unsigned long long ) V_68 , V_87 ) ;
if ( V_87 > V_3 -> V_33 . V_39 ) {
V_18 = V_94 ;
goto V_63;
}
if ( V_68 + V_87 > V_3 -> V_95 -> V_96 ( V_3 ) + 1 ) {
V_18 = V_97 ;
goto V_63;
}
V_63 = F_50 ( V_11 -> V_32 , V_68 , V_87 ,
V_12 , 0 ) ;
if ( V_63 < 0 ) {
F_8 ( L_19 ,
V_63 ) ;
V_18 = V_93 ;
goto V_63;
}
V_85 += 16 ;
V_86 -= 16 ;
}
V_63:
F_51 ( V_53 ) ;
if ( ! V_18 )
F_28 ( V_53 , V_98 ) ;
return V_18 ;
}
static T_5
F_52 ( struct V_52 * V_53 )
{
struct V_1 * V_11 = F_1 ( V_53 -> V_70 ) ;
int V_99 ;
V_99 = F_50 ( V_11 -> V_32 , V_53 -> V_100 ,
F_53 ( V_53 ) , V_12 , 0 ) ;
if ( V_99 < 0 ) {
F_45 ( L_19 , V_99 ) ;
return V_93 ;
}
F_28 ( V_53 , V_98 ) ;
return 0 ;
}
static T_5
F_54 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_101 * V_102 ;
struct V_62 * V_62 ;
struct V_76 V_77 ;
T_4 V_103 = V_53 -> V_100 ;
T_4 V_104 = F_53 ( V_53 ) ;
V_102 = & V_53 -> V_105 [ 0 ] ;
if ( V_53 -> V_106 > 1 ||
V_102 -> V_107 != V_53 -> V_70 -> V_33 . V_51 ) {
F_8 ( L_20
L_21 , V_53 -> V_106 , V_102 -> V_107 ,
V_53 -> V_70 -> V_33 . V_51 ) ;
return V_90 ;
}
V_55 = F_7 ( sizeof( struct V_54 ) , V_12 ) ;
if ( ! V_55 )
goto V_108;
V_53 -> V_56 = V_55 ;
V_62 = F_34 ( V_53 , V_103 , 1 ) ;
if ( ! V_62 )
goto V_109;
F_55 ( & V_77 ) ;
F_56 ( & V_77 , V_62 ) ;
F_57 ( & V_55 -> V_58 , 1 ) ;
while ( V_104 ) {
while ( F_58 ( V_62 , F_59 ( V_102 ) , V_102 -> V_107 , V_102 -> V_110 )
!= V_102 -> V_107 ) {
V_62 = F_34 ( V_53 , V_103 , 1 ) ;
if ( ! V_62 )
goto V_111;
F_31 ( & V_55 -> V_58 ) ;
F_56 ( & V_77 , V_62 ) ;
}
V_103 += V_102 -> V_107 >> V_112 ;
V_104 -= 1 ;
}
F_36 ( & V_77 , V_113 ) ;
return 0 ;
V_111:
while ( ( V_62 = F_38 ( & V_77 ) ) )
F_33 ( V_62 ) ;
V_109:
F_21 ( V_55 ) ;
V_108:
return V_93 ;
}
static T_6 F_60 ( struct V_2 * V_3 ,
const char * V_114 , T_6 V_115 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_116 , * V_85 , * V_117 , * V_118 ;
T_7 args [ V_119 ] ;
int V_18 = 0 , V_120 ;
unsigned long V_121 ;
V_118 = F_61 ( V_114 , V_12 ) ;
if ( ! V_118 )
return - V_19 ;
V_116 = V_118 ;
while ( ( V_85 = F_62 ( & V_118 , L_22 ) ) != NULL ) {
if ( ! * V_85 )
continue;
V_120 = F_63 ( V_85 , V_122 , args ) ;
switch ( V_120 ) {
case V_123 :
if ( V_11 -> V_32 ) {
F_8 ( L_23
L_24 ) ;
V_18 = - V_124 ;
goto V_25;
}
if ( F_64 ( V_11 -> V_26 , & args [ 0 ] ,
V_125 ) == 0 ) {
V_18 = - V_22 ;
break;
}
F_4 ( L_25 ,
V_11 -> V_26 ) ;
V_11 -> V_20 |= V_21 ;
break;
case V_126 :
V_117 = F_65 ( & args [ 0 ] ) ;
if ( ! V_117 ) {
V_18 = - V_19 ;
break;
}
V_18 = F_66 ( V_117 , 0 , & V_121 ) ;
F_21 ( V_117 ) ;
if ( V_18 < 0 ) {
F_8 ( L_26
L_27 ) ;
goto V_25;
}
V_11 -> V_29 = V_121 ;
F_4 ( L_28 , V_11 -> V_29 ) ;
break;
case V_127 :
break;
default:
break;
}
}
V_25:
F_21 ( V_116 ) ;
return ( ! V_18 ) ? V_115 : V_18 ;
}
static T_6 F_67 ( struct V_2 * V_3 , char * V_128 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
char V_84 [ V_129 ] ;
T_6 V_130 = 0 ;
if ( V_16 )
V_130 += sprintf ( V_128 + V_130 , L_29 ,
F_68 ( V_16 , V_84 ) ) ;
if ( V_11 -> V_20 & V_21 )
V_130 += sprintf ( V_128 + V_130 , L_30 ,
V_11 -> V_26 ) ;
V_130 += sprintf ( V_128 + V_130 , L_31 , V_11 -> V_29 ) ;
V_130 += sprintf ( V_128 + V_130 , L_32 ) ;
if ( V_16 ) {
V_130 += sprintf ( V_128 + V_130 , L_33 ,
F_69 ( V_16 -> V_131 ) , F_70 ( V_16 -> V_131 ) , ( ! V_16 -> V_132 ) ?
L_34 : ( V_16 -> V_133 == V_11 ) ?
L_35 : L_36 ) ;
} else {
V_130 += sprintf ( V_128 + V_130 , L_37 ) ;
}
return V_130 ;
}
static T_5
F_71 ( struct V_52 * V_53 )
{
struct V_101 * V_134 = V_53 -> V_105 ;
T_1 V_135 = V_53 -> V_106 ;
enum V_136 V_137 = V_53 -> V_137 ;
struct V_2 * V_3 = V_53 -> V_70 ;
struct V_54 * V_55 ;
struct V_62 * V_62 ;
struct V_76 V_77 ;
struct V_101 * V_102 ;
T_1 V_69 = V_135 ;
T_4 V_103 ;
unsigned V_138 ;
int V_78 = 0 ;
int V_139 ;
if ( V_137 == V_140 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_32 ) ;
if ( V_14 -> V_141 & V_142 ) {
if ( V_53 -> V_143 & V_144 )
V_78 = V_145 ;
else if ( ! ( V_14 -> V_141 & V_146 ) )
V_78 = V_145 ;
} else {
V_78 = V_113 ;
}
} else {
V_78 = V_147 ;
}
if ( V_3 -> V_33 . V_51 == 4096 )
V_103 = ( V_53 -> V_100 << 3 ) ;
else if ( V_3 -> V_33 . V_51 == 2048 )
V_103 = ( V_53 -> V_100 << 2 ) ;
else if ( V_3 -> V_33 . V_51 == 1024 )
V_103 = ( V_53 -> V_100 << 1 ) ;
else if ( V_3 -> V_33 . V_51 == 512 )
V_103 = V_53 -> V_100 ;
else {
F_8 ( L_38
L_39 , V_3 -> V_33 . V_51 ) ;
return V_93 ;
}
V_55 = F_7 ( sizeof( struct V_54 ) , V_12 ) ;
if ( ! V_55 )
goto V_108;
V_53 -> V_56 = V_55 ;
if ( ! V_135 ) {
F_57 ( & V_55 -> V_58 , 1 ) ;
F_25 ( V_53 ) ;
return 0 ;
}
V_62 = F_34 ( V_53 , V_103 , V_135 ) ;
if ( ! V_62 )
goto V_109;
F_55 ( & V_77 ) ;
F_56 ( & V_77 , V_62 ) ;
F_57 ( & V_55 -> V_58 , 2 ) ;
V_138 = 1 ;
F_72 (sgl, sg, sgl_nents, i) {
while ( F_58 ( V_62 , F_59 ( V_102 ) , V_102 -> V_107 , V_102 -> V_110 )
!= V_102 -> V_107 ) {
if ( V_138 >= V_148 ) {
F_36 ( & V_77 , V_78 ) ;
V_138 = 0 ;
}
V_62 = F_34 ( V_53 , V_103 , V_69 ) ;
if ( ! V_62 )
goto V_111;
F_31 ( & V_55 -> V_58 ) ;
F_56 ( & V_77 , V_62 ) ;
V_138 ++ ;
}
V_103 += V_102 -> V_107 >> V_112 ;
V_69 -- ;
}
F_36 ( & V_77 , V_78 ) ;
F_25 ( V_53 ) ;
return 0 ;
V_111:
while ( ( V_62 = F_38 ( & V_77 ) ) )
F_33 ( V_62 ) ;
V_109:
F_21 ( V_55 ) ;
V_108:
return V_93 ;
}
static T_4 F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_22 ( V_3 , V_16 , V_14 ) ;
}
static T_5
F_74 ( struct V_52 * V_53 )
{
return F_75 ( V_53 , & V_149 ) ;
}
bool F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return V_14 -> V_141 & V_146 ;
}
static int T_8 F_77 ( void )
{
return F_78 ( & V_150 ) ;
}
static void T_9 F_79 ( void )
{
F_80 ( & V_150 ) ;
}
