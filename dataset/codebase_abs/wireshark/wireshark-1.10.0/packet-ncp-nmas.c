static int
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , int V_4 , T_3 V_5 )
{
int V_6 = V_4 ;
T_4 V_7 ;
char * V_8 ;
T_4 V_9 ;
T_5 V_10 ;
T_4 V_11 = 0 ;
V_8 = ( char * ) F_2 ( V_12 + 1 ) ;
if ( V_5 ) {
V_7 = F_3 ( V_1 , V_6 ) ;
}
else
{
V_7 = F_4 ( V_1 , V_6 ) ;
}
V_6 += 4 ;
if( V_7 >= V_12 )
{
F_5 ( V_3 , V_2 , V_1 , V_6 ,
V_11 + 4 , L_1 ) ;
V_6 += V_11 ;
return V_6 ;
}
if( V_7 == 0 )
{
F_5 ( V_3 , V_2 , V_1 , V_4 ,
4 , L_2 ) ;
return V_6 ;
}
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ )
{
V_10 = F_6 ( V_1 , V_6 ) ;
if ( V_10 < 0x20 || V_10 > 0x7e )
{
if ( V_10 != 0x00 )
{
V_10 = 0x2e ;
V_8 [ V_9 ] = V_10 & 0xff ;
}
else
{
V_9 -- ;
V_7 -- ;
}
}
else
{
V_8 [ V_9 ] = V_10 & 0xff ;
}
V_6 ++ ;
V_11 -- ;
if( V_11 == 1 )
{
V_9 ++ ;
break;
}
}
V_8 [ V_9 ] = '\0' ;
if ( V_5 ) {
V_7 = F_3 ( V_1 , V_4 ) ;
}
else
{
V_7 = F_4 ( V_1 , V_4 ) ;
}
F_5 ( V_3 , V_2 , V_1 , V_4 + 4 ,
V_7 , V_8 ) ;
return V_6 ;
}
void
F_7 ( T_1 * V_1 , T_6 * V_13 , T_2 * V_14 , T_7 * V_15 )
{
T_8 V_16 ;
T_4 V_17 = 0 , V_18 = 0 ;
T_4 V_6 ;
T_4 V_19 = 0 ;
T_4 V_20 = 0 ;
T_8 V_21 = 0 ;
T_2 * V_22 ;
T_9 * V_23 ;
V_6 = 6 ;
V_6 += 1 ;
V_16 = F_6 ( V_1 , V_6 ) ;
V_6 += 1 ;
F_8 ( V_13 -> V_24 , V_25 , L_3 ) ;
if ( F_9 ( V_13 -> V_24 , V_26 ) ) {
F_10 ( V_13 -> V_24 , V_26 , L_4 ,
F_11 ( V_16 , V_27 , L_5 ) ) ;
}
V_23 = F_12 ( V_14 , V_1 , V_6 , - 1 , L_6 ,
F_11 ( V_16 , V_27 , L_5 ) ) ;
V_22 = F_13 ( V_23 , V_28 ) ;
switch ( V_16 ) {
case 1 :
F_14 ( V_22 , V_29 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_31 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
break;
case 2 :
F_14 ( V_22 , V_32 , V_1 , V_6 , 4 , V_30 ) ;
if ( F_3 ( V_1 , V_6 ) != 0xffffffff ) {
break;
}
V_6 += 4 ;
V_6 += 4 ;
F_14 ( V_22 , V_33 , V_1 , V_6 , 4 , V_30 ) ;
V_17 = F_3 ( V_1 , V_6 ) ;
V_6 += 4 ;
V_6 += 12 ;
V_17 -= 16 ;
F_14 ( V_22 , V_34 , V_1 , V_6 , 4 , V_30 ) ;
V_19 = F_3 ( V_1 , V_6 ) ;
if ( V_15 ) {
V_15 -> V_35 = V_19 ;
}
V_6 += 4 ;
V_17 -= 4 ;
if ( F_9 ( V_13 -> V_24 , V_26 ) ) {
F_15 ( V_13 -> V_24 , V_26 , L_7 ,
F_11 ( V_19 , V_36 , L_8 ) ) ;
}
switch ( V_19 ) {
case 0 :
F_14 ( V_22 , V_29 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_31 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
break;
case 2 :
F_14 ( V_22 , V_37 , V_1 , V_6 , V_17 , V_38 ) ;
V_6 += V_17 ;
break;
case 4 :
case 6 :
break;
case 8 :
F_14 ( V_22 , V_39 , V_1 , V_6 , 1 , V_30 ) ;
V_6 += 4 ;
V_21 = F_6 ( V_1 , V_6 ) ;
if ( V_15 ) {
V_15 -> V_40 = V_21 ;
}
F_14 ( V_22 , V_41 , V_1 , V_6 , 1 , V_30 ) ;
V_6 += 4 ;
if ( F_9 ( V_13 -> V_24 , V_26 ) ) {
F_15 ( V_13 -> V_24 , V_26 , L_7 ,
F_11 ( V_21 , V_42 , L_9 ) ) ;
}
switch ( V_21 )
{
case 1 :
break;
case 2 :
break;
case 4 :
break;
case 5 :
break;
case 6 :
break;
default:
break;
}
break;
case 10 :
V_6 += 4 ;
V_6 += 8 ;
V_6 = F_1 ( V_1 , V_43 , V_22 , V_6 , TRUE ) ;
V_6 = F_1 ( V_1 , V_44 , V_22 , V_6 , TRUE ) ;
break;
case 1242 :
V_6 += 4 ;
F_14 ( V_22 , V_45 , V_1 , V_6 , 4 , V_46 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_47 , V_1 , V_6 , 4 , V_46 ) ;
V_6 += 4 ;
V_6 += 3 ;
V_21 = F_6 ( V_1 , V_6 ) ;
if ( V_15 ) {
V_15 -> V_40 = V_21 ;
}
F_14 ( V_22 , V_48 , V_1 , V_6 , 1 , V_46 ) ;
V_6 += 1 ;
V_17 -= 12 ;
if ( F_9 ( V_13 -> V_24 , V_26 ) ) {
F_15 ( V_13 -> V_24 , V_26 , L_7 ,
F_11 ( V_21 , V_49 , L_9 ) ) ;
}
switch( V_21 )
{
case 1 :
V_17 = F_4 ( V_1 , V_6 ) ;
F_14 ( V_22 , V_33 , V_1 , V_6 , 4 , V_46 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_50 , V_1 , V_6 , V_17 , V_38 ) ;
V_6 += V_17 ;
break;
case 3 :
V_17 = F_4 ( V_1 , V_6 ) ;
V_17 -= 4 ;
F_14 ( V_22 , V_33 , V_1 , V_6 , 4 , V_46 ) ;
V_6 += 4 ;
while ( V_17 > 0 )
{
V_20 = F_4 ( V_1 , V_6 ) ;
V_6 += 4 ;
V_18 = F_4 ( V_1 , V_6 ) ;
switch ( V_20 ) {
case 1 :
V_6 = F_1 ( V_1 , V_44 , V_22 , V_6 , FALSE ) ;
break;
case 2 :
V_6 = F_1 ( V_1 , V_43 , V_22 , V_6 , FALSE ) ;
break;
case 4 :
V_6 = F_1 ( V_1 , V_51 , V_22 , V_6 , FALSE ) ;
break;
case 11 :
V_6 = F_1 ( V_1 , V_52 , V_22 , V_6 , FALSE ) ;
break;
default:
break;
}
V_17 -= V_18 ;
if ( F_16 ( V_1 , V_6 ) < 5 )
{
break;
}
}
break;
case 5 :
F_14 ( V_22 , V_37 , V_1 , V_6 , F_16 ( V_1 , V_6 ) , V_38 ) ;
V_6 += V_17 ;
break;
case 7 :
case 9 :
break;
default:
break;
}
break;
default:
break;
}
break;
case 3 :
break;
default:
break;
}
}
void
F_17 ( T_1 * V_1 , T_6 * V_13 , T_2 * V_14 , T_8 T_10 V_53 , T_8 V_16 , T_7 * V_15 )
{
T_4 V_6 = 0 , V_54 = 0 ;
T_4 V_19 = 0 ;
T_8 V_21 = 0 ;
T_4 V_17 = 0 ;
T_4 V_55 = 0 , V_56 = 0 ;
T_2 * V_22 ;
T_9 * V_23 ;
T_9 * V_57 ;
const T_11 * V_58 ;
V_6 = 8 ;
if ( V_15 ) {
V_19 = V_15 -> V_35 ;
V_21 = V_15 -> V_40 ;
}
F_8 ( V_13 -> V_24 , V_25 , L_3 ) ;
if ( F_16 ( V_1 , V_6 ) < 4 ) {
return;
}
V_23 = F_12 ( V_14 , V_1 , V_6 , - 1 , L_6 ,
F_11 ( V_16 , V_27 , L_5 ) ) ;
V_22 = F_13 ( V_23 , V_28 ) ;
switch ( V_16 ) {
case 1 :
F_14 ( V_22 , V_31 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_59 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
break;
case 2 :
F_12 ( V_22 , V_1 , V_6 , - 1 , L_10 ,
F_11 ( V_19 , V_36 , L_9 ) ) ;
F_14 ( V_22 , V_33 , V_1 , V_6 , 4 , V_30 ) ;
V_17 = F_3 ( V_1 , V_6 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_32 , V_1 , V_6 , 4 , V_30 ) ;
if ( F_3 ( V_1 , V_6 ) != 0xffffffff ) {
break;
}
V_6 += 4 ;
V_55 = F_3 ( V_1 , V_6 ) ;
V_54 = V_6 ;
V_6 += 4 ;
V_17 -= 8 ;
if ( V_55 == 0 && V_17 > 0 )
{
switch ( V_19 ) {
case 0 :
F_14 ( V_22 , V_47 , V_1 , V_6 , 4 , V_46 ) ;
V_6 += 4 ;
break;
case 2 :
F_14 ( V_22 , V_60 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_61 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
break;
case 4 :
F_14 ( V_22 , V_37 , V_1 , V_6 , V_17 , V_38 ) ;
V_6 += V_17 ;
break;
case 6 :
F_14 ( V_22 , V_62 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_63 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_64 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
V_17 -= 12 ;
F_14 ( V_22 , V_65 , V_1 , V_6 , V_17 , V_38 ) ;
V_6 += V_17 ;
break;
case 8 :
F_12 ( V_22 , V_1 , V_6 , - 1 , L_11 ,
F_11 ( V_21 , V_42 , L_9 ) ) ;
switch( V_21 )
{
case 1 :
case 3 :
case 5 :
case 7 :
case 9 :
F_14 ( V_22 , V_66 , V_1 , V_6 , V_17 , V_38 ) ;
V_6 += V_17 ;
break;
default:
break;
}
break;
case 10 :
F_14 ( V_22 , V_59 , V_1 , V_6 , 4 , V_30 ) ;
V_6 += 4 ;
break;
case 1242 :
F_12 ( V_22 , V_1 , V_6 , - 1 , L_11 ,
F_11 ( V_21 , V_49 , L_9 ) ) ;
switch( V_21 )
{
case 1 :
V_17 = F_4 ( V_1 , V_6 ) ;
F_14 ( V_22 , V_33 , V_1 , V_6 , 4 , V_46 ) ;
V_6 += 4 ;
F_14 ( V_22 , V_50 , V_1 , V_6 , V_17 , V_38 ) ;
V_6 += V_17 ;
break;
case 3 :
F_14 ( V_22 , V_47 , V_1 , V_6 , 4 , V_46 ) ;
V_6 += 4 ;
break;
case 5 :
break;
case 7 :
V_56 = F_4 ( V_1 , V_6 ) ;
V_58 = F_18 ( V_56 , V_67 ) ;
if ( V_58 )
{
F_10 ( V_13 -> V_24 , V_26 , L_12 , V_58 ) ;
V_57 = F_14 ( V_22 , V_68 , V_1 , V_6 , 4 , V_46 ) ;
F_19 ( V_13 , V_57 , V_69 , V_70 , L_13 , V_58 ) ;
}
else
{
F_14 ( V_22 , V_37 , V_1 , V_6 , V_17 , V_38 ) ;
}
V_6 += V_17 ;
break;
case 9 :
break;
default:
break;
}
break;
default:
break;
}
}
V_58 = F_18 ( V_55 , V_67 ) ;
if ( V_58 )
{
V_57 = F_14 ( V_22 , V_71 , V_1 , V_54 , 4 , V_30 ) ;
F_19 ( V_13 , V_57 , V_69 , V_70 , L_14 , V_55 , V_58 ) ;
F_10 ( V_13 -> V_24 , V_26 , L_15 , V_58 ) ;
}
else
{
if ( V_55 != 0 )
{
V_57 = F_14 ( V_22 , V_71 , V_1 , V_54 , 4 , V_30 ) ;
F_19 ( V_13 , V_57 , V_69 , V_70 , L_16 , V_55 ) ;
if ( F_9 ( V_13 -> V_24 , V_26 ) ) {
F_10 ( V_13 -> V_24 , V_26 , L_17 , V_55 ) ;
}
}
}
if ( V_55 == 0 ) {
F_12 ( V_22 , V_1 , V_54 , 4 , L_18 ) ;
}
break;
case 3 :
break;
default:
break;
}
}
void
F_20 ( void )
{
static T_12 V_72 [] = {
#if 0
{ &hf_func,
{ "Function", "nmas.func", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
#endif
#if 0
{ &hf_subfunc,
{ "Subfunction", "nmas.subfunc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
#endif
{ & V_29 ,
{ L_19 , L_20 , V_73 , V_74 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_31 ,
{ L_21 , L_22 , V_73 , V_74 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_32 ,
{ L_23 , L_24 , V_73 , V_74 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_33 ,
{ L_25 , L_26 , V_73 , V_76 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_34 ,
{ L_27 , L_28 ,
V_73 , V_74 , F_21 ( V_36 ) , 0x0 ,
NULL , V_75 } } ,
{ & V_43 ,
{ L_29 , L_30 ,
V_77 , V_78 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_44 ,
{ L_31 , L_32 ,
V_77 , V_78 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_59 ,
{ L_33 , L_34 , V_73 , V_74 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_45 ,
{ L_35 , L_36 , V_73 , V_74 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_47 ,
{ L_37 , L_38 , V_73 , V_74 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_48 ,
{ L_39 , L_40 , V_79 , V_74 , F_21 ( V_49 ) , 0x0 ,
NULL , V_75 } } ,
#if 0
{ &hf_attribute,
{ "Attribute Type", "nmas.attribute", FT_UINT32, BASE_DEC, VALS(nmas_attribute_enum), 0x0,
NULL, HFILL }},
#endif
{ & V_51 ,
{ L_41 , L_42 ,
V_77 , V_78 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_52 ,
{ L_43 , L_44 ,
V_77 , V_78 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_37 ,
{ L_45 , L_46 ,
V_80 , V_78 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_50 ,
{ L_47 , L_48 ,
V_80 , V_78 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_71 ,
{ L_49 , L_50 , V_73 , V_74 , F_21 ( V_67 ) , 0x0 ,
NULL , V_75 } } ,
{ & V_41 ,
{ L_51 , L_52 , V_79 , V_74 , F_21 ( V_42 ) , 0x0 ,
NULL , V_75 } } ,
{ & V_60 ,
{ L_53 , L_54 , V_73 , V_76 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_61 ,
{ L_55 , L_56 , V_73 , V_76 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_62 ,
{ L_57 , L_58 , V_73 , V_76 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_63 ,
{ L_59 , L_60 , V_73 , V_76 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_64 ,
{ L_61 , L_62 , V_73 , V_76 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_65 ,
{ L_63 , L_64 ,
V_80 , V_78 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_66 ,
{ L_65 , L_66 ,
V_80 , V_78 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_39 ,
{ L_67 , L_68 , V_73 , V_76 , NULL , 0x0 ,
NULL , V_75 } } ,
{ & V_68 ,
{ L_69 , L_70 , V_73 , V_74 , F_21 ( V_67 ) , 0x0 ,
L_71 , V_75 } } ,
} ;
static T_13 * V_81 [] = {
& V_28 ,
} ;
V_82 = F_22 ( L_72 , L_3 , L_73 ) ;
F_23 ( V_82 , V_72 , F_24 ( V_72 ) ) ;
F_25 ( V_81 , F_24 ( V_81 ) ) ;
}
