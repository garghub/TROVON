static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 -> V_7 -> V_8 ( V_4 , V_2 -> V_9 ) ;
}
static int F_2 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_12 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_13 = V_11 -> V_13 ;
if ( ! V_4 )
return V_14 ;
V_12 = F_3 ( V_4 -> V_15 + ( V_13 << V_16 ) ) ;
if ( ! V_12 )
return V_17 ;
F_4 ( V_12 ) ;
V_11 -> V_12 = V_12 ;
return 0 ;
}
static struct V_12 * * F_5 ( unsigned int V_18 )
{
const T_2 V_19 = V_18 * sizeof( struct V_12 * ) ;
if ( V_19 > V_20 )
return F_6 ( V_19 ) ;
return F_7 ( V_19 , V_21 ) ;
}
static void F_8 ( struct V_12 * * V_22 )
{
if ( F_9 ( V_22 ) )
F_10 ( V_22 ) ;
else
F_11 ( V_22 ) ;
}
static int F_12 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
unsigned long V_23 = V_2 -> V_24 - V_2 -> V_25 ;
struct V_26 * V_27 = V_2 -> V_9 ;
if ( ! V_4 )
return - V_28 ;
if ( V_23 != ( unsigned long ) V_4 -> V_6 -> V_29 )
return - V_30 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 |= V_34 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_6 -> V_7 -> V_35 ( V_4 , V_27 ) ;
return 0 ;
}
static void * F_13 ( struct V_3 * V_4 , T_2 * V_36 )
{
void * V_37 ;
unsigned int V_38 , V_39 , V_18 ;
* V_36 = F_14 ( * V_36 ) ;
V_18 = * V_36 >> V_16 ;
V_4 -> V_40 = F_5 ( V_18 ) ;
if ( ! V_4 -> V_40 )
return NULL ;
for ( V_38 = 0 ; V_38 < V_18 ; V_38 ++ ) {
V_4 -> V_40 [ V_38 ] = F_15 ( V_21 ) ;
if ( F_16 ( ! V_4 -> V_40 [ V_38 ] ) )
goto V_41;
F_17 ( V_4 -> V_40 [ V_38 ] , ( unsigned long ) V_4 ) ;
}
V_37 = F_18 ( V_4 -> V_40 , V_18 , V_42 , V_43 ) ;
if ( ! V_37 )
goto V_41;
memset ( V_37 , 0 , * V_36 ) ;
V_4 -> V_44 = V_18 ;
return V_37 ;
V_41:
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ )
F_19 ( V_4 -> V_40 [ V_39 ] ) ;
F_8 ( V_4 -> V_40 ) ;
return NULL ;
}
static struct V_3 * F_20 ( struct V_45 * V_6 )
{
struct V_3 * V_4 ;
if ( V_6 -> V_46 > V_47 / sizeof( T_2 * ) )
return NULL ;
V_4 = F_7 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_48 = F_21 ( V_6 -> V_46 * sizeof( T_2 * ) , V_21 ) ;
if ( ! V_4 -> V_48 )
goto V_49;
V_4 -> V_15 = F_13 ( V_4 , & V_6 -> V_29 ) ;
if ( ! V_4 -> V_15 )
goto V_49;
V_4 -> V_6 = V_6 ;
F_22 ( & V_4 -> V_6 -> V_50 ) ;
return V_4 ;
V_49:
F_11 ( V_4 -> V_48 ) ;
F_11 ( V_4 ) ;
return NULL ;
}
static void F_23 ( struct V_50 * V_50 )
{
struct V_45 * V_6 = F_24 ( V_50 , struct V_45 , V_50 ) ;
F_11 ( V_6 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_45 * V_6 = V_4 -> V_6 ;
unsigned int V_38 ;
if ( F_26 ( V_4 -> V_15 ) ) {
F_27 ( V_4 -> V_15 ) ;
for ( V_38 = 0 ; V_38 < V_4 -> V_44 ; V_38 ++ )
F_19 ( V_4 -> V_40 [ V_38 ] ) ;
F_8 ( V_4 -> V_40 ) ;
}
V_6 -> V_4 [ V_4 -> V_51 ] = NULL ;
F_11 ( V_4 -> V_48 ) ;
F_11 ( V_4 ) ;
F_28 ( & V_6 -> V_50 , F_23 ) ;
}
static void F_29 ( struct V_50 * V_50 )
{
struct V_3 * V_4 = F_24 ( V_50 , struct V_3 , V_50 ) ;
V_4 -> V_6 -> V_7 -> V_52 ( V_4 -> V_53 ) ;
F_25 ( V_4 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
return ( V_4 -> V_54 - V_4 -> V_55 ) ? 0 : 1 ;
}
int F_31 ( struct V_3 * V_4 )
{
T_2 V_56 = V_4 -> V_54 - V_4 -> V_55 ;
return ( V_56 >= V_4 -> V_6 -> V_46 ) ? 1 : 0 ;
}
static int F_32 ( struct V_3 * V_4 ,
void * V_57 ,
void * V_58 ,
T_2 V_59 )
{
if ( F_31 ( V_4 ) )
return 0 ;
return 1 ;
}
static void F_33 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
}
static void F_34 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
}
static struct V_53 * F_35 ( const char * V_60 ,
struct V_53 * V_61 ,
T_3 V_62 ,
struct V_3 * V_4 ,
int * V_63 )
{
return NULL ;
}
static int F_36 ( struct V_53 * V_53 )
{
return - V_30 ;
}
static void F_37 ( unsigned long V_64 )
{
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
F_38 ( & V_4 -> V_65 ) ;
}
static void F_39 ( struct V_3 * V_4 , unsigned int V_66 )
{
T_2 V_38 ;
if ( V_66 ) {
F_40 ( & V_4 -> V_65 ) ;
F_41 ( & V_4 -> V_50 ) ;
F_42 ( & V_4 -> V_67 , F_37 , ( unsigned long ) V_4 ) ;
} else
F_43 ( & V_4 -> V_67 ) ;
V_4 -> V_54 = 0 ;
V_4 -> V_55 = 0 ;
V_4 -> V_68 = 0 ;
V_4 -> V_69 = 0 ;
V_4 -> V_64 = V_4 -> V_15 ;
V_4 -> V_70 = 0 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_6 -> V_46 ; V_38 ++ )
V_4 -> V_48 [ V_38 ] = 0 ;
V_4 -> V_6 -> V_7 -> V_71 ( V_4 , V_4 -> V_64 , NULL , 0 ) ;
}
void F_44 ( struct V_45 * V_6 )
{
unsigned int V_38 ;
if ( ! V_6 )
return;
if ( V_6 -> V_63 && V_6 -> V_4 [ 0 ] ) {
F_39 ( V_6 -> V_4 [ 0 ] , 0 ) ;
return;
}
F_45 ( & V_72 ) ;
F_46 (i)
if ( V_6 -> V_4 [ V_38 ] )
F_39 ( V_6 -> V_4 [ V_38 ] , 0 ) ;
F_47 ( & V_72 ) ;
}
static inline void F_48 ( struct V_3 * V_4 ,
struct V_53 * V_53 )
{
V_4 -> V_53 = V_53 ;
V_4 -> V_53 -> V_73 -> V_74 = V_4 -> V_75 ;
}
static struct V_53 * F_49 ( struct V_45 * V_6 ,
struct V_3 * V_4 ,
unsigned int V_51 )
{
struct V_53 * V_53 ;
char * V_76 ;
V_76 = F_7 ( V_77 + 1 , V_21 ) ;
if ( ! V_76 )
return NULL ;
snprintf ( V_76 , V_77 , L_1 , V_6 -> V_78 , V_51 ) ;
V_53 = V_6 -> V_7 -> V_79 ( V_76 , V_6 -> V_61 ,
V_80 , V_4 ,
& V_6 -> V_63 ) ;
F_11 ( V_76 ) ;
return V_53 ;
}
static struct V_3 * F_50 ( struct V_45 * V_6 , unsigned int V_51 )
{
struct V_3 * V_4 = NULL ;
struct V_53 * V_53 ;
if ( V_6 -> V_63 )
return V_6 -> V_4 [ 0 ] ;
V_4 = F_20 ( V_6 ) ;
if ( ! V_4 )
return NULL ;
if ( V_6 -> V_81 ) {
V_53 = F_49 ( V_6 , V_4 , V_51 ) ;
if ( ! V_53 )
goto V_49;
F_48 ( V_4 , V_53 ) ;
}
V_4 -> V_51 = V_51 ;
F_39 ( V_4 , 1 ) ;
if( V_6 -> V_63 ) {
V_6 -> V_4 [ 0 ] = V_4 ;
V_4 -> V_51 = 0 ;
}
return V_4 ;
V_49:
F_25 ( V_4 ) ;
return NULL ;
}
static void F_51 ( struct V_3 * V_4 )
{
V_4 -> V_69 = 1 ;
F_43 ( & V_4 -> V_67 ) ;
F_28 ( & V_4 -> V_50 , F_29 ) ;
}
static void F_52 ( struct V_45 * V_6 ,
struct V_82 * V_7 )
{
if ( ! V_7 ) {
V_6 -> V_7 = & V_83 ;
return;
}
if ( ! V_7 -> V_71 )
V_7 -> V_71 = F_32 ;
if ( ! V_7 -> V_35 )
V_7 -> V_35 = F_33 ;
if ( ! V_7 -> V_8 )
V_7 -> V_8 = F_34 ;
if ( ! V_7 -> V_79 )
V_7 -> V_79 = F_35 ;
if ( ! V_7 -> V_52 )
V_7 -> V_52 = F_36 ;
V_6 -> V_7 = V_7 ;
}
static int T_4 F_53 ( struct V_84 * V_85 ,
unsigned long V_86 ,
void * V_87 )
{
unsigned int V_88 = ( unsigned long ) V_87 ;
struct V_45 * V_6 ;
switch( V_86 ) {
case V_89 :
case V_90 :
F_45 ( & V_72 ) ;
F_54 (chan, &relay_channels, list) {
if ( V_6 -> V_4 [ V_88 ] )
continue;
V_6 -> V_4 [ V_88 ] = F_50 ( V_6 , V_88 ) ;
if( ! V_6 -> V_4 [ V_88 ] ) {
F_55 ( V_91
L_2
L_3 , V_88 ) ;
F_47 ( & V_72 ) ;
return F_56 ( - V_92 ) ;
}
}
F_47 ( & V_72 ) ;
break;
case V_93 :
case V_94 :
break;
}
return V_95 ;
}
struct V_45 * F_57 ( const char * V_78 ,
struct V_53 * V_61 ,
T_2 V_96 ,
T_2 V_46 ,
struct V_82 * V_7 ,
void * V_97 )
{
unsigned int V_38 ;
struct V_45 * V_6 ;
if ( ! ( V_96 && V_46 ) )
return NULL ;
if ( V_96 > V_47 / V_46 )
return NULL ;
V_6 = F_7 ( sizeof( struct V_45 ) , V_21 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_98 = V_99 ;
V_6 -> V_46 = V_46 ;
V_6 -> V_96 = V_96 ;
V_6 -> V_29 = F_58 ( V_96 * V_46 ) ;
V_6 -> V_61 = V_61 ;
V_6 -> V_97 = V_97 ;
if ( V_78 ) {
V_6 -> V_81 = 1 ;
F_59 ( V_6 -> V_78 , V_78 , V_77 ) ;
}
F_52 ( V_6 , V_7 ) ;
F_41 ( & V_6 -> V_50 ) ;
F_45 ( & V_72 ) ;
F_60 (i) {
V_6 -> V_4 [ V_38 ] = F_50 ( V_6 , V_38 ) ;
if ( ! V_6 -> V_4 [ V_38 ] )
goto V_100;
}
F_61 ( & V_6 -> V_101 , & V_102 ) ;
F_47 ( & V_72 ) ;
return V_6 ;
V_100:
F_46 (i) {
if ( V_6 -> V_4 [ V_38 ] )
F_51 ( V_6 -> V_4 [ V_38 ] ) ;
}
F_28 ( & V_6 -> V_50 , F_23 ) ;
F_47 ( & V_72 ) ;
return NULL ;
}
static void F_62 ( void * V_103 )
{
struct V_104 * V_105 = V_103 ;
F_48 ( V_105 -> V_4 , V_105 -> V_53 ) ;
}
int F_63 ( struct V_45 * V_6 ,
const char * V_78 ,
struct V_53 * V_61 )
{
int V_106 = 0 ;
unsigned int V_38 , V_107 ;
unsigned long V_108 ;
struct V_53 * V_53 ;
struct V_104 V_109 ;
if ( ! V_6 || ! V_78 )
return - V_30 ;
F_59 ( V_6 -> V_78 , V_78 , V_77 ) ;
F_45 ( & V_72 ) ;
if ( F_16 ( V_6 -> V_81 ) ) {
F_47 ( & V_72 ) ;
return - V_110 ;
}
V_6 -> V_81 = 1 ;
V_6 -> V_61 = V_61 ;
V_107 = F_64 () ;
F_60 (i) {
if ( F_16 ( ! V_6 -> V_4 [ V_38 ] ) ) {
F_65 ( 1 , V_91 L_4 ) ;
V_106 = - V_30 ;
break;
}
V_53 = F_49 ( V_6 , V_6 -> V_4 [ V_38 ] , V_38 ) ;
if ( F_16 ( ! V_53 ) ) {
V_106 = - V_30 ;
break;
}
if ( V_107 == V_38 ) {
F_66 ( V_108 ) ;
F_48 ( V_6 -> V_4 [ V_38 ] , V_53 ) ;
F_67 ( V_108 ) ;
} else {
V_109 . V_4 = V_6 -> V_4 [ V_38 ] ;
V_109 . V_53 = V_53 ;
F_68 () ;
V_106 = F_69 ( V_38 ,
F_62 ,
& V_109 , 1 ) ;
}
if ( F_16 ( V_106 ) )
break;
}
F_70 () ;
F_47 ( & V_72 ) ;
return V_106 ;
}
T_2 F_71 ( struct V_3 * V_4 , T_2 V_23 )
{
void * V_111 , * V_112 ;
T_2 V_113 , V_114 ;
if ( F_16 ( V_23 > V_4 -> V_6 -> V_96 ) )
goto V_115;
if ( V_4 -> V_70 != V_4 -> V_6 -> V_96 + 1 ) {
V_4 -> V_59 = V_4 -> V_6 -> V_96 - V_4 -> V_70 ;
V_113 = V_4 -> V_54 % V_4 -> V_6 -> V_46 ;
V_4 -> V_48 [ V_113 ] = V_4 -> V_59 ;
V_4 -> V_54 ++ ;
if ( V_4 -> V_53 )
V_4 -> V_53 -> V_73 -> V_74 +=
V_4 -> V_6 -> V_96 -
V_4 -> V_48 [ V_113 ] ;
else
V_4 -> V_75 += V_4 -> V_6 -> V_96 -
V_4 -> V_48 [ V_113 ] ;
F_68 () ;
if ( F_72 ( & V_4 -> V_65 ) )
F_73 ( & V_4 -> V_67 , V_116 + 1 ) ;
}
V_111 = V_4 -> V_64 ;
V_114 = V_4 -> V_54 % V_4 -> V_6 -> V_46 ;
V_112 = V_4 -> V_15 + V_114 * V_4 -> V_6 -> V_96 ;
V_4 -> V_70 = 0 ;
if ( ! V_4 -> V_6 -> V_7 -> V_71 ( V_4 , V_112 , V_111 , V_4 -> V_59 ) ) {
V_4 -> V_70 = V_4 -> V_6 -> V_96 + 1 ;
return 0 ;
}
V_4 -> V_64 = V_112 ;
V_4 -> V_48 [ V_114 ] = 0 ;
if ( F_16 ( V_23 + V_4 -> V_70 > V_4 -> V_6 -> V_96 ) )
goto V_115;
return V_23 ;
V_115:
V_4 -> V_6 -> V_117 = V_23 ;
return 0 ;
}
void F_74 ( struct V_45 * V_6 ,
unsigned int V_51 ,
T_2 V_55 )
{
struct V_3 * V_4 ;
if ( ! V_6 )
return;
if ( V_51 >= V_118 || ! V_6 -> V_4 [ V_51 ] ||
V_55 > V_6 -> V_46 )
return;
V_4 = V_6 -> V_4 [ V_51 ] ;
if ( V_55 > V_4 -> V_54 - V_4 -> V_55 )
V_4 -> V_55 = V_4 -> V_54 ;
else
V_4 -> V_55 += V_55 ;
}
void F_75 ( struct V_45 * V_6 )
{
unsigned int V_38 ;
if ( ! V_6 )
return;
F_45 ( & V_72 ) ;
if ( V_6 -> V_63 && V_6 -> V_4 [ 0 ] )
F_51 ( V_6 -> V_4 [ 0 ] ) ;
else
F_46 (i)
if ( V_6 -> V_4 [ V_38 ] )
F_51 ( V_6 -> V_4 [ V_38 ] ) ;
if ( V_6 -> V_117 )
F_55 ( V_119 L_5
L_6 ,
V_6 -> V_117 , V_6 -> V_96 ) ;
F_76 ( & V_6 -> V_101 ) ;
F_28 ( & V_6 -> V_50 , F_23 ) ;
F_47 ( & V_72 ) ;
}
void F_77 ( struct V_45 * V_6 )
{
unsigned int V_38 ;
if ( ! V_6 )
return;
if ( V_6 -> V_63 && V_6 -> V_4 [ 0 ] ) {
F_71 ( V_6 -> V_4 [ 0 ] , 0 ) ;
return;
}
F_45 ( & V_72 ) ;
F_46 (i)
if ( V_6 -> V_4 [ V_38 ] )
F_71 ( V_6 -> V_4 [ V_38 ] , 0 ) ;
F_47 ( & V_72 ) ;
}
static int F_78 ( struct V_120 * V_120 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_120 -> V_121 ;
F_22 ( & V_4 -> V_50 ) ;
V_27 -> V_97 = V_4 ;
return F_79 ( V_120 , V_27 ) ;
}
static int F_80 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_27 -> V_97 ;
return F_12 ( V_4 , V_2 ) ;
}
static unsigned int F_81 ( struct V_26 * V_27 , T_5 * V_122 )
{
unsigned int V_123 = 0 ;
struct V_3 * V_4 = V_27 -> V_97 ;
if ( V_4 -> V_69 )
return V_124 ;
if ( V_27 -> V_125 & V_126 ) {
F_82 ( V_27 , & V_4 -> V_65 , V_122 ) ;
if ( ! F_30 ( V_4 ) )
V_123 |= V_127 | V_128 ;
}
return V_123 ;
}
static int F_83 ( struct V_120 * V_120 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_97 ;
F_28 ( & V_4 -> V_50 , F_29 ) ;
return 0 ;
}
static void F_84 ( struct V_3 * V_4 ,
T_2 V_129 ,
T_2 V_68 )
{
T_2 V_96 = V_4 -> V_6 -> V_96 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_130 ;
if ( V_4 -> V_54 == V_4 -> V_55 &&
V_4 -> V_70 == V_4 -> V_68 )
return;
if ( V_4 -> V_68 + V_68 > V_96 ) {
F_74 ( V_4 -> V_6 , V_4 -> V_51 , 1 ) ;
V_4 -> V_68 = 0 ;
}
V_4 -> V_68 += V_68 ;
if ( ! V_129 )
V_130 = V_4 -> V_55 % V_46 ;
else
V_130 = V_129 / V_4 -> V_6 -> V_96 ;
if ( V_4 -> V_68 + V_4 -> V_48 [ V_130 ] == V_96 ) {
if ( ( V_130 == V_4 -> V_54 % V_46 ) &&
( V_4 -> V_70 == V_96 ) )
return;
F_74 ( V_4 -> V_6 , V_4 -> V_51 , 1 ) ;
V_4 -> V_68 = 0 ;
}
}
static int F_85 ( struct V_3 * V_4 , T_2 V_129 )
{
T_2 V_96 = V_4 -> V_6 -> V_96 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_131 = V_4 -> V_54 ;
T_2 V_132 = V_4 -> V_55 ;
F_84 ( V_4 , V_129 , 0 ) ;
V_132 = V_4 -> V_55 ;
if ( F_16 ( V_4 -> V_70 > V_96 ) ) {
if ( V_131 == V_132 )
return 0 ;
return 1 ;
}
if ( F_16 ( V_131 - V_132 >= V_46 ) ) {
V_132 = V_131 - V_46 + 1 ;
V_4 -> V_55 = V_132 ;
V_4 -> V_68 = 0 ;
}
V_131 = ( V_131 % V_46 ) * V_96 + V_4 -> V_70 ;
V_132 = ( V_132 % V_46 ) * V_96 + V_4 -> V_68 ;
if ( V_132 > V_131 )
V_131 += V_46 * V_96 ;
if ( V_132 == V_131 ) {
if ( V_4 -> V_70 == V_96 &&
V_4 -> V_54 > V_4 -> V_55 )
return 1 ;
return 0 ;
}
return 1 ;
}
static T_2 F_86 ( T_2 V_129 ,
struct V_3 * V_4 )
{
T_2 V_48 , V_133 = 0 ;
T_2 V_130 , V_134 , V_135 , V_136 ;
T_2 V_96 = V_4 -> V_6 -> V_96 ;
V_135 = ( V_4 -> V_64 - V_4 -> V_15 ) / V_96 ;
V_136 = V_4 -> V_70 > V_96 ? V_96 : V_4 -> V_70 ;
V_130 = V_129 / V_96 ;
V_134 = V_129 % V_96 ;
V_48 = V_4 -> V_48 [ V_130 ] ;
if ( V_130 == V_135 ) {
if ( V_134 + V_48 < V_136 )
V_133 = V_136 - ( V_134 + V_48 ) ;
} else
V_133 = ( V_96 - V_48 ) - V_134 ;
return V_133 ;
}
static T_2 F_87 ( T_2 V_129 ,
struct V_3 * V_4 )
{
T_2 V_130 , V_48 , V_137 , V_138 ;
T_2 V_96 = V_4 -> V_6 -> V_96 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_132 = V_4 -> V_55 % V_46 ;
if ( ! V_129 )
V_129 = V_132 * V_96 + V_4 -> V_68 ;
V_130 = V_129 / V_96 ;
V_48 = V_4 -> V_48 [ V_130 ] ;
V_137 = ( V_130 + 1 ) * V_96 - V_48 ;
V_138 = ( V_130 + 1 ) * V_96 ;
if ( V_129 >= V_137 && V_129 < V_138 ) {
V_130 = ( V_130 + 1 ) % V_46 ;
V_129 = V_130 * V_96 ;
}
return V_129 ;
}
static T_2 F_88 ( struct V_3 * V_4 ,
T_2 V_129 ,
T_2 V_139 )
{
T_2 V_130 , V_48 , V_140 ;
T_2 V_96 = V_4 -> V_6 -> V_96 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
V_130 = V_129 / V_96 ;
V_48 = V_4 -> V_48 [ V_130 ] ;
if ( V_129 % V_96 + V_139 + V_48 == V_96 )
V_140 = ( V_130 + 1 ) * V_96 ;
else
V_140 = V_129 + V_139 ;
if ( V_140 >= V_96 * V_46 )
V_140 = 0 ;
return V_140 ;
}
static int F_89 ( T_2 V_141 ,
struct V_3 * V_4 ,
T_2 V_133 ,
T_6 * V_142 ,
T_7 V_143 )
{
void * V_144 ;
int V_145 = 0 ;
V_144 = V_4 -> V_15 + V_141 ;
V_145 = V_133 ;
if ( F_90 ( V_142 -> V_146 . V_4 , V_144 , V_133 ) ) {
V_142 -> error = - V_147 ;
V_145 = 0 ;
}
V_142 -> V_146 . V_64 += V_145 ;
V_142 -> V_148 += V_145 ;
V_142 -> V_139 -= V_145 ;
return V_145 ;
}
static T_8 F_91 ( struct V_26 * V_27 , T_9 * V_149 ,
T_10 V_150 ,
T_7 V_143 ,
T_6 * V_142 )
{
struct V_3 * V_4 = V_27 -> V_97 ;
T_2 V_141 , V_133 ;
int V_145 ;
if ( ! V_142 -> V_139 )
return 0 ;
F_45 ( & F_92 ( V_27 ) -> V_151 ) ;
do {
if ( ! F_85 ( V_4 , * V_149 ) )
break;
V_141 = F_87 ( * V_149 , V_4 ) ;
V_133 = F_86 ( V_141 , V_4 ) ;
if ( ! V_133 )
break;
V_133 = F_93 ( V_142 -> V_139 , V_133 ) ;
V_145 = V_150 ( V_141 , V_4 , V_133 , V_142 , V_143 ) ;
if ( V_142 -> error < 0 )
break;
if ( V_145 ) {
F_84 ( V_4 , V_141 , V_145 ) ;
* V_149 = F_88 ( V_4 , V_141 , V_145 ) ;
}
} while ( V_142 -> V_139 && V_145 );
F_47 ( & F_92 ( V_27 ) -> V_151 ) ;
return V_142 -> V_148 ;
}
static T_8 F_94 ( struct V_26 * V_27 ,
char T_11 * V_152 ,
T_2 V_139 ,
T_9 * V_149 )
{
T_6 V_142 ;
V_142 . V_148 = 0 ;
V_142 . V_139 = V_139 ;
V_142 . V_146 . V_4 = V_152 ;
V_142 . error = 0 ;
return F_91 ( V_27 , V_149 , F_89 ,
NULL , & V_142 ) ;
}
static void F_95 ( struct V_3 * V_153 , int V_68 )
{
V_153 -> V_68 += V_68 ;
if ( V_153 -> V_68 >= V_153 -> V_6 -> V_96 ) {
F_74 ( V_153 -> V_6 , V_153 -> V_51 , 1 ) ;
V_153 -> V_68 %= V_153 -> V_6 -> V_96 ;
}
}
static void F_96 ( struct V_154 * V_155 ,
struct V_156 * V_4 )
{
struct V_3 * V_153 ;
V_153 = (struct V_3 * ) F_97 ( V_4 -> V_12 ) ;
F_95 ( V_153 , V_4 -> V_157 ) ;
}
static void F_98 ( struct V_158 * V_159 , unsigned int V_38 )
{
}
static T_8 F_99 ( struct V_26 * V_160 ,
T_9 * V_149 ,
struct V_154 * V_155 ,
T_2 V_161 ,
unsigned int V_108 ,
int * V_162 )
{
unsigned int V_163 , V_164 , V_165 , V_166 , V_167 ;
struct V_3 * V_153 = V_160 -> V_97 ;
unsigned int V_96 = V_153 -> V_6 -> V_96 ;
T_12 V_168 = ( T_12 ) * V_149 ;
T_13 V_29 = ( T_13 ) V_153 -> V_6 -> V_29 ;
T_2 V_141 = ( T_2 ) F_100 ( V_168 , V_29 ) ;
T_2 V_130 = V_141 / V_96 ;
T_2 V_48 = V_153 -> V_48 [ V_130 ] ;
T_2 V_169 = V_130 * V_96 + V_96 - V_48 ;
struct V_12 * V_170 [ V_171 ] ;
struct V_172 V_173 [ V_171 ] ;
struct V_158 V_159 = {
. V_170 = V_170 ,
. V_167 = 0 ,
. V_174 = V_171 ,
. V_173 = V_173 ,
. V_108 = V_108 ,
. V_175 = & V_176 ,
. V_177 = F_98 ,
} ;
T_8 V_145 ;
if ( V_153 -> V_54 == V_153 -> V_55 )
return 0 ;
if ( F_101 ( V_155 , & V_159 ) )
return - V_92 ;
if ( V_161 > ( V_96 - V_141 % V_96 ) )
V_161 = V_96 - V_141 % V_96 ;
V_166 = V_153 -> V_6 -> V_29 >> V_16 ;
V_163 = ( V_141 / V_20 ) % V_166 ;
V_164 = V_141 & ~ V_178 ;
V_167 = F_102 (unsigned int, subbuf_pages, pipe->buffers) ;
for ( V_165 = 0 ; V_159 . V_167 < V_167 ; V_159 . V_167 ++ ) {
unsigned int V_179 , V_180 , V_157 ;
unsigned int V_181 = V_141 + V_165 ;
if ( ! V_161 )
break;
V_179 = F_102 (unsigned long, len, PAGE_SIZE - poff) ;
V_157 = V_179 ;
V_159 . V_170 [ V_159 . V_167 ] = V_153 -> V_40 [ V_163 ] ;
V_159 . V_173 [ V_159 . V_167 ] . V_70 = V_164 ;
V_180 = V_181 + V_179 ;
if ( V_180 >= V_169 ) {
V_179 = V_169 - V_181 ;
V_157 = V_179 + V_48 ;
}
V_159 . V_173 [ V_159 . V_167 ] . V_161 = V_179 ;
V_159 . V_173 [ V_159 . V_167 ] . V_157 = V_157 ;
V_161 -= V_179 ;
V_165 += V_179 ;
V_164 = 0 ;
V_163 = ( V_163 + 1 ) % V_166 ;
if ( V_180 >= V_169 ) {
V_159 . V_167 ++ ;
break;
}
}
V_145 = 0 ;
if ( ! V_159 . V_167 )
goto V_182;
V_145 = * V_162 = F_103 ( V_155 , & V_159 ) ;
if ( V_145 < 0 || V_145 < V_165 )
goto V_182;
if ( V_141 + V_145 == V_169 )
V_145 += V_48 ;
V_182:
F_104 ( & V_159 ) ;
return V_145 ;
}
static T_8 F_105 ( struct V_26 * V_160 ,
T_9 * V_149 ,
struct V_154 * V_155 ,
T_2 V_161 ,
unsigned int V_108 )
{
T_8 V_183 ;
int V_145 ;
int V_162 = 0 ;
V_145 = 0 ;
V_183 = 0 ;
while ( V_161 && ! V_183 ) {
V_145 = F_99 ( V_160 , V_149 , V_155 , V_161 , V_108 , & V_162 ) ;
if ( V_145 < 0 )
break;
else if ( ! V_145 ) {
if ( V_108 & V_184 )
V_145 = - V_185 ;
break;
}
* V_149 += V_145 ;
if ( V_145 > V_161 )
V_161 = 0 ;
else
V_161 -= V_145 ;
V_183 += V_162 ;
V_162 = 0 ;
}
if ( V_183 )
return V_183 ;
return V_145 ;
}
static T_14 int F_106 ( void )
{
F_107 ( F_53 , 0 ) ;
return 0 ;
}
