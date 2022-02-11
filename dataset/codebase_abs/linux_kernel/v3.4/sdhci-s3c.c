static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static T_1 F_3 ( T_1 V_4 )
{
V_4 &= V_5 ;
V_4 >>= V_6 ;
return V_4 ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_8 = F_5 ( V_3 -> V_9 + V_10 ) ;
if ( F_3 ( V_8 ) != V_7 -> V_11 ) {
F_6 ( & V_7 -> V_12 -> V_13 , L_1 ) ;
V_8 &= ~ V_5 ;
V_8 |= V_7 -> V_11 << V_6 ;
F_7 ( V_8 , V_3 -> V_9 + V_10 ) ;
}
}
static unsigned int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_14 * V_15 ;
unsigned int V_16 , V_17 ;
int V_14 ;
F_4 ( V_3 ) ;
for ( V_17 = 0 , V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
V_15 = V_7 -> V_19 [ V_14 ] ;
if ( ! V_15 )
continue;
V_16 = F_9 ( V_15 ) ;
if ( V_16 > V_17 )
V_17 = V_16 ;
}
return V_17 ;
}
static unsigned int F_10 ( struct V_1 * V_7 ,
unsigned int V_20 ,
unsigned int V_21 )
{
unsigned long V_16 ;
struct V_14 * V_22 = V_7 -> V_19 [ V_20 ] ;
int div ;
if ( ! V_22 )
return V_23 ;
if ( V_7 -> V_3 -> V_24 & V_25 ) {
V_16 = F_11 ( V_22 , V_21 ) ;
return V_21 - V_16 ;
}
V_16 = F_9 ( V_22 ) ;
for ( div = 1 ; div < 256 ; div *= 2 ) {
if ( ( V_16 / div ) <= V_21 )
break;
}
F_6 ( & V_7 -> V_12 -> V_13 , L_2 ,
V_20 , V_16 , V_21 , V_16 / div ) ;
return ( V_21 - ( V_16 / div ) ) ;
}
static void F_12 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_26 = V_23 ;
unsigned int V_27 ;
int V_28 = 0 ;
int V_20 ;
T_1 V_29 ;
if ( clock == 0 )
return;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
V_27 = F_10 ( V_7 , V_20 , clock ) ;
if ( V_27 < V_26 ) {
V_26 = V_27 ;
V_28 = V_20 ;
}
}
F_6 ( & V_7 -> V_12 -> V_13 ,
L_3 ,
V_28 , clock , V_26 ) ;
if ( V_7 -> V_11 != V_28 ) {
struct V_14 * V_14 = V_7 -> V_19 [ V_28 ] ;
F_13 ( 0 , V_3 -> V_9 + V_30 ) ;
V_7 -> V_11 = V_28 ;
V_3 -> V_31 = F_9 ( V_14 ) ;
V_29 = F_5 ( V_3 -> V_9 + V_10 ) ;
V_29 &= ~ V_5 ;
V_29 |= V_28 << V_6 ;
F_7 ( V_29 , V_3 -> V_9 + V_10 ) ;
}
F_7 ( V_32 ,
V_3 -> V_9 + V_33 ) ;
V_29 = F_5 ( V_3 -> V_9 + V_10 ) ;
V_29 |= ( V_34 |
V_35 |
V_36 |
V_37 |
V_38 ) ;
F_7 ( V_29 , V_3 -> V_9 + V_10 ) ;
V_29 = ( V_39 | V_40 ) ;
if ( clock < 25 * 1000000 )
V_29 |= ( V_41 | V_42 ) ;
F_7 ( V_29 , V_3 -> V_9 + V_43 ) ;
}
static unsigned int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_27 , V_44 = V_23 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
V_27 = F_10 ( V_7 , V_20 , 0 ) ;
if ( V_27 == V_23 )
continue;
if ( - V_27 < V_44 )
V_44 = - V_27 ;
}
return V_44 ;
}
static unsigned int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_11 ( V_7 -> V_19 [ V_7 -> V_11 ] , V_23 ) ;
}
static unsigned int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_11 ( V_7 -> V_19 [ V_7 -> V_11 ] , 400000 ) ;
}
static void F_17 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_45 ;
T_2 V_14 = 0 ;
if ( clock == 0 )
return;
F_12 ( V_3 , clock ) ;
F_18 ( V_7 -> V_19 [ V_7 -> V_11 ] , clock ) ;
V_3 -> clock = clock ;
V_14 = V_46 ;
F_19 ( V_3 , V_14 , V_30 ) ;
V_45 = 20 ;
while ( ! ( ( V_14 = F_20 ( V_3 , V_30 ) )
& V_47 ) ) {
if ( V_45 == 0 ) {
F_21 ( V_48 L_4
L_5 , F_22 ( V_3 -> V_49 ) ) ;
return;
}
V_45 -- ;
F_23 ( 1 ) ;
}
V_14 |= V_50 ;
F_19 ( V_3 , V_14 , V_30 ) ;
}
static int F_24 ( struct V_2 * V_3 , int V_51 )
{
T_3 V_29 ;
V_29 = F_25 ( V_3 , V_52 ) ;
switch ( V_51 ) {
case V_53 :
V_29 |= V_54 ;
V_29 &= ~ V_55 ;
break;
case V_56 :
V_29 |= V_55 ;
V_29 &= ~ V_54 ;
break;
default:
V_29 &= ~ V_55 ;
V_29 &= ~ V_54 ;
break;
}
F_26 ( V_3 , V_29 , V_52 ) ;
return 0 ;
}
static void F_27 ( struct V_57 * V_13 , int V_58 )
{
struct V_2 * V_3 = F_28 ( V_13 ) ;
unsigned long V_59 ;
if ( V_3 ) {
F_29 ( & V_3 -> V_60 , V_59 ) ;
if ( V_58 ) {
F_6 ( & V_13 -> V_13 , L_6 ) ;
V_3 -> V_59 &= ~ V_61 ;
V_3 -> V_24 |= V_62 ;
} else {
F_6 ( & V_13 -> V_13 , L_7 ) ;
V_3 -> V_59 |= V_61 ;
V_3 -> V_24 &= ~ V_62 ;
}
F_30 ( & V_3 -> V_63 ) ;
F_31 ( & V_3 -> V_60 , V_59 ) ;
}
}
static T_4 F_32 ( int V_64 , void * V_65 )
{
struct V_1 * V_66 = V_65 ;
int V_67 = F_33 ( V_66 -> V_68 ) ;
if ( V_66 -> V_69 -> V_70 )
V_67 = ! V_67 ;
F_27 ( V_66 -> V_12 , V_67 ) ;
return V_71 ;
}
static void F_34 ( struct V_1 * V_66 )
{
struct V_72 * V_69 = V_66 -> V_69 ;
struct V_73 * V_13 = & V_66 -> V_12 -> V_13 ;
if ( F_35 ( V_69 -> V_68 , L_8 ) == 0 ) {
V_66 -> V_68 = V_69 -> V_68 ;
V_66 -> V_74 = F_36 ( V_69 -> V_68 ) ;
if ( V_66 -> V_74 &&
F_37 ( V_66 -> V_74 , NULL ,
F_32 ,
V_75 | V_76 ,
F_38 ( V_13 ) , V_66 ) == 0 ) {
int V_67 = F_33 ( V_66 -> V_68 ) ;
if ( V_69 -> V_70 )
V_67 = ! V_67 ;
F_27 ( V_66 -> V_12 , V_67 ) ;
} else {
F_39 ( V_13 , L_9 ) ;
V_66 -> V_74 = 0 ;
}
} else {
F_40 ( V_13 , L_10 ) ;
}
}
static inline struct V_77 * F_41 (
struct V_57 * V_12 )
{
return (struct V_77 * )
F_42 ( V_12 ) -> V_78 ;
}
static int T_5 F_43 ( struct V_57 * V_12 )
{
struct V_72 * V_69 ;
struct V_77 * V_79 ;
struct V_73 * V_13 = & V_12 -> V_13 ;
struct V_2 * V_3 ;
struct V_1 * V_66 ;
struct V_80 * V_81 ;
int V_82 , V_64 , V_83 , V_84 ;
if ( ! V_12 -> V_13 . V_85 ) {
F_40 ( V_13 , L_11 ) ;
return - V_86 ;
}
V_64 = F_44 ( V_12 , 0 ) ;
if ( V_64 < 0 ) {
F_40 ( V_13 , L_12 ) ;
return V_64 ;
}
V_3 = F_45 ( V_13 , sizeof( struct V_1 ) ) ;
if ( F_46 ( V_3 ) ) {
F_40 ( V_13 , L_13 ) ;
return F_47 ( V_3 ) ;
}
V_69 = F_48 ( & V_12 -> V_13 , sizeof( * V_69 ) , V_87 ) ;
if ( ! V_69 ) {
V_82 = - V_88 ;
goto V_89;
}
memcpy ( V_69 , V_12 -> V_13 . V_85 , sizeof( * V_69 ) ) ;
V_79 = F_41 ( V_12 ) ;
V_66 = F_2 ( V_3 ) ;
V_66 -> V_3 = V_3 ;
V_66 -> V_12 = V_12 ;
V_66 -> V_69 = V_69 ;
V_66 -> V_68 = - 1 ;
F_49 ( V_12 , V_3 ) ;
V_66 -> V_90 = F_50 ( V_13 , L_14 ) ;
if ( F_46 ( V_66 -> V_90 ) ) {
F_40 ( V_13 , L_15 ) ;
V_82 = F_47 ( V_66 -> V_90 ) ;
goto V_89;
}
F_51 ( V_66 -> V_90 ) ;
for ( V_84 = 0 , V_83 = 0 ; V_83 < V_18 ; V_83 ++ ) {
struct V_14 * V_14 ;
char V_91 [ 14 ] ;
snprintf ( V_91 , 14 , L_16 , V_83 ) ;
V_14 = F_50 ( V_13 , V_91 ) ;
if ( F_46 ( V_14 ) ) {
continue;
}
V_84 ++ ;
V_66 -> V_19 [ V_83 ] = V_14 ;
V_66 -> V_11 = V_83 ;
F_51 ( V_14 ) ;
F_52 ( V_13 , L_17 ,
V_83 , V_91 , F_9 ( V_14 ) ) ;
}
if ( V_84 == 0 ) {
F_40 ( V_13 , L_18 ) ;
V_82 = - V_86 ;
goto V_92;
}
V_81 = F_53 ( V_12 , V_93 , 0 ) ;
V_3 -> V_9 = F_54 ( & V_12 -> V_13 , V_81 ) ;
if ( ! V_3 -> V_9 ) {
F_40 ( V_13 , L_19 ) ;
V_82 = - V_94 ;
goto V_95;
}
if ( V_69 -> V_96 )
V_69 -> V_96 ( V_12 , V_69 -> V_97 ) ;
V_3 -> V_98 = L_20 ;
V_3 -> V_99 = & V_100 ;
V_3 -> V_24 = 0 ;
V_3 -> V_64 = V_64 ;
V_3 -> V_24 |= V_101 ;
V_3 -> V_24 |= V_102 ;
if ( V_79 )
V_3 -> V_24 |= V_79 -> V_103 ;
#ifndef F_55
V_3 -> V_24 |= V_104 ;
#endif
V_3 -> V_24 |= V_105 ;
V_3 -> V_24 |= V_106 ;
V_3 -> V_24 |= V_107 ;
if ( V_69 -> V_108 == V_109 ||
V_69 -> V_108 == V_110 )
V_3 -> V_24 |= V_62 ;
if ( V_69 -> V_108 == V_110 )
V_3 -> V_49 -> V_111 = V_112 ;
switch ( V_69 -> V_97 ) {
case 8 :
V_3 -> V_49 -> V_111 |= V_113 ;
case 4 :
V_3 -> V_49 -> V_111 |= V_114 ;
break;
}
if ( V_69 -> V_115 )
V_3 -> V_49 -> V_115 |= V_69 -> V_115 ;
V_3 -> V_24 |= ( V_116 |
V_117 ) ;
V_3 -> V_24 |= V_118 ;
if ( V_3 -> V_24 & V_25 ) {
V_100 . V_119 = F_17 ;
V_100 . V_120 = F_16 ;
V_100 . V_121 = F_15 ;
}
if ( V_69 -> V_122 )
V_3 -> V_49 -> V_111 |= V_69 -> V_122 ;
if ( V_69 -> V_123 )
V_3 -> V_49 -> V_124 |= V_69 -> V_123 ;
F_56 ( & V_12 -> V_13 ) ;
F_57 ( & V_12 -> V_13 , 50 ) ;
F_58 ( & V_12 -> V_13 ) ;
F_59 ( & V_12 -> V_13 , 1 ) ;
V_82 = F_60 ( V_3 ) ;
if ( V_82 ) {
F_40 ( V_13 , L_21 ) ;
F_61 ( & V_12 -> V_13 ) ;
F_62 ( & V_12 -> V_13 ) ;
goto V_95;
}
if ( V_69 -> V_108 == V_125 && V_69 -> V_126 )
V_69 -> V_126 ( & F_27 ) ;
if ( V_69 -> V_108 == V_127 &&
F_63 ( V_69 -> V_68 ) )
F_34 ( V_66 ) ;
return 0 ;
V_95:
for ( V_83 = 0 ; V_83 < V_18 ; V_83 ++ ) {
if ( V_66 -> V_19 [ V_83 ] ) {
F_64 ( V_66 -> V_19 [ V_83 ] ) ;
F_65 ( V_66 -> V_19 [ V_83 ] ) ;
}
}
V_92:
F_64 ( V_66 -> V_90 ) ;
F_65 ( V_66 -> V_90 ) ;
V_89:
F_66 ( V_3 ) ;
return V_82 ;
}
static int T_6 F_67 ( struct V_57 * V_12 )
{
struct V_72 * V_69 = V_12 -> V_13 . V_85 ;
struct V_2 * V_3 = F_28 ( V_12 ) ;
struct V_1 * V_66 = F_2 ( V_3 ) ;
int V_83 ;
if ( V_69 -> V_108 == V_125 && V_69 -> V_128 )
V_69 -> V_128 ( & F_27 ) ;
if ( V_66 -> V_74 )
F_68 ( V_66 -> V_74 , V_66 ) ;
if ( F_63 ( V_66 -> V_68 ) )
F_69 ( V_66 -> V_68 ) ;
F_70 ( V_3 , 1 ) ;
F_71 ( & V_12 -> V_13 ) ;
for ( V_83 = 0 ; V_83 < 3 ; V_83 ++ ) {
if ( V_66 -> V_19 [ V_83 ] ) {
F_64 ( V_66 -> V_19 [ V_83 ] ) ;
F_65 ( V_66 -> V_19 [ V_83 ] ) ;
}
}
F_64 ( V_66 -> V_90 ) ;
F_65 ( V_66 -> V_90 ) ;
F_66 ( V_3 ) ;
F_49 ( V_12 , NULL ) ;
return 0 ;
}
static int F_72 ( struct V_73 * V_13 )
{
struct V_2 * V_3 = F_73 ( V_13 ) ;
return F_74 ( V_3 ) ;
}
static int F_75 ( struct V_73 * V_13 )
{
struct V_2 * V_3 = F_73 ( V_13 ) ;
return F_76 ( V_3 ) ;
}
static int F_77 ( struct V_73 * V_13 )
{
struct V_2 * V_3 = F_73 ( V_13 ) ;
return F_78 ( V_3 ) ;
}
static int F_79 ( struct V_73 * V_13 )
{
struct V_2 * V_3 = F_73 ( V_13 ) ;
return F_80 ( V_3 ) ;
}
