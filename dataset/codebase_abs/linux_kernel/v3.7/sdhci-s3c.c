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
if ( clock == 0 )
return;
F_12 ( V_3 , clock ) ;
F_20 ( V_7 -> V_19 [ V_7 -> V_11 ] , clock ) ;
V_3 -> clock = clock ;
V_14 = V_47 ;
F_21 ( V_3 , V_14 , V_30 ) ;
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
F_21 ( V_3 , V_14 , V_30 ) ;
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
struct V_1 * V_59 = F_2 ( V_3 ) ;
unsigned long V_60 ;
if ( V_3 ) {
F_31 ( & V_3 -> V_61 , V_60 ) ;
if ( V_58 ) {
F_6 ( & V_13 -> V_13 , L_5 ) ;
#ifdef F_32
F_13 ( V_59 -> V_62 ) ;
#endif
V_3 -> V_60 &= ~ V_63 ;
V_3 -> V_24 |= V_64 ;
} else {
F_6 ( & V_13 -> V_13 , L_6 ) ;
V_3 -> V_60 |= V_63 ;
V_3 -> V_24 &= ~ V_64 ;
#ifdef F_32
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
if ( F_38 ( V_70 -> V_69 , L_7 ) == 0 ) {
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
static int T_5 F_43 ( struct V_45 * V_13 ,
struct V_2 * V_3 , struct V_73 * V_70 )
{
struct V_78 * V_79 = V_13 -> V_80 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_81 ;
int V_82 , V_83 , V_84 ;
if ( F_44 ( V_79 , L_10 , & V_81 ) )
V_81 = 1 ;
V_70 -> V_81 = V_81 ;
V_7 -> V_85 = F_45 ( V_13 , F_46 ( V_70 -> V_81 ) *
sizeof( int ) , V_86 ) ;
if ( ! V_7 -> V_85 )
return - V_87 ;
if ( F_47 ( V_79 , L_11 , 0 ) ) {
V_70 -> V_88 = V_89 ;
goto V_90;
}
if ( F_47 ( V_79 , L_12 , 0 ) ) {
V_70 -> V_88 = V_91 ;
goto V_90;
}
V_82 = F_48 ( V_79 , L_13 , 0 ) ;
if ( F_49 ( V_82 ) ) {
V_70 -> V_88 = V_92 ;
goto V_93;
} else if ( V_82 != - V_94 ) {
F_23 ( V_13 , L_14 ) ;
return - V_95 ;
}
V_82 = F_48 ( V_79 , L_15 , 0 ) ;
if ( F_49 ( V_82 ) ) {
V_70 -> V_88 = V_96 ;
goto V_93;
} else if ( V_82 != - V_94 ) {
F_23 ( V_13 , L_14 ) ;
return - V_95 ;
}
F_50 ( V_13 , L_16 ) ;
V_70 -> V_88 = V_89 ;
V_93:
if ( V_70 -> V_88 == V_92 ) {
V_70 -> V_69 = V_82 ;
V_7 -> V_69 = - 1 ;
if ( F_47 ( V_79 , L_17 , NULL ) )
V_70 -> V_71 = 1 ;
} else if ( V_70 -> V_88 == V_96 ) {
V_84 = F_38 ( V_82 , L_18 ) ;
if ( V_84 ) {
F_23 ( V_13 , L_19 ) ;
return - V_95 ;
}
V_7 -> V_69 = V_82 ;
}
V_90:
for ( V_83 = 0 ; V_83 < F_46 ( V_70 -> V_81 ) ; V_83 ++ ) {
V_82 = F_51 ( V_79 , V_83 ) ;
if ( ! F_49 ( V_82 ) ) {
F_23 ( V_13 , L_20 , V_83 ) ;
goto V_97;
}
V_7 -> V_85 [ V_83 ] = V_82 ;
}
for ( V_83 = 0 ; V_83 < F_46 ( V_70 -> V_81 ) ; V_83 ++ ) {
V_84 = F_38 ( V_7 -> V_85 [ V_83 ] , L_21 ) ;
if ( V_84 ) {
F_23 ( V_13 , L_22 , V_83 ) ;
goto V_98;
}
}
return 0 ;
V_98:
while ( -- V_83 >= 0 )
F_52 ( V_7 -> V_85 [ V_83 ] ) ;
V_97:
if ( V_70 -> V_88 == V_96 )
F_52 ( V_7 -> V_69 ) ;
return - V_95 ;
}
static int T_5 F_43 ( struct V_45 * V_13 ,
struct V_2 * V_3 , struct V_73 * V_70 )
{
return - V_95 ;
}
static inline struct V_99 * F_53 (
struct V_57 * V_12 )
{
#ifdef F_54
if ( V_12 -> V_13 . V_80 ) {
const struct V_100 * V_101 ;
V_101 = F_55 ( V_102 , V_12 -> V_13 . V_80 ) ;
return (struct V_99 * ) V_101 -> V_103 ;
}
#endif
return (struct V_99 * )
F_56 ( V_12 ) -> V_104 ;
}
static int T_5 F_57 ( struct V_57 * V_12 )
{
struct V_73 * V_70 ;
struct V_99 * V_105 ;
struct V_45 * V_13 = & V_12 -> V_13 ;
struct V_2 * V_3 ;
struct V_1 * V_59 ;
struct V_106 * V_107 ;
int V_84 , V_66 , V_108 , V_109 ;
if ( ! V_12 -> V_13 . V_110 && ! V_12 -> V_13 . V_80 ) {
F_23 ( V_13 , L_23 ) ;
return - V_94 ;
}
V_66 = F_58 ( V_12 , 0 ) ;
if ( V_66 < 0 ) {
F_23 ( V_13 , L_24 ) ;
return V_66 ;
}
V_3 = F_59 ( V_13 , sizeof( struct V_1 ) ) ;
if ( F_60 ( V_3 ) ) {
F_23 ( V_13 , L_25 ) ;
return F_61 ( V_3 ) ;
}
V_59 = F_2 ( V_3 ) ;
V_70 = F_45 ( & V_12 -> V_13 , sizeof( * V_70 ) , V_86 ) ;
if ( ! V_70 ) {
V_84 = - V_87 ;
goto V_111;
}
if ( V_12 -> V_13 . V_80 ) {
V_84 = F_43 ( & V_12 -> V_13 , V_3 , V_70 ) ;
if ( V_84 )
goto V_111;
} else {
memcpy ( V_70 , V_12 -> V_13 . V_110 , sizeof( * V_70 ) ) ;
V_59 -> V_69 = - 1 ;
}
V_105 = F_53 ( V_12 ) ;
V_59 -> V_3 = V_3 ;
V_59 -> V_12 = V_12 ;
V_59 -> V_70 = V_70 ;
F_62 ( V_12 , V_3 ) ;
V_59 -> V_62 = F_63 ( V_13 , L_26 ) ;
if ( F_60 ( V_59 -> V_62 ) ) {
F_23 ( V_13 , L_27 ) ;
V_84 = F_61 ( V_59 -> V_62 ) ;
goto V_112;
}
F_13 ( V_59 -> V_62 ) ;
for ( V_109 = 0 , V_108 = 0 ; V_108 < V_18 ; V_108 ++ ) {
struct V_14 * V_14 ;
char V_113 [ 14 ] ;
snprintf ( V_113 , 14 , L_28 , V_108 ) ;
V_14 = F_63 ( V_13 , V_113 ) ;
if ( F_60 ( V_14 ) )
continue;
V_109 ++ ;
V_59 -> V_19 [ V_108 ] = V_14 ;
V_59 -> V_11 = V_108 ;
F_50 ( V_13 , L_29 ,
V_108 , V_113 , F_9 ( V_14 ) ) ;
}
if ( V_109 == 0 ) {
F_23 ( V_13 , L_30 ) ;
V_84 = - V_94 ;
goto V_114;
}
#ifndef F_32
F_13 ( V_59 -> V_19 [ V_59 -> V_11 ] ) ;
#endif
V_107 = F_64 ( V_12 , V_115 , 0 ) ;
V_3 -> V_9 = F_65 ( & V_12 -> V_13 , V_107 ) ;
if ( ! V_3 -> V_9 ) {
F_23 ( V_13 , L_31 ) ;
V_84 = - V_116 ;
goto V_117;
}
if ( V_70 -> V_118 )
V_70 -> V_118 ( V_12 , V_70 -> V_81 ) ;
V_3 -> V_119 = L_32 ;
V_3 -> V_120 = & V_121 ;
V_3 -> V_24 = 0 ;
V_3 -> V_66 = V_66 ;
V_3 -> V_24 |= V_122 ;
V_3 -> V_24 |= V_123 ;
if ( V_105 )
V_3 -> V_24 |= V_105 -> V_124 ;
#ifndef F_66
V_3 -> V_24 |= V_125 ;
#endif
V_3 -> V_24 |= V_126 ;
V_3 -> V_24 |= V_127 ;
V_3 -> V_24 |= V_128 ;
if ( V_70 -> V_88 == V_89 ||
V_70 -> V_88 == V_91 )
V_3 -> V_24 |= V_64 ;
if ( V_70 -> V_88 == V_91 )
V_3 -> V_49 -> V_129 = V_130 ;
switch ( V_70 -> V_81 ) {
case 8 :
V_3 -> V_49 -> V_129 |= V_131 ;
case 4 :
V_3 -> V_49 -> V_129 |= V_132 ;
break;
}
if ( V_70 -> V_133 )
V_3 -> V_49 -> V_133 |= V_70 -> V_133 ;
V_3 -> V_24 |= ( V_134 |
V_135 ) ;
V_3 -> V_24 |= V_136 ;
if ( V_3 -> V_24 & V_25 ) {
V_121 . V_137 = F_19 ;
V_121 . V_138 = F_18 ;
V_121 . V_139 = F_17 ;
}
if ( V_70 -> V_140 )
V_3 -> V_49 -> V_129 |= V_70 -> V_140 ;
if ( V_70 -> V_141 )
V_3 -> V_49 -> V_142 |= V_70 -> V_141 ;
F_67 ( & V_12 -> V_13 ) ;
F_68 ( & V_12 -> V_13 , 50 ) ;
F_69 ( & V_12 -> V_13 ) ;
F_70 ( & V_12 -> V_13 , 1 ) ;
V_84 = F_71 ( V_3 ) ;
if ( V_84 ) {
F_23 ( V_13 , L_33 ) ;
F_72 ( & V_12 -> V_13 ) ;
F_73 ( & V_12 -> V_13 ) ;
goto V_117;
}
if ( V_70 -> V_88 == V_143 && V_70 -> V_144 )
V_70 -> V_144 ( & F_29 ) ;
if ( V_70 -> V_88 == V_92 &&
F_49 ( V_70 -> V_69 ) )
F_37 ( V_59 ) ;
#ifdef F_32
if ( V_70 -> V_88 != V_96 )
F_14 ( V_59 -> V_62 ) ;
#endif
return 0 ;
V_117:
#ifndef F_32
F_14 ( V_59 -> V_19 [ V_59 -> V_11 ] ) ;
#endif
for ( V_108 = 0 ; V_108 < V_18 ; V_108 ++ ) {
if ( V_59 -> V_19 [ V_108 ] ) {
F_74 ( V_59 -> V_19 [ V_108 ] ) ;
}
}
V_114:
F_14 ( V_59 -> V_62 ) ;
F_74 ( V_59 -> V_62 ) ;
V_112:
for ( V_108 = 0 ; V_108 < F_46 ( V_59 -> V_70 -> V_81 ) ; V_108 ++ )
F_52 ( V_59 -> V_85 [ V_108 ] ) ;
if ( V_70 -> V_88 == V_96 )
F_52 ( V_59 -> V_69 ) ;
V_111:
F_75 ( V_3 ) ;
return V_84 ;
}
static int T_6 F_76 ( struct V_57 * V_12 )
{
struct V_2 * V_3 = F_30 ( V_12 ) ;
struct V_1 * V_59 = F_2 ( V_3 ) ;
struct V_73 * V_70 = V_59 -> V_70 ;
int V_108 ;
if ( V_70 -> V_88 == V_143 && V_70 -> V_145 )
V_70 -> V_145 ( & F_29 ) ;
if ( V_59 -> V_74 )
F_77 ( V_59 -> V_74 , V_59 ) ;
if ( F_49 ( V_59 -> V_69 ) )
F_52 ( V_59 -> V_69 ) ;
#ifdef F_32
if ( V_70 -> V_88 != V_96 )
F_13 ( V_59 -> V_62 ) ;
#endif
F_78 ( V_3 , 1 ) ;
F_79 ( & V_12 -> V_13 ) ;
F_80 ( & V_12 -> V_13 ) ;
#ifndef F_32
F_14 ( V_59 -> V_19 [ V_59 -> V_11 ] ) ;
#endif
for ( V_108 = 0 ; V_108 < V_18 ; V_108 ++ ) {
if ( V_59 -> V_19 [ V_108 ] ) {
F_74 ( V_59 -> V_19 [ V_108 ] ) ;
}
}
F_14 ( V_59 -> V_62 ) ;
F_74 ( V_59 -> V_62 ) ;
if ( V_12 -> V_13 . V_80 ) {
for ( V_108 = 0 ; V_108 < F_46 ( V_59 -> V_70 -> V_81 ) ; V_108 ++ )
F_52 ( V_59 -> V_85 [ V_108 ] ) ;
}
F_75 ( V_3 ) ;
F_62 ( V_12 , NULL ) ;
return 0 ;
}
static int F_81 ( struct V_45 * V_13 )
{
struct V_2 * V_3 = F_82 ( V_13 ) ;
return F_83 ( V_3 ) ;
}
static int F_84 ( struct V_45 * V_13 )
{
struct V_2 * V_3 = F_82 ( V_13 ) ;
return F_85 ( V_3 ) ;
}
static int F_86 ( struct V_45 * V_13 )
{
struct V_2 * V_3 = F_82 ( V_13 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_7 -> V_62 ;
int V_84 ;
V_84 = F_87 ( V_3 ) ;
F_14 ( V_7 -> V_19 [ V_7 -> V_11 ] ) ;
F_14 ( V_15 ) ;
return V_84 ;
}
static int F_88 ( struct V_45 * V_13 )
{
struct V_2 * V_3 = F_82 ( V_13 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_7 -> V_62 ;
int V_84 ;
F_13 ( V_15 ) ;
F_13 ( V_7 -> V_19 [ V_7 -> V_11 ] ) ;
V_84 = F_89 ( V_3 ) ;
return V_84 ;
}
