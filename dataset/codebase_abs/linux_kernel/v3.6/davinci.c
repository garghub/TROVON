static inline void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 ) ;
V_1 &= ~ ( V_3 | V_4 | V_5 ) ;
V_1 |= V_6 | V_7 | V_8 ;
F_3 ( V_1 , V_2 ) ;
while ( ( F_2 ( V_2 ) & V_9 ) == 0 )
F_4 () ;
}
static inline void F_5 ( void )
{
T_1 V_1 = F_2 ( V_2 ) ;
V_1 &= ~ ( V_6 | V_7 | V_8 ) ;
V_1 |= V_3 | V_4 | V_5 ;
F_3 ( V_1 , V_2 ) ;
}
static void F_6 ( struct V_10 * V_10 )
{
T_1 V_11 , V_12 , V_13 ;
V_11 = ( V_10 -> V_14 & V_15 )
<< V_16 ;
F_7 ( V_10 -> V_17 , V_18 , V_11 ) ;
V_12 = V_11 ;
V_11 = ( V_10 -> V_14 & ( 0xfffe & V_19 ) )
<< V_20 ;
F_7 ( V_10 -> V_17 , V_18 , V_11 ) ;
V_11 |= V_12 ;
V_13 = ~ V_21 ;
V_11 |= ( ( V_13 & 0x01ff ) << V_22 ) ;
F_7 ( V_10 -> V_17 , V_18 , V_11 ) ;
if ( F_8 () && ! V_23 )
F_9 ( V_24 L_1 ,
__FILE__ , V_25 ) ;
else
V_23 = 0 ;
if ( F_10 ( V_10 ) )
F_7 ( V_10 -> V_17 , V_26 ,
V_27 << V_22 ) ;
}
static void F_11 ( struct V_10 * V_10 )
{
F_7 ( V_10 -> V_17 , V_28 ,
V_29
| V_30
| V_31 ) ;
F_12 ( V_10 -> V_32 , V_33 , 0 ) ;
F_7 ( V_10 -> V_17 , V_34 , 0 ) ;
if ( F_8 () && ! V_23 )
F_13 ( L_2 ) ;
}
static void F_14 ( struct V_35 * V_36 )
{
F_15 ( V_37 , V_38 ) ;
V_38 = ! V_38 ;
}
static void F_16 ( struct V_10 * V_10 , int V_39 , int V_40 )
{
#ifdef F_17
if ( V_39 )
V_39 = 1 ;
if ( V_38 == V_39 )
return;
V_38 = ! V_39 ;
if ( F_18 () ) {
static F_19 ( V_41 , F_14 ) ;
if ( V_40 )
F_15 ( V_37 , V_38 ) ;
else
F_20 ( & V_41 ) ;
}
if ( V_40 )
V_38 = V_39 ;
#endif
}
static void F_21 ( struct V_10 * V_10 , int V_39 )
{
F_22 ( V_39 && F_23 ( V_10 ) ) ;
F_16 ( V_10 , V_39 , 0 ) ;
}
static void F_24 ( unsigned long V_42 )
{
struct V_10 * V_10 = ( void * ) V_42 ;
void T_2 * V_32 = V_10 -> V_32 ;
T_3 V_43 ;
unsigned long V_44 ;
V_43 = F_25 ( V_32 , V_33 ) ;
F_26 ( V_10 -> V_45 , L_3 , V_43 ,
F_27 ( V_10 -> V_46 -> V_47 ) ) ;
F_28 ( & V_10 -> V_48 , V_44 ) ;
switch ( V_10 -> V_46 -> V_47 ) {
case V_49 :
if ( V_43 & V_50 ) {
F_29 ( & V_51 , V_52 + V_53 * V_54 ) ;
break;
}
V_10 -> V_46 -> V_47 = V_55 ;
F_7 ( V_10 -> V_17 , V_26 ,
V_56 << V_22 ) ;
break;
case V_57 :
if ( ! F_30 ( V_10 ) )
break;
F_12 ( V_32 , V_33 ,
V_43 | V_58 ) ;
V_43 = F_25 ( V_32 , V_33 ) ;
if ( V_43 & V_59 )
F_29 ( & V_51 , V_52 + V_53 * V_54 ) ;
else
V_10 -> V_46 -> V_47 = V_60 ;
break;
default:
break;
}
F_31 ( & V_10 -> V_48 , V_44 ) ;
}
static T_4 F_32 ( int V_61 , void * V_62 )
{
unsigned long V_44 ;
T_4 V_63 = V_64 ;
struct V_10 * V_10 = V_62 ;
struct V_65 * V_66 = V_10 -> V_46 -> V_66 ;
void T_2 * V_67 = V_10 -> V_17 ;
struct V_68 * V_68 ;
T_1 V_11 ;
F_28 ( & V_10 -> V_48 , V_44 ) ;
V_68 = F_33 ( V_10 -> V_69 , struct V_68 , V_45 ) ;
if ( F_34 () && V_10 -> V_69 && ! V_68 -> V_61 )
V_63 = F_35 ( V_61 , V_62 ) ;
V_11 = F_36 ( V_67 , V_70 ) ;
F_7 ( V_67 , V_71 , V_11 ) ;
F_26 ( V_10 -> V_45 , L_4 , V_11 ) ;
V_10 -> V_72 = ( V_11 & V_31 )
>> V_20 ;
V_10 -> V_73 = ( V_11 & V_30 )
>> V_16 ;
V_10 -> V_74 = ( V_11 & V_29 )
>> V_22 ;
if ( V_11 & ( V_27 << V_22 ) ) {
int V_75 = F_36 ( V_67 , V_76 ) ;
void T_2 * V_32 = V_10 -> V_32 ;
T_3 V_43 = F_25 ( V_32 , V_33 ) ;
int V_77 = V_10 -> V_74 & V_56 ;
V_77 = F_37 ( V_10 )
&& ( V_10 -> V_74 & V_56 ) ;
if ( V_77 ) {
V_10 -> V_74 &= ~ V_56 ;
V_10 -> V_46 -> V_47 = V_49 ;
F_29 ( & V_51 , V_52 + V_53 * V_54 ) ;
F_13 ( L_5 ) ;
} else if ( F_37 ( V_10 ) && V_75 ) {
F_38 ( V_10 ) ;
V_66 -> V_78 = 1 ;
V_10 -> V_46 -> V_47 = V_55 ;
F_39 ( V_10 -> V_79 |= V_80 ) ;
F_40 ( & V_51 ) ;
} else {
V_10 -> V_81 = 0 ;
F_41 ( V_10 ) ;
V_66 -> V_78 = 0 ;
V_10 -> V_46 -> V_47 = V_57 ;
F_39 ( V_10 -> V_79 &= ~ V_80 ) ;
}
F_16 ( V_10 , V_75 , 0 ) ;
F_26 ( V_10 -> V_45 , L_6 ,
V_75 ? L_7 : L_8 ,
F_27 ( V_10 -> V_46 -> V_47 ) ,
V_77 ? L_9 : L_10 ,
V_43 ) ;
V_63 = V_82 ;
}
if ( V_10 -> V_73 || V_10 -> V_72 || V_10 -> V_74 )
V_63 |= F_42 ( V_10 ) ;
F_7 ( V_67 , V_34 , 0 ) ;
if ( F_10 ( V_10 )
&& V_10 -> V_46 -> V_47 == V_57 )
F_29 ( & V_51 , V_52 + V_53 * V_54 ) ;
F_31 ( & V_10 -> V_48 , V_44 ) ;
return V_63 ;
}
static int F_43 ( struct V_10 * V_10 , T_3 V_83 )
{
return - V_84 ;
}
static int F_44 ( struct V_10 * V_10 )
{
void T_2 * V_67 = V_10 -> V_17 ;
T_1 V_85 ;
F_45 () ;
V_10 -> V_46 = F_46 ( V_86 ) ;
if ( F_47 ( V_10 -> V_46 ) )
goto V_87;
V_10 -> V_32 += V_88 ;
V_85 = F_36 ( V_67 , V_89 ) ;
if ( V_85 == 0 )
goto V_90;
if ( F_37 ( V_10 ) )
F_48 ( & V_51 , F_24 , ( unsigned long ) V_10 ) ;
F_16 ( V_10 , 0 , 1 ) ;
if ( F_49 () ) {
T_1 V_1 = F_2 ( V_2 ) ;
V_1 &= ~ ( 3 << 9 ) ;
V_1 |= V_91 ;
F_3 ( V_1 , V_2 ) ;
}
if ( F_50 () ) {
T_1 V_92 = F_2 ( V_93 ) ;
if ( F_37 ( V_10 ) ) {
V_92 &= ~ V_94 ;
} else {
V_92 &= ~ V_95 ;
V_92 |= V_94 ;
}
F_3 ( V_92 , V_93 ) ;
}
F_7 ( V_67 , V_96 , 0x1 ) ;
F_1 () ;
F_51 ( 5 ) ;
F_52 ( L_11 ,
V_85 , F_2 ( V_2 ) ,
F_25 ( V_67 , V_96 ) ) ;
V_10 -> V_97 = F_32 ;
return 0 ;
V_90:
F_53 ( V_10 -> V_46 ) ;
V_87:
F_54 () ;
return - V_98 ;
}
static int F_55 ( struct V_10 * V_10 )
{
if ( F_37 ( V_10 ) )
F_56 ( & V_51 ) ;
if ( F_50 () ) {
T_1 V_92 = F_2 ( V_93 ) ;
V_92 &= ~ V_95 ;
V_92 |= V_94 ;
F_3 ( V_92 , V_93 ) ;
}
F_16 ( V_10 , 0 , 1 ) ;
if ( F_37 ( V_10 ) && V_10 -> V_46 -> V_66 -> V_78 ) {
int V_99 = 30 ;
T_3 V_43 , V_100 = 0 ;
do {
V_43 = F_25 ( V_10 -> V_32 , V_33 ) ;
if ( ! ( V_43 & V_50 ) )
break;
if ( ( V_43 & V_50 ) != V_100 ) {
V_100 = V_43 & V_50 ;
F_26 ( V_10 -> V_45 , L_12 ,
V_100 >> V_101 ) ;
}
F_51 ( 1000 ) ;
V_99 -- ;
} while ( V_99 > 0 );
if ( V_43 & V_50 )
F_26 ( V_10 -> V_45 , L_13 , V_43 ) ;
}
F_5 () ;
F_53 ( V_10 -> V_46 ) ;
F_54 () ;
return 0 ;
}
static int T_5 F_57 ( struct V_102 * V_103 )
{
struct V_104 * V_105 = V_103 -> V_106 . V_107 ;
struct V_102 * V_10 ;
struct V_108 * V_109 ;
struct V_110 * V_110 ;
int V_111 = - V_112 ;
V_109 = F_58 ( sizeof( * V_109 ) , V_113 ) ;
if ( ! V_109 ) {
F_59 ( & V_103 -> V_106 , L_14 ) ;
goto V_114;
}
V_10 = F_60 ( L_15 , - 1 ) ;
if ( ! V_10 ) {
F_59 ( & V_103 -> V_106 , L_16 ) ;
goto V_115;
}
V_110 = F_61 ( & V_103 -> V_106 , L_17 ) ;
if ( F_62 ( V_110 ) ) {
F_59 ( & V_103 -> V_106 , L_18 ) ;
V_111 = F_63 ( V_110 ) ;
goto V_116;
}
V_111 = F_64 ( V_110 ) ;
if ( V_111 ) {
F_59 ( & V_103 -> V_106 , L_19 ) ;
goto V_117;
}
V_10 -> V_106 . V_118 = & V_103 -> V_106 ;
V_10 -> V_106 . V_119 = & V_120 ;
V_10 -> V_106 . V_121 = V_120 ;
V_109 -> V_106 = & V_103 -> V_106 ;
V_109 -> V_10 = V_10 ;
V_109 -> V_110 = V_110 ;
V_105 -> V_122 = & V_123 ;
F_65 ( V_103 , V_109 ) ;
V_111 = F_66 ( V_10 , V_103 -> V_124 ,
V_103 -> V_125 ) ;
if ( V_111 ) {
F_59 ( & V_103 -> V_106 , L_20 ) ;
goto V_126;
}
V_111 = F_67 ( V_10 , V_105 , sizeof( * V_105 ) ) ;
if ( V_111 ) {
F_59 ( & V_103 -> V_106 , L_21 ) ;
goto V_126;
}
V_111 = F_68 ( V_10 ) ;
if ( V_111 ) {
F_59 ( & V_103 -> V_106 , L_22 ) ;
goto V_126;
}
return 0 ;
V_126:
F_69 ( V_110 ) ;
V_117:
F_70 ( V_110 ) ;
V_116:
F_71 ( V_10 ) ;
V_115:
F_72 ( V_109 ) ;
V_114:
return V_111 ;
}
static int T_6 F_73 ( struct V_102 * V_103 )
{
struct V_108 * V_109 = F_74 ( V_103 ) ;
F_75 ( V_109 -> V_10 ) ;
F_71 ( V_109 -> V_10 ) ;
F_69 ( V_109 -> V_110 ) ;
F_70 ( V_109 -> V_110 ) ;
F_72 ( V_109 ) ;
return 0 ;
}
static int T_7 F_76 ( void )
{
return F_77 ( & V_127 ) ;
}
static void T_8 F_78 ( void )
{
F_79 ( & V_127 ) ;
}
