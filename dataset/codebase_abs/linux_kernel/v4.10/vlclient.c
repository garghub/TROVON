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
static int F_4 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
T_2 * V_43 ;
T_1 V_44 ;
int V_45 , V_46 ;
F_2 ( L_2 ) ;
V_46 = F_5 ( V_40 ) ;
if ( V_46 < 0 )
return V_46 ;
V_42 = V_40 -> V_47 ;
V_43 = V_40 -> V_48 ;
for ( V_45 = 0 ; V_45 < 64 ; V_45 ++ )
V_42 -> V_49 [ V_45 ] = F_6 ( * V_43 ++ ) ;
V_42 -> V_49 [ V_45 ] = 0 ;
V_43 ++ ;
V_43 ++ ;
V_42 -> V_50 = F_6 ( * V_43 ++ ) ;
for ( V_45 = 0 ; V_45 < 8 ; V_45 ++ )
V_42 -> V_51 [ V_45 ] . V_52 = * V_43 ++ ;
V_43 += 8 ;
for ( V_45 = 0 ; V_45 < 8 ; V_45 ++ ) {
V_44 = F_6 ( * V_43 ++ ) ;
V_42 -> V_53 [ V_45 ] = 0 ;
if ( V_44 & V_54 )
V_42 -> V_53 [ V_45 ] |= V_55 ;
if ( V_44 & V_56 )
V_42 -> V_53 [ V_45 ] |= V_57 ;
if ( V_44 & V_58 )
V_42 -> V_53 [ V_45 ] |= V_59 ;
}
V_42 -> V_60 [ 0 ] = F_6 ( * V_43 ++ ) ;
V_42 -> V_60 [ 1 ] = F_6 ( * V_43 ++ ) ;
V_42 -> V_60 [ 2 ] = F_6 ( * V_43 ++ ) ;
V_43 ++ ;
V_44 = F_6 ( * V_43 ++ ) ;
V_42 -> V_61 = 0 ;
if ( V_44 & V_62 )
V_42 -> V_61 |= V_55 ;
if ( V_44 & V_63 )
V_42 -> V_61 |= V_57 ;
if ( V_44 & V_64 )
V_42 -> V_61 |= V_59 ;
if ( ! V_42 -> V_61 )
return - V_65 ;
F_7 ( L_3 ) ;
return 0 ;
}
int F_8 ( struct V_66 * V_67 ,
struct V_68 * V_68 ,
const char * V_69 ,
struct V_41 * V_42 ,
const struct V_70 * V_71 )
{
struct V_39 * V_40 ;
T_3 V_72 , V_73 , V_74 ;
T_2 * V_43 ;
F_2 ( L_2 ) ;
V_72 = strlen ( V_69 ) ;
V_74 = ( 4 - ( V_72 & 3 ) ) & 3 ;
V_73 = 8 + V_72 + V_74 ;
V_40 = F_9 ( & V_75 , V_73 , 384 ) ;
if ( ! V_40 )
return - V_76 ;
V_40 -> V_68 = V_68 ;
V_40 -> V_47 = V_42 ;
V_40 -> V_77 = V_78 ;
V_40 -> V_79 = F_10 ( V_80 ) ;
V_43 = V_40 -> V_81 ;
* V_43 ++ = F_11 ( V_82 ) ;
* V_43 ++ = F_11 ( V_72 ) ;
memcpy ( V_43 , V_69 , V_72 ) ;
if ( V_74 > 0 )
memset ( ( void * ) V_43 + V_72 , 0 , V_74 ) ;
return F_12 ( V_67 , V_40 , V_83 , V_71 ) ;
}
int F_13 ( struct V_66 * V_67 ,
struct V_68 * V_68 ,
T_4 V_84 ,
T_5 V_85 ,
struct V_41 * V_42 ,
const struct V_70 * V_71 )
{
struct V_39 * V_40 ;
T_2 * V_43 ;
F_2 ( L_2 ) ;
V_40 = F_9 ( & V_86 , 12 , 384 ) ;
if ( ! V_40 )
return - V_76 ;
V_40 -> V_68 = V_68 ;
V_40 -> V_47 = V_42 ;
V_40 -> V_77 = V_78 ;
V_40 -> V_79 = F_10 ( V_80 ) ;
V_43 = V_40 -> V_81 ;
* V_43 ++ = F_11 ( V_87 ) ;
* V_43 ++ = F_11 ( V_84 ) ;
* V_43 = F_11 ( V_85 ) ;
return F_12 ( V_67 , V_40 , V_83 , V_71 ) ;
}
