static void F_1 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
if ( V_1 & V_4 )
V_1 &= ( V_4 | V_5
| V_6 ) ;
else
V_1 = V_4 | V_6 ;
F_3 ( V_1 , V_2 + V_3 ) ;
F_3 ( F_4 ( V_7 * ( V_8 / 0xffff ) ) |
F_5 ( 0xffff ) , V_2 + V_9 ) ;
V_1 |= F_6 ( 0xA5 ) | V_10 | V_11 ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static void F_7 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
V_1 &= ~ ( V_10 | V_11 ) ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static void F_8 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
V_1 |= F_6 ( 0xA5 ) ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static int F_9 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_10 ( V_14 , & V_15 ) )
return - V_16 ;
F_11 ( V_17 , & V_15 ) ;
F_1 () ;
return F_12 ( V_12 , V_13 ) ;
}
static T_1 F_13 ( struct V_13 * V_13 , const char * V_18 ,
T_2 V_19 , T_3 * V_20 )
{
if ( V_19 ) {
if ( ! V_21 ) {
T_2 V_22 ;
F_11 ( V_17 , & V_15 ) ;
for ( V_22 = 0 ; V_22 != V_19 ; V_22 ++ ) {
char V_23 ;
if ( F_14 ( V_23 , V_18 + V_22 ) )
return - V_24 ;
if ( V_23 == 'V' )
F_15 ( V_17 , & V_15 ) ;
}
}
F_8 () ;
}
return V_19 ;
}
static long F_16 ( struct V_13 * V_13 , unsigned int V_25 ,
unsigned long V_26 )
{
int V_27 = - V_28 ;
int time ;
switch ( V_25 ) {
case V_29 :
V_27 = F_17 ( (struct V_30 * ) V_26 , & V_31 ,
sizeof( V_31 ) ) ? - V_24 : 0 ;
break;
case V_32 :
V_27 = F_18 ( 0 , ( int * ) V_26 ) ;
break;
case V_33 :
V_27 = F_18 ( 0 , ( int * ) V_26 ) ;
break;
case V_34 :
F_8 () ;
V_27 = 0 ;
break;
case V_35 :
V_27 = F_14 ( time , ( int * ) V_26 ) ;
if ( V_27 )
break;
if ( time <= 0 || time > 30 ) {
V_27 = - V_36 ;
break;
}
V_7 = time ;
F_1 () ;
case V_37 :
V_27 = F_18 ( V_7 , ( int * ) V_26 ) ;
break;
}
return V_27 ;
}
static int F_19 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_20 ( V_17 , & V_15 ) )
F_7 () ;
else {
F_21 ( L_1 ) ;
F_8 () ;
}
F_11 ( V_14 , & V_15 ) ;
F_11 ( V_17 , & V_15 ) ;
return 0 ;
}
static int T_4 F_22 ( void )
{
if ( ! F_23 ( V_2 + V_9 , 4 ,
L_2 ) ) {
F_24 ( L_3 ) ;
return - V_16 ;
}
F_25 ( L_4 ) ;
return F_26 ( & V_38 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_38 ) ;
F_29 ( V_2 + V_9 , 4 ) ;
}
