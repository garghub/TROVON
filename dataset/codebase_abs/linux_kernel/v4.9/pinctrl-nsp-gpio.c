static inline unsigned F_1 ( unsigned V_1 )
{
return V_1 ;
}
static inline void F_2 ( struct V_2 * V_3 , enum V_4 V_5 ,
unsigned int V_6 , unsigned V_7 , bool V_8 )
{
T_1 V_9 ;
void T_2 * V_10 ;
if ( V_5 == V_11 )
V_10 = V_3 -> V_12 ;
else
V_10 = V_3 -> V_13 ;
V_9 = F_3 ( V_10 + V_6 ) ;
if ( V_8 )
V_9 |= F_4 ( V_7 ) ;
else
V_9 &= ~ F_4 ( V_7 ) ;
F_5 ( V_9 , V_10 + V_6 ) ;
}
static inline bool F_6 ( struct V_2 * V_3 , enum V_4 V_5 ,
unsigned int V_6 , unsigned V_7 )
{
if ( V_5 == V_11 )
return ! ! ( F_3 ( V_3 -> V_12 + V_6 ) & F_4 ( V_7 ) ) ;
else
return ! ! ( F_3 ( V_3 -> V_13 + V_6 ) & F_4 ( V_7 ) ) ;
}
static T_3 F_7 ( int V_14 , void * V_15 )
{
struct V_2 * V_3 = (struct V_2 * ) V_15 ;
struct V_16 V_17 = V_3 -> V_17 ;
int V_18 ;
unsigned long V_19 = 0 ;
T_1 V_20 ;
V_20 = F_3 ( V_3 -> V_13 + V_21 ) ;
if ( V_20 & V_22 ) {
unsigned int V_23 , V_24 ;
V_23 = F_3 ( V_3 -> V_13 + V_25 ) &
F_3 ( V_3 -> V_13 + V_26 ) ;
V_24 = F_3 ( V_3 -> V_13 + V_27 ) ^
F_3 ( V_3 -> V_13 + V_28 ) ;
V_24 &= F_3 ( V_3 -> V_13 + V_29 ) ;
V_19 = V_24 | V_23 ;
F_8 (bit, &int_bits, gc.ngpio) {
F_5 ( F_4 ( V_18 ) , V_3 -> V_13 + V_26 ) ;
F_9 (
F_10 ( V_3 -> V_30 , V_18 ) ) ;
}
}
return V_19 ? V_31 : V_32 ;
}
static void F_11 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
unsigned V_7 = V_34 -> V_35 ;
T_1 V_9 = F_4 ( V_7 ) ;
T_1 V_36 ;
V_36 = F_13 ( V_34 -> V_14 ) ;
if ( V_36 & ( V_37 | V_38 ) )
F_2 ( V_3 , V_39 , V_26 , V_7 , V_9 ) ;
}
static void F_14 ( struct V_33 * V_34 , bool V_40 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
unsigned V_7 = V_34 -> V_35 ;
T_1 V_36 ;
V_36 = F_13 ( V_34 -> V_14 ) ;
if ( V_36 & ( V_37 | V_38 ) )
F_2 ( V_3 , V_39 , V_25 , V_7 , V_40 ) ;
else
F_2 ( V_3 , V_39 , V_29 , V_7 , V_40 ) ;
}
static void F_15 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
unsigned long V_41 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
F_14 ( V_34 , false ) ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
}
static void F_18 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
unsigned long V_41 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
F_14 ( V_34 , true ) ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
}
static int F_19 ( struct V_33 * V_34 , unsigned int type )
{
struct V_2 * V_3 = F_12 ( V_34 ) ;
unsigned V_7 = V_34 -> V_35 ;
bool V_43 ;
bool V_44 ;
unsigned long V_41 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
V_44 = F_6 ( V_3 , V_39 , V_45 , V_7 ) ;
V_43 = F_6 ( V_3 , V_39 , V_28 , V_7 ) ;
switch ( type & V_46 ) {
case V_38 :
V_44 = false ;
break;
case V_37 :
V_44 = true ;
break;
case V_47 :
V_43 = false ;
break;
case V_48 :
V_43 = true ;
break;
default:
F_20 ( V_3 -> V_49 , L_1 ,
type ) ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
return - V_50 ;
}
F_2 ( V_3 , V_39 , V_45 , V_7 , V_44 ) ;
F_2 ( V_3 , V_39 , V_28 , V_7 , V_43 ) ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
F_21 ( V_3 -> V_49 , L_2 , V_7 ,
V_43 ? L_3 : L_4 , V_44 ? L_3 : L_4 ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , unsigned V_51 )
{
unsigned V_7 = V_17 -> V_13 + V_51 ;
return F_23 ( V_7 ) ;
}
static void F_24 ( struct V_16 * V_17 , unsigned V_51 )
{
unsigned V_7 = V_17 -> V_13 + V_51 ;
F_25 ( V_7 ) ;
}
static int F_26 ( struct V_16 * V_17 , unsigned V_7 )
{
struct V_2 * V_3 = F_27 ( V_17 ) ;
unsigned long V_41 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
F_2 ( V_3 , V_39 , V_52 , V_7 , false ) ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
F_21 ( V_3 -> V_49 , L_5 , V_7 ) ;
return 0 ;
}
static int F_28 ( struct V_16 * V_17 , unsigned V_7 ,
int V_9 )
{
struct V_2 * V_3 = F_27 ( V_17 ) ;
unsigned long V_41 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
F_2 ( V_3 , V_39 , V_52 , V_7 , true ) ;
F_2 ( V_3 , V_39 , V_53 , V_7 , ! ! ( V_9 ) ) ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
F_21 ( V_3 -> V_49 , L_6 , V_7 , V_9 ) ;
return 0 ;
}
static void F_29 ( struct V_16 * V_17 , unsigned V_7 , int V_9 )
{
struct V_2 * V_3 = F_27 ( V_17 ) ;
unsigned long V_41 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
F_2 ( V_3 , V_39 , V_53 , V_7 , ! ! ( V_9 ) ) ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
F_21 ( V_3 -> V_49 , L_7 , V_7 , V_9 ) ;
}
static int F_30 ( struct V_16 * V_17 , unsigned V_7 )
{
struct V_2 * V_3 = F_27 ( V_17 ) ;
return ! ! ( F_3 ( V_3 -> V_13 + V_27 ) & F_4 ( V_7 ) ) ;
}
static int F_31 ( struct V_16 * V_17 , unsigned V_51 )
{
struct V_2 * V_3 = F_27 ( V_17 ) ;
return F_10 ( V_3 -> V_30 , V_51 ) ;
}
static int F_32 ( struct V_54 * V_55 )
{
return 1 ;
}
static const char * F_33 ( struct V_54 * V_55 ,
unsigned V_56 )
{
return L_8 ;
}
static int F_34 ( struct V_2 * V_3 , unsigned V_7 , T_4 V_57 )
{
if ( V_57 )
F_2 ( V_3 , V_11 , V_58 , V_7 , true ) ;
else
F_2 ( V_3 , V_11 , V_58 , V_7 , false ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , unsigned V_7 ,
bool V_59 , bool V_60 )
{
unsigned long V_41 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
F_2 ( V_3 , V_11 , V_61 , V_7 , V_60 ) ;
F_2 ( V_3 , V_11 , V_62 , V_7 , V_59 ) ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
F_21 ( V_3 -> V_49 , L_9 ,
V_7 , V_59 , V_60 ) ;
return 0 ;
}
static void F_36 ( struct V_2 * V_3 , unsigned V_7 ,
bool * V_59 , bool * V_60 )
{
unsigned long V_41 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
* V_59 = F_6 ( V_3 , V_11 , V_62 , V_7 ) ;
* V_60 = F_6 ( V_3 , V_11 , V_61 , V_7 ) ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
}
static int F_37 ( struct V_2 * V_3 , unsigned V_7 ,
T_4 V_63 )
{
T_1 V_51 , V_64 , V_65 ;
T_1 V_9 ;
unsigned long V_41 ;
if ( V_63 < 2 || V_63 > 16 || ( V_63 % 2 ) )
return - V_66 ;
V_64 = V_7 ;
V_51 = V_67 ;
F_21 ( V_3 -> V_49 , L_10 , V_7 ,
V_63 ) ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
V_63 = ( V_63 / 2 ) - 1 ;
for ( V_65 = V_68 ; V_65 > 0 ; V_65 -- ) {
V_9 = F_3 ( V_3 -> V_12 + V_51 ) ;
V_9 &= ~ F_4 ( V_64 ) ;
V_9 |= ( ( V_63 >> ( V_65 - 1 ) ) & 0x1 ) << V_64 ;
F_5 ( V_9 , V_3 -> V_12 + V_51 ) ;
V_51 += 4 ;
}
F_17 ( & V_3 -> V_42 , V_41 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , unsigned V_7 ,
T_4 * V_63 )
{
unsigned int V_51 , V_64 ;
T_1 V_9 ;
unsigned long V_41 ;
int V_65 ;
V_51 = V_67 ;
V_64 = V_7 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
* V_63 = 0 ;
for ( V_65 = ( V_68 - 1 ) ; V_65 >= 0 ; V_65 -- ) {
V_9 = F_3 ( V_3 -> V_12 + V_51 ) & F_4 ( V_64 ) ;
V_9 >>= V_64 ;
* V_63 += ( V_9 << V_65 ) ;
V_51 += 4 ;
}
* V_63 = ( * V_63 + 1 ) * 2 ;
F_17 ( & V_3 -> V_42 , V_41 ) ;
return 0 ;
}
static int F_39 ( struct V_54 * V_55 ,
unsigned V_56 ,
unsigned long * V_69 )
{
return 0 ;
}
static int F_40 ( struct V_54 * V_55 ,
unsigned V_56 ,
unsigned long * V_70 , unsigned V_71 )
{
return 0 ;
}
static int F_41 ( struct V_54 * V_55 , unsigned V_1 ,
unsigned long * V_69 )
{
struct V_2 * V_3 = F_42 ( V_55 ) ;
enum V_72 V_73 = F_43 ( * V_69 ) ;
unsigned int V_7 ;
T_4 V_74 = 0 ;
bool V_59 , V_60 ;
int V_75 ;
V_7 = F_1 ( V_1 ) ;
switch ( V_73 ) {
case V_76 :
F_36 ( V_3 , V_7 , & V_59 , & V_60 ) ;
if ( ( V_59 == false ) && ( V_60 == false ) )
return 0 ;
else
return - V_50 ;
case V_77 :
F_36 ( V_3 , V_7 , & V_59 , & V_60 ) ;
if ( V_59 )
return 0 ;
else
return - V_50 ;
case V_78 :
F_36 ( V_3 , V_7 , & V_59 , & V_60 ) ;
if ( V_60 )
return 0 ;
else
return - V_50 ;
case V_79 :
V_75 = F_38 ( V_3 , V_7 , & V_74 ) ;
if ( V_75 )
return V_75 ;
* V_69 = F_44 ( V_73 , V_74 ) ;
return 0 ;
default:
return - V_66 ;
}
}
static int F_45 ( struct V_54 * V_55 , unsigned V_1 ,
unsigned long * V_70 , unsigned V_71 )
{
struct V_2 * V_3 = F_42 ( V_55 ) ;
enum V_72 V_73 ;
T_4 V_74 ;
unsigned int V_65 , V_7 ;
int V_75 = - V_66 ;
V_7 = F_1 ( V_1 ) ;
for ( V_65 = 0 ; V_65 < V_71 ; V_65 ++ ) {
V_73 = F_43 ( V_70 [ V_65 ] ) ;
V_74 = F_46 ( V_70 [ V_65 ] ) ;
switch ( V_73 ) {
case V_76 :
V_75 = F_35 ( V_3 , V_7 , false , false ) ;
if ( V_75 < 0 )
goto V_80;
break;
case V_77 :
V_75 = F_35 ( V_3 , V_7 , true , false ) ;
if ( V_75 < 0 )
goto V_80;
break;
case V_78 :
V_75 = F_35 ( V_3 , V_7 , false , true ) ;
if ( V_75 < 0 )
goto V_80;
break;
case V_79 :
V_75 = F_37 ( V_3 , V_7 , V_74 ) ;
if ( V_75 < 0 )
goto V_80;
break;
case V_81 :
V_75 = F_34 ( V_3 , V_7 , V_74 ) ;
if ( V_75 < 0 )
goto V_80;
break;
default:
F_20 ( V_3 -> V_49 , L_11 ) ;
return - V_66 ;
}
}
V_80:
return V_75 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_82 * V_83 = & V_3 -> V_83 ;
struct V_84 * V_85 ;
struct V_16 * V_17 = & V_3 -> V_17 ;
int V_65 ;
V_85 = F_48 ( V_3 -> V_49 , V_17 -> V_86 , sizeof( * V_85 ) , V_87 ) ;
if ( ! V_85 )
return - V_88 ;
for ( V_65 = 0 ; V_65 < V_17 -> V_86 ; V_65 ++ ) {
V_85 [ V_65 ] . V_89 = V_65 ;
V_85 [ V_65 ] . V_90 = F_49 ( V_3 -> V_49 , V_87 ,
L_12 , V_65 ) ;
if ( ! V_85 [ V_65 ] . V_90 )
return - V_88 ;
}
V_83 -> V_90 = F_50 ( V_3 -> V_49 ) ;
V_83 -> V_91 = & V_92 ;
V_83 -> V_85 = V_85 ;
V_83 -> V_93 = V_17 -> V_86 ;
V_83 -> V_94 = & V_95 ;
V_3 -> V_96 = F_51 ( V_3 -> V_49 , V_83 , V_3 ) ;
if ( F_52 ( V_3 -> V_96 ) ) {
F_20 ( V_3 -> V_49 , L_13 ) ;
return F_53 ( V_3 -> V_96 ) ;
}
return 0 ;
}
static int F_54 ( struct V_97 * V_98 )
{
struct V_99 * V_49 = & V_98 -> V_49 ;
struct V_100 * V_101 ;
struct V_2 * V_3 ;
struct V_16 * V_17 ;
T_1 V_9 , V_102 ;
int V_14 , V_75 ;
if ( F_55 ( V_98 -> V_49 . V_103 , L_14 , & V_9 ) ) {
F_20 ( & V_98 -> V_49 , L_15 ) ;
return - V_104 ;
}
V_3 = F_56 ( V_49 , sizeof( * V_3 ) , V_87 ) ;
if ( ! V_3 )
return - V_88 ;
V_3 -> V_49 = V_49 ;
F_57 ( V_98 , V_3 ) ;
V_101 = F_58 ( V_98 , V_105 , 0 ) ;
V_3 -> V_13 = F_59 ( V_49 , V_101 ) ;
if ( F_52 ( V_3 -> V_13 ) ) {
F_20 ( V_49 , L_16 ) ;
return F_53 ( V_3 -> V_13 ) ;
}
V_101 = F_58 ( V_98 , V_105 , 1 ) ;
V_3 -> V_12 = F_59 ( V_49 , V_101 ) ;
if ( F_52 ( V_3 -> V_12 ) ) {
F_20 ( V_49 , L_16 ) ;
return F_53 ( V_3 -> V_12 ) ;
}
F_60 ( & V_3 -> V_42 ) ;
V_17 = & V_3 -> V_17 ;
V_17 -> V_13 = - 1 ;
V_17 -> V_106 = false ;
V_17 -> V_86 = V_9 ;
V_17 -> V_107 = F_50 ( V_49 ) ;
V_17 -> V_108 = V_49 ;
V_17 -> V_103 = V_49 -> V_103 ;
V_17 -> V_109 = F_22 ;
V_17 -> free = F_24 ;
V_17 -> V_110 = F_26 ;
V_17 -> V_111 = F_28 ;
V_17 -> V_8 = F_29 ;
V_17 -> V_112 = F_30 ;
V_17 -> V_113 = F_31 ;
V_14 = F_61 ( V_98 , 0 ) ;
if ( V_14 > 0 ) {
V_3 -> V_30 = F_62 ( V_17 -> V_103 , V_17 -> V_86 ,
& V_114 ,
V_3 ) ;
if ( ! V_3 -> V_30 ) {
F_20 ( & V_98 -> V_49 , L_17 ) ;
return - V_115 ;
}
for ( V_102 = 0 ; V_102 < V_17 -> V_86 ; V_102 ++ ) {
int V_14 = F_63 ( V_3 -> V_30 , V_102 ) ;
F_64 ( V_14 , & V_116 ,
V_117 ) ;
F_65 ( V_14 , V_3 ) ;
}
V_75 = F_66 ( & V_98 -> V_49 , V_14 , F_7 ,
V_118 , L_18 , V_3 ) ;
if ( V_75 ) {
F_20 ( & V_98 -> V_49 , L_19 ,
V_14 , V_75 ) ;
goto V_119;
}
V_9 = F_3 ( V_3 -> V_13 + V_120 ) ;
V_9 = V_9 | V_22 ;
F_5 ( V_9 , ( V_3 -> V_13 + V_120 ) ) ;
}
V_75 = F_67 ( V_17 , V_3 ) ;
if ( V_75 < 0 ) {
F_20 ( V_49 , L_20 ) ;
return V_75 ;
}
V_75 = F_47 ( V_3 ) ;
if ( V_75 ) {
F_20 ( V_49 , L_21 ) ;
goto V_119;
}
return 0 ;
V_119:
F_68 ( V_17 ) ;
return V_75 ;
}
static int T_5 F_69 ( void )
{
return F_70 ( & V_121 ) ;
}
