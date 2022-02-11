void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
unsigned int V_6 ;
V_6 = F_2 ( (struct V_7 * ) & V_2 -> V_8 ) ;
if ( V_4 && V_4 -> V_9 == V_10 )
F_3 ( & V_4 -> V_11 , 0 , V_4 -> V_12 , V_6 , 1 ) ;
}
static void F_4 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 , struct V_1 ,
V_15 ) ;
F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_11 ) ;
}
void F_7 ( struct V_16 * V_5 )
{
struct V_1 * V_2 ;
F_8 ( & V_5 -> V_17 ) ;
F_9 (unit, &port->unit_list, list) {
F_10 ( & V_2 -> V_11 ) ;
if ( F_11 ( V_5 -> V_18 -> V_19 ,
& V_2 -> V_15 ) <= 0 )
F_6 ( & V_2 -> V_11 ) ;
}
F_12 ( & V_5 -> V_17 ) ;
}
static struct V_1 * F_13 ( struct V_16 * V_5 , T_1 V_8 )
{
struct V_1 * V_2 ;
F_9 (unit, &port->unit_list, list)
if ( V_2 -> V_8 == V_8 ) {
F_10 ( & V_2 -> V_11 ) ;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_14 ( struct V_16 * V_5 , T_1 V_8 )
{
struct V_1 * V_2 ;
F_8 ( & V_5 -> V_17 ) ;
V_2 = F_13 ( V_5 , V_8 ) ;
F_12 ( & V_5 -> V_17 ) ;
return V_2 ;
}
static void F_15 ( struct V_20 * V_11 )
{
struct V_1 * V_2 = F_5 ( V_11 , struct V_1 , V_11 ) ;
F_16 ( & V_2 -> V_5 -> V_21 ) ;
F_17 ( V_2 ) ;
}
int F_18 ( struct V_16 * V_5 , T_1 V_8 )
{
struct V_1 * V_2 ;
int V_22 = 0 ;
F_19 ( & V_23 ) ;
if ( F_20 ( & V_5 -> V_21 ) == - 1 ) {
V_22 = - V_24 ;
goto V_25;
}
V_2 = F_14 ( V_5 , V_8 ) ;
if ( V_2 ) {
F_6 ( & V_2 -> V_11 ) ;
V_22 = - V_26 ;
goto V_25;
}
V_2 = F_21 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_2 ) {
V_22 = - V_28 ;
goto V_25;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_11 . V_29 = & V_5 -> V_11 ;
V_2 -> V_11 . V_30 = F_15 ;
F_22 ( & V_2 -> V_15 , F_4 ) ;
if ( F_23 ( & V_2 -> V_11 , L_1 ,
( unsigned long long ) V_8 ) ) {
F_17 ( V_2 ) ;
V_22 = - V_28 ;
goto V_25;
}
if ( F_24 ( & V_2 -> V_11 ) ) {
F_6 ( & V_2 -> V_11 ) ;
V_22 = - V_28 ;
goto V_25;
}
if ( F_25 ( & V_2 -> V_11 . V_31 , & V_32 ) ) {
F_26 ( & V_2 -> V_11 ) ;
V_22 = - V_33 ;
goto V_25;
}
F_27 ( & V_5 -> V_21 ) ;
F_28 ( & V_5 -> V_17 ) ;
F_29 ( & V_2 -> V_34 , & V_5 -> V_35 ) ;
F_30 ( & V_5 -> V_17 ) ;
F_1 ( V_2 ) ;
V_25:
F_31 ( & V_23 ) ;
return V_22 ;
}
struct V_36 * F_32 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
struct V_16 * V_5 ;
unsigned int V_6 ;
V_6 = F_2 ( (struct V_7 * ) & V_2 -> V_8 ) ;
V_5 = V_2 -> V_5 ;
V_38 = V_5 -> V_18 -> V_19 ;
return F_33 ( V_38 , 0 , V_5 -> V_39 , V_6 ) ;
}
unsigned int F_34 ( struct V_1 * V_2 )
{
unsigned int V_40 = 0 ;
struct V_36 * V_41 ;
struct V_42 * V_43 ;
V_41 = F_32 ( V_2 ) ;
if ( V_41 ) {
V_43 = F_35 ( V_41 ) ;
V_40 = F_20 ( & V_43 -> V_40 ) ;
F_36 ( V_41 ) ;
}
return V_40 ;
}
int F_37 ( struct V_16 * V_5 , T_1 V_8 )
{
struct V_1 * V_2 ;
struct V_36 * V_41 ;
F_28 ( & V_5 -> V_17 ) ;
V_2 = F_13 ( V_5 , V_8 ) ;
if ( V_2 )
F_38 ( & V_2 -> V_34 ) ;
F_30 ( & V_5 -> V_17 ) ;
if ( ! V_2 )
return - V_33 ;
V_41 = F_32 ( V_2 ) ;
if ( V_41 ) {
F_39 ( V_41 ) ;
F_36 ( V_41 ) ;
}
F_6 ( & V_2 -> V_11 ) ;
F_40 ( & V_2 -> V_11 , & V_32 ) ;
return 0 ;
}
