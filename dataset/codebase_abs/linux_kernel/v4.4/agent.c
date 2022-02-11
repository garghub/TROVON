static struct V_1 *
F_1 ( const struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 (entry, &ib_agent_port_list, port_list) {
if ( V_5 -> V_6 [ 1 ] -> V_3 == V_3 &&
V_5 -> V_6 [ 1 ] -> V_4 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_1 *
F_3 ( const struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
unsigned long V_7 ;
F_4 ( & V_8 , V_7 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
F_5 ( & V_8 , V_7 ) ;
return V_5 ;
}
void F_6 ( const struct V_9 * V_10 , const struct V_11 * V_12 ,
const struct V_13 * V_14 , const struct V_2 * V_3 ,
int V_4 , int V_15 , T_1 V_16 , bool V_17 )
{
struct V_1 * V_18 ;
struct V_19 * V_6 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
if ( F_7 ( V_3 ) )
V_18 = F_3 ( V_3 , 0 ) ;
else
V_18 = F_3 ( V_3 , V_4 ) ;
if ( ! V_18 ) {
F_8 ( & V_3 -> V_26 , L_1 ) ;
return;
}
V_6 = V_18 -> V_6 [ V_15 ] ;
V_23 = F_9 ( V_6 -> V_27 -> V_28 , V_14 , V_12 , V_4 ) ;
if ( F_10 ( V_23 ) ) {
F_8 ( & V_3 -> V_26 , L_2 ,
F_11 ( V_23 ) ) ;
return;
}
if ( V_17 && V_10 -> V_29 != V_30 )
V_16 = V_31 ;
V_21 = F_12 ( V_6 , V_14 -> V_32 , V_14 -> V_33 , 0 ,
V_34 ,
V_16 - V_34 ,
V_35 ,
V_10 -> V_29 ) ;
if ( F_10 ( V_21 ) ) {
F_8 ( & V_3 -> V_26 , L_3 ) ;
goto V_36;
}
memcpy ( V_21 -> V_37 , V_10 , V_16 ) ;
V_21 -> V_23 = V_23 ;
if ( F_7 ( V_3 ) ) {
V_25 = F_13 ( V_21 ,
struct V_24 ,
V_21 ) ;
V_25 -> V_38 . V_4 = V_4 ;
}
if ( F_14 ( V_21 , NULL ) ) {
F_8 ( & V_3 -> V_26 , L_4 ) ;
goto V_39;
}
return;
V_39:
F_15 ( V_21 ) ;
V_36:
F_16 ( V_23 ) ;
}
static void F_17 ( struct V_19 * V_40 ,
struct V_41 * V_42 )
{
F_16 ( V_42 -> V_21 -> V_23 ) ;
F_15 ( V_42 -> V_21 ) ;
}
int F_18 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_18 ;
unsigned long V_7 ;
int V_43 ;
V_18 = F_19 ( sizeof *V_18 , V_35 ) ;
if ( ! V_18 ) {
F_8 ( & V_3 -> V_26 , L_5 ) ;
V_43 = - V_44 ;
goto V_45;
}
if ( F_20 ( V_3 , V_4 ) ) {
V_18 -> V_6 [ 0 ] = F_21 ( V_3 , V_4 ,
V_46 , NULL , 0 ,
& F_17 ,
NULL , NULL , 0 ) ;
if ( F_10 ( V_18 -> V_6 [ 0 ] ) ) {
V_43 = F_11 ( V_18 -> V_6 [ 0 ] ) ;
goto V_47;
}
}
V_18 -> V_6 [ 1 ] = F_21 ( V_3 , V_4 ,
V_48 , NULL , 0 ,
& F_17 ,
NULL , NULL , 0 ) ;
if ( F_10 ( V_18 -> V_6 [ 1 ] ) ) {
V_43 = F_11 ( V_18 -> V_6 [ 1 ] ) ;
goto V_49;
}
F_4 ( & V_8 , V_7 ) ;
F_22 ( & V_18 -> V_50 , & V_51 ) ;
F_5 ( & V_8 , V_7 ) ;
return 0 ;
V_49:
if ( V_18 -> V_6 [ 0 ] )
F_23 ( V_18 -> V_6 [ 0 ] ) ;
V_47:
F_24 ( V_18 ) ;
V_45:
return V_43 ;
}
int F_25 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_18 ;
unsigned long V_7 ;
F_4 ( & V_8 , V_7 ) ;
V_18 = F_1 ( V_3 , V_4 ) ;
if ( V_18 == NULL ) {
F_5 ( & V_8 , V_7 ) ;
F_8 ( & V_3 -> V_26 , L_6 , V_4 ) ;
return - V_52 ;
}
F_26 ( & V_18 -> V_50 ) ;
F_5 ( & V_8 , V_7 ) ;
F_23 ( V_18 -> V_6 [ 1 ] ) ;
if ( V_18 -> V_6 [ 0 ] )
F_23 ( V_18 -> V_6 [ 0 ] ) ;
F_24 ( V_18 ) ;
return 0 ;
}
