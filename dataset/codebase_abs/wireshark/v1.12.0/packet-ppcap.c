static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 , * V_5 ;
T_3 * V_6 , * V_7 ;
T_5 V_8 ;
int V_9 = 0 ;
T_6 V_10 = V_11 ;
F_2 ( V_2 -> V_12 , V_13 , L_1 ) ;
F_3 ( V_2 -> V_12 , V_14 ) ;
V_4 = F_4 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_6 = F_5 ( V_4 , V_17 ) ;
while ( F_6 ( V_1 , V_9 ) > 0 )
{
V_8 = F_7 ( V_1 , V_9 ) ;
V_5 = F_8 ( V_6 , V_1 , V_9 , 2 , L_2 ,
F_9 ( V_8 , V_18 , L_3 ) ) ;
V_7 = F_5 ( V_5 , V_19 ) ;
V_9 = V_9 + 2 ;
switch ( V_8 ) {
case 1 :
V_10 = V_11 ;
V_9 = F_10 ( V_1 , V_7 , V_9 , & V_10 ) ;
break;
case 2 :
V_9 = F_11 ( V_1 , V_2 , V_7 , V_9 , V_3 , V_10 ) ;
break;
case 3 :
V_9 = F_12 ( V_1 , V_2 , V_7 , V_9 ) ;
break;
case 4 :
V_9 = F_13 ( V_1 , V_2 , V_7 , V_9 ) ;
break;
case 5 :
if( V_20 == V_21 )
V_9 = F_14 ( V_1 , V_7 , V_9 ) ;
break;
case 6 :
if( V_20 == V_21 )
V_9 = F_15 ( V_1 , V_7 , V_9 ) ;
break;
case 7 :
if( V_20 == V_21 )
V_9 = F_16 ( V_1 , V_7 , V_9 ) ;
break;
case 256 :
if( V_20 == V_22 )
V_9 = F_17 ( V_1 , V_7 , V_9 ) ;
break;
}
}
}
static int
F_10 ( T_1 * V_1 , T_3 * V_7 , int V_9 , T_6 * V_10 )
{
char * string ;
T_5 V_23 = 0 ;
V_23 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_24 , V_1 , V_9 , 2 , V_25 ) ;
V_9 = V_9 + 2 ;
string = F_18 ( F_19 () , V_1 , V_9 , V_23 , V_26 | V_16 ) ;
if ( strcmp ( string , L_4 ) == 0 ) {
* V_10 = V_27 ;
} else if ( strcmp ( string , L_5 ) == 0 ) {
* V_10 = V_28 ;
} else if ( strcmp ( string , L_6 ) == 0 ) {
* V_10 = V_29 ;
} else if ( strcmp ( string , L_7 ) == 0 ) {
* V_10 = V_30 ;
} else if ( strcmp ( string , L_8 ) == 0 ) {
* V_10 = V_31 ;
} else if ( strcmp ( string , L_9 ) == 0 ) {
* V_10 = V_32 ;
} else if ( strcmp ( string , L_10 ) == 0 ) {
* V_10 = V_33 ;
}
F_4 ( V_7 , V_34 , V_1 , V_9 , V_23 , V_26 | V_16 ) ;
if ( V_23 % 4 )
V_23 = V_23 + ( 4 - ( V_23 % 4 ) ) ;
V_9 += V_23 ;
return V_9 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_7 , int V_9 )
{
int V_35 ;
T_5 V_23 ;
V_23 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_24 , V_1 , V_9 , 2 , V_25 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_36 , V_1 , V_9 , 2 , V_25 ) ;
V_9 += 2 ;
V_35 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_37 , V_1 , V_9 , 2 , V_25 ) ;
V_9 += 2 ;
if ( V_35 == 1 )
{
F_4 ( V_7 , V_38 , V_1 , V_9 , 1 , V_25 ) ;
V_9 += 1 ;
F_4 ( V_7 , V_39 , V_1 , V_9 , 3 , V_25 ) ;
V_40 = F_20 ( F_19 () , V_41 ) ;
V_40 -> V_42 = ( V_43 ) F_21 ( V_1 , V_9 ) ;
V_40 -> type = V_44 ;
V_40 -> V_45 = 0 ;
F_22 ( & V_2 -> V_46 , V_47 , sizeof( V_41 ) , ( V_48 * ) V_40 ) ;
if ( V_23 % 4 )
V_23 = V_23 + ( 4 - ( V_23 % 4 ) ) ;
V_9 += V_23 - 1 ;
return V_9 ;
}
else if ( V_35 == 2 )
{
F_4 ( V_7 , V_49 , V_1 , V_9 , V_23 , V_25 ) ;
V_40 = F_20 ( F_19 () , V_41 ) ;
V_40 -> V_42 = F_23 ( V_1 , V_9 ) ;
V_40 -> type = V_44 ;
V_40 -> V_45 = 0 ;
F_22 ( & V_2 -> V_46 , V_47 , sizeof( V_41 ) , ( V_48 * ) V_40 ) ;
}
else if ( V_35 == 3 )
{
if ( V_23 % 16 != 0 )
{
F_24 ( V_7 , V_50 , V_1 , V_9 , V_23 , F_25 ( V_1 , V_9 ) ) ;
F_26 ( & V_2 -> V_51 , V_52 , V_1 , V_9 , 4 ) ;
F_27 ( & V_2 -> V_46 , & V_2 -> V_51 ) ;
}
else
{
struct V_53 V_54 ;
F_28 ( V_1 , V_9 , & V_54 ) ;
F_29 ( V_7 , V_55 , V_1 , V_9 , V_23 , ( V_48 * ) & V_54 ) ;
F_26 ( & V_2 -> V_51 , V_56 , V_1 , V_9 , 6 ) ;
F_27 ( & V_2 -> V_46 , & V_2 -> V_51 ) ;
}
}
else if ( V_35 == 4 )
{
F_4 ( V_7 , V_57 , V_1 , V_9 , V_23 , V_25 | V_58 ) ;
F_26 ( & V_2 -> V_51 , V_59 , V_1 , V_9 , V_23 ) ;
F_27 ( & V_2 -> V_46 , & V_2 -> V_51 ) ;
}
if ( V_23 % 4 )
V_23 = V_23 + ( 4 - ( V_23 % 4 ) ) ;
V_9 += V_23 ;
return V_9 ;
}
static int
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_7 , int V_9 )
{
int V_60 ;
T_5 V_23 ;
V_23 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_24 , V_1 , V_9 , 2 , V_25 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_61 , V_1 , V_9 , 2 , V_25 ) ;
V_9 += 2 ;
V_60 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_37 , V_1 , V_9 , 2 , V_25 ) ;
V_9 += 2 ;
if ( V_60 == 1 )
{
V_62 = F_30 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_63 , V_1 , V_9 , 1 , V_25 ) ;
V_9 += 1 ;
F_4 ( V_7 , V_64 , V_1 , V_9 , 3 , V_25 ) ;
V_65 = F_20 ( F_19 () , V_41 ) ;
V_65 -> V_42 = ( V_43 ) F_21 ( V_1 , V_9 ) ;
V_65 -> type = V_44 ;
V_65 -> V_45 = 0 ;
F_22 ( & V_2 -> V_66 , V_47 , sizeof( V_41 ) , ( V_48 * ) V_65 ) ;
if ( V_23 % 4 )
V_23 = V_23 + ( 4 - ( V_23 % 4 ) ) ;
V_9 += V_23 - 1 ;
return V_9 ;
}
else if ( V_60 == 2 )
{
F_4 ( V_7 , V_67 , V_1 , V_9 , 4 , V_25 ) ;
V_65 = F_20 ( F_19 () , V_41 ) ;
V_65 -> V_42 = F_23 ( V_1 , V_9 ) ;
V_65 -> type = V_44 ;
V_65 -> V_45 = 0 ;
F_22 ( & V_2 -> V_66 , V_47 , sizeof( V_41 ) , ( V_48 * ) V_65 ) ;
}
else if ( V_60 == 3 )
{
if ( V_23 % 16 != 0 )
{
F_24 ( V_7 , V_68 , V_1 , V_9 , V_23 , F_25 ( V_1 , V_9 ) ) ;
F_26 ( & V_2 -> V_69 , V_52 , V_1 , V_9 , 4 ) ;
F_27 ( & V_2 -> V_66 , & V_2 -> V_69 ) ;
}
else
{
struct V_53 V_54 ;
F_28 ( V_1 , V_9 , & V_54 ) ;
F_29 ( V_7 , V_70 , V_1 , V_9 , V_23 , ( V_48 * ) & V_54 ) ;
F_26 ( & V_2 -> V_69 , V_56 , V_1 , V_9 , 6 ) ;
F_27 ( & V_2 -> V_66 , & V_2 -> V_69 ) ;
}
}
else if ( V_60 == 4 )
{
char * string ;
string = F_18 ( F_19 () , V_1 , V_9 , V_23 , V_26 | V_16 ) ;
F_31 ( V_7 , V_71 , V_1 , V_9 , V_23 , string ) ;
F_26 ( & V_2 -> V_69 , V_59 , V_1 , V_9 , V_23 ) ;
F_27 ( & V_2 -> V_66 , & V_2 -> V_69 ) ;
}
if ( V_23 % 4 )
V_23 = V_23 + ( 4 - ( V_23 % 4 ) ) ;
V_9 += V_23 ;
return V_9 ;
}
static int
F_17 ( T_1 * V_1 , T_3 * V_7 , int V_9 )
{
T_5 V_23 ;
V_23 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_24 , V_1 , V_9 , 2 , V_25 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_72 , V_1 , V_9 , V_23 , V_58 | V_16 ) ;
if ( V_23 % 4 )
V_23 = V_23 + ( 4 - ( V_23 % 4 ) ) ;
V_9 += V_23 ;
return V_9 ;
}
static int
F_14 ( T_1 * V_1 , T_3 * V_7 , int V_9 )
{
F_4 ( V_7 , V_73 , V_1 , V_9 , 2 , V_25 ) ;
V_9 = V_9 + 6 ;
return V_9 ;
}
static int
F_15 ( T_1 * V_1 , T_3 * V_7 , int V_9 )
{
F_4 ( V_7 , V_74 , V_1 , V_9 , 2 , V_25 ) ;
V_9 = V_9 + 6 ;
return V_9 ;
}
static int
F_16 ( T_1 * V_1 , T_3 * V_7 , int V_9 )
{
F_4 ( V_7 , V_24 , V_1 , V_9 , 2 , V_25 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_75 , V_1 , V_9 , 4 , V_25 | V_58 ) ;
V_9 += 4 ;
return V_9 ;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_7 , int V_9 , T_3 * V_3 , T_6 V_10 )
{
T_1 * V_76 ;
T_5 V_23 ;
V_23 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_24 , V_1 , V_9 , 2 , V_25 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_77 , V_1 , V_9 , V_23 , V_16 ) ;
if ( V_23 % 4 )
V_23 = V_23 + ( 4 - ( V_23 % 4 ) ) ;
V_76 = F_32 ( V_1 , V_9 ) ;
switch ( V_10 ) {
case V_27 :
F_33 ( V_78 , V_76 , V_2 , V_3 ) ;
break;
case V_28 :
if ( V_62 != V_79 && F_34 ( V_80 , V_62 , V_76 , V_2 , V_3 ) ) {
return V_9 + V_23 ;
} else{
F_33 ( V_81 , V_76 , V_2 , V_3 ) ;
}
break;
case V_29 :
F_33 ( V_82 , V_76 , V_2 , V_3 ) ;
break;
case V_30 :
F_33 ( V_83 , V_76 , V_2 , V_3 ) ;
break;
case V_31 :
F_33 ( V_84 , V_76 , V_2 , V_3 ) ;
break;
case V_32 :
F_33 ( V_85 , V_76 , V_2 , V_3 ) ;
break;
case V_33 :
F_33 ( V_86 , V_76 , V_2 , V_3 ) ;
break;
default:
F_33 ( V_87 , V_76 , V_2 , V_3 ) ;
break;
}
V_9 += V_23 ;
return V_9 ;
}
void F_35 ( void )
{
T_7 * V_88 ;
static T_8 V_89 [] = {
{ & V_24 ,
{ L_11 , L_12 ,
V_90 , V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_34 ,
{ L_13 , L_14 , V_93 ,
V_94 , NULL , 0x0 , NULL , V_92 } } ,
{ & V_36 ,
{ L_15 , L_16 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_37 ,
{ L_17 , L_18 , V_90 ,
V_91 , F_36 ( V_95 ) , 0x00 , NULL , V_92 } } ,
#if 0
{ &hf_ppcap_source_address_type,
{ "Source Address Type", "ppcap.source_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00 , NULL, HFILL}},
#endif
{ & V_38 ,
{ L_19 , L_20 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_39 ,
{ L_21 , L_22 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_49 ,
{ L_21 , L_23 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_50 ,
{ L_24 , L_25 , V_96 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_55 ,
{ L_26 , L_27 , V_97 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_61 ,
{ L_15 , L_28 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
#if 0
{ &hf_ppcap_destination_address_type,
{ "Destination Address Type", "ppcap.destination_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00, NULL, HFILL}},
#endif
{ & V_63 ,
{ L_19 , L_29 , V_98 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_64 ,
{ L_30 , L_31 , V_99 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_67 ,
{ L_30 , L_32 , V_100 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_68 ,
{ L_33 , L_34 , V_96 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_70 ,
{ L_33 , L_35 , V_97 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_57 ,
{ L_36 , L_37 , V_93 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_71 ,
{ L_38 , L_39 , V_93 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_72 ,
{ L_40 , L_41 , V_93 ,
V_94 , NULL , 0x0000 , NULL , V_92 } } ,
{ & V_77 ,
{ L_42 , L_43 , V_101 ,
V_94 , NULL , 0x0000 , NULL , V_92 } } ,
{ & V_73 ,
{ L_44 , L_45 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_74 ,
{ L_46 , L_47 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_75 ,
{ L_48 , L_49 , V_93 ,
V_94 , NULL , 0x0 , NULL , V_92 } } ,
} ;
static T_9 * V_102 [] = {
& V_17 ,
& V_19 ,
& V_103 ,
} ;
V_15 = F_37 ( L_50 , L_1 , L_51 ) ;
F_38 ( V_15 , V_89 , F_39 ( V_89 ) ) ;
F_40 ( V_102 , F_39 ( V_102 ) ) ;
F_41 ( L_51 , F_1 , V_15 ) ;
V_88 = F_42 ( V_15 , V_104 ) ;
F_43 ( V_88 , L_52 , L_53 , L_54 , & V_20 , V_105 , TRUE ) ;
}
void V_104 ( void )
{
V_106 = F_44 ( L_51 ) ;
V_78 = F_44 ( L_4 ) ;
V_81 = F_44 ( L_5 ) ;
V_82 = F_44 ( L_6 ) ;
V_83 = F_44 ( L_7 ) ;
V_84 = F_44 ( L_8 ) ;
V_85 = F_44 ( L_9 ) ;
V_86 = F_44 ( L_10 ) ;
V_87 = F_44 ( L_55 ) ;
V_80 = F_45 ( L_56 ) ;
}
