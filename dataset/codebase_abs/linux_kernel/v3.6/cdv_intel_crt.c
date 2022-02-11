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
if ( V_3 -> V_19 & V_20 )
return V_21 ;
if ( V_3 -> clock < 20000 )
return V_22 ;
if ( V_3 -> clock > 355000 )
return V_23 ;
return V_24 ;
}
static bool F_5 ( struct V_1 * V_2 ,
const struct V_18 * V_3 ,
struct V_18 * V_25 )
{
return true ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_18 * V_3 ,
struct V_18 * V_25 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_28 * V_28 =
F_7 ( V_27 ) ;
int V_29 ;
T_1 V_30 , V_31 ;
T_1 V_32 ;
if ( V_28 -> V_33 == 0 )
V_29 = V_34 ;
else
V_29 = V_35 ;
V_32 = V_8 ;
{
V_31 = F_2 ( V_29 ) ;
F_3 ( V_29 ,
V_31 & ~ V_36 ) ;
}
V_30 = 0 ;
if ( V_25 -> V_19 & V_37 )
V_30 |= V_38 ;
if ( V_25 -> V_19 & V_39 )
V_30 |= V_40 ;
if ( V_28 -> V_33 == 0 )
V_30 |= V_41 ;
else
V_30 |= V_42 ;
F_3 ( V_32 , V_30 ) ;
}
static bool F_8 ( struct V_16 * V_17 ,
bool V_43 )
{
struct V_4 * V_5 = V_17 -> V_5 ;
T_1 V_44 ;
int V_45 , V_46 = 0 , V_47 = false ;
T_1 V_48 ;
V_46 = 2 ;
V_48 = V_44 = F_2 ( V_49 ) ;
V_44 &= ~ ( V_50 ) ;
V_44 |= V_51 ;
V_44 |= V_52 ;
V_44 |= V_53 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
unsigned long V_54 ;
F_3 ( V_49 , V_44 ) ;
V_54 = V_55 + F_9 ( 1000 ) ;
do {
if ( ! ( F_2 ( V_49 ) &
V_51 ) )
break;
F_10 ( 1 ) ;
} while ( F_11 ( V_54 , V_55 ) );
}
if ( ( F_2 ( V_56 ) & V_57 ) !=
V_58 )
V_47 = true ;
F_3 ( V_56 , V_59 ) ;
F_3 ( V_49 , V_48 ) ;
return V_47 ;
}
static enum V_60 F_12 (
struct V_16 * V_17 , bool V_43 )
{
if ( F_8 ( V_17 , V_43 ) )
return V_61 ;
else
return V_62 ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_63 * V_63 =
F_14 ( V_17 ) ;
F_15 ( V_63 -> V_64 ) ;
F_16 ( V_17 ) ;
F_17 ( V_17 ) ;
F_18 ( V_17 ) ;
}
static int F_19 ( struct V_16 * V_17 )
{
struct V_63 * V_63 =
F_14 ( V_17 ) ;
return F_20 ( V_17 , & V_63 -> V_64 -> V_65 ) ;
}
static int F_21 ( struct V_16 * V_17 ,
struct V_66 * V_67 ,
T_2 V_68 )
{
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
}
void F_24 ( struct V_4 * V_5 ,
struct V_69 * V_70 )
{
struct V_71 * V_71 ;
struct V_63 * V_63 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
T_1 V_72 ;
V_63 = F_25 ( sizeof( struct V_63 ) , V_73 ) ;
if ( ! V_63 )
return;
V_71 = F_25 ( sizeof( struct V_71 ) , V_73 ) ;
if ( ! V_71 )
goto V_74;
V_17 = & V_71 -> V_75 ;
F_26 ( V_5 , V_17 ,
& V_76 , V_77 ) ;
V_2 = & V_63 -> V_75 ;
F_27 ( V_5 , V_2 ,
& V_78 , V_79 ) ;
F_28 ( V_71 ,
V_63 ) ;
V_72 = V_80 ;
V_63 -> V_64 = F_29 ( V_5 ,
V_72 , L_1 ) ;
if ( ! V_63 -> V_64 ) {
F_30 ( V_81 , & V_5 -> V_82 -> V_5 , L_2
L_3 ) ;
goto V_83;
}
V_63 -> type = V_84 ;
V_17 -> V_85 = 0 ;
V_17 -> V_86 = 0 ;
F_31 ( V_2 , & V_87 ) ;
F_32 ( V_17 ,
& V_88 ) ;
F_33 ( V_17 ) ;
return;
V_83:
F_23 ( & V_63 -> V_75 ) ;
F_17 ( & V_71 -> V_75 ) ;
F_18 ( V_71 ) ;
V_74:
F_18 ( V_63 ) ;
return;
}
