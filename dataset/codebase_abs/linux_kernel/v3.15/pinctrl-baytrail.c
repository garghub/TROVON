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
struct V_5 * V_6 = F_12 ( V_26 ) ;
T_2 V_3 = F_13 ( V_26 ) ;
T_2 V_16 ;
unsigned long V_27 ;
void T_1 * V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_15 ) ;
if ( V_3 >= V_6 -> V_2 . V_28 )
return - V_21 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
V_16 = F_5 ( V_4 ) ;
V_16 &= ~ ( V_22 | V_23 | V_24 ) ;
switch ( type ) {
case V_30 :
V_16 |= V_24 ;
case V_31 :
V_16 |= V_22 ;
break;
case V_32 :
V_16 |= V_24 ;
case V_33 :
V_16 |= V_23 ;
break;
case V_34 :
V_16 |= ( V_23 | V_22 ) ;
break;
}
F_9 ( V_16 , V_4 ) ;
F_15 ( & V_6 -> V_29 , V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_35 ) ;
return F_5 ( V_4 ) & V_36 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned V_3 , int V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_35 ) ;
unsigned long V_27 ;
T_2 V_37 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
V_37 = F_5 ( V_4 ) ;
if ( V_16 )
F_9 ( V_37 | V_36 , V_4 ) ;
else
F_9 ( V_37 & ~ V_36 , V_4 ) ;
F_15 ( & V_6 -> V_29 , V_27 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_35 ) ;
unsigned long V_27 ;
T_2 V_16 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
V_16 = F_5 ( V_4 ) | V_38 ;
V_16 &= ~ V_39 ;
F_9 ( V_16 , V_4 ) ;
F_15 ( & V_6 -> V_29 , V_27 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned V_40 , int V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_40 , V_35 ) ;
unsigned long V_27 ;
T_2 V_41 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
V_41 = F_5 ( V_4 ) | V_38 ;
V_41 &= ~ V_42 ;
if ( V_16 )
F_9 ( V_41 | V_36 , V_4 ) ;
else
F_9 ( V_41 & ~ V_36 , V_4 ) ;
F_15 ( & V_6 -> V_29 , V_27 ) ;
return 0 ;
}
static void F_20 ( struct V_43 * V_44 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_45 ;
unsigned long V_27 ;
T_2 V_46 , V_47 , V_48 ;
F_14 ( & V_6 -> V_29 , V_27 ) ;
for ( V_45 = 0 ; V_45 < V_6 -> V_2 . V_28 ; V_45 ++ ) {
const char * V_49 ;
V_48 = V_6 -> V_9 -> V_10 [ V_45 ] * 16 ;
V_46 = F_5 ( V_6 -> V_11 + V_48 + V_15 ) ;
V_47 = F_5 ( V_6 -> V_11 + V_48 + V_35 ) ;
V_49 = F_21 ( V_2 , V_45 ) ;
if ( ! V_49 )
V_49 = L_2 ;
F_22 ( V_44 ,
L_3 ,
V_45 ,
V_49 ,
V_47 & V_39 ? L_4 : L_5 ,
V_47 & V_42 ? L_6 : L_7 ,
V_47 & V_36 ? L_8 : L_9 ,
V_6 -> V_9 -> V_10 [ V_45 ] , V_48 ,
V_46 & 0x7 ,
V_46 & V_23 ? L_10 : L_11 ,
V_46 & V_22 ? L_12 : L_11 ,
V_46 & V_24 ? L_13 : L_11 ) ;
}
F_15 ( & V_6 -> V_29 , V_27 ) ;
}
static int F_23 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_24 ( V_6 -> V_50 , V_3 ) ;
}
static void F_25 ( unsigned V_51 , struct V_52 * V_53 )
{
struct V_25 * V_54 = F_26 ( V_53 ) ;
struct V_5 * V_6 = F_27 ( V_54 ) ;
struct V_55 * V_2 = F_28 ( V_54 ) ;
T_2 V_56 , V_57 , V_58 ;
void T_1 * V_4 ;
T_2 V_59 ;
unsigned V_60 ;
int V_61 = 0 ;
for ( V_56 = 0 ; V_56 < V_6 -> V_2 . V_28 ; V_56 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_56 , V_8 ) ;
while ( ( V_59 = F_5 ( V_4 ) ) ) {
V_57 = F_29 ( V_59 ) ;
V_58 = F_30 ( V_57 ) ;
F_9 ( V_58 , V_4 ) ;
V_60 = F_31 ( V_6 -> V_50 , V_56 + V_57 ) ;
F_32 ( V_60 ) ;
if ( V_61 ++ > 32 ) {
F_6 ( & V_6 -> V_19 -> V_20 ,
L_14 ,
V_56 + V_57 ) ;
V_4 = F_1 ( & V_6 -> V_2 , V_56 + V_57 ,
V_15 ) ;
V_58 = F_5 ( V_4 ) ;
V_58 &= ~ ( V_23 | V_22 |
V_24 ) ;
F_9 ( V_58 , V_4 ) ;
V_58 = F_5 ( V_4 ) ;
break;
}
}
}
V_2 -> V_62 ( V_54 ) ;
}
static void F_33 ( struct V_25 * V_26 )
{
}
static void F_34 ( struct V_25 * V_26 )
{
}
static int F_35 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_12 ( V_26 ) ;
if ( F_36 ( & V_6 -> V_2 , F_13 ( V_26 ) ) ) {
F_6 ( V_6 -> V_2 . V_20 ,
L_15 ,
F_13 ( V_26 ) ) ;
return - V_21 ;
}
return 0 ;
}
static void F_37 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_12 ( V_26 ) ;
F_38 ( & V_6 -> V_2 , F_13 ( V_26 ) ) ;
}
static void F_39 ( struct V_5 * V_6 )
{
void T_1 * V_4 ;
T_2 V_56 , V_16 ;
for ( V_56 = 0 ; V_56 < V_6 -> V_2 . V_28 ; V_56 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_56 , V_8 ) ;
F_9 ( 0xffffffff , V_4 ) ;
V_16 = F_5 ( V_4 ) ;
if ( V_16 )
F_6 ( & V_6 -> V_19 -> V_20 ,
L_16 ) ;
}
}
static int F_40 ( struct V_63 * V_26 , unsigned int V_60 ,
T_3 V_64 )
{
struct V_5 * V_6 = V_26 -> V_65 ;
F_41 ( V_60 , & V_66 , V_67 ,
L_17 ) ;
F_42 ( V_60 , V_6 ) ;
F_43 ( V_60 , V_68 ) ;
return 0 ;
}
static int F_44 ( struct V_69 * V_19 )
{
struct V_5 * V_6 ;
struct V_1 * V_70 ;
struct V_71 * V_72 , * V_73 ;
struct V_74 * V_20 = & V_19 -> V_20 ;
struct V_75 * V_76 ;
struct V_77 * V_9 ;
T_4 V_78 = F_45 ( V_20 ) ;
unsigned V_79 ;
int V_80 ;
if ( F_46 ( V_78 , & V_76 ) )
return - V_81 ;
V_6 = F_47 ( V_20 , sizeof( struct V_5 ) , V_82 ) ;
if ( ! V_6 ) {
F_6 ( & V_19 -> V_20 , L_18 ) ;
return - V_83 ;
}
for ( V_9 = V_84 ; V_9 -> V_12 ; V_9 ++ ) {
if ( ! strcmp ( V_76 -> V_85 . V_86 , V_9 -> V_12 ) ) {
V_6 -> V_2 . V_28 = V_9 -> V_87 ;
V_6 -> V_9 = V_9 ;
break;
}
}
if ( ! V_6 -> V_2 . V_28 || ! V_6 -> V_9 )
return - V_81 ;
V_6 -> V_19 = V_19 ;
F_48 ( V_19 , V_6 ) ;
V_72 = F_49 ( V_19 , V_88 , 0 ) ;
V_6 -> V_11 = F_50 ( V_20 , V_72 ) ;
if ( F_51 ( V_6 -> V_11 ) )
return F_52 ( V_6 -> V_11 ) ;
F_53 ( & V_6 -> V_29 ) ;
V_70 = & V_6 -> V_2 ;
V_70 -> V_49 = F_54 ( & V_19 -> V_20 ) ;
V_70 -> V_89 = V_90 ;
V_70 -> V_91 = F_4 ;
V_70 -> free = F_8 ;
V_70 -> V_92 = F_18 ;
V_70 -> V_93 = F_19 ;
V_70 -> V_94 = F_16 ;
V_70 -> V_95 = F_17 ;
V_70 -> V_96 = F_20 ;
V_70 -> V_56 = - 1 ;
V_70 -> V_97 = false ;
V_70 -> V_20 = V_20 ;
V_80 = F_55 ( V_70 ) ;
if ( V_80 ) {
F_6 ( & V_19 -> V_20 , L_19 ) ;
return V_80 ;
}
V_73 = F_49 ( V_19 , V_98 , 0 ) ;
if ( V_73 && V_73 -> V_99 ) {
V_79 = V_73 -> V_99 ;
V_70 -> V_100 = F_23 ;
V_6 -> V_50 = F_56 ( NULL , V_70 -> V_28 ,
& V_101 , V_6 ) ;
if ( ! V_6 -> V_50 )
return - V_102 ;
F_39 ( V_6 ) ;
F_57 ( V_79 , V_6 ) ;
F_58 ( V_79 , F_25 ) ;
}
F_59 ( V_20 ) ;
return 0 ;
}
static int F_60 ( struct V_74 * V_20 )
{
return 0 ;
}
static int F_61 ( struct V_74 * V_20 )
{
return 0 ;
}
static int F_62 ( struct V_69 * V_19 )
{
struct V_5 * V_6 = F_63 ( V_19 ) ;
int V_103 ;
F_64 ( & V_19 -> V_20 ) ;
V_103 = F_65 ( & V_6 -> V_2 ) ;
if ( V_103 )
F_66 ( & V_19 -> V_20 , L_20 ) ;
return 0 ;
}
static int T_5 F_67 ( void )
{
return F_68 ( & V_104 ) ;
}
