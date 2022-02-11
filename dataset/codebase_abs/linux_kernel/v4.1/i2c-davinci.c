static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
int V_4 )
{
T_1 V_6 ;
V_6 = F_3 ( V_2 , V_7 ) ;
if ( ! V_4 )
V_6 &= ~ V_8 ;
else
V_6 |= V_8 ;
F_1 ( V_2 , V_7 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_1 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
T_2 V_15 ;
T_2 V_16 ;
T_2 V_17 = F_7 ( V_9 -> V_13 ) ;
V_12 = ( V_17 / 7000000 ) - 1 ;
if ( ( V_17 / ( V_12 + 1 ) ) > 12000000 )
V_12 ++ ;
V_14 = ( V_12 >= 2 ) ? 5 : 7 - V_12 ;
V_13 = ( ( V_17 / ( V_12 + 1 ) ) / ( V_11 -> V_18 * 1000 ) ) - ( V_14 << 1 ) ;
V_15 = V_13 >> 1 ;
V_16 = V_13 - V_15 ;
F_1 ( V_9 , V_19 , V_12 ) ;
F_1 ( V_9 , V_20 , V_15 ) ;
F_1 ( V_9 , V_21 , V_16 ) ;
F_8 ( V_9 -> V_9 , L_1 , V_17 , V_13 ) ;
}
static int F_9 ( struct V_1 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
F_5 ( V_9 , 0 ) ;
F_6 ( V_9 ) ;
F_1 ( V_9 , V_22 , 0x08 ) ;
F_8 ( V_9 -> V_9 , L_2 ,
F_3 ( V_9 , V_19 ) ) ;
F_8 ( V_9 -> V_9 , L_3 ,
F_3 ( V_9 , V_21 ) ) ;
F_8 ( V_9 -> V_9 , L_4 ,
F_3 ( V_9 , V_20 ) ) ;
F_8 ( V_9 -> V_9 , L_5 ,
V_11 -> V_18 , V_11 -> V_23 ) ;
F_5 ( V_9 , 1 ) ;
F_1 ( V_9 , V_24 , V_25 ) ;
return 0 ;
}
static void F_10 ( struct V_26 * V_27 )
{
struct V_1 * V_9 = F_11 ( V_27 ) ;
F_1 ( V_9 , V_24 , 0 ) ;
F_5 ( V_9 , 0 ) ;
}
static void F_12 ( struct V_26 * V_27 )
{
struct V_1 * V_9 = F_11 ( V_27 ) ;
F_9 ( V_9 ) ;
}
static void F_13 ( struct V_26 * V_27 , int V_4 )
{
struct V_1 * V_9 = F_11 ( V_27 ) ;
if ( V_4 )
F_1 ( V_9 , V_28 ,
V_29 ) ;
else
F_1 ( V_9 , V_30 ,
V_31 ) ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_1 * V_9 = F_11 ( V_27 ) ;
int V_4 ;
V_4 = F_3 ( V_9 , V_32 ) ;
return V_4 & V_33 ;
}
static int F_15 ( struct V_26 * V_27 )
{
struct V_1 * V_9 = F_11 ( V_27 ) ;
int V_4 ;
V_4 = F_3 ( V_9 , V_32 ) ;
return V_4 & V_34 ;
}
static void F_16 ( struct V_26 * V_27 )
{
struct V_1 * V_9 = F_11 ( V_27 ) ;
F_10 ( V_27 ) ;
F_1 ( V_9 , V_35 , V_36 ) ;
F_1 ( V_9 , V_37 ,
V_38 ) ;
}
static void F_17 ( struct V_26 * V_27 )
{
struct V_1 * V_9 = F_11 ( V_27 ) ;
F_1 ( V_9 , V_37 , 0 ) ;
F_12 ( V_27 ) ;
}
static int F_18 ( struct V_1 * V_9 ,
char V_39 )
{
unsigned long V_40 ;
static T_1 V_41 ;
V_40 = V_42 + V_9 -> V_43 . V_40 ;
while ( F_3 ( V_9 , V_44 )
& V_45 ) {
if ( V_41 <= V_46 ) {
if ( F_19 ( V_42 , V_40 ) ) {
F_20 ( V_9 -> V_9 ,
L_6 ) ;
V_41 ++ ;
return - V_47 ;
} else {
V_41 = 0 ;
F_21 ( & V_9 -> V_43 ) ;
}
}
if ( V_39 )
F_22 ( 1 ) ;
}
return 0 ;
}
static int
F_23 ( struct V_26 * V_27 , struct V_48 * V_49 , int V_50 )
{
struct V_1 * V_9 = F_11 ( V_27 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
T_2 V_51 ;
T_1 V_6 ;
unsigned long V_52 ;
if ( V_11 -> V_23 )
F_24 ( V_11 -> V_23 ) ;
F_1 ( V_9 , V_53 , V_49 -> V_54 ) ;
V_9 -> V_55 = V_49 -> V_55 ;
V_9 -> V_56 = V_49 -> V_57 ;
V_9 -> V_50 = V_50 ;
F_1 ( V_9 , V_58 , V_9 -> V_56 ) ;
F_25 ( & V_9 -> V_59 ) ;
V_9 -> V_60 = 0 ;
V_51 = V_8 | V_61 ;
if ( V_49 -> V_62 & V_63 )
V_51 |= V_64 ;
if ( ! ( V_49 -> V_62 & V_65 ) )
V_51 |= V_66 ;
if ( V_49 -> V_57 == 0 )
V_51 |= V_67 ;
V_6 = F_3 ( V_9 , V_24 ) ;
if ( V_49 -> V_62 & V_65 )
V_6 |= V_68 ;
else
V_6 |= V_69 ;
F_1 ( V_9 , V_24 , V_6 ) ;
V_9 -> V_70 = 0 ;
F_1 ( V_9 , V_7 , V_51 ) ;
if ( ( ! ( V_49 -> V_62 & V_65 ) ) && V_9 -> V_56 ) {
F_1 ( V_9 , V_71 , * V_9 -> V_55 ++ ) ;
V_9 -> V_56 -- ;
}
V_51 |= V_72 ;
if ( V_50 && V_49 -> V_57 != 0 )
V_51 |= V_73 ;
F_1 ( V_9 , V_7 , V_51 ) ;
V_52 = F_26 ( & V_9 -> V_59 ,
V_9 -> V_43 . V_40 ) ;
if ( ! V_52 ) {
F_27 ( V_9 -> V_9 , L_7 ) ;
F_21 ( V_27 ) ;
V_9 -> V_56 = 0 ;
return - V_47 ;
}
if ( V_9 -> V_56 ) {
F_27 ( V_9 -> V_9 , L_8 ,
V_9 -> V_56 ) ;
V_9 -> V_70 = 1 ;
F_28 () ;
V_9 -> V_56 = 0 ;
return - V_74 ;
}
if ( F_29 ( ! V_9 -> V_60 ) )
return V_49 -> V_57 ;
if ( V_9 -> V_60 & V_75 ) {
F_9 ( V_9 ) ;
return - V_76 ;
}
if ( V_9 -> V_60 & V_77 ) {
if ( V_49 -> V_62 & V_78 )
return V_49 -> V_57 ;
V_6 = F_3 ( V_9 , V_7 ) ;
V_6 |= V_73 ;
F_1 ( V_9 , V_7 , V_6 ) ;
return - V_74 ;
}
return - V_76 ;
}
static int
F_30 ( struct V_26 * V_27 , struct V_48 V_79 [] , int V_80 )
{
struct V_1 * V_9 = F_11 ( V_27 ) ;
int V_81 ;
int V_82 ;
F_8 ( V_9 -> V_9 , L_9 , V_83 , V_80 ) ;
V_82 = F_18 ( V_9 , 1 ) ;
if ( V_82 < 0 ) {
F_20 ( V_9 -> V_9 , L_6 ) ;
return V_82 ;
}
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
V_82 = F_23 ( V_27 , & V_79 [ V_81 ] , ( V_81 == ( V_80 - 1 ) ) ) ;
F_8 ( V_9 -> V_9 , L_10 , V_83 , V_81 + 1 , V_80 ,
V_82 ) ;
if ( V_82 < 0 )
return V_82 ;
}
#ifdef F_31
F_32 ( & V_9 -> V_84 ) ;
#endif
return V_80 ;
}
static T_2 F_33 ( struct V_26 * V_27 )
{
return V_85 | V_86 ;
}
static void F_34 ( struct V_1 * V_9 )
{
T_1 V_6 = F_3 ( V_9 , V_7 ) ;
V_6 |= V_87 ;
F_1 ( V_9 , V_7 , V_6 ) ;
F_3 ( V_9 , V_88 ) ;
if ( ! V_9 -> V_70 )
F_27 ( V_9 -> V_9 , L_11 ) ;
}
static void F_35 ( struct V_1 * V_9 )
{
T_1 V_6 = F_3 ( V_9 , V_7 ) ;
V_6 |= V_67 | V_73 ;
F_1 ( V_9 , V_7 , V_6 ) ;
if ( ! V_9 -> V_70 )
F_8 ( V_9 -> V_9 , L_12 ) ;
}
static T_3 F_36 ( int V_89 , void * V_90 )
{
struct V_1 * V_9 = V_90 ;
T_2 V_91 ;
int V_92 = 0 ;
T_1 V_6 ;
while ( ( V_91 = F_3 ( V_9 , V_93 ) ) ) {
F_8 ( V_9 -> V_9 , L_13 , V_83 , V_91 ) ;
if ( V_92 ++ == 100 ) {
F_20 ( V_9 -> V_9 , L_14 ) ;
break;
}
switch ( V_91 ) {
case V_94 :
V_9 -> V_60 |= V_75 ;
V_9 -> V_56 = 0 ;
F_32 ( & V_9 -> V_59 ) ;
break;
case V_95 :
V_9 -> V_60 |= V_77 ;
V_9 -> V_56 = 0 ;
F_32 ( & V_9 -> V_59 ) ;
break;
case V_96 :
F_1 ( V_9 ,
V_44 , V_97 ) ;
if ( ( ( V_9 -> V_56 == 0 ) && ( V_9 -> V_50 != 0 ) ) ||
( V_9 -> V_60 & V_77 ) ) {
V_6 = F_3 ( V_9 ,
V_7 ) ;
V_6 |= V_73 ;
F_1 ( V_9 ,
V_7 , V_6 ) ;
}
F_32 ( & V_9 -> V_59 ) ;
break;
case V_98 :
if ( V_9 -> V_56 ) {
* V_9 -> V_55 ++ =
F_3 ( V_9 ,
V_88 ) ;
V_9 -> V_56 -- ;
if ( V_9 -> V_56 )
continue;
F_1 ( V_9 ,
V_44 ,
V_68 ) ;
} else {
F_34 ( V_9 ) ;
}
break;
case V_99 :
if ( V_9 -> V_56 ) {
F_1 ( V_9 , V_71 ,
* V_9 -> V_55 ++ ) ;
V_9 -> V_56 -- ;
if ( V_9 -> V_56 )
continue;
V_6 = F_3 ( V_9 ,
V_24 ) ;
V_6 &= ~ V_69 ;
F_1 ( V_9 ,
V_24 ,
V_6 ) ;
} else {
F_35 ( V_9 ) ;
}
break;
case V_100 :
F_1 ( V_9 ,
V_44 , V_101 ) ;
F_32 ( & V_9 -> V_59 ) ;
break;
case V_102 :
F_8 ( V_9 -> V_9 , L_15 ) ;
break;
default:
F_20 ( V_9 -> V_9 , L_16 , V_91 ) ;
break;
}
}
return V_92 ? V_103 : V_104 ;
}
static int F_37 ( struct V_105 * V_106 ,
unsigned long V_4 , void * V_107 )
{
struct V_1 * V_9 ;
V_9 = F_38 ( V_106 , struct V_1 , V_108 ) ;
if ( V_4 == V_109 ) {
F_39 ( & V_9 -> V_84 ) ;
F_5 ( V_9 , 0 ) ;
} else if ( V_4 == V_110 ) {
F_6 ( V_9 ) ;
F_5 ( V_9 , 1 ) ;
}
return 0 ;
}
static inline int F_40 ( struct V_1 * V_9 )
{
V_9 -> V_108 . V_111 = F_37 ;
return F_41 ( & V_9 -> V_108 ,
V_112 ) ;
}
static inline void F_42 ( struct V_1 * V_9 )
{
F_43 ( & V_9 -> V_108 ,
V_112 ) ;
}
static inline int F_40 ( struct V_1 * V_9 )
{
return 0 ;
}
static inline void F_42 ( struct V_1 * V_9 )
{
}
static int F_44 ( struct V_113 * V_114 )
{
struct V_1 * V_9 ;
struct V_26 * V_27 ;
struct V_115 * V_116 ;
int V_117 , V_118 ;
V_118 = F_45 ( V_114 , 0 ) ;
if ( V_118 <= 0 ) {
if ( ! V_118 )
V_118 = - V_119 ;
if ( V_118 != - V_120 )
F_27 ( & V_114 -> V_9 ,
L_17 , V_118 ) ;
return V_118 ;
}
V_9 = F_46 ( & V_114 -> V_9 , sizeof( struct V_1 ) ,
V_121 ) ;
if ( ! V_9 ) {
F_27 ( & V_114 -> V_9 , L_18 ) ;
return - V_122 ;
}
F_47 ( & V_9 -> V_59 ) ;
#ifdef F_31
F_47 ( & V_9 -> V_84 ) ;
#endif
V_9 -> V_9 = & V_114 -> V_9 ;
V_9 -> V_118 = V_118 ;
V_9 -> V_11 = F_48 ( & V_114 -> V_9 ) ;
F_49 ( V_114 , V_9 ) ;
if ( ! V_9 -> V_11 && V_114 -> V_9 . V_123 ) {
T_2 V_124 ;
V_9 -> V_11 = F_46 ( & V_114 -> V_9 ,
sizeof( struct V_10 ) , V_121 ) ;
if ( ! V_9 -> V_11 )
return - V_122 ;
memcpy ( V_9 -> V_11 , & V_125 ,
sizeof( struct V_10 ) ) ;
if ( ! F_50 ( V_114 -> V_9 . V_123 , L_19 ,
& V_124 ) )
V_9 -> V_11 -> V_18 = V_124 / 1000 ;
V_9 -> V_11 -> V_126 =
F_51 ( V_114 -> V_9 . V_123 ,
L_20 ) ;
} else if ( ! V_9 -> V_11 ) {
V_9 -> V_11 = & V_125 ;
}
V_9 -> V_13 = F_52 ( & V_114 -> V_9 , NULL ) ;
if ( F_53 ( V_9 -> V_13 ) )
return - V_127 ;
F_54 ( V_9 -> V_13 ) ;
V_116 = F_55 ( V_114 , V_128 , 0 ) ;
V_9 -> V_5 = F_56 ( & V_114 -> V_9 , V_116 ) ;
if ( F_53 ( V_9 -> V_5 ) ) {
V_117 = F_57 ( V_9 -> V_5 ) ;
goto V_129;
}
F_9 ( V_9 ) ;
V_117 = F_58 ( & V_114 -> V_9 , V_9 -> V_118 , F_36 , 0 ,
V_114 -> V_130 , V_9 ) ;
if ( V_117 ) {
F_27 ( & V_114 -> V_9 , L_21 , V_9 -> V_118 ) ;
goto V_129;
}
V_117 = F_40 ( V_9 ) ;
if ( V_117 ) {
F_27 ( & V_114 -> V_9 , L_22 ) ;
goto V_129;
}
V_27 = & V_9 -> V_43 ;
F_59 ( V_27 , V_9 ) ;
V_27 -> V_131 = V_132 ;
V_27 -> V_133 = V_134 ;
F_60 ( V_27 -> V_130 , L_23 , sizeof( V_27 -> V_130 ) ) ;
V_27 -> V_135 = & V_136 ;
V_27 -> V_9 . V_137 = & V_114 -> V_9 ;
V_27 -> V_40 = V_138 ;
V_27 -> V_9 . V_123 = V_114 -> V_9 . V_123 ;
if ( V_9 -> V_11 -> V_126 )
V_27 -> V_139 = & V_140 ;
else if ( V_9 -> V_11 -> V_141 ) {
V_27 -> V_139 = & V_142 ;
V_27 -> V_139 -> V_143 = V_9 -> V_11 -> V_141 ;
V_27 -> V_139 -> V_144 = V_9 -> V_11 -> V_145 ;
}
V_27 -> V_146 = V_114 -> V_147 ;
V_117 = F_61 ( V_27 ) ;
if ( V_117 ) {
F_27 ( & V_114 -> V_9 , L_24 ) ;
goto V_129;
}
return 0 ;
V_129:
F_62 ( V_9 -> V_13 ) ;
V_9 -> V_13 = NULL ;
return V_117 ;
}
static int F_63 ( struct V_113 * V_114 )
{
struct V_1 * V_9 = F_64 ( V_114 ) ;
F_42 ( V_9 ) ;
F_65 ( & V_9 -> V_43 ) ;
F_62 ( V_9 -> V_13 ) ;
V_9 -> V_13 = NULL ;
F_1 ( V_9 , V_7 , 0 ) ;
return 0 ;
}
static int F_66 ( struct V_148 * V_9 )
{
struct V_113 * V_114 = F_67 ( V_9 ) ;
struct V_1 * V_2 = F_64 ( V_114 ) ;
F_5 ( V_2 , 0 ) ;
F_62 ( V_2 -> V_13 ) ;
return 0 ;
}
static int F_68 ( struct V_148 * V_9 )
{
struct V_113 * V_114 = F_67 ( V_9 ) ;
struct V_1 * V_2 = F_64 ( V_114 ) ;
F_54 ( V_2 -> V_13 ) ;
F_5 ( V_2 , 1 ) ;
return 0 ;
}
static int T_4 F_69 ( void )
{
return F_70 ( & V_149 ) ;
}
static void T_5 F_71 ( void )
{
F_72 ( & V_149 ) ;
}
