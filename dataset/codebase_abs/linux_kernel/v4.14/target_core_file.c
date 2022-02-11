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
if ( F_19 ( & V_3 -> V_39 , V_35 ) )
F_6 ( L_14
L_15 ) ;
V_3 -> V_39 . V_40 = 0xFFFF ;
if ( F_20 ( V_35 ) )
V_3 -> V_39 . V_41 = 1 ;
} else {
if ( ! ( V_1 -> V_21 & V_42 ) ) {
F_5 ( L_16
L_17
L_18 ) ;
goto V_29;
}
V_1 -> V_38 = V_43 ;
V_3 -> V_39 . V_44 = 0x2000 ;
V_3 -> V_39 . V_45 = 1 ;
V_3 -> V_39 . V_46 = 1 ;
V_3 -> V_39 . V_47 = 0 ;
V_3 -> V_39 . V_40 = 0x1000 ;
}
V_3 -> V_39 . V_48 = V_1 -> V_38 ;
V_3 -> V_39 . V_49 = V_50 ;
V_3 -> V_39 . V_51 = V_50 / V_1 -> V_38 ;
V_3 -> V_39 . V_52 = V_53 ;
if ( V_1 -> V_21 & V_27 ) {
F_6 ( L_19
L_20 ) ;
V_3 -> V_39 . V_54 = 1 ;
}
V_1 -> V_55 = V_7 -> V_56 ++ ;
V_1 -> V_57 = V_3 -> V_58 ;
F_6 ( L_21
L_22 , V_7 -> V_10 , V_1 -> V_55 ,
V_1 -> V_28 , V_1 -> V_59 ) ;
return 0 ;
V_29:
if ( V_1 -> V_30 ) {
F_21 ( V_1 -> V_30 , NULL ) ;
V_1 -> V_30 = NULL ;
}
return V_19 ;
}
static void F_22 ( struct V_60 * V_61 )
{
struct V_2 * V_3 = F_2 ( V_61 , struct V_2 , V_60 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_8 ( V_1 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
F_24 ( & V_3 -> V_60 , F_22 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_30 ) {
F_21 ( V_1 -> V_30 , NULL ) ;
V_1 -> V_30 = NULL ;
}
}
static int F_26 ( struct V_62 * V_63 , struct V_16 * V_64 ,
T_1 V_65 , struct V_66 * V_67 ,
T_1 V_68 , T_1 V_69 , int V_70 )
{
struct V_66 * V_71 ;
struct V_72 V_73 ;
struct V_74 * V_75 ;
T_2 V_76 = 0 ;
T_3 V_77 = ( V_63 -> V_78 * V_65 ) ;
int V_19 = 0 , V_79 ;
V_75 = F_27 ( V_68 , sizeof( struct V_74 ) , V_8 ) ;
if ( ! V_75 ) {
F_5 ( L_23 ) ;
return - V_9 ;
}
F_28 (sgl, sg, sgl_nents, i) {
V_75 [ V_79 ] . V_80 = F_29 ( V_71 ) ;
V_75 [ V_79 ] . V_81 = V_71 -> V_82 ;
V_75 [ V_79 ] . V_83 = V_71 -> V_84 ;
V_76 += V_71 -> V_82 ;
}
F_30 ( & V_73 , V_85 , V_75 , V_68 , V_76 ) ;
if ( V_70 )
V_19 = F_31 ( V_64 , & V_73 , & V_77 , 0 ) ;
else
V_19 = F_32 ( V_64 , & V_73 , & V_77 , 0 ) ;
if ( V_70 ) {
if ( V_19 < 0 || V_19 != V_69 ) {
F_5 ( L_24 , V_86 , V_19 ) ;
if ( V_19 >= 0 )
V_19 = - V_20 ;
}
} else {
if ( F_14 ( F_33 ( V_64 ) -> V_33 ) ) {
if ( V_19 < 0 || V_19 != V_69 ) {
F_5 ( L_25
L_26 , V_86 , V_19 ,
V_69 ) ;
if ( V_19 >= 0 )
V_19 = - V_20 ;
}
} else {
if ( V_19 < 0 ) {
F_5 ( L_27 ,
V_86 , V_19 ) ;
} else if ( V_19 != V_69 ) {
if ( V_19 < V_69 )
V_19 += F_34 ( V_69 - V_19 , & V_73 ) ;
else
V_19 = - V_20 ;
}
}
}
F_8 ( V_75 ) ;
return V_19 ;
}
static T_4
F_35 ( struct V_62 * V_63 )
{
struct V_2 * V_3 = V_63 -> V_87 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_88 = ( V_63 -> V_89 [ 1 ] & 0x2 ) ;
T_3 V_90 , V_91 ;
int V_19 ;
if ( V_88 )
F_36 ( V_63 , V_92 ) ;
if ( V_63 -> V_78 == 0 && V_63 -> V_69 == 0 ) {
V_90 = 0 ;
V_91 = V_93 ;
} else {
V_90 = V_63 -> V_78 * V_3 -> V_39 . V_65 ;
if ( V_63 -> V_69 )
V_91 = V_90 + V_63 -> V_69 - 1 ;
else
V_91 = V_93 ;
}
V_19 = F_37 ( V_1 -> V_30 , V_90 , V_91 , 1 ) ;
if ( V_19 != 0 )
F_5 ( L_28 , V_19 ) ;
if ( V_88 )
return 0 ;
if ( V_19 )
F_36 ( V_63 , V_94 ) ;
else
F_36 ( V_63 , V_92 ) ;
return 0 ;
}
static T_4
F_38 ( struct V_62 * V_63 )
{
struct V_2 * V_87 = V_63 -> V_87 ;
struct V_1 * V_1 = F_1 ( V_87 ) ;
T_3 V_77 = V_63 -> V_78 * V_87 -> V_39 . V_65 ;
T_5 V_95 = F_39 ( V_63 ) ;
struct V_72 V_73 ;
struct V_74 * V_75 ;
unsigned int V_76 = 0 , V_79 ;
T_2 V_19 ;
if ( ! V_95 ) {
F_36 ( V_63 , V_92 ) ;
return 0 ;
}
if ( V_63 -> V_96 ) {
F_5 ( L_29
L_30 ) ;
return V_97 ;
}
if ( V_63 -> V_98 > 1 ||
V_63 -> V_99 [ 0 ] . V_82 != V_63 -> V_87 -> V_39 . V_65 ) {
F_5 ( L_31
L_32 ,
V_63 -> V_98 ,
V_63 -> V_99 [ 0 ] . V_82 ,
V_63 -> V_87 -> V_39 . V_65 ) ;
return V_100 ;
}
V_75 = F_27 ( V_95 , sizeof( struct V_74 ) , V_8 ) ;
if ( ! V_75 )
return V_97 ;
for ( V_79 = 0 ; V_79 < V_95 ; V_79 ++ ) {
V_75 [ V_79 ] . V_80 = F_29 ( & V_63 -> V_99 [ 0 ] ) ;
V_75 [ V_79 ] . V_81 = V_63 -> V_99 [ 0 ] . V_82 ;
V_75 [ V_79 ] . V_83 = V_63 -> V_99 [ 0 ] . V_84 ;
V_76 += V_87 -> V_39 . V_65 ;
}
F_30 ( & V_73 , V_85 , V_75 , V_95 , V_76 ) ;
V_19 = F_31 ( V_1 -> V_30 , & V_73 , & V_77 , 0 ) ;
F_8 ( V_75 ) ;
if ( V_19 < 0 || V_19 != V_76 ) {
F_5 ( L_33 , V_19 ) ;
return V_97 ;
}
F_36 ( V_63 , V_92 ) ;
return 0 ;
}
static int
F_40 ( struct V_2 * V_87 , T_5 V_101 , T_5 V_95 ,
void * V_102 , T_6 V_103 )
{
struct V_1 * V_1 = F_1 ( V_87 ) ;
struct V_16 * V_104 = V_1 -> V_105 ;
T_5 V_106 , V_107 ;
T_3 V_77 = V_101 * V_87 -> V_106 ;
if ( ! V_104 ) {
F_5 ( L_34 ) ;
return - V_108 ;
}
V_106 = V_95 * V_87 -> V_106 ;
for ( V_107 = 0 ; V_107 < V_106 ; ) {
T_5 V_76 = F_41 ( T_5 , V_103 , V_106 - V_107 ) ;
T_2 V_19 = F_42 ( V_104 , V_102 , V_76 , & V_77 ) ;
if ( V_19 != V_76 ) {
F_5 ( L_35 , V_19 ) ;
return V_19 < 0 ? V_19 : - V_108 ;
}
V_107 += V_19 ;
}
return 0 ;
}
static int
F_43 ( struct V_62 * V_63 , T_5 V_101 , T_5 V_95 )
{
void * V_102 ;
int V_109 ;
V_102 = ( void * ) F_44 ( V_8 ) ;
if ( ! V_102 ) {
F_5 ( L_36 ) ;
return - V_9 ;
}
memset ( V_102 , 0xff , V_110 ) ;
V_109 = F_40 ( V_63 -> V_87 , V_101 , V_95 , V_102 , V_110 ) ;
F_45 ( ( unsigned long ) V_102 ) ;
return V_109 ;
}
static T_4
F_46 ( struct V_62 * V_63 , T_5 V_101 , T_5 V_95 )
{
struct V_16 * V_16 = F_1 ( V_63 -> V_87 ) -> V_30 ;
struct V_17 * V_17 = V_16 -> V_31 -> V_32 ;
int V_19 ;
if ( V_63 -> V_87 -> V_39 . V_111 ) {
V_19 = F_43 ( V_63 , V_101 , V_95 ) ;
if ( V_19 )
return V_97 ;
}
if ( F_14 ( V_17 -> V_33 ) ) {
struct V_112 * V_113 = V_17 -> V_36 ;
struct V_2 * V_3 = V_63 -> V_87 ;
V_19 = F_47 ( V_113 ,
F_48 ( V_3 , V_101 ) ,
F_48 ( V_3 , V_95 ) ,
V_8 , 0 ) ;
if ( V_19 < 0 ) {
F_49 ( L_37 ,
V_19 ) ;
return V_97 ;
}
} else {
struct V_2 * V_87 = V_63 -> V_87 ;
T_3 V_77 = V_101 * V_87 -> V_39 . V_65 ;
unsigned int V_76 = V_95 * V_87 -> V_39 . V_65 ;
int V_114 = V_115 | V_116 ;
if ( ! V_16 -> V_117 -> V_118 )
return V_97 ;
V_19 = V_16 -> V_117 -> V_118 ( V_16 , V_114 , V_77 , V_76 ) ;
if ( V_19 < 0 ) {
F_49 ( L_38 , V_19 ) ;
return V_97 ;
}
}
return 0 ;
}
static T_4
F_50 ( struct V_62 * V_63 , struct V_66 * V_67 , T_1 V_68 ,
enum V_119 V_120 )
{
struct V_2 * V_3 = V_63 -> V_87 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_16 = V_1 -> V_30 ;
struct V_16 * V_121 = V_1 -> V_105 ;
T_4 V_109 ;
int V_19 = 0 ;
if ( V_63 -> V_69 > V_50 ) {
F_5 ( L_39
L_40 ,
V_63 -> V_69 , V_50 ) ;
return V_97 ;
}
if ( V_120 == V_122 ) {
if ( V_63 -> V_123 && V_3 -> V_39 . V_111 ) {
V_19 = F_26 ( V_63 , V_121 , V_3 -> V_106 ,
V_63 -> V_124 , V_63 -> V_125 ,
V_63 -> V_106 , 0 ) ;
if ( V_19 < 0 )
return V_97 ;
}
V_19 = F_26 ( V_63 , V_16 , V_3 -> V_39 . V_65 ,
V_67 , V_68 , V_63 -> V_69 , 0 ) ;
if ( V_19 > 0 && V_63 -> V_123 && V_3 -> V_39 . V_111 &&
V_3 -> V_39 . V_126 ) {
T_1 V_127 = V_63 -> V_69 >>
F_51 ( V_3 -> V_39 . V_65 ) ;
V_109 = F_52 ( V_63 , V_63 -> V_78 , V_127 ,
0 , V_63 -> V_124 , 0 ) ;
if ( V_109 )
return V_109 ;
}
} else {
if ( V_63 -> V_123 && V_3 -> V_39 . V_111 &&
V_3 -> V_39 . V_126 ) {
T_1 V_127 = V_63 -> V_69 >>
F_51 ( V_3 -> V_39 . V_65 ) ;
V_109 = F_52 ( V_63 , V_63 -> V_78 , V_127 ,
0 , V_63 -> V_124 , 0 ) ;
if ( V_109 )
return V_109 ;
}
V_19 = F_26 ( V_63 , V_16 , V_3 -> V_39 . V_65 ,
V_67 , V_68 , V_63 -> V_69 , 1 ) ;
if ( V_19 > 0 && ( V_63 -> V_128 & V_129 ) ) {
T_3 V_90 = V_63 -> V_78 *
V_3 -> V_39 . V_65 ;
T_3 V_91 ;
if ( V_63 -> V_69 )
V_91 = V_90 + V_63 -> V_69 - 1 ;
else
V_91 = V_93 ;
F_37 ( V_1 -> V_30 , V_90 , V_91 , 1 ) ;
}
if ( V_19 > 0 && V_63 -> V_123 && V_3 -> V_39 . V_111 ) {
V_19 = F_26 ( V_63 , V_121 , V_3 -> V_106 ,
V_63 -> V_124 , V_63 -> V_125 ,
V_63 -> V_106 , 1 ) ;
if ( V_19 < 0 )
return V_97 ;
}
}
if ( V_19 < 0 )
return V_97 ;
F_36 ( V_63 , V_92 ) ;
return 0 ;
}
static T_2 F_53 ( struct V_2 * V_3 ,
const char * V_130 , T_2 V_131 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_132 , * V_133 , * V_134 , * V_135 ;
T_7 args [ V_136 ] ;
int V_19 = 0 , V_137 , V_138 ;
V_135 = F_54 ( V_130 , V_8 ) ;
if ( ! V_135 )
return - V_9 ;
V_132 = V_135 ;
while ( ( V_133 = F_55 ( & V_135 , L_41 ) ) != NULL ) {
if ( ! * V_133 )
continue;
V_138 = F_56 ( V_133 , V_139 , args ) ;
switch ( V_138 ) {
case V_140 :
if ( F_57 ( V_1 -> V_28 , & args [ 0 ] ,
V_141 ) == 0 ) {
V_19 = - V_20 ;
break;
}
F_6 ( L_42 ,
V_1 -> V_28 ) ;
V_1 -> V_21 |= V_22 ;
break;
case V_142 :
V_134 = F_58 ( & args [ 0 ] ) ;
if ( ! V_134 ) {
V_19 = - V_9 ;
break;
}
V_19 = F_59 ( V_134 , 0 , & V_1 -> V_59 ) ;
F_8 ( V_134 ) ;
if ( V_19 < 0 ) {
F_5 ( L_43
L_44 ) ;
goto V_143;
}
F_6 ( L_45
L_46 , V_1 -> V_59 ) ;
V_1 -> V_21 |= V_42 ;
break;
case V_144 :
V_19 = F_60 ( args , & V_137 ) ;
if ( V_19 )
goto V_143;
if ( V_137 != 1 ) {
F_5 ( L_47 , V_137 ) ;
V_19 = - V_20 ;
goto V_143;
}
F_6 ( L_48
L_49 ) ;
V_1 -> V_21 |= V_27 ;
break;
default:
break;
}
}
V_143:
F_8 ( V_132 ) ;
return ( ! V_19 ) ? V_131 : V_19 ;
}
static T_2 F_61 ( struct V_2 * V_3 , char * V_145 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_146 = 0 ;
V_146 = sprintf ( V_145 + V_146 , L_50 , V_1 -> V_55 ) ;
V_146 += sprintf ( V_145 + V_146 , L_51 ,
V_1 -> V_28 , V_1 -> V_59 ,
( V_1 -> V_21 & V_27 ) ?
L_52 : L_53 ) ;
return V_146 ;
}
static T_5 F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_147 = V_1 -> V_30 ;
struct V_17 * V_79 = V_147 -> V_31 -> V_32 ;
unsigned long long V_37 ;
if ( F_14 ( V_79 -> V_33 ) )
V_37 = F_17 ( V_79 ) ;
else
V_37 = V_1 -> V_59 ;
return F_18 ( V_37 - V_3 -> V_39 . V_65 ,
V_3 -> V_39 . V_65 ) ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_148 , * V_16 = V_1 -> V_30 ;
struct V_17 * V_17 ;
int V_19 , V_18 = V_23 | V_24 | V_25 | V_26 ;
char V_102 [ V_149 ] ;
if ( ! V_16 ) {
F_5 ( L_54 ) ;
return - V_108 ;
}
V_17 = V_16 -> V_31 -> V_32 ;
if ( F_14 ( V_17 -> V_33 ) ) {
F_5 ( L_55
L_56 ) ;
return - V_150 ;
}
if ( V_1 -> V_21 & V_27 )
V_18 &= ~ V_26 ;
snprintf ( V_102 , V_149 , L_57 ,
V_1 -> V_28 ) ;
V_148 = F_11 ( V_102 , V_18 , 0600 ) ;
if ( F_12 ( V_148 ) ) {
F_5 ( L_11 , V_102 ) ;
V_19 = F_13 ( V_148 ) ;
return V_19 ;
}
V_1 -> V_105 = V_148 ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
unsigned char * V_102 ;
int V_151 = V_152 * V_3 -> V_39 . V_65 ;
int V_19 ;
if ( ! V_3 -> V_39 . V_111 ) {
F_5 ( L_58 ) ;
return - V_108 ;
}
V_102 = F_65 ( V_151 ) ;
if ( ! V_102 ) {
F_5 ( L_36 ) ;
return - V_9 ;
}
F_6 ( L_59 ,
( unsigned long long ) ( V_3 -> V_153 -> V_154 ( V_3 ) + 1 ) *
V_3 -> V_106 ) ;
memset ( V_102 , 0xff , V_151 ) ;
V_19 = F_40 ( V_3 , 0 , V_3 -> V_153 -> V_154 ( V_3 ) + 1 ,
V_102 , V_151 ) ;
F_66 ( V_102 ) ;
return V_19 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 -> V_105 )
return;
F_21 ( V_1 -> V_105 , NULL ) ;
V_1 -> V_105 = NULL ;
}
static T_4
F_68 ( struct V_62 * V_63 )
{
return F_69 ( V_63 , & V_155 ) ;
}
static int T_8 F_70 ( void )
{
return F_71 ( & V_156 ) ;
}
static void T_9 F_72 ( void )
{
F_73 ( & V_156 ) ;
}
