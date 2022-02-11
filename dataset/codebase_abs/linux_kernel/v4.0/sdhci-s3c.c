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
V_11 = F_20 ( V_3 , V_28 ) ;
V_11 &= ~ V_49 ;
F_19 ( V_3 , V_11 , V_28 ) ;
F_21 ( & V_3 -> V_50 ) ;
V_48 = F_22 ( V_4 -> V_13 [ V_4 -> V_25 ] , clock ) ;
F_23 ( & V_3 -> V_50 ) ;
if ( V_48 != 0 ) {
F_24 ( V_18 , L_4 ,
F_25 ( V_3 -> V_23 ) , clock ) ;
return;
}
V_11 = V_51 ;
F_19 ( V_3 , V_11 , V_28 ) ;
V_47 = 20 ;
while ( ! ( ( V_11 = F_20 ( V_3 , V_28 ) )
& V_52 ) ) {
if ( V_47 == 0 ) {
F_24 ( V_18 , L_5 ,
F_25 ( V_3 -> V_23 ) ) ;
return;
}
V_47 -- ;
F_26 ( 1 ) ;
}
V_11 |= V_49 ;
F_19 ( V_3 , V_11 , V_28 ) ;
}
static void F_27 ( struct V_2 * V_3 , int V_53 )
{
T_3 V_22 ;
V_22 = F_28 ( V_3 , V_54 ) ;
switch ( V_53 ) {
case V_55 :
V_22 |= V_56 ;
V_22 &= ~ V_57 ;
break;
case V_58 :
V_22 |= V_57 ;
V_22 &= ~ V_56 ;
break;
default:
V_22 &= ~ V_57 ;
V_22 &= ~ V_56 ;
break;
}
F_29 ( V_3 , V_22 , V_54 ) ;
}
static int F_30 ( struct V_46 * V_18 ,
struct V_2 * V_3 , struct V_59 * V_60 )
{
struct V_61 * V_62 = V_18 -> V_63 ;
T_1 V_64 ;
if ( F_31 ( V_62 , L_6 , & V_64 ) )
V_64 = 1 ;
V_60 -> V_64 = V_64 ;
if ( F_32 ( V_62 , L_7 , NULL ) ) {
V_60 -> V_65 = V_66 ;
return 0 ;
}
if ( F_32 ( V_62 , L_8 , NULL ) ) {
V_60 -> V_65 = V_67 ;
return 0 ;
}
if ( F_33 ( V_62 , L_9 , 0 ) )
return 0 ;
V_60 -> V_65 = V_68 ;
return 0 ;
}
static int F_30 ( struct V_46 * V_18 ,
struct V_2 * V_3 , struct V_59 * V_60 )
{
return - V_69 ;
}
static inline struct V_70 * F_34 (
struct V_71 * V_17 )
{
#ifdef F_35
if ( V_17 -> V_18 . V_63 ) {
const struct V_72 * V_73 ;
V_73 = F_36 ( V_74 , V_17 -> V_18 . V_63 ) ;
return (struct V_70 * ) V_73 -> V_75 ;
}
#endif
return (struct V_70 * )
F_37 ( V_17 ) -> V_76 ;
}
static int F_38 ( struct V_71 * V_17 )
{
struct V_59 * V_60 ;
struct V_70 * V_77 ;
struct V_46 * V_18 = & V_17 -> V_18 ;
struct V_2 * V_3 ;
struct V_1 * V_78 ;
struct V_79 * V_80 ;
int V_48 , V_81 , V_82 , V_83 ;
if ( ! V_17 -> V_18 . V_84 && ! V_17 -> V_18 . V_63 ) {
F_24 ( V_18 , L_10 ) ;
return - V_85 ;
}
V_81 = F_39 ( V_17 , 0 ) ;
if ( V_81 < 0 ) {
F_24 ( V_18 , L_11 ) ;
return V_81 ;
}
V_3 = F_40 ( V_18 , sizeof( struct V_1 ) ) ;
if ( F_5 ( V_3 ) ) {
F_24 ( V_18 , L_12 ) ;
return F_41 ( V_3 ) ;
}
V_78 = F_2 ( V_3 ) ;
V_60 = F_42 ( & V_17 -> V_18 , sizeof( * V_60 ) , V_86 ) ;
if ( ! V_60 ) {
V_48 = - V_87 ;
goto V_88;
}
if ( V_17 -> V_18 . V_63 ) {
V_48 = F_30 ( & V_17 -> V_18 , V_3 , V_60 ) ;
if ( V_48 )
goto V_88;
} else {
memcpy ( V_60 , V_17 -> V_18 . V_84 , sizeof( * V_60 ) ) ;
V_78 -> V_89 = - 1 ;
}
V_77 = F_34 ( V_17 ) ;
V_78 -> V_3 = V_3 ;
V_78 -> V_17 = V_17 ;
V_78 -> V_60 = V_60 ;
V_78 -> V_25 = - 1 ;
F_43 ( V_17 , V_3 ) ;
V_78 -> V_90 = F_44 ( V_18 , L_13 ) ;
if ( F_5 ( V_78 -> V_90 ) ) {
F_24 ( V_18 , L_14 ) ;
V_48 = F_41 ( V_78 -> V_90 ) ;
goto V_88;
}
F_10 ( V_78 -> V_90 ) ;
for ( V_83 = 0 , V_82 = 0 ; V_82 < V_8 ; V_82 ++ ) {
char V_91 [ 14 ] ;
snprintf ( V_91 , 14 , L_15 , V_82 ) ;
V_78 -> V_13 [ V_82 ] = F_44 ( V_18 , V_91 ) ;
if ( F_5 ( V_78 -> V_13 [ V_82 ] ) )
continue;
V_83 ++ ;
V_78 -> V_9 [ V_82 ] = F_45 ( V_78 -> V_13 [ V_82 ] ) ;
F_46 ( V_18 , L_16 ,
V_82 , V_91 , V_78 -> V_9 [ V_82 ] ) ;
}
if ( V_83 == 0 ) {
F_24 ( V_18 , L_17 ) ;
V_48 = - V_85 ;
goto V_92;
}
V_80 = F_47 ( V_17 , V_93 , 0 ) ;
V_3 -> V_27 = F_48 ( & V_17 -> V_18 , V_80 ) ;
if ( F_5 ( V_3 -> V_27 ) ) {
V_48 = F_41 ( V_3 -> V_27 ) ;
goto V_94;
}
if ( V_60 -> V_95 )
V_60 -> V_95 ( V_17 , V_60 -> V_64 ) ;
V_3 -> V_96 = L_18 ;
V_3 -> V_97 = & V_98 ;
V_3 -> V_99 = 0 ;
V_3 -> V_100 = 0 ;
V_3 -> V_81 = V_81 ;
V_3 -> V_99 |= V_101 ;
V_3 -> V_99 |= V_102 ;
if ( V_77 ) {
V_3 -> V_99 |= V_77 -> V_103 ;
V_78 -> V_16 = V_77 -> V_16 ;
}
#ifndef F_49
V_3 -> V_99 |= V_104 ;
#endif
V_3 -> V_99 |= V_105 ;
V_3 -> V_99 |= V_106 ;
V_3 -> V_99 |= V_107 ;
if ( V_60 -> V_65 == V_66 ||
V_60 -> V_65 == V_67 )
V_3 -> V_99 |= V_108 ;
if ( V_60 -> V_65 == V_67 )
V_3 -> V_23 -> V_109 = V_110 ;
switch ( V_60 -> V_64 ) {
case 8 :
V_3 -> V_23 -> V_109 |= V_111 ;
case 4 :
V_3 -> V_23 -> V_109 |= V_112 ;
break;
}
if ( V_60 -> V_113 )
V_3 -> V_23 -> V_113 |= V_60 -> V_113 ;
V_3 -> V_99 |= ( V_114 |
V_115 ) ;
V_3 -> V_99 |= V_116 ;
if ( V_78 -> V_16 ) {
V_98 . V_117 = F_18 ;
V_98 . V_118 = F_17 ;
V_98 . V_119 = F_16 ;
}
if ( V_60 -> V_120 )
V_3 -> V_23 -> V_109 |= V_60 -> V_120 ;
if ( V_60 -> V_121 )
V_3 -> V_23 -> V_122 |= V_60 -> V_121 ;
F_50 ( & V_17 -> V_18 ) ;
F_51 ( & V_17 -> V_18 , 50 ) ;
F_52 ( & V_17 -> V_18 ) ;
F_53 ( & V_17 -> V_18 , 1 ) ;
V_48 = F_54 ( V_3 -> V_23 ) ;
if ( V_48 )
goto V_94;
V_48 = F_55 ( V_3 ) ;
if ( V_48 ) {
F_24 ( V_18 , L_19 ) ;
goto V_94;
}
#ifdef F_56
if ( V_60 -> V_65 != V_68 )
F_11 ( V_78 -> V_90 ) ;
#endif
return 0 ;
V_94:
F_57 ( & V_17 -> V_18 ) ;
V_92:
F_11 ( V_78 -> V_90 ) ;
V_88:
F_58 ( V_3 ) ;
return V_48 ;
}
static int F_59 ( struct V_71 * V_17 )
{
struct V_2 * V_3 = F_60 ( V_17 ) ;
struct V_1 * V_78 = F_2 ( V_3 ) ;
if ( V_78 -> V_123 )
F_61 ( V_78 -> V_123 , V_78 ) ;
#ifdef F_56
if ( V_78 -> V_60 -> V_65 != V_68 )
F_10 ( V_78 -> V_90 ) ;
#endif
F_62 ( V_3 , 1 ) ;
F_63 ( & V_17 -> V_18 ) ;
F_57 ( & V_17 -> V_18 ) ;
F_11 ( V_78 -> V_90 ) ;
F_58 ( V_3 ) ;
return 0 ;
}
static int F_64 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_65 ( V_18 ) ;
return F_66 ( V_3 ) ;
}
static int F_67 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_65 ( V_18 ) ;
return F_68 ( V_3 ) ;
}
static int F_69 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_65 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_124 = V_4 -> V_90 ;
int V_48 ;
V_48 = F_70 ( V_3 ) ;
if ( V_4 -> V_25 >= 0 )
F_11 ( V_4 -> V_13 [ V_4 -> V_25 ] ) ;
F_11 ( V_124 ) ;
return V_48 ;
}
static int F_71 ( struct V_46 * V_18 )
{
struct V_2 * V_3 = F_65 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_124 = V_4 -> V_90 ;
int V_48 ;
F_10 ( V_124 ) ;
if ( V_4 -> V_25 >= 0 )
F_10 ( V_4 -> V_13 [ V_4 -> V_25 ] ) ;
V_48 = F_72 ( V_3 ) ;
return V_48 ;
}
