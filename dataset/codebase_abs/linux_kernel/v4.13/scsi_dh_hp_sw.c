static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = V_8 ;
switch ( V_6 -> V_9 ) {
case V_10 :
V_7 = V_11 ;
break;
case V_12 :
if ( V_6 -> V_13 == 0x04 && V_6 -> V_14 == 2 ) {
V_4 -> V_15 = V_16 ;
V_7 = V_17 ;
break;
}
default:
F_2 ( V_18 , V_2 ,
L_1 ,
V_19 , V_6 -> V_9 , V_6 -> V_13 ,
V_6 -> V_14 ) ;
break;
}
return V_7 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_20 [ 6 ] = { V_21 } ;
struct V_5 V_6 ;
int V_7 = V_17 , V_22 ;
T_1 V_23 = V_24 | V_25 |
V_26 ;
V_27:
V_22 = F_4 ( V_2 , V_20 , V_28 , NULL , 0 , NULL , & V_6 ,
V_29 , V_30 , V_23 , 0 , NULL ) ;
if ( V_22 ) {
if ( F_5 ( & V_6 ) )
V_7 = F_1 ( V_2 , V_4 , & V_6 ) ;
else {
F_2 ( V_18 , V_2 ,
L_2 ,
V_19 , V_22 ) ;
V_7 = V_8 ;
}
} else {
V_4 -> V_15 = V_31 ;
V_7 = V_17 ;
}
if ( V_7 == V_11 )
goto V_27;
return V_7 ;
}
static int F_6 ( struct V_3 * V_4 )
{
unsigned char V_20 [ 6 ] = { V_32 , 0 , 0 , 0 , 1 , 0 } ;
struct V_5 V_6 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_22 , V_33 = V_17 ;
int V_34 = V_30 ;
T_1 V_23 = V_24 | V_25 |
V_26 ;
V_27:
V_22 = F_4 ( V_2 , V_20 , V_28 , NULL , 0 , NULL , & V_6 ,
V_29 , V_30 , V_23 , 0 , NULL ) ;
if ( V_22 ) {
if ( ! F_5 ( & V_6 ) ) {
F_2 ( V_18 , V_2 ,
L_3
L_4 , V_19 ) ;
return V_8 ;
}
switch ( V_6 . V_9 ) {
case V_12 :
if ( V_6 . V_13 == 0x04 && V_6 . V_14 == 3 ) {
if ( -- V_34 )
goto V_27;
V_33 = V_35 ;
break;
}
default:
F_2 ( V_18 , V_2 ,
L_3
L_5 , V_19 ,
V_6 . V_9 , V_6 . V_13 , V_6 . V_14 ) ;
V_33 = V_8 ;
}
}
return V_33 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_4 = V_2 -> V_38 ;
int V_7 = V_39 ;
if ( V_4 -> V_15 != V_31 ) {
V_7 = V_40 ;
V_37 -> V_41 |= V_42 ;
}
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_2 V_43 , void * V_44 )
{
int V_7 = V_17 ;
struct V_3 * V_4 = V_2 -> V_38 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( V_7 == V_17 && V_4 -> V_15 == V_16 )
V_7 = F_6 ( V_4 ) ;
if ( V_43 )
V_43 ( V_44 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
return - V_46 ;
V_4 -> V_15 = V_47 ;
V_4 -> V_48 = V_30 ;
V_4 -> V_2 = V_2 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( V_7 != V_17 || V_4 -> V_15 == V_47 )
goto V_49;
F_2 ( V_50 , V_2 , L_6 ,
V_19 , V_4 -> V_15 == V_31 ?
L_7 : L_8 ) ;
V_2 -> V_38 = V_4 ;
return 0 ;
V_49:
F_11 ( V_4 ) ;
return - V_51 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_52 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_52 ) ;
}
