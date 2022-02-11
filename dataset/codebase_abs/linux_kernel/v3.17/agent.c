static struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
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
F_3 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
unsigned long V_7 ;
F_4 ( & V_8 , V_7 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
F_5 ( & V_8 , V_7 ) ;
return V_5 ;
}
void F_6 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_13 * V_14 , struct V_2 * V_3 ,
int V_4 , int V_15 )
{
struct V_1 * V_16 ;
struct V_17 * V_6 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
if ( V_3 -> V_24 == V_25 )
V_16 = F_3 ( V_3 , 0 ) ;
else
V_16 = F_3 ( V_3 , V_4 ) ;
if ( ! V_16 ) {
F_7 ( & V_3 -> V_26 , L_1 ) ;
return;
}
V_6 = V_16 -> V_6 [ V_15 ] ;
V_21 = F_8 ( V_6 -> V_27 -> V_28 , V_14 , V_12 , V_4 ) ;
if ( F_9 ( V_21 ) ) {
F_7 ( & V_3 -> V_26 , L_2 ,
F_10 ( V_21 ) ) ;
return;
}
V_19 = F_11 ( V_6 , V_14 -> V_29 , V_14 -> V_30 , 0 ,
V_31 , V_32 ,
V_33 ) ;
if ( F_9 ( V_19 ) ) {
F_7 ( & V_3 -> V_26 , L_3 ) ;
goto V_34;
}
memcpy ( V_19 -> V_10 , V_10 , sizeof *V_10 ) ;
V_19 -> V_21 = V_21 ;
if ( V_3 -> V_24 == V_25 ) {
V_23 = F_12 ( V_19 ,
struct V_22 ,
V_19 ) ;
V_23 -> V_35 . V_36 . V_37 . V_4 = V_4 ;
}
if ( F_13 ( V_19 , NULL ) ) {
F_7 ( & V_3 -> V_26 , L_4 ) ;
goto V_38;
}
return;
V_38:
F_14 ( V_19 ) ;
V_34:
F_15 ( V_21 ) ;
}
static void F_16 ( struct V_17 * V_39 ,
struct V_40 * V_41 )
{
F_15 ( V_41 -> V_19 -> V_21 ) ;
F_14 ( V_41 -> V_19 ) ;
}
int F_17 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_16 ;
unsigned long V_7 ;
int V_42 ;
V_16 = F_18 ( sizeof *V_16 , V_33 ) ;
if ( ! V_16 ) {
F_7 ( & V_3 -> V_26 , L_5 ) ;
V_42 = - V_43 ;
goto V_44;
}
if ( F_19 ( V_3 , V_4 ) == V_45 ) {
V_16 -> V_6 [ 0 ] = F_20 ( V_3 , V_4 ,
V_46 , NULL , 0 ,
& F_16 ,
NULL , NULL , 0 ) ;
if ( F_9 ( V_16 -> V_6 [ 0 ] ) ) {
V_42 = F_10 ( V_16 -> V_6 [ 0 ] ) ;
goto V_47;
}
}
V_16 -> V_6 [ 1 ] = F_20 ( V_3 , V_4 ,
V_48 , NULL , 0 ,
& F_16 ,
NULL , NULL , 0 ) ;
if ( F_9 ( V_16 -> V_6 [ 1 ] ) ) {
V_42 = F_10 ( V_16 -> V_6 [ 1 ] ) ;
goto V_49;
}
F_4 ( & V_8 , V_7 ) ;
F_21 ( & V_16 -> V_50 , & V_51 ) ;
F_5 ( & V_8 , V_7 ) ;
return 0 ;
V_49:
if ( V_16 -> V_6 [ 0 ] )
F_22 ( V_16 -> V_6 [ 0 ] ) ;
V_47:
F_23 ( V_16 ) ;
V_44:
return V_42 ;
}
int F_24 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_16 ;
unsigned long V_7 ;
F_4 ( & V_8 , V_7 ) ;
V_16 = F_1 ( V_3 , V_4 ) ;
if ( V_16 == NULL ) {
F_5 ( & V_8 , V_7 ) ;
F_7 ( & V_3 -> V_26 , L_6 , V_4 ) ;
return - V_52 ;
}
F_25 ( & V_16 -> V_50 ) ;
F_5 ( & V_8 , V_7 ) ;
F_22 ( V_16 -> V_6 [ 1 ] ) ;
if ( V_16 -> V_6 [ 0 ] )
F_22 ( V_16 -> V_6 [ 0 ] ) ;
F_23 ( V_16 ) ;
return 0 ;
}
