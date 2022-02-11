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
static void F_49 ( struct V_5 * V_6 , T_3 V_95 ,
unsigned long V_96 , int V_97 )
{
T_2 V_98 = V_97 * sizeof( T_1 ) ;
F_50 ( V_6 , V_95 , V_96 , V_98 , V_99 ) ;
}
static void F_51 ( struct V_7 * V_8 , T_1 * V_100 , bool V_101 )
{
T_3 V_102 ;
if ( V_100 ) {
if ( V_101 ) {
V_102 = F_14 ( V_100 ) ;
F_52 ( V_8 -> V_6 , V_102 , V_103 ,
V_99 ) ;
}
F_53 ( V_104 , V_100 ) ;
}
}
static T_1 * F_54 ( struct V_7 * V_8 , T_1 * V_31 ,
T_3 * V_102 , T_1 V_62 )
{
T_1 * V_100 ;
unsigned long V_96 = F_55 ( V_62 ) * sizeof( V_62 ) ;
if ( * V_31 )
goto V_105;
F_56 ( & V_8 -> V_106 ) ;
V_100 = F_57 ( V_104 , V_83 ) ;
F_58 ( & V_8 -> V_106 ) ;
if ( ! * V_31 ) {
if ( ! V_100 )
return F_36 ( - V_84 ) ;
* V_102 = F_59 ( V_8 -> V_6 , V_100 , V_103 ,
V_99 ) ;
if ( F_60 ( V_8 -> V_6 , * V_102 ) ) {
F_20 ( V_8 -> V_6 , L_10 ) ;
F_51 ( V_8 , V_100 , false ) ;
return F_36 ( - V_84 ) ;
}
if ( F_61 ( * V_102 != F_14 ( V_100 ) ) ) {
F_20 ( V_8 -> V_6 , L_11 ) ;
F_52 ( V_8 -> V_6 , * V_102 , V_103 ,
V_99 ) ;
F_51 ( V_8 , V_100 , false ) ;
return F_36 ( - V_84 ) ;
}
* V_31 = F_14 ( V_100 ) | V_107 ;
F_49 ( V_8 -> V_6 , V_8 -> V_108 , V_96 , 1 ) ;
F_62 ( V_8 -> V_6 , L_12 , V_13 , V_100 ) ;
} else {
F_51 ( V_8 , V_100 , false ) ;
}
V_105:
V_100 = F_63 ( V_31 , V_62 ) ;
* V_102 = F_14 ( V_100 ) ;
F_62 ( V_8 -> V_6 ,
L_13 ,
V_13 , V_62 , V_31 , * V_31 , V_100 , * V_100 ) ;
return V_100 ;
}
static int F_64 ( struct V_7 * V_8 , T_1 V_62 , T_1 V_30 , T_1 V_109 )
{
T_1 * V_31 = F_65 ( V_8 , V_62 ) ;
unsigned long V_96 = F_55 ( V_62 ) * sizeof( V_62 ) ;
if ( ( V_62 | V_30 ) & ~ V_110 ) {
F_20 ( V_8 -> V_6 , L_14 ,
V_13 , V_62 , V_30 , V_111 ) ;
return - V_33 ;
}
* V_31 = ( V_30 & V_110 ) | V_109 | V_112 ;
F_49 ( V_8 -> V_6 , V_8 -> V_108 , V_96 , 1 ) ;
return 0 ;
}
static int F_66 ( struct V_7 * V_8 , T_1 V_62 , T_1 V_30 , T_1 V_109 )
{
T_1 * V_31 = F_65 ( V_8 , V_62 ) ;
unsigned long V_96 = F_55 ( V_62 ) * sizeof( V_62 ) ;
int V_11 ;
if ( ( V_62 | V_30 ) & ~ V_113 ) {
F_20 ( V_8 -> V_6 , L_14 ,
V_13 , V_62 , V_30 , V_114 ) ;
return - V_33 ;
}
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
* ( V_31 + V_11 ) = ( V_30 & V_113 ) | V_109 | V_115 ;
F_49 ( V_8 -> V_6 , V_8 -> V_108 , V_96 , 16 ) ;
return 0 ;
}
static int F_67 ( struct V_7 * V_8 , T_1 V_62 , T_1 V_30 , T_1 V_109 )
{
T_1 * V_31 = F_65 ( V_8 , V_62 ) ;
T_3 V_102 ;
T_1 * V_100 = F_54 ( V_8 , V_31 , & V_102 , V_62 ) ;
unsigned long V_96 = F_68 ( V_62 ) * sizeof( V_62 ) ;
if ( F_42 ( V_100 ) )
return F_43 ( V_100 ) ;
* V_100 = ( V_30 & V_116 ) | V_109 | V_117 ;
F_49 ( V_8 -> V_6 , V_102 , V_96 , 1 ) ;
F_62 ( V_8 -> V_6 , L_15 ,
V_13 , V_62 , V_30 , V_100 , * V_100 ) ;
return 0 ;
}
static int F_69 ( struct V_7 * V_8 , T_1 V_62 , T_1 V_30 , T_1 V_109 )
{
T_1 * V_31 = F_65 ( V_8 , V_62 ) ;
T_3 V_102 ;
T_1 * V_100 = F_54 ( V_8 , V_31 , & V_102 , V_62 ) ;
unsigned long V_96 = F_68 ( V_62 ) * sizeof( V_62 ) ;
int V_11 ;
if ( ( V_62 | V_30 ) & ~ V_118 ) {
F_20 ( V_8 -> V_6 , L_14 ,
V_13 , V_62 , V_30 , V_119 ) ;
return - V_33 ;
}
if ( F_42 ( V_100 ) )
return F_43 ( V_100 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
* ( V_100 + V_11 ) = ( V_30 & V_118 ) | V_109 | V_120 ;
F_49 ( V_8 -> V_6 , V_102 , V_96 , 16 ) ;
return 0 ;
}
static int
F_70 ( struct V_7 * V_8 , struct V_53 * V_54 )
{
int (* F_71)( struct V_7 * , T_1 , T_1 , T_1 );
T_1 V_109 ;
int V_40 ;
if ( ! V_8 || ! V_54 )
return - V_33 ;
switch ( V_54 -> V_59 ) {
case V_121 :
F_71 = F_66 ;
break;
case V_122 :
F_71 = F_64 ;
break;
case V_61 :
F_71 = F_69 ;
break;
case V_60 :
F_71 = F_67 ;
break;
default:
F_71 = NULL ;
break;
}
if ( F_61 ( ! F_71 ) )
return - V_33 ;
V_109 = F_26 ( V_54 ) ;
F_58 ( & V_8 -> V_106 ) ;
V_40 = F_71 ( V_8 , V_54 -> V_62 , V_54 -> V_30 , V_109 ) ;
F_56 ( & V_8 -> V_106 ) ;
return V_40 ;
}
static int
F_72 ( struct V_7 * V_8 , struct V_53 * V_54 )
{
int V_40 ;
F_46 ( V_8 , V_54 -> V_62 ) ;
V_40 = F_70 ( V_8 , V_54 ) ;
if ( ! V_40 )
F_45 ( V_8 , V_54 ) ;
return V_40 ;
}
static void
F_73 ( struct V_7 * V_8 , T_1 V_62 , T_1 * * V_123 , T_1 * * V_124 )
{
T_1 * V_31 , * V_100 = NULL ;
V_31 = F_65 ( V_8 , V_62 ) ;
if ( ! * V_31 )
goto V_90;
if ( F_74 ( * V_31 ) )
V_100 = F_63 ( V_31 , V_62 ) ;
V_90:
* V_123 = V_31 ;
* V_124 = V_100 ;
}
static T_2 F_75 ( struct V_7 * V_8 , T_1 V_62 )
{
T_2 V_93 ;
T_1 * V_31 = F_65 ( V_8 , V_62 ) ;
int V_125 = 1 ;
T_3 V_102 ;
unsigned long V_126 = F_55 ( V_62 ) * sizeof( V_62 ) ;
unsigned long V_127 = F_68 ( V_62 ) * sizeof( V_62 ) ;
if ( ! * V_31 )
return 0 ;
if ( F_74 ( * V_31 ) ) {
int V_11 ;
T_1 * V_100 = F_63 ( V_31 , V_62 ) ;
V_93 = V_128 ;
if ( * V_100 & V_120 ) {
V_125 *= 16 ;
V_100 = F_63 ( V_31 , ( V_62 & V_118 ) ) ;
}
V_93 *= V_125 ;
memset ( V_100 , 0 , V_125 * sizeof( * V_100 ) ) ;
V_102 = F_14 ( V_100 ) ;
F_49 ( V_8 -> V_6 , V_102 , V_127 , V_125 ) ;
V_100 = F_63 ( V_31 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_129 ; V_11 ++ )
if ( V_100 [ V_11 ] )
goto V_90;
F_51 ( V_8 , V_100 , true ) ;
V_125 = 1 ;
} else {
V_93 = V_130 ;
if ( ( * V_31 & V_115 ) == V_115 ) {
V_125 *= 16 ;
V_31 = F_65 ( V_8 , ( V_62 & V_113 ) ) ;
}
V_93 *= V_125 ;
}
memset ( V_31 , 0 , V_125 * sizeof( * V_31 ) ) ;
F_49 ( V_8 -> V_6 , V_8 -> V_108 , V_126 , V_125 ) ;
V_90:
return V_93 ;
}
static T_2 F_76 ( struct V_7 * V_8 , T_1 V_62 )
{
T_2 V_93 ;
F_58 ( & V_8 -> V_106 ) ;
V_93 = F_75 ( V_8 , V_62 ) ;
F_46 ( V_8 , V_62 ) ;
F_56 ( & V_8 -> V_106 ) ;
return V_93 ;
}
static void F_77 ( struct V_7 * V_8 )
{
unsigned long V_96 ;
int V_11 ;
F_58 ( & V_8 -> V_106 ) ;
for ( V_11 = 0 ; V_11 < V_131 ; V_11 ++ ) {
T_1 V_62 ;
T_1 * V_31 ;
V_62 = V_11 << V_132 ;
V_31 = F_65 ( V_8 , V_62 ) ;
V_96 = F_55 ( V_62 ) * sizeof( V_62 ) ;
if ( ! * V_31 )
continue;
if ( F_74 ( * V_31 ) )
F_51 ( V_8 , F_63 ( V_31 , 0 ) , true ) ;
* V_31 = 0 ;
F_49 ( V_8 -> V_6 , V_8 -> V_108 , V_96 , 1 ) ;
}
F_48 ( V_8 ) ;
F_56 ( & V_8 -> V_106 ) ;
}
static T_4 F_78 ( int V_133 , void * V_134 )
{
T_1 V_62 , V_135 ;
T_1 * V_31 , * V_100 ;
struct V_7 * V_8 = V_134 ;
struct V_2 * V_4 = V_8 -> V_4 ;
struct V_1 * V_136 = F_1 ( V_4 ) ;
if ( ! V_136 -> V_137 )
return V_138 ;
V_135 = F_27 ( V_8 , & V_62 ) ;
if ( V_135 == 0 )
return V_139 ;
if ( ! F_79 ( V_4 , V_8 -> V_6 , V_62 , 0 ) )
return V_139 ;
F_8 ( V_8 , 0 , V_25 ) ;
V_31 = F_65 ( V_8 , V_62 ) ;
if ( ! F_74 ( * V_31 ) ) {
F_20 ( V_8 -> V_6 , L_16 ,
V_8 -> V_35 , V_135 , V_62 , V_31 , * V_31 ) ;
return V_138 ;
}
V_100 = F_63 ( V_31 , V_62 ) ;
F_20 ( V_8 -> V_6 , L_17 ,
V_8 -> V_35 , V_135 , V_62 , V_31 , * V_31 , V_100 , * V_100 ) ;
return V_138 ;
}
static int F_80 ( struct V_7 * V_8 , T_1 * V_31 )
{
int V_40 ;
F_58 ( & V_8 -> V_140 ) ;
V_8 -> V_108 = F_59 ( V_8 -> V_6 , V_31 , V_141 ,
V_99 ) ;
if ( F_60 ( V_8 -> V_6 , V_8 -> V_108 ) ) {
F_20 ( V_8 -> V_6 , L_18 ) ;
V_40 = - V_84 ;
goto V_142;
}
V_8 -> V_31 = V_31 ;
V_40 = F_17 ( V_8 ) ;
if ( V_40 )
goto V_142;
F_48 ( V_8 ) ;
F_56 ( & V_8 -> V_140 ) ;
F_6 ( V_8 -> V_6 , L_19 , V_13 , V_8 -> V_35 ) ;
return 0 ;
V_142:
F_56 ( & V_8 -> V_140 ) ;
return V_40 ;
}
static void F_81 ( struct V_7 * V_8 )
{
if ( ! V_8 || F_42 ( V_8 ) )
return;
F_58 ( & V_8 -> V_140 ) ;
F_52 ( V_8 -> V_6 , V_8 -> V_108 , V_141 ,
V_99 ) ;
F_22 ( V_8 ) ;
V_8 -> V_108 = 0 ;
V_8 -> V_31 = NULL ;
F_56 ( & V_8 -> V_140 ) ;
F_6 ( V_8 -> V_6 , L_19 , V_13 , V_8 -> V_35 ) ;
}
static int F_82 ( struct V_41 * V_42 ,
struct V_7 * V_8 )
{
struct V_143 * V_144 = V_42 -> V_6 . V_145 ;
int V_146 ;
if ( ! F_83 ( V_144 , L_20 ) )
return 0 ;
if ( ! F_84 ( V_144 , L_21 ) ) {
F_20 ( & V_42 -> V_6 , L_22 ) ;
return - V_33 ;
}
V_8 -> V_17 =
F_85 ( V_144 , L_21 ) ;
if ( F_42 ( V_8 -> V_17 ) ) {
V_146 = F_43 ( V_8 -> V_17 ) ;
return V_146 ;
}
if ( F_86 ( V_144 , L_21 , 1 ,
& V_8 -> V_18 ) ) {
F_20 ( & V_42 -> V_6 , L_23 ) ;
return - V_33 ;
}
if ( V_8 -> V_18 != 0 && V_8 -> V_18 != 1 ) {
F_20 ( & V_42 -> V_6 , L_24 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_87 ( struct V_41 * V_42 )
{
int V_40 = - V_147 ;
int V_133 ;
struct V_7 * V_8 ;
struct V_148 * V_149 ;
struct V_143 * V_150 = V_42 -> V_6 . V_145 ;
if ( ! V_150 ) {
F_88 ( L_25 , V_13 ) ;
return - V_147 ;
}
V_8 = F_89 ( & V_42 -> V_6 , sizeof( * V_8 ) + V_12 , V_83 ) ;
if ( ! V_8 )
return - V_84 ;
V_8 -> V_35 = F_90 ( & V_42 -> V_6 ) ;
V_8 -> V_88 = 32 ;
V_40 = F_91 ( V_150 , L_26 , & V_8 -> V_88 ) ;
if ( V_40 && V_40 != - V_33 )
return V_40 ;
if ( V_8 -> V_88 != 32 && V_8 -> V_88 != 8 )
return - V_33 ;
if ( F_92 ( V_150 , L_27 , NULL ) )
V_8 -> V_37 = V_38 ;
V_8 -> V_6 = & V_42 -> V_6 ;
V_8 -> V_10 = ( void * ) V_8 + sizeof( * V_8 ) ;
F_93 ( & V_8 -> V_140 ) ;
F_93 ( & V_8 -> V_106 ) ;
V_149 = F_94 ( V_42 , V_151 , 0 ) ;
V_8 -> V_152 = F_95 ( V_8 -> V_6 , V_149 ) ;
if ( F_42 ( V_8 -> V_152 ) )
return F_43 ( V_8 -> V_152 ) ;
V_40 = F_82 ( V_42 , V_8 ) ;
if ( V_40 )
return V_40 ;
V_133 = F_96 ( V_42 , 0 ) ;
if ( V_133 < 0 )
return - V_147 ;
V_40 = F_97 ( V_8 -> V_6 , V_133 , F_78 , V_153 ,
F_90 ( V_8 -> V_6 ) , V_8 ) ;
if ( V_40 < 0 )
return V_40 ;
F_98 ( V_42 , V_8 ) ;
V_8 -> V_154 = F_99 () ;
if ( F_42 ( V_8 -> V_154 ) )
return F_43 ( V_8 -> V_154 ) ;
V_40 = F_100 ( & V_8 -> V_155 , V_8 -> V_6 , NULL , V_8 -> V_35 ) ;
if ( V_40 )
goto V_156;
F_101 ( & V_8 -> V_155 , & V_157 ) ;
V_40 = F_102 ( & V_8 -> V_155 ) ;
if ( V_40 )
goto V_158;
F_103 ( V_8 -> V_6 ) ;
F_104 ( V_8 -> V_6 ) ;
F_105 ( V_8 ) ;
F_15 ( & V_42 -> V_6 , L_28 , V_8 -> V_35 ) ;
return 0 ;
V_158:
F_106 ( & V_8 -> V_155 ) ;
V_156:
F_107 ( V_8 -> V_154 ) ;
return V_40 ;
}
static int F_108 ( struct V_41 * V_42 )
{
struct V_7 * V_8 = F_109 ( V_42 ) ;
F_107 ( V_8 -> V_154 ) ;
V_8 -> V_154 = NULL ;
F_106 ( & V_8 -> V_155 ) ;
F_110 ( & V_8 -> V_155 ) ;
F_111 ( V_8 ) ;
F_112 ( V_8 -> V_6 ) ;
F_15 ( & V_42 -> V_6 , L_29 , V_8 -> V_35 ) ;
return 0 ;
}
static T_1 F_113 ( struct V_53 * V_54 , T_1 V_62 , T_1 V_30 , int V_59 )
{
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_62 = V_62 ;
V_54 -> V_30 = V_30 ;
V_54 -> V_87 = V_77 ;
V_54 -> V_59 = V_59 ;
V_54 -> V_57 = V_159 ;
V_54 -> V_58 = V_160 ;
V_54 -> V_56 = 0 ;
return F_47 ( V_54 -> V_59 ) ;
}
static int F_114 ( struct V_2 * V_4 , unsigned long V_62 ,
T_5 V_30 , T_2 V_93 , int V_109 )
{
struct V_1 * V_136 = F_1 ( V_4 ) ;
struct V_7 * V_161 = V_136 -> V_137 ;
struct V_5 * V_6 = V_161 -> V_6 ;
struct V_53 V_54 ;
int V_162 ;
T_1 V_146 ;
V_162 = F_115 ( V_93 ) ;
if ( V_162 < 0 ) {
F_20 ( V_6 , L_30 , V_93 ) ;
return - V_33 ;
}
F_6 ( V_6 , L_31 , V_62 , & V_30 , V_93 ) ;
F_113 ( & V_54 , V_62 , V_30 , V_162 ) ;
V_146 = F_72 ( V_161 , & V_54 ) ;
if ( V_146 )
F_20 ( V_6 , L_32 , V_146 ) ;
return V_146 ;
}
static T_2 F_116 ( struct V_2 * V_4 , unsigned long V_62 ,
T_2 V_98 )
{
struct V_1 * V_136 = F_1 ( V_4 ) ;
struct V_7 * V_161 = V_136 -> V_137 ;
struct V_5 * V_6 = V_161 -> V_6 ;
F_6 ( V_6 , L_33 , V_62 , V_98 ) ;
return F_76 ( V_161 , V_62 ) ;
}
static int
F_117 ( struct V_2 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_136 = F_1 ( V_4 ) ;
struct V_163 * V_164 = V_6 -> V_165 . V_155 ;
struct V_7 * V_161 ;
int V_146 = 0 ;
if ( ! V_164 || ! V_164 -> V_137 ) {
F_20 ( V_6 , L_34 ) ;
return - V_33 ;
}
F_58 ( & V_136 -> V_166 ) ;
if ( V_136 -> V_137 ) {
F_20 ( V_6 , L_35 ) ;
V_146 = - V_89 ;
goto V_90;
}
V_161 = V_164 -> V_137 ;
V_146 = F_80 ( V_161 , V_136 -> V_167 ) ;
if ( V_146 ) {
F_20 ( V_6 , L_36 , V_146 ) ;
goto V_90;
}
V_136 -> V_137 = V_161 ;
V_136 -> V_6 = V_6 ;
V_161 -> V_4 = V_4 ;
V_90:
F_56 ( & V_136 -> V_166 ) ;
return V_146 ;
}
static void F_118 ( struct V_1 * V_136 ,
struct V_5 * V_6 )
{
struct V_7 * V_161 = F_4 ( V_6 ) ;
if ( V_136 -> V_137 != V_161 ) {
F_20 ( V_6 , L_37 ) ;
return;
}
F_77 ( V_161 ) ;
F_81 ( V_161 ) ;
V_136 -> V_137 = NULL ;
V_136 -> V_6 = NULL ;
V_161 -> V_4 = NULL ;
}
static void F_119 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_136 = F_1 ( V_4 ) ;
F_58 ( & V_136 -> V_166 ) ;
F_118 ( V_136 , V_6 ) ;
F_56 ( & V_136 -> V_166 ) ;
}
static struct V_2 * F_120 ( unsigned type )
{
struct V_1 * V_136 ;
if ( type != V_168 )
return NULL ;
V_136 = F_121 ( sizeof( * V_136 ) , V_83 ) ;
if ( ! V_136 )
goto V_90;
V_136 -> V_167 = F_121 ( V_141 , V_83 ) ;
if ( ! V_136 -> V_167 )
goto V_169;
if ( F_61 ( ! F_13 ( ( long ) V_136 -> V_167 , V_141 ) ) )
goto V_170;
F_93 ( & V_136 -> V_166 ) ;
V_136 -> V_4 . V_171 . V_172 = 0 ;
V_136 -> V_4 . V_171 . V_173 = ( 1ULL << 32 ) - 1 ;
V_136 -> V_4 . V_171 . V_174 = true ;
return & V_136 -> V_4 ;
V_170:
F_44 ( V_136 -> V_167 ) ;
V_169:
F_44 ( V_136 ) ;
V_90:
return NULL ;
}
static void F_122 ( struct V_2 * V_4 )
{
struct V_1 * V_136 = F_1 ( V_4 ) ;
if ( V_136 -> V_137 )
F_118 ( V_136 , V_136 -> V_6 ) ;
F_44 ( V_136 -> V_167 ) ;
F_44 ( V_136 ) ;
}
static T_5 F_123 ( struct V_2 * V_4 ,
T_3 V_62 )
{
struct V_1 * V_136 = F_1 ( V_4 ) ;
struct V_7 * V_161 = V_136 -> V_137 ;
struct V_5 * V_6 = V_161 -> V_6 ;
T_1 * V_175 , * V_176 ;
T_5 V_146 = 0 ;
F_73 ( V_161 , V_62 , & V_175 , & V_176 ) ;
if ( V_176 ) {
if ( F_124 ( * V_176 ) )
V_146 = F_125 ( * V_176 , V_62 , V_177 ) ;
else if ( F_126 ( * V_176 ) )
V_146 = F_125 ( * V_176 , V_62 , V_118 ) ;
else
F_20 ( V_6 , L_38 , * V_176 ,
( unsigned long long ) V_62 ) ;
} else {
if ( F_127 ( * V_175 ) )
V_146 = F_125 ( * V_175 , V_62 , V_110 ) ;
else if ( F_128 ( * V_175 ) )
V_146 = F_125 ( * V_175 , V_62 , V_113 ) ;
else
F_20 ( V_6 , L_39 , * V_175 ,
( unsigned long long ) V_62 ) ;
}
return V_146 ;
}
static int F_129 ( struct V_5 * V_6 )
{
struct V_163 * V_164 ;
struct V_7 * V_161 ;
struct V_178 * V_154 ;
struct V_143 * V_144 ;
struct V_41 * V_42 ;
int V_146 ;
if ( ! V_6 -> V_145 )
return 0 ;
V_144 = F_130 ( V_6 -> V_145 , L_40 , 0 ) ;
if ( ! V_144 )
return 0 ;
V_42 = F_131 ( V_144 ) ;
if ( F_61 ( ! V_42 ) ) {
F_132 ( V_144 ) ;
return - V_33 ;
}
V_161 = F_109 ( V_42 ) ;
if ( ! V_161 ) {
F_132 ( V_144 ) ;
return - V_33 ;
}
V_164 = F_121 ( sizeof( * V_164 ) , V_83 ) ;
if ( ! V_164 ) {
F_132 ( V_144 ) ;
return - V_84 ;
}
V_146 = F_133 ( & V_161 -> V_155 , V_6 ) ;
if ( V_146 ) {
F_44 ( V_164 ) ;
F_132 ( V_144 ) ;
return V_146 ;
}
V_164 -> V_137 = V_161 ;
V_6 -> V_165 . V_155 = V_164 ;
V_154 = F_134 ( V_6 ) ;
if ( F_42 ( V_154 ) ) {
F_135 ( & V_161 -> V_155 , V_6 ) ;
V_6 -> V_165 . V_155 = NULL ;
F_44 ( V_164 ) ;
return F_43 ( V_154 ) ;
}
F_107 ( V_154 ) ;
F_132 ( V_144 ) ;
return 0 ;
}
static void F_136 ( struct V_5 * V_6 )
{
struct V_163 * V_164 = V_6 -> V_165 . V_155 ;
if ( ! V_6 -> V_145 || ! V_164 )
return;
F_135 ( & V_164 -> V_137 -> V_155 , V_6 ) ;
F_137 ( V_6 ) ;
V_6 -> V_165 . V_155 = NULL ;
F_44 ( V_164 ) ;
}
static struct V_178 * F_138 ( struct V_5 * V_6 )
{
struct V_163 * V_164 = V_6 -> V_165 . V_155 ;
struct V_178 * V_154 = F_36 ( - V_33 ) ;
if ( V_164 -> V_137 )
V_154 = V_164 -> V_137 -> V_154 ;
return V_154 ;
}
static int T_6 F_139 ( void )
{
struct V_179 * V_9 ;
const unsigned long V_180 = V_181 ;
T_2 V_182 = 1 << 10 ;
struct V_143 * V_144 ;
int V_146 ;
V_144 = F_140 ( NULL , V_183 ) ;
if ( ! V_144 )
return 0 ;
F_132 ( V_144 ) ;
V_9 = F_141 ( L_41 , V_103 , V_182 , V_180 ,
NULL ) ;
if ( ! V_9 )
return - V_84 ;
V_104 = V_9 ;
F_142 () ;
V_146 = F_143 ( & V_184 ) ;
if ( V_146 ) {
F_88 ( L_42 , V_13 ) ;
goto V_185;
}
V_146 = F_144 ( & V_186 , & V_157 ) ;
if ( V_146 )
goto V_187;
return 0 ;
V_187:
F_145 ( & V_184 ) ;
V_185:
F_146 ( V_104 ) ;
return V_146 ;
}
