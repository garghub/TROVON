static void F_1 ( unsigned char V_1 , unsigned char V_2 )
{
F_2 ( V_2 , V_3 ) ;
F_3 ( 200 ) ;
F_2 ( V_1 , V_4 ) ;
F_3 ( 100 ) ;
}
static void F_4 ( void )
{
F_5 ( & V_5 ) ;
F_1 ( V_6 , 1 ) ;
F_1 ( V_7 , V_8 ) ;
F_6 ( & V_5 ) ;
}
static void F_7 ( void )
{
F_5 ( & V_5 ) ;
F_1 ( V_6 , 0 ) ;
F_1 ( V_7 , 0 ) ;
F_6 ( & V_5 ) ;
}
static int F_8 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
if ( F_9 ( V_11 , & V_12 ) )
return - V_13 ;
F_10 ( V_14 , & V_12 ) ;
F_4 () ;
return F_11 ( V_9 , V_10 ) ;
}
static T_1 F_12 ( struct V_10 * V_10 , const char * V_2 ,
T_2 V_15 , T_3 * V_16 )
{
T_2 V_17 ;
if ( ! V_15 )
return 0 ;
if ( V_18 ) {
V_15 = 0 ;
goto V_19;
}
F_10 ( V_14 , & V_12 ) ;
for ( V_17 = 0 ; V_17 != V_15 ; V_17 ++ ) {
char V_20 ;
if ( F_13 ( V_20 , V_2 + V_17 ) )
return - V_21 ;
if ( V_20 == 'V' )
F_14 ( V_14 , & V_12 ) ;
}
V_19:
F_4 () ;
return V_15 ;
}
static long F_15 ( struct V_10 * V_10 , unsigned int V_22 ,
unsigned long V_23 )
{
int V_24 = - V_25 ;
int time ;
switch ( V_22 ) {
case V_26 :
V_24 = F_16 ( (struct V_27 * ) V_23 , & V_28 ,
sizeof( V_28 ) ) ? - V_21 : 0 ;
break;
case V_29 :
V_24 = F_17 ( 0 , ( int * ) V_23 ) ;
break;
case V_30 :
V_24 = F_17 ( 0 , ( int * ) V_23 ) ;
break;
case V_31 :
F_4 () ;
V_24 = 0 ;
break;
case V_32 :
V_24 = F_13 ( time , ( int * ) V_23 ) ;
if ( V_24 )
break;
if ( time < 31 || time > 255 ) {
V_24 = - V_33 ;
break;
}
V_8 = time ;
F_4 () ;
case V_34 :
V_24 = F_17 ( V_8 , ( int * ) V_23 ) ;
break;
}
return V_24 ;
}
static int F_18 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
if ( F_19 ( V_14 , & V_12 ) ) {
F_7 () ;
F_20 ( L_1 ) ;
} else {
F_21 ( L_2 ) ;
F_4 () ;
}
F_10 ( V_11 , & V_12 ) ;
F_10 ( V_14 , & V_12 ) ;
return 0 ;
}
static int T_4 F_22 ( void )
{
int V_35 ;
const char * V_36 ;
V_36 = F_23 ( V_37 ) ;
if ( ! V_36 || ! strstr ( V_36 , L_3 ) )
return - V_38 ;
F_20 ( L_4 , V_36 ) ;
if ( ! F_24 ( V_4 , 1 , V_39 ) ) {
F_25 ( L_5 , V_4 ) ;
return - V_40 ;
}
if ( ! F_24 ( V_3 , 1 , V_39 ) ) {
F_25 ( L_5 , V_3 ) ;
V_35 = - V_40 ;
goto V_41;
}
if ( V_8 < 31 || V_8 > 255 ) {
F_25 ( L_6 ,
V_8 ) ;
V_35 = - V_33 ;
goto V_42;
}
V_35 = F_26 ( & V_43 ) ;
if ( V_35 ) {
F_25 ( L_7 ,
V_44 , V_35 ) ;
goto V_42;
}
return 0 ;
V_42:
F_27 ( V_3 , 1 ) ;
V_41:
F_27 ( V_4 , 1 ) ;
return V_35 ;
}
static void T_5 F_28 ( void )
{
F_29 ( & V_43 ) ;
F_27 ( V_3 , 1 ) ;
F_27 ( V_4 , 1 ) ;
}
