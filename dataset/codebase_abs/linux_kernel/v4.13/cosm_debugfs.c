static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
void T_1 * V_4 ;
int T_1 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
void * V_9 ;
int V_10 ;
T_2 V_11 ;
if ( ! V_7 || ! V_7 -> V_12 || ! V_7 -> V_13 )
goto V_14;
F_2 ( & V_7 -> V_15 ) ;
switch ( V_7 -> V_16 ) {
case V_17 :
case V_18 :
case V_19 :
break;
default:
goto V_20;
}
V_11 = ( T_2 ) V_7 -> V_13 - V_21 ;
V_5 = V_7 -> V_22 -> V_23 ( V_7 ) -> V_24 + V_11 ;
V_11 = ( T_2 ) V_7 -> V_12 - V_21 ;
V_4 = V_7 -> V_22 -> V_23 ( V_7 ) -> V_24 + V_11 ;
V_10 = F_3 ( V_5 ) ;
V_9 = F_4 ( V_10 , V_25 ) ;
if ( ! V_9 )
goto V_20;
F_5 ( V_9 , V_4 , V_10 ) ;
F_6 ( V_2 , V_9 , V_10 ) ;
F_7 ( V_9 ) ;
V_20:
F_8 ( & V_7 -> V_15 ) ;
V_14:
return 0 ;
}
static int F_9 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
return F_10 ( V_27 , F_1 , V_26 -> V_28 ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_29 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_12 ( V_7 , true ) ;
return 0 ;
}
static int F_13 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
return F_10 ( V_27 , F_11 , V_26 -> V_28 ) ;
}
void F_14 ( struct V_6 * V_7 )
{
char V_30 [ 16 ] ;
if ( ! V_31 )
return;
F_15 ( V_30 , sizeof( V_30 ) , L_1 , V_7 -> V_32 ) ;
V_7 -> V_33 = F_16 ( V_30 , V_31 ) ;
if ( ! V_7 -> V_33 )
return;
F_17 ( L_2 , 0444 , V_7 -> V_33 , V_7 , & V_34 ) ;
F_17 ( L_3 , 0444 , V_7 -> V_33 , V_7 ,
& V_35 ) ;
}
void F_18 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_33 )
return;
F_19 ( V_7 -> V_33 ) ;
}
void F_20 ( void )
{
V_31 = F_16 ( V_36 , NULL ) ;
if ( ! V_31 )
F_21 ( L_4 ) ;
}
void F_22 ( void )
{
F_23 ( V_31 ) ;
}
