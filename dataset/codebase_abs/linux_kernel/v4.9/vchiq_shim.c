const T_1 *
F_1 ( void )
{
return NULL ;
}
const T_2 *
F_2 ( void )
{
return NULL ;
}
T_3 * F_3 (
const T_2 * V_1 ,
const T_1 * V_2 )
{
( void ) V_1 ;
( void ) V_2 ;
return NULL ;
}
T_4 F_4 ( T_5 V_3 ,
void * * V_4 ,
T_6 * V_5 ,
T_7 V_6 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_9 * V_8 ;
F_5 ( ( V_6 != V_9 ) &&
( V_6 != V_10 ) ) ;
if ( V_6 == V_9 )
if ( F_6 ( & V_7 -> V_11 ) )
return - 1 ;
V_8 = F_7 ( & V_7 -> V_11 ) ;
* V_4 = V_8 -> V_4 ;
* V_5 = V_8 -> V_12 ;
return 0 ;
}
T_4 F_8 ( T_5 V_3 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_9 * V_8 ;
V_8 = F_9 ( & V_7 -> V_11 ) ;
F_10 ( V_7 -> V_3 , V_8 ) ;
return 0 ;
}
T_4 F_11 ( T_5 V_3 ,
const void * V_4 ,
T_6 V_13 ,
T_7 V_6 ,
void * V_14 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_10 V_15 = { V_4 , V_13 } ;
T_11 V_16 ;
( void ) V_14 ;
F_5 ( V_6 != V_17 ) ;
V_16 = F_12 ( V_7 -> V_3 , & V_15 , 1 ) ;
while ( V_16 == V_18 ) {
F_13 ( 1 ) ;
V_16 = F_12 ( V_7 -> V_3 , & V_15 , 1 ) ;
}
return F_14 ( V_16 ) ;
}
T_4 F_15 ( T_5 V_3 ,
void * V_19 ,
T_6 V_13 ,
T_7 V_6 ,
void * V_20 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_12 V_21 ;
T_11 V_16 ;
switch ( ( int ) V_6 ) {
case V_22
| V_17 :
F_5 ( ! V_7 -> V_23 ) ;
V_21 = V_24 ;
break;
case V_10 :
V_21 = V_25 ;
break;
case V_17 :
case V_9 :
V_21 = V_26 ;
break;
default:
F_16 ( 1 , L_1 ) ;
return F_14 ( V_27 ) ;
}
V_16 = F_17 ( V_7 -> V_3 , V_19 , V_13 ,
V_20 , V_21 ) ;
while ( V_16 == V_18 ) {
F_13 ( 1 ) ;
V_16 = F_17 ( V_7 -> V_3 , V_19 ,
V_13 , V_20 , V_21 ) ;
}
return F_14 ( V_16 ) ;
}
T_4 F_18 ( T_5 V_3 ,
const void * V_28 ,
T_6 V_13 ,
T_7 V_6 ,
void * V_20 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_12 V_21 ;
T_11 V_16 ;
switch ( ( int ) V_6 ) {
case V_22
| V_17 :
F_5 ( ! V_7 -> V_23 ) ;
V_21 = V_24 ;
break;
case V_29 :
case V_10 :
V_21 = V_25 ;
break;
case V_17 :
case V_9 :
V_21 = V_26 ;
break;
default:
F_16 ( 1 , L_1 ) ;
return F_14 ( V_27 ) ;
}
V_16 = F_19 ( V_7 -> V_3 , V_28 , V_13 ,
V_20 , V_21 ) ;
while ( V_16 == V_18 ) {
F_13 ( 1 ) ;
V_16 = F_19 ( V_7 -> V_3 , V_28 ,
V_13 , V_20 , V_21 ) ;
}
return F_14 ( V_16 ) ;
}
T_4 F_20 ( T_5 V_3 ,
void * V_4 ,
T_6 V_30 ,
T_6 * V_31 ,
T_7 V_6 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_9 * V_8 ;
F_5 ( ( V_6 != V_9 ) &&
( V_6 != V_10 ) ) ;
if ( V_6 == V_9 )
if ( F_6 ( & V_7 -> V_11 ) )
return - 1 ;
V_8 = F_9 ( & V_7 -> V_11 ) ;
memcpy ( V_4 , V_8 -> V_4 , V_8 -> V_12 < V_30 ?
V_8 -> V_12 : V_30 ) ;
* V_31 = V_8 -> V_12 ;
F_10 ( V_7 -> V_3 , V_8 ) ;
return 0 ;
}
T_4 F_21 ( T_5 V_3 ,
T_13 * V_32 ,
T_6 V_33 ,
T_7 V_6 ,
void * V_14 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
( void ) V_14 ;
F_5 ( V_6 != V_17 ) ;
return F_14 ( F_12 ( V_7 -> V_3 ,
( const T_10 * ) V_32 , V_33 ) ) ;
}
T_4 F_22 ( T_14 * V_34 )
{
F_10 ( ( V_35 ) V_34 -> V_7 ,
( T_9 * ) V_34 -> V_34 ) ;
return 0 ;
}
T_4 F_23 ( T_5 V_3 ,
void * * V_4 ,
T_6 * V_5 ,
T_7 V_6 ,
T_14 * V_36 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_9 * V_8 ;
F_5 ( ( V_6 != V_9 ) &&
( V_6 != V_10 ) ) ;
if ( V_6 == V_9 )
if ( F_6 ( & V_7 -> V_11 ) )
return - 1 ;
V_8 = F_9 ( & V_7 -> V_11 ) ;
* V_4 = V_8 -> V_4 ;
* V_5 = V_8 -> V_12 ;
V_36 -> V_7 =
(struct V_37 * ) V_7 -> V_3 ;
V_36 -> V_34 = V_8 ;
return 0 ;
}
T_4 F_24 ( T_15 * V_38 )
{
T_16 V_39 ;
T_11 V_16 ;
V_16 = F_25 ( & V_39 ) ;
* V_38 = ( T_15 ) V_39 ;
return F_14 ( V_16 ) ;
}
T_4 F_26 ( T_3 * * V_40 ,
const T_6 V_41 ,
T_15 V_38 )
{
T_16 V_39 = ( T_16 ) V_38 ;
( void ) V_40 ;
( void ) V_41 ;
return F_27 ( V_39 ) ;
}
T_4 F_28 ( T_15 V_38 )
{
T_16 V_39 = ( T_16 ) V_38 ;
return F_14 ( F_29 ( V_39 ) ) ;
}
static T_11 F_30 ( T_17 V_42 ,
T_9 * V_8 , V_35 V_3 , void * V_43 )
{
T_8 * V_7 =
( T_8 * ) F_31 ( V_3 ) ;
if ( ! V_7 -> V_23 )
goto V_44;
switch ( V_42 ) {
case V_45 :
F_32 ( & V_7 -> V_11 , V_8 ) ;
V_7 -> V_23 ( V_7 -> V_46 ,
V_47 , NULL ) ;
goto V_48;
break;
case V_49 :
V_7 -> V_23 ( V_7 -> V_46 ,
V_50 , V_43 ) ;
break;
case V_51 :
V_7 -> V_23 ( V_7 -> V_46 ,
V_52 , V_43 ) ;
break;
case V_53 :
V_7 -> V_23 ( V_7 -> V_46 ,
V_54 , NULL ) ;
break;
case V_55 :
break;
case V_56 :
V_7 -> V_23 ( V_7 -> V_46 ,
V_57 ,
V_43 ) ;
break;
case V_58 :
V_7 -> V_23 ( V_7 -> V_46 ,
V_59 ,
V_43 ) ;
break;
default:
F_16 ( 1 , L_2 ) ;
break;
}
V_44:
F_10 ( V_7 -> V_3 , V_8 ) ;
V_48:
return V_60 ;
}
static T_8 * F_33 ( T_16 V_39 ,
T_18 * V_61 )
{
T_8 * V_7 = F_34 ( sizeof( T_8 ) , V_62 ) ;
( void ) V_39 ;
if ( V_7 ) {
if ( F_35 ( & V_7 -> V_11 , 64 ) ) {
V_7 -> V_23 = V_61 -> V_23 ;
V_7 -> V_46 = V_61 -> V_46 ;
} else {
F_36 ( V_7 ) ;
V_7 = NULL ;
}
}
return V_7 ;
}
static void F_37 ( T_8 * V_7 )
{
if ( V_7 ) {
F_38 ( & V_7 -> V_11 ) ;
F_36 ( V_7 ) ;
}
}
T_4 F_39 ( T_15 V_38 ,
T_18 * V_61 ,
T_5 * V_3 )
{
T_16 V_39 = ( T_16 ) V_38 ;
T_8 * V_7 = F_33 ( V_39 , V_61 ) ;
* V_3 = ( T_5 ) V_7 ;
if ( V_7 ) {
T_19 V_63 ;
T_11 V_16 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_64 = V_61 -> V_65 ;
V_63 . V_23 = F_30 ;
V_63 . V_66 = V_7 ;
V_63 . V_67 = V_61 -> V_67 . V_67 ;
V_63 . V_68 = V_61 -> V_67 . V_68 ;
V_16 = F_40 ( V_39 , & V_63 ,
& V_7 -> V_3 ) ;
if ( V_16 != V_60 ) {
F_37 ( V_7 ) ;
V_7 = NULL ;
* V_3 = NULL ;
}
}
return ( V_7 != NULL ) ? 0 : - 1 ;
}
T_4 F_41 ( T_15 V_38 ,
T_18 * V_61 ,
T_5 * V_3 )
{
T_16 V_39 = ( T_16 ) V_38 ;
T_8 * V_7 = F_33 ( V_39 , V_61 ) ;
* V_3 = ( T_5 ) V_7 ;
if ( V_7 ) {
T_19 V_63 ;
T_11 V_16 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_64 = V_61 -> V_65 ;
V_63 . V_23 = F_30 ;
V_63 . V_66 = V_7 ;
V_63 . V_67 = V_61 -> V_67 . V_67 ;
V_63 . V_68 = V_61 -> V_67 . V_68 ;
V_16 = F_42 ( V_39 , & V_63 , & V_7 -> V_3 ) ;
if ( V_16 != V_60 ) {
F_37 ( V_7 ) ;
V_7 = NULL ;
* V_3 = NULL ;
}
}
return ( V_7 != NULL ) ? 0 : - 1 ;
}
T_4 F_43 ( const T_5 V_3 )
{
T_4 V_69 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if ( V_7 ) {
T_11 V_16 = F_44 ( V_7 -> V_3 ) ;
if ( V_16 == V_60 ) {
F_37 ( V_7 ) ;
V_7 = NULL ;
}
V_69 = F_14 ( V_16 ) ;
}
return V_69 ;
}
T_4 F_45 ( const T_5 V_3 )
{
T_4 V_69 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if ( V_7 ) {
T_11 V_16 = F_46 ( V_7 -> V_3 ) ;
if ( V_16 == V_60 ) {
F_37 ( V_7 ) ;
V_7 = NULL ;
}
V_69 = F_14 ( V_16 ) ;
}
return V_69 ;
}
T_4 F_47 ( const T_5 V_3 ,
T_20 V_70 ,
int V_71 )
{
T_4 V_69 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
T_21 V_72 ;
switch ( V_70 ) {
case V_73 :
V_72 = V_74 ;
break;
case V_75 :
V_72 = V_76 ;
break;
default:
V_7 = NULL ;
break;
}
if ( V_7 ) {
T_11 V_16 =
F_48 ( V_7 -> V_3 ,
V_72 ,
V_71 ) ;
V_69 = F_14 ( V_16 ) ;
}
return V_69 ;
}
T_4 F_49 ( const T_5 V_3 , short * V_77 )
{
T_4 V_69 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if( V_7 )
{
T_11 V_16 = F_50 ( V_7 -> V_3 , V_77 ) ;
V_69 = F_14 ( V_16 ) ;
}
return V_69 ;
}
T_6
F_51 ( const void * V_78 )
{
const unsigned char * V_79 = V_78 ;
return V_79 [ 0 ] | ( V_79 [ 1 ] << 8 ) | ( V_79 [ 2 ] << 16 ) | ( V_79 [ 3 ] << 24 ) ;
}
void
F_52 ( void * V_78 , T_6 V_71 )
{
unsigned char * V_79 = V_78 ;
V_79 [ 0 ] = ( unsigned char ) ( ( V_71 >> 0 ) & 0xFF ) ;
V_79 [ 1 ] = ( unsigned char ) ( ( V_71 >> 8 ) & 0xFF ) ;
V_79 [ 2 ] = ( unsigned char ) ( ( V_71 >> 16 ) & 0xFF ) ;
V_79 [ 3 ] = ( unsigned char ) ( ( V_71 >> 24 ) & 0xFF ) ;
}
T_22
F_53 ( const void * V_78 )
{
const unsigned char * V_79 = V_78 ;
return V_79 [ 0 ] | ( V_79 [ 1 ] << 8 ) ;
}
void
F_54 ( void * V_78 , T_22 V_71 )
{
unsigned char * V_79 = V_78 ;
V_79 [ 0 ] = ( V_71 >> 0 ) & 0xFF ;
V_79 [ 1 ] = ( V_71 >> 8 ) & 0xFF ;
}
T_4 F_55 ( const T_5 V_3 )
{
T_4 V_69 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if ( V_7 )
V_69 = F_14 ( F_56 ( V_7 -> V_3 ) ) ;
return V_69 ;
}
T_4 F_57 ( const T_5 V_3 )
{
T_4 V_69 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if ( V_7 )
V_69 = F_14 (
F_58 ( V_7 -> V_3 ) ) ;
return V_69 ;
}
