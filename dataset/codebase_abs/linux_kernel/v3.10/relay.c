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
F_25 ( V_4 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
return ( V_4 -> V_52 - V_4 -> V_53 ) ? 0 : 1 ;
}
int F_31 ( struct V_3 * V_4 )
{
T_2 V_54 = V_4 -> V_52 - V_4 -> V_53 ;
return ( V_54 >= V_4 -> V_6 -> V_46 ) ? 1 : 0 ;
}
static int F_32 ( struct V_3 * V_4 ,
void * V_55 ,
void * V_56 ,
T_2 V_57 )
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
static struct V_58 * F_35 ( const char * V_59 ,
struct V_58 * V_60 ,
T_3 V_61 ,
struct V_3 * V_4 ,
int * V_62 )
{
return NULL ;
}
static int F_36 ( struct V_58 * V_58 )
{
return - V_30 ;
}
static void F_37 ( unsigned long V_63 )
{
struct V_3 * V_4 = (struct V_3 * ) V_63 ;
F_38 ( & V_4 -> V_64 ) ;
}
static void F_39 ( struct V_3 * V_4 , unsigned int V_65 )
{
T_2 V_38 ;
if ( V_65 ) {
F_40 ( & V_4 -> V_64 ) ;
F_41 ( & V_4 -> V_50 ) ;
F_42 ( & V_4 -> V_66 , F_37 , ( unsigned long ) V_4 ) ;
} else
F_43 ( & V_4 -> V_66 ) ;
V_4 -> V_52 = 0 ;
V_4 -> V_53 = 0 ;
V_4 -> V_67 = 0 ;
V_4 -> V_68 = 0 ;
V_4 -> V_63 = V_4 -> V_15 ;
V_4 -> V_69 = 0 ;
for ( V_38 = 0 ; V_38 < V_4 -> V_6 -> V_46 ; V_38 ++ )
V_4 -> V_48 [ V_38 ] = 0 ;
V_4 -> V_6 -> V_7 -> V_70 ( V_4 , V_4 -> V_63 , NULL , 0 ) ;
}
void F_44 ( struct V_45 * V_6 )
{
unsigned int V_38 ;
if ( ! V_6 )
return;
if ( V_6 -> V_62 && V_6 -> V_4 [ 0 ] ) {
F_39 ( V_6 -> V_4 [ 0 ] , 0 ) ;
return;
}
F_45 ( & V_71 ) ;
F_46 (i)
if ( V_6 -> V_4 [ V_38 ] )
F_39 ( V_6 -> V_4 [ V_38 ] , 0 ) ;
F_47 ( & V_71 ) ;
}
static inline void F_48 ( struct V_3 * V_4 ,
struct V_58 * V_58 )
{
V_4 -> V_58 = V_58 ;
V_4 -> V_58 -> V_72 -> V_73 = V_4 -> V_74 ;
}
static struct V_58 * F_49 ( struct V_45 * V_6 ,
struct V_3 * V_4 ,
unsigned int V_51 )
{
struct V_58 * V_58 ;
char * V_75 ;
V_75 = F_7 ( V_76 + 1 , V_21 ) ;
if ( ! V_75 )
return NULL ;
snprintf ( V_75 , V_76 , L_1 , V_6 -> V_77 , V_51 ) ;
V_58 = V_6 -> V_7 -> V_78 ( V_75 , V_6 -> V_60 ,
V_79 , V_4 ,
& V_6 -> V_62 ) ;
F_11 ( V_75 ) ;
return V_58 ;
}
static struct V_3 * F_50 ( struct V_45 * V_6 , unsigned int V_51 )
{
struct V_3 * V_4 = NULL ;
struct V_58 * V_58 ;
if ( V_6 -> V_62 )
return V_6 -> V_4 [ 0 ] ;
V_4 = F_20 ( V_6 ) ;
if ( ! V_4 )
return NULL ;
if ( V_6 -> V_80 ) {
V_58 = F_49 ( V_6 , V_4 , V_51 ) ;
if ( ! V_58 )
goto V_49;
F_48 ( V_4 , V_58 ) ;
}
V_4 -> V_51 = V_51 ;
F_39 ( V_4 , 1 ) ;
if( V_6 -> V_62 ) {
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
V_4 -> V_68 = 1 ;
F_43 ( & V_4 -> V_66 ) ;
V_4 -> V_6 -> V_7 -> V_81 ( V_4 -> V_58 ) ;
F_28 ( & V_4 -> V_50 , F_29 ) ;
}
static void F_52 ( struct V_45 * V_6 ,
struct V_82 * V_7 )
{
if ( ! V_7 ) {
V_6 -> V_7 = & V_83 ;
return;
}
if ( ! V_7 -> V_70 )
V_7 -> V_70 = F_32 ;
if ( ! V_7 -> V_35 )
V_7 -> V_35 = F_33 ;
if ( ! V_7 -> V_8 )
V_7 -> V_8 = F_34 ;
if ( ! V_7 -> V_78 )
V_7 -> V_78 = F_35 ;
if ( ! V_7 -> V_81 )
V_7 -> V_81 = F_36 ;
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
F_45 ( & V_71 ) ;
F_54 (chan, &relay_channels, list) {
if ( V_6 -> V_4 [ V_88 ] )
continue;
V_6 -> V_4 [ V_88 ] = F_50 ( V_6 , V_88 ) ;
if( ! V_6 -> V_4 [ V_88 ] ) {
F_55 ( V_91
L_2
L_3 , V_88 ) ;
F_47 ( & V_71 ) ;
return F_56 ( - V_92 ) ;
}
}
F_47 ( & V_71 ) ;
break;
case V_93 :
case V_94 :
break;
}
return V_95 ;
}
struct V_45 * F_57 ( const char * V_77 ,
struct V_58 * V_60 ,
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
V_6 -> V_29 = F_14 ( V_96 * V_46 ) ;
V_6 -> V_60 = V_60 ;
V_6 -> V_97 = V_97 ;
if ( V_77 ) {
V_6 -> V_80 = 1 ;
F_58 ( V_6 -> V_77 , V_77 , V_76 ) ;
}
F_52 ( V_6 , V_7 ) ;
F_41 ( & V_6 -> V_50 ) ;
F_45 ( & V_71 ) ;
F_59 (i) {
V_6 -> V_4 [ V_38 ] = F_50 ( V_6 , V_38 ) ;
if ( ! V_6 -> V_4 [ V_38 ] )
goto V_100;
}
F_60 ( & V_6 -> V_101 , & V_102 ) ;
F_47 ( & V_71 ) ;
return V_6 ;
V_100:
F_46 (i) {
if ( V_6 -> V_4 [ V_38 ] )
F_51 ( V_6 -> V_4 [ V_38 ] ) ;
}
F_28 ( & V_6 -> V_50 , F_23 ) ;
F_47 ( & V_71 ) ;
return NULL ;
}
static void F_61 ( void * V_103 )
{
struct V_104 * V_105 = V_103 ;
F_48 ( V_105 -> V_4 , V_105 -> V_58 ) ;
}
int F_62 ( struct V_45 * V_6 ,
const char * V_77 ,
struct V_58 * V_60 )
{
int V_106 = 0 ;
unsigned int V_38 , V_107 ;
unsigned long V_108 ;
struct V_58 * V_58 ;
struct V_104 V_109 ;
if ( ! V_6 || ! V_77 )
return - V_30 ;
F_58 ( V_6 -> V_77 , V_77 , V_76 ) ;
F_45 ( & V_71 ) ;
if ( F_16 ( V_6 -> V_80 ) ) {
F_47 ( & V_71 ) ;
return - V_110 ;
}
V_6 -> V_80 = 1 ;
V_6 -> V_60 = V_60 ;
V_107 = F_63 () ;
F_59 (i) {
if ( F_16 ( ! V_6 -> V_4 [ V_38 ] ) ) {
F_64 ( 1 , V_91 L_4 ) ;
V_106 = - V_30 ;
break;
}
V_58 = F_49 ( V_6 , V_6 -> V_4 [ V_38 ] , V_38 ) ;
if ( F_16 ( ! V_58 ) ) {
V_106 = - V_30 ;
break;
}
if ( V_107 == V_38 ) {
F_65 ( V_108 ) ;
F_48 ( V_6 -> V_4 [ V_38 ] , V_58 ) ;
F_66 ( V_108 ) ;
} else {
V_109 . V_4 = V_6 -> V_4 [ V_38 ] ;
V_109 . V_58 = V_58 ;
F_67 () ;
V_106 = F_68 ( V_38 ,
F_61 ,
& V_109 , 1 ) ;
}
if ( F_16 ( V_106 ) )
break;
}
F_69 () ;
F_47 ( & V_71 ) ;
return V_106 ;
}
T_2 F_70 ( struct V_3 * V_4 , T_2 V_23 )
{
void * V_111 , * V_112 ;
T_2 V_113 , V_114 ;
if ( F_16 ( V_23 > V_4 -> V_6 -> V_96 ) )
goto V_115;
if ( V_4 -> V_69 != V_4 -> V_6 -> V_96 + 1 ) {
V_4 -> V_57 = V_4 -> V_6 -> V_96 - V_4 -> V_69 ;
V_113 = V_4 -> V_52 % V_4 -> V_6 -> V_46 ;
V_4 -> V_48 [ V_113 ] = V_4 -> V_57 ;
V_4 -> V_52 ++ ;
if ( V_4 -> V_58 )
V_4 -> V_58 -> V_72 -> V_73 +=
V_4 -> V_6 -> V_96 -
V_4 -> V_48 [ V_113 ] ;
else
V_4 -> V_74 += V_4 -> V_6 -> V_96 -
V_4 -> V_48 [ V_113 ] ;
F_67 () ;
if ( F_71 ( & V_4 -> V_64 ) )
F_72 ( & V_4 -> V_66 , V_116 + 1 ) ;
}
V_111 = V_4 -> V_63 ;
V_114 = V_4 -> V_52 % V_4 -> V_6 -> V_46 ;
V_112 = V_4 -> V_15 + V_114 * V_4 -> V_6 -> V_96 ;
V_4 -> V_69 = 0 ;
if ( ! V_4 -> V_6 -> V_7 -> V_70 ( V_4 , V_112 , V_111 , V_4 -> V_57 ) ) {
V_4 -> V_69 = V_4 -> V_6 -> V_96 + 1 ;
return 0 ;
}
V_4 -> V_63 = V_112 ;
V_4 -> V_48 [ V_114 ] = 0 ;
if ( F_16 ( V_23 + V_4 -> V_69 > V_4 -> V_6 -> V_96 ) )
goto V_115;
return V_23 ;
V_115:
V_4 -> V_6 -> V_117 = V_23 ;
return 0 ;
}
void F_73 ( struct V_45 * V_6 ,
unsigned int V_51 ,
T_2 V_53 )
{
struct V_3 * V_4 ;
if ( ! V_6 )
return;
if ( V_51 >= V_118 || ! V_6 -> V_4 [ V_51 ] ||
V_53 > V_6 -> V_46 )
return;
V_4 = V_6 -> V_4 [ V_51 ] ;
if ( V_53 > V_4 -> V_52 - V_4 -> V_53 )
V_4 -> V_53 = V_4 -> V_52 ;
else
V_4 -> V_53 += V_53 ;
}
void F_74 ( struct V_45 * V_6 )
{
unsigned int V_38 ;
if ( ! V_6 )
return;
F_45 ( & V_71 ) ;
if ( V_6 -> V_62 && V_6 -> V_4 [ 0 ] )
F_51 ( V_6 -> V_4 [ 0 ] ) ;
else
F_46 (i)
if ( V_6 -> V_4 [ V_38 ] )
F_51 ( V_6 -> V_4 [ V_38 ] ) ;
if ( V_6 -> V_117 )
F_55 ( V_119 L_5
L_6 ,
V_6 -> V_117 , V_6 -> V_96 ) ;
F_75 ( & V_6 -> V_101 ) ;
F_28 ( & V_6 -> V_50 , F_23 ) ;
F_47 ( & V_71 ) ;
}
void F_76 ( struct V_45 * V_6 )
{
unsigned int V_38 ;
if ( ! V_6 )
return;
if ( V_6 -> V_62 && V_6 -> V_4 [ 0 ] ) {
F_70 ( V_6 -> V_4 [ 0 ] , 0 ) ;
return;
}
F_45 ( & V_71 ) ;
F_46 (i)
if ( V_6 -> V_4 [ V_38 ] )
F_70 ( V_6 -> V_4 [ V_38 ] , 0 ) ;
F_47 ( & V_71 ) ;
}
static int F_77 ( struct V_120 * V_120 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_120 -> V_121 ;
F_22 ( & V_4 -> V_50 ) ;
V_27 -> V_97 = V_4 ;
return F_78 ( V_120 , V_27 ) ;
}
static int F_79 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_27 -> V_97 ;
return F_12 ( V_4 , V_2 ) ;
}
static unsigned int F_80 ( struct V_26 * V_27 , T_5 * V_122 )
{
unsigned int V_123 = 0 ;
struct V_3 * V_4 = V_27 -> V_97 ;
if ( V_4 -> V_68 )
return V_124 ;
if ( V_27 -> V_125 & V_126 ) {
F_81 ( V_27 , & V_4 -> V_64 , V_122 ) ;
if ( ! F_30 ( V_4 ) )
V_123 |= V_127 | V_128 ;
}
return V_123 ;
}
static int F_82 ( struct V_120 * V_120 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_97 ;
F_28 ( & V_4 -> V_50 , F_29 ) ;
return 0 ;
}
static void F_83 ( struct V_3 * V_4 ,
T_2 V_129 ,
T_2 V_67 )
{
T_2 V_96 = V_4 -> V_6 -> V_96 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_130 ;
if ( V_4 -> V_52 == V_4 -> V_53 &&
V_4 -> V_69 == V_4 -> V_67 )
return;
if ( V_4 -> V_67 + V_67 > V_96 ) {
F_73 ( V_4 -> V_6 , V_4 -> V_51 , 1 ) ;
V_4 -> V_67 = 0 ;
}
V_4 -> V_67 += V_67 ;
if ( ! V_129 )
V_130 = V_4 -> V_53 % V_46 ;
else
V_130 = V_129 / V_4 -> V_6 -> V_96 ;
if ( V_4 -> V_67 + V_4 -> V_48 [ V_130 ] == V_96 ) {
if ( ( V_130 == V_4 -> V_52 % V_46 ) &&
( V_4 -> V_69 == V_96 ) )
return;
F_73 ( V_4 -> V_6 , V_4 -> V_51 , 1 ) ;
V_4 -> V_67 = 0 ;
}
}
static int F_84 ( struct V_3 * V_4 , T_2 V_129 )
{
T_2 V_96 = V_4 -> V_6 -> V_96 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_131 = V_4 -> V_52 ;
T_2 V_132 = V_4 -> V_53 ;
F_83 ( V_4 , V_129 , 0 ) ;
V_132 = V_4 -> V_53 ;
if ( F_16 ( V_4 -> V_69 > V_96 ) ) {
if ( V_131 == V_132 )
return 0 ;
return 1 ;
}
if ( F_16 ( V_131 - V_132 >= V_46 ) ) {
V_132 = V_131 - V_46 + 1 ;
V_4 -> V_53 = V_132 ;
V_4 -> V_67 = 0 ;
}
V_131 = ( V_131 % V_46 ) * V_96 + V_4 -> V_69 ;
V_132 = ( V_132 % V_46 ) * V_96 + V_4 -> V_67 ;
if ( V_132 > V_131 )
V_131 += V_46 * V_96 ;
if ( V_132 == V_131 ) {
if ( V_4 -> V_69 == V_96 &&
V_4 -> V_52 > V_4 -> V_53 )
return 1 ;
return 0 ;
}
return 1 ;
}
static T_2 F_85 ( T_2 V_129 ,
struct V_3 * V_4 )
{
T_2 V_48 , V_133 = 0 ;
T_2 V_130 , V_134 , V_135 , V_136 ;
T_2 V_96 = V_4 -> V_6 -> V_96 ;
V_135 = ( V_4 -> V_63 - V_4 -> V_15 ) / V_96 ;
V_136 = V_4 -> V_69 > V_96 ? V_96 : V_4 -> V_69 ;
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
static T_2 F_86 ( T_2 V_129 ,
struct V_3 * V_4 )
{
T_2 V_130 , V_48 , V_137 , V_138 ;
T_2 V_96 = V_4 -> V_6 -> V_96 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_132 = V_4 -> V_53 % V_46 ;
if ( ! V_129 )
V_129 = V_132 * V_96 + V_4 -> V_67 ;
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
static T_2 F_87 ( struct V_3 * V_4 ,
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
static int F_88 ( T_2 V_141 ,
struct V_3 * V_4 ,
T_2 V_133 ,
T_6 * V_142 )
{
void * V_143 ;
int V_144 = 0 ;
V_143 = V_4 -> V_15 + V_141 ;
V_144 = V_133 ;
if ( F_89 ( V_142 -> V_145 . V_4 , V_143 , V_133 ) ) {
V_142 -> error = - V_146 ;
V_144 = 0 ;
}
V_142 -> V_145 . V_63 += V_144 ;
V_142 -> V_147 += V_144 ;
V_142 -> V_139 -= V_144 ;
return V_144 ;
}
static T_7 F_90 ( struct V_26 * V_27 , T_8 * V_148 ,
T_9 V_149 ,
T_6 * V_142 )
{
struct V_3 * V_4 = V_27 -> V_97 ;
T_2 V_141 , V_133 ;
int V_144 ;
if ( ! V_142 -> V_139 )
return 0 ;
F_45 ( & F_91 ( V_27 ) -> V_150 ) ;
do {
if ( ! F_84 ( V_4 , * V_148 ) )
break;
V_141 = F_86 ( * V_148 , V_4 ) ;
V_133 = F_85 ( V_141 , V_4 ) ;
if ( ! V_133 )
break;
V_133 = F_92 ( V_142 -> V_139 , V_133 ) ;
V_144 = V_149 ( V_141 , V_4 , V_133 , V_142 ) ;
if ( V_142 -> error < 0 )
break;
if ( V_144 ) {
F_83 ( V_4 , V_141 , V_144 ) ;
* V_148 = F_87 ( V_4 , V_141 , V_144 ) ;
}
} while ( V_142 -> V_139 && V_144 );
F_47 ( & F_91 ( V_27 ) -> V_150 ) ;
return V_142 -> V_147 ;
}
static T_7 F_93 ( struct V_26 * V_27 ,
char T_10 * V_151 ,
T_2 V_139 ,
T_8 * V_148 )
{
T_6 V_142 ;
V_142 . V_147 = 0 ;
V_142 . V_139 = V_139 ;
V_142 . V_145 . V_4 = V_151 ;
V_142 . error = 0 ;
return F_90 ( V_27 , V_148 , F_88 , & V_142 ) ;
}
static void F_94 ( struct V_3 * V_152 , int V_67 )
{
V_152 -> V_67 += V_67 ;
if ( V_152 -> V_67 >= V_152 -> V_6 -> V_96 ) {
F_73 ( V_152 -> V_6 , V_152 -> V_51 , 1 ) ;
V_152 -> V_67 %= V_152 -> V_6 -> V_96 ;
}
}
static void F_95 ( struct V_153 * V_154 ,
struct V_155 * V_4 )
{
struct V_3 * V_152 ;
V_152 = (struct V_3 * ) F_96 ( V_4 -> V_12 ) ;
F_94 ( V_152 , V_4 -> V_156 ) ;
}
static void F_97 ( struct V_157 * V_158 , unsigned int V_38 )
{
}
static T_7 F_98 ( struct V_26 * V_159 ,
T_8 * V_148 ,
struct V_153 * V_154 ,
T_2 V_160 ,
unsigned int V_108 ,
int * V_161 )
{
unsigned int V_162 , V_163 , V_164 , V_165 , V_166 ;
struct V_3 * V_152 = V_159 -> V_97 ;
unsigned int V_96 = V_152 -> V_6 -> V_96 ;
T_11 V_167 = ( T_11 ) * V_148 ;
T_12 V_29 = ( T_12 ) V_152 -> V_6 -> V_29 ;
T_2 V_141 = ( T_2 ) F_99 ( V_167 , V_29 ) ;
T_2 V_130 = V_141 / V_96 ;
T_2 V_48 = V_152 -> V_48 [ V_130 ] ;
T_2 V_168 = V_130 * V_96 + V_96 - V_48 ;
struct V_12 * V_169 [ V_170 ] ;
struct V_171 V_172 [ V_170 ] ;
struct V_157 V_158 = {
. V_169 = V_169 ,
. V_166 = 0 ,
. V_173 = V_170 ,
. V_172 = V_172 ,
. V_108 = V_108 ,
. V_174 = & V_175 ,
. V_176 = F_97 ,
} ;
T_7 V_144 ;
if ( V_152 -> V_52 == V_152 -> V_53 )
return 0 ;
if ( F_100 ( V_154 , & V_158 ) )
return - V_92 ;
if ( V_160 > ( V_96 - V_141 % V_96 ) )
V_160 = V_96 - V_141 % V_96 ;
V_165 = V_152 -> V_6 -> V_29 >> V_16 ;
V_162 = ( V_141 / V_20 ) % V_165 ;
V_163 = V_141 & ~ V_177 ;
V_166 = F_101 (unsigned int, subbuf_pages, pipe->buffers) ;
for ( V_164 = 0 ; V_158 . V_166 < V_166 ; V_158 . V_166 ++ ) {
unsigned int V_178 , V_179 , V_156 ;
unsigned int V_180 = V_141 + V_164 ;
if ( ! V_160 )
break;
V_178 = F_101 (unsigned long, len, PAGE_SIZE - poff) ;
V_156 = V_178 ;
V_158 . V_169 [ V_158 . V_166 ] = V_152 -> V_40 [ V_162 ] ;
V_158 . V_172 [ V_158 . V_166 ] . V_69 = V_163 ;
V_179 = V_180 + V_178 ;
if ( V_179 >= V_168 ) {
V_178 = V_168 - V_180 ;
V_156 = V_178 + V_48 ;
}
V_158 . V_172 [ V_158 . V_166 ] . V_160 = V_178 ;
V_158 . V_172 [ V_158 . V_166 ] . V_156 = V_156 ;
V_160 -= V_178 ;
V_164 += V_178 ;
V_163 = 0 ;
V_162 = ( V_162 + 1 ) % V_165 ;
if ( V_179 >= V_168 ) {
V_158 . V_166 ++ ;
break;
}
}
V_144 = 0 ;
if ( ! V_158 . V_166 )
goto V_181;
V_144 = * V_161 = F_102 ( V_154 , & V_158 ) ;
if ( V_144 < 0 || V_144 < V_164 )
goto V_181;
if ( V_141 + V_144 == V_168 )
V_144 += V_48 ;
V_181:
F_103 ( & V_158 ) ;
return V_144 ;
}
static T_7 F_104 ( struct V_26 * V_159 ,
T_8 * V_148 ,
struct V_153 * V_154 ,
T_2 V_160 ,
unsigned int V_108 )
{
T_7 V_182 ;
int V_144 ;
int V_161 = 0 ;
V_144 = 0 ;
V_182 = 0 ;
while ( V_160 && ! V_182 ) {
V_144 = F_98 ( V_159 , V_148 , V_154 , V_160 , V_108 , & V_161 ) ;
if ( V_144 < 0 )
break;
else if ( ! V_144 ) {
if ( V_108 & V_183 )
V_144 = - V_184 ;
break;
}
* V_148 += V_144 ;
if ( V_144 > V_160 )
V_160 = 0 ;
else
V_160 -= V_144 ;
V_182 += V_161 ;
V_161 = 0 ;
}
if ( V_182 )
return V_182 ;
return V_144 ;
}
static T_13 int F_105 ( void )
{
F_106 ( F_53 , 0 ) ;
return 0 ;
}
