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
T_2 * V_34 ;
V_31 = F_2 ( V_1 , V_2 ) ;
V_32 = 4 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
V_32 += ( 4 + F_2 ( V_1 , V_2 + V_32 ) ) ;
}
V_34 = F_7 ( V_3 , V_1 , V_2 , V_32 ,
V_35 , NULL , L_1 ) ;
V_2 = F_3 ( V_1 , V_34 ,
V_36 , V_2 ) ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
V_2 = F_8 ( V_1 , V_34 ,
V_37 , V_2 ) ;
}
return V_2 ;
}
static int
F_9 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
V_2 = F_8 ( V_1 , V_3 , V_38 ,
V_2 ) ;
V_2 = F_8 ( V_1 , V_3 , V_37 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_39 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_40 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_41 , V_2 ) ;
return V_2 ;
}
static int
F_10 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_11 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
V_2 = F_8 ( V_1 , V_3 , V_38 ,
V_2 ) ;
V_2 = F_8 ( V_1 , V_3 , V_37 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_39 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_40 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_41 , V_2 ) ;
return V_2 ;
}
static int
F_12 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_13 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
V_2 = F_8 ( V_1 , V_3 , V_38 ,
V_2 ) ;
V_2 = F_8 ( V_1 , V_3 , V_37 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_39 , V_2 ) ;
return V_2 ;
}
static int
F_14 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_15 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
V_2 = F_8 ( V_1 , V_3 , V_38 ,
V_2 ) ;
V_2 = F_8 ( V_1 , V_3 , V_37 , V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_39 , V_2 ) ;
V_2 = F_16 ( V_1 , V_3 , V_42 , V_2 ) ;
return V_2 ;
}
static int
F_17 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_18 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 , T_2 * V_3 , void * T_6 V_30 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
if ( V_4 == 0 ) {
V_2 = F_8 ( V_1 , V_3 ,
V_38 , V_2 ) ;
V_2 = F_8 ( V_1 , V_3 , V_37 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_39 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_43 ,
V_2 ) ;
V_2 = F_19 ( V_1 , V_2 , T_5 , V_3 ) ;
}
return V_2 ;
}
static int
F_20 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_21 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
V_2 = F_8 ( V_1 , V_3 , V_38 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_3 , V_44 , V_2 ) ;
return V_2 ;
}
static int
F_22 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_23 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 ,
T_2 * V_3 , void * T_6 V_30 )
{
V_2 = F_8 ( V_1 , V_3 , V_38 ,
V_2 ) ;
V_2 = F_4 ( V_1 , V_2 , V_3 ) ;
V_2 = F_6 ( V_1 , V_2 , T_5 , V_3 ) ;
return V_2 ;
}
static int
F_24 ( T_1 * V_1 , int V_2 ,
T_4 * T_5 V_30 , T_2 * V_3 , void * T_6 V_30 )
{
int V_4 ;
V_2 = F_1 ( V_1 , V_2 , V_3 , & V_4 ) ;
return V_2 ;
}
static int
F_25 ( T_1 * V_1 , int V_2 , T_2 * V_3 )
{
V_2 = F_3 ( V_1 , V_3 , V_45 ,
V_2 ) ;
return V_2 ;
}
static int
F_26 ( T_1 * V_1 , int V_2 , T_4 * T_5 V_30 ,
T_2 * V_3 , T_7 V_46 )
{
T_2 * V_47 ;
V_47 = F_27 ( V_3 , V_1 , V_2 , 20 ,
V_48 , NULL , L_2 , ( T_7 ) V_46 ) ;
V_2 = F_3 ( V_1 , V_47 , V_40 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_47 , V_49 ,
V_2 ) ;
V_2 = F_3 ( V_1 , V_47 , V_50 , V_2 ) ;
V_2 = F_3 ( V_1 , V_47 , V_51 ,
V_2 ) ;
V_2 = F_25 ( V_1 , V_2 , V_47 ) ;
return V_2 ;
}
static int
F_19 ( T_1 * V_1 , int V_2 , T_4 * T_5 V_30 ,
T_2 * V_3 )
{
T_7 V_52 ;
T_7 V_53 ;
T_2 * V_54 ;
T_7 V_33 ;
V_52 = F_2 ( V_1 , V_2 ) ;
V_53 = 4 + ( 20 * V_52 ) ;
V_54 = F_7 ( V_3 , V_1 , V_2 , V_53 ,
V_55 , NULL , L_3 ) ;
V_2 = F_3 ( V_1 , V_54 ,
V_56 , V_2 ) ;
for ( V_33 = 0 ; V_33 < V_52 ; V_33 ++ ) {
V_2 = F_26 ( V_1 , V_2 , T_5 , V_54 , V_33 + 1 ) ;
}
return V_2 ;
}
void
F_28 ( void )
{
static T_8 V_57 [] = {
{ & V_58 , {
L_4 , L_5 , V_59 , V_60 ,
F_29 ( V_61 ) , 0 , NULL , V_62 } } ,
{ & V_27 , {
L_6 , L_7 , V_59 , V_60 ,
F_29 ( V_63 ) , 0 , L_8 , V_62 } } ,
{ & V_56 , {
L_9 , L_10 ,
V_59 , V_60 , NULL , 0 , NULL , V_62 } } ,
{ & V_49 , {
L_11 , L_12 , V_59 ,
V_60 , NULL , 0 , NULL , V_62 } } ,
{ & V_50 , {
L_13 , L_14 , V_59 ,
V_60 , NULL , 0 , NULL , V_62 } } ,
{ & V_51 , {
L_15 , L_16 , V_59 ,
V_60 , NULL , 0 , NULL , V_62 } } ,
{ & V_45 , {
L_17 , L_18 , V_59 ,
V_60 , NULL , 0 , NULL , V_62 } } ,
{ & V_36 , {
L_19 , L_20 ,
V_59 , V_60 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_38 , {
L_21 , L_22 , V_64 , V_65 ,
NULL , 0 , NULL , V_62 } } ,
{ & V_44 , {
L_23 , L_24 , V_59 , V_66 ,
NULL , 0 , NULL , V_62 } } ,
#if 0
{ &hf_fmp_fsBlkSz, {
"FS Block Size", "fmp_notify.fsBlkSz", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
#endif
{ & V_41 , {
L_25 , L_26 , V_59 ,
V_60 , NULL , 0 , NULL , V_62 } } ,
{ & V_39 , {
L_27 , L_28 , V_59 , V_60 ,
NULL , 0 , NULL , V_62 } } ,
{ & V_43 , {
L_29 , L_30 , V_59 , V_66 ,
NULL , 0 , L_31 , V_62 } } ,
{ & V_40 , {
L_32 , L_33 , V_59 ,
V_60 , NULL , 0 , L_34 , V_62 } } ,
{ & V_42 , {
L_35 , L_36 , V_67 , V_60 ,
NULL , 0 , NULL , V_62 } } ,
{ & V_37 , {
L_37 , L_38 ,
V_64 , V_65 , NULL , 0 , NULL ,
V_62 } } ,
{ & V_28 ,
{ L_39 , L_40 ,
V_59 , V_60 , F_29 ( V_68 ) , 0 ,
NULL , V_62 } } ,
} ;
static T_9 * V_69 [] = {
& V_70 ,
& V_35 ,
& V_55 ,
& V_48
} ;
V_71 =
F_30 ( L_41 ,
L_42 , L_43 ) ;
F_31 ( V_71 , V_57 , F_32 ( V_57 ) ) ;
F_33 ( V_69 , F_32 ( V_69 ) ) ;
}
void
F_34 ( void )
{
F_35 ( V_71 , V_72 , V_70 ) ;
F_36 ( V_72 , V_73 ,
V_74 , V_58 ) ;
}
