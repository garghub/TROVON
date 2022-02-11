static void F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 [ 0 ] & 0xF0 ) {
case V_4 :
V_2 -> V_5 = F_2 ( V_6 ) ;
break;
case V_7 :
V_2 -> V_5 = F_2 ( V_8 ) ;
break;
default:
V_2 -> V_5 = F_2 ( V_9 ) ;
break;
}
}
static T_1
F_3 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( ! V_11 -> V_12 )
F_4 ( V_2 ) ;
else
F_5 ( V_2 , V_11 ) ;
return V_13 ;
}
static T_1
F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
switch ( V_11 -> V_14 ) {
case V_15 :
return V_16 ;
case V_17 :
return F_3 ( V_2 , V_11 ) ;
case V_18 :
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 , V_2 -> V_19 ) ;
V_2 -> V_20 = V_21 ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return V_13 ;
default:
F_4 ( V_2 ) ;
return V_13 ;
}
}
static T_1
F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
if ( ! V_23 ) {
F_4 ( V_2 ) ;
return V_13 ;
}
V_2 -> V_19 = V_23 -> V_24 . V_12 ;
return F_6 ( V_2 , & V_23 -> V_24 ) ;
}
static T_1
F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_10 * V_11 ;
T_2 V_25 ;
T_3 V_26 ;
if ( F_14 ( V_2 ) ) {
if ( V_23 -> V_27
& V_28 )
return F_15 ( V_2 , V_23 ) ;
F_4 ( V_2 ) ;
return V_13 ;
}
V_25 = F_16 ( V_2 ) ;
V_26 = F_17 ( V_2 ) - F_18 ( V_2 ) ;
if ( V_25 >= V_29 ) {
F_4 ( V_2 ) ;
return V_13 ;
}
V_11 = & V_23 -> V_30 [ V_25 ] ;
if ( V_23 -> V_27 & V_31 )
V_2 -> V_19 = V_11 -> V_12 ;
F_19 ( V_2 , sizeof( struct V_32 ) ) ;
F_20 ( V_2 , V_26 ) ;
F_1 ( V_2 ) ;
return F_6 ( V_2 , V_11 ) ;
}
static T_1
F_21 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_1 * V_33 ;
int V_34 ;
if ( V_23 -> V_27 & V_35 ) {
while ( ( V_33 = F_22 ( V_2 ) ) != NULL )
F_13 ( V_33 , V_23 ) ;
F_23 ( V_2 ) ;
V_34 = V_13 ;
} else {
V_34 = F_13 ( V_2 , V_23 ) ;
}
return V_34 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_10 * V_11 ,
struct V_36 * V_37 )
{
int V_38 , V_39 ;
struct V_32 * V_40 ;
V_39 = 0 ;
V_38 = sizeof( struct V_32 ) ;
if ( F_25 ( V_2 ) < V_38 ) {
if ( F_26 ( V_2 , V_38 , 0 , V_41 ) )
return V_42 ;
}
V_40 = F_27 ( V_2 , V_39 , 0 ) ;
if ( ! V_40 )
return V_42 ;
if ( V_23 -> V_43 & V_44 ) {
if ( V_11 -> V_25 == 0xff )
V_40 -> V_25 = 0 ;
else
V_40 -> V_25 = V_11 -> V_25 ;
}
V_2 -> V_5 = F_2 ( V_9 ) ;
return V_45 ;
}
T_1 F_28 ( struct V_1 * * V_46 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 = * V_46 ;
struct V_36 * V_19 ;
int V_34 ;
if ( ! V_2 )
return V_13 ;
V_19 = V_2 -> V_19 ;
V_23 = F_29 ( V_19 ) ;
if ( V_23 -> V_27 & V_47 ) {
V_34 = F_21 ( V_2 , V_23 ) ;
} else {
switch ( F_30 ( V_2 -> V_5 ) ) {
case V_9 :
if ( V_23 -> V_24 . V_14 ==
V_17 ) {
V_34 = F_12 ( V_2 , V_23 ) ;
} else {
F_4 ( V_2 ) ;
V_34 = V_13 ;
}
break;
case V_6 :
case V_8 :
V_34 = F_12 ( V_2 , V_23 ) ;
break;
default:
V_34 = V_16 ;
}
}
return V_34 ;
}
void F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_36 * V_37 ;
struct V_22 * V_23 ;
V_37 = V_2 -> V_19 ;
V_2 -> V_19 = V_11 -> V_12 ;
V_23 = F_29 ( V_2 -> V_19 ) ;
if ( ! V_23 ) {
F_4 ( V_2 ) ;
return;
}
if ( V_23 -> V_43 & V_48 ) {
switch ( F_24 ( V_2 , V_23 , V_11 , V_37 ) ) {
case V_42 :
return;
case V_45 :
break;
default:
F_4 ( V_2 ) ;
return;
}
}
if ( V_11 -> V_14 == V_18 )
F_31 ( V_2 , V_37 ) ;
F_32 ( V_2 ) ;
}
