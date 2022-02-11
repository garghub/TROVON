static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 ,
int * V_6 , long V_7 )
{
int V_8 , V_9 ;
unsigned int V_10 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_13 :
switch ( V_4 -> type ) {
case V_14 :
V_8 = F_3 ( V_12 ,
& V_9 ) ;
if ( V_8 )
return V_8 ;
* V_5 = V_9 ;
return V_15 ;
case V_16 :
V_8 = F_4 ( V_12 ,
& V_10 ) ;
if ( V_8 )
return V_8 ;
* V_5 = V_10 ;
return V_15 ;
default:
return - V_17 ;
}
case V_18 :
* V_5 = V_19 [ V_12 -> V_20 ] ;
return V_15 ;
default:
return - V_17 ;
}
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 const * V_21 ,
int V_5 , int V_6 , long V_7 )
{
struct V_11 * V_12 = F_2 ( V_2 ) ;
int V_22 , V_8 ;
switch ( V_7 ) {
case V_18 :
V_22 = F_6 ( V_19 ) ;
while ( V_22 -- > 0 )
if ( V_5 == V_19 [ V_22 ] )
break;
if ( V_22 < 0 )
return - V_17 ;
F_7 ( & V_12 -> V_23 ) ;
V_12 -> V_20 = V_22 ;
V_8 = F_8 ( V_12 , V_22 ) ;
F_9 ( & V_12 -> V_23 ) ;
return V_8 ;
default:
return - V_17 ;
}
}
static T_1 F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_1 * V_2 = F_11 ( V_25 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
return F_12 ( V_12 , V_28 ) ;
}
static T_1 F_13 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_1 * V_2 = F_11 ( V_25 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
return F_14 ( V_12 , V_28 ) ;
}
static T_1 F_15 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_29 )
{
struct V_1 * V_2 = F_11 ( V_25 ) ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
return F_16 ( V_12 , V_28 , V_29 ) ;
}
static int F_17 ( struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
int V_8 ;
T_3 V_34 ;
if ( ! F_18 ( V_31 -> V_35 ,
V_36 |
V_37 |
V_38 ) ) {
F_19 ( & V_31 -> V_25 ,
L_1 ) ;
return - V_39 ;
}
V_2 = F_20 ( & V_31 -> V_25 , sizeof( * V_12 ) ) ;
if ( ! V_2 )
return - V_40 ;
V_12 = F_2 ( V_2 ) ;
V_12 -> V_31 = V_31 ;
V_12 -> V_20 = 0 ;
F_21 ( & V_12 -> V_23 ) ;
V_2 -> V_41 = & V_42 ;
V_2 -> V_43 = V_33 -> V_43 ;
V_2 -> V_25 . V_44 = & V_31 -> V_25 ;
V_2 -> V_45 = V_46 ;
if ( V_33 -> V_47 == V_48 ) {
V_2 -> V_49 = V_50 ;
V_2 -> V_51 = F_6 ( V_50 ) ;
} else {
V_2 -> V_49 = V_52 ;
V_2 -> V_51 = F_6 ( V_52 ) ;
}
F_22 ( V_31 , V_2 ) ;
V_8 = F_23 ( V_31 , V_53 , 15000 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_24 ( V_31 , & V_34 ) ;
if ( V_8 )
return V_8 ;
F_25 ( & V_31 -> V_25 , L_2 , V_34 ) ;
return F_26 ( & V_31 -> V_25 , V_2 ) ;
}
