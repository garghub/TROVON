static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
V_2 -> V_6 = 0 ;
V_2 -> V_7 = V_4 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = F_2 ( V_5 ) ;
V_2 -> V_10 = F_3 ( F_4 ( V_3 ) ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 ,
unsigned long V_11 , unsigned int V_12 )
{
unsigned int V_13 = F_6 (unsigned int, len, LEN_ON_PAGE(pa)) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = F_2 ( V_13 ) ;
V_2 -> V_10 = F_3 ( V_11 ) ;
return V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
unsigned char * V_14 , unsigned int V_12 ,
bool V_15 )
{
unsigned long V_11 = F_4 ( V_14 ) ;
int V_16 , V_17 , V_18 = V_12 ;
if ( ! F_8 ( V_11 , V_19 ) ) {
F_9 ( L_1 ,
V_15 ? L_2 : L_3 , V_11 , V_19 ) ;
return - V_20 ;
}
if ( V_12 % V_21 ) {
F_9 ( L_4 ,
V_15 ? L_2 : L_3 , V_12 , V_21 ) ;
if ( V_15 )
return - V_20 ;
V_12 = F_10 ( V_12 , V_21 ) ;
}
if ( V_12 <= F_11 ( V_11 ) ) {
V_17 = F_5 ( V_2 , V_11 , V_12 ) ;
F_12 ( V_17 < V_12 ) ;
return 0 ;
}
for ( V_16 = 0 ; V_16 < V_22 && V_12 > 0 ; V_16 ++ ) {
V_17 = F_5 ( & V_3 [ V_16 ] , V_11 , V_12 ) ;
V_14 += V_17 ;
V_12 -= V_17 ;
V_11 = F_4 ( V_14 ) ;
}
if ( V_12 > 0 ) {
F_9 ( L_5 ,
V_18 , V_15 ? L_2 : L_3 , V_12 ) ;
if ( V_15 )
return - V_23 ;
V_18 -= V_12 ;
}
F_1 ( V_2 , V_3 , V_16 , V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
T_1 V_28 = V_25 -> V_28 , V_29 = F_14 () ;
T_1 V_30 = F_15 ( V_28 , V_31 ) ;
while ( ! ( F_16 ( V_27 -> V_6 ) & V_32 ) ) {
F_17 () ;
V_29 = F_14 () ;
if ( F_18 ( V_29 , V_30 ) )
break;
}
F_19 () ;
if ( ! ( V_27 -> V_6 & V_32 ) ) {
F_20 ( V_27 , L_6 ,
( long ) F_21 ( V_29 , V_28 ) ) ;
return - V_33 ;
}
if ( V_27 -> V_6 & V_34 ) {
F_20 ( V_27 , L_7 ) ;
return - V_35 ;
}
if ( V_27 -> V_6 & V_36 ) {
F_20 ( V_27 , L_8 ) ;
return - V_35 ;
}
if ( V_27 -> V_37 ) {
F_20 ( V_27 , L_9 ) ;
return - V_35 ;
}
switch ( V_27 -> V_38 ) {
case V_39 :
break;
case V_40 :
break;
case V_41 :
F_20 ( V_27 , L_10 ) ;
return - V_20 ;
case V_42 :
F_20 ( V_27 , L_11 ) ;
return - V_20 ;
case V_43 :
return - V_44 ;
case V_45 :
F_20 ( V_27 , L_12 ) ;
return - V_46 ;
case V_47 :
F_20 ( V_27 , L_13 ) ;
return - V_20 ;
case V_48 :
F_20 ( V_27 , L_14 ) ;
return - V_20 ;
case V_49 :
F_20 ( V_27 , L_15 ) ;
return - V_20 ;
case V_50 :
F_22 ( V_27 , L_16 ) ;
return - V_20 ;
case V_51 :
F_20 ( V_27 , L_17 ) ;
return - V_20 ;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
F_22 ( V_27 , L_18 ) ;
return - V_35 ;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
F_22 ( V_27 , L_19 ) ;
return - V_35 ;
case V_68 :
F_20 ( V_27 , L_20 ) ;
return - V_35 ;
case V_69 :
F_20 ( V_27 , L_21 ) ;
return - V_20 ;
case V_70 :
F_20 ( V_27 , L_22 ) ;
return - V_20 ;
case V_71 :
F_20 ( V_27 , L_23 ) ;
return - V_20 ;
case V_72 :
F_20 ( V_27 , L_24 ) ;
return - V_20 ;
case V_73 :
F_20 ( V_27 , L_25 ) ;
return - V_35 ;
case V_74 :
F_20 ( V_27 , L_26 ) ;
return - V_35 ;
case V_75 :
F_20 ( V_27 , L_27 ) ;
return - V_35 ;
case V_76 :
F_20 ( V_27 , L_28 ) ;
return - V_35 ;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
F_22 ( V_27 , L_29 ) ;
return - V_35 ;
case V_81 :
F_22 ( V_27 , L_30 ) ;
return - V_35 ;
case V_82 :
F_20 ( V_27 , L_31 ) ;
return - V_35 ;
case V_83 :
F_20 ( V_27 , L_32 ) ;
return - V_35 ;
case V_84 :
F_20 ( V_27 , L_33 ) ;
return - V_35 ;
default:
F_20 ( V_27 , L_34 , V_27 -> V_38 ) ;
return - V_35 ;
}
if ( V_27 -> V_85 & V_86 ) {
F_20 ( V_27 , L_35 ) ;
return - V_35 ;
}
if ( V_27 -> V_85 & V_87 ) {
F_20 ( V_27 , L_36 ) ;
return - V_35 ;
}
if ( ! ( V_27 -> V_85 & V_88 ) ) {
F_20 ( V_27 , L_37 ) ;
return - V_35 ;
}
F_23 ( L_38 ,
F_24 ( V_27 -> V_7 ) ,
( unsigned long ) F_21 ( V_29 , V_28 ) ) ;
return 0 ;
}
static int F_25 ( const unsigned char * V_15 , unsigned int V_89 ,
unsigned char * V_90 , unsigned int * V_91 ,
void * V_92 , int V_93 )
{
struct V_94 * V_95 ;
struct V_26 * V_27 ;
struct V_24 * V_25 ;
int V_17 ;
T_2 V_96 ;
T_3 V_97 ;
unsigned int V_98 = * V_91 ;
V_25 = F_26 ( V_92 , V_99 ) ;
* V_91 = 0 ;
if ( ! V_100 ) {
F_27 ( L_39 ) ;
return - V_101 ;
}
V_95 = & V_25 -> V_95 ;
V_27 = & V_95 -> V_27 ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_17 = F_7 ( & V_95 -> V_102 , V_25 -> V_103 ,
( unsigned char * ) V_15 , V_89 , true ) ;
if ( V_17 )
return V_17 ;
V_17 = F_7 ( & V_95 -> V_104 , V_25 -> V_105 ,
V_90 , V_98 , false ) ;
if ( V_17 )
return V_17 ;
V_97 = 0 ;
V_97 = F_28 ( V_97 , V_106 , V_100 ) ;
V_97 = F_28 ( V_97 , V_107 , 0 ) ;
V_97 = F_28 ( V_97 , V_108 , V_93 ) ;
V_96 = F_4 ( V_27 ) & V_109 ;
V_96 |= V_110 ;
V_95 -> V_96 = F_3 ( V_96 ) ;
V_25 -> V_28 = F_14 () ;
V_17 = F_29 ( F_2 ( V_97 ) , V_95 ) ;
F_23 ( L_40 , V_17 ,
( unsigned int ) V_97 ,
( unsigned int ) F_24 ( V_95 -> V_97 ) ) ;
switch ( V_17 ) {
case V_111 :
V_17 = F_13 ( V_25 , V_27 ) ;
break;
case V_112 :
F_23 ( L_41 ) ;
V_17 = - V_113 ;
break;
case V_114 :
F_27 ( L_42 ) ;
V_17 = - V_35 ;
break;
default:
F_27 ( L_43 , V_17 ) ;
V_17 = - V_35 ;
break;
}
if ( ! V_17 )
* V_91 = F_24 ( V_27 -> V_7 ) ;
return V_17 ;
}
static int F_30 ( const unsigned char * V_15 , unsigned int V_89 ,
unsigned char * V_90 , unsigned int * V_91 ,
void * V_25 )
{
return F_25 ( V_15 , V_89 , V_90 , V_91 ,
V_25 , V_115 ) ;
}
static int F_31 ( const unsigned char * V_15 , unsigned int V_89 ,
unsigned char * V_90 , unsigned int * V_91 ,
void * V_25 )
{
return F_25 ( V_15 , V_89 , V_90 , V_91 ,
V_25 , V_116 ) ;
}
static int T_4 F_32 ( struct V_117 * V_118 )
{
struct V_119 * V_120 ;
struct V_121 * V_122 , * V_123 ;
unsigned int V_124 , V_125 ;
int V_126 ;
V_126 = F_33 ( V_118 ) ;
if ( V_126 < 0 ) {
F_34 ( L_44 ) ;
return - V_20 ;
}
V_122 = F_35 ( V_118 , L_45 , NULL ) ;
if ( ! V_122 ) {
F_34 ( L_46 ) ;
return - V_20 ;
}
V_124 = F_24 ( * ( unsigned int * ) V_122 -> V_127 ) ;
V_123 = F_35 ( V_118 , L_47 , NULL ) ;
if ( ! V_123 ) {
F_34 ( L_48 ) ;
return - V_20 ;
}
V_125 = F_24 ( * ( unsigned int * ) V_123 -> V_127 ) ;
V_120 = F_36 ( sizeof( * V_120 ) , V_128 ) ;
if ( ! V_120 )
return - V_129 ;
V_120 -> V_126 = V_126 ;
V_120 -> V_124 = V_124 ;
V_120 -> V_125 = V_125 ;
F_37 ( & V_120 -> V_130 ) ;
F_38 ( & V_120 -> V_130 , & V_131 ) ;
F_39 ( L_49 , V_126 , V_124 , V_125 ) ;
if ( ! V_100 )
V_100 = V_124 ;
else if ( V_100 != V_124 )
F_34 ( L_50 ,
V_126 , V_124 , V_100 ) ;
return 0 ;
}
static int F_40 ( struct V_132 * V_133 )
{
return F_41 ( V_133 , & V_134 ) ;
}
static T_4 int F_42 ( void )
{
struct V_117 * V_118 ;
int V_17 ;
F_43 ( V_99 % V_135 ) ;
F_43 ( V_135 % V_136 ) ;
F_43 ( V_137 % V_136 ) ;
F_43 ( V_138 % V_19 ) ;
F_43 ( V_19 % V_139 ) ;
F_43 ( V_139 % V_21 ) ;
F_44 (dn, NULL, L_51 )
F_32 ( V_118 ) ;
if ( ! V_100 )
return - V_101 ;
V_17 = F_45 ( & V_140 ) ;
if ( V_17 ) {
struct V_119 * V_120 , * V_141 ;
F_46 (coproc, n, &nx842_coprocs, list) {
F_47 ( & V_120 -> V_130 ) ;
F_48 ( V_120 ) ;
}
return V_17 ;
}
return 0 ;
}
static void T_5 F_49 ( void )
{
struct V_119 * V_120 , * V_141 ;
F_50 ( & V_140 ) ;
F_46 (coproc, n, &nx842_coprocs, list) {
F_47 ( & V_120 -> V_130 ) ;
F_48 ( V_120 ) ;
}
}
