static int
F_1 ( T_1 * V_1 , T_2 T_3 * V_2 , T_4 * V_3 , T_5 V_4 , char * * V_5 , T_6 V_6 , const char * V_7 )
{
T_5 V_8 ;
T_5 V_9 ;
V_8 = V_4 ;
while( F_2 ( V_1 , V_4 ) != ':' )
V_4 += 1 ;
V_9 = atoi ( F_3 ( V_1 , V_8 , V_4 - V_8 ) ) ;
V_4 += 1 ;
if( V_6 )
* V_5 = F_4 ( V_1 , V_4 , V_9 ) ;
else
* V_5 = F_3 ( V_1 , V_4 , V_9 ) ;
F_5 ( V_3 , V_10 , V_1 , V_4 , V_9 , * V_5 , L_1 , V_7 , * V_5 ) ;
V_4 += V_9 ;
return V_4 ;
}
static int
F_6 ( T_1 * V_1 , T_2 T_3 * V_2 , T_4 * V_3 , T_5 V_4 , char * * V_5 , const char * V_7 )
{
T_5 V_11 ;
V_11 = V_4 ;
V_4 += 1 ;
while( F_2 ( V_1 , V_4 ) != 'e' )
V_4 += 1 ;
* V_5 = F_3 ( V_1 , V_4 , V_4 - V_11 - 1 ) ;
F_5 ( V_3 , V_12 , V_1 , V_4 , V_4 - V_11 - 1 , * V_5 ,
L_1 , V_7 , * V_5 ) ;
V_4 += 1 ;
return V_4 ;
}
static int
F_7 ( T_1 * V_1 , T_2 * V_2 , T_4 * V_3 , T_5 V_4 , const char * V_7 )
{
T_7 * V_13 ;
T_4 * V_14 ;
T_5 V_15 ;
char * V_5 ;
V_13 = F_8 ( V_3 , V_16 , V_1 , V_4 , 0 , L_2 , V_7 ) ;
V_14 = F_9 ( V_13 , V_17 ) ;
V_4 += 1 ;
while( ( V_15 = F_2 ( V_1 , V_4 ) ) != 'e' )
{
switch( V_15 )
{
case 'i' :
V_4 = F_6 ( V_1 , V_2 , V_14 , V_4 , & V_5 , L_3 ) ;
break;
case 'l' :
V_4 = F_7 ( V_1 , V_2 , V_14 , V_4 , L_4 ) ;
break;
case 'd' :
V_4 = F_10 ( V_1 , V_2 , V_14 , V_4 , L_5 ) ;
break;
default:
V_4 = F_1 ( V_1 , V_2 , V_14 , V_4 , & V_5 , FALSE , L_6 ) ;
break;
}
}
V_4 += 1 ;
return V_4 ;
}
static int
F_11 ( T_1 * V_1 , T_2 * V_2 , T_4 * V_3 , T_5 V_4 , char * * V_5 , const char * V_7 )
{
T_7 * V_13 ;
T_4 * V_14 ;
char * V_18 , * V_19 ;
V_18 = NULL ;
V_19 = NULL ;
V_13 = F_12 ( V_3 , V_20 , V_1 , V_4 , 0 , V_21 ) ;
V_14 = F_9 ( V_13 , V_22 ) ;
V_4 += 1 ;
V_4 = F_6 ( V_1 , V_2 , V_14 , V_4 , & V_18 , L_7 ) ;
V_4 = F_1 ( V_1 , V_2 , V_14 , V_4 , & V_19 , FALSE , L_8 ) ;
F_13 ( V_13 , L_9 , V_7 , V_18 , V_19 ) ;
F_14 ( V_2 -> V_23 , V_24 , L_10 , V_18 , V_19 ) ;
* V_5 = F_15 ( L_11 , V_18 , V_19 ) ;
return V_4 ;
}
static int
F_16 ( T_1 * V_1 , T_2 * V_2 , T_4 * V_3 , T_5 V_4 , char * * V_5 , const char * V_7 )
{
T_7 * V_13 ;
T_4 * V_14 ;
T_7 * V_25 ;
T_4 * V_26 ;
T_8 V_27 ;
T_5 V_28 ;
T_5 V_8 ;
T_5 V_9 ;
T_9 V_29 ;
V_13 = F_12 ( V_3 , V_30 , V_1 , V_4 , 0 , V_21 ) ;
V_14 = F_9 ( V_13 , V_31 ) ;
V_28 = 0 ;
V_4 += 1 ;
while( F_2 ( V_1 , V_4 ) != 'e' )
{
V_8 = V_4 ;
while( F_2 ( V_1 , V_4 ) != ':' )
V_4 += 1 ;
V_9 = atoi ( F_3 ( V_1 , V_8 , V_4 - V_8 ) ) ;
V_4 += 1 ;
for( ; V_9 >= 6 ; V_9 -= 6 , V_4 += 6 )
{
V_28 += 1 ;
F_17 ( & V_27 , V_32 , 4 , F_18 ( V_1 , V_4 , 4 ) ) ;
V_29 = F_19 ( V_1 , V_4 + 4 ) ;
V_25 = F_8 ( V_14 , V_33 , V_1 , V_4 , 6 ,
L_12 , V_28 , F_20 ( & V_27 ) , V_29 ) ;
V_26 = F_9 ( V_25 , V_31 ) ;
F_12 ( V_26 , V_34 , V_1 , V_4 , 4 , V_35 ) ;
F_12 ( V_26 , V_36 , V_1 , V_4 + 4 , 2 , V_35 ) ;
}
if( V_9 > 0 )
{
F_12 ( V_3 , V_37 , V_1 , V_4 , V_9 , V_21 ) ;
V_4 += V_9 ;
}
}
F_13 ( V_13 , L_13 , V_7 , V_28 ) ;
F_14 ( V_2 -> V_23 , V_24 , L_14 , V_28 ) ;
* V_5 = F_15 ( L_15 , V_28 ) ;
return V_4 ;
}
static int
F_21 ( T_1 * V_1 , T_2 * V_2 , T_4 * V_3 , T_5 V_4 , char * * V_5 , char * V_7 )
{
T_7 * V_13 ;
T_4 * V_14 ;
T_7 * V_38 ;
T_4 * V_39 ;
T_5 V_40 ;
T_5 V_8 ;
T_5 V_9 ;
T_8 V_27 ;
T_9 V_29 ;
T_10 * V_41 ;
V_13 = F_12 ( V_3 , V_42 , V_1 , V_4 , 0 , V_21 ) ;
V_14 = F_9 ( V_13 , V_43 ) ;
V_40 = 0 ;
V_8 = V_4 ;
while( F_2 ( V_1 , V_4 ) != ':' )
V_4 += 1 ;
V_9 = atoi ( F_3 ( V_1 , V_8 , V_4 - V_8 ) ) ;
V_4 += 1 ;
for( ; V_9 >= 26 ; V_9 -= 26 , V_4 += 26 )
{
V_40 += 1 ;
V_41 = F_4 ( V_1 , V_4 , 20 ) ;
F_17 ( & V_27 , V_32 , 4 , F_18 ( V_1 , V_4 , 4 ) ) ;
V_29 = F_19 ( V_1 , V_4 + 24 ) ;
V_38 = F_8 ( V_14 , V_44 , V_1 , V_4 , 26 ,
L_16 , V_40 , V_41 , F_20 ( & V_27 ) , V_29 ) ;
V_39 = F_9 ( V_38 , V_31 ) ;
F_12 ( V_39 , V_45 , V_1 , V_4 , 20 , V_21 ) ;
F_12 ( V_39 , V_34 , V_1 , V_4 + 20 , 4 , V_35 ) ;
F_12 ( V_39 , V_36 , V_1 , V_4 + 24 , 2 , V_35 ) ;
}
if( V_9 > 0 )
{
F_12 ( V_3 , V_37 , V_1 , V_4 , V_9 , V_21 ) ;
V_4 += V_9 ;
}
F_13 ( V_13 , L_17 , V_7 , V_40 ) ;
F_14 ( V_2 -> V_23 , V_24 , L_18 , V_40 ) ;
* V_5 = F_15 ( L_19 , V_40 ) ;
return V_4 ;
}
static int
F_22 ( T_1 * V_1 , T_2 * V_2 , T_4 * V_3 , T_5 V_4 )
{
T_7 * V_13 ;
T_4 * V_14 ;
T_6 V_6 ;
char * V_46 , * V_47 ;
T_5 V_48 = V_4 ;
V_46 = NULL ;
V_47 = NULL ;
V_13 = F_12 ( V_3 , V_49 , V_1 , V_4 , 0 , V_21 ) ;
V_14 = F_9 ( V_13 , V_50 ) ;
V_4 = F_1 ( V_1 , V_2 , V_14 , V_4 , & V_46 , FALSE , L_20 ) ;
switch( F_2 ( V_1 , V_4 ) )
{
case 'd' :
V_4 = F_10 ( V_1 , V_2 , V_14 , V_4 , L_21 ) ;
V_47 = ( char * ) V_51 ;
break;
case 'l' :
if( strcmp ( V_46 , L_22 ) == 0 )
V_4 = F_11 ( V_1 , V_2 , V_14 , V_4 , & V_47 , L_21 ) ;
else if( strcmp ( V_46 , L_23 ) == 0 )
V_4 = F_16 ( V_1 , V_2 , V_14 , V_4 , & V_47 , L_21 ) ;
else
{
V_4 = F_7 ( V_1 , V_2 , V_14 , V_4 , L_21 ) ;
V_47 = ( char * ) V_52 ;
}
break;
case 'i' :
V_4 = F_6 ( V_1 , V_2 , V_14 , V_4 , & V_47 , L_21 ) ;
break;
default:
if( strcmp ( V_46 , L_24 ) == 0 )
V_4 = F_21 ( V_1 , V_2 , V_14 , V_4 , & V_47 , L_21 ) ;
else
{
V_6 = strcmp ( V_46 , L_25 ) == 0 || strcmp ( V_46 , L_26 ) == 0
|| strcmp ( V_46 , L_27 ) == 0 || strcmp ( V_46 , L_28 ) == 0
|| strcmp ( V_46 , L_29 ) == 0 ;
V_4 = F_1 ( V_1 , V_2 , V_14 , V_4 , & V_47 , V_6 , L_21 ) ;
}
}
if( strlen ( V_46 ) == 1 )
V_46 = ( char * ) F_23 ( V_46 [ 0 ] , V_53 , V_46 ) ;
if( strlen ( V_47 ) == 1 )
V_47 = ( char * ) F_23 ( V_47 [ 0 ] , V_54 , V_47 ) ;
F_13 ( V_13 , L_1 , V_46 , V_47 ) ;
F_24 ( V_13 , V_4 - V_48 ) ;
if( strcmp ( V_46 , L_30 ) == 0 || strcmp ( V_46 , L_31 ) == 0 )
F_14 ( V_2 -> V_23 , V_24 , L_32 , V_46 , V_47 ) ;
return V_4 ;
}
static int
F_10 ( T_1 * V_1 , T_2 * V_2 , T_4 * V_3 , T_5 V_4 , char * V_7 )
{
T_7 * V_13 ;
T_4 * V_14 ;
T_5 V_48 = V_4 ;
V_13 = F_8 ( V_3 , V_55 , V_1 , V_4 , 0 , L_33 , V_7 ) ;
V_14 = F_9 ( V_13 , V_56 ) ;
V_4 += 1 ;
while( F_2 ( V_1 , V_4 ) != 'e' )
V_4 = F_22 ( V_1 , V_2 , V_14 , V_4 ) ;
V_4 += 1 ;
F_24 ( V_13 , V_4 - V_48 ) ;
return V_4 ;
}
static int
F_25 ( T_1 * V_1 , T_2 * V_2 , T_4 * V_3 )
{
F_26 ( V_2 -> V_23 , V_57 , L_34 ) ;
F_27 ( V_2 -> V_23 , V_24 ) ;
return F_10 ( V_1 , V_2 , V_3 , 0 , L_35 ) ;
}
static
T_6 F_28 ( T_1 * V_1 , T_2 * V_2 ,
T_4 * V_3 )
{
if( F_2 ( V_1 , 0 ) == 'd' )
{
T_11 * V_58 ;
V_58 = F_29 ( V_2 ) ;
F_30 ( V_58 , V_59 ) ;
F_25 ( V_1 , V_2 , V_3 ) ;
return TRUE ;
}
return FALSE ;
}
void
F_31 ( void )
{
static T_12 V_60 [] = {
{ & V_10 ,
{ L_36 , L_37 ,
V_61 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_16 ,
{ L_38 , L_39 ,
V_64 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_12 ,
{ L_40 , L_41 ,
V_61 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_55 ,
{ L_42 , L_43 ,
V_64 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_49 ,
{ L_44 , L_45 ,
V_64 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_20 ,
{ L_46 , L_47 ,
V_64 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_33 ,
{ L_48 , L_49 ,
V_64 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_30 ,
{ L_50 , L_51 ,
V_64 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_44 ,
{ L_52 , L_53 ,
V_64 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_42 ,
{ L_54 , L_55 ,
V_64 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_45 ,
{ L_25 , L_56 ,
V_65 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_34 ,
{ L_57 , L_58 ,
V_66 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_36 ,
{ L_59 , L_60 ,
V_67 , V_68 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_37 ,
{ L_61 , L_62 ,
V_65 , V_62 , NULL , 0x0 , NULL , V_63 }
}
} ;
static T_13 * V_69 [] = {
& V_70 ,
& V_17 ,
& V_56 ,
& V_22 ,
& V_31 ,
& V_43 ,
& V_50
} ;
T_14 * V_71 ;
V_72 = F_32 (
L_63 ,
L_34 ,
L_64
) ;
V_71 = F_33 ( V_72 , V_73 ) ;
F_34 ( V_71 , L_65 , L_66 ,
L_67 ,
& V_74 ) ;
F_35 ( V_72 , V_60 , F_36 ( V_60 ) ) ;
F_37 ( V_69 , F_36 ( V_69 ) ) ;
}
void
V_73 ( void )
{
static T_6 V_75 = FALSE ;
if ( ! V_75 ) {
F_38 ( L_68 , F_28 , V_72 ) ;
V_59 = F_39 ( F_25 , V_72 ) ;
F_40 ( L_69 , V_59 ) ;
V_75 = TRUE ;
}
F_41 ( L_68 , F_28 , V_72 , V_74 ) ;
}
