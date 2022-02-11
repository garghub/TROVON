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
int F_14 ( struct V_1 * V_4 )
{
return V_4 -> V_2 -> V_15 . V_16 == V_17 ;
}
static int F_15 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_18 * V_19 , * V_20 ;
struct V_21 * V_22 , * V_23 ;
F_17 ( V_24 ) ;
F_17 ( V_25 ) ;
F_18 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
F_19 ( & V_4 -> V_26 ) ;
F_20 (port, p, &adapter->port_list, list) {
F_21 ( & V_19 -> V_27 ) ;
F_20 (unit, u, &port->unit_list, list)
F_22 ( & V_22 -> V_28 , & V_24 ) ;
F_23 ( & V_19 -> V_27 ) ;
F_22 ( & V_19 -> V_28 , & V_25 ) ;
}
F_24 ( & V_4 -> V_26 ) ;
F_6 ( V_4 ) ;
F_20 (unit, u, &unit_remove_lh, list)
F_25 ( & V_22 -> V_7 , & V_29 ) ;
F_20 (port, p, &port_remove_lh, list)
F_25 ( & V_19 -> V_7 , & V_30 ) ;
F_26 ( V_4 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_4 = F_28 ( V_3 ) ;
if ( F_29 ( V_4 ) ) {
F_30 ( & V_3 -> V_7 ,
L_1
L_2 ) ;
return F_31 ( V_4 ) ;
}
F_4 ( & V_4 -> V_8 ) ;
}
F_32 ( ! F_33 ( V_4 -> V_31 ) ) ;
V_4 -> V_32 = 0 ;
F_8 ( V_3 , 0 , L_3 ) ;
F_34 ( V_4 ) ;
F_13 ( & V_4 -> V_14 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , int V_33 , char * V_11 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
F_10 ( V_4 , V_33 ) ;
F_36 ( V_4 , 0 , V_11 ) ;
F_12 ( V_4 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 )
{
return F_35 ( V_3 , 0 , L_4 ) ;
}
static int F_38 ( struct V_2 * V_3 , int V_34 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 1 ;
switch ( V_34 ) {
case V_35 :
if ( F_39 ( & V_4 -> V_36 ) &
V_37 ) {
F_40 ( L_5 , V_4 ) ;
break;
}
F_41 ( & V_3 -> V_7 , L_6 ) ;
F_36 ( V_4 , 0 , L_7 ) ;
break;
case V_38 :
F_41 ( & V_3 -> V_7 ,
L_8 ) ;
F_36 ( V_4 , 0 , L_9 ) ;
break;
case V_39 :
if ( F_39 ( & V_4 -> V_36 ) &
V_37 ) {
F_40 ( L_10 , V_4 ) ;
break;
}
F_42 ( & V_3 -> V_7 , L_11 ) ;
F_10 ( V_4 ,
V_12 ) ;
F_11 ( V_4 , V_13 ,
L_12 ) ;
break;
case V_40 :
F_41 ( & V_3 -> V_7 , L_13
L_14 ) ;
F_36 ( V_4 , 0 , L_15 ) ;
break;
}
F_6 ( V_4 ) ;
return 1 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
F_36 ( V_4 , 0 , L_16 ) ;
F_12 ( V_4 ) ;
F_44 ( V_4 ) ;
F_6 ( V_4 ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
F_35 ( V_3 , V_37 , L_17 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
F_8 ( V_3 , 0 , L_18 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
F_8 ( V_3 , V_37 , L_19 ) ;
return 0 ;
}
