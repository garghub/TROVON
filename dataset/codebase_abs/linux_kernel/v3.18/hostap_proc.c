static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( V_2 , L_1 ,
V_4 -> V_7 , V_4 -> V_8 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ )
F_2 ( V_2 , L_2 ,
V_4 -> V_10 [ V_6 ] , V_4 -> V_11 [ V_6 ] ) ;
F_2 ( V_2 , L_3 , V_4 -> V_12 ) ;
F_2 ( V_2 , L_4 , V_4 -> V_13 ) ;
F_2 ( V_2 , L_5 , V_4 -> V_14 ) ;
F_2 ( V_2 , L_6 , V_4 -> V_15 ) ;
F_2 ( V_2 , L_7 , V_4 -> V_16 ) ;
F_2 ( V_2 , L_8 , V_4 -> V_17 ) ;
for ( V_6 = 0 ; V_6 < V_18 ; V_6 ++ ) {
if ( V_4 -> V_19 . V_20 [ V_6 ] &&
V_4 -> V_19 . V_20 [ V_6 ] -> V_21 ) {
F_2 ( V_2 , L_9 , V_6 ,
V_4 -> V_19 . V_20 [ V_6 ] -> V_21 -> V_22 ) ;
}
}
F_2 ( V_2 , L_10 , V_4 -> V_23 ) ;
F_2 ( V_2 , L_11 , V_4 -> V_24 -> V_25 == V_26 ) ;
F_2 ( V_2 , L_12 , V_4 -> V_27 ) ;
F_2 ( V_2 , L_13 , V_4 -> V_28 ) ;
return 0 ;
}
static int F_3 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
return F_4 ( V_30 , F_1 , F_5 ( V_29 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = & V_4 -> V_33 ;
F_2 ( V_2 , L_14 , V_32 -> V_34 ) ;
F_2 ( V_2 , L_15 , V_32 -> V_35 ) ;
F_2 ( V_2 , L_16 , V_32 -> V_36 ) ;
F_2 ( V_2 , L_17 , V_32 -> V_37 ) ;
F_2 ( V_2 , L_18 , V_32 -> V_38 ) ;
F_2 ( V_2 , L_19 ,
V_32 -> V_39 ) ;
F_2 ( V_2 , L_20 , V_32 -> V_40 ) ;
F_2 ( V_2 , L_21 ,
V_32 -> V_41 ) ;
F_2 ( V_2 , L_22 ,
V_32 -> V_42 ) ;
F_2 ( V_2 , L_23 , V_32 -> V_43 ) ;
F_2 ( V_2 , L_24 , V_32 -> V_44 ) ;
F_2 ( V_2 , L_25 , V_32 -> V_45 ) ;
F_2 ( V_2 , L_26 , V_32 -> V_46 ) ;
F_2 ( V_2 , L_27 , V_32 -> V_47 ) ;
F_2 ( V_2 , L_28 , V_32 -> V_48 ) ;
F_2 ( V_2 , L_29 , V_32 -> V_49 ) ;
F_2 ( V_2 , L_30 , V_32 -> V_50 ) ;
F_2 ( V_2 , L_31 , V_32 -> V_51 ) ;
F_2 ( V_2 , L_32 ,
V_32 -> V_52 ) ;
F_2 ( V_2 , L_33 ,
V_32 -> V_53 ) ;
F_2 ( V_2 , L_34 ,
V_32 -> V_54 ) ;
return 0 ;
}
static int F_7 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
return F_4 ( V_30 , F_6 , F_5 ( V_29 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_55 * V_56 = V_3 ;
struct V_57 * V_58 ;
V_58 = F_9 ( V_56 , struct V_57 , V_59 ) ;
if ( V_58 -> type == V_60 )
F_2 ( V_2 , L_35 ,
V_58 -> V_61 -> V_22 , V_58 -> V_62 . V_63 . V_64 ) ;
return 0 ;
}
static void * F_10 ( struct V_1 * V_2 , T_2 * V_65 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_11 ( & V_4 -> V_66 ) ;
return F_12 ( & V_4 -> V_67 , * V_65 ) ;
}
static void * F_13 ( struct V_1 * V_2 , void * V_3 , T_2 * V_65 )
{
T_1 * V_4 = V_2 -> V_5 ;
return F_14 ( V_3 , & V_4 -> V_67 , V_65 ) ;
}
static void F_15 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_16 ( & V_4 -> V_66 ) ;
}
static int F_17 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
int V_68 = F_18 ( V_30 , & V_69 ) ;
if ( V_68 == 0 ) {
struct V_1 * V_2 = V_30 -> V_70 ;
V_2 -> V_5 = F_5 ( V_29 ) ;
}
return V_68 ;
}
static int F_19 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
struct V_55 * V_56 = V_3 ;
struct V_71 * V_72 ;
if ( V_56 == & V_4 -> V_73 ) {
F_2 ( V_2 , L_36
L_37 ) ;
return 0 ;
}
V_72 = F_9 ( V_56 , struct V_71 , V_59 ) ;
F_2 ( V_2 , L_38 ,
V_72 -> V_74 , V_72 -> V_75 ,
V_72 -> V_76 , V_72 -> V_77 ) ;
F_2 ( V_2 , L_39 , ( int ) V_72 -> V_78 , V_72 -> V_79 ) ;
F_20 ( V_2 , '\t' ) ;
F_2 ( V_2 , L_40 , ( int ) V_72 -> V_78 , V_72 -> V_79 ) ;
F_20 ( V_2 , '\t' ) ;
F_2 ( V_2 , L_40 , ( int ) V_72 -> V_80 , V_72 -> V_81 ) ;
F_20 ( V_2 , '\n' ) ;
return 0 ;
}
static void * F_21 ( struct V_1 * V_2 , T_2 * V_65 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_22 ( & V_4 -> V_82 ) ;
return F_23 ( & V_4 -> V_73 , * V_65 ) ;
}
static void * F_24 ( struct V_1 * V_2 , void * V_3 , T_2 * V_65 )
{
T_1 * V_4 = V_2 -> V_5 ;
return F_14 ( V_3 , & V_4 -> V_73 , V_65 ) ;
}
static void F_25 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_26 ( & V_4 -> V_82 ) ;
}
static int F_27 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
int V_68 = F_18 ( V_30 , & V_83 ) ;
if ( V_68 == 0 ) {
struct V_1 * V_2 = V_30 -> V_70 ;
V_2 -> V_5 = F_5 ( V_29 ) ;
}
return V_68 ;
}
static int F_28 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( V_2 , L_41 , V_4 -> V_19 . V_84 ) ;
for ( V_6 = 0 ; V_6 < V_18 ; V_6 ++ ) {
if ( V_4 -> V_19 . V_20 [ V_6 ] &&
V_4 -> V_19 . V_20 [ V_6 ] -> V_21 &&
V_4 -> V_19 . V_20 [ V_6 ] -> V_21 -> V_85 ) {
V_4 -> V_19 . V_20 [ V_6 ] -> V_21 -> V_85 (
V_2 , V_4 -> V_19 . V_20 [ V_6 ] -> V_86 ) ;
}
}
return 0 ;
}
static int F_29 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
return F_4 ( V_30 , F_28 , F_5 ( V_29 ) ) ;
}
static T_3 F_30 ( struct V_30 * V_30 , char T_4 * V_87 ,
T_5 V_76 , T_2 * V_65 )
{
T_1 * V_4 = F_5 ( F_31 ( V_30 ) ) ;
T_5 V_88 ;
if ( V_4 -> V_89 == NULL || * V_65 >= V_90 )
return 0 ;
V_88 = * V_65 ;
if ( V_76 > V_90 - V_88 )
V_76 = V_90 - V_88 ;
if ( F_32 ( V_87 , V_4 -> V_89 + V_88 , V_76 ) != 0 )
return - V_91 ;
* V_65 += V_76 ;
return V_76 ;
}
static T_3 F_33 ( struct V_30 * V_30 , char T_4 * V_87 ,
T_5 V_92 , T_2 * V_65 )
{
return 0 ;
}
static int F_34 ( char * V_93 , char * * V_94 , T_6 V_88 ,
int V_76 , int * V_95 , void * V_96 )
{
T_1 * V_4 = ( T_1 * ) V_96 ;
int V_97 = V_4 -> V_98 ;
int V_99 , V_100 , V_101 , V_102 ;
if ( V_88 + V_76 > V_103 * 4 ) {
* V_95 = 1 ;
if ( V_88 >= V_103 * 4 )
return 0 ;
V_76 = V_103 * 4 - V_88 ;
}
V_102 = 0 ;
V_99 = ( V_103 - V_97 ) * 4 ;
V_100 = V_76 ;
if ( V_88 < V_99 ) {
V_101 = V_99 - V_88 ;
if ( V_101 > V_76 )
V_101 = V_76 ;
memcpy ( V_93 , ( ( V_104 * ) & V_4 -> V_105 [ V_97 ] ) + V_88 , V_101 ) ;
V_100 -= V_101 ;
if ( V_100 > 0 )
memcpy ( & V_93 [ V_101 ] , V_4 -> V_105 , V_100 ) ;
} else {
memcpy ( V_93 , ( ( V_104 * ) V_4 -> V_105 ) + ( V_88 - V_99 ) ,
V_100 ) ;
}
* V_94 = V_93 ;
return V_76 ;
}
static int F_35 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
unsigned long V_106 ;
int V_6 , V_107 ;
struct V_108 * V_109 ;
V_104 * V_110 ;
if ( V_3 == V_111 ) {
F_2 ( V_2 ,
L_42 ) ;
return 0 ;
}
V_106 = ( unsigned long ) V_3 - 2 ;
V_109 = & V_4 -> V_112 [ V_106 ] ;
F_2 ( V_2 , L_43 ,
F_36 ( V_109 -> V_113 ) ,
( V_114 ) F_36 ( V_109 -> V_115 ) ,
( V_114 ) F_36 ( V_109 -> V_116 ) ,
F_36 ( V_109 -> V_117 ) ,
F_36 ( V_109 -> V_118 ) ,
F_36 ( V_109 -> V_119 ) ,
V_109 -> V_74 ,
F_36 ( V_109 -> V_120 ) ) ;
V_110 = V_109 -> V_121 ;
for ( V_6 = 0 ; V_6 < sizeof( V_109 -> V_121 ) ; V_6 ++ ) {
if ( V_110 [ V_6 ] == 0 )
break;
F_2 ( V_2 , L_44 , V_110 [ V_6 ] ) ;
}
F_20 ( V_2 , ' ' ) ;
V_110 = V_109 -> V_79 ;
V_107 = F_36 ( V_109 -> V_78 ) ;
if ( V_107 > 32 )
V_107 = 32 ;
for ( V_6 = 0 ; V_6 < V_107 ; V_6 ++ ) {
unsigned char V_122 = V_110 [ V_6 ] ;
if ( V_122 >= 32 && V_122 < 127 )
F_20 ( V_2 , V_122 ) ;
else
F_2 ( V_2 , L_44 , V_122 ) ;
}
F_20 ( V_2 , '\n' ) ;
return 0 ;
}
static void * F_37 ( struct V_1 * V_2 , T_2 * V_65 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_22 ( & V_4 -> V_82 ) ;
if ( * V_65 > V_4 -> V_123 )
return NULL ;
return ( void * ) ( unsigned long ) ( * V_65 + 1 ) ;
}
static void * F_38 ( struct V_1 * V_2 , void * V_3 , T_2 * V_65 )
{
T_1 * V_4 = V_2 -> V_5 ;
++ * V_65 ;
if ( * V_65 > V_4 -> V_123 )
return NULL ;
return ( void * ) ( unsigned long ) ( * V_65 + 1 ) ;
}
static void F_39 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_26 ( & V_4 -> V_82 ) ;
}
static int F_40 ( struct V_29 * V_29 , struct V_30 * V_30 )
{
int V_68 = F_18 ( V_30 , & V_124 ) ;
if ( V_68 == 0 ) {
struct V_1 * V_2 = V_30 -> V_70 ;
V_2 -> V_5 = F_5 ( V_29 ) ;
}
return V_68 ;
}
void F_41 ( T_1 * V_4 )
{
V_4 -> V_125 = NULL ;
if ( V_126 == NULL ) {
F_42 ( V_127 L_45 ,
V_4 -> V_61 -> V_22 ) ;
return;
}
V_4 -> V_125 = F_43 ( V_4 -> V_128 -> V_22 , V_126 ) ;
if ( V_4 -> V_125 == NULL ) {
F_42 ( V_129 L_46 ,
V_4 -> V_128 -> V_22 ) ;
return;
}
#ifndef F_44
F_45 ( L_47 , 0 , V_4 -> V_125 ,
& V_130 , V_4 ) ;
#endif
F_45 ( L_48 , 0 , V_4 -> V_125 ,
& V_131 , V_4 ) ;
F_45 ( L_49 , 0 , V_4 -> V_125 ,
& V_132 , V_4 ) ;
F_45 ( L_50 , 0 , V_4 -> V_125 ,
& V_133 , V_4 ) ;
F_45 ( L_51 , 0 , V_4 -> V_125 ,
V_4 -> V_24 -> V_134 ? : & V_135 ,
V_4 ) ;
F_45 ( L_52 , 0 , V_4 -> V_125 ,
& V_136 , V_4 ) ;
F_45 ( L_53 , 0 , V_4 -> V_125 ,
& V_137 , V_4 ) ;
#ifdef F_46
F_45 ( L_54 , 0 , V_4 -> V_125 ,
& V_138 , V_4 ) ;
#endif
#ifndef F_47
F_45 ( L_55 , 0 , V_4 -> V_125 ,
& V_139 , V_4 ) ;
#endif
}
void F_48 ( T_1 * V_4 )
{
F_49 ( V_4 -> V_125 ) ;
}
