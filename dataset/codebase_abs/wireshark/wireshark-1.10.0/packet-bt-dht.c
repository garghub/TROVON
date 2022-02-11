static inline int
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_2 V_3 , V_4 , V_5 ;
V_3 = * V_2 ;
V_4 = V_3 ;
while( F_2 ( V_1 , V_3 ) != ':' )
++ V_3 ;
V_5 = atoi ( F_3 ( V_1 , V_4 , V_3 - V_4 ) ) ;
++ V_3 ;
* V_2 = V_3 ;
return V_5 ;
}
static int
F_4 ( T_1 * V_1 , T_3 T_4 * V_6 , T_5 * V_7 , T_2 V_3 , char * * V_8 , T_6 V_9 , const char * V_10 )
{
T_2 V_11 ;
V_11 = F_1 ( V_1 , & V_3 ) ;
if( V_9 )
* V_8 = F_5 ( V_1 , V_3 , V_11 ) ;
else
* V_8 = F_3 ( V_1 , V_3 , V_11 ) ;
F_6 ( V_7 , V_12 , V_1 , V_3 , V_11 , * V_8 , L_1 , V_10 , * V_8 ) ;
V_3 += V_11 ;
return V_3 ;
}
static int
F_7 ( T_1 * V_1 , T_3 T_4 * V_6 , T_5 * V_7 , T_2 V_3 , char * * V_8 , const char * V_10 )
{
T_2 V_13 ;
V_13 = V_3 ;
V_3 += 1 ;
while( F_2 ( V_1 , V_3 ) != 'e' )
V_3 += 1 ;
* V_8 = F_3 ( V_1 , V_3 , V_3 - V_13 - 1 ) ;
F_6 ( V_7 , V_14 , V_1 , V_3 , V_3 - V_13 - 1 , * V_8 ,
L_1 , V_10 , * V_8 ) ;
V_3 += 1 ;
return V_3 ;
}
static int
F_8 ( T_1 * V_1 , T_3 * V_6 , T_5 * V_7 , T_2 V_3 , const char * V_10 )
{
T_7 * V_15 ;
T_5 * V_16 ;
T_2 V_17 ;
char * V_8 ;
V_15 = F_9 ( V_7 , V_18 , V_1 , V_3 , 0 , L_2 , V_10 ) ;
V_16 = F_10 ( V_15 , V_19 ) ;
V_3 += 1 ;
while( ( V_17 = F_2 ( V_1 , V_3 ) ) != 'e' )
{
switch( V_17 )
{
case 'i' :
V_3 = F_7 ( V_1 , V_6 , V_16 , V_3 , & V_8 , L_3 ) ;
break;
case 'l' :
V_3 = F_8 ( V_1 , V_6 , V_16 , V_3 , L_4 ) ;
break;
case 'd' :
V_3 = F_11 ( V_1 , V_6 , V_16 , V_3 , L_5 ) ;
break;
default:
V_3 = F_4 ( V_1 , V_6 , V_16 , V_3 , & V_8 , FALSE , L_6 ) ;
break;
}
}
V_3 += 1 ;
return V_3 ;
}
static int
F_12 ( T_1 * V_1 , T_3 * V_6 , T_5 * V_7 , T_2 V_3 , char * * V_8 , const char * V_10 )
{
T_7 * V_15 ;
T_5 * V_16 ;
char * V_20 , * V_21 ;
V_20 = NULL ;
V_21 = NULL ;
V_15 = F_13 ( V_7 , V_22 , V_1 , V_3 , 0 , V_23 ) ;
V_16 = F_10 ( V_15 , V_24 ) ;
V_3 += 1 ;
V_3 = F_7 ( V_1 , V_6 , V_16 , V_3 , & V_20 , L_7 ) ;
V_3 = F_4 ( V_1 , V_6 , V_16 , V_3 , & V_21 , FALSE , L_8 ) ;
F_14 ( V_15 , L_9 , V_10 , V_20 , V_21 ) ;
F_15 ( V_6 -> V_25 , V_26 , L_10 , V_20 , V_21 ) ;
* V_8 = F_16 ( L_11 , V_20 , V_21 ) ;
return V_3 ;
}
static int
F_17 ( T_1 * V_1 , T_3 * V_6 , T_5 * V_7 , T_2 V_3 , char * * V_8 , const char * V_10 )
{
T_7 * V_15 ;
T_5 * V_16 ;
T_7 * V_27 ;
T_5 * V_28 ;
T_2 V_29 ;
T_2 V_11 ;
V_15 = F_13 ( V_7 , V_30 , V_1 , V_3 , 0 , V_23 ) ;
V_16 = F_10 ( V_15 , V_31 ) ;
V_29 = 0 ;
V_3 += 1 ;
while( F_2 ( V_1 , V_3 ) != 'e' )
{
V_11 = F_1 ( V_1 , & V_3 ) ;
for( ; V_11 >= 6 ; V_11 -= 6 , V_3 += 6 )
{
V_29 += 1 ;
V_27 = F_13 ( V_16 , V_32 , V_1 , V_3 , 6 , V_23 ) ;
F_18 ( V_27 , L_12 , V_29 ) ;
V_28 = F_10 ( V_27 , V_31 ) ;
F_13 ( V_28 , V_33 , V_1 , V_3 , 4 , V_34 ) ;
F_18 ( V_27 , L_13 , F_19 ( V_1 , V_3 ) ) ;
F_13 ( V_28 , V_35 , V_1 , V_3 + 4 , 2 , V_34 ) ;
F_18 ( V_27 , L_14 , F_20 ( V_1 , V_3 + 4 ) ) ;
}
if( V_11 > 0 )
{
F_13 ( V_7 , V_36 , V_1 , V_3 , V_11 , V_23 ) ;
V_3 += V_11 ;
}
}
if ( F_2 ( V_1 , V_3 ) == 'e' )
V_3 ++ ;
F_14 ( V_15 , L_15 , V_10 , V_29 ) ;
F_15 ( V_6 -> V_25 , V_26 , L_16 , V_29 ) ;
* V_8 = F_16 ( L_17 , V_29 ) ;
return V_3 ;
}
static int
F_21 ( T_1 * V_1 , T_3 * V_6 , T_5 * V_7 , T_2 V_3 , char * * V_8 , const char * V_10 )
{
T_7 * V_15 ;
T_5 * V_16 ;
T_7 * V_37 ;
T_5 * V_38 ;
T_2 V_39 ;
T_2 V_11 ;
V_11 = F_1 ( V_1 , & V_3 ) ;
V_15 = F_13 ( V_7 , V_40 , V_1 , V_3 , V_11 , V_23 ) ;
V_16 = F_10 ( V_15 , V_41 ) ;
V_39 = 0 ;
for( ; V_11 >= 26 ; V_11 -= 26 , V_3 += 26 )
{
V_39 += 1 ;
V_37 = F_13 ( V_16 , V_42 , V_1 , V_3 , 26 , V_23 ) ;
F_18 ( V_37 , L_12 , V_39 ) ;
V_38 = F_10 ( V_37 , V_31 ) ;
F_13 ( V_38 , V_43 , V_1 , V_3 , 20 , V_23 ) ;
F_18 ( V_37 , L_18 , F_5 ( V_1 , V_3 , 20 ) ) ;
F_13 ( V_38 , V_33 , V_1 , V_3 + 20 , 4 , V_34 ) ;
F_18 ( V_37 , L_19 , F_19 ( V_1 , V_3 + 20 ) ) ;
F_13 ( V_38 , V_35 , V_1 , V_3 + 24 , 2 , V_34 ) ;
F_18 ( V_37 , L_14 , F_20 ( V_1 , V_3 + 24 ) ) ;
}
if( V_11 > 0 )
{
F_13 ( V_7 , V_36 , V_1 , V_3 , V_11 , V_23 ) ;
V_3 += V_11 ;
}
F_14 ( V_15 , L_20 , V_10 , V_39 ) ;
F_15 ( V_6 -> V_25 , V_26 , L_21 , V_39 ) ;
* V_8 = F_16 ( L_22 , V_39 ) ;
return V_3 ;
}
static int
F_22 ( T_1 * V_1 , T_3 * V_6 , T_5 * V_7 , T_2 V_3 )
{
T_7 * V_15 ;
T_5 * V_16 ;
T_6 V_9 ;
char * V_44 , * V_45 ;
T_2 V_46 = V_3 ;
V_44 = NULL ;
V_45 = NULL ;
V_15 = F_13 ( V_7 , V_47 , V_1 , V_3 , 0 , V_23 ) ;
V_16 = F_10 ( V_15 , V_48 ) ;
V_3 = F_4 ( V_1 , V_6 , V_16 , V_3 , & V_44 , FALSE , L_23 ) ;
switch( F_2 ( V_1 , V_3 ) )
{
case 'd' :
V_3 = F_11 ( V_1 , V_6 , V_16 , V_3 , L_24 ) ;
V_45 = ( char * ) V_49 ;
break;
case 'l' :
if( strcmp ( V_44 , L_25 ) == 0 )
V_3 = F_12 ( V_1 , V_6 , V_16 , V_3 , & V_45 , L_24 ) ;
else if( strcmp ( V_44 , L_26 ) == 0 )
V_3 = F_17 ( V_1 , V_6 , V_16 , V_3 , & V_45 , L_24 ) ;
else
{
V_3 = F_8 ( V_1 , V_6 , V_16 , V_3 , L_24 ) ;
V_45 = ( char * ) V_50 ;
}
break;
case 'i' :
V_3 = F_7 ( V_1 , V_6 , V_16 , V_3 , & V_45 , L_24 ) ;
break;
default:
if( strcmp ( V_44 , L_27 ) == 0 )
{
V_3 = F_21 ( V_1 , V_6 , V_16 , V_3 , & V_45 , L_24 ) ;
}
else if( strcmp ( V_44 , L_28 ) == 0 )
{
int V_5 , V_51 ;
V_51 = V_3 ;
V_5 = F_1 ( V_1 , & V_3 ) ;
if( V_5 == 4 ) {
F_13 ( V_16 , V_33 , V_1 , V_3 , V_5 , V_34 ) ;
V_45 = ( char * ) F_19 ( V_1 , V_3 ) ;
V_3 += V_5 ;
}
else {
V_3 = F_4 ( V_1 , V_6 , V_16 , V_51 , & V_45 , TRUE , L_24 ) ;
}
}
else
{
V_9 = strcmp ( V_44 , L_29 ) == 0 || strcmp ( V_44 , L_30 ) == 0
|| strcmp ( V_44 , L_31 ) == 0 || strcmp ( V_44 , L_32 ) == 0
|| strcmp ( V_44 , L_33 ) == 0 || strcmp ( V_44 , L_34 ) == 0 ;
V_3 = F_4 ( V_1 , V_6 , V_16 , V_3 , & V_45 , V_9 , L_24 ) ;
}
}
if( strlen ( V_44 ) == 1 )
V_44 = ( char * ) F_23 ( V_44 [ 0 ] , V_52 , V_44 ) ;
if( strlen ( V_45 ) == 1 )
V_45 = ( char * ) F_23 ( V_45 [ 0 ] , V_53 , V_45 ) ;
F_14 ( V_15 , L_1 , V_44 , V_45 ) ;
F_24 ( V_15 , V_3 - V_46 ) ;
if( strcmp ( V_44 , L_35 ) == 0 || strcmp ( V_44 , L_36 ) == 0 )
F_15 ( V_6 -> V_25 , V_26 , L_37 , V_44 , V_45 ) ;
return V_3 ;
}
static int
F_11 ( T_1 * V_1 , T_3 * V_6 , T_5 * V_7 , T_2 V_3 , const char * V_10 )
{
T_7 * V_15 ;
T_5 * V_16 ;
T_2 V_46 = V_3 ;
if( V_3 == 0 )
{
V_15 = F_13 ( V_7 , V_54 , V_1 , 0 , - 1 , V_23 ) ;
V_16 = F_10 ( V_15 , V_55 ) ;
}
else
{
V_15 = F_9 ( V_7 , V_56 , V_1 , V_3 , - 1 , L_38 , V_10 ) ;
V_16 = F_10 ( V_15 , V_57 ) ;
}
V_3 += 1 ;
while( F_2 ( V_1 , V_3 ) != 'e' )
V_3 = F_22 ( V_1 , V_6 , V_16 , V_3 ) ;
V_3 += 1 ;
F_24 ( V_15 , V_3 - V_46 ) ;
return V_3 ;
}
static int
F_25 ( T_1 * V_1 , T_3 * V_6 , T_5 * V_7 , void * T_8 T_4 )
{
F_26 ( V_6 -> V_25 , V_58 , L_39 ) ;
F_27 ( V_6 -> V_25 , V_26 ) ;
return F_11 ( V_1 , V_6 , V_7 , 0 , L_40 ) ;
}
static
T_6 F_28 ( T_1 * V_1 , T_3 * V_6 ,
T_5 * V_7 , void * T_8 T_4 )
{
if( F_29 ( V_1 , 0 , L_41 , 3 ) == 0 )
{
int V_59 ;
T_9 V_44 = F_2 ( V_1 , 3 ) ;
for( V_59 = 0 ; V_52 [ V_59 ] . V_60 != 0 ; V_59 ++ )
{
if( V_52 [ V_59 ] . V_60 == V_44 )
{
T_10 * V_61 ;
V_61 = F_30 ( V_6 ) ;
F_31 ( V_61 , V_62 ) ;
F_25 ( V_1 , V_6 , V_7 , NULL ) ;
return TRUE ;
}
}
}
return FALSE ;
}
void
F_32 ( void )
{
static T_11 V_63 [] = {
{ & V_12 ,
{ L_6 , L_42 ,
V_64 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_18 ,
{ L_43 , L_44 ,
V_67 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_14 ,
{ L_45 , L_46 ,
V_64 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_56 ,
{ L_47 , L_48 ,
V_67 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_47 ,
{ L_49 , L_50 ,
V_67 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_22 ,
{ L_51 , L_52 ,
V_67 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_32 ,
{ L_53 , L_54 ,
V_67 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_30 ,
{ L_55 , L_56 ,
V_67 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_42 ,
{ L_57 , L_58 ,
V_67 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_40 ,
{ L_59 , L_60 ,
V_67 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_43 ,
{ L_61 , L_62 ,
V_68 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_33 ,
{ L_63 , L_64 ,
V_69 , V_65 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_35 ,
{ L_65 , L_66 ,
V_70 , V_71 , NULL , 0x0 , NULL , V_66 }
} ,
{ & V_36 ,
{ L_67 , L_68 ,
V_68 , V_65 , NULL , 0x0 , NULL , V_66 }
}
} ;
static T_12 * V_72 [] = {
& V_55 ,
& V_19 ,
& V_57 ,
& V_24 ,
& V_31 ,
& V_41 ,
& V_48
} ;
T_13 * V_73 ;
V_54 = F_33 (
L_40 ,
L_39 ,
L_69
) ;
V_73 = F_34 ( V_54 , V_74 ) ;
F_35 ( V_73 , L_70 , L_71 ,
L_72 ,
& V_75 ) ;
F_36 ( V_54 , V_63 , F_37 ( V_63 ) ) ;
F_38 ( V_72 , F_37 ( V_72 ) ) ;
}
void
V_74 ( void )
{
static T_6 V_76 = FALSE ;
if ( ! V_76 ) {
F_39 ( L_73 , F_28 , V_54 ) ;
V_62 = F_40 ( F_25 , V_54 ) ;
F_41 ( L_74 , V_62 ) ;
V_76 = TRUE ;
}
F_42 ( L_73 , F_28 , V_54 , V_75 ) ;
}
