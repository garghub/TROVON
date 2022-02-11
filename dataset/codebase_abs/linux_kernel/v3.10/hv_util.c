static void F_1 ( struct V_1 * V_2 )
{
F_2 ( true ) ;
}
static void F_3 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
T_3 V_8 = false ;
T_3 * V_9 = V_10 . V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = NULL ;
F_4 ( V_5 , V_9 ,
V_18 , & V_6 , & V_7 ) ;
if ( V_6 > 0 ) {
V_15 = (struct V_14 * ) & V_9 [
sizeof( struct V_19 ) ] ;
if ( V_15 -> V_20 == V_21 ) {
F_5 ( V_15 , V_17 ,
V_9 , V_22 , V_22 ) ;
} else {
V_13 =
(struct V_12 * ) & V_9 [
sizeof( struct V_19 ) +
sizeof( struct V_14 ) ] ;
switch ( V_13 -> V_23 ) {
case 0 :
case 1 :
V_15 -> V_24 = V_25 ;
V_8 = true ;
F_6 ( L_1
L_2 ) ;
break;
default:
V_15 -> V_24 = V_26 ;
V_8 = false ;
F_6 ( L_1
L_3 ) ;
break;
}
}
V_15 -> V_27 = V_28
| V_29 ;
F_7 ( V_5 , V_9 ,
V_6 , V_7 ,
V_30 , 0 ) ;
}
if ( V_8 == true )
F_8 ( & V_31 ) ;
}
static inline void F_9 ( T_2 V_32 )
{
T_4 V_33 ;
struct V_34 V_35 ;
V_33 = ( V_32 - V_36 ) * 100 ;
V_35 = F_10 ( V_33 ) ;
F_11 ( & V_35 ) ;
}
static void F_12 ( struct V_1 * V_37 )
{
struct V_38 * V_39 ;
V_39 = F_13 ( V_37 , struct V_38 , V_37 ) ;
F_9 ( V_39 -> V_40 ) ;
F_14 ( V_39 ) ;
}
static inline void F_15 ( T_2 V_32 , T_3 V_23 )
{
struct V_38 * V_39 ;
static T_5 V_41 = 50 ;
V_39 = F_16 ( sizeof( struct V_38 ) , V_42 ) ;
if ( V_39 == NULL )
return;
V_39 -> V_40 = V_32 ;
if ( ( V_23 & V_43 ) != 0 ) {
F_17 ( & V_39 -> V_37 , F_12 ) ;
F_8 ( & V_39 -> V_37 ) ;
return;
}
if ( ( V_23 & V_44 ) != 0 && V_41 > 0 ) {
V_41 -- ;
F_17 ( & V_39 -> V_37 , F_12 ) ;
F_8 ( & V_39 -> V_37 ) ;
} else
F_14 ( V_39 ) ;
}
static void F_18 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_45 * V_46 ;
T_3 * V_47 = V_48 . V_11 ;
F_4 ( V_5 , V_47 ,
V_18 , & V_6 , & V_7 ) ;
if ( V_6 > 0 ) {
V_15 = (struct V_14 * ) & V_47 [
sizeof( struct V_19 ) ] ;
if ( V_15 -> V_20 == V_21 ) {
F_5 ( V_15 , NULL , V_47 ,
V_22 , V_22 ) ;
} else {
V_46 = (struct V_45 * ) & V_47 [
sizeof( struct V_19 ) +
sizeof( struct V_14 ) ] ;
F_15 ( V_46 -> V_49 , V_46 -> V_23 ) ;
}
V_15 -> V_27 = V_28
| V_29 ;
F_7 ( V_5 , V_47 ,
V_6 , V_7 ,
V_30 , 0 ) ;
}
}
static void F_19 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_50 * V_51 ;
T_3 * V_52 = V_53 . V_11 ;
F_4 ( V_5 , V_52 ,
V_18 , & V_6 , & V_7 ) ;
if ( V_6 > 0 ) {
V_15 = (struct V_14 * ) & V_52 [
sizeof( struct V_19 ) ] ;
if ( V_15 -> V_20 == V_21 ) {
F_5 ( V_15 , NULL ,
V_52 , V_22 , V_22 ) ;
} else {
V_51 =
(struct V_50 * ) & V_52 [
sizeof( struct V_19 ) +
sizeof( struct V_14 ) ] ;
V_51 -> V_54 += 1 ;
}
V_15 -> V_27 = V_28
| V_29 ;
F_7 ( V_5 , V_52 ,
V_6 , V_7 ,
V_30 , 0 ) ;
}
}
static int F_20 ( struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_59 * V_60 =
(struct V_59 * ) V_58 -> V_61 ;
int V_62 ;
V_60 -> V_11 = F_16 ( V_18 * 2 , V_63 ) ;
if ( ! V_60 -> V_11 )
return - V_64 ;
if ( V_60 -> V_65 ) {
V_62 = V_60 -> V_65 ( V_60 ) ;
if ( V_62 ) {
V_62 = - V_66 ;
goto V_67;
}
}
F_21 ( V_56 -> V_5 , false ) ;
V_62 = F_22 ( V_56 -> V_5 , 4 * V_18 , 4 * V_18 , NULL , 0 ,
V_60 -> V_68 , V_56 -> V_5 ) ;
if ( V_62 )
goto error;
F_23 ( V_56 , V_60 ) ;
return 0 ;
error:
if ( V_60 -> V_69 )
V_60 -> V_69 () ;
V_67:
F_14 ( V_60 -> V_11 ) ;
return V_62 ;
}
static int F_24 ( struct V_55 * V_56 )
{
struct V_59 * V_60 = F_25 ( V_56 ) ;
F_26 ( V_56 -> V_5 ) ;
if ( V_60 -> V_69 )
V_60 -> V_69 () ;
F_14 ( V_60 -> V_11 ) ;
return 0 ;
}
static int T_6 F_27 ( void )
{
F_6 ( L_4 ) ;
return F_28 ( & V_70 ) ;
}
static void F_29 ( void )
{
F_6 ( L_5 ) ;
F_30 ( & V_70 ) ;
}
