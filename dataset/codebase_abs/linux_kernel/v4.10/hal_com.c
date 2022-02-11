void F_1 ( struct V_1 V_2 )
{
T_1 V_3 = 0 ;
char V_4 [ 128 ] ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_1 ) ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_2 , V_2 . V_5 == V_6 ?
L_3 : L_4 ) ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_2 , V_2 . V_7 == V_8 ?
L_5 : L_6 ) ;
if ( V_2 . V_9 == V_10 )
V_3 += sprintf ( ( V_4 + V_3 ) , L_7 ) ;
else if ( V_2 . V_9 == V_11 )
V_3 += sprintf ( ( V_4 + V_3 ) , L_8 ) ;
else if ( V_2 . V_9 == V_12 )
V_3 += sprintf ( ( V_4 + V_3 ) , L_9 ) ;
else if ( V_2 . V_9 == V_13 )
V_3 += sprintf ( ( V_4 + V_3 ) , L_10 ) ;
else if ( V_2 . V_9 == V_14 )
V_3 += sprintf ( ( V_4 + V_3 ) , L_11 ) ;
else
V_3 += sprintf ( ( V_4 + V_3 ) , L_12 ,
V_2 . V_9 ) ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_13 ) ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_14 ) ;
F_2 ( L_15 , V_4 ) ;
}
T_2
F_3 ( struct V_15 * V_16 , T_2 V_17 ,
T_2 V_18 , T_2 V_19 ,
bool V_20 )
{
T_2 V_21 ;
T_2 V_22 ;
V_21 = true ;
if ( ! V_20 ) {
if ( ! F_4 ( V_18 ) )
V_21 = false ;
if ( V_17 & V_23 )
V_21 = false ;
}
if ( V_21 )
V_22 = V_18 ;
else
V_22 = V_17 & ( ~ V_23 ) ;
if ( ! F_4 ( V_22 ) )
V_22 = V_19 ;
return V_22 ;
}
T_2 F_5 ( T_2 V_24 )
{
T_2 V_25 = V_26 ;
switch ( V_24 ) {
case V_27 :
V_25 = V_26 ;
break;
case V_28 :
V_25 = V_29 ;
break;
case V_30 :
V_25 = V_31 ;
break;
case V_32 :
V_25 = V_33 ;
break;
case V_34 :
V_25 = V_35 ;
break;
case V_36 :
V_25 = V_37 ;
break;
case V_38 :
V_25 = V_39 ;
break;
case V_40 :
V_25 = V_41 ;
break;
case V_42 :
V_25 = V_43 ;
break;
case V_44 :
V_25 = V_45 ;
break;
case V_46 :
V_25 = V_47 ;
break;
case V_48 :
V_25 = V_49 ;
break;
default:
break;
}
return V_25 ;
}
void F_6 ( struct V_15 * V_50 , T_2 * V_51 , T_3 * V_52 )
{
T_2 V_53 , V_54 , V_55 ;
for ( V_53 = 0 ; V_53 < V_56 ; V_53 ++ ) {
V_54 = V_51 [ V_53 ] & V_57 ;
V_55 = V_51 [ V_53 ] & 0x7f ;
if ( V_54 ) {
switch ( V_55 ) {
case V_27 :
* V_52 |= V_58 ;
break;
case V_28 :
* V_52 |= V_59 ;
break;
case V_30 :
* V_52 |= V_60 ;
break;
case V_32 :
* V_52 |= V_61 ;
break;
case V_34 :
* V_52 |= V_62 ;
break;
case V_36 :
* V_52 |= V_63 ;
break;
case V_38 :
* V_52 |= V_64 ;
break;
case V_40 :
* V_52 |= V_65 ;
break;
case V_42 :
* V_52 |= V_66 ;
break;
case V_44 :
* V_52 |= V_67 ;
break;
case V_46 :
* V_52 |= V_68 ;
break;
case V_48 :
* V_52 |= V_69 ;
break;
}
}
}
}
static void F_7 ( struct V_15 * V_15 )
{
struct V_70 * V_71 = F_8 ( V_15 ) ;
V_71 -> V_72 [ 0 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 1 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 2 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 3 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 4 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 5 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 6 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 7 ] = V_71 -> V_73 [ 0 ] ;
}
static void F_9 ( struct V_15 * V_15 , bool V_74 )
{
struct V_70 * V_71 = F_8 ( V_15 ) ;
if ( V_74 ) {
V_71 -> V_72 [ 0 ] = V_71 -> V_73 [ 1 ] ;
V_71 -> V_72 [ 1 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 2 ] = V_71 -> V_73 [ 1 ] ;
V_71 -> V_72 [ 3 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 4 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 5 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 6 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 7 ] = V_71 -> V_73 [ 0 ] ;
} else {
V_71 -> V_72 [ 0 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 1 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 2 ] = V_71 -> V_73 [ 1 ] ;
V_71 -> V_72 [ 3 ] = V_71 -> V_73 [ 1 ] ;
V_71 -> V_72 [ 4 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 5 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 6 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 7 ] = V_71 -> V_73 [ 0 ] ;
}
}
static void F_10 ( struct V_15 * V_15 , bool V_74 )
{
struct V_70 * V_71 = F_8 ( V_15 ) ;
if ( V_74 ) {
V_71 -> V_72 [ 0 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 1 ] = V_71 -> V_73 [ 1 ] ;
V_71 -> V_72 [ 2 ] = V_71 -> V_73 [ 2 ] ;
V_71 -> V_72 [ 3 ] = V_71 -> V_73 [ 1 ] ;
V_71 -> V_72 [ 4 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 5 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 6 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 7 ] = V_71 -> V_73 [ 0 ] ;
} else {
V_71 -> V_72 [ 0 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 1 ] = V_71 -> V_73 [ 1 ] ;
V_71 -> V_72 [ 2 ] = V_71 -> V_73 [ 2 ] ;
V_71 -> V_72 [ 3 ] = V_71 -> V_73 [ 2 ] ;
V_71 -> V_72 [ 4 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 5 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 6 ] = V_71 -> V_73 [ 0 ] ;
V_71 -> V_72 [ 7 ] = V_71 -> V_73 [ 0 ] ;
}
}
bool F_11 ( struct V_15 * V_15 , T_2 V_75 )
{
struct V_76 * V_77 = & V_15 -> V_78 ;
bool V_74 = ( V_77 -> V_79 ) ? true : false ;
bool V_80 = true ;
switch ( V_75 ) {
case 2 :
F_9 ( V_15 , V_74 ) ;
break;
case 3 :
F_10 ( V_15 , V_74 ) ;
break;
case 1 :
F_7 ( V_15 ) ;
break;
default:
V_80 = false ;
break;
}
return V_80 ;
}
void F_12 ( struct V_15 * V_15 )
{
F_13 ( V_15 , V_81 ,
V_15 -> V_82 . V_83 ) ;
}
