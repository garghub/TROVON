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
void F_12 ( T_4 * V_10 , const char * V_20 , const char * V_21 , const char * V_22 , const char * V_23 )
{
F_13 ( V_20 ) ;
V_10 -> V_24 = F_14 ( L_5 ,
V_20 ,
V_21 ? L_6 : L_7 ,
V_21 ? V_21 : L_7 ,
V_22 ? L_6 : L_7 ,
V_22 ? V_22 : L_7 ) ;
V_10 -> V_23 = F_10 ( V_23 ) ;
}
T_7 F_15 ( T_4 * V_10 , int V_25 , char * V_26 )
{
switch ( V_25 ) {
case V_27 :
V_10 -> V_28 = 1 ;
break;
case V_29 :
V_10 -> V_30 = 1 ;
break;
case V_31 :
V_10 -> V_32 = 1 ;
break;
case V_33 :
V_10 -> V_11 = F_10 ( V_26 ) ;
break;
case V_34 :
V_10 -> V_35 = 1 ;
break;
case V_36 :
V_10 -> V_37 = 1 ;
break;
case V_38 :
V_10 -> V_39 = F_10 ( V_26 ) ;
break;
case V_40 :
V_10 -> V_41 = F_10 ( V_26 ) ;
break;
}
return 1 ;
}
static void F_16 ( V_19 V_42 , V_19 T_8 V_43 )
{
T_6 * V_16 = ( T_6 * ) V_42 ;
printf ( L_8 , V_16 -> V_11 ) ;
if ( V_16 -> V_17 != NULL )
printf ( L_9 , V_16 -> V_17 ) ;
else
printf ( L_10 ) ;
}
static T_9 F_17 ( T_10 V_44 , T_10 V_45 )
{
const T_6 * V_46 = ( const T_6 * ) V_44 ;
return ( F_18 ( V_46 -> V_11 , ( const char * ) V_45 ) ) ;
}
static void F_19 ( T_4 * V_10 )
{
printf ( L_11 , V_10 -> V_24 != NULL ? V_10 -> V_24 : L_12 ) ;
if ( V_10 -> V_23 != NULL )
printf ( L_13 , V_10 -> V_23 ) ;
printf ( L_10 ) ;
}
static T_9 F_20 ( T_4 * V_10 , T_7 V_47 )
{
if ( V_47 ) {
if ( F_21 ( V_10 -> V_18 ) > 0 ) {
F_19 ( V_10 ) ;
F_22 ( V_10 -> V_18 , F_16 , V_10 ) ;
}
} else {
if ( V_10 -> V_30 ) {
F_19 ( V_10 ) ;
} else {
T_11 * V_48 = NULL ;
T_6 * V_16 = NULL ;
if ( ( V_48 = F_23 ( V_10 -> V_18 , V_10 -> V_11 , F_17 ) ) == NULL )
return 0 ;
V_16 = ( T_6 * ) V_48 -> V_42 ;
printf ( L_14 , V_16 -> V_13 , V_16 -> V_15 != NULL ? V_16 -> V_15 : V_16 -> V_11 ) ;
if ( V_16 -> V_17 != NULL )
printf ( L_9 , V_16 -> V_14 ) ;
else
printf ( L_10 ) ;
}
}
return 1 ;
}
T_7 F_24 ( T_4 * V_10 )
{
if ( V_10 -> V_37 && ( V_10 -> V_41 == NULL || strlen ( V_10 -> V_41 ) <= 0 ) ) {
V_10 -> V_37 = 0 ;
F_6 ( L_15 ) ;
return 0 ;
}
if ( V_10 -> V_28 ) {
return F_20 ( V_10 , 1 ) ;
} else if ( V_10 -> V_30 || V_10 -> V_32 ) {
return F_20 ( V_10 , 0 ) ;
}
return 0 ;
}
static void F_25 ( V_19 V_42 )
{
T_6 * V_16 = ( T_6 * ) V_42 ;
F_26 ( V_16 -> V_11 ) ;
F_26 ( V_16 -> V_17 ) ;
F_26 ( V_16 -> V_15 ) ;
F_26 ( V_16 -> V_14 ) ;
F_26 ( V_16 ) ;
}
void F_27 ( T_4 * * V_10 )
{
F_22 ( ( * V_10 ) -> V_18 , ( V_49 ) F_25 , NULL ) ;
F_28 ( ( * V_10 ) -> V_18 ) ;
F_26 ( ( * V_10 ) -> V_41 ) ;
F_26 ( ( * V_10 ) -> V_11 ) ;
F_26 ( ( * V_10 ) -> V_24 ) ;
F_26 ( ( * V_10 ) -> V_23 ) ;
F_26 ( * V_10 ) ;
* V_10 = NULL ;
}
