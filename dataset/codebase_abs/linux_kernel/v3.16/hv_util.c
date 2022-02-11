static void F_1 ( struct V_1 * V_2 )
{
F_2 ( true ) ;
}
static void F_3 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
bool V_8 = false ;
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
V_9 , V_22 ,
V_23 ) ;
} else {
V_13 =
(struct V_12 * ) & V_9 [
sizeof( struct V_19 ) +
sizeof( struct V_14 ) ] ;
switch ( V_13 -> V_24 ) {
case 0 :
case 1 :
V_15 -> V_25 = V_26 ;
V_8 = true ;
F_6 ( L_1
L_2 ) ;
break;
default:
V_15 -> V_25 = V_27 ;
V_8 = false ;
F_6 ( L_1
L_3 ) ;
break;
}
}
V_15 -> V_28 = V_29
| V_30 ;
F_7 ( V_5 , V_9 ,
V_6 , V_7 ,
V_31 , 0 ) ;
}
if ( V_8 == true )
F_8 ( & V_32 ) ;
}
static inline void F_9 ( T_2 V_33 )
{
T_4 V_34 ;
struct V_35 V_36 ;
V_34 = ( V_33 - V_37 ) * 100 ;
V_36 = F_10 ( V_34 ) ;
F_11 ( & V_36 ) ;
}
static void F_12 ( struct V_1 * V_38 )
{
struct V_39 * V_40 ;
V_40 = F_13 ( V_38 , struct V_39 , V_38 ) ;
F_9 ( V_40 -> V_41 ) ;
F_14 ( V_40 ) ;
}
static inline void F_15 ( T_2 V_33 , T_3 V_24 )
{
struct V_39 * V_40 ;
static T_5 V_42 = 50 ;
V_40 = F_16 ( sizeof( struct V_39 ) , V_43 ) ;
if ( V_40 == NULL )
return;
V_40 -> V_41 = V_33 ;
if ( ( V_24 & V_44 ) != 0 ) {
F_17 ( & V_40 -> V_38 , F_12 ) ;
F_8 ( & V_40 -> V_38 ) ;
return;
}
if ( ( V_24 & V_45 ) != 0 && V_42 > 0 ) {
V_42 -- ;
F_17 ( & V_40 -> V_38 , F_12 ) ;
F_8 ( & V_40 -> V_38 ) ;
} else
F_14 ( V_40 ) ;
}
static void F_18 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_46 * V_47 ;
T_3 * V_48 = V_49 . V_11 ;
struct V_16 * V_17 = NULL ;
F_4 ( V_5 , V_48 ,
V_18 , & V_6 , & V_7 ) ;
if ( V_6 > 0 ) {
V_15 = (struct V_14 * ) & V_48 [
sizeof( struct V_19 ) ] ;
if ( V_15 -> V_20 == V_21 ) {
F_5 ( V_15 , V_17 ,
V_48 ,
V_22 ,
V_50 ) ;
} else {
V_47 = (struct V_46 * ) & V_48 [
sizeof( struct V_19 ) +
sizeof( struct V_14 ) ] ;
F_15 ( V_47 -> V_51 , V_47 -> V_24 ) ;
}
V_15 -> V_28 = V_29
| V_30 ;
F_7 ( V_5 , V_48 ,
V_6 , V_7 ,
V_31 , 0 ) ;
}
}
static void F_19 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_52 * V_53 ;
T_3 * V_54 = V_55 . V_11 ;
struct V_16 * V_17 = NULL ;
F_4 ( V_5 , V_54 ,
V_18 , & V_6 , & V_7 ) ;
if ( V_6 > 0 ) {
V_15 = (struct V_14 * ) & V_54 [
sizeof( struct V_19 ) ] ;
if ( V_15 -> V_20 == V_21 ) {
F_5 ( V_15 , V_17 ,
V_54 , V_22 ,
V_56 ) ;
} else {
V_53 =
(struct V_52 * ) & V_54 [
sizeof( struct V_19 ) +
sizeof( struct V_14 ) ] ;
V_53 -> V_57 += 1 ;
}
V_15 -> V_28 = V_29
| V_30 ;
F_7 ( V_5 , V_54 ,
V_6 , V_7 ,
V_31 , 0 ) ;
}
}
static int F_20 ( struct V_58 * V_59 ,
const struct V_60 * V_61 )
{
struct V_62 * V_63 =
(struct V_62 * ) V_61 -> V_64 ;
int V_65 ;
V_63 -> V_11 = F_16 ( V_18 * 4 , V_66 ) ;
if ( ! V_63 -> V_11 )
return - V_67 ;
if ( V_63 -> V_68 ) {
V_65 = V_63 -> V_68 ( V_63 ) ;
if ( V_65 ) {
V_65 = - V_69 ;
goto V_70;
}
}
F_21 ( V_59 -> V_5 , false ) ;
V_65 = F_22 ( V_59 -> V_5 , 4 * V_18 , 4 * V_18 , NULL , 0 ,
V_63 -> V_71 , V_59 -> V_5 ) ;
if ( V_65 )
goto error;
F_23 ( V_59 , V_63 ) ;
switch ( V_72 ) {
case ( V_73 ) :
V_22 = V_74 ;
V_23 = V_75 ;
V_50 = V_76 ;
V_56 = V_77 ;
break;
default:
V_22 = V_78 ;
V_23 = V_79 ;
V_50 = V_80 ;
V_56 = V_81 ;
}
return 0 ;
error:
if ( V_63 -> V_82 )
V_63 -> V_82 () ;
V_70:
F_14 ( V_63 -> V_11 ) ;
return V_65 ;
}
static int F_24 ( struct V_58 * V_59 )
{
struct V_62 * V_63 = F_25 ( V_59 ) ;
F_26 ( V_59 -> V_5 ) ;
if ( V_63 -> V_82 )
V_63 -> V_82 () ;
F_14 ( V_63 -> V_11 ) ;
return 0 ;
}
static int T_6 F_27 ( void )
{
F_6 ( L_4 ) ;
return F_28 ( & V_83 ) ;
}
static void F_29 ( void )
{
F_6 ( L_5 ) ;
F_30 ( & V_83 ) ;
}
