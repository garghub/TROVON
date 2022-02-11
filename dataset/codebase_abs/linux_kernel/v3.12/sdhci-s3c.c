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
return V_21 - ( V_16 / div ) ;
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
F_13 ( V_14 ) ;
F_14 ( V_7 -> V_19 [ V_7 -> V_11 ] ) ;
F_15 ( 0 , V_3 -> V_9 + V_30 ) ;
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
static unsigned int F_16 ( struct V_2 * V_3 )
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
static unsigned int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_11 ( V_7 -> V_19 [ V_7 -> V_11 ] , V_23 ) ;
}
static unsigned int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_11 ( V_7 -> V_19 [ V_7 -> V_11 ] , 400000 ) ;
}
static void F_19 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_45 * V_13 = & V_7 -> V_12 -> V_13 ;
unsigned long V_46 ;
T_2 V_14 = 0 ;
if ( clock == 0 ) {
F_20 ( V_3 , 0 , V_30 ) ;
V_3 -> clock = clock ;
return;
}
F_12 ( V_3 , clock ) ;
F_21 ( V_7 -> V_19 [ V_7 -> V_11 ] , clock ) ;
V_3 -> clock = clock ;
V_14 = V_47 ;
F_20 ( V_3 , V_14 , V_30 ) ;
V_46 = 20 ;
while ( ! ( ( V_14 = F_22 ( V_3 , V_30 ) )
& V_48 ) ) {
if ( V_46 == 0 ) {
F_23 ( V_13 , L_4 ,
F_24 ( V_3 -> V_49 ) ) ;
return;
}
V_46 -- ;
F_25 ( 1 ) ;
}
V_14 |= V_50 ;
F_20 ( V_3 , V_14 , V_30 ) ;
}
static int F_26 ( struct V_2 * V_3 , int V_51 )
{
T_3 V_29 ;
V_29 = F_27 ( V_3 , V_52 ) ;
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
F_28 ( V_3 , V_29 , V_52 ) ;
return 0 ;
}
static void F_29 ( struct V_57 * V_13 , int V_58 )
{
struct V_2 * V_3 = F_30 ( V_13 ) ;
#ifdef F_31
struct V_1 * V_59 = F_2 ( V_3 ) ;
#endif
unsigned long V_60 ;
if ( V_3 ) {
F_32 ( & V_3 -> V_61 , V_60 ) ;
if ( V_58 ) {
F_6 ( & V_13 -> V_13 , L_5 ) ;
#ifdef F_31
F_13 ( V_59 -> V_62 ) ;
#endif
V_3 -> V_60 &= ~ V_63 ;
V_3 -> V_24 |= V_64 ;
} else {
F_6 ( & V_13 -> V_13 , L_6 ) ;
V_3 -> V_60 |= V_63 ;
V_3 -> V_24 &= ~ V_64 ;
#ifdef F_31
F_14 ( V_59 -> V_62 ) ;
#endif
}
F_33 ( & V_3 -> V_65 ) ;
F_34 ( & V_3 -> V_61 , V_60 ) ;
}
}
static T_4 F_35 ( int V_66 , void * V_67 )
{
struct V_1 * V_59 = V_67 ;
int V_68 = F_36 ( V_59 -> V_69 ) ;
if ( V_59 -> V_70 -> V_71 )
V_68 = ! V_68 ;
F_29 ( V_59 -> V_12 , V_68 ) ;
return V_72 ;
}
static void F_37 ( struct V_1 * V_59 )
{
struct V_73 * V_70 = V_59 -> V_70 ;
struct V_45 * V_13 = & V_59 -> V_12 -> V_13 ;
if ( F_38 ( V_13 , V_70 -> V_69 , L_7 ) == 0 ) {
V_59 -> V_69 = V_70 -> V_69 ;
V_59 -> V_74 = F_39 ( V_70 -> V_69 ) ;
if ( V_59 -> V_74 &&
F_40 ( V_59 -> V_74 , NULL ,
F_35 ,
V_75 |
V_76 |
V_77 ,
F_41 ( V_13 ) , V_59 ) == 0 ) {
int V_68 = F_36 ( V_59 -> V_69 ) ;
if ( V_70 -> V_71 )
V_68 = ! V_68 ;
F_29 ( V_59 -> V_12 , V_68 ) ;
} else {
F_42 ( V_13 , L_8 ) ;
V_59 -> V_74 = 0 ;
}
} else {
F_23 ( V_13 , L_9 ) ;
}
}
static int F_43 ( struct V_45 * V_13 ,
struct V_2 * V_3 , struct V_73 * V_70 )
{
struct V_78 * V_79 = V_13 -> V_80 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_81 ;
int V_82 ;
if ( F_44 ( V_79 , L_10 , & V_81 ) )
V_81 = 1 ;
V_70 -> V_81 = V_81 ;
if ( F_45 ( V_79 , L_11 , NULL ) ) {
V_70 -> V_83 = V_84 ;
return 0 ;
}
if ( F_45 ( V_79 , L_12 , NULL ) ) {
V_70 -> V_83 = V_85 ;
return 0 ;
}
V_82 = F_46 ( V_79 , L_13 , 0 ) ;
if ( F_47 ( V_82 ) ) {
V_70 -> V_83 = V_86 ;
V_70 -> V_69 = V_82 ;
V_7 -> V_69 = - 1 ;
if ( F_45 ( V_79 , L_14 , NULL ) )
V_70 -> V_71 = 1 ;
return 0 ;
} else if ( V_82 != - V_87 ) {
F_23 ( V_13 , L_15 ) ;
return - V_88 ;
}
V_70 -> V_83 = V_89 ;
return 0 ;
}
static int F_43 ( struct V_45 * V_13 ,
struct V_2 * V_3 , struct V_73 * V_70 )
{
return - V_88 ;
}
static inline struct V_90 * F_48 (
struct V_57 * V_12 )
{
#ifdef F_49
if ( V_12 -> V_13 . V_80 ) {
const struct V_91 * V_92 ;
V_92 = F_50 ( V_93 , V_12 -> V_13 . V_80 ) ;
return (struct V_90 * ) V_92 -> V_94 ;
}
#endif
return (struct V_90 * )
F_51 ( V_12 ) -> V_95 ;
}
static int F_52 ( struct V_57 * V_12 )
{
struct V_73 * V_70 ;
struct V_90 * V_96 ;
struct V_45 * V_13 = & V_12 -> V_13 ;
struct V_2 * V_3 ;
struct V_1 * V_59 ;
struct V_97 * V_98 ;
int V_99 , V_66 , V_100 , V_101 ;
if ( ! V_12 -> V_13 . V_102 && ! V_12 -> V_13 . V_80 ) {
F_23 ( V_13 , L_16 ) ;
return - V_87 ;
}
V_66 = F_53 ( V_12 , 0 ) ;
if ( V_66 < 0 ) {
F_23 ( V_13 , L_17 ) ;
return V_66 ;
}
V_3 = F_54 ( V_13 , sizeof( struct V_1 ) ) ;
if ( F_55 ( V_3 ) ) {
F_23 ( V_13 , L_18 ) ;
return F_56 ( V_3 ) ;
}
V_59 = F_2 ( V_3 ) ;
V_70 = F_57 ( & V_12 -> V_13 , sizeof( * V_70 ) , V_103 ) ;
if ( ! V_70 ) {
V_99 = - V_104 ;
goto V_105;
}
if ( V_12 -> V_13 . V_80 ) {
V_99 = F_43 ( & V_12 -> V_13 , V_3 , V_70 ) ;
if ( V_99 )
goto V_105;
} else {
memcpy ( V_70 , V_12 -> V_13 . V_102 , sizeof( * V_70 ) ) ;
V_59 -> V_69 = - 1 ;
}
V_96 = F_48 ( V_12 ) ;
V_59 -> V_3 = V_3 ;
V_59 -> V_12 = V_12 ;
V_59 -> V_70 = V_70 ;
F_58 ( V_12 , V_3 ) ;
V_59 -> V_62 = F_59 ( V_13 , L_19 ) ;
if ( F_55 ( V_59 -> V_62 ) ) {
F_23 ( V_13 , L_20 ) ;
V_99 = F_56 ( V_59 -> V_62 ) ;
goto V_105;
}
F_13 ( V_59 -> V_62 ) ;
for ( V_101 = 0 , V_100 = 0 ; V_100 < V_18 ; V_100 ++ ) {
struct V_14 * V_14 ;
char V_106 [ 14 ] ;
snprintf ( V_106 , 14 , L_21 , V_100 ) ;
V_14 = F_59 ( V_13 , V_106 ) ;
if ( F_55 ( V_14 ) )
continue;
V_101 ++ ;
V_59 -> V_19 [ V_100 ] = V_14 ;
V_59 -> V_11 = V_100 ;
F_60 ( V_13 , L_22 ,
V_100 , V_106 , F_9 ( V_14 ) ) ;
}
if ( V_101 == 0 ) {
F_23 ( V_13 , L_23 ) ;
V_99 = - V_87 ;
goto V_107;
}
#ifndef F_31
F_13 ( V_59 -> V_19 [ V_59 -> V_11 ] ) ;
#endif
V_98 = F_61 ( V_12 , V_108 , 0 ) ;
V_3 -> V_9 = F_62 ( & V_12 -> V_13 , V_98 ) ;
if ( F_55 ( V_3 -> V_9 ) ) {
V_99 = F_56 ( V_3 -> V_9 ) ;
goto V_109;
}
if ( V_70 -> V_110 )
V_70 -> V_110 ( V_12 , V_70 -> V_81 ) ;
V_3 -> V_111 = L_24 ;
V_3 -> V_112 = & V_113 ;
V_3 -> V_24 = 0 ;
V_3 -> V_114 = 0 ;
V_3 -> V_66 = V_66 ;
V_3 -> V_24 |= V_115 ;
V_3 -> V_24 |= V_116 ;
if ( V_96 )
V_3 -> V_24 |= V_96 -> V_117 ;
#ifndef F_63
V_3 -> V_24 |= V_118 ;
#endif
V_3 -> V_24 |= V_119 ;
V_3 -> V_24 |= V_120 ;
V_3 -> V_24 |= V_121 ;
if ( V_70 -> V_83 == V_84 ||
V_70 -> V_83 == V_85 )
V_3 -> V_24 |= V_64 ;
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
V_3 -> V_24 |= ( V_127 |
V_128 ) ;
V_3 -> V_24 |= V_129 ;
if ( V_3 -> V_24 & V_25 ) {
V_113 . V_130 = F_19 ;
V_113 . V_131 = F_18 ;
V_113 . V_132 = F_17 ;
}
if ( V_70 -> V_133 )
V_3 -> V_49 -> V_122 |= V_70 -> V_133 ;
if ( V_70 -> V_134 )
V_3 -> V_49 -> V_135 |= V_70 -> V_134 ;
F_64 ( & V_12 -> V_13 ) ;
F_65 ( & V_12 -> V_13 , 50 ) ;
F_66 ( & V_12 -> V_13 ) ;
F_67 ( & V_12 -> V_13 , 1 ) ;
V_99 = F_68 ( V_3 ) ;
if ( V_99 ) {
F_23 ( V_13 , L_25 ) ;
F_69 ( & V_12 -> V_13 ) ;
F_70 ( & V_12 -> V_13 ) ;
goto V_109;
}
if ( V_70 -> V_83 == V_136 && V_70 -> V_137 )
V_70 -> V_137 ( & F_29 ) ;
if ( V_70 -> V_83 == V_86 &&
F_47 ( V_70 -> V_69 ) )
F_37 ( V_59 ) ;
#ifdef F_31
if ( V_70 -> V_83 != V_89 )
F_14 ( V_59 -> V_62 ) ;
#endif
return 0 ;
V_109:
#ifndef F_31
F_14 ( V_59 -> V_19 [ V_59 -> V_11 ] ) ;
#endif
V_107:
F_14 ( V_59 -> V_62 ) ;
V_105:
F_71 ( V_3 ) ;
return V_99 ;
}
static int F_72 ( struct V_57 * V_12 )
{
struct V_2 * V_3 = F_30 ( V_12 ) ;
struct V_1 * V_59 = F_2 ( V_3 ) ;
struct V_73 * V_70 = V_59 -> V_70 ;
if ( V_70 -> V_83 == V_136 && V_70 -> V_138 )
V_70 -> V_138 ( & F_29 ) ;
if ( V_59 -> V_74 )
F_73 ( V_59 -> V_74 , V_59 ) ;
#ifdef F_31
if ( V_70 -> V_83 != V_89 )
F_13 ( V_59 -> V_62 ) ;
#endif
F_74 ( V_3 , 1 ) ;
F_75 ( & V_12 -> V_13 ) ;
F_76 ( & V_12 -> V_13 ) ;
#ifndef F_31
F_14 ( V_59 -> V_19 [ V_59 -> V_11 ] ) ;
#endif
F_14 ( V_59 -> V_62 ) ;
F_71 ( V_3 ) ;
return 0 ;
}
static int F_77 ( struct V_45 * V_13 )
{
struct V_2 * V_3 = F_78 ( V_13 ) ;
return F_79 ( V_3 ) ;
}
static int F_80 ( struct V_45 * V_13 )
{
struct V_2 * V_3 = F_78 ( V_13 ) ;
return F_81 ( V_3 ) ;
}
static int F_82 ( struct V_45 * V_13 )
{
struct V_2 * V_3 = F_78 ( V_13 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_7 -> V_62 ;
int V_99 ;
V_99 = F_83 ( V_3 ) ;
F_14 ( V_7 -> V_19 [ V_7 -> V_11 ] ) ;
F_14 ( V_15 ) ;
return V_99 ;
}
static int F_84 ( struct V_45 * V_13 )
{
struct V_2 * V_3 = F_78 ( V_13 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_7 -> V_62 ;
int V_99 ;
F_13 ( V_15 ) ;
F_13 ( V_7 -> V_19 [ V_7 -> V_11 ] ) ;
V_99 = F_85 ( V_3 ) ;
return V_99 ;
}
