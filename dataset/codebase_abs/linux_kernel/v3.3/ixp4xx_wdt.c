static void F_1 ( void )
{
F_2 ( & V_1 ) ;
* V_2 = V_3 ;
* V_4 = 0 ;
* V_5 = V_6 * V_7 ;
* V_4 = V_8 | V_9 ;
* V_2 = 0 ;
F_3 ( & V_1 ) ;
}
static void F_4 ( void )
{
F_2 ( & V_1 ) ;
* V_2 = V_3 ;
* V_4 = 0 ;
* V_2 = 0 ;
F_3 ( & V_1 ) ;
}
static int F_5 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( F_6 ( V_12 , & V_13 ) )
return - V_14 ;
F_7 ( V_15 , & V_13 ) ;
F_1 () ;
return F_8 ( V_10 , V_11 ) ;
}
static T_1
F_9 ( struct V_11 * V_11 , const char * V_16 , T_2 V_17 , T_3 * V_18 )
{
if ( V_17 ) {
if ( ! V_19 ) {
T_2 V_20 ;
F_7 ( V_15 , & V_13 ) ;
for ( V_20 = 0 ; V_20 != V_17 ; V_20 ++ ) {
char V_21 ;
if ( F_10 ( V_21 , V_16 + V_20 ) )
return - V_22 ;
if ( V_21 == 'V' )
F_11 ( V_15 , & V_13 ) ;
}
}
F_1 () ;
}
return V_17 ;
}
static long F_12 ( struct V_11 * V_11 , unsigned int V_23 ,
unsigned long V_24 )
{
int V_25 = - V_26 ;
int time ;
switch ( V_23 ) {
case V_27 :
V_25 = F_13 ( (struct V_28 * ) V_24 , & V_29 ,
sizeof( V_29 ) ) ? - V_22 : 0 ;
break;
case V_30 :
V_25 = F_14 ( 0 , ( int * ) V_24 ) ;
break;
case V_31 :
V_25 = F_14 ( V_32 , ( int * ) V_24 ) ;
break;
case V_33 :
F_1 () ;
V_25 = 0 ;
break;
case V_34 :
V_25 = F_10 ( time , ( int * ) V_24 ) ;
if ( V_25 )
break;
if ( time <= 0 || time > 60 ) {
V_25 = - V_35 ;
break;
}
V_7 = time ;
F_1 () ;
case V_36 :
V_25 = F_14 ( V_7 , ( int * ) V_24 ) ;
break;
}
return V_25 ;
}
static int F_15 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( F_16 ( V_15 , & V_13 ) )
F_4 () ;
else
F_17 ( V_37 L_1
L_2 ) ;
F_7 ( V_12 , & V_13 ) ;
F_7 ( V_15 , & V_13 ) ;
return 0 ;
}
static int T_4 F_18 ( void )
{
int V_25 ;
if ( ! ( F_19 () & 0xf ) && ! F_20 () ) {
F_17 ( V_38 L_3
L_4 ) ;
return - V_39 ;
}
V_32 = ( * V_40 & V_41 ) ?
V_42 : 0 ;
V_25 = F_21 ( & V_43 ) ;
if ( V_25 == 0 )
F_17 ( V_44 L_5 ,
V_7 ) ;
return V_25 ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_43 ) ;
}
