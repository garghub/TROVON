static inline int
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_2 V_3 , V_4 , V_5 ;
V_3 = * V_2 ;
V_4 = V_3 ;
while( F_2 ( V_1 , V_3 ) != ':' )
++ V_3 ;
V_5 = atoi ( F_3 ( F_4 () , V_1 , V_4 , V_3 - V_4 , V_6 ) ) ;
++ V_3 ;
* V_2 = V_3 ;
return V_5 ;
}
static int
F_5 ( T_1 * V_1 , T_3 T_4 * V_7 , T_5 * V_8 , T_2 V_3 , const char * * V_9 , T_6 V_10 , const char * V_11 )
{
T_2 V_12 ;
V_12 = F_1 ( V_1 , & V_3 ) ;
if( V_10 )
* V_9 = F_6 ( V_1 , V_3 , V_12 ) ;
else
* V_9 = F_3 ( F_4 () , V_1 , V_3 , V_12 , V_6 ) ;
F_7 ( V_8 , V_13 , V_1 , V_3 , V_12 , * V_9 , L_1 , V_11 , * V_9 ) ;
V_3 += V_12 ;
return V_3 ;
}
static int
F_8 ( T_1 * V_1 , T_3 T_4 * V_7 , T_5 * V_8 , T_2 V_3 , const char * * V_9 , const char * V_11 )
{
T_2 V_14 ;
V_3 += 1 ;
V_14 = V_3 ;
while( F_2 ( V_1 , V_3 ) != 'e' )
V_3 += 1 ;
* V_9 = F_3 ( F_4 () , V_1 , V_14 , V_3 - V_14 , V_6 ) ;
F_7 ( V_8 , V_15 , V_1 , V_14 , V_3 - V_14 , * V_9 ,
L_1 , V_11 , * V_9 ) ;
V_3 += 1 ;
return V_3 ;
}
static int
F_9 ( T_1 * V_1 , T_3 * V_7 , T_5 * V_8 , T_2 V_3 , const char * V_11 )
{
T_7 * V_16 ;
T_5 * V_17 ;
T_2 V_18 ;
const char * V_9 ;
V_16 = F_10 ( V_8 , V_19 , V_1 , V_3 , 0 , L_2 , V_11 ) ;
V_17 = F_11 ( V_16 , V_20 ) ;
V_3 += 1 ;
while( ( V_18 = F_2 ( V_1 , V_3 ) ) != 'e' )
{
switch( V_18 )
{
case 'i' :
V_3 = F_8 ( V_1 , V_7 , V_17 , V_3 , & V_9 , L_3 ) ;
break;
case 'l' :
V_3 = F_9 ( V_1 , V_7 , V_17 , V_3 , L_4 ) ;
break;
case 'd' :
V_3 = F_12 ( V_1 , V_7 , V_17 , V_3 , L_5 ) ;
break;
default:
V_3 = F_5 ( V_1 , V_7 , V_17 , V_3 , & V_9 , FALSE , L_6 ) ;
break;
}
}
V_3 += 1 ;
return V_3 ;
}
static int
F_13 ( T_1 * V_1 , T_3 * V_7 , T_5 * V_8 , T_2 V_3 , const char * * V_9 , const char * V_11 )
{
T_7 * V_16 ;
T_5 * V_17 ;
const char * V_21 , * V_22 ;
V_21 = NULL ;
V_22 = NULL ;
V_16 = F_14 ( V_8 , V_23 , V_1 , V_3 , 0 , V_24 ) ;
V_17 = F_11 ( V_16 , V_25 ) ;
V_3 += 1 ;
V_3 = F_8 ( V_1 , V_7 , V_17 , V_3 , & V_21 , L_7 ) ;
V_3 = F_5 ( V_1 , V_7 , V_17 , V_3 , & V_22 , FALSE , L_8 ) ;
F_15 ( V_16 , L_9 , V_11 , V_21 , V_22 ) ;
F_16 ( V_7 -> V_26 , V_27 , L_10 , V_21 , V_22 ) ;
* V_9 = F_17 ( F_4 () , L_11 , V_21 , V_22 ) ;
return V_3 ;
}
static int
F_18 ( T_1 * V_1 , T_3 * V_7 , T_5 * V_8 , T_2 V_3 , const char * * V_9 , const char * V_11 )
{
T_7 * V_16 ;
T_5 * V_17 ;
T_7 * V_28 ;
T_5 * V_29 ;
T_2 V_30 ;
T_2 V_12 ;
V_16 = F_14 ( V_8 , V_31 , V_1 , V_3 , 0 , V_24 ) ;
V_17 = F_11 ( V_16 , V_32 ) ;
V_30 = 0 ;
V_3 += 1 ;
while( F_2 ( V_1 , V_3 ) != 'e' )
{
V_12 = F_1 ( V_1 , & V_3 ) ;
for( ; V_12 >= 6 ; V_12 -= 6 , V_3 += 6 )
{
V_30 += 1 ;
V_28 = F_14 ( V_17 , V_33 , V_1 , V_3 , 6 , V_24 ) ;
F_19 ( V_28 , L_12 , V_30 ) ;
V_29 = F_11 ( V_28 , V_32 ) ;
F_14 ( V_29 , V_34 , V_1 , V_3 , 4 , V_35 ) ;
F_19 ( V_28 , L_13 , F_20 ( V_1 , V_3 ) ) ;
F_14 ( V_29 , V_36 , V_1 , V_3 + 4 , 2 , V_35 ) ;
F_19 ( V_28 , L_14 , F_21 ( V_1 , V_3 + 4 ) ) ;
}
if( V_12 > 0 )
{
F_14 ( V_8 , V_37 , V_1 , V_3 , V_12 , V_24 ) ;
V_3 += V_12 ;
}
}
if ( F_2 ( V_1 , V_3 ) == 'e' )
V_3 ++ ;
F_15 ( V_16 , L_15 , V_11 , V_30 ) ;
F_16 ( V_7 -> V_26 , V_27 , L_16 , V_30 ) ;
* V_9 = F_17 ( F_4 () , L_17 , V_30 ) ;
return V_3 ;
}
static int
F_22 ( T_1 * V_1 , T_3 * V_7 , T_5 * V_8 , T_2 V_3 , const char * * V_9 , const char * V_11 )
{
T_7 * V_16 ;
T_5 * V_17 ;
T_7 * V_38 ;
T_5 * V_39 ;
T_2 V_40 ;
T_2 V_12 ;
V_12 = F_1 ( V_1 , & V_3 ) ;
V_16 = F_14 ( V_8 , V_41 , V_1 , V_3 , V_12 , V_24 ) ;
V_17 = F_11 ( V_16 , V_42 ) ;
V_40 = 0 ;
for( ; V_12 >= 26 ; V_12 -= 26 , V_3 += 26 )
{
V_40 += 1 ;
V_38 = F_14 ( V_17 , V_43 , V_1 , V_3 , 26 , V_24 ) ;
F_19 ( V_38 , L_12 , V_40 ) ;
V_39 = F_11 ( V_38 , V_32 ) ;
F_14 ( V_39 , V_44 , V_1 , V_3 , 20 , V_24 ) ;
F_19 ( V_38 , L_18 , F_6 ( V_1 , V_3 , 20 ) ) ;
F_14 ( V_39 , V_34 , V_1 , V_3 + 20 , 4 , V_35 ) ;
F_19 ( V_38 , L_19 , F_20 ( V_1 , V_3 + 20 ) ) ;
F_14 ( V_39 , V_36 , V_1 , V_3 + 24 , 2 , V_35 ) ;
F_19 ( V_38 , L_14 , F_21 ( V_1 , V_3 + 24 ) ) ;
}
if( V_12 > 0 )
{
F_14 ( V_8 , V_37 , V_1 , V_3 , V_12 , V_24 ) ;
V_3 += V_12 ;
}
F_15 ( V_16 , L_20 , V_11 , V_40 ) ;
F_16 ( V_7 -> V_26 , V_27 , L_21 , V_40 ) ;
* V_9 = F_17 ( F_4 () , L_22 , V_40 ) ;
return V_3 ;
}
static int
F_23 ( T_1 * V_1 , T_3 * V_7 , T_5 * V_8 , T_2 V_3 )
{
T_7 * V_16 ;
T_5 * V_17 ;
T_6 V_10 ;
const char * V_45 ;
const char * V_46 ;
T_2 V_47 = V_3 ;
V_45 = NULL ;
V_46 = NULL ;
V_16 = F_14 ( V_8 , V_48 , V_1 , V_3 , 0 , V_24 ) ;
V_17 = F_11 ( V_16 , V_49 ) ;
V_3 = F_5 ( V_1 , V_7 , V_17 , V_3 , & V_45 , FALSE , L_23 ) ;
switch( F_2 ( V_1 , V_3 ) )
{
case 'd' :
V_3 = F_12 ( V_1 , V_7 , V_17 , V_3 , L_24 ) ;
V_46 = V_50 ;
break;
case 'l' :
if( strcmp ( V_45 , L_25 ) == 0 )
V_3 = F_13 ( V_1 , V_7 , V_17 , V_3 , & V_46 , L_24 ) ;
else if( strcmp ( V_45 , L_26 ) == 0 )
V_3 = F_18 ( V_1 , V_7 , V_17 , V_3 , & V_46 , L_24 ) ;
else
{
V_3 = F_9 ( V_1 , V_7 , V_17 , V_3 , L_24 ) ;
V_46 = V_51 ;
}
break;
case 'i' :
V_3 = F_8 ( V_1 , V_7 , V_17 , V_3 , & V_46 , L_24 ) ;
break;
default:
if( strcmp ( V_45 , L_27 ) == 0 )
{
V_3 = F_22 ( V_1 , V_7 , V_17 , V_3 , & V_46 , L_24 ) ;
}
else if( strcmp ( V_45 , L_28 ) == 0 )
{
int V_5 , V_52 ;
V_52 = V_3 ;
V_5 = F_1 ( V_1 , & V_3 ) ;
if( V_5 == 4 ) {
F_14 ( V_17 , V_34 , V_1 , V_3 , V_5 , V_35 ) ;
V_46 = F_20 ( V_1 , V_3 ) ;
V_3 += V_5 ;
}
else {
V_3 = F_5 ( V_1 , V_7 , V_17 , V_52 , & V_46 , TRUE , L_24 ) ;
}
}
else
{
V_10 = strcmp ( V_45 , L_29 ) == 0 || strcmp ( V_45 , L_30 ) == 0
|| strcmp ( V_45 , L_31 ) == 0 || strcmp ( V_45 , L_32 ) == 0
|| strcmp ( V_45 , L_33 ) == 0 || strcmp ( V_45 , L_34 ) == 0 ;
V_3 = F_5 ( V_1 , V_7 , V_17 , V_3 , & V_46 , V_10 , L_24 ) ;
}
}
if( strlen ( V_45 ) == 1 )
V_45 = F_24 ( V_45 [ 0 ] , V_53 , V_45 ) ;
if( strlen ( V_46 ) == 1 )
V_46 = F_24 ( V_46 [ 0 ] , V_54 , V_46 ) ;
F_15 ( V_16 , L_1 , V_45 , V_46 ) ;
F_25 ( V_16 , V_3 - V_47 ) ;
if( strcmp ( V_45 , L_35 ) == 0 || strcmp ( V_45 , L_36 ) == 0 )
F_16 ( V_7 -> V_26 , V_27 , L_37 , V_45 , V_46 ) ;
return V_3 ;
}
static int
F_12 ( T_1 * V_1 , T_3 * V_7 , T_5 * V_8 , T_2 V_3 , const char * V_11 )
{
T_7 * V_16 ;
T_5 * V_17 ;
T_2 V_47 = V_3 ;
if( V_3 == 0 )
{
V_16 = F_14 ( V_8 , V_55 , V_1 , 0 , - 1 , V_24 ) ;
V_17 = F_11 ( V_16 , V_56 ) ;
}
else
{
V_16 = F_10 ( V_8 , V_57 , V_1 , V_3 , - 1 , L_38 , V_11 ) ;
V_17 = F_11 ( V_16 , V_58 ) ;
}
V_3 += 1 ;
while( F_2 ( V_1 , V_3 ) != 'e' )
V_3 = F_23 ( V_1 , V_7 , V_17 , V_3 ) ;
V_3 += 1 ;
F_25 ( V_16 , V_3 - V_47 ) ;
return V_3 ;
}
static int
F_26 ( T_1 * V_1 , T_3 * V_7 , T_5 * V_8 , void * T_8 T_4 )
{
F_27 ( V_7 -> V_26 , V_59 , L_39 ) ;
F_28 ( V_7 -> V_26 , V_27 ) ;
return F_12 ( V_1 , V_7 , V_8 , 0 , L_40 ) ;
}
static
T_6 F_29 ( T_1 * V_1 , T_3 * V_7 ,
T_5 * V_8 , void * T_8 T_4 )
{
T_9 * V_60 ;
if( F_30 ( V_1 ) < 4 )
return FALSE ;
if( F_31 ( V_1 , 0 , L_41 , 3 ) != 0 )
return FALSE ;
if( F_32 ( F_2 ( V_1 , 3 ) , V_53 ) == NULL )
return FALSE ;
V_60 = F_33 ( V_7 ) ;
F_34 ( V_60 , V_61 ) ;
F_26 ( V_1 , V_7 , V_8 , NULL ) ;
return TRUE ;
}
void
F_35 ( void )
{
static T_10 V_62 [] = {
{ & V_13 ,
{ L_6 , L_42 ,
V_63 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_19 ,
{ L_43 , L_44 ,
V_66 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_15 ,
{ L_45 , L_46 ,
V_63 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_57 ,
{ L_47 , L_48 ,
V_66 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_48 ,
{ L_49 , L_50 ,
V_66 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_23 ,
{ L_51 , L_52 ,
V_66 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_33 ,
{ L_53 , L_54 ,
V_66 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_31 ,
{ L_55 , L_56 ,
V_66 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_43 ,
{ L_57 , L_58 ,
V_66 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_41 ,
{ L_59 , L_60 ,
V_66 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_44 ,
{ L_61 , L_62 ,
V_67 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_34 ,
{ L_63 , L_64 ,
V_68 , V_64 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_36 ,
{ L_65 , L_66 ,
V_69 , V_70 , NULL , 0x0 , NULL , V_65 }
} ,
{ & V_37 ,
{ L_67 , L_68 ,
V_67 , V_64 , NULL , 0x0 , NULL , V_65 }
}
} ;
static T_11 * V_71 [] = {
& V_56 ,
& V_20 ,
& V_58 ,
& V_25 ,
& V_32 ,
& V_42 ,
& V_49
} ;
T_12 * V_72 ;
V_55 = F_36 (
L_40 ,
L_39 ,
L_69
) ;
V_72 = F_37 ( V_55 , V_73 ) ;
F_38 ( V_72 , L_70 , L_71 ,
L_72 ,
& V_74 ) ;
F_39 ( V_55 , V_62 , F_40 ( V_62 ) ) ;
F_41 ( V_71 , F_40 ( V_71 ) ) ;
}
void
V_73 ( void )
{
static T_6 V_75 = FALSE ;
if ( ! V_75 ) {
F_42 ( L_73 , F_29 , V_55 ) ;
V_61 = F_43 ( F_26 , V_55 ) ;
F_44 ( L_74 , V_61 ) ;
V_75 = TRUE ;
}
F_45 ( L_73 , F_29 , V_55 , V_74 ) ;
}
