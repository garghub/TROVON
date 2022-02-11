static void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
static unsigned int F_3 ( void T_2 * V_2 )
{
return F_4 ( V_2 ) ;
}
static void F_5 ( T_1 V_1 , void T_2 * V_2 )
{
F_6 ( V_1 , V_2 ) ;
}
static unsigned int F_7 ( void T_2 * V_2 )
{
return F_8 ( V_2 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
if ( ! V_4 -> V_6 ) {
V_4 -> V_7 ( 0 , V_4 -> V_8 + V_9 ) ;
return;
}
switch ( V_4 -> V_10 ) {
case 1 :
V_5 = * ( V_11 * ) ( V_4 -> V_6 ) ;
break;
case 2 :
V_5 = * ( V_12 * ) ( V_4 -> V_6 ) ;
break;
case 4 :
V_5 = * ( T_1 * ) ( V_4 -> V_6 ) ;
break;
}
V_4 -> V_7 ( V_5 , V_4 -> V_8 + V_9 ) ;
V_4 -> V_6 += V_4 -> V_10 ;
}
static void F_10 ( struct V_3 * V_4 )
{
T_1 V_5 = V_4 -> V_13 ( V_4 -> V_8 + V_14 ) ;
if ( ! V_4 -> V_15 )
return;
switch ( V_4 -> V_10 ) {
case 1 :
* ( V_11 * ) ( V_4 -> V_15 ) = V_5 ;
break;
case 2 :
* ( V_12 * ) ( V_4 -> V_15 ) = V_5 ;
break;
case 4 :
* ( T_1 * ) ( V_4 -> V_15 ) = V_5 ;
break;
}
V_4 -> V_15 += V_4 -> V_10 ;
}
static void F_11 ( struct V_3 * V_4 )
{
void T_2 * V_16 = V_4 -> V_8 ;
V_4 -> V_7 ( V_17 ,
V_16 + V_18 ) ;
V_4 -> V_7 ( V_19 ,
V_16 + V_20 ) ;
V_4 -> V_7 ( 0 , V_16 + V_21 ) ;
V_4 -> V_7 ( 0xffff , V_16 + V_22 ) ;
V_4 -> V_7 ( V_23 | V_24 |
V_25 | V_26 | V_27 ,
V_16 + V_28 ) ;
}
static void F_12 ( struct V_29 * V_30 , int V_31 )
{
struct V_3 * V_4 = F_13 ( V_30 -> V_32 ) ;
V_12 V_33 ;
T_1 V_34 ;
if ( V_31 == V_35 ) {
V_4 -> V_7 ( V_4 -> V_36 , V_4 -> V_8 + V_22 ) ;
return;
}
V_33 = V_4 -> V_13 ( V_4 -> V_8 + V_28 ) & ~ V_37 ;
if ( V_30 -> V_38 & V_39 )
V_33 |= V_40 ;
if ( V_30 -> V_38 & V_41 )
V_33 |= V_42 ;
if ( V_30 -> V_38 & V_43 )
V_33 |= V_44 ;
if ( V_30 -> V_38 & V_45 )
V_33 |= V_46 ;
V_4 -> V_7 ( V_33 , V_4 -> V_8 + V_28 ) ;
V_34 = V_4 -> V_36 ;
V_34 ^= F_14 ( V_30 -> V_47 ) ;
V_4 -> V_7 ( V_34 , V_4 -> V_8 + V_22 ) ;
}
static int F_15 ( struct V_29 * V_30 ,
struct V_48 * V_49 )
{
struct V_3 * V_4 = F_13 ( V_30 -> V_32 ) ;
if ( V_30 -> V_38 & V_50 )
V_4 -> V_36 &= ~ F_14 ( V_30 -> V_47 ) ;
else
V_4 -> V_36 |= F_14 ( V_30 -> V_47 ) ;
return 0 ;
}
static int F_16 ( struct V_29 * V_30 , struct V_48 * V_49 )
{
struct V_3 * V_4 = F_13 ( V_30 -> V_32 ) ;
int V_51 ;
bool V_52 = false ;
V_12 V_33 = 0 ;
V_4 -> V_6 = V_49 -> V_53 ;
V_4 -> V_15 = V_49 -> V_54 ;
V_51 = V_49 -> V_55 / V_4 -> V_10 ;
if ( V_4 -> V_56 >= 0 && V_51 > V_4 -> V_57 ) {
T_1 V_58 ;
V_52 = true ;
V_33 = V_4 -> V_13 ( V_4 -> V_8 + V_28 ) ;
V_4 -> V_7 ( V_33 | V_59 ,
V_4 -> V_8 + V_28 ) ;
V_58 = V_4 -> V_13 ( V_4 -> V_8 + V_60 ) ;
if ( V_58 )
V_4 -> V_7 ( V_58 ,
V_4 -> V_8 + V_60 ) ;
V_4 -> V_7 ( V_61 ,
V_4 -> V_8 + V_21 ) ;
F_17 ( & V_4 -> V_62 ) ;
}
while ( V_51 ) {
int V_63 , V_64 , V_65 ;
T_1 V_66 ;
V_63 = F_18 ( V_51 , V_4 -> V_57 ) ;
V_64 = V_63 ;
while ( V_64 -- )
F_9 ( V_4 ) ;
if ( V_52 ) {
V_4 -> V_7 ( V_33 , V_4 -> V_8 + V_28 ) ;
F_19 ( & V_4 -> V_62 ) ;
V_4 -> V_7 ( V_33 | V_59 ,
V_4 -> V_8 + V_28 ) ;
V_66 = V_67 ;
} else
V_66 = V_4 -> V_13 ( V_4 -> V_8 + V_68 ) ;
V_65 = V_63 ;
while ( V_65 ) {
if ( ( V_66 & V_67 ) && ( V_65 > 1 ) ) {
F_10 ( V_4 ) ;
V_65 -- ;
continue;
}
V_66 = V_4 -> V_13 ( V_4 -> V_8 + V_68 ) ;
if ( ! ( V_66 & V_69 ) ) {
F_10 ( V_4 ) ;
V_65 -- ;
}
}
V_51 -= V_63 ;
}
if ( V_52 ) {
V_4 -> V_7 ( 0 , V_4 -> V_8 + V_21 ) ;
V_4 -> V_7 ( V_33 , V_4 -> V_8 + V_28 ) ;
}
return V_49 -> V_55 ;
}
static T_3 F_20 ( int V_56 , void * V_70 )
{
struct V_3 * V_4 = V_70 ;
T_1 V_71 ;
V_71 = V_4 -> V_13 ( V_4 -> V_8 + V_60 ) ;
V_4 -> V_7 ( V_71 , V_4 -> V_8 + V_60 ) ;
if ( V_71 & V_19 ) {
F_21 ( & V_4 -> V_62 ) ;
return V_72 ;
}
return V_73 ;
}
static int F_22 ( struct V_3 * V_4 )
{
V_11 V_66 ;
int V_63 = 0 ;
V_4 -> V_7 ( V_17 ,
V_4 -> V_8 + V_18 ) ;
do {
V_4 -> V_7 ( 0 , V_4 -> V_8 + V_9 ) ;
V_66 = V_4 -> V_13 ( V_4 -> V_8 + V_68 ) ;
V_63 ++ ;
} while ( ! ( V_66 & V_74 ) );
return V_63 ;
}
static int F_23 ( struct V_75 * V_76 )
{
struct V_3 * V_4 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
int V_81 , V_82 = 0 , V_83 = 8 ;
struct V_84 * V_32 ;
T_1 V_85 ;
V_11 V_86 ;
V_78 = F_24 ( & V_76 -> V_87 ) ;
if ( V_78 ) {
V_82 = V_78 -> V_88 ;
V_83 = V_78 -> V_83 ;
} else {
F_25 ( V_76 -> V_87 . V_89 , L_1 ,
& V_82 ) ;
}
if ( ! V_82 ) {
F_26 ( & V_76 -> V_87 ,
L_2 ) ;
return - V_90 ;
}
if ( V_82 > V_91 ) {
F_26 ( & V_76 -> V_87 , L_3 ) ;
return - V_90 ;
}
V_32 = F_27 ( & V_76 -> V_87 , sizeof( struct V_3 ) ) ;
if ( ! V_32 )
return - V_92 ;
V_32 -> V_93 = V_41 | V_39 | V_43 | V_45 |
V_50 ;
V_4 = F_13 ( V_32 ) ;
V_4 -> V_36 = 0xffffffff ;
V_4 -> V_94 . V_32 = V_32 ;
V_4 -> V_94 . V_95 = F_12 ;
V_4 -> V_94 . V_96 = F_15 ;
V_4 -> V_94 . V_97 = F_16 ;
F_28 ( & V_4 -> V_62 ) ;
V_80 = F_29 ( V_76 , V_98 , 0 ) ;
V_4 -> V_8 = F_30 ( & V_76 -> V_87 , V_80 ) ;
if ( F_31 ( V_4 -> V_8 ) ) {
V_81 = F_32 ( V_4 -> V_8 ) ;
goto V_99;
}
V_32 -> V_100 = V_76 -> V_101 ;
V_32 -> V_88 = V_82 ;
V_32 -> V_87 . V_89 = V_76 -> V_87 . V_89 ;
V_4 -> V_13 = F_3 ;
V_4 -> V_7 = F_1 ;
V_4 -> V_7 ( V_46 , V_4 -> V_8 + V_28 ) ;
V_85 = V_4 -> V_13 ( V_4 -> V_8 + V_28 ) ;
V_85 &= V_46 ;
if ( V_85 != V_46 ) {
V_4 -> V_13 = F_7 ;
V_4 -> V_7 = F_5 ;
}
V_32 -> V_102 = F_33 ( V_83 ) ;
V_4 -> V_10 = V_83 / 8 ;
V_4 -> V_57 = F_22 ( V_4 ) ;
V_4 -> V_56 = F_34 ( V_76 , 0 ) ;
if ( V_4 -> V_56 < 0 && V_4 -> V_56 != - V_103 ) {
V_81 = V_4 -> V_56 ;
goto V_99;
} else if ( V_4 -> V_56 >= 0 ) {
V_81 = F_35 ( & V_76 -> V_87 , V_4 -> V_56 , F_20 , 0 ,
F_36 ( & V_76 -> V_87 ) , V_4 ) ;
if ( V_81 )
goto V_99;
}
F_11 ( V_4 ) ;
V_81 = F_37 ( & V_4 -> V_94 ) ;
if ( V_81 ) {
F_26 ( & V_76 -> V_87 , L_4 ) ;
goto V_99;
}
F_38 ( & V_76 -> V_87 , L_5 ,
( unsigned long long ) V_80 -> V_104 , V_4 -> V_8 , V_4 -> V_56 ) ;
if ( V_78 ) {
for ( V_86 = 0 ; V_86 < V_78 -> V_105 ; V_86 ++ )
F_39 ( V_32 , V_78 -> V_106 + V_86 ) ;
}
F_40 ( V_76 , V_32 ) ;
return 0 ;
V_99:
F_41 ( V_32 ) ;
return V_81 ;
}
static int F_42 ( struct V_75 * V_76 )
{
struct V_84 * V_32 = F_43 ( V_76 ) ;
struct V_3 * V_4 = F_13 ( V_32 ) ;
void T_2 * V_16 = V_4 -> V_8 ;
F_44 ( & V_4 -> V_94 ) ;
V_4 -> V_7 ( 0 , V_16 + V_20 ) ;
V_4 -> V_7 ( 0 , V_16 + V_21 ) ;
F_41 ( V_4 -> V_94 . V_32 ) ;
return 0 ;
}
