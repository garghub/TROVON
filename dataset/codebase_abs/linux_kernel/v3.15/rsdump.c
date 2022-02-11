static void
F_1 ( void * V_1 , struct V_2 * V_3 )
{
T_1 * V_4 = NULL ;
T_1 * V_5 ;
char * V_6 ;
T_1 V_7 ;
V_7 = V_3 -> V_8 ;
while ( V_7 ) {
V_5 = V_4 ;
V_4 = F_2 ( T_1 , V_1 , V_3 -> V_8 ) ;
V_6 = V_3 -> V_6 ;
switch ( V_3 -> V_9 ) {
case V_10 :
if ( V_3 -> V_6 ) {
F_3 ( L_1 , V_6 ) ;
}
break;
case V_11 :
F_4 ( V_6 ,
F_5 ( char , V_3 -> V_12 ) ) ;
break;
case V_13 :
F_4 ( V_6 , F_5 ( char , V_4 ) ) ;
break;
case V_14 :
if ( V_3 -> V_12 ) {
F_4 ( V_6 , F_5 ( char ,
V_3 ->
V_12
[ * V_4 ] ) ) ;
} else {
F_6 ( V_6 , F_7 ( V_4 ) ) ;
}
break;
case V_15 :
F_8 ( V_6 , F_9 ( V_4 ) ) ;
break;
case V_16 :
F_10 ( V_6 , F_11 ( V_4 ) ) ;
break;
case V_17 :
F_12 ( V_6 , F_13 ( V_4 ) ) ;
break;
case V_18 :
F_4 ( V_6 , F_5 ( char ,
V_3 ->
V_12 [ * V_4 &
0x01 ] ) ) ;
break;
case V_19 :
F_4 ( V_6 , F_5 ( char ,
V_3 ->
V_12 [ * V_4 &
0x03 ] ) ) ;
break;
case V_20 :
F_4 ( V_6 , F_5 ( char ,
V_3 ->
V_12 [ * V_4 &
0x07 ] ) ) ;
break;
case V_21 :
if ( V_5 ) {
F_14 ( V_6 ) ;
F_15 ( * V_5 ,
V_4 ) ;
}
break;
case V_22 :
if ( V_5 ) {
F_14 ( V_6 ) ;
F_15 ( * V_5 ,
*
( F_16
( T_1 , V_4 ) ) ) ;
}
break;
case V_23 :
if ( V_5 ) {
F_17 ( F_9
( V_5 ) ,
V_4 ) ;
}
break;
case V_24 :
if ( V_5 ) {
F_18 ( * V_5 ,
F_5 ( V_25 ,
V_4 ) ) ;
}
break;
case V_26 :
if ( V_5 ) {
F_19 ( * V_5 ,
* ( F_16
( V_27 , V_4 ) ) ) ;
}
break;
case V_28 :
F_20 ( F_5
( union V_29 ,
V_4 ) ) ;
break;
case V_30 :
F_21 ( F_5
( struct
V_31 ,
V_4 ) ) ;
break;
default:
F_3 ( L_2 ,
V_3 -> V_9 ) ;
return;
}
V_3 ++ ;
V_7 -- ;
}
}
static void
F_21 ( struct V_31 * V_32 )
{
F_22 () ;
if ( V_32 -> V_33 == 0xFF ) {
return;
}
F_6 ( L_3 , V_32 -> V_33 ) ;
F_4 ( L_4 ,
V_32 -> V_34 ?
V_32 -> V_34 : L_5 ) ;
}
static void F_20 ( union V_29 * V_1 )
{
F_22 () ;
switch ( V_1 -> V_35 . V_36 ) {
case V_37 :
F_1 ( V_1 , V_38 ) ;
break;
case V_39 :
F_1 ( V_1 , V_40 ) ;
break;
case V_41 :
F_4 ( L_6 , L_7 ) ;
break;
default:
F_6 ( L_6 ,
( T_1 ) V_1 -> V_35 . V_36 ) ;
break;
}
F_1 ( V_1 , V_42 ) ;
}
void F_23 ( struct V_43 * V_44 )
{
V_25 V_7 = 0 ;
V_25 type ;
F_22 () ;
if ( ! F_24 ( V_45 , V_46 ) ) {
return;
}
do {
F_3 ( L_8 , V_7 ) ;
V_7 ++ ;
type = V_44 -> type ;
if ( type > V_47 ) {
F_3
( L_9 ,
V_44 -> type ) ;
return;
}
if ( ! V_44 -> V_48 ) {
F_3
( L_10 ) ;
return;
}
if ( type == V_49 ) {
F_1 ( & V_44 -> V_50 ,
V_51
[ V_44 -> V_50 .
V_52 . type ] ) ;
} else {
F_1 ( & V_44 -> V_50 ,
V_53
[ type ] ) ;
}
V_44 = F_25 ( V_44 ) ;
} while ( type != V_54 );
}
void F_26 ( T_1 * V_55 )
{
struct V_56 * V_57 ;
T_1 V_7 ;
F_22 () ;
if ( ! F_24 ( V_45 , V_46 ) ) {
return;
}
V_57 = F_5 ( struct V_56 , V_55 ) ;
for ( V_7 = 0 ; V_57 -> V_48 ; V_7 ++ ) {
F_3 ( L_11 ,
V_7 ) ;
F_1 ( V_57 , V_58 ) ;
V_57 = F_2 ( struct V_56 ,
V_57 , V_57 -> V_48 ) ;
}
}
static void F_4 ( char * V_59 , char * V_60 )
{
F_3 ( L_12 , V_59 , V_60 ) ;
if ( ! * V_60 ) {
F_3 ( L_13 ) ;
}
F_3 ( L_14 ) ;
}
static void F_6 ( char * V_59 , T_1 V_60 )
{
F_3 ( L_15 , V_59 , V_60 ) ;
}
static void F_8 ( char * V_59 , V_27 V_60 )
{
F_3 ( L_16 , V_59 , V_60 ) ;
}
static void F_10 ( char * V_59 , V_25 V_60 )
{
F_3 ( L_17 , V_59 , V_60 ) ;
}
static void F_12 ( char * V_59 , T_2 V_60 )
{
F_3 ( L_18 , V_59 , F_27 ( V_60 ) ) ;
}
static void F_14 ( char * V_59 )
{
F_3 ( L_19 , V_59 ) ;
}
static void F_17 ( V_27 V_48 , T_1 * V_50 )
{
T_1 V_61 ;
for ( V_61 = 0 ; V_61 < V_48 ; V_61 ++ ) {
F_3 ( L_20 , L_21 , V_61 , V_50 [ V_61 ] ) ;
}
}
static void F_15 ( T_1 V_48 , T_1 * V_50 )
{
T_1 V_61 ;
for ( V_61 = 0 ; V_61 < V_48 ; V_61 ++ ) {
F_3 ( L_22 , V_50 [ V_61 ] ) ;
}
F_3 ( L_14 ) ;
}
static void F_18 ( T_1 V_48 , V_25 * V_50 )
{
T_1 V_61 ;
for ( V_61 = 0 ; V_61 < V_48 ; V_61 ++ ) {
F_3 ( L_23 , L_24 , V_61 , V_50 [ V_61 ] ) ;
}
}
static void F_19 ( V_27 V_48 , V_27 * V_50 )
{
V_27 V_61 ;
for ( V_61 = 0 ; V_61 < V_48 ; V_61 ++ ) {
F_3 ( L_25 , L_26 , V_61 , V_50 [ V_61 ] ) ;
}
}
