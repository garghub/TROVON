static int
F_1 ( void * V_1 , T_1 * V_2 , T_2 * T_3 V_3 , const void * V_4 )
{
T_4 * V_5 = ( T_4 * ) V_1 ;
const T_5 * V_6 = V_4 ;
T_6 V_7 ;
int V_8 = 0 ;
switch ( V_6 -> V_9 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
if( V_6 -> V_19 ) {
V_5 -> V_20 ++ ;
}
else {
V_5 -> V_21 ++ ;
}
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
if( V_6 -> V_19 ) {
V_5 -> V_35 ++ ;
}
else if ( ! V_6 -> V_36 ) {
V_5 -> V_37 ++ ;
}
else {
V_5 -> V_21 -- ;
F_2 ( & V_7 , & V_2 -> V_38 -> V_39 , & V_6 -> V_40 ) ;
F_3 ( & ( V_5 -> V_41 [ V_42 ] ) , & V_7 , V_2 ) ;
if ( V_6 -> V_9 == V_22 || V_6 -> V_9 == V_23 ) {
F_3 ( & ( V_5 -> V_41 [ V_43 ] ) , & V_7 , V_2 ) ;
}
else if ( V_6 -> V_9 == V_24 ) {
F_3 ( & ( V_5 -> V_41 [ V_44 ] ) , & V_7 , V_2 ) ;
}
else {
F_3 ( & ( V_5 -> V_41 [ V_45 ] ) , & V_7 , V_2 ) ;
}
V_8 = 1 ;
}
break;
default:
break;
}
return V_8 ;
}
static void
F_4 ( void * V_1 )
{
T_4 * V_5 = ( T_4 * ) V_1 ;
int V_46 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 , V_5 -> V_47 ? V_5 -> V_47 : L_5 ) ;
printf ( L_6 , V_5 -> V_20 ) ;
printf ( L_7 , V_5 -> V_35 ) ;
printf ( L_8 , V_5 -> V_21 ) ;
printf ( L_9 , V_5 -> V_37 ) ;
printf ( L_10 ) ;
for( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
if( V_5 -> V_41 [ V_46 ] . V_49 ) {
printf ( L_11 ,
F_5 ( V_46 , V_50 , L_12 ) , V_5 -> V_41 [ V_46 ] . V_49 ,
F_6 ( & ( V_5 -> V_41 [ V_46 ] . V_51 ) ) , F_6 ( & ( V_5 -> V_41 [ V_46 ] . V_52 ) ) ,
F_7 ( & ( V_5 -> V_41 [ V_46 ] . V_53 ) , V_5 -> V_41 [ V_46 ] . V_49 ) ,
V_5 -> V_41 [ V_46 ] . V_54 , V_5 -> V_41 [ V_46 ] . V_55
) ;
}
}
printf ( L_2 ) ;
}
static void
F_8 ( const char * V_56 , void * T_7 V_3 )
{
T_4 * V_5 ;
int V_46 ;
T_8 * V_57 ;
V_5 = F_9 ( sizeof( T_4 ) ) ;
if( ! strncmp ( V_56 , L_13 , 11 ) ) {
V_5 -> V_47 = F_10 ( V_56 + 11 ) ;
} else {
V_5 -> V_47 = NULL ;
}
for( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
V_5 -> V_41 [ V_46 ] . V_49 = 0 ;
V_5 -> V_41 [ V_46 ] . V_54 = 0 ;
V_5 -> V_41 [ V_46 ] . V_55 = 0 ;
V_5 -> V_41 [ V_46 ] . V_51 . V_58 = 0 ;
V_5 -> V_41 [ V_46 ] . V_51 . V_59 = 0 ;
V_5 -> V_41 [ V_46 ] . V_52 . V_58 = 0 ;
V_5 -> V_41 [ V_46 ] . V_52 . V_59 = 0 ;
V_5 -> V_41 [ V_46 ] . V_53 . V_58 = 0 ;
V_5 -> V_41 [ V_46 ] . V_53 . V_59 = 0 ;
}
V_5 -> V_21 = 0 ;
V_5 -> V_37 = 0 ;
V_5 -> V_20 = 0 ;
V_5 -> V_35 = 0 ;
V_57 = F_11 ( L_14 , V_5 , V_5 -> V_47 , 0 , NULL , F_1 , F_4 ) ;
if( V_57 ) {
F_12 ( V_5 -> V_47 ) ;
F_12 ( V_5 ) ;
fprintf ( V_60 , L_15 ,
V_57 -> V_61 ) ;
F_13 ( V_57 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_14 ( void )
{
F_15 ( L_16 , F_8 , NULL ) ;
}
