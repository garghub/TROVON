static void T_1 * F_1 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_7 ;
if ( V_4 == V_8 )
V_7 = ( V_3 / 32 ) * 4 ;
else
V_7 = V_6 -> V_9 -> V_10 [ V_3 ] * 16 ;
return V_6 -> V_11 + V_7 + V_4 ;
}
static void F_3 ( struct V_5 * V_6 , unsigned V_3 )
{
void T_1 * V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_12 ) ;
unsigned long V_13 ;
T_2 V_14 ;
F_4 ( & V_6 -> V_15 , V_13 ) ;
V_14 = F_5 ( V_4 ) ;
V_14 &= ~ ( V_16 | V_17 | V_18 ) ;
F_6 ( V_14 , V_4 ) ;
F_7 ( & V_6 -> V_15 , V_13 ) ;
}
static T_2 F_8 ( struct V_5 * V_6 , unsigned V_3 )
{
if ( ! strcmp ( V_6 -> V_9 -> V_19 , V_20 ) &&
V_3 >= 92 && V_3 <= 93 )
return 1 ;
if ( ! strcmp ( V_6 -> V_9 -> V_19 , V_21 ) &&
V_3 >= 11 && V_3 <= 21 )
return 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_12 ) ;
T_2 V_14 , V_22 ;
unsigned long V_13 ;
F_4 ( & V_6 -> V_15 , V_13 ) ;
V_14 = F_5 ( V_4 ) & V_23 ;
V_22 = F_8 ( V_6 , V_3 ) ;
if ( F_10 ( V_22 != V_14 ) ) {
V_14 = F_5 ( V_4 ) & ~ V_23 ;
V_14 |= V_22 ;
F_6 ( V_14 , V_4 ) ;
F_11 ( & V_6 -> V_24 -> V_25 ,
L_1 , V_3 ) ;
}
F_7 ( & V_6 -> V_15 , V_13 ) ;
F_12 ( & V_6 -> V_24 -> V_25 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_3 ) ;
F_14 ( & V_6 -> V_24 -> V_25 ) ;
}
static int F_15 ( struct V_26 * V_27 , unsigned type )
{
struct V_5 * V_6 = F_2 ( F_16 ( V_27 ) ) ;
T_2 V_3 = F_17 ( V_27 ) ;
T_2 V_14 ;
unsigned long V_13 ;
void T_1 * V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_12 ) ;
if ( V_3 >= V_6 -> V_2 . V_28 )
return - V_29 ;
F_4 ( & V_6 -> V_15 , V_13 ) ;
V_14 = F_5 ( V_4 ) ;
F_18 ( V_14 & V_30 ,
L_2 ) ;
V_14 &= ~ ( V_30 | V_16 | V_17 |
V_18 ) ;
F_6 ( V_14 , V_4 ) ;
if ( type & V_31 )
F_19 ( V_27 , V_32 ) ;
else if ( type & V_33 )
F_19 ( V_27 , V_34 ) ;
F_7 ( & V_6 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_35 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_13 ;
T_2 V_36 ;
F_4 ( & V_6 -> V_15 , V_13 ) ;
V_36 = F_5 ( V_4 ) ;
F_7 ( & V_6 -> V_15 , V_13 ) ;
return ! ! ( V_36 & V_37 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned V_3 , int V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_35 ) ;
unsigned long V_13 ;
T_2 V_38 ;
F_4 ( & V_6 -> V_15 , V_13 ) ;
V_38 = F_5 ( V_4 ) ;
if ( V_14 )
F_6 ( V_38 | V_37 , V_4 ) ;
else
F_6 ( V_38 & ~ V_37 , V_4 ) ;
F_7 ( & V_6 -> V_15 , V_13 ) ;
}
static int F_22 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_35 ) ;
unsigned long V_13 ;
T_2 V_14 ;
F_4 ( & V_6 -> V_15 , V_13 ) ;
V_14 = F_5 ( V_4 ) | V_39 ;
V_14 &= ~ V_40 ;
F_6 ( V_14 , V_4 ) ;
F_7 ( & V_6 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned V_41 , int V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_42 = F_1 ( V_2 , V_41 , V_12 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_41 , V_35 ) ;
unsigned long V_13 ;
T_2 V_43 ;
F_4 ( & V_6 -> V_15 , V_13 ) ;
F_18 ( F_5 ( V_42 ) & V_30 ,
L_3 ) ;
V_43 = F_5 ( V_4 ) | V_39 ;
V_43 &= ~ ( V_44 | V_40 ) ;
if ( V_14 )
F_6 ( V_43 | V_37 , V_4 ) ;
else
F_6 ( V_43 & ~ V_37 , V_4 ) ;
F_7 ( & V_6 -> V_15 , V_13 ) ;
return 0 ;
}
static void F_24 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_47 ;
T_2 V_48 , V_36 , V_49 ;
for ( V_47 = 0 ; V_47 < V_6 -> V_2 . V_28 ; V_47 ++ ) {
const char * V_50 = NULL ;
const char * V_51 = NULL ;
unsigned long V_13 ;
const char * V_52 ;
V_49 = V_6 -> V_9 -> V_10 [ V_47 ] * 16 ;
F_4 ( & V_6 -> V_15 , V_13 ) ;
V_48 = F_5 ( V_6 -> V_11 + V_49 + V_12 ) ;
V_36 = F_5 ( V_6 -> V_11 + V_49 + V_35 ) ;
F_7 ( & V_6 -> V_15 , V_13 ) ;
V_52 = F_25 ( V_2 , V_47 ) ;
if ( ! V_52 )
V_52 = L_4 ;
switch ( V_48 & V_53 ) {
case V_54 :
V_51 = L_5 ;
break;
case V_55 :
V_51 = L_6 ;
break;
}
switch ( V_48 & V_56 ) {
case V_57 :
V_50 = L_7 ;
break;
case V_58 :
V_50 = L_8 ;
break;
case V_59 :
V_50 = L_9 ;
break;
case V_60 :
V_50 = L_10 ;
break;
}
F_26 ( V_46 ,
L_11 ,
V_47 ,
V_52 ,
V_36 & V_40 ? L_12 : L_13 ,
V_36 & V_44 ? L_14 : L_15 ,
V_36 & V_37 ? L_16 : L_17 ,
V_6 -> V_9 -> V_10 [ V_47 ] , V_49 ,
V_48 & 0x7 ,
V_48 & V_17 ? L_18 : L_19 ,
V_48 & V_16 ? L_20 : L_19 ,
V_48 & V_18 ? L_21 : L_22 ) ;
if ( V_51 && V_50 )
F_26 ( V_46 , L_23 , V_51 , V_50 ) ;
else
F_27 ( V_46 , L_24 ) ;
if ( V_48 & V_61 )
F_27 ( V_46 , L_25 ) ;
F_27 ( V_46 , L_26 ) ;
}
}
static void F_28 ( struct V_62 * V_63 )
{
struct V_26 * V_64 = F_29 ( V_63 ) ;
struct V_5 * V_6 = F_2 ( F_30 ( V_63 ) ) ;
struct V_65 * V_2 = F_31 ( V_64 ) ;
T_2 V_66 , V_67 ;
void T_1 * V_4 ;
unsigned long V_68 ;
unsigned V_69 ;
for ( V_66 = 0 ; V_66 < V_6 -> V_2 . V_28 ; V_66 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_66 , V_8 ) ;
V_68 = F_5 ( V_4 ) ;
F_32 (pin, &pending, 32 ) {
V_69 = F_33 ( V_6 -> V_2 . V_70 , V_66 + V_67 ) ;
F_34 ( V_69 ) ;
}
}
V_2 -> V_71 ( V_64 ) ;
}
static void F_35 ( struct V_26 * V_27 )
{
struct V_1 * V_72 = F_16 ( V_27 ) ;
struct V_5 * V_6 = F_2 ( V_72 ) ;
unsigned V_3 = F_17 ( V_27 ) ;
void T_1 * V_4 ;
F_36 ( & V_6 -> V_15 ) ;
V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_8 ) ;
F_6 ( F_37 ( V_3 % 32 ) , V_4 ) ;
F_38 ( & V_6 -> V_15 ) ;
}
static void F_39 ( struct V_26 * V_27 )
{
struct V_1 * V_72 = F_16 ( V_27 ) ;
struct V_5 * V_6 = F_2 ( V_72 ) ;
unsigned V_3 = F_17 ( V_27 ) ;
unsigned long V_13 ;
void T_1 * V_4 ;
T_2 V_14 ;
V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_12 ) ;
F_4 ( & V_6 -> V_15 , V_13 ) ;
V_14 = F_5 ( V_4 ) ;
switch ( F_40 ( V_27 ) ) {
case V_73 :
V_14 |= V_18 ;
case V_74 :
V_14 |= V_16 ;
break;
case V_75 :
V_14 |= V_18 ;
case V_76 :
V_14 |= V_17 ;
break;
case V_31 :
V_14 |= ( V_17 | V_16 ) ;
break;
}
F_6 ( V_14 , V_4 ) ;
F_7 ( & V_6 -> V_15 , V_13 ) ;
}
static void F_41 ( struct V_26 * V_27 )
{
struct V_1 * V_72 = F_16 ( V_27 ) ;
struct V_5 * V_6 = F_2 ( V_72 ) ;
F_3 ( V_6 , F_17 ( V_27 ) ) ;
}
static void F_42 ( struct V_5 * V_6 )
{
void T_1 * V_4 ;
T_2 V_66 , V_14 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_6 -> V_2 . V_28 ; V_47 ++ ) {
V_14 = F_5 ( F_1 ( & V_6 -> V_2 , V_47 , V_12 ) ) ;
if ( ( V_14 & V_23 ) == F_8 ( V_6 , V_47 ) &&
! ( V_14 & V_30 ) ) {
F_3 ( V_6 , V_47 ) ;
F_43 ( & V_6 -> V_24 -> V_25 , L_27 , V_47 ) ;
}
}
for ( V_66 = 0 ; V_66 < V_6 -> V_2 . V_28 ; V_66 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_66 , V_8 ) ;
F_6 ( 0xffffffff , V_4 ) ;
V_14 = F_5 ( V_4 ) ;
if ( V_14 )
F_44 ( & V_6 -> V_24 -> V_25 ,
L_28 ) ;
}
}
static int F_45 ( struct V_77 * V_24 )
{
struct V_5 * V_6 ;
struct V_1 * V_72 ;
struct V_78 * V_79 , * V_80 ;
struct V_81 * V_25 = & V_24 -> V_25 ;
struct V_82 * V_83 ;
struct V_84 * V_9 ;
T_3 V_85 = F_46 ( V_25 ) ;
int V_86 ;
if ( F_47 ( V_85 , & V_83 ) )
return - V_87 ;
V_6 = F_48 ( V_25 , sizeof( struct V_5 ) , V_88 ) ;
if ( ! V_6 ) {
F_44 ( & V_24 -> V_25 , L_29 ) ;
return - V_89 ;
}
for ( V_9 = V_90 ; V_9 -> V_19 ; V_9 ++ ) {
if ( ! strcmp ( V_83 -> V_91 . V_92 , V_9 -> V_19 ) ) {
V_6 -> V_2 . V_28 = V_9 -> V_93 ;
V_6 -> V_9 = V_9 ;
break;
}
}
if ( ! V_6 -> V_2 . V_28 || ! V_6 -> V_9 )
return - V_87 ;
V_6 -> V_24 = V_24 ;
F_49 ( V_24 , V_6 ) ;
V_79 = F_50 ( V_24 , V_94 , 0 ) ;
V_6 -> V_11 = F_51 ( V_25 , V_79 ) ;
if ( F_52 ( V_6 -> V_11 ) )
return F_53 ( V_6 -> V_11 ) ;
F_54 ( & V_6 -> V_15 ) ;
V_72 = & V_6 -> V_2 ;
V_72 -> V_52 = F_55 ( & V_24 -> V_25 ) ;
V_72 -> V_95 = V_96 ;
V_72 -> V_97 = F_9 ;
V_72 -> free = F_13 ;
V_72 -> V_98 = F_22 ;
V_72 -> V_99 = F_23 ;
V_72 -> V_100 = F_20 ;
V_72 -> V_101 = F_21 ;
V_72 -> V_102 = F_24 ;
V_72 -> V_66 = - 1 ;
V_72 -> V_103 = false ;
V_72 -> V_104 = V_25 ;
#ifdef F_56
V_6 -> V_105 = F_57 ( & V_24 -> V_25 , V_72 -> V_28 ,
sizeof( * V_6 -> V_105 ) , V_88 ) ;
#endif
V_86 = F_58 ( V_72 , V_6 ) ;
if ( V_86 ) {
F_44 ( & V_24 -> V_25 , L_30 ) ;
return V_86 ;
}
V_80 = F_50 ( V_24 , V_106 , 0 ) ;
if ( V_80 && V_80 -> V_107 ) {
F_42 ( V_6 ) ;
V_86 = F_59 ( V_72 , & V_108 , 0 ,
V_109 , V_110 ) ;
if ( V_86 ) {
F_44 ( V_25 , L_31 ) ;
F_60 ( V_72 ) ;
return V_86 ;
}
F_61 ( V_72 , & V_108 ,
( unsigned ) V_80 -> V_107 ,
F_28 ) ;
}
F_62 ( V_25 ) ;
return 0 ;
}
static int F_63 ( struct V_81 * V_25 )
{
struct V_77 * V_24 = F_64 ( V_25 ) ;
struct V_5 * V_6 = F_65 ( V_24 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_6 -> V_2 . V_28 ; V_47 ++ ) {
void T_1 * V_4 ;
T_2 V_14 ;
V_4 = F_1 ( & V_6 -> V_2 , V_47 , V_12 ) ;
V_14 = F_5 ( V_4 ) & V_111 ;
V_6 -> V_105 [ V_47 ] . V_48 = V_14 ;
V_4 = F_1 ( & V_6 -> V_2 , V_47 , V_35 ) ;
V_14 = F_5 ( V_4 ) & V_112 ;
V_6 -> V_105 [ V_47 ] . V_36 = V_14 ;
}
return 0 ;
}
static int F_66 ( struct V_81 * V_25 )
{
struct V_77 * V_24 = F_64 ( V_25 ) ;
struct V_5 * V_6 = F_65 ( V_24 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_6 -> V_2 . V_28 ; V_47 ++ ) {
void T_1 * V_4 ;
T_2 V_14 ;
V_4 = F_1 ( & V_6 -> V_2 , V_47 , V_12 ) ;
V_14 = F_5 ( V_4 ) ;
if ( ( V_14 & V_111 ) !=
V_6 -> V_105 [ V_47 ] . V_48 ) {
V_14 &= ~ V_111 ;
V_14 |= V_6 -> V_105 [ V_47 ] . V_48 ;
F_6 ( V_14 , V_4 ) ;
F_67 ( V_25 , L_32 , V_47 , V_14 ) ;
}
V_4 = F_1 ( & V_6 -> V_2 , V_47 , V_35 ) ;
V_14 = F_5 ( V_4 ) ;
if ( ( V_14 & V_112 ) !=
V_6 -> V_105 [ V_47 ] . V_36 ) {
T_2 V_113 ;
V_113 = V_14 & ~ V_112 ;
V_113 |= V_6 -> V_105 [ V_47 ] . V_36 ;
if ( V_113 != V_14 ) {
F_6 ( V_113 , V_4 ) ;
F_43 ( V_25 , L_33 ,
V_47 , V_113 ) ;
}
}
}
return 0 ;
}
static int F_68 ( struct V_81 * V_25 )
{
return 0 ;
}
static int F_69 ( struct V_81 * V_25 )
{
return 0 ;
}
static int F_70 ( struct V_77 * V_24 )
{
struct V_5 * V_6 = F_65 ( V_24 ) ;
F_71 ( & V_24 -> V_25 ) ;
F_60 ( & V_6 -> V_2 ) ;
return 0 ;
}
static int T_4 F_72 ( void )
{
return F_73 ( & V_114 ) ;
}
static void T_5 F_74 ( void )
{
F_75 ( & V_114 ) ;
}
