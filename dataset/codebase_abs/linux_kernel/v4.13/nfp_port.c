struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( F_2 ( V_3 ) ) {
struct V_4 * V_5 = F_3 ( V_3 ) ;
return V_5 -> V_6 ;
}
if ( F_4 ( V_3 ) ) {
struct V_7 * V_8 = F_3 ( V_3 ) ;
return V_8 -> V_6 ;
}
F_5 ( 1 , L_1 ) ;
return NULL ;
}
static int
F_6 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 )
return - V_11 ;
switch ( V_10 -> V_12 ) {
case V_13 : {
const T_1 * V_14 ;
V_10 -> V_15 . V_16 . V_17 = F_7 ( V_6 -> V_18 -> V_19 , & V_14 ) ;
memcpy ( & V_10 -> V_15 . V_16 . V_12 , V_14 , V_10 -> V_15 . V_16 . V_17 ) ;
break;
}
default:
return - V_11 ;
}
return 0 ;
}
int F_8 ( struct V_2 * V_3 , T_2 V_20 , T_2 V_21 ,
T_3 V_22 , struct V_23 * V_24 )
{
struct V_1 * V_6 ;
if ( V_21 )
return - V_11 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 )
return - V_11 ;
return F_9 ( V_6 -> V_18 , V_3 , V_20 , V_22 , V_24 ) ;
}
struct V_1 *
F_10 ( struct V_25 * V_26 , enum V_27 type , unsigned int V_12 )
{
struct V_1 * V_6 ;
F_11 ( & V_26 -> V_28 ) ;
if ( type != V_29 )
return NULL ;
F_12 (port, &pf->ports, port_list)
if ( V_6 -> V_30 == V_12 )
return V_6 ;
return NULL ;
}
struct V_31 * F_13 ( struct V_1 * V_6 )
{
if ( ! V_6 )
return NULL ;
if ( V_6 -> type != V_29 )
return NULL ;
return V_6 -> V_32 ;
}
struct V_31 * F_14 ( struct V_1 * V_6 )
{
if ( ! F_13 ( V_6 ) )
return NULL ;
if ( F_15 ( V_33 , & V_6 -> V_34 ) )
if ( F_16 ( V_6 ) )
return NULL ;
return F_13 ( V_6 ) ;
}
int
F_17 ( struct V_2 * V_3 , char * V_35 , T_4 V_36 )
{
struct V_31 * V_32 ;
struct V_1 * V_6 ;
int V_37 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 )
return - V_11 ;
switch ( V_6 -> type ) {
case V_29 :
V_32 = F_13 ( V_6 ) ;
if ( ! V_32 )
return - V_11 ;
if ( ! V_32 -> V_38 )
V_37 = snprintf ( V_35 , V_36 , L_2 , V_32 -> V_39 ) ;
else
V_37 = snprintf ( V_35 , V_36 , L_3 , V_32 -> V_39 ,
V_32 -> V_40 ) ;
break;
case V_41 :
V_37 = snprintf ( V_35 , V_36 , L_4 , V_6 -> V_42 ) ;
break;
case V_43 :
V_37 = snprintf ( V_35 , V_36 , L_5 , V_6 -> V_42 , V_6 -> V_44 ) ;
break;
default:
return - V_11 ;
}
if ( V_37 >= V_36 )
return - V_45 ;
return 0 ;
}
int F_18 ( struct V_25 * V_26 , struct V_46 * V_18 ,
struct V_1 * V_6 , unsigned int V_12 )
{
if ( ! V_26 -> V_47 || V_12 >= V_26 -> V_47 -> V_48 ) {
F_19 ( V_18 -> V_19 ,
L_6 ,
V_12 ) ;
return - V_45 ;
}
if ( V_26 -> V_47 -> V_49 [ V_12 ] . V_50 ) {
F_20 ( V_18 -> V_19 ,
L_7 ,
V_26 -> V_47 -> V_49 [ V_12 ] . V_51 ) ;
V_6 -> type = V_52 ;
return 0 ;
}
V_6 -> V_32 = & V_26 -> V_47 -> V_49 [ V_12 ] ;
V_6 -> V_30 = V_26 -> V_47 -> V_49 [ V_12 ] . V_51 ;
return 0 ;
}
struct V_1 *
F_21 ( struct V_46 * V_18 , enum V_27 type ,
struct V_2 * V_3 )
{
struct V_1 * V_6 ;
V_6 = F_22 ( sizeof( * V_6 ) , V_53 ) ;
if ( ! V_6 )
return F_23 ( - V_54 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> type = type ;
V_6 -> V_18 = V_18 ;
F_24 ( & V_6 -> V_55 , & V_18 -> V_26 -> V_49 ) ;
return V_6 ;
}
void F_25 ( struct V_1 * V_6 )
{
if ( ! V_6 )
return;
F_26 ( & V_6 -> V_55 ) ;
F_27 ( V_6 ) ;
}
