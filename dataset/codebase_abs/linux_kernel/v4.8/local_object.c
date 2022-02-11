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
default:
F_2 () ;
}
}
static struct V_1 * F_3 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( struct V_1 ) , V_16 ) ;
if ( V_2 ) {
F_5 ( & V_2 -> V_17 , 1 ) ;
F_6 ( & V_2 -> V_18 ) ;
F_7 ( & V_2 -> V_19 , V_20 ) ;
F_6 ( & V_2 -> V_21 ) ;
F_8 ( & V_2 -> V_22 ) ;
F_9 ( & V_2 -> V_23 ) ;
F_9 ( & V_2 -> V_24 ) ;
F_9 ( & V_2 -> V_25 ) ;
V_2 -> V_26 = V_27 ;
F_10 ( & V_2 -> V_28 ) ;
F_10 ( & V_2 -> V_29 ) ;
F_11 ( & V_2 -> V_30 ) ;
V_2 -> V_31 = F_12 ( & V_32 ) ;
memcpy ( & V_2 -> V_4 , V_4 , sizeof( * V_4 ) ) ;
}
F_13 ( L_1 , V_2 ) ;
return V_2 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_33 * V_33 ;
int V_34 , V_35 ;
F_15 ( L_2 , V_2 , V_2 -> V_4 . V_6 ) ;
V_34 = F_16 ( & V_36 , V_37 , V_2 -> V_4 . V_6 ,
V_38 , & V_2 -> V_39 ) ;
if ( V_34 < 0 ) {
F_13 ( L_3 , V_34 ) ;
return V_34 ;
}
if ( V_2 -> V_4 . V_7 > sizeof( V_40 ) ) {
F_17 ( L_4 ) ;
V_34 = F_18 ( V_2 -> V_39 ,
(struct V_41 * ) & V_2 -> V_4 . V_8 ,
V_2 -> V_4 . V_7 ) ;
if ( V_34 < 0 ) {
F_17 ( L_5 , V_34 ) ;
goto error;
}
}
V_35 = 1 ;
V_34 = F_19 ( V_2 -> V_39 , V_42 , V_43 ,
( char * ) & V_35 , sizeof( V_35 ) ) ;
if ( V_34 < 0 ) {
F_17 ( L_6 ) ;
goto error;
}
V_35 = V_44 ;
V_34 = F_19 ( V_2 -> V_39 , V_42 , V_45 ,
( char * ) & V_35 , sizeof( V_35 ) ) ;
if ( V_34 < 0 ) {
F_17 ( L_6 ) ;
goto error;
}
V_33 = V_2 -> V_39 -> V_46 ;
V_33 -> V_47 = V_2 ;
V_33 -> V_48 = V_49 ;
V_33 -> V_50 = V_51 ;
F_13 ( L_7 ) ;
return 0 ;
error:
F_20 ( V_2 -> V_39 , V_52 ) ;
V_2 -> V_39 -> V_46 -> V_47 = NULL ;
F_21 ( V_2 -> V_39 ) ;
V_2 -> V_39 = NULL ;
F_13 ( L_8 , V_34 ) ;
return V_34 ;
}
struct V_1 * F_22 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_53 * V_54 ;
const char * V_55 ;
long V_5 ;
int V_34 ;
if ( V_4 -> V_8 . V_9 == V_10 ) {
F_15 ( L_9 ,
V_4 -> V_6 ,
V_4 -> V_8 . V_9 ,
& V_4 -> V_8 . sin . V_14 ,
F_23 ( V_4 -> V_8 . sin . V_13 ) ) ;
} else {
F_15 ( L_10 ,
V_4 -> V_6 ,
V_4 -> V_8 . V_9 ) ;
return F_24 ( - V_56 ) ;
}
F_25 ( & V_57 ) ;
for ( V_54 = V_58 . V_59 ;
V_54 != & V_58 ;
V_54 = V_54 -> V_59 ) {
V_2 = F_26 ( V_54 , struct V_1 , V_18 ) ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
continue;
if ( V_5 > 0 )
break;
if ( V_4 -> V_60 ) {
V_2 = NULL ;
goto V_61;
}
if ( ! F_27 ( V_2 ) ) {
V_54 = V_54 -> V_59 ;
F_28 ( & V_2 -> V_18 ) ;
break;
}
V_55 = L_11 ;
goto V_62;
}
V_2 = F_3 ( V_4 ) ;
if ( ! V_2 )
goto V_63;
V_34 = F_14 ( V_2 ) ;
if ( V_34 < 0 )
goto V_64;
F_29 ( & V_2 -> V_18 , V_54 ) ;
V_55 = L_12 ;
V_62:
F_30 ( & V_57 ) ;
F_31 ( L_13 ,
V_55 ,
V_2 -> V_31 ,
V_2 -> V_4 . V_6 ,
V_2 -> V_4 . V_8 . V_9 ,
& V_2 -> V_4 . V_8 . sin . V_14 ,
F_23 ( V_2 -> V_4 . V_8 . sin . V_13 ) ) ;
F_13 ( L_1 , V_2 ) ;
return V_2 ;
V_63:
V_34 = - V_65 ;
V_64:
F_30 ( & V_57 ) ;
F_32 ( V_2 ) ;
F_13 ( L_8 , V_34 ) ;
return F_24 ( V_34 ) ;
V_61:
F_30 ( & V_57 ) ;
F_13 ( L_14 ) ;
return F_24 ( - V_66 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_15 ( L_15 , V_2 -> V_31 ) ;
F_34 ( & V_2 -> V_19 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_39 * V_39 = V_2 -> V_39 ;
F_15 ( L_15 , V_2 -> V_31 ) ;
if ( V_2 -> V_67 ) {
F_13 ( L_16 ) ;
return;
}
V_2 -> V_67 = true ;
F_25 ( & V_57 ) ;
F_28 ( & V_2 -> V_18 ) ;
F_30 ( & V_57 ) ;
ASSERT ( F_36 ( & V_2 -> V_26 ) ) ;
ASSERT ( F_37 ( & V_2 -> V_21 ) ) ;
if ( V_39 ) {
V_2 -> V_39 = NULL ;
F_20 ( V_39 , V_52 ) ;
V_39 -> V_46 -> V_47 = NULL ;
F_21 ( V_39 ) ;
}
F_38 ( & V_2 -> V_23 ) ;
F_38 ( & V_2 -> V_24 ) ;
F_38 ( & V_2 -> V_25 ) ;
F_17 ( L_17 , V_2 -> V_31 ) ;
F_39 ( & V_2 -> V_68 , V_69 ) ;
}
static void V_20 ( struct V_70 * V_71 )
{
struct V_1 * V_2 =
F_40 ( V_71 , struct V_1 , V_19 ) ;
bool V_72 ;
F_15 ( L_15 , V_2 -> V_31 ) ;
do {
V_72 = false ;
if ( F_41 ( & V_2 -> V_17 ) == 0 )
return F_35 ( V_2 ) ;
if ( ! F_42 ( & V_2 -> V_23 ) ) {
F_43 ( V_2 ) ;
V_72 = true ;
}
if ( ! F_42 ( & V_2 -> V_24 ) ) {
F_44 ( V_2 ) ;
V_72 = true ;
}
if ( ! F_42 ( & V_2 -> V_25 ) ) {
F_45 ( V_2 ) ;
V_72 = true ;
}
} while ( V_72 );
}
static void V_69 ( struct V_73 * V_68 )
{
struct V_1 * V_2 = F_40 ( V_68 , struct V_1 , V_68 ) ;
F_15 ( L_15 , V_2 -> V_31 ) ;
ASSERT ( ! F_46 ( & V_2 -> V_19 ) ) ;
F_31 ( L_18 , V_2 -> V_31 ) ;
F_32 ( V_2 ) ;
F_13 ( L_19 ) ;
}
void T_1 F_47 ( void )
{
struct V_1 * V_2 ;
F_15 ( L_19 ) ;
F_48 ( V_74 ) ;
if ( ! F_37 ( & V_58 ) ) {
F_25 ( & V_57 ) ;
F_49 (local, &rxrpc_local_endpoints, link) {
F_50 ( L_20 ,
V_2 , F_41 ( & V_2 -> V_17 ) ) ;
}
F_30 ( & V_57 ) ;
F_2 () ;
}
F_51 () ;
}
