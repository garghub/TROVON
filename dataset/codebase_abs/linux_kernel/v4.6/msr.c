static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_5 T_2 * V_5 = ( T_5 T_2 * ) V_2 ;
T_5 V_6 [ 2 ] ;
T_5 V_7 = * V_4 ;
int V_8 = F_2 ( F_3 ( V_1 ) ) ;
int V_9 = 0 ;
T_1 V_10 = 0 ;
if ( V_3 % 8 )
return - V_11 ;
for (; V_3 ; V_3 -= 8 ) {
V_9 = F_4 ( V_8 , V_7 , & V_6 [ 0 ] , & V_6 [ 1 ] ) ;
if ( V_9 )
break;
if ( F_5 ( V_5 , & V_6 , 8 ) ) {
V_9 = - V_12 ;
break;
}
V_5 += 2 ;
V_10 += 8 ;
}
return V_10 ? V_10 : V_9 ;
}
static T_1 F_6 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
const T_5 T_2 * V_5 = ( const T_5 T_2 * ) V_2 ;
T_5 V_6 [ 2 ] ;
T_5 V_7 = * V_4 ;
int V_8 = F_2 ( F_3 ( V_1 ) ) ;
int V_9 = 0 ;
T_1 V_10 = 0 ;
if ( V_3 % 8 )
return - V_11 ;
for (; V_3 ; V_3 -= 8 ) {
if ( F_7 ( & V_6 , V_5 , 8 ) ) {
V_9 = - V_12 ;
break;
}
V_9 = F_8 ( V_8 , V_7 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
if ( V_9 )
break;
V_5 += 2 ;
V_10 += 8 ;
}
return V_10 ? V_10 : V_9 ;
}
static long F_9 ( struct V_1 * V_1 , unsigned int V_13 , unsigned long V_14 )
{
T_5 T_2 * V_15 = ( T_5 T_2 * ) V_14 ;
T_5 V_16 [ 8 ] ;
int V_8 = F_2 ( F_3 ( V_1 ) ) ;
int V_9 ;
switch ( V_13 ) {
case V_17 :
if ( ! ( V_1 -> V_18 & V_19 ) ) {
V_9 = - V_20 ;
break;
}
if ( F_7 ( & V_16 , V_15 , sizeof V_16 ) ) {
V_9 = - V_12 ;
break;
}
V_9 = F_10 ( V_8 , V_16 ) ;
if ( V_9 )
break;
if ( F_5 ( V_15 , & V_16 , sizeof V_16 ) )
V_9 = - V_12 ;
break;
case V_21 :
if ( ! ( V_1 -> V_18 & V_22 ) ) {
V_9 = - V_20 ;
break;
}
if ( F_7 ( & V_16 , V_15 , sizeof V_16 ) ) {
V_9 = - V_12 ;
break;
}
V_9 = F_11 ( V_8 , V_16 ) ;
if ( V_9 )
break;
if ( F_5 ( V_15 , & V_16 , sizeof V_16 ) )
V_9 = - V_12 ;
break;
default:
V_9 = - V_23 ;
break;
}
return V_9 ;
}
static int F_12 ( struct V_24 * V_24 , struct V_1 * V_1 )
{
unsigned int V_8 = F_2 ( F_3 ( V_1 ) ) ;
struct V_25 * V_26 ;
if ( ! F_13 ( V_27 ) )
return - V_28 ;
if ( V_8 >= V_29 || ! F_14 ( V_8 ) )
return - V_30 ;
V_26 = & F_15 ( V_8 ) ;
if ( ! F_16 ( V_26 , V_31 ) )
return - V_32 ;
return 0 ;
}
static int F_17 ( int V_8 )
{
struct V_33 * V_34 ;
V_34 = F_18 ( V_35 , NULL , F_19 ( V_36 , V_8 ) , NULL ,
L_1 , V_8 ) ;
return F_20 ( V_34 ) ;
}
static void F_21 ( int V_8 )
{
F_22 ( V_35 , F_19 ( V_36 , V_8 ) ) ;
}
static int F_23 ( struct V_37 * V_38 ,
unsigned long V_39 , void * V_40 )
{
unsigned int V_8 = ( unsigned long ) V_40 ;
int V_9 = 0 ;
switch ( V_39 ) {
case V_41 :
V_9 = F_17 ( V_8 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
F_21 ( V_8 ) ;
break;
}
return F_24 ( V_9 ) ;
}
static char * F_25 ( struct V_33 * V_34 , T_6 * V_45 )
{
return F_26 ( V_46 , L_2 , F_27 ( V_34 -> V_47 ) ) ;
}
static int T_7 F_28 ( void )
{
int V_48 , V_9 = 0 ;
V_48 = 0 ;
if ( F_29 ( V_36 , 0 , V_49 , L_3 , & V_50 ) ) {
F_30 ( L_4 , V_36 ) ;
V_9 = - V_51 ;
goto V_52;
}
V_35 = F_31 ( V_53 , L_5 ) ;
if ( F_32 ( V_35 ) ) {
V_9 = F_33 ( V_35 ) ;
goto V_54;
}
V_35 -> V_55 = F_25 ;
F_34 () ;
F_35 (i) {
V_9 = F_17 ( V_48 ) ;
if ( V_9 != 0 )
goto V_56;
}
F_36 ( & V_57 ) ;
F_37 () ;
V_9 = 0 ;
goto V_52;
V_56:
V_48 = 0 ;
F_35 (i)
F_21 ( V_48 ) ;
F_37 () ;
F_38 ( V_35 ) ;
V_54:
F_39 ( V_36 , 0 , V_49 , L_3 ) ;
V_52:
return V_9 ;
}
static void T_8 F_40 ( void )
{
int V_8 = 0 ;
F_34 () ;
F_35 (cpu)
F_21 ( V_8 ) ;
F_38 ( V_35 ) ;
F_39 ( V_36 , 0 , V_49 , L_3 ) ;
F_41 ( & V_57 ) ;
F_37 () ;
}
