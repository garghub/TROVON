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
static T_1 F_22 ( struct V_41 * V_42 )
{
T_1 V_43 = V_42 -> V_44 & V_45 ;
T_1 V_46 = F_23 ( V_42 -> V_44 & V_43 ) ;
return V_42 -> V_44 & V_46 ;
}
static T_1 F_24 ( struct V_47 * V_48 )
{
T_1 V_49 ;
V_49 = V_48 -> V_50 << 5 ;
V_49 |= V_48 -> V_51 ;
V_49 |= V_48 -> V_52 >> 3 ;
V_49 <<= ( ( ( V_48 -> V_53 == V_54 ) ||
( V_48 -> V_53 == V_55 ) ) ? 0 : 6 ) ;
return V_49 ;
}
static T_1 F_25 ( struct V_7 * V_8 , T_1 * V_56 )
{
T_1 V_57 , V_58 ;
V_57 = F_5 ( V_8 , V_59 ) ;
V_57 &= V_60 ;
if ( ! V_57 ) {
* V_56 = 0 ;
return 0 ;
}
V_58 = F_5 ( V_8 , V_61 ) ;
* V_56 = V_58 ;
F_8 ( V_8 , V_57 , V_59 ) ;
return V_57 ;
}
void F_26 ( struct V_7 * V_8 , struct V_62 * V_15 )
{
T_1 V_63 ;
V_63 = F_5 ( V_8 , V_64 ) ;
V_15 -> V_65 = F_27 ( V_63 ) ;
V_15 -> V_66 = F_28 ( V_63 ) ;
}
void F_29 ( struct V_7 * V_8 , struct V_62 * V_15 )
{
T_1 V_63 ;
V_63 = ( V_15 -> V_65 << V_67 ) ;
V_63 |= ( V_15 -> V_66 << V_68 ) ;
F_8 ( V_8 , V_63 , V_64 ) ;
}
static void F_30 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
V_42 -> V_44 = F_5 ( V_8 , V_69 ) ;
V_42 -> V_70 = F_5 ( V_8 , V_71 ) ;
}
static void F_31 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
F_8 ( V_8 , V_42 -> V_44 | V_72 , V_73 ) ;
F_8 ( V_8 , V_42 -> V_70 , V_74 ) ;
F_8 ( V_8 , 1 , V_75 ) ;
F_8 ( V_8 , 1 , V_76 ) ;
}
struct V_41 F_32 ( struct V_7 * V_8 , int V_77 )
{
struct V_41 V_42 ;
struct V_62 V_15 ;
F_26 ( V_8 , & V_15 ) ;
V_15 . V_66 = V_77 ;
F_29 ( V_8 , & V_15 ) ;
F_30 ( V_8 , & V_42 ) ;
return V_42 ;
}
static struct V_41 * F_33 ( struct V_7 * V_8 ,
struct V_47 * V_48 )
{
struct V_41 * V_42 ;
if ( ! V_48 )
return NULL ;
if ( V_48 -> V_56 & ~ ( F_23 ( V_48 -> V_53 ) ) ) {
F_18 ( V_8 -> V_6 , L_5 , V_13 ,
V_48 -> V_56 ) ;
return F_34 ( - V_26 ) ;
}
V_42 = F_35 ( sizeof( * V_42 ) , V_78 ) ;
if ( ! V_42 )
return F_34 ( - V_79 ) ;
V_42 -> V_44 = ( V_48 -> V_56 & V_80 ) | V_48 -> V_81 | V_48 -> V_53 | V_48 -> V_82 ;
V_42 -> V_70 = V_48 -> V_23 | V_48 -> V_51 | V_48 -> V_52 | V_48 -> V_50 ;
return V_42 ;
}
static int F_36 ( struct V_7 * V_8 , struct V_47 * V_48 )
{
int V_33 = 0 ;
struct V_62 V_15 ;
struct V_41 * V_42 ;
if ( ! V_8 || ! V_8 -> V_83 || ! V_48 )
return - V_26 ;
F_19 ( V_8 -> V_6 ) ;
F_26 ( V_8 , & V_15 ) ;
if ( V_15 . V_65 == V_8 -> V_83 ) {
F_37 ( V_8 -> V_6 , L_6 , V_13 ) ;
V_33 = - V_84 ;
goto V_85;
}
if ( ! V_48 -> V_81 ) {
int V_11 ;
struct V_41 V_86 ;
F_38 (obj, obj->nr_tlb_entries, i, tmp)
if ( ! F_39 ( & V_86 ) )
break;
if ( V_11 == V_8 -> V_83 ) {
F_6 ( V_8 -> V_6 , L_7 , V_13 ) ;
V_33 = - V_84 ;
goto V_85;
}
F_26 ( V_8 , & V_15 ) ;
} else {
V_15 . V_66 = V_15 . V_65 ;
F_29 ( V_8 , & V_15 ) ;
}
V_42 = F_33 ( V_8 , V_48 ) ;
if ( F_40 ( V_42 ) ) {
F_21 ( V_8 -> V_6 ) ;
return F_41 ( V_42 ) ;
}
F_31 ( V_8 , V_42 ) ;
F_42 ( V_42 ) ;
if ( V_48 -> V_81 )
V_15 . V_65 ++ ;
if ( ++ V_15 . V_66 == V_8 -> V_83 )
V_15 . V_66 = V_15 . V_65 ;
F_29 ( V_8 , & V_15 ) ;
V_85:
F_21 ( V_8 -> V_6 ) ;
return V_33 ;
}
static int F_36 ( struct V_7 * V_8 , struct V_47 * V_48 )
{
return 0 ;
}
static int F_43 ( struct V_7 * V_8 , struct V_47 * V_48 )
{
return F_36 ( V_8 , V_48 ) ;
}
static void F_44 ( struct V_7 * V_8 , T_1 V_56 )
{
int V_11 ;
struct V_41 V_42 ;
F_19 ( V_8 -> V_6 ) ;
F_38 (obj, obj->nr_tlb_entries, i, cr) {
T_1 V_87 ;
T_2 V_88 ;
if ( ! F_39 ( & V_42 ) )
continue;
V_87 = F_22 ( & V_42 ) ;
V_88 = F_45 ( V_42 . V_44 & 3 ) ;
if ( ( V_87 <= V_56 ) && ( V_56 < V_87 + V_88 ) ) {
F_6 ( V_8 -> V_6 , L_8 ,
V_13 , V_87 , V_56 , V_88 ) ;
F_31 ( V_8 , & V_42 ) ;
F_8 ( V_8 , 1 , V_75 ) ;
break;
}
}
F_21 ( V_8 -> V_6 ) ;
if ( V_11 == V_8 -> V_83 )
F_6 ( V_8 -> V_6 , L_9 , V_13 , V_56 ) ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_62 V_15 ;
F_19 ( V_8 -> V_6 ) ;
V_15 . V_65 = 0 ;
V_15 . V_66 = 0 ;
F_29 ( V_8 , & V_15 ) ;
F_8 ( V_8 , 1 , V_89 ) ;
F_21 ( V_8 -> V_6 ) ;
}
static void F_47 ( T_1 * V_90 , T_1 * V_91 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pgd"
: : "r" (first));
V_90 += V_92 / sizeof( * V_90 ) ;
} while ( V_90 <= V_91 );
}
static void F_48 ( T_1 * V_90 , T_1 * V_91 )
{
do {
asm("mcr p15, 0, %0, c7, c10, 1 @ flush_pte"
: : "r" (first));
V_90 += V_92 / sizeof( * V_90 ) ;
} while ( V_90 <= V_91 );
}
static void F_49 ( T_1 * V_93 )
{
if ( V_93 )
F_50 ( V_94 , V_93 ) ;
}
static T_1 * F_51 ( struct V_7 * V_8 , T_1 * V_24 , T_1 V_56 )
{
T_1 * V_93 ;
if ( * V_24 )
goto V_95;
F_52 ( & V_8 -> V_96 ) ;
V_93 = F_53 ( V_94 , V_78 ) ;
F_54 ( & V_8 -> V_96 ) ;
if ( ! * V_24 ) {
if ( ! V_93 )
return F_34 ( - V_79 ) ;
* V_24 = F_12 ( V_93 ) | V_97 ;
F_47 ( V_24 , V_24 ) ;
F_55 ( V_8 -> V_6 , L_10 , V_13 , V_93 ) ;
} else {
F_49 ( V_93 ) ;
}
V_95:
V_93 = F_56 ( V_24 , V_56 ) ;
F_55 ( V_8 -> V_6 ,
L_11 ,
V_13 , V_56 , V_24 , * V_24 , V_93 , * V_93 ) ;
return V_93 ;
}
static int F_57 ( struct V_7 * V_8 , T_1 V_56 , T_1 V_23 , T_1 V_98 )
{
T_1 * V_24 = F_58 ( V_8 , V_56 ) ;
if ( ( V_56 | V_23 ) & ~ V_99 ) {
F_18 ( V_8 -> V_6 , L_12 ,
V_13 , V_56 , V_23 , V_100 ) ;
return - V_26 ;
}
* V_24 = ( V_23 & V_99 ) | V_98 | V_101 ;
F_47 ( V_24 , V_24 ) ;
return 0 ;
}
static int F_59 ( struct V_7 * V_8 , T_1 V_56 , T_1 V_23 , T_1 V_98 )
{
T_1 * V_24 = F_58 ( V_8 , V_56 ) ;
int V_11 ;
if ( ( V_56 | V_23 ) & ~ V_102 ) {
F_18 ( V_8 -> V_6 , L_12 ,
V_13 , V_56 , V_23 , V_103 ) ;
return - V_26 ;
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
* ( V_24 + V_11 ) = ( V_23 & V_102 ) | V_98 | V_104 ;
F_47 ( V_24 , V_24 + 15 ) ;
return 0 ;
}
static int F_60 ( struct V_7 * V_8 , T_1 V_56 , T_1 V_23 , T_1 V_98 )
{
T_1 * V_24 = F_58 ( V_8 , V_56 ) ;
T_1 * V_93 = F_51 ( V_8 , V_24 , V_56 ) ;
if ( F_40 ( V_93 ) )
return F_41 ( V_93 ) ;
* V_93 = ( V_23 & V_105 ) | V_98 | V_106 ;
F_48 ( V_93 , V_93 ) ;
F_55 ( V_8 -> V_6 , L_13 ,
V_13 , V_56 , V_23 , V_93 , * V_93 ) ;
return 0 ;
}
static int F_61 ( struct V_7 * V_8 , T_1 V_56 , T_1 V_23 , T_1 V_98 )
{
T_1 * V_24 = F_58 ( V_8 , V_56 ) ;
T_1 * V_93 = F_51 ( V_8 , V_24 , V_56 ) ;
int V_11 ;
if ( ( V_56 | V_23 ) & ~ V_107 ) {
F_18 ( V_8 -> V_6 , L_12 ,
V_13 , V_56 , V_23 , V_108 ) ;
return - V_26 ;
}
if ( F_40 ( V_93 ) )
return F_41 ( V_93 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
* ( V_93 + V_11 ) = ( V_23 & V_107 ) | V_98 | V_109 ;
F_48 ( V_93 , V_93 + 15 ) ;
return 0 ;
}
static int
F_62 ( struct V_7 * V_8 , struct V_47 * V_48 )
{
int (* F_63)( struct V_7 * , T_1 , T_1 , T_1 );
T_1 V_98 ;
int V_33 ;
if ( ! V_8 || ! V_48 )
return - V_26 ;
switch ( V_48 -> V_53 ) {
case V_110 :
F_63 = F_59 ;
break;
case V_111 :
F_63 = F_57 ;
break;
case V_55 :
F_63 = F_61 ;
break;
case V_54 :
F_63 = F_60 ;
break;
default:
F_63 = NULL ;
F_64 () ;
break;
}
V_98 = F_24 ( V_48 ) ;
F_54 ( & V_8 -> V_96 ) ;
V_33 = F_63 ( V_8 , V_48 -> V_56 , V_48 -> V_23 , V_98 ) ;
F_52 ( & V_8 -> V_96 ) ;
return V_33 ;
}
static int
F_65 ( struct V_7 * V_8 , struct V_47 * V_48 )
{
int V_33 ;
F_44 ( V_8 , V_48 -> V_56 ) ;
V_33 = F_62 ( V_8 , V_48 ) ;
if ( ! V_33 )
F_43 ( V_8 , V_48 ) ;
return V_33 ;
}
static void
F_66 ( struct V_7 * V_8 , T_1 V_56 , T_1 * * V_112 , T_1 * * V_113 )
{
T_1 * V_24 , * V_93 = NULL ;
V_24 = F_58 ( V_8 , V_56 ) ;
if ( ! * V_24 )
goto V_85;
if ( F_67 ( * V_24 ) )
V_93 = F_56 ( V_24 , V_56 ) ;
V_85:
* V_112 = V_24 ;
* V_113 = V_93 ;
}
static T_2 F_68 ( struct V_7 * V_8 , T_1 V_56 )
{
T_2 V_88 ;
T_1 * V_24 = F_58 ( V_8 , V_56 ) ;
int V_114 = 1 ;
if ( ! * V_24 )
return 0 ;
if ( F_67 ( * V_24 ) ) {
int V_11 ;
T_1 * V_93 = F_56 ( V_24 , V_56 ) ;
V_88 = V_115 ;
if ( * V_93 & V_109 ) {
V_114 *= 16 ;
V_93 = F_56 ( V_24 , ( V_56 & V_107 ) ) ;
}
V_88 *= V_114 ;
memset ( V_93 , 0 , V_114 * sizeof( * V_93 ) ) ;
F_48 ( V_93 , V_93 + ( V_114 - 1 ) * sizeof( * V_93 ) ) ;
V_93 = F_56 ( V_24 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_116 ; V_11 ++ )
if ( V_93 [ V_11 ] )
goto V_85;
F_49 ( V_93 ) ;
V_114 = 1 ;
} else {
V_88 = V_117 ;
if ( ( * V_24 & V_104 ) == V_104 ) {
V_114 *= 16 ;
V_24 = F_58 ( V_8 , ( V_56 & V_102 ) ) ;
}
V_88 *= V_114 ;
}
memset ( V_24 , 0 , V_114 * sizeof( * V_24 ) ) ;
F_47 ( V_24 , V_24 + ( V_114 - 1 ) * sizeof( * V_24 ) ) ;
V_85:
return V_88 ;
}
static T_2 F_69 ( struct V_7 * V_8 , T_1 V_56 )
{
T_2 V_88 ;
F_54 ( & V_8 -> V_96 ) ;
V_88 = F_68 ( V_8 , V_56 ) ;
F_44 ( V_8 , V_56 ) ;
F_52 ( & V_8 -> V_96 ) ;
return V_88 ;
}
static void F_70 ( struct V_7 * V_8 )
{
int V_11 ;
F_54 ( & V_8 -> V_96 ) ;
for ( V_11 = 0 ; V_11 < V_118 ; V_11 ++ ) {
T_1 V_56 ;
T_1 * V_24 ;
V_56 = V_11 << V_119 ;
V_24 = F_58 ( V_8 , V_56 ) ;
if ( ! * V_24 )
continue;
if ( F_67 ( * V_24 ) )
F_49 ( F_56 ( V_24 , 0 ) ) ;
* V_24 = 0 ;
F_47 ( V_24 , V_24 ) ;
}
F_46 ( V_8 ) ;
F_52 ( & V_8 -> V_96 ) ;
}
static T_3 F_71 ( int V_120 , void * V_121 )
{
T_1 V_56 , V_122 ;
T_1 * V_24 , * V_93 ;
struct V_7 * V_8 = V_121 ;
struct V_2 * V_4 = V_8 -> V_4 ;
struct V_1 * V_123 = F_1 ( V_4 ) ;
if ( ! V_123 -> V_124 )
return V_125 ;
V_122 = F_25 ( V_8 , & V_56 ) ;
if ( V_122 == 0 )
return V_126 ;
if ( ! F_72 ( V_4 , V_8 -> V_6 , V_56 , 0 ) )
return V_126 ;
F_20 ( V_8 ) ;
V_24 = F_58 ( V_8 , V_56 ) ;
if ( ! F_67 ( * V_24 ) ) {
F_18 ( V_8 -> V_6 , L_14 ,
V_8 -> V_28 , V_122 , V_56 , V_24 , * V_24 ) ;
return V_125 ;
}
V_93 = F_56 ( V_24 , V_56 ) ;
F_18 ( V_8 -> V_6 , L_15 ,
V_8 -> V_28 , V_122 , V_56 , V_24 , * V_24 , V_93 , * V_93 ) ;
return V_125 ;
}
static int F_73 ( struct V_5 * V_6 , void * V_121 )
{
struct V_7 * V_8 = F_74 ( V_6 ) ;
const char * V_28 = V_121 ;
F_75 ( L_16 , V_13 , V_8 -> V_28 , V_28 ) ;
return strcmp ( V_8 -> V_28 , V_28 ) == 0 ;
}
static struct V_7 * F_76 ( const char * V_28 , T_1 * V_24 )
{
int V_33 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_77 ( & V_127 . V_128 , NULL , ( void * ) V_28 ,
F_73 ) ;
if ( ! V_6 )
return F_34 ( - V_129 ) ;
V_8 = F_74 ( V_6 ) ;
F_54 ( & V_8 -> V_130 ) ;
V_8 -> V_24 = V_24 ;
V_33 = F_15 ( V_8 ) ;
if ( V_33 )
goto V_131;
F_46 ( V_8 ) ;
F_52 ( & V_8 -> V_130 ) ;
F_6 ( V_8 -> V_6 , L_17 , V_13 , V_8 -> V_28 ) ;
return V_8 ;
V_131:
F_52 ( & V_8 -> V_130 ) ;
return F_34 ( V_33 ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
if ( ! V_8 || F_40 ( V_8 ) )
return;
F_54 ( & V_8 -> V_130 ) ;
F_20 ( V_8 ) ;
V_8 -> V_24 = NULL ;
F_52 ( & V_8 -> V_130 ) ;
F_6 ( V_8 -> V_6 , L_17 , V_13 , V_8 -> V_28 ) ;
}
static int F_79 ( struct V_34 * V_35 )
{
int V_33 = - V_129 ;
int V_120 ;
struct V_7 * V_8 ;
struct V_132 * V_133 ;
struct V_36 * V_37 = F_17 ( & V_35 -> V_6 ) ;
struct V_134 * V_135 = V_35 -> V_6 . V_136 ;
V_8 = F_80 ( & V_35 -> V_6 , sizeof( * V_8 ) + V_12 , V_78 ) ;
if ( ! V_8 )
return - V_79 ;
if ( V_135 ) {
V_8 -> V_28 = F_81 ( & V_35 -> V_6 ) ;
V_8 -> V_83 = 32 ;
V_33 = F_82 ( V_135 , L_18 ,
& V_8 -> V_83 ) ;
if ( V_33 && V_33 != - V_26 )
return V_33 ;
if ( V_8 -> V_83 != 32 && V_8 -> V_83 != 8 )
return - V_26 ;
if ( F_83 ( V_135 , L_19 , NULL ) )
V_8 -> V_30 = V_31 ;
} else {
V_8 -> V_83 = V_37 -> V_83 ;
V_8 -> V_28 = V_37 -> V_28 ;
}
V_8 -> V_6 = & V_35 -> V_6 ;
V_8 -> V_10 = ( void * ) V_8 + sizeof( * V_8 ) ;
F_84 ( & V_8 -> V_130 ) ;
F_84 ( & V_8 -> V_96 ) ;
V_133 = F_85 ( V_35 , V_137 , 0 ) ;
V_8 -> V_138 = F_86 ( V_8 -> V_6 , V_133 ) ;
if ( F_40 ( V_8 -> V_138 ) )
return F_41 ( V_8 -> V_138 ) ;
V_120 = F_87 ( V_35 , 0 ) ;
if ( V_120 < 0 )
return - V_129 ;
V_33 = F_88 ( V_8 -> V_6 , V_120 , F_71 , V_139 ,
F_81 ( V_8 -> V_6 ) , V_8 ) ;
if ( V_33 < 0 )
return V_33 ;
F_89 ( V_35 , V_8 ) ;
F_90 ( V_8 -> V_6 ) ;
F_91 ( V_8 -> V_6 ) ;
F_92 ( V_8 ) ;
F_13 ( & V_35 -> V_6 , L_20 , V_8 -> V_28 ) ;
return 0 ;
}
static int F_93 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = F_94 ( V_35 ) ;
F_70 ( V_8 ) ;
F_95 ( V_8 ) ;
F_96 ( V_8 -> V_6 ) ;
F_13 ( & V_35 -> V_6 , L_21 , V_8 -> V_28 ) ;
return 0 ;
}
static void F_97 ( void * V_93 )
{
F_98 ( V_93 , V_140 ) ;
}
static T_1 F_99 ( struct V_47 * V_48 , T_1 V_56 , T_1 V_23 , int V_53 )
{
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_56 = V_56 ;
V_48 -> V_23 = V_23 ;
V_48 -> V_82 = V_72 ;
V_48 -> V_53 = V_53 ;
V_48 -> V_51 = V_141 ;
V_48 -> V_52 = V_142 ;
V_48 -> V_50 = 0 ;
return F_45 ( V_48 -> V_53 ) ;
}
static int F_100 ( struct V_2 * V_4 , unsigned long V_56 ,
T_4 V_23 , T_2 V_88 , int V_98 )
{
struct V_1 * V_123 = F_1 ( V_4 ) ;
struct V_7 * V_143 = V_123 -> V_124 ;
struct V_5 * V_6 = V_143 -> V_6 ;
struct V_47 V_48 ;
int V_144 ;
T_1 V_145 ;
V_144 = F_101 ( V_88 ) ;
if ( V_144 < 0 ) {
F_18 ( V_6 , L_22 , V_88 ) ;
return - V_26 ;
}
F_6 ( V_6 , L_23 , V_56 , & V_23 , V_88 ) ;
F_99 ( & V_48 , V_56 , V_23 , V_144 ) ;
V_145 = F_65 ( V_143 , & V_48 ) ;
if ( V_145 )
F_18 ( V_6 , L_24 , V_145 ) ;
return V_145 ;
}
static T_2 F_102 ( struct V_2 * V_4 , unsigned long V_56 ,
T_2 V_146 )
{
struct V_1 * V_123 = F_1 ( V_4 ) ;
struct V_7 * V_143 = V_123 -> V_124 ;
struct V_5 * V_6 = V_143 -> V_6 ;
F_6 ( V_6 , L_25 , V_56 , V_146 ) ;
return F_69 ( V_143 , V_56 ) ;
}
static int
F_103 ( struct V_2 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_123 = F_1 ( V_4 ) ;
struct V_7 * V_143 ;
struct V_147 * V_148 = V_6 -> V_149 . V_150 ;
int V_145 = 0 ;
if ( ! V_148 || ! V_148 -> V_28 ) {
F_18 ( V_6 , L_26 ) ;
return - V_26 ;
}
F_54 ( & V_123 -> V_151 ) ;
if ( V_123 -> V_124 ) {
F_18 ( V_6 , L_27 ) ;
V_145 = - V_84 ;
goto V_85;
}
V_143 = F_76 ( V_148 -> V_28 , V_123 -> V_152 ) ;
if ( F_40 ( V_143 ) ) {
V_145 = F_41 ( V_143 ) ;
F_18 ( V_6 , L_28 , V_145 ) ;
goto V_85;
}
V_123 -> V_124 = V_148 -> V_124 = V_143 ;
V_123 -> V_6 = V_6 ;
V_143 -> V_4 = V_4 ;
V_85:
F_52 ( & V_123 -> V_151 ) ;
return V_145 ;
}
static void F_104 ( struct V_1 * V_123 ,
struct V_5 * V_6 )
{
struct V_7 * V_143 = F_4 ( V_6 ) ;
struct V_147 * V_148 = V_6 -> V_149 . V_150 ;
if ( V_123 -> V_124 != V_143 ) {
F_18 ( V_6 , L_29 ) ;
return;
}
F_70 ( V_143 ) ;
F_78 ( V_143 ) ;
V_123 -> V_124 = V_148 -> V_124 = NULL ;
V_123 -> V_6 = NULL ;
V_143 -> V_4 = NULL ;
}
static void F_105 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_123 = F_1 ( V_4 ) ;
F_54 ( & V_123 -> V_151 ) ;
F_104 ( V_123 , V_6 ) ;
F_52 ( & V_123 -> V_151 ) ;
}
static struct V_2 * F_106 ( unsigned type )
{
struct V_1 * V_123 ;
if ( type != V_153 )
return NULL ;
V_123 = F_107 ( sizeof( * V_123 ) , V_78 ) ;
if ( ! V_123 )
goto V_85;
V_123 -> V_152 = F_107 ( V_154 , V_78 ) ;
if ( ! V_123 -> V_152 )
goto V_155;
F_108 ( ! F_11 ( ( long ) V_123 -> V_152 , V_154 ) ) ;
F_98 ( V_123 -> V_152 , V_154 ) ;
F_84 ( & V_123 -> V_151 ) ;
V_123 -> V_4 . V_156 . V_157 = 0 ;
V_123 -> V_4 . V_156 . V_158 = ( 1ULL << 32 ) - 1 ;
V_123 -> V_4 . V_156 . V_159 = true ;
return & V_123 -> V_4 ;
V_155:
F_42 ( V_123 ) ;
V_85:
return NULL ;
}
static void F_109 ( struct V_2 * V_4 )
{
struct V_1 * V_123 = F_1 ( V_4 ) ;
if ( V_123 -> V_124 )
F_104 ( V_123 , V_123 -> V_6 ) ;
F_42 ( V_123 -> V_152 ) ;
F_42 ( V_123 ) ;
}
static T_4 F_110 ( struct V_2 * V_4 ,
T_5 V_56 )
{
struct V_1 * V_123 = F_1 ( V_4 ) ;
struct V_7 * V_143 = V_123 -> V_124 ;
struct V_5 * V_6 = V_143 -> V_6 ;
T_1 * V_160 , * V_161 ;
T_4 V_145 = 0 ;
F_66 ( V_143 , V_56 , & V_160 , & V_161 ) ;
if ( V_161 ) {
if ( F_111 ( * V_161 ) )
V_145 = F_112 ( * V_161 , V_56 , V_162 ) ;
else if ( F_113 ( * V_161 ) )
V_145 = F_112 ( * V_161 , V_56 , V_107 ) ;
else
F_18 ( V_6 , L_30 , * V_161 ,
( unsigned long long ) V_56 ) ;
} else {
if ( F_114 ( * V_160 ) )
V_145 = F_112 ( * V_160 , V_56 , V_99 ) ;
else if ( F_115 ( * V_160 ) )
V_145 = F_112 ( * V_160 , V_56 , V_102 ) ;
else
F_18 ( V_6 , L_31 , * V_160 ,
( unsigned long long ) V_56 ) ;
}
return V_145 ;
}
static int F_116 ( struct V_5 * V_6 )
{
struct V_147 * V_148 ;
struct V_134 * V_163 ;
struct V_34 * V_35 ;
if ( ! V_6 -> V_136 )
return 0 ;
V_163 = F_117 ( V_6 -> V_136 , L_32 , 0 ) ;
if ( ! V_163 )
return 0 ;
V_35 = F_118 ( V_163 ) ;
if ( F_119 ( ! V_35 ) ) {
F_120 ( V_163 ) ;
return - V_26 ;
}
V_148 = F_107 ( sizeof( * V_148 ) , V_78 ) ;
if ( ! V_148 ) {
F_120 ( V_163 ) ;
return - V_79 ;
}
V_148 -> V_28 = F_121 ( F_81 ( & V_35 -> V_6 ) , V_78 ) ;
V_6 -> V_149 . V_150 = V_148 ;
F_120 ( V_163 ) ;
return 0 ;
}
static void F_122 ( struct V_5 * V_6 )
{
struct V_147 * V_148 = V_6 -> V_149 . V_150 ;
if ( ! V_6 -> V_136 || ! V_148 )
return;
F_42 ( V_148 -> V_28 ) ;
F_42 ( V_148 ) ;
}
static int T_6 F_123 ( void )
{
struct V_164 * V_9 ;
const unsigned long V_165 = V_166 ;
T_2 V_167 = 1 << 10 ;
struct V_134 * V_163 ;
V_163 = F_124 ( NULL , V_168 ) ;
if ( ! V_163 )
return 0 ;
F_120 ( V_163 ) ;
V_9 = F_125 ( L_33 , V_140 , V_167 , V_165 ,
F_97 ) ;
if ( ! V_9 )
return - V_79 ;
V_94 = V_9 ;
F_126 ( & V_169 , & V_170 ) ;
F_127 () ;
return F_128 ( & V_127 ) ;
}
