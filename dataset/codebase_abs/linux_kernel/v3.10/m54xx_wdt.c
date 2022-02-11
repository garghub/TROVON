static void F_1 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 ) ;
if ( V_1 & V_3 )
V_1 &= ( V_3 | V_4
| V_5 ) ;
else
V_1 = V_3 | V_5 ;
F_3 ( V_1 , V_2 ) ;
F_3 ( F_4 ( V_6 * ( V_7 / 0xffff ) ) |
F_5 ( 0xffff ) , V_8 ) ;
V_1 |= F_6 ( 0xA5 ) | V_9 | V_10 ;
F_3 ( V_1 , V_2 ) ;
}
static void F_7 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 &= ~ ( V_9 | V_10 ) ;
F_3 ( V_1 , V_2 ) ;
}
static void F_8 ( void )
{
unsigned int V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= F_6 ( 0xA5 ) ;
F_3 ( V_1 , V_2 ) ;
}
static int F_9 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
if ( F_10 ( V_13 , & V_14 ) )
return - V_15 ;
F_11 ( V_16 , & V_14 ) ;
F_1 () ;
return F_12 ( V_11 , V_12 ) ;
}
static T_1 F_13 ( struct V_12 * V_12 , const char * V_17 ,
T_2 V_18 , T_3 * V_19 )
{
if ( V_18 ) {
if ( ! V_20 ) {
T_2 V_21 ;
F_11 ( V_16 , & V_14 ) ;
for ( V_21 = 0 ; V_21 != V_18 ; V_21 ++ ) {
char V_22 ;
if ( F_14 ( V_22 , V_17 + V_21 ) )
return - V_23 ;
if ( V_22 == 'V' )
F_15 ( V_16 , & V_14 ) ;
}
}
F_8 () ;
}
return V_18 ;
}
static long F_16 ( struct V_12 * V_12 , unsigned int V_24 ,
unsigned long V_25 )
{
int V_26 = - V_27 ;
int time ;
switch ( V_24 ) {
case V_28 :
V_26 = F_17 ( (struct V_29 * ) V_25 , & V_30 ,
sizeof( V_30 ) ) ? - V_23 : 0 ;
break;
case V_31 :
V_26 = F_18 ( 0 , ( int * ) V_25 ) ;
break;
case V_32 :
V_26 = F_18 ( 0 , ( int * ) V_25 ) ;
break;
case V_33 :
F_8 () ;
V_26 = 0 ;
break;
case V_34 :
V_26 = F_14 ( time , ( int * ) V_25 ) ;
if ( V_26 )
break;
if ( time <= 0 || time > 30 ) {
V_26 = - V_35 ;
break;
}
V_6 = time ;
F_1 () ;
case V_36 :
V_26 = F_18 ( V_6 , ( int * ) V_25 ) ;
break;
}
return V_26 ;
}
static int F_19 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
if ( F_20 ( V_16 , & V_14 ) )
F_7 () ;
else {
F_21 ( L_1 ) ;
F_8 () ;
}
F_11 ( V_13 , & V_14 ) ;
F_11 ( V_16 , & V_14 ) ;
return 0 ;
}
static int T_4 F_22 ( void )
{
if ( ! F_23 ( V_8 , 4 , L_2 ) ) {
F_24 ( L_3 ) ;
return - V_15 ;
}
F_25 ( L_4 ) ;
return F_26 ( & V_37 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_37 ) ;
F_29 ( V_8 , 4 ) ;
}
