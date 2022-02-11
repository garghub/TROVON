static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 args = { . V_5 = 1 , . V_6 [ 0 ] . V_7 = ! ! V_3 } ;
int V_8 ;
if ( F_2 ( ! V_2 ) ) return;
V_8 = F_3 ( V_2 -> V_9 , L_1 , & args ) ;
if ( V_8 )
F_4 ( V_10 L_2
L_3 , V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_11 ;
if ( F_2 ( ! V_2 ) ) return;
V_11 = V_2 -> V_12 ;
F_6 ( V_2 , 0 ) ;
F_7 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
V_2 -> V_12 = V_11 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_13 ;
if ( F_2 ( ! V_2 ) ) return;
V_13 = V_2 -> V_12 ;
F_6 ( V_2 , ( V_13 >> 0 ) & 1 ) ;
F_7 ( V_2 , ( V_13 >> 1 ) & 1 ) ;
F_8 ( V_2 , ( V_13 >> 2 ) & 1 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 =
F_11 ( V_15 , struct V_16 , V_15 . V_15 ) ;
F_12 ( & V_17 -> V_18 ) ;
if ( V_17 -> V_19 )
V_17 -> V_19 ( V_17 -> V_20 ) ;
F_13 ( & V_17 -> V_18 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
V_2 -> V_12 = 0 ;
F_15 ( & V_2 -> V_21 . V_15 , F_10 ) ;
F_15 ( & V_2 -> V_22 . V_15 , F_10 ) ;
F_15 ( & V_2 -> V_23 . V_15 , F_10 ) ;
F_16 ( & V_2 -> V_21 . V_18 ) ;
F_16 ( & V_2 -> V_22 . V_18 ) ;
F_16 ( & V_2 -> V_23 . V_18 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
V_2 -> V_12 = 0 ;
if ( V_2 -> V_21 . V_24 )
F_18 ( V_2 -> V_21 . V_24 ) ;
if ( V_2 -> V_22 . V_24 )
F_18 ( V_2 -> V_22 . V_24 ) ;
if ( V_2 -> V_23 . V_24 )
F_18 ( V_2 -> V_23 . V_24 ) ;
F_19 ( & V_2 -> V_21 . V_15 ) ;
F_19 ( & V_2 -> V_22 . V_15 ) ;
F_19 ( & V_2 -> V_23 . V_15 ) ;
F_20 ( & V_2 -> V_21 . V_18 ) ;
F_20 ( & V_2 -> V_22 . V_18 ) ;
F_20 ( & V_2 -> V_23 . V_18 ) ;
F_21 ( V_2 -> V_21 . V_24 ) ;
F_21 ( V_2 -> V_22 . V_24 ) ;
F_21 ( V_2 -> V_23 . V_24 ) ;
}
static void F_22 ( void * V_20 )
{
struct V_16 * V_17 = V_20 ;
F_23 ( & V_17 -> V_15 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
enum V_25 type ,
T_1 V_19 ,
void * V_20 )
{
struct V_16 * V_17 ;
T_1 V_26 ;
struct V_27 * V_28 ;
char * V_29 ;
int V_30 = - V_31 ;
switch ( type ) {
case V_32 :
V_17 = & V_2 -> V_21 ;
V_29 = L_4 ;
break;
case V_33 :
V_17 = & V_2 -> V_22 ;
V_29 = L_5 ;
break;
case V_34 :
V_17 = & V_2 -> V_23 ;
V_29 = L_6 ;
break;
default:
return - V_35 ;
}
F_12 ( & V_17 -> V_18 ) ;
V_26 = V_17 -> V_19 ;
if ( ! V_26 && ! V_19 ) {
V_30 = 0 ;
goto V_36;
}
if ( V_26 && V_19 ) {
if ( V_26 == V_19 && V_17 -> V_20 == V_20 )
V_30 = 0 ;
goto V_36;
}
if ( V_26 && ! V_19 ) {
V_28 = V_17 -> V_24 ;
F_18 ( V_28 ) ;
F_21 ( V_28 ) ;
V_17 -> V_24 = NULL ;
}
if ( ! V_26 && V_19 ) {
V_28 = F_25 ( sizeof( struct V_27 ) ,
V_37 ) ;
if ( ! V_28 ) {
V_30 = - V_38 ;
goto V_36;
}
V_28 -> V_20 = V_17 ;
V_28 -> V_39 = F_22 ;
V_28 -> V_40 = V_41 ;
V_30 = F_26 ( V_2 -> V_9 ,
V_29 ,
V_28 ) ;
if ( V_30 ) {
F_4 ( V_42 L_7
L_8 , V_29 , V_30 ) ;
F_21 ( V_28 ) ;
goto V_36;
}
V_17 -> V_24 = V_28 ;
}
V_17 -> V_19 = V_19 ;
V_17 -> V_20 = V_20 ;
V_30 = 0 ;
V_36:
F_13 ( & V_17 -> V_18 ) ;
return V_30 ;
}
static int F_27 ( struct V_1 * V_2 ,
enum V_25 type )
{
char * V_29 ;
int V_30 = - V_31 , V_43 ;
struct V_4 args = { . V_5 = 1 , . V_6 [ 0 ] . V_44 = & V_43 } ;
switch ( type ) {
case V_32 :
V_29 = L_4 ;
break;
case V_33 :
V_29 = L_5 ;
break;
case V_34 :
V_29 = L_6 ;
break;
default:
return - V_35 ;
}
V_30 = F_3 ( V_2 -> V_9 , V_29 , & args ) ;
if ( V_30 )
return V_30 ;
return V_43 ;
}
