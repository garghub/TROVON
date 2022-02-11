static inline unsigned F_1 ( unsigned V_1 )
{
return V_1 ;
}
static inline void F_2 ( struct V_2 * V_3 , unsigned int V_4 ,
unsigned V_5 , bool V_6 )
{
unsigned int V_7 = F_3 ( V_5 , V_4 ) ;
unsigned int V_8 = F_4 ( V_5 ) ;
T_1 V_9 ;
V_9 = F_5 ( V_3 -> V_10 + V_7 ) ;
if ( V_6 )
V_9 |= F_6 ( V_8 ) ;
else
V_9 &= ~ F_6 ( V_8 ) ;
F_7 ( V_9 , V_3 -> V_10 + V_7 ) ;
}
static inline bool F_8 ( struct V_2 * V_3 , unsigned int V_4 ,
unsigned V_5 )
{
unsigned int V_7 = F_3 ( V_5 , V_4 ) ;
unsigned int V_8 = F_4 ( V_5 ) ;
return ! ! ( F_5 ( V_3 -> V_10 + V_7 ) & F_6 ( V_8 ) ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_10 ( V_12 ) ;
struct V_2 * V_3 = F_11 ( V_14 ) ;
struct V_15 * V_15 = F_12 ( V_12 ) ;
int V_16 , V_17 ;
F_13 ( V_15 , V_12 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_18 ; V_16 ++ ) {
unsigned long V_9 = F_5 ( V_3 -> V_10 + ( V_16 * V_19 ) +
V_20 ) ;
F_14 (bit, &val, NGPIOS_PER_BANK) {
unsigned V_1 = V_21 * V_16 + V_17 ;
int V_22 = F_15 ( V_14 -> V_23 , V_1 ) ;
F_7 ( F_6 ( V_17 ) , V_3 -> V_10 + ( V_16 * V_19 ) +
V_24 ) ;
F_16 ( V_22 ) ;
}
}
F_17 ( V_15 , V_12 ) ;
}
static void F_18 ( struct V_25 * V_26 )
{
struct V_13 * V_14 = F_19 ( V_26 ) ;
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned V_5 = V_26 -> V_27 ;
unsigned int V_7 = F_3 ( V_5 ,
V_24 ) ;
unsigned int V_8 = F_4 ( V_5 ) ;
T_1 V_9 = F_6 ( V_8 ) ;
F_7 ( V_9 , V_3 -> V_10 + V_7 ) ;
}
static void F_20 ( struct V_25 * V_26 , bool V_28 )
{
struct V_13 * V_14 = F_19 ( V_26 ) ;
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned V_5 = V_26 -> V_27 ;
F_2 ( V_3 , V_29 , V_5 , V_28 ) ;
}
static void F_21 ( struct V_25 * V_26 )
{
struct V_13 * V_14 = F_19 ( V_26 ) ;
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned long V_30 ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
F_20 ( V_26 , false ) ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
}
static void F_24 ( struct V_25 * V_26 )
{
struct V_13 * V_14 = F_19 ( V_26 ) ;
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned long V_30 ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
F_20 ( V_26 , true ) ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
}
static int F_25 ( struct V_25 * V_26 , unsigned int type )
{
struct V_13 * V_14 = F_19 ( V_26 ) ;
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned V_5 = V_26 -> V_27 ;
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
F_26 ( V_3 -> V_41 , L_1 ,
type ) ;
return - V_42 ;
}
F_22 ( & V_3 -> V_31 , V_30 ) ;
F_2 ( V_3 , V_43 , V_5 ,
V_32 ) ;
F_2 ( V_3 , V_44 , V_5 , V_33 ) ;
F_2 ( V_3 , V_45 , V_5 ,
V_34 ) ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
F_27 ( V_3 -> V_41 ,
L_2 ,
V_5 , V_32 , V_33 , V_34 ) ;
return 0 ;
}
static int F_28 ( struct V_13 * V_14 , unsigned V_7 )
{
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned V_5 = V_14 -> V_10 + V_7 ;
if ( ! V_3 -> V_46 )
return 0 ;
return F_29 ( V_5 ) ;
}
static void F_30 ( struct V_13 * V_14 , unsigned V_7 )
{
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned V_5 = V_14 -> V_10 + V_7 ;
if ( ! V_3 -> V_46 )
return;
F_31 ( V_5 ) ;
}
static int F_32 ( struct V_13 * V_14 , unsigned V_5 )
{
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned long V_30 ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
F_2 ( V_3 , V_47 , V_5 , false ) ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
F_27 ( V_3 -> V_41 , L_3 , V_5 ) ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 , unsigned V_5 ,
int V_9 )
{
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned long V_30 ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
F_2 ( V_3 , V_47 , V_5 , true ) ;
F_2 ( V_3 , V_48 , V_5 , ! ! ( V_9 ) ) ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
F_27 ( V_3 -> V_41 , L_4 , V_5 , V_9 ) ;
return 0 ;
}
static void F_34 ( struct V_13 * V_14 , unsigned V_5 , int V_9 )
{
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned long V_30 ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
F_2 ( V_3 , V_48 , V_5 , ! ! ( V_9 ) ) ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
F_27 ( V_3 -> V_41 , L_5 , V_5 , V_9 ) ;
}
static int F_35 ( struct V_13 * V_14 , unsigned V_5 )
{
struct V_2 * V_3 = F_11 ( V_14 ) ;
unsigned int V_7 = F_3 ( V_5 ,
V_49 ) ;
unsigned int V_8 = F_4 ( V_5 ) ;
return ! ! ( F_5 ( V_3 -> V_10 + V_7 ) & F_6 ( V_8 ) ) ;
}
static int F_36 ( struct V_50 * V_51 )
{
return 1 ;
}
static const char * F_37 ( struct V_50 * V_51 ,
unsigned V_52 )
{
return L_6 ;
}
static int F_38 ( struct V_2 * V_3 , unsigned V_5 ,
bool V_53 , bool V_54 )
{
unsigned long V_30 ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
if ( V_53 ) {
F_2 ( V_3 , V_55 , V_5 , false ) ;
} else {
F_2 ( V_3 , V_56 , V_5 ,
V_54 ) ;
F_2 ( V_3 , V_55 , V_5 , true ) ;
}
F_23 ( & V_3 -> V_31 , V_30 ) ;
F_27 ( V_3 -> V_41 , L_7 , V_5 , V_54 ) ;
return 0 ;
}
static void F_39 ( struct V_2 * V_3 , unsigned V_5 ,
bool * V_53 , bool * V_54 )
{
unsigned long V_30 ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
* V_53 = ! F_8 ( V_3 , V_55 , V_5 ) ;
* V_54 = F_8 ( V_3 , V_56 , V_5 ) ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
}
static int F_40 ( struct V_2 * V_3 , unsigned V_5 ,
unsigned V_57 )
{
void T_2 * V_10 ;
unsigned int V_16 , V_7 , V_8 ;
T_1 V_9 ;
unsigned long V_30 ;
if ( V_57 < 2 || V_57 > 16 || ( V_57 % 2 ) )
return - V_58 ;
if ( V_3 -> V_59 ) {
V_10 = V_3 -> V_59 ;
V_7 = V_60 ;
} else {
V_10 = V_3 -> V_10 ;
V_7 = F_3 ( V_5 ,
V_61 ) ;
}
V_8 = F_4 ( V_5 ) ;
F_27 ( V_3 -> V_41 , L_8 , V_5 ,
V_57 ) ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
V_57 = ( V_57 / 2 ) - 1 ;
for ( V_16 = 0 ; V_16 < V_62 ; V_16 ++ ) {
V_9 = F_5 ( V_10 + V_7 ) ;
V_9 &= ~ F_6 ( V_8 ) ;
V_9 |= ( ( V_57 >> V_16 ) & 0x1 ) << V_8 ;
F_7 ( V_9 , V_10 + V_7 ) ;
V_7 += 4 ;
}
F_23 ( & V_3 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , unsigned V_5 ,
T_3 * V_57 )
{
void T_2 * V_10 ;
unsigned int V_16 , V_7 , V_8 ;
T_1 V_9 ;
unsigned long V_30 ;
if ( V_3 -> V_59 ) {
V_10 = V_3 -> V_59 ;
V_7 = V_60 ;
} else {
V_10 = V_3 -> V_10 ;
V_7 = F_3 ( V_5 ,
V_61 ) ;
}
V_8 = F_4 ( V_5 ) ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
* V_57 = 0 ;
for ( V_16 = 0 ; V_16 < V_62 ; V_16 ++ ) {
V_9 = F_5 ( V_10 + V_7 ) & F_6 ( V_8 ) ;
V_9 >>= V_8 ;
* V_57 += ( V_9 << V_16 ) ;
V_7 += 4 ;
}
* V_57 = ( * V_57 + 1 ) * 2 ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_42 ( struct V_50 * V_51 , unsigned V_1 ,
unsigned long * V_63 )
{
struct V_2 * V_3 = F_43 ( V_51 ) ;
enum V_64 V_65 = F_44 ( * V_63 ) ;
unsigned V_5 = F_1 ( V_1 ) ;
T_3 V_66 ;
bool V_53 , V_54 ;
int V_67 ;
switch ( V_65 ) {
case V_68 :
F_39 ( V_3 , V_5 , & V_53 , & V_54 ) ;
if ( V_53 )
return 0 ;
else
return - V_42 ;
case V_69 :
F_39 ( V_3 , V_5 , & V_53 , & V_54 ) ;
if ( ! V_53 && V_54 )
return 0 ;
else
return - V_42 ;
case V_70 :
F_39 ( V_3 , V_5 , & V_53 , & V_54 ) ;
if ( ! V_53 && ! V_54 )
return 0 ;
else
return - V_42 ;
case V_71 :
V_67 = F_41 ( V_3 , V_5 , & V_66 ) ;
if ( V_67 )
return V_67 ;
* V_63 = F_45 ( V_65 , V_66 ) ;
return 0 ;
default:
return - V_58 ;
}
return - V_58 ;
}
static int F_46 ( struct V_50 * V_51 , unsigned V_1 ,
unsigned long * V_72 , unsigned V_73 )
{
struct V_2 * V_3 = F_43 ( V_51 ) ;
enum V_64 V_65 ;
T_3 V_66 ;
unsigned V_16 , V_5 = F_1 ( V_1 ) ;
int V_67 = - V_58 ;
for ( V_16 = 0 ; V_16 < V_73 ; V_16 ++ ) {
V_65 = F_44 ( V_72 [ V_16 ] ) ;
V_66 = F_47 ( V_72 [ V_16 ] ) ;
switch ( V_65 ) {
case V_68 :
V_67 = F_38 ( V_3 , V_5 , true , false ) ;
if ( V_67 < 0 )
goto V_74;
break;
case V_69 :
V_67 = F_38 ( V_3 , V_5 , false , true ) ;
if ( V_67 < 0 )
goto V_74;
break;
case V_70 :
V_67 = F_38 ( V_3 , V_5 , false , false ) ;
if ( V_67 < 0 )
goto V_74;
break;
case V_71 :
V_67 = F_40 ( V_3 , V_5 , V_66 ) ;
if ( V_67 < 0 )
goto V_74;
break;
default:
F_26 ( V_3 -> V_41 , L_9 ) ;
return - V_58 ;
}
}
V_74:
return V_67 ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_75 * V_76 = & V_3 -> V_76 ;
struct V_77 * V_78 ;
struct V_13 * V_14 = & V_3 -> V_14 ;
int V_16 ;
V_78 = F_49 ( V_3 -> V_41 , V_14 -> V_79 , sizeof( * V_78 ) , V_80 ) ;
if ( ! V_78 )
return - V_81 ;
for ( V_16 = 0 ; V_16 < V_14 -> V_79 ; V_16 ++ ) {
V_78 [ V_16 ] . V_82 = V_16 ;
V_78 [ V_16 ] . V_83 = F_50 ( V_3 -> V_41 , V_80 ,
L_10 , V_16 ) ;
if ( ! V_78 [ V_16 ] . V_83 )
return - V_81 ;
}
V_76 -> V_83 = F_51 ( V_3 -> V_41 ) ;
V_76 -> V_84 = & V_85 ;
V_76 -> V_78 = V_78 ;
V_76 -> V_86 = V_14 -> V_79 ;
V_76 -> V_87 = & V_88 ;
V_3 -> V_89 = F_52 ( V_76 , V_3 -> V_41 , V_3 ) ;
if ( F_53 ( V_3 -> V_89 ) ) {
F_26 ( V_3 -> V_41 , L_11 ) ;
return F_54 ( V_3 -> V_89 ) ;
}
return 0 ;
}
static void F_55 ( struct V_2 * V_3 )
{
F_56 ( V_3 -> V_89 ) ;
}
static int F_57 ( struct V_90 * V_91 )
{
struct V_92 * V_41 = & V_91 -> V_41 ;
struct V_93 * V_94 ;
struct V_2 * V_3 ;
struct V_13 * V_14 ;
T_1 V_95 ;
int V_96 , V_67 ;
V_3 = F_58 ( V_41 , sizeof( * V_3 ) , V_80 ) ;
if ( ! V_3 )
return - V_81 ;
V_3 -> V_41 = V_41 ;
F_59 ( V_91 , V_3 ) ;
V_94 = F_60 ( V_91 , V_97 , 0 ) ;
V_3 -> V_10 = F_61 ( V_41 , V_94 ) ;
if ( F_53 ( V_3 -> V_10 ) ) {
F_26 ( V_41 , L_12 ) ;
return F_54 ( V_3 -> V_10 ) ;
}
V_94 = F_60 ( V_91 , V_97 , 1 ) ;
if ( V_94 ) {
V_3 -> V_59 = F_61 ( V_41 , V_94 ) ;
if ( F_53 ( V_3 -> V_59 ) ) {
F_26 ( V_41 , L_12 ) ;
return F_54 ( V_3 -> V_59 ) ;
}
}
if ( F_62 ( V_41 -> V_98 , L_13 , & V_95 ) ) {
F_26 ( & V_91 -> V_41 , L_14 ) ;
return - V_99 ;
}
F_63 ( & V_3 -> V_31 ) ;
V_14 = & V_3 -> V_14 ;
V_14 -> V_10 = - 1 ;
V_14 -> V_79 = V_95 ;
V_3 -> V_18 = ( V_95 + V_21 - 1 ) / V_21 ;
V_14 -> V_100 = F_51 ( V_41 ) ;
V_14 -> V_101 = V_41 ;
V_14 -> V_98 = V_41 -> V_98 ;
V_14 -> V_102 = F_28 ;
V_14 -> free = F_30 ;
V_14 -> V_103 = F_32 ;
V_14 -> V_104 = F_33 ;
V_14 -> V_6 = F_34 ;
V_14 -> V_105 = F_35 ;
V_3 -> V_46 = F_64 ( V_41 -> V_98 ,
L_15 ) ;
V_67 = F_65 ( V_14 , V_3 ) ;
if ( V_67 < 0 ) {
F_26 ( V_41 , L_16 ) ;
return V_67 ;
}
V_67 = F_48 ( V_3 ) ;
if ( V_67 ) {
F_26 ( V_41 , L_17 ) ;
goto V_106;
}
V_96 = F_66 ( V_91 , 0 ) ;
if ( V_96 ) {
V_67 = F_67 ( V_14 , & V_107 , 0 ,
V_108 , V_109 ) ;
if ( V_67 ) {
F_26 ( V_41 , L_18 ) ;
goto V_110;
}
F_68 ( V_14 , & V_107 , V_96 ,
F_9 ) ;
}
return 0 ;
V_110:
F_55 ( V_3 ) ;
V_106:
F_69 ( V_14 ) ;
return V_67 ;
}
static int T_4 F_70 ( void )
{
return F_71 ( & V_111 , F_57 ) ;
}
