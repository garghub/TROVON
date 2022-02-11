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
static int F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( & V_6 -> V_12 -> V_13 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_14 ) ;
T_2 V_15 ;
V_15 = F_6 ( V_4 ) ;
V_15 &= ~ ( V_16 | V_17 | V_18 ) ;
F_7 ( V_15 , V_4 ) ;
F_8 ( & V_6 -> V_12 -> V_13 ) ;
}
static int F_9 ( struct V_19 * V_20 , unsigned type )
{
struct V_5 * V_6 = F_10 ( V_20 ) ;
T_2 V_3 = F_11 ( V_20 ) ;
T_2 V_15 ;
unsigned long V_21 ;
void T_1 * V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_14 ) ;
if ( V_3 >= V_6 -> V_2 . V_22 )
return - V_23 ;
F_12 ( & V_6 -> V_24 , V_21 ) ;
V_15 = F_6 ( V_4 ) ;
V_15 &= ~ ( V_16 | V_17 | V_18 ) ;
switch ( type ) {
case V_25 :
V_15 |= V_18 ;
case V_26 :
V_15 |= V_16 ;
break;
case V_27 :
V_15 |= V_18 ;
case V_28 :
V_15 |= V_17 ;
break;
case V_29 :
V_15 |= ( V_17 | V_16 ) ;
break;
}
F_7 ( V_15 , V_4 ) ;
F_13 ( & V_6 -> V_24 , V_21 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_30 ) ;
return F_6 ( V_4 ) & V_31 ;
}
static void F_15 ( struct V_1 * V_2 , unsigned V_3 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_30 ) ;
unsigned long V_21 ;
T_2 V_32 ;
F_12 ( & V_6 -> V_24 , V_21 ) ;
V_32 = F_6 ( V_4 ) ;
if ( V_15 )
F_7 ( V_32 | V_31 , V_4 ) ;
else
F_7 ( V_32 & ~ V_31 , V_4 ) ;
F_13 ( & V_6 -> V_24 , V_21 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_30 ) ;
unsigned long V_21 ;
T_2 V_15 ;
F_12 ( & V_6 -> V_24 , V_21 ) ;
V_15 = F_6 ( V_4 ) | V_33 ;
V_15 &= ~ V_34 ;
F_7 ( V_15 , V_4 ) ;
F_13 ( & V_6 -> V_24 , V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_35 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_35 , V_30 ) ;
unsigned long V_21 ;
T_2 V_36 ;
F_12 ( & V_6 -> V_24 , V_21 ) ;
V_36 = F_6 ( V_4 ) | V_33 ;
V_36 &= ~ V_37 ;
if ( V_15 )
F_7 ( V_36 | V_31 , V_4 ) ;
else
F_7 ( V_36 & ~ V_31 , V_4 ) ;
F_13 ( & V_6 -> V_24 , V_21 ) ;
return 0 ;
}
static void F_18 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_40 ;
unsigned long V_21 ;
T_2 V_41 , V_42 , V_43 ;
F_12 ( & V_6 -> V_24 , V_21 ) ;
for ( V_40 = 0 ; V_40 < V_6 -> V_2 . V_22 ; V_40 ++ ) {
const char * V_44 ;
V_43 = V_6 -> V_9 -> V_10 [ V_40 ] * 16 ;
V_41 = F_6 ( V_6 -> V_11 + V_43 + V_14 ) ;
V_42 = F_6 ( V_6 -> V_11 + V_43 + V_30 ) ;
V_44 = F_19 ( V_2 , V_40 ) ;
if ( ! V_44 )
V_44 = L_1 ;
F_20 ( V_39 ,
L_2 ,
V_40 ,
V_44 ,
V_42 & V_34 ? L_3 : L_4 ,
V_42 & V_37 ? L_5 : L_6 ,
V_42 & V_31 ? L_7 : L_8 ,
V_6 -> V_9 -> V_10 [ V_40 ] , V_43 ,
V_41 & 0x7 ,
V_41 & V_17 ? L_9 : L_10 ,
V_41 & V_16 ? L_11 : L_10 ,
V_41 & V_18 ? L_12 : L_10 ) ;
}
F_13 ( & V_6 -> V_24 , V_21 ) ;
}
static int F_21 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_22 ( V_6 -> V_45 , V_3 ) ;
}
static void F_23 ( unsigned V_46 , struct V_47 * V_48 )
{
struct V_19 * V_49 = F_24 ( V_48 ) ;
struct V_5 * V_6 = F_25 ( V_49 ) ;
struct V_50 * V_2 = F_26 ( V_49 ) ;
T_2 V_51 , V_52 , V_53 ;
void T_1 * V_4 ;
T_2 V_54 ;
unsigned V_55 ;
int V_56 = 0 ;
for ( V_51 = 0 ; V_51 < V_6 -> V_2 . V_22 ; V_51 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_51 , V_8 ) ;
while ( ( V_54 = F_6 ( V_4 ) ) ) {
V_52 = F_27 ( V_54 ) ;
V_53 = F_28 ( V_52 ) ;
F_7 ( V_53 , V_4 ) ;
V_55 = F_29 ( V_6 -> V_45 , V_51 + V_52 ) ;
F_30 ( V_55 ) ;
if ( V_56 ++ > 32 ) {
F_31 ( & V_6 -> V_12 -> V_13 ,
L_13 ,
V_51 + V_52 ) ;
V_4 = F_1 ( & V_6 -> V_2 , V_51 + V_52 ,
V_14 ) ;
V_53 = F_6 ( V_4 ) ;
V_53 &= ~ ( V_17 | V_16 |
V_18 ) ;
F_7 ( V_53 , V_4 ) ;
V_53 = F_6 ( V_4 ) ;
break;
}
}
}
V_2 -> V_57 ( V_49 ) ;
}
static void F_32 ( struct V_19 * V_20 )
{
}
static void F_33 ( struct V_19 * V_20 )
{
}
static unsigned int F_34 ( struct V_19 * V_20 )
{
struct V_5 * V_6 = F_10 ( V_20 ) ;
if ( F_35 ( & V_6 -> V_2 , F_11 ( V_20 ) ) )
F_31 ( V_6 -> V_2 . V_13 ,
L_14 ,
F_11 ( V_20 ) ) ;
F_32 ( V_20 ) ;
return 0 ;
}
static void F_36 ( struct V_19 * V_20 )
{
struct V_5 * V_6 = F_10 ( V_20 ) ;
F_33 ( V_20 ) ;
F_37 ( & V_6 -> V_2 , F_11 ( V_20 ) ) ;
}
static void F_38 ( struct V_5 * V_6 )
{
void T_1 * V_4 ;
T_2 V_51 , V_15 ;
for ( V_51 = 0 ; V_51 < V_6 -> V_2 . V_22 ; V_51 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_51 , V_8 ) ;
F_7 ( 0xffffffff , V_4 ) ;
V_15 = F_6 ( V_4 ) ;
if ( V_15 )
F_31 ( & V_6 -> V_12 -> V_13 ,
L_15 ) ;
}
}
static int F_39 ( struct V_58 * V_20 , unsigned int V_55 ,
T_3 V_59 )
{
struct V_5 * V_6 = V_20 -> V_60 ;
F_40 ( V_55 , & V_61 , V_62 ,
L_16 ) ;
F_41 ( V_55 , V_6 ) ;
F_42 ( V_55 , V_63 ) ;
return 0 ;
}
static int F_43 ( struct V_64 * V_12 )
{
struct V_5 * V_6 ;
struct V_1 * V_65 ;
struct V_66 * V_67 , * V_68 ;
struct V_69 * V_13 = & V_12 -> V_13 ;
struct V_70 * V_71 ;
struct V_72 * V_9 ;
T_4 V_73 = F_44 ( V_13 ) ;
unsigned V_74 ;
int V_75 ;
if ( F_45 ( V_73 , & V_71 ) )
return - V_76 ;
V_6 = F_46 ( V_13 , sizeof( struct V_5 ) , V_77 ) ;
if ( ! V_6 ) {
F_31 ( & V_12 -> V_13 , L_17 ) ;
return - V_78 ;
}
for ( V_9 = V_79 ; V_9 -> V_80 ; V_9 ++ ) {
if ( ! strcmp ( V_71 -> V_81 . V_82 , V_9 -> V_80 ) ) {
V_6 -> V_2 . V_22 = V_9 -> V_83 ;
V_6 -> V_9 = V_9 ;
break;
}
}
if ( ! V_6 -> V_2 . V_22 || ! V_6 -> V_9 )
return - V_76 ;
V_6 -> V_12 = V_12 ;
F_47 ( V_12 , V_6 ) ;
V_67 = F_48 ( V_12 , V_84 , 0 ) ;
V_6 -> V_11 = F_49 ( V_13 , V_67 ) ;
if ( F_50 ( V_6 -> V_11 ) )
return F_51 ( V_6 -> V_11 ) ;
F_52 ( & V_6 -> V_24 ) ;
V_65 = & V_6 -> V_2 ;
V_65 -> V_44 = F_53 ( & V_12 -> V_13 ) ;
V_65 -> V_85 = V_86 ;
V_65 -> V_87 = F_3 ;
V_65 -> free = F_5 ;
V_65 -> V_88 = F_16 ;
V_65 -> V_89 = F_17 ;
V_65 -> V_90 = F_14 ;
V_65 -> V_91 = F_15 ;
V_65 -> V_92 = F_18 ;
V_65 -> V_51 = - 1 ;
V_65 -> V_93 = false ;
V_65 -> V_13 = V_13 ;
V_75 = F_54 ( V_65 ) ;
if ( V_75 ) {
F_31 ( & V_12 -> V_13 , L_18 ) ;
return V_75 ;
}
V_68 = F_48 ( V_12 , V_94 , 0 ) ;
if ( V_68 && V_68 -> V_95 ) {
V_74 = V_68 -> V_95 ;
V_65 -> V_96 = F_21 ;
V_6 -> V_45 = F_55 ( NULL , V_65 -> V_22 ,
& V_97 , V_6 ) ;
if ( ! V_6 -> V_45 )
return - V_98 ;
F_38 ( V_6 ) ;
F_56 ( V_74 , V_6 ) ;
F_57 ( V_74 , F_23 ) ;
}
F_58 ( V_13 ) ;
return 0 ;
}
static int F_59 ( struct V_69 * V_13 )
{
return 0 ;
}
static int F_60 ( struct V_69 * V_13 )
{
return 0 ;
}
static int F_61 ( struct V_64 * V_12 )
{
struct V_5 * V_6 = F_62 ( V_12 ) ;
int V_99 ;
F_63 ( & V_12 -> V_13 ) ;
V_99 = F_64 ( & V_6 -> V_2 ) ;
if ( V_99 )
F_65 ( & V_12 -> V_13 , L_19 ) ;
return 0 ;
}
static int T_5 F_66 ( void )
{
return F_67 ( & V_100 ) ;
}
