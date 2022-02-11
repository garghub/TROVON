void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
T_1 type ;
F_2 () ;
if ( ! F_3 ( V_4 , V_5 ) ) {
return;
}
do {
F_4 ( L_1 , V_3 ) ;
V_3 ++ ;
type = V_2 -> type ;
if ( type > V_6 ) {
F_4
( L_2 ,
V_2 -> type ) ;
return;
}
if ( ! V_2 -> V_7 ) {
F_4
( L_3 ) ;
return;
}
if ( type == V_8 ) {
F_5 ( & V_2 -> V_9 ,
V_10
[ V_2 -> V_9 .
V_11 . type ] ) ;
} else {
F_5 ( & V_2 -> V_9 ,
V_12
[ type ] ) ;
}
V_2 = F_6 ( V_2 ) ;
} while ( type != V_13 );
}
void F_7 ( T_2 * V_14 )
{
struct V_15 * V_16 ;
T_2 V_3 ;
F_2 () ;
if ( ! F_3 ( V_4 , V_5 ) ) {
return;
}
V_16 = F_8 ( struct V_15 , V_14 ) ;
for ( V_3 = 0 ; V_16 -> V_7 ; V_3 ++ ) {
F_4 ( L_4 ,
V_3 ) ;
F_5 ( V_16 , V_17 ) ;
V_16 = F_9 ( struct V_15 ,
V_16 , V_16 -> V_7 ) ;
}
}
static void
F_5 ( void * V_18 , struct V_19 * V_20 )
{
T_2 * V_21 = NULL ;
T_2 * V_22 ;
const char * V_23 ;
T_2 V_3 ;
V_3 = V_20 -> V_24 ;
while ( V_3 ) {
V_22 = V_21 ;
V_21 = F_9 ( T_2 , V_18 , V_20 -> V_24 ) ;
V_23 = V_20 -> V_23 ;
switch ( V_20 -> V_25 ) {
case V_26 :
if ( V_20 -> V_23 ) {
F_4 ( L_5 , V_23 ) ;
}
break;
case V_27 :
F_10 ( V_23 ,
F_8 ( char , V_20 -> V_28 ) ) ;
break;
case V_29 :
F_10 ( V_23 , F_8 ( char , V_21 ) ) ;
break;
case V_30 :
if ( V_20 -> V_28 ) {
F_10 ( V_23 ,
V_20 -> V_28 [ * V_21 ] ) ;
} else {
F_11 ( V_23 , F_12 ( V_21 ) ) ;
}
break;
case V_31 :
F_13 ( V_23 , F_14 ( V_21 ) ) ;
break;
case V_32 :
F_15 ( V_23 , F_16 ( V_21 ) ) ;
break;
case V_33 :
F_17 ( V_23 , F_18 ( V_21 ) ) ;
break;
case V_34 :
F_10 ( V_23 ,
V_20 -> V_28 [ * V_21 & 0x01 ] ) ;
break;
case V_35 :
F_10 ( V_23 ,
V_20 -> V_28 [ * V_21 & 0x03 ] ) ;
break;
case V_36 :
F_10 ( V_23 ,
V_20 -> V_28 [ * V_21 & 0x07 ] ) ;
break;
case V_37 :
if ( V_22 ) {
F_19 ( V_23 ) ;
F_20 ( * V_22 ,
V_21 ) ;
}
break;
case V_38 :
if ( V_22 ) {
F_19 ( V_23 ) ;
F_20 ( * V_22 ,
*
( F_21
( T_2 , V_21 ) ) ) ;
}
break;
case V_39 :
if ( V_22 ) {
F_22 ( F_14
( V_22 ) ,
V_21 ) ;
}
break;
case V_40 :
if ( V_22 ) {
F_23 ( * V_22 ,
F_8 ( T_1 ,
V_21 ) ) ;
}
break;
case V_41 :
if ( V_22 ) {
F_24 ( * V_22 ,
* ( F_21
( V_42 , V_21 ) ) ) ;
}
break;
case V_43 :
F_25 ( F_8
( union V_44 ,
V_21 ) ) ;
break;
case V_45 :
F_26 ( F_8
( struct
V_46 ,
V_21 ) ) ;
break;
default:
F_4 ( L_6 ,
V_20 -> V_25 ) ;
return;
}
V_20 ++ ;
V_3 -- ;
}
}
static void
F_26 ( struct V_46 * V_47 )
{
F_2 () ;
if ( V_47 -> V_48 == 0xFF ) {
return;
}
F_11 ( L_7 , V_47 -> V_48 ) ;
F_10 ( L_8 ,
V_47 -> V_49 ?
V_47 -> V_49 : L_9 ) ;
}
static void F_25 ( union V_44 * V_18 )
{
F_2 () ;
switch ( V_18 -> V_50 . V_51 ) {
case V_52 :
F_5 ( V_18 , V_53 ) ;
break;
case V_54 :
F_5 ( V_18 , V_55 ) ;
break;
case V_56 :
F_10 ( L_10 , L_11 ) ;
break;
default:
F_11 ( L_10 ,
( T_2 ) V_18 -> V_50 . V_51 ) ;
break;
}
F_5 ( V_18 , V_57 ) ;
}
static void F_10 ( const char * V_58 , const char * V_59 )
{
F_4 ( L_12 , V_58 , V_59 ) ;
if ( ! * V_59 ) {
F_4 ( L_13 ) ;
}
F_4 ( L_14 ) ;
}
static void F_11 ( const char * V_58 , T_2 V_59 )
{
F_4 ( L_15 , V_58 , V_59 ) ;
}
static void F_13 ( const char * V_58 , V_42 V_59 )
{
F_4 ( L_16 , V_58 , V_59 ) ;
}
static void F_15 ( const char * V_58 , T_1 V_59 )
{
F_4 ( L_17 , V_58 , V_59 ) ;
}
static void F_17 ( const char * V_58 , T_3 V_59 )
{
F_4 ( L_18 , V_58 , F_27 ( V_59 ) ) ;
}
static void F_19 ( const char * V_58 )
{
F_4 ( L_19 , V_58 ) ;
}
static void F_22 ( V_42 V_7 , T_2 * V_9 )
{
T_2 V_60 ;
for ( V_60 = 0 ; V_60 < V_7 ; V_60 ++ ) {
F_4 ( L_20 , L_21 , V_60 , V_9 [ V_60 ] ) ;
}
}
static void F_20 ( T_2 V_7 , T_2 * V_9 )
{
T_2 V_60 ;
for ( V_60 = 0 ; V_60 < V_7 ; V_60 ++ ) {
F_4 ( L_22 , V_9 [ V_60 ] ) ;
}
F_4 ( L_14 ) ;
}
static void F_23 ( T_2 V_7 , T_1 * V_9 )
{
T_2 V_60 ;
for ( V_60 = 0 ; V_60 < V_7 ; V_60 ++ ) {
F_4 ( L_23 , L_24 , V_60 , V_9 [ V_60 ] ) ;
}
}
static void F_24 ( V_42 V_7 , V_42 * V_9 )
{
V_42 V_60 ;
for ( V_60 = 0 ; V_60 < V_7 ; V_60 ++ ) {
F_4 ( L_25 , L_26 , V_60 , V_9 [ V_60 ] ) ;
}
}
