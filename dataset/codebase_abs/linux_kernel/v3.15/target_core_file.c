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
struct V_71 * V_72 ;
T_2 V_73 = ( V_65 -> V_74 * V_68 -> V_75 ) ;
unsigned char * V_76 ;
T_1 V_77 , V_78 , V_79 ;
int V_80 , V_19 = 1 , V_81 ;
V_77 = ( V_65 -> V_82 / V_68 -> V_39 . V_83 ) *
V_68 -> V_75 ;
if ( ! V_67 ) {
V_66 -> V_84 = F_24 ( V_77 ) ;
if ( ! V_66 -> V_84 ) {
F_5 ( L_23 ) ;
return - V_9 ;
}
V_76 = V_66 -> V_84 ;
V_66 -> V_85 = V_65 -> V_86 ;
V_66 -> V_87 = F_4 ( sizeof( struct V_71 ) *
V_66 -> V_85 , V_8 ) ;
if ( ! V_66 -> V_87 ) {
F_5 ( L_24 ) ;
F_25 ( V_66 -> V_84 ) ;
return - V_9 ;
}
V_79 = V_77 ;
F_26 (fd_prot->prot_sg, sg, fd_prot->prot_sg_nents, i) {
V_78 = F_27 ( T_1 , V_88 , V_79 ) ;
F_28 ( V_72 , V_76 , V_78 ) ;
V_79 -= V_78 ;
V_76 += V_78 ;
}
}
if ( V_67 ) {
V_80 = F_29 ( V_69 , V_66 -> V_84 , V_77 , V_73 ) ;
if ( V_80 < 0 || V_77 != V_80 ) {
F_5 ( L_25
L_26 , V_80 ) ;
V_19 = - V_20 ;
}
} else {
V_80 = F_30 ( V_69 , V_73 , V_66 -> V_84 , V_77 ) ;
if ( V_80 < 0 ) {
F_5 ( L_27
L_26 , V_80 ) ;
V_19 = - V_20 ;
}
}
if ( V_67 || V_19 < 0 ) {
F_8 ( V_66 -> V_87 ) ;
F_25 ( V_66 -> V_84 ) ;
}
return V_19 ;
}
static int F_31 ( struct V_64 * V_65 , struct V_71 * V_89 ,
T_1 V_90 , int V_67 )
{
struct V_2 * V_68 = V_65 -> V_68 ;
struct V_1 * V_3 = F_1 ( V_68 ) ;
struct V_16 * V_91 = V_3 -> V_30 ;
struct V_71 * V_72 ;
struct V_92 * V_93 ;
T_3 V_94 ;
T_2 V_73 = ( V_65 -> V_74 * V_68 -> V_39 . V_83 ) ;
int V_19 = 0 , V_81 ;
V_93 = F_4 ( sizeof( struct V_92 ) * V_90 , V_8 ) ;
if ( ! V_93 ) {
F_5 ( L_28 ) ;
return - V_9 ;
}
F_26 (sgl, sg, sgl_nents, i) {
V_93 [ V_81 ] . V_95 = V_72 -> V_96 ;
V_93 [ V_81 ] . V_97 = F_32 ( F_33 ( V_72 ) ) + V_72 -> V_98 ;
}
V_94 = F_34 () ;
F_35 ( F_36 () ) ;
if ( V_67 )
V_19 = F_37 ( V_91 , & V_93 [ 0 ] , V_90 , & V_73 ) ;
else
V_19 = F_38 ( V_91 , & V_93 [ 0 ] , V_90 , & V_73 ) ;
F_35 ( V_94 ) ;
F_26 (sgl, sg, sgl_nents, i)
F_39 ( F_33 ( V_72 ) ) ;
F_8 ( V_93 ) ;
if ( V_67 ) {
if ( V_19 < 0 || V_19 != V_65 -> V_82 ) {
F_5 ( L_29 , V_99 , V_19 ) ;
return ( V_19 < 0 ? V_19 : - V_20 ) ;
}
} else {
if ( F_14 ( F_40 ( V_91 ) -> V_33 ) ) {
if ( V_19 < 0 || V_19 != V_65 -> V_82 ) {
F_5 ( L_30
L_31 , V_99 , V_19 ,
V_65 -> V_82 ) ;
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
F_41 ( struct V_64 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_68 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_100 = ( V_65 -> V_101 [ 1 ] & 0x2 ) ;
T_2 V_102 , V_103 ;
int V_19 ;
if ( V_100 )
F_42 ( V_65 , V_104 ) ;
if ( V_65 -> V_74 == 0 && V_65 -> V_82 == 0 ) {
V_102 = 0 ;
V_103 = V_105 ;
} else {
V_102 = V_65 -> V_74 * V_3 -> V_39 . V_83 ;
if ( V_65 -> V_82 )
V_103 = V_102 + V_65 -> V_82 ;
else
V_103 = V_105 ;
}
V_19 = F_43 ( V_1 -> V_30 , V_102 , V_103 , 1 ) ;
if ( V_19 != 0 )
F_5 ( L_33 , V_19 ) ;
if ( V_100 )
return 0 ;
if ( V_19 )
F_42 ( V_65 , V_106 ) ;
else
F_42 ( V_65 , V_104 ) ;
return 0 ;
}
static unsigned char *
F_44 ( struct V_64 * V_65 , struct V_71 * V_72 ,
unsigned int V_78 )
{
struct V_2 * V_68 = V_65 -> V_68 ;
unsigned int V_83 = V_68 -> V_39 . V_83 ;
unsigned int V_81 = 0 , V_103 ;
unsigned char * V_76 , * V_107 , * V_108 ;
V_76 = F_4 ( F_27 (unsigned int, len, PAGE_SIZE) , V_8 ) ;
if ( ! V_76 ) {
F_5 ( L_34 ) ;
return NULL ;
}
V_108 = F_32 ( F_33 ( V_72 ) ) + V_72 -> V_98 ;
if ( ! V_108 ) {
F_5 ( L_35 ) ;
F_8 ( V_76 ) ;
return NULL ;
}
V_107 = V_76 ;
V_103 = F_27 (unsigned int, len, PAGE_SIZE) ;
while ( V_81 < V_103 ) {
memcpy ( V_107 , V_108 , V_83 ) ;
V_81 += V_83 ;
V_107 += V_83 ;
}
F_39 ( F_33 ( V_72 ) ) ;
return V_76 ;
}
static T_4
F_45 ( struct V_64 * V_65 )
{
struct V_2 * V_68 = V_65 -> V_68 ;
struct V_1 * V_1 = F_1 ( V_68 ) ;
struct V_16 * V_109 = V_1 -> V_30 ;
struct V_71 * V_72 ;
struct V_92 * V_93 ;
T_3 V_94 ;
T_5 V_110 = F_46 ( V_65 ) ;
T_2 V_73 = V_65 -> V_74 * V_68 -> V_39 . V_83 ;
unsigned int V_78 , V_111 , V_112 ;
int V_81 , V_80 ;
unsigned char * V_76 ;
if ( ! V_110 ) {
F_42 ( V_65 , V_104 ) ;
return 0 ;
}
V_72 = & V_65 -> V_113 [ 0 ] ;
if ( V_65 -> V_114 > 1 ||
V_72 -> V_96 != V_65 -> V_68 -> V_39 . V_83 ) {
F_5 ( L_36
L_37 , V_65 -> V_114 , V_72 -> V_96 ,
V_65 -> V_68 -> V_39 . V_83 ) ;
return V_115 ;
}
V_78 = V_111 = V_110 * V_68 -> V_39 . V_83 ;
V_112 = F_47 ( V_78 , V_88 ) ;
V_76 = F_44 ( V_65 , V_72 , V_78 ) ;
if ( ! V_76 )
return V_116 ;
V_93 = F_24 ( sizeof( struct V_92 ) * V_112 ) ;
if ( ! V_93 ) {
F_5 ( L_38 ) ;
F_8 ( V_76 ) ;
return V_116 ;
}
for ( V_81 = 0 ; V_81 < V_112 ; V_81 ++ ) {
V_93 [ V_81 ] . V_97 = V_76 ;
V_93 [ V_81 ] . V_95 = F_27 (unsigned int, len_tmp, PAGE_SIZE) ;
V_111 -= V_93 [ V_81 ] . V_95 ;
}
V_94 = F_34 () ;
F_35 ( F_36 () ) ;
V_80 = F_37 ( V_109 , & V_93 [ 0 ] , V_112 , & V_73 ) ;
F_35 ( V_94 ) ;
F_25 ( V_93 ) ;
F_8 ( V_76 ) ;
if ( V_80 < 0 || V_80 != V_78 ) {
F_5 ( L_39 , V_80 ) ;
return V_116 ;
}
F_42 ( V_65 , V_104 ) ;
return 0 ;
}
static T_4
F_48 ( struct V_64 * V_65 , void * V_117 , T_5 V_118 , T_5 V_110 )
{
struct V_16 * V_16 = V_117 ;
struct V_17 * V_17 = V_16 -> V_31 -> V_32 ;
int V_19 ;
if ( F_14 ( V_17 -> V_33 ) ) {
struct V_119 * V_120 = V_17 -> V_36 ;
V_19 = F_49 ( V_120 , V_118 ,
V_110 , V_8 , 0 ) ;
if ( V_19 < 0 ) {
F_50 ( L_40 ,
V_19 ) ;
return V_116 ;
}
} else {
struct V_2 * V_68 = V_65 -> V_68 ;
T_2 V_73 = V_118 * V_68 -> V_39 . V_83 ;
unsigned int V_78 = V_110 * V_68 -> V_39 . V_83 ;
int V_121 = V_122 | V_123 ;
if ( ! V_16 -> V_124 -> V_125 )
return V_116 ;
V_19 = V_16 -> V_124 -> V_125 ( V_16 , V_121 , V_73 , V_78 ) ;
if ( V_19 < 0 ) {
F_50 ( L_41 , V_19 ) ;
return V_116 ;
}
}
return 0 ;
}
static T_4
F_51 ( struct V_64 * V_65 )
{
struct V_2 * V_68 = V_65 -> V_68 ;
struct V_1 * V_1 = F_1 ( V_68 ) ;
struct V_16 * V_16 = V_1 -> V_30 ;
T_5 V_118 = V_65 -> V_74 ;
T_5 V_110 = F_46 ( V_65 ) ;
int V_19 ;
if ( ! V_110 ) {
F_42 ( V_65 , V_104 ) ;
return 0 ;
}
V_19 = F_48 ( V_65 , V_16 , V_118 , V_110 ) ;
if ( V_19 )
return V_19 ;
F_42 ( V_65 , V_126 ) ;
return 0 ;
}
static T_4
F_52 ( struct V_64 * V_65 )
{
struct V_16 * V_16 = F_1 ( V_65 -> V_68 ) -> V_30 ;
return F_53 ( V_65 , F_48 , V_16 ) ;
}
static T_4
F_54 ( struct V_64 * V_65 , struct V_71 * V_89 , T_1 V_90 ,
enum V_127 V_128 )
{
struct V_2 * V_3 = V_65 -> V_68 ;
struct V_66 V_66 ;
T_4 V_80 ;
int V_19 = 0 ;
if ( V_128 == V_129 ) {
memset ( & V_66 , 0 , sizeof( struct V_66 ) ) ;
if ( V_65 -> V_130 ) {
V_19 = F_23 ( V_65 , & V_66 , false ) ;
if ( V_19 < 0 )
return V_116 ;
}
V_19 = F_31 ( V_65 , V_89 , V_90 , 0 ) ;
if ( V_19 > 0 && V_65 -> V_130 ) {
T_1 V_131 = V_65 -> V_82 / V_3 -> V_39 . V_83 ;
V_80 = F_55 ( V_65 , V_65 -> V_74 , V_131 ,
0 , V_66 . V_87 , 0 ) ;
if ( V_80 ) {
F_8 ( V_66 . V_87 ) ;
F_25 ( V_66 . V_84 ) ;
return V_80 ;
}
F_8 ( V_66 . V_87 ) ;
F_25 ( V_66 . V_84 ) ;
}
} else {
memset ( & V_66 , 0 , sizeof( struct V_66 ) ) ;
if ( V_65 -> V_130 ) {
T_1 V_131 = V_65 -> V_82 / V_3 -> V_39 . V_83 ;
V_19 = F_23 ( V_65 , & V_66 , false ) ;
if ( V_19 < 0 )
return V_116 ;
V_80 = F_56 ( V_65 , V_65 -> V_74 , V_131 ,
0 , V_66 . V_87 , 0 ) ;
if ( V_80 ) {
F_8 ( V_66 . V_87 ) ;
F_25 ( V_66 . V_84 ) ;
return V_80 ;
}
}
V_19 = F_31 ( V_65 , V_89 , V_90 , 1 ) ;
if ( V_19 > 0 &&
V_3 -> V_39 . V_132 > 0 &&
( V_65 -> V_133 & V_134 ) ) {
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_2 V_102 = V_65 -> V_74 *
V_3 -> V_39 . V_83 ;
T_2 V_103 = V_102 + V_65 -> V_82 ;
F_43 ( V_1 -> V_30 , V_102 , V_103 , 1 ) ;
}
if ( V_19 > 0 && V_65 -> V_130 ) {
V_19 = F_23 ( V_65 , & V_66 , true ) ;
if ( V_19 < 0 )
return V_116 ;
}
}
if ( V_19 < 0 ) {
F_8 ( V_66 . V_87 ) ;
F_25 ( V_66 . V_84 ) ;
return V_116 ;
}
if ( V_19 )
F_42 ( V_65 , V_104 ) ;
return 0 ;
}
static T_6 F_57 ( struct V_2 * V_3 ,
const char * V_135 , T_6 V_136 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_137 , * V_138 , * V_139 , * V_140 ;
T_7 args [ V_141 ] ;
int V_19 = 0 , V_142 , V_143 ;
V_140 = F_58 ( V_135 , V_8 ) ;
if ( ! V_140 )
return - V_9 ;
V_137 = V_140 ;
while ( ( V_138 = F_59 ( & V_140 , L_42 ) ) != NULL ) {
if ( ! * V_138 )
continue;
V_143 = F_60 ( V_138 , V_144 , args ) ;
switch ( V_143 ) {
case V_145 :
if ( F_61 ( V_1 -> V_28 , & args [ 0 ] ,
V_146 ) == 0 ) {
V_19 = - V_20 ;
break;
}
F_6 ( L_43 ,
V_1 -> V_28 ) ;
V_1 -> V_21 |= V_22 ;
break;
case V_147 :
V_139 = F_62 ( & args [ 0 ] ) ;
if ( ! V_139 ) {
V_19 = - V_9 ;
break;
}
V_19 = F_63 ( V_139 , 0 , & V_1 -> V_63 ) ;
F_8 ( V_139 ) ;
if ( V_19 < 0 ) {
F_5 ( L_44
L_45 ) ;
goto V_148;
}
F_6 ( L_46
L_47 , V_1 -> V_63 ) ;
V_1 -> V_21 |= V_50 ;
break;
case V_149 :
F_64 ( args , & V_142 ) ;
if ( V_142 != 1 ) {
F_5 ( L_48 , V_142 ) ;
V_19 = - V_20 ;
goto V_148;
}
F_6 ( L_49
L_50 ) ;
V_1 -> V_21 |= V_27 ;
break;
default:
break;
}
}
V_148:
F_8 ( V_137 ) ;
return ( ! V_19 ) ? V_136 : V_19 ;
}
static T_6 F_65 ( struct V_2 * V_3 , char * V_150 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_6 V_151 = 0 ;
V_151 = sprintf ( V_150 + V_151 , L_51 , V_1 -> V_59 ) ;
V_151 += sprintf ( V_150 + V_151 , L_52 ,
V_1 -> V_28 , V_1 -> V_63 ,
( V_1 -> V_21 & V_27 ) ?
L_53 : L_54 ) ;
return V_151 ;
}
static T_5 F_66 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_109 = V_1 -> V_30 ;
struct V_17 * V_81 = V_109 -> V_31 -> V_32 ;
unsigned long long V_37 ;
if ( F_14 ( V_81 -> V_33 ) )
V_37 = F_17 ( V_81 ) ;
else
V_37 = V_1 -> V_63 ;
return F_18 ( V_37 - V_3 -> V_39 . V_83 ,
V_3 -> V_39 . V_83 ) ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_152 , * V_16 = V_1 -> V_30 ;
struct V_17 * V_17 ;
int V_19 , V_18 = V_23 | V_24 | V_25 | V_26 ;
char V_76 [ V_153 ] ;
if ( ! V_16 ) {
F_5 ( L_55 ) ;
return - V_154 ;
}
V_17 = V_16 -> V_31 -> V_32 ;
if ( F_14 ( V_17 -> V_33 ) ) {
F_5 ( L_56
L_57 ) ;
return - V_155 ;
}
if ( V_1 -> V_21 & V_27 )
V_18 &= ~ V_26 ;
snprintf ( V_76 , V_153 , L_58 ,
V_1 -> V_28 ) ;
V_152 = F_11 ( V_76 , V_18 , 0600 ) ;
if ( F_12 ( V_152 ) ) {
F_5 ( L_11 , V_76 ) ;
V_19 = F_13 ( V_152 ) ;
return V_19 ;
}
V_1 -> V_70 = V_152 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_69 = V_1 -> V_70 ;
T_5 V_75 , V_156 ;
unsigned char * V_76 ;
T_2 V_73 = 0 ;
int V_157 = V_158 * V_3 -> V_39 . V_83 ;
int V_80 , V_19 = 0 , V_79 , V_78 ;
if ( ! V_3 -> V_39 . V_159 ) {
F_5 ( L_59 ) ;
return - V_154 ;
}
if ( ! V_69 ) {
F_5 ( L_60 ) ;
return - V_154 ;
}
V_76 = F_24 ( V_157 ) ;
if ( ! V_76 ) {
F_5 ( L_61 ) ;
return - V_9 ;
}
V_75 = ( V_3 -> V_160 -> V_161 ( V_3 ) + 1 ) * V_3 -> V_75 ;
V_79 = V_75 ;
F_6 ( L_62 ,
( unsigned long long ) V_75 ) ;
memset ( V_76 , 0xff , V_157 ) ;
for ( V_156 = 0 ; V_156 < V_75 ; V_156 += V_157 ) {
V_78 = F_69 ( V_157 , V_79 ) ;
V_80 = F_29 ( V_69 , V_76 , V_78 , V_73 ) ;
if ( V_80 != V_78 ) {
F_5 ( L_63 , V_80 ) ;
V_19 = - V_154 ;
goto V_148;
}
V_73 += V_78 ;
V_79 -= V_78 ;
}
V_148:
F_25 ( V_76 ) ;
return V_19 ;
}
static void F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 -> V_70 )
return;
F_21 ( V_1 -> V_70 , NULL ) ;
V_1 -> V_70 = NULL ;
}
static T_4
F_71 ( struct V_64 * V_65 )
{
return F_72 ( V_65 , & V_162 ) ;
}
static int T_8 F_73 ( void )
{
return F_74 ( & V_163 ) ;
}
static void T_9 F_75 ( void )
{
F_76 ( & V_163 ) ;
}
