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
V_16 = F_11 ( V_11 -> V_28 , V_19 , V_11 ) ;
if ( F_12 ( V_16 ) ) {
V_20 = F_13 ( V_16 ) ;
goto V_33;
}
V_11 -> V_34 = V_16 ;
V_14 = F_14 ( V_16 ) ;
V_3 -> V_35 . V_36 = F_15 ( V_16 ) ;
V_3 -> V_35 . V_37 = F_16 ( V_14 ) ;
V_3 -> V_35 . V_38 = V_14 -> V_39 ;
if ( F_17 ( V_14 ) ) {
V_3 -> V_35 . V_40 =
V_14 -> V_41 . V_42 ;
V_3 -> V_35 . V_43 = 1 ;
V_3 -> V_35 . V_44 =
V_14 -> V_41 . V_45 >> 9 ;
V_3 -> V_35 . V_46 =
V_14 -> V_41 . V_47 ;
F_4 ( L_8
L_9 ) ;
}
V_3 -> V_35 . V_48 = 0xFFFF ;
if ( F_18 ( V_14 ) )
V_3 -> V_35 . V_49 = 1 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 ) {
struct V_50 * V_51 = V_11 -> V_25 ;
if ( ! strcmp ( V_18 -> V_10 , L_10 ) ||
! strcmp ( V_18 -> V_10 , L_11 ) ) {
F_8 ( L_12
L_13 , V_18 -> V_10 ) ;
V_20 = - V_52 ;
goto V_53;
}
if ( ! strcmp ( V_18 -> V_10 , L_14 ) ) {
V_3 -> V_35 . V_54 = V_55 ;
} else if ( ! strcmp ( V_18 -> V_10 , L_15 ) ) {
V_3 -> V_35 . V_54 = V_56 ;
}
if ( V_3 -> V_35 . V_54 ) {
if ( F_20 ( V_51 , V_26 ) < 0 ) {
F_8 ( L_16 ) ;
V_20 = - V_21 ;
goto V_53;
}
F_4 ( L_17 ,
V_51 -> V_57 ) ;
}
V_3 -> V_35 . V_58 = V_3 -> V_35 . V_54 ;
}
return 0 ;
V_53:
F_21 ( V_11 -> V_34 , V_32 | V_29 | V_30 ) ;
V_33:
F_22 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
V_27:
return V_20 ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 -> V_34 != NULL )
F_21 ( V_11 -> V_34 , V_32 | V_29 | V_30 ) ;
if ( V_11 -> V_25 != NULL )
F_22 ( V_11 -> V_25 ) ;
F_24 ( V_11 ) ;
}
static unsigned long long F_25 (
struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_13 * V_14 )
{
unsigned long long V_59 = ( F_26 ( F_27 ( V_16 -> V_60 ) ,
F_15 ( V_16 ) ) - 1 ) ;
T_1 V_61 = F_15 ( V_16 ) ;
if ( V_61 == V_3 -> V_35 . V_61 )
return V_59 ;
switch ( V_61 ) {
case 4096 :
switch ( V_3 -> V_35 . V_61 ) {
case 2048 :
V_59 <<= 1 ;
break;
case 1024 :
V_59 <<= 2 ;
break;
case 512 :
V_59 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_3 -> V_35 . V_61 ) {
case 4096 :
V_59 >>= 1 ;
break;
case 1024 :
V_59 <<= 1 ;
break;
case 512 :
V_59 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_3 -> V_35 . V_61 ) {
case 4096 :
V_59 >>= 2 ;
break;
case 2048 :
V_59 >>= 1 ;
break;
case 512 :
V_59 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_3 -> V_35 . V_61 ) {
case 4096 :
V_59 >>= 3 ;
break;
case 2048 :
V_59 >>= 2 ;
break;
case 1024 :
V_59 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_59 ;
}
static void F_28 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
T_3 V_67 ;
if ( ! F_29 ( & V_65 -> V_68 ) )
return;
if ( F_30 ( & V_65 -> V_69 ) )
V_67 = V_70 ;
else
V_67 = V_71 ;
F_31 ( V_63 , V_67 ) ;
F_24 ( V_65 ) ;
}
static void F_32 ( struct V_72 * V_72 , int V_73 )
{
struct V_62 * V_63 = V_72 -> V_74 ;
struct V_64 * V_65 = V_63 -> V_66 ;
if ( ! F_33 ( V_75 , & V_72 -> V_76 ) && ! V_73 )
V_73 = - V_77 ;
if ( V_73 != 0 ) {
F_8 ( L_18
L_19 , V_72 , V_73 ) ;
F_34 ( & V_65 -> V_69 ) ;
F_35 () ;
}
F_36 ( V_72 ) ;
F_28 ( V_63 ) ;
}
static struct V_72 *
F_37 ( struct V_62 * V_63 , T_4 V_78 , T_1 V_79 )
{
struct V_1 * V_11 = F_1 ( V_63 -> V_80 ) ;
struct V_72 * V_72 ;
if ( V_79 > V_81 )
V_79 = V_81 ;
V_72 = F_38 ( V_82 , V_79 , V_11 -> V_25 ) ;
if ( ! V_72 ) {
F_8 ( L_20 ) ;
return NULL ;
}
V_72 -> V_83 = V_11 -> V_34 ;
V_72 -> V_74 = V_63 ;
V_72 -> V_84 = & F_32 ;
V_72 -> V_85 . V_86 = V_78 ;
return V_72 ;
}
static void F_39 ( struct V_87 * V_88 , int V_89 )
{
struct V_90 V_91 ;
struct V_72 * V_72 ;
F_40 ( & V_91 ) ;
while ( ( V_72 = F_41 ( V_88 ) ) )
F_42 ( V_89 , V_72 ) ;
F_43 ( & V_91 ) ;
}
static void F_44 ( struct V_72 * V_72 , int V_73 )
{
struct V_62 * V_63 = V_72 -> V_74 ;
if ( V_73 )
F_8 ( L_21 , V_73 ) ;
if ( V_63 ) {
if ( V_73 )
F_31 ( V_63 , V_70 ) ;
else
F_31 ( V_63 , V_71 ) ;
}
F_36 ( V_72 ) ;
}
static T_5
F_45 ( struct V_62 * V_63 )
{
struct V_1 * V_11 = F_1 ( V_63 -> V_80 ) ;
int V_92 = ( V_63 -> V_93 [ 1 ] & 0x2 ) ;
struct V_72 * V_72 ;
if ( V_92 )
F_31 ( V_63 , V_71 ) ;
V_72 = F_46 ( V_12 , 0 ) ;
V_72 -> V_84 = F_44 ;
V_72 -> V_83 = V_11 -> V_34 ;
if ( ! V_92 )
V_72 -> V_74 = V_63 ;
F_42 ( V_94 , V_72 ) ;
return 0 ;
}
static T_5
F_47 ( struct V_62 * V_63 , void * V_66 ,
T_4 V_78 , T_4 V_95 )
{
struct V_15 * V_96 = V_66 ;
int V_20 ;
V_20 = F_48 ( V_96 , V_78 , V_95 , V_12 , 0 ) ;
if ( V_20 < 0 ) {
F_8 ( L_22 , V_20 ) ;
return V_97 ;
}
return 0 ;
}
static T_5
F_49 ( struct V_62 * V_63 )
{
struct V_15 * V_96 = F_1 ( V_63 -> V_80 ) -> V_34 ;
return F_50 ( V_63 , F_47 , V_96 ) ;
}
static T_5
F_51 ( struct V_62 * V_63 )
{
struct V_15 * V_96 = F_1 ( V_63 -> V_80 ) -> V_34 ;
T_4 V_78 = V_63 -> V_98 ;
T_4 V_95 = F_52 ( V_63 ) ;
T_5 V_20 ;
V_20 = F_47 ( V_63 , V_96 , V_78 , V_95 ) ;
if ( V_20 )
return V_20 ;
F_31 ( V_63 , V_99 ) ;
return 0 ;
}
static T_5
F_53 ( struct V_62 * V_63 )
{
struct V_64 * V_65 ;
struct V_100 * V_101 ;
struct V_72 * V_72 ;
struct V_87 V_88 ;
T_4 V_102 = V_63 -> V_98 ;
T_4 V_103 = F_52 ( V_63 ) ;
if ( V_63 -> V_104 ) {
F_8 ( L_23
L_24 ) ;
return V_97 ;
}
V_101 = & V_63 -> V_105 [ 0 ] ;
if ( V_63 -> V_106 > 1 ||
V_101 -> V_107 != V_63 -> V_80 -> V_35 . V_61 ) {
F_8 ( L_25
L_26 , V_63 -> V_106 , V_101 -> V_107 ,
V_63 -> V_80 -> V_35 . V_61 ) ;
return V_108 ;
}
V_65 = F_7 ( sizeof( struct V_64 ) , V_12 ) ;
if ( ! V_65 )
goto V_109;
V_63 -> V_66 = V_65 ;
V_72 = F_37 ( V_63 , V_102 , 1 ) ;
if ( ! V_72 )
goto V_110;
F_54 ( & V_88 ) ;
F_55 ( & V_88 , V_72 ) ;
F_56 ( & V_65 -> V_68 , 1 ) ;
while ( V_103 ) {
while ( F_57 ( V_72 , F_58 ( V_101 ) , V_101 -> V_107 , V_101 -> V_111 )
!= V_101 -> V_107 ) {
V_72 = F_37 ( V_63 , V_102 , 1 ) ;
if ( ! V_72 )
goto V_112;
F_34 ( & V_65 -> V_68 ) ;
F_55 ( & V_88 , V_72 ) ;
}
V_102 += V_101 -> V_107 >> V_113 ;
V_103 -= 1 ;
}
F_39 ( & V_88 , V_114 ) ;
return 0 ;
V_112:
while ( ( V_72 = F_41 ( & V_88 ) ) )
F_36 ( V_72 ) ;
V_110:
F_24 ( V_65 ) ;
V_109:
return V_97 ;
}
static T_6 F_59 ( struct V_2 * V_3 ,
const char * V_115 , T_6 V_116 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_117 , * V_118 , * V_119 , * V_120 ;
T_7 args [ V_121 ] ;
int V_20 = 0 , V_122 ;
unsigned long V_123 ;
V_120 = F_60 ( V_115 , V_12 ) ;
if ( ! V_120 )
return - V_21 ;
V_117 = V_120 ;
while ( ( V_118 = F_61 ( & V_120 , L_27 ) ) != NULL ) {
if ( ! * V_118 )
continue;
V_122 = F_62 ( V_118 , V_124 , args ) ;
switch ( V_122 ) {
case V_125 :
if ( V_11 -> V_34 ) {
F_8 ( L_28
L_29 ) ;
V_20 = - V_126 ;
goto V_27;
}
if ( F_63 ( V_11 -> V_28 , & args [ 0 ] ,
V_127 ) == 0 ) {
V_20 = - V_24 ;
break;
}
F_4 ( L_30 ,
V_11 -> V_28 ) ;
V_11 -> V_22 |= V_23 ;
break;
case V_128 :
V_119 = F_64 ( & args [ 0 ] ) ;
if ( ! V_119 ) {
V_20 = - V_21 ;
break;
}
V_20 = F_65 ( V_119 , 0 , & V_123 ) ;
F_24 ( V_119 ) ;
if ( V_20 < 0 ) {
F_8 ( L_31
L_32 ) ;
goto V_27;
}
V_11 -> V_31 = V_123 ;
F_4 ( L_33 , V_11 -> V_31 ) ;
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
static T_6 F_66 ( struct V_2 * V_3 , char * V_130 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_34 ;
char V_131 [ V_132 ] ;
T_6 V_133 = 0 ;
if ( V_16 )
V_133 += sprintf ( V_130 + V_133 , L_34 ,
F_67 ( V_16 , V_131 ) ) ;
if ( V_11 -> V_22 & V_23 )
V_133 += sprintf ( V_130 + V_133 , L_35 ,
V_11 -> V_28 ) ;
V_133 += sprintf ( V_130 + V_133 , L_36 , V_11 -> V_31 ) ;
V_133 += sprintf ( V_130 + V_133 , L_37 ) ;
if ( V_16 ) {
V_133 += sprintf ( V_130 + V_133 , L_38 ,
F_68 ( V_16 -> V_134 ) , F_69 ( V_16 -> V_134 ) , ( ! V_16 -> V_135 ) ?
L_39 : ( V_16 -> V_136 == V_11 ) ?
L_40 : L_41 ) ;
} else {
V_133 += sprintf ( V_130 + V_133 , L_42 ) ;
}
return V_133 ;
}
static int
F_70 ( struct V_62 * V_63 , struct V_72 * V_72 )
{
struct V_2 * V_3 = V_63 -> V_80 ;
struct V_17 * V_18 ;
struct V_137 * V_138 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_100 * V_101 ;
int V_139 , V_140 ;
V_18 = F_19 ( V_11 -> V_34 ) ;
if ( ! V_18 ) {
F_8 ( L_43 ) ;
return - V_141 ;
}
V_138 = F_71 ( V_72 , V_82 , V_63 -> V_142 ) ;
if ( ! V_138 ) {
F_8 ( L_44 ) ;
return - V_21 ;
}
V_138 -> V_143 . V_144 = ( V_63 -> V_145 / V_3 -> V_35 . V_61 ) *
V_3 -> V_146 ;
V_138 -> V_143 . V_86 = V_72 -> V_85 . V_86 ;
F_4 ( L_45 , V_138 -> V_143 . V_144 ,
( unsigned long long ) V_138 -> V_143 . V_86 ) ;
F_72 (cmd->t_prot_sg, sg, cmd->t_prot_nents, i) {
V_140 = F_73 ( V_72 , F_58 ( V_101 ) , V_101 -> V_107 ,
V_101 -> V_111 ) ;
if ( V_140 != V_101 -> V_107 ) {
F_8 ( L_46 , V_140 ) ;
return - V_21 ;
}
F_4 ( L_47 ,
F_58 ( V_101 ) , V_101 -> V_107 , V_101 -> V_111 ) ;
}
return 0 ;
}
static T_5
F_74 ( struct V_62 * V_63 , struct V_100 * V_147 , T_1 V_148 ,
enum V_149 V_150 )
{
struct V_2 * V_3 = V_63 -> V_80 ;
struct V_64 * V_65 ;
struct V_72 * V_72 , * V_151 ;
struct V_87 V_88 ;
struct V_100 * V_101 ;
T_1 V_79 = V_148 ;
T_4 V_102 ;
unsigned V_152 ;
int V_89 = 0 ;
int V_139 ;
if ( V_150 == V_153 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_34 ) ;
if ( V_14 -> V_154 & V_155 ) {
if ( V_63 -> V_156 & V_157 )
V_89 = V_158 ;
else if ( ! ( V_14 -> V_154 & V_159 ) )
V_89 = V_158 ;
else
V_89 = V_114 ;
} else {
V_89 = V_114 ;
}
} else {
V_89 = V_160 ;
}
if ( V_3 -> V_35 . V_61 == 4096 )
V_102 = ( V_63 -> V_98 << 3 ) ;
else if ( V_3 -> V_35 . V_61 == 2048 )
V_102 = ( V_63 -> V_98 << 2 ) ;
else if ( V_3 -> V_35 . V_61 == 1024 )
V_102 = ( V_63 -> V_98 << 1 ) ;
else if ( V_3 -> V_35 . V_61 == 512 )
V_102 = V_63 -> V_98 ;
else {
F_8 ( L_48
L_49 , V_3 -> V_35 . V_61 ) ;
return V_97 ;
}
V_65 = F_7 ( sizeof( struct V_64 ) , V_12 ) ;
if ( ! V_65 )
goto V_109;
V_63 -> V_66 = V_65 ;
if ( ! V_148 ) {
F_56 ( & V_65 -> V_68 , 1 ) ;
F_28 ( V_63 ) ;
return 0 ;
}
V_72 = F_37 ( V_63 , V_102 , V_148 ) ;
if ( ! V_72 )
goto V_110;
V_151 = V_72 ;
F_54 ( & V_88 ) ;
F_55 ( & V_88 , V_72 ) ;
F_56 ( & V_65 -> V_68 , 2 ) ;
V_152 = 1 ;
F_72 (sgl, sg, sgl_nents, i) {
while ( F_57 ( V_72 , F_58 ( V_101 ) , V_101 -> V_107 , V_101 -> V_111 )
!= V_101 -> V_107 ) {
if ( V_152 >= V_161 ) {
F_39 ( & V_88 , V_89 ) ;
V_152 = 0 ;
}
V_72 = F_37 ( V_63 , V_102 , V_79 ) ;
if ( ! V_72 )
goto V_112;
F_34 ( & V_65 -> V_68 ) ;
F_55 ( & V_88 , V_72 ) ;
V_152 ++ ;
}
V_102 += V_101 -> V_107 >> V_113 ;
V_79 -- ;
}
if ( V_63 -> V_162 && V_3 -> V_35 . V_54 ) {
int V_140 = F_70 ( V_63 , V_151 ) ;
if ( V_140 )
goto V_112;
}
F_39 ( & V_88 , V_89 ) ;
F_28 ( V_63 ) ;
return 0 ;
V_112:
while ( ( V_72 = F_41 ( & V_88 ) ) )
F_36 ( V_72 ) ;
V_110:
F_24 ( V_65 ) ;
V_109:
return V_97 ;
}
static T_4 F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_34 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_25 ( V_3 , V_16 , V_14 ) ;
}
static T_4 F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_34 ;
int V_20 ;
V_20 = F_77 ( V_16 ) ;
if ( V_20 == - 1 )
return 0 ;
return V_20 / F_15 ( V_16 ) ;
}
static unsigned int F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_34 ;
int V_163 = F_79 ( V_16 ) / F_15 ( V_16 ) ;
return F_80 ( V_163 ) ;
}
static unsigned int F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_34 ;
return F_82 ( V_16 ) ;
}
static unsigned int F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_34 ;
return F_84 ( V_16 ) ;
}
static T_5
F_85 ( struct V_62 * V_63 )
{
return F_86 ( V_63 , & V_164 ) ;
}
static bool F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_34 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return V_14 -> V_154 & V_159 ;
}
static int T_8 F_88 ( void )
{
struct V_165 * V_166 = & V_167 . V_168 ;
F_89 ( & V_167 ) ;
V_166 -> V_169 . V_170 = V_171 ;
return F_90 ( & V_167 ) ;
}
static void T_9 F_91 ( void )
{
F_92 ( & V_167 ) ;
}
