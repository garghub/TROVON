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
if ( V_7 -> V_24 -> V_25 ) {
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
if ( clock == 0 )
return;
F_12 ( V_3 , clock ) ;
F_18 ( V_7 -> V_19 [ V_7 -> V_11 ] , clock ) ;
V_3 -> clock = clock ;
}
static int F_19 ( struct V_2 * V_3 , int V_45 )
{
T_2 V_29 ;
V_29 = F_20 ( V_3 , V_46 ) ;
switch ( V_45 ) {
case V_47 :
V_29 |= V_48 ;
V_29 &= ~ V_49 ;
break;
case V_50 :
V_29 |= V_49 ;
V_29 &= ~ V_48 ;
break;
default:
V_29 &= ~ V_49 ;
V_29 &= ~ V_48 ;
break;
}
F_21 ( V_3 , V_29 , V_46 ) ;
return 0 ;
}
static void F_22 ( struct V_51 * V_13 , int V_52 )
{
struct V_2 * V_3 = F_23 ( V_13 ) ;
unsigned long V_53 ;
if ( V_3 ) {
F_24 ( & V_3 -> V_54 , V_53 ) ;
if ( V_52 ) {
F_6 ( & V_13 -> V_13 , L_4 ) ;
V_3 -> V_53 &= ~ V_55 ;
V_3 -> V_56 |= V_57 ;
} else {
F_6 ( & V_13 -> V_13 , L_5 ) ;
V_3 -> V_53 |= V_55 ;
V_3 -> V_56 &= ~ V_57 ;
}
F_25 ( & V_3 -> V_58 ) ;
F_26 ( & V_3 -> V_54 , V_53 ) ;
}
}
static T_3 F_27 ( int V_59 , void * V_60 )
{
struct V_1 * V_61 = V_60 ;
int V_62 = F_28 ( V_61 -> V_63 ) ;
if ( V_61 -> V_24 -> V_64 )
V_62 = ! V_62 ;
F_22 ( V_61 -> V_12 , V_62 ) ;
return V_65 ;
}
static void F_29 ( struct V_1 * V_61 )
{
struct V_66 * V_24 = V_61 -> V_24 ;
struct V_67 * V_13 = & V_61 -> V_12 -> V_13 ;
if ( F_30 ( V_24 -> V_63 , L_6 ) == 0 ) {
V_61 -> V_63 = V_24 -> V_63 ;
V_61 -> V_68 = F_31 ( V_24 -> V_63 ) ;
if ( V_61 -> V_68 &&
F_32 ( V_61 -> V_68 , NULL ,
F_27 ,
V_69 | V_70 ,
F_33 ( V_13 ) , V_61 ) == 0 ) {
int V_62 = F_28 ( V_61 -> V_63 ) ;
if ( V_24 -> V_64 )
V_62 = ! V_62 ;
F_22 ( V_61 -> V_12 , V_62 ) ;
} else {
F_34 ( V_13 , L_7 ) ;
V_61 -> V_68 = 0 ;
}
} else {
F_35 ( V_13 , L_8 ) ;
}
}
static int T_4 F_36 ( struct V_51 * V_12 )
{
struct V_66 * V_24 = V_12 -> V_13 . V_71 ;
struct V_67 * V_13 = & V_12 -> V_13 ;
struct V_2 * V_3 ;
struct V_1 * V_61 ;
struct V_72 * V_73 ;
int V_74 , V_59 , V_75 , V_76 ;
if ( ! V_24 ) {
F_35 ( V_13 , L_9 ) ;
return - V_77 ;
}
V_59 = F_37 ( V_12 , 0 ) ;
if ( V_59 < 0 ) {
F_35 ( V_13 , L_10 ) ;
return V_59 ;
}
V_73 = F_38 ( V_12 , V_78 , 0 ) ;
if ( ! V_73 ) {
F_35 ( V_13 , L_11 ) ;
return - V_77 ;
}
V_3 = F_39 ( V_13 , sizeof( struct V_1 ) ) ;
if ( F_40 ( V_3 ) ) {
F_35 ( V_13 , L_12 ) ;
return F_41 ( V_3 ) ;
}
V_61 = F_2 ( V_3 ) ;
V_61 -> V_3 = V_3 ;
V_61 -> V_12 = V_12 ;
V_61 -> V_24 = V_24 ;
V_61 -> V_63 = - 1 ;
F_42 ( V_12 , V_3 ) ;
V_61 -> V_79 = F_43 ( V_13 , L_13 ) ;
if ( F_40 ( V_61 -> V_79 ) ) {
F_35 ( V_13 , L_14 ) ;
V_74 = F_41 ( V_61 -> V_79 ) ;
goto V_80;
}
F_44 ( V_61 -> V_79 ) ;
for ( V_76 = 0 , V_75 = 0 ; V_75 < V_18 ; V_75 ++ ) {
struct V_14 * V_14 ;
char V_81 [ 14 ] ;
snprintf ( V_81 , 14 , L_15 , V_75 ) ;
V_14 = F_43 ( V_13 , V_81 ) ;
if ( F_40 ( V_14 ) ) {
continue;
}
V_76 ++ ;
V_61 -> V_19 [ V_75 ] = V_14 ;
V_61 -> V_11 = V_75 ;
F_44 ( V_14 ) ;
F_45 ( V_13 , L_16 ,
V_75 , V_81 , F_9 ( V_14 ) ) ;
}
if ( V_76 == 0 ) {
F_35 ( V_13 , L_17 ) ;
V_74 = - V_77 ;
goto V_82;
}
V_61 -> V_83 = F_46 ( V_73 -> V_84 , F_47 ( V_73 ) ,
F_48 ( V_3 -> V_85 ) ) ;
if ( ! V_61 -> V_83 ) {
F_35 ( V_13 , L_18 ) ;
V_74 = - V_86 ;
goto V_87;
}
V_3 -> V_9 = F_49 ( V_73 -> V_84 , F_47 ( V_73 ) ) ;
if ( ! V_3 -> V_9 ) {
F_35 ( V_13 , L_19 ) ;
V_74 = - V_86 ;
goto V_87;
}
if ( V_24 -> V_88 )
V_24 -> V_88 ( V_12 , V_24 -> V_89 ) ;
V_3 -> V_90 = L_20 ;
V_3 -> V_91 = & V_92 ;
V_3 -> V_56 = 0 ;
V_3 -> V_59 = V_59 ;
V_3 -> V_56 |= V_93 ;
V_3 -> V_56 |= V_94 ;
#ifndef F_50
V_3 -> V_56 |= V_95 ;
#endif
V_3 -> V_56 |= V_96 ;
V_3 -> V_56 |= V_97 ;
V_3 -> V_56 |= V_98 ;
if ( V_24 -> V_99 == V_100 ||
V_24 -> V_99 == V_101 )
V_3 -> V_56 |= V_57 ;
if ( V_24 -> V_99 == V_101 )
V_3 -> V_85 -> V_102 = V_103 ;
if ( V_24 -> V_104 )
V_3 -> V_85 -> V_102 |= V_24 -> V_104 ;
if ( V_24 -> V_105 )
V_3 -> V_85 -> V_105 |= V_24 -> V_105 ;
V_3 -> V_56 |= ( V_106 |
V_107 ) ;
V_3 -> V_56 |= V_108 ;
if ( V_24 -> V_25 ) {
V_92 . V_109 = F_17 ;
V_92 . V_110 = F_16 ;
V_92 . V_111 = F_15 ;
}
if ( V_24 -> V_104 )
V_3 -> V_85 -> V_102 |= V_24 -> V_104 ;
V_74 = F_51 ( V_3 ) ;
if ( V_74 ) {
F_35 ( V_13 , L_21 ) ;
goto V_112;
}
if ( V_24 -> V_99 == V_113 && V_24 -> V_114 )
V_24 -> V_114 ( & F_22 ) ;
if ( V_24 -> V_99 == V_115 &&
F_52 ( V_24 -> V_63 ) )
F_29 ( V_61 ) ;
return 0 ;
V_112:
F_53 ( V_61 -> V_83 ) ;
F_54 ( V_61 -> V_83 ) ;
V_87:
for ( V_75 = 0 ; V_75 < V_18 ; V_75 ++ ) {
if ( V_61 -> V_19 [ V_75 ] ) {
F_55 ( V_61 -> V_19 [ V_75 ] ) ;
F_56 ( V_61 -> V_19 [ V_75 ] ) ;
}
}
V_82:
F_55 ( V_61 -> V_79 ) ;
F_56 ( V_61 -> V_79 ) ;
V_80:
F_57 ( V_3 ) ;
return V_74 ;
}
static int T_5 F_58 ( struct V_51 * V_12 )
{
struct V_66 * V_24 = V_12 -> V_13 . V_71 ;
struct V_2 * V_3 = F_23 ( V_12 ) ;
struct V_1 * V_61 = F_2 ( V_3 ) ;
int V_75 ;
if ( V_24 -> V_99 == V_113 && V_24 -> V_116 )
V_24 -> V_116 ( & F_22 ) ;
if ( V_61 -> V_68 )
F_59 ( V_61 -> V_68 , V_61 ) ;
if ( F_52 ( V_61 -> V_63 ) )
F_60 ( V_61 -> V_63 ) ;
F_61 ( V_3 , 1 ) ;
for ( V_75 = 0 ; V_75 < 3 ; V_75 ++ ) {
if ( V_61 -> V_19 [ V_75 ] ) {
F_55 ( V_61 -> V_19 [ V_75 ] ) ;
F_56 ( V_61 -> V_19 [ V_75 ] ) ;
}
}
F_55 ( V_61 -> V_79 ) ;
F_56 ( V_61 -> V_79 ) ;
F_62 ( V_3 -> V_9 ) ;
F_53 ( V_61 -> V_83 ) ;
F_54 ( V_61 -> V_83 ) ;
F_57 ( V_3 ) ;
F_42 ( V_12 , NULL ) ;
return 0 ;
}
static int F_63 ( struct V_67 * V_13 )
{
struct V_2 * V_3 = F_64 ( V_13 ) ;
return F_65 ( V_3 ) ;
}
static int F_66 ( struct V_67 * V_13 )
{
struct V_2 * V_3 = F_64 ( V_13 ) ;
return F_67 ( V_3 ) ;
}
