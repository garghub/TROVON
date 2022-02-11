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
struct V_10 * V_11 = V_8 -> V_11 ;
F_9 ( V_8 -> V_8 , L_1 ) ;
V_9 = F_3 ( V_8 , V_12 ) ;
V_9 |= V_13 ;
F_1 ( V_8 , V_12 , V_9 ) ;
F_5 ( V_11 -> V_6 ) ;
V_9 = F_3 ( V_8 , V_12 ) ;
V_9 |= V_14 ;
F_1 ( V_8 , V_12 , V_9 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
int V_4 )
{
T_1 V_15 ;
V_15 = F_3 ( V_2 , V_12 ) ;
if ( ! V_4 )
V_15 &= ~ V_16 ;
else
V_15 |= V_16 ;
F_1 ( V_2 , V_12 , V_15 ) ;
}
static void F_11 ( struct V_1 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
T_1 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
T_2 V_20 ;
T_2 V_21 ;
T_2 V_22 = F_12 ( V_8 -> V_18 ) ;
V_17 = ( V_22 / 7000000 ) - 1 ;
if ( ( V_22 / ( V_17 + 1 ) ) > 12000000 )
V_17 ++ ;
V_19 = ( V_17 >= 2 ) ? 5 : 7 - V_17 ;
V_18 = ( ( V_22 / ( V_17 + 1 ) ) / ( V_11 -> V_23 * 1000 ) ) - ( V_19 << 1 ) ;
V_20 = V_18 >> 1 ;
V_21 = V_18 - V_20 ;
F_1 ( V_8 , V_24 , V_17 ) ;
F_1 ( V_8 , V_25 , V_20 ) ;
F_1 ( V_8 , V_26 , V_21 ) ;
F_13 ( V_8 -> V_8 , L_2 , V_22 , V_18 ) ;
}
static int F_14 ( struct V_1 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
F_10 ( V_8 , 0 ) ;
F_11 ( V_8 ) ;
F_1 ( V_8 , V_27 , 0x08 ) ;
F_13 ( V_8 -> V_8 , L_3 ,
F_3 ( V_8 , V_24 ) ) ;
F_13 ( V_8 -> V_8 , L_4 ,
F_3 ( V_8 , V_26 ) ) ;
F_13 ( V_8 -> V_8 , L_5 ,
F_3 ( V_8 , V_25 ) ) ;
F_13 ( V_8 -> V_8 , L_6 ,
V_11 -> V_23 , V_11 -> V_28 ) ;
F_10 ( V_8 , 1 ) ;
F_1 ( V_8 , V_29 , V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_8 ,
char V_31 )
{
unsigned long V_32 ;
static T_1 V_33 ;
V_32 = V_34 + V_8 -> V_35 . V_32 ;
while ( F_3 ( V_8 , V_36 )
& V_37 ) {
if ( V_33 <= V_38 ) {
if ( F_16 ( V_34 , V_32 ) ) {
F_17 ( V_8 -> V_8 ,
L_7 ) ;
V_33 ++ ;
return - V_39 ;
} else {
V_33 = 0 ;
F_8 ( V_8 ) ;
F_14 ( V_8 ) ;
}
}
if ( V_31 )
F_18 ( 1 ) ;
}
return 0 ;
}
static int
F_19 ( struct V_40 * V_41 , struct V_42 * V_43 , int V_44 )
{
struct V_1 * V_8 = F_20 ( V_41 ) ;
struct V_10 * V_11 = V_8 -> V_11 ;
T_2 V_9 ;
T_1 V_15 ;
int V_45 ;
if ( V_11 -> V_28 )
F_7 ( V_11 -> V_28 ) ;
F_1 ( V_8 , V_46 , V_43 -> V_47 ) ;
V_8 -> V_48 = V_43 -> V_48 ;
V_8 -> V_49 = V_43 -> V_50 ;
V_8 -> V_44 = V_44 ;
F_1 ( V_8 , V_51 , V_8 -> V_49 ) ;
F_21 ( & V_8 -> V_52 ) ;
V_8 -> V_53 = 0 ;
V_9 = V_16 | V_54 ;
if ( V_43 -> V_55 & V_56 )
V_9 |= V_57 ;
if ( ! ( V_43 -> V_55 & V_58 ) )
V_9 |= V_59 ;
if ( V_43 -> V_50 == 0 )
V_9 |= V_60 ;
V_15 = F_3 ( V_8 , V_29 ) ;
if ( V_43 -> V_55 & V_58 )
V_15 |= V_61 ;
else
V_15 |= V_62 ;
F_1 ( V_8 , V_29 , V_15 ) ;
V_8 -> V_63 = 0 ;
F_1 ( V_8 , V_12 , V_9 ) ;
if ( ( ! ( V_43 -> V_55 & V_58 ) ) && V_8 -> V_49 ) {
F_1 ( V_8 , V_64 , * V_8 -> V_48 ++ ) ;
V_8 -> V_49 -- ;
}
V_9 |= V_65 ;
if ( V_44 && V_43 -> V_50 != 0 )
V_9 |= V_14 ;
F_1 ( V_8 , V_12 , V_9 ) ;
V_45 = F_22 ( & V_8 -> V_52 ,
V_8 -> V_35 . V_32 ) ;
if ( V_45 == 0 ) {
F_9 ( V_8 -> V_8 , L_8 ) ;
F_8 ( V_8 ) ;
F_14 ( V_8 ) ;
V_8 -> V_49 = 0 ;
return - V_39 ;
}
if ( V_8 -> V_49 ) {
if ( V_45 >= 0 ) {
F_9 ( V_8 -> V_8 , L_9 ,
V_8 -> V_49 ) ;
V_45 = - V_66 ;
}
V_8 -> V_63 = 1 ;
F_23 () ;
V_8 -> V_49 = 0 ;
}
if ( V_45 < 0 )
return V_45 ;
if ( F_24 ( ! V_8 -> V_53 ) )
return V_43 -> V_50 ;
if ( V_8 -> V_53 & V_67 ) {
F_14 ( V_8 ) ;
return - V_68 ;
}
if ( V_8 -> V_53 & V_69 ) {
if ( V_43 -> V_55 & V_70 )
return V_43 -> V_50 ;
if ( V_44 ) {
V_15 = F_3 ( V_8 , V_12 ) ;
V_15 |= V_14 ;
F_1 ( V_8 , V_12 , V_15 ) ;
}
return - V_66 ;
}
return - V_68 ;
}
static int
F_25 ( struct V_40 * V_41 , struct V_42 V_71 [] , int V_72 )
{
struct V_1 * V_8 = F_20 ( V_41 ) ;
int V_7 ;
int V_73 ;
F_13 ( V_8 -> V_8 , L_10 , V_74 , V_72 ) ;
V_73 = F_15 ( V_8 , 1 ) ;
if ( V_73 < 0 ) {
F_17 ( V_8 -> V_8 , L_7 ) ;
return V_73 ;
}
for ( V_7 = 0 ; V_7 < V_72 ; V_7 ++ ) {
V_73 = F_19 ( V_41 , & V_71 [ V_7 ] , ( V_7 == ( V_72 - 1 ) ) ) ;
F_13 ( V_8 -> V_8 , L_11 , V_74 , V_7 + 1 , V_72 ,
V_73 ) ;
if ( V_73 < 0 )
return V_73 ;
}
#ifdef F_26
F_27 ( & V_8 -> V_75 ) ;
#endif
return V_72 ;
}
static T_2 F_28 ( struct V_40 * V_41 )
{
return V_76 | V_77 ;
}
static void F_29 ( struct V_1 * V_8 )
{
T_1 V_15 = F_3 ( V_8 , V_12 ) ;
V_15 |= V_13 ;
F_1 ( V_8 , V_12 , V_15 ) ;
F_3 ( V_8 , V_78 ) ;
if ( ! V_8 -> V_63 )
F_9 ( V_8 -> V_8 , L_12 ) ;
}
static void F_30 ( struct V_1 * V_8 )
{
T_1 V_15 = F_3 ( V_8 , V_12 ) ;
V_15 |= V_60 | V_14 ;
F_1 ( V_8 , V_12 , V_15 ) ;
if ( ! V_8 -> V_63 )
F_13 ( V_8 -> V_8 , L_13 ) ;
}
static T_3 F_31 ( int V_79 , void * V_80 )
{
struct V_1 * V_8 = V_80 ;
T_2 V_81 ;
int V_82 = 0 ;
T_1 V_15 ;
while ( ( V_81 = F_3 ( V_8 , V_83 ) ) ) {
F_13 ( V_8 -> V_8 , L_14 , V_74 , V_81 ) ;
if ( V_82 ++ == 100 ) {
F_17 ( V_8 -> V_8 , L_15 ) ;
break;
}
switch ( V_81 ) {
case V_84 :
V_8 -> V_53 |= V_67 ;
V_8 -> V_49 = 0 ;
F_27 ( & V_8 -> V_52 ) ;
break;
case V_85 :
V_8 -> V_53 |= V_69 ;
V_8 -> V_49 = 0 ;
F_27 ( & V_8 -> V_52 ) ;
break;
case V_86 :
F_1 ( V_8 ,
V_36 , V_87 ) ;
if ( ( ( V_8 -> V_49 == 0 ) && ( V_8 -> V_44 != 0 ) ) ||
( V_8 -> V_53 & V_69 ) ) {
V_15 = F_3 ( V_8 ,
V_12 ) ;
V_15 |= V_14 ;
F_1 ( V_8 ,
V_12 , V_15 ) ;
}
F_27 ( & V_8 -> V_52 ) ;
break;
case V_88 :
if ( V_8 -> V_49 ) {
* V_8 -> V_48 ++ =
F_3 ( V_8 ,
V_78 ) ;
V_8 -> V_49 -- ;
if ( V_8 -> V_49 )
continue;
F_1 ( V_8 ,
V_36 ,
V_61 ) ;
} else {
F_29 ( V_8 ) ;
}
break;
case V_89 :
if ( V_8 -> V_49 ) {
F_1 ( V_8 , V_64 ,
* V_8 -> V_48 ++ ) ;
V_8 -> V_49 -- ;
if ( V_8 -> V_49 )
continue;
V_15 = F_3 ( V_8 ,
V_29 ) ;
V_15 &= ~ V_62 ;
F_1 ( V_8 ,
V_29 ,
V_15 ) ;
} else {
F_30 ( V_8 ) ;
}
break;
case V_90 :
F_1 ( V_8 ,
V_36 , V_91 ) ;
F_27 ( & V_8 -> V_52 ) ;
break;
case V_92 :
F_13 ( V_8 -> V_8 , L_16 ) ;
break;
default:
F_17 ( V_8 -> V_8 , L_17 , V_81 ) ;
break;
}
}
return V_82 ? V_93 : V_94 ;
}
static int F_32 ( struct V_95 * V_96 ,
unsigned long V_4 , void * V_97 )
{
struct V_1 * V_8 ;
V_8 = F_33 ( V_96 , struct V_1 , V_98 ) ;
if ( V_4 == V_99 ) {
F_34 ( & V_8 -> V_75 ) ;
F_10 ( V_8 , 0 ) ;
} else if ( V_4 == V_100 ) {
F_11 ( V_8 ) ;
F_10 ( V_8 , 1 ) ;
}
return 0 ;
}
static inline int F_35 ( struct V_1 * V_8 )
{
V_8 -> V_98 . V_101 = F_32 ;
return F_36 ( & V_8 -> V_98 ,
V_102 ) ;
}
static inline void F_37 ( struct V_1 * V_8 )
{
F_38 ( & V_8 -> V_98 ,
V_102 ) ;
}
static inline int F_35 ( struct V_1 * V_8 )
{
return 0 ;
}
static inline void F_37 ( struct V_1 * V_8 )
{
}
static int F_39 ( struct V_103 * V_104 )
{
struct V_1 * V_8 ;
struct V_40 * V_41 ;
struct V_105 * V_106 , * V_107 ;
int V_45 ;
V_107 = F_40 ( V_104 , V_108 , 0 ) ;
if ( ! V_107 ) {
F_9 ( & V_104 -> V_8 , L_18 ) ;
return - V_109 ;
}
V_8 = F_41 ( & V_104 -> V_8 , sizeof( struct V_1 ) ,
V_110 ) ;
if ( ! V_8 ) {
F_9 ( & V_104 -> V_8 , L_19 ) ;
return - V_111 ;
}
F_42 ( & V_8 -> V_52 ) ;
#ifdef F_26
F_42 ( & V_8 -> V_75 ) ;
#endif
V_8 -> V_8 = & V_104 -> V_8 ;
V_8 -> V_107 = V_107 -> V_112 ;
V_8 -> V_11 = F_43 ( & V_104 -> V_8 ) ;
F_44 ( V_104 , V_8 ) ;
if ( ! V_8 -> V_11 && V_104 -> V_8 . V_113 ) {
T_2 V_114 ;
V_8 -> V_11 = F_41 ( & V_104 -> V_8 ,
sizeof( struct V_10 ) , V_110 ) ;
if ( ! V_8 -> V_11 )
return - V_111 ;
memcpy ( V_8 -> V_11 , & V_115 ,
sizeof( struct V_10 ) ) ;
if ( ! F_45 ( V_104 -> V_8 . V_113 , L_20 ,
& V_114 ) )
V_8 -> V_11 -> V_23 = V_114 / 1000 ;
} else if ( ! V_8 -> V_11 ) {
V_8 -> V_11 = & V_115 ;
}
V_8 -> V_18 = F_46 ( & V_104 -> V_8 , NULL ) ;
if ( F_47 ( V_8 -> V_18 ) )
return - V_109 ;
F_48 ( V_8 -> V_18 ) ;
V_106 = F_40 ( V_104 , V_116 , 0 ) ;
V_8 -> V_5 = F_49 ( & V_104 -> V_8 , V_106 ) ;
if ( F_47 ( V_8 -> V_5 ) ) {
V_45 = F_50 ( V_8 -> V_5 ) ;
goto V_117;
}
F_14 ( V_8 ) ;
V_45 = F_51 ( & V_104 -> V_8 , V_8 -> V_107 , F_31 , 0 ,
V_104 -> V_118 , V_8 ) ;
if ( V_45 ) {
F_9 ( & V_104 -> V_8 , L_21 , V_8 -> V_107 ) ;
goto V_117;
}
V_45 = F_35 ( V_8 ) ;
if ( V_45 ) {
F_9 ( & V_104 -> V_8 , L_22 ) ;
goto V_117;
}
V_41 = & V_8 -> V_35 ;
F_52 ( V_41 , V_8 ) ;
V_41 -> V_119 = V_120 ;
V_41 -> V_121 = V_122 | V_123 ;
F_53 ( V_41 -> V_118 , L_23 , sizeof( V_41 -> V_118 ) ) ;
V_41 -> V_124 = & V_125 ;
V_41 -> V_8 . V_126 = & V_104 -> V_8 ;
V_41 -> V_32 = V_127 ;
V_41 -> V_8 . V_113 = V_104 -> V_8 . V_113 ;
V_41 -> V_128 = V_104 -> V_129 ;
V_45 = F_54 ( V_41 ) ;
if ( V_45 ) {
F_9 ( & V_104 -> V_8 , L_24 ) ;
goto V_117;
}
return 0 ;
V_117:
F_55 ( V_8 -> V_18 ) ;
V_8 -> V_18 = NULL ;
return V_45 ;
}
static int F_56 ( struct V_103 * V_104 )
{
struct V_1 * V_8 = F_57 ( V_104 ) ;
F_37 ( V_8 ) ;
F_58 ( & V_8 -> V_35 ) ;
F_55 ( V_8 -> V_18 ) ;
V_8 -> V_18 = NULL ;
F_1 ( V_8 , V_12 , 0 ) ;
return 0 ;
}
static int F_59 ( struct V_130 * V_8 )
{
struct V_103 * V_104 = F_60 ( V_8 ) ;
struct V_1 * V_2 = F_57 ( V_104 ) ;
F_10 ( V_2 , 0 ) ;
F_55 ( V_2 -> V_18 ) ;
return 0 ;
}
static int F_61 ( struct V_130 * V_8 )
{
struct V_103 * V_104 = F_60 ( V_8 ) ;
struct V_1 * V_2 = F_57 ( V_104 ) ;
F_48 ( V_2 -> V_18 ) ;
F_10 ( V_2 , 1 ) ;
return 0 ;
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_131 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_131 ) ;
}
