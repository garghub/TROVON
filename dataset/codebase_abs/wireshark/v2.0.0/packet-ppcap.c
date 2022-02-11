static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_3 * V_5 , * V_6 ;
T_5 V_7 ;
int V_8 = 0 ;
T_6 V_9 = V_10 ;
F_2 ( V_2 -> V_11 , V_12 , L_1 ) ;
F_3 ( V_2 -> V_11 , V_13 ) ;
V_4 = F_4 ( V_3 , V_14 , V_1 , 0 , - 1 , V_15 ) ;
V_5 = F_5 ( V_4 , V_16 ) ;
while ( F_6 ( V_1 , V_8 ) > 0 )
{
V_7 = F_7 ( V_1 , V_8 ) ;
V_6 = F_8 ( V_5 , V_1 , V_8 , 2 , V_17 , NULL ,
F_9 ( V_7 , V_18 , L_2 ) ) ;
V_8 = V_8 + 2 ;
switch ( V_7 ) {
case 1 :
V_9 = V_10 ;
V_8 = F_10 ( V_1 , V_6 , V_8 , & V_9 ) ;
break;
case 2 :
V_8 = F_11 ( V_1 , V_2 , V_6 , V_8 , V_3 , V_9 ) ;
break;
case 3 :
V_8 = F_12 ( V_1 , V_2 , V_6 , V_8 ) ;
break;
case 4 :
V_8 = F_13 ( V_1 , V_2 , V_6 , V_8 ) ;
break;
case 5 :
if( V_19 == V_20 )
V_8 = F_14 ( V_1 , V_6 , V_8 ) ;
break;
case 6 :
if( V_19 == V_20 )
V_8 = F_15 ( V_1 , V_6 , V_8 ) ;
break;
case 7 :
if( V_19 == V_20 )
V_8 = F_16 ( V_1 , V_6 , V_8 ) ;
break;
case 256 :
if( V_19 == V_21 )
V_8 = F_17 ( V_1 , V_6 , V_8 ) ;
break;
}
}
}
static int
F_10 ( T_1 * V_1 , T_3 * V_6 , int V_8 , T_6 * V_9 )
{
char * string ;
T_5 V_22 = 0 ;
V_22 = F_7 ( V_1 , V_8 ) ;
F_4 ( V_6 , V_23 , V_1 , V_8 , 2 , V_24 ) ;
V_8 = V_8 + 2 ;
string = F_18 ( F_19 () , V_1 , V_8 , V_22 , V_25 | V_15 ) ;
if ( strcmp ( string , L_3 ) == 0 ) {
* V_9 = V_26 ;
} else if ( strcmp ( string , L_4 ) == 0 ) {
* V_9 = V_27 ;
} else if ( strcmp ( string , L_5 ) == 0 ) {
* V_9 = V_28 ;
} else if ( strcmp ( string , L_6 ) == 0 ) {
* V_9 = V_29 ;
} else if ( strcmp ( string , L_7 ) == 0 ) {
* V_9 = V_30 ;
} else if ( strcmp ( string , L_8 ) == 0 ) {
* V_9 = V_31 ;
} else if ( strcmp ( string , L_9 ) == 0 ) {
* V_9 = V_32 ;
}
F_4 ( V_6 , V_33 , V_1 , V_8 , V_22 , V_25 | V_15 ) ;
if ( V_22 % 4 )
V_22 = V_22 + ( 4 - ( V_22 % 4 ) ) ;
V_8 += V_22 ;
return V_8 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_6 , int V_8 )
{
int V_34 ;
T_5 V_22 ;
V_22 = F_7 ( V_1 , V_8 ) ;
F_4 ( V_6 , V_23 , V_1 , V_8 , 2 , V_24 ) ;
V_8 = V_8 + 2 ;
F_4 ( V_6 , V_35 , V_1 , V_8 , 2 , V_24 ) ;
V_8 += 2 ;
V_34 = F_7 ( V_1 , V_8 ) ;
F_4 ( V_6 , V_36 , V_1 , V_8 , 2 , V_24 ) ;
V_8 += 2 ;
if ( V_34 == 1 )
{
F_4 ( V_6 , V_37 , V_1 , V_8 , 1 , V_24 ) ;
V_8 += 1 ;
F_4 ( V_6 , V_38 , V_1 , V_8 , 3 , V_24 ) ;
V_39 = F_20 ( F_19 () , V_40 ) ;
V_39 -> V_41 = ( V_42 ) F_21 ( V_1 , V_8 ) ;
V_39 -> type = V_43 ;
V_39 -> V_44 = 0 ;
F_22 ( & V_2 -> V_45 , V_46 , sizeof( V_40 ) , ( V_47 * ) V_39 ) ;
if ( V_22 % 4 )
V_22 = V_22 + ( 4 - ( V_22 % 4 ) ) ;
V_8 += V_22 - 1 ;
return V_8 ;
}
else if ( V_34 == 2 )
{
F_4 ( V_6 , V_48 , V_1 , V_8 , V_22 , V_24 ) ;
V_39 = F_20 ( F_19 () , V_40 ) ;
V_39 -> V_41 = F_23 ( V_1 , V_8 ) ;
V_39 -> type = V_43 ;
V_39 -> V_44 = 0 ;
F_22 ( & V_2 -> V_45 , V_46 , sizeof( V_40 ) , ( V_47 * ) V_39 ) ;
}
else if ( V_34 == 3 )
{
if ( V_22 % 16 != 0 )
{
F_24 ( V_6 , V_49 , V_1 , V_8 , V_22 , F_25 ( V_1 , V_8 ) ) ;
F_26 ( & V_2 -> V_50 , V_51 , V_1 , V_8 , 4 ) ;
F_27 ( & V_2 -> V_45 , & V_2 -> V_50 ) ;
}
else
{
struct V_52 V_53 ;
F_28 ( V_1 , V_8 , & V_53 ) ;
F_29 ( V_6 , V_54 , V_1 , V_8 , V_22 , & V_53 ) ;
F_26 ( & V_2 -> V_50 , V_55 , V_1 , V_8 , 6 ) ;
F_27 ( & V_2 -> V_45 , & V_2 -> V_50 ) ;
}
}
else if ( V_34 == 4 )
{
F_4 ( V_6 , V_56 , V_1 , V_8 , V_22 , V_57 | V_15 ) ;
F_26 ( & V_2 -> V_50 , V_58 , V_1 , V_8 , V_22 ) ;
F_27 ( & V_2 -> V_45 , & V_2 -> V_50 ) ;
}
if ( V_22 % 4 )
V_22 = V_22 + ( 4 - ( V_22 % 4 ) ) ;
V_8 += V_22 ;
return V_8 ;
}
static int
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_6 , int V_8 )
{
int V_59 ;
T_5 V_22 ;
V_22 = F_7 ( V_1 , V_8 ) ;
F_4 ( V_6 , V_23 , V_1 , V_8 , 2 , V_24 ) ;
V_8 = V_8 + 2 ;
F_4 ( V_6 , V_60 , V_1 , V_8 , 2 , V_24 ) ;
V_8 += 2 ;
V_59 = F_7 ( V_1 , V_8 ) ;
F_4 ( V_6 , V_36 , V_1 , V_8 , 2 , V_24 ) ;
V_8 += 2 ;
if ( V_59 == 1 )
{
V_61 = F_30 ( V_1 , V_8 ) ;
F_4 ( V_6 , V_62 , V_1 , V_8 , 1 , V_24 ) ;
V_8 += 1 ;
F_4 ( V_6 , V_63 , V_1 , V_8 , 3 , V_24 ) ;
V_64 = F_20 ( F_19 () , V_40 ) ;
V_64 -> V_41 = ( V_42 ) F_21 ( V_1 , V_8 ) ;
V_64 -> type = V_43 ;
V_64 -> V_44 = 0 ;
F_22 ( & V_2 -> V_65 , V_46 , sizeof( V_40 ) , ( V_47 * ) V_64 ) ;
if ( V_22 % 4 )
V_22 = V_22 + ( 4 - ( V_22 % 4 ) ) ;
V_8 += V_22 - 1 ;
return V_8 ;
}
else if ( V_59 == 2 )
{
F_4 ( V_6 , V_66 , V_1 , V_8 , 4 , V_24 ) ;
V_64 = F_20 ( F_19 () , V_40 ) ;
V_64 -> V_41 = F_23 ( V_1 , V_8 ) ;
V_64 -> type = V_43 ;
V_64 -> V_44 = 0 ;
F_22 ( & V_2 -> V_65 , V_46 , sizeof( V_40 ) , ( V_47 * ) V_64 ) ;
}
else if ( V_59 == 3 )
{
if ( V_22 % 16 != 0 )
{
F_24 ( V_6 , V_67 , V_1 , V_8 , V_22 , F_25 ( V_1 , V_8 ) ) ;
F_26 ( & V_2 -> V_68 , V_51 , V_1 , V_8 , 4 ) ;
F_27 ( & V_2 -> V_65 , & V_2 -> V_68 ) ;
}
else
{
struct V_52 V_53 ;
F_28 ( V_1 , V_8 , & V_53 ) ;
F_29 ( V_6 , V_69 , V_1 , V_8 , V_22 , & V_53 ) ;
F_26 ( & V_2 -> V_68 , V_55 , V_1 , V_8 , 6 ) ;
F_27 ( & V_2 -> V_65 , & V_2 -> V_68 ) ;
}
}
else if ( V_59 == 4 )
{
char * string ;
string = F_18 ( F_19 () , V_1 , V_8 , V_22 , V_25 | V_15 ) ;
F_31 ( V_6 , V_70 , V_1 , V_8 , V_22 , string ) ;
F_26 ( & V_2 -> V_68 , V_58 , V_1 , V_8 , V_22 ) ;
F_27 ( & V_2 -> V_65 , & V_2 -> V_68 ) ;
}
if ( V_22 % 4 )
V_22 = V_22 + ( 4 - ( V_22 % 4 ) ) ;
V_8 += V_22 ;
return V_8 ;
}
static int
F_17 ( T_1 * V_1 , T_3 * V_6 , int V_8 )
{
T_5 V_22 ;
V_22 = F_7 ( V_1 , V_8 ) ;
F_4 ( V_6 , V_23 , V_1 , V_8 , 2 , V_24 ) ;
V_8 = V_8 + 2 ;
F_4 ( V_6 , V_71 , V_1 , V_8 , V_22 , V_57 | V_15 ) ;
if ( V_22 % 4 )
V_22 = V_22 + ( 4 - ( V_22 % 4 ) ) ;
V_8 += V_22 ;
return V_8 ;
}
static int
F_14 ( T_1 * V_1 , T_3 * V_6 , int V_8 )
{
F_4 ( V_6 , V_72 , V_1 , V_8 , 2 , V_24 ) ;
V_8 = V_8 + 6 ;
return V_8 ;
}
static int
F_15 ( T_1 * V_1 , T_3 * V_6 , int V_8 )
{
F_4 ( V_6 , V_73 , V_1 , V_8 , 2 , V_24 ) ;
V_8 = V_8 + 6 ;
return V_8 ;
}
static int
F_16 ( T_1 * V_1 , T_3 * V_6 , int V_8 )
{
F_4 ( V_6 , V_23 , V_1 , V_8 , 2 , V_24 ) ;
V_8 = V_8 + 2 ;
F_4 ( V_6 , V_74 , V_1 , V_8 , 4 , V_57 | V_15 ) ;
V_8 += 4 ;
return V_8 ;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_6 , int V_8 , T_3 * V_3 , T_6 V_9 )
{
T_1 * V_75 ;
T_5 V_22 ;
V_22 = F_7 ( V_1 , V_8 ) ;
F_4 ( V_6 , V_23 , V_1 , V_8 , 2 , V_24 ) ;
V_8 = V_8 + 2 ;
F_4 ( V_6 , V_76 , V_1 , V_8 , V_22 , V_15 ) ;
if ( V_22 % 4 )
V_22 = V_22 + ( 4 - ( V_22 % 4 ) ) ;
V_75 = F_32 ( V_1 , V_8 ) ;
switch ( V_9 ) {
case V_26 :
F_33 ( V_77 , V_75 , V_2 , V_3 ) ;
break;
case V_27 :
if ( V_61 != V_78 && F_34 ( V_79 , V_61 , V_75 , V_2 , V_3 ) ) {
return V_8 + V_22 ;
} else{
F_33 ( V_80 , V_75 , V_2 , V_3 ) ;
}
break;
case V_28 :
F_33 ( V_81 , V_75 , V_2 , V_3 ) ;
break;
case V_29 :
F_33 ( V_82 , V_75 , V_2 , V_3 ) ;
break;
case V_30 :
F_33 ( V_83 , V_75 , V_2 , V_3 ) ;
break;
case V_31 :
F_33 ( V_84 , V_75 , V_2 , V_3 ) ;
break;
case V_32 :
F_33 ( V_85 , V_75 , V_2 , V_3 ) ;
break;
default:
F_33 ( V_86 , V_75 , V_2 , V_3 ) ;
break;
}
V_8 += V_22 ;
return V_8 ;
}
void F_35 ( void )
{
T_7 * V_87 ;
static T_8 V_88 [] = {
{ & V_23 ,
{ L_10 , L_11 ,
V_89 , V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_33 ,
{ L_12 , L_13 , V_92 ,
V_93 , NULL , 0x0 , NULL , V_91 } } ,
{ & V_35 ,
{ L_14 , L_15 , V_89 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_36 ,
{ L_16 , L_17 , V_89 ,
V_90 , F_36 ( V_94 ) , 0x00 , NULL , V_91 } } ,
#if 0
{ &hf_ppcap_source_address_type,
{ "Source Address Type", "ppcap.source_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00 , NULL, HFILL}},
#endif
{ & V_37 ,
{ L_18 , L_19 , V_89 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_38 ,
{ L_20 , L_21 , V_89 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_48 ,
{ L_20 , L_22 , V_89 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_49 ,
{ L_23 , L_24 , V_95 ,
V_93 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_54 ,
{ L_23 , L_25 , V_96 ,
V_93 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_60 ,
{ L_14 , L_26 , V_89 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
#if 0
{ &hf_ppcap_destination_address_type,
{ "Destination Address Type", "ppcap.destination_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00, NULL, HFILL}},
#endif
{ & V_62 ,
{ L_18 , L_27 , V_97 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_63 ,
{ L_28 , L_29 , V_98 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_66 ,
{ L_28 , L_30 , V_99 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_67 ,
{ L_31 , L_32 , V_95 ,
V_93 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_69 ,
{ L_31 , L_33 , V_96 ,
V_93 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_56 ,
{ L_34 , L_35 , V_92 ,
V_93 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_70 ,
{ L_36 , L_37 , V_92 ,
V_93 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_71 ,
{ L_38 , L_39 , V_92 ,
V_93 , NULL , 0x0000 , NULL , V_91 } } ,
{ & V_76 ,
{ L_40 , L_41 , V_100 ,
V_93 , NULL , 0x0000 , NULL , V_91 } } ,
{ & V_72 ,
{ L_42 , L_43 , V_89 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_73 ,
{ L_44 , L_45 , V_89 ,
V_90 , NULL , 0x00 , NULL , V_91 } } ,
{ & V_74 ,
{ L_46 , L_47 , V_92 ,
V_93 , NULL , 0x0 , NULL , V_91 } } ,
} ;
static T_9 * V_101 [] = {
& V_16 ,
& V_17 ,
& V_102 ,
} ;
V_14 = F_37 ( L_48 , L_1 , L_49 ) ;
F_38 ( V_14 , V_88 , F_39 ( V_88 ) ) ;
F_40 ( V_101 , F_39 ( V_101 ) ) ;
F_41 ( L_49 , F_1 , V_14 ) ;
V_87 = F_42 ( V_14 , V_103 ) ;
F_43 ( V_87 , L_50 , L_51 , L_52 , & V_19 , V_104 , TRUE ) ;
}
void V_103 ( void )
{
V_105 = F_44 ( L_49 ) ;
V_77 = F_44 ( L_3 ) ;
V_80 = F_44 ( L_4 ) ;
V_81 = F_44 ( L_5 ) ;
V_82 = F_44 ( L_6 ) ;
V_83 = F_44 ( L_7 ) ;
V_84 = F_44 ( L_8 ) ;
V_85 = F_44 ( L_9 ) ;
V_86 = F_44 ( L_53 ) ;
V_79 = F_45 ( L_54 ) ;
}
