static long F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
long V_5 ;
V_5 = ( ( V_2 -> V_4 . V_6 - V_4 -> V_6 ) ? :
( V_2 -> V_4 . V_7 - V_4 -> V_7 ) ? :
( V_2 -> V_4 . V_8 . V_9 - V_4 -> V_8 . V_9 ) ) ;
if ( V_5 != 0 )
return V_5 ;
switch ( V_4 -> V_8 . V_9 ) {
case V_10 :
return ( ( V_11 V_12 ) V_2 -> V_4 . V_8 . sin . V_13 -
( V_11 V_12 ) V_4 -> V_8 . sin . V_13 ) ? :
memcmp ( & V_2 -> V_4 . V_8 . sin . V_14 ,
& V_4 -> V_8 . sin . V_14 ,
sizeof( struct V_15 ) ) ;
#ifdef F_2
case V_16 :
return ( ( V_11 V_12 ) V_2 -> V_4 . V_8 . V_17 . V_18 -
( V_11 V_12 ) V_4 -> V_8 . V_17 . V_18 ) ? :
memcmp ( & V_2 -> V_4 . V_8 . V_17 . V_19 ,
& V_4 -> V_8 . V_17 . V_19 ,
sizeof( struct V_20 ) ) ;
#endif
default:
F_3 () ;
}
}
static struct V_1 * F_4 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_21 ) ;
if ( V_2 ) {
F_6 ( & V_2 -> V_22 , 1 ) ;
F_7 ( & V_2 -> V_23 ) ;
F_8 ( & V_2 -> V_24 , V_25 ) ;
F_9 ( & V_2 -> V_26 ) ;
F_10 ( & V_2 -> V_27 ) ;
F_10 ( & V_2 -> V_28 ) ;
V_2 -> V_29 = V_30 ;
F_11 ( & V_2 -> V_31 ) ;
F_11 ( & V_2 -> V_32 ) ;
F_12 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = F_13 ( & V_35 ) ;
memcpy ( & V_2 -> V_4 , V_4 , sizeof( * V_4 ) ) ;
}
F_14 ( L_1 , V_2 ) ;
return V_2 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_36 * V_36 ;
int V_37 , V_38 ;
F_16 ( L_2 ,
V_2 , V_2 -> V_4 . V_6 , V_2 -> V_4 . V_8 . V_9 ) ;
V_37 = F_17 ( & V_39 , V_2 -> V_4 . V_8 . V_9 ,
V_2 -> V_4 . V_6 , 0 , & V_2 -> V_40 ) ;
if ( V_37 < 0 ) {
F_14 ( L_3 , V_37 ) ;
return V_37 ;
}
if ( V_2 -> V_4 . V_7 > sizeof( V_41 ) ) {
F_18 ( L_4 ) ;
V_37 = F_19 ( V_2 -> V_40 ,
(struct V_42 * ) & V_2 -> V_4 . V_8 ,
V_2 -> V_4 . V_7 ) ;
if ( V_37 < 0 ) {
F_18 ( L_5 , V_37 ) ;
goto error;
}
}
V_38 = 1 ;
V_37 = F_20 ( V_2 -> V_40 , V_43 , V_44 ,
( char * ) & V_38 , sizeof( V_38 ) ) ;
if ( V_37 < 0 ) {
F_18 ( L_6 ) ;
goto error;
}
V_38 = V_45 ;
V_37 = F_20 ( V_2 -> V_40 , V_43 , V_46 ,
( char * ) & V_38 , sizeof( V_38 ) ) ;
if ( V_37 < 0 ) {
F_18 ( L_6 ) ;
goto error;
}
V_36 = V_2 -> V_40 -> V_47 ;
V_36 -> V_48 = V_2 ;
V_36 -> V_49 = V_50 ;
V_36 -> V_51 = V_52 ;
F_14 ( L_7 ) ;
return 0 ;
error:
F_21 ( V_2 -> V_40 , V_53 ) ;
V_2 -> V_40 -> V_47 -> V_48 = NULL ;
F_22 ( V_2 -> V_40 ) ;
V_2 -> V_40 = NULL ;
F_14 ( L_8 , V_37 ) ;
return V_37 ;
}
struct V_1 * F_23 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_54 * V_55 ;
const char * V_56 ;
long V_5 ;
int V_37 ;
F_16 ( L_9 ,
V_4 -> V_6 , V_4 -> V_8 . V_9 , & V_4 -> V_8 ) ;
F_24 ( & V_57 ) ;
for ( V_55 = V_58 . V_59 ;
V_55 != & V_58 ;
V_55 = V_55 -> V_59 ) {
V_2 = F_25 ( V_55 , struct V_1 , V_23 ) ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
continue;
if ( V_5 > 0 )
break;
if ( V_4 -> V_60 ) {
V_2 = NULL ;
goto V_61;
}
if ( ! F_26 ( V_2 ) ) {
V_55 = V_55 -> V_59 ;
F_27 ( & V_2 -> V_23 ) ;
break;
}
V_56 = L_10 ;
goto V_62;
}
V_2 = F_4 ( V_4 ) ;
if ( ! V_2 )
goto V_63;
V_37 = F_15 ( V_2 ) ;
if ( V_37 < 0 )
goto V_64;
F_28 ( & V_2 -> V_23 , V_55 ) ;
V_56 = L_11 ;
V_62:
F_29 ( & V_57 ) ;
F_30 ( L_12 ,
V_56 , V_2 -> V_34 , & V_2 -> V_4 . V_8 ) ;
F_14 ( L_1 , V_2 ) ;
return V_2 ;
V_63:
V_37 = - V_65 ;
V_64:
F_29 ( & V_57 ) ;
F_31 ( V_2 ) ;
F_14 ( L_8 , V_37 ) ;
return F_32 ( V_37 ) ;
V_61:
F_29 ( & V_57 ) ;
F_14 ( L_13 ) ;
return F_32 ( - V_66 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_16 ( L_14 , V_2 -> V_34 ) ;
F_34 ( & V_2 -> V_24 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_40 * V_40 = V_2 -> V_40 ;
F_16 ( L_14 , V_2 -> V_34 ) ;
if ( V_2 -> V_67 ) {
F_14 ( L_15 ) ;
return;
}
V_2 -> V_67 = true ;
F_24 ( & V_57 ) ;
F_27 ( & V_2 -> V_23 ) ;
F_29 ( & V_57 ) ;
ASSERT ( F_36 ( & V_2 -> V_29 ) ) ;
ASSERT ( ! V_2 -> V_68 ) ;
if ( V_40 ) {
V_2 -> V_40 = NULL ;
F_21 ( V_40 , V_53 ) ;
V_40 -> V_47 -> V_48 = NULL ;
F_22 ( V_40 ) ;
}
F_37 ( & V_2 -> V_27 ) ;
F_37 ( & V_2 -> V_28 ) ;
F_18 ( L_16 , V_2 -> V_34 ) ;
F_38 ( & V_2 -> V_69 , V_70 ) ;
}
static void V_25 ( struct V_71 * V_72 )
{
struct V_1 * V_2 =
F_39 ( V_72 , struct V_1 , V_24 ) ;
bool V_73 ;
F_16 ( L_14 , V_2 -> V_34 ) ;
do {
V_73 = false ;
if ( F_40 ( & V_2 -> V_22 ) == 0 )
return F_35 ( V_2 ) ;
if ( ! F_41 ( & V_2 -> V_27 ) ) {
F_42 ( V_2 ) ;
V_73 = true ;
}
if ( ! F_41 ( & V_2 -> V_28 ) ) {
F_43 ( V_2 ) ;
V_73 = true ;
}
} while ( V_73 );
}
static void V_70 ( struct V_74 * V_69 )
{
struct V_1 * V_2 = F_39 ( V_69 , struct V_1 , V_69 ) ;
F_16 ( L_14 , V_2 -> V_34 ) ;
ASSERT ( ! F_44 ( & V_2 -> V_24 ) ) ;
F_30 ( L_17 , V_2 -> V_34 ) ;
F_31 ( V_2 ) ;
F_14 ( L_18 ) ;
}
void T_1 F_45 ( void )
{
struct V_1 * V_2 ;
F_16 ( L_18 ) ;
F_46 ( V_75 ) ;
if ( ! F_47 ( & V_58 ) ) {
F_24 ( & V_57 ) ;
F_48 (local, &rxrpc_local_endpoints, link) {
F_49 ( L_19 ,
V_2 , F_40 ( & V_2 -> V_22 ) ) ;
}
F_29 ( & V_57 ) ;
F_3 () ;
}
F_50 () ;
}
