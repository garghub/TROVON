static int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_2 ( V_1 -> V_3 , V_4 ,
V_5 ,
V_5 , V_6 ) ;
if ( V_2 ) {
F_3 ( V_1 -> V_7 ,
L_1 , V_2 ) ;
return V_2 ;
}
V_1 -> V_8 = true ;
F_4 ( V_1 -> V_7 , L_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_6 ( V_1 -> V_3 ,
V_4 ,
V_5 ,
V_6 ) ;
if ( V_2 ) {
F_3 ( V_1 -> V_7 ,
L_3 , V_2 ) ;
return V_2 ;
}
V_1 -> V_8 = false ;
F_4 ( V_1 -> V_7 , L_4 ) ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_8 ( V_10 ) ;
int V_2 ;
int V_11 = V_10 -> V_12 . V_11 ;
if ( V_10 -> V_12 . V_13 & V_14 )
V_11 = 0 ;
if ( ( V_10 -> V_12 . V_15 != V_16 ) ||
( V_10 -> V_12 . V_17 != V_16 ) )
V_11 = 0 ;
if ( V_11 > 0 ) {
V_2 = F_9 ( V_1 -> V_3 ,
V_18 ,
V_11 - 1 ,
V_6 ) ;
if ( V_2 ) {
F_3 ( V_1 -> V_7 ,
L_5 , V_2 ) ;
return V_2 ;
}
F_4 ( V_1 -> V_7 , L_6 , V_11 ) ;
if ( ! V_1 -> V_8 )
V_2 = F_1 ( V_1 ) ;
} else {
V_2 = F_5 ( V_1 ) ;
}
return V_2 ;
}
static int F_10 ( struct V_9 * V_10 )
{
return V_10 -> V_12 . V_11 ;
}
static int F_11 ( struct V_1 * V_1 ,
struct V_19 * V_20 )
{
int V_2 ;
V_2 = F_5 ( V_1 ) ;
if ( V_2 )
return V_2 ;
switch ( V_20 -> V_21 ) {
case V_22 :
V_2 = F_6 ( V_1 -> V_3 ,
V_4 ,
V_23 ,
V_6 ) ;
if ( V_2 ) {
F_3 ( V_1 -> V_7 ,
L_7 ,
V_2 ) ;
return V_2 ;
}
F_4 ( V_1 -> V_7 , L_8 ) ;
break;
case V_24 :
V_2 = F_2 ( V_1 -> V_3 , V_4 ,
V_23 ,
V_23 , V_6 ) ;
if ( V_2 ) {
F_3 ( V_1 -> V_7 ,
L_9 ,
V_2 ) ;
return V_2 ;
}
F_4 ( V_1 -> V_7 , L_10 ) ;
break;
default:
F_3 ( V_1 -> V_7 ,
L_11 , V_20 -> V_21 ) ;
return - V_25 ;
}
V_2 = F_2 ( V_1 -> V_3 ,
V_4 ,
V_26 ,
V_20 -> V_27 ,
V_6 ) ;
if ( V_2 ) {
F_3 ( V_1 -> V_7 ,
L_12 ,
V_2 ) ;
return V_2 ;
}
return 0 ;
}
static struct V_19 *
F_12 ( struct V_28 * V_29 )
{
struct V_30 * V_3 = F_13 ( V_29 -> V_7 . V_31 ) ;
struct V_32 * V_33 = F_14 ( V_3 -> V_7 -> V_34 ) ;
struct V_19 * V_20 , * V_35 ;
T_1 V_36 ;
V_33 = F_15 ( V_33 , L_13 ) ;
if ( ! V_33 )
return F_16 ( - V_37 ) ;
V_20 = F_17 ( & V_29 -> V_7 , sizeof( * V_20 ) , V_38 ) ;
if ( ! V_20 ) {
F_3 ( & V_29 -> V_7 , L_14 ) ;
V_35 = F_16 ( - V_39 ) ;
goto V_35;
}
V_20 -> V_21 = V_22 ;
if ( ! F_18 ( V_33 , L_15 , & V_36 ) ) {
if ( V_36 < V_22 ||
V_36 > V_24 ) {
F_3 ( & V_29 -> V_7 ,
L_16 ) ;
V_35 = F_16 ( - V_25 ) ;
goto V_35;
}
V_20 -> V_21 = V_36 ;
}
V_20 -> V_27 = V_40 ;
if ( ! F_18 ( V_33 , L_17 , & V_36 ) ) {
switch ( V_36 ) {
case 100 :
V_20 -> V_27 = V_41 ;
break;
case 200 :
V_20 -> V_27 = V_40 ;
break;
case 500 :
V_20 -> V_27 = V_42 ;
break;
case 1000 :
V_20 -> V_27 = V_43 ;
break;
default:
F_3 ( & V_29 -> V_7 ,
L_18 ) ;
V_35 = F_16 ( - V_25 ) ;
goto V_35;
}
}
if ( ! F_18 ( V_33 , L_19 , & V_36 ) ) {
if ( V_36 < 0 ||
V_36 > 100 ) {
F_3 ( & V_29 -> V_7 ,
L_20 ) ;
V_35 = F_16 ( - V_25 ) ;
goto V_35;
}
V_20 -> V_44 = V_36 ;
}
F_19 ( V_33 ) ;
return V_20 ;
V_35:
F_19 ( V_33 ) ;
return V_35 ;
}
static struct V_19 *
F_12 ( struct V_28 * V_29 )
{
return NULL ;
}
static int F_20 ( struct V_28 * V_29 )
{
int V_2 ;
struct V_30 * V_3 = F_13 ( V_29 -> V_7 . V_31 ) ;
struct V_1 * V_1 ;
struct V_19 * V_20 ;
struct V_45 V_46 ;
if ( V_3 -> V_7 -> V_34 ) {
V_20 = F_12 ( V_29 ) ;
if ( F_21 ( V_20 ) )
return F_22 ( V_20 ) ;
} else {
if ( ! V_29 -> V_7 . V_47 ) {
F_3 ( & V_29 -> V_7 , L_21 ) ;
return - V_25 ;
}
V_20 = V_29 -> V_7 . V_47 ;
}
V_1 = F_17 ( & V_29 -> V_7 , sizeof( * V_1 ) ,
V_38 ) ;
if ( V_1 == NULL ) {
F_3 ( & V_29 -> V_7 , L_22 ) ;
return - V_39 ;
}
V_1 -> V_3 = V_3 ;
V_1 -> V_7 = & V_29 -> V_7 ;
V_1 -> V_8 = false ;
V_2 = F_11 ( V_1 , V_20 ) ;
if ( V_2 )
return V_2 ;
memset ( & V_46 , 0 , sizeof( struct V_45 ) ) ;
V_46 . type = V_48 ;
V_46 . V_49 = 100 ;
V_1 -> V_10 = F_23 ( V_29 -> V_50 ,
V_1 -> V_7 , V_1 ,
& V_51 , & V_46 ) ;
if ( F_21 ( V_1 -> V_10 ) ) {
F_3 ( V_1 -> V_7 ,
L_23 , V_2 ) ;
return F_22 ( V_1 -> V_10 ) ;
}
V_1 -> V_10 -> V_12 . V_11 = V_20 -> V_44 ;
F_24 ( V_1 -> V_10 ) ;
F_25 ( V_29 , V_1 ) ;
return 0 ;
}
static int F_26 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = F_27 ( V_29 ) ;
F_28 ( V_1 -> V_10 ) ;
return 0 ;
}
