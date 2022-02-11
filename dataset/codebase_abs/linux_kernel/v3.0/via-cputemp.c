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
static int T_3 F_6 ( struct V_20 * V_21 )
{
struct V_9 * V_10 ;
struct V_22 * V_23 = & F_7 ( V_21 -> V_14 ) ;
int V_17 ;
T_2 V_15 , V_16 ;
V_10 = F_8 ( sizeof( struct V_9 ) , V_24 ) ;
if ( ! V_10 ) {
V_17 = - V_25 ;
F_9 ( & V_21 -> V_2 , L_4 ) ;
goto exit;
}
V_10 -> V_14 = V_21 -> V_14 ;
V_10 -> V_13 = L_5 ;
switch ( V_23 -> V_26 ) {
case 0xA :
case 0xD :
V_10 -> V_18 = 0x1169 ;
break;
case 0xF :
V_10 -> V_18 = 0x1423 ;
break;
default:
V_17 = - V_27 ;
goto V_28;
}
V_17 = F_5 ( V_10 -> V_14 , V_10 -> V_18 , & V_15 , & V_16 ) ;
if ( V_17 ) {
F_9 ( & V_21 -> V_2 ,
L_6 ) ;
goto V_28;
}
F_10 ( V_21 , V_10 ) ;
V_17 = F_11 ( & V_21 -> V_2 . V_29 , & V_30 ) ;
if ( V_17 )
goto V_28;
V_10 -> V_31 = F_12 ( & V_21 -> V_2 ) ;
if ( F_13 ( V_10 -> V_31 ) ) {
V_17 = F_14 ( V_10 -> V_31 ) ;
F_9 ( & V_21 -> V_2 , L_7 ,
V_17 ) ;
goto V_32;
}
return 0 ;
V_32:
F_15 ( & V_21 -> V_2 . V_29 , & V_30 ) ;
V_28:
F_10 ( V_21 , NULL ) ;
F_16 ( V_10 ) ;
exit:
return V_17 ;
}
static int T_4 F_17 ( struct V_20 * V_21 )
{
struct V_9 * V_10 = F_18 ( V_21 ) ;
F_19 ( V_10 -> V_31 ) ;
F_15 ( & V_21 -> V_2 . V_29 , & V_30 ) ;
F_10 ( V_21 , NULL ) ;
F_16 ( V_10 ) ;
return 0 ;
}
static int T_5 F_20 ( unsigned int V_33 )
{
int V_17 ;
struct V_20 * V_21 ;
struct V_34 * V_34 ;
V_21 = F_21 ( V_35 , V_33 ) ;
if ( ! V_21 ) {
V_17 = - V_25 ;
F_22 ( L_8 ) ;
goto exit;
}
V_34 = F_8 ( sizeof( struct V_34 ) , V_24 ) ;
if ( ! V_34 ) {
V_17 = - V_25 ;
goto V_36;
}
V_17 = F_23 ( V_21 ) ;
if ( V_17 ) {
F_22 ( L_9 , V_17 ) ;
goto V_37;
}
V_34 -> V_21 = V_21 ;
V_34 -> V_33 = V_33 ;
F_24 ( & V_38 ) ;
F_25 ( & V_34 -> V_39 , & V_40 ) ;
F_26 ( & V_38 ) ;
return 0 ;
V_37:
F_16 ( V_34 ) ;
V_36:
F_27 ( V_21 ) ;
exit:
return V_17 ;
}
static void T_5 F_28 ( unsigned int V_33 )
{
struct V_34 * V_41 ;
F_24 ( & V_38 ) ;
F_29 (p, &pdev_list, list) {
if ( V_41 -> V_33 == V_33 ) {
F_30 ( V_41 -> V_21 ) ;
F_31 ( & V_41 -> V_39 ) ;
F_26 ( & V_38 ) ;
F_16 ( V_41 ) ;
return;
}
}
F_26 ( & V_38 ) ;
}
static int T_5 F_32 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
unsigned int V_33 = ( unsigned long ) V_45 ;
switch ( V_44 ) {
case V_46 :
case V_47 :
F_20 ( V_33 ) ;
break;
case V_48 :
F_28 ( V_33 ) ;
break;
}
return V_49 ;
}
static int T_6 F_33 ( void )
{
int V_50 , V_17 ;
if ( F_7 ( 0 ) . V_51 != V_52 ) {
F_34 (KERN_DEBUG DRVNAME L_10 ) ;
V_17 = - V_27 ;
goto exit;
}
V_17 = F_35 ( & V_53 ) ;
if ( V_17 )
goto exit;
F_36 (i) {
struct V_22 * V_23 = & F_7 ( V_50 ) ;
if ( V_23 -> V_54 != 6 )
continue;
if ( V_23 -> V_26 < 0x0a )
continue;
if ( V_23 -> V_26 > 0x0f ) {
F_37 ( L_11 , V_23 -> V_26 ) ;
continue;
}
F_20 ( V_50 ) ;
}
#ifndef F_38
if ( F_39 ( & V_40 ) ) {
V_17 = - V_27 ;
goto V_55;
}
#endif
F_40 ( & V_56 ) ;
return 0 ;
#ifndef F_38
V_55:
F_41 ( & V_53 ) ;
#endif
exit:
return V_17 ;
}
static void T_7 F_42 ( void )
{
struct V_34 * V_41 , * V_57 ;
F_43 ( & V_56 ) ;
F_24 ( & V_38 ) ;
F_44 (p, n, &pdev_list, list) {
F_30 ( V_41 -> V_21 ) ;
F_31 ( & V_41 -> V_39 ) ;
F_16 ( V_41 ) ;
}
F_26 ( & V_38 ) ;
F_41 ( & V_53 ) ;
}
