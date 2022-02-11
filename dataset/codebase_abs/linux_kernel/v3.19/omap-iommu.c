void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * V_5 = V_4 -> V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < ( V_8 / sizeof( T_1 ) ) ; V_7 ++ ) {
V_5 [ V_7 ] = F_3 ( V_4 , V_7 * sizeof( T_1 ) ) ;
F_4 ( V_4 -> V_2 , L_1 , V_9 , V_7 , V_5 [ V_7 ] ) ;
}
}
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 * V_5 = V_4 -> V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < ( V_8 / sizeof( T_1 ) ) ; V_7 ++ ) {
F_6 ( V_4 , V_5 [ V_7 ] , V_7 * sizeof( T_1 ) ) ;
F_4 ( V_4 -> V_2 , L_1 , V_9 , V_7 , V_5 [ V_7 ] ) ;
}
}
static void F_7 ( struct V_3 * V_4 , bool V_10 )
{
T_1 V_11 = F_3 ( V_4 , V_12 ) ;
if ( V_10 )
F_6 ( V_4 , V_13 , V_14 ) ;
else
F_6 ( V_4 , V_15 , V_14 ) ;
V_11 &= ~ V_16 ;
if ( V_10 )
V_11 |= ( V_17 | V_18 ) ;
else
V_11 |= ( V_17 ) ;
F_6 ( V_4 , V_11 , V_12 ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
T_1 V_11 , V_19 ;
if ( ! V_4 -> V_20 || ! F_9 ( ( T_1 ) V_4 -> V_20 , V_21 ) )
return - V_22 ;
V_19 = F_10 ( V_4 -> V_20 ) ;
if ( ! F_9 ( V_19 , V_21 ) )
return - V_22 ;
V_11 = F_3 ( V_4 , V_23 ) ;
F_11 ( V_4 -> V_2 , L_2 , V_4 -> V_24 ,
( V_11 >> 4 ) & 0xf , V_11 & 0xf ) ;
F_6 ( V_4 , V_19 , V_25 ) ;
if ( V_4 -> V_26 )
F_6 ( V_4 , V_27 , V_28 ) ;
F_7 ( V_4 , true ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
T_1 V_11 = F_3 ( V_4 , V_12 ) ;
V_11 &= ~ V_16 ;
F_6 ( V_4 , V_11 , V_12 ) ;
F_4 ( V_4 -> V_2 , L_3 , V_4 -> V_24 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
int V_29 ;
struct V_30 * V_31 = F_14 ( V_4 -> V_2 ) ;
struct V_32 * V_33 = F_15 ( & V_31 -> V_2 ) ;
if ( V_33 && V_33 -> V_34 ) {
V_29 = V_33 -> V_34 ( V_31 , V_33 -> V_35 ) ;
if ( V_29 ) {
F_16 ( V_4 -> V_2 , L_4 , V_29 ) ;
return V_29 ;
}
}
F_17 ( V_4 -> V_2 ) ;
V_29 = F_8 ( V_4 ) ;
return V_29 ;
}
static void F_18 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = F_14 ( V_4 -> V_2 ) ;
struct V_32 * V_33 = F_15 ( & V_31 -> V_2 ) ;
F_12 ( V_4 ) ;
F_19 ( V_4 -> V_2 ) ;
if ( V_33 && V_33 -> V_36 )
V_33 -> V_36 ( V_31 , V_33 -> V_35 ) ;
}
static inline int F_20 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return - V_22 ;
return V_38 -> V_39 & V_40 ;
}
static T_1 F_21 ( struct V_37 * V_38 )
{
T_1 V_41 = V_38 -> V_39 & V_42 ;
T_1 V_43 = F_22 ( V_38 -> V_39 & V_41 ) ;
return V_38 -> V_39 & V_43 ;
}
static T_1 F_23 ( struct V_44 * V_45 )
{
T_1 V_46 ;
V_46 = V_45 -> V_47 << 5 ;
V_46 |= V_45 -> V_48 ;
V_46 |= V_45 -> V_49 >> 3 ;
V_46 <<= ( ( ( V_45 -> V_50 == V_51 ) ||
( V_45 -> V_50 == V_52 ) ) ? 0 : 6 ) ;
return V_46 ;
}
static T_1 F_24 ( struct V_3 * V_4 , T_1 * V_53 )
{
T_1 V_54 , V_55 ;
V_54 = F_3 ( V_4 , V_56 ) ;
V_54 &= V_57 ;
if ( ! V_54 ) {
* V_53 = 0 ;
return 0 ;
}
V_55 = F_3 ( V_4 , V_58 ) ;
* V_53 = V_55 ;
F_6 ( V_4 , V_54 , V_56 ) ;
return V_54 ;
}
static void F_25 ( struct V_3 * V_4 , struct V_59 * V_11 )
{
T_1 V_60 ;
V_60 = F_3 ( V_4 , V_61 ) ;
V_11 -> V_62 = F_26 ( V_60 ) ;
V_11 -> V_63 = F_27 ( V_60 ) ;
}
static void F_28 ( struct V_3 * V_4 , struct V_59 * V_11 )
{
T_1 V_60 ;
V_60 = ( V_11 -> V_62 << V_64 ) ;
V_60 |= ( V_11 -> V_63 << V_65 ) ;
F_6 ( V_4 , V_60 , V_61 ) ;
}
static void F_29 ( struct V_3 * V_4 , struct V_37 * V_38 )
{
V_38 -> V_39 = F_3 ( V_4 , V_66 ) ;
V_38 -> V_67 = F_3 ( V_4 , V_68 ) ;
}
static void F_30 ( struct V_3 * V_4 , struct V_37 * V_38 )
{
F_6 ( V_4 , V_38 -> V_39 | V_40 , V_69 ) ;
F_6 ( V_4 , V_38 -> V_67 , V_70 ) ;
F_6 ( V_4 , 1 , V_71 ) ;
F_6 ( V_4 , 1 , V_72 ) ;
}
static struct V_37 F_31 ( struct V_3 * V_4 , int V_73 )
{
struct V_37 V_38 ;
struct V_59 V_11 ;
F_25 ( V_4 , & V_11 ) ;
V_11 . V_63 = V_73 ;
F_28 ( V_4 , & V_11 ) ;
F_29 ( V_4 , & V_38 ) ;
return V_38 ;
}
static struct V_37 * F_32 ( struct V_3 * V_4 ,
struct V_44 * V_45 )
{
struct V_37 * V_38 ;
if ( ! V_45 )
return NULL ;
if ( V_45 -> V_53 & ~ ( F_22 ( V_45 -> V_50 ) ) ) {
F_16 ( V_4 -> V_2 , L_5 , V_9 ,
V_45 -> V_53 ) ;
return F_33 ( - V_22 ) ;
}
V_38 = F_34 ( sizeof( * V_38 ) , V_74 ) ;
if ( ! V_38 )
return F_33 ( - V_75 ) ;
V_38 -> V_39 = ( V_45 -> V_53 & V_76 ) | V_45 -> V_77 | V_45 -> V_50 | V_45 -> V_78 ;
V_38 -> V_67 = V_45 -> V_19 | V_45 -> V_48 | V_45 -> V_49 | V_45 -> V_47 ;
return V_38 ;
}
static int F_35 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
int V_29 = 0 ;
struct V_59 V_11 ;
struct V_37 * V_38 ;
if ( ! V_4 || ! V_4 -> V_79 || ! V_45 )
return - V_22 ;
F_17 ( V_4 -> V_2 ) ;
F_25 ( V_4 , & V_11 ) ;
if ( V_11 . V_62 == V_4 -> V_79 ) {
F_36 ( V_4 -> V_2 , L_6 , V_9 ) ;
V_29 = - V_80 ;
goto V_81;
}
if ( ! V_45 -> V_77 ) {
int V_7 ;
struct V_37 V_82 ;
F_37 (obj, obj->nr_tlb_entries, i, tmp)
if ( ! F_20 ( & V_82 ) )
break;
if ( V_7 == V_4 -> V_79 ) {
F_4 ( V_4 -> V_2 , L_7 , V_9 ) ;
V_29 = - V_80 ;
goto V_81;
}
F_25 ( V_4 , & V_11 ) ;
} else {
V_11 . V_63 = V_11 . V_62 ;
F_28 ( V_4 , & V_11 ) ;
}
V_38 = F_32 ( V_4 , V_45 ) ;
if ( F_38 ( V_38 ) ) {
F_19 ( V_4 -> V_2 ) ;
return F_39 ( V_38 ) ;
}
F_30 ( V_4 , V_38 ) ;
F_40 ( V_38 ) ;
if ( V_45 -> V_77 )
V_11 . V_62 ++ ;
if ( ++ V_11 . V_63 == V_4 -> V_79 )
V_11 . V_63 = V_11 . V_62 ;
F_28 ( V_4 , & V_11 ) ;
V_81:
F_19 ( V_4 -> V_2 ) ;
return V_29 ;
}
static int F_35 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
return F_35 ( V_4 , V_45 ) ;
}
static void F_42 ( struct V_3 * V_4 , T_1 V_53 )
{
int V_7 ;
struct V_37 V_38 ;
F_17 ( V_4 -> V_2 ) ;
F_37 (obj, obj->nr_tlb_entries, i, cr) {
T_1 V_83 ;
T_2 V_84 ;
if ( ! F_20 ( & V_38 ) )
continue;
V_83 = F_21 ( & V_38 ) ;
V_84 = F_43 ( V_38 . V_39 & 3 ) ;
if ( ( V_83 <= V_53 ) && ( V_53 < V_83 + V_84 ) ) {
F_4 ( V_4 -> V_2 , L_8 ,
V_9 , V_83 , V_53 , V_84 ) ;
F_30 ( V_4 , & V_38 ) ;
F_6 ( V_4 , 1 , V_71 ) ;
break;
}
}
F_19 ( V_4 -> V_2 ) ;
if ( V_7 == V_4 -> V_79 )
F_4 ( V_4 -> V_2 , L_9 , V_9 , V_53 ) ;
}
static void F_44 ( struct V_3 * V_4 )
{
struct V_59 V_11 ;
F_17 ( V_4 -> V_2 ) ;
V_11 . V_62 = 0 ;
V_11 . V_63 = 0 ;
F_28 ( V_4 , & V_11 ) ;
F_6 ( V_4 , 1 , V_85 ) ;
F_19 ( V_4 -> V_2 ) ;
}
static T_3
F_45 ( struct V_3 * V_4 , char * V_86 , T_3 V_87 )
{
char * V_5 = V_86 ;
F_46 ( V_88 ) ;
F_46 ( V_89 ) ;
F_46 ( V_90 ) ;
F_46 ( V_91 ) ;
F_46 ( V_92 ) ;
F_46 ( V_93 ) ;
F_46 ( V_94 ) ;
F_46 ( V_95 ) ;
F_46 ( V_96 ) ;
F_46 ( V_97 ) ;
F_46 ( V_98 ) ;
F_46 ( V_99 ) ;
F_46 ( V_100 ) ;
F_46 ( V_101 ) ;
F_46 ( V_102 ) ;
F_46 ( V_103 ) ;
V_81:
return V_5 - V_86 ;
}
T_3 F_47 ( struct V_3 * V_4 , char * V_86 , T_3 V_84 )
{
if ( ! V_4 || ! V_86 )
return - V_22 ;
F_17 ( V_4 -> V_2 ) ;
V_84 = F_45 ( V_4 , V_86 , V_84 ) ;
F_19 ( V_4 -> V_2 ) ;
return V_84 ;
}
static int
F_48 ( struct V_3 * V_4 , struct V_37 * V_104 , int V_105 )
{
int V_7 ;
struct V_59 V_106 ;
struct V_37 V_82 ;
struct V_37 * V_5 = V_104 ;
F_17 ( V_4 -> V_2 ) ;
F_25 ( V_4 , & V_106 ) ;
F_37 (obj, num, i, tmp) {
if ( ! F_20 ( & V_82 ) )
continue;
* V_5 ++ = V_82 ;
}
F_28 ( V_4 , & V_106 ) ;
F_19 ( V_4 -> V_2 ) ;
return V_5 - V_104 ;
}
static T_3 F_49 ( struct V_3 * V_4 , struct V_37 * V_38 ,
char * V_86 )
{
char * V_5 = V_86 ;
V_5 += sprintf ( V_5 , L_10 , V_38 -> V_39 , V_38 -> V_67 ,
( V_38 -> V_39 & V_107 ) ? 1 : 0 ) ;
return V_5 - V_86 ;
}
T_2 F_50 ( struct V_3 * V_4 , char * V_86 , T_3 V_84 )
{
int V_7 , V_105 ;
struct V_37 * V_38 ;
char * V_5 = V_86 ;
V_105 = V_84 / sizeof( * V_38 ) ;
V_105 = F_51 ( V_4 -> V_79 , V_105 ) ;
V_38 = F_52 ( V_105 , sizeof( * V_38 ) , V_74 ) ;
if ( ! V_38 )
return 0 ;
V_105 = F_48 ( V_4 , V_38 , V_105 ) ;
for ( V_7 = 0 ; V_7 < V_105 ; V_7 ++ )
V_5 += F_49 ( V_4 , V_38 + V_7 , V_5 ) ;
F_40 ( V_38 ) ;
return V_5 - V_86 ;
}
static void F_53 ( T_1 * V_108 , T_1 * V_109 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pgd"
: : "r" (first));
V_108 += V_110 / sizeof( * V_108 ) ;
} while ( V_108 <= V_109 );
}
static void F_54 ( T_1 * V_108 , T_1 * V_109 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pte"
: : "r" (first));
V_108 += V_110 / sizeof( * V_108 ) ;
} while ( V_108 <= V_109 );
}
static void F_55 ( T_1 * V_111 )
{
if ( V_111 )
F_56 ( V_112 , V_111 ) ;
}
static T_1 * F_57 ( struct V_3 * V_4 , T_1 * V_20 , T_1 V_53 )
{
T_1 * V_111 ;
if ( * V_20 )
goto V_113;
F_58 ( & V_4 -> V_114 ) ;
V_111 = F_59 ( V_112 , V_74 ) ;
F_60 ( & V_4 -> V_114 ) ;
if ( ! * V_20 ) {
if ( ! V_111 )
return F_33 ( - V_75 ) ;
* V_20 = F_10 ( V_111 ) | V_115 ;
F_53 ( V_20 , V_20 ) ;
F_61 ( V_4 -> V_2 , L_11 , V_9 , V_111 ) ;
} else {
F_55 ( V_111 ) ;
}
V_113:
V_111 = F_62 ( V_20 , V_53 ) ;
F_61 ( V_4 -> V_2 ,
L_12 ,
V_9 , V_53 , V_20 , * V_20 , V_111 , * V_111 ) ;
return V_111 ;
}
static int F_63 ( struct V_3 * V_4 , T_1 V_53 , T_1 V_19 , T_1 V_116 )
{
T_1 * V_20 = F_64 ( V_4 , V_53 ) ;
if ( ( V_53 | V_19 ) & ~ V_117 ) {
F_16 ( V_4 -> V_2 , L_13 ,
V_9 , V_53 , V_19 , V_118 ) ;
return - V_22 ;
}
* V_20 = ( V_19 & V_117 ) | V_116 | V_119 ;
F_53 ( V_20 , V_20 ) ;
return 0 ;
}
static int F_65 ( struct V_3 * V_4 , T_1 V_53 , T_1 V_19 , T_1 V_116 )
{
T_1 * V_20 = F_64 ( V_4 , V_53 ) ;
int V_7 ;
if ( ( V_53 | V_19 ) & ~ V_120 ) {
F_16 ( V_4 -> V_2 , L_13 ,
V_9 , V_53 , V_19 , V_121 ) ;
return - V_22 ;
}
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ )
* ( V_20 + V_7 ) = ( V_19 & V_120 ) | V_116 | V_122 ;
F_53 ( V_20 , V_20 + 15 ) ;
return 0 ;
}
static int F_66 ( struct V_3 * V_4 , T_1 V_53 , T_1 V_19 , T_1 V_116 )
{
T_1 * V_20 = F_64 ( V_4 , V_53 ) ;
T_1 * V_111 = F_57 ( V_4 , V_20 , V_53 ) ;
if ( F_38 ( V_111 ) )
return F_39 ( V_111 ) ;
* V_111 = ( V_19 & V_123 ) | V_116 | V_124 ;
F_54 ( V_111 , V_111 ) ;
F_61 ( V_4 -> V_2 , L_14 ,
V_9 , V_53 , V_19 , V_111 , * V_111 ) ;
return 0 ;
}
static int F_67 ( struct V_3 * V_4 , T_1 V_53 , T_1 V_19 , T_1 V_116 )
{
T_1 * V_20 = F_64 ( V_4 , V_53 ) ;
T_1 * V_111 = F_57 ( V_4 , V_20 , V_53 ) ;
int V_7 ;
if ( ( V_53 | V_19 ) & ~ V_125 ) {
F_16 ( V_4 -> V_2 , L_13 ,
V_9 , V_53 , V_19 , V_126 ) ;
return - V_22 ;
}
if ( F_38 ( V_111 ) )
return F_39 ( V_111 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ )
* ( V_111 + V_7 ) = ( V_19 & V_125 ) | V_116 | V_127 ;
F_54 ( V_111 , V_111 + 15 ) ;
return 0 ;
}
static int
F_68 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
int (* F_69)( struct V_3 * , T_1 , T_1 , T_1 );
T_1 V_116 ;
int V_29 ;
if ( ! V_4 || ! V_45 )
return - V_22 ;
switch ( V_45 -> V_50 ) {
case V_128 :
F_69 = F_65 ;
break;
case V_129 :
F_69 = F_63 ;
break;
case V_52 :
F_69 = F_67 ;
break;
case V_51 :
F_69 = F_66 ;
break;
default:
F_69 = NULL ;
F_70 () ;
break;
}
V_116 = F_23 ( V_45 ) ;
F_60 ( & V_4 -> V_114 ) ;
V_29 = F_69 ( V_4 , V_45 -> V_53 , V_45 -> V_19 , V_116 ) ;
F_58 ( & V_4 -> V_114 ) ;
return V_29 ;
}
static int
F_71 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
int V_29 ;
F_42 ( V_4 , V_45 -> V_53 ) ;
V_29 = F_68 ( V_4 , V_45 ) ;
if ( ! V_29 )
F_41 ( V_4 , V_45 ) ;
return V_29 ;
}
static void
F_72 ( struct V_3 * V_4 , T_1 V_53 , T_1 * * V_130 , T_1 * * V_131 )
{
T_1 * V_20 , * V_111 = NULL ;
V_20 = F_64 ( V_4 , V_53 ) ;
if ( ! * V_20 )
goto V_81;
if ( F_73 ( * V_20 ) )
V_111 = F_62 ( V_20 , V_53 ) ;
V_81:
* V_130 = V_20 ;
* V_131 = V_111 ;
}
static T_2 F_74 ( struct V_3 * V_4 , T_1 V_53 )
{
T_2 V_84 ;
T_1 * V_20 = F_64 ( V_4 , V_53 ) ;
int V_132 = 1 ;
if ( ! * V_20 )
return 0 ;
if ( F_73 ( * V_20 ) ) {
int V_7 ;
T_1 * V_111 = F_62 ( V_20 , V_53 ) ;
V_84 = V_133 ;
if ( * V_111 & V_127 ) {
V_132 *= 16 ;
V_111 = F_62 ( V_20 , ( V_53 & V_125 ) ) ;
}
V_84 *= V_132 ;
memset ( V_111 , 0 , V_132 * sizeof( * V_111 ) ) ;
F_54 ( V_111 , V_111 + ( V_132 - 1 ) * sizeof( * V_111 ) ) ;
V_111 = F_62 ( V_20 , 0 ) ;
for ( V_7 = 0 ; V_7 < V_134 ; V_7 ++ )
if ( V_111 [ V_7 ] )
goto V_81;
F_55 ( V_111 ) ;
V_132 = 1 ;
} else {
V_84 = V_135 ;
if ( ( * V_20 & V_122 ) == V_122 ) {
V_132 *= 16 ;
V_20 = F_64 ( V_4 , ( V_53 & V_120 ) ) ;
}
V_84 *= V_132 ;
}
memset ( V_20 , 0 , V_132 * sizeof( * V_20 ) ) ;
F_53 ( V_20 , V_20 + ( V_132 - 1 ) * sizeof( * V_20 ) ) ;
V_81:
return V_84 ;
}
static T_2 F_75 ( struct V_3 * V_4 , T_1 V_53 )
{
T_2 V_84 ;
F_60 ( & V_4 -> V_114 ) ;
V_84 = F_74 ( V_4 , V_53 ) ;
F_42 ( V_4 , V_53 ) ;
F_58 ( & V_4 -> V_114 ) ;
return V_84 ;
}
static void F_76 ( struct V_3 * V_4 )
{
int V_7 ;
F_60 ( & V_4 -> V_114 ) ;
for ( V_7 = 0 ; V_7 < V_136 ; V_7 ++ ) {
T_1 V_53 ;
T_1 * V_20 ;
V_53 = V_7 << V_137 ;
V_20 = F_64 ( V_4 , V_53 ) ;
if ( ! * V_20 )
continue;
if ( F_73 ( * V_20 ) )
F_55 ( F_62 ( V_20 , 0 ) ) ;
* V_20 = 0 ;
F_53 ( V_20 , V_20 ) ;
}
F_44 ( V_4 ) ;
F_58 ( & V_4 -> V_114 ) ;
}
static T_4 F_77 ( int V_138 , void * V_139 )
{
T_1 V_53 , V_140 ;
T_1 * V_20 , * V_111 ;
struct V_3 * V_4 = V_139 ;
struct V_141 * V_142 = V_4 -> V_142 ;
struct V_143 * V_144 = V_142 -> V_145 ;
if ( ! V_144 -> V_146 )
return V_147 ;
V_140 = F_24 ( V_4 , & V_53 ) ;
if ( V_140 == 0 )
return V_148 ;
if ( ! F_78 ( V_142 , V_4 -> V_2 , V_53 , 0 ) )
return V_148 ;
F_18 ( V_4 ) ;
V_20 = F_64 ( V_4 , V_53 ) ;
if ( ! F_73 ( * V_20 ) ) {
F_16 ( V_4 -> V_2 , L_15 ,
V_4 -> V_24 , V_140 , V_53 , V_20 , * V_20 ) ;
return V_147 ;
}
V_111 = F_62 ( V_20 , V_53 ) ;
F_16 ( V_4 -> V_2 , L_16 ,
V_4 -> V_24 , V_140 , V_53 , V_20 , * V_20 , V_111 , * V_111 ) ;
return V_147 ;
}
static int F_79 ( struct V_1 * V_2 , void * V_139 )
{
struct V_3 * V_4 = F_80 ( V_2 ) ;
const char * V_24 = V_139 ;
F_81 ( L_17 , V_9 , V_4 -> V_24 , V_24 ) ;
return strcmp ( V_4 -> V_24 , V_24 ) == 0 ;
}
static struct V_3 * F_82 ( const char * V_24 , T_1 * V_20 )
{
int V_29 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_83 ( & V_149 . V_150 , NULL ,
( void * ) V_24 ,
F_79 ) ;
if ( ! V_2 )
return F_33 ( - V_151 ) ;
V_4 = F_80 ( V_2 ) ;
F_60 ( & V_4 -> V_152 ) ;
V_4 -> V_20 = V_20 ;
V_29 = F_13 ( V_4 ) ;
if ( V_29 )
goto V_153;
F_44 ( V_4 ) ;
F_58 ( & V_4 -> V_152 ) ;
F_4 ( V_4 -> V_2 , L_18 , V_9 , V_4 -> V_24 ) ;
return V_4 ;
V_153:
F_58 ( & V_4 -> V_152 ) ;
return F_33 ( V_29 ) ;
}
static void F_84 ( struct V_3 * V_4 )
{
if ( ! V_4 || F_38 ( V_4 ) )
return;
F_60 ( & V_4 -> V_152 ) ;
F_18 ( V_4 ) ;
V_4 -> V_20 = NULL ;
F_58 ( & V_4 -> V_152 ) ;
F_4 ( V_4 -> V_2 , L_18 , V_9 , V_4 -> V_24 ) ;
}
static int F_85 ( struct V_30 * V_31 )
{
int V_29 = - V_151 ;
int V_138 ;
struct V_3 * V_4 ;
struct V_154 * V_155 ;
struct V_32 * V_33 = F_15 ( & V_31 -> V_2 ) ;
struct V_156 * V_157 = V_31 -> V_2 . V_158 ;
V_4 = F_86 ( & V_31 -> V_2 , sizeof( * V_4 ) + V_8 , V_74 ) ;
if ( ! V_4 )
return - V_75 ;
if ( V_157 ) {
V_4 -> V_24 = F_87 ( & V_31 -> V_2 ) ;
V_4 -> V_79 = 32 ;
V_29 = F_88 ( V_157 , L_19 ,
& V_4 -> V_79 ) ;
if ( V_29 && V_29 != - V_22 )
return V_29 ;
if ( V_4 -> V_79 != 32 && V_4 -> V_79 != 8 )
return - V_22 ;
if ( F_89 ( V_157 , L_20 , NULL ) )
V_4 -> V_26 = V_27 ;
} else {
V_4 -> V_79 = V_33 -> V_79 ;
V_4 -> V_24 = V_33 -> V_24 ;
}
V_4 -> V_2 = & V_31 -> V_2 ;
V_4 -> V_6 = ( void * ) V_4 + sizeof( * V_4 ) ;
F_90 ( & V_4 -> V_152 ) ;
F_90 ( & V_4 -> V_114 ) ;
V_155 = F_91 ( V_31 , V_159 , 0 ) ;
V_4 -> V_160 = F_92 ( V_4 -> V_2 , V_155 ) ;
if ( F_38 ( V_4 -> V_160 ) )
return F_39 ( V_4 -> V_160 ) ;
V_138 = F_93 ( V_31 , 0 ) ;
if ( V_138 < 0 )
return - V_151 ;
V_29 = F_94 ( V_4 -> V_2 , V_138 , F_77 , V_161 ,
F_87 ( V_4 -> V_2 ) , V_4 ) ;
if ( V_29 < 0 )
return V_29 ;
F_95 ( V_31 , V_4 ) ;
F_96 ( V_4 -> V_2 ) ;
F_97 ( V_4 -> V_2 ) ;
F_98 ( V_4 ) ;
F_11 ( & V_31 -> V_2 , L_21 , V_4 -> V_24 ) ;
return 0 ;
}
static int F_99 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_100 ( V_31 ) ;
F_76 ( V_4 ) ;
F_101 ( V_4 ) ;
F_102 ( V_4 -> V_2 ) ;
F_11 ( & V_31 -> V_2 , L_22 , V_4 -> V_24 ) ;
return 0 ;
}
static void F_103 ( void * V_111 )
{
F_104 ( V_111 , V_162 ) ;
}
static T_1 F_105 ( struct V_44 * V_45 , T_1 V_53 , T_1 V_19 , int V_50 )
{
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_53 = V_53 ;
V_45 -> V_19 = V_19 ;
V_45 -> V_78 = V_40 ;
V_45 -> V_50 = V_50 ;
V_45 -> V_48 = V_163 ;
V_45 -> V_49 = V_164 ;
V_45 -> V_47 = 0 ;
return F_43 ( V_45 -> V_50 ) ;
}
static int F_106 ( struct V_141 * V_142 , unsigned long V_53 ,
T_5 V_19 , T_2 V_84 , int V_116 )
{
struct V_143 * V_144 = V_142 -> V_145 ;
struct V_3 * V_165 = V_144 -> V_146 ;
struct V_1 * V_2 = V_165 -> V_2 ;
struct V_44 V_45 ;
int V_166 ;
T_1 V_167 ;
V_166 = F_107 ( V_84 ) ;
if ( V_166 < 0 ) {
F_16 ( V_2 , L_23 , V_84 ) ;
return - V_22 ;
}
F_4 ( V_2 , L_24 , V_53 , V_19 , V_84 ) ;
F_105 ( & V_45 , V_53 , V_19 , V_166 ) ;
V_167 = F_71 ( V_165 , & V_45 ) ;
if ( V_167 )
F_16 ( V_2 , L_25 , V_167 ) ;
return V_167 ;
}
static T_2 F_108 ( struct V_141 * V_142 , unsigned long V_53 ,
T_2 V_168 )
{
struct V_143 * V_144 = V_142 -> V_145 ;
struct V_3 * V_165 = V_144 -> V_146 ;
struct V_1 * V_2 = V_165 -> V_2 ;
F_4 ( V_2 , L_26 , V_53 , V_168 ) ;
return F_75 ( V_165 , V_53 ) ;
}
static int
F_109 ( struct V_141 * V_142 , struct V_1 * V_2 )
{
struct V_143 * V_144 = V_142 -> V_145 ;
struct V_3 * V_165 ;
struct V_169 * V_170 = V_2 -> V_171 . V_172 ;
int V_167 = 0 ;
if ( ! V_170 || ! V_170 -> V_24 ) {
F_16 ( V_2 , L_27 ) ;
return - V_22 ;
}
F_60 ( & V_144 -> V_173 ) ;
if ( V_144 -> V_146 ) {
F_16 ( V_2 , L_28 ) ;
V_167 = - V_80 ;
goto V_81;
}
V_165 = F_82 ( V_170 -> V_24 , V_144 -> V_174 ) ;
if ( F_38 ( V_165 ) ) {
V_167 = F_39 ( V_165 ) ;
F_16 ( V_2 , L_29 , V_167 ) ;
goto V_81;
}
V_144 -> V_146 = V_170 -> V_146 = V_165 ;
V_144 -> V_2 = V_2 ;
V_165 -> V_142 = V_142 ;
V_81:
F_58 ( & V_144 -> V_173 ) ;
return V_167 ;
}
static void F_110 ( struct V_143 * V_144 ,
struct V_1 * V_2 )
{
struct V_3 * V_165 = F_2 ( V_2 ) ;
struct V_169 * V_170 = V_2 -> V_171 . V_172 ;
if ( V_144 -> V_146 != V_165 ) {
F_16 ( V_2 , L_30 ) ;
return;
}
F_76 ( V_165 ) ;
F_84 ( V_165 ) ;
V_144 -> V_146 = V_170 -> V_146 = NULL ;
V_144 -> V_2 = NULL ;
V_165 -> V_142 = NULL ;
}
static void F_111 ( struct V_141 * V_142 ,
struct V_1 * V_2 )
{
struct V_143 * V_144 = V_142 -> V_145 ;
F_60 ( & V_144 -> V_173 ) ;
F_110 ( V_144 , V_2 ) ;
F_58 ( & V_144 -> V_173 ) ;
}
static int F_112 ( struct V_141 * V_142 )
{
struct V_143 * V_144 ;
V_144 = F_113 ( sizeof( * V_144 ) , V_74 ) ;
if ( ! V_144 ) {
F_114 ( L_31 ) ;
goto V_81;
}
V_144 -> V_174 = F_113 ( V_175 , V_74 ) ;
if ( ! V_144 -> V_174 ) {
F_114 ( L_31 ) ;
goto V_176;
}
F_115 ( ! F_9 ( ( long ) V_144 -> V_174 , V_175 ) ) ;
F_104 ( V_144 -> V_174 , V_175 ) ;
F_90 ( & V_144 -> V_173 ) ;
V_142 -> V_145 = V_144 ;
V_142 -> V_177 . V_178 = 0 ;
V_142 -> V_177 . V_179 = ( 1ULL << 32 ) - 1 ;
V_142 -> V_177 . V_180 = true ;
return 0 ;
V_176:
F_40 ( V_144 ) ;
V_81:
return - V_75 ;
}
static void F_116 ( struct V_141 * V_142 )
{
struct V_143 * V_144 = V_142 -> V_145 ;
V_142 -> V_145 = NULL ;
if ( V_144 -> V_146 )
F_110 ( V_144 , V_144 -> V_2 ) ;
F_40 ( V_144 -> V_174 ) ;
F_40 ( V_144 ) ;
}
static T_5 F_117 ( struct V_141 * V_142 ,
T_6 V_53 )
{
struct V_143 * V_144 = V_142 -> V_145 ;
struct V_3 * V_165 = V_144 -> V_146 ;
struct V_1 * V_2 = V_165 -> V_2 ;
T_1 * V_181 , * V_182 ;
T_5 V_167 = 0 ;
F_72 ( V_165 , V_53 , & V_181 , & V_182 ) ;
if ( V_182 ) {
if ( F_118 ( * V_182 ) )
V_167 = F_119 ( * V_182 , V_53 , V_183 ) ;
else if ( F_120 ( * V_182 ) )
V_167 = F_119 ( * V_182 , V_53 , V_125 ) ;
else
F_16 ( V_2 , L_32 , * V_182 ,
( unsigned long long ) V_53 ) ;
} else {
if ( F_121 ( * V_181 ) )
V_167 = F_119 ( * V_181 , V_53 , V_117 ) ;
else if ( F_122 ( * V_181 ) )
V_167 = F_119 ( * V_181 , V_53 , V_120 ) ;
else
F_16 ( V_2 , L_33 , * V_181 ,
( unsigned long long ) V_53 ) ;
}
return V_167 ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_169 * V_170 ;
struct V_156 * V_184 ;
struct V_30 * V_31 ;
if ( ! V_2 -> V_158 )
return 0 ;
V_184 = F_124 ( V_2 -> V_158 , L_34 , 0 ) ;
if ( ! V_184 )
return 0 ;
V_31 = F_125 ( V_184 ) ;
if ( F_126 ( ! V_31 ) ) {
F_127 ( V_184 ) ;
return - V_22 ;
}
V_170 = F_113 ( sizeof( * V_170 ) , V_74 ) ;
if ( ! V_170 ) {
F_127 ( V_184 ) ;
return - V_75 ;
}
V_170 -> V_24 = F_128 ( F_87 ( & V_31 -> V_2 ) , V_74 ) ;
V_2 -> V_171 . V_172 = V_170 ;
F_127 ( V_184 ) ;
return 0 ;
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_169 * V_170 = V_2 -> V_171 . V_172 ;
if ( ! V_2 -> V_158 || ! V_170 )
return;
F_40 ( V_170 -> V_24 ) ;
F_40 ( V_170 ) ;
}
static int T_7 F_130 ( void )
{
struct V_185 * V_5 ;
const unsigned long V_186 = V_187 ;
T_2 V_188 = 1 << 10 ;
V_5 = F_131 ( L_35 , V_162 , V_188 , V_186 ,
F_103 ) ;
if ( ! V_5 )
return - V_75 ;
V_112 = V_5 ;
F_132 ( & V_189 , & V_190 ) ;
F_133 () ;
return F_134 ( & V_149 ) ;
}
static void T_8 F_135 ( void )
{
F_136 ( V_112 ) ;
F_137 ( & V_149 ) ;
F_138 () ;
}
