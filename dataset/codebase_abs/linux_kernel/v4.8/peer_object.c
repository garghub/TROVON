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
default:
F_4 ( 1 , L_2 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < V_7 ; V_6 += sizeof( * V_5 ) , V_5 ++ )
V_8 += * V_5 ;
F_5 ( L_3 , V_8 ) ;
return V_8 ;
}
static long F_6 ( const struct V_17 * V_18 ,
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned long V_8 )
{
long V_19 ;
V_19 = ( ( V_18 -> V_8 - V_8 ) ? :
( ( unsigned long ) V_18 -> V_2 - ( unsigned long ) V_2 ) ? :
( V_18 -> V_4 . V_9 - V_4 -> V_9 ) ? :
( V_18 -> V_4 . V_10 - V_4 -> V_10 ) ? :
( V_18 -> V_4 . V_11 . V_12 - V_4 -> V_11 . V_12 ) ) ;
if ( V_19 != 0 )
return V_19 ;
switch ( V_4 -> V_11 . V_12 ) {
case V_13 :
return ( ( T_1 V_14 ) V_18 -> V_4 . V_11 . sin . V_15 -
( T_1 V_14 ) V_4 -> V_11 . sin . V_15 ) ? :
memcmp ( & V_18 -> V_4 . V_11 . sin . V_16 ,
& V_4 -> V_11 . sin . V_16 ,
sizeof( struct V_20 ) ) ;
default:
F_7 () ;
}
}
static struct V_17 * F_8 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned long V_8 )
{
struct V_17 * V_18 ;
F_9 (rxrpc_peer_hash, peer, hash_link, hash_key) {
if ( F_6 ( V_18 , V_2 , V_4 , V_8 ) == 0 ) {
if ( F_10 ( & V_18 -> V_21 ) == 0 )
return NULL ;
return V_18 ;
}
}
return NULL ;
}
struct V_17 * F_11 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_17 * V_18 ;
unsigned long V_8 = F_1 ( V_2 , V_4 ) ;
V_18 = F_8 ( V_2 , V_4 , V_8 ) ;
if ( V_18 ) {
switch ( V_4 -> V_11 . V_12 ) {
case V_13 :
F_12 ( L_4 ,
V_18 -> V_22 ,
V_18 -> V_4 . V_9 ,
V_18 -> V_4 . V_11 . V_12 ,
& V_18 -> V_4 . V_11 . sin . V_16 ,
F_13 ( V_18 -> V_4 . V_11 . sin . V_15 ) ) ;
break;
}
F_5 ( L_5 , V_18 , F_10 ( & V_18 -> V_21 ) ) ;
}
return V_18 ;
}
static void F_14 ( struct V_17 * V_18 )
{
struct V_23 * V_24 ;
struct V_25 V_26 ;
V_18 -> V_27 = 1500 ;
V_24 = F_15 ( & V_28 , & V_26 , NULL ,
V_18 -> V_4 . V_11 . sin . V_16 . V_29 , 0 ,
F_16 ( 7000 ) , F_16 ( 7001 ) ,
V_30 , 0 , 0 ) ;
if ( F_17 ( V_24 ) ) {
F_5 ( L_6 , F_18 ( V_24 ) ) ;
return;
}
V_18 -> V_27 = F_19 ( & V_24 -> V_31 ) ;
F_20 ( & V_24 -> V_31 ) ;
F_5 ( L_7 , V_18 -> V_27 ) ;
}
struct V_17 * F_21 ( struct V_1 * V_2 , T_2 V_32 )
{
struct V_17 * V_18 ;
F_2 ( L_1 ) ;
V_18 = F_22 ( sizeof( struct V_17 ) , V_32 ) ;
if ( V_18 ) {
F_23 ( & V_18 -> V_21 , 1 ) ;
V_18 -> V_2 = V_2 ;
F_24 ( & V_18 -> V_33 ) ;
F_25 ( & V_18 -> V_34 ,
& V_35 ) ;
V_18 -> V_36 = V_37 ;
F_26 ( & V_18 -> V_38 ) ;
F_27 ( & V_18 -> V_39 ) ;
V_18 -> V_22 = F_28 ( & V_40 ) ;
}
F_5 ( L_8 , V_18 ) ;
return V_18 ;
}
static struct V_17 * F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_8 ,
T_2 V_32 )
{
struct V_17 * V_18 ;
F_2 ( L_1 ) ;
V_18 = F_21 ( V_2 , V_32 ) ;
if ( V_18 ) {
V_18 -> V_8 = V_8 ;
memcpy ( & V_18 -> V_4 , V_4 , sizeof( * V_4 ) ) ;
F_14 ( V_18 ) ;
V_18 -> V_41 = V_18 -> V_27 ;
if ( V_4 -> V_11 . V_12 == V_13 ) {
V_18 -> V_42 = sizeof( struct V_43 ) ;
switch ( V_4 -> V_9 ) {
case V_44 :
V_18 -> V_42 += sizeof( struct V_45 ) ;
break;
default:
F_7 () ;
break;
}
} else {
F_7 () ;
}
V_18 -> V_42 += sizeof( struct V_46 ) ;
V_18 -> V_47 = V_18 -> V_41 - V_18 -> V_42 ;
}
F_5 ( L_8 , V_18 ) ;
return V_18 ;
}
struct V_17 * F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_32 )
{
struct V_17 * V_18 , * V_48 ;
unsigned long V_8 = F_1 ( V_2 , V_4 ) ;
F_2 ( L_9 ,
V_4 -> V_9 ,
V_4 -> V_10 ,
& V_4 -> V_11 . sin . V_16 ,
F_13 ( V_4 -> V_11 . sin . V_15 ) ) ;
F_31 () ;
V_18 = F_8 ( V_2 , V_4 , V_8 ) ;
if ( V_18 && ! F_32 ( V_18 ) )
V_18 = NULL ;
F_33 () ;
if ( ! V_18 ) {
V_48 = F_29 ( V_2 , V_4 , V_8 , V_32 ) ;
if ( ! V_48 ) {
F_5 ( L_10 ) ;
return NULL ;
}
F_34 ( & V_49 ) ;
V_18 = F_8 ( V_2 , V_4 , V_8 ) ;
if ( V_18 && ! F_32 ( V_18 ) )
V_18 = NULL ;
if ( ! V_18 )
F_35 ( V_50 ,
& V_48 -> V_51 , V_8 ) ;
F_36 ( & V_49 ) ;
if ( V_18 )
F_37 ( V_48 ) ;
else
V_18 = V_48 ;
}
F_12 ( L_11 ,
V_18 -> V_22 ,
V_18 -> V_4 . V_9 ,
& V_18 -> V_4 . V_11 . sin . V_16 ,
F_13 ( V_18 -> V_4 . V_11 . sin . V_15 ) ) ;
F_5 ( L_5 , V_18 , F_10 ( & V_18 -> V_21 ) ) ;
return V_18 ;
}
void F_38 ( struct V_17 * V_18 )
{
ASSERT ( F_39 ( & V_18 -> V_33 ) ) ;
F_34 ( & V_49 ) ;
F_40 ( & V_18 -> V_51 ) ;
F_36 ( & V_49 ) ;
F_41 ( V_18 , V_52 ) ;
}
