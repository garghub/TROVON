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
if ( ! strcmp ( V_18 -> V_54 -> V_10 , L_10 ) ||
! strcmp ( V_18 -> V_54 -> V_10 , L_11 ) ) {
F_8 ( L_12
L_13 , V_18 -> V_54 -> V_10 ) ;
V_20 = - V_55 ;
goto V_56;
}
if ( ! strcmp ( V_18 -> V_54 -> V_10 , L_14 ) ) {
V_3 -> V_37 . V_57 = V_58 ;
} else if ( ! strcmp ( V_18 -> V_54 -> V_10 , L_15 ) ) {
V_3 -> V_37 . V_57 = V_59 ;
}
if ( V_3 -> V_37 . V_57 ) {
if ( F_20 ( V_53 , V_26 ) < 0 ) {
F_8 ( L_16 ) ;
V_20 = - V_21 ;
goto V_56;
}
F_4 ( L_17 ,
V_53 -> V_60 ) ;
}
V_3 -> V_37 . V_61 = V_3 -> V_37 . V_57 ;
}
return 0 ;
V_56:
F_21 ( V_11 -> V_36 , V_32 | V_29 | V_30 ) ;
V_35:
F_22 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
V_27:
return V_20 ;
}
static void F_23 ( struct V_62 * V_63 )
{
struct V_2 * V_3 = F_2 ( V_63 , struct V_2 , V_62 ) ;
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
F_26 ( & V_3 -> V_62 , F_23 ) ;
}
static unsigned long long F_27 (
struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_13 * V_14 )
{
unsigned long long V_64 = ( F_28 ( F_29 ( V_16 -> V_65 ) ,
F_15 ( V_16 ) ) - 1 ) ;
T_1 V_66 = F_15 ( V_16 ) ;
if ( V_66 == V_3 -> V_37 . V_66 )
return V_64 ;
switch ( V_66 ) {
case 4096 :
switch ( V_3 -> V_37 . V_66 ) {
case 2048 :
V_64 <<= 1 ;
break;
case 1024 :
V_64 <<= 2 ;
break;
case 512 :
V_64 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_3 -> V_37 . V_66 ) {
case 4096 :
V_64 >>= 1 ;
break;
case 1024 :
V_64 <<= 1 ;
break;
case 512 :
V_64 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_3 -> V_37 . V_66 ) {
case 4096 :
V_64 >>= 2 ;
break;
case 2048 :
V_64 >>= 1 ;
break;
case 512 :
V_64 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_3 -> V_37 . V_66 ) {
case 4096 :
V_64 >>= 3 ;
break;
case 2048 :
V_64 >>= 2 ;
break;
case 1024 :
V_64 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_64 ;
}
static void F_30 ( struct V_67 * V_68 )
{
struct V_69 * V_70 = V_68 -> V_71 ;
T_3 V_72 ;
if ( ! F_31 ( & V_70 -> V_73 ) )
return;
if ( F_32 ( & V_70 -> V_74 ) )
V_72 = V_75 ;
else
V_72 = V_76 ;
F_33 ( V_68 , V_72 ) ;
F_24 ( V_70 ) ;
}
static void F_34 ( struct V_77 * V_77 )
{
struct V_67 * V_68 = V_77 -> V_78 ;
struct V_69 * V_70 = V_68 -> V_71 ;
if ( V_77 -> V_79 ) {
F_8 ( L_18 , V_77 , V_77 -> V_79 ) ;
F_35 ( & V_70 -> V_74 ) ;
F_36 () ;
}
F_37 ( V_77 ) ;
F_30 ( V_68 ) ;
}
static struct V_77 *
F_38 ( struct V_67 * V_68 , T_4 V_80 , T_1 V_81 )
{
struct V_1 * V_11 = F_1 ( V_68 -> V_82 ) ;
struct V_77 * V_77 ;
if ( V_81 > V_83 )
V_81 = V_83 ;
V_77 = F_39 ( V_84 , V_81 , V_11 -> V_25 ) ;
if ( ! V_77 ) {
F_8 ( L_19 ) ;
return NULL ;
}
V_77 -> V_85 = V_11 -> V_36 ;
V_77 -> V_78 = V_68 ;
V_77 -> V_86 = & F_34 ;
V_77 -> V_87 . V_88 = V_80 ;
return V_77 ;
}
static void F_40 ( struct V_89 * V_90 , int V_91 )
{
struct V_92 V_93 ;
struct V_77 * V_77 ;
F_41 ( & V_93 ) ;
while ( ( V_77 = F_42 ( V_90 ) ) )
F_43 ( V_91 , V_77 ) ;
F_44 ( & V_93 ) ;
}
static void F_45 ( struct V_77 * V_77 )
{
struct V_67 * V_68 = V_77 -> V_78 ;
if ( V_77 -> V_79 )
F_8 ( L_20 , V_77 -> V_79 ) ;
if ( V_68 ) {
if ( V_77 -> V_79 )
F_33 ( V_68 , V_75 ) ;
else
F_33 ( V_68 , V_76 ) ;
}
F_37 ( V_77 ) ;
}
static T_5
F_46 ( struct V_67 * V_68 )
{
struct V_1 * V_11 = F_1 ( V_68 -> V_82 ) ;
int V_94 = ( V_68 -> V_95 [ 1 ] & 0x2 ) ;
struct V_77 * V_77 ;
if ( V_94 )
F_33 ( V_68 , V_76 ) ;
V_77 = F_47 ( V_12 , 0 ) ;
V_77 -> V_86 = F_45 ;
V_77 -> V_85 = V_11 -> V_36 ;
if ( ! V_94 )
V_77 -> V_78 = V_68 ;
F_43 ( V_96 , V_77 ) ;
return 0 ;
}
static T_5
F_48 ( struct V_67 * V_68 , T_4 V_80 , T_4 V_97 )
{
struct V_15 * V_98 = F_1 ( V_68 -> V_82 ) -> V_36 ;
int V_20 ;
V_20 = F_49 ( V_98 , V_80 , V_97 , V_12 , 0 ) ;
if ( V_20 < 0 ) {
F_8 ( L_21 , V_20 ) ;
return V_99 ;
}
return 0 ;
}
static T_5
F_50 ( struct V_67 * V_68 )
{
struct V_69 * V_70 ;
struct V_100 * V_101 ;
struct V_77 * V_77 ;
struct V_89 V_90 ;
T_4 V_102 = V_68 -> V_103 ;
T_4 V_104 = F_51 ( V_68 ) ;
if ( V_68 -> V_105 ) {
F_8 ( L_22
L_23 ) ;
return V_99 ;
}
V_101 = & V_68 -> V_106 [ 0 ] ;
if ( V_68 -> V_107 > 1 ||
V_101 -> V_108 != V_68 -> V_82 -> V_37 . V_66 ) {
F_8 ( L_24
L_25 , V_68 -> V_107 , V_101 -> V_108 ,
V_68 -> V_82 -> V_37 . V_66 ) ;
return V_109 ;
}
V_70 = F_7 ( sizeof( struct V_69 ) , V_12 ) ;
if ( ! V_70 )
goto V_110;
V_68 -> V_71 = V_70 ;
V_77 = F_38 ( V_68 , V_102 , 1 ) ;
if ( ! V_77 )
goto V_111;
F_52 ( & V_90 ) ;
F_53 ( & V_90 , V_77 ) ;
F_54 ( & V_70 -> V_73 , 1 ) ;
while ( V_104 ) {
while ( F_55 ( V_77 , F_56 ( V_101 ) , V_101 -> V_108 , V_101 -> V_112 )
!= V_101 -> V_108 ) {
V_77 = F_38 ( V_68 , V_102 , 1 ) ;
if ( ! V_77 )
goto V_113;
F_35 ( & V_70 -> V_73 ) ;
F_53 ( & V_90 , V_77 ) ;
}
V_102 += V_101 -> V_108 >> V_114 ;
V_104 -= 1 ;
}
F_40 ( & V_90 , V_115 ) ;
return 0 ;
V_113:
while ( ( V_77 = F_42 ( & V_90 ) ) )
F_37 ( V_77 ) ;
V_111:
F_24 ( V_70 ) ;
V_110:
return V_99 ;
}
static T_6 F_57 ( struct V_2 * V_3 ,
const char * V_116 , T_6 V_117 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_118 , * V_119 , * V_120 , * V_121 ;
T_7 args [ V_122 ] ;
int V_20 = 0 , V_123 ;
unsigned long V_124 ;
V_121 = F_58 ( V_116 , V_12 ) ;
if ( ! V_121 )
return - V_21 ;
V_118 = V_121 ;
while ( ( V_119 = F_59 ( & V_121 , L_26 ) ) != NULL ) {
if ( ! * V_119 )
continue;
V_123 = F_60 ( V_119 , V_125 , args ) ;
switch ( V_123 ) {
case V_126 :
if ( V_11 -> V_36 ) {
F_8 ( L_27
L_28 ) ;
V_20 = - V_127 ;
goto V_27;
}
if ( F_61 ( V_11 -> V_28 , & args [ 0 ] ,
V_128 ) == 0 ) {
V_20 = - V_24 ;
break;
}
F_4 ( L_29 ,
V_11 -> V_28 ) ;
V_11 -> V_22 |= V_23 ;
break;
case V_129 :
V_120 = F_62 ( & args [ 0 ] ) ;
if ( ! V_120 ) {
V_20 = - V_21 ;
break;
}
V_20 = F_63 ( V_120 , 0 , & V_124 ) ;
F_24 ( V_120 ) ;
if ( V_20 < 0 ) {
F_8 ( L_30
L_31 ) ;
goto V_27;
}
V_11 -> V_31 = V_124 ;
F_4 ( L_32 , V_11 -> V_31 ) ;
break;
case V_130 :
break;
default:
break;
}
}
V_27:
F_24 ( V_118 ) ;
return ( ! V_20 ) ? V_117 : V_20 ;
}
static T_6 F_64 ( struct V_2 * V_3 , char * V_131 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
char V_132 [ V_133 ] ;
T_6 V_134 = 0 ;
if ( V_16 )
V_134 += sprintf ( V_131 + V_134 , L_33 ,
F_65 ( V_16 , V_132 ) ) ;
if ( V_11 -> V_22 & V_23 )
V_134 += sprintf ( V_131 + V_134 , L_34 ,
V_11 -> V_28 ) ;
V_134 += sprintf ( V_131 + V_134 , L_35 , V_11 -> V_31 ) ;
V_134 += sprintf ( V_131 + V_134 , L_36 ) ;
if ( V_16 ) {
V_134 += sprintf ( V_131 + V_134 , L_37 ,
F_66 ( V_16 -> V_135 ) , F_67 ( V_16 -> V_135 ) , ( ! V_16 -> V_136 ) ?
L_38 : ( V_16 -> V_137 == V_11 ) ?
L_39 : L_40 ) ;
} else {
V_134 += sprintf ( V_131 + V_134 , L_41 ) ;
}
return V_134 ;
}
static int
F_68 ( struct V_67 * V_68 , struct V_77 * V_77 )
{
struct V_2 * V_3 = V_68 -> V_82 ;
struct V_17 * V_18 ;
struct V_138 * V_139 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_100 * V_101 ;
int V_140 , V_141 ;
V_18 = F_19 ( V_11 -> V_36 ) ;
if ( ! V_18 ) {
F_8 ( L_42 ) ;
return - V_142 ;
}
V_139 = F_69 ( V_77 , V_84 , V_68 -> V_143 ) ;
if ( ! V_139 ) {
F_8 ( L_43 ) ;
return - V_21 ;
}
V_139 -> V_144 . V_145 = ( V_68 -> V_146 / V_3 -> V_37 . V_66 ) *
V_3 -> V_147 ;
V_139 -> V_144 . V_88 = V_77 -> V_87 . V_88 ;
F_4 ( L_44 , V_139 -> V_144 . V_145 ,
( unsigned long long ) V_139 -> V_144 . V_88 ) ;
F_70 (cmd->t_prot_sg, sg, cmd->t_prot_nents, i) {
V_141 = F_71 ( V_77 , F_56 ( V_101 ) , V_101 -> V_108 ,
V_101 -> V_112 ) ;
if ( V_141 != V_101 -> V_108 ) {
F_8 ( L_45 , V_141 ) ;
return - V_21 ;
}
F_4 ( L_46 ,
F_56 ( V_101 ) , V_101 -> V_108 , V_101 -> V_112 ) ;
}
return 0 ;
}
static T_5
F_72 ( struct V_67 * V_68 , struct V_100 * V_148 , T_1 V_149 ,
enum V_150 V_151 )
{
struct V_2 * V_3 = V_68 -> V_82 ;
struct V_69 * V_70 ;
struct V_77 * V_77 , * V_152 ;
struct V_89 V_90 ;
struct V_100 * V_101 ;
T_1 V_81 = V_149 ;
T_4 V_102 ;
unsigned V_153 ;
int V_91 = 0 ;
int V_140 ;
if ( V_151 == V_154 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_36 ) ;
if ( V_14 -> V_155 & V_156 ) {
if ( V_68 -> V_157 & V_158 )
V_91 = V_159 ;
else if ( ! ( V_14 -> V_155 & V_160 ) )
V_91 = V_159 ;
else
V_91 = V_115 ;
} else {
V_91 = V_115 ;
}
} else {
V_91 = V_161 ;
}
if ( V_3 -> V_37 . V_66 == 4096 )
V_102 = ( V_68 -> V_103 << 3 ) ;
else if ( V_3 -> V_37 . V_66 == 2048 )
V_102 = ( V_68 -> V_103 << 2 ) ;
else if ( V_3 -> V_37 . V_66 == 1024 )
V_102 = ( V_68 -> V_103 << 1 ) ;
else if ( V_3 -> V_37 . V_66 == 512 )
V_102 = V_68 -> V_103 ;
else {
F_8 ( L_47
L_48 , V_3 -> V_37 . V_66 ) ;
return V_99 ;
}
V_70 = F_7 ( sizeof( struct V_69 ) , V_12 ) ;
if ( ! V_70 )
goto V_110;
V_68 -> V_71 = V_70 ;
if ( ! V_149 ) {
F_54 ( & V_70 -> V_73 , 1 ) ;
F_30 ( V_68 ) ;
return 0 ;
}
V_77 = F_38 ( V_68 , V_102 , V_149 ) ;
if ( ! V_77 )
goto V_111;
V_152 = V_77 ;
F_52 ( & V_90 ) ;
F_53 ( & V_90 , V_77 ) ;
F_54 ( & V_70 -> V_73 , 2 ) ;
V_153 = 1 ;
F_70 (sgl, sg, sgl_nents, i) {
while ( F_55 ( V_77 , F_56 ( V_101 ) , V_101 -> V_108 , V_101 -> V_112 )
!= V_101 -> V_108 ) {
if ( V_153 >= V_162 ) {
F_40 ( & V_90 , V_91 ) ;
V_153 = 0 ;
}
V_77 = F_38 ( V_68 , V_102 , V_81 ) ;
if ( ! V_77 )
goto V_113;
F_35 ( & V_70 -> V_73 ) ;
F_53 ( & V_90 , V_77 ) ;
V_153 ++ ;
}
V_102 += V_101 -> V_108 >> V_114 ;
V_81 -- ;
}
if ( V_68 -> V_163 && V_3 -> V_37 . V_57 ) {
int V_141 = F_68 ( V_68 , V_152 ) ;
if ( V_141 )
goto V_113;
}
F_40 ( & V_90 , V_91 ) ;
F_30 ( V_68 ) ;
return 0 ;
V_113:
while ( ( V_77 = F_42 ( & V_90 ) ) )
F_37 ( V_77 ) ;
V_111:
F_24 ( V_70 ) ;
V_110:
return V_99 ;
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
int V_164 = F_77 ( V_16 ) / F_15 ( V_16 ) ;
return F_78 ( V_164 ) ;
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
F_83 ( struct V_67 * V_68 )
{
return F_84 ( V_68 , & V_165 ) ;
}
static bool F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return V_14 -> V_155 & V_160 ;
}
static int T_8 F_86 ( void )
{
return F_87 ( & V_166 ) ;
}
static void T_9 F_88 ( void )
{
F_89 ( & V_166 ) ;
}
