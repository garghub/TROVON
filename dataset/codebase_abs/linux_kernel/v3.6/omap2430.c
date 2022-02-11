static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_2 = ( void * ) V_1 ;
unsigned long V_3 ;
T_1 V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_3 ) ;
switch ( V_2 -> V_7 -> V_8 ) {
case V_9 :
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_5 & V_12 ) {
V_2 -> V_7 -> V_8 = V_13 ;
F_4 ( V_2 ) ;
} else {
V_2 -> V_7 -> V_8 = V_14 ;
F_5 ( V_2 ) ;
}
break;
case V_15 :
if ( V_2 -> V_16 & V_17 ) {
V_4 = F_3 ( V_2 -> V_10 , V_18 ) ;
V_4 &= ~ V_19 ;
F_6 ( V_2 -> V_20 , L_1 , V_4 ) ;
F_7 ( V_2 -> V_10 , V_18 , V_4 ) ;
V_2 -> V_21 = 1 ;
V_2 -> V_16 &= ~ ( V_22
| V_17 ) ;
V_2 -> V_16 |= V_23 << 16 ;
F_8 ( F_9 ( V_2 ) ) ;
V_2 -> V_7 -> V_8 = V_24 ;
}
break;
case V_24 :
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_5 & V_12 )
V_2 -> V_7 -> V_8 = V_13 ;
else
V_2 -> V_7 -> V_8 = V_9 ;
default:
break;
}
F_10 ( & V_2 -> V_6 , V_3 ) ;
}
static void F_11 ( struct V_2 * V_2 , unsigned long V_25 )
{
unsigned long V_26 = V_27 + F_12 ( 3 ) ;
static unsigned long V_28 ;
if ( V_25 == 0 )
V_25 = V_26 ;
if ( V_2 -> V_21 || ( ( V_2 -> V_29 == 0 )
&& ( V_2 -> V_7 -> V_8 == V_9 ) ) ) {
F_6 ( V_2 -> V_20 , L_2 ,
F_13 ( V_2 -> V_7 -> V_8 ) ) ;
F_14 ( & V_30 ) ;
V_28 = V_27 ;
return;
}
if ( F_15 ( V_28 , V_25 ) ) {
if ( ! F_16 ( & V_30 ) )
V_28 = V_25 ;
else {
F_6 ( V_2 -> V_20 , L_3 ) ;
return;
}
}
V_28 = V_25 ;
F_6 ( V_2 -> V_20 , L_4 ,
F_13 ( V_2 -> V_7 -> V_8 ) ,
( unsigned long ) F_17 ( V_25 - V_27 ) ) ;
F_18 ( & V_30 , V_25 ) ;
}
static void F_19 ( struct V_2 * V_2 , int V_31 )
{
struct V_32 * V_33 = V_2 -> V_7 -> V_33 ;
T_1 V_5 ;
unsigned long V_25 = V_27 + F_12 ( 1000 ) ;
int V_34 = 1 ;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_31 ) {
if ( V_2 -> V_7 -> V_8 == V_14 ) {
V_5 |= V_35 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) & 0x80 ) {
F_20 () ;
if ( F_15 ( V_27 , V_25 ) ) {
F_21 ( V_2 -> V_20 ,
L_5 ) ;
V_34 = - V_36 ;
break;
}
}
if ( V_34 && V_33 -> V_37 )
F_22 ( V_33 , 1 ) ;
} else {
V_2 -> V_21 = 1 ;
V_33 -> V_38 = 1 ;
V_2 -> V_7 -> V_8 = V_39 ;
V_5 |= V_35 ;
F_5 ( V_2 ) ;
}
} else {
V_2 -> V_21 = 0 ;
V_33 -> V_38 = 0 ;
V_2 -> V_7 -> V_8 = V_13 ;
V_5 &= ~ V_35 ;
F_4 ( V_2 ) ;
}
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
F_6 ( V_2 -> V_20 , L_6
L_7 ,
F_13 ( V_2 -> V_7 -> V_8 ) ,
F_3 ( V_2 -> V_10 , V_11 ) ) ;
}
static int F_23 ( struct V_2 * V_2 , T_1 V_40 )
{
T_1 V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_35 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
return 0 ;
}
static inline void F_24 ( struct V_2 * V_2 )
{
T_2 V_41 ;
V_41 = F_25 ( V_2 -> V_10 , V_42 ) ;
V_41 |= V_43 ;
F_26 ( V_2 -> V_10 , V_42 , V_41 ) ;
}
static inline void F_27 ( struct V_2 * V_2 )
{
T_2 V_41 ;
V_41 = F_25 ( V_2 -> V_10 , V_42 ) ;
V_41 &= ~ V_43 ;
F_26 ( V_2 -> V_10 , V_42 , V_41 ) ;
}
void F_28 ( enum V_44 V_45 )
{
struct V_46 * V_47 = V_48 ;
struct V_2 * V_2 = F_29 ( V_47 ) ;
V_47 -> V_45 = V_45 ;
if ( ! V_2 ) {
F_21 ( V_47 -> V_49 , L_8 ) ;
return;
}
F_30 ( & V_47 -> V_50 ) ;
}
static void F_31 ( struct V_46 * V_47 )
{
struct V_2 * V_2 = F_29 ( V_47 ) ;
struct V_51 * V_49 = V_2 -> V_20 ;
struct V_52 * V_53 = V_49 -> V_54 ;
struct V_55 * V_56 = V_53 -> V_57 ;
struct V_32 * V_33 = V_2 -> V_7 -> V_33 ;
switch ( V_47 -> V_45 ) {
case V_58 :
F_6 ( V_49 , L_9 ) ;
V_33 -> V_38 = true ;
V_2 -> V_7 -> V_8 = V_14 ;
V_2 -> V_7 -> V_59 = V_60 ;
if ( ! F_32 ( V_2 ) || V_2 -> V_61 ) {
F_33 ( V_49 ) ;
F_34 ( V_2 -> V_7 ) ;
F_19 ( V_2 , 1 ) ;
}
break;
case V_62 :
F_6 ( V_49 , L_10 ) ;
V_33 -> V_38 = false ;
V_2 -> V_7 -> V_8 = V_13 ;
V_2 -> V_7 -> V_59 = V_63 ;
if ( V_2 -> V_61 )
F_33 ( V_49 ) ;
F_34 ( V_2 -> V_7 ) ;
break;
case V_64 :
case V_65 :
F_6 ( V_49 , L_11 ) ;
V_2 -> V_7 -> V_59 = V_66 ;
if ( F_32 ( V_2 ) || F_35 ( V_2 ) )
if ( V_2 -> V_61 ) {
F_36 ( V_49 ) ;
F_37 ( V_49 ) ;
}
if ( V_56 -> V_67 == V_68 ) {
if ( V_2 -> V_7 -> V_33 -> V_37 )
F_22 ( V_2 -> V_7 -> V_33 , 0 ) ;
}
F_38 ( V_2 -> V_7 ) ;
break;
default:
F_6 ( V_49 , L_12 ) ;
}
}
static void V_50 ( struct V_69 * V_70 )
{
struct V_46 * V_47 = F_39 ( V_70 ,
struct V_46 , V_50 ) ;
F_31 ( V_47 ) ;
}
static int F_40 ( struct V_2 * V_2 )
{
T_2 V_41 ;
int V_45 = 0 ;
struct V_51 * V_49 = V_2 -> V_20 ;
struct V_46 * V_47 = F_41 ( V_49 -> V_71 ) ;
struct V_52 * V_72 = V_49 -> V_54 ;
struct V_55 * V_56 = V_72 -> V_57 ;
V_2 -> V_7 = F_42 ( V_49 , V_73 ) ;
if ( F_43 ( V_2 -> V_7 ) ) {
F_44 ( L_13 ) ;
return - V_74 ;
}
V_45 = F_33 ( V_49 ) ;
if ( V_45 < 0 ) {
F_21 ( V_49 , L_14 , V_45 ) ;
goto V_75;
}
V_41 = F_25 ( V_2 -> V_10 , V_76 ) ;
if ( V_56 -> V_67 == V_68 ) {
V_41 &= ~ V_77 ;
V_41 |= V_78 ;
} else {
V_41 |= V_77 ;
}
F_26 ( V_2 -> V_10 , V_76 , V_41 ) ;
F_45 ( L_15
L_16 ,
F_25 ( V_2 -> V_10 , V_79 ) ,
F_25 ( V_2 -> V_10 , V_80 ) ,
F_25 ( V_2 -> V_10 , V_81 ) ,
F_25 ( V_2 -> V_10 , V_76 ) ,
F_25 ( V_2 -> V_10 , V_82 ) ) ;
F_46 ( & V_30 , F_1 , ( unsigned long ) V_2 ) ;
if ( V_47 -> V_45 != V_83 )
F_31 ( V_47 ) ;
F_47 ( V_2 -> V_20 ) ;
return 0 ;
V_75:
return V_45 ;
}
static void F_48 ( struct V_2 * V_2 )
{
T_1 V_5 ;
unsigned long V_25 = V_27 + F_12 ( 1000 ) ;
struct V_51 * V_49 = V_2 -> V_20 ;
struct V_46 * V_47 = F_41 ( V_49 -> V_71 ) ;
struct V_52 * V_53 = V_49 -> V_54 ;
struct V_55 * V_56 = V_53 -> V_57 ;
switch ( V_47 -> V_45 ) {
case V_58 :
F_34 ( V_2 -> V_7 ) ;
if ( V_56 -> V_67 != V_68 )
break;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_35 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) &
V_12 ) {
F_20 () ;
if ( F_15 ( V_27 , V_25 ) ) {
F_21 ( V_49 , L_5 ) ;
break;
}
}
break;
case V_62 :
F_34 ( V_2 -> V_7 ) ;
break;
default:
break;
}
}
static void F_49 ( struct V_2 * V_2 )
{
struct V_51 * V_49 = V_2 -> V_20 ;
struct V_46 * V_47 = F_41 ( V_49 -> V_71 ) ;
if ( V_47 -> V_45 != V_83 )
F_38 ( V_2 -> V_7 ) ;
}
static int F_50 ( struct V_2 * V_2 )
{
F_51 ( & V_30 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int T_3 F_52 ( struct V_84 * V_85 )
{
struct V_52 * V_53 = V_85 -> V_49 . V_54 ;
struct V_84 * V_2 ;
struct V_46 * V_47 ;
int V_34 = - V_86 ;
V_47 = F_53 ( & V_85 -> V_49 , sizeof( * V_47 ) , V_87 ) ;
if ( ! V_47 ) {
F_21 ( & V_85 -> V_49 , L_17 ) ;
goto V_88;
}
V_2 = F_54 ( L_18 , - 1 ) ;
if ( ! V_2 ) {
F_21 ( & V_85 -> V_49 , L_19 ) ;
goto V_88;
}
V_2 -> V_49 . V_71 = & V_85 -> V_49 ;
V_2 -> V_49 . V_89 = & V_90 ;
V_2 -> V_49 . V_91 = V_90 ;
V_47 -> V_49 = & V_85 -> V_49 ;
V_47 -> V_2 = V_2 ;
V_47 -> V_45 = V_83 ;
V_53 -> V_92 = & V_93 ;
F_55 ( V_85 , V_47 ) ;
V_48 = V_47 ;
F_56 ( & V_47 -> V_50 , V_50 ) ;
V_34 = F_57 ( V_2 , V_85 -> V_94 ,
V_85 -> V_95 ) ;
if ( V_34 ) {
F_21 ( & V_85 -> V_49 , L_20 ) ;
goto V_75;
}
V_34 = F_58 ( V_2 , V_53 , sizeof( * V_53 ) ) ;
if ( V_34 ) {
F_21 ( & V_85 -> V_49 , L_21 ) ;
goto V_75;
}
F_59 ( & V_85 -> V_49 ) ;
V_34 = F_60 ( V_2 ) ;
if ( V_34 ) {
F_21 ( & V_85 -> V_49 , L_22 ) ;
goto V_75;
}
return 0 ;
V_75:
F_61 ( V_2 ) ;
V_88:
return V_34 ;
}
static int T_4 F_62 ( struct V_84 * V_85 )
{
struct V_46 * V_47 = F_63 ( V_85 ) ;
F_64 ( & V_47 -> V_50 ) ;
F_65 ( V_47 -> V_2 ) ;
F_61 ( V_47 -> V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_51 * V_49 )
{
struct V_46 * V_47 = F_41 ( V_49 ) ;
struct V_2 * V_2 = F_29 ( V_47 ) ;
if ( V_2 ) {
V_2 -> V_96 . V_97 = F_25 ( V_2 -> V_10 ,
V_76 ) ;
F_24 ( V_2 ) ;
F_67 ( V_2 -> V_7 , 1 ) ;
}
return 0 ;
}
static int F_68 ( struct V_51 * V_49 )
{
struct V_46 * V_47 = F_41 ( V_49 ) ;
struct V_2 * V_2 = F_29 ( V_47 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
F_26 ( V_2 -> V_10 , V_76 ,
V_2 -> V_96 . V_97 ) ;
F_67 ( V_2 -> V_7 , 0 ) ;
}
return 0 ;
}
static int T_5 F_69 ( void )
{
return F_70 ( & V_98 ) ;
}
static void T_6 F_71 ( void )
{
F_72 ( & V_98 ) ;
}
