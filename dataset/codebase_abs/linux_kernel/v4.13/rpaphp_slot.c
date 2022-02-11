static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) V_1 -> V_3 ;
F_2 ( V_2 ) ;
}
void F_2 ( struct V_2 * V_2 )
{
F_3 ( V_2 -> V_1 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_1 ) ;
F_3 ( V_2 ) ;
}
struct V_2 * F_4 ( struct V_6 * V_7 ,
int V_8 , char * V_9 , int V_10 )
{
struct V_2 * V_2 ;
V_2 = F_5 ( sizeof( struct V_2 ) , V_11 ) ;
if ( ! V_2 )
goto V_12;
V_2 -> V_1 = F_5 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_2 -> V_1 )
goto V_13;
V_2 -> V_1 -> V_4 = F_5 ( sizeof( struct V_14 ) ,
V_11 ) ;
if ( ! V_2 -> V_1 -> V_4 )
goto V_15;
V_2 -> V_5 = F_6 ( V_9 , V_11 ) ;
if ( ! V_2 -> V_5 )
goto V_16;
V_2 -> V_7 = V_7 ;
V_2 -> V_17 = V_8 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_1 -> V_3 = V_2 ;
V_2 -> V_1 -> V_18 = & V_19 ;
V_2 -> V_1 -> V_20 = & F_1 ;
return ( V_2 ) ;
V_16:
F_3 ( V_2 -> V_1 -> V_4 ) ;
V_15:
F_3 ( V_2 -> V_1 ) ;
V_13:
F_3 ( V_2 ) ;
V_12:
return NULL ;
}
static int F_7 ( struct V_2 * V_2 )
{
struct V_2 * V_21 ;
F_8 (tmp_slot, &rpaphp_slot_head, rpaphp_slot_list) {
if ( ! strcmp ( V_21 -> V_5 , V_2 -> V_5 ) )
return 1 ;
}
return 0 ;
}
int F_9 ( struct V_2 * V_2 )
{
int V_22 = 0 ;
struct V_1 * V_23 = V_2 -> V_1 ;
F_10 ( L_1 ,
V_24 , V_2 -> V_5 ) ;
F_11 ( & V_2 -> V_25 ) ;
V_22 = F_12 ( V_23 ) ;
if ( V_22 )
F_13 ( L_2 , V_2 -> V_5 ) ;
F_10 ( L_3 , V_24 , V_22 ) ;
return V_22 ;
}
int F_14 ( struct V_2 * V_2 )
{
struct V_1 * V_23 = V_2 -> V_1 ;
struct V_6 * V_26 ;
T_1 V_27 ;
int V_22 ;
int V_28 = - 1 ;
F_10 ( L_4 ,
V_24 , V_2 -> V_7 -> V_29 , V_2 -> V_17 , V_2 -> V_5 ,
V_2 -> V_10 , V_2 -> type ) ;
if ( F_7 ( V_2 ) ) {
F_13 ( L_5 , V_2 -> V_5 ) ;
return - V_30 ;
}
F_15 (slot->dn, child) {
V_22 = F_16 ( V_26 , L_6 , & V_27 ) ;
if ( V_27 == V_2 -> V_17 ) {
V_28 = F_17 ( F_18 ( V_26 ) -> V_31 ) ;
F_19 ( V_26 ) ;
break;
}
}
V_22 = F_20 ( V_23 , V_2 -> V_32 , V_28 , V_2 -> V_5 ) ;
if ( V_22 ) {
F_13 ( L_7 , V_22 ) ;
return V_22 ;
}
F_21 ( & V_2 -> V_25 , & V_33 ) ;
V_4 ( L_8 , V_2 -> V_5 ) ;
return 0 ;
}
