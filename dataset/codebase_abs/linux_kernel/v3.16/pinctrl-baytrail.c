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
const char * V_49 = NULL ;
const char * V_50 = NULL ;
const char * V_51 ;
V_48 = V_6 -> V_9 -> V_10 [ V_45 ] * 16 ;
V_46 = F_5 ( V_6 -> V_11 + V_48 + V_15 ) ;
V_47 = F_5 ( V_6 -> V_11 + V_48 + V_35 ) ;
V_51 = F_21 ( V_2 , V_45 ) ;
if ( ! V_51 )
V_51 = L_2 ;
switch ( V_46 & V_52 ) {
case V_53 :
V_50 = L_3 ;
break;
case V_54 :
V_50 = L_4 ;
break;
}
switch ( V_46 & V_55 ) {
case V_56 :
V_49 = L_5 ;
break;
case V_57 :
V_49 = L_6 ;
break;
case V_58 :
V_49 = L_7 ;
break;
case V_59 :
V_49 = L_8 ;
break;
}
F_22 ( V_44 ,
L_9 ,
V_45 ,
V_51 ,
V_47 & V_39 ? L_10 : L_11 ,
V_47 & V_42 ? L_12 : L_13 ,
V_47 & V_36 ? L_14 : L_15 ,
V_6 -> V_9 -> V_10 [ V_45 ] , V_48 ,
V_46 & 0x7 ,
V_46 & V_23 ? L_16 : L_17 ,
V_46 & V_22 ? L_18 : L_17 ,
V_46 & V_24 ? L_19 : L_20 ) ;
if ( V_50 && V_49 )
F_22 ( V_44 , L_21 , V_50 , V_49 ) ;
else
F_23 ( V_44 , L_22 ) ;
if ( V_46 & V_60 )
F_23 ( V_44 , L_23 ) ;
F_23 ( V_44 , L_24 ) ;
}
F_15 ( & V_6 -> V_29 , V_27 ) ;
}
static int F_24 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_25 ( V_6 -> V_61 , V_3 ) ;
}
static void F_26 ( unsigned V_62 , struct V_63 * V_64 )
{
struct V_25 * V_65 = F_27 ( V_64 ) ;
struct V_5 * V_6 = F_28 ( V_65 ) ;
struct V_66 * V_2 = F_29 ( V_65 ) ;
T_2 V_67 , V_68 , V_69 ;
void T_1 * V_4 ;
T_2 V_70 ;
unsigned V_71 ;
int V_72 = 0 ;
for ( V_67 = 0 ; V_67 < V_6 -> V_2 . V_28 ; V_67 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_67 , V_8 ) ;
while ( ( V_70 = F_5 ( V_4 ) ) ) {
V_68 = F_30 ( V_70 ) ;
V_69 = F_31 ( V_68 ) ;
F_9 ( V_69 , V_4 ) ;
V_71 = F_32 ( V_6 -> V_61 , V_67 + V_68 ) ;
F_33 ( V_71 ) ;
if ( V_72 ++ > 32 ) {
F_6 ( & V_6 -> V_19 -> V_20 ,
L_25 ,
V_67 + V_68 ) ;
V_4 = F_1 ( & V_6 -> V_2 , V_67 + V_68 ,
V_15 ) ;
V_69 = F_5 ( V_4 ) ;
V_69 &= ~ ( V_23 | V_22 |
V_24 ) ;
F_9 ( V_69 , V_4 ) ;
V_69 = F_5 ( V_4 ) ;
break;
}
}
}
V_2 -> V_73 ( V_65 ) ;
}
static void F_34 ( struct V_25 * V_26 )
{
}
static void F_35 ( struct V_25 * V_26 )
{
}
static int F_36 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_12 ( V_26 ) ;
if ( F_37 ( & V_6 -> V_2 , F_13 ( V_26 ) ) ) {
F_6 ( V_6 -> V_2 . V_20 ,
L_26 ,
F_13 ( V_26 ) ) ;
return - V_21 ;
}
return 0 ;
}
static void F_38 ( struct V_25 * V_26 )
{
struct V_5 * V_6 = F_12 ( V_26 ) ;
F_39 ( & V_6 -> V_2 , F_13 ( V_26 ) ) ;
}
static void F_40 ( struct V_5 * V_6 )
{
void T_1 * V_4 ;
T_2 V_67 , V_16 ;
for ( V_67 = 0 ; V_67 < V_6 -> V_2 . V_28 ; V_67 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_67 , V_8 ) ;
F_9 ( 0xffffffff , V_4 ) ;
V_16 = F_5 ( V_4 ) ;
if ( V_16 )
F_6 ( & V_6 -> V_19 -> V_20 ,
L_27 ) ;
}
}
static int F_41 ( struct V_74 * V_26 , unsigned int V_71 ,
T_3 V_75 )
{
struct V_5 * V_6 = V_26 -> V_76 ;
F_42 ( V_71 , & V_77 , V_78 ,
L_28 ) ;
F_43 ( V_71 , V_6 ) ;
F_44 ( V_71 , V_79 ) ;
return 0 ;
}
static int F_45 ( struct V_80 * V_19 )
{
struct V_5 * V_6 ;
struct V_1 * V_81 ;
struct V_82 * V_83 , * V_84 ;
struct V_85 * V_20 = & V_19 -> V_20 ;
struct V_86 * V_87 ;
struct V_88 * V_9 ;
T_4 V_89 = F_46 ( V_20 ) ;
unsigned V_90 ;
int V_91 ;
if ( F_47 ( V_89 , & V_87 ) )
return - V_92 ;
V_6 = F_48 ( V_20 , sizeof( struct V_5 ) , V_93 ) ;
if ( ! V_6 ) {
F_6 ( & V_19 -> V_20 , L_29 ) ;
return - V_94 ;
}
for ( V_9 = V_95 ; V_9 -> V_12 ; V_9 ++ ) {
if ( ! strcmp ( V_87 -> V_96 . V_97 , V_9 -> V_12 ) ) {
V_6 -> V_2 . V_28 = V_9 -> V_98 ;
V_6 -> V_9 = V_9 ;
break;
}
}
if ( ! V_6 -> V_2 . V_28 || ! V_6 -> V_9 )
return - V_92 ;
V_6 -> V_19 = V_19 ;
F_49 ( V_19 , V_6 ) ;
V_83 = F_50 ( V_19 , V_99 , 0 ) ;
V_6 -> V_11 = F_51 ( V_20 , V_83 ) ;
if ( F_52 ( V_6 -> V_11 ) )
return F_53 ( V_6 -> V_11 ) ;
F_54 ( & V_6 -> V_29 ) ;
V_81 = & V_6 -> V_2 ;
V_81 -> V_51 = F_55 ( & V_19 -> V_20 ) ;
V_81 -> V_100 = V_101 ;
V_81 -> V_102 = F_4 ;
V_81 -> free = F_8 ;
V_81 -> V_103 = F_18 ;
V_81 -> V_104 = F_19 ;
V_81 -> V_105 = F_16 ;
V_81 -> V_106 = F_17 ;
V_81 -> V_107 = F_20 ;
V_81 -> V_67 = - 1 ;
V_81 -> V_108 = false ;
V_81 -> V_20 = V_20 ;
V_84 = F_50 ( V_19 , V_109 , 0 ) ;
if ( V_84 && V_84 -> V_110 ) {
V_90 = V_84 -> V_110 ;
V_81 -> V_111 = F_24 ;
V_6 -> V_61 = F_56 ( NULL , V_81 -> V_28 ,
& V_112 , V_6 ) ;
if ( ! V_6 -> V_61 )
return - V_113 ;
F_40 ( V_6 ) ;
F_57 ( V_90 , V_6 ) ;
F_58 ( V_90 , F_26 ) ;
}
V_91 = F_59 ( V_81 ) ;
if ( V_91 ) {
F_6 ( & V_19 -> V_20 , L_30 ) ;
return V_91 ;
}
F_60 ( V_20 ) ;
return 0 ;
}
static int F_61 ( struct V_85 * V_20 )
{
return 0 ;
}
static int F_62 ( struct V_85 * V_20 )
{
return 0 ;
}
static int F_63 ( struct V_80 * V_19 )
{
struct V_5 * V_6 = F_64 ( V_19 ) ;
int V_114 ;
F_65 ( & V_19 -> V_20 ) ;
V_114 = F_66 ( & V_6 -> V_2 ) ;
if ( V_114 )
F_67 ( & V_19 -> V_20 , L_31 ) ;
return 0 ;
}
static int T_5 F_68 ( void )
{
return F_69 ( & V_115 ) ;
}
