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
switch ( V_5 -> V_11 ) {
case 0 :
V_5 -> V_12 = 300 +
( 6720 << V_13 ) / ( 5 * V_14 [ 0 ] + ( 7 << V_13 ) ) ;
V_5 -> V_12 =
F_4 ( V_5 -> V_12 ) ;
V_9 = F_4 ( 70 ) ;
V_5 -> V_11 ++ ;
if ( ! V_5 -> V_15 )
V_7 = V_3 -> V_16 ;
break;
case 1 :
V_9 = V_5 -> V_12 / 4 - F_4 ( 70 ) ;
V_5 -> V_11 ++ ;
if ( V_5 -> V_15 )
V_7 = V_3 -> V_16 ;
break;
case 2 :
V_9 = F_4 ( 70 ) ;
V_5 -> V_11 ++ ;
if ( ! V_5 -> V_15 )
V_7 = V_3 -> V_16 ;
break;
default:
V_9 = V_5 -> V_12 - V_5 -> V_12 / 4 -
F_4 ( 70 ) ;
V_5 -> V_11 = 0 ;
if ( V_5 -> V_15 )
V_7 = V_3 -> V_16 ;
break;
}
F_5 ( V_3 , V_7 ) ;
F_6 ( & V_5 -> V_17 , V_18 + V_9 ) ;
}
static T_1 F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_2 * V_3 = F_8 ( V_20 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
return sprintf ( V_23 , L_1 , V_5 -> V_15 ) ;
}
static T_1 F_9 ( struct V_19 * V_20 ,
struct V_21 * V_22 , const char * V_23 , T_2 V_24 )
{
struct V_2 * V_3 = F_8 ( V_20 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_25 ;
int V_26 ;
V_26 = F_10 ( V_23 , 0 , & V_25 ) ;
if ( V_26 )
return V_26 ;
V_5 -> V_15 = ! ! V_25 ;
return V_24 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_27 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_28 ) ;
if ( ! V_5 )
return;
V_3 -> V_6 = V_5 ;
V_27 = F_13 ( V_3 -> V_20 , & V_29 ) ;
if ( V_27 ) {
F_14 ( V_3 -> V_6 ) ;
return;
}
F_15 ( & V_5 -> V_17 ,
F_1 , ( unsigned long ) V_3 ) ;
V_5 -> V_11 = 0 ;
F_1 ( V_5 -> V_17 . V_1 ) ;
V_3 -> V_30 = true ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_3 -> V_30 ) {
F_17 ( & V_5 -> V_17 ) ;
F_18 ( V_3 -> V_20 , & V_29 ) ;
F_14 ( V_5 ) ;
V_3 -> V_30 = false ;
}
}
static int F_19 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
F_20 ( & V_35 ) ;
return V_36 ;
}
static int F_21 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
V_10 = 1 ;
return V_36 ;
}
static int T_3 F_22 ( void )
{
int V_27 = F_23 ( & V_35 ) ;
if ( ! V_27 ) {
F_24 ( & V_37 ,
& V_38 ) ;
F_25 ( & V_39 ) ;
}
return V_27 ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_39 ) ;
F_28 ( & V_37 ,
& V_38 ) ;
F_20 ( & V_35 ) ;
}
