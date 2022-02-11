static void F_1 ( void )
{
static struct V_1 * V_2 ;
if ( V_2 )
return;
V_2 = F_2 ( NULL , L_1 , NULL , 0 , 0 ) ;
F_3 ( V_2 , L_1 , NULL ) ;
}
static int F_4 ( struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
bool V_13 = false ;
int V_14 = 0 ;
int V_15 ;
if ( V_4 -> V_16 )
return 0 ;
V_8 = F_5 ( F_6 ( & V_4 -> V_8 ) , 0 , 0 ) ;
if ( ! V_8 ) {
F_7 ( & V_4 -> V_8 , L_2 ,
V_17 ) ;
return - V_18 ;
}
F_8 ( & V_12 ) ;
V_15 = F_9 ( V_4 , & V_12 , NULL , NULL ) ;
if ( V_15 < 0 )
goto V_19;
F_10 (rentry, &resource_list, node) {
switch ( F_11 ( V_10 -> V_20 ) ) {
case V_21 :
if ( ! V_13 ) {
V_8 -> V_20 = * V_10 -> V_20 ;
V_13 = true ;
}
break;
case V_22 :
if ( V_14 < V_23 )
V_8 -> V_24 [ V_14 ++ ] = V_10 -> V_20 -> V_25 ;
break;
default:
F_12 ( & V_4 -> V_8 , L_3 ) ;
break;
}
}
F_13 ( & V_12 ) ;
if ( V_4 -> V_26 )
V_8 -> V_8 . V_26 = F_14 ( V_4 -> V_26 ) ;
F_15 ( & V_8 -> V_8 , V_4 ) ;
V_15 = F_16 ( V_8 , & V_27 ) ;
if ( V_15 ) {
F_7 ( & V_4 -> V_8 , L_4 ,
V_17 , V_15 ) ;
goto V_19;
}
return 1 ;
V_19:
F_17 ( V_8 ) ;
return V_15 ;
}
void T_1 F_18 ( void )
{
F_1 () ;
F_19 ( & V_28 ) ;
}
