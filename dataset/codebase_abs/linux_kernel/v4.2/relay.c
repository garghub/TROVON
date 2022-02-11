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
F_9 ( V_22 ) ;
}
static int F_10 ( struct V_3 * V_4 , struct V_1 * V_2 )
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
static void * F_11 ( struct V_3 * V_4 , T_2 * V_36 )
{
void * V_37 ;
unsigned int V_38 , V_39 , V_18 ;
* V_36 = F_12 ( * V_36 ) ;
V_18 = * V_36 >> V_16 ;
V_4 -> V_40 = F_5 ( V_18 ) ;
if ( ! V_4 -> V_40 )
return NULL ;
for ( V_38 = 0 ; V_38 < V_18 ; V_38 ++ ) {
V_4 -> V_40 [ V_38 ] = F_13 ( V_21 ) ;
if ( F_14 ( ! V_4 -> V_40 [ V_38 ] ) )
goto V_41;
F_15 ( V_4 -> V_40 [ V_38 ] , ( unsigned long ) V_4 ) ;
}
V_37 = F_16 ( V_4 -> V_40 , V_18 , V_42 , V_43 ) ;
if ( ! V_37 )
goto V_41;
memset ( V_37 , 0 , * V_36 ) ;
V_4 -> V_44 = V_18 ;
return V_37 ;
V_41:
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ )
F_17 ( V_4 -> V_40 [ V_39 ] ) ;
F_8 ( V_4 -> V_40 ) ;
return NULL ;
}
static struct V_3 * F_18 ( struct V_45 * V_6 )
{
struct V_3 * V_4 ;
if ( V_6 -> V_46 > V_47 / sizeof( T_2 * ) )
return NULL ;
V_4 = F_7 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_48 = F_19 ( V_6 -> V_46 * sizeof( T_2 * ) , V_21 ) ;
if ( ! V_4 -> V_48 )
goto V_49;
V_4 -> V_15 = F_11 ( V_4 , & V_6 -> V_29 ) ;
if ( ! V_4 -> V_15 )
goto V_49;
V_4 -> V_6 = V_6 ;
F_20 ( & V_4 -> V_6 -> V_50 ) ;
return V_4 ;
V_49:
F_21 ( V_4 -> V_48 ) ;
F_21 ( V_4 ) ;
return NULL ;
}
static void F_22 ( struct V_50 * V_50 )
{
struct V_45 * V_6 = F_23 ( V_50 , struct V_45 , V_50 ) ;
F_21 ( V_6 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_45 * V_6 = V_4 -> V_6 ;
unsigned int V_38 ;
if ( F_25 ( V_4 -> V_15 ) ) {
F_26 ( V_4 -> V_15 ) ;
for ( V_38 = 0 ; V_38 < V_4 -> V_44 ; V_38 ++ )
F_17 ( V_4 -> V_40 [ V_38 ] ) ;
F_8 ( V_4 -> V_40 ) ;
}
V_6 -> V_4 [ V_4 -> V_51 ] = NULL ;
F_21 ( V_4 -> V_48 ) ;
F_21 ( V_4 ) ;
F_27 ( & V_6 -> V_50 , F_22 ) ;
}
static void F_28 ( struct V_50 * V_50 )
{
struct V_3 * V_4 = F_23 ( V_50 , struct V_3 , V_50 ) ;
F_24 ( V_4 ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
return ( V_4 -> V_52 - V_4 -> V_53 ) ? 0 : 1 ;
}
int F_30 ( struct V_3 * V_4 )
{
T_2 V_54 = V_4 -> V_52 - V_4 -> V_53 ;
return ( V_54 >= V_4 -> V_6 -> V_46 ) ? 1 : 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
void * V_55 ,
void * V_56 ,
T_2 V_57 )
{
if ( F_30 ( V_4 ) )
return 0 ;
return 1 ;
}
static void F_32 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
}
static void F_33 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
}
static struct V_58 * F_34 ( const char * V_59 ,
struct V_58 * V_60 ,
T_3 V_61 ,
struct V_3 * V_4 ,
int * V_62 )
{
return NULL ;
}
static int F_35 ( struct V_58 * V_58 )
{
return - V_30 ;
}
static void F_36 ( unsigned long V_63 )
{
struct V_3 * V_4 = (struct V_3 * ) V_63 ;
F_37 ( & V_4 -> V_64 ) ;
}
static void F_38 ( struct V_3 * V_4 , unsigned int V_65 )
{
T_2 V_38 ;
if ( V_65 ) {
F_39 ( & V_4 -> V_64 ) ;
F_40 ( & V_4 -> V_50 ) ;
F_41 ( & V_4 -> V_66 , F_36 , ( unsigned long ) V_4 ) ;
} else
F_42 ( & V_4 -> V_66 ) ;
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
void F_43 ( struct V_45 * V_6 )
{
unsigned int V_38 ;
if ( ! V_6 )
return;
if ( V_6 -> V_62 && V_6 -> V_4 [ 0 ] ) {
F_38 ( V_6 -> V_4 [ 0 ] , 0 ) ;
return;
}
F_44 ( & V_71 ) ;
F_45 (i)
if ( V_6 -> V_4 [ V_38 ] )
F_38 ( V_6 -> V_4 [ V_38 ] , 0 ) ;
F_46 ( & V_71 ) ;
}
static inline void F_47 ( struct V_3 * V_4 ,
struct V_58 * V_58 )
{
V_4 -> V_58 = V_58 ;
F_48 ( V_4 -> V_58 ) -> V_72 = V_4 -> V_73 ;
}
static struct V_58 * F_49 ( struct V_45 * V_6 ,
struct V_3 * V_4 ,
unsigned int V_51 )
{
struct V_58 * V_58 ;
char * V_74 ;
V_74 = F_7 ( V_75 + 1 , V_21 ) ;
if ( ! V_74 )
return NULL ;
snprintf ( V_74 , V_75 , L_1 , V_6 -> V_76 , V_51 ) ;
V_58 = V_6 -> V_7 -> V_77 ( V_74 , V_6 -> V_60 ,
V_78 , V_4 ,
& V_6 -> V_62 ) ;
F_21 ( V_74 ) ;
return V_58 ;
}
static struct V_3 * F_50 ( struct V_45 * V_6 , unsigned int V_51 )
{
struct V_3 * V_4 = NULL ;
struct V_58 * V_58 ;
if ( V_6 -> V_62 )
return V_6 -> V_4 [ 0 ] ;
V_4 = F_18 ( V_6 ) ;
if ( ! V_4 )
return NULL ;
if ( V_6 -> V_79 ) {
V_58 = F_49 ( V_6 , V_4 , V_51 ) ;
if ( ! V_58 )
goto V_49;
F_47 ( V_4 , V_58 ) ;
}
V_4 -> V_51 = V_51 ;
F_38 ( V_4 , 1 ) ;
if( V_6 -> V_62 ) {
V_6 -> V_4 [ 0 ] = V_4 ;
V_4 -> V_51 = 0 ;
}
return V_4 ;
V_49:
F_24 ( V_4 ) ;
return NULL ;
}
static void F_51 ( struct V_3 * V_4 )
{
V_4 -> V_68 = 1 ;
F_42 ( & V_4 -> V_66 ) ;
V_4 -> V_6 -> V_7 -> V_80 ( V_4 -> V_58 ) ;
F_27 ( & V_4 -> V_50 , F_28 ) ;
}
static void F_52 ( struct V_45 * V_6 ,
struct V_81 * V_7 )
{
if ( ! V_7 ) {
V_6 -> V_7 = & V_82 ;
return;
}
if ( ! V_7 -> V_70 )
V_7 -> V_70 = F_31 ;
if ( ! V_7 -> V_35 )
V_7 -> V_35 = F_32 ;
if ( ! V_7 -> V_8 )
V_7 -> V_8 = F_33 ;
if ( ! V_7 -> V_77 )
V_7 -> V_77 = F_34 ;
if ( ! V_7 -> V_80 )
V_7 -> V_80 = F_35 ;
V_6 -> V_7 = V_7 ;
}
static int F_53 ( struct V_83 * V_84 ,
unsigned long V_85 ,
void * V_86 )
{
unsigned int V_87 = ( unsigned long ) V_86 ;
struct V_45 * V_6 ;
switch( V_85 ) {
case V_88 :
case V_89 :
F_44 ( & V_71 ) ;
F_54 (chan, &relay_channels, list) {
if ( V_6 -> V_4 [ V_87 ] )
continue;
V_6 -> V_4 [ V_87 ] = F_50 ( V_6 , V_87 ) ;
if( ! V_6 -> V_4 [ V_87 ] ) {
F_55 ( V_90
L_2
L_3 , V_87 ) ;
F_46 ( & V_71 ) ;
return F_56 ( - V_91 ) ;
}
}
F_46 ( & V_71 ) ;
break;
case V_92 :
case V_93 :
break;
}
return V_94 ;
}
struct V_45 * F_57 ( const char * V_76 ,
struct V_58 * V_60 ,
T_2 V_95 ,
T_2 V_46 ,
struct V_81 * V_7 ,
void * V_96 )
{
unsigned int V_38 ;
struct V_45 * V_6 ;
if ( ! ( V_95 && V_46 ) )
return NULL ;
if ( V_95 > V_47 / V_46 )
return NULL ;
V_6 = F_7 ( sizeof( struct V_45 ) , V_21 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_97 = V_98 ;
V_6 -> V_46 = V_46 ;
V_6 -> V_95 = V_95 ;
V_6 -> V_29 = F_12 ( V_95 * V_46 ) ;
V_6 -> V_60 = V_60 ;
V_6 -> V_96 = V_96 ;
if ( V_76 ) {
V_6 -> V_79 = 1 ;
F_58 ( V_6 -> V_76 , V_76 , V_75 ) ;
}
F_52 ( V_6 , V_7 ) ;
F_40 ( & V_6 -> V_50 ) ;
F_44 ( & V_71 ) ;
F_59 (i) {
V_6 -> V_4 [ V_38 ] = F_50 ( V_6 , V_38 ) ;
if ( ! V_6 -> V_4 [ V_38 ] )
goto V_99;
}
F_60 ( & V_6 -> V_100 , & V_101 ) ;
F_46 ( & V_71 ) ;
return V_6 ;
V_99:
F_45 (i) {
if ( V_6 -> V_4 [ V_38 ] )
F_51 ( V_6 -> V_4 [ V_38 ] ) ;
}
F_27 ( & V_6 -> V_50 , F_22 ) ;
F_46 ( & V_71 ) ;
return NULL ;
}
static void F_61 ( void * V_102 )
{
struct V_103 * V_104 = V_102 ;
F_47 ( V_104 -> V_4 , V_104 -> V_58 ) ;
}
int F_62 ( struct V_45 * V_6 ,
const char * V_76 ,
struct V_58 * V_60 )
{
int V_105 = 0 ;
unsigned int V_38 , V_106 ;
unsigned long V_107 ;
struct V_58 * V_58 ;
struct V_103 V_108 ;
if ( ! V_6 || ! V_76 )
return - V_30 ;
F_58 ( V_6 -> V_76 , V_76 , V_75 ) ;
F_44 ( & V_71 ) ;
if ( F_14 ( V_6 -> V_79 ) ) {
F_46 ( & V_71 ) ;
return - V_109 ;
}
V_6 -> V_79 = 1 ;
V_6 -> V_60 = V_60 ;
V_106 = F_63 () ;
F_59 (i) {
if ( F_14 ( ! V_6 -> V_4 [ V_38 ] ) ) {
F_64 ( 1 , V_90 L_4 ) ;
V_105 = - V_30 ;
break;
}
V_58 = F_49 ( V_6 , V_6 -> V_4 [ V_38 ] , V_38 ) ;
if ( F_14 ( ! V_58 ) ) {
V_105 = - V_30 ;
break;
}
if ( V_106 == V_38 ) {
F_65 ( V_107 ) ;
F_47 ( V_6 -> V_4 [ V_38 ] , V_58 ) ;
F_66 ( V_107 ) ;
} else {
V_108 . V_4 = V_6 -> V_4 [ V_38 ] ;
V_108 . V_58 = V_58 ;
F_67 () ;
V_105 = F_68 ( V_38 ,
F_61 ,
& V_108 , 1 ) ;
}
if ( F_14 ( V_105 ) )
break;
}
F_69 () ;
F_46 ( & V_71 ) ;
return V_105 ;
}
T_2 F_70 ( struct V_3 * V_4 , T_2 V_23 )
{
void * V_110 , * V_111 ;
T_2 V_112 , V_113 ;
if ( F_14 ( V_23 > V_4 -> V_6 -> V_95 ) )
goto V_114;
if ( V_4 -> V_69 != V_4 -> V_6 -> V_95 + 1 ) {
V_4 -> V_57 = V_4 -> V_6 -> V_95 - V_4 -> V_69 ;
V_112 = V_4 -> V_52 % V_4 -> V_6 -> V_46 ;
V_4 -> V_48 [ V_112 ] = V_4 -> V_57 ;
V_4 -> V_52 ++ ;
if ( V_4 -> V_58 )
F_48 ( V_4 -> V_58 ) -> V_72 +=
V_4 -> V_6 -> V_95 -
V_4 -> V_48 [ V_112 ] ;
else
V_4 -> V_73 += V_4 -> V_6 -> V_95 -
V_4 -> V_48 [ V_112 ] ;
F_67 () ;
if ( F_71 ( & V_4 -> V_64 ) )
F_72 ( & V_4 -> V_66 , V_115 + 1 ) ;
}
V_110 = V_4 -> V_63 ;
V_113 = V_4 -> V_52 % V_4 -> V_6 -> V_46 ;
V_111 = V_4 -> V_15 + V_113 * V_4 -> V_6 -> V_95 ;
V_4 -> V_69 = 0 ;
if ( ! V_4 -> V_6 -> V_7 -> V_70 ( V_4 , V_111 , V_110 , V_4 -> V_57 ) ) {
V_4 -> V_69 = V_4 -> V_6 -> V_95 + 1 ;
return 0 ;
}
V_4 -> V_63 = V_111 ;
V_4 -> V_48 [ V_113 ] = 0 ;
if ( F_14 ( V_23 + V_4 -> V_69 > V_4 -> V_6 -> V_95 ) )
goto V_114;
return V_23 ;
V_114:
V_4 -> V_6 -> V_116 = V_23 ;
return 0 ;
}
void F_73 ( struct V_45 * V_6 ,
unsigned int V_51 ,
T_2 V_53 )
{
struct V_3 * V_4 ;
if ( ! V_6 )
return;
if ( V_51 >= V_117 || ! V_6 -> V_4 [ V_51 ] ||
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
F_44 ( & V_71 ) ;
if ( V_6 -> V_62 && V_6 -> V_4 [ 0 ] )
F_51 ( V_6 -> V_4 [ 0 ] ) ;
else
F_45 (i)
if ( V_6 -> V_4 [ V_38 ] )
F_51 ( V_6 -> V_4 [ V_38 ] ) ;
if ( V_6 -> V_116 )
F_55 ( V_118 L_5
L_6 ,
V_6 -> V_116 , V_6 -> V_95 ) ;
F_75 ( & V_6 -> V_100 ) ;
F_27 ( & V_6 -> V_50 , F_22 ) ;
F_46 ( & V_71 ) ;
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
F_44 ( & V_71 ) ;
F_45 (i)
if ( V_6 -> V_4 [ V_38 ] )
F_70 ( V_6 -> V_4 [ V_38 ] , 0 ) ;
F_46 ( & V_71 ) ;
}
static int F_77 ( struct V_119 * V_119 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_119 -> V_120 ;
F_20 ( & V_4 -> V_50 ) ;
V_27 -> V_96 = V_4 ;
return F_78 ( V_119 , V_27 ) ;
}
static int F_79 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_27 -> V_96 ;
return F_10 ( V_4 , V_2 ) ;
}
static unsigned int F_80 ( struct V_26 * V_27 , T_4 * V_121 )
{
unsigned int V_122 = 0 ;
struct V_3 * V_4 = V_27 -> V_96 ;
if ( V_4 -> V_68 )
return V_123 ;
if ( V_27 -> V_124 & V_125 ) {
F_81 ( V_27 , & V_4 -> V_64 , V_121 ) ;
if ( ! F_29 ( V_4 ) )
V_122 |= V_126 | V_127 ;
}
return V_122 ;
}
static int F_82 ( struct V_119 * V_119 , struct V_26 * V_27 )
{
struct V_3 * V_4 = V_27 -> V_96 ;
F_27 ( & V_4 -> V_50 , F_28 ) ;
return 0 ;
}
static void F_83 ( struct V_3 * V_4 ,
T_2 V_128 ,
T_2 V_67 )
{
T_2 V_95 = V_4 -> V_6 -> V_95 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_129 ;
if ( V_4 -> V_52 == V_4 -> V_53 &&
V_4 -> V_69 == V_4 -> V_67 )
return;
if ( V_4 -> V_67 + V_67 > V_95 ) {
F_73 ( V_4 -> V_6 , V_4 -> V_51 , 1 ) ;
V_4 -> V_67 = 0 ;
}
V_4 -> V_67 += V_67 ;
if ( ! V_128 )
V_129 = V_4 -> V_53 % V_46 ;
else
V_129 = V_128 / V_4 -> V_6 -> V_95 ;
if ( V_4 -> V_67 + V_4 -> V_48 [ V_129 ] == V_95 ) {
if ( ( V_129 == V_4 -> V_52 % V_46 ) &&
( V_4 -> V_69 == V_95 ) )
return;
F_73 ( V_4 -> V_6 , V_4 -> V_51 , 1 ) ;
V_4 -> V_67 = 0 ;
}
}
static int F_84 ( struct V_3 * V_4 , T_2 V_128 )
{
T_2 V_95 = V_4 -> V_6 -> V_95 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_130 = V_4 -> V_52 ;
T_2 V_131 = V_4 -> V_53 ;
F_83 ( V_4 , V_128 , 0 ) ;
V_131 = V_4 -> V_53 ;
if ( F_14 ( V_4 -> V_69 > V_95 ) ) {
if ( V_130 == V_131 )
return 0 ;
return 1 ;
}
if ( F_14 ( V_130 - V_131 >= V_46 ) ) {
V_131 = V_130 - V_46 + 1 ;
V_4 -> V_53 = V_131 ;
V_4 -> V_67 = 0 ;
}
V_130 = ( V_130 % V_46 ) * V_95 + V_4 -> V_69 ;
V_131 = ( V_131 % V_46 ) * V_95 + V_4 -> V_67 ;
if ( V_131 > V_130 )
V_130 += V_46 * V_95 ;
if ( V_131 == V_130 ) {
if ( V_4 -> V_69 == V_95 &&
V_4 -> V_52 > V_4 -> V_53 )
return 1 ;
return 0 ;
}
return 1 ;
}
static T_2 F_85 ( T_2 V_128 ,
struct V_3 * V_4 )
{
T_2 V_48 , V_132 = 0 ;
T_2 V_129 , V_133 , V_134 , V_135 ;
T_2 V_95 = V_4 -> V_6 -> V_95 ;
V_134 = ( V_4 -> V_63 - V_4 -> V_15 ) / V_95 ;
V_135 = V_4 -> V_69 > V_95 ? V_95 : V_4 -> V_69 ;
V_129 = V_128 / V_95 ;
V_133 = V_128 % V_95 ;
V_48 = V_4 -> V_48 [ V_129 ] ;
if ( V_129 == V_134 ) {
if ( V_133 + V_48 < V_135 )
V_132 = V_135 - ( V_133 + V_48 ) ;
} else
V_132 = ( V_95 - V_48 ) - V_133 ;
return V_132 ;
}
static T_2 F_86 ( T_2 V_128 ,
struct V_3 * V_4 )
{
T_2 V_129 , V_48 , V_136 , V_137 ;
T_2 V_95 = V_4 -> V_6 -> V_95 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
T_2 V_131 = V_4 -> V_53 % V_46 ;
if ( ! V_128 )
V_128 = V_131 * V_95 + V_4 -> V_67 ;
V_129 = V_128 / V_95 ;
V_48 = V_4 -> V_48 [ V_129 ] ;
V_136 = ( V_129 + 1 ) * V_95 - V_48 ;
V_137 = ( V_129 + 1 ) * V_95 ;
if ( V_128 >= V_136 && V_128 < V_137 ) {
V_129 = ( V_129 + 1 ) % V_46 ;
V_128 = V_129 * V_95 ;
}
return V_128 ;
}
static T_2 F_87 ( struct V_3 * V_4 ,
T_2 V_128 ,
T_2 V_138 )
{
T_2 V_129 , V_48 , V_139 ;
T_2 V_95 = V_4 -> V_6 -> V_95 ;
T_2 V_46 = V_4 -> V_6 -> V_46 ;
V_129 = V_128 / V_95 ;
V_48 = V_4 -> V_48 [ V_129 ] ;
if ( V_128 % V_95 + V_138 + V_48 == V_95 )
V_139 = ( V_129 + 1 ) * V_95 ;
else
V_139 = V_128 + V_138 ;
if ( V_139 >= V_95 * V_46 )
V_139 = 0 ;
return V_139 ;
}
static int F_88 ( T_2 V_140 ,
struct V_3 * V_4 ,
T_2 V_132 ,
T_5 * V_141 )
{
void * V_142 ;
int V_143 = 0 ;
V_142 = V_4 -> V_15 + V_140 ;
V_143 = V_132 ;
if ( F_89 ( V_141 -> V_144 . V_4 , V_142 , V_132 ) ) {
V_141 -> error = - V_145 ;
V_143 = 0 ;
}
V_141 -> V_144 . V_63 += V_143 ;
V_141 -> V_146 += V_143 ;
V_141 -> V_138 -= V_143 ;
return V_143 ;
}
static T_6 F_90 ( struct V_26 * V_27 , T_7 * V_147 ,
T_8 V_148 ,
T_5 * V_141 )
{
struct V_3 * V_4 = V_27 -> V_96 ;
T_2 V_140 , V_132 ;
int V_143 ;
if ( ! V_141 -> V_138 )
return 0 ;
F_44 ( & F_91 ( V_27 ) -> V_149 ) ;
do {
if ( ! F_84 ( V_4 , * V_147 ) )
break;
V_140 = F_86 ( * V_147 , V_4 ) ;
V_132 = F_85 ( V_140 , V_4 ) ;
if ( ! V_132 )
break;
V_132 = F_92 ( V_141 -> V_138 , V_132 ) ;
V_143 = V_148 ( V_140 , V_4 , V_132 , V_141 ) ;
if ( V_141 -> error < 0 )
break;
if ( V_143 ) {
F_83 ( V_4 , V_140 , V_143 ) ;
* V_147 = F_87 ( V_4 , V_140 , V_143 ) ;
}
} while ( V_141 -> V_138 && V_143 );
F_46 ( & F_91 ( V_27 ) -> V_149 ) ;
return V_141 -> V_146 ;
}
static T_6 F_93 ( struct V_26 * V_27 ,
char T_9 * V_150 ,
T_2 V_138 ,
T_7 * V_147 )
{
T_5 V_141 ;
V_141 . V_146 = 0 ;
V_141 . V_138 = V_138 ;
V_141 . V_144 . V_4 = V_150 ;
V_141 . error = 0 ;
return F_90 ( V_27 , V_147 , F_88 , & V_141 ) ;
}
static void F_94 ( struct V_3 * V_151 , int V_67 )
{
V_151 -> V_67 += V_67 ;
if ( V_151 -> V_67 >= V_151 -> V_6 -> V_95 ) {
F_73 ( V_151 -> V_6 , V_151 -> V_51 , 1 ) ;
V_151 -> V_67 %= V_151 -> V_6 -> V_95 ;
}
}
static void F_95 ( struct V_152 * V_153 ,
struct V_154 * V_4 )
{
struct V_3 * V_151 ;
V_151 = (struct V_3 * ) F_96 ( V_4 -> V_12 ) ;
F_94 ( V_151 , V_4 -> V_155 ) ;
}
static void F_97 ( struct V_156 * V_157 , unsigned int V_38 )
{
}
static T_6 F_98 ( struct V_26 * V_158 ,
T_7 * V_147 ,
struct V_152 * V_153 ,
T_2 V_159 ,
unsigned int V_107 ,
int * V_160 )
{
unsigned int V_161 , V_162 , V_163 , V_164 , V_165 ;
struct V_3 * V_151 = V_158 -> V_96 ;
unsigned int V_95 = V_151 -> V_6 -> V_95 ;
T_10 V_166 = ( T_10 ) * V_147 ;
T_11 V_29 = ( T_11 ) V_151 -> V_6 -> V_29 ;
T_2 V_140 = ( T_2 ) F_99 ( V_166 , V_29 ) ;
T_2 V_129 = V_140 / V_95 ;
T_2 V_48 = V_151 -> V_48 [ V_129 ] ;
T_2 V_167 = V_129 * V_95 + V_95 - V_48 ;
struct V_12 * V_168 [ V_169 ] ;
struct V_170 V_171 [ V_169 ] ;
struct V_156 V_157 = {
. V_168 = V_168 ,
. V_165 = 0 ,
. V_172 = V_169 ,
. V_171 = V_171 ,
. V_107 = V_107 ,
. V_173 = & V_174 ,
. V_175 = F_97 ,
} ;
T_6 V_143 ;
if ( V_151 -> V_52 == V_151 -> V_53 )
return 0 ;
if ( F_100 ( V_153 , & V_157 ) )
return - V_91 ;
if ( V_159 > ( V_95 - V_140 % V_95 ) )
V_159 = V_95 - V_140 % V_95 ;
V_164 = V_151 -> V_6 -> V_29 >> V_16 ;
V_161 = ( V_140 / V_20 ) % V_164 ;
V_162 = V_140 & ~ V_176 ;
V_165 = F_101 (unsigned int, subbuf_pages, spd.nr_pages_max) ;
for ( V_163 = 0 ; V_157 . V_165 < V_165 ; V_157 . V_165 ++ ) {
unsigned int V_177 , V_178 , V_155 ;
unsigned int V_179 = V_140 + V_163 ;
if ( ! V_159 )
break;
V_177 = F_101 (unsigned long, len, PAGE_SIZE - poff) ;
V_155 = V_177 ;
V_157 . V_168 [ V_157 . V_165 ] = V_151 -> V_40 [ V_161 ] ;
V_157 . V_171 [ V_157 . V_165 ] . V_69 = V_162 ;
V_178 = V_179 + V_177 ;
if ( V_178 >= V_167 ) {
V_177 = V_167 - V_179 ;
V_155 = V_177 + V_48 ;
}
V_157 . V_171 [ V_157 . V_165 ] . V_159 = V_177 ;
V_157 . V_171 [ V_157 . V_165 ] . V_155 = V_155 ;
V_159 -= V_177 ;
V_163 += V_177 ;
V_162 = 0 ;
V_161 = ( V_161 + 1 ) % V_164 ;
if ( V_178 >= V_167 ) {
V_157 . V_165 ++ ;
break;
}
}
V_143 = 0 ;
if ( ! V_157 . V_165 )
goto V_180;
V_143 = * V_160 = F_102 ( V_153 , & V_157 ) ;
if ( V_143 < 0 || V_143 < V_163 )
goto V_180;
if ( V_140 + V_143 == V_167 )
V_143 += V_48 ;
V_180:
F_103 ( & V_157 ) ;
return V_143 ;
}
static T_6 F_104 ( struct V_26 * V_158 ,
T_7 * V_147 ,
struct V_152 * V_153 ,
T_2 V_159 ,
unsigned int V_107 )
{
T_6 V_181 ;
int V_143 ;
int V_160 = 0 ;
V_143 = 0 ;
V_181 = 0 ;
while ( V_159 && ! V_181 ) {
V_143 = F_98 ( V_158 , V_147 , V_153 , V_159 , V_107 , & V_160 ) ;
if ( V_143 < 0 )
break;
else if ( ! V_143 ) {
if ( V_107 & V_182 )
V_143 = - V_183 ;
break;
}
* V_147 += V_143 ;
if ( V_143 > V_159 )
V_159 = 0 ;
else
V_159 -= V_143 ;
V_181 += V_160 ;
V_160 = 0 ;
}
if ( V_181 )
return V_181 ;
return V_143 ;
}
static T_12 int F_105 ( void )
{
F_106 ( F_53 , 0 ) ;
return 0 ;
}
