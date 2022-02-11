static void
F_1 ( void * V_1 )
{
T_1 * V_2 = ( T_1 * ) V_1 ;
T_2 * V_3 = ( T_2 * ) V_2 -> V_4 ;
T_3 * V_5 ;
T_4 V_6 , V_7 ;
struct V_8 * V_9 ;
T_5 V_10 ;
printf ( L_1 ) ;
printf ( L_2 , V_3 -> type ) ;
printf ( L_3 , V_3 -> V_11 ? V_3 -> V_11 : L_4 ) ;
switch ( F_2 () ) {
case V_12 :
case V_13 :
printf ( L_5 ) ;
printf ( L_6 ) ;
break;
case V_14 :
case V_15 :
case V_16 :
case V_17 :
printf ( L_7 ) ;
printf ( L_8 ) ;
break;
case V_18 :
case V_19 :
default:
printf ( L_9 ) ;
printf ( L_6 ) ;
break;
}
V_7 = V_20 ;
do {
V_6 = 0 ;
for ( V_10 = 0 ; ( V_3 -> V_2 . V_21 && V_10 < V_3 -> V_2 . V_21 -> V_22 ) ; V_10 ++ ) {
T_4 V_23 ;
V_5 = & F_3 ( V_3 -> V_2 . V_21 , T_3 , V_10 ) ;
V_23 = V_5 -> V_24 + V_5 -> V_25 ;
if ( ( V_23 > V_6 ) && ( V_23 < V_7 ) ) {
V_6 = V_23 ;
}
}
for ( V_10 = 0 ; ( V_3 -> V_2 . V_21 && V_10 < V_3 -> V_2 . V_21 -> V_22 ) ; V_10 ++ ) {
T_4 V_23 ;
V_5 = & F_3 ( V_3 -> V_2 . V_21 , T_3 , V_10 ) ;
V_23 = V_5 -> V_24 + V_5 -> V_25 ;
if ( V_23 == V_6 ) {
printf ( L_10 V_26 L_11 V_26
L_12 V_26 L_11 V_26 L_12
V_26 L_11 V_26 L_13 ,
F_4 ( & V_5 -> V_27 , TRUE ) , F_4 ( & V_5 -> V_28 , TRUE ) ,
V_5 -> V_25 , V_5 -> V_29 ,
V_5 -> V_24 , V_5 -> V_30 ,
V_5 -> V_25 + V_5 -> V_24 ,
V_5 -> V_29 + V_5 -> V_30
) ;
switch ( F_2 () ) {
case V_12 :
V_9 = localtime ( & V_5 -> V_31 . V_32 ) ;
printf ( L_14 ,
V_9 -> V_33 ,
V_9 -> V_34 ,
V_9 -> V_35 ,
F_5 ( & V_5 -> V_36 ) - F_5 ( & V_5 -> V_37 ) ) ;
break;
case V_14 :
V_9 = localtime ( & V_5 -> V_31 . V_32 ) ;
printf ( L_15 ,
V_9 -> V_38 + 1900 ,
V_9 -> V_39 + 1 ,
V_9 -> V_40 ,
V_9 -> V_33 ,
V_9 -> V_34 ,
V_9 -> V_35 ,
F_5 ( & V_5 -> V_36 ) - F_5 ( & V_5 -> V_37 ) ) ;
break;
case V_15 :
V_9 = localtime ( & V_5 -> V_31 . V_32 ) ;
printf ( L_16 ,
V_9 -> V_38 + 1900 ,
V_9 -> V_41 + 1 ,
V_9 -> V_33 ,
V_9 -> V_34 ,
V_9 -> V_35 ,
F_5 ( & V_5 -> V_36 ) - F_5 ( & V_5 -> V_37 ) ) ;
break;
case V_13 :
V_9 = gmtime ( & V_5 -> V_31 . V_32 ) ;
printf ( L_14 ,
V_9 -> V_33 ,
V_9 -> V_34 ,
V_9 -> V_35 ,
F_5 ( & V_5 -> V_36 ) - F_5 ( & V_5 -> V_37 ) ) ;
break;
case V_16 :
V_9 = gmtime ( & V_5 -> V_31 . V_32 ) ;
printf ( L_15 ,
V_9 -> V_38 + 1900 ,
V_9 -> V_39 + 1 ,
V_9 -> V_40 ,
V_9 -> V_33 ,
V_9 -> V_34 ,
V_9 -> V_35 ,
F_5 ( & V_5 -> V_36 ) - F_5 ( & V_5 -> V_37 ) ) ;
break;
case V_17 :
V_9 = gmtime ( & V_5 -> V_31 . V_32 ) ;
printf ( L_16 ,
V_9 -> V_38 + 1900 ,
V_9 -> V_41 + 1 ,
V_9 -> V_33 ,
V_9 -> V_34 ,
V_9 -> V_35 ,
F_5 ( & V_5 -> V_36 ) - F_5 ( & V_5 -> V_37 ) ) ;
break;
case V_18 :
case V_19 :
default:
printf ( L_17 ,
F_5 ( & V_5 -> V_37 ) ,
F_5 ( & V_5 -> V_36 ) - F_5 ( & V_5 -> V_37 )
) ;
break;
}
}
}
V_7 = V_6 ;
} while( V_6 );
printf ( L_1 ) ;
}
void F_6 ( struct V_42 * V_43 , const char * V_11 )
{
T_2 * V_3 ;
T_6 * V_44 ;
V_3 = F_7 ( T_2 , 1 ) ;
V_3 -> type = F_8 ( F_9 ( F_10 ( V_43 ) ) ) ;
V_3 -> V_11 = F_11 ( V_11 ) ;
V_3 -> V_2 . V_4 = V_3 ;
V_44 = F_12 ( F_13 ( F_10 ( V_43 ) ) , & V_3 -> V_2 , V_11 , 0 , NULL , F_14 ( V_43 ) , F_1 ) ;
if( V_44 ) {
F_15 ( V_3 ) ;
fprintf ( V_45 , L_18 ,
V_44 -> V_46 ) ;
F_16 ( V_44 , TRUE ) ;
exit ( 1 ) ;
}
}
