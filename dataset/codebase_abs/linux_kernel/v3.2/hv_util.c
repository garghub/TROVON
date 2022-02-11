static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
T_1 V_4 ;
T_2 V_5 ;
T_3 V_6 = false ;
T_3 * V_7 = V_8 . V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = NULL ;
F_2 ( V_3 , V_7 ,
V_16 , & V_4 , & V_5 ) ;
if ( V_4 > 0 ) {
V_13 = (struct V_12 * ) & V_7 [
sizeof( struct V_17 ) ] ;
if ( V_13 -> V_18 == V_19 ) {
F_3 ( V_13 , V_15 , V_7 ) ;
} else {
V_11 =
(struct V_10 * ) & V_7 [
sizeof( struct V_17 ) +
sizeof( struct V_12 ) ] ;
switch ( V_11 -> V_20 ) {
case 0 :
case 1 :
V_13 -> V_21 = V_22 ;
V_6 = true ;
F_4 ( L_1
L_2 ) ;
break;
default:
V_13 -> V_21 = V_23 ;
V_6 = false ;
F_4 ( L_1
L_3 ) ;
break;
}
}
V_13 -> V_24 = V_25
| V_26 ;
F_5 ( V_3 , V_7 ,
V_4 , V_5 ,
V_27 , 0 ) ;
}
if ( V_6 == true )
F_6 ( true ) ;
}
static inline void F_7 ( T_2 V_28 )
{
T_4 V_29 ;
struct V_30 V_31 ;
V_29 = ( V_28 - V_32 ) * 100 ;
V_31 = F_8 ( V_29 ) ;
F_9 ( & V_31 ) ;
}
static void F_10 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
V_36 = F_11 ( V_34 , struct V_35 , V_34 ) ;
F_7 ( V_36 -> V_37 ) ;
F_12 ( V_36 ) ;
}
static inline void F_13 ( T_2 V_28 , T_3 V_20 )
{
struct V_35 * V_36 ;
static T_5 V_38 = 50 ;
V_36 = F_14 ( sizeof( struct V_35 ) , V_39 ) ;
if ( V_36 == NULL )
return;
V_36 -> V_37 = V_28 ;
if ( ( V_20 & V_40 ) != 0 ) {
F_15 ( & V_36 -> V_34 , F_10 ) ;
F_16 ( & V_36 -> V_34 ) ;
return;
}
if ( ( V_20 & V_41 ) != 0 && V_38 > 0 ) {
V_38 -- ;
F_15 ( & V_36 -> V_34 , F_10 ) ;
F_16 ( & V_36 -> V_34 ) ;
} else
F_12 ( V_36 ) ;
}
static void F_17 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
T_1 V_4 ;
T_2 V_5 ;
struct V_12 * V_13 ;
struct V_42 * V_43 ;
T_3 * V_44 = V_45 . V_9 ;
F_2 ( V_3 , V_44 ,
V_16 , & V_4 , & V_5 ) ;
if ( V_4 > 0 ) {
V_13 = (struct V_12 * ) & V_44 [
sizeof( struct V_17 ) ] ;
if ( V_13 -> V_18 == V_19 ) {
F_3 ( V_13 , NULL , V_44 ) ;
} else {
V_43 = (struct V_42 * ) & V_44 [
sizeof( struct V_17 ) +
sizeof( struct V_12 ) ] ;
F_13 ( V_43 -> V_46 , V_43 -> V_20 ) ;
}
V_13 -> V_24 = V_25
| V_26 ;
F_5 ( V_3 , V_44 ,
V_4 , V_5 ,
V_27 , 0 ) ;
}
}
static void F_18 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
T_1 V_4 ;
T_2 V_5 ;
struct V_12 * V_13 ;
struct V_47 * V_48 ;
T_3 * V_49 = V_50 . V_9 ;
F_2 ( V_3 , V_49 ,
V_16 , & V_4 , & V_5 ) ;
if ( V_4 > 0 ) {
V_13 = (struct V_12 * ) & V_49 [
sizeof( struct V_17 ) ] ;
if ( V_13 -> V_18 == V_19 ) {
F_3 ( V_13 , NULL , V_49 ) ;
} else {
V_48 =
(struct V_47 * ) & V_49 [
sizeof( struct V_17 ) +
sizeof( struct V_12 ) ] ;
V_48 -> V_51 += 1 ;
}
V_13 -> V_24 = V_25
| V_26 ;
F_5 ( V_3 , V_49 ,
V_4 , V_5 ,
V_27 , 0 ) ;
}
}
static int F_19 ( struct V_52 * V_53 ,
const struct V_54 * V_55 )
{
struct V_56 * V_57 =
(struct V_56 * ) V_55 -> V_58 ;
int V_59 ;
V_57 -> V_9 = F_14 ( V_16 , V_60 ) ;
if ( ! V_57 -> V_9 )
return - V_61 ;
if ( V_57 -> V_62 ) {
V_59 = V_57 -> V_62 ( V_57 ) ;
if ( V_59 ) {
V_59 = - V_63 ;
goto V_64;
}
}
V_59 = F_20 ( V_53 -> V_3 , 2 * V_16 , 2 * V_16 , NULL , 0 ,
V_57 -> V_65 , V_53 -> V_3 ) ;
if ( V_59 )
goto error;
F_21 ( V_53 , V_57 ) ;
return 0 ;
error:
if ( V_57 -> V_66 )
V_57 -> V_66 () ;
V_64:
F_12 ( V_57 -> V_9 ) ;
return V_59 ;
}
static int F_22 ( struct V_52 * V_53 )
{
struct V_56 * V_57 = F_23 ( V_53 ) ;
F_24 ( V_53 -> V_3 ) ;
if ( V_57 -> V_66 )
V_57 -> V_66 () ;
F_12 ( V_57 -> V_9 ) ;
return 0 ;
}
static int T_6 F_25 ( void )
{
F_4 ( L_4 ) ;
return F_26 ( & V_67 ) ;
}
static void F_27 ( void )
{
F_4 ( L_5 ) ;
F_28 ( & V_67 ) ;
}
