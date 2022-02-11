static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
V_2 -> V_7 = 1500 ;
V_4 = F_2 ( & V_8 , & V_6 , NULL ,
V_2 -> V_9 . V_10 . sin . V_11 . V_12 , 0 ,
F_3 ( 7000 ) , F_3 ( 7001 ) ,
V_13 , 0 , 0 ) ;
if ( F_4 ( V_4 ) ) {
F_5 ( L_1 , F_6 ( V_4 ) ) ;
return;
}
V_2 -> V_7 = F_7 ( & V_4 -> V_14 ) ;
F_8 ( & V_4 -> V_14 ) ;
F_5 ( L_2 , V_2 -> V_7 ) ;
}
static struct V_1 * F_9 ( struct V_15 * V_9 ,
T_1 V_16 )
{
struct V_1 * V_2 ;
F_10 ( L_3 ) ;
V_2 = F_11 ( sizeof( struct V_1 ) , V_16 ) ;
if ( V_2 ) {
F_12 ( & V_2 -> V_17 , & V_18 ) ;
F_13 ( & V_2 -> V_19 ) ;
F_13 ( & V_2 -> V_20 ) ;
F_14 ( & V_2 -> V_21 ) ;
F_15 ( & V_2 -> V_22 , 1 ) ;
V_2 -> V_23 = F_16 ( & V_24 ) ;
memcpy ( & V_2 -> V_9 , V_9 , sizeof( * V_9 ) ) ;
F_1 ( V_2 ) ;
V_2 -> V_25 = V_2 -> V_7 ;
if ( V_9 -> V_10 . V_26 == V_27 ) {
V_2 -> V_28 = sizeof( struct V_29 ) ;
switch ( V_9 -> V_30 ) {
case V_31 :
V_2 -> V_28 += sizeof( struct V_32 ) ;
break;
default:
F_17 () ;
break;
}
} else {
F_17 () ;
}
V_2 -> V_28 += sizeof( struct V_33 ) ;
V_2 -> V_34 = V_2 -> V_25 - V_2 -> V_28 ;
}
F_5 ( L_4 , V_2 ) ;
return V_2 ;
}
struct V_1 * F_18 ( struct V_15 * V_9 , T_1 V_16 )
{
struct V_1 * V_2 , * V_35 ;
const char * V_36 = L_5 ;
int V_22 ;
F_10 ( L_6 ,
V_9 -> V_30 ,
V_9 -> V_37 ,
& V_9 -> V_10 . sin . V_11 ,
F_19 ( V_9 -> V_10 . sin . V_38 ) ) ;
F_20 ( & V_39 ) ;
F_21 (peer, &rxrpc_peers, link) {
F_22 ( L_7 ,
V_2 -> V_23 ,
F_23 ( & V_2 -> V_22 ) ,
V_2 -> V_9 . V_30 ,
V_2 -> V_9 . V_37 ) ;
if ( F_23 ( & V_2 -> V_22 ) > 0 &&
V_2 -> V_9 . V_30 == V_9 -> V_30 &&
V_2 -> V_9 . V_37 == V_9 -> V_37 &&
memcmp ( & V_2 -> V_9 . V_10 ,
& V_9 -> V_10 ,
V_9 -> V_37 ) == 0 )
goto V_40;
}
F_24 ( & V_39 ) ;
V_35 = F_9 ( V_9 , V_16 ) ;
if ( ! V_35 ) {
F_5 ( L_8 ) ;
return F_25 ( - V_41 ) ;
}
F_26 ( & V_39 ) ;
F_21 (peer, &rxrpc_peers, link) {
if ( F_23 ( & V_2 -> V_22 ) > 0 &&
V_2 -> V_9 . V_30 == V_9 -> V_30 &&
V_2 -> V_9 . V_37 == V_9 -> V_37 &&
memcmp ( & V_2 -> V_9 . V_10 ,
& V_9 -> V_10 ,
V_9 -> V_37 ) == 0 )
goto V_42;
}
V_2 = V_35 ;
V_35 = NULL ;
V_22 = F_23 ( & V_2 -> V_22 ) ;
F_27 ( & V_2 -> V_19 , & V_43 ) ;
F_28 ( & V_39 ) ;
V_36 = L_9 ;
V_44:
F_29 ( L_10 ,
V_36 ,
V_2 -> V_23 ,
V_2 -> V_9 . V_30 ,
V_2 -> V_9 . V_10 . V_26 ,
& V_2 -> V_9 . V_10 . sin . V_11 ,
F_19 ( V_2 -> V_9 . V_10 . sin . V_38 ) ) ;
F_5 ( L_11 , V_2 , V_22 ) ;
return V_2 ;
V_40:
V_22 = F_16 ( & V_2 -> V_22 ) ;
F_24 ( & V_39 ) ;
goto V_44;
V_42:
V_22 = F_16 ( & V_2 -> V_22 ) ;
F_28 ( & V_39 ) ;
F_30 ( V_35 ) ;
goto V_44;
}
struct V_1 * F_31 ( struct V_45 * V_46 ,
T_2 V_47 , T_3 V_48 )
{
struct V_1 * V_2 ;
F_10 ( L_3 ) ;
F_20 ( & V_39 ) ;
if ( V_46 -> V_9 . V_10 . V_26 == V_27 &&
V_46 -> V_9 . V_30 == V_31
) {
F_21 (peer, &rxrpc_peers, link) {
if ( F_23 ( & V_2 -> V_22 ) > 0 &&
V_2 -> V_9 . V_30 == V_31 &&
V_2 -> V_9 . V_10 . V_26 == V_27 &&
V_2 -> V_9 . V_10 . sin . V_38 == V_48 &&
V_2 -> V_9 . V_10 . sin . V_11 . V_12 == V_47 )
goto V_49;
}
goto V_50;
}
F_24 ( & V_39 ) ;
F_5 ( L_12 ) ;
return F_25 ( - V_51 ) ;
V_49:
F_29 ( L_13 , V_2 -> V_23 ) ;
F_32 ( & V_2 -> V_22 ) ;
F_24 ( & V_39 ) ;
F_5 ( L_4 , V_2 ) ;
return V_2 ;
V_50:
F_29 ( L_14 , V_2 -> V_23 ) ;
F_24 ( & V_39 ) ;
F_5 ( L_15 ) ;
return F_25 ( - V_52 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_10 ( L_16 , V_2 , F_23 ( & V_2 -> V_22 ) ) ;
F_34 ( F_23 ( & V_2 -> V_22 ) , > , 0 ) ;
if ( F_35 ( ! F_36 ( & V_2 -> V_22 ) ) ) {
F_5 ( L_17 ) ;
return;
}
F_37 ( & V_2 -> V_17 ) ;
F_5 ( L_3 ) ;
}
static void V_18 ( struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_38 ( V_54 , struct V_1 , V_17 ) ;
F_10 ( L_18 , V_2 , F_23 ( & V_2 -> V_22 ) ) ;
F_26 ( & V_39 ) ;
F_39 ( & V_2 -> V_19 ) ;
F_28 ( & V_39 ) ;
F_29 ( L_19 , V_2 -> V_23 ) ;
F_30 ( V_2 ) ;
if ( F_40 ( & V_43 ) )
F_41 ( & V_55 ) ;
F_5 ( L_3 ) ;
}
void T_4 F_42 ( void )
{
F_43 ( V_56 , V_57 ) ;
F_10 ( L_3 ) ;
if ( ! F_40 ( & V_43 ) ) {
F_44 ( V_58 ) ;
F_45 ( & V_55 , & V_56 ) ;
while ( ! F_40 ( & V_43 ) ) {
F_46 () ;
F_44 ( V_58 ) ;
}
F_47 ( & V_55 , & V_56 ) ;
F_44 ( V_59 ) ;
}
F_5 ( L_3 ) ;
}
