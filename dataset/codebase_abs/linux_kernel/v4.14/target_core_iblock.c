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
F_42 ( V_71 , V_11 -> V_38 ) ;
V_71 -> V_72 = V_62 ;
V_71 -> V_81 = & F_36 ;
V_71 -> V_82 . V_83 = V_74 ;
F_43 ( V_71 , V_76 , V_77 ) ;
return V_71 ;
}
static void F_44 ( struct V_84 * V_85 )
{
struct V_86 V_87 ;
struct V_71 * V_71 ;
F_45 ( & V_87 ) ;
while ( ( V_71 = F_46 ( V_85 ) ) )
F_47 ( V_71 ) ;
F_48 ( & V_87 ) ;
}
static void F_49 ( struct V_71 * V_71 )
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
F_50 ( struct V_61 * V_62 )
{
struct V_1 * V_11 = F_1 ( V_62 -> V_78 ) ;
int V_88 = ( V_62 -> V_89 [ 1 ] & 0x2 ) ;
struct V_71 * V_71 ;
if ( V_88 )
F_35 ( V_62 , V_70 ) ;
V_71 = F_51 ( V_12 , 0 ) ;
V_71 -> V_81 = F_49 ;
F_42 ( V_71 , V_11 -> V_38 ) ;
V_71 -> V_90 = V_91 | V_92 ;
if ( ! V_88 )
V_71 -> V_72 = V_62 ;
F_47 ( V_71 ) ;
return 0 ;
}
static T_5
F_52 ( struct V_61 * V_62 , T_4 V_74 , T_4 V_93 )
{
struct V_15 * V_94 = F_1 ( V_62 -> V_78 ) -> V_38 ;
struct V_2 * V_3 = V_62 -> V_78 ;
int V_21 ;
V_21 = F_53 ( V_94 ,
F_54 ( V_3 , V_74 ) ,
F_54 ( V_3 , V_93 ) ,
V_12 , 0 ) ;
if ( V_21 < 0 ) {
F_8 ( L_21 , V_21 ) ;
return V_95 ;
}
return 0 ;
}
static T_5
F_55 ( struct V_15 * V_94 , struct V_61 * V_62 )
{
struct V_2 * V_3 = V_62 -> V_78 ;
struct V_96 * V_97 = & V_62 -> V_98 [ 0 ] ;
unsigned char * V_99 , V_100 = 0x00 , * V_57 = & V_100 ;
int V_101 , V_21 ;
V_99 = F_56 ( F_57 ( V_97 ) ) + V_97 -> V_102 ;
if ( ! V_99 )
return V_95 ;
V_101 = memcmp ( V_99 , V_57 , V_62 -> V_103 ) ;
F_58 ( F_57 ( V_97 ) ) ;
if ( V_101 )
return V_95 ;
V_21 = F_59 ( V_94 ,
F_54 ( V_3 , V_62 -> V_104 ) ,
F_54 ( V_3 ,
F_60 ( V_62 ) ) ,
V_12 , false ) ;
if ( V_21 )
return V_95 ;
F_35 ( V_62 , V_105 ) ;
return 0 ;
}
static T_5
F_61 ( struct V_61 * V_62 )
{
struct V_15 * V_94 = F_1 ( V_62 -> V_78 ) -> V_38 ;
struct V_63 * V_64 ;
struct V_96 * V_97 ;
struct V_71 * V_71 ;
struct V_84 V_85 ;
struct V_2 * V_3 = V_62 -> V_78 ;
T_4 V_106 = F_54 ( V_3 , V_62 -> V_104 ) ;
T_4 V_107 = F_54 ( V_3 ,
F_60 ( V_62 ) ) ;
if ( V_62 -> V_108 ) {
F_8 ( L_22
L_23 ) ;
return V_95 ;
}
V_97 = & V_62 -> V_98 [ 0 ] ;
if ( V_62 -> V_109 > 1 ||
V_97 -> V_110 != V_62 -> V_78 -> V_39 . V_60 ) {
F_8 ( L_24
L_25 , V_62 -> V_109 , V_97 -> V_110 ,
V_62 -> V_78 -> V_39 . V_60 ) ;
return V_111 ;
}
if ( F_18 ( V_94 ) ) {
if ( ! F_55 ( V_94 , V_62 ) )
return 0 ;
}
V_64 = F_7 ( sizeof( struct V_63 ) , V_12 ) ;
if ( ! V_64 )
goto V_112;
V_62 -> V_65 = V_64 ;
V_71 = F_40 ( V_62 , V_106 , 1 , V_91 , 0 ) ;
if ( ! V_71 )
goto V_113;
F_62 ( & V_85 ) ;
F_63 ( & V_85 , V_71 ) ;
F_64 ( & V_64 -> V_67 , 1 ) ;
while ( V_107 ) {
while ( F_65 ( V_71 , F_57 ( V_97 ) , V_97 -> V_110 , V_97 -> V_102 )
!= V_97 -> V_110 ) {
V_71 = F_40 ( V_62 , V_106 , 1 , V_91 ,
0 ) ;
if ( ! V_71 )
goto V_114;
F_66 ( & V_64 -> V_67 ) ;
F_63 ( & V_85 , V_71 ) ;
}
V_106 += V_97 -> V_110 >> V_115 ;
V_107 -= 1 ;
}
F_44 ( & V_85 ) ;
return 0 ;
V_114:
while ( ( V_71 = F_46 ( & V_85 ) ) )
F_39 ( V_71 ) ;
V_113:
F_25 ( V_64 ) ;
V_112:
return V_95 ;
}
static T_6 F_67 ( struct V_2 * V_3 ,
const char * V_116 , T_6 V_117 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_118 , * V_119 , * V_120 , * V_121 ;
T_7 args [ V_122 ] ;
int V_21 = 0 , V_123 ;
unsigned long V_124 ;
V_121 = F_68 ( V_116 , V_12 ) ;
if ( ! V_121 )
return - V_22 ;
V_118 = V_121 ;
while ( ( V_119 = F_69 ( & V_121 , L_26 ) ) != NULL ) {
if ( ! * V_119 )
continue;
V_123 = F_70 ( V_119 , V_125 , args ) ;
switch ( V_123 ) {
case V_126 :
if ( V_11 -> V_38 ) {
F_8 ( L_27
L_28 ) ;
V_21 = - V_127 ;
goto V_29;
}
if ( F_71 ( V_11 -> V_30 , & args [ 0 ] ,
V_128 ) == 0 ) {
V_21 = - V_25 ;
break;
}
F_4 ( L_29 ,
V_11 -> V_30 ) ;
V_11 -> V_23 |= V_24 ;
break;
case V_129 :
V_120 = F_72 ( & args [ 0 ] ) ;
if ( ! V_120 ) {
V_21 = - V_22 ;
break;
}
V_21 = F_73 ( V_120 , 0 , & V_124 ) ;
F_25 ( V_120 ) ;
if ( V_21 < 0 ) {
F_8 ( L_30
L_31 ) ;
goto V_29;
}
V_11 -> V_33 = V_124 ;
F_4 ( L_32 , V_11 -> V_33 ) ;
break;
case V_130 :
break;
default:
break;
}
}
V_29:
F_25 ( V_118 ) ;
return ( ! V_21 ) ? V_117 : V_21 ;
}
static T_6 F_74 ( struct V_2 * V_3 , char * V_131 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
char V_99 [ V_132 ] ;
T_6 V_133 = 0 ;
if ( V_16 )
V_133 += sprintf ( V_131 + V_133 , L_33 ,
F_75 ( V_16 , V_99 ) ) ;
if ( V_11 -> V_23 & V_24 )
V_133 += sprintf ( V_131 + V_133 , L_34 ,
V_11 -> V_30 ) ;
V_133 += sprintf ( V_131 + V_133 , L_35 , V_11 -> V_33 ) ;
V_133 += sprintf ( V_131 + V_133 , L_36 ) ;
if ( V_16 ) {
V_133 += sprintf ( V_131 + V_133 , L_37 ,
F_76 ( V_16 -> V_134 ) , F_77 ( V_16 -> V_134 ) , ( ! V_16 -> V_135 ) ?
L_38 : ( V_16 -> V_136 == V_11 ) ?
L_39 : L_40 ) ;
} else {
V_133 += sprintf ( V_131 + V_133 , L_41 ) ;
}
return V_133 ;
}
static int
F_78 ( struct V_61 * V_62 , struct V_71 * V_71 )
{
struct V_2 * V_3 = V_62 -> V_78 ;
struct V_17 * V_18 ;
struct V_137 * V_138 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_96 * V_97 ;
int V_139 , V_101 ;
V_18 = F_20 ( V_11 -> V_38 ) ;
if ( ! V_18 ) {
F_8 ( L_42 ) ;
return - V_140 ;
}
V_138 = F_79 ( V_71 , V_80 , V_62 -> V_141 ) ;
if ( F_12 ( V_138 ) ) {
F_8 ( L_43 ) ;
return F_13 ( V_138 ) ;
}
V_138 -> V_142 . V_143 = ( V_62 -> V_103 / V_3 -> V_39 . V_60 ) *
V_3 -> V_144 ;
V_138 -> V_142 . V_83 = V_71 -> V_82 . V_83 ;
F_4 ( L_44 , V_138 -> V_142 . V_143 ,
( unsigned long long ) V_138 -> V_142 . V_83 ) ;
F_80 (cmd->t_prot_sg, sg, cmd->t_prot_nents, i) {
V_101 = F_81 ( V_71 , F_57 ( V_97 ) , V_97 -> V_110 ,
V_97 -> V_102 ) ;
if ( V_101 != V_97 -> V_110 ) {
F_8 ( L_45 , V_101 ) ;
return - V_22 ;
}
F_4 ( L_46 ,
F_57 ( V_97 ) , V_97 -> V_110 , V_97 -> V_102 ) ;
}
return 0 ;
}
static T_5
F_82 ( struct V_61 * V_62 , struct V_96 * V_145 , T_1 V_146 ,
enum V_147 V_148 )
{
struct V_2 * V_3 = V_62 -> V_78 ;
T_4 V_106 = F_54 ( V_3 , V_62 -> V_104 ) ;
struct V_63 * V_64 ;
struct V_71 * V_71 , * V_149 ;
struct V_84 V_85 ;
struct V_96 * V_97 ;
T_1 V_75 = V_146 ;
unsigned V_150 ;
int V_139 , V_76 , V_77 = 0 ;
if ( V_148 == V_151 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_38 ) ;
V_76 = V_91 ;
if ( F_83 ( V_152 , & V_14 -> V_153 ) ) {
if ( V_62 -> V_154 & V_155 )
V_77 = V_156 ;
else if ( ! F_83 ( V_157 , & V_14 -> V_153 ) )
V_77 = V_156 ;
}
} else {
V_76 = V_158 ;
}
V_64 = F_7 ( sizeof( struct V_63 ) , V_12 ) ;
if ( ! V_64 )
goto V_112;
V_62 -> V_65 = V_64 ;
if ( ! V_146 ) {
F_64 ( & V_64 -> V_67 , 1 ) ;
F_32 ( V_62 ) ;
return 0 ;
}
V_71 = F_40 ( V_62 , V_106 , V_146 , V_76 , V_77 ) ;
if ( ! V_71 )
goto V_113;
V_149 = V_71 ;
F_62 ( & V_85 ) ;
F_63 ( & V_85 , V_71 ) ;
F_64 ( & V_64 -> V_67 , 2 ) ;
V_150 = 1 ;
F_80 (sgl, sg, sgl_nents, i) {
while ( F_65 ( V_71 , F_57 ( V_97 ) , V_97 -> V_110 , V_97 -> V_102 )
!= V_97 -> V_110 ) {
if ( V_150 >= V_159 ) {
F_44 ( & V_85 ) ;
V_150 = 0 ;
}
V_71 = F_40 ( V_62 , V_106 , V_75 , V_76 ,
V_77 ) ;
if ( ! V_71 )
goto V_114;
F_66 ( & V_64 -> V_67 ) ;
F_63 ( & V_85 , V_71 ) ;
V_150 ++ ;
}
V_106 += V_97 -> V_110 >> V_115 ;
V_75 -- ;
}
if ( V_62 -> V_160 && V_3 -> V_39 . V_51 ) {
int V_101 = F_78 ( V_62 , V_149 ) ;
if ( V_101 )
goto V_114;
}
F_44 ( & V_85 ) ;
F_32 ( V_62 ) ;
return 0 ;
V_114:
while ( ( V_71 = F_46 ( & V_85 ) ) )
F_39 ( V_71 ) ;
V_113:
F_25 ( V_64 ) ;
V_112:
return V_95 ;
}
static T_4 F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_29 ( V_3 , V_16 , V_14 ) ;
}
static T_4 F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
int V_21 ;
V_21 = F_86 ( V_16 ) ;
if ( V_21 == - 1 )
return 0 ;
return V_21 / F_15 ( V_16 ) ;
}
static unsigned int F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
int V_161 = F_88 ( V_16 ) / F_15 ( V_16 ) ;
return F_89 ( V_161 ) ;
}
static unsigned int F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
return F_91 ( V_16 ) ;
}
static unsigned int F_92 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
return F_93 ( V_16 ) ;
}
static T_5
F_94 ( struct V_61 * V_62 )
{
return F_95 ( V_62 , & V_162 ) ;
}
static bool F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_38 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_83 ( V_157 , & V_14 -> V_153 ) ;
}
static int T_8 F_97 ( void )
{
return F_98 ( & V_163 ) ;
}
static void T_9 F_99 ( void )
{
F_100 ( & V_163 ) ;
}
