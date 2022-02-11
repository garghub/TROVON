static void
F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) + strlen ( V_3 ) + 1 , V_4 ) ;
if ( V_2 ) {
V_2 -> V_5 . V_6 = V_7 ;
V_2 -> V_5 . V_8 = V_9 ;
V_2 -> V_10 = V_11 ;
strcpy ( V_2 -> V_12 , V_3 ) ;
V_2 -> V_13 = strlen ( V_3 ) + 1 ;
F_3 ( V_2 , 0 , V_4 ) ;
F_4 ( V_2 ) ;
}
}
static void
F_5 ( struct V_14 * V_15 )
{
F_6 ( L_1 , L_2 , V_16 ) ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_19 * V_20 ;
V_20 = (struct V_19 * ) V_2 -> V_12 ;
if ( V_2 -> V_10 == V_11 ) {
F_8 ( L_3 ) ;
F_1 () ;
}
if ( V_2 -> V_10 == V_21 ) {
if ( F_9 ( & V_22 ) )
F_6 ( V_20 -> V_23 ,
V_20 -> V_24 ,
! strlen ( V_20 -> V_23 ) ) ;
}
}
static void
F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_25 = V_26 . V_25 ;
V_2 = F_2 ( sizeof( * V_2 ) + sizeof( struct V_27 ) , V_4 ) ;
if ( V_2 ) {
V_2 -> V_5 . V_6 = V_7 ;
V_2 -> V_5 . V_8 = V_9 ;
V_2 -> V_10 = V_28 ;
( (struct V_19 * ) V_2 -> V_12 ) -> V_29 = V_25 ;
V_2 -> V_13 = sizeof( struct V_19 ) ;
F_3 ( V_2 , 0 , V_4 ) ;
F_4 ( V_2 ) ;
}
return;
}
static void
F_6 ( char * V_30 , char * V_31 , int error )
{
struct V_27 * V_32 ;
struct V_33 * V_34 ;
char * V_35 ;
struct V_36 * V_37 ;
int V_38 , V_39 ;
T_1 V_40 ;
struct V_41 * V_42 ;
T_2 V_43 ;
if ( ! V_26 . V_44 ) {
F_11 ( L_4 ) ;
return;
}
V_40 = V_26 . V_45 ;
V_42 = V_26 . V_46 ;
V_43 = V_26 . V_47 ;
V_26 . V_44 = false ;
if ( V_42 -> V_48 == NULL )
return;
V_37 = (struct V_36 * )
& V_49 [ sizeof( struct V_50 ) ] ;
V_32 = (struct V_27 * )
& V_49 [ sizeof( struct V_50 ) +
sizeof( struct V_36 ) ] ;
V_34 = & V_32 -> V_34 ;
V_35 = V_30 ;
if ( error ) {
V_37 -> V_51 = V_52 ;
goto V_53;
}
V_38 = F_12 ( V_35 , strlen ( V_35 ) ,
( V_54 * ) V_34 -> V_12 . V_30 ) ;
V_34 -> V_12 . V_55 = 2 * ( V_38 + 1 ) ;
V_39 = F_12 ( V_31 , strlen ( V_31 ) ,
( V_54 * ) V_34 -> V_12 . V_31 ) ;
V_34 -> V_12 . V_56 = 2 * ( V_39 + 1 ) ;
V_34 -> V_12 . V_57 = V_58 ;
V_37 -> V_51 = V_59 ;
V_53:
V_37 -> V_60 = V_61 | V_62 ;
F_13 ( V_42 , V_49 , V_40 , V_43 ,
V_63 , 0 ) ;
}
void F_14 ( void * V_64 )
{
struct V_41 * V_42 = V_64 ;
T_1 V_65 ;
T_2 V_66 ;
struct V_27 * V_32 ;
struct V_33 * V_34 ;
struct V_36 * V_37 ;
struct V_67 * V_68 = NULL ;
F_15 ( V_42 , V_49 , V_69 , & V_65 , & V_66 ) ;
if ( V_65 > 0 ) {
V_37 = (struct V_36 * ) & V_49 [
sizeof( struct V_50 ) ] ;
if ( V_37 -> V_70 == V_71 ) {
F_16 ( V_37 , V_68 , V_49 ) ;
} else {
V_32 = (struct V_27 * ) & V_49 [
sizeof( struct V_50 ) +
sizeof( struct V_36 ) ] ;
V_34 = & V_32 -> V_34 ;
if ( ( V_32 -> V_72 . V_73 != V_74 ) ||
( V_32 -> V_72 . V_75 !=
V_76 ) ) {
V_37 -> V_51 = V_52 ;
goto V_77;
}
V_26 . V_45 = V_65 ;
V_26 . V_46 = V_42 ;
V_26 . V_47 = V_66 ;
V_26 . V_44 = true ;
V_26 . V_25 = V_34 -> V_25 ;
F_17 ( & V_78 ) ;
F_18 ( & V_22 , 5 * V_79 ) ;
return;
}
V_77:
V_37 -> V_60 = V_61
| V_62 ;
F_13 ( V_42 , V_49 ,
V_65 , V_66 ,
V_63 , 0 ) ;
}
}
int
F_19 ( struct V_80 * V_81 )
{
int V_82 ;
V_82 = F_20 ( & V_83 , V_84 , F_7 ) ;
if ( V_82 )
return V_82 ;
V_49 = V_81 -> V_49 ;
return 0 ;
}
void F_21 ( void )
{
F_22 ( & V_83 ) ;
F_9 ( & V_22 ) ;
F_23 ( & V_78 ) ;
}
