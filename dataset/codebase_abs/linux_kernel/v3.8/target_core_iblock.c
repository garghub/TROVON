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
if ( V_53 -> V_90 < 8 ) {
F_45 ( L_14 ,
V_53 -> V_90 ) ;
return V_91 ;
}
V_84 = F_46 ( V_53 ) ;
if ( ! V_84 )
return V_92 ;
V_88 = F_47 ( & V_84 [ 0 ] ) ;
V_89 = F_47 ( & V_84 [ 2 ] ) ;
V_86 = V_53 -> V_90 - 8 ;
if ( V_89 > V_86 )
F_45 ( L_15 ,
V_53 -> V_90 , V_89 ) ;
else
V_86 = V_89 ;
if ( V_86 / 16 > V_3 -> V_33 . V_42 ) {
V_18 = V_91 ;
goto V_63;
}
V_85 = & V_84 [ 8 ] ;
F_4 ( L_16
L_17 , V_3 -> V_93 -> V_10 , V_88 , V_89 , V_86 , V_85 ) ;
while ( V_86 >= 16 ) {
V_68 = F_48 ( & V_85 [ 0 ] ) ;
V_87 = F_49 ( & V_85 [ 8 ] ) ;
F_4 ( L_18 ,
( unsigned long long ) V_68 , V_87 ) ;
if ( V_87 > V_3 -> V_33 . V_39 ) {
V_18 = V_91 ;
goto V_63;
}
if ( V_68 + V_87 > V_3 -> V_93 -> V_94 ( V_3 ) + 1 ) {
V_18 = V_95 ;
goto V_63;
}
V_63 = F_50 ( V_11 -> V_32 , V_68 , V_87 ,
V_12 , 0 ) ;
if ( V_63 < 0 ) {
F_8 ( L_19 ,
V_63 ) ;
V_18 = V_92 ;
goto V_63;
}
V_85 += 16 ;
V_86 -= 16 ;
}
V_63:
F_51 ( V_53 ) ;
if ( ! V_18 )
F_28 ( V_53 , V_96 ) ;
return V_18 ;
}
static T_5
F_52 ( struct V_52 * V_53 )
{
struct V_1 * V_11 = F_1 ( V_53 -> V_70 ) ;
int V_97 ;
V_97 = F_50 ( V_11 -> V_32 , V_53 -> V_98 ,
F_53 ( V_53 ) , V_12 , 0 ) ;
if ( V_97 < 0 ) {
F_45 ( L_19 , V_97 ) ;
return V_92 ;
}
F_28 ( V_53 , V_96 ) ;
return 0 ;
}
static T_5
F_54 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_99 * V_100 ;
struct V_62 * V_62 ;
struct V_76 V_77 ;
T_4 V_101 = V_53 -> V_98 ;
T_4 V_102 = F_53 ( V_53 ) ;
V_100 = & V_53 -> V_103 [ 0 ] ;
if ( V_53 -> V_104 > 1 ||
V_100 -> V_105 != V_53 -> V_70 -> V_33 . V_51 ) {
F_8 ( L_20
L_21 , V_53 -> V_104 , V_100 -> V_105 ,
V_53 -> V_70 -> V_33 . V_51 ) ;
return V_106 ;
}
V_55 = F_7 ( sizeof( struct V_54 ) , V_12 ) ;
if ( ! V_55 )
goto V_107;
V_53 -> V_56 = V_55 ;
V_62 = F_34 ( V_53 , V_101 , 1 ) ;
if ( ! V_62 )
goto V_108;
F_55 ( & V_77 ) ;
F_56 ( & V_77 , V_62 ) ;
F_57 ( & V_55 -> V_58 , 1 ) ;
while ( V_102 ) {
while ( F_58 ( V_62 , F_59 ( V_100 ) , V_100 -> V_105 , V_100 -> V_109 )
!= V_100 -> V_105 ) {
V_62 = F_34 ( V_53 , V_101 , 1 ) ;
if ( ! V_62 )
goto V_110;
F_31 ( & V_55 -> V_58 ) ;
F_56 ( & V_77 , V_62 ) ;
}
V_101 += V_100 -> V_105 >> V_111 ;
V_102 -= 1 ;
}
F_36 ( & V_77 , V_112 ) ;
return 0 ;
V_110:
while ( ( V_62 = F_38 ( & V_77 ) ) )
F_33 ( V_62 ) ;
V_108:
F_21 ( V_55 ) ;
V_107:
return V_92 ;
}
static T_6 F_60 ( struct V_2 * V_3 ,
const char * V_113 , T_6 V_114 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_115 , * V_85 , * V_116 , * V_117 ;
T_7 args [ V_118 ] ;
int V_18 = 0 , V_119 ;
unsigned long V_120 ;
V_117 = F_61 ( V_113 , V_12 ) ;
if ( ! V_117 )
return - V_19 ;
V_115 = V_117 ;
while ( ( V_85 = F_62 ( & V_117 , L_22 ) ) != NULL ) {
if ( ! * V_85 )
continue;
V_119 = F_63 ( V_85 , V_121 , args ) ;
switch ( V_119 ) {
case V_122 :
if ( V_11 -> V_32 ) {
F_8 ( L_23
L_24 ) ;
V_18 = - V_123 ;
goto V_25;
}
if ( F_64 ( V_11 -> V_26 , & args [ 0 ] ,
V_124 ) == 0 ) {
V_18 = - V_22 ;
break;
}
F_4 ( L_25 ,
V_11 -> V_26 ) ;
V_11 -> V_20 |= V_21 ;
break;
case V_125 :
V_116 = F_65 ( & args [ 0 ] ) ;
if ( ! V_116 ) {
V_18 = - V_19 ;
break;
}
V_18 = F_66 ( V_116 , 0 , & V_120 ) ;
F_21 ( V_116 ) ;
if ( V_18 < 0 ) {
F_8 ( L_26
L_27 ) ;
goto V_25;
}
V_11 -> V_29 = V_120 ;
F_4 ( L_28 , V_11 -> V_29 ) ;
break;
case V_126 :
break;
default:
break;
}
}
V_25:
F_21 ( V_115 ) ;
return ( ! V_18 ) ? V_114 : V_18 ;
}
static T_6 F_67 ( struct V_2 * V_3 , char * V_127 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
char V_84 [ V_128 ] ;
T_6 V_129 = 0 ;
if ( V_16 )
V_129 += sprintf ( V_127 + V_129 , L_29 ,
F_68 ( V_16 , V_84 ) ) ;
if ( V_11 -> V_20 & V_21 )
V_129 += sprintf ( V_127 + V_129 , L_30 ,
V_11 -> V_26 ) ;
V_129 += sprintf ( V_127 + V_129 , L_31 , V_11 -> V_29 ) ;
V_129 += sprintf ( V_127 + V_129 , L_32 ) ;
if ( V_16 ) {
V_129 += sprintf ( V_127 + V_129 , L_33 ,
F_69 ( V_16 -> V_130 ) , F_70 ( V_16 -> V_130 ) , ( ! V_16 -> V_131 ) ?
L_34 : ( V_16 -> V_132 == V_11 ) ?
L_35 : L_36 ) ;
} else {
V_129 += sprintf ( V_127 + V_129 , L_37 ) ;
}
return V_129 ;
}
static T_5
F_71 ( struct V_52 * V_53 )
{
struct V_99 * V_133 = V_53 -> V_103 ;
T_1 V_134 = V_53 -> V_104 ;
enum V_135 V_136 = V_53 -> V_136 ;
struct V_2 * V_3 = V_53 -> V_70 ;
struct V_54 * V_55 ;
struct V_62 * V_62 ;
struct V_76 V_77 ;
struct V_99 * V_100 ;
T_1 V_69 = V_134 ;
T_4 V_101 ;
unsigned V_137 ;
int V_78 ;
int V_138 ;
if ( V_136 == V_139 ) {
if ( V_3 -> V_33 . V_140 == 0 ||
( V_3 -> V_33 . V_141 > 0 &&
( V_53 -> V_142 & V_143 ) ) )
V_78 = V_144 ;
else
V_78 = V_112 ;
} else {
V_78 = V_145 ;
}
if ( V_3 -> V_33 . V_51 == 4096 )
V_101 = ( V_53 -> V_98 << 3 ) ;
else if ( V_3 -> V_33 . V_51 == 2048 )
V_101 = ( V_53 -> V_98 << 2 ) ;
else if ( V_3 -> V_33 . V_51 == 1024 )
V_101 = ( V_53 -> V_98 << 1 ) ;
else if ( V_3 -> V_33 . V_51 == 512 )
V_101 = V_53 -> V_98 ;
else {
F_8 ( L_38
L_39 , V_3 -> V_33 . V_51 ) ;
return V_92 ;
}
V_55 = F_7 ( sizeof( struct V_54 ) , V_12 ) ;
if ( ! V_55 )
goto V_107;
V_53 -> V_56 = V_55 ;
if ( ! V_134 ) {
F_57 ( & V_55 -> V_58 , 1 ) ;
F_25 ( V_53 ) ;
return 0 ;
}
V_62 = F_34 ( V_53 , V_101 , V_134 ) ;
if ( ! V_62 )
goto V_108;
F_55 ( & V_77 ) ;
F_56 ( & V_77 , V_62 ) ;
F_57 ( & V_55 -> V_58 , 2 ) ;
V_137 = 1 ;
F_72 (sgl, sg, sgl_nents, i) {
while ( F_58 ( V_62 , F_59 ( V_100 ) , V_100 -> V_105 , V_100 -> V_109 )
!= V_100 -> V_105 ) {
if ( V_137 >= V_146 ) {
F_36 ( & V_77 , V_78 ) ;
V_137 = 0 ;
}
V_62 = F_34 ( V_53 , V_101 , V_69 ) ;
if ( ! V_62 )
goto V_110;
F_31 ( & V_55 -> V_58 ) ;
F_56 ( & V_77 , V_62 ) ;
V_137 ++ ;
}
V_101 += V_100 -> V_105 >> V_111 ;
V_69 -- ;
}
F_36 ( & V_77 , V_78 ) ;
F_25 ( V_53 ) ;
return 0 ;
V_110:
while ( ( V_62 = F_38 ( & V_77 ) ) )
F_33 ( V_62 ) ;
V_108:
F_21 ( V_55 ) ;
V_107:
return V_92 ;
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
return F_75 ( V_53 , & V_147 ) ;
}
static int T_8 F_76 ( void )
{
return F_77 ( & V_148 ) ;
}
static void F_78 ( void )
{
F_79 ( & V_148 ) ;
}
