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
F_14 ( V_2 -> V_10 [ V_12 ] ,
1 << ( V_2 -> V_8 - V_12 ) ) ;
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
static T_1 F_17 ( struct V_18 * V_19 , int V_3 ,
struct V_1 * V_2 )
{
T_1 V_6 = F_1 ( V_2 , V_3 ) ;
if ( V_6 == - 1 )
return - 1 ;
if ( F_18 ( V_19 ) )
if ( F_19 ( V_19 , V_19 -> V_20 . V_21 , V_6 ,
V_6 + ( 1 << V_3 ) - 1 ) ) {
F_7 ( V_2 , V_6 , V_3 ) ;
V_6 = - 1 ;
}
return V_6 ;
}
static struct V_22 * F_20 ( struct V_18 * V_19 , int V_23 ,
struct V_1 * V_2 )
{
struct V_22 * V_24 ;
int V_12 ;
if ( V_23 <= 0 )
return F_21 ( - V_25 ) ;
V_24 = F_13 ( sizeof *V_24 , V_14 ) ;
if ( ! V_24 )
return F_21 ( - V_17 ) ;
V_24 -> V_2 = V_2 ;
V_24 -> V_3 = 0 ;
for ( V_12 = V_19 -> V_26 . V_27 / 8 ; V_12 < V_23 ; V_12 <<= 1 )
++ V_24 -> V_3 ;
V_24 -> V_28 = F_17 ( V_19 , V_24 -> V_3 , V_2 ) ;
if ( V_24 -> V_28 == - 1 ) {
F_15 ( V_24 ) ;
return F_21 ( - V_17 ) ;
}
return V_24 ;
}
struct V_22 * F_22 ( struct V_18 * V_19 , int V_23 )
{
return F_20 ( V_19 , V_23 , & V_19 -> V_20 . V_29 ) ;
}
void F_23 ( struct V_18 * V_19 , struct V_22 * V_24 )
{
if ( ! V_24 )
return;
F_7 ( V_24 -> V_2 , V_24 -> V_28 , V_24 -> V_3 ) ;
F_24 ( V_19 , V_19 -> V_20 . V_21 ,
V_24 -> V_28 ,
V_24 -> V_28 + ( 1 << V_24 -> V_3 ) - 1 ) ;
F_15 ( V_24 ) ;
}
static int F_25 ( struct V_18 * V_19 , struct V_22 * V_24 ,
int V_30 , T_2 * V_31 , int V_32 )
{
struct V_33 * V_34 ;
T_3 * V_35 ;
int V_36 = 0 ;
T_4 V_37 ;
int V_12 ;
V_34 = F_26 ( V_19 , V_14 ) ;
if ( F_27 ( V_34 ) )
return F_28 ( V_34 ) ;
V_35 = V_34 -> V_38 ;
while ( V_32 > 0 ) {
V_35 [ 0 ] = F_29 ( V_19 -> V_20 . V_39 +
V_24 -> V_28 * V_19 -> V_26 . V_27 +
V_30 * 8 ) ;
V_35 [ 1 ] = 0 ;
for ( V_12 = 0 ; V_12 < V_32 && V_12 < V_40 / 8 - 2 ; ++ V_12 )
V_35 [ V_12 + 2 ] = F_29 ( V_31 [ V_12 ] |
V_41 ) ;
if ( V_12 & 1 )
V_35 [ V_12 + 2 ] = 0 ;
V_36 = F_30 ( V_19 , V_34 , ( V_12 + 1 ) & ~ 1 , & V_37 ) ;
if ( V_36 ) {
F_31 ( V_19 , L_1 , V_36 ) ;
goto V_42;
}
if ( V_37 ) {
F_31 ( V_19 , L_2 ,
V_37 ) ;
V_36 = - V_25 ;
goto V_42;
}
V_32 -= V_12 ;
V_30 += V_12 ;
V_31 += V_12 ;
}
V_42:
F_32 ( V_19 , V_34 ) ;
return V_36 ;
}
int F_33 ( struct V_18 * V_19 )
{
if ( V_19 -> V_20 . V_43 != & V_19 -> V_20 . V_29 ||
! ( V_19 -> V_44 & V_45 ) )
return V_46 / sizeof ( T_2 ) - 2 ;
return F_18 ( V_19 ) ? ( V_46 / sizeof ( T_2 ) ) : 0x7ffffff ;
}
static void F_34 ( struct V_18 * V_19 ,
struct V_22 * V_24 , int V_30 ,
T_2 * V_31 , int V_32 )
{
T_2 T_5 * V_47 ;
int V_12 ;
V_47 = V_19 -> V_20 . V_48 . V_39 + V_24 -> V_28 * V_19 -> V_26 . V_27 +
V_30 * sizeof ( T_2 ) ;
for ( V_12 = 0 ; V_12 < V_32 ; ++ V_12 )
F_35 ( F_29 ( V_31 [ V_12 ] | V_41 ) ,
V_47 + V_12 ) ;
}
static void F_36 ( struct V_18 * V_19 ,
struct V_22 * V_24 , int V_30 ,
T_2 * V_31 , int V_32 )
{
T_3 * V_47 ;
T_6 V_49 ;
int V_12 ;
int V_13 = V_30 * sizeof ( T_2 ) ;
F_37 ( V_13 / V_46 != ( V_13 + V_32 * sizeof( T_2 ) - 1 ) / V_46 ) ;
F_37 ( V_13 % V_19 -> V_26 . V_27 ) ;
V_47 = F_38 ( V_19 -> V_20 . V_21 , V_24 -> V_28 +
V_13 / V_19 -> V_26 . V_27 , & V_49 ) ;
F_37 ( ! V_47 ) ;
F_39 ( & V_19 -> V_50 -> V_19 , V_49 ,
V_32 * sizeof ( T_2 ) , V_51 ) ;
for ( V_12 = 0 ; V_12 < V_32 ; ++ V_12 )
V_47 [ V_12 ] = F_29 ( V_31 [ V_12 ] | V_41 ) ;
F_40 ( & V_19 -> V_50 -> V_19 , V_49 ,
V_32 * sizeof ( T_2 ) , V_51 ) ;
}
int F_41 ( struct V_18 * V_19 , struct V_22 * V_24 ,
int V_30 , T_2 * V_31 , int V_32 )
{
int V_23 = F_33 ( V_19 ) ;
int V_52 ;
if ( V_19 -> V_20 . V_43 != & V_19 -> V_20 . V_29 ||
! ( V_19 -> V_44 & V_45 ) )
return F_25 ( V_19 , V_24 , V_30 , V_31 , V_32 ) ;
while ( V_32 > 0 ) {
V_52 = F_42 ( V_23 , V_32 ) ;
if ( F_18 ( V_19 ) )
F_36 ( V_19 , V_24 , V_30 ,
V_31 , V_52 ) ;
else
F_34 ( V_19 , V_24 , V_30 ,
V_31 , V_52 ) ;
V_32 -= V_52 ;
V_30 += V_52 ;
V_31 += V_52 ;
}
return 0 ;
}
static inline T_1 F_43 ( T_1 V_53 )
{
return V_53 ;
}
static inline T_1 F_44 ( T_1 V_54 )
{
return V_54 ;
}
static inline T_1 F_45 ( T_1 V_53 )
{
return ( V_53 >> 24 ) | ( V_53 << 8 ) ;
}
static inline T_1 F_46 ( T_1 V_54 )
{
return ( V_54 << 24 ) | ( V_54 >> 8 ) ;
}
static inline T_1 F_47 ( struct V_18 * V_19 , T_1 V_53 )
{
if ( F_18 ( V_19 ) )
return F_45 ( V_53 ) ;
else
return F_43 ( V_53 ) ;
}
static inline T_1 F_48 ( struct V_18 * V_19 , T_1 V_54 )
{
if ( F_18 ( V_19 ) )
return F_46 ( V_54 ) ;
else
return F_44 ( V_54 ) ;
}
static inline T_1 F_49 ( struct V_18 * V_19 , T_1 V_54 )
{
if ( V_19 -> V_44 & V_55 )
return ( ( V_54 << 20 ) & 0x800000 ) | ( V_54 & 0x7fffff ) ;
else
return V_54 ;
}
int F_50 ( struct V_18 * V_19 , T_1 V_56 , int V_57 ,
T_2 V_58 , T_2 V_59 , T_1 V_60 , struct V_61 * V_62 )
{
struct V_33 * V_34 ;
struct V_63 * V_64 ;
T_1 V_54 ;
int V_12 ;
int V_36 ;
T_4 V_37 ;
F_51 ( V_57 >= 32 ) ;
V_54 = F_52 ( & V_19 -> V_20 . V_65 ) ;
if ( V_54 == - 1 )
return - V_17 ;
V_54 = F_49 ( V_19 , V_54 ) ;
V_62 -> V_66 . V_67 = V_62 -> V_66 . V_68 = F_47 ( V_19 , V_54 ) ;
if ( F_18 ( V_19 ) ) {
V_36 = F_53 ( V_19 , V_19 -> V_20 . V_69 , V_54 ) ;
if ( V_36 )
goto V_70;
}
V_34 = F_26 ( V_19 , V_14 ) ;
if ( F_27 ( V_34 ) ) {
V_36 = F_28 ( V_34 ) ;
goto V_71;
}
V_64 = V_34 -> V_38 ;
V_64 -> V_72 = F_54 ( V_73 |
V_74 |
V_75 |
V_60 ) ;
if ( ! V_62 -> V_24 )
V_64 -> V_72 |= F_54 ( V_76 ) ;
V_64 -> V_77 = F_54 ( V_57 - 12 ) ;
V_64 -> V_54 = F_54 ( V_54 ) ;
V_64 -> V_56 = F_54 ( V_56 ) ;
V_64 -> V_78 = F_29 ( V_58 ) ;
V_64 -> V_79 = F_29 ( V_59 ) ;
memset ( & V_64 -> V_68 , 0 ,
sizeof *V_64 - F_55 ( struct V_63 , V_68 ) ) ;
if ( V_62 -> V_24 )
V_64 -> V_80 =
F_29 ( V_19 -> V_20 . V_39 +
V_62 -> V_24 -> V_28 * V_19 -> V_26 . V_27 ) ;
if ( 0 ) {
F_56 ( V_19 , L_3 , V_62 -> V_66 . V_68 ) ;
for ( V_12 = 0 ; V_12 < sizeof ( struct V_63 ) / 4 ; ++ V_12 ) {
if ( V_12 % 4 == 0 )
F_57 ( L_4 , V_12 * 4 ) ;
F_57 ( L_5 , F_58 ( ( ( V_81 * ) V_64 ) [ V_12 ] ) ) ;
if ( ( V_12 + 1 ) % 4 == 0 )
F_57 ( L_6 ) ;
}
}
V_36 = F_59 ( V_19 , V_34 ,
V_54 & ( V_19 -> V_26 . V_82 - 1 ) ,
& V_37 ) ;
if ( V_36 ) {
F_31 ( V_19 , L_7 , V_36 ) ;
goto V_83;
} else if ( V_37 ) {
F_31 ( V_19 , L_8 ,
V_37 ) ;
V_36 = - V_25 ;
goto V_83;
}
F_32 ( V_19 , V_34 ) ;
return V_36 ;
V_83:
F_32 ( V_19 , V_34 ) ;
V_71:
F_60 ( V_19 , V_19 -> V_20 . V_69 , V_54 ) ;
V_70:
F_61 ( & V_19 -> V_20 . V_65 , V_54 ) ;
return V_36 ;
}
int F_62 ( struct V_18 * V_19 , T_1 V_56 ,
T_1 V_60 , struct V_61 * V_62 )
{
V_62 -> V_24 = NULL ;
return F_50 ( V_19 , V_56 , 12 , 0 , ~ 0ULL , V_60 , V_62 ) ;
}
int F_63 ( struct V_18 * V_19 , T_1 V_56 ,
T_2 * V_31 , int V_57 ,
int V_32 , T_2 V_58 , T_2 V_59 ,
T_1 V_60 , struct V_61 * V_62 )
{
int V_36 ;
V_62 -> V_24 = F_22 ( V_19 , V_32 ) ;
if ( F_27 ( V_62 -> V_24 ) )
return F_28 ( V_62 -> V_24 ) ;
V_36 = F_41 ( V_19 , V_62 -> V_24 , 0 , V_31 , V_32 ) ;
if ( V_36 ) {
F_23 ( V_19 , V_62 -> V_24 ) ;
return V_36 ;
}
V_36 = F_50 ( V_19 , V_56 , V_57 , V_58 ,
V_59 , V_60 , V_62 ) ;
if ( V_36 )
F_23 ( V_19 , V_62 -> V_24 ) ;
return V_36 ;
}
static void F_64 ( struct V_18 * V_19 , T_1 V_68 )
{
F_60 ( V_19 , V_19 -> V_20 . V_69 ,
F_48 ( V_19 , V_68 ) ) ;
F_61 ( & V_19 -> V_20 . V_65 , F_48 ( V_19 , V_68 ) ) ;
}
void F_65 ( struct V_18 * V_19 , struct V_61 * V_62 )
{
int V_36 ;
T_4 V_37 ;
V_36 = F_66 ( V_19 , NULL ,
F_48 ( V_19 , V_62 -> V_66 . V_68 ) &
( V_19 -> V_26 . V_82 - 1 ) ,
& V_37 ) ;
if ( V_36 )
F_31 ( V_19 , L_9 , V_36 ) ;
else if ( V_37 )
F_31 ( V_19 , L_10 ,
V_37 ) ;
F_64 ( V_19 , V_62 -> V_66 . V_68 ) ;
F_23 ( V_19 , V_62 -> V_24 ) ;
}
int F_67 ( struct V_18 * V_19 , T_1 V_56 ,
T_1 V_60 , struct V_84 * V_62 )
{
struct V_63 * V_64 ;
struct V_33 * V_34 ;
T_2 V_80 ;
T_1 V_54 , V_85 ;
T_4 V_37 ;
int V_32 = V_62 -> V_86 . V_87 ;
int V_36 = - V_17 ;
int V_12 ;
if ( V_62 -> V_86 . V_88 < 12 || V_62 -> V_86 . V_88 >= 32 )
return - V_25 ;
if ( F_18 ( V_19 ) &&
V_62 -> V_86 . V_87 * sizeof * V_62 -> V_89 . V_90 . V_47 > V_46 )
return - V_25 ;
V_62 -> V_91 = 0 ;
V_54 = F_52 ( & V_19 -> V_20 . V_65 ) ;
if ( V_54 == - 1 )
return - V_17 ;
V_54 = F_49 ( V_19 , V_54 ) ;
V_85 = V_54 & ( V_19 -> V_26 . V_82 - 1 ) ;
V_62 -> V_66 . V_67 = V_62 -> V_66 . V_68 = F_47 ( V_19 , V_54 ) ;
if ( F_18 ( V_19 ) ) {
V_36 = F_53 ( V_19 , V_19 -> V_20 . V_69 , V_54 ) ;
if ( V_36 )
goto V_70;
V_62 -> V_89 . V_90 . V_92 = F_38 ( V_19 -> V_20 . V_69 , V_54 , NULL ) ;
F_37 ( ! V_62 -> V_89 . V_90 . V_92 ) ;
} else
V_62 -> V_89 . V_93 . V_92 = V_19 -> V_20 . V_48 . V_94 +
sizeof *( V_62 -> V_89 . V_93 . V_92 ) * V_85 ;
V_62 -> V_24 = F_20 ( V_19 , V_32 , V_19 -> V_20 . V_43 ) ;
if ( F_27 ( V_62 -> V_24 ) ) {
V_36 = F_28 ( V_62 -> V_24 ) ;
goto V_71;
}
V_80 = V_62 -> V_24 -> V_28 * V_19 -> V_26 . V_27 ;
if ( F_18 ( V_19 ) ) {
V_62 -> V_89 . V_90 . V_47 = F_38 ( V_19 -> V_20 . V_21 ,
V_62 -> V_24 -> V_28 ,
& V_62 -> V_89 . V_90 . V_49 ) ;
F_37 ( ! V_62 -> V_89 . V_90 . V_47 ) ;
} else
V_62 -> V_89 . V_93 . V_47 = V_19 -> V_20 . V_48 . V_39 + V_80 ;
V_34 = F_26 ( V_19 , V_14 ) ;
if ( F_27 ( V_34 ) ) {
V_36 = F_28 ( V_34 ) ;
goto V_95;
}
V_64 = V_34 -> V_38 ;
V_64 -> V_72 = F_54 ( V_73 |
V_74 |
V_75 |
V_60 ) ;
V_64 -> V_77 = F_54 ( V_62 -> V_86 . V_88 - 12 ) ;
V_64 -> V_54 = F_54 ( V_54 ) ;
V_64 -> V_56 = F_54 ( V_56 ) ;
memset ( & V_64 -> V_78 , 0 ,
sizeof *V_64 - F_55 ( struct V_63 , V_78 ) ) ;
V_64 -> V_80 = F_29 ( V_19 -> V_20 . V_39 + V_80 ) ;
if ( 0 ) {
F_56 ( V_19 , L_3 , V_62 -> V_66 . V_68 ) ;
for ( V_12 = 0 ; V_12 < sizeof ( struct V_63 ) / 4 ; ++ V_12 ) {
if ( V_12 % 4 == 0 )
F_57 ( L_4 , V_12 * 4 ) ;
F_57 ( L_5 , F_58 ( ( ( V_81 * ) V_64 ) [ V_12 ] ) ) ;
if ( ( V_12 + 1 ) % 4 == 0 )
F_57 ( L_6 ) ;
}
}
V_36 = F_59 ( V_19 , V_34 ,
V_54 & ( V_19 -> V_26 . V_82 - 1 ) ,
& V_37 ) ;
if ( V_36 ) {
F_31 ( V_19 , L_7 , V_36 ) ;
goto V_96;
}
if ( V_37 ) {
F_31 ( V_19 , L_8 ,
V_37 ) ;
V_36 = - V_25 ;
goto V_96;
}
F_32 ( V_19 , V_34 ) ;
return 0 ;
V_96:
F_32 ( V_19 , V_34 ) ;
V_95:
F_23 ( V_19 , V_62 -> V_24 ) ;
V_71:
F_60 ( V_19 , V_19 -> V_20 . V_69 , V_54 ) ;
V_70:
F_61 ( & V_19 -> V_20 . V_65 , V_54 ) ;
return V_36 ;
}
int F_68 ( struct V_18 * V_19 , struct V_84 * V_97 )
{
if ( V_97 -> V_91 )
return - V_98 ;
F_64 ( V_19 , V_97 -> V_66 . V_68 ) ;
F_23 ( V_19 , V_97 -> V_24 ) ;
return 0 ;
}
static inline int F_69 ( struct V_84 * V_97 , T_2 * V_99 ,
int V_32 , T_2 V_58 )
{
int V_12 , V_100 ;
if ( V_32 > V_97 -> V_86 . V_87 )
return - V_25 ;
V_100 = ( 1 << V_97 -> V_86 . V_88 ) - 1 ;
if ( V_58 & V_100 )
return - V_25 ;
if ( 0 )
for ( V_12 = 0 ; V_12 < V_32 ; ++ V_12 ) {
if ( V_99 [ V_12 ] & ~ V_100 )
return - V_25 ;
}
if ( V_97 -> V_91 >= V_97 -> V_86 . V_101 )
return - V_25 ;
return 0 ;
}
int F_70 ( struct V_102 * V_103 , T_2 * V_99 ,
int V_32 , T_2 V_58 )
{
struct V_84 * V_97 = F_71 ( V_103 ) ;
struct V_18 * V_19 = F_72 ( V_103 -> V_104 ) ;
struct V_63 V_64 ;
T_1 V_54 ;
int V_12 , V_36 ;
V_36 = F_69 ( V_97 , V_99 , V_32 , V_58 ) ;
if ( V_36 )
return V_36 ;
++ V_97 -> V_91 ;
V_54 = F_44 ( V_97 -> V_66 . V_68 ) ;
V_54 += V_19 -> V_26 . V_82 ;
V_97 -> V_66 . V_68 = V_97 -> V_66 . V_67 = F_43 ( V_54 ) ;
F_73 ( V_105 , V_97 -> V_89 . V_93 . V_92 ) ;
for ( V_12 = 0 ; V_12 < V_32 ; ++ V_12 ) {
T_3 V_35 = F_29 ( V_99 [ V_12 ] |
V_41 ) ;
F_35 ( V_35 , V_97 -> V_89 . V_93 . V_47 + V_12 ) ;
}
V_64 . V_68 = F_54 ( V_54 ) ;
V_64 . V_79 = F_29 ( V_32 * ( 1ull << V_97 -> V_86 . V_88 ) ) ;
V_64 . V_78 = F_29 ( V_58 ) ;
F_74 ( ( V_106 T_1 ) V_64 . V_68 , & V_97 -> V_89 . V_93 . V_92 -> V_54 ) ;
F_75 ( & V_97 -> V_89 . V_93 . V_92 -> V_78 , & V_64 . V_78 ,
F_55 ( struct V_63 , V_107 ) -
F_55 ( struct V_63 , V_78 ) ) ;
F_73 ( V_108 , V_97 -> V_89 . V_93 . V_92 ) ;
return 0 ;
}
int F_76 ( struct V_102 * V_103 , T_2 * V_99 ,
int V_32 , T_2 V_58 )
{
struct V_84 * V_97 = F_71 ( V_103 ) ;
struct V_18 * V_19 = F_72 ( V_103 -> V_104 ) ;
T_1 V_54 ;
int V_12 , V_36 ;
V_36 = F_69 ( V_97 , V_99 , V_32 , V_58 ) ;
if ( V_36 )
return V_36 ;
++ V_97 -> V_91 ;
V_54 = F_46 ( V_97 -> V_66 . V_68 ) ;
if ( V_19 -> V_44 & V_55 )
V_54 += V_109 ;
else
V_54 += V_19 -> V_26 . V_82 ;
V_97 -> V_66 . V_68 = V_97 -> V_66 . V_67 = F_45 ( V_54 ) ;
* ( T_4 * ) V_97 -> V_89 . V_90 . V_92 = V_105 ;
F_77 () ;
F_39 ( & V_19 -> V_50 -> V_19 , V_97 -> V_89 . V_90 . V_49 ,
V_32 * sizeof( T_2 ) , V_51 ) ;
for ( V_12 = 0 ; V_12 < V_32 ; ++ V_12 )
V_97 -> V_89 . V_90 . V_47 [ V_12 ] = F_29 ( V_99 [ V_12 ] |
V_41 ) ;
F_40 ( & V_19 -> V_50 -> V_19 , V_97 -> V_89 . V_90 . V_49 ,
V_32 * sizeof( T_2 ) , V_51 ) ;
V_97 -> V_89 . V_90 . V_92 -> V_54 = F_54 ( V_54 ) ;
V_97 -> V_89 . V_90 . V_92 -> V_68 = F_54 ( V_54 ) ;
V_97 -> V_89 . V_90 . V_92 -> V_79 = F_29 ( V_32 * ( 1ull << V_97 -> V_86 . V_88 ) ) ;
V_97 -> V_89 . V_90 . V_92 -> V_78 = F_29 ( V_58 ) ;
F_77 () ;
* ( T_4 * ) V_97 -> V_89 . V_90 . V_92 = V_108 ;
F_77 () ;
return 0 ;
}
void F_78 ( struct V_18 * V_19 , struct V_84 * V_97 )
{
if ( ! V_97 -> V_91 )
return;
V_97 -> V_91 = 0 ;
F_73 ( V_105 , V_97 -> V_89 . V_93 . V_92 ) ;
}
void F_79 ( struct V_18 * V_19 , struct V_84 * V_97 )
{
if ( ! V_97 -> V_91 )
return;
V_97 -> V_91 = 0 ;
* ( T_4 * ) V_97 -> V_89 . V_90 . V_92 = V_105 ;
}
int F_80 ( struct V_18 * V_19 )
{
T_7 V_110 ;
int V_111 , V_47 , V_36 , V_12 ;
V_36 = F_81 ( & V_19 -> V_20 . V_65 ,
V_19 -> V_26 . V_82 ,
~ 0 , V_19 -> V_26 . V_112 ) ;
if ( V_36 )
return V_36 ;
if ( ! F_18 ( V_19 ) &&
( V_19 -> V_44 & V_113 ) )
V_19 -> V_26 . V_114 = 0 ;
else
V_19 -> V_44 |= V_45 ;
if ( V_19 -> V_44 & V_55 )
F_56 ( V_19 , L_11 ) ;
V_36 = F_9 ( & V_19 -> V_20 . V_29 ,
F_82 ( V_19 -> V_26 . V_115 - 1 ) ) ;
if ( V_36 )
goto V_116;
V_19 -> V_20 . V_48 . V_94 = NULL ;
V_19 -> V_20 . V_48 . V_39 = NULL ;
if ( V_19 -> V_26 . V_114 ) {
V_12 = F_82 ( V_19 -> V_26 . V_114 - 1 ) ;
if ( V_12 >= 31 ) {
F_31 ( V_19 , L_12 ) ;
V_36 = - V_25 ;
goto V_117;
}
V_111 = V_47 = 1 << V_12 ;
} else {
V_47 = V_19 -> V_26 . V_115 ;
V_111 = V_19 -> V_26 . V_82 ;
}
if ( ! F_18 ( V_19 ) &&
( V_19 -> V_44 & V_45 ) ) {
V_110 = F_83 ( V_19 -> V_50 , 4 ) +
( ( F_84 ( V_19 -> V_50 , 4 ) - 1 ) &
V_19 -> V_20 . V_94 ) ;
V_19 -> V_20 . V_48 . V_94 =
F_85 ( V_110 , V_111 * sizeof( struct V_63 ) ) ;
if ( ! V_19 -> V_20 . V_48 . V_94 ) {
F_31 ( V_19 , L_13 ) ;
V_36 = - V_17 ;
goto V_117;
}
V_110 = F_83 ( V_19 -> V_50 , 4 ) +
( ( F_84 ( V_19 -> V_50 , 4 ) - 1 ) &
V_19 -> V_20 . V_39 ) ;
V_19 -> V_20 . V_48 . V_39 =
F_85 ( V_110 , V_47 * V_19 -> V_26 . V_27 ) ;
if ( ! V_19 -> V_20 . V_48 . V_39 ) {
F_31 ( V_19 , L_14 ) ;
V_36 = - V_17 ;
goto V_118;
}
}
if ( V_19 -> V_26 . V_114 ) {
V_36 = F_9 ( & V_19 -> V_20 . V_48 . V_29 , F_82 ( V_47 - 1 ) ) ;
if ( V_36 )
goto V_119;
V_36 = F_1 ( & V_19 -> V_20 . V_29 , F_82 ( V_47 - 1 ) ) ;
if ( V_36 )
goto V_120;
V_19 -> V_20 . V_43 =
& V_19 -> V_20 . V_48 . V_29 ;
} else
V_19 -> V_20 . V_43 = & V_19 -> V_20 . V_29 ;
if ( V_19 -> V_26 . V_121 ) {
V_12 = F_82 ( V_19 -> V_26 . V_121 - 1 ) ;
if ( F_17 ( V_19 , V_12 ,
V_19 -> V_20 . V_43 ) == - 1 ) {
F_31 ( V_19 , L_15 ,
V_19 -> V_20 . V_43 -> V_8 ) ;
V_36 = - V_17 ;
goto V_122;
}
}
return 0 ;
V_122:
V_120:
if ( V_19 -> V_26 . V_114 )
F_16 ( & V_19 -> V_20 . V_48 . V_29 ) ;
V_119:
if ( V_19 -> V_20 . V_48 . V_39 )
F_86 ( V_19 -> V_20 . V_48 . V_39 ) ;
V_118:
if ( V_19 -> V_20 . V_48 . V_94 )
F_86 ( V_19 -> V_20 . V_48 . V_94 ) ;
V_117:
F_16 ( & V_19 -> V_20 . V_29 ) ;
V_116:
F_87 ( & V_19 -> V_20 . V_65 ) ;
return V_36 ;
}
void F_88 ( struct V_18 * V_19 )
{
if ( V_19 -> V_26 . V_114 )
F_16 ( & V_19 -> V_20 . V_48 . V_29 ) ;
F_16 ( & V_19 -> V_20 . V_29 ) ;
if ( V_19 -> V_20 . V_48 . V_39 )
F_86 ( V_19 -> V_20 . V_48 . V_39 ) ;
if ( V_19 -> V_20 . V_48 . V_94 )
F_86 ( V_19 -> V_20 . V_48 . V_94 ) ;
F_87 ( & V_19 -> V_20 . V_65 ) ;
}
