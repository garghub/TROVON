static void F_1 ( void )
{
static struct V_1 * V_2 ;
if ( V_2 )
return;
V_2 = F_2 ( NULL , L_1 , NULL ,
V_3 , 0 ) ;
F_3 ( V_2 , L_1 , NULL ) ;
}
static int F_4 ( struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 V_13 ;
bool V_14 = false ;
int V_15 = 0 ;
int V_16 ;
if ( V_5 -> V_17 )
return 0 ;
V_9 = F_5 ( F_6 ( & V_5 -> V_9 ) , 0 , 0 ) ;
if ( ! V_9 ) {
F_7 ( & V_5 -> V_9 , L_2 ,
V_18 ) ;
return - V_19 ;
}
F_8 ( & V_13 ) ;
V_16 = F_9 ( V_5 , & V_13 , NULL , NULL ) ;
if ( V_16 < 0 )
goto V_20;
F_10 (rentry, &resource_list, node) {
switch ( F_11 ( V_11 -> V_21 ) ) {
case V_22 :
if ( ! V_14 ) {
V_9 -> V_21 = * V_11 -> V_21 ;
V_14 = true ;
}
break;
case V_23 :
if ( V_15 < V_24 )
V_9 -> V_25 [ V_15 ++ ] = V_11 -> V_21 -> V_26 ;
break;
default:
F_12 ( & V_5 -> V_9 , L_3 ) ;
break;
}
}
F_13 ( & V_13 ) ;
if ( V_5 -> V_27 )
V_9 -> V_9 . V_27 = F_14 ( V_5 -> V_27 ) ;
F_15 ( & V_9 -> V_9 , V_5 ) ;
V_16 = F_16 ( V_9 , & V_28 ) ;
if ( V_16 ) {
F_7 ( & V_5 -> V_9 , L_4 ,
V_18 , V_16 ) ;
goto V_20;
}
return 1 ;
V_20:
F_17 ( V_9 ) ;
return V_16 ;
}
void T_1 F_18 ( void )
{
F_1 () ;
F_19 ( & V_29 ) ;
}
