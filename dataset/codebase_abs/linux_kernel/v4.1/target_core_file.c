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
static void F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_30 ) {
F_21 ( V_1 -> V_30 , NULL ) ;
V_1 -> V_30 = NULL ;
}
F_8 ( V_1 ) ;
}
static int F_23 ( struct V_64 * V_65 , struct V_66 * V_66 ,
int V_67 )
{
struct V_2 * V_68 = V_65 -> V_68 ;
struct V_1 * V_3 = F_1 ( V_68 ) ;
struct V_16 * V_69 = V_3 -> V_70 ;
T_2 V_71 = ( V_65 -> V_72 * V_68 -> V_73 ) ;
unsigned char * V_74 ;
T_1 V_75 ;
int V_76 , V_19 = 1 ;
V_75 = ( V_65 -> V_77 / V_68 -> V_39 . V_78 ) *
V_68 -> V_73 ;
if ( ! V_67 ) {
V_66 -> V_79 = F_4 ( V_75 , V_8 ) ;
if ( ! V_66 -> V_79 ) {
F_5 ( L_23 ) ;
return - V_9 ;
}
V_74 = V_66 -> V_79 ;
V_66 -> V_80 = 1 ;
V_66 -> V_81 = F_4 ( sizeof( struct V_82 ) ,
V_8 ) ;
if ( ! V_66 -> V_81 ) {
F_5 ( L_24 ) ;
F_8 ( V_66 -> V_79 ) ;
return - V_9 ;
}
F_24 ( V_66 -> V_81 , V_66 -> V_80 ) ;
F_25 ( V_66 -> V_81 , V_74 , V_75 ) ;
}
if ( V_67 ) {
V_76 = F_26 ( V_69 , V_66 -> V_79 , V_75 , V_71 ) ;
if ( V_76 < 0 || V_75 != V_76 ) {
F_5 ( L_25
L_26 , V_76 ) ;
V_19 = - V_20 ;
}
} else {
V_76 = F_27 ( V_69 , V_71 , V_66 -> V_79 , V_75 ) ;
if ( V_76 < 0 ) {
F_5 ( L_27
L_26 , V_76 ) ;
V_19 = - V_20 ;
}
}
if ( V_67 || V_19 < 0 ) {
F_8 ( V_66 -> V_81 ) ;
F_8 ( V_66 -> V_79 ) ;
}
return V_19 ;
}
static int F_28 ( struct V_64 * V_65 , struct V_82 * V_83 ,
T_1 V_84 , int V_67 )
{
struct V_2 * V_68 = V_65 -> V_68 ;
struct V_1 * V_3 = F_1 ( V_68 ) ;
struct V_16 * V_85 = V_3 -> V_30 ;
struct V_82 * V_86 ;
struct V_87 V_88 ;
struct V_89 * V_90 ;
T_3 V_91 = 0 ;
T_2 V_71 = ( V_65 -> V_72 * V_68 -> V_39 . V_78 ) ;
int V_19 = 0 , V_92 ;
V_90 = F_29 ( V_84 , sizeof( struct V_89 ) , V_8 ) ;
if ( ! V_90 ) {
F_5 ( L_28 ) ;
return - V_9 ;
}
F_30 (sgl, sg, sgl_nents, i) {
V_90 [ V_92 ] . V_93 = F_31 ( V_86 ) ;
V_90 [ V_92 ] . V_94 = V_86 -> V_95 ;
V_90 [ V_92 ] . V_96 = V_86 -> V_97 ;
V_91 += V_86 -> V_95 ;
}
F_32 ( & V_88 , V_98 , V_90 , V_84 , V_91 ) ;
if ( V_67 )
V_19 = F_33 ( V_85 , & V_88 , & V_71 ) ;
else
V_19 = F_34 ( V_85 , & V_88 , & V_71 ) ;
F_8 ( V_90 ) ;
if ( V_67 ) {
if ( V_19 < 0 || V_19 != V_65 -> V_77 ) {
F_5 ( L_29 , V_99 , V_19 ) ;
return ( V_19 < 0 ? V_19 : - V_20 ) ;
}
} else {
if ( F_14 ( F_35 ( V_85 ) -> V_33 ) ) {
if ( V_19 < 0 || V_19 != V_65 -> V_77 ) {
F_5 ( L_30
L_31 , V_99 , V_19 ,
V_65 -> V_77 ) ;
return ( V_19 < 0 ? V_19 : - V_20 ) ;
}
} else {
if ( V_19 < 0 ) {
F_5 ( L_32 ,
V_99 , V_19 ) ;
return V_19 ;
}
}
}
return 1 ;
}
static T_4
F_36 ( struct V_64 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_68 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_100 = ( V_65 -> V_101 [ 1 ] & 0x2 ) ;
T_2 V_102 , V_103 ;
int V_19 ;
if ( V_100 )
F_37 ( V_65 , V_104 ) ;
if ( V_65 -> V_72 == 0 && V_65 -> V_77 == 0 ) {
V_102 = 0 ;
V_103 = V_105 ;
} else {
V_102 = V_65 -> V_72 * V_3 -> V_39 . V_78 ;
if ( V_65 -> V_77 )
V_103 = V_102 + V_65 -> V_77 - 1 ;
else
V_103 = V_105 ;
}
V_19 = F_38 ( V_1 -> V_30 , V_102 , V_103 , 1 ) ;
if ( V_19 != 0 )
F_5 ( L_33 , V_19 ) ;
if ( V_100 )
return 0 ;
if ( V_19 )
F_37 ( V_65 , V_106 ) ;
else
F_37 ( V_65 , V_104 ) ;
return 0 ;
}
static T_4
F_39 ( struct V_64 * V_65 )
{
struct V_2 * V_68 = V_65 -> V_68 ;
struct V_1 * V_1 = F_1 ( V_68 ) ;
T_2 V_71 = V_65 -> V_72 * V_68 -> V_39 . V_78 ;
T_5 V_107 = F_40 ( V_65 ) ;
struct V_87 V_88 ;
struct V_89 * V_90 ;
unsigned int V_91 = 0 , V_92 ;
T_3 V_19 ;
if ( ! V_107 ) {
F_37 ( V_65 , V_104 ) ;
return 0 ;
}
if ( V_65 -> V_108 ) {
F_5 ( L_34
L_35 ) ;
return V_109 ;
}
if ( V_65 -> V_110 > 1 ||
V_65 -> V_111 [ 0 ] . V_95 != V_65 -> V_68 -> V_39 . V_78 ) {
F_5 ( L_36
L_37 ,
V_65 -> V_110 ,
V_65 -> V_111 [ 0 ] . V_95 ,
V_65 -> V_68 -> V_39 . V_78 ) ;
return V_112 ;
}
V_90 = F_29 ( V_107 , sizeof( struct V_89 ) , V_8 ) ;
if ( ! V_90 )
return V_109 ;
for ( V_92 = 0 ; V_92 < V_107 ; V_92 ++ ) {
V_90 [ V_92 ] . V_93 = F_31 ( & V_65 -> V_111 [ 0 ] ) ;
V_90 [ V_92 ] . V_94 = V_65 -> V_111 [ 0 ] . V_95 ;
V_90 [ V_92 ] . V_96 = V_65 -> V_111 [ 0 ] . V_97 ;
V_91 += V_68 -> V_39 . V_78 ;
}
F_32 ( & V_88 , V_98 , V_90 , V_107 , V_91 ) ;
V_19 = F_33 ( V_1 -> V_30 , & V_88 , & V_71 ) ;
F_8 ( V_90 ) ;
if ( V_19 < 0 || V_19 != V_91 ) {
F_5 ( L_38 , V_19 ) ;
return V_109 ;
}
F_37 ( V_65 , V_104 ) ;
return 0 ;
}
static int
F_41 ( struct V_2 * V_68 , T_5 V_113 , T_5 V_107 ,
void * V_74 , T_6 V_114 )
{
struct V_1 * V_1 = F_1 ( V_68 ) ;
struct V_16 * V_69 = V_1 -> V_70 ;
T_5 V_73 , V_115 ;
T_2 V_71 = V_113 * V_68 -> V_73 ;
if ( ! V_69 ) {
F_5 ( L_39 ) ;
return - V_116 ;
}
V_73 = V_107 * V_68 -> V_73 ;
for ( V_115 = 0 ; V_115 < V_73 ; ) {
T_5 V_91 = F_42 ( T_5 , V_114 , V_73 - V_115 ) ;
T_3 V_19 = F_26 ( V_69 , V_74 , V_91 , V_71 + V_115 ) ;
if ( V_19 != V_91 ) {
F_5 ( L_40 , V_19 ) ;
return V_19 < 0 ? V_19 : - V_116 ;
}
V_115 += V_19 ;
}
return 0 ;
}
static int
F_43 ( struct V_64 * V_65 , T_5 V_113 , T_5 V_107 )
{
void * V_74 ;
int V_76 ;
V_74 = ( void * ) F_44 ( V_8 ) ;
if ( ! V_74 ) {
F_5 ( L_41 ) ;
return - V_9 ;
}
memset ( V_74 , 0xff , V_117 ) ;
V_76 = F_41 ( V_65 -> V_68 , V_113 , V_107 , V_74 , V_117 ) ;
F_45 ( ( unsigned long ) V_74 ) ;
return V_76 ;
}
static T_4
F_46 ( struct V_64 * V_65 , void * V_118 , T_5 V_113 , T_5 V_107 )
{
struct V_16 * V_16 = V_118 ;
struct V_17 * V_17 = V_16 -> V_31 -> V_32 ;
int V_19 ;
if ( V_65 -> V_68 -> V_39 . V_119 ) {
V_19 = F_43 ( V_65 , V_113 , V_107 ) ;
if ( V_19 )
return V_109 ;
}
if ( F_14 ( V_17 -> V_33 ) ) {
struct V_120 * V_121 = V_17 -> V_36 ;
V_19 = F_47 ( V_121 , V_113 ,
V_107 , V_8 , 0 ) ;
if ( V_19 < 0 ) {
F_48 ( L_42 ,
V_19 ) ;
return V_109 ;
}
} else {
struct V_2 * V_68 = V_65 -> V_68 ;
T_2 V_71 = V_113 * V_68 -> V_39 . V_78 ;
unsigned int V_91 = V_107 * V_68 -> V_39 . V_78 ;
int V_122 = V_123 | V_124 ;
if ( ! V_16 -> V_125 -> V_126 )
return V_109 ;
V_19 = V_16 -> V_125 -> V_126 ( V_16 , V_122 , V_71 , V_91 ) ;
if ( V_19 < 0 ) {
F_48 ( L_43 , V_19 ) ;
return V_109 ;
}
}
return 0 ;
}
static T_4
F_49 ( struct V_64 * V_65 )
{
struct V_2 * V_68 = V_65 -> V_68 ;
struct V_1 * V_1 = F_1 ( V_68 ) ;
struct V_16 * V_16 = V_1 -> V_30 ;
T_5 V_113 = V_65 -> V_72 ;
T_5 V_107 = F_40 ( V_65 ) ;
T_4 V_19 ;
if ( ! V_107 ) {
F_37 ( V_65 , V_104 ) ;
return 0 ;
}
V_19 = F_46 ( V_65 , V_16 , V_113 , V_107 ) ;
if ( V_19 )
return V_19 ;
F_37 ( V_65 , V_127 ) ;
return 0 ;
}
static T_4
F_50 ( struct V_64 * V_65 )
{
struct V_16 * V_16 = F_1 ( V_65 -> V_68 ) -> V_30 ;
return F_51 ( V_65 , F_46 , V_16 ) ;
}
static T_4
F_52 ( struct V_64 * V_65 , struct V_82 * V_83 , T_1 V_84 ,
enum V_128 V_129 )
{
struct V_2 * V_3 = V_65 -> V_68 ;
struct V_66 V_66 ;
T_4 V_76 ;
int V_19 = 0 ;
if ( V_65 -> V_77 > V_54 ) {
F_5 ( L_44
L_45 ,
V_65 -> V_77 , V_54 ) ;
return V_109 ;
}
if ( V_129 == V_130 ) {
memset ( & V_66 , 0 , sizeof( struct V_66 ) ) ;
if ( V_65 -> V_131 && V_3 -> V_39 . V_119 ) {
V_19 = F_23 ( V_65 , & V_66 , false ) ;
if ( V_19 < 0 )
return V_109 ;
}
V_19 = F_28 ( V_65 , V_83 , V_84 , 0 ) ;
if ( V_19 > 0 && V_65 -> V_131 && V_3 -> V_39 . V_119 ) {
T_1 V_132 = V_65 -> V_77 / V_3 -> V_39 . V_78 ;
V_76 = F_53 ( V_65 , V_65 -> V_72 , V_132 ,
0 , V_66 . V_81 , 0 ) ;
if ( V_76 ) {
F_8 ( V_66 . V_81 ) ;
F_8 ( V_66 . V_79 ) ;
return V_76 ;
}
F_8 ( V_66 . V_81 ) ;
F_8 ( V_66 . V_79 ) ;
}
} else {
memset ( & V_66 , 0 , sizeof( struct V_66 ) ) ;
if ( V_65 -> V_131 && V_3 -> V_39 . V_119 ) {
T_1 V_132 = V_65 -> V_77 / V_3 -> V_39 . V_78 ;
V_19 = F_23 ( V_65 , & V_66 , false ) ;
if ( V_19 < 0 )
return V_109 ;
V_76 = F_54 ( V_65 , V_65 -> V_72 , V_132 ,
0 , V_66 . V_81 , 0 ) ;
if ( V_76 ) {
F_8 ( V_66 . V_81 ) ;
F_8 ( V_66 . V_79 ) ;
return V_76 ;
}
}
V_19 = F_28 ( V_65 , V_83 , V_84 , 1 ) ;
if ( V_19 > 0 &&
V_3 -> V_39 . V_133 > 0 &&
( V_65 -> V_134 & V_135 ) ) {
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_102 = V_65 -> V_72 *
V_3 -> V_39 . V_78 ;
T_2 V_103 ;
if ( V_65 -> V_77 )
V_103 = V_102 + V_65 -> V_77 - 1 ;
else
V_103 = V_105 ;
F_38 ( V_1 -> V_30 , V_102 , V_103 , 1 ) ;
}
if ( V_19 > 0 && V_65 -> V_131 && V_3 -> V_39 . V_119 ) {
V_19 = F_23 ( V_65 , & V_66 , true ) ;
if ( V_19 < 0 )
return V_109 ;
}
}
if ( V_19 < 0 ) {
F_8 ( V_66 . V_81 ) ;
F_8 ( V_66 . V_79 ) ;
return V_109 ;
}
if ( V_19 )
F_37 ( V_65 , V_104 ) ;
return 0 ;
}
static T_3 F_55 ( struct V_2 * V_3 ,
const char * V_136 , T_3 V_137 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_138 , * V_139 , * V_140 , * V_141 ;
T_7 args [ V_142 ] ;
int V_19 = 0 , V_143 , V_144 ;
V_141 = F_56 ( V_136 , V_8 ) ;
if ( ! V_141 )
return - V_9 ;
V_138 = V_141 ;
while ( ( V_139 = F_57 ( & V_141 , L_46 ) ) != NULL ) {
if ( ! * V_139 )
continue;
V_144 = F_58 ( V_139 , V_145 , args ) ;
switch ( V_144 ) {
case V_146 :
if ( F_59 ( V_1 -> V_28 , & args [ 0 ] ,
V_147 ) == 0 ) {
V_19 = - V_20 ;
break;
}
F_6 ( L_47 ,
V_1 -> V_28 ) ;
V_1 -> V_21 |= V_22 ;
break;
case V_148 :
V_140 = F_60 ( & args [ 0 ] ) ;
if ( ! V_140 ) {
V_19 = - V_9 ;
break;
}
V_19 = F_61 ( V_140 , 0 , & V_1 -> V_63 ) ;
F_8 ( V_140 ) ;
if ( V_19 < 0 ) {
F_5 ( L_48
L_49 ) ;
goto V_149;
}
F_6 ( L_50
L_51 , V_1 -> V_63 ) ;
V_1 -> V_21 |= V_50 ;
break;
case V_150 :
V_19 = F_62 ( args , & V_143 ) ;
if ( V_19 )
goto V_149;
if ( V_143 != 1 ) {
F_5 ( L_52 , V_143 ) ;
V_19 = - V_20 ;
goto V_149;
}
F_6 ( L_53
L_54 ) ;
V_1 -> V_21 |= V_27 ;
break;
default:
break;
}
}
V_149:
F_8 ( V_138 ) ;
return ( ! V_19 ) ? V_137 : V_19 ;
}
static T_3 F_63 ( struct V_2 * V_3 , char * V_151 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_152 = 0 ;
V_152 = sprintf ( V_151 + V_152 , L_55 , V_1 -> V_59 ) ;
V_152 += sprintf ( V_151 + V_152 , L_56 ,
V_1 -> V_28 , V_1 -> V_63 ,
( V_1 -> V_21 & V_27 ) ?
L_57 : L_58 ) ;
return V_152 ;
}
static T_5 F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_153 = V_1 -> V_30 ;
struct V_17 * V_92 = V_153 -> V_31 -> V_32 ;
unsigned long long V_37 ;
if ( F_14 ( V_92 -> V_33 ) )
V_37 = F_17 ( V_92 ) ;
else
V_37 = V_1 -> V_63 ;
return F_18 ( V_37 - V_3 -> V_39 . V_78 ,
V_3 -> V_39 . V_78 ) ;
}
static int F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_154 , * V_16 = V_1 -> V_30 ;
struct V_17 * V_17 ;
int V_19 , V_18 = V_23 | V_24 | V_25 | V_26 ;
char V_74 [ V_155 ] ;
if ( ! V_16 ) {
F_5 ( L_59 ) ;
return - V_116 ;
}
V_17 = V_16 -> V_31 -> V_32 ;
if ( F_14 ( V_17 -> V_33 ) ) {
F_5 ( L_60
L_61 ) ;
return - V_156 ;
}
if ( V_1 -> V_21 & V_27 )
V_18 &= ~ V_26 ;
snprintf ( V_74 , V_155 , L_62 ,
V_1 -> V_28 ) ;
V_154 = F_11 ( V_74 , V_18 , 0600 ) ;
if ( F_12 ( V_154 ) ) {
F_5 ( L_11 , V_74 ) ;
V_19 = F_13 ( V_154 ) ;
return V_19 ;
}
V_1 -> V_70 = V_154 ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 )
{
unsigned char * V_74 ;
int V_157 = V_158 * V_3 -> V_39 . V_78 ;
int V_19 ;
if ( ! V_3 -> V_39 . V_119 ) {
F_5 ( L_63 ) ;
return - V_116 ;
}
V_74 = F_67 ( V_157 ) ;
if ( ! V_74 ) {
F_5 ( L_41 ) ;
return - V_9 ;
}
F_6 ( L_64 ,
( unsigned long long ) ( V_3 -> V_159 -> V_160 ( V_3 ) + 1 ) *
V_3 -> V_73 ) ;
memset ( V_74 , 0xff , V_157 ) ;
V_19 = F_41 ( V_3 , 0 , V_3 -> V_159 -> V_160 ( V_3 ) + 1 ,
V_74 , V_157 ) ;
F_68 ( V_74 ) ;
return V_19 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 -> V_70 )
return;
F_21 ( V_1 -> V_70 , NULL ) ;
V_1 -> V_70 = NULL ;
}
static T_4
F_70 ( struct V_64 * V_65 )
{
return F_71 ( V_65 , & V_161 ) ;
}
static int T_8 F_72 ( void )
{
struct V_162 * V_163 = & V_164 . V_165 ;
F_73 ( & V_164 ) ;
V_163 -> V_166 . V_167 = V_168 ;
return F_74 ( & V_164 ) ;
}
static void T_9 F_75 ( void )
{
F_76 ( & V_164 ) ;
}
