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
static bool F_3 ( struct V_5 * V_6 , unsigned V_3 )
{
if ( ! strcmp ( V_6 -> V_9 -> V_12 , V_13 ) &&
V_3 >= 92 && V_3 <= 93 )
return true ;
if ( ! strcmp ( V_6 -> V_9 -> V_12 , V_14 ) &&
V_3 >= 11 && V_3 <= 21 )
return true ;
return false ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_15 ) ;
T_2 V_16 ;
bool V_17 ;
V_16 = F_5 ( V_4 ) & V_18 ;
V_17 = F_3 ( V_6 , V_3 ) ;
if ( ( V_17 && V_16 != 1 ) || ( ! V_17 && V_16 ) ) {
F_6 ( & V_6 -> V_19 -> V_20 ,
L_1 , V_3 ) ;
return - V_21 ;
}
F_7 ( & V_6 -> V_19 -> V_20 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_15 ) ;
T_2 V_16 ;
V_16 = F_5 ( V_4 ) ;
V_16 &= ~ ( V_22 | V_23 | V_24 ) ;
F_9 ( V_16 , V_4 ) ;
F_10 ( & V_6 -> V_19 -> V_20 ) ;
}
static int F_11 ( struct V_25 * V_26 , unsigned type )
{
struct V_5 * V_6 = F_2 ( F_12 ( V_26 ) ) ;
T_2 V_3 = F_13 ( V_26 ) ;
T_2 V_16 ;
unsigned long V_27 ;
void T_1 * V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_15 ) ;
if ( V_3 >= V_6 -> V_2 . V_28 )
return - V_21 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
V_16 = F_5 ( V_4 ) ;
F_15 ( V_16 & V_30 ,
L_2 ) ;
V_16 &= ~ ( V_30 | V_22 | V_23 |
V_24 ) ;
switch ( type ) {
case V_31 :
V_16 |= V_24 ;
case V_32 :
V_16 |= V_22 ;
break;
case V_33 :
V_16 |= V_24 ;
case V_34 :
V_16 |= V_23 ;
break;
case V_35 :
V_16 |= ( V_23 | V_22 ) ;
break;
}
F_9 ( V_16 , V_4 ) ;
F_16 ( & V_6 -> V_29 , V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_36 ) ;
return F_5 ( V_4 ) & V_37 ;
}
static void F_18 ( struct V_1 * V_2 , unsigned V_3 , int V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_36 ) ;
unsigned long V_27 ;
T_2 V_38 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
V_38 = F_5 ( V_4 ) ;
if ( V_16 )
F_9 ( V_38 | V_37 , V_4 ) ;
else
F_9 ( V_38 & ~ V_37 , V_4 ) ;
F_16 ( & V_6 -> V_29 , V_27 ) ;
}
static int F_19 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_36 ) ;
unsigned long V_27 ;
T_2 V_16 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
V_16 = F_5 ( V_4 ) | V_39 ;
V_16 &= ~ V_40 ;
F_9 ( V_16 , V_4 ) ;
F_16 ( & V_6 -> V_29 , V_27 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned V_41 , int V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_42 = F_1 ( V_2 , V_41 , V_15 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_41 , V_36 ) ;
unsigned long V_27 ;
T_2 V_43 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
F_15 ( F_5 ( V_42 ) & V_30 ,
L_3 ) ;
V_43 = F_5 ( V_4 ) | V_39 ;
V_43 &= ~ ( V_44 | V_40 ) ;
if ( V_16 )
F_9 ( V_43 | V_37 , V_4 ) ;
else
F_9 ( V_43 & ~ V_37 , V_4 ) ;
F_16 ( & V_6 -> V_29 , V_27 ) ;
return 0 ;
}
static void F_21 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_47 ;
unsigned long V_27 ;
T_2 V_48 , V_49 , V_50 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
for ( V_47 = 0 ; V_47 < V_6 -> V_2 . V_28 ; V_47 ++ ) {
const char * V_51 = NULL ;
const char * V_52 = NULL ;
const char * V_53 ;
V_50 = V_6 -> V_9 -> V_10 [ V_47 ] * 16 ;
V_48 = F_5 ( V_6 -> V_11 + V_50 + V_15 ) ;
V_49 = F_5 ( V_6 -> V_11 + V_50 + V_36 ) ;
V_53 = F_22 ( V_2 , V_47 ) ;
if ( ! V_53 )
V_53 = L_4 ;
switch ( V_48 & V_54 ) {
case V_55 :
V_52 = L_5 ;
break;
case V_56 :
V_52 = L_6 ;
break;
}
switch ( V_48 & V_57 ) {
case V_58 :
V_51 = L_7 ;
break;
case V_59 :
V_51 = L_8 ;
break;
case V_60 :
V_51 = L_9 ;
break;
case V_61 :
V_51 = L_10 ;
break;
}
F_23 ( V_46 ,
L_11 ,
V_47 ,
V_53 ,
V_49 & V_40 ? L_12 : L_13 ,
V_49 & V_44 ? L_14 : L_15 ,
V_49 & V_37 ? L_16 : L_17 ,
V_6 -> V_9 -> V_10 [ V_47 ] , V_50 ,
V_48 & 0x7 ,
V_48 & V_23 ? L_18 : L_19 ,
V_48 & V_22 ? L_20 : L_19 ,
V_48 & V_24 ? L_21 : L_22 ) ;
if ( V_52 && V_51 )
F_23 ( V_46 , L_23 , V_52 , V_51 ) ;
else
F_24 ( V_46 , L_24 ) ;
if ( V_48 & V_62 )
F_24 ( V_46 , L_25 ) ;
F_24 ( V_46 , L_26 ) ;
}
F_16 ( & V_6 -> V_29 , V_27 ) ;
}
static void F_25 ( unsigned V_63 , struct V_64 * V_65 )
{
struct V_25 * V_66 = F_26 ( V_65 ) ;
struct V_5 * V_6 = F_2 ( F_27 ( V_65 ) ) ;
struct V_67 * V_2 = F_28 ( V_66 ) ;
T_2 V_68 , V_69 , V_70 ;
void T_1 * V_4 ;
T_2 V_71 ;
unsigned V_72 ;
int V_73 = 0 ;
for ( V_68 = 0 ; V_68 < V_6 -> V_2 . V_28 ; V_68 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_68 , V_8 ) ;
while ( ( V_71 = F_5 ( V_4 ) ) ) {
V_69 = F_29 ( V_71 ) ;
V_70 = F_30 ( V_69 ) ;
F_9 ( V_70 , V_4 ) ;
V_72 = F_31 ( V_6 -> V_2 . V_74 , V_68 + V_69 ) ;
F_32 ( V_72 ) ;
if ( V_73 ++ > 32 ) {
F_6 ( & V_6 -> V_19 -> V_20 ,
L_27 ,
V_68 + V_69 ) ;
V_4 = F_1 ( & V_6 -> V_2 , V_68 + V_69 ,
V_15 ) ;
V_70 = F_5 ( V_4 ) ;
V_70 &= ~ ( V_23 | V_22 |
V_24 ) ;
F_9 ( V_70 , V_4 ) ;
V_70 = F_5 ( V_4 ) ;
break;
}
}
}
V_2 -> V_75 ( V_66 ) ;
}
static void F_33 ( struct V_25 * V_26 )
{
}
static void F_34 ( struct V_25 * V_26 )
{
}
static void F_35 ( struct V_5 * V_6 )
{
void T_1 * V_4 ;
T_2 V_68 , V_16 ;
for ( V_68 = 0 ; V_68 < V_6 -> V_2 . V_28 ; V_68 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_68 , V_8 ) ;
F_9 ( 0xffffffff , V_4 ) ;
V_16 = F_5 ( V_4 ) ;
if ( V_16 )
F_6 ( & V_6 -> V_19 -> V_20 ,
L_28 ) ;
}
}
static int F_36 ( struct V_76 * V_19 )
{
struct V_5 * V_6 ;
struct V_1 * V_77 ;
struct V_78 * V_79 , * V_80 ;
struct V_81 * V_20 = & V_19 -> V_20 ;
struct V_82 * V_83 ;
struct V_84 * V_9 ;
T_3 V_85 = F_37 ( V_20 ) ;
int V_86 ;
if ( F_38 ( V_85 , & V_83 ) )
return - V_87 ;
V_6 = F_39 ( V_20 , sizeof( struct V_5 ) , V_88 ) ;
if ( ! V_6 ) {
F_6 ( & V_19 -> V_20 , L_29 ) ;
return - V_89 ;
}
for ( V_9 = V_90 ; V_9 -> V_12 ; V_9 ++ ) {
if ( ! strcmp ( V_83 -> V_91 . V_92 , V_9 -> V_12 ) ) {
V_6 -> V_2 . V_28 = V_9 -> V_93 ;
V_6 -> V_9 = V_9 ;
break;
}
}
if ( ! V_6 -> V_2 . V_28 || ! V_6 -> V_9 )
return - V_87 ;
V_6 -> V_19 = V_19 ;
F_40 ( V_19 , V_6 ) ;
V_79 = F_41 ( V_19 , V_94 , 0 ) ;
V_6 -> V_11 = F_42 ( V_20 , V_79 ) ;
if ( F_43 ( V_6 -> V_11 ) )
return F_44 ( V_6 -> V_11 ) ;
F_45 ( & V_6 -> V_29 ) ;
V_77 = & V_6 -> V_2 ;
V_77 -> V_53 = F_46 ( & V_19 -> V_20 ) ;
V_77 -> V_95 = V_96 ;
V_77 -> V_97 = F_4 ;
V_77 -> free = F_8 ;
V_77 -> V_98 = F_19 ;
V_77 -> V_99 = F_20 ;
V_77 -> V_100 = F_17 ;
V_77 -> V_101 = F_18 ;
V_77 -> V_102 = F_21 ;
V_77 -> V_68 = - 1 ;
V_77 -> V_103 = false ;
V_77 -> V_20 = V_20 ;
V_86 = F_47 ( V_77 ) ;
if ( V_86 ) {
F_6 ( & V_19 -> V_20 , L_30 ) ;
return V_86 ;
}
V_80 = F_41 ( V_19 , V_104 , 0 ) ;
if ( V_80 && V_80 -> V_105 ) {
F_35 ( V_6 ) ;
V_86 = F_48 ( V_77 , & V_106 , 0 ,
V_107 , V_108 ) ;
if ( V_86 ) {
F_6 ( V_20 , L_31 ) ;
F_49 ( V_77 ) ;
return V_86 ;
}
F_50 ( V_77 , & V_106 ,
( unsigned ) V_80 -> V_105 ,
F_25 ) ;
}
F_51 ( V_20 ) ;
return 0 ;
}
static int F_52 ( struct V_81 * V_20 )
{
return 0 ;
}
static int F_53 ( struct V_81 * V_20 )
{
return 0 ;
}
static int F_54 ( struct V_76 * V_19 )
{
struct V_5 * V_6 = F_55 ( V_19 ) ;
F_56 ( & V_19 -> V_20 ) ;
F_49 ( & V_6 -> V_2 ) ;
return 0 ;
}
static int T_4 F_57 ( void )
{
return F_58 ( & V_109 ) ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_109 ) ;
}
