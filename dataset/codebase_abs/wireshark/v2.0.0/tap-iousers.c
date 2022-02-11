static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_2 * V_3 = ( T_2 * ) V_2 -> V_4 ;
T_3 * V_5 ;
T_4 V_6 , V_7 ;
struct V_8 * V_9 ;
T_5 V_10 ;
T_6 V_11 = ( ! strncmp ( V_3 -> type , L_1 , 3 ) || ! strncmp ( V_3 -> type , L_2 , 3 ) || ! strncmp ( V_3 -> type , L_3 , 4 ) ) ? TRUE : FALSE ;
printf ( L_4 ) ;
printf ( L_5 , V_3 -> type ) ;
printf ( L_6 , V_3 -> V_12 ? V_3 -> V_12 : L_7 ) ;
switch ( F_2 () ) {
case V_13 :
case V_14 :
printf ( L_8 ,
V_11 ? L_9 : L_10 ) ;
printf ( L_11 ,
V_11 ? L_9 : L_10 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
printf ( L_12 ,
V_11 ? L_9 : L_10 ) ;
printf ( L_13 ,
V_11 ? L_9 : L_10 ) ;
break;
case V_19 :
case V_20 :
default:
printf ( L_14 ,
V_11 ? L_9 : L_10 ) ;
printf ( L_11 ,
V_11 ? L_9 : L_10 ) ;
break;
}
V_7 = V_21 ;
do {
V_6 = 0 ;
for ( V_10 = 0 ; ( V_3 -> V_2 . V_22 && V_10 < V_3 -> V_2 . V_22 -> V_23 ) ; V_10 ++ ) {
T_4 V_24 ;
V_5 = & F_3 ( V_3 -> V_2 . V_22 , T_3 , V_10 ) ;
V_24 = V_5 -> V_25 + V_5 -> V_26 ;
if ( ( V_24 > V_6 ) && ( V_24 < V_7 ) ) {
V_6 = V_24 ;
}
}
for ( V_10 = 0 ; ( V_3 -> V_2 . V_22 && V_10 < V_3 -> V_2 . V_22 -> V_23 ) ; V_10 ++ ) {
T_4 V_24 ;
char * V_27 , * V_28 ;
V_5 = & F_3 ( V_3 -> V_2 . V_22 , T_3 , V_10 ) ;
V_24 = V_5 -> V_25 + V_5 -> V_26 ;
if ( V_24 == V_6 ) {
V_27 = ( char * ) F_4 ( NULL , & V_5 -> V_29 , TRUE ) ;
V_28 = ( char * ) F_4 ( NULL , & V_5 -> V_30 , TRUE ) ;
if ( V_11 ) {
char * V_31 , * V_32 , * V_33 , * V_34 ;
V_33 = ( char * ) F_5 ( NULL , V_5 -> V_33 , V_5 -> V_35 , TRUE ) ;
V_34 = ( char * ) F_5 ( NULL , V_5 -> V_34 , V_5 -> V_35 , TRUE ) ;
V_31 = F_6 ( NULL , V_27 , L_15 , V_33 , NULL ) ;
V_32 = F_6 ( NULL , V_28 , L_15 , V_34 , NULL ) ;
printf ( L_16 V_36 L_17 V_36
L_18 V_36 L_17 V_36 L_18
V_36 L_17 V_36 L_19 ,
V_31 , V_32 ,
V_5 -> V_26 , V_5 -> V_37 ,
V_5 -> V_25 , V_5 -> V_38 ,
V_5 -> V_26 + V_5 -> V_25 ,
V_5 -> V_37 + V_5 -> V_38
) ;
F_7 ( NULL , V_33 ) ;
F_7 ( NULL , V_34 ) ;
F_7 ( NULL , V_31 ) ;
F_7 ( NULL , V_32 ) ;
} else {
printf ( L_20 V_36 L_17 V_36
L_18 V_36 L_17 V_36 L_18
V_36 L_17 V_36 L_19 ,
V_27 , V_28 ,
V_5 -> V_26 , V_5 -> V_37 ,
V_5 -> V_25 , V_5 -> V_38 ,
V_5 -> V_26 + V_5 -> V_25 ,
V_5 -> V_37 + V_5 -> V_38
) ;
}
F_7 ( NULL , V_27 ) ;
F_7 ( NULL , V_28 ) ;
switch ( F_2 () ) {
case V_13 :
V_9 = localtime ( & V_5 -> V_39 . V_40 ) ;
printf ( L_21 ,
V_9 -> V_41 ,
V_9 -> V_42 ,
V_9 -> V_43 ,
F_8 ( & V_5 -> V_44 ) - F_8 ( & V_5 -> V_45 ) ) ;
break;
case V_15 :
V_9 = localtime ( & V_5 -> V_39 . V_40 ) ;
printf ( L_22 ,
V_9 -> V_46 + 1900 ,
V_9 -> V_47 + 1 ,
V_9 -> V_48 ,
V_9 -> V_41 ,
V_9 -> V_42 ,
V_9 -> V_43 ,
F_8 ( & V_5 -> V_44 ) - F_8 ( & V_5 -> V_45 ) ) ;
break;
case V_16 :
V_9 = localtime ( & V_5 -> V_39 . V_40 ) ;
printf ( L_23 ,
V_9 -> V_46 + 1900 ,
V_9 -> V_49 + 1 ,
V_9 -> V_41 ,
V_9 -> V_42 ,
V_9 -> V_43 ,
F_8 ( & V_5 -> V_44 ) - F_8 ( & V_5 -> V_45 ) ) ;
break;
case V_14 :
V_9 = gmtime ( & V_5 -> V_39 . V_40 ) ;
printf ( L_21 ,
V_9 -> V_41 ,
V_9 -> V_42 ,
V_9 -> V_43 ,
F_8 ( & V_5 -> V_44 ) - F_8 ( & V_5 -> V_45 ) ) ;
break;
case V_17 :
V_9 = gmtime ( & V_5 -> V_39 . V_40 ) ;
printf ( L_22 ,
V_9 -> V_46 + 1900 ,
V_9 -> V_47 + 1 ,
V_9 -> V_48 ,
V_9 -> V_41 ,
V_9 -> V_42 ,
V_9 -> V_43 ,
F_8 ( & V_5 -> V_44 ) - F_8 ( & V_5 -> V_45 ) ) ;
break;
case V_18 :
V_9 = gmtime ( & V_5 -> V_39 . V_40 ) ;
printf ( L_23 ,
V_9 -> V_46 + 1900 ,
V_9 -> V_49 + 1 ,
V_9 -> V_41 ,
V_9 -> V_42 ,
V_9 -> V_43 ,
F_8 ( & V_5 -> V_44 ) - F_8 ( & V_5 -> V_45 ) ) ;
break;
case V_19 :
case V_20 :
default:
printf ( L_24 ,
F_8 ( & V_5 -> V_45 ) ,
F_8 ( & V_5 -> V_44 ) - F_8 ( & V_5 -> V_45 )
) ;
break;
}
}
}
V_7 = V_6 ;
} while ( V_6 );
printf ( L_4 ) ;
}
void F_9 ( struct V_50 * V_51 , const char * V_12 )
{
T_2 * V_3 ;
T_7 * V_52 ;
V_3 = F_10 ( T_2 , 1 ) ;
V_3 -> type = F_11 ( F_12 ( F_13 ( V_51 ) ) ) ;
V_3 -> V_12 = F_14 ( V_12 ) ;
V_3 -> V_2 . V_4 = V_3 ;
V_52 = F_15 ( F_16 ( F_13 ( V_51 ) ) , & V_3 -> V_2 , V_12 , 0 , NULL , F_17 ( V_51 ) , F_1 ) ;
if ( V_52 ) {
F_18 ( V_3 ) ;
fprintf ( V_53 , L_25 ,
V_52 -> V_54 ) ;
F_19 ( V_52 , TRUE ) ;
exit ( 1 ) ;
}
}
