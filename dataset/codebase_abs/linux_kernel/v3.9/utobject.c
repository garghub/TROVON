union V_1 * F_1 ( const char
* V_2 ,
T_1 V_3 ,
T_1 V_4 ,
T_2
type )
{
union V_1 * V_5 ;
union V_1 * V_6 ;
F_2 ( V_7 ,
F_3 ( type ) ) ;
V_5 =
F_4 ( V_2 , V_3 ,
V_4 ) ;
if ( ! V_5 ) {
F_5 ( NULL ) ;
}
switch ( type ) {
case V_8 :
case V_9 :
case V_10 :
V_6 = F_4 ( V_2 ,
V_3 ,
V_4 ) ;
if ( ! V_6 ) {
F_6 ( V_5 ) ;
F_5 ( NULL ) ;
}
V_6 -> V_11 . type = V_12 ;
V_6 -> V_11 . V_13 = 1 ;
V_5 -> V_11 . V_14 = V_6 ;
break;
default:
break;
}
V_5 -> V_11 . type = ( V_15 ) type ;
V_5 -> V_11 . V_13 = 1 ;
F_5 ( V_5 ) ;
}
union V_1 * F_7 ( T_1 V_16 )
{
union V_1 * V_17 ;
union V_1 * * V_18 ;
F_8 ( V_19 , V_16 ) ;
V_17 = F_9 ( V_20 ) ;
if ( ! V_17 ) {
F_5 ( NULL ) ;
}
V_18 = F_10 ( ( ( V_21 ) V_16 +
1 ) * sizeof( void * ) ) ;
if ( ! V_18 ) {
F_11 ( V_17 ) ;
F_5 ( NULL ) ;
}
V_17 -> V_22 . V_16 = V_16 ;
V_17 -> V_22 . V_23 = V_18 ;
F_5 ( V_17 ) ;
}
union V_1 * F_12 ( T_3 V_24 )
{
union V_1 * V_25 ;
F_13 ( V_26 ) ;
V_25 = F_9 ( V_27 ) ;
if ( ! V_25 ) {
F_5 ( NULL ) ;
}
V_25 -> integer . V_28 = V_24 ;
F_5 ( V_25 ) ;
}
union V_1 * F_14 ( V_21 V_29 )
{
union V_1 * V_30 ;
V_15 * V_31 = NULL ;
F_8 ( V_32 , V_29 ) ;
V_30 = F_9 ( V_33 ) ;
if ( ! V_30 ) {
F_5 ( NULL ) ;
}
if ( V_29 > 0 ) {
V_31 = F_10 ( V_29 ) ;
if ( ! V_31 ) {
F_15 ( ( V_34 , L_1 ,
( T_1 ) V_29 ) ) ;
F_11 ( V_30 ) ;
F_5 ( NULL ) ;
}
}
V_30 -> V_31 . V_35 |= V_36 ;
V_30 -> V_31 . V_37 = V_31 ;
V_30 -> V_31 . V_38 = ( T_1 ) V_29 ;
F_5 ( V_30 ) ;
}
union V_1 * F_16 ( V_21 V_39 )
{
union V_1 * V_40 ;
char * string ;
F_8 ( V_41 , V_39 ) ;
V_40 = F_9 ( V_42 ) ;
if ( ! V_40 ) {
F_5 ( NULL ) ;
}
string = F_10 ( V_39 + 1 ) ;
if ( ! string ) {
F_15 ( ( V_34 , L_1 ,
( T_1 ) V_39 ) ) ;
F_11 ( V_40 ) ;
F_5 ( NULL ) ;
}
V_40 -> string . V_37 = string ;
V_40 -> string . V_38 = ( T_1 ) V_39 ;
F_5 ( V_40 ) ;
}
V_15 F_17 ( void * V_5 )
{
F_18 ( V_43 ) ;
if ( ! V_5 ) {
F_19 ( ( V_44 , L_2 ) ) ;
return ( FALSE ) ;
}
switch ( F_20 ( V_5 ) ) {
case V_45 :
return ( TRUE ) ;
default:
F_19 ( ( V_44 ,
L_3 ,
V_5 , F_21 ( V_5 ) ) ) ;
break;
}
return ( FALSE ) ;
}
void * F_4 ( const char * V_2 ,
T_1 V_3 , T_1 V_4 )
{
union V_1 * V_5 ;
F_13 ( V_46 ) ;
V_5 = F_22 ( V_47 ) ;
if ( ! V_5 ) {
F_15 ( ( V_2 , V_3 ,
L_4 ) ) ;
F_5 ( NULL ) ;
}
memset ( V_5 , 0 , sizeof( union V_1 ) ) ;
F_23 ( V_5 , V_45 ) ;
F_19 ( ( V_48 , L_5 ,
V_5 , ( T_1 ) sizeof( union V_1 ) ) ) ;
F_5 ( V_5 ) ;
}
void F_6 ( union V_1 * V_5 )
{
F_24 ( V_49 , V_5 ) ;
if ( F_20 ( V_5 ) != V_45 ) {
F_15 ( ( V_34 ,
L_6 , V_5 ,
F_21 ( V_5 ) ) ) ;
V_50 ;
}
( void ) F_25 ( V_47 , V_5 ) ;
V_50 ;
}
static T_4
F_26 ( union V_1 * V_51 ,
V_21 * V_52 )
{
V_21 V_38 ;
V_21 V_53 ;
T_4 V_54 = V_55 ;
F_24 ( V_56 , V_51 ) ;
if ( ! V_51 ) {
* V_52 = sizeof( union V_57 ) ;
F_27 ( V_55 ) ;
}
V_38 = sizeof( union V_57 ) ;
if ( F_20 ( V_51 ) == V_58 ) {
* V_52 = F_28 ( V_38 ) ;
F_27 ( V_54 ) ;
}
switch ( V_51 -> V_11 . type ) {
case V_42 :
V_38 += ( V_21 ) V_51 -> string . V_38 + 1 ;
break;
case V_33 :
V_38 += ( V_21 ) V_51 -> V_31 . V_38 ;
break;
case V_27 :
case V_59 :
case V_60 :
break;
case V_61 :
switch ( V_51 -> V_62 . V_63 ) {
case V_64 :
V_53 =
F_29 ( V_51 ->
V_62 . V_65 ) ;
if ( ! V_53 ) {
F_27 ( V_66 ) ;
}
V_38 += F_28 ( V_53 ) ;
break;
default:
F_15 ( ( V_34 ,
L_7
L_8 ,
F_30 ( V_51 ) ,
V_51 -> V_62 . V_63 ,
V_51 ) ) ;
V_54 = V_67 ;
break;
}
break;
default:
F_15 ( ( V_34 , L_7
L_9 ,
F_31 ( V_51 ) ,
V_51 -> V_11 . type , V_51 ) ) ;
V_54 = V_67 ;
break;
}
* V_52 = F_28 ( V_38 ) ;
F_27 ( V_54 ) ;
}
static T_4
F_32 ( V_15 V_68 ,
union V_1 * V_69 ,
union V_70 * V_71 , void * V_72 )
{
T_4 V_54 = V_55 ;
struct V_73 * V_74 = (struct V_73 * ) V_72 ;
V_21 V_75 ;
switch ( V_68 ) {
case V_76 :
V_54 =
F_26 ( V_69 ,
& V_75 ) ;
if ( F_33 ( V_54 ) ) {
return ( V_54 ) ;
}
V_74 -> V_38 += V_75 ;
break;
case V_77 :
V_74 -> V_78 ++ ;
V_71 -> V_79 . V_80 = NULL ;
break;
default:
return ( V_66 ) ;
}
return ( V_54 ) ;
}
static T_4
F_34 ( union V_1 * V_51 ,
V_21 * V_52 )
{
T_4 V_54 ;
struct V_73 V_74 ;
F_24 ( V_81 , V_51 ) ;
V_74 . V_38 = 0 ;
V_74 . V_75 = 0 ;
V_74 . V_78 = 1 ;
V_54 = F_35 ( V_51 , NULL ,
F_32 , & V_74 ) ;
if ( F_33 ( V_54 ) ) {
F_27 ( V_54 ) ;
}
V_74 . V_38 += F_28 ( sizeof( union V_57 ) ) *
( V_21 ) V_74 . V_78 ;
* V_52 = V_74 . V_38 ;
F_27 ( V_54 ) ;
}
T_4
F_36 ( union V_1 * V_51 ,
V_21 * V_52 )
{
T_4 V_54 ;
F_37 () ;
if ( ( F_20 ( V_51 ) ==
V_45 )
&& ( V_51 -> V_11 . type == V_20 ) ) {
V_54 =
F_34 ( V_51 ,
V_52 ) ;
} else {
V_54 =
F_26 ( V_51 , V_52 ) ;
}
return ( V_54 ) ;
}
