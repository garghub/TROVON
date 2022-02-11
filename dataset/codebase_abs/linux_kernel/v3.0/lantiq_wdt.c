static void
F_1 ( void )
{
V_1 = V_1 *
( V_2 / V_3 ) + 0x1000 ;
if ( V_1 > V_4 )
V_1 = V_4 ;
F_2 ( V_5 , V_6 + V_7 ) ;
F_2 ( V_8 | V_9 | V_10 |
V_11 | V_1 , V_6 + V_7 ) ;
}
static void
F_3 ( void )
{
F_2 ( V_5 , V_6 + V_7 ) ;
F_2 ( V_11 , V_6 + V_7 ) ;
}
static T_1
F_4 ( struct V_12 * V_12 , const char T_2 * V_13 ,
T_3 V_14 , T_4 * V_15 )
{
if ( V_14 ) {
if ( ! V_16 ) {
T_3 V_17 ;
V_18 = 0 ;
for ( V_17 = 0 ; V_17 != V_14 ; V_17 ++ ) {
char V_19 ;
if ( F_5 ( V_19 , V_13 + V_17 ) )
return - V_20 ;
if ( V_19 == 'V' )
V_18 = 1 ;
else
V_18 = 0 ;
}
}
F_1 () ;
}
return V_14 ;
}
static long
F_6 ( struct V_12 * V_12 ,
unsigned int V_21 , unsigned long V_22 )
{
int V_23 = - V_24 ;
switch ( V_21 ) {
case V_25 :
V_23 = F_7 ( (struct V_26 T_2 * ) V_22 , & V_27 ,
sizeof( V_27 ) ) ? - V_20 : 0 ;
break;
case V_28 :
V_23 = F_8 ( V_29 , ( int T_2 * ) V_22 ) ;
break;
case V_30 :
V_23 = F_8 ( 0 , ( int T_2 * ) V_22 ) ;
break;
case V_31 :
V_23 = F_5 ( V_1 , ( int T_2 * ) V_22 ) ;
if ( ! V_23 )
F_1 () ;
case V_32 :
V_23 = F_8 ( V_1 , ( int T_2 * ) V_22 ) ;
break;
case V_33 :
F_1 () ;
V_23 = 0 ;
break;
}
return V_23 ;
}
static int
F_9 ( struct V_34 * V_34 , struct V_12 * V_12 )
{
if ( F_10 ( 0 , & V_35 ) )
return - V_36 ;
V_35 = 1 ;
F_1 () ;
return F_11 ( V_34 , V_12 ) ;
}
static int
F_12 ( struct V_34 * V_34 , struct V_12 * V_12 )
{
if ( V_18 )
F_3 () ;
else
F_13 ( L_1 ) ;
V_18 = 0 ;
F_14 ( 0 , & V_35 ) ;
return 0 ;
}
static int T_5
F_15 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_16 ( V_38 , V_41 , 0 ) ;
struct V_42 * V_42 ;
if ( ! V_40 ) {
F_17 ( & V_38 -> V_43 , L_2 ) ;
return - V_44 ;
}
V_40 = F_18 ( & V_38 -> V_43 , V_40 -> V_45 ,
F_19 ( V_40 ) , F_20 ( & V_38 -> V_43 ) ) ;
if ( ! V_40 ) {
F_17 ( & V_38 -> V_43 , L_3 ) ;
return - V_36 ;
}
V_6 = F_21 ( & V_38 -> V_43 , V_40 -> V_45 ,
F_19 ( V_40 ) ) ;
if ( ! V_6 ) {
F_17 ( & V_38 -> V_43 , L_4 ) ;
return - V_46 ;
}
V_42 = F_22 ( & V_38 -> V_43 , L_5 ) ;
F_23 ( ! V_42 ) ;
V_2 = F_24 ( V_42 ) ;
F_25 ( V_42 ) ;
if ( F_26 () == V_47 )
V_29 = V_48 ;
return F_27 ( & V_49 ) ;
}
static int T_6
F_28 ( struct V_37 * V_38 )
{
F_29 ( & V_49 ) ;
if ( V_6 )
F_30 ( V_6 ) ;
return 0 ;
}
static int T_5
F_31 ( void )
{
return F_32 ( & V_50 , F_15 ) ;
}
static void T_7
F_33 ( void )
{
return F_34 ( & V_50 ) ;
}
