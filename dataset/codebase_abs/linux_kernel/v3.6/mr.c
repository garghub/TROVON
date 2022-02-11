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
V_2 -> V_10 = F_11 ( V_2 -> V_8 + 1 , sizeof ( long * ) ,
V_14 ) ;
V_2 -> V_9 = F_11 ( ( V_2 -> V_8 + 1 ) , sizeof * V_2 -> V_9 ,
V_14 ) ;
if ( ! V_2 -> V_10 || ! V_2 -> V_9 )
goto V_15;
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 ) {
V_13 = F_12 ( 1 << ( V_2 -> V_8 - V_12 ) ) ;
V_2 -> V_10 [ V_12 ] = F_11 ( V_13 , sizeof ( long ) , V_14 | V_16 ) ;
if ( ! V_2 -> V_10 [ V_12 ] ) {
V_2 -> V_10 [ V_12 ] = F_13 ( V_13 * sizeof( long ) ) ;
if ( ! V_2 -> V_10 [ V_12 ] )
goto V_17;
}
}
F_6 ( 0 , V_2 -> V_10 [ V_2 -> V_8 ] ) ;
V_2 -> V_9 [ V_2 -> V_8 ] = 1 ;
return 0 ;
V_17:
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 )
if ( V_2 -> V_10 [ V_12 ] && F_14 ( V_2 -> V_10 [ V_12 ] ) )
F_15 ( V_2 -> V_10 [ V_12 ] ) ;
else
F_16 ( V_2 -> V_10 [ V_12 ] ) ;
V_15:
F_16 ( V_2 -> V_10 ) ;
F_16 ( V_2 -> V_9 ) ;
return - V_18 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 )
if ( F_14 ( V_2 -> V_10 [ V_12 ] ) )
F_15 ( V_2 -> V_10 [ V_12 ] ) ;
else
F_16 ( V_2 -> V_10 [ V_12 ] ) ;
F_16 ( V_2 -> V_10 ) ;
F_16 ( V_2 -> V_9 ) ;
}
T_1 F_18 ( struct V_19 * V_20 , int V_3 )
{
struct V_21 * V_22 = & F_19 ( V_20 ) -> V_22 ;
T_1 V_6 ;
int V_23 ;
T_1 V_24 ;
V_23 = F_20 ( int , V_3 - V_25 , 0 ) ;
V_6 = F_1 ( & V_22 -> V_26 , V_23 ) ;
if ( V_6 == - 1 )
return - 1 ;
V_24 = V_6 * ( 1 << V_25 ) ;
if ( F_21 ( V_20 , & V_22 -> V_27 , V_24 ,
V_24 + ( 1 << V_3 ) - 1 ) ) {
F_7 ( & V_22 -> V_26 , V_6 , V_23 ) ;
return - 1 ;
}
return V_24 ;
}
static T_1 F_22 ( struct V_19 * V_20 , int V_3 )
{
T_2 V_28 ;
T_2 V_29 ;
int V_30 ;
if ( F_23 ( V_20 ) ) {
F_24 ( & V_28 , V_3 ) ;
V_30 = F_25 ( V_20 , V_28 , & V_29 , V_31 ,
V_32 ,
V_33 ,
V_34 ,
V_35 ) ;
if ( V_30 )
return - 1 ;
return F_26 ( & V_29 ) ;
}
return F_18 ( V_20 , V_3 ) ;
}
int F_27 ( struct V_19 * V_20 , int V_36 , int V_37 ,
struct V_38 * V_39 )
{
int V_12 ;
if ( ! V_36 ) {
V_39 -> V_3 = - 1 ;
V_39 -> V_37 = V_40 ;
return 0 ;
} else
V_39 -> V_37 = V_37 ;
for ( V_39 -> V_3 = 0 , V_12 = 1 ; V_12 < V_36 ; V_12 <<= 1 )
++ V_39 -> V_3 ;
V_39 -> V_24 = F_22 ( V_20 , V_39 -> V_3 ) ;
if ( V_39 -> V_24 == - 1 )
return - V_18 ;
return 0 ;
}
void F_28 ( struct V_19 * V_20 , T_1 V_24 , int V_3 )
{
T_1 V_41 ;
int V_23 ;
struct V_21 * V_22 = & F_19 ( V_20 ) -> V_22 ;
V_23 = F_20 ( int , V_3 - V_25 , 0 ) ;
V_41 = V_24 / ( 1 << V_25 ) ;
F_7 ( & V_22 -> V_26 , V_41 , V_23 ) ;
F_29 ( V_20 , & V_22 -> V_27 , V_24 ,
V_24 + ( 1 << V_3 ) - 1 ) ;
}
static void F_30 ( struct V_19 * V_20 , T_1 V_24 , int V_3 )
{
T_2 V_28 ;
int V_30 ;
if ( F_23 ( V_20 ) ) {
F_24 ( & V_28 , V_24 ) ;
F_31 ( & V_28 , V_3 ) ;
V_30 = F_32 ( V_20 , V_28 , V_31 , V_32 ,
V_42 ,
V_34 ,
V_35 ) ;
if ( V_30 )
F_33 ( V_20 , L_1
L_2 , V_24 , V_3 ) ;
return;
}
F_28 ( V_20 , V_24 , V_3 ) ;
}
void F_34 ( struct V_19 * V_20 , struct V_38 * V_39 )
{
if ( V_39 -> V_3 < 0 )
return;
F_30 ( V_20 , V_39 -> V_24 , V_39 -> V_3 ) ;
}
T_2 F_35 ( struct V_19 * V_20 , struct V_38 * V_39 )
{
return ( T_2 ) V_39 -> V_24 * V_20 -> V_43 . V_44 ;
}
static T_1 F_36 ( T_1 V_45 )
{
return ( V_45 >> 24 ) | ( V_45 << 8 ) ;
}
static T_1 F_37 ( T_1 V_46 )
{
return ( V_46 << 24 ) | ( V_46 >> 8 ) ;
}
static int F_38 ( struct V_19 * V_20 , struct V_47 * V_48 ,
int V_49 )
{
return F_32 ( V_20 , V_48 -> V_50 , V_49 ,
0 , V_51 , V_52 ,
V_35 ) ;
}
static int F_39 ( struct V_19 * V_20 , struct V_47 * V_48 ,
int V_49 )
{
return F_40 ( V_20 , 0 , V_48 ? V_48 -> V_50 : 0 , V_49 ,
! V_48 , V_53 ,
V_52 , V_35 ) ;
}
static int F_41 ( struct V_19 * V_20 , T_1 V_54 , T_1 V_55 ,
T_2 V_56 , T_2 V_57 , T_1 V_58 , int V_36 ,
int V_37 , struct V_59 * V_60 )
{
V_60 -> V_56 = V_56 ;
V_60 -> V_57 = V_57 ;
V_60 -> V_55 = V_55 ;
V_60 -> V_58 = V_58 ;
V_60 -> V_61 = V_62 ;
V_60 -> V_46 = F_36 ( V_54 ) ;
return F_27 ( V_20 , V_36 , V_37 , & V_60 -> V_39 ) ;
}
static int F_42 ( struct V_19 * V_20 ,
struct V_47 * V_48 ,
int V_63 )
{
return F_32 ( V_20 , V_48 -> V_50 , V_63 , 0 , V_64 ,
V_34 , V_35 ) ;
}
int F_43 ( struct V_19 * V_20 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
return F_44 ( & V_65 -> V_22 . V_66 ) ;
}
static int F_45 ( struct V_19 * V_20 )
{
T_2 V_29 ;
if ( F_23 ( V_20 ) ) {
if ( F_25 ( V_20 , 0 , & V_29 , V_67 , V_68 ,
V_33 ,
V_34 , V_35 ) )
return - 1 ;
return F_26 ( & V_29 ) ;
}
return F_43 ( V_20 ) ;
}
void F_46 ( struct V_19 * V_20 , T_1 V_69 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
F_47 ( & V_65 -> V_22 . V_66 , V_69 ) ;
}
static void F_48 ( struct V_19 * V_20 , T_1 V_69 )
{
T_2 V_28 ;
if ( F_23 ( V_20 ) ) {
F_24 ( & V_28 , V_69 ) ;
if ( F_32 ( V_20 , V_28 , V_67 , V_68 ,
V_42 ,
V_34 , V_35 ) )
F_33 ( V_20 , L_3 ,
V_69 ) ;
return;
}
F_46 ( V_20 , V_69 ) ;
}
int F_49 ( struct V_19 * V_20 , T_1 V_69 )
{
struct V_21 * V_22 = & F_19 ( V_20 ) -> V_22 ;
return F_50 ( V_20 , & V_22 -> V_70 , V_69 ) ;
}
static int F_51 ( struct V_19 * V_20 , T_1 V_69 )
{
T_2 V_71 ;
if ( F_23 ( V_20 ) ) {
F_24 ( & V_71 , V_69 ) ;
return F_25 ( V_20 , V_71 , & V_71 , V_67 , V_72 ,
V_33 ,
V_34 ,
V_35 ) ;
}
return F_49 ( V_20 , V_69 ) ;
}
void F_52 ( struct V_19 * V_20 , T_1 V_69 )
{
struct V_21 * V_22 = & F_19 ( V_20 ) -> V_22 ;
F_53 ( V_20 , & V_22 -> V_70 , V_69 ) ;
}
static void F_54 ( struct V_19 * V_20 , T_1 V_69 )
{
T_2 V_28 ;
if ( F_23 ( V_20 ) ) {
F_24 ( & V_28 , V_69 ) ;
if ( F_32 ( V_20 , V_28 , V_67 , V_72 ,
V_42 , V_34 ,
V_35 ) )
F_33 ( V_20 , L_4 ,
V_69 ) ;
return;
}
return F_52 ( V_20 , V_69 ) ;
}
int F_55 ( struct V_19 * V_20 , T_1 V_55 , T_2 V_56 , T_2 V_57 , T_1 V_58 ,
int V_36 , int V_37 , struct V_59 * V_60 )
{
T_1 V_69 ;
int V_30 ;
V_69 = F_45 ( V_20 ) ;
if ( V_69 == - 1 )
return - V_18 ;
V_30 = F_41 ( V_20 , V_69 , V_55 , V_56 , V_57 ,
V_58 , V_36 , V_37 , V_60 ) ;
if ( V_30 )
F_48 ( V_20 , V_69 ) ;
return V_30 ;
}
static void F_56 ( struct V_19 * V_20 , struct V_59 * V_60 )
{
int V_30 ;
if ( V_60 -> V_61 == V_73 ) {
V_30 = F_39 ( V_20 , NULL ,
F_37 ( V_60 -> V_46 ) &
( V_20 -> V_43 . V_74 - 1 ) ) ;
if ( V_30 )
F_33 ( V_20 , L_5 , V_30 ) ;
V_60 -> V_61 = V_75 ;
}
F_34 ( V_20 , & V_60 -> V_39 ) ;
}
void F_57 ( struct V_19 * V_20 , struct V_59 * V_60 )
{
F_56 ( V_20 , V_60 ) ;
if ( V_60 -> V_61 )
F_54 ( V_20 , F_37 ( V_60 -> V_46 ) ) ;
F_48 ( V_20 , F_37 ( V_60 -> V_46 ) ) ;
}
int F_58 ( struct V_19 * V_20 , struct V_59 * V_60 )
{
struct V_47 * V_48 ;
struct V_76 * V_77 ;
int V_30 ;
V_30 = F_51 ( V_20 , F_37 ( V_60 -> V_46 ) ) ;
if ( V_30 )
return V_30 ;
V_48 = F_59 ( V_20 ) ;
if ( F_60 ( V_48 ) ) {
V_30 = F_61 ( V_48 ) ;
goto V_78;
}
V_77 = V_48 -> V_79 ;
memset ( V_77 , 0 , sizeof *V_77 ) ;
V_77 -> V_80 = F_62 ( V_81 |
V_82 |
V_60 -> V_58 ) ;
V_77 -> V_46 = F_62 ( F_37 ( V_60 -> V_46 ) ) ;
V_77 -> V_83 = F_62 ( V_60 -> V_55 | V_84 ) ;
V_77 -> V_85 = F_63 ( V_60 -> V_56 ) ;
V_77 -> V_86 = F_63 ( V_60 -> V_57 ) ;
V_77 -> V_87 = F_62 ( V_60 -> V_39 . V_37 ) ;
if ( V_60 -> V_39 . V_3 < 0 ) {
V_77 -> V_80 |= F_62 ( V_88 ) ;
V_77 -> V_89 = 0 ;
} else {
V_77 -> V_89 = F_63 ( F_35 ( V_20 ,
& V_60 -> V_39 ) ) ;
}
if ( V_60 -> V_39 . V_3 >= 0 && V_60 -> V_39 . V_37 == 0 ) {
V_77 -> V_80 |= F_62 ( V_90 ) ;
V_77 -> V_83 |= F_62 ( V_91 |
V_92 ) ;
V_77 -> V_93 = F_62 ( 1 << V_60 -> V_39 . V_3 ) ;
} else {
V_77 -> V_80 |= F_62 ( V_94 ) ;
}
V_30 = F_38 ( V_20 , V_48 ,
F_37 ( V_60 -> V_46 ) & ( V_20 -> V_43 . V_74 - 1 ) ) ;
if ( V_30 ) {
F_33 ( V_20 , L_6 , V_30 ) ;
goto V_95;
}
V_60 -> V_61 = V_73 ;
F_64 ( V_20 , V_48 ) ;
return 0 ;
V_95:
F_64 ( V_20 , V_48 ) ;
V_78:
F_54 ( V_20 , F_37 ( V_60 -> V_46 ) ) ;
return V_30 ;
}
static int F_65 ( struct V_19 * V_20 , struct V_38 * V_39 ,
int V_96 , int V_36 , T_2 * V_97 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
T_3 * V_98 ;
T_4 V_99 ;
int V_12 ;
V_98 = F_66 ( & V_65 -> V_22 . V_27 , V_39 -> V_24 +
V_96 , & V_99 ) ;
if ( ! V_98 )
return - V_18 ;
F_67 ( & V_20 -> V_100 -> V_20 , V_99 ,
V_36 * sizeof ( T_2 ) , V_101 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_98 [ V_12 ] = F_63 ( V_97 [ V_12 ] | V_102 ) ;
F_68 ( & V_20 -> V_100 -> V_20 , V_99 ,
V_36 * sizeof ( T_2 ) , V_101 ) ;
return 0 ;
}
int F_69 ( struct V_19 * V_20 , struct V_38 * V_39 ,
int V_96 , int V_36 , T_2 * V_97 )
{
int V_30 = 0 ;
int V_103 ;
int V_104 ;
int V_105 ;
V_104 = V_106 / sizeof( T_2 ) ;
V_105 = V_104 - ( V_39 -> V_24 + V_96 )
% V_104 ;
V_103 = F_70 ( int , V_105 , V_36 ) ;
while ( V_36 > 0 ) {
V_30 = F_65 ( V_20 , V_39 , V_96 , V_103 , V_97 ) ;
if ( V_30 )
return V_30 ;
V_36 -= V_103 ;
V_96 += V_103 ;
V_97 += V_103 ;
V_103 = F_70 ( int , V_104 , V_36 ) ;
}
return V_30 ;
}
int F_71 ( struct V_19 * V_20 , struct V_38 * V_39 ,
int V_96 , int V_36 , T_2 * V_97 )
{
struct V_47 * V_48 = NULL ;
T_3 * V_107 = NULL ;
int V_103 ;
int V_30 = 0 ;
int V_12 ;
if ( V_39 -> V_3 < 0 )
return - V_108 ;
if ( F_23 ( V_20 ) ) {
V_48 = F_59 ( V_20 ) ;
if ( F_60 ( V_48 ) )
return F_61 ( V_48 ) ;
V_107 = V_48 -> V_79 ;
while ( V_36 > 0 ) {
V_103 = F_70 ( int , V_109 / sizeof( T_2 ) - 2 ,
V_36 ) ;
V_107 [ 0 ] = F_63 ( V_39 -> V_24 + V_96 ) ;
V_107 [ 1 ] = 0 ;
for ( V_12 = 0 ; V_12 < V_103 ; ++ V_12 )
V_107 [ V_12 + 2 ] = F_63 ( V_97 [ V_12 ] |
V_102 ) ;
V_30 = F_42 ( V_20 , V_48 , V_103 ) ;
if ( V_30 ) {
F_64 ( V_20 , V_48 ) ;
return V_30 ;
}
V_36 -= V_103 ;
V_96 += V_103 ;
V_97 += V_103 ;
}
F_64 ( V_20 , V_48 ) ;
return V_30 ;
}
return F_69 ( V_20 , V_39 , V_96 , V_36 , V_97 ) ;
}
int F_72 ( struct V_19 * V_20 , struct V_38 * V_39 ,
struct V_110 * V_79 )
{
T_2 * V_97 ;
int V_30 ;
int V_12 ;
V_97 = F_73 ( V_79 -> V_36 * sizeof *V_97 , V_14 ) ;
if ( ! V_97 )
return - V_18 ;
for ( V_12 = 0 ; V_12 < V_79 -> V_36 ; ++ V_12 )
if ( V_79 -> V_111 == 1 )
V_97 [ V_12 ] = V_79 -> V_112 . V_113 + ( V_12 << V_79 -> V_37 ) ;
else
V_97 [ V_12 ] = V_79 -> V_97 [ V_12 ] . V_113 ;
V_30 = F_71 ( V_20 , V_39 , 0 , V_79 -> V_36 , V_97 ) ;
F_16 ( V_97 ) ;
return V_30 ;
}
int F_74 ( struct V_19 * V_20 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
struct V_21 * V_22 = & V_65 -> V_22 ;
int V_30 ;
if ( ! F_75 ( V_20 -> V_43 . V_74 ) )
return - V_108 ;
if ( F_76 ( V_20 ) )
return 0 ;
V_30 = F_77 ( & V_22 -> V_66 , V_20 -> V_43 . V_74 ,
~ 0 , V_20 -> V_43 . V_114 , 0 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_9 ( & V_22 -> V_26 ,
F_78 ( ( T_1 ) V_20 -> V_43 . V_115 /
( 1 << V_25 ) ) ) ;
if ( V_30 )
goto V_116;
if ( V_20 -> V_43 . V_117 ) {
V_65 -> V_117 =
F_22 ( V_20 ,
F_79 ( V_20 -> V_43 . V_117 - 1 ) ) ;
if ( V_65 -> V_117 < 0 ) {
F_33 ( V_20 , L_7 ,
V_22 -> V_26 . V_8 ) ;
V_30 = - V_18 ;
goto V_118;
}
}
return 0 ;
V_118:
F_17 ( & V_22 -> V_26 ) ;
V_116:
F_80 ( & V_22 -> V_66 ) ;
return V_30 ;
}
void F_81 ( struct V_19 * V_20 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
struct V_21 * V_22 = & V_65 -> V_22 ;
if ( F_76 ( V_20 ) )
return;
if ( V_65 -> V_117 >= 0 )
F_30 ( V_20 , V_65 -> V_117 ,
F_79 ( V_20 -> V_43 . V_117 - 1 ) ) ;
F_17 ( & V_22 -> V_26 ) ;
F_80 ( & V_22 -> V_66 ) ;
}
static inline int F_82 ( struct V_119 * V_120 , T_2 * V_97 ,
int V_36 , T_2 V_56 )
{
int V_12 , V_121 ;
if ( V_36 > V_120 -> V_122 )
return - V_108 ;
V_121 = ( 1 << V_120 -> V_37 ) - 1 ;
if ( V_56 & V_121 )
return - V_108 ;
if ( 0 )
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
if ( V_97 [ V_12 ] & ~ V_121 )
return - V_108 ;
}
if ( V_120 -> V_123 >= V_120 -> V_124 )
return - V_108 ;
return 0 ;
}
int F_83 ( struct V_19 * V_20 , struct V_119 * V_120 , T_2 * V_97 ,
int V_36 , T_2 V_56 , T_1 * V_125 , T_1 * V_126 )
{
T_1 V_46 ;
int V_12 , V_30 ;
V_30 = F_82 ( V_120 , V_97 , V_36 , V_56 ) ;
if ( V_30 )
return V_30 ;
++ V_120 -> V_123 ;
V_46 = F_37 ( V_120 -> V_60 . V_46 ) ;
V_46 += V_20 -> V_43 . V_74 ;
* V_125 = * V_126 = V_120 -> V_60 . V_46 = F_36 ( V_46 ) ;
* ( V_127 * ) V_120 -> V_128 = V_129 ;
F_84 () ;
F_67 ( & V_20 -> V_100 -> V_20 , V_120 -> V_99 ,
V_36 * sizeof( T_2 ) , V_101 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_120 -> V_98 [ V_12 ] = F_63 ( V_97 [ V_12 ] | V_102 ) ;
F_68 ( & V_20 -> V_100 -> V_20 , V_120 -> V_99 ,
V_36 * sizeof( T_2 ) , V_101 ) ;
V_120 -> V_128 -> V_46 = F_62 ( V_46 ) ;
V_120 -> V_128 -> V_125 = F_62 ( V_46 ) ;
V_120 -> V_128 -> V_86 = F_63 ( V_36 * ( 1ull << V_120 -> V_37 ) ) ;
V_120 -> V_128 -> V_85 = F_63 ( V_56 ) ;
F_84 () ;
* ( V_127 * ) V_120 -> V_128 = V_130 ;
F_84 () ;
return 0 ;
}
int F_85 ( struct V_19 * V_20 , T_1 V_55 , T_1 V_58 , int V_122 ,
int V_124 , V_127 V_37 , struct V_119 * V_120 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
int V_30 = - V_18 ;
if ( V_124 > V_20 -> V_43 . V_131 )
return - V_108 ;
if ( V_37 < ( F_86 ( V_20 -> V_43 . V_132 ) - 1 ) || V_37 >= 32 )
return - V_108 ;
if ( V_122 * sizeof * V_120 -> V_98 > V_106 )
return - V_108 ;
V_120 -> V_37 = V_37 ;
V_120 -> V_122 = V_122 ;
V_120 -> V_124 = V_124 ;
V_120 -> V_123 = 0 ;
V_30 = F_55 ( V_20 , V_55 , 0 , 0 , V_58 , V_122 ,
V_37 , & V_120 -> V_60 ) ;
if ( V_30 )
return V_30 ;
V_120 -> V_98 = F_66 ( & V_65 -> V_22 . V_27 ,
V_120 -> V_60 . V_39 . V_24 ,
& V_120 -> V_99 ) ;
if ( ! V_120 -> V_98 ) {
V_30 = - V_18 ;
goto V_133;
}
return 0 ;
V_133:
F_57 ( V_20 , & V_120 -> V_60 ) ;
return V_30 ;
}
int F_87 ( struct V_19 * V_20 , struct V_119 * V_120 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
int V_30 ;
V_30 = F_58 ( V_20 , & V_120 -> V_60 ) ;
if ( V_30 )
return V_30 ;
V_120 -> V_128 = F_66 ( & V_65 -> V_22 . V_70 ,
F_37 ( V_120 -> V_60 . V_46 ) , NULL ) ;
if ( ! V_120 -> V_128 )
return - V_18 ;
return 0 ;
}
void F_88 ( struct V_19 * V_20 , struct V_119 * V_120 ,
T_1 * V_125 , T_1 * V_126 )
{
struct V_47 * V_48 ;
int V_30 ;
if ( ! V_120 -> V_123 )
return;
V_120 -> V_123 = 0 ;
V_48 = F_59 ( V_20 ) ;
if ( F_60 ( V_48 ) ) {
V_30 = F_61 ( V_48 ) ;
F_89 ( V_134 L_8
L_9 , V_30 ) ;
return;
}
V_30 = F_39 ( V_20 , NULL ,
F_37 ( V_120 -> V_60 . V_46 ) &
( V_20 -> V_43 . V_74 - 1 ) ) ;
F_64 ( V_20 , V_48 ) ;
if ( V_30 ) {
F_89 ( V_134 L_10 ,
V_30 ) ;
return;
}
V_120 -> V_60 . V_61 = V_75 ;
}
int F_90 ( struct V_19 * V_20 , struct V_119 * V_120 )
{
if ( V_120 -> V_123 )
return - V_135 ;
F_57 ( V_20 , & V_120 -> V_60 ) ;
V_120 -> V_60 . V_61 = V_62 ;
return 0 ;
}
int F_91 ( struct V_19 * V_20 )
{
return F_32 ( V_20 , 0 , 0 , 0 , V_136 , 1000 ,
V_137 ) ;
}
