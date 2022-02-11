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
struct V_17 * V_18 ;
T_2 V_19 ;
int V_20 = - V_21 ;
if ( ! ( V_11 -> V_22 & V_23 ) ) {
F_8 ( L_5 ) ;
return - V_24 ;
}
V_11 -> V_25 = F_10 ( V_26 , 0 ) ;
if ( ! V_11 -> V_25 ) {
F_8 ( L_6 ) ;
goto V_27;
}
F_4 ( L_7 ,
V_11 -> V_28 ) ;
V_19 = V_29 | V_30 ;
if ( ! V_11 -> V_31 )
V_19 |= V_32 ;
else
V_3 -> V_33 |= V_34 ;
V_16 = F_11 ( V_11 -> V_28 , V_19 , V_11 ) ;
if ( F_12 ( V_16 ) ) {
V_20 = F_13 ( V_16 ) ;
goto V_35;
}
V_11 -> V_36 = V_16 ;
V_14 = F_14 ( V_16 ) ;
V_3 -> V_37 . V_38 = F_15 ( V_16 ) ;
V_3 -> V_37 . V_39 = F_16 ( V_14 ) ;
V_3 -> V_37 . V_40 = V_14 -> V_41 ;
if ( F_17 ( V_14 ) ) {
V_3 -> V_37 . V_42 =
V_14 -> V_43 . V_44 ;
V_3 -> V_37 . V_45 = 1 ;
V_3 -> V_37 . V_46 =
V_14 -> V_43 . V_47 >> 9 ;
V_3 -> V_37 . V_48 =
V_14 -> V_43 . V_49 ;
F_4 ( L_8
L_9 ) ;
}
V_3 -> V_37 . V_50 = 0xFFFF ;
if ( F_18 ( V_14 ) )
V_3 -> V_37 . V_51 = 1 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 ) {
struct V_52 * V_53 = V_11 -> V_25 ;
if ( ! strcmp ( V_18 -> V_10 , L_10 ) ||
! strcmp ( V_18 -> V_10 , L_11 ) ) {
F_8 ( L_12
L_13 , V_18 -> V_10 ) ;
V_20 = - V_54 ;
goto V_55;
}
if ( ! strcmp ( V_18 -> V_10 , L_14 ) ) {
V_3 -> V_37 . V_56 = V_57 ;
} else if ( ! strcmp ( V_18 -> V_10 , L_15 ) ) {
V_3 -> V_37 . V_56 = V_58 ;
}
if ( V_3 -> V_37 . V_56 ) {
if ( F_20 ( V_53 , V_26 ) < 0 ) {
F_8 ( L_16 ) ;
V_20 = - V_21 ;
goto V_55;
}
F_4 ( L_17 ,
V_53 -> V_59 ) ;
}
V_3 -> V_37 . V_60 = V_3 -> V_37 . V_56 ;
}
return 0 ;
V_55:
F_21 ( V_11 -> V_36 , V_32 | V_29 | V_30 ) ;
V_35:
F_22 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
V_27:
return V_20 ;
}
static void F_23 ( struct V_61 * V_62 )
{
struct V_2 * V_3 = F_2 ( V_62 , struct V_2 , V_61 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
F_24 ( V_11 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 -> V_36 != NULL )
F_21 ( V_11 -> V_36 , V_32 | V_29 | V_30 ) ;
if ( V_11 -> V_25 != NULL )
F_22 ( V_11 -> V_25 ) ;
F_26 ( & V_3 -> V_61 , F_23 ) ;
}
static unsigned long long F_27 (
struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_13 * V_14 )
{
unsigned long long V_63 = ( F_28 ( F_29 ( V_16 -> V_64 ) ,
F_15 ( V_16 ) ) - 1 ) ;
T_1 V_65 = F_15 ( V_16 ) ;
if ( V_65 == V_3 -> V_37 . V_65 )
return V_63 ;
switch ( V_65 ) {
case 4096 :
switch ( V_3 -> V_37 . V_65 ) {
case 2048 :
V_63 <<= 1 ;
break;
case 1024 :
V_63 <<= 2 ;
break;
case 512 :
V_63 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_3 -> V_37 . V_65 ) {
case 4096 :
V_63 >>= 1 ;
break;
case 1024 :
V_63 <<= 1 ;
break;
case 512 :
V_63 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_3 -> V_37 . V_65 ) {
case 4096 :
V_63 >>= 2 ;
break;
case 2048 :
V_63 >>= 1 ;
break;
case 512 :
V_63 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_3 -> V_37 . V_65 ) {
case 4096 :
V_63 >>= 3 ;
break;
case 2048 :
V_63 >>= 2 ;
break;
case 1024 :
V_63 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_63 ;
}
static void F_30 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 ;
T_3 V_71 ;
if ( ! F_31 ( & V_69 -> V_72 ) )
return;
if ( F_32 ( & V_69 -> V_73 ) )
V_71 = V_74 ;
else
V_71 = V_75 ;
F_33 ( V_67 , V_71 ) ;
F_24 ( V_69 ) ;
}
static void F_34 ( struct V_76 * V_76 )
{
struct V_66 * V_67 = V_76 -> V_77 ;
struct V_68 * V_69 = V_67 -> V_70 ;
if ( V_76 -> V_78 ) {
F_8 ( L_18 , V_76 , V_76 -> V_78 ) ;
F_35 ( & V_69 -> V_73 ) ;
F_36 () ;
}
F_37 ( V_76 ) ;
F_30 ( V_67 ) ;
}
static struct V_76 *
F_38 ( struct V_66 * V_67 , T_4 V_79 , T_1 V_80 )
{
struct V_1 * V_11 = F_1 ( V_67 -> V_81 ) ;
struct V_76 * V_76 ;
if ( V_80 > V_82 )
V_80 = V_82 ;
V_76 = F_39 ( V_83 , V_80 , V_11 -> V_25 ) ;
if ( ! V_76 ) {
F_8 ( L_19 ) ;
return NULL ;
}
V_76 -> V_84 = V_11 -> V_36 ;
V_76 -> V_77 = V_67 ;
V_76 -> V_85 = & F_34 ;
V_76 -> V_86 . V_87 = V_79 ;
return V_76 ;
}
static void F_40 ( struct V_88 * V_89 , int V_90 )
{
struct V_91 V_92 ;
struct V_76 * V_76 ;
F_41 ( & V_92 ) ;
while ( ( V_76 = F_42 ( V_89 ) ) )
F_43 ( V_90 , V_76 ) ;
F_44 ( & V_92 ) ;
}
static void F_45 ( struct V_76 * V_76 )
{
struct V_66 * V_67 = V_76 -> V_77 ;
if ( V_76 -> V_78 )
F_8 ( L_20 , V_76 -> V_78 ) ;
if ( V_67 ) {
if ( V_76 -> V_78 )
F_33 ( V_67 , V_74 ) ;
else
F_33 ( V_67 , V_75 ) ;
}
F_37 ( V_76 ) ;
}
static T_5
F_46 ( struct V_66 * V_67 )
{
struct V_1 * V_11 = F_1 ( V_67 -> V_81 ) ;
int V_93 = ( V_67 -> V_94 [ 1 ] & 0x2 ) ;
struct V_76 * V_76 ;
if ( V_93 )
F_33 ( V_67 , V_75 ) ;
V_76 = F_47 ( V_12 , 0 ) ;
V_76 -> V_85 = F_45 ;
V_76 -> V_84 = V_11 -> V_36 ;
if ( ! V_93 )
V_76 -> V_77 = V_67 ;
F_43 ( V_95 , V_76 ) ;
return 0 ;
}
static T_5
F_48 ( struct V_66 * V_67 , T_4 V_79 , T_4 V_96 )
{
struct V_15 * V_97 = F_1 ( V_67 -> V_81 ) -> V_36 ;
int V_20 ;
V_20 = F_49 ( V_97 , V_79 , V_96 , V_12 , 0 ) ;
if ( V_20 < 0 ) {
F_8 ( L_21 , V_20 ) ;
return V_98 ;
}
return 0 ;
}
static T_5
F_50 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_99 * V_100 ;
struct V_76 * V_76 ;
struct V_88 V_89 ;
T_4 V_101 = V_67 -> V_102 ;
T_4 V_103 = F_51 ( V_67 ) ;
if ( V_67 -> V_104 ) {
F_8 ( L_22
L_23 ) ;
return V_98 ;
}
V_100 = & V_67 -> V_105 [ 0 ] ;
if ( V_67 -> V_106 > 1 ||
V_100 -> V_107 != V_67 -> V_81 -> V_37 . V_65 ) {
F_8 ( L_24
L_25 , V_67 -> V_106 , V_100 -> V_107 ,
V_67 -> V_81 -> V_37 . V_65 ) ;
return V_108 ;
}
V_69 = F_7 ( sizeof( struct V_68 ) , V_12 ) ;
if ( ! V_69 )
goto V_109;
V_67 -> V_70 = V_69 ;
V_76 = F_38 ( V_67 , V_101 , 1 ) ;
if ( ! V_76 )
goto V_110;
F_52 ( & V_89 ) ;
F_53 ( & V_89 , V_76 ) ;
F_54 ( & V_69 -> V_72 , 1 ) ;
while ( V_103 ) {
while ( F_55 ( V_76 , F_56 ( V_100 ) , V_100 -> V_107 , V_100 -> V_111 )
!= V_100 -> V_107 ) {
V_76 = F_38 ( V_67 , V_101 , 1 ) ;
if ( ! V_76 )
goto V_112;
F_35 ( & V_69 -> V_72 ) ;
F_53 ( & V_89 , V_76 ) ;
}
V_101 += V_100 -> V_107 >> V_113 ;
V_103 -= 1 ;
}
F_40 ( & V_89 , V_114 ) ;
return 0 ;
V_112:
while ( ( V_76 = F_42 ( & V_89 ) ) )
F_37 ( V_76 ) ;
V_110:
F_24 ( V_69 ) ;
V_109:
return V_98 ;
}
static T_6 F_57 ( struct V_2 * V_3 ,
const char * V_115 , T_6 V_116 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_117 , * V_118 , * V_119 , * V_120 ;
T_7 args [ V_121 ] ;
int V_20 = 0 , V_122 ;
unsigned long V_123 ;
V_120 = F_58 ( V_115 , V_12 ) ;
if ( ! V_120 )
return - V_21 ;
V_117 = V_120 ;
while ( ( V_118 = F_59 ( & V_120 , L_26 ) ) != NULL ) {
if ( ! * V_118 )
continue;
V_122 = F_60 ( V_118 , V_124 , args ) ;
switch ( V_122 ) {
case V_125 :
if ( V_11 -> V_36 ) {
F_8 ( L_27
L_28 ) ;
V_20 = - V_126 ;
goto V_27;
}
if ( F_61 ( V_11 -> V_28 , & args [ 0 ] ,
V_127 ) == 0 ) {
V_20 = - V_24 ;
break;
}
F_4 ( L_29 ,
V_11 -> V_28 ) ;
V_11 -> V_22 |= V_23 ;
break;
case V_128 :
V_119 = F_62 ( & args [ 0 ] ) ;
if ( ! V_119 ) {
V_20 = - V_21 ;
break;
}
V_20 = F_63 ( V_119 , 0 , & V_123 ) ;
F_24 ( V_119 ) ;
if ( V_20 < 0 ) {
F_8 ( L_30
L_31 ) ;
goto V_27;
}
V_11 -> V_31 = V_123 ;
F_4 ( L_32 , V_11 -> V_31 ) ;
break;
case V_129 :
break;
default:
break;
}
}
V_27:
F_24 ( V_117 ) ;
return ( ! V_20 ) ? V_116 : V_20 ;
}
static T_6 F_64 ( struct V_2 * V_3 , char * V_130 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
char V_131 [ V_132 ] ;
T_6 V_133 = 0 ;
if ( V_16 )
V_133 += sprintf ( V_130 + V_133 , L_33 ,
F_65 ( V_16 , V_131 ) ) ;
if ( V_11 -> V_22 & V_23 )
V_133 += sprintf ( V_130 + V_133 , L_34 ,
V_11 -> V_28 ) ;
V_133 += sprintf ( V_130 + V_133 , L_35 , V_11 -> V_31 ) ;
V_133 += sprintf ( V_130 + V_133 , L_36 ) ;
if ( V_16 ) {
V_133 += sprintf ( V_130 + V_133 , L_37 ,
F_66 ( V_16 -> V_134 ) , F_67 ( V_16 -> V_134 ) , ( ! V_16 -> V_135 ) ?
L_38 : ( V_16 -> V_136 == V_11 ) ?
L_39 : L_40 ) ;
} else {
V_133 += sprintf ( V_130 + V_133 , L_41 ) ;
}
return V_133 ;
}
static int
F_68 ( struct V_66 * V_67 , struct V_76 * V_76 )
{
struct V_2 * V_3 = V_67 -> V_81 ;
struct V_17 * V_18 ;
struct V_137 * V_138 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_99 * V_100 ;
int V_139 , V_140 ;
V_18 = F_19 ( V_11 -> V_36 ) ;
if ( ! V_18 ) {
F_8 ( L_42 ) ;
return - V_141 ;
}
V_138 = F_69 ( V_76 , V_83 , V_67 -> V_142 ) ;
if ( ! V_138 ) {
F_8 ( L_43 ) ;
return - V_21 ;
}
V_138 -> V_143 . V_144 = ( V_67 -> V_145 / V_3 -> V_37 . V_65 ) *
V_3 -> V_146 ;
V_138 -> V_143 . V_87 = V_76 -> V_86 . V_87 ;
F_4 ( L_44 , V_138 -> V_143 . V_144 ,
( unsigned long long ) V_138 -> V_143 . V_87 ) ;
F_70 (cmd->t_prot_sg, sg, cmd->t_prot_nents, i) {
V_140 = F_71 ( V_76 , F_56 ( V_100 ) , V_100 -> V_107 ,
V_100 -> V_111 ) ;
if ( V_140 != V_100 -> V_107 ) {
F_8 ( L_45 , V_140 ) ;
return - V_21 ;
}
F_4 ( L_46 ,
F_56 ( V_100 ) , V_100 -> V_107 , V_100 -> V_111 ) ;
}
return 0 ;
}
static T_5
F_72 ( struct V_66 * V_67 , struct V_99 * V_147 , T_1 V_148 ,
enum V_149 V_150 )
{
struct V_2 * V_3 = V_67 -> V_81 ;
struct V_68 * V_69 ;
struct V_76 * V_76 , * V_151 ;
struct V_88 V_89 ;
struct V_99 * V_100 ;
T_1 V_80 = V_148 ;
T_4 V_101 ;
unsigned V_152 ;
int V_90 = 0 ;
int V_139 ;
if ( V_150 == V_153 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_36 ) ;
if ( V_14 -> V_154 & V_155 ) {
if ( V_67 -> V_156 & V_157 )
V_90 = V_158 ;
else if ( ! ( V_14 -> V_154 & V_159 ) )
V_90 = V_158 ;
else
V_90 = V_114 ;
} else {
V_90 = V_114 ;
}
} else {
V_90 = V_160 ;
}
if ( V_3 -> V_37 . V_65 == 4096 )
V_101 = ( V_67 -> V_102 << 3 ) ;
else if ( V_3 -> V_37 . V_65 == 2048 )
V_101 = ( V_67 -> V_102 << 2 ) ;
else if ( V_3 -> V_37 . V_65 == 1024 )
V_101 = ( V_67 -> V_102 << 1 ) ;
else if ( V_3 -> V_37 . V_65 == 512 )
V_101 = V_67 -> V_102 ;
else {
F_8 ( L_47
L_48 , V_3 -> V_37 . V_65 ) ;
return V_98 ;
}
V_69 = F_7 ( sizeof( struct V_68 ) , V_12 ) ;
if ( ! V_69 )
goto V_109;
V_67 -> V_70 = V_69 ;
if ( ! V_148 ) {
F_54 ( & V_69 -> V_72 , 1 ) ;
F_30 ( V_67 ) ;
return 0 ;
}
V_76 = F_38 ( V_67 , V_101 , V_148 ) ;
if ( ! V_76 )
goto V_110;
V_151 = V_76 ;
F_52 ( & V_89 ) ;
F_53 ( & V_89 , V_76 ) ;
F_54 ( & V_69 -> V_72 , 2 ) ;
V_152 = 1 ;
F_70 (sgl, sg, sgl_nents, i) {
while ( F_55 ( V_76 , F_56 ( V_100 ) , V_100 -> V_107 , V_100 -> V_111 )
!= V_100 -> V_107 ) {
if ( V_152 >= V_161 ) {
F_40 ( & V_89 , V_90 ) ;
V_152 = 0 ;
}
V_76 = F_38 ( V_67 , V_101 , V_80 ) ;
if ( ! V_76 )
goto V_112;
F_35 ( & V_69 -> V_72 ) ;
F_53 ( & V_89 , V_76 ) ;
V_152 ++ ;
}
V_101 += V_100 -> V_107 >> V_113 ;
V_80 -- ;
}
if ( V_67 -> V_162 && V_3 -> V_37 . V_56 ) {
int V_140 = F_68 ( V_67 , V_151 ) ;
if ( V_140 )
goto V_112;
}
F_40 ( & V_89 , V_90 ) ;
F_30 ( V_67 ) ;
return 0 ;
V_112:
while ( ( V_76 = F_42 ( & V_89 ) ) )
F_37 ( V_76 ) ;
V_110:
F_24 ( V_69 ) ;
V_109:
return V_98 ;
}
static T_4 F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_27 ( V_3 , V_16 , V_14 ) ;
}
static T_4 F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
int V_20 ;
V_20 = F_75 ( V_16 ) ;
if ( V_20 == - 1 )
return 0 ;
return V_20 / F_15 ( V_16 ) ;
}
static unsigned int F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
int V_163 = F_77 ( V_16 ) / F_15 ( V_16 ) ;
return F_78 ( V_163 ) ;
}
static unsigned int F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
return F_80 ( V_16 ) ;
}
static unsigned int F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
return F_82 ( V_16 ) ;
}
static T_5
F_83 ( struct V_66 * V_67 )
{
return F_84 ( V_67 , & V_164 ) ;
}
static bool F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return V_14 -> V_154 & V_159 ;
}
static int T_8 F_86 ( void )
{
return F_87 ( & V_165 ) ;
}
static void T_9 F_88 ( void )
{
F_89 ( & V_165 ) ;
}
