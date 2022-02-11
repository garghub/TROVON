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
static bool F_7 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 ;
T_1 V_11 ;
V_10 = F_3 ( V_5 , F_4 ( V_3 ) , & V_11 ) ;
if ( V_10 < 0 )
return false ;
if ( ( V_11 & ( V_14 | V_12 ) ) ==
( V_14 | V_12 ) ) {
V_5 -> V_15 = V_3 ;
return true ;
}
return false ;
}
static void F_8 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
F_9 ( V_5 , F_4 ( V_3 ) , V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
unsigned long V_7 , V_16 ;
long V_10 ;
if ( F_7 ( V_2 , V_3 ) )
return V_3 ;
V_10 = F_9 ( V_5 , F_4 ( V_3 ) , V_17 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 = V_8 + V_2 -> V_9 ;
if ( V_2 -> V_18 & V_19 ) {
V_20:
V_16 = V_7 - V_8 ;
if ( ( long ) V_16 <= 0 )
return - 1 ;
V_10 = F_11 ( V_5 -> V_21 ,
( F_7
( V_2 , V_3 ) ) ,
V_16 ) ;
if ( V_10 > 0 )
return V_3 ;
if ( V_10 == - V_22 && F_12 ( V_23 ) ) {
F_13 ( V_24 ) ;
goto V_20;
}
} else {
do {
if ( F_7 ( V_2 , V_3 ) )
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
T_1 V_25 ;
V_10 = F_3 ( V_5 , F_15 ( V_5 -> V_15 ) , & V_25 ) ;
if ( V_10 < 0 )
return 0 ;
return V_25 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
F_9 ( V_5 , F_15 ( V_5 -> V_15 ) , V_26 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
unsigned long V_7 ;
int V_27 , V_10 ;
T_2 V_28 ;
if ( V_2 -> V_18 & V_29 )
V_7 = V_8 + V_2 -> V_9 ;
else
V_7 = V_8 + V_2 -> V_30 ;
do {
V_10 = F_18 ( V_5 , F_15 ( V_5 -> V_15 ) , & V_28 ) ;
if ( V_10 < 0 )
return V_10 ;
V_27 = ( V_28 >> 8 ) & 0xFFFF ;
if ( V_27 )
return V_27 ;
F_5 ( V_13 ) ;
} while ( F_6 ( V_8 , V_7 ) );
return - V_31 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_32 , T_3 V_33 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_34 = 0 , V_27 , V_10 ;
while ( V_34 < V_33 ) {
V_10 = F_20 ( V_2 ,
V_35 | V_36 ,
V_2 -> V_37 ,
& V_5 -> V_38 , true ) ;
if ( V_10 < 0 )
return V_10 ;
V_27 = F_17 ( V_2 ) ;
if ( V_27 < 0 ) {
F_21 ( & V_2 -> V_6 , L_1 ) ;
return V_27 ;
}
V_27 = F_22 ( int , V_27 , V_33 - V_34 ) ;
V_10 = F_23 ( V_5 , F_24 ( V_5 -> V_15 ) ,
V_27 , V_32 + V_34 ) ;
if ( V_10 < 0 )
return V_10 ;
V_34 += V_27 ;
}
return V_34 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 * V_32 , T_3 V_33 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_34 = 0 ;
int V_39 , V_25 ;
if ( V_33 < V_40 ) {
V_34 = - V_41 ;
goto V_42;
}
V_34 = F_19 ( V_2 , V_32 , V_40 ) ;
if ( V_34 < V_40 ) {
F_21 ( & V_2 -> V_6 , L_2 ) ;
goto V_42;
}
V_39 = F_26 ( * ( V_43 * ) ( V_32 + 2 ) ) ;
if ( V_39 > V_33 ) {
V_34 = - V_41 ;
goto V_42;
}
V_34 += F_19 ( V_2 , & V_32 [ V_40 ] ,
V_39 - V_40 ) ;
if ( V_34 < V_39 ) {
F_21 ( & V_2 -> V_6 , L_3 ) ;
V_34 = - V_44 ;
goto V_42;
}
if ( F_20 ( V_2 , V_36 , V_2 -> V_37 ,
& V_5 -> V_21 , false ) < 0 ) {
V_34 = - V_44 ;
goto V_42;
}
V_25 = F_14 ( V_2 ) ;
if ( V_25 & V_35 ) {
F_21 ( & V_2 -> V_6 , L_4 ) ;
V_34 = - V_41 ;
goto V_42;
}
V_42:
F_16 ( V_2 ) ;
return V_34 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 * V_32 , T_3 V_45 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 , V_25 , V_27 ;
T_3 V_33 = 0 ;
bool V_46 = V_5 -> V_18 & V_47 ;
V_25 = F_14 ( V_2 ) ;
if ( ( V_25 & V_26 ) == 0 ) {
F_16 ( V_2 ) ;
if ( F_20
( V_2 , V_26 , V_2 -> V_48 ,
& V_5 -> V_21 , false ) < 0 ) {
V_10 = - V_44 ;
goto V_49;
}
}
while ( V_33 < V_45 - 1 ) {
V_27 = F_17 ( V_2 ) ;
if ( V_27 < 0 ) {
F_21 ( & V_2 -> V_6 , L_1 ) ;
V_10 = V_27 ;
goto V_49;
}
V_27 = F_22 ( int , V_27 , V_45 - V_33 - 1 ) ;
V_10 = F_28 ( V_5 , F_24 ( V_5 -> V_15 ) ,
V_27 , V_32 + V_33 ) ;
if ( V_10 < 0 )
goto V_49;
V_33 += V_27 ;
if ( F_20 ( V_2 , V_36 , V_2 -> V_37 ,
& V_5 -> V_21 , false ) < 0 ) {
V_10 = - V_44 ;
goto V_49;
}
V_25 = F_14 ( V_2 ) ;
if ( ! V_46 && ( V_25 & V_50 ) == 0 ) {
V_10 = - V_41 ;
goto V_49;
}
}
V_10 = F_9 ( V_5 , F_24 ( V_5 -> V_15 ) , V_32 [ V_33 ] ) ;
if ( V_10 < 0 )
goto V_49;
if ( F_20 ( V_2 , V_36 , V_2 -> V_37 ,
& V_5 -> V_21 , false ) < 0 ) {
V_10 = - V_44 ;
goto V_49;
}
V_25 = F_14 ( V_2 ) ;
if ( ! V_46 && ( V_25 & V_50 ) != 0 ) {
V_10 = - V_41 ;
goto V_49;
}
return 0 ;
V_49:
F_16 ( V_2 ) ;
return V_10 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_2 V_51 ;
int V_10 ;
V_10 = F_18 ( V_5 , F_30 ( V_5 -> V_15 ) , & V_51 ) ;
if ( V_10 < 0 )
V_51 = 0 ;
V_51 &= ~ V_52 ;
V_10 = F_31 ( V_5 , F_30 ( V_5 -> V_15 ) , V_51 ) ;
F_32 ( V_2 -> V_6 . V_53 , V_5 -> V_54 , V_2 ) ;
V_5 -> V_54 = 0 ;
V_2 -> V_18 &= ~ V_19 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 * V_32 , T_3 V_45 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 ;
T_2 V_55 ;
unsigned long V_56 ;
V_10 = F_27 ( V_2 , V_32 , V_45 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_9 ( V_5 , F_15 ( V_5 -> V_15 ) , V_57 ) ;
if ( V_10 < 0 )
goto V_49;
if ( V_2 -> V_18 & V_19 ) {
V_55 = F_26 ( * ( ( V_43 * ) ( V_32 + 6 ) ) ) ;
if ( V_2 -> V_18 & V_29 )
V_56 = F_34 ( V_2 , V_55 ) ;
else
V_56 = F_35 ( V_2 , V_55 ) ;
if ( F_20
( V_2 , V_35 | V_36 , V_56 ,
& V_5 -> V_38 , false ) < 0 ) {
V_10 = - V_44 ;
goto V_49;
}
}
return V_45 ;
V_49:
F_16 ( V_2 ) ;
return V_10 ;
}
static int F_36 ( struct V_1 * V_2 , T_1 * V_32 , T_3 V_45 )
{
int V_10 , V_54 ;
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
if ( ! ( V_2 -> V_18 & V_19 ) || V_5 -> V_58 )
return F_33 ( V_2 , V_32 , V_45 ) ;
V_54 = V_5 -> V_54 ;
V_5 -> V_54 = 0 ;
V_2 -> V_18 &= ~ V_19 ;
V_10 = F_33 ( V_2 , V_32 , V_45 ) ;
V_5 -> V_54 = V_54 ;
V_2 -> V_18 |= V_19 ;
if ( ! V_5 -> V_58 )
F_5 ( 1 ) ;
if ( ! V_5 -> V_58 )
F_29 ( V_2 ) ;
V_5 -> V_58 = true ;
return V_10 ;
}
static bool F_37 ( struct V_1 * V_2 ,
unsigned long * V_59 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_60 , V_10 ;
T_2 V_61 ;
V_10 = F_18 ( V_5 , F_38 ( 0 ) , & V_61 ) ;
if ( V_10 < 0 )
return V_10 ;
for ( V_60 = 0 ; V_60 != F_39 ( V_62 ) ; V_60 ++ ) {
if ( V_62 [ V_60 ] . V_61 != V_61 )
continue;
memcpy ( V_59 , V_62 [ V_60 ] . V_63 ,
sizeof( V_62 [ V_60 ] . V_63 ) ) ;
return true ;
}
return false ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_10 = 0 ;
T_1 V_64 [] = {
0x00 , 0xc1 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0xf1
} ;
T_3 V_45 = sizeof( V_64 ) ;
T_4 V_65 ;
if ( V_5 -> V_18 & V_47 )
return 0 ;
V_10 = F_41 ( V_5 , F_38 ( 0 ) , & V_65 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_65 != V_66 )
return 0 ;
if ( F_10 ( V_2 , 0 ) != 0 )
return - V_31 ;
V_10 = F_27 ( V_2 , V_64 , V_45 ) ;
if ( V_10 == 0 )
goto V_42;
F_16 ( V_2 ) ;
V_5 -> V_18 |= V_47 ;
V_10 = F_27 ( V_2 , V_64 , V_45 ) ;
if ( V_10 == 0 )
F_42 ( & V_2 -> V_6 , L_5 ) ;
else {
V_5 -> V_18 &= ~ V_47 ;
V_10 = - V_67 ;
}
V_42:
F_16 ( V_2 ) ;
F_8 ( V_2 , V_5 -> V_15 ) ;
return V_10 ;
}
static bool F_43 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
switch ( V_5 -> V_68 ) {
case V_69 :
return ( ( V_25 == V_36 ) ||
( V_25 == ( V_36 | V_26 ) ) ) ;
case V_70 :
return ( V_25 == ( V_36 | V_26 ) ) ;
default:
return ( V_25 == V_26 ) ;
}
}
static T_5 F_44 ( int V_71 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_2 V_73 ;
int V_60 , V_10 ;
V_10 = F_18 ( V_5 , F_45 ( V_5 -> V_15 ) , & V_73 ) ;
if ( V_10 < 0 )
return V_74 ;
if ( V_73 == 0 )
return V_74 ;
V_5 -> V_58 = true ;
if ( V_73 & V_75 )
F_46 ( & V_5 -> V_38 ) ;
if ( V_73 & V_76 )
for ( V_60 = 0 ; V_60 < 5 ; V_60 ++ )
if ( F_7 ( V_2 , V_60 ) )
break;
if ( V_73 &
( V_76 | V_77 |
V_78 ) )
F_46 ( & V_5 -> V_21 ) ;
V_10 = F_31 ( V_5 , F_45 ( V_5 -> V_15 ) , V_73 ) ;
if ( V_10 < 0 )
return V_74 ;
F_18 ( V_5 , F_45 ( V_5 -> V_15 ) , & V_73 ) ;
return V_79 ;
}
static int F_47 ( struct V_1 * V_2 )
{
const char * V_80 = L_6 ;
T_2 V_81 ;
T_6 V_82 ;
if ( V_2 -> V_18 & V_29 )
return F_48 ( V_2 , 0x100 , & V_81 , V_80 ) ;
else
return F_49 ( V_2 , V_83 , & V_82 , V_80 ,
0 ) ;
}
static int F_50 ( struct V_1 * V_2 , T_2 V_51 ,
int V_18 , int V_54 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_1 V_84 ;
int V_10 ;
T_2 V_85 ;
if ( F_51 ( V_2 -> V_6 . V_53 , V_54 , F_44 , V_18 ,
F_52 ( & V_2 -> V_6 ) , V_2 ) != 0 ) {
F_42 ( & V_2 -> V_6 , L_7 ,
V_54 ) ;
return - 1 ;
}
V_5 -> V_54 = V_54 ;
V_10 = F_3 ( V_5 , F_53 ( V_5 -> V_15 ) ,
& V_84 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_9 ( V_5 , F_53 ( V_5 -> V_15 ) , V_54 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_18 ( V_5 , F_45 ( V_5 -> V_15 ) , & V_85 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_31 ( V_5 , F_45 ( V_5 -> V_15 ) , V_85 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_31 ( V_5 , F_30 ( V_5 -> V_15 ) ,
V_51 | V_52 ) ;
if ( V_10 < 0 )
return V_10 ;
V_5 -> V_58 = false ;
V_10 = F_47 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_2 -> V_18 & V_19 ) ) {
V_10 = F_9 ( V_5 , V_84 ,
F_53 ( V_5 -> V_15 ) ) ;
if ( V_10 < 0 )
return V_10 ;
return 1 ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 , T_2 V_51 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_1 V_84 ;
int V_60 , V_10 ;
V_10 = F_3 ( V_5 , F_53 ( V_5 -> V_15 ) ,
& V_84 ) ;
if ( V_10 < 0 )
return;
if ( ! V_84 ) {
if ( F_55 ( V_86 ) )
for ( V_60 = 3 ; V_60 <= 15 ; V_60 ++ )
if ( ! F_50 ( V_2 , V_51 , 0 ,
V_60 ) )
return;
} else if ( ! F_50 ( V_2 , V_51 , 0 ,
V_84 ) )
return;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_2 V_87 = F_30 ( V_5 -> V_15 ) ;
T_2 V_73 ;
int V_10 ;
V_10 = F_18 ( V_5 , V_87 , & V_73 ) ;
if ( V_10 < 0 )
V_73 = 0 ;
F_31 ( V_5 , V_87 , ~ V_52 & V_73 ) ;
}
int F_57 ( struct V_88 * V_6 , struct V_4 * V_5 , int V_54 ,
const struct V_89 * V_90 ,
T_7 V_91 )
{
T_2 V_65 , V_92 , V_51 ;
T_1 V_93 ;
int V_10 , V_94 ;
struct V_1 * V_2 ;
V_2 = F_58 ( V_6 , & V_95 ) ;
if ( F_59 ( V_2 ) )
return F_60 ( V_2 ) ;
#ifdef F_61
V_2 -> V_91 = V_91 ;
#endif
V_2 -> V_9 = F_62 ( V_96 ) ;
V_2 -> V_48 = F_62 ( V_97 ) ;
V_2 -> V_37 = F_62 ( V_98 ) ;
V_2 -> V_30 = F_62 ( V_99 ) ;
V_5 -> V_90 = V_90 ;
F_63 ( & V_2 -> V_6 , V_5 ) ;
if ( F_1 ( V_2 , 0 ) != 0 ) {
V_10 = - V_100 ;
goto V_49;
}
V_10 = F_18 ( V_5 , F_30 ( V_5 -> V_15 ) , & V_51 ) ;
if ( V_10 < 0 )
goto V_49;
V_51 |= V_78 | V_76 |
V_75 | V_77 ;
V_51 &= ~ V_52 ;
F_31 ( V_5 , F_30 ( V_5 -> V_15 ) , V_51 ) ;
V_10 = F_64 ( V_2 ) ;
if ( V_10 )
goto V_49;
V_10 = F_18 ( V_5 , F_38 ( 0 ) , & V_65 ) ;
if ( V_10 < 0 )
goto V_49;
V_5 -> V_68 = V_65 ;
V_10 = F_3 ( V_5 , F_65 ( 0 ) , & V_93 ) ;
if ( V_10 < 0 )
goto V_49;
F_42 ( V_6 , L_8 ,
( V_2 -> V_18 & V_29 ) ? L_9 : L_10 ,
V_65 >> 16 , V_93 ) ;
V_94 = F_40 ( V_2 ) ;
if ( V_94 < 0 ) {
V_10 = - V_100 ;
goto V_49;
}
V_10 = F_18 ( V_5 , F_66 ( V_5 -> V_15 ) , & V_92 ) ;
if ( V_10 < 0 )
goto V_49;
F_67 ( V_6 , L_11 ,
V_92 ) ;
if ( V_92 & V_101 )
F_67 ( V_6 , L_12 ) ;
if ( V_92 & V_78 )
F_67 ( V_6 , L_13 ) ;
if ( V_92 & V_102 )
F_67 ( V_6 , L_14 ) ;
if ( V_92 & V_103 )
F_67 ( V_6 , L_15 ) ;
if ( V_92 & V_104 )
F_67 ( V_6 , L_16 ) ;
if ( V_92 & V_105 )
F_67 ( V_6 , L_17 ) ;
if ( V_92 & V_76 )
F_67 ( V_6 , L_18 ) ;
if ( V_92 & V_77 )
F_67 ( V_6 , L_19 ) ;
if ( V_92 & V_75 )
F_67 ( V_6 , L_20 ) ;
F_68 ( & V_5 -> V_38 ) ;
F_68 ( & V_5 -> V_21 ) ;
if ( V_54 != - 1 ) {
if ( F_69 ( V_2 ) ) {
F_21 ( V_6 , L_21 ) ;
V_10 = - V_100 ;
goto V_49;
}
if ( V_54 ) {
F_50 ( V_2 , V_51 , V_106 ,
V_54 ) ;
if ( ! ( V_2 -> V_18 & V_19 ) )
F_21 ( & V_2 -> V_6 , V_107
L_22 ) ;
} else {
F_54 ( V_2 , V_51 ) ;
}
}
return F_70 ( V_2 ) ;
V_49:
F_56 ( V_2 ) ;
return V_10 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
T_2 V_51 ;
int V_10 ;
V_10 = F_9 ( V_5 , F_53 ( V_5 -> V_15 ) , V_5 -> V_54 ) ;
if ( V_10 < 0 )
return;
V_10 = F_18 ( V_5 , F_30 ( V_5 -> V_15 ) , & V_51 ) ;
if ( V_10 < 0 )
return;
V_51 |= V_78
| V_76 | V_75
| V_77 | V_52 ;
F_31 ( V_5 , F_30 ( V_5 -> V_15 ) , V_51 ) ;
}
int F_72 ( struct V_88 * V_6 )
{
struct V_1 * V_2 = F_2 ( V_6 ) ;
int V_108 ;
if ( V_2 -> V_18 & V_19 )
F_71 ( V_2 ) ;
V_108 = F_73 ( V_6 ) ;
if ( V_108 )
return V_108 ;
if ( ! ( V_2 -> V_18 & V_29 ) )
F_74 ( V_2 ) ;
return 0 ;
}
