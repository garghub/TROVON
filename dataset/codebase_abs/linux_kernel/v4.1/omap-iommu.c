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
T_1 V_15 = F_5 ( V_8 , V_16 ) ;
if ( V_14 )
F_8 ( V_8 , V_17 , V_18 ) ;
else
F_8 ( V_8 , V_19 , V_18 ) ;
V_15 &= ~ V_20 ;
if ( V_14 )
V_15 |= ( V_21 | V_22 ) ;
else
V_15 |= ( V_21 ) ;
F_8 ( V_8 , V_15 , V_16 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
T_1 V_15 , V_23 ;
if ( ! V_8 -> V_24 || ! F_11 ( ( T_1 ) V_8 -> V_24 , V_25 ) )
return - V_26 ;
V_23 = F_12 ( V_8 -> V_24 ) ;
if ( ! F_11 ( V_23 , V_25 ) )
return - V_26 ;
V_15 = F_5 ( V_8 , V_27 ) ;
F_13 ( V_8 -> V_6 , L_2 , V_8 -> V_28 ,
( V_15 >> 4 ) & 0xf , V_15 & 0xf ) ;
F_8 ( V_8 , V_23 , V_29 ) ;
if ( V_8 -> V_30 )
F_8 ( V_8 , V_31 , V_32 ) ;
F_9 ( V_8 , true ) ;
return 0 ;
}
static void F_14 ( struct V_7 * V_8 )
{
T_1 V_15 = F_5 ( V_8 , V_16 ) ;
V_15 &= ~ V_20 ;
F_8 ( V_8 , V_15 , V_16 ) ;
F_6 ( V_8 -> V_6 , L_3 , V_8 -> V_28 ) ;
}
static int F_15 ( struct V_7 * V_8 )
{
int V_33 ;
struct V_34 * V_35 = F_16 ( V_8 -> V_6 ) ;
struct V_36 * V_37 = F_17 ( & V_35 -> V_6 ) ;
if ( V_37 && V_37 -> V_38 ) {
V_33 = V_37 -> V_38 ( V_35 , V_37 -> V_39 ) ;
if ( V_33 ) {
F_18 ( V_8 -> V_6 , L_4 , V_33 ) ;
return V_33 ;
}
}
F_19 ( V_8 -> V_6 ) ;
V_33 = F_10 ( V_8 ) ;
return V_33 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_34 * V_35 = F_16 ( V_8 -> V_6 ) ;
struct V_36 * V_37 = F_17 ( & V_35 -> V_6 ) ;
F_14 ( V_8 ) ;
F_21 ( V_8 -> V_6 ) ;
if ( V_37 && V_37 -> V_40 )
V_37 -> V_40 ( V_35 , V_37 -> V_39 ) ;
}
static inline int F_22 ( struct V_41 * V_42 )
{
if ( ! V_42 )
return - V_26 ;
return V_42 -> V_43 & V_44 ;
}
static T_1 F_23 ( struct V_41 * V_42 )
{
T_1 V_45 = V_42 -> V_43 & V_46 ;
T_1 V_47 = F_24 ( V_42 -> V_43 & V_45 ) ;
return V_42 -> V_43 & V_47 ;
}
static T_1 F_25 ( struct V_48 * V_49 )
{
T_1 V_50 ;
V_50 = V_49 -> V_51 << 5 ;
V_50 |= V_49 -> V_52 ;
V_50 |= V_49 -> V_53 >> 3 ;
V_50 <<= ( ( ( V_49 -> V_54 == V_55 ) ||
( V_49 -> V_54 == V_56 ) ) ? 0 : 6 ) ;
return V_50 ;
}
static T_1 F_26 ( struct V_7 * V_8 , T_1 * V_57 )
{
T_1 V_58 , V_59 ;
V_58 = F_5 ( V_8 , V_60 ) ;
V_58 &= V_61 ;
if ( ! V_58 ) {
* V_57 = 0 ;
return 0 ;
}
V_59 = F_5 ( V_8 , V_62 ) ;
* V_57 = V_59 ;
F_8 ( V_8 , V_58 , V_60 ) ;
return V_58 ;
}
static void F_27 ( struct V_7 * V_8 , struct V_63 * V_15 )
{
T_1 V_64 ;
V_64 = F_5 ( V_8 , V_65 ) ;
V_15 -> V_66 = F_28 ( V_64 ) ;
V_15 -> V_67 = F_29 ( V_64 ) ;
}
static void F_30 ( struct V_7 * V_8 , struct V_63 * V_15 )
{
T_1 V_64 ;
V_64 = ( V_15 -> V_66 << V_68 ) ;
V_64 |= ( V_15 -> V_67 << V_69 ) ;
F_8 ( V_8 , V_64 , V_65 ) ;
}
static void F_31 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
V_42 -> V_43 = F_5 ( V_8 , V_70 ) ;
V_42 -> V_71 = F_5 ( V_8 , V_72 ) ;
}
static void F_32 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
F_8 ( V_8 , V_42 -> V_43 | V_44 , V_73 ) ;
F_8 ( V_8 , V_42 -> V_71 , V_74 ) ;
F_8 ( V_8 , 1 , V_75 ) ;
F_8 ( V_8 , 1 , V_76 ) ;
}
static struct V_41 F_33 ( struct V_7 * V_8 , int V_77 )
{
struct V_41 V_42 ;
struct V_63 V_15 ;
F_27 ( V_8 , & V_15 ) ;
V_15 . V_67 = V_77 ;
F_30 ( V_8 , & V_15 ) ;
F_31 ( V_8 , & V_42 ) ;
return V_42 ;
}
static struct V_41 * F_34 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
struct V_41 * V_42 ;
if ( ! V_49 )
return NULL ;
if ( V_49 -> V_57 & ~ ( F_24 ( V_49 -> V_54 ) ) ) {
F_18 ( V_8 -> V_6 , L_5 , V_13 ,
V_49 -> V_57 ) ;
return F_35 ( - V_26 ) ;
}
V_42 = F_36 ( sizeof( * V_42 ) , V_78 ) ;
if ( ! V_42 )
return F_35 ( - V_79 ) ;
V_42 -> V_43 = ( V_49 -> V_57 & V_80 ) | V_49 -> V_81 | V_49 -> V_54 | V_49 -> V_82 ;
V_42 -> V_71 = V_49 -> V_23 | V_49 -> V_52 | V_49 -> V_53 | V_49 -> V_51 ;
return V_42 ;
}
static int F_37 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
int V_33 = 0 ;
struct V_63 V_15 ;
struct V_41 * V_42 ;
if ( ! V_8 || ! V_8 -> V_83 || ! V_49 )
return - V_26 ;
F_19 ( V_8 -> V_6 ) ;
F_27 ( V_8 , & V_15 ) ;
if ( V_15 . V_66 == V_8 -> V_83 ) {
F_38 ( V_8 -> V_6 , L_6 , V_13 ) ;
V_33 = - V_84 ;
goto V_85;
}
if ( ! V_49 -> V_81 ) {
int V_11 ;
struct V_41 V_86 ;
F_39 (obj, obj->nr_tlb_entries, i, tmp)
if ( ! F_22 ( & V_86 ) )
break;
if ( V_11 == V_8 -> V_83 ) {
F_6 ( V_8 -> V_6 , L_7 , V_13 ) ;
V_33 = - V_84 ;
goto V_85;
}
F_27 ( V_8 , & V_15 ) ;
} else {
V_15 . V_67 = V_15 . V_66 ;
F_30 ( V_8 , & V_15 ) ;
}
V_42 = F_34 ( V_8 , V_49 ) ;
if ( F_40 ( V_42 ) ) {
F_21 ( V_8 -> V_6 ) ;
return F_41 ( V_42 ) ;
}
F_32 ( V_8 , V_42 ) ;
F_42 ( V_42 ) ;
if ( V_49 -> V_81 )
V_15 . V_66 ++ ;
if ( ++ V_15 . V_67 == V_8 -> V_83 )
V_15 . V_67 = V_15 . V_66 ;
F_30 ( V_8 , & V_15 ) ;
V_85:
F_21 ( V_8 -> V_6 ) ;
return V_33 ;
}
static int F_37 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
return 0 ;
}
static int F_43 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
return F_37 ( V_8 , V_49 ) ;
}
static void F_44 ( struct V_7 * V_8 , T_1 V_57 )
{
int V_11 ;
struct V_41 V_42 ;
F_19 ( V_8 -> V_6 ) ;
F_39 (obj, obj->nr_tlb_entries, i, cr) {
T_1 V_87 ;
T_2 V_88 ;
if ( ! F_22 ( & V_42 ) )
continue;
V_87 = F_23 ( & V_42 ) ;
V_88 = F_45 ( V_42 . V_43 & 3 ) ;
if ( ( V_87 <= V_57 ) && ( V_57 < V_87 + V_88 ) ) {
F_6 ( V_8 -> V_6 , L_8 ,
V_13 , V_87 , V_57 , V_88 ) ;
F_32 ( V_8 , & V_42 ) ;
F_8 ( V_8 , 1 , V_75 ) ;
break;
}
}
F_21 ( V_8 -> V_6 ) ;
if ( V_11 == V_8 -> V_83 )
F_6 ( V_8 -> V_6 , L_9 , V_13 , V_57 ) ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_63 V_15 ;
F_19 ( V_8 -> V_6 ) ;
V_15 . V_66 = 0 ;
V_15 . V_67 = 0 ;
F_30 ( V_8 , & V_15 ) ;
F_8 ( V_8 , 1 , V_89 ) ;
F_21 ( V_8 -> V_6 ) ;
}
static T_3
F_47 ( struct V_7 * V_8 , char * V_90 , T_3 V_91 )
{
char * V_9 = V_90 ;
F_48 ( V_92 ) ;
F_48 ( V_93 ) ;
F_48 ( V_94 ) ;
F_48 ( V_95 ) ;
F_48 ( V_96 ) ;
F_48 ( V_97 ) ;
F_48 ( V_98 ) ;
F_48 ( V_99 ) ;
F_48 ( V_100 ) ;
F_48 ( V_101 ) ;
F_48 ( V_102 ) ;
F_48 ( V_103 ) ;
F_48 ( V_104 ) ;
F_48 ( V_105 ) ;
F_48 ( V_106 ) ;
F_48 ( V_107 ) ;
V_85:
return V_9 - V_90 ;
}
T_3 F_49 ( struct V_7 * V_8 , char * V_90 , T_3 V_88 )
{
if ( ! V_8 || ! V_90 )
return - V_26 ;
F_19 ( V_8 -> V_6 ) ;
V_88 = F_47 ( V_8 , V_90 , V_88 ) ;
F_21 ( V_8 -> V_6 ) ;
return V_88 ;
}
static int
F_50 ( struct V_7 * V_8 , struct V_41 * V_108 , int V_109 )
{
int V_11 ;
struct V_63 V_110 ;
struct V_41 V_86 ;
struct V_41 * V_9 = V_108 ;
F_19 ( V_8 -> V_6 ) ;
F_27 ( V_8 , & V_110 ) ;
F_39 (obj, num, i, tmp) {
if ( ! F_22 ( & V_86 ) )
continue;
* V_9 ++ = V_86 ;
}
F_30 ( V_8 , & V_110 ) ;
F_21 ( V_8 -> V_6 ) ;
return V_9 - V_108 ;
}
static T_3 F_51 ( struct V_7 * V_8 , struct V_41 * V_42 ,
char * V_90 )
{
char * V_9 = V_90 ;
V_9 += sprintf ( V_9 , L_10 , V_42 -> V_43 , V_42 -> V_71 ,
( V_42 -> V_43 & V_111 ) ? 1 : 0 ) ;
return V_9 - V_90 ;
}
T_2 F_52 ( struct V_7 * V_8 , char * V_90 , T_3 V_88 )
{
int V_11 , V_109 ;
struct V_41 * V_42 ;
char * V_9 = V_90 ;
V_109 = V_88 / sizeof( * V_42 ) ;
V_109 = F_53 ( V_8 -> V_83 , V_109 ) ;
V_42 = F_54 ( V_109 , sizeof( * V_42 ) , V_78 ) ;
if ( ! V_42 )
return 0 ;
V_109 = F_50 ( V_8 , V_42 , V_109 ) ;
for ( V_11 = 0 ; V_11 < V_109 ; V_11 ++ )
V_9 += F_51 ( V_8 , V_42 + V_11 , V_9 ) ;
F_42 ( V_42 ) ;
return V_9 - V_90 ;
}
static void F_55 ( T_1 * V_112 , T_1 * V_113 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pgd"
: : "r" (first));
V_112 += V_114 / sizeof( * V_112 ) ;
} while ( V_112 <= V_113 );
}
static void F_56 ( T_1 * V_112 , T_1 * V_113 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pte"
: : "r" (first));
V_112 += V_114 / sizeof( * V_112 ) ;
} while ( V_112 <= V_113 );
}
static void F_57 ( T_1 * V_115 )
{
if ( V_115 )
F_58 ( V_116 , V_115 ) ;
}
static T_1 * F_59 ( struct V_7 * V_8 , T_1 * V_24 , T_1 V_57 )
{
T_1 * V_115 ;
if ( * V_24 )
goto V_117;
F_60 ( & V_8 -> V_118 ) ;
V_115 = F_61 ( V_116 , V_78 ) ;
F_62 ( & V_8 -> V_118 ) ;
if ( ! * V_24 ) {
if ( ! V_115 )
return F_35 ( - V_79 ) ;
* V_24 = F_12 ( V_115 ) | V_119 ;
F_55 ( V_24 , V_24 ) ;
F_63 ( V_8 -> V_6 , L_11 , V_13 , V_115 ) ;
} else {
F_57 ( V_115 ) ;
}
V_117:
V_115 = F_64 ( V_24 , V_57 ) ;
F_63 ( V_8 -> V_6 ,
L_12 ,
V_13 , V_57 , V_24 , * V_24 , V_115 , * V_115 ) ;
return V_115 ;
}
static int F_65 ( struct V_7 * V_8 , T_1 V_57 , T_1 V_23 , T_1 V_120 )
{
T_1 * V_24 = F_66 ( V_8 , V_57 ) ;
if ( ( V_57 | V_23 ) & ~ V_121 ) {
F_18 ( V_8 -> V_6 , L_13 ,
V_13 , V_57 , V_23 , V_122 ) ;
return - V_26 ;
}
* V_24 = ( V_23 & V_121 ) | V_120 | V_123 ;
F_55 ( V_24 , V_24 ) ;
return 0 ;
}
static int F_67 ( struct V_7 * V_8 , T_1 V_57 , T_1 V_23 , T_1 V_120 )
{
T_1 * V_24 = F_66 ( V_8 , V_57 ) ;
int V_11 ;
if ( ( V_57 | V_23 ) & ~ V_124 ) {
F_18 ( V_8 -> V_6 , L_13 ,
V_13 , V_57 , V_23 , V_125 ) ;
return - V_26 ;
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
* ( V_24 + V_11 ) = ( V_23 & V_124 ) | V_120 | V_126 ;
F_55 ( V_24 , V_24 + 15 ) ;
return 0 ;
}
static int F_68 ( struct V_7 * V_8 , T_1 V_57 , T_1 V_23 , T_1 V_120 )
{
T_1 * V_24 = F_66 ( V_8 , V_57 ) ;
T_1 * V_115 = F_59 ( V_8 , V_24 , V_57 ) ;
if ( F_40 ( V_115 ) )
return F_41 ( V_115 ) ;
* V_115 = ( V_23 & V_127 ) | V_120 | V_128 ;
F_56 ( V_115 , V_115 ) ;
F_63 ( V_8 -> V_6 , L_14 ,
V_13 , V_57 , V_23 , V_115 , * V_115 ) ;
return 0 ;
}
static int F_69 ( struct V_7 * V_8 , T_1 V_57 , T_1 V_23 , T_1 V_120 )
{
T_1 * V_24 = F_66 ( V_8 , V_57 ) ;
T_1 * V_115 = F_59 ( V_8 , V_24 , V_57 ) ;
int V_11 ;
if ( ( V_57 | V_23 ) & ~ V_129 ) {
F_18 ( V_8 -> V_6 , L_13 ,
V_13 , V_57 , V_23 , V_130 ) ;
return - V_26 ;
}
if ( F_40 ( V_115 ) )
return F_41 ( V_115 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
* ( V_115 + V_11 ) = ( V_23 & V_129 ) | V_120 | V_131 ;
F_56 ( V_115 , V_115 + 15 ) ;
return 0 ;
}
static int
F_70 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
int (* F_71)( struct V_7 * , T_1 , T_1 , T_1 );
T_1 V_120 ;
int V_33 ;
if ( ! V_8 || ! V_49 )
return - V_26 ;
switch ( V_49 -> V_54 ) {
case V_132 :
F_71 = F_67 ;
break;
case V_133 :
F_71 = F_65 ;
break;
case V_56 :
F_71 = F_69 ;
break;
case V_55 :
F_71 = F_68 ;
break;
default:
F_71 = NULL ;
F_72 () ;
break;
}
V_120 = F_25 ( V_49 ) ;
F_62 ( & V_8 -> V_118 ) ;
V_33 = F_71 ( V_8 , V_49 -> V_57 , V_49 -> V_23 , V_120 ) ;
F_60 ( & V_8 -> V_118 ) ;
return V_33 ;
}
static int
F_73 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
int V_33 ;
F_44 ( V_8 , V_49 -> V_57 ) ;
V_33 = F_70 ( V_8 , V_49 ) ;
if ( ! V_33 )
F_43 ( V_8 , V_49 ) ;
return V_33 ;
}
static void
F_74 ( struct V_7 * V_8 , T_1 V_57 , T_1 * * V_134 , T_1 * * V_135 )
{
T_1 * V_24 , * V_115 = NULL ;
V_24 = F_66 ( V_8 , V_57 ) ;
if ( ! * V_24 )
goto V_85;
if ( F_75 ( * V_24 ) )
V_115 = F_64 ( V_24 , V_57 ) ;
V_85:
* V_134 = V_24 ;
* V_135 = V_115 ;
}
static T_2 F_76 ( struct V_7 * V_8 , T_1 V_57 )
{
T_2 V_88 ;
T_1 * V_24 = F_66 ( V_8 , V_57 ) ;
int V_136 = 1 ;
if ( ! * V_24 )
return 0 ;
if ( F_75 ( * V_24 ) ) {
int V_11 ;
T_1 * V_115 = F_64 ( V_24 , V_57 ) ;
V_88 = V_137 ;
if ( * V_115 & V_131 ) {
V_136 *= 16 ;
V_115 = F_64 ( V_24 , ( V_57 & V_129 ) ) ;
}
V_88 *= V_136 ;
memset ( V_115 , 0 , V_136 * sizeof( * V_115 ) ) ;
F_56 ( V_115 , V_115 + ( V_136 - 1 ) * sizeof( * V_115 ) ) ;
V_115 = F_64 ( V_24 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_138 ; V_11 ++ )
if ( V_115 [ V_11 ] )
goto V_85;
F_57 ( V_115 ) ;
V_136 = 1 ;
} else {
V_88 = V_139 ;
if ( ( * V_24 & V_126 ) == V_126 ) {
V_136 *= 16 ;
V_24 = F_66 ( V_8 , ( V_57 & V_124 ) ) ;
}
V_88 *= V_136 ;
}
memset ( V_24 , 0 , V_136 * sizeof( * V_24 ) ) ;
F_55 ( V_24 , V_24 + ( V_136 - 1 ) * sizeof( * V_24 ) ) ;
V_85:
return V_88 ;
}
static T_2 F_77 ( struct V_7 * V_8 , T_1 V_57 )
{
T_2 V_88 ;
F_62 ( & V_8 -> V_118 ) ;
V_88 = F_76 ( V_8 , V_57 ) ;
F_44 ( V_8 , V_57 ) ;
F_60 ( & V_8 -> V_118 ) ;
return V_88 ;
}
static void F_78 ( struct V_7 * V_8 )
{
int V_11 ;
F_62 ( & V_8 -> V_118 ) ;
for ( V_11 = 0 ; V_11 < V_140 ; V_11 ++ ) {
T_1 V_57 ;
T_1 * V_24 ;
V_57 = V_11 << V_141 ;
V_24 = F_66 ( V_8 , V_57 ) ;
if ( ! * V_24 )
continue;
if ( F_75 ( * V_24 ) )
F_57 ( F_64 ( V_24 , 0 ) ) ;
* V_24 = 0 ;
F_55 ( V_24 , V_24 ) ;
}
F_46 ( V_8 ) ;
F_60 ( & V_8 -> V_118 ) ;
}
static T_4 F_79 ( int V_142 , void * V_143 )
{
T_1 V_57 , V_144 ;
T_1 * V_24 , * V_115 ;
struct V_7 * V_8 = V_143 ;
struct V_2 * V_4 = V_8 -> V_4 ;
struct V_1 * V_145 = F_1 ( V_4 ) ;
if ( ! V_145 -> V_146 )
return V_147 ;
V_144 = F_26 ( V_8 , & V_57 ) ;
if ( V_144 == 0 )
return V_148 ;
if ( ! F_80 ( V_4 , V_8 -> V_6 , V_57 , 0 ) )
return V_148 ;
F_20 ( V_8 ) ;
V_24 = F_66 ( V_8 , V_57 ) ;
if ( ! F_75 ( * V_24 ) ) {
F_18 ( V_8 -> V_6 , L_15 ,
V_8 -> V_28 , V_144 , V_57 , V_24 , * V_24 ) ;
return V_147 ;
}
V_115 = F_64 ( V_24 , V_57 ) ;
F_18 ( V_8 -> V_6 , L_16 ,
V_8 -> V_28 , V_144 , V_57 , V_24 , * V_24 , V_115 , * V_115 ) ;
return V_147 ;
}
static int F_81 ( struct V_5 * V_6 , void * V_143 )
{
struct V_7 * V_8 = F_82 ( V_6 ) ;
const char * V_28 = V_143 ;
F_83 ( L_17 , V_13 , V_8 -> V_28 , V_28 ) ;
return strcmp ( V_8 -> V_28 , V_28 ) == 0 ;
}
static struct V_7 * F_84 ( const char * V_28 , T_1 * V_24 )
{
int V_33 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_85 ( & V_149 . V_150 , NULL ,
( void * ) V_28 ,
F_81 ) ;
if ( ! V_6 )
return F_35 ( - V_151 ) ;
V_8 = F_82 ( V_6 ) ;
F_62 ( & V_8 -> V_152 ) ;
V_8 -> V_24 = V_24 ;
V_33 = F_15 ( V_8 ) ;
if ( V_33 )
goto V_153;
F_46 ( V_8 ) ;
F_60 ( & V_8 -> V_152 ) ;
F_6 ( V_8 -> V_6 , L_18 , V_13 , V_8 -> V_28 ) ;
return V_8 ;
V_153:
F_60 ( & V_8 -> V_152 ) ;
return F_35 ( V_33 ) ;
}
static void F_86 ( struct V_7 * V_8 )
{
if ( ! V_8 || F_40 ( V_8 ) )
return;
F_62 ( & V_8 -> V_152 ) ;
F_20 ( V_8 ) ;
V_8 -> V_24 = NULL ;
F_60 ( & V_8 -> V_152 ) ;
F_6 ( V_8 -> V_6 , L_18 , V_13 , V_8 -> V_28 ) ;
}
static int F_87 ( struct V_34 * V_35 )
{
int V_33 = - V_151 ;
int V_142 ;
struct V_7 * V_8 ;
struct V_154 * V_155 ;
struct V_36 * V_37 = F_17 ( & V_35 -> V_6 ) ;
struct V_156 * V_157 = V_35 -> V_6 . V_158 ;
V_8 = F_88 ( & V_35 -> V_6 , sizeof( * V_8 ) + V_12 , V_78 ) ;
if ( ! V_8 )
return - V_79 ;
if ( V_157 ) {
V_8 -> V_28 = F_89 ( & V_35 -> V_6 ) ;
V_8 -> V_83 = 32 ;
V_33 = F_90 ( V_157 , L_19 ,
& V_8 -> V_83 ) ;
if ( V_33 && V_33 != - V_26 )
return V_33 ;
if ( V_8 -> V_83 != 32 && V_8 -> V_83 != 8 )
return - V_26 ;
if ( F_91 ( V_157 , L_20 , NULL ) )
V_8 -> V_30 = V_31 ;
} else {
V_8 -> V_83 = V_37 -> V_83 ;
V_8 -> V_28 = V_37 -> V_28 ;
}
V_8 -> V_6 = & V_35 -> V_6 ;
V_8 -> V_10 = ( void * ) V_8 + sizeof( * V_8 ) ;
F_92 ( & V_8 -> V_152 ) ;
F_92 ( & V_8 -> V_118 ) ;
V_155 = F_93 ( V_35 , V_159 , 0 ) ;
V_8 -> V_160 = F_94 ( V_8 -> V_6 , V_155 ) ;
if ( F_40 ( V_8 -> V_160 ) )
return F_41 ( V_8 -> V_160 ) ;
V_142 = F_95 ( V_35 , 0 ) ;
if ( V_142 < 0 )
return - V_151 ;
V_33 = F_96 ( V_8 -> V_6 , V_142 , F_79 , V_161 ,
F_89 ( V_8 -> V_6 ) , V_8 ) ;
if ( V_33 < 0 )
return V_33 ;
F_97 ( V_35 , V_8 ) ;
F_98 ( V_8 -> V_6 ) ;
F_99 ( V_8 -> V_6 ) ;
F_100 ( V_8 ) ;
F_13 ( & V_35 -> V_6 , L_21 , V_8 -> V_28 ) ;
return 0 ;
}
static int F_101 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = F_102 ( V_35 ) ;
F_78 ( V_8 ) ;
F_103 ( V_8 ) ;
F_104 ( V_8 -> V_6 ) ;
F_13 ( & V_35 -> V_6 , L_22 , V_8 -> V_28 ) ;
return 0 ;
}
static void F_105 ( void * V_115 )
{
F_106 ( V_115 , V_162 ) ;
}
static T_1 F_107 ( struct V_48 * V_49 , T_1 V_57 , T_1 V_23 , int V_54 )
{
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_57 = V_57 ;
V_49 -> V_23 = V_23 ;
V_49 -> V_82 = V_44 ;
V_49 -> V_54 = V_54 ;
V_49 -> V_52 = V_163 ;
V_49 -> V_53 = V_164 ;
V_49 -> V_51 = 0 ;
return F_45 ( V_49 -> V_54 ) ;
}
static int F_108 ( struct V_2 * V_4 , unsigned long V_57 ,
T_5 V_23 , T_2 V_88 , int V_120 )
{
struct V_1 * V_145 = F_1 ( V_4 ) ;
struct V_7 * V_165 = V_145 -> V_146 ;
struct V_5 * V_6 = V_165 -> V_6 ;
struct V_48 V_49 ;
int V_166 ;
T_1 V_167 ;
V_166 = F_109 ( V_88 ) ;
if ( V_166 < 0 ) {
F_18 ( V_6 , L_23 , V_88 ) ;
return - V_26 ;
}
F_6 ( V_6 , L_24 , V_57 , & V_23 , V_88 ) ;
F_107 ( & V_49 , V_57 , V_23 , V_166 ) ;
V_167 = F_73 ( V_165 , & V_49 ) ;
if ( V_167 )
F_18 ( V_6 , L_25 , V_167 ) ;
return V_167 ;
}
static T_2 F_110 ( struct V_2 * V_4 , unsigned long V_57 ,
T_2 V_168 )
{
struct V_1 * V_145 = F_1 ( V_4 ) ;
struct V_7 * V_165 = V_145 -> V_146 ;
struct V_5 * V_6 = V_165 -> V_6 ;
F_6 ( V_6 , L_26 , V_57 , V_168 ) ;
return F_77 ( V_165 , V_57 ) ;
}
static int
F_111 ( struct V_2 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_145 = F_1 ( V_4 ) ;
struct V_7 * V_165 ;
struct V_169 * V_170 = V_6 -> V_171 . V_172 ;
int V_167 = 0 ;
if ( ! V_170 || ! V_170 -> V_28 ) {
F_18 ( V_6 , L_27 ) ;
return - V_26 ;
}
F_62 ( & V_145 -> V_173 ) ;
if ( V_145 -> V_146 ) {
F_18 ( V_6 , L_28 ) ;
V_167 = - V_84 ;
goto V_85;
}
V_165 = F_84 ( V_170 -> V_28 , V_145 -> V_174 ) ;
if ( F_40 ( V_165 ) ) {
V_167 = F_41 ( V_165 ) ;
F_18 ( V_6 , L_29 , V_167 ) ;
goto V_85;
}
V_145 -> V_146 = V_170 -> V_146 = V_165 ;
V_145 -> V_6 = V_6 ;
V_165 -> V_4 = V_4 ;
V_85:
F_60 ( & V_145 -> V_173 ) ;
return V_167 ;
}
static void F_112 ( struct V_1 * V_145 ,
struct V_5 * V_6 )
{
struct V_7 * V_165 = F_4 ( V_6 ) ;
struct V_169 * V_170 = V_6 -> V_171 . V_172 ;
if ( V_145 -> V_146 != V_165 ) {
F_18 ( V_6 , L_30 ) ;
return;
}
F_78 ( V_165 ) ;
F_86 ( V_165 ) ;
V_145 -> V_146 = V_170 -> V_146 = NULL ;
V_145 -> V_6 = NULL ;
V_165 -> V_4 = NULL ;
}
static void F_113 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_145 = F_1 ( V_4 ) ;
F_62 ( & V_145 -> V_173 ) ;
F_112 ( V_145 , V_6 ) ;
F_60 ( & V_145 -> V_173 ) ;
}
static struct V_2 * F_114 ( unsigned type )
{
struct V_1 * V_145 ;
if ( type != V_175 )
return NULL ;
V_145 = F_115 ( sizeof( * V_145 ) , V_78 ) ;
if ( ! V_145 ) {
F_116 ( L_31 ) ;
goto V_85;
}
V_145 -> V_174 = F_115 ( V_176 , V_78 ) ;
if ( ! V_145 -> V_174 ) {
F_116 ( L_31 ) ;
goto V_177;
}
F_117 ( ! F_11 ( ( long ) V_145 -> V_174 , V_176 ) ) ;
F_106 ( V_145 -> V_174 , V_176 ) ;
F_92 ( & V_145 -> V_173 ) ;
V_145 -> V_4 . V_178 . V_179 = 0 ;
V_145 -> V_4 . V_178 . V_180 = ( 1ULL << 32 ) - 1 ;
V_145 -> V_4 . V_178 . V_181 = true ;
return & V_145 -> V_4 ;
V_177:
F_42 ( V_145 ) ;
V_85:
return NULL ;
}
static void F_118 ( struct V_2 * V_4 )
{
struct V_1 * V_145 = F_1 ( V_4 ) ;
if ( V_145 -> V_146 )
F_112 ( V_145 , V_145 -> V_6 ) ;
F_42 ( V_145 -> V_174 ) ;
F_42 ( V_145 ) ;
}
static T_5 F_119 ( struct V_2 * V_4 ,
T_6 V_57 )
{
struct V_1 * V_145 = F_1 ( V_4 ) ;
struct V_7 * V_165 = V_145 -> V_146 ;
struct V_5 * V_6 = V_165 -> V_6 ;
T_1 * V_182 , * V_183 ;
T_5 V_167 = 0 ;
F_74 ( V_165 , V_57 , & V_182 , & V_183 ) ;
if ( V_183 ) {
if ( F_120 ( * V_183 ) )
V_167 = F_121 ( * V_183 , V_57 , V_184 ) ;
else if ( F_122 ( * V_183 ) )
V_167 = F_121 ( * V_183 , V_57 , V_129 ) ;
else
F_18 ( V_6 , L_32 , * V_183 ,
( unsigned long long ) V_57 ) ;
} else {
if ( F_123 ( * V_182 ) )
V_167 = F_121 ( * V_182 , V_57 , V_121 ) ;
else if ( F_124 ( * V_182 ) )
V_167 = F_121 ( * V_182 , V_57 , V_124 ) ;
else
F_18 ( V_6 , L_33 , * V_182 ,
( unsigned long long ) V_57 ) ;
}
return V_167 ;
}
static int F_125 ( struct V_5 * V_6 )
{
struct V_169 * V_170 ;
struct V_156 * V_185 ;
struct V_34 * V_35 ;
if ( ! V_6 -> V_158 )
return 0 ;
V_185 = F_126 ( V_6 -> V_158 , L_34 , 0 ) ;
if ( ! V_185 )
return 0 ;
V_35 = F_127 ( V_185 ) ;
if ( F_128 ( ! V_35 ) ) {
F_129 ( V_185 ) ;
return - V_26 ;
}
V_170 = F_115 ( sizeof( * V_170 ) , V_78 ) ;
if ( ! V_170 ) {
F_129 ( V_185 ) ;
return - V_79 ;
}
V_170 -> V_28 = F_130 ( F_89 ( & V_35 -> V_6 ) , V_78 ) ;
V_6 -> V_171 . V_172 = V_170 ;
F_129 ( V_185 ) ;
return 0 ;
}
static void F_131 ( struct V_5 * V_6 )
{
struct V_169 * V_170 = V_6 -> V_171 . V_172 ;
if ( ! V_6 -> V_158 || ! V_170 )
return;
F_42 ( V_170 -> V_28 ) ;
F_42 ( V_170 ) ;
}
static int T_7 F_132 ( void )
{
struct V_186 * V_9 ;
const unsigned long V_187 = V_188 ;
T_2 V_189 = 1 << 10 ;
struct V_156 * V_185 ;
V_185 = F_133 ( NULL , V_190 ) ;
if ( ! V_185 )
return 0 ;
F_129 ( V_185 ) ;
V_9 = F_134 ( L_35 , V_162 , V_189 , V_187 ,
F_105 ) ;
if ( ! V_9 )
return - V_79 ;
V_116 = V_9 ;
F_135 ( & V_191 , & V_192 ) ;
F_136 () ;
return F_137 ( & V_149 ) ;
}
static void T_8 F_138 ( void )
{
F_139 ( V_116 ) ;
F_140 ( & V_149 ) ;
F_141 () ;
}
