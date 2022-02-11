static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 )
{
struct V_1 * V_7 ;
F_2 ( L_1 ) ;
V_7 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( V_7 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_5 = V_5 ;
F_4 ( & V_7 -> V_8 ) ;
V_7 -> V_9 = V_10 ;
V_7 -> V_11 = V_10 ;
V_7 -> V_12 = V_10 ;
F_5 ( & V_7 -> V_13 ) ;
F_6 ( & V_7 -> V_14 ) ;
F_7 ( & V_7 -> V_15 ) ;
F_8 ( & V_7 -> V_16 , 1 ) ;
V_7 -> V_17 = F_9 ( & V_18 ) ;
if ( V_5 -> V_19 . V_20 . V_21 == V_22 ) {
switch ( V_5 -> V_19 . V_23 ) {
case V_24 :
F_10 ( & V_7 -> V_25 ,
V_26 ) ;
break;
default:
F_11 () ;
break;
}
} else {
F_11 () ;
}
}
F_12 ( L_2 , V_7 ) ;
return V_7 ;
}
struct V_1 * F_13 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 )
{
struct V_1 * V_7 , * V_27 ;
const char * V_28 = L_3 ;
int V_16 ;
F_2 ( L_4 ,
& V_3 -> V_19 . V_20 . sin . V_29 ,
F_14 ( V_3 -> V_19 . V_20 . sin . V_30 ) ,
& V_5 -> V_19 . V_20 . sin . V_29 ,
F_14 ( V_5 -> V_19 . V_20 . sin . V_30 ) ) ;
F_15 ( & V_31 ) ;
F_16 (trans, &rxrpc_transports, link) {
if ( V_7 -> V_3 == V_3 && V_7 -> V_5 == V_5 )
goto V_32;
}
F_17 ( & V_31 ) ;
V_27 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( ! V_27 ) {
F_12 ( L_5 ) ;
return F_18 ( - V_33 ) ;
}
F_19 ( & V_31 ) ;
F_16 (trans, &rxrpc_transports, link) {
if ( V_7 -> V_3 == V_3 && V_7 -> V_5 == V_5 )
goto V_34;
}
V_7 = V_27 ;
V_27 = NULL ;
V_16 = F_20 ( & V_7 -> V_16 ) ;
F_21 ( V_7 -> V_3 ) ;
F_22 ( & V_7 -> V_5 -> V_16 ) ;
F_23 ( & V_7 -> V_8 , & V_35 ) ;
F_24 ( & V_31 ) ;
V_28 = L_6 ;
V_36:
F_25 ( L_7 ,
V_28 ,
V_7 -> V_17 ,
V_7 -> V_3 -> V_17 ,
V_7 -> V_5 -> V_17 ) ;
F_12 ( L_8 , V_7 , V_16 ) ;
return V_7 ;
V_32:
V_16 = F_9 ( & V_7 -> V_16 ) ;
F_17 ( & V_31 ) ;
goto V_36;
V_34:
V_16 = F_9 ( & V_7 -> V_16 ) ;
F_24 ( & V_31 ) ;
F_26 ( V_27 ) ;
goto V_36;
}
struct V_1 * F_27 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_7 ;
F_2 ( L_4 ,
& V_3 -> V_19 . V_20 . sin . V_29 ,
F_14 ( V_3 -> V_19 . V_20 . sin . V_30 ) ,
& V_5 -> V_19 . V_20 . sin . V_29 ,
F_14 ( V_5 -> V_19 . V_20 . sin . V_30 ) ) ;
F_15 ( & V_31 ) ;
F_16 (trans, &rxrpc_transports, link) {
if ( V_7 -> V_3 == V_3 && V_7 -> V_5 == V_5 )
goto V_32;
}
F_17 ( & V_31 ) ;
F_12 ( L_9 ) ;
return NULL ;
V_32:
F_22 ( & V_7 -> V_16 ) ;
F_17 ( & V_31 ) ;
F_12 ( L_2 , V_7 ) ;
return V_7 ;
}
void F_28 ( struct V_1 * V_7 )
{
F_2 ( L_10 , V_7 , F_20 ( & V_7 -> V_16 ) ) ;
F_29 ( F_20 ( & V_7 -> V_16 ) , > , 0 ) ;
V_7 -> V_37 = F_30 () ;
if ( F_31 ( F_32 ( & V_7 -> V_16 ) ) ) {
F_33 ( L_11 ) ;
F_34 ( & V_38 , 0 ) ;
}
F_12 ( L_1 ) ;
}
static void F_35 ( struct V_1 * V_7 )
{
F_25 ( L_12 , V_7 -> V_17 ) ;
F_36 ( & V_7 -> V_13 ) ;
F_37 ( V_7 -> V_3 ) ;
F_38 ( V_7 -> V_5 ) ;
F_26 ( V_7 ) ;
}
static void F_39 ( struct V_39 * V_40 )
{
struct V_1 * V_7 , * V_41 ;
unsigned long V_42 , V_43 , V_44 ;
F_40 ( V_45 ) ;
F_2 ( L_1 ) ;
V_42 = F_30 () ;
V_43 = V_46 ;
F_19 ( & V_31 ) ;
F_41 (trans, _p, &rxrpc_transports, link) {
F_33 ( L_13 ,
V_7 -> V_17 , F_20 ( & V_7 -> V_16 ) ,
( long ) V_42 - ( long ) V_7 -> V_37 ) ;
if ( F_42 ( F_20 ( & V_7 -> V_16 ) > 0 ) )
continue;
V_44 = V_7 -> V_37 + V_47 ;
if ( V_44 <= V_42 )
F_43 ( & V_7 -> V_8 , & V_45 ) ;
else if ( V_44 < V_43 )
V_43 = V_44 ;
}
F_24 ( & V_31 ) ;
if ( V_43 != V_46 ) {
F_33 ( L_14 , ( long ) V_43 - V_42 ) ;
F_29 ( V_43 , > , V_42 ) ;
F_34 ( & V_38 ,
( V_43 - V_42 ) * V_48 ) ;
}
while ( ! F_44 ( & V_45 ) ) {
V_7 = F_45 ( V_45 . V_49 , struct V_1 ,
V_8 ) ;
F_46 ( & V_7 -> V_8 ) ;
F_29 ( F_20 ( & V_7 -> V_16 ) , == , 0 ) ;
F_35 ( V_7 ) ;
}
F_12 ( L_1 ) ;
}
void T_2 F_47 ( void )
{
F_2 ( L_1 ) ;
V_47 = 0 ;
F_48 ( & V_38 ) ;
F_34 ( & V_38 , 0 ) ;
F_12 ( L_1 ) ;
}
