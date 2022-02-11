T_1
F_1 ( char * V_1 ,
T_2 V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 ;
V_5 = F_2 ( sizeof( struct V_3 ) ) ;
if ( ! V_5 ) {
return ( V_6 ) ;
}
memset ( V_5 , 0 , sizeof( struct V_3 ) ) ;
V_5 -> V_1 = V_1 ;
V_5 -> V_2 = V_2 ;
* V_4 = V_5 ;
return ( V_7 ) ;
}
void * F_3 ( T_3 V_8 ,
T_4 V_9 , const char * V_10 , T_4 line )
{
struct V_11 * V_12 ;
T_1 V_13 ;
if ( ! V_8 ) {
F_4 ( ( V_10 , line ,
L_1 ) ) ;
V_8 = 1 ;
}
V_12 =
F_2 ( V_8 + sizeof( struct V_14 ) ) ;
if ( ! V_12 ) {
F_4 ( ( V_10 , line ,
L_2 , ( T_4 ) V_8 ) ) ;
return ( NULL ) ;
}
V_13 = F_5 ( V_12 , V_8 ,
V_15 , V_9 , V_10 ,
line ) ;
if ( F_6 ( V_13 ) ) {
F_7 ( V_12 ) ;
return ( NULL ) ;
}
V_16 -> V_17 ++ ;
V_16 -> V_18 += ( T_4 ) V_8 ;
V_16 -> V_19 += ( T_4 ) V_8 ;
if ( V_16 -> V_19 >
V_16 -> V_20 ) {
V_16 -> V_20 =
V_16 -> V_19 ;
}
return ( ( void * ) & V_12 -> V_21 ) ;
}
void * F_8 ( T_3 V_8 ,
T_4 V_9 ,
const char * V_10 , T_4 line )
{
struct V_11 * V_12 ;
T_1 V_13 ;
if ( ! V_8 ) {
F_4 ( ( V_10 , line ,
L_1 ) ) ;
V_8 = 1 ;
}
V_12 =
F_9 ( V_8 +
sizeof( struct V_14 ) ) ;
if ( ! V_12 ) {
F_10 ( ( V_10 , line ,
L_2 , ( T_4 ) V_8 ) ) ;
return ( NULL ) ;
}
V_13 = F_5 ( V_12 , V_8 ,
V_22 , V_9 , V_10 ,
line ) ;
if ( F_6 ( V_13 ) ) {
F_7 ( V_12 ) ;
return ( NULL ) ;
}
V_16 -> V_17 ++ ;
V_16 -> V_18 += ( T_4 ) V_8 ;
V_16 -> V_19 += ( T_4 ) V_8 ;
if ( V_16 -> V_19 >
V_16 -> V_20 ) {
V_16 -> V_20 =
V_16 -> V_19 ;
}
return ( ( void * ) & V_12 -> V_21 ) ;
}
void
F_11 ( void * V_12 ,
T_4 V_9 , const char * V_10 , T_4 line )
{
struct V_11 * V_23 ;
T_1 V_13 ;
F_12 ( V_24 , V_12 ) ;
if ( NULL == V_12 ) {
F_10 ( ( V_10 , line , L_3 ) ) ;
V_25 ;
}
V_23 = F_13 ( struct V_11 ,
( ( ( char * ) V_12 ) -
sizeof( struct V_14 ) ) ) ;
V_16 -> V_26 ++ ;
V_16 -> V_19 -= V_23 -> V_8 ;
V_13 = F_14 ( V_23 ,
V_9 , V_10 , line ) ;
if ( F_6 ( V_13 ) ) {
F_15 ( ( V_27 , V_13 , L_4 ) ) ;
}
F_7 ( V_23 ) ;
F_16 ( ( V_28 , L_5 ,
V_12 , V_23 ) ) ;
V_25 ;
}
static struct V_11 * F_17 ( struct
V_11
* V_12 )
{
struct V_11 * V_29 ;
V_29 = V_16 -> V_30 ;
if ( ! V_29 ) {
return ( NULL ) ;
}
while ( V_29 > V_12 ) {
if ( ! V_29 -> V_31 ) {
return ( V_29 ) ;
}
V_29 = V_29 -> V_31 ;
}
if ( V_29 == V_12 ) {
return ( V_29 ) ;
}
return ( V_29 -> V_32 ) ;
}
static T_1
F_5 ( struct V_11 * V_12 ,
T_3 V_8 ,
T_5 V_33 ,
T_4 V_9 , const char * V_10 , T_4 line )
{
struct V_3 * V_34 ;
struct V_11 * V_29 ;
T_1 V_13 = V_7 ;
F_12 ( V_35 , V_12 ) ;
if ( V_36 ) {
F_18 ( V_7 ) ;
}
V_34 = V_16 ;
V_13 = F_19 ( V_37 ) ;
if ( F_6 ( V_13 ) ) {
F_18 ( V_13 ) ;
}
V_29 = F_17 ( V_12 ) ;
if ( V_29 == V_12 ) {
F_10 ( ( V_27 ,
L_6 ,
V_12 ) ) ;
goto V_38;
}
V_12 -> V_8 = ( T_4 ) V_8 ;
V_12 -> V_33 = V_33 ;
V_12 -> V_9 = V_9 ;
V_12 -> line = line ;
strncpy ( V_12 -> V_10 , V_10 , V_39 ) ;
V_12 -> V_10 [ V_39 - 1 ] = 0 ;
if ( ! V_29 ) {
if ( V_34 -> V_30 ) {
( (struct V_11 * ) ( V_34 -> V_30 ) ) ->
V_32 = V_12 ;
}
V_12 -> V_31 = V_34 -> V_30 ;
V_12 -> V_32 = NULL ;
V_34 -> V_30 = V_12 ;
} else {
V_12 -> V_31 = V_29 -> V_31 ;
V_12 -> V_32 = V_29 ;
if ( V_29 -> V_31 ) {
( V_29 -> V_31 ) -> V_32 = V_12 ;
}
V_29 -> V_31 = V_12 ;
}
V_38:
V_13 = F_20 ( V_37 ) ;
F_18 ( V_13 ) ;
}
static T_1
F_14 ( struct V_11 * V_12 ,
T_4 V_9 , const char * V_10 , T_4 line )
{
struct V_3 * V_34 ;
T_1 V_13 ;
F_21 ( V_40 ) ;
if ( V_36 ) {
return ( V_7 ) ;
}
V_34 = V_16 ;
if ( NULL == V_34 -> V_30 ) {
F_10 ( ( V_10 , line ,
L_7 ) ) ;
return ( V_7 ) ;
}
V_13 = F_19 ( V_37 ) ;
if ( F_6 ( V_13 ) ) {
return ( V_13 ) ;
}
if ( V_12 -> V_32 ) {
( V_12 -> V_32 ) -> V_31 = V_12 -> V_31 ;
} else {
V_34 -> V_30 = V_12 -> V_31 ;
}
if ( V_12 -> V_31 ) {
( V_12 -> V_31 ) -> V_32 = V_12 -> V_32 ;
}
F_16 ( ( V_28 , L_8 ,
& V_12 -> V_21 , V_12 -> V_8 ) ) ;
memset ( & V_12 -> V_21 , 0xEA , V_12 -> V_8 ) ;
V_13 = F_20 ( V_37 ) ;
return ( V_13 ) ;
}
void F_22 ( void )
{
F_23 ( V_41 ) ;
V_25 ;
}
void F_24 ( T_4 V_9 , const char * V_10 )
{
struct V_11 * V_29 ;
union V_42 * V_43 ;
T_4 V_44 = 0 ;
T_5 V_45 ;
F_23 ( V_46 ) ;
if ( V_36 ) {
V_25 ;
}
if ( F_6 ( F_19 ( V_37 ) ) ) {
V_25 ;
}
V_29 = V_16 -> V_30 ;
while ( V_29 ) {
if ( ( V_29 -> V_9 & V_9 ) &&
( ( V_10 == NULL )
|| ( 0 == strcmp ( V_10 , V_29 -> V_10 ) ) ) ) {
V_43 =
F_13 ( union V_42 ,
& V_29 -> V_21 ) ;
if ( V_29 -> V_8 <
sizeof( struct V_47 ) ) {
F_25 ( L_9
L_10 ,
V_43 , V_29 -> V_8 ,
V_29 -> V_10 , V_29 -> line ) ;
} else {
if ( F_26 ( V_43 ) !=
V_48 ) {
F_25
( L_11 ,
V_43 , V_29 -> V_8 ,
V_29 -> V_10 , V_29 -> line ,
F_27
( V_43 ) ) ;
V_45 = 0 ;
switch ( F_26
( V_43 ) ) {
case V_49 :
if ( V_29 -> V_8 ==
sizeof( union
V_50 ) )
{
V_45 =
V_49 ;
}
break;
case V_51 :
if ( V_29 -> V_8 ==
sizeof( union
V_52 ) ) {
V_45 =
V_51 ;
}
break;
case V_53 :
if ( V_29 -> V_8 ==
sizeof( struct
V_54 ) )
{
V_45 =
V_53 ;
}
break;
default:
break;
}
switch ( V_45 ) {
case V_49 :
F_25
( L_12 ,
F_28
( V_43 -> V_55 . V_56 .
type ) ,
V_43 -> V_55 . V_56 .
V_57 ) ;
break;
case V_51 :
F_25
( L_13 ,
V_43 -> V_58 . V_59 .
V_60 ) ;
break;
case V_53 :
F_25 ( L_14 ,
F_29
( & V_43 ->
V_61 ) ) ;
break;
default:
F_25 ( L_15 ) ;
break;
}
}
}
V_44 ++ ;
}
V_29 = V_29 -> V_31 ;
}
( void ) F_20 ( V_37 ) ;
if ( ! V_44 ) {
F_30 ( ( V_27 , L_16 ) ) ;
} else {
F_10 ( ( V_27 , L_17 ,
V_44 , V_44 ) ) ;
}
V_25 ;
}
