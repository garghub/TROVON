static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
unsigned long V_7 = V_8 + V_2 -> V_9 ;
do {
int V_10 ;
T_1 V_11 ;
V_10 = F_3 ( V_5 , F_4 ( V_3 ) , & V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_11 & V_12 )
return 0 ;
F_5 ( V_13 ) ;
} while ( F_6 ( V_8 , V_7 ) );
return - 1 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 ;
T_1 V_11 ;
V_10 = F_3 ( V_5 , F_4 ( V_3 ) , & V_11 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ( V_11 & ( V_14 | V_12 ) ) ==
( V_14 | V_12 ) )
return V_5 -> V_15 = V_3 ;
return - 1 ;
}
static void F_8 ( struct V_1 * V_2 , int V_3 , int V_16 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 ;
T_1 V_11 ;
V_10 = F_3 ( V_5 , F_4 ( V_3 ) , & V_11 ) ;
if ( V_10 < 0 )
return;
if ( V_16 || ( V_11 &
( V_17 | V_12 ) ) ==
( V_17 | V_12 ) )
F_9 ( V_5 , F_4 ( V_3 ) , V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
unsigned long V_7 , V_18 ;
long V_10 ;
if ( F_7 ( V_2 , V_3 ) >= 0 )
return V_3 ;
V_10 = F_9 ( V_5 , F_4 ( V_3 ) , V_19 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 = V_8 + V_2 -> V_9 ;
if ( V_2 -> V_20 & V_21 ) {
V_22:
V_18 = V_7 - V_8 ;
if ( ( long ) V_18 <= 0 )
return - 1 ;
V_10 = F_11 ( V_5 -> V_23 ,
( F_7
( V_2 , V_3 ) >= 0 ) ,
V_18 ) ;
if ( V_10 > 0 )
return V_3 ;
if ( V_10 == - V_24 && F_12 ( V_25 ) ) {
F_13 ( V_26 ) ;
goto V_22;
}
} else {
do {
if ( F_7 ( V_2 , V_3 ) >= 0 )
return V_3 ;
F_5 ( V_13 ) ;
} while ( F_6 ( V_8 , V_7 ) );
}
return - 1 ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 ;
T_1 V_27 ;
V_10 = F_3 ( V_5 , F_15 ( V_5 -> V_15 ) , & V_27 ) ;
if ( V_10 < 0 )
return 0 ;
return V_27 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
F_9 ( V_5 , F_15 ( V_5 -> V_15 ) , V_28 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
unsigned long V_7 ;
int V_29 , V_10 ;
T_2 V_30 ;
V_7 = V_8 + V_2 -> V_31 ;
do {
V_10 = F_18 ( V_5 , F_15 ( V_5 -> V_15 ) , & V_30 ) ;
if ( V_10 < 0 )
return V_10 ;
V_29 = ( V_30 >> 8 ) & 0xFFFF ;
if ( V_29 )
return V_29 ;
F_5 ( V_13 ) ;
} while ( F_6 ( V_8 , V_7 ) );
return - V_32 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_33 , T_3 V_34 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_35 = 0 , V_29 , V_10 ;
while ( V_35 < V_34 &&
F_20 ( V_2 ,
V_36 | V_37 ,
V_2 -> V_38 ,
& V_5 -> V_39 , true ) == 0 ) {
V_29 = F_21 ( int , F_17 ( V_2 ) , V_34 - V_35 ) ;
V_10 = F_22 ( V_5 , F_23 ( V_5 -> V_15 ) ,
V_29 , V_33 + V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
V_35 += V_29 ;
}
return V_35 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 * V_33 , T_3 V_34 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_35 = 0 ;
int V_40 , V_27 ;
if ( V_34 < V_41 ) {
V_35 = - V_42 ;
goto V_43;
}
V_35 = F_19 ( V_2 , V_33 , V_41 ) ;
if ( V_35 < V_41 ) {
F_25 ( & V_2 -> V_6 , L_1 ) ;
goto V_43;
}
V_40 = F_26 ( * ( V_44 * ) ( V_33 + 2 ) ) ;
if ( V_40 > V_34 ) {
V_35 = - V_42 ;
goto V_43;
}
V_35 += F_19 ( V_2 , & V_33 [ V_41 ] ,
V_40 - V_41 ) ;
if ( V_35 < V_40 ) {
F_25 ( & V_2 -> V_6 , L_2 ) ;
V_35 = - V_45 ;
goto V_43;
}
F_20 ( V_2 , V_37 , V_2 -> V_38 ,
& V_5 -> V_23 , false ) ;
V_27 = F_14 ( V_2 ) ;
if ( V_27 & V_36 ) {
F_25 ( & V_2 -> V_6 , L_3 ) ;
V_35 = - V_42 ;
goto V_43;
}
V_43:
F_16 ( V_2 ) ;
F_8 ( V_2 , V_5 -> V_15 , 0 ) ;
return V_35 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 * V_33 , T_3 V_46 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 , V_27 , V_29 ;
T_3 V_34 = 0 ;
bool V_47 = V_5 -> V_20 & V_48 ;
if ( F_10 ( V_2 , 0 ) < 0 )
return - V_32 ;
V_27 = F_14 ( V_2 ) ;
if ( ( V_27 & V_28 ) == 0 ) {
F_16 ( V_2 ) ;
if ( F_20
( V_2 , V_28 , V_2 -> V_49 ,
& V_5 -> V_23 , false ) < 0 ) {
V_10 = - V_45 ;
goto V_50;
}
}
while ( V_34 < V_46 - 1 ) {
V_29 = F_21 ( int , F_17 ( V_2 ) , V_46 - V_34 - 1 ) ;
V_10 = F_28 ( V_5 , F_23 ( V_5 -> V_15 ) ,
V_29 , V_33 + V_34 ) ;
if ( V_10 < 0 )
goto V_50;
V_34 += V_29 ;
F_20 ( V_2 , V_37 , V_2 -> V_38 ,
& V_5 -> V_23 , false ) ;
V_27 = F_14 ( V_2 ) ;
if ( ! V_47 && ( V_27 & V_51 ) == 0 ) {
V_10 = - V_42 ;
goto V_50;
}
}
V_10 = F_9 ( V_5 , F_23 ( V_5 -> V_15 ) , V_33 [ V_34 ] ) ;
if ( V_10 < 0 )
goto V_50;
F_20 ( V_2 , V_37 , V_2 -> V_38 ,
& V_5 -> V_23 , false ) ;
V_27 = F_14 ( V_2 ) ;
if ( ! V_47 && ( V_27 & V_51 ) != 0 ) {
V_10 = - V_42 ;
goto V_50;
}
return 0 ;
V_50:
F_16 ( V_2 ) ;
F_8 ( V_2 , V_5 -> V_15 , 0 ) ;
return V_10 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_2 V_52 ;
int V_10 ;
V_10 = F_18 ( V_5 , F_30 ( V_5 -> V_15 ) , & V_52 ) ;
if ( V_10 < 0 )
V_52 = 0 ;
V_52 &= ~ V_53 ;
V_10 = F_31 ( V_5 , F_30 ( V_5 -> V_15 ) , V_52 ) ;
F_32 ( V_2 -> V_6 . V_54 , V_5 -> V_55 , V_2 ) ;
V_5 -> V_55 = 0 ;
V_2 -> V_20 &= ~ V_21 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 * V_33 , T_3 V_46 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 ;
T_2 V_56 ;
unsigned long V_57 ;
V_10 = F_27 ( V_2 , V_33 , V_46 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_9 ( V_5 , F_15 ( V_5 -> V_15 ) , V_58 ) ;
if ( V_10 < 0 )
goto V_50;
if ( V_2 -> V_20 & V_21 ) {
V_56 = F_26 ( * ( ( V_44 * ) ( V_33 + 6 ) ) ) ;
if ( V_2 -> V_20 & V_59 )
V_57 = F_34 ( V_2 , V_56 ) ;
else
V_57 = F_35 ( V_2 , V_56 ) ;
if ( F_20
( V_2 , V_36 | V_37 , V_57 ,
& V_5 -> V_39 , false ) < 0 ) {
V_10 = - V_45 ;
goto V_50;
}
}
return V_46 ;
V_50:
F_16 ( V_2 ) ;
F_8 ( V_2 , V_5 -> V_15 , 0 ) ;
return V_10 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 * V_33 , T_3 V_46 )
{
int V_10 , V_55 ;
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
if ( ! ( V_2 -> V_20 & V_21 ) || V_5 -> V_60 )
return F_33 ( V_2 , V_33 , V_46 ) ;
V_55 = V_5 -> V_55 ;
V_5 -> V_55 = 0 ;
V_2 -> V_20 &= ~ V_21 ;
V_10 = F_33 ( V_2 , V_33 , V_46 ) ;
V_5 -> V_55 = V_55 ;
V_2 -> V_20 |= V_21 ;
if ( ! V_5 -> V_60 )
F_5 ( 1 ) ;
if ( ! V_5 -> V_60 )
F_29 ( V_2 ) ;
V_5 -> V_60 = true ;
return V_10 ;
}
static bool F_37 ( struct V_1 * V_2 ,
unsigned long * V_61 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_62 , V_10 ;
T_2 V_63 ;
V_10 = F_18 ( V_5 , F_38 ( 0 ) , & V_63 ) ;
if ( V_10 < 0 )
return V_10 ;
for ( V_62 = 0 ; V_62 != F_39 ( V_64 ) ; V_62 ++ ) {
if ( V_64 [ V_62 ] . V_63 != V_63 )
continue;
memcpy ( V_61 , V_64 [ V_62 ] . V_65 ,
sizeof( V_64 [ V_62 ] . V_65 ) ) ;
return true ;
}
return false ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 = 0 ;
T_1 V_66 [] = {
0x00 , 0xc1 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0xf1
} ;
T_3 V_46 = sizeof( V_66 ) ;
T_4 V_67 ;
V_10 = F_41 ( V_5 , F_38 ( 0 ) , & V_67 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_67 != V_68 )
return 0 ;
V_10 = F_27 ( V_2 , V_66 , V_46 ) ;
if ( V_10 == 0 )
goto V_43;
F_16 ( V_2 ) ;
F_8 ( V_2 , V_5 -> V_15 , 0 ) ;
V_10 = F_27 ( V_2 , V_66 , V_46 ) ;
if ( V_10 == 0 ) {
F_42 ( & V_2 -> V_6 , L_4 ) ;
V_10 = 1 ;
} else
V_10 = - V_69 ;
V_43:
F_16 ( V_2 ) ;
F_8 ( V_2 , V_5 -> V_15 , 0 ) ;
return V_10 ;
}
static bool F_43 ( struct V_1 * V_2 , T_1 V_27 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
switch ( V_5 -> V_70 ) {
case V_71 :
return ( ( V_27 == V_37 ) ||
( V_27 == ( V_37 | V_28 ) ) ) ;
case V_72 :
return ( V_27 == ( V_37 | V_28 ) ) ;
default:
return ( V_27 == V_28 ) ;
}
}
static T_5 F_44 ( int V_73 , void * V_74 )
{
struct V_1 * V_2 = V_74 ;
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_2 V_75 ;
int V_62 , V_10 ;
V_10 = F_18 ( V_5 , F_45 ( V_5 -> V_15 ) , & V_75 ) ;
if ( V_10 < 0 )
return V_76 ;
if ( V_75 == 0 )
return V_76 ;
V_5 -> V_60 = true ;
if ( V_75 & V_77 )
F_46 ( & V_5 -> V_39 ) ;
if ( V_75 & V_78 )
for ( V_62 = 0 ; V_62 < 5 ; V_62 ++ )
if ( F_7 ( V_2 , V_62 ) >= 0 )
break;
if ( V_75 &
( V_78 | V_79 |
V_80 ) )
F_46 ( & V_5 -> V_23 ) ;
V_10 = F_31 ( V_5 , F_45 ( V_5 -> V_15 ) , V_75 ) ;
if ( V_10 < 0 )
return V_76 ;
F_18 ( V_5 , F_45 ( V_5 -> V_15 ) , & V_75 ) ;
return V_81 ;
}
static int F_47 ( struct V_1 * V_2 )
{
const char * V_82 = L_5 ;
T_2 V_83 ;
T_6 V_84 ;
if ( V_2 -> V_20 & V_59 )
return F_48 ( V_2 , 0x100 , & V_83 , V_82 ) ;
else
return F_49 ( V_2 , V_85 , & V_84 , V_82 ) ;
}
static int F_50 ( struct V_1 * V_2 , T_2 V_52 ,
int V_20 , int V_55 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_1 V_86 ;
int V_10 ;
T_2 V_87 ;
if ( F_51 ( V_2 -> V_6 . V_54 , V_55 , F_44 , V_20 ,
F_52 ( & V_2 -> V_6 ) , V_2 ) != 0 ) {
F_42 ( & V_2 -> V_6 , L_6 ,
V_55 ) ;
return - 1 ;
}
V_5 -> V_55 = V_55 ;
V_10 = F_3 ( V_5 , F_53 ( V_5 -> V_15 ) ,
& V_86 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_9 ( V_5 , F_53 ( V_5 -> V_15 ) , V_55 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_5 , F_45 ( V_5 -> V_15 ) , & V_87 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_31 ( V_5 , F_45 ( V_5 -> V_15 ) , V_87 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_31 ( V_5 , F_30 ( V_5 -> V_15 ) ,
V_52 | V_53 ) ;
if ( V_10 < 0 )
return V_10 ;
V_5 -> V_60 = false ;
V_10 = F_47 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_2 -> V_20 & V_21 ) ) {
V_10 = F_9 ( V_5 , V_86 ,
F_53 ( V_5 -> V_15 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 1 ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 , T_2 V_52 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_1 V_86 ;
int V_62 , V_10 ;
V_10 = F_3 ( V_5 , F_53 ( V_5 -> V_15 ) ,
& V_86 ) ;
if ( V_10 < 0 )
return;
if ( ! V_86 ) {
if ( F_55 ( V_88 ) )
for ( V_62 = 3 ; V_62 <= 15 ; V_62 ++ )
if ( ! F_50 ( V_2 , V_52 , 0 ,
V_62 ) )
return;
} else if ( ! F_50 ( V_2 , V_52 , 0 ,
V_86 ) )
return;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_2 V_89 = F_30 ( V_5 -> V_15 ) ;
T_2 V_75 ;
int V_10 ;
V_10 = F_18 ( V_5 , V_89 , & V_75 ) ;
if ( V_10 < 0 )
V_75 = 0 ;
F_31 ( V_5 , V_89 , ~ V_53 & V_75 ) ;
F_8 ( V_2 , V_5 -> V_15 , 1 ) ;
}
int F_57 ( struct V_90 * V_6 , struct V_4 * V_5 , int V_55 ,
const struct V_91 * V_92 ,
T_7 V_93 )
{
T_2 V_67 , V_94 , V_52 ;
T_1 V_95 ;
int V_10 , V_96 ;
struct V_1 * V_2 ;
V_2 = F_58 ( V_6 , & V_97 ) ;
if ( F_59 ( V_2 ) )
return F_60 ( V_2 ) ;
#ifdef F_61
V_2 -> V_93 = V_93 ;
#endif
V_2 -> V_9 = F_62 ( V_98 ) ;
V_2 -> V_49 = F_62 ( V_99 ) ;
V_2 -> V_38 = F_62 ( V_100 ) ;
V_2 -> V_31 = F_62 ( V_101 ) ;
V_5 -> V_92 = V_92 ;
F_63 ( & V_2 -> V_6 , V_5 ) ;
if ( F_1 ( V_2 , 0 ) != 0 ) {
V_10 = - V_102 ;
goto V_50;
}
V_10 = F_18 ( V_5 , F_30 ( V_5 -> V_15 ) , & V_52 ) ;
if ( V_10 < 0 )
goto V_50;
V_52 |= V_80 | V_78 |
V_77 | V_79 ;
V_52 &= ~ V_53 ;
F_31 ( V_5 , F_30 ( V_5 -> V_15 ) , V_52 ) ;
if ( F_10 ( V_2 , 0 ) != 0 ) {
V_10 = - V_102 ;
goto V_50;
}
V_10 = F_64 ( V_2 ) ;
if ( V_10 )
goto V_50;
V_10 = F_18 ( V_5 , F_38 ( 0 ) , & V_67 ) ;
if ( V_10 < 0 )
goto V_50;
V_5 -> V_70 = V_67 ;
V_10 = F_3 ( V_5 , F_65 ( 0 ) , & V_95 ) ;
if ( V_10 < 0 )
goto V_50;
F_42 ( V_6 , L_7 ,
( V_2 -> V_20 & V_59 ) ? L_8 : L_9 ,
V_67 >> 16 , V_95 ) ;
if ( ! ( V_5 -> V_20 & V_48 ) ) {
V_96 = F_40 ( V_2 ) ;
if ( V_96 < 0 ) {
V_10 = - V_102 ;
goto V_50;
}
if ( ! ! V_96 )
V_5 -> V_20 |= V_48 ;
}
V_10 = F_18 ( V_5 , F_66 ( V_5 -> V_15 ) , & V_94 ) ;
if ( V_10 < 0 )
goto V_50;
F_67 ( V_6 , L_10 ,
V_94 ) ;
if ( V_94 & V_103 )
F_67 ( V_6 , L_11 ) ;
if ( V_94 & V_80 )
F_67 ( V_6 , L_12 ) ;
if ( V_94 & V_104 )
F_67 ( V_6 , L_13 ) ;
if ( V_94 & V_105 )
F_67 ( V_6 , L_14 ) ;
if ( V_94 & V_106 )
F_67 ( V_6 , L_15 ) ;
if ( V_94 & V_107 )
F_67 ( V_6 , L_16 ) ;
if ( V_94 & V_78 )
F_67 ( V_6 , L_17 ) ;
if ( V_94 & V_79 )
F_67 ( V_6 , L_18 ) ;
if ( V_94 & V_77 )
F_67 ( V_6 , L_19 ) ;
if ( F_68 ( V_2 ) ) {
F_25 ( V_6 , L_20 ) ;
V_10 = - V_102 ;
goto V_50;
}
F_69 ( & V_5 -> V_39 ) ;
F_69 ( & V_5 -> V_23 ) ;
if ( V_55 != - 1 ) {
if ( V_55 ) {
F_50 ( V_2 , V_52 , V_108 ,
V_55 ) ;
if ( ! ( V_2 -> V_20 & V_21 ) )
F_25 ( & V_2 -> V_6 , V_109
L_21 ) ;
} else {
F_54 ( V_2 , V_52 ) ;
}
}
return F_70 ( V_2 ) ;
V_50:
F_56 ( V_2 ) ;
return V_10 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_2 V_52 ;
int V_10 ;
V_10 = F_9 ( V_5 , F_53 ( V_5 -> V_15 ) , V_5 -> V_55 ) ;
if ( V_10 < 0 )
return;
V_10 = F_18 ( V_5 , F_30 ( V_5 -> V_15 ) , & V_52 ) ;
if ( V_10 < 0 )
return;
V_52 |= V_80
| V_78 | V_77
| V_79 | V_53 ;
F_31 ( V_5 , F_30 ( V_5 -> V_15 ) , V_52 ) ;
}
int F_72 ( struct V_90 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
int V_110 ;
if ( V_2 -> V_20 & V_21 )
F_71 ( V_2 ) ;
V_110 = F_73 ( V_6 ) ;
if ( V_110 )
return V_110 ;
if ( ! ( V_2 -> V_20 & V_59 ) )
F_74 ( V_2 ) ;
return 0 ;
}
