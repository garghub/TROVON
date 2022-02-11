static inline int F_1 ( int V_1 , int V_2 )
{
int V_3 , V_4 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
if ( V_5 [ V_3 ] . V_1 >= V_1 )
break;
}
if ( V_3 == F_2 ( V_5 ) )
return - V_6 ;
switch ( V_2 ) {
case 8000 :
return V_5 [ V_3 ] . V_7 [ V_8 ] ;
case 16000 :
return V_5 [ V_3 ] . V_7 [ V_9 ] ;
case 32000 :
return V_5 [ V_3 ] . V_7 [ V_10 ] ;
case 44100 :
return V_5 [ V_3 ] . V_7 [ V_11 ] ;
case 48000 :
return V_5 [ V_3 ] . V_7 [ V_12 ] ;
default:
F_3 ( L_1 , V_13 , V_2 ) ;
V_4 = - V_6 ;
}
return V_4 ;
}
static int F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = F_5 ( V_21 ) ;
unsigned int V_24 , V_25 ;
int V_26 ;
V_26 = F_1 ( V_23 -> V_27 , F_6 ( V_17 ) ) ;
if ( V_26 < 0 )
return V_26 ;
V_24 = ( 0xFF00 & V_26 ) >> 8 ;
V_25 = 0x00FF & V_26 ;
F_7 ( V_23 -> V_28 , V_29 ,
V_30 , V_24 ) ;
F_7 ( V_23 -> V_28 , V_31 ,
V_32 , V_25 ) ;
if ( ! V_23 -> V_33 ) {
F_7 ( V_23 -> V_28 , V_31 ,
V_34 , V_34 ) ;
F_7 ( V_23 -> V_28 , V_29 ,
V_35 , V_35 ) ;
} else {
unsigned long int V_36 , V_37 ;
int V_38 ;
V_36 = F_6 ( V_17 ) * 2 * F_8 ( V_17 ) ;
V_37 = V_23 -> V_39 / V_36 ;
switch ( F_8 ( V_17 ) ) {
case 8 :
case 16 :
switch ( V_37 ) {
case 2 :
V_38 = V_40 ;
break;
case 4 :
V_38 = V_41 ;
break;
case 8 :
V_38 = V_42 ;
break;
case 16 :
V_38 = V_43 ;
break;
default:
F_9 ( V_21 -> V_44 ,
L_2 ) ;
return - V_6 ;
}
break;
case 24 :
V_38 = V_45 ;
break;
case 32 :
V_38 = V_46 ;
break;
default:
F_9 ( V_21 -> V_44 , L_2 ) ;
return - V_6 ;
}
F_7 ( V_23 -> V_28 , V_47 ,
V_48 , V_38 ) ;
}
return 0 ;
}
static int F_10 ( struct V_14 * V_15 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = F_5 ( V_21 ) ;
F_7 ( V_23 -> V_28 , V_49 ,
V_50 , V_50 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 , int V_51 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = F_5 ( V_21 ) ;
if ( V_51 )
F_7 ( V_23 -> V_28 , V_52 ,
V_53 , V_53 ) ;
else
F_7 ( V_23 -> V_28 , V_52 ,
V_53 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_54 ,
int V_55 , unsigned int V_56 , int V_57 )
{
struct V_20 * V_21 = V_54 -> V_21 ;
struct V_22 * V_23 = F_5 ( V_21 ) ;
int V_26 = 0 ;
if ( V_56 >= 10000000 && V_56 <= 20000000 ) {
V_26 |= V_58 ;
V_23 -> V_39 = V_56 ;
} else if ( V_56 >= 20000000 && V_56 <= 40000000 ) {
V_26 |= V_59 ;
V_23 -> V_39 = V_56 / 2 ;
} else if ( V_56 >= 40000000 && V_56 <= 60000000 ) {
V_26 |= V_60 ;
V_23 -> V_39 = V_56 / 4 ;
} else {
F_3 ( L_3 , V_56 ) ;
return - V_6 ;
}
V_26 = V_26 << V_61 ;
V_23 -> V_27 = V_56 ;
V_26 &= ~ V_62 ;
F_7 ( V_23 -> V_28 , V_63 ,
V_64 , V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_18 * V_54 ,
unsigned int V_65 )
{
struct V_20 * V_21 = V_54 -> V_21 ;
struct V_22 * V_23 = F_5 ( V_21 ) ;
T_1 V_66 = 0 , V_67 = 0 ;
int V_4 ;
switch ( V_65 & V_68 ) {
case V_69 :
V_23 -> V_33 = 1 ;
V_66 |= V_70 ;
break;
case V_71 :
V_23 -> V_33 = 0 ;
V_66 &= ~ V_70 ;
break;
default:
return - V_6 ;
}
V_66 |= V_72 ;
V_66 |= V_73 ;
switch ( V_65 & V_74 ) {
case V_75 :
break;
case V_76 :
V_66 |= V_77 | V_78 ;
break;
case V_79 :
V_66 |= V_78 ;
break;
case V_80 :
V_66 |= V_77 ;
break;
default:
return - V_6 ;
}
V_4 = F_14 ( V_23 -> V_28 , V_81 , V_66 ) ;
V_4 = F_14 ( V_23 -> V_28 , V_47 , V_67 ) ;
return 0 ;
}
static int F_15 ( struct V_82 * V_44 )
{
struct V_22 * V_23 = F_16 ( V_44 ) ;
F_7 ( V_23 -> V_28 , V_49 ,
V_50 , ~ V_50 ) ;
return 0 ;
}
static int F_17 ( struct V_82 * V_44 )
{
struct V_22 * V_23 = F_16 ( V_44 ) ;
F_7 ( V_23 -> V_28 , V_49 ,
V_50 , V_50 ) ;
return 0 ;
}
static int F_18 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_5 ( V_21 ) ;
F_19 ( V_21 -> V_44 , L_4 ) ;
V_23 -> V_21 = V_21 ;
return 0 ;
}
static bool F_20 ( struct V_82 * V_44 , unsigned int V_83 )
{
switch ( V_83 ) {
case V_84 :
case V_85 :
case V_86 :
case V_87 :
return true ;
default:
return false ;
}
}
static int F_21 ( struct V_88 * V_89 ,
const struct V_90 * V_91 )
{
struct V_22 * V_23 ;
int V_4 = 0 , V_83 ;
V_23 = F_22 ( & V_89 -> V_44 ,
sizeof( * V_23 ) , V_92 ) ;
if ( ! V_23 )
return - V_93 ;
F_23 ( V_89 , V_23 ) ;
V_23 -> V_28 = F_24 ( V_89 , & V_94 ) ;
if ( F_25 ( V_23 -> V_28 ) ) {
V_4 = F_26 ( V_23 -> V_28 ) ;
F_9 ( & V_89 -> V_44 ,
L_5 , V_4 ) ;
return V_4 ;
}
V_4 = F_27 ( V_23 -> V_28 ,
V_95 , & V_83 ) ;
if ( V_4 < 0 ) {
F_9 ( & V_89 -> V_44 , L_6 , V_4 ) ;
return V_4 ;
}
F_28 ( & V_89 -> V_44 , L_7 , V_83 ) ;
V_4 = F_29 ( & V_89 -> V_44 , & V_96 ,
V_97 , F_2 ( V_97 ) ) ;
if ( V_4 < 0 ) {
F_9 ( & V_89 -> V_44 , L_8 , V_4 ) ;
return V_4 ;
}
return V_4 ;
}
static int F_30 ( struct V_88 * V_98 )
{
F_31 ( & V_98 -> V_44 ) ;
return 0 ;
}
