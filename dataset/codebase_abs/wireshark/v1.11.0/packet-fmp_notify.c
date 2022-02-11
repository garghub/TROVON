static int
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , int * V_4 )
{
T_3 V_5 ;
V_5 = ( T_3 ) F_2 ( V_1 , V_2 ) ;
switch ( V_5 ) {
case V_6 :
* V_4 = 0 ;
break;
case V_7 :
* V_4 = 1 ;
break;
case V_8 :
* V_4 = 1 ;
break;
case V_9 :
* V_4 = 1 ;
break;
case V_10 :
* V_4 = 1 ;
break;
case V_11 :
* V_4 = 0 ;
break;
case V_12 :
* V_4 = 1 ;
break;
case V_13 :
* V_4 = 1 ;
break;
case V_14 :
* V_4 = 1 ;
break;
case V_15 :
* V_4 = 0 ;
break;
case V_16 :
* V_4 = 0 ;
break;
case V_17 :
* V_4 = 0 ;
break;
case V_18 :
* V_4 = 1 ;
break;
case V_19 :
* V_4 = 0 ;
break;
case V_20 :
* V_4 = 0 ;
break;
case V_21 :
* V_4 = 1 ;
break;
case V_22 :
* V_4 = 0 ;
break;
case V_23 :
* V_4 = 1 ;
break;
case V_24 :
* V_4 = 0 ;
break;
case V_25 :
* V_4 = 1 ;
break;
case V_26 :
* V_4 = 1 ;
break;
default:
* V_4 = 1 ;
break;
}
V_2 = F_3 ( V_1 , V_3 , V_27 , V_2 ) ;
return V_2 ;
}
static int
F_4 ( T_1 * V_1 , int V_2 , T_2 * V_3 )
{
F_5 ( V_3 , V_28 , V_1 , V_2 , 4 , V_29 ) ;
V_2 += 4 ;
return V_2 ;
}
static int
F_6 ( T_1 * V_1 , int V_2 , T_4 * T_5 V_30 ,
T_2 * V_3 )
{
int V_31 ;
int V_32 ;
int V_33 ;
T_6 * V_34 ;
T_2 * V_35 ;
V_31 = F_2 ( V_1 , V_2 ) ;
V_32 = 4 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
V_32 += ( 4 + F_2 ( V_1 , V_2 + V_32 ) ) ;
}
V_34 = F_7 ( V_3 , V_1 , V_2 , V_32 ,
L_1 ) ;
V_35 = F_8 ( V_34 ,
V_36 ) ;
V_2 = F_3 ( V_1 , V_35 ,
V_37 , V_2 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
V_2 = F_9 ( V_1 , V_35 ,
V_38 , V_2 ) ;
}
return V_2 ;
}
static int
F_10 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
V_2 = F_9 ( V_1 , V_3 , V_39 ,
V_2 ) ;
V_2 = F_9 ( V_1 , V_3 , V_38 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_40 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_41 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_42 , V_2 ) ;
return V_2 ;
}
static int
F_11 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_12 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
V_2 = F_9 ( V_1 , V_3 , V_39 ,
V_2 ) ;
V_2 = F_9 ( V_1 , V_3 , V_38 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_40 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_41 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_42 , V_2 ) ;
return V_2 ;
}
static int
F_13 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_14 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
V_2 = F_9 ( V_1 , V_3 , V_39 ,
V_2 ) ;
V_2 = F_9 ( V_1 , V_3 , V_38 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_40 , V_2 ) ;
return V_2 ;
}
static int
F_15 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_16 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
V_2 = F_9 ( V_1 , V_3 , V_39 ,
V_2 ) ;
V_2 = F_9 ( V_1 , V_3 , V_38 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_40 , V_2 ) ;
V_2 = F_17 ( V_1 , V_3 , V_43 , V_2 ) ;
return V_2 ;
}
static int
F_18 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_19 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 , T_2 * V_3 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
if ( V_4 == 0 ) {
V_2 = F_9 ( V_1 , V_3 ,
V_39 , V_2 ) ;
V_2 = F_9 ( V_1 , V_3 , V_38 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_40 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_44 ,
V_2 ) ;
V_2 = F_20 ( V_1 , V_2 , T_5 , V_3 ) ;
}
return V_2 ;
}
static int
F_21 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_22 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
V_2 = F_9 ( V_1 , V_3 , V_39 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_45 , V_2 ) ;
return V_2 ;
}
static int
F_23 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_24 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 ,
T_2 * V_3 )
{
V_2 = F_9 ( V_1 , V_3 , V_39 ,
V_2 ) ;
V_2 = F_4 ( V_1 , V_2 , V_3 ) ;
V_2 = F_6 ( V_1 , V_2 , T_5 , V_3 ) ;
return V_2 ;
}
static int
F_25 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_26 ( T_1 * V_1 , int V_2 , T_2 * V_3 )
{
V_2 = F_3 ( V_1 , V_3 , V_46 ,
V_2 ) ;
return V_2 ;
}
static int
F_27 ( T_1 * V_1 , int V_2 , T_4 * T_5 V_30 ,
T_2 * V_3 , T_7 V_47 )
{
T_6 * V_48 ;
T_2 * V_49 ;
V_48 = F_7 ( V_3 , V_1 , V_2 , 20 ,
L_2 , ( T_7 ) V_47 ) ;
V_49 = F_8 ( V_48 , V_50 ) ;
V_2 = F_3 ( V_1 , V_49 , V_41 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_49 , V_51 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_49 , V_52 , V_2 ) ;
V_2 = F_3 ( V_1 , V_49 , V_53 ,
V_2 ) ;
V_2 = F_26 ( V_1 , V_2 , V_49 ) ;
return V_2 ;
}
static int
F_20 ( T_1 * V_1 , int V_2 , T_4 * T_5 V_30 ,
T_2 * V_3 )
{
T_7 V_54 ;
T_7 V_55 ;
T_6 * V_56 ;
T_2 * V_57 ;
T_7 V_33 ;
V_54 = F_2 ( V_1 , V_2 ) ;
V_55 = 4 + ( 20 * V_54 ) ;
V_56 = F_7 ( V_3 , V_1 , V_2 , V_55 ,
L_3 ) ;
V_57 = F_8 ( V_56 , V_58 ) ;
V_2 = F_3 ( V_1 , V_57 ,
V_59 , V_2 ) ;
for ( V_33 = 0 ; V_33 < V_54 ; V_33 ++ ) {
V_2 = F_27 ( V_1 , V_2 , T_5 , V_57 , V_33 + 1 ) ;
}
return V_2 ;
}
void
F_28 ( void )
{
static T_8 V_60 [] = {
{ & V_61 , {
L_4 , L_5 , V_62 , V_63 ,
F_29 ( V_64 ) , 0 , NULL , V_65 } } ,
{ & V_27 , {
L_6 , L_7 , V_62 , V_63 ,
F_29 ( V_66 ) , 0 , L_8 , V_65 } } ,
{ & V_59 , {
L_9 , L_10 ,
V_62 , V_63 , NULL , 0 , NULL , V_65 } } ,
{ & V_51 , {
L_11 , L_12 , V_62 ,
V_63 , NULL , 0 , NULL , V_65 } } ,
{ & V_52 , {
L_13 , L_14 , V_62 ,
V_63 , NULL , 0 , NULL , V_65 } } ,
{ & V_53 , {
L_15 , L_16 , V_62 ,
V_63 , NULL , 0 , NULL , V_65 } } ,
{ & V_46 , {
L_17 , L_18 , V_62 ,
V_63 , NULL , 0 , NULL , V_65 } } ,
{ & V_37 , {
L_19 , L_20 ,
V_62 , V_63 , NULL , 0 ,
NULL , V_65 } } ,
{ & V_39 , {
L_21 , L_22 , V_67 , V_68 ,
NULL , 0 , NULL , V_65 } } ,
{ & V_45 , {
L_23 , L_24 , V_62 , V_69 ,
NULL , 0 , NULL , V_65 } } ,
#if 0
{ &hf_fmp_fsBlkSz, {
"FS Block Size", "fmp_notify.fsBlkSz", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
#endif
{ & V_42 , {
L_25 , L_26 , V_62 ,
V_63 , NULL , 0 , NULL , V_65 } } ,
{ & V_40 , {
L_27 , L_28 , V_62 , V_63 ,
NULL , 0 , NULL , V_65 } } ,
{ & V_44 , {
L_29 , L_30 , V_62 , V_69 ,
NULL , 0 , L_31 , V_65 } } ,
{ & V_41 , {
L_32 , L_33 , V_62 ,
V_63 , NULL , 0 , L_34 , V_65 } } ,
{ & V_43 , {
L_35 , L_36 , V_70 , V_63 ,
NULL , 0 , NULL , V_65 } } ,
{ & V_38 , {
L_37 , L_38 ,
V_67 , V_68 , NULL , 0 , NULL ,
V_65 } } ,
{ & V_28 ,
{ L_39 , L_40 ,
V_62 , V_63 , F_29 ( V_71 ) , 0 ,
NULL , V_65 } } ,
} ;
static T_9 * V_72 [] = {
& V_73 ,
& V_36 ,
& V_58 ,
& V_50
} ;
V_74 =
F_30 ( L_41 ,
L_42 , L_43 ) ;
F_31 ( V_74 , V_60 , F_32 ( V_60 ) ) ;
F_33 ( V_72 , F_32 ( V_72 ) ) ;
}
void
F_34 ( void )
{
F_35 ( V_74 , V_75 , V_73 ) ;
F_36 ( V_75 , V_76 ,
V_77 , V_61 ) ;
}
