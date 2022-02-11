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
if ( F_17 ( & V_3 -> V_37 , V_14 ,
V_3 -> V_37 . V_38 ) )
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
F_38 ( struct V_59 * V_60 , T_4 V_72 , T_1 V_73 )
{
struct V_1 * V_11 = F_1 ( V_60 -> V_74 ) ;
struct V_69 * V_69 ;
if ( V_73 > V_75 )
V_73 = V_75 ;
V_69 = F_39 ( V_76 , V_73 , V_11 -> V_25 ) ;
if ( ! V_69 ) {
F_8 ( L_19 ) ;
return NULL ;
}
V_69 -> V_77 = V_11 -> V_36 ;
V_69 -> V_70 = V_60 ;
V_69 -> V_78 = & F_34 ;
V_69 -> V_79 . V_80 = V_72 ;
return V_69 ;
}
static void F_40 ( struct V_81 * V_82 , int V_83 )
{
struct V_84 V_85 ;
struct V_69 * V_69 ;
F_41 ( & V_85 ) ;
while ( ( V_69 = F_42 ( V_82 ) ) )
F_43 ( V_83 , V_69 ) ;
F_44 ( & V_85 ) ;
}
static void F_45 ( struct V_69 * V_69 )
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
F_46 ( struct V_59 * V_60 )
{
struct V_1 * V_11 = F_1 ( V_60 -> V_74 ) ;
int V_86 = ( V_60 -> V_87 [ 1 ] & 0x2 ) ;
struct V_69 * V_69 ;
if ( V_86 )
F_33 ( V_60 , V_68 ) ;
V_69 = F_47 ( V_12 , 0 ) ;
V_69 -> V_78 = F_45 ;
V_69 -> V_77 = V_11 -> V_36 ;
if ( ! V_86 )
V_69 -> V_70 = V_60 ;
F_43 ( V_88 , V_69 ) ;
return 0 ;
}
static T_5
F_48 ( struct V_59 * V_60 , T_4 V_72 , T_4 V_89 )
{
struct V_15 * V_90 = F_1 ( V_60 -> V_74 ) -> V_36 ;
struct V_2 * V_3 = V_60 -> V_74 ;
int V_20 ;
V_20 = F_49 ( V_90 ,
F_50 ( V_3 , V_72 ) ,
F_50 ( V_3 , V_89 ) ,
V_12 , 0 ) ;
if ( V_20 < 0 ) {
F_8 ( L_21 , V_20 ) ;
return V_91 ;
}
return 0 ;
}
static T_5
F_51 ( struct V_15 * V_90 , struct V_59 * V_60 )
{
struct V_2 * V_3 = V_60 -> V_74 ;
struct V_92 * V_93 = & V_60 -> V_94 [ 0 ] ;
struct V_95 * V_95 = NULL ;
int V_20 ;
if ( V_93 -> V_96 ) {
V_95 = F_52 ( V_12 ) ;
if ( ! V_95 )
return V_97 ;
F_53 ( V_93 , V_60 -> V_98 , F_54 ( V_95 ) ,
V_3 -> V_37 . V_58 ) ;
}
V_20 = F_55 ( V_90 ,
F_50 ( V_3 , V_60 -> V_99 ) ,
F_50 ( V_3 ,
F_56 ( V_60 ) ) ,
V_12 , V_95 ? V_95 : F_57 ( V_93 ) ) ;
if ( V_95 )
F_58 ( V_95 ) ;
if ( V_20 )
return V_91 ;
F_33 ( V_60 , V_100 ) ;
return 0 ;
}
static T_5
F_59 ( struct V_59 * V_60 )
{
struct V_15 * V_90 = F_1 ( V_60 -> V_74 ) -> V_36 ;
struct V_61 * V_62 ;
struct V_92 * V_93 ;
struct V_69 * V_69 ;
struct V_81 V_82 ;
struct V_2 * V_3 = V_60 -> V_74 ;
T_4 V_101 = F_50 ( V_3 , V_60 -> V_99 ) ;
T_4 V_102 = F_50 ( V_3 ,
F_56 ( V_60 ) ) ;
if ( V_60 -> V_103 ) {
F_8 ( L_22
L_23 ) ;
return V_91 ;
}
V_93 = & V_60 -> V_94 [ 0 ] ;
if ( V_60 -> V_98 > 1 ||
V_93 -> V_104 != V_60 -> V_74 -> V_37 . V_58 ) {
F_8 ( L_24
L_25 , V_60 -> V_98 , V_93 -> V_104 ,
V_60 -> V_74 -> V_37 . V_58 ) ;
return V_105 ;
}
if ( F_60 ( V_90 ) )
return F_51 ( V_90 , V_60 ) ;
V_62 = F_7 ( sizeof( struct V_61 ) , V_12 ) ;
if ( ! V_62 )
goto V_106;
V_60 -> V_63 = V_62 ;
V_69 = F_38 ( V_60 , V_101 , 1 ) ;
if ( ! V_69 )
goto V_107;
F_61 ( & V_82 ) ;
F_62 ( & V_82 , V_69 ) ;
F_63 ( & V_62 -> V_65 , 1 ) ;
while ( V_102 ) {
while ( F_64 ( V_69 , F_57 ( V_93 ) , V_93 -> V_104 , V_93 -> V_96 )
!= V_93 -> V_104 ) {
V_69 = F_38 ( V_60 , V_101 , 1 ) ;
if ( ! V_69 )
goto V_108;
F_35 ( & V_62 -> V_65 ) ;
F_62 ( & V_82 , V_69 ) ;
}
V_101 += V_93 -> V_104 >> V_109 ;
V_102 -= 1 ;
}
F_40 ( & V_82 , V_110 ) ;
return 0 ;
V_108:
while ( ( V_69 = F_42 ( & V_82 ) ) )
F_37 ( V_69 ) ;
V_107:
F_24 ( V_62 ) ;
V_106:
return V_91 ;
}
static T_6 F_65 ( struct V_2 * V_3 ,
const char * V_95 , T_6 V_111 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_112 , * V_113 , * V_114 , * V_115 ;
T_7 args [ V_116 ] ;
int V_20 = 0 , V_117 ;
unsigned long V_118 ;
V_115 = F_66 ( V_95 , V_12 ) ;
if ( ! V_115 )
return - V_21 ;
V_112 = V_115 ;
while ( ( V_113 = F_67 ( & V_115 , L_26 ) ) != NULL ) {
if ( ! * V_113 )
continue;
V_117 = F_68 ( V_113 , V_119 , args ) ;
switch ( V_117 ) {
case V_120 :
if ( V_11 -> V_36 ) {
F_8 ( L_27
L_28 ) ;
V_20 = - V_121 ;
goto V_27;
}
if ( F_69 ( V_11 -> V_28 , & args [ 0 ] ,
V_122 ) == 0 ) {
V_20 = - V_24 ;
break;
}
F_4 ( L_29 ,
V_11 -> V_28 ) ;
V_11 -> V_22 |= V_23 ;
break;
case V_123 :
V_114 = F_70 ( & args [ 0 ] ) ;
if ( ! V_114 ) {
V_20 = - V_21 ;
break;
}
V_20 = F_71 ( V_114 , 0 , & V_118 ) ;
F_24 ( V_114 ) ;
if ( V_20 < 0 ) {
F_8 ( L_30
L_31 ) ;
goto V_27;
}
V_11 -> V_31 = V_118 ;
F_4 ( L_32 , V_11 -> V_31 ) ;
break;
case V_124 :
break;
default:
break;
}
}
V_27:
F_24 ( V_112 ) ;
return ( ! V_20 ) ? V_111 : V_20 ;
}
static T_6 F_72 ( struct V_2 * V_3 , char * V_125 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
char V_126 [ V_127 ] ;
T_6 V_128 = 0 ;
if ( V_16 )
V_128 += sprintf ( V_125 + V_128 , L_33 ,
F_73 ( V_16 , V_126 ) ) ;
if ( V_11 -> V_22 & V_23 )
V_128 += sprintf ( V_125 + V_128 , L_34 ,
V_11 -> V_28 ) ;
V_128 += sprintf ( V_125 + V_128 , L_35 , V_11 -> V_31 ) ;
V_128 += sprintf ( V_125 + V_128 , L_36 ) ;
if ( V_16 ) {
V_128 += sprintf ( V_125 + V_128 , L_37 ,
F_74 ( V_16 -> V_129 ) , F_75 ( V_16 -> V_129 ) , ( ! V_16 -> V_130 ) ?
L_38 : ( V_16 -> V_131 == V_11 ) ?
L_39 : L_40 ) ;
} else {
V_128 += sprintf ( V_125 + V_128 , L_41 ) ;
}
return V_128 ;
}
static int
F_76 ( struct V_59 * V_60 , struct V_69 * V_69 )
{
struct V_2 * V_3 = V_60 -> V_74 ;
struct V_17 * V_18 ;
struct V_132 * V_133 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_92 * V_93 ;
int V_134 , V_135 ;
V_18 = F_19 ( V_11 -> V_36 ) ;
if ( ! V_18 ) {
F_8 ( L_42 ) ;
return - V_136 ;
}
V_133 = F_77 ( V_69 , V_76 , V_60 -> V_137 ) ;
if ( F_12 ( V_133 ) ) {
F_8 ( L_43 ) ;
return F_13 ( V_133 ) ;
}
V_133 -> V_138 . V_139 = ( V_60 -> V_140 / V_3 -> V_37 . V_58 ) *
V_3 -> V_141 ;
V_133 -> V_138 . V_80 = V_69 -> V_79 . V_80 ;
F_4 ( L_44 , V_133 -> V_138 . V_139 ,
( unsigned long long ) V_133 -> V_138 . V_80 ) ;
F_78 (cmd->t_prot_sg, sg, cmd->t_prot_nents, i) {
V_135 = F_79 ( V_69 , F_57 ( V_93 ) , V_93 -> V_104 ,
V_93 -> V_96 ) ;
if ( V_135 != V_93 -> V_104 ) {
F_8 ( L_45 , V_135 ) ;
return - V_21 ;
}
F_4 ( L_46 ,
F_57 ( V_93 ) , V_93 -> V_104 , V_93 -> V_96 ) ;
}
return 0 ;
}
static T_5
F_80 ( struct V_59 * V_60 , struct V_92 * V_142 , T_1 V_143 ,
enum V_144 V_145 )
{
struct V_2 * V_3 = V_60 -> V_74 ;
T_4 V_101 = F_50 ( V_3 , V_60 -> V_99 ) ;
struct V_61 * V_62 ;
struct V_69 * V_69 , * V_146 ;
struct V_81 V_82 ;
struct V_92 * V_93 ;
T_1 V_73 = V_143 ;
unsigned V_147 ;
int V_83 = 0 ;
int V_134 ;
if ( V_145 == V_148 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_36 ) ;
if ( F_81 ( V_149 , & V_14 -> V_150 ) ) {
if ( V_60 -> V_151 & V_152 )
V_83 = V_153 ;
else if ( ! F_81 ( V_154 , & V_14 -> V_150 ) )
V_83 = V_153 ;
else
V_83 = V_110 ;
} else {
V_83 = V_110 ;
}
} else {
V_83 = V_155 ;
}
V_62 = F_7 ( sizeof( struct V_61 ) , V_12 ) ;
if ( ! V_62 )
goto V_106;
V_60 -> V_63 = V_62 ;
if ( ! V_143 ) {
F_63 ( & V_62 -> V_65 , 1 ) ;
F_30 ( V_60 ) ;
return 0 ;
}
V_69 = F_38 ( V_60 , V_101 , V_143 ) ;
if ( ! V_69 )
goto V_107;
V_146 = V_69 ;
F_61 ( & V_82 ) ;
F_62 ( & V_82 , V_69 ) ;
F_63 ( & V_62 -> V_65 , 2 ) ;
V_147 = 1 ;
F_78 (sgl, sg, sgl_nents, i) {
while ( F_64 ( V_69 , F_57 ( V_93 ) , V_93 -> V_104 , V_93 -> V_96 )
!= V_93 -> V_104 ) {
if ( V_147 >= V_156 ) {
F_40 ( & V_82 , V_83 ) ;
V_147 = 0 ;
}
V_69 = F_38 ( V_60 , V_101 , V_73 ) ;
if ( ! V_69 )
goto V_108;
F_35 ( & V_62 -> V_65 ) ;
F_62 ( & V_82 , V_69 ) ;
V_147 ++ ;
}
V_101 += V_93 -> V_104 >> V_109 ;
V_73 -- ;
}
if ( V_60 -> V_157 && V_3 -> V_37 . V_49 ) {
int V_135 = F_76 ( V_60 , V_146 ) ;
if ( V_135 )
goto V_108;
}
F_40 ( & V_82 , V_83 ) ;
F_30 ( V_60 ) ;
return 0 ;
V_108:
while ( ( V_69 = F_42 ( & V_82 ) ) )
F_37 ( V_69 ) ;
V_107:
F_24 ( V_62 ) ;
V_106:
return V_91 ;
}
static T_4 F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_27 ( V_3 , V_16 , V_14 ) ;
}
static T_4 F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
int V_20 ;
V_20 = F_84 ( V_16 ) ;
if ( V_20 == - 1 )
return 0 ;
return V_20 / F_15 ( V_16 ) ;
}
static unsigned int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
int V_158 = F_86 ( V_16 ) / F_15 ( V_16 ) ;
return F_87 ( V_158 ) ;
}
static unsigned int F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
return F_89 ( V_16 ) ;
}
static unsigned int F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
return F_91 ( V_16 ) ;
}
static T_5
F_92 ( struct V_59 * V_60 )
{
return F_93 ( V_60 , & V_159 ) ;
}
static bool F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_36 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_81 ( V_154 , & V_14 -> V_150 ) ;
}
static int T_8 F_95 ( void )
{
return F_96 ( & V_160 ) ;
}
static void T_9 F_97 ( void )
{
F_98 ( & V_160 ) ;
}
