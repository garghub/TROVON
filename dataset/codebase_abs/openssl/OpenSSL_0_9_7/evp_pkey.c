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
F_4 ( T_6 ) * V_9 = NULL ;
T_7 * V_10 = NULL ;
int V_11 ;
#endif
T_8 * V_12 ;
unsigned char * V_13 ;
const unsigned char * V_14 ;
int V_15 ;
char V_16 [ 80 ] ;
if( V_1 -> V_2 -> type == V_17 ) {
V_1 -> V_18 = V_19 ;
V_13 = V_1 -> V_2 -> V_20 . V_21 -> V_22 ;
V_15 = V_1 -> V_2 -> V_20 . V_21 -> V_23 ;
} else {
V_1 -> V_18 = V_24 ;
V_13 = V_1 -> V_2 -> V_20 . V_25 -> V_22 ;
V_15 = V_1 -> V_2 -> V_20 . V_25 -> V_23 ;
}
if ( ! ( V_2 = F_5 () ) ) {
F_6 ( V_26 , V_27 ) ;
return NULL ;
}
V_12 = V_1 -> V_28 ;
switch ( F_7 ( V_12 -> V_29 ) )
{
#ifndef F_2
case V_30 :
V_14 = V_13 ;
if ( ! ( V_3 = F_8 ( NULL , & V_14 , V_15 ) ) ) {
F_6 ( V_26 , V_31 ) ;
return NULL ;
}
F_9 ( V_2 , V_3 ) ;
break;
#endif
#ifndef F_3
case V_32 :
if( * V_13 == ( V_33 | V_34 ) ) {
if( ! ( V_9 = F_10 ( V_13 , V_15 ,
V_35 ,
V_36 ) ) ) {
F_6 ( V_26 , V_31 ) ;
goto V_37;
}
if( F_11 ( V_9 ) != 2 ) {
F_6 ( V_26 , V_31 ) ;
goto V_37;
}
V_6 = F_12 ( V_9 , 0 ) ;
V_7 = F_12 ( V_9 , 1 ) ;
if( V_6 -> type == V_33 ) {
V_1 -> V_18 = V_38 ;
V_8 = V_6 ;
} else if( V_12 -> V_39 -> type == V_33 ) {
V_1 -> V_18 = V_40 ;
V_8 = V_12 -> V_39 ;
} else {
F_6 ( V_26 , V_31 ) ;
goto V_37;
}
if( V_7 -> type != V_41 ) {
F_6 ( V_26 , V_31 ) ;
goto V_37;
}
V_5 = V_7 -> V_20 . integer ;
} else {
if ( ! ( V_5 = F_13 ( NULL , & V_13 , V_15 ) ) ) {
F_6 ( V_26 , V_31 ) ;
goto V_37;
}
V_8 = V_1 -> V_28 -> V_39 ;
}
if ( ! V_8 || ( V_8 -> type != V_33 ) ) {
F_6 ( V_26 , V_31 ) ;
goto V_37;
}
V_14 = V_13 = V_8 -> V_20 . V_25 -> V_22 ;
V_11 = V_8 -> V_20 . V_25 -> V_23 ;
if ( ! ( V_4 = F_14 ( NULL , & V_14 , V_11 ) ) ) {
F_6 ( V_26 , V_31 ) ;
goto V_37;
}
if ( ! ( V_4 -> V_42 = F_15 ( V_5 , NULL ) ) ) {
F_6 ( V_26 , V_43 ) ;
goto V_37;
}
if ( ! ( V_4 -> V_44 = F_16 () ) ) {
F_6 ( V_26 , V_27 ) ;
goto V_37;
}
if ( ! ( V_10 = F_17 () ) ) {
F_6 ( V_26 , V_27 ) ;
goto V_37;
}
if ( ! F_18 ( V_4 -> V_44 , V_4 -> V_45 ,
V_4 -> V_42 , V_4 -> V_13 , V_10 ) ) {
F_6 ( V_26 , V_46 ) ;
goto V_37;
}
F_19 ( V_2 , V_4 ) ;
F_20 ( V_10 ) ;
if( V_9 ) F_21 ( V_9 , V_36 ) ;
else F_22 ( V_5 ) ;
break;
V_37:
F_20 ( V_10 ) ;
F_21 ( V_9 , V_36 ) ;
F_23 ( V_4 ) ;
F_24 ( V_2 ) ;
return NULL ;
break;
#endif
default:
F_6 ( V_26 , V_47 ) ;
if ( ! V_12 -> V_29 ) strcpy ( V_16 , L_1 ) ;
else F_25 ( V_16 , 80 , V_12 -> V_29 ) ;
F_26 ( 2 , L_2 , V_16 ) ;
F_24 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
T_2 * F_27 ( T_1 * V_2 )
{
return F_28 ( V_2 , V_19 ) ;
}
T_2 * F_28 ( T_1 * V_2 , int V_18 )
{
T_2 * V_1 ;
if ( ! ( V_1 = F_29 () ) ) {
F_6 ( V_48 , V_27 ) ;
return NULL ;
}
V_1 -> V_18 = V_18 ;
F_30 ( V_1 -> V_49 , 0 ) ;
if ( ! ( V_1 -> V_28 -> V_39 = F_31 () ) ) {
F_6 ( V_48 , V_27 ) ;
F_32 ( V_1 ) ;
return NULL ;
}
V_1 -> V_2 -> type = V_17 ;
switch ( F_33 ( V_2 -> type ) ) {
#ifndef F_2
case V_50 :
if( V_1 -> V_18 == V_24 ) V_1 -> V_2 -> type = V_33 ;
V_1 -> V_28 -> V_29 = F_34 ( V_30 ) ;
V_1 -> V_28 -> V_39 -> type = V_51 ;
if ( ! F_35 ( ( char * ) V_2 , V_52 ,
& V_1 -> V_2 -> V_20 . V_21 ) ) {
F_6 ( V_48 , V_27 ) ;
F_32 ( V_1 ) ;
return NULL ;
}
break;
#endif
#ifndef F_3
case V_53 :
if( ! F_36 ( V_1 , V_2 ) ) {
F_32 ( V_1 ) ;
return NULL ;
}
break;
#endif
default:
F_6 ( V_48 , V_47 ) ;
F_32 ( V_1 ) ;
return NULL ;
}
F_37 ( V_1 -> V_2 -> V_20 . V_21 -> V_22 ,
V_1 -> V_2 -> V_20 . V_21 -> V_23 , 0 ) ;
return V_1 ;
}
T_2 * F_38 ( T_2 * V_1 , int V_18 )
{
switch ( V_18 ) {
case V_19 :
V_1 -> V_18 = V_19 ;
return V_1 ;
break;
case V_24 :
V_1 -> V_18 = V_24 ;
V_1 -> V_2 -> type = V_33 ;
return V_1 ;
break;
default:
F_6 ( V_54 , V_55 ) ;
return NULL ;
break;
}
}
static int F_36 ( T_2 * V_1 , T_1 * V_2 )
{
T_9 * V_56 ;
T_5 * V_57 ;
T_6 * V_58 ;
F_4 ( T_6 ) * V_9 ;
unsigned char * V_13 , * V_59 ;
int V_60 ;
V_1 -> V_28 -> V_29 = F_34 ( V_32 ) ;
V_60 = F_39 ( V_2 -> V_2 . V_4 , NULL ) ;
if ( ! ( V_13 = F_40 ( V_60 ) ) ) {
F_6 ( V_48 , V_27 ) ;
F_32 ( V_1 ) ;
return 0 ;
}
V_59 = V_13 ;
F_39 ( V_2 -> V_2 . V_4 , & V_59 ) ;
V_56 = F_41 () ;
F_42 ( V_56 , V_13 , V_60 ) ;
F_43 ( V_13 ) ;
if ( ! ( V_57 = F_44 ( V_2 -> V_2 . V_4 -> V_42 , NULL ) ) ) {
F_6 ( V_48 , V_61 ) ;
return 0 ;
}
switch( V_1 -> V_18 ) {
case V_19 :
case V_24 :
if ( ! F_35 ( ( char * ) V_57 , V_62 ,
& V_1 -> V_2 -> V_20 . V_21 ) ) {
F_6 ( V_48 , V_27 ) ;
F_45 ( V_57 ) ;
return 0 ;
}
F_45 ( V_57 ) ;
V_1 -> V_28 -> V_39 -> V_20 . V_25 = V_56 ;
V_1 -> V_28 -> V_39 -> type = V_33 ;
break;
case V_40 :
V_1 -> V_28 -> V_39 -> V_20 . V_25 = V_56 ;
V_1 -> V_28 -> V_39 -> type = V_33 ;
V_9 = F_46 () ;
V_58 = F_31 () ;
if ( ! ( V_58 -> V_20 . integer = F_44 ( V_2 -> V_2 . V_4 -> V_44 , NULL ) ) ) {
F_6 ( V_48 , V_61 ) ;
F_32 ( V_1 ) ;
return 0 ;
}
V_58 -> type = V_41 ;
F_47 ( V_9 , V_58 ) ;
V_58 = F_31 () ;
V_58 -> V_20 . integer = V_57 ;
V_58 -> type = V_41 ;
F_47 ( V_9 , V_58 ) ;
V_1 -> V_2 -> V_20 . V_21 = F_48 () ;
if ( ! F_49 ( V_9 , V_63 ,
& V_1 -> V_2 -> V_20 . V_21 -> V_22 ,
& V_1 -> V_2 -> V_20 . V_21 -> V_23 ) ) {
F_6 ( V_48 , V_27 ) ;
F_21 ( V_9 , V_36 ) ;
F_45 ( V_57 ) ;
return 0 ;
}
F_21 ( V_9 , V_36 ) ;
break;
case V_38 :
V_1 -> V_28 -> V_39 -> type = V_51 ;
V_9 = F_46 () ;
V_58 = F_31 () ;
V_58 -> V_20 . V_25 = V_56 ;
V_58 -> type = V_33 ;
F_47 ( V_9 , V_58 ) ;
V_58 = F_31 () ;
V_58 -> V_20 . integer = V_57 ;
V_58 -> type = V_41 ;
F_47 ( V_9 , V_58 ) ;
V_1 -> V_2 -> V_20 . V_21 = F_48 () ;
if ( ! F_49 ( V_9 , V_63 ,
& V_1 -> V_2 -> V_20 . V_21 -> V_22 ,
& V_1 -> V_2 -> V_20 . V_21 -> V_23 ) ) {
F_6 ( V_48 , V_27 ) ;
F_21 ( V_9 , V_36 ) ;
F_45 ( V_57 ) ;
return 0 ;
}
F_21 ( V_9 , V_36 ) ;
break;
}
return 1 ;
}
