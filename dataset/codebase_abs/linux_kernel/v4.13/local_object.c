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
static struct V_1 * F_4 ( struct V_21 * V_22 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( sizeof( struct V_1 ) , V_23 ) ;
if ( V_2 ) {
F_6 ( & V_2 -> V_24 , 1 ) ;
V_2 -> V_22 = V_22 ;
F_7 ( & V_2 -> V_25 ) ;
F_8 ( & V_2 -> V_26 , V_27 ) ;
F_9 ( & V_2 -> V_28 ) ;
F_10 ( & V_2 -> V_29 ) ;
F_10 ( & V_2 -> V_30 ) ;
V_2 -> V_31 = V_32 ;
F_11 ( & V_2 -> V_33 ) ;
F_11 ( & V_2 -> V_34 ) ;
F_12 ( & V_2 -> V_35 ) ;
V_2 -> V_36 = F_13 ( & V_37 ) ;
memcpy ( & V_2 -> V_4 , V_4 , sizeof( * V_4 ) ) ;
V_2 -> V_4 . V_38 = 0 ;
}
F_14 ( L_1 , V_2 ) ;
return V_2 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_39 * V_39 )
{
struct V_40 * V_40 ;
int V_41 , V_42 ;
F_16 ( L_2 ,
V_2 , V_2 -> V_4 . V_6 , V_2 -> V_4 . V_8 . V_9 ) ;
V_41 = F_17 ( V_39 , V_2 -> V_4 . V_8 . V_9 ,
V_2 -> V_4 . V_6 , 0 , & V_2 -> V_43 ) ;
if ( V_41 < 0 ) {
F_14 ( L_3 , V_41 ) ;
return V_41 ;
}
if ( V_2 -> V_4 . V_7 > sizeof( V_44 ) ) {
F_18 ( L_4 ) ;
V_41 = F_19 ( V_2 -> V_43 ,
(struct V_45 * ) & V_2 -> V_4 . V_8 ,
V_2 -> V_4 . V_7 ) ;
if ( V_41 < 0 ) {
F_18 ( L_5 , V_41 ) ;
goto error;
}
}
V_42 = 1 ;
V_41 = F_20 ( V_2 -> V_43 , V_46 , V_47 ,
( char * ) & V_42 , sizeof( V_42 ) ) ;
if ( V_41 < 0 ) {
F_18 ( L_6 ) ;
goto error;
}
V_42 = V_48 ;
V_41 = F_20 ( V_2 -> V_43 , V_46 , V_49 ,
( char * ) & V_42 , sizeof( V_42 ) ) ;
if ( V_41 < 0 ) {
F_18 ( L_6 ) ;
goto error;
}
V_40 = V_2 -> V_43 -> V_50 ;
V_40 -> V_51 = V_2 ;
V_40 -> V_52 = V_53 ;
V_40 -> V_54 = V_55 ;
F_14 ( L_7 ) ;
return 0 ;
error:
F_21 ( V_2 -> V_43 , V_56 ) ;
V_2 -> V_43 -> V_50 -> V_51 = NULL ;
F_22 ( V_2 -> V_43 ) ;
V_2 -> V_43 = NULL ;
F_14 ( L_8 , V_41 ) ;
return V_41 ;
}
struct V_1 * F_23 ( struct V_39 * V_39 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 = V_21 ( V_39 ) ;
struct V_57 * V_58 ;
const char * V_59 ;
long V_5 ;
int V_41 ;
F_16 ( L_9 ,
V_4 -> V_6 , V_4 -> V_8 . V_9 , & V_4 -> V_8 ) ;
F_24 ( & V_22 -> V_60 ) ;
for ( V_58 = V_22 -> V_61 . V_62 ;
V_58 != & V_22 -> V_61 ;
V_58 = V_58 -> V_62 ) {
V_2 = F_25 ( V_58 , struct V_1 , V_25 ) ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
continue;
if ( V_5 > 0 )
break;
if ( V_4 -> V_38 ) {
V_2 = NULL ;
goto V_63;
}
if ( ! F_26 ( V_2 ) ) {
V_58 = V_58 -> V_62 ;
F_27 ( & V_2 -> V_25 ) ;
break;
}
V_59 = L_10 ;
goto V_64;
}
V_2 = F_4 ( V_22 , V_4 ) ;
if ( ! V_2 )
goto V_65;
V_41 = F_15 ( V_2 , V_39 ) ;
if ( V_41 < 0 )
goto V_66;
F_28 ( & V_2 -> V_25 , V_58 ) ;
V_59 = L_11 ;
V_64:
F_29 ( & V_22 -> V_60 ) ;
F_30 ( L_12 ,
V_59 , V_2 -> V_36 , & V_2 -> V_4 . V_8 ) ;
F_14 ( L_1 , V_2 ) ;
return V_2 ;
V_65:
V_41 = - V_67 ;
V_66:
F_29 ( & V_22 -> V_60 ) ;
F_31 ( V_2 ) ;
F_14 ( L_8 , V_41 ) ;
return F_32 ( V_41 ) ;
V_63:
F_29 ( & V_22 -> V_60 ) ;
F_14 ( L_13 ) ;
return F_32 ( - V_68 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_16 ( L_14 , V_2 -> V_36 ) ;
F_34 ( & V_2 -> V_26 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_43 * V_43 = V_2 -> V_43 ;
struct V_21 * V_22 = V_2 -> V_22 ;
F_16 ( L_14 , V_2 -> V_36 ) ;
if ( V_2 -> V_69 ) {
F_14 ( L_15 ) ;
return;
}
V_2 -> V_69 = true ;
F_24 ( & V_22 -> V_60 ) ;
F_27 ( & V_2 -> V_25 ) ;
F_29 ( & V_22 -> V_60 ) ;
ASSERT ( F_36 ( & V_2 -> V_31 ) ) ;
ASSERT ( ! V_2 -> V_70 ) ;
if ( V_43 ) {
V_2 -> V_43 = NULL ;
F_21 ( V_43 , V_56 ) ;
V_43 -> V_50 -> V_51 = NULL ;
F_22 ( V_43 ) ;
}
F_37 ( & V_2 -> V_29 ) ;
F_37 ( & V_2 -> V_30 ) ;
F_18 ( L_16 , V_2 -> V_36 ) ;
F_38 ( & V_2 -> V_71 , V_72 ) ;
}
static void V_27 ( struct V_73 * V_74 )
{
struct V_1 * V_2 =
F_39 ( V_74 , struct V_1 , V_26 ) ;
bool V_75 ;
F_16 ( L_14 , V_2 -> V_36 ) ;
do {
V_75 = false ;
if ( F_40 ( & V_2 -> V_24 ) == 0 )
return F_35 ( V_2 ) ;
if ( ! F_41 ( & V_2 -> V_29 ) ) {
F_42 ( V_2 ) ;
V_75 = true ;
}
if ( ! F_41 ( & V_2 -> V_30 ) ) {
F_43 ( V_2 ) ;
V_75 = true ;
}
} while ( V_75 );
}
static void V_72 ( struct V_76 * V_71 )
{
struct V_1 * V_2 = F_39 ( V_71 , struct V_1 , V_71 ) ;
F_16 ( L_14 , V_2 -> V_36 ) ;
ASSERT ( ! F_44 ( & V_2 -> V_26 ) ) ;
F_30 ( L_17 , V_2 -> V_36 ) ;
F_31 ( V_2 ) ;
F_14 ( L_18 ) ;
}
void F_45 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
F_16 ( L_18 ) ;
F_46 ( V_77 ) ;
if ( ! F_47 ( & V_22 -> V_61 ) ) {
F_24 ( & V_22 -> V_60 ) ;
F_48 (local, &rxnet->local_endpoints, link) {
F_49 ( L_19 ,
V_2 , F_40 ( & V_2 -> V_24 ) ) ;
}
F_29 ( & V_22 -> V_60 ) ;
F_3 () ;
}
}
