static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static unsigned int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_5 = V_4 -> V_9 [ V_7 ] ;
if ( V_5 > V_6 )
V_6 = V_5 ;
}
return V_6 ;
}
static unsigned int F_4 ( struct V_1 * V_4 ,
unsigned int V_7 ,
unsigned int V_10 )
{
unsigned long V_5 ;
struct V_11 * V_12 = V_4 -> V_13 [ V_7 ] ;
int V_14 ;
if ( F_5 ( V_12 ) )
return V_15 ;
if ( V_4 -> V_16 ) {
V_5 = F_6 ( V_12 , V_10 ) ;
return V_10 - V_5 ;
}
V_5 = V_4 -> V_9 [ V_7 ] ;
for ( V_14 = 0 ; V_14 <= 8 ; ++ V_14 ) {
if ( ( V_5 >> V_14 ) <= V_10 )
break;
}
if ( V_14 > 8 ) {
F_7 ( & V_4 -> V_17 -> V_18 ,
L_1 ,
V_7 , V_5 , V_5 / 256 , V_10 ) ;
return V_15 ;
}
F_7 ( & V_4 -> V_17 -> V_18 , L_2 ,
V_7 , V_5 , V_10 , V_5 >> V_14 ) ;
return V_10 - ( V_5 >> V_14 ) ;
}
static void F_8 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_19 = V_15 ;
unsigned int V_20 ;
int V_21 = 0 ;
int V_7 ;
T_1 V_22 ;
V_3 -> V_23 -> V_24 = 0 ;
if ( clock == 0 ) {
F_9 ( V_3 , clock ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_20 = F_4 ( V_4 , V_7 , clock ) ;
if ( V_20 < V_19 ) {
V_19 = V_20 ;
V_21 = V_7 ;
}
}
F_7 ( & V_4 -> V_17 -> V_18 ,
L_3 ,
V_21 , clock , V_19 ) ;
if ( V_4 -> V_25 != V_21 ) {
struct V_11 * V_11 = V_4 -> V_13 [ V_21 ] ;
F_10 ( V_11 ) ;
if ( V_4 -> V_25 >= 0 )
F_11 (
V_4 -> V_13 [ V_4 -> V_25 ] ) ;
V_4 -> V_25 = V_21 ;
V_3 -> V_26 = V_4 -> V_9 [ V_21 ] ;
}
F_12 ( 0 , V_3 -> V_27 + V_28 ) ;
V_22 = F_13 ( V_3 -> V_27 + V_29 ) ;
V_22 &= ~ V_30 ;
V_22 |= V_21 << V_31 ;
F_14 ( V_22 , V_3 -> V_27 + V_29 ) ;
F_14 ( V_32 ,
V_3 -> V_27 + V_33 ) ;
V_22 = F_13 ( V_3 -> V_27 + V_29 ) ;
V_22 |= ( V_34 |
V_35 |
V_36 |
V_37 |
V_38 ) ;
F_14 ( V_22 , V_3 -> V_27 + V_29 ) ;
V_22 = ( V_39 | V_40 ) ;
if ( clock < 25 * 1000000 )
V_22 |= ( V_41 | V_42 ) ;
F_14 ( V_22 , V_3 -> V_27 + V_43 ) ;
F_9 ( V_3 , clock ) ;
}
static unsigned int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_44 = V_45 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_5 = V_4 -> V_9 [ V_7 ] / 256 ;
if ( ! V_5 )
continue;
if ( V_5 < V_44 )
V_44 = V_5 ;
}
return V_44 ;
}
static unsigned int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_11 * V_11 ;
V_11 = V_4 -> V_13 [ V_7 ] ;
if ( F_5 ( V_11 ) )
continue;
V_5 = F_6 ( V_11 , V_45 ) ;
if ( V_5 > V_6 )
V_6 = V_5 ;
}
return V_6 ;
}
static unsigned int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_44 = V_45 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_11 * V_11 ;
V_11 = V_4 -> V_13 [ V_7 ] ;
if ( F_5 ( V_11 ) )
continue;
V_5 = F_6 ( V_11 , 0 ) ;
if ( V_5 < V_44 )
V_44 = V_5 ;
}
return V_44 ;
}
static void F_18 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_46 * V_18 = & V_4 -> V_17 -> V_18 ;
unsigned long V_47 ;
T_2 V_11 = 0 ;
int V_48 ;
V_3 -> V_23 -> V_24 = 0 ;
if ( clock == 0 ) {
F_19 ( V_3 , 0 , V_28 ) ;
return;
}
F_8 ( V_3 , clock ) ;
V_48 = F_20 ( V_4 -> V_13 [ V_4 -> V_25 ] , clock ) ;
if ( V_48 != 0 ) {
F_21 ( V_18 , L_4 ,
F_22 ( V_3 -> V_23 ) , clock ) ;
return;
}
V_11 = V_49 ;
F_19 ( V_3 , V_11 , V_28 ) ;
V_47 = 20 ;
while ( ! ( ( V_11 = F_23 ( V_3 , V_28 ) )
& V_50 ) ) {
if ( V_47 == 0 ) {
F_21 ( V_18 , L_5 ,
F_22 ( V_3 -> V_23 ) ) ;
return;
}
V_47 -- ;
F_24 ( 1 ) ;
}
V_11 |= V_51 ;
F_19 ( V_3 , V_11 , V_28 ) ;
}
static void F_25 ( struct V_2 * V_3 , int V_52 )
{
T_3 V_22 ;
V_22 = F_26 ( V_3 , V_53 ) ;
switch ( V_52 ) {
case V_54 :
V_22 |= V_55 ;
V_22 &= ~ V_56 ;
break;
case V_57 :
V_22 |= V_56 ;
V_22 &= ~ V_55 ;
break;
default:
V_22 &= ~ V_56 ;
V_22 &= ~ V_55 ;
break;
}
F_27 ( V_3 , V_22 , V_53 ) ;
}
static int F_28 ( struct V_46 * V_18 ,
struct V_2 * V_3 , struct V_58 * V_59 )
{
struct V_60 * V_61 = V_18 -> V_62 ;
T_1 V_63 ;
if ( F_29 ( V_61 , L_6 , & V_63 ) )
V_63 = 1 ;
V_59 -> V_63 = V_63 ;
if ( F_30 ( V_61 , L_7 , NULL ) ) {
V_59 -> V_64 = V_65 ;
return 0 ;
}
if ( F_30 ( V_61 , L_8 , NULL ) ) {
V_59 -> V_64 = V_66 ;
return 0 ;
}
if ( F_31 ( V_61 , L_9 , 0 ) )
return 0 ;
V_59 -> V_64 = V_67 ;
return 0 ;
}
static int F_28 ( struct V_46 * V_18 ,
struct V_2 * V_3 , struct V_58 * V_59 )
{
return - V_68 ;
}
static inline struct V_69 * F_32 (
struct V_70 * V_17 )
{
#ifdef F_33
if ( V_17 -> V_18 . V_62 ) {
const struct V_71 * V_72 ;
V_72 = F_34 ( V_73 , V_17 -> V_18 . V_62 ) ;
return (struct V_69 * ) V_72 -> V_74 ;
}
#endif
return (struct V_69 * )
F_35 ( V_17 ) -> V_75 ;
}
static int F_36 ( struct V_70 * V_17 )
{
struct V_58 * V_59 ;
struct V_69 * V_76 ;
struct V_46 * V_18 = & V_17 -> V_18 ;
struct V_2 * V_3 ;
struct V_1 * V_77 ;
struct V_78 * V_79 ;
int V_48 , V_80 , V_81 , V_82 ;
if ( ! V_17 -> V_18 . V_83 && ! V_17 -> V_18 . V_62 ) {
F_21 ( V_18 , L_10 ) ;
return - V_84 ;
}
V_80 = F_37 ( V_17 , 0 ) ;
if ( V_80 < 0 ) {
F_21 ( V_18 , L_11 ) ;
return V_80 ;
}
V_3 = F_38 ( V_18 , sizeof( struct V_1 ) ) ;
if ( F_5 ( V_3 ) ) {
F_21 ( V_18 , L_12 ) ;
return F_39 ( V_3 ) ;
}
V_77 = F_2 ( V_3 ) ;
V_59 = F_40 ( & V_17 -> V_18 , sizeof( * V_59 ) , V_85 ) ;
if ( ! V_59 ) {
V_48 = - V_86 ;
goto V_87;
}
if ( V_17 -> V_18 . V_62 ) {
V_48 = F_28 ( & V_17 -> V_18 , V_3 , V_59 ) ;
if ( V_48 )
goto V_87;
} else {
memcpy ( V_59 , V_17 -> V_18 . V_83 , sizeof( * V_59 ) ) ;
V_77 -> V_88 = - 1 ;
}
V_76 = F_32 ( V_17 ) ;
V_77 -> V_3 = V_3 ;
V_77 -> V_17 = V_17 ;
V_77 -> V_59 = V_59 ;
V_77 -> V_25 = - 1 ;
F_41 ( V_17 , V_3 ) ;
V_77 -> V_89 = F_42 ( V_18 , L_13 ) ;
if ( F_5 ( V_77 -> V_89 ) ) {
F_21 ( V_18 , L_14 ) ;
V_48 = F_39 ( V_77 -> V_89 ) ;
goto V_87;
}
F_10 ( V_77 -> V_89 ) ;
for ( V_82 = 0 , V_81 = 0 ; V_81 < V_8 ; V_81 ++ ) {
char V_90 [ 14 ] ;
snprintf ( V_90 , 14 , L_15 , V_81 ) ;
V_77 -> V_13 [ V_81 ] = F_42 ( V_18 , V_90 ) ;
if ( F_5 ( V_77 -> V_13 [ V_81 ] ) )
continue;
V_82 ++ ;
V_77 -> V_9 [ V_81 ] = F_43 ( V_77 -> V_13 [ V_81 ] ) ;
F_44 ( V_18 , L_16 ,
V_81 , V_90 , V_77 -> V_9 [ V_81 ] ) ;
}
if ( V_82 == 0 ) {
F_21 ( V_18 , L_17 ) ;
V_48 = - V_84 ;
goto V_91;
}
V_79 = F_45 ( V_17 , V_92 , 0 ) ;
V_3 -> V_27 = F_46 ( & V_17 -> V_18 , V_79 ) ;
if ( F_5 ( V_3 -> V_27 ) ) {
V_48 = F_39 ( V_3 -> V_27 ) ;
goto V_93;
}
if ( V_59 -> V_94 )
V_59 -> V_94 ( V_17 , V_59 -> V_63 ) ;
V_3 -> V_95 = L_18 ;
V_3 -> V_96 = & V_97 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_80 = V_80 ;
V_3 -> V_98 |= V_100 ;
V_3 -> V_98 |= V_101 ;
if ( V_76 ) {
V_3 -> V_98 |= V_76 -> V_102 ;
V_77 -> V_16 = V_76 -> V_16 ;
}
#ifndef F_47
V_3 -> V_98 |= V_103 ;
#endif
V_3 -> V_98 |= V_104 ;
V_3 -> V_98 |= V_105 ;
V_3 -> V_98 |= V_106 ;
if ( V_59 -> V_64 == V_65 ||
V_59 -> V_64 == V_66 )
V_3 -> V_98 |= V_107 ;
if ( V_59 -> V_64 == V_66 )
V_3 -> V_23 -> V_108 = V_109 ;
switch ( V_59 -> V_63 ) {
case 8 :
V_3 -> V_23 -> V_108 |= V_110 ;
case 4 :
V_3 -> V_23 -> V_108 |= V_111 ;
break;
}
if ( V_59 -> V_112 )
V_3 -> V_23 -> V_112 |= V_59 -> V_112 ;
V_3 -> V_98 |= ( V_113 |
V_114 ) ;
V_3 -> V_98 |= V_115 ;
if ( V_77 -> V_16 ) {
V_97 . V_116 = F_18 ;
V_97 . V_117 = F_17 ;
V_97 . V_118 = F_16 ;
}
if ( V_59 -> V_119 )
V_3 -> V_23 -> V_108 |= V_59 -> V_119 ;
if ( V_59 -> V_120 )
V_3 -> V_23 -> V_121 |= V_59 -> V_120 ;
F_48 ( & V_17 -> V_18 ) ;
F_49 ( & V_17 -> V_18 , 50 ) ;
F_50 ( & V_17 -> V_18 ) ;
F_51 ( & V_17 -> V_18 , 1 ) ;
F_52 ( V_3 -> V_23 ) ;
V_48 = F_53 ( V_3 ) ;
if ( V_48 ) {
F_21 ( V_18 , L_19 ) ;
goto V_93;
}
#ifdef F_54
if ( V_59 -> V_64 != V_67 )
F_11 ( V_77 -> V_89 ) ;
#endif
return 0 ;
V_93:
F_55 ( & V_17 -> V_18 ) ;
V_91:
F_11 ( V_77 -> V_89 ) ;
V_87:
F_56 ( V_3 ) ;
return V_48 ;
}
static int F_57 ( struct V_70 * V_17 )
{
struct V_2 * V_3 = F_58 ( V_17 ) ;
struct V_1 * V_77 = F_2 ( V_3 ) ;
if ( V_77 -> V_122 )
F_59 ( V_77 -> V_122 , V_77 ) ;
#ifdef F_54
if ( V_77 -> V_59 -> V_64 != V_67 )
F_10 ( V_77 -> V_89 ) ;
#endif
F_60 ( V_3 , 1 ) ;
F_61 ( & V_17 -> V_18 ) ;
F_55 ( & V_17 -> V_18 ) ;
F_11 ( V_77 -> V_89 ) ;
F_56 ( V_3 ) ;
return 0 ;
}
static int F_62 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_63 ( V_18 ) ;
return F_64 ( V_3 ) ;
}
static int F_65 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_63 ( V_18 ) ;
return F_66 ( V_3 ) ;
}
static int F_67 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_63 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_123 = V_4 -> V_89 ;
int V_48 ;
V_48 = F_68 ( V_3 ) ;
if ( V_4 -> V_25 >= 0 )
F_11 ( V_4 -> V_13 [ V_4 -> V_25 ] ) ;
F_11 ( V_123 ) ;
return V_48 ;
}
static int F_69 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_63 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_123 = V_4 -> V_89 ;
int V_48 ;
F_10 ( V_123 ) ;
if ( V_4 -> V_25 >= 0 )
F_10 ( V_4 -> V_13 [ V_4 -> V_25 ] ) ;
V_48 = F_70 ( V_3 ) ;
return V_48 ;
}
