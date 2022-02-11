static enum V_1 F_1 ( struct V_2 * V_3 )
{
switch ( F_2 ( V_3 -> V_4 ) ) {
case 0 :
return V_5 ;
case 1 :
return V_6 ;
case 2 :
return V_7 ;
case 3 :
return V_8 ;
default:
return V_9 ;
}
}
static int F_3 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_12 V_13 ;
enum V_1 V_14 ;
int V_15 ;
V_14 = F_1 ( V_3 ) ;
if ( V_14 == V_9 )
return - V_16 ;
F_4 ( & V_13 , NULL , V_14 , true ) ;
V_15 = F_5 ( V_3 , V_11 , & V_13 ) ;
if ( V_15 && V_15 != - V_16 ) {
return V_15 ;
} else if ( V_15 == - V_16 ) {
if ( V_3 -> V_17 < V_3 -> V_4 -> V_18 )
return 0 ;
F_6 ( V_3 , L_1 ) ;
return - V_19 ;
} else if ( ! V_15 && ! V_13 . V_20 ) {
F_6 ( V_3 , L_2 ) ;
return - V_19 ;
}
return V_15 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_21 V_13 ;
enum V_1 V_14 ;
int V_15 ;
V_14 = F_1 ( V_3 ) ;
if ( V_14 == V_9 )
return - V_16 ;
F_4 ( NULL , & V_13 , V_14 , true ) ;
V_15 = F_8 ( V_3 , V_11 , & V_13 ) ;
if ( V_15 == - V_16 ) {
if ( V_3 -> V_17 < V_3 -> V_4 -> V_18 ) {
V_15 = 0 ;
} else {
F_6 ( V_3 , L_1 ) ;
return - V_16 ;
}
} else if ( V_15 ) {
F_6 ( V_3 , L_3 ) ;
}
return V_15 ;
}
static int F_9 ( struct V_22 * V_4 , T_1 * V_23 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_10 * V_11 = V_3 -> V_24 ;
T_2 V_25 ;
* V_23 = 0 ;
V_25 = F_11 ( V_3 , V_11 , V_26 ) ;
if ( ! ( V_25 & V_27 ) ) {
F_6 ( V_3 , L_4 , V_25 ) ;
return - V_16 ;
}
V_25 = F_11 ( V_3 , V_11 , V_28 ) ;
* V_23 = F_11 ( V_3 , V_11 , V_29 ) ;
* V_23 <<= 32 ;
* V_23 |= V_25 ;
F_12 ( V_3 , V_11 , V_26 ,
V_27 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_4 , T_1 * V_23 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_10 * V_11 = V_3 -> V_24 ;
T_2 V_25 ;
* V_23 = 0 ;
V_25 = F_11 ( V_3 , V_11 , V_30 ) ;
if ( ! ( V_25 & V_27 ) ) {
F_6 ( V_3 , L_5 , V_25 ) ;
return - V_16 ;
}
V_25 = F_11 ( V_3 , V_11 , V_31 ) ;
* V_23 = F_11 ( V_3 , V_11 , V_32 ) ;
* V_23 <<= 32 ;
* V_23 |= V_25 ;
F_12 ( V_3 , V_11 , V_30 , V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_22 * V_4 , T_1 * V_33 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_10 * V_11 = V_3 -> V_24 ;
T_2 V_34 = 0 ;
V_34 = F_11 ( V_3 , V_11 , V_35 ) ;
* V_33 = F_11 ( V_3 , V_11 , V_36 ) ;
* V_33 <<= 32 ;
* V_33 |= V_34 ;
return 0 ;
}
static int F_15 ( struct V_22 * V_4 ,
enum V_37 V_38 ,
enum V_39 V_40 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_10 * V_11 = V_3 -> V_24 ;
T_2 V_41 , V_42 = 0x0 ;
switch ( V_38 ) {
case V_43 :
V_42 = 0x0 ;
V_41 = 0x3FFF ;
break;
case V_44 :
V_42 = 0x7 ;
V_41 = 0x3CAA ;
break;
case V_45 :
V_42 = 0x3 ;
V_41 = 0x3FFA ;
break;
case V_46 :
V_42 = 0x3 ;
V_41 = 0x3FFE ;
break;
case V_47 :
V_42 = 0x5 ;
V_41 = 0x3FAA ;
break;
case V_48 :
V_42 = 0x5 ;
V_41 = 0x3FEE ;
break;
case V_49 :
V_42 = 0x5 ;
V_41 = 0x3CFF ;
break;
case V_50 :
V_42 = 0x5 ;
V_41 = 0x3EFF ;
break;
case V_51 :
V_42 = 0x5 ;
V_41 = 0x3CAA ;
break;
case V_52 :
V_42 = 0x5 ;
V_41 = 0x3EEE ;
break;
default:
F_6 ( V_3 , L_6 , V_38 ) ;
return - V_16 ;
}
F_12 ( V_3 , V_11 , V_53 , 0 ) ;
F_12 ( V_3 , V_11 , V_54 , V_41 ) ;
F_12 ( V_3 , V_11 , V_55 , V_42 ) ;
if ( V_40 == V_56 ) {
F_12 ( V_3 , V_11 , V_57 , 0x0 ) ;
F_12 ( V_3 , V_11 , V_58 , 0x7FF ) ;
F_12 ( V_3 , V_11 , V_59 , 0x3FFF ) ;
} else {
F_12 ( V_3 , V_11 , V_57 , V_42 ) ;
F_12 ( V_3 , V_11 , V_58 , 0 ) ;
F_12 ( V_3 , V_11 , V_59 , V_41 ) ;
}
F_12 ( V_3 , V_11 , V_26 ,
V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_22 * V_4 , T_3 V_60 )
{
T_4 V_61 = 0 , V_25 , V_62 = 0 , V_63 , V_64 , V_65 , V_66 ;
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_10 * V_11 = V_3 -> V_24 ;
T_2 V_67 = 0 , V_68 ;
int V_69 = 1 ;
if ( V_60 < 0 ) {
V_60 = - V_60 ;
V_69 = 0 ;
}
if ( V_60 > 1 ) {
T_4 V_70 = V_60 , V_71 = 1 ;
for ( V_25 = 7 ; V_25 > 0 ; V_25 -- ) {
V_63 = F_17 ( V_25 * 1000000000 , V_60 ) ;
V_63 -= 8 ;
V_63 >>= 4 ;
if ( V_63 < 1 )
V_63 = 1 ;
if ( V_63 > 0xFFFFFFE )
V_63 = 0xFFFFFFE ;
V_64 = V_63 * 16 + 8 ;
V_65 = V_60 * V_64 - V_25 * 1000000000 ;
V_66 = V_65 + 16 * V_60 ;
if ( V_65 < 0 )
V_65 = - V_65 ;
if ( V_66 < 0 )
V_66 = - V_66 ;
if ( V_65 * ( V_64 + 16 ) > V_66 * V_64 ) {
V_63 ++ ;
V_64 += 16 ;
V_65 = V_66 ;
}
if ( V_70 * V_64 > V_65 * V_71 ) {
V_70 = V_65 ;
V_61 = V_25 ;
V_62 = V_63 ;
V_71 = V_64 ;
}
}
} else if ( V_60 == 1 ) {
V_61 = 4 ;
V_62 = 0xee6b27f ;
} else {
V_61 = 0 ;
V_62 = 0xFFFFFFF ;
}
V_67 = ( V_62 << V_72 ) |
( ( ( int ) V_61 ) << V_73 ) |
( ( ( int ) V_69 ) << V_74 ) ;
F_12 ( V_3 , V_11 , V_75 , 0x1 ) ;
V_68 = F_11 ( V_3 , V_11 , V_75 ) ;
if ( V_68 & 1 ) {
F_12 ( V_3 , V_11 , V_76 ,
V_67 ) ;
} else {
F_6 ( V_3 , L_7 ) ;
return - V_16 ;
}
F_12 ( V_3 , V_11 , V_75 , 0x0 ) ;
return 0 ;
}
static int F_18 ( struct V_22 * V_4 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_10 * V_11 ;
int V_15 ;
V_11 = F_19 ( V_3 ) ;
if ( ! V_11 ) {
F_20 ( V_3 , L_8 ) ;
return - V_19 ;
}
V_3 -> V_24 = V_11 ;
V_15 = F_3 ( V_3 , V_11 ) ;
if ( V_15 ) {
F_6 ( V_3 ,
L_9 ) ;
F_21 ( V_3 , V_11 ) ;
V_3 -> V_24 = NULL ;
return V_15 ;
}
F_12 ( V_3 , V_11 , V_53 , 0x7FF ) ;
F_12 ( V_3 , V_11 , V_54 , 0x3FFF ) ;
F_12 ( V_3 , V_11 , V_58 , 0x7FF ) ;
F_12 ( V_3 , V_11 , V_59 , 0x3FFF ) ;
F_12 ( V_3 , V_11 , V_57 , 7 ) ;
F_12 ( V_3 , V_11 , V_55 , 7 ) ;
F_12 ( V_3 , V_11 , V_77 , 0x1 ) ;
if ( F_22 ( V_3 -> V_4 ) )
F_12 ( V_3 , V_11 , V_78 , 2 ) ;
if ( F_23 ( V_3 -> V_4 ) )
F_12 ( V_3 , V_11 , V_79 , 2 ) ;
F_12 ( V_3 , V_11 , V_80 , 0 ) ;
F_12 ( V_3 , V_11 , V_81 , 0 ) ;
if ( F_22 ( V_3 -> V_4 ) )
F_12 ( V_3 , V_11 , V_78 , 4 ) ;
if ( F_23 ( V_3 -> V_4 ) ) {
F_12 ( V_3 , V_11 , V_79 , 4 ) ;
F_12 ( V_3 , V_11 , V_82 , 1 ) ;
}
F_12 ( V_3 , V_11 , V_76 , 0x0 ) ;
F_12 ( V_3 , V_11 , V_75 , 0x0 ) ;
F_12 ( V_3 , V_11 , V_26 ,
V_27 ) ;
F_12 ( V_3 , V_11 , V_30 , V_27 ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_4 )
{
struct V_2 * V_3 = F_10 ( V_4 ) ;
struct V_10 * V_11 = V_3 -> V_24 ;
F_7 ( V_3 , V_11 ) ;
F_12 ( V_3 , V_11 , V_53 , 0x7FF ) ;
F_12 ( V_3 , V_11 , V_54 , 0x3FFF ) ;
F_12 ( V_3 , V_11 , V_58 , 0x7FF ) ;
F_12 ( V_3 , V_11 , V_59 , 0x3FFF ) ;
F_12 ( V_3 , V_11 , V_55 , 0x0 ) ;
F_12 ( V_3 , V_11 , V_57 , 0x0 ) ;
F_21 ( V_3 , V_11 ) ;
V_3 -> V_24 = NULL ;
return 0 ;
}
