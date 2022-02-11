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
static void F_9 ( struct V_1 * V_33 )
{
struct V_34 * V_35 ;
T_4 V_36 ;
T_2 V_37 ;
struct V_38 V_39 ;
V_35 = F_10 ( V_33 , struct V_34 , V_33 ) ;
V_37 = V_35 -> V_40 ;
if ( V_41 > V_42 ) {
T_2 V_43 ;
F_11 ( V_44 , V_43 ) ;
V_37 += ( V_43 - V_35 -> V_45 ) ;
}
V_36 = ( V_37 - V_46 ) * 100 ;
V_39 = F_12 ( V_36 ) ;
F_13 ( & V_39 ) ;
}
static inline void F_14 ( T_2 V_47 , T_2 V_48 , T_3 V_24 )
{
if ( F_15 ( & V_35 . V_33 ) )
return;
V_35 . V_40 = V_47 ;
V_35 . V_45 = V_48 ;
V_35 . V_24 = V_24 ;
if ( ( V_24 & ( V_49 | V_50 ) ) != 0 ) {
F_8 ( & V_35 . V_33 ) ;
}
}
static void F_16 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
T_3 * V_55 = V_56 . V_11 ;
struct V_16 * V_17 = NULL ;
F_4 ( V_5 , V_55 ,
V_18 , & V_6 , & V_7 ) ;
if ( V_6 > 0 ) {
V_15 = (struct V_14 * ) & V_55 [
sizeof( struct V_19 ) ] ;
if ( V_15 -> V_20 == V_21 ) {
F_5 ( V_15 , V_17 ,
V_55 ,
V_22 ,
V_41 ) ;
F_6 ( L_4 ,
V_41 >> 16 , V_41 & 0xFFFF ) ;
} else {
if ( V_41 > V_42 ) {
V_54 = (struct V_53 * )
& V_55 [
sizeof( struct V_19 ) +
sizeof( struct V_14 ) ] ;
F_14 ( V_54 -> V_57 ,
V_54 -> V_58 ,
V_54 -> V_24 ) ;
} else {
V_52 = (struct V_51 * )
& V_55 [
sizeof( struct V_19 ) +
sizeof( struct V_14 ) ] ;
F_14 ( V_52 -> V_57 ,
0 ,
V_52 -> V_24 ) ;
}
}
V_15 -> V_28 = V_29
| V_30 ;
F_7 ( V_5 , V_55 ,
V_6 , V_7 ,
V_31 , 0 ) ;
}
}
static void F_17 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
T_1 V_6 ;
T_2 V_7 ;
struct V_14 * V_15 ;
struct V_59 * V_60 ;
T_3 * V_61 = V_62 . V_11 ;
struct V_16 * V_17 = NULL ;
while ( 1 ) {
F_4 ( V_5 , V_61 ,
V_18 , & V_6 , & V_7 ) ;
if ( ! V_6 )
break;
V_15 = (struct V_14 * ) & V_61 [
sizeof( struct V_19 ) ] ;
if ( V_15 -> V_20 == V_21 ) {
F_5 ( V_15 , V_17 ,
V_61 , V_22 ,
V_63 ) ;
} else {
V_60 =
(struct V_59 * ) & V_61 [
sizeof( struct V_19 ) +
sizeof( struct V_14 ) ] ;
V_60 -> V_64 += 1 ;
}
V_15 -> V_28 = V_29
| V_30 ;
F_7 ( V_5 , V_61 ,
V_6 , V_7 ,
V_31 , 0 ) ;
}
}
static int F_18 ( struct V_65 * V_66 ,
const struct V_67 * V_68 )
{
struct V_69 * V_70 =
(struct V_69 * ) V_68 -> V_71 ;
int V_72 ;
V_70 -> V_11 = F_19 ( V_18 * 4 , V_73 ) ;
if ( ! V_70 -> V_11 )
return - V_74 ;
V_70 -> V_5 = V_66 -> V_5 ;
if ( V_70 -> V_75 ) {
V_72 = V_70 -> V_75 ( V_70 ) ;
if ( V_72 ) {
V_72 = - V_76 ;
goto V_77;
}
}
F_20 ( V_66 -> V_5 , false ) ;
F_21 ( V_66 , V_70 ) ;
switch ( V_78 ) {
case ( V_79 ) :
V_22 = V_80 ;
V_23 = V_81 ;
V_41 = V_82 ;
V_63 = V_83 ;
break;
case ( V_84 ) :
V_22 = V_85 ;
V_23 = V_86 ;
V_41 = V_87 ;
V_63 = V_88 ;
break;
default:
V_22 = V_85 ;
V_23 = V_86 ;
V_41 = V_42 ;
V_63 = V_88 ;
}
V_72 = F_22 ( V_66 -> V_5 , 4 * V_18 , 4 * V_18 , NULL , 0 ,
V_70 -> V_89 , V_66 -> V_5 ) ;
if ( V_72 )
goto error;
return 0 ;
error:
if ( V_70 -> V_90 )
V_70 -> V_90 () ;
V_77:
F_23 ( V_70 -> V_11 ) ;
return V_72 ;
}
static int F_24 ( struct V_65 * V_66 )
{
struct V_69 * V_70 = F_25 ( V_66 ) ;
if ( V_70 -> V_90 )
V_70 -> V_90 () ;
F_26 ( V_66 -> V_5 ) ;
F_23 ( V_70 -> V_11 ) ;
return 0 ;
}
static int F_27 ( struct V_69 * V_70 )
{
F_28 ( & V_35 . V_33 , F_9 ) ;
return 0 ;
}
static void F_29 ( void )
{
F_30 ( & V_35 . V_33 ) ;
}
static int T_5 F_31 ( void )
{
F_6 ( L_5 ) ;
return F_32 ( & V_91 ) ;
}
static void F_33 ( void )
{
F_6 ( L_6 ) ;
F_34 ( & V_91 ) ;
}
