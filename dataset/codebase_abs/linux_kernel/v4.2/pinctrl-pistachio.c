static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline struct V_6 * F_5 ( struct V_7 * V_8 )
{
return F_6 ( V_8 , struct V_6 , V_7 ) ;
}
static inline struct V_6 * F_7 ( struct V_9 * V_10 )
{
return F_5 ( F_8 ( V_10 ) ) ;
}
static inline T_1 F_9 ( struct V_6 * V_11 , T_1 V_3 )
{
return F_2 ( V_11 -> V_4 + V_3 ) ;
}
static inline void F_10 ( struct V_6 * V_11 , T_1 V_5 ,
T_1 V_3 )
{
F_4 ( V_5 , V_11 -> V_4 + V_3 ) ;
}
static inline void F_11 ( struct V_6 * V_11 ,
T_1 V_3 , unsigned int V_12 , T_1 V_5 )
{
F_10 ( V_11 , ( 0x10000 | V_5 ) << V_12 , V_3 ) ;
}
static inline void F_12 ( struct V_6 * V_11 ,
unsigned V_13 )
{
F_11 ( V_11 , V_14 , V_13 , 1 ) ;
}
static inline void F_13 ( struct V_6 * V_11 ,
unsigned V_13 )
{
F_11 ( V_11 , V_14 , V_13 , 0 ) ;
}
static int F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
return V_2 -> V_17 ;
}
static const char * F_16 ( struct V_15 * V_16 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
return V_2 -> V_19 [ V_18 ] . V_20 ;
}
static int F_17 ( struct V_15 * V_16 ,
unsigned V_18 ,
const unsigned * * V_21 ,
unsigned * V_22 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
* V_21 = & V_2 -> V_19 [ V_18 ] . V_23 ;
* V_22 = 1 ;
return 0 ;
}
static int F_18 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
return V_2 -> V_24 ;
}
static const char *
F_19 ( struct V_15 * V_16 , unsigned V_25 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
return V_2 -> V_26 [ V_25 ] . V_20 ;
}
static int F_20 ( struct V_15 * V_16 ,
unsigned V_25 ,
const char * const * * V_19 ,
unsigned * const V_27 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
* V_19 = V_2 -> V_26 [ V_25 ] . V_19 ;
* V_27 = V_2 -> V_26 [ V_25 ] . V_17 ;
return 0 ;
}
static int F_21 ( struct V_15 * V_16 ,
unsigned V_25 , unsigned V_18 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
const struct V_28 * V_29 = & V_2 -> V_19 [ V_18 ] ;
const struct V_30 * V_31 = & V_2 -> V_26 [ V_25 ] ;
struct V_32 * V_33 ;
unsigned int V_34 ;
T_1 V_5 ;
if ( V_29 -> V_35 > 0 ) {
for ( V_34 = 0 ; V_34 < F_22 ( V_29 -> V_36 ) ; V_34 ++ ) {
if ( V_29 -> V_36 [ V_34 ] == V_25 )
break;
}
if ( V_34 == F_22 ( V_29 -> V_36 ) ) {
F_23 ( V_2 -> V_37 , L_1 ,
V_18 , V_25 ) ;
return - V_38 ;
}
V_5 = F_1 ( V_2 , V_29 -> V_35 ) ;
V_5 &= ~ ( V_29 -> V_39 << V_29 -> V_40 ) ;
V_5 |= V_34 << V_29 -> V_40 ;
F_3 ( V_2 , V_5 , V_29 -> V_35 ) ;
if ( V_31 -> V_41 ) {
for ( V_34 = 0 ; V_34 < V_31 -> V_42 ; V_34 ++ ) {
if ( V_31 -> V_41 [ V_34 ] == V_18 )
break;
}
if ( F_24 ( V_34 == V_31 -> V_42 ) )
return - V_38 ;
V_5 = F_1 ( V_2 , V_31 -> V_43 ) ;
V_5 &= ~ ( V_31 -> V_44 << V_31 -> V_45 ) ;
V_5 |= V_34 << V_31 -> V_45 ;
F_3 ( V_2 , V_5 , V_31 -> V_43 ) ;
}
}
V_33 = F_25 ( V_2 -> V_16 , V_29 -> V_23 ) ;
if ( V_33 )
F_13 ( F_5 ( V_33 -> V_8 ) , V_29 -> V_23 - V_33 -> V_46 ) ;
return 0 ;
}
static int F_26 ( struct V_15 * V_16 , unsigned V_23 ,
unsigned long * V_47 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
enum V_48 V_49 = F_27 ( * V_47 ) ;
T_1 V_5 , V_50 ;
switch ( V_49 ) {
case V_51 :
V_5 = F_1 ( V_2 , F_28 ( V_23 ) ) ;
V_50 = ! ! ( V_5 & F_29 ( V_23 ) ) ;
break;
case V_52 :
V_5 = F_1 ( V_2 , F_30 ( V_23 ) ) >>
F_31 ( V_23 ) ;
V_50 = ( V_5 & V_53 ) == V_54 ;
break;
case V_55 :
V_5 = F_1 ( V_2 , F_30 ( V_23 ) ) >>
F_31 ( V_23 ) ;
V_50 = ( V_5 & V_53 ) == V_56 ;
break;
case V_57 :
V_5 = F_1 ( V_2 , F_30 ( V_23 ) ) >>
F_31 ( V_23 ) ;
V_50 = ( V_5 & V_53 ) == V_58 ;
break;
case V_59 :
V_5 = F_1 ( V_2 , F_30 ( V_23 ) ) >>
F_31 ( V_23 ) ;
V_50 = ( V_5 & V_53 ) == V_60 ;
break;
case V_61 :
V_5 = F_1 ( V_2 , F_32 ( V_23 ) ) ;
V_50 = ! ! ( V_5 & F_33 ( V_23 ) ) ;
break;
case V_62 :
V_5 = F_1 ( V_2 , F_34 ( V_23 ) ) >>
F_35 ( V_23 ) ;
switch ( V_5 & V_63 ) {
case V_64 :
V_50 = 2 ;
break;
case V_65 :
V_50 = 4 ;
break;
case V_66 :
V_50 = 8 ;
break;
case V_67 :
default:
V_50 = 12 ;
break;
}
break;
default:
F_36 ( V_2 -> V_37 , L_2 , V_49 ) ;
return - V_68 ;
}
* V_47 = F_37 ( V_49 , V_50 ) ;
return 0 ;
}
static int F_38 ( struct V_15 * V_16 , unsigned V_23 ,
unsigned long * V_69 , unsigned V_70 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
enum V_48 V_49 ;
T_1 V_71 , V_5 , V_50 ;
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_70 ; V_34 ++ ) {
V_49 = F_27 ( V_69 [ V_34 ] ) ;
V_50 = F_39 ( V_69 [ V_34 ] ) ;
switch ( V_49 ) {
case V_51 :
V_5 = F_1 ( V_2 , F_28 ( V_23 ) ) ;
if ( V_50 )
V_5 |= F_29 ( V_23 ) ;
else
V_5 &= ~ F_29 ( V_23 ) ;
F_3 ( V_2 , V_5 , F_28 ( V_23 ) ) ;
break;
case V_52 :
V_5 = F_1 ( V_2 , F_30 ( V_23 ) ) ;
V_5 &= ~ ( V_53 << F_31 ( V_23 ) ) ;
V_5 |= V_54 << F_31 ( V_23 ) ;
F_3 ( V_2 , V_5 , F_30 ( V_23 ) ) ;
break;
case V_55 :
V_5 = F_1 ( V_2 , F_30 ( V_23 ) ) ;
V_5 &= ~ ( V_53 << F_31 ( V_23 ) ) ;
V_5 |= V_56 << F_31 ( V_23 ) ;
F_3 ( V_2 , V_5 , F_30 ( V_23 ) ) ;
break;
case V_57 :
V_5 = F_1 ( V_2 , F_30 ( V_23 ) ) ;
V_5 &= ~ ( V_53 << F_31 ( V_23 ) ) ;
V_5 |= V_58 << F_31 ( V_23 ) ;
F_3 ( V_2 , V_5 , F_30 ( V_23 ) ) ;
break;
case V_59 :
V_5 = F_1 ( V_2 , F_30 ( V_23 ) ) ;
V_5 &= ~ ( V_53 << F_31 ( V_23 ) ) ;
V_5 |= V_60 << F_31 ( V_23 ) ;
F_3 ( V_2 , V_5 , F_30 ( V_23 ) ) ;
break;
case V_61 :
V_5 = F_1 ( V_2 , F_32 ( V_23 ) ) ;
if ( V_50 )
V_5 |= F_33 ( V_23 ) ;
else
V_5 &= ~ F_33 ( V_23 ) ;
F_3 ( V_2 , V_5 , F_32 ( V_23 ) ) ;
break;
case V_62 :
V_5 = F_1 ( V_2 , F_34 ( V_23 ) ) ;
V_5 &= ~ ( V_63 <<
F_35 ( V_23 ) ) ;
switch ( V_50 ) {
case 2 :
V_71 = V_64 ;
break;
case 4 :
V_71 = V_65 ;
break;
case 8 :
V_71 = V_66 ;
break;
case 12 :
V_71 = V_67 ;
break;
default:
F_23 ( V_2 -> V_37 ,
L_3 ,
V_50 ) ;
return - V_38 ;
}
V_5 |= V_71 << F_35 ( V_23 ) ;
F_3 ( V_2 , V_5 , F_34 ( V_23 ) ) ;
break;
default:
F_23 ( V_2 -> V_37 , L_2 ,
V_49 ) ;
return - V_68 ;
}
}
return 0 ;
}
static int F_40 ( struct V_7 * V_72 , unsigned V_13 )
{
return F_41 ( V_72 -> V_4 + V_13 ) ;
}
static void F_42 ( struct V_7 * V_72 , unsigned V_13 )
{
F_43 ( V_72 -> V_4 + V_13 ) ;
}
static int F_44 ( struct V_7 * V_72 , unsigned V_13 )
{
struct V_6 * V_11 = F_5 ( V_72 ) ;
return ! ( F_9 ( V_11 , V_73 ) & F_45 ( V_13 ) ) ;
}
static int F_46 ( struct V_7 * V_72 , unsigned V_13 )
{
struct V_6 * V_11 = F_5 ( V_72 ) ;
T_1 V_3 ;
if ( F_9 ( V_11 , V_73 ) & F_45 ( V_13 ) )
V_3 = V_74 ;
else
V_3 = V_75 ;
return ! ! ( F_9 ( V_11 , V_3 ) & F_45 ( V_13 ) ) ;
}
static void F_47 ( struct V_7 * V_72 , unsigned V_13 ,
int V_76 )
{
struct V_6 * V_11 = F_5 ( V_72 ) ;
F_11 ( V_11 , V_74 , V_13 , ! ! V_76 ) ;
}
static int F_48 ( struct V_7 * V_72 ,
unsigned V_13 )
{
struct V_6 * V_11 = F_5 ( V_72 ) ;
F_11 ( V_11 , V_73 , V_13 , 0 ) ;
F_12 ( V_11 , V_13 ) ;
return 0 ;
}
static int F_49 ( struct V_7 * V_72 ,
unsigned V_13 , int V_76 )
{
struct V_6 * V_11 = F_5 ( V_72 ) ;
F_47 ( V_72 , V_13 , V_76 ) ;
F_11 ( V_11 , V_73 , V_13 , 1 ) ;
F_12 ( V_11 , V_13 ) ;
return 0 ;
}
static void F_50 ( struct V_9 * V_77 )
{
struct V_6 * V_11 = F_7 ( V_77 ) ;
F_11 ( V_11 , V_78 , V_77 -> V_79 , 0 ) ;
}
static void F_51 ( struct V_9 * V_77 )
{
struct V_6 * V_11 = F_7 ( V_77 ) ;
F_11 ( V_11 , V_80 , V_77 -> V_79 , 0 ) ;
}
static void F_52 ( struct V_9 * V_77 )
{
struct V_6 * V_11 = F_7 ( V_77 ) ;
F_11 ( V_11 , V_80 , V_77 -> V_79 , 1 ) ;
}
static unsigned int F_53 ( struct V_9 * V_77 )
{
struct V_7 * V_72 = F_8 ( V_77 ) ;
F_48 ( V_72 , V_77 -> V_79 ) ;
F_52 ( V_77 ) ;
return 0 ;
}
static int F_54 ( struct V_9 * V_77 , unsigned int type )
{
struct V_6 * V_11 = F_7 ( V_77 ) ;
switch ( type & V_81 ) {
case V_82 :
F_11 ( V_11 , V_83 , V_77 -> V_79 , 1 ) ;
F_11 ( V_11 , V_84 , V_77 -> V_79 ,
V_85 ) ;
F_11 ( V_11 , V_86 , V_77 -> V_79 ,
V_87 ) ;
break;
case V_88 :
F_11 ( V_11 , V_83 , V_77 -> V_79 , 0 ) ;
F_11 ( V_11 , V_84 , V_77 -> V_79 ,
V_85 ) ;
F_11 ( V_11 , V_86 , V_77 -> V_79 ,
V_87 ) ;
break;
case V_89 :
F_11 ( V_11 , V_84 , V_77 -> V_79 ,
V_85 ) ;
F_11 ( V_11 , V_86 , V_77 -> V_79 ,
V_90 ) ;
break;
case V_91 :
F_11 ( V_11 , V_83 , V_77 -> V_79 , 1 ) ;
F_11 ( V_11 , V_84 , V_77 -> V_79 ,
V_92 ) ;
break;
case V_93 :
F_11 ( V_11 , V_83 , V_77 -> V_79 , 0 ) ;
F_11 ( V_11 , V_84 , V_77 -> V_79 ,
V_92 ) ;
break;
default:
return - V_38 ;
}
if ( type & V_94 )
F_55 ( V_77 -> V_95 , V_96 ) ;
else
F_55 ( V_77 -> V_95 , V_97 ) ;
return 0 ;
}
static void F_56 ( unsigned int V_95 , struct V_98 * V_99 )
{
struct V_7 * V_8 = F_57 ( V_95 ) ;
struct V_6 * V_11 = F_5 ( V_8 ) ;
struct V_100 * V_72 = F_58 ( V_95 ) ;
unsigned long V_101 ;
unsigned int V_23 ;
F_59 ( V_72 , V_99 ) ;
V_101 = F_9 ( V_11 , V_78 ) &
F_9 ( V_11 , V_80 ) ;
F_60 (pin, &pending, 16 )
F_61 ( F_62 ( V_8 -> V_102 , V_23 ) ) ;
F_63 ( V_72 , V_99 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_103 * V_104 = V_2 -> V_37 -> V_105 ;
struct V_6 * V_11 ;
unsigned int V_34 ;
int V_95 , V_106 = 0 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_107 ; V_34 ++ ) {
char V_108 [ sizeof( L_4 ) ] ;
struct V_103 * V_109 ;
snprintf ( V_108 , sizeof( V_108 ) , L_5 , V_34 ) ;
V_109 = F_65 ( V_104 , V_108 ) ;
if ( ! V_109 ) {
F_23 ( V_2 -> V_37 , L_6 , V_34 ) ;
V_106 = - V_110 ;
goto V_111;
}
if ( ! F_66 ( V_109 , L_7 , NULL ) ) {
F_23 ( V_2 -> V_37 ,
L_8 , V_34 ) ;
V_106 = - V_110 ;
goto V_111;
}
V_95 = F_67 ( V_109 , 0 ) ;
if ( V_95 < 0 ) {
F_23 ( V_2 -> V_37 , L_9 , V_34 , V_95 ) ;
V_106 = V_95 ;
goto V_111;
}
V_11 = & V_2 -> V_112 [ V_34 ] ;
V_11 -> V_2 = V_2 ;
V_11 -> V_4 = V_2 -> V_4 + F_68 ( V_34 ) ;
V_11 -> V_7 . V_37 = V_2 -> V_37 ;
V_11 -> V_7 . V_105 = V_109 ;
V_106 = F_69 ( & V_11 -> V_7 ) ;
if ( V_106 < 0 ) {
F_23 ( V_2 -> V_37 , L_10 ,
V_34 , V_106 ) ;
goto V_111;
}
V_106 = F_70 ( & V_11 -> V_7 , & V_11 -> V_100 ,
0 , V_96 , V_113 ) ;
if ( V_106 < 0 ) {
F_23 ( V_2 -> V_37 , L_11 ,
V_34 , V_106 ) ;
F_71 ( & V_11 -> V_7 ) ;
goto V_111;
}
F_72 ( & V_11 -> V_7 , & V_11 -> V_100 ,
V_95 , F_56 ) ;
V_106 = F_73 ( & V_11 -> V_7 ,
F_74 ( V_2 -> V_37 ) , 0 ,
V_11 -> V_46 , V_11 -> V_114 ) ;
if ( V_106 < 0 ) {
F_23 ( V_2 -> V_37 , L_12 ,
V_34 , V_106 ) ;
F_71 ( & V_11 -> V_7 ) ;
goto V_111;
}
}
return 0 ;
V_111:
for (; V_34 > 0 ; V_34 -- ) {
V_11 = & V_2 -> V_112 [ V_34 - 1 ] ;
F_71 ( & V_11 -> V_7 ) ;
}
return V_106 ;
}
static int F_75 ( struct V_115 * V_116 )
{
struct V_1 * V_2 ;
struct V_117 * V_118 ;
int V_106 ;
V_2 = F_76 ( & V_116 -> V_37 , sizeof( * V_2 ) , V_119 ) ;
if ( ! V_2 )
return - V_120 ;
V_2 -> V_37 = & V_116 -> V_37 ;
F_77 ( & V_116 -> V_37 , V_2 ) ;
V_118 = F_78 ( V_116 , V_121 , 0 ) ;
V_2 -> V_4 = F_79 ( & V_116 -> V_37 , V_118 ) ;
if ( F_80 ( V_2 -> V_4 ) )
return F_81 ( V_2 -> V_4 ) ;
V_2 -> V_21 = V_122 ;
V_2 -> V_114 = F_22 ( V_122 ) ;
V_2 -> V_26 = V_123 ;
V_2 -> V_24 = F_22 ( V_123 ) ;
V_2 -> V_19 = V_124 ;
V_2 -> V_17 = F_22 ( V_124 ) ;
V_2 -> V_112 = V_125 ;
V_2 -> V_107 = F_22 ( V_125 ) ;
V_126 . V_21 = V_2 -> V_21 ;
V_126 . V_114 = V_2 -> V_114 ;
V_2 -> V_16 = F_82 ( & V_126 , & V_116 -> V_37 ,
V_2 ) ;
if ( F_80 ( V_2 -> V_16 ) ) {
F_23 ( & V_116 -> V_37 , L_13 ) ;
return F_81 ( V_2 -> V_16 ) ;
}
V_106 = F_64 ( V_2 ) ;
if ( V_106 < 0 ) {
F_83 ( V_2 -> V_16 ) ;
return V_106 ;
}
return 0 ;
}
static int T_2 F_84 ( void )
{
return F_85 ( & V_127 ) ;
}
