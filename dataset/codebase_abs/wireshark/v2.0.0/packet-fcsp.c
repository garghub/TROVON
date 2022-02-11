static void F_1 ( T_1 * V_1 , T_2 * V_2 ,
int V_3 , T_3 V_4 )
{
T_4 V_5 ;
T_4 V_6 , V_7 ;
if ( V_2 ) {
V_4 -= 4 ;
while ( V_4 > 0 ) {
F_2 ( V_2 , V_8 , V_1 , V_3 ,
2 , V_9 ) ;
F_2 ( V_2 , V_10 , V_1 , V_3 + 2 ,
2 , V_9 ) ;
V_5 = F_3 ( V_1 , V_3 ) ;
V_6 = F_3 ( V_1 , V_3 + 2 ) * 4 ;
switch ( V_5 ) {
case V_11 :
V_3 += 4 ;
V_4 -= 4 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 += 4 ) {
F_2 ( V_2 , V_12 , V_1 ,
V_3 , 4 , V_9 ) ;
V_3 += 4 ;
}
break;
case V_13 :
V_3 += 4 ;
V_4 -= 4 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 += 4 ) {
F_2 ( V_2 , V_14 , V_1 ,
V_3 , 4 , V_9 ) ;
V_3 += 4 ;
}
break;
default:
if ( V_6 == 0 ) {
return;
}
break;
}
V_4 -= V_6 ;
}
}
}
static void F_4 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 12 ;
T_4 V_15 ;
T_4 V_6 , V_16 ;
if ( V_2 ) {
F_2 ( V_2 , V_17 , V_1 , V_3 ,
2 , V_9 ) ;
V_15 = F_3 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_18 , V_1 , V_3 + 2 ,
2 , V_9 ) ;
V_16 = F_3 ( V_1 , V_3 + 2 ) ;
if ( V_15 == V_19 ) {
F_2 ( V_2 , V_20 , V_1 , V_3 + 4 ,
8 , V_21 ) ;
}
else {
F_2 ( V_2 , V_22 , V_1 , V_3 + 4 ,
V_16 , V_21 ) ;
}
V_3 += ( 4 + V_16 ) ;
F_2 ( V_2 , V_12 , V_1 , V_3 ,
4 , V_9 ) ;
F_2 ( V_2 , V_14 , V_1 , V_3 + 4 ,
4 , V_9 ) ;
F_2 ( V_2 , V_23 , V_1 , V_3 + 8 ,
4 , V_9 ) ;
V_6 = F_5 ( V_1 , V_3 + 8 ) ;
F_2 ( V_2 , V_24 , V_1 , V_3 + 12 ,
V_6 , V_21 ) ;
V_3 += ( V_6 + 12 ) ;
F_2 ( V_2 , V_25 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_5 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_26 , V_1 , V_3 + 4 ,
V_6 , V_21 ) ;
}
}
static void F_6 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 12 ;
T_5 V_6 ;
if ( V_2 ) {
F_2 ( V_2 , V_27 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_5 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_28 , V_1 , V_3 + 4 ,
V_6 , V_21 ) ;
V_3 += ( V_6 + 4 ) ;
F_2 ( V_2 , V_25 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_5 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_26 , V_1 , V_3 + 4 ,
V_6 , V_21 ) ;
V_3 += ( V_6 + 4 ) ;
F_2 ( V_2 , V_23 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_5 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_24 , V_1 , V_3 + 4 ,
V_6 , V_21 ) ;
}
}
static void F_7 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 12 ;
T_5 V_6 ;
if ( V_2 ) {
F_2 ( V_2 , V_27 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_5 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_28 , V_1 , V_3 + 4 ,
V_6 , V_21 ) ;
}
}
static void F_8 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 12 ;
T_4 V_15 , V_16 , V_29 , V_6 ;
T_5 V_30 , V_7 ;
if ( V_2 ) {
F_2 ( V_2 , V_31 , V_1 , V_3 ,
2 , V_9 ) ;
V_15 = F_3 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_32 , V_1 , V_3 + 2 ,
2 , V_9 ) ;
V_16 = F_3 ( V_1 , V_3 + 2 ) ;
if ( V_15 == V_19 ) {
F_2 ( V_2 , V_33 , V_1 , V_3 + 4 , 8 , V_21 ) ;
}
else {
F_2 ( V_2 , V_34 , V_1 , V_3 + 4 ,
V_16 , V_21 ) ;
}
V_3 += ( 4 + V_16 ) ;
F_2 ( V_2 , V_35 , V_1 , V_3 , 4 , V_9 ) ;
V_30 = F_5 ( V_1 , V_3 ) ;
V_3 += 4 ;
for ( V_7 = 0 ; V_7 < V_30 ; V_7 ++ ) {
F_2 ( V_2 , V_36 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_5 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( F_9 ( V_1 , V_3 , V_6 ) ) {
V_29 = F_5 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_37 , V_1 , V_3 , 4 , V_9 ) ;
switch ( V_29 ) {
case V_38 :
F_1 ( V_1 , V_2 , V_3 + 4 , V_6 ) ;
break;
case V_39 :
break;
default:
break;
}
}
V_3 += V_6 ;
}
}
}
static void F_10 ( T_1 * V_1 V_40 , T_2 * V_2 V_40 )
{
}
static void F_11 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 12 ;
if ( V_2 ) {
F_2 ( V_2 , V_41 , V_1 , V_3 , 1 , V_9 ) ;
F_2 ( V_2 , V_42 , V_1 , V_3 + 1 , 1 , V_9 ) ;
}
}
static void F_12 ( T_1 * V_1 , T_6 * V_43 , T_2 * V_2 )
{
T_7 * V_44 = NULL ;
T_8 V_45 ;
int V_3 = 0 ;
T_2 * V_46 = NULL ;
V_45 = F_13 ( V_1 , 2 ) ;
F_14 ( V_43 -> V_47 , V_48 ,
F_15 ( V_45 , V_49 , L_1 ) ) ;
if ( V_2 ) {
V_44 = F_16 ( V_2 , V_50 , V_1 , 0 ,
F_17 ( V_1 ) , L_2 ) ;
V_46 = F_18 ( V_44 , V_51 ) ;
F_2 ( V_46 , V_52 , V_1 , V_3 + 1 , 1 , V_9 ) ;
F_2 ( V_46 , V_53 , V_1 , V_3 + 2 , 1 , V_9 ) ;
F_2 ( V_46 , V_54 , V_1 , V_3 + 3 , 1 ,
V_9 ) ;
F_2 ( V_46 , V_55 , V_1 , V_3 + 4 , 4 , V_9 ) ;
F_2 ( V_46 , V_56 , V_1 , V_3 + 8 , 4 , V_9 ) ;
switch ( V_45 ) {
case V_57 :
F_11 ( V_1 , V_2 ) ;
break;
case V_58 :
F_8 ( V_1 , V_2 ) ;
break;
case V_59 :
F_10 ( V_1 , V_2 ) ;
break;
case V_60 :
F_4 ( V_1 , V_2 ) ;
break;
case V_61 :
F_6 ( V_1 , V_2 ) ;
break;
case V_62 :
F_7 ( V_1 , V_2 ) ;
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
F_19 ( V_46 , V_43 , & V_69 , V_1 , V_3 + 12 , - 1 ) ;
break;
default:
break;
}
}
}
void
F_20 ( void )
{
static T_9 V_70 [] = {
{ & V_54 ,
{ L_3 , L_4 ,
V_71 , V_72 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_53 ,
{ L_5 , L_6 ,
V_71 , V_72 , F_21 ( V_49 ) , 0x0 ,
NULL , V_73 } } ,
{ & V_52 ,
{ L_7 , L_8 ,
V_71 , V_72 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_55 ,
{ L_9 , L_10 ,
V_74 , V_75 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_56 ,
{ L_11 , L_12 ,
V_74 , V_72 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_33 ,
{ L_13 , L_14 ,
V_76 , V_77 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_34 ,
{ L_15 , L_16 ,
V_78 , V_77 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_31 ,
{ L_17 , L_18 ,
V_79 , V_72 , F_21 ( V_80 ) , 0x0 ,
NULL , V_73 } } ,
{ & V_32 ,
{ L_19 , L_20 ,
V_79 , V_75 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_35 ,
{ L_21 , L_22 ,
V_74 , V_75 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_41 ,
{ L_23 , L_24 ,
V_71 , V_75 , F_21 ( V_81 ) , 0x0 ,
NULL , V_73 } } ,
{ & V_42 ,
{ L_25 , L_26 ,
V_71 , V_75 , F_21 ( V_82 ) , 0x0 ,
NULL , V_73 } } ,
{ & V_20 ,
{ L_27 , L_28 ,
V_76 , V_77 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_22 ,
{ L_29 , L_30 ,
V_78 , V_77 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_17 ,
{ L_31 , L_32 ,
V_79 , V_72 , F_21 ( V_80 ) , 0x0 ,
NULL , V_73 } } ,
{ & V_18 ,
{ L_31 , L_33 ,
V_79 , V_75 , NULL , 0x0 ,
NULL , V_73 } } ,
#if 0
{ &hf_auth_dhchap_hashid,
{ "Hash Identifier", "fcsp.dhchap.hashid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
#endif
#if 0
{ &hf_auth_dhchap_groupid,
{ "DH Group Identifier", "fcsp.dhchap.groupid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
#endif
{ & V_23 ,
{ L_34 , L_35 ,
V_74 , V_75 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_25 ,
{ L_36 , L_37 ,
V_74 , V_75 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_27 ,
{ L_38 , L_39 ,
V_74 , V_75 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_37 ,
{ L_40 , L_41 ,
V_74 , V_75 , F_21 ( V_83 ) , 0x0 ,
NULL , V_73 } } ,
{ & V_36 ,
{ L_42 , L_43 ,
V_74 , V_75 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_8 ,
{ L_44 , L_45 ,
V_79 , V_72 , F_21 ( V_84 ) , 0x0 ,
NULL , V_73 } } ,
{ & V_10 ,
{ L_46 , L_47 ,
V_79 , V_75 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_12 ,
{ L_48 , L_49 ,
V_74 , V_75 , F_21 ( V_85 ) , 0x0 ,
NULL , V_73 } } ,
{ & V_14 ,
{ L_50 , L_51 ,
V_74 , V_75 , F_21 ( V_86 ) , 0x0 ,
NULL , V_73 } } ,
{ & V_24 ,
{ L_52 , L_53 ,
V_78 , V_77 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_26 ,
{ L_54 , L_55 ,
V_78 , V_77 , NULL , 0x0 ,
NULL , V_73 } } ,
{ & V_28 ,
{ L_56 , L_57 ,
V_78 , V_77 , NULL , 0x0 ,
NULL , V_73 } } ,
} ;
static T_10 * V_87 [] = {
& V_51 ,
} ;
static T_11 V_88 [] = {
{ & V_69 , { L_58 , V_89 , V_90 , L_59 , V_91 } } ,
} ;
T_12 * V_92 ;
V_50 = F_22 ( L_60 , L_2 , L_61 ) ;
F_23 ( L_61 , F_12 , V_50 ) ;
F_24 ( V_50 , V_70 , F_25 ( V_70 ) ) ;
F_26 ( V_87 , F_25 ( V_87 ) ) ;
V_92 = F_27 ( V_50 ) ;
F_28 ( V_92 , V_88 , F_25 ( V_88 ) ) ;
}
