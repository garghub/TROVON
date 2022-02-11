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
F_12 ( V_4 ) ;
F_13 ( & V_4 -> V_14 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_15 * V_16 , * V_17 ;
struct V_18 * V_19 , * V_20 ;
F_16 ( V_21 ) ;
F_16 ( V_22 ) ;
F_17 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
F_18 ( & V_4 -> V_23 ) ;
F_19 (port, p, &adapter->port_list, list) {
F_20 ( & V_16 -> V_24 ) ;
F_19 (unit, u, &port->unit_list, list)
F_21 ( & V_19 -> V_25 , & V_21 ) ;
F_22 ( & V_16 -> V_24 ) ;
F_21 ( & V_16 -> V_25 , & V_22 ) ;
}
F_23 ( & V_4 -> V_23 ) ;
F_6 ( V_4 ) ;
F_19 (unit, u, &unit_remove_lh, list)
F_24 ( & V_19 -> V_7 ) ;
F_19 (port, p, &port_remove_lh, list)
F_24 ( & V_16 -> V_7 ) ;
F_25 ( V_4 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_4 = F_27 ( V_3 ) ;
if ( F_28 ( V_4 ) ) {
F_29 ( & V_3 -> V_7 ,
L_1
L_2 ) ;
return F_30 ( V_4 ) ;
}
F_4 ( & V_4 -> V_8 ) ;
}
F_31 ( ! F_32 ( V_4 -> V_26 ) ) ;
V_4 -> V_27 = 0 ;
F_8 ( V_3 , 0 , L_3 ) ;
F_33 ( V_4 ) ;
F_13 ( & V_4 -> V_14 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , int V_28 , char * V_11 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
F_10 ( V_4 , V_28 ) ;
F_35 ( V_4 , 0 , V_11 ) ;
F_12 ( V_4 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
return F_34 ( V_3 , 0 , L_4 ) ;
}
static int F_37 ( struct V_2 * V_3 , int V_29 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 1 ;
switch ( V_29 ) {
case V_30 :
if ( F_38 ( & V_4 -> V_31 ) &
V_32 ) {
F_39 ( L_5 , V_4 ) ;
break;
}
F_40 ( & V_3 -> V_7 , L_6 ) ;
F_35 ( V_4 , 0 , L_7 ) ;
break;
case V_33 :
F_40 ( & V_3 -> V_7 ,
L_8 ) ;
F_35 ( V_4 , 0 , L_9 ) ;
break;
case V_34 :
if ( F_38 ( & V_4 -> V_31 ) &
V_32 ) {
F_39 ( L_10 , V_4 ) ;
break;
}
F_41 ( & V_3 -> V_7 , L_11 ) ;
F_10 ( V_4 ,
V_12 ) ;
F_11 ( V_4 , V_13 ,
L_12 ) ;
break;
case V_35 :
F_40 ( & V_3 -> V_7 , L_13
L_14 ) ;
F_35 ( V_4 , 0 , L_15 ) ;
break;
}
F_6 ( V_4 ) ;
return 1 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
F_35 ( V_4 , 0 , L_16 ) ;
F_12 ( V_4 ) ;
F_43 ( V_4 ) ;
F_6 ( V_4 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
F_34 ( V_3 , V_32 , L_17 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
F_8 ( V_3 , 0 , L_18 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
F_8 ( V_3 , V_32 , L_19 ) ;
return 0 ;
}
