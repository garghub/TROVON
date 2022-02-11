static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 , * V_6 , * V_7 ;
int V_8 = 0 ;
V_4 = F_2 ( NULL , L_1 ) ;
if ( F_3 ( V_4 ) ) {
F_4 ( V_9 L_2 ,
V_10 ) ;
return - V_11 ;
}
V_5 = F_2 ( NULL , L_3 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_9 L_4 ,
V_10 ) ;
V_8 = - V_11 ;
goto V_12;
}
V_6 = F_2 ( & V_2 -> V_13 , L_5 ) ;
if ( F_3 ( V_6 ) ) {
F_4 ( V_9 L_6 ,
V_10 ) ;
V_8 = - V_11 ;
goto V_14;
}
V_7 = F_2 ( NULL , L_7 ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( V_9 L_8 ,
V_10 ) ;
V_8 = - V_11 ;
goto V_15;
}
F_5 ( V_5 , V_4 ) ;
F_5 ( V_6 , V_5 ) ;
F_5 ( V_7 , V_6 ) ;
F_6 ( V_7 ) ;
V_15:
F_6 ( V_6 ) ;
V_14:
F_6 ( V_5 ) ;
V_12:
F_6 ( V_4 ) ;
return V_8 ;
}
static int F_7 ( unsigned long V_16 ,
unsigned long V_17 )
{
struct V_3 * V_4 , * V_7 ;
V_4 = F_2 ( NULL , L_1 ) ;
if ( F_3 ( V_4 ) ) {
F_4 ( V_18 L_9 , V_10 ) ;
return - V_19 ;
}
F_8 ( V_4 , V_16 ) ;
F_6 ( V_4 ) ;
V_7 = F_2 ( NULL , L_7 ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( V_18 L_10 , V_10 ) ;
return - V_19 ;
}
F_8 ( V_7 , V_17 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_28 ;
unsigned long V_29 , V_30 ;
int V_8 , V_31 ;
switch ( F_10 ( V_23 ) ) {
case 44100 :
V_29 = 45158400 ;
break;
case 32000 :
case 48000 :
case 96000 :
V_29 = 49152000 ;
break;
default:
return - V_11 ;
}
V_31 = 512 ;
V_30 = F_10 ( V_23 ) * V_31 ;
V_8 = F_7 ( V_29 , V_30 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_11 ( V_28 , V_32 ,
V_30 , V_33 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_8 ;
}
static int T_1 F_12 ( void )
{
int V_8 ;
V_34 = F_13 ( L_11 , - 1 ) ;
if ( ! V_34 )
return - V_35 ;
V_8 = F_14 ( V_34 ) ;
if ( V_8 )
goto V_36;
V_37 = F_13 ( L_12 , - 1 ) ;
if ( ! V_37 ) {
V_8 = - V_35 ;
goto V_38;
}
F_15 ( V_37 , & V_39 ) ;
V_8 = F_14 ( V_37 ) ;
if ( V_8 )
goto V_40;
V_8 = F_1 ( V_37 ) ;
if ( V_8 )
goto V_41;
return 0 ;
V_41:
F_16 ( V_37 ) ;
V_40:
F_17 ( V_37 ) ;
V_38:
F_16 ( V_34 ) ;
V_36:
F_17 ( V_34 ) ;
return V_8 ;
}
static void T_2 F_18 ( void )
{
F_19 ( V_37 ) ;
F_19 ( V_34 ) ;
}
