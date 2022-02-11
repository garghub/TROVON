T_1 *
F_1 ( const T_2 * V_1 , T_3 * V_2 ,
T_4 V_3 )
{
T_1 * V_4 ;
T_5 V_5 ;
const T_2 * V_6 ;
switch ( V_3 ) {
case V_7 :
V_5 = V_8 ;
V_6 = V_9 ;
break;
case V_10 :
V_5 = V_8 ;
V_6 = V_11 ;
break;
case V_12 :
V_5 = V_13 ;
V_6 = V_14 ;
break;
case V_15 :
V_5 = V_13 ;
V_6 = V_11 ;
break;
case V_16 :
V_5 = V_17 ;
V_6 = V_11 ;
break;
default:
F_2 () ;
V_5 = ( T_5 ) - 1 ;
V_6 = NULL ;
break;
}
V_4 = F_3 ( V_1 , V_2 , V_5 ,
V_18 , V_19 ,
V_6 , V_20 ,
NULL ) ;
F_4 ( F_5 ( V_4 ) ,
V_20 ,
V_19 ,
- 1 ) ;
if ( V_3 == V_12 )
F_6 ( F_7 ( V_4 ) , TRUE ) ;
if ( V_21 ) {
F_8 ( V_4 , V_21 ) ;
}
return V_4 ;
}
T_6
F_8 ( T_1 * V_22 , const T_2 * V_23 )
{
T_6 V_24 ;
T_7 V_25 = strlen ( V_23 ) ;
T_2 * V_26 ;
if ( V_23 [ V_25 - 1 ] == V_27
#ifdef F_9
&& V_25 > 3 )
#else
&& V_25 > 1 )
#endif
{
V_26 = F_10 ( V_23 ) ;
V_26 [ V_25 - 1 ] = '\0' ;
} else {
V_26 = F_10 ( V_23 ) ;
}
ret = gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(fs
static T_2 * F_11 ( const T_2 * V_28 )
{
T_8 V_29 ;
T_9 * V_30 ;
T_10 * V_31 ;
T_11 * V_32 ;
T_11 V_33 [ V_34 ] ;
T_2 * V_35 = NULL ;
V_33 [ 0 ] = 0L ;
F_12 ( NULL ) ;
if ( V_36 == F_13 ( & V_37 , NULL , V_38 ,
& V_39 , ( void * * ) & V_30 ) ) {
if ( V_36 == F_14 ( V_30 , & V_40 ,
( void * * ) & V_31 ) ) {
V_32 = F_15 ( V_28 , - 1 , NULL , NULL , NULL ) ;
if ( V_36 == F_16 ( V_31 , V_32 , V_41 ) ) {
if ( V_36 == F_17 ( V_30 , V_33 , V_34 , & V_29 ,
V_42 ) ) {
V_35 = F_18 ( V_33 , - 1 , NULL , NULL , NULL ) ;
}
}
F_19 ( V_31 ) ;
F_20 ( V_32 ) ;
}
F_21 ( V_30 ) ;
}
F_22 () ;
return V_35 ;
}
T_2 *
F_23 ( T_1 * V_22 )
{
T_2 * V_43 ;
#ifdef F_9
T_2 * V_35 ;
const T_2 * V_44 ;
#endif
for (; ; ) {
if ( F_24 ( F_5 ( V_22 ) ) != V_20 ) {
F_25 ( V_22 ) ;
return NULL ;
}
V_43 = F_26 ( F_7 ( V_22 ) ) ;
if ( F_27 ( V_43 ) == V_45 ) {
F_28 ( V_43 ) ;
F_20 ( V_43 ) ;
F_8 ( V_22 , F_29 () ) ;
continue;
}
#ifdef F_9
if ( ( V_44 = strrchr ( V_43 , '.' ) ) && F_30 ( V_44 , L_1 ) == 0 ) {
V_35 = F_11 ( V_43 ) ;
if ( V_35 != NULL ) {
F_20 ( V_43 ) ;
if ( F_27 ( V_35 ) ) {
F_28 ( V_35 ) ;
F_20 ( V_35 ) ;
F_8 ( V_22 , F_29 () ) ;
continue;
}
V_43 = V_35 ;
}
}
#endif
break;
}
return V_43 ;
}
T_6
F_31 ( T_1 * V_46 , char * V_43 )
{
T_1 * V_47 ;
T_2 * V_48 ;
T_12 V_49 ;
T_13 V_50 ;
if ( F_32 ( V_43 , & V_50 ) == - 1 ) {
return TRUE ;
}
#ifdef F_33
if ( V_50 . V_51 & V_52 ) {
V_48 = F_34 ( V_43 ) ;
V_47 = F_35 ( F_36 ( V_46 ) ,
( V_53 ) ( V_54 | V_55 ) ,
V_56 ,
V_57 ,
#ifdef F_37
L_2 ,
#else
L_3 ,
#endif
V_48 ) ;
F_20 ( V_48 ) ;
} else
#endif
if ( ( V_50 . V_58 & ( V_59 | V_60 | V_61 ) ) == 0 ) {
V_48 = F_34 ( V_43 ) ;
V_47 = F_35 ( F_36 ( V_46 ) ,
( V_53 ) ( V_54 | V_55 ) ,
V_56 ,
V_57 ,
L_4 ,
V_48 ) ;
F_20 ( V_48 ) ;
} else {
V_47 = NULL ;
}
if ( V_47 != NULL ) {
F_38 ( F_39 ( V_47 ) ,
L_5 ) ;
F_40 ( F_5 ( V_47 ) ,
L_6 , V_20 ,
L_7 , V_62 ,
NULL ) ;
F_41 ( F_5 ( V_47 ) , V_62 ) ;
V_49 = F_24 ( F_5 ( V_47 ) ) ;
F_42 ( V_47 ) ;
if ( V_49 != V_20 ) {
return FALSE ;
}
#ifdef F_33
if ( V_50 . V_51 & V_52 ) {
F_43 ( V_43 , V_50 . V_51 & ~ V_52 ) ;
}
#endif
}
return TRUE ;
}
void
F_44 ( T_1 * V_63 , T_1 * V_64 , const char * V_65 , T_4 V_3 )
{
T_1 * V_66 = F_45 ( V_63 ) ;
T_1 * V_22 ;
T_2 * V_67 ;
V_22 = F_1 ( V_65 , F_36 ( V_66 ) , V_3 ) ;
F_46 ( F_47 ( V_22 ) , V_68 , V_64 ) ;
F_46 ( F_47 ( V_22 ) , V_69 , V_66 ) ;
F_46 ( F_47 ( V_66 ) , V_70 , V_22 ) ;
F_48 ( V_22 , L_8 , F_49 ( V_71 ) ,
V_64 ) ;
if ( F_24 ( F_5 ( V_22 ) ) == V_20 )
{
V_67 = F_26 ( F_7 ( V_22 ) ) ;
F_50 ( F_51 ( V_64 ) , V_67 ) ;
F_20 ( V_67 ) ;
}
F_25 ( V_22 ) ;
}
static void
V_71 ( T_1 * V_4 , T_1 * V_72 )
{
T_1 * V_66 ;
V_66 = ( T_1 * ) F_52 ( F_47 ( V_4 ) , V_69 ) ;
F_46 ( F_47 ( V_66 ) , V_70 , NULL ) ;
F_53 ( V_72 ) ;
}
void
F_28 ( const char * V_73 )
{
T_7 V_74 ;
T_2 * V_75 ;
if ( V_73 && V_73 [ 0 ] ) {
V_74 = strlen ( V_73 ) ;
if ( V_73 [ V_74 - 1 ] == V_27 ) {
V_75 = F_54 ( V_73 , NULL ) ;
}
else {
V_75 = F_54 ( V_73 ,
V_76 , NULL ) ;
}
} else {
V_75 = NULL ;
}
F_20 ( V_21 ) ;
V_21 = V_75 ;
}
char *
F_29 ( void )
{
return V_21 ;
}
