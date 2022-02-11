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
F_14 ( V_2 -> V_10 [ V_12 ] ) ;
V_15:
F_15 ( V_2 -> V_10 ) ;
F_15 ( V_2 -> V_9 ) ;
return - V_18 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 )
F_14 ( V_2 -> V_10 [ V_12 ] ) ;
F_15 ( V_2 -> V_10 ) ;
F_15 ( V_2 -> V_9 ) ;
}
T_1 F_17 ( struct V_19 * V_20 , int V_3 )
{
struct V_21 * V_22 = & F_18 ( V_20 ) -> V_22 ;
T_1 V_6 ;
int V_23 ;
T_1 V_24 ;
V_23 = F_19 ( int , V_3 - V_25 , 0 ) ;
V_6 = F_1 ( & V_22 -> V_26 , V_23 ) ;
if ( V_6 == - 1 )
return - 1 ;
V_24 = V_6 * ( 1 << V_25 ) ;
if ( F_20 ( V_20 , & V_22 -> V_27 , V_24 ,
V_24 + ( 1 << V_3 ) - 1 ) ) {
F_7 ( & V_22 -> V_26 , V_6 , V_23 ) ;
return - 1 ;
}
return V_24 ;
}
static T_1 F_21 ( struct V_19 * V_20 , int V_3 )
{
T_2 V_28 = 0 ;
T_2 V_29 ;
int V_30 ;
if ( F_22 ( V_20 ) ) {
F_23 ( & V_28 , V_3 ) ;
V_30 = F_24 ( V_20 , V_28 , & V_29 , V_31 ,
V_32 ,
V_33 ,
V_34 ,
V_35 ) ;
if ( V_30 )
return - 1 ;
return F_25 ( & V_29 ) ;
}
return F_17 ( V_20 , V_3 ) ;
}
int F_26 ( struct V_19 * V_20 , int V_36 , int V_37 ,
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
V_39 -> V_24 = F_21 ( V_20 , V_39 -> V_3 ) ;
if ( V_39 -> V_24 == - 1 )
return - V_18 ;
return 0 ;
}
void F_27 ( struct V_19 * V_20 , T_1 V_24 , int V_3 )
{
T_1 V_41 ;
int V_23 ;
struct V_21 * V_22 = & F_18 ( V_20 ) -> V_22 ;
V_23 = F_19 ( int , V_3 - V_25 , 0 ) ;
V_41 = V_24 / ( 1 << V_25 ) ;
F_7 ( & V_22 -> V_26 , V_41 , V_23 ) ;
F_28 ( V_20 , & V_22 -> V_27 , V_24 ,
V_24 + ( 1 << V_3 ) - 1 ) ;
}
static void F_29 ( struct V_19 * V_20 , T_1 V_24 , int V_3 )
{
T_2 V_28 = 0 ;
int V_30 ;
if ( F_22 ( V_20 ) ) {
F_23 ( & V_28 , V_24 ) ;
F_30 ( & V_28 , V_3 ) ;
V_30 = F_31 ( V_20 , V_28 , V_31 , V_32 ,
V_42 ,
V_34 ,
V_35 ) ;
if ( V_30 )
F_32 ( V_20 , L_1 ,
V_24 , V_3 ) ;
return;
}
F_27 ( V_20 , V_24 , V_3 ) ;
}
void F_33 ( struct V_19 * V_20 , struct V_38 * V_39 )
{
if ( V_39 -> V_3 < 0 )
return;
F_29 ( V_20 , V_39 -> V_24 , V_39 -> V_3 ) ;
}
T_2 F_34 ( struct V_19 * V_20 , struct V_38 * V_39 )
{
return ( T_2 ) V_39 -> V_24 * V_20 -> V_43 . V_44 ;
}
static T_1 F_35 ( T_1 V_45 )
{
return ( V_45 >> 24 ) | ( V_45 << 8 ) ;
}
static T_1 F_36 ( T_1 V_46 )
{
return ( V_46 << 24 ) | ( V_46 >> 8 ) ;
}
static int F_37 ( struct V_19 * V_20 , struct V_47 * V_48 ,
int V_49 )
{
return F_31 ( V_20 , V_48 -> V_50 , V_49 ,
0 , V_51 , V_52 ,
V_35 ) ;
}
static int F_38 ( struct V_19 * V_20 , struct V_47 * V_48 ,
int V_49 )
{
return F_39 ( V_20 , 0 , V_48 ? V_48 -> V_50 : 0 , V_49 ,
! V_48 , V_53 ,
V_52 , V_35 ) ;
}
int F_40 ( struct V_19 * V_20 , struct V_54 * V_55 ,
struct V_56 * * * V_57 )
{
int V_30 ;
int V_46 = F_36 ( V_55 -> V_46 ) & ( V_20 -> V_43 . V_58 - 1 ) ;
struct V_47 * V_48 = NULL ;
if ( V_55 -> V_59 != V_60 )
return - V_61 ;
V_30 = F_38 ( V_20 , NULL , V_46 ) ;
if ( V_30 ) {
F_32 ( V_20 , L_2 , V_30 ) ;
F_32 ( V_20 , L_3 ) ;
return V_30 ;
}
V_55 -> V_59 = V_62 ;
if ( ! F_22 ( V_20 ) ) {
* * V_57 = F_41 (
& F_18 ( V_20 ) -> V_22 . V_63 ,
V_46 , NULL ) ;
} else {
V_48 = F_42 ( V_20 ) ;
if ( F_43 ( V_48 ) )
return F_44 ( V_48 ) ;
V_30 = F_39 ( V_20 , 0 , V_48 -> V_50 , V_46 ,
0 , V_64 ,
V_52 ,
V_35 ) ;
if ( V_30 )
goto V_65;
* V_57 = (struct V_56 * * ) & V_48 -> V_66 ;
}
if ( ! ( * V_57 ) || ! ( * * V_57 ) ) {
V_30 = - V_18 ;
goto V_65;
}
return 0 ;
V_65:
F_45 ( V_20 , V_48 ) ;
return V_30 ;
}
int F_46 ( struct V_19 * V_20 , struct V_54 * V_55 ,
struct V_56 * * V_57 )
{
int V_30 ;
if ( ! F_22 ( V_20 ) ) {
F_47 () ;
* ( V_67 * ) ( * V_57 ) = V_68 ;
F_47 () ;
V_30 = F_48 ( V_20 ) ;
} else {
int V_46 = F_36 ( V_55 -> V_46 ) & ( V_20 -> V_43 . V_58 - 1 ) ;
struct V_47 * V_48 =
F_49 ( ( void * ) V_57 , struct V_47 ,
V_66 ) ;
V_30 = F_37 ( V_20 , V_48 , V_46 ) ;
}
if ( ! V_30 ) {
V_55 -> V_69 = F_50 ( ( * V_57 ) -> V_70 ) & V_71 ;
V_55 -> V_59 = V_60 ;
}
return V_30 ;
}
void F_51 ( struct V_19 * V_20 ,
struct V_56 * * V_57 )
{
if ( F_22 ( V_20 ) ) {
struct V_47 * V_48 =
F_49 ( ( void * ) V_57 , struct V_47 ,
V_66 ) ;
F_45 ( V_20 , V_48 ) ;
}
}
int F_52 ( struct V_19 * V_20 , struct V_56 * V_57 ,
T_1 V_72 )
{
T_1 V_70 = F_50 ( V_57 -> V_70 ) & ~ V_71 ;
if ( F_22 ( V_20 ) )
V_70 &= ~ V_73 ;
V_57 -> V_70 = F_53 ( V_70 |
( V_72 & V_71 )
| V_74 ) ;
return 0 ;
}
int F_54 ( struct V_19 * V_20 ,
struct V_56 * V_57 ,
T_1 V_75 )
{
T_1 V_76 = ( F_50 ( V_57 -> V_76 ) & ~ V_77 ) |
( V_75 & V_77 ) ;
V_57 -> V_76 = F_53 ( V_76 ) ;
return 0 ;
}
static int F_55 ( struct V_19 * V_20 , T_1 V_78 , T_1 V_69 ,
T_2 V_79 , T_2 V_80 , T_1 V_75 , int V_36 ,
int V_37 , struct V_54 * V_81 )
{
V_81 -> V_79 = V_79 ;
V_81 -> V_80 = V_80 ;
V_81 -> V_69 = V_69 ;
V_81 -> V_75 = V_75 ;
V_81 -> V_59 = V_82 ;
V_81 -> V_46 = F_35 ( V_78 ) ;
return F_26 ( V_20 , V_36 , V_37 , & V_81 -> V_39 ) ;
}
static int F_56 ( struct V_19 * V_20 ,
struct V_47 * V_48 ,
int V_83 )
{
return F_31 ( V_20 , V_48 -> V_50 , V_83 , 0 , V_84 ,
V_34 , V_35 ) ;
}
int F_57 ( struct V_19 * V_20 )
{
struct F_18 * V_85 = F_18 ( V_20 ) ;
return F_58 ( & V_85 -> V_22 . V_86 ) ;
}
static int F_59 ( struct V_19 * V_20 )
{
T_2 V_29 ;
if ( F_22 ( V_20 ) ) {
if ( F_24 ( V_20 , 0 , & V_29 , V_87 , V_88 ,
V_33 ,
V_34 , V_35 ) )
return - 1 ;
return F_25 ( & V_29 ) ;
}
return F_57 ( V_20 ) ;
}
void F_60 ( struct V_19 * V_20 , T_1 V_89 )
{
struct F_18 * V_85 = F_18 ( V_20 ) ;
F_61 ( & V_85 -> V_22 . V_86 , V_89 , V_90 ) ;
}
static void F_62 ( struct V_19 * V_20 , T_1 V_89 )
{
T_2 V_28 = 0 ;
if ( F_22 ( V_20 ) ) {
F_23 ( & V_28 , V_89 ) ;
if ( F_31 ( V_20 , V_28 , V_87 , V_88 ,
V_42 ,
V_34 , V_35 ) )
F_32 ( V_20 , L_4 ,
V_89 ) ;
return;
}
F_60 ( V_20 , V_89 ) ;
}
int F_63 ( struct V_19 * V_20 , T_1 V_89 , T_3 V_91 )
{
struct V_21 * V_22 = & F_18 ( V_20 ) -> V_22 ;
return F_64 ( V_20 , & V_22 -> V_63 , V_89 , V_91 ) ;
}
static int F_65 ( struct V_19 * V_20 , T_1 V_89 , T_3 V_91 )
{
T_2 V_92 = 0 ;
if ( F_22 ( V_20 ) ) {
F_23 ( & V_92 , V_89 ) ;
return F_24 ( V_20 , V_92 , & V_92 , V_87 , V_93 ,
V_33 ,
V_34 ,
V_35 ) ;
}
return F_63 ( V_20 , V_89 , V_91 ) ;
}
void F_66 ( struct V_19 * V_20 , T_1 V_89 )
{
struct V_21 * V_22 = & F_18 ( V_20 ) -> V_22 ;
F_67 ( V_20 , & V_22 -> V_63 , V_89 ) ;
}
static void F_68 ( struct V_19 * V_20 , T_1 V_89 )
{
T_2 V_28 = 0 ;
if ( F_22 ( V_20 ) ) {
F_23 ( & V_28 , V_89 ) ;
if ( F_31 ( V_20 , V_28 , V_87 , V_93 ,
V_42 , V_34 ,
V_35 ) )
F_32 ( V_20 , L_5 ,
V_89 ) ;
return;
}
return F_66 ( V_20 , V_89 ) ;
}
int F_69 ( struct V_19 * V_20 , T_1 V_69 , T_2 V_79 , T_2 V_80 , T_1 V_75 ,
int V_36 , int V_37 , struct V_54 * V_81 )
{
T_1 V_89 ;
int V_30 ;
V_89 = F_59 ( V_20 ) ;
if ( V_89 == - 1 )
return - V_18 ;
V_30 = F_55 ( V_20 , V_89 , V_69 , V_79 , V_80 ,
V_75 , V_36 , V_37 , V_81 ) ;
if ( V_30 )
F_62 ( V_20 , V_89 ) ;
return V_30 ;
}
static int F_70 ( struct V_19 * V_20 , struct V_54 * V_81 )
{
int V_30 ;
if ( V_81 -> V_59 == V_60 ) {
V_30 = F_38 ( V_20 , NULL ,
F_36 ( V_81 -> V_46 ) &
( V_20 -> V_43 . V_58 - 1 ) ) ;
if ( V_30 ) {
F_32 ( V_20 , L_6 ,
V_30 ) ;
return V_30 ;
}
V_81 -> V_59 = V_62 ;
}
F_33 ( V_20 , & V_81 -> V_39 ) ;
return 0 ;
}
int F_71 ( struct V_19 * V_20 , struct V_54 * V_81 )
{
int V_94 ;
V_94 = F_70 ( V_20 , V_81 ) ;
if ( V_94 )
return V_94 ;
if ( V_81 -> V_59 )
F_68 ( V_20 , F_36 ( V_81 -> V_46 ) ) ;
F_62 ( V_20 , F_36 ( V_81 -> V_46 ) ) ;
return 0 ;
}
void F_72 ( struct V_19 * V_20 , struct V_54 * V_81 )
{
F_33 ( V_20 , & V_81 -> V_39 ) ;
V_81 -> V_39 . V_3 = - 1 ;
}
int F_73 ( struct V_19 * V_20 , struct V_54 * V_81 ,
T_2 V_79 , T_2 V_80 , int V_36 ,
int V_37 , struct V_56 * V_57 )
{
int V_30 ;
V_30 = F_26 ( V_20 , V_36 , V_37 , & V_81 -> V_39 ) ;
if ( V_30 )
return V_30 ;
V_57 -> V_95 = F_74 ( V_81 -> V_79 ) ;
V_57 -> V_96 = F_74 ( V_81 -> V_80 ) ;
V_57 -> V_97 = F_53 ( V_81 -> V_39 . V_37 ) ;
V_57 -> V_70 &= F_53 ( V_71 |
V_74 ) ;
V_57 -> V_76 &= F_53 ( V_98 |
V_99 ) ;
if ( V_81 -> V_39 . V_3 < 0 ) {
V_57 -> V_76 |= F_53 ( V_100 ) ;
V_57 -> V_101 = 0 ;
} else {
V_57 -> V_101 = F_74 ( F_34 ( V_20 ,
& V_81 -> V_39 ) ) ;
if ( V_81 -> V_39 . V_37 == 0 )
V_57 -> V_102 = F_53 ( 1 << V_81 -> V_39 . V_3 ) ;
}
if ( V_81 -> V_39 . V_3 >= 0 && V_81 -> V_39 . V_37 == 0 ) {
V_57 -> V_76 |= F_53 ( V_98 ) ;
V_57 -> V_70 |= F_53 ( V_103 |
V_104 ) ;
} else {
V_57 -> V_76 |= F_53 ( V_99 ) ;
}
V_81 -> V_59 = V_62 ;
return 0 ;
}
int F_75 ( struct V_19 * V_20 , struct V_54 * V_81 )
{
struct V_47 * V_48 ;
struct V_56 * V_57 ;
int V_30 ;
V_30 = F_65 ( V_20 , F_36 ( V_81 -> V_46 ) , V_14 ) ;
if ( V_30 )
return V_30 ;
V_48 = F_42 ( V_20 ) ;
if ( F_76 ( V_48 ) ) {
V_30 = F_44 ( V_48 ) ;
goto V_105;
}
V_57 = V_48 -> V_66 ;
V_57 -> V_76 = F_53 ( V_106 |
V_107 |
V_81 -> V_75 ) ;
V_57 -> V_46 = F_53 ( F_36 ( V_81 -> V_46 ) ) ;
V_57 -> V_70 = F_53 ( V_81 -> V_69 | V_74 ) ;
V_57 -> V_95 = F_74 ( V_81 -> V_79 ) ;
V_57 -> V_96 = F_74 ( V_81 -> V_80 ) ;
V_57 -> V_97 = F_53 ( V_81 -> V_39 . V_37 ) ;
if ( V_81 -> V_39 . V_3 < 0 ) {
V_57 -> V_76 |= F_53 ( V_100 ) ;
V_57 -> V_101 = 0 ;
} else {
V_57 -> V_101 = F_74 ( F_34 ( V_20 ,
& V_81 -> V_39 ) ) ;
}
if ( V_81 -> V_39 . V_3 >= 0 && V_81 -> V_39 . V_37 == 0 ) {
V_57 -> V_76 |= F_53 ( V_98 ) ;
V_57 -> V_70 |= F_53 ( V_103 |
V_104 ) ;
V_57 -> V_102 = F_53 ( 1 << V_81 -> V_39 . V_3 ) ;
} else {
V_57 -> V_76 |= F_53 ( V_99 ) ;
}
V_30 = F_37 ( V_20 , V_48 ,
F_36 ( V_81 -> V_46 ) & ( V_20 -> V_43 . V_58 - 1 ) ) ;
if ( V_30 ) {
F_32 ( V_20 , L_7 , V_30 ) ;
goto V_108;
}
V_81 -> V_59 = V_60 ;
F_45 ( V_20 , V_48 ) ;
return 0 ;
V_108:
F_45 ( V_20 , V_48 ) ;
V_105:
F_68 ( V_20 , F_36 ( V_81 -> V_46 ) ) ;
return V_30 ;
}
static int F_77 ( struct V_19 * V_20 , struct V_38 * V_39 ,
int V_109 , int V_36 , T_2 * V_110 )
{
struct F_18 * V_85 = F_18 ( V_20 ) ;
T_4 * V_111 ;
T_5 V_112 ;
int V_12 ;
V_111 = F_41 ( & V_85 -> V_22 . V_27 , V_39 -> V_24 +
V_109 , & V_112 ) ;
if ( ! V_111 )
return - V_18 ;
F_78 ( & V_20 -> V_113 -> V_20 , V_112 ,
V_36 * sizeof ( T_2 ) , V_114 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_111 [ V_12 ] = F_74 ( V_110 [ V_12 ] | V_115 ) ;
F_79 ( & V_20 -> V_113 -> V_20 , V_112 ,
V_36 * sizeof ( T_2 ) , V_114 ) ;
return 0 ;
}
int F_80 ( struct V_19 * V_20 , struct V_38 * V_39 ,
int V_109 , int V_36 , T_2 * V_110 )
{
int V_30 = 0 ;
int V_116 ;
int V_117 ;
int V_118 ;
V_117 = V_119 / sizeof( T_2 ) ;
V_118 = V_117 - ( V_39 -> V_24 + V_109 )
% V_117 ;
V_116 = F_81 ( int , V_118 , V_36 ) ;
while ( V_36 > 0 ) {
V_30 = F_77 ( V_20 , V_39 , V_109 , V_116 , V_110 ) ;
if ( V_30 )
return V_30 ;
V_36 -= V_116 ;
V_109 += V_116 ;
V_110 += V_116 ;
V_116 = F_81 ( int , V_117 , V_36 ) ;
}
return V_30 ;
}
int F_82 ( struct V_19 * V_20 , struct V_38 * V_39 ,
int V_109 , int V_36 , T_2 * V_110 )
{
struct V_47 * V_48 = NULL ;
T_4 * V_120 = NULL ;
int V_116 ;
int V_30 = 0 ;
int V_12 ;
if ( V_39 -> V_3 < 0 )
return - V_61 ;
if ( F_22 ( V_20 ) ) {
V_48 = F_42 ( V_20 ) ;
if ( F_76 ( V_48 ) )
return F_44 ( V_48 ) ;
V_120 = V_48 -> V_66 ;
while ( V_36 > 0 ) {
V_116 = F_81 ( int , V_121 / sizeof( T_2 ) - 2 ,
V_36 ) ;
V_120 [ 0 ] = F_74 ( V_39 -> V_24 + V_109 ) ;
V_120 [ 1 ] = 0 ;
for ( V_12 = 0 ; V_12 < V_116 ; ++ V_12 )
V_120 [ V_12 + 2 ] = F_74 ( V_110 [ V_12 ] |
V_115 ) ;
V_30 = F_56 ( V_20 , V_48 , V_116 ) ;
if ( V_30 ) {
F_45 ( V_20 , V_48 ) ;
return V_30 ;
}
V_36 -= V_116 ;
V_109 += V_116 ;
V_110 += V_116 ;
}
F_45 ( V_20 , V_48 ) ;
return V_30 ;
}
return F_80 ( V_20 , V_39 , V_109 , V_36 , V_110 ) ;
}
int F_83 ( struct V_19 * V_20 , struct V_38 * V_39 ,
struct V_122 * V_66 , T_3 V_91 )
{
T_2 * V_110 ;
int V_30 ;
int V_12 ;
V_110 = F_84 ( V_66 -> V_36 * sizeof *V_110 ,
V_91 ) ;
if ( ! V_110 )
return - V_18 ;
for ( V_12 = 0 ; V_12 < V_66 -> V_36 ; ++ V_12 )
if ( V_66 -> V_123 == 1 )
V_110 [ V_12 ] = V_66 -> V_124 . V_125 + ( V_12 << V_66 -> V_37 ) ;
else
V_110 [ V_12 ] = V_66 -> V_110 [ V_12 ] . V_125 ;
V_30 = F_82 ( V_20 , V_39 , 0 , V_66 -> V_36 , V_110 ) ;
F_15 ( V_110 ) ;
return V_30 ;
}
int F_85 ( struct V_19 * V_20 , T_1 V_69 , enum V_126 type ,
struct V_127 * V_128 )
{
T_1 V_89 ;
if ( ( type == V_129 &&
! ( V_20 -> V_43 . V_76 & V_130 ) ) ||
( type == V_131 &&
! ( V_20 -> V_43 . V_132 & V_133 ) ) )
return - V_134 ;
V_89 = F_59 ( V_20 ) ;
if ( V_89 == - 1 )
return - V_18 ;
V_128 -> V_46 = F_35 ( V_89 ) ;
V_128 -> V_69 = V_69 ;
V_128 -> type = type ;
V_128 -> V_59 = V_82 ;
return 0 ;
}
int F_86 ( struct V_19 * V_20 , struct V_127 * V_128 )
{
struct V_47 * V_48 ;
struct V_56 * V_57 ;
int V_30 ;
V_30 = F_65 ( V_20 , F_36 ( V_128 -> V_46 ) , V_14 ) ;
if ( V_30 )
return V_30 ;
V_48 = F_42 ( V_20 ) ;
if ( F_76 ( V_48 ) ) {
V_30 = F_44 ( V_48 ) ;
goto V_105;
}
V_57 = V_48 -> V_66 ;
V_57 -> V_46 = F_53 ( F_36 ( V_128 -> V_46 ) ) ;
V_57 -> V_70 = F_53 ( V_128 -> V_69 ) ;
if ( V_128 -> type == V_131 ) {
V_57 -> V_76 |= F_53 ( V_98 ) ;
V_57 -> V_135 = F_53 ( V_136 ) ;
V_57 -> V_70 |= F_53 ( V_74 ) ;
}
V_30 = F_37 ( V_20 , V_48 ,
F_36 ( V_128 -> V_46 ) &
( V_20 -> V_43 . V_58 - 1 ) ) ;
if ( V_30 ) {
F_32 ( V_20 , L_7 , V_30 ) ;
goto V_108;
}
V_128 -> V_59 = V_60 ;
F_45 ( V_20 , V_48 ) ;
return 0 ;
V_108:
F_45 ( V_20 , V_48 ) ;
V_105:
F_68 ( V_20 , F_36 ( V_128 -> V_46 ) ) ;
return V_30 ;
}
void F_87 ( struct V_19 * V_20 , struct V_127 * V_128 )
{
int V_30 ;
if ( V_128 -> V_59 == V_60 ) {
V_30 = F_38 ( V_20 , NULL ,
F_36 ( V_128 -> V_46 ) &
( V_20 -> V_43 . V_58 - 1 ) ) ;
if ( V_30 )
F_32 ( V_20 , L_8 , V_30 ) ;
V_128 -> V_59 = V_62 ;
}
if ( V_128 -> V_59 )
F_68 ( V_20 , F_36 ( V_128 -> V_46 ) ) ;
F_62 ( V_20 , F_36 ( V_128 -> V_46 ) ) ;
}
int F_88 ( struct V_19 * V_20 )
{
struct F_18 * V_85 = F_18 ( V_20 ) ;
struct V_21 * V_22 = & V_85 -> V_22 ;
int V_30 ;
if ( F_89 ( V_20 ) )
return 0 ;
if ( ! F_90 ( V_20 -> V_43 . V_58 ) )
return - V_61 ;
V_30 = F_91 ( & V_22 -> V_86 , V_20 -> V_43 . V_58 ,
~ 0 , V_20 -> V_43 . V_137 , 0 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_9 ( & V_22 -> V_26 ,
F_92 ( ( T_1 ) V_20 -> V_43 . V_138 /
( 1 << V_25 ) ) ) ;
if ( V_30 )
goto V_139;
if ( V_20 -> V_43 . V_140 ) {
V_85 -> V_140 =
F_21 ( V_20 ,
F_93 ( V_20 -> V_43 . V_140 - 1 ) ) ;
if ( V_85 -> V_140 < 0 ) {
F_32 ( V_20 , L_9 ,
V_22 -> V_26 . V_8 ) ;
V_30 = - V_18 ;
goto V_141;
}
}
return 0 ;
V_141:
F_16 ( & V_22 -> V_26 ) ;
V_139:
F_94 ( & V_22 -> V_86 ) ;
return V_30 ;
}
void F_95 ( struct V_19 * V_20 )
{
struct F_18 * V_85 = F_18 ( V_20 ) ;
struct V_21 * V_22 = & V_85 -> V_22 ;
if ( F_89 ( V_20 ) )
return;
if ( V_85 -> V_140 >= 0 )
F_29 ( V_20 , V_85 -> V_140 ,
F_93 ( V_20 -> V_43 . V_140 - 1 ) ) ;
F_16 ( & V_22 -> V_26 ) ;
F_94 ( & V_22 -> V_86 ) ;
}
static inline int F_96 ( struct V_142 * V_143 , T_2 * V_110 ,
int V_36 , T_2 V_79 )
{
int V_12 , V_144 ;
if ( V_36 > V_143 -> V_145 )
return - V_61 ;
V_144 = ( 1 << V_143 -> V_37 ) - 1 ;
if ( V_79 & V_144 )
return - V_61 ;
if ( 0 )
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 ) {
if ( V_110 [ V_12 ] & ~ V_144 )
return - V_61 ;
}
if ( V_143 -> V_146 >= V_143 -> V_147 )
return - V_61 ;
return 0 ;
}
int F_97 ( struct V_19 * V_20 , struct V_142 * V_143 , T_2 * V_110 ,
int V_36 , T_2 V_79 , T_1 * V_148 , T_1 * V_149 )
{
T_1 V_46 ;
int V_12 , V_30 ;
V_30 = F_96 ( V_143 , V_110 , V_36 , V_79 ) ;
if ( V_30 )
return V_30 ;
++ V_143 -> V_146 ;
V_46 = F_36 ( V_143 -> V_81 . V_46 ) ;
V_46 += V_20 -> V_43 . V_58 ;
* V_148 = * V_149 = V_143 -> V_81 . V_46 = F_35 ( V_46 ) ;
* ( V_67 * ) V_143 -> V_150 = V_151 ;
F_47 () ;
F_78 ( & V_20 -> V_113 -> V_20 , V_143 -> V_112 ,
V_36 * sizeof( T_2 ) , V_114 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; ++ V_12 )
V_143 -> V_111 [ V_12 ] = F_74 ( V_110 [ V_12 ] | V_115 ) ;
F_79 ( & V_20 -> V_113 -> V_20 , V_143 -> V_112 ,
V_36 * sizeof( T_2 ) , V_114 ) ;
V_143 -> V_150 -> V_46 = F_53 ( V_46 ) ;
V_143 -> V_150 -> V_148 = F_53 ( V_46 ) ;
V_143 -> V_150 -> V_96 = F_74 ( V_36 * ( 1ull << V_143 -> V_37 ) ) ;
V_143 -> V_150 -> V_95 = F_74 ( V_79 ) ;
F_47 () ;
* ( V_67 * ) V_143 -> V_150 = V_68 ;
F_47 () ;
return 0 ;
}
int F_98 ( struct V_19 * V_20 , T_1 V_69 , T_1 V_75 , int V_145 ,
int V_147 , V_67 V_37 , struct V_142 * V_143 )
{
struct F_18 * V_85 = F_18 ( V_20 ) ;
int V_30 = - V_18 ;
if ( V_147 > V_20 -> V_43 . V_152 )
return - V_61 ;
if ( V_37 < ( F_99 ( V_20 -> V_43 . V_153 ) - 1 ) || V_37 >= 32 )
return - V_61 ;
if ( V_145 * sizeof * V_143 -> V_111 > V_119 )
return - V_61 ;
V_143 -> V_37 = V_37 ;
V_143 -> V_145 = V_145 ;
V_143 -> V_147 = V_147 ;
V_143 -> V_146 = 0 ;
V_30 = F_69 ( V_20 , V_69 , 0 , 0 , V_75 , V_145 ,
V_37 , & V_143 -> V_81 ) ;
if ( V_30 )
return V_30 ;
V_143 -> V_111 = F_41 ( & V_85 -> V_22 . V_27 ,
V_143 -> V_81 . V_39 . V_24 ,
& V_143 -> V_112 ) ;
if ( ! V_143 -> V_111 ) {
V_30 = - V_18 ;
goto V_154;
}
return 0 ;
V_154:
( void ) F_71 ( V_20 , & V_143 -> V_81 ) ;
return V_30 ;
}
int F_100 ( struct V_19 * V_20 , struct V_142 * V_143 )
{
struct F_18 * V_85 = F_18 ( V_20 ) ;
int V_30 ;
V_30 = F_75 ( V_20 , & V_143 -> V_81 ) ;
if ( V_30 )
return V_30 ;
V_143 -> V_150 = F_41 ( & V_85 -> V_22 . V_63 ,
F_36 ( V_143 -> V_81 . V_46 ) , NULL ) ;
if ( ! V_143 -> V_150 )
return - V_18 ;
return 0 ;
}
void F_101 ( struct V_19 * V_20 , struct V_142 * V_143 ,
T_1 * V_148 , T_1 * V_149 )
{
struct V_47 * V_48 ;
int V_30 ;
if ( ! V_143 -> V_146 )
return;
V_143 -> V_146 = 0 ;
V_48 = F_42 ( V_20 ) ;
if ( F_76 ( V_48 ) ) {
V_30 = F_44 ( V_48 ) ;
F_102 ( L_10 , V_30 ) ;
return;
}
V_30 = F_38 ( V_20 , NULL ,
F_36 ( V_143 -> V_81 . V_46 ) &
( V_20 -> V_43 . V_58 - 1 ) ) ;
F_45 ( V_20 , V_48 ) ;
if ( V_30 ) {
F_102 ( L_11 , V_30 ) ;
return;
}
V_143 -> V_81 . V_59 = V_62 ;
}
int F_103 ( struct V_19 * V_20 , struct V_142 * V_143 )
{
int V_94 ;
if ( V_143 -> V_146 )
return - V_155 ;
V_94 = F_71 ( V_20 , & V_143 -> V_81 ) ;
if ( V_94 )
return V_94 ;
V_143 -> V_81 . V_59 = V_82 ;
return 0 ;
}
int F_48 ( struct V_19 * V_20 )
{
return F_31 ( V_20 , 0 , 0 , 0 , V_156 , 1000 ,
V_157 ) ;
}
