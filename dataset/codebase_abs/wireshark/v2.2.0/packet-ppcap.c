static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 , * V_7 ;
T_6 V_8 ;
int V_9 = 0 ;
T_7 V_10 = V_11 ;
F_2 ( V_2 -> V_12 , V_13 , L_1 ) ;
F_3 ( V_2 -> V_12 , V_14 ) ;
V_5 = F_4 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_6 = F_5 ( V_5 , V_17 ) ;
while ( F_6 ( V_1 , V_9 ) > 0 )
{
V_8 = F_7 ( V_1 , V_9 ) ;
V_7 = F_8 ( V_6 , V_1 , V_9 , 2 , V_18 , NULL ,
F_9 ( V_8 , V_19 , L_2 ) ) ;
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
V_9 = F_14 ( V_1 , V_7 , V_9 ) ;
break;
case 6 :
V_9 = F_15 ( V_1 , V_7 , V_9 ) ;
break;
case 7 :
V_9 = F_16 ( V_1 , V_7 , V_9 ) ;
break;
case 8 :
V_9 = F_17 ( V_1 , V_7 , V_9 ) ;
break;
case 256 :
V_9 = F_18 ( V_1 , V_7 , V_9 ) ;
break;
}
}
return F_19 ( V_1 ) ;
}
static int
F_10 ( T_1 * V_1 , T_3 * V_7 , int V_9 , T_7 * V_10 )
{
char * string ;
T_6 V_20 = 0 ;
V_20 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_21 , V_1 , V_9 , 2 , V_22 ) ;
V_9 = V_9 + 2 ;
string = F_20 ( F_21 () , V_1 , V_9 , V_20 , V_23 | V_16 ) ;
if ( strcmp ( string , L_3 ) == 0 ) {
* V_10 = V_24 ;
} else if ( strcmp ( string , L_4 ) == 0 ) {
* V_10 = V_25 ;
} else if ( strcmp ( string , L_5 ) == 0 ) {
* V_10 = V_26 ;
} else if ( strcmp ( string , L_6 ) == 0 ) {
* V_10 = V_27 ;
} else if ( strcmp ( string , L_7 ) == 0 ) {
* V_10 = V_28 ;
} else if ( strcmp ( string , L_8 ) == 0 ) {
* V_10 = V_29 ;
} else if ( strcmp ( string , L_9 ) == 0 ) {
* V_10 = V_30 ;
} else if ( strcmp ( string , L_10 ) == 0 ) {
* V_10 = V_31 ;
} else if ( strcmp ( string , L_11 ) == 0 ) {
* V_10 = V_32 ;
}
F_4 ( V_7 , V_33 , V_1 , V_9 , V_20 , V_23 | V_16 ) ;
if ( V_20 % 4 )
V_20 = V_20 + ( 4 - ( V_20 % 4 ) ) ;
V_9 += V_20 ;
return V_9 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_7 , int V_9 )
{
int V_34 ;
T_6 V_20 ;
V_20 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_21 , V_1 , V_9 , 2 , V_22 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_35 , V_1 , V_9 , 2 , V_22 ) ;
V_9 += 2 ;
V_34 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_36 , V_1 , V_9 , 2 , V_22 ) ;
V_9 += 2 ;
if ( V_34 == 1 )
{
F_4 ( V_7 , V_37 , V_1 , V_9 , 1 , V_22 ) ;
V_9 += 1 ;
F_4 ( V_7 , V_38 , V_1 , V_9 , 3 , V_22 ) ;
V_39 = F_22 ( F_21 () , V_40 ) ;
V_39 -> V_41 = ( V_42 ) F_23 ( V_1 , V_9 ) ;
V_39 -> type = V_43 ;
V_39 -> V_44 = 0 ;
F_24 ( & V_2 -> V_45 , V_46 , sizeof( V_40 ) , ( V_47 * ) V_39 ) ;
if ( V_20 % 4 )
V_20 = V_20 + ( 4 - ( V_20 % 4 ) ) ;
V_9 += V_20 - 1 ;
return V_9 ;
}
else if ( V_34 == 2 )
{
F_4 ( V_7 , V_48 , V_1 , V_9 , V_20 , V_22 ) ;
V_39 = F_22 ( F_21 () , V_40 ) ;
V_39 -> V_41 = F_25 ( V_1 , V_9 ) ;
V_39 -> type = V_43 ;
V_39 -> V_44 = 0 ;
F_24 ( & V_2 -> V_45 , V_46 , sizeof( V_40 ) , ( V_47 * ) V_39 ) ;
}
else if ( V_34 == 3 )
{
if ( V_20 % 16 != 0 )
{
F_4 ( V_7 , V_49 , V_1 , V_9 , V_20 , V_16 ) ;
F_26 ( & V_2 -> V_50 , V_51 , 4 , V_1 , V_9 ) ;
F_27 ( & V_2 -> V_45 , & V_2 -> V_50 ) ;
}
else
{
F_4 ( V_7 , V_52 , V_1 , V_9 , V_20 , V_16 ) ;
F_26 ( & V_2 -> V_50 , V_53 , 6 , V_1 , V_9 ) ;
F_27 ( & V_2 -> V_45 , & V_2 -> V_50 ) ;
}
}
else if ( V_34 == 4 )
{
F_4 ( V_7 , V_54 , V_1 , V_9 , V_20 , V_55 | V_16 ) ;
F_26 ( & V_2 -> V_50 , V_56 , V_20 , V_1 , V_9 ) ;
F_27 ( & V_2 -> V_45 , & V_2 -> V_50 ) ;
}
if ( V_20 % 4 )
V_20 = V_20 + ( 4 - ( V_20 % 4 ) ) ;
V_9 += V_20 ;
return V_9 ;
}
static int
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_7 , int V_9 )
{
int V_57 ;
T_6 V_20 ;
V_20 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_21 , V_1 , V_9 , 2 , V_22 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_58 , V_1 , V_9 , 2 , V_22 ) ;
V_9 += 2 ;
V_57 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_36 , V_1 , V_9 , 2 , V_22 ) ;
V_9 += 2 ;
if ( V_57 == 1 )
{
V_59 = F_28 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_60 , V_1 , V_9 , 1 , V_22 ) ;
V_9 += 1 ;
F_4 ( V_7 , V_61 , V_1 , V_9 , 3 , V_22 ) ;
V_62 = F_22 ( F_21 () , V_40 ) ;
V_62 -> V_41 = ( V_42 ) F_23 ( V_1 , V_9 ) ;
V_62 -> type = V_43 ;
V_62 -> V_44 = 0 ;
F_24 ( & V_2 -> V_63 , V_46 , sizeof( V_40 ) , ( V_47 * ) V_62 ) ;
if ( V_20 % 4 )
V_20 = V_20 + ( 4 - ( V_20 % 4 ) ) ;
V_9 += V_20 - 1 ;
return V_9 ;
}
else if ( V_57 == 2 )
{
F_4 ( V_7 , V_64 , V_1 , V_9 , 4 , V_22 ) ;
V_62 = F_22 ( F_21 () , V_40 ) ;
V_62 -> V_41 = F_25 ( V_1 , V_9 ) ;
V_62 -> type = V_43 ;
V_62 -> V_44 = 0 ;
F_24 ( & V_2 -> V_63 , V_46 , sizeof( V_40 ) , ( V_47 * ) V_62 ) ;
}
else if ( V_57 == 3 )
{
if ( V_20 % 16 != 0 )
{
F_4 ( V_7 , V_65 , V_1 , V_9 , V_20 , V_16 ) ;
F_26 ( & V_2 -> V_66 , V_51 , 4 , V_1 , V_9 ) ;
F_27 ( & V_2 -> V_63 , & V_2 -> V_66 ) ;
}
else
{
F_4 ( V_7 , V_67 , V_1 , V_9 , V_20 , V_16 ) ;
F_26 ( & V_2 -> V_66 , V_53 , 6 , V_1 , V_9 ) ;
F_27 ( & V_2 -> V_63 , & V_2 -> V_66 ) ;
}
}
else if ( V_57 == 4 )
{
const V_47 * string ;
F_29 ( V_7 , V_68 , V_1 , V_9 , V_20 , V_23 | V_16 , F_21 () , & string ) ;
F_26 ( & V_2 -> V_66 , V_56 , V_20 , V_1 , V_9 ) ;
F_27 ( & V_2 -> V_63 , & V_2 -> V_66 ) ;
}
if ( V_20 % 4 )
V_20 = V_20 + ( 4 - ( V_20 % 4 ) ) ;
V_9 += V_20 ;
return V_9 ;
}
static int
F_18 ( T_1 * V_1 , T_3 * V_7 , int V_9 )
{
T_6 V_20 ;
V_20 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_21 , V_1 , V_9 , 2 , V_22 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_69 , V_1 , V_9 , V_20 , V_55 | V_16 ) ;
if ( V_20 % 4 )
V_20 = V_20 + ( 4 - ( V_20 % 4 ) ) ;
V_9 += V_20 ;
return V_9 ;
}
static int
F_14 ( T_1 * V_1 , T_3 * V_7 , int V_9 )
{
F_4 ( V_7 , V_70 , V_1 , V_9 , 2 , V_22 ) ;
V_9 = V_9 + 6 ;
return V_9 ;
}
static int
F_15 ( T_1 * V_1 , T_3 * V_7 , int V_9 )
{
F_4 ( V_7 , V_71 , V_1 , V_9 , 2 , V_22 ) ;
V_9 = V_9 + 6 ;
return V_9 ;
}
static int
F_16 ( T_1 * V_1 , T_3 * V_7 , int V_9 )
{
F_4 ( V_7 , V_21 , V_1 , V_9 , 2 , V_22 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_72 , V_1 , V_9 , 4 , V_55 | V_16 ) ;
V_9 += 4 ;
return V_9 ;
}
static int
F_17 ( T_1 * V_1 V_4 , T_3 * V_3 V_4 , int V_9 )
{
T_6 V_73 ;
V_73 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_3 , V_21 , V_1 , V_9 , 2 , V_22 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_3 , V_74 , V_1 , V_9 , V_73 , V_55 | V_16 ) ;
return V_9 + 16 ;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_7 , int V_9 , T_3 * V_3 , T_7 V_10 )
{
T_1 * V_75 ;
T_6 V_20 ;
V_20 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_7 , V_21 , V_1 , V_9 , 2 , V_22 ) ;
V_9 = V_9 + 2 ;
F_4 ( V_7 , V_76 , V_1 , V_9 , V_20 , V_16 ) ;
if ( V_20 % 4 )
V_20 = V_20 + ( 4 - ( V_20 % 4 ) ) ;
V_75 = F_30 ( V_1 , V_9 ) ;
switch ( V_10 ) {
case V_24 :
F_31 ( V_77 , V_75 , V_2 , V_3 ) ;
break;
case V_25 :
if ( V_59 != V_78 && F_32 ( V_79 , V_59 , V_75 , V_2 , V_3 ) ) {
return V_9 + V_20 ;
} else{
F_31 ( V_80 , V_75 , V_2 , V_3 ) ;
}
break;
case V_26 :
F_31 ( V_81 , V_75 , V_2 , V_3 ) ;
break;
case V_27 :
F_31 ( V_82 , V_75 , V_2 , V_3 ) ;
break;
case V_28 :
F_31 ( V_83 , V_75 , V_2 , V_3 ) ;
break;
case V_29 :
F_31 ( V_84 , V_75 , V_2 , V_3 ) ;
break;
case V_30 :
F_31 ( V_85 , V_75 , V_2 , V_3 ) ;
break;
case V_31 :
F_31 ( V_86 , V_75 , V_2 , V_3 ) ;
break;
case V_32 :
F_31 ( V_87 , V_75 , V_2 , V_3 ) ;
break;
default:
F_33 ( V_75 , V_2 , V_3 ) ;
break;
}
V_9 += V_20 ;
return V_9 ;
}
void F_34 ( void )
{
T_8 * V_88 ;
static T_9 V_89 [] = {
{ & V_21 ,
{ L_12 , L_13 ,
V_90 , V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_33 ,
{ L_14 , L_15 , V_93 ,
V_94 , NULL , 0x0 , NULL , V_92 } } ,
{ & V_35 ,
{ L_16 , L_17 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_36 ,
{ L_18 , L_19 , V_90 ,
V_91 , F_35 ( V_95 ) , 0x00 , NULL , V_92 } } ,
#if 0
{ &hf_ppcap_source_address_type,
{ "Source Address Type", "ppcap.source_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00 , NULL, HFILL}},
#endif
{ & V_37 ,
{ L_20 , L_21 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_38 ,
{ L_22 , L_23 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_48 ,
{ L_22 , L_24 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_49 ,
{ L_25 , L_26 , V_96 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_52 ,
{ L_25 , L_27 , V_97 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_58 ,
{ L_16 , L_28 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
#if 0
{ &hf_ppcap_destination_address_type,
{ "Destination Address Type", "ppcap.destination_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00, NULL, HFILL}},
#endif
{ & V_60 ,
{ L_20 , L_29 , V_98 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_61 ,
{ L_30 , L_31 , V_99 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_64 ,
{ L_30 , L_32 , V_100 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_65 ,
{ L_33 , L_34 , V_96 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_67 ,
{ L_33 , L_35 , V_97 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_54 ,
{ L_36 , L_37 , V_93 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_68 ,
{ L_38 , L_39 , V_93 ,
V_94 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_69 ,
{ L_40 , L_41 , V_93 ,
V_94 , NULL , 0x0000 , NULL , V_92 } } ,
{ & V_76 ,
{ L_42 , L_43 , V_101 ,
V_94 , NULL , 0x0000 , NULL , V_92 } } ,
{ & V_70 ,
{ L_44 , L_45 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_71 ,
{ L_46 , L_47 , V_90 ,
V_91 , NULL , 0x00 , NULL , V_92 } } ,
{ & V_72 ,
{ L_48 , L_49 , V_93 ,
V_94 , NULL , 0x0 , NULL , V_92 } } ,
{ & V_74 ,
{ L_50 , L_51 , V_93 ,
V_94 , NULL , 0x0 , NULL , V_92 } } ,
} ;
static T_10 * V_102 [] = {
& V_17 ,
& V_18 ,
& V_103 ,
} ;
V_15 = F_36 ( L_52 , L_1 , L_53 ) ;
F_37 ( V_15 , V_89 , F_38 ( V_89 ) ) ;
F_39 ( V_102 , F_38 ( V_102 ) ) ;
F_40 ( L_53 , F_1 , V_15 ) ;
V_88 = F_41 ( V_15 , V_104 ) ;
F_42 ( V_88 , L_54 ) ;
}
void V_104 ( void )
{
V_105 = F_43 ( L_53 , V_15 ) ;
V_77 = F_43 ( L_3 , V_15 ) ;
V_80 = F_43 ( L_4 , V_15 ) ;
V_81 = F_43 ( L_5 , V_15 ) ;
V_82 = F_43 ( L_6 , V_15 ) ;
V_83 = F_43 ( L_7 , V_15 ) ;
V_84 = F_43 ( L_8 , V_15 ) ;
V_85 = F_43 ( L_9 , V_15 ) ;
V_86 = F_43 ( L_10 , V_15 ) ;
V_87 = F_43 ( L_11 , V_15 ) ;
V_79 = F_44 ( L_55 ) ;
V_46 = F_45 ( L_56 ) ;
}
