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
static void F_11 ( struct V_13 * V_14 )
{
struct V_2 * V_3 = F_12 ( V_14 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_15 * V_15 = F_13 ( V_14 ) ;
int V_16 , V_17 ;
F_14 ( V_15 , V_14 ) ;
for ( V_16 = 0 ; V_16 < V_5 -> V_18 ; V_16 ++ ) {
unsigned long V_11 = F_7 ( V_5 -> V_12 + ( V_16 * V_19 ) +
V_20 ) ;
F_15 (bit, &val, NGPIOS_PER_BANK) {
unsigned V_4 = V_21 * V_16 + V_17 ;
int V_22 = F_16 ( V_3 -> V_23 , V_4 ) ;
F_9 ( F_8 ( V_17 ) , V_5 -> V_12 + ( V_16 * V_19 ) +
V_24 ) ;
F_17 ( V_22 ) ;
}
}
F_18 ( V_15 , V_14 ) ;
}
static void F_19 ( struct V_25 * V_26 )
{
struct V_2 * V_3 = F_20 ( V_26 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_26 -> V_27 ;
unsigned int V_9 = F_5 ( V_7 ,
V_24 ) ;
unsigned int V_10 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_10 ) ;
F_9 ( V_11 , V_5 -> V_12 + V_9 ) ;
}
static void F_21 ( struct V_25 * V_26 , bool V_28 )
{
struct V_2 * V_3 = F_20 ( V_26 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_26 -> V_27 ;
F_4 ( V_5 , V_29 , V_7 , V_28 ) ;
}
static void F_22 ( struct V_25 * V_26 )
{
struct V_2 * V_3 = F_20 ( V_26 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_30 ;
F_23 ( & V_5 -> V_31 , V_30 ) ;
F_21 ( V_26 , false ) ;
F_24 ( & V_5 -> V_31 , V_30 ) ;
}
static void F_25 ( struct V_25 * V_26 )
{
struct V_2 * V_3 = F_20 ( V_26 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_30 ;
F_23 ( & V_5 -> V_31 , V_30 ) ;
F_21 ( V_26 , true ) ;
F_24 ( & V_5 -> V_31 , V_30 ) ;
}
static int F_26 ( struct V_25 * V_26 , unsigned int type )
{
struct V_2 * V_3 = F_20 ( V_26 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_26 -> V_27 ;
bool V_32 = false ;
bool V_33 = false ;
bool V_34 = false ;
unsigned long V_30 ;
switch ( type & V_35 ) {
case V_36 :
V_34 = true ;
break;
case V_37 :
break;
case V_38 :
V_33 = true ;
break;
case V_39 :
V_32 = true ;
V_34 = true ;
break;
case V_40 :
V_32 = true ;
break;
default:
F_27 ( V_5 -> V_41 , L_1 ,
type ) ;
return - V_42 ;
}
F_23 ( & V_5 -> V_31 , V_30 ) ;
F_4 ( V_5 , V_43 , V_7 ,
V_32 ) ;
F_4 ( V_5 , V_44 , V_7 , V_33 ) ;
F_4 ( V_5 , V_45 , V_7 ,
V_34 ) ;
F_24 ( & V_5 -> V_31 , V_30 ) ;
F_28 ( V_5 -> V_41 ,
L_2 ,
V_7 , V_32 , V_33 , V_34 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , unsigned V_9 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_3 -> V_12 + V_9 ;
if ( ! V_5 -> V_46 )
return 0 ;
return F_30 ( V_7 ) ;
}
static void F_31 ( struct V_2 * V_3 , unsigned V_9 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_7 = V_3 -> V_12 + V_9 ;
if ( ! V_5 -> V_46 )
return;
F_32 ( V_7 ) ;
}
static int F_33 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_30 ;
F_23 ( & V_5 -> V_31 , V_30 ) ;
F_4 ( V_5 , V_47 , V_7 , false ) ;
F_24 ( & V_5 -> V_31 , V_30 ) ;
F_28 ( V_5 -> V_41 , L_3 , V_7 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , unsigned V_7 ,
int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_30 ;
F_23 ( & V_5 -> V_31 , V_30 ) ;
F_4 ( V_5 , V_47 , V_7 , true ) ;
F_4 ( V_5 , V_48 , V_7 , ! ! ( V_11 ) ) ;
F_24 ( & V_5 -> V_31 , V_30 ) ;
F_28 ( V_5 -> V_41 , L_4 , V_7 , V_11 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 , unsigned V_7 , int V_11 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_30 ;
F_23 ( & V_5 -> V_31 , V_30 ) ;
F_4 ( V_5 , V_48 , V_7 , ! ! ( V_11 ) ) ;
F_24 ( & V_5 -> V_31 , V_30 ) ;
F_28 ( V_5 -> V_41 , L_5 , V_7 , V_11 ) ;
}
static int F_36 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_9 = F_5 ( V_7 ,
V_49 ) ;
unsigned int V_10 = F_6 ( V_7 ) ;
return ! ! ( F_7 ( V_5 -> V_12 + V_9 ) & F_8 ( V_10 ) ) ;
}
static int F_37 ( struct V_50 * V_51 )
{
return 1 ;
}
static const char * F_38 ( struct V_50 * V_51 ,
unsigned V_52 )
{
return L_6 ;
}
static int F_39 ( struct V_1 * V_5 , unsigned V_7 ,
bool V_53 , bool V_54 )
{
unsigned long V_30 ;
F_23 ( & V_5 -> V_31 , V_30 ) ;
if ( V_53 ) {
F_4 ( V_5 , V_55 , V_7 , false ) ;
} else {
F_4 ( V_5 , V_56 , V_7 ,
V_54 ) ;
F_4 ( V_5 , V_55 , V_7 , true ) ;
}
F_24 ( & V_5 -> V_31 , V_30 ) ;
F_28 ( V_5 -> V_41 , L_7 , V_7 , V_54 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_5 , unsigned V_7 ,
bool * V_53 , bool * V_54 )
{
unsigned long V_30 ;
F_23 ( & V_5 -> V_31 , V_30 ) ;
* V_53 = ! F_10 ( V_5 , V_55 , V_7 ) ;
* V_54 = F_10 ( V_5 , V_56 , V_7 ) ;
F_24 ( & V_5 -> V_31 , V_30 ) ;
}
static int F_41 ( struct V_1 * V_5 , unsigned V_7 ,
unsigned V_57 )
{
void T_2 * V_12 ;
unsigned int V_16 , V_9 , V_10 ;
T_1 V_11 ;
unsigned long V_30 ;
if ( V_57 < 2 || V_57 > 16 || ( V_57 % 2 ) )
return - V_58 ;
if ( V_5 -> V_59 ) {
V_12 = V_5 -> V_59 ;
V_9 = V_60 ;
} else {
V_12 = V_5 -> V_12 ;
V_9 = F_5 ( V_7 ,
V_61 ) ;
}
V_10 = F_6 ( V_7 ) ;
F_28 ( V_5 -> V_41 , L_8 , V_7 ,
V_57 ) ;
F_23 ( & V_5 -> V_31 , V_30 ) ;
V_57 = ( V_57 / 2 ) - 1 ;
for ( V_16 = 0 ; V_16 < V_62 ; V_16 ++ ) {
V_11 = F_7 ( V_12 + V_9 ) ;
V_11 &= ~ F_8 ( V_10 ) ;
V_11 |= ( ( V_57 >> V_16 ) & 0x1 ) << V_10 ;
F_9 ( V_11 , V_12 + V_9 ) ;
V_9 += 4 ;
}
F_24 ( & V_5 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_5 , unsigned V_7 ,
T_3 * V_57 )
{
void T_2 * V_12 ;
unsigned int V_16 , V_9 , V_10 ;
T_1 V_11 ;
unsigned long V_30 ;
if ( V_5 -> V_59 ) {
V_12 = V_5 -> V_59 ;
V_9 = V_60 ;
} else {
V_12 = V_5 -> V_12 ;
V_9 = F_5 ( V_7 ,
V_61 ) ;
}
V_10 = F_6 ( V_7 ) ;
F_23 ( & V_5 -> V_31 , V_30 ) ;
* V_57 = 0 ;
for ( V_16 = 0 ; V_16 < V_62 ; V_16 ++ ) {
V_11 = F_7 ( V_12 + V_9 ) & F_8 ( V_10 ) ;
V_11 >>= V_10 ;
* V_57 += ( V_11 << V_16 ) ;
V_9 += 4 ;
}
* V_57 = ( * V_57 + 1 ) * 2 ;
F_24 ( & V_5 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_43 ( struct V_50 * V_51 , unsigned V_4 ,
unsigned long * V_63 )
{
struct V_1 * V_5 = F_44 ( V_51 ) ;
enum V_64 V_65 = F_45 ( * V_63 ) ;
unsigned V_7 = F_3 ( V_4 ) ;
T_3 V_66 ;
bool V_53 , V_54 ;
int V_67 ;
switch ( V_65 ) {
case V_68 :
F_40 ( V_5 , V_7 , & V_53 , & V_54 ) ;
if ( V_53 )
return 0 ;
else
return - V_42 ;
case V_69 :
F_40 ( V_5 , V_7 , & V_53 , & V_54 ) ;
if ( ! V_53 && V_54 )
return 0 ;
else
return - V_42 ;
case V_70 :
F_40 ( V_5 , V_7 , & V_53 , & V_54 ) ;
if ( ! V_53 && ! V_54 )
return 0 ;
else
return - V_42 ;
case V_71 :
V_67 = F_42 ( V_5 , V_7 , & V_66 ) ;
if ( V_67 )
return V_67 ;
* V_63 = F_46 ( V_65 , V_66 ) ;
return 0 ;
default:
return - V_58 ;
}
return - V_58 ;
}
static int F_47 ( struct V_50 * V_51 , unsigned V_4 ,
unsigned long * V_72 , unsigned V_73 )
{
struct V_1 * V_5 = F_44 ( V_51 ) ;
enum V_64 V_65 ;
T_3 V_66 ;
unsigned V_16 , V_7 = F_3 ( V_4 ) ;
int V_67 = - V_58 ;
for ( V_16 = 0 ; V_16 < V_73 ; V_16 ++ ) {
V_65 = F_45 ( V_72 [ V_16 ] ) ;
V_66 = F_48 ( V_72 [ V_16 ] ) ;
switch ( V_65 ) {
case V_68 :
V_67 = F_39 ( V_5 , V_7 , true , false ) ;
if ( V_67 < 0 )
goto V_74;
break;
case V_69 :
V_67 = F_39 ( V_5 , V_7 , false , true ) ;
if ( V_67 < 0 )
goto V_74;
break;
case V_70 :
V_67 = F_39 ( V_5 , V_7 , false , false ) ;
if ( V_67 < 0 )
goto V_74;
break;
case V_71 :
V_67 = F_41 ( V_5 , V_7 , V_66 ) ;
if ( V_67 < 0 )
goto V_74;
break;
default:
F_27 ( V_5 -> V_41 , L_9 ) ;
return - V_58 ;
}
}
V_74:
return V_67 ;
}
static int F_49 ( struct V_1 * V_5 )
{
struct V_75 * V_76 = & V_5 -> V_76 ;
struct V_77 * V_78 ;
struct V_2 * V_3 = & V_5 -> V_3 ;
int V_16 ;
V_78 = F_50 ( V_5 -> V_41 , V_3 -> V_79 , sizeof( * V_78 ) , V_80 ) ;
if ( ! V_78 )
return - V_81 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_79 ; V_16 ++ ) {
V_78 [ V_16 ] . V_82 = V_16 ;
V_78 [ V_16 ] . V_83 = F_51 ( V_5 -> V_41 , V_80 ,
L_10 , V_16 ) ;
if ( ! V_78 [ V_16 ] . V_83 )
return - V_81 ;
}
V_76 -> V_83 = F_52 ( V_5 -> V_41 ) ;
V_76 -> V_84 = & V_85 ;
V_76 -> V_78 = V_78 ;
V_76 -> V_86 = V_3 -> V_79 ;
V_76 -> V_87 = & V_88 ;
V_5 -> V_89 = F_53 ( V_76 , V_5 -> V_41 , V_5 ) ;
if ( F_54 ( V_5 -> V_89 ) ) {
F_27 ( V_5 -> V_41 , L_11 ) ;
return F_55 ( V_5 -> V_89 ) ;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_5 )
{
F_57 ( V_5 -> V_89 ) ;
}
static int F_58 ( struct V_90 * V_91 )
{
struct V_92 * V_41 = & V_91 -> V_41 ;
struct V_93 * V_94 ;
struct V_1 * V_5 ;
struct V_2 * V_3 ;
T_1 V_95 ;
int V_96 , V_67 ;
V_5 = F_59 ( V_41 , sizeof( * V_5 ) , V_80 ) ;
if ( ! V_5 )
return - V_81 ;
V_5 -> V_41 = V_41 ;
F_60 ( V_91 , V_5 ) ;
V_94 = F_61 ( V_91 , V_97 , 0 ) ;
V_5 -> V_12 = F_62 ( V_41 , V_94 ) ;
if ( F_54 ( V_5 -> V_12 ) ) {
F_27 ( V_41 , L_12 ) ;
return F_55 ( V_5 -> V_12 ) ;
}
V_94 = F_61 ( V_91 , V_97 , 1 ) ;
if ( V_94 ) {
V_5 -> V_59 = F_62 ( V_41 , V_94 ) ;
if ( F_54 ( V_5 -> V_59 ) ) {
F_27 ( V_41 , L_12 ) ;
return F_55 ( V_5 -> V_59 ) ;
}
}
if ( F_63 ( V_41 -> V_98 , L_13 , & V_95 ) ) {
F_27 ( & V_91 -> V_41 , L_14 ) ;
return - V_99 ;
}
F_64 ( & V_5 -> V_31 ) ;
V_3 = & V_5 -> V_3 ;
V_3 -> V_12 = - 1 ;
V_3 -> V_79 = V_95 ;
V_5 -> V_18 = ( V_95 + V_21 - 1 ) / V_21 ;
V_3 -> V_100 = F_52 ( V_41 ) ;
V_3 -> V_101 = V_41 ;
V_3 -> V_98 = V_41 -> V_98 ;
V_3 -> V_102 = F_29 ;
V_3 -> free = F_31 ;
V_3 -> V_103 = F_33 ;
V_3 -> V_104 = F_34 ;
V_3 -> V_8 = F_35 ;
V_3 -> V_105 = F_36 ;
V_5 -> V_46 = F_65 ( V_41 -> V_98 ,
L_15 ) ;
V_67 = F_66 ( V_3 ) ;
if ( V_67 < 0 ) {
F_27 ( V_41 , L_16 ) ;
return V_67 ;
}
V_67 = F_49 ( V_5 ) ;
if ( V_67 ) {
F_27 ( V_41 , L_17 ) ;
goto V_106;
}
V_96 = F_67 ( V_91 , 0 ) ;
if ( V_96 ) {
V_67 = F_68 ( V_3 , & V_107 , 0 ,
V_108 , V_109 ) ;
if ( V_67 ) {
F_27 ( V_41 , L_18 ) ;
goto V_110;
}
F_69 ( V_3 , & V_107 , V_96 ,
F_11 ) ;
}
return 0 ;
V_110:
F_56 ( V_5 ) ;
V_106:
F_70 ( V_3 ) ;
return V_67 ;
}
static int T_4 F_71 ( void )
{
return F_72 ( & V_111 , F_58 ) ;
}
