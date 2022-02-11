const char *
F_1 ( const char * V_1 )
{
return ( const char * ) F_2 ( V_2 , V_1 ) ;
}
static void
F_3 ( const char * V_1 , const char * V_3 )
{
if ( F_1 ( V_1 ) ) {
return;
}
F_4 ( V_2 , F_5 ( V_1 ) , F_5 ( V_3 ) ) ;
}
static int
F_6 ( void * T_1 V_4 , T_2 * V_5 , T_3 * V_6 , const void * V_7 )
{
const T_4 * V_8 = ( const T_4 * ) V_7 ;
void * V_9 = NULL ;
char * V_10 ;
char * V_1 ;
int V_11 ;
int V_12 ;
int V_13 ;
T_5 * V_14 ;
T_5 * V_15 ;
T_5 * V_16 ;
T_6 * V_17 ;
T_6 * V_18 ;
T_6 * V_19 ;
char V_20 [ 256 ] ;
int V_21 ;
V_14 = F_7 ( V_6 -> V_22 , V_23 ) ;
if( ! V_14 || V_14 -> V_24 != 1 ) {
return 0 ;
}
V_17 = ( T_6 * ) V_14 -> V_25 [ 0 ] ;
V_21 = V_17 -> V_26 . V_26 . V_27 ;
if( V_21 != 1 ) {
return 0 ;
}
if( ! V_8 ) {
return 0 ;
}
if( ! V_8 -> V_28 ) {
return 0 ;
}
if( V_8 -> V_29 == V_30 ) {
V_14 = F_7 ( V_6 -> V_22 , V_31 ) ;
if( ! V_14 || V_14 -> V_24 != 1 ) {
return 0 ;
}
V_17 = ( T_6 * ) V_14 -> V_25 [ 0 ] ;
V_9 = F_2 ( V_32 , F_8 ( V_5 -> V_33 ) ) ;
if( V_9 ) {
F_9 ( V_32 , F_8 ( V_5 -> V_33 ) ) ;
}
if( ! V_9 ) {
V_9 = F_10 ( F_11 () , V_17 -> V_26 . V_26 . V_34 -> V_35 , 20 ) ;
}
F_4 ( V_32 , F_8 ( V_5 -> V_33 ) , V_9 ) ;
return 0 ;
}
if( ! V_8 -> V_28 -> V_36 ) {
return 0 ;
}
V_9 = F_2 ( V_32 , F_8 ( V_8 -> V_28 -> V_36 ) ) ;
if( ! V_9 ) {
return 0 ;
}
if ( ! F_12 ( ( V_37 * ) V_9 , & V_10 , NULL , NULL , NULL , V_8 -> V_28 -> V_36 ) ) {
return 0 ;
}
if ( ! V_10 )
return 0 ;
V_1 = strstr ( V_10 , L_1 ) ;
if( ! V_1 ) {
return 0 ;
}
for( V_11 = 4 ; 1 ; V_11 ++ ) {
if( ( V_1 [ V_11 ] >= '0' ) && ( V_1 [ V_11 ] <= '9' ) ) {
continue;
}
if( V_1 [ V_11 ] == '-' ) {
continue;
}
break;
}
V_15 = F_7 ( V_6 -> V_22 , V_38 ) ;
if( ! V_15 || V_15 -> V_24 < 1 ) {
return 0 ;
}
V_12 = V_15 -> V_24 ;
V_16 = F_7 ( V_6 -> V_22 , V_39 ) ;
if( ! V_16 || V_16 -> V_24 < 1 ) {
return 0 ;
}
V_13 = V_16 -> V_24 ;
if( V_12 > V_13 ) {
V_12 = V_13 ;
}
for(; V_12 ; V_12 -- ) {
int V_24 = V_11 ;
if ( V_24 > 247 )
V_24 = 247 ;
V_18 = ( T_6 * ) V_15 -> V_25 [ V_12 - 1 ] ;
V_19 = ( T_6 * ) V_16 -> V_25 [ V_12 - 1 ] ;
F_13 ( V_20 , V_1 , 256 ) ;
V_20 [ V_24 ++ ] = '-' ;
F_14 ( V_20 + V_24 , 256 - V_24 , L_2 , V_18 -> V_26 . V_26 . V_27 ) ;
F_3 ( V_20 , V_19 -> V_26 . V_26 . string ) ;
}
return 1 ;
}
static int
F_15 ( void * T_1 V_4 , T_2 * V_5 V_4 , T_3 * V_6 , const void * V_7 V_4 )
{
T_5 * V_14 ;
T_6 * V_17 ;
char * V_40 ;
char * V_1 ;
int V_21 ;
V_14 = F_7 ( V_6 -> V_22 , V_41 ) ;
if( ! V_14 || V_14 -> V_24 != 1 ) {
return 0 ;
}
V_17 = ( T_6 * ) V_14 -> V_25 [ 0 ] ;
V_21 = V_17 -> V_26 . V_26 . V_27 ;
switch( V_21 ) {
case 3 :
case 5 :
case 12 :
V_14 = F_7 ( V_6 -> V_22 , V_42 ) ;
if( ! V_14 || V_14 -> V_24 != 1 ) {
return 0 ;
}
V_17 = ( T_6 * ) V_14 -> V_25 [ 0 ] ;
V_40 = V_17 -> V_26 . V_26 . string ;
V_14 = F_7 ( V_6 -> V_22 , V_43 ) ;
if( ! V_14 || V_14 -> V_24 != 1 ) {
return 0 ;
}
V_17 = ( T_6 * ) V_14 -> V_25 [ 0 ] ;
V_1 = V_17 -> V_26 . V_26 . string ;
F_3 ( V_1 , V_40 ) ;
break;
}
return 0 ;
}
static T_7
F_16 ( T_8 V_44 , T_8 V_45 )
{
int V_46 = F_17 ( V_44 ) ;
int V_47 = F_17 ( V_45 ) ;
return V_46 == V_47 ;
}
static T_9
F_18 ( T_8 V_48 )
{
int V_49 = F_17 ( V_48 ) ;
return V_49 ;
}
static void
F_19 ( void )
{
T_10 * V_50 ;
if( V_51 ) {
F_20 ( & V_51 ) ;
V_51 = FALSE ;
}
if( V_52 ) {
F_20 ( & V_52 ) ;
V_52 = FALSE ;
}
V_2 = F_21 ( V_53 , V_54 ,
V_55 , V_55 ) ;
V_32 = F_22 ( F_18 , F_16 ) ;
V_56 = FALSE ;
if( ! V_56 ) {
return;
}
#if 0
hf_lsa = proto_get_id_by_filter_name("lsa");
hf_lsa_opnum = proto_registrar_get_id_byname("lsa.opnum");
#endif
V_43 = F_23 ( L_3 ) ;
V_42 = F_23 ( L_4 ) ;
V_41 = F_23 ( L_5 ) ;
V_31 = F_23 ( L_6 ) ;
V_38 = F_23 ( L_7 ) ;
V_39 = F_23 ( L_8 ) ;
V_23 = F_23 ( L_9 ) ;
V_50 = F_24 ( L_10 ,
& V_51 ,
L_11 ,
V_57 , NULL , F_15 , NULL ) ;
if( V_50 ) {
F_25 ( L_12 ,
V_50 -> V_58 ) ;
F_26 ( V_50 , TRUE ) ;
return;
}
V_51 = TRUE ;
V_50 = F_24 ( L_10 ,
& V_52 ,
L_13 ,
V_57 , NULL , F_6 , NULL ) ;
if( V_50 ) {
F_25 ( L_14 ,
V_50 -> V_58 ) ;
F_26 ( V_50 , TRUE ) ;
return;
}
V_52 = TRUE ;
}
static void
F_27 ( void )
{
F_28 ( V_2 ) ;
F_28 ( V_32 ) ;
}
void
F_29 ( void )
{
F_30 ( F_19 ) ;
F_31 ( F_27 ) ;
}
