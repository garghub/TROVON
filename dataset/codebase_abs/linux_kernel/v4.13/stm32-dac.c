static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 ;
int V_8 ;
V_8 = F_3 ( V_5 -> V_9 -> V_10 , V_11 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( F_4 ( V_3 ) )
V_6 = F_5 ( V_12 , V_7 ) ;
else
V_6 = F_5 ( V_13 , V_7 ) ;
return ! ! V_6 ;
}
static int F_6 ( struct V_1 * V_2 , int V_14 ,
bool V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_16 = F_4 ( V_14 ) ? V_12 : V_13 ;
T_1 V_6 = V_15 ? V_16 : 0 ;
int V_8 ;
V_8 = F_7 ( V_5 -> V_9 -> V_10 , V_11 , V_16 , V_6 ) ;
if ( V_8 < 0 ) {
F_8 ( & V_2 -> V_17 , L_1 , V_6 ?
L_2 : L_3 ) ;
return V_8 ;
}
if ( V_6 && V_5 -> V_9 -> V_18 )
F_9 ( 1 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 , int V_3 , int * V_7 )
{
int V_8 ;
if ( F_4 ( V_3 ) )
V_8 = F_3 ( V_5 -> V_9 -> V_10 , V_19 , V_7 ) ;
else
V_8 = F_3 ( V_5 -> V_9 -> V_10 , V_20 , V_7 ) ;
return V_8 ? V_8 : V_21 ;
}
static int F_11 ( struct V_4 * V_5 , int V_3 , int V_7 )
{
int V_8 ;
if ( F_4 ( V_3 ) )
V_8 = F_12 ( V_5 -> V_9 -> V_10 , V_22 , V_7 ) ;
else
V_8 = F_12 ( V_5 -> V_9 -> V_10 , V_23 , V_7 ) ;
return V_8 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_24 const * V_25 ,
int * V_7 , int * V_26 , long V_27 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_27 ) {
case V_28 :
return F_10 ( V_5 , V_25 -> V_3 , V_7 ) ;
case V_29 :
* V_7 = V_5 -> V_9 -> V_30 ;
* V_26 = V_25 -> V_31 . V_32 ;
return V_33 ;
default:
return - V_34 ;
}
}
static int F_14 ( struct V_1 * V_2 ,
struct V_24 const * V_25 ,
int V_7 , int V_26 , long V_27 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_27 ) {
case V_28 :
return F_11 ( V_5 , V_25 -> V_3 , V_7 ) ;
default:
return - V_34 ;
}
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_35 , unsigned V_36 ,
unsigned * V_37 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_37 )
return F_12 ( V_5 -> V_9 -> V_10 , V_35 , V_36 ) ;
else
return F_3 ( V_5 -> V_9 -> V_10 , V_35 , V_37 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_24 * V_25 ,
unsigned int type )
{
return 0 ;
}
static T_2 F_18 ( struct V_1 * V_2 ,
T_3 V_38 ,
const struct V_24 * V_25 ,
char * V_39 )
{
int V_8 = F_1 ( V_2 , V_25 -> V_3 ) ;
if ( V_8 < 0 )
return V_8 ;
return sprintf ( V_39 , L_4 , V_8 ? 0 : 1 ) ;
}
static T_2 F_19 ( struct V_1 * V_2 ,
T_3 V_38 ,
const struct V_24 * V_25 ,
const char * V_39 , T_4 V_40 )
{
bool V_41 ;
int V_8 ;
V_8 = F_20 ( V_39 , & V_41 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_6 ( V_2 , V_25 -> V_3 , ! V_41 ) ;
if ( V_8 )
return V_8 ;
return V_40 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_17 . V_44 ;
unsigned int V_45 ;
T_1 V_3 ;
int V_8 ;
V_8 = F_22 ( V_43 , L_5 , & V_3 ) ;
if ( V_8 ) {
F_8 ( & V_2 -> V_17 , L_6 ) ;
return V_8 ;
}
for ( V_45 = 0 ; V_45 < F_23 ( V_46 ) ; V_45 ++ ) {
if ( V_46 [ V_45 ] . V_3 == V_3 )
break;
}
if ( V_45 >= F_23 ( V_46 ) ) {
F_8 ( & V_2 -> V_17 , L_7 ) ;
return - V_34 ;
}
V_2 -> V_47 = & V_46 [ V_45 ] ;
V_2 -> V_48 = 1 ;
return 0 ;
}
static int F_24 ( struct V_49 * V_50 )
{
struct V_42 * V_43 = V_50 -> V_17 . V_44 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_8 ;
if ( ! V_43 )
return - V_51 ;
V_2 = F_25 ( & V_50 -> V_17 , sizeof( * V_5 ) ) ;
if ( ! V_2 )
return - V_52 ;
F_26 ( V_50 , V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_5 -> V_9 = F_27 ( V_50 -> V_17 . V_53 ) ;
V_2 -> V_54 = F_28 ( & V_50 -> V_17 ) ;
V_2 -> V_17 . V_53 = & V_50 -> V_17 ;
V_2 -> V_17 . V_44 = V_50 -> V_17 . V_44 ;
V_2 -> V_55 = & V_56 ;
V_2 -> V_57 = V_58 ;
V_8 = F_21 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_29 ( & V_50 -> V_17 , V_2 ) ;
}
