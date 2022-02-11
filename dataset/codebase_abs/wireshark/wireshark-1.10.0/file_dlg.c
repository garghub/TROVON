T_1 *
F_1 ( const T_2 * V_1 , T_3 * V_2 ,
T_4 V_3 )
{
T_1 * V_4 ;
T_5 V_5 ;
#ifdef F_2
char * V_6 ;
#endif
const T_2 * V_7 ;
switch ( V_3 ) {
case V_8 :
V_5 = V_9 ;
V_7 = V_10 ;
break;
case V_11 :
V_5 = V_9 ;
V_7 = V_12 ;
break;
case V_13 :
V_5 = V_14 ;
V_7 = V_15 ;
break;
case V_16 :
V_5 = V_14 ;
V_7 = V_12 ;
break;
case V_17 :
V_5 = V_18 ;
V_7 = V_12 ;
break;
default:
F_3 () ;
V_5 = ( T_5 ) - 1 ;
V_7 = NULL ;
break;
}
V_4 = F_4 ( V_1 , V_2 , V_5 ,
V_19 , V_20 ,
V_7 , V_21 ,
NULL ) ;
F_5 ( F_6 ( V_4 ) ,
V_21 ,
V_20 ,
- 1 ) ;
if ( V_3 == V_13 )
F_7 ( F_8 ( V_4 ) , TRUE ) ;
if ( V_22 )
F_9 ( V_4 , V_22 ) ;
#ifdef F_2
else {
V_6 = F_10 ( L_1 ) ;
if( V_6 != NULL )
F_9 ( V_4 , V_6 ) ;
}
#endif
return V_4 ;
}
T_6
F_9 ( T_1 * V_23 , const T_2 * V_24 )
{
T_6 V_25 ;
T_7 V_26 = strlen ( V_24 ) ;
T_2 * V_27 ;
if ( V_24 [ V_26 - 1 ] == V_28
#ifdef F_2
&& V_26 > 3 )
#else
&& V_26 > 1 )
#endif
{
V_27 = F_11 ( V_24 ) ;
V_27 [ V_26 - 1 ] = '\0' ;
} else {
V_27 = F_11 ( V_24 ) ;
}
ret = gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(fs
static T_2 * F_12 ( const T_2 * V_29 )
{
T_8 V_30 ;
T_9 * V_31 ;
T_10 * V_32 ;
T_11 * V_33 ;
T_11 V_34 [ V_35 ] ;
T_2 * V_36 = NULL ;
V_34 [ 0 ] = 0L ;
F_13 ( NULL ) ;
if ( V_37 == F_14 ( & V_38 , NULL , V_39 ,
& V_40 , ( void * * ) & V_31 ) ) {
if ( V_37 == F_15 ( V_31 , & V_41 ,
( void * * ) & V_32 ) ) {
V_33 = F_16 ( V_29 , - 1 , NULL , NULL , NULL ) ;
if ( V_37 == F_17 ( V_32 , V_33 , V_42 ) ) {
if ( V_37 == F_18 ( V_31 , V_34 , V_35 , & V_30 ,
V_43 ) ) {
V_36 = F_19 ( V_34 , - 1 , NULL , NULL , NULL ) ;
}
}
F_20 ( V_32 ) ;
F_21 ( V_33 ) ;
}
F_22 ( V_31 ) ;
}
F_23 () ;
return V_36 ;
}
T_2 *
F_24 ( T_1 * V_23 )
{
T_2 * V_44 ;
#ifdef F_2
T_2 * V_36 ;
const T_2 * V_45 ;
#endif
for (; ; ) {
if ( F_25 ( F_6 ( V_23 ) ) != V_21 ) {
F_26 ( V_23 ) ;
return NULL ;
}
V_44 = F_27 ( F_8 ( V_23 ) ) ;
if ( F_28 ( V_44 ) == V_46 ) {
F_29 ( V_44 ) ;
F_21 ( V_44 ) ;
F_9 ( V_23 , F_30 () ) ;
continue;
}
#ifdef F_2
if ( ( V_45 = strrchr ( V_44 , '.' ) ) && F_31 ( V_45 , L_2 ) == 0 ) {
V_36 = F_12 ( V_44 ) ;
if ( V_36 != NULL ) {
F_21 ( V_44 ) ;
if ( F_28 ( V_36 ) ) {
F_29 ( V_36 ) ;
F_21 ( V_36 ) ;
F_9 ( V_23 , F_30 () ) ;
continue;
}
V_44 = V_36 ;
}
}
#endif
break;
}
return V_44 ;
}
T_6
F_32 ( T_1 * V_47 , char * V_44 )
{
T_1 * V_48 ;
T_2 * V_49 ;
T_12 V_50 ;
T_13 V_51 ;
if ( F_33 ( V_44 , & V_51 ) == - 1 ) {
return TRUE ;
}
#ifdef F_34
if ( V_51 . V_52 & V_53 ) {
V_49 = F_35 ( V_44 ) ;
V_48 = F_36 ( F_37 ( V_47 ) ,
V_54 | V_55 ,
V_56 ,
V_57 ,
#ifdef F_38
L_3 ,
#else
L_4 ,
#endif
V_49 ) ;
F_21 ( V_49 ) ;
} else
#endif
if ( ( V_51 . V_58 & ( V_59 | V_60 | V_61 ) ) == 0 ) {
V_49 = F_35 ( V_44 ) ;
V_48 = F_36 ( F_37 ( V_47 ) ,
( V_62 ) ( V_54 | V_55 ) ,
V_56 ,
V_57 ,
L_5 ,
V_49 ) ;
F_21 ( V_49 ) ;
} else {
V_48 = NULL ;
}
if ( V_48 != NULL ) {
F_39 ( F_40 ( V_48 ) ,
L_6 ) ;
F_41 ( F_6 ( V_48 ) ,
L_7 , V_21 ,
L_8 , V_63 ,
NULL ) ;
F_42 ( F_6 ( V_48 ) , V_63 ) ;
V_50 = F_25 ( F_6 ( V_48 ) ) ;
F_43 ( V_48 ) ;
if ( V_50 != V_21 ) {
return FALSE ;
}
#ifdef F_34
if ( V_51 . V_52 & V_53 ) {
F_44 ( V_44 , V_51 . V_52 & ~ V_53 ) ;
}
#endif
}
return TRUE ;
}
void
F_45 ( T_1 * V_64 , T_1 * V_65 , const char * V_66 , T_4 V_3 )
{
T_1 * V_67 = F_46 ( V_64 ) ;
T_1 * V_23 ;
T_2 * V_68 ;
V_23 = F_1 ( V_66 , F_37 ( V_67 ) , V_3 ) ;
F_47 ( F_48 ( V_23 ) , V_69 , V_65 ) ;
F_47 ( F_48 ( V_23 ) , V_70 , V_67 ) ;
F_47 ( F_48 ( V_67 ) , V_71 , V_23 ) ;
F_49 ( V_23 , L_9 , F_50 ( V_72 ) ,
V_65 ) ;
if ( F_25 ( F_6 ( V_23 ) ) == V_21 )
{
V_68 = F_27 ( F_8 ( V_23 ) ) ;
F_51 ( F_52 ( V_65 ) , V_68 ) ;
F_21 ( V_68 ) ;
}
F_26 ( V_23 ) ;
}
static void
V_72 ( T_1 * V_4 , T_1 * V_73 )
{
T_1 * V_67 ;
V_67 = ( T_1 * ) F_53 ( F_48 ( V_4 ) , V_70 ) ;
F_47 ( F_48 ( V_67 ) , V_71 , NULL ) ;
F_54 ( V_73 ) ;
}
void
F_29 ( const char * V_74 )
{
T_7 V_75 ;
T_2 * V_76 ;
if ( V_74 ) {
V_75 = strlen ( V_74 ) ;
if ( V_74 [ V_75 - 1 ] == V_28 ) {
V_76 = F_55 ( V_74 , NULL ) ;
}
else {
V_76 = F_55 ( V_74 ,
V_77 , NULL ) ;
}
if ( V_22 == NULL ||
strcmp ( V_22 , V_76 ) != 0 )
V_78 = TRUE ;
}
else {
V_76 = NULL ;
if ( V_22 != NULL )
V_78 = TRUE ;
}
F_21 ( V_22 ) ;
V_22 = V_76 ;
}
char *
F_30 ( void )
{
return V_22 ;
}
