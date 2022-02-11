static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_9 = V_4 -> V_10 ;
T_1 V_11 = V_4 -> V_11 & 1 ;
T_1 V_12 ;
T_1 V_13 ;
T_1 V_14 ;
T_1 V_15 ;
T_1 V_16 ;
if ( ! V_11 ) {
V_12 = V_17 ;
V_13 = V_18 ;
} else {
V_12 = V_19 ;
V_13 = V_20 ;
}
V_14 = F_2 ( V_6 -> V_21 + V_22 ) ;
V_14 &= ~ V_12 ;
V_14 &= ~ V_13 ;
if ( V_9 & V_23 ) {
V_16 = V_9 & ~ V_23 ;
F_3 ( V_6 -> V_24 , L_1 ,
V_9 , V_16 ) ;
V_14 |= V_12 ;
if ( V_25 [ V_16 ] ) {
V_14 |= V_13 ;
V_15 = V_26 [ V_16 ] << 4 |
V_27 [ V_16 ] ;
} else {
V_15 = V_28 [ V_16 ] << 4 |
V_29 [ V_16 ] ;
}
if ( V_16 >= 5 )
V_15 |= V_30 ;
F_3 ( V_6 -> V_24 , L_2 ,
V_14 , V_15 ) ;
F_4 ( V_14 , V_6 -> V_21 + V_22 ) ;
F_4 ( V_15 , V_6 -> V_21 + V_31 + V_11 ) ;
} else {
V_16 = V_9 & ~ V_32 ;
F_3 ( V_6 -> V_24 , L_3 ,
V_9 , V_16 ) ;
if ( V_33 [ V_16 ] ) {
V_14 |= V_13 ;
V_15 = V_34 [ V_16 ] << 4 |
V_35 [ V_16 ] ;
} else {
V_15 = V_36 [ V_16 ] << 4 |
V_37 [ V_16 ] ;
}
F_3 ( V_6 -> V_24 ,
L_4 ,
V_14 , V_15 ) ;
F_4 ( V_14 , V_6 -> V_21 + V_22 ) ;
F_4 ( V_15 , V_6 -> V_21 + V_38 ) ;
}
V_2 -> V_8 = V_4 ;
return;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_39 = V_4 -> V_40 - V_41 ;
F_3 ( V_6 -> V_24 , L_5 ,
V_4 -> V_40 , V_39 ) ;
F_4 ( V_42 [ V_39 ] << 4 | V_43 [ V_39 ] ,
V_6 -> V_21 + V_44 ) ;
}
static unsigned int F_6 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_3 * V_4 = V_46 -> V_24 ;
if ( V_4 != V_2 -> V_8 && F_7 ( V_4 ) )
F_1 ( V_2 , V_4 ) ;
return F_8 ( V_46 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_47 * V_24 = V_6 -> V_24 ;
struct V_48 * V_49 = V_6 -> V_49 ;
int V_50 = 0 ;
int V_51 ;
V_51 = F_10 ( V_2 ) ;
if ( V_51 )
return V_51 ;
if ( V_6 -> V_52 ) {
F_11 ( V_24 , L_6 ) ;
V_51 = F_12 ( V_49 , 0 ) ;
if ( ! V_51 )
V_50 ++ ;
}
if ( V_6 -> V_53 ) {
F_11 ( V_24 , L_7 ) ;
V_51 = F_12 ( V_49 , 1 ) ;
if ( ! V_51 )
V_50 ++ ;
}
if ( V_6 -> V_54 && ! V_6 -> V_52 ) {
F_11 ( V_24 , L_8 ) ;
V_51 = F_12 ( V_49 , 0 ) ;
if ( ! V_51 )
V_50 ++ ;
}
if ( V_6 -> V_55 && ! V_6 -> V_53 ) {
F_11 ( V_24 , L_9 ) ;
V_51 = F_12 ( V_49 , 1 ) ;
if ( ! V_51 )
V_50 ++ ;
}
F_11 ( V_24 , L_10 , V_50 ) ;
return ( V_50 > 0 ) ? 0 : - V_56 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_47 * V_24 = V_6 -> V_24 ;
struct V_48 * V_49 = V_6 -> V_49 ;
if ( V_6 -> V_52 ) {
F_11 ( V_24 , L_11 ) ;
F_14 ( V_49 , 0 ) ;
}
if ( V_6 -> V_53 ) {
F_11 ( V_24 , L_12 ) ;
F_14 ( V_49 , 1 ) ;
}
if ( V_6 -> V_54 && ! V_6 -> V_52 ) {
F_11 ( V_24 , L_13 ) ;
F_14 ( V_49 , 0 ) ;
}
if ( V_6 -> V_55 && ! V_6 -> V_53 ) {
F_11 ( V_24 , L_14 ) ;
F_14 ( V_49 , 1 ) ;
}
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return V_6 -> V_57 ;
}
static int F_16 ( struct V_5 * V_6 ,
bool V_58 )
{
struct V_47 * V_24 = V_6 -> V_24 ;
struct V_48 * V_49 ;
enum V_59 V_60 ;
V_49 = F_17 () ;
if ( F_18 ( V_49 ) )
return F_19 ( V_49 ) ;
V_6 -> V_49 = V_49 ;
V_60 = F_20 ( V_49 ) ;
V_61 . V_62 =
F_9 ;
V_61 . V_63 =
F_13 ;
V_61 . V_64 =
F_15 ;
if ( F_21 ( V_49 , V_58 ) )
V_65 [ 0 ] . V_66 |= V_67 ;
if ( ! V_58 ) {
switch ( V_60 ) {
case V_68 :
V_6 -> V_57 = V_69 ;
V_6 -> V_70 = V_71 ;
V_6 -> V_52 = true ;
break;
case V_72 :
V_6 -> V_57 = V_69 ;
V_6 -> V_70 = V_73 ;
V_6 -> V_52 = true ;
break;
case V_74 :
V_6 -> V_57 = V_71 ;
V_6 -> V_70 = V_71 ;
break;
case V_75 :
V_6 -> V_57 = V_69 ;
V_6 -> V_70 = V_69 ;
V_6 -> V_52 = true ;
V_6 -> V_55 = true ;
break;
}
} else {
switch ( V_60 ) {
case V_68 :
V_6 -> V_57 = V_69 ;
V_6 -> V_70 = V_73 ;
V_6 -> V_53 = true ;
break;
case V_72 :
V_6 -> V_57 = V_69 ;
V_6 -> V_70 = V_71 ;
V_6 -> V_53 = true ;
break;
case V_74 :
V_6 -> V_57 = V_69 ;
V_6 -> V_70 = V_69 ;
V_6 -> V_54 = true ;
V_6 -> V_53 = true ;
break;
case V_75 :
V_6 -> V_57 = V_71 ;
V_6 -> V_70 = V_71 ;
break;
}
}
F_11 ( V_24 , L_15 , V_58 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
bool V_58 )
{
return - V_76 ;
}
static int F_22 ( struct V_77 * V_78 )
{
struct V_47 * V_24 = & V_78 -> V_24 ;
struct V_79 * V_80 = V_24 -> V_81 ;
const struct V_82 V_83 = V_65 [ 0 ] ;
const struct V_82 * V_84 [] = { & V_83 , NULL } ;
struct V_5 * V_6 ;
struct V_85 * V_86 ;
int V_87 ;
int V_51 ;
int V_16 ;
V_6 = F_23 ( V_24 , sizeof( * V_6 ) , V_88 ) ;
if ( ! V_6 )
return - V_89 ;
V_6 -> V_24 = V_24 ;
V_87 = F_24 ( V_78 , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
V_86 = F_25 ( V_78 , V_90 , 0 ) ;
if ( ! V_86 )
return - V_91 ;
V_6 -> V_21 = F_26 ( V_24 , V_86 ) ;
if ( F_18 ( V_6 -> V_21 ) )
return F_19 ( V_6 -> V_21 ) ;
V_6 -> V_92 = F_27 ( V_24 , L_16 ) ;
if ( ! F_18 ( V_6 -> V_92 ) ) {
V_51 = F_28 ( V_6 -> V_92 ) ;
if ( V_51 ) {
F_29 ( V_24 , L_17 ) ;
return V_51 ;
}
}
if ( F_30 ( V_80 , L_18 ) ) {
V_51 = F_16 ( V_6 ,
( V_86 -> V_93 == 0x63400000 ) ) ;
if ( V_51 )
goto V_94;
} else {
V_6 -> V_57 = V_71 ;
V_6 -> V_70 = V_71 ;
}
V_6 -> V_7 = F_31 ( V_24 , V_84 , 1 ) ;
if ( ! V_6 -> V_7 ) {
V_51 = - V_89 ;
goto V_94;
}
V_6 -> V_7 -> V_8 = V_6 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_7 -> V_95 ; V_16 ++ ) {
struct V_1 * V_2 = V_6 -> V_7 -> V_96 [ V_16 ] ;
struct V_97 * V_98 = & V_2 -> V_98 ;
V_98 -> V_99 = V_6 -> V_21 + V_100 ;
V_98 -> V_101 = V_6 -> V_21 + V_102 ;
V_98 -> V_103 = V_6 -> V_21 + V_104 ;
V_98 -> V_105 = V_6 -> V_21 + V_104 ;
F_32 ( V_98 ) ;
}
F_11 ( V_24 , L_19 ,
F_33 ( V_6 -> V_21 + V_106 ) , V_87 , V_86 ) ;
V_51 = F_34 ( V_6 -> V_7 , V_87 , V_107 ,
0 , & V_108 ) ;
if ( V_51 )
goto V_94;
return 0 ;
V_94:
if ( ! F_18 ( V_6 -> V_92 ) )
F_35 ( V_6 -> V_92 ) ;
return V_51 ;
}
static int F_36 ( struct V_77 * V_78 )
{
struct V_109 * V_7 = F_37 ( V_78 ) ;
struct V_5 * V_6 = V_7 -> V_8 ;
F_38 ( V_6 -> V_7 ) ;
if ( ! F_18 ( V_6 -> V_92 ) )
F_35 ( V_6 -> V_92 ) ;
return 0 ;
}
