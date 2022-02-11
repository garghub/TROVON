static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 = 0 , V_5 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_6 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 -> V_7 ,
L_1 , V_4 ) ;
return V_4 ;
}
if ( V_2 -> V_8 >= 0 )
F_4 ( V_2 -> V_8 , 1 ) ;
F_5 ( V_2 -> V_9 , false ) ;
V_4 = F_6 ( V_2 -> V_9 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 -> V_7 ,
L_2 , V_4 ) ;
F_5 ( V_2 -> V_9 , true ) ;
if ( V_2 -> V_8 >= 0 )
F_4 ( V_2 -> V_8 , 0 ) ;
V_5 = F_7 ( V_2 -> V_6 ) ;
if ( V_5 != 0 )
F_3 ( V_2 -> V_7 ,
L_3 , V_5 ) ;
return V_4 ;
}
} else {
F_8 ( V_2 -> V_9 ) ;
F_5 ( V_2 -> V_9 , true ) ;
if ( V_2 -> V_8 >= 0 )
F_4 ( V_2 -> V_8 , 0 ) ;
V_4 = F_7 ( V_2 -> V_6 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 -> V_7 ,
L_3 , V_4 ) ;
return V_4 ;
}
}
return V_4 ;
}
static int F_9 ( struct V_10 * V_11 ,
struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_10 ( V_11 -> V_17 ) ;
struct V_1 * V_2 = F_11 ( V_16 ) ;
if ( F_12 ( V_14 ) ) {
return F_1 ( V_2 , true ) ;
} else {
return F_1 ( V_2 , false ) ;
}
}
static int F_13 ( struct V_15 * V_18 )
{
struct V_1 * V_2 = F_11 ( V_18 ) ;
if ( V_2 -> V_19 == V_20 )
return F_14 ( V_18 ,
V_21 , F_15 ( V_21 ) ) ;
else
return F_14 ( V_18 ,
V_22 , F_15 ( V_22 ) ) ;
}
static int F_16 ( struct V_23 * V_24 ,
const struct V_25 * V_19 )
{
struct V_26 * V_7 ;
struct V_1 * V_2 ;
struct V_27 * V_28 = V_24 -> V_7 . V_29 ;
struct V_30 * V_31 = V_24 -> V_7 . V_32 ;
const char * V_33 ;
unsigned int V_34 ;
int V_4 ;
V_7 = & V_24 -> V_7 ;
V_2 = F_17 ( & V_24 -> V_7 , sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = F_18 ( V_24 , & V_37 ) ;
if ( F_19 ( V_2 -> V_9 ) )
return F_20 ( V_2 -> V_9 ) ;
if ( V_28 ) {
V_2 -> V_8 = V_28 -> V_8 ;
} else if ( V_31 ) {
V_2 -> V_8 = F_21 ( V_31 , L_4 , 0 ) ;
} else {
F_3 ( V_7 , L_5 ) ;
F_22 () ;
return - V_38 ;
}
F_23 ( V_24 , V_2 ) ;
V_2 -> V_19 = V_19 -> V_39 ;
if ( V_2 -> V_8 >= 0 ) {
V_4 = F_24 ( V_7 , V_2 -> V_8 ,
L_6 ) ;
if ( V_4 < 0 ) {
F_3 ( V_7 , L_7 ,
V_2 -> V_8 ) ;
return V_4 ;
}
F_25 ( V_2 -> V_8 , 0 ) ;
}
switch ( V_2 -> V_19 ) {
default:
F_26 ( V_7 , L_8 ,
V_2 -> V_19 ) ;
case V_40 :
V_33 = L_9 ;
break;
case V_20 :
V_33 = L_10 ;
break;
}
V_2 -> V_6 = F_27 ( V_7 , V_33 ) ;
if ( F_19 ( V_2 -> V_6 ) ) {
V_4 = F_20 ( V_2 -> V_6 ) ;
F_3 ( V_7 , L_11 , V_4 ) ;
return V_4 ;
}
V_4 = F_1 ( V_2 , true ) ;
if ( V_4 != 0 )
return V_4 ;
F_28 ( V_2 -> V_9 , V_41 , & V_34 ) ;
V_34 &= V_42 ;
if ( ( V_34 != 1 ) && ( V_34 != 2 ) )
F_26 ( V_7 , L_12 , V_34 ) ;
V_4 = F_1 ( V_2 , false ) ;
if ( V_4 != 0 )
return V_4 ;
return F_29 ( & V_24 -> V_7 ,
& V_43 , NULL , 0 ) ;
}
