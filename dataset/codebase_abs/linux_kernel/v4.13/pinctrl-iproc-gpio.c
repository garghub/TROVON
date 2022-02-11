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
static bool F_36 ( struct V_2 * V_3 ,
enum V_50 V_51 )
{
unsigned int V_16 ;
if ( ! V_3 -> V_52 )
return false ;
for ( V_16 = 0 ; V_16 < V_3 -> V_52 ; V_16 ++ )
if ( V_3 -> V_53 [ V_16 ] == V_51 )
return true ;
return false ;
}
static int F_37 ( struct V_2 * V_3 ,
unsigned long V_54 )
{
unsigned int V_55 = F_38 ( V_56 ) ;
unsigned int V_17 , V_57 = 0 ;
F_14 (bit, &disable_mask, map_size)
V_57 ++ ;
if ( ! V_57 )
return 0 ;
V_3 -> V_53 = F_39 ( V_3 -> V_41 , V_57 ,
sizeof( * V_3 -> V_53 ) ,
V_58 ) ;
if ( ! V_3 -> V_53 )
return - V_59 ;
V_3 -> V_52 = V_57 ;
V_57 = 0 ;
F_14 (bit, &disable_mask, map_size)
V_3 -> V_53 [ V_57 ++ ] = V_56 [ V_17 ] ;
return 0 ;
}
static int F_40 ( struct V_60 * V_61 )
{
return 1 ;
}
static const char * F_41 ( struct V_60 * V_61 ,
unsigned V_62 )
{
return L_6 ;
}
static int F_42 ( struct V_2 * V_3 , unsigned V_5 ,
bool V_63 , bool V_64 )
{
unsigned long V_30 ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
if ( V_63 ) {
F_2 ( V_3 , V_65 , V_5 , false ) ;
} else {
F_2 ( V_3 , V_66 , V_5 ,
V_64 ) ;
F_2 ( V_3 , V_65 , V_5 , true ) ;
}
F_23 ( & V_3 -> V_31 , V_30 ) ;
F_27 ( V_3 -> V_41 , L_7 , V_5 , V_64 ) ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 , unsigned V_5 ,
bool * V_63 , bool * V_64 )
{
unsigned long V_30 ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
* V_63 = ! F_8 ( V_3 , V_65 , V_5 ) ;
* V_64 = F_8 ( V_3 , V_66 , V_5 ) ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
}
static int F_44 ( struct V_2 * V_3 , unsigned V_5 ,
unsigned V_67 )
{
void T_2 * V_10 ;
unsigned int V_16 , V_7 , V_8 ;
T_1 V_9 ;
unsigned long V_30 ;
if ( V_67 < 2 || V_67 > 16 || ( V_67 % 2 ) )
return - V_68 ;
if ( V_3 -> V_69 ) {
V_10 = V_3 -> V_69 ;
V_7 = V_70 ;
} else {
V_10 = V_3 -> V_10 ;
V_7 = F_3 ( V_5 ,
V_71 ) ;
}
V_8 = F_4 ( V_5 ) ;
F_27 ( V_3 -> V_41 , L_8 , V_5 ,
V_67 ) ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
V_67 = ( V_67 / 2 ) - 1 ;
for ( V_16 = 0 ; V_16 < V_72 ; V_16 ++ ) {
V_9 = F_5 ( V_10 + V_7 ) ;
V_9 &= ~ F_6 ( V_8 ) ;
V_9 |= ( ( V_67 >> V_16 ) & 0x1 ) << V_8 ;
F_7 ( V_9 , V_10 + V_7 ) ;
V_7 += 4 ;
}
F_23 ( & V_3 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , unsigned V_5 ,
T_3 * V_67 )
{
void T_2 * V_10 ;
unsigned int V_16 , V_7 , V_8 ;
T_1 V_9 ;
unsigned long V_30 ;
if ( V_3 -> V_69 ) {
V_10 = V_3 -> V_69 ;
V_7 = V_70 ;
} else {
V_10 = V_3 -> V_10 ;
V_7 = F_3 ( V_5 ,
V_71 ) ;
}
V_8 = F_4 ( V_5 ) ;
F_22 ( & V_3 -> V_31 , V_30 ) ;
* V_67 = 0 ;
for ( V_16 = 0 ; V_16 < V_72 ; V_16 ++ ) {
V_9 = F_5 ( V_10 + V_7 ) & F_6 ( V_8 ) ;
V_9 >>= V_8 ;
* V_67 += ( V_9 << V_16 ) ;
V_7 += 4 ;
}
* V_67 = ( * V_67 + 1 ) * 2 ;
F_23 ( & V_3 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_46 ( struct V_60 * V_61 , unsigned V_1 ,
unsigned long * V_73 )
{
struct V_2 * V_3 = F_47 ( V_61 ) ;
enum V_50 V_51 = F_48 ( * V_73 ) ;
unsigned V_5 = F_1 ( V_1 ) ;
T_3 V_74 ;
bool V_63 , V_64 ;
int V_75 ;
if ( F_36 ( V_3 , V_51 ) )
return - V_68 ;
switch ( V_51 ) {
case V_76 :
F_43 ( V_3 , V_5 , & V_63 , & V_64 ) ;
if ( V_63 )
return 0 ;
else
return - V_42 ;
case V_77 :
F_43 ( V_3 , V_5 , & V_63 , & V_64 ) ;
if ( ! V_63 && V_64 )
return 0 ;
else
return - V_42 ;
case V_78 :
F_43 ( V_3 , V_5 , & V_63 , & V_64 ) ;
if ( ! V_63 && ! V_64 )
return 0 ;
else
return - V_42 ;
case V_79 :
V_75 = F_45 ( V_3 , V_5 , & V_74 ) ;
if ( V_75 )
return V_75 ;
* V_73 = F_49 ( V_51 , V_74 ) ;
return 0 ;
default:
return - V_68 ;
}
return - V_68 ;
}
static int F_50 ( struct V_60 * V_61 , unsigned V_1 ,
unsigned long * V_80 , unsigned V_81 )
{
struct V_2 * V_3 = F_47 ( V_61 ) ;
enum V_50 V_51 ;
T_1 V_74 ;
unsigned V_16 , V_5 = F_1 ( V_1 ) ;
int V_75 = - V_68 ;
for ( V_16 = 0 ; V_16 < V_81 ; V_16 ++ ) {
V_51 = F_48 ( V_80 [ V_16 ] ) ;
if ( F_36 ( V_3 , V_51 ) )
return - V_68 ;
V_74 = F_51 ( V_80 [ V_16 ] ) ;
switch ( V_51 ) {
case V_76 :
V_75 = F_42 ( V_3 , V_5 , true , false ) ;
if ( V_75 < 0 )
goto V_82;
break;
case V_77 :
V_75 = F_42 ( V_3 , V_5 , false , true ) ;
if ( V_75 < 0 )
goto V_82;
break;
case V_78 :
V_75 = F_42 ( V_3 , V_5 , false , false ) ;
if ( V_75 < 0 )
goto V_82;
break;
case V_79 :
V_75 = F_44 ( V_3 , V_5 , V_74 ) ;
if ( V_75 < 0 )
goto V_82;
break;
default:
F_26 ( V_3 -> V_41 , L_9 ) ;
return - V_68 ;
}
}
V_82:
return V_75 ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_83 * V_84 = & V_3 -> V_84 ;
struct V_85 * V_86 ;
struct V_13 * V_14 = & V_3 -> V_14 ;
int V_16 ;
V_86 = F_39 ( V_3 -> V_41 , V_14 -> V_87 , sizeof( * V_86 ) , V_58 ) ;
if ( ! V_86 )
return - V_59 ;
for ( V_16 = 0 ; V_16 < V_14 -> V_87 ; V_16 ++ ) {
V_86 [ V_16 ] . V_88 = V_16 ;
V_86 [ V_16 ] . V_89 = F_53 ( V_3 -> V_41 , V_58 ,
L_10 , V_16 ) ;
if ( ! V_86 [ V_16 ] . V_89 )
return - V_59 ;
}
V_84 -> V_89 = F_54 ( V_3 -> V_41 ) ;
V_84 -> V_90 = & V_91 ;
V_84 -> V_86 = V_86 ;
V_84 -> V_92 = V_14 -> V_87 ;
V_84 -> V_93 = & V_94 ;
V_3 -> V_95 = F_55 ( V_3 -> V_41 , V_84 , V_3 ) ;
if ( F_56 ( V_3 -> V_95 ) ) {
F_26 ( V_3 -> V_41 , L_11 ) ;
return F_57 ( V_3 -> V_95 ) ;
}
return 0 ;
}
static int F_58 ( struct V_96 * V_97 )
{
struct V_98 * V_41 = & V_97 -> V_41 ;
struct V_99 * V_100 ;
struct V_2 * V_3 ;
struct V_13 * V_14 ;
T_1 V_101 , V_102 = 0 ;
int V_103 , V_75 ;
bool V_104 = false ;
if ( F_59 ( V_41 -> V_105 , L_12 ) )
V_102 = F_6 ( V_106 ) ;
else if ( F_59 ( V_41 -> V_105 ,
L_13 ) )
V_104 = true ;
V_3 = F_60 ( V_41 , sizeof( * V_3 ) , V_58 ) ;
if ( ! V_3 )
return - V_59 ;
V_3 -> V_41 = V_41 ;
F_61 ( V_97 , V_3 ) ;
V_100 = F_62 ( V_97 , V_107 , 0 ) ;
V_3 -> V_10 = F_63 ( V_41 , V_100 ) ;
if ( F_56 ( V_3 -> V_10 ) ) {
F_26 ( V_41 , L_14 ) ;
return F_57 ( V_3 -> V_10 ) ;
}
V_100 = F_62 ( V_97 , V_107 , 1 ) ;
if ( V_100 ) {
V_3 -> V_69 = F_63 ( V_41 , V_100 ) ;
if ( F_56 ( V_3 -> V_69 ) ) {
F_26 ( V_41 , L_14 ) ;
return F_57 ( V_3 -> V_69 ) ;
}
}
if ( F_64 ( V_41 -> V_105 , L_15 , & V_101 ) ) {
F_26 ( & V_97 -> V_41 , L_16 ) ;
return - V_108 ;
}
F_65 ( & V_3 -> V_31 ) ;
V_14 = & V_3 -> V_14 ;
V_14 -> V_10 = - 1 ;
V_14 -> V_87 = V_101 ;
V_3 -> V_18 = ( V_101 + V_21 - 1 ) / V_21 ;
V_14 -> V_109 = F_54 ( V_41 ) ;
V_14 -> V_110 = V_41 ;
V_14 -> V_105 = V_41 -> V_105 ;
V_14 -> V_111 = F_28 ;
V_14 -> free = F_30 ;
V_14 -> V_112 = F_32 ;
V_14 -> V_113 = F_33 ;
V_14 -> V_6 = F_34 ;
V_14 -> V_114 = F_35 ;
V_3 -> V_46 = F_66 ( V_41 -> V_105 ,
L_17 ) ;
V_75 = F_67 ( V_14 , V_3 ) ;
if ( V_75 < 0 ) {
F_26 ( V_41 , L_18 ) ;
return V_75 ;
}
if ( ! V_104 ) {
V_75 = F_52 ( V_3 ) ;
if ( V_75 ) {
F_26 ( V_41 , L_19 ) ;
goto V_115;
}
if ( V_102 ) {
V_75 = F_37 ( V_3 ,
V_102 ) ;
if ( V_75 ) {
F_26 ( V_41 ,
L_20 ) ;
goto V_115;
}
}
}
V_103 = F_68 ( V_97 , 0 ) ;
if ( V_103 ) {
V_75 = F_69 ( V_14 , & V_116 , 0 ,
V_117 , V_118 ) ;
if ( V_75 ) {
F_26 ( V_41 , L_21 ) ;
goto V_115;
}
F_70 ( V_14 , & V_116 , V_103 ,
F_9 ) ;
}
return 0 ;
V_115:
F_71 ( V_14 ) ;
return V_75 ;
}
static int T_4 F_72 ( void )
{
return F_73 ( & V_119 ) ;
}
