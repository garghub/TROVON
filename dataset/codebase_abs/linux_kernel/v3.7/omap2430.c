static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 )
F_2 ( V_3 , V_2 -> V_4 ) ;
}
static void F_3 ( unsigned long V_5 )
{
struct V_6 * V_6 = ( void * ) V_5 ;
unsigned long V_7 ;
T_2 V_8 ;
T_2 V_9 ;
F_4 ( & V_6 -> V_10 , V_7 ) ;
switch ( V_6 -> V_11 -> V_12 ) {
case V_13 :
V_9 = F_5 ( V_6 -> V_14 , V_15 ) ;
if ( V_9 & V_16 ) {
V_6 -> V_11 -> V_12 = V_17 ;
F_6 ( V_6 ) ;
} else {
V_6 -> V_11 -> V_12 = V_18 ;
F_7 ( V_6 ) ;
}
break;
case V_19 :
if ( V_6 -> V_20 & V_21 ) {
V_8 = F_5 ( V_6 -> V_14 , V_22 ) ;
V_8 &= ~ V_23 ;
F_8 ( V_6 -> V_24 , L_1 , V_8 ) ;
F_9 ( V_6 -> V_14 , V_22 , V_8 ) ;
V_6 -> V_25 = 1 ;
V_6 -> V_20 &= ~ ( V_26
| V_21 ) ;
V_6 -> V_20 |= V_27 << 16 ;
F_10 ( F_11 ( V_6 ) ) ;
V_6 -> V_11 -> V_12 = V_28 ;
}
break;
case V_28 :
V_9 = F_5 ( V_6 -> V_14 , V_15 ) ;
if ( V_9 & V_16 )
V_6 -> V_11 -> V_12 = V_17 ;
else
V_6 -> V_11 -> V_12 = V_13 ;
default:
break;
}
F_12 ( & V_6 -> V_10 , V_7 ) ;
}
static void F_13 ( struct V_6 * V_6 , unsigned long V_29 )
{
unsigned long V_30 = V_31 + F_14 ( 3 ) ;
static unsigned long V_32 ;
if ( V_29 == 0 )
V_29 = V_30 ;
if ( V_6 -> V_25 || ( ( V_6 -> V_33 == 0 )
&& ( V_6 -> V_11 -> V_12 == V_13 ) ) ) {
F_8 ( V_6 -> V_24 , L_2 ,
F_15 ( V_6 -> V_11 -> V_12 ) ) ;
F_16 ( & V_34 ) ;
V_32 = V_31 ;
return;
}
if ( F_17 ( V_32 , V_29 ) ) {
if ( ! F_18 ( & V_34 ) )
V_32 = V_29 ;
else {
F_8 ( V_6 -> V_24 , L_3 ) ;
return;
}
}
V_32 = V_29 ;
F_8 ( V_6 -> V_24 , L_4 ,
F_15 ( V_6 -> V_11 -> V_12 ) ,
( unsigned long ) F_19 ( V_29 - V_31 ) ) ;
F_20 ( & V_34 , V_29 ) ;
}
static void F_21 ( struct V_6 * V_6 , int V_35 )
{
struct V_36 * V_37 = V_6 -> V_11 -> V_37 ;
T_2 V_9 ;
unsigned long V_29 = V_31 + F_14 ( 1000 ) ;
V_9 = F_5 ( V_6 -> V_14 , V_15 ) ;
if ( V_35 ) {
if ( V_6 -> V_11 -> V_12 == V_18 ) {
int V_38 = 100 ;
V_9 |= V_39 ;
F_9 ( V_6 -> V_14 , V_15 , V_9 ) ;
while ( F_5 ( V_6 -> V_14 , V_15 ) & 0x80 ) {
F_22 ( 5 ) ;
F_23 () ;
if ( F_17 ( V_31 , V_29 )
|| V_38 -- <= 0 ) {
F_24 ( V_6 -> V_24 ,
L_5 ) ;
break;
}
}
if ( V_37 -> V_40 )
F_25 ( V_37 , 1 ) ;
} else {
V_6 -> V_25 = 1 ;
V_37 -> V_41 = 1 ;
V_6 -> V_11 -> V_12 = V_42 ;
V_9 |= V_39 ;
F_7 ( V_6 ) ;
}
} else {
V_6 -> V_25 = 0 ;
V_37 -> V_41 = 0 ;
V_6 -> V_11 -> V_12 = V_17 ;
V_9 &= ~ V_39 ;
F_6 ( V_6 ) ;
}
F_9 ( V_6 -> V_14 , V_15 , V_9 ) ;
F_8 ( V_6 -> V_24 , L_6
L_7 ,
F_15 ( V_6 -> V_11 -> V_12 ) ,
F_5 ( V_6 -> V_14 , V_15 ) ) ;
}
static int F_26 ( struct V_6 * V_6 , T_2 V_43 )
{
T_2 V_9 = F_5 ( V_6 -> V_14 , V_15 ) ;
V_9 |= V_39 ;
F_9 ( V_6 -> V_14 , V_15 , V_9 ) ;
return 0 ;
}
static inline void F_27 ( struct V_6 * V_6 )
{
T_1 V_44 ;
V_44 = F_28 ( V_6 -> V_14 , V_45 ) ;
V_44 |= V_46 ;
F_29 ( V_6 -> V_14 , V_45 , V_44 ) ;
}
static inline void F_30 ( struct V_6 * V_6 )
{
T_1 V_44 ;
V_44 = F_28 ( V_6 -> V_14 , V_45 ) ;
V_44 &= ~ V_46 ;
F_29 ( V_6 -> V_14 , V_45 , V_44 ) ;
}
void F_31 ( enum V_47 V_48 )
{
struct V_1 * V_2 = V_49 ;
struct V_6 * V_6 = F_32 ( V_2 ) ;
V_2 -> V_48 = V_48 ;
if ( ! V_6 ) {
F_24 ( V_2 -> V_50 , L_8 ) ;
return;
}
F_33 ( & V_2 -> V_51 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_6 * V_6 = F_32 ( V_2 ) ;
struct V_52 * V_50 = V_6 -> V_24 ;
struct V_53 * V_54 = V_50 -> V_55 ;
struct V_56 * V_57 = V_54 -> V_58 ;
struct V_36 * V_37 = V_6 -> V_11 -> V_37 ;
switch ( V_2 -> V_48 ) {
case V_59 :
F_8 ( V_50 , L_9 ) ;
V_37 -> V_41 = true ;
V_6 -> V_11 -> V_12 = V_18 ;
V_6 -> V_11 -> V_60 = V_61 ;
if ( V_6 -> V_62 ) {
F_35 ( V_50 ) ;
V_3 = V_63 | V_64 ;
F_1 ( V_2 , V_3 ) ;
F_21 ( V_6 , 1 ) ;
}
break;
case V_65 :
F_8 ( V_50 , L_10 ) ;
V_37 -> V_41 = false ;
V_6 -> V_11 -> V_12 = V_17 ;
V_6 -> V_11 -> V_60 = V_66 ;
if ( V_6 -> V_62 )
F_35 ( V_50 ) ;
V_3 = V_67 | V_63 | V_64 ;
F_1 ( V_2 , V_3 ) ;
break;
case V_68 :
case V_69 :
F_8 ( V_50 , L_11 ) ;
V_6 -> V_11 -> V_60 = V_70 ;
if ( V_6 -> V_62 ) {
F_36 ( V_50 ) ;
F_37 ( V_50 ) ;
}
if ( V_57 -> V_71 == V_72 ) {
if ( V_6 -> V_11 -> V_37 -> V_40 )
F_25 ( V_6 -> V_11 -> V_37 , 0 ) ;
}
V_3 = V_73 | V_67 ;
F_1 ( V_2 , V_3 ) ;
break;
default:
F_8 ( V_50 , L_12 ) ;
}
}
static void V_51 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_38 ( V_75 ,
struct V_1 , V_51 ) ;
F_34 ( V_2 ) ;
}
static int F_39 ( struct V_6 * V_6 )
{
T_1 V_44 ;
int V_48 = 0 ;
struct V_52 * V_50 = V_6 -> V_24 ;
struct V_1 * V_2 = F_40 ( V_50 -> V_76 ) ;
struct V_53 * V_77 = V_50 -> V_55 ;
struct V_56 * V_57 = V_77 -> V_58 ;
V_6 -> V_11 = F_41 ( V_50 , V_78 ) ;
if ( F_42 ( V_6 -> V_11 ) ) {
F_43 ( L_13 ) ;
return - V_79 ;
}
V_48 = F_35 ( V_50 ) ;
if ( V_48 < 0 ) {
F_24 ( V_50 , L_14 , V_48 ) ;
goto V_80;
}
V_44 = F_28 ( V_6 -> V_14 , V_81 ) ;
if ( V_57 -> V_71 == V_72 ) {
V_44 &= ~ V_82 ;
V_44 |= V_83 ;
} else {
V_44 |= V_82 ;
}
F_29 ( V_6 -> V_14 , V_81 , V_44 ) ;
F_44 ( L_15
L_16 ,
F_28 ( V_6 -> V_14 , V_84 ) ,
F_28 ( V_6 -> V_14 , V_85 ) ,
F_28 ( V_6 -> V_14 , V_86 ) ,
F_28 ( V_6 -> V_14 , V_81 ) ,
F_28 ( V_6 -> V_14 , V_87 ) ) ;
F_45 ( & V_34 , F_3 , ( unsigned long ) V_6 ) ;
if ( V_2 -> V_48 != V_88 )
F_34 ( V_2 ) ;
F_46 ( V_6 -> V_24 ) ;
return 0 ;
V_80:
return V_48 ;
}
static void F_47 ( struct V_6 * V_6 )
{
T_2 V_9 ;
T_1 V_3 ;
unsigned long V_29 = V_31 + F_14 ( 1000 ) ;
struct V_52 * V_50 = V_6 -> V_24 ;
struct V_1 * V_2 = F_40 ( V_50 -> V_76 ) ;
struct V_53 * V_54 = V_50 -> V_55 ;
struct V_56 * V_57 = V_54 -> V_58 ;
switch ( V_2 -> V_48 ) {
case V_59 :
V_3 = V_63 | V_64 ;
F_1 ( V_2 , V_3 ) ;
if ( V_57 -> V_71 != V_72 )
break;
V_9 = F_5 ( V_6 -> V_14 , V_15 ) ;
V_9 |= V_39 ;
F_9 ( V_6 -> V_14 , V_15 , V_9 ) ;
while ( F_5 ( V_6 -> V_14 , V_15 ) &
V_16 ) {
F_23 () ;
if ( F_17 ( V_31 , V_29 ) ) {
F_24 ( V_50 , L_5 ) ;
break;
}
}
break;
case V_65 :
V_3 = V_67 | V_63 | V_64 ;
F_1 ( V_2 , V_3 ) ;
break;
default:
break;
}
}
static void F_48 ( struct V_6 * V_6 )
{
T_1 V_3 ;
struct V_52 * V_50 = V_6 -> V_24 ;
struct V_1 * V_2 = F_40 ( V_50 -> V_76 ) ;
if ( V_2 -> V_48 != V_88 ) {
V_3 = V_73 | V_67 ;
F_1 ( V_2 , V_3 ) ;
}
}
static int F_49 ( struct V_6 * V_6 )
{
F_50 ( & V_34 ) ;
F_27 ( V_6 ) ;
return 0 ;
}
static int T_3 F_51 ( struct V_89 * V_90 )
{
struct V_53 * V_54 = V_90 -> V_50 . V_55 ;
struct V_56 * V_57 ;
struct V_89 * V_6 ;
struct V_1 * V_2 ;
struct V_91 * V_92 = V_90 -> V_50 . V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
int V_98 = - V_99 ;
int V_100 ;
V_2 = F_52 ( & V_90 -> V_50 , sizeof( * V_2 ) , V_101 ) ;
if ( ! V_2 ) {
F_24 ( & V_90 -> V_50 , L_17 ) ;
goto V_102;
}
V_100 = F_53 ( & V_90 -> V_50 , V_101 ) ;
if ( V_100 < 0 ) {
F_24 ( & V_90 -> V_50 , L_18 ) ;
V_98 = - V_99 ;
goto V_102;
}
V_6 = F_54 ( L_19 , V_100 ) ;
if ( ! V_6 ) {
F_24 ( & V_90 -> V_50 , L_20 ) ;
goto V_80;
}
V_6 -> V_103 = V_100 ;
V_6 -> V_50 . V_76 = & V_90 -> V_50 ;
V_6 -> V_50 . V_104 = & V_105 ;
V_6 -> V_50 . V_106 = V_105 ;
V_2 -> V_50 = & V_90 -> V_50 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_48 = V_88 ;
V_97 = F_55 ( V_90 , V_107 , 1 ) ;
V_2 -> V_4 = F_56 ( & V_90 -> V_50 , V_97 ) ;
if ( V_2 -> V_4 == NULL )
F_8 ( & V_90 -> V_50 , L_21 ) ;
if ( V_92 ) {
V_54 = F_52 ( & V_90 -> V_50 , sizeof( * V_54 ) , V_101 ) ;
if ( ! V_54 ) {
F_24 ( & V_90 -> V_50 ,
L_22 ) ;
V_98 = - V_99 ;
goto V_80;
}
V_57 = F_52 ( & V_90 -> V_50 , sizeof( * V_57 ) , V_101 ) ;
if ( ! V_57 ) {
F_24 ( & V_90 -> V_50 ,
L_23 ) ;
V_98 = - V_99 ;
goto V_80;
}
V_95 = F_52 ( & V_90 -> V_50 , sizeof( * V_95 ) , V_101 ) ;
if ( ! V_57 ) {
F_24 ( & V_90 -> V_50 ,
L_24 ) ;
goto V_80;
}
F_57 ( V_92 , L_25 , ( T_1 * ) & V_54 -> V_108 ) ;
F_57 ( V_92 , L_26 ,
( T_1 * ) & V_57 -> V_71 ) ;
F_57 ( V_92 , L_27 , ( T_1 * ) & V_95 -> V_109 ) ;
F_57 ( V_92 , L_28 , ( T_1 * ) & V_95 -> V_110 ) ;
F_57 ( V_92 , L_29 , ( T_1 * ) & V_54 -> V_8 ) ;
V_95 -> V_111 = F_58 ( V_92 , L_30 ) ;
V_54 -> V_58 = V_57 ;
V_54 -> V_95 = V_95 ;
}
V_54 -> V_112 = & V_113 ;
F_59 ( V_90 , V_2 ) ;
V_49 = V_2 ;
F_60 ( & V_2 -> V_51 , V_51 ) ;
V_98 = F_61 ( V_6 , V_90 -> V_96 ,
V_90 -> V_114 ) ;
if ( V_98 ) {
F_24 ( & V_90 -> V_50 , L_31 ) ;
goto V_115;
}
V_98 = F_62 ( V_6 , V_54 , sizeof( * V_54 ) ) ;
if ( V_98 ) {
F_24 ( & V_90 -> V_50 , L_32 ) ;
goto V_115;
}
F_63 ( & V_90 -> V_50 ) ;
V_98 = F_64 ( V_6 ) ;
if ( V_98 ) {
F_24 ( & V_90 -> V_50 , L_33 ) ;
goto V_115;
}
return 0 ;
V_115:
F_65 ( V_6 ) ;
V_80:
F_66 ( & V_90 -> V_50 , V_100 ) ;
V_102:
return V_98 ;
}
static int T_4 F_67 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_68 ( V_90 ) ;
F_69 ( & V_2 -> V_51 ) ;
F_66 ( & V_90 -> V_50 , V_2 -> V_6 -> V_103 ) ;
F_70 ( V_2 -> V_6 ) ;
return 0 ;
}
static int F_71 ( struct V_52 * V_50 )
{
struct V_1 * V_2 = F_40 ( V_50 ) ;
struct V_6 * V_6 = F_32 ( V_2 ) ;
if ( V_6 ) {
V_6 -> V_116 . V_117 = F_28 ( V_6 -> V_14 ,
V_81 ) ;
F_27 ( V_6 ) ;
F_72 ( V_6 -> V_11 , 1 ) ;
}
return 0 ;
}
static int F_73 ( struct V_52 * V_50 )
{
struct V_1 * V_2 = F_40 ( V_50 ) ;
struct V_6 * V_6 = F_32 ( V_2 ) ;
if ( V_6 ) {
F_30 ( V_6 ) ;
F_29 ( V_6 -> V_14 , V_81 ,
V_6 -> V_116 . V_117 ) ;
F_72 ( V_6 -> V_11 , 0 ) ;
}
return 0 ;
}
static int T_5 F_74 ( void )
{
return F_75 ( & V_118 ) ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_118 ) ;
}
