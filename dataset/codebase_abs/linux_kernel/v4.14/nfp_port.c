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
int F_8 ( struct V_2 * V_3 , enum V_20 type ,
void * V_21 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 )
return - V_11 ;
return F_9 ( V_6 -> V_18 , V_3 , type , V_21 ) ;
}
struct V_1 *
F_10 ( struct V_22 * V_23 , enum V_24 type , unsigned int V_12 )
{
struct V_1 * V_6 ;
F_11 ( & V_23 -> V_25 ) ;
if ( type != V_26 )
return NULL ;
F_12 (port, &pf->ports, port_list)
if ( V_6 -> V_27 == V_12 )
return V_6 ;
return NULL ;
}
struct V_28 * F_13 ( struct V_1 * V_6 )
{
if ( ! V_6 )
return NULL ;
if ( V_6 -> type != V_26 )
return NULL ;
return V_6 -> V_29 ;
}
struct V_28 * F_14 ( struct V_1 * V_6 )
{
if ( ! F_13 ( V_6 ) )
return NULL ;
if ( F_15 ( V_30 , & V_6 -> V_31 ) )
if ( F_16 ( V_6 ) )
return NULL ;
return F_13 ( V_6 ) ;
}
int
F_17 ( struct V_2 * V_3 , char * V_32 , T_2 V_33 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
int V_34 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 )
return - V_11 ;
switch ( V_6 -> type ) {
case V_26 :
V_29 = F_13 ( V_6 ) ;
if ( ! V_29 )
return - V_11 ;
if ( ! V_29 -> V_35 )
V_34 = snprintf ( V_32 , V_33 , L_2 , V_29 -> V_36 ) ;
else
V_34 = snprintf ( V_32 , V_33 , L_3 , V_29 -> V_36 ,
V_29 -> V_37 ) ;
break;
case V_38 :
V_34 = snprintf ( V_32 , V_33 , L_4 , V_6 -> V_39 ) ;
break;
case V_40 :
V_34 = snprintf ( V_32 , V_33 , L_5 , V_6 -> V_39 , V_6 -> V_41 ) ;
break;
default:
return - V_11 ;
}
if ( V_34 >= V_33 )
return - V_42 ;
return 0 ;
}
int F_18 ( struct V_2 * V_3 , bool V_43 )
{
struct V_28 * V_29 ;
struct V_1 * V_6 ;
int V_44 ;
V_6 = F_1 ( V_3 ) ;
V_29 = F_13 ( V_6 ) ;
if ( ! V_29 )
return 0 ;
V_44 = F_19 ( V_6 -> V_18 -> V_19 , V_29 -> V_45 , V_43 ) ;
return V_44 < 0 && V_44 != - V_11 ? V_44 : 0 ;
}
int F_20 ( struct V_22 * V_23 , struct V_46 * V_18 ,
struct V_1 * V_6 , unsigned int V_12 )
{
if ( ! V_23 -> V_47 || V_12 >= V_23 -> V_47 -> V_48 ) {
F_21 ( V_18 -> V_19 ,
L_6 ,
V_12 ) ;
return - V_42 ;
}
if ( V_23 -> V_47 -> V_49 [ V_12 ] . V_50 ) {
F_22 ( V_18 -> V_19 ,
L_7 ,
V_23 -> V_47 -> V_49 [ V_12 ] . V_45 ) ;
V_6 -> type = V_51 ;
return 0 ;
}
V_6 -> V_29 = & V_23 -> V_47 -> V_49 [ V_12 ] ;
V_6 -> V_27 = V_23 -> V_47 -> V_49 [ V_12 ] . V_45 ;
if ( V_23 -> V_52 )
V_6 -> V_53 =
V_23 -> V_52 + V_6 -> V_27 * V_54 ;
return 0 ;
}
struct V_1 *
F_23 ( struct V_46 * V_18 , enum V_24 type ,
struct V_2 * V_3 )
{
struct V_1 * V_6 ;
V_6 = F_24 ( sizeof( * V_6 ) , V_55 ) ;
if ( ! V_6 )
return F_25 ( - V_56 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> type = type ;
V_6 -> V_18 = V_18 ;
F_26 ( & V_6 -> V_57 , & V_18 -> V_23 -> V_49 ) ;
return V_6 ;
}
void F_27 ( struct V_1 * V_6 )
{
if ( ! V_6 )
return;
F_28 ( & V_6 -> V_57 ) ;
F_29 ( V_6 ) ;
}
