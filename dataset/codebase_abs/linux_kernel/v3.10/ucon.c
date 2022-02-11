static int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
unsigned int V_6 ;
int V_7 ;
char V_8 [ 128 ] ;
struct V_2 * V_9 ;
V_6 = F_2 ( sizeof( struct V_2 ) + V_3 -> V_10 ) ;
V_5 = (struct V_4 * ) V_8 ;
V_5 -> V_11 = V_12 ++ ;
V_5 -> V_13 = F_3 () ;
V_5 -> V_14 = V_15 ;
V_5 -> V_16 = F_4 ( V_6 - sizeof( * V_5 ) ) ;
V_5 -> V_17 = 0 ;
V_9 = F_5 ( V_5 ) ;
#if 0
ulog("%s: [%08x.%08x] len=%u, seq=%u, ack=%u.\n",
__func__, msg->id.idx, msg->id.val, msg->len, msg->seq, msg->ack);
#endif
memcpy ( V_9 , V_3 , sizeof( * V_9 ) + V_3 -> V_10 ) ;
V_7 = F_6 ( V_1 , V_5 , V_6 , 0 ) ;
if ( V_7 == - 1 )
F_7 ( L_1 ,
strerror ( V_18 ) , V_18 ) ;
return V_7 ;
}
static void F_8 ( void )
{
printf (
L_2
L_3
L_4
L_5
L_3
L_6
L_7
L_8
L_9
L_3
L_10
L_11
, V_19 , V_20
) ;
}
int main ( int V_21 , char * V_22 [] )
{
int V_1 ;
char V_8 [ 1024 ] ;
int V_10 ;
struct V_4 * V_23 ;
struct V_24 V_25 ;
struct V_2 * V_26 ;
T_1 * V_27 ;
T_2 V_28 ;
struct V_29 V_30 ;
bool V_31 = false ;
while ( ( V_1 = F_9 ( V_21 , V_22 , L_12 ) ) != - 1 ) {
switch ( V_1 ) {
case 's' :
V_31 = true ;
break;
case 'h' :
F_8 () ;
return 0 ;
default:
F_8 () ;
return 1 ;
}
}
if ( V_21 != V_32 ) {
V_27 = fopen ( V_22 [ V_32 ] , L_13 ) ;
if ( ! V_27 ) {
F_7 ( L_14 ,
V_22 [ 1 ] , strerror ( V_18 ) ) ;
V_27 = stdout ;
}
} else
V_27 = stdout ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_1 = F_10 ( V_33 , V_34 , V_35 ) ;
if ( V_1 == - 1 ) {
perror ( L_15 ) ;
return - 1 ;
}
V_25 . V_36 = V_37 ;
V_25 . V_38 = - 1 ;
V_25 . V_39 = 0 ;
F_7 ( L_16 , V_19 , V_20 ) ;
if ( F_11 ( V_1 , (struct V_40 * ) & V_25 , sizeof( struct V_24 ) ) == - 1 ) {
perror ( L_17 ) ;
F_12 ( V_1 ) ;
return - 1 ;
}
#if 0
{
int on = 0x57;
setsockopt(s, SOL_NETLINK, NETLINK_ADD_MEMBERSHIP, &on, sizeof(on));
}
#endif
if ( V_31 ) {
int V_41 , V_42 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_26 = (struct V_2 * ) V_8 ;
V_26 -> V_43 . V_44 = V_19 ;
V_26 -> V_43 . V_45 = V_20 ;
V_26 -> V_12 = V_12 ++ ;
V_26 -> V_46 = 0 ;
V_26 -> V_10 = 0 ;
for ( V_42 = 0 ; V_42 < 10 ; ++ V_42 ) {
for ( V_41 = 0 ; V_41 < 1000 ; ++ V_41 ) {
V_10 = F_1 ( V_1 , V_26 ) ;
}
F_7 ( L_18 , V_41 , V_26 -> V_43 . V_44 , V_26 -> V_43 . V_45 ) ;
}
return 0 ;
}
V_30 . V_47 = V_1 ;
while ( ! V_48 ) {
V_30 . V_49 = V_50 ;
V_30 . V_51 = 0 ;
switch ( F_13 ( & V_30 , 1 , - 1 ) ) {
case 0 :
V_48 = 1 ;
break;
case - 1 :
if ( V_18 != V_52 ) {
V_48 = 1 ;
break;
}
continue;
}
if ( V_48 )
break;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_10 = F_14 ( V_1 , V_8 , sizeof( V_8 ) , 0 ) ;
if ( V_10 == - 1 ) {
perror ( L_19 ) ;
F_12 ( V_1 ) ;
return - 1 ;
}
V_23 = (struct V_4 * ) V_8 ;
switch ( V_23 -> V_14 ) {
case V_53 :
fprintf ( V_27 , L_20 ) ;
fflush ( V_27 ) ;
break;
case V_15 :
V_26 = (struct V_2 * ) F_5 ( V_23 ) ;
time ( & V_28 ) ;
fprintf ( V_27 , L_21 ,
ctime ( & V_28 ) , V_26 -> V_43 . V_44 , V_26 -> V_43 . V_45 , V_26 -> V_12 , V_26 -> V_46 ) ;
fflush ( V_27 ) ;
break;
default:
break;
}
}
F_12 ( V_1 ) ;
return 0 ;
}
