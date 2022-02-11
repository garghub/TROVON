static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; ++ V_4 ) {
struct V_6 * V_7 = & V_2 -> V_8 [ V_4 ] ;
if ( V_7 -> V_3 && V_7 -> V_3 < V_3 )
V_3 = V_7 -> V_3 ;
}
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned int V_3 = V_10 -> V_3 ;
struct V_11 * V_12 = V_10 -> V_12 ;
if ( F_3 ( V_12 ) ) {
if ( V_2 -> V_13 && V_3 < V_2 -> V_13 )
return - V_14 ;
if ( V_2 -> V_15 && V_3 > V_2 -> V_15 )
return - V_14 ;
return 0 ;
}
V_3 = F_1 ( V_2 , V_3 ) ;
if ( V_2 -> V_16 -> V_17 )
return V_2 -> V_16 -> V_17 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_18 * V_10 )
{
if ( V_2 -> V_19 == V_10 -> V_20 && V_2 -> V_16 -> V_21 )
return V_2 -> V_16 -> V_21 ( V_2 , V_10 -> V_22 , V_10 -> V_23 ) ;
if ( V_2 -> V_19 != V_10 -> V_20 && V_2 -> V_16 -> V_24 )
return V_2 -> V_16 -> V_24 ( V_2 , V_10 -> V_20 ,
V_10 -> V_22 , V_10 -> V_23 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_18 * V_10 )
{
if ( V_2 -> V_19 == V_10 -> V_20 && V_2 -> V_16 -> V_25 )
V_2 -> V_16 -> V_25 ( V_2 , V_10 -> V_22 , V_10 -> V_23 ) ;
if ( V_2 -> V_19 != V_10 -> V_20 && V_2 -> V_16 -> V_26 )
V_2 -> V_16 -> V_26 ( V_2 , V_10 -> V_20 , V_10 -> V_22 ,
V_10 -> V_23 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_27 * V_10 )
{
const struct V_28 * V_29 = V_10 -> V_29 ;
struct V_11 * V_12 = V_10 -> V_12 ;
if ( V_2 -> V_19 != V_10 -> V_20 )
return 0 ;
if ( F_3 ( V_12 ) ) {
if ( ! V_2 -> V_16 -> V_30 || ! V_2 -> V_16 -> V_31 )
return - V_32 ;
return V_2 -> V_16 -> V_30 ( V_2 , V_10 -> V_22 , V_29 , V_12 ) ;
}
V_2 -> V_16 -> V_31 ( V_2 , V_10 -> V_22 , V_29 , V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_27 * V_10 )
{
const struct V_28 * V_29 = V_10 -> V_29 ;
if ( V_2 -> V_19 != V_10 -> V_20 )
return 0 ;
if ( ! V_2 -> V_16 -> V_33 )
return - V_32 ;
return V_2 -> V_16 -> V_33 ( V_2 , V_10 -> V_22 , V_29 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_34 * V_10 )
{
const struct V_35 * V_36 = V_10 -> V_36 ;
struct V_11 * V_12 = V_10 -> V_12 ;
F_9 ( V_37 , V_2 -> V_5 ) ;
int V_22 , V_38 ;
F_10 ( V_37 , V_2 -> V_5 ) ;
if ( V_2 -> V_19 == V_10 -> V_20 )
F_11 ( V_10 -> V_22 , V_37 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_5 ; V_22 ++ )
if ( F_12 ( V_2 , V_22 ) || F_13 ( V_2 , V_22 ) )
F_11 ( V_22 , V_37 ) ;
if ( F_3 ( V_12 ) ) {
if ( ! V_2 -> V_16 -> V_39 || ! V_2 -> V_16 -> V_40 )
return - V_32 ;
F_14 (port, group, ds->num_ports) {
V_38 = V_2 -> V_16 -> V_39 ( V_2 , V_22 , V_36 , V_12 ) ;
if ( V_38 )
return V_38 ;
}
}
F_14 (port, group, ds->num_ports)
V_2 -> V_16 -> V_40 ( V_2 , V_22 , V_36 , V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_34 * V_10 )
{
const struct V_35 * V_36 = V_10 -> V_36 ;
if ( ! V_2 -> V_16 -> V_41 )
return - V_32 ;
if ( V_2 -> V_19 == V_10 -> V_20 )
return V_2 -> V_16 -> V_41 ( V_2 , V_10 -> V_22 , V_36 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_42 * V_10 )
{
const struct V_43 * V_44 = V_10 -> V_44 ;
struct V_11 * V_12 = V_10 -> V_12 ;
F_9 ( V_45 , V_2 -> V_5 ) ;
int V_22 , V_38 ;
F_10 ( V_45 , V_2 -> V_5 ) ;
if ( V_2 -> V_19 == V_10 -> V_20 )
F_11 ( V_10 -> V_22 , V_45 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_5 ; V_22 ++ )
if ( F_12 ( V_2 , V_22 ) || F_13 ( V_2 , V_22 ) )
F_11 ( V_22 , V_45 ) ;
if ( F_3 ( V_12 ) ) {
if ( ! V_2 -> V_16 -> V_46 || ! V_2 -> V_16 -> V_47 )
return - V_32 ;
F_14 (port, members, ds->num_ports) {
V_38 = V_2 -> V_16 -> V_46 ( V_2 , V_22 , V_44 , V_12 ) ;
if ( V_38 )
return V_38 ;
}
}
F_14 (port, members, ds->num_ports)
V_2 -> V_16 -> V_47 ( V_2 , V_22 , V_44 , V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_42 * V_10 )
{
const struct V_43 * V_44 = V_10 -> V_44 ;
if ( ! V_2 -> V_16 -> V_48 )
return - V_32 ;
if ( V_2 -> V_19 == V_10 -> V_20 )
return V_2 -> V_16 -> V_48 ( V_2 , V_10 -> V_22 , V_44 ) ;
return 0 ;
}
static int F_18 ( struct V_49 * V_50 ,
unsigned long V_51 , void * V_10 )
{
struct V_1 * V_2 = F_19 ( V_50 , struct V_1 , V_50 ) ;
int V_38 ;
switch ( V_51 ) {
case V_52 :
V_38 = F_2 ( V_2 , V_10 ) ;
break;
case V_53 :
V_38 = F_4 ( V_2 , V_10 ) ;
break;
case V_54 :
V_38 = F_5 ( V_2 , V_10 ) ;
break;
case V_55 :
V_38 = F_6 ( V_2 , V_10 ) ;
break;
case V_56 :
V_38 = F_7 ( V_2 , V_10 ) ;
break;
case V_57 :
V_38 = F_8 ( V_2 , V_10 ) ;
break;
case V_58 :
V_38 = F_15 ( V_2 , V_10 ) ;
break;
case V_59 :
V_38 = F_16 ( V_2 , V_10 ) ;
break;
case V_60 :
V_38 = F_17 ( V_2 , V_10 ) ;
break;
default:
V_38 = - V_32 ;
break;
}
if ( V_38 )
F_20 ( V_2 -> V_61 , L_1 ,
V_51 , V_38 ) ;
return F_21 ( V_38 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
V_2 -> V_50 . V_62 = F_18 ;
return F_23 ( & V_2 -> V_63 -> V_64 , & V_2 -> V_50 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_25 ( & V_2 -> V_63 -> V_64 , & V_2 -> V_50 ) ;
if ( V_38 )
F_26 ( V_2 -> V_61 , L_2 , V_38 ) ;
}
