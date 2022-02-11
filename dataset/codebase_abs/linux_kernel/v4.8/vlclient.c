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
int V_48 , V_49 ;
F_2 ( L_2 , V_43 ) ;
V_49 = F_5 ( V_40 , V_42 , V_43 ) ;
if ( V_49 < 0 )
return V_49 ;
V_45 = V_40 -> V_50 ;
V_46 = V_40 -> V_51 ;
for ( V_48 = 0 ; V_48 < 64 ; V_48 ++ )
V_45 -> V_52 [ V_48 ] = F_6 ( * V_46 ++ ) ;
V_45 -> V_52 [ V_48 ] = 0 ;
V_46 ++ ;
V_46 ++ ;
V_45 -> V_53 = F_6 ( * V_46 ++ ) ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ )
V_45 -> V_54 [ V_48 ] . V_55 = * V_46 ++ ;
V_46 += 8 ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_47 = F_6 ( * V_46 ++ ) ;
V_45 -> V_56 [ V_48 ] = 0 ;
if ( V_47 & V_57 )
V_45 -> V_56 [ V_48 ] |= V_58 ;
if ( V_47 & V_59 )
V_45 -> V_56 [ V_48 ] |= V_60 ;
if ( V_47 & V_61 )
V_45 -> V_56 [ V_48 ] |= V_62 ;
}
V_45 -> V_63 [ 0 ] = F_6 ( * V_46 ++ ) ;
V_45 -> V_63 [ 1 ] = F_6 ( * V_46 ++ ) ;
V_45 -> V_63 [ 2 ] = F_6 ( * V_46 ++ ) ;
V_46 ++ ;
V_47 = F_6 ( * V_46 ++ ) ;
V_45 -> V_64 = 0 ;
if ( V_47 & V_65 )
V_45 -> V_64 |= V_58 ;
if ( V_47 & V_66 )
V_45 -> V_64 |= V_60 ;
if ( V_47 & V_67 )
V_45 -> V_64 |= V_62 ;
if ( ! V_45 -> V_64 )
return - V_68 ;
F_7 ( L_3 ) ;
return 0 ;
}
int F_8 ( struct V_69 * V_70 ,
struct V_71 * V_71 ,
const char * V_72 ,
struct V_44 * V_45 ,
const struct V_73 * V_74 )
{
struct V_39 * V_40 ;
T_3 V_75 , V_76 , V_77 ;
T_2 * V_46 ;
F_2 ( L_4 ) ;
V_75 = strlen ( V_72 ) ;
V_77 = ( 4 - ( V_75 & 3 ) ) & 3 ;
V_76 = 8 + V_75 + V_77 ;
V_40 = F_9 ( & V_78 , V_76 , 384 ) ;
if ( ! V_40 )
return - V_79 ;
V_40 -> V_71 = V_71 ;
V_40 -> V_50 = V_45 ;
V_40 -> V_80 = V_81 ;
V_40 -> V_82 = F_10 ( V_83 ) ;
V_46 = V_40 -> V_84 ;
* V_46 ++ = F_11 ( V_85 ) ;
* V_46 ++ = F_11 ( V_75 ) ;
memcpy ( V_46 , V_72 , V_75 ) ;
if ( V_77 > 0 )
memset ( ( void * ) V_46 + V_75 , 0 , V_77 ) ;
return F_12 ( V_70 , V_40 , V_86 , V_74 ) ;
}
int F_13 ( struct V_69 * V_70 ,
struct V_71 * V_71 ,
T_4 V_87 ,
T_5 V_88 ,
struct V_44 * V_45 ,
const struct V_73 * V_74 )
{
struct V_39 * V_40 ;
T_2 * V_46 ;
F_2 ( L_4 ) ;
V_40 = F_9 ( & V_89 , 12 , 384 ) ;
if ( ! V_40 )
return - V_79 ;
V_40 -> V_71 = V_71 ;
V_40 -> V_50 = V_45 ;
V_40 -> V_80 = V_81 ;
V_40 -> V_82 = F_10 ( V_83 ) ;
V_46 = V_40 -> V_84 ;
* V_46 ++ = F_11 ( V_90 ) ;
* V_46 ++ = F_11 ( V_87 ) ;
* V_46 = F_11 ( V_88 ) ;
return F_12 ( V_70 , V_40 , V_86 , V_74 ) ;
}
