static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
T_1 V_4 ;
struct V_5 * V_5 = F_2 ( V_1 ) ;
F_3 ( & V_5 -> V_6 ) ;
switch ( V_3 ) {
case 0 :
V_1 -> V_7 = V_2 ;
V_4 = V_1 -> V_7 ;
break;
case 1 :
V_1 -> V_7 += V_2 ;
V_4 = V_1 -> V_7 ;
break;
default:
V_4 = - V_8 ;
}
F_4 ( & V_5 -> V_6 ) ;
return V_4 ;
}
static T_2 F_5 ( struct V_1 * V_1 , char T_3 * V_9 ,
T_4 V_10 , T_1 * V_11 )
{
T_5 T_3 * V_12 = ( T_5 T_3 * ) V_9 ;
T_5 V_13 [ 2 ] ;
T_5 V_14 = * V_11 ;
int V_15 = F_6 ( F_2 ( V_1 ) ) ;
int V_16 = 0 ;
T_2 V_17 = 0 ;
if ( V_10 % 8 )
return - V_8 ;
for (; V_10 ; V_10 -= 8 ) {
V_16 = F_7 ( V_15 , V_14 , & V_13 [ 0 ] , & V_13 [ 1 ] ) ;
if ( V_16 )
break;
if ( F_8 ( V_12 , & V_13 , 8 ) ) {
V_16 = - V_18 ;
break;
}
V_12 += 2 ;
V_17 += 8 ;
}
return V_17 ? V_17 : V_16 ;
}
static T_2 F_9 ( struct V_1 * V_1 , const char T_3 * V_9 ,
T_4 V_10 , T_1 * V_11 )
{
const T_5 T_3 * V_12 = ( const T_5 T_3 * ) V_9 ;
T_5 V_13 [ 2 ] ;
T_5 V_14 = * V_11 ;
int V_15 = F_6 ( F_2 ( V_1 ) ) ;
int V_16 = 0 ;
T_2 V_17 = 0 ;
if ( V_10 % 8 )
return - V_8 ;
for (; V_10 ; V_10 -= 8 ) {
if ( F_10 ( & V_13 , V_12 , 8 ) ) {
V_16 = - V_18 ;
break;
}
V_16 = F_11 ( V_15 , V_14 , V_13 [ 0 ] , V_13 [ 1 ] ) ;
if ( V_16 )
break;
V_12 += 2 ;
V_17 += 8 ;
}
return V_17 ? V_17 : V_16 ;
}
static long F_12 ( struct V_1 * V_1 , unsigned int V_19 , unsigned long V_20 )
{
T_5 T_3 * V_21 = ( T_5 T_3 * ) V_20 ;
T_5 V_22 [ 8 ] ;
int V_15 = F_6 ( F_2 ( V_1 ) ) ;
int V_16 ;
switch ( V_19 ) {
case V_23 :
if ( ! ( V_1 -> V_24 & V_25 ) ) {
V_16 = - V_26 ;
break;
}
if ( F_10 ( & V_22 , V_21 , sizeof V_22 ) ) {
V_16 = - V_18 ;
break;
}
V_16 = F_13 ( V_15 , V_22 ) ;
if ( V_16 )
break;
if ( F_8 ( V_21 , & V_22 , sizeof V_22 ) )
V_16 = - V_18 ;
break;
case V_27 :
if ( ! ( V_1 -> V_24 & V_28 ) ) {
V_16 = - V_26 ;
break;
}
if ( F_10 ( & V_22 , V_21 , sizeof V_22 ) ) {
V_16 = - V_18 ;
break;
}
V_16 = F_14 ( V_15 , V_22 ) ;
if ( V_16 )
break;
if ( F_8 ( V_21 , & V_22 , sizeof V_22 ) )
V_16 = - V_18 ;
break;
default:
V_16 = - V_29 ;
break;
}
return V_16 ;
}
static int F_15 ( struct V_5 * V_5 , struct V_1 * V_1 )
{
unsigned int V_15 = F_6 ( F_2 ( V_1 ) ) ;
struct V_30 * V_31 ;
if ( ! F_16 ( V_32 ) )
return - V_33 ;
if ( V_15 >= V_34 || ! F_17 ( V_15 ) )
return - V_35 ;
V_31 = & F_18 ( V_15 ) ;
if ( ! F_19 ( V_31 , V_36 ) )
return - V_37 ;
return 0 ;
}
static int F_20 ( int V_15 )
{
struct V_38 * V_39 ;
V_39 = F_21 ( V_40 , NULL , F_22 ( V_41 , V_15 ) , NULL ,
L_1 , V_15 ) ;
return F_23 ( V_39 ) ? F_24 ( V_39 ) : 0 ;
}
static void F_25 ( int V_15 )
{
F_26 ( V_40 , F_22 ( V_41 , V_15 ) ) ;
}
static int F_27 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
unsigned int V_15 = ( unsigned long ) V_45 ;
int V_16 = 0 ;
switch ( V_44 ) {
case V_46 :
V_16 = F_20 ( V_15 ) ;
break;
case V_47 :
case V_48 :
case V_49 :
F_25 ( V_15 ) ;
break;
}
return F_28 ( V_16 ) ;
}
static char * F_29 ( struct V_38 * V_39 , T_6 * V_50 )
{
return F_30 ( V_51 , L_2 , F_31 ( V_39 -> V_52 ) ) ;
}
static int T_7 F_32 ( void )
{
int V_53 , V_16 = 0 ;
V_53 = 0 ;
if ( F_33 ( V_41 , 0 , V_54 , L_3 , & V_55 ) ) {
F_34 ( V_56 L_4 ,
V_41 ) ;
V_16 = - V_57 ;
goto V_58;
}
V_40 = F_35 ( V_59 , L_5 ) ;
if ( F_23 ( V_40 ) ) {
V_16 = F_24 ( V_40 ) ;
goto V_60;
}
V_40 -> V_61 = F_29 ;
F_36 () ;
F_37 (i) {
V_16 = F_20 ( V_53 ) ;
if ( V_16 != 0 )
goto V_62;
}
F_38 ( & V_63 ) ;
F_39 () ;
V_16 = 0 ;
goto V_58;
V_62:
V_53 = 0 ;
F_37 (i)
F_25 ( V_53 ) ;
F_39 () ;
F_40 ( V_40 ) ;
V_60:
F_41 ( V_41 , 0 , V_54 , L_3 ) ;
V_58:
return V_16 ;
}
static void T_8 F_42 ( void )
{
int V_15 = 0 ;
F_36 () ;
F_37 (cpu)
F_25 ( V_15 ) ;
F_40 ( V_40 ) ;
F_41 ( V_41 , 0 , V_54 , L_3 ) ;
F_43 ( & V_63 ) ;
F_39 () ;
}
