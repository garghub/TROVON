BOOLEAN F_1 ( T_1 V_1 )
{
T_2 V_2 = F_2 ( V_1 ) ;
if ( V_2 ) {
T_3 V_3 ;
if ( F_3 ( V_2 , & V_3 ) ) {
return TRUE ;
}
}
return FALSE ;
}
void F_4 ()
{
BOOL V_4 , V_5 ;
V_4 = F_1 ( V_6 ) ;
V_5 = F_1 ( V_7 ) ;
if ( V_4 && V_5 ) {
return;
}
if ( F_5 ( V_8 ) == 0 ) {
return;
}
if ( V_4 == FALSE ) {
if ( ! freopen ( L_1 , L_2 , stdout ) ) {
F_6 ( L_3 ) ;
}
}
if ( V_5 == FALSE ) {
if ( ! freopen ( L_1 , L_2 , V_9 ) ) {
F_6 ( L_4 ) ;
}
}
}
void F_7 ( T_4 * V_10 , const char * V_11 , const char * V_12 , T_5 V_13 , const char * V_14 )
{
F_8 ( V_10 , V_11 , V_12 , V_13 , NULL , V_14 ) ;
}
void F_8 ( T_4 * V_10 ,
const char * V_11 , const char * V_12 ,
T_5 V_13 , const char * V_15 , const char * V_14 )
{
T_6 * V_16 ;
if ( V_11 == NULL )
return;
V_16 = F_9 ( T_6 , 1 ) ;
V_16 -> V_11 = F_10 ( V_11 ) ;
V_16 -> V_17 = F_10 ( V_12 ) ;
V_16 -> V_13 = V_13 ;
V_16 -> V_15 = F_10 ( V_15 ) ;
V_16 -> V_14 = F_10 ( V_14 ) ;
V_10 -> V_18 = F_11 ( V_10 -> V_18 , ( V_19 ) V_16 ) ;
}
void F_12 ( T_4 * V_10 , const char * V_20 , const char * V_21 , const char * V_22 , const char * V_23 , const char * V_24 )
{
V_10 -> V_20 = F_13 ( V_20 ) ;
F_14 ( V_21 ) ;
if ( ! V_22 )
F_14 ( ! V_23 ) ;
V_10 -> V_25 = F_15 ( L_5 ,
V_21 ,
V_22 ? L_6 : L_7 ,
V_22 ? V_22 : L_7 ,
V_23 ? L_6 : L_7 ,
V_23 ? V_23 : L_7 ) ;
V_10 -> V_24 = F_10 ( V_24 ) ;
}
T_7 F_16 ( T_4 * V_10 , int V_26 , char * V_27 )
{
switch ( V_26 ) {
case V_28 :
#ifdef F_17
F_18 ( L_8 , L_9 ) ;
#else
F_19 ( L_8 , L_9 , 1 ) ;
#endif
break;
case V_29 :
V_10 -> V_30 = 1 ;
break;
case V_31 :
V_10 -> V_32 = 1 ;
break;
case V_33 :
V_10 -> V_34 = 1 ;
break;
case V_35 :
V_10 -> V_11 = F_10 ( V_27 ) ;
break;
case V_36 :
V_10 -> V_37 = 1 ;
break;
case V_38 :
V_10 -> V_39 = 1 ;
break;
case V_40 :
V_10 -> V_41 = F_10 ( V_27 ) ;
break;
case V_42 :
V_10 -> V_43 = F_10 ( V_27 ) ;
break;
}
return 1 ;
}
static void F_20 ( V_19 V_44 , V_19 T_8 V_45 )
{
T_6 * V_16 = ( T_6 * ) V_44 ;
printf ( L_10 , V_16 -> V_11 ) ;
if ( V_16 -> V_17 != NULL )
printf ( L_11 , V_16 -> V_17 ) ;
else
printf ( L_12 ) ;
}
static T_9 F_21 ( T_10 V_46 , T_10 V_47 )
{
const T_6 * V_48 = ( const T_6 * ) V_46 ;
return ( F_22 ( V_48 -> V_11 , ( const char * ) V_47 ) ) ;
}
static void F_23 ( T_4 * V_10 )
{
printf ( L_13 , V_10 -> V_25 != NULL ? V_10 -> V_25 : L_14 ) ;
if ( V_10 -> V_24 != NULL )
printf ( L_15 , V_10 -> V_24 ) ;
printf ( L_12 ) ;
}
static T_9 F_24 ( T_4 * V_10 , T_7 V_49 )
{
if ( V_49 ) {
if ( F_25 ( V_10 -> V_18 ) > 0 ) {
F_23 ( V_10 ) ;
F_26 ( V_10 -> V_18 , F_20 , V_10 ) ;
}
} else {
if ( V_10 -> V_32 ) {
F_23 ( V_10 ) ;
} else {
T_11 * V_50 = NULL ;
T_6 * V_16 = NULL ;
if ( ( V_50 = F_27 ( V_10 -> V_18 , V_10 -> V_11 , F_21 ) ) == NULL )
return 0 ;
V_16 = ( T_6 * ) V_50 -> V_44 ;
printf ( L_16 , V_16 -> V_13 , V_16 -> V_15 != NULL ? V_16 -> V_15 : V_16 -> V_11 ) ;
if ( V_16 -> V_17 != NULL )
printf ( L_11 , V_16 -> V_14 ) ;
else
printf ( L_12 ) ;
}
}
return 1 ;
}
T_7 F_28 ( T_4 * V_10 )
{
if ( V_10 -> V_39 && ( V_10 -> V_43 == NULL || strlen ( V_10 -> V_43 ) <= 0 ) ) {
V_10 -> V_39 = 0 ;
F_29 ( L_17 ) ;
return 0 ;
}
if ( V_10 -> V_30 ) {
return F_24 ( V_10 , 1 ) ;
} else if ( V_10 -> V_32 || V_10 -> V_34 ) {
return F_24 ( V_10 , 0 ) ;
}
return 0 ;
}
static void F_30 ( V_19 V_44 )
{
T_6 * V_16 = ( T_6 * ) V_44 ;
F_31 ( V_16 -> V_11 ) ;
F_31 ( V_16 -> V_17 ) ;
F_31 ( V_16 -> V_15 ) ;
F_31 ( V_16 -> V_14 ) ;
F_31 ( V_16 ) ;
}
static void F_32 ( V_19 V_51 )
{
T_12 * V_52 = ( T_12 * ) V_51 ;
F_31 ( V_52 -> V_53 ) ;
F_31 ( V_52 -> V_54 ) ;
F_31 ( V_52 ) ;
}
void F_33 ( T_4 * * V_10 )
{
F_26 ( ( * V_10 ) -> V_18 , ( V_55 ) F_30 , NULL ) ;
F_34 ( ( * V_10 ) -> V_18 ) ;
F_31 ( ( * V_10 ) -> V_20 ) ;
F_31 ( ( * V_10 ) -> V_43 ) ;
F_31 ( ( * V_10 ) -> V_11 ) ;
F_31 ( ( * V_10 ) -> V_25 ) ;
F_31 ( ( * V_10 ) -> V_24 ) ;
F_31 ( ( * V_10 ) -> V_56 ) ;
F_26 ( ( * V_10 ) -> V_57 , ( V_55 ) F_32 , NULL ) ;
F_34 ( ( * V_10 ) -> V_57 ) ;
F_31 ( * V_10 ) ;
* V_10 = NULL ;
}
static void F_35 ( V_19 V_51 )
{
T_12 * V_52 = ( T_12 * ) V_51 ;
printf ( L_18 , V_52 -> V_53 , V_52 -> V_54 ) ;
}
void F_36 ( T_4 * V_10 )
{
printf ( L_19 , V_10 -> V_20 , V_10 -> V_25 ) ;
printf ( L_20 ) ;
printf ( L_21 , V_10 -> V_56 ) ;
printf ( L_12 ) ;
printf ( L_22 ) ;
F_26 ( V_10 -> V_57 , ( V_55 ) F_35 , NULL ) ;
printf ( L_12 ) ;
}
void F_37 ( T_4 * V_10 , const char * V_58 , const char * V_59 )
{
T_12 * V_52 = F_9 ( T_12 , 1 ) ;
V_52 -> V_53 = F_10 ( V_58 ) ;
V_52 -> V_54 = F_10 ( V_59 ) ;
V_10 -> V_57 = F_11 ( V_10 -> V_57 , V_52 ) ;
}
void F_38 ( T_4 * V_10 , char * V_56 )
{
V_10 -> V_56 = F_10 ( V_56 ) ;
F_37 ( V_10 , L_23 , L_24 ) ;
F_37 ( V_10 , L_25 , L_26 ) ;
F_37 ( V_10 , L_27 , L_28 ) ;
F_37 ( V_10 , L_29 , L_30 ) ;
F_37 ( V_10 , L_31 , L_32 ) ;
F_37 ( V_10 , L_33 , L_34 ) ;
F_37 ( V_10 , L_35 , L_36 ) ;
F_37 ( V_10 , L_37 , L_38 ) ;
F_37 ( V_10 , L_39 , L_40 ) ;
}
