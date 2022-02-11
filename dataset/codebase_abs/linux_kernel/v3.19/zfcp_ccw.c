struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
V_4 = F_3 ( & V_3 -> V_7 ) ;
if ( V_4 )
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_6 , V_5 ) ;
return V_4 ;
}
void F_6 ( struct V_1 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
F_7 ( & V_4 -> V_8 , V_9 ) ;
F_5 ( & V_6 , V_5 ) ;
}
static int F_8 ( struct V_2 * V_3 , int V_10 , char * V_11 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
F_9 ( V_4 , V_10 ) ;
F_10 ( V_4 , V_12 ) ;
F_11 ( V_4 , V_13 ,
V_11 ) ;
F_12 ( F_13 () ) ;
F_14 ( V_4 ) ;
F_15 ( & V_4 -> V_14 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_15 * V_16 , * V_17 ;
struct V_18 * V_19 , * V_20 ;
F_18 ( V_21 ) ;
F_18 ( V_22 ) ;
F_19 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
F_20 ( & V_4 -> V_23 ) ;
F_21 (port, p, &adapter->port_list, list) {
F_22 ( & V_16 -> V_24 ) ;
F_21 (unit, u, &port->unit_list, list)
F_23 ( & V_19 -> V_25 , & V_21 ) ;
F_24 ( & V_16 -> V_24 ) ;
F_23 ( & V_16 -> V_25 , & V_22 ) ;
}
F_25 ( & V_4 -> V_23 ) ;
F_6 ( V_4 ) ;
F_21 (unit, u, &unit_remove_lh, list)
F_26 ( & V_19 -> V_7 ) ;
F_21 (port, p, &port_remove_lh, list)
F_26 ( & V_16 -> V_7 ) ;
F_27 ( V_4 ) ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_4 = F_29 ( V_3 ) ;
if ( F_30 ( V_4 ) ) {
F_31 ( & V_3 -> V_7 ,
L_1
L_2 ) ;
return F_32 ( V_4 ) ;
}
F_4 ( & V_4 -> V_8 ) ;
}
F_33 ( ! F_34 ( V_4 -> V_26 ) ) ;
V_4 -> V_27 = 0 ;
F_8 ( V_3 , 0 , L_3 ) ;
F_35 ( V_4 ) ;
F_15 ( & V_4 -> V_14 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , int V_28 , char * V_11 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
F_10 ( V_4 , V_28 ) ;
F_37 ( V_4 , 0 , V_11 ) ;
F_14 ( V_4 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
return F_36 ( V_3 , 0 , L_4 ) ;
}
static int F_39 ( struct V_2 * V_3 , int V_29 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 1 ;
switch ( V_29 ) {
case V_30 :
if ( F_40 ( & V_4 -> V_31 ) &
V_32 ) {
F_41 ( L_5 , V_4 ) ;
break;
}
F_42 ( & V_3 -> V_7 , L_6 ) ;
F_37 ( V_4 , 0 , L_7 ) ;
break;
case V_33 :
F_42 ( & V_3 -> V_7 ,
L_8 ) ;
F_37 ( V_4 , 0 , L_9 ) ;
break;
case V_34 :
if ( F_40 ( & V_4 -> V_31 ) &
V_32 ) {
F_41 ( L_10 , V_4 ) ;
break;
}
F_43 ( & V_3 -> V_7 , L_11 ) ;
F_10 ( V_4 ,
V_12 ) ;
F_11 ( V_4 , V_13 ,
L_12 ) ;
break;
case V_35 :
F_42 ( & V_3 -> V_7 , L_13
L_14 ) ;
F_37 ( V_4 , 0 , L_15 ) ;
break;
}
F_6 ( V_4 ) ;
return 1 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
F_37 ( V_4 , 0 , L_16 ) ;
F_14 ( V_4 ) ;
F_45 ( V_4 ) ;
F_6 ( V_4 ) ;
}
static int F_46 ( struct V_2 * V_3 )
{
F_36 ( V_3 , V_32 , L_17 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
F_8 ( V_3 , 0 , L_18 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
F_8 ( V_3 , V_32 , L_19 ) ;
return 0 ;
}
