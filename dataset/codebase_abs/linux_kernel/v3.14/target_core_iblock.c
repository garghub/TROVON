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
V_3 -> V_35 . V_37 = V_38 ;
V_3 -> V_35 . V_39 = V_14 -> V_40 ;
if ( F_16 ( V_14 ) ) {
V_3 -> V_35 . V_41 =
V_14 -> V_42 . V_43 ;
V_3 -> V_35 . V_44 = 1 ;
V_3 -> V_35 . V_45 =
V_14 -> V_42 . V_46 >> 9 ;
V_3 -> V_35 . V_47 =
V_14 -> V_42 . V_48 ;
F_4 ( L_8
L_9 ) ;
}
V_3 -> V_35 . V_49 = 0xFFFF ;
if ( F_17 ( V_14 ) )
V_3 -> V_35 . V_50 = 1 ;
V_18 = F_18 ( V_16 ) ;
if ( V_18 ) {
struct V_51 * V_52 = V_11 -> V_25 ;
if ( ! strcmp ( V_18 -> V_10 , L_10 ) ||
! strcmp ( V_18 -> V_10 , L_11 ) ) {
F_8 ( L_12
L_13 , V_18 -> V_10 ) ;
V_20 = - V_53 ;
goto V_54;
}
if ( ! strcmp ( V_18 -> V_10 , L_14 ) ) {
V_3 -> V_35 . V_55 = V_56 ;
} else if ( ! strcmp ( V_18 -> V_10 , L_15 ) ) {
V_3 -> V_35 . V_55 = V_57 ;
}
if ( V_3 -> V_35 . V_55 ) {
if ( F_19 ( V_52 , V_26 ) < 0 ) {
F_8 ( L_16 ) ;
V_20 = - V_21 ;
goto V_54;
}
F_4 ( L_17 ,
V_52 -> V_58 ) ;
}
V_3 -> V_35 . V_59 = V_3 -> V_35 . V_55 ;
}
return 0 ;
V_54:
F_20 ( V_11 -> V_34 , V_32 | V_29 | V_30 ) ;
V_33:
F_21 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
V_27:
return V_20 ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 -> V_34 != NULL )
F_20 ( V_11 -> V_34 , V_32 | V_29 | V_30 ) ;
if ( V_11 -> V_25 != NULL ) {
F_23 ( V_11 -> V_25 ) ;
F_21 ( V_11 -> V_25 ) ;
}
F_24 ( V_11 ) ;
}
static unsigned long long F_25 (
struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_13 * V_14 )
{
unsigned long long V_60 = ( F_26 ( F_27 ( V_16 -> V_61 ) ,
F_15 ( V_16 ) ) - 1 ) ;
T_1 V_62 = F_15 ( V_16 ) ;
if ( V_62 == V_3 -> V_35 . V_62 )
return V_60 ;
switch ( V_62 ) {
case 4096 :
switch ( V_3 -> V_35 . V_62 ) {
case 2048 :
V_60 <<= 1 ;
break;
case 1024 :
V_60 <<= 2 ;
break;
case 512 :
V_60 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_3 -> V_35 . V_62 ) {
case 4096 :
V_60 >>= 1 ;
break;
case 1024 :
V_60 <<= 1 ;
break;
case 512 :
V_60 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_3 -> V_35 . V_62 ) {
case 4096 :
V_60 >>= 2 ;
break;
case 2048 :
V_60 >>= 1 ;
break;
case 512 :
V_60 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_3 -> V_35 . V_62 ) {
case 4096 :
V_60 >>= 3 ;
break;
case 2048 :
V_60 >>= 2 ;
break;
case 1024 :
V_60 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_60 ;
}
static void F_28 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = V_64 -> V_67 ;
T_3 V_68 ;
if ( ! F_29 ( & V_66 -> V_69 ) )
return;
if ( F_30 ( & V_66 -> V_70 ) )
V_68 = V_71 ;
else
V_68 = V_72 ;
F_31 ( V_64 , V_68 ) ;
F_24 ( V_66 ) ;
}
static void F_32 ( struct V_73 * V_73 , int V_74 )
{
struct V_63 * V_64 = V_73 -> V_75 ;
struct V_65 * V_66 = V_64 -> V_67 ;
if ( ! F_33 ( V_76 , & V_73 -> V_77 ) && ! V_74 )
V_74 = - V_78 ;
if ( V_74 != 0 ) {
F_8 ( L_18
L_19 , V_73 , V_74 ) ;
F_34 ( & V_66 -> V_70 ) ;
F_35 () ;
}
F_36 ( V_73 ) ;
F_28 ( V_64 ) ;
}
static struct V_73 *
F_37 ( struct V_63 * V_64 , T_4 V_79 , T_1 V_80 )
{
struct V_1 * V_11 = F_1 ( V_64 -> V_81 ) ;
struct V_73 * V_73 ;
if ( V_80 > V_82 )
V_80 = V_82 ;
V_73 = F_38 ( V_83 , V_80 , V_11 -> V_25 ) ;
if ( ! V_73 ) {
F_8 ( L_20 ) ;
return NULL ;
}
V_73 -> V_84 = V_11 -> V_34 ;
V_73 -> V_75 = V_64 ;
V_73 -> V_85 = & F_32 ;
V_73 -> V_86 . V_87 = V_79 ;
return V_73 ;
}
static void F_39 ( struct V_88 * V_89 , int V_90 )
{
struct V_91 V_92 ;
struct V_73 * V_73 ;
F_40 ( & V_92 ) ;
while ( ( V_73 = F_41 ( V_89 ) ) )
F_42 ( V_90 , V_73 ) ;
F_43 ( & V_92 ) ;
}
static void F_44 ( struct V_73 * V_73 , int V_74 )
{
struct V_63 * V_64 = V_73 -> V_75 ;
if ( V_74 )
F_8 ( L_21 , V_74 ) ;
if ( V_64 ) {
if ( V_74 )
F_31 ( V_64 , V_71 ) ;
else
F_31 ( V_64 , V_72 ) ;
}
F_36 ( V_73 ) ;
}
static T_5
F_45 ( struct V_63 * V_64 )
{
struct V_1 * V_11 = F_1 ( V_64 -> V_81 ) ;
int V_93 = ( V_64 -> V_94 [ 1 ] & 0x2 ) ;
struct V_73 * V_73 ;
if ( V_93 )
F_31 ( V_64 , V_72 ) ;
V_73 = F_46 ( V_12 , 0 ) ;
V_73 -> V_85 = F_44 ;
V_73 -> V_84 = V_11 -> V_34 ;
if ( ! V_93 )
V_73 -> V_75 = V_64 ;
F_42 ( V_95 , V_73 ) ;
return 0 ;
}
static T_5
F_47 ( struct V_63 * V_64 , void * V_67 ,
T_4 V_79 , T_4 V_96 )
{
struct V_15 * V_97 = V_67 ;
int V_20 ;
V_20 = F_48 ( V_97 , V_79 , V_96 , V_12 , 0 ) ;
if ( V_20 < 0 ) {
F_8 ( L_22 , V_20 ) ;
return V_98 ;
}
return 0 ;
}
static T_5
F_49 ( struct V_63 * V_64 )
{
struct V_15 * V_97 = F_1 ( V_64 -> V_81 ) -> V_34 ;
return F_50 ( V_64 , F_47 , V_97 ) ;
}
static T_5
F_51 ( struct V_63 * V_64 )
{
struct V_15 * V_97 = F_1 ( V_64 -> V_81 ) -> V_34 ;
T_4 V_79 = V_64 -> V_99 ;
T_4 V_96 = F_52 ( V_64 ) ;
int V_20 ;
V_20 = F_47 ( V_64 , V_97 , V_79 , V_96 ) ;
if ( V_20 )
return V_20 ;
F_31 ( V_64 , V_100 ) ;
return 0 ;
}
static T_5
F_53 ( struct V_63 * V_64 )
{
struct V_65 * V_66 ;
struct V_101 * V_102 ;
struct V_73 * V_73 ;
struct V_88 V_89 ;
T_4 V_103 = V_64 -> V_99 ;
T_4 V_104 = F_52 ( V_64 ) ;
V_102 = & V_64 -> V_105 [ 0 ] ;
if ( V_64 -> V_106 > 1 ||
V_102 -> V_107 != V_64 -> V_81 -> V_35 . V_62 ) {
F_8 ( L_23
L_24 , V_64 -> V_106 , V_102 -> V_107 ,
V_64 -> V_81 -> V_35 . V_62 ) ;
return V_108 ;
}
V_66 = F_7 ( sizeof( struct V_65 ) , V_12 ) ;
if ( ! V_66 )
goto V_109;
V_64 -> V_67 = V_66 ;
V_73 = F_37 ( V_64 , V_103 , 1 ) ;
if ( ! V_73 )
goto V_110;
F_54 ( & V_89 ) ;
F_55 ( & V_89 , V_73 ) ;
F_56 ( & V_66 -> V_69 , 1 ) ;
while ( V_104 ) {
while ( F_57 ( V_73 , F_58 ( V_102 ) , V_102 -> V_107 , V_102 -> V_111 )
!= V_102 -> V_107 ) {
V_73 = F_37 ( V_64 , V_103 , 1 ) ;
if ( ! V_73 )
goto V_112;
F_34 ( & V_66 -> V_69 ) ;
F_55 ( & V_89 , V_73 ) ;
}
V_103 += V_102 -> V_107 >> V_113 ;
V_104 -= 1 ;
}
F_39 ( & V_89 , V_114 ) ;
return 0 ;
V_112:
while ( ( V_73 = F_41 ( & V_89 ) ) )
F_36 ( V_73 ) ;
V_110:
F_24 ( V_66 ) ;
V_109:
return V_98 ;
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
while ( ( V_118 = F_61 ( & V_120 , L_25 ) ) != NULL ) {
if ( ! * V_118 )
continue;
V_122 = F_62 ( V_118 , V_124 , args ) ;
switch ( V_122 ) {
case V_125 :
if ( V_11 -> V_34 ) {
F_8 ( L_26
L_27 ) ;
V_20 = - V_126 ;
goto V_27;
}
if ( F_63 ( V_11 -> V_28 , & args [ 0 ] ,
V_127 ) == 0 ) {
V_20 = - V_24 ;
break;
}
F_4 ( L_28 ,
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
F_8 ( L_29
L_30 ) ;
goto V_27;
}
V_11 -> V_31 = V_123 ;
F_4 ( L_31 , V_11 -> V_31 ) ;
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
V_133 += sprintf ( V_130 + V_133 , L_32 ,
F_67 ( V_16 , V_131 ) ) ;
if ( V_11 -> V_22 & V_23 )
V_133 += sprintf ( V_130 + V_133 , L_33 ,
V_11 -> V_28 ) ;
V_133 += sprintf ( V_130 + V_133 , L_34 , V_11 -> V_31 ) ;
V_133 += sprintf ( V_130 + V_133 , L_35 ) ;
if ( V_16 ) {
V_133 += sprintf ( V_130 + V_133 , L_36 ,
F_68 ( V_16 -> V_134 ) , F_69 ( V_16 -> V_134 ) , ( ! V_16 -> V_135 ) ?
L_37 : ( V_16 -> V_136 == V_11 ) ?
L_38 : L_39 ) ;
} else {
V_133 += sprintf ( V_130 + V_133 , L_40 ) ;
}
return V_133 ;
}
static int
F_70 ( struct V_63 * V_64 , struct V_73 * V_73 )
{
struct V_2 * V_3 = V_64 -> V_81 ;
struct V_17 * V_18 ;
struct V_137 * V_138 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_101 * V_102 ;
int V_139 , V_140 ;
V_18 = F_18 ( V_11 -> V_34 ) ;
if ( ! V_18 ) {
F_8 ( L_41 ) ;
return - V_141 ;
}
V_138 = F_71 ( V_73 , V_83 , V_64 -> V_142 ) ;
if ( ! V_138 ) {
F_8 ( L_42 ) ;
return - V_21 ;
}
V_138 -> V_143 . V_144 = ( V_64 -> V_145 / V_3 -> V_35 . V_62 ) *
V_3 -> V_146 ;
V_138 -> V_143 . V_87 = V_73 -> V_86 . V_87 ;
F_4 ( L_43 , V_138 -> V_143 . V_144 ,
( unsigned long long ) V_138 -> V_143 . V_87 ) ;
F_72 (cmd->t_prot_sg, sg, cmd->t_prot_nents, i) {
V_140 = F_73 ( V_73 , F_58 ( V_102 ) , V_102 -> V_107 ,
V_102 -> V_111 ) ;
if ( V_140 != V_102 -> V_107 ) {
F_8 ( L_44 , V_140 ) ;
return - V_21 ;
}
F_4 ( L_45 ,
F_58 ( V_102 ) , V_102 -> V_107 , V_102 -> V_111 ) ;
}
return 0 ;
}
static T_5
F_74 ( struct V_63 * V_64 , struct V_101 * V_147 , T_1 V_148 ,
enum V_149 V_150 )
{
struct V_2 * V_3 = V_64 -> V_81 ;
struct V_65 * V_66 ;
struct V_73 * V_73 , * V_151 ;
struct V_88 V_89 ;
struct V_101 * V_102 ;
T_1 V_80 = V_148 ;
T_4 V_103 ;
unsigned V_152 ;
int V_90 = 0 ;
int V_139 ;
if ( V_150 == V_153 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_34 ) ;
if ( V_14 -> V_154 & V_155 ) {
if ( V_64 -> V_156 & V_157 )
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
if ( V_3 -> V_35 . V_62 == 4096 )
V_103 = ( V_64 -> V_99 << 3 ) ;
else if ( V_3 -> V_35 . V_62 == 2048 )
V_103 = ( V_64 -> V_99 << 2 ) ;
else if ( V_3 -> V_35 . V_62 == 1024 )
V_103 = ( V_64 -> V_99 << 1 ) ;
else if ( V_3 -> V_35 . V_62 == 512 )
V_103 = V_64 -> V_99 ;
else {
F_8 ( L_46
L_47 , V_3 -> V_35 . V_62 ) ;
return V_98 ;
}
V_66 = F_7 ( sizeof( struct V_65 ) , V_12 ) ;
if ( ! V_66 )
goto V_109;
V_64 -> V_67 = V_66 ;
if ( ! V_148 ) {
F_56 ( & V_66 -> V_69 , 1 ) ;
F_28 ( V_64 ) ;
return 0 ;
}
V_73 = F_37 ( V_64 , V_103 , V_148 ) ;
if ( ! V_73 )
goto V_110;
V_151 = V_73 ;
F_54 ( & V_89 ) ;
F_55 ( & V_89 , V_73 ) ;
F_56 ( & V_66 -> V_69 , 2 ) ;
V_152 = 1 ;
F_72 (sgl, sg, sgl_nents, i) {
while ( F_57 ( V_73 , F_58 ( V_102 ) , V_102 -> V_107 , V_102 -> V_111 )
!= V_102 -> V_107 ) {
if ( V_152 >= V_161 ) {
F_39 ( & V_89 , V_90 ) ;
V_152 = 0 ;
}
V_73 = F_37 ( V_64 , V_103 , V_80 ) ;
if ( ! V_73 )
goto V_112;
F_34 ( & V_66 -> V_69 ) ;
F_55 ( & V_89 , V_73 ) ;
V_152 ++ ;
}
V_103 += V_102 -> V_107 >> V_113 ;
V_80 -- ;
}
if ( V_64 -> V_162 ) {
int V_140 = F_70 ( V_64 , V_151 ) ;
if ( V_140 )
goto V_112;
}
F_39 ( & V_89 , V_90 ) ;
F_28 ( V_64 ) ;
return 0 ;
V_112:
while ( ( V_73 = F_41 ( & V_89 ) ) )
F_36 ( V_73 ) ;
V_110:
F_24 ( V_66 ) ;
V_109:
return V_98 ;
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
F_85 ( struct V_63 * V_64 )
{
return F_86 ( V_64 , & V_164 ) ;
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
return F_89 ( & V_165 ) ;
}
static void T_9 F_90 ( void )
{
F_91 ( & V_165 ) ;
}
