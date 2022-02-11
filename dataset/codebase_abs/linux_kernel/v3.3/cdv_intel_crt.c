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
struct V_19 * V_20 = V_17 -> V_5 -> V_21 ;
int V_22 = 0 ;
if ( V_3 -> V_23 & V_24 )
return V_25 ;
if ( V_3 -> clock < 20000 )
return V_26 ;
V_22 = 355000 ;
if ( V_3 -> clock > V_22 )
return V_27 ;
if ( V_3 -> V_28 > 1680 || V_3 -> V_29 > 1050 )
return V_30 ;
if ( ( F_5 ( V_3 -> V_28 * 4 , 64 ) * V_3 -> V_29 ) >
V_20 -> V_31 )
return V_32 ;
return V_33 ;
}
static bool F_6 ( struct V_1 * V_2 ,
struct V_18 * V_3 ,
struct V_18 * V_34 )
{
return true ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_18 * V_3 ,
struct V_18 * V_34 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_37 * V_37 =
F_8 ( V_36 ) ;
int V_38 ;
T_1 V_39 , V_40 ;
T_1 V_41 ;
if ( V_37 -> V_42 == 0 )
V_38 = V_43 ;
else
V_38 = V_44 ;
V_41 = V_8 ;
{
V_40 = F_2 ( V_38 ) ;
F_3 ( V_38 ,
V_40 & ~ V_45 ) ;
}
V_39 = 0 ;
if ( V_34 -> V_23 & V_46 )
V_39 |= V_47 ;
if ( V_34 -> V_23 & V_48 )
V_39 |= V_49 ;
if ( V_37 -> V_42 == 0 )
V_39 |= V_50 ;
else
V_39 |= V_51 ;
F_3 ( V_41 , V_39 ) ;
}
static bool F_9 ( struct V_16 * V_17 ,
bool V_52 )
{
struct V_4 * V_5 = V_17 -> V_5 ;
T_1 V_53 ;
int V_54 , V_55 = 0 , V_56 = false ;
T_1 V_57 ;
V_57 = F_2 ( V_8 ) ;
F_3 ( V_8 , V_57 & ~ ( V_11 ) ) ;
V_55 = 2 ;
V_53 = F_2 ( V_58 ) ;
V_53 &= ~ ( V_59 ) ;
V_53 |= V_60 ;
V_53 |= V_61 ;
V_53 |= V_62 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
unsigned long V_63 ;
F_3 ( V_58 , V_53 ) ;
V_63 = V_64 + F_10 ( 1000 ) ;
do {
if ( ! ( F_2 ( V_58 ) &
V_60 ) )
break;
F_11 ( 1 ) ;
} while ( F_12 ( V_63 , V_64 ) );
}
if ( ( F_2 ( V_65 ) & V_66 ) !=
V_67 )
V_56 = true ;
F_3 ( V_8 , V_57 ) ;
return V_56 ;
}
static enum V_68 F_13 (
struct V_16 * V_17 , bool V_52 )
{
if ( F_9 ( V_17 , V_52 ) )
return V_69 ;
else
return V_70 ;
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_71 * V_71 =
F_15 ( V_17 ) ;
F_16 ( V_71 -> V_72 ) ;
F_17 ( V_17 ) ;
F_18 ( V_17 ) ;
F_19 ( V_17 ) ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_71 * V_71 =
F_15 ( V_17 ) ;
return F_21 ( V_17 , & V_71 -> V_72 -> V_73 ) ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_74 * V_75 ,
T_2 V_76 )
{
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
}
void F_25 ( struct V_4 * V_5 ,
struct V_77 * V_78 )
{
struct V_79 * V_79 ;
struct V_71 * V_71 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
T_1 V_80 ;
V_71 = F_26 ( sizeof( struct V_71 ) , V_81 ) ;
if ( ! V_71 )
return;
V_79 = F_26 ( sizeof( struct V_79 ) , V_81 ) ;
if ( ! V_79 )
goto V_82;
V_17 = & V_79 -> V_83 ;
F_27 ( V_5 , V_17 ,
& V_84 , V_85 ) ;
V_2 = & V_71 -> V_83 ;
F_28 ( V_5 , V_2 ,
& V_86 , V_87 ) ;
F_29 ( V_79 ,
V_71 ) ;
V_80 = V_88 ;
V_71 -> V_72 = F_30 ( V_5 ,
V_80 , L_1 ) ;
if ( ! V_71 -> V_72 ) {
F_31 ( V_89 , & V_5 -> V_90 -> V_5 , L_2
L_3 ) ;
goto V_91;
}
V_71 -> type = V_92 ;
V_17 -> V_93 = 0 ;
V_17 -> V_94 = 0 ;
F_32 ( V_2 , & V_95 ) ;
F_33 ( V_17 ,
& V_96 ) ;
F_34 ( V_17 ) ;
return;
V_91:
F_24 ( & V_71 -> V_83 ) ;
F_18 ( & V_79 -> V_83 ) ;
F_19 ( V_79 ) ;
V_82:
F_19 ( V_71 ) ;
return;
}
