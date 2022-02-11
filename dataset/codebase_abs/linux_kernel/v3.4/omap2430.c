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
static int F_28 ( struct V_44 * V_45 ,
unsigned long V_46 , void * V_47 )
{
struct V_2 * V_2 = F_29 ( V_45 , struct V_2 , V_45 ) ;
V_2 -> V_48 = V_46 ;
F_30 ( & V_2 -> V_49 ) ;
return V_50 ;
}
static void F_31 ( struct V_51 * V_52 )
{
struct V_2 * V_2 = F_29 ( V_52 , struct V_2 , V_49 ) ;
struct V_53 * V_54 = V_2 -> V_20 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 = V_56 -> V_60 ;
switch ( V_2 -> V_48 ) {
case V_61 :
F_6 ( V_2 -> V_20 , L_8 ) ;
if ( ! F_32 ( V_2 ) || V_2 -> V_62 ) {
F_33 ( V_2 -> V_20 ) ;
F_34 ( V_2 -> V_7 ) ;
F_19 ( V_2 , 1 ) ;
}
break;
case V_63 :
F_6 ( V_2 -> V_20 , L_9 ) ;
if ( V_2 -> V_62 )
F_33 ( V_2 -> V_20 ) ;
F_34 ( V_2 -> V_7 ) ;
break;
case V_64 :
F_6 ( V_2 -> V_20 , L_10 ) ;
if ( F_32 ( V_2 ) || F_35 ( V_2 ) )
if ( V_2 -> V_62 ) {
F_36 ( V_2 -> V_20 ) ;
F_37 ( V_2 -> V_20 ) ;
}
if ( V_59 -> V_65 == V_66 ) {
if ( V_2 -> V_7 -> V_33 -> V_37 )
F_22 ( V_2 -> V_7 -> V_33 , 0 ) ;
}
F_38 ( V_2 -> V_7 ) ;
break;
default:
F_6 ( V_2 -> V_20 , L_11 ) ;
}
}
static int F_39 ( struct V_2 * V_2 )
{
T_2 V_41 ;
int V_67 = 0 ;
struct V_53 * V_54 = V_2 -> V_20 ;
struct V_55 * V_68 = V_54 -> V_57 ;
struct V_58 * V_59 = V_68 -> V_60 ;
V_2 -> V_7 = F_40 () ;
if ( ! V_2 -> V_7 ) {
F_41 ( L_12 ) ;
return - V_69 ;
}
F_42 ( & V_2 -> V_49 , F_31 ) ;
V_67 = F_33 ( V_54 ) ;
if ( V_67 < 0 ) {
F_21 ( V_54 , L_13 , V_67 ) ;
goto V_70;
}
V_41 = F_25 ( V_2 -> V_10 , V_71 ) ;
if ( V_59 -> V_65 == V_66 ) {
V_41 &= ~ V_72 ;
V_41 |= V_73 ;
} else {
V_41 |= V_72 ;
}
F_26 ( V_2 -> V_10 , V_71 , V_41 ) ;
F_43 ( L_14
L_15 ,
F_25 ( V_2 -> V_10 , V_74 ) ,
F_25 ( V_2 -> V_10 , V_75 ) ,
F_25 ( V_2 -> V_10 , V_76 ) ,
F_25 ( V_2 -> V_10 , V_71 ) ,
F_25 ( V_2 -> V_10 , V_77 ) ) ;
V_2 -> V_45 . V_78 = F_28 ;
V_67 = F_44 ( V_2 -> V_7 , & V_2 -> V_45 ) ;
if ( V_67 )
F_6 ( V_2 -> V_20 , L_16 ) ;
F_45 ( & V_30 , F_1 , ( unsigned long ) V_2 ) ;
F_46 ( V_2 -> V_20 ) ;
return 0 ;
V_70:
return V_67 ;
}
static void F_47 ( struct V_2 * V_2 )
{
T_1 V_5 ;
unsigned long V_25 = V_27 + F_12 ( 1000 ) ;
struct V_53 * V_54 = V_2 -> V_20 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_58 * V_59 = V_56 -> V_60 ;
switch ( V_2 -> V_7 -> V_79 ) {
case V_61 :
F_34 ( V_2 -> V_7 ) ;
if ( V_59 -> V_65 != V_66 )
break;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_35 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) &
V_12 ) {
F_20 () ;
if ( F_15 ( V_27 , V_25 ) ) {
F_21 ( V_54 , L_5 ) ;
break;
}
}
break;
case V_63 :
F_34 ( V_2 -> V_7 ) ;
break;
default:
break;
}
}
static void F_48 ( struct V_2 * V_2 )
{
if ( V_2 -> V_7 -> V_79 )
F_38 ( V_2 -> V_7 ) ;
}
static int F_49 ( struct V_2 * V_2 )
{
F_50 ( & V_30 ) ;
F_51 ( & V_2 -> V_49 ) ;
F_24 ( V_2 ) ;
F_52 ( V_2 -> V_7 ) ;
return 0 ;
}
static int T_3 F_53 ( struct V_80 * V_81 )
{
struct V_55 * V_56 = V_81 -> V_54 . V_57 ;
struct V_80 * V_2 ;
struct V_82 * V_83 ;
int V_34 = - V_84 ;
V_83 = F_54 ( sizeof( * V_83 ) , V_85 ) ;
if ( ! V_83 ) {
F_21 ( & V_81 -> V_54 , L_17 ) ;
goto V_86;
}
V_2 = F_55 ( L_18 , - 1 ) ;
if ( ! V_2 ) {
F_21 ( & V_81 -> V_54 , L_19 ) ;
goto V_70;
}
V_2 -> V_54 . V_87 = & V_81 -> V_54 ;
V_2 -> V_54 . V_88 = & V_89 ;
V_2 -> V_54 . V_90 = V_89 ;
V_83 -> V_54 = & V_81 -> V_54 ;
V_83 -> V_2 = V_2 ;
V_56 -> V_91 = & V_92 ;
F_56 ( V_81 , V_83 ) ;
V_34 = F_57 ( V_2 , V_81 -> V_93 ,
V_81 -> V_94 ) ;
if ( V_34 ) {
F_21 ( & V_81 -> V_54 , L_20 ) ;
goto V_95;
}
V_34 = F_58 ( V_2 , V_56 , sizeof( * V_56 ) ) ;
if ( V_34 ) {
F_21 ( & V_81 -> V_54 , L_21 ) ;
goto V_95;
}
F_59 ( & V_81 -> V_54 ) ;
V_34 = F_60 ( V_2 ) ;
if ( V_34 ) {
F_21 ( & V_81 -> V_54 , L_22 ) ;
goto V_95;
}
return 0 ;
V_95:
F_61 ( V_2 ) ;
V_70:
F_62 ( V_83 ) ;
V_86:
return V_34 ;
}
static int T_4 F_63 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_64 ( V_81 ) ;
F_65 ( V_83 -> V_2 ) ;
F_61 ( V_83 -> V_2 ) ;
F_62 ( V_83 ) ;
return 0 ;
}
static int F_66 ( struct V_53 * V_54 )
{
struct V_82 * V_83 = F_67 ( V_54 ) ;
struct V_2 * V_2 = F_68 ( V_83 ) ;
if ( V_2 ) {
V_2 -> V_96 . V_97 = F_25 ( V_2 -> V_10 ,
V_71 ) ;
F_24 ( V_2 ) ;
F_69 ( V_2 -> V_7 , 1 ) ;
}
return 0 ;
}
static int F_70 ( struct V_53 * V_54 )
{
struct V_82 * V_83 = F_67 ( V_54 ) ;
struct V_2 * V_2 = F_68 ( V_83 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
F_26 ( V_2 -> V_10 , V_71 ,
V_2 -> V_96 . V_97 ) ;
F_69 ( V_2 -> V_7 , 0 ) ;
}
return 0 ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_98 ) ;
}
static void T_6 F_73 ( void )
{
F_74 ( & V_98 ) ;
}
