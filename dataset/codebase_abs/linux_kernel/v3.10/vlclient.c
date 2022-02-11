static int F_1 ( T_1 V_1 )
{
F_2 ( L_1 , V_1 ) ;
switch ( V_1 ) {
case V_2 : return - V_3 ;
case V_4 : return - V_5 ;
case V_6 : return - V_3 ;
case V_7 : return - V_5 ;
case V_8 : return - V_9 ;
case V_10 : return - V_9 ;
case V_11 : return - V_9 ;
case V_12 : return - V_13 ;
case V_14 : return - V_13 ;
case V_15 : return - V_13 ;
case V_16 : return - V_13 ;
case V_17 : return - V_13 ;
case V_18 : return - V_19 ;
case V_20 : return - V_21 ;
case V_22 : return - V_3 ;
case V_23 : return - V_21 ;
case V_24 : return - V_13 ;
case V_25 : return - V_13 ;
case V_26 : return - V_13 ;
case V_27 : return - V_13 ;
case V_28 : return - V_13 ;
case V_29 : return - V_30 ;
case V_31 : return - V_32 ;
case V_33 : return - V_13 ;
case V_34 : return - V_5 ;
case V_35 : return - V_13 ;
case V_36 : return - V_37 ;
case V_38 : return - V_5 ;
default:
return F_3 ( V_1 ) ;
}
}
static int F_4 ( struct V_39 * V_40 ,
struct V_41 * V_42 , bool V_43 )
{
struct V_44 * V_45 ;
T_2 * V_46 ;
T_1 V_47 ;
int V_48 ;
F_2 ( L_2 , V_43 ) ;
F_5 ( V_40 , V_42 ) ;
if ( ! V_43 )
return 0 ;
if ( V_40 -> V_49 != V_40 -> V_50 )
return - V_51 ;
V_45 = V_40 -> V_52 ;
V_46 = V_40 -> V_53 ;
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_45 -> V_54 [ V_48 ] = F_6 ( * V_46 ++ ) ;
V_45 -> V_54 [ V_48 ] = 0 ;
V_46 ++ ;
V_46 ++ ;
V_45 -> V_55 = F_6 ( * V_46 ++ ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ )
V_45 -> V_56 [ V_48 ] . V_57 = * V_46 ++ ;
V_46 += 8 ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_47 = F_6 ( * V_46 ++ ) ;
V_45 -> V_58 [ V_48 ] = 0 ;
if ( V_47 & V_59 )
V_45 -> V_58 [ V_48 ] |= V_60 ;
if ( V_47 & V_61 )
V_45 -> V_58 [ V_48 ] |= V_62 ;
if ( V_47 & V_63 )
V_45 -> V_58 [ V_48 ] |= V_64 ;
}
V_45 -> V_65 [ 0 ] = F_6 ( * V_46 ++ ) ;
V_45 -> V_65 [ 1 ] = F_6 ( * V_46 ++ ) ;
V_45 -> V_65 [ 2 ] = F_6 ( * V_46 ++ ) ;
V_46 ++ ;
V_47 = F_6 ( * V_46 ++ ) ;
V_45 -> V_66 = 0 ;
if ( V_47 & V_67 )
V_45 -> V_66 |= V_60 ;
if ( V_47 & V_68 )
V_45 -> V_66 |= V_62 ;
if ( V_47 & V_69 )
V_45 -> V_66 |= V_64 ;
if ( ! V_45 -> V_66 )
return - V_51 ;
F_7 ( L_3 ) ;
return 0 ;
}
int F_8 ( struct V_70 * V_71 ,
struct V_72 * V_72 ,
const char * V_73 ,
struct V_44 * V_45 ,
const struct V_74 * V_75 )
{
struct V_39 * V_40 ;
T_3 V_76 , V_77 , V_78 ;
T_2 * V_46 ;
F_2 ( L_4 ) ;
V_76 = strlen ( V_73 ) ;
V_78 = ( 4 - ( V_76 & 3 ) ) & 3 ;
V_77 = 8 + V_76 + V_78 ;
V_40 = F_9 ( & V_79 , V_77 , 384 ) ;
if ( ! V_40 )
return - V_80 ;
V_40 -> V_72 = V_72 ;
V_40 -> V_52 = V_45 ;
V_40 -> V_81 = V_82 ;
V_40 -> V_83 = F_10 ( V_84 ) ;
V_46 = V_40 -> V_85 ;
* V_46 ++ = F_11 ( V_86 ) ;
* V_46 ++ = F_11 ( V_76 ) ;
memcpy ( V_46 , V_73 , V_76 ) ;
if ( V_78 > 0 )
memset ( ( void * ) V_46 + V_76 , 0 , V_78 ) ;
return F_12 ( V_71 , V_40 , V_87 , V_75 ) ;
}
int F_13 ( struct V_70 * V_71 ,
struct V_72 * V_72 ,
T_4 V_88 ,
T_5 V_89 ,
struct V_44 * V_45 ,
const struct V_74 * V_75 )
{
struct V_39 * V_40 ;
T_2 * V_46 ;
F_2 ( L_4 ) ;
V_40 = F_9 ( & V_90 , 12 , 384 ) ;
if ( ! V_40 )
return - V_80 ;
V_40 -> V_72 = V_72 ;
V_40 -> V_52 = V_45 ;
V_40 -> V_81 = V_82 ;
V_40 -> V_83 = F_10 ( V_84 ) ;
V_46 = V_40 -> V_85 ;
* V_46 ++ = F_11 ( V_91 ) ;
* V_46 ++ = F_11 ( V_88 ) ;
* V_46 = F_11 ( V_89 ) ;
return F_12 ( V_71 , V_40 , V_87 , V_75 ) ;
}
