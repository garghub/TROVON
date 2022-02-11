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
F_5 ( V_2 , V_43 , V_44 ) ;
F_5 ( V_2 , V_45 , V_46 ) ;
F_17 ( V_2 , 1 ) ;
return F_22 ( V_2 -> V_47 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_11 * V_12 , T_3 V_48 ,
unsigned long * V_49 , struct V_50 * V_50 , int V_51 )
{
T_1 V_5 ;
unsigned long V_52 = V_51
? F_24 ( V_48 , V_53 )
: F_24 ( V_48 , V_54 ) ;
V_5 = V_55 | F_25 ( V_49 , V_50 ) ;
F_5 ( V_2 , V_5 , V_23 ) ;
F_13 ( V_2 ) ;
V_5 = V_52 |
V_56 |
( V_12 -> V_14 << V_57 ) ;
F_5 ( V_2 , V_5 , V_26 ) ;
F_13 ( V_2 ) ;
}
static void F_26 ( struct V_11 * V_12 , T_3 V_48 )
{
unsigned long V_58 = F_27 ( V_48 ) ;
unsigned long * V_59 = ( unsigned long * ) F_28 ( V_12 -> V_31 ) ;
if ( V_59 [ V_58 ] != F_29 ( V_58 ) ) {
F_30 ( V_12 -> V_2 -> V_60 , L_1 , V_58 ) ;
F_31 ( F_32 ( V_59 [ V_58 ] ) ) ;
F_33 ( F_32 ( V_59 [ V_58 ] ) ) ;
V_59 [ V_58 ] = F_29 ( V_58 ) ;
F_34 ( & V_59 [ V_58 ] , V_12 -> V_31 , sizeof V_59 [ V_58 ] ) ;
F_23 ( V_12 -> V_2 , V_12 , V_48 , & V_59 [ V_58 ] ,
V_12 -> V_31 , 1 ) ;
}
}
static void F_35 ( struct V_11 * V_12 )
{
unsigned V_61 ;
int V_62 ;
struct V_63 * V_60 = V_12 -> V_2 -> V_60 ;
if ( ! V_12 -> V_31 )
return;
V_61 = V_12 -> V_2 -> V_64 ;
V_62 = V_12 -> V_2 -> V_65 ;
while ( V_62 -- > 0 ) {
F_26 ( V_12 , V_61 ) ;
V_61 += V_66 * V_67 ;
}
F_31 ( V_12 -> V_31 ) ;
F_33 ( V_12 -> V_31 ) ;
V_12 -> V_31 = NULL ;
F_36 ( V_60 , V_12 -> V_68 ) ;
V_12 -> V_68 = NULL ;
}
static unsigned long * F_37 ( struct V_11 * V_12 ,
T_3 V_48 , bool V_69 ,
struct V_50 * * V_70 ,
unsigned int * * V_62 )
{
unsigned long V_71 = F_38 ( V_48 ) ;
unsigned long V_58 = F_27 ( V_48 ) ;
unsigned long * V_59 = F_28 ( V_12 -> V_31 ) ;
unsigned long * V_72 ;
if ( V_59 [ V_58 ] != F_29 ( V_58 ) ) {
* V_70 = F_32 ( V_59 [ V_58 ] ) ;
V_72 = F_28 ( * V_70 ) ;
} else if ( ! V_69 ) {
return NULL ;
} else {
int V_73 ;
unsigned long V_61 = F_39 ( V_58 ) ;
F_30 ( V_12 -> V_2 -> V_60 , L_2 , V_58 ) ;
* V_70 = F_40 ( V_74 ) ;
if ( ! * V_70 ) {
F_41 ( V_12 -> V_2 -> V_60 ,
L_3 ) ;
return NULL ;
}
F_42 ( * V_70 ) ;
V_72 = ( unsigned long * ) F_28 ( * V_70 ) ;
for ( V_73 = 0 ; V_73 < V_67 ;
V_73 ++ , V_61 += V_66 ) {
V_72 [ V_73 ] = F_43 ( V_61 ) ;
}
F_34 ( V_72 , * V_70 , V_75 ) ;
V_59 [ V_58 ] = F_44 ( * V_70 ,
V_12 -> V_76 | V_77 ) ;
F_34 ( & V_59 [ V_58 ] , V_12 -> V_31 , sizeof V_59 [ V_58 ] ) ;
F_23 ( V_12 -> V_2 , V_12 , V_48 , & V_59 [ V_58 ] ,
V_12 -> V_31 , 1 ) ;
}
* V_62 = & V_12 -> V_68 [ V_58 ] ;
return & V_72 [ V_71 % V_67 ] ;
}
static void F_45 ( struct V_11 * V_12 ,
T_3 V_48 , unsigned long V_78 )
{
struct V_50 * V_50 ;
unsigned long * V_79 ;
V_50 = F_46 ( V_78 ) ;
V_79 = F_28 ( V_50 ) ;
if ( ! V_79 )
return;
V_79 [ 0 ] = V_48 ;
V_79 [ 1 ] = V_78 << V_80 ;
F_34 ( V_79 , V_50 , sizeof( V_79 [ 0 ] ) * 2 ) ;
}
static inline void F_45 ( struct V_11 * V_12 ,
unsigned long V_61 , unsigned long V_78 )
{
}
static int F_47 ( struct V_11 * V_12 )
{
unsigned long * V_59 , V_19 ;
int V_58 , V_81 = 0 ;
T_1 V_5 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_50 * V_50 ;
unsigned int * V_82 ;
V_82 = F_48 ( V_2 -> V_60 ,
sizeof( V_82 [ 0 ] ) * V_83 ,
V_84 ) ;
V_50 = F_40 ( V_84 | V_85 ) ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
if ( V_12 -> V_31 ) {
V_81 = - V_86 ;
goto V_87;
}
if ( ! V_50 || ! V_82 ) {
F_41 ( V_2 -> V_60 , L_4 , V_88 ) ;
V_81 = - V_89 ;
goto V_87;
}
V_12 -> V_31 = V_50 ;
V_12 -> V_68 = V_82 ;
F_42 ( V_12 -> V_31 ) ;
V_59 = F_28 ( V_12 -> V_31 ) ;
for ( V_58 = 0 ; V_58 < V_83 ; V_58 ++ )
V_59 [ V_58 ] = F_29 ( V_58 ) ;
F_34 ( V_59 , V_12 -> V_31 , V_90 ) ;
V_5 = V_55 | F_25 ( V_59 , V_12 -> V_31 ) ;
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
F_36 ( V_2 -> V_60 , V_82 ) ;
if ( V_50 )
F_33 ( V_50 ) ;
return V_81 ;
}
static void F_49 ( struct V_11 * V_12 , T_3 V_48 )
{
unsigned long * V_49 ;
struct V_50 * V_50 ;
unsigned int * V_62 ;
V_49 = F_37 ( V_12 , V_48 , false , & V_50 , & V_62 ) ;
if ( F_9 ( ! V_49 ) )
return;
if ( F_9 ( * V_49 == F_43 ( V_48 ) ) )
return;
* V_49 = F_43 ( V_48 ) ;
F_34 ( V_49 , V_50 , sizeof( * V_49 ) ) ;
F_23 ( V_12 -> V_2 , V_12 , V_48 , V_49 , V_50 , 0 ) ;
if ( ! -- ( * V_62 ) ) {
F_26 ( V_12 , V_48 ) ;
F_17 ( V_12 -> V_2 , 0 ) ;
}
}
static void F_50 ( struct V_11 * V_12 , T_3 V_48 ,
unsigned long V_78 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned long * V_49 ;
unsigned int * V_62 ;
struct V_50 * V_50 ;
V_49 = F_37 ( V_12 , V_48 , true , & V_50 , & V_62 ) ;
if ( F_9 ( ! V_49 ) )
return;
if ( * V_49 == F_43 ( V_48 ) )
( * V_62 ) ++ ;
* V_49 = F_51 ( V_78 , V_12 -> V_91 ) ;
if ( F_52 ( ( * V_49 == F_43 ( V_48 ) ) ) )
( * V_62 ) -- ;
F_34 ( V_49 , V_50 , sizeof( * V_49 ) ) ;
F_23 ( V_2 , V_12 , V_48 , V_49 , V_50 , 0 ) ;
F_45 ( V_12 , V_48 , V_78 ) ;
}
static int F_53 ( struct V_92 * V_93 , unsigned long V_48 ,
T_4 V_94 , T_2 V_95 , int V_96 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
unsigned long V_78 = F_54 ( V_94 ) ;
unsigned long V_19 ;
F_30 ( V_12 -> V_2 -> V_60 , L_5 , V_12 -> V_14 , V_48 , V_94 ) ;
if ( ! F_55 ( V_78 ) )
return - V_89 ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
F_50 ( V_12 , V_48 , V_78 ) ;
F_16 ( & V_12 -> V_20 , V_19 ) ;
return 0 ;
}
static T_2 F_56 ( struct V_92 * V_93 , unsigned long V_48 ,
T_2 V_95 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
unsigned long V_19 ;
F_30 ( V_12 -> V_2 -> V_60 , L_6 , V_12 -> V_14 , V_48 ) ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
F_49 ( V_12 , V_48 ) ;
F_16 ( & V_12 -> V_20 , V_19 ) ;
return V_66 ;
}
static T_4 F_57 ( struct V_92 * V_93 ,
unsigned long V_48 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
unsigned long * V_49 ;
unsigned int * V_62 ;
struct V_50 * V_50 ;
unsigned long V_78 ;
unsigned long V_19 ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
V_49 = F_37 ( V_12 , V_48 , true , & V_50 , & V_62 ) ;
V_78 = * V_49 & V_98 ;
F_9 ( ! F_55 ( V_78 ) ) ;
F_30 ( V_12 -> V_2 -> V_60 ,
L_7 , V_48 , V_78 , V_12 -> V_14 ) ;
F_16 ( & V_12 -> V_20 , V_19 ) ;
return F_58 ( V_78 ) ;
}
static int F_59 ( struct V_92 * V_93 ,
unsigned long V_99 )
{
return 0 ;
}
static int F_60 ( struct V_92 * V_93 ,
struct V_63 * V_60 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_6 * V_100 , * V_7 ;
T_1 V_8 ;
int V_81 ;
V_100 = F_48 ( V_2 -> V_60 , sizeof( * V_7 ) , V_84 ) ;
if ( ! V_100 )
return - V_89 ;
V_100 -> V_60 = V_60 ;
V_100 -> V_12 = V_12 ;
V_8 = ( unsigned long ) V_60 -> V_101 ;
if ( ! V_8 )
return - V_15 ;
V_81 = F_61 ( V_100 , V_8 ) ;
if ( V_81 )
goto V_102;
F_62 ( & V_12 -> V_103 ) ;
F_21 (c, &as->client, list) {
if ( V_7 -> V_60 == V_60 ) {
F_41 ( V_2 -> V_60 ,
L_8 , F_63 ( V_7 -> V_60 ) ) ;
V_81 = - V_15 ;
goto V_104;
}
}
F_64 ( & V_100 -> V_105 , & V_12 -> V_100 ) ;
F_65 ( & V_12 -> V_103 ) ;
if ( V_8 & V_106 ) {
struct V_50 * V_50 ;
V_50 = V_12 -> V_2 -> V_107 ;
F_50 ( V_12 , 0 , F_66 ( V_50 ) ) ;
F_67 ( L_9 ) ;
}
F_30 ( V_2 -> V_60 , L_10 , F_63 ( V_60 ) ) ;
return 0 ;
V_104:
F_68 ( V_100 ) ;
F_65 ( & V_12 -> V_103 ) ;
V_102:
F_36 ( V_2 -> V_60 , V_100 ) ;
return V_81 ;
}
static void F_69 ( struct V_92 * V_93 ,
struct V_63 * V_60 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_6 * V_7 ;
F_62 ( & V_12 -> V_103 ) ;
F_21 (c, &as->client, list) {
if ( V_7 -> V_60 == V_60 ) {
F_68 ( V_7 ) ;
F_70 ( & V_7 -> V_105 ) ;
F_36 ( V_2 -> V_60 , V_7 ) ;
V_7 -> V_12 = NULL ;
F_30 ( V_2 -> V_60 ,
L_11 , F_63 ( V_7 -> V_60 ) ) ;
goto V_108;
}
}
F_41 ( V_2 -> V_60 , L_12 , F_63 ( V_60 ) ) ;
V_108:
F_65 ( & V_12 -> V_103 ) ;
}
static int F_71 ( struct V_92 * V_93 )
{
int V_10 , V_81 = - V_86 ;
unsigned long V_19 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_109 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ ) {
V_12 = & V_2 -> V_12 [ V_10 ] ;
if ( V_12 -> V_31 )
continue;
V_81 = F_47 ( V_12 ) ;
if ( ! V_81 )
goto V_110;
if ( V_81 != - V_86 )
break;
}
if ( V_10 == V_2 -> V_29 )
F_41 ( V_2 -> V_60 , L_13 ) ;
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
F_30 ( V_2 -> V_60 , L_14 , V_12 ) ;
return 0 ;
}
static void F_72 ( struct V_92 * V_93 )
{
struct V_11 * V_12 = V_93 -> V_97 ;
struct V_1 * V_2 = V_12 -> V_2 ;
unsigned long V_19 ;
F_15 ( & V_12 -> V_20 , V_19 ) ;
if ( V_12 -> V_31 ) {
F_62 ( & V_2 -> V_20 ) ;
F_5 ( V_2 , F_19 ( V_12 -> V_14 ) , V_30 ) ;
F_5 ( V_2 , V_33 , V_34 ) ;
F_13 ( V_2 ) ;
F_65 ( & V_2 -> V_20 ) ;
F_35 ( V_12 ) ;
}
if ( ! F_73 ( & V_12 -> V_100 ) ) {
struct V_6 * V_7 ;
F_21 (c, &as->client, list)
F_69 ( V_93 , V_7 -> V_60 ) ;
}
F_16 ( & V_12 -> V_20 , V_19 ) ;
V_93 -> V_97 = NULL ;
F_30 ( V_2 -> V_60 , L_14 , V_12 ) ;
}
static int F_74 ( struct V_63 * V_60 )
{
struct V_1 * V_2 = F_75 ( V_60 ) ;
V_2 -> V_35 = F_1 ( V_2 , V_36 ) ;
V_2 -> V_37 = F_1 ( V_2 , V_38 ) ;
V_2 -> V_39 = F_1 ( V_2 , V_40 ) ;
V_2 -> V_41 = F_1 ( V_2 , V_42 ) ;
return 0 ;
}
static int F_76 ( struct V_63 * V_60 )
{
struct V_1 * V_2 = F_75 ( V_60 ) ;
unsigned long V_19 ;
int V_81 ;
F_15 ( & V_2 -> V_20 , V_19 ) ;
V_81 = F_18 ( V_2 ) ;
F_16 ( & V_2 -> V_20 , V_19 ) ;
return V_81 ;
}
static int F_77 ( struct V_115 * V_116 )
{
struct V_1 * V_2 ;
struct V_63 * V_60 = & V_116 -> V_60 ;
int V_10 , V_117 , V_81 = 0 ;
T_3 V_118 ( V_119 ) ;
T_2 V_95 , V_118 ( V_120 ) ;
if ( V_109 )
return - V_121 ;
F_78 ( V_80 != V_122 ) ;
if ( F_79 ( V_60 -> V_123 , L_15 , & V_117 ) )
return - V_124 ;
V_95 = sizeof( * V_2 ) + V_117 * sizeof( * V_2 -> V_12 ) ;
V_2 = F_48 ( V_60 , V_95 , V_84 ) ;
if ( ! V_2 ) {
F_41 ( V_60 , L_16 ) ;
return - V_89 ;
}
for ( V_10 = 0 ; V_10 < F_80 ( V_2 -> V_4 ) ; V_10 ++ ) {
struct V_125 * V_126 ;
V_126 = F_81 ( V_116 , V_127 , V_10 ) ;
if ( ! V_126 )
return - V_124 ;
V_2 -> V_4 [ V_10 ] = F_82 ( & V_116 -> V_60 , V_126 ) ;
if ( ! V_2 -> V_4 [ V_10 ] )
return - V_18 ;
}
V_81 = F_83 ( V_60 -> V_123 , NULL , 0 , NULL , & V_119 , & V_120 ) ;
if ( V_81 )
return - V_124 ;
if ( V_120 & V_128 )
return - V_15 ;
V_120 >>= V_122 ;
if ( ! V_120 )
return - V_15 ;
V_2 -> V_47 = F_84 ( V_60 -> V_123 , L_17 , 0 ) ;
if ( ! V_2 -> V_47 )
return - V_124 ;
V_2 -> V_60 = V_60 ;
V_2 -> V_29 = V_117 ;
V_2 -> V_64 = V_119 ;
V_2 -> V_65 = V_120 ;
V_2 -> V_35 = ~ 0 ;
V_2 -> V_37 = ~ 0 ;
V_2 -> V_39 = ~ 0 ;
V_2 -> V_41 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ ) {
struct V_11 * V_12 = & V_2 -> V_12 [ V_10 ] ;
V_12 -> V_2 = V_2 ;
V_12 -> V_14 = V_10 ;
V_12 -> V_32 = V_129 ;
V_12 -> V_76 = V_130 ;
V_12 -> V_91 = V_131 ;
F_85 ( & V_12 -> V_20 ) ;
F_86 ( & V_12 -> V_100 ) ;
}
F_85 ( & V_2 -> V_20 ) ;
V_81 = F_18 ( V_2 ) ;
if ( V_81 )
return V_81 ;
F_87 ( V_116 , V_2 ) ;
V_2 -> V_107 = F_40 ( V_84 ) ;
if ( ! V_2 -> V_107 )
return - V_89 ;
V_109 = V_2 ;
return 0 ;
}
static int F_88 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_89 ( V_116 ) ;
int V_10 ;
F_5 ( V_2 , V_132 , V_28 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_29 ; V_10 ++ )
F_35 ( & V_2 -> V_12 [ V_10 ] ) ;
F_33 ( V_2 -> V_107 ) ;
V_109 = NULL ;
return 0 ;
}
static int T_5 F_90 ( void )
{
F_91 ( & V_133 , & V_134 ) ;
return F_92 ( & V_135 ) ;
}
static void T_6 F_93 ( void )
{
F_94 ( & V_135 ) ;
}
