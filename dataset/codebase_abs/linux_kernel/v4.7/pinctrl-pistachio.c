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
return F_6 ( F_7 ( V_8 ) ) ;
}
static inline T_1 F_8 ( struct V_6 * V_9 , T_1 V_3 )
{
return F_2 ( V_9 -> V_4 + V_3 ) ;
}
static inline void F_9 ( struct V_6 * V_9 , T_1 V_5 ,
T_1 V_3 )
{
F_4 ( V_5 , V_9 -> V_4 + V_3 ) ;
}
static inline void F_10 ( struct V_6 * V_9 ,
T_1 V_3 , unsigned int V_10 , T_1 V_5 )
{
F_9 ( V_9 , ( 0x10000 | V_5 ) << V_10 , V_3 ) ;
}
static inline void F_11 ( struct V_6 * V_9 ,
unsigned V_11 )
{
F_10 ( V_9 , V_12 , V_11 , 1 ) ;
}
static inline void F_12 ( struct V_6 * V_9 ,
unsigned V_11 )
{
F_10 ( V_9 , V_12 , V_11 , 0 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
return V_2 -> V_15 ;
}
static const char * F_15 ( struct V_13 * V_14 ,
unsigned V_16 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
return V_2 -> V_17 [ V_16 ] . V_18 ;
}
static int F_16 ( struct V_13 * V_14 ,
unsigned V_16 ,
const unsigned * * V_19 ,
unsigned * V_20 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
* V_19 = & V_2 -> V_17 [ V_16 ] . V_21 ;
* V_20 = 1 ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
return V_2 -> V_22 ;
}
static const char *
F_18 ( struct V_13 * V_14 , unsigned V_23 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
return V_2 -> V_24 [ V_23 ] . V_18 ;
}
static int F_19 ( struct V_13 * V_14 ,
unsigned V_23 ,
const char * const * * V_17 ,
unsigned * const V_25 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
* V_17 = V_2 -> V_24 [ V_23 ] . V_17 ;
* V_25 = V_2 -> V_24 [ V_23 ] . V_15 ;
return 0 ;
}
static int F_20 ( struct V_13 * V_14 ,
unsigned V_23 , unsigned V_16 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
const struct V_26 * V_27 = & V_2 -> V_17 [ V_16 ] ;
const struct V_28 * V_29 = & V_2 -> V_24 [ V_23 ] ;
struct V_30 * V_31 ;
unsigned int V_32 ;
T_1 V_5 ;
if ( V_27 -> V_33 > 0 ) {
for ( V_32 = 0 ; V_32 < F_21 ( V_27 -> V_34 ) ; V_32 ++ ) {
if ( V_27 -> V_34 [ V_32 ] == V_23 )
break;
}
if ( V_32 == F_21 ( V_27 -> V_34 ) ) {
F_22 ( V_2 -> V_35 , L_1 ,
V_16 , V_23 ) ;
return - V_36 ;
}
V_5 = F_1 ( V_2 , V_27 -> V_33 ) ;
V_5 &= ~ ( V_27 -> V_37 << V_27 -> V_38 ) ;
V_5 |= V_32 << V_27 -> V_38 ;
F_3 ( V_2 , V_5 , V_27 -> V_33 ) ;
if ( V_29 -> V_39 ) {
for ( V_32 = 0 ; V_32 < V_29 -> V_40 ; V_32 ++ ) {
if ( V_29 -> V_39 [ V_32 ] == V_16 )
break;
}
if ( F_23 ( V_32 == V_29 -> V_40 ) )
return - V_36 ;
V_5 = F_1 ( V_2 , V_29 -> V_41 ) ;
V_5 &= ~ ( V_29 -> V_42 << V_29 -> V_43 ) ;
V_5 |= V_32 << V_29 -> V_43 ;
F_3 ( V_2 , V_5 , V_29 -> V_41 ) ;
}
}
V_31 = F_24 ( V_2 -> V_14 , V_27 -> V_21 ) ;
if ( V_31 )
F_12 ( F_6 ( V_31 -> V_44 ) , V_27 -> V_21 - V_31 -> V_45 ) ;
return 0 ;
}
static int F_25 ( struct V_13 * V_14 , unsigned V_21 ,
unsigned long * V_46 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
enum V_47 V_48 = F_26 ( * V_46 ) ;
T_1 V_5 , V_49 ;
switch ( V_48 ) {
case V_50 :
V_5 = F_1 ( V_2 , F_27 ( V_21 ) ) ;
V_49 = ! ! ( V_5 & F_28 ( V_21 ) ) ;
break;
case V_51 :
V_5 = F_1 ( V_2 , F_29 ( V_21 ) ) >>
F_30 ( V_21 ) ;
V_49 = ( V_5 & V_52 ) == V_53 ;
break;
case V_54 :
V_5 = F_1 ( V_2 , F_29 ( V_21 ) ) >>
F_30 ( V_21 ) ;
V_49 = ( V_5 & V_52 ) == V_55 ;
break;
case V_56 :
V_5 = F_1 ( V_2 , F_29 ( V_21 ) ) >>
F_30 ( V_21 ) ;
V_49 = ( V_5 & V_52 ) == V_57 ;
break;
case V_58 :
V_5 = F_1 ( V_2 , F_29 ( V_21 ) ) >>
F_30 ( V_21 ) ;
V_49 = ( V_5 & V_52 ) == V_59 ;
break;
case V_60 :
V_5 = F_1 ( V_2 , F_31 ( V_21 ) ) ;
V_49 = ! ! ( V_5 & F_32 ( V_21 ) ) ;
break;
case V_61 :
V_5 = F_1 ( V_2 , F_33 ( V_21 ) ) >>
F_34 ( V_21 ) ;
switch ( V_5 & V_62 ) {
case V_63 :
V_49 = 2 ;
break;
case V_64 :
V_49 = 4 ;
break;
case V_65 :
V_49 = 8 ;
break;
case V_66 :
default:
V_49 = 12 ;
break;
}
break;
default:
F_35 ( V_2 -> V_35 , L_2 , V_48 ) ;
return - V_67 ;
}
* V_46 = F_36 ( V_48 , V_49 ) ;
return 0 ;
}
static int F_37 ( struct V_13 * V_14 , unsigned V_21 ,
unsigned long * V_68 , unsigned V_69 )
{
struct V_1 * V_2 = F_14 ( V_14 ) ;
enum V_47 V_48 ;
T_1 V_70 , V_5 , V_49 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_69 ; V_32 ++ ) {
V_48 = F_26 ( V_68 [ V_32 ] ) ;
V_49 = F_38 ( V_68 [ V_32 ] ) ;
switch ( V_48 ) {
case V_50 :
V_5 = F_1 ( V_2 , F_27 ( V_21 ) ) ;
if ( V_49 )
V_5 |= F_28 ( V_21 ) ;
else
V_5 &= ~ F_28 ( V_21 ) ;
F_3 ( V_2 , V_5 , F_27 ( V_21 ) ) ;
break;
case V_51 :
V_5 = F_1 ( V_2 , F_29 ( V_21 ) ) ;
V_5 &= ~ ( V_52 << F_30 ( V_21 ) ) ;
V_5 |= V_53 << F_30 ( V_21 ) ;
F_3 ( V_2 , V_5 , F_29 ( V_21 ) ) ;
break;
case V_54 :
V_5 = F_1 ( V_2 , F_29 ( V_21 ) ) ;
V_5 &= ~ ( V_52 << F_30 ( V_21 ) ) ;
V_5 |= V_55 << F_30 ( V_21 ) ;
F_3 ( V_2 , V_5 , F_29 ( V_21 ) ) ;
break;
case V_56 :
V_5 = F_1 ( V_2 , F_29 ( V_21 ) ) ;
V_5 &= ~ ( V_52 << F_30 ( V_21 ) ) ;
V_5 |= V_57 << F_30 ( V_21 ) ;
F_3 ( V_2 , V_5 , F_29 ( V_21 ) ) ;
break;
case V_58 :
V_5 = F_1 ( V_2 , F_29 ( V_21 ) ) ;
V_5 &= ~ ( V_52 << F_30 ( V_21 ) ) ;
V_5 |= V_59 << F_30 ( V_21 ) ;
F_3 ( V_2 , V_5 , F_29 ( V_21 ) ) ;
break;
case V_60 :
V_5 = F_1 ( V_2 , F_31 ( V_21 ) ) ;
if ( V_49 )
V_5 |= F_32 ( V_21 ) ;
else
V_5 &= ~ F_32 ( V_21 ) ;
F_3 ( V_2 , V_5 , F_31 ( V_21 ) ) ;
break;
case V_61 :
V_5 = F_1 ( V_2 , F_33 ( V_21 ) ) ;
V_5 &= ~ ( V_62 <<
F_34 ( V_21 ) ) ;
switch ( V_49 ) {
case 2 :
V_70 = V_63 ;
break;
case 4 :
V_70 = V_64 ;
break;
case 8 :
V_70 = V_65 ;
break;
case 12 :
V_70 = V_66 ;
break;
default:
F_22 ( V_2 -> V_35 ,
L_3 ,
V_49 ) ;
return - V_36 ;
}
V_5 |= V_70 << F_34 ( V_21 ) ;
F_3 ( V_2 , V_5 , F_33 ( V_21 ) ) ;
break;
default:
F_22 ( V_2 -> V_35 , L_2 ,
V_48 ) ;
return - V_67 ;
}
}
return 0 ;
}
static int F_39 ( struct V_71 * V_72 , unsigned V_11 )
{
struct V_6 * V_9 = F_6 ( V_72 ) ;
return ! ( F_8 ( V_9 , V_73 ) & F_40 ( V_11 ) ) ;
}
static int F_41 ( struct V_71 * V_72 , unsigned V_11 )
{
struct V_6 * V_9 = F_6 ( V_72 ) ;
T_1 V_3 ;
if ( F_8 ( V_9 , V_73 ) & F_40 ( V_11 ) )
V_3 = V_74 ;
else
V_3 = V_75 ;
return ! ! ( F_8 ( V_9 , V_3 ) & F_40 ( V_11 ) ) ;
}
static void F_42 ( struct V_71 * V_72 , unsigned V_11 ,
int V_76 )
{
struct V_6 * V_9 = F_6 ( V_72 ) ;
F_10 ( V_9 , V_74 , V_11 , ! ! V_76 ) ;
}
static int F_43 ( struct V_71 * V_72 ,
unsigned V_11 )
{
struct V_6 * V_9 = F_6 ( V_72 ) ;
F_10 ( V_9 , V_73 , V_11 , 0 ) ;
F_11 ( V_9 , V_11 ) ;
return 0 ;
}
static int F_44 ( struct V_71 * V_72 ,
unsigned V_11 , int V_76 )
{
struct V_6 * V_9 = F_6 ( V_72 ) ;
F_42 ( V_72 , V_11 , V_76 ) ;
F_10 ( V_9 , V_73 , V_11 , 1 ) ;
F_11 ( V_9 , V_11 ) ;
return 0 ;
}
static void F_45 ( struct V_7 * V_77 )
{
struct V_6 * V_9 = F_5 ( V_77 ) ;
F_10 ( V_9 , V_78 , V_77 -> V_79 , 0 ) ;
}
static void F_46 ( struct V_7 * V_77 )
{
struct V_6 * V_9 = F_5 ( V_77 ) ;
F_10 ( V_9 , V_80 , V_77 -> V_79 , 0 ) ;
}
static void F_47 ( struct V_7 * V_77 )
{
struct V_6 * V_9 = F_5 ( V_77 ) ;
F_10 ( V_9 , V_80 , V_77 -> V_79 , 1 ) ;
}
static unsigned int F_48 ( struct V_7 * V_77 )
{
struct V_71 * V_72 = F_7 ( V_77 ) ;
F_43 ( V_72 , V_77 -> V_79 ) ;
F_47 ( V_77 ) ;
return 0 ;
}
static int F_49 ( struct V_7 * V_77 , unsigned int type )
{
struct V_6 * V_9 = F_5 ( V_77 ) ;
switch ( type & V_81 ) {
case V_82 :
F_10 ( V_9 , V_83 , V_77 -> V_79 , 1 ) ;
F_10 ( V_9 , V_84 , V_77 -> V_79 ,
V_85 ) ;
F_10 ( V_9 , V_86 , V_77 -> V_79 ,
V_87 ) ;
break;
case V_88 :
F_10 ( V_9 , V_83 , V_77 -> V_79 , 0 ) ;
F_10 ( V_9 , V_84 , V_77 -> V_79 ,
V_85 ) ;
F_10 ( V_9 , V_86 , V_77 -> V_79 ,
V_87 ) ;
break;
case V_89 :
F_10 ( V_9 , V_84 , V_77 -> V_79 ,
V_85 ) ;
F_10 ( V_9 , V_86 , V_77 -> V_79 ,
V_90 ) ;
break;
case V_91 :
F_10 ( V_9 , V_83 , V_77 -> V_79 , 1 ) ;
F_10 ( V_9 , V_84 , V_77 -> V_79 ,
V_92 ) ;
break;
case V_93 :
F_10 ( V_9 , V_83 , V_77 -> V_79 , 0 ) ;
F_10 ( V_9 , V_84 , V_77 -> V_79 ,
V_92 ) ;
break;
default:
return - V_36 ;
}
if ( type & V_94 )
F_50 ( V_77 , V_95 ) ;
else
F_50 ( V_77 , V_96 ) ;
return 0 ;
}
static void F_51 ( struct V_97 * V_98 )
{
struct V_71 * V_44 = F_52 ( V_98 ) ;
struct V_6 * V_9 = F_6 ( V_44 ) ;
struct V_99 * V_72 = F_53 ( V_98 ) ;
unsigned long V_100 ;
unsigned int V_21 ;
F_54 ( V_72 , V_98 ) ;
V_100 = F_8 ( V_9 , V_78 ) &
F_8 ( V_9 , V_80 ) ;
F_55 (pin, &pending, 16 )
F_56 ( F_57 ( V_44 -> V_101 , V_21 ) ) ;
F_58 ( V_72 , V_98 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_102 * V_103 = V_2 -> V_35 -> V_104 ;
struct V_6 * V_9 ;
unsigned int V_32 ;
int V_105 , V_106 = 0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_107 ; V_32 ++ ) {
char V_108 [ sizeof( L_4 ) ] ;
struct V_102 * V_109 ;
snprintf ( V_108 , sizeof( V_108 ) , L_5 , V_32 ) ;
V_109 = F_60 ( V_103 , V_108 ) ;
if ( ! V_109 ) {
F_22 ( V_2 -> V_35 , L_6 , V_32 ) ;
V_106 = - V_110 ;
goto V_111;
}
if ( ! F_61 ( V_109 , L_7 , NULL ) ) {
F_22 ( V_2 -> V_35 ,
L_8 , V_32 ) ;
V_106 = - V_110 ;
goto V_111;
}
V_105 = F_62 ( V_109 , 0 ) ;
if ( V_105 < 0 ) {
F_22 ( V_2 -> V_35 , L_9 , V_32 , V_105 ) ;
V_106 = V_105 ;
goto V_111;
}
V_9 = & V_2 -> V_112 [ V_32 ] ;
V_9 -> V_2 = V_2 ;
V_9 -> V_4 = V_2 -> V_4 + F_63 ( V_32 ) ;
V_9 -> V_71 . V_113 = V_2 -> V_35 ;
V_9 -> V_71 . V_104 = V_109 ;
V_106 = F_64 ( & V_9 -> V_71 , V_9 ) ;
if ( V_106 < 0 ) {
F_22 ( V_2 -> V_35 , L_10 ,
V_32 , V_106 ) ;
goto V_111;
}
V_106 = F_65 ( & V_9 -> V_71 , & V_9 -> V_99 ,
0 , V_95 , V_114 ) ;
if ( V_106 < 0 ) {
F_22 ( V_2 -> V_35 , L_11 ,
V_32 , V_106 ) ;
F_66 ( & V_9 -> V_71 ) ;
goto V_111;
}
F_67 ( & V_9 -> V_71 , & V_9 -> V_99 ,
V_105 , F_51 ) ;
V_106 = F_68 ( & V_9 -> V_71 ,
F_69 ( V_2 -> V_35 ) , 0 ,
V_9 -> V_45 , V_9 -> V_115 ) ;
if ( V_106 < 0 ) {
F_22 ( V_2 -> V_35 , L_12 ,
V_32 , V_106 ) ;
F_66 ( & V_9 -> V_71 ) ;
goto V_111;
}
}
return 0 ;
V_111:
for (; V_32 > 0 ; V_32 -- ) {
V_9 = & V_2 -> V_112 [ V_32 - 1 ] ;
F_66 ( & V_9 -> V_71 ) ;
}
return V_106 ;
}
static int F_70 ( struct V_116 * V_117 )
{
struct V_1 * V_2 ;
struct V_118 * V_119 ;
int V_106 ;
V_2 = F_71 ( & V_117 -> V_35 , sizeof( * V_2 ) , V_120 ) ;
if ( ! V_2 )
return - V_121 ;
V_2 -> V_35 = & V_117 -> V_35 ;
F_72 ( & V_117 -> V_35 , V_2 ) ;
V_119 = F_73 ( V_117 , V_122 , 0 ) ;
V_2 -> V_4 = F_74 ( & V_117 -> V_35 , V_119 ) ;
if ( F_75 ( V_2 -> V_4 ) )
return F_76 ( V_2 -> V_4 ) ;
V_2 -> V_19 = V_123 ;
V_2 -> V_115 = F_21 ( V_123 ) ;
V_2 -> V_24 = V_124 ;
V_2 -> V_22 = F_21 ( V_124 ) ;
V_2 -> V_17 = V_125 ;
V_2 -> V_15 = F_21 ( V_125 ) ;
V_2 -> V_112 = V_126 ;
V_2 -> V_107 = F_21 ( V_126 ) ;
V_127 . V_19 = V_2 -> V_19 ;
V_127 . V_115 = V_2 -> V_115 ;
V_2 -> V_14 = F_77 ( & V_117 -> V_35 , & V_127 ,
V_2 ) ;
if ( F_75 ( V_2 -> V_14 ) ) {
F_22 ( & V_117 -> V_35 , L_13 ) ;
return F_76 ( V_2 -> V_14 ) ;
}
V_106 = F_59 ( V_2 ) ;
if ( V_106 < 0 ) {
F_78 ( V_2 -> V_14 ) ;
return V_106 ;
}
return 0 ;
}
static int T_2 F_79 ( void )
{
return F_80 ( & V_128 ) ;
}
