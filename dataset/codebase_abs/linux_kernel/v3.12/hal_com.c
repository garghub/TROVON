void F_1 ( struct V_1 V_2 )
{
T_1 V_3 = 0 ;
char V_4 [ 128 ] ;
if ( F_2 ( V_2 ) ) {
V_3 += sprintf ( ( V_4 + V_3 ) , L_1 ,
F_3 ( V_2 ) ?
L_2 : L_3 ) ;
} else if ( F_4 ( V_2 ) ) {
V_3 += sprintf ( ( V_4 + V_3 ) , L_4 ) ;
} else if ( F_5 ( V_2 ) ) {
V_3 += sprintf ( ( V_4 + V_3 ) , L_5 ) ;
} else if ( F_6 ( V_2 ) ) {
V_3 += sprintf ( ( V_4 + V_3 ) , L_6 ) ;
}
V_3 += sprintf ( ( V_4 + V_3 ) , L_7 , F_7 ( V_2 ) ?
L_8 : L_9 ) ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_7 , F_8 ( V_2 ) ?
L_10 : L_11 ) ;
if ( F_9 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_12 ) ;
else if ( F_10 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_13 ) ;
else if ( F_11 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_14 ) ;
else if ( F_12 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_15 ) ;
else if ( F_13 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_16 ) ;
else
V_3 += sprintf ( ( V_4 + V_3 ) , L_17 ,
V_2 . V_5 ) ;
if ( F_14 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_18 ) ;
else if ( F_15 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_19 ) ;
else if ( F_16 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_20 ) ;
else
V_3 += sprintf ( ( V_4 + V_3 ) , L_21 ,
V_2 . V_6 ) ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_22 , V_2 . V_7 ) ;
F_17 ( L_23 , V_4 ) ;
}
T_2
F_18 ( struct V_8 * V_9 , T_2 V_10 ,
T_2 V_11 , T_2 V_12 ,
bool V_13 )
{
T_2 V_14 ;
T_2 V_15 ;
V_14 = true ;
if ( ! V_13 ) {
if ( ! F_19 ( V_11 ) )
V_14 = false ;
if ( V_10 & V_16 )
V_14 = false ;
}
if ( V_14 )
V_15 = V_11 ;
else
V_15 = V_10 & ( ~ V_16 ) ;
if ( ! F_19 ( V_15 ) )
V_15 = V_12 ;
return V_15 ;
}
T_2 F_20 ( T_2 V_17 )
{
T_2 V_18 = V_19 ;
switch ( V_17 ) {
case V_20 :
V_18 = V_19 ;
break;
case V_21 :
V_18 = V_22 ;
break;
case V_23 :
V_18 = V_24 ;
break;
case V_25 :
V_18 = V_26 ;
break;
case V_27 :
V_18 = V_28 ;
break;
case V_29 :
V_18 = V_30 ;
break;
case V_31 :
V_18 = V_32 ;
break;
case V_33 :
V_18 = V_34 ;
break;
case V_35 :
V_18 = V_36 ;
break;
case V_37 :
V_18 = V_38 ;
break;
case V_39 :
V_18 = V_40 ;
break;
case V_41 :
V_18 = V_42 ;
break;
default:
break;
}
return V_18 ;
}
void F_21 ( struct V_8 * V_43 , T_2 * V_44 , T_3 * V_45 )
{
T_2 V_46 , V_47 , V_48 ;
for ( V_46 = 0 ; V_46 < V_49 ; V_46 ++ ) {
V_47 = V_44 [ V_46 ] & V_50 ;
V_48 = V_44 [ V_46 ] & 0x7f ;
if ( V_47 ) {
switch ( V_48 ) {
case V_20 :
* V_45 |= V_51 ;
break;
case V_21 :
* V_45 |= V_52 ;
break;
case V_23 :
* V_45 |= V_53 ;
break;
case V_25 :
* V_45 |= V_54 ;
break;
case V_27 :
* V_45 |= V_55 ;
break;
case V_29 :
* V_45 |= V_56 ;
break;
case V_31 :
* V_45 |= V_57 ;
break;
case V_33 :
* V_45 |= V_58 ;
break;
case V_35 :
* V_45 |= V_59 ;
break;
case V_37 :
* V_45 |= V_60 ;
break;
case V_39 :
* V_45 |= V_61 ;
break;
case V_41 :
* V_45 |= V_62 ;
break;
}
}
}
}
static void F_22 ( struct V_8 * V_8 )
{
struct V_63 * V_64 = F_23 ( V_8 ) ;
V_64 -> V_65 [ 0 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 1 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 2 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 3 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 4 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 5 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 6 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 7 ] = V_64 -> V_66 [ 0 ] ;
}
static void F_24 ( struct V_8 * V_8 , bool V_67 )
{
struct V_63 * V_64 = F_23 ( V_8 ) ;
if ( V_67 ) {
V_64 -> V_65 [ 0 ] = V_64 -> V_66 [ 1 ] ;
V_64 -> V_65 [ 1 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 2 ] = V_64 -> V_66 [ 1 ] ;
V_64 -> V_65 [ 3 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 4 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 5 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 6 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 7 ] = V_64 -> V_66 [ 0 ] ;
} else {
V_64 -> V_65 [ 0 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 1 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 2 ] = V_64 -> V_66 [ 1 ] ;
V_64 -> V_65 [ 3 ] = V_64 -> V_66 [ 1 ] ;
V_64 -> V_65 [ 4 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 5 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 6 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 7 ] = V_64 -> V_66 [ 0 ] ;
}
}
static void F_25 ( struct V_8 * V_8 , bool V_67 )
{
struct V_63 * V_64 = F_23 ( V_8 ) ;
if ( V_67 ) {
V_64 -> V_65 [ 0 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 1 ] = V_64 -> V_66 [ 1 ] ;
V_64 -> V_65 [ 2 ] = V_64 -> V_66 [ 2 ] ;
V_64 -> V_65 [ 3 ] = V_64 -> V_66 [ 1 ] ;
V_64 -> V_65 [ 4 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 5 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 6 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 7 ] = V_64 -> V_66 [ 0 ] ;
} else {
V_64 -> V_65 [ 0 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 1 ] = V_64 -> V_66 [ 1 ] ;
V_64 -> V_65 [ 2 ] = V_64 -> V_66 [ 2 ] ;
V_64 -> V_65 [ 3 ] = V_64 -> V_66 [ 2 ] ;
V_64 -> V_65 [ 4 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 5 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 6 ] = V_64 -> V_66 [ 0 ] ;
V_64 -> V_65 [ 7 ] = V_64 -> V_66 [ 0 ] ;
}
}
bool F_26 ( struct V_8 * V_8 , T_2 V_68 )
{
struct V_69 * V_70 = & V_8 -> V_71 ;
bool V_67 = ( V_70 -> V_72 ) ? true : false ;
bool V_73 = true ;
switch ( V_68 ) {
case 2 :
F_24 ( V_8 , V_67 ) ;
break;
case 3 :
F_25 ( V_8 , V_67 ) ;
break;
case 1 :
F_22 ( V_8 ) ;
break;
default:
V_73 = false ;
break;
}
return V_73 ;
}
void F_27 ( struct V_8 * V_8 )
{
F_28 ( V_8 , V_74 ,
V_8 -> V_75 . V_76 ) ;
}
void F_29 ( struct V_8 * V_8 )
{
F_30 ( V_8 , V_77 , V_78 ) ;
}
T_4 F_31 ( struct V_8 * V_8 , T_2 * V_4 )
{
T_4 V_18 = V_79 ;
struct V_80 * V_81 ;
int V_46 ;
T_2 V_82 ;
if ( V_4 == NULL )
goto exit;
V_82 = F_32 ( V_8 , V_77 ) ;
if ( V_82 == V_78 )
goto exit;
else if ( V_82 != V_83 )
goto V_84;
V_81 = (struct V_80 * ) V_4 ;
F_33 ( V_81 , 0 , 16 ) ;
* V_4 = F_32 ( V_8 , V_85 ) ;
* ( V_4 + 1 ) = F_32 ( V_8 , V_85 + 1 ) ;
F_34 ( V_86 , V_87 , L_24 ,
& V_81 , sizeof( V_81 ) ) ;
for ( V_46 = 0 ; V_46 < V_81 -> V_88 ; V_46 ++ )
V_81 -> V_89 [ V_46 ] = F_32 ( V_8 , V_85 +
sizeof( * V_81 ) + V_46 ) ;
F_34 ( V_86 , V_87 ,
L_25 ,
V_81 -> V_89 , V_81 -> V_88 ) ;
V_18 = V_90 ;
V_84:
F_29 ( V_8 ) ;
exit:
return V_18 ;
}
