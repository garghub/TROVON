void
F_1 ( T_1 * V_1 , const char * V_2 ,
T_2 V_3 )
{
T_3 * V_4 ;
const T_3 * V_5 = NULL ;
F_2 ( V_1 -> V_6 , V_1 -> V_7 , NULL ) ;
V_4 = F_3 ( L_1 , V_2 ) ;
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
break;
case V_12 :
V_5 = V_13 ;
break;
case V_14 :
V_5 = V_15 ;
break;
case V_16 :
V_5 = V_17 ;
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
break;
case V_22 :
break;
}
F_4 (
F_5 ( V_3 ) ,
V_2 ,
V_5 ,
V_4 ,
NULL ,
NULL ,
V_23 ,
V_1 ,
TRUE ,
NULL ,
NULL ) ;
}
void F_6 ( void )
{
T_4 * V_24 = V_25 ;
char * V_26 ;
char * V_27 ;
while( V_24 != NULL ) {
if( V_24 -> V_28 ) {
V_26 = F_7 ( & V_29 ) ;
V_27 = F_3 ( L_2 , V_24 -> V_30 . V_31 , V_26 ) ;
F_8 ( V_26 ) ;
F_9 ( F_10 ( V_24 -> V_28 ) , V_27 ) ;
F_8 ( V_27 ) ;
}
V_24 = V_24 -> V_32 ;
}
}
static void
F_11 ( T_5 * T_6 V_33 , T_7 V_34 )
{
T_4 * V_35 = ( T_4 * ) V_34 ;
V_35 -> V_28 = NULL ;
}
static void
F_12 ( T_5 * T_6 V_33 , T_7 V_34 )
{
T_8 * V_36 ;
T_9 V_37 ;
T_10 V_38 ;
T_11 V_39 ;
T_4 * V_35 = ( T_4 * ) V_34 ;
V_36 = F_13 ( V_35 -> V_30 . V_6 ) ;
for( V_37 = 0 ; V_37 < V_35 -> V_30 . V_40 ; V_37 ++ ) {
F_14 ( V_36 , ',' ) ;
switch ( V_35 -> V_30 . V_36 [ V_37 ] . type ) {
case V_41 :
V_39 = F_15 ( F_16 ( V_35 -> V_42 [ V_37 ] ) ) ;
F_17 ( V_36 , L_3 ,
V_35 -> V_30 . V_36 [ V_37 ] . V_43 [ V_39 ] . V_44 ) ;
break;
case V_45 :
V_38 = F_18 ( F_19 ( V_35 -> V_42 [ V_37 ] ) ) ;
F_17 ( V_36 , L_4 , ( V_46 ) V_38 ) ;
break;
case V_47 :
case V_48 :
F_20 ( V_36 ,
F_21 ( F_22 ( V_35 -> V_42 [ V_37 ] ) ) ) ;
break;
}
}
( V_35 -> V_30 . V_7 ) ( V_36 -> V_49 , NULL ) ;
F_23 ( V_36 , TRUE ) ;
}
void
V_23 ( T_12 * T_13 V_33 , T_7 V_50 )
{
const char * V_51 ;
char * V_26 ;
char * V_27 ;
T_5 * V_52 ;
T_5 * V_53 , * T_6 , * V_54 , * V_55 ;
T_5 * V_56 , * V_57 , * V_58 ;
T_9 V_37 , V_39 ;
char * V_59 ;
T_1 * V_35 = ( T_1 * ) V_50 ;
if( V_35 == NULL )
return;
if( V_35 -> V_60 == - 1 ) {
if( V_25 == NULL ) {
V_25 = ( T_4 * ) F_24 ( sizeof ( T_4 ) ) ;
V_61 = V_25 ;
V_61 -> V_30 . V_60 = 0 ;
} else {
V_61 -> V_32 = ( T_4 * ) F_24 ( sizeof ( T_4 ) ) ;
V_61 -> V_32 -> V_30 . V_60 = V_61 -> V_30 . V_60 + 1 ;
V_61 = V_61 -> V_32 ;
}
V_61 -> V_28 = NULL ;
V_61 -> V_42 = ( T_5 * * ) F_24 ( V_35 -> V_40 * sizeof ( T_5 * ) ) ;
V_61 -> V_30 . V_31 = V_35 -> V_31 ;
V_61 -> V_30 . V_6 = V_35 -> V_6 ;
V_61 -> V_30 . V_7 = V_35 -> V_7 ;
V_61 -> V_30 . V_40 = V_35 -> V_40 ;
V_61 -> V_30 . V_36 = V_35 -> V_36 ;
V_61 -> args . V_27 = F_3 ( L_5 , V_35 -> V_31 ) ;
V_61 -> args . V_62 = TRUE ;
V_61 -> args . V_63 = FALSE ;
V_61 -> args . V_64 = FALSE ;
V_61 -> V_32 = NULL ;
V_35 -> V_60 = V_61 -> V_30 . V_60 ;
V_65 = V_61 ;
} else {
V_65 = V_25 ;
while( V_35 -> V_60 != V_65 -> V_30 . V_60 )
{
if( V_65 -> V_32 == NULL ) {
return;
}
V_65 = V_65 -> V_32 ;
}
}
if( V_65 -> V_28 ) {
F_25 ( F_26 ( V_65 -> V_28 ) ) ;
return;
}
V_26 = F_7 ( & V_29 ) ;
V_27 = F_3 ( L_2 , V_65 -> V_30 . V_31 , V_26 ) ;
F_8 ( V_26 ) ;
V_65 -> V_28 = F_27 ( V_27 ) ;
F_28 ( F_10 ( V_65 -> V_28 ) , 300 , - 1 ) ;
F_8 ( V_27 ) ;
V_52 = F_29 ( V_66 , 10 , FALSE ) ;
F_30 ( F_31 ( V_52 ) , 10 ) ;
F_32 ( F_31 ( V_65 -> V_28 ) , V_52 ) ;
F_33 ( V_52 ) ;
for( V_37 = 0 ; V_37 < V_65 -> V_30 . V_40 ; V_37 ++ ) {
V_53 = F_29 ( V_67 , 3 , FALSE ) ;
switch ( V_65 -> V_30 . V_36 [ V_37 ] . type ) {
case V_45 :
V_59 = F_3 ( L_6 , V_65 -> V_30 . V_36 [ V_37 ] . V_27 ) ;
V_54 = F_34 ( V_59 ) ;
F_8 ( V_59 ) ;
F_35 ( F_36 ( V_53 ) , V_54 , FALSE , TRUE , 0 ) ;
F_33 ( V_54 ) ;
T_6 = F_37 ( 0 , V_68 , 1 ) ;
F_38 ( F_19 ( T_6 ) , TRUE ) ;
break;
case V_47 :
V_59 = F_3 ( L_6 , V_65 -> V_30 . V_36 [ V_37 ] . V_27 ) ;
V_54 = F_34 ( V_59 ) ;
F_8 ( V_59 ) ;
F_35 ( F_36 ( V_53 ) , V_54 , FALSE , TRUE , 0 ) ;
F_33 ( V_54 ) ;
T_6 = F_39 () ;
break;
case V_41 :
V_59 = F_3 ( L_6 , V_65 -> V_30 . V_36 [ V_37 ] . V_27 ) ;
V_54 = F_34 ( V_59 ) ;
F_8 ( V_59 ) ;
F_35 ( F_36 ( V_53 ) , V_54 , FALSE , TRUE , 0 ) ;
F_33 ( V_54 ) ;
T_6 = F_40 () ;
for ( V_39 = 0 ; V_65 -> V_30 . V_36 [ V_37 ] . V_43 [ V_39 ] . V_2 != NULL ;
V_39 ++ )
F_41 ( F_42 ( T_6 ) ,
V_65 -> V_30 . V_36 [ V_37 ] . V_43 [ V_39 ] . V_69 ) ;
F_43 ( F_16 ( T_6 ) , 0 ) ;
break;
case V_48 :
V_55 = F_44 ( V_70 ) ;
F_45 ( V_55 , L_7 , F_46 ( V_71 ) , & ( V_65 -> args ) ) ;
F_35 ( F_36 ( V_53 ) , V_55 , FALSE , TRUE , 0 ) ;
F_33 ( V_55 ) ;
T_6 = F_39 () ;
F_45 ( T_6 , L_8 , F_46 ( V_72 ) , NULL ) ;
F_47 ( F_48 ( V_53 ) , V_73 , NULL ) ;
F_45 ( T_6 , L_9 , F_46 ( V_74 ) , NULL ) ;
F_45 ( V_65 -> V_28 , L_9 , F_46 ( V_75 ) , NULL ) ;
F_47 ( F_48 ( V_55 ) , V_76 , T_6 ) ;
V_51 = F_21 ( F_22 ( V_77 ) ) ;
if( V_51 ) {
F_49 ( F_22 ( T_6 ) , V_51 ) ;
} else {
F_50 ( T_6 ) ;
}
break;
default:
F_51 () ;
T_6 = NULL ;
break;
}
F_35 ( F_36 ( V_53 ) , T_6 , TRUE , TRUE , 0 ) ;
V_65 -> V_42 [ V_37 ] = T_6 ;
F_33 ( T_6 ) ;
F_35 ( F_36 ( V_52 ) , V_53 , TRUE , TRUE , 0 ) ;
F_33 ( V_53 ) ;
}
V_56 = F_52 ( V_78 , V_79 , NULL ) ;
F_35 ( F_36 ( V_52 ) , V_56 , FALSE , FALSE , 0 ) ;
F_33 ( V_56 ) ;
V_57 = ( T_5 * ) F_53 ( F_48 ( V_56 ) , V_78 ) ;
F_45 ( V_57 , L_7 ,
F_46 ( F_12 ) , V_65 ) ;
V_58 = ( T_5 * ) F_53 ( F_48 ( V_56 ) , V_79 ) ;
F_54 ( V_65 -> V_28 , V_58 , V_80 ) ;
for( V_37 = 0 ; V_37 < V_65 -> V_30 . V_40 ; V_37 ++ ) {
switch ( V_65 -> V_30 . V_36 [ V_37 ] . type ) {
case V_45 :
case V_41 :
break;
case V_47 :
case V_48 :
F_55 ( V_65 -> V_42 [ V_37 ] , V_57 ) ;
break;
}
}
if( V_65 -> V_30 . V_40 > 0 ) {
F_56 ( V_65 -> V_42 [ 0 ] ) ;
}
F_57 ( V_57 ) ;
F_45 ( V_65 -> V_28 , L_10 , F_46 ( V_81 ) , NULL ) ;
F_45 ( V_65 -> V_28 , L_11 , F_46 ( F_11 ) , V_65 ) ;
F_58 ( V_65 -> V_28 ) ;
F_59 ( V_65 -> V_28 ) ;
}
