static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( unsigned int V_6 )
{
T_1 V_7 ;
if ( V_6 ) {
for ( V_7 = 0 ; V_7 < 9 ; V_7 ++ ) {
F_6 ( V_6 , 0 ) ;
F_7 ( 20 ) ;
F_6 ( V_6 , 1 ) ;
F_7 ( 20 ) ;
}
}
}
static void F_8 ( struct V_1 * V_8 )
{
T_2 V_9 = 0 ;
struct V_10 * V_11 = V_8 -> V_8 -> V_12 ;
F_9 ( V_8 -> V_8 , L_1 ) ;
V_9 = F_3 ( V_8 , V_13 ) ;
V_9 |= V_14 ;
F_1 ( V_8 , V_13 , V_9 ) ;
if ( V_11 )
F_5 ( V_11 -> V_6 ) ;
V_9 = F_3 ( V_8 , V_13 ) ;
V_9 |= V_15 ;
F_1 ( V_8 , V_13 , V_9 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
int V_4 )
{
T_1 V_16 ;
V_16 = F_3 ( V_2 , V_13 ) ;
if ( ! V_4 )
V_16 &= ~ V_17 ;
else
V_16 |= V_17 ;
F_1 ( V_2 , V_13 , V_16 ) ;
}
static void F_11 ( struct V_1 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_8 -> V_12 ;
T_1 V_18 ;
T_2 V_19 ;
T_2 V_20 ;
T_2 V_21 ;
T_2 V_22 ;
T_2 V_23 = F_12 ( V_8 -> V_19 ) ;
V_18 = ( V_23 / 7000000 ) - 1 ;
if ( ( V_23 / ( V_18 + 1 ) ) > 12000000 )
V_18 ++ ;
V_20 = ( V_18 >= 2 ) ? 5 : 7 - V_18 ;
V_19 = ( ( V_23 / ( V_18 + 1 ) ) / ( V_11 -> V_24 * 1000 ) ) - ( V_20 << 1 ) ;
V_21 = V_19 >> 1 ;
V_22 = V_19 - V_21 ;
F_1 ( V_8 , V_25 , V_18 ) ;
F_1 ( V_8 , V_26 , V_21 ) ;
F_1 ( V_8 , V_27 , V_22 ) ;
F_13 ( V_8 -> V_8 , L_2 , V_23 , V_19 ) ;
}
static int F_14 ( struct V_1 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_8 -> V_12 ;
if ( ! V_11 )
V_11 = & V_28 ;
F_10 ( V_8 , 0 ) ;
F_11 ( V_8 ) ;
F_1 ( V_8 , V_29 , 0x08 ) ;
F_13 ( V_8 -> V_8 , L_3 ,
F_3 ( V_8 , V_25 ) ) ;
F_13 ( V_8 -> V_8 , L_4 ,
F_3 ( V_8 , V_27 ) ) ;
F_13 ( V_8 -> V_8 , L_5 ,
F_3 ( V_8 , V_26 ) ) ;
F_13 ( V_8 -> V_8 , L_6 ,
V_11 -> V_24 , V_11 -> V_30 ) ;
F_10 ( V_8 , 1 ) ;
F_1 ( V_8 , V_31 , V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_8 ,
char V_33 )
{
unsigned long V_34 ;
static T_1 V_35 ;
V_34 = V_36 + V_8 -> V_37 . V_34 ;
while ( F_3 ( V_8 , V_38 )
& V_39 ) {
if ( V_35 <= V_40 ) {
if ( F_16 ( V_36 , V_34 ) ) {
F_17 ( V_8 -> V_8 ,
L_7 ) ;
V_35 ++ ;
return - V_41 ;
} else {
V_35 = 0 ;
F_8 ( V_8 ) ;
F_14 ( V_8 ) ;
}
}
if ( V_33 )
F_18 ( 1 ) ;
}
return 0 ;
}
static int
F_19 ( struct V_42 * V_43 , struct V_44 * V_45 , int V_46 )
{
struct V_1 * V_8 = F_20 ( V_43 ) ;
struct V_10 * V_11 = V_8 -> V_8 -> V_12 ;
T_2 V_9 ;
T_1 V_16 ;
int V_47 ;
if ( ! V_11 )
V_11 = & V_28 ;
if ( V_11 -> V_30 )
F_7 ( V_11 -> V_30 ) ;
F_1 ( V_8 , V_48 , V_45 -> V_49 ) ;
V_8 -> V_50 = V_45 -> V_50 ;
V_8 -> V_51 = V_45 -> V_52 ;
V_8 -> V_46 = V_46 ;
F_1 ( V_8 , V_53 , V_8 -> V_51 ) ;
F_21 ( V_8 -> V_54 ) ;
V_8 -> V_55 = 0 ;
V_9 = V_17 | V_56 ;
if ( V_45 -> V_57 & V_58 )
V_9 |= V_59 ;
if ( ! ( V_45 -> V_57 & V_60 ) )
V_9 |= V_61 ;
if ( V_45 -> V_52 == 0 )
V_9 |= V_62 ;
V_16 = F_3 ( V_8 , V_31 ) ;
if ( V_45 -> V_57 & V_60 )
V_16 |= V_63 ;
else
V_16 |= V_64 ;
F_1 ( V_8 , V_31 , V_16 ) ;
V_8 -> V_65 = 0 ;
F_1 ( V_8 , V_13 , V_9 ) ;
if ( ( ! ( V_45 -> V_57 & V_60 ) ) && V_8 -> V_51 ) {
F_1 ( V_8 , V_66 , * V_8 -> V_50 ++ ) ;
V_8 -> V_51 -- ;
}
V_9 |= V_67 ;
if ( V_46 && V_45 -> V_52 != 0 )
V_9 |= V_15 ;
F_1 ( V_8 , V_13 , V_9 ) ;
V_47 = F_22 ( & V_8 -> V_54 ,
V_8 -> V_37 . V_34 ) ;
if ( V_47 == 0 ) {
F_9 ( V_8 -> V_8 , L_8 ) ;
F_8 ( V_8 ) ;
F_14 ( V_8 ) ;
V_8 -> V_51 = 0 ;
return - V_41 ;
}
if ( V_8 -> V_51 ) {
if ( V_47 >= 0 ) {
F_9 ( V_8 -> V_8 , L_9 ,
V_8 -> V_51 ) ;
V_47 = - V_68 ;
}
V_8 -> V_65 = 1 ;
F_23 () ;
V_8 -> V_51 = 0 ;
}
if ( V_47 < 0 )
return V_47 ;
if ( F_24 ( ! V_8 -> V_55 ) )
return V_45 -> V_52 ;
if ( V_8 -> V_55 & V_69 ) {
F_14 ( V_8 ) ;
return - V_70 ;
}
if ( V_8 -> V_55 & V_71 ) {
if ( V_45 -> V_57 & V_72 )
return V_45 -> V_52 ;
if ( V_46 ) {
V_16 = F_3 ( V_8 , V_13 ) ;
V_16 |= V_15 ;
F_1 ( V_8 , V_13 , V_16 ) ;
}
return - V_68 ;
}
return - V_70 ;
}
static int
F_25 ( struct V_42 * V_43 , struct V_44 V_73 [] , int V_74 )
{
struct V_1 * V_8 = F_20 ( V_43 ) ;
int V_7 ;
int V_75 ;
F_13 ( V_8 -> V_8 , L_10 , V_76 , V_74 ) ;
V_75 = F_15 ( V_8 , 1 ) ;
if ( V_75 < 0 ) {
F_17 ( V_8 -> V_8 , L_7 ) ;
return V_75 ;
}
for ( V_7 = 0 ; V_7 < V_74 ; V_7 ++ ) {
V_75 = F_19 ( V_43 , & V_73 [ V_7 ] , ( V_7 == ( V_74 - 1 ) ) ) ;
F_13 ( V_8 -> V_8 , L_11 , V_76 , V_7 + 1 , V_74 ,
V_75 ) ;
if ( V_75 < 0 )
return V_75 ;
}
#ifdef F_26
F_27 ( & V_8 -> V_77 ) ;
#endif
return V_74 ;
}
static T_2 F_28 ( struct V_42 * V_43 )
{
return V_78 | V_79 ;
}
static void F_29 ( struct V_1 * V_8 )
{
T_1 V_16 = F_3 ( V_8 , V_13 ) ;
V_16 |= V_14 ;
F_1 ( V_8 , V_13 , V_16 ) ;
F_3 ( V_8 , V_80 ) ;
if ( ! V_8 -> V_65 )
F_9 ( V_8 -> V_8 , L_12 ) ;
}
static void F_30 ( struct V_1 * V_8 )
{
T_1 V_16 = F_3 ( V_8 , V_13 ) ;
V_16 |= V_62 | V_15 ;
F_1 ( V_8 , V_13 , V_16 ) ;
if ( ! V_8 -> V_65 )
F_13 ( V_8 -> V_8 , L_13 ) ;
}
static T_3 F_31 ( int V_81 , void * V_82 )
{
struct V_1 * V_8 = V_82 ;
T_2 V_83 ;
int V_84 = 0 ;
T_1 V_16 ;
while ( ( V_83 = F_3 ( V_8 , V_85 ) ) ) {
F_13 ( V_8 -> V_8 , L_14 , V_76 , V_83 ) ;
if ( V_84 ++ == 100 ) {
F_17 ( V_8 -> V_8 , L_15 ) ;
break;
}
switch ( V_83 ) {
case V_86 :
V_8 -> V_55 |= V_69 ;
V_8 -> V_51 = 0 ;
F_27 ( & V_8 -> V_54 ) ;
break;
case V_87 :
V_8 -> V_55 |= V_71 ;
V_8 -> V_51 = 0 ;
F_27 ( & V_8 -> V_54 ) ;
break;
case V_88 :
F_1 ( V_8 ,
V_38 , V_89 ) ;
if ( ( ( V_8 -> V_51 == 0 ) && ( V_8 -> V_46 != 0 ) ) ||
( V_8 -> V_55 & V_71 ) ) {
V_16 = F_3 ( V_8 ,
V_13 ) ;
V_16 |= V_15 ;
F_1 ( V_8 ,
V_13 , V_16 ) ;
}
F_27 ( & V_8 -> V_54 ) ;
break;
case V_90 :
if ( V_8 -> V_51 ) {
* V_8 -> V_50 ++ =
F_3 ( V_8 ,
V_80 ) ;
V_8 -> V_51 -- ;
if ( V_8 -> V_51 )
continue;
F_1 ( V_8 ,
V_38 ,
V_63 ) ;
} else {
F_29 ( V_8 ) ;
}
break;
case V_91 :
if ( V_8 -> V_51 ) {
F_1 ( V_8 , V_66 ,
* V_8 -> V_50 ++ ) ;
V_8 -> V_51 -- ;
if ( V_8 -> V_51 )
continue;
V_16 = F_3 ( V_8 ,
V_31 ) ;
V_16 &= ~ V_64 ;
F_1 ( V_8 ,
V_31 ,
V_16 ) ;
} else {
F_30 ( V_8 ) ;
}
break;
case V_92 :
F_1 ( V_8 ,
V_38 , V_93 ) ;
F_27 ( & V_8 -> V_54 ) ;
break;
case V_94 :
F_13 ( V_8 -> V_8 , L_16 ) ;
break;
default:
F_17 ( V_8 -> V_8 , L_17 , V_83 ) ;
break;
}
}
return V_84 ? V_95 : V_96 ;
}
static int F_32 ( struct V_97 * V_98 ,
unsigned long V_4 , void * V_99 )
{
struct V_1 * V_8 ;
V_8 = F_33 ( V_98 , struct V_1 , V_100 ) ;
if ( V_4 == V_101 ) {
F_34 ( & V_8 -> V_77 ) ;
F_10 ( V_8 , 0 ) ;
} else if ( V_4 == V_102 ) {
F_11 ( V_8 ) ;
F_10 ( V_8 , 1 ) ;
}
return 0 ;
}
static inline int F_35 ( struct V_1 * V_8 )
{
V_8 -> V_100 . V_103 = F_32 ;
return F_36 ( & V_8 -> V_100 ,
V_104 ) ;
}
static inline void F_37 ( struct V_1 * V_8 )
{
F_38 ( & V_8 -> V_100 ,
V_104 ) ;
}
static inline int F_35 ( struct V_1 * V_8 )
{
return 0 ;
}
static inline void F_37 ( struct V_1 * V_8 )
{
}
static int F_39 ( struct V_105 * V_106 )
{
struct V_1 * V_8 ;
struct V_42 * V_43 ;
struct V_107 * V_108 , * V_109 , * V_110 ;
int V_47 ;
V_108 = F_40 ( V_106 , V_111 , 0 ) ;
if ( ! V_108 ) {
F_9 ( & V_106 -> V_8 , L_18 ) ;
return - V_112 ;
}
V_109 = F_40 ( V_106 , V_113 , 0 ) ;
if ( ! V_109 ) {
F_9 ( & V_106 -> V_8 , L_19 ) ;
return - V_112 ;
}
V_110 = F_41 ( V_108 -> V_114 , F_42 ( V_108 ) ,
V_106 -> V_115 ) ;
if ( ! V_110 ) {
F_9 ( & V_106 -> V_8 , L_20 ) ;
return - V_116 ;
}
V_8 = F_43 ( sizeof( struct V_1 ) , V_117 ) ;
if ( ! V_8 ) {
V_47 = - V_118 ;
goto V_119;
}
F_44 ( & V_8 -> V_54 ) ;
#ifdef F_26
F_44 ( & V_8 -> V_77 ) ;
#endif
V_8 -> V_8 = F_45 ( & V_106 -> V_8 ) ;
V_8 -> V_109 = V_109 -> V_114 ;
F_46 ( V_106 , V_8 ) ;
V_8 -> V_19 = F_47 ( & V_106 -> V_8 , NULL ) ;
if ( F_48 ( V_8 -> V_19 ) ) {
V_47 = - V_112 ;
goto V_120;
}
F_49 ( V_8 -> V_19 ) ;
V_8 -> V_5 = F_50 ( V_108 -> V_114 , F_42 ( V_108 ) ) ;
if ( ! V_8 -> V_5 ) {
V_47 = - V_116 ;
goto V_121;
}
F_14 ( V_8 ) ;
V_47 = F_51 ( V_8 -> V_109 , F_31 , 0 , V_106 -> V_115 , V_8 ) ;
if ( V_47 ) {
F_9 ( & V_106 -> V_8 , L_21 , V_8 -> V_109 ) ;
goto V_122;
}
V_47 = F_35 ( V_8 ) ;
if ( V_47 ) {
F_9 ( & V_106 -> V_8 , L_22 ) ;
goto V_123;
}
V_43 = & V_8 -> V_37 ;
F_52 ( V_43 , V_8 ) ;
V_43 -> V_124 = V_125 ;
V_43 -> V_126 = V_127 ;
F_53 ( V_43 -> V_115 , L_23 , sizeof( V_43 -> V_115 ) ) ;
V_43 -> V_128 = & V_129 ;
V_43 -> V_8 . V_130 = & V_106 -> V_8 ;
V_43 -> V_34 = V_131 ;
V_43 -> V_132 = V_106 -> V_133 ;
V_47 = F_54 ( V_43 ) ;
if ( V_47 ) {
F_9 ( & V_106 -> V_8 , L_24 ) ;
goto V_123;
}
return 0 ;
V_123:
F_55 ( V_8 -> V_109 , V_8 ) ;
V_122:
F_56 ( V_8 -> V_5 ) ;
V_121:
F_57 ( V_8 -> V_19 ) ;
F_58 ( V_8 -> V_19 ) ;
V_8 -> V_19 = NULL ;
V_120:
F_46 ( V_106 , NULL ) ;
F_59 ( & V_106 -> V_8 ) ;
F_60 ( V_8 ) ;
V_119:
F_61 ( V_108 -> V_114 , F_42 ( V_108 ) ) ;
return V_47 ;
}
static int F_62 ( struct V_105 * V_106 )
{
struct V_1 * V_8 = F_63 ( V_106 ) ;
struct V_107 * V_108 ;
F_37 ( V_8 ) ;
F_46 ( V_106 , NULL ) ;
F_64 ( & V_8 -> V_37 ) ;
F_59 ( & V_106 -> V_8 ) ;
F_57 ( V_8 -> V_19 ) ;
F_58 ( V_8 -> V_19 ) ;
V_8 -> V_19 = NULL ;
F_1 ( V_8 , V_13 , 0 ) ;
F_55 ( V_134 , V_8 ) ;
F_56 ( V_8 -> V_5 ) ;
F_60 ( V_8 ) ;
V_108 = F_40 ( V_106 , V_111 , 0 ) ;
F_61 ( V_108 -> V_114 , F_42 ( V_108 ) ) ;
return 0 ;
}
static int F_65 ( struct V_135 * V_8 )
{
struct V_105 * V_106 = F_66 ( V_8 ) ;
struct V_1 * V_2 = F_63 ( V_106 ) ;
F_10 ( V_2 , 0 ) ;
F_57 ( V_2 -> V_19 ) ;
return 0 ;
}
static int F_67 ( struct V_135 * V_8 )
{
struct V_105 * V_106 = F_66 ( V_8 ) ;
struct V_1 * V_2 = F_63 ( V_106 ) ;
F_49 ( V_2 -> V_19 ) ;
F_10 ( V_2 , 1 ) ;
return 0 ;
}
static int T_4 F_68 ( void )
{
return F_69 ( & V_136 ) ;
}
static void T_5 F_70 ( void )
{
F_71 ( & V_136 ) ;
}
