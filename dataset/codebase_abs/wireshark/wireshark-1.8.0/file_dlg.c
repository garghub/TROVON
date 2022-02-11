T_1 *
F_1 ( const T_2 * V_1 , T_3 V_2 )
{
T_1 * V_3 ;
T_4 V_4 ;
#ifdef F_2
char * V_5 ;
#endif
const T_2 * V_6 ;
switch ( V_2 ) {
case V_7 :
V_4 = V_8 ;
V_6 = V_9 ;
break;
case V_10 :
V_4 = V_8 ;
V_6 = V_11 ;
break;
case V_12 :
V_4 = V_13 ;
V_6 = V_14 ;
break;
case V_15 :
V_4 = V_13 ;
V_6 = V_11 ;
break;
case V_16 :
V_4 = V_17 ;
V_6 = V_11 ;
break;
default:
F_3 () ;
V_4 = - 1 ;
V_6 = NULL ;
break;
}
V_3 = F_4 ( V_1 , F_5 ( V_18 ) , V_4 ,
#ifndef F_2
V_19 , V_20 ,
V_6 , V_21 ,
#else
V_6 , V_21 ,
V_19 , V_20 ,
#endif
NULL ) ;
if ( V_22 )
F_6 ( V_3 , V_22 ) ;
#ifdef F_2
else {
V_5 = F_7 ( L_1 ) ;
if( V_5 != NULL )
F_6 ( V_3 , V_5 ) ;
}
#endif
return V_3 ;
}
T_5
F_6 ( T_1 * V_23 , const T_2 * V_24 )
{
T_5 V_25 ;
T_6 V_26 = strlen ( V_24 ) ;
T_2 * V_27 ;
if ( V_24 [ V_26 - 1 ] == V_28
#ifdef F_2
&& V_26 > 3 )
#else
&& V_26 > 1 )
#endif
{
V_27 = F_8 ( V_24 ) ;
V_27 [ V_26 - 1 ] = '\0' ;
} else {
V_27 = F_8 ( V_24 ) ;
}
ret = gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(fs
T_5
F_9 ( T_1 * V_29 , char * V_30 )
{
T_1 * V_31 ;
T_2 * V_32 ;
T_7 V_33 ;
T_8 V_34 ;
if ( F_10 ( V_30 , & V_34 ) == - 1 ) {
return TRUE ;
}
#ifdef F_11
if ( V_34 . V_35 & V_36 ) {
V_32 = F_12 ( V_30 ) ;
V_31 = F_13 ( F_5 ( V_29 ) ,
V_37 | V_38 ,
V_39 ,
V_40 ,
#ifdef F_14
L_2 ,
#else
L_3 ,
#endif
V_32 ) ;
F_15 ( V_32 ) ;
} else
#endif
if ( ( V_34 . V_41 & ( V_42 | V_43 | V_44 ) ) == 0 ) {
V_32 = F_12 ( V_30 ) ;
V_31 = F_13 ( F_5 ( V_29 ) ,
V_37 | V_38 ,
V_39 ,
V_40 ,
L_4 ,
V_32 ) ;
F_15 ( V_32 ) ;
} else {
V_31 = NULL ;
}
if ( V_31 != NULL ) {
F_16 ( F_17 ( V_31 ) ,
L_5 ) ;
F_18 ( F_19 ( V_31 ) ,
L_6 , V_21 ,
L_7 , V_45 ,
NULL ) ;
F_20 ( F_19 ( V_31 ) , V_45 ) ;
V_33 = F_21 ( F_19 ( V_31 ) ) ;
F_22 ( V_31 ) ;
if ( V_33 != V_21 ) {
return FALSE ;
}
#ifdef F_11
if ( V_34 . V_35 & V_36 ) {
F_23 ( V_30 , V_34 . V_35 & ~ V_36 ) ;
}
#endif
}
return TRUE ;
}
void
F_24 ( T_1 * V_46 , T_1 * V_47 , const char * V_48 , T_3 V_2 )
{
T_1 * V_49 = F_25 ( V_46 ) ;
T_1 * V_23 ;
T_2 * V_50 ;
V_23 = F_26 ( F_27 ( V_49 ) , V_51 ) ;
if ( V_23 != NULL ) {
F_28 ( V_23 ) ;
return;
}
V_23 = F_1 ( V_48 , V_2 ) ;
F_29 ( F_27 ( V_23 ) , V_52 , V_47 ) ;
F_29 ( F_27 ( V_23 ) , V_53 , V_49 ) ;
F_29 ( F_27 ( V_49 ) , V_51 , V_23 ) ;
F_30 ( V_23 , L_8 , F_31 ( V_54 ) ,
V_47 ) ;
if ( F_21 ( F_19 ( V_23 ) ) == V_21 )
{
V_50 = F_32 ( F_33 ( V_23 ) ) ;
F_34 ( F_35 ( V_47 ) , V_50 ) ;
F_15 ( V_50 ) ;
}
F_36 ( V_23 ) ;
}
static void
V_54 ( T_1 * V_3 , T_1 * V_55 )
{
T_1 * V_49 ;
V_49 = F_26 ( F_27 ( V_3 ) , V_53 ) ;
F_29 ( F_27 ( V_49 ) , V_51 , NULL ) ;
F_37 ( V_55 ) ;
}
void
F_38 ( const char * V_56 )
{
T_6 V_57 ;
T_2 * V_58 ;
if ( V_56 ) {
V_57 = strlen ( V_56 ) ;
if ( V_56 [ V_57 - 1 ] == V_28 ) {
V_58 = F_39 ( V_56 , NULL ) ;
}
else {
V_58 = F_39 ( V_56 ,
V_59 , NULL ) ;
}
if ( V_22 == NULL ||
strcmp ( V_22 , V_58 ) != 0 )
V_60 = TRUE ;
}
else {
V_58 = NULL ;
if ( V_22 != NULL )
V_60 = TRUE ;
}
F_15 ( V_22 ) ;
V_22 = V_58 ;
}
char *
F_40 ( void )
{
return V_22 ;
}
