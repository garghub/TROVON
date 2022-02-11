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
struct V_3 * V_4 = F_17 ( V_29 -> V_31 ) ;
T_3 V_44 ;
V_44 = ( V_43 && V_43 -> V_44 )
? V_43 -> V_44 : V_29 -> V_44 ;
if ( V_44 != V_4 -> V_44 ) {
F_19 ( & V_29 -> V_45 , L_1 ,
V_46 , V_44 ) ;
return - V_47 ;
}
return 0 ;
}
static void F_20 ( struct V_3 * V_4 )
{
T_3 V_48 ;
V_48 = V_4 -> V_11 ( V_4 -> V_7 + V_49 ) ;
while ( ( V_48 & V_50 ) == 0 && V_4 -> V_51 > 0 ) {
if ( V_4 -> V_6 )
V_4 -> V_52 ( V_4 ) ;
else
V_4 -> V_5 ( 0 , V_4 -> V_7 + V_8 ) ;
V_4 -> V_51 -= V_4 -> V_44 / 8 ;
V_48 = V_4 -> V_11 ( V_4 -> V_7 + V_49 ) ;
}
}
static int F_21 ( struct V_28 * V_29 , struct V_42 * V_43 )
{
struct V_3 * V_4 = F_17 ( V_29 -> V_31 ) ;
T_1 V_53 ;
V_4 -> V_6 = V_43 -> V_54 ;
V_4 -> V_13 = V_43 -> V_55 ;
V_4 -> V_51 = V_43 -> V_56 ;
F_22 ( V_4 -> V_57 ) ;
V_53 = V_4 -> V_11 ( V_4 -> V_7 + V_17 ) ;
V_4 -> V_5 ( V_53 | V_58 ,
V_4 -> V_7 + V_17 ) ;
for (; ; ) {
V_9 V_34 ;
T_3 V_48 ;
F_20 ( V_4 ) ;
V_34 = V_4 -> V_11 ( V_4 -> V_7 + V_27 ) &
~ V_21 ;
V_4 -> V_5 ( V_34 , V_4 -> V_7 + V_27 ) ;
F_23 ( & V_4 -> V_57 ) ;
V_34 = V_4 -> V_11 ( V_4 -> V_7 + V_27 ) ;
V_4 -> V_5 ( V_34 | V_21 ,
V_4 -> V_7 + V_27 ) ;
V_48 = V_4 -> V_11 ( V_4 -> V_7 + V_49 ) ;
while ( ( V_48 & V_59 ) == 0 ) {
V_4 -> V_60 ( V_4 ) ;
V_48 = V_4 -> V_11 ( V_4 -> V_7 + V_49 ) ;
}
if ( V_4 -> V_51 <= 0 )
break;
}
V_4 -> V_5 ( V_53 , V_4 -> V_7 + V_17 ) ;
return V_43 -> V_56 - V_4 -> V_51 ;
}
static T_4 F_24 ( int V_61 , void * V_62 )
{
struct V_3 * V_4 = V_62 ;
T_1 V_63 ;
V_63 = V_4 -> V_11 ( V_4 -> V_7 + V_64 ) ;
V_4 -> V_5 ( V_63 , V_4 -> V_7 + V_64 ) ;
if ( V_63 & V_58 ) {
F_25 ( & V_4 -> V_57 ) ;
}
return V_65 ;
}
static int F_26 ( struct V_66 * V_67 )
{
struct V_3 * V_4 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
int V_72 , V_73 = 0 , V_44 = 8 ;
struct V_74 * V_31 ;
T_1 V_75 ;
T_3 V_76 ;
V_69 = F_27 ( & V_67 -> V_45 ) ;
if ( V_69 ) {
V_73 = V_69 -> V_77 ;
V_44 = V_69 -> V_44 ;
} else {
F_28 ( V_67 -> V_45 . V_78 , L_2 ,
& V_73 ) ;
}
if ( ! V_73 ) {
F_19 ( & V_67 -> V_45 ,
L_3 ) ;
return - V_47 ;
}
V_31 = F_29 ( & V_67 -> V_45 , sizeof( struct V_3 ) ) ;
if ( ! V_31 )
return - V_79 ;
V_31 -> V_80 = V_39 | V_37 ;
V_4 = F_17 ( V_31 ) ;
V_4 -> V_81 . V_31 = F_30 ( V_31 ) ;
V_4 -> V_81 . V_82 = F_16 ;
V_4 -> V_81 . V_83 = F_18 ;
V_4 -> V_81 . V_84 = F_21 ;
F_31 ( & V_4 -> V_57 ) ;
V_71 = F_32 ( V_67 , V_85 , 0 ) ;
V_4 -> V_7 = F_33 ( & V_67 -> V_45 , V_71 ) ;
if ( F_34 ( V_4 -> V_7 ) ) {
V_72 = F_35 ( V_4 -> V_7 ) ;
goto V_86;
}
V_31 -> V_87 = V_67 -> V_45 . V_88 ;
V_31 -> V_77 = V_73 ;
V_31 -> V_45 . V_78 = V_67 -> V_45 . V_78 ;
V_4 -> V_11 = F_3 ;
V_4 -> V_5 = F_1 ;
V_4 -> V_5 ( V_89 , V_4 -> V_7 + V_27 ) ;
V_75 = V_4 -> V_11 ( V_4 -> V_7 + V_27 ) ;
V_75 &= V_89 ;
if ( V_75 != V_89 ) {
V_4 -> V_11 = F_7 ;
V_4 -> V_5 = F_5 ;
}
V_4 -> V_44 = V_44 ;
if ( V_4 -> V_44 == 8 ) {
V_4 -> V_52 = F_9 ;
V_4 -> V_60 = F_12 ;
} else if ( V_4 -> V_44 == 16 ) {
V_4 -> V_52 = F_10 ;
V_4 -> V_60 = F_13 ;
} else if ( V_4 -> V_44 == 32 ) {
V_4 -> V_52 = F_11 ;
V_4 -> V_60 = F_14 ;
} else {
V_72 = - V_47 ;
goto V_86;
}
F_15 ( V_4 ) ;
V_4 -> V_61 = F_36 ( V_67 , 0 ) ;
if ( V_4 -> V_61 < 0 ) {
V_72 = V_4 -> V_61 ;
goto V_86;
}
V_72 = F_37 ( & V_67 -> V_45 , V_4 -> V_61 , F_24 , 0 ,
F_38 ( & V_67 -> V_45 ) , V_4 ) ;
if ( V_72 )
goto V_86;
V_72 = F_39 ( & V_4 -> V_81 ) ;
if ( V_72 ) {
F_19 ( & V_67 -> V_45 , L_4 ) ;
goto V_86;
}
F_40 ( & V_67 -> V_45 , L_5 ,
( unsigned long long ) V_71 -> V_90 , V_4 -> V_7 , V_4 -> V_61 ) ;
if ( V_69 ) {
for ( V_76 = 0 ; V_76 < V_69 -> V_91 ; V_76 ++ )
F_41 ( V_31 , V_69 -> V_92 + V_76 ) ;
}
F_42 ( V_67 , V_31 ) ;
return 0 ;
V_86:
F_43 ( V_31 ) ;
return V_72 ;
}
static int F_44 ( struct V_66 * V_67 )
{
struct V_74 * V_31 = F_45 ( V_67 ) ;
struct V_3 * V_4 = F_17 ( V_31 ) ;
void T_2 * V_14 = V_4 -> V_7 ;
F_46 ( & V_4 -> V_81 ) ;
V_4 -> V_5 ( 0 , V_14 + V_17 ) ;
V_4 -> V_5 ( 0 , V_14 + V_19 ) ;
F_43 ( V_4 -> V_81 . V_31 ) ;
return 0 ;
}
