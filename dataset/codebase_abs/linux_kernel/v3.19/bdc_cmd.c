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
int V_19 = 0 ;
int V_20 ;
V_9 = F_4 ( V_1 -> V_10 , V_14 ) ;
F_7 ( V_1 -> V_17 ,
L_4 ,
V_21 , V_9 , V_2 , V_3 , V_4 , V_5 ) ;
V_8 = F_6 ( V_9 ) ;
if ( V_8 == V_18 ) {
F_9 ( V_1 -> V_17 , L_5 , V_8 ) ;
return - V_22 ;
}
V_20 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
switch ( V_20 ) {
case V_23 :
F_7 ( V_1 -> V_17 , L_6 ) ;
V_20 = 0 ;
break;
case V_24 :
F_9 ( V_1 -> V_17 , L_7 ) ;
V_20 = - V_25 ;
break;
case V_26 :
F_9 ( V_1 -> V_17 , L_8 ) ;
V_20 = - V_25 ;
break;
case V_27 :
F_9 ( V_1 -> V_17 , L_9 ) ;
V_20 = - V_28 ;
break;
case V_29 :
F_9 ( V_1 -> V_17 , L_10 ) ;
V_19 = 1 ;
V_20 = - V_30 ;
break;
case V_18 :
F_9 ( V_1 -> V_17 ,
L_11 ,
V_7 ) ;
V_19 = 1 ;
V_20 = - V_30 ;
break;
default:
F_7 ( V_1 -> V_17 , L_12 , V_20 ) ;
}
return V_20 ;
}
int F_11 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
T_1 V_2 ;
V_2 = V_33 | F_12 ( V_32 -> V_34 ) | V_35 ;
F_7 ( V_1 -> V_17 , L_13 , V_21 ,
V_32 -> V_34 , V_2 ) ;
return F_10 ( V_1 , V_2 , 0 , 0 , 0 ) ;
}
static void F_13 ( struct V_31 * V_32 )
{
struct V_1 * V_1 = V_32 -> V_1 ;
struct V_36 * V_37 ;
V_32 -> V_38 . V_39 = 0 ;
V_32 -> V_38 . V_40 = 0 ;
V_37 = V_32 -> V_38 . V_41 [ 0 ] -> V_42 ;
F_7 ( V_1 -> V_17 , L_14 , V_21 , V_32 , V_37 ) ;
memset ( V_37 , 0 , sizeof( struct V_36 ) ) ;
V_37 -> V_43 [ 3 ] |= F_14 ( V_44 ) ;
}
int F_15 ( struct V_1 * V_1 , struct V_31 * V_32 )
{
const struct V_45 * V_46 ;
const struct V_47 * V_48 ;
T_1 V_3 , V_4 , V_5 , V_2 ;
T_1 V_49 , V_50 , V_51 , V_52 ;
int V_20 ;
V_48 = V_32 -> V_48 ;
V_46 = V_32 -> V_46 ;
V_2 = V_51 = V_50 = V_5 = 0 ;
V_3 = F_16 ( V_32 -> V_38 . V_41 [ 0 ] -> V_53 ) ;
V_4 = F_17 ( V_32 -> V_38 . V_41 [ 0 ] -> V_53 ) ;
F_18 ( & V_3 ) ;
F_18 ( & V_4 ) ;
F_7 ( V_1 -> V_17 , L_15 ,
V_21 , V_3 , V_4 ) ;
V_52 = V_48 -> V_54 ;
V_52 = F_19 ( V_52 , 1 , 16 ) - 1 ;
V_49 = F_20 ( V_48 ) ;
V_49 &= 0x7ff ;
V_5 |= V_49 << V_55 ;
V_5 |= F_21 ( V_48 ) << V_56 ;
switch ( V_1 -> V_57 . V_58 ) {
case V_59 :
if ( F_22 ( V_48 ) ||
F_23 ( V_48 ) ) {
V_5 |= V_52 ;
if ( F_23 ( V_48 ) && V_46 )
V_51 = V_46 -> V_60 ;
}
V_5 |= V_51 << V_61 ;
if ( V_46 )
V_50 = V_46 -> V_62 ;
V_5 |= V_50 << V_63 ;
break;
case V_64 :
if ( F_23 ( V_48 ) ||
F_22 ( V_48 ) ) {
V_5 |= V_52 ;
V_50 = ( F_20 ( V_48 ) & 0x1800 ) >> 11 ;
V_5 |= V_50 << V_63 ;
}
break;
case V_65 :
case V_66 :
if ( F_23 ( V_48 ) )
V_52 += 3 ;
if ( F_22 ( V_48 ) )
V_52 = F_24 ( V_48 -> V_54 * 8 ) - 1 ;
V_5 |= V_52 ;
break;
default:
F_9 ( V_1 -> V_17 , L_16 ) ;
return - V_25 ;
}
V_2 |= V_35 | F_12 ( V_32 -> V_34 ) | V_67 ;
F_7 ( V_1 -> V_17 , L_17 , V_2 , V_5 ) ;
V_20 = F_10 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if ( V_20 ) {
F_9 ( V_1 -> V_17 , L_18 , V_20 ) ;
return V_20 ;
}
F_13 ( V_32 ) ;
return V_20 ;
}
int F_25 ( struct V_1 * V_1 , struct V_31 * V_32 , T_2 V_68 )
{
T_1 V_3 , V_4 ;
T_1 V_2 = 0 ;
F_7 ( V_1 -> V_17 , L_19 , V_21 ,
( unsigned long long ) ( V_68 ) ) ;
V_3 = F_16 ( V_68 ) ;
V_4 = F_17 ( V_68 ) ;
F_18 ( & V_3 ) ;
F_18 ( & V_4 ) ;
V_2 |= F_12 ( V_32 -> V_34 ) | V_69 ;
F_7 ( V_1 -> V_17 , L_20 , V_2 ) ;
return F_10 ( V_1 , V_2 , V_3 , V_4 , 0 ) ;
}
int F_26 ( struct V_1 * V_1 , T_1 V_70 )
{
T_1 V_2 = 0 ;
T_1 V_5 ;
F_7 ( V_1 -> V_17 , L_21 , V_21 , V_70 ) ;
V_2 |= V_71 | V_72 ;
V_5 = V_70 & 0x7f ;
return F_10 ( V_1 , V_2 , 0 , 0 , V_5 ) ;
}
int F_27 ( struct V_1 * V_1 , T_3 V_73 )
{
T_1 V_3 , V_4 ;
T_1 V_2 = 0 ;
V_3 = V_4 = 0 ;
F_7 ( V_1 -> V_17 , L_22 , V_21 , V_73 ) ;
V_2 |= V_74 ;
V_3 |= V_75 ;
V_3 |= ( V_1 -> V_76 << 25 ) ;
V_4 |= V_77 ;
V_4 |= ( V_78 << 4 ) ;
F_7 ( V_1 -> V_17 , L_23 , V_3 , V_4 ) ;
return F_10 ( V_1 , V_2 , V_3 , V_4 , 0 ) ;
}
int F_28 ( struct V_1 * V_1 , T_3 V_73 )
{
T_1 V_2 = 0 ;
T_1 V_5 = 0 ;
F_7 ( V_1 -> V_17 , L_24 , V_21 , V_73 ) ;
V_5 |= V_73 ;
V_2 |= V_79 | V_80 ;
return F_10 ( V_1 , V_2 , 0 , 0 , V_5 ) ;
}
int F_29 ( struct V_1 * V_1 , int V_81 )
{
T_1 V_2 = 0 ;
F_7 ( V_1 -> V_17 , L_25 , V_21 , V_81 ) ;
V_2 |= V_82 | F_12 ( V_81 ) | V_83 ;
return F_10 ( V_1 , V_2 , 0 , 0 , 0 ) ;
}
int F_30 ( struct V_1 * V_1 , int V_81 )
{
struct V_31 * V_32 ;
T_1 V_2 = 0 ;
int V_20 ;
F_7 ( V_1 -> V_17 , L_26 , V_21 , V_81 ) ;
V_32 = V_1 -> V_84 [ V_81 ] ;
if ( V_81 != 1 ) {
if ( ! ( V_32 -> V_85 & V_86 ) ) {
V_20 = F_29 ( V_1 , V_81 ) ;
if ( V_20 )
return V_20 ;
}
}
if ( V_81 != 1 )
V_2 |= V_87 ;
V_2 |= V_88 | F_12 ( V_81 ) | V_83 ;
V_20 = F_10 ( V_1 , V_2 , 0 , 0 , 0 ) ;
if ( V_20 ) {
F_9 ( V_1 -> V_17 , L_27 , V_20 ) ;
return V_20 ;
}
F_31 ( V_1 , V_81 ) ;
return V_20 ;
}
int F_32 ( struct V_1 * V_1 , int V_81 )
{
struct V_31 * V_32 ;
T_1 V_2 = 0 ;
int V_20 ;
V_32 = V_1 -> V_84 [ V_81 ] ;
F_7 ( V_1 -> V_17 , L_28 , V_21 ,
V_32 -> V_89 , V_32 -> V_85 ) ;
if ( ! ( V_32 -> V_85 & V_90 ) ) {
F_9 ( V_1 -> V_17 , L_29 ) ;
return - V_25 ;
}
if ( ( V_32 -> V_85 & V_86 ) || ( V_32 -> V_85 & V_91 ) )
return 0 ;
V_2 |= V_92 | V_93
| F_12 ( V_81 ) | V_83 ;
V_20 = F_10 ( V_1 , V_2 , 0 , 0 , 0 ) ;
if ( V_20 ) {
F_9 ( V_1 -> V_17 ,
L_30 ,
V_20 , V_32 -> V_89 ) ;
return V_20 ;
}
V_32 -> V_85 |= V_91 ;
F_33 ( V_1 ) ;
return V_20 ;
}
