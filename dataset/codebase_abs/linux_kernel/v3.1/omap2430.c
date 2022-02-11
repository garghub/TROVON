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
T_1 V_5 ;
unsigned long V_25 = V_27 + F_12 ( 1000 ) ;
int V_32 = 1 ;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_31 ) {
if ( V_2 -> V_7 -> V_8 == V_14 ) {
V_5 |= V_33 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) & 0x80 ) {
F_20 () ;
if ( F_15 ( V_27 , V_25 ) ) {
F_21 ( V_2 -> V_20 ,
L_5 ) ;
V_32 = - V_34 ;
break;
}
}
if ( V_32 && V_2 -> V_7 -> V_35 )
F_22 ( V_2 -> V_7 , 1 ) ;
} else {
V_2 -> V_21 = 1 ;
V_2 -> V_7 -> V_36 = 1 ;
V_2 -> V_7 -> V_8 = V_37 ;
V_5 |= V_33 ;
F_5 ( V_2 ) ;
}
} else {
V_2 -> V_21 = 0 ;
V_2 -> V_7 -> V_36 = 0 ;
V_2 -> V_7 -> V_8 = V_13 ;
V_5 &= ~ V_33 ;
F_4 ( V_2 ) ;
}
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
F_6 ( V_2 -> V_20 , L_6
L_7 ,
F_13 ( V_2 -> V_7 -> V_8 ) ,
F_3 ( V_2 -> V_10 , V_11 ) ) ;
}
static int F_23 ( struct V_2 * V_2 , T_1 V_38 )
{
T_1 V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_33 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
return 0 ;
}
static inline void F_24 ( struct V_2 * V_2 )
{
T_2 V_39 ;
V_39 = F_25 ( V_2 -> V_10 , V_40 ) ;
V_39 |= V_41 ;
F_26 ( V_2 -> V_10 , V_40 , V_39 ) ;
}
static inline void F_27 ( struct V_2 * V_2 )
{
T_2 V_39 ;
V_39 = F_25 ( V_2 -> V_10 , V_40 ) ;
V_39 &= ~ V_41 ;
F_26 ( V_2 -> V_10 , V_40 , V_39 ) ;
}
static int F_28 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
struct V_2 * V_2 = F_29 ( V_43 , struct V_2 , V_43 ) ;
struct V_46 * V_47 = V_2 -> V_20 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_51 * V_52 = V_49 -> V_53 ;
switch ( V_44 ) {
case V_54 :
F_6 ( V_2 -> V_20 , L_8 ) ;
if ( F_30 ( V_2 ) ) {
if ( V_2 -> V_55 ) {
F_31 ( V_2 -> V_20 ) ;
F_32 ( V_2 -> V_7 ) ;
F_19 ( V_2 , 1 ) ;
}
} else {
F_31 ( V_2 -> V_20 ) ;
F_32 ( V_2 -> V_7 ) ;
F_19 ( V_2 , 1 ) ;
}
break;
case V_56 :
F_6 ( V_2 -> V_20 , L_9 ) ;
if ( V_2 -> V_55 )
F_31 ( V_2 -> V_20 ) ;
F_32 ( V_2 -> V_7 ) ;
break;
case V_57 :
F_6 ( V_2 -> V_20 , L_10 ) ;
if ( F_30 ( V_2 ) || F_33 ( V_2 ) )
if ( V_2 -> V_55 ) {
F_34 ( V_2 -> V_20 ) ;
F_35 ( V_2 -> V_20 ) ;
}
if ( V_52 -> V_58 == V_59 ) {
if ( V_2 -> V_7 -> V_35 )
F_22 ( V_2 -> V_7 , 0 ) ;
}
F_36 ( V_2 -> V_7 ) ;
break;
default:
F_6 ( V_2 -> V_20 , L_11 ) ;
return V_60 ;
}
return V_61 ;
}
static int F_37 ( struct V_2 * V_2 )
{
T_2 V_39 , V_62 = 0 ;
struct V_46 * V_47 = V_2 -> V_20 ;
struct V_48 * V_63 = V_47 -> V_50 ;
struct V_51 * V_52 = V_63 -> V_53 ;
V_2 -> V_7 = F_38 () ;
if ( ! V_2 -> V_7 ) {
F_39 ( L_12 ) ;
return - V_64 ;
}
V_62 = F_31 ( V_47 ) ;
if ( V_62 < 0 ) {
F_21 ( V_47 , L_13 ) ;
goto V_65;
}
V_39 = F_25 ( V_2 -> V_10 , V_66 ) ;
if ( V_52 -> V_58 == V_59 ) {
V_39 &= ~ V_67 ;
V_39 |= V_68 ;
} else {
V_39 |= V_67 ;
}
F_26 ( V_2 -> V_10 , V_66 , V_39 ) ;
F_40 ( L_14
L_15 ,
F_25 ( V_2 -> V_10 , V_69 ) ,
F_25 ( V_2 -> V_10 , V_70 ) ,
F_25 ( V_2 -> V_10 , V_71 ) ,
F_25 ( V_2 -> V_10 , V_66 ) ,
F_25 ( V_2 -> V_10 , V_72 ) ) ;
V_2 -> V_43 . V_73 = F_28 ;
V_62 = F_41 ( V_2 -> V_7 , & V_2 -> V_43 ) ;
if ( V_62 )
F_6 ( V_2 -> V_20 , L_16 ) ;
F_42 ( & V_30 , F_1 , ( unsigned long ) V_2 ) ;
return 0 ;
V_65:
F_43 ( V_47 ) ;
return V_62 ;
}
static void F_44 ( struct V_2 * V_2 )
{
T_1 V_5 ;
unsigned long V_25 = V_27 + F_12 ( 1000 ) ;
struct V_46 * V_47 = V_2 -> V_20 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_51 * V_52 = V_49 -> V_53 ;
switch ( V_2 -> V_7 -> V_74 ) {
case V_54 :
F_32 ( V_2 -> V_7 ) ;
if ( V_52 -> V_58 == V_59 ) {
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_33 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) &
V_12 ) {
F_20 () ;
if ( F_15 ( V_27 , V_25 ) ) {
F_21 ( V_2 -> V_20 ,
L_5 ) ;
break;
}
}
}
break;
case V_56 :
F_32 ( V_2 -> V_7 ) ;
break;
default:
break;
}
}
static void F_45 ( struct V_2 * V_2 )
{
if ( V_2 -> V_7 -> V_74 )
F_36 ( V_2 -> V_7 ) ;
}
static int F_46 ( struct V_2 * V_2 )
{
F_47 ( & V_30 ) ;
F_24 ( V_2 ) ;
F_48 ( V_2 -> V_7 ) ;
return 0 ;
}
static int T_3 F_49 ( struct V_75 * V_76 )
{
struct V_48 * V_49 = V_76 -> V_47 . V_50 ;
struct V_75 * V_2 ;
struct V_77 * V_78 ;
int V_32 = - V_79 ;
V_78 = F_50 ( sizeof( * V_78 ) , V_80 ) ;
if ( ! V_78 ) {
F_21 ( & V_76 -> V_47 , L_17 ) ;
goto V_81;
}
V_2 = F_51 ( L_18 , - 1 ) ;
if ( ! V_2 ) {
F_21 ( & V_76 -> V_47 , L_19 ) ;
goto V_65;
}
V_2 -> V_47 . V_82 = & V_76 -> V_47 ;
V_2 -> V_47 . V_83 = & V_84 ;
V_2 -> V_47 . V_85 = V_84 ;
V_78 -> V_47 = & V_76 -> V_47 ;
V_78 -> V_2 = V_2 ;
V_49 -> V_86 = & V_87 ;
F_52 ( V_76 , V_78 ) ;
V_32 = F_53 ( V_2 , V_76 -> V_88 ,
V_76 -> V_89 ) ;
if ( V_32 ) {
F_21 ( & V_76 -> V_47 , L_20 ) ;
goto V_90;
}
V_32 = F_54 ( V_2 , V_49 , sizeof( * V_49 ) ) ;
if ( V_32 ) {
F_21 ( & V_76 -> V_47 , L_21 ) ;
goto V_90;
}
V_32 = F_55 ( V_2 ) ;
if ( V_32 ) {
F_21 ( & V_76 -> V_47 , L_22 ) ;
goto V_90;
}
F_56 ( & V_76 -> V_47 ) ;
return 0 ;
V_90:
F_57 ( V_2 ) ;
V_65:
F_58 ( V_78 ) ;
V_81:
return V_32 ;
}
static int T_4 F_59 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = F_60 ( V_76 ) ;
F_61 ( V_78 -> V_2 ) ;
F_57 ( V_78 -> V_2 ) ;
F_62 ( & V_76 -> V_47 ) ;
F_43 ( & V_76 -> V_47 ) ;
F_58 ( V_78 ) ;
return 0 ;
}
static int F_63 ( struct V_46 * V_47 )
{
struct V_77 * V_78 = F_64 ( V_47 ) ;
struct V_2 * V_2 = F_65 ( V_78 ) ;
F_24 ( V_2 ) ;
F_66 ( V_2 -> V_7 , 1 ) ;
return 0 ;
}
static int F_67 ( struct V_46 * V_47 )
{
struct V_77 * V_78 = F_64 ( V_47 ) ;
struct V_2 * V_2 = F_65 ( V_78 ) ;
F_27 ( V_2 ) ;
F_66 ( V_2 -> V_7 , 0 ) ;
return 0 ;
}
static int T_3 F_68 ( void )
{
return F_69 ( & V_91 , F_49 ) ;
}
static void T_4 F_70 ( void )
{
F_71 ( & V_91 ) ;
}
