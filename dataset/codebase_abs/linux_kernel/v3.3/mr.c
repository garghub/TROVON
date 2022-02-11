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
int F_41 ( struct V_18 * V_19 , int V_53 , int V_54 ,
T_1 * V_55 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
T_1 V_57 ;
V_57 = F_42 ( & V_56 -> V_21 . V_58 , V_53 , V_54 ) ;
if ( V_57 == - 1 )
return - V_17 ;
* V_55 = V_57 ;
return 0 ;
}
void F_43 ( struct V_18 * V_19 , T_1 V_55 , int V_53 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
F_44 ( & V_56 -> V_21 . V_58 , V_55 , V_53 ) ;
}
int F_45 ( struct V_18 * V_19 , T_1 V_57 , T_1 V_59 ,
T_2 V_60 , T_2 V_61 , T_1 V_62 , int V_35 ,
int V_36 , struct V_63 * V_64 )
{
V_64 -> V_60 = V_60 ;
V_64 -> V_61 = V_61 ;
V_64 -> V_59 = V_59 ;
V_64 -> V_62 = V_62 ;
V_64 -> V_65 = V_66 ;
V_64 -> V_45 = F_36 ( V_57 ) ;
return F_27 ( V_19 , V_35 , V_36 , & V_64 -> V_38 ) ;
}
static int F_46 ( struct V_18 * V_19 ,
struct V_46 * V_47 ,
int V_67 )
{
return F_32 ( V_19 , V_47 -> V_49 , V_67 , 0 , V_68 ,
V_33 , V_34 ) ;
}
int F_47 ( struct V_18 * V_19 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
return F_48 ( & V_56 -> V_21 . V_58 ) ;
}
static int F_49 ( struct V_18 * V_19 )
{
T_2 V_28 ;
if ( F_23 ( V_19 ) ) {
if ( F_25 ( V_19 , 0 , & V_28 , V_69 , V_70 ,
V_32 ,
V_33 , V_34 ) )
return - 1 ;
return F_26 ( & V_28 ) ;
}
return F_47 ( V_19 ) ;
}
void F_50 ( struct V_18 * V_19 , T_1 V_71 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
F_51 ( & V_56 -> V_21 . V_58 , V_71 ) ;
}
static void F_52 ( struct V_18 * V_19 , T_1 V_71 )
{
T_2 V_27 ;
if ( F_23 ( V_19 ) ) {
F_24 ( & V_27 , V_71 ) ;
if ( F_32 ( V_19 , V_27 , V_69 , V_70 ,
V_41 ,
V_33 , V_34 ) )
F_33 ( V_19 , L_3 ,
V_71 ) ;
return;
}
F_50 ( V_19 , V_71 ) ;
}
int F_53 ( struct V_18 * V_19 , T_1 V_71 )
{
struct V_20 * V_21 = & F_19 ( V_19 ) -> V_21 ;
return F_54 ( V_19 , & V_21 -> V_72 , V_71 ) ;
}
static int F_55 ( struct V_18 * V_19 , T_1 V_71 )
{
T_2 V_73 ;
if ( F_23 ( V_19 ) ) {
F_24 ( & V_73 , V_71 ) ;
return F_25 ( V_19 , V_73 , & V_73 , V_69 , V_74 ,
V_32 ,
V_33 ,
V_34 ) ;
}
return F_53 ( V_19 , V_71 ) ;
}
void F_56 ( struct V_18 * V_19 , T_1 V_71 )
{
struct V_20 * V_21 = & F_19 ( V_19 ) -> V_21 ;
F_57 ( V_19 , & V_21 -> V_72 , V_71 ) ;
}
static void F_58 ( struct V_18 * V_19 , T_1 V_71 )
{
T_2 V_27 ;
if ( F_23 ( V_19 ) ) {
F_24 ( & V_27 , V_71 ) ;
if ( F_32 ( V_19 , V_27 , V_69 , V_74 ,
V_41 , V_33 ,
V_34 ) )
F_33 ( V_19 , L_4 ,
V_71 ) ;
return;
}
return F_56 ( V_19 , V_71 ) ;
}
int F_59 ( struct V_18 * V_19 , T_1 V_59 , T_2 V_60 , T_2 V_61 , T_1 V_62 ,
int V_35 , int V_36 , struct V_63 * V_64 )
{
T_1 V_71 ;
int V_29 ;
V_71 = F_49 ( V_19 ) ;
if ( V_71 == - 1 )
return - V_17 ;
V_29 = F_45 ( V_19 , V_71 , V_59 , V_60 , V_61 ,
V_62 , V_35 , V_36 , V_64 ) ;
if ( V_29 )
F_52 ( V_19 , V_71 ) ;
return V_29 ;
}
void F_60 ( struct V_18 * V_19 , struct V_63 * V_64 )
{
int V_29 ;
if ( V_64 -> V_65 == V_75 ) {
V_29 = F_39 ( V_19 , NULL ,
F_37 ( V_64 -> V_45 ) &
( V_19 -> V_42 . V_76 - 1 ) ) ;
if ( V_29 )
F_33 ( V_19 , L_5 , V_29 ) ;
V_64 -> V_65 = V_77 ;
}
F_34 ( V_19 , & V_64 -> V_38 ) ;
}
void F_61 ( struct V_18 * V_19 , struct V_63 * V_64 )
{
F_60 ( V_19 , V_64 ) ;
if ( V_64 -> V_65 )
F_58 ( V_19 , F_37 ( V_64 -> V_45 ) ) ;
F_52 ( V_19 , F_37 ( V_64 -> V_45 ) ) ;
}
int F_62 ( struct V_18 * V_19 , struct V_63 * V_64 )
{
struct V_46 * V_47 ;
struct V_78 * V_79 ;
int V_29 ;
V_29 = F_55 ( V_19 , F_37 ( V_64 -> V_45 ) ) ;
if ( V_29 )
return V_29 ;
V_47 = F_63 ( V_19 ) ;
if ( F_64 ( V_47 ) ) {
V_29 = F_65 ( V_47 ) ;
goto V_80;
}
V_79 = V_47 -> V_81 ;
memset ( V_79 , 0 , sizeof *V_79 ) ;
V_79 -> V_82 = F_66 ( V_83 |
V_84 |
V_64 -> V_62 ) ;
V_79 -> V_45 = F_66 ( F_37 ( V_64 -> V_45 ) ) ;
V_79 -> V_85 = F_66 ( V_64 -> V_59 | V_86 ) ;
V_79 -> V_87 = F_67 ( V_64 -> V_60 ) ;
V_79 -> V_88 = F_67 ( V_64 -> V_61 ) ;
V_79 -> V_89 = F_66 ( V_64 -> V_38 . V_36 ) ;
if ( V_64 -> V_38 . V_3 < 0 ) {
V_79 -> V_82 |= F_66 ( V_90 ) ;
V_79 -> V_91 = 0 ;
} else {
V_79 -> V_91 = F_67 ( F_35 ( V_19 ,
& V_64 -> V_38 ) ) ;
}
if ( V_64 -> V_38 . V_3 >= 0 && V_64 -> V_38 . V_36 == 0 ) {
V_79 -> V_82 |= F_66 ( V_92 ) ;
V_79 -> V_85 |= F_66 ( V_93 |
V_94 ) ;
V_79 -> V_95 = F_66 ( 1 << V_64 -> V_38 . V_3 ) ;
} else {
V_79 -> V_82 |= F_66 ( V_96 ) ;
}
V_29 = F_38 ( V_19 , V_47 ,
F_37 ( V_64 -> V_45 ) & ( V_19 -> V_42 . V_76 - 1 ) ) ;
if ( V_29 ) {
F_33 ( V_19 , L_6 , V_29 ) ;
goto V_97;
}
V_64 -> V_65 = V_75 ;
F_68 ( V_19 , V_47 ) ;
return 0 ;
V_97:
F_68 ( V_19 , V_47 ) ;
V_80:
F_58 ( V_19 , F_37 ( V_64 -> V_45 ) ) ;
return V_29 ;
}
static int F_69 ( struct V_18 * V_19 , struct V_37 * V_38 ,
int V_98 , int V_35 , T_2 * V_99 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
T_3 * V_100 ;
T_4 V_101 ;
int V_12 ;
V_100 = F_70 ( & V_56 -> V_21 . V_26 , V_38 -> V_23 +
V_98 , & V_101 ) ;
if ( ! V_100 )
return - V_17 ;
F_71 ( & V_19 -> V_102 -> V_19 , V_101 ,
V_35 * sizeof ( T_2 ) , V_103 ) ;
for ( V_12 = 0 ; V_12 < V_35 ; ++ V_12 )
V_100 [ V_12 ] = F_67 ( V_99 [ V_12 ] | V_104 ) ;
F_72 ( & V_19 -> V_102 -> V_19 , V_101 ,
V_35 * sizeof ( T_2 ) , V_103 ) ;
return 0 ;
}
int F_73 ( struct V_18 * V_19 , struct V_37 * V_38 ,
int V_98 , int V_35 , T_2 * V_99 )
{
int V_29 = 0 ;
int V_105 ;
int V_106 ;
int V_107 ;
V_106 = V_108 / sizeof( T_2 ) ;
V_107 = V_106 - ( V_38 -> V_23 + V_98 )
% V_106 ;
V_105 = F_74 ( int , V_107 , V_35 ) ;
while ( V_35 > 0 ) {
V_29 = F_69 ( V_19 , V_38 , V_98 , V_105 , V_99 ) ;
if ( V_29 )
return V_29 ;
V_35 -= V_105 ;
V_98 += V_105 ;
V_99 += V_105 ;
V_105 = F_74 ( int , V_106 , V_35 ) ;
}
return V_29 ;
}
int F_75 ( struct V_18 * V_19 , struct V_37 * V_38 ,
int V_98 , int V_35 , T_2 * V_99 )
{
struct V_46 * V_47 = NULL ;
T_3 * V_109 = NULL ;
int V_105 ;
int V_29 = 0 ;
int V_12 ;
if ( V_38 -> V_3 < 0 )
return - V_110 ;
if ( F_23 ( V_19 ) ) {
V_47 = F_63 ( V_19 ) ;
if ( F_64 ( V_47 ) )
return F_65 ( V_47 ) ;
V_109 = V_47 -> V_81 ;
while ( V_35 > 0 ) {
V_105 = F_74 ( int , V_111 / sizeof( T_2 ) - 2 ,
V_35 ) ;
V_109 [ 0 ] = F_67 ( V_38 -> V_23 + V_98 ) ;
V_109 [ 1 ] = 0 ;
for ( V_12 = 0 ; V_12 < V_105 ; ++ V_12 )
V_109 [ V_12 + 2 ] = F_67 ( V_99 [ V_12 ] |
V_104 ) ;
V_29 = F_46 ( V_19 , V_47 , V_105 ) ;
if ( V_29 ) {
F_68 ( V_19 , V_47 ) ;
return V_29 ;
}
V_35 -= V_105 ;
V_98 += V_105 ;
V_99 += V_105 ;
}
F_68 ( V_19 , V_47 ) ;
return V_29 ;
}
return F_73 ( V_19 , V_38 , V_98 , V_35 , V_99 ) ;
}
int F_76 ( struct V_18 * V_19 , struct V_37 * V_38 ,
struct V_112 * V_81 )
{
T_2 * V_99 ;
int V_29 ;
int V_12 ;
V_99 = F_14 ( V_81 -> V_35 * sizeof *V_99 , V_14 ) ;
if ( ! V_99 )
return - V_17 ;
for ( V_12 = 0 ; V_12 < V_81 -> V_35 ; ++ V_12 )
if ( V_81 -> V_113 == 1 )
V_99 [ V_12 ] = V_81 -> V_114 . V_115 + ( V_12 << V_81 -> V_36 ) ;
else
V_99 [ V_12 ] = V_81 -> V_99 [ V_12 ] . V_115 ;
V_29 = F_75 ( V_19 , V_38 , 0 , V_81 -> V_35 , V_99 ) ;
F_16 ( V_99 ) ;
return V_29 ;
}
int F_77 ( struct V_18 * V_19 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
struct V_20 * V_21 = & V_56 -> V_21 ;
int V_29 ;
if ( ! F_78 ( V_19 -> V_42 . V_76 ) )
return - V_110 ;
if ( F_79 ( V_19 ) )
return 0 ;
V_29 = F_80 ( & V_21 -> V_58 , V_19 -> V_42 . V_76 ,
~ 0 , V_19 -> V_42 . V_116 , 0 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_9 ( & V_21 -> V_25 ,
F_81 ( V_19 -> V_42 . V_117 /
( 1 << V_24 ) ) ) ;
if ( V_29 )
goto V_118;
if ( V_19 -> V_42 . V_119 ) {
V_56 -> V_119 =
F_22 ( V_19 ,
F_82 ( V_19 -> V_42 . V_119 - 1 ) ) ;
if ( V_56 -> V_119 < 0 ) {
F_33 ( V_19 , L_7 ,
V_21 -> V_25 . V_8 ) ;
V_29 = - V_17 ;
goto V_120;
}
}
return 0 ;
V_120:
F_17 ( & V_21 -> V_25 ) ;
V_118:
F_83 ( & V_21 -> V_58 ) ;
return V_29 ;
}
void F_84 ( struct V_18 * V_19 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
struct V_20 * V_21 = & V_56 -> V_21 ;
if ( F_79 ( V_19 ) )
return;
if ( V_56 -> V_119 >= 0 )
F_30 ( V_19 , V_56 -> V_119 ,
F_82 ( V_19 -> V_42 . V_119 - 1 ) ) ;
F_17 ( & V_21 -> V_25 ) ;
F_83 ( & V_21 -> V_58 ) ;
}
static inline int F_85 ( struct V_121 * V_122 , T_2 * V_99 ,
int V_35 , T_2 V_60 )
{
int V_12 , V_123 ;
if ( V_35 > V_122 -> V_124 )
return - V_110 ;
V_123 = ( 1 << V_122 -> V_36 ) - 1 ;
if ( V_60 & V_123 )
return - V_110 ;
if ( 0 )
for ( V_12 = 0 ; V_12 < V_35 ; ++ V_12 ) {
if ( V_99 [ V_12 ] & ~ V_123 )
return - V_110 ;
}
if ( V_122 -> V_125 >= V_122 -> V_126 )
return - V_110 ;
return 0 ;
}
int F_86 ( struct V_18 * V_19 , struct V_121 * V_122 , T_2 * V_99 ,
int V_35 , T_2 V_60 , T_1 * V_127 , T_1 * V_128 )
{
T_1 V_45 ;
int V_12 , V_29 ;
V_29 = F_85 ( V_122 , V_99 , V_35 , V_60 ) ;
if ( V_29 )
return V_29 ;
++ V_122 -> V_125 ;
V_45 = F_37 ( V_122 -> V_64 . V_45 ) ;
V_45 += V_19 -> V_42 . V_76 ;
* V_127 = * V_128 = V_122 -> V_64 . V_45 = F_36 ( V_45 ) ;
* ( V_129 * ) V_122 -> V_130 = V_131 ;
F_87 () ;
F_71 ( & V_19 -> V_102 -> V_19 , V_122 -> V_101 ,
V_35 * sizeof( T_2 ) , V_103 ) ;
for ( V_12 = 0 ; V_12 < V_35 ; ++ V_12 )
V_122 -> V_100 [ V_12 ] = F_67 ( V_99 [ V_12 ] | V_104 ) ;
F_72 ( & V_19 -> V_102 -> V_19 , V_122 -> V_101 ,
V_35 * sizeof( T_2 ) , V_103 ) ;
V_122 -> V_130 -> V_45 = F_66 ( V_45 ) ;
V_122 -> V_130 -> V_127 = F_66 ( V_45 ) ;
V_122 -> V_130 -> V_88 = F_67 ( V_35 * ( 1ull << V_122 -> V_36 ) ) ;
V_122 -> V_130 -> V_87 = F_67 ( V_60 ) ;
F_87 () ;
* ( V_129 * ) V_122 -> V_130 = V_132 ;
F_87 () ;
return 0 ;
}
int F_88 ( struct V_18 * V_19 , T_1 V_59 , T_1 V_62 , int V_124 ,
int V_126 , V_129 V_36 , struct V_121 * V_122 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
T_2 V_133 ;
int V_29 = - V_17 ;
if ( V_36 < ( F_89 ( V_19 -> V_42 . V_134 ) - 1 ) || V_36 >= 32 )
return - V_110 ;
if ( V_124 * sizeof * V_122 -> V_100 > V_108 )
return - V_110 ;
V_122 -> V_36 = V_36 ;
V_122 -> V_124 = V_124 ;
V_122 -> V_126 = V_126 ;
V_122 -> V_125 = 0 ;
V_29 = F_59 ( V_19 , V_59 , 0 , 0 , V_62 , V_124 ,
V_36 , & V_122 -> V_64 ) ;
if ( V_29 )
return V_29 ;
V_133 = V_122 -> V_64 . V_38 . V_23 * V_19 -> V_42 . V_43 ;
V_122 -> V_100 = F_70 ( & V_56 -> V_21 . V_26 ,
V_122 -> V_64 . V_38 . V_23 ,
& V_122 -> V_101 ) ;
if ( ! V_122 -> V_100 ) {
V_29 = - V_17 ;
goto V_135;
}
return 0 ;
V_135:
F_61 ( V_19 , & V_122 -> V_64 ) ;
return V_29 ;
}
int F_90 ( struct V_18 * V_19 , T_1 V_57 ,
T_1 V_59 , T_1 V_62 , int V_124 ,
int V_126 , V_129 V_36 , struct V_121 * V_122 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
int V_29 = - V_17 ;
if ( V_36 < ( F_89 ( V_19 -> V_42 . V_134 ) - 1 ) || V_36 >= 32 )
return - V_110 ;
if ( V_124 * sizeof * V_122 -> V_100 > V_108 )
return - V_110 ;
V_122 -> V_36 = V_36 ;
V_122 -> V_124 = V_124 ;
V_122 -> V_126 = V_126 ;
V_122 -> V_125 = 0 ;
V_29 = F_45 ( V_19 , V_57 , V_59 , 0 , 0 , V_62 , V_124 ,
V_36 , & V_122 -> V_64 ) ;
if ( V_29 )
return V_29 ;
V_122 -> V_100 = F_70 ( & V_56 -> V_21 . V_26 ,
V_122 -> V_64 . V_38 . V_23 ,
& V_122 -> V_101 ) ;
if ( ! V_122 -> V_100 ) {
V_29 = - V_17 ;
goto V_135;
}
return 0 ;
V_135:
F_60 ( V_19 , & V_122 -> V_64 ) ;
return V_29 ;
}
int F_91 ( struct V_18 * V_19 , struct V_121 * V_122 )
{
struct F_19 * V_56 = F_19 ( V_19 ) ;
int V_29 ;
V_29 = F_62 ( V_19 , & V_122 -> V_64 ) ;
if ( V_29 )
return V_29 ;
V_122 -> V_130 = F_70 ( & V_56 -> V_21 . V_72 ,
F_37 ( V_122 -> V_64 . V_45 ) , NULL ) ;
if ( ! V_122 -> V_130 )
return - V_17 ;
return 0 ;
}
void F_92 ( struct V_18 * V_19 , struct V_121 * V_122 ,
T_1 * V_127 , T_1 * V_128 )
{
struct V_46 * V_47 ;
int V_29 ;
if ( ! V_122 -> V_125 )
return;
V_122 -> V_125 = 0 ;
V_47 = F_63 ( V_19 ) ;
if ( F_64 ( V_47 ) ) {
V_29 = F_65 ( V_47 ) ;
F_93 ( V_136 L_8
L_9 , V_29 ) ;
return;
}
V_29 = F_39 ( V_19 , NULL ,
F_37 ( V_122 -> V_64 . V_45 ) &
( V_19 -> V_42 . V_76 - 1 ) ) ;
F_68 ( V_19 , V_47 ) ;
if ( V_29 ) {
F_93 ( V_136 L_10 ,
V_29 ) ;
return;
}
V_122 -> V_64 . V_65 = V_77 ;
}
int F_94 ( struct V_18 * V_19 , struct V_121 * V_122 )
{
if ( V_122 -> V_125 )
return - V_137 ;
F_61 ( V_19 , & V_122 -> V_64 ) ;
V_122 -> V_64 . V_65 = V_66 ;
return 0 ;
}
int F_95 ( struct V_18 * V_19 , struct V_121 * V_122 )
{
if ( V_122 -> V_125 )
return - V_137 ;
F_60 ( V_19 , & V_122 -> V_64 ) ;
V_122 -> V_64 . V_65 = V_66 ;
return 0 ;
}
int F_96 ( struct V_18 * V_19 )
{
return F_32 ( V_19 , 0 , 0 , 0 , V_138 , 1000 ,
V_34 ) ;
}
