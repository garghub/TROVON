static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_7 = V_8 ;
unsigned long V_9 = 0 ;
if ( F_2 ( V_10 ) ) {
F_3 ( V_3 , V_8 ) ;
return;
}
if ( F_4 ( V_11 , & V_3 -> V_12 ) )
V_3 -> V_13 = V_3 -> V_14 ;
switch ( V_5 -> V_15 ) {
case 0 :
V_5 -> V_16 = 300 +
( 6720 << V_17 ) / ( 5 * V_18 [ 0 ] + ( 7 << V_17 ) ) ;
V_5 -> V_16 =
F_5 ( V_5 -> V_16 ) ;
V_9 = F_5 ( 70 ) ;
V_5 -> V_15 ++ ;
if ( ! V_5 -> V_19 )
V_7 = V_3 -> V_13 ;
break;
case 1 :
V_9 = V_5 -> V_16 / 4 - F_5 ( 70 ) ;
V_5 -> V_15 ++ ;
if ( V_5 -> V_19 )
V_7 = V_3 -> V_13 ;
break;
case 2 :
V_9 = F_5 ( 70 ) ;
V_5 -> V_15 ++ ;
if ( ! V_5 -> V_19 )
V_7 = V_3 -> V_13 ;
break;
default:
V_9 = V_5 -> V_16 - V_5 -> V_16 / 4 -
F_5 ( 70 ) ;
V_5 -> V_15 = 0 ;
if ( V_5 -> V_19 )
V_7 = V_3 -> V_13 ;
break;
}
F_3 ( V_3 , V_7 ) ;
F_6 ( & V_5 -> V_20 , V_21 + V_9 ) ;
}
static T_1 F_7 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_2 * V_3 = F_8 ( V_23 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
return sprintf ( V_26 , L_1 , V_5 -> V_19 ) ;
}
static T_1 F_9 ( struct V_22 * V_23 ,
struct V_24 * V_25 , const char * V_26 , T_2 V_27 )
{
struct V_2 * V_3 = F_8 ( V_23 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_28 ;
int V_29 ;
V_29 = F_10 ( V_26 , 0 , & V_28 ) ;
if ( V_29 )
return V_29 ;
V_5 -> V_19 = ! ! V_28 ;
return V_27 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_30 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_31 ) ;
if ( ! V_5 )
return;
V_3 -> V_6 = V_5 ;
V_30 = F_13 ( V_3 -> V_23 , & V_32 ) ;
if ( V_30 ) {
F_14 ( V_3 -> V_6 ) ;
return;
}
F_15 ( & V_5 -> V_20 ,
F_1 , ( unsigned long ) V_3 ) ;
V_5 -> V_15 = 0 ;
if ( ! V_3 -> V_13 )
V_3 -> V_13 = V_3 -> V_33 ;
F_1 ( V_5 -> V_20 . V_1 ) ;
F_16 ( V_34 , & V_3 -> V_12 ) ;
V_3 -> V_35 = true ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_3 -> V_35 ) {
F_18 ( & V_5 -> V_20 ) ;
F_19 ( V_3 -> V_23 , & V_32 ) ;
F_14 ( V_5 ) ;
F_20 ( V_34 , & V_3 -> V_12 ) ;
V_3 -> V_35 = false ;
}
}
static int F_21 ( struct V_36 * V_37 ,
unsigned long V_38 , void * V_39 )
{
int V_30 ;
switch ( V_38 ) {
case V_40 :
case V_41 :
case V_42 :
F_22 ( & V_43 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
V_30 = F_23 ( & V_43 ) ;
if ( V_30 )
F_24 ( L_2 ) ;
break;
default:
break;
}
return V_47 ;
}
static int F_25 ( struct V_36 * V_37 ,
unsigned long V_48 , void * V_39 )
{
F_22 ( & V_43 ) ;
return V_47 ;
}
static int F_26 ( struct V_36 * V_37 ,
unsigned long V_48 , void * V_39 )
{
V_10 = 1 ;
return V_47 ;
}
static int T_3 F_27 ( void )
{
int V_30 = F_23 ( & V_43 ) ;
if ( ! V_30 ) {
F_28 ( & V_49 ,
& V_50 ) ;
F_29 ( & V_51 ) ;
F_30 ( & V_52 ) ;
}
return V_30 ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_52 ) ;
F_33 ( & V_51 ) ;
F_34 ( & V_49 ,
& V_50 ) ;
F_22 ( & V_43 ) ;
}
