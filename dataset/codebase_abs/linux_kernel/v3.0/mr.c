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
V_2 -> V_9 = F_11 ( ( V_2 -> V_8 + 1 ) * sizeof ( int * ) ,
V_14 ) ;
if ( ! V_2 -> V_10 || ! V_2 -> V_9 )
goto V_15;
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 ) {
V_13 = F_12 ( 1 << ( V_2 -> V_8 - V_12 ) ) ;
V_2 -> V_10 [ V_12 ] = F_13 ( V_13 * sizeof ( long ) , V_14 ) ;
if ( ! V_2 -> V_10 [ V_12 ] )
goto V_16;
F_14 ( V_2 -> V_10 [ V_12 ] , 1 << ( V_2 -> V_8 - V_12 ) ) ;
}
F_6 ( 0 , V_2 -> V_10 [ V_2 -> V_8 ] ) ;
V_2 -> V_9 [ V_2 -> V_8 ] = 1 ;
return 0 ;
V_16:
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 )
F_15 ( V_2 -> V_10 [ V_12 ] ) ;
V_15:
F_15 ( V_2 -> V_10 ) ;
F_15 ( V_2 -> V_9 ) ;
return - V_17 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 <= V_2 -> V_8 ; ++ V_12 )
F_15 ( V_2 -> V_10 [ V_12 ] ) ;
F_15 ( V_2 -> V_10 ) ;
F_15 ( V_2 -> V_9 ) ;
}
static T_1 F_17 ( struct V_18 * V_19 , int V_3 )
{
struct V_20 * V_21 = & F_18 ( V_19 ) -> V_21 ;
T_1 V_6 ;
V_6 = F_1 ( & V_21 -> V_22 , V_3 ) ;
if ( V_6 == - 1 )
return - 1 ;
if ( F_19 ( V_19 , & V_21 -> V_23 , V_6 ,
V_6 + ( 1 << V_3 ) - 1 ) ) {
F_7 ( & V_21 -> V_22 , V_6 , V_3 ) ;
return - 1 ;
}
return V_6 ;
}
int F_20 ( struct V_18 * V_19 , int V_24 , int V_25 ,
struct V_26 * V_27 )
{
int V_12 ;
if ( ! V_24 ) {
V_27 -> V_3 = - 1 ;
V_27 -> V_25 = V_28 ;
return 0 ;
} else
V_27 -> V_25 = V_25 ;
for ( V_27 -> V_3 = 0 , V_12 = V_19 -> V_29 . V_30 ; V_12 < V_24 ; V_12 <<= 1 )
++ V_27 -> V_3 ;
V_27 -> V_31 = F_17 ( V_19 , V_27 -> V_3 ) ;
if ( V_27 -> V_31 == - 1 )
return - V_17 ;
return 0 ;
}
void F_21 ( struct V_18 * V_19 , struct V_26 * V_27 )
{
struct V_20 * V_21 = & F_18 ( V_19 ) -> V_21 ;
if ( V_27 -> V_3 < 0 )
return;
F_7 ( & V_21 -> V_22 , V_27 -> V_31 , V_27 -> V_3 ) ;
F_22 ( V_19 , & V_21 -> V_23 , V_27 -> V_31 ,
V_27 -> V_31 + ( 1 << V_27 -> V_3 ) - 1 ) ;
}
T_2 F_23 ( struct V_18 * V_19 , struct V_26 * V_27 )
{
return ( T_2 ) V_27 -> V_31 * V_19 -> V_29 . V_32 ;
}
static T_1 F_24 ( T_1 V_33 )
{
return ( V_33 >> 24 ) | ( V_33 << 8 ) ;
}
static T_1 F_25 ( T_1 V_34 )
{
return ( V_34 << 24 ) | ( V_34 >> 8 ) ;
}
static int F_26 ( struct V_18 * V_19 , struct V_35 * V_36 ,
int V_37 )
{
return F_27 ( V_19 , V_36 -> V_38 , V_37 , 0 , V_39 ,
V_40 ) ;
}
static int F_28 ( struct V_18 * V_19 , struct V_35 * V_36 ,
int V_37 )
{
return F_29 ( V_19 , 0 , V_36 ? V_36 -> V_38 : 0 , V_37 ,
! V_36 , V_41 , V_40 ) ;
}
int F_30 ( struct V_18 * V_19 , T_1 V_42 , T_2 V_43 , T_2 V_44 , T_1 V_45 ,
int V_24 , int V_25 , struct V_46 * V_47 )
{
struct F_18 * V_48 = F_18 ( V_19 ) ;
T_1 V_49 ;
int V_50 ;
V_49 = F_31 ( & V_48 -> V_21 . V_51 ) ;
if ( V_49 == - 1 )
return - V_17 ;
V_47 -> V_43 = V_43 ;
V_47 -> V_44 = V_44 ;
V_47 -> V_42 = V_42 ;
V_47 -> V_45 = V_45 ;
V_47 -> V_52 = 0 ;
V_47 -> V_34 = F_24 ( V_49 ) ;
V_50 = F_20 ( V_19 , V_24 , V_25 , & V_47 -> V_27 ) ;
if ( V_50 )
F_32 ( & V_48 -> V_21 . V_51 , V_49 ) ;
return V_50 ;
}
void F_33 ( struct V_18 * V_19 , struct V_46 * V_47 )
{
struct F_18 * V_48 = F_18 ( V_19 ) ;
int V_50 ;
if ( V_47 -> V_52 ) {
V_50 = F_28 ( V_19 , NULL ,
F_25 ( V_47 -> V_34 ) &
( V_19 -> V_29 . V_53 - 1 ) ) ;
if ( V_50 )
F_34 ( V_19 , L_1 , V_50 ) ;
}
F_21 ( V_19 , & V_47 -> V_27 ) ;
F_32 ( & V_48 -> V_21 . V_51 , F_25 ( V_47 -> V_34 ) ) ;
}
int F_35 ( struct V_18 * V_19 , struct V_46 * V_47 )
{
struct V_20 * V_21 = & F_18 ( V_19 ) -> V_21 ;
struct V_35 * V_36 ;
struct V_54 * V_55 ;
int V_50 ;
V_50 = F_36 ( V_19 , & V_21 -> V_56 , F_25 ( V_47 -> V_34 ) ) ;
if ( V_50 )
return V_50 ;
V_36 = F_37 ( V_19 ) ;
if ( F_38 ( V_36 ) ) {
V_50 = F_39 ( V_36 ) ;
goto V_57;
}
V_55 = V_36 -> V_58 ;
memset ( V_55 , 0 , sizeof *V_55 ) ;
V_55 -> V_59 = F_40 ( V_60 |
V_61 |
V_47 -> V_45 ) ;
V_55 -> V_34 = F_40 ( F_25 ( V_47 -> V_34 ) ) ;
V_55 -> V_62 = F_40 ( V_47 -> V_42 | V_63 ) ;
V_55 -> V_64 = F_41 ( V_47 -> V_43 ) ;
V_55 -> V_65 = F_41 ( V_47 -> V_44 ) ;
V_55 -> V_66 = F_40 ( V_47 -> V_27 . V_25 ) ;
if ( V_47 -> V_27 . V_3 < 0 ) {
V_55 -> V_59 |= F_40 ( V_67 ) ;
V_55 -> V_68 = 0 ;
} else {
V_55 -> V_68 = F_41 ( F_23 ( V_19 , & V_47 -> V_27 ) ) ;
}
if ( V_47 -> V_27 . V_3 >= 0 && V_47 -> V_27 . V_25 == 0 ) {
V_55 -> V_59 |= F_40 ( V_69 ) ;
V_55 -> V_62 |= F_40 ( V_70 |
V_71 ) ;
V_55 -> V_72 = F_40 ( ( 1 << V_47 -> V_27 . V_3 ) *
V_19 -> V_29 . V_30 ) ;
} else {
V_55 -> V_59 |= F_40 ( V_73 ) ;
}
V_50 = F_26 ( V_19 , V_36 ,
F_25 ( V_47 -> V_34 ) & ( V_19 -> V_29 . V_53 - 1 ) ) ;
if ( V_50 ) {
F_34 ( V_19 , L_2 , V_50 ) ;
goto V_74;
}
V_47 -> V_52 = 1 ;
F_42 ( V_19 , V_36 ) ;
return 0 ;
V_74:
F_42 ( V_19 , V_36 ) ;
V_57:
F_43 ( V_19 , & V_21 -> V_56 , F_25 ( V_47 -> V_34 ) ) ;
return V_50 ;
}
static int F_44 ( struct V_18 * V_19 , struct V_26 * V_27 ,
int V_75 , int V_24 , T_2 * V_76 )
{
struct F_18 * V_48 = F_18 ( V_19 ) ;
T_3 * V_77 ;
T_4 V_78 ;
int V_12 ;
int V_13 = V_75 * sizeof ( T_2 ) ;
if ( V_75 / ( V_79 / sizeof ( T_2 ) ) !=
( V_75 + V_24 - 1 ) / ( V_79 / sizeof ( T_2 ) ) )
return - V_80 ;
if ( V_75 & ( V_19 -> V_29 . V_30 - 1 ) )
return - V_80 ;
V_77 = F_45 ( & V_48 -> V_21 . V_23 , V_27 -> V_31 +
V_13 / V_19 -> V_29 . V_32 , & V_78 ) ;
if ( ! V_77 )
return - V_17 ;
F_46 ( & V_19 -> V_81 -> V_19 , V_78 ,
V_24 * sizeof ( T_2 ) , V_82 ) ;
for ( V_12 = 0 ; V_12 < V_24 ; ++ V_12 )
V_77 [ V_12 ] = F_41 ( V_76 [ V_12 ] | V_83 ) ;
F_47 ( & V_19 -> V_81 -> V_19 , V_78 ,
V_24 * sizeof ( T_2 ) , V_82 ) ;
return 0 ;
}
int F_48 ( struct V_18 * V_19 , struct V_26 * V_27 ,
int V_75 , int V_24 , T_2 * V_76 )
{
int V_84 ;
int V_50 ;
if ( V_27 -> V_3 < 0 )
return - V_80 ;
while ( V_24 > 0 ) {
V_84 = F_49 ( int , V_79 / sizeof( T_2 ) , V_24 ) ;
V_50 = F_44 ( V_19 , V_27 , V_75 , V_84 , V_76 ) ;
if ( V_50 )
return V_50 ;
V_24 -= V_84 ;
V_75 += V_84 ;
V_76 += V_84 ;
}
return 0 ;
}
int F_50 ( struct V_18 * V_19 , struct V_26 * V_27 ,
struct V_85 * V_58 )
{
T_2 * V_76 ;
int V_50 ;
int V_12 ;
V_76 = F_13 ( V_58 -> V_24 * sizeof *V_76 , V_14 ) ;
if ( ! V_76 )
return - V_17 ;
for ( V_12 = 0 ; V_12 < V_58 -> V_24 ; ++ V_12 )
if ( V_58 -> V_86 == 1 )
V_76 [ V_12 ] = V_58 -> V_87 . V_88 + ( V_12 << V_58 -> V_25 ) ;
else
V_76 [ V_12 ] = V_58 -> V_76 [ V_12 ] . V_88 ;
V_50 = F_48 ( V_19 , V_27 , 0 , V_58 -> V_24 , V_76 ) ;
F_15 ( V_76 ) ;
return V_50 ;
}
int F_51 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & F_18 ( V_19 ) -> V_21 ;
int V_50 ;
V_50 = F_52 ( & V_21 -> V_51 , V_19 -> V_29 . V_53 ,
~ 0 , V_19 -> V_29 . V_89 , 0 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_9 ( & V_21 -> V_22 ,
F_53 ( V_19 -> V_29 . V_90 ) ) ;
if ( V_50 )
goto V_91;
if ( V_19 -> V_29 . V_92 ) {
if ( F_17 ( V_19 , F_54 ( V_19 -> V_29 . V_92 - 1 ) ) == - 1 ) {
F_34 ( V_19 , L_3 ,
V_21 -> V_22 . V_8 ) ;
V_50 = - V_17 ;
goto V_93;
}
}
return 0 ;
V_93:
F_16 ( & V_21 -> V_22 ) ;
V_91:
F_55 ( & V_21 -> V_51 ) ;
return V_50 ;
}
void F_56 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = & F_18 ( V_19 ) -> V_21 ;
F_16 ( & V_21 -> V_22 ) ;
F_55 ( & V_21 -> V_51 ) ;
}
static inline int F_57 ( struct V_94 * V_95 , T_2 * V_76 ,
int V_24 , T_2 V_43 )
{
int V_12 , V_96 ;
if ( V_24 > V_95 -> V_97 )
return - V_80 ;
V_96 = ( 1 << V_95 -> V_25 ) - 1 ;
if ( V_43 & V_96 )
return - V_80 ;
if ( 0 )
for ( V_12 = 0 ; V_12 < V_24 ; ++ V_12 ) {
if ( V_76 [ V_12 ] & ~ V_96 )
return - V_80 ;
}
if ( V_95 -> V_98 >= V_95 -> V_99 )
return - V_80 ;
return 0 ;
}
int F_58 ( struct V_18 * V_19 , struct V_94 * V_95 , T_2 * V_76 ,
int V_24 , T_2 V_43 , T_1 * V_100 , T_1 * V_101 )
{
T_1 V_34 ;
int V_12 , V_50 ;
V_50 = F_57 ( V_95 , V_76 , V_24 , V_43 ) ;
if ( V_50 )
return V_50 ;
++ V_95 -> V_98 ;
V_34 = F_25 ( V_95 -> V_47 . V_34 ) ;
V_34 += V_19 -> V_29 . V_53 ;
* V_100 = * V_101 = V_95 -> V_47 . V_34 = F_24 ( V_34 ) ;
* ( V_102 * ) V_95 -> V_103 = V_104 ;
F_59 () ;
F_46 ( & V_19 -> V_81 -> V_19 , V_95 -> V_78 ,
V_24 * sizeof( T_2 ) , V_82 ) ;
for ( V_12 = 0 ; V_12 < V_24 ; ++ V_12 )
V_95 -> V_77 [ V_12 ] = F_41 ( V_76 [ V_12 ] | V_83 ) ;
F_47 ( & V_19 -> V_81 -> V_19 , V_95 -> V_78 ,
V_24 * sizeof( T_2 ) , V_82 ) ;
V_95 -> V_103 -> V_34 = F_40 ( V_34 ) ;
V_95 -> V_103 -> V_100 = F_40 ( V_34 ) ;
V_95 -> V_103 -> V_65 = F_41 ( V_24 * ( 1ull << V_95 -> V_25 ) ) ;
V_95 -> V_103 -> V_64 = F_41 ( V_43 ) ;
F_59 () ;
* ( V_102 * ) V_95 -> V_103 = V_105 ;
F_59 () ;
return 0 ;
}
int F_60 ( struct V_18 * V_19 , T_1 V_42 , T_1 V_45 , int V_97 ,
int V_99 , V_102 V_25 , struct V_94 * V_95 )
{
struct F_18 * V_48 = F_18 ( V_19 ) ;
T_2 V_68 ;
int V_50 = - V_17 ;
if ( V_25 < ( F_61 ( V_19 -> V_29 . V_106 ) - 1 ) || V_25 >= 32 )
return - V_80 ;
if ( V_97 * sizeof * V_95 -> V_77 > V_79 )
return - V_80 ;
V_95 -> V_25 = V_25 ;
V_95 -> V_97 = V_97 ;
V_95 -> V_99 = V_99 ;
V_95 -> V_98 = 0 ;
V_50 = F_30 ( V_19 , V_42 , 0 , 0 , V_45 , V_97 ,
V_25 , & V_95 -> V_47 ) ;
if ( V_50 )
return V_50 ;
V_68 = V_95 -> V_47 . V_27 . V_31 * V_19 -> V_29 . V_32 ;
V_95 -> V_77 = F_45 ( & V_48 -> V_21 . V_23 ,
V_95 -> V_47 . V_27 . V_31 ,
& V_95 -> V_78 ) ;
if ( ! V_95 -> V_77 ) {
V_50 = - V_17 ;
goto V_107;
}
return 0 ;
V_107:
F_33 ( V_19 , & V_95 -> V_47 ) ;
return V_50 ;
}
int F_62 ( struct V_18 * V_19 , struct V_94 * V_95 )
{
struct F_18 * V_48 = F_18 ( V_19 ) ;
int V_50 ;
V_50 = F_35 ( V_19 , & V_95 -> V_47 ) ;
if ( V_50 )
return V_50 ;
V_95 -> V_103 = F_45 ( & V_48 -> V_21 . V_56 ,
F_25 ( V_95 -> V_47 . V_34 ) , NULL ) ;
if ( ! V_95 -> V_103 )
return - V_17 ;
return 0 ;
}
void F_63 ( struct V_18 * V_19 , struct V_94 * V_95 ,
T_1 * V_100 , T_1 * V_101 )
{
if ( ! V_95 -> V_98 )
return;
V_95 -> V_98 = 0 ;
* ( V_102 * ) V_95 -> V_103 = V_104 ;
}
int F_64 ( struct V_18 * V_19 , struct V_94 * V_95 )
{
if ( V_95 -> V_98 )
return - V_108 ;
V_95 -> V_47 . V_52 = 0 ;
F_33 ( V_19 , & V_95 -> V_47 ) ;
return 0 ;
}
int F_65 ( struct V_18 * V_19 )
{
return F_27 ( V_19 , 0 , 0 , 0 , V_109 , 1000 ) ;
}
