static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline unsigned F_3 ( unsigned V_4 )
{
return V_4 ;
}
static inline void F_4 ( struct V_1 * V_5 , unsigned int V_6 ,
unsigned V_7 , bool V_8 )
{
unsigned int V_9 = F_5 ( V_7 , V_6 ) ;
unsigned int V_10 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_7 ( V_5 -> V_12 + V_9 ) ;
if ( V_8 )
V_11 |= F_8 ( V_10 ) ;
else
V_11 &= ~ F_8 ( V_10 ) ;
F_9 ( V_11 , V_5 -> V_12 + V_9 ) ;
}
static inline bool F_10 ( struct V_1 * V_5 , unsigned int V_6 ,
unsigned V_7 )
{
unsigned int V_9 = F_5 ( V_7 , V_6 ) ;
unsigned int V_10 = F_6 ( V_7 ) ;
return ! ! ( F_7 ( V_5 -> V_12 + V_9 ) & F_8 ( V_10 ) ) ;
}
static void F_11 ( unsigned int V_13 , struct V_14 * V_15 )
{
struct V_2 * V_3 = F_12 ( V_15 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_16 = F_13 ( V_15 ) ;
int V_17 , V_18 ;
F_14 ( V_16 , V_15 ) ;
for ( V_17 = 0 ; V_17 < V_5 -> V_19 ; V_17 ++ ) {
unsigned long V_11 = F_7 ( V_5 -> V_12 + ( V_17 * V_20 ) +
V_21 ) ;
F_15 (bit, &val, NGPIOS_PER_BANK) {
unsigned V_4 = V_22 * V_17 + V_18 ;
int V_23 = F_16 ( V_3 -> V_24 , V_4 ) ;
F_9 ( F_8 ( V_18 ) , V_5 -> V_12 + ( V_17 * V_20 ) +
V_25 ) ;
F_17 ( V_23 ) ;
}
}
F_18 ( V_16 , V_15 ) ;
}
static void F_19 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = F_20 ( V_27 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_27 -> V_28 ;
unsigned int V_9 = F_5 ( V_7 ,
V_25 ) ;
unsigned int V_10 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_10 ) ;
F_9 ( V_11 , V_5 -> V_12 + V_9 ) ;
}
static void F_21 ( struct V_26 * V_27 , bool V_29 )
{
struct V_2 * V_3 = F_20 ( V_27 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_27 -> V_28 ;
F_4 ( V_5 , V_30 , V_7 , V_29 ) ;
}
static void F_22 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = F_20 ( V_27 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_31 ;
F_23 ( & V_5 -> V_32 , V_31 ) ;
F_21 ( V_27 , false ) ;
F_24 ( & V_5 -> V_32 , V_31 ) ;
}
static void F_25 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = F_20 ( V_27 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_31 ;
F_23 ( & V_5 -> V_32 , V_31 ) ;
F_21 ( V_27 , true ) ;
F_24 ( & V_5 -> V_32 , V_31 ) ;
}
static int F_26 ( struct V_26 * V_27 , unsigned int type )
{
struct V_2 * V_3 = F_20 ( V_27 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_27 -> V_28 ;
bool V_33 = false ;
bool V_34 = false ;
bool V_35 = false ;
unsigned long V_31 ;
switch ( type & V_36 ) {
case V_37 :
V_35 = true ;
break;
case V_38 :
break;
case V_39 :
V_34 = true ;
break;
case V_40 :
V_33 = true ;
V_35 = true ;
break;
case V_41 :
V_33 = true ;
break;
default:
F_27 ( V_5 -> V_42 , L_1 ,
type ) ;
return - V_43 ;
}
F_23 ( & V_5 -> V_32 , V_31 ) ;
F_4 ( V_5 , V_44 , V_7 ,
V_33 ) ;
F_4 ( V_5 , V_45 , V_7 , V_34 ) ;
F_4 ( V_5 , V_46 , V_7 ,
V_35 ) ;
F_24 ( & V_5 -> V_32 , V_31 ) ;
F_28 ( V_5 -> V_42 ,
L_2 ,
V_7 , V_33 , V_34 , V_35 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , unsigned V_9 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_3 -> V_12 + V_9 ;
if ( ! V_5 -> V_47 )
return 0 ;
return F_30 ( V_7 ) ;
}
static void F_31 ( struct V_2 * V_3 , unsigned V_9 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_3 -> V_12 + V_9 ;
if ( ! V_5 -> V_47 )
return;
F_32 ( V_7 ) ;
}
static int F_33 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_31 ;
F_23 ( & V_5 -> V_32 , V_31 ) ;
F_4 ( V_5 , V_48 , V_7 , false ) ;
F_24 ( & V_5 -> V_32 , V_31 ) ;
F_28 ( V_5 -> V_42 , L_3 , V_7 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , unsigned V_7 ,
int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_31 ;
F_23 ( & V_5 -> V_32 , V_31 ) ;
F_4 ( V_5 , V_48 , V_7 , true ) ;
F_4 ( V_5 , V_49 , V_7 , ! ! ( V_11 ) ) ;
F_24 ( & V_5 -> V_32 , V_31 ) ;
F_28 ( V_5 -> V_42 , L_4 , V_7 , V_11 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 , unsigned V_7 , int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_31 ;
F_23 ( & V_5 -> V_32 , V_31 ) ;
F_4 ( V_5 , V_49 , V_7 , ! ! ( V_11 ) ) ;
F_24 ( & V_5 -> V_32 , V_31 ) ;
F_28 ( V_5 -> V_42 , L_5 , V_7 , V_11 ) ;
}
static int F_36 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_9 = F_5 ( V_7 ,
V_50 ) ;
unsigned int V_10 = F_6 ( V_7 ) ;
return ! ! ( F_7 ( V_5 -> V_12 + V_9 ) & F_8 ( V_10 ) ) ;
}
static int F_37 ( struct V_51 * V_52 )
{
return 1 ;
}
static const char * F_38 ( struct V_51 * V_52 ,
unsigned V_53 )
{
return L_6 ;
}
static int F_39 ( struct V_1 * V_5 , unsigned V_7 ,
bool V_54 , bool V_55 )
{
unsigned long V_31 ;
F_23 ( & V_5 -> V_32 , V_31 ) ;
if ( V_54 ) {
F_4 ( V_5 , V_56 , V_7 , false ) ;
} else {
F_4 ( V_5 , V_57 , V_7 ,
V_55 ) ;
F_4 ( V_5 , V_56 , V_7 , true ) ;
}
F_24 ( & V_5 -> V_32 , V_31 ) ;
F_28 ( V_5 -> V_42 , L_7 , V_7 , V_55 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_5 , unsigned V_7 ,
bool * V_54 , bool * V_55 )
{
unsigned long V_31 ;
F_23 ( & V_5 -> V_32 , V_31 ) ;
* V_54 = ! F_10 ( V_5 , V_56 , V_7 ) ;
* V_55 = F_10 ( V_5 , V_57 , V_7 ) ;
F_24 ( & V_5 -> V_32 , V_31 ) ;
}
static int F_41 ( struct V_1 * V_5 , unsigned V_7 ,
unsigned V_58 )
{
void T_2 * V_12 ;
unsigned int V_17 , V_9 , V_10 ;
T_1 V_11 ;
unsigned long V_31 ;
if ( V_58 < 2 || V_58 > 16 || ( V_58 % 2 ) )
return - V_59 ;
if ( V_5 -> V_60 ) {
V_12 = V_5 -> V_60 ;
V_9 = V_61 ;
} else {
V_12 = V_5 -> V_12 ;
V_9 = F_5 ( V_7 ,
V_62 ) ;
}
V_10 = F_6 ( V_7 ) ;
F_28 ( V_5 -> V_42 , L_8 , V_7 ,
V_58 ) ;
F_23 ( & V_5 -> V_32 , V_31 ) ;
V_58 = ( V_58 / 2 ) - 1 ;
for ( V_17 = 0 ; V_17 < V_63 ; V_17 ++ ) {
V_11 = F_7 ( V_12 + V_9 ) ;
V_11 &= ~ F_8 ( V_10 ) ;
V_11 |= ( ( V_58 >> V_17 ) & 0x1 ) << V_10 ;
F_9 ( V_11 , V_12 + V_9 ) ;
V_9 += 4 ;
}
F_24 ( & V_5 -> V_32 , V_31 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_5 , unsigned V_7 ,
T_3 * V_58 )
{
void T_2 * V_12 ;
unsigned int V_17 , V_9 , V_10 ;
T_1 V_11 ;
unsigned long V_31 ;
if ( V_5 -> V_60 ) {
V_12 = V_5 -> V_60 ;
V_9 = V_61 ;
} else {
V_12 = V_5 -> V_12 ;
V_9 = F_5 ( V_7 ,
V_62 ) ;
}
V_10 = F_6 ( V_7 ) ;
F_23 ( & V_5 -> V_32 , V_31 ) ;
* V_58 = 0 ;
for ( V_17 = 0 ; V_17 < V_63 ; V_17 ++ ) {
V_11 = F_7 ( V_12 + V_9 ) & F_8 ( V_10 ) ;
V_11 >>= V_10 ;
* V_58 += ( V_11 << V_17 ) ;
V_9 += 4 ;
}
* V_58 = ( * V_58 + 1 ) * 2 ;
F_24 ( & V_5 -> V_32 , V_31 ) ;
return 0 ;
}
static int F_43 ( struct V_51 * V_52 , unsigned V_4 ,
unsigned long * V_64 )
{
struct V_1 * V_5 = F_44 ( V_52 ) ;
enum V_65 V_66 = F_45 ( * V_64 ) ;
unsigned V_7 = F_3 ( V_4 ) ;
T_3 V_67 ;
bool V_54 , V_55 ;
int V_68 ;
switch ( V_66 ) {
case V_69 :
F_40 ( V_5 , V_7 , & V_54 , & V_55 ) ;
if ( V_54 )
return 0 ;
else
return - V_43 ;
case V_70 :
F_40 ( V_5 , V_7 , & V_54 , & V_55 ) ;
if ( ! V_54 && V_55 )
return 0 ;
else
return - V_43 ;
case V_71 :
F_40 ( V_5 , V_7 , & V_54 , & V_55 ) ;
if ( ! V_54 && ! V_55 )
return 0 ;
else
return - V_43 ;
case V_72 :
V_68 = F_42 ( V_5 , V_7 , & V_67 ) ;
if ( V_68 )
return V_68 ;
else
* V_64 = F_46 ( V_66 , V_67 ) ;
return 0 ;
default:
return - V_59 ;
}
return - V_59 ;
}
static int F_47 ( struct V_51 * V_52 , unsigned V_4 ,
unsigned long * V_73 , unsigned V_74 )
{
struct V_1 * V_5 = F_44 ( V_52 ) ;
enum V_65 V_66 ;
T_3 V_67 ;
unsigned V_17 , V_7 = F_3 ( V_4 ) ;
int V_68 = - V_59 ;
for ( V_17 = 0 ; V_17 < V_74 ; V_17 ++ ) {
V_66 = F_45 ( V_73 [ V_17 ] ) ;
V_67 = F_48 ( V_73 [ V_17 ] ) ;
switch ( V_66 ) {
case V_69 :
V_68 = F_39 ( V_5 , V_7 , true , false ) ;
if ( V_68 < 0 )
goto V_75;
break;
case V_70 :
V_68 = F_39 ( V_5 , V_7 , false , true ) ;
if ( V_68 < 0 )
goto V_75;
break;
case V_71 :
V_68 = F_39 ( V_5 , V_7 , false , false ) ;
if ( V_68 < 0 )
goto V_75;
break;
case V_72 :
V_68 = F_41 ( V_5 , V_7 , V_67 ) ;
if ( V_68 < 0 )
goto V_75;
break;
default:
F_27 ( V_5 -> V_42 , L_9 ) ;
return - V_59 ;
}
}
V_75:
return V_68 ;
}
static int F_49 ( struct V_1 * V_5 )
{
struct V_76 * V_77 = V_5 -> V_42 -> V_78 ;
struct V_76 * V_79 ;
struct V_80 * V_81 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
int V_17 , V_68 = 0 ;
V_79 = F_50 ( V_77 , L_10 , 0 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = F_51 ( V_79 ) ;
F_52 ( V_79 ) ;
if ( ! V_81 ) {
F_27 ( V_5 -> V_42 , L_11 ) ;
return - V_43 ;
}
for ( V_17 = 0 ; V_17 < F_53 ( V_83 ) ; V_17 ++ ) {
V_68 = F_54 ( V_3 , F_55 ( & V_81 -> V_42 ) ,
V_83 [ V_17 ] . V_9 ,
V_83 [ V_17 ] . V_84 ,
V_83 [ V_17 ] . V_85 ) ;
if ( V_68 ) {
F_27 ( V_5 -> V_42 , L_12 ) ;
goto V_86;
}
}
V_5 -> V_47 = true ;
F_56 ( & V_81 -> V_42 ) ;
return 0 ;
V_86:
F_56 ( & V_81 -> V_42 ) ;
F_57 ( V_3 ) ;
return V_68 ;
}
static int F_58 ( struct V_1 * V_5 )
{
struct V_87 * V_88 = & V_5 -> V_88 ;
struct V_89 * V_90 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
int V_17 ;
V_90 = F_59 ( V_5 -> V_42 , V_3 -> V_91 , sizeof( * V_90 ) , V_92 ) ;
if ( ! V_90 )
return - V_93 ;
for ( V_17 = 0 ; V_17 < V_3 -> V_91 ; V_17 ++ ) {
V_90 [ V_17 ] . V_94 = V_17 ;
V_90 [ V_17 ] . V_95 = F_60 ( V_5 -> V_42 , V_92 ,
L_13 , V_17 ) ;
if ( ! V_90 [ V_17 ] . V_95 )
return - V_93 ;
}
V_88 -> V_95 = F_55 ( V_5 -> V_42 ) ;
V_88 -> V_96 = & V_97 ;
V_88 -> V_90 = V_90 ;
V_88 -> V_98 = V_3 -> V_91 ;
V_88 -> V_99 = & V_100 ;
V_5 -> V_101 = F_61 ( V_88 , V_5 -> V_42 , V_5 ) ;
if ( ! V_5 -> V_101 ) {
F_27 ( V_5 -> V_42 , L_14 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_62 ( struct V_1 * V_5 )
{
if ( V_5 -> V_101 )
F_63 ( V_5 -> V_101 ) ;
}
static int F_64 ( struct V_80 * V_102 )
{
struct V_103 * V_42 = & V_102 -> V_42 ;
struct V_104 * V_105 ;
struct V_1 * V_5 ;
struct V_2 * V_3 ;
T_1 V_106 ;
int V_13 , V_68 ;
const struct V_107 * V_108 ;
const struct V_109 * V_110 ;
V_108 = F_65 ( V_111 , V_42 ) ;
if ( ! V_108 )
return - V_82 ;
V_110 = V_108 -> V_112 ;
V_106 = V_110 -> V_113 ;
V_5 = F_66 ( V_42 , sizeof( * V_5 ) , V_92 ) ;
if ( ! V_5 )
return - V_93 ;
V_5 -> V_42 = V_42 ;
F_67 ( V_102 , V_5 ) ;
V_105 = F_68 ( V_102 , V_114 , 0 ) ;
V_5 -> V_12 = F_69 ( V_42 , V_105 ) ;
if ( F_70 ( V_5 -> V_12 ) ) {
F_27 ( V_42 , L_15 ) ;
return F_71 ( V_5 -> V_12 ) ;
}
V_105 = F_68 ( V_102 , V_114 , 1 ) ;
if ( V_105 ) {
V_5 -> V_60 = F_69 ( V_42 , V_105 ) ;
if ( F_70 ( V_5 -> V_60 ) ) {
F_27 ( V_42 , L_15 ) ;
return F_71 ( V_5 -> V_60 ) ;
}
}
F_72 ( & V_5 -> V_32 ) ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_12 = - 1 ;
V_3 -> V_91 = V_106 ;
V_5 -> V_19 = ( V_106 + V_22 - 1 ) / V_22 ;
V_3 -> V_115 = F_55 ( V_42 ) ;
V_3 -> V_42 = V_42 ;
V_3 -> V_78 = V_42 -> V_78 ;
V_3 -> V_116 = F_29 ;
V_3 -> free = F_31 ;
V_3 -> V_117 = F_33 ;
V_3 -> V_118 = F_34 ;
V_3 -> V_8 = F_35 ;
V_3 -> V_119 = F_36 ;
V_68 = F_73 ( V_3 ) ;
if ( V_68 < 0 ) {
F_27 ( V_42 , L_16 ) ;
return V_68 ;
}
V_68 = F_49 ( V_5 ) ;
if ( V_68 && V_68 != - V_82 ) {
F_27 ( V_42 , L_12 ) ;
goto V_120;
}
V_68 = F_58 ( V_5 ) ;
if ( V_68 ) {
F_27 ( V_42 , L_17 ) ;
goto V_120;
}
V_13 = F_74 ( V_102 , 0 ) ;
if ( V_13 ) {
V_68 = F_75 ( V_3 , & V_121 , 0 ,
V_122 , V_123 ) ;
if ( V_68 ) {
F_27 ( V_42 , L_18 ) ;
goto V_124;
}
F_76 ( V_3 , & V_121 , V_13 ,
F_11 ) ;
}
return 0 ;
V_124:
F_62 ( V_5 ) ;
V_120:
F_77 ( V_3 ) ;
return V_68 ;
}
static int T_4 F_78 ( void )
{
return F_79 ( & V_125 , F_64 ) ;
}
