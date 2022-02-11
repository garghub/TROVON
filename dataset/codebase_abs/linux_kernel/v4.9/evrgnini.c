T_1
F_1 ( T_2 V_1 ,
T_3 V_2 ,
void * V_3 , void * * V_4 )
{
union V_5 * V_6 =
(union V_5 * ) V_1 ;
struct V_7 * V_8 ;
F_2 ( V_9 ) ;
if ( V_2 == V_10 ) {
if ( * V_4 ) {
V_8 =
(struct V_7 * ) * V_4 ;
if ( V_8 -> V_11 ) {
F_3 ( V_8 ->
V_12 ,
V_8 ->
V_11 ) ;
}
F_4 ( V_8 ) ;
* V_4 = NULL ;
}
F_5 ( V_13 ) ;
}
V_8 =
F_6 ( sizeof( struct V_7 ) ) ;
if ( ! ( V_8 ) ) {
F_5 ( V_14 ) ;
}
V_8 -> V_15 = V_6 -> V_16 . V_15 ;
V_8 -> V_17 = V_6 -> V_16 . V_17 ;
* V_4 = V_8 ;
F_5 ( V_13 ) ;
}
T_1
F_7 ( T_2 V_1 ,
T_3 V_2 ,
void * V_3 , void * * V_4 )
{
F_2 ( V_18 ) ;
if ( V_2 == V_10 ) {
* V_4 = NULL ;
} else {
* V_4 = V_3 ;
}
F_5 ( V_13 ) ;
}
T_1
F_8 ( T_2 V_1 ,
T_3 V_2 ,
void * V_3 , void * * V_4 )
{
T_1 V_19 = V_13 ;
T_4 V_20 ;
struct V_21 * V_22 = * V_4 ;
union V_5 * V_23 ;
struct V_24 * V_25 ;
struct V_24 * V_26 ;
struct V_24 * V_27 ;
union V_5 * V_28 =
(union V_5 * ) V_1 ;
F_2 ( V_29 ) ;
V_23 = V_28 -> V_16 . V_30 ;
if ( ! V_23 ) {
F_9 ( ( V_31 ,
L_1 ,
V_28 ) ) ;
F_5 ( V_32 ) ;
}
* V_4 = NULL ;
if ( V_2 == V_10 ) {
if ( V_22 ) {
F_4 ( V_22 ) ;
}
F_5 ( V_19 ) ;
}
V_25 = V_28 -> V_16 . V_33 -> V_34 ;
if ( V_23 -> V_35 . V_33 == V_36 ) {
V_26 = V_25 ;
while ( V_26 != V_36 ) {
if ( F_10 ( V_26 ) ) {
V_19 = F_11 ( ( T_2 ) V_26 , V_37 , V_38 , NULL , NULL ) ;
if ( F_12 ( V_19 ) ) {
if ( V_19 == V_39 ) {
V_19 = V_13 ;
} else {
F_13 ( ( V_40 , V_19 ,
L_2
L_3 ,
F_14
( V_26 ) ) ) ;
}
}
break;
}
V_26 = V_26 -> V_34 ;
}
} else {
V_26 = V_23 -> V_35 . V_33 ;
}
if ( V_28 -> V_16 . V_41 & V_42 ) {
F_5 ( V_13 ) ;
}
V_22 = F_6 ( sizeof( struct V_21 ) ) ;
if ( ! V_22 ) {
F_5 ( V_14 ) ;
}
V_27 = V_28 -> V_16 . V_33 ;
while ( V_27 && ( V_27 -> type != V_43 ) ) {
V_27 = V_27 -> V_34 ;
}
if ( ! V_27 ) {
F_4 ( V_22 ) ;
F_5 ( V_44 ) ;
}
V_19 = F_15 ( V_45 ,
V_27 , & V_20 ) ;
if ( F_16 ( V_19 ) ) {
V_22 -> V_46 = F_17 ( F_18 ( V_20 ) ) ;
V_22 -> V_2 = F_19 ( F_18 ( V_20 ) ) ;
}
V_19 = F_15 ( V_47 ,
V_26 , & V_20 ) ;
if ( F_16 ( V_19 ) ) {
V_22 -> V_48 = F_19 ( V_20 ) ;
}
V_19 = F_15 ( V_49 ,
V_26 , & V_20 ) ;
if ( F_16 ( V_19 ) ) {
V_22 -> V_50 = F_19 ( V_20 ) ;
}
V_19 =
F_20 ( V_22 , V_26 ,
V_28 -> V_16 . V_33 ) ;
if ( F_12 ( V_19 ) ) {
F_4 ( V_22 ) ;
F_5 ( V_19 ) ;
}
* V_4 = V_22 ;
F_5 ( V_13 ) ;
}
static T_5 F_10 ( struct V_24 * V_33 )
{
T_1 V_19 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
T_3 V_55 ;
T_5 V_56 ;
V_19 = F_21 ( V_33 , & V_52 ) ;
if ( F_12 ( V_19 ) ) {
return ( FALSE ) ;
}
V_56 = F_22 ( V_52 -> string ) ;
F_4 ( V_52 ) ;
if ( V_56 ) {
return ( TRUE ) ;
}
V_19 = F_23 ( V_33 , & V_54 ) ;
if ( F_12 ( V_19 ) ) {
return ( FALSE ) ;
}
for ( V_55 = 0 ; V_55 < V_54 -> V_57 ; V_55 ++ ) {
if ( F_22 ( V_54 -> V_58 [ V_55 ] . string ) ) {
F_4 ( V_54 ) ;
return ( TRUE ) ;
}
}
F_4 ( V_54 ) ;
return ( FALSE ) ;
}
T_1
F_24 ( T_2 V_1 ,
T_3 V_2 ,
void * V_3 , void * * V_4 )
{
F_2 ( V_59 ) ;
F_5 ( V_13 ) ;
}
T_1
F_25 ( T_2 V_1 ,
T_3 V_2 ,
void * V_3 , void * * V_4 )
{
F_2 ( V_60 ) ;
F_5 ( V_13 ) ;
}
T_1
F_26 ( T_2 V_1 ,
T_3 V_2 ,
void * V_3 , void * * V_4 )
{
F_2 ( V_61 ) ;
if ( V_2 == V_10 ) {
* V_4 = NULL ;
} else {
* V_4 = V_3 ;
}
F_5 ( V_13 ) ;
}
T_1
F_27 ( union V_5 * V_28 ,
T_5 V_62 )
{
union V_5 * V_23 ;
union V_5 * V_63 ;
T_6 V_64 ;
struct V_24 * V_33 ;
T_1 V_19 ;
F_28 ( V_65 , V_62 ) ;
if ( ! V_28 ) {
F_5 ( V_66 ) ;
}
if ( V_28 -> V_67 . V_41 & V_68 ) {
F_5 ( V_13 ) ;
}
V_28 -> V_67 . V_41 |= V_68 ;
V_33 = V_28 -> V_16 . V_33 -> V_34 ;
V_64 = V_28 -> V_16 . V_64 ;
while ( V_33 ) {
V_23 = NULL ;
V_63 = F_29 ( V_33 ) ;
if ( V_63 ) {
switch ( V_33 -> type ) {
case V_43 :
case V_69 :
case V_70 :
V_23 = V_63 -> V_71 . V_30 ;
break;
case V_72 :
if ( ! V_73 &&
V_63 -> V_74 .
V_75 & V_76 ) {
V_23 =
V_63 -> V_74 . V_77 . V_30 ;
}
break;
default:
break;
}
V_23 =
F_30 ( V_64 , V_23 ) ;
if ( V_23 ) {
F_9 ( ( V_31 ,
L_4 ,
V_23 , V_28 ,
V_63 ) ) ;
V_19 =
F_31 ( V_23 ,
V_28 ,
V_62 ) ;
if ( V_62 ) {
V_19 =
F_32
( V_78 ) ;
if ( F_12 ( V_19 ) ) {
F_5 ( V_19 ) ;
}
}
F_33 () ;
V_19 =
F_34 ( V_28 ,
V_79 ) ;
F_35 () ;
if ( V_62 ) {
V_19 =
F_36
( V_78 ) ;
if ( F_12 ( V_19 ) ) {
F_5 ( V_19 ) ;
}
}
F_5 ( V_13 ) ;
}
}
V_33 = V_33 -> V_34 ;
}
F_9 ( ( V_31 ,
L_5 ,
F_37 ( V_64 ) , V_64 ,
V_28 ) ) ;
F_5 ( V_32 ) ;
}
