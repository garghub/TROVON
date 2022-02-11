static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
V_6 = F_2 ( V_5 , V_3 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_5 -> V_7 , L_1 ) ;
return V_6 ;
}
V_6 = F_4 ( V_5 ) ;
if ( V_6 < 0 )
F_3 ( & V_5 -> V_7 , L_2 ) ;
return V_6 ;
}
static inline int F_5 ( struct V_1 * V_2 , int V_8 )
{
return F_6 ( V_2 -> V_5 , V_9 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_6 ;
int V_8 ;
V_6 = F_1 ( V_2 , V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_8 = V_6 << 8 ;
V_6 = F_1 ( V_2 , V_11 ) ;
if ( V_6 < 0 )
return V_6 ;
V_8 |= V_6 ;
* V_3 = V_8 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_12 = 10 ;
int V_6 ;
V_6 = F_5 ( V_2 , V_13 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_5 -> V_7 , L_3 ) ;
return V_6 ;
}
while ( V_12 -- ) {
F_9 ( 1000 , 2000 ) ;
V_6 = F_1 ( V_2 , V_14 ) ;
if ( V_6 < 0 )
break;
if ( V_6 & V_15 ) {
* V_3 = 0 ;
V_6 = - V_16 ;
break;
}
if ( ! ( V_6 & V_17 ) ) {
V_6 = F_7 ( V_2 , V_3 ) ;
break;
}
V_6 = - V_18 ;
}
return V_6 ;
}
static int F_10 ( struct V_19 * V_20 ,
struct V_21 const * V_22 ,
int * V_8 , int * V_23 , long V_24 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
int V_6 = - V_16 ;
F_12 ( & V_20 -> V_25 ) ;
if ( F_13 ( V_20 ) && V_24 == V_26 ) {
V_6 = - V_27 ;
goto V_28;
}
switch ( V_24 ) {
case V_26 : {
T_1 V_3 ;
V_6 = F_8 ( V_2 , & V_3 ) ;
if ( ! V_6 ) {
* V_8 = V_3 ;
V_6 = V_29 ;
}
break;
}
case V_30 :
* V_8 = 0 ;
* V_23 = 10000 ;
V_6 = V_31 ;
break;
}
V_28:
F_14 ( & V_20 -> V_25 ) ;
return V_6 ;
}
static T_2 F_15 ( int V_32 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
struct V_19 * V_20 = V_35 -> V_20 ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
int V_6 ;
V_6 = F_8 ( V_2 , V_2 -> V_36 ) ;
if ( ! V_6 ) {
F_16 ( V_20 , V_2 -> V_36 ,
F_17 () ) ;
} else if ( V_6 != - V_16 ) {
F_3 ( & V_2 -> V_5 -> V_7 , L_4 ) ;
}
F_18 ( V_20 -> V_37 ) ;
return V_38 ;
}
static int F_19 ( struct V_4 * V_5 ,
const struct V_39 * V_40 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 ;
int V_6 ;
V_20 = F_20 ( & V_5 -> V_7 , sizeof( * V_2 ) ) ;
if ( ! V_20 )
return - V_41 ;
V_20 -> V_42 = & V_43 ;
V_20 -> V_44 = V_45 ;
V_20 -> V_46 = V_47 ;
V_20 -> V_48 = F_21 ( V_47 ) ;
V_20 -> V_49 = V_50 ;
V_2 = F_11 ( V_20 ) ;
F_22 ( V_5 , V_20 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_20 = V_20 ;
V_6 = F_23 ( V_20 , NULL ,
F_15 , NULL ) ;
if ( V_6 )
return V_6 ;
V_6 = F_24 ( V_20 ) ;
if ( V_6 )
goto V_51;
return 0 ;
V_51:
F_25 ( V_20 ) ;
return V_6 ;
}
static int F_26 ( struct V_4 * V_5 )
{
struct V_19 * V_20 = F_27 ( V_5 ) ;
F_28 ( V_20 ) ;
F_25 ( V_20 ) ;
return 0 ;
}
