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
if ( V_4 -> V_3 -> V_16 & V_17 ) {
V_5 = F_6 ( V_12 , V_10 ) ;
return V_10 - V_5 ;
}
V_5 = V_4 -> V_9 [ V_7 ] ;
for ( V_14 = 0 ; V_14 <= 8 ; ++ V_14 ) {
if ( ( V_5 >> V_14 ) <= V_10 )
break;
}
if ( V_14 > 8 ) {
F_7 ( & V_4 -> V_18 -> V_19 ,
L_1 ,
V_7 , V_5 , V_5 / 256 , V_10 ) ;
return V_15 ;
}
F_7 ( & V_4 -> V_18 -> V_19 , L_2 ,
V_7 , V_5 , V_10 , V_5 >> V_14 ) ;
return V_10 - ( V_5 >> V_14 ) ;
}
static void F_8 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_20 = V_15 ;
unsigned int V_21 ;
int V_22 = 0 ;
int V_7 ;
T_1 V_23 ;
if ( clock == 0 )
return;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_21 = F_4 ( V_4 , V_7 , clock ) ;
if ( V_21 < V_20 ) {
V_20 = V_21 ;
V_22 = V_7 ;
}
}
F_7 ( & V_4 -> V_18 -> V_19 ,
L_3 ,
V_22 , clock , V_20 ) ;
if ( V_4 -> V_24 != V_22 ) {
struct V_11 * V_11 = V_4 -> V_13 [ V_22 ] ;
F_9 ( V_11 ) ;
if ( V_4 -> V_24 >= 0 )
F_10 (
V_4 -> V_13 [ V_4 -> V_24 ] ) ;
V_4 -> V_24 = V_22 ;
V_3 -> V_25 = V_4 -> V_9 [ V_22 ] ;
}
F_11 ( 0 , V_3 -> V_26 + V_27 ) ;
V_23 = F_12 ( V_3 -> V_26 + V_28 ) ;
V_23 &= ~ V_29 ;
V_23 |= V_22 << V_30 ;
F_13 ( V_23 , V_3 -> V_26 + V_28 ) ;
F_13 ( V_31 ,
V_3 -> V_26 + V_32 ) ;
V_23 = F_12 ( V_3 -> V_26 + V_28 ) ;
V_23 |= ( V_33 |
V_34 |
V_35 |
V_36 |
V_37 ) ;
F_13 ( V_23 , V_3 -> V_26 + V_28 ) ;
V_23 = ( V_38 | V_39 ) ;
if ( clock < 25 * 1000000 )
V_23 |= ( V_40 | V_41 ) ;
F_13 ( V_23 , V_3 -> V_26 + V_42 ) ;
}
static unsigned int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_43 = V_44 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_5 = V_4 -> V_9 [ V_7 ] / 256 ;
if ( ! V_5 )
continue;
if ( V_5 < V_43 )
V_43 = V_5 ;
}
return V_43 ;
}
static unsigned int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_6 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_11 * V_11 ;
V_11 = V_4 -> V_13 [ V_7 ] ;
if ( F_5 ( V_11 ) )
continue;
V_5 = F_6 ( V_11 , V_44 ) ;
if ( V_5 > V_6 )
V_6 = V_5 ;
}
return V_6 ;
}
static unsigned int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_5 , V_43 = V_44 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_11 * V_11 ;
V_11 = V_4 -> V_13 [ V_7 ] ;
if ( F_5 ( V_11 ) )
continue;
V_5 = F_6 ( V_11 , 0 ) ;
if ( V_5 < V_43 )
V_43 = V_5 ;
}
return V_43 ;
}
static void F_17 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_45 * V_19 = & V_4 -> V_18 -> V_19 ;
unsigned long V_46 ;
T_2 V_11 = 0 ;
if ( clock == 0 ) {
F_18 ( V_3 , 0 , V_27 ) ;
V_3 -> clock = clock ;
return;
}
F_8 ( V_3 , clock ) ;
F_19 ( V_4 -> V_13 [ V_4 -> V_24 ] , clock ) ;
V_3 -> clock = clock ;
V_11 = V_47 ;
F_18 ( V_3 , V_11 , V_27 ) ;
V_46 = 20 ;
while ( ! ( ( V_11 = F_20 ( V_3 , V_27 ) )
& V_48 ) ) {
if ( V_46 == 0 ) {
F_21 ( V_19 , L_4 ,
F_22 ( V_3 -> V_49 ) ) ;
return;
}
V_46 -- ;
F_23 ( 1 ) ;
}
V_11 |= V_50 ;
F_18 ( V_3 , V_11 , V_27 ) ;
}
static int F_24 ( struct V_2 * V_3 , int V_51 )
{
T_3 V_23 ;
V_23 = F_25 ( V_3 , V_52 ) ;
switch ( V_51 ) {
case V_53 :
V_23 |= V_54 ;
V_23 &= ~ V_55 ;
break;
case V_56 :
V_23 |= V_55 ;
V_23 &= ~ V_54 ;
break;
default:
V_23 &= ~ V_55 ;
V_23 &= ~ V_54 ;
break;
}
F_26 ( V_3 , V_23 , V_52 ) ;
return 0 ;
}
static void F_27 ( struct V_57 * V_19 , int V_58 )
{
struct V_2 * V_3 = F_28 ( V_19 ) ;
#ifdef F_29
struct V_1 * V_59 = F_2 ( V_3 ) ;
#endif
unsigned long V_60 ;
if ( V_3 ) {
F_30 ( & V_3 -> V_61 , V_60 ) ;
if ( V_58 ) {
F_7 ( & V_19 -> V_19 , L_5 ) ;
#ifdef F_29
F_9 ( V_59 -> V_62 ) ;
#endif
V_3 -> V_60 &= ~ V_63 ;
V_3 -> V_16 |= V_64 ;
} else {
F_7 ( & V_19 -> V_19 , L_6 ) ;
V_3 -> V_60 |= V_63 ;
V_3 -> V_16 &= ~ V_64 ;
#ifdef F_29
F_10 ( V_59 -> V_62 ) ;
#endif
}
F_31 ( & V_3 -> V_65 ) ;
F_32 ( & V_3 -> V_61 , V_60 ) ;
}
}
static T_4 F_33 ( int V_66 , void * V_67 )
{
struct V_1 * V_59 = V_67 ;
int V_68 = F_34 ( V_59 -> V_69 ) ;
if ( V_59 -> V_70 -> V_71 )
V_68 = ! V_68 ;
F_27 ( V_59 -> V_18 , V_68 ) ;
return V_72 ;
}
static void F_35 ( struct V_1 * V_59 )
{
struct V_73 * V_70 = V_59 -> V_70 ;
struct V_45 * V_19 = & V_59 -> V_18 -> V_19 ;
if ( F_36 ( V_19 , V_70 -> V_69 , L_7 ) == 0 ) {
V_59 -> V_69 = V_70 -> V_69 ;
V_59 -> V_74 = F_37 ( V_70 -> V_69 ) ;
if ( V_59 -> V_74 &&
F_38 ( V_59 -> V_74 , NULL ,
F_33 ,
V_75 |
V_76 |
V_77 ,
F_39 ( V_19 ) , V_59 ) == 0 ) {
int V_68 = F_34 ( V_59 -> V_69 ) ;
if ( V_70 -> V_71 )
V_68 = ! V_68 ;
F_27 ( V_59 -> V_18 , V_68 ) ;
} else {
F_40 ( V_19 , L_8 ) ;
V_59 -> V_74 = 0 ;
}
} else {
F_21 ( V_19 , L_9 ) ;
}
}
static int F_41 ( struct V_45 * V_19 ,
struct V_2 * V_3 , struct V_73 * V_70 )
{
struct V_78 * V_79 = V_19 -> V_80 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_81 ;
int V_82 ;
if ( F_42 ( V_79 , L_10 , & V_81 ) )
V_81 = 1 ;
V_70 -> V_81 = V_81 ;
if ( F_43 ( V_79 , L_11 , NULL ) ) {
V_70 -> V_83 = V_84 ;
return 0 ;
}
if ( F_43 ( V_79 , L_12 , NULL ) ) {
V_70 -> V_83 = V_85 ;
return 0 ;
}
V_82 = F_44 ( V_79 , L_13 , 0 ) ;
if ( F_45 ( V_82 ) ) {
V_70 -> V_83 = V_86 ;
V_70 -> V_69 = V_82 ;
V_4 -> V_69 = - 1 ;
if ( F_43 ( V_79 , L_14 , NULL ) )
V_70 -> V_71 = 1 ;
return 0 ;
} else if ( V_82 != - V_87 ) {
F_21 ( V_19 , L_15 ) ;
return - V_88 ;
}
V_70 -> V_83 = V_89 ;
return 0 ;
}
static int F_41 ( struct V_45 * V_19 ,
struct V_2 * V_3 , struct V_73 * V_70 )
{
return - V_88 ;
}
static inline struct V_90 * F_46 (
struct V_57 * V_18 )
{
#ifdef F_47
if ( V_18 -> V_19 . V_80 ) {
const struct V_91 * V_92 ;
V_92 = F_48 ( V_93 , V_18 -> V_19 . V_80 ) ;
return (struct V_90 * ) V_92 -> V_94 ;
}
#endif
return (struct V_90 * )
F_49 ( V_18 ) -> V_95 ;
}
static int F_50 ( struct V_57 * V_18 )
{
struct V_73 * V_70 ;
struct V_90 * V_96 ;
struct V_45 * V_19 = & V_18 -> V_19 ;
struct V_2 * V_3 ;
struct V_1 * V_59 ;
struct V_97 * V_98 ;
int V_99 , V_66 , V_100 , V_101 ;
if ( ! V_18 -> V_19 . V_102 && ! V_18 -> V_19 . V_80 ) {
F_21 ( V_19 , L_16 ) ;
return - V_87 ;
}
V_66 = F_51 ( V_18 , 0 ) ;
if ( V_66 < 0 ) {
F_21 ( V_19 , L_17 ) ;
return V_66 ;
}
V_3 = F_52 ( V_19 , sizeof( struct V_1 ) ) ;
if ( F_5 ( V_3 ) ) {
F_21 ( V_19 , L_18 ) ;
return F_53 ( V_3 ) ;
}
V_59 = F_2 ( V_3 ) ;
V_70 = F_54 ( & V_18 -> V_19 , sizeof( * V_70 ) , V_103 ) ;
if ( ! V_70 ) {
V_99 = - V_104 ;
goto V_105;
}
if ( V_18 -> V_19 . V_80 ) {
V_99 = F_41 ( & V_18 -> V_19 , V_3 , V_70 ) ;
if ( V_99 )
goto V_105;
} else {
memcpy ( V_70 , V_18 -> V_19 . V_102 , sizeof( * V_70 ) ) ;
V_59 -> V_69 = - 1 ;
}
V_96 = F_46 ( V_18 ) ;
V_59 -> V_3 = V_3 ;
V_59 -> V_18 = V_18 ;
V_59 -> V_70 = V_70 ;
V_59 -> V_24 = - 1 ;
F_55 ( V_18 , V_3 ) ;
V_59 -> V_62 = F_56 ( V_19 , L_19 ) ;
if ( F_5 ( V_59 -> V_62 ) ) {
F_21 ( V_19 , L_20 ) ;
V_99 = F_53 ( V_59 -> V_62 ) ;
goto V_105;
}
F_9 ( V_59 -> V_62 ) ;
for ( V_101 = 0 , V_100 = 0 ; V_100 < V_8 ; V_100 ++ ) {
char V_106 [ 14 ] ;
snprintf ( V_106 , 14 , L_21 , V_100 ) ;
V_59 -> V_13 [ V_100 ] = F_56 ( V_19 , V_106 ) ;
if ( F_5 ( V_59 -> V_13 [ V_100 ] ) )
continue;
V_101 ++ ;
V_59 -> V_9 [ V_100 ] = F_57 ( V_59 -> V_13 [ V_100 ] ) ;
F_58 ( V_19 , L_22 ,
V_100 , V_106 , V_59 -> V_9 [ V_100 ] ) ;
}
if ( V_101 == 0 ) {
F_21 ( V_19 , L_23 ) ;
V_99 = - V_87 ;
goto V_107;
}
V_98 = F_59 ( V_18 , V_108 , 0 ) ;
V_3 -> V_26 = F_60 ( & V_18 -> V_19 , V_98 ) ;
if ( F_5 ( V_3 -> V_26 ) ) {
V_99 = F_53 ( V_3 -> V_26 ) ;
goto V_109;
}
if ( V_70 -> V_110 )
V_70 -> V_110 ( V_18 , V_70 -> V_81 ) ;
V_3 -> V_111 = L_24 ;
V_3 -> V_112 = & V_113 ;
V_3 -> V_16 = 0 ;
V_3 -> V_114 = 0 ;
V_3 -> V_66 = V_66 ;
V_3 -> V_16 |= V_115 ;
V_3 -> V_16 |= V_116 ;
if ( V_96 )
V_3 -> V_16 |= V_96 -> V_117 ;
#ifndef F_61
V_3 -> V_16 |= V_118 ;
#endif
V_3 -> V_16 |= V_119 ;
V_3 -> V_16 |= V_120 ;
V_3 -> V_16 |= V_121 ;
if ( V_70 -> V_83 == V_84 ||
V_70 -> V_83 == V_85 )
V_3 -> V_16 |= V_64 ;
if ( V_70 -> V_83 == V_85 )
V_3 -> V_49 -> V_122 = V_123 ;
switch ( V_70 -> V_81 ) {
case 8 :
V_3 -> V_49 -> V_122 |= V_124 ;
case 4 :
V_3 -> V_49 -> V_122 |= V_125 ;
break;
}
if ( V_70 -> V_126 )
V_3 -> V_49 -> V_126 |= V_70 -> V_126 ;
V_3 -> V_16 |= ( V_127 |
V_128 ) ;
V_3 -> V_16 |= V_129 ;
if ( V_3 -> V_16 & V_17 ) {
V_113 . V_130 = F_17 ;
V_113 . V_131 = F_16 ;
V_113 . V_132 = F_15 ;
}
if ( V_70 -> V_133 )
V_3 -> V_49 -> V_122 |= V_70 -> V_133 ;
if ( V_70 -> V_134 )
V_3 -> V_49 -> V_135 |= V_70 -> V_134 ;
F_62 ( & V_18 -> V_19 ) ;
F_63 ( & V_18 -> V_19 , 50 ) ;
F_64 ( & V_18 -> V_19 ) ;
F_65 ( & V_18 -> V_19 , 1 ) ;
V_99 = F_66 ( V_3 ) ;
if ( V_99 ) {
F_21 ( V_19 , L_25 ) ;
F_67 ( & V_18 -> V_19 ) ;
F_68 ( & V_18 -> V_19 ) ;
goto V_109;
}
if ( V_70 -> V_83 == V_136 && V_70 -> V_137 )
V_70 -> V_137 ( & F_27 ) ;
if ( V_70 -> V_83 == V_86 &&
F_45 ( V_70 -> V_69 ) )
F_35 ( V_59 ) ;
#ifdef F_29
if ( V_70 -> V_83 != V_89 )
F_10 ( V_59 -> V_62 ) ;
#endif
return 0 ;
V_109:
V_107:
F_10 ( V_59 -> V_62 ) ;
V_105:
F_69 ( V_3 ) ;
return V_99 ;
}
static int F_70 ( struct V_57 * V_18 )
{
struct V_2 * V_3 = F_28 ( V_18 ) ;
struct V_1 * V_59 = F_2 ( V_3 ) ;
struct V_73 * V_70 = V_59 -> V_70 ;
if ( V_70 -> V_83 == V_136 && V_70 -> V_138 )
V_70 -> V_138 ( & F_27 ) ;
if ( V_59 -> V_74 )
F_71 ( V_59 -> V_74 , V_59 ) ;
#ifdef F_29
if ( V_70 -> V_83 != V_89 )
F_9 ( V_59 -> V_62 ) ;
#endif
F_72 ( V_3 , 1 ) ;
F_73 ( & V_18 -> V_19 ) ;
F_74 ( & V_18 -> V_19 ) ;
F_10 ( V_59 -> V_62 ) ;
F_69 ( V_3 ) ;
return 0 ;
}
static int F_75 ( struct V_45 * V_19 )
{
struct V_2 * V_3 = F_76 ( V_19 ) ;
return F_77 ( V_3 ) ;
}
static int F_78 ( struct V_45 * V_19 )
{
struct V_2 * V_3 = F_76 ( V_19 ) ;
return F_79 ( V_3 ) ;
}
static int F_80 ( struct V_45 * V_19 )
{
struct V_2 * V_3 = F_76 ( V_19 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_139 = V_4 -> V_62 ;
int V_99 ;
V_99 = F_81 ( V_3 ) ;
if ( V_4 -> V_24 >= 0 )
F_10 ( V_4 -> V_13 [ V_4 -> V_24 ] ) ;
F_10 ( V_139 ) ;
return V_99 ;
}
static int F_82 ( struct V_45 * V_19 )
{
struct V_2 * V_3 = F_76 ( V_19 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_11 * V_139 = V_4 -> V_62 ;
int V_99 ;
F_9 ( V_139 ) ;
if ( V_4 -> V_24 >= 0 )
F_9 ( V_4 -> V_13 [ V_4 -> V_24 ] ) ;
V_99 = F_83 ( V_3 ) ;
return V_99 ;
}
