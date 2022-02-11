T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 , V_4 , V_5 , V_6 ;
V_3 = F_2 ( V_2 , V_7 ) ;
switch ( V_3 & V_8 ) {
case V_9 :
V_2 -> V_10 . V_11 = V_12 ;
break;
case V_13 :
V_2 -> V_10 . V_11 = V_14 ;
break;
case V_15 :
V_2 -> V_10 . V_11 = V_16 ;
break;
case V_17 :
V_2 -> V_10 . V_11 = V_18 ;
break;
default:
V_2 -> V_10 . V_11 = V_19 ;
break;
}
switch ( V_3 & V_20 ) {
case V_21 :
V_2 -> V_10 . V_22 = V_23 ;
break;
case V_24 :
V_2 -> V_10 . V_22 = V_25 ;
break;
case V_26 :
V_2 -> V_10 . V_22 = V_27 ;
break;
default:
V_2 -> V_10 . V_22 = V_28 ;
break;
}
V_5 = F_2 ( V_2 , V_29 ) ;
switch ( V_5 & V_30 ) {
case V_31 :
V_2 -> V_10 . V_32 = V_33 ;
break;
case V_34 :
V_2 -> V_10 . V_32 = V_35 ;
break;
case V_36 :
V_2 -> V_10 . V_32 = V_37 ;
break;
default:
V_2 -> V_10 . V_32 = V_38 ;
break;
}
V_4 = F_2 ( V_2 , V_39 ) ;
switch ( V_4 & V_8 ) {
case V_9 :
V_2 -> V_40 . V_11 = V_12 ;
break;
case V_13 :
V_2 -> V_40 . V_11 = V_14 ;
break;
case V_15 :
V_2 -> V_40 . V_11 = V_16 ;
break;
case V_17 :
V_2 -> V_40 . V_11 = V_18 ;
break;
default:
V_2 -> V_40 . V_11 = V_19 ;
break;
}
switch ( V_4 & V_20 ) {
case V_21 :
V_2 -> V_40 . V_22 = V_23 ;
break;
case V_24 :
V_2 -> V_40 . V_22 = V_25 ;
break;
case V_26 :
V_2 -> V_40 . V_22 = V_27 ;
break;
default:
V_2 -> V_40 . V_22 = V_28 ;
break;
}
V_6 = F_2 ( V_2 , V_41 ) ;
switch ( V_6 & V_42 ) {
case V_43 :
V_2 -> V_40 . V_32 = V_33 ;
break;
case V_44 :
V_2 -> V_40 . V_32 = V_35 ;
break;
case V_45 :
V_2 -> V_40 . V_32 = V_37 ;
break;
default:
V_2 -> V_40 . V_32 = V_38 ;
break;
}
return 0 ;
}
static T_2 F_3 ( struct V_1 * V_2 )
{
T_2 V_46 ;
V_46 = F_2 ( V_2 , V_47 ) ;
V_46 &= V_48 ;
V_46 ++ ;
if ( V_46 > V_49 )
V_46 = V_49 ;
return V_46 ;
}
T_1 F_4 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = & V_2 -> V_51 ;
V_51 -> V_52 = V_53 ;
V_51 -> V_54 = F_3 ( V_2 ) ;
return 0 ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
V_2 -> V_51 . V_55 = true ;
return 0 ;
}
T_1 F_6 ( struct V_1 * V_2 , T_2 V_56 )
{
T_3 V_57 ;
T_2 V_58 , time ;
V_2 -> V_51 . V_55 = false ;
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ ) {
V_57 = F_7 ( V_2 , F_8 ( V_58 ) ) ;
F_9 ( V_2 , F_8 ( V_58 ) ,
V_57 & ~ V_59 ) ;
V_57 = F_7 ( V_2 , F_10 ( V_58 ) ) ;
F_9 ( V_2 , F_10 ( V_58 ) ,
V_57 & ~ V_60 ) ;
}
F_11 ( V_2 ) ;
F_12 ( 1 ) ;
for ( V_58 = 0 , time = V_61 ; time ; ) {
if ( V_58 == V_56 )
return 0 ;
V_57 = F_7 ( V_2 , F_8 ( V_58 ) ) ;
if ( ! ~ V_57 || ! ( V_57 & V_59 ) ) {
V_57 = F_7 ( V_2 , F_10 ( V_58 ) ) ;
if ( ! ~ V_57 || ! ( V_57 & V_60 ) ) {
V_58 ++ ;
continue;
}
}
time -- ;
if ( time )
F_12 ( 1 ) ;
}
return V_62 ;
}
T_1 F_13 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_2 -> V_51 . V_63 ) ;
}
T_3 F_14 ( struct V_1 * V_2 , T_3 V_64 ,
struct V_65 * V_66 )
{
T_3 V_67 = F_7 ( V_2 , V_64 ) - V_66 -> V_68 ;
if ( F_15 ( V_2 -> V_69 ) )
V_66 -> V_70 = 0 ;
return V_67 ;
}
static T_4 F_16 ( struct V_1 * V_2 , T_3 V_64 ,
struct V_65 * V_66 )
{
T_3 V_71 ;
T_3 V_72 ;
T_3 V_73 ;
T_4 V_67 ;
V_72 = F_7 ( V_2 , V_64 + 1 ) ;
do {
V_73 = V_72 ;
V_71 = F_7 ( V_2 , V_64 ) ;
V_72 = F_7 ( V_2 , V_64 + 1 ) ;
} while ( V_72 != V_73 );
V_67 = ( ( T_4 ) ( V_72 - V_66 -> V_70 ) << 32 ) + V_71 ;
V_67 -= V_66 -> V_68 ;
return V_67 & V_74 ;
}
static void F_17 ( struct V_65 * V_66 , T_4 V_67 )
{
if ( ! V_67 )
return;
V_67 += V_66 -> V_68 ;
V_66 -> V_68 = ( T_3 ) V_67 ;
V_66 -> V_70 += ( T_3 ) ( V_67 >> 32 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
T_3 V_77 )
{
T_3 V_78 , V_79 , V_80 ;
T_4 V_81 = 0 ;
V_78 = F_7 ( V_2 , F_19 ( V_77 ) ) ;
do {
V_80 = F_14 ( V_2 , F_20 ( V_77 ) ,
& V_76 -> V_80 ) ;
if ( V_80 )
V_81 = F_16 ( V_2 ,
F_21 ( V_77 ) ,
& V_76 -> V_81 ) ;
V_79 = V_78 ;
V_78 = F_7 ( V_2 , F_19 ( V_77 ) ) ;
} while ( ( V_78 ^ V_79 ) & V_82 );
V_78 &= V_82 ;
V_78 |= V_83 ;
if ( V_76 -> V_84 == V_78 ) {
V_76 -> V_80 . V_85 += V_80 ;
V_76 -> V_81 . V_85 += V_81 ;
}
F_22 ( & V_76 -> V_80 , V_80 ) ;
F_17 ( & V_76 -> V_81 , V_81 ) ;
V_76 -> V_84 = V_78 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
T_3 V_77 )
{
T_3 V_86 , V_87 , V_88 , V_89 ;
T_4 V_90 = 0 ;
V_86 = F_7 ( V_2 , F_10 ( V_77 ) ) ;
do {
V_89 = F_14 ( V_2 , F_24 ( V_77 ) ,
& V_76 -> V_89 ) ;
V_88 = F_14 ( V_2 , F_25 ( V_77 ) ,
& V_76 -> V_88 ) ;
if ( V_88 )
V_90 = F_16 ( V_2 ,
F_26 ( V_77 ) ,
& V_76 -> V_90 ) ;
V_87 = V_86 ;
V_86 = F_7 ( V_2 , F_10 ( V_77 ) ) ;
} while ( ( V_86 ^ V_87 ) & V_91 );
V_86 &= V_91 ;
V_86 |= V_83 ;
if ( V_76 -> V_92 == V_86 ) {
V_76 -> V_89 . V_85 += V_89 ;
V_76 -> V_88 . V_85 += V_88 ;
V_76 -> V_90 . V_85 += V_90 ;
}
F_22 ( & V_76 -> V_89 , V_89 ) ;
F_22 ( & V_76 -> V_88 , V_88 ) ;
F_17 ( & V_76 -> V_90 , V_90 ) ;
V_76 -> V_92 = V_86 ;
}
void F_27 ( struct V_1 * V_2 , struct V_75 * V_76 ,
T_3 V_77 , T_3 V_85 )
{
T_3 V_58 ;
for ( V_58 = 0 ; V_58 < V_85 ; V_58 ++ , V_77 ++ , V_76 ++ ) {
F_18 ( V_2 , V_76 , V_77 ) ;
F_23 ( V_2 , V_76 , V_77 ) ;
}
}
void F_28 ( struct V_75 * V_76 , T_3 V_77 , T_3 V_85 )
{
T_3 V_58 ;
for ( V_58 = 0 ; V_58 < V_85 ; V_58 ++ , V_77 ++ , V_76 ++ ) {
V_76 -> V_92 = 0 ;
V_76 -> V_84 = 0 ;
}
}
T_1 F_29 ( struct V_1 * V_2 , bool * V_93 )
{
struct V_94 * V_95 = & V_2 -> V_95 ;
struct V_50 * V_51 = & V_2 -> V_51 ;
T_1 V_96 = 0 ;
T_3 V_97 = F_7 ( V_2 , F_8 ( 0 ) ) ;
V_95 -> V_98 . V_99 ( V_2 , V_95 ) ;
if ( ! ( ~ V_97 ) || ! ( V_97 & V_59 ) )
V_51 -> V_100 = true ;
if ( ! V_51 -> V_100 || ! ( ~ V_97 ) )
goto V_101;
if ( V_2 -> V_51 . V_55 && ! ( V_97 & V_59 ) ) {
V_96 = V_102 ;
goto V_101;
}
if ( ! V_95 -> V_103 ) {
V_96 = V_102 ;
goto V_101;
}
if ( ! V_95 -> V_98 . V_55 ( V_95 , V_104 ) )
goto V_101;
if ( V_51 -> V_52 == V_53 ) {
if ( V_2 -> V_51 . V_98 . V_105 )
V_96 = V_2 -> V_51 . V_98 . V_105 ( V_2 ) ;
goto V_101;
}
V_51 -> V_100 = false ;
V_101:
* V_93 = ! V_51 -> V_100 ;
return V_96 ;
}
