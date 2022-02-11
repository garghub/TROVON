static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
unsigned int V_7 = V_2 -> V_8 ;
unsigned long V_9 = F_2 ( V_5 , NULL , 16 ) ;
#ifdef F_3
F_4 ( V_10 L_1 , V_7 ) ;
F_4 ( V_10 L_2 , V_11 [ V_7 ] ) ;
F_4 ( V_10 L_3 , V_12 [ V_7 ] ) ;
F_4 ( V_10 L_4 ,
V_13 [ V_7 ] . V_14 ,
V_13 [ V_7 ] . V_15 ,
V_13 [ V_7 ] . V_16 ) ;
#endif
switch ( V_9 ) {
case 0 :
break;
case 1 :
V_17 [ V_7 ] = F_5 ( V_11 [ V_7 ] ,
V_12 [ V_7 ] ,
F_6 ( & V_13 [ V_7 ] ) ,
& V_18 [ V_7 ] ,
& V_19 [ V_7 ] ) ;
break;
case 2 :
V_17 [ V_7 ] = F_7 ( V_11 [ V_7 ] ,
V_12 [ V_7 ] ,
F_6 ( & V_13 [ V_7 ] ) ,
& V_18 [ V_7 ] ,
& V_19 [ V_7 ] ) ;
break;
default:
V_17 [ V_7 ] = - V_20 ;
break;
}
#ifdef F_3
F_4 ( V_10 L_5 , ( int ) V_17 [ V_7 ] ) ;
F_4 ( V_10 L_6 , V_18 [ V_7 ] ) ;
F_4 ( V_10 L_7 , V_19 [ V_7 ] ) ;
#endif
return V_6 ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
unsigned int V_7 = V_2 -> V_8 ;
return sprintf ( V_5 , L_8 , V_21 [ V_7 ] ) ;
}
static T_1
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
unsigned int V_7 = V_2 -> V_8 ;
T_3 V_22 = F_2 ( V_5 , NULL , 16 ) ;
int V_23 ;
V_23 = F_10 ( V_24 , V_24 -> V_25 , V_22 ,
1 , V_26 , 0 , NULL , NULL ) ;
if ( V_23 <= 0 ) {
#ifdef F_3
F_4 ( L_9 , V_22 ) ;
#endif
return - V_20 ;
}
V_21 [ V_7 ] = F_6 ( V_22 ) ;
return V_6 ;
}
static T_1
F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
unsigned int V_7 = V_2 -> V_8 ;
return sprintf ( V_5 , L_10 ,
V_13 [ V_7 ] . V_14 ,
V_13 [ V_7 ] . V_15 ,
V_13 [ V_7 ] . V_16 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
unsigned int V_7 = V_2 -> V_8 ;
int V_23 ;
#ifdef F_3
F_4 ( L_11 ,
V_13 [ V_7 ] . V_14 ,
V_13 [ V_7 ] . V_15 ,
V_13 [ V_7 ] . V_16 ,
V_7 ) ;
#endif
V_23 = sscanf ( V_5 , L_12 ,
& V_13 [ V_7 ] . V_14 ,
& V_13 [ V_7 ] . V_15 ,
& V_13 [ V_7 ] . V_16 ) ;
if ( V_23 != V_27 )
return - V_20 ;
return V_6 ;
}
static int F_13 ( struct V_1 * V_28 )
{
return F_14 ( & V_28 -> V_29 , & V_30 ) ;
}
static int F_15 ( struct V_1 * V_28 )
{
F_16 ( & V_28 -> V_29 , & V_30 ) ;
return 0 ;
}
static int F_17 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
unsigned int V_7 = ( unsigned long ) V_34 ;
struct V_1 * V_28 ;
V_28 = F_18 ( V_7 ) ;
switch ( V_33 ) {
case V_35 :
case V_36 :
F_13 ( V_28 ) ;
break;
case V_37 :
case V_38 :
F_15 ( V_28 ) ;
break;
}
return V_39 ;
}
static int T_4
F_19 ( void )
{
int V_40 ;
#ifdef F_3
F_4 ( V_41 L_13 ) ;
#endif
F_20 (i) {
F_17 ( & V_42 , V_35 ,
( void * ) ( long ) V_40 ) ;
}
F_21 ( & V_42 ) ;
return 0 ;
}
static void T_5
F_22 ( void )
{
int V_40 ;
struct V_1 * V_28 ;
#ifdef F_3
F_4 ( V_41 L_14 ) ;
#endif
F_20 (i) {
V_28 = F_18 ( V_40 ) ;
F_16 ( & V_28 -> V_29 , & V_30 ) ;
}
F_23 ( & V_42 ) ;
}
