static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 = V_7 ;
T_1 V_8 ;
T_1 V_9 ;
F_2 ( V_1 -> V_10 , V_11 , V_3 ) ;
F_2 ( V_1 -> V_10 , V_12 , V_4 ) ;
F_2 ( V_1 -> V_10 , V_13 , V_5 ) ;
F_3 () ;
F_2 ( V_1 -> V_10 , V_14 , V_2 | V_15 | V_16 ) ;
do {
V_9 = F_4 ( V_1 -> V_10 , V_14 ) ;
F_5 ( V_1 -> V_17 , L_1 , V_9 ) ;
V_8 = F_6 ( V_9 ) ;
if ( V_8 != V_18 ) {
F_7 ( V_1 -> V_17 ,
L_2 , V_8 ) ;
return V_8 ;
}
F_8 ( 1 ) ;
} while ( V_6 -- );
F_9 ( V_1 -> V_17 ,
L_3 , V_8 ) ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_9 , V_8 ;
int V_19 ;
V_9 = F_4 ( V_1 -> V_10 , V_14 ) ;
F_7 ( V_1 -> V_17 ,
L_4 ,
V_20 , V_9 , V_2 , V_3 , V_4 , V_5 ) ;
V_8 = F_6 ( V_9 ) ;
if ( V_8 == V_18 ) {
F_9 ( V_1 -> V_17 , L_5 , V_8 ) ;
return - V_21 ;
}
V_19 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
switch ( V_19 ) {
case V_22 :
F_7 ( V_1 -> V_17 , L_6 ) ;
V_19 = 0 ;
break;
case V_23 :
F_9 ( V_1 -> V_17 , L_7 ) ;
V_19 = - V_24 ;
break;
case V_25 :
F_9 ( V_1 -> V_17 , L_8 ) ;
V_19 = - V_24 ;
break;
case V_26 :
F_9 ( V_1 -> V_17 , L_9 ) ;
V_19 = - V_27 ;
break;
case V_28 :
F_9 ( V_1 -> V_17 , L_10 ) ;
V_19 = - V_29 ;
break;
case V_18 :
F_9 ( V_1 -> V_17 ,
L_11 ,
V_7 ) ;
V_19 = - V_29 ;
break;
default:
F_7 ( V_1 -> V_17 , L_12 , V_19 ) ;
}
return V_19 ;
}
int F_11 ( struct V_1 * V_1 , struct V_30 * V_31 )
{
T_1 V_2 ;
V_2 = V_32 | F_12 ( V_31 -> V_33 ) | V_34 ;
F_7 ( V_1 -> V_17 , L_13 , V_20 ,
V_31 -> V_33 , V_2 ) ;
return F_10 ( V_1 , V_2 , 0 , 0 , 0 ) ;
}
static void F_13 ( struct V_30 * V_31 )
{
struct V_1 * V_1 = V_31 -> V_1 ;
struct V_35 * V_36 ;
V_31 -> V_37 . V_38 = 0 ;
V_31 -> V_37 . V_39 = 0 ;
V_36 = V_31 -> V_37 . V_40 [ 0 ] -> V_41 ;
F_7 ( V_1 -> V_17 , L_14 , V_20 , V_31 , V_36 ) ;
memset ( V_36 , 0 , sizeof( struct V_35 ) ) ;
V_36 -> V_42 [ 3 ] |= F_14 ( V_43 ) ;
}
int F_15 ( struct V_1 * V_1 , struct V_30 * V_31 )
{
const struct V_44 * V_45 ;
const struct V_46 * V_47 ;
T_1 V_3 , V_4 , V_5 , V_2 ;
T_1 V_48 , V_49 , V_50 , V_51 ;
int V_19 ;
V_47 = V_31 -> V_47 ;
V_45 = V_31 -> V_45 ;
V_2 = V_50 = V_49 = V_5 = 0 ;
V_3 = F_16 ( V_31 -> V_37 . V_40 [ 0 ] -> V_52 ) ;
V_4 = F_17 ( V_31 -> V_37 . V_40 [ 0 ] -> V_52 ) ;
F_18 ( & V_3 ) ;
F_18 ( & V_4 ) ;
F_7 ( V_1 -> V_17 , L_15 ,
V_20 , V_3 , V_4 ) ;
V_51 = V_47 -> V_53 ;
V_51 = F_19 ( V_51 , 1 , 16 ) - 1 ;
V_48 = F_20 ( V_47 ) ;
V_48 &= 0x7ff ;
V_5 |= V_48 << V_54 ;
V_5 |= F_21 ( V_47 ) << V_55 ;
switch ( V_1 -> V_56 . V_57 ) {
case V_58 :
if ( F_22 ( V_47 ) ||
F_23 ( V_47 ) ) {
V_5 |= V_51 ;
if ( F_23 ( V_47 ) && V_45 )
V_50 = V_45 -> V_59 ;
}
V_5 |= V_50 << V_60 ;
if ( V_45 )
V_49 = V_45 -> V_61 ;
V_5 |= V_49 << V_62 ;
break;
case V_63 :
if ( F_23 ( V_47 ) ||
F_22 ( V_47 ) ) {
V_5 |= V_51 ;
V_49 = ( F_20 ( V_47 ) & 0x1800 ) >> 11 ;
V_5 |= V_49 << V_62 ;
}
break;
case V_64 :
case V_65 :
if ( F_23 ( V_47 ) )
V_51 += 3 ;
if ( F_22 ( V_47 ) )
V_51 = F_24 ( V_47 -> V_53 * 8 ) - 1 ;
V_5 |= V_51 ;
break;
default:
F_9 ( V_1 -> V_17 , L_16 ) ;
return - V_24 ;
}
V_2 |= V_34 | F_12 ( V_31 -> V_33 ) | V_66 ;
F_7 ( V_1 -> V_17 , L_17 , V_2 , V_5 ) ;
V_19 = F_10 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_19 ) {
F_9 ( V_1 -> V_17 , L_18 , V_19 ) ;
return V_19 ;
}
F_13 ( V_31 ) ;
return V_19 ;
}
int F_25 ( struct V_1 * V_1 , struct V_30 * V_31 , T_2 V_67 )
{
T_1 V_3 , V_4 ;
T_1 V_2 = 0 ;
F_7 ( V_1 -> V_17 , L_19 , V_20 ,
( unsigned long long ) ( V_67 ) ) ;
V_3 = F_16 ( V_67 ) ;
V_4 = F_17 ( V_67 ) ;
F_18 ( & V_3 ) ;
F_18 ( & V_4 ) ;
V_2 |= F_12 ( V_31 -> V_33 ) | V_68 ;
F_7 ( V_1 -> V_17 , L_20 , V_2 ) ;
return F_10 ( V_1 , V_2 , V_3 , V_4 , 0 ) ;
}
int F_26 ( struct V_1 * V_1 , T_1 V_69 )
{
T_1 V_2 = 0 ;
T_1 V_5 ;
F_7 ( V_1 -> V_17 , L_21 , V_20 , V_69 ) ;
V_2 |= V_70 | V_71 ;
V_5 = V_69 & 0x7f ;
return F_10 ( V_1 , V_2 , 0 , 0 , V_5 ) ;
}
int F_27 ( struct V_1 * V_1 , T_3 V_72 )
{
T_1 V_3 , V_4 ;
T_1 V_2 = 0 ;
V_3 = V_4 = 0 ;
F_7 ( V_1 -> V_17 , L_22 , V_20 , V_72 ) ;
V_2 |= V_73 ;
V_3 |= V_74 ;
V_3 |= ( V_1 -> V_75 << 25 ) ;
V_4 |= V_76 ;
V_4 |= ( V_77 << 4 ) ;
F_7 ( V_1 -> V_17 , L_23 , V_3 , V_4 ) ;
return F_10 ( V_1 , V_2 , V_3 , V_4 , 0 ) ;
}
int F_28 ( struct V_1 * V_1 , T_3 V_72 )
{
T_1 V_2 = 0 ;
T_1 V_5 = 0 ;
F_7 ( V_1 -> V_17 , L_24 , V_20 , V_72 ) ;
V_5 |= V_72 ;
V_2 |= V_78 | V_79 ;
return F_10 ( V_1 , V_2 , 0 , 0 , V_5 ) ;
}
int F_29 ( struct V_1 * V_1 , int V_80 )
{
T_1 V_2 = 0 ;
F_7 ( V_1 -> V_17 , L_25 , V_20 , V_80 ) ;
V_2 |= V_81 | F_12 ( V_80 ) | V_82 ;
return F_10 ( V_1 , V_2 , 0 , 0 , 0 ) ;
}
int F_30 ( struct V_1 * V_1 , int V_80 )
{
struct V_30 * V_31 ;
T_1 V_2 = 0 ;
int V_19 ;
F_7 ( V_1 -> V_17 , L_26 , V_20 , V_80 ) ;
V_31 = V_1 -> V_83 [ V_80 ] ;
if ( V_80 != 1 ) {
if ( ! ( V_31 -> V_84 & V_85 ) ) {
V_19 = F_29 ( V_1 , V_80 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( V_80 != 1 )
V_2 |= V_86 ;
V_2 |= V_87 | F_12 ( V_80 ) | V_82 ;
V_19 = F_10 ( V_1 , V_2 , 0 , 0 , 0 ) ;
if ( V_19 ) {
F_9 ( V_1 -> V_17 , L_27 , V_19 ) ;
return V_19 ;
}
F_31 ( V_1 , V_80 ) ;
return V_19 ;
}
int F_32 ( struct V_1 * V_1 , int V_80 )
{
struct V_30 * V_31 ;
T_1 V_2 = 0 ;
int V_19 ;
V_31 = V_1 -> V_83 [ V_80 ] ;
F_7 ( V_1 -> V_17 , L_28 , V_20 ,
V_31 -> V_88 , V_31 -> V_84 ) ;
if ( ! ( V_31 -> V_84 & V_89 ) ) {
F_9 ( V_1 -> V_17 , L_29 ) ;
return - V_24 ;
}
if ( ( V_31 -> V_84 & V_85 ) || ( V_31 -> V_84 & V_90 ) )
return 0 ;
V_2 |= V_91 | V_92
| F_12 ( V_80 ) | V_82 ;
V_19 = F_10 ( V_1 , V_2 , 0 , 0 , 0 ) ;
if ( V_19 ) {
F_9 ( V_1 -> V_17 ,
L_30 ,
V_19 , V_31 -> V_88 ) ;
return V_19 ;
}
V_31 -> V_84 |= V_90 ;
F_33 ( V_1 ) ;
return V_19 ;
}
