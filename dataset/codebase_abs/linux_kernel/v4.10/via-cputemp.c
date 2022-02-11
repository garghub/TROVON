static T_1 F_1 ( struct V_1 * V_2 , struct V_3
* V_4 , char * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
if ( V_8 -> V_11 == V_12 )
V_6 = sprintf ( V_5 , L_1 , V_10 -> V_13 ) ;
else
V_6 = sprintf ( V_5 , L_2 , V_10 -> V_14 ) ;
return V_6 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_2 V_15 , V_16 ;
int V_17 ;
V_17 = F_5 ( V_10 -> V_14 , V_10 -> V_18 , & V_15 , & V_16 ) ;
if ( V_17 )
return - V_19 ;
return sprintf ( V_5 , L_3 , ( ( unsigned long ) V_15 & 0xffffff ) * 1000 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_2 V_15 , V_16 ;
int V_17 ;
V_17 = F_5 ( V_10 -> V_14 , V_10 -> V_20 , & V_15 , & V_16 ) ;
if ( V_17 )
return - V_19 ;
return sprintf ( V_5 , L_4 , F_7 ( ~ V_16 & 0x7f , V_10 -> V_21 ) ) ;
}
static int F_8 ( struct V_22 * V_23 )
{
struct V_9 * V_10 ;
struct V_24 * V_25 = & F_9 ( V_23 -> V_14 ) ;
int V_17 ;
T_2 V_15 , V_16 ;
V_10 = F_10 ( & V_23 -> V_2 , sizeof( struct V_9 ) ,
V_26 ) ;
if ( ! V_10 )
return - V_27 ;
V_10 -> V_14 = V_23 -> V_14 ;
V_10 -> V_13 = L_5 ;
switch ( V_25 -> V_28 ) {
case 0xA :
case 0xD :
V_10 -> V_18 = 0x1169 ;
V_10 -> V_20 = 0x198 ;
break;
case 0xF :
V_10 -> V_18 = 0x1423 ;
break;
default:
return - V_29 ;
}
V_17 = F_5 ( V_10 -> V_14 , V_10 -> V_18 , & V_15 , & V_16 ) ;
if ( V_17 ) {
F_11 ( & V_23 -> V_2 ,
L_6 ) ;
return V_17 ;
}
F_12 ( V_23 , V_10 ) ;
V_17 = F_13 ( & V_23 -> V_2 . V_30 , & V_31 ) ;
if ( V_17 )
return V_17 ;
if ( V_10 -> V_20 )
V_10 -> V_21 = F_14 () ;
if ( V_10 -> V_21 ) {
V_17 = F_15 ( & V_23 -> V_2 , & V_32 ) ;
if ( V_17 )
goto V_33;
}
V_10 -> V_34 = F_16 ( & V_23 -> V_2 ) ;
if ( F_17 ( V_10 -> V_34 ) ) {
V_17 = F_18 ( V_10 -> V_34 ) ;
F_11 ( & V_23 -> V_2 , L_7 ,
V_17 ) ;
goto V_33;
}
return 0 ;
V_33:
if ( V_10 -> V_21 )
F_19 ( & V_23 -> V_2 , & V_32 ) ;
F_20 ( & V_23 -> V_2 . V_30 , & V_31 ) ;
return V_17 ;
}
static int F_21 ( struct V_22 * V_23 )
{
struct V_9 * V_10 = F_22 ( V_23 ) ;
F_23 ( V_10 -> V_34 ) ;
if ( V_10 -> V_21 )
F_19 ( & V_23 -> V_2 , & V_32 ) ;
F_20 ( & V_23 -> V_2 . V_30 , & V_31 ) ;
return 0 ;
}
static int F_24 ( unsigned int V_35 )
{
int V_17 ;
struct V_22 * V_23 ;
struct V_36 * V_36 ;
V_23 = F_25 ( V_37 , V_35 ) ;
if ( ! V_23 ) {
V_17 = - V_27 ;
F_26 ( L_8 ) ;
goto exit;
}
V_36 = F_27 ( sizeof( struct V_36 ) , V_26 ) ;
if ( ! V_36 ) {
V_17 = - V_27 ;
goto V_38;
}
V_17 = F_28 ( V_23 ) ;
if ( V_17 ) {
F_26 ( L_9 , V_17 ) ;
goto V_39;
}
V_36 -> V_23 = V_23 ;
V_36 -> V_35 = V_35 ;
F_29 ( & V_40 ) ;
F_30 ( & V_36 -> V_41 , & V_42 ) ;
F_31 ( & V_40 ) ;
return 0 ;
V_39:
F_32 ( V_36 ) ;
V_38:
F_33 ( V_23 ) ;
exit:
return V_17 ;
}
static int F_34 ( unsigned int V_35 )
{
struct V_36 * V_43 ;
F_29 ( & V_40 ) ;
F_35 (p, &pdev_list, list) {
if ( V_43 -> V_35 == V_35 ) {
F_36 ( V_43 -> V_23 ) ;
F_37 ( & V_43 -> V_41 ) ;
F_31 ( & V_40 ) ;
F_32 ( V_43 ) ;
return 0 ;
}
}
F_31 ( & V_40 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
int V_17 ;
if ( ! F_39 ( V_44 ) )
return - V_29 ;
V_17 = F_40 ( & V_45 ) ;
if ( V_17 )
goto exit;
V_17 = F_41 ( V_46 , L_10 ,
F_24 , F_34 ) ;
if ( V_17 < 0 )
goto V_47;
V_48 = V_17 ;
#ifndef F_42
if ( F_43 ( & V_42 ) ) {
V_17 = - V_29 ;
goto V_49;
}
#endif
return 0 ;
#ifndef F_42
V_49:
F_44 ( V_48 ) ;
#endif
V_47:
F_45 ( & V_45 ) ;
exit:
return V_17 ;
}
static void T_4 F_46 ( void )
{
F_47 ( V_48 ) ;
F_45 ( & V_45 ) ;
}
