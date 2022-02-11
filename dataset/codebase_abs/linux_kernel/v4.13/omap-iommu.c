static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
T_1 * V_9 = V_8 -> V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < ( V_12 / sizeof( T_1 ) ) ; V_11 ++ ) {
V_9 [ V_11 ] = F_5 ( V_8 , V_11 * sizeof( T_1 ) ) ;
F_6 ( V_8 -> V_6 , L_1 , V_13 , V_11 , V_9 [ V_11 ] ) ;
}
}
void F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
T_1 * V_9 = V_8 -> V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < ( V_12 / sizeof( T_1 ) ) ; V_11 ++ ) {
F_8 ( V_8 , V_9 [ V_11 ] , V_11 * sizeof( T_1 ) ) ;
F_6 ( V_8 -> V_6 , L_1 , V_13 , V_11 , V_9 [ V_11 ] ) ;
}
}
static void F_9 ( struct V_7 * V_8 , bool V_14 )
{
T_1 V_15 , V_16 ;
if ( ! V_8 -> V_17 )
return;
V_16 = ( 1 << ( V_8 -> V_18 * V_19 ) ) ;
V_15 = V_14 ? V_16 : 0 ;
F_10 ( V_8 -> V_17 , V_20 , V_16 , V_15 ) ;
}
static void F_11 ( struct V_7 * V_8 , bool V_21 )
{
T_1 V_22 = F_5 ( V_8 , V_23 ) ;
if ( V_21 )
F_8 ( V_8 , V_24 , V_25 ) ;
else
F_8 ( V_8 , V_26 , V_25 ) ;
V_22 &= ~ V_27 ;
if ( V_21 )
V_22 |= ( V_28 | V_29 ) ;
else
V_22 |= ( V_28 ) ;
F_8 ( V_8 , V_22 , V_23 ) ;
}
static int F_12 ( struct V_7 * V_8 )
{
T_1 V_22 , V_30 ;
if ( ! V_8 -> V_31 || ! F_13 ( ( T_1 ) V_8 -> V_31 , V_32 ) )
return - V_33 ;
V_30 = F_14 ( V_8 -> V_31 ) ;
if ( ! F_13 ( V_30 , V_32 ) )
return - V_33 ;
V_22 = F_5 ( V_8 , V_34 ) ;
F_15 ( V_8 -> V_6 , L_2 , V_8 -> V_35 ,
( V_22 >> 4 ) & 0xf , V_22 & 0xf ) ;
F_8 ( V_8 , V_30 , V_36 ) ;
F_9 ( V_8 , true ) ;
if ( V_8 -> V_37 )
F_8 ( V_8 , V_38 , V_39 ) ;
F_11 ( V_8 , true ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_8 )
{
T_1 V_22 = F_5 ( V_8 , V_23 ) ;
V_22 &= ~ V_27 ;
F_8 ( V_8 , V_22 , V_23 ) ;
F_9 ( V_8 , false ) ;
F_6 ( V_8 -> V_6 , L_3 , V_8 -> V_35 ) ;
}
static int F_17 ( struct V_7 * V_8 )
{
int V_40 ;
struct V_41 * V_42 = F_18 ( V_8 -> V_6 ) ;
struct V_43 * V_44 = F_19 ( & V_42 -> V_6 ) ;
if ( V_44 && V_44 -> V_45 ) {
V_40 = V_44 -> V_45 ( V_42 , V_44 -> V_46 ) ;
if ( V_40 ) {
F_20 ( V_8 -> V_6 , L_4 , V_40 ) ;
return V_40 ;
}
}
F_21 ( V_8 -> V_6 ) ;
V_40 = F_12 ( V_8 ) ;
return V_40 ;
}
static void F_22 ( struct V_7 * V_8 )
{
struct V_41 * V_42 = F_18 ( V_8 -> V_6 ) ;
struct V_43 * V_44 = F_19 ( & V_42 -> V_6 ) ;
F_16 ( V_8 ) ;
F_23 ( V_8 -> V_6 ) ;
if ( V_44 && V_44 -> V_47 )
V_44 -> V_47 ( V_42 , V_44 -> V_46 ) ;
}
static T_1 F_24 ( struct V_48 * V_49 )
{
T_1 V_50 = V_49 -> V_51 & V_52 ;
T_1 V_16 = F_25 ( V_49 -> V_51 & V_50 ) ;
return V_49 -> V_51 & V_16 ;
}
static T_1 F_26 ( struct V_53 * V_54 )
{
T_1 V_55 ;
V_55 = V_54 -> V_56 << 5 ;
V_55 |= V_54 -> V_57 ;
V_55 |= V_54 -> V_58 >> 3 ;
V_55 <<= ( ( ( V_54 -> V_59 == V_60 ) ||
( V_54 -> V_59 == V_61 ) ) ? 0 : 6 ) ;
return V_55 ;
}
static T_1 F_27 ( struct V_7 * V_8 , T_1 * V_62 )
{
T_1 V_63 , V_64 ;
V_63 = F_5 ( V_8 , V_65 ) ;
V_63 &= V_66 ;
if ( ! V_63 ) {
* V_62 = 0 ;
return 0 ;
}
V_64 = F_5 ( V_8 , V_67 ) ;
* V_62 = V_64 ;
F_8 ( V_8 , V_63 , V_65 ) ;
return V_63 ;
}
void F_28 ( struct V_7 * V_8 , struct V_68 * V_22 )
{
T_1 V_15 ;
V_15 = F_5 ( V_8 , V_69 ) ;
V_22 -> V_70 = F_29 ( V_15 ) ;
V_22 -> V_71 = F_30 ( V_15 ) ;
}
void F_31 ( struct V_7 * V_8 , struct V_68 * V_22 )
{
T_1 V_15 ;
V_15 = ( V_22 -> V_70 << V_72 ) ;
V_15 |= ( V_22 -> V_71 << V_73 ) ;
F_8 ( V_8 , V_15 , V_69 ) ;
}
static void F_32 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
V_49 -> V_51 = F_5 ( V_8 , V_74 ) ;
V_49 -> V_75 = F_5 ( V_8 , V_76 ) ;
}
static void F_33 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
F_8 ( V_8 , V_49 -> V_51 | V_77 , V_78 ) ;
F_8 ( V_8 , V_49 -> V_75 , V_79 ) ;
F_8 ( V_8 , 1 , V_80 ) ;
F_8 ( V_8 , 1 , V_81 ) ;
}
struct V_48 F_34 ( struct V_7 * V_8 , int V_82 )
{
struct V_48 V_49 ;
struct V_68 V_22 ;
F_28 ( V_8 , & V_22 ) ;
V_22 . V_71 = V_82 ;
F_31 ( V_8 , & V_22 ) ;
F_32 ( V_8 , & V_49 ) ;
return V_49 ;
}
static struct V_48 * F_35 ( struct V_7 * V_8 ,
struct V_53 * V_54 )
{
struct V_48 * V_49 ;
if ( ! V_54 )
return NULL ;
if ( V_54 -> V_62 & ~ ( F_25 ( V_54 -> V_59 ) ) ) {
F_20 ( V_8 -> V_6 , L_5 , V_13 ,
V_54 -> V_62 ) ;
return F_36 ( - V_33 ) ;
}
V_49 = F_37 ( sizeof( * V_49 ) , V_83 ) ;
if ( ! V_49 )
return F_36 ( - V_84 ) ;
V_49 -> V_51 = ( V_54 -> V_62 & V_85 ) | V_54 -> V_86 | V_54 -> V_59 | V_54 -> V_87 ;
V_49 -> V_75 = V_54 -> V_30 | V_54 -> V_57 | V_54 -> V_58 | V_54 -> V_56 ;
return V_49 ;
}
static int F_38 ( struct V_7 * V_8 , struct V_53 * V_54 )
{
int V_40 = 0 ;
struct V_68 V_22 ;
struct V_48 * V_49 ;
if ( ! V_8 || ! V_8 -> V_88 || ! V_54 )
return - V_33 ;
F_21 ( V_8 -> V_6 ) ;
F_28 ( V_8 , & V_22 ) ;
if ( V_22 . V_70 == V_8 -> V_88 ) {
F_39 ( V_8 -> V_6 , L_6 , V_13 ) ;
V_40 = - V_89 ;
goto V_90;
}
if ( ! V_54 -> V_86 ) {
int V_11 ;
struct V_48 V_91 ;
F_40 (obj, obj->nr_tlb_entries, i, tmp)
if ( ! F_41 ( & V_91 ) )
break;
if ( V_11 == V_8 -> V_88 ) {
F_6 ( V_8 -> V_6 , L_7 , V_13 ) ;
V_40 = - V_89 ;
goto V_90;
}
F_28 ( V_8 , & V_22 ) ;
} else {
V_22 . V_71 = V_22 . V_70 ;
F_31 ( V_8 , & V_22 ) ;
}
V_49 = F_35 ( V_8 , V_54 ) ;
if ( F_42 ( V_49 ) ) {
F_23 ( V_8 -> V_6 ) ;
return F_43 ( V_49 ) ;
}
F_33 ( V_8 , V_49 ) ;
F_44 ( V_49 ) ;
if ( V_54 -> V_86 )
V_22 . V_70 ++ ;
if ( ++ V_22 . V_71 == V_8 -> V_88 )
V_22 . V_71 = V_22 . V_70 ;
F_31 ( V_8 , & V_22 ) ;
V_90:
F_23 ( V_8 -> V_6 ) ;
return V_40 ;
}
static int F_38 ( struct V_7 * V_8 , struct V_53 * V_54 )
{
return 0 ;
}
static int F_45 ( struct V_7 * V_8 , struct V_53 * V_54 )
{
return F_38 ( V_8 , V_54 ) ;
}
static void F_46 ( struct V_7 * V_8 , T_1 V_62 )
{
int V_11 ;
struct V_48 V_49 ;
F_21 ( V_8 -> V_6 ) ;
F_40 (obj, obj->nr_tlb_entries, i, cr) {
T_1 V_92 ;
T_2 V_93 ;
if ( ! F_41 ( & V_49 ) )
continue;
V_92 = F_24 ( & V_49 ) ;
V_93 = F_47 ( V_49 . V_51 & 3 ) ;
if ( ( V_92 <= V_62 ) && ( V_62 < V_92 + V_93 ) ) {
F_6 ( V_8 -> V_6 , L_8 ,
V_13 , V_92 , V_62 , V_93 ) ;
F_33 ( V_8 , & V_49 ) ;
F_8 ( V_8 , 1 , V_80 ) ;
break;
}
}
F_23 ( V_8 -> V_6 ) ;
if ( V_11 == V_8 -> V_88 )
F_6 ( V_8 -> V_6 , L_9 , V_13 , V_62 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_68 V_22 ;
F_21 ( V_8 -> V_6 ) ;
V_22 . V_70 = 0 ;
V_22 . V_71 = 0 ;
F_31 ( V_8 , & V_22 ) ;
F_8 ( V_8 , 1 , V_94 ) ;
F_23 ( V_8 -> V_6 ) ;
}
static void F_49 ( T_1 * V_95 , T_1 * V_96 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pgd"
: : "r" (first));
V_95 += V_97 / sizeof( * V_95 ) ;
} while ( V_95 <= V_96 );
}
static void F_50 ( T_1 * V_95 , T_1 * V_96 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pte"
: : "r" (first));
V_95 += V_97 / sizeof( * V_95 ) ;
} while ( V_95 <= V_96 );
}
static void F_51 ( T_1 * V_98 )
{
if ( V_98 )
F_52 ( V_99 , V_98 ) ;
}
static T_1 * F_53 ( struct V_7 * V_8 , T_1 * V_31 , T_1 V_62 )
{
T_1 * V_98 ;
if ( * V_31 )
goto V_100;
F_54 ( & V_8 -> V_101 ) ;
V_98 = F_55 ( V_99 , V_83 ) ;
F_56 ( & V_8 -> V_101 ) ;
if ( ! * V_31 ) {
if ( ! V_98 )
return F_36 ( - V_84 ) ;
* V_31 = F_14 ( V_98 ) | V_102 ;
F_49 ( V_31 , V_31 ) ;
F_57 ( V_8 -> V_6 , L_10 , V_13 , V_98 ) ;
} else {
F_51 ( V_98 ) ;
}
V_100:
V_98 = F_58 ( V_31 , V_62 ) ;
F_57 ( V_8 -> V_6 ,
L_11 ,
V_13 , V_62 , V_31 , * V_31 , V_98 , * V_98 ) ;
return V_98 ;
}
static int F_59 ( struct V_7 * V_8 , T_1 V_62 , T_1 V_30 , T_1 V_103 )
{
T_1 * V_31 = F_60 ( V_8 , V_62 ) ;
if ( ( V_62 | V_30 ) & ~ V_104 ) {
F_20 ( V_8 -> V_6 , L_12 ,
V_13 , V_62 , V_30 , V_105 ) ;
return - V_33 ;
}
* V_31 = ( V_30 & V_104 ) | V_103 | V_106 ;
F_49 ( V_31 , V_31 ) ;
return 0 ;
}
static int F_61 ( struct V_7 * V_8 , T_1 V_62 , T_1 V_30 , T_1 V_103 )
{
T_1 * V_31 = F_60 ( V_8 , V_62 ) ;
int V_11 ;
if ( ( V_62 | V_30 ) & ~ V_107 ) {
F_20 ( V_8 -> V_6 , L_12 ,
V_13 , V_62 , V_30 , V_108 ) ;
return - V_33 ;
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
* ( V_31 + V_11 ) = ( V_30 & V_107 ) | V_103 | V_109 ;
F_49 ( V_31 , V_31 + 15 ) ;
return 0 ;
}
static int F_62 ( struct V_7 * V_8 , T_1 V_62 , T_1 V_30 , T_1 V_103 )
{
T_1 * V_31 = F_60 ( V_8 , V_62 ) ;
T_1 * V_98 = F_53 ( V_8 , V_31 , V_62 ) ;
if ( F_42 ( V_98 ) )
return F_43 ( V_98 ) ;
* V_98 = ( V_30 & V_110 ) | V_103 | V_111 ;
F_50 ( V_98 , V_98 ) ;
F_57 ( V_8 -> V_6 , L_13 ,
V_13 , V_62 , V_30 , V_98 , * V_98 ) ;
return 0 ;
}
static int F_63 ( struct V_7 * V_8 , T_1 V_62 , T_1 V_30 , T_1 V_103 )
{
T_1 * V_31 = F_60 ( V_8 , V_62 ) ;
T_1 * V_98 = F_53 ( V_8 , V_31 , V_62 ) ;
int V_11 ;
if ( ( V_62 | V_30 ) & ~ V_112 ) {
F_20 ( V_8 -> V_6 , L_12 ,
V_13 , V_62 , V_30 , V_113 ) ;
return - V_33 ;
}
if ( F_42 ( V_98 ) )
return F_43 ( V_98 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
* ( V_98 + V_11 ) = ( V_30 & V_112 ) | V_103 | V_114 ;
F_50 ( V_98 , V_98 + 15 ) ;
return 0 ;
}
static int
F_64 ( struct V_7 * V_8 , struct V_53 * V_54 )
{
int (* F_65)( struct V_7 * , T_1 , T_1 , T_1 );
T_1 V_103 ;
int V_40 ;
if ( ! V_8 || ! V_54 )
return - V_33 ;
switch ( V_54 -> V_59 ) {
case V_115 :
F_65 = F_61 ;
break;
case V_116 :
F_65 = F_59 ;
break;
case V_61 :
F_65 = F_63 ;
break;
case V_60 :
F_65 = F_62 ;
break;
default:
F_65 = NULL ;
break;
}
if ( F_66 ( ! F_65 ) )
return - V_33 ;
V_103 = F_26 ( V_54 ) ;
F_56 ( & V_8 -> V_101 ) ;
V_40 = F_65 ( V_8 , V_54 -> V_62 , V_54 -> V_30 , V_103 ) ;
F_54 ( & V_8 -> V_101 ) ;
return V_40 ;
}
static int
F_67 ( struct V_7 * V_8 , struct V_53 * V_54 )
{
int V_40 ;
F_46 ( V_8 , V_54 -> V_62 ) ;
V_40 = F_64 ( V_8 , V_54 ) ;
if ( ! V_40 )
F_45 ( V_8 , V_54 ) ;
return V_40 ;
}
static void
F_68 ( struct V_7 * V_8 , T_1 V_62 , T_1 * * V_117 , T_1 * * V_118 )
{
T_1 * V_31 , * V_98 = NULL ;
V_31 = F_60 ( V_8 , V_62 ) ;
if ( ! * V_31 )
goto V_90;
if ( F_69 ( * V_31 ) )
V_98 = F_58 ( V_31 , V_62 ) ;
V_90:
* V_117 = V_31 ;
* V_118 = V_98 ;
}
static T_2 F_70 ( struct V_7 * V_8 , T_1 V_62 )
{
T_2 V_93 ;
T_1 * V_31 = F_60 ( V_8 , V_62 ) ;
int V_119 = 1 ;
if ( ! * V_31 )
return 0 ;
if ( F_69 ( * V_31 ) ) {
int V_11 ;
T_1 * V_98 = F_58 ( V_31 , V_62 ) ;
V_93 = V_120 ;
if ( * V_98 & V_114 ) {
V_119 *= 16 ;
V_98 = F_58 ( V_31 , ( V_62 & V_112 ) ) ;
}
V_93 *= V_119 ;
memset ( V_98 , 0 , V_119 * sizeof( * V_98 ) ) ;
F_50 ( V_98 , V_98 + ( V_119 - 1 ) * sizeof( * V_98 ) ) ;
V_98 = F_58 ( V_31 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_121 ; V_11 ++ )
if ( V_98 [ V_11 ] )
goto V_90;
F_51 ( V_98 ) ;
V_119 = 1 ;
} else {
V_93 = V_122 ;
if ( ( * V_31 & V_109 ) == V_109 ) {
V_119 *= 16 ;
V_31 = F_60 ( V_8 , ( V_62 & V_107 ) ) ;
}
V_93 *= V_119 ;
}
memset ( V_31 , 0 , V_119 * sizeof( * V_31 ) ) ;
F_49 ( V_31 , V_31 + ( V_119 - 1 ) * sizeof( * V_31 ) ) ;
V_90:
return V_93 ;
}
static T_2 F_71 ( struct V_7 * V_8 , T_1 V_62 )
{
T_2 V_93 ;
F_56 ( & V_8 -> V_101 ) ;
V_93 = F_70 ( V_8 , V_62 ) ;
F_46 ( V_8 , V_62 ) ;
F_54 ( & V_8 -> V_101 ) ;
return V_93 ;
}
static void F_72 ( struct V_7 * V_8 )
{
int V_11 ;
F_56 ( & V_8 -> V_101 ) ;
for ( V_11 = 0 ; V_11 < V_123 ; V_11 ++ ) {
T_1 V_62 ;
T_1 * V_31 ;
V_62 = V_11 << V_124 ;
V_31 = F_60 ( V_8 , V_62 ) ;
if ( ! * V_31 )
continue;
if ( F_69 ( * V_31 ) )
F_51 ( F_58 ( V_31 , 0 ) ) ;
* V_31 = 0 ;
F_49 ( V_31 , V_31 ) ;
}
F_48 ( V_8 ) ;
F_54 ( & V_8 -> V_101 ) ;
}
static T_3 F_73 ( int V_125 , void * V_126 )
{
T_1 V_62 , V_127 ;
T_1 * V_31 , * V_98 ;
struct V_7 * V_8 = V_126 ;
struct V_2 * V_4 = V_8 -> V_4 ;
struct V_1 * V_128 = F_1 ( V_4 ) ;
if ( ! V_128 -> V_129 )
return V_130 ;
V_127 = F_27 ( V_8 , & V_62 ) ;
if ( V_127 == 0 )
return V_131 ;
if ( ! F_74 ( V_4 , V_8 -> V_6 , V_62 , 0 ) )
return V_131 ;
F_22 ( V_8 ) ;
V_31 = F_60 ( V_8 , V_62 ) ;
if ( ! F_69 ( * V_31 ) ) {
F_20 ( V_8 -> V_6 , L_14 ,
V_8 -> V_35 , V_127 , V_62 , V_31 , * V_31 ) ;
return V_130 ;
}
V_98 = F_58 ( V_31 , V_62 ) ;
F_20 ( V_8 -> V_6 , L_15 ,
V_8 -> V_35 , V_127 , V_62 , V_31 , * V_31 , V_98 , * V_98 ) ;
return V_130 ;
}
static int F_75 ( struct V_7 * V_8 , T_1 * V_31 )
{
int V_40 ;
F_56 ( & V_8 -> V_132 ) ;
V_8 -> V_31 = V_31 ;
V_40 = F_17 ( V_8 ) ;
if ( V_40 )
goto V_133;
F_48 ( V_8 ) ;
F_54 ( & V_8 -> V_132 ) ;
F_6 ( V_8 -> V_6 , L_16 , V_13 , V_8 -> V_35 ) ;
return 0 ;
V_133:
F_54 ( & V_8 -> V_132 ) ;
return V_40 ;
}
static void F_76 ( struct V_7 * V_8 )
{
if ( ! V_8 || F_42 ( V_8 ) )
return;
F_56 ( & V_8 -> V_132 ) ;
F_22 ( V_8 ) ;
V_8 -> V_31 = NULL ;
F_54 ( & V_8 -> V_132 ) ;
F_6 ( V_8 -> V_6 , L_16 , V_13 , V_8 -> V_35 ) ;
}
static int F_77 ( struct V_41 * V_42 ,
struct V_7 * V_8 )
{
struct V_134 * V_135 = V_42 -> V_6 . V_136 ;
int V_137 ;
if ( ! F_78 ( V_135 , L_17 ) )
return 0 ;
if ( ! F_79 ( V_135 , L_18 ) ) {
F_20 ( & V_42 -> V_6 , L_19 ) ;
return - V_33 ;
}
V_8 -> V_17 =
F_80 ( V_135 , L_18 ) ;
if ( F_42 ( V_8 -> V_17 ) ) {
V_137 = F_43 ( V_8 -> V_17 ) ;
return V_137 ;
}
if ( F_81 ( V_135 , L_18 , 1 ,
& V_8 -> V_18 ) ) {
F_20 ( & V_42 -> V_6 , L_20 ) ;
return - V_33 ;
}
if ( V_8 -> V_18 != 0 && V_8 -> V_18 != 1 ) {
F_20 ( & V_42 -> V_6 , L_21 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_82 ( struct V_41 * V_42 )
{
int V_40 = - V_138 ;
int V_125 ;
struct V_7 * V_8 ;
struct V_139 * V_140 ;
struct V_134 * V_141 = V_42 -> V_6 . V_136 ;
if ( ! V_141 ) {
F_83 ( L_22 , V_13 ) ;
return - V_138 ;
}
V_8 = F_84 ( & V_42 -> V_6 , sizeof( * V_8 ) + V_12 , V_83 ) ;
if ( ! V_8 )
return - V_84 ;
V_8 -> V_35 = F_85 ( & V_42 -> V_6 ) ;
V_8 -> V_88 = 32 ;
V_40 = F_86 ( V_141 , L_23 , & V_8 -> V_88 ) ;
if ( V_40 && V_40 != - V_33 )
return V_40 ;
if ( V_8 -> V_88 != 32 && V_8 -> V_88 != 8 )
return - V_33 ;
if ( F_87 ( V_141 , L_24 , NULL ) )
V_8 -> V_37 = V_38 ;
V_8 -> V_6 = & V_42 -> V_6 ;
V_8 -> V_10 = ( void * ) V_8 + sizeof( * V_8 ) ;
F_88 ( & V_8 -> V_132 ) ;
F_88 ( & V_8 -> V_101 ) ;
V_140 = F_89 ( V_42 , V_142 , 0 ) ;
V_8 -> V_143 = F_90 ( V_8 -> V_6 , V_140 ) ;
if ( F_42 ( V_8 -> V_143 ) )
return F_43 ( V_8 -> V_143 ) ;
V_40 = F_77 ( V_42 , V_8 ) ;
if ( V_40 )
return V_40 ;
V_125 = F_91 ( V_42 , 0 ) ;
if ( V_125 < 0 )
return - V_138 ;
V_40 = F_92 ( V_8 -> V_6 , V_125 , F_73 , V_144 ,
F_85 ( V_8 -> V_6 ) , V_8 ) ;
if ( V_40 < 0 )
return V_40 ;
F_93 ( V_42 , V_8 ) ;
V_8 -> V_145 = F_94 () ;
if ( F_42 ( V_8 -> V_145 ) )
return F_43 ( V_8 -> V_145 ) ;
V_40 = F_95 ( & V_8 -> V_146 , V_8 -> V_6 , NULL , V_8 -> V_35 ) ;
if ( V_40 )
goto V_147;
F_96 ( & V_8 -> V_146 , & V_148 ) ;
V_40 = F_97 ( & V_8 -> V_146 ) ;
if ( V_40 )
goto V_149;
F_98 ( V_8 -> V_6 ) ;
F_99 ( V_8 -> V_6 ) ;
F_100 ( V_8 ) ;
F_15 ( & V_42 -> V_6 , L_25 , V_8 -> V_35 ) ;
return 0 ;
V_149:
F_101 ( & V_8 -> V_146 ) ;
V_147:
F_102 ( V_8 -> V_145 ) ;
return V_40 ;
}
static int F_103 ( struct V_41 * V_42 )
{
struct V_7 * V_8 = F_104 ( V_42 ) ;
F_102 ( V_8 -> V_145 ) ;
V_8 -> V_145 = NULL ;
F_101 ( & V_8 -> V_146 ) ;
F_105 ( & V_8 -> V_146 ) ;
F_106 ( V_8 ) ;
F_107 ( V_8 -> V_6 ) ;
F_15 ( & V_42 -> V_6 , L_26 , V_8 -> V_35 ) ;
return 0 ;
}
static void F_108 ( void * V_98 )
{
F_109 ( V_98 , V_150 ) ;
}
static T_1 F_110 ( struct V_53 * V_54 , T_1 V_62 , T_1 V_30 , int V_59 )
{
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_62 = V_62 ;
V_54 -> V_30 = V_30 ;
V_54 -> V_87 = V_77 ;
V_54 -> V_59 = V_59 ;
V_54 -> V_57 = V_151 ;
V_54 -> V_58 = V_152 ;
V_54 -> V_56 = 0 ;
return F_47 ( V_54 -> V_59 ) ;
}
static int F_111 ( struct V_2 * V_4 , unsigned long V_62 ,
T_4 V_30 , T_2 V_93 , int V_103 )
{
struct V_1 * V_128 = F_1 ( V_4 ) ;
struct V_7 * V_153 = V_128 -> V_129 ;
struct V_5 * V_6 = V_153 -> V_6 ;
struct V_53 V_54 ;
int V_154 ;
T_1 V_137 ;
V_154 = F_112 ( V_93 ) ;
if ( V_154 < 0 ) {
F_20 ( V_6 , L_27 , V_93 ) ;
return - V_33 ;
}
F_6 ( V_6 , L_28 , V_62 , & V_30 , V_93 ) ;
F_110 ( & V_54 , V_62 , V_30 , V_154 ) ;
V_137 = F_67 ( V_153 , & V_54 ) ;
if ( V_137 )
F_20 ( V_6 , L_29 , V_137 ) ;
return V_137 ;
}
static T_2 F_113 ( struct V_2 * V_4 , unsigned long V_62 ,
T_2 V_155 )
{
struct V_1 * V_128 = F_1 ( V_4 ) ;
struct V_7 * V_153 = V_128 -> V_129 ;
struct V_5 * V_6 = V_153 -> V_6 ;
F_6 ( V_6 , L_30 , V_62 , V_155 ) ;
return F_71 ( V_153 , V_62 ) ;
}
static int
F_114 ( struct V_2 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_128 = F_1 ( V_4 ) ;
struct V_156 * V_157 = V_6 -> V_158 . V_146 ;
struct V_7 * V_153 ;
int V_137 = 0 ;
if ( ! V_157 || ! V_157 -> V_129 ) {
F_20 ( V_6 , L_31 ) ;
return - V_33 ;
}
F_56 ( & V_128 -> V_159 ) ;
if ( V_128 -> V_129 ) {
F_20 ( V_6 , L_32 ) ;
V_137 = - V_89 ;
goto V_90;
}
V_153 = V_157 -> V_129 ;
V_137 = F_75 ( V_153 , V_128 -> V_160 ) ;
if ( V_137 ) {
F_20 ( V_6 , L_33 , V_137 ) ;
goto V_90;
}
V_128 -> V_129 = V_153 ;
V_128 -> V_6 = V_6 ;
V_153 -> V_4 = V_4 ;
V_90:
F_54 ( & V_128 -> V_159 ) ;
return V_137 ;
}
static void F_115 ( struct V_1 * V_128 ,
struct V_5 * V_6 )
{
struct V_7 * V_153 = F_4 ( V_6 ) ;
if ( V_128 -> V_129 != V_153 ) {
F_20 ( V_6 , L_34 ) ;
return;
}
F_72 ( V_153 ) ;
F_76 ( V_153 ) ;
V_128 -> V_129 = NULL ;
V_128 -> V_6 = NULL ;
V_153 -> V_4 = NULL ;
}
static void F_116 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_128 = F_1 ( V_4 ) ;
F_56 ( & V_128 -> V_159 ) ;
F_115 ( V_128 , V_6 ) ;
F_54 ( & V_128 -> V_159 ) ;
}
static struct V_2 * F_117 ( unsigned type )
{
struct V_1 * V_128 ;
if ( type != V_161 )
return NULL ;
V_128 = F_118 ( sizeof( * V_128 ) , V_83 ) ;
if ( ! V_128 )
goto V_90;
V_128 -> V_160 = F_118 ( V_162 , V_83 ) ;
if ( ! V_128 -> V_160 )
goto V_163;
if ( F_66 ( ! F_13 ( ( long ) V_128 -> V_160 , V_162 ) ) )
goto V_164;
F_109 ( V_128 -> V_160 , V_162 ) ;
F_88 ( & V_128 -> V_159 ) ;
V_128 -> V_4 . V_165 . V_166 = 0 ;
V_128 -> V_4 . V_165 . V_167 = ( 1ULL << 32 ) - 1 ;
V_128 -> V_4 . V_165 . V_168 = true ;
return & V_128 -> V_4 ;
V_164:
F_44 ( V_128 -> V_160 ) ;
V_163:
F_44 ( V_128 ) ;
V_90:
return NULL ;
}
static void F_119 ( struct V_2 * V_4 )
{
struct V_1 * V_128 = F_1 ( V_4 ) ;
if ( V_128 -> V_129 )
F_115 ( V_128 , V_128 -> V_6 ) ;
F_44 ( V_128 -> V_160 ) ;
F_44 ( V_128 ) ;
}
static T_4 F_120 ( struct V_2 * V_4 ,
T_5 V_62 )
{
struct V_1 * V_128 = F_1 ( V_4 ) ;
struct V_7 * V_153 = V_128 -> V_129 ;
struct V_5 * V_6 = V_153 -> V_6 ;
T_1 * V_169 , * V_170 ;
T_4 V_137 = 0 ;
F_68 ( V_153 , V_62 , & V_169 , & V_170 ) ;
if ( V_170 ) {
if ( F_121 ( * V_170 ) )
V_137 = F_122 ( * V_170 , V_62 , V_171 ) ;
else if ( F_123 ( * V_170 ) )
V_137 = F_122 ( * V_170 , V_62 , V_112 ) ;
else
F_20 ( V_6 , L_35 , * V_170 ,
( unsigned long long ) V_62 ) ;
} else {
if ( F_124 ( * V_169 ) )
V_137 = F_122 ( * V_169 , V_62 , V_104 ) ;
else if ( F_125 ( * V_169 ) )
V_137 = F_122 ( * V_169 , V_62 , V_107 ) ;
else
F_20 ( V_6 , L_36 , * V_169 ,
( unsigned long long ) V_62 ) ;
}
return V_137 ;
}
static int F_126 ( struct V_5 * V_6 )
{
struct V_156 * V_157 ;
struct V_7 * V_153 ;
struct V_172 * V_145 ;
struct V_134 * V_135 ;
struct V_41 * V_42 ;
int V_137 ;
if ( ! V_6 -> V_136 )
return 0 ;
V_135 = F_127 ( V_6 -> V_136 , L_37 , 0 ) ;
if ( ! V_135 )
return 0 ;
V_42 = F_128 ( V_135 ) ;
if ( F_66 ( ! V_42 ) ) {
F_129 ( V_135 ) ;
return - V_33 ;
}
V_153 = F_104 ( V_42 ) ;
if ( ! V_153 ) {
F_129 ( V_135 ) ;
return - V_33 ;
}
V_157 = F_118 ( sizeof( * V_157 ) , V_83 ) ;
if ( ! V_157 ) {
F_129 ( V_135 ) ;
return - V_84 ;
}
V_137 = F_130 ( & V_153 -> V_146 , V_6 ) ;
if ( V_137 ) {
F_44 ( V_157 ) ;
F_129 ( V_135 ) ;
return V_137 ;
}
V_157 -> V_129 = V_153 ;
V_6 -> V_158 . V_146 = V_157 ;
V_145 = F_131 ( V_6 ) ;
if ( F_42 ( V_145 ) ) {
F_132 ( & V_153 -> V_146 , V_6 ) ;
V_6 -> V_158 . V_146 = NULL ;
F_44 ( V_157 ) ;
return F_43 ( V_145 ) ;
}
F_102 ( V_145 ) ;
F_129 ( V_135 ) ;
return 0 ;
}
static void F_133 ( struct V_5 * V_6 )
{
struct V_156 * V_157 = V_6 -> V_158 . V_146 ;
if ( ! V_6 -> V_136 || ! V_157 )
return;
F_132 ( & V_157 -> V_129 -> V_146 , V_6 ) ;
F_134 ( V_6 ) ;
V_6 -> V_158 . V_146 = NULL ;
F_44 ( V_157 ) ;
}
static struct V_172 * F_135 ( struct V_5 * V_6 )
{
struct V_156 * V_157 = V_6 -> V_158 . V_146 ;
struct V_172 * V_145 = F_36 ( - V_33 ) ;
if ( V_157 -> V_129 )
V_145 = V_157 -> V_129 -> V_145 ;
return V_145 ;
}
static int T_6 F_136 ( void )
{
struct V_173 * V_9 ;
const unsigned long V_174 = V_175 ;
T_2 V_176 = 1 << 10 ;
struct V_134 * V_135 ;
int V_137 ;
V_135 = F_137 ( NULL , V_177 ) ;
if ( ! V_135 )
return 0 ;
F_129 ( V_135 ) ;
V_9 = F_138 ( L_38 , V_150 , V_176 , V_174 ,
F_108 ) ;
if ( ! V_9 )
return - V_84 ;
V_99 = V_9 ;
F_139 () ;
V_137 = F_140 ( & V_178 ) ;
if ( V_137 ) {
F_83 ( L_39 , V_13 ) ;
goto V_179;
}
V_137 = F_141 ( & V_180 , & V_148 ) ;
if ( V_137 )
goto V_181;
return 0 ;
V_181:
F_142 ( & V_178 ) ;
V_179:
F_143 ( V_99 ) ;
return V_137 ;
}
