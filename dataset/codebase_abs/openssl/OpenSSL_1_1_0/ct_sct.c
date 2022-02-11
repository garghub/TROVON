T_1 * F_1 ( void )
{
T_1 * V_1 = F_2 ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_2 , V_3 ) ;
return NULL ;
}
V_1 -> V_4 = V_5 ;
V_1 -> V_6 = V_7 ;
return V_1 ;
}
void F_4 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_5 ( V_1 -> V_8 ) ;
F_5 ( V_1 -> V_9 ) ;
F_5 ( V_1 -> V_10 ) ;
F_5 ( V_1 -> V_1 ) ;
F_5 ( V_1 ) ;
}
int F_6 ( T_1 * V_1 , T_2 V_6 )
{
if ( V_6 != V_11 ) {
F_3 ( V_12 , V_13 ) ;
return 0 ;
}
V_1 -> V_6 = V_6 ;
V_1 -> V_14 = V_15 ;
return 1 ;
}
int F_7 ( T_1 * V_1 , T_3 V_4 )
{
V_1 -> V_14 = V_15 ;
switch ( V_4 ) {
case V_16 :
case V_17 :
V_1 -> V_4 = V_4 ;
return 1 ;
default:
F_3 ( V_18 , V_19 ) ;
return 0 ;
}
}
int F_8 ( T_1 * V_1 , unsigned char * V_8 , T_4 V_20 )
{
if ( V_1 -> V_6 == V_11 && V_20 != V_21 ) {
F_3 ( V_22 , V_23 ) ;
return 0 ;
}
F_5 ( V_1 -> V_8 ) ;
V_1 -> V_8 = V_8 ;
V_1 -> V_20 = V_20 ;
V_1 -> V_14 = V_15 ;
return 1 ;
}
int F_9 ( T_1 * V_1 , const unsigned char * V_8 , T_4 V_20 )
{
if ( V_1 -> V_6 == V_11 && V_20 != V_21 ) {
F_3 ( V_24 , V_23 ) ;
return 0 ;
}
F_5 ( V_1 -> V_8 ) ;
V_1 -> V_8 = NULL ;
V_1 -> V_20 = 0 ;
V_1 -> V_14 = V_15 ;
if ( V_8 != NULL && V_20 > 0 ) {
V_1 -> V_8 = F_10 ( V_8 , V_20 ) ;
if ( V_1 -> V_8 == NULL ) {
F_3 ( V_24 , V_3 ) ;
return 0 ;
}
V_1 -> V_20 = V_20 ;
}
return 1 ;
}
void F_11 ( T_1 * V_1 , T_5 V_25 )
{
V_1 -> V_25 = V_25 ;
V_1 -> V_14 = V_15 ;
}
int F_12 ( T_1 * V_1 , int V_26 )
{
switch ( V_26 ) {
case V_27 :
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_14 = V_15 ;
return 1 ;
case V_32 :
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_33 ;
V_1 -> V_14 = V_15 ;
return 1 ;
default:
F_3 ( V_34 , V_35 ) ;
return 0 ;
}
}
void F_13 ( T_1 * V_1 , unsigned char * V_9 , T_4 V_36 )
{
F_5 ( V_1 -> V_9 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_36 = V_36 ;
V_1 -> V_14 = V_15 ;
}
int F_14 ( T_1 * V_1 , const unsigned char * V_9 , T_4 V_36 )
{
F_5 ( V_1 -> V_9 ) ;
V_1 -> V_9 = NULL ;
V_1 -> V_36 = 0 ;
V_1 -> V_14 = V_15 ;
if ( V_9 != NULL && V_36 > 0 ) {
V_1 -> V_9 = F_10 ( V_9 , V_36 ) ;
if ( V_1 -> V_9 == NULL ) {
F_3 ( V_37 , V_3 ) ;
return 0 ;
}
V_1 -> V_36 = V_36 ;
}
return 1 ;
}
void F_15 ( T_1 * V_1 , unsigned char * V_10 , T_4 V_38 )
{
F_5 ( V_1 -> V_10 ) ;
V_1 -> V_10 = V_10 ;
V_1 -> V_38 = V_38 ;
V_1 -> V_14 = V_15 ;
}
int F_16 ( T_1 * V_1 , const unsigned char * V_10 , T_4 V_38 )
{
F_5 ( V_1 -> V_10 ) ;
V_1 -> V_10 = NULL ;
V_1 -> V_38 = 0 ;
V_1 -> V_14 = V_15 ;
if ( V_10 != NULL && V_38 > 0 ) {
V_1 -> V_10 = F_10 ( V_10 , V_38 ) ;
if ( V_1 -> V_10 == NULL ) {
F_3 ( V_39 , V_3 ) ;
return 0 ;
}
V_1 -> V_38 = V_38 ;
}
return 1 ;
}
T_2 F_17 ( const T_1 * V_1 )
{
return V_1 -> V_6 ;
}
T_3 F_18 ( const T_1 * V_1 )
{
return V_1 -> V_4 ;
}
T_4 F_19 ( const T_1 * V_1 , unsigned char * * V_8 )
{
* V_8 = V_1 -> V_8 ;
return V_1 -> V_20 ;
}
T_5 F_20 ( const T_1 * V_1 )
{
return V_1 -> V_25 ;
}
int F_21 ( const T_1 * V_1 )
{
if ( V_1 -> V_6 == V_11 ) {
if ( V_1 -> V_28 == V_29 ) {
switch ( V_1 -> V_30 ) {
case V_33 :
return V_32 ;
case V_31 :
return V_27 ;
default:
return V_40 ;
}
}
}
return V_40 ;
}
T_4 F_22 ( const T_1 * V_1 , unsigned char * * V_9 )
{
* V_9 = V_1 -> V_9 ;
return V_1 -> V_36 ;
}
T_4 F_23 ( const T_1 * V_1 , unsigned char * * V_10 )
{
* V_10 = V_1 -> V_10 ;
return V_1 -> V_38 ;
}
int F_24 ( const T_1 * V_1 )
{
switch ( V_1 -> V_6 ) {
case V_7 :
return 0 ;
case V_11 :
return V_1 -> V_8 != NULL && F_25 ( V_1 ) ;
default:
return V_1 -> V_1 != NULL ;
}
}
int F_25 ( const T_1 * V_1 )
{
return F_21 ( V_1 ) != V_40 &&
V_1 -> V_10 != NULL && V_1 -> V_38 > 0 ;
}
T_6 F_26 ( const T_1 * V_1 )
{
return V_1 -> V_41 ;
}
int F_27 ( T_1 * V_1 , T_6 V_41 )
{
V_1 -> V_41 = V_41 ;
V_1 -> V_14 = V_15 ;
switch ( V_41 ) {
case V_42 :
case V_43 :
return F_7 ( V_1 , V_16 ) ;
case V_44 :
return F_7 ( V_1 , V_17 ) ;
default:
return 1 ;
}
}
T_7 F_28 ( const T_1 * V_1 )
{
return V_1 -> V_14 ;
}
int F_29 ( T_1 * V_1 , const T_8 * V_45 )
{
int V_46 = - 1 ;
T_9 * V_47 = NULL ;
T_10 * V_48 = NULL , * V_49 = NULL ;
const T_11 * log ;
if ( V_1 -> V_6 != V_11 ) {
V_1 -> V_14 = V_50 ;
return 0 ;
}
log = F_30 ( V_45 -> V_51 ,
V_1 -> V_8 , V_1 -> V_20 ) ;
if ( log == NULL ) {
V_1 -> V_14 = V_52 ;
return 0 ;
}
V_47 = F_31 () ;
if ( V_47 == NULL )
goto V_53;
if ( F_32 ( & V_49 , F_33 ( log ) ) != 1 )
goto V_53;
if ( F_34 ( V_47 , V_49 ) != 1 )
goto V_53;
if ( F_18 ( V_1 ) == V_17 ) {
T_12 * V_54 ;
if ( V_45 -> V_55 == NULL ) {
V_1 -> V_14 = V_56 ;
goto V_57;
}
V_54 = F_35 ( V_45 -> V_55 ) ;
if ( F_32 ( & V_48 , V_54 ) != 1 )
goto V_53;
if ( F_36 ( V_47 , V_48 ) != 1 )
goto V_53;
}
if ( F_37 ( V_47 , V_45 -> V_58 , NULL ) != 1 )
V_1 -> V_14 = V_56 ;
else
V_1 -> V_14 = F_38 ( V_47 , V_1 ) == 1 ?
V_59 : V_60 ;
V_57:
V_46 = V_1 -> V_14 == V_59 ;
V_53:
F_39 ( V_48 ) ;
F_39 ( V_49 ) ;
F_40 ( V_47 ) ;
return V_46 ;
}
