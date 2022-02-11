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
struct V_17 * F_9 ( struct V_17 * V_18 )
{
struct V_17 * V_19 ;
bool V_20 = false ;
for ( V_19 = V_18 ; V_19 -> V_21 [ 0 ] ; V_19 ++ )
if ( F_10 ( F_5 ( V_19 -> V_21 ,
F_7 ,
& V_20 , NULL ) ) && V_20 )
return V_19 ;
return NULL ;
}
static T_1 F_11 ( T_2 V_1 , T_3 V_2 ,
void * V_3 , void * * V_4 )
{
struct V_5 * V_6 ;
T_1 V_9 = V_8 ;
struct V_22 * V_23 = V_3 ;
V_23 -> V_24 = false ;
if ( F_2 ( V_1 , & V_6 ) )
return V_8 ;
if ( V_6 -> V_9 . V_10 && V_6 -> V_9 . V_11 ) {
struct V_25 V_26 = { V_27 , NULL } ;
union V_28 * V_29 = NULL ;
V_9 = F_12 ( V_1 , V_23 -> V_7 ,
NULL , & V_26 ,
V_30 ) ;
if ( F_6 ( V_9 ) )
return V_8 ;
V_29 = V_26 . V_31 ;
if ( ! V_29 || V_29 -> V_32 . V_33 != V_23 -> V_34 ) {
F_13 ( V_26 . V_31 ) ;
return V_8 ;
}
V_9 = F_14 ( V_29 ,
V_23 -> V_35 , V_23 -> V_36 ) ;
if ( F_6 ( V_9 ) ) {
F_13 ( V_26 . V_31 ) ;
return V_8 ;
}
F_13 ( V_26 . V_31 ) ;
V_23 -> V_24 = true ;
return V_12 ;
}
return V_8 ;
}
bool F_15 ( const T_4 V_13 [ V_14 ] ,
struct V_22 * V_37 )
{
T_1 V_9 ;
V_9 = F_5 ( V_13 , F_11 , V_37 , NULL ) ;
if ( F_6 ( V_9 ) || ! V_37 -> V_24 )
return false ;
return true ;
}
