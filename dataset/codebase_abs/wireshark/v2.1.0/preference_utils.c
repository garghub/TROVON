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
F_2 ( * V_1 -> V_6 . string ) ;
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
static T_5
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
F_2 ( * V_1 -> V_6 . string ) ;
* V_1 -> V_6 . string = F_3 ( V_1 -> V_4 . string ) ;
}
}
return V_52 ;
}
T_5
F_21 ( const char * V_48 , const char * V_49 , const char * V_50 )
{
if ( F_17 ( V_48 , V_49 , V_50 ) )
{
F_12 () ;
F_22 () ;
F_10 () ;
return TRUE ;
}
return FALSE ;
}
T_5
F_23 ( const char * V_51 , T_7 * V_54 )
{
T_5 V_52 = FALSE ;
T_8 * V_55 = NULL ;
if ( ! F_18 ( V_51 ) )
return V_52 ;
V_55 = F_24 ( V_54 ) ;
if ( ! V_55 )
return V_52 ;
while ( V_55 != NULL )
{
V_53 * V_49 = ( V_53 * ) V_55 -> V_56 ;
V_53 * V_50 = ( V_53 * ) F_25 ( V_54 , V_55 -> V_56 ) ;
if ( V_49 && V_50 )
{
if ( F_17 ( V_51 , V_49 , V_50 ) )
V_52 = TRUE ;
}
V_55 = F_26 ( V_55 ) ;
}
if ( V_52 )
{
F_12 () ;
F_22 () ;
F_10 () ;
}
return TRUE ;
}
T_9
F_27 ( T_9 V_57 , const V_53 * V_58 , const V_53 * V_59 , T_9 V_60 )
{
T_8 * V_61 ;
T_10 * V_62 , * V_63 ;
T_9 V_64 ;
V_62 = ( T_10 * ) F_28 ( sizeof( T_10 ) ) ;
V_62 -> V_58 = F_3 ( V_58 ) ;
V_62 -> V_57 = V_57 ;
V_62 -> V_59 = F_3 ( V_59 ) ;
V_62 -> V_60 = V_60 ;
V_62 -> V_65 = TRUE ;
V_64 = F_29 ( V_32 . V_66 ) ;
if ( V_59 ) {
V_62 -> V_67 = TRUE ;
V_61 = F_30 ( V_32 . V_66 ) ;
V_63 = ( T_10 * ) V_61 -> V_56 ;
if ( V_63 -> V_57 == V_68 ) {
V_64 -= 1 ;
V_32 . V_66 = F_31 ( V_32 . V_66 , V_62 , V_64 ) ;
} else {
V_32 . V_66 = F_32 ( V_32 . V_66 , V_62 ) ;
}
} else {
V_62 -> V_67 = FALSE ;
V_32 . V_66 = F_32 ( V_32 . V_66 , V_62 ) ;
}
return V_64 ;
}
void
F_33 ( T_8 * V_69 )
{
T_10 * V_62 ;
if ( ! V_69 || ! V_69 -> V_56 ) return;
V_62 = ( T_10 * ) V_69 -> V_56 ;
F_2 ( V_62 -> V_58 ) ;
F_2 ( V_62 -> V_59 ) ;
F_2 ( V_62 ) ;
V_32 . V_66 = F_34 ( V_32 . V_66 , V_69 ) ;
}
void
F_35 ( T_9 V_70 )
{
F_33 ( F_36 ( V_32 . V_66 , V_70 ) ) ;
}
