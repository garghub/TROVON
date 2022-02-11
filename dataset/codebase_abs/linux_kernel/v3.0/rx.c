static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = V_2 -> V_6 -> V_5 ;
if ( V_2 -> V_7 )
V_5 += V_2 -> V_6 -> V_8 ;
F_2 ( V_2 , V_5 , V_4 , sizeof( * V_4 ) ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
T_3 V_12 ;
int V_13 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_14 = V_15 ;
V_10 -> V_12 = V_4 -> V_16 ;
if ( ( V_2 -> V_17 == V_18 ) && V_11 ) {
V_13 = F_4 ( V_2 , & V_12 ) ;
if ( V_13 == 0 )
V_10 -> V_12 = V_12 ;
}
V_10 -> signal = V_4 -> V_19 ;
V_2 -> V_20 = V_4 -> V_19 - V_4 -> V_21 / 2 ;
V_10 -> V_22 = F_5 ( V_4 -> V_23 ,
V_10 -> V_14 ) ;
V_10 -> V_24 |= V_25 ;
if ( V_4 -> V_26 & V_27 ) {
V_10 -> V_24 |= V_28 | V_29 ;
if ( F_6 ( ! ( V_4 -> V_26 & V_30 ) ) )
V_10 -> V_24 |= V_31 ;
if ( F_7 ( V_4 -> V_26 & V_32 ) )
V_10 -> V_24 |= V_33 ;
}
if ( F_7 ( ! ( V_4 -> V_26 & V_34 ) ) )
V_10 -> V_24 |= V_35 ;
switch ( V_4 -> V_36 ) {
case V_37 :
V_10 -> V_38 = 1 ;
break;
case V_39 :
V_10 -> V_38 = 2 ;
break;
case V_40 :
V_10 -> V_38 = 3 ;
break;
case V_41 :
V_10 -> V_38 = 4 ;
break;
case V_42 :
V_10 -> V_38 = 5 ;
break;
case V_43 :
V_10 -> V_38 = 7 ;
break;
case V_44 :
V_10 -> V_38 = 8 ;
break;
case V_45 :
V_10 -> V_38 = 9 ;
break;
case V_46 :
V_10 -> V_38 = 10 ;
break;
case V_47 :
V_10 -> V_38 = 11 ;
break;
}
if ( V_4 -> V_36 == V_48 ) {
if ( ! ( V_4 -> V_49 & V_50 ) )
V_10 -> V_38 = 0 ;
else
V_10 -> V_38 = 6 ;
}
if ( V_4 -> V_49 & V_51 )
V_10 -> V_24 |= V_52 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_53 * V_54 ;
struct V_9 V_10 ;
T_2 * V_55 , V_11 = 0 ;
T_4 V_56 , * V_57 ;
T_1 V_58 , V_59 , V_5 ;
V_56 = F_9 ( V_4 -> V_56 - V_60 ) ;
V_58 = ( V_4 -> V_26 & V_61 ) >> V_62 ;
V_59 = ( V_2 -> V_63 + 1 ) % ( V_64 + 1 ) ;
if ( V_59 != V_58 ) {
F_10 ( L_1 ,
V_58 , V_59 ) ;
V_2 -> V_63 = V_58 ;
} else {
V_2 -> V_63 = V_59 ;
}
V_5 = V_2 -> V_6 -> V_5 +
sizeof( struct V_3 ) + 20 ;
if ( V_2 -> V_7 )
V_5 += V_2 -> V_6 -> V_8 ;
V_54 = F_11 ( V_56 , V_65 ) ;
if ( ! V_54 ) {
F_12 ( L_2 ) ;
return;
}
V_55 = F_13 ( V_54 , V_56 ) ;
F_2 ( V_2 , V_5 , V_55 , V_56 ) ;
V_54 -> V_66 = V_4 -> V_56 - V_60 ;
V_57 = ( T_4 * ) V_54 -> V_67 ;
if ( ( * V_57 & V_68 ) == V_69 )
V_11 = 1 ;
F_3 ( V_2 , V_4 , & V_10 , V_11 ) ;
F_14 ( V_70 , L_3 , V_54 , V_54 -> V_66 ,
V_11 ? L_4 : L_5 ) ;
memcpy ( F_15 ( V_54 ) , & V_10 , sizeof( V_10 ) ) ;
F_16 ( V_2 -> V_71 , V_54 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_67 , V_72 ;
if ( V_2 -> V_7 ) {
V_72 = V_73 ;
V_67 = V_74 ;
} else {
V_72 = V_75 ;
V_67 = V_76 ;
}
F_18 ( V_2 , V_72 , V_67 ) ;
V_2 -> V_7 = ! V_2 -> V_7 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_77 ;
if ( V_2 -> V_78 != V_79 )
return;
V_77 = V_2 -> V_80 ;
F_1 ( V_2 , V_77 ) ;
F_8 ( V_2 , V_77 ) ;
F_17 ( V_2 ) ;
}
