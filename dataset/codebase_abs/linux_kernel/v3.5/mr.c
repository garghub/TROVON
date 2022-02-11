static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
int V_5 ;
T_1 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
for ( V_4 = V_3 ; V_4 <= V_2 -> V_8 ; ++ V_4 )
if ( V_2 -> V_9 [ V_4 ] ) {
V_5 = 1 << ( V_2 -> V_8 - V_4 ) ;
V_6 = F_3 ( V_2 -> V_10 [ V_4 ] , V_5 ) ;
if ( V_6 < V_5 )
goto V_11;
}
F_4 ( & V_2 -> V_7 ) ;
return - 1 ;
V_11:
F_5 ( V_6 , V_2 -> V_10 [ V_4 ] ) ;
-- V_2 -> V_9 [ V_4 ] ;
while ( V_4 > V_3 ) {
-- V_4 ;
V_6 <<= 1 ;
F_6 ( V_6 ^ 1 , V_2 -> V_10 [ V_4 ] ) ;
++ V_2 -> V_9 [ V_4 ] ;
}
F_4 ( & V_2 -> V_7 ) ;
V_6 <<= V_3 ;
return V_6 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_6 , int V_3 )
{
V_6 >>= V_3 ;
F_2 ( & V_2 -> V_7 ) ;
while ( F_8 ( V_6 ^ 1 , V_2 -> V_10 [ V_3 ] ) ) {
F_5 ( V_6 ^ 1 , V_2 -> V_10 [ V_3 ] ) ;
-- V_2 -> V_9 [ V_3 ] ;
V_6 >>= 1 ;
++ V_3 ;
}
F_6 ( V_6 , V_2 -> V_10 [ V_3 ] ) ;
++ V_2 -> V_9 [ V_3 ] ;
F_4 ( & V_2 -> V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_8 )
{
int V_12 , V_13 ;
V_2 -> V_8 = V_8 ;
F_10 ( & V_2 -> V_7 ) ;
V_2 -> V_10 = F_11 ( ( V_2 -> V_8 + 1 ) * sizeof ( long * ) ,
V_14 ) ;
V_2 -> V_9 = F_12 ( ( V_2 -> V_8 + 1 ) , sizeof * V_2 -> V_9 ,
V_14 ) ;
if ( ! V_2 -> V_10 || ! V_2 -> V_9 )
goto V_15;
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 ) {
V_13 = F_13 ( 1 << ( V_2 -> V_8 - V_12 ) ) ;
V_2 -> V_10 [ V_12 ] = F_14 ( V_13 * sizeof ( long ) , V_14 ) ;
if ( ! V_2 -> V_10 [ V_12 ] )
goto V_16;
F_15 ( V_2 -> V_10 [ V_12 ] , 1 << ( V_2 -> V_8 - V_12 ) ) ;
}
F_6 ( 0 , V_2 -> V_10 [ V_2 -> V_8 ] ) ;
V_2 -> V_9 [ V_2 -> V_8 ] = 1 ;
return 0 ;
V_16:
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 )
F_16 ( V_2 -> V_10 [ V_12 ] ) ;
V_15:
F_16 ( V_2 -> V_10 ) ;
F_16 ( V_2 -> V_9 ) ;
return - V_17 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 )
F_16 ( V_2 -> V_10 [ V_12 ] ) ;
F_16 ( V_2 -> V_10 ) ;
F_16 ( V_2 -> V_9 ) ;
}
T_1 F_18 ( struct V_18 * V_19 , int V_3 )
{
struct V_20 * V_21 = & F_19 ( V_19 ) -> V_21 ;
T_1 V_6 ;
int V_22 ;
T_1 V_23 ;
V_22 = F_20 ( int , V_3 - V_24 , 0 ) ;
V_6 = F_1 ( & V_21 -> V_25 , V_22 ) ;
if ( V_6 == - 1 )
return - 1 ;
V_23 = V_6 * ( 1 << V_24 ) ;
if ( F_21 ( V_19 , & V_21 -> V_26 , V_23 ,
V_23 + ( 1 << V_3 ) - 1 ) ) {
F_7 ( & V_21 -> V_25 , V_6 , V_22 ) ;
return - 1 ;
}
return V_23 ;
}
static T_1 F_22 ( struct V_18 * V_19 , int V_3 )
{
T_2 V_27 ;
T_2 V_28 ;
int V_29 ;
if ( F_23 ( V_19 ) ) {
F_24 ( & V_27 , V_3 ) ;
V_29 = F_25 ( V_19 , V_27 , & V_28 , V_30 ,
V_31 ,
V_32 ,
V_33 ,
V_34 ) ;
if ( V_29 )
return - 1 ;
return F_26 ( & V_28 ) ;
}
return F_18 ( V_19 , V_3 ) ;
}
int F_27 ( struct V_18 * V_19 , int V_35 , int V_36 ,
struct V_37 * V_38 )
{
int V_12 ;
if ( ! V_35 ) {
V_38 -> V_3 = - 1 ;
V_38 -> V_36 = V_39 ;
return 0 ;
} else
V_38 -> V_36 = V_36 ;
for ( V_38 -> V_3 = 0 , V_12 = 1 ; V_12 < V_35 ; V_12 <<= 1 )
++ V_38 -> V_3 ;
V_38 -> V_23 = F_22 ( V_19 , V_38 -> V_3 ) ;
if ( V_38 -> V_23 == - 1 )
return - V_17 ;
return 0 ;
}
void F_28 ( struct V_18 * V_19 , T_1 V_23 , int V_3 )
{
T_1 V_40 ;
int V_22 ;
struct V_20 * V_21 = & F_19 ( V_19 ) -> V_21 ;
V_22 = F_20 ( int , V_3 - V_24 , 0 ) ;
V_40 = V_23 / ( 1 << V_24 ) ;
F_7 ( & V_21 -> V_25 , V_40 , V_22 ) ;
F_29 ( V_19 , & V_21 -> V_26 , V_23 ,
V_23 + ( 1 << V_3 ) - 1 ) ;
}
static void F_30 ( struct V_18 * V_19 , T_1 V_23 , int V_3 )
{
T_2 V_27 ;
int V_29 ;
if ( F_23 ( V_19 ) ) {
F_24 ( & V_27 , V_23 ) ;
F_31 ( & V_27 , V_3 ) ;
V_29 = F_32 ( V_19 , V_27 , V_30 , V_31 ,
V_41 ,
V_33 ,
V_34 ) ;
if ( V_29 )
F_33 ( V_19 , L_1
L_2 , V_23 , V_3 ) ;
return;
}
F_28 ( V_19 , V_23 , V_3 ) ;
}
void F_34 ( struct V_18 * V_19 , struct V_37 * V_38 )
{
if ( V_38 -> V_3 < 0 )
return;
F_30 ( V_19 , V_38 -> V_23 , V_38 -> V_3 ) ;
}
T_2 F_35 ( struct V_18 * V_19 , struct V_37 * V_38 )
{
return ( T_2 ) V_38 -> V_23 * V_19 -> V_42 . V_43 ;
}
static T_1 F_36 ( T_1 V_44 )
{
return ( V_44 >> 24 ) | ( V_44 << 8 ) ;
}
static T_1 F_37 ( T_1 V_45 )
{
return ( V_45 << 24 ) | ( V_45 >> 8 ) ;
}
static int F_38 ( struct V_18 * V_19 , struct V_46 * V_47 ,
int V_48 )
{
return F_32 ( V_19 , V_47 -> V_49 , V_48 ,
0 , V_50 , V_51 ,
V_34 ) ;
}
static int F_39 ( struct V_18 * V_19 , struct V_46 * V_47 ,
int V_48 )
{
return F_40 ( V_19 , 0 , V_47 ? V_47 -> V_49 : 0 , V_48 ,
! V_47 , V_52 ,
V_51 , V_34 ) ;
}
static int F_41 ( struct V_18 * V_19 , T_1 V_53 , T_1 V_54 ,
T_2 V_55 , T_2 V_56 , T_1 V_57 , int V_35 ,
int V_36 , struct V_58 * V_59 )
{
V_59 -> V_55 = V_55 ;
V_59 -> V_56 = V_56 ;
V_59 -> V_54 = V_54 ;
V_59 -> V_57 = V_57 ;
V_59 -> V_60 = V_61 ;
V_59 -> V_45 = F_36 ( V_53 ) ;
return F_27 ( V_19 , V_35 , V_36 , & V_59 -> V_38 ) ;
}
static int F_42 ( struct V_18 * V_19 ,
struct V_46 * V_47 ,
int V_62 )
{
return F_32 ( V_19 , V_47 -> V_49 , V_62 , 0 , V_63 ,
V_33 , V_34 ) ;
}
int F_43 ( struct V_18 * V_19 )
{
struct F_19 * V_64 = F_19 ( V_19 ) ;
return F_44 ( & V_64 -> V_21 . V_65 ) ;
}
static int F_45 ( struct V_18 * V_19 )
{
T_2 V_28 ;
if ( F_23 ( V_19 ) ) {
if ( F_25 ( V_19 , 0 , & V_28 , V_66 , V_67 ,
V_32 ,
V_33 , V_34 ) )
return - 1 ;
return F_26 ( & V_28 ) ;
}
return F_43 ( V_19 ) ;
}
void F_46 ( struct V_18 * V_19 , T_1 V_68 )
{
struct F_19 * V_64 = F_19 ( V_19 ) ;
F_47 ( & V_64 -> V_21 . V_65 , V_68 ) ;
}
static void F_48 ( struct V_18 * V_19 , T_1 V_68 )
{
T_2 V_27 ;
if ( F_23 ( V_19 ) ) {
F_24 ( & V_27 , V_68 ) ;
if ( F_32 ( V_19 , V_27 , V_66 , V_67 ,
V_41 ,
V_33 , V_34 ) )
F_33 ( V_19 , L_3 ,
V_68 ) ;
return;
}
F_46 ( V_19 , V_68 ) ;
}
int F_49 ( struct V_18 * V_19 , T_1 V_68 )
{
struct V_20 * V_21 = & F_19 ( V_19 ) -> V_21 ;
return F_50 ( V_19 , & V_21 -> V_69 , V_68 ) ;
}
static int F_51 ( struct V_18 * V_19 , T_1 V_68 )
{
T_2 V_70 ;
if ( F_23 ( V_19 ) ) {
F_24 ( & V_70 , V_68 ) ;
return F_25 ( V_19 , V_70 , & V_70 , V_66 , V_71 ,
V_32 ,
V_33 ,
V_34 ) ;
}
return F_49 ( V_19 , V_68 ) ;
}
void F_52 ( struct V_18 * V_19 , T_1 V_68 )
{
struct V_20 * V_21 = & F_19 ( V_19 ) -> V_21 ;
F_53 ( V_19 , & V_21 -> V_69 , V_68 ) ;
}
static void F_54 ( struct V_18 * V_19 , T_1 V_68 )
{
T_2 V_27 ;
if ( F_23 ( V_19 ) ) {
F_24 ( & V_27 , V_68 ) ;
if ( F_32 ( V_19 , V_27 , V_66 , V_71 ,
V_41 , V_33 ,
V_34 ) )
F_33 ( V_19 , L_4 ,
V_68 ) ;
return;
}
return F_52 ( V_19 , V_68 ) ;
}
int F_55 ( struct V_18 * V_19 , T_1 V_54 , T_2 V_55 , T_2 V_56 , T_1 V_57 ,
int V_35 , int V_36 , struct V_58 * V_59 )
{
T_1 V_68 ;
int V_29 ;
V_68 = F_45 ( V_19 ) ;
if ( V_68 == - 1 )
return - V_17 ;
V_29 = F_41 ( V_19 , V_68 , V_54 , V_55 , V_56 ,
V_57 , V_35 , V_36 , V_59 ) ;
if ( V_29 )
F_48 ( V_19 , V_68 ) ;
return V_29 ;
}
static void F_56 ( struct V_18 * V_19 , struct V_58 * V_59 )
{
int V_29 ;
if ( V_59 -> V_60 == V_72 ) {
V_29 = F_39 ( V_19 , NULL ,
F_37 ( V_59 -> V_45 ) &
( V_19 -> V_42 . V_73 - 1 ) ) ;
if ( V_29 )
F_33 ( V_19 , L_5 , V_29 ) ;
V_59 -> V_60 = V_74 ;
}
F_34 ( V_19 , & V_59 -> V_38 ) ;
}
void F_57 ( struct V_18 * V_19 , struct V_58 * V_59 )
{
F_56 ( V_19 , V_59 ) ;
if ( V_59 -> V_60 )
F_54 ( V_19 , F_37 ( V_59 -> V_45 ) ) ;
F_48 ( V_19 , F_37 ( V_59 -> V_45 ) ) ;
}
int F_58 ( struct V_18 * V_19 , struct V_58 * V_59 )
{
struct V_46 * V_47 ;
struct V_75 * V_76 ;
int V_29 ;
V_29 = F_51 ( V_19 , F_37 ( V_59 -> V_45 ) ) ;
if ( V_29 )
return V_29 ;
V_47 = F_59 ( V_19 ) ;
if ( F_60 ( V_47 ) ) {
V_29 = F_61 ( V_47 ) ;
goto V_77;
}
V_76 = V_47 -> V_78 ;
memset ( V_76 , 0 , sizeof *V_76 ) ;
V_76 -> V_79 = F_62 ( V_80 |
V_81 |
V_59 -> V_57 ) ;
V_76 -> V_45 = F_62 ( F_37 ( V_59 -> V_45 ) ) ;
V_76 -> V_82 = F_62 ( V_59 -> V_54 | V_83 ) ;
V_76 -> V_84 = F_63 ( V_59 -> V_55 ) ;
V_76 -> V_85 = F_63 ( V_59 -> V_56 ) ;
V_76 -> V_86 = F_62 ( V_59 -> V_38 . V_36 ) ;
if ( V_59 -> V_38 . V_3 < 0 ) {
V_76 -> V_79 |= F_62 ( V_87 ) ;
V_76 -> V_88 = 0 ;
} else {
V_76 -> V_88 = F_63 ( F_35 ( V_19 ,
& V_59 -> V_38 ) ) ;
}
if ( V_59 -> V_38 . V_3 >= 0 && V_59 -> V_38 . V_36 == 0 ) {
V_76 -> V_79 |= F_62 ( V_89 ) ;
V_76 -> V_82 |= F_62 ( V_90 |
V_91 ) ;
V_76 -> V_92 = F_62 ( 1 << V_59 -> V_38 . V_3 ) ;
} else {
V_76 -> V_79 |= F_62 ( V_93 ) ;
}
V_29 = F_38 ( V_19 , V_47 ,
F_37 ( V_59 -> V_45 ) & ( V_19 -> V_42 . V_73 - 1 ) ) ;
if ( V_29 ) {
F_33 ( V_19 , L_6 , V_29 ) ;
goto V_94;
}
V_59 -> V_60 = V_72 ;
F_64 ( V_19 , V_47 ) ;
return 0 ;
V_94:
F_64 ( V_19 , V_47 ) ;
V_77:
F_54 ( V_19 , F_37 ( V_59 -> V_45 ) ) ;
return V_29 ;
}
static int F_65 ( struct V_18 * V_19 , struct V_37 * V_38 ,
int V_95 , int V_35 , T_2 * V_96 )
{
struct F_19 * V_64 = F_19 ( V_19 ) ;
T_3 * V_97 ;
T_4 V_98 ;
int V_12 ;
V_97 = F_66 ( & V_64 -> V_21 . V_26 , V_38 -> V_23 +
V_95 , & V_98 ) ;
if ( ! V_97 )
return - V_17 ;
F_67 ( & V_19 -> V_99 -> V_19 , V_98 ,
V_35 * sizeof ( T_2 ) , V_100 ) ;
for ( V_12 = 0 ; V_12 < V_35 ; ++ V_12 )
V_97 [ V_12 ] = F_63 ( V_96 [ V_12 ] | V_101 ) ;
F_68 ( & V_19 -> V_99 -> V_19 , V_98 ,
V_35 * sizeof ( T_2 ) , V_100 ) ;
return 0 ;
}
int F_69 ( struct V_18 * V_19 , struct V_37 * V_38 ,
int V_95 , int V_35 , T_2 * V_96 )
{
int V_29 = 0 ;
int V_102 ;
int V_103 ;
int V_104 ;
V_103 = V_105 / sizeof( T_2 ) ;
V_104 = V_103 - ( V_38 -> V_23 + V_95 )
% V_103 ;
V_102 = F_70 ( int , V_104 , V_35 ) ;
while ( V_35 > 0 ) {
V_29 = F_65 ( V_19 , V_38 , V_95 , V_102 , V_96 ) ;
if ( V_29 )
return V_29 ;
V_35 -= V_102 ;
V_95 += V_102 ;
V_96 += V_102 ;
V_102 = F_70 ( int , V_103 , V_35 ) ;
}
return V_29 ;
}
int F_71 ( struct V_18 * V_19 , struct V_37 * V_38 ,
int V_95 , int V_35 , T_2 * V_96 )
{
struct V_46 * V_47 = NULL ;
T_3 * V_106 = NULL ;
int V_102 ;
int V_29 = 0 ;
int V_12 ;
if ( V_38 -> V_3 < 0 )
return - V_107 ;
if ( F_23 ( V_19 ) ) {
V_47 = F_59 ( V_19 ) ;
if ( F_60 ( V_47 ) )
return F_61 ( V_47 ) ;
V_106 = V_47 -> V_78 ;
while ( V_35 > 0 ) {
V_102 = F_70 ( int , V_108 / sizeof( T_2 ) - 2 ,
V_35 ) ;
V_106 [ 0 ] = F_63 ( V_38 -> V_23 + V_95 ) ;
V_106 [ 1 ] = 0 ;
for ( V_12 = 0 ; V_12 < V_102 ; ++ V_12 )
V_106 [ V_12 + 2 ] = F_63 ( V_96 [ V_12 ] |
V_101 ) ;
V_29 = F_42 ( V_19 , V_47 , V_102 ) ;
if ( V_29 ) {
F_64 ( V_19 , V_47 ) ;
return V_29 ;
}
V_35 -= V_102 ;
V_95 += V_102 ;
V_96 += V_102 ;
}
F_64 ( V_19 , V_47 ) ;
return V_29 ;
}
return F_69 ( V_19 , V_38 , V_95 , V_35 , V_96 ) ;
}
int F_72 ( struct V_18 * V_19 , struct V_37 * V_38 ,
struct V_109 * V_78 )
{
T_2 * V_96 ;
int V_29 ;
int V_12 ;
V_96 = F_14 ( V_78 -> V_35 * sizeof *V_96 , V_14 ) ;
if ( ! V_96 )
return - V_17 ;
for ( V_12 = 0 ; V_12 < V_78 -> V_35 ; ++ V_12 )
if ( V_78 -> V_110 == 1 )
V_96 [ V_12 ] = V_78 -> V_111 . V_112 + ( V_12 << V_78 -> V_36 ) ;
else
V_96 [ V_12 ] = V_78 -> V_96 [ V_12 ] . V_112 ;
V_29 = F_71 ( V_19 , V_38 , 0 , V_78 -> V_35 , V_96 ) ;
F_16 ( V_96 ) ;
return V_29 ;
}
int F_73 ( struct V_18 * V_19 )
{
struct F_19 * V_64 = F_19 ( V_19 ) ;
struct V_20 * V_21 = & V_64 -> V_21 ;
int V_29 ;
if ( ! F_74 ( V_19 -> V_42 . V_73 ) )
return - V_107 ;
if ( F_75 ( V_19 ) )
return 0 ;
V_29 = F_76 ( & V_21 -> V_65 , V_19 -> V_42 . V_73 ,
~ 0 , V_19 -> V_42 . V_113 , 0 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_9 ( & V_21 -> V_25 ,
F_77 ( V_19 -> V_42 . V_114 /
( 1 << V_24 ) ) ) ;
if ( V_29 )
goto V_115;
if ( V_19 -> V_42 . V_116 ) {
V_64 -> V_116 =
F_22 ( V_19 ,
F_78 ( V_19 -> V_42 . V_116 - 1 ) ) ;
if ( V_64 -> V_116 < 0 ) {
F_33 ( V_19 , L_7 ,
V_21 -> V_25 . V_8 ) ;
V_29 = - V_17 ;
goto V_117;
}
}
return 0 ;
V_117:
F_17 ( & V_21 -> V_25 ) ;
V_115:
F_79 ( & V_21 -> V_65 ) ;
return V_29 ;
}
void F_80 ( struct V_18 * V_19 )
{
struct F_19 * V_64 = F_19 ( V_19 ) ;
struct V_20 * V_21 = & V_64 -> V_21 ;
if ( F_75 ( V_19 ) )
return;
if ( V_64 -> V_116 >= 0 )
F_30 ( V_19 , V_64 -> V_116 ,
F_78 ( V_19 -> V_42 . V_116 - 1 ) ) ;
F_17 ( & V_21 -> V_25 ) ;
F_79 ( & V_21 -> V_65 ) ;
}
static inline int F_81 ( struct V_118 * V_119 , T_2 * V_96 ,
int V_35 , T_2 V_55 )
{
int V_12 , V_120 ;
if ( V_35 > V_119 -> V_121 )
return - V_107 ;
V_120 = ( 1 << V_119 -> V_36 ) - 1 ;
if ( V_55 & V_120 )
return - V_107 ;
if ( 0 )
for ( V_12 = 0 ; V_12 < V_35 ; ++ V_12 ) {
if ( V_96 [ V_12 ] & ~ V_120 )
return - V_107 ;
}
if ( V_119 -> V_122 >= V_119 -> V_123 )
return - V_107 ;
return 0 ;
}
int F_82 ( struct V_18 * V_19 , struct V_118 * V_119 , T_2 * V_96 ,
int V_35 , T_2 V_55 , T_1 * V_124 , T_1 * V_125 )
{
T_1 V_45 ;
int V_12 , V_29 ;
V_29 = F_81 ( V_119 , V_96 , V_35 , V_55 ) ;
if ( V_29 )
return V_29 ;
++ V_119 -> V_122 ;
V_45 = F_37 ( V_119 -> V_59 . V_45 ) ;
V_45 += V_19 -> V_42 . V_73 ;
* V_124 = * V_125 = V_119 -> V_59 . V_45 = F_36 ( V_45 ) ;
* ( V_126 * ) V_119 -> V_127 = V_128 ;
F_83 () ;
F_67 ( & V_19 -> V_99 -> V_19 , V_119 -> V_98 ,
V_35 * sizeof( T_2 ) , V_100 ) ;
for ( V_12 = 0 ; V_12 < V_35 ; ++ V_12 )
V_119 -> V_97 [ V_12 ] = F_63 ( V_96 [ V_12 ] | V_101 ) ;
F_68 ( & V_19 -> V_99 -> V_19 , V_119 -> V_98 ,
V_35 * sizeof( T_2 ) , V_100 ) ;
V_119 -> V_127 -> V_45 = F_62 ( V_45 ) ;
V_119 -> V_127 -> V_124 = F_62 ( V_45 ) ;
V_119 -> V_127 -> V_85 = F_63 ( V_35 * ( 1ull << V_119 -> V_36 ) ) ;
V_119 -> V_127 -> V_84 = F_63 ( V_55 ) ;
F_83 () ;
* ( V_126 * ) V_119 -> V_127 = V_129 ;
F_83 () ;
return 0 ;
}
int F_84 ( struct V_18 * V_19 , T_1 V_54 , T_1 V_57 , int V_121 ,
int V_123 , V_126 V_36 , struct V_118 * V_119 )
{
struct F_19 * V_64 = F_19 ( V_19 ) ;
int V_29 = - V_17 ;
if ( V_123 > V_19 -> V_42 . V_130 )
return - V_107 ;
if ( V_36 < ( F_85 ( V_19 -> V_42 . V_131 ) - 1 ) || V_36 >= 32 )
return - V_107 ;
if ( V_121 * sizeof * V_119 -> V_97 > V_105 )
return - V_107 ;
V_119 -> V_36 = V_36 ;
V_119 -> V_121 = V_121 ;
V_119 -> V_123 = V_123 ;
V_119 -> V_122 = 0 ;
V_29 = F_55 ( V_19 , V_54 , 0 , 0 , V_57 , V_121 ,
V_36 , & V_119 -> V_59 ) ;
if ( V_29 )
return V_29 ;
V_119 -> V_97 = F_66 ( & V_64 -> V_21 . V_26 ,
V_119 -> V_59 . V_38 . V_23 ,
& V_119 -> V_98 ) ;
if ( ! V_119 -> V_97 ) {
V_29 = - V_17 ;
goto V_132;
}
return 0 ;
V_132:
F_57 ( V_19 , & V_119 -> V_59 ) ;
return V_29 ;
}
int F_86 ( struct V_18 * V_19 , struct V_118 * V_119 )
{
struct F_19 * V_64 = F_19 ( V_19 ) ;
int V_29 ;
V_29 = F_58 ( V_19 , & V_119 -> V_59 ) ;
if ( V_29 )
return V_29 ;
V_119 -> V_127 = F_66 ( & V_64 -> V_21 . V_69 ,
F_37 ( V_119 -> V_59 . V_45 ) , NULL ) ;
if ( ! V_119 -> V_127 )
return - V_17 ;
return 0 ;
}
void F_87 ( struct V_18 * V_19 , struct V_118 * V_119 ,
T_1 * V_124 , T_1 * V_125 )
{
struct V_46 * V_47 ;
int V_29 ;
if ( ! V_119 -> V_122 )
return;
V_119 -> V_122 = 0 ;
V_47 = F_59 ( V_19 ) ;
if ( F_60 ( V_47 ) ) {
V_29 = F_61 ( V_47 ) ;
F_88 ( V_133 L_8
L_9 , V_29 ) ;
return;
}
V_29 = F_39 ( V_19 , NULL ,
F_37 ( V_119 -> V_59 . V_45 ) &
( V_19 -> V_42 . V_73 - 1 ) ) ;
F_64 ( V_19 , V_47 ) ;
if ( V_29 ) {
F_88 ( V_133 L_10 ,
V_29 ) ;
return;
}
V_119 -> V_59 . V_60 = V_74 ;
}
int F_89 ( struct V_18 * V_19 , struct V_118 * V_119 )
{
if ( V_119 -> V_122 )
return - V_134 ;
F_57 ( V_19 , & V_119 -> V_59 ) ;
V_119 -> V_59 . V_60 = V_61 ;
return 0 ;
}
int F_90 ( struct V_18 * V_19 )
{
return F_32 ( V_19 , 0 , 0 , 0 , V_135 , 1000 ,
V_136 ) ;
}
