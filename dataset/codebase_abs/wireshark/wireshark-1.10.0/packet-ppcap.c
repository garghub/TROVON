static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 , * V_5 ;
T_3 * V_6 , * V_7 ;
T_5 V_8 , V_9 ;
int V_10 = 0 ;
T_6 V_11 = V_12 ;
F_2 ( V_2 -> V_13 , V_14 , L_1 ) ;
F_3 ( V_2 -> V_13 , V_15 ) ;
V_4 = F_4 ( V_3 , V_16 , V_1 , 0 , - 1 , V_17 ) ;
V_6 = F_5 ( V_4 , V_18 ) ;
while ( F_6 ( V_1 , V_10 ) > 0 )
{
V_8 = F_7 ( V_1 , V_10 ) ;
V_5 = F_8 ( V_6 , V_1 , V_10 , 2 , L_2 ,
F_9 ( V_8 , V_19 , L_3 ) ) ;
V_7 = F_5 ( V_5 , V_20 ) ;
V_10 = V_10 + 2 ;
V_9 = F_7 ( V_1 , V_10 ) ;
F_4 ( V_7 , V_21 , V_1 , V_10 , 2 , V_22 ) ;
V_10 = V_10 + 2 ;
switch ( V_8 ) {
case 1 :
V_11 = V_12 ;
V_10 = F_10 ( V_1 , V_7 , V_10 , V_9 , & V_11 ) ;
break;
case 2 :
V_10 = F_11 ( V_1 , V_2 , V_7 , V_10 , V_9 , V_3 , V_11 ) ;
break;
case 3 :
V_10 = F_12 ( V_1 , V_2 , V_7 , V_10 , V_9 ) ;
break;
case 4 :
V_10 = F_13 ( V_1 , V_2 , V_7 , V_10 , V_9 ) ;
break;
case 256 :
V_10 = F_14 ( V_1 , V_7 , V_10 , V_9 ) ;
break;
}
}
}
static int
F_10 ( T_1 * V_1 , T_3 * V_7 , int V_10 , T_5 V_9 , T_6 * V_11 )
{
char * string ;
string = F_15 ( V_1 , V_10 , V_9 ) ;
if ( strcmp ( string , L_4 ) == 0 ) {
* V_11 = V_23 ;
} else if ( strcmp ( string , L_5 ) == 0 ) {
* V_11 = V_24 ;
} else if ( strcmp ( string , L_6 ) == 0 ) {
* V_11 = V_25 ;
} else if ( strcmp ( string , L_7 ) == 0 ) {
* V_11 = V_26 ;
} else if ( strcmp ( string , L_8 ) == 0 ) {
* V_11 = V_27 ;
} else if ( strcmp ( string , L_9 ) == 0 ) {
* V_11 = V_28 ;
} else if ( strcmp ( string , L_10 ) == 0 ) {
* V_11 = V_29 ;
}
F_4 ( V_7 , V_30 , V_1 , V_10 , V_9 , V_22 | V_31 ) ;
if ( V_9 % 4 )
V_9 = V_9 + ( 4 - ( V_9 % 4 ) ) ;
V_10 += V_9 ;
return V_10 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_7 , int V_10 , T_5 V_9 )
{
int V_32 ;
F_4 ( V_7 , V_33 , V_1 , V_10 , 2 , V_22 ) ;
V_10 += 2 ;
V_32 = F_7 ( V_1 , V_10 ) ;
F_4 ( V_7 , V_34 , V_1 , V_10 , 2 , V_22 ) ;
V_10 += 2 ;
if ( V_32 == 1 )
{
F_4 ( V_7 , V_35 , V_1 , V_10 , 1 , V_22 ) ;
V_10 += 1 ;
F_4 ( V_7 , V_36 , V_1 , V_10 , 3 , V_22 ) ;
V_37 = F_16 ( V_38 ) ;
V_37 -> V_39 = ( V_40 ) F_17 ( V_1 , V_10 ) ;
V_37 -> type = V_41 ;
V_37 -> V_42 = 0 ;
F_18 ( & V_2 -> V_43 , V_44 , sizeof( V_38 ) , ( V_45 * ) V_37 ) ;
if ( V_9 % 4 )
V_9 = V_9 + ( 4 - ( V_9 % 4 ) ) ;
V_10 += V_9 - 1 ;
return V_10 ;
}
else if ( V_32 == 2 )
{
F_4 ( V_7 , V_46 , V_1 , V_10 , V_9 , V_22 ) ;
V_37 = F_16 ( V_38 ) ;
V_37 -> V_39 = F_19 ( V_1 , V_10 ) ;
V_37 -> type = V_41 ;
V_37 -> V_42 = 0 ;
F_18 ( & V_2 -> V_43 , V_44 , sizeof( V_38 ) , ( V_45 * ) V_37 ) ;
}
else if ( V_32 == 3 )
{
if ( V_9 % 4 == 0 )
{
F_20 ( V_7 , V_47 , V_1 , V_10 , V_9 , F_21 ( V_1 , V_10 ) ) ;
F_22 ( & V_2 -> V_48 , V_49 , V_1 , V_10 , 4 ) ;
F_23 ( & V_2 -> V_43 , & V_2 -> V_48 ) ;
}
else
{
struct V_50 V_51 ;
F_24 ( V_1 , V_10 , & V_51 ) ;
F_25 ( V_7 , V_52 , V_1 , V_10 , V_9 , ( V_45 * ) & V_51 ) ;
F_22 ( & V_2 -> V_48 , V_53 , V_1 , V_10 , 6 ) ;
F_23 ( & V_2 -> V_43 , & V_2 -> V_48 ) ;
}
}
else if ( V_32 == 4 )
{
F_4 ( V_7 , V_54 , V_1 , V_10 , V_9 , V_22 | V_31 ) ;
F_22 ( & V_2 -> V_48 , V_55 , V_1 , V_10 , V_9 ) ;
F_23 ( & V_2 -> V_43 , & V_2 -> V_48 ) ;
}
if ( V_9 % 4 )
V_9 = V_9 + ( 4 - ( V_9 % 4 ) ) ;
V_10 += V_9 ;
return V_10 ;
}
static int
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_7 , int V_10 , T_5 V_9 )
{
int V_56 ;
F_4 ( V_7 , V_57 , V_1 , V_10 , 2 , V_22 ) ;
V_10 += 2 ;
V_56 = F_7 ( V_1 , V_10 ) ;
F_4 ( V_7 , V_34 , V_1 , V_10 , 2 , V_22 ) ;
V_10 += 2 ;
if ( V_56 == 1 )
{
V_58 = F_26 ( V_1 , V_10 ) ;
F_4 ( V_7 , V_59 , V_1 , V_10 , 1 , V_22 ) ;
V_10 += 1 ;
F_4 ( V_7 , V_60 , V_1 , V_10 , 3 , V_22 ) ;
V_61 = F_16 ( V_38 ) ;
V_61 -> V_39 = ( V_40 ) F_17 ( V_1 , V_10 ) ;
V_61 -> type = V_41 ;
V_61 -> V_42 = 0 ;
F_18 ( & V_2 -> V_62 , V_44 , sizeof( V_38 ) , ( V_45 * ) V_61 ) ;
if ( V_9 % 4 )
V_9 = V_9 + ( 4 - ( V_9 % 4 ) ) ;
V_10 += V_9 - 1 ;
return V_10 ;
}
else if ( V_56 == 2 )
{
F_4 ( V_7 , V_63 , V_1 , V_10 , 4 , V_22 ) ;
V_61 = F_16 ( V_38 ) ;
V_61 -> V_39 = F_19 ( V_1 , V_10 ) ;
V_61 -> type = V_41 ;
V_61 -> V_42 = 0 ;
F_18 ( & V_2 -> V_62 , V_44 , sizeof( V_38 ) , ( V_45 * ) V_61 ) ;
}
else if ( V_56 == 3 )
{
if ( V_9 % 4 == 0 )
{
F_20 ( V_7 , V_64 , V_1 , V_10 , V_9 , F_21 ( V_1 , V_10 ) ) ;
F_22 ( & V_2 -> V_65 , V_49 , V_1 , V_10 , 4 ) ;
F_23 ( & V_2 -> V_62 , & V_2 -> V_65 ) ;
}
else
{
struct V_50 V_51 ;
F_24 ( V_1 , V_10 , & V_51 ) ;
F_25 ( V_7 , V_66 , V_1 , V_10 , V_9 , ( V_45 * ) & V_51 ) ;
F_22 ( & V_2 -> V_65 , V_53 , V_1 , V_10 , 6 ) ;
F_23 ( & V_2 -> V_62 , & V_2 -> V_65 ) ;
}
}
else if ( V_56 == 4 )
{
char * string ;
string = F_27 ( V_1 , V_10 , V_9 ) ;
F_28 ( V_7 , V_67 , V_1 , V_10 , V_9 , string ) ;
F_22 ( & V_2 -> V_65 , V_55 , V_1 , V_10 , V_9 ) ;
F_23 ( & V_2 -> V_62 , & V_2 -> V_65 ) ;
}
if ( V_9 % 4 )
V_9 = V_9 + ( 4 - ( V_9 % 4 ) ) ;
V_10 += V_9 ;
return V_10 ;
}
static int
F_14 ( T_1 * V_1 , T_3 * V_7 , int V_10 , T_5 V_9 )
{
F_4 ( V_7 , V_68 , V_1 , V_10 , V_9 , V_31 | V_17 ) ;
if ( V_9 % 4 )
V_9 = V_9 + ( 4 - ( V_9 % 4 ) ) ;
V_10 += V_9 ;
return V_10 ;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_7 , int V_10 , T_5 V_9 , T_3 * V_3 , T_6 V_11 )
{
T_1 * V_69 ;
F_4 ( V_7 , V_70 , V_1 , V_10 , V_9 , V_17 ) ;
if ( V_9 % 4 )
V_9 = V_9 + ( 4 - ( V_9 % 4 ) ) ;
V_69 = F_29 ( V_1 , V_10 ) ;
switch ( V_11 ) {
case V_23 :
F_30 ( V_71 , V_69 , V_2 , V_3 ) ;
break;
case V_24 :
if ( V_58 != V_72 && F_31 ( V_73 , V_58 , V_69 , V_2 , V_3 ) ) {
return V_10 + V_9 ;
} else{
F_30 ( V_74 , V_69 , V_2 , V_3 ) ;
}
break;
case V_25 :
F_30 ( V_75 , V_69 , V_2 , V_3 ) ;
break;
case V_26 :
F_30 ( V_76 , V_69 , V_2 , V_3 ) ;
break;
case V_27 :
F_30 ( V_77 , V_69 , V_2 , V_3 ) ;
break;
case V_28 :
F_30 ( V_78 , V_69 , V_2 , V_3 ) ;
break;
case V_29 :
F_30 ( V_79 , V_69 , V_2 , V_3 ) ;
break;
default:
F_30 ( V_80 , V_69 , V_2 , V_3 ) ;
break;
}
V_10 += V_9 ;
return V_10 ;
}
void F_32 ( void )
{
static T_7 V_81 [] = {
{ & V_21 ,
{ L_11 , L_12 ,
V_82 , V_83 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_30 ,
{ L_13 , L_14 , V_85 ,
V_86 , NULL , 0x0 , NULL , V_84 } } ,
{ & V_33 ,
{ L_15 , L_16 , V_82 ,
V_83 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_34 ,
{ L_17 , L_18 , V_82 ,
V_83 , F_33 ( V_87 ) , 0x00 , NULL , V_84 } } ,
#if 0
{ &hf_ppcap_source_address_type,
{ "Source Address Type", "ppcap.source_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00 , NULL, HFILL}},
#endif
{ & V_35 ,
{ L_19 , L_20 , V_82 ,
V_83 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_36 ,
{ L_21 , L_22 , V_82 ,
V_83 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_46 ,
{ L_21 , L_23 , V_82 ,
V_83 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_47 ,
{ L_24 , L_25 , V_88 ,
V_86 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_52 ,
{ L_26 , L_27 , V_89 ,
V_86 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_57 ,
{ L_15 , L_28 , V_82 ,
V_83 , NULL , 0x00 , NULL , V_84 } } ,
#if 0
{ &hf_ppcap_destination_address_type,
{ "Destination Address Type", "ppcap.destination_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00, NULL, HFILL}},
#endif
{ & V_59 ,
{ L_19 , L_29 , V_90 ,
V_83 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_60 ,
{ L_30 , L_31 , V_91 ,
V_83 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_63 ,
{ L_30 , L_32 , V_92 ,
V_83 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_64 ,
{ L_33 , L_34 , V_88 ,
V_86 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_66 ,
{ L_33 , L_35 , V_89 ,
V_86 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_54 ,
{ L_36 , L_37 , V_85 ,
V_86 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_67 ,
{ L_38 , L_39 , V_85 ,
V_86 , NULL , 0x00 , NULL , V_84 } } ,
{ & V_68 ,
{ L_40 , L_41 , V_85 ,
V_86 , NULL , 0x0000 , NULL , V_84 } } ,
{ & V_70 ,
{ L_42 , L_43 , V_93 ,
V_86 , NULL , 0x0000 , NULL , V_84 } } ,
} ;
static T_8 * V_94 [] = {
& V_18 ,
& V_20 ,
& V_95 ,
} ;
V_16 = F_34 ( L_44 , L_1 , L_45 ) ;
F_35 ( V_16 , V_81 , F_36 ( V_81 ) ) ;
F_37 ( V_94 , F_36 ( V_94 ) ) ;
F_38 ( L_45 , F_1 , V_16 ) ;
}
void F_39 ( void )
{
V_96 = F_40 ( L_45 ) ;
V_71 = F_40 ( L_4 ) ;
V_74 = F_40 ( L_5 ) ;
V_75 = F_40 ( L_6 ) ;
V_76 = F_40 ( L_7 ) ;
V_77 = F_40 ( L_8 ) ;
V_78 = F_40 ( L_9 ) ;
V_79 = F_40 ( L_10 ) ;
V_80 = F_40 ( L_46 ) ;
V_73 = F_41 ( L_47 ) ;
}
