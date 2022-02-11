static T_1 F_1 ( T_2 V_1 , T_3 V_2 ,
void * V_3 , void * * V_4 )
{
struct V_5 * V_6 ;
const char * V_7 = NULL ;
if ( F_2 ( V_1 , & V_6 ) )
return V_8 ;
if ( V_6 -> V_9 . V_10 && V_6 -> V_9 . V_11 ) {
V_7 = F_3 ( V_6 ) ;
* ( const char * * ) V_4 = V_7 ;
return V_12 ;
}
return V_8 ;
}
const char * F_4 ( const T_4 V_13 [ V_14 ] )
{
const char * V_7 = NULL ;
T_1 V_9 ;
V_9 = F_5 ( V_13 , F_1 , NULL ,
( void * * ) & V_7 ) ;
if ( F_6 ( V_9 ) || V_7 [ 0 ] == '\0' )
return NULL ;
return V_7 ;
}
static T_1 F_7 ( T_2 V_1 , T_3 V_2 ,
void * V_3 , void * * V_4 )
{
unsigned long long V_15 ;
T_1 V_9 ;
* ( bool * ) V_3 = true ;
V_9 = F_8 ( V_1 , L_1 , NULL , & V_15 ) ;
if ( F_6 ( V_9 ) || ! ( V_15 & V_16 ) )
* ( bool * ) V_3 = false ;
return V_8 ;
}
bool F_9 ( const T_4 V_13 [ V_14 ] )
{
T_1 V_9 ;
bool V_17 = false ;
V_9 = F_5 ( V_13 , F_7 , & V_17 , NULL ) ;
if ( F_6 ( V_9 ) )
return false ;
return V_17 ;
}
struct V_18 * F_10 ( struct V_18 * V_19 )
{
struct V_18 * V_20 ;
for ( V_20 = V_19 ; V_20 -> V_21 [ 0 ] ; V_20 ++ ) {
if ( F_9 ( V_20 -> V_21 ) == true ) {
if ( V_20 -> V_22 == NULL )
return V_20 ;
if ( V_20 -> V_22 ( V_20 ) != NULL )
return V_20 ;
}
}
return NULL ;
}
static T_1 F_11 ( T_2 V_1 , T_3 V_2 ,
void * V_3 , void * * V_4 )
{
struct V_5 * V_6 ;
T_1 V_9 = V_8 ;
struct V_23 * V_24 = V_3 ;
V_24 -> V_25 = false ;
if ( F_2 ( V_1 , & V_6 ) )
return V_8 ;
if ( V_6 -> V_9 . V_10 && V_6 -> V_9 . V_11 ) {
struct V_26 V_27 = { V_28 , NULL } ;
union V_29 * V_30 = NULL ;
V_9 = F_12 ( V_1 , V_24 -> V_7 ,
NULL , & V_27 ,
V_31 ) ;
if ( F_6 ( V_9 ) )
return V_8 ;
V_30 = V_27 . V_32 ;
if ( ! V_30 || V_30 -> V_33 . V_34 != V_24 -> V_35 ) {
F_13 ( V_27 . V_32 ) ;
return V_8 ;
}
V_9 = F_14 ( V_30 ,
V_24 -> V_36 , V_24 -> V_37 ) ;
if ( F_6 ( V_9 ) ) {
F_13 ( V_27 . V_32 ) ;
return V_8 ;
}
F_13 ( V_27 . V_32 ) ;
V_24 -> V_25 = true ;
return V_12 ;
}
return V_8 ;
}
bool F_15 ( const T_4 V_13 [ V_14 ] ,
struct V_23 * V_38 )
{
T_1 V_9 ;
V_9 = F_5 ( V_13 , F_11 , V_38 , NULL ) ;
if ( F_6 ( V_9 ) || ! V_38 -> V_25 )
return false ;
return true ;
}
struct V_18 * F_16 ( void * V_39 )
{
struct V_18 * V_20 = V_39 ;
struct V_40 * V_41 = (struct V_40 * ) V_20 -> V_42 ;
int V_43 ;
if ( V_20 -> V_42 == NULL )
return V_20 ;
for ( V_43 = 0 ; V_43 < V_41 -> V_44 ; V_43 ++ ) {
if ( F_9 ( V_41 -> V_45 [ V_43 ] ) != true )
return NULL ;
}
return V_20 ;
}
