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
unsigned int V_20 ;
int V_21 = - V_22 ;
if ( ! ( V_11 -> V_23 & V_24 ) ) {
F_8 ( L_5 ) ;
return - V_25 ;
}
V_11 -> V_26 = F_10 ( V_27 , 0 , V_28 ) ;
if ( ! V_11 -> V_26 ) {
F_8 ( L_6 ) ;
goto V_29;
}
F_4 ( L_7 ,
V_11 -> V_30 ) ;
V_19 = V_31 | V_32 ;
if ( ! V_11 -> V_33 )
V_19 |= V_34 ;
else
V_3 -> V_35 |= V_36 ;
V_16 = F_11 ( V_11 -> V_30 , V_19 , V_11 ) ;
if ( F_12 ( V_16 ) ) {
V_21 = F_13 ( V_16 ) ;
goto V_37;
}
V_11 -> V_38 = V_16 ;
V_14 = F_14 ( V_16 ) ;
V_3 -> V_39 . V_40 = F_15 ( V_16 ) ;
V_3 -> V_39 . V_41 = F_16 ( V_14 ) ;
V_3 -> V_39 . V_42 = V_14 -> V_43 ;
if ( F_17 ( & V_3 -> V_39 , V_14 ) )
F_4 ( L_8
L_9 ) ;
V_20 = F_18 ( V_16 ) ;
if ( V_20 )
V_3 -> V_39 . V_44 = V_20 ;
else
V_3 -> V_39 . V_44 = 0xFFFF ;
if ( F_19 ( V_14 ) )
V_3 -> V_39 . V_45 = 1 ;
V_18 = F_20 ( V_16 ) ;
if ( V_18 ) {
struct V_46 * V_47 = V_11 -> V_26 ;
if ( ! strcmp ( V_18 -> V_48 -> V_10 , L_10 ) ||
! strcmp ( V_18 -> V_48 -> V_10 , L_11 ) ) {
F_8 ( L_12
L_13 , V_18 -> V_48 -> V_10 ) ;
V_21 = - V_49 ;
goto V_50;
}
if ( ! strcmp ( V_18 -> V_48 -> V_10 , L_14 ) ) {
V_3 -> V_39 . V_51 = V_52 ;
} else if ( ! strcmp ( V_18 -> V_48 -> V_10 , L_15 ) ) {
V_3 -> V_39 . V_51 = V_53 ;
}
if ( V_3 -> V_39 . V_51 ) {
if ( F_21 ( V_47 , V_27 ) < 0 ) {
F_8 ( L_16 ) ;
V_21 = - V_22 ;
goto V_50;
}
F_4 ( L_17 ,
V_47 -> V_54 ) ;
}
V_3 -> V_39 . V_55 = V_3 -> V_39 . V_51 ;
}
return 0 ;
V_50:
F_22 ( V_11 -> V_38 , V_34 | V_31 | V_32 ) ;
V_37:
F_23 ( V_11 -> V_26 ) ;
V_11 -> V_26 = NULL ;
V_29:
return V_21 ;
}
static void F_24 ( struct V_56 * V_57 )
{
struct V_2 * V_3 = F_2 ( V_57 , struct V_2 , V_56 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
F_25 ( V_11 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
F_27 ( & V_3 -> V_56 , F_24 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 -> V_38 != NULL )
F_22 ( V_11 -> V_38 , V_34 | V_31 | V_32 ) ;
if ( V_11 -> V_26 != NULL )
F_23 ( V_11 -> V_26 ) ;
}
static unsigned long long F_29 (
struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_13 * V_14 )
{
unsigned long long V_58 = ( F_30 ( F_31 ( V_16 -> V_59 ) ,
F_15 ( V_16 ) ) - 1 ) ;
T_1 V_60 = F_15 ( V_16 ) ;
if ( V_60 == V_3 -> V_39 . V_60 )
return V_58 ;
switch ( V_60 ) {
case 4096 :
switch ( V_3 -> V_39 . V_60 ) {
case 2048 :
V_58 <<= 1 ;
break;
case 1024 :
V_58 <<= 2 ;
break;
case 512 :
V_58 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_3 -> V_39 . V_60 ) {
case 4096 :
V_58 >>= 1 ;
break;
case 1024 :
V_58 <<= 1 ;
break;
case 512 :
V_58 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_3 -> V_39 . V_60 ) {
case 4096 :
V_58 >>= 2 ;
break;
case 2048 :
V_58 >>= 1 ;
break;
case 512 :
V_58 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_3 -> V_39 . V_60 ) {
case 4096 :
V_58 >>= 3 ;
break;
case 2048 :
V_58 >>= 2 ;
break;
case 1024 :
V_58 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_58 ;
}
static void F_32 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_65 ;
T_3 V_66 ;
if ( ! F_33 ( & V_64 -> V_67 ) )
return;
if ( F_34 ( & V_64 -> V_68 ) )
V_66 = V_69 ;
else
V_66 = V_70 ;
F_35 ( V_62 , V_66 ) ;
F_25 ( V_64 ) ;
}
static void F_36 ( struct V_71 * V_71 )
{
struct V_61 * V_62 = V_71 -> V_72 ;
struct V_63 * V_64 = V_62 -> V_65 ;
if ( V_71 -> V_73 ) {
F_8 ( L_18 , V_71 , V_71 -> V_73 ) ;
F_37 ( & V_64 -> V_68 ) ;
F_38 () ;
}
F_39 ( V_71 ) ;
F_32 ( V_62 ) ;
}
static struct V_71 *
F_40 ( struct V_61 * V_62 , T_4 V_74 , T_1 V_75 , int V_76 ,
int V_77 )
{
struct V_1 * V_11 = F_1 ( V_62 -> V_78 ) ;
struct V_71 * V_71 ;
if ( V_75 > V_79 )
V_75 = V_79 ;
V_71 = F_41 ( V_80 , V_75 , V_11 -> V_26 ) ;
if ( ! V_71 ) {
F_8 ( L_19 ) ;
return NULL ;
}
V_71 -> V_81 = V_11 -> V_38 ;
V_71 -> V_72 = V_62 ;
V_71 -> V_82 = & F_36 ;
V_71 -> V_83 . V_84 = V_74 ;
F_42 ( V_71 , V_76 , V_77 ) ;
return V_71 ;
}
static void F_43 ( struct V_85 * V_86 )
{
struct V_87 V_88 ;
struct V_71 * V_71 ;
F_44 ( & V_88 ) ;
while ( ( V_71 = F_45 ( V_86 ) ) )
F_46 ( V_71 ) ;
F_47 ( & V_88 ) ;
}
static void F_48 ( struct V_71 * V_71 )
{
struct V_61 * V_62 = V_71 -> V_72 ;
if ( V_71 -> V_73 )
F_8 ( L_20 , V_71 -> V_73 ) ;
if ( V_62 ) {
if ( V_71 -> V_73 )
F_35 ( V_62 , V_69 ) ;
else
F_35 ( V_62 , V_70 ) ;
}
F_39 ( V_71 ) ;
}
static T_5
F_49 ( struct V_61 * V_62 )
{
struct V_1 * V_11 = F_1 ( V_62 -> V_78 ) ;
int V_89 = ( V_62 -> V_90 [ 1 ] & 0x2 ) ;
struct V_71 * V_71 ;
if ( V_89 )
F_35 ( V_62 , V_70 ) ;
V_71 = F_50 ( V_12 , 0 ) ;
V_71 -> V_82 = F_48 ;
V_71 -> V_81 = V_11 -> V_38 ;
V_71 -> V_91 = V_92 | V_93 ;
if ( ! V_89 )
V_71 -> V_72 = V_62 ;
F_46 ( V_71 ) ;
return 0 ;
}
static T_5
F_51 ( struct V_61 * V_62 , T_4 V_74 , T_4 V_94 )
{
struct V_15 * V_95 = F_1 ( V_62 -> V_78 ) -> V_38 ;
struct V_2 * V_3 = V_62 -> V_78 ;
int V_21 ;
V_21 = F_52 ( V_95 ,
F_53 ( V_3 , V_74 ) ,
F_53 ( V_3 , V_94 ) ,
V_12 , 0 ) ;
if ( V_21 < 0 ) {
F_8 ( L_21 , V_21 ) ;
return V_96 ;
}
return 0 ;
}
static T_5
F_54 ( struct V_15 * V_95 , struct V_61 * V_62 )
{
struct V_2 * V_3 = V_62 -> V_78 ;
struct V_97 * V_98 = & V_62 -> V_99 [ 0 ] ;
unsigned char * V_100 , V_101 = 0x00 , * V_57 = & V_101 ;
int V_102 , V_21 ;
V_100 = F_55 ( F_56 ( V_98 ) ) + V_98 -> V_103 ;
if ( ! V_100 )
return V_96 ;
V_102 = memcmp ( V_100 , V_57 , V_62 -> V_104 ) ;
F_57 ( F_56 ( V_98 ) ) ;
if ( V_102 )
return V_96 ;
V_21 = F_58 ( V_95 ,
F_53 ( V_3 , V_62 -> V_105 ) ,
F_53 ( V_3 ,
F_59 ( V_62 ) ) ,
V_12 , false ) ;
if ( V_21 )
return V_96 ;
F_35 ( V_62 , V_106 ) ;
return 0 ;
}
static T_5
F_60 ( struct V_61 * V_62 )
{
struct V_15 * V_95 = F_1 ( V_62 -> V_78 ) -> V_38 ;
struct V_63 * V_64 ;
struct V_97 * V_98 ;
struct V_71 * V_71 ;
struct V_85 V_86 ;
struct V_2 * V_3 = V_62 -> V_78 ;
T_4 V_107 = F_53 ( V_3 , V_62 -> V_105 ) ;
T_4 V_108 = F_53 ( V_3 ,
F_59 ( V_62 ) ) ;
if ( V_62 -> V_109 ) {
F_8 ( L_22
L_23 ) ;
return V_96 ;
}
V_98 = & V_62 -> V_99 [ 0 ] ;
if ( V_62 -> V_110 > 1 ||
V_98 -> V_111 != V_62 -> V_78 -> V_39 . V_60 ) {
F_8 ( L_24
L_25 , V_62 -> V_110 , V_98 -> V_111 ,
V_62 -> V_78 -> V_39 . V_60 ) ;
return V_112 ;
}
if ( F_18 ( V_95 ) ) {
if ( ! F_54 ( V_95 , V_62 ) )
return 0 ;
}
V_64 = F_7 ( sizeof( struct V_63 ) , V_12 ) ;
if ( ! V_64 )
goto V_113;
V_62 -> V_65 = V_64 ;
V_71 = F_40 ( V_62 , V_107 , 1 , V_92 , 0 ) ;
if ( ! V_71 )
goto V_114;
F_61 ( & V_86 ) ;
F_62 ( & V_86 , V_71 ) ;
F_63 ( & V_64 -> V_67 , 1 ) ;
while ( V_108 ) {
while ( F_64 ( V_71 , F_56 ( V_98 ) , V_98 -> V_111 , V_98 -> V_103 )
!= V_98 -> V_111 ) {
V_71 = F_40 ( V_62 , V_107 , 1 , V_92 ,
0 ) ;
if ( ! V_71 )
goto V_115;
F_65 ( & V_64 -> V_67 ) ;
F_62 ( & V_86 , V_71 ) ;
}
V_107 += V_98 -> V_111 >> V_116 ;
V_108 -= 1 ;
}
F_43 ( & V_86 ) ;
return 0 ;
V_115:
while ( ( V_71 = F_45 ( & V_86 ) ) )
F_39 ( V_71 ) ;
V_114:
F_25 ( V_64 ) ;
V_113:
return V_96 ;
}
static T_6 F_66 ( struct V_2 * V_3 ,
const char * V_117 , T_6 V_118 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_119 , * V_120 , * V_121 , * V_122 ;
T_7 args [ V_123 ] ;
int V_21 = 0 , V_124 ;
unsigned long V_125 ;
V_122 = F_67 ( V_117 , V_12 ) ;
if ( ! V_122 )
return - V_22 ;
V_119 = V_122 ;
while ( ( V_120 = F_68 ( & V_122 , L_26 ) ) != NULL ) {
if ( ! * V_120 )
continue;
V_124 = F_69 ( V_120 , V_126 , args ) ;
switch ( V_124 ) {
case V_127 :
if ( V_11 -> V_38 ) {
F_8 ( L_27
L_28 ) ;
V_21 = - V_128 ;
goto V_29;
}
if ( F_70 ( V_11 -> V_30 , & args [ 0 ] ,
V_129 ) == 0 ) {
V_21 = - V_25 ;
break;
}
F_4 ( L_29 ,
V_11 -> V_30 ) ;
V_11 -> V_23 |= V_24 ;
break;
case V_130 :
V_121 = F_71 ( & args [ 0 ] ) ;
if ( ! V_121 ) {
V_21 = - V_22 ;
break;
}
V_21 = F_72 ( V_121 , 0 , & V_125 ) ;
F_25 ( V_121 ) ;
if ( V_21 < 0 ) {
F_8 ( L_30
L_31 ) ;
goto V_29;
}
V_11 -> V_33 = V_125 ;
F_4 ( L_32 , V_11 -> V_33 ) ;
break;
case V_131 :
break;
default:
break;
}
}
V_29:
F_25 ( V_119 ) ;
return ( ! V_21 ) ? V_118 : V_21 ;
}
static T_6 F_73 ( struct V_2 * V_3 , char * V_132 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
char V_100 [ V_133 ] ;
T_6 V_134 = 0 ;
if ( V_16 )
V_134 += sprintf ( V_132 + V_134 , L_33 ,
F_74 ( V_16 , V_100 ) ) ;
if ( V_11 -> V_23 & V_24 )
V_134 += sprintf ( V_132 + V_134 , L_34 ,
V_11 -> V_30 ) ;
V_134 += sprintf ( V_132 + V_134 , L_35 , V_11 -> V_33 ) ;
V_134 += sprintf ( V_132 + V_134 , L_36 ) ;
if ( V_16 ) {
V_134 += sprintf ( V_132 + V_134 , L_37 ,
F_75 ( V_16 -> V_135 ) , F_76 ( V_16 -> V_135 ) , ( ! V_16 -> V_136 ) ?
L_38 : ( V_16 -> V_137 == V_11 ) ?
L_39 : L_40 ) ;
} else {
V_134 += sprintf ( V_132 + V_134 , L_41 ) ;
}
return V_134 ;
}
static int
F_77 ( struct V_61 * V_62 , struct V_71 * V_71 )
{
struct V_2 * V_3 = V_62 -> V_78 ;
struct V_17 * V_18 ;
struct V_138 * V_139 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_97 * V_98 ;
int V_140 , V_102 ;
V_18 = F_20 ( V_11 -> V_38 ) ;
if ( ! V_18 ) {
F_8 ( L_42 ) ;
return - V_141 ;
}
V_139 = F_78 ( V_71 , V_80 , V_62 -> V_142 ) ;
if ( F_12 ( V_139 ) ) {
F_8 ( L_43 ) ;
return F_13 ( V_139 ) ;
}
V_139 -> V_143 . V_144 = ( V_62 -> V_104 / V_3 -> V_39 . V_60 ) *
V_3 -> V_145 ;
V_139 -> V_143 . V_84 = V_71 -> V_83 . V_84 ;
F_4 ( L_44 , V_139 -> V_143 . V_144 ,
( unsigned long long ) V_139 -> V_143 . V_84 ) ;
F_79 (cmd->t_prot_sg, sg, cmd->t_prot_nents, i) {
V_102 = F_80 ( V_71 , F_56 ( V_98 ) , V_98 -> V_111 ,
V_98 -> V_103 ) ;
if ( V_102 != V_98 -> V_111 ) {
F_8 ( L_45 , V_102 ) ;
return - V_22 ;
}
F_4 ( L_46 ,
F_56 ( V_98 ) , V_98 -> V_111 , V_98 -> V_103 ) ;
}
return 0 ;
}
static T_5
F_81 ( struct V_61 * V_62 , struct V_97 * V_146 , T_1 V_147 ,
enum V_148 V_149 )
{
struct V_2 * V_3 = V_62 -> V_78 ;
T_4 V_107 = F_53 ( V_3 , V_62 -> V_105 ) ;
struct V_63 * V_64 ;
struct V_71 * V_71 , * V_150 ;
struct V_85 V_86 ;
struct V_97 * V_98 ;
T_1 V_75 = V_147 ;
unsigned V_151 ;
int V_140 , V_76 , V_77 = 0 ;
if ( V_149 == V_152 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_38 ) ;
V_76 = V_92 ;
if ( F_82 ( V_153 , & V_14 -> V_154 ) ) {
if ( V_62 -> V_155 & V_156 )
V_77 = V_157 ;
else if ( ! F_82 ( V_158 , & V_14 -> V_154 ) )
V_77 = V_157 ;
}
} else {
V_76 = V_159 ;
}
V_64 = F_7 ( sizeof( struct V_63 ) , V_12 ) ;
if ( ! V_64 )
goto V_113;
V_62 -> V_65 = V_64 ;
if ( ! V_147 ) {
F_63 ( & V_64 -> V_67 , 1 ) ;
F_32 ( V_62 ) ;
return 0 ;
}
V_71 = F_40 ( V_62 , V_107 , V_147 , V_76 , V_77 ) ;
if ( ! V_71 )
goto V_114;
V_150 = V_71 ;
F_61 ( & V_86 ) ;
F_62 ( & V_86 , V_71 ) ;
F_63 ( & V_64 -> V_67 , 2 ) ;
V_151 = 1 ;
F_79 (sgl, sg, sgl_nents, i) {
while ( F_64 ( V_71 , F_56 ( V_98 ) , V_98 -> V_111 , V_98 -> V_103 )
!= V_98 -> V_111 ) {
if ( V_151 >= V_160 ) {
F_43 ( & V_86 ) ;
V_151 = 0 ;
}
V_71 = F_40 ( V_62 , V_107 , V_75 , V_76 ,
V_77 ) ;
if ( ! V_71 )
goto V_115;
F_65 ( & V_64 -> V_67 ) ;
F_62 ( & V_86 , V_71 ) ;
V_151 ++ ;
}
V_107 += V_98 -> V_111 >> V_116 ;
V_75 -- ;
}
if ( V_62 -> V_161 && V_3 -> V_39 . V_51 ) {
int V_102 = F_77 ( V_62 , V_150 ) ;
if ( V_102 )
goto V_115;
}
F_43 ( & V_86 ) ;
F_32 ( V_62 ) ;
return 0 ;
V_115:
while ( ( V_71 = F_45 ( & V_86 ) ) )
F_39 ( V_71 ) ;
V_114:
F_25 ( V_64 ) ;
V_113:
return V_96 ;
}
static T_4 F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_29 ( V_3 , V_16 , V_14 ) ;
}
static T_4 F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
int V_21 ;
V_21 = F_85 ( V_16 ) ;
if ( V_21 == - 1 )
return 0 ;
return V_21 / F_15 ( V_16 ) ;
}
static unsigned int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
int V_162 = F_87 ( V_16 ) / F_15 ( V_16 ) ;
return F_88 ( V_162 ) ;
}
static unsigned int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
return F_90 ( V_16 ) ;
}
static unsigned int F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
return F_92 ( V_16 ) ;
}
static T_5
F_93 ( struct V_61 * V_62 )
{
return F_94 ( V_62 , & V_163 ) ;
}
static bool F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_82 ( V_158 , & V_14 -> V_154 ) ;
}
static int T_8 F_96 ( void )
{
return F_97 ( & V_164 ) ;
}
static void T_9 F_98 ( void )
{
F_99 ( & V_164 ) ;
}
