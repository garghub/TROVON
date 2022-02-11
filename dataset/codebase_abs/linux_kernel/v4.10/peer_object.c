static unsigned long F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const T_1 * V_5 ;
unsigned int V_6 , V_7 ;
unsigned long V_8 ;
F_2 ( L_1 ) ;
V_8 = ( unsigned long ) V_2 / F_3 ( * V_2 ) ;
V_8 += V_4 -> V_9 ;
V_8 += V_4 -> V_10 ;
V_8 += V_4 -> V_11 . V_12 ;
switch ( V_4 -> V_11 . V_12 ) {
case V_13 :
V_8 += ( T_1 V_14 ) V_4 -> V_11 . sin . V_15 ;
V_7 = sizeof( V_4 -> V_11 . sin . V_16 ) ;
V_5 = ( T_1 * ) & V_4 -> V_11 . sin . V_16 ;
break;
#ifdef F_4
case V_17 :
V_8 += ( T_1 V_14 ) V_4 -> V_11 . sin . V_15 ;
V_7 = sizeof( V_4 -> V_11 . V_18 . V_19 ) ;
V_5 = ( T_1 * ) & V_4 -> V_11 . V_18 . V_19 ;
break;
#endif
default:
F_5 ( 1 , L_2 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < V_7 ; V_6 += sizeof( * V_5 ) , V_5 ++ )
V_8 += * V_5 ;
F_6 ( L_3 , V_8 ) ;
return V_8 ;
}
static long F_7 ( const struct V_20 * V_21 ,
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned long V_8 )
{
long V_22 ;
V_22 = ( ( V_21 -> V_8 - V_8 ) ? :
( ( unsigned long ) V_21 -> V_2 - ( unsigned long ) V_2 ) ? :
( V_21 -> V_4 . V_9 - V_4 -> V_9 ) ? :
( V_21 -> V_4 . V_10 - V_4 -> V_10 ) ? :
( V_21 -> V_4 . V_11 . V_12 - V_4 -> V_11 . V_12 ) ) ;
if ( V_22 != 0 )
return V_22 ;
switch ( V_4 -> V_11 . V_12 ) {
case V_13 :
return ( ( T_1 V_14 ) V_21 -> V_4 . V_11 . sin . V_15 -
( T_1 V_14 ) V_4 -> V_11 . sin . V_15 ) ? :
memcmp ( & V_21 -> V_4 . V_11 . sin . V_16 ,
& V_4 -> V_11 . sin . V_16 ,
sizeof( struct V_23 ) ) ;
#ifdef F_4
case V_17 :
return ( ( T_1 V_14 ) V_21 -> V_4 . V_11 . V_18 . V_24 -
( T_1 V_14 ) V_4 -> V_11 . V_18 . V_24 ) ? :
memcmp ( & V_21 -> V_4 . V_11 . V_18 . V_19 ,
& V_4 -> V_11 . V_18 . V_19 ,
sizeof( struct V_25 ) ) ;
#endif
default:
F_8 () ;
}
}
static struct V_20 * F_9 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned long V_8 )
{
struct V_20 * V_21 ;
F_10 (rxrpc_peer_hash, peer, hash_link, hash_key) {
if ( F_7 ( V_21 , V_2 , V_4 , V_8 ) == 0 ) {
if ( F_11 ( & V_21 -> V_26 ) == 0 )
return NULL ;
return V_21 ;
}
}
return NULL ;
}
struct V_20 * F_12 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_20 * V_21 ;
unsigned long V_8 = F_1 ( V_2 , V_4 ) ;
V_21 = F_9 ( V_2 , V_4 , V_8 ) ;
if ( V_21 ) {
F_13 ( L_4 , V_21 -> V_27 , & V_21 -> V_4 . V_11 ) ;
F_6 ( L_5 , V_21 , F_11 ( & V_21 -> V_26 ) ) ;
}
return V_21 ;
}
static void F_14 ( struct V_20 * V_21 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 V_33 ;
struct V_34 * V_35 = & V_33 . V_36 . V_37 ;
#ifdef F_4
struct V_38 * V_39 = & V_33 . V_36 . V_40 ;
#endif
V_21 -> V_41 = 1500 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
switch ( V_21 -> V_4 . V_11 . V_12 ) {
case V_13 :
V_31 = F_15 (
& V_42 , V_35 , NULL ,
V_21 -> V_4 . V_11 . sin . V_16 . V_43 , 0 ,
F_16 ( 7000 ) , F_16 ( 7001 ) , V_44 , 0 , 0 ) ;
if ( F_17 ( V_31 ) ) {
F_6 ( L_6 , F_18 ( V_31 ) ) ;
return;
}
V_29 = & V_31 -> V_29 ;
break;
#ifdef F_4
case V_17 :
V_39 -> V_45 = V_46 ;
V_39 -> V_47 = V_48 ;
V_39 -> V_49 = V_44 ;
memcpy ( & V_39 -> V_50 , & V_21 -> V_4 . V_11 . V_18 . V_19 ,
sizeof( struct V_25 ) ) ;
V_39 -> V_51 = F_16 ( 7001 ) ;
V_39 -> V_52 = F_16 ( 7000 ) ;
V_29 = F_19 ( & V_42 , NULL , V_39 ) ;
if ( V_29 -> error ) {
F_6 ( L_7 , V_29 -> error ) ;
return;
}
break;
#endif
default:
F_8 () ;
}
V_21 -> V_41 = F_20 ( V_29 ) ;
F_21 ( V_29 ) ;
F_6 ( L_8 , V_21 -> V_41 ) ;
}
struct V_20 * F_22 ( struct V_1 * V_2 , T_2 V_53 )
{
struct V_20 * V_21 ;
F_2 ( L_1 ) ;
V_21 = F_23 ( sizeof( struct V_20 ) , V_53 ) ;
if ( V_21 ) {
F_24 ( & V_21 -> V_26 , 1 ) ;
V_21 -> V_2 = V_2 ;
F_25 ( & V_21 -> V_54 ) ;
F_26 ( & V_21 -> V_55 ,
& V_56 ) ;
V_21 -> V_57 = V_58 ;
F_27 ( & V_21 -> V_59 ) ;
F_28 ( & V_21 -> V_60 ) ;
V_21 -> V_27 = F_29 ( & V_61 ) ;
}
F_6 ( L_9 , V_21 ) ;
return V_21 ;
}
static void F_30 ( struct V_20 * V_21 , unsigned long V_8 )
{
V_21 -> V_8 = V_8 ;
F_14 ( V_21 ) ;
V_21 -> V_62 = V_21 -> V_41 ;
V_21 -> V_63 = F_31 () ;
switch ( V_21 -> V_4 . V_11 . V_12 ) {
case V_13 :
V_21 -> V_64 = sizeof( struct V_65 ) ;
break;
#ifdef F_4
case V_17 :
V_21 -> V_64 = sizeof( struct V_66 ) ;
break;
#endif
default:
F_8 () ;
}
switch ( V_21 -> V_4 . V_9 ) {
case V_67 :
V_21 -> V_64 += sizeof( struct V_68 ) ;
break;
default:
F_8 () ;
}
V_21 -> V_64 += sizeof( struct V_69 ) ;
V_21 -> V_70 = V_21 -> V_62 - V_21 -> V_64 ;
}
static struct V_20 * F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_8 ,
T_2 V_53 )
{
struct V_20 * V_21 ;
F_2 ( L_1 ) ;
V_21 = F_22 ( V_2 , V_53 ) ;
if ( V_21 ) {
memcpy ( & V_21 -> V_4 , V_4 , sizeof( * V_4 ) ) ;
F_30 ( V_21 , V_8 ) ;
}
F_6 ( L_9 , V_21 ) ;
return V_21 ;
}
struct V_20 * F_33 ( struct V_1 * V_2 ,
struct V_20 * V_71 )
{
struct V_20 * V_21 ;
unsigned long V_8 ;
V_8 = F_1 ( V_2 , & V_71 -> V_4 ) ;
V_71 -> V_2 = V_2 ;
F_30 ( V_71 , V_8 ) ;
F_34 ( & V_72 ) ;
V_21 = F_9 ( V_2 , & V_71 -> V_4 , V_8 ) ;
if ( V_21 && ! F_35 ( V_21 ) )
V_21 = NULL ;
if ( ! V_21 ) {
V_21 = V_71 ;
F_36 ( V_73 , & V_21 -> V_74 , V_8 ) ;
}
F_37 ( & V_72 ) ;
return V_21 ;
}
struct V_20 * F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_53 )
{
struct V_20 * V_21 , * V_75 ;
unsigned long V_8 = F_1 ( V_2 , V_4 ) ;
F_2 ( L_10 , & V_4 -> V_11 ) ;
F_39 () ;
V_21 = F_9 ( V_2 , V_4 , V_8 ) ;
if ( V_21 && ! F_35 ( V_21 ) )
V_21 = NULL ;
F_40 () ;
if ( ! V_21 ) {
V_75 = F_32 ( V_2 , V_4 , V_8 , V_53 ) ;
if ( ! V_75 ) {
F_6 ( L_11 ) ;
return NULL ;
}
F_41 ( & V_72 ) ;
V_21 = F_9 ( V_2 , V_4 , V_8 ) ;
if ( V_21 && ! F_35 ( V_21 ) )
V_21 = NULL ;
if ( ! V_21 )
F_36 ( V_73 ,
& V_75 -> V_74 , V_8 ) ;
F_42 ( & V_72 ) ;
if ( V_21 )
F_43 ( V_75 ) ;
else
V_21 = V_75 ;
}
F_13 ( L_4 , V_21 -> V_27 , & V_21 -> V_4 . V_11 ) ;
F_6 ( L_5 , V_21 , F_11 ( & V_21 -> V_26 ) ) ;
return V_21 ;
}
void F_44 ( struct V_20 * V_21 )
{
ASSERT ( F_45 ( & V_21 -> V_54 ) ) ;
F_41 ( & V_72 ) ;
F_46 ( & V_21 -> V_74 ) ;
F_42 ( & V_72 ) ;
F_47 ( V_21 , V_76 ) ;
}
void F_48 ( struct V_77 * V_78 , struct V_79 * V_80 ,
struct V_3 * V_81 )
{
* V_81 = V_80 -> V_21 -> V_4 ;
}
