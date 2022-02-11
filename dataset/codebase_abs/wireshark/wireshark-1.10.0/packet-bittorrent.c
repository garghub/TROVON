static T_1
F_1 ( T_2 * T_3 V_1 , T_4 * V_2 , int V_3 )
{
T_5 type ;
T_6 V_4 ;
if ( F_2 ( V_2 , V_3 ) == 19 &&
F_3 ( V_2 , V_3 + 1 , L_1 , 19 ) == 0 ) {
return 1 +
19 +
8 +
20 +
20 ;
} else {
V_4 = F_4 ( V_2 , V_3 ) ;
if( V_4 == 0 ) {
return V_5 ;
}
if( F_5 ( V_2 , V_3 + V_5 ) ) {
type = F_2 ( V_2 , V_3 + V_5 ) ;
if( ( type <= V_6 || type == V_7 ) && V_4 < 0x1000000 ) {
return V_5 + V_4 ;
} else {
return F_6 ( V_2 , V_3 ) ;
}
} else {
return F_6 ( V_2 , V_3 ) ;
}
}
}
static int
F_7 ( T_4 * V_2 , T_2 * T_3 V_1 ,
int V_3 , int V_4 , T_7 * V_8 , T_8 * V_9 , int V_10 )
{
T_5 V_11 ;
int V_12 = 0 , V_13 ;
int V_14 ;
int V_15 = 0 ;
if ( V_4 < 2 ) {
if ( V_8 ) {
F_8 ( V_8 , V_2 , V_3 , V_4 , L_2 ) ;
}
return - 1 ;
}
V_14 = 0 ;
while ( V_4 >= 1 ) {
V_11 = F_2 ( V_2 , V_3 + V_14 ) ;
V_4 -- ;
V_14 ++ ;
if ( V_11 == ':' && V_14 > 1 ) {
if ( V_12 > V_4 || V_12 < 0 ) {
if ( V_8 ) {
F_8 ( V_8 , V_2 , V_3 , V_4 , L_3 ) ;
}
return - 1 ;
}
if ( V_8 ) {
F_9 ( V_8 , V_16 , V_2 , V_3 , V_14 , V_12 ) ;
F_10 ( V_8 , V_17 , V_2 , V_3 + V_14 , V_12 , V_18 | V_19 ) ;
if ( V_10 == 1 ) {
F_11 ( V_9 , L_4 , F_12 ( ( V_20 * ) F_13 ( V_2 , V_3 + V_14 , V_12 ) , V_12 ) ) ;
}
if ( V_10 == 2 ) {
F_11 ( V_9 , L_5 , F_12 ( ( V_20 * ) F_13 ( V_2 , V_3 + V_14 , V_12 ) , V_12 ) ) ;
}
}
return V_14 + V_12 ;
}
if ( ! V_15 && V_11 >= '0' && V_11 <= '9' ) {
if ( V_11 == '0' && V_14 == 1 ) {
V_15 = 1 ;
}
V_13 = ( V_12 * 10 ) + ( V_11 - '0' ) ;
if ( V_13 >= V_12 ) {
V_12 = V_13 ;
continue;
}
}
if ( V_8 ) {
F_8 ( V_8 , V_2 , V_3 , V_4 , L_2 ) ;
}
return - 1 ;
}
if ( V_8 ) {
F_8 ( V_8 , V_2 , V_3 , V_4 , L_6 ) ;
}
return - 1 ;
}
static int
F_14 ( T_4 * V_2 , T_2 * T_3 V_1 ,
int V_3 , int V_4 , T_7 * V_8 , T_8 * V_9 , int V_10 )
{
T_9 V_21 = 0 ;
int V_22 = 0 ;
int V_15 = 0 ;
int V_14 ;
T_5 V_11 ;
if ( V_4 < 3 ) {
if ( V_8 ) {
F_8 ( V_8 , V_2 , V_3 , V_4 , L_7 ) ;
}
return - 1 ;
}
V_4 -- ;
V_14 = 1 ;
while ( V_4 >= 1 ) {
V_11 = F_2 ( V_2 , V_3 + V_14 ) ;
V_4 -- ;
V_14 ++ ;
switch ( V_11 ) {
case 'e' :
if ( V_8 ) {
if ( V_22 ) V_21 = - V_21 ;
F_15 ( V_8 , V_23 , V_2 , V_3 , V_14 , V_21 ) ;
if ( V_10 == 2 ) {
F_11 ( V_9 , L_8 , V_21 ) ;
}
}
return V_14 ;
case '-' :
if ( V_14 == 2 ) {
V_22 = 1 ;
break;
}
default:
if ( ! ( V_11 == '0' && V_14 == 3 && V_22 ) ) {
if ( V_11 == '0' && V_14 == 2 ) {
V_15 = 1 ;
break;
}
if ( ! V_15 && V_11 >= '0' && V_11 <= '9' ) {
V_21 = ( V_21 * 10 ) + ( V_11 - '0' ) ;
break;
}
}
if ( V_8 ) {
F_8 ( V_8 , V_2 , V_3 , V_4 , L_7 ) ;
}
return - 1 ;
}
}
if ( V_8 ) {
F_8 ( V_8 , V_2 , V_3 , V_4 , L_6 ) ;
}
return - 1 ;
}
static int
F_16 ( T_4 * V_2 , T_2 * T_3 V_1 ,
int V_3 , int V_4 , T_7 * V_8 , int V_24 , T_8 * V_25 , int V_10 )
{
T_5 V_26 ;
int V_27 = 0 , V_28 , V_29 ;
int V_14 ;
T_8 * V_9 = NULL , * V_30 = NULL ;
T_7 * V_31 = NULL , * V_32 = NULL ;
if ( V_24 > 10 ) {
F_8 ( V_8 , V_2 , V_3 , - 1 , L_9 ) ;
return - 1 ;
}
if ( V_4 < 1 ) {
F_8 ( V_8 , V_2 , V_3 , - 1 , L_6 ) ;
return V_4 ;
}
V_26 = F_2 ( V_2 , V_3 ) ;
if ( V_8 ) {
V_27 = F_16 ( V_2 , T_3 , V_3 , V_4 , NULL , V_24 , NULL , 0 ) ;
if ( V_27 < 0 ) V_27 = V_4 ;
}
switch ( V_26 ) {
case 'd' :
if ( V_8 ) {
V_30 = F_10 ( V_8 , V_33 , V_2 , V_3 , V_27 , V_19 ) ;
V_32 = F_17 ( V_30 , V_34 ) ;
}
V_14 = 1 ;
V_4 -- ;
while ( V_4 >= 1 ) {
V_26 = F_2 ( V_2 , V_3 + V_14 ) ;
if ( V_26 == 'e' ) {
return V_14 + 1 ;
}
V_28 = F_7 ( V_2 , T_3 , V_3 + V_14 , V_4 , NULL , NULL , 0 ) ;
if ( V_28 < 0 ) {
if ( V_32 ) {
F_8 ( V_32 , V_2 , V_3 + V_14 , - 1 , L_10 ) ;
}
return V_28 ;
}
V_29 = - 1 ;
if ( V_4 - V_28 > 2 )
V_29 = F_16 ( V_2 , T_3 , V_3 + V_14 + V_28 , V_4 - V_28 , NULL , V_24 + 1 , NULL , 0 ) ;
if ( V_29 < 0 ) {
if ( V_32 ) {
F_8 ( V_32 , V_2 , V_3 + V_14 + V_28 , - 1 , L_11 ) ;
}
return V_29 ;
}
if ( V_32 ) {
V_9 = F_10 ( V_32 , V_35 , V_2 , V_3 + V_14 , V_28 + V_29 , V_19 ) ;
V_31 = F_17 ( V_9 , V_36 ) ;
F_7 ( V_2 , T_3 , V_3 + V_14 , V_4 , V_31 , V_9 , 1 ) ;
F_16 ( V_2 , T_3 , V_3 + V_14 + V_28 , V_4 - V_28 , V_31 , V_24 + 1 , V_9 , 2 ) ;
}
V_14 += V_28 + V_29 ;
V_4 -= V_28 + V_29 ;
}
if ( V_32 ) {
F_8 ( V_32 , V_2 , V_3 + V_14 , - 1 , L_6 ) ;
}
return - 1 ;
case 'l' :
if ( V_8 ) {
V_9 = F_10 ( V_8 , V_37 , V_2 , V_3 , V_27 , V_19 ) ;
V_31 = F_17 ( V_9 , V_38 ) ;
}
V_14 = 1 ;
V_4 -- ;
while ( V_4 >= 1 ) {
V_26 = F_2 ( V_2 , V_3 + V_14 ) ;
if ( V_26 == 'e' ) {
return V_14 + 1 ;
}
V_27 = F_16 ( V_2 , T_3 , V_3 + V_14 , V_4 , V_31 , V_24 + 1 , V_9 , 0 ) ;
if ( V_27 < 1 ) return V_27 ;
V_14 += V_27 ;
V_4 -= V_27 ;
}
if ( V_31 ) {
F_8 ( V_31 , V_2 , V_3 + V_14 , - 1 , L_6 ) ;
}
return - 1 ;
case 'i' :
return F_14 ( V_2 , T_3 , V_3 , V_4 , V_8 , V_25 , V_10 ) ;
default:
if ( V_26 >= '1' && V_26 <= '9' ) {
return F_7 ( V_2 , T_3 , V_3 , V_4 , V_8 , V_25 , V_10 ) ;
}
if ( V_8 ) {
F_8 ( V_8 , V_2 , V_3 , - 1 , L_12 ) ;
}
}
return - 1 ;
}
static void
F_18 ( T_4 * V_2 , T_2 * T_3 V_1 ,
int V_3 , int V_4 , T_7 * V_8 )
{
F_16 ( V_2 , T_3 , V_3 , V_4 , V_8 , 0 , NULL , 0 ) ;
}
static void
F_19 ( T_4 * V_2 , T_2 * T_3 , T_7 * V_8 )
{
int V_3 = 0 ;
int V_39 ;
int V_40 = 0 ;
T_7 * V_41 ;
T_10 type = 0 ;
T_6 V_42 = 0 ;
T_5 V_43 = 0 ;
T_6 V_4 ;
const char * V_44 = NULL ;
T_8 * V_9 ;
T_6 V_45 , V_46 , V_47 ;
T_6 V_12 ;
if ( F_20 ( V_2 , V_3 + V_5 , 1 ) ) {
V_4 = F_4 ( V_2 , V_3 ) ;
type = F_2 ( V_2 , V_3 + V_5 ) ;
if ( type == V_48 && V_4 > 4 ) {
if ( ! F_20 ( V_2 , V_3 + V_5 , 4 ) )
return;
V_42 = F_4 ( V_2 , V_3 + V_5 ) ;
if ( 4 + V_42 + 1 <= V_4 ) {
if ( ! F_20 ( V_2 , V_3 + V_5 + 4 , V_42 + 1 ) )
return;
for ( V_39 = 0 ; V_49 [ V_39 ] . V_50 ; V_39 ++ ) {
if ( strlen ( V_49 [ V_39 ] . V_50 ) == V_42 &&
F_3 ( V_2 , V_3 + V_5 + 4 ,
V_49 [ V_39 ] . V_50 , ( int ) strlen ( V_49 [ V_39 ] . V_50 ) ) == 0 ) {
V_43 = F_2 ( V_2 , V_3 + V_5 + 4 + V_42 ) ;
if ( V_43 == 0 || V_43 == 1 || V_43 == 2 ) {
type = V_49 [ V_39 ] . V_51 ;
V_40 = 1 ;
}
break;
}
}
}
}
V_44 = F_21 ( type , V_52 ) ;
#if 0
if (msgtype == NULL && isamp) {
msgtype = try_val_to_str(type, azureus_messages);
}
#endif
if ( V_44 == NULL ) {
F_8 ( V_8 , V_2 , V_3 , - 1 , L_13 ) ;
F_22 ( T_3 -> V_53 , V_54 , L_13 ) ;
return;
}
} else {
return;
}
if ( V_40 ) {
V_9 = F_10 ( V_8 , V_55 , V_2 , V_3 , V_4 + V_5 , V_19 ) ;
} else {
V_9 = F_10 ( V_8 , V_56 , V_2 , V_3 , V_4 + V_5 , V_19 ) ;
}
V_41 = F_17 ( V_9 , V_57 ) ;
if ( V_4 == 0 ) {
F_10 ( V_41 , V_58 , V_2 , V_3 , V_5 , V_59 ) ;
F_22 ( T_3 -> V_53 , V_54 , L_14 ) ;
return;
}
F_10 ( V_41 , V_58 , V_2 , V_3 , V_5 , V_59 ) ;
V_3 += V_5 ;
if ( V_40 ) {
F_10 ( V_41 , V_60 , V_2 , V_3 , 4 , V_59 ) ;
F_10 ( V_41 , V_61 , V_2 , V_3 + 4 , V_42 , V_18 | V_19 ) ;
F_11 ( V_9 , L_15 , V_4 , V_44 ) ;
F_10 ( V_41 , V_62 , V_2 , V_3 + 4 + V_42 , 1 , V_59 ) ;
V_3 += 4 + V_42 + 1 ;
V_4 -= 4 + V_42 + 1 ;
} else {
F_10 ( V_41 , V_63 , V_2 , V_3 , 1 , V_59 ) ;
F_11 ( V_9 , L_16 , V_4 , V_44 ) ;
V_3 += 1 ;
V_4 -= 1 ;
}
F_22 ( T_3 -> V_53 , V_54 , V_44 ) ;
switch ( type ) {
case V_48 :
case V_64 :
case V_65 :
case V_66 :
break;
case V_67 :
case V_68 :
V_45 = F_4 ( V_2 , V_3 ) ;
F_9 ( V_41 , V_69 , V_2 , V_3 , 4 , V_45 ) ; V_3 += 4 ;
V_46 = F_4 ( V_2 , V_3 ) ;
F_9 ( V_41 , V_70 , V_2 , V_3 , 4 , V_46 ) ; V_3 += 4 ;
V_47 = F_4 ( V_2 , V_3 ) ;
F_9 ( V_41 , V_71 , V_2 , V_3 , 4 , V_47 ) ;
F_11 ( V_9 , L_17 , V_45 , V_46 , V_47 ) ;
F_23 ( T_3 -> V_53 , V_54 , L_17 , V_45 , V_46 , V_47 ) ;
break;
case V_6 :
F_10 ( V_41 , V_72 , V_2 , V_3 , 2 , V_59 ) ;
break;
case V_7 :
F_10 ( V_41 , V_73 , V_2 , V_3 , V_4 , V_19 ) ;
break;
case V_74 :
V_45 = F_4 ( V_2 , V_3 ) ;
F_10 ( V_41 , V_69 , V_2 , V_3 , 4 , V_59 ) ;
F_11 ( V_9 , L_18 , V_45 ) ;
F_23 ( T_3 -> V_53 , V_54 , L_18 , V_45 ) ;
break;
case V_75 :
F_10 ( V_41 , V_76 , V_2 , V_3 , V_4 , V_19 ) ;
F_11 ( V_9 , L_19 , V_4 ) ;
F_23 ( T_3 -> V_53 , V_54 , L_19 , V_4 ) ;
break;
case V_77 :
V_45 = F_4 ( V_2 , V_3 ) ;
F_9 ( V_41 , V_69 , V_2 , V_3 , 4 , V_45 ) ;
V_3 += 4 ;
V_4 -= 4 ;
V_46 = F_4 ( V_2 , V_3 ) ;
F_9 ( V_41 , V_70 , V_2 , V_3 , 4 , V_46 ) ;
V_3 += 4 ;
V_4 -= 4 ;
F_10 ( V_41 , V_78 , V_2 , V_3 , V_4 , V_19 ) ;
F_11 ( V_9 , L_20 , V_45 , V_46 , V_4 ) ;
F_23 ( T_3 -> V_53 , V_54 , L_20 , V_45 , V_46 , V_4 ) ;
break;
case V_79 :
case V_80 :
F_18 ( V_2 , T_3 , V_3 , V_4 , V_41 ) ;
break;
case V_81 :
V_12 = F_4 ( V_2 , V_3 ) ;
F_10 ( V_41 , V_82 , V_2 , V_3 , 4 , V_59 ) ;
F_10 ( V_41 , V_83 , V_2 , V_3 + 4 , V_12 , V_18 | V_19 ) ;
F_10 ( V_41 , V_84 , V_2 , V_3 + 4 + V_12 , 4 , V_59 ) ;
F_10 ( V_41 , V_85 , V_2 , V_3 + 4 + V_12 + 4 , 4 , V_59 ) ;
break;
case V_86 :
F_10 ( V_41 , V_85 , V_2 , V_3 , 4 , V_59 ) ;
break;
default:
break;
}
}
static int
F_24 ( T_4 * V_2 , T_2 * T_3 V_1 , T_7 * V_8 )
{
int V_3 = 0 ;
int V_39 ;
char * V_87 ;
F_22 ( T_3 -> V_53 , V_54 , L_21 ) ;
F_10 ( V_8 , V_88 , V_2 , V_3 , 1 , V_59 ) ; V_3 += 1 ;
F_10 ( V_8 , V_89 , V_2 , V_3 , 19 , V_18 | V_19 ) ; V_3 += 19 ;
F_10 ( V_8 , V_90 , V_2 , V_3 , 8 , V_19 ) ; V_3 += 8 ;
F_10 ( V_8 , V_91 , V_2 , V_3 , 20 , V_19 ) ;
V_3 += 20 ;
F_10 ( V_8 , V_92 , V_2 , V_3 , 20 , V_19 ) ;
if( V_93 ) {
for( V_39 = 0 ; V_94 [ V_39 ] . V_50 != NULL ; ++ V_39 )
{
if( F_3 ( V_2 , V_3 , V_94 [ V_39 ] . V_95 , ( int ) strlen ( V_94 [ V_39 ] . V_95 ) ) == 0 ) {
V_87 = F_25 ( V_2 , V_3 + ( int ) strlen ( V_94 [ V_39 ] . V_95 ) ,
V_94 [ V_39 ] . V_96 ) ;
F_8 ( V_8 , V_2 , V_3 , 20 , L_22 ,
V_94 [ V_39 ] . V_50 ,
F_12 ( ( V_20 * ) V_87 , V_94 [ V_39 ] . V_96 ) ) ;
break;
}
}
}
V_3 += 20 ;
return V_3 ;
}
static
void F_26 ( T_4 * V_2 , T_2 * T_3 , T_7 * V_8 )
{
T_8 * V_9 ;
F_22 ( T_3 -> V_53 , V_97 , L_23 ) ;
F_22 ( T_3 -> V_53 , V_54 , L_24 ) ;
V_9 = F_10 ( V_8 , V_98 , V_2 , 0 , - 1 , V_19 ) ;
V_8 = F_17 ( V_9 , V_99 ) ;
if ( F_2 ( V_2 , 0 ) == 19 &&
F_3 ( V_2 , 1 , L_1 , 19 ) == 0 ) {
F_24 ( V_2 , T_3 , V_8 ) ;
} else {
F_19 ( V_2 , T_3 , V_8 ) ;
}
F_27 ( T_3 -> V_53 , V_54 , L_25 ) ;
F_28 ( T_3 -> V_53 , V_54 ) ;
}
static
void F_29 ( T_4 * V_2 , T_2 * T_3 , T_7 * V_8 )
{
F_30 ( V_2 , T_3 , V_8 , V_100 , V_5 ,
F_1 , F_26 ) ;
}
static
T_11 F_31 ( T_4 * V_2 , T_2 * T_3 ,
T_7 * V_8 , void * T_12 V_1 )
{
T_13 * V_101 ;
if ( F_32 ( V_2 ) >= 20 &&
F_2 ( V_2 , 0 ) == 19 &&
F_3 ( V_2 , 1 , L_1 , 19 ) == 0 ) {
V_101 = F_33 ( T_3 ) ;
F_34 ( V_101 , V_102 ) ;
F_29 ( V_2 , T_3 , V_8 ) ;
return TRUE ;
}
return FALSE ;
}
void
F_35 ( void )
{
static T_14 V_103 [] = {
#if 0
{ &hf_bittorrent_field_length,
{ "Field Length", "bittorrent.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ & V_88 ,
{ L_26 , L_27 , V_104 , V_105 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_89 ,
{ L_28 , L_29 , V_107 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_90 ,
{ L_30 , L_31 , V_109 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_91 ,
{ L_32 , L_33 , V_109 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_92 ,
{ L_34 , L_35 , V_109 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_56 ,
{ L_36 , L_37 , V_110 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_58 ,
{ L_38 , L_39 , V_111 , V_105 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_63 ,
{ L_40 , L_41 , V_104 , V_105 , F_36 ( V_52 ) , 0x0 , NULL , V_106 }
} ,
{ & V_55 ,
{ L_42 , L_43 , V_110 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_60 ,
{ L_44 , L_45 , V_111 , V_105 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_61 ,
{ L_40 , L_46 , V_107 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_62 ,
{ L_47 , L_48 , V_104 , V_105 , F_36 ( V_112 ) , 0x0 , NULL , V_106 }
} ,
{ & V_76 ,
{ L_49 , L_50 , V_109 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_69 ,
{ L_51 , L_52 , V_111 , V_113 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_70 ,
{ L_53 , L_54 , V_111 , V_113 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_78 ,
{ L_55 , L_56 , V_109 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_71 ,
{ L_57 , L_58 , V_111 , V_113 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_16 ,
{ L_59 , L_60 , V_111 , V_105 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_17 ,
{ L_61 , L_62 , V_107 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_23 ,
{ L_63 , L_64 , V_114 , V_105 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_33 ,
{ L_65 , L_66 , V_110 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_35 ,
{ L_67 , L_68 , V_110 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_37 ,
{ L_69 , L_70 , V_110 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_82 ,
{ L_71 , L_72 , V_111 , V_105 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_83 ,
{ L_73 , L_74 , V_107 , V_108 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_84 ,
{ L_75 , L_76 , V_111 , V_105 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_85 ,
{ L_77 , L_78 , V_111 , V_113 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_72 ,
{ L_75 , L_79 , V_115 , V_105 , NULL , 0x0 , NULL , V_106 }
} ,
{ & V_73 ,
{ L_80 , L_81 , V_109 , V_108 , NULL , 0x0 , NULL , V_106 }
}
} ;
static T_15 * V_116 [] = {
& V_99 ,
& V_57 ,
& V_117 ,
& V_34 ,
& V_36 ,
& V_38
} ;
T_16 * V_118 ;
V_98 = F_37 ( L_23 , L_23 , L_82 ) ;
F_38 ( V_98 , V_103 , F_39 ( V_103 ) ) ;
F_40 ( V_116 , F_39 ( V_116 ) ) ;
F_41 ( L_83 , F_29 , V_98 ) ;
V_118 = F_42 ( V_98 , NULL ) ;
F_43 ( V_118 , L_84 ,
L_85 ,
L_86
L_87 ,
& V_100 ) ;
F_43 ( V_118 , L_88 ,
L_89 ,
L_90 ,
& V_93 ) ;
}
void
F_44 ( void )
{
V_102 = F_45 ( L_83 ) ;
#if 0
dissector_add_uint("tcp.port", 6881, dissector_handle);
dissector_add_uint("tcp.port", 6882, dissector_handle);
dissector_add_uint("tcp.port", 6883, dissector_handle);
dissector_add_uint("tcp.port", 6884, dissector_handle);
dissector_add_uint("tcp.port", 6885, dissector_handle);
dissector_add_uint("tcp.port", 6886, dissector_handle);
dissector_add_uint("tcp.port", 6887, dissector_handle);
dissector_add_uint("tcp.port", 6888, dissector_handle);
dissector_add_uint("tcp.port", 6889, dissector_handle);
#endif
F_46 ( L_91 , F_31 , V_98 ) ;
}
