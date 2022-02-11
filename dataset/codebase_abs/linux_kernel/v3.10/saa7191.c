static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
return F_1 ( V_3 ) -> V_4 [ V_4 ] ;
}
static int F_4 ( struct V_2 * V_3 , T_1 * V_5 )
{
struct V_6 * V_7 = F_5 ( V_3 ) ;
int V_8 ;
V_8 = F_6 ( V_7 , V_5 , 1 ) ;
if ( V_8 < 0 ) {
F_7 ( V_9 L_1 ) ;
return V_8 ;
}
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_5 ( V_3 ) ;
F_1 ( V_3 ) -> V_4 [ V_4 ] = V_5 ;
return F_9 ( V_7 , V_4 , V_5 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
T_1 V_10 , const T_1 * V_11 )
{
struct V_6 * V_7 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_13 ;
int V_8 ;
for ( V_13 = 0 ; V_13 < ( V_10 - 1 ) ; V_13 ++ ) {
V_12 -> V_4 [ V_11 [ 0 ] + V_13 ] = V_11 [ V_13 + 1 ] ;
}
V_8 = F_11 ( V_7 , V_11 , V_10 ) ;
if ( V_8 < 0 ) {
F_7 ( V_9 L_2
L_3 ) ;
return V_8 ;
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 ,
T_2 V_14 , T_2 V_15 , T_2 V_16 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_17 = F_3 ( V_3 , V_18 ) ;
T_1 V_19 = F_3 ( V_3 , V_20 ) ;
int V_21 ;
switch ( V_14 ) {
case V_22 :
V_19 &= ~ ( V_23 | V_24
| V_25 ) ;
V_17 &= ~ V_26 ;
break;
case V_27 :
V_19 |= V_23 | V_25 ;
V_17 |= V_26 ;
break;
default:
return - V_28 ;
}
V_21 = F_8 ( V_3 , V_18 , V_17 ) ;
if ( V_21 )
return - V_29 ;
V_21 = F_8 ( V_3 , V_20 , V_19 ) ;
if ( V_21 )
return - V_29 ;
V_12 -> V_14 = V_14 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , T_3 V_30 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_31 = F_3 ( V_3 , V_32 ) ;
T_1 V_33 = F_3 ( V_3 , V_34 ) ;
T_1 V_35 = F_3 ( V_3 , V_36 ) ;
int V_21 ;
if ( V_30 & V_37 ) {
V_31 &= ~ V_38 ;
V_33 &= ~ ( V_39 | V_40 ) ;
V_35 = V_41 ;
} else if ( V_30 & V_42 ) {
V_31 &= ~ V_38 ;
V_33 &= ~ V_39 ;
V_33 |= V_40 ;
V_35 = V_43 ;
} else if ( V_30 & V_44 ) {
V_31 |= V_38 ;
V_33 &= ~ ( V_39 | V_40 ) ;
V_35 = V_41 ;
} else {
return - V_28 ;
}
V_21 = F_8 ( V_3 , V_34 , V_33 ) ;
if ( V_21 )
return - V_29 ;
V_21 = F_8 ( V_3 , V_32 , V_31 ) ;
if ( V_21 )
return - V_29 ;
V_21 = F_8 ( V_3 , V_36 , V_35 ) ;
if ( V_21 )
return - V_29 ;
V_12 -> V_30 = V_30 ;
F_14 ( L_4 , V_33 ,
V_31 , V_35 ) ;
F_14 ( L_5 , V_30 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , T_1 * V_45 )
{
int V_13 = 0 ;
F_14 ( L_6 ) ;
for ( V_13 = 0 ; V_13 < V_46 ; V_13 ++ ) {
if ( F_4 ( V_3 , V_45 ) )
return - V_29 ;
if ( ( ( * V_45 ) & V_47 ) == 0 ) {
F_14 ( L_7 ) ;
return 0 ;
}
F_16 ( V_48 ) ;
}
F_14 ( L_8 ) ;
return - V_49 ;
}
static int F_17 ( struct V_2 * V_3 , T_3 * V_30 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_31 = F_3 ( V_3 , V_32 ) ;
T_1 V_33 = F_3 ( V_3 , V_34 ) ;
T_1 V_45 ;
T_3 V_50 = V_12 -> V_30 ;
int V_21 = 0 ;
F_14 ( L_9 ) ;
* V_30 = V_42 | V_37 | V_44 ;
V_31 &= ~ V_38 ;
V_33 &= ~ ( V_40 ) ;
V_21 = F_8 ( V_3 , V_32 , V_31 ) ;
if ( V_21 ) {
V_21 = - V_29 ;
goto V_51;
}
V_21 = F_8 ( V_3 , V_34 , V_33 ) ;
if ( V_21 ) {
V_21 = - V_29 ;
goto V_51;
}
V_33 |= V_39 ;
V_21 = F_8 ( V_3 , V_34 , V_33 ) ;
if ( V_21 ) {
V_21 = - V_29 ;
goto V_51;
}
F_16 ( V_48 ) ;
V_21 = F_15 ( V_3 , & V_45 ) ;
if ( V_21 )
goto V_51;
if ( V_45 & V_52 ) {
F_14 ( L_10 ) ;
* V_30 = V_42 ;
return 0 ;
}
F_14 ( L_11 ) ;
V_21 = F_13 ( V_3 , V_37 ) ;
if ( V_21 )
goto V_51;
F_16 ( V_48 ) ;
V_21 = F_15 ( V_3 , & V_45 ) ;
if ( V_21 )
goto V_51;
if ( V_45 & V_52 ) {
F_14 ( L_12 ) ;
F_13 ( V_3 , V_50 ) ;
return - V_53 ;
}
if ( V_45 & V_54 ) {
F_14 ( L_13 ) ;
* V_30 = V_37 ;
return F_13 ( V_3 , V_50 ) ;
}
F_14 ( L_14 ) ;
V_21 = F_13 ( V_3 , V_44 ) ;
if ( V_21 )
goto V_51;
F_16 ( V_48 ) ;
V_21 = F_15 ( V_3 , & V_45 ) ;
if ( V_21 )
goto V_51;
if ( V_45 & V_52 ) {
F_14 ( L_12 ) ;
V_21 = - V_53 ;
goto V_51;
}
if ( V_45 & V_54 ) {
F_14 ( L_15 ) ;
* V_30 = V_44 ;
return F_13 ( V_3 , V_50 ) ;
}
F_14 ( L_16 ) ;
V_51:
return F_13 ( V_3 , V_50 ) ;
}
static int F_18 ( struct V_2 * V_3 )
{
T_1 V_45 ;
F_14 ( L_17 ) ;
F_14 ( L_18 ) ;
if ( F_4 ( V_3 , & V_45 ) )
return - V_29 ;
F_14 ( L_6 ) ;
if ( V_45 & V_47 ) {
F_14 ( L_8 ) ;
return - V_49 ;
}
F_14 ( L_7 ) ;
if ( V_45 & V_52 ) {
F_14 ( L_19 ) ;
return F_13 ( V_3 , V_42 ) ;
} else {
F_14 ( L_13 ) ;
return F_13 ( V_3 , V_37 ) ;
}
}
static int F_19 ( struct V_2 * V_3 , struct V_55 * V_56 )
{
T_1 V_4 ;
int V_8 = 0 ;
switch ( V_56 -> V_57 ) {
case V_58 :
case V_59 :
case V_60 :
V_4 = F_3 ( V_3 , V_18 ) ;
switch ( V_56 -> V_57 ) {
case V_58 :
V_56 -> V_5 = ( ( V_61 ) V_4 & V_62 )
>> V_63 ;
break;
case V_59 :
V_56 -> V_5 = ( ( V_61 ) V_4 & V_64 )
>> V_65 ;
break;
case V_60 :
V_56 -> V_5 = ( ( V_61 ) V_4 & V_66 )
>> V_67 ;
break;
}
break;
case V_68 :
case V_69 :
V_4 = F_3 ( V_3 , V_70 ) ;
if ( V_56 -> V_57 == V_68 )
V_56 -> V_5 = ( ( V_61 ) V_4 & V_71 ) ? 1 : 0 ;
else
V_56 -> V_5 = ( ( V_61 ) V_4 & V_72 )
>> V_73 ;
break;
case V_74 :
V_4 = F_3 ( V_3 , V_75 ) ;
if ( V_4 < 0x80 )
V_4 += 0x80 ;
else
V_4 -= 0x80 ;
V_56 -> V_5 = ( V_61 ) V_4 ;
break;
case V_76 :
V_4 = F_3 ( V_3 , V_32 ) ;
V_56 -> V_5 = ( ( V_61 ) V_4 & V_77 ) ? 1 : 0 ;
break;
case V_78 :
V_4 = F_3 ( V_3 , V_34 ) ;
V_56 -> V_5 = ( ( V_61 ) V_4 & V_79 )
>> V_80 ;
if ( V_56 -> V_5 >= 4 )
V_56 -> V_5 -= 8 ;
break;
case V_81 :
V_4 = F_3 ( V_3 , V_82 ) ;
V_56 -> V_5 = ( ( V_61 ) V_4 & V_83 )
>> V_84 ;
break;
default:
V_8 = - V_28 ;
}
return V_8 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_55 * V_56 )
{
T_1 V_4 ;
int V_8 = 0 ;
switch ( V_56 -> V_57 ) {
case V_58 :
case V_59 :
case V_60 :
V_4 = F_3 ( V_3 , V_18 ) ;
switch ( V_56 -> V_57 ) {
case V_58 :
V_4 &= ~ V_62 ;
V_4 |= ( V_56 -> V_5 << V_63 )
& V_62 ;
break;
case V_59 :
V_4 &= ~ V_64 ;
V_4 |= ( V_56 -> V_5 << V_65 )
& V_64 ;
break;
case V_60 :
V_4 &= ~ V_66 ;
V_4 |= ( V_56 -> V_5 << V_67 )
& V_66 ;
break;
}
V_8 = F_8 ( V_3 , V_18 , V_4 ) ;
break;
case V_68 :
case V_69 :
V_4 = F_3 ( V_3 , V_70 ) ;
if ( V_56 -> V_57 == V_68 ) {
if ( V_56 -> V_5 )
V_4 |= V_71 ;
else
V_4 &= ~ V_71 ;
} else {
V_4 &= ~ V_72 ;
V_4 |= ( V_56 -> V_5 << V_73 )
& V_72 ;
}
V_8 = F_8 ( V_3 , V_70 , V_4 ) ;
break;
case V_74 :
V_4 = V_56 -> V_5 & 0xff ;
if ( V_4 < 0x80 )
V_4 += 0x80 ;
else
V_4 -= 0x80 ;
V_8 = F_8 ( V_3 , V_75 , V_4 ) ;
break;
case V_76 :
V_4 = F_3 ( V_3 , V_32 ) ;
if ( V_56 -> V_5 )
V_4 |= V_77 ;
else
V_4 &= ~ V_77 ;
V_8 = F_8 ( V_3 , V_32 , V_4 ) ;
break;
case V_78 : {
V_61 V_5 = V_56 -> V_5 ;
if ( V_5 < 0 )
V_5 += 8 ;
V_4 = F_3 ( V_3 , V_34 ) ;
V_4 &= ~ V_79 ;
V_4 |= ( V_5 << V_80 )
& V_79 ;
V_8 = F_8 ( V_3 , V_34 , V_4 ) ;
break;
}
case V_81 :
V_4 = F_3 ( V_3 , V_82 ) ;
V_4 &= ~ V_83 ;
V_4 |= ( V_56 -> V_5 << V_84 )
& V_83 ;
V_8 = F_8 ( V_3 , V_82 , V_4 ) ;
break;
default:
V_8 = - V_28 ;
}
return V_8 ;
}
static int F_21 ( struct V_2 * V_3 , T_2 * V_45 )
{
T_1 V_85 ;
int V_86 = V_87 ;
if ( F_4 ( V_3 , & V_85 ) )
return - V_29 ;
if ( ( V_85 & V_47 ) == 0 )
V_86 = 0 ;
if ( ! ( V_85 & V_54 ) )
V_86 |= V_88 ;
* V_45 = V_86 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_89 * V_90 )
{
struct V_6 * V_7 = F_5 ( V_3 ) ;
return F_23 ( V_7 , V_90 , V_91 , 0 ) ;
}
static int F_24 ( struct V_6 * V_7 ,
const struct V_92 * V_57 )
{
int V_21 = 0 ;
struct V_1 * V_12 ;
struct V_2 * V_3 ;
F_25 ( V_7 , L_20 ,
V_7 -> V_93 << 1 , V_7 -> V_94 -> V_95 ) ;
V_12 = F_26 ( sizeof( * V_12 ) , V_96 ) ;
if ( ! V_12 )
return - V_97 ;
V_3 = & V_12 -> V_3 ;
F_27 ( V_3 , V_7 , & V_98 ) ;
V_21 = F_10 ( V_3 , sizeof( V_99 ) , V_99 ) ;
if ( V_21 ) {
F_7 ( V_9 L_21 ) ;
F_28 ( V_12 ) ;
return V_21 ;
}
F_7 ( V_100 L_22 ) ;
V_12 -> V_14 = V_22 ;
V_12 -> V_30 = V_37 ;
V_21 = F_18 ( V_3 ) ;
if ( V_21 && ( V_21 != - V_49 ) )
F_7 ( V_9 L_23 ) ;
return 0 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_30 ( V_7 ) ;
F_31 ( V_3 ) ;
F_28 ( F_1 ( V_3 ) ) ;
return 0 ;
}
