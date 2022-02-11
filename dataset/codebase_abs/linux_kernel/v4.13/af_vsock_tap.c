int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 -> type != V_4 ) )
return - V_5 ;
F_3 ( V_2 -> V_6 ) ;
F_4 ( & V_7 ) ;
F_5 ( & V_2 -> V_8 , & V_9 ) ;
F_6 ( & V_7 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_1 * V_10 ;
bool V_11 = false ;
F_4 ( & V_7 ) ;
F_8 (tmp, &vsock_tap_all, list) {
if ( V_2 == V_10 ) {
F_9 ( & V_2 -> V_8 ) ;
V_11 = true ;
goto V_12;
}
}
F_10 ( L_1 , V_2 ) ;
V_12:
F_6 ( & V_7 ) ;
F_11 () ;
if ( V_11 )
F_12 ( V_2 -> V_6 ) ;
return V_11 ? 0 : - V_13 ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_16 * V_3 )
{
int V_17 = 0 ;
struct V_14 * V_18 = F_14 ( V_15 , V_19 ) ;
if ( V_18 ) {
F_15 ( V_3 ) ;
V_18 -> V_3 = V_3 ;
V_17 = F_16 ( V_18 ) ;
if ( F_2 ( V_17 > 0 ) )
V_17 = F_17 ( V_17 ) ;
F_18 ( V_3 ) ;
}
return V_17 ;
}
static void F_19 ( struct V_14 * V_15 )
{
int V_17 ;
struct V_1 * V_10 ;
F_20 (tmp, &vsock_tap_all, list) {
V_17 = F_13 ( V_15 , V_10 -> V_3 ) ;
if ( F_2 ( V_17 ) )
break;
}
}
