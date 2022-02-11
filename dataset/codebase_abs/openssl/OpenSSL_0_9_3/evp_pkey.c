T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
#ifndef F_2
T_3 * V_3 ;
#endif
#ifndef F_3
T_4 * V_4 ;
T_5 * V_5 ;
T_6 * V_6 ;
T_7 * V_7 ;
int V_8 ;
#endif
T_8 * V_9 ;
unsigned char * V_10 ;
int V_11 ;
char V_12 [ 80 ] ;
switch ( V_1 -> V_13 ) {
case V_14 :
V_10 = V_1 -> V_2 -> V_15 . V_16 -> V_17 ;
V_11 = V_1 -> V_2 -> V_15 . V_16 -> V_18 ;
break;
case V_19 :
V_10 = V_1 -> V_2 -> V_15 . V_20 -> V_17 ;
V_11 = V_1 -> V_2 -> V_15 . V_20 -> V_18 ;
break;
default:
F_4 ( V_21 , V_22 ) ;
return NULL ;
break;
}
if ( ! ( V_2 = F_5 () ) ) {
F_4 ( V_21 , V_23 ) ;
return NULL ;
}
V_9 = V_1 -> V_24 ;
switch ( F_6 ( V_9 -> V_25 ) )
{
#ifndef F_2
case V_26 :
if ( ! ( V_3 = F_7 ( NULL , & V_10 , V_11 ) ) ) {
F_4 ( V_21 , V_27 ) ;
return NULL ;
}
F_8 ( V_2 , V_3 ) ;
break;
#endif
#ifndef F_3
case V_28 :
if( * V_10 == ( V_29 | V_30 ) ) {
if( ! ( V_6 = F_9 ( V_10 , V_11 ,
( char * (*)() ) V_31 ,
V_32 ) ) ) {
F_4 ( V_21 , V_27 ) ;
return NULL ;
}
if( F_10 ( V_6 ) != 2 ) {
F_4 ( V_21 , V_27 ) ;
F_11 ( V_6 , V_32 ) ;
return NULL ;
}
V_5 = ( T_5 * ) F_12 ( V_6 ) ;
F_11 ( V_6 , V_32 ) ;
} else if ( ! ( V_5 = V_31 ( NULL , & V_10 , V_11 ) ) ) {
F_4 ( V_21 , V_27 ) ;
return NULL ;
}
if ( V_9 -> V_33 -> type != V_29 ) {
F_4 ( V_21 , V_34 ) ;
return NULL ;
}
V_10 = V_9 -> V_33 -> V_15 . V_20 -> V_17 ;
V_8 = V_9 -> V_33 -> V_15 . V_20 -> V_18 ;
if ( ! ( V_4 = F_13 ( NULL , & V_10 , V_8 ) ) ) {
F_4 ( V_21 , V_27 ) ;
return NULL ;
}
if ( ! ( V_4 -> V_35 = F_14 ( V_5 , NULL ) ) ) {
F_4 ( V_21 , V_36 ) ;
F_15 ( V_4 ) ;
return NULL ;
}
if ( ! ( V_4 -> V_37 = F_16 () ) ) {
F_4 ( V_21 , V_23 ) ;
F_15 ( V_4 ) ;
return NULL ;
}
if ( ! ( V_7 = F_17 () ) ) {
F_4 ( V_21 , V_23 ) ;
F_15 ( V_4 ) ;
return NULL ;
}
if ( ! F_18 ( V_4 -> V_37 , V_4 -> V_38 ,
V_4 -> V_35 , V_4 -> V_10 , V_7 ) ) {
F_4 ( V_21 , V_39 ) ;
F_19 ( V_7 ) ;
F_15 ( V_4 ) ;
return NULL ;
}
F_20 ( V_2 , V_4 ) ;
F_19 ( V_7 ) ;
break;
#endif
default:
F_4 ( V_21 , V_40 ) ;
if ( ! V_9 -> V_25 ) strcpy ( V_12 , L_1 ) ;
else F_21 ( V_12 , 80 , V_9 -> V_25 ) ;
F_22 ( 2 , L_2 , V_12 ) ;
F_23 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
T_2 * F_24 ( T_1 * V_2 )
{
T_2 * V_1 ;
#ifndef F_3
T_5 * V_41 ;
unsigned char * V_10 , * V_42 ;
int V_43 ;
#endif
if ( ! ( V_1 = F_25 () ) ) {
F_4 ( V_44 , V_23 ) ;
return NULL ;
}
F_26 ( V_1 -> V_45 , 0 ) ;
if ( ! ( V_1 -> V_24 -> V_33 = F_27 () ) ) {
F_4 ( V_44 , V_23 ) ;
F_28 ( V_1 ) ;
return NULL ;
}
switch ( F_29 ( V_2 -> type ) ) {
#ifndef F_2
case V_46 :
V_1 -> V_24 -> V_25 = F_30 ( V_26 ) ;
V_1 -> V_24 -> V_33 -> type = V_47 ;
if ( ! F_31 ( ( char * ) V_2 , V_48 ,
& V_1 -> V_2 -> V_15 . V_16 ) ) {
F_4 ( V_44 , V_23 ) ;
F_28 ( V_1 ) ;
return NULL ;
}
break;
#endif
#ifndef F_3
case V_49 :
V_1 -> V_24 -> V_25 = F_30 ( V_28 ) ;
V_43 = F_32 ( V_2 -> V_2 . V_4 , NULL ) ;
if ( ! ( V_10 = Malloc ( V_43 ) ) ) {
F_4 ( V_44 , V_23 ) ;
F_28 ( V_1 ) ;
return NULL ;
}
V_42 = V_10 ;
F_32 ( V_2 -> V_2 . V_4 , & V_42 ) ;
V_1 -> V_24 -> V_33 -> type = V_29 ;
V_1 -> V_24 -> V_33 -> V_15 . V_20 = F_33 () ;
F_34 ( V_1 -> V_24 -> V_33 -> V_15 . V_20 , V_10 , V_43 ) ;
Free ( V_10 ) ;
if ( ! ( V_41 = F_35 ( V_2 -> V_2 . V_4 -> V_35 , NULL ) ) ) {
F_4 ( V_44 , V_50 ) ;
F_28 ( V_1 ) ;
return NULL ;
}
if ( ! F_31 ( ( char * ) V_41 , V_51 ,
& V_1 -> V_2 -> V_15 . V_16 ) ) {
F_4 ( V_44 , V_23 ) ;
F_36 ( V_41 ) ;
F_28 ( V_1 ) ;
return NULL ;
}
F_36 ( V_41 ) ;
break;
#endif
default:
F_4 ( V_44 , V_40 ) ;
F_28 ( V_1 ) ;
return NULL ;
}
V_1 -> V_2 -> type = V_52 ;
F_37 ( V_1 -> V_2 -> V_15 . V_16 -> V_17 ,
V_1 -> V_2 -> V_15 . V_16 -> V_18 ) ;
return V_1 ;
}
T_2 * F_38 ( T_2 * V_1 , int V_13 )
{
switch ( V_13 ) {
case V_14 :
V_1 -> V_13 = V_14 ;
return V_1 ;
break;
case V_19 :
V_1 -> V_13 = V_19 ;
V_1 -> V_2 -> type = V_29 ;
return V_1 ;
break;
default:
F_4 ( V_53 , V_22 ) ;
return NULL ;
break;
}
}
