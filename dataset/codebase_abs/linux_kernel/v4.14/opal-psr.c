static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_4 , struct V_6 , V_4 ) ;
struct V_7 V_8 ;
int V_9 , V_10 , V_11 ;
V_11 = F_3 () ;
if ( V_11 < 0 ) {
F_4 ( L_1 ) ;
return V_11 ;
}
V_10 = F_5 ( & V_12 ) ;
if ( V_10 )
goto V_13;
V_10 = F_6 ( V_6 -> V_14 , V_11 ,
( V_15 * ) F_7 ( & V_9 ) ) ;
switch ( V_10 ) {
case V_16 :
V_10 = F_8 ( V_11 , & V_8 ) ;
if ( V_10 ) {
F_4 ( L_2 ) ;
V_10 = - V_17 ;
goto V_18;
}
V_10 = F_9 ( F_10 ( V_8 ) ) ;
if ( ! V_10 ) {
V_10 = sprintf ( V_5 , L_3 , F_11 ( V_9 ) ) ;
if ( V_10 < 0 )
V_10 = - V_17 ;
}
break;
case V_19 :
V_10 = sprintf ( V_5 , L_3 , F_11 ( V_9 ) ) ;
if ( V_10 < 0 )
V_10 = - V_17 ;
break;
default:
V_10 = F_9 ( V_10 ) ;
}
V_18:
F_12 ( & V_12 ) ;
V_13:
F_13 ( V_11 ) ;
return V_10 ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_20 )
{
struct V_6 * V_6 = F_2 ( V_4 , struct V_6 , V_4 ) ;
struct V_7 V_8 ;
int V_9 , V_10 , V_11 ;
V_10 = F_15 ( V_5 , 0 , & V_9 ) ;
if ( V_10 )
return V_10 ;
V_11 = F_3 () ;
if ( V_11 < 0 ) {
F_4 ( L_1 ) ;
return V_11 ;
}
V_10 = F_5 ( & V_12 ) ;
if ( V_10 )
goto V_13;
V_10 = F_16 ( V_6 -> V_14 , V_11 , V_9 ) ;
switch ( V_10 ) {
case V_16 :
V_10 = F_8 ( V_11 , & V_8 ) ;
if ( V_10 ) {
F_4 ( L_2 ) ;
V_10 = - V_17 ;
goto V_18;
}
V_10 = F_9 ( F_10 ( V_8 ) ) ;
if ( ! V_10 )
V_10 = V_20 ;
break;
case V_19 :
V_10 = V_20 ;
break;
default:
V_10 = F_9 ( V_10 ) ;
}
V_18:
F_12 ( & V_12 ) ;
V_13:
F_13 ( V_11 ) ;
return V_10 ;
}
void T_3 F_17 ( void )
{
struct V_21 * V_9 , * V_22 ;
int V_23 = 0 ;
V_9 = F_18 ( NULL , NULL ,
L_4 ) ;
if ( ! V_9 ) {
F_4 ( L_5 ) ;
return;
}
V_24 = F_19 ( F_20 ( V_9 ) , sizeof( struct V_6 ) ,
V_25 ) ;
if ( ! V_24 )
return;
V_26 = F_21 ( L_6 , V_27 ) ;
if ( ! V_26 ) {
F_22 ( L_7 ) ;
goto V_18;
}
F_23 (psr, node) {
if ( F_24 ( V_22 , L_8 ,
& V_24 [ V_23 ] . V_14 ) )
goto V_28;
F_25 ( & V_24 [ V_23 ] . V_4 . V_4 ) ;
if ( F_26 ( V_22 , L_9 ,
& V_24 [ V_23 ] . V_4 . V_4 . V_29 ) )
goto V_28;
V_24 [ V_23 ] . V_4 . V_4 . V_30 = 0664 ;
V_24 [ V_23 ] . V_4 . V_31 = F_1 ;
V_24 [ V_23 ] . V_4 . V_32 = F_14 ;
if ( F_27 ( V_26 , & V_24 [ V_23 ] . V_4 . V_4 ) ) {
F_4 ( L_10 ,
V_24 [ V_23 ] . V_4 . V_4 . V_29 ) ;
goto V_28;
}
V_23 ++ ;
}
return;
V_28:
F_28 ( V_26 ) ;
V_18:
F_29 ( V_24 ) ;
}
