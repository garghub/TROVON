static T_1 F_1 ( T_2 V_1 )
{
T_2 V_2 , V_3 , V_4 , V_5 ;
T_1 V_6 ;
T_3 V_7 = V_1 / V_8 ;
if ( V_7 % 2 )
return - F_1 ( V_1 - V_8 ) ;
V_1 = V_1 % V_8 ;
if ( V_1 > V_8 / 2 )
return - F_1 ( V_8 / 2 - ( V_1 % ( V_8 / 2 ) ) ) ;
V_2 = V_1 * V_1 / 32768 / 2 ;
V_3 = V_2 * V_1 / 32768 * V_1 / 32768 / 3 / 4 ;
V_4 = V_3 * V_1 / 32768 * V_1 / 32768 / 5 / 6 ;
V_5 = V_4 * V_1 / 32768 * V_1 / 32768 / 7 / 8 ;
V_6 = 32768 - V_2 + V_3 - V_4 + V_5 ;
return V_6 ;
}
static T_2 F_2 ( T_4 V_1 [] , T_2 V_9 , T_2 V_10 )
{
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
T_1 V_13 = 2 * F_1 ( V_10 ) ;
T_2 V_14 ;
T_5 V_15 ;
T_2 V_16 ;
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
T_1 V_17 = V_1 [ V_14 ] + ( ( V_18 ) V_13 * V_11 / 32768 ) - V_12 ;
V_12 = V_11 ;
V_11 = V_17 ;
}
V_15 = ( V_18 ) V_12 * V_12 + ( V_18 ) V_11 * V_11 -
( V_18 ) V_13 * V_12 * V_11 / 32768 ;
V_16 = V_9 * V_9 ;
F_3 ( V_15 , V_16 ) ;
return ( T_2 ) V_15 ;
}
static T_2 F_4 ( T_4 V_1 [] , T_2 V_9 , T_2 V_10 )
{
T_2 V_19 = F_2 ( V_1 , V_9 , V_10 ) ;
return ( T_2 ) F_5 ( V_19 ) ;
}
static T_2 F_6 ( T_4 V_1 [] , T_2 V_9 , T_2 V_20 , T_2 V_21 )
{
int V_14 ;
T_2 V_19 = 0 ;
T_2 V_22 ;
int V_23 = 5 ;
if ( V_9 > 192 ) {
V_1 += ( V_9 - 192 ) ;
V_9 = 192 ;
}
V_22 = ( V_21 - V_20 ) / ( V_23 - 1 ) ;
for ( V_14 = 0 ; V_14 < V_23 ; V_14 ++ ) {
V_19 += F_2 ( V_1 , V_9 , V_20 ) ;
V_20 += V_22 ;
}
return ( T_2 ) F_5 ( V_19 / V_23 ) ;
}
static T_1 F_7 ( struct V_24 * V_25 , T_4 V_1 [] , T_2 V_9 )
{
T_1 V_26 , V_27 , V_28 , V_29 ;
T_1 V_30 , V_31 , V_32 ;
T_1 V_6 ;
switch ( V_25 -> V_33 ) {
case V_34 :
case V_35 :
V_30 = V_36 ;
V_31 = V_37 ;
V_32 = V_38 ;
break;
case V_39 :
V_30 = V_40 ;
V_31 = V_41 ;
V_32 = V_42 ;
break;
case V_43 :
V_30 = V_44 ;
V_31 = V_45 ;
V_32 = V_46 ;
break;
default:
F_8 ( L_1 ,
V_25 -> V_33 , V_47 ) ;
return V_48 ;
}
V_26 = F_4 ( V_1 , V_9 , V_30 ) ;
V_27 = F_4 ( V_1 , V_9 , V_31 ) ;
V_28 = F_4 ( V_1 , V_9 , V_32 ) ;
V_29 = F_6 ( V_1 , V_9 , V_49 , V_50 ) ;
F_9 ( 1 ,
L_2 ,
V_26 , V_27 , V_28 , V_29 ) ;
if ( V_27 > V_28 )
V_6 = V_51 ;
else
V_6 = V_52 | V_53 ;
if ( V_25 -> V_33 == V_43 ) {
if ( ( V_26 > F_10 ( V_27 , V_28 ) * 2 ) &&
( V_26 < F_10 ( V_27 , V_28 ) * 6 ) &&
( V_26 > 20 && V_26 < 200 ) &&
( F_10 ( V_27 , V_28 ) > F_11 ( V_27 , V_28 ) ) ) {
return V_6 ;
}
} else {
if ( ( V_26 > F_10 ( V_27 , V_28 ) * 2 ) &&
( V_26 < F_10 ( V_27 , V_28 ) * 8 ) &&
( V_26 > 20 && V_26 < 200 ) &&
( V_29 < 10 ) &&
( F_10 ( V_27 , V_28 ) > F_11 ( V_27 , V_28 ) * 2 ) ) {
return V_6 ;
}
}
return V_54 ;
}
static T_1 F_12 ( struct V_24 * V_25 , T_4 V_1 [] , T_2 V_9 )
{
T_1 V_55 = F_4 ( V_1 , V_9 , V_56 ) ;
T_1 V_57 = F_4 ( V_1 , V_9 , V_58 ) ;
T_1 V_59 = F_4 ( V_1 , V_9 , V_60 ) ;
T_1 V_28 = F_4 ( V_1 , V_9 , V_61 ) ;
F_9 ( 1 , L_3 ,
V_59 , V_28 , V_55 , V_57 ) ;
return V_48 ;
}
static T_4 * F_13 ( struct V_24 * V_25 , T_2 * V_9 )
{
const struct V_62 * V_63 = & V_64 [ V_65 ] ;
T_4 * V_23 ;
unsigned int V_14 ;
unsigned int V_66 = V_63 -> V_67 / V_68 ;
unsigned int V_69 = V_66 / 4 ;
unsigned int V_70 = V_69 * ( V_68 - 1 ) ;
T_2 V_71 = F_14 ( V_63 -> V_72 ) ;
T_2 V_73 = ( V_71 - V_63 -> V_74 + V_66 ) ;
F_9 ( 1 ,
L_4 ,
V_71 ,
V_71 - V_63 -> V_74 , V_70 ,
F_14 ( V_75 ) ) ;
V_23 = F_15 ( V_70 , sizeof( * V_23 ) , V_76 ) ;
if ( ! V_23 )
return NULL ;
* V_9 = V_70 ;
for ( V_14 = 0 ; V_14 < V_70 ; V_14 ++ ) {
V_73 = V_73 % ( V_68 * V_66 ) ;
V_23 [ V_14 ] = F_14 ( V_63 -> V_74 + V_73 ) ;
V_73 += 4 ;
}
F_9 ( 2 , L_5 , V_70 , V_23 ) ;
return V_23 ;
}
T_1 F_16 ( struct V_24 * V_25 )
{
T_4 * V_23 ;
T_2 V_9 = 0 ;
T_1 V_6 = V_48 ;
if ( ! ( F_14 ( V_77 ) & 0x04 ) )
return V_6 ;
if ( ! ( F_14 ( V_78 ) & V_79 ) )
return V_6 ;
if ( F_17 ( V_80 , V_25 -> V_81 + F_18 ( 500 ) ) )
return V_6 ;
V_23 = F_13 ( V_25 , & V_9 ) ;
if ( ! V_23 )
return V_6 ;
switch ( V_25 -> V_33 ) {
case V_34 :
case V_35 :
case V_43 :
case V_39 :
V_6 = F_7 ( V_25 , V_23 , V_9 ) ;
break;
case V_82 :
V_6 = F_12 ( V_25 , V_23 , V_9 ) ;
break;
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
break;
}
F_19 ( V_23 ) ;
if ( V_6 != V_48 )
F_9 ( 1 , L_6 ,
( V_6 & V_54 ) ? L_7 : L_8 ,
( V_6 & V_51 ) ? L_9 : L_8 ,
( V_6 & V_53 ) ? L_10 : L_8 ) ;
return V_6 ;
}
