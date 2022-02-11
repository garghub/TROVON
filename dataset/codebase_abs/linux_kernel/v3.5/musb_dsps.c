static inline T_1 F_1 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_2 ( V_1 + V_2 ) ; }
static inline T_3 F_3 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_4 ( V_1 + V_2 ) ; }
static inline void F_5 ( void T_2 * V_1 , unsigned V_2 , T_1 V_3 )
{ F_6 ( V_3 , V_1 + V_2 ) ; }
static inline void F_7 ( void T_2 * V_1 , unsigned V_2 , T_3 V_3 )
{ F_8 ( V_3 , V_1 + V_2 ) ; }
static void F_9 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
void T_2 * V_15 = V_4 -> V_16 ;
T_3 V_17 , V_18 ;
V_17 = ( ( V_4 -> V_17 & V_14 -> V_19 ) << V_14 -> V_20 ) |
( ( V_4 -> V_17 & V_14 -> V_21 ) << V_14 -> V_22 ) ;
V_18 = ( V_14 -> V_23 & ~ V_24 ) ;
F_7 ( V_15 , V_14 -> V_25 , V_17 ) ;
F_7 ( V_15 , V_14 -> V_26 , V_18 ) ;
if ( F_12 ( V_4 ) )
F_7 ( V_15 , V_14 -> V_26 ,
( 1 << V_14 -> V_27 ) << V_14 -> V_28 ) ;
}
static void F_13 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
void T_2 * V_15 = V_4 -> V_16 ;
F_7 ( V_15 , V_14 -> V_29 , V_14 -> V_23 ) ;
F_7 ( V_15 , V_14 -> V_30 ,
V_14 -> V_31 | V_14 -> V_32 ) ;
F_5 ( V_4 -> V_33 , V_34 , 0 ) ;
F_7 ( V_15 , V_14 -> V_35 , 0 ) ;
}
static void F_14 ( unsigned long V_36 )
{
struct V_4 * V_4 = ( void * ) V_36 ;
void T_2 * V_33 = V_4 -> V_33 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
T_1 V_37 ;
unsigned long V_38 ;
V_37 = F_1 ( V_33 , V_34 ) ;
F_15 ( V_4 -> V_7 , L_1 , V_37 ,
F_16 ( V_4 -> V_39 -> V_40 ) ) ;
F_17 ( & V_4 -> V_41 , V_38 ) ;
switch ( V_4 -> V_39 -> V_40 ) {
case V_42 :
V_37 &= ~ V_43 ;
F_5 ( V_4 -> V_33 , V_34 , V_37 ) ;
V_37 = F_1 ( V_4 -> V_33 , V_34 ) ;
if ( V_37 & V_44 ) {
V_4 -> V_39 -> V_40 = V_45 ;
F_18 ( V_4 ) ;
} else {
V_4 -> V_39 -> V_40 = V_46 ;
F_19 ( V_4 ) ;
}
break;
case V_47 :
V_4 -> V_39 -> V_40 = V_48 ;
F_7 ( V_4 -> V_16 , V_14 -> V_26 ,
V_49 << V_14 -> V_28 ) ;
break;
case V_45 :
if ( ! F_20 ( V_4 ) )
break;
V_37 = F_1 ( V_33 , V_34 ) ;
if ( V_37 & V_44 )
F_21 ( & V_12 -> V_50 ,
V_51 + V_14 -> V_52 * V_53 ) ;
else
V_4 -> V_39 -> V_40 = V_46 ;
break;
default:
break;
}
F_22 ( & V_4 -> V_41 , V_38 ) ;
}
static void F_23 ( struct V_4 * V_4 , unsigned long V_54 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
static unsigned long V_55 ;
if ( ! F_12 ( V_4 ) )
return;
if ( V_54 == 0 )
V_54 = V_51 + F_24 ( 3 ) ;
if ( V_4 -> V_56 || ( V_4 -> V_57 == 0 &&
V_4 -> V_39 -> V_40 == V_42 ) ) {
F_15 ( V_4 -> V_7 , L_2 ,
F_16 ( V_4 -> V_39 -> V_40 ) ) ;
F_25 ( & V_12 -> V_50 ) ;
V_55 = V_51 ;
return;
}
if ( F_26 ( V_55 , V_54 ) && F_27 ( & V_12 -> V_50 ) ) {
F_15 ( V_4 -> V_7 ,
L_3 ) ;
return;
}
V_55 = V_54 ;
F_15 ( V_4 -> V_7 , L_4 ,
F_16 ( V_4 -> V_39 -> V_40 ) ,
F_28 ( V_54 - V_51 ) ) ;
F_21 ( & V_12 -> V_50 , V_54 ) ;
}
static T_4 F_29 ( int V_58 , void * V_59 )
{
struct V_4 * V_4 = V_59 ;
void T_2 * V_15 = V_4 -> V_16 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
unsigned long V_38 ;
T_4 V_60 = V_61 ;
T_3 V_62 , V_63 ;
F_17 ( & V_4 -> V_41 , V_38 ) ;
V_62 = F_3 ( V_15 , V_14 -> V_64 ) ;
V_4 -> V_65 = ( V_62 & V_14 -> V_32 ) >> V_14 -> V_22 ;
V_4 -> V_66 = ( V_62 & V_14 -> V_31 ) >> V_14 -> V_20 ;
if ( V_62 )
F_7 ( V_15 , V_14 -> V_64 , V_62 ) ;
V_63 = F_3 ( V_15 , V_14 -> V_67 ) ;
if ( ! V_63 && ! V_62 )
goto V_35;
V_4 -> V_68 = ( V_63 & V_14 -> V_23 ) >> V_14 -> V_28 ;
if ( V_63 )
F_7 ( V_15 , V_14 -> V_67 , V_63 ) ;
F_15 ( V_4 -> V_7 , L_5 ,
V_63 , V_62 ) ;
if ( ( V_63 & V_69 ) && F_30 ( V_4 ) )
F_31 ( L_6 ) ;
if ( V_63 & ( ( 1 << V_14 -> V_27 ) << V_14 -> V_28 ) ) {
int V_27 = F_3 ( V_15 , V_14 -> V_70 ) ;
void T_2 * V_33 = V_4 -> V_33 ;
T_1 V_37 = F_1 ( V_33 , V_34 ) ;
int V_71 ;
V_71 = F_30 ( V_4 ) && ( V_4 -> V_68 &
V_49 ) ;
if ( V_71 ) {
V_4 -> V_68 &= ~ V_49 ;
V_4 -> V_39 -> V_40 = V_47 ;
F_21 ( & V_12 -> V_50 ,
V_51 + V_14 -> V_52 * V_53 ) ;
F_32 ( L_7 ) ;
} else if ( F_30 ( V_4 ) && V_27 ) {
V_4 -> V_56 = 1 ;
F_19 ( V_4 ) ;
V_4 -> V_39 -> V_72 -> V_73 = 1 ;
V_4 -> V_39 -> V_40 = V_48 ;
F_25 ( & V_12 -> V_50 ) ;
} else {
V_4 -> V_56 = 0 ;
F_18 ( V_4 ) ;
V_4 -> V_39 -> V_72 -> V_73 = 0 ;
V_4 -> V_39 -> V_40 = V_45 ;
}
F_15 ( V_4 -> V_7 , L_8 ,
V_27 ? L_9 : L_10 ,
F_16 ( V_4 -> V_39 -> V_40 ) ,
V_71 ? L_11 : L_12 ,
V_37 ) ;
V_60 = V_74 ;
}
if ( V_4 -> V_66 || V_4 -> V_65 || V_4 -> V_68 )
V_60 |= F_33 ( V_4 ) ;
V_35:
if ( V_60 == V_74 || V_62 || V_63 )
F_7 ( V_15 , V_14 -> V_35 , 1 ) ;
if ( F_12 ( V_4 ) && V_4 -> V_39 -> V_40 == V_45 )
F_21 ( & V_12 -> V_50 , V_51 + V_14 -> V_52 * V_53 ) ;
F_22 ( & V_4 -> V_41 , V_38 ) ;
return V_60 ;
}
static int F_34 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_75 * V_76 = V_6 -> V_77 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
struct V_78 * V_3 = V_76 -> V_79 ;
void T_2 * V_15 = V_4 -> V_16 ;
T_3 V_80 , V_81 ;
int V_70 ;
V_4 -> V_33 += V_14 -> V_82 ;
F_35 () ;
V_4 -> V_39 = F_36 () ;
if ( ! V_4 -> V_39 )
return - V_83 ;
V_80 = F_3 ( V_15 , V_14 -> V_84 ) ;
if ( ! V_80 ) {
V_70 = - V_83 ;
goto V_85;
}
if ( F_30 ( V_4 ) )
F_37 ( & V_12 -> V_50 , F_14 , ( unsigned long ) V_4 ) ;
F_7 ( V_15 , V_14 -> V_86 , ( 1 << V_14 -> V_87 ) ) ;
if ( V_3 -> V_88 )
V_3 -> V_88 ( 1 ) ;
V_4 -> V_89 = F_29 ;
V_81 = F_3 ( V_15 , V_14 -> V_90 ) ;
V_81 &= ~ ( 1 << V_14 -> V_91 ) ;
F_7 ( V_4 -> V_16 , V_14 -> V_90 , V_81 ) ;
F_7 ( V_15 , V_14 -> V_35 , 0 ) ;
return 0 ;
V_85:
F_38 ( V_4 -> V_39 ) ;
F_39 () ;
return V_70 ;
}
static int F_40 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_75 * V_76 = V_6 -> V_77 ;
struct V_78 * V_3 = V_76 -> V_79 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
if ( F_30 ( V_4 ) )
F_41 ( & V_12 -> V_50 ) ;
if ( V_3 -> V_88 )
V_3 -> V_88 ( 0 ) ;
F_38 ( V_4 -> V_39 ) ;
F_39 () ;
return 0 ;
}
static int T_5 F_42 ( struct V_11 * V_12 , T_1 V_92 )
{
struct V_5 * V_6 = V_12 -> V_6 ;
struct V_8 * V_9 = F_10 ( V_6 ) ;
struct V_75 * V_93 = V_6 -> V_77 ;
struct V_8 * V_4 ;
struct V_94 * V_95 ;
struct V_94 V_96 [ 2 ] ;
char V_97 [ 10 ] ;
int V_60 ;
sprintf ( V_97 , L_13 , V_92 ) ;
V_95 = F_43 ( V_9 , V_98 , V_97 ) ;
if ( ! V_95 ) {
F_44 ( V_6 , L_14 , V_97 ) ;
V_60 = - V_83 ;
goto V_85;
}
V_95 -> V_10 = NULL ;
V_96 [ 0 ] = * V_95 ;
sprintf ( V_97 , L_15 , V_92 ) ;
V_95 = F_43 ( V_9 , V_99 , V_97 ) ;
if ( ! V_95 ) {
F_44 ( V_6 , L_16 , V_97 ) ;
V_60 = - V_83 ;
goto V_85;
}
strcpy ( ( T_1 * ) V_95 -> V_100 , L_17 ) ;
V_95 -> V_10 = NULL ;
V_96 [ 1 ] = * V_95 ;
V_4 = F_45 ( L_18 , - 1 ) ;
if ( ! V_4 ) {
F_44 ( V_6 , L_19 ) ;
V_60 = - V_101 ;
goto V_85;
}
V_4 -> V_6 . V_10 = V_6 ;
V_4 -> V_6 . V_102 = & V_103 ;
V_4 -> V_6 . V_104 = V_103 ;
V_12 -> V_4 = V_4 ;
V_93 -> V_105 = & V_106 ;
V_60 = F_46 ( V_4 , V_96 , 2 ) ;
if ( V_60 ) {
F_44 ( V_6 , L_20 ) ;
goto V_107;
}
V_60 = F_47 ( V_4 , V_93 , sizeof( * V_93 ) ) ;
if ( V_60 ) {
F_44 ( V_6 , L_21 ) ;
goto V_107;
}
V_60 = F_48 ( V_4 ) ;
if ( V_60 ) {
F_44 ( V_6 , L_22 ) ;
goto V_107;
}
return 0 ;
V_107:
F_49 ( V_4 ) ;
V_85:
return V_60 ;
}
static void T_6 F_50 ( struct V_11 * V_12 )
{
F_51 ( V_12 -> V_4 ) ;
F_49 ( V_12 -> V_4 ) ;
}
static int T_5 F_52 ( struct V_8 * V_9 )
{
const struct V_108 * V_92 = F_53 ( V_9 ) ;
const struct V_13 * V_14 =
(struct V_13 * ) V_92 -> V_109 ;
struct V_11 * V_12 ;
struct V_94 * V_110 ;
int V_60 ;
V_12 = F_54 ( sizeof( * V_12 ) , V_111 ) ;
if ( ! V_12 ) {
F_44 ( & V_9 -> V_6 , L_23 ) ;
V_60 = - V_101 ;
goto V_85;
}
V_110 = F_55 ( V_9 , V_98 , 0 ) ;
if ( ! V_110 ) {
F_44 ( & V_9 -> V_6 , L_24 ) ;
V_60 = - V_83 ;
goto V_107;
}
V_12 -> V_6 = & V_9 -> V_6 ;
V_12 -> V_14 = F_56 ( V_14 , sizeof( * V_14 ) , V_111 ) ;
if ( ! V_12 -> V_14 ) {
F_44 ( & V_9 -> V_6 , L_25 ) ;
V_60 = - V_101 ;
goto V_107;
}
F_57 ( V_9 , V_12 ) ;
V_60 = F_42 ( V_12 , 0 ) ;
if ( V_60 != 0 ) {
F_44 ( & V_9 -> V_6 , L_26 ) ;
goto V_112;
}
F_58 ( & V_9 -> V_6 ) ;
V_60 = F_59 ( & V_9 -> V_6 ) ;
if ( V_60 < 0 ) {
F_44 ( & V_9 -> V_6 , L_27 ) ;
goto V_113;
}
return 0 ;
V_113:
F_60 ( & V_9 -> V_6 ) ;
V_112:
F_61 ( V_12 -> V_14 ) ;
V_107:
F_61 ( V_12 ) ;
V_85:
return V_60 ;
}
static int T_6 F_62 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_11 ( V_9 ) ;
F_50 ( V_12 ) ;
F_63 ( & V_9 -> V_6 ) ;
F_60 ( & V_9 -> V_6 ) ;
F_61 ( V_12 -> V_14 ) ;
F_61 ( V_12 ) ;
return 0 ;
}
static int F_64 ( struct V_5 * V_6 )
{
struct V_75 * V_76 = V_6 -> V_77 ;
struct V_78 * V_3 = V_76 -> V_79 ;
if ( V_3 -> V_88 )
V_3 -> V_88 ( 0 ) ;
return 0 ;
}
static int F_65 ( struct V_5 * V_6 )
{
struct V_75 * V_76 = V_6 -> V_77 ;
struct V_78 * V_3 = V_76 -> V_79 ;
if ( V_3 -> V_88 )
V_3 -> V_88 ( 1 ) ;
return 0 ;
}
static int T_7 F_66 ( void )
{
return F_67 ( & V_114 ) ;
}
static void T_8 F_68 ( void )
{
F_69 ( & V_114 ) ;
}
