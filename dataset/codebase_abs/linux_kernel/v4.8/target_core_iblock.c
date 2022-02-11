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
if ( F_17 ( & V_3 -> V_37 , V_14 ) )
F_4 ( L_8
L_9 ) ;
V_3 -> V_37 . V_42 = 0xFFFF ;
if ( F_18 ( V_14 ) )
V_3 -> V_37 . V_43 = 1 ;
V_18 = F_19 ( V_16 ) ;
if ( V_18 ) {
struct V_44 * V_45 = V_11 -> V_25 ;
if ( ! strcmp ( V_18 -> V_46 -> V_10 , L_10 ) ||
! strcmp ( V_18 -> V_46 -> V_10 , L_11 ) ) {
F_8 ( L_12
L_13 , V_18 -> V_46 -> V_10 ) ;
V_20 = - V_47 ;
goto V_48;
}
if ( ! strcmp ( V_18 -> V_46 -> V_10 , L_14 ) ) {
V_3 -> V_37 . V_49 = V_50 ;
} else if ( ! strcmp ( V_18 -> V_46 -> V_10 , L_15 ) ) {
V_3 -> V_37 . V_49 = V_51 ;
}
if ( V_3 -> V_37 . V_49 ) {
if ( F_20 ( V_45 , V_26 ) < 0 ) {
F_8 ( L_16 ) ;
V_20 = - V_21 ;
goto V_48;
}
F_4 ( L_17 ,
V_45 -> V_52 ) ;
}
V_3 -> V_37 . V_53 = V_3 -> V_37 . V_49 ;
}
return 0 ;
V_48:
F_21 ( V_11 -> V_36 , V_32 | V_29 | V_30 ) ;
V_35:
F_22 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
V_27:
return V_20 ;
}
static void F_23 ( struct V_54 * V_55 )
{
struct V_2 * V_3 = F_2 ( V_55 , struct V_2 , V_54 ) ;
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
F_26 ( & V_3 -> V_54 , F_23 ) ;
}
static unsigned long long F_27 (
struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_13 * V_14 )
{
unsigned long long V_56 = ( F_28 ( F_29 ( V_16 -> V_57 ) ,
F_15 ( V_16 ) ) - 1 ) ;
T_1 V_58 = F_15 ( V_16 ) ;
if ( V_58 == V_3 -> V_37 . V_58 )
return V_56 ;
switch ( V_58 ) {
case 4096 :
switch ( V_3 -> V_37 . V_58 ) {
case 2048 :
V_56 <<= 1 ;
break;
case 1024 :
V_56 <<= 2 ;
break;
case 512 :
V_56 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_3 -> V_37 . V_58 ) {
case 4096 :
V_56 >>= 1 ;
break;
case 1024 :
V_56 <<= 1 ;
break;
case 512 :
V_56 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_3 -> V_37 . V_58 ) {
case 4096 :
V_56 >>= 2 ;
break;
case 2048 :
V_56 >>= 1 ;
break;
case 512 :
V_56 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_3 -> V_37 . V_58 ) {
case 4096 :
V_56 >>= 3 ;
break;
case 2048 :
V_56 >>= 2 ;
break;
case 1024 :
V_56 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_56 ;
}
static void F_30 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = V_60 -> V_63 ;
T_3 V_64 ;
if ( ! F_31 ( & V_62 -> V_65 ) )
return;
if ( F_32 ( & V_62 -> V_66 ) )
V_64 = V_67 ;
else
V_64 = V_68 ;
F_33 ( V_60 , V_64 ) ;
F_24 ( V_62 ) ;
}
static void F_34 ( struct V_69 * V_69 )
{
struct V_59 * V_60 = V_69 -> V_70 ;
struct V_61 * V_62 = V_60 -> V_63 ;
if ( V_69 -> V_71 ) {
F_8 ( L_18 , V_69 , V_69 -> V_71 ) ;
F_35 ( & V_62 -> V_66 ) ;
F_36 () ;
}
F_37 ( V_69 ) ;
F_30 ( V_60 ) ;
}
static struct V_69 *
F_38 ( struct V_59 * V_60 , T_4 V_72 , T_1 V_73 , int V_74 ,
int V_75 )
{
struct V_1 * V_11 = F_1 ( V_60 -> V_76 ) ;
struct V_69 * V_69 ;
if ( V_73 > V_77 )
V_73 = V_77 ;
V_69 = F_39 ( V_78 , V_73 , V_11 -> V_25 ) ;
if ( ! V_69 ) {
F_8 ( L_19 ) ;
return NULL ;
}
V_69 -> V_79 = V_11 -> V_36 ;
V_69 -> V_70 = V_60 ;
V_69 -> V_80 = & F_34 ;
V_69 -> V_81 . V_82 = V_72 ;
F_40 ( V_69 , V_74 , V_75 ) ;
return V_69 ;
}
static void F_41 ( struct V_83 * V_84 )
{
struct V_85 V_86 ;
struct V_69 * V_69 ;
F_42 ( & V_86 ) ;
while ( ( V_69 = F_43 ( V_84 ) ) )
F_44 ( V_69 ) ;
F_45 ( & V_86 ) ;
}
static void F_46 ( struct V_69 * V_69 )
{
struct V_59 * V_60 = V_69 -> V_70 ;
if ( V_69 -> V_71 )
F_8 ( L_20 , V_69 -> V_71 ) ;
if ( V_60 ) {
if ( V_69 -> V_71 )
F_33 ( V_60 , V_67 ) ;
else
F_33 ( V_60 , V_68 ) ;
}
F_37 ( V_69 ) ;
}
static T_5
F_47 ( struct V_59 * V_60 )
{
struct V_1 * V_11 = F_1 ( V_60 -> V_76 ) ;
int V_87 = ( V_60 -> V_88 [ 1 ] & 0x2 ) ;
struct V_69 * V_69 ;
if ( V_87 )
F_33 ( V_60 , V_68 ) ;
V_69 = F_48 ( V_12 , 0 ) ;
V_69 -> V_80 = F_46 ;
V_69 -> V_79 = V_11 -> V_36 ;
F_40 ( V_69 , V_89 , V_90 ) ;
if ( ! V_87 )
V_69 -> V_70 = V_60 ;
F_44 ( V_69 ) ;
return 0 ;
}
static T_5
F_49 ( struct V_59 * V_60 , T_4 V_72 , T_4 V_91 )
{
struct V_15 * V_92 = F_1 ( V_60 -> V_76 ) -> V_36 ;
struct V_2 * V_3 = V_60 -> V_76 ;
int V_20 ;
V_20 = F_50 ( V_92 ,
F_51 ( V_3 , V_72 ) ,
F_51 ( V_3 , V_91 ) ,
V_12 , 0 ) ;
if ( V_20 < 0 ) {
F_8 ( L_21 , V_20 ) ;
return V_93 ;
}
return 0 ;
}
static T_5
F_52 ( struct V_15 * V_92 , struct V_59 * V_60 )
{
struct V_2 * V_3 = V_60 -> V_76 ;
struct V_94 * V_95 = & V_60 -> V_96 [ 0 ] ;
struct V_97 * V_97 = NULL ;
int V_20 ;
if ( V_95 -> V_98 ) {
V_97 = F_53 ( V_12 ) ;
if ( ! V_97 )
return V_99 ;
F_54 ( V_95 , V_60 -> V_100 , F_55 ( V_97 ) ,
V_3 -> V_37 . V_58 ) ;
}
V_20 = F_56 ( V_92 ,
F_51 ( V_3 , V_60 -> V_101 ) ,
F_51 ( V_3 ,
F_57 ( V_60 ) ) ,
V_12 , V_97 ? V_97 : F_58 ( V_95 ) ) ;
if ( V_97 )
F_59 ( V_97 ) ;
if ( V_20 )
return V_93 ;
F_33 ( V_60 , V_102 ) ;
return 0 ;
}
static T_5
F_60 ( struct V_59 * V_60 )
{
struct V_15 * V_92 = F_1 ( V_60 -> V_76 ) -> V_36 ;
struct V_61 * V_62 ;
struct V_94 * V_95 ;
struct V_69 * V_69 ;
struct V_83 V_84 ;
struct V_2 * V_3 = V_60 -> V_76 ;
T_4 V_103 = F_51 ( V_3 , V_60 -> V_101 ) ;
T_4 V_104 = F_51 ( V_3 ,
F_57 ( V_60 ) ) ;
if ( V_60 -> V_105 ) {
F_8 ( L_22
L_23 ) ;
return V_93 ;
}
V_95 = & V_60 -> V_96 [ 0 ] ;
if ( V_60 -> V_100 > 1 ||
V_95 -> V_106 != V_60 -> V_76 -> V_37 . V_58 ) {
F_8 ( L_24
L_25 , V_60 -> V_100 , V_95 -> V_106 ,
V_60 -> V_76 -> V_37 . V_58 ) ;
return V_107 ;
}
if ( F_61 ( V_92 ) )
return F_52 ( V_92 , V_60 ) ;
V_62 = F_7 ( sizeof( struct V_61 ) , V_12 ) ;
if ( ! V_62 )
goto V_108;
V_60 -> V_63 = V_62 ;
V_69 = F_38 ( V_60 , V_103 , 1 , V_89 , 0 ) ;
if ( ! V_69 )
goto V_109;
F_62 ( & V_84 ) ;
F_63 ( & V_84 , V_69 ) ;
F_64 ( & V_62 -> V_65 , 1 ) ;
while ( V_104 ) {
while ( F_65 ( V_69 , F_58 ( V_95 ) , V_95 -> V_106 , V_95 -> V_98 )
!= V_95 -> V_106 ) {
V_69 = F_38 ( V_60 , V_103 , 1 , V_89 ,
0 ) ;
if ( ! V_69 )
goto V_110;
F_35 ( & V_62 -> V_65 ) ;
F_63 ( & V_84 , V_69 ) ;
}
V_103 += V_95 -> V_106 >> V_111 ;
V_104 -= 1 ;
}
F_41 ( & V_84 ) ;
return 0 ;
V_110:
while ( ( V_69 = F_43 ( & V_84 ) ) )
F_37 ( V_69 ) ;
V_109:
F_24 ( V_62 ) ;
V_108:
return V_93 ;
}
static T_6 F_66 ( struct V_2 * V_3 ,
const char * V_97 , T_6 V_112 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_113 , * V_114 , * V_115 , * V_116 ;
T_7 args [ V_117 ] ;
int V_20 = 0 , V_118 ;
unsigned long V_119 ;
V_116 = F_67 ( V_97 , V_12 ) ;
if ( ! V_116 )
return - V_21 ;
V_113 = V_116 ;
while ( ( V_114 = F_68 ( & V_116 , L_26 ) ) != NULL ) {
if ( ! * V_114 )
continue;
V_118 = F_69 ( V_114 , V_120 , args ) ;
switch ( V_118 ) {
case V_121 :
if ( V_11 -> V_36 ) {
F_8 ( L_27
L_28 ) ;
V_20 = - V_122 ;
goto V_27;
}
if ( F_70 ( V_11 -> V_28 , & args [ 0 ] ,
V_123 ) == 0 ) {
V_20 = - V_24 ;
break;
}
F_4 ( L_29 ,
V_11 -> V_28 ) ;
V_11 -> V_22 |= V_23 ;
break;
case V_124 :
V_115 = F_71 ( & args [ 0 ] ) ;
if ( ! V_115 ) {
V_20 = - V_21 ;
break;
}
V_20 = F_72 ( V_115 , 0 , & V_119 ) ;
F_24 ( V_115 ) ;
if ( V_20 < 0 ) {
F_8 ( L_30
L_31 ) ;
goto V_27;
}
V_11 -> V_31 = V_119 ;
F_4 ( L_32 , V_11 -> V_31 ) ;
break;
case V_125 :
break;
default:
break;
}
}
V_27:
F_24 ( V_113 ) ;
return ( ! V_20 ) ? V_112 : V_20 ;
}
static T_6 F_73 ( struct V_2 * V_3 , char * V_126 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
char V_127 [ V_128 ] ;
T_6 V_129 = 0 ;
if ( V_16 )
V_129 += sprintf ( V_126 + V_129 , L_33 ,
F_74 ( V_16 , V_127 ) ) ;
if ( V_11 -> V_22 & V_23 )
V_129 += sprintf ( V_126 + V_129 , L_34 ,
V_11 -> V_28 ) ;
V_129 += sprintf ( V_126 + V_129 , L_35 , V_11 -> V_31 ) ;
V_129 += sprintf ( V_126 + V_129 , L_36 ) ;
if ( V_16 ) {
V_129 += sprintf ( V_126 + V_129 , L_37 ,
F_75 ( V_16 -> V_130 ) , F_76 ( V_16 -> V_130 ) , ( ! V_16 -> V_131 ) ?
L_38 : ( V_16 -> V_132 == V_11 ) ?
L_39 : L_40 ) ;
} else {
V_129 += sprintf ( V_126 + V_129 , L_41 ) ;
}
return V_129 ;
}
static int
F_77 ( struct V_59 * V_60 , struct V_69 * V_69 )
{
struct V_2 * V_3 = V_60 -> V_76 ;
struct V_17 * V_18 ;
struct V_133 * V_134 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_94 * V_95 ;
int V_135 , V_136 ;
V_18 = F_19 ( V_11 -> V_36 ) ;
if ( ! V_18 ) {
F_8 ( L_42 ) ;
return - V_137 ;
}
V_134 = F_78 ( V_69 , V_78 , V_60 -> V_138 ) ;
if ( F_12 ( V_134 ) ) {
F_8 ( L_43 ) ;
return F_13 ( V_134 ) ;
}
V_134 -> V_139 . V_140 = ( V_60 -> V_141 / V_3 -> V_37 . V_58 ) *
V_3 -> V_142 ;
V_134 -> V_139 . V_82 = V_69 -> V_81 . V_82 ;
F_4 ( L_44 , V_134 -> V_139 . V_140 ,
( unsigned long long ) V_134 -> V_139 . V_82 ) ;
F_79 (cmd->t_prot_sg, sg, cmd->t_prot_nents, i) {
V_136 = F_80 ( V_69 , F_58 ( V_95 ) , V_95 -> V_106 ,
V_95 -> V_98 ) ;
if ( V_136 != V_95 -> V_106 ) {
F_8 ( L_45 , V_136 ) ;
return - V_21 ;
}
F_4 ( L_46 ,
F_58 ( V_95 ) , V_95 -> V_106 , V_95 -> V_98 ) ;
}
return 0 ;
}
static T_5
F_81 ( struct V_59 * V_60 , struct V_94 * V_143 , T_1 V_144 ,
enum V_145 V_146 )
{
struct V_2 * V_3 = V_60 -> V_76 ;
T_4 V_103 = F_51 ( V_3 , V_60 -> V_101 ) ;
struct V_61 * V_62 ;
struct V_69 * V_69 , * V_147 ;
struct V_83 V_84 ;
struct V_94 * V_95 ;
T_1 V_73 = V_144 ;
unsigned V_148 ;
int V_135 , V_74 , V_75 = 0 ;
if ( V_146 == V_149 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_36 ) ;
V_74 = V_89 ;
if ( F_82 ( V_150 , & V_14 -> V_151 ) ) {
if ( V_60 -> V_152 & V_153 )
V_75 = V_154 ;
else if ( ! F_82 ( V_155 , & V_14 -> V_151 ) )
V_75 = V_154 ;
}
} else {
V_74 = V_156 ;
}
V_62 = F_7 ( sizeof( struct V_61 ) , V_12 ) ;
if ( ! V_62 )
goto V_108;
V_60 -> V_63 = V_62 ;
if ( ! V_144 ) {
F_64 ( & V_62 -> V_65 , 1 ) ;
F_30 ( V_60 ) ;
return 0 ;
}
V_69 = F_38 ( V_60 , V_103 , V_144 , V_74 , V_75 ) ;
if ( ! V_69 )
goto V_109;
V_147 = V_69 ;
F_62 ( & V_84 ) ;
F_63 ( & V_84 , V_69 ) ;
F_64 ( & V_62 -> V_65 , 2 ) ;
V_148 = 1 ;
F_79 (sgl, sg, sgl_nents, i) {
while ( F_65 ( V_69 , F_58 ( V_95 ) , V_95 -> V_106 , V_95 -> V_98 )
!= V_95 -> V_106 ) {
if ( V_148 >= V_157 ) {
F_41 ( & V_84 ) ;
V_148 = 0 ;
}
V_69 = F_38 ( V_60 , V_103 , V_73 , V_74 ,
V_75 ) ;
if ( ! V_69 )
goto V_110;
F_35 ( & V_62 -> V_65 ) ;
F_63 ( & V_84 , V_69 ) ;
V_148 ++ ;
}
V_103 += V_95 -> V_106 >> V_111 ;
V_73 -- ;
}
if ( V_60 -> V_158 && V_3 -> V_37 . V_49 ) {
int V_136 = F_77 ( V_60 , V_147 ) ;
if ( V_136 )
goto V_110;
}
F_41 ( & V_84 ) ;
F_30 ( V_60 ) ;
return 0 ;
V_110:
while ( ( V_69 = F_43 ( & V_84 ) ) )
F_37 ( V_69 ) ;
V_109:
F_24 ( V_62 ) ;
V_108:
return V_93 ;
}
static T_4 F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_27 ( V_3 , V_16 , V_14 ) ;
}
static T_4 F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
int V_20 ;
V_20 = F_85 ( V_16 ) ;
if ( V_20 == - 1 )
return 0 ;
return V_20 / F_15 ( V_16 ) ;
}
static unsigned int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
int V_159 = F_87 ( V_16 ) / F_15 ( V_16 ) ;
return F_88 ( V_159 ) ;
}
static unsigned int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
return F_90 ( V_16 ) ;
}
static unsigned int F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
return F_92 ( V_16 ) ;
}
static T_5
F_93 ( struct V_59 * V_60 )
{
return F_94 ( V_60 , & V_160 ) ;
}
static bool F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_82 ( V_155 , & V_14 -> V_151 ) ;
}
static int T_8 F_96 ( void )
{
return F_97 ( & V_161 ) ;
}
static void T_9 F_98 ( void )
{
F_99 ( & V_161 ) ;
}
