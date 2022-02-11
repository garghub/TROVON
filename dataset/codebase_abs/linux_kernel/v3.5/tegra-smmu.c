static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_2 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_6 + V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_5 , T_2 V_3 )
{
F_4 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static int F_7 ( struct V_7 * V_8 ,
unsigned long V_9 , int V_10 )
{
int V_11 ;
struct V_12 * V_13 = V_8 -> V_13 ;
T_1 V_5 , V_3 , V_14 = F_8 ( V_13 -> V_15 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
F_9 ( ! V_10 && V_9 ) ;
if ( V_10 && ! V_9 )
return - V_16 ;
if ( ! V_10 )
V_9 = F_10 ( V_8 ) ;
F_11 (i, &map, HWGRP_COUNT) {
V_3 = F_12 ( V_11 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
if ( V_10 ) {
if ( F_9 ( V_5 & V_14 ) )
goto V_17;
V_5 |= V_14 ;
} else {
F_9 ( ( V_5 & V_14 ) == V_14 ) ;
V_5 &= ~ V_14 ;
}
F_3 ( V_2 , V_5 , V_3 ) ;
}
F_13 ( V_2 ) ;
V_8 -> V_18 = V_9 ;
return 0 ;
V_17:
F_11 (i, &map, HWGRP_COUNT) {
V_3 = F_12 ( V_11 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
V_5 &= ~ V_14 ;
F_3 ( V_2 , V_5 , V_3 ) ;
}
return - V_19 ;
}
static int F_14 ( struct V_7 * V_8 , T_1 V_9 , int V_10 )
{
T_1 V_5 ;
unsigned long V_20 ;
struct V_12 * V_13 = V_8 -> V_13 ;
struct V_1 * V_2 = V_13 -> V_2 ;
F_15 ( & V_2 -> V_21 , V_20 ) ;
V_5 = F_7 ( V_8 , V_9 , V_10 ) ;
F_16 ( & V_2 -> V_21 , V_20 ) ;
return V_5 ;
}
static void F_17 ( struct V_1 * V_2 , int V_22 )
{
T_1 V_5 ;
F_3 ( V_2 , V_23 , V_24 ) ;
F_13 ( V_2 ) ;
V_5 = V_25 |
V_26 ;
F_3 ( V_2 , V_5 , V_27 ) ;
if ( V_22 )
F_3 ( V_2 , V_28 , V_29 ) ;
F_13 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_11 ;
T_1 V_5 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_30 ; V_11 ++ ) {
struct V_12 * V_13 = & V_2 -> V_13 [ V_11 ] ;
struct V_7 * V_8 ;
F_3 ( V_2 , F_19 ( V_13 -> V_15 ) , V_31 ) ;
V_5 = V_13 -> V_32 ?
F_20 ( V_13 -> V_32 , V_13 -> V_33 ) :
V_34 ;
F_3 ( V_2 , V_5 , V_35 ) ;
F_21 (c, &as->client, list)
F_7 ( V_8 , V_8 -> V_18 , 1 ) ;
}
F_3 ( V_2 , V_2 -> V_36 , V_37 ) ;
F_3 ( V_2 , V_2 -> V_38 , V_39 ) ;
F_3 ( V_2 , V_2 -> V_40 , V_41 ) ;
F_3 ( V_2 , V_2 -> V_42 , V_43 ) ;
F_3 ( V_2 , V_44 , V_45 ) ;
F_3 ( V_2 , V_46 , V_47 ) ;
F_17 ( V_2 , 1 ) ;
V_5 = F_5 ( V_2 , V_48 ) ;
V_5 |= V_49 <<
V_50 ;
F_6 ( V_2 , V_5 , V_48 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_3 V_51 ,
unsigned long * V_52 , struct V_53 * V_53 , int V_54 )
{
T_1 V_5 ;
unsigned long V_55 = V_54
? F_23 ( V_51 , V_56 )
: F_23 ( V_51 , V_57 ) ;
V_5 = V_58 | F_24 ( V_52 , V_53 ) ;
F_3 ( V_2 , V_5 , V_24 ) ;
F_13 ( V_2 ) ;
V_5 = V_55 |
V_59 |
( V_13 -> V_15 << V_60 ) ;
F_3 ( V_2 , V_5 , V_27 ) ;
F_13 ( V_2 ) ;
}
static void F_25 ( struct V_12 * V_13 , T_3 V_51 )
{
unsigned long V_61 = F_26 ( V_51 ) ;
unsigned long * V_62 = ( unsigned long * ) F_27 ( V_13 -> V_32 ) ;
if ( V_62 [ V_61 ] != F_28 ( V_61 ) ) {
F_29 ( V_13 -> V_2 -> V_63 , L_1 , V_61 ) ;
F_30 ( F_31 ( V_62 [ V_61 ] ) ) ;
F_32 ( F_31 ( V_62 [ V_61 ] ) ) ;
V_62 [ V_61 ] = F_28 ( V_61 ) ;
F_33 ( & V_62 [ V_61 ] , V_13 -> V_32 , sizeof V_62 [ V_61 ] ) ;
F_22 ( V_13 -> V_2 , V_13 , V_51 , & V_62 [ V_61 ] ,
V_13 -> V_32 , 1 ) ;
}
}
static void F_34 ( struct V_12 * V_13 )
{
unsigned V_64 ;
int V_65 ;
struct V_66 * V_63 = V_13 -> V_2 -> V_63 ;
if ( ! V_13 -> V_32 )
return;
V_64 = V_13 -> V_2 -> V_67 ;
V_65 = V_13 -> V_2 -> V_68 ;
while ( V_65 -- > 0 ) {
F_25 ( V_13 , V_64 ) ;
V_64 += V_69 * V_70 ;
}
F_30 ( V_13 -> V_32 ) ;
F_32 ( V_13 -> V_32 ) ;
V_13 -> V_32 = NULL ;
F_35 ( V_63 , V_13 -> V_71 ) ;
V_13 -> V_71 = NULL ;
}
static unsigned long * F_36 ( struct V_12 * V_13 ,
T_3 V_51 , bool V_72 ,
struct V_53 * * V_73 ,
unsigned int * * V_65 )
{
unsigned long V_74 = F_37 ( V_51 ) ;
unsigned long V_61 = F_26 ( V_51 ) ;
unsigned long * V_62 = F_27 ( V_13 -> V_32 ) ;
unsigned long * V_75 ;
if ( V_62 [ V_61 ] != F_28 ( V_61 ) ) {
* V_73 = F_31 ( V_62 [ V_61 ] ) ;
V_75 = F_27 ( * V_73 ) ;
} else if ( ! V_72 ) {
return NULL ;
} else {
int V_76 ;
unsigned long V_64 = F_38 ( V_61 ) ;
F_29 ( V_13 -> V_2 -> V_63 , L_2 , V_61 ) ;
* V_73 = F_39 ( V_77 ) ;
if ( ! * V_73 ) {
F_40 ( V_13 -> V_2 -> V_63 ,
L_3 ) ;
return NULL ;
}
F_41 ( * V_73 ) ;
V_75 = ( unsigned long * ) F_27 ( * V_73 ) ;
for ( V_76 = 0 ; V_76 < V_70 ;
V_76 ++ , V_64 += V_69 ) {
V_75 [ V_76 ] = F_42 ( V_64 ) ;
}
F_33 ( V_75 , * V_73 , V_78 ) ;
V_62 [ V_61 ] = F_43 ( * V_73 ,
V_13 -> V_79 | V_80 ) ;
F_33 ( & V_62 [ V_61 ] , V_13 -> V_32 , sizeof V_62 [ V_61 ] ) ;
F_22 ( V_13 -> V_2 , V_13 , V_51 , & V_62 [ V_61 ] ,
V_13 -> V_32 , 1 ) ;
}
* V_65 = & V_13 -> V_71 [ V_61 ] ;
return & V_75 [ V_74 % V_70 ] ;
}
static void F_44 ( struct V_12 * V_13 ,
T_3 V_51 , unsigned long V_81 )
{
struct V_53 * V_53 ;
unsigned long * V_82 ;
V_53 = F_45 ( V_81 ) ;
V_82 = F_27 ( V_53 ) ;
if ( ! V_82 )
return;
V_82 [ 0 ] = V_51 ;
V_82 [ 1 ] = V_81 << V_83 ;
F_33 ( V_82 , V_53 , sizeof( V_82 [ 0 ] ) * 2 ) ;
}
static inline void F_44 ( struct V_12 * V_13 ,
unsigned long V_64 , unsigned long V_81 )
{
}
static int F_46 ( struct V_12 * V_13 )
{
unsigned long * V_62 ;
int V_61 ;
T_1 V_5 ;
struct V_1 * V_2 = V_13 -> V_2 ;
if ( V_13 -> V_32 )
return 0 ;
V_13 -> V_71 = F_47 ( V_2 -> V_63 ,
sizeof( V_13 -> V_71 [ 0 ] ) * V_84 , V_77 ) ;
if ( ! V_13 -> V_71 ) {
F_40 ( V_2 -> V_63 ,
L_4 ) ;
return - V_85 ;
}
V_13 -> V_32 = F_39 ( V_77 | V_86 ) ;
if ( ! V_13 -> V_32 ) {
F_40 ( V_2 -> V_63 ,
L_5 ) ;
F_35 ( V_2 -> V_63 , V_13 -> V_71 ) ;
V_13 -> V_71 = NULL ;
return - V_85 ;
}
F_41 ( V_13 -> V_32 ) ;
V_62 = F_27 ( V_13 -> V_32 ) ;
for ( V_61 = 0 ; V_61 < V_84 ; V_61 ++ )
V_62 [ V_61 ] = F_28 ( V_61 ) ;
F_33 ( V_62 , V_13 -> V_32 , V_87 ) ;
V_5 = V_58 | F_24 ( V_62 , V_13 -> V_32 ) ;
F_3 ( V_2 , V_5 , V_24 ) ;
F_13 ( V_13 -> V_2 ) ;
V_5 = V_25 |
V_59 |
( V_13 -> V_15 << V_60 ) ;
F_3 ( V_2 , V_5 , V_27 ) ;
F_13 ( V_13 -> V_2 ) ;
return 0 ;
}
static void F_48 ( struct V_12 * V_13 , T_3 V_51 )
{
unsigned long * V_52 ;
struct V_53 * V_53 ;
unsigned int * V_65 ;
V_52 = F_36 ( V_13 , V_51 , false , & V_53 , & V_65 ) ;
if ( F_9 ( ! V_52 ) )
return;
if ( F_9 ( * V_52 == F_42 ( V_51 ) ) )
return;
* V_52 = F_42 ( V_51 ) ;
F_33 ( V_52 , V_53 , sizeof( * V_52 ) ) ;
F_22 ( V_13 -> V_2 , V_13 , V_51 , V_52 , V_53 , 0 ) ;
if ( ! -- ( * V_65 ) ) {
F_25 ( V_13 , V_51 ) ;
F_17 ( V_13 -> V_2 , 0 ) ;
}
}
static void F_49 ( struct V_12 * V_13 , T_3 V_51 ,
unsigned long V_81 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long * V_52 ;
unsigned int * V_65 ;
struct V_53 * V_53 ;
V_52 = F_36 ( V_13 , V_51 , true , & V_53 , & V_65 ) ;
if ( F_9 ( ! V_52 ) )
return;
if ( * V_52 == F_42 ( V_51 ) )
( * V_65 ) ++ ;
* V_52 = F_50 ( V_81 , V_13 -> V_88 ) ;
if ( F_51 ( ( * V_52 == F_42 ( V_51 ) ) ) )
( * V_65 ) -- ;
F_33 ( V_52 , V_53 , sizeof( * V_52 ) ) ;
F_22 ( V_2 , V_13 , V_51 , V_52 , V_53 , 0 ) ;
F_44 ( V_13 , V_51 , V_81 ) ;
}
static int F_52 ( struct V_89 * V_90 , unsigned long V_51 ,
T_4 V_91 , T_2 V_92 , int V_93 )
{
struct V_12 * V_13 = V_90 -> V_94 ;
unsigned long V_81 = F_53 ( V_91 ) ;
unsigned long V_20 ;
F_29 ( V_13 -> V_2 -> V_63 , L_6 , V_13 -> V_15 , V_51 , V_91 ) ;
if ( ! F_54 ( V_81 ) )
return - V_85 ;
F_15 ( & V_13 -> V_21 , V_20 ) ;
F_49 ( V_13 , V_51 , V_81 ) ;
F_16 ( & V_13 -> V_21 , V_20 ) ;
return 0 ;
}
static T_2 F_55 ( struct V_89 * V_90 , unsigned long V_51 ,
T_2 V_92 )
{
struct V_12 * V_13 = V_90 -> V_94 ;
unsigned long V_20 ;
F_29 ( V_13 -> V_2 -> V_63 , L_7 , V_13 -> V_15 , V_51 ) ;
F_15 ( & V_13 -> V_21 , V_20 ) ;
F_48 ( V_13 , V_51 ) ;
F_16 ( & V_13 -> V_21 , V_20 ) ;
return V_69 ;
}
static T_4 F_56 ( struct V_89 * V_90 ,
unsigned long V_51 )
{
struct V_12 * V_13 = V_90 -> V_94 ;
unsigned long * V_52 ;
unsigned int * V_65 ;
struct V_53 * V_53 ;
unsigned long V_81 ;
unsigned long V_20 ;
F_15 ( & V_13 -> V_21 , V_20 ) ;
V_52 = F_36 ( V_13 , V_51 , true , & V_53 , & V_65 ) ;
V_81 = * V_52 & V_95 ;
F_9 ( ! F_54 ( V_81 ) ) ;
F_29 ( V_13 -> V_2 -> V_63 ,
L_8 , V_51 , V_81 , V_13 -> V_15 ) ;
F_16 ( & V_13 -> V_21 , V_20 ) ;
return F_57 ( V_81 ) ;
}
static int F_58 ( struct V_89 * V_90 ,
unsigned long V_96 )
{
return 0 ;
}
static int F_59 ( struct V_89 * V_90 ,
struct V_66 * V_63 )
{
struct V_12 * V_13 = V_90 -> V_94 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_7 * V_97 , * V_8 ;
T_1 V_9 ;
int V_98 ;
V_97 = F_47 ( V_2 -> V_63 , sizeof( * V_8 ) , V_99 ) ;
if ( ! V_97 )
return - V_85 ;
V_97 -> V_63 = V_63 ;
V_97 -> V_13 = V_13 ;
V_9 = ( unsigned long ) V_63 -> V_100 ;
if ( ! V_9 )
return - V_16 ;
V_98 = F_60 ( V_97 , V_9 ) ;
if ( V_98 )
goto V_101;
F_61 ( & V_13 -> V_102 ) ;
F_21 (c, &as->client, list) {
if ( V_8 -> V_63 == V_63 ) {
F_40 ( V_2 -> V_63 ,
L_9 , F_62 ( V_8 -> V_63 ) ) ;
V_98 = - V_16 ;
goto V_103;
}
}
F_63 ( & V_97 -> V_104 , & V_13 -> V_97 ) ;
F_64 ( & V_13 -> V_102 ) ;
if ( V_9 & V_105 ) {
struct V_53 * V_53 ;
V_53 = V_13 -> V_2 -> V_106 ;
F_49 ( V_13 , 0 , F_65 ( V_53 ) ) ;
F_66 ( L_10 ) ;
}
F_29 ( V_2 -> V_63 , L_11 , F_62 ( V_63 ) ) ;
return 0 ;
V_103:
F_67 ( V_97 ) ;
F_64 ( & V_13 -> V_102 ) ;
V_101:
F_35 ( V_2 -> V_63 , V_97 ) ;
return V_98 ;
}
static void F_68 ( struct V_89 * V_90 ,
struct V_66 * V_63 )
{
struct V_12 * V_13 = V_90 -> V_94 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_7 * V_8 ;
F_61 ( & V_13 -> V_102 ) ;
F_21 (c, &as->client, list) {
if ( V_8 -> V_63 == V_63 ) {
F_67 ( V_8 ) ;
F_69 ( & V_8 -> V_104 ) ;
F_35 ( V_2 -> V_63 , V_8 ) ;
V_8 -> V_13 = NULL ;
F_29 ( V_2 -> V_63 ,
L_12 , F_62 ( V_8 -> V_63 ) ) ;
goto V_107;
}
}
F_40 ( V_2 -> V_63 , L_13 , F_62 ( V_8 -> V_63 ) ) ;
V_107:
F_64 ( & V_13 -> V_102 ) ;
}
static int F_70 ( struct V_89 * V_90 )
{
int V_11 ;
unsigned long V_20 ;
struct V_12 * V_13 ;
struct V_1 * V_2 = V_108 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_30 ; V_11 ++ ) {
struct V_12 * V_109 = & V_2 -> V_13 [ V_11 ] ;
F_15 ( & V_109 -> V_21 , V_20 ) ;
if ( ! V_109 -> V_32 ) {
V_13 = V_109 ;
goto V_110;
}
F_16 ( & V_109 -> V_21 , V_20 ) ;
}
F_40 ( V_2 -> V_63 , L_14 ) ;
return - V_111 ;
V_110:
if ( F_46 ( V_13 ) < 0 )
goto V_112;
F_61 ( & V_2 -> V_21 ) ;
F_3 ( V_2 , F_19 ( V_13 -> V_15 ) , V_31 ) ;
F_3 ( V_2 ,
F_20 ( V_13 -> V_32 , V_13 -> V_33 ) , V_35 ) ;
F_13 ( V_2 ) ;
F_64 ( & V_2 -> V_21 ) ;
F_16 ( & V_13 -> V_21 , V_20 ) ;
V_90 -> V_94 = V_13 ;
F_29 ( V_2 -> V_63 , L_15 , V_13 ) ;
return 0 ;
V_112:
F_16 ( & V_13 -> V_21 , V_20 ) ;
return - V_111 ;
}
static void F_71 ( struct V_89 * V_90 )
{
struct V_12 * V_13 = V_90 -> V_94 ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_20 ;
F_15 ( & V_13 -> V_21 , V_20 ) ;
if ( V_13 -> V_32 ) {
F_61 ( & V_2 -> V_21 ) ;
F_3 ( V_2 , F_19 ( V_13 -> V_15 ) , V_31 ) ;
F_3 ( V_2 , V_34 , V_35 ) ;
F_13 ( V_2 ) ;
F_64 ( & V_2 -> V_21 ) ;
F_34 ( V_13 ) ;
}
if ( ! F_72 ( & V_13 -> V_97 ) ) {
struct V_7 * V_8 ;
F_21 (c, &as->client, list)
F_68 ( V_90 , V_8 -> V_63 ) ;
}
F_16 ( & V_13 -> V_21 , V_20 ) ;
V_90 -> V_94 = NULL ;
F_29 ( V_2 -> V_63 , L_15 , V_13 ) ;
}
static int F_73 ( struct V_66 * V_63 )
{
struct V_1 * V_2 = F_74 ( V_63 ) ;
V_2 -> V_36 = F_1 ( V_2 , V_37 ) ;
V_2 -> V_38 = F_1 ( V_2 , V_39 ) ;
V_2 -> V_40 = F_1 ( V_2 , V_41 ) ;
V_2 -> V_42 = F_1 ( V_2 , V_43 ) ;
return 0 ;
}
static int F_75 ( struct V_66 * V_63 )
{
struct V_1 * V_2 = F_74 ( V_63 ) ;
unsigned long V_20 ;
F_15 ( & V_2 -> V_21 , V_20 ) ;
F_18 ( V_2 ) ;
F_16 ( & V_2 -> V_21 , V_20 ) ;
return 0 ;
}
static int F_76 ( struct V_113 * V_114 )
{
struct V_1 * V_2 ;
struct V_115 * V_4 , * V_116 , * V_117 ;
struct V_66 * V_63 = & V_114 -> V_63 ;
int V_11 , V_98 = 0 ;
if ( V_108 )
return - V_118 ;
F_77 ( V_83 != V_119 ) ;
V_4 = F_78 ( V_114 , V_120 , 0 ) ;
V_116 = F_78 ( V_114 , V_120 , 1 ) ;
V_117 = F_78 ( V_114 , V_120 , 2 ) ;
if ( ! V_4 || ! V_116 || ! V_117 ) {
F_40 ( V_63 , L_16 ) ;
return - V_111 ;
}
V_2 = F_47 ( V_63 , sizeof( * V_2 ) , V_99 ) ;
if ( ! V_2 ) {
F_40 ( V_63 , L_17 ) ;
return - V_85 ;
}
V_2 -> V_63 = V_63 ;
V_2 -> V_30 = V_121 ;
V_2 -> V_67 = ( unsigned long ) V_117 -> V_122 ;
V_2 -> V_68 = F_79 ( V_117 ) >> V_119 ;
V_2 -> V_4 = F_80 ( V_63 , V_4 -> V_122 , F_79 ( V_4 ) ) ;
V_2 -> V_6 = F_80 ( V_63 , V_116 -> V_122 ,
F_79 ( V_116 ) ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_6 ) {
F_40 ( V_63 , L_18 ) ;
V_98 = - V_123 ;
goto V_124;
}
V_2 -> V_36 = ~ 0 ;
V_2 -> V_38 = ~ 0 ;
V_2 -> V_40 = ~ 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_13 = F_47 ( V_63 ,
sizeof( V_2 -> V_13 [ 0 ] ) * V_2 -> V_30 , V_99 ) ;
if ( ! V_2 -> V_13 ) {
F_40 ( V_63 , L_19 ) ;
V_98 = - V_85 ;
goto V_124;
}
for ( V_11 = 0 ; V_11 < V_2 -> V_30 ; V_11 ++ ) {
struct V_12 * V_13 = & V_2 -> V_13 [ V_11 ] ;
V_13 -> V_2 = V_2 ;
V_13 -> V_15 = V_11 ;
V_13 -> V_33 = V_125 ;
V_13 -> V_79 = V_126 ;
V_13 -> V_88 = V_127 ;
F_81 ( & V_13 -> V_21 ) ;
F_82 ( & V_13 -> V_97 ) ;
}
F_81 ( & V_2 -> V_21 ) ;
F_18 ( V_2 ) ;
F_83 ( V_114 , V_2 ) ;
V_2 -> V_106 = F_39 ( V_99 ) ;
if ( ! V_2 -> V_106 )
goto V_124;
V_108 = V_2 ;
return 0 ;
V_124:
if ( V_2 -> V_106 )
F_32 ( V_2 -> V_106 ) ;
if ( V_2 -> V_4 )
F_84 ( V_63 , V_2 -> V_4 ) ;
if ( V_2 -> V_6 )
F_84 ( V_63 , V_2 -> V_6 ) ;
if ( V_2 && V_2 -> V_13 ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_30 ; V_11 ++ ) {
if ( V_2 -> V_13 [ V_11 ] . V_32 ) {
F_30 ( V_2 -> V_13 [ V_11 ] . V_32 ) ;
F_32 ( V_2 -> V_13 [ V_11 ] . V_32 ) ;
}
}
F_35 ( V_63 , V_2 -> V_13 ) ;
}
F_35 ( V_63 , V_2 ) ;
return V_98 ;
}
static int F_85 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = F_86 ( V_114 ) ;
struct V_66 * V_63 = V_2 -> V_63 ;
F_3 ( V_2 , V_128 , V_29 ) ;
F_83 ( V_114 , NULL ) ;
if ( V_2 -> V_13 ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_30 ; V_11 ++ )
F_34 ( & V_2 -> V_13 [ V_11 ] ) ;
F_35 ( V_63 , V_2 -> V_13 ) ;
}
if ( V_2 -> V_106 )
F_32 ( V_2 -> V_106 ) ;
if ( V_2 -> V_4 )
F_84 ( V_63 , V_2 -> V_4 ) ;
if ( V_2 -> V_6 )
F_84 ( V_63 , V_2 -> V_6 ) ;
F_35 ( V_63 , V_2 ) ;
V_108 = NULL ;
return 0 ;
}
static int T_5 F_87 ( void )
{
F_88 ( & V_129 , & V_130 ) ;
return F_89 ( & V_131 ) ;
}
static void T_6 F_90 ( void )
{
F_91 ( & V_131 ) ;
}
