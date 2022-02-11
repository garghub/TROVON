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
T_2 V_28 = 0 ;
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
T_2 V_28 = 0 ;
int V_30 ;
if ( F_23 ( V_20 ) ) {
F_24 ( & V_28 , V_24 ) ;
F_31 ( & V_28 , V_3 ) ;
V_30 = F_32 ( V_20 , V_28 , V_31 , V_32 ,
V_42 ,
V_34 ,
V_35 ) ;
if ( V_30 )
F_33 ( V_20 , L_1 ,
V_24 , V_3 ) ;
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
F_47 ( & V_65 -> V_22 . V_66 , V_69 , V_70 ) ;
}
static void F_48 ( struct V_19 * V_20 , T_1 V_69 )
{
T_2 V_28 = 0 ;
if ( F_23 ( V_20 ) ) {
F_24 ( & V_28 , V_69 ) ;
if ( F_32 ( V_20 , V_28 , V_67 , V_68 ,
V_42 ,
V_34 , V_35 ) )
F_33 ( V_20 , L_2 ,
V_69 ) ;
return;
}
F_46 ( V_20 , V_69 ) ;
}
int F_49 ( struct V_19 * V_20 , T_1 V_69 , T_3 V_71 )
{
struct V_21 * V_22 = & F_19 ( V_20 ) -> V_22 ;
return F_50 ( V_20 , & V_22 -> V_72 , V_69 , V_71 ) ;
}
static int F_51 ( struct V_19 * V_20 , T_1 V_69 , T_3 V_71 )
{
T_2 V_73 = 0 ;
if ( F_23 ( V_20 ) ) {
F_24 ( & V_73 , V_69 ) ;
return F_25 ( V_20 , V_73 , & V_73 , V_67 , V_74 ,
V_33 ,
V_34 ,
V_35 ) ;
}
return F_49 ( V_20 , V_69 , V_71 ) ;
}
void F_52 ( struct V_19 * V_20 , T_1 V_69 )
{
struct V_21 * V_22 = & F_19 ( V_20 ) -> V_22 ;
F_53 ( V_20 , & V_22 -> V_72 , V_69 ) ;
}
static void F_54 ( struct V_19 * V_20 , T_1 V_69 )
{
T_2 V_28 = 0 ;
if ( F_23 ( V_20 ) ) {
F_24 ( & V_28 , V_69 ) ;
if ( F_32 ( V_20 , V_28 , V_67 , V_74 ,
V_42 , V_34 ,
V_35 ) )
F_33 ( V_20 , L_3 ,
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
static int F_56 ( struct V_19 * V_20 , struct V_59 * V_60 )
{
int V_30 ;
if ( V_60 -> V_61 == V_75 ) {
V_30 = F_39 ( V_20 , NULL ,
F_37 ( V_60 -> V_46 ) &
( V_20 -> V_43 . V_76 - 1 ) ) ;
if ( V_30 ) {
F_33 ( V_20 , L_4 ,
V_30 ) ;
return V_30 ;
}
V_60 -> V_61 = V_77 ;
}
F_34 ( V_20 , & V_60 -> V_39 ) ;
return 0 ;
}
int F_57 ( struct V_19 * V_20 , struct V_59 * V_60 )
{
int V_78 ;
V_78 = F_56 ( V_20 , V_60 ) ;
if ( V_78 )
return V_78 ;
if ( V_60 -> V_61 )
F_54 ( V_20 , F_37 ( V_60 -> V_46 ) ) ;
F_48 ( V_20 , F_37 ( V_60 -> V_46 ) ) ;
return 0 ;
}
int F_58 ( struct V_19 * V_20 , struct V_59 * V_60 )
{
struct V_47 * V_48 ;
struct V_79 * V_80 ;
int V_30 ;
V_30 = F_51 ( V_20 , F_37 ( V_60 -> V_46 ) , V_14 ) ;
if ( V_30 )
return V_30 ;
V_48 = F_59 ( V_20 ) ;
if ( F_60 ( V_48 ) ) {
V_30 = F_61 ( V_48 ) ;
goto V_81;
}
V_80 = V_48 -> V_82 ;
V_80 -> V_83 = F_62 ( V_84 |
V_85 |
V_60 -> V_58 ) ;
V_80 -> V_46 = F_62 ( F_37 ( V_60 -> V_46 ) ) ;
V_80 -> V_86 = F_62 ( V_60 -> V_55 | V_87 ) ;
V_80 -> V_88 = F_63 ( V_60 -> V_56 ) ;
V_80 -> V_89 = F_63 ( V_60 -> V_57 ) ;
V_80 -> V_90 = F_62 ( V_60 -> V_39 . V_37 ) ;
if ( V_60 -> V_39 . V_3 < 0 ) {
V_80 -> V_83 |= F_62 ( V_91 ) ;
V_80 -> V_92 = 0 ;
} else {
V_80 -> V_92 = F_63 ( F_35 ( V_20 ,
& V_60 -> V_39 ) ) ;
}
if ( V_60 -> V_39 . V_3 >= 0 && V_60 -> V_39 . V_37 == 0 ) {
V_80 -> V_83 |= F_62 ( V_93 ) ;
V_80 -> V_86 |= F_62 ( V_94 |
V_95 ) ;
V_80 -> V_96 = F_62 ( 1 << V_60 -> V_39 . V_3 ) ;
} else {
V_80 -> V_83 |= F_62 ( V_97 ) ;
}
V_30 = F_38 ( V_20 , V_48 ,
F_37 ( V_60 -> V_46 ) & ( V_20 -> V_43 . V_76 - 1 ) ) ;
if ( V_30 ) {
F_33 ( V_20 , L_5 , V_30 ) ;
goto V_98;
}
V_60 -> V_61 = V_75 ;
F_64 ( V_20 , V_48 ) ;
return 0 ;
V_98:
F_64 ( V_20 , V_48 ) ;
V_81:
F_54 ( V_20 , F_37 ( V_60 -> V_46 ) ) ;
return V_30 ;
}
static int F_65 ( struct V_19 * V_20 , struct V_38 * V_39 ,
int V_99 , int V_36 , T_2 * V_100 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
T_4 * V_101 ;
T_5 V_102 ;
int V_12 ;
V_101 = F_66 ( & V_65 -> V_22 . V_27 , V_39 -> V_24 +
V_99 , & V_102 ) ;
if ( ! V_101 )
return - V_18 ;
F_67 ( & V_20 -> V_103 -> V_20 , V_102 ,
V_36 * sizeof ( T_2 ) , V_104 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_101 [ V_12 ] = F_63 ( V_100 [ V_12 ] | V_105 ) ;
F_68 ( & V_20 -> V_103 -> V_20 , V_102 ,
V_36 * sizeof ( T_2 ) , V_104 ) ;
return 0 ;
}
int F_69 ( struct V_19 * V_20 , struct V_38 * V_39 ,
int V_99 , int V_36 , T_2 * V_100 )
{
int V_30 = 0 ;
int V_106 ;
int V_107 ;
int V_108 ;
V_107 = V_109 / sizeof( T_2 ) ;
V_108 = V_107 - ( V_39 -> V_24 + V_99 )
% V_107 ;
V_106 = F_70 ( int , V_108 , V_36 ) ;
while ( V_36 > 0 ) {
V_30 = F_65 ( V_20 , V_39 , V_99 , V_106 , V_100 ) ;
if ( V_30 )
return V_30 ;
V_36 -= V_106 ;
V_99 += V_106 ;
V_100 += V_106 ;
V_106 = F_70 ( int , V_107 , V_36 ) ;
}
return V_30 ;
}
int F_71 ( struct V_19 * V_20 , struct V_38 * V_39 ,
int V_99 , int V_36 , T_2 * V_100 )
{
struct V_47 * V_48 = NULL ;
T_4 * V_110 = NULL ;
int V_106 ;
int V_30 = 0 ;
int V_12 ;
if ( V_39 -> V_3 < 0 )
return - V_111 ;
if ( F_23 ( V_20 ) ) {
V_48 = F_59 ( V_20 ) ;
if ( F_60 ( V_48 ) )
return F_61 ( V_48 ) ;
V_110 = V_48 -> V_82 ;
while ( V_36 > 0 ) {
V_106 = F_70 ( int , V_112 / sizeof( T_2 ) - 2 ,
V_36 ) ;
V_110 [ 0 ] = F_63 ( V_39 -> V_24 + V_99 ) ;
V_110 [ 1 ] = 0 ;
for ( V_12 = 0 ; V_12 < V_106 ; ++ V_12 )
V_110 [ V_12 + 2 ] = F_63 ( V_100 [ V_12 ] |
V_105 ) ;
V_30 = F_42 ( V_20 , V_48 , V_106 ) ;
if ( V_30 ) {
F_64 ( V_20 , V_48 ) ;
return V_30 ;
}
V_36 -= V_106 ;
V_99 += V_106 ;
V_100 += V_106 ;
}
F_64 ( V_20 , V_48 ) ;
return V_30 ;
}
return F_69 ( V_20 , V_39 , V_99 , V_36 , V_100 ) ;
}
int F_72 ( struct V_19 * V_20 , struct V_38 * V_39 ,
struct V_113 * V_82 , T_3 V_71 )
{
T_2 * V_100 ;
int V_30 ;
int V_12 ;
V_100 = F_73 ( V_82 -> V_36 * sizeof *V_100 ,
V_71 ) ;
if ( ! V_100 )
return - V_18 ;
for ( V_12 = 0 ; V_12 < V_82 -> V_36 ; ++ V_12 )
if ( V_82 -> V_114 == 1 )
V_100 [ V_12 ] = V_82 -> V_115 . V_116 + ( V_12 << V_82 -> V_37 ) ;
else
V_100 [ V_12 ] = V_82 -> V_100 [ V_12 ] . V_116 ;
V_30 = F_71 ( V_20 , V_39 , 0 , V_82 -> V_36 , V_100 ) ;
F_16 ( V_100 ) ;
return V_30 ;
}
int F_74 ( struct V_19 * V_20 , T_1 V_55 , enum V_117 type ,
struct V_118 * V_119 )
{
T_1 V_69 ;
if ( ( type == V_120 &&
! ( V_20 -> V_43 . V_83 & V_121 ) ) ||
( type == V_122 &&
! ( V_20 -> V_43 . V_123 & V_124 ) ) )
return - V_125 ;
V_69 = F_45 ( V_20 ) ;
if ( V_69 == - 1 )
return - V_18 ;
V_119 -> V_46 = F_36 ( V_69 ) ;
V_119 -> V_55 = V_55 ;
V_119 -> type = type ;
V_119 -> V_61 = V_62 ;
return 0 ;
}
int F_75 ( struct V_19 * V_20 , struct V_118 * V_119 )
{
struct V_47 * V_48 ;
struct V_79 * V_80 ;
int V_30 ;
V_30 = F_51 ( V_20 , F_37 ( V_119 -> V_46 ) , V_14 ) ;
if ( V_30 )
return V_30 ;
V_48 = F_59 ( V_20 ) ;
if ( F_60 ( V_48 ) ) {
V_30 = F_61 ( V_48 ) ;
goto V_81;
}
V_80 = V_48 -> V_82 ;
V_80 -> V_46 = F_62 ( F_37 ( V_119 -> V_46 ) ) ;
V_80 -> V_86 = F_62 ( V_119 -> V_55 ) ;
if ( V_119 -> type == V_122 ) {
V_80 -> V_83 |= F_62 ( V_93 ) ;
V_80 -> V_126 = F_62 ( V_127 ) ;
V_80 -> V_86 |= F_62 ( V_87 ) ;
}
V_30 = F_38 ( V_20 , V_48 ,
F_37 ( V_119 -> V_46 ) &
( V_20 -> V_43 . V_76 - 1 ) ) ;
if ( V_30 ) {
F_33 ( V_20 , L_5 , V_30 ) ;
goto V_98;
}
V_119 -> V_61 = V_75 ;
F_64 ( V_20 , V_48 ) ;
return 0 ;
V_98:
F_64 ( V_20 , V_48 ) ;
V_81:
F_54 ( V_20 , F_37 ( V_119 -> V_46 ) ) ;
return V_30 ;
}
void F_76 ( struct V_19 * V_20 , struct V_118 * V_119 )
{
int V_30 ;
if ( V_119 -> V_61 == V_75 ) {
V_30 = F_39 ( V_20 , NULL ,
F_37 ( V_119 -> V_46 ) &
( V_20 -> V_43 . V_76 - 1 ) ) ;
if ( V_30 )
F_33 ( V_20 , L_6 , V_30 ) ;
V_119 -> V_61 = V_77 ;
}
if ( V_119 -> V_61 )
F_54 ( V_20 , F_37 ( V_119 -> V_46 ) ) ;
F_48 ( V_20 , F_37 ( V_119 -> V_46 ) ) ;
}
int F_77 ( struct V_19 * V_20 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
struct V_21 * V_22 = & V_65 -> V_22 ;
int V_30 ;
if ( F_78 ( V_20 ) )
return 0 ;
if ( ! F_79 ( V_20 -> V_43 . V_76 ) )
return - V_111 ;
V_30 = F_80 ( & V_22 -> V_66 , V_20 -> V_43 . V_76 ,
~ 0 , V_20 -> V_43 . V_128 , 0 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_9 ( & V_22 -> V_26 ,
F_81 ( ( T_1 ) V_20 -> V_43 . V_129 /
( 1 << V_25 ) ) ) ;
if ( V_30 )
goto V_130;
if ( V_20 -> V_43 . V_131 ) {
V_65 -> V_131 =
F_22 ( V_20 ,
F_82 ( V_20 -> V_43 . V_131 - 1 ) ) ;
if ( V_65 -> V_131 < 0 ) {
F_33 ( V_20 , L_7 ,
V_22 -> V_26 . V_8 ) ;
V_30 = - V_18 ;
goto V_132;
}
}
return 0 ;
V_132:
F_17 ( & V_22 -> V_26 ) ;
V_130:
F_83 ( & V_22 -> V_66 ) ;
return V_30 ;
}
void F_84 ( struct V_19 * V_20 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
struct V_21 * V_22 = & V_65 -> V_22 ;
if ( F_78 ( V_20 ) )
return;
if ( V_65 -> V_131 >= 0 )
F_30 ( V_20 , V_65 -> V_131 ,
F_82 ( V_20 -> V_43 . V_131 - 1 ) ) ;
F_17 ( & V_22 -> V_26 ) ;
F_83 ( & V_22 -> V_66 ) ;
}
static inline int F_85 ( struct V_133 * V_134 , T_2 * V_100 ,
int V_36 , T_2 V_56 )
{
int V_12 , V_135 ;
if ( V_36 > V_134 -> V_136 )
return - V_111 ;
V_135 = ( 1 << V_134 -> V_37 ) - 1 ;
if ( V_56 & V_135 )
return - V_111 ;
if ( 0 )
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
if ( V_100 [ V_12 ] & ~ V_135 )
return - V_111 ;
}
if ( V_134 -> V_137 >= V_134 -> V_138 )
return - V_111 ;
return 0 ;
}
int F_86 ( struct V_19 * V_20 , struct V_133 * V_134 , T_2 * V_100 ,
int V_36 , T_2 V_56 , T_1 * V_139 , T_1 * V_140 )
{
T_1 V_46 ;
int V_12 , V_30 ;
V_30 = F_85 ( V_134 , V_100 , V_36 , V_56 ) ;
if ( V_30 )
return V_30 ;
++ V_134 -> V_137 ;
V_46 = F_37 ( V_134 -> V_60 . V_46 ) ;
V_46 += V_20 -> V_43 . V_76 ;
* V_139 = * V_140 = V_134 -> V_60 . V_46 = F_36 ( V_46 ) ;
* ( V_141 * ) V_134 -> V_142 = V_143 ;
F_87 () ;
F_67 ( & V_20 -> V_103 -> V_20 , V_134 -> V_102 ,
V_36 * sizeof( T_2 ) , V_104 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_134 -> V_101 [ V_12 ] = F_63 ( V_100 [ V_12 ] | V_105 ) ;
F_68 ( & V_20 -> V_103 -> V_20 , V_134 -> V_102 ,
V_36 * sizeof( T_2 ) , V_104 ) ;
V_134 -> V_142 -> V_46 = F_62 ( V_46 ) ;
V_134 -> V_142 -> V_139 = F_62 ( V_46 ) ;
V_134 -> V_142 -> V_89 = F_63 ( V_36 * ( 1ull << V_134 -> V_37 ) ) ;
V_134 -> V_142 -> V_88 = F_63 ( V_56 ) ;
F_87 () ;
* ( V_141 * ) V_134 -> V_142 = V_144 ;
F_87 () ;
return 0 ;
}
int F_88 ( struct V_19 * V_20 , T_1 V_55 , T_1 V_58 , int V_136 ,
int V_138 , V_141 V_37 , struct V_133 * V_134 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
int V_30 = - V_18 ;
if ( V_138 > V_20 -> V_43 . V_145 )
return - V_111 ;
if ( V_37 < ( F_89 ( V_20 -> V_43 . V_146 ) - 1 ) || V_37 >= 32 )
return - V_111 ;
if ( V_136 * sizeof * V_134 -> V_101 > V_109 )
return - V_111 ;
V_134 -> V_37 = V_37 ;
V_134 -> V_136 = V_136 ;
V_134 -> V_138 = V_138 ;
V_134 -> V_137 = 0 ;
V_30 = F_55 ( V_20 , V_55 , 0 , 0 , V_58 , V_136 ,
V_37 , & V_134 -> V_60 ) ;
if ( V_30 )
return V_30 ;
V_134 -> V_101 = F_66 ( & V_65 -> V_22 . V_27 ,
V_134 -> V_60 . V_39 . V_24 ,
& V_134 -> V_102 ) ;
if ( ! V_134 -> V_101 ) {
V_30 = - V_18 ;
goto V_147;
}
return 0 ;
V_147:
( void ) F_57 ( V_20 , & V_134 -> V_60 ) ;
return V_30 ;
}
int F_90 ( struct V_19 * V_20 , struct V_133 * V_134 )
{
struct F_19 * V_65 = F_19 ( V_20 ) ;
int V_30 ;
V_30 = F_58 ( V_20 , & V_134 -> V_60 ) ;
if ( V_30 )
return V_30 ;
V_134 -> V_142 = F_66 ( & V_65 -> V_22 . V_72 ,
F_37 ( V_134 -> V_60 . V_46 ) , NULL ) ;
if ( ! V_134 -> V_142 )
return - V_18 ;
return 0 ;
}
void F_91 ( struct V_19 * V_20 , struct V_133 * V_134 ,
T_1 * V_139 , T_1 * V_140 )
{
struct V_47 * V_48 ;
int V_30 ;
if ( ! V_134 -> V_137 )
return;
V_134 -> V_137 = 0 ;
V_48 = F_59 ( V_20 ) ;
if ( F_60 ( V_48 ) ) {
V_30 = F_61 ( V_48 ) ;
F_92 ( L_8 , V_30 ) ;
return;
}
V_30 = F_39 ( V_20 , NULL ,
F_37 ( V_134 -> V_60 . V_46 ) &
( V_20 -> V_43 . V_76 - 1 ) ) ;
F_64 ( V_20 , V_48 ) ;
if ( V_30 ) {
F_92 ( L_9 , V_30 ) ;
return;
}
V_134 -> V_60 . V_61 = V_77 ;
}
int F_93 ( struct V_19 * V_20 , struct V_133 * V_134 )
{
int V_78 ;
if ( V_134 -> V_137 )
return - V_148 ;
V_78 = F_57 ( V_20 , & V_134 -> V_60 ) ;
if ( V_78 )
return V_78 ;
V_134 -> V_60 . V_61 = V_62 ;
return 0 ;
}
int F_94 ( struct V_19 * V_20 )
{
return F_32 ( V_20 , 0 , 0 , 0 , V_149 , 1000 ,
V_150 ) ;
}
