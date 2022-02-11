static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 , struct V_1 * V_2 ,
int V_8 , unsigned int V_9 )
{
int V_5 = ( V_7 -> V_10 & V_11 ) ? V_8 : ! V_8 ;
if ( V_8 ) {
if ( V_2 -> V_12 >= 0 )
F_6 ( V_2 -> V_12 ,
! V_2 -> V_13 ) ;
V_2 -> V_12 = V_7 -> V_14 ;
V_2 -> V_13 = V_5 ;
} else {
V_2 -> V_12 = - 1 ;
F_7 ( V_9 ) ;
}
F_6 ( V_7 -> V_14 , V_5 ) ;
F_7 ( V_9 ) ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_9 ( V_7 -> V_15 ) ;
if ( ! V_7 -> V_16 )
return - V_17 ;
if ( F_10 ( V_7 -> V_14 ,
! ( V_7 -> V_10 & V_11 ) ) ) {
F_11 ( & V_7 -> V_18 , L_1 ) ;
return - V_17 ;
}
F_12 ( & V_2 -> V_19 ) ;
F_5 ( V_7 , V_2 , 0 , ( V_20 / 2 ) / V_7 -> V_16 ) ;
F_13 ( & V_2 -> V_19 ) ;
return 0 ;
}
static T_2 F_14 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
F_3 ( V_2 , F_1 ( V_2 , V_23 ) & ~ V_24 ,
V_23 ) ;
F_15 ( & V_2 -> V_25 ) ;
return V_26 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_6 * V_7 = V_28 -> V_7 ;
struct V_29 * V_30 ;
unsigned int V_9 ;
unsigned int V_31 = 1 ;
int V_32 = 0 ;
T_1 V_33 ;
T_1 V_34 = 0 ;
T_3 V_35 = 0 ;
V_9 = 100 + ( V_20 / 2 ) / V_7 -> V_16 ;
V_33 = F_1 ( V_2 , V_36 ) ;
if ( F_17 ( ( V_33 & V_37 ) == V_38 ) ) {
F_11 ( & V_7 -> V_18 , L_2 ) ;
V_32 = - V_39 ;
goto exit;
}
V_33 &= ~ ( V_37 | V_40 | V_41 ) ;
F_3 ( V_2 , V_33 | V_42 | V_41 , V_36 ) ;
F_3 ( V_2 , V_43
| ( ( V_7 -> V_10 & V_44 ) ? V_45 : 0 )
| ( ( V_7 -> V_10 & V_46 ) ? V_47 : 0 )
| 0x08 ,
V_23 ) ;
F_18 (t, &m->transfers, transfer_list) {
const void * V_48 = V_30 -> V_49 ;
void * V_50 = V_30 -> V_51 ;
T_1 V_52 ;
unsigned int V_53 = V_30 -> V_53 ;
unsigned int V_54 ;
T_1 V_55 = V_30 -> V_55 ? : V_7 -> V_16 ;
T_3 V_56 = V_30 -> V_56 ;
V_54 = V_56 >> 3 ;
if ( V_34 != V_55
|| V_35 != V_56 ) {
int V_57 = F_19 ( V_2 -> V_58 , V_55 ) - 1 ;
V_57 = F_20 ( V_57 , V_59 , V_60 ) ;
F_3 ( V_2 , V_33 | V_42 | V_41 ,
V_36 ) ;
F_3 ( V_2 , ( V_57 << 8 ) | V_56 , V_61 ) ;
F_3 ( V_2 , V_33 | V_38 , V_36 ) ;
V_34 = V_55 ;
V_35 = V_56 ;
}
if ( V_31 )
F_5 ( V_7 , V_2 , 1 , V_9 ) ;
V_31 = V_30 -> V_31 ;
while ( V_53 ) {
unsigned int V_62 = V_63 ;
int V_64 ;
T_1 V_65 ;
if ( V_53 < V_62 * V_54 )
V_62 = V_53 / V_54 ;
while ( ! ( F_1 ( V_2 , V_66 ) & V_67 ) )
F_21 () ;
V_65 = F_1 ( V_2 , V_23 ) ;
V_65 &= ~ V_68 ;
V_65 |= ( V_62 - 1 ) << 12 ;
V_65 |= V_24 ;
F_3 ( V_2 , V_65 , V_23 ) ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
if ( V_48 ) {
V_52 = ( V_54 == 1 )
? * ( const T_3 * ) V_48
: * ( const V_69 * ) V_48 ;
F_3 ( V_2 , V_52 , V_70 ) ;
V_48 += V_54 ;
} else
F_3 ( V_2 , 0 , V_70 ) ;
}
F_22 ( V_2 -> V_25 ,
F_1 ( V_2 , V_66 ) & V_71 ) ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
V_52 = F_1 ( V_2 , V_70 ) ;
if ( V_50 ) {
if ( V_54 == 1 )
* ( T_3 * ) V_50 = V_52 ;
else
* ( V_69 * ) V_50 = V_52 ;
V_50 += V_54 ;
}
}
V_53 -= V_62 * V_54 ;
}
V_28 -> V_72 += V_30 -> V_53 ;
if ( V_30 -> V_73 )
F_23 ( V_30 -> V_73 ) ;
if ( ! V_31 )
continue;
if ( V_30 -> V_74 . V_75 == & V_28 -> V_76 )
break;
F_5 ( V_7 , V_2 , 0 , V_9 ) ;
}
exit:
V_28 -> V_32 = V_32 ;
if ( V_28 -> V_77 )
V_28 -> V_77 ( V_28 -> V_78 ) ;
if ( ! ( V_32 == 0 && V_31 ) )
F_5 ( V_7 , V_2 , 0 , V_9 ) ;
F_3 ( V_2 , V_33 | V_42 | V_41 , V_36 ) ;
}
static void F_24 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_25 ( V_80 , struct V_1 , V_80 ) ;
unsigned long V_81 ;
F_26 ( & V_2 -> V_19 , V_81 ) ;
while ( ! F_27 ( & V_2 -> V_82 ) ) {
struct V_27 * V_28 ;
V_28 = F_25 ( V_2 -> V_82 . V_75 , struct V_27 , V_82 ) ;
F_28 ( & V_28 -> V_82 ) ;
F_29 ( & V_2 -> V_19 , V_81 ) ;
F_16 ( V_2 , V_28 ) ;
F_26 ( & V_2 -> V_19 , V_81 ) ;
}
F_29 ( & V_2 -> V_19 , V_81 ) ;
}
static int F_30 ( struct V_6 * V_7 , struct V_27 * V_28 )
{
struct V_83 * V_15 = V_7 -> V_15 ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
struct V_29 * V_30 ;
unsigned long V_81 ;
V_28 -> V_72 = 0 ;
F_18 (t, &m->transfers, transfer_list) {
if ( ! V_30 -> V_49 && ! V_30 -> V_51 && V_30 -> V_53 )
return - V_17 ;
}
F_26 ( & V_2 -> V_19 , V_81 ) ;
F_31 ( & V_28 -> V_82 , & V_2 -> V_82 ) ;
F_32 ( V_2 -> V_84 , & V_2 -> V_80 ) ;
F_29 ( & V_2 -> V_19 , V_81 ) ;
return 0 ;
}
static int F_33 ( struct V_85 * V_18 )
{
struct V_83 * V_15 ;
struct V_1 * V_2 ;
struct V_86 * V_87 ;
int V_88 = - V_89 ;
T_1 V_33 ;
int V_21 ;
V_15 = F_34 ( & V_18 -> V_18 , sizeof( * V_2 ) ) ;
if ( ! V_15 )
return V_88 ;
V_2 = F_9 ( V_15 ) ;
F_35 ( V_18 , V_15 ) ;
F_36 ( & V_2 -> V_80 , F_24 ) ;
F_37 ( & V_2 -> V_19 ) ;
F_38 ( & V_2 -> V_82 ) ;
F_39 ( & V_2 -> V_25 ) ;
V_2 -> V_90 = F_40 ( & V_18 -> V_18 , L_3 ) ;
if ( F_41 ( V_2 -> V_90 ) ) {
V_88 = F_42 ( V_2 -> V_90 ) ;
V_2 -> V_90 = NULL ;
goto exit;
}
V_88 = F_43 ( V_2 -> V_90 ) ;
if ( V_88 ) {
V_2 -> V_90 = NULL ;
goto exit;
}
V_2 -> V_58 = F_44 ( V_2 -> V_90 ) ;
V_15 -> V_91 = F_19 ( V_2 -> V_58 , V_60 + 1 ) ;
V_15 -> V_16 = V_2 -> V_58 / ( V_59 + 1 ) ;
V_87 = F_45 ( V_18 , V_92 , 0 ) ;
V_2 -> V_4 = F_46 ( & V_18 -> V_18 , V_87 ) ;
if ( F_41 ( V_2 -> V_4 ) )
goto V_93;
V_33 = F_1 ( V_2 , V_36 ) ;
V_33 &= ~ ( V_37 | V_40 | V_41 ) ;
F_3 ( V_2 , V_33 | V_42 | V_41 , V_36 ) ;
V_21 = F_47 ( V_18 , 0 ) ;
if ( V_21 < 0 )
goto V_93;
V_88 = F_48 ( & V_18 -> V_18 , V_21 , F_14 , 0 ,
L_4 , V_2 ) ;
if ( V_88 )
goto exit;
V_2 -> V_84 = F_49 (
F_50 ( V_15 -> V_18 . V_94 ) ) ;
if ( ! V_2 -> V_84 )
goto V_93;
V_2 -> V_12 = - 1 ;
F_51 ( & V_18 -> V_18 , L_5 ,
( unsigned long long ) V_87 -> V_95 , V_21 ,
( V_2 -> V_58 + 500000 ) / 1000000 ) ;
V_15 -> V_96 = V_11 | V_44 | V_46 ;
V_15 -> V_97 = V_18 -> V_98 ;
V_15 -> V_99 = F_8 ;
V_15 -> V_100 = F_30 ;
V_15 -> V_101 = ( V_69 ) V_102 ;
V_15 -> V_103 = F_52 ( 8 ) | F_52 ( 16 ) ;
V_88 = F_53 ( & V_18 -> V_18 , V_15 ) ;
if ( V_88 )
goto exit;
return 0 ;
V_93:
V_88 = - V_104 ;
exit:
if ( V_2 -> V_84 )
F_54 ( V_2 -> V_84 ) ;
if ( V_2 -> V_90 )
F_55 ( V_2 -> V_90 ) ;
F_56 ( V_15 ) ;
return V_88 ;
}
static int F_57 ( struct V_85 * V_18 )
{
struct V_83 * V_15 = F_58 ( V_18 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
F_54 ( V_2 -> V_84 ) ;
F_55 ( V_2 -> V_90 ) ;
return 0 ;
}
static int T_4 F_59 ( void )
{
return F_60 ( & V_105 ) ;
}
static void T_5 F_61 ( void )
{
F_62 ( & V_105 ) ;
}
