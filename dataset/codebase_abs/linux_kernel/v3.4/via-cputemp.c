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
static int T_3 F_8 ( struct V_22 * V_23 )
{
struct V_9 * V_10 ;
struct V_24 * V_25 = & F_9 ( V_23 -> V_14 ) ;
int V_17 ;
T_2 V_15 , V_16 ;
V_10 = F_10 ( sizeof( struct V_9 ) , V_26 ) ;
if ( ! V_10 ) {
V_17 = - V_27 ;
F_11 ( & V_23 -> V_2 , L_5 ) ;
goto exit;
}
V_10 -> V_14 = V_23 -> V_14 ;
V_10 -> V_13 = L_6 ;
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
V_17 = - V_29 ;
goto V_30;
}
V_17 = F_5 ( V_10 -> V_14 , V_10 -> V_18 , & V_15 , & V_16 ) ;
if ( V_17 ) {
F_11 ( & V_23 -> V_2 ,
L_7 ) ;
goto V_30;
}
F_12 ( V_23 , V_10 ) ;
V_17 = F_13 ( & V_23 -> V_2 . V_31 , & V_32 ) ;
if ( V_17 )
goto V_30;
if ( V_10 -> V_20 )
V_10 -> V_21 = F_14 () ;
if ( V_10 -> V_21 ) {
V_17 = F_15 ( & V_23 -> V_2 , & V_33 ) ;
if ( V_17 )
goto V_34;
}
V_10 -> V_35 = F_16 ( & V_23 -> V_2 ) ;
if ( F_17 ( V_10 -> V_35 ) ) {
V_17 = F_18 ( V_10 -> V_35 ) ;
F_11 ( & V_23 -> V_2 , L_8 ,
V_17 ) ;
goto V_34;
}
return 0 ;
V_34:
if ( V_10 -> V_21 )
F_19 ( & V_23 -> V_2 , & V_33 ) ;
F_20 ( & V_23 -> V_2 . V_31 , & V_32 ) ;
V_30:
F_12 ( V_23 , NULL ) ;
F_21 ( V_10 ) ;
exit:
return V_17 ;
}
static int T_4 F_22 ( struct V_22 * V_23 )
{
struct V_9 * V_10 = F_23 ( V_23 ) ;
F_24 ( V_10 -> V_35 ) ;
if ( V_10 -> V_21 )
F_19 ( & V_23 -> V_2 , & V_33 ) ;
F_20 ( & V_23 -> V_2 . V_31 , & V_32 ) ;
F_12 ( V_23 , NULL ) ;
F_21 ( V_10 ) ;
return 0 ;
}
static int T_5 F_25 ( unsigned int V_36 )
{
int V_17 ;
struct V_22 * V_23 ;
struct V_37 * V_37 ;
V_23 = F_26 ( V_38 , V_36 ) ;
if ( ! V_23 ) {
V_17 = - V_27 ;
F_27 ( L_9 ) ;
goto exit;
}
V_37 = F_10 ( sizeof( struct V_37 ) , V_26 ) ;
if ( ! V_37 ) {
V_17 = - V_27 ;
goto V_39;
}
V_17 = F_28 ( V_23 ) ;
if ( V_17 ) {
F_27 ( L_10 , V_17 ) ;
goto V_40;
}
V_37 -> V_23 = V_23 ;
V_37 -> V_36 = V_36 ;
F_29 ( & V_41 ) ;
F_30 ( & V_37 -> V_42 , & V_43 ) ;
F_31 ( & V_41 ) ;
return 0 ;
V_40:
F_21 ( V_37 ) ;
V_39:
F_32 ( V_23 ) ;
exit:
return V_17 ;
}
static void T_5 F_33 ( unsigned int V_36 )
{
struct V_37 * V_44 ;
F_29 ( & V_41 ) ;
F_34 (p, &pdev_list, list) {
if ( V_44 -> V_36 == V_36 ) {
F_35 ( V_44 -> V_23 ) ;
F_36 ( & V_44 -> V_42 ) ;
F_31 ( & V_41 ) ;
F_21 ( V_44 ) ;
return;
}
}
F_31 ( & V_41 ) ;
}
static int T_5 F_37 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
unsigned int V_36 = ( unsigned long ) V_48 ;
switch ( V_47 ) {
case V_49 :
case V_50 :
F_25 ( V_36 ) ;
break;
case V_51 :
F_33 ( V_36 ) ;
break;
}
return V_52 ;
}
static int T_6 F_38 ( void )
{
int V_53 , V_17 ;
if ( ! F_39 ( V_54 ) )
return - V_29 ;
V_17 = F_40 ( & V_55 ) ;
if ( V_17 )
goto exit;
F_41 (i) {
struct V_24 * V_25 = & F_9 ( V_53 ) ;
if ( V_25 -> V_56 != 6 )
continue;
if ( V_25 -> V_28 < 0x0a )
continue;
if ( V_25 -> V_28 > 0x0f ) {
F_42 ( L_11 , V_25 -> V_28 ) ;
continue;
}
F_25 ( V_53 ) ;
}
#ifndef F_43
if ( F_44 ( & V_43 ) ) {
V_17 = - V_29 ;
goto V_57;
}
#endif
F_45 ( & V_58 ) ;
return 0 ;
#ifndef F_43
V_57:
F_46 ( & V_55 ) ;
#endif
exit:
return V_17 ;
}
static void T_7 F_47 ( void )
{
struct V_37 * V_44 , * V_59 ;
F_48 ( & V_58 ) ;
F_29 ( & V_41 ) ;
F_49 (p, n, &pdev_list, list) {
F_35 ( V_44 -> V_23 ) ;
F_36 ( & V_44 -> V_42 ) ;
F_21 ( V_44 ) ;
}
F_31 ( & V_41 ) ;
F_46 ( & V_55 ) ;
}
