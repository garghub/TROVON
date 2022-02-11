static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( ! V_4 ) {
F_3 ( V_3 -> V_5 , L_1 ,
V_6 , V_3 -> V_7 ) ;
return NULL ;
}
F_4 ( V_4 , V_8 ) ;
V_9 [ V_3 -> V_7 ] = V_4 ;
F_5 ( V_3 -> V_5 , L_2 , V_3 -> V_7 ) ;
return V_4 ;
}
static void F_6 ( unsigned int V_7 )
{
struct V_1 * V_4 = V_9 [ V_7 ] ;
const struct V_2 * V_3 ;
if ( ! V_4 )
return;
V_3 = F_7 ( V_4 ) ;
if ( ! V_3 )
return;
F_8 ( V_3 -> V_10 , F_9 ( 0 ) ) ;
}
static void F_10 ( unsigned int V_7 )
{
struct V_1 * V_4 = V_9 [ V_7 ] ;
const struct V_2 * V_3 ;
if ( ! V_4 )
return;
V_3 = F_7 ( V_4 ) ;
if ( ! V_3 )
return;
F_8 ( V_3 -> V_10 , F_9 ( V_7 ) ) ;
}
static int F_11 ( struct V_11 * V_12 ,
unsigned long V_13 , void * V_14 )
{
unsigned int V_7 = ( unsigned long ) V_14 ;
switch ( V_13 ) {
case V_15 :
case V_16 :
F_10 ( V_7 ) ;
break;
case V_17 :
case V_18 :
F_6 ( V_7 ) ;
}
return V_19 ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_22 * V_5 = & V_21 -> V_5 ;
struct V_23 * V_24 = V_5 -> V_25 ;
struct V_2 * V_3 ;
struct V_26 * V_27 [ 2 ] ;
void T_1 * V_28 ;
int V_10 , V_7 ;
V_3 = F_13 ( V_5 , sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 )
return - V_30 ;
V_3 -> V_5 = V_5 ;
V_27 [ 0 ] = F_14 ( V_21 , V_31 ,
V_32 ) ;
if ( ! V_27 [ 0 ] ) {
F_15 ( V_5 , L_3 ,
V_24 -> V_33 ) ;
return - V_34 ;
}
V_27 [ 1 ] = F_14 ( V_21 , V_31 ,
V_35 ) ;
if ( ! V_27 [ 1 ] ) {
F_15 ( V_5 , L_4 ,
V_24 -> V_33 ) ;
return - V_34 ;
}
V_3 -> V_7 = - 1 ;
V_10 = F_16 ( V_21 , 0 ) ;
if ( V_10 <= 0 ) {
F_15 ( V_5 , L_5 , V_24 -> V_33 ) ;
return - V_34 ;
}
V_3 -> V_10 = V_10 ;
V_28 = F_17 ( V_27 [ 0 ] -> V_36 , F_18 ( V_27 [ 0 ] ) , 0 ) ;
if ( ! V_28 )
goto V_37;
V_3 -> V_38 [ V_32 ] = V_28 ;
V_28 = F_17 ( V_27 [ 1 ] -> V_36 , F_18 ( V_27 [ 1 ] ) ,
V_39 | V_40 ) ;
if ( ! V_28 )
goto V_41;
V_3 -> V_38 [ V_35 ] = V_28 ;
F_19 ( & V_42 ) ;
V_7 = F_20 ( - 1 , & V_43 ) ;
if ( V_7 >= V_44 ) {
F_21 ( & V_42 ) ;
return 0 ;
}
F_22 ( V_7 , & V_43 ) ;
F_21 ( & V_42 ) ;
V_3 -> V_7 = V_7 ;
if ( ! F_1 ( V_3 ) )
goto V_41;
if ( ! F_23 ( V_7 ) )
F_6 ( V_7 ) ;
return 0 ;
V_41:
F_24 ( V_3 -> V_38 [ V_32 ] ) ;
V_37:
F_15 ( V_5 , L_6 ) ;
return - V_34 ;
}
static int T_2 F_25 ( struct V_45 * V_46 )
{
int V_47 ;
V_47 = F_26 ( V_46 ) ;
if ( V_47 < 0 )
return V_47 ;
F_27 ( & V_48 ) ;
return 0 ;
}
