static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 -> V_6 ,
L_1 , V_4 ) ;
return V_4 ;
}
if ( V_2 -> V_7 >= 0 )
F_4 ( V_2 -> V_7 , 1 ) ;
} else {
if ( V_2 -> V_7 >= 0 )
F_4 ( V_2 -> V_7 , 0 ) ;
V_4 = F_5 ( V_2 -> V_5 ) ;
if ( V_4 != 0 ) {
F_3 ( V_2 -> V_6 ,
L_2 , V_4 ) ;
return V_4 ;
}
F_6 ( V_2 -> V_8 ) ;
}
return V_4 ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 , int V_13 )
{
struct V_14 * V_15 = F_8 ( V_10 -> V_16 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
int V_4 ;
if ( F_10 ( V_13 ) ) {
F_1 ( V_2 , true ) ;
V_4 = F_11 ( V_2 -> V_8 ) ;
if ( V_4 < 0 ) {
F_3 ( V_15 -> V_6 , L_3 ) ;
F_1 ( V_2 , false ) ;
return V_4 ;
}
} else {
F_1 ( V_2 , false ) ;
}
return 0 ;
}
static int F_12 ( struct V_14 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 ) ;
if ( V_2 -> V_18 == V_19 )
return F_13 ( V_17 ,
V_20 , F_14 ( V_20 ) ) ;
else
return F_13 ( V_17 ,
V_21 , F_14 ( V_21 ) ) ;
}
static int F_15 ( struct V_22 * V_23 ,
const struct V_24 * V_18 )
{
struct V_25 * V_6 ;
struct V_1 * V_2 ;
struct V_26 * V_27 = V_23 -> V_6 . V_28 ;
struct V_29 * V_30 = V_23 -> V_6 . V_31 ;
const char * V_32 ;
unsigned int V_33 ;
int V_4 ;
V_6 = & V_23 -> V_6 ;
V_2 = F_16 ( & V_23 -> V_6 , sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_8 = F_17 ( V_23 , & V_36 ) ;
if ( F_18 ( V_2 -> V_8 ) )
return F_19 ( V_2 -> V_8 ) ;
if ( V_27 ) {
V_2 -> V_7 = V_27 -> V_7 ;
} else if ( V_30 ) {
V_2 -> V_7 = F_20 ( V_30 , L_4 , 0 ) ;
} else {
F_3 ( V_6 , L_5 ) ;
F_21 () ;
return - V_37 ;
}
F_22 ( V_23 , V_2 ) ;
V_2 -> V_18 = V_18 -> V_38 ;
if ( V_2 -> V_7 >= 0 ) {
V_4 = F_23 ( V_6 , V_2 -> V_7 ,
L_6 ) ;
if ( V_4 < 0 ) {
F_3 ( V_6 , L_7 ,
V_2 -> V_7 ) ;
return V_4 ;
}
F_24 ( V_2 -> V_7 , 0 ) ;
}
switch ( V_2 -> V_18 ) {
default:
F_25 ( V_6 , L_8 ,
V_2 -> V_18 ) ;
case V_39 :
V_32 = L_9 ;
break;
case V_19 :
V_32 = L_10 ;
break;
}
V_2 -> V_5 = F_26 ( V_6 , V_32 ) ;
if ( F_18 ( V_2 -> V_5 ) ) {
V_4 = F_19 ( V_2 -> V_5 ) ;
F_3 ( V_6 , L_11 , V_4 ) ;
return V_4 ;
}
V_4 = F_1 ( V_2 , true ) ;
if ( V_4 != 0 )
return V_4 ;
F_27 ( V_2 -> V_8 , V_40 , & V_33 ) ;
V_33 &= V_41 ;
if ( ( V_33 != 1 ) && ( V_33 != 2 ) )
F_25 ( V_6 , L_12 , V_33 ) ;
V_4 = F_1 ( V_2 , false ) ;
if ( V_4 != 0 )
return V_4 ;
return F_28 ( & V_23 -> V_6 ,
& V_42 , NULL , 0 ) ;
}
