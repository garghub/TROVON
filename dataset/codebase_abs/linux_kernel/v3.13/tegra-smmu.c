static bool inline F_1 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( V_3 < V_2 -> V_6 [ V_4 ] )
break;
if ( V_3 <= V_2 -> V_7 [ V_4 ] )
return true ;
}
return false ;
}
static inline T_2 F_2 ( struct V_1 * V_2 , T_3 V_8 )
{
void T_1 * V_3 = V_2 -> V_9 + V_8 ;
F_3 ( ! F_1 ( V_2 , V_3 ) ) ;
return F_4 ( V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_2 V_10 , T_3 V_8 )
{
void T_1 * V_3 = V_2 -> V_9 + V_8 ;
F_3 ( ! F_1 ( V_2 , V_3 ) ) ;
F_6 ( V_10 , V_3 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
unsigned long V_13 , int V_14 )
{
int V_4 ;
struct V_15 * V_16 = V_12 -> V_16 ;
T_2 V_10 , V_8 , V_17 = F_8 ( V_16 -> V_18 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_9 ( ! V_14 && V_13 ) ;
if ( V_14 && ! V_13 )
return - V_19 ;
if ( ! V_14 )
V_13 = F_10 ( V_12 ) ;
F_11 (i, &map, HWGRP_COUNT) {
V_8 = F_12 ( V_4 ) ;
V_10 = F_2 ( V_2 , V_8 ) ;
if ( V_14 ) {
if ( F_9 ( V_10 & V_17 ) )
goto V_20;
V_10 |= V_17 ;
} else {
F_9 ( ( V_10 & V_17 ) == V_17 ) ;
V_10 &= ~ V_17 ;
}
F_5 ( V_2 , V_10 , V_8 ) ;
}
F_13 ( V_2 ) ;
V_12 -> V_21 = V_13 ;
return 0 ;
V_20:
F_11 (i, &map, HWGRP_COUNT) {
V_8 = F_12 ( V_4 ) ;
V_10 = F_2 ( V_2 , V_8 ) ;
V_10 &= ~ V_17 ;
F_5 ( V_2 , V_10 , V_8 ) ;
}
return - V_22 ;
}
static int F_14 ( struct V_11 * V_12 , T_2 V_13 , int V_14 )
{
T_2 V_10 ;
unsigned long V_23 ;
struct V_15 * V_16 = V_12 -> V_16 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_15 ( & V_2 -> V_24 , V_23 ) ;
V_10 = F_7 ( V_12 , V_13 , V_14 ) ;
F_16 ( & V_2 -> V_24 , V_23 ) ;
return V_10 ;
}
static void F_17 ( struct V_1 * V_2 , int V_25 )
{
T_2 V_10 ;
F_5 ( V_2 , V_26 , V_27 ) ;
F_13 ( V_2 ) ;
V_10 = V_28 |
V_29 ;
F_5 ( V_2 , V_10 , V_30 ) ;
if ( V_25 )
F_5 ( V_2 , V_31 , V_32 ) ;
F_13 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_10 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_33 ; V_4 ++ ) {
struct V_15 * V_16 = & V_2 -> V_16 [ V_4 ] ;
struct V_11 * V_12 ;
F_5 ( V_2 , F_19 ( V_16 -> V_18 ) , V_34 ) ;
V_10 = V_16 -> V_35 ?
F_20 ( V_16 -> V_35 , V_16 -> V_36 ) :
V_37 ;
F_5 ( V_2 , V_10 , V_38 ) ;
F_21 (c, &as->client, list)
F_7 ( V_12 , V_12 -> V_21 , 1 ) ;
}
F_5 ( V_2 , V_2 -> V_39 , V_40 ) ;
F_5 ( V_2 , V_2 -> V_41 , V_42 ) ;
F_5 ( V_2 , V_2 -> V_43 , V_44 ) ;
F_5 ( V_2 , V_2 -> V_45 , V_46 ) ;
F_5 ( V_2 , V_47 , F_22 ( V_48 ) ) ;
F_5 ( V_2 , V_49 , F_22 ( V_50 ) ) ;
F_17 ( V_2 , 1 ) ;
return F_23 ( V_2 -> V_51 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_4 V_52 ,
unsigned long * V_53 , struct V_54 * V_54 , int V_55 )
{
T_2 V_10 ;
unsigned long V_56 = V_55
? F_25 ( V_52 , V_57 )
: F_25 ( V_52 , V_58 ) ;
V_10 = V_59 | F_26 ( V_53 , V_54 ) ;
F_5 ( V_2 , V_10 , V_27 ) ;
F_13 ( V_2 ) ;
V_10 = V_56 |
V_60 |
( V_16 -> V_18 << V_61 ) ;
F_5 ( V_2 , V_10 , V_30 ) ;
F_13 ( V_2 ) ;
}
static void F_27 ( struct V_15 * V_16 , T_4 V_52 )
{
unsigned long V_62 = F_28 ( V_52 ) ;
unsigned long * V_63 = ( unsigned long * ) F_29 ( V_16 -> V_35 ) ;
if ( V_63 [ V_62 ] != F_30 ( V_62 ) ) {
F_31 ( V_16 -> V_2 -> V_64 , L_1 , V_62 ) ;
F_32 ( F_33 ( V_63 [ V_62 ] ) ) ;
F_34 ( F_33 ( V_63 [ V_62 ] ) ) ;
V_63 [ V_62 ] = F_30 ( V_62 ) ;
F_35 ( & V_63 [ V_62 ] , V_16 -> V_35 , sizeof V_63 [ V_62 ] ) ;
F_24 ( V_16 -> V_2 , V_16 , V_52 , & V_63 [ V_62 ] ,
V_16 -> V_35 , 1 ) ;
}
}
static void F_36 ( struct V_15 * V_16 )
{
unsigned V_3 ;
int V_65 ;
struct V_66 * V_64 = V_16 -> V_2 -> V_64 ;
if ( ! V_16 -> V_35 )
return;
V_3 = V_16 -> V_2 -> V_67 ;
V_65 = V_16 -> V_2 -> V_68 ;
while ( V_65 -- > 0 ) {
F_27 ( V_16 , V_3 ) ;
V_3 += V_69 * V_70 ;
}
F_32 ( V_16 -> V_35 ) ;
F_34 ( V_16 -> V_35 ) ;
V_16 -> V_35 = NULL ;
F_37 ( V_64 , V_16 -> V_71 ) ;
V_16 -> V_71 = NULL ;
}
static unsigned long * F_38 ( struct V_15 * V_16 ,
T_4 V_52 , bool V_72 ,
struct V_54 * * V_73 ,
unsigned int * * V_65 )
{
unsigned long V_74 = F_39 ( V_52 ) ;
unsigned long V_62 = F_28 ( V_52 ) ;
unsigned long * V_63 = F_29 ( V_16 -> V_35 ) ;
unsigned long * V_75 ;
if ( V_63 [ V_62 ] != F_30 ( V_62 ) ) {
* V_73 = F_33 ( V_63 [ V_62 ] ) ;
V_75 = F_29 ( * V_73 ) ;
} else if ( ! V_72 ) {
return NULL ;
} else {
int V_76 ;
unsigned long V_3 = F_40 ( V_62 ) ;
F_31 ( V_16 -> V_2 -> V_64 , L_2 , V_62 ) ;
* V_73 = F_41 ( V_77 ) ;
if ( ! * V_73 ) {
F_42 ( V_16 -> V_2 -> V_64 ,
L_3 ) ;
return NULL ;
}
F_43 ( * V_73 ) ;
V_75 = ( unsigned long * ) F_29 ( * V_73 ) ;
for ( V_76 = 0 ; V_76 < V_70 ;
V_76 ++ , V_3 += V_69 ) {
V_75 [ V_76 ] = F_44 ( V_3 ) ;
}
F_35 ( V_75 , * V_73 , V_78 ) ;
V_63 [ V_62 ] = F_45 ( * V_73 ,
V_16 -> V_79 | V_80 ) ;
F_35 ( & V_63 [ V_62 ] , V_16 -> V_35 , sizeof V_63 [ V_62 ] ) ;
F_24 ( V_16 -> V_2 , V_16 , V_52 , & V_63 [ V_62 ] ,
V_16 -> V_35 , 1 ) ;
}
* V_65 = & V_16 -> V_71 [ V_62 ] ;
return & V_75 [ V_74 % V_70 ] ;
}
static void F_46 ( struct V_15 * V_16 ,
T_4 V_52 , unsigned long V_81 )
{
struct V_54 * V_54 ;
unsigned long * V_82 ;
V_54 = F_47 ( V_81 ) ;
V_82 = F_29 ( V_54 ) ;
if ( ! V_82 )
return;
V_82 [ 0 ] = V_52 ;
V_82 [ 1 ] = V_81 << V_83 ;
F_35 ( V_82 , V_54 , sizeof( V_82 [ 0 ] ) * 2 ) ;
}
static inline void F_46 ( struct V_15 * V_16 ,
unsigned long V_3 , unsigned long V_81 )
{
}
static int F_48 ( struct V_15 * V_16 )
{
unsigned long * V_63 , V_23 ;
int V_62 , V_84 = 0 ;
T_2 V_10 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_54 * V_54 ;
unsigned int * V_85 ;
V_85 = F_49 ( V_2 -> V_64 ,
sizeof( V_85 [ 0 ] ) * V_86 ,
V_87 ) ;
V_54 = F_41 ( V_87 | V_88 ) ;
F_15 ( & V_16 -> V_24 , V_23 ) ;
if ( V_16 -> V_35 ) {
V_84 = - V_89 ;
goto V_90;
}
if ( ! V_54 || ! V_85 ) {
F_42 ( V_2 -> V_64 , L_4 , V_91 ) ;
V_84 = - V_92 ;
goto V_90;
}
V_16 -> V_35 = V_54 ;
V_16 -> V_71 = V_85 ;
F_43 ( V_16 -> V_35 ) ;
V_63 = F_29 ( V_16 -> V_35 ) ;
for ( V_62 = 0 ; V_62 < V_86 ; V_62 ++ )
V_63 [ V_62 ] = F_30 ( V_62 ) ;
F_35 ( V_63 , V_16 -> V_35 , V_93 ) ;
V_10 = V_59 | F_26 ( V_63 , V_16 -> V_35 ) ;
F_5 ( V_2 , V_10 , V_27 ) ;
F_13 ( V_16 -> V_2 ) ;
V_10 = V_28 |
V_60 |
( V_16 -> V_18 << V_61 ) ;
F_5 ( V_2 , V_10 , V_30 ) ;
F_13 ( V_16 -> V_2 ) ;
F_16 ( & V_16 -> V_24 , V_23 ) ;
return 0 ;
V_90:
F_16 ( & V_16 -> V_24 , V_23 ) ;
F_37 ( V_2 -> V_64 , V_85 ) ;
if ( V_54 )
F_34 ( V_54 ) ;
return V_84 ;
}
static void F_50 ( struct V_15 * V_16 , T_4 V_52 )
{
unsigned long * V_53 ;
struct V_54 * V_54 ;
unsigned int * V_65 ;
V_53 = F_38 ( V_16 , V_52 , false , & V_54 , & V_65 ) ;
if ( F_9 ( ! V_53 ) )
return;
if ( F_9 ( * V_53 == F_44 ( V_52 ) ) )
return;
* V_53 = F_44 ( V_52 ) ;
F_35 ( V_53 , V_54 , sizeof( * V_53 ) ) ;
F_24 ( V_16 -> V_2 , V_16 , V_52 , V_53 , V_54 , 0 ) ;
if ( ! -- ( * V_65 ) )
F_27 ( V_16 , V_52 ) ;
}
static void F_51 ( struct V_15 * V_16 , T_4 V_52 ,
unsigned long V_81 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long * V_53 ;
unsigned int * V_65 ;
struct V_54 * V_54 ;
V_53 = F_38 ( V_16 , V_52 , true , & V_54 , & V_65 ) ;
if ( F_9 ( ! V_53 ) )
return;
if ( * V_53 == F_44 ( V_52 ) )
( * V_65 ) ++ ;
* V_53 = F_52 ( V_81 , V_16 -> V_94 ) ;
if ( F_53 ( ( * V_53 == F_44 ( V_52 ) ) ) )
( * V_65 ) -- ;
F_35 ( V_53 , V_54 , sizeof( * V_53 ) ) ;
F_24 ( V_2 , V_16 , V_52 , V_53 , V_54 , 0 ) ;
F_46 ( V_16 , V_52 , V_81 ) ;
}
static int F_54 ( struct V_95 * V_96 , unsigned long V_52 ,
T_5 V_97 , T_3 V_98 , int V_99 )
{
struct V_15 * V_16 = V_96 -> V_100 ;
unsigned long V_81 = F_55 ( V_97 ) ;
unsigned long V_23 ;
F_31 ( V_16 -> V_2 -> V_64 , L_5 , V_16 -> V_18 , V_52 , & V_97 ) ;
if ( ! F_56 ( V_81 ) )
return - V_92 ;
F_15 ( & V_16 -> V_24 , V_23 ) ;
F_51 ( V_16 , V_52 , V_81 ) ;
F_16 ( & V_16 -> V_24 , V_23 ) ;
return 0 ;
}
static T_3 F_57 ( struct V_95 * V_96 , unsigned long V_52 ,
T_3 V_98 )
{
struct V_15 * V_16 = V_96 -> V_100 ;
unsigned long V_23 ;
F_31 ( V_16 -> V_2 -> V_64 , L_6 , V_16 -> V_18 , V_52 ) ;
F_15 ( & V_16 -> V_24 , V_23 ) ;
F_50 ( V_16 , V_52 ) ;
F_16 ( & V_16 -> V_24 , V_23 ) ;
return V_69 ;
}
static T_5 F_58 ( struct V_95 * V_96 ,
T_4 V_52 )
{
struct V_15 * V_16 = V_96 -> V_100 ;
unsigned long * V_53 ;
unsigned int * V_65 ;
struct V_54 * V_54 ;
unsigned long V_81 ;
unsigned long V_23 ;
F_15 ( & V_16 -> V_24 , V_23 ) ;
V_53 = F_38 ( V_16 , V_52 , true , & V_54 , & V_65 ) ;
V_81 = * V_53 & V_101 ;
F_9 ( ! F_56 ( V_81 ) ) ;
F_31 ( V_16 -> V_2 -> V_64 ,
L_7 , ( unsigned long long ) V_52 ,
V_81 , V_16 -> V_18 ) ;
F_16 ( & V_16 -> V_24 , V_23 ) ;
return F_59 ( V_81 ) ;
}
static int F_60 ( struct V_95 * V_96 ,
unsigned long V_102 )
{
return 0 ;
}
static int F_61 ( struct V_95 * V_96 ,
struct V_66 * V_64 )
{
struct V_15 * V_16 = V_96 -> V_100 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_11 * V_103 , * V_12 ;
T_2 V_13 ;
int V_84 ;
V_103 = F_49 ( V_2 -> V_64 , sizeof( * V_12 ) , V_87 ) ;
if ( ! V_103 )
return - V_92 ;
V_103 -> V_64 = V_64 ;
V_103 -> V_16 = V_16 ;
V_13 = ( unsigned long ) V_64 -> V_104 ;
if ( ! V_13 )
return - V_19 ;
V_84 = F_62 ( V_103 , V_13 ) ;
if ( V_84 )
goto V_105;
F_63 ( & V_16 -> V_106 ) ;
F_21 (c, &as->client, list) {
if ( V_12 -> V_64 == V_64 ) {
F_42 ( V_2 -> V_64 ,
L_8 , F_64 ( V_12 -> V_64 ) ) ;
V_84 = - V_19 ;
goto V_107;
}
}
F_65 ( & V_103 -> V_108 , & V_16 -> V_103 ) ;
F_66 ( & V_16 -> V_106 ) ;
if ( V_13 & V_109 ) {
struct V_54 * V_54 ;
V_54 = V_16 -> V_2 -> V_110 ;
F_51 ( V_16 , 0 , F_67 ( V_54 ) ) ;
F_68 ( L_9 ) ;
}
F_31 ( V_2 -> V_64 , L_10 , F_64 ( V_64 ) ) ;
return 0 ;
V_107:
F_69 ( V_103 ) ;
F_66 ( & V_16 -> V_106 ) ;
V_105:
F_37 ( V_2 -> V_64 , V_103 ) ;
return V_84 ;
}
static void F_70 ( struct V_95 * V_96 ,
struct V_66 * V_64 )
{
struct V_15 * V_16 = V_96 -> V_100 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_11 * V_12 ;
F_63 ( & V_16 -> V_106 ) ;
F_21 (c, &as->client, list) {
if ( V_12 -> V_64 == V_64 ) {
F_69 ( V_12 ) ;
F_71 ( & V_12 -> V_108 ) ;
F_37 ( V_2 -> V_64 , V_12 ) ;
V_12 -> V_16 = NULL ;
F_31 ( V_2 -> V_64 ,
L_11 , F_64 ( V_12 -> V_64 ) ) ;
goto V_111;
}
}
F_42 ( V_2 -> V_64 , L_12 , F_64 ( V_64 ) ) ;
V_111:
F_66 ( & V_16 -> V_106 ) ;
}
static int F_72 ( struct V_95 * V_96 )
{
int V_4 , V_84 = - V_89 ;
unsigned long V_23 ;
struct V_15 * V_16 ;
struct V_1 * V_2 = V_112 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_33 ; V_4 ++ ) {
V_16 = & V_2 -> V_16 [ V_4 ] ;
if ( V_16 -> V_35 )
continue;
V_84 = F_48 ( V_16 ) ;
if ( ! V_84 )
goto V_113;
if ( V_84 != - V_89 )
break;
}
if ( V_4 == V_2 -> V_33 )
F_42 ( V_2 -> V_64 , L_13 ) ;
return V_84 ;
V_113:
F_15 ( & V_2 -> V_24 , V_23 ) ;
F_5 ( V_2 , F_19 ( V_16 -> V_18 ) , V_34 ) ;
F_5 ( V_2 ,
F_20 ( V_16 -> V_35 , V_16 -> V_36 ) , V_38 ) ;
F_13 ( V_2 ) ;
F_16 ( & V_2 -> V_24 , V_23 ) ;
V_96 -> V_100 = V_16 ;
V_96 -> V_114 . V_115 = V_2 -> V_67 ;
V_96 -> V_114 . V_116 = V_2 -> V_67 +
V_2 -> V_68 * V_69 - 1 ;
V_96 -> V_114 . V_117 = true ;
F_31 ( V_2 -> V_64 , L_14 , V_16 ) ;
return 0 ;
}
static void F_73 ( struct V_95 * V_96 )
{
struct V_15 * V_16 = V_96 -> V_100 ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned long V_23 ;
F_15 ( & V_16 -> V_24 , V_23 ) ;
if ( V_16 -> V_35 ) {
F_63 ( & V_2 -> V_24 ) ;
F_5 ( V_2 , F_19 ( V_16 -> V_18 ) , V_34 ) ;
F_5 ( V_2 , V_37 , V_38 ) ;
F_13 ( V_2 ) ;
F_66 ( & V_2 -> V_24 ) ;
F_36 ( V_16 ) ;
}
if ( ! F_74 ( & V_16 -> V_103 ) ) {
struct V_11 * V_12 ;
F_21 (c, &as->client, list)
F_70 ( V_96 , V_12 -> V_64 ) ;
}
F_16 ( & V_16 -> V_24 , V_23 ) ;
V_96 -> V_100 = NULL ;
F_31 ( V_2 -> V_64 , L_14 , V_16 ) ;
}
static T_6 F_75 ( struct V_118 * V_118 ,
const char T_7 * V_119 ,
T_3 V_65 , T_8 * V_120 )
{
struct V_121 * V_122 ;
struct V_1 * V_2 ;
int V_4 ;
enum {
V_123 = 0 ,
V_124 ,
V_125 ,
};
const char * const V_126 [] = {
[ V_123 ] = L_15 ,
[ V_124 ] = L_16 ,
[ V_125 ] = L_17 ,
} ;
char V_127 [] = L_17 ;
T_2 V_10 ;
T_3 V_8 ;
V_65 = F_76 ( T_3 , V_65 , sizeof( V_127 ) ) ;
if ( F_77 ( V_127 , V_119 , V_65 ) )
return - V_19 ;
for ( V_4 = 0 ; V_4 < F_78 ( V_126 ) ; V_4 ++ )
if ( strncmp ( V_127 , V_126 [ V_4 ] ,
strlen ( V_126 [ V_4 ] ) ) == 0 )
break;
if ( V_4 == F_78 ( V_126 ) )
return - V_19 ;
V_122 = F_79 ( V_118 ) -> V_128 ;
V_2 = V_122 -> V_2 ;
V_8 = F_22 ( V_122 -> V_129 ) ;
V_10 = F_2 ( V_2 , V_8 ) ;
switch ( V_4 ) {
case V_123 :
V_10 &= ~ V_130 ;
V_10 &= ~ V_131 ;
F_5 ( V_2 , V_10 , V_8 ) ;
break;
case V_124 :
V_10 |= V_130 ;
V_10 &= ~ V_131 ;
F_5 ( V_2 , V_10 , V_8 ) ;
break;
case V_125 :
V_10 |= V_131 ;
F_5 ( V_2 , V_10 , V_8 ) ;
V_10 &= ~ V_131 ;
F_5 ( V_2 , V_10 , V_8 ) ;
break;
default:
F_80 () ;
break;
}
F_31 ( V_2 -> V_64 , L_18 , V_91 ,
V_10 , F_2 ( V_2 , V_8 ) , V_8 ) ;
return V_65 ;
}
static int F_81 ( struct V_132 * V_133 , void * V_134 )
{
struct V_121 * V_122 = V_133 -> V_135 ;
struct V_1 * V_2 = V_122 -> V_2 ;
int V_4 ;
const char * const V_136 [] = { L_19 , L_20 , } ;
for ( V_4 = 0 ; V_4 < F_78 ( V_136 ) ; V_4 ++ ) {
T_2 V_10 ;
T_3 V_8 ;
V_8 = F_82 ( V_122 -> V_137 , V_122 -> V_129 , V_4 ) ;
V_10 = F_2 ( V_2 , V_8 ) ;
F_83 ( V_133 , L_21 , V_136 [ V_4 ] , V_10 ) ;
F_31 ( V_2 -> V_64 , L_22 , V_91 ,
V_136 [ V_4 ] , V_10 , V_8 ) ;
}
F_83 ( V_133 , L_23 ) ;
return 0 ;
}
static int F_84 ( struct V_138 * V_138 , struct V_118 * V_118 )
{
return F_85 ( V_118 , F_81 , V_138 -> V_128 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_87 ( V_2 -> V_139 ) ;
F_88 ( V_2 -> V_140 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_4 ;
T_3 V_98 ;
struct V_141 * V_142 ;
V_98 = F_78 ( V_143 ) * F_78 ( V_144 ) *
sizeof( * V_2 -> V_140 ) ;
V_2 -> V_140 = F_90 ( V_98 , V_87 ) ;
if ( ! V_2 -> V_140 )
return;
V_142 = F_91 ( F_64 ( V_2 -> V_64 ) , NULL ) ;
if ( ! V_142 )
goto V_90;
V_2 -> V_139 = V_142 ;
for ( V_4 = 0 ; V_4 < F_78 ( V_143 ) ; V_4 ++ ) {
int V_145 ;
struct V_141 * V_137 ;
V_137 = F_91 ( V_143 [ V_4 ] , V_142 ) ;
if ( ! V_137 )
goto V_90;
for ( V_145 = 0 ; V_145 < F_78 ( V_144 ) ; V_145 ++ ) {
struct V_141 * V_129 ;
struct V_121 * V_122 ;
V_122 = V_2 -> V_140 ;
V_122 += V_4 * F_78 ( V_143 ) + V_145 ;
V_122 -> V_2 = V_2 ;
V_122 -> V_137 = V_4 ;
V_122 -> V_129 = V_145 ;
V_129 = F_92 ( V_144 [ V_145 ] ,
V_146 | V_147 , V_137 ,
( void * ) V_122 ,
& V_148 ) ;
if ( ! V_129 )
goto V_90;
}
}
return;
V_90:
F_86 ( V_2 ) ;
}
static int F_93 ( struct V_66 * V_64 )
{
struct V_1 * V_2 = F_94 ( V_64 ) ;
V_2 -> V_39 = F_2 ( V_2 , V_40 ) ;
V_2 -> V_41 = F_2 ( V_2 , V_42 ) ;
V_2 -> V_43 = F_2 ( V_2 , V_44 ) ;
V_2 -> V_45 = F_2 ( V_2 , V_46 ) ;
return 0 ;
}
static int F_95 ( struct V_66 * V_64 )
{
struct V_1 * V_2 = F_94 ( V_64 ) ;
unsigned long V_23 ;
int V_84 ;
F_15 ( & V_2 -> V_24 , V_23 ) ;
V_84 = F_18 ( V_2 ) ;
F_16 ( & V_2 -> V_24 , V_23 ) ;
return V_84 ;
}
static int F_96 ( struct V_149 * V_150 )
{
struct V_1 * V_2 ;
struct V_66 * V_64 = & V_150 -> V_64 ;
int V_4 , V_151 , V_84 = 0 ;
T_4 V_152 ( V_153 ) ;
T_3 V_98 , V_152 ( V_154 ) ;
if ( V_112 )
return - V_155 ;
F_97 ( V_83 != V_156 ) ;
if ( F_98 ( V_64 -> V_157 , L_24 , & V_151 ) )
return - V_158 ;
V_98 = sizeof( * V_2 ) + V_151 * sizeof( * V_2 -> V_16 ) ;
V_2 = F_49 ( V_64 , V_98 , V_87 ) ;
if ( ! V_2 ) {
F_42 ( V_64 , L_25 ) ;
return - V_92 ;
}
V_2 -> V_5 = V_150 -> V_159 ;
V_2 -> V_6 = F_49 ( V_64 , 2 * V_2 -> V_5 * sizeof( * V_2 -> V_6 ) ,
V_87 ) ;
V_2 -> V_7 = V_2 -> V_6 + V_2 -> V_5 ;
if ( ! V_2 -> V_6 )
return - V_92 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_160 * V_161 ;
V_161 = F_99 ( V_150 , V_162 , V_4 ) ;
V_2 -> V_6 [ V_4 ] = F_100 ( & V_150 -> V_64 , V_161 ) ;
if ( F_101 ( V_2 -> V_6 [ V_4 ] ) )
return F_102 ( V_2 -> V_6 [ V_4 ] ) ;
V_2 -> V_7 [ V_4 ] = V_2 -> V_6 [ V_4 ] + F_103 ( V_161 ) - 1 ;
}
V_2 -> V_9 = ( void T_1 * ) ( ( T_2 ) V_2 -> V_6 [ 0 ] & V_163 ) ;
V_84 = F_104 ( V_64 -> V_157 , NULL , 0 , NULL , & V_153 , & V_154 ) ;
if ( V_84 )
return - V_158 ;
if ( V_154 & V_164 )
return - V_19 ;
V_154 >>= V_156 ;
if ( ! V_154 )
return - V_19 ;
V_2 -> V_51 = F_105 ( V_64 -> V_157 , L_26 , 0 ) ;
if ( ! V_2 -> V_51 )
return - V_158 ;
V_2 -> V_64 = V_64 ;
V_2 -> V_33 = V_151 ;
V_2 -> V_67 = V_153 ;
V_2 -> V_68 = V_154 ;
V_2 -> V_39 = ~ 0 ;
V_2 -> V_41 = ~ 0 ;
V_2 -> V_43 = ~ 0 ;
V_2 -> V_45 = 0 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_33 ; V_4 ++ ) {
struct V_15 * V_16 = & V_2 -> V_16 [ V_4 ] ;
V_16 -> V_2 = V_2 ;
V_16 -> V_18 = V_4 ;
V_16 -> V_36 = V_165 ;
V_16 -> V_79 = V_166 ;
V_16 -> V_94 = V_167 ;
F_106 ( & V_16 -> V_24 ) ;
F_106 ( & V_16 -> V_106 ) ;
F_107 ( & V_16 -> V_103 ) ;
}
F_106 ( & V_2 -> V_24 ) ;
V_84 = F_18 ( V_2 ) ;
if ( V_84 )
return V_84 ;
F_108 ( V_150 , V_2 ) ;
V_2 -> V_110 = F_41 ( V_87 ) ;
if ( ! V_2 -> V_110 )
return - V_92 ;
F_89 ( V_2 ) ;
V_112 = V_2 ;
F_109 ( & V_168 , & V_169 ) ;
return 0 ;
}
static int F_110 ( struct V_149 * V_150 )
{
struct V_1 * V_2 = F_111 ( V_150 ) ;
int V_4 ;
F_86 ( V_2 ) ;
F_5 ( V_2 , V_170 , V_32 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_33 ; V_4 ++ )
F_36 ( & V_2 -> V_16 [ V_4 ] ) ;
F_34 ( V_2 -> V_110 ) ;
V_112 = NULL ;
return 0 ;
}
static int F_112 ( void )
{
return F_113 ( & V_171 ) ;
}
static void T_9 F_114 ( void )
{
F_115 ( & V_171 ) ;
}
