T_1
F_1 ( T_2 * V_1 , T_3 T_4 V_2 )
{
switch ( V_1 -> type ) {
case V_3 :
V_1 -> V_4 . V_5 = * V_1 -> V_6 . V_5 ;
break;
case V_7 :
V_1 -> V_4 . V_8 = * V_1 -> V_6 . V_9 ;
break;
case V_10 :
V_1 -> V_4 . V_11 = * V_1 -> V_6 . V_12 ;
break;
case V_13 :
case V_14 :
case V_15 :
F_2 ( V_1 -> V_4 . string ) ;
V_1 -> V_4 . string = F_3 ( * V_1 -> V_6 . string ) ;
break;
case V_16 :
F_2 ( V_1 -> V_4 . V_17 ) ;
V_1 -> V_4 . V_17 = F_4 ( * V_1 -> V_6 . V_17 ) ;
break;
case V_18 :
V_1 -> V_4 . V_19 = * V_1 -> V_6 . V_20 ;
break;
case V_21 :
case V_22 :
case V_23 :
break;
case V_24 :
F_5 () ;
break;
}
return 0 ;
}
T_1
F_6 ( T_2 * V_1 , T_3 V_25 )
{
T_5 * V_26 = ( T_5 * ) V_25 ;
switch ( V_1 -> type ) {
case V_3 :
if ( * V_1 -> V_6 . V_5 != V_1 -> V_4 . V_5 ) {
* V_26 = TRUE ;
* V_1 -> V_6 . V_5 = V_1 -> V_4 . V_5 ;
}
break;
case V_7 :
if ( * V_1 -> V_6 . V_9 != V_1 -> V_4 . V_8 ) {
* V_26 = TRUE ;
* V_1 -> V_6 . V_9 = V_1 -> V_4 . V_8 ;
}
break;
case V_10 :
if ( * V_1 -> V_6 . V_12 != V_1 -> V_4 . V_11 ) {
* V_26 = TRUE ;
* V_1 -> V_6 . V_12 = V_1 -> V_4 . V_11 ;
}
break;
case V_13 :
case V_14 :
case V_15 :
if ( strcmp ( * V_1 -> V_6 . string , V_1 -> V_4 . string ) != 0 ) {
* V_26 = TRUE ;
F_2 ( ( void * ) * V_1 -> V_6 . string ) ;
* V_1 -> V_6 . string = F_3 ( V_1 -> V_4 . string ) ;
}
break;
case V_16 :
if ( ! F_7 ( * V_1 -> V_6 . V_17 , V_1 -> V_4 . V_17 ) ) {
* V_26 = TRUE ;
F_2 ( * V_1 -> V_6 . V_17 ) ;
* V_1 -> V_6 . V_17 = F_4 ( V_1 -> V_4 . V_17 ) ;
}
break;
case V_18 :
* V_1 -> V_6 . V_20 = V_1 -> V_4 . V_19 ;
break;
case V_21 :
case V_22 :
case V_23 :
break;
case V_24 :
F_5 () ;
break;
}
return 0 ;
}
void
F_8 ( T_2 * V_1 ) {
switch ( V_1 -> type ) {
case V_3 :
V_1 -> V_4 . V_5 = V_1 -> V_27 . V_5 ;
break;
case V_7 :
V_1 -> V_4 . V_8 = V_1 -> V_27 . V_8 ;
break;
case V_10 :
V_1 -> V_4 . V_11 = V_1 -> V_27 . V_11 ;
break;
case V_13 :
case V_14 :
case V_15 :
F_2 ( V_1 -> V_4 . string ) ;
V_1 -> V_4 . string = F_3 ( V_1 -> V_27 . string ) ;
break;
case V_16 :
F_2 ( V_1 -> V_4 . V_17 ) ;
V_1 -> V_4 . V_17 = F_4 ( V_1 -> V_27 . V_17 ) ;
break;
case V_18 :
memcpy ( & V_1 -> V_4 . V_19 , & V_1 -> V_27 . V_19 , sizeof( V_28 ) ) ;
break;
case V_21 :
case V_22 :
case V_23 :
break;
case V_24 :
F_5 () ;
break;
}
}
T_1
F_9 ( T_2 * V_1 , T_3 T_4 V_2 )
{
switch ( V_1 -> type ) {
case V_3 :
break;
case V_7 :
break;
case V_10 :
break;
case V_13 :
case V_14 :
case V_15 :
if ( V_1 -> V_4 . string != NULL ) {
F_2 ( V_1 -> V_4 . string ) ;
V_1 -> V_4 . string = NULL ;
}
break;
case V_16 :
if ( V_1 -> V_4 . V_17 != NULL ) {
F_2 ( V_1 -> V_4 . V_17 ) ;
V_1 -> V_4 . V_17 = NULL ;
}
break;
case V_21 :
case V_22 :
case V_18 :
case V_23 :
break;
case V_24 :
F_5 () ;
break;
}
return 0 ;
}
void
F_10 ( void )
{
#ifdef F_11
V_29 . V_30 . V_31 = V_32 . V_33 ;
V_29 . V_34 = V_32 . V_35 ;
V_29 . V_36 = V_32 . V_37 ;
V_29 . V_38 = V_32 . V_39 ;
V_40 = V_32 . V_41 ;
#endif
}
void
F_12 ( void )
{
int V_42 ;
char * V_43 ;
char * V_44 ;
if ( F_13 ( & V_43 ) == - 1 ) {
F_14 ( V_45 , V_46 ,
L_1 , V_43 ,
F_15 ( V_47 ) ) ;
F_2 ( V_43 ) ;
} else {
V_42 = F_16 ( & V_44 ) ;
if ( V_42 != 0 ) {
F_14 ( V_45 , V_46 ,
L_2 , V_44 ,
F_15 ( V_42 ) ) ;
F_2 ( V_44 ) ;
}
}
}
T_5
F_17 ( const char * V_48 , const char * V_49 , const char * V_50 )
{
T_6 * V_51 = NULL ;
T_2 * V_1 = NULL ;
T_5 V_52 = TRUE ;
if ( ! F_18 ( V_48 ) )
return FALSE ;
V_51 = F_19 ( V_48 ) ;
if ( ! V_51 )
return FALSE ;
V_1 = F_20 ( V_51 , V_49 ) ;
if ( ! V_1 )
return FALSE ;
if ( V_1 -> type == V_13 )
{
F_2 ( ( void * ) V_1 -> V_4 . string ) ;
V_1 -> V_4 . string = ( V_53 * ) F_3 ( V_50 ) ;
if ( strcmp ( * V_1 -> V_6 . string , V_1 -> V_4 . string ) != 0 )
{
V_52 = TRUE ;
F_2 ( ( void * ) * V_1 -> V_6 . string ) ;
* V_1 -> V_6 . string = F_3 ( V_1 -> V_4 . string ) ;
}
}
if ( V_52 )
{
F_12 () ;
F_21 () ;
F_10 () ;
}
return TRUE ;
}
T_7
F_22 ( T_7 V_54 , const V_53 * V_55 , const V_53 * V_56 , T_7 V_57 )
{
T_8 * V_58 ;
T_9 * V_59 , * V_60 ;
T_7 V_61 ;
V_59 = ( T_9 * ) F_23 ( sizeof( T_9 ) ) ;
V_59 -> V_55 = F_3 ( V_55 ) ;
V_59 -> V_54 = V_54 ;
V_59 -> V_56 = F_3 ( V_56 ) ;
V_59 -> V_57 = V_57 ;
V_59 -> V_62 = TRUE ;
V_61 = F_24 ( V_32 . V_63 ) ;
if ( V_56 ) {
V_59 -> V_64 = TRUE ;
V_58 = F_25 ( V_32 . V_63 ) ;
V_60 = ( T_9 * ) V_58 -> V_65 ;
if ( V_60 -> V_54 == V_66 ) {
V_61 -= 1 ;
V_32 . V_63 = F_26 ( V_32 . V_63 , V_59 , V_61 ) ;
} else {
V_32 . V_63 = F_27 ( V_32 . V_63 , V_59 ) ;
}
} else {
V_59 -> V_64 = FALSE ;
V_32 . V_63 = F_27 ( V_32 . V_63 , V_59 ) ;
}
return V_61 ;
}
void
F_28 ( T_8 * V_67 )
{
T_9 * V_59 ;
if ( ! V_67 || ! V_67 -> V_65 ) return;
V_59 = ( T_9 * ) V_67 -> V_65 ;
F_2 ( V_59 -> V_55 ) ;
F_2 ( V_59 -> V_56 ) ;
F_2 ( V_59 ) ;
V_32 . V_63 = F_29 ( V_32 . V_63 , V_67 ) ;
}
void
F_30 ( T_7 V_68 )
{
F_28 ( F_31 ( V_32 . V_63 , V_68 ) ) ;
}
