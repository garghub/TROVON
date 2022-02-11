static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
F_2 ( V_3 < 0x10 ) ;
if ( V_3 < 0x3c )
return F_3 ( V_2 -> V_4 [ 0 ] + V_3 - 0x10 ) ;
F_2 ( V_3 < 0x1f0 ) ;
if ( V_3 < 0x200 )
return F_3 ( V_2 -> V_4 [ 1 ] + V_3 - 0x1f0 ) ;
F_2 ( V_3 < 0x228 ) ;
if ( V_3 < 0x284 )
return F_3 ( V_2 -> V_4 [ 2 ] + V_3 - 0x228 ) ;
F_4 () ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_5 , T_2 V_3 )
{
F_2 ( V_3 < 0x10 ) ;
if ( V_3 < 0x3c ) {
F_6 ( V_5 , V_2 -> V_4 [ 0 ] + V_3 - 0x10 ) ;
return;
}
F_2 ( V_3 < 0x1f0 ) ;
if ( V_3 < 0x200 ) {
F_6 ( V_5 , V_2 -> V_4 [ 1 ] + V_3 - 0x1f0 ) ;
return;
}
F_2 ( V_3 < 0x228 ) ;
if ( V_3 < 0x284 ) {
F_6 ( V_5 , V_2 -> V_4 [ 2 ] + V_3 - 0x228 ) ;
return;
}
F_4 () ;
}
static int F_7 ( struct V_6 * V_7 ,
unsigned long V_8 , int V_9 )
{
int V_10 ;
struct V_11 * V_12 = V_7 -> V_12 ;
T_1 V_5 , V_3 , V_13 = F_8 ( V_12 -> V_14 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
F_9 ( ! V_9 && V_8 ) ;
if ( V_9 && ! V_8 )
return - V_15 ;
if ( ! V_9 )
V_8 = F_10 ( V_7 ) ;
F_11 (i, &map, HWGRP_COUNT) {
V_3 = F_12 ( V_10 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
if ( V_9 ) {
if ( F_9 ( V_5 & V_13 ) )
goto V_16;
V_5 |= V_13 ;
} else {
F_9 ( ( V_5 & V_13 ) == V_13 ) ;
V_5 &= ~ V_13 ;
}
F_5 ( V_2 , V_5 , V_3 ) ;
}
F_13 ( V_2 ) ;
V_7 -> V_17 = V_8 ;
return 0 ;
V_16:
F_11 (i, &map, HWGRP_COUNT) {
V_3 = F_12 ( V_10 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
V_5 &= ~ V_13 ;
F_5 ( V_2 , V_5 , V_3 ) ;
}
return - V_18 ;
}
static int F_14 ( struct V_6 * V_7 , T_1 V_8 , int V_9 )
{
T_1 V_5 ;
unsigned long V_19 ;
struct V_11 * V_12 = V_7 -> V_12 ;
struct V_1 * V_2 = V_12 -> V_2 ;
F_15 ( & V_2 -> V_20 , V_19 ) ;
V_5 = F_7 ( V_7 , V_8 , V_9 ) ;
F_16 ( & V_2 -> V_20 , V_19 ) ;
return V_5 ;
}
static void F_17 ( struct V_1 * V_2 , int V_21 )
{
T_1 V_5 ;
F_5 ( V_2 , V_22 , V_23 ) ;
F_13 ( V_2 ) ;
V_5 = V_24 |
V_25 ;
F_5 ( V_2 , V_5 , V_26 ) ;
if ( V_21 )
F_5 ( V_2 , V_27 , V_28 ) ;
F_13 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_10 ;
T_1 V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ ) {
struct V_11 * V_12 = & V_2 -> V_12 [ V_10 ] ;
struct V_6 * V_7 ;
F_5 ( V_2 , F_19 ( V_12 -> V_14 ) , V_30 ) ;
V_5 = V_12 -> V_31 ?
F_20 ( V_12 -> V_31 , V_12 -> V_32 ) :
V_33 ;
F_5 ( V_2 , V_5 , V_34 ) ;
F_21 (c, &as->client, list)
F_7 ( V_7 , V_7 -> V_17 , 1 ) ;
}
F_5 ( V_2 , V_2 -> V_35 , V_36 ) ;
F_5 ( V_2 , V_2 -> V_37 , V_38 ) ;
F_5 ( V_2 , V_2 -> V_39 , V_40 ) ;
F_5 ( V_2 , V_2 -> V_41 , V_42 ) ;
F_5 ( V_2 , V_43 , F_22 ( V_44 ) ) ;
F_5 ( V_2 , V_45 , F_22 ( V_46 ) ) ;
F_17 ( V_2 , 1 ) ;
return F_23 ( V_2 -> V_47 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_3 V_48 ,
unsigned long * V_49 , struct V_50 * V_50 , int V_51 )
{
T_1 V_5 ;
unsigned long V_52 = V_51
? F_25 ( V_48 , V_53 )
: F_25 ( V_48 , V_54 ) ;
V_5 = V_55 | F_26 ( V_49 , V_50 ) ;
F_5 ( V_2 , V_5 , V_23 ) ;
F_13 ( V_2 ) ;
V_5 = V_52 |
V_56 |
( V_12 -> V_14 << V_57 ) ;
F_5 ( V_2 , V_5 , V_26 ) ;
F_13 ( V_2 ) ;
}
static void F_27 ( struct V_11 * V_12 , T_3 V_48 )
{
unsigned long V_58 = F_28 ( V_48 ) ;
unsigned long * V_59 = ( unsigned long * ) F_29 ( V_12 -> V_31 ) ;
if ( V_59 [ V_58 ] != F_30 ( V_58 ) ) {
F_31 ( V_12 -> V_2 -> V_60 , L_1 , V_58 ) ;
F_32 ( F_33 ( V_59 [ V_58 ] ) ) ;
F_34 ( F_33 ( V_59 [ V_58 ] ) ) ;
V_59 [ V_58 ] = F_30 ( V_58 ) ;
F_35 ( & V_59 [ V_58 ] , V_12 -> V_31 , sizeof V_59 [ V_58 ] ) ;
F_24 ( V_12 -> V_2 , V_12 , V_48 , & V_59 [ V_58 ] ,
V_12 -> V_31 , 1 ) ;
}
}
static void F_36 ( struct V_11 * V_12 )
{
unsigned V_61 ;
int V_62 ;
struct V_63 * V_60 = V_12 -> V_2 -> V_60 ;
if ( ! V_12 -> V_31 )
return;
V_61 = V_12 -> V_2 -> V_64 ;
V_62 = V_12 -> V_2 -> V_65 ;
while ( V_62 -- > 0 ) {
F_27 ( V_12 , V_61 ) ;
V_61 += V_66 * V_67 ;
}
F_32 ( V_12 -> V_31 ) ;
F_34 ( V_12 -> V_31 ) ;
V_12 -> V_31 = NULL ;
F_37 ( V_60 , V_12 -> V_68 ) ;
V_12 -> V_68 = NULL ;
}
static unsigned long * F_38 ( struct V_11 * V_12 ,
T_3 V_48 , bool V_69 ,
struct V_50 * * V_70 ,
unsigned int * * V_62 )
{
unsigned long V_71 = F_39 ( V_48 ) ;
unsigned long V_58 = F_28 ( V_48 ) ;
unsigned long * V_59 = F_29 ( V_12 -> V_31 ) ;
unsigned long * V_72 ;
if ( V_59 [ V_58 ] != F_30 ( V_58 ) ) {
* V_70 = F_33 ( V_59 [ V_58 ] ) ;
V_72 = F_29 ( * V_70 ) ;
} else if ( ! V_69 ) {
return NULL ;
} else {
int V_73 ;
unsigned long V_61 = F_40 ( V_58 ) ;
F_31 ( V_12 -> V_2 -> V_60 , L_2 , V_58 ) ;
* V_70 = F_41 ( V_74 ) ;
if ( ! * V_70 ) {
F_42 ( V_12 -> V_2 -> V_60 ,
L_3 ) ;
return NULL ;
}
F_43 ( * V_70 ) ;
V_72 = ( unsigned long * ) F_29 ( * V_70 ) ;
for ( V_73 = 0 ; V_73 < V_67 ;
V_73 ++ , V_61 += V_66 ) {
V_72 [ V_73 ] = F_44 ( V_61 ) ;
}
F_35 ( V_72 , * V_70 , V_75 ) ;
V_59 [ V_58 ] = F_45 ( * V_70 ,
V_12 -> V_76 | V_77 ) ;
F_35 ( & V_59 [ V_58 ] , V_12 -> V_31 , sizeof V_59 [ V_58 ] ) ;
F_24 ( V_12 -> V_2 , V_12 , V_48 , & V_59 [ V_58 ] ,
V_12 -> V_31 , 1 ) ;
}
* V_62 = & V_12 -> V_68 [ V_58 ] ;
return & V_72 [ V_71 % V_67 ] ;
}
static void F_46 ( struct V_11 * V_12 ,
T_3 V_48 , unsigned long V_78 )
{
struct V_50 * V_50 ;
unsigned long * V_79 ;
V_50 = F_47 ( V_78 ) ;
V_79 = F_29 ( V_50 ) ;
if ( ! V_79 )
return;
V_79 [ 0 ] = V_48 ;
V_79 [ 1 ] = V_78 << V_80 ;
F_35 ( V_79 , V_50 , sizeof( V_79 [ 0 ] ) * 2 ) ;
}
static inline void F_46 ( struct V_11 * V_12 ,
unsigned long V_61 , unsigned long V_78 )
{
}
static int F_48 ( struct V_11 * V_12 )
{
unsigned long * V_59 , V_19 ;
int V_58 , V_81 = 0 ;
T_1 V_5 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_50 * V_50 ;
unsigned int * V_82 ;
V_82 = F_49 ( V_2 -> V_60 ,
sizeof( V_82 [ 0 ] ) * V_83 ,
V_84 ) ;
V_50 = F_41 ( V_84 | V_85 ) ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
if ( V_12 -> V_31 ) {
V_81 = - V_86 ;
goto V_87;
}
if ( ! V_50 || ! V_82 ) {
F_42 ( V_2 -> V_60 , L_4 , V_88 ) ;
V_81 = - V_89 ;
goto V_87;
}
V_12 -> V_31 = V_50 ;
V_12 -> V_68 = V_82 ;
F_43 ( V_12 -> V_31 ) ;
V_59 = F_29 ( V_12 -> V_31 ) ;
for ( V_58 = 0 ; V_58 < V_83 ; V_58 ++ )
V_59 [ V_58 ] = F_30 ( V_58 ) ;
F_35 ( V_59 , V_12 -> V_31 , V_90 ) ;
V_5 = V_55 | F_26 ( V_59 , V_12 -> V_31 ) ;
F_5 ( V_2 , V_5 , V_23 ) ;
F_13 ( V_12 -> V_2 ) ;
V_5 = V_24 |
V_56 |
( V_12 -> V_14 << V_57 ) ;
F_5 ( V_2 , V_5 , V_26 ) ;
F_13 ( V_12 -> V_2 ) ;
F_16 ( & V_12 -> V_20 , V_19 ) ;
return 0 ;
V_87:
F_16 ( & V_12 -> V_20 , V_19 ) ;
F_37 ( V_2 -> V_60 , V_82 ) ;
if ( V_50 )
F_34 ( V_50 ) ;
return V_81 ;
}
static void F_50 ( struct V_11 * V_12 , T_3 V_48 )
{
unsigned long * V_49 ;
struct V_50 * V_50 ;
unsigned int * V_62 ;
V_49 = F_38 ( V_12 , V_48 , false , & V_50 , & V_62 ) ;
if ( F_9 ( ! V_49 ) )
return;
if ( F_9 ( * V_49 == F_44 ( V_48 ) ) )
return;
* V_49 = F_44 ( V_48 ) ;
F_35 ( V_49 , V_50 , sizeof( * V_49 ) ) ;
F_24 ( V_12 -> V_2 , V_12 , V_48 , V_49 , V_50 , 0 ) ;
if ( ! -- ( * V_62 ) ) {
F_27 ( V_12 , V_48 ) ;
F_17 ( V_12 -> V_2 , 0 ) ;
}
}
static void F_51 ( struct V_11 * V_12 , T_3 V_48 ,
unsigned long V_78 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned long * V_49 ;
unsigned int * V_62 ;
struct V_50 * V_50 ;
V_49 = F_38 ( V_12 , V_48 , true , & V_50 , & V_62 ) ;
if ( F_9 ( ! V_49 ) )
return;
if ( * V_49 == F_44 ( V_48 ) )
( * V_62 ) ++ ;
* V_49 = F_52 ( V_78 , V_12 -> V_91 ) ;
if ( F_53 ( ( * V_49 == F_44 ( V_48 ) ) ) )
( * V_62 ) -- ;
F_35 ( V_49 , V_50 , sizeof( * V_49 ) ) ;
F_24 ( V_2 , V_12 , V_48 , V_49 , V_50 , 0 ) ;
F_46 ( V_12 , V_48 , V_78 ) ;
}
static int F_54 ( struct V_92 * V_93 , unsigned long V_48 ,
T_4 V_94 , T_2 V_95 , int V_96 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
unsigned long V_78 = F_55 ( V_94 ) ;
unsigned long V_19 ;
F_31 ( V_12 -> V_2 -> V_60 , L_5 , V_12 -> V_14 , V_48 , V_94 ) ;
if ( ! F_56 ( V_78 ) )
return - V_89 ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
F_51 ( V_12 , V_48 , V_78 ) ;
F_16 ( & V_12 -> V_20 , V_19 ) ;
return 0 ;
}
static T_2 F_57 ( struct V_92 * V_93 , unsigned long V_48 ,
T_2 V_95 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
unsigned long V_19 ;
F_31 ( V_12 -> V_2 -> V_60 , L_6 , V_12 -> V_14 , V_48 ) ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
F_50 ( V_12 , V_48 ) ;
F_16 ( & V_12 -> V_20 , V_19 ) ;
return V_66 ;
}
static T_4 F_58 ( struct V_92 * V_93 ,
unsigned long V_48 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
unsigned long * V_49 ;
unsigned int * V_62 ;
struct V_50 * V_50 ;
unsigned long V_78 ;
unsigned long V_19 ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
V_49 = F_38 ( V_12 , V_48 , true , & V_50 , & V_62 ) ;
V_78 = * V_49 & V_98 ;
F_9 ( ! F_56 ( V_78 ) ) ;
F_31 ( V_12 -> V_2 -> V_60 ,
L_7 , V_48 , V_78 , V_12 -> V_14 ) ;
F_16 ( & V_12 -> V_20 , V_19 ) ;
return F_59 ( V_78 ) ;
}
static int F_60 ( struct V_92 * V_93 ,
unsigned long V_99 )
{
return 0 ;
}
static int F_61 ( struct V_92 * V_93 ,
struct V_63 * V_60 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_6 * V_100 , * V_7 ;
T_1 V_8 ;
int V_81 ;
V_100 = F_49 ( V_2 -> V_60 , sizeof( * V_7 ) , V_84 ) ;
if ( ! V_100 )
return - V_89 ;
V_100 -> V_60 = V_60 ;
V_100 -> V_12 = V_12 ;
V_8 = ( unsigned long ) V_60 -> V_101 ;
if ( ! V_8 )
return - V_15 ;
V_81 = F_62 ( V_100 , V_8 ) ;
if ( V_81 )
goto V_102;
F_63 ( & V_12 -> V_103 ) ;
F_21 (c, &as->client, list) {
if ( V_7 -> V_60 == V_60 ) {
F_42 ( V_2 -> V_60 ,
L_8 , F_64 ( V_7 -> V_60 ) ) ;
V_81 = - V_15 ;
goto V_104;
}
}
F_65 ( & V_100 -> V_105 , & V_12 -> V_100 ) ;
F_66 ( & V_12 -> V_103 ) ;
if ( V_8 & V_106 ) {
struct V_50 * V_50 ;
V_50 = V_12 -> V_2 -> V_107 ;
F_51 ( V_12 , 0 , F_67 ( V_50 ) ) ;
F_68 ( L_9 ) ;
}
F_31 ( V_2 -> V_60 , L_10 , F_64 ( V_60 ) ) ;
return 0 ;
V_104:
F_69 ( V_100 ) ;
F_66 ( & V_12 -> V_103 ) ;
V_102:
F_37 ( V_2 -> V_60 , V_100 ) ;
return V_81 ;
}
static void F_70 ( struct V_92 * V_93 ,
struct V_63 * V_60 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_6 * V_7 ;
F_63 ( & V_12 -> V_103 ) ;
F_21 (c, &as->client, list) {
if ( V_7 -> V_60 == V_60 ) {
F_69 ( V_7 ) ;
F_71 ( & V_7 -> V_105 ) ;
F_37 ( V_2 -> V_60 , V_7 ) ;
V_7 -> V_12 = NULL ;
F_31 ( V_2 -> V_60 ,
L_11 , F_64 ( V_7 -> V_60 ) ) ;
goto V_108;
}
}
F_42 ( V_2 -> V_60 , L_12 , F_64 ( V_60 ) ) ;
V_108:
F_66 ( & V_12 -> V_103 ) ;
}
static int F_72 ( struct V_92 * V_93 )
{
int V_10 , V_81 = - V_86 ;
unsigned long V_19 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_109 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ ) {
V_12 = & V_2 -> V_12 [ V_10 ] ;
if ( V_12 -> V_31 )
continue;
V_81 = F_48 ( V_12 ) ;
if ( ! V_81 )
goto V_110;
if ( V_81 != - V_86 )
break;
}
if ( V_10 == V_2 -> V_29 )
F_42 ( V_2 -> V_60 , L_13 ) ;
return V_81 ;
V_110:
F_15 ( & V_2 -> V_20 , V_19 ) ;
F_5 ( V_2 , F_19 ( V_12 -> V_14 ) , V_30 ) ;
F_5 ( V_2 ,
F_20 ( V_12 -> V_31 , V_12 -> V_32 ) , V_34 ) ;
F_13 ( V_2 ) ;
F_16 ( & V_2 -> V_20 , V_19 ) ;
V_93 -> V_97 = V_12 ;
V_93 -> V_111 . V_112 = V_2 -> V_64 ;
V_93 -> V_111 . V_113 = V_2 -> V_64 +
V_2 -> V_65 * V_66 - 1 ;
V_93 -> V_111 . V_114 = true ;
F_31 ( V_2 -> V_60 , L_14 , V_12 ) ;
return 0 ;
}
static void F_73 ( struct V_92 * V_93 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned long V_19 ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
if ( V_12 -> V_31 ) {
F_63 ( & V_2 -> V_20 ) ;
F_5 ( V_2 , F_19 ( V_12 -> V_14 ) , V_30 ) ;
F_5 ( V_2 , V_33 , V_34 ) ;
F_13 ( V_2 ) ;
F_66 ( & V_2 -> V_20 ) ;
F_36 ( V_12 ) ;
}
if ( ! F_74 ( & V_12 -> V_100 ) ) {
struct V_6 * V_7 ;
F_21 (c, &as->client, list)
F_70 ( V_93 , V_7 -> V_60 ) ;
}
F_16 ( & V_12 -> V_20 , V_19 ) ;
V_93 -> V_97 = NULL ;
F_31 ( V_2 -> V_60 , L_14 , V_12 ) ;
}
static T_5 F_75 ( struct V_115 * V_115 ,
const char T_6 * V_116 ,
T_2 V_62 , T_7 * V_117 )
{
struct V_118 * V_119 ;
struct V_1 * V_2 ;
struct V_120 * V_121 ;
int V_10 ;
enum {
V_122 = 0 ,
V_123 ,
V_124 ,
};
const char * const V_125 [] = {
[ V_122 ] = L_15 ,
[ V_123 ] = L_16 ,
[ V_124 ] = L_17 ,
} ;
char V_126 [] = L_17 ;
T_1 V_5 ;
T_2 V_3 ;
V_62 = F_76 ( T_2 , V_62 , sizeof( V_126 ) ) ;
if ( F_77 ( V_126 , V_116 , V_62 ) )
return - V_15 ;
for ( V_10 = 0 ; V_10 < F_78 ( V_125 ) ; V_10 ++ )
if ( strncmp ( V_126 , V_125 [ V_10 ] ,
strlen ( V_125 [ V_10 ] ) ) == 0 )
break;
if ( V_10 == F_78 ( V_125 ) )
return - V_15 ;
V_121 = V_115 -> V_127 ;
V_119 = V_121 -> V_128 -> V_129 ;
V_2 = V_119 -> V_2 ;
V_3 = F_22 ( V_119 -> V_130 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
switch ( V_10 ) {
case V_122 :
V_5 &= ~ V_131 ;
V_5 &= ~ V_132 ;
F_5 ( V_2 , V_5 , V_3 ) ;
break;
case V_123 :
V_5 |= V_131 ;
V_5 &= ~ V_132 ;
F_5 ( V_2 , V_5 , V_3 ) ;
break;
case V_124 :
V_5 |= V_132 ;
F_5 ( V_2 , V_5 , V_3 ) ;
V_5 &= ~ V_132 ;
F_5 ( V_2 , V_5 , V_3 ) ;
break;
default:
F_4 () ;
break;
}
F_31 ( V_2 -> V_60 , L_18 , V_88 ,
V_5 , F_1 ( V_2 , V_3 ) , V_3 ) ;
return V_62 ;
}
static int F_79 ( struct V_133 * V_134 , void * V_135 )
{
struct V_118 * V_119 ;
struct V_1 * V_2 ;
struct V_120 * V_121 ;
int V_10 ;
const char * const V_136 [] = { L_19 , L_20 , } ;
V_121 = F_80 ( V_134 -> V_137 ) ;
V_119 = V_121 -> V_128 -> V_129 ;
V_2 = V_119 -> V_2 ;
for ( V_10 = 0 ; V_10 < F_78 ( V_136 ) ; V_10 ++ ) {
T_1 V_5 ;
T_2 V_3 ;
V_3 = F_81 ( V_119 -> V_138 , V_119 -> V_130 , V_10 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
F_82 ( V_134 , L_21 , V_136 [ V_10 ] , V_5 ) ;
F_31 ( V_2 -> V_60 , L_22 , V_88 ,
V_136 [ V_10 ] , V_5 , V_3 ) ;
}
F_82 ( V_134 , L_23 ) ;
F_83 ( V_121 ) ;
return 0 ;
}
static int F_84 ( struct V_139 * V_139 , struct V_115 * V_115 )
{
return F_85 ( V_115 , F_79 , V_139 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_87 ( V_2 -> V_140 ) ;
F_88 ( V_2 -> V_141 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_10 ;
T_2 V_95 ;
struct V_120 * V_142 ;
V_95 = F_78 ( V_143 ) * F_78 ( V_144 ) *
sizeof( * V_2 -> V_141 ) ;
V_2 -> V_141 = F_90 ( V_95 , V_84 ) ;
if ( ! V_2 -> V_141 )
return;
V_142 = F_91 ( F_64 ( V_2 -> V_60 ) , NULL ) ;
if ( ! V_142 )
goto V_87;
V_2 -> V_140 = V_142 ;
for ( V_10 = 0 ; V_10 < F_78 ( V_143 ) ; V_10 ++ ) {
int V_145 ;
struct V_120 * V_138 ;
V_138 = F_91 ( V_143 [ V_10 ] , V_142 ) ;
if ( ! V_138 )
goto V_87;
for ( V_145 = 0 ; V_145 < F_78 ( V_144 ) ; V_145 ++ ) {
struct V_120 * V_130 ;
struct V_118 * V_119 ;
V_119 = V_2 -> V_141 ;
V_119 += V_10 * F_78 ( V_143 ) + V_145 ;
V_119 -> V_2 = V_2 ;
V_119 -> V_138 = V_10 ;
V_119 -> V_130 = V_145 ;
V_130 = F_92 ( V_144 [ V_145 ] ,
V_146 | V_147 , V_138 ,
( void * ) V_119 ,
& V_148 ) ;
if ( ! V_130 )
goto V_87;
}
}
return;
V_87:
F_86 ( V_2 ) ;
}
static int F_93 ( struct V_63 * V_60 )
{
struct V_1 * V_2 = F_94 ( V_60 ) ;
V_2 -> V_35 = F_1 ( V_2 , V_36 ) ;
V_2 -> V_37 = F_1 ( V_2 , V_38 ) ;
V_2 -> V_39 = F_1 ( V_2 , V_40 ) ;
V_2 -> V_41 = F_1 ( V_2 , V_42 ) ;
return 0 ;
}
static int F_95 ( struct V_63 * V_60 )
{
struct V_1 * V_2 = F_94 ( V_60 ) ;
unsigned long V_19 ;
int V_81 ;
F_15 ( & V_2 -> V_20 , V_19 ) ;
V_81 = F_18 ( V_2 ) ;
F_16 ( & V_2 -> V_20 , V_19 ) ;
return V_81 ;
}
static int F_96 ( struct V_149 * V_150 )
{
struct V_1 * V_2 ;
struct V_63 * V_60 = & V_150 -> V_60 ;
int V_10 , V_151 , V_81 = 0 ;
T_3 V_152 ( V_153 ) ;
T_2 V_95 , V_152 ( V_154 ) ;
if ( V_109 )
return - V_155 ;
F_97 ( V_80 != V_156 ) ;
if ( F_98 ( V_60 -> V_157 , L_24 , & V_151 ) )
return - V_158 ;
V_95 = sizeof( * V_2 ) + V_151 * sizeof( * V_2 -> V_12 ) ;
V_2 = F_49 ( V_60 , V_95 , V_84 ) ;
if ( ! V_2 ) {
F_42 ( V_60 , L_25 ) ;
return - V_89 ;
}
for ( V_10 = 0 ; V_10 < F_78 ( V_2 -> V_4 ) ; V_10 ++ ) {
struct V_159 * V_160 ;
V_160 = F_99 ( V_150 , V_161 , V_10 ) ;
if ( ! V_160 )
return - V_158 ;
V_2 -> V_4 [ V_10 ] = F_100 ( & V_150 -> V_60 , V_160 ) ;
if ( ! V_2 -> V_4 [ V_10 ] )
return - V_18 ;
}
V_81 = F_101 ( V_60 -> V_157 , NULL , 0 , NULL , & V_153 , & V_154 ) ;
if ( V_81 )
return - V_158 ;
if ( V_154 & V_162 )
return - V_15 ;
V_154 >>= V_156 ;
if ( ! V_154 )
return - V_15 ;
V_2 -> V_47 = F_102 ( V_60 -> V_157 , L_26 , 0 ) ;
if ( ! V_2 -> V_47 )
return - V_158 ;
V_2 -> V_60 = V_60 ;
V_2 -> V_29 = V_151 ;
V_2 -> V_64 = V_153 ;
V_2 -> V_65 = V_154 ;
V_2 -> V_35 = ~ 0 ;
V_2 -> V_37 = ~ 0 ;
V_2 -> V_39 = ~ 0 ;
V_2 -> V_41 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ ) {
struct V_11 * V_12 = & V_2 -> V_12 [ V_10 ] ;
V_12 -> V_2 = V_2 ;
V_12 -> V_14 = V_10 ;
V_12 -> V_32 = V_163 ;
V_12 -> V_76 = V_164 ;
V_12 -> V_91 = V_165 ;
F_103 ( & V_12 -> V_20 ) ;
F_104 ( & V_12 -> V_100 ) ;
}
F_103 ( & V_2 -> V_20 ) ;
V_81 = F_18 ( V_2 ) ;
if ( V_81 )
return V_81 ;
F_105 ( V_150 , V_2 ) ;
V_2 -> V_107 = F_41 ( V_84 ) ;
if ( ! V_2 -> V_107 )
return - V_89 ;
F_89 ( V_2 ) ;
V_109 = V_2 ;
return 0 ;
}
static int F_106 ( struct V_149 * V_150 )
{
struct V_1 * V_2 = F_107 ( V_150 ) ;
int V_10 ;
F_86 ( V_2 ) ;
F_5 ( V_2 , V_166 , V_28 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ )
F_36 ( & V_2 -> V_12 [ V_10 ] ) ;
F_34 ( V_2 -> V_107 ) ;
V_109 = NULL ;
return 0 ;
}
static int T_8 F_108 ( void )
{
F_109 ( & V_167 , & V_168 ) ;
return F_110 ( & V_169 ) ;
}
static void T_9 F_111 ( void )
{
F_112 ( & V_169 ) ;
}
