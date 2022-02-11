static inline int F_1 ( T_1 V_1 , int V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_6 ;
T_1 V_7 ;
do {
F_2 ( 1 ) ;
V_7 = F_3 ( V_4 -> V_8 + V_1 ) ;
if ( V_7 & V_2 )
return 0 ;
} while ( -- V_5 > 0 );
return - V_9 ;
}
static int F_4 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_3 * V_4 = V_12 -> V_4 ;
T_1 V_7 ;
V_7 = F_3 ( V_4 -> V_8 + V_13 ) ;
if ( V_12 -> V_14 == V_15 ) {
V_7 &= ~ V_16 ;
V_7 |= V_17 ;
} else {
V_7 &= ~ V_17 ;
V_7 |= V_16 ;
}
F_6 ( V_7 , V_4 -> V_8 + V_13 ) ;
return 0 ;
}
static int F_7 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_3 * V_4 = V_12 -> V_4 ;
T_1 V_7 ;
V_7 = F_3 ( V_4 -> V_18 ) ;
V_7 &= ~ V_19 ;
F_6 ( V_7 , V_4 -> V_18 ) ;
V_7 = F_3 ( V_4 -> V_18 ) ;
V_7 &= ~ V_20 ;
F_6 ( V_7 , V_4 -> V_18 ) ;
V_7 = F_3 ( V_4 -> V_8 + V_13 ) ;
V_7 &= ~ ( V_17 | V_16 | V_21 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_3 * V_4 = V_12 -> V_4 ;
T_1 V_22 = V_12 -> V_14 ;
int V_23 ;
T_1 V_7 ;
if ( V_22 == V_24 ) {
F_6 ( V_25 , V_4 -> V_8 + V_26 ) ;
V_7 = F_3 ( V_4 -> V_27 ) ;
V_7 &= ~ V_28 ;
F_6 ( V_7 , V_4 -> V_27 ) ;
V_7 = F_3 ( V_4 -> V_18 ) ;
V_7 |= ( V_19 | V_20 ) ;
F_6 ( V_7 , V_4 -> V_18 ) ;
V_7 = F_3 ( V_4 -> V_18 ) ;
V_7 |= ( V_29 | V_30 ) ;
F_6 ( V_7 , V_4 -> V_18 ) ;
V_23 = F_1 ( V_31 , V_32 , V_4 ) ;
if ( V_23 < 0 ) {
F_9 ( & V_10 -> V_33 , L_1 ) ;
return V_23 ;
}
} else {
F_6 ( V_34 , V_4 -> V_8 + V_26 ) ;
V_7 = F_3 ( V_4 -> V_18 ) ;
V_7 |= V_19 ;
F_6 ( V_7 , V_4 -> V_18 ) ;
V_23 = F_1 ( V_31 , V_32 , V_4 ) ;
if ( V_23 < 0 ) {
F_9 ( & V_10 -> V_33 , L_1 ) ;
return V_23 ;
}
V_7 = F_3 ( V_4 -> V_27 ) ;
V_7 &= ~ V_28 ;
F_6 ( V_7 , V_4 -> V_27 ) ;
V_7 = F_3 ( V_4 -> V_35 ) ;
V_7 |= V_36 ;
F_6 ( V_7 , V_4 -> V_35 ) ;
}
return 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
T_1 V_22 ;
T_1 V_7 ;
V_22 = V_4 -> V_12 -> V_14 ;
V_7 = F_3 ( V_4 -> V_8 + V_13 ) ;
switch ( V_22 ) {
case V_24 :
V_7 &= ~ ( V_17 | V_16 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_13 ) ;
V_7 = ( V_7 & ~ V_17 ) | V_16 ;
F_6 ( V_7 , V_4 -> V_8 + V_13 ) ;
V_7 = F_3 ( V_4 -> V_8 + V_26 ) ;
V_7 |= V_37 ;
F_6 ( V_7 , V_4 -> V_8 + V_26 ) ;
break;
case V_15 :
V_7 &= ~ ( V_17 | V_16 ) ;
F_6 ( V_7 , V_4 -> V_8 + V_13 ) ;
V_7 = ( V_7 & ~ V_16 ) | V_17 ;
F_6 ( V_7 , V_4 -> V_8 + V_13 ) ;
V_7 = F_3 ( V_4 -> V_35 ) ;
V_7 |= V_36 ;
F_6 ( V_7 , V_4 -> V_35 ) ;
V_7 = F_3 ( V_4 -> V_8 + V_26 ) ;
V_7 &= ~ V_37 ;
F_6 ( V_7 , V_4 -> V_8 + V_26 ) ;
break;
default:
F_11 ( L_2 ) ;
break;
}
}
static void F_12 ( struct V_38 * V_39 )
{
struct V_3 * V_4 ;
int V_40 ;
int V_41 ;
V_4 = F_13 ( F_14 ( V_39 ) ,
struct V_3 , V_42 ) ;
V_41 = F_15 ( V_4 -> V_43 ) ;
V_40 = F_15 ( V_4 -> V_44 ) ;
if ( ! V_41 && V_40 ) {
F_16 ( V_4 -> V_45 , V_46 , true ) ;
F_17 ( L_3 ) ;
V_4 -> V_12 -> V_14 = V_15 ;
F_10 ( V_4 ) ;
} else if ( V_41 && ! V_40 ) {
F_16 ( V_4 -> V_45 , V_46 , false ) ;
F_16 ( V_4 -> V_45 , V_47 , false ) ;
F_17 ( L_4 ) ;
} else if ( V_41 && V_40 ) {
F_16 ( V_4 -> V_45 , V_47 , true ) ;
F_17 ( L_5 ) ;
V_4 -> V_12 -> V_14 = V_24 ;
F_10 ( V_4 ) ;
}
}
static T_2 F_18 ( int V_48 , void * V_49 )
{
struct V_3 * V_4 = V_49 ;
F_19 ( V_50 , & V_4 -> V_42 ,
V_4 -> V_51 ) ;
return V_52 ;
}
static int F_20 ( struct V_53 * V_54 )
{
struct V_55 * V_55 ;
struct V_56 * V_33 = & V_54 -> V_33 ;
struct V_3 * V_4 ;
struct V_11 * V_12 ;
struct V_57 * V_58 ;
int V_23 ;
T_1 V_7 ;
V_4 = F_21 ( V_33 , sizeof( struct V_3 ) ,
V_59 ) ;
if ( ! V_4 )
return - V_60 ;
V_4 -> V_12 = F_21 ( V_33 , sizeof( struct V_11 ) ,
V_59 ) ;
if ( ! V_4 -> V_12 )
return - V_60 ;
V_58 = F_22 ( V_54 , V_61 , L_6 ) ;
V_4 -> V_8 = F_23 ( V_33 , V_58 ) ;
if ( F_24 ( V_4 -> V_8 ) )
return F_25 ( V_4 -> V_8 ) ;
V_58 = F_22 ( V_54 , V_61 , L_7 ) ;
V_4 -> V_27 = F_23 ( V_33 , V_58 ) ;
if ( F_24 ( V_4 -> V_27 ) )
return F_25 ( V_4 -> V_27 ) ;
V_58 = F_22 ( V_54 , V_61 , L_8 ) ;
V_4 -> V_18 = F_23 ( V_33 , V_58 ) ;
if ( F_24 ( V_4 -> V_18 ) )
return F_25 ( V_4 -> V_18 ) ;
V_58 = F_22 ( V_54 , V_61 , L_9 ) ;
V_4 -> V_35 = F_23 ( V_33 , V_58 ) ;
if ( F_24 ( V_4 -> V_35 ) )
return F_25 ( V_4 -> V_35 ) ;
V_4 -> V_43 = F_26 ( & V_54 -> V_33 , L_10 , V_62 ) ;
if ( F_24 ( V_4 -> V_43 ) ) {
F_9 ( V_33 , L_11 ) ;
return F_25 ( V_4 -> V_43 ) ;
}
V_4 -> V_44 = F_26 ( & V_54 -> V_33 , L_12 , V_62 ) ;
if ( F_24 ( V_4 -> V_44 ) ) {
F_9 ( V_33 , L_13 ) ;
return F_25 ( V_4 -> V_44 ) ;
}
V_4 -> V_45 = F_27 ( V_33 , V_63 ) ;
if ( F_24 ( V_4 -> V_45 ) ) {
F_9 ( V_33 , L_14 ) ;
return - V_60 ;
}
V_23 = F_28 ( V_33 , V_4 -> V_45 ) ;
if ( V_23 < 0 ) {
F_9 ( V_33 , L_15 ) ;
return V_23 ;
}
V_23 = F_29 ( V_4 -> V_43 , V_64 * 1000 ) ;
if ( V_23 < 0 )
V_4 -> V_51 = F_30 ( V_64 ) ;
F_31 ( & V_4 -> V_42 , F_12 ) ;
V_4 -> V_65 = F_32 ( V_4 -> V_43 ) ;
if ( V_4 -> V_65 < 0 ) {
F_9 ( V_33 , L_16 ) ;
return V_4 -> V_65 ;
}
V_4 -> V_66 = F_32 ( V_4 -> V_44 ) ;
if ( V_4 -> V_66 < 0 ) {
F_9 ( V_33 , L_16 ) ;
return V_4 -> V_66 ;
}
V_23 = F_33 ( V_33 , V_4 -> V_65 , F_18 ,
V_67 | V_68 ,
L_17 , V_4 ) ;
if ( V_23 < 0 ) {
F_9 ( V_33 , L_18 ) ;
return V_23 ;
}
V_23 = F_33 ( V_33 , V_4 -> V_66 , F_18 ,
V_67 | V_68 ,
L_19 , V_4 ) ;
if ( V_23 < 0 ) {
F_9 ( V_33 , L_20 ) ;
return V_23 ;
}
F_34 ( V_33 , V_4 ) ;
V_7 = F_3 ( V_4 -> V_18 ) ;
V_7 &= ~ ( V_19 | V_30 ) ;
F_6 ( V_7 , V_4 -> V_18 ) ;
V_12 = V_4 -> V_12 ;
V_12 -> V_10 = F_35 ( V_33 , V_33 -> V_69 , & V_70 ) ;
if ( F_24 ( V_12 -> V_10 ) ) {
F_9 ( V_33 , L_21 ) ;
return F_25 ( V_12 -> V_10 ) ;
}
V_12 -> V_4 = V_4 ;
F_36 ( V_12 -> V_10 , V_12 ) ;
V_55 = F_37 ( V_33 , V_71 ) ;
if ( F_24 ( V_55 ) ) {
F_9 ( V_33 , L_22 ) ;
return F_25 ( V_55 ) ;
}
F_38 ( V_54 , V_4 ) ;
F_39 ( V_33 , L_23 ) ;
F_19 ( V_50 , & V_4 -> V_42 ,
V_4 -> V_51 ) ;
return 0 ;
}
