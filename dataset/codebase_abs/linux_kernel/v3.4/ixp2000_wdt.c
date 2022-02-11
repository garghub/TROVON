static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_2 , * ( V_2 ) | V_3 ) ;
F_3 ( V_4 , V_5 ) ;
F_3 ( V_6 , V_7 * V_8 ) ;
F_3 ( V_9 , V_10 | V_11 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_9 , 0 ) ;
F_4 ( & V_1 ) ;
}
static void F_6 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_6 , V_7 * V_8 ) ;
F_4 ( & V_1 ) ;
}
static int F_7 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_8 ( V_14 , & V_15 ) )
return - V_16 ;
F_9 ( V_17 , & V_15 ) ;
F_1 () ;
return F_10 ( V_12 , V_13 ) ;
}
static T_1 F_11 ( struct V_13 * V_13 , const char * V_18 ,
T_2 V_19 , T_3 * V_20 )
{
if ( V_19 ) {
if ( ! V_21 ) {
T_2 V_22 ;
F_9 ( V_17 , & V_15 ) ;
for ( V_22 = 0 ; V_22 != V_19 ; V_22 ++ ) {
char V_23 ;
if ( F_12 ( V_23 , V_18 + V_22 ) )
return - V_24 ;
if ( V_23 == 'V' )
F_13 ( V_17 , & V_15 ) ;
}
}
F_6 () ;
}
return V_19 ;
}
static long F_14 ( struct V_13 * V_13 , unsigned int V_25 ,
unsigned long V_26 )
{
int V_27 = - V_28 ;
int time ;
switch ( V_25 ) {
case V_29 :
V_27 = F_15 ( (struct V_30 * ) V_26 , & V_31 ,
sizeof( V_31 ) ) ? - V_24 : 0 ;
break;
case V_32 :
V_27 = F_16 ( 0 , ( int * ) V_26 ) ;
break;
case V_33 :
V_27 = F_16 ( 0 , ( int * ) V_26 ) ;
break;
case V_34 :
F_1 () ;
V_27 = 0 ;
break;
case V_35 :
V_27 = F_12 ( time , ( int * ) V_26 ) ;
if ( V_27 )
break;
if ( time <= 0 || time > 60 ) {
V_27 = - V_36 ;
break;
}
V_7 = time ;
F_6 () ;
case V_37 :
V_27 = F_16 ( V_7 , ( int * ) V_26 ) ;
break;
}
return V_27 ;
}
static int F_17 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_18 ( V_17 , & V_15 ) )
F_5 () ;
else
F_19 ( L_1 ) ;
F_9 ( V_14 , & V_15 ) ;
F_9 ( V_17 , & V_15 ) ;
return 0 ;
}
static int T_4 F_20 ( void )
{
if ( ( * V_38 & 0x001ffef0 ) == 0x00000000 ) {
F_21 ( L_2 ) ;
return - V_39 ;
}
V_8 = ( * V_40 * V_41 ) / 256 ;
return F_22 ( & V_42 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_42 ) ;
}
