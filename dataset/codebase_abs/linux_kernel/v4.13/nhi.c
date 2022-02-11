static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 ;
if ( ! V_2 -> V_5 )
V_3 += V_2 -> V_6 -> V_7 ;
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , bool V_8 )
{
int V_9 = V_10 +
F_1 ( V_2 ) / 32 * 4 ;
int V_3 = F_1 ( V_2 ) & 31 ;
int V_11 = 1 << V_3 ;
T_1 V_12 , V_13 ;
if ( V_2 -> V_14 > 0 ) {
T_1 V_15 , V_16 , V_17 , V_18 ;
void T_2 * V_19 ;
int V_20 ;
if ( V_2 -> V_5 )
V_20 = V_2 -> V_4 ;
else
V_20 = V_2 -> V_4 + V_2 -> V_6 -> V_7 ;
V_18 = F_3 ( V_2 -> V_6 -> V_21 + V_22 ) ;
if ( ! ( V_18 & V_23 ) ) {
V_18 |= V_23 ;
F_4 ( V_18 , V_2 -> V_6 -> V_21 + V_22 ) ;
}
V_19 = V_2 -> V_6 -> V_21 + V_24 ;
V_15 = V_20 / V_25 * V_26 ;
V_16 = V_20 % V_25 * V_26 ;
V_17 = F_3 ( V_19 + V_15 ) ;
V_17 &= ~ ( V_27 << V_16 ) ;
if ( V_8 )
V_17 |= V_2 -> V_28 << V_16 ;
F_4 ( V_17 , V_19 + V_15 ) ;
}
V_12 = F_3 ( V_2 -> V_6 -> V_21 + V_9 ) ;
if ( V_8 )
V_13 = V_12 | V_11 ;
else
V_13 = V_12 & ~ V_11 ;
F_5 ( & V_2 -> V_6 -> V_29 -> V_30 ,
L_1 ,
V_8 ? L_2 : L_3 , V_9 , V_3 , V_12 , V_13 ) ;
if ( V_13 == V_12 )
F_6 ( & V_2 -> V_6 -> V_29 -> V_30 ,
L_4 ,
F_7 ( V_2 ) , V_2 -> V_4 ,
V_8 ? L_5 : L_6 ) ;
F_4 ( V_13 , V_2 -> V_6 -> V_21 + V_9 ) ;
}
static void F_8 ( struct V_31 * V_6 )
{
int V_32 = 0 ;
for ( V_32 = 0 ; V_32 < F_9 ( V_6 ) ; V_32 ++ )
F_4 ( 0 , V_6 -> V_21 + V_10 + 4 * V_32 ) ;
for ( V_32 = 0 ; V_32 < F_10 ( V_6 ) ; V_32 ++ )
F_3 ( V_6 -> V_21 + V_33 + 4 * V_32 ) ;
}
static void T_2 * F_11 ( struct V_1 * V_2 )
{
void T_2 * V_34 = V_2 -> V_6 -> V_21 ;
V_34 += V_2 -> V_5 ? V_35 : V_36 ;
V_34 += V_2 -> V_4 * 16 ;
return V_34 ;
}
static void T_2 * F_12 ( struct V_1 * V_2 )
{
void T_2 * V_34 = V_2 -> V_6 -> V_21 ;
V_34 += V_2 -> V_5 ? V_37 : V_38 ;
V_34 += V_2 -> V_4 * 32 ;
return V_34 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_40 )
{
F_14 ( V_39 , F_11 ( V_2 ) + V_40 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_40 )
{
F_4 ( V_39 , F_11 ( V_2 ) + V_40 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_3 V_39 , T_1 V_40 )
{
F_4 ( V_39 , F_11 ( V_2 ) + V_40 ) ;
F_4 ( V_39 >> 32 , F_11 ( V_2 ) + V_40 + 4 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_40 )
{
F_4 ( V_39 , F_12 ( V_2 ) + V_40 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_41 + 1 ) % V_2 -> V_42 ) == V_2 -> V_43 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_41 == V_2 -> V_43 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_44 * V_45 , * V_46 ;
struct V_47 * V_48 ;
F_21 (frame, n, &ring->queue, list) {
if ( F_18 ( V_2 ) )
break;
F_22 ( & V_45 -> V_49 , & V_2 -> V_50 ) ;
V_48 = & V_2 -> V_51 [ V_2 -> V_41 ] ;
V_48 -> V_52 = V_45 -> V_53 ;
V_48 -> time = 0 ;
V_48 -> V_54 = V_55 | V_56 ;
if ( V_2 -> V_5 ) {
V_48 -> V_57 = V_45 -> V_42 ;
V_48 -> V_58 = V_45 -> V_58 ;
V_48 -> V_59 = V_45 -> V_59 ;
}
V_2 -> V_41 = ( V_2 -> V_41 + 1 ) % V_2 -> V_42 ;
F_13 ( V_2 , V_2 -> V_41 , V_2 -> V_5 ? 10 : 8 ) ;
}
}
static void F_23 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_24 ( V_61 , F_25 ( * V_2 ) , V_61 ) ;
struct V_44 * V_45 ;
bool V_62 = false ;
F_26 ( V_63 ) ;
F_27 ( & V_2 -> V_64 ) ;
if ( ! V_2 -> V_65 ) {
F_28 ( & V_2 -> V_50 , & V_63 ) ;
F_28 ( & V_2 -> V_66 , & V_63 ) ;
V_62 = true ;
goto V_67;
}
while ( ! F_19 ( V_2 ) ) {
if ( ! ( V_2 -> V_51 [ V_2 -> V_43 ] . V_54
& V_68 ) )
break;
V_45 = F_29 ( & V_2 -> V_50 , F_25 ( * V_45 ) ,
V_49 ) ;
F_22 ( & V_45 -> V_49 , & V_63 ) ;
if ( ! V_2 -> V_5 ) {
V_45 -> V_42 = V_2 -> V_51 [ V_2 -> V_43 ] . V_57 ;
V_45 -> V_58 = V_2 -> V_51 [ V_2 -> V_43 ] . V_58 ;
V_45 -> V_59 = V_2 -> V_51 [ V_2 -> V_43 ] . V_59 ;
V_45 -> V_54 = V_2 -> V_51 [ V_2 -> V_43 ] . V_54 ;
if ( V_45 -> V_59 != 0 )
F_6 ( & V_2 -> V_6 -> V_29 -> V_30 ,
L_7 ,
F_7 ( V_2 ) , V_2 -> V_4 ,
V_45 -> V_59 ) ;
if ( V_45 -> V_54 != 0xa )
F_6 ( & V_2 -> V_6 -> V_29 -> V_30 ,
L_8 ,
F_7 ( V_2 ) , V_2 -> V_4 ,
V_45 -> V_54 ) ;
}
V_2 -> V_43 = ( V_2 -> V_43 + 1 ) % V_2 -> V_42 ;
}
F_20 ( V_2 ) ;
V_67:
F_30 ( & V_2 -> V_64 ) ;
while ( ! F_31 ( & V_63 ) ) {
V_45 = F_29 ( & V_63 , F_25 ( * V_45 ) , V_49 ) ;
F_32 ( & V_45 -> V_49 ) ;
V_45 -> V_69 ( V_2 , V_45 , V_62 ) ;
}
}
int F_33 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
int V_70 = 0 ;
F_27 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_65 ) {
F_34 ( & V_45 -> V_49 , & V_2 -> V_66 ) ;
F_20 ( V_2 ) ;
} else {
V_70 = - V_71 ;
}
F_30 ( & V_2 -> V_64 ) ;
return V_70 ;
}
static T_4 F_35 ( int V_14 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
F_36 ( & V_2 -> V_61 ) ;
return V_73 ;
}
static int F_37 ( struct V_1 * V_2 , bool V_74 )
{
struct V_31 * V_6 = V_2 -> V_6 ;
unsigned long V_75 ;
int V_70 ;
if ( ! V_6 -> V_29 -> V_76 )
return 0 ;
V_70 = F_38 ( & V_6 -> V_77 , 0 , V_78 , V_79 ) ;
if ( V_70 < 0 )
return V_70 ;
V_2 -> V_28 = V_70 ;
V_2 -> V_14 = F_39 ( V_2 -> V_6 -> V_29 , V_2 -> V_28 ) ;
if ( V_2 -> V_14 < 0 )
return V_2 -> V_14 ;
V_75 = V_74 ? V_80 : 0 ;
return F_40 ( V_2 -> V_14 , F_35 , V_75 , L_9 , V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 <= 0 )
return;
F_42 ( V_2 -> V_14 , V_2 ) ;
F_43 ( & V_2 -> V_6 -> V_77 , V_2 -> V_28 ) ;
V_2 -> V_28 = 0 ;
V_2 -> V_14 = 0 ;
}
static struct V_1 * F_44 ( struct V_31 * V_6 , T_1 V_4 , int V_42 ,
bool V_81 , unsigned int V_54 )
{
struct V_1 * V_2 = NULL ;
F_5 ( & V_6 -> V_29 -> V_30 , L_10 ,
V_81 ? L_11 : L_12 , V_4 , V_42 ) ;
F_27 ( & V_6 -> V_64 ) ;
if ( V_4 >= V_6 -> V_7 ) {
F_6 ( & V_6 -> V_29 -> V_30 , L_13 , V_4 ) ;
goto V_82;
}
if ( V_81 && V_6 -> V_83 [ V_4 ] ) {
F_6 ( & V_6 -> V_29 -> V_30 , L_14 , V_4 ) ;
goto V_82;
} else if ( ! V_81 && V_6 -> V_84 [ V_4 ] ) {
F_6 ( & V_6 -> V_29 -> V_30 , L_15 , V_4 ) ;
goto V_82;
}
V_2 = F_45 ( sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
goto V_82;
F_46 ( & V_2 -> V_64 ) ;
F_47 ( & V_2 -> V_66 ) ;
F_47 ( & V_2 -> V_50 ) ;
F_48 ( & V_2 -> V_61 , F_23 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_81 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_41 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_65 = false ;
if ( F_37 ( V_2 , V_54 & V_85 ) )
goto V_82;
V_2 -> V_51 = F_49 ( & V_2 -> V_6 -> V_29 -> V_30 ,
V_42 * sizeof( * V_2 -> V_51 ) ,
& V_2 -> V_86 , V_79 | V_87 ) ;
if ( ! V_2 -> V_51 )
goto V_82;
if ( V_81 )
V_6 -> V_83 [ V_4 ] = V_2 ;
else
V_6 -> V_84 [ V_4 ] = V_2 ;
F_30 ( & V_6 -> V_64 ) ;
return V_2 ;
V_82:
if ( V_2 )
F_50 ( & V_2 -> V_64 ) ;
F_51 ( V_2 ) ;
F_30 ( & V_6 -> V_64 ) ;
return NULL ;
}
struct V_1 * F_52 ( struct V_31 * V_6 , int V_4 , int V_42 ,
unsigned int V_54 )
{
return F_44 ( V_6 , V_4 , V_42 , true , V_54 ) ;
}
struct V_1 * F_53 ( struct V_31 * V_6 , int V_4 , int V_42 ,
unsigned int V_54 )
{
return F_44 ( V_6 , V_4 , V_42 , false , V_54 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_6 -> V_64 ) ;
F_27 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_6 -> V_88 )
goto V_82;
if ( V_2 -> V_65 ) {
F_6 ( & V_2 -> V_6 -> V_29 -> V_30 , L_16 ) ;
goto V_82;
}
F_5 ( & V_2 -> V_6 -> V_29 -> V_30 , L_17 ,
F_7 ( V_2 ) , V_2 -> V_4 ) ;
F_16 ( V_2 , V_2 -> V_86 , 0 ) ;
if ( V_2 -> V_5 ) {
F_15 ( V_2 , V_2 -> V_42 , 12 ) ;
F_17 ( V_2 , 0 , 4 ) ;
F_17 ( V_2 ,
V_89 | V_90 , 0 ) ;
} else {
F_15 ( V_2 ,
( V_91 << 16 ) | V_2 -> V_42 , 12 ) ;
F_17 ( V_2 , 0xffffffff , 4 ) ;
F_17 ( V_2 ,
V_89 | V_90 , 0 ) ;
}
F_2 ( V_2 , true ) ;
V_2 -> V_65 = true ;
V_82:
F_30 ( & V_2 -> V_64 ) ;
F_30 ( & V_2 -> V_6 -> V_64 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_6 -> V_64 ) ;
F_27 ( & V_2 -> V_64 ) ;
F_5 ( & V_2 -> V_6 -> V_29 -> V_30 , L_18 ,
F_7 ( V_2 ) , V_2 -> V_4 ) ;
if ( V_2 -> V_6 -> V_88 )
goto V_82;
if ( ! V_2 -> V_65 ) {
F_6 ( & V_2 -> V_6 -> V_29 -> V_30 , L_19 ,
F_7 ( V_2 ) , V_2 -> V_4 ) ;
goto V_82;
}
F_2 ( V_2 , false ) ;
F_17 ( V_2 , 0 , 0 ) ;
F_16 ( V_2 , 0 , 0 ) ;
F_13 ( V_2 , 0 , V_2 -> V_5 ? 10 : 8 ) ;
F_15 ( V_2 , 0 , 12 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_65 = false ;
V_82:
F_30 ( & V_2 -> V_64 ) ;
F_30 ( & V_2 -> V_6 -> V_64 ) ;
F_36 ( & V_2 -> V_61 ) ;
F_56 ( & V_2 -> V_61 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_6 -> V_64 ) ;
if ( V_2 -> V_5 )
V_2 -> V_6 -> V_83 [ V_2 -> V_4 ] = NULL ;
else
V_2 -> V_6 -> V_84 [ V_2 -> V_4 ] = NULL ;
if ( V_2 -> V_65 ) {
F_6 ( & V_2 -> V_6 -> V_29 -> V_30 , L_20 ,
F_7 ( V_2 ) , V_2 -> V_4 ) ;
}
F_41 ( V_2 ) ;
F_58 ( & V_2 -> V_6 -> V_29 -> V_30 ,
V_2 -> V_42 * sizeof( * V_2 -> V_51 ) ,
V_2 -> V_51 , V_2 -> V_86 ) ;
V_2 -> V_51 = NULL ;
V_2 -> V_86 = 0 ;
F_5 ( & V_2 -> V_6 -> V_29 -> V_30 ,
L_21 ,
F_7 ( V_2 ) ,
V_2 -> V_4 ) ;
F_30 ( & V_2 -> V_6 -> V_64 ) ;
F_56 ( & V_2 -> V_61 ) ;
F_50 ( & V_2 -> V_64 ) ;
F_51 ( V_2 ) ;
}
int F_59 ( struct V_31 * V_6 , enum F_59 V_92 , T_1 V_72 )
{
T_5 V_93 ;
T_1 V_94 ;
F_4 ( V_72 , V_6 -> V_21 + V_95 ) ;
V_94 = F_3 ( V_6 -> V_21 + V_96 ) ;
V_94 &= ~ ( V_97 | V_98 ) ;
V_94 |= V_99 | V_92 ;
F_4 ( V_94 , V_6 -> V_21 + V_96 ) ;
V_93 = F_60 ( F_61 () , V_100 ) ;
do {
V_94 = F_3 ( V_6 -> V_21 + V_96 ) ;
if ( ! ( V_94 & V_99 ) )
break;
F_62 ( 10 , 20 ) ;
} while ( F_63 ( F_61 () , V_93 ) );
if ( V_94 & V_99 )
return - V_101 ;
if ( V_94 & V_98 )
return - V_102 ;
return 0 ;
}
enum V_103 F_64 ( struct V_31 * V_6 )
{
T_1 V_94 ;
V_94 = F_3 ( V_6 -> V_21 + V_104 ) ;
V_94 &= V_105 ;
V_94 >>= V_106 ;
return (enum V_103 ) V_94 ;
}
static void F_65 ( struct V_60 * V_61 )
{
struct V_31 * V_6 = F_24 ( V_61 , F_25 ( * V_6 ) , V_107 ) ;
int V_39 = 0 ;
int V_3 ;
int V_4 = - 1 ;
int type = 0 ;
struct V_1 * V_2 ;
F_27 ( & V_6 -> V_64 ) ;
for ( V_3 = 0 ; V_3 < 3 * V_6 -> V_7 ; V_3 ++ ) {
if ( V_3 % 32 == 0 )
V_39 = F_3 ( V_6 -> V_21
+ V_33
+ 4 * ( V_3 / 32 ) ) ;
if ( ++ V_4 == V_6 -> V_7 ) {
V_4 = 0 ;
type ++ ;
}
if ( ( V_39 & ( 1 << ( V_3 % 32 ) ) ) == 0 )
continue;
if ( type == 2 ) {
F_66 ( & V_6 -> V_29 -> V_30 ,
L_22 ,
V_4 ) ;
continue;
}
if ( type == 0 )
V_2 = V_6 -> V_83 [ V_4 ] ;
else
V_2 = V_6 -> V_84 [ V_4 ] ;
if ( V_2 == NULL ) {
F_66 ( & V_6 -> V_29 -> V_30 ,
L_23 ,
type ? L_12 : L_11 ,
V_4 ) ;
continue;
}
F_36 ( & V_2 -> V_61 ) ;
}
F_30 ( & V_6 -> V_64 ) ;
}
static T_4 F_67 ( int V_14 , void * V_72 )
{
struct V_31 * V_6 = V_72 ;
F_36 ( & V_6 -> V_107 ) ;
return V_73 ;
}
static int F_68 ( struct V_108 * V_30 )
{
struct V_109 * V_29 = F_69 ( V_30 ) ;
struct V_110 * V_110 = F_70 ( V_29 ) ;
return F_71 ( V_110 ) ;
}
static int F_72 ( struct V_108 * V_30 )
{
struct V_109 * V_29 = F_69 ( V_30 ) ;
struct V_110 * V_110 = F_70 ( V_29 ) ;
if ( ! F_73 ( V_29 ) )
V_110 -> V_6 -> V_88 = true ;
return F_74 ( V_110 ) ;
}
static int F_75 ( struct V_108 * V_30 )
{
struct V_109 * V_29 = F_69 ( V_30 ) ;
struct V_110 * V_110 = F_70 ( V_29 ) ;
return F_76 ( V_110 ) ;
}
static void F_77 ( struct V_108 * V_30 )
{
struct V_109 * V_29 = F_69 ( V_30 ) ;
struct V_110 * V_110 = F_70 ( V_29 ) ;
F_78 ( V_110 ) ;
}
static void F_79 ( struct V_31 * V_6 )
{
int V_32 ;
F_5 ( & V_6 -> V_29 -> V_30 , L_24 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_7 ; V_32 ++ ) {
if ( V_6 -> V_83 [ V_32 ] )
F_6 ( & V_6 -> V_29 -> V_30 ,
L_25 , V_32 ) ;
if ( V_6 -> V_84 [ V_32 ] )
F_6 ( & V_6 -> V_29 -> V_30 ,
L_26 , V_32 ) ;
}
F_8 ( V_6 ) ;
if ( ! V_6 -> V_29 -> V_76 ) {
F_80 ( & V_6 -> V_29 -> V_30 , V_6 -> V_29 -> V_14 , V_6 ) ;
F_56 ( & V_6 -> V_107 ) ;
}
F_50 ( & V_6 -> V_64 ) ;
F_81 ( & V_6 -> V_77 ) ;
}
static int F_82 ( struct V_31 * V_6 )
{
struct V_109 * V_29 = V_6 -> V_29 ;
int V_111 , V_14 , V_112 ;
F_8 ( V_6 ) ;
F_83 ( & V_6 -> V_77 ) ;
V_112 = F_84 ( V_29 , V_113 , V_78 ,
V_114 ) ;
if ( V_112 < 0 ) {
V_112 = F_84 ( V_29 , 1 , 1 , V_115 ) ;
if ( V_112 < 0 )
return V_112 ;
F_48 ( & V_6 -> V_107 , F_65 ) ;
V_14 = F_39 ( V_6 -> V_29 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_111 = F_85 ( & V_29 -> V_30 , V_14 , F_67 ,
V_80 , L_9 , V_6 ) ;
if ( V_111 ) {
F_86 ( & V_29 -> V_30 , L_27 ) ;
return V_111 ;
}
}
return 0 ;
}
static int F_87 ( struct V_109 * V_29 , const struct V_116 * V_117 )
{
struct V_31 * V_6 ;
struct V_110 * V_110 ;
int V_111 ;
V_111 = F_88 ( V_29 ) ;
if ( V_111 ) {
F_86 ( & V_29 -> V_30 , L_28 ) ;
return V_111 ;
}
V_111 = F_89 ( V_29 , 1 << 0 , L_9 ) ;
if ( V_111 ) {
F_86 ( & V_29 -> V_30 , L_29 ) ;
return V_111 ;
}
V_6 = F_90 ( & V_29 -> V_30 , sizeof( * V_6 ) , V_79 ) ;
if ( ! V_6 )
return - V_118 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_21 = F_91 ( V_29 ) [ 0 ] ;
V_6 -> V_7 = F_3 ( V_6 -> V_21 + V_119 ) & 0x3ff ;
if ( V_6 -> V_7 != 12 && V_6 -> V_7 != 32 )
F_66 ( & V_29 -> V_30 , L_30 ,
V_6 -> V_7 ) ;
V_6 -> V_83 = F_92 ( & V_29 -> V_30 , V_6 -> V_7 ,
sizeof( * V_6 -> V_83 ) , V_79 ) ;
V_6 -> V_84 = F_92 ( & V_29 -> V_30 , V_6 -> V_7 ,
sizeof( * V_6 -> V_84 ) , V_79 ) ;
if ( ! V_6 -> V_83 || ! V_6 -> V_84 )
return - V_118 ;
V_111 = F_82 ( V_6 ) ;
if ( V_111 ) {
F_86 ( & V_29 -> V_30 , L_31 ) ;
return V_111 ;
}
F_46 ( & V_6 -> V_64 ) ;
F_93 ( V_29 ) ;
F_4 ( 3906250 / 10000 , V_6 -> V_21 + 0x38c00 ) ;
V_110 = F_94 ( V_6 ) ;
if ( ! V_110 )
V_110 = F_95 ( V_6 ) ;
if ( ! V_110 ) {
F_86 ( & V_6 -> V_29 -> V_30 ,
L_32 ) ;
return - V_120 ;
}
F_5 ( & V_6 -> V_29 -> V_30 , L_33 ) ;
V_111 = F_96 ( V_110 ) ;
if ( V_111 ) {
F_97 ( V_110 ) ;
F_79 ( V_6 ) ;
return - V_102 ;
}
F_98 ( V_29 , V_110 ) ;
return 0 ;
}
static void F_99 ( struct V_109 * V_29 )
{
struct V_110 * V_110 = F_70 ( V_29 ) ;
struct V_31 * V_6 = V_110 -> V_6 ;
F_100 ( V_110 ) ;
F_79 ( V_6 ) ;
}
static int T_6 F_101 ( void )
{
int V_70 ;
V_70 = F_102 () ;
if ( V_70 )
return V_70 ;
V_70 = F_103 ( & V_121 ) ;
if ( V_70 )
F_104 () ;
return V_70 ;
}
static void T_7 F_105 ( void )
{
F_106 ( & V_121 ) ;
F_104 () ;
}
