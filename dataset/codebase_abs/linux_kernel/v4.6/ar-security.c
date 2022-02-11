static struct V_1 * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ? V_2 : NULL ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static struct V_1 * F_5 ( T_1 V_4 )
{
struct V_1 * V_2 = NULL ;
F_6 ( L_1 ) ;
F_7 ( & V_5 ) ;
F_8 (sec, &rxrpc_security_methods, link) {
if ( V_2 -> V_4 == V_4 ) {
if ( F_9 ( ! F_1 ( V_2 ) ) )
break;
goto V_6;
}
}
V_2 = NULL ;
V_6:
F_10 ( & V_5 ) ;
F_11 ( L_2 , V_2 , V_2 ? V_2 -> V_7 : L_1 ) ;
return V_2 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_1 * V_8 ;
int V_9 ;
F_6 ( L_1 ) ;
F_13 ( & V_5 ) ;
V_9 = - V_10 ;
F_8 (psec, &rxrpc_security_methods, link) {
if ( V_8 -> V_4 == V_2 -> V_4 )
goto V_6;
}
F_14 ( & V_2 -> V_11 , & V_12 ) ;
F_15 ( V_13 L_3 ,
V_2 -> V_4 , V_2 -> V_7 ) ;
V_9 = 0 ;
V_6:
F_16 ( & V_5 ) ;
F_11 ( L_4 , V_9 ) ;
return V_9 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_6 ( L_1 ) ;
F_13 ( & V_5 ) ;
F_18 ( & V_2 -> V_11 ) ;
F_16 ( & V_5 ) ;
F_15 ( V_13 L_5 ,
V_2 -> V_4 , V_2 -> V_7 ) ;
}
int F_19 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_18 * V_18 = V_15 -> V_18 ;
int V_9 ;
F_6 ( L_6 , V_15 -> V_19 , F_20 ( V_18 ) ) ;
if ( ! V_18 )
return 0 ;
V_9 = F_21 ( V_18 ) ;
if ( V_9 < 0 )
return V_9 ;
V_17 = V_18 -> V_20 . V_21 [ 0 ] ;
if ( ! V_17 )
return - V_22 ;
V_2 = F_5 ( V_17 -> V_4 ) ;
if ( ! V_2 )
return - V_22 ;
V_15 -> V_23 = V_2 ;
V_9 = V_15 -> V_23 -> V_24 ( V_15 ) ;
if ( V_9 < 0 ) {
F_3 ( V_15 -> V_23 ) ;
V_15 -> V_23 = NULL ;
return V_9 ;
}
F_11 ( L_7 ) ;
return 0 ;
}
int F_22 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 = V_15 -> V_27 -> V_26 ;
struct V_28 * V_29 ;
struct V_18 * V_18 ;
T_2 V_30 ;
char V_31 [ 5 + 1 + 3 + 1 ] ;
F_6 ( L_1 ) ;
sprintf ( V_31 , L_8 , V_15 -> V_32 , V_15 -> V_33 ) ;
V_2 = F_5 ( V_15 -> V_33 ) ;
if ( ! V_2 ) {
F_11 ( L_9 ) ;
return - V_34 ;
}
F_23 ( & V_26 -> V_35 ) ;
F_8 (rx, &local->services, listen_link) {
if ( V_29 -> V_36 . V_37 == V_15 -> V_32 )
goto V_38;
}
F_24 ( & V_26 -> V_35 ) ;
F_3 ( V_2 ) ;
F_11 ( L_10 ) ;
return - V_39 ;
V_38:
if ( ! V_29 -> V_40 ) {
F_24 ( & V_26 -> V_35 ) ;
F_3 ( V_2 ) ;
F_11 ( L_11 ) ;
return - V_34 ;
}
V_30 = F_25 ( F_26 ( V_29 -> V_40 , 1UL ) ,
& V_41 , V_31 ) ;
if ( F_27 ( V_30 ) ) {
F_24 ( & V_26 -> V_35 ) ;
F_3 ( V_2 ) ;
F_11 ( L_12 , F_28 ( V_30 ) ) ;
return F_28 ( V_30 ) ;
}
V_18 = F_29 ( V_30 ) ;
F_24 ( & V_26 -> V_35 ) ;
V_15 -> V_42 = V_18 ;
V_15 -> V_23 = V_2 ;
F_11 ( L_7 ) ;
return 0 ;
}
int F_30 ( const struct V_43 * V_44 ,
struct V_45 * V_46 ,
T_3 V_47 ,
void * V_48 )
{
if ( V_44 -> V_15 -> V_23 )
return V_44 -> V_15 -> V_23 -> V_49 (
V_44 , V_46 , V_47 , V_48 ) ;
return 0 ;
}
int F_31 ( const struct V_43 * V_44 , struct V_45 * V_46 ,
T_4 * V_50 )
{
if ( V_44 -> V_15 -> V_23 )
return V_44 -> V_15 -> V_23 -> V_51 (
V_44 , V_46 , V_50 ) ;
return 0 ;
}
void F_32 ( struct V_14 * V_15 )
{
F_6 ( L_13 , V_15 -> V_19 ) ;
if ( V_15 -> V_23 ) {
V_15 -> V_23 -> V_52 ( V_15 ) ;
F_3 ( V_15 -> V_23 ) ;
V_15 -> V_23 = NULL ;
}
F_33 ( V_15 -> V_18 ) ;
F_33 ( V_15 -> V_42 ) ;
}
