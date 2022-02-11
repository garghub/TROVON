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
V_16 = 1 ;
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
static int
F_10 ( int V_25 )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) + sizeof( struct V_26 ) , V_4 ) ;
if ( V_2 ) {
V_2 -> V_5 . V_6 = V_7 ;
V_2 -> V_5 . V_8 = V_9 ;
V_2 -> V_10 = V_27 ;
( (struct V_19 * ) V_2 -> V_12 ) -> V_28 = V_25 ;
V_2 -> V_13 = sizeof( struct V_19 ) ;
F_3 ( V_2 , 0 , V_4 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
return 1 ;
}
static void
F_6 ( char * V_29 , char * V_30 , int error )
{
struct V_26 * V_31 ;
struct V_32 * V_33 ;
char * V_34 ;
struct V_35 * V_36 ;
int V_37 , V_38 ;
T_1 V_39 ;
struct V_40 * V_41 ;
T_2 V_42 ;
if ( ! V_43 . V_44 ) {
F_11 ( L_4 ) ;
return;
}
V_39 = V_43 . V_45 ;
V_41 = V_43 . V_46 ;
V_42 = V_43 . V_47 ;
V_36 = (struct V_35 * )
& V_48 [ sizeof( struct V_49 ) ] ;
V_31 = (struct V_26 * )
& V_48 [ sizeof( struct V_49 ) +
sizeof( struct V_35 ) ] ;
V_33 = & V_31 -> V_33 ;
V_34 = V_29 ;
if ( error ) {
V_36 -> V_50 = V_51 ;
goto V_52;
}
V_37 = F_12 ( V_34 , strlen ( V_34 ) ,
( V_53 * ) V_33 -> V_12 . V_29 ) ;
V_33 -> V_12 . V_54 = 2 * ( V_37 + 1 ) ;
V_38 = F_12 ( V_30 , strlen ( V_30 ) ,
( V_53 * ) V_33 -> V_12 . V_30 ) ;
V_33 -> V_12 . V_55 = 2 * ( V_38 + 1 ) ;
V_33 -> V_12 . V_56 = V_57 ;
V_36 -> V_50 = V_58 ;
V_52:
V_36 -> V_59 = V_60 | V_61 ;
F_13 ( V_41 , V_48 , V_39 , V_42 ,
V_62 , 0 ) ;
V_43 . V_44 = false ;
}
void F_14 ( void * V_63 )
{
struct V_40 * V_41 = V_63 ;
T_1 V_64 ;
T_2 V_65 ;
struct V_26 * V_31 ;
struct V_32 * V_33 ;
struct V_35 * V_36 ;
struct V_66 * V_67 = NULL ;
if ( V_43 . V_44 )
return;
F_15 ( V_41 , V_48 , V_68 , & V_64 , & V_65 ) ;
if ( V_64 > 0 ) {
V_36 = (struct V_35 * ) & V_48 [
sizeof( struct V_49 ) ] ;
if ( V_36 -> V_69 == V_70 ) {
F_16 ( V_36 , V_67 , V_48 ) ;
} else {
V_31 = (struct V_26 * ) & V_48 [
sizeof( struct V_49 ) +
sizeof( struct V_35 ) ] ;
V_33 = & V_31 -> V_33 ;
if ( ( V_31 -> V_71 . V_72 != V_73 ) ||
( V_31 -> V_71 . V_74 !=
V_75 ) ) {
V_36 -> V_50 = V_51 ;
goto V_76;
}
V_43 . V_45 = V_64 ;
V_43 . V_46 = V_41 ;
V_43 . V_47 = V_65 ;
V_43 . V_44 = true ;
F_10 ( V_33 -> V_25 ) ;
F_17 ( & V_22 , 100 ) ;
return;
}
V_76:
V_36 -> V_59 = V_60
| V_61 ;
F_13 ( V_41 , V_48 ,
V_64 , V_65 ,
V_62 , 0 ) ;
}
}
int
F_18 ( void )
{
int V_77 ;
V_77 = F_19 ( & V_78 , V_79 , F_7 ) ;
if ( V_77 )
return V_77 ;
V_48 = F_20 ( V_68 , V_80 ) ;
if ( ! V_48 )
return - V_81 ;
return 0 ;
}
void F_21 ( void )
{
F_22 ( & V_78 ) ;
F_9 ( & V_22 ) ;
F_4 ( V_48 ) ;
}
