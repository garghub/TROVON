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
F_14 ( L_1 ,
V_12 . V_13 ) ;
F_6 ( V_9 ) ;
}
F_15 ( 0 , & V_6 ) ;
V_11 = 0 ;
return 0 ;
}
static T_2 F_16 ( struct V_5 * V_5 , const char T_3 * V_14 ,
T_4 V_15 , T_5 * V_16 )
{
int V_17 ;
if ( V_15 ) {
V_11 = 0 ;
for ( V_17 = 0 ; V_17 != V_15 ; V_17 ++ ) {
char V_18 ;
if ( F_17 ( V_18 , V_14 + V_17 ) )
return - V_19 ;
if ( V_18 == 'V' )
V_11 = 42 ;
}
F_6 ( V_9 ) ;
}
return V_15 ;
}
static long F_18 ( struct V_5 * V_5 , unsigned int V_20 ,
unsigned long V_21 )
{
int V_22 = - V_23 ;
unsigned long time ;
void T_3 * V_24 = ( void T_3 * ) V_21 ;
int T_3 * V_25 = V_24 ;
switch ( V_20 ) {
case V_26 :
V_22 = F_19 ( V_24 , & V_12 , sizeof( V_12 ) ) ? - V_19 : 0 ;
break;
case V_27 :
case V_28 :
V_22 = F_20 ( 0 , V_25 ) ;
break;
case V_29 :
F_6 ( V_9 ) ;
V_22 = 0 ;
break;
case V_30 :
V_22 = F_17 ( time , V_25 ) ;
if ( V_22 )
break;
time *= 1000000 ;
if ( time > 0x7fffffUL ) {
V_22 = - V_31 ;
break;
}
V_10 = time ;
F_1 ( V_9 , V_10 ) ;
F_6 ( V_9 ) ;
case V_32 :
V_22 = F_20 ( F_21 ( V_9 - 8 ) / 1000000 , V_25 ) ;
break;
}
return V_22 ;
}
static int F_22 ( struct V_33 * V_34 , unsigned long V_35 ,
void * erf )
{
if ( V_35 == V_36 || V_35 == V_37 ) {
F_3 ( 0 , V_9 ) ;
F_3 ( 0 , V_38 ) ;
}
return V_39 ;
}
T_6 F_23 ( int V_40 , void * V_41 )
{
unsigned long V_42 ;
char * V_43 = ( char * ) V_41 ;
T_7 V_44 ;
V_44 = F_7 ( V_43 ) ;
V_42 = F_21 ( V_43 - 8 ) & 0x7fffff ;
if ( V_43 == V_9 )
F_14 ( L_2
L_3 ,
V_12 . V_13 ,
V_42 / 1000000 , ( V_42 / 100000 ) % 10 ) ;
else
V_44 |= 1 ;
F_3 ( V_44 , V_43 ) ;
return V_45 ;
}
static int T_8 F_24 ( void )
{
int V_22 ;
V_22 = F_25 ( & V_46 ) ;
if ( V_22 ) {
F_26 ( L_4 ,
V_12 . V_13 , V_22 ) ;
return V_22 ;
}
V_22 = F_27 ( 1 , F_23 , V_47 ,
V_12 . V_13 , ( void * ) V_9 ) ;
if ( V_22 ) {
F_26 ( L_5 ,
V_12 . V_13 , V_22 ) ;
goto V_48;
}
V_22 = F_28 ( & V_49 ) ;
if ( V_22 == 0 ) {
F_29 ( L_6 ,
V_12 . V_13 ,
V_10 / 1000000 , ( V_10 / 100000 ) % 10 ) ;
return 0 ;
}
F_30 ( 1 , ( void * ) V_9 ) ;
V_48:
F_31 ( & V_46 ) ;
return V_22 ;
}
static void T_9 F_32 ( void )
{
F_33 ( & V_49 ) ;
F_30 ( 1 , ( void * ) V_9 ) ;
F_31 ( & V_46 ) ;
}
