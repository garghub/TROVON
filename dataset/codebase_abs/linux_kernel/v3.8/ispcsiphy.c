static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
T_1 V_5 = F_2 (
V_2 -> V_6 , V_7 , 0 ) ;
T_1 V_8 , V_9 ;
switch ( V_3 ) {
case V_10 :
V_5 &= ~ V_11 ;
V_8 = V_12 ;
break;
case V_13 :
V_8 = V_12 ;
V_9 = V_14 ;
break;
case V_15 :
V_5 |= V_11 ;
V_8 = V_16 ;
break;
case V_17 :
V_8 = V_16 ;
V_9 = V_14 ;
break;
}
switch ( V_3 ) {
case V_10 :
case V_15 :
if ( V_4 )
V_9 = V_18 ;
else
V_9 = V_19 ;
}
V_5 &= ~ ( V_20 << V_8 ) ;
V_5 |= V_9 << V_8 ;
F_3 ( V_2 -> V_6 , V_5 ,
V_7 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , bool V_21 ,
bool V_4 )
{
T_1 V_22 = V_23
| V_24 ;
if ( V_3 != V_10 )
return;
if ( ! V_21 ) {
F_3 ( V_2 -> V_6 , 0 ,
V_25 , 0 ) ;
return;
}
if ( V_4 )
V_22 |= V_26 ;
F_3 ( V_2 -> V_6 , V_22 ,
V_25 , 0 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , bool V_21 ,
bool V_4 )
{
if ( V_2 -> V_6 -> V_27 [ V_7 ]
&& V_21 )
return F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_2 -> V_6 -> V_27 [ V_25 ] )
return F_4 ( V_2 , V_3 , V_21 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , bool V_28 )
{
F_7 ( V_2 -> V_6 , V_2 -> V_29 , V_30 ,
V_31 ,
V_28 ? V_31 : 0 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_32 )
{
T_1 V_5 ;
T_2 V_33 ;
F_7 ( V_2 -> V_6 , V_2 -> V_29 , V_30 ,
V_34 , V_32 ) ;
V_33 = 0 ;
do {
F_9 ( 50 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_2 -> V_29 , V_30 ) &
V_35 ;
if ( V_5 != V_32 >> 2 )
V_33 ++ ;
} while ( ( V_5 != V_32 >> 2 ) && ( V_33 < 100 ) );
if ( V_33 == 100 ) {
F_10 ( V_2 -> V_6 -> V_36 , L_1 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_41 = F_12 ( & V_39 -> V_42 . V_43 ) ;
struct V_44 * V_45 = V_41 -> V_46 -> V_47 ;
struct V_48 * V_49 ;
int V_50 ;
unsigned int V_51 = 0 ;
unsigned int V_52 ;
T_1 V_5 ;
if ( V_45 -> V_53 == V_10
|| V_45 -> V_53 == V_15 )
V_49 = & V_45 -> V_54 . V_55 . V_56 ;
else
V_49 = & V_45 -> V_54 . V_39 . V_56 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_57 ; V_52 ++ ) {
if ( V_49 -> V_58 [ V_52 ] . V_59 > 1 || V_49 -> V_58 [ V_52 ] . V_60 > 3 )
return - V_61 ;
if ( V_51 & ( 1 << V_49 -> V_58 [ V_52 ] . V_60 ) )
return - V_61 ;
V_51 |= 1 << V_49 -> V_58 [ V_52 ] . V_60 ;
}
if ( V_49 -> V_62 . V_59 > 1 || V_49 -> V_62 . V_60 > 3 )
return - V_61 ;
if ( V_49 -> V_62 . V_60 == 0 || V_51 & ( 1 << V_49 -> V_62 . V_60 ) )
return - V_61 ;
F_5 ( V_2 , V_45 -> V_53 , true ,
V_45 -> V_54 . V_55 . V_63 ) ;
V_50 = V_41 -> V_64 / 1000
/ ( 2 * F_13 ( V_51 ) ) * V_41 -> V_65 ;
V_5 = F_2 ( V_39 -> V_6 , V_2 -> V_66 , V_67 ) ;
V_5 &= ~ ( V_68 |
V_69 ) ;
V_5 |= ( F_14 ( 25 * V_50 , 2000000 ) - 1 )
<< V_70 ;
V_5 |= ( F_14 ( 90 * V_50 , 1000000 ) + 3 )
<< V_71 ;
F_3 ( V_39 -> V_6 , V_5 , V_2 -> V_66 , V_67 ) ;
V_5 = F_2 ( V_39 -> V_6 , V_2 -> V_66 , V_72 ) ;
V_5 &= ~ ( V_73 |
V_74 |
V_75 ) ;
V_5 |= V_76 << V_77 ;
V_5 |= V_78 << V_79 ;
V_5 |= V_80 << V_81 ;
F_3 ( V_39 -> V_6 , V_5 , V_2 -> V_66 , V_72 ) ;
V_5 = F_2 ( V_39 -> V_6 , V_2 -> V_29 , V_30 ) ;
for ( V_52 = 0 ; V_52 < V_2 -> V_57 ; V_52 ++ ) {
V_5 &= ~ ( F_15 ( V_52 + 1 ) |
F_16 ( V_52 + 1 ) ) ;
V_5 |= ( V_49 -> V_58 [ V_52 ] . V_59 <<
F_17 ( V_52 + 1 ) ) ;
V_5 |= ( V_49 -> V_58 [ V_52 ] . V_60 <<
F_18 ( V_52 + 1 ) ) ;
}
V_5 &= ~ ( V_82 |
V_83 ) ;
V_5 |= V_49 -> V_62 . V_59 << V_84 ;
V_5 |= V_49 -> V_62 . V_60 << V_85 ;
F_3 ( V_39 -> V_6 , V_5 , V_2 -> V_29 , V_30 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_86 ;
if ( V_2 -> V_87 == NULL ) {
F_10 ( V_2 -> V_6 -> V_36 , L_2
L_3 ) ;
return - V_88 ;
}
F_20 ( & V_2 -> V_89 ) ;
V_86 = F_21 ( V_2 -> V_87 ) ;
if ( V_86 < 0 )
goto V_90;
V_86 = F_22 ( V_2 -> V_39 ) ;
if ( V_86 < 0 )
goto V_90;
V_86 = F_11 ( V_2 ) ;
if ( V_86 < 0 )
goto V_90;
V_86 = F_8 ( V_2 , V_91 ) ;
if ( V_86 ) {
F_23 ( V_2 -> V_87 ) ;
goto V_90;
}
F_6 ( V_2 , true ) ;
V_2 -> V_92 = 1 ;
V_90:
F_24 ( & V_2 -> V_89 ) ;
return V_86 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_89 ) ;
if ( V_2 -> V_92 ) {
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_40 * V_41 =
F_12 ( & V_39 -> V_42 . V_43 ) ;
struct V_44 * V_45 =
V_41 -> V_46 -> V_47 ;
F_5 ( V_2 , V_45 -> V_53 , false ,
V_45 -> V_54 . V_55 . V_63 ) ;
F_6 ( V_2 , false ) ;
F_8 ( V_2 , V_93 ) ;
F_23 ( V_2 -> V_87 ) ;
V_2 -> V_92 = 0 ;
}
F_24 ( & V_2 -> V_89 ) ;
}
int F_26 ( struct V_94 * V_6 )
{
struct V_1 * V_95 = & V_6 -> V_96 ;
struct V_1 * V_97 = & V_6 -> V_98 ;
V_97 -> V_6 = V_6 ;
V_97 -> V_39 = & V_6 -> V_99 ;
V_97 -> V_57 = V_100 ;
V_97 -> V_29 = V_101 ;
V_97 -> V_66 = V_102 ;
F_27 ( & V_97 -> V_89 ) ;
if ( V_6 -> V_103 == V_104 ) {
V_95 -> V_6 = V_6 ;
V_95 -> V_39 = & V_6 -> V_105 ;
V_95 -> V_57 = V_106 ;
V_95 -> V_29 = V_107 ;
V_95 -> V_66 = V_108 ;
F_27 ( & V_95 -> V_89 ) ;
}
return 0 ;
}
