static void T_1 * F_1 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
T_2 V_7 ;
void T_1 * V_8 ;
if ( V_4 == V_9 )
V_7 = ( V_3 / 32 ) * 4 ;
else
V_7 = V_6 -> V_10 -> V_11 [ V_3 ] * 16 ;
V_8 = ( void T_1 * ) ( V_6 -> V_12 + V_7 + V_4 ) ;
return V_8 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
F_4 ( & V_6 -> V_13 -> V_14 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
void T_1 * V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_15 ) ;
T_2 V_16 ;
V_16 = F_6 ( V_4 ) ;
V_16 &= ~ ( V_17 | V_18 | V_19 ) ;
F_7 ( V_16 , V_4 ) ;
F_8 ( & V_6 -> V_13 -> V_14 ) ;
}
static int F_9 ( struct V_20 * V_21 , unsigned type )
{
struct V_5 * V_6 = F_10 ( V_21 ) ;
T_2 V_3 = F_11 ( V_21 ) ;
T_2 V_16 ;
unsigned long V_22 ;
void T_1 * V_4 = F_1 ( & V_6 -> V_2 , V_3 , V_15 ) ;
if ( V_3 >= V_6 -> V_2 . V_23 )
return - V_24 ;
F_12 ( & V_6 -> V_25 , V_22 ) ;
V_16 = F_6 ( V_4 ) ;
V_16 &= ~ ( V_17 | V_18 | V_19 ) ;
switch ( type ) {
case V_26 :
V_16 |= V_19 ;
case V_27 :
V_16 |= V_17 ;
break;
case V_28 :
V_16 |= V_19 ;
case V_29 :
V_16 |= V_18 ;
break;
case V_30 :
V_16 |= ( V_18 | V_17 ) ;
break;
}
F_7 ( V_16 , V_4 ) ;
F_13 ( & V_6 -> V_25 , V_22 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_31 ) ;
return F_6 ( V_4 ) & V_32 ;
}
static void F_15 ( struct V_1 * V_2 , unsigned V_3 , int V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_31 ) ;
unsigned long V_22 ;
T_2 V_33 ;
F_12 ( & V_6 -> V_25 , V_22 ) ;
V_33 = F_6 ( V_4 ) ;
if ( V_16 )
F_7 ( V_33 | V_32 , V_4 ) ;
else
F_7 ( V_33 & ~ V_32 , V_4 ) ;
F_13 ( & V_6 -> V_25 , V_22 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_3 , V_31 ) ;
unsigned long V_22 ;
T_2 V_16 ;
F_12 ( & V_6 -> V_25 , V_22 ) ;
V_16 = F_6 ( V_4 ) | V_34 ;
V_16 = V_16 & ( ~ V_35 ) ;
F_7 ( V_16 , V_4 ) ;
F_13 ( & V_6 -> V_25 , V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_36 , int V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
void T_1 * V_4 = F_1 ( V_2 , V_36 , V_31 ) ;
unsigned long V_22 ;
T_2 V_37 ;
F_12 ( & V_6 -> V_25 , V_22 ) ;
V_37 = F_6 ( V_4 ) | ( V_34 | ! ! V_16 ) ;
V_37 &= ~ ( V_38 | ! V_16 ) ;
F_7 ( V_37 , V_4 ) ;
F_13 ( & V_6 -> V_25 , V_22 ) ;
return 0 ;
}
static void F_18 ( struct V_39 * V_40 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
int V_41 ;
unsigned long V_22 ;
T_2 V_42 , V_43 , V_44 ;
F_12 ( & V_6 -> V_25 , V_22 ) ;
for ( V_41 = 0 ; V_41 < V_6 -> V_2 . V_23 ; V_41 ++ ) {
V_44 = V_6 -> V_10 -> V_11 [ V_41 ] * 16 ;
V_42 = F_6 ( V_6 -> V_12 + V_44 + V_15 ) ;
V_43 = F_6 ( V_6 -> V_12 + V_44 + V_31 ) ;
F_19 ( V_40 ,
L_1 ,
V_41 ,
V_43 & V_35 ? L_2 : L_3 ,
V_43 & V_38 ? L_4 : L_5 ,
V_43 & V_32 ? L_6 : L_7 ,
V_6 -> V_10 -> V_11 [ V_41 ] , V_44 ,
V_42 & 0x7 ,
V_42 & V_18 ? L_8 : L_9 ,
V_42 & V_17 ? L_10 : L_9 ,
V_42 & V_19 ? L_11 : L_9 ) ;
}
F_13 ( & V_6 -> V_25 , V_22 ) ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
return F_21 ( V_6 -> V_45 , V_3 ) ;
}
static void F_22 ( unsigned V_46 , struct V_47 * V_48 )
{
struct V_20 * V_49 = F_23 ( V_48 ) ;
struct V_5 * V_6 = F_24 ( V_49 ) ;
struct V_50 * V_2 = F_25 ( V_49 ) ;
T_2 V_51 , V_52 , V_53 ;
void T_1 * V_4 ;
T_2 V_54 ;
unsigned V_55 ;
int V_56 = 0 ;
for ( V_51 = 0 ; V_51 < V_6 -> V_2 . V_23 ; V_51 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_51 , V_9 ) ;
while ( ( V_54 = F_6 ( V_4 ) ) ) {
V_52 = F_26 ( V_54 ) ;
V_53 = F_27 ( V_52 ) ;
F_7 ( V_53 , V_4 ) ;
V_55 = F_28 ( V_6 -> V_45 , V_51 + V_52 ) ;
F_29 ( V_55 ) ;
if ( V_56 ++ > 32 ) {
F_30 ( & V_6 -> V_13 -> V_14 ,
L_12 ,
V_51 + V_52 ) ;
V_4 = F_1 ( & V_6 -> V_2 , V_51 + V_52 ,
V_15 ) ;
V_53 = F_6 ( V_4 ) ;
V_53 &= ~ ( V_18 | V_17 |
V_19 ) ;
F_7 ( V_53 , V_4 ) ;
V_53 = F_6 ( V_4 ) ;
break;
}
}
}
V_2 -> V_57 ( V_49 ) ;
}
static void F_31 ( struct V_20 * V_21 )
{
}
static void F_32 ( struct V_20 * V_21 )
{
}
static void F_33 ( struct V_5 * V_6 )
{
void T_1 * V_4 ;
T_2 V_51 , V_16 ;
for ( V_51 = 0 ; V_51 < V_6 -> V_2 . V_23 ; V_51 += 32 ) {
V_4 = F_1 ( & V_6 -> V_2 , V_51 , V_9 ) ;
F_7 ( 0xffffffff , V_4 ) ;
V_16 = F_6 ( V_4 ) ;
if ( V_16 )
F_30 ( & V_6 -> V_13 -> V_14 ,
L_13 ) ;
}
}
static int F_34 ( struct V_58 * V_21 , unsigned int V_55 ,
T_3 V_59 )
{
struct V_5 * V_6 = V_21 -> V_60 ;
F_35 ( V_55 , & V_61 , V_62 ,
L_14 ) ;
F_36 ( V_55 , V_6 ) ;
F_37 ( V_55 , V_63 ) ;
return 0 ;
}
static int F_38 ( struct V_64 * V_13 )
{
struct V_5 * V_6 ;
struct V_1 * V_65 ;
struct V_66 * V_67 , * V_68 ;
struct V_69 * V_14 = & V_13 -> V_14 ;
struct V_70 * V_71 ;
struct V_72 * V_10 ;
T_4 V_73 = F_39 ( V_14 ) ;
unsigned V_74 ;
int V_75 ;
if ( F_40 ( V_73 , & V_71 ) )
return - V_76 ;
V_6 = F_41 ( V_14 , sizeof( struct V_5 ) , V_77 ) ;
if ( ! V_6 ) {
F_30 ( & V_13 -> V_14 , L_15 ) ;
return - V_78 ;
}
for ( V_10 = V_79 ; V_10 -> V_80 ; V_10 ++ ) {
if ( ! strcmp ( V_71 -> V_81 . V_82 , V_10 -> V_80 ) ) {
V_6 -> V_2 . V_23 = V_10 -> V_83 ;
V_6 -> V_10 = V_10 ;
break;
}
}
if ( ! V_6 -> V_2 . V_23 || ! V_6 -> V_10 )
return - V_76 ;
V_6 -> V_13 = V_13 ;
F_42 ( V_13 , V_6 ) ;
V_67 = F_43 ( V_13 , V_84 , 0 ) ;
V_6 -> V_12 = F_44 ( V_14 , V_67 ) ;
if ( F_45 ( V_6 -> V_12 ) )
return F_46 ( V_6 -> V_12 ) ;
F_47 ( & V_6 -> V_25 ) ;
V_65 = & V_6 -> V_2 ;
V_65 -> V_85 = F_48 ( & V_13 -> V_14 ) ;
V_65 -> V_86 = V_87 ;
V_65 -> V_88 = F_3 ;
V_65 -> free = F_5 ;
V_65 -> V_89 = F_16 ;
V_65 -> V_90 = F_17 ;
V_65 -> V_91 = F_14 ;
V_65 -> V_92 = F_15 ;
V_65 -> V_93 = F_18 ;
V_65 -> V_51 = - 1 ;
V_65 -> V_94 = 0 ;
V_65 -> V_14 = V_14 ;
V_75 = F_49 ( V_65 ) ;
if ( V_75 ) {
F_30 ( & V_13 -> V_14 , L_16 ) ;
return V_75 ;
}
V_68 = F_43 ( V_13 , V_95 , 0 ) ;
if ( V_68 && V_68 -> V_96 ) {
V_74 = V_68 -> V_96 ;
V_65 -> V_97 = F_20 ;
V_6 -> V_45 = F_50 ( NULL , V_65 -> V_23 ,
& V_98 , V_6 ) ;
if ( ! V_6 -> V_45 )
return - V_99 ;
F_33 ( V_6 ) ;
F_51 ( V_74 , V_6 ) ;
F_52 ( V_74 , F_22 ) ;
F_53 ( V_65 ) ;
}
F_54 ( V_14 ) ;
return 0 ;
}
static int F_55 ( struct V_69 * V_14 )
{
return 0 ;
}
static int F_56 ( struct V_69 * V_14 )
{
return 0 ;
}
static int F_57 ( struct V_64 * V_13 )
{
struct V_5 * V_6 = F_58 ( V_13 ) ;
int V_100 ;
F_59 ( & V_13 -> V_14 ) ;
V_100 = F_60 ( & V_6 -> V_2 ) ;
if ( V_100 )
F_61 ( & V_13 -> V_14 , L_17 ) ;
return 0 ;
}
static int T_5 F_62 ( void )
{
return F_63 ( & V_101 ) ;
}
