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
int V_17 = F_5 ( V_1 -> V_18 . V_19 -> V_20 ) ;
int V_21 = 0 ;
T_2 V_22 = 0 ;
if ( V_12 % 8 )
return - V_10 ;
for (; V_12 ; V_12 -= 8 ) {
V_21 = F_6 ( V_17 , V_16 , & V_15 [ 0 ] , & V_15 [ 1 ] ) ;
if ( V_21 )
break;
if ( F_7 ( V_14 , & V_15 , 8 ) ) {
V_21 = - V_23 ;
break;
}
V_14 += 2 ;
V_22 += 8 ;
}
return V_22 ? V_22 : V_21 ;
}
static T_2 F_8 ( struct V_1 * V_1 , const char T_3 * V_11 ,
T_4 V_12 , T_1 * V_13 )
{
const T_5 T_3 * V_14 = ( const T_5 T_3 * ) V_11 ;
T_5 V_15 [ 2 ] ;
T_5 V_16 = * V_13 ;
int V_17 = F_5 ( V_1 -> V_18 . V_19 -> V_20 ) ;
int V_21 = 0 ;
T_2 V_22 = 0 ;
if ( V_12 % 8 )
return - V_10 ;
for (; V_12 ; V_12 -= 8 ) {
if ( F_9 ( & V_15 , V_14 , 8 ) ) {
V_21 = - V_23 ;
break;
}
V_21 = F_10 ( V_17 , V_16 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
if ( V_21 )
break;
V_14 += 2 ;
V_22 += 8 ;
}
return V_22 ? V_22 : V_21 ;
}
static long F_11 ( struct V_1 * V_1 , unsigned int V_24 , unsigned long V_25 )
{
T_5 T_3 * V_26 = ( T_5 T_3 * ) V_25 ;
T_5 V_27 [ 8 ] ;
int V_17 = F_5 ( V_1 -> V_18 . V_19 -> V_20 ) ;
int V_21 ;
switch ( V_24 ) {
case V_28 :
if ( ! ( V_1 -> V_29 & V_30 ) ) {
V_21 = - V_31 ;
break;
}
if ( F_9 ( & V_27 , V_26 , sizeof V_27 ) ) {
V_21 = - V_23 ;
break;
}
V_21 = F_12 ( V_17 , V_27 ) ;
if ( V_21 )
break;
if ( F_7 ( V_26 , & V_27 , sizeof V_27 ) )
V_21 = - V_23 ;
break;
case V_32 :
if ( ! ( V_1 -> V_29 & V_33 ) ) {
V_21 = - V_31 ;
break;
}
if ( F_9 ( & V_27 , V_26 , sizeof V_27 ) ) {
V_21 = - V_23 ;
break;
}
V_21 = F_13 ( V_17 , V_27 ) ;
if ( V_21 )
break;
if ( F_7 ( V_26 , & V_27 , sizeof V_27 ) )
V_21 = - V_23 ;
break;
default:
V_21 = - V_34 ;
break;
}
return V_21 ;
}
static int F_14 ( struct V_5 * V_5 , struct V_1 * V_1 )
{
unsigned int V_17 ;
struct V_35 * V_36 ;
V_17 = F_5 ( V_1 -> V_18 . V_19 -> V_20 ) ;
if ( V_17 >= V_37 || ! F_15 ( V_17 ) )
return - V_38 ;
V_36 = & F_16 ( V_17 ) ;
if ( ! F_17 ( V_36 , V_39 ) )
return - V_40 ;
return 0 ;
}
static int T_6 F_18 ( int V_17 )
{
struct V_41 * V_42 ;
V_42 = F_19 ( V_43 , NULL , F_20 ( V_44 , V_17 ) , NULL ,
L_1 , V_17 ) ;
return F_21 ( V_42 ) ? F_22 ( V_42 ) : 0 ;
}
static void F_23 ( int V_17 )
{
F_24 ( V_43 , F_20 ( V_44 , V_17 ) ) ;
}
static int T_6 F_25 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
unsigned int V_17 = ( unsigned long ) V_48 ;
int V_21 = 0 ;
switch ( V_47 ) {
case V_49 :
V_21 = F_18 ( V_17 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
F_23 ( V_17 ) ;
break;
}
return F_26 ( V_21 ) ;
}
static char * F_27 ( struct V_41 * V_42 , T_7 * V_53 )
{
return F_28 ( V_54 , L_2 , F_29 ( V_42 -> V_55 ) ) ;
}
static int T_8 F_30 ( void )
{
int V_56 , V_21 = 0 ;
V_56 = 0 ;
if ( F_31 ( V_44 , 0 , V_57 , L_3 , & V_58 ) ) {
F_32 ( V_59 L_4 ,
V_44 ) ;
V_21 = - V_60 ;
goto V_61;
}
V_43 = F_33 ( V_62 , L_5 ) ;
if ( F_21 ( V_43 ) ) {
V_21 = F_22 ( V_43 ) ;
goto V_63;
}
V_43 -> V_64 = F_27 ;
F_34 () ;
F_35 (i) {
V_21 = F_18 ( V_56 ) ;
if ( V_21 != 0 )
goto V_65;
}
F_36 ( & V_66 ) ;
F_37 () ;
V_21 = 0 ;
goto V_61;
V_65:
V_56 = 0 ;
F_35 (i)
F_23 ( V_56 ) ;
F_37 () ;
F_38 ( V_43 ) ;
V_63:
F_39 ( V_44 , 0 , V_57 , L_3 ) ;
V_61:
return V_21 ;
}
static void T_9 F_40 ( void )
{
int V_17 = 0 ;
F_34 () ;
F_35 (cpu)
F_23 ( V_17 ) ;
F_38 ( V_43 ) ;
F_39 ( V_44 , 0 , V_57 , L_3 ) ;
F_41 ( & V_66 ) ;
F_37 () ;
}
