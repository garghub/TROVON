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
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
F_9 ( V_4 , V_10 ) ;
F_10 ( V_4 , V_11 ,
L_1 ) ;
F_11 ( V_4 ) ;
F_12 ( & V_4 -> V_12 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_4 )
{
return V_4 -> V_2 -> V_13 . V_14 == V_15 ;
}
static int F_14 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_16 * V_17 , * V_18 ;
struct V_19 * V_20 , * V_21 ;
F_16 ( V_22 ) ;
F_16 ( V_23 ) ;
F_17 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
F_18 ( & V_4 -> V_24 ) ;
F_19 (port, p, &adapter->port_list, list) {
F_20 ( & V_17 -> V_25 ) ;
F_19 (unit, u, &port->unit_list, list)
F_21 ( & V_20 -> V_26 , & V_22 ) ;
F_22 ( & V_17 -> V_25 ) ;
F_21 ( & V_17 -> V_26 , & V_23 ) ;
}
F_23 ( & V_4 -> V_24 ) ;
F_6 ( V_4 ) ;
F_19 (unit, u, &unit_remove_lh, list)
F_24 ( & V_20 -> V_7 , & V_27 ) ;
F_19 (port, p, &port_remove_lh, list)
F_24 ( & V_17 -> V_7 , & V_28 ) ;
F_25 ( V_4 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_4 = F_27 ( V_3 ) ;
if ( F_28 ( V_4 ) ) {
F_29 ( & V_3 -> V_7 ,
L_2
L_3 ) ;
return F_30 ( V_4 ) ;
}
F_4 ( & V_4 -> V_8 ) ;
}
F_31 ( ! F_32 ( V_4 -> V_29 ) ) ;
V_4 -> V_30 = 0 ;
F_8 ( V_3 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
F_34 ( V_4 , 0 , L_4 ) ;
F_11 ( V_4 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , int V_31 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 1 ;
switch ( V_31 ) {
case V_32 :
F_36 ( & V_3 -> V_7 , L_5 ) ;
F_34 ( V_4 , 0 , L_6 ) ;
break;
case V_33 :
F_36 ( & V_3 -> V_7 ,
L_7 ) ;
F_34 ( V_4 , 0 , L_8 ) ;
break;
case V_34 :
F_37 ( & V_3 -> V_7 , L_9 ) ;
F_9 ( V_4 ,
V_10 ) ;
F_10 ( V_4 , V_11 ,
L_10 ) ;
break;
case V_35 :
F_36 ( & V_3 -> V_7 , L_11
L_12 ) ;
F_34 ( V_4 , 0 , L_13 ) ;
break;
}
F_6 ( V_4 ) ;
return 1 ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
F_34 ( V_4 , 0 , L_14 ) ;
F_11 ( V_4 ) ;
F_39 ( V_4 ) ;
F_6 ( V_4 ) ;
}
