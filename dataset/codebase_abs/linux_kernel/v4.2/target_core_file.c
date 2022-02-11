static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_7 ;
V_7 = F_4 ( sizeof( struct V_7 ) , V_8 ) ;
if ( ! V_7 ) {
F_5 ( L_1 ) ;
return - V_9 ;
}
V_7 -> V_10 = V_6 ;
V_5 -> V_11 = V_7 ;
F_6 ( L_2
L_3 , V_5 -> V_12 , V_13 ,
V_14 ) ;
F_6 ( L_4 ,
V_5 -> V_12 , V_7 -> V_10 ) ;
return 0 ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_7 * V_7 = V_5 -> V_11 ;
F_6 ( L_5
L_6 , V_5 -> V_12 , V_7 -> V_10 ) ;
F_8 ( V_7 ) ;
V_5 -> V_11 = NULL ;
}
static struct V_2 * F_9 ( struct V_4 * V_5 , const char * V_15 )
{
struct V_1 * V_1 ;
struct V_7 * V_7 = V_5 -> V_11 ;
V_1 = F_4 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_1 ) {
F_5 ( L_7 ) ;
return NULL ;
}
V_1 -> V_7 = V_7 ;
F_6 ( L_8 , V_15 ) ;
return & V_1 -> V_3 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_3 -> V_4 -> V_11 ;
struct V_16 * V_16 ;
struct V_17 * V_17 = NULL ;
int V_18 , V_19 = - V_20 ;
if ( ! ( V_1 -> V_21 & V_22 ) ) {
F_5 ( L_9 ) ;
return - V_20 ;
}
V_18 = V_23 | V_24 | V_25 | V_26 ;
if ( V_1 -> V_21 & V_27 ) {
F_6 ( L_10 ) ;
V_18 &= ~ V_26 ;
}
V_16 = F_11 ( V_1 -> V_28 , V_18 , 0600 ) ;
if ( F_12 ( V_16 ) ) {
F_5 ( L_11 , V_1 -> V_28 ) ;
V_19 = F_13 ( V_16 ) ;
goto V_29;
}
V_1 -> V_30 = V_16 ;
V_17 = V_16 -> V_31 -> V_32 ;
if ( F_14 ( V_17 -> V_33 ) ) {
struct V_34 * V_35 = F_15 ( V_17 -> V_36 ) ;
unsigned long long V_37 ;
V_1 -> V_38 = F_16 ( V_17 -> V_36 ) ;
V_37 = ( F_17 ( V_16 -> V_31 -> V_32 ) -
V_1 -> V_38 ) ;
F_6 ( L_12
L_13 ,
V_37 , F_18 ( V_37 , V_1 -> V_38 ) ,
V_1 -> V_38 ) ;
if ( F_19 ( V_35 ) ) {
V_3 -> V_39 . V_40 =
V_35 -> V_41 . V_42 ;
V_3 -> V_39 . V_43 = 1 ;
V_3 -> V_39 . V_44 =
V_35 -> V_41 . V_45 >> 9 ;
V_3 -> V_39 . V_46 =
V_35 -> V_41 . V_47 ;
F_6 ( L_14
L_15 ) ;
}
V_3 -> V_39 . V_48 = 0xFFFF ;
if ( F_20 ( V_35 ) )
V_3 -> V_39 . V_49 = 1 ;
} else {
if ( ! ( V_1 -> V_21 & V_50 ) ) {
F_5 ( L_16
L_17
L_18 ) ;
goto V_29;
}
V_1 -> V_38 = V_51 ;
V_3 -> V_39 . V_40 = 0x2000 ;
V_3 -> V_39 . V_43 = 1 ;
V_3 -> V_39 . V_44 = 1 ;
V_3 -> V_39 . V_46 = 0 ;
V_3 -> V_39 . V_48 = 0x1000 ;
}
V_3 -> V_39 . V_52 = V_1 -> V_38 ;
V_3 -> V_39 . V_53 = V_54 ;
V_3 -> V_39 . V_55 = V_54 / V_1 -> V_38 ;
V_3 -> V_39 . V_56 = V_57 ;
if ( V_1 -> V_21 & V_27 ) {
F_6 ( L_19
L_20 ) ;
V_3 -> V_39 . V_58 = 1 ;
}
V_1 -> V_59 = V_7 -> V_60 ++ ;
V_1 -> V_61 = V_3 -> V_62 ;
F_6 ( L_21
L_22 , V_7 -> V_10 , V_1 -> V_59 ,
V_1 -> V_28 , V_1 -> V_63 ) ;
return 0 ;
V_29:
if ( V_1 -> V_30 ) {
F_21 ( V_1 -> V_30 , NULL ) ;
V_1 -> V_30 = NULL ;
}
return V_19 ;
}
static void F_22 ( struct V_64 * V_65 )
{
struct V_2 * V_3 = F_2 ( V_65 , struct V_2 , V_64 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_8 ( V_1 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_30 ) {
F_21 ( V_1 -> V_30 , NULL ) ;
V_1 -> V_30 = NULL ;
}
F_24 ( & V_3 -> V_64 , F_22 ) ;
}
static int F_25 ( struct V_66 * V_67 , struct V_16 * V_68 ,
T_1 V_69 , struct V_70 * V_71 ,
T_1 V_72 , T_1 V_73 , int V_74 )
{
struct V_70 * V_75 ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
T_2 V_80 = 0 ;
T_3 V_81 = ( V_67 -> V_82 * V_69 ) ;
int V_19 = 0 , V_83 ;
V_79 = F_26 ( V_72 , sizeof( struct V_78 ) , V_8 ) ;
if ( ! V_79 ) {
F_5 ( L_23 ) ;
return - V_9 ;
}
F_27 (sgl, sg, sgl_nents, i) {
V_79 [ V_83 ] . V_84 = F_28 ( V_75 ) ;
V_79 [ V_83 ] . V_85 = V_75 -> V_86 ;
V_79 [ V_83 ] . V_87 = V_75 -> V_88 ;
V_80 += V_75 -> V_86 ;
}
F_29 ( & V_77 , V_89 , V_79 , V_72 , V_80 ) ;
if ( V_74 )
V_19 = F_30 ( V_68 , & V_77 , & V_81 ) ;
else
V_19 = F_31 ( V_68 , & V_77 , & V_81 ) ;
F_8 ( V_79 ) ;
if ( V_74 ) {
if ( V_19 < 0 || V_19 != V_73 ) {
F_5 ( L_24 , V_90 , V_19 ) ;
return ( V_19 < 0 ? V_19 : - V_20 ) ;
}
} else {
if ( F_14 ( F_32 ( V_68 ) -> V_33 ) ) {
if ( V_19 < 0 || V_19 != V_73 ) {
F_5 ( L_25
L_26 , V_90 , V_19 ,
V_73 ) ;
return ( V_19 < 0 ? V_19 : - V_20 ) ;
}
} else {
if ( V_19 < 0 ) {
F_5 ( L_27 ,
V_90 , V_19 ) ;
return V_19 ;
}
}
}
return 1 ;
}
static T_4
F_33 ( struct V_66 * V_67 )
{
struct V_2 * V_3 = V_67 -> V_91 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_92 = ( V_67 -> V_93 [ 1 ] & 0x2 ) ;
T_3 V_94 , V_95 ;
int V_19 ;
if ( V_92 )
F_34 ( V_67 , V_96 ) ;
if ( V_67 -> V_82 == 0 && V_67 -> V_73 == 0 ) {
V_94 = 0 ;
V_95 = V_97 ;
} else {
V_94 = V_67 -> V_82 * V_3 -> V_39 . V_69 ;
if ( V_67 -> V_73 )
V_95 = V_94 + V_67 -> V_73 - 1 ;
else
V_95 = V_97 ;
}
V_19 = F_35 ( V_1 -> V_30 , V_94 , V_95 , 1 ) ;
if ( V_19 != 0 )
F_5 ( L_28 , V_19 ) ;
if ( V_92 )
return 0 ;
if ( V_19 )
F_34 ( V_67 , V_98 ) ;
else
F_34 ( V_67 , V_96 ) ;
return 0 ;
}
static T_4
F_36 ( struct V_66 * V_67 )
{
struct V_2 * V_91 = V_67 -> V_91 ;
struct V_1 * V_1 = F_1 ( V_91 ) ;
T_3 V_81 = V_67 -> V_82 * V_91 -> V_39 . V_69 ;
T_5 V_99 = F_37 ( V_67 ) ;
struct V_76 V_77 ;
struct V_78 * V_79 ;
unsigned int V_80 = 0 , V_83 ;
T_2 V_19 ;
if ( ! V_99 ) {
F_34 ( V_67 , V_96 ) ;
return 0 ;
}
if ( V_67 -> V_100 ) {
F_5 ( L_29
L_30 ) ;
return V_101 ;
}
if ( V_67 -> V_102 > 1 ||
V_67 -> V_103 [ 0 ] . V_86 != V_67 -> V_91 -> V_39 . V_69 ) {
F_5 ( L_31
L_32 ,
V_67 -> V_102 ,
V_67 -> V_103 [ 0 ] . V_86 ,
V_67 -> V_91 -> V_39 . V_69 ) ;
return V_104 ;
}
V_79 = F_26 ( V_99 , sizeof( struct V_78 ) , V_8 ) ;
if ( ! V_79 )
return V_101 ;
for ( V_83 = 0 ; V_83 < V_99 ; V_83 ++ ) {
V_79 [ V_83 ] . V_84 = F_28 ( & V_67 -> V_103 [ 0 ] ) ;
V_79 [ V_83 ] . V_85 = V_67 -> V_103 [ 0 ] . V_86 ;
V_79 [ V_83 ] . V_87 = V_67 -> V_103 [ 0 ] . V_88 ;
V_80 += V_91 -> V_39 . V_69 ;
}
F_29 ( & V_77 , V_89 , V_79 , V_99 , V_80 ) ;
V_19 = F_30 ( V_1 -> V_30 , & V_77 , & V_81 ) ;
F_8 ( V_79 ) ;
if ( V_19 < 0 || V_19 != V_80 ) {
F_5 ( L_33 , V_19 ) ;
return V_101 ;
}
F_34 ( V_67 , V_96 ) ;
return 0 ;
}
static int
F_38 ( struct V_2 * V_91 , T_5 V_105 , T_5 V_99 ,
void * V_106 , T_6 V_107 )
{
struct V_1 * V_1 = F_1 ( V_91 ) ;
struct V_16 * V_108 = V_1 -> V_109 ;
T_5 V_110 , V_111 ;
T_3 V_81 = V_105 * V_91 -> V_110 ;
if ( ! V_108 ) {
F_5 ( L_34 ) ;
return - V_112 ;
}
V_110 = V_99 * V_91 -> V_110 ;
for ( V_111 = 0 ; V_111 < V_110 ; ) {
T_5 V_80 = F_39 ( T_5 , V_107 , V_110 - V_111 ) ;
T_2 V_19 = F_40 ( V_108 , V_106 , V_80 , V_81 + V_111 ) ;
if ( V_19 != V_80 ) {
F_5 ( L_35 , V_19 ) ;
return V_19 < 0 ? V_19 : - V_112 ;
}
V_111 += V_19 ;
}
return 0 ;
}
static int
F_41 ( struct V_66 * V_67 , T_5 V_105 , T_5 V_99 )
{
void * V_106 ;
int V_113 ;
V_106 = ( void * ) F_42 ( V_8 ) ;
if ( ! V_106 ) {
F_5 ( L_36 ) ;
return - V_9 ;
}
memset ( V_106 , 0xff , V_114 ) ;
V_113 = F_38 ( V_67 -> V_91 , V_105 , V_99 , V_106 , V_114 ) ;
F_43 ( ( unsigned long ) V_106 ) ;
return V_113 ;
}
static T_4
F_44 ( struct V_66 * V_67 , T_5 V_105 , T_5 V_99 )
{
struct V_16 * V_16 = F_1 ( V_67 -> V_91 ) -> V_30 ;
struct V_17 * V_17 = V_16 -> V_31 -> V_32 ;
int V_19 ;
if ( V_67 -> V_91 -> V_39 . V_115 ) {
V_19 = F_41 ( V_67 , V_105 , V_99 ) ;
if ( V_19 )
return V_101 ;
}
if ( F_14 ( V_17 -> V_33 ) ) {
struct V_116 * V_117 = V_17 -> V_36 ;
V_19 = F_45 ( V_117 , V_105 ,
V_99 , V_8 , 0 ) ;
if ( V_19 < 0 ) {
F_46 ( L_37 ,
V_19 ) ;
return V_101 ;
}
} else {
struct V_2 * V_91 = V_67 -> V_91 ;
T_3 V_81 = V_105 * V_91 -> V_39 . V_69 ;
unsigned int V_80 = V_99 * V_91 -> V_39 . V_69 ;
int V_118 = V_119 | V_120 ;
if ( ! V_16 -> V_121 -> V_122 )
return V_101 ;
V_19 = V_16 -> V_121 -> V_122 ( V_16 , V_118 , V_81 , V_80 ) ;
if ( V_19 < 0 ) {
F_46 ( L_38 , V_19 ) ;
return V_101 ;
}
}
return 0 ;
}
static T_4
F_47 ( struct V_66 * V_67 , struct V_70 * V_71 , T_1 V_72 ,
enum V_123 V_124 )
{
struct V_2 * V_3 = V_67 -> V_91 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_16 = V_1 -> V_30 ;
struct V_16 * V_125 = V_1 -> V_109 ;
T_4 V_113 ;
int V_19 = 0 ;
if ( V_67 -> V_73 > V_54 ) {
F_5 ( L_39
L_40 ,
V_67 -> V_73 , V_54 ) ;
return V_101 ;
}
if ( V_124 == V_126 ) {
if ( V_67 -> V_127 && V_3 -> V_39 . V_115 ) {
V_19 = F_25 ( V_67 , V_125 , V_3 -> V_110 ,
V_67 -> V_128 , V_67 -> V_129 ,
V_67 -> V_110 , 0 ) ;
if ( V_19 < 0 )
return V_101 ;
}
V_19 = F_25 ( V_67 , V_16 , V_3 -> V_39 . V_69 ,
V_71 , V_72 , V_67 -> V_73 , 0 ) ;
if ( V_19 > 0 && V_67 -> V_127 && V_3 -> V_39 . V_115 ) {
T_1 V_130 = V_67 -> V_73 >>
F_48 ( V_3 -> V_39 . V_69 ) ;
V_113 = F_49 ( V_67 , V_67 -> V_82 , V_130 ,
0 , V_67 -> V_128 , 0 ) ;
if ( V_113 )
return V_113 ;
}
} else {
if ( V_67 -> V_127 && V_3 -> V_39 . V_115 ) {
T_1 V_130 = V_67 -> V_73 >>
F_48 ( V_3 -> V_39 . V_69 ) ;
V_113 = F_49 ( V_67 , V_67 -> V_82 , V_130 ,
0 , V_67 -> V_128 , 0 ) ;
if ( V_113 )
return V_113 ;
}
V_19 = F_25 ( V_67 , V_16 , V_3 -> V_39 . V_69 ,
V_71 , V_72 , V_67 -> V_73 , 1 ) ;
if ( V_19 > 0 && ( V_67 -> V_131 & V_132 ) ) {
T_3 V_94 = V_67 -> V_82 *
V_3 -> V_39 . V_69 ;
T_3 V_95 ;
if ( V_67 -> V_73 )
V_95 = V_94 + V_67 -> V_73 - 1 ;
else
V_95 = V_97 ;
F_35 ( V_1 -> V_30 , V_94 , V_95 , 1 ) ;
}
if ( V_19 > 0 && V_67 -> V_127 && V_3 -> V_39 . V_115 ) {
V_19 = F_25 ( V_67 , V_125 , V_3 -> V_110 ,
V_67 -> V_128 , V_67 -> V_129 ,
V_67 -> V_110 , 1 ) ;
if ( V_19 < 0 )
return V_101 ;
}
}
if ( V_19 < 0 )
return V_101 ;
if ( V_19 )
F_34 ( V_67 , V_96 ) ;
return 0 ;
}
static T_2 F_50 ( struct V_2 * V_3 ,
const char * V_133 , T_2 V_134 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_135 , * V_136 , * V_137 , * V_138 ;
T_7 args [ V_139 ] ;
int V_19 = 0 , V_140 , V_141 ;
V_138 = F_51 ( V_133 , V_8 ) ;
if ( ! V_138 )
return - V_9 ;
V_135 = V_138 ;
while ( ( V_136 = F_52 ( & V_138 , L_41 ) ) != NULL ) {
if ( ! * V_136 )
continue;
V_141 = F_53 ( V_136 , V_142 , args ) ;
switch ( V_141 ) {
case V_143 :
if ( F_54 ( V_1 -> V_28 , & args [ 0 ] ,
V_144 ) == 0 ) {
V_19 = - V_20 ;
break;
}
F_6 ( L_42 ,
V_1 -> V_28 ) ;
V_1 -> V_21 |= V_22 ;
break;
case V_145 :
V_137 = F_55 ( & args [ 0 ] ) ;
if ( ! V_137 ) {
V_19 = - V_9 ;
break;
}
V_19 = F_56 ( V_137 , 0 , & V_1 -> V_63 ) ;
F_8 ( V_137 ) ;
if ( V_19 < 0 ) {
F_5 ( L_43
L_44 ) ;
goto V_146;
}
F_6 ( L_45
L_46 , V_1 -> V_63 ) ;
V_1 -> V_21 |= V_50 ;
break;
case V_147 :
V_19 = F_57 ( args , & V_140 ) ;
if ( V_19 )
goto V_146;
if ( V_140 != 1 ) {
F_5 ( L_47 , V_140 ) ;
V_19 = - V_20 ;
goto V_146;
}
F_6 ( L_48
L_49 ) ;
V_1 -> V_21 |= V_27 ;
break;
default:
break;
}
}
V_146:
F_8 ( V_135 ) ;
return ( ! V_19 ) ? V_134 : V_19 ;
}
static T_2 F_58 ( struct V_2 * V_3 , char * V_148 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_149 = 0 ;
V_149 = sprintf ( V_148 + V_149 , L_50 , V_1 -> V_59 ) ;
V_149 += sprintf ( V_148 + V_149 , L_51 ,
V_1 -> V_28 , V_1 -> V_63 ,
( V_1 -> V_21 & V_27 ) ?
L_52 : L_53 ) ;
return V_149 ;
}
static T_5 F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_150 = V_1 -> V_30 ;
struct V_17 * V_83 = V_150 -> V_31 -> V_32 ;
unsigned long long V_37 ;
if ( F_14 ( V_83 -> V_33 ) )
V_37 = F_17 ( V_83 ) ;
else
V_37 = V_1 -> V_63 ;
return F_18 ( V_37 - V_3 -> V_39 . V_69 ,
V_3 -> V_39 . V_69 ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_151 , * V_16 = V_1 -> V_30 ;
struct V_17 * V_17 ;
int V_19 , V_18 = V_23 | V_24 | V_25 | V_26 ;
char V_106 [ V_152 ] ;
if ( ! V_16 ) {
F_5 ( L_54 ) ;
return - V_112 ;
}
V_17 = V_16 -> V_31 -> V_32 ;
if ( F_14 ( V_17 -> V_33 ) ) {
F_5 ( L_55
L_56 ) ;
return - V_153 ;
}
if ( V_1 -> V_21 & V_27 )
V_18 &= ~ V_26 ;
snprintf ( V_106 , V_152 , L_57 ,
V_1 -> V_28 ) ;
V_151 = F_11 ( V_106 , V_18 , 0600 ) ;
if ( F_12 ( V_151 ) ) {
F_5 ( L_11 , V_106 ) ;
V_19 = F_13 ( V_151 ) ;
return V_19 ;
}
V_1 -> V_109 = V_151 ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
unsigned char * V_106 ;
int V_154 = V_155 * V_3 -> V_39 . V_69 ;
int V_19 ;
if ( ! V_3 -> V_39 . V_115 ) {
F_5 ( L_58 ) ;
return - V_112 ;
}
V_106 = F_62 ( V_154 ) ;
if ( ! V_106 ) {
F_5 ( L_36 ) ;
return - V_9 ;
}
F_6 ( L_59 ,
( unsigned long long ) ( V_3 -> V_156 -> V_157 ( V_3 ) + 1 ) *
V_3 -> V_110 ) ;
memset ( V_106 , 0xff , V_154 ) ;
V_19 = F_38 ( V_3 , 0 , V_3 -> V_156 -> V_157 ( V_3 ) + 1 ,
V_106 , V_154 ) ;
F_63 ( V_106 ) ;
return V_19 ;
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 -> V_109 )
return;
F_21 ( V_1 -> V_109 , NULL ) ;
V_1 -> V_109 = NULL ;
}
static T_4
F_65 ( struct V_66 * V_67 )
{
return F_66 ( V_67 , & V_158 ) ;
}
static int T_8 F_67 ( void )
{
return F_68 ( & V_159 ) ;
}
static void T_9 F_69 ( void )
{
F_70 ( & V_159 ) ;
}
