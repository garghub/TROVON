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
static
T_4 F_11 ( T_5 V_3 ,
T_10 (* F_12)( void * V_13 , void * V_14 ,
T_11 V_15 , T_11 V_16 ) ,
void * V_13 ,
T_6 V_17 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_12 V_18 ;
while ( 1 ) {
V_18 = F_13 ( V_7 -> V_3 ,
F_12 ,
V_13 ,
V_17 ) ;
if ( V_18 != V_19 )
break;
F_14 ( 1 ) ;
}
return F_15 ( V_18 ) ;
}
static T_10
F_16 ( void * V_13 ,
void * V_14 ,
T_11 V_15 ,
T_11 V_16 )
{
memcpy ( V_14 , V_13 + V_15 , V_16 ) ;
return V_16 ;
}
int
F_17 ( T_5 V_3 ,
void * V_4 ,
unsigned int V_12 )
{
return F_11 ( V_3 ,
F_16 ,
V_4 ,
V_12 ) ;
}
static T_10
F_18 ( void * V_13 ,
void * V_14 ,
T_11 V_15 ,
T_11 V_16 )
{
struct V_20 * V_21 = V_13 ;
if ( F_19 ( V_14 , V_21 -> V_4 + V_15 , V_16 ) )
return - V_22 ;
return V_16 ;
}
int
F_20 ( T_5 V_3 ,
void T_13 * V_4 ,
unsigned int V_12 )
{
struct V_20 V_21 = {
. V_4 = V_4
} ;
return F_11 ( V_3 ,
F_18 ,
& V_21 ,
V_12 ) ;
}
T_4 F_21 ( T_5 V_3 ,
void * V_23 ,
T_6 V_17 ,
T_7 V_6 ,
void * V_24 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_14 V_25 ;
T_12 V_18 ;
switch ( ( int ) V_6 ) {
case V_26
| V_27 :
F_5 ( ! V_7 -> V_28 ) ;
V_25 = V_29 ;
break;
case V_10 :
V_25 = V_30 ;
break;
case V_27 :
case V_9 :
V_25 = V_31 ;
break;
default:
F_22 ( 1 , L_1 ) ;
return F_15 ( V_32 ) ;
}
while ( 1 ) {
V_18 = F_23 ( V_7 -> V_3 , V_23 ,
V_17 , V_24 , V_25 ) ;
if ( V_18 != V_19 )
break;
F_14 ( 1 ) ;
}
return F_15 ( V_18 ) ;
}
T_4 F_24 ( T_5 V_3 ,
const void * V_33 ,
T_6 V_17 ,
T_7 V_6 ,
void * V_24 )
{
T_8 * V_7 = ( T_8 * ) V_3 ;
T_14 V_25 ;
T_12 V_18 ;
switch ( ( int ) V_6 ) {
case V_26
| V_27 :
F_5 ( ! V_7 -> V_28 ) ;
V_25 = V_29 ;
break;
case V_34 :
case V_10 :
V_25 = V_30 ;
break;
case V_27 :
case V_9 :
V_25 = V_31 ;
break;
default:
F_22 ( 1 , L_1 ) ;
return F_15 ( V_32 ) ;
}
while ( 1 ) {
V_18 = F_25 ( V_7 -> V_3 , V_33 ,
V_17 , V_24 , V_25 ) ;
if ( V_18 != V_19 )
break;
F_14 ( 1 ) ;
}
return F_15 ( V_18 ) ;
}
T_4 F_26 ( T_5 V_3 ,
void * V_4 ,
T_6 V_35 ,
T_6 * V_36 ,
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
memcpy ( V_4 , V_8 -> V_4 , V_8 -> V_12 < V_35 ?
V_8 -> V_12 : V_35 ) ;
* V_36 = V_8 -> V_12 ;
F_10 ( V_7 -> V_3 , V_8 ) ;
return 0 ;
}
T_4 F_27 ( T_15 * V_37 )
{
F_10 ( ( V_38 ) ( long ) V_37 -> V_7 ,
( T_9 * ) V_37 -> V_37 ) ;
return 0 ;
}
T_4 F_28 ( T_5 V_3 ,
void * * V_4 ,
T_6 * V_5 ,
T_7 V_6 ,
T_15 * V_39 )
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
V_39 -> V_7 =
(struct V_40 * ) ( long ) V_7 -> V_3 ;
V_39 -> V_37 = V_8 ;
return 0 ;
}
T_4 F_29 ( T_16 * V_41 )
{
T_17 V_42 ;
T_12 V_18 ;
V_18 = F_30 ( & V_42 ) ;
* V_41 = ( T_16 ) V_42 ;
return F_15 ( V_18 ) ;
}
T_4 F_31 ( T_3 * * V_43 ,
const T_6 V_44 ,
T_16 V_41 )
{
T_17 V_42 = ( T_17 ) V_41 ;
( void ) V_43 ;
( void ) V_44 ;
return F_32 ( V_42 ) ;
}
T_4 F_33 ( T_16 V_41 )
{
T_17 V_42 = ( T_17 ) V_41 ;
return F_15 ( F_34 ( V_42 ) ) ;
}
static T_12 F_35 ( T_18 V_45 ,
T_9 * V_8 , V_38 V_3 , void * V_46 )
{
T_8 * V_7 =
( T_8 * ) F_36 ( V_3 ) ;
if ( ! V_7 -> V_28 )
goto V_47;
switch ( V_45 ) {
case V_48 :
F_37 ( & V_7 -> V_11 , V_8 ) ;
V_7 -> V_28 ( V_7 -> V_49 ,
V_50 , NULL ) ;
goto V_51;
break;
case V_52 :
V_7 -> V_28 ( V_7 -> V_49 ,
V_53 , V_46 ) ;
break;
case V_54 :
V_7 -> V_28 ( V_7 -> V_49 ,
V_55 , V_46 ) ;
break;
case V_56 :
V_7 -> V_28 ( V_7 -> V_49 ,
V_57 , NULL ) ;
break;
case V_58 :
break;
case V_59 :
V_7 -> V_28 ( V_7 -> V_49 ,
V_60 ,
V_46 ) ;
break;
case V_61 :
V_7 -> V_28 ( V_7 -> V_49 ,
V_62 ,
V_46 ) ;
break;
default:
F_22 ( 1 , L_2 ) ;
break;
}
V_47:
F_10 ( V_7 -> V_3 , V_8 ) ;
V_51:
return V_63 ;
}
static T_8 * F_38 ( T_17 V_42 ,
T_19 * V_64 )
{
T_8 * V_7 = F_39 ( sizeof( T_8 ) , V_65 ) ;
( void ) V_42 ;
if ( V_7 ) {
if ( F_40 ( & V_7 -> V_11 , 64 ) ) {
V_7 -> V_28 = V_64 -> V_28 ;
V_7 -> V_49 = V_64 -> V_49 ;
} else {
F_41 ( V_7 ) ;
V_7 = NULL ;
}
}
return V_7 ;
}
static void F_42 ( T_8 * V_7 )
{
if ( V_7 ) {
F_43 ( & V_7 -> V_11 ) ;
F_41 ( V_7 ) ;
}
}
T_4 F_44 ( T_16 V_41 ,
T_19 * V_64 ,
T_5 * V_3 )
{
T_17 V_42 = ( T_17 ) V_41 ;
T_8 * V_7 = F_38 ( V_42 , V_64 ) ;
* V_3 = ( T_5 ) V_7 ;
if ( V_7 ) {
T_20 V_66 ;
T_12 V_18 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_67 = V_64 -> V_68 ;
V_66 . V_28 = F_35 ;
V_66 . V_69 = V_7 ;
V_66 . V_70 = V_64 -> V_70 . V_70 ;
V_66 . V_71 = V_64 -> V_70 . V_71 ;
V_18 = F_45 ( V_42 , & V_66 ,
& V_7 -> V_3 ) ;
if ( V_18 != V_63 ) {
F_42 ( V_7 ) ;
V_7 = NULL ;
* V_3 = NULL ;
}
}
return ( V_7 != NULL ) ? 0 : - 1 ;
}
T_4 F_46 ( T_16 V_41 ,
T_19 * V_64 ,
T_5 * V_3 )
{
T_17 V_42 = ( T_17 ) V_41 ;
T_8 * V_7 = F_38 ( V_42 , V_64 ) ;
* V_3 = ( T_5 ) V_7 ;
if ( V_7 ) {
T_20 V_66 ;
T_12 V_18 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_67 = V_64 -> V_68 ;
V_66 . V_28 = F_35 ;
V_66 . V_69 = V_7 ;
V_66 . V_70 = V_64 -> V_70 . V_70 ;
V_66 . V_71 = V_64 -> V_70 . V_71 ;
V_18 = F_47 ( V_42 , & V_66 , & V_7 -> V_3 ) ;
if ( V_18 != V_63 ) {
F_42 ( V_7 ) ;
V_7 = NULL ;
* V_3 = NULL ;
}
}
return ( V_7 != NULL ) ? 0 : - 1 ;
}
T_4 F_48 ( const T_5 V_3 )
{
T_4 V_72 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if ( V_7 ) {
T_12 V_18 = F_49 ( V_7 -> V_3 ) ;
if ( V_18 == V_63 ) {
F_42 ( V_7 ) ;
V_7 = NULL ;
}
V_72 = F_15 ( V_18 ) ;
}
return V_72 ;
}
T_4 F_50 ( const T_5 V_3 )
{
T_4 V_72 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if ( V_7 ) {
T_12 V_18 = F_51 ( V_7 -> V_3 ) ;
if ( V_18 == V_63 ) {
F_42 ( V_7 ) ;
V_7 = NULL ;
}
V_72 = F_15 ( V_18 ) ;
}
return V_72 ;
}
T_4 F_52 ( const T_5 V_3 ,
T_21 V_73 ,
int V_74 )
{
T_4 V_72 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
T_22 V_75 ;
switch ( V_73 ) {
case V_76 :
V_75 = V_77 ;
break;
case V_78 :
V_75 = V_79 ;
break;
default:
V_7 = NULL ;
break;
}
if ( V_7 ) {
T_12 V_18 =
F_53 ( V_7 -> V_3 ,
V_75 ,
V_74 ) ;
V_72 = F_15 ( V_18 ) ;
}
return V_72 ;
}
T_4 F_54 ( const T_5 V_3 , short * V_80 )
{
T_4 V_72 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if ( V_7 )
{
T_12 V_18 ;
V_18 = F_55 ( V_7 -> V_3 , V_80 ) ;
V_72 = F_15 ( V_18 ) ;
}
return V_72 ;
}
T_4 F_56 ( const T_5 V_3 )
{
T_4 V_72 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if ( V_7 )
V_72 = F_15 ( F_57 ( V_7 -> V_3 ) ) ;
return V_72 ;
}
T_4 F_58 ( const T_5 V_3 )
{
T_4 V_72 = - 1 ;
T_8 * V_7 = ( T_8 * ) V_3 ;
if ( V_7 )
V_72 = F_15 (
F_59 ( V_7 -> V_3 ) ) ;
return V_72 ;
}
