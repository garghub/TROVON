T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 = NULL ;
#ifndef F_2
T_3 * V_3 = NULL ;
#endif
#ifndef F_3
T_4 * V_4 = NULL ;
T_5 * V_5 ;
T_6 * V_6 , * V_7 , * V_8 = NULL ;
T_7 * V_9 = NULL ;
T_8 * V_10 = NULL ;
int V_11 ;
#endif
T_9 * V_12 ;
unsigned char * V_13 ;
int V_14 ;
char V_15 [ 80 ] ;
if( V_1 -> V_2 -> type == V_16 ) {
V_1 -> V_17 = V_18 ;
V_13 = V_1 -> V_2 -> V_19 . V_20 -> V_21 ;
V_14 = V_1 -> V_2 -> V_19 . V_20 -> V_22 ;
} else {
V_1 -> V_17 = V_23 ;
V_13 = V_1 -> V_2 -> V_19 . V_24 -> V_21 ;
V_14 = V_1 -> V_2 -> V_19 . V_24 -> V_22 ;
}
if ( ! ( V_2 = F_4 () ) ) {
F_5 ( V_25 , V_26 ) ;
return NULL ;
}
V_12 = V_1 -> V_27 ;
switch ( F_6 ( V_12 -> V_28 ) )
{
#ifndef F_2
case V_29 :
if ( ! ( V_3 = F_7 ( NULL , & V_13 , V_14 ) ) ) {
F_5 ( V_25 , V_30 ) ;
return NULL ;
}
F_8 ( V_2 , V_3 ) ;
break;
#endif
#ifndef F_3
case V_31 :
if( * V_13 == ( V_32 | V_33 ) ) {
if( ! ( V_9 = F_9 ( V_13 , V_14 ,
( char * (*)() ) V_34 ,
V_35 ) ) ) {
F_5 ( V_25 , V_30 ) ;
goto V_36;
}
if( F_10 ( V_9 ) != 2 ) {
F_5 ( V_25 , V_30 ) ;
goto V_36;
}
V_6 = ( T_6 * ) F_11 ( V_9 , 0 ) ;
V_7 = ( T_6 * ) F_11 ( V_9 , 1 ) ;
if( V_6 -> type == V_32 ) {
V_1 -> V_17 = V_37 ;
V_8 = V_6 ;
} else if( V_12 -> V_38 -> type == V_32 ) {
V_1 -> V_17 = V_39 ;
V_8 = V_12 -> V_38 ;
} else {
F_5 ( V_25 , V_30 ) ;
goto V_36;
}
if( V_7 -> type != V_40 ) {
F_5 ( V_25 , V_30 ) ;
goto V_36;
}
V_5 = V_7 -> V_19 . integer ;
} else if ( ! ( V_5 = F_12 ( NULL , & V_13 , V_14 ) ) ) {
F_5 ( V_25 , V_30 ) ;
goto V_36;
}
V_13 = V_8 -> V_19 . V_24 -> V_21 ;
V_11 = V_8 -> V_19 . V_24 -> V_22 ;
if ( ! ( V_4 = F_13 ( NULL , & V_13 , V_11 ) ) ) {
F_5 ( V_25 , V_30 ) ;
goto V_36;
}
if ( ! ( V_4 -> V_41 = F_14 ( V_5 , NULL ) ) ) {
F_5 ( V_25 , V_42 ) ;
goto V_36;
}
if ( ! ( V_4 -> V_43 = F_15 () ) ) {
F_5 ( V_25 , V_26 ) ;
goto V_36;
}
if ( ! ( V_10 = F_16 () ) ) {
F_5 ( V_25 , V_26 ) ;
goto V_36;
}
if ( ! F_17 ( V_4 -> V_43 , V_4 -> V_44 ,
V_4 -> V_41 , V_4 -> V_13 , V_10 ) ) {
F_5 ( V_25 , V_45 ) ;
goto V_36;
}
F_18 ( V_2 , V_4 ) ;
F_19 ( V_10 ) ;
F_20 ( V_9 , V_35 ) ;
break;
V_36:
F_19 ( V_10 ) ;
F_20 ( V_9 , V_35 ) ;
F_21 ( V_4 ) ;
F_22 ( V_2 ) ;
return NULL ;
break;
#endif
default:
F_5 ( V_25 , V_46 ) ;
if ( ! V_12 -> V_28 ) strcpy ( V_15 , L_1 ) ;
else F_23 ( V_15 , 80 , V_12 -> V_28 ) ;
F_24 ( 2 , L_2 , V_15 ) ;
F_22 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
T_2 * F_25 ( T_1 * V_2 )
{
return F_26 ( V_2 , V_18 ) ;
}
T_2 * F_26 ( T_1 * V_2 , int V_17 )
{
T_2 * V_1 ;
if ( ! ( V_1 = F_27 () ) ) {
F_5 ( V_47 , V_26 ) ;
return NULL ;
}
V_1 -> V_17 = V_17 ;
F_28 ( V_1 -> V_48 , 0 ) ;
if ( ! ( V_1 -> V_27 -> V_38 = F_29 () ) ) {
F_5 ( V_47 , V_26 ) ;
F_30 ( V_1 ) ;
return NULL ;
}
V_1 -> V_2 -> type = V_16 ;
switch ( F_31 ( V_2 -> type ) ) {
#ifndef F_2
case V_49 :
if( V_1 -> V_17 == V_23 ) V_1 -> V_2 -> type = V_32 ;
V_1 -> V_27 -> V_28 = F_32 ( V_29 ) ;
V_1 -> V_27 -> V_38 -> type = V_50 ;
if ( ! F_33 ( ( char * ) V_2 , V_51 ,
& V_1 -> V_2 -> V_19 . V_20 ) ) {
F_5 ( V_47 , V_26 ) ;
F_30 ( V_1 ) ;
return NULL ;
}
break;
#endif
#ifndef F_3
case V_52 :
if( ! F_34 ( V_1 , V_2 ) ) {
F_30 ( V_1 ) ;
return NULL ;
}
break;
#endif
default:
F_5 ( V_47 , V_46 ) ;
F_30 ( V_1 ) ;
return NULL ;
}
F_35 ( V_1 -> V_2 -> V_19 . V_20 -> V_21 ,
V_1 -> V_2 -> V_19 . V_20 -> V_22 , 0 ) ;
return V_1 ;
}
T_2 * F_36 ( T_2 * V_1 , int V_17 )
{
switch ( V_17 ) {
case V_18 :
V_1 -> V_17 = V_18 ;
return V_1 ;
break;
case V_23 :
V_1 -> V_17 = V_23 ;
V_1 -> V_2 -> type = V_32 ;
return V_1 ;
break;
default:
F_5 ( V_53 , V_54 ) ;
return NULL ;
break;
}
}
static int F_34 ( T_2 * V_1 , T_1 * V_2 )
{
T_10 * V_55 ;
T_5 * V_56 ;
T_6 * V_57 ;
T_7 * V_9 ;
unsigned char * V_13 , * V_58 ;
int V_59 ;
V_1 -> V_27 -> V_28 = F_32 ( V_31 ) ;
V_59 = F_37 ( V_2 -> V_2 . V_4 , NULL ) ;
if ( ! ( V_13 = Malloc ( V_59 ) ) ) {
F_5 ( V_47 , V_26 ) ;
F_30 ( V_1 ) ;
return 0 ;
}
V_58 = V_13 ;
F_37 ( V_2 -> V_2 . V_4 , & V_58 ) ;
V_55 = F_38 () ;
F_39 ( V_55 , V_13 , V_59 ) ;
Free ( V_13 ) ;
if ( ! ( V_56 = F_40 ( V_2 -> V_2 . V_4 -> V_41 , NULL ) ) ) {
F_5 ( V_47 , V_60 ) ;
return 0 ;
}
switch( V_1 -> V_17 ) {
case V_18 :
case V_23 :
if ( ! F_33 ( ( char * ) V_56 , V_61 ,
& V_1 -> V_2 -> V_19 . V_20 ) ) {
F_5 ( V_47 , V_26 ) ;
F_41 ( V_56 ) ;
return 0 ;
}
F_41 ( V_56 ) ;
V_1 -> V_27 -> V_38 -> V_19 . V_24 = V_55 ;
V_1 -> V_27 -> V_38 -> type = V_32 ;
break;
case V_39 :
V_1 -> V_27 -> V_38 -> V_19 . V_24 = V_55 ;
V_1 -> V_27 -> V_38 -> type = V_32 ;
V_9 = F_42 () ;
V_57 = F_29 () ;
if ( ! ( V_57 -> V_19 . integer = F_40 ( V_2 -> V_2 . V_4 -> V_43 , NULL ) ) ) {
F_5 ( V_47 , V_60 ) ;
F_30 ( V_1 ) ;
return 0 ;
}
V_57 -> type = V_40 ;
F_43 ( V_9 , ( char * ) V_57 ) ;
V_57 = F_29 () ;
V_57 -> V_19 . integer = V_56 ;
V_57 -> type = V_40 ;
F_43 ( V_9 , ( char * ) V_57 ) ;
V_1 -> V_2 -> V_19 . V_20 = F_44 () ;
if ( ! F_45 ( V_9 , V_62 ,
& V_1 -> V_2 -> V_19 . V_20 -> V_21 ,
& V_1 -> V_2 -> V_19 . V_20 -> V_22 ) ) {
F_5 ( V_47 , V_26 ) ;
F_20 ( V_9 , V_35 ) ;
F_41 ( V_56 ) ;
return 0 ;
}
F_20 ( V_9 , V_35 ) ;
break;
case V_37 :
V_1 -> V_27 -> V_38 -> type = V_50 ;
V_9 = F_42 () ;
V_57 = F_29 () ;
V_57 -> V_19 . V_24 = V_55 ;
V_57 -> type = V_32 ;
F_43 ( V_9 , ( char * ) V_57 ) ;
V_57 = F_29 () ;
V_57 -> V_19 . integer = V_56 ;
V_57 -> type = V_40 ;
F_43 ( V_9 , ( char * ) V_57 ) ;
V_1 -> V_2 -> V_19 . V_20 = F_44 () ;
if ( ! F_45 ( V_9 , V_62 ,
& V_1 -> V_2 -> V_19 . V_20 -> V_21 ,
& V_1 -> V_2 -> V_19 . V_20 -> V_22 ) ) {
F_5 ( V_47 , V_26 ) ;
F_20 ( V_9 , V_35 ) ;
F_41 ( V_56 ) ;
return 0 ;
}
F_20 ( V_9 , V_35 ) ;
break;
}
return 1 ;
}
