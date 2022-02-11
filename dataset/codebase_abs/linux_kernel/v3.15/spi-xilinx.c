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
V_4 -> V_5 ( * V_4 -> V_6 , V_4 -> V_7 + V_8 ) ;
V_4 -> V_6 ++ ;
}
static void F_10 ( struct V_3 * V_4 )
{
V_4 -> V_5 ( * ( V_9 * ) ( V_4 -> V_6 ) , V_4 -> V_7 + V_8 ) ;
V_4 -> V_6 += 2 ;
}
static void F_11 ( struct V_3 * V_4 )
{
V_4 -> V_5 ( * ( T_1 * ) ( V_4 -> V_6 ) , V_4 -> V_7 + V_8 ) ;
V_4 -> V_6 += 4 ;
}
static void F_12 ( struct V_3 * V_4 )
{
T_1 V_10 = V_4 -> V_11 ( V_4 -> V_7 + V_12 ) ;
if ( V_4 -> V_13 ) {
* V_4 -> V_13 = V_10 & 0xff ;
V_4 -> V_13 ++ ;
}
}
static void F_13 ( struct V_3 * V_4 )
{
T_1 V_10 = V_4 -> V_11 ( V_4 -> V_7 + V_12 ) ;
if ( V_4 -> V_13 ) {
* ( V_9 * ) ( V_4 -> V_13 ) = V_10 & 0xffff ;
V_4 -> V_13 += 2 ;
}
}
static void F_14 ( struct V_3 * V_4 )
{
T_1 V_10 = V_4 -> V_11 ( V_4 -> V_7 + V_12 ) ;
if ( V_4 -> V_13 ) {
* ( T_1 * ) ( V_4 -> V_13 ) = V_10 ;
V_4 -> V_13 += 4 ;
}
}
static void F_15 ( struct V_3 * V_4 )
{
void T_2 * V_14 = V_4 -> V_7 ;
V_4 -> V_5 ( V_15 ,
V_14 + V_16 ) ;
V_4 -> V_5 ( 0 , V_14 + V_17 ) ;
V_4 -> V_5 ( V_18 ,
V_14 + V_19 ) ;
V_4 -> V_5 ( 0xffff , V_14 + V_20 ) ;
V_4 -> V_5 ( V_21 | V_22 |
V_23 | V_24 | V_25 |
V_26 , V_14 + V_27 ) ;
}
static void F_16 ( struct V_28 * V_29 , int V_30 )
{
struct V_3 * V_4 = F_17 ( V_29 -> V_31 ) ;
if ( V_30 == V_32 ) {
V_4 -> V_5 ( 0xffff , V_4 -> V_7 + V_20 ) ;
} else if ( V_30 == V_33 ) {
V_9 V_34 = V_4 -> V_11 ( V_4 -> V_7 + V_27 )
& ~ V_35 ;
if ( V_29 -> V_36 & V_37 )
V_34 |= V_38 ;
if ( V_29 -> V_36 & V_39 )
V_34 |= V_40 ;
V_4 -> V_5 ( V_34 , V_4 -> V_7 + V_27 ) ;
V_4 -> V_5 ( ~ ( 0x0001 << V_29 -> V_41 ) ,
V_4 -> V_7 + V_20 ) ;
}
}
static int F_18 ( struct V_28 * V_29 ,
struct V_42 * V_43 )
{
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
T_3 V_44 ;
V_44 = V_4 -> V_11 ( V_4 -> V_7 + V_45 ) ;
while ( ( V_44 & V_46 ) == 0 && V_4 -> V_47 > 0 ) {
if ( V_4 -> V_6 )
V_4 -> V_48 ( V_4 ) ;
else
V_4 -> V_5 ( 0 , V_4 -> V_7 + V_8 ) ;
V_4 -> V_47 -= V_4 -> V_49 / 8 ;
V_44 = V_4 -> V_11 ( V_4 -> V_7 + V_45 ) ;
}
}
static int F_20 ( struct V_28 * V_29 , struct V_42 * V_43 )
{
struct V_3 * V_4 = F_17 ( V_29 -> V_31 ) ;
T_1 V_50 ;
V_4 -> V_6 = V_43 -> V_51 ;
V_4 -> V_13 = V_43 -> V_52 ;
V_4 -> V_47 = V_43 -> V_53 ;
F_21 ( & V_4 -> V_54 ) ;
V_50 = V_4 -> V_11 ( V_4 -> V_7 + V_17 ) ;
V_4 -> V_5 ( V_50 | V_55 ,
V_4 -> V_7 + V_17 ) ;
for (; ; ) {
V_9 V_34 ;
T_3 V_44 ;
F_19 ( V_4 ) ;
V_34 = V_4 -> V_11 ( V_4 -> V_7 + V_27 ) &
~ V_21 ;
V_4 -> V_5 ( V_34 , V_4 -> V_7 + V_27 ) ;
F_22 ( & V_4 -> V_54 ) ;
V_34 = V_4 -> V_11 ( V_4 -> V_7 + V_27 ) ;
V_4 -> V_5 ( V_34 | V_21 ,
V_4 -> V_7 + V_27 ) ;
V_44 = V_4 -> V_11 ( V_4 -> V_7 + V_45 ) ;
while ( ( V_44 & V_56 ) == 0 ) {
V_4 -> V_57 ( V_4 ) ;
V_44 = V_4 -> V_11 ( V_4 -> V_7 + V_45 ) ;
}
if ( V_4 -> V_47 <= 0 )
break;
}
V_4 -> V_5 ( V_50 , V_4 -> V_7 + V_17 ) ;
return V_43 -> V_53 - V_4 -> V_47 ;
}
static T_4 F_23 ( int V_58 , void * V_59 )
{
struct V_3 * V_4 = V_59 ;
T_1 V_60 ;
V_60 = V_4 -> V_11 ( V_4 -> V_7 + V_61 ) ;
V_4 -> V_5 ( V_60 , V_4 -> V_7 + V_61 ) ;
if ( V_60 & V_55 ) {
F_24 ( & V_4 -> V_54 ) ;
}
return V_62 ;
}
static int F_25 ( struct V_63 * V_64 )
{
struct V_3 * V_4 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
int V_69 , V_70 = 0 , V_49 = 8 ;
struct V_71 * V_31 ;
T_1 V_72 ;
T_3 V_73 ;
V_66 = F_26 ( & V_64 -> V_74 ) ;
if ( V_66 ) {
V_70 = V_66 -> V_75 ;
V_49 = V_66 -> V_49 ;
} else {
F_27 ( V_64 -> V_74 . V_76 , L_1 ,
& V_70 ) ;
}
if ( ! V_70 ) {
F_28 ( & V_64 -> V_74 ,
L_2 ) ;
return - V_77 ;
}
V_31 = F_29 ( & V_64 -> V_74 , sizeof( struct V_3 ) ) ;
if ( ! V_31 )
return - V_78 ;
V_31 -> V_79 = V_39 | V_37 ;
V_4 = F_17 ( V_31 ) ;
V_4 -> V_80 . V_31 = V_31 ;
V_4 -> V_80 . V_81 = F_16 ;
V_4 -> V_80 . V_82 = F_18 ;
V_4 -> V_80 . V_83 = F_20 ;
F_30 ( & V_4 -> V_54 ) ;
V_68 = F_31 ( V_64 , V_84 , 0 ) ;
V_4 -> V_7 = F_32 ( & V_64 -> V_74 , V_68 ) ;
if ( F_33 ( V_4 -> V_7 ) ) {
V_69 = F_34 ( V_4 -> V_7 ) ;
goto V_85;
}
V_31 -> V_86 = V_64 -> V_74 . V_87 ;
V_31 -> V_75 = V_70 ;
V_31 -> V_74 . V_76 = V_64 -> V_74 . V_76 ;
V_4 -> V_11 = F_3 ;
V_4 -> V_5 = F_1 ;
V_4 -> V_5 ( V_88 , V_4 -> V_7 + V_27 ) ;
V_72 = V_4 -> V_11 ( V_4 -> V_7 + V_27 ) ;
V_72 &= V_88 ;
if ( V_72 != V_88 ) {
V_4 -> V_11 = F_7 ;
V_4 -> V_5 = F_5 ;
}
V_31 -> V_89 = F_35 ( V_49 ) ;
V_4 -> V_49 = V_49 ;
if ( V_4 -> V_49 == 8 ) {
V_4 -> V_48 = F_9 ;
V_4 -> V_57 = F_12 ;
} else if ( V_4 -> V_49 == 16 ) {
V_4 -> V_48 = F_10 ;
V_4 -> V_57 = F_13 ;
} else if ( V_4 -> V_49 == 32 ) {
V_4 -> V_48 = F_11 ;
V_4 -> V_57 = F_14 ;
} else {
V_69 = - V_77 ;
goto V_85;
}
F_15 ( V_4 ) ;
V_4 -> V_58 = F_36 ( V_64 , 0 ) ;
if ( V_4 -> V_58 < 0 ) {
V_69 = V_4 -> V_58 ;
goto V_85;
}
V_69 = F_37 ( & V_64 -> V_74 , V_4 -> V_58 , F_23 , 0 ,
F_38 ( & V_64 -> V_74 ) , V_4 ) ;
if ( V_69 )
goto V_85;
V_69 = F_39 ( & V_4 -> V_80 ) ;
if ( V_69 ) {
F_28 ( & V_64 -> V_74 , L_3 ) ;
goto V_85;
}
F_40 ( & V_64 -> V_74 , L_4 ,
( unsigned long long ) V_68 -> V_90 , V_4 -> V_7 , V_4 -> V_58 ) ;
if ( V_66 ) {
for ( V_73 = 0 ; V_73 < V_66 -> V_91 ; V_73 ++ )
F_41 ( V_31 , V_66 -> V_92 + V_73 ) ;
}
F_42 ( V_64 , V_31 ) ;
return 0 ;
V_85:
F_43 ( V_31 ) ;
return V_69 ;
}
static int F_44 ( struct V_63 * V_64 )
{
struct V_71 * V_31 = F_45 ( V_64 ) ;
struct V_3 * V_4 = F_17 ( V_31 ) ;
void T_2 * V_14 = V_4 -> V_7 ;
F_46 ( & V_4 -> V_80 ) ;
V_4 -> V_5 ( 0 , V_14 + V_17 ) ;
V_4 -> V_5 ( 0 , V_14 + V_19 ) ;
F_43 ( V_4 -> V_80 . V_31 ) ;
return 0 ;
}
