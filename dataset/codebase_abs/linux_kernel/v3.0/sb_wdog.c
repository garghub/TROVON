void F_1 ( char T_1 * V_1 , unsigned long V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( 0 , V_1 ) ;
F_4 ( V_2 & 0x7fffffUL , V_1 - 0x10 ) ;
F_5 ( & V_3 ) ;
}
void F_6 ( char T_1 * V_1 )
{
F_2 ( & V_3 ) ;
F_3 ( F_7 ( V_1 ) | 1 , V_1 ) ;
F_5 ( & V_3 ) ;
}
static int F_8 ( struct V_4 * V_4 , struct V_5 * V_5 )
{
F_9 ( V_4 , V_5 ) ;
if ( F_10 ( 0 , & V_6 ) )
return - V_7 ;
F_11 ( V_8 ) ;
F_1 ( V_9 , V_10 ) ;
F_3 ( 1 , V_9 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_4 , struct V_5 * V_5 )
{
if ( V_11 == 42 ) {
F_3 ( 0 , V_9 ) ;
F_13 ( V_8 ) ;
} else {
F_14 ( V_12
L_1 ,
V_13 . V_14 ) ;
F_6 ( V_9 ) ;
}
F_15 ( 0 , & V_6 ) ;
V_11 = 0 ;
return 0 ;
}
static T_2 F_16 ( struct V_5 * V_5 , const char T_3 * V_15 ,
T_4 V_16 , T_5 * V_17 )
{
int V_18 ;
if ( V_16 ) {
V_11 = 0 ;
for ( V_18 = 0 ; V_18 != V_16 ; V_18 ++ ) {
char V_19 ;
if ( F_17 ( V_19 , V_15 + V_18 ) )
return - V_20 ;
if ( V_19 == 'V' )
V_11 = 42 ;
}
F_6 ( V_9 ) ;
}
return V_16 ;
}
static long F_18 ( struct V_5 * V_5 , unsigned int V_21 ,
unsigned long V_22 )
{
int V_23 = - V_24 ;
unsigned long time ;
void T_3 * V_25 = ( void T_3 * ) V_22 ;
int T_3 * V_26 = V_25 ;
switch ( V_21 ) {
case V_27 :
V_23 = F_19 ( V_25 , & V_13 , sizeof( V_13 ) ) ? - V_20 : 0 ;
break;
case V_28 :
case V_29 :
V_23 = F_20 ( 0 , V_26 ) ;
break;
case V_30 :
F_6 ( V_9 ) ;
V_23 = 0 ;
break;
case V_31 :
V_23 = F_17 ( time , V_26 ) ;
if ( V_23 )
break;
time *= 1000000 ;
if ( time > 0x7fffffUL ) {
V_23 = - V_32 ;
break;
}
V_10 = time ;
F_1 ( V_9 , V_10 ) ;
F_6 ( V_9 ) ;
case V_33 :
V_23 = F_20 ( F_21 ( V_9 - 8 ) / 1000000 , V_26 ) ;
break;
}
return V_23 ;
}
static int F_22 ( struct V_34 * V_35 , unsigned long V_36 ,
void * erf )
{
if ( V_36 == V_37 || V_36 == V_38 ) {
F_3 ( 0 , V_9 ) ;
F_3 ( 0 , V_39 ) ;
}
return V_40 ;
}
T_6 F_23 ( int V_41 , void * V_42 )
{
unsigned long V_43 ;
char * V_44 = ( char * ) V_42 ;
T_7 V_45 ;
V_45 = F_7 ( V_44 ) ;
V_43 = F_21 ( V_44 - 8 ) & 0x7fffff ;
if ( V_44 == V_9 )
F_14 ( V_12 L_2
L_3 ,
V_13 . V_14 ,
V_43 / 1000000 , ( V_43 / 100000 ) % 10 ) ;
else
V_45 |= 1 ;
F_3 ( V_45 , V_44 ) ;
return V_46 ;
}
static int T_8 F_24 ( void )
{
int V_23 ;
V_23 = F_25 ( & V_47 ) ;
if ( V_23 ) {
F_14 ( V_48
L_4 ,
V_13 . V_14 , V_23 ) ;
return V_23 ;
}
V_23 = F_26 ( 1 , F_23 , V_49 | V_50 ,
V_13 . V_14 , ( void * ) V_9 ) ;
if ( V_23 ) {
F_14 ( V_48 L_5 ,
V_13 . V_14 , V_23 ) ;
goto V_51;
}
V_23 = F_27 ( & V_52 ) ;
if ( V_23 == 0 ) {
F_14 ( V_53 L_6 ,
V_13 . V_14 ,
V_10 / 1000000 , ( V_10 / 100000 ) % 10 ) ;
return 0 ;
}
F_28 ( 1 , ( void * ) V_9 ) ;
V_51:
F_29 ( & V_47 ) ;
return V_23 ;
}
static void T_9 F_30 ( void )
{
F_31 ( & V_52 ) ;
F_28 ( 1 , ( void * ) V_9 ) ;
F_29 ( & V_47 ) ;
}
