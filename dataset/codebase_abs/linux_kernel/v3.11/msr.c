static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
T_1 V_4 ;
struct V_5 * V_5 = V_1 -> V_6 -> V_7 ;
F_2 ( & V_5 -> V_8 ) ;
switch ( V_3 ) {
case 0 :
V_1 -> V_9 = V_2 ;
V_4 = V_1 -> V_9 ;
break;
case 1 :
V_1 -> V_9 += V_2 ;
V_4 = V_1 -> V_9 ;
break;
default:
V_4 = - V_10 ;
}
F_3 ( & V_5 -> V_8 ) ;
return V_4 ;
}
static T_2 F_4 ( struct V_1 * V_1 , char T_3 * V_11 ,
T_4 V_12 , T_1 * V_13 )
{
T_5 T_3 * V_14 = ( T_5 T_3 * ) V_11 ;
T_5 V_15 [ 2 ] ;
T_5 V_16 = * V_13 ;
int V_17 = F_5 ( F_6 ( V_1 ) ) ;
int V_18 = 0 ;
T_2 V_19 = 0 ;
if ( V_12 % 8 )
return - V_10 ;
for (; V_12 ; V_12 -= 8 ) {
V_18 = F_7 ( V_17 , V_16 , & V_15 [ 0 ] , & V_15 [ 1 ] ) ;
if ( V_18 )
break;
if ( F_8 ( V_14 , & V_15 , 8 ) ) {
V_18 = - V_20 ;
break;
}
V_14 += 2 ;
V_19 += 8 ;
}
return V_19 ? V_19 : V_18 ;
}
static T_2 F_9 ( struct V_1 * V_1 , const char T_3 * V_11 ,
T_4 V_12 , T_1 * V_13 )
{
const T_5 T_3 * V_14 = ( const T_5 T_3 * ) V_11 ;
T_5 V_15 [ 2 ] ;
T_5 V_16 = * V_13 ;
int V_17 = F_5 ( F_6 ( V_1 ) ) ;
int V_18 = 0 ;
T_2 V_19 = 0 ;
if ( V_12 % 8 )
return - V_10 ;
for (; V_12 ; V_12 -= 8 ) {
if ( F_10 ( & V_15 , V_14 , 8 ) ) {
V_18 = - V_20 ;
break;
}
V_18 = F_11 ( V_17 , V_16 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
if ( V_18 )
break;
V_14 += 2 ;
V_19 += 8 ;
}
return V_19 ? V_19 : V_18 ;
}
static long F_12 ( struct V_1 * V_1 , unsigned int V_21 , unsigned long V_22 )
{
T_5 T_3 * V_23 = ( T_5 T_3 * ) V_22 ;
T_5 V_24 [ 8 ] ;
int V_17 = F_5 ( F_6 ( V_1 ) ) ;
int V_18 ;
switch ( V_21 ) {
case V_25 :
if ( ! ( V_1 -> V_26 & V_27 ) ) {
V_18 = - V_28 ;
break;
}
if ( F_10 ( & V_24 , V_23 , sizeof V_24 ) ) {
V_18 = - V_20 ;
break;
}
V_18 = F_13 ( V_17 , V_24 ) ;
if ( V_18 )
break;
if ( F_8 ( V_23 , & V_24 , sizeof V_24 ) )
V_18 = - V_20 ;
break;
case V_29 :
if ( ! ( V_1 -> V_26 & V_30 ) ) {
V_18 = - V_28 ;
break;
}
if ( F_10 ( & V_24 , V_23 , sizeof V_24 ) ) {
V_18 = - V_20 ;
break;
}
V_18 = F_14 ( V_17 , V_24 ) ;
if ( V_18 )
break;
if ( F_8 ( V_23 , & V_24 , sizeof V_24 ) )
V_18 = - V_20 ;
break;
default:
V_18 = - V_31 ;
break;
}
return V_18 ;
}
static int F_15 ( struct V_5 * V_5 , struct V_1 * V_1 )
{
unsigned int V_17 = F_5 ( F_6 ( V_1 ) ) ;
struct V_32 * V_33 ;
if ( ! F_16 ( V_34 ) )
return - V_35 ;
if ( V_17 >= V_36 || ! F_17 ( V_17 ) )
return - V_37 ;
V_33 = & F_18 ( V_17 ) ;
if ( ! F_19 ( V_33 , V_38 ) )
return - V_39 ;
return 0 ;
}
static int F_20 ( int V_17 )
{
struct V_40 * V_41 ;
V_41 = F_21 ( V_42 , NULL , F_22 ( V_43 , V_17 ) , NULL ,
L_1 , V_17 ) ;
return F_23 ( V_41 ) ? F_24 ( V_41 ) : 0 ;
}
static void F_25 ( int V_17 )
{
F_26 ( V_42 , F_22 ( V_43 , V_17 ) ) ;
}
static int F_27 ( struct V_44 * V_45 ,
unsigned long V_46 , void * V_47 )
{
unsigned int V_17 = ( unsigned long ) V_47 ;
int V_18 = 0 ;
switch ( V_46 ) {
case V_48 :
V_18 = F_20 ( V_17 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
F_25 ( V_17 ) ;
break;
}
return F_28 ( V_18 ) ;
}
static char * F_29 ( struct V_40 * V_41 , T_6 * V_52 )
{
return F_30 ( V_53 , L_2 , F_31 ( V_41 -> V_54 ) ) ;
}
static int T_7 F_32 ( void )
{
int V_55 , V_18 = 0 ;
V_55 = 0 ;
if ( F_33 ( V_43 , 0 , V_56 , L_3 , & V_57 ) ) {
F_34 ( V_58 L_4 ,
V_43 ) ;
V_18 = - V_59 ;
goto V_60;
}
V_42 = F_35 ( V_61 , L_5 ) ;
if ( F_23 ( V_42 ) ) {
V_18 = F_24 ( V_42 ) ;
goto V_62;
}
V_42 -> V_63 = F_29 ;
F_36 () ;
F_37 (i) {
V_18 = F_20 ( V_55 ) ;
if ( V_18 != 0 )
goto V_64;
}
F_38 ( & V_65 ) ;
F_39 () ;
V_18 = 0 ;
goto V_60;
V_64:
V_55 = 0 ;
F_37 (i)
F_25 ( V_55 ) ;
F_39 () ;
F_40 ( V_42 ) ;
V_62:
F_41 ( V_43 , 0 , V_56 , L_3 ) ;
V_60:
return V_18 ;
}
static void T_8 F_42 ( void )
{
int V_17 = 0 ;
F_36 () ;
F_37 (cpu)
F_25 ( V_17 ) ;
F_40 ( V_42 ) ;
F_41 ( V_43 , 0 , V_56 , L_3 ) ;
F_43 ( & V_65 ) ;
F_39 () ;
}
