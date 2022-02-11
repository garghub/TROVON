static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 , V_7 ;
V_7 = V_8 ;
V_6 = F_2 ( V_7 ) ;
V_6 &= ~ ( V_9 | V_10 ) ;
V_6 &= ~ V_11 ;
switch ( V_3 ) {
case V_12 :
V_6 |= V_11 ;
break;
case V_13 :
V_6 |= V_11 | V_9 ;
break;
case V_14 :
V_6 |= V_11 | V_10 ;
break;
case V_15 :
V_6 |= V_9 | V_10 ;
break;
}
F_3 ( V_7 , V_6 ) ;
}
static int F_4 ( struct V_16 * V_17 ,
struct V_18 * V_3 )
{
int V_19 = 0 ;
if ( V_3 -> V_20 & V_21 )
return V_22 ;
if ( V_3 -> clock < 20000 )
return V_23 ;
V_19 = 355000 ;
if ( V_3 -> clock > V_19 )
return V_24 ;
if ( V_3 -> V_25 > 1680 || V_3 -> V_26 > 1050 )
return V_27 ;
return V_28 ;
}
static bool F_5 ( struct V_1 * V_2 ,
struct V_18 * V_3 ,
struct V_18 * V_29 )
{
return true ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_18 * V_3 ,
struct V_18 * V_29 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_30 * V_31 = V_2 -> V_31 ;
struct V_32 * V_32 =
F_7 ( V_31 ) ;
int V_33 ;
T_1 V_34 , V_35 ;
T_1 V_36 ;
if ( V_32 -> V_37 == 0 )
V_33 = V_38 ;
else
V_33 = V_39 ;
V_36 = V_8 ;
{
V_35 = F_2 ( V_33 ) ;
F_3 ( V_33 ,
V_35 & ~ V_40 ) ;
}
V_34 = 0 ;
if ( V_29 -> V_20 & V_41 )
V_34 |= V_42 ;
if ( V_29 -> V_20 & V_43 )
V_34 |= V_44 ;
if ( V_32 -> V_37 == 0 )
V_34 |= V_45 ;
else
V_34 |= V_46 ;
F_3 ( V_36 , V_34 ) ;
}
static bool F_8 ( struct V_16 * V_17 ,
bool V_47 )
{
struct V_4 * V_5 = V_17 -> V_5 ;
T_1 V_48 ;
int V_49 , V_50 = 0 , V_51 = false ;
T_1 V_52 ;
V_52 = F_2 ( V_8 ) ;
F_3 ( V_8 , V_52 & ~ ( V_11 ) ) ;
V_50 = 2 ;
V_48 = F_2 ( V_53 ) ;
V_48 &= ~ ( V_54 ) ;
V_48 |= V_55 ;
V_48 |= V_56 ;
V_48 |= V_57 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
unsigned long V_58 ;
F_3 ( V_53 , V_48 ) ;
V_58 = V_59 + F_9 ( 1000 ) ;
do {
if ( ! ( F_2 ( V_53 ) &
V_55 ) )
break;
F_10 ( 1 ) ;
} while ( F_11 ( V_58 , V_59 ) );
}
if ( ( F_2 ( V_60 ) & V_61 ) !=
V_62 )
V_51 = true ;
F_3 ( V_8 , V_52 ) ;
return V_51 ;
}
static enum V_63 F_12 (
struct V_16 * V_17 , bool V_47 )
{
if ( F_8 ( V_17 , V_47 ) )
return V_64 ;
else
return V_65 ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_66 * V_67 = F_14 ( V_17 ) ;
F_15 ( V_67 -> V_68 ) ;
F_16 ( V_17 ) ;
F_17 ( V_17 ) ;
F_18 ( V_17 ) ;
}
static int F_19 ( struct V_16 * V_17 )
{
struct V_66 * V_67 =
F_14 ( V_17 ) ;
return F_20 ( V_67 ) ;
}
static int F_21 ( struct V_16 * V_17 ,
struct V_69 * V_70 ,
T_2 V_71 )
{
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
}
void F_24 ( struct V_4 * V_5 ,
struct V_72 * V_73 )
{
struct V_66 * V_66 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
T_1 V_74 ;
V_66 = F_25 ( sizeof( struct V_66 ) , V_75 ) ;
if ( ! V_66 )
return;
V_66 -> V_73 = V_73 ;
V_17 = & V_66 -> V_76 ;
F_26 ( V_5 , V_17 ,
& V_77 , V_78 ) ;
V_2 = & V_66 -> V_79 ;
F_27 ( V_5 , V_2 ,
& V_80 , V_81 ) ;
F_28 ( & V_66 -> V_76 ,
& V_66 -> V_79 ) ;
V_74 = V_82 ;
V_66 -> V_68 = F_29 ( V_5 ,
V_74 , L_1 ) ;
if ( ! V_66 -> V_68 ) {
F_30 ( V_83 , & V_5 -> V_84 -> V_5 , L_2
L_3 ) ;
goto V_85;
}
V_66 -> type = V_86 ;
V_17 -> V_87 = 0 ;
V_17 -> V_88 = 0 ;
F_31 ( V_2 , & V_89 ) ;
F_32 ( V_17 ,
& V_90 ) ;
F_33 ( V_17 ) ;
return;
V_85:
F_23 ( & V_66 -> V_79 ) ;
F_17 ( & V_66 -> V_76 ) ;
F_18 ( V_66 ) ;
return;
}
