static int F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
V_2 -> V_5 -> V_4 = V_4 ;
V_2 -> V_5 -> V_6 = V_7 ;
F_2 ( V_2 -> V_8 , V_2 -> V_9 -> V_10 + V_11 ) ;
return V_2 -> V_5 -> V_6 ;
}
static int F_3 ( struct V_1 * V_2 , enum V_3 V_4 )
{
int V_6 ;
if ( F_4 ( & V_2 -> V_12 ) )
return V_13 ;
V_6 = F_1 ( V_2 , V_4 ) ;
F_5 ( & V_2 -> V_12 ) ;
return V_6 ;
}
static int F_6 ( int V_6 )
{
switch ( V_6 ) {
case V_14 :
return - V_15 ;
case V_16 :
return - V_17 ;
case V_13 :
return - V_18 ;
default:
return - V_19 ;
}
}
static int F_7 ( unsigned long V_20 , unsigned long V_21 ,
unsigned int V_22 , int V_23 ,
struct V_24 * V_25 [ V_26 ] ,
unsigned int * V_27 )
{
int V_28 ;
int V_29 = ( ( V_21 - V_20 ) >> V_30 ) + 1 ;
if ( V_29 > V_26 ) {
V_29 = V_26 ;
* V_27 = V_31 ;
} else {
* V_27 = V_22 ;
}
V_28 = F_8 (
V_20 , V_29 , ! V_23 , V_25 ) ;
if ( V_28 <= 0 )
return - V_32 ;
if ( V_28 < V_29 )
* V_27 = V_31 ;
return V_28 ;
}
static void F_9 ( struct V_24 * * V_25 , int V_33 ,
int V_23 , T_1 V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_33 ; V_35 ++ ) {
if ( ! V_23 && V_34 > 0 )
F_10 ( V_25 [ V_35 ] ) ;
F_11 ( V_25 [ V_35 ] ) ;
}
}
static void F_12 (
struct V_24 * * V_25 , int V_33 ,
unsigned long V_36 , unsigned long V_37 ,
unsigned long V_20 , unsigned long V_21 ,
unsigned int V_27 , int V_23 ,
struct V_38 * V_39 )
{
unsigned long V_40 = F_13 ( V_25 [ 0 ] ) ;
unsigned long V_41 = V_40 ;
int V_42 = 0 ;
int V_35 = 1 ;
int V_43 = V_20 == V_21
? ( int ) ( V_37 - V_36 )
: ( V_31 - ( V_36 & ~ V_44 ) ) ;
V_39 -> V_45 . V_46 [ 0 ] = ( V_47 ) ( V_40 | ( V_36 & ~ V_44 ) ) ;
V_39 -> V_45 . V_48 [ 0 ] = V_43 ;
for (; V_35 < V_33 ; ++ V_35 ) {
V_40 = F_13 ( V_25 [ V_35 ] ) ;
V_43 = ( V_35 == V_33 - 1 ) ?
V_27 : V_31 ;
if ( V_40 == V_41 + V_31 ) {
V_39 -> V_45 . V_48 [ V_42 ] += V_43 ;
} else {
++ V_42 ;
V_39 -> V_45 . V_46 [ V_42 ] = ( V_47 ) V_40 ;
V_39 -> V_45 . V_48 [ V_42 ] = V_43 ;
}
V_41 = V_40 ;
}
V_39 -> V_45 . V_49 = V_42 + 1 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned long V_36 , unsigned long V_37 , int V_23 ,
unsigned long V_21 , unsigned int V_22 ,
T_1 * V_34 , int * V_6 )
{
static struct V_24 * V_25 [ V_26 ] ;
unsigned long V_20 = V_36 & V_44 ;
unsigned int V_27 ;
int V_33 = F_7 ( V_20 , V_21 ,
V_22 , V_23 ,
V_25 , & V_27 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( F_4 ( & V_2 -> V_12 ) )
return - V_50 ;
F_12 ( V_25 , V_33 , V_36 , V_37 ,
V_20 , V_21 , V_27 , V_23 ,
V_2 -> V_5 ) ;
* V_6 = F_1 ( V_2 ,
V_23 ? V_51 : V_52 ) ;
* V_34 = V_2 -> V_5 -> V_45 . V_34 ;
F_9 ( V_25 , V_33 , V_23 , * V_34 ) ;
F_5 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_23 )
{
T_2 V_53 = V_23 ? V_54 : V_55 ;
F_16 ( V_53 , & V_2 -> V_56 ) ;
( void ) F_3 ( V_2 ,
V_23 ? V_57 : V_58 ) ;
while ( F_17 ( V_53 , & V_2 -> V_56 ) ) {
if ( F_18 (
V_2 -> V_59 ,
! F_17 ( V_53 , & V_2 -> V_56 ) ) )
return - V_50 ;
if ( F_17 ( V_60 , & V_2 -> V_56 ) )
return - V_18 ;
}
return 0 ;
}
static T_3 F_19 ( struct V_61 * V_62 ,
char T_4 * V_63 , T_5 V_64 , int V_23 )
{
struct V_1 * V_2 = V_62 -> V_65 ;
int V_66 = 0 , V_28 = - V_19 ;
unsigned long V_36 , V_37 , V_21 ;
unsigned int V_22 ;
if ( F_20 ( F_17 ( V_60 , & V_2 -> V_56 ) ) )
return - V_18 ;
if ( F_20 ( V_64 == 0 ) )
return 0 ;
if ( F_20 ( ! F_21 ( V_23 ? V_67 : V_68 ,
V_63 , V_64 ) ) )
return - V_32 ;
V_36 = ( unsigned long ) V_63 ;
V_37 = V_36 + V_64 ;
V_21 = ( V_37 - 1 ) & V_44 ;
V_22 = ( ( V_37 - 1 ) & ~ V_44 ) + 1 ;
while ( V_36 < V_37 ) {
T_1 V_34 ;
int V_6 ;
V_28 = F_14 ( V_2 , V_36 , V_37 , V_23 ,
V_21 , V_22 , & V_34 ,
& V_6 ) ;
if ( V_28 < 0 )
break;
if ( V_34 > 0 ) {
V_66 += V_34 ;
V_36 += V_34 ;
}
if ( V_6 > 0 )
continue;
if ( V_6 == 0 ) {
V_28 = 0 ;
break;
}
if ( V_66 > 0 ) {
if ( V_6 != V_14 )
F_22 ( L_1 ,
V_6 , V_23 ? L_2 : L_3 ) ;
break;
}
if ( V_6 != V_14 ||
( V_62 -> V_69 & V_70 ) != 0 ) {
V_28 = F_6 ( V_6 ) ;
break;
}
V_6 = F_15 ( V_2 , V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_66 > 0 )
return V_66 ;
return V_28 ;
}
static T_3 F_23 ( struct V_61 * V_62 , char T_4 * V_63 ,
T_5 V_64 , T_6 * V_71 )
{
return F_19 ( V_62 , V_63 , V_64 ,
0 ) ;
}
static T_3 F_24 ( struct V_61 * V_62 ,
const char T_4 * V_63 , T_5 V_64 ,
T_6 * V_71 )
{
return F_19 ( V_62 ,
( char T_4 * ) V_63 , V_64 ,
1 ) ;
}
static unsigned int F_25 ( struct V_61 * V_62 , T_7 * V_72 )
{
struct V_1 * V_2 = V_62 -> V_65 ;
unsigned int V_73 = 0 ;
int V_6 ;
F_26 ( V_62 , & V_2 -> V_59 , V_72 ) ;
V_6 = F_3 ( V_2 , V_74 ) ;
if ( V_6 < 0 )
return - V_50 ;
if ( V_6 & V_75 )
V_73 |= V_76 | V_77 ;
if ( V_6 & V_78 )
V_73 |= V_79 | V_80 ;
if ( V_6 & V_81 )
V_73 |= V_82 ;
if ( F_17 ( V_60 , & V_2 -> V_56 ) )
V_73 |= V_83 ;
return V_73 ;
}
static void F_27 ( struct V_84 * V_9 ,
T_2 V_8 , T_2 V_56 )
{
struct V_1 * V_2 ;
if ( F_28 ( V_8 >= V_9 -> V_85 ) )
return;
V_2 = V_9 -> V_86 [ V_8 ] ;
if ( ! V_2 )
return;
V_2 -> V_87 |= V_56 ;
if ( V_2 -> V_88 || V_2 -> V_89
|| V_9 -> V_90 == V_2 )
return;
V_2 -> V_89 = V_9 -> V_90 ;
if ( V_9 -> V_90 )
V_9 -> V_90 -> V_88 = V_2 ;
V_9 -> V_90 = V_2 ;
}
static void F_29 ( struct V_84 * V_9 ,
struct V_1 * V_2 ) {
if ( V_2 -> V_88 )
V_2 -> V_88 -> V_89 = V_2 -> V_89 ;
if ( V_2 -> V_89 )
V_2 -> V_89 -> V_88 = V_2 -> V_88 ;
if ( V_2 == V_9 -> V_90 )
V_9 -> V_90 = V_2 -> V_89 ;
V_2 -> V_88 = NULL ;
V_2 -> V_89 = NULL ;
}
static struct V_1 * F_30 (
struct V_84 * V_9 , int * V_91 )
{
struct V_1 * V_2 ;
unsigned long V_56 ;
F_31 ( & V_9 -> V_12 , V_56 ) ;
V_2 = V_9 -> V_90 ;
if ( V_2 ) {
* V_91 = V_2 -> V_87 ;
V_2 -> V_87 = 0 ;
V_9 -> V_90 = V_2 -> V_89 ;
if ( V_9 -> V_90 )
V_9 -> V_90 -> V_88 = NULL ;
V_2 -> V_89 = NULL ;
}
F_32 ( & V_9 -> V_12 , V_56 ) ;
return V_2 ;
}
static void F_33 ( unsigned long V_92 )
{
struct V_84 * V_9 = V_93 ;
struct V_1 * V_2 ;
int V_91 ;
while ( ( V_2 = F_30 ( V_9 , & V_91 ) ) != NULL ) {
if ( V_91 & V_94 ) {
V_2 -> V_56 = 1 << V_60 ;
} else {
if ( V_91 & V_95 )
F_34 ( V_55 , & V_2 -> V_56 ) ;
if ( V_91 & V_96 )
F_34 ( V_54 , & V_2 -> V_56 ) ;
}
F_35 ( & V_2 -> V_59 ) ;
}
}
static T_8 F_36 ( int V_97 , void * V_98 )
{
T_2 V_66 ;
T_2 V_35 ;
unsigned long V_56 ;
struct V_84 * V_9 = V_98 ;
if ( V_9 != V_93 )
return V_99 ;
F_31 ( & V_9 -> V_12 , V_56 ) ;
V_66 = F_37 ( V_9 -> V_10 + V_100 ) ;
if ( V_66 == 0 ) {
F_32 ( & V_9 -> V_12 , V_56 ) ;
return V_99 ;
}
if ( V_66 > V_101 )
V_66 = V_101 ;
for ( V_35 = 0 ; V_35 < V_66 ; ++ V_35 )
F_27 ( V_9 ,
V_9 -> V_102 -> V_103 [ V_35 ] . V_8 ,
V_9 -> V_102 -> V_103 [ V_35 ] . V_56 ) ;
F_32 ( & V_9 -> V_12 , V_56 ) ;
F_38 ( & V_104 ) ;
return V_105 ;
}
static int F_39 ( struct V_84 * V_9 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 -> V_85 ; ++ V_8 )
if ( ! V_9 -> V_86 [ V_8 ] )
return V_8 ;
{
T_2 V_106 = 2 * V_9 -> V_85 ;
struct V_1 * * V_86 =
F_40 ( V_106 , sizeof( * V_86 ) , V_107 ) ;
if ( ! V_86 )
return - V_17 ;
memcpy ( V_86 , V_9 -> V_86 , sizeof( * V_86 ) * V_9 -> V_85 ) ;
F_41 ( V_9 -> V_86 ) ;
V_9 -> V_86 = V_86 ;
V_8 = V_9 -> V_85 ;
V_9 -> V_85 = V_106 ;
}
return V_8 ;
}
static int F_42 ( struct V_108 * V_108 , struct V_61 * V_61 )
{
struct V_84 * V_9 = V_93 ;
unsigned long V_56 ;
int V_8 ;
int V_6 ;
struct V_1 * V_2 = F_43 ( sizeof( * V_2 ) , V_109 ) ;
if ( V_2 == NULL )
return - V_17 ;
V_2 -> V_9 = V_9 ;
F_44 ( & V_2 -> V_12 ) ;
F_45 ( & V_2 -> V_59 ) ;
V_2 -> V_5 =
(struct V_38 * ) F_46 ( V_109 ) ;
if ( ! V_2 -> V_5 ) {
V_6 = - V_17 ;
goto V_110;
}
F_31 ( & V_9 -> V_12 , V_56 ) ;
V_8 = F_39 ( V_9 ) ;
if ( V_8 < 0 ) {
V_6 = V_8 ;
goto V_111;
}
V_9 -> V_86 [ V_8 ] = V_2 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_5 -> V_8 = V_8 ;
V_9 -> V_102 -> V_112 . V_113 =
V_26 ;
V_9 -> V_102 -> V_112 . V_114 =
( V_47 ) ( unsigned long ) F_47 ( V_2 -> V_5 ) ;
V_6 = F_1 ( V_2 , V_115 ) ;
F_32 ( & V_9 -> V_12 , V_56 ) ;
if ( V_6 < 0 )
goto V_116;
V_61 -> V_65 = V_2 ;
return 0 ;
V_116:
F_31 ( & V_9 -> V_12 , V_56 ) ;
V_9 -> V_86 [ V_8 ] = NULL ;
V_111:
F_32 ( & V_9 -> V_12 , V_56 ) ;
F_48 ( ( unsigned long ) V_2 -> V_5 ) ;
V_110:
F_41 ( V_2 ) ;
return V_6 ;
}
static int F_49 ( struct V_108 * V_108 , struct V_61 * V_62 )
{
unsigned long V_56 ;
struct V_1 * V_2 = V_62 -> V_65 ;
struct V_84 * V_9 = V_2 -> V_9 ;
( void ) F_3 ( V_2 , V_117 ) ;
F_31 ( & V_9 -> V_12 , V_56 ) ;
V_9 -> V_86 [ V_2 -> V_8 ] = NULL ;
F_29 ( V_9 , V_2 ) ;
F_32 ( & V_9 -> V_12 , V_56 ) ;
V_62 -> V_65 = NULL ;
F_48 ( ( unsigned long ) V_2 -> V_5 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_118 * V_119 )
{
char * V_24 ;
struct V_84 * V_9 = V_93 ;
int V_120 = F_51 ( & V_119 -> V_9 , V_9 -> V_97 ,
F_36 ,
V_121 , L_4 , V_9 ) ;
if ( V_120 ) {
F_52 ( & V_119 -> V_9 , L_5 ) ;
return V_120 ;
}
V_120 = F_53 ( & V_84 ) ;
if ( V_120 ) {
F_52 ( & V_119 -> V_9 , L_6 ) ;
return V_120 ;
}
V_9 -> V_90 = NULL ;
V_9 -> V_85 = V_122 ;
V_9 -> V_86 = F_40 ( V_9 -> V_85 , sizeof( * V_9 -> V_86 ) ,
V_109 ) ;
if ( ! V_9 -> V_86 )
return - V_17 ;
if ( F_28 ( sizeof( * V_9 -> V_102 ) > V_31 ) )
return - V_17 ;
V_24 = ( char * ) F_46 ( V_109 ) ;
if ( ! V_24 ) {
F_41 ( V_9 -> V_86 ) ;
return - V_17 ;
}
V_9 -> V_102 = (struct V_123 * ) V_24 ;
{
V_47 V_124 = F_47 ( & V_9 -> V_102 -> V_103 ) ;
F_2 ( ( T_2 ) ( unsigned long ) ( V_124 >> 32 ) ,
V_9 -> V_10 + V_125 ) ;
F_2 ( ( T_2 ) ( unsigned long ) V_124 ,
V_9 -> V_10 + V_126 ) ;
F_2 ( ( T_2 ) V_101 ,
V_9 -> V_10 + V_127 ) ;
V_124 = F_47 ( & V_9 -> V_102 -> V_112 ) ;
F_2 ( ( T_2 ) ( unsigned long ) ( V_124 >> 32 ) ,
V_9 -> V_10 + V_128 ) ;
F_2 ( ( T_2 ) ( unsigned long ) V_124 ,
V_9 -> V_10 + V_129 ) ;
}
return 0 ;
}
static void F_54 ( struct V_118 * V_119 )
{
struct V_84 * V_9 = V_93 ;
F_55 ( & V_84 ) ;
F_41 ( V_9 -> V_86 ) ;
F_48 ( ( unsigned long ) V_9 -> V_102 ) ;
}
static int F_56 ( struct V_118 * V_119 )
{
int V_120 ;
struct V_130 * V_131 ;
struct V_84 * V_9 = V_93 ;
if ( F_28 ( sizeof( struct V_38 ) > V_31 ) )
return - V_17 ;
F_28 ( V_9 -> V_10 != NULL ) ;
F_57 ( & V_9 -> V_12 ) ;
V_131 = F_58 ( V_119 , V_132 , 0 ) ;
if ( V_131 == NULL || F_59 ( V_131 ) < V_31 ) {
F_52 ( & V_119 -> V_9 , L_7 ) ;
return - V_19 ;
}
V_9 -> V_10 = F_60 ( & V_119 -> V_9 , V_131 -> V_133 , V_31 ) ;
if ( V_9 -> V_10 == NULL ) {
F_52 ( & V_119 -> V_9 , L_8 ) ;
return - V_19 ;
}
V_131 = F_58 ( V_119 , V_134 , 0 ) ;
if ( V_131 == NULL ) {
V_120 = - V_19 ;
goto error;
}
V_9 -> V_97 = V_131 -> V_133 ;
F_2 ( ( T_2 ) V_135 , V_9 -> V_10 + V_136 ) ;
V_9 -> V_137 = F_37 ( V_9 -> V_10 + V_136 ) ;
if ( F_28 ( V_9 -> V_137 < V_138 ) )
return - V_19 ;
V_120 = F_50 ( V_119 ) ;
if ( ! V_120 )
return 0 ;
error:
V_9 -> V_10 = NULL ;
return V_120 ;
}
static int F_61 ( struct V_118 * V_119 )
{
struct V_84 * V_9 = V_93 ;
F_54 ( V_119 ) ;
V_9 -> V_10 = NULL ;
return 0 ;
}
