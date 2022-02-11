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
static int F_23 ( struct V_64 * V_65 , struct V_66 * V_67 ,
T_1 V_68 , int V_69 )
{
struct V_2 * V_70 = V_65 -> V_70 ;
struct V_1 * V_3 = F_1 ( V_70 ) ;
struct V_16 * V_71 = V_3 -> V_30 ;
struct V_66 * V_72 ;
struct V_73 * V_74 ;
T_2 V_75 ;
T_3 V_76 = ( V_65 -> V_77 * V_70 -> V_39 . V_78 ) ;
int V_19 = 0 , V_79 ;
V_74 = F_4 ( sizeof( struct V_73 ) * V_68 , V_8 ) ;
if ( ! V_74 ) {
F_5 ( L_23 ) ;
return - V_9 ;
}
F_24 (sgl, sg, sgl_nents, i) {
V_74 [ V_79 ] . V_80 = V_72 -> V_81 ;
V_74 [ V_79 ] . V_82 = F_25 ( F_26 ( V_72 ) ) + V_72 -> V_83 ;
}
V_75 = F_27 () ;
F_28 ( F_29 () ) ;
if ( V_69 )
V_19 = F_30 ( V_71 , & V_74 [ 0 ] , V_68 , & V_76 ) ;
else
V_19 = F_31 ( V_71 , & V_74 [ 0 ] , V_68 , & V_76 ) ;
F_28 ( V_75 ) ;
F_24 (sgl, sg, sgl_nents, i)
F_32 ( F_26 ( V_72 ) ) ;
F_8 ( V_74 ) ;
if ( V_69 ) {
if ( V_19 < 0 || V_19 != V_65 -> V_84 ) {
F_5 ( L_24 , V_85 , V_19 ) ;
return ( V_19 < 0 ? V_19 : - V_20 ) ;
}
} else {
if ( F_14 ( F_33 ( V_71 ) -> V_33 ) ) {
if ( V_19 < 0 || V_19 != V_65 -> V_84 ) {
F_5 ( L_25
L_26 , V_85 , V_19 ,
V_65 -> V_84 ) ;
return ( V_19 < 0 ? V_19 : - V_20 ) ;
}
} else {
if ( V_19 < 0 ) {
F_5 ( L_27 ,
V_85 , V_19 ) ;
return V_19 ;
}
}
}
return 1 ;
}
static T_4
F_34 ( struct V_64 * V_65 )
{
struct V_2 * V_3 = V_65 -> V_70 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_86 = ( V_65 -> V_87 [ 1 ] & 0x2 ) ;
T_3 V_88 , V_89 ;
int V_19 ;
if ( V_86 )
F_35 ( V_65 , V_90 ) ;
if ( V_65 -> V_77 == 0 && V_65 -> V_84 == 0 ) {
V_88 = 0 ;
V_89 = V_91 ;
} else {
V_88 = V_65 -> V_77 * V_3 -> V_39 . V_78 ;
if ( V_65 -> V_84 )
V_89 = V_88 + V_65 -> V_84 ;
else
V_89 = V_91 ;
}
V_19 = F_36 ( V_1 -> V_30 , V_88 , V_89 , 1 ) ;
if ( V_19 != 0 )
F_5 ( L_28 , V_19 ) ;
if ( V_86 )
return 0 ;
if ( V_19 )
F_35 ( V_65 , V_92 ) ;
else
F_35 ( V_65 , V_90 ) ;
return 0 ;
}
static unsigned char *
F_37 ( struct V_64 * V_65 , struct V_66 * V_72 ,
unsigned int V_93 )
{
struct V_2 * V_70 = V_65 -> V_70 ;
unsigned int V_78 = V_70 -> V_39 . V_78 ;
unsigned int V_79 = 0 , V_89 ;
unsigned char * V_94 , * V_95 , * V_96 ;
V_94 = F_4 ( F_38 (unsigned int, len, PAGE_SIZE) , V_8 ) ;
if ( ! V_94 ) {
F_5 ( L_29 ) ;
return NULL ;
}
V_96 = F_25 ( F_26 ( V_72 ) ) + V_72 -> V_83 ;
if ( ! V_96 ) {
F_5 ( L_30 ) ;
F_8 ( V_94 ) ;
return NULL ;
}
V_95 = V_94 ;
V_89 = F_38 (unsigned int, len, PAGE_SIZE) ;
while ( V_79 < V_89 ) {
memcpy ( V_95 , V_96 , V_78 ) ;
V_79 += V_78 ;
V_95 += V_78 ;
}
F_32 ( F_26 ( V_72 ) ) ;
return V_94 ;
}
static T_4
F_39 ( struct V_64 * V_65 )
{
struct V_2 * V_70 = V_65 -> V_70 ;
struct V_1 * V_1 = F_1 ( V_70 ) ;
struct V_16 * V_97 = V_1 -> V_30 ;
struct V_66 * V_72 ;
struct V_73 * V_74 ;
T_2 V_75 ;
T_5 V_98 = F_40 ( V_65 ) ;
T_3 V_76 = V_65 -> V_77 * V_70 -> V_39 . V_78 ;
unsigned int V_93 , V_99 , V_100 ;
int V_79 , V_101 ;
unsigned char * V_94 ;
if ( ! V_98 ) {
F_35 ( V_65 , V_90 ) ;
return 0 ;
}
V_72 = & V_65 -> V_102 [ 0 ] ;
if ( V_65 -> V_103 > 1 ||
V_72 -> V_81 != V_65 -> V_70 -> V_39 . V_78 ) {
F_5 ( L_31
L_32 , V_65 -> V_103 , V_72 -> V_81 ,
V_65 -> V_70 -> V_39 . V_78 ) ;
return V_104 ;
}
V_93 = V_99 = V_98 * V_70 -> V_39 . V_78 ;
V_100 = F_41 ( V_93 , V_105 ) ;
V_94 = F_37 ( V_65 , V_72 , V_93 ) ;
if ( ! V_94 )
return V_106 ;
V_74 = F_42 ( sizeof( struct V_73 ) * V_100 ) ;
if ( ! V_74 ) {
F_5 ( L_33 ) ;
F_8 ( V_94 ) ;
return V_106 ;
}
for ( V_79 = 0 ; V_79 < V_100 ; V_79 ++ ) {
V_74 [ V_79 ] . V_82 = V_94 ;
V_74 [ V_79 ] . V_80 = F_38 (unsigned int, len_tmp, PAGE_SIZE) ;
V_99 -= V_74 [ V_79 ] . V_80 ;
}
V_75 = F_27 () ;
F_28 ( F_29 () ) ;
V_101 = F_30 ( V_97 , & V_74 [ 0 ] , V_100 , & V_76 ) ;
F_28 ( V_75 ) ;
F_43 ( V_74 ) ;
F_8 ( V_94 ) ;
if ( V_101 < 0 || V_101 != V_93 ) {
F_5 ( L_34 , V_101 ) ;
return V_106 ;
}
F_35 ( V_65 , V_90 ) ;
return 0 ;
}
static T_4
F_44 ( struct V_64 * V_65 , void * V_107 , T_5 V_108 , T_5 V_98 )
{
struct V_16 * V_16 = V_107 ;
struct V_17 * V_17 = V_16 -> V_31 -> V_32 ;
int V_19 ;
if ( F_14 ( V_17 -> V_33 ) ) {
struct V_109 * V_110 = V_17 -> V_36 ;
V_19 = F_45 ( V_110 , V_108 ,
V_98 , V_8 , 0 ) ;
if ( V_19 < 0 ) {
F_46 ( L_35 ,
V_19 ) ;
return V_106 ;
}
} else {
struct V_2 * V_70 = V_65 -> V_70 ;
T_3 V_76 = V_108 * V_70 -> V_39 . V_78 ;
unsigned int V_93 = V_98 * V_70 -> V_39 . V_78 ;
int V_111 = V_112 | V_113 ;
if ( ! V_16 -> V_114 -> V_115 )
return V_106 ;
V_19 = V_16 -> V_114 -> V_115 ( V_16 , V_111 , V_76 , V_93 ) ;
if ( V_19 < 0 ) {
F_46 ( L_36 , V_19 ) ;
return V_106 ;
}
}
return 0 ;
}
static T_4
F_47 ( struct V_64 * V_65 )
{
struct V_2 * V_70 = V_65 -> V_70 ;
struct V_1 * V_1 = F_1 ( V_70 ) ;
struct V_16 * V_16 = V_1 -> V_30 ;
T_5 V_108 = V_65 -> V_77 ;
T_5 V_98 = F_40 ( V_65 ) ;
int V_19 ;
if ( ! V_98 ) {
F_35 ( V_65 , V_90 ) ;
return 0 ;
}
V_19 = F_44 ( V_65 , V_16 , V_108 , V_98 ) ;
if ( V_19 )
return V_19 ;
F_35 ( V_65 , V_116 ) ;
return 0 ;
}
static T_4
F_48 ( struct V_64 * V_65 )
{
struct V_16 * V_16 = F_1 ( V_65 -> V_70 ) -> V_30 ;
return F_49 ( V_65 , F_44 , V_16 ) ;
}
static T_4
F_50 ( struct V_64 * V_65 , struct V_66 * V_67 , T_1 V_68 ,
enum V_117 V_118 )
{
struct V_2 * V_3 = V_65 -> V_70 ;
int V_19 = 0 ;
if ( V_118 == V_119 ) {
V_19 = F_23 ( V_65 , V_67 , V_68 , 0 ) ;
} else {
V_19 = F_23 ( V_65 , V_67 , V_68 , 1 ) ;
if ( V_19 > 0 &&
V_3 -> V_39 . V_120 > 0 &&
( V_65 -> V_121 & V_122 ) ) {
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_88 = V_65 -> V_77 *
V_3 -> V_39 . V_78 ;
T_3 V_89 = V_88 + V_65 -> V_84 ;
F_36 ( V_1 -> V_30 , V_88 , V_89 , 1 ) ;
}
}
if ( V_19 < 0 )
return V_106 ;
if ( V_19 )
F_35 ( V_65 , V_90 ) ;
return 0 ;
}
static T_6 F_51 ( struct V_2 * V_3 ,
const char * V_123 , T_6 V_124 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
char * V_125 , * V_126 , * V_127 , * V_128 ;
T_7 args [ V_129 ] ;
int V_19 = 0 , V_130 , V_131 ;
V_128 = F_52 ( V_123 , V_8 ) ;
if ( ! V_128 )
return - V_9 ;
V_125 = V_128 ;
while ( ( V_126 = F_53 ( & V_128 , L_37 ) ) != NULL ) {
if ( ! * V_126 )
continue;
V_131 = F_54 ( V_126 , V_132 , args ) ;
switch ( V_131 ) {
case V_133 :
if ( F_55 ( V_1 -> V_28 , & args [ 0 ] ,
V_134 ) == 0 ) {
V_19 = - V_20 ;
break;
}
F_6 ( L_38 ,
V_1 -> V_28 ) ;
V_1 -> V_21 |= V_22 ;
break;
case V_135 :
V_127 = F_56 ( & args [ 0 ] ) ;
if ( ! V_127 ) {
V_19 = - V_9 ;
break;
}
V_19 = F_57 ( V_127 , 0 , & V_1 -> V_63 ) ;
F_8 ( V_127 ) ;
if ( V_19 < 0 ) {
F_5 ( L_39
L_40 ) ;
goto V_136;
}
F_6 ( L_41
L_42 , V_1 -> V_63 ) ;
V_1 -> V_21 |= V_50 ;
break;
case V_137 :
F_58 ( args , & V_130 ) ;
if ( V_130 != 1 ) {
F_5 ( L_43 , V_130 ) ;
V_19 = - V_20 ;
goto V_136;
}
F_6 ( L_44
L_45 ) ;
V_1 -> V_21 |= V_27 ;
break;
default:
break;
}
}
V_136:
F_8 ( V_125 ) ;
return ( ! V_19 ) ? V_124 : V_19 ;
}
static T_6 F_59 ( struct V_2 * V_3 , char * V_138 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_6 V_139 = 0 ;
V_139 = sprintf ( V_138 + V_139 , L_46 , V_1 -> V_59 ) ;
V_139 += sprintf ( V_138 + V_139 , L_47 ,
V_1 -> V_28 , V_1 -> V_63 ,
( V_1 -> V_21 & V_27 ) ?
L_48 : L_49 ) ;
return V_139 ;
}
static T_5 F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_16 * V_97 = V_1 -> V_30 ;
struct V_17 * V_79 = V_97 -> V_31 -> V_32 ;
unsigned long long V_37 ;
if ( F_14 ( V_79 -> V_33 ) )
V_37 = F_17 ( V_79 ) ;
else
V_37 = V_1 -> V_63 ;
return F_18 ( V_37 - V_3 -> V_39 . V_78 ,
V_3 -> V_39 . V_78 ) ;
}
static T_4
F_61 ( struct V_64 * V_65 )
{
return F_62 ( V_65 , & V_140 ) ;
}
static int T_8 F_63 ( void )
{
return F_64 ( & V_141 ) ;
}
static void T_9 F_65 ( void )
{
F_66 ( & V_141 ) ;
}
