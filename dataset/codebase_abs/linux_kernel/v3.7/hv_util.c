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
F_3 ( V_13 , V_15 ,
V_7 , V_20 , V_20 ) ;
} else {
V_11 =
(struct V_10 * ) & V_7 [
sizeof( struct V_17 ) +
sizeof( struct V_12 ) ] ;
switch ( V_11 -> V_21 ) {
case 0 :
case 1 :
V_13 -> V_22 = V_23 ;
V_6 = true ;
F_4 ( L_1
L_2 ) ;
break;
default:
V_13 -> V_22 = V_24 ;
V_6 = false ;
F_4 ( L_1
L_3 ) ;
break;
}
}
V_13 -> V_25 = V_26
| V_27 ;
F_5 ( V_3 , V_7 ,
V_4 , V_5 ,
V_28 , 0 ) ;
}
if ( V_6 == true )
F_6 ( true ) ;
}
static inline void F_7 ( T_2 V_29 )
{
T_4 V_30 ;
struct V_31 V_32 ;
V_30 = ( V_29 - V_33 ) * 100 ;
V_32 = F_8 ( V_30 ) ;
F_9 ( & V_32 ) ;
}
static void F_10 ( struct V_34 * V_35 )
{
struct V_36 * V_37 ;
V_37 = F_11 ( V_35 , struct V_36 , V_35 ) ;
F_7 ( V_37 -> V_38 ) ;
F_12 ( V_37 ) ;
}
static inline void F_13 ( T_2 V_29 , T_3 V_21 )
{
struct V_36 * V_37 ;
static T_5 V_39 = 50 ;
V_37 = F_14 ( sizeof( struct V_36 ) , V_40 ) ;
if ( V_37 == NULL )
return;
V_37 -> V_38 = V_29 ;
if ( ( V_21 & V_41 ) != 0 ) {
F_15 ( & V_37 -> V_35 , F_10 ) ;
F_16 ( & V_37 -> V_35 ) ;
return;
}
if ( ( V_21 & V_42 ) != 0 && V_39 > 0 ) {
V_39 -- ;
F_15 ( & V_37 -> V_35 , F_10 ) ;
F_16 ( & V_37 -> V_35 ) ;
} else
F_12 ( V_37 ) ;
}
static void F_17 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
T_1 V_4 ;
T_2 V_5 ;
struct V_12 * V_13 ;
struct V_43 * V_44 ;
T_3 * V_45 = V_46 . V_9 ;
F_2 ( V_3 , V_45 ,
V_16 , & V_4 , & V_5 ) ;
if ( V_4 > 0 ) {
V_13 = (struct V_12 * ) & V_45 [
sizeof( struct V_17 ) ] ;
if ( V_13 -> V_18 == V_19 ) {
F_3 ( V_13 , NULL , V_45 ,
V_20 , V_20 ) ;
} else {
V_44 = (struct V_43 * ) & V_45 [
sizeof( struct V_17 ) +
sizeof( struct V_12 ) ] ;
F_13 ( V_44 -> V_47 , V_44 -> V_21 ) ;
}
V_13 -> V_25 = V_26
| V_27 ;
F_5 ( V_3 , V_45 ,
V_4 , V_5 ,
V_28 , 0 ) ;
}
}
static void F_18 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
T_1 V_4 ;
T_2 V_5 ;
struct V_12 * V_13 ;
struct V_48 * V_49 ;
T_3 * V_50 = V_51 . V_9 ;
F_2 ( V_3 , V_50 ,
V_16 , & V_4 , & V_5 ) ;
if ( V_4 > 0 ) {
V_13 = (struct V_12 * ) & V_50 [
sizeof( struct V_17 ) ] ;
if ( V_13 -> V_18 == V_19 ) {
F_3 ( V_13 , NULL ,
V_50 , V_20 , V_20 ) ;
} else {
V_49 =
(struct V_48 * ) & V_50 [
sizeof( struct V_17 ) +
sizeof( struct V_12 ) ] ;
V_49 -> V_52 += 1 ;
}
V_13 -> V_25 = V_26
| V_27 ;
F_5 ( V_3 , V_50 ,
V_4 , V_5 ,
V_28 , 0 ) ;
}
}
static int F_19 ( struct V_53 * V_54 ,
const struct V_55 * V_56 )
{
struct V_57 * V_58 =
(struct V_57 * ) V_56 -> V_59 ;
int V_60 ;
V_58 -> V_9 = F_14 ( V_16 * 2 , V_61 ) ;
if ( ! V_58 -> V_9 )
return - V_62 ;
if ( V_58 -> V_63 ) {
V_60 = V_58 -> V_63 ( V_58 ) ;
if ( V_60 ) {
V_60 = - V_64 ;
goto V_65;
}
}
V_60 = F_20 ( V_54 -> V_3 , 4 * V_16 , 4 * V_16 , NULL , 0 ,
V_58 -> V_66 , V_54 -> V_3 ) ;
if ( V_60 )
goto error;
F_21 ( V_54 , V_58 ) ;
return 0 ;
error:
if ( V_58 -> V_67 )
V_58 -> V_67 () ;
V_65:
F_12 ( V_58 -> V_9 ) ;
return V_60 ;
}
static int F_22 ( struct V_53 * V_54 )
{
struct V_57 * V_58 = F_23 ( V_54 ) ;
F_24 ( V_54 -> V_3 ) ;
if ( V_58 -> V_67 )
V_58 -> V_67 () ;
F_12 ( V_58 -> V_9 ) ;
return 0 ;
}
static int T_6 F_25 ( void )
{
F_4 ( L_4 ) ;
return F_26 ( & V_68 ) ;
}
static void F_27 ( void )
{
F_4 ( L_5 ) ;
F_28 ( & V_68 ) ;
}
