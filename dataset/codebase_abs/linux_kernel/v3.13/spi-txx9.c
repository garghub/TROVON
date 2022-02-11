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
if ( ! V_7 -> V_16
|| V_7 -> V_16 > V_2 -> V_16
|| V_7 -> V_16 < V_2 -> V_17 )
return - V_18 ;
if ( F_10 ( V_7 -> V_14 ,
! ( V_7 -> V_10 & V_11 ) ) ) {
F_11 ( & V_7 -> V_19 , L_1 ) ;
return - V_18 ;
}
F_12 ( & V_2 -> V_20 ) ;
F_5 ( V_7 , V_2 , 0 , ( V_21 / 2 ) / V_7 -> V_16 ) ;
F_13 ( & V_2 -> V_20 ) ;
return 0 ;
}
static T_2 F_14 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
F_3 ( V_2 , F_1 ( V_2 , V_24 ) & ~ V_25 ,
V_24 ) ;
F_15 ( & V_2 -> V_26 ) ;
return V_27 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_7 ;
struct V_30 * V_31 ;
unsigned int V_9 ;
unsigned int V_32 = 1 ;
int V_33 = 0 ;
T_1 V_34 ;
T_1 V_35 = 0 ;
T_3 V_36 = 0 ;
V_9 = 100 + ( V_21 / 2 ) / V_7 -> V_16 ;
V_34 = F_1 ( V_2 , V_37 ) ;
if ( F_17 ( ( V_34 & V_38 ) == V_39 ) ) {
F_11 ( & V_7 -> V_19 , L_2 ) ;
V_33 = - V_40 ;
goto exit;
}
V_34 &= ~ ( V_38 | V_41 | V_42 ) ;
F_3 ( V_2 , V_34 | V_43 | V_42 , V_37 ) ;
F_3 ( V_2 , V_44
| ( ( V_7 -> V_10 & V_45 ) ? V_46 : 0 )
| ( ( V_7 -> V_10 & V_47 ) ? V_48 : 0 )
| 0x08 ,
V_24 ) ;
F_18 (t, &m->transfers, transfer_list) {
const void * V_49 = V_31 -> V_50 ;
void * V_51 = V_31 -> V_52 ;
T_1 V_53 ;
unsigned int V_54 = V_31 -> V_54 ;
unsigned int V_55 ;
T_1 V_56 = V_31 -> V_56 ? : V_7 -> V_16 ;
T_3 V_57 = V_31 -> V_57 ;
V_55 = V_57 >> 3 ;
if ( V_35 != V_56
|| V_36 != V_57 ) {
int V_58 = F_19 ( V_2 -> V_59 , V_56 ) - 1 ;
V_58 = F_20 ( V_58 , V_60 , V_61 ) ;
F_3 ( V_2 , V_34 | V_43 | V_42 ,
V_37 ) ;
F_3 ( V_2 , ( V_58 << 8 ) | V_57 , V_62 ) ;
F_3 ( V_2 , V_34 | V_39 , V_37 ) ;
V_35 = V_56 ;
V_36 = V_57 ;
}
if ( V_32 )
F_5 ( V_7 , V_2 , 1 , V_9 ) ;
V_32 = V_31 -> V_32 ;
while ( V_54 ) {
unsigned int V_63 = V_64 ;
int V_65 ;
T_1 V_66 ;
if ( V_54 < V_63 * V_55 )
V_63 = V_54 / V_55 ;
while ( ! ( F_1 ( V_2 , V_67 ) & V_68 ) )
F_21 () ;
V_66 = F_1 ( V_2 , V_24 ) ;
V_66 &= ~ V_69 ;
V_66 |= ( V_63 - 1 ) << 12 ;
V_66 |= V_25 ;
F_3 ( V_2 , V_66 , V_24 ) ;
for ( V_65 = 0 ; V_65 < V_63 ; V_65 ++ ) {
if ( V_49 ) {
V_53 = ( V_55 == 1 )
? * ( const T_3 * ) V_49
: * ( const V_70 * ) V_49 ;
F_3 ( V_2 , V_53 , V_71 ) ;
V_49 += V_55 ;
} else
F_3 ( V_2 , 0 , V_71 ) ;
}
F_22 ( V_2 -> V_26 ,
F_1 ( V_2 , V_67 ) & V_72 ) ;
for ( V_65 = 0 ; V_65 < V_63 ; V_65 ++ ) {
V_53 = F_1 ( V_2 , V_71 ) ;
if ( V_51 ) {
if ( V_55 == 1 )
* ( T_3 * ) V_51 = V_53 ;
else
* ( V_70 * ) V_51 = V_53 ;
V_51 += V_55 ;
}
}
V_54 -= V_63 * V_55 ;
}
V_29 -> V_73 += V_31 -> V_54 ;
if ( V_31 -> V_74 )
F_23 ( V_31 -> V_74 ) ;
if ( ! V_32 )
continue;
if ( V_31 -> V_75 . V_76 == & V_29 -> V_77 )
break;
F_5 ( V_7 , V_2 , 0 , V_9 ) ;
}
exit:
V_29 -> V_33 = V_33 ;
V_29 -> V_78 ( V_29 -> V_79 ) ;
if ( ! ( V_33 == 0 && V_32 ) )
F_5 ( V_7 , V_2 , 0 , V_9 ) ;
F_3 ( V_2 , V_34 | V_43 | V_42 , V_37 ) ;
}
static void F_24 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_25 ( V_81 , struct V_1 , V_81 ) ;
unsigned long V_82 ;
F_26 ( & V_2 -> V_20 , V_82 ) ;
while ( ! F_27 ( & V_2 -> V_83 ) ) {
struct V_28 * V_29 ;
V_29 = F_25 ( V_2 -> V_83 . V_76 , struct V_28 , V_83 ) ;
F_28 ( & V_29 -> V_83 ) ;
F_29 ( & V_2 -> V_20 , V_82 ) ;
F_16 ( V_2 , V_29 ) ;
F_26 ( & V_2 -> V_20 , V_82 ) ;
}
F_29 ( & V_2 -> V_20 , V_82 ) ;
}
static int F_30 ( struct V_6 * V_7 , struct V_28 * V_29 )
{
struct V_84 * V_15 = V_7 -> V_15 ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
struct V_30 * V_31 ;
unsigned long V_82 ;
V_29 -> V_73 = 0 ;
F_18 (t, &m->transfers, transfer_list) {
T_1 V_56 = V_31 -> V_56 ? : V_7 -> V_16 ;
T_3 V_57 = V_31 -> V_57 ;
if ( ! V_31 -> V_50 && ! V_31 -> V_52 && V_31 -> V_54 )
return - V_18 ;
if ( V_31 -> V_54 & ( ( V_57 >> 3 ) - 1 ) )
return - V_18 ;
if ( V_56 < V_2 -> V_17 || V_56 > V_2 -> V_16 )
return - V_18 ;
}
F_26 ( & V_2 -> V_20 , V_82 ) ;
F_31 ( & V_29 -> V_83 , & V_2 -> V_83 ) ;
F_32 ( V_2 -> V_85 , & V_2 -> V_81 ) ;
F_29 ( & V_2 -> V_20 , V_82 ) ;
return 0 ;
}
static int F_33 ( struct V_86 * V_19 )
{
struct V_84 * V_15 ;
struct V_1 * V_2 ;
struct V_87 * V_88 ;
int V_89 = - V_90 ;
T_1 V_34 ;
int V_22 ;
V_15 = F_34 ( & V_19 -> V_19 , sizeof( * V_2 ) ) ;
if ( ! V_15 )
return V_89 ;
V_2 = F_9 ( V_15 ) ;
F_35 ( V_19 , V_15 ) ;
F_36 ( & V_2 -> V_81 , F_24 ) ;
F_37 ( & V_2 -> V_20 ) ;
F_38 ( & V_2 -> V_83 ) ;
F_39 ( & V_2 -> V_26 ) ;
V_2 -> V_91 = F_40 ( & V_19 -> V_19 , L_3 ) ;
if ( F_41 ( V_2 -> V_91 ) ) {
V_89 = F_42 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
goto exit;
}
V_89 = F_43 ( V_2 -> V_91 ) ;
if ( V_89 ) {
F_44 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
goto exit;
}
V_2 -> V_59 = F_45 ( V_2 -> V_91 ) ;
V_2 -> V_17 = F_19 ( V_2 -> V_59 , V_61 + 1 ) ;
V_2 -> V_16 = V_2 -> V_59 / ( V_60 + 1 ) ;
V_88 = F_46 ( V_19 , V_92 , 0 ) ;
if ( ! V_88 )
goto V_93;
if ( ! F_47 ( & V_19 -> V_19 , V_88 -> V_94 , F_48 ( V_88 ) ,
L_4 ) )
goto V_93;
V_2 -> V_4 = F_49 ( & V_19 -> V_19 , V_88 -> V_94 , F_48 ( V_88 ) ) ;
if ( ! V_2 -> V_4 )
goto V_93;
V_34 = F_1 ( V_2 , V_37 ) ;
V_34 &= ~ ( V_38 | V_41 | V_42 ) ;
F_3 ( V_2 , V_34 | V_43 | V_42 , V_37 ) ;
V_22 = F_50 ( V_19 , 0 ) ;
if ( V_22 < 0 )
goto V_93;
V_89 = F_51 ( & V_19 -> V_19 , V_22 , F_14 , 0 ,
L_4 , V_2 ) ;
if ( V_89 )
goto exit;
V_2 -> V_85 = F_52 (
F_53 ( V_15 -> V_19 . V_95 ) ) ;
if ( ! V_2 -> V_85 )
goto V_93;
V_2 -> V_12 = - 1 ;
F_54 ( & V_19 -> V_19 , L_5 ,
( unsigned long long ) V_88 -> V_94 , V_22 ,
( V_2 -> V_59 + 500000 ) / 1000000 ) ;
V_15 -> V_96 = V_11 | V_45 | V_47 ;
V_15 -> V_97 = V_19 -> V_98 ;
V_15 -> V_99 = F_8 ;
V_15 -> V_100 = F_30 ;
V_15 -> V_101 = ( V_70 ) V_102 ;
V_15 -> V_103 = F_55 ( 8 ) | F_55 ( 16 ) ;
V_89 = F_56 ( & V_19 -> V_19 , V_15 ) ;
if ( V_89 )
goto exit;
return 0 ;
V_93:
V_89 = - V_104 ;
exit:
if ( V_2 -> V_85 )
F_57 ( V_2 -> V_85 ) ;
if ( V_2 -> V_91 ) {
F_58 ( V_2 -> V_91 ) ;
F_44 ( V_2 -> V_91 ) ;
}
F_59 ( V_15 ) ;
return V_89 ;
}
static int F_60 ( struct V_86 * V_19 )
{
struct V_84 * V_15 = F_61 ( V_19 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
F_57 ( V_2 -> V_85 ) ;
F_58 ( V_2 -> V_91 ) ;
F_44 ( V_2 -> V_91 ) ;
return 0 ;
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_105 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_105 ) ;
}
