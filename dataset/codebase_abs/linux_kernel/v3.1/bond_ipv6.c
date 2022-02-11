static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( ! V_2 )
return;
V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return;
F_3 ( & V_6 -> V_7 ) ;
if ( ! F_4 ( & V_6 -> V_8 ) ) {
struct V_9 * V_10
= F_5 ( & V_6 -> V_8 ,
struct V_9 , V_11 ) ;
F_6 ( V_4 , & V_10 -> V_4 ) ;
} else
F_7 ( V_4 , 0 , 0 , 0 , 0 ) ;
F_8 ( & V_6 -> V_7 ) ;
F_9 ( V_6 ) ;
}
static void F_10 ( struct V_1 * V_12 ,
struct V_3 * V_13 ,
int V_14 ,
unsigned short V_15 )
{
struct V_3 V_16 ;
struct V_17 V_18 = {
. V_19 = V_20 ,
} ;
struct V_21 * V_22 ;
V_18 . V_23 = V_14 ;
V_18 . V_24 = 0 ;
V_18 . V_25 = 1 ;
F_11 ( V_13 , & V_16 ) ;
F_12 ( L_1 ,
V_12 -> V_26 , & V_16 , V_13 ) ;
V_22 = F_13 ( V_12 , & V_16 , V_13 , & V_18 , V_13 ,
V_27 ) ;
if ( ! V_22 ) {
F_14 ( L_2 ) ;
return;
}
if ( V_15 ) {
V_22 = F_15 ( V_22 , V_15 ) ;
if ( ! V_22 ) {
F_14 ( L_3 ) ;
return;
}
}
F_16 ( V_22 , V_12 , NULL , & V_16 , V_13 , & V_18 ) ;
}
void F_17 ( struct V_28 * V_29 )
{
struct V_30 * V_30 = V_29 -> V_31 ;
struct V_32 * V_33 ;
struct V_5 * V_6 ;
int V_34 ;
F_12 ( L_4 , V_29 -> V_2 -> V_26 ,
V_35 , V_30 ? V_30 -> V_2 -> V_26 : L_5 ) ;
if ( ! V_30 || ! V_29 -> V_36 ||
F_18 ( V_37 , & V_30 -> V_2 -> V_38 ) )
return;
V_29 -> V_36 -- ;
V_6 = F_2 ( V_29 -> V_2 ) ;
if ( ! V_6 )
return;
V_34 = ! ! V_6 -> V_39 . V_40 ;
F_9 ( V_6 ) ;
if ( ! F_19 ( & V_29 -> V_41 ) )
F_10 ( V_30 -> V_2 , & V_29 -> V_41 , V_34 , 0 ) ;
F_20 (vlan, &bond->vlan_list, vlan_list) {
if ( ! F_19 ( & V_33 -> V_42 ) ) {
F_10 ( V_30 -> V_2 , & V_33 -> V_42 , V_34 ,
V_33 -> V_15 ) ;
}
}
}
static int F_21 ( struct V_43 * V_44 ,
unsigned long V_45 ,
void * V_46 )
{
struct V_9 * V_10 = V_46 ;
struct V_1 * V_47 , * V_48 = V_10 -> V_6 -> V_2 ;
struct V_28 * V_29 ;
struct V_32 * V_33 ;
struct V_49 * V_50 = F_22 ( F_23 ( V_48 ) , V_51 ) ;
F_20 (bond, &bn->dev_list, bond_list) {
if ( V_29 -> V_2 == V_48 ) {
switch ( V_45 ) {
case V_52 :
if ( F_19 ( & V_29 -> V_41 ) )
F_6 ( & V_29 -> V_41 ,
& V_10 -> V_4 ) ;
return V_53 ;
case V_54 :
if ( F_24 ( & V_29 -> V_41 ,
& V_10 -> V_4 ) )
F_1 ( V_29 -> V_2 ,
& V_29 -> V_41 ) ;
return V_53 ;
default:
return V_55 ;
}
}
F_20 (vlan, &bond->vlan_list, vlan_list) {
F_25 () ;
V_47 = F_26 ( V_29 -> V_2 ,
V_33 -> V_15 ) ;
F_27 () ;
if ( V_47 == V_48 ) {
switch ( V_45 ) {
case V_52 :
if ( F_19 ( & V_33 -> V_42 ) )
F_6 ( & V_33 -> V_42 ,
& V_10 -> V_4 ) ;
return V_53 ;
case V_54 :
if ( F_24 ( & V_33 -> V_42 ,
& V_10 -> V_4 ) )
F_1 ( V_47 ,
& V_33 -> V_42 ) ;
return V_53 ;
default:
return V_55 ;
}
}
}
}
return V_55 ;
}
void F_28 ( void )
{
F_29 ( & V_56 ) ;
}
void F_30 ( void )
{
F_31 ( & V_56 ) ;
}
