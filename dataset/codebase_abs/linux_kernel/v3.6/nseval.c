T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 * V_5 ;
F_2 ( V_6 ) ;
if ( ! V_2 ) {
F_3 ( V_7 ) ;
}
V_2 -> V_8 = NULL ;
V_2 -> V_9 = 0 ;
V_3 = F_4 ( V_2 -> V_10 , V_2 -> V_11 ,
V_12 , & V_2 -> V_13 ) ;
if ( F_5 ( V_3 ) ) {
F_3 ( V_3 ) ;
}
if ( F_6 ( V_2 -> V_13 ) ==
V_14 ) {
V_2 -> V_13 =
F_7 ( struct V_4 ,
V_2 -> V_13 -> V_15 ) ;
}
F_8 ( ( V_16 , L_1 , V_2 -> V_11 ,
V_2 -> V_13 ,
F_9 ( V_2 -> V_13 ) ) ) ;
V_5 = V_2 -> V_13 ;
if ( F_6 ( V_2 -> V_13 ) == V_17 ) {
V_2 -> V_18 =
F_9 ( V_2 -> V_13 ) ;
if ( ! V_2 -> V_18 ) {
F_10 ( ( V_19 ,
L_2 ) ) ;
F_3 ( V_20 ) ;
}
if ( V_2 -> V_21 ) {
while ( V_2 -> V_21 [ V_2 -> V_9 ] ) {
if ( V_2 -> V_9 > V_22 ) {
F_3 ( V_23 ) ;
}
V_2 -> V_9 ++ ;
}
}
F_11 ( V_2 -> V_13 , L_3 ,
V_24 , V_25 ) ;
F_8 ( ( V_26 ,
L_4 ,
V_2 -> V_18 -> V_27 . V_28 + 1 ,
V_2 -> V_18 -> V_27 . V_29 - 1 ) ) ;
F_12 () ;
V_3 = F_13 ( V_2 ) ;
F_14 () ;
} else {
switch ( V_2 -> V_13 -> type ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
F_10 ( ( V_19 ,
L_5 ,
V_2 -> V_13 -> V_36 . V_37 ,
F_15 ( V_2 -> V_13 ->
type ) ) ) ;
F_3 ( V_38 ) ;
default:
break;
}
F_12 () ;
V_3 =
F_16 ( & V_2 -> V_13 , NULL ) ;
F_14 () ;
if ( F_17 ( V_3 ) ) {
V_3 = V_39 ;
V_2 -> V_8 =
F_7 ( union V_40 ,
V_2 -> V_13 ) ;
F_8 ( ( V_16 ,
L_6 ,
V_2 -> V_8 ,
F_18 ( V_2 ->
V_8 ) ) ) ;
}
}
( void ) F_19 ( V_5 , V_2 -> V_9 ,
V_3 , & V_2 -> V_8 ) ;
if ( V_3 == V_39 ) {
if ( V_2 -> V_41 & V_42 ) {
F_20 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
V_3 = V_43 ;
}
F_8 ( ( V_16 ,
L_7 ,
V_2 -> V_11 ) ) ;
F_3 ( V_3 ) ;
}
void F_21 ( void )
{
union V_40 * V_44 ;
union V_40 * V_45 ;
struct V_1 * V_2 ;
T_2 V_46 = 0 ;
F_2 ( V_47 ) ;
V_45 = V_48 ;
if ( ! V_45 ) {
V_49 ;
}
V_2 = F_22 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
V_49 ;
}
while ( V_45 ) {
V_44 = V_45 ;
V_45 = V_45 -> V_27 . V_50 ;
V_44 -> V_27 . V_50 = NULL ;
F_23 ( V_44 , V_2 ) ;
V_46 ++ ;
F_20 ( V_44 ) ;
}
F_24 ( ( V_19 ,
L_8 ,
V_46 ) ) ;
F_25 ( V_2 ) ;
V_48 = NULL ;
V_49 ;
}
static void
F_23 ( union V_40 * V_51 ,
struct V_1 * V_2 )
{
union V_40 * V_52 ;
struct V_4 * V_53 ;
T_3 type ;
T_1 V_3 ;
F_2 ( V_54 ) ;
V_53 = F_7 ( struct V_4 ,
V_51 -> V_27 . V_55 ) ;
type = F_6 ( V_53 ) ;
if ( ( type == V_30 ) && V_53 -> V_15 ) {
V_51 -> V_27 . V_56 . V_57 =
V_53 -> V_15 -> V_58 . V_57 ;
}
V_51 -> V_27 . V_55 = NULL ;
F_26 ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_10 = V_53 ;
V_52 = F_9 ( V_53 ) ;
if ( V_52 ) {
F_27 ( V_52 ) ;
}
V_3 = F_28 ( V_53 , V_51 ,
V_17 ) ;
if ( F_5 ( V_3 ) ) {
goto exit;
}
V_3 = F_1 ( V_2 ) ;
F_8 ( ( V_59 , L_9 ,
V_51 -> V_27 . V_28 ) ) ;
if ( V_2 -> V_8 ) {
F_20 ( V_2 -> V_8 ) ;
}
F_29 ( V_53 ) ;
if ( V_52 ) {
V_3 = F_28 ( V_53 , V_52 , type ) ;
} else {
V_53 -> type = ( V_60 ) type ;
}
exit:
if ( V_52 ) {
F_20 ( V_52 ) ;
}
V_49 ;
}
