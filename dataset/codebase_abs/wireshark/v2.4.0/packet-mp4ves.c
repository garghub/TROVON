static int
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int V_4 )
{
int V_5 ;
F_2 ( V_3 , V_6 , V_1 , V_4 , 24 , V_7 ) ;
V_4 += 24 ;
F_2 ( V_3 , V_8 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
V_5 = V_4 ;
while ( F_3 ( V_1 , V_4 , 24 , V_7 ) != 1 ) {
V_4 += 8 ;
}
F_4 ( V_3 , V_9 , V_1 , V_5 >> 3 , ( V_4 - V_5 ) >> 2 , V_10 ) ;
return V_4 ;
}
static int
F_5 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int V_4 )
{
T_5 V_11 ;
int V_5 ;
V_5 = V_4 ;
V_11 = F_6 ( V_1 , V_4 , 1 ) ;
if ( V_11 != 0 ) {
}
V_4 ++ ;
if( V_4 % 8 == 0 )
return V_4 ;
while( V_4 % 8 != 0 ) {
V_4 ++ ;
}
F_2 ( V_3 , V_12 , V_1 , V_5 , V_4 - V_5 , V_7 ) ;
return V_4 ;
}
static int
F_7 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int V_4 )
{
T_5 V_13 , V_14 ;
V_13 = F_6 ( V_1 , V_4 , 1 ) ;
F_2 ( V_3 , V_15 , V_1 , V_4 , 1 , V_7 ) ;
V_4 ++ ;
if ( V_13 ) {
V_4 += 3 ;
V_4 ++ ;
V_14 = F_6 ( V_1 , V_4 , 1 ) ;
if ( V_14 ) {
V_4 += 8 ;
V_4 += 8 ;
V_4 += 8 ;
}
}
return V_4 ;
}
static int
F_8 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , int V_4 )
{
T_6 V_16 ;
int V_17 ;
T_5 V_18 , V_19 , V_20 , V_21 , V_22 ;
T_5 V_23 , V_24 = 0 ;
V_16 = F_3 ( V_1 , V_4 , 24 , V_7 ) ;
if ( V_16 != 1 ) {
return V_4 ;
}
V_18 = F_6 ( V_1 , V_4 + 24 , 8 ) ;
if( ( V_18 >= 0x20 ) && ( V_18 <= 0x2f ) ) {
} else{
return V_4 ;
}
F_2 ( V_3 , V_6 , V_1 , V_4 , 24 , V_7 ) ;
V_4 += 24 ;
F_2 ( V_3 , V_8 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
F_2 ( V_3 , V_25 , V_1 , V_4 , 1 , V_7 ) ;
V_4 ++ ;
F_2 ( V_3 , V_26 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
V_19 = F_6 ( V_1 , V_4 , 1 ) ;
F_2 ( V_3 , V_27 , V_1 , V_4 , 1 , V_7 ) ;
V_4 ++ ;
if( V_19 ) {
V_4 += 4 ;
V_4 += 3 ;
}
V_20 = F_6 ( V_1 , V_4 , 1 ) ;
F_2 ( V_3 , V_28 , V_1 , V_4 , 4 , V_7 ) ;
if ( V_20 == 0xf ) {
V_4 += 8 ;
V_4 += 8 ;
}
V_21 = F_6 ( V_1 , V_4 , 1 ) ;
F_2 ( V_3 , V_29 , V_1 , V_4 , 1 , V_7 ) ;
V_4 ++ ;
V_17 = V_4 ;
if ( V_21 ) {
V_4 += 2 ;
V_4 ++ ;
V_22 = F_6 ( V_1 , V_4 , 1 ) ;
V_4 ++ ;
if ( V_22 ) {
V_4 += 15 ;
V_4 ++ ;
V_4 += 15 ;
V_4 ++ ;
V_4 += 15 ;
V_4 ++ ;
V_4 += 3 ;
V_4 += 11 ;
V_4 ++ ;
V_4 += 15 ;
V_4 ++ ;
}
}
if( V_4 - V_17 > 0 )
F_9 ( V_3 , T_3 , & V_30 , V_1 , V_17 >> 3 , ( V_4 + 7 ) >> 3 ) ;
V_23 = F_6 ( V_1 , V_4 , 2 ) ;
F_2 ( V_3 , V_31 , V_1 , V_4 , 2 , V_7 ) ;
V_4 += 2 ;
if ( V_23 == 3 && V_24 != 1 ) {
V_4 += 4 ;
}
V_4 ++ ;
V_4 += 16 ;
V_4 ++ ;
V_4 ++ ;
return V_4 ;
}
static int
F_10 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 , int V_4 )
{
T_5 V_32 , V_33 ;
T_6 V_16 ;
T_5 V_18 ;
V_32 = F_6 ( V_1 , V_4 , 1 ) ;
F_2 ( V_3 , V_34 , V_1 , V_4 , 1 , V_7 ) ;
V_4 ++ ;
if( V_32 ) {
V_4 += 4 ;
V_4 += 3 ;
}
V_33 = F_6 ( V_1 , V_4 , 4 ) ;
F_2 ( V_3 , V_35 , V_1 , V_4 , 4 , V_7 ) ;
V_4 += 4 ;
if ( ( V_33 == 1 ) || ( V_33 == 2 ) ) {
V_4 = F_7 ( V_1 , T_3 , V_3 , V_4 ) ;
}
V_4 = F_5 ( V_1 , T_3 , V_3 , V_4 ) ;
V_16 = F_3 ( V_1 , V_4 , 32 , V_7 ) ;
while( V_16 == 0x1b2 ) {
V_4 = F_1 ( V_1 , T_3 , V_3 , V_4 ) ;
V_16 = F_3 ( V_1 , V_4 , 32 , V_7 ) ;
}
if ( V_33 == 1 ) {
V_16 = F_3 ( V_1 , V_4 , 24 , V_7 ) ;
if ( V_16 != 1 ) {
return - 1 ;
}
V_18 = F_6 ( V_1 , V_4 + 24 , 8 ) ;
if( V_18 > 0x20 ) {
return - 1 ;
}
F_2 ( V_3 , V_6 , V_1 , V_4 , 24 , V_7 ) ;
V_4 += 24 ;
F_2 ( V_3 , V_8 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
if( F_11 ( V_1 , ( V_4 >> 3 ) ) <= 0 ) {
F_9 ( V_3 , T_3 , & V_36 , V_1 , 0 , - 1 ) ;
return - 1 ;
}
V_4 = F_8 ( V_1 , T_3 , V_3 , V_4 ) ;
}
return V_4 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 , int V_4 )
{
T_6 V_16 ;
V_16 = F_3 ( V_1 , V_4 , 32 , V_7 ) ;
if ( ( V_16 & 0x00000100 ) != 0x00000100 ) {
return - 1 ;
}
F_2 ( V_3 , V_6 , V_1 , V_4 , 24 , V_7 ) ;
V_4 += 24 ;
F_2 ( V_3 , V_8 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
if( V_16 != 0x1b0 )
return - 1 ;
F_2 ( V_3 , V_37 , V_1 , V_4 , 8 , V_7 ) ;
V_4 += 8 ;
V_16 = F_3 ( V_1 , V_4 , 32 , V_7 ) ;
V_4 += 32 ;
if ( ( V_16 & 0x00000100 ) != 0x00000100 ) {
return - 1 ;
}
if( V_16 == 0x1b2 ) {
return - 1 ;
}
if( V_16 == 0x1b5 ) {
V_4 = F_10 ( V_1 , T_3 , V_3 , V_4 ) ;
}
return V_4 ;
}
static int
F_13 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 , void * T_7 V_2 )
{
T_8 * V_38 ;
T_4 * V_39 ;
V_38 = F_4 ( V_3 , V_40 , V_1 , 0 , - 1 , V_10 ) ;
V_39 = F_14 ( V_38 , V_41 ) ;
F_12 ( V_1 , T_3 , V_39 , 0 ) ;
return F_15 ( V_1 ) ;
}
static int
F_16 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 , void * T_7 V_2 )
{
int V_4 = 0 ;
T_8 * V_38 ;
T_4 * V_39 ;
T_6 V_16 ;
F_17 ( T_3 -> V_42 , V_43 , L_1 ) ;
if ( V_3 ) {
V_38 = F_4 ( V_3 , V_44 , V_1 , 0 , - 1 , V_10 ) ;
V_39 = F_14 ( V_38 , V_45 ) ;
if ( F_18 ( V_1 ) < 4 ) {
F_4 ( V_39 , V_46 , V_1 , V_4 >> 3 , - 1 , V_10 ) ;
return F_15 ( V_1 ) ;
}
V_16 = F_3 ( V_1 , V_4 , 24 , V_7 ) ;
if ( V_16 != 1 ) {
F_4 ( V_39 , V_46 , V_1 , V_4 >> 3 , - 1 , V_10 ) ;
return F_15 ( V_1 ) ;
}
V_16 = F_6 ( V_1 , 24 , 8 ) ;
V_4 = V_4 + 8 ;
switch( V_16 ) {
case 0xb6 :
F_2 ( V_39 , V_6 , V_1 , V_4 , 24 , V_7 ) ;
V_4 = V_4 + 24 ;
F_2 ( V_39 , V_47 , V_1 , V_4 , 2 , V_7 ) ;
break;
case 0xb0 :
F_12 ( V_1 , T_3 , V_39 , 0 ) ;
break;
default:
F_2 ( V_39 , V_6 , V_1 , V_4 , 24 , V_7 ) ;
break;
}
}
return F_15 ( V_1 ) ;
}
static int
F_19 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 V_2 , void * T_7 )
{
int V_48 = 0 ;
T_9 V_49 ;
const T_10 * V_50 = NULL ;
T_11 * V_51 ;
if ( T_7 == NULL )
return 0 ;
V_51 = F_20 ( T_7 ) ;
F_21 ( V_51 ) ;
V_49 = F_22 ( V_1 , V_48 ) ;
V_50 = F_23 ( V_49 , F_24 ( V_52 ) ) ;
if ( V_50 ) {
F_25 ( V_51 -> V_53 , L_2 , V_50 ) ;
}
V_48 += 2 ;
return V_48 ;
}
static int
F_26 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 V_2 , void * T_7 )
{
int V_48 = 0 ;
T_9 V_49 ;
const T_10 * V_50 = NULL ;
T_11 * V_51 ;
if ( T_7 == NULL )
return 0 ;
V_51 = F_20 ( T_7 ) ;
F_21 ( V_51 ) ;
V_49 = F_22 ( V_1 , V_48 ) ;
V_50 = F_23 ( V_49 , F_24 ( V_54 ) ) ;
if ( V_50 ) {
F_25 ( V_51 -> V_53 , L_3 , V_50 ) ;
}
V_48 += 2 ;
return V_48 ;
}
static int
F_27 ( T_1 * V_1 , T_2 * T_3 , T_4 * V_3 , void * T_7 )
{
T_11 * V_51 ;
if ( T_7 == NULL )
return 0 ;
V_51 = F_20 ( T_7 ) ;
F_21 ( V_51 ) ;
F_13 ( V_1 , T_3 , V_3 , T_7 ) ;
return F_18 ( V_1 ) ;
}
static T_12 * F_28 ( const T_10 * V_55 ) {
T_12 * V_56 = NULL ;
T_12 * V_57 ;
for ( V_57 = V_58 ; V_57 -> V_55 ; V_57 ++ ) {
if ( ! strcmp ( V_55 , V_57 -> V_55 ) ) { V_56 = V_57 ; break; }
}
return V_56 ;
}
static int
F_29 ( T_1 * V_1 V_2 , T_2 * T_3 , T_4 * V_3 , void * T_7 )
{
T_11 * V_51 ;
T_12 * V_56 ;
if ( T_7 == NULL )
return 0 ;
V_51 = F_20 ( T_7 ) ;
F_21 ( V_51 ) ;
if ( V_3 ) {
V_56 = F_28 ( T_3 -> V_59 ) ;
if ( V_56 ) {
F_25 ( V_51 -> V_53 , L_4 , V_56 -> V_60 ) ;
F_25 ( F_30 ( F_31 ( V_3 ) ) , L_5 , V_56 -> V_60 ) ;
} else {
F_25 ( V_51 -> V_53 , L_6 , T_3 -> V_59 ) ;
}
}
return F_18 ( V_1 ) ;
}
void
F_32 ( void )
{
static T_13 V_61 [] = {
{ & V_40 ,
{ L_7 , L_8 ,
V_62 , V_63 , NULL , 0x0 ,
NULL , V_64 }
} ,
{ & V_6 ,
{ L_9 , L_10 ,
V_65 , V_66 , NULL , 0x0 ,
NULL , V_64 }
} ,
{ & V_8 ,
{ L_11 , L_12 ,
V_67 , V_68 | V_66 , F_33 ( V_69 ) , 0x0 ,
NULL , V_64 }
} ,
{ & V_47 ,
{ L_13 , L_14 ,
V_67 , V_70 , F_24 ( V_71 ) , 0x0 ,
L_11 , V_64 }
} ,
{ & V_37 ,
{ L_15 , L_16 ,
V_67 , V_70 , F_24 ( V_52 ) , 0x0 ,
NULL , V_64 }
} ,
{ & V_34 ,
{ L_17 , L_18 ,
V_67 , V_70 , NULL , 0x0 ,
NULL , V_64 }
} ,
{ & V_35 ,
{ L_19 , L_20 ,
V_65 , V_70 , F_24 ( V_72 ) , 0x0 ,
NULL , V_64 }
} ,
{ & V_15 ,
{ L_21 , L_22 ,
V_67 , V_70 , NULL , 0x0 ,
NULL , V_64 }
} ,
{ & V_12 ,
{ L_23 , L_24 ,
V_67 , V_70 , NULL , 0x0 ,
NULL , V_64 }
} ,
{ & V_26 ,
{ L_25 , L_26 ,
V_67 , V_70 , F_24 ( V_73 ) , 0x0 ,
NULL , V_64 }
} ,
{ & V_25 ,
{ L_27 , L_28 ,
V_67 , V_70 , NULL , 0x0 ,
L_25 , V_64 }
} ,
{ & V_27 ,
{ L_29 , L_30 ,
V_67 , V_70 , NULL , 0x0 ,
NULL , V_64 }
} ,
{ & V_28 ,
{ L_31 , L_32 ,
V_67 , V_70 , F_24 ( V_74 ) , 0x0 ,
NULL , V_64 }
} ,
{ & V_29 ,
{ L_33 , L_34 ,
V_67 , V_70 , NULL , 0x0 ,
NULL , V_64 }
} ,
{ & V_31 ,
{ L_35 , L_36 ,
V_67 , V_70 , F_24 ( V_75 ) , 0x0 ,
NULL , V_64 }
} ,
{ & V_9 ,
{ L_37 , L_38 ,
V_62 , V_63 , NULL , 0x0 ,
NULL , V_64 }
} ,
{ & V_46 ,
{ L_39 , L_40 ,
V_62 , V_63 , NULL , 0x0 ,
NULL , V_64 }
} ,
} ;
static T_14 * V_76 [] = {
& V_45 ,
& V_41 ,
} ;
static T_15 V_77 [] = {
{ & V_36 , { L_41 , V_78 , V_79 , L_42 , V_80 } } ,
{ & V_30 , { L_43 , V_81 , V_82 , L_44 , V_80 } } ,
} ;
T_16 * V_83 ;
T_17 * V_84 ;
V_44 = F_34 ( L_1 , L_1 , L_45 ) ;
F_35 ( V_44 , V_61 , F_36 ( V_61 ) ) ;
F_37 ( V_76 , F_36 ( V_76 ) ) ;
V_84 = F_38 ( V_44 ) ;
F_39 ( V_84 , V_77 , F_36 ( V_77 ) ) ;
V_85 = F_40 ( L_46 , F_16 , V_44 ) ;
F_40 ( L_47 , F_13 , V_44 ) ;
V_83 = F_41 ( V_44 , V_86 ) ;
F_42 ( V_83 ,
L_48 ,
L_49 ,
L_50 ,
10 ,
& V_87 ) ;
}
void
V_86 ( void )
{
static T_18 V_88 ;
static T_19 V_89 = FALSE ;
if ( ! V_89 ) {
T_12 * V_56 ;
F_43 ( L_51 , L_1 , V_85 ) ;
V_89 = TRUE ;
V_90 = F_44 ( F_29 , V_44 ) ;
for ( V_56 = V_58 ; V_56 -> V_55 ; V_56 ++ ) {
if ( V_56 -> V_60 )
F_43 ( L_52 , V_56 -> V_55 , V_90 ) ;
if ( V_56 -> V_91 )
F_43 ( L_53 , V_56 -> V_55 , F_44 ( V_56 -> V_91 , V_44 ) ) ;
}
} else{
if ( V_88 > 95 )
F_45 ( L_54 , V_88 , V_85 ) ;
}
V_88 = V_87 ;
if ( V_88 > 95 ) {
F_46 ( L_54 , V_88 , V_85 ) ;
}
}
