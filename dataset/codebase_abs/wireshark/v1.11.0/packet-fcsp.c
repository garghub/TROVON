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
F_5 ( V_2 , V_20 , V_1 , V_3 + 4 ,
8 , F_6 ( V_1 , V_3 + 4 ) ) ;
}
else {
F_2 ( V_2 , V_21 , V_1 , V_3 + 4 ,
V_16 , V_22 ) ;
}
V_3 += ( 4 + V_16 ) ;
F_2 ( V_2 , V_12 , V_1 , V_3 ,
4 , V_9 ) ;
F_2 ( V_2 , V_14 , V_1 , V_3 + 4 ,
4 , V_9 ) ;
F_2 ( V_2 , V_23 , V_1 , V_3 + 8 ,
4 , V_9 ) ;
V_6 = F_7 ( V_1 , V_3 + 8 ) ;
F_2 ( V_2 , V_24 , V_1 , V_3 + 12 ,
V_6 , V_22 ) ;
V_3 += ( V_6 + 12 ) ;
F_2 ( V_2 , V_25 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_7 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_26 , V_1 , V_3 + 4 ,
V_6 , V_22 ) ;
}
}
static void F_8 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 12 ;
T_5 V_6 ;
if ( V_2 ) {
F_2 ( V_2 , V_27 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_7 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_28 , V_1 , V_3 + 4 ,
V_6 , V_22 ) ;
V_3 += ( V_6 + 4 ) ;
F_2 ( V_2 , V_25 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_7 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_26 , V_1 , V_3 + 4 ,
V_6 , V_22 ) ;
V_3 += ( V_6 + 4 ) ;
F_2 ( V_2 , V_23 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_7 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_24 , V_1 , V_3 + 4 ,
V_6 , V_22 ) ;
}
}
static void F_9 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 12 ;
T_5 V_6 ;
if ( V_2 ) {
F_2 ( V_2 , V_27 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_7 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_28 , V_1 , V_3 + 4 ,
V_6 , V_22 ) ;
}
}
static void F_10 ( T_1 * V_1 , T_2 * V_2 )
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
F_5 ( V_2 , V_33 , V_1 , V_3 + 4 , 8 ,
F_6 ( V_1 , V_3 + 4 ) ) ;
}
else {
F_2 ( V_2 , V_34 , V_1 , V_3 + 4 ,
V_16 , V_22 ) ;
}
V_3 += ( 4 + V_16 ) ;
F_2 ( V_2 , V_35 , V_1 , V_3 , 4 , V_9 ) ;
V_30 = F_7 ( V_1 , V_3 ) ;
V_3 += 4 ;
for ( V_7 = 0 ; V_7 < V_30 ; V_7 ++ ) {
F_2 ( V_2 , V_36 , V_1 , V_3 , 4 , V_9 ) ;
V_6 = F_7 ( V_1 , V_3 ) ;
V_3 += 4 ;
if ( F_11 ( V_1 , V_3 , V_6 ) ) {
V_29 = F_7 ( V_1 , V_3 ) ;
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
static void F_12 ( T_1 * V_1 V_40 , T_2 * V_2 V_40 )
{
}
static void F_13 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 = 12 ;
if ( V_2 ) {
F_2 ( V_2 , V_41 , V_1 , V_3 , 1 , V_9 ) ;
F_2 ( V_2 , V_42 , V_1 , V_3 + 1 , 1 , V_9 ) ;
}
}
static void F_14 ( T_1 * V_1 , T_6 * V_43 , T_2 * V_2 )
{
T_7 * V_44 = NULL ;
T_8 V_45 ;
int V_3 = 0 ;
T_2 * V_46 = NULL ;
V_45 = F_15 ( V_1 , 2 ) ;
F_16 ( V_43 -> V_47 , V_48 ,
F_17 ( V_45 , V_49 , L_1 ) ) ;
if ( V_2 ) {
V_44 = F_18 ( V_2 , V_50 , V_1 , 0 ,
F_19 ( V_1 ) , L_2 ) ;
V_46 = F_20 ( V_44 , V_51 ) ;
F_2 ( V_46 , V_52 , V_1 , V_3 + 1 , 1 , V_9 ) ;
F_2 ( V_46 , V_53 , V_1 , V_3 + 2 , 1 , V_9 ) ;
F_2 ( V_46 , V_54 , V_1 , V_3 + 3 , 1 ,
V_9 ) ;
F_2 ( V_46 , V_55 , V_1 , V_3 + 4 , 4 , V_9 ) ;
F_2 ( V_46 , V_56 , V_1 , V_3 + 8 , 4 , V_9 ) ;
switch ( V_45 ) {
case V_57 :
F_13 ( V_1 , V_2 ) ;
break;
case V_58 :
F_10 ( V_1 , V_2 ) ;
break;
case V_59 :
F_12 ( V_1 , V_2 ) ;
break;
case V_60 :
F_4 ( V_1 , V_2 ) ;
break;
case V_61 :
F_8 ( V_1 , V_2 ) ;
break;
case V_62 :
F_9 ( V_1 , V_2 ) ;
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
F_21 ( V_46 , V_1 , V_3 + 12 , F_19 ( V_1 ) ,
L_3 ) ;
break;
default:
break;
}
}
}
void
F_22 ( void )
{
static T_9 V_69 [] = {
{ & V_54 ,
{ L_4 , L_5 ,
V_70 , V_71 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_53 ,
{ L_6 , L_7 ,
V_70 , V_71 , F_23 ( V_49 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_52 ,
{ L_8 , L_9 ,
V_70 , V_71 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_55 ,
{ L_10 , L_11 ,
V_73 , V_74 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_56 ,
{ L_12 , L_13 ,
V_73 , V_71 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_33 ,
{ L_14 , L_15 ,
V_75 , V_76 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_34 ,
{ L_16 , L_17 ,
V_77 , V_76 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_31 ,
{ L_18 , L_19 ,
V_78 , V_71 , F_23 ( V_79 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_32 ,
{ L_20 , L_21 ,
V_78 , V_74 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_35 ,
{ L_22 , L_23 ,
V_73 , V_74 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_41 ,
{ L_24 , L_25 ,
V_70 , V_74 , F_23 ( V_80 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_42 ,
{ L_26 , L_27 ,
V_70 , V_74 , F_23 ( V_81 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_20 ,
{ L_28 , L_29 ,
V_75 , V_76 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_21 ,
{ L_30 , L_31 ,
V_77 , V_76 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_17 ,
{ L_32 , L_33 ,
V_78 , V_71 , F_23 ( V_79 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_18 ,
{ L_32 , L_34 ,
V_78 , V_74 , NULL , 0x0 ,
NULL , V_72 } } ,
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
{ L_35 , L_36 ,
V_73 , V_74 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_25 ,
{ L_37 , L_38 ,
V_73 , V_74 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_27 ,
{ L_39 , L_40 ,
V_73 , V_74 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_37 ,
{ L_41 , L_42 ,
V_73 , V_74 , F_23 ( V_82 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_36 ,
{ L_43 , L_44 ,
V_73 , V_74 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_8 ,
{ L_45 , L_46 ,
V_78 , V_71 , F_23 ( V_83 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_10 ,
{ L_47 , L_48 ,
V_78 , V_74 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_12 ,
{ L_49 , L_50 ,
V_73 , V_74 , F_23 ( V_84 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_14 ,
{ L_51 , L_52 ,
V_73 , V_74 , F_23 ( V_85 ) , 0x0 ,
NULL , V_72 } } ,
{ & V_24 ,
{ L_53 , L_54 ,
V_77 , V_76 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_26 ,
{ L_55 , L_56 ,
V_77 , V_76 , NULL , 0x0 ,
NULL , V_72 } } ,
{ & V_28 ,
{ L_57 , L_58 ,
V_77 , V_76 , NULL , 0x0 ,
NULL , V_72 } } ,
} ;
static T_10 * V_86 [] = {
& V_51 ,
} ;
V_50 = F_24 ( L_59 ,
L_2 , L_60 ) ;
F_25 ( L_60 , F_14 , V_50 ) ;
F_26 ( V_50 , V_69 , F_27 ( V_69 ) ) ;
F_28 ( V_86 , F_27 ( V_86 ) ) ;
}
void
F_29 ( void )
{
V_87 = F_30 ( L_61 ) ;
}
