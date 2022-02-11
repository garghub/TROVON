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
if ( ! F_15 ( V_37 ) )
return - V_38 ;
V_17 = F_5 ( V_1 -> V_18 . V_19 -> V_20 ) ;
if ( V_17 >= V_39 || ! F_16 ( V_17 ) )
return - V_40 ;
V_36 = & F_17 ( V_17 ) ;
if ( ! F_18 ( V_36 , V_41 ) )
return - V_42 ;
return 0 ;
}
static int T_6 F_19 ( int V_17 )
{
struct V_43 * V_44 ;
V_44 = F_20 ( V_45 , NULL , F_21 ( V_46 , V_17 ) , NULL ,
L_1 , V_17 ) ;
return F_22 ( V_44 ) ? F_23 ( V_44 ) : 0 ;
}
static void F_24 ( int V_17 )
{
F_25 ( V_45 , F_21 ( V_46 , V_17 ) ) ;
}
static int T_6 F_26 ( struct V_47 * V_48 ,
unsigned long V_49 , void * V_50 )
{
unsigned int V_17 = ( unsigned long ) V_50 ;
int V_21 = 0 ;
switch ( V_49 ) {
case V_51 :
V_21 = F_19 ( V_17 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
F_24 ( V_17 ) ;
break;
}
return F_27 ( V_21 ) ;
}
static char * F_28 ( struct V_43 * V_44 , T_7 * V_55 )
{
return F_29 ( V_56 , L_2 , F_30 ( V_44 -> V_57 ) ) ;
}
static int T_8 F_31 ( void )
{
int V_58 , V_21 = 0 ;
V_58 = 0 ;
if ( F_32 ( V_46 , 0 , V_59 , L_3 , & V_60 ) ) {
F_33 ( V_61 L_4 ,
V_46 ) ;
V_21 = - V_62 ;
goto V_63;
}
V_45 = F_34 ( V_64 , L_5 ) ;
if ( F_22 ( V_45 ) ) {
V_21 = F_23 ( V_45 ) ;
goto V_65;
}
V_45 -> V_66 = F_28 ;
F_35 () ;
F_36 (i) {
V_21 = F_19 ( V_58 ) ;
if ( V_21 != 0 )
goto V_67;
}
F_37 ( & V_68 ) ;
F_38 () ;
V_21 = 0 ;
goto V_63;
V_67:
V_58 = 0 ;
F_36 (i)
F_24 ( V_58 ) ;
F_38 () ;
F_39 ( V_45 ) ;
V_65:
F_40 ( V_46 , 0 , V_59 , L_3 ) ;
V_63:
return V_21 ;
}
static void T_9 F_41 ( void )
{
int V_17 = 0 ;
F_35 () ;
F_36 (cpu)
F_24 ( V_17 ) ;
F_39 ( V_45 ) ;
F_40 ( V_46 , 0 , V_59 , L_3 ) ;
F_42 ( & V_68 ) ;
F_38 () ;
}
